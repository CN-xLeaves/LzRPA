'------------------------------------------------------------------------------
'
'  WinDef.inc - Basic Windows Type Definitions
'
'  Copyright (c) 2009-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 23 Mar 2011
'
'------------------------------------------------------------------------------
'  from WinDef.h dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WINDEF = 1


' Win32 defines %WIN32 automatically,
' but Macintosh doesn't, so if we are using
' Win32 Functions, we must do it here

#IF %DEF(%MAC)
#IF NOT %DEF(%WIN32)
%WIN32 = 100
#ENDIF
#ENDIF '%MAC

#IF NOT %DEF(%WIN32)
%WIN32 = 100
#ENDIF


#IF NOT %DEF(%WINVER)
%WINVER = &H0500
#ENDIF ' WINVER

'
' BASETYPES is %DEF in ntdef.h if these types are already %DEF
'

'#IF NOT %DEF(%BASETYPES)
'%BASETYPES = 1
'typedef unsigned long ULONG;
'typedef DWORD *PULONG;
'typedef unsigned short USHORT;
'typedef WORD *PUSHORT;
'typedef unsigned char UCHAR;
'typedef UCHAR *PUCHAR;
'typedef char *PSZ;
'#endif  ' NOT BASETYPES

%MAX_PATH = 260

#IF NOT %DEF(%NULL)
%NULL = 0
#ENDIF

#IF NOT %DEF(%FALSE)
%FALSE = 0
#ENDIF

#IF NOT %DEF(%TRUE)
%TRUE = 1
#ENDIF

'typedef unsigned long       DWORD;
'typedef int                 BOOL;
'typedef unsigned char       BYTE;
'typedef unsigned short      WORD;
'typedef float               FLOAT;
'typedef FLOAT               *PFLOAT;
'typedef BOOL near           *PBOOL;
'typedef BOOL far            *LPBOOL;
'typedef BYTE near           *PBYTE;
'typedef BYTE far            *LPBYTE;
'typedef int near            *PINT;
'typedef int far             *LPINT;
'typedef WORD near           *PWORD;
'typedef WORD far            *LPWORD;
'typedef long far            *LPLONG;
'typedef DWORD near          *PDWORD;
'typedef DWORD far           *LPDWORD;
'typedef void far            *LPVOID;
'typedef CONST void far      *LPCVOID;

'typedef int                 INT;
'typedef unsigned int        UINT;
'typedef unsigned int        *PUINT;

#INCLUDE "WinNT.inc"


' Types use for passing & returning polymorphic values
'typedef UINT_PTR            WPARAM;
'typedef LONG_PTR            LPARAM;
'typedef LONG_PTR            LRESULT;

'#define MAKEWORD(a, b)      ((WORD)(((BYTE)(((DWORD_PTR)(a)) & &Hff)) | ((WORD)((BYTE)(((DWORD_PTR)(b)) & &Hff))) << 8))
'#define MAKELONG(a, b)      ((LONG)(((WORD)(((DWORD_PTR)(a)) & &Hffff)) | ((DWORD)((WORD)(((DWORD_PTR)(b)) & &Hffff))) << 16))
'#define LOWORD(l)           ((WORD)(((DWORD_PTR)(l)) & &Hffff))
'#define HIWORD(l)           ((WORD)((((DWORD_PTR)(l)) >> 16) & &Hffff))
'#define LOBYTE(w)           ((BYTE)(((DWORD_PTR)(w)) & &Hff))
'#define HIBYTE(w)           ((BYTE)((((DWORD_PTR)(w)) >> 8) & &Hff))


'typedef WORD                ATOM;

'typedef DWORD NEAR         *SPHANDLE;
'typedef DWORD FAR          *LPHANDLE;
'typedef DWORD              HGLOBAL;
'typedef DWORD              HLOCAL;
'typedef DWORD              GLOBALHANDLE;
'typedef DWORD              LOCALHANDLE;

'DECLARE_HANDLE(HGDIOBJ);

'DECLARE_HANDLE(HKEY);
'typedef HKEY *PHKEY;

