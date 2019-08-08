/*
  RTL32.inc

  OxygenBasic RunTime Library
  ===========================

  For creating standalon executables and dynamic link libraries which
  will run independently of Oxygen.dll

  NB Functions relating to dynamic compiling are not implemented in this library:
  "compile" and "uncompile"

  Version Alpha026

  21:48 09/01/2011
  Charles Pegge
  cevpegge (at) oxygenbasic.org


*/



  /*
  ==========================

  EXAMPLE:
  ========
                        'ENTER THESE LINES AT THE START OF YOUR PROGRAM

  $ dll                'THIS PRODUCES A DLL INSTEAD OF AN EXE FILE
  $ FileName t         'SPECIFIES THE COMPILED FILENAME "t.exe" or "t.dll"
  include "RTL32.inc"  'INCLUDES THIS FILE

  ==========================
  */



  #ifdef dll
    def FileType dll
  #else
    def FileType exe
  #endif

  def CompileSpec
    #file "%1.%2" independent
  end def

  CompileSpec FileName FileType


  '=================
  #ifdef dll
  '=================
  '
  'DLL EQUATES
  '
  % DLL_PROCESS_ATTACH   1
  % DLL_THREAD_ATTACH    2
  % DLL_THREAD_DETACH    3
  % DLL_PROCESS_DETACH   0
  % DLL_PROCESS_VERIFIER 4
  '
  mov edx,[esp+8] 'second param of DLLmain
  '
  select edx
    case DLL_PROCESS_ATTACH : jmp fwd dll_start
    case DLL_PROCESS_DETACH : jmp fwd dll_finish
    case DLL_THREAD_ATTACH  : eax=1
    case DLL_THREAD_DETACH  : eax=0
  end select
  ret 12

  '---------
  dll_start:
  '=========
  '
  call prolog
  mov eax,1
  ret 12

  '----------
  dll_finish:
  '==========
  '
  'push ebx : push esi : push edi
  '
  declare sub finish()
  finish()
  '
  mov eax,0
  'pop edi : pop esi : pop ebx
  ret 12


  '==========
  #endif 'DLL
  '==========



  '------
  Prolog:
  '======

  push ebx : push esi : push edi : push ebp
  mov ebp,esp
  sub esp,256

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
 'def LoadLibrary           [ebx+024]
 'def GetProcAddress        [ebx+040]
 'def FreeLibrary           [ebx+032]
  def SysAllocStringByteLen [ebx+160]
  def SysFreeString         [ebx+168]
  def GetModuleHandle       [ebx+440]
  def GetGetCommandLine     [ebx+448]
  def GetExitCodeProcess    [ebx+456]
  def ExitProcess           [ebx+464]
  def CreateFile            [ebx+480]
  def ReadFile              [ebx+488]
  def CloseHandle           [ebx+496]
  def MessageBox            [ebx+472]
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


  '---------------------------
  'ADDITIONAL OS CALLS GO HERE
  '===========================
  '
  sub esp,16
  '
  indexers ebx offset 4096 ascending
  '
  var long a at [ebp-4]
  var long WriteFile,GetFileSize,SetFilePointer
  '
  a=LoadLibrary "oleaut32.dll"
  '
  SysAllocStringByteLen=GetProcAddress a,"SysAllocStringByteLen"
  SysFreeString=GetProcAddress a,"SysFreeString"
  '
  a=LoadLibrary "kernel32.dll"
  '
  WriteFile=GetProcAddress a,"WriteFile"
  GetFileSize=GetProcAddress a,"GetFileSize"
  SetFilePointer=GetProcAddress a,"SetFilePointer"
  '
  add esp,16
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
  typedef byte ubyte
  '
  type numformat
    dp  as sys  ' DECIMAL PLACES
    trz as sys  ' STRIP TRAILING ZEROS
    sn  as sys  ' SCIENTIFIC NOTATION BY DEFAULT
    sdp as sys  ' INHIBIT ZERO BEFORE DECIMAL POINT
  end type

  'const
  string cr=chr(13)+chr(10)

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


  '---------------------------------------------------------
  function float_to_ascii() as string external 'at [ebx+200]
  '=========================================================
  '
  static as zstring s(24),t(24), u(16),bcd(12) 'BUFFERS
  static as sys pt,pa
  local as sys esize,tempdw,dp,sn,snv,b,nzero,oldcw,truncw

  '
  pt= & t
  pa= & u
  '
  '
  fstpt [u] 'pop store ext number from fpu
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
        '------

        jmp fwd fadonez 'NEGATIVE ZERO
      )
      '
      '*pt="0"
      '
      mov eax,[pt]
      mov byte [eax],0x30
      '------

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
        '
        jmp fwd fadonez 'SIGNALLING NAN
      )
      '
      '*pt="#qNAN"
      '
      mov eax,[pt]
      mov [eax],0x414E7123
      mov [eax+4],0x4E
      '
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
      '
      jmp fwd fadonez 'NEGATIVE INFINITY
    )
    '
    '*pt="#INF"
    '
    mov eax,[pt]
    mov byte [eax],0x464E4923
    mov [eax+4],0x00
    '
    jmp fwd fadonez 'POSITIVE INFINITY
  )


  fldt [u]

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
  mov eax,[num.dp]
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
  lea edx,[t]
  '
  'NEGATIVE SIGN NEEDED?
  '
  (
    cmp al,48
    jz exit
    mov byte ptr [edx],45
    inc edx
  )

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
    lea ecx,[t] 'BASE ADDRESS OF NUMBER STRING

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
  lea ecx,[t]
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
  'ASSIGN RESULT TO BSTRING
  '
  function=t
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

  mov ecx,[p]
  '
  'SKIP LEADING WHITE SPACE
  '
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
  '
  mov [stt],ecx 'START OF NUMBER
  '
  '
  'filter word types
  '=================
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

  'NAKED HEXADECIMAL
  'cmp al,&h41 'exclude below A
  'jb numnok
  'cmp al,&h48 'include below H
  'jb numhok
  'cmp al,&h61 'exclude below a
  'jb numnok
  'cmp al,&h68 'include below h
  'jb numhok
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
  fldz
  '
  inc ecx
  mov al,[ecx]
  cmp al,32
  jbe ParseHExit
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
  cmp al,&h48 'h
  jnz tryoctal
  '
  '
  'HEXADECIMAL
  '-----------
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
  xor edx,edx 'zero the accum
  (
    inc ecx
    mov al,[ecx]
    cmp al,48 '0
    jb exit
    cmp al,55 '7
    ja exit
    sub al,48 'ascii to hex number
    shl edx,3 'shift octo
    add dl,al
    '
    'itr overflow
    repeat    
  )
  noctconv: 'done conversion
  mov eax,edx
  jmp cputofpu
  '
  '
  '
  '
  trybinary: 'BINARY BITS
  '----------------------
  '
  cmp al,&h42 'b
  jnz ParseHExit
  '
  xor edx,edx 'zero the accum
  (
    inc ecx
    mov al,[ecx]
    cmp al,48 '0
    jb exit
    cmp al,49 '1
    ja exit
    sub al,48 'ascii to hex number
    shl edx 'shift bit
    add dl,al
    '
    'itr overflow
    '    
    repeat
  )
  'done conversion
  mov eax,edx
  jmp cputofpu
  '
  '
  'TREAT AS UNSIGNED INTEGER
  '
  cputofpu:
  '
  push 0
  push eax
  fstp st(0) ' dump default 0 
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
  sub esp,16
  mov edx,esp
  '
  'DEFAULT ZERO
  '
  mov dword ptr [edx],0
  mov dword ptr [edx+4],0
  mov word ptr [edx+8],0
  '
  inc ecx
  mov eax,[ecx]
  add ecx,4
  or eax,&h20202020 'QUICK LOWERCASE
  '
  (
    cmp eax,&h666e692d '#-INF
    jnz exit
    mov word ptr [edx+8],&hffff
    jmp xitsn
  )
  '
  (
    cmp eax,&h6e616e71 '#QNAN
    jnz exit
    mov dword ptr [edx+4],&h40000000
    mov word ptr [edx+8],&h7fff
    jmp xitsn
  )
  '
  (
    cmp eax,&h6e616e73 '#SNAN
    jnz exit
    mov dword ptr [edx+4],&h20000000
    mov word ptr [edx+8],&h7fff
    jmp xitsn
  )
  '
  and eax,&hffffff 'IGNORE 4TH CHAR
  '
  (  
    cmp eax,&h666e69 '#INF
    jnz exit
    mov word ptr [edx+8],&h7fff
    dec ecx
    jmp xitsn
  )
  '
  mov dword ptr [edx+4],&h40000000 'DEFAULT #QNAN
  mov word ptr [edx+8],&h7fff
  
  xitsn:
  '
  fldt [edx]
  add esp,16
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
    cmp al,32
    jle ParseExit
    '
    'TEST FOR E
    '
    ( 'raf3:
      cmp al,&h65
      jz exit
      cmp al,&h45
      jz exit
      jmp nexne
    )
    '
    'E ENCOUNTERED
    '
    (
      mov eax,ecx
      inc eax
      mov dword ptr [enf],eax
      fldz
      mov al,[sgf]
      mov [sgg],al
      mov dword ptr [sgf],0
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
      cmp byte ptr [sgf],0
      jnz NumErr 'NEG SIGN ALREADY ENCOUNTERED
      mov byte ptr [sgf],1 'SET SIGN FLAG
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
      cmp dword ptr [enf],0
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
      cmp byte ptr [enf],0
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
    cmp byte ptr [sgf],0
    jz exit
    fchs
  )
  '
  'DECIMAL PLACES BUT NO E NUMBER
  '
  (
    cmp dword ptr [enf],0
    jnz exit
    mov dword ptr [enf],1 'SET TO SCALE
    fldz
  )
  '
  'SCALE VALUE PRESENT?
  '
  (
    cmp dword ptr [enf],0
    jz exit
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
    'CHECK FOR NEG SIGN
    '
    (
      cmp byte ptr [sgg],0
      jz exit
      fchs
    )
  )
  '
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


  '---------------------------------------------------------------
  function getmem(byval a as sys) as sys external 'bstr at [ebx+8]
  '===============================================================
   push [a]
    push 0
    'call SysAllocStringByteLen
    call [ebx+160]
    mov [function],eax
    push 0
    push [a]
    push [function]
    mov eax,[a]
    and al,3
    jnz nini4
      pop edx
      pop ecx
      pop eax
      shr ecx,2
      cmp ecx,0
      jz xini
      rini:
        mov [edx],eax
        add edx,4
        dec ecx
        jg rini 
      jmp xini
    nini4:
      call init1#sys#sys#sys
    xini:
    'init1 p,a,0 ' BYTE NULLS
  end function



  '--------------------------------------
  sub FreeMem(byval a as sys) 'at [ebx+16]
  '======================================
    mov eax,[a]
    'cmp eax,0
    'jz nfreestr
      push eax
      call SysFreeString
      'call [ebx+168]
    'nfreestr:
  end sub


  '-------------------------------------------------------------------
  sub binderr(byval z as string, byval e as sys) external 'ebx restore
  '===================================================================
  '
  wdg=left(z,e)
  '
  'ADD TO RUNTIME ERRORS
  '
  ers+="Unable to bind "+wdg+cr
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
      call binderr#string#sys 'ebx
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
  'if erc then qq ers,1 'then terminate app?
  end sub


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


  '--------------------------------------------
  function hexs() as sys external 'at [ebx+208]
  '============================================
  sub esp,32 'workspace
  mov esi,esp
  fistp dword ptr [esi]
  mov edx,[esi]
  add esi,28  'offset for working backwoards
  mov edi,esi 'hold end position
  inc edi
  mov byte ptr [edi],32 'endstop space
  mov ecx,8   'down count
  rhextoc:
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
  jg rhextoc
  rtrimzer:  'trim leading zeros
  inc esi
  mov al,[esi]
  cmp al,48 'is it a leading zero?
  jz rtrimzer
  cmp esi,edi
  jl nsinglez 'leave at least 1 digit
  dec esi
  nsinglez:
  sub edi,esi 'calc length
  push edi 'length
  push esi 'pointer
  call SysAllocStringByteLen
  mov [function],eax 'return it
  add esp,32
  end function

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



  '-----------------------------------------------------------------------------------------------------------------
  function replaces(byval s0 as string, byval f0 as string, byval r0 as string) as sys external 'string at [ebx+328]
  '=================================================================================================================
  '
  dim as sys a,b,lw,lr,ls,lp
  dim as sys p=s0
  '
  'uses customised string concat
  '
    mov eax,[s0]
    cmp eax,0
    jz norpl 'void string
    mov eax,[eax-4]
    cmp eax,0
    jz norpl 'empty string
    mov [ls],eax
    '-----------
    mov eax,[f0]
    cmp eax,0
    jz norpl 'void keyword
    mov eax,[eax-4]
    cmp eax,0
    jz norpl 'empty keyword (protection)
    mov [lw],eax
    '-----------
    mov eax,[r0]
    cmp eax,0
    jz nunr0 'void replacement
    mov eax,[eax-4]
    mov [lr],eax
    nunr0:
    '
    'make copy of original string
    '----------------------------
    '
    push [ls]
    push 0
    call SysallocStringByteLen 'new uninitialised string
    mov [p],eax
    push [ls]
    push [s0]
    push eax
    call copysn
    mov eax,[p]
    mov [s0],eax
    '
  '
  a=1
  do
    a=instrsh(a,s0,f0)
    if a=0 then
      exit do
    else
      'ls=ls+lr-lw to calc length of new string
      mov eax,[ls]
      sub eax,[lw]
      add eax,[lr]
      mov [lp],eax 'save length of new string
      cmp eax,[ls]
      jnz newrpl   'new string is required
      mov eax,[s0] 'new string is not required
      jmp nnewrpl
      '------
      newrpl:
      '------
      push eax
      push 0
      call SysallocStringByteLen 'new uninitialised string
      '---------
      nnewrpl:
      '---------
      mov [p],eax 'new or existing string
      mov eax,[a] 'left length
      dec eax
      push eax
      push [s0]
      push [p]
      call copysn 'append left of s0
      '---------
      mov eax,[lr]
      cmp eax,0
      jz nappsr0 'empty replacement
      push eax
      push [r0]
      mov eax,[p]
      add eax,[a]
      dec eax
      push eax
      call copysn 'append r0
      '---------
      nappsr0:
      '---------
      mov eax,[ls]
      sub eax,[a]
      inc eax
      sub eax,[lw]
      push eax 'length of remaining mid s0
      mov eax,[s0]
      add eax,[a]
      add eax,[lw]
      dec eax
      push eax 'mid s0 position
      mov eax,[p]
      add eax,[a]
      dec eax
      add eax,[lr]
      push eax
      call copysn 'append mid s
      '---------
      mov eax,[p]
      cmp eax,[s0]
      jz nfrepl 'original string was used
      push [s0]
      call SysFreeString 'free Original s0
      mov eax,[p]
      mov [s0],eax 'new s0
      mov eax,[lp]
      mov [ls],eax 'new s0 length
      '------
      nfrepl:
      '------
      mov eax,[lr]
      add [a],eax 'next position to search from
      '----------
    end if
  end do
  '
  norpl:
  '
  function=p
  '
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




  mboxa: 'at [ebx+2048]
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


  addlist: 'at [ebx+2064] ' ( eax strptr edi list pointer ) retains string pointer in eax : return ptr edi for dyn string
  '=====================
  '
  addlisti:        '
  push ecx         'save reg
  push edi         'address of list ptr
  mov edi,[edi]    'address of list 'lea edi,[ebx+...]
  mov ecx,[edi+4]  '
  add ecx,16       '
  cmp ecx,4096     'check against list length 4096
  jl addsok        'skip if within list
    '
    'CREATE NEW LIST AND ADD TO CHAIN OF LISTS
    '
    push eax       'save BSTR
    '
    push 4096      'list block size
    call getmem#sys 'space filled with nulls
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
  pop ecx          'restore reg
  ret              '



  'DELETE STRINGS IN LIST
  '======================

  delist: 'at [ebx+2072]      ' (ecx index_limit edi list pointer)
  '====================
  '
  delisti:
  '---------
  '
  push esi
  '
  delisti1:
  '
  mov esi,edi      'save list base address
  mov edx,[edi+4]  'ubound
  add edi,edx      'start at end of list
  add edi,16       'offset
  '
  rdofreem:        '
    sub edi,4      '
    sub edx,4      'in reverse order
    jl xdofreem    'done or empty 
    mov eax,[edi]  'get bstring
    cmp eax,1      'check for stop marker
    jz xdofreem1   'to return 1
    push edx       'save downcount
    push eax       '
    call freemem#sys 'free the string
    pop edx        'restore downcount
  jmp rdofreem     '
  '
  xdofreem: 'list completed
  '--------
  '
  mov edi,esi      'restore base
  mov edx,0        'zero records
  mov eax,[edi]    'check for back link
  cmp eax,0        '
  jz xdofreem1     'no more lists
  push edi         'as param for freemem
  mov edi,eax      'back link
  call freemem#sys 'free original list (already on stack)
  jmp delisti1     'go for next list
  '
  xdofreem1:
  '---------
  '
  mov edi,esi
  mov [edi+4],edx  'record remainin records
  pop esi          'restore esi
  ret              '



  'DELETE CHAINED LISTS OF STRINGS BACKWARDS
  '=========================================
                   
  delchain: 'at [ebx+2080]
  '======================
  '
  cmp dword ptr [edi],0 'no list available
  jz ndelchain     '
  '
  delchaini:       '
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

  strinstl: 'at [ebx+2088]
  '======================
  '
  cmp dword ptr [ecx],0
  jz nstrinstl
  ret
  nstrinstl:
  push ecx
  push 0
  call getmem#sys
  pop ecx
  'mov eax,0
  lea edi,[ebx+656]
  call addlisti
  mov [ecx],edi  ' assign pointer to variable
  ret


  strinstg: 'at [ebx+2096]
  '=======================
  '
  cmp dword ptr [ecx],0
  jz nstrinstg
  ret
  nstrinstg:
  push ecx
  push 0
  call getmem#sys
  pop ecx
  'mov eax,0
  lea edi,[ebx+664]
  call addlisti
  mov [ecx],edi  ' assign pointer to variable
  ret


  deltmp: 'at [ebx+2104]
  '====================
  '
  deltmpi:
  lea edi,[ebx+648]
  call delchaini   'delete temp strings
  ret


  delloc: 'at [ebx+2112]
  '====================
  '
  lea edi,[ebx+656]
  call delchaini   'delete local strings
  ret

  compnnul: 'at [ebx+2128]
  '======================
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

  sysdelbufs: 'at [ebx+2144]
  '========================
  '           '
  push [ebx+640]    'concatenation buffer
  call freemem#sys  '
  lea edi,[ebx+648] 'temp list
  call cdelsysbufs
  lea edi,[ebx+656] 'local list
  call cdelsysbufs
  lea edi,[ebx+664] 'global list
  call cdelsysbufs
  push [ebx+680]    'lib handle buffer
  call freemem#sys
  '
   ret
  '
  cdelsysbufs:      ' repeat
  '------------------'
  'delete each list  '
  '------------------'
  cmp  dword ptr [edi],0
  jz ndempty
  call delchaini'delete strings in list
  push [edi]
  call freemem#sys   'free this final list
  '------------------'
  ndempty:
  ret               '
  '=================='


  'PREPARE JOIN-BUFFER
  '
  catbufprp: 'at [ebx+2152]
  '=======================
  '
  push edi
  mov edi,[ebx+640]
  cmp dword ptr [edi],16
  jg ncatbufprp
    mov dword ptr [edi],16
  ncatbufprp:
  add dword ptr [edi],8
  add edi,[edi]
  mov dword ptr [edi-8],-1 'PLACE STOP MARKER AT OFFSET 16 OR MORE
  pop edi
  ret


  'ADD BSTR TO LIST  ' byref ptr in eax, list in edi


  badcatl: 'at [ebx+2160] ' ptr in eax, list in edi
  '=====================
  '
  cmp eax,0         ' pointer exist?
  jnz nbadcatl1     '
    ret             '
  nbadcatl1:        '
  mov eax,[eax]     ' deref
  push edi
  mov edx,0
  cmp eax,0
  jz nbadcatl2        '
  mov edx,[eax-4]   ' get length
  nbadcatl2:
  mov edi,[ebx+640] ' catlist 
  mov ecx,[edi]     ' next place
  add ecx,8         ' preinc stride of 2 dwords
  mov [edi],ecx     '
  add ecx,edi       '
  '------------------'
  mov [ecx-8],edx   ' store length
  mov [ecx-4],eax   ' store pointer
  pop edi
  ret               '


  'ADD ZSTR TO LIST  '


  zadcatl: 'at [ebx+2168] ' ptr in eax, list in edi
  '=====================
  '
  cmp eax,0 'check for null pointer
  jnz nzad
  ret
  nzad:
  push edi
  mov edi,[ebx+640]' catlist 
  mov ecx,[edi]     ' next place
  add ecx,8         ' preinc place in list
  mov [edi],ecx     '
  add ecx,edi       '
  '------------------'
  push eax          ' save string base pointer
  push ecx          ' save list place pointer
  xor edx,edx       ' clear counter         ' 
  rzadl:          '
    mov cl,[eax]  ' get character
    inc edx       ' add to count
    inc eax       ' add to pointer
    cmp cl,0      ' is it a null char
    jnz rzadl       ' repeat if not
  pop ecx           ' restore list place pointer
  pop eax           ' restore string base pointer
  dec edx           ' count excluding null terminator char
  mov [ecx-8],edx   ' store length excl null
  mov [ecx-4],eax   ' store pointer
  pop edi
  ret               '


  'JOIN STRINGS TOGETHER
  '
  'STACKING VERSION TO HANDLE NESTED STRING EXPRESSIONS
  '
  '=================='
  ' FORMAT: LEN PTR '
  '=================='

  '  #################################           ############################
  '  # |  |  |  |  |  |  |  |  |  |  #  =====|>  #                          #
  '  #################################           ############################



  'STACKING SCHEME (ascending stack)
  '
  '------------
  ' HEADER:
  '  0 LIMIT BOUNDARY
  '  4 CURRENT BOUNDARY
  '  8 UNUSED
  ' 12 UNUSED
  '------------
  ' STRING LIST
  '------------
  ' stop marker
  '------------
  ' new string
  ' new string
  '------------
  ' stop marker
  '------------
  ' new string
  ' new string
  '...
  '==================


  'null strings must not be present in the buffer list.


  joins: 'at [ebx+2184] ' ( eax destptr if exists, edi list of strings to) eax new string ptr
  '===================
  '                 '
  joinsi:           '
  '
  push esi          'save reg
  push edi          'save reg
  '
  mov edi,[ebx+640] 'the join string list
  mov esi,[edi]     'count step
  add edi,esi       'boundary of data
  sub esi,16        'base zero
  '
  xor ecx,ecx       'byte counter
  '
  'COUNT ALL BYTES
  '
  (  
    sub edi,8       'last data downward
    sub esi,8       'down counter
    jl exit
    mov edx,[edi]   '
    cmp edx,-1      'CHECK FOR STOP MARKER
    jz exit
    add ecx,edx     'add length of string
    repeat
  )                 'finished counting bytes
  '
  'CHECK EMPTY?
  '
  (
    cmp ecx,0
    jnz exit 'no bytes
    cmp eax,0
    jz exit 'to create a null Bstring
    mov word ptr [eax],0 ' NULL TERMINATION: 2 NULL BYTES
    jmp ajoinsi    
  )
  '
  mov esi,ecx       'byte total required
  '
  'accepts 0 byte requests
  '
  '
  'itr check overflow before
  '
  (
    cmp eax,0       'request new Bstring or use existing Zstring
    jnz exit
    push ecx        'req n bytes
    call getmem#sys 'create new string
    cmp eax,0       'test for success
    jz ajoinsi      'failure so exit with null bstr
    cmp dword ptr [eax-4],0
    jz ajoinsi      'no bytes to transfer so exit with valid bstr
    jmp dnews       'otherwise prepare for copy joining
  '
  )
  '
  mov word ptr [eax+esi],0 'insert double null into target boundary
  '
  '-----
  dnews: 'entry point for copy joining
  '-----
  '
  push eax          'target base
  mov ecx,esi       'byte count
  xor edx,edx       'clear byte adder
  '
  push edi          'save stop point
  '
  (
    add edi,8       'step forward for next string
    cmp edx,ecx     'check byte count
    jge exit        'copied all the bytes so exit
    add edx,[edi]   'n to copy
    push ecx        'save byte count
    push edx        'save byte tally
    mov ecx,[edi]   'LENGTH OR STOP MARKER
    cmp ecx,0
    jle ncops
    mov esi,[edi+4] 'pointer
    '
    (               'copy over
      mov dl,[esi]  'source byte
      mov [eax],dl  'dest
      inc eax       'inc dest
      inc esi       'inc src
      dec ecx       'downcount bytes to copy
      jg repeat     'continue copying
    )
    '
    '-----
    ncops:
    '-----
    '
    pop edx         'restore byte tally
    pop ecx         'restore byte count
    repeat
  )
  '
  '-----
  xcopa:
  '-----
  '
  pop ecx           'restore stop point
  '
  mov edi,[ebx+640]
  sub ecx,edi
  cmp ecx,16        'stop marker at 16 'empty buffer at 8
  jge nemptyb
  mov ecx,16
  nemptyb:
  mov [edi],ecx     'boundary for next string
  '
  '
  pop eax          'restore target base
  '
  xjoinsi:
  '
  pop edi          'restore edi
  pop esi          'restore esi
  ret     
  '
  '(null string or Bstring denied)
  '
  '
  '-------
  ajoinsi: 'cleardown for null byte strings
  '-------
  '
  push eax
  push ecx
  jmp xcopa
  


