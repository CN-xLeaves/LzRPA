/*
  RTL32.inc

  OxygenBasic RunTime Library
  ===========================

  For creating standalon executables and dynamic link libraries which
  will run independently of Oxygen.dll

  NB Functions relating to dynamic compiling are not implemented in this library:
  "compile" and "uncompile"

  Version Alpha040

  21:48 09/01/2011
  15:56 07/03/2011
  22:43 02/06/2011
  07:37 08/09/2011
  05:28 21/10/2011
  18:50 31/10/2011
  11:28 17/02/2013
  10:42 15/03/2013
  04:33 31/03/2013
  06:01 14/04/2013
  13:03 15/10/2014
  17:55 24/01/2015
  05:06 15/05/2015
  08:28 07/09/2016
  09:51 23/03/2017

  Charles Pegge
  cevpegge (at) oxygenbasic.org


*/



  /*
  ==========================

  EXAMPLE:
  ========
                        'ENTER THESE LINES AT THE START OF YOUR PROGRAM

  $ dll                'THIS PRODUCES A DYNAMIC LINK LIBRARY INSTEAD OF AN EXE FILE
  $ FileName "t.dll"   'SPECIFIES THE COMPILED FILENAME
  include "RTL32.inc"  'INCLUDES THIS FILE

  ==========================
  */



  #file FileName independent

  %mode32bit

  '=================
  #ifdef dll
  '=================
  '
  'DLL EQUATES
  '
  % DLL_PROCESS_DETACH   0
  % DLL_PROCESS_ATTACH   1
  % DLL_THREAD_ATTACH    2
  % DLL_THREAD_DETACH    3
  % DLL_PROCESS_VERIFIER 4
  '
  mov edx,[esp+8] 'second param of DLLmain
  '
  select edx
    case DLL_PROCESS_ATTACH : jmp fwd dll_start
    case DLL_PROCESS_DETACH : jmp fwd dll_finish
    case DLL_THREAD_ATTACH  : mov eax,1
    case DLL_THREAD_DETACH  : mov eax,0
  end select
  ret 12


  '---------
  dll_start:
  '=========
  '
  jmp fwd prolog

  '----------
  dll_finish:
  '==========
  '
  declare sub finish()
  finish()
  mov eax,0
  ret 12


  '==========
  #endif 'DLL
  '==========



  '------
  Prolog:
  '======

  push ebx : push esi : push edi : push eax : push ebp
  mov ebp,esp
  '
  'TOP LEVEL LOCALS
  '
  push 0      '[ebp-4]  local
  push 0      '[ebp-8]  temp
  push 0      '[ebp-12] concat
  push 0      '[ebp-16] unused
  sub esp,240 '[ebp-20] other local space uninitialised


  '--------------------------------------------------------------
  'MOVE BOOTSTRAP PROCEDURE POINTERS TO RUNTIME LIBRARY POSITIONS
  '==============================================================
  '
  'GET ABSOLUTE ADDRESSES
  '
  call fwd here
  .here
  pop eax
  sub eax,here
  mov ebx,eax : add ebx,bssdata
  mov edi,eax : add edi,import_address_table
  '

  '--------------------------------
  'COPY BOOTSTRAP LIBRARY ADDRESSES
  '================================
  '
 'def LoadLibrary           call [ebx+024]
 'def GetProcAddress        call [ebx+040]
 'def FreeLibrary           call [ebx+032]
  def SysAllocStringByteLen call [ebx+160]
  def SysFreeString         call [ebx+168]
  def GetModuleHandle       call [ebx+440]
  def GetGetCommandLine     call [ebx+448]
  def GetExitCodeProcess    call [ebx+456]
  def ExitProcess           call [ebx+464]
  def CreateFile            call [ebx+480]
  def ReadFile              call [ebx+488]
  def CloseHandle           call [ebx+496]
  def MessageBox            call [ebx+472]
  def MessageBoxW           call [ebx+504]
  '
  mov eax,[edi+00] : mov [ebx+024],eax 'LoadLibrary
  mov eax,[edi+04] : mov [ebx+040],eax 'GetProcAddress
  mov eax,[edi+08] : mov [ebx+032],eax 'FreeLibrary
  mov eax,[edi+12] : mov [ebx+440],eax 'GetModuleHandle
  mov eax,[edi+16] : mov [ebx+448],eax 'GetGetCommandLine
  mov eax,[edi+20] : mov [ebx+456],eax 'GetExitCodeProcess
  mov eax,[edi+24] : mov [ebx+464],eax 'ExitProcess
  mov eax,[edi+28] : mov [ebx+480],eax 'CreateFileA
  mov eax,[edi+32] : mov [ebx+488],eax 'Readfile
  mov eax,[edi+36] : mov [ebx+496],eax 'CloseHandle
  mov eax,[edi+44] : mov [ebx+472],eax 'MessageBoxA
  mov eax,[edi+48] : mov [ebx+504],eax 'MessageBoxW



  '---------------------------
  'ADDITIONAL OS CALLS GO HERE
  '===========================
  '
  '
  indexers ebx offset 4096 ascending
  var long WriteFile,GetFileSize,SetFilePointer
  '
  edi=LoadLibrary "oleaut32.dll"
  '
  [ebx+160]=GetProcAddress edi,"SysAllocStringByteLen"
  [ebx+168]=GetProcAddress edi,"SysFreeString"
  '
  edi=LoadLibrary "kernel32.dll"
  '
  WriteFile=GetProcAddress edi,"WriteFile"
  GetFileSize=GetProcAddress edi,"GetFileSize"
  SetFilePointer=GetProcAddress edi,"SetFilePointer"
  '
  '
  '=============
  jmp fwd endlib
  '=============
  '
  '
  '
  '================
  'RUN TIME GLOBALS
  '================
  '
  type numformat
    dp  as sys  ' DECIMAL PLACES
    trz as sys  ' STRIP TRAILING ZEROS
    sn  as sys  ' SCIENTIFIC NOTATION BY DEFAULT
    sdp as sys  ' INHIBIT ZERO BEFORE DECIMAL POINT
    sns as sys  ' LEADING SPACE FOR NON NEGATIVE NUMBERS
    lps as sys  ' LEAD PADDING SPACES
  end type

  'const
  string cr=chr(13,10)

  'ert     error number
  'ers     error description
  'wdg     runtime messages string
  'num     number to ascii format specifier


  sys ert
  numformat num
  string ers,wdg


  '=================
  'LIBRARY FUNCTIONS
  '=================


  '------------------------------------------------------------------
  sub init1(byval p as sys, byval le as sys, byval c as sys) external
  '==================================================================
  mov edx,[p]
  mov ecx,[le]
  mov al,[c]
  mov ah,al
  shl eax,16
  mov al,[c]
  mov ah,al
  shr ecx,2
  (
    dec ecx
    jl exit
    mov [edx],eax
    add edx,4
    repeat
  )
  mov ecx,[le]
  and ecx,3
  (
    dec ecx
    jl exit
    mov [edx],al
    inc edx
    repeat
  )
  end sub


  '----------------------------------------------------------------
  function float_to_ascii(sys dpp) as string external 'at [ebx+200]
  '================================================================
  '
  zstring s[24], t[64], bcd[16] 'BUFFERS
  sys esize,tempdw,dp,dpl,sn,snv,b,nzero,oldcw,truncw,a,b,i,pt,pa
  '
  '
  'optional padding
  '================
  '
  if num.lps then
    pt= @t
    for i=1 to 8
      *pt=0x20202020
      pt+=4
    next
  end if
  '
  pt= @t + 32
  pa= @bcd
  '
  if dpp>=0 then
    dpl=dpp
  else
    dpl=num.dp
  end if
  '
  fstpt [bcd] 'pop store ext number from fpu
  '
  mov eax,0
  mov [snv],eax
  mov [sn],eax
  mov [nzero],eax
  '
  '
  'CHECK FOR ZERO INFINITY AND NAN
  '-------------------------------
  '
  mov ecx,[pa]

  mov eax,[ecx+8]

  (
    and eax,&h7fff
    '
    'TEST FOR ZERO
    '
    (
      cmp eax,0
      jnz exit 'EXCLUDE NON ZERO
      cmp dword ptr [num.trz],0
      jz exit 'ZERO STRIPPER FLAG
      or eax,[ecx]
      or eax,[ecx+4]
      jnz exit
      (
        test byte [ecx+9],&h80
        jz exit
        '
        '*pt="-0"
        '
        mov eax,[pt]
        mov word [eax],0x302d
        lea edx,[eax+2]         
        jmp fwd fadonez 'NEGATIVE ZERO
      )
      '
      '*pt="0"
      '
      mov eax,[pt]
      mov byte [eax],0x30
      lea edx,[eax+1]
      jmp fadonez 'POSITIVE ZERO
    )

    cmp eax,&h7fff
    jnz exit
    mov dword ptr [nzero],1
    '
    mov eax,[ecx+4]
    and eax,0x7fffffff 'exclude bit 63
    or  eax,[ecx]
    '
    'CHECK FOR NAN OR INFINITY
    '
    (
      cmp eax,0
      jz exit
      '
      'sNAN OR qNAN
      '
      (
        test byte ptr [ecx+7],&h40
        jnz exit
        '
        '*pt="#sNAN"
        '
        mov eax,[pt]
        mov [eax],0x414E7323
        mov [eax+4],0x4E
        lea edx,[eax+5]
        jmp fwd fadonez 'SIGNALLING NAN
      )
      '
      '*pt="#qNAN"
      '
      mov eax,[pt]
      mov [eax],0x414E7123
      mov [eax+4],0x4E
      lea edx,[eax+5]
      jmp fwd fadonez 'QUIET NAN
    )
    '
    'NEGATIVE / POSITIVE INFINITY
    '
    (
      test byte ptr [ecx+9],&h80
      jz exit
      '
      '*pt="#-INF"
      '
      mov eax,[pt]
      mov [eax],0x4E492D23
      mov [eax+4],0x46
      lea edx,[eax+5]
      jmp fwd fadonez 'NEGATIVE INFINITY
    )
    '
    '*pt="#INF"
    '
    mov eax,[pt]
    mov [eax],0x464E4923
    mov [eax+4],0x00
    lea edx,[eax+4]
    jmp fwd fadonez 'POSITIVE INFINITY
  )


  fldt [bcd]

  '---------------------------
  ' get the size of the number
  '---------------------------
  (
    '
    'CHECK FOR ZERO
    '
    mov dword ptr [esize],0
    fldz
    fcomip st(0),st(1)
    jz exit
    '
    mov dword ptr [nzero],1
    

    fldlg2                    'log10(2)
    fld   st(1)               'copy Src
    fabs                      'insures a positive value
    fyl2x                     '->[log2(Src)]*[log10(2)] = log10(Src)
      
    fstcw [oldcw]             'get current control word
    fwait
    mov   ax,[oldcw]
    or    ax,&hc00            'code it for truncating
    mov   [truncw],ax
    fldcw [truncw]            'insure rounding code of FPU to truncating
  
    fist dword ptr [esize]    'store characteristic of logarithm
    fldcw [oldcw]             'load back the former control word

    ftst                      'test logarithm for its sign
    fstsw ax                  'get result
    fwait
    sahf                      'transfer to CPU flags
    sbb   dword ptr [esize],0 'decrement esize if log is negative
    fstp  st(0)               'get rid of the logarithm
  )
  '
  'DECIMAL PLACES LIMIT
  '---------------------
  '
  mov eax,[dpl]
  (
   cmp eax,16
   jle exit
   mov eax,16 'LIMIT DECIMAL PLACES
  )

  mov [dp],eax


  'IS SCIENTIFIC NOTATION ALWAYS REQUIRED

  cmp byte ptr [num.sn],0
  jnz ENotation

  '
  'VERY LARGE NUMBERS
  '
  (
    mov ecx,[esize]
    'add ecx,dp
    cmp ecx,18
    jl exit
    jmp ENotation
  )
  '
  'SMALL NUMBERS
  '
  (
    cmp dword ptr [esize],0
    jge exit
    mov ecx,[dp]
    mov edx,[esize]
    neg edx
    cmp edx,4
    jg ENotation 'LIMIT FOR SIMPLE FORMAT
    mov eax,ecx
    mov [dp],ecx
    jmp PowerAdjust
  )
  '
  'NUMBERS NOT REQUIRING SCIENTIFIC NOTATION
  '
  (
    mov eax,[dp]
    mov ecx,eax   'DECIMAL PLACES
    add ecx,[esize] 'INTEGER DIGITS 
    sub ecx,16
    jle exit
    '
    'TOO MANY DIGITS? (ecx contains excess digits)
    '
    '
    sub eax,ecx 'REDUCE MULTIPLIER PLACES IF NECESSARY
    sub [dp],ecx  'REDUCE DECIMAL PLACES ALSO
  )
  '
  '
  jmp PowerAdjust
  '
  ENotation:
  '---------

    mov ecx,[esize]
    mov [snv],ecx
    mov eax,[dp]
    sub eax,ecx
    mov dword ptr [sn],1 'SCIENTIFIC NOTATION FLAG

  PowerAdjust:
  '-----------

  mov [tempdw],eax 'ADJUSTED MULTIPLIER


  'Multiply the number by the power of 10
  '---------------------------------------
  (
    mov eax,[tempdw]
    cmp eax,0
    jz exit
    '
    fild dword ptr [tempdw]
    fldl2t
    fmulp st(1),st(0)       '->log2(10)*exponent
    fld st(0)
    frndint                 'get the characteristic of the log
    fxch st(1)
    fsub st(0),st(1)        'get only the fractional part but keep the characteristic
    f2xm1                   '->2^(fractional part)-1
    fld1
    faddp st(1),st(0)                    'add 1 back
    fscale                  're-adjust the exponent part of the REAL number
    fstp  st(1)             'get rid of the characteristic of the log
    fmulp st(1),st(0)       '->16-digit integer
  )


  fbstp [bcd] 'SAVE AS PACKED BINARY CODED DECIMAL