'#if NOT %DEF(%MAC) OR NOT %DEF(WIN_INTERNAL)
'DECLARE_HANDLE(HACCEL);
'#endif
'#if NOT %DEF(%MAC) OR NOT %DEF(GDI_INTERNAL)
'DECLARE_HANDLE(HBITMAP);
'DECLARE_HANDLE(HBRUSH);
'#endif
'#if(WINVER >= &H0400)
'DECLARE_HANDLE(HCOLORSPACE);
'#endif ' WINVER >= &H0400
'#if NOT %DEF(%MAC) OR NOT %DEF(GDI_INTERNAL)
'DECLARE_HANDLE(HDC);
'#endif
'DECLARE_HANDLE(HGLRC);          ' OpenGL
'DECLARE_HANDLE(HDESK);
'DECLARE_HANDLE(HENHMETAFILE);
'#if NOT %DEF(%MAC) OR NOT %DEF(GDI_INTERNAL)
'DECLARE_HANDLE(HFONT);
'#endif
'DECLARE_HANDLE(HICON);
'#if NOT %DEF(%MAC) OR NOT %DEF(WIN_INTERNAL)
'DECLARE_HANDLE(HMENU);
'#endif
'DECLARE_HANDLE(HMETAFILE);
'DECLARE_HANDLE(HINSTANCE);
'typedef HINSTANCE HMODULE;      ' HMODULEs can be used in place of HINSTANCEs
'#if NOT %DEF(%MAC) OR NOT %DEF(GDI_INTERNAL)
'DECLARE_HANDLE(HPALETTE);
'DECLARE_HANDLE(HPEN);
'#endif
'DECLARE_HANDLE(HRGN);
'DECLARE_HANDLE(HRSRC);
'DECLARE_HANDLE(HSPRITE);
'DECLARE_HANDLE(HLSURF);
'DECLARE_HANDLE(HSTR);
'DECLARE_HANDLE(HTASK);
'DECLARE_HANDLE(HWINSTA);
'DECLARE_HANDLE(HKL);
'
'#if(WINVER >= &H0400)
'DECLARE_HANDLE(HWINEVENTHOOK);
'#endif ' WINVER >= &H0400
'
'#if(WINVER >= &H0500)
'#IF NOT %DEF(%MAC
'DECLARE_HANDLE(HMONITOR);
'#endif
'DECLARE_HANDLE(HUMPD);
'#endif ' WINVER >= &H0500
'
'#IF NOT %DEF(%MAC
'typedef int HFILE;
'typedef HICON HCURSOR;      ' HICONs & HCURSORs are polymorphic
'#else
'typedef short HFILE;
'DECLARE_HANDLE(HCURSOR);    ' HICONs & HCURSORs are not polymorphic
'#endif
'
MACRO COLORREF=DWORD

%HFILE_ERROR = -1

TYPE RECT_old
    nLeft   AS LONG
    nTop    AS LONG
    nRight  AS LONG
    nBottom AS LONG
END TYPE

TYPE RECT_new
    Left   AS LONG
    Top    AS LONG
    Right  AS LONG
    Bottom AS LONG
END TYPE

UNION RECT
    RECT_old
    RECT_new
END UNION

TYPE RECTL       ' rcl
    RECT
END TYPE


TYPE POINT
    x AS LONG
    y AS LONG
END TYPE

' [PowerBASIC legacy]
TYPE POINTAPI
    POINT
END TYPE

TYPE POINTL      ' ptl
    x AS LONG
    y AS LONG
END TYPE

TYPE SIZE
    cx AS LONG
    cy AS LONG
END TYPE

' [legacy]
TYPE apiSIZE
    SIZE
END TYPE

TYPE SIZEL
    SIZE
END TYPE


TYPE POINTS
#IF NOT %DEF(%MAC)
    x AS INTEGER
    y AS INTEGER
#ELSE
    y AS INTEGER
    x AS INTEGER
#ENDIF
END TYPE

'
'  File System time stamps are represented with the following structure:
'

#IF NOT %DEF(%FILETIME)
%FILETIME = 1

TYPE FILETIME_dword
    dwLowDateTime  AS DWORD
    dwHighDateTime AS DWORD
END TYPE

TYPE FILETIME_quad
    qDateTime      AS QUAD
END TYPE

UNION FILETIME
    FILETIME_dword
    FILETIME_quad
END UNION
#ENDIF


' mode selections for the device mode function
%DM_UPDATE           = 1
%DM_COPY             = 2
%DM_PROMPT           = 4
%DM_MODIFY           = 8

%DM_IN_BUFFER        = %DM_MODIFY
%DM_IN_PROMPT        = %DM_PROMPT
%DM_OUT_BUFFER       = %DM_COPY
%DM_OUT_DEFAULT      = %DM_UPDATE

' device capabilities indices
%DC_FIELDS           = 1
%DC_PAPERS           = 2
%DC_PAPERSIZE        = 3
%DC_MINEXTENT        = 4
%DC_MAXEXTENT        = 5
%DC_BINS             = 6
%DC_DUPLEX           = 7
%DC_SIZE             = 8
%DC_EXTRA            = 9
%DC_VERSION          = 10
%DC_DRIVER           = 11
%DC_BINNAMES         = 12
%DC_ENUMRESOLUTIONS  = 13
%DC_FILEDEPENDENCIES = 14
%DC_TRUETYPE         = 15
%DC_PAPERNAMES       = 16
%DC_ORIENTATION      = 17
%DC_COPIES           = 18