'COMPARE DYNAMIC STRINGS

  comps: 'at [ebx+2192] '(compare [esp+8]-[esp+4] )
  '===================
               '
  compsi:            ' select least length
  mov edx,[esp+8]  '
  mov ecx,[esp+4]  '
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

  'ADD BSTR TO LOCAL LIST

  assloc: 'at [ebx+2216]  'ecx addr of chainable list
  '====================
  '               '
  lea edi,[ebx+656]
  call addlisti
  ret              '


  'ADD BSTR TO TEMP LIST

  asstmp: 'at [ebx+2224]
  '====================
  '
  asstmpi:
  lea edi,[ebx+648]
  call addlisti
  ret


  'ASSIGN LOCAL BSTRING

  asstrl: 'at [ebx+2240] 'dyn addr in ecx, bstr in eax
  '====================
  '
  mov edi,[ecx]    '
  cmp edi,0        ' pointer exists?
  jnz naddl        '
    lea edi,[ebx+656]
    call addlisti  ' add to chainable list
    mov [ecx],edi  ' assign pointer to variable
   ret
  naddl:           '
  cmp dword ptr [edi],0' bstring already exists?
  jz nwipe         '
    push eax       '
    push [edi]     '
    call freemem#sys ' release original bstr
    pop eax        '
  nwipe:           '
  mov [edi],eax    ' assign bstr to pointer
  ret                '


  'ASSIGN GLOBAL/STATIC BSTR

  asstrg: 'at [ebx+2248] 'dyn addr in ecx, bstr in eax
  '====================
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
    call freemem#sys ' release original bstr
    pop eax        '
  nwipeg:          '
  mov [edi],eax    ' assign bstr to pointer
  ret                '


  'TRANSFER BSTRING (return value in function)

  trbstr: 'at [ebx+2256] 'transfer dyn string for returning BSTR
  '====================
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



  'SHUFFLE LAST TO FIRST THEN JOIN

  shjoins: 'at [ebx+2264] 'shuffle and join
  '=====================
  '
  push eax         '
  push esi
  push edi         '
  '----------------'
  mov edi,[ebx+640]'the join string list
  mov esi,[edi]    ' count step
  cmp esi,16       ' empty
  jle xshjoins     '
  add edi,esi      ' end of data
  sub edi,8        ' last string record
  sub esi,16       ' base counter zero
  mov ecx,[edi]    ' hold length last string
  mov edx,[edi+4]  ' hold ptr last string
  'cmp edx,0        ' CHECK FOR NULL STRING PTR
  'jz  xshjoins     '
  'cmp ecx,0        ' CHECK FOR EMPTY STRING
  'jz xshjoins      '
  '----------------'
  doshuf:          ' do
    mov eax,[edi-8]' TRANSFER LENGTH
    cmp eax,-1     ' CHECK FOR END MARKER
    jz xdoshuf     ' EXIT IF MARKER
    mov [edi],eax  '
    mov eax,[edi-4]' TRANSFER POINTER
    mov [edi+4],eax'
    sub edi,8      ' next string back
    jmp doshuf     ' repeat
  xdoshuf:         ' finished counting bytes
  '----------------'
  mov [edi],ecx    ' insert length
  mov [edi+4],edx  ' insert ppointer
  '----------------'
  xshjoins:
  pop edi
  pop esi          '
  pop eax          '
  '----------------'
  call joinsi      '
  ret                '


  'ADD BSTR TO LIST  ' byval bstr in eax, list in edi



  sadcatl: 'at [ebx+2272] 'bstr byval in eax
  '=====================
  '
  mov edx,0
  cmp eax,0         ' bstr exist?
  jz nsadcatl1      '
  mov edx,[eax-4]   ' get length
  nsadcatl1:        '
  push edi          '
  mov edi,[ebx+640] ' catlist 
  mov ecx,[edi]     ' next place
  add ecx,8         ' preinc stride of 2 dwords
  mov [edi],ecx     '
  add ecx,edi       '
  '-----------------'
  mov [ecx-8],edx   ' store length
  mov [ecx-4],eax   ' store pointer
  pop edi
  ret               '

  'BSTRING BYREF COMPARE

  compis: 'at [ebx+2280] 'bstr byref compare operand with accum
  '====================
  '
  mov eax,[esp+8]    ' operand
  cmp eax,0          '
  jz ncompis         '
  mov eax,[eax]      '
  ncompis:           '
  mov [esp+8],eax  '
  jmp compsi         '



  compris: 'at [ebx+2288] 'bstr byref compare with accum with operand
  '=====================
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

  deref0: 'at [ebx+2296]
  '====================
  '
  cmp eax,0
  jnz derefok
  ret
  derefok:
  mov eax,[eax]
  ret



  compn: 'at [ebx+2304]  'COMPARE [esp+12] WITH [esp+4] NSTRING
  '===================
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


  ltrims: 'at [ebx+2312]
  '====================
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
  ltrimr:
  dec edi
  jl ltrimx
  mov al,[esi]
  inc esi
  cmp al,32
  jle ltrimr
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
  call copysn
  '
  pop eax
  pop esi
  ret 4



  rtrims: 'at [ebx+2320]
  '====================
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
  rtrimr:
  dec edi
  jl rtrimx
  dec esi
  mov al,[esi]
  cmp al,32
  jle rtrimr
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
  call copysn
  '
  pop eax
  pop esi
  ret 4



  lcases: 'at [ebx+2328]
  '====================
  '
  push esi
  mov esi,[esp+8]
  mov edi,0
  cmp esi,0 'null string test
  jz lwrx1
  mov edi,[esi-4]
  lwrx1:
  push edi
  push 0
  call SysAllocStringByteLen
  mov edx,edi
  mov edi,eax
  push eax
  lwrr:
  dec edx
  jl lwrx
  mov al,[esi]
  cmp al,65
  jl lwrn
  cmp al,90
  jg lwrn
  add al,32
  lwrn:
  mov [edi],al
  inc esi
  inc edi
  jmp lwrr
  lwrx:
  pop eax
  pop esi
  ret 4


  ucases: 'at [ebx+2336]
  '====================
  '
  push esi
  mov esi,[esp+8]
  mov edi,0
  cmp esi,0 'null string test
  jz uprx1
  mov edi,[esi-4]
  uprx1:
  push edi
  push 0
  call SysAllocStringByteLen
  mov edx,edi
  mov edi,eax
  push eax
  uprr:
  dec edx
  jl uprx
  mov al,[esi]
  cmp al,97
  jl uprn
  cmp al,122
  jg uprn
  sub al,32
  uprn:
  mov [edi],al
  inc esi
  inc edi
  jmp uprr
  uprx:
  pop eax
  pop esi
  ret 4



  lefts: 'at [ebx+2344]
  '===================
  pop eax  'return address
  pop edx  'string
  push 1   'insert offset
  push edx 'string
  push eax 'return address
  jmp midsi


  '2352 ?



  mids: 'at [ebx+2360]
  '==================
  '
  midsi: 'entry point for bstrings
  '
  mov ecx,0          ' default source length is 0
  mov edi,[esp+4]    ' ptr
  cmp edi,0
  jz midok1
  mov ecx,[edi-4]    'get source length
  '
  midok1: ' the length of source
  '
  '------------------------------                   '
  astrin: 'entry point for asciiz
  '------------------------------
                     '
  push esi           ' preserve esi
  mov edx,[esp+12]   ' get offset
  '                  '
  '-------------     '
  'NEG OFFSETS       '
  '-------------     '
  '                  '
  cmp edx,0          '
  jnz midnoinc
  inc edx            'change offset 0 to 1
  '
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
  call copysn         '
  mov eax,esi        ' new bstring to return
  '
  midx:                '
  '
  pop esi            'restore esi
  ret 12             '


  ascs: 'at [ebx+2368]
  '==================
  '
  ascsi:
  xor eax,eax
  push esi         '
  mov esi,[esp+8]  'pointer
  cmp esi,0
  jz ascx
  mov edi,[esi-4]  'length
  cmp edi,0
  jle ascx
  ascsi1:            '
  xor eax,eax      'clear
  mov edx,[esp+12] 'req pos
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
  add esi,edx      '
  mov al,[esi]     '
  ascx:              '
  pop esi          '
  ret 8            '


  lens: 'at [ebx+2376]
  '==================
  '
  mov eax,[esp+4]  '
  cmp eax,0        '
  jz nlens         '
  mov eax,[eax-4]  '
  nlens:           '
  ret 4            '



  chrs: 'at [ebx+2384]
  '==================
  '               '
  push 1           '
  push 0           '
  call SysAllocStringByteLen
  'call [ebx+160] 'AllocString
  mov dl,[esp+4]   '
  mov [eax],dl     '
  ret 4            '



