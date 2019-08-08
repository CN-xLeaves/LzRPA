'
'
'
'         ###############
'       ###################
'      ###               ###
'     ###    ###          ###
'    ###    ## ##         ###
'    ###   ##   ##        ###
'    ###  ##     ##       ###
'    ###  ##      ##      ###
'    ###  ##      ##      ###
'    ###   ####  ##      ###
'     ###    ####       ###
'      ###             ###
'       ###           ###
'         #############
'           #########




  '----------
  'META TYPES
  '==========

  const  metatypes as string=_
  " 1    structured variable,"+_
  " 0    primitive variable or constant,"+_
  " -1   def macro,"+_
  " -2   defs enumeration,"+_
  " -3   type / class,"+_
  " -4   o2 intrinsic function,"+_
  " -5   proc sub or function,"+_
  " -6   imported sub or function,"+_
  " -7   vectored sub or function - declare ... AT v,"+_
  " -8   struct from typedef,"+_
  " -9   reserved word,"+_
  " -10  x86 register,"+_
  " -11  type attribute with 1 param,"+_
  " -12  type attributes with 2 params,"+_
  " -13  o2 major keywords,"+_
  " -14  o2h major keywords,"+_
  " -15  C type keywords,"+_
  " -16  overoadable intrinsic functions,"+_
  " -17  intrinsic float macro,"+_
  " -18  o2h labels,"+_
  " -19  o2h low level macro,"+_
  " -20  o2h high level macro,"+_
  " -21  o2h operator,"+_
  ""


  '---------
  'OPERATORS
  '=========
  '
  '
  const as string opname=_
  " 0 load "+_
  " 1 load "+_
  " 2 `=` "+_
  " 3 cmp "+_
  " 4 push "+_
  " 5 dump "+_
  " 6 pop "+_
  " 8 `+=` "+_
  " 9 `-=` "+_
  " 10 swap "+_
  " 11 not "+_
  " 11 ! "+_
  " 12 inc "+_
  " 13 dec "+_
  " 14 `*=` "+_
  " 15 `/=` "+_
  " 16 `==` "+_
  " 17 `<>` "+_
  " 28 `<` "+_
  " 29 `>=` "+_
  " 30 `<=` "+_
  " 31 `>` "+_
  " 33 and "+_
  " 33 & "+_
  " 34 or "+_
  " 34 | "+_
  " 35 xor "+_
  " 65 `and=` "+_
  " 66 `or=` "+_
  " 67 `xor=` "+_
  " 42 * "+_
  " 43 + "+_
  " 45 - "+_
  " 47 / "+_
  " 92 \ "+_
  " 71 `&&` "+_ 'boolean and
  " 72 `||` "+_ 'boolean or
  " 74 `<<` "+_
  " 75 `>>` "+_
  " 94 ^ "+_   'normally power of
  ""

  '----------
  'DATA TYPES
  '==========
  '
  'ENCODING FROM SIGNATURE
  '
  const as string idtype=_
  " short 2,"+_
  " long 4,"+_
  " int 4,"+_
  " bool 4,"+_
  " integer 4,"+_
  " quad 8,"+_
  " byte 21,"+_
  " byte 1,"+_
  " word 22,"+_
  " dword 24,"+_
  " qword 28,"+_
  " single 64,"+_
  " double 68,"+_
  " ext 6A,"+_
  " extended 6A,"+_
  " cpu 4,"+_
  " fpu 40,"+_
  " zstring A1,"+_
  " asciiz A1,"+_
  " bstring C1,"+_
  " bstr C1,"+_
  " string E1,"+_
  " astring E1,"+_
  " sys 1FF,"+_
  " any 1FF,"+_
  " sub 11F,"+_
  " function 11F,"+_
  " method 11F,"+_
  " mmx 130,"+_
  " xmm 150,"+_
  ""

  '
  '-------------------
  'CALLING CONVENTIONS
  '===================
  '
  const as string callco=_
  " stdcall 100"+_
  " cdecl 101"+_
  " ms64 102"+_
  " pascal 108"+_
  " fpu 111"+_
  ""
  '



kernel_funs:




'===========================
'>>O2 LOW LEVEL MACROS
'===========================



data "#view"         ,-1, "###"
data "#endv"         ,-1, "###"
'==============================

'group:    directives
'action:   creates a window for compiler listings.
'use:      Allows the programmer to see a selected part of the compiled code
'example:  dim a,b,c
'          ###
'          a=b+c
'          ###
'          s="Value "+str(a)
'remarks:  #view and #endv are generated internally from the pair of '###' symbols.



'========================
'>>O2 LOW LEVEL FUNCTIONS
'========================




data "getmemory"     ,-4, 08
'===========================

'action:   allocate block of memory and return its base address
'use:      address=getmemory bytes
'example:  m=getmemory 8000
'related:  freememory, news, frees
'group:    low level oxygen functions



data "freememory"    ,-4, 16
'===========================

'action:   free previously allocated memory block
'use:      freememory address
'example:  freememory m
'related:  getmemory, news, frees
'group:    low level oxygen functions



data "loadlibrary"   ,-4, 24
'===========================

'action:   load a library (if not already loaded) and return its handle
'use:      handle=loadlibrary "library filename"
'example:  h=loadlibrary "kernel32.dll"
'related:  freelibrary, library, getprocaddress
'group:    low level oxygen functions


data "freelibrary"   ,-4, 32
'===========================

'action:   free library
'use:      freelibrary handle
'example:  freelibrary h
'related:  loadlibrary, library, getprocaddress
'group:    low level oxygen functions



data "getprocaddress" ,-4, 40
'============================

'action:   get procedure address
'use:      getprocaddress libraryHandle "proc name"
'example:  a=getprocaddress h, "AllocConsole"
'related:  loadlibrary, freelibrary, library
'group:    low level oxygen functions



data "copy0"         ,-4, 56
'===========================

'action:   copy null terminated string to another location
'use:      copy DestinationAddress, SourceAddress
'example:  copy &a,&b
'related:  copy00 copy
'group:    low level oxygen functions



data "copy00"        ,-4, 64
'===========================

'action:   copy null terminated string of wide (2 byte) characters to another location
'use:      copy DestinationAddress, SourceAddress
'example:  copy &v,&w
'related:  copy0, copy, copyn
'group:    low level oxygen functions



data "copyn"         ,-4, 72
data "copy"          ,-4, 72
'===========================

'action:   string to another location by a specified number of bytes
'use:      copy DestinationAddress, SourceAddress, NumberOfBytes
'example:  copy &dest,&src,n
'remarks:  copy and copyn are the same
'related:  copy0 copy00
'group:    low level oxygen functions



data "strd"          ,-4, 88
'===========================

'action:   convert double precision number to string 
'use:      strd Number, StringAddress 
'example:  strd n,&s  
'related:  str, hex, vald, val
'group:    low level oxygen functions


data "vald"          ,-4, 96
'===========================

'action:   convert string to double precision number
'use:      vald StringAddress, &Value
'example:  vald "0.618033",&phi
'related:  val, str, hex, strd
'group:    low level oxygen functions



data "mbox"         ,-4, 2048 'mboxa
'===========================

'action:   display message null-terminated ascii string
'use:      mbox StringAddress
'example:  mbox "okay"
'related:  print
'group:    low level oxygen functions



data "comparestr"   ,-4, 2192' compsa ' COMPARING BSTRS
'===========================

'action:   compare first string with second string
'use:      comparestr bstr1,bstr2 : jg greater : jl less : jz equal      
'example:  comparestr bs1,bs2
'related:  str, ( < = > )
'group:    low level oxygen functions


'===========================
'>>COMMON RESERVED WORDS
'===========================
data "exit"            ,-9,1
data "repeat"          ,-9,1
data "mov"             ,-9,0
data "lea"             ,-9,0
data "add"             ,-9,0
data "sub"             ,-9,1
data "mul"             ,-9.0
data "div"             ,-9,0
data "jmp"             ,-9,1
data "jz"              ,-9,0
data "jnz"             ,-9,0
data "call"            ,-9,1
data "and"             ,-9,0
data "or"              ,-9,0
data "xor"             ,-9,0
data "not"             ,-9,1
data "shl"             ,-9,0
data "shr"             ,-9,0
data "sal"             ,-9,0
data "sar"             ,-9,0
'===========================
'groupref: common_asm
'group:    common x86 assembly instrunctions