'  /*
'  'TRAP ERRORS
'  '
'  fstsw ax                'retrieve exception flags from FPU
'  fwait
'  shr   eax,1             'test for invalid operation
'  jc    srcerr            'clean-up and return error
'  */


  '
  'EXPAND DIGITS
  '
  lea edx,[bcd]
  lea ecx,[s]
  '
  push esi
  '
  mov esi,10
  '
  'looping
  (
    dec esi
    jl exit
    '
    mov ah,[edx]
    inc edx
    '
    mov al,ah
    and al,15
    add al,48
    mov [ecx],al
    inc ecx
    '
    mov al,ah
    shr al,4
    and al,15
    add al,48
    mov [ecx],al
    inc ecx
    repeat
  )


  mov byte ptr [ecx],0
  '
  'COPY FORMATTED
  '--------------
  '
  mov edx,[pt]
  '
  'NEGATIVE SIGN NEEDED?
  '
  (
    and al,0xf
    jz exit
    mov byte [edx],45
    inc edx
    jmp fwd nex
  )
  '
  'PADDING FOR NON-NEGATIVE NUMBERS
  '
  cmp num.sns,0
  jz fwd nex
  mov byte [edx],32
  inc edx
  '
  nex:
  '
  lea esi,[s]
  add esi,18
  mov cl,19
  mov ah,0
  mov ch,[dp]
  dec ch

  'looping
  (
    dec cl
    jl exit
    '
    'INSERT DECIMAL POINT
    '
    (
      cmp cl,ch
      jnz exit
      '
      'PLACE LEADING ZERO
      '
      (
       cmp dword ptr [num.sdp],0
       jnz exit 'SDP FLAG TO INHIBIT
       cmp ah,0
       jnz exit
       mov byte ptr [edx],48
       inc edx
      )

      mov byte ptr [edx],46
      inc edx
      mov ah,1 'STOP STRIPPING ZEROS
    )

    mov al,[esi]
    dec esi
    (
      (
        cmp ah,0
        jnz faok
      )

      cmp al,48
      jz exit 'STRIP LEADING ZEROS
      mov ah,1 'INHIBIT FUTURE STRIPPING
      faok:
      mov [edx],al
      inc edx
    )

    repeat
  )

  pop esi
  '
  fadone:


  '
  'REMOVE ENDING ZEROS
  '
  (
    cmp dword ptr [num.trz],0
    jz exit
    cmp dword ptr [dp],0
    jz exit
    mov ecx,[pt] 'BASE ADDRESS OF NUMBER STRING
    '
    'looping
    (
      dec edx
      cmp edx,ecx      
      jle xit1 'exit LEAVE FIRST CHARACTER ALONE
      mov al,[edx]
      (
       cmp al,46
       jnz exit
       dec edx
       jmp xit1 'STRIP DOT AND EXIT
      )

      cmp al,48
      jnz exit 'ONLY 'LOOK AT RIGHT HAND ZEROS
      repeat 'STRIP ZERO AND CONTINUE
    )

    '----
    xit1:
    '----
    '
    inc edx
  )
  '
  'ENSURE AT LEAST ONE DIGIT
  '
  mov ecx,[pt]
  mov al,[ecx]
  (
    cmp al,45
    jnz exit
    inc ecx
  )
  '
  (
    cmp ecx,edx
    jnz exit
    mov byte ptr [edx],48
    inc edx
  )
  '
  'CHECK FOR SCIENTIC NOTATION
  '
  (
    cmp dword ptr [sn],0
    jz exit
    cmp dword ptr [nzero],0
    jz exit
    mov eax,[snv]
    cmp eax,0
    jz exit 'E VALUE ZERO SO OMIT
    mov byte ptr [edx],69
    inc edx 'E'
    mov cl,43
    (
      cmp eax,0
      jge exit
      neg eax
      mov cl,45
    )
    '
    mov [edx],cl
    inc edx 'SIGN
    mov cl,100
    div cl
    push eax
    and eax,&hff
    mov cl,10
    div cl
    (
      cmp ax,0
      jz exit
      or eax,&h3030 'TO ASCII THOUSANDS AND HUNDREDS
      ( 
        cmp al,48
        jz exit
        mov [edx],al
        inc edx
      )

      mov [edx],ah
      inc edx
    )

    pop eax
    shr eax,8
    div cl
    or eax,&h3030 'TO ASCII TENS AND UNITS
    mov [edx],aX
    add edx,2
  )
  '
  mov byte ptr [edx],0 'APPEND NULL TERMINATOR
  '
  fadonez:
  '
  'PADDING IF SPECIFIED
  '
  a=32      'offset
  b=edx-pt  'length
  '
  if num.lps then
    if b<num.lps then
      a=a-num.lps+pt 'padding
      b=b+num.lpS-pt 'extra length
    end if
  end if
  '
  'ASSIGN RESULT TO BSTRING
  '
  push b
  lea rcx,t
  add ecx,a
  push ecx
  call SysAllocStringByteLen
  mov dl,1
  return
  '
  end function 'float_to_ascii



  '-------
  hexaval:
  '=======
  '
  'ECX POINTS TO LEFT BOUNDARY OF TEXT NUMBER
  '
  push esi
  xor edx,edx
  xor esi,esi
  '
  ( 'rhexconv:
    inc ecx
    mov al,[ecx]
    cmp al,48 '0
    jb exit 'boundary reached
    '
    'CONVERT TO UPPERCASE
    '
    (
      cmp al,96
      jbe exit
      cmp al,122
      ja exit
      sub al,32
    )
    '
    cmp al,70 'F
    ja exit
    cmp al,57 '9
    jbe nadjal
      cmp al,65
      jb exit 'boundary character
      sub al,7
    nadjal:
    sub al,48 'ascii to hex number
    shld esi,edx,4 'shift nybble
    'o2 0f a4 d6 04 
    shl edx,4
    add dl,al
    '
    'itr overflow
    '
    repeat 'jmp rhexconv
  '
  ) 'nhexconv: 'done conversion 'result in edx
  '
  mov eax,edx 'return lower dword
  mov edx,esi 'possible upper dword
  pop esi
  ret



  '-----------------------------------------------------------
  sub ascii_to_float(byval s as string) external 'at [ebx+192]
  '===========================================================
  '
  sys stt,dpf,dpl,enf,eno,digi,sgf,sgg,ten=10
  sys p=?s 'itr byval string as bstring

  '
  mov ecx,[s]
  '
  '
  'SKIP LEADING WHITE SPACE
  '
  (
    mov al,[ecx]
    cmp al,0
    jz numnok 'end of string (error)
    cmp al,32
    jg exit 'start of word
    inc ecx
    repeat
  )
  '
  mov [stt],ecx 'START OF NUMBER
  '
  cmp al,&h26 '&
  jz n0xn
  cmp al,0x3a '>9
  jae numnok
  '
  'Lookahead for endings h o
  '=========================
  '
  push ecx
  '
  (
    inc ecx
    mov ah,[ecx]
    cmp ah,45 '-' and above
    jae repeat
    '
    'check ending
    '
    dec ecx
    mov ah,[ecx]
    cmp ah,&h3a
    jb exit 'skip numbers
    '
    'uppercase conversion
    '
    (
      cmp ah,&h60
      jbe exit
       sub ah,32
    )
    '
    (
      cmp ah,&h48 'h
      jnz exit
      mov byte ptr [ecx],32
      pop ecx
      dec ecx
      jmp gohexadecimal
    )
    '
    (
      cmp ah,&h4f 'o
      jnz exit
      mov byte ptr [ecx],32
      pop ecx
      dec ecx
      jmp octad
    )
    '
    'cmp ah,&h42 'b itr: incompatible with hexadecimal
    'jnz nafb
    'mov byte ptr [ecx],32
    'pop ecx
    'dec ecx
    'jmp binad
    'nafb:
    '
  )
  '
  '
  pop ecx
  '
  'Check for 0x 0o 0b
  '==================
  '
  cmp al,&h30
  jnz n0xn
  '
  mov ah,[ecx+1]
  (
    cmp ah,&h60
    jbe exit
    sub ah,&h20
  )
  cmp ah,&h3a
  jb n0xn
  mov al,&h26
  jmp numhok  
  '
  '
  'filter word types
  '=================
  '
  n0xn:
  '----
  '
  cmp al,&h23 'include #  special numbers
  jz spnums
  cmp al,&h26 'include &  hex number
  jz numhok
  cmp al,&h2d 'include -  neg number
  jz normf
  cmp al,&h2e 'include .  decimal point
  jz normf
  cmp al,&h30 'exclude below 0
  jb numnok
  cmp al,&h3a 'include below :
  jb normf
  '
  '--------------------------
  numnok: 'cannot be a number
  '==========================
  '
  fldz
  jmp NumErr
  '  
  '---------------------------------
  numhok: 'HEX OCTAL OR BINARY MAYBE
  '=================================
  '
  '
  cmp al,38 '&
  jnz spnums
  '
  inc ecx
  mov al,[ecx]
  (
    cmp al,32
    jg exit
    fldz
    jmp ParseHExit
  )
  '
  'CONVERT TO UPPERCASE
  '
  (
    cmp al,96
    jbe exit
    cmp al,122
    ja exit
    sub al,32
  )
  '
  cmp al,&h48 'H
  jz gohexadecimal
  cmp al,&h58 'X 
  jnz tryoctal
  '
  '
  'HEXADECIMAL
  '-----------
  '
  gohexadecimal:
  '
  call hexaval
  jmp cputofpu
  '
  '
  tryoctal: 'OCTAL
  '--------------
  '
  cmp al,&h4f 'o
  jnz trybinary
  '
  octad:
  '
  xor edx,edx 'zero lower accum
  xor esi,esi 'zero upper accum
  (
    inc ecx
    mov al,[ecx]
    cmp al,48 '0
    jb exit
    cmp al,55 '7
    ja exit
    sub al,48 'ascii to hex number
    shl edx
    rcl esi
    shl edx
    rcl esi
    shl edx
    rcl esi
    add dl,al
    '
    repeat    
  )
  noctconv: 'done conversion
  mov eax,edx
  mov edx,esi
  jmp fwd cputofpu
  '
  '
  '
  '
  trybinary: 'BINARY BITS
  '----------------------
  '
  cmp al,&h42 'b
  jz fwd binad
  fldz
  jmp ParseHExit
  '
  binad:
  '
  xor edx,edx 'zero lower accum
  xor esi,esi 'zero upper accum
  (
    inc ecx
    mov al,[ecx]
    cmp al,48 '0
    jb exit
    cmp al,49 '1
    ja exit
    sub al,48 'ascii to hex number
    shl edx 'shift bit
    rcl esi
    add dl,al
    repeat
  )
  'done conversion
  mov eax,edx
  mov edx,esi
  jmp fwd cputofpu
  '
  '
  'TREAT AS UNSIGNED INTEGER
  '
  cputofpu:
  '
  push edx
  push eax
  fild qword ptr [esp]
  add esp,8
  '
  '
  ParseHExit:
  '
  exit sub
  '
  '---------------
  'SPECIAL NUMBERS
  '---------------
  '
  spnums:
  '
  cmp al,35 '#
  jnz normf 'NORMAL NUMBERS
  '
  inc ecx
  mov eax,[ecx]
  add ecx,4
  or eax,&h20202020 'QUICK LOWERCASE
  '
  (
    cmp eax,&h666e692d '#-INF
    jnz exit
    fld1
    fchs
    fldz
    jmp fwd xitsn
  )
  '
  and eax,&hffffff 'IGNORE 4TH CHAR
  '
  (  
    cmp eax,&h666e69 '#INF
    jnz exit
    fld1
    fldz
    jmp fwd xitsn
  )
  '
  fldz
  fldz
  '
  xitsn:
  '
  fdivp st1
  exit sub
  '
  '
  '-------------------------------------
  normf: 'OTHERWISE CONVENTIONAL NUMBERS
  '-------------------------------------
  '
  fldz
  dec ecx     'PRE DECR
  '
  '---------
  ParseLoop:
  '---------
  '
  (
    inc ecx
    mov al,[ecx]
    cmp al,47
    jz ParseExit
    cmp al,44
    jbe ParseExit
    '
    'TEST FOR E
    '
    ( 'raf3:
      cmp al,&h65 'e
      jz exit
      cmp al,&h45 'E
      jz exit
      jmp nexne   'not e or E
    )
    '
    'E ENCOUNTERED
    '
    (
      mov eax,ecx
      inc eax
      mov [enf],eax
      fldz 'FOR E NUMBER
      mov al,[sgf]
      mov [sgg],al
      mov byte [sgf],0
      jmp ParseLoop
    )
    '
    '-------------------
    nexne: 'BYPASS E SETUP
    '-------------------
    '
    'NEGATIVE SIGN
    '
    (
      cmp al,45
      jnz exit
      cmp byte [sgf],0
      jnz NumErr 'NEG SIGN ALREADY ENCOUNTERED
      mov byte [sgf],1 'SET SIGN FLAG
      jmp ParseLoop
    )
    '
    (
      cmp al,43
      jnz exit
      cmp ecx,[stt]
      jz ParseLoop 'PLUS SIGN AT START OF NUMBER
      cmp byte ptr [sgf],0
      jnz ParseExit 'PLUS SIGN MARKING BOUNDARY OF NUMBER
      cmp [enf],ecx
      jz ParseLoop 'PLUS SIGN IMMEDIATELY FOLLOWING E
      jmp ParseExit
    )
    '
    'CHECK FOR DECIMAL POINT
    '
    ( 'raf7:
      cmp al,46
      jnz exit
      cmp dword [enf],0
      jnz NumErr 'DECIMAL POINT AFTER E
      cmp byte ptr [dpf],0
      jnz NumErr 'DECIMAL POINT ALREADY PRESENT
      mov byte ptr [dpf],1
      jmp ParseLoop
    )
    '
    'VALIDATE DIGIT
    '
    sub al,48
    jb ParseExit 'ASCII BELOW '0'
    cmp al,9
    ja ParseExit 'exit  'ASCII ABOVE '9'
    '
    'ACCUM * 10 + DIGIT
    '
    fimul dword ptr [ten]
    mov [digi],al
    fiadd dword ptr [digi]
    '
    (
      cmp byte ptr [dpf],0
      jz exit  'NO DECIMAL POINT
      cmp [enf],0
      jnz exit 'EXCLUDING E NUMBER
      inc dword ptr [dpl]
    )
    '
    jmp ParseLoop
  )
  '
  '---------
  ParseExit:
  '---------
  '
  'CHECK FOR NEG SIGN
  '
  (
    cmp byte [sgf],0
    jz exit
    fchs
  )
  '
  'NO E NUMBER
  '
  (
    cmp [enf],0
    jnz exit
    cmp [dpl],0
    jz fwd nscale
    fldz
  )
  '
  'SCALE VALUE PRESENT?
  '
  fisub dword ptr [dpl] 'ADJUST SCALER FOR DECIMAL PLACES
  fldl2t
  fmulp  st(1),st(0)   '->log2(10)*exponent
  fld   st(0)
  frndint              'get the characteristic of the log
  fxch
  fsub st,st(1)        'get only the fractional part but keep the characteristic
  f2xm1                '->2^(fractional part)-1
  fld1
  faddp st(1),st(0)    'add 1 back
  fscale               're-adjust the exponent part of the REAL number
  fstp  st(1)          'get rid of the characteristic of the log
  fmulp st(1),st(0)    '->16-digit integer
  '
  nscale:
  '------
  '
  'CHECK FOR NEG SIGN
  (
    cmp byte ptr [sgg],0
    jz exit
    fchs
  )
  '
  numokay: 'NUMBER COMPLETED
  '-------------------------
  '
  'result remains on fpu stack.
  '
  exit sub
  '
  NumErr: 'NUMBER ERRORS
  '---------------------
  '
  'itr runtime error?
  '
  'print "Number error"
 
  end sub



  type guid
    a as long
    b as short
    c as short
    d(8) as byte
  end type


  '--------
  guidvals:
  '========
  '
  '(byref g as guid, byval s as string) external 'at [ebx+352]
  '
  '{dddddddd-wwww-wwww-bbbb-bbbbbbbbbbbb}
  '
  push edi
  mov edi,[esp+8]  'g
  mov ecx,[esp+12] 's
  mov al,[ecx]
  (
    cmp al,123
    jz exit
    dec ecx
  )
  call hexaval
  mov [edi],eax
  call hexaval
  mov [edi+4],ax
  call hexaval
  mov [edi+6],ax
  call hexaval
  mov [edi+8],ah
  mov [edi+9],al
  call hexaval
  mov [edi+10],dh
  mov [edi+11],dl
  mov edx,eax
  shr edx,16
  mov [edi+12],dh
  mov [edi+13],dl
  mov [edi+14],ah
  mov [edi+15],al
  inc ecx 'move to txtguid boundary
  pop edi
  ret


  '----
  ghex:
  '====
  mov dh,al
  and dh,15
  add dh,48
  (
    cmp dh,57
    jle exit
    add dh,7
  )
  shr eax,4
  mov dl,al
  and dl,15
  add dl,48
  (
    cmp dl,57
    jle exit
    add dl,7
  )
  shr eax,4
  ret


  '--------
  guidtxts:
  '========
  '
  '(byref g as guid) as sys external ' as string at [ebx+360]
  '
  push esi
  push edi
  push 38
  push 0
  call SysAllocStringByteLen
  mov edi,eax
  push eax
  mov ecx,[esp+16] 'guid pointer g
  mov byte ptr [edi],123
  mov byte ptr [edi+37],125
  inc edi
  '--------
  'dddddddd
  '--------
  mov eax,[ecx]
  call ghex
  mov [edi+6],dx
  call ghex
  mov [edi+4],dx
  call ghex
  mov [edi+2],dx
  call ghex
  mov [edi],dx
  mov byte ptr [edi+8],45
  add edi,9
  '----
  'wwww
  '----
  mov ax,[ecx+4]
  call ghex
  mov [edi+2],dx
  call ghex
  mov [edi],dx
  mov byte ptr [edi+4],45
  add edi,5
  '----
  'wwww
  '----
  mov ax,[ecx+6]
  call ghex
  mov [edi+2],dx
  call ghex
  mov [edi],dx
  mov byte ptr [edi+4],45
  add edi,5
  '----
  'bbbb
  '----
  mov ax,[ecx+8]
  call ghex
  mov [edi],dx
  call ghex
  mov [edi+2],dx
  mov byte ptr [edi+4],45
  add edi,5
  '------------
  'bbbbbbbbbbbb
  '------------
  add ecx,10
  mov esi,6
  rghexb:
    mov al,[ecx]
    call ghex
    mov [edi],dx
    inc ecx
    add edi,2
    dec esi
  ja rghexb
  '--------
  pop eax
  pop edi
  pop esi
  ret

  '-----------------------
  getmem: 'bstr at [ebx+8]
  '=======================
  mov eax, [esp+4] 'requested size
  push eax
  push 0
  'call SysAllocStringByteLen
  call [ebx+160]
  '
  'initialise
  '----------
  '
  mov edx,eax     'pointer
  mov ecx,[eax-4] 'length
  '
  'STEP 4 BYTES
  (
    sub ecx,4
    jl exit
    mov [edx],0
    add edx,4
    repeat
  )
  add ecx,4
  '
  'STEP SINGLE BYTES REMAINDER
  (
    dec ecx
    jl exit
    mov byte ptr [edx],0
    inc edx
    repeat
  )
  ret 4



  '-------------------------
  FreeMem: 'bstr at [ebx+16]
  '=========================
  mov eax,[esp+4]
  cmp eax,0
  jz nfreestr
    push eax
    'call SysFreeString
    call [ebx+168]
  nfreestr:
  ret 4

