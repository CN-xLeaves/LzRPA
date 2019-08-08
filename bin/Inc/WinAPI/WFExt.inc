'------------------------------------------------------------------------------
'
'  WFExt.inc -- Windows File Manager Extensions definitions (Win32 variant)
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 23 Mar 2011
'
'------------------------------------------------------------------------------
'  from wfext.h version 3.10 of 14 Jul 2009
'------------------------------------------------------------------------------


#INCLUDE THIS ONCE

%WFEXT_INC = 1

#INCLUDE "WTypes.inc"


%MENU_TEXT_LEN         = 40

%FMMENU_FIRST          = 1
%FMMENU_LAST           = 99

%FMEVENT_LOAD          = 100
%FMEVENT_UNLOAD        = 101
%FMEVENT_INITMENU      = 102
%FMEVENT_USER_REFRESH  = 103
%FMEVENT_SELCHANGE     = 104
%FMEVENT_TOOLBARLOAD   = 105
%FMEVENT_HELPSTRING    = 106
%FMEVENT_HELPMENUITEM  = 107

%FMFOCUS_DIR           = 1
%FMFOCUS_TREE          = 2
%FMFOCUS_DRIVES        = 3
%FMFOCUS_SEARCH        = 4

%FM_GETFOCUS           = %WM_USER + &H0200
%FM_GETSELCOUNT        = %WM_USER + &H0202
%FM_GETSELCOUNTLFN     = %WM_USER + &H0203   ' LFN versions are odd
%FM_REFRESH_WINDOWS    = %WM_USER + &H0206
%FM_RELOAD_EXTENSIONS  = %WM_USER + &H0207

%FM_GETDRIVEINFOA      = %WM_USER + &H0201
%FM_GETFILESELA        = %WM_USER + &H0204
%FM_GETFILESELLFNA     = %WM_USER + &H0205   ' LFN versions are odd

%FM_GETDRIVEINFOW      = %WM_USER + &H0211
%FM_GETFILESELW        = %WM_USER + &H0214
%FM_GETFILESELLFNW     = %WM_USER + &H0215   ' LFN versions are odd

#IF %DEF(%UNICODE)
%FM_GETDRIVEINFO  = %FM_GETDRIVEINFOW
%FM_GETFILESEL    = %FM_GETFILESELW
%FM_GETFILESELLFN = %FM_GETFILESELLFNW
#ELSE
%FM_GETDRIVEINFO  = %FM_GETDRIVEINFOA
%FM_GETFILESEL    = %FM_GETFILESELA
%FM_GETFILESELLFN = %FM_GETFILESELLFNA
#ENDIF


TYPE FMS_GETFILESELA
    ftTime AS FILETIME
    dwSize AS DWORD
    bAttr  AS BYTE
    szName AS ASCIIZ * 260     ' always fully qualified
END TYPE

TYPE FMS_GETFILESELW
    ftTime AS FILETIME
    dwSize AS DWORD
    bAttr  AS BYTE
    szName AS WSTRINGZ * 260   ' always fully qualified
END TYPE

#IF %DEF(%UNICODE)
TYPE FMS_GETFILESEL
    FMS_GETFILESELW
END TYPE
#ELSE
TYPE FMS_GETFILESEL
    FMS_GETFILESELA
END TYPE
#ENDIF


TYPE FMS_GETDRIVEINFOA        ' for drive
    dwTotalSpace AS DWORD
    dwFreeSpace  AS DWORD
    szPath       AS ASCIIZ * 260   ' current directory
    szVolume     AS ASCIIZ * 14    ' volume label
    szShare      AS ASCIIZ * 128   ' if this is a net drive
END TYPE

TYPE FMS_GETDRIVEINFOW        ' for drive
    dwTotalSpace AS DWORD
    dwFreeSpace  AS DWORD
    szPath       AS WSTRINGZ * 260 ' current directory
    szVolume     AS WSTRINGZ * 14  ' volume label
    szShare      AS WSTRINGZ * 128 ' if this is a net drive
END TYPE

#IF %DEF(%UNICODE)
TYPE FMS_GETDRIVEINFO
    FMS_GETDRIVEINFOW
END TYPE
#ELSE
TYPE FMS_GETDRIVEINFO
    FMS_GETDRIVEINFOA
END TYPE
#ENDIF


TYPE FMS_LOADA
    dwSize     AS DWORD                      ' for version checks
    szMenuName AS ASCIIZ * %MENU_TEXT_LEN    ' output
    hMenu      AS DWORD                      ' output
    wMenuDelta AS DWORD                      ' input
END TYPE

TYPE FMS_LOADW
    dwSize     AS DWORD                      ' for version checks
    szMenuName AS WSTRINGZ * %MENU_TEXT_LEN  ' output
    hMenu      AS DWORD                      ' output
    wMenuDelta AS DWORD                      ' input
END TYPE

#IF %DEF(%UNICODE)
TYPE FMS_LOAD
    FMS_LOADW
END TYPE
#ELSE
TYPE FMS_LOAD
    FMS_LOADA
END TYPE
#ENDIF



' Toolbar definitions

TYPE EXT_BUTTON
    idCommand AS WORD   ' menu command to trigger
    idsHelp   AS WORD   ' help string ID
    fsStyle   AS WORD   ' button style
END TYPE

TYPE FMS_TOOLBARLOAD DWORD
    dwSize    AS DWORD            ' for version checks
    lpButtons AS EXT_BUTTON PTR   ' output
    cButtons  AS WORD             ' output, 0==>no buttons
    cBitmaps  AS WORD             ' number of non-sep buttons
    idBitmap  AS WORD             ' output
    hBitmap   AS DWORD            ' output if idBitmap==0
END TYPE

TYPE FMS_HELPSTRINGA
    idCommand AS LONG           ' input, -1==>the menu was selected
    hMenu     AS DWORD          ' input, the extensions menu
    szHelp    AS ASCIIZ * 128   ' output, the help string
END TYPE

TYPE FMS_HELPSTRINGW
    idCommand AS LONG           ' input, -1==>the menu was selected
    hMenu     AS DWORD          ' input, the extensions menu
    szHelp    AS WSTRINGZ * 128 ' output, the help string
END TYPE

#IF %DEF(%UNICODE)
TYPE FMS_HELPSTRING
    FMS_HELPSTRINGW
END TYPE
#ELSE
TYPE FMS_HELPSTRING
    FMS_HELPSTRINGA
END TYPE
#ENDIF



'DECLARE FUNCTION FM_EXT_PROC (BYVAL hWnd AS DWORD, BYVAL w AS WORD, _
'    BYVAL l AS LONG) AS DWORD
'
'#IF %DEF(%UNICODE)
'DECLARE FUNCTION FM_UNDELETE_PROC (BYVAL hWnd AS DWORD, psz AS WSTRINGZ) _
'    AS DWORD
'#ELSE
'DECLARE FUNCTION FM_UNDELETE_PROC (BYVAL hWnd AS DWORD, psz AS ASCIIZ) _
'    AS DWORD
'#ENDIF
'
'
'' [unusual naming convention, but that's the way the .h file has it]
'#IF %DEF(%UNICODE)
'DECLARE FUNCTION FMExtensionProcW (BYVAL hWnd AS DWORD, BYVAL wEvent AS WORD, _
'    BYVAL lParam AS LONG) AS LONG
'#ELSE
'DECLARE FUNCTION FMExtensionProc (BYVAL hWnd AS DWORD, BYVAL wEvent AS WORD, _
'    BYVAL lParam AS LONG) AS LONG
'#ENDIF