'===========================
'>>REGISTERS
'===========================
data "al"      ,-10, 1,0,1
data "cl"      ,-10, 1,1,1
data "dl"      ,-10, 1,2,1
data "bl"      ,-10, 1,3,1
data "ah"      ,-10, 1,4,1
data "ch"      ,-10, 1,5,1
data "dh"      ,-10, 1,6,1
data "bh"      ,-10, 1,7,1
'---------------------------
data "ax"      ,-10, 2,0,1
data "cx"      ,-10, 2,1,1
data "dx"      ,-10, 2,2,1
data "bx"      ,-10, 2,3,1
data "sp"      ,-10, 2,4,1
data "bp"      ,-10, 2,5,1
data "si"      ,-10, 2,6,1
data "di"      ,-10, 2,7,1
'---------------------------
data "eax"     ,-10, 4,0,1
data "ecx"     ,-10, 4,1,1
data "edx"     ,-10, 4,2,1
data "ebx"     ,-10, 4,3,1
data "esp"     ,-10, 4,4,1
data "ebp"     ,-10, 4,5,1
data "esi"     ,-10, 4,6,1
data "edi"     ,-10, 4,7,1
'---------------------------
data "st0"     ,-10,10,0,2
data "st1"     ,-10,10,1,2
data "st2"     ,-10,10,2,2
data "st3"     ,-10,10,3,2
data "st4"     ,-10,10,4,2
data "st5"     ,-10,10,5,2
data "st6"     ,-10,10,6,2
data "st7"     ,-10,10,7,2
'---------------------------
data "mmx0"    ,-10,16,0,3  
data "mmx1"    ,-10,16,1,3  
data "mmx2"    ,-10,16,2,3  
data "mmx3"    ,-10,16,3,3  
data "mmx4"    ,-10,16,4,3  
data "mmx5"    ,-10,16,5,3  
data "mmx6"    ,-10,16,6,3  
data "mmx7"    ,-10,16,7,3
'---------------------------  
data "xmm0"    ,-10,16,0,4  
data "xmm1"    ,-10,16,1,4  
data "xmm2"    ,-10,16,2,4  
data "xmm3"    ,-10,16,3,4  
data "xmm4"    ,-10,16,4,4  
data "xmm5"    ,-10,16,5,4  
data "xmm6"    ,-10,16,6,4  
data "xmm7"    ,-10,16,7,4  
data "xmm8"    ,-10,16,8,4  
data "xmm9"    ,-10,16,9,4  
data "xmm10"   ,-10,16,10,4  
data "xmm11"   ,-10,16,11,4  
data "xmm12"   ,-10,16,12,4  
data "xmm13"   ,-10,16,13,4  
data "xmm14"   ,-10,16,14,4  
data "xmm15"   ,-10,16,15,4  
'---------------------------
data "cr0"     ,-10,4,0,5 '129  
data "cr2"     ,-10,4,1,5  
data "cr3"     ,-10,4,2,5  
data "cr4"     ,-10,4,3,5  
'---------------------------
data "dr0"     ,-10,4,0,6 '130  
data "dr1"     ,-10,4,1,6  
data "dr2"     ,-10,4,2,6  
data "dr3"     ,-10,4,3,6  
data "dr4"     ,-10,4,4,6 
data "dr5"     ,-10,4,5,6  
data "dr6"     ,-10,4,6,6  
data "dr7"     ,-10,4,7,6  
'---------------------------
data "es"      ,-10,4,0,7 '131  
data "cs"      ,-10,4,1,7  
data "ss"      ,-10,4,2,7  
data "ds"      ,-10,4,3,7  
data "fs"      ,-10,4,4,7 
data "gs"      ,-10,4,5,7  
'---------------------------
'64 bit mode registers
'---------------------------
data "rax"     ,-10, 8, 0,9
data "rcx"     ,-10, 8, 1,9
data "rdx"     ,-10, 8, 2,9
data "rbx"     ,-10, 8, 3,9
data "rsp"     ,-10, 8, 4,9
data "rbp"     ,-10, 8, 5,9
data "rsi"     ,-10, 8, 6,9
data "rdi"     ,-10, 8, 7,9
data "r8"      ,-10, 8, 8,9
data "r9"      ,-10, 8, 9,9
data "r10"     ,-10, 8,10,9
data "r11"     ,-10, 8,11,9
data "r12"     ,-10, 8,12,9
data "r13"     ,-10, 8,13,9
data "r14"     ,-10, 8,14,9
data "r15"     ,-10, 8,15,9
'---------------------------
data "spl"     ,-10, 1, 4,9
data "bpl"     ,-10, 1, 5,9
data "sil"     ,-10, 1, 6,9
data "dil"     ,-10, 1, 7,9
'---------------------------
data "r8l"     ,-10, 1, 8,9
data "r9l"     ,-10, 1, 9,9
data "r10l"    ,-10, 1,10,9
data "r11l"    ,-10, 1,11,9
data "r12l"    ,-10, 1,12,9
data "r13l"    ,-10, 1,13,9
data "r14l"    ,-10, 1,14,9
data "r15l"    ,-10, 1,15,9
'---------------------------
data "r8w"     ,-10, 2, 8,9
data "r9w"     ,-10, 2, 9,9
data "r10w"    ,-10, 2,10,9
data "r11w"    ,-10, 2,11,9
data "r12w"    ,-10, 2,12,9
data "r13w"    ,-10, 2,13,9
data "r14w"    ,-10, 2,14,9
data "r15w"    ,-10, 2,15,9
'---------------------------
data "r8d"     ,-10, 4, 8,9
data "r9d"     ,-10, 4, 9,9
data "r10d"    ,-10, 4,10,9
data "r11d"    ,-10, 4,11,9
data "r12d"    ,-10, 4,12,9
data "r13d"    ,-10, 4,13,9
data "r14d"    ,-10, 4,14,9
data "r15d"    ,-10, 4,15,9
'
'groupref: x86Registers
'action:   access CPU registers directly using Assembly code
'use:      
'example:  mov eax,42
'          add eax,ecx
'result:   eax now contains 42 plus the value in ecx
'remarks:  many of these registers are only accessible if the CPU
'          is runnig in a particular mode - eg: the R* registers require
'          64 bit mode.
'group:    X86 CPU registers



'===========================
'>>O2 ATTRIBUTE MACROS
'===========================


data "sizeof"      ,-11, 1
'===========================

'action:   return length of variable element (in bytes)
'use:      nbytes=sizeof variable
'example:  n=sizeof a
'related:  offsetof, termsof, spanof, extentof,typeof
'group:    variable and type attributes



data "offsetof"    ,-11, 2
'===========================

'action:   return offset of variable from index register
'use:      nbytes=offsetof variable
'example:  n=offsetof a
'related:  sizeof, termsof, spanof, extentof,typeof
'group:    variable and type attributes



data "spanof"      ,-12, 3
'===========================

'action:   return span of array variable dimension
'use:      nbytes=spanof variable dimension
'example:  dim as long v(10,20,4) : n=spanof v,3
'result:   n=16
'related:  sizeof, offsetof, termsof, extentof, typeof
'group:    variable and type attributes



data "typeof"      ,-11, 4
'===========================

'action:   return name of the variable type
'use:      name=typeof variable
'example:  dim as long v : s=typeof v
'result:   s="long"
'related:  sizeof, offsetof, termsof, spanof, recordof
'group:    variable and type attributes



data "recordof"    ,-11, 5
data "structureof" ,-11, 5
data "encodingof"  ,-11, 5
'===========================

'action:   return record of compund (UDT) variabe
'use:      RecordString=recordof variable
'example:  type vt long v,double d
'          dim as vt v :  r=recordof v
'result:   r="
'          v 0 4 1 A0 , long
'          d 4 4 1 A0 , double
'          "
'related:  sizeof, offsetof, termsof, spanof, typeof
'group:    variable and type attributes
'remarks:  recordof structureof and encodingof give the same result



data "statusof"    ,-11, 7
'===========================

'action:   return status of (UDT) element
'use:      RecordString=statusof variable.element
'example:  type vt v as long, d as double
'          dim as vt v :  r=statusof v.d
'result:   r="element"
'other:    status is 1 composite 1 element 2 byref element 8 procedure 9 method 10+ inherited method
'related:  structureof, typeof
'group:    variable and type attributes



data "termsof"     ,-11, 8
'===========================

'action:   return number of dimensions in an array
'use:      n=termsof array variable
'example:  dim as long a(10,20,4) : n=termsof a
'result:   n=3
'related:  spanof, sizeof, offsetof, typeof,recordof
'group:    variable and type attributes