/*

  '----------------------------------------------
  sub binderr(char*z,sys e) external 'ebx restore
  '==============================================
  '
  'ADD TO RUNTIME ERRORS
  '
  if len(ers)<1024 then ers+="Unable to bind "+z+chr(13,10)
  '
  end sub



  '-----------------------------------------------------------------------------------
  sub procaddrs(byval li as sys, byval p as sys, byval a as sys) external 'at [ebx+48]
  '===================================================================================
  dim as sys erc
  mov esi,[p]  ' NAME LIST PTR
  mov edi,[a]  ' PROC ADDRESS LIST PTR
  '
  '--------------------
  'CHAR COLLECTION LOOP
  '--------------------
  '
  dec esi
  rprocl:
    inc esi
    mov al,[esi]
    cmp al,3 'SIGNAL END OF LIST
    jz xprocl
    cmp al,32
    jle rprocl
    mov ecx,esi 'START OF PROCNAME
    dec esi
  rproclw:
    inc esi
    mov al,[esi]
    '
    'CHECK FOR LIST TERMINATOR
    '-------------------------
    '
    cmp al,3
    jz xprocl
    '
    'CHECK FOR NAME BOUNDARY (NULL CRLF ETC)
    '-----------------------
    '
    cmp al,32
    jg rproclw
    '
    'PREPARE PROC NAME
    '-----------------
    '
    'NO PATCHING ALLOWED IN PE CODE SECTION
    'mov byte ptr [esi],0 'PATCH NULL TERMINATOR
    '
    push ecx ' PRESERVE START OF NAME
    '
    'GET PROC ADDRESS
    '----------------
    '
    'push ecx  ' START OF NAME
    'push [li] ' LIB HANDLE
    'call GetProcAddress
    GetProcAddress li,ecx
    '
    pop ecx ' RESTORE START OF NAME PTR
    '
    'CHECK VALID
    '-----------
    '
    cmp eax,0
    jnz cprocl 'WAS VALID PROCADDRESS
      mov eax,esi
      sub eax,ecx
      push eax
      push ecx
      call binderr 'ebx
      'inc dword ptr [erc]
    cprocl:
    '
    'PATCH ADDRESS INTO TABLE
    '------------------------
    '
    mov [edi],eax
    add edi,4
    '
    'NEXT PROC NAME
    '--------------
    '
    jmp rprocl
    '
    'END OF LIST
    '-----------
    '
  xprocl:
  '
  if erc then
    MessageBox 0,ers,"Binding Error",0 'terminate app?
  end if
  end sub

*/

  '-------------------
  copys0: 'at [ebx+56]
  '===================
  '
  mov edx,[esp+4] 'dest
  mov ecx,[esp+8] 'source
  (
    mov al,[ecx]
    mov [edx],al
    inc ecx
    inc edx
    cmp al,0
    jnz repeat
  )
  ret 8


  '--------------------
  copys00: 'at [ebx+64]
  '====================
  '
  mov edx,[esp+4] 'dest
  mov ecx,[esp+8] 'source
  (
    mov ax,[ecx]
    mov [edx],ax
    inc ecx
    inc ecx
    inc edx
    inc edx
    cmp ax,0
    jnz repeat
  )
  ret 8



  '-------------------
  copysn: 'at [ebx+72]
  '===================
  '
  push ecx
  push esi
  push edi
  mov edi,[esp+16] 'dest
  mov esi,[esp+20] 'source
  mov ecx,[esp+24] 'length
  '
  (
    dec ecx
    jl  exit
    mov al,[esi]
    mov [edi],al
    inc esi
    inc edi
    repeat
  )
  pop edi
  pop esi
  pop ecx
  ret 12



  '##############################
  '
  '     #####    #####   #     #
  '    #     #  #     #  #     #
  '    #     #        #  #     #
  '    #     #   #####   #######
  '    #     #  #        #     #
  '    #     #  #        #     #
  '     #####   #######  #     #
  '
  '##############################


  '---------------------------------------------------------------
  function hexsl(sys min_len) as sys, external,label 'at [ebx+216]
  '===============================================================
  '
  'extended for quad values
  'build hex string form right to left
  'starting with least significant
  '
  sub esp,64 'workspace
  mov esi,esp
  fistp qword ptr [esi] 'save as quad integer
  mov edx,[esi]
  add esi,32  'offset for working backwards
  mov edi,esi 'hold end position
  inc edi
  'mov byte ptr [edi],32 'endstop space
  push edi
  mov edx,[esi-32] 'lower dword
  mov edi,[esi-28] 'upper dword
  '
  call hextoc
  mov edx,edi 'load upper dword
  call hextoc
  '
  pop edi
  jmp rtrimzer
  '
  hextoc: 'convert nybbles to hex chars
  '------------------------------------
  '
  mov ecx,8 'down count
  '
  rhextoc: 'cycle thru hex nybbles
  '
  mov al,dl
  shr edx,4
  and al,15
  add al,48
  cmp al,58
  jb nadjhexal
  add al,7
  nadjhexal:
  mov [esi],al
  dec esi 'move to left
  dec ecx 'downcount
  '
  jg rhextoc
  ret
  '
  rtrimzer:  'trim leading zeros (left to right)
  '---------------------------------------------
  '
  inc esi
  mov al,[esi]
  cmp al,48 'is it a leading zero?
  jz rtrimzer
  '
  cmp esi,edi
  jl nsinglez 'leave at least one '0' digit
  dec esi
  nsinglez:
  '
  'copy into a new bstring
  '-----------------------
  '
  sub edi,esi 'calc length
  cmp dword ptr [min_len],0
  jz nplzero
    mov eax,[min_len]
    sub eax,edi
    cmp eax,0
      jle nplzero
      sub esi,eax
    add edi,eax
  nplzero:
  push edi 'length
  push esi 'pointer
  'call SysAllocStringByteLen
  call [ebx+160] 'AllocString 'create BSTR
  mov [function],eax 'return it
  add esp,64 'release workspace
  '
  end function


  '-------------------
  hexs:  'at [ebx+208]
  '===================
  call hexsl 0
  ret 4


  '------------------------------------------------------------------------------------------------------
  function instrsh(byval i as sys, byval s0 as string, byval w0 as string ) as sys external 'at [ebx+320]
  '======================================================================================================
  push ebx
  push esi
  mov ebx,[i]
  dec ebx
  cmp ebx,0
  jl xinstr       'invalid offset
  mov edi,[s0]    'main string
  cmp edi,0
  jz xinstr       'empty string
  mov edx,[w0]    'keyword
  cmp edx,0
  jz xinstr       'empty keyword
  mov ecx,[edx-4] 'length of keyword
  '
  mov esi,edi
  add esi,[edi-4] 'main string boundary
  sub esi,ecx     'minus length of keyword
  mov eax,esi     'search limit
  sub eax,ebx     'offset
  cmp eax,edi     '
  jl xinstr       'no room for keyword
  '
  add edi,ebx     'set offset
  mov ah,[edx]
  '
  trinstr:
  '-------
    cmp edi,esi 'boundary check
    jg xinstr
    mov al,[edi]
    inc edi
    cmp al,ah
    jnz trinstr 'check 1st letter against next
    '
    push edi
    push edx
    push ecx
    inc edx   'second letter
    rinstr:
    '------
      dec ecx     'downcount (second letter onward)
      jle ninstr  'match complete
      mov al,[edi]
      cmp al,[edx]
      jnz nminstr
      inc edx
      inc edi
    jmp rinstr
    '
    nminstr: 'no match
  pop ecx
  pop edx
  pop edi
  jmp trinstr 'carry on searching
  '
  ninstr: 'done
  '------------
  pop ecx
  pop edx
  pop edi
  sub edi,[s0]
  mov [function],edi
  '
  xinstr: 'exit
  '------------
  pop esi
  pop ebx
  end function



  '-----------------------------------------------------------------
  function getfiles(byval w as string) as sys external 'at [ebx+336]
  '=================================================================
  '
  dim as sys b,h,p,pf,ph,le,leh
  '
  '
  'CHECK VALID NAME
  '
  cmp dword ptr [w],0
  jz ngetfile
  '
  'OPEN FILE
  '
  push 0             'HANDLE hTemplateFile OPT
  push 128           'FILE_ATTRIBUTE_NORMAL
  push 3             'CREATE (NEW 1) (ALWAYS 2) (OPEN 4) (OPEN EXISTING 3)
  push 0             'LP SECURITY  ATTRIBUTES OPT
  push 1             'SHARE MODE read(1) write(2)
  push &h80000000    'GENERIC_READ (0x80000000) GENERIC_WRITE (0x40000000)
  push [w] 'name
  call Createfile
  mov [h],eax
  '
  'SET FILE POINTER
  '
  push 0              'DWORD dwMoveMethod 0,FILE_BEGIN(0) FILE_CURRENT(1) FILE_END (2) 
  lea eax,[ph]        'PLONG lpDistanceToMoveHigh
  push eax
  push 0              'LONG lDistanceToMove
  push [h]            'DWORD HANDLE
  call SetFilePointer '
  mov [pf],eax        'File Pointer position low
  '
  'GET FILE SIZE
  '
  lea eax,[leh]       'PLONG lpFileSizeHigh
  push eax            '
  push [h]            'DWORD HANDLE
  call GetFileSize    '
  mov [le],eax        '
  '
  'CREATE STRING BUFFER
  '
  push [le]           'FILE LENGTH
  push 0              'OPTIONAL COPY POINTER
  call SysAllocStringByteLen 'CREATE BSTR
  mov [p],eax
  mov [function],eax
  '
  'READ FILE
  '
  push 0              'LPOVERLAPPED lpOverlapped
  lea eax,[b]         'lpNumberOfBytesRead
  push eax            '
  push [le]           'DWORD nNumberOfBytesToRead
  push [p]            'LPVOID lpBuffer
  push [h]            'DWORD HANDLE
  call ReadFile
  '
  push [h]
  call CloseHandle
  '
  ngetfile:
  '
  'CLOSE HANDLE
  '
  end function



  '---------------------------------------------------------------------------------------
  function putfilen(byval w as string, byval s as string, byval le as sys) as sys external
  '=======================================================================================
  '
  dim as sys b,h,p,pf,ph,leh
  '
    '
    'CHECK VALID NAME
    '
    xor eax,eax
    cmp dword ptr [w],0
    jz nputfile
    '
    'OPEN FILE
    '
    push 0             'HANDLE hTemplateFile OPT
    push 128           'FILE_ATTRIBUTE_NORMAL
    push 2             'CREATE (NEW 1) (ALWAYS 2) (OPEN 4) (OPEN EXISTING 3)
    push 0             'LP SECURITY  ATTRIBUTES OPT
    push 0             'SHARE MODE read(1) write(2)
    push &h40000000    'GENERIC_READ (0x80000000) GENERIC_WRITE (0x40000000)
    push [w] 'name
    call Createfile
    mov [h],eax
    '
    'SET FILE POINTER
    '
    push 0              'DWORD dwMoveMethod 0,FILE_BEGIN(0) FILE_CURRENT(1) FILE_END (2) 
    lea eax,[ph]        'PLONG lpDistanceToMoveHigh
    push eax
    push 0              'LONG lDistanceToMove
    push [h]            'DWORD HANDLE
    call SetFilePointer '
    mov [pf],eax        'File Pointer position low
    '
    'WRITEFILE
    '
    push 0              'LPOVERLAPPED lpOverlapped
    lea eax,[b]         'lpNumberOfBytesWritten
    push eax            '
    push [le]           'DWORD nNumberOfBytesToWrite
    push [s]            'LPVOID lpBuffer
    push [h]            'DWORD HANDLE
    call WriteFile
    mov [function],eax
    '
    'CLOSE HANDLE
    '
    push [h]
    call CloseHandle

    '
    nputfile:
    '
  end function


  '-----------------------------------------------------------------------------------
  function putfiles(byval w as string,byval s as string) as sys external 'at [ebx+344]
  '===================================================================================
    '
    'GET LENGTH of BSTR TO WRITE
    '
    mov eax,[s]
    '
    '
    push dword ptr [eax-4]
    push [s]
    push [w]
    call putfilen#string#string#sys
    mov dword ptr [function],1
    '
  end function




  '-------------------------------------------------
  Function errors() as string external 'at [ebx+128]
  '=================================================
  '
  function=ers
  ers="" 'clear the error buffer
  end function



  '##############################'
  '##                            #
  '##                            #
  '##############################'
  ' ############################
  ' # ||                     | #
  ' # ||       MAP           | #
  ' # ||    FUNCTIONS        | #
  ' # ||                     | #
  ' # ||                     | #
  ' # ||                     | #
  ' # ||                     | #
  ' # ||                     | #
  '##############################'
  '##                            #
  '##############################'
  '

  ._mem
  call fwd here
  .here
  pop ebx
  sub ebx,here
  add ebx,bssdata
  ret


  noof:
  '====
  ret




  '--------------------
  mboxs: 'at [ebx+2048]
  '===================
  mov eax,[esp+4]  '
  pusha            '
  push &h48324f      ' title: O2H
  mov ecx,esp      '
  push 0           '
  push ecx         ' title string
  push eax         ' message string
  push 0           '
  call messagebox  '
  pop eax          ' unstack title string
  popa             '
  ret 4            '

  '----------------------
  addlist: 'at [ebx+2064] ' ( eax strptr edi list pointer ) retains string pointer in eax : return ptr edi for dyn string
  '=====================
  addlisti:        '
  push ecx         'save reg
  push edi         'address of list ptr
  mov edi,[edi]    'address of list 'lea edi,[ebx+...]
  cmp edi,0
  jnz nnewbuf
    push eax
    push 512        'buffer size
    call getmem
    mov edi,eax
    mov eax,[esp+4]
    mov [eax],edi    'store new root buffer pointer
    pop eax
  nnewbuf:
  '
  mov ecx,[edi+4]  '
  add ecx,16       '
  cmp ecx,512      'check against list length 4096
  jl addsok        'skip if within list
    '
    'CREATE NEW LIST AND ADD TO CHAIN OF LISTS
    '
    push eax       'save BSTR
    '
    push 512       'list block size
    call getmem    'space filled with nulls
    '
    mov ecx,[esp+4]'get base list ptr 2nd up on stack
    mov [ecx],eax  'assign as current list in .. to [ebx+ ...]
    mov [eax],edi  'link chain backward from new list to previous list
    mov edi,eax    'make this list current in edi
    mov ecx,16
    '
    pop eax        ' restore BSTR
    '
  '------------------'
  addsok:           '
  add dword ptr [edi+4],4    ' new ubound offset
  add edi,ecx      'new edi for dynamic string
  mov [edi],eax    'save BSTR
  pop ecx          'discard main list ptr
  pop ecx          'restore original string pointer
  ret              '



  'DELETE STRINGS IN LIST
  '======================


  '---------------------
  delist: 'at [ebx+2072]      ' (ecx index_limit edi list pointer)
  '====================
  '
  delisti:
  '---------
  '
  push esi
  '
  delisti1:
  '--------
  '
  mov esi,[edi+4]  'ubound
  '
  rdofreem:        '
    sub esi,4      'in reverse order
    jl xdofreem    'done or empty 
    push [edi+esi+16]  'get bstring
    call freemem   'free the string
  jmp rdofreem     '
  '
  xdofreem: 'list completed
  '
  mov esi,[edi]    'check for back link
  cmp esi,0        '
  jz xdofreem1     'no more lists
  push edi         'as param for freemem
  call freemem     'free original list (already on stack)
  mov edi,esi      'back link
  jmp delisti1     'go for next list
  '
  xdofreem1:
  '
  mov dword ptr [edi+4],0 'zero records
  pop esi          'restore esi
  ret              '



  'DELETE CHAINED LISTS OF STRINGS BACKWARDS
  '=========================================
                   
  '-----------------------
  delchain: 'at [ebx+2080]
  '=======================
  '
  delchaini:
  '       '
  cmp dword ptr [edi],0 'no list available
  jz ndelchain     '
  '
  push eax
  push edx         '
  '
  push edi         'address of list chain
  mov edi,[edi]    'first list in the chain
  call delisti     'delete current list bstrs
  pop edx          '
  mov [edx],edi    'make current base list
  mov edi,edx      'restore list chain base
  '
  pop edx
  pop eax
  ndelchain:
  ret

  '-----------------------
  strinstl: 'at [ebx+2088]
  '=======================
  '
  cmp dword ptr [ecx],0
  jz nstrinstl
  ret
  nstrinstl:
  push ecx
  push 0
  call getmem
  pop ecx
  lea edi,[ebp-4]
  call addlisti
  mov [ecx],edi  ' assign pointer to variable
  ret


  '-----------------------
  strinstg: 'at [ebx+2096]
  '=======================
  '
  cmp dword ptr [ecx],0
  jz nstrinstg
  ret
  nstrinstg:
  push ecx
  push 0
  call getmem
  pop ecx
  'mov eax,0
  lea edi,[ebx+664]
  call addlisti
  mov [ecx],edi  ' assign pointer to variable
  ret


  '---------------------
  deltmp: 'at [ebx+2104]
  '=====================
  '
  deltmpi:
  lea edi,[ebp-8]
  call delchaini 'delete temp strings
  ret


  '---------------------
  delloc: 'at [ebx+2112]
  '=====================
  '
  lea edi,[ebp-4]
  call delbuf 'delete local strings and buffer
  ret

  '-----------------------
  compnnul: 'at [ebx+2128]
  '=======================
  '
  mov ecx,[esp+8]  ' length
  mov edi,[esp+4]  ' address
  cmp edi,0        ' test null pointer
  jz cmpbnok       '
  '
  cmpbdo:          ' compare each char
    dec ecx   
    jge cmpb2
      '
      'end string zero flag
      '
      xor eax,eax
      ret 8
    cmpb2:
    cmp byte ptr [edi],0
    jnz cmpbnok    '
    inc edi        '
  jmp cmpbdo       '
  cmpbnok:
  ret 8




  '===============================
  'SYSTEM BUFFERS FOR STRING LISTS
  '===============================
  '...at startup

  '-------------------------
  sysdelbufs: 'at [ebx+2144]
  '=========================
  '         '
  push eax
  #ifndef dll
    'lea edi,[ebp-8]   'temp list
    'call delbuf
    'lea edi,[ebp-4]  'local list
    'call delbuf
  #endif
  lea edi,[ebx+664] 'global list
  call delbuf
  push [ebx+680]    'lib handle buffer
  call freemem
  pop eax
  ret

   delbuf:
  '=======
  '
  cmp dword ptr [edi],0
  jz ndempty
  call delchaini 'delete strings in list
  push [edi]
  call freemem     'free this final list
  mov dword ptr [edi],0
  ndempty:
  ret


  'PREPARE JOIN-BUFFER
  '
  '------------------------
  catbufprp: 'at [ebx+2152]
  '========================
  '
  push edi
  push eax
  'mov edi,[ebx+640]
  mov edi,[ebp-12]
  cmp edi,0
  jnz ncatbufmem
    push 1024
    call getmem
    mov [ebp-12],eax
    mov edi,eax
    mov dword ptr [edi],16 
    mov dword ptr [edi+16],-1
  ncatbufmem:
  '
  add dword ptr [edi],16 'stride
  add edi,[edi]
  mov dword ptr [edi-16],-1 'PLACE STOP MARKER AT OFFSET 16 OR MORE
  pop eax
  pop edi
  ret


  'ADD BSTR TO LIST  ' byref ptr in eax, list in edi


  '-------------
  badcatl: '2160     ' ptr in eax, list in edi
  '=============
  cmp eax,0         'pointer exist?
  jnz badcatl1      '
  ret
  '
  badcatl1:        '
  '--------
  '
  mov eax,[eax]    'deref
  cmp eax,0        'check pointer
  jnz badcatl2     '
  ret
  '
  badcatl2:
  '--------
  '
  mov ecx,[eax-4]   'get length
  cmp ecx,0
  jg badcatl3
  ret
  '
  badcatl3:
  '--------
  '
  push esi
  push edi
  'mov edi,[ebx+640] 'catlist
  mov edi,[ebp-12]  'cat list 
  mov esi,[edi]     'next place
  add dword ptr [edi],16 'stride increment
  add edi,esi       'location
  '
  mov [edi],ecx     'store byte length
  mov [edi+4],eax   'store pointer
  mov [edi+8],edx   'store type
  pop edi
  pop esi
  ret               '

  '
  'ADD BSTR TO LIST  ' byval bstr in eax, list in edi
  '
  '-------------
  sadcatl: '2168     ' bstr byval in eax
  '============='
  cmp eax,0
  jnz badcatl2
  ret

  'ADD ZSTR TO LIST  '

  '-------------
  zadcatl: '2176     ' ptr in eax
  '=============
  '
  cmp eax,0 'check for null pointer
  jnz nzad
  ret
  nzad:
  call lenzi
  cmp ecx,0
  jg badcatl3
  ret


  '-----
  lenz:
  '=====
  mov eax, [esp+4]
  call lenzi
  mov eax,ecx
  cmp dl,2
  jnz nwidelen
  shr eax,1
  nwidelen:
  ret 4


  '-----
  lenzi:
  '=====
  '
  cmp dl,2
  jz lenz2
  '
  push eax        ' save string base pointer
  push edx        '
  xor ecx,ecx     ' clear counter
  rlenz1:         '
    mov dl,[eax]  ' get character
    inc ecx       ' add to count
    inc eax       ' add to pointer
    cmp dl,0      ' is it a null char
  jnz rlenz1      ' repeat if not
  pop edx         '
  pop eax         ' restore string base pointer
  dec ecx         ' count excluding null terminator char
  ret
  '
  '-----
  lenz2:
  '-----
  '
  push eax        ' save string base pointer
  push edx        '
  xor ecx,ecx     ' clear counter         ' 
  rlenz2:         '
    mov dx,[eax]  ' get character
    add ecx,2     ' add to count
    add eax,2     ' add to pointer
    cmp dx,0      ' is it a null char
    jnz rlenz2    ' repeat if not
  pop edx
  pop eax         ' restore string base pointer
  sub ecx,2       ' count excluding null terminator char
  ret


  'JOIN STRINGS TOGETHER
  '
  '-----------
  joins: '2184        ' ( eax destptr if exists, edi list of strings to) eax new string ptr
  '==========='
  '                 '
  joinsi:           '
  '                 '
  push esi          'save reg
  push edi          'save reg
  '
  'mov edi,[ebx+640] 'the join string list
  mov edi,[ebp-12]  'the join string list
  mov esi,[edi]     'count step
  '
  add edi,esi       'boundary of data
  mov dword ptr [edi],-1 'set end stop
  sub esi,16        'base zero
  '------------------ '
  push edx          'save wide char flag
  xor ecx,ecx       'byte counter
  '
  '-------
  docount:          'iterate through strings in reverse
  '-------
    '
    sub edi,16      'last data downward
    sub esi,16      'down counter
    jl xdocount     'exit
    mov edx,[edi]   '
    cmp edx,-1      'CHECK FOR STOP MARKER
    jz xdocount     '
    '
    'ADJUSTMENT FOR WIDE CHARACTERS
    '
    cmp byte ptr [edi+8],2 'wide string?
    jnz ndivco
    shr edx,1 'convert to wide character count
    ndivco:
    add ecx,edx     'add length of string
    '
  jmp docount       'repeat
  '
  xdocount:         'finished counting bytes
  '
  mov esi,ecx       'byte total req
  pop ecx ' wide string flag
  cmp cl,2
  jnz nscalcha
  shl esi,1 'SCALE FOR WIDE STRING DEST
  nscalcha:
  '
  '
  'CHECK EMPTY (NO CHARS COUNTED)
  '
  cmp esi,0
  jnz nejoinsi
    cmp eax,0
    jz nejoinsi 'to create a null Bstring
    mov word ptr [eax],0 ' PLACE NULL TERMINATION: (2 NULL BYTES)
    jmp ajoinsi 'finish early    
  nejoinsi:
  '
  'accepts 0 byte requests
  '
  cmp eax,0         'request new Bstring or use existing Zstring
  '
  'itr check overflow before
  '
  jnz nnews
    push ecx        'save wide string flag
    push esi        'req n bytes
    call getmem     'create new string
    pop ecx         'restore wide string flag
    cmp eax,0       'test for success
    jz ajoinsi      'failure so exit with null bstr
    cmp dword ptr [eax-4],0
    jz ajoinsi      'no bytes to transfer so exit with valid bstr
    jmp dnews       'otherwise prepare for copy joining
  '
  nnews: 'for Zstrings
  '
  mov word ptr [eax+esi],0 'insert double null into target boundary
  '
  '-----
  dnews: 'entry point for copy joining
  '-----
  '
  '
  push eax          'target base
  push edi          'save stop point
  '
  cmp cl,2          'check for wide dest
  mov ecx,esi       'byte count
  jz rcopa2
  '
  '------------------------------------------
  rcopa1: 'append each string to ascii string
  '==========================================
  '
  add edi,16       'step forward for next string
  mov ecx,[edi]    'LENGTH OR STOP MARKER
  cmp ecx,-1       'end stop
  jz xcopa         'copied all the bytes so exit
  '
  cmp ecx,0
  jle rcopa1
  '
  mov esi,[edi+4] 'pointer    
  cmp byte ptr [edi+8],2 'wide strings
  jz rcops12
  '
  '------------------------------
  rcops11: 'asc to asc string copy
  '------------------------------
  '               'copy over
  mov dl,[esi]  'source byte
  mov [eax],dl  'dest
  inc eax       'inc dest
  inc esi       'inc src
  dec ecx       'downcount souce bytes to copy
  jg rcops11    'continue copying
  jmp rcopa1
  '
  '
  '-----------------------------------
  rcops12: ' wide to ascii string copy
  '-----------------------------------
  ' 
  mov dx,[esi]  'source byte
  mov [eax],dl  'dest
  inc eax       'inc dest
  add esi,2     'inc src
  sub ecx,2     'downcount source bytes to copy
  jg rcops12    'continue copying
  jmp rcopa1
  '
  '
  '-----------------------------------------
  rcopa2: 'append each string to wide string
  '=========================================
  '
  add edi,16       'step forward for next string
  mov ecx,[edi]    'LENGTH OR STOP MARKER
  cmp ecx,-1       'end stop
  jz xcopa         'copied all the bytes so exit
  cmp ecx,0
  jle rcopa2
  '
  mov esi,[edi+4] 'pointer    
  cmp byte ptr [edi+8],2 'wide strings
  jz rcops22
  '
  '--------------------------------
  rcops21: 'asc to wide string copy
  '--------------------------------
  '
  xor edx,edx   'clear transfer reg
  mov dl,[esi]  'source byte
  mov [eax],dx  'dest wide string
  add eax,2     'inc dest
  inc esi       'inc src
  dec ecx       'downcount source bytes to copy
  jg rcops21    'continue copying
  jmp rcopa2
  '
  '
  '----------------------------------
  rcops22: ' wide to wide string copy
  '----------------------------------
  ' 
  mov dx,[esi]  'source byte
  mov [eax],dx  'dest
  add eax,2     'inc dest
  add esi,2     'inc src
  sub ecx,2     'downcount source bytes to copy
  jg rcops22    'continue copying
  jmp rcopa2
  '
  '
  '(null string or Bstring denied)
  '
  '
  xcopa: 'terminate join procedure
  '-----
  '
  pop edi           'restore stop point
  pop eax           'restore target base
  '
  ajoinsi: 'cleardown for zero byte strings (or Bstring denied)
  '-------
  '
  'mov edx,[ebx+640]
  mov edx,[ebp-12]
  sub edi,edx
  mov [edx],edi    'boundary for prior concatenation segment
  '
  '
  xjoinsi:
  '-------
  '
  pop edi          'restore edi
  pop esi          'restore esi
  ret     
  


  'COMPARE DYNAMIC STRINGS

  '--------------------
  comps: 'at [ebx+2192] '(compare [esp+8]-[esp+4] )
  '====================
               '
  compsi:          ' select least length
  mov edx,[esp+8]  ' left string
  mov ecx,[esp+4]  ' right string
  cmp edx,0        ' test null ptr
  jz cmpnok1       '
  mov edx,[edx-4]  '
  cmpnok1:         '
  cmp ecx,0        ' test null ptr
  jz cmpnok2       '
  mov ecx,[ecx-4]  '
  cmpnok2:         '
  cmp edx,0        ' test zero length
  jz cmpnok        '
  cmp ecx,0        ' test zero length
  jz cmpnok        '
  cmp edx,ecx      '
  cmovl ecx,edx    ' select least length
  mov edx,[esp+8]  '
  mov edi,[esp+4]  '
  cmpdo:           ' compare each char
    mov al,[edx]   ' from L string 
    cmp al,[edi]   ' from R string
    jnz cmpxr1     '
    inc edx        '
    inc edi        '
    dec ecx        '
  jge cmpdo        '
                   ' tie break: which string is longer
  mov edx,[esp+8]  '
  mov edx,[edx-4]  ' get  Llength
  mov ecx,[esp+4]  '
  mov ecx,[ecx-4]  ' get R length
  cmpnok:         '
  cmp edx,ecx      ' null ptrs, null lengths or tie breaks
  cmpxr1:          ' flags hold result
  ret 8            '




  'COMPARE Z STRINGS


  '--------------------
  compz: 'at [ebx+2200] '(compare [esp+8]-[esp+4] ) zstrings
  '===================
  '
  mov edx,[esp+8]  '
  mov ecx,[esp+4]  '
  cmp edx,0        ' test null pointers
  jz cmpznok       '
  cmp ecx,0
  jz cmpznok       '
  mov edi,ecx      '
  cmpzdo:          ' compare each char
    mov al,[edx]   ' from L string
    mov cl,[edi]   '
    cmp al,cl      ' from R string
    jnz cmpzxr     '
    cmp al,0       '
    jz cmpzxr      '
    inc edx        '
    inc edi        '
  jmp cmpzdo       '
  cmpzxr:          ' flags hold result
  ret 8            '
  cmpznok:
  cmp edx,ecx
  ret 8

                 '

  'ADD BSTR TO GLOBAL LIST

  '---------------------
  assglo: 'at [ebx+2208]
  '=====================
  '               '
  lea edi,[ebx+664]
  call addlisti
  ret


  'ADD BSTR TO LOCAL LIST

  '---------------------
  assloc: 'at [ebx+2216]
  '=====================
  '               '
  lea edi,[ebp-4]
  call addlisti
  ret


  'ADD BSTR TO TEMP LIST

  '---------------------
  asstmp: 'at [ebx+2224]
  '=====================
  '
  asstmpi:
  lea edi,[ebp-8]
  call addlisti
  ret


  'ASSIGN LOCAL BSTRING

  '---------------------
  asstrl: 'at [ebx+2240] 'dyn addr in ecx, bstr in eax
  '=====================
  '
  mov edi,[ecx]    '
  cmp edi,0        ' pointer exists?
  jnz naddl        '
    lea edi,[ebp-4]'
    call addlisti  ' add to chainable list
    mov [ecx],edi  ' assign pointer to variable
    ret
  naddl:           '
  cmp dword ptr [edi],0 ' bstring already exists?
  jz nwipe         '
    push eax       '
    push [edi]     '
    call freemem   ' release original bstr
    pop eax        '
  nwipe:           '
  mov [edi],eax    ' assign bstr to pointer
  ret                '


  'ASSIGN GLOBAL/STATIC BSTR

  '---------------------
  asstrg: 'at [ebx+2248] 'dyn addr in ecx, bstr in eax
  '=====================
  '
  mov edi,[ecx]    '
  cmp edi,0        ' pointer exists?
  jnz naddlg       '
    lea edi,[ebx+664]
    call addlisti  ' add to chainable list
    mov [ecx],edi  ' assign pointer to variable
     ret
  naddlg:          '
  cmp dword ptr [edi],0' bstring already exists?
  jz nwipeg        '
    push eax
    push [edi]     '
    call freemem   ' release original bstr
    pop eax        '
  nwipeg:          '
  mov [edi],eax    ' assign bstr to pointer
  ret                '


  'TRANSFER BSTRING (return value in function)

  '---------------------
  trbstr: 'at [ebx+2256] 'transfer dyn string for returning BSTR
  '=====================
  '
  cmp edi,0        '
  jnz nxis1        '
    xor eax,eax    '
    ret            '
  nxis1:           '
  cmp dword ptr [edi],0 ' string already exists?
  jnz nxis2        '
    xor eax,eax    '
    ret            '
  nxis2:           '
  mov eax,[edi]    '
  mov dword ptr [edi],0 ' null record on del list
  ret                '



  'BSTRING BYREF COMPARE

  '---------------------
  compis: 'at [ebx+2280] 'bstr byref compare operand with accum
  '=====================
  '
  mov eax,[esp+8]    ' operand
  cmp eax,0          '
  jz ncompis         '
  mov eax,[eax]      '
  ncompis:           '
  mov [esp+8],eax  '
  jmp compsi         '



  '----------------------
  compris: 'at [ebx+2288] 'bstr byref compare with accum with operand
  '======================
  '
  mov eax,[esp+8]    ' operand
  cmp eax,0          '
  jz ncompris        '
  mov eax,[eax]      '
  ncompris:          '
  mov ecx,[esp+4]  '
  mov [esp+8],ecx  ' swap so that accum is compared with operand
  mov [esp+4],eax  ' 
  jmp compsi         '