'====

'mid for asciiz

  midz: 'at [ebx+2392]
  '==================
  '
  midzi:
  mov edi,[esp+4] 'pass base in edi
  mov ecx,edi
  rmidz:
  mov al,[ecx]
  inc ecx
  cmp al,0
  jnz rmidz
  dec ecx          'exclude null term in count
  sub ecx,edi      'pass length in ecx
  jmp astrin



  leftz: 'at [ebx+2400]
  '===================
  '
  pop eax  'return address
  pop edx  'string base
  push 1   'insert offset
  push edx 'string basr
  push eax 'return address
  jmp midzi



  '2 PARAM MID

  mids2: 'at [ebx+2416]
  '===================
  '
  pop eax  'return address
  pop ecx  'string base
  pop edx  'string offset
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
  push edx 'string offset
  push ecx 'string base
  push eax 'return address
  jmp midsi


  midz2: 'at [ebx+2424]
  '===================
  '
  pop eax          'return address
  pop edi          'address base
  pop edx          'offset
  push &h7fffffff  'req max length
  push edx         'offset
  push edi         'ptr
  push eax         'return address
  jmp midzi        '


  'SINGLE PARAM ASCII

  ascs1: 'at [ebx+2432]
  '===================
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
  add edx,[esp+4] ' ADD STATIC VARIABLE BASE [ESI]
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

  freels: 'at [ebx+2448]
  '====================
  '
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
  ret




  'COMMAND MID:
  '
  'MID()=
  '  
  midbuf: 'at [ebx+2456]
  '====================
  '
  mov ecx,[esp+4]   'byref buffer ptr
  cmp ecx,0
  jz xmidbuf        'null buffer
  mov ecx,[ecx]     'deref
  cmp ecx,0
  jz xmidbuf
  mov edx,[ecx-4]   'length of buffer
  sub edx,[esp+8]   'offset
  inc edx           'space available
  mov edi,[esp+12]  'source
  cmp edi,0
  jz  xmidbuf       'nul source
  cmp edx,[edi-4]   'check length of source
  jle nmidbuf1      '
    mov edx,[edi-4] 'least qty to transfer
  nmidbuf1:
  cmp edx,0         'check if any to transfer
  jle xmidbuf
  add ecx,[esp+8]   ' add index to target
  dec ecx           ' base zero
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





  'STRING(N,BYTE)


  stringa: 'at [ebx+2464]
  '=====================
  '
  stringi:
  mov eax,[esp+4]  'length
  push eax         'length
  push 0           'no copy
  '
  call SysAllocStringByteLen
  'call [ebx+160] ' AllocString
  '
  mov ecx,[esp+4]  'length
  mov edx,[esp+8]  'byte fill
  push eax         'addr
    push edx       'byte fill
    push ecx       'length
    push eax       'ptr
    call init1#sys#sys#sys 'fill
  pop eax ' BSTR addr
  ret 8

  stringz: 'at [ebx+2472]
  '=====================
  '
  stringj:
  mov eax,[esp+8]
  cmp eax,0
  jz nstringz
    mov eax,[eax]
    mov [esp+8],eax
  nstringz:
  jmp stringi


  strings: 'at [ebx+2480]
  '=====================
  '
  jmp stringj


  spaces: 'at [ebx+2488]
  '====================
  '
  pop eax
  pop ecx
  push 32  '+8
  push ecx '+4
  push eax
  jmp stringi


  prints: 'at [ebx+2496]
  '====================
  '
  mov eax,[esp+4]
  push eax
  call [ebx+2048]
  ret 4


  instrs2: 'at [ebx+2504]
  '=====================
  '
  pop eax
  push 1
  push eax
  jmp [ebx+320]


  'GETFILE "T.TXT",F

  getfile2: 'at [ebx+2512]
  '======================
  '
  mov edi,[esp+8]
  push [edi]
  call freemem#sys 'dump existing string
  mov eax,[esp+4]
  push eax
  call getfiles
  mov [edi],eax
  ret 8  



  printv: 'at [ebx+2520]
  '====================
  '
  'VALUE IN FPU
  '
  call float_to_ascii 'was strs
  push eax
  push eax
  call [ebx+2048]
  call freemem#sys
  ret