data "extentof"    ,-11, 9
'===========================
'action:   return size of an array in bytes
'use:      n=extentof array
'example:  dim as long a(10,20,4) : n=extentof a
'result:   n=3200
'related:  spanof, termsof, sizeof, offsetof
'group:    variable and type attributes



'===========================
'>>O2 KEYWORDS
'===========================

'===========================

'action:   exit a block of code
'use:      exit
'          exit 2
'example:  (
'            dec eax
'            jle exit
'            repeat
'          )
'result:   repeats block until eax<=0
'related:  repeat
'group:    control structures




data "incl"        ,-13, 01
'===========================

'action:   expand macro non recursively without parameter substitutions
'use:      incl aMacro   
'example:  def helo "hello " %1
'          incl helo
'result:   substitution: "hello " %1
'related:  def
'group:    Oxygen keywords



data "symbols"     ,-13, 02
'===========================

'action:   specify interpretation of some lexical symbols
'use:      
'example:  
'group:    Oxygen keywords



data "indexers"    ,-13, 03
'===========================

'action:   specify register to be used to access variables
'use:      
'example:  
'related:  offset
'group:    Oxygen keywords



data "retn"        ,-13, 04
'===========================

'action:   macro ret n. Releases correct number of bytes at end of procedure (stdcall convention)
'use:      
'example:  
'group:    Oxygen keywords



data "offset"      ,-13, 05
'===========================

'action:   specifty base offset to be used to access variables
'use:      
'example:  
'related:  indexers
'group:    Oxygen keywords



data "skip"        ,-13, 06
'===========================