'====
  'DEREF IF POSSIBLE OR RETURN 0

  '---------------------
  deref0: 'at [ebx+2296]
  '=====================
  '
  cmp eax,0
  jnz derefok
  ret
  derefok:
  mov eax,[eax]
  ret


  '--------------------
  compn: 'at [ebx+2304]  'COMPARE [esp+12] WITH [esp+4] NSTRING
  '====================
  '
  mov edx,[esp+12] ' lstring
  mov edi,[esp+4]  ' rstring
  cmp edx,0        ' test null pointer
  jz cmpnnok       '
  cmp edi,0        ' test null pointer
  jz cmpnnok       '
  mov ecx,[esp+16]  ' length lstring
  cmp ecx,[esp+8]   ' compare length of rstring
  cmovg ecx,[esp+8] 'least length
  '
  cmpndo:           ' compare each char
    dec ecx   
    jge cmpn2
      '
      'tie break on length
      '
      mov ecx,[esp+16] 'l length
      cmp ecx,[esp+8]  'r length
      ret 16
    cmpn2:
    mov al,[edx]   ' from L string
    cmp al,[edi]   ' from R string
    jnz cmpnxr     '
    inc edx        '
    inc edi        '
  jmp cmpndo       '
  cmpnxr:          ' flags hold result
  ret 16
  '
  'tie break on null ptr
  '
  cmpnnok:
  cmp edx,edi
  ret 16
                   '

 