'====


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
  static sys a[4]
  return & a
  end function

  '-------------------------
  sub uncompile(s as string)
  '=========================
  '...
  end sub


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
  adrf mboxa      2048 'display string in message box
  adrf noof       2056 'was newlist. create a generic list (header of 16)
  adrf addlist    2064 'add to list
  adrf delist     2072 'delete
  adrf delchain   2080 'delete chain of lists
  adrf strinstl   2088 'check string instance local
  adrf strinstg   2096 'check string instance global
  adrf deltmp     2104 '
  adrf delloc     2112 '
  adrf noof       2120 '
  adrf compnnul   2128 '
  '
  adrf noof       2136 '
  adrf sysdelbufs 2144 'del system buffs
  adrf catbufprp  2152 'clear string lists
  adrf badcatl    2160 'add byref bstr to cat list [640]
  adrf zadcatl    2168 'add z string to cat list   [640]
  adrf noof       2176 '
  adrf joins      2184 'join strings: copy into one
  adrf comps      2192 'compare bstring
  adrf compz      2200 'compare zstrings
  adrf noof       2208 '
  adrf assloc     2216 'assign to local bstr local list [656]
  adrf asstmp     2224 'assign to temp bstr list [648]
  adrf noof       2232 '
  adrf asstrl     2240 'assign bstring [local list 656]
  adrf asstrg     2248 'assign bstring [global list 664]
  adrf trbstr     2256 'transfer bstr
  adrf shjoins    2264 'string shuffle and join for str+=...
  adrf sadcatl    2272 'add byval bstr to list (bstr params passed byval)
  adrf compis     2280 'compare with bstr byref with byval
  adrf compris    2288 'compare with bstr byref with byval
  adrf deref0     2296 'dereference if possible or return 0
  adrf compn      2304 'compare n bytes
  '
  adrf ltrims     2312 'ltrim
  adrf rtrims     2320 'rtrim
  adrf lcases     2328 'lcase
  adrf ucases     2336 'ucase
  adrf lefts      2344 'left
  adrf noof       2352 '
  adrf mids       2360 'mid
  adrf ascs       2368 'asc
  adrf lens       2376 'len
  adrf chrs       2384 'chr
  adrf midz       2392 'mid for asciiz string literals
  adrf leftz      2400 'left for asciiz
  adrf noof       2408 '
  adrf mids2      2416 '2 param mid
  adrf midz2      2424 '2 param mid for asciiz
  adrf ascs1      2432 '1 param asc
  '
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
  adrf printv     2520 'print value
  '
  adrf getmem#sys            08 'new nulled memory block
  adrf freemem#sys           16 'free memory block
  adrf procaddrs#sys#sys#sys 48 'bind proc addresses
  adrf copys0                56 'copy nul terminated string
  adrf copys00               64 'copy null terminated wide string (2 byte characters)
  adrf copysn                72 'copy string of n bytes
  adrf getvarptr#string      80 'O2 GET HOST VAR ADDRESS
  '
  '
  [ebx+128]=& errors
  [ebx+192]=& ascii_to_float#string
  [ebx+200]=& float_to_ascii
  [ebx+208]=& hexs
  [ebx+320]=& instrsh#sys#string#string
  [ebx+328]=& replaces#string#string#string
  [ebx+336]=& getfiles
  [ebx+344]=& putfiles
  [ebx+352]=& guidvals
  [ebx+360]=& guidtxts
  [ebx+368]=& compile#string
  [ebx+376]=& uncompile#string
  '
  jmp fwd endp
  '
  '-------------------------------
  _newbuf: 'CREATE A SYSTEM BUFFER
  '===============================
  '
  push 4096 : push 0  : call SysAllocStringByteLen
  mov ecx,4096 : mov edx,eax
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
  lea edi,[ebx+640] 'CREATE SYSTEM BUFFERS 
  call _newbuf
  call _newbuf
  call _newbuf
  call _newbuf '640 to 664
  '
  lea edi,[ebx+680]
  call _newbuf 'SET UP BUFFER FOR  LIB HANDLES


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
  sub esp,16
  sys a at [ebp-4]

  a=0


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
  'push eax : call [ebx+2448] : call [ebx+2144] : pop eax
  'end def


  '--------------------------------
  'EPILOG (APPENDED TO END OF CODE)
  '================================
  '
  def _epilog

  ._end_

    #ifndef dll
      mov a,eax
      push 0 'place for exit code
      mov eax,esp 
      push eax
      call getModuleHandle
      push eax
      call GetExitCodeProcess
      mov eax,a
      call ExitProcess
    #endif
    mov esp,ebp : pop ebp : pop edi : pop esi : pop ebx
    ret
  ._error_
    push ecx : call [ebx+2048]
    jmp _end_

  end def