'action:   start a skip block.
'use:      prevent code within the block from being executed
'example:  
'related:  rem, ('), (/* .. */), (//)
'group:    control structures
'group:    Oxygen keywords



data "rem"         ,-13, 25
'===========================

'action:   comment till end of line
'use:      
'example:  rem this is a comment
'related:  skip, ('), (/* .. */), (//)
'group:    Oxygen keywords



data "with"        ,-13, 07
'===========================

'action:   specify a variable name prefix for assignments
'use:      Allows long names to be shortened when assigning values
'example:  dim as vector4 vectorI
'          with vectorI. : x=1 : y=0 : z=13 : w=0 : end with
'group:    Oxygen keywords



data "dataspace"   ,-13, 08
'===========================

'action:   create an inline space for storage
'use:      
'example:  p=dataspace 1024
'          copy0 p,"This could be used as a static string buffer"
'          mbox p
'related:  data
'group:    Oxygen keywords


data "data"        ,-13, 09
'===========================

'action:   create an inline data area for constants
'use:      
'example:
'          mydata:
'          data "abc",42
'          data "def",32
'          '...
'          restore mydata
'          string s : sys a
'          read s,a : print s "  " a 
'          read s,a : print s "  " a 
'related:  restore, read
'group:    Oxygen keywords




data "o2"          ,-13, 10
'===========================

'action:   start a block of o2 machine code notation
'use:      inserting inline machine code and other binary data.
'          direct use of o2 language (used by the o2 linker)
'example:  o2 b8 00 01 00 00 'machine code for mov eax,256
'related:  asm
'group:    Oxygen keywords


data "bind"        ,-13, 12
'===========================

'action:   bind a list of procedures from a Dynamic Link Library (DLL)
'use:      for low level (without protoype) calls to DLL functions.
'          the first name is the one used in the program. The second is the name used in the DLL.
'example:
'          sys Kernel32
'          kernel32=LoadLibrary "kernel32.dll"
'
'          bind kernel32
'          (
'          GetExitCodeProcess GetExitCodeProcess           ; @8
'          ExitProcess        ExitProcess                  ; @4
'          GetCommandLine     GetCommandLineA              ; @0
'          GetModuleHandle    GetModuleHandleA             ; @4
'          QueryPerformanceCounter QueryPerformanceCounter ; @4
'          )
'result:   the first column of keywords is recognised as procedure calls. A prototype may be attached
'          to any of these keywords later. Otherwise the programmer must ensure that the parameters
'          passed are a perfect match for each procedure call.
'remarks:  Comments are supported - both semicolon and single quote marks.
'related:  loadlibrary, freelibrary, getprocaddress, declare, library
'group:    Oxygen keywords
  


data "defs"        ,-13, 14
'===========================

'action:   create an enumeration
'use:      assign a numeric identity to a name (same as enum)
'example:  
'          defs bit thing
'          (
'          Shoes,Ships, SealingWax, Cabbages, Kings
'          )
'          thing t
'          t=cabbages
'          print t
'          if t=cabbages then print "Cabbages!"
'
'related:  enum, def, #define, (%), typedef enum
'group:    Oxygen keywords



data "def"         ,-13, 15
data "#def"        ,-13, 15
'===========================

'action:   define a low level macro
'use:      
'example: 
'          'DEFINE MACRO:
'
'          def Create
'            dim as %1 %2
'            %2.new("%2")
'          end def
'
'          'INVOKE MACRO
'
'          create SomeClass SomeObject
'          
'          'EXPANDS TO:
'
'          dim as SomeClass SomeObject
'          SomeObject.new("SomeObject")
'
'remarks:  def and #def are the same
'related:  macro, #define, defs
'group:    Oxygen keywords



data "type"        ,-13, 16
'===========================

'action:   define a compound variable type
'use:      
'example:
'          type rgbacolor
'            red   as byte
'            green as byte
'            blue  as byte
'            alpha as byte
'          end type
'
'          rgbacolor c
'          c.red=100 : c.green=50 : c.blue=100
'
'related:  typedef, struct, class
'group:    Oxygen keywords
 


data "struct"      ,-13, 16
'===========================

'action:   define a compound variable type (C Syntax)
'use:      
'example:  
'          struct rgbacolor
'          {
'            red   as byte
'            green as byte
'            blue  as byte
'            alpha as byte
'          }
'related:  type, typedef, class
'group:    Oxygen keywords



data "class"       ,-13, 16
'===========================

'action:   define a class (strucure and methods for objects)
'use:      
'example:
'          'DEFINE CLASS
'          '  
'          class rgbacolor
'            red   as byte
'            green as byte
'            blue  as byte
'            alpha as byte
'            '
'            method in(sys r, sys g, sys b, sys a)
'              red=r : green=g : blue=b : alpha=a
'            end method
'            '
'          end class
'
'          'INSTANTIATE
'
'          dim as rgbaColor c
'
'          'INVOKE METHOD
'          '
'          c.in(100,200,100,128)
'
'related:  type, typedef, struct
'group:    Oxygen keywords



data "var"         ,-13, 17
'===========================

'action:   define a set of variables
'use:      
'example:  var string s,t,u(64),v  
'related:  dim
'group:    Oxygen keywords



data "include"     ,-13, 18
data "#include"    ,-13, 18
'===========================

'action:   include source code from another file
'use:      used for including header files and other units of source code
'example:  #include "rtl32.inc"
'remarks:  include and #include are the same
'related:  includepath
'group:    Oxygen keywords




data "asm"         ,-13, 19
data "#asm"        ,-13, 19
'===========================

'group:    directives
'action:   switch to assembly code mode (excludes BASIC keywords)
'use:      used when scripting a section of assembly code only.
'example:  asm
'remarks:  asm and #asm are the same.
'          
'          if the script also uses basic, it must end with then "basic" instruction
'          to generate the Basic intialisation and termination code blocks
'related:  basic, o2h
'group:    Oxygen keywords



data "o2h"         ,-13, 20
data "#o2h"        ,-13, 20
data "basic"       ,-13, 20
data "#basic"      ,-13, 20
'===========================

'group:    directives
'action:   switch to BASIC mode
'use:      enable support for BASIC and other high level scripting
'example:  basic
'remarks:  o2h #o2h basic and #basic are the same.
'related:  asm
'group:    Oxygen keywords



data "exposed"     ,-13, 21
'===========================
'action:   exposes the next label to the outside of the current scope
'use:      supports low level (non-OOP) encapsulation
'example:  (
'            exposed function f() as sys = 42
'          )
'result:   f() is visible and can be called outside the scoping brackets.
'related:  block, scope
'group:    Oxygen keywords



data "includepath" ,-13, 30
'===========================

'action:   define a filepath for source files specified by Include.
'use:      
'example:  
'related:  include
'group:    Oxygen keywords



data "librarypath" ,-13, 31
'===========================

'action:   define a filepath for DLL files
'use:      tells the computer where to find Dynamic Link Libraries
'          required to run the program. (System DLLs  do not require this.)
'example:  
'related:  library, extern, includepath
'group:    Oxygen keywords


data "#o2path"    ,-13, 32
'===========================

'action:   define a filepaths for Oxygen.dll (or hosted dll)
'use:      tells the computer where to find Oxygen
'          required to run the program. ('Independent' mode programs do not require this.)
'example:  
'         #o2paths "
'           `.\thinBasic_oxygen.dll`? `lib\thinBasic_oxygen.dll`?
'           `..\thinBasic_Oxygen.dll`?
'           `..\lib\thinBasic_Oxygen.dll`? 
'           `\thinbasic\lib\thinBasic_Oxygen.dll`?
'           `c:\thinbasic\lib\thinBasic_Oxygen.dll`? "
'
'
'related:   #file
'group:    Oxygen keywords



data "#file"       ,-13, 35
'===========================

'action:   specifiy a filename for compiled code ( .EXE or .DLL )
'use:      creates an executable ".EXE" or  Dynamic Link Library ".DLL" file
'example:  #file "4PortViewer.exe"
'related:  o2paths
'group:    Oxygen keywords



data "quote"       ,-13, 36
'===========================

'action:   specify tagname for superquotes
'use:      supports almost unlimited nesting of quotes. Can be used for containg
'          embedded scripts which themselves use quotes and have different syntax.
'example:  quote !!! this quote contains other quotes "containing `other quotes`   " !!!
'related:  ("), (`)
'group:    Oxygen keywords


data "typedef"     ,-13, 37
'===========================

'action:   define a set of types (C syntax)
'use:      create type definitions for creating other types
'example:
'          typedef Double *pDouble
'example:  
'
'          'CREATE TYPES FROM ANONYMOUS STRUCT
'
'          typedef struct
'           {
'             single x;
'             single y;
'             single z;
'           } vector, *pVector;
'
'           'CREATE VARIABLE
'
'           vector v;
'
'           v.x=42.01
'
'example:   'from winbase.h
'           typedef struct _OVERLAPPED {
'               ULONG_PTR Internal;
'               ULONG_PTR InternalHigh;
'               union {
'                   struct {
'                       DWORD Offset;
'                       DWORD OffsetHigh;
'                   };
'
'                   PVOID Pointer;
'               };
'
'               HANDLE  hEvent;
'           } OVERLAPPED, *LPOVERLAPPED;
'
'related:  type, struct, class, union, enum
'group:    Oxygen keywords





data "union"       ,-13, 38
'===========================

'action:   define a union (C syntax)
'use:      allows different variables to occupy the same space.
'example:  
'          union utype
'          {
'            byte  b
'            short w
'            long  i
'          }
'
'
'          utype v
'
'          v.b=42
'result:   v.b=42 : v.w=42 : v.i=42
'remarks:  a union may also be nested inside a type.
'related:  typedef, type, struct, class, enum
'group:    Oxygen keywords



data "restore"       ,-13, 39
'============================

'action:   set a data point to read data from
'use:      Allow reading from different series of data
'example:  see 'data'
'related:  data, read
'group:    Oxygen keywords



data "read"       ,-13, 40
'=========================

'action:   read series of data statements into variables
'use:      reading sets numerical and string data into variable for lookup or initialisation.
'example:  see 'data'
'related:  data, restore
'group:    Oxygen keywords



data "#case"       ,-13, 41
'===========================

'action:   specify mode of case sensitivity.
'use:      case can be 'sensitive' insensitive' or 'capital'
example:   
'          #case insensitive 'AbC is the same as 'aBC' and 'ABC'
'          #case sensitive   'AbC and 'abc' are not the same
'          #case capital     'AbC is the same as 'aBC' but not 'ABC'
'remarks:  The default is 'insensitive'.
'          #case has block scope and reverts to its previous state when
'          the block ends.
'related:  
'group:    Oxygen keywords: directives



data "leaf"        ,-13, 42
'==========================

'action:   reduces prolog and epilog code in procedures
'use:      to reduce unnecessary code and thus improve execution time.
'example:  leaf function(sys a, sys b) as sys '...
'remarks:  this is mostly applicable in 64 bit programming
'related:  external, export
'group:    Oxygen keywords: directives



data "#lookahead"  ,-13, 43
'==========================

'action:   internally creates header declarations for all procedures.
'use:      allows procedure calls to forward reference
'example:  #lookahead
'          f "ok"
'          '...
'          sub f(s as string)
'            print s
'          end sub
'
'remarks:  procedures in inner blocks are ignored, so each block must
'          have its own '#lookahead'
'related:  scope
'group:    Oxygen keywords: directives




data "#autodim"    ,-13, 44
'==========================

'action:   enable variables to be created without a Dim statement
'use:      switch off this mode for stricter compiling!
'example:  #autodim off
'remarks:  this mode is normally active.
'related:  
'group:    Oxygen keywords: directives



data "#minormajor" ,-13, 45
'==========================

'action:   switch minor to major simensional order in arrays
'use:      change from the C standard array[major,..,minor] to 
'          array[minor,...,major]
'example:  #minormajor on
'remarks:  The default is 'off' so that the most significant indices come first
'related:  
'group:    Oxygen keywords: directives



data "#alert"       ,-13, 46
'===========================

'action:   generates a compiler message (like an error)
'use:      used to alert programmer about an area of code
'          that requires attention
'example:  #alert (please implement methods for this interface)
'related:  #error
'group:    Oxygen keywords: directives



data "#error"       ,-13, 47
'===========================

'action:   generates a compiler error message
'use:      used to alert programmer about inconsistencies
'          that require attention.
'example:  #error (please implement methods for this interface)
'related:  #alert
'group:    Oxygen keywords: directives



data "#pragma"     ,-13, 48
'===========================

'action:   ignored (C style compiler directives)
'use:      compilers use it for platform or compiler-specific mode changes
'example:  #pragma warning(push)
'related:  
'group:    Oxygen keywords: directives

data "#unique"     ,-13, 49
'===========================

'group:    directives
'action:   flags an error if a a symbol definition is not unique (in the same nesting level)
'use:      prevent symbols from being redefined
'example:  #unique enabled
'          #unique disabled 'default
'group:    Oxygen keywords: directives



'===========================
'>>O2H KEYWORDS
'===========================



data "enum"        ,-14, 01
'===========================

'action:   defines an enumeration structure (C syntax)
'use:      
'example:  see 'defs'
'related:  defs, typedef enum
'group:    Oxygen Basic structures



data "operator"    ,-14, 03
'===========================

'action:   define a new operator
'use:      
'example:  
'related:  operation, operations
'group:    Oxygen Basic keywords



data "dim"         ,-14, 04
'===========================

'action:   define a set of variables
'use:      
'example:  dim as string s="Hello World"
'related:  var
'group:    Oxygen Basic keywords



data "const"       ,-14, 04
'===========================

'action:   define a set of constants
'use:      
'example:  const as string s="HelloWorld"
'related:  dim, #define
'group:    Oxygen Basic keywords



data "local"       ,-14, 05
'===========================

'action:   define a local set of variables
'use:      
'example:  
'related:  global, static
'group:    Oxygen Basic keywords



data "static"      ,-14, 06
'===========================

'action:   define a static set of variables, (persistant but invisible outsid the block)
'use:      
'example:  
'related:  global, local
'group:    Oxygen Basic keywords



data "global"      ,-14, 07
'===========================

'action:   define a set of variable that are visible throughout the program
'use:      
'example:  
'related:  static, local
'group:    Oxygen Basic keywords



data "declare"     ,-14, 08
'===========================

'action:   declare a procedure with its prototype (may be external or declared in advance)
'use:      
'example:  
'related:  library, lib, alias
'group:    Oxygen Basic keywords



data "function"    ,-14, 09
'===========================

'action:   define a function
'use:      
'example:  
'related:  sub, method, operation
'group:    Oxygen Basic keywords: procedures



data "sub"         ,-14, 10
'===========================

'action:   define a sub. (like a function but not returning a value)
'use:      
'example:  
'related:  function, method, operation
'group:    Oxygen Basic keywords: procedures



data "method"      ,-14, 11
'===========================

'action:   define a method. (a function or sub for objects)
'use:      
'example:  
'related:  function, sub, operation
'group:    Oxygen Basic keywords: procedures



data "end"         ,-14, 12
'===========================

'action:   marks the end of a code block
'use:      
'example:  if a>b then
'            b=a
'          end if
'related:  { .. }
'group:    Oxygen Basic keywords



data "if"          ,-14, 13
'===========================

'action:   start a conditional block with a test
'use:      
'example:  
'related:  then, else, elseif, endif, while
'group:    Oxygen Basic: control structures



data "then"        ,-14, 14
'===========================

'action:   starts the conditional block where the prior test is met.
'use:      
'example:  if a>b then print a
'related:  if, elseif, endif
'group:    Oxygen Basic: control structures



data "else"        ,-14, 15
'===========================

'action:   starts the alternative block where none of the prior conditions are met
'use:      
'example:  if a>b then print a else print b 
'related:  if, elseif, endif
'group:    Oxygen Basic: control structures



data "elseif"      ,-14, 16
'===========================
'action:   make an alternative test if the previous condition was not met.
'use:      
'example:  
'related:  if, else, endif
'group:    Oxygen Basic: control structures



data "endif"       ,-14, 17
'===========================
'same:     "end if"
'action:   end the conditional block
'use:      
'example:  
'related:  if, then, elseif, else, end if
'group:    Oxygen Basic: control structures




data "endsel"      ,-14, 20 'ALSO: "END SELECT"
'===========================

'action:   end the select block
'use:      
'example:  
'related:  select, case
'group:    Oxygen Basic: control structures



data "do"          ,-14, 21
'===========================

'action:   start a block for repetition (looping)
'use:      
'example:  
'          a=0
'          do
'            '...
'            a+=1 : if a=4 then exit do
'          end do
'result:   a=4 '4 loops
'related:  while, continue do , exit do, enddo, end do
'group:    Oxygen Basic: control structures



data "while"       ,-14, 23
'===========================

'action:   start a block for conditional repetition
'use:      
'example:  
'          a=0
'          while a<4
'            a+=1
'          wend
'result:   a=4 '4 loops
'related:  do, continue do , exit do, wend, enddo, exit do
'group:    Oxygen Basic: control structures



data "enddo"       ,-14, 18
data "endwhile"    ,-14, 19
data "wend"        ,-14, 24 ' (NO `LOOP` KEYWORD)
'===========================
'same:     "end do"
'same:     "end while"
'action:   end a block with conditional repetition (while..)
'use:      see: "while"
'related:  while, do, continue do , exit do
'group:    Oxygen Basic: control structures



data "exit"        ,-14, 25
'===========================

'action:   exit a Do or While block immediately
'use:      leave a loop after a condition has been met
'example:  
'          a=0 : b=1
'          do
'            a+=1
'            if a>4 then exit do
'            b+=b
'          end do
'result:   a=5 : b=16
'related:  do, while, continue do , exit do
'group:    Oxygen Basic: control structures



data "continue"    ,-14, 26
'===========================

'action:   go back to the beginning of a Do or While block
'use:      "short circuit" a loop
'example:
'related:  do, while, exit do, wend, enddo
'group:    Oxygen Basic: control structures



data "operation"   ,-14, 27
'===========================

'action:   define an operation (procedure defining an operator associated with a variable Type )
'use:      
'example:  
'related:  function, method, sub
'group:    Oxygen Basic: control structures



data "operations"  ,-14, 28
'===========================

'action:   define a operations block containing a set of operations associated with a variable type.
'use:      
'example:  
'related:  operation
'group:    Oxygen Basic: structures



data "select"      ,-14, 29
'===========================

'action:   Start a Case block
'use:      
'example:  
'related:  case, endsel, end select
'group:    Oxygen Basic: control structures



data "case"        ,-14, 30
'===========================

'action:   specify a case to match followed by actions to perform
'use:      
'example:  
'related:  select, endsel, end select
'group:    Oxygen Basic: control structures



data "for"         ,-14, 31
'===========================

'action:   start an iteration block
'use:      
'example:  
'related:  to, step, next
'group:    Oxygen Basic: control structures



data "to"          ,-14, 32
'===========================

'action:   specify limit of an iteration
'use:      
'example:  
'related:  for, step, next
'group:    Oxygen Basic: control structures



data "step"        ,-14, 33
'===========================

'action:   specify increment of an iteration
'use:      for iterator = start to end step step increment
'example:  for i=1 to 10 step 2 : ... : next
'result:   i increeases by 2 with each cycle : 1 3 5 7 9
'comments: step can be omitted, a step of 1 is then assumed.
'          a negative step can also be used for down counting.
'related:  for, to, next
'group:    Oxygen Basic: control structures



data "next"        ,-14, 34
'===========================

'action:   end iteration block
'use:      
'example:  
'related:  for, to, step
'group:    Oxygen Basic: control structures



data "goto"        ,-14, 35
'===========================

'action:   jump to a specified label in the code
'use:      
'example:  
'related:  jmp, jmp fwd, gosub
'group:    Oxygen Basic: control structures



data "gosub"       ,-14, 36
'===========================

'action:   call a labelled subroutine
'use:      
'example:  
'related:  call
'group:    Oxygen Basic: procedures



data "methods"     ,-14, 37
'===========================

'action:   start a methods block for a class of objects.
'use:      
'example:  
'related:  method, class
'group:    procedures block
'group:    Oxygen Basic: structures




data "return"      ,-14, 38
'===========================

'action:   exit from a procedure returning a value (in a function or method)
'use:      
'example:  
'related:  ret
'group:    Oxygen Basic: procedures



data "%"           ,-14, 39 ' QB style equate
data "$"           ,-14, 39 ' QB style equate
'===========================

'action:   define an equate (which can be used as constants)
'use:      
'example:  
'related:  #define. #def. def
'group:    Oxygen Basic: constants




data "block"       ,-14, 41
'===========================

'action:   sart a block
'use:      
'example:  
'related:  scope
'group:    code blocks
'group:    Oxygen Basic: code structures



data "scope"        ,-14, 42
'===========================
'action:   start a scope
'use:      
'example:  
'group:    Oxygen Basic: code structures



data "indexbase"    ,-14, 44
'===========================

'action:   define the index base for an array (first element usually 0 or 1)
'use:      
'example:  
'related:  dim
'group:    Oxygen Basic: directives



data "lib"         ,-14, 45
data "library"     ,-14, 45
'===========================

'action:   specify the name of a DLL library to associate with a set of procedure declarations
'use:      
'example:  lib "kernel32.dll"
'related:  declare
'group:    Oxygen Basic: directives



data "loadlibs"    ,-14, 46
'===========================

'action:   start a set of late binding declarations
'use:      
'example:  loadlibs
'related:  linklibs, declare
'group:    Oxygen Basic: linkage



data "linklibs"    ,-14, 47
'===========================

'action:   terminate a list of late binding declarations and link them
'use:      
'example:  linklibs
'related:  loadlibs, declare
'group:    Oxygen Basic: linkage



data "extern"      ,-14, 48
'===========================

'action:   associate declared procedures with a calling convention and/or dll name
'use:      
'example:  
'          extern stdcall lib "kernel32.dll"
'            declare function QueryPerformanceCounter(lpPerformanceCount as quad) as sys
'            declare function QueryPerformanceFrequency(lpPerformanceFrequency as quad) as sys
'          end extern
'remarks:  note ther is no need to use an Alias in these declarations if you give the exact name
'          of the procedures in their original case.
'related:  lib, stdcall, cdecl, pascal, ms64, library
'group:    Oxygen Basic: linkage



data "#fpu"        ,-14, 51
'===========================

'action:   directive to favour operations to be performed in the Floating Poit Unit
'use:      
'example:  
'related:  #cpu, #noprec
'group:    Oxygen Basic: directives



data "#cpu"        ,-14, 52
'===========================

'action:   directive to favour operations to be performed in the Central Processing Unit.
'use:      
'example:  
'related:  #fpu, #noprec
'group:    Oxygen Basic: directives



data "#noprec"     ,-14, 53
'===========================

'action:   directive to evaluate an expression from left to right, ignoring standard operator precedence rules.
'use:      
'example:  
'related:  #cpu, #fpu
'group:    Oxygen Basic: directives



data "#noinit"     ,-14, 54
'===========================

'action:   prevent variables from being automatically initialised to nul within a procedure
'use:      
'example:  
'related:  
'group:    Oxygen Basic: directives



data "#byval"      ,-14, 55
'===========================

'action:   pass parameter by value (not by its address)
'use:      
'example:  
'related:  #byref
'group:    Oxygen Basic: directives



data "#byref"      ,-14, 56
'===========================

'action:   pass parameter using its address instead of its value
'use:      
'example:  
'related:  #byval
'group:    Oxygen Basic: directives



data "readstate"        ,-14, 57
'===============================

'action:   read state records into compiler's state buffer.
'use:      
'example:
'related:  writestate 
'group:    Oxygen Basic: dynamic compiling



data "writestate"        ,-14, 58
'================================

'action:   write state records from compiler's state buffer.
'use:      
'example:  
'related:  readstate
'group:    Oxygen Basic: dynamic compiling



'===========================
'METACOMMANDS
'#if #elseif #endif #ifdef #ifndef
'===========================


data "#if"         ,-13, 100
'===========================

'action:   include block of code if conditions are met
'use:      
'example:  
'related:  #else, #elseif, #elif, #endif, #fi
'group:    meta control



data "#else"       ,-13, 101
'===========================

'action:   alternative block of code to include if prior conditions are not met.
'use:      
'example:  
'related:  #if, #elseif, #elif, #endif, #fi
'group:    meta control



data "#elseif"     ,-13, 102
data "#elif"       ,-13, 102
'===========================

'action:   include block of code if these alternative conditions are met
'use:      
'example:  
'related:  #if, #else, #endif, #fi
'group:    meta control



data "#endif"      ,-13, 103
data "#fi"         ,-13, 103
'===========================

'action:   end of conditional code inclusion block
'use:      
'example:  
'related:  #if, #elseif, #elif
'group:    meta control



data "#define"     ,-13, 104
'===========================

'action:   define a macro (C syntax)
'use:      
'example:  
'group:    macro



data "#ifdef"      ,-13, 105
data "#ifndef"     ,-13, 106
'===========================

'action:   include code if symbol already defined
'use:      to allow blocks of code to be included or omitted at compile time
'example:  #ifdef MSWIN
'            #include "windows.inc"
'          #endif
'related:  #if, #elseif, #elif, #endif
'group:    meta control



data "#undef"      ,-13, 107
data "#undefine"   ,-13, 107
'===========================

'action:   remove a previously defined symbol
'use:      #undefine name
'example:  
'related:  #define, def, dim
'group:    macro



data "alias"       ,-13, 108 'thinBasic headers
'===========================

'action:   define another name for a name
'use:      alias original as newname
'example:  alias single as glFloat
'          dim as glFloat x,y,z
'related:  typedef
'group:    Oxygen Basic: linkage



data "macro"       ,-13, 109
'===========================

'action:   define a high level macro
'use:      many uses. Often a pseudo function for producing
'          inline code instead of a call
'example:  macro message(title,text) ( messagebox (0,text,title,0) )
'          message "Greeting","Hello!"
'related:  #define, #def, def
'group:    Oxygen Basic macro





'===========================




'================================
'C style primitives
'================================



data "void"        ,-15, 11, 0
data "byte"        ,-15, 12, &h21
data "astring"     ,-15, 14, &he1
data "pstring"     ,-15, 14, &he1
data "bstring"     ,-15, 15, &hc1
data "char"        ,-15, 13, &ha1
data "zstring"     ,-15, 16, &ha1
data "asciiz"      ,-15, 16, &ha1
data "short"       ,-15, 17, 2
data "long"        ,-15, 18, 4
data "int"         ,-15, 19, 4
data "integer"     ,-15, 20, 4
data "float"       ,-15, 21, &h64
data "single"      ,-15, 22, &h64
data "double"      ,-15, 23, &h68
data "quad"        ,-15, 24, 8
data "word"        ,-15, 25, &h22
data "dword"       ,-15, 26, &h24
data "qword"       ,-15, 27, &h28
data "uint"        ,-15, 28, &h24
data "__int8"      ,-15, 30, 1
data "__int16"     ,-15, 31, 2
data "__int32"     ,-15, 32, 4
data "__int64"     ,-15, 33, 8
data "int8_t"      ,-15, 34, 1
data "int16_t"     ,-15, 35, 2
data "int32_t"     ,-15, 36, 4
data "int64_t"     ,-15, 37, 8
data "uint8_t"     ,-15, 38, &h21
data "uint16_t"    ,-15, 39, &h22
data "uint32_t"    ,-15, 40, &h24
data "uint64_t"    ,-15, 41, &h28
data "any"         ,-15, 42, &h08
data "sys"          ,-15, 42, &h08
data "bool"         ,-15, 42, &h08
'============================
'group:    primitive types
'incfile:  types.txt
'groupref: types




data "signed"      ,-15, 64, 4
'===========================

'action:   specifies the type to be of signed integer
'use:      signed type variable
'example:  signed int v
'result:   a nsigned int (long) called v is created.
'group:    primitive types



data "unsigned"    ,-15, 65, &h24
'===========================

'action:   specifies the type to be of positive numbers only
'use:      unsigned type variable
'example:  unsigned long v
'result:   an unsigned long (dword) called v is created.
'group:    primitive types






'===========================
'>>OVERLOADABLE INTEGER AND STRING FUNCTIONS
' overloadable functions -16
' integer and string
' TREATED AS STDCALL
'===========================



data "news"    ,-16, "##sys@a0 sys 08"
'===================

'action:   allocates a bstring of null characters given the length in bytes
'use:      bstring=news length
'example:  b=news 1000 : ... : frees b
'result:   b contains address of a string of 1000 nul characters . Then the sting is freed
'remarks:  Oxygen strings are automatically freed but Bstrings must be explicitly freed when no longer needed.
'related:  frees nuls space string
'group:    memory functions



data "frees"   ,-16, " ##bstring#@a0 sys 16 ##sys@a0 sys 16"
'===================

'action:   deallocates a bstring
'use:      frees bstring
'example:  b=news 1000 : frees b
'result:   b contains address of a string of 1000 nul characters . Then the sting is freed
'remarks:  Oxygen strings are automatically freed but Bstrings must be explicitly freed when no longer needed.
'related:  news
'group:    memory functions



data "error"   ,-16, "##@ bstr 128"
'===================

'action:   returns a string containing the most recent compile or runtime errors (cleared at start of compiling)
'use:      string=error
'example:  if error then print error
'result:   displays the las error, if it exists.
'related:  #error #alert
'group:    string functions



data "nuls"    ,-16, "##sys@a0 bstr 08"
'===================

'action:   returns the address of a string of null characters given the length.
'use:      string=nuls length
'example:  s=nuls 1000
'result:   s is a string of 1000 null characters
'related:  space string news frees
'group:    string functions



data "compile" ,-16, "##string@a0 sys 120"
'===================

'action:   compiles a string of source code and return address of executable machine code (which cn be called)
'use:      c=compile sourceString : call c
'example:  c=compile "basic : print `Hello` " : call c
'result:   when c is called `Hello` is displayed
'remarks:  If the compiling fails then error() will return a description of the problem.
'          The code has access to the parental local and static variables as well as globals.
'          When no longer used the code string should be deallocated by calling Frees c.
'related:  frees
'group:    string functions


data "val"     ,-16, "##string@a0 double 192 ##astring@a0 double 192"
'===================

'action:   returns numeric value of string
'use:      value=val string
'example:  v=val "2.5"
'result:   v=2.5
'relateds: str hex asc
'group:    string functions


data "ltrim"   ,-16, "##string@a0 bstr 2312"
'===================

'action:   returns string with white space on the left trimmed off
'use:      string=rtrim(string)
'example:  s=ltrim "   abc"
'result:   s="abc"
'related:  rtrim space
'group:    string functions



data "rtrim"   ,-16, "##string@a0 bstr 2320"
'===================

'action:   returns string with white space on the right trimmed off
'use:      string=rtrim(string)
'example:  s=rtrim "abc   "
'result:   s="abc"
'related:  ltrim space
'group:    string functions



data "lcase"   ,-16, "##string@a0 bstr 2328"
'===================

'action:   returns lowercase of string
'use:      string=lcase(string)
'example:  s=lcase "ABCDEF"
'result:   s="abcdef"
'related:  ucase ltrim rtrim asc
'group:    string functions



data "ucase"   ,-16, "##string@a0 bstr 2336"
'===================

'action:   returns uppercase of string
'use:      string=ucase(string)
'example:  s=ucase "abcdef"
'result:   s="ABCDEF"
'related:  lcase ltrim rtrim asc
'group:    string functions



data "string"  ,-16, "##sys#sys@a0a0 bstr 2464 ##sys#zstring@a0a0 bstr 2472 ##sys#string@a0a0 bstr 2480"
'===================

'action:   returns a string of characters
'use:      string=string(length,character)
'example:  string=string(4,"a")
'result:   s="aaaa"
'related:  space nuls asc
'group:    string functions



data "space"   ,-16, "##sys@a0 bstr 2488"
'===================

'action:   returns a string of spaces
'use:      string=space length
'example:  s=space 10
'result:   s="          " ' 10 spaces (ascii 32)
'related:  nuls string ltrim rtrim
'group:    string functions



data "left"    ,-16, "##string#sys@a0a0 bstr 2344 ##zstring#sys@a0a0 bstr 2400"
'===================

'action:   returns left part of a string by length
'use:      string=left string1,length
'example:  s=left "abcdef",3
'result:   s="abc"
'related:  mid ltrim rtrim
'group:    string functions



data "mid"     ,-16, "##string#sys#sys@a0a0a0 bstr 2360 ##zstring#sys#sys@a0a0a0 bstr 2392 "+_
                     "##string#sys@a0a0 bstr 2416 ##zstring#sys@a0a0 bstr 2424 "+_
                     "##sys#sys#sys@a0a0a0 bstr 2360 ##sys#sys@a0a0 bstr 2416"
'===================

'name:     mid
'action:   returns part of string1 at position with length
'use:      string=mid string1, position, length 'if length is omitted then the rest of string1 is returned
'example:  s=mid "abcdef",3 : t=mid "abcdef",3,2
'result:   s="cdef" : t="cd"
'remarks:  also works with untyped pointers
'related:   left ltrim rtrim instr _mid
'group:    string functions



data "_mid"    ,-16, "##string#sys#string@a1a0a0 sys 2456 "
'===================

'name:     mid
'action:   patches string2 into string1 as position
'use:      mid(string1,position)=string2 : mid string1,position,string2
'example:  s="abcdef" : mid s,2,"BC"
'result:   s="aBCdef"
'related:  mid left ltrim rtrim
'group:    string command



data "instr"   ,-16, "##sys#sys@a0a0 sys 2504 ##sys#sys#sys@a0a0a0 sys 320 "+_
                     "##string#string@a0a0 sys 2504 ##sys#string#string@a0a0a0 sys 320 "
'===================

'action:   returns position of String2 within string1 searching from start position
'use:      location=instr(string1,string2) : location=instr(start,string1,string2)
'example:  p=instr("abcdef abcdef","def") : q=instr(8,"abcdef abcdef","def")
'result:   p=4 : q=11
'remarks:  also works with untyped pointers
'related:  replace mid
'group:    string functions



data "replace" ,-16, "##string#string#string@a0a0a0 bstr 328 "
'===================

'action:   returns copy of string1 where all instances of string2 is replaced by string3
'use:      string=replace(string1,string2,string3)
'example:  s=replace("abcdefabcdef", "a", " A")
'result:   s=" Abcdef Abcdef"
'related:  instr mid space
'group:    string functions



data "getfile" ,-16, "##string@a0 bstr 336 ##string#string@a0a1 sys 2512"
'===================

'action:   copies file content to a string
'use:      String=getfile FileName : getfile FileName,String
'example:  string s : getfile "t.txt",s
'result:   s contains content of "t.txt"
'related:  putfile print
'group:    string functions



data "putfile" ,-16, "##string#string@a0a0 sys 344"
'===================

'action:   saves a string to a file
'use:      putfile FileName, String
'example:  putfile "t.txt","Hello"
'result:   A file named "t.xt" is created or overwritten containing "Hello"
'related:  getfile print
'group:    string functions



data "print"   ,-16, "##string@a0 sys 2496 ##fpu@a0 sys 2520"
'===================

'action:   Displays strings and numbers
'use:      print String : print Number
'example:  print "ABC" : print 123 : print "ABC: " 123 " DEF: " 456
'result:   ABC
'          123
'          ABC: 123 DEF: 456
'remarks:  strings can be combined with numbers as sys as the first element is a string
'related:  val str hex putfile getfile
'group:    string functions



data "asc"     ,-16, "##string@a0 sys 2432 ##string#sys@a0a0 sys 2368 ##sys@a0 sys 2432 ##sys#sys@a0a0 sys 2368"
'===================

'action:   returns ascii encoding of a character in a string
'use:      AsciiCode=asc(String,CharacterPosition)
'example:  a=asc("ABCDEF",2)
'result:   a=66 'character='B'
'related:  chr val len
'group:    string functions



data "len"     ,-16, "##string@a0 sys 2376 ##sys@a0 sys 2376" 'ITR MISSING LENGTH OF Z STRING?
'===================

'action:   returns length of string
'use:      length=len(string)
'example:  v=len("Hello")
'result:   v=5
'related:  sizeof string space
'group:    string functions



data "chr"     ,-16, "##sys@a0 bstr 2384"
'===================

'action:   returns string of 1 character of ascii encoding (0..255)
'use:      string=chr(AsciiValue)
'example:  s=chr(65)
'result:   s contains "A"
'related:  asc string
'group:    string functions



data "str"     ,-16, "##fpu@a0 bstr 200 "
'===================

'action:   returns string representation of number
'use:      String=str(value)
'example:  s=str(-255.4)
'result:   s="-255.4"
'related:  hex val
'group:    string functions



data "hex"     ,-16, "##fpu@a0 bstr 208 "
'===================

'action:   returns hexadecimal string representation of integer part of number
'use:      hexString=hex(value)
'example:  s=hex(255.4)
'result:   s="FF"
'related:  str val
'group:    string functions



data "guidval"     ,-16, "##guid#bstr@a1a0 sys 352  ##guid#zstring@a1a1 sys 352"
'===================
'action:   converts guid string to guidval
'use:      COM interfaces
'example:  guid clsid
'          guidval clsid,"{96749377-3391-11D2-9EE3-00C04F797396}"
'related:  guidtxt com
'group:    string functions



data "guidtxt"     ,-16, "##guid@a1 bstr 360"
'===================
'action:   converts guid string to guidval
'use:      COM interfaces
'example:  print guidtxt(clsid)
'result:   displays: {96749377-3391-11D2-9EE3-00C04F797396}
'related:  guidval com
'group:    string functions




'===========================




'===========================
'>>FLOATING POINT MACRO
' macro function
'===========================


data "abs"      ,-17, "fabs"
'===================

'action:   returns the absolute value of a number (removes negative sign)
'use:      AbsoluteValue=abs(value)
'example:  a=abs(-2.5)
'result:   a=2.5
'related:  round frac trunc
'group:    floating point functions


data "acos"     ,-17, "fld st(0),st(0) : fmul st(0),st(0) : fld1 : fsubp st(1),st(0) : fchs : fsqrt : fxch st(1) : fpatan"
'===================

'action:   returns angle in radians given the ratio x/radius
'use:      angle=acos(YRRatio)
'example:  a=acos(0.5)
'result:   a=pi/3
'related:  cos asin atn atan
'group:    floating point functions



data "asin"     ,-17, "fld st(0),st(0) : fmul st(0),st(0) : fld1 : fsubp st(1),st(0) : fchs : fsqrt : fpatan"
'===================

'action:   returns angle in radians given the ratio y/radius
'use:      angle=asin(YRRatio)
'example:  a=asin(0.5)
'result:   a=pi/6
'related:  sin acos atn atan
'group:    floating point functions



data "atan"     ,-17, "fpatan"
'===================

'action:   returns angle in radians given the values of y and x
'use:      angle=atan(y,x)
'example:  a=atan(0.5,sqr(0.75))
'result:   a=pi/6
'related:  atn asin acos tan
'group:    floating point functions



data "atn"      ,-17, "fld1 : fpatan"
'===================

'action:   returns angle in radians given ratio y/x
'use:      angle=atn(YXRatio)
'example:  a=atn(1)*4
'result:   a=pi
'related:  atan asin acos tan
'group:    floating point functions



data "cos"      ,-17, "fcos"
'===================

'action:   returns cosine value (ratio of x/r)  given angle in radians
'use:      Cosine=cos(radians)
'example:  c=cos(pi/3)
'result:   c=0.5
'related:  sin tan
'group:    floating point functions



data "deg"      ,-17, "fldpi : fdivp st(1) : push 180 : fimul dword [esp] : add esp,4"
'===================

'action:   returns degrees from value given in radians
'use:      degrees=deg(radians)
'example:  d=deg(pi)
'result:   180
'related:  rad atan
'group:    floating point functions



data "frac"     ,-17, "sub esp,8 : fstcw [esp] : fstcw [esp+2] : or [esp],0xc00 : fldcw [esp]"+cr+_
                     "fld st(0) : frndint : fsubp st(1),st(0) : fldcw [esp+2] : add esp,8"
'===================

'action:   returns the fractional part of a value
'use:      FractionValue=frac(value)
'example:  n=frac(123.456)
'result:   n=0.456
'related:  round abs
'group:    floating point functions



data "hypot"    ,-17, "fmul st(0),st(0) : fxch st(1) : fmul st(0),st(0) : faddp st(1) : fsqrt"
'===================

'action:   returns the hypotenuse (longest side) of a right angle triangle given the other 2 sides.
'use:      hypotenuse=hypot(side1,side2)
'example:  h=hypot(3,4)
'result:   h=5
'related:  sqr pow
'group:    floating point functions



data "lin"      ,-17, "fldln2 : fxch st(1) : fyl2x"
data "log"      ,-17, "fldln2 : fxch st(1) : fyl2x"
'===================

'action:   returns the logarthm of the first value to base e (2.71828182845904523536….)
'use:      LogValue=log(Value)
'example:  a=log(10)
'result:   a=2.30258092...
'related:  lin2 log10 logn pow
'group:    floating point functions



data "log2"     ,-17, "fld1 : fxch st(1) : fyl2x"
'===================

'action:   returns the logarthm of the first value to base 2
'use:      LogValue=log2(Value)
'example:  a=log2(32)
'result:   a=5
'related:  log log10 logn pow
'group:    floating point functions


data "log10"    ,-17, "fldlg2 : fxch st(1) : fyl2x"
'===================

'action:   returns the logarthm of the first value to base 10
'use:      LogValue=log10(Value)
'example:  a=log10(100)
'result:   a=2
'group:    floating point functions



data "logn"     ,-17, "fld1 : fxch st(1) : fyl2x : fld1 : fdivrp st(1) : fxch st(1) : fyl2x"
'===================

'action:   returns the logarthm of the first value to the base of the second value.
'use:      value=logn(value1,value2)
'example:  u=logn 1000,10) : v=logn(pow(10,1.5),10)
'result:   u=3 : v=1.5
'group:    floating point functions



data "mod"      ,-17, "fxch st(1) : fprem : fstp st(1),st(0)"
'===================

'action:   returns the remainder of first value divided by the second value
'use:      modulus=mod(value1,value2)
'example:  m=mod(83.5, 10)
'result:   m=3.5
'related:  remain round trunc abs
'group:    floating point functions



data "pi"       ,-17, "fldpi"
'===================

'action:   returns pi, the ratio of the circumference of a circle to its diameter
'use:      p=pi ' or pi()
'example:  p=pi*2
'result:   p=6.283185...
'related:  tan atan
'group:    floating point functions



data "pow"      ,-17, powers
'===================

'action:   returns the value of the first value to the power of the second value
'use:      a=pow(value,exponent)
'example:  a=pow(2,3)
'result:   a=8
'remarks:  this is equivalent to 2^3
'related:  log logn
'group:    floating point functions



data "rad"      ,-17, "fldpi : fmulp st(1) : push 180 : fidiv dword [esp] : add esp,4"
'===================

'action:   returns value in radians, given degrees
'use:      radians=rad(degrees)
'example:  v=rad(180)
'result:   v=pi
'related:  deg pi
'group:    floating point functions



data "recip"    ,-17, "fld1 : fdivrp"
'===================

'action:   returns reciprocal of value: a=1/v
'use:      reciprocal=recip(value)
'example:  a=recip(5/4)
'result:   a=0.8
'related:  frac round
'group:    floating point functions


'data "remain"   ,-17, "fxch st(1) : fprem"
'===================

'action:   returns remainder of a value after division
'use:      
'example:
'related:  frac round mod  
'group:    floating point functions



data "round"    ,-17, "frndint"
'===================

'action:   returns a value rounded to the nearest whole number (rounded up or down)
'use:      WholeNumber=round(number)
'example:  m=round(1.49) : n=round(1.5)
'result:   m=1 : n=2
'related:  frac remain
'group:    floating point functions



data "sin"      ,-17, "fsin"
'===================

'action:   returns the sine of a value given in radians
'use:      Sine=sin(Radians)
'example:  v=sin(pi/6)
'result:   v=0.5
'related:  asin cos tan
'group:    floating point functions



data "sincos"   ,-17, "fsincos" ' leaves 2 results on FPU stack
'===================

'action:   
'use:      
'example:  
'related   sin cos tan
'group:    floating point functions



data "sqr"      ,-17, "fsqrt"
data "sqrt"     ,-17, "fsqrt"
'===================

'action:   returns the square root of a value
'use:      SquareRoot=sqr(value)
'example:  v=sqr(9)
'result:   3
'remarks:  sqr and sqrt are the same
'related:  pow log hypot
'group:    floating point functions



data "tan"      ,-17, "fptan : fcomp st(0),st(0)"
'===================

'action:   returns the tangent of a value given in radians
'use:      tangent=tan(radians)
'example:  t=tan(a)
'result:   t= ratio y/x
'related:  atan atn sin cos
'group:    floating point functions


data "trunc"    ,-17, "sub esp,8 : fstcw [esp] : fstcw [esp+2] : or [esp],0xc00 : fldcw [esp]"+cr+_
                     "frndint : fldcw [esp+2] : add esp,8"
'===================

'action:   truncate the fractional part of a value and return it
'use:      IntegerValue=trunc(FloatValue)
'example:  i=trunc(123.456)
'result:   i=123
'related:  round trunc
'group:    floating point functions







'===========================
'>>O2H LOW LEVEL MACROS
'===========================

data "terminate"     ,-19, "push eax : call [ebx+2448] : call [ebx+2144] : pop eax"+cr
'===================

'action:   Deallocate all Strings, static variables and free DLL libraries (at end of program).
'          This is automatically appended unless it is detected in the program.
'          It is composed of the three macros below: FreeLibs FreeStrings. If either
'          of these are used then Terminate itself will not be automatically appended.
'use:      explicit termination of program
'example:  terminate
'related:  freestrings freelibs
'group:    system macro

data "freestrings"   ,-19, "push eax : call [ebx+2144] : pop eax"
'===================

'action:   deallocate all remaining static strings only (at end of program)
'use:      allow the program to terminate without freeing libraries
'example:  freestrings
'related:  terminate freelibs
'group:    system macro


data "freelibs"      ,-19, "push eax : call [ebx+2448] : pop eax"
'===================

'action:   free all loaded DLL libraries only (at end of program)
'use:      allow the program to terminate but all static strings are retained
'example:  freelibs
'related:  terminate freestrings
'group:    system macro






'==================
'SECONDARY KEYWORDS
'==================

#if 0

'data "this" ,-99

'action:   explicitly refer to an object's own members
'use:      distinguish a member from a local variable, param or function of the same name
'example:  this.len=len(s)
'related:  method class that
'group:    secondary keyword




data "that" ,-99

'action:   suppress automatic "this" prefix inside OOP methods
'use:      resolving name conflict between an object member and another variable
'example:  this.voice=that voice
'          voice=that voice
'related:  method this
'group:    secondary keyword




data "of" ,-99

'related:  from inherits has
'group:    secondary keyword



data "from" ,-99

'related:  of inherits has
'group:    secondary keyword



data "inherits" ,-99

'related:  of from has
'group:    secondary keyword



data "has" ,-99

'related:  of from inherits
'group:    secondary keyword



data "lib" ,-99

'related: library declare extern alias
'group:    secondary keyword



data "alias" ,-99

'related: library declare extern alias
'group:    secondary keyword



data "export" ,-99

'related:  external function
'group:    secondary keyword



data "external" ,-99

'related:  export com function
'group:    secondary keyword



data "com" ,-99

'related:  external export class
'group:    secondary keyword



'---------
'OPERATORS
'=========
'
'
data "load" ,
data "=" ,
data ":=" ,
data "+" ,
data "-" ,
data "*" ,
data "/" ,
data "\" ,
data "+=" ,
data "-=" ,
data "*=" ,
data "/=" ,
data "==" ,
data "!=" , 'itr check
data "<>" ,
data "<" ,
data ">" ,
data "<=" ,
data ">" ,
data ">=" ,
data "<=" ,
data "and" ,
data "or" ,
data "xor" ,
data "and=" ,
data "or=" ,
data "xor=" ,
data "&" ,
data "|" ,
data "&=" ,
data "|=" ,
data "&&" ,
data "||" ,
data "<<" ,
data ">>" ,
'data "^^" ,'itr logical xor ??

'groupref: operators
'group:    operators




#endif


'===========================

data "" ,0,0 'mark end of data



'===========================
'end
'===========================