'
'                                      ####
'         ###                        ###   ####
'       ##   ##                    ##          ####STRINGS
'     ##       ##                 ##
'   ##          ##               ##
'  ##            ##            ##
'  ##             ##         ##
'                   ##     ##
'                     #####


  '------------
  ltrims: '2312
  '============
  '
  push esi
  mov edi,0
  mov esi,[esp+8] 'pointer
  cmp esi,0
  jz xltrim1
  mov edi,[esi-4] 'length
  xltrim1:
  cmp edi,0
  jle xltrim2

  and edx,2
  jnz ltrimr2
  '
  ltrimr:
  dec edi
  jl ltrimx
  mov al,[esi]
  inc esi
  cmp al,32
  jle ltrimr
  jmp ltrimx

  ltrimr2:
  sub edi,2
  jl ltrimx2
  mov ax,[esi]
  add esi,2
  cmp ax,0x20
  jle ltrimr2
  ltrimx2:
  inc edi
  dec esi

  ltrimx:
  inc edi
  dec esi

  xltrim2:
  push edi
  push 0
  call SysAllocStringByteLen
  'call [ebx+160] 'AllocString
  push eax
  '
  push edi ' remaining length
  push esi ' start of str
  push eax ' new string dest
  call copyn
  '
  pop eax
  pop esi
  ret 4



  '------------
  rtrims: '2320
  '============
  '
  push esi
  mov edi,0
  mov esi,[esp+8]  ' pointer
  cmp esi,0        'check null ptr
  jz xrtrim1
  mov edi,[esi-4]  ' length
  xrtrim1:
  cmp edi,0
  jle xrtrim2
  add esi,edi   ' end of string
  and edx,2
  jnz rtrimr2

  rtrimr:
  dec edi
  jl rtrimx
  dec esi
  mov al,[esi]
  cmp al,32
  jle rtrimr
  jmp rtrimx
  '
  rtrimr2:
  sub edi,2
  jl rtrimx2
  sub esi,2
  mov ax,[esi]
  cmp ax,0x20
  jle rtrimr2
  rtrimx2:
  inc edi
  '
  rtrimx:
  mov esi,[esp+8]
  inc edi

  xrtrim2:
  push edi
  push 0
  call SysAllocStringByteLen
  'call [ebx+160] ' AllocString
  push eax
  '
  push edi ' remaining length
  push esi ' start of str
  push eax ' new string dest
  call copyn
  '
  pop eax
  pop esi
  ret 4



  '------------
  lcases: '2328
  '============
  '
  push esi
  mov esi,[esp+8]
  mov edi,0
  cmp esi,0 'null string test
  jz lwrx1
  mov edi,[esi-4]
  lwrx1:
  push edx
  push edi
  push 0
  call SysAllocStringByteLen
  pop edx
  mov ecx,edi
  mov edi,eax
  push eax
  and edx,0xff 'supporting wide code

  lwrr:
  sub ecx,edx
  jl lwrx
  mov al,[esi]
  cmp al,65
  jl lwrn
  cmp al,90
  jg lwrn
  add al,32
  lwrn:
  mov [edi],al
  add esi,edx
  add edi,edx
  jmp lwrr

  lwrx:
  pop eax
  pop esi
  ret 4



  '------------
  ucases: '2336
  '============
  '
  push esi
  mov esi,[esp+8]
  mov edi,0
  cmp esi,0 'null string test
  jz uprx1
  mov edi,[esi-4]
  uprx1:
  push edx
  push edi
  push 0
  call SysAllocStringByteLen
  pop edx
  mov ecx,edi
  mov edi,eax
  push eax
  and edx,0xff 'supporting wide code

  uprr:
  sub ecx,edx
  jl uprx
  mov al,[esi]
  cmp al,97
  jl uprn
  cmp al,122
  jg uprn
  sub al,32
  uprn:
  mov [edi],al
  add esi,edx
  add edi,edx
  jmp uprr

  uprx:
  pop eax
  pop esi
  ret 4



  '-----------
  lefts: '2344
  '===========
  '
  pop eax  'return address
  pop ecx  'string
  push 1   'insert offset
  push ecx 'string
  push eax 'return address
  jmp midsi


'2352 ?



  '----------
  mids: '2360
  '==========
  '
  midsi: 'entry point for bstrings
  '
  mov ecx,0          ' default source length is 0
  mov edi,[esp+4]    ' ptr
  cmp edi,0
  jz midok1
  mov ecx,[edi-4]    'get source length
  '
  midok1: 'the length of source
  '
  '------------------------------                   '
  astrin: 'entry point for asciiz
  '------------------------------

  'support for wide strings
  '
  push ecx      'length
  and  edx,&hff ' char width
  mov ecx,edx
  dec cl
  jz nadjwid
  mov eax,[esp+12]
  dec eax
  shl eax,cl
  inc eax
  mov [esp+12],eax
  shl dword ptr [esp+16],cl
  nadjwid:
  pop ecx
  '
  push esi           ' preserve esi
  '
  mov edx,[esp+12]   ' get offset
  '
  '-------------     '
  'NEG OFFSETS       '
  '-------------     '
  '
  cmp edx,0          '
  jnz midnoinc
  inc edx            'change offset 0 to 1
  midnoinc:

  jg midok2         'skip if offset not negative
  '
  inc edx
  add edx,ecx       'add length to negative offset to obtain offset
  jg midok2         '
  mov edx,1         'must be at least 1
  '
  midok2: 'assess whether any bytes are available    
  '         '
  cmp edi,0          'null or empty source string
  jz midnul          '
  cmp ecx,edx        'compare bytes available with offset
  jge midok3         'not past end end of source string
  '
  midnul: 'no bytes are available so a null string is to be returned
  '
  push 0             '
  push 0             '
  call SysAllocStringByteLen
  'call [ebx+160]    'AllocString
  jmp midx           'null string allocation done
  '
  midok3: 'at least one byte is available to return
  '
  mov eax,ecx        'length of source
  dec edx            'zero base adjust the offset
  sub eax,edx        'deduct from source to get bytes available
  cmp eax,[esp+16]   'bytes requested
  jle midok4
  mov eax,[esp+16] 'bytes requested iss less than bytes avail
  '
  midok4:
  '
  push eax           'bytelength for copyn
  add edi,edx        'src base+offset
  push edi           'source for copyn
  push eax           'bytelength for SysAlloc
  push 0             'null string for SysAlloc
  call SysAllocStringByteLen
  'call [ebx+160] 'AllocString
  push eax           'new string dest for copyn
  mov esi,eax        'retain new string in non-volatile reg
  call copyn         '
  mov eax,esi        ' new bstring to return
  '
  midx:                '
  '
  pop esi            'restore esi
  ret 12             '



  '----------
  ascs: '2368
  '==========
  '              '
  ascsi:
  mov ecx,[esp+4]  'pointer
  mov edx,[esp+8]  'req pos
  xor eax,eax
  cmp ecx,0
  jz ascx
  mov edi,[ecx-4]  'length
  cmp edi,0
  jle ascx

  ascsi1:            '
  cmp edx,0        '
  jnz asco1        '
  inc edx          'set to 1

  asco1:             '
  jge ascso2       'neg spec
  add edx,edi      '
  inc edx          'base adjust

  ascso2:            '
  cmp edx,1        'lower limit check
  jl ascx          'leave as null
  cmp edi,edx      'upper limit check
  jl ascx          'leave as null
  dec edx          'base adjust
  add ecx,edx      '
  mov al,[ecx]     '

  ascx:
  ret 8            '



  '----------
  lens: '2376
  '==========
  '              '
  mov eax,[esp+4]  '
  cmp eax,0        '
  jz nlens         '
  mov eax,[eax-4]  '
  mov cl,dl
  dec cl
  jz nlens
  shr eax,cl
  nlens:           '
  ret 4            '



  '----------
  chrs: '2384
  '==========
  '             '
  push 1           '
  push 0           '
  call SysAllocStringByteLen
  'call [ebx+160] 'AllocString
  mov dl,[esp+4]   '
  mov [eax],dl     '
  ret 4            '


  'mid for asciiz

  '----------
  midz: '2392
  '==========
  '
  midzi:
  mov edi,[esp+4] 'pass base in edi
  mov ecx,edi
  cmp dl,2
  jz rmidz2
  rmidz1:
    mov al,[ecx]
    inc ecx
    cmp al,0
  jnz rmidz1
  dec ecx          'exclude null term in count
  sub ecx,edi      'pass length in ecx
  jmp astrin

  rmidz2:
    mov ax,[ecx]
    add ecx,2
    cmp ax,0
  jnz rmidz2
  sub ecx,2        'exclude null term in count
  sub ecx,edi      'pass length in ecx
  jmp astrin




  '-----------
  leftz: '2400
  '===========
  '
  pop eax  'return address
  pop ecx  'string base
  push 1   'insert offset
  push ecx 'string basr
  push eax 'return address
  jmp midzi



  '2 PARAM MID

  '-----------
  mids2: '2416
  '===========
  '
  pop eax  'return address
  pop ecx  'string base
  pop edi  'string offset
  '
  cmp ecx,0
  jnz nnulm2el
    '
    push 0 'length req
    jmp nnulm2ei
    '
  nnulm2el:
    '
    push [ecx-4] 'length req
    '
  nnulm2ei:
  '
  push edi 'string offset
  push ecx 'string base
  push eax 'return address
  jmp midsi


  '-----------
  midz2: '2424
  '===========
  '
  pop eax          'return address
  pop ecx          'address base
  pop edi          'offset
  push &h7fffffff  'req max length
  push edi         'offset
  push ecx         'ptr
  push eax         'return address
  jmp midzi        '


  'SINGLE PARAM ASCII

  '-----------
  ascs1: '2432
  '===========
  '
  pop ecx            'return address
  pop eax            'string base
  push 1             'offset
  push eax           'string pointer
  push ecx           'return address
  jmp ascsi          '2 term asc





  'O2H RUNTIME BIND TO IMPORTED DLLS

  '------------
  'COMMAND BYTE
  '============
  '00 NULL TERMINATOR
  '01 NEW LIBRARY NAME
  '02 PROCADDRESS
  '03 END

  '---------------------
  bindls: 'at [ebx+2440]
  '=====================
  '
  'SAVE BASE
  '---------
  '
  push ebx 'GLOBAL BASE [ESP+4]
  '
  'STORE BINDING DATA
  '------------------
  '
  mov edi,eax
  mov [ebx+672],edi 'BINDING DATA
  '
  'PREPARE LIST FOR LIBRARY HANDLES (512)
  '--------------------------------------
  '
  'this list is used for unloading libraries with FREELIBRARY
  '
  mov eax,[ebx+680]
  add eax,[eax]         '1ST DWORD HOLDS OFFSET FOR NEXT DATA
  add eax,4
  mov dword ptr [eax],1 'SET MARKER
  add eax,4
  push eax  'HOLD LIBRARY LIST BASE ON STACK [ESP]
  '
  '
  'GET COMMAND
  '-----------
  '
  mov al,[edi]
  '
  '--------------------
  rbindlsa: 'LOOP POINT
  '====================
  '
  'CHECK FOR TERMINATORS
  '---------------------
  '
  cmp al,0
  jz xbindls 'NULL TERMINATION OF LIST
  cmp al,3
  jz xbindls 'FORMAL END OF LIST
  '
  'CHECK FOR LOAD LIBRARY
  '----------------------
  '
  cmp al,1
  jz bindlslok
  mov eax,100 'REPORT INVALID COMMAND
  jmp xbindls
  bindlslok:
  '
  call bindlsw
  push ecx
  call LoadLibrary ecx
  'call [ebx+24] 'library
  pop ecx
  '
  'CHECK VALID LIBRARY HANDLE
  '--------------------------
  '
  cmp eax,0
  jnz nbindlsl
  mov eax,101 'REPORT INVALID LIBRARY NAME
  jmp xbindls
  nbindlsl:
  '
  'HOLD/SAVE LIBRARY HANDLE
  '------------------------
  '
  mov esi,eax 'LIBRARY HANDLE
  pop eax
  mov [eax],esi
  add eax,4 'NEXT LIBRARY HANDLE STORAGE ADDRESS
  push eax
  mov al,[edi]
  '
  'CHECK FOR GETPROCADDRESS
  '------------------------
  '
  cmp al,2
  jnz rbindlsa 'NEXT PROC ADDRESS OR NEXT LIBRARY
  '
  '
  'NEXT PROC ENTRY
  '---------------
  '
  '-----------------------------------
  rbindlsp: 'LOOP POINT FOR PROCEDURES
  '===================================
  '
  'HOLD TABLE OFFSET
  '-----------------
  '
  inc edi
  mov edx,[edi] 'VARIABLE ADDRESS (will be an offset from esi)
  push edx
  add edi,3
  '
  'GET PROC NAME
  '-------------
  '
  call bindlsw
  push ecx   ' PROCNAME PTR
  'push ecx   ' PROCNAME PTR
  'push esi   ' LIBRARY
  'call getprocaddress
  'call [ebx+40] 'getprocaddress
  GetProcAddress esi,ecx
  pop ecx    ' RESTORE PROCNAME PTR
  pop edx    ' RESTORE TABLE OFFSET
  '
  'CHECK VALID PROC ADRESS
  '-----------------------
  '
  cmp eax,0
  jnz bindlspok
  mov eax,102 ' REPORT PROCADDRESS ERROR
  jmp xbindls
  '
  '---------
  bindlspok:
  '=========
  '
  'STORE PROCADDRESS IN TABLE
  '--------------------------
  '
  add edx,[esp+4] ' ADD STATIC VARIABLE BASE [EBX]
  mov [edx],eax   ' STORE ADDRESS
  mov al,[edi]
  '
  'ANOTHER PROC?
  '-------------
  '
  cmp al,2
  jz rbindlsp 'ANOTHER PROCADRESS ENTRY
  '
  'NEXT LIB OR EXIT
  '----------------
  '
  jmp rbindlsa 'OTHERWISE NEXT LIB OR FINISH
  '
  'EXIT POINT
  '----------
  '
  '-------
  xbindls:
  '=======
  '
  'MUST RETAIN EAX/AL CONTENTS
  '
  pop esi 'NEXT LIB HANDLE STORAGE ADDRESS
  mov edx,[ebx+680]
  sub esi,edx
  sub esi,4
  mov [edx],esi 'STORE NUMBER OF LIBRARY ADDRESSES *4
  pop ebx
  ret     'RETURN
  '
  '
  'READ FOLLOWING NAME
  '-------------------
  '
  '-------------------------------------
  bindlsw: 'ADVANCE BEYOND WORD BOUNDARY
  '=====================================
  '
  inc edi
  mov ecx,edi
  '
  '---------------------
  rbindlsw: ' LOOP POINT
  '---------------------
  '
  mov al,[edi]
  inc edi
  cmp al,0
  jnz rbindlsw
  ret




  'FREE DLLS USING LIST

  '---------------------
  freels: 'at [ebx+2448]
  '====================
  '
  push eax
  '
  'LOCATE END POSITION
  '
  mov edi,[ebx+680]
  mov eax,[edi]
  cmp eax,0      'CHECK IF EMPTY
  jz xxfreels
  add edi,eax
  add edi,4
  '
  '
  '--------------------------
  'REPEAT TILL MARKER OR NULL
  '--------------------------
  '
  'FREE LIBS WORKING BACKWARDS TILL BOUNDARY MARKER
  '
  (
    sub edi,4
    'cmp dword ptr [edi],0
    'jz xfreels
    cmp dword ptr [edi],1 'EXIT AT MARKER
    jz xfreels
    push [edi]
    'FreeLibrary
    call [ebx+32] 'FreeLibrary
    repeat
  )
  '
  xfreels:
  '
  mov eax,[ebx+680]
  sub edi,eax
  sub edi,4
  mov [eax],edi
  xxfreels:
  pop eax
  ret




  'COMMAND FORMAT:
  '
  'MID()=
  '  
  '-------------
  midbufz: '2352
  '=============
  dec dword ptr [esp+8] 'offset base 0
  cmp dl,2
  jz midbufzw
  '
  mov ecx,[esp+4]
  cmp ecx,0
  jz xmidbuf
  rmidbuflenz:
  mov al,[ecx]
  inc ecx
  cmp al,0
  jnz rmidbuflenz
  dec ecx
  mov edx,ecx
  mov ecx,[esp+4]
  sub edx,ecx
  jmp midbuflres

  midbufzw:
  '========
  shl dword ptr [esp+8] 'wide character offset
  mov ecx,[esp+4]
  cmp ecx,0
  jz xmidbuf
  rmidbuflenz2:
  mov ax,[ecx]
  add ecx,1
  cmp ax,0
  jnz rmidbuflenz2
  sub ecx,2
  mov edx,ecx
  mov ecx,[esp+4]
  sub edx,ecx
  jmp midbuflres
 

  '------------
  midbuf: '2456
  '============
  dec dword ptr [esp+8] 'offset base 0
  cmp dl,2
  jnz nmidbufwid
  shl dword ptr [esp+8] 'wide character offset
  '
  nmidbufwid:
  '
  mov ecx,[esp+4]   'byref buffer ptr
  'cmp ecx,0
  'jz xmidbuf        'null buffer
  'mov ecx,[ecx]     'deref
  cmp ecx,0
  jz xmidbuf
  mov edx,[ecx-4]   'length of buffer
  '
  midbuflres:
  '==========
  '
  sub edx,[esp+8]   'offset
  mov edi,[esp+12]  'source
  cmp edi,0
  jz  xmidbuf       'nul source
  mov eax,[edi-4]
  cmp edx,eax       'check length of source
  jle nmidbuf1      '
    mov edx,eax     'least qty to transfer
  nmidbuf1:
  cmp edx,0         'check if any to transfer
  jle xmidbuf
  add ecx,[esp+8]   ' add offset to target
  rmidbuf:
    mov al,[edi]
    inc edi
    mov [ecx],al
    inc ecx
    dec edx         'check n
    jg rmidbuf
  xmidbuf:
  '
  mov eax,[esp+4]
  mov ecx,[esp+12]
  ret 12





  'STRING(N,CHAR)


  '-------------
  stringa: '2464
  '=============
  '
  stringi:
  mov eax,[esp+4]  'length
  cmp dl,2
  jz stringwid
  push eax         'length
  push 0           'no copy
  call SysAllocStringByteLen
  'call [ebx+160]  'AllocString
  mov ecx,[esp+4]  'length
  mov edx,[esp+8]  'byte fill
  push eax         'addr
    push edx       'byte fill
    push ecx       'length
    push eax       'ptr
    call init1     'fill
  pop eax ' BSTR addr
  ret 8
  '
  stringwid:
  '
  shl eax,1        'double for wide chars
  push eax         'length
  push 0           'no copy
  call SysAllocStringByteLen
  'call [ebx+160] ' AllocString
  mov ecx,[esp+4]  'length chars
  cmp ecx,0
  jle xstringwid
  mov edx,[esp+8]  'byte fill
  push eax 'save address
  '
  rstringwid:
  '
  mov [eax],dx
  add eax,2
  dec ecx
  jg rstringwid  
  pop eax 'restore address
  xstringwid:
  ret 8

  '-------
  stringj:
  '=======
  '
  mov eax,[esp+8]
  cmp eax,0
  jz nstringz
    mov eax,[eax] 'deref for 1st char
    mov [esp+8],eax
  nstringz:
  jmp stringi


  '-------------
  stringz: '2472
  '=============
  '
  jmp stringj
  '

  '-------------
  strings: '2480
  '=============
  '
  jmp stringj

  '------------
  spaces: '2488
  '=============
  '
  pop eax
  pop ecx
  push 32  '+8
  push ecx '+4
  push eax
  jmp stringi

  '------------
  prints: '2496
  '============
  '
  cmp dl,2
  jz printsw 'WIDE STRINGS
  mov eax,[esp+4]
  push eax
  call [ebx+2048]
  ret 4
  '
  printsw:
  '
  mov eax,[esp+4]
  push &h00000048
  push &h0032004f      ' wide char title: O2
  mov ecx,esp      '
  push 0           '
  push ecx         ' title string
  push eax         ' message string
  push 0           '
  call MessageBoxW
  add esp,8        ' unstack title string
  ret 4



  '-------------
  instrs2: '2504
  '=============
  '
  pop eax
  push 1
  push eax
  jmp [ebx+320]


  'GETFILE "T.TXT",F

  '--------------
  getfile2: '2512
  '==============
  '
  mov edi,[esp+8]
  push [edi]
  call freemem 'dump existing string
  mov eax,[esp+4]
  push eax
  call getfiles
  mov [edi],eax
  ret 8  



  '----------
  strs: '2520
  '==========
  '
  'VALUE IN FPU
  '
  push -1
  call float_to_ascii
  ret




  '-----------
  unics: '2528
  '===========
  '
  unicsi:
  '
  mov ecx,[esp+4]  'pointer
  mov edx,[esp+8]  'req char pos
  shl edx,1        'convert to bytes
  xor eax,eax
  cmp ecx,0
  jz unicx
  mov edi,[ecx-4]  'byte length
  cmp edi,0
  jle unicx
  cmp edx,0        '
  jnz unicso1      '
  mov edx,2        'set to 1
  '
  unicso1:             '
  '
  jge unicso2       'neg spec
  add edx,2        'base adjust
  add edx,edi      '
  '
  unicso2:           '
  '
  sub edx,2
  jl unicx         'below so leave as null
  cmp edi,edx      'upper limit check
  jle unicx        'above so leave as null
  add ecx,edx      '
  mov ax,[ecx]     '
  '
  unicx:
  '
  ret 8            '



  '------------
  unics1: '2536
  '============
  '
  pop edx
  pop eax
  push 1
  push eax
  push edx
  jmp unicsi


  '-----------
  wchrs: '2544
  '===========
  '             '
  push 2           '
  push 0           '
  call SysAllocStringByteLen
  'call [ebx+160] 'AllocString
  mov dx,[esp+4]   '
  mov [eax],dx     '
  ret 4            '


  '-------------
  numform: '2552
  '============= 
  '
  lea ecx,[num]
  mov eax,[esp+4]
  mov [ecx],eax
  mov eax,[esp+8]
  mov [ecx+4],eax
  mov eax,[esp+12]
  mov [ecx+8],eax
  mov eax,[esp+16]
  mov [ecx+12],eax
  mov eax,[esp+20]
  mov [ecx+16],eax
  mov eax,[esp+24]
  mov [ecx+20],eax
  ret 24


  '--------------
  numformd: '2560
  '==============
  '
  lea ecx,[num]
  mov eax,16
  mov [ecx],eax
  mov eax,1
  mov [ecx+4],eax
  mov eax,0
  mov [ecx+8],eax
  mov [ecx+12],eax
  mov [ecx+16],eax
  mov [ecx+20],eax
  ret


  '================================================
  'STUB FUNCTIONS (UNIMPLEMENTED PROCEDURES IN RTL)
  '================================================


  '----------------------------------------------
  function getvarptr(s as string) as sys external
  '==============================================
  static sys a[4]
  return & a
  end function

  '----------------------------------------------------
  function compile(s as string) as sys external 'string
  '====================================================
  static sys a
  a=0xc3 'ret instruction
  return & a
  end function


  '===================
  'End Run Time Procs:
  '===================


  '------------------
  DisplayCommandLine:
  '==================
  push 0
  "COMMAND LINE"
  push eax
  call [ebx+448]
  push eax
  push 0
  call [ebx+472]
  ret


  '======
  endlib:
  '======

  '
  'GET ABSOLUTE ADDRESSES
  '======================
  '
  call fwd here
  .here
  pop eax
  sub eax,here
  '
  'mov ebx,bssdata
  'add ebx,eax
  '
  def adrf
    mov ecx,%1 : add ecx,eax : mov [ebx+%2],ecx
  end def
  '
  '
  adrf mboxs      2048 'display string in message box
  adrf noof       2056 'was newlist. create a generic list (header of 16)
  adrf addlist    2064 'add to list
  adrf delist     2072 'delete
  adrf delchain   2080 'delete chain of lists
  adrf strinstl   2088 'check string instance local
  adrf strinstg   2096 'check string instance global
  adrf deltmp     2104 
  adrf delloc     2112 
  adrf noof       2120
  adrf compnnul   2128 
  adrf noof       2136 '
  adrf sysdelbufs 2144 'del system buffs
  adrf catbufprp  2152 'clear string lists
  adrf badcatl    2160 'add byref bstr to cat list [640]
  adrf sadcatl    2168 'add byval bstr to list (bstr params passed byva
  adrf zadcatl    2176 'add z string to cat list   [640]
  adrf joins      2184 'join strings: copy into one
  adrf comps      2192 'compare bstring
  adrf compz      2200 'compare zstrings
  adrf assglo     2208 'assign to global bstr list [ebp-4]
  adrf assloc     2216 'assign to local bstr list [ebp-4]
  adrf asstmp     2224 'assign to temp bstr list [ebp-8]
  adrf noof       2232 '
  adrf asstrl     2240 'assign bstring [local list 656]
  adrf asstrg     2248 'assign bstring [global list 664]
  adrf trbstr     2256 'transfer bstr
  adrf noof       2264 '
  adrf noof       2272 '
  adrf compis     2280 'compare with bstr byref with byval
  adrf compris    2288 'compare with bstr byref with byval
  adrf deref0     2296 'dereference if possible or return 0
  adrf compn      2304 'compare n bytes
  adrf ltrims     2312 'ltrim
  adrf rtrims     2320 'rtrim
  adrf lcases     2328 'lcase
  adrf ucases     2336 'ucase
  adrf lefts      2344 'left
  adrf midbufz    2352 '
  adrf mids       2360 'mid
  adrf ascs       2368 'asc
  adrf lens       2376 'len
  adrf chrs       2384 'chr
  adrf midz       2392 'mid for asciiz string literals
  adrf leftz      2400 'left for asciiz
  adrf lenz       2408 'len for zstring and zstring2
  adrf mids2      2416 '2 param mid
  adrf midz2      2424 '2 param mid for asciiz
  adrf ascs1      2432 '1 param asc
  adrf bindls     2440 'bind imported ibs and procs
  adrf freels     2448 'free dlls
  adrf midbuf     2456 'mid(s,i)=t
  adrf stringa    2464 'string byte
  adrf stringz    2472 'string string
  adrf strings    2480 'string zstring
  adrf spaces     2488 'space zstring
  adrf prints     2496 'print string
  adrf instrs2    2504 '2 parm instr(s,u)
  adrf getfile2   2512 'getfile "t.txt",f
  adrf strs       2520 'str(n)
  adrf unics      2528 'unicode (wide string)
  adrf unics1     2536 'unicode (wide string)
  adrf wchrs      2544 'wide chr
  adrf numform    2552 'numberformat
  adrf numformd   2560 'numberformat default
  adrf getmem                08 'new nulled memory block
  adrf freemem               16 'free memory block
 'adrf procaddrs#sys#sys#sys 48 'bind proc addresses
  adrf copys0                56 'copy nul terminated string
  adrf copys00               64 'copy null terminated wide string (2 byte characters)
  adrf copysn                72 'copy string of n bytes
  adrf getvarptr#string      80 'O2 GET HOST VAR ADDRESS
  '
  '
  [ebx+128]=@errors
  [ebx+192]=@ascii_to_float
  [ebx+200]=@float_to_ascii
  [ebx+208]=@hexs
  [ebx+216]=@hexsl
  [ebx+320]=@instrsh
  [ebx+328]=@noof
  [ebx+336]=@getfiles
  [ebx+344]=@putfiles
  [ebx+352]=@guidvals
  [ebx+360]=@guidtxts
  [ebx+368]=@compile
  '
  jmp fwd endp
  '
  '-------------------------------
  _newbuf: 'CREATE A SYSTEM BUFFER
  '===============================
  '
  push esi : push 0  : call SysAllocStringByteLen
  mov ecx,esi
  mov edx,eax
  (
    mov [edx],0
    add edx,4
    sub ecx,4
    jg repeat
  )
  mov [edi],eax : add edi,8 'ready for next buffer
  ret
  endp:
  '
  push esi
  lea edi,[ebx+664] 'CREATE GLOBAL STRING BUFFER 
  mov esi,512
  call _newbuf
  lea edi,[ebx+680]
  mov esi,4096
  call _newbuf 'SET UP BUFFER FOR  LIB HANDLES
  pop esi


  'VACANT BUFFER POINTERS
  '======================
  '
  '[ebx+648]
  '[ebx+656]
  '[ebx+640]

  '---------------------
  'NUMBER FORMAT CONTROL
  '=====================
  '
  num.dp =16 ' DECIMAL PLACES
  num.trz= 1 ' STRIP TRAILING ZEROS
  num.sn = 0 ' SCIENTIFIC NOTATION BY DEFAULT
  num.sdp= 0 ' INHIBIT ZERO BEFORE DECIMAL POINT
  '
  finit 'initialise FPU


  '----------------------------------------------------
  'INSERTION POINT LIBRARY BINDINGS AND STATIC ENTITIES
  '====================================================
  '
  ._statics_



  '---------------------------------
  'NON-DEFAULT TERMINATION PROCEDURE
  '=================================
  '
  'def terminate
  'call [ebx+2448] : call [ebx+2144]
  'end def




  '--------------------------------
  'EPILOG (APPENDED TO END OF CODE)
  '================================
  '
  def _epilog

  ._end_

  #ifndef dll
    mov edi,eax 'hld exit value in edi
    push 0 'place for exit code
    mov eax,esp 
    push eax
    call getModuleHandle
    push eax
    call GetExitCodeProcess
    mov eax,edi 'return exit value in eax
    call ExitProcess

    ._error_

    push ecx : call [ebx+2048]
    jmp _end_

  #else
    lea edi,[ebp-8]   'temp list
    call delbuf
    mov esp,ebp : pop ebp : add esp,4 : pop edi : pop esi : pop ebx
    ret 12

  ._error_

    push ecx : call [ebx+2048]
    lea edi,[ebp-8]   'temp list
    call delbuf
    mov esp,ebp : pop ebp : add esp,4 : pop edi : pop esi : pop ebx
    mov eax,0
    ret 12

    #endif



  end def
