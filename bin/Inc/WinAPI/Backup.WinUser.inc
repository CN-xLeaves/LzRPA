'------------------------------------------------------------------------------
'
'  WinUser.inc - User procedure declarations, constant definitions and macros
'
'  Copyright (c) 1997-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 30 Mar 2011
'
'------------------------------------------------------------------------------
'  from WinUser.h dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WINUSER = 1

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "WinDef.inc"

#IF NOT %DEF(%WINVER)
%WINVER = &H0500      ' version 5.0
#ENDIF ' NOT %WINVER

#IF NOT %DEF(%NOUSER)

#IF %DEF(%UNICODE)
MACRO WINSTAENUMPROC=WINSTAENUMPROCW
MACRO DESKTOPENUMPROC=DESKTOPENUMPROCW
#ELSE
MACRO WINSTAENUMPROC=WINSTAENUMPROCA
MACRO DESKTOPENUMPROC=DESKTOPENUMPROCA
#ENDIF

MACRO IS_INTRESOURCE(r)=((r) \ 65536 = 0) ' ((((ULONG_PTR)(_r)) >> 16) == 0)
MACRO MAKEINTRESOURCEA(i)=(i)  ' ((LPSTR)((ULONG_PTR)((WORD)(i))))
MACRO MAKEINTRESOURCEW(i)=(i)  ' ((LPWSTR)((ULONG_PTR)((WORD)(i))))
#IF %DEF(%UNICODE)
MACRO MAKEINTRESOURCE=MAKEINTRESOURCEW
#ELSE
MACRO MAKEINTRESOURCE=MAKEINTRESOURCEA
#ENDIF ' NOT %UNICODE

#IF NOT %DEF(%NORESOURCE)

'
' Predefined Resource Types
'
%RT_CURSOR           = 1
%RT_BITMAP           = 2
%RT_ICON             = 3
%RT_MENU             = 4
%RT_DIALOG           = 5
%RT_STRING           = 6
%RT_FONTDIR          = 7
%RT_FONT             = 8
%RT_ACCELERATOR      = 9
%RT_RCDATA           = 10
%RT_MESSAGETABLE     = 11

%DIFFERENCE     = 11
%RT_GROUP_CURSOR = %RT_CURSOR + %DIFFERENCE
%RT_GROUP_ICON   = %RT_ICON + %DIFFERENCE
%RT_VERSION      = 16
%RT_DLGINCLUDE   = 17
#IF (%WINVER >= &H0400)
%RT_PLUGPLAY     = 19
%RT_VXD          = 20
%RT_ANICURSOR    = 21
%RT_ANIICON      = 22
#ENDIF ' WINVER >= &H0400
%RT_HTML         = 23

%RT_MANIFEST                        = 24
%CREATEPROCESS_MANIFEST_RESOURCE_ID  = 1
%ISOLATIONAWARE_MANIFEST_RESOURCE_ID = 2
%ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID = 3
%MINIMUM_RESERVED_MANIFEST_RESOURCE_ID = 1   ' inclusive
%MAXIMUM_RESERVED_MANIFEST_RESOURCE_ID = 16  ' inclusive

#ENDIF ' !NORESOURCE


DECLARE FUNCTION wvsprintfA CDECL LIB "User32.dll" ALIAS "wvsprintfA" _
    (lpOutput AS ASCIIZ, lpFormat AS ASCIIZ, x AS ANY) AS LONG

DECLARE FUNCTION wvsprintfW CDECL LIB "User32.dll" ALIAS "wvsprintfW" _
    (lpOutput AS WSTRINGZ, lpFormat AS WSTRINGZ, x AS ANY) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION wvsprintf CDECL LIB "User32.dll" ALIAS "wvsprintfW" _
    (lpOutput AS WSTRINGZ, lpFormat AS WSTRINGZ, x AS ANY) AS LONG
#ELSE
DECLARE FUNCTION wvsprintf CDECL LIB "User32.dll" ALIAS "wvsprintfA" _
    (lpOutput AS ASCIIZ, lpFormat AS ASCIIZ, x AS ANY) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION wsprintfA CDECL LIB "User32.dll" ALIAS "wsprintfA" _
    (lpOutput AS ASCIIZ, lpFormat AS ASCIIZ, OPTIONAL x AS ANY, OPTIONAL x1 AS ANY, _
    OPTIONAL x2 AS ANY, OPTIONAL x3 AS ANY, OPTIONAL x4 AS ANY, OPTIONAL x5 AS ANY, _
    OPTIONAL x6 AS ANY, OPTIONAL x7 AS ANY, OPTIONAL x8 AS ANY, OPTIONAL x9 AS ANY, _
    OPTIONAL x10 AS ANY, OPTIONAL x11 AS ANY, OPTIONAL x12 AS ANY) AS LONG

DECLARE FUNCTION wsprintfW CDECL LIB "User32.dll" ALIAS "wsprintfW" _
    (lpOutput AS WSTRINGZ, lpFormat AS WSTRINGZ, OPTIONAL x AS ANY, OPTIONAL x1 AS ANY, _
    OPTIONAL x2 AS ANY, OPTIONAL x3 AS ANY, OPTIONAL x4 AS ANY, OPTIONAL x5 AS ANY, _
    OPTIONAL x6 AS ANY, OPTIONAL x7 AS ANY, OPTIONAL x8 AS ANY, OPTIONAL x9 AS ANY, _
    OPTIONAL x10 AS ANY, OPTIONAL x11 AS ANY, OPTIONAL x12 AS ANY) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION wsprintf CDECL LIB "User32.dll" ALIAS "wsprintfW" _
    (lpOutput AS WSTRINGZ, lpFormat AS WSTRINGZ, OPTIONAL x AS ANY, OPTIONAL x1 AS ANY, _
    OPTIONAL x2 AS ANY, OPTIONAL x3 AS ANY, OPTIONAL x4 AS ANY, OPTIONAL x5 AS ANY, _
    OPTIONAL x6 AS ANY, OPTIONAL x7 AS ANY, OPTIONAL x8 AS ANY, OPTIONAL x9 AS ANY, _
    OPTIONAL x10 AS ANY, OPTIONAL x11 AS ANY, OPTIONAL x12 AS ANY) AS LONG
#ELSE
DECLARE FUNCTION wsprintf CDECL LIB "User32.dll" ALIAS "wsprintfA" _
    (lpOutput AS ASCIIZ, lpFormat AS ASCIIZ, OPTIONAL x AS ANY, OPTIONAL x1 AS ANY, _
    OPTIONAL x2 AS ANY, OPTIONAL x3 AS ANY, OPTIONAL x4 AS ANY, OPTIONAL x5 AS ANY, _
    OPTIONAL x6 AS ANY, OPTIONAL x7 AS ANY, OPTIONAL x8 AS ANY, OPTIONAL x9 AS ANY, _
    OPTIONAL x10 AS ANY, OPTIONAL x11 AS ANY, OPTIONAL x12 AS ANY) AS LONG
#ENDIF ' NOT %UNICODE


'
' SPI_SETDESKWALLPAPER defined constants
'
%SETWALLPAPER_DEFAULT = &HFFFFFFFF???

#IF NOT %DEF(%NOSCROLL)

'
' Scroll Bar Constants
'
%SB_HORZ           = 0
%SB_VERT           = 1
%SB_CTL            = 2
%SB_BOTH           = 3

'
' Scroll Bar Commands
'
%SB_LINEUP         = 0
%SB_LINELEFT       = 0
%SB_LINEDOWN       = 1
%SB_LINERIGHT      = 1
%SB_PAGEUP         = 2
%SB_PAGELEFT       = 2
%SB_PAGEDOWN       = 3
%SB_PAGERIGHT      = 3
%SB_THUMBPOSITION  = 4
%SB_THUMBTRACK     = 5
%SB_TOP            = 6
%SB_LEFT           = 6
%SB_BOTTOM         = 7
%SB_RIGHT          = 7
%SB_ENDSCROLL      = 8

#ENDIF ' !NOSCROLL


#IF NOT %DEF(%NOSHOWWINDOW)

'
' ShowWindow() Commands
'
%SW_HIDE             = 0
%SW_SHOWNORMAL       = 1
%SW_NORMAL           = 1
%SW_SHOWMINIMIZED    = 2
%SW_SHOWMAXIMIZED    = 3
%SW_MAXIMIZE         = 3
%SW_SHOWNOACTIVATE   = 4
%SW_SHOW             = 5
%SW_MINIMIZE         = 6
%SW_SHOWMINNOACTIVE  = 7
%SW_SHOWNA           = 8
%SW_RESTORE          = 9
%SW_SHOWDEFAULT      = 10
%SW_FORCEMINIMIZE    = 11
%SW_MAX              = 11


'
' Old ShowWindow() Commands
'
%HIDE_WINDOW         = 0
%SHOW_OPENWINDOW     = 1
%SHOW_ICONWINDOW     = 2
%SHOW_FULLSCREEN     = 3
%SHOW_OPENNOACTIVATE = 4

'
' Identifiers for the %WM_SHOWWINDOW message
'
%SW_PARENTCLOSING    = 1
%SW_OTHERZOOM        = 2
%SW_PARENTOPENING    = 3
%SW_OTHERUNZOOM      = 4


#ENDIF ' !NOSHOWWINDOW


#IF (%WINVER >= &H0500)

'
' AnimateWindow() Commands
'
%AW_HOR_POSITIVE = &H00000001
%AW_HOR_NEGATIVE = &H00000002
%AW_VER_POSITIVE = &H00000004
%AW_VER_NEGATIVE = &H00000008
%AW_CENTER       = &H00000010
%AW_HIDE         = &H00010000
%AW_ACTIVATE     = &H00020000
%AW_SLIDE        = &H00040000
%AW_BLEND        = &H00080000

#ENDIF ' WINVER >= &H0500


'
' %WM_KEYUP/DOWN/CHAR HIWORD(lParam) flags
'
%KF_EXTENDED    = &H0100
%KF_DLGMODE     = &H0800
%KF_MENUMODE    = &H1000
%KF_ALTDOWN     = &H2000
%KF_REPEAT      = &H4000
%KF_UP          = &H8000??

#IF NOT %DEF(%NOVIRTUALKEYCODES)


'
' Virtual Keys, Standard Set
'
%VK_LBUTTON     = &H01
%VK_RBUTTON     = &H02
%VK_CANCEL      = &H03
%VK_MBUTTON     = &H04    ' NOT contiguous with L & RBUTTON

#IF (%WIN32_WINNT >= &H0500)
%VK_XBUTTON1    = &H05    ' NOT contiguous with L & RBUTTON
%VK_XBUTTON2    = &H06    ' NOT contiguous with L & RBUTTON
#ENDIF ' _WIN32_WINNT >= &H0500

'
' &H07 : unassigned
'

%VK_BACK           = &H08
%VK_TAB            = &H09

'
' &H0A - &H0B : reserved
'

%VK_CLEAR          = &H0C
%VK_RETURN         = &H0D

%VK_SHIFT          = &H10
%VK_CONTROL        = &H11
%VK_MENU           = &H12
%VK_PAUSE          = &H13
%VK_CAPITAL        = &H14

%VK_KANA           = &H15
%VK_HANGEUL        = &H15  ' old name - should be here for compatibility
%VK_HANGUL         = &H15
%VK_JUNJA          = &H17
%VK_FINAL          = &H18
%VK_HANJA          = &H19
%VK_KANJI          = &H19

%VK_ESCAPE         = &H1B

%VK_CONVERT        = &H1C
%VK_NONCONVERT     = &H1D
%VK_ACCEPT         = &H1E
%VK_MODECHANGE     = &H1F

%VK_SPACE          = &H20
%VK_PRIOR          = &H21
%VK_NEXT           = &H22
%VK_END            = &H23
%VK_HOME           = &H24
%VK_LEFT           = &H25
%VK_UP             = &H26
%VK_RIGHT          = &H27
%VK_DOWN           = &H28
%VK_SELECT         = &H29
%VK_PRINT          = &H2A
%VK_EXECUTE        = &H2B
%VK_SNAPSHOT       = &H2C
%VK_INSERT         = &H2D
%VK_DELETE         = &H2E
%VK_HELP           = &H2F

'
' VK_0 - VK_9 are the same as ASCII '0' - '9' (&H30 - &H39)

' [so let's define them]
%VK_0 = &H30
%VK_1 = &H31
%VK_2 = &H32
%VK_3 = &H33
%VK_4 = &H34
%VK_5 = &H35
%VK_6 = &H36
%VK_7 = &H37
%VK_8 = &H38
%VK_9 = &H39

' &H40 : unassigned
' VK_A - VK_Z are the same as ASCII 'A' - 'Z' (&H41 - &H5A)

' [so let's define them]
%VK_A = &H41
%VK_B = &H42
%VK_C = &H43
%VK_D = &H44
%VK_E = &H45
%VK_F = &H46
%VK_G = &H47
%VK_H = &H48
%VK_I = &H49
%VK_J = &H4A
%VK_K = &H4B
%VK_L = &H4C
%VK_M = &H4D
%VK_N = &H4E
%VK_O = &H4F
%VK_P = &H50
%VK_Q = &H51
%VK_R = &H52
%VK_S = &H53
%VK_T = &H54
%VK_U = &H55
%VK_V = &H56
%VK_W = &H57
%VK_X = &H58
%VK_Y = &H59
%VK_Z = &H5A


%VK_LWIN           = &H5B
%VK_RWIN           = &H5C
%VK_APPS           = &H5D

'
' &H5E : reserved
'

%VK_SLEEP          = &H5F

%VK_NUMPAD0        = &H60
%VK_NUMPAD1        = &H61
%VK_NUMPAD2        = &H62
%VK_NUMPAD3        = &H63
%VK_NUMPAD4        = &H64
%VK_NUMPAD5        = &H65
%VK_NUMPAD6        = &H66
%VK_NUMPAD7        = &H67
%VK_NUMPAD8        = &H68
%VK_NUMPAD9        = &H69
%VK_MULTIPLY       = &H6A
%VK_ADD            = &H6B
%VK_SEPARATOR      = &H6C
%VK_SUBTRACT       = &H6D
%VK_DECIMAL        = &H6E
%VK_DIVIDE         = &H6F
%VK_F1             = &H70
%VK_F2             = &H71
%VK_F3             = &H72
%VK_F4             = &H73
%VK_F5             = &H74
%VK_F6             = &H75
%VK_F7             = &H76
%VK_F8             = &H77
%VK_F9             = &H78
%VK_F10            = &H79
%VK_F11            = &H7A
%VK_F12            = &H7B
%VK_F13            = &H7C
%VK_F14            = &H7D
%VK_F15            = &H7E
%VK_F16            = &H7F
%VK_F17            = &H80?
%VK_F18            = &H81?
%VK_F19            = &H82?
%VK_F20            = &H83?
%VK_F21            = &H84?
%VK_F22            = &H85?
%VK_F23            = &H86?
%VK_F24            = &H87?

'
' &H88 - &H8F : unassigned
'

%VK_NUMLOCK        = &H90?
%VK_SCROLL         = &H91?

'
' NEC PC-9800 kbd definitions
'
%VK_OEM_NEC_EQUAL  = &H92?   ' '=' key on numpad

'
' Fujitsu/OASYS kbd definitions
'
%VK_OEM_FJ_JISHO   = &H92?   ' 'Dictionary' key
%VK_OEM_FJ_MASSHOU = &H93?   ' 'Unregister word' key
%VK_OEM_FJ_TOUROKU = &H94?   ' 'Register word' key
%VK_OEM_FJ_LOYA    = &H95?   ' 'Left OYAYUBI' key
%VK_OEM_FJ_ROYA    = &H96?   ' 'Right OYAYUBI' key

'
' &H97 - &H9F : unassigned
'

'
' VK_L* & VK_R* - left and right Alt, Ctrl and Shift virtual keys.
' Used only as parameters to GetAsyncKeyState() and GetKeyState().
' No other API or message will distinguish left and right keys in this way.
'
%VK_LSHIFT         = &HA0?
%VK_RSHIFT         = &HA1?
%VK_LCONTROL       = &HA2?
%VK_RCONTROL       = &HA3?
%VK_LMENU          = &HA4?
%VK_RMENU          = &HA5?

#IF (%WIN32_WINNT >= &H0500)
%VK_BROWSER_BACK        = &HA6?
%VK_BROWSER_FORWARD     = &HA7?
%VK_BROWSER_REFRESH     = &HA8?
%VK_BROWSER_STOP        = &HA9?
%VK_BROWSER_SEARCH      = &HAA?
%VK_BROWSER_FAVORITES   = &HAB?
%VK_BROWSER_HOME        = &HAC?

%VK_VOLUME_MUTE         = &HAD?
%VK_VOLUME_DOWN         = &HAE?
%VK_VOLUME_UP           = &HAF?
%VK_MEDIA_NEXT_TRACK    = &HB0?
%VK_MEDIA_PREV_TRACK    = &HB1?
%VK_MEDIA_STOP          = &HB2?
%VK_MEDIA_PLAY_PAUSE    = &HB3?
%VK_LAUNCH_MAIL         = &HB4?
%VK_LAUNCH_MEDIA_SELECT = &HB5?
%VK_LAUNCH_APP1         = &HB6?
%VK_LAUNCH_APP2         = &HB7?

#ENDIF ' _WIN32_WINNT >= &H0500

'
' &HB8 - &HB9 : reserved
'

%VK_OEM_1          = &HBA?   ' ';:' for US
%VK_OEM_PLUS       = &HBB?   ' '+' any country
%VK_OEM_COMMA      = &HBC?   ' ',' any country
%VK_OEM_MINUS      = &HBD?   ' '-' any country
%VK_OEM_PERIOD     = &HBE?   ' '.' any country
%VK_OEM_2          = &HBF?   ' '/?' for US
%VK_OEM_3          = &HC0?   ' '`~' for US

'
' &HC1 - = &HD7 : reserved
'

'
' &HD8 - = &HDA : unassigned
'

%VK_OEM_4          = &HDB?  '  '[{' for US
%VK_OEM_5          = &HDC?  '  '\|' for US
%VK_OEM_6          = &HDD?  '  ']}' for US
%VK_OEM_7          = &HDE?  '  ''"' for US
%VK_OEM_8          = &HDF?

'
' &HE0 : reserved
'

'
' Various extended or enhanced keyboards
'
%VK_OEM_AX         = &HE1?  '  'AX' key on Japanese AX kbd
%VK_OEM_102        = &HE2?  '  "<>" or "\|" on RT 102-key kbd.
%VK_ICO_HELP       = &HE3?  '  Help key on ICO
%VK_ICO_00         = &HE4?  '  00 key on ICO

#IF (%WINVER >= &H0400)
%VK_PROCESSKEY     = &HE5?
#ENDIF ' %WINVER >= &H0400

%VK_ICO_CLEAR      = &HE6?


#IF (%WIN32_WINNT >= &H0500)
%VK_PACKET         = &HE7?
#ENDIF ' %WIN32_WINNT >= &H0500

'
' &HE8 : unassigned
'

'
' Nokia/Ericsson definitions
'
%VK_OEM_RESET      = &HE9?
%VK_OEM_JUMP       = &HEA?
%VK_OEM_PA1        = &HEB?
%VK_OEM_PA2        = &HEC?
%VK_OEM_PA3        = &HED?
%VK_OEM_WSCTRL     = &HEE?
%VK_OEM_CUSEL      = &HEF?
%VK_OEM_ATTN       = &HF0?
%VK_OEM_FINISH     = &HF1?
%VK_OEM_COPY       = &HF2?
%VK_OEM_AUTO       = &HF3?
%VK_OEM_ENLW       = &HF4?
%VK_OEM_BACKTAB    = &HF5?

%VK_ATTN           = &HF6?
%VK_CRSEL          = &HF7?
%VK_EXSEL          = &HF8?
%VK_EREOF          = &HF9?
%VK_PLAY           = &HFA?
%VK_ZOOM           = &HFB?
%VK_NONAME         = &HFC?
%VK_PA1            = &HFD?
%VK_OEM_CLEAR      = &HFE?

'
' &HFF : reserved
'


#ENDIF ' !NOVIRTUALKEYCODES

#IF NOT %DEF(%NOWH)

'
' SetWindowsHook() codes
'
%WH_MIN             = -1
%WH_MSGFILTER       = -1
%WH_JOURNALRECORD   = 0
%WH_JOURNALPLAYBACK = 1
%WH_KEYBOARD        = 2
%WH_GETMESSAGE      = 3
%WH_CALLWNDPROC     = 4
%WH_CBT             = 5
%WH_SYSMSGFILTER    = 6
%WH_MOUSE           = 7
#IF %DEF(%WIN32_WINDOWS)
%WH_HARDWARE        = 8
#ENDIF
%WH_DEBUG           = 9
%WH_SHELL           =10
%WH_FOREGROUNDIDLE  =11
#IF (%WINVER >= &H0400)
%WH_CALLWNDPROCRET  =12
#ENDIF ' WINVER >= &H0400

#IF (%WIN32_WINNT >= &H0400)
%WH_KEYBOARD_LL     =13
%WH_MOUSE_LL        =14
#ENDIF ' (%WIN32_WINNT >= &H0400)

#IF (%WINVER >= &H0400)
#IF (%WIN32_WINNT >= &H0400)
%WH_MAX             =14
#ELSE
%WH_MAX             =12
#ENDIF ' (%WIN32_WINNT >= &H0400)
#ELSE
%WH_MAX             =11
#ENDIF ' #IF (%WINVER >= &H0400)

%WH_MINHOOK       = %WH_MIN
%WH_MAXHOOK       = %WH_MAX

'
' Hook Codes
'
%HC_ACTION         = 0
%HC_GETNEXT        = 1
%HC_SKIP           = 2
%HC_NOREMOVE       = 3
%HC_NOREM          = %HC_NOREMOVE
%HC_SYSMODALON     = 4
%HC_SYSMODALOFF    = 5

'
' CBT Hook Codes
'
%HCBT_MOVESIZE     = 0
%HCBT_MINMAX       = 1
%HCBT_QS           = 2
%HCBT_CREATEWND    = 3
%HCBT_DESTROYWND   = 4
%HCBT_ACTIVATE     = 5
%HCBT_CLICKSKIPPED = 6
%HCBT_KEYSKIPPED   = 7
%HCBT_SYSCOMMAND   = 8
%HCBT_SETFOCUS     = 9

TYPE CREATESTRUCTA
    lpCreateParams AS DWORD
    hInstance      AS DWORD
    hMenu          AS DWORD
    hwndParent     AS DWORD
    cy             AS LONG
    cx             AS LONG
    y              AS LONG
    x              AS LONG
    STYLE          AS LONG
    lpszName       AS ASCIIZ PTR
    lpszClass      AS ASCIIZ PTR
    dwExStyle      AS DWORD
END TYPE

TYPE CREATESTRUCTW
    lpCreateParams AS DWORD
    hInstance      AS DWORD
    hMenu          AS DWORD
    hwndParent     AS DWORD
    cy             AS LONG
    cx             AS LONG
    y              AS LONG
    x              AS LONG
    STYLE          AS LONG
    lpszName       AS WSTRINGZ PTR
    lpszClass      AS WSTRINGZ PTR
    dwExStyle      AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE CREATESTRUCT
    CREATESTRUCTW
END TYPE
#ELSE
TYPE CREATESTRUCT
    CREATESTRUCTA
END TYPE
#ENDIF ' UNICODE

'
' HCBT_CREATEWND parameters pointed to by lParam
'
TYPE CBT_CREATEWNDA
    lpcs            AS CREATESTRUCTA PTR
    hwndInsertAfter AS DWORD
END TYPE

'
' HCBT_CREATEWND parameters pointed to by lParam
'
TYPE CBT_CREATEWNDW
    lpcs            AS CREATESTRUCTW PTR
    hwndInsertAfter AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE CBT_CREATEWND
    CBT_CREATEWNDW
END TYPE
#ELSE
TYPE CBT_CREATEWND
    CBT_CREATEWNDA
END TYPE
#ENDIF ' UNICODE

'
' HCBT_ACTIVATE structure pointed to by lParam
'
TYPE CBTACTIVATESTRUCT
    fMouse     AS LONG
    hWndActive AS DWORD
END TYPE

#IF (%WIN32_WINNT >= &H0501)
'
' WTSSESSION_NOTIFICATION struct pointed by lParam, for %WM_WTSSESSION_CHANGE
'
TYPE WTSSESSION_NOTIFICATION
    cbSize      AS DWORD
    dwSessionId AS DWORD
END TYPE

'
' codes passed in WPARAM for %WM_WTSSESSION_CHANGE
'

%WTS_CONSOLE_CONNECT           = &H1
%WTS_CONSOLE_DISCONNECT        = &H2
%WTS_REMOTE_CONNECT            = &H3
%WTS_REMOTE_DISCONNECT         = &H4
%WTS_SESSION_LOGON             = &H5
%WTS_SESSION_LOGOFF            = &H6
%WTS_SESSION_LOCK              = &H7
%WTS_SESSION_UNLOCK            = &H8
%WTS_SESSION_REMOTE_CONTROL    = &H9

#ENDIF ' %WIN32_WINNT >= &H0501

'
' WH_MSGFILTER Filter Proc Codes
'
%MSGF_DIALOGBOX    = 0
%MSGF_MESSAGEBOX   = 1
%MSGF_MENU         = 2
%MSGF_SCROLLBAR    = 5
%MSGF_NEXTWINDOW   = 6
%MSGF_MAX          = 8                       ' unused
%MSGF_USER         = 4096

'
' Shell support
'
%HSHELL_WINDOWCREATED       = 1
%HSHELL_WINDOWDESTROYED     = 2
%HSHELL_ACTIVATESHELLWINDOW = 3

#IF (%WINVER >= &H0400)
%HSHELL_WINDOWACTIVATED     = 4
%HSHELL_GETMINRECT          = 5
%HSHELL_REDRAW              = 6
%HSHELL_TASKMAN             = 7
%HSHELL_LANGUAGE            = 8
%HSHELL_SYSMENU             = 9
%HSHELL_ENDTASK             = 10
#ENDIF ' WINVER >= &H0400

#IF (%WIN32_WINNT >= &H0500)
%HSHELL_ACCESSIBILITYSTATE  = 11
%HSHELL_APPCOMMAND          = 12
#ENDIF ' _WIN32_WINNT >= &H0500

#IF (%WIN32_WINNT >= &H0501)
%HSHELL_WINDOWREPLACED      = 13
%HSHELL_WINDOWREPLACING     = 14
#ENDIF ' _WIN32_WINNT >= &H0501


%HSHELL_HIGHBIT          = &H8000??
%HSHELL_FLASH            = (%HSHELL_REDRAW OR %HSHELL_HIGHBIT)
%HSHELL_RUDEAPPACTIVATED = (%HSHELL_WINDOWACTIVATED OR %HSHELL_HIGHBIT)

#IF (%WIN32_WINNT >= &H0500)
' cmd for HSHELL_APPCOMMAND and %WM_APPCOMMAND
%APPCOMMAND_BROWSER_BACKWARD       = 1
%APPCOMMAND_BROWSER_FORWARD        = 2
%APPCOMMAND_BROWSER_REFRESH        = 3
%APPCOMMAND_BROWSER_STOP           = 4
%APPCOMMAND_BROWSER_SEARCH         = 5
%APPCOMMAND_BROWSER_FAVORITES      = 6
%APPCOMMAND_BROWSER_HOME           = 7
%APPCOMMAND_VOLUME_MUTE            = 8
%APPCOMMAND_VOLUME_DOWN            = 9
%APPCOMMAND_VOLUME_UP              = 10
%APPCOMMAND_MEDIA_NEXTTRACK        = 11
%APPCOMMAND_MEDIA_PREVIOUSTRACK    = 12
%APPCOMMAND_MEDIA_STOP             = 13
%APPCOMMAND_MEDIA_PLAY_PAUSE       = 14
%APPCOMMAND_LAUNCH_MAIL            = 15
%APPCOMMAND_LAUNCH_MEDIA_SELECT    = 16
%APPCOMMAND_LAUNCH_APP1            = 17
%APPCOMMAND_LAUNCH_APP2            = 18
%APPCOMMAND_BASS_DOWN              = 19
%APPCOMMAND_BASS_BOOST             = 20
%APPCOMMAND_BASS_UP                = 21
%APPCOMMAND_TREBLE_DOWN            = 22
%APPCOMMAND_TREBLE_UP              = 23
#IF (%WIN32_WINNT >= &H0501)
%APPCOMMAND_MICROPHONE_VOLUME_MUTE = 24
%APPCOMMAND_MICROPHONE_VOLUME_DOWN = 25
%APPCOMMAND_MICROPHONE_VOLUME_UP   = 26
%APPCOMMAND_HELP                   = 27
%APPCOMMAND_FIND                   = 28
%APPCOMMAND_NEW                    = 29
%APPCOMMAND_OPEN                   = 30
%APPCOMMAND_CLOSE                  = 31
%APPCOMMAND_SAVE                   = 32
%APPCOMMAND_PRINT                  = 33
%APPCOMMAND_UNDO                   = 34
%APPCOMMAND_REDO                   = 35
%APPCOMMAND_COPY                   = 36
%APPCOMMAND_CUT                    = 37
%APPCOMMAND_PASTE                  = 38
%APPCOMMAND_REPLY_TO_MAIL          = 39
%APPCOMMAND_FORWARD_MAIL           = 40
%APPCOMMAND_SEND_MAIL              = 41
%APPCOMMAND_SPELL_CHECK            = 42
%APPCOMMAND_DICTATE_OR_COMMAND_CONTROL_TOGGLE = 43
%APPCOMMAND_MIC_ON_OFF_TOGGLE      = 44
%APPCOMMAND_CORRECTION_LIST        = 45
%APPCOMMAND_MEDIA_PLAY             = 46
%APPCOMMAND_MEDIA_PAUSE            = 47
%APPCOMMAND_MEDIA_RECORD           = 48
%APPCOMMAND_MEDIA_FAST_FORWARD     = 49
%APPCOMMAND_MEDIA_REWIND           = 50
%APPCOMMAND_MEDIA_CHANNEL_UP       = 51
%APPCOMMAND_MEDIA_CHANNEL_DOWN     = 52
#ENDIF ' %WIN32_WINNT >= &H0501

#IF (%WIN32_WINNT >= &H0600)
%APPCOMMAND_DELETE               = 53
%APPCOMMAND_DWM_FLIP3D           = 54
#ENDIF ' %WIN32_WINNT >= &H0600

%FAPPCOMMAND_MOUSE = &H8000??
%FAPPCOMMAND_KEY   = 0
%FAPPCOMMAND_OEM   = &H1000
%FAPPCOMMAND_MASK  = &HF000??

MACRO GET_APPCOMMAND_LPARAM(lParam)=(HI(WORD,lParam) AND NOT %FAPPCOMMAND_MASK)
MACRO GET_DEVICE_LPARAM(lParam)=(HI(WORD,lParam) AND %FAPPCOMMAND_MASK)
MACRO GET_MOUSEORKEY_LPARAM=GET_DEVICE_LPARAM
MACRO GET_FLAGS_LPARAM(lParam)=LO(WORD,lParam)
MACRO GET_KEYSTATE_LPARAM(lParam)=GET_FLAGS_LPARAM(lParam)

#ENDIF ' _WIN32_WINNT >= &H0500

TYPE SHELLHOOKINFO
    hwnd AS DWORD
    rc   AS RECT
END TYPE

'
' Message Structure used in Journaling
'
TYPE EVENTMSG
    message AS DWORD
    paramL  AS DWORD
    paramH  AS DWORD
    dtime   AS DWORD
    hwnd    AS DWORD
END TYPE


'
' Message structure used by WH_CALLWNDPROC
'
TYPE CWPSTRUCT
    lParam  AS LONG
    wParam  AS DWORD
    message AS DWORD
    hwnd    AS DWORD
END TYPE

#IF (%WINVER >= &H0400)

'
' Message structure used by WH_CALLWNDPROCRET
'
TYPE CWPRETSTRUCT
    lResult AS DWORD
    lParam  AS LONG
    wParam  AS DWORD
    message AS DWORD
    hwnd    AS DWORD
END TYPE

#ENDIF ' WINVER >= &H0400

#IF (%WIN32_WINNT >= &H0400)

'
' Low level hook flags
'

%LLKHF_EXTENDED     = %KF_EXTENDED \ 256
%LLKHF_INJECTED     = &H00000010
%LLKHF_ALTDOWN      = %KF_ALTDOWN \ 256
%LLKHF_UP           = %KF_UP \ 256

%LLMHF_INJECTED     = &H00000001

'
' Structure used by WH_KEYBOARD_LL
'
TYPE KBDLLHOOKSTRUCT
    vkCode      AS DWORD
    scanCode    AS DWORD
    flags       AS DWORD
    time        AS DWORD
    dwExtraInfo AS DWORD
END TYPE

'
' Structure used by WH_MOUSE_LL
'
TYPE MSLLHOOKSTRUCT
    pt          AS POINT
    mouseData   AS DWORD
    flags       AS DWORD
    time        AS DWORD
    dwExtraInfo AS DWORD
END TYPE

#ENDIF ' (%WIN32_WINNT >= &H0400)

'
' Structure used by WH_DEBUG
'
TYPE DEBUGHOOKINFO
    idThread          AS DWORD
    idThreadInstaller AS DWORD
    lParam            AS LONG
    wParam            AS DWORD
    CODE              AS LONG
END TYPE

'
' Structure used by WH_MOUSE
'
TYPE MOUSEHOOKSTRUCT
    pt           AS POINT
    hwnd         AS DWORD
    wHitTestCode AS DWORD
    dwExtraInfo  AS DWORD
END TYPE

#IF (%WIN32_WINNT >= &H0500)

TYPE MOUSEHOOKSTRUCTEX
    MOUSEHOOKSTRUCT
    mouseData AS DWORD
END TYPE

#ENDIF ' %WIN32_WINNT >= &H0500

#IF (%WINVER >= &H0400)
'
' Structure used by WH_HARDWARE
'
TYPE HARDWAREHOOKSTRUCT
    hwnd    AS DWORD
    message AS DWORD
    wParam  AS DWORD
    lParam  AS LONG
END TYPE
#ENDIF ' WINVER >= &H0400

#ENDIF ' !NOWH

'
' Keyboard Layout API
'
%HKL_PREV          = 0
%HKL_NEXT          = 1


%KLF_ACTIVATE      = &H00000001
%KLF_SUBSTITUTE_OK = &H00000002
%KLF_REORDER       = &H00000008
#IF (%WINVER >= &H0400)
%KLF_REPLACELANG   = &H00000010
%KLF_NOTELLSHELL   = &H00000080
#ENDIF ' WINVER >= &H0400
%KLF_SETFORPROCESS = &H00000100
#IF (%WIN32_WINNT >= &H0500)
%KLF_SHIFTLOCK     = &H00010000
%KLF_RESET         = &H40000000
#ENDIF ' _WIN32_WINNT >= &H0500


#IF (%WINVER >= &H0500)
'
' Bits in wParam of %WM_INPUTLANGCHANGEREQUEST message
'
%INPUTLANGCHANGE_SYSCHARSET = &H0001
%INPUTLANGCHANGE_FORWARD    = &H0002
%INPUTLANGCHANGE_BACKWARD   = &H0004
#ENDIF ' WINVER >= &H0500

'
' Size of KeyboardLayoutName (number of characters), including nul terminator
'
%KL_NAMELENGTH = 9

DECLARE FUNCTION LoadKeyboardLayoutA LIB "User32.dll" _
    ALIAS "LoadKeyboardLayoutA" (pwszKLID AS ASCIIZ, BYVAL flags AS DWORD) _
    AS DWORD

DECLARE FUNCTION LoadKeyboardLayoutW LIB "User32.dll" _
    ALIAS "LoadKeyboardLayoutW" (pwszKLID AS WSTRINGZ, BYVAL flags AS DWORD) _
    AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION LoadKeyboardLayout LIB "User32.dll" _
    ALIAS "LoadKeyboardLayoutW" (pwszKLID AS WSTRINGZ, BYVAL flags AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION LoadKeyboardLayout LIB "User32.dll" _
    ALIAS "LoadKeyboardLayoutA" (pwszKLID AS ASCIIZ, BYVAL flags AS DWORD) _
    AS DWORD
#ENDIF ' NOT %UNICODE


#IF (%WINVER >= &H0400)

DECLARE FUNCTION ActivateKeyboardLayout LIB "User32.dll" _
    ALIAS "ActivateKeyboardLayout" (BYVAL HKL AS DWORD, BYVAL flags AS DWORD) _
    AS DWORD

#ELSE

DECLARE FUNCTION ActivateKeyboardLayout LIB "User32.dll" _
    ALIAS "ActivateKeyboardLayout" (BYVAL HKL AS DWORD, BYVAL flags AS DWORD) _
    AS LONG

#ENDIF ' WINVER >= &H0400

#IF (%WINVER >= &H0400)

DECLARE FUNCTION ToUnicodeEx LIB "User32.dll" ALIAS "ToUnicodeEx" _
    (BYVAL uVirtKey AS DWORD, BYVAL uScanCode AS DWORD, _
    BYVAL lpKeyState AS BYTE PTR, pwszBuff AS WSTRINGZ, _
    BYVAL cchBuff AS LONG, BYVAL uFlags AS DWORD, _
    OPTIONAL BYVAL dwhkl AS DWORD) AS LONG

#ENDIF ' WINVER >= &H0400

DECLARE FUNCTION UnloadKeyboardLayout LIB "User32.dll" _
    ALIAS "UnloadKeyboardLayout" (BYVAL HKL AS DWORD) AS LONG

DECLARE FUNCTION GetKeyboardLayoutNameA LIB "User32.dll" _
    ALIAS "GetKeyboardLayoutNameA" (pwszKLID AS ASCIIZ) AS LONG

DECLARE FUNCTION GetKeyboardLayoutNameW LIB "User32.dll" _
    ALIAS "GetKeyboardLayoutNameW" (pwszKLID AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetKeyboardLayoutName LIB "User32.dll" _
    ALIAS "GetKeyboardLayoutNameW" (pwszKLID AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION GetKeyboardLayoutName LIB "User32.dll" _
    ALIAS "GetKeyboardLayoutNameA" (pwszKLID AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

#IF (%WINVER >= &H0400)

DECLARE FUNCTION GetKeyboardLayoutList LIB "User32.dll" _
    ALIAS "GetKeyboardLayoutList" (BYVAL nBuff AS LONG, _
    BYVAL lpList AS DWORD PTR) AS LONG

DECLARE FUNCTION GetKeyboardLayout LIB "User32.dll" _
    ALIAS "GetKeyboardLayout" (BYVAL dwLayout AS DWORD) AS DWORD

#ENDIF ' WINVER >= &H0400

#IF (%WINVER >= &H0500)

TYPE MOUSEMOVEPOINT
    x           AS LONG
    y           AS LONG
    dtime       AS DWORD
    dwExtraInfo AS DWORD
END TYPE

'
' Values for resolution parameter of GetMouseMovePointsEx
'
%GMMP_USE_DISPLAY_POINTS         = 1
%GMMP_USE_HIGH_RESOLUTION_POINTS = 2

DECLARE FUNCTION GetMouseMovePointsEx LIB "User32.dll" _
    ALIAS "GetMouseMovePointsEx" (BYVAL cbSize AS DWORD, _
    lppt AS MOUSEMOVEPOINT, BYVAL lpptBuf AS MOUSEMOVEPOINT PTR, _
    BYVAL nBufPoints AS LONG, BYVAL resolution AS DWORD) AS LONG

#ENDIF ' WINVER >= &H0500

#IF NOT %DEF(%NODESKTOP)
'
' Desktop-specific access flags
'
%DESKTOP_READOBJECTS       = &H0001
%DESKTOP_CREATEWINDOW      = &H0002
%DESKTOP_CREATEMENU        = &H0004
%DESKTOP_HOOKCONTROL       = &H0008
%DESKTOP_JOURNALRECORD     = &H0010
%DESKTOP_JOURNALPLAYBACK   = &H0020
%DESKTOP_ENUMERATE         = &H0040
%DESKTOP_WRITEOBJECTS      = &H0080
%DESKTOP_SWITCHDESKTOP     = &H0100

'
' Desktop-specific control flags
'
%DF_ALLOWOTHERACCOUNTHOOK  = &H0001

#IF %DEF(%WINGDI)
#IF NOT %DEF(%NOGDI)


DECLARE FUNCTION CreateDesktopA LIB "User32.dll" ALIAS "CreateDesktopA" _
    (lpszDesktop AS ASCIIZ, lpszDevice AS ASCIIZ, pDevmode AS DEVMODEA, _
    BYVAL dwFlags AS DWORD, BYVAL dwDesiredAccess AS DWORD, _
    lpsa AS SECURITY_ATTRIBUTES) AS DWORD

DECLARE FUNCTION CreateDesktopW LIB "User32.dll" ALIAS "CreateDesktopW" _
    (lpszDesktop AS WSTRINGZ, lpszDevice AS WSTRINGZ, pDevmode AS DEVMODEW, _
    BYVAL dwFlags AS DWORD, BYVAL dwDesiredAccess AS DWORD, _
    lpsa AS SECURITY_ATTRIBUTES) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateDesktop LIB "User32.dll" ALIAS "CreateDesktopW" _
    (lpszDesktop AS WSTRINGZ, lpszDevice AS WSTRINGZ, pDevmode AS DEVMODEW, _
    BYVAL dwFlags AS DWORD, BYVAL dwDesiredAccess AS DWORD, _
    lpsa AS SECURITY_ATTRIBUTES) AS DWORD
#ELSE
DECLARE FUNCTION CreateDesktop LIB "User32.dll" ALIAS "CreateDesktopA" _
    (lpszDesktop AS ASCIIZ, lpszDevice AS ASCIIZ, pDevmode AS DEVMODEA, _
    BYVAL dwFlags AS DWORD, BYVAL dwDesiredAccess AS DWORD, _
    lpsa AS SECURITY_ATTRIBUTES) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CreateDesktopExA LIB "User32.dll" ALIAS "CreateDesktopExA" _
   (lpszDesktop AS ASCIIZ, lpszDevice AS ASCIIZ, pDevmode AS DEVMODEA, _
   BYVAL dwFlags AS DWORD, BYVAL dwDesiredAccess AS DWORD, _
   lpsz AS SECURITY_ATTRIBUTES, BYVAL ulHeapSize AS DWORD, pvoid AS DWORD) _
   AS DWORD

DECLARE FUNCTION CreateDesktopExW LIB "User32.dll" ALIAS "CreateDesktopExW" _
   (lpszDesktop AS WSTRINGZ, lpszDevice AS WSTRINGZ, pDevmode AS DEVMODEA, _
   BYVAL dwFlags AS DWORD, BYVAL dwDesiredAccess AS DWORD, _
   lpsz AS SECURITY_ATTRIBUTES, BYVAL ulHeapSize AS DWORD, pvoid AS DWORD) _
   AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateDesktopEx LIB "User32.dll" ALIAS "CreateDesktopExW" _
   (lpszDesktop AS WSTRINGZ, lpszDevice AS WSTRINGZ, pDevmode AS DEVMODEA, _
   BYVAL dwFlags AS DWORD, BYVAL dwDesiredAccess AS DWORD, _
   lpsz AS SECURITY_ATTRIBUTES, BYVAL ulHeapSize AS DWORD, pvoid AS DWORD) _
   AS DWORD
#ELSE
DECLARE FUNCTION CreateDesktopEx LIB "User32.dll" ALIAS "CreateDesktopExA" _
   (lpszDesktop AS ASCIIZ, lpszDevice AS ASCIIZ, pDevmode AS DEVMODEA, _
   BYVAL dwFlags AS DWORD, BYVAL dwDesiredAccess AS DWORD, _
   lpsz AS SECURITY_ATTRIBUTES, BYVAL ulHeapSize AS DWORD, pvoid AS DWORD) _
   AS DWORD
#ENDIF ' NOT %UNICODE

#ENDIF ' %NOGDI
#ENDIF ' %WINGDI

DECLARE FUNCTION OpenDesktopA LIB "User32.dll" ALIAS "OpenDesktopA" _
    (lpszDesktop AS ASCIIZ, BYVAL dwFlags AS DWORD, BYVAL fInherit AS LONG, _
    BYVAL dwDesiredAccess AS DWORD) AS DWORD

DECLARE FUNCTION OpenDesktopW LIB "User32.dll" ALIAS "OpenDesktopW" _
    (lpszDesktop AS WSTRINGZ, BYVAL dwFlags AS DWORD, BYVAL fInherit AS LONG, _
    BYVAL dwDesiredAccess AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION OpenDesktop LIB "User32.dll" ALIAS "OpenDesktopW" _
    (lpszDesktop AS WSTRINGZ, BYVAL dwFlags AS DWORD, BYVAL fInherit AS LONG, _
    BYVAL dwDesiredAccess AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION OpenDesktop LIB "User32.dll" ALIAS "OpenDesktopA" _
    (lpszDesktop AS ASCIIZ, BYVAL dwFlags AS DWORD, BYVAL fInherit AS LONG, _
    BYVAL dwDesiredAccess AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION OpenInputDesktop LIB "User32.dll" ALIAS "OpenInputDesktop" _
    (BYVAL dwFlags AS DWORD, BYVAL fInherit AS LONG, _
    BYVAL dwDesiredAccess AS DWORD) AS DWORD

DECLARE FUNCTION EnumDesktopsA LIB "User32.dll" ALIAS "EnumDesktopsA" _
    (BYVAL hWinSta AS DWORD, BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG) _
    AS LONG

DECLARE FUNCTION EnumDesktopsW LIB "User32.dll" ALIAS "EnumDesktopsW" _
    (BYVAL hWinSta AS DWORD, BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG) _
    AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION EnumDesktops LIB "User32.dll" ALIAS "EnumDesktopsW" _
    (BYVAL hWinSta AS DWORD, BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG) _
    AS LONG
#ELSE
DECLARE FUNCTION EnumDesktops LIB "User32.dll" ALIAS "EnumDesktopsA" _
    (BYVAL hWinSta AS DWORD, BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG) _
    AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumDesktopWindows LIB "User32.dll" _
    ALIAS "EnumDesktopWindows" (BYVAL hDesktop AS DWORD, BYVAL lpfn AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION SwitchDesktop LIB "User32.dll" ALIAS "SwitchDesktop" _
    (BYVAL hDesktop AS DWORD) AS LONG

DECLARE FUNCTION SetThreadDesktop LIB "User32.dll" ALIAS "SetThreadDesktop" _
    (BYVAL hDesktop AS DWORD) AS LONG

DECLARE FUNCTION CloseDesktop LIB "User32.dll" ALIAS "CloseDesktop" _
    (BYVAL hDesktop AS DWORD) AS LONG

DECLARE FUNCTION GetThreadDesktop LIB "User32.dll" ALIAS "GetThreadDesktop" _
    (BYVAL dwThread AS DWORD) AS DWORD

#ENDIF  ' NOT %NODESKTOP


#IF NOT %DEF(%NOWINDOWSTATION)

'
' Windowstation-specific access flags
'
%WINSTA_ENUMDESKTOPS       = &H0001
%WINSTA_READATTRIBUTES     = &H0002
%WINSTA_ACCESSCLIPBOARD    = &H0004
%WINSTA_CREATEDESKTOP      = &H0008
%WINSTA_WRITEATTRIBUTES    = &H0010
%WINSTA_ACCESSGLOBALATOMS  = &H0020
%WINSTA_EXITWINDOWS        = &H0040
%WINSTA_ENUMERATE          = &H0100
%WINSTA_READSCREEN         = &H0200

%WINSTA_ALL_ACCESS = (%WINSTA_ENUMDESKTOPS _
                   OR %WINSTA_READATTRIBUTES _
                   OR %WINSTA_ACCESSCLIPBOARD _
                   OR %WINSTA_CREATEDESKTOP _
                   OR %WINSTA_WRITEATTRIBUTES _
                   OR %WINSTA_ACCESSGLOBALATOMS _
                   OR %WINSTA_EXITWINDOWS _
                   OR %WINSTA_ENUMERATE _
                   OR %WINSTA_READSCREEN)

'
' Windowstation creation flags.
'
%CWF_CREATE_ONLY        = &H00000001

'
' Windowstation-specific attribute flags
'
%WSF_VISIBLE            = &H0001

DECLARE FUNCTION CreateWindowStationA LIB "User32.dll" _
    ALIAS "CreateWindowStationA" (lpszwinsta AS ASCIIZ, _
    BYVAL dwReserved AS DWORD, BYVAL dwDesiredAccess AS DWORD, _
    lpsa AS SECURITY_ATTRIBUTES) AS DWORD

DECLARE FUNCTION CreateWindowStationW LIB "User32.dll" _
    ALIAS "CreateWindowStationW" (lpszwinsta AS WSTRINGZ, _
    BYVAL dwReserved AS DWORD, BYVAL dwDesiredAccess AS DWORD, _
    lpsa AS SECURITY_ATTRIBUTES) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateWindowStation LIB "User32.dll" _
    ALIAS "CreateWindowStationW" (lpszwinsta AS WSTRINGZ, _
    BYVAL dwReserved AS DWORD, BYVAL dwDesiredAccess AS DWORD, _
    lpsa AS SECURITY_ATTRIBUTES) AS DWORD
#ELSE
DECLARE FUNCTION CreateWindowStation LIB "User32.dll" _
    ALIAS "CreateWindowStationA" (lpszwinsta AS ASCIIZ, _
    BYVAL dwReserved AS DWORD, BYVAL dwDesiredAccess AS DWORD, _
    lpsa AS SECURITY_ATTRIBUTES) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION OpenWindowStationA LIB "User32.dll" _
    ALIAS "OpenWindowStationA" (lpszWinSta AS ASCIIZ, _
    BYVAL fInherit AS LONG, BYVAL dwDesiredAccess AS DWORD) AS DWORD

DECLARE FUNCTION OpenWindowStationW LIB "User32.dll" _
    ALIAS "OpenWindowStationW" (lpszWinSta AS WSTRINGZ, _
    BYVAL fInherit AS LONG, BYVAL dwDesiredAccess AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION OpenWindowStation LIB "User32.dll" _
    ALIAS "OpenWindowStationW" (lpszWinSta AS WSTRINGZ, _
    BYVAL fInherit AS LONG, BYVAL dwDesiredAccess AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION OpenWindowStation LIB "User32.dll" _
    ALIAS "OpenWindowStationA" (lpszWinSta AS ASCIIZ, _
    BYVAL fInherit AS LONG, BYVAL dwDesiredAccess AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumWindowStationsA LIB "User32.dll" _
    ALIAS "EnumWindowStationsA" (BYVAL lpEnumFunc AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION EnumWindowStationsW LIB "User32.dll" _
    ALIAS "EnumWindowStationsW" (BYVAL lpEnumFunc AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION EnumWindowStations LIB "User32.dll" _
    ALIAS "EnumWindowStationsW" (BYVAL lpEnumFunc AS DWORD, _
    BYVAL lParam AS LONG) AS LONG
#ELSE
DECLARE FUNCTION EnumWindowStations LIB "User32.dll" _
    ALIAS "EnumWindowStationsA" (BYVAL lpEnumFunc AS DWORD, _
    BYVAL lParam AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CloseWindowStation LIB "User32.dll" _
    ALIAS "CloseWindowStation" (BYVAL hWinSta AS DWORD) AS LONG

DECLARE FUNCTION SetProcessWindowStation LIB "User32.dll" _
    ALIAS "SetProcessWindowStation" (BYVAL hWinSta AS DWORD) AS LONG

DECLARE FUNCTION GetProcessWindowStation LIB "User32.dll" _
    ALIAS "GetProcessWindowStation" () AS DWORD

#ENDIF  ' NOT %NOWINDOWSTATION



#IF NOT %DEF(%NOSECURITY)

DECLARE FUNCTION SetUserObjectSecurity LIB "User32.dll" _
    ALIAS "SetUserObjectSecurity" (BYVAL hObj AS DWORD, _
    pSIRequested AS LONG, pSd AS SECURITY_DESCRIPTOR) AS LONG

DECLARE FUNCTION GetUserObjectSecurity LIB "User32.dll" _
    ALIAS "GetUserObjectSecurity" (BYVAL hObj AS DWORD, pSIRequested AS LONG, _
    pSd AS SECURITY_DESCRIPTOR, BYVAL nLength AS DWORD, _
    lpnLengthNeeded AS DWORD) AS LONG

%UOI_FLAGS     = 1
%UOI_NAME      = 2
%UOI_TYPE      = 3
%UOI_USER_SID  = 4
#IF (%WINVER >= &H0600)
%UOI_HEAPSIZE  = 5
%UOI_IO        = 6
#ENDIF ' WINVER >= &H0600

TYPE USEROBJECTFLAGS
    fInherit  AS LONG
    fReserved AS LONG
    dwFlags   AS DWORD
END TYPE

DECLARE FUNCTION GetUserObjectInformationA LIB "User32.dll" _
    ALIAS "GetUserObjectInformationA" (BYVAL hObj AS DWORD, _
    BYVAL nIndex AS LONG, BYVAL pvInfo AS DWORD, BYVAL nLength AS DWORD, _
    lpnLengthNeeded AS DWORD) AS LONG

DECLARE FUNCTION GetUserObjectInformationW LIB "User32.dll" _
    ALIAS "GetUserObjectInformationW" (BYVAL hObj AS DWORD, _
    BYVAL nIndex AS LONG, BYVAL pvInfo AS DWORD, BYVAL nLength AS DWORD, _
    lpnLengthNeeded AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetUserObjectInformation LIB "User32.dll" _
    ALIAS "GetUserObjectInformationW" (BYVAL hObj AS DWORD, _
    BYVAL nIndex AS LONG, BYVAL pvInfo AS DWORD, BYVAL nLength AS DWORD, _
    lpnLengthNeeded AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetUserObjectInformation LIB "User32.dll" _
    ALIAS "GetUserObjectInformationA" (BYVAL hObj AS DWORD, _
    BYVAL nIndex AS LONG, BYVAL pvInfo AS DWORD, BYVAL nLength AS DWORD, _
    lpnLengthNeeded AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetUserObjectInformationA LIB "User32.dll" _
    ALIAS "SetUserObjectInformationA" (BYVAL hObj AS DWORD, _
    BYVAL nIndex AS LONG, BYVAL pvInfo AS DWORD, BYVAL nLength AS DWORD) _
    AS LONG

DECLARE FUNCTION SetUserObjectInformationW LIB "User32.dll" _
    ALIAS "SetUserObjectInformationW" (BYVAL hObj AS DWORD, _
    BYVAL nIndex AS LONG, BYVAL pvInfo AS DWORD, BYVAL nLength AS DWORD) _
    AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetUserObjectInformation LIB "User32.dll" _
    ALIAS "SetUserObjectInformationW" (BYVAL hObj AS DWORD, _
    BYVAL nIndex AS LONG, BYVAL pvInfo AS DWORD, BYVAL nLength AS DWORD) _
    AS LONG
#ELSE
DECLARE FUNCTION SetUserObjectInformation LIB "User32.dll" _
    ALIAS "SetUserObjectInformationA" (BYVAL hObj AS DWORD, _
    BYVAL nIndex AS LONG, BYVAL pvInfo AS DWORD, BYVAL nLength AS DWORD) _
    AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF  ' NOT %NOSECURITY



#IF (%WINVER >= &H0400)

TYPE WNDCLASSEXA
    cbSize        AS DWORD
    ' Win 3.x
    STYLE         AS DWORD
    lpfnWndProc   AS DWORD
    cbClsExtra    AS LONG
    cbWndExtra    AS LONG
    hInstance     AS DWORD
    hIcon         AS DWORD
    hCursor       AS DWORD
    hbrBackground AS DWORD
    lpszMenuName  AS ASCIIZ PTR
    lpszClassName AS ASCIIZ PTR
    ' Win 4.0
    hIconSm       AS DWORD
END TYPE

TYPE WNDCLASSEXW
    cbSize        AS DWORD
    ' Win 3.x
    STYLE         AS DWORD
    lpfnWndProc   AS DWORD
    cbClsExtra    AS LONG
    cbWndExtra    AS LONG
    hInstance     AS DWORD
    hIcon         AS DWORD
    hCursor       AS DWORD
    hbrBackground AS DWORD
    lpszMenuName  AS WSTRINGZ PTR
    lpszClassName AS WSTRINGZ PTR
    ' Win 4.0
    hIconSm       AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE WNDCLASSEX
    WNDCLASSEXW
END TYPE
#ELSE
TYPE WNDCLASSEX
    WNDCLASSEXA
END TYPE
#ENDIF ' UNICODE

#ENDIF ' WINVER >= &H0400

TYPE WNDCLASSA
    STYLE         AS DWORD
    lpfnwndproc   AS DWORD
    cbClsextra    AS LONG
    cbWndExtra    AS LONG
    hInstance     AS DWORD
    hIcon         AS DWORD
    hCursor       AS DWORD
    hbrBackground AS DWORD
    lpszMenuName  AS ASCIIZ PTR
    lpszClassName AS ASCIIZ PTR
END TYPE

TYPE WNDCLASSW
    STYLE         AS DWORD
    lpfnwndproc   AS DWORD
    cbClsextra    AS LONG
    cbWndExtra    AS LONG
    hInstance     AS DWORD
    hIcon         AS DWORD
    hCursor       AS DWORD
    hbrBackground AS DWORD
    lpszMenuName  AS WSTRINGZ PTR
    lpszClassName AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE WNDCLASS
    WNDCLASSW
END TYPE
#ELSE
TYPE WNDCLASS
    WNDCLASSA
END TYPE
#ENDIF ' UNICODE

DECLARE FUNCTION IsHungAppWindow LIB "User32.dll" ALIAS "IsHungAppWindow" _
    (BYVAL hwnd AS DWORD) AS LONG

#IF (%WINVER >= &H0501)

DECLARE SUB DisableProcessWindowsGhosting LIB "User32.dll" _
    ALIAS "DisableProcessWindowsGhosting" ()

#ENDIF ' %WINVER >= &H0501


#IF NOT %DEF(%NOMSG)

'
' Message structure
'
TYPE MSG_type
    hwnd     AS DWORD
    message  AS DWORD
    wParam   AS DWORD
    lParam   AS LONG
    time     AS DWORD
    pt       AS POINT
#IF %DEF(%MAC)
    lPrivate AS DWORD
#ENDIF
END TYPE

' [legacy]
TYPE tagMSG
    MSG_type
END TYPE

SUB POINTSTOPOINT (pt AS POINT, pts AS POINTS)
    pt.x = LO(WORD,pts.x)
    pt.y = HI(WORD,pts.y)
END SUB

MACRO POINTTOPOINTS(pt)=MAK(LONG,pt.x,pt.y)
MACRO MAKEWPARAM(l,h)=MAK(DWORD,l,h)
MACRO MAKELPARAM(l,h)=MAK(LONG,l,h)
MACRO MAKELRESULT(l,h)=MAK(LONG,l,h)

#ENDIF ' NOT %NOMSG



#IF NOT %DEF(%NOWINOFFSETS)

'
' Window field offsets for GetWindowLong()
'
#IF %DEF(%WIN64)
%GWL_STYLE         = -16
%GWL_EXSTYLE       = -20
%GWL_ID            = -12
#ELSE
%GWL_WNDPROC       = -4
%GWL_HINSTANCE     = -6
%GWL_HWNDPARENT    = -8
%GWL_STYLE         = -16
%GWL_EXSTYLE       = -20
%GWL_USERDATA      = -21
%GWL_ID            = -12
#ENDIF

%GWLP_WNDPROC      = -4
%GWLP_HINSTANCE    = -6
%GWLP_HWNDPARENT   = -8
%GWLP_USERDATA     = -21
%GWLP_ID           = -12

'
' Class field offsets for GetClassLong()
'
#IF %DEF(%WIN64)
%GCL_CBWNDEXTRA    = -18
%GCL_CBCLSEXTRA    = -20
%GCL_STYLE         = -26
%GCW_ATOM          = -32
#ELSE
%GCL_MENUNAME      = -8
%GCL_HBRBACKGROUND = -10
%GCL_HCURSOR       = -12
%GCL_HICON         = -14
%GCL_HMODULE       = -16
%GCL_CBWNDEXTRA    = -18
%GCL_CBCLSEXTRA    = -20
%GCL_WNDPROC       = -24
%GCL_STYLE         = -26
%GCW_ATOM          = -32

#IF (%WINVER >= &H0400)
%GCL_HICONSM       = -34
#ENDIF ' %WINVER >= &H0400

#ENDIF ' %WIN64

%GCLP_MENUNAME       = -8
%GCLP_HBRBACKGROUND  = -10
%GCLP_HCURSOR        = -12
%GCLP_HICON          = -14
%GCLP_HMODULE        = -16
%GCLP_WNDPROC        = -24
%GCLP_HICONSM        = -34

#ENDIF ' NOT %NOWINOFFSETS



#IF NOT %DEF(%NOWINMESSAGES)


'
' Window Messages
'

%WM_NULL                     = &H0000
%WM_CREATE                   = &H0001
%WM_DESTROY                  = &H0002
%WM_MOVE                     = &H0003
%WM_SIZE                     = &H0005

%WM_ACTIVATE                 = &H0006
'
' WM_ACTIVATE state values
'
%WA_INACTIVE    = 0
%WA_ACTIVE      = 1
%WA_CLICKACTIVE = 2

%WM_SETFOCUS                 = &H0007
%WM_KILLFOCUS                = &H0008
%WM_ENABLE                   = &H000A
%WM_SETREDRAW                = &H000B
%WM_SETTEXT                  = &H000C
%WM_GETTEXT                  = &H000D
%WM_GETTEXTLENGTH            = &H000E
%WM_PAINT                    = &H000F
%WM_CLOSE                    = &H0010
#IF NOT %DEF(%WIN32_WCE)
%WM_QUERYENDSESSION          = &H0011
%WM_QUERYOPEN                = &H0013
%WM_ENDSESSION               = &H0016
#ENDIF
%WM_QUIT                     = &H0012
%WM_ERASEBKGND               = &H0014
%WM_SYSCOLORCHANGE           = &H0015
%WM_SHOWWINDOW               = &H0018
%WM_WININICHANGE             = &H001A
#IF (%WINVER >= &H0400)
%WM_SETTINGCHANGE            = %WM_WININICHANGE
#ENDIF ' %WINVER >= &H0400

%WM_DEVMODECHANGE            = &H001B
%WM_ACTIVATEAPP              = &H001C
%WM_FONTCHANGE               = &H001D
%WM_TIMECHANGE               = &H001E
%WM_CANCELMODE               = &H001F
%WM_SETCURSOR                = &H0020
%WM_MOUSEACTIVATE            = &H0021
%WM_CHILDACTIVATE            = &H0022
%WM_QUEUESYNC                = &H0023

%WM_GETMINMAXINFO            = &H0024
'
' Struct pointed to by WM_GETMINMAXINFO lParam
'
TYPE MINMAXINFO
    ptReserved     AS POINT
    ptMaxSize      AS POINT
    ptMaxPosition  AS POINT
    ptMinTrackSize AS POINT
    ptMaxTrackSize AS POINT
END TYPE

%WM_PAINTICON                = &H0026
%WM_ICONERASEBKGND           = &H0027
%WM_NEXTDLGCTL               = &H0028
%WM_SPOOLERSTATUS            = &H002A
%WM_DRAWITEM                 = &H002B
%WM_MEASUREITEM              = &H002C
%WM_DELETEITEM               = &H002D
%WM_VKEYTOITEM               = &H002E
%WM_CHARTOITEM               = &H002F
%WM_SETFONT                  = &H0030
%WM_GETFONT                  = &H0031
%WM_SETHOTKEY                = &H0032
%WM_GETHOTKEY                = &H0033
%WM_QUERYDRAGICON            = &H0037
%WM_COMPAREITEM              = &H0039
#IF (%WINVER >= &H0500)
#IF NOT %DEF(%WIN32_WCE)
%WM_GETOBJECT                = &H003D
#ENDIF ' #IF NOT %DEF(%WIN32_WCE)
#ENDIF ' %WINVER >= &H0500
%WM_COMPACTING               = &H0041
%WM_COMMNOTIFY               = &H0044  ' no longer supported
%WM_WINDOWPOSCHANGING        = &H0046
%WM_WINDOWPOSCHANGED         = &H0047

%WM_POWER                    = &H0048
'
' wParam for WM_POWER window message and DRV_POWER driver notification
'
%PWR_OK             = 1
%PWR_FAIL           = -1
%PWR_SUSPENDREQUEST = 1
%PWR_SUSPENDRESUME  = 2
%PWR_CRITICALRESUME = 3

%WM_COPYDATA                 = &H004A
%WM_CANCELJOURNAL            = &H004B


'
' lParam of WM_COPYDATA message points to...
'
TYPE COPYDATASTRUCT
    dwData AS DWORD
    cbData AS DWORD
    lpData AS DWORD
END TYPE

#IF (%WINVER >= &H0400)

TYPE MDINEXTMENU
    hmenuIn   AS DWORD
    hmenuNext AS DWORD
    hwndNext  AS DWORD
END TYPE

#ENDIF ' %WINVER >= &H0400


#IF (%WINVER >= &H0400)
%WM_NOTIFY                    = &H004E
%WM_INPUTLANGCHANGEREQUEST    = &H0050
%WM_INPUTLANGCHANGE           = &H0051
%WM_TCARD                     = &H0052
%WM_HELP                      = &H0053
%WM_USERCHANGED               = &H0054
%WM_NOTIFYFORMAT              = &H0055

%NFR_ANSI                     = 1
%NFR_UNICODE                  = 2
%NF_QUERY                     = 3
%NF_REQUERY                   = 4

%WM_CONTEXTMENU               = &H007B
%WM_STYLECHANGING             = &H007C
%WM_STYLECHANGED              = &H007D
%WM_DISPLAYCHANGE             = &H007E
%WM_GETICON                   = &H007F
%WM_SETICON                   = &H0080
#ENDIF ' %WINVER >= &H0400

%WM_NCCREATE                  = &H0081
%WM_NCDESTROY                 = &H0082
%WM_NCCALCSIZE                = &H0083
%WM_NCHITTEST                 = &H0084
%WM_NCPAINT                   = &H0085
%WM_NCACTIVATE                = &H0086
%WM_GETDLGCODE                = &H0087
#IF NOT %DEF(%WIN32_WCE)
%WM_SYNCPAINT                 = &H0088
#ENDIF
%WM_NCMOUSEMOVE               = &H00A0
%WM_NCLBUTTONDOWN             = &H00A1
%WM_NCLBUTTONUP               = &H00A2
%WM_NCLBUTTONDBLCLK           = &H00A3
%WM_NCRBUTTONDOWN             = &H00A4
%WM_NCRBUTTONUP               = &H00A5
%WM_NCRBUTTONDBLCLK           = &H00A6
%WM_NCMBUTTONDOWN             = &H00A7
%WM_NCMBUTTONUP               = &H00A8
%WM_NCMBUTTONDBLCLK           = &H00A9



#IF (%WIN32_WINNT >= &H0500)
%WM_NCXBUTTONDOWN             = &H00AB
%WM_NCXBUTTONUP               = &H00AC
%WM_NCXBUTTONDBLCLK           = &H00AD
#ENDIF ' %WIN32_WINNT >= &H0500


#IF (%WIN32_WINNT >= &H0501)
%WM_INPUT_DEVICE_CHANGE       = &H00FE
#ENDIF ' %WIN32_WINNT >= &H0501

#IF (%WIN32_WINNT >= &H0501)
%WM_INPUT                     = &H00FF
#ENDIF ' %WIN32_WINNT >= &H0501

%WM_KEYFIRST                 = &H0100
%WM_KEYDOWN                  = &H0100
%WM_KEYUP                    = &H0101
%WM_CHAR                     = &H0102
%WM_DEADCHAR                 = &H0103
%WM_SYSKEYDOWN               = &H0104
%WM_SYSKEYUP                 = &H0105
%WM_SYSCHAR                  = &H0106
%WM_SYSDEADCHAR              = &H0107
#IF (%WIN32_WINNT >= &H0501)
%WM_UNICHAR                  = &H0109
%WM_KEYLAST                  = &H0109
%UNICODE_NOCHAR              = &HFFFF??
#ELSE
%WM_KEYLAST                  = &H0108
#ENDIF ' %WIN32_WINNT >= &H0501

#IF (%WINVER >= &H0400)
%WM_IME_STARTCOMPOSITION     = &H010D
%WM_IME_ENDCOMPOSITION       = &H010E
%WM_IME_COMPOSITION          = &H010F
%WM_IME_KEYLAST              = &H010F
#ENDIF ' %WINVER >= &H0400

%WM_INITDIALOG               = &H0110
%WM_COMMAND                  = &H0111
%WM_SYSCOMMAND               = &H0112
%WM_TIMER                    = &H0113
%WM_HSCROLL                  = &H0114
%WM_VSCROLL                  = &H0115
%WM_INITMENU                 = &H0116
%WM_INITMENUPOPUP            = &H0117
#IF (%WINVER >= &H0601)
%WM_GESTURE                  = &H0119
%WM_GESTURENOTIFY            = &H011A
#ENDIF  ' %WINVER >= &H0601
%WM_MENUSELECT               = &H011F
%WM_MENUCHAR                 = &H0120
%WM_ENTERIDLE                = &H0121
#IF (%WINVER >= &H0500)
#IF NOT %DEF(%WIN32_WCE)
%WM_MENURBUTTONUP            = &H0122
%WM_MENUDRAG                 = &H0123
%WM_MENUGETOBJECT            = &H0124
%WM_UNINITMENUPOPUP          = &H0125
%WM_MENUCOMMAND              = &H0126

#IF NOT %DEF(%WIN32_WCE)
#IF (%WIN32_WINNT >= &H0500)
%WM_CHANGEUISTATE            = &H0127
%WM_UPDATEUISTATE            = &H0128
%WM_QUERYUISTATE             = &H0129

'
' LOWORD(wParam) values in WM_*UISTATE*
'
%UIS_SET                     = 1
%UIS_CLEAR                   = 2
%UIS_INITIALIZE              = 3

'
' HIWORD(wParam) values in WM_*UISTATE*
'
%UISF_HIDEFOCUS              = &H1
%UISF_HIDEACCEL              = &H2
#IF (%WIN32_WINNT >= &H0501)
%UISF_ACTIVE                 = &H4
#ENDIF ' %WIN32_WINNT >= &H0501
#ENDIF ' %WIN32_WINNT >= &H0500
#ENDIF ' NOT %DEF(%WIN32_WCE)

#ENDIF ' NOT %DEF(%WIN32_WCE)
#ENDIF ' %WINVER >= &H0500

%WM_CTLCOLORMSGBOX           = &H0132
%WM_CTLCOLOREDIT             = &H0133
%WM_CTLCOLORLISTBOX          = &H0134
%WM_CTLCOLORBTN              = &H0135
%WM_CTLCOLORDLG              = &H0136
%WM_CTLCOLORSCROLLBAR        = &H0137
%WM_CTLCOLORSTATIC           = &H0138
%MN_GETHMENU                 = &H01E1

%WM_MOUSEFIRST               = &H0200
%WM_MOUSEMOVE                = &H0200
%WM_LBUTTONDOWN              = &H0201
%WM_LBUTTONUP                = &H0202
%WM_LBUTTONDBLCLK            = &H0203
%WM_RBUTTONDOWN              = &H0204
%WM_RBUTTONUP                = &H0205
%WM_RBUTTONDBLCLK            = &H0206
%WM_MBUTTONDOWN              = &H0207
%WM_MBUTTONUP                = &H0208
%WM_MBUTTONDBLCLK            = &H0209
#IF (%WIN32_WINNT >= &H0400) OR (%WIN32_WINDOWS > &H0400)
%WM_MOUSEWHEEL               = &H020A
#ENDIF
#IF (%WIN32_WINNT >= &H0500)
%WM_XBUTTONDOWN              = &H020B
%WM_XBUTTONUP                = &H020C
%WM_XBUTTONDBLCLK            = &H020D
#ENDIF
#IF (%WIN32_WINNT >= &H0600)
%WM_MOUSEHWHEEL              = &H020E
#ENDIF

#IF (%WIN32_WINNT >= &H0600)
%WM_MOUSELAST                = &H020E
#ELSEIF (%WIN32_WINNT >= &H0500)
%WM_MOUSELAST                = &H020D
#ELSEIF (%WIN32_WINNT >= &H0400) OR (%WIN32_WINDOWS > &H0400)
%WM_MOUSELAST                = &H020A
#ELSE
%WM_MOUSELAST                = &H0209
#ENDIF ' (%WIN32_WINNT >= &H0600)


#IF (%WIN32_WINNT >= &H0400)
' Value for rolling one detent
%WHEEL_DELTA                 = 120
MACRO GET_WHEEL_DELTA_WPARAM(wParam)=HI(INTEGER,wParam)

' Setting to scroll one page for SPI_GET/SETWHEELSCROLLLINES
%WHEEL_PAGESCROLL            = &HFFFFFFFF??? ' (UINT_MAX)
#ENDIF ' %WIN32_WINNT >= &H0400

#IF (%WIN32_WINNT >= &H0500)
MACRO GET_KEYSTATE_WPARAM(wParam)=LO(WORD,wParam)
MACRO GET_NCHITTEST_WPARAM(wParam)=LO(INTEGER,wParam)
MACRO GET_XBUTTON_WPARAM(wParam)=HI(WORD,wParam)

' XButton values are WORD flags
%XBUTTON1    = &H0001
%XBUTTON2    = &H0002
' Were there to be an XBUTTON3, its value would be &H0004
#ENDIF ' %WIN32_WINNT >= &H0500

%WM_PARENTNOTIFY               = &H0210
%WM_ENTERMENULOOP              = &H0211
%WM_EXITMENULOOP               = &H0212

#IF (%WINVER >= &H0400)
%WM_NEXTMENU                   = &H0213
%WM_SIZING                     = &H0214
%WM_CAPTURECHANGED             = &H0215
%WM_MOVING                     = &H0216
#ENDIF ' %WINVER >= &H0400

#IF (%WINVER >= &H0400)

%WM_POWERBROADCAST             = &H0218

#IF NOT %DEF(%WIN32_WCE)
%PBT_APMQUERYSUSPEND           = &H0000
%PBT_APMQUERYSTANDBY           = &H0001

%PBT_APMQUERYSUSPENDFAILED     = &H0002
%PBT_APMQUERYSTANDBYFAILED     = &H0003

%PBT_APMSUSPEND                = &H0004
%PBT_APMSTANDBY                = &H0005

%PBT_APMRESUMECRITICAL         = &H0006
%PBT_APMRESUMESUSPEND          = &H0007
%PBT_APMRESUMESTANDBY          = &H0008

%PBTF_APMRESUMEFROMFAILURE     = &H00000001

%PBT_APMBATTERYLOW             = &H0009
%PBT_APMPOWERSTATUSCHANGE      = &H000A

%PBT_APMOEMEVENT               = &H000B


%PBT_APMRESUMEAUTOMATIC        = &H0012

#IF (%WIN32_WINNT >= &H0502)
#IF NOT %DEF(%PBT_POWERSETTINGCHANGE)

%PBT_POWERSETTINGCHANGE        = &H8013??

TYPE POWERBROADCAST_SETTING
    PowerSetting AS GUID
    DataLength   AS DWORD
    bData(0)     AS BYTE
END TYPE

#ENDIF ' %PBT_POWERSETTINGCHANGE

#ENDIF ' (%WIN32_WINNT >= &H0502)
#ENDIF ' NOT %DEF(%WIN32_WCE)

#ENDIF ' %WINVER >= &H0400

#IF (%WINVER >= &H0400)
%WM_DEVICECHANGE              = &H0219
#ENDIF ' %WINVER >= &H0400

%WM_MDICREATE                 = &H0220
%WM_MDIDESTROY                = &H0221
%WM_MDIACTIVATE               = &H0222
%WM_MDIRESTORE                = &H0223
%WM_MDINEXT                   = &H0224
%WM_MDIMAXIMIZE               = &H0225
%WM_MDITILE                   = &H0226
%WM_MDICASCADE                = &H0227
%WM_MDIICONARRANGE            = &H0228
%WM_MDIGETACTIVE              = &H0229


%WM_MDISETMENU                = &H0230
%WM_ENTERSIZEMOVE             = &H0231
%WM_EXITSIZEMOVE              = &H0232
%WM_DROPFILES                 = &H0233
%WM_MDIREFRESHMENU            = &H0234

#IF (%WINVER >= &H0601)
%WM_TOUCH                     = &H0240
#ENDIF  ' %WINVER >= &H0601

#IF (%WINVER >= &H0400)
%WM_IME_SETCONTEXT            = &H0281
%WM_IME_NOTIFY                = &H0282
%WM_IME_CONTROL               = &H0283
%WM_IME_COMPOSITIONFULL       = &H0284
%WM_IME_SELECT                = &H0285
%WM_IME_CHAR                  = &H0286
#ENDIF ' %WINVER >= &H0400
#IF (%WINVER >= &H0500)
%WM_IME_REQUEST               = &H0288
#ENDIF ' %WINVER >= &H0500
#IF (%WINVER >= &H0400)
%WM_IME_KEYDOWN               = &H0290
%WM_IME_KEYUP                 = &H0291
#ENDIF ' %WINVER >= &H0400

#IF (%WIN32_WINNT >= &H0400) OR (%WINVER >= &H0500)
%WM_MOUSEHOVER               = &H02A1
%WM_MOUSELEAVE               = &H02A3
#ENDIF
#IF (%WINVER >= &H0500)
%WM_NCMOUSEHOVER             = &H02A0
%WM_NCMOUSELEAVE             = &H02A2
#ENDIF ' %WINVER >= &H0500

#IF (%WIN32_WINNT >= &H0501)
%WM_WTSSESSION_CHANGE        = &H02B1

%WM_TABLET_FIRST             = &H02c0
%WM_TABLET_LAST              = &H02df
#ENDIF ' %WIN32_WINNT >= &H0501

%WM_CUT                      = &H0300
%WM_COPY                     = &H0301
%WM_PASTE                    = &H0302
%WM_CLEAR                    = &H0303
%WM_UNDO                     = &H0304
%WM_RENDERFORMAT             = &H0305
%WM_RENDERALLFORMATS         = &H0306
%WM_DESTROYCLIPBOARD         = &H0307
%WM_DRAWCLIPBOARD            = &H0308
%WM_PAINTCLIPBOARD           = &H0309
%WM_VSCROLLCLIPBOARD         = &H030A
%WM_SIZECLIPBOARD            = &H030B
%WM_ASKCBFORMATNAME          = &H030C
%WM_CHANGECBCHAIN            = &H030D
%WM_HSCROLLCLIPBOARD         = &H030E
%WM_QUERYNEWPALETTE          = &H030F
%WM_PALETTEISCHANGING        = &H0310
%WM_PALETTECHANGED           = &H0311
%WM_HOTKEY                   = &H0312

#IF (%WINVER >= &H0400)
%WM_PRINT                    = &H0317
%WM_PRINTCLIENT              = &H0318
#ENDIF ' %WINVER >= &H0400

#IF (%WIN32_WINNT >= &H0500)
%WM_APPCOMMAND               = &H0319
#ENDIF ' %WIN32_WINNT >= &H0500

#IF (%WIN32_WINNT >= &H0501)
%WM_THEMECHANGED             = &H031A
#ENDIF ' %WIN32_WINNT >= &H0501


#IF (%WIN32_WINNT >= &H0501)
%WM_CLIPBOARDUPDATE          = &H031D
#ENDIF ' %WIN32_WINNT >= &H0501

#IF (%WIN32_WINNT >= &H0600)
%WM_DWMCOMPOSITIONCHANGED       = &H031E
%WM_DWMNCRENDERINGCHANGED       = &H031F
%WM_DWMCOLORIZATIONCOLORCHANGED = &H0320
%WM_DWMWINDOWMAXIMIZEDCHANGE    = &H0321
#ENDIF ' %WIN32_WINNT >= &H0600

#IF (%WIN32_WINNT >= &H0601)
%WM_DWMSENDICONICTHUMBNAIL         = &H0323
%WM_DWMSENDICONICLIVEPREVIEWBITMAP = &H0326
#ENDIF  ' %WIN32_WINNT >= &H0601

#IF (%WINVER >= &H0600)
%WM_GETTITLEBARINFOEX        = &H033F
#ENDIF ' %WINVER >= &H0600

#IF (%WINVER >= &H0400)

%WM_HANDHELDFIRST            = &H0358
%WM_HANDHELDLAST             = &H035F

%WM_AFXFIRST                 = &H0360
%WM_AFXLAST                  = &H037F
#ENDIF ' %WINVER >= &H0400

%WM_PENWINFIRST              = &H0380
%WM_PENWINLAST               = &H038F


#IF (%WINVER >= &H0400)
%WM_APP                      = &H8000??
#ENDIF ' %WINVER >= &H0400


'
' NOTE: All Message Numbers below &H0400 are RESERVED.
'
' Private Window Messages Start Here:
'
%WM_USER                     = &H0400

#IF (%WINVER >= &H0400)

' wParam for %WM_SIZING message
%WMSZ_LEFT         = 1
%WMSZ_RIGHT        = 2
%WMSZ_TOP          = 3
%WMSZ_TOPLEFT      = 4
%WMSZ_TOPRIGHT     = 5
%WMSZ_BOTTOM       = 6
%WMSZ_BOTTOMLEFT   = 7
%WMSZ_BOTTOMRIGHT  = 8
#ENDIF ' %WINVER >= &H0400

#IF NOT %DEF(%NONCMESSAGES)

'
' %WM_NCHITTEST and MOUSEHOOKSTRUCT Mouse Position Codes
'
%HTERROR           = -2
%HTTRANSPARENT     = -1
%HTNOWHERE         = 0
%HTCLIENT          = 1
%HTCAPTION         = 2
%HTSYSMENU         = 3
%HTGROWBOX         = 4
%HTSIZE            = %HTGROWBOX
%HTMENU            = 5
%HTHSCROLL         = 6
%HTVSCROLL         = 7
%HTMINBUTTON       = 8
%HTMAXBUTTON       = 9
%HTLEFT            = 10
%HTRIGHT           = 11
%HTTOP             = 12
%HTTOPLEFT         = 13
%HTTOPRIGHT        = 14
%HTBOTTOM          = 15
%HTBOTTOMLEFT      = 16
%HTBOTTOMRIGHT     = 17
%HTBORDER          = 18
%HTREDUCE          = %HTMINBUTTON
%HTZOOM            = %HTMAXBUTTON
%HTSIZEFIRST       = %HTLEFT
%HTSIZELAST        = %HTBOTTOMRIGHT
#IF (%WINVER >= &H0400)
%HTOBJECT          = 19
%HTCLOSE           = 20
%HTHELP            = 21
#ENDIF ' %WINVER >= &H0400

'
' SendMessageTimeout values
'
%SMTO_NORMAL       = &H0000
%SMTO_BLOCK        = &H0001
%SMTO_ABORTIFHUNG  = &H0002
#IF (%WINVER >= &H0500)
%SMTO_NOTIMEOUTIFNOTHUNG = &H0008
#ENDIF ' %WINVER >= &H0500
#IF (%WINVER >= &H0600)
%SMTO_ERRORONEXIT  = &H0020
#ENDIF ' %WINVER >= &H0600

#ENDIF ' NOT %NONCMESSAGES

'
' %WM_MOUSEACTIVATE Return Codes
'
%MA_ACTIVATE         = 1
%MA_ACTIVATEANDEAT   = 2
%MA_NOACTIVATE       = 3
%MA_NOACTIVATEANDEAT = 4

'
' %WM_SETICON / %WM_GETICON Type Codes
'
%ICON_SMALL        = 0
%ICON_BIG          = 1
#IF (%WIN32_WINNT >= &H0501)
%ICON_SMALL2       = 2
#ENDIF ' %WIN32_WINNT >= &H0501

DECLARE FUNCTION RegisterWindowMessageA LIB "User32.dll" _
    ALIAS "RegisterWindowMessageA" (lpString AS ASCIIZ) AS DWORD

DECLARE FUNCTION RegisterWindowMessageW LIB "User32.dll" _
    ALIAS "RegisterWindowMessageW" (lpString AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION RegisterWindowMessage LIB "User32.dll" _
    ALIAS "RegisterWindowMessageW" (lpString AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION RegisterWindowMessage LIB "User32.dll" _
    ALIAS "RegisterWindowMessageA" (lpString AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE


'
' %WM_SIZE message wParam values
'
%SIZE_RESTORED      = 0
%SIZE_MINIMIZED     = 1
%SIZE_MAXIMIZED     = 2
%SIZE_MAXSHOW       = 3
%SIZE_MAXHIDE       = 4

'
' Obsolete constant names
'
%SIZENORMAL         = %SIZE_RESTORED
%SIZEICONIC         = %SIZE_MINIMIZED
%SIZEFULLSCREEN     = %SIZE_MAXIMIZED
%SIZEZOOMSHOW       = %SIZE_MAXSHOW
%SIZEZOOMHIDE       = %SIZE_MAXHIDE

'
' %WM_WINDOWPOSCHANGING/CHANGED struct pointed to by lParam
'
TYPE WINDOWPOS
    hwnd            AS DWORD
    hwndInsertAfter AS DWORD
    x               AS LONG
    y               AS LONG
    cx              AS LONG
    cy              AS LONG
    flags           AS DWORD
END TYPE

'
' %WM_NCCALCSIZE parameter structure
'
TYPE NCCALCSIZE_PARAMS
    rgrc(2) AS RECT
    lppos   AS WINDOWPOS PTR
END TYPE

'
' %WM_NCCALCSIZE "window valid rect" return values
'
%WVR_ALIGNTOP      = &H0010
%WVR_ALIGNLEFT     = &H0020
%WVR_ALIGNBOTTOM   = &H0040
%WVR_ALIGNRIGHT    = &H0080
%WVR_HREDRAW       = &H0100
%WVR_VREDRAW       = &H0200
%WVR_REDRAW        = (%WVR_HREDRAW OR %WVR_VREDRAW)
%WVR_VALIDRECTS    = &H0400


#IF NOT %DEF(%NOKEYSTATES)

'
' Key State Masks for Mouse Messages
'
%MK_LBUTTON        = &H0001
%MK_RBUTTON        = &H0002
%MK_SHIFT          = &H0004
%MK_CONTROL        = &H0008
%MK_MBUTTON        = &H0010
#IF (%WIN32_WINNT >= &H0500)
%MK_XBUTTON1       = &H0020
%MK_XBUTTON2       = &H0040
#ENDIF ' %WIN32_WINNT >= &H0500

#ENDIF ' NOT %NOKEYSTATES


#IF (%WIN32_WINNT >= &H0400)
#IF NOT %DEF(%NOTRACKMOUSEEVENT)

%TME_HOVER     = &H00000001
%TME_LEAVE     = &H00000002
#IF (%WINVER >= &H0500)
%TME_NONCLIENT = &H00000010
#ENDIF ' %WINVER >= &H0500
%TME_QUERY     = &H40000000
%TME_CANCEL    = &H80000000???


%HOVER_DEFAULT = &HFFFFFFFF???

#IF (%WIN32_WINNT >= &H0400)

TYPE TRACKMOUSEEVENT_type
    cbSize      AS DWORD
    dwFlags     AS DWORD
    hwndTrack   AS DWORD   ' HWND
    dwHoverTime AS DWORD
END TYPE

' [legacy]
TYPE EVENTTRACK
    TRACKMOUSEEVENT_type
END TYPE

' [legacy]
TYPE TRACKMOUSEEVENTAPI
    TRACKMOUSEEVENT_type
END TYPE

DECLARE FUNCTION TrackMouseEvent LIB "User32.dll" ALIAS "TrackMouseEvent" _
    (lpEventTrack AS TRACKMOUSEEVENT_type) AS LONG

#ENDIF ' %WIN32_WINNT >= &H0400

#ENDIF ' NOT %NOTRACKMOUSEEVENT
#ENDIF ' %WIN32_WINNT >= &H0400


#ENDIF ' NOT %NOWINMESSAGES



#IF NOT %DEF(%NOWINSTYLES)

'
' Window Styles
'
%WS_OVERLAPPED     = &H00000000
%WS_POPUP          = &H80000000???
%WS_CHILD          = &H40000000
%WS_MINIMIZE       = &H20000000
%WS_VISIBLE        = &H10000000
%WS_DISABLED       = &H08000000
%WS_CLIPSIBLINGS   = &H04000000
%WS_CLIPCHILDREN   = &H02000000
%WS_MAXIMIZE       = &H01000000
%WS_CAPTION        = &H00C00000     ' %WS_BORDER OR %WS_DLGFRAME
%WS_BORDER         = &H00800000
%WS_DLGFRAME       = &H00400000
%WS_VSCROLL        = &H00200000
%WS_HSCROLL        = &H00100000
%WS_SYSMENU        = &H00080000
%WS_THICKFRAME     = &H00040000
%WS_GROUP          = &H00020000
%WS_TABSTOP        = &H00010000

%WS_MINIMIZEBOX    = &H00020000
%WS_MAXIMIZEBOX    = &H00010000


%WS_TILED          = %WS_OVERLAPPED
%WS_ICONIC         = %WS_MINIMIZE
%WS_SIZEBOX        = %WS_THICKFRAME
%WS_TILEDWINDOW    = %WS_OVERLAPPEDWINDOW

'
' Common Window Styles
'
%WS_OVERLAPPEDWINDOW = (%WS_OVERLAPPED  _
                     OR %WS_CAPTION     _
                     OR %WS_SYSMENU     _
                     OR %WS_THICKFRAME  _
                     OR %WS_MINIMIZEBOX _
                     OR %WS_MAXIMIZEBOX)

%WS_POPUPWINDOW      = (%WS_POPUP  _
                     OR %WS_BORDER _
                     OR %WS_SYSMENU)

%WS_CHILDWINDOW      = %WS_CHILD

'
' Extended Window Styles
'
%WS_EX_DLGMODALFRAME   = &H00000001
%WS_EX_NOPARENTNOTIFY  = &H00000004
%WS_EX_TOPMOST         = &H00000008
%WS_EX_ACCEPTFILES     = &H00000010
%WS_EX_TRANSPARENT     = &H00000020
#IF (%WINVER >= &H0400)
%WS_EX_MDICHILD        = &H00000040
%WS_EX_TOOLWINDOW      = &H00000080
%WS_EX_WINDOWEDGE      = &H00000100
%WS_EX_CLIENTEDGE      = &H00000200
%WS_EX_CONTEXTHELP     = &H00000400
#ENDIF ' %WINVER >= &H0400

#IF (%WINVER >= &H0400)

%WS_EX_RIGHT           = &H00001000
%WS_EX_LEFT            = &H00000000
%WS_EX_RTLREADING      = &H00002000
%WS_EX_LTRREADING      = &H00000000
%WS_EX_LEFTSCROLLBAR   = &H00004000
%WS_EX_RIGHTSCROLLBAR  = &H00000000

%WS_EX_CONTROLPARENT   = &H00010000
%WS_EX_STATICEDGE      = &H00020000
%WS_EX_APPWINDOW       = &H00040000


%WS_EX_OVERLAPPEDWINDOW = (%WS_EX_WINDOWEDGE OR %WS_EX_CLIENTEDGE)
%WS_EX_PALETTEWINDOW    = (%WS_EX_WINDOWEDGE OR %WS_EX_TOOLWINDOW OR %WS_EX_TOPMOST)

#ENDIF ' %WINVER >= &H0400

#IF (%WIN32_WINNT >= &H0500)
%WS_EX_LAYERED         = &H00080000

#ENDIF ' %WIN32_WINNT >= &H0500

#IF (%WINVER >= &H0500)
%WS_EX_NOINHERITLAYOUT  = &H00100000 ' Disable inheritence of mirroring by children
%WS_EX_LAYOUTRTL        = &H00400000 ' Right to left mirroring
#ENDIF ' %WINVER >= &H0500

#IF (%WIN32_WINNT >= &H0501)
%WS_EX_COMPOSITED       = &H02000000
#ENDIF ' %WIN32_WINNT >= &H0501

#IF (%WIN32_WINNT >= &H0500)
%WS_EX_NOACTIVATE       = &H08000000
#ENDIF ' %WIN32_WINNT >= &H0500

'
' Class styles
'
%CS_VREDRAW         = &H0001
%CS_HREDRAW         = &H0002
%CS_DBLCLKS         = &H0008
%CS_OWNDC           = &H0020
%CS_CLASSDC         = &H0040
%CS_PARENTDC        = &H0080
%CS_NOCLOSE         = &H0200
%CS_SAVEBITS        = &H0800
%CS_BYTEALIGNCLIENT = &H1000
%CS_BYTEALIGNWINDOW = &H2000
%CS_GLOBALCLASS     = &H4000

%CS_IME             = &H00010000
#IF (%WIN32_WINNT >= &H0501)
%CS_DROPSHADOW      = &H00020000
#ENDIF ' %WIN32_WINNT >= &H0501

#ENDIF ' NOT %NOWINSTYLES

#IF (%WINVER >= &H0400)
' %WM_PRINT flags
%PRF_CHECKVISIBLE    = &H00000001
%PRF_NONCLIENT       = &H00000002
%PRF_CLIENT          = &H00000004
%PRF_ERASEBKGND      = &H00000008
%PRF_CHILDREN        = &H00000010
%PRF_OWNED           = &H00000020

' 3D border styles
%BDR_RAISEDOUTER = &H0001
%BDR_SUNKENOUTER = &H0002
%BDR_RAISEDINNER = &H0004
%BDR_SUNKENINNER = &H0008

%BDR_OUTER       = (%BDR_RAISEDOUTER OR %BDR_SUNKENOUTER)
%BDR_INNER       = (%BDR_RAISEDINNER OR %BDR_SUNKENINNER)
%BDR_RAISED      = (%BDR_RAISEDOUTER OR %BDR_RAISEDINNER)
%BDR_SUNKEN      = (%BDR_SUNKENOUTER OR %BDR_SUNKENINNER)


%EDGE_RAISED     = (%BDR_RAISEDOUTER OR %BDR_RAISEDINNER)
%EDGE_SUNKEN     = (%BDR_SUNKENOUTER OR %BDR_SUNKENINNER)
%EDGE_ETCHED     = (%BDR_SUNKENOUTER OR %BDR_RAISEDINNER)
%EDGE_BUMP       = (%BDR_RAISEDOUTER OR %BDR_SUNKENINNER)

' Border flags
%BF_LEFT         = &H0001
%BF_TOP          = &H0002
%BF_RIGHT        = &H0004
%BF_BOTTOM       = &H0008

%BF_TOPLEFT      = (%BF_TOP OR %BF_LEFT)
%BF_TOPRIGHT     = (%BF_TOP OR %BF_RIGHT)
%BF_BOTTOMLEFT   = (%BF_BOTTOM OR %BF_LEFT)
%BF_BOTTOMRIGHT  = (%BF_BOTTOM OR %BF_RIGHT)
%BF_RECT         = (%BF_LEFT OR %BF_TOP OR %BF_RIGHT OR %BF_BOTTOM)

%BF_DIAGONAL     = &H0010

' For diagonal lines, the BF_RECT flags specify the end point of the
' vector bounded by the rectangle parameter.
%BF_DIAGONAL_ENDTOPRIGHT     = (%BF_DIAGONAL OR %BF_TOP OR %BF_RIGHT)
%BF_DIAGONAL_ENDTOPLEFT      = (%BF_DIAGONAL OR %BF_TOP OR %BF_LEFT)
%BF_DIAGONAL_ENDBOTTOMLEFT   = (%BF_DIAGONAL OR %BF_BOTTOM OR %BF_LEFT)
%BF_DIAGONAL_ENDBOTTOMRIGHT  = (%BF_DIAGONAL OR %BF_BOTTOM OR %BF_RIGHT)


%BF_MIDDLE    = &H0800  ' Fill in the middle
%BF_SOFT      = &H1000  ' For softer buttons
%BF_ADJUST    = &H2000  ' Calculate the space left over
%BF_FLAT      = &H4000  ' For flat rather than 3D borders
%BF_MONO      = &H8000??  ' For monochrome borders


DECLARE FUNCTION DrawEdge LIB "User32.dll" ALIAS "DrawEdge" _
    (BYVAL hDC AS DWORD, qrc AS RECT, BYVAL edge AS DWORD, _
    BYVAL grfFlags AS DWORD) AS LONG

' flags for DrawFrameControl

%DFC_CAPTION           = 1
%DFC_MENU              = 2
%DFC_SCROLL            = 3
%DFC_BUTTON            = 4
#IF (%WINVER >= &H0500)
%DFC_POPUPMENU         = 5
#ENDIF ' %WINVER >= &H0500

%DFCS_CAPTIONCLOSE        = &H0000
%DFCS_CAPTIONMIN          = &H0001
%DFCS_CAPTIONMAX          = &H0002
%DFCS_CAPTIONRESTORE      = &H0003
%DFCS_CAPTIONHELP         = &H0004

%DFCS_MENUARROW           = &H0000
%DFCS_MENUCHECK           = &H0001
%DFCS_MENUBULLET          = &H0002
%DFCS_MENUARROWRIGHT      = &H0004
%DFCS_SCROLLUP            = &H0000
%DFCS_SCROLLDOWN          = &H0001
%DFCS_SCROLLLEFT          = &H0002
%DFCS_SCROLLRIGHT         = &H0003
%DFCS_SCROLLCOMBOBOX      = &H0005
%DFCS_SCROLLSIZEGRIP      = &H0008
%DFCS_SCROLLSIZEGRIPRIGHT = &H0010

%DFCS_BUTTONCHECK         = &H0000
%DFCS_BUTTONRADIOIMAGE    = &H0001
%DFCS_BUTTONRADIOMASK     = &H0002
%DFCS_BUTTONRADIO         = &H0004
%DFCS_BUTTON3STATE        = &H0008
%DFCS_BUTTONPUSH          = &H0010

%DFCS_INACTIVE            = &H0100
%DFCS_PUSHED              = &H0200
%DFCS_CHECKED             = &H0400

#IF (%WINVER >= &H0500)
%DFCS_TRANSPARENT         = &H0800
%DFCS_HOT                 = &H1000
#ENDIF ' %WINVER >= &H0500

%DFCS_ADJUSTRECT          = &H2000
%DFCS_FLAT                = &H4000
%DFCS_MONO                = &H8000??

DECLARE FUNCTION DrawFrameControl LIB "User32.dll" ALIAS "DrawFrameControl" _
    (BYVAL hDC AS DWORD, lpRect AS RECT, BYVAL un1 AS DWORD, _
    BYVAL un2 AS DWORD) AS LONG

' flags for DrawCaption
%DC_ACTIVE            = &H0001
%DC_SMALLCAP          = &H0002
%DC_ICON              = &H0004
%DC_TEXT              = &H0008
%DC_INBUTTON          = &H0010
#IF (%WINVER >= &H0500)
%DC_GRADIENT          = &H0020
#ENDIF ' %WINVER >= &H0500
#IF (%WIN32_WINNT >= &H0501)
%DC_BUTTONS           = &H1000
#ENDIF ' %WIN32_WINNT >= &H0501

DECLARE FUNCTION DrawCaption LIB "User32.dll" ALIAS "DrawCaption" _
    (BYVAL hWnd AS DWORD, BYVAL hDC AS DWORD, pcRect AS RECT, _
    BYVAL uFlags AS DWORD) AS LONG

%IDANI_OPEN        = 1
%IDANI_CAPTION     = 3

DECLARE FUNCTION DrawAnimatedRects LIB "User32.dll" ALIAS "DrawAnimatedRects" _
    (BYVAL hWnd AS DWORD, BYVAL idAni AS LONG, lprcFrom AS RECT, _
    lprcTo AS RECT) AS LONG

#ENDIF ' %WINVER >= &H0400



#IF NOT %DEF(%NOCLIPBOARD)

'
' Predefined Clipboard Formats
'
%CF_TEXT           = 1
%CF_BITMAP         = 2
%CF_METAFILEPICT   = 3
%CF_SYLK           = 4
%CF_DIF            = 5
%CF_TIFF           = 6
%CF_OEMTEXT        = 7
%CF_DIB            = 8
%CF_PALETTE        = 9
%CF_PENDATA        = 10
%CF_RIFF           = 11
%CF_WAVE           = 12
%CF_UNICODETEXT    = 13
%CF_ENHMETAFILE    = 14
#IF (%WINVER >= &H0400)
%CF_HDROP          = 15
%CF_LOCALE         = 16
#ENDIF ' %WINVER >= &H0400
#IF (%WINVER >= &H0500)
%CF_DIBV5          = 17
#ENDIF ' %WINVER >= &H0500

#IF (%WINVER >= &H0500)
%CF_MAX            = 18
#ELSEIF (%WINVER >= &H0400)
%CF_MAX            = 17
#ELSE
%CF_MAX            = 15
#ENDIF

%CF_OWNERDISPLAY     = &H0080
%CF_DSPTEXT          = &H0081
%CF_DSPBITMAP        = &H0082
%CF_DSPMETAFILEPICT  = &H0083
%CF_DSPENHMETAFILE   = &H008E

'
' "Private" formats don't get GlobalFree()'d
'
%CF_PRIVATEFIRST     = &H0200
%CF_PRIVATELAST      = &H02FF

'
' "GDIOBJ" formats do get DeleteObject()'d
'
%CF_GDIOBJFIRST      = &H0300
%CF_GDIOBJLAST       = &H03FF


#ENDIF ' IF NOT %NOCLIPBOARD

'
' Defines for the fVirt field of the Accelerator table structure.
'
%FVIRTKEY  = %TRUE          ' Assumed to be == %TRUE
%FNOINVERT = &H02
%FSHIFT    = &H04
%FCONTROL  = &H08
%FALT      = &H10

TYPE ACCEL_type WORD
    fVirt AS BYTE        ' Also called the flags field
    Key   AS WORD
    cmd   AS WORD
END TYPE

TYPE ACCELAPI
    ACCEL_type
END TYPE

TYPE PAINTSTRUCT
    hDC        AS DWORD
    fErase     AS LONG
    rcPaint    AS RECT
    fRestore   AS LONG
    fIncUpdate AS LONG
    rgbReserved(31) AS BYTE
END TYPE

TYPE WINDOWPLACEMENT
    length           AS DWORD
    flags            AS DWORD
    showCmd          AS DWORD
    ptMinPosition    AS POINT
    ptMaxPosition    AS POINT
    rcNormalPosition AS RECT
#IF %DEF(%MAC)
    rcDevice         AS RECT
#ENDIF
END TYPE

%WPF_SETMINPOSITION        = &H0001
%WPF_RESTORETOMAXIMIZED    = &H0002
#IF (%WIN32_WINNT >= &H0500)
%WPF_ASYNCWINDOWPLACEMENT  = &H0004
#ENDIF ' %WIN32_WINNT >= &H0500

#IF (%WINVER >= &H0400)

TYPE NMHDR
    hwndFrom AS DWORD
    idFrom   AS DWORD
    Code     AS LONG    ' NM_ code
    ' [Code is used for messages, so it really needs to be LONG]
END TYPE

TYPE STYLESTRUCT
    styleOld AS DWORD
    styleNew AS DWORD
END TYPE

#ENDIF ' %WINVER >= &H0400


'
' Owner draw control types
'
%ODT_MENU      = 1
%ODT_LISTBOX   = 2
%ODT_COMBOBOX  = 3
%ODT_BUTTON    = 4
#IF (%WINVER >= &H0400)
%ODT_STATIC    = 5
#ENDIF ' %WINVER >= &H0400

'
' Owner draw actions
'
%ODA_DRAWENTIRE  = &H0001
%ODA_SELECT      = &H0002
%ODA_FOCUS       = &H0004

'
' Owner draw state
'
%ODS_SELECTED    = &H0001
%ODS_GRAYED      = &H0002
%ODS_DISABLED    = &H0004
%ODS_CHECKED     = &H0008
%ODS_FOCUS       = &H0010
#IF (%WINVER >= &H0400)
%ODS_DEFAULT         = &H0020
%ODS_COMBOBOXEDIT    = &H1000
#ENDIF ' %WINVER >= &H0400
#IF (%WINVER >= &H0500)
%ODS_HOTLIGHT        = &H0040
%ODS_INACTIVE        = &H0080
#IF (%WIN32_WINNT >= &H0500)
%ODS_NOACCEL         = &H0100
%ODS_NOFOCUSRECT     = &H0200
#ENDIF ' %WIN32_WINNT >= &H0500
#ENDIF ' %WINVER >= &H0500

'
' MEASUREITEMSTRUCT for ownerdraw
'
TYPE MEASUREITEMSTRUCT
    CtlType    AS DWORD
    CtlID      AS DWORD
    itemID     AS DWORD
    itemWidth  AS DWORD
    itemHeight AS DWORD
    itemData   AS DWORD
END TYPE

'
' DRAWITEMSTRUCT for ownerdraw
'
TYPE DRAWITEMSTRUCT
    CtlType    AS DWORD
    CtlID      AS DWORD
    itemID     AS DWORD
    itemAction AS DWORD
    itemState  AS DWORD
    hwndItem   AS DWORD
    hDC        AS DWORD
    rcItem     AS RECT
    itemData   AS DWORD
END TYPE

'
' DELETEITEMSTRUCT for ownerdraw
'
TYPE DELETEITEMSTRUCT
    CtlType  AS DWORD
    CtlID    AS DWORD
    itemID   AS DWORD
    hwndItem AS DWORD
    itemData AS DWORD
END TYPE

'
' COMPAREITEMSTUCT for ownerdraw sorting
'
TYPE COMPAREITEMSTRUCT
    CtlType    AS DWORD
    CtlID      AS DWORD
    hwndItem   AS DWORD
    itemID1    AS DWORD
    itemData1  AS DWORD
    itemID2    AS DWORD
    itemData2  AS DWORD
    dwLocaleId AS DWORD
END TYPE

#IF NOT %DEF(%NOMSG)

'
' Message Function Templates
'

DECLARE FUNCTION GetMessageA LIB "User32.dll" ALIAS "GetMessageA" _
    (lpMsg AS MSG_type, BYVAL hWnd AS DWORD, BYVAL uMsgFilterMin AS DWORD, _
    BYVAL uMsgFilterMax AS DWORD) AS LONG

DECLARE FUNCTION GetMessageW LIB "User32.dll" ALIAS "GetMessageW" _
    (lpMsg AS MSG_type, BYVAL hWnd AS DWORD, BYVAL uMsgFilterMin AS DWORD, _
    BYVAL uMsgFilterMax AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetMessage LIB "User32.dll" ALIAS "GetMessageW" _
    (lpMsg AS MSG_type, BYVAL hWnd AS DWORD, BYVAL uMsgFilterMin AS DWORD, _
    BYVAL uMsgFilterMax AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetMessage LIB "User32.dll" ALIAS "GetMessageA" _
    (lpMsg AS MSG_type, BYVAL hWnd AS DWORD, BYVAL uMsgFilterMin AS DWORD, _
    BYVAL uMsgFilterMax AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION TranslateMessage LIB "User32.dll" ALIAS "TranslateMessage" _
    (lpMsg AS MSG_type) AS LONG

DECLARE FUNCTION DispatchMessageA LIB "User32.dll" ALIAS "DispatchMessageA" _
    (lpMsg AS MSG_type) AS LONG

DECLARE FUNCTION DispatchMessageW LIB "User32.dll" ALIAS "DispatchMessageW" _
    (lpMsg AS MSG_type) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION DispatchMessage LIB "User32.dll" ALIAS "DispatchMessageW" _
    (lpMsg AS MSG_type) AS LONG
#ELSE
DECLARE FUNCTION DispatchMessage LIB "User32.dll" ALIAS "DispatchMessageA" _
    (lpMsg AS MSG_type) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetMessageQueue LIB "User32.dll" ALIAS "SetMessageQueue" _
    (BYVAL cMessagesMax AS LONG) AS LONG

DECLARE FUNCTION PeekMessageA LIB "User32.dll" ALIAS "PeekMessageA" _
    (lpMsg AS MSG_type, BYVAL hWnd AS DWORD, BYVAL dwMsgFilterMin AS DWORD, _
    BYVAL dwMsgFilterMax AS DWORD, BYVAL dwRemoveMsg AS DWORD) AS LONG

DECLARE FUNCTION PeekMessageW LIB "User32.dll" ALIAS "PeekMessageW" _
    (lpMsg AS MSG_type, BYVAL hWnd AS DWORD, BYVAL dwMsgFilterMin AS DWORD, _
    BYVAL dwMsgFilterMax AS DWORD, BYVAL dwRemoveMsg AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION PeekMessage LIB "User32.dll" ALIAS "PeekMessageW" _
    (lpMsg AS MSG_type, BYVAL hWnd AS DWORD, BYVAL dwMsgFilterMin AS DWORD, _
    BYVAL dwMsgFilterMax AS DWORD, BYVAL dwRemoveMsg AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION PeekMessage LIB "User32.dll" ALIAS "PeekMessageA" _
    (lpMsg AS MSG_type, BYVAL hWnd AS DWORD, BYVAL dwMsgFilterMin AS DWORD, _
    BYVAL dwMsgFilterMax AS DWORD, BYVAL dwRemoveMsg AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE


'
' PeekMessage() Options
'
%PM_NOREMOVE       = &H0000
%PM_REMOVE         = &H0001
%PM_NOYIELD        = &H0002
' [the %PM_QS_INPUT equates have been moved to avoid a sequence issue]

#ENDIF ' NOT %NOMSG


DECLARE FUNCTION RegisterHotKey LIB "User32.dll" ALIAS "RegisterHotKey" _
    (BYVAL hWnd AS DWORD, BYVAL ID AS LONG, BYVAL fsModifiers AS DWORD, _
    BYVAL vk AS DWORD) AS LONG

DECLARE FUNCTION UnregisterHotKey LIB "User32.dll" ALIAS "UnregisterHotKey" _
    (BYVAL hWnd AS DWORD, BYVAL ID AS LONG) AS LONG

%MOD_ALT       = &H0001
%MOD_CONTROL   = &H0002
%MOD_SHIFT     = &H0004
%MOD_WIN       = &H0008
#IF (%WINVER >= &H0601)
%MOD_NOREPEAT  = &H4000
#ENDIF  ' %WINVER >= &H0601


%IDHOT_SNAPWINDOW     = -1    ' SHIFT-PRINTSCRN
%IDHOT_SNAPDESKTOP    = -2    ' PRINTSCRN

#IF (%WINVER >= &H0400)

%ENDSESSION_LOGOFF   = &H80000000???

%ENDSESSION_CRITICAL = &H40000000

%ENDSESSION_CLOSEAPP = &H00000001
#ENDIF ' %WINVER >= &H0400

%EWX_LOGOFF         = 0
%EWX_SHUTDOWN       = &H00000001
%EWX_REBOOT         = &H00000002
%EWX_FORCE          = &H00000004
%EWX_POWEROFF       = &H00000008
#IF (%WIN32_WINNT >= &H0500)
%EWX_FORCEIFHUNG    = &H00000010
#ENDIF ' %WIN32_WINNT >= &H0500
%EWX_QUICKRESOLVE   = &H00000020
#IF (%WIN32_WINNT >= &H0600)
%EWX_RESTARTAPPS    = &H00000040
#ENDIF ' %WIN32_WINNT >= &H0600


FUNCTION ExitWindows (BYVAL dwReserved AS LONG, BYVAL uReserved AS DWORD) AS LONG
    FUNCTION = ExitWindowsEx(%EWX_LOGOFF,&HFFFFFFFF???)
END FUNCTION

DECLARE FUNCTION ExitWindowsEx LIB "User32.dll" ALIAS "ExitWindowsEx" _
    (BYVAL uFlags AS DWORD, BYVAL dwReserved AS DWORD) AS LONG

DECLARE FUNCTION SwapMouseButton LIB "User32.dll" ALIAS "SwapMouseButton" _
    (BYVAL bSwap AS LONG) AS LONG

DECLARE FUNCTION GetMessagePos LIB "User32.dll" ALIAS "GetMessagePos" () _
    AS DWORD

DECLARE FUNCTION GetMessageTime LIB "User32.dll" ALIAS "GetMessageTime" () _
    AS LONG

DECLARE FUNCTION GetMessageExtraInfo LIB "User32.dll" _
    ALIAS "GetMessageExtraInfo" () AS LONG

#IF (%WIN32_WINNT >= &H0501)

DECLARE FUNCTION IsWow64Message LIB "User32.dll" ALIAS "IsWow64Message" () _
    AS LONG

#ENDIF ' %WIN32_WINNT >= &H0501

#IF (%WINVER >= &H0400)

DECLARE FUNCTION SetMessageExtraInfo LIB "User32.dll" _
    ALIAS "SetMessageExtraInfo" (BYVAL lParam AS LONG) AS LONG

#ENDIF ' %WINVER >= &H0400

DECLARE FUNCTION SendMessageA LIB "User32.dll" ALIAS "SendMessageA" _
    (BYVAL hWnd AS DWORD, BYVAL dwMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION SendMessageW LIB "User32.dll" ALIAS "SendMessageW" _
    (BYVAL hWnd AS DWORD, BYVAL dwMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SendMessage LIB "User32.dll" ALIAS "SendMessageW" _
    (BYVAL hWnd AS DWORD, BYVAL dwMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG
#ELSE
DECLARE FUNCTION SendMessage LIB "User32.dll" ALIAS "SendMessageA" _
    (BYVAL hWnd AS DWORD, BYVAL dwMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SendMessageTimeoutA LIB "User32.dll" _
    ALIAS "SendMessageTimeoutA" (BYVAL hWnd AS DWORD, BYVAL dwMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG, BYVAL fuFlags AS DWORD, _
    BYVAL uTimeout AS DWORD, lpdwResult AS DWORD) AS LONG

DECLARE FUNCTION SendMessageTimeoutW LIB "User32.dll" _
    ALIAS "SendMessageTimeoutW" (BYVAL hWnd AS DWORD, BYVAL dwMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG, BYVAL fuFlags AS DWORD, _
    BYVAL uTimeout AS DWORD, lpdwResult AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SendMessageTimeout LIB "User32.dll" _
    ALIAS "SendMessageTimeoutW" (BYVAL hWnd AS DWORD, BYVAL dwMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG, BYVAL fuFlags AS DWORD, _
    BYVAL uTimeout AS DWORD, lpdwResult AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SendMessageTimeout LIB "User32.dll" _
    ALIAS "SendMessageTimeoutA" (BYVAL hWnd AS DWORD, BYVAL dwMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG, BYVAL fuFlags AS DWORD, _
    BYVAL uTimeout AS DWORD, lpdwResult AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SendNotifyMessageA LIB "User32.dll" _
    ALIAS "SendNotifyMessageA" (BYVAL hWnd AS DWORD, BYVAL dwMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION SendNotifyMessageW LIB "User32.dll" _
    ALIAS "SendNotifyMessageW" (BYVAL hWnd AS DWORD, BYVAL dwMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SendNotifyMessage LIB "User32.dll" _
    ALIAS "SendNotifyMessageW" (BYVAL hWnd AS DWORD, BYVAL dwMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG
#ELSE
DECLARE FUNCTION SendNotifyMessage LIB "User32.dll" _
    ALIAS "SendNotifyMessageA" (BYVAL hWnd AS DWORD, BYVAL dwMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SendMessageCallbackA LIB "User32.dll" _
    ALIAS "SendMessageCallbackA" (BYVAL hWnd AS DWORD, BYVAL dwMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG, _
    BYVAL lpResultCallBack AS DWORD, BYVAL dwData AS DWORD) AS LONG

DECLARE FUNCTION SendMessageCallbackW LIB "User32.dll" _
    ALIAS "SendMessageCallbackW" (BYVAL hWnd AS DWORD, BYVAL dwMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG, _
    BYVAL lpResultCallBack AS DWORD, BYVAL dwData AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SendMessageCallback LIB "User32.dll" _
    ALIAS "SendMessageCallbackW" (BYVAL hWnd AS DWORD, BYVAL dwMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG, _
    BYVAL lpResultCallBack AS DWORD, BYVAL dwData AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SendMessageCallback LIB "User32.dll" _
    ALIAS "SendMessageCallbackA" (BYVAL hWnd AS DWORD, BYVAL dwMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG, _
    BYVAL lpResultCallBack AS DWORD, BYVAL dwData AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

#IF (%WIN32_WINNT >= &H0501)

TYPE BSMINFO
    cbSize AS DWORD
    hdesk  AS DWORD
    hwnd   AS DWORD
    luid   AS QUAD  ' LUID
END TYPE

DECLARE FUNCTION BroadcastSystemMessageExA LIB "User32.dll" _
    ALIAS "BroadcastSystemMessageExA" (BYVAL dwFlags AS DWORD, _
    pdwRecipients AS DWORD, BYVAL uiMessage AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG, pBSMInfo AS BSMINFO) AS LONG

DECLARE FUNCTION BroadcastSystemMessageExW LIB "User32.dll" _
    ALIAS "BroadcastSystemMessageExW" (BYVAL dwFlags AS DWORD, _
    pdwRecipients AS DWORD, BYVAL uiMessage AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG, pBSMInfo AS BSMINFO) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION BroadcastSystemMessageEx LIB "User32.dll" _
    ALIAS "BroadcastSystemMessageExW" (BYVAL dwFlags AS DWORD, _
    pdwRecipients AS DWORD, BYVAL uiMessage AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG, pBSMInfo AS BSMINFO) AS LONG
#ELSE
DECLARE FUNCTION BroadcastSystemMessageEx LIB "User32.dll" _
    ALIAS "BroadcastSystemMessageExA" (BYVAL dwFlags AS DWORD, _
    pdwRecipients AS DWORD, BYVAL uiMessage AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG, pBSMInfo AS BSMINFO) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' %WIN32_WINNT >= &H0501

#IF (%WINVER >= &H0400)

#IF %DEF(%WIN32_WINNT)

DECLARE FUNCTION BroadcastSystemMessageA LIB "User32.dll" _
    ALIAS "BroadcastSystemMessageA" (BYVAL dwFlags AS DWORD, _
    lpInfo AS DWORD, BYVAL uiMessage AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION BroadcastSystemMessageW LIB "User32.dll" _
    ALIAS "BroadcastSystemMessageW" (BYVAL dwFlags AS DWORD, _
    lpInfo AS DWORD, BYVAL uiMessage AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION BroadcastSystemMessage LIB "User32.dll" _
    ALIAS "BroadcastSystemMessageW" (BYVAL dwFlags AS DWORD, _
    lpInfo AS DWORD, BYVAL uiMessage AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG
#ELSE
DECLARE FUNCTION BroadcastSystemMessage LIB "User32.dll" _
    ALIAS "BroadcastSystemMessageA" (BYVAL dwFlags AS DWORD, _
    lpInfo AS DWORD, BYVAL uiMessage AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

#ELSEIF %DEF(%WIN32_WINDOWS)

' The Win95 version isn't A/W decorated
DECLARE FUNCTION BroadcastSystemMessage LIB "User32.dll" _
    ALIAS "BroadcastSystemMessage" (BYVAL dwFlags AS DWORD, _
    lpInfo AS DWORD, BYVAL uiMessage AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

#ENDIF ' %DEF(%WIN32_WINNT)

'Broadcast Special Message Recipient list
%BSM_ALLCOMPONENTS       = &H00000000
%BSM_VXDS                = &H00000001
%BSM_NETDRIVER           = &H00000002
%BSM_INSTALLABLEDRIVERS  = &H00000004
%BSM_APPLICATIONS        = &H00000008
%BSM_ALLDESKTOPS         = &H00000010

'Broadcast Special Message Flags
%BSF_QUERY               = &H00000001
%BSF_IGNORECURRENTTASK   = &H00000002
%BSF_FLUSHDISK           = &H00000004
%BSF_NOHANG              = &H00000008
%BSF_POSTMESSAGE         = &H00000010
%BSF_FORCEIFHUNG         = &H00000020
%BSF_NOTIMEOUTIFNOTHUNG  = &H00000040
#IF (%WIN32_WINNT >= &H0500)
%BSF_ALLOWSFW            = &H00000080
%BSF_SENDNOTIFYMESSAGE   = &H00000100
#ENDIF ' %WIN32_WINNT >= &H0500
#IF (%WIN32_WINNT >= &H0501)
%BSF_RETURNHDESK         = &H00000200
%BSF_LUID                = &H00000400
#ENDIF ' %WIN32_WINNT >= &H0501

%BROADCAST_QUERY_DENY    = &H424D5144  ' Return this value to deny a query.
#ENDIF ' %WINVER >= &H0400

' RegisterDeviceNotification

#IF (%WINVER >= &H0500)
%DEVICE_NOTIFY_WINDOW_HANDLE  = &H00000000
%DEVICE_NOTIFY_SERVICE_HANDLE = &H00000001
#IF (%WIN32_WINNT >= &H0501)
%DEVICE_NOTIFY_ALL_INTERFACE_CLASSES  = &H00000004
#ENDIF ' %WIN32_WINNT >= &H0501

DECLARE FUNCTION RegisterDeviceNotificationA LIB "User32.dll" _
    ALIAS "RegisterDeviceNotificationA" (BYVAL hRecipient AS DWORD, _
    NotificationFilter AS DWORD, BYVAL Flags AS DWORD) AS DWORD

DECLARE FUNCTION RegisterDeviceNotificationW LIB "User32.dll" _
    ALIAS "RegisterDeviceNotificationW" (BYVAL hRecipient AS DWORD, _
    NotificationFilter AS DWORD, BYVAL Flags AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION RegisterDeviceNotification LIB "User32.dll" _
    ALIAS "RegisterDeviceNotificationW" (BYVAL hRecipient AS DWORD, _
    NotificationFilter AS DWORD, BYVAL Flags AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION RegisterDeviceNotification LIB "User32.dll" _
    ALIAS "RegisterDeviceNotificationA" (BYVAL hRecipient AS DWORD, _
    NotificationFilter AS DWORD, BYVAL Flags AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION UnregisterDeviceNotification LIB "User32.dll" _
    ALIAS "UnregisterDeviceNotification" (BYVAL hDev AS DWORD) AS LONG

#IF (%WIN32_WINNT >= &H0502)

DECLARE FUNCTION RegisterPowerSettingNotification LIB "User32.dll" _
    ALIAS "RegisterPowerSettingNotification" (BYVAL hRecipient AS DWORD, _
    PowerSettingGuid AS GUID, BYVAL Flags AS DWORD) AS DWORD

DECLARE FUNCTION UnregisterPowerSettingNotification LIB "User32.dll" _
    ALIAS "UnregisterPowerSettingNotification" (BYVAL hPow AS DWORD) AS LONG

#ENDIF ' (%WIN32_WINNT >= &H0502)
#ENDIF ' %WINVER >= &H0500


DECLARE FUNCTION PostMessageA LIB "User32.dll" ALIAS "PostMessageA" _
    (BYVAL hWnd AS DWORD, BYVAL dwMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION PostMessageW LIB "User32.dll" ALIAS "PostMessageW" _
    (BYVAL hWnd AS DWORD, BYVAL dwMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION PostMessage LIB "User32.dll" ALIAS "PostMessageW" _
    (BYVAL hWnd AS DWORD, BYVAL dwMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG
#ELSE
DECLARE FUNCTION PostMessage LIB "User32.dll" ALIAS "PostMessageA" _
    (BYVAL hWnd AS DWORD, BYVAL dwMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION PostThreadMessageA LIB "User32.dll" _
    ALIAS "PostThreadMessageA" (BYVAL idThread AS DWORD, BYVAL uMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION PostThreadMessageW LIB "User32.dll" _
    ALIAS "PostThreadMessageW" (BYVAL idThread AS DWORD, BYVAL uMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION PostThreadMessage LIB "User32.dll" _
    ALIAS "PostThreadMessageW" (BYVAL idThread AS DWORD, BYVAL uMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG
#ELSE
DECLARE FUNCTION PostThreadMessageA LIB "User32.dll" _
    ALIAS "PostThreadMessageA" (BYVAL idThread AS DWORD, BYVAL uMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION PostAppMessageA LIB "User32.dll" _
    ALIAS "PostThreadMessageA" (BYVAL idThread AS DWORD, BYVAL uMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION PostAppMessageW LIB "User32.dll" _
    ALIAS "PostThreadMessageW" (BYVAL idThread AS DWORD, BYVAL uMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION PostAppMessage LIB "User32.dll" _
    ALIAS "PostThreadMessageW" (BYVAL idThread AS DWORD, BYVAL uMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG
#ELSE
DECLARE FUNCTION PostAppMessage LIB "User32.dll" _
    ALIAS "PostThreadMessageA" (BYVAL idThread AS DWORD, BYVAL uMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

'
' Special DWORD value for use with PostMessage() and SendMessage()
'
%HWND_BROADCAST = &Hffffffff??

#IF (%WINVER >= &H0500)
%HWND_MESSAGE   = (-3 AND &HFFFFFFFF???) 'LO(DWORD,-3)
#ENDIF ' %WINVER >= &H0500


DECLARE FUNCTION AttachThreadInput LIB "User32.dll" ALIAS "AttachThreadInput" _
    (BYVAL idAttach AS DWORD, BYVAL idAttachTo AS DWORD, _
    BYVAL fAttach AS LONG) AS LONG

DECLARE FUNCTION ReplyMessage LIB "User32.dll" ALIAS "ReplyMessage" _
    (BYVAL lReply AS LONG) AS LONG

DECLARE FUNCTION WaitMessage LIB "User32.dll" ALIAS "WaitMessage" () AS LONG

DECLARE FUNCTION WaitForInputIdle LIB "User32.dll" ALIAS "WaitForInputIdle" _
    (BYVAL hProcess AS DWORD, BYVAL dwMilliseconds AS DWORD) AS DWORD

DECLARE FUNCTION DefWindowProcA LIB "User32.dll" ALIAS "DefWindowProcA" _
    (BYVAL hWnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION DefWindowProcW LIB "User32.dll" ALIAS "DefWindowProcW" _
    (BYVAL hWnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION DefWindowProc LIB "User32.dll" ALIAS "DefWindowProcW" _
    (BYVAL hWnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG
#ELSE
DECLARE FUNCTION DefWindowProc LIB "User32.dll" ALIAS "DefWindowProcA" _
    (BYVAL hWnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE SUB PostQuitMessage LIB "User32.dll" ALIAS "PostQuitMessage" _
    (BYVAL nExitCode AS LONG)

DECLARE FUNCTION CallWindowProcA LIB "User32.dll" ALIAS "CallWindowProcA" _
    (BYVAL lpPrevWndFunc AS DWORD, BYVAL hWnd AS DWORD, BYVAL uMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION CallWindowProcW LIB "User32.dll" ALIAS "CallWindowProcW" _
    (BYVAL lpPrevWndFunc AS DWORD, BYVAL hWnd AS DWORD, BYVAL uMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CallWindowProc LIB "User32.dll" ALIAS "CallWindowProcW" _
    (BYVAL lpPrevWndFunc AS DWORD, BYVAL hWnd AS DWORD, BYVAL uMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG
#ELSE
DECLARE FUNCTION CallWindowProc LIB "User32.dll" ALIAS "CallWindowProcA" _
    (BYVAL lpPrevWndFunc AS DWORD, BYVAL hWnd AS DWORD, BYVAL uMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION InSendMessage LIB "User32.dll" ALIAS "InSendMessage" () _
    AS LONG

#IF (%WINVER >= &H0500)

DECLARE FUNCTION InSendMessageEx LIB "User32.dll" ALIAS "InSendMessageEx" _
    (lpReserved AS DWORD) AS DWORD

'
' InSendMessageEx return value
'
%ISMEX_NOSEND    = &H00000000
%ISMEX_SEND      = &H00000001
%ISMEX_NOTIFY    = &H00000002
%ISMEX_CALLBACK  = &H00000004
%ISMEX_REPLIED   = &H00000008
#ENDIF ' %WINVER >= &H0500

DECLARE FUNCTION GetDoubleClickTime LIB "User32.dll" _
    ALIAS "GetDoubleClickTime" () AS DWORD

DECLARE FUNCTION SetDoubleClickTime LIB "User32.dll" _
    ALIAS "SetDoubleClickTime" (BYVAL uInterval AS DWORD) AS LONG

DECLARE FUNCTION RegisterClassA LIB "User32.dll" ALIAS "RegisterClassA" _
    (pcWndClass AS WNDCLASS) AS WORD

DECLARE FUNCTION RegisterClassW LIB "User32.dll" ALIAS "RegisterClassW" _
    (pcWndClass AS WNDCLASS) AS WORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION RegisterClass LIB "User32.dll" ALIAS "RegisterClassW" _
    (pcWndClass AS WNDCLASS) AS WORD
#ELSE
DECLARE FUNCTION RegisterClass LIB "User32.dll" ALIAS "RegisterClassA" _
    (pcWndClass AS WNDCLASS) AS WORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION UnregisterClassA LIB "User32.dll" ALIAS "UnregisterClassA" _
    (lpClassName AS ASCIIZ, OPTIONAL BYVAL hInstance AS DWORD) AS LONG

DECLARE FUNCTION UnregisterClassW LIB "User32.dll" ALIAS "UnregisterClassW" _
    (lpClassName AS WSTRINGZ, OPTIONAL BYVAL hInstance AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION UnregisterClass LIB "User32.dll" ALIAS "UnregisterClassW" _
    (lpClassName AS WSTRINGZ, OPTIONAL BYVAL hInstance AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION UnregisterClass LIB "User32.dll" ALIAS "UnregisterClassA" _
    (lpClassName AS ASCIIZ, OPTIONAL BYVAL hInstance AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetClassInfoA LIB "User32.dll" ALIAS "GetClassInfoA" _
    (BYVAL hInstance AS DWORD, lpClassName AS ASCIIZ, _
    lpWndClass AS WNDCLASSA) AS LONG

DECLARE FUNCTION GetClassInfoW LIB "User32.dll" ALIAS "GetClassInfoW" _
    (BYVAL hInstance AS DWORD, lpClassName AS WSTRINGZ, _
    lpWndClass AS WNDCLASSW) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetClassInfo LIB "User32.dll" ALIAS "GetClassInfoW" _
    (BYVAL hInstance AS DWORD, lpClassName AS WSTRINGZ, _
    lpWndClass AS WNDCLASSW) AS LONG
#ELSE
DECLARE FUNCTION GetClassInfo LIB "User32.dll" ALIAS "GetClassInfoA" _
    (BYVAL hInstance AS DWORD, lpClassName AS ASCIIZ, _
    lpWndClass AS WNDCLASSA) AS LONG
#ENDIF ' NOT %UNICODE

#IF (%WINVER >= &H0400)

DECLARE FUNCTION RegisterClassExA LIB "User32.dll" ALIAS "RegisterClassExA" _
    (pcWndClassEx AS WNDCLASSEXA) AS WORD

DECLARE FUNCTION RegisterClassExW LIB "User32.dll" ALIAS "RegisterClassExW" _
    (pcWndClassEx AS WNDCLASSEXW) AS WORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION RegisterClassEx LIB "User32.dll" ALIAS "RegisterClassExW" _
    (pcWndClassEx AS WNDCLASSEXW) AS WORD
#ELSE
DECLARE FUNCTION RegisterClassEx LIB "User32.dll" ALIAS "RegisterClassExA" _
    (pcWndClassEx AS WNDCLASSEXA) AS WORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetClassInfoExA LIB "User32.dll" ALIAS "GetClassInfoExA" _
    (BYVAL hInst AS DWORD, lpszClass AS ASCIIZ, lpWndClass AS WNDCLASSEXA) _
    AS LONG

DECLARE FUNCTION GetClassInfoExW LIB "User32.dll" ALIAS "GetClassInfoExW" _
    (BYVAL hInst AS DWORD, lpszClass AS WSTRINGZ, lpWndClass AS WNDCLASSEXW) _
    AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetClassInfoEx LIB "User32.dll" ALIAS "GetClassInfoExW" _
    (BYVAL hInst AS DWORD, lpszClass AS WSTRINGZ, lpWndClass AS WNDCLASSEXW) _
    AS LONG
#ELSE
DECLARE FUNCTION GetClassInfoEx LIB "User32.dll" ALIAS "GetClassInfoExA" _
    (BYVAL hInst AS DWORD, lpszClass AS ASCIIZ, lpWndClass AS WNDCLASSEXA) _
    AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' %WINVER >= &H0400

%CW_USEDEFAULT = &H80000000& ' long

'
' Special value for CreateWindow, et al.
'
%HWND_DESKTOP = 0

#IF (%WIN32_WINNT >= &H0501)
DECLARE FUNCTION PREGISTERCLASSNAMEW (lpwsz AS WSTRINGZ) AS BYTE ' BOOLEAN
#ENDIF

DECLARE FUNCTION CreateWindowExA LIB "User32.dll" ALIAS "CreateWindowExA" _
    (BYVAL dwExStyle AS DWORD, lpClassName AS ASCIIZ, _
    lpWindowName AS ASCIIZ, BYVAL dwStyle AS DWORD, BYVAL x AS LONG, _
    BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
    BYVAL hWndParent AS DWORD, BYVAL hMenu AS DWORD, _
    BYVAL hInstance AS DWORD, lpParam AS ANY) AS DWORD

DECLARE FUNCTION CreateWindowExW LIB "User32.dll" ALIAS "CreateWindowExW" _
    (BYVAL dwExStyle AS DWORD, lpClassName AS WSTRINGZ, _
    lpWindowName AS WSTRINGZ, BYVAL dwStyle AS DWORD, BYVAL x AS LONG, _
    BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
    BYVAL hWndParent AS DWORD, BYVAL hMenu AS DWORD, _
    BYVAL hInstance AS DWORD, lpParam AS ANY) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateWindowEx LIB "User32.dll" ALIAS "CreateWindowExW" _
    (BYVAL dwExStyle AS DWORD, lpClassName AS WSTRINGZ, _
    lpWindowName AS WSTRINGZ, BYVAL dwStyle AS DWORD, BYVAL x AS LONG, _
    BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
    BYVAL hWndParent AS DWORD, BYVAL hMenu AS DWORD, _
    BYVAL hInstance AS DWORD, lpParam AS ANY) AS DWORD
#ELSE
DECLARE FUNCTION CreateWindowEx LIB "User32.dll" ALIAS "CreateWindowExA" _
    (BYVAL dwExStyle AS DWORD, lpClassName AS ASCIIZ, _
    lpWindowName AS ASCIIZ, BYVAL dwStyle AS DWORD, BYVAL x AS LONG, _
    BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
    BYVAL hWndParent AS DWORD, BYVAL hMenu AS DWORD, _
    BYVAL hInstance AS DWORD, lpParam AS ANY) AS DWORD
#ENDIF ' NOT %UNICODE

FUNCTION CreateWindowA ( _
    lpClassName      AS ASCIIZ, _
    lpWindowName     AS ASCIIZ, _
    BYVAL dwStyle    AS DWORD, _
    BYVAL x          AS LONG, _
    BYVAL y          AS LONG, _
    BYVAL nWidth     AS LONG, _
    BYVAL nHeight    AS LONG, _
    BYVAL hWndParent AS DWORD, _
    BYVAL hMenu      AS DWORD, _
    BYVAL hInstance  AS DWORD, _
    BYVAL lpParam    AS DWORD _
    ) AS DWORD

    FUNCTION = CreateWindowExA(0, lpClassName, lpWindowName, dwStyle, _
        x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)

END FUNCTION

FUNCTION CreateWindowW ( _
    lpClassName      AS WSTRINGZ, _
    lpWindowName     AS WSTRINGZ, _
    BYVAL dwStyle    AS DWORD, _
    BYVAL x          AS LONG, _
    BYVAL y          AS LONG, _
    BYVAL nWidth     AS LONG, _
    BYVAL nHeight    AS LONG, _
    BYVAL hWndParent AS DWORD, _
    BYVAL hMenu      AS DWORD, _
    BYVAL hInstance  AS DWORD, _
    BYVAL lpParam    AS DWORD _
    ) AS DWORD

    FUNCTION = CreateWindowExW(0, lpClassName, lpWindowName, dwStyle, _
        x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)

END FUNCTION

#IF %DEF(%UNICODE)
FUNCTION CreateWindow ( _
    lpClassName      AS WSTRINGZ, _
    lpWindowName     AS WSTRINGZ, _
    BYVAL dwStyle    AS DWORD, _
    BYVAL x          AS LONG, _
    BYVAL y          AS LONG, _
    BYVAL nWidth     AS LONG, _
    BYVAL nHeight    AS LONG, _
    BYVAL hWndParent AS DWORD, _
    BYVAL hMenu      AS DWORD, _
    BYVAL hInstance  AS DWORD, _
    BYVAL lpParam    AS DWORD _
    ) AS DWORD

    FUNCTION = CreateWindowExW(0, lpClassName, lpWindowName, dwStyle, _
        x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)

END FUNCTION
#ELSE
FUNCTION CreateWindow ( _
    lpClassName      AS ASCIIZ, _
    lpWindowName     AS ASCIIZ, _
    BYVAL dwStyle    AS DWORD, _
    BYVAL x          AS LONG, _
    BYVAL y          AS LONG, _
    BYVAL nWidth     AS LONG, _
    BYVAL nHeight    AS LONG, _
    BYVAL hWndParent AS DWORD, _
    BYVAL hMenu      AS DWORD, _
    BYVAL hInstance  AS DWORD, _
    BYVAL lpParam    AS DWORD _
    ) AS DWORD

    FUNCTION = CreateWindowExA(0, lpClassName, lpWindowName, dwStyle, _
        x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)

END FUNCTION

#ENDIF ' NOT %UNICODE

DECLARE FUNCTION IsWindow LIB "User32.dll" ALIAS "IsWindow" _
    (OPTIONAL BYVAL hWnd AS DWORD) AS LONG

DECLARE FUNCTION IsMenu LIB "User32.dll" ALIAS "IsMenu" _
    (BYVAL hMenu AS DWORD) AS LONG

DECLARE FUNCTION IsChild LIB "User32.dll" ALIAS "IsChild" _
    (BYVAL hwndParent AS DWORD, BYVAL hWnd AS DWORD) AS LONG

DECLARE FUNCTION DestroyWindow LIB "User32.dll" ALIAS "DestroyWindow" _
    (BYVAL hWnd AS DWORD) AS LONG

DECLARE FUNCTION ShowWindow LIB "User32.dll" ALIAS "ShowWindow" _
    (BYVAL hWnd AS DWORD, BYVAL nCmdShow AS LONG) AS LONG

#IF (%WINVER >= &H0500)

DECLARE FUNCTION AnimateWindow LIB "User32.dll" ALIAS "AnimateWindow" _
    (BYVAL hWnd AS DWORD, BYVAL dwTime AS DWORD, BYVAL dwFlags AS DWORD) _
    AS LONG

#ENDIF ' %WINVER >= &H0500

#IF (%WIN32_WINNT >= &H0500)
#IF %DEF(%WINGDI) AND (NOT %DEF(%NOGDI))

DECLARE FUNCTION UpdateLayeredWindow LIB "User32.dll" _
    ALIAS "UpdateLayeredWindow" (BYVAL hWnd AS DWORD, BYVAL hdcDst AS DWORD, _
    pptDst AS POINT, psize AS SIZEL, BYVAL hdcSrc AS DWORD, pptSrc AS POINT, _
    BYVAL crKey AS DWORD, pblend AS BLENDFUNCTION, BYVAL dwFlags AS DWORD) _
    AS LONG

'
' Layered Window Update information
'
TYPE UPDATELAYEREDWINDOWINFO
    cbSize   AS DWORD
    hdcDst   AS DWORD
    pptDst   AS POINT PTR
    psize    AS SIZEL PTR
    hdcSrc   AS DWORD
    pptSrc   AS POINT PTR
    crKey    AS DWORD
    pblend   AS BLENDFUNCTION PTR
    dwFlags  AS DWORD
    prcDirty AS RECT PTR
END TYPE


DECLARE FUNCTION UpdateLayeredWindowIndirect LIB "User32.dll" _
    ALIAS "UpdateLayeredWindowIndirect" (BYVAL hWnd AS DWORD, _
    pULWInfo AS UPDATELAYEREDWINDOWINFO) AS LONG

#ENDIF ' #IF %DEF(%WINGDI) AND (NOT %DEF(%NOGDI))

#IF (%WIN32_WINNT >= &H0501)
DECLARE FUNCTION GetLayeredWindowAttributes LIB "User32.dll" _
    ALIAS "GetLayeredWindowAttributes" (BYVAL hwnd AS DWORD, _
    pcrKey AS DWORD, pbAlpha AS BYTE, pdwFlags AS DWORD) AS LONG

%PW_CLIENTONLY         = &H00000001

DECLARE FUNCTION PrintWindow LIB "User32.dll" ALIAS "PrintWindow" _
    (BYVAL hwnd AS DWORD, BYVAL hdcBlt AS DWORD, BYVAL nFlags AS DWORD) AS LONG

#ENDIF ' %WIN32_WINNT >= &H0501

DECLARE FUNCTION SetLayeredWindowAttributes LIB "User32.dll" _
    ALIAS "SetLayeredWindowAttributes" (BYVAL hwnd AS DWORD, _
    BYVAL crKey AS DWORD, BYVAL bAlpha AS BYTE, BYVAL dwFlags AS DWORD) AS LONG

%LWA_COLORKEY          = &H00000001
%LWA_ALPHA             = &H00000002


%ULW_COLORKEY          = &H00000001
%ULW_ALPHA             = &H00000002
%ULW_OPAQUE            = &H00000004

%ULW_EX_NORESIZE       = &H00000008

#ENDIF ' %WIN32_WINNT >= &H0500


#IF (%WINVER >= &H0400)

DECLARE FUNCTION ShowWindowAsync LIB "User32.dll" ALIAS "ShowWindowAsync" _
    (BYVAL hWnd AS DWORD, BYVAL nCmdShow AS LONG) AS LONG

#ENDIF ' %WINVER >= &H0400

DECLARE FUNCTION FlashWindow LIB "User32.dll" ALIAS "FlashWindow" _
    (BYVAL hWnd AS DWORD, BYVAL bInvert AS LONG) AS LONG

#IF (%WINVER >= &H0500)

TYPE FLASHWINDOW_type
    cbSize    AS DWORD
    hwnd      AS DWORD
    dwFlags   AS DWORD
    uCount    AS DWORD
    dwTimeout AS DWORD
END TYPE

' [legacy]
TYPE FLASHWINDOWAPI
    FLASHWINDOW_type
END TYPE

DECLARE FUNCTION FlashWindowEx LIB "User32.dll" ALIAS "FlashWindowEx" _
    (pfwi AS FLASHWINDOWAPI) AS LONG

%FLASHW_STOP       = 0
%FLASHW_CAPTION    = &H00000001
%FLASHW_TRAY       = &H00000002
%FLASHW_ALL        = (%FLASHW_CAPTION OR %FLASHW_TRAY)
%FLASHW_TIMER      = &H00000004
%FLASHW_TIMERNOFG  = &H0000000C

#ENDIF ' %WINVER >= &H0500

DECLARE FUNCTION ShowOwnedPopups LIB "User32.dll" ALIAS "ShowOwnedPopups" _
    (BYVAL hWnd AS DWORD, BYVAL fShow AS LONG) AS LONG

DECLARE FUNCTION OpenIcon LIB "User32.dll" ALIAS "OpenIcon" _
    (BYVAL hWnd AS DWORD) AS LONG

DECLARE FUNCTION CloseWindow LIB "User32.dll" ALIAS "CloseWindow" _
    (BYVAL hWnd AS DWORD) AS LONG

DECLARE FUNCTION MoveWindow LIB "User32.dll" ALIAS "MoveWindow" _
    (BYVAL hWnd AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL bRepaint AS LONG) _
    AS LONG

DECLARE FUNCTION SetWindowPos LIB "User32.dll" ALIAS "SetWindowPos" _
    (BYVAL hWnd AS DWORD, BYVAL hWndInsertAfter AS DWORD, BYVAL x AS LONG, _
    BYVAL y AS LONG, BYVAL cx AS LONG, BYVAL cy AS LONG, _
    BYVAL wFlags AS DWORD) AS LONG

DECLARE FUNCTION GetWindowPlacement LIB "User32.dll" _
    ALIAS "GetWindowPlacement" (BYVAL hWnd AS DWORD, _
    lpwndpl AS WINDOWPLACEMENT) AS LONG

DECLARE FUNCTION SetWindowPlacement LIB "User32.dll" _
    ALIAS "SetWindowPlacement" (BYVAL hWnd AS DWORD, _
    lpwndpl AS WINDOWPLACEMENT) AS LONG

#IF (%WIN32_WINNT >= &H0601)
%WDA_NONE      = &H00000000
%WDA_MONITOR   = &H00000001

DECLARE FUNCTION GetWindowDisplayAffinity LIB "User32.dll" _
    ALIAS "GetWindowDisplayAffinity" (BYVAL hwnd AS DWORD, _
    pdwAffinity AS DWORD) AS LONG

DECLARE FUNCTION SetWindowDisplayAffinity LIB "User32.dll" _
    ALIAS "SetWindowDisplayAffinity" (BYVAL hwnd AS DWORD, _
    BYVAL dwAffinity AS DWORD) AS LONG

#ENDIF  ' %WIN32_WINNT >= &H0601

#IF NOT %DEF(%NODEFERWINDOWPOS)

DECLARE FUNCTION BeginDeferWindowPos LIB "User32.dll" _
    ALIAS "BeginDeferWindowPos" (BYVAL nNumWindows AS LONG) AS DWORD

DECLARE FUNCTION DeferWindowPos LIB "User32.dll" ALIAS "DeferWindowPos" _
    (BYVAL hWinPosInfo AS DWORD, BYVAL hWnd AS DWORD, _
    BYVAL hWndInsertAfter AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    BYVAL cx AS LONG, BYVAL cy AS LONG, BYVAL wFlags AS DWORD) AS DWORD

DECLARE FUNCTION EndDeferWindowPos LIB "User32.dll" ALIAS "EndDeferWindowPos" _
    (BYVAL hWinPosInfo AS DWORD) AS LONG

#ENDIF ' NOT %NODEFERWINDOWPOS

DECLARE FUNCTION IsWindowVisible LIB "User32.dll" ALIAS "IsWindowVisible" _
    (BYVAL hWnd AS DWORD) AS LONG

DECLARE FUNCTION IsIconic LIB "User32.dll" ALIAS "IsIconic" _
    (BYVAL hWnd AS DWORD) AS LONG

DECLARE FUNCTION AnyPopup LIB "User32.dll" ALIAS "AnyPopup" () AS LONG

DECLARE FUNCTION BringWindowToTop LIB "User32.dll" ALIAS "BringWindowToTop" _
    (BYVAL hWnd AS DWORD) AS LONG

DECLARE FUNCTION IsZoomed LIB "User32.dll" ALIAS "IsZoomed" _
    (BYVAL hWnd AS DWORD) AS LONG

'
' SetWindowPos Flags
'
%SWP_NOSIZE          = &H0001
%SWP_NOMOVE          = &H0002
%SWP_NOZORDER        = &H0004
%SWP_NOREDRAW        = &H0008
%SWP_NOACTIVATE      = &H0010
%SWP_FRAMECHANGED    = &H0020  ' The frame changed: send %WM_NCCALCSIZE
%SWP_SHOWWINDOW      = &H0040
%SWP_HIDEWINDOW      = &H0080
%SWP_NOCOPYBITS      = &H0100
%SWP_NOOWNERZORDER   = &H0200  ' Don't do owner Z ordering
%SWP_NOSENDCHANGING  = &H0400  ' Don't send %WM_WINDOWPOSCHANGING

%SWP_DRAWFRAME       = %SWP_FRAMECHANGED
%SWP_NOREPOSITION    = %SWP_NOOWNERZORDER

#IF (%WINVER >= &H0400)
%SWP_DEFERERASE      = &H2000
%SWP_ASYNCWINDOWPOS  = &H4000
#ENDIF ' %WINVER >= &H0400


%HWND_TOP        = 0
%HWND_BOTTOM     = 1
%HWND_TOPMOST    = (-1 AND &HFFFFFFFF???) ' LO(DWORD,-1)
%HWND_NOTOPMOST  = (-2 AND &HFFFFFFFF???) ' LO(DWORD,-2)

#IF NOT %DEF(%NOCTLMGR)

'
' WARNING:
' The following structures must NOT be DWORD padded because they are
' followed by strings, etc that do not have to be DWORD aligned.
'

'
' original NT 32 bit dialog template:
'
TYPE DLGTEMPLATE
    STYLE           AS DWORD
    dwExtendedStyle AS DWORD
    cdit            AS WORD
    x               AS INTEGER
    y               AS INTEGER
    cx              AS INTEGER
    cy              AS INTEGER
END TYPE

'
' 32 bit Dialog item template.
'
TYPE DLGITEMTEMPLATE
    STYLE         AS DWORD
    ExtendedStyle AS DWORD
    x             AS INTEGER
    y             AS INTEGER
    cx            AS INTEGER
    cy            AS INTEGER
    ID            AS WORD
END TYPE


' Resume normal packing


DECLARE FUNCTION CreateDialogParamA LIB "User32.dll" _
    ALIAS "CreateDialogParamA" (BYVAL hInstance AS DWORD, lpName AS ASCIIZ, _
    BYVAL hwndParent AS DWORD, BYVAL lpDialogFunc AS DWORD, _
    BYVAL lParamInit AS LONG) AS DWORD

DECLARE FUNCTION CreateDialogParamW LIB "User32.dll" _
    ALIAS "CreateDialogParamW" (BYVAL hInstance AS DWORD, lpName AS WSTRINGZ, _
    BYVAL hwndParent AS DWORD, BYVAL lpDialogFunc AS DWORD, _
    BYVAL lParamInit AS LONG) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateDialogParam LIB "User32.dll" _
    ALIAS "CreateDialogParamW" (BYVAL hInstance AS DWORD, lpName AS WSTRINGZ, _
    BYVAL hwndParent AS DWORD, BYVAL lpDialogFunc AS DWORD, _
    BYVAL lParamInit AS LONG) AS DWORD
#ELSE
DECLARE FUNCTION CreateDialogParam LIB "User32.dll" _
    ALIAS "CreateDialogParamA" (BYVAL hInstance AS DWORD, lpName AS ASCIIZ, _
    BYVAL hwndParent AS DWORD, BYVAL lpDialogFunc AS DWORD, _
    BYVAL lParamInit AS LONG) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CreateDialogIndirectParamA LIB "User32.dll" _
    ALIAS "CreateDialogIndirectParamA" (BYVAL hInstance AS DWORD, _
    lpTemplate AS DLGTEMPLATE, BYVAL hWndParent AS DWORD, _
    BYVAL lpDialogFunc AS DWORD, BYVAL dwInitParam AS DWORD) AS DWORD

DECLARE FUNCTION CreateDialogIndirectParamW LIB "User32.dll" _
    ALIAS "CreateDialogIndirectParamW" (BYVAL hInstance AS DWORD, _
    lpTemplate AS DLGTEMPLATE, BYVAL hWndParent AS DWORD, _
    BYVAL lpDialogFunc AS DWORD, BYVAL dwInitParam AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateDialogIndirectParam LIB "User32.dll" _
    ALIAS "CreateDialogIndirectParamW" (BYVAL hInstance AS DWORD, _
    lpTemplate AS DLGTEMPLATE, BYVAL hWndParent AS DWORD, _
    BYVAL lpDialogFunc AS DWORD, BYVAL dwInitParam AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION CreateDialogIndirectParam LIB "User32.dll" _
    ALIAS "CreateDialogIndirectParamA" (BYVAL hInstance AS DWORD, _
    lpTemplate AS DLGTEMPLATE, BYVAL hWndParent AS DWORD, _
    BYVAL lpDialogFunc AS DWORD, BYVAL dwInitParam AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

FUNCTION CreateDialogA (BYVAL hInstance AS DWORD, lpName AS ASCIIZ, _
    BYVAL hwndParent AS DWORD, BYVAL lpDialogFunc AS DWORD) AS DWORD
    FUNCTION = CreateDialogParamA(hInstance, lpName, hWndParent, lpDialogFunc, 0)
END FUNCTION

FUNCTION CreateDialogW (BYVAL hInstance AS DWORD, lpName AS WSTRINGZ, _
    BYVAL hwndParent AS DWORD, BYVAL lpDialogFunc AS DWORD) AS DWORD
    FUNCTION = CreateDialogParamW(hInstance, lpName, hWndParent, lpDialogFunc, 0)
END FUNCTION

#IF %DEF(%UNICODE)
FUNCTION CreateDialog (BYVAL hInstance AS DWORD, lpName AS WSTRINGZ, _
    BYVAL hwndParent AS DWORD, BYVAL lpDialogFunc AS DWORD) AS DWORD
    FUNCTION = CreateDialogParamW(hInstance, lpName, hWndParent, lpDialogFunc, 0)
END FUNCTION
#ELSE
FUNCTION CreateDialog (BYVAL hInstance AS DWORD, lpName AS ASCIIZ, _
    BYVAL hwndParent AS DWORD, BYVAL lpDialogFunc AS DWORD) AS DWORD
    FUNCTION = CreateDialogParamA(hInstance, lpName, hWndParent, lpDialogFunc, 0)
END FUNCTION
#ENDIF ' NOT %UNICODE

FUNCTION CreateDialogIndirectA (BYVAL hInstance AS DWORD, _
    lpTemplate AS DLGTEMPLATE, BYVAL hWndParent AS DWORD, _
    BYVAL lpDialogFunc AS DWORD) AS DWORD
    FUNCTION = CreateDialogIndirectParamA(hInstance, lpTemplate, hWndParent, _
        lpDialogFunc, 0)
END FUNCTION

FUNCTION CreateDialogIndirectW (BYVAL hInstance AS DWORD, _
    lpTemplate AS DLGTEMPLATE, BYVAL hWndParent AS DWORD, _
    BYVAL lpDialogFunc AS DWORD) AS DWORD
    FUNCTION = CreateDialogIndirectParamW(hInstance, lpTemplate, hWndParent, _
        lpDialogFunc, 0)
END FUNCTION

#IF %DEF(%UNICODE)
FUNCTION CreateDialogIndirect (BYVAL hInstance AS DWORD, _
    lpTemplate AS DLGTEMPLATE, BYVAL hWndParent AS DWORD, _
    BYVAL lpDialogFunc AS DWORD) AS DWORD
    FUNCTION = CreateDialogIndirectParamW(hInstance, lpTemplate, hWndParent, _
        lpDialogFunc, 0)
END FUNCTION
#ELSE
FUNCTION CreateDialogIndirect (BYVAL hInstance AS DWORD, _
    lpTemplate AS DLGTEMPLATE, BYVAL hWndParent AS DWORD, _
    BYVAL lpDialogFunc AS DWORD) AS DWORD
    FUNCTION = CreateDialogIndirectParamA(hInstance, lpTemplate, hWndParent, _
        lpDialogFunc, 0)
END FUNCTION
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DialogBoxParamA LIB "User32.dll" ALIAS "DialogBoxParamA" _
    (BYVAL hInstance AS DWORD, lpTemplateName AS ASCIIZ, _
    BYVAL hwndParent AS DWORD, BYVAL lpDialogFunc AS DWORD, _
    BYVAL dwInitParam AS DWORD) AS LONG

DECLARE FUNCTION DialogBoxParamW LIB "User32.dll" ALIAS "DialogBoxParamW" _
    (BYVAL hInstance AS DWORD, lpTemplateName AS WSTRINGZ, _
    BYVAL hwndParent AS DWORD, BYVAL lpDialogFunc AS DWORD, _
    BYVAL dwInitParam AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION DialogBoxParam LIB "User32.dll" ALIAS "DialogBoxParamW" _
    (BYVAL hInstance AS DWORD, lpTemplateName AS WSTRINGZ, _
    BYVAL hwndParent AS DWORD, BYVAL lpDialogFunc AS DWORD, _
    BYVAL dwInitParam AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION DialogBoxParam LIB "User32.dll" ALIAS "DialogBoxParamA" _
    (BYVAL hInstance AS DWORD, lpTemplateName AS ASCIIZ, _
    BYVAL hwndParent AS DWORD, BYVAL lpDialogFunc AS DWORD, _
    BYVAL dwInitParam AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DialogBoxIndirectParamA LIB "User32.dll" _
    ALIAS "DialogBoxIndirectParamA" (BYVAL hInstance AS DWORD, _
    hDialogTemplate AS DLGTEMPLATE, BYVAL hwndParent AS DWORD, _
    BYVAL lpDialogFunc AS DWORD, BYVAL dwInitParam AS DWORD) AS LONG

DECLARE FUNCTION DialogBoxIndirectParamW LIB "User32.dll" _
    ALIAS "DialogBoxIndirectParamW" (BYVAL hInstance AS DWORD, _
    hDialogTemplate AS DLGTEMPLATE, BYVAL hwndParent AS DWORD, _
    BYVAL lpDialogFunc AS DWORD, BYVAL dwInitParam AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION DialogBoxIndirectParam LIB "User32.dll" _
    ALIAS "DialogBoxIndirectParamW" (BYVAL hInstance AS DWORD, _
    hDialogTemplate AS DLGTEMPLATE, BYVAL hwndParent AS DWORD, _
    BYVAL lpDialogFunc AS DWORD, BYVAL dwInitParam AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION DialogBoxIndirectParam LIB "User32.dll" _
    ALIAS "DialogBoxIndirectParamA" (BYVAL hInstance AS DWORD, _
    hDialogTemplate AS DLGTEMPLATE, BYVAL hwndParent AS DWORD, _
    BYVAL lpDialogFunc AS DWORD, BYVAL dwInitParam AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

FUNCTION DialogBoxA (BYVAL hInstance AS DWORD, lpTemplateName AS ASCIIZ, _
    BYVAL hwndParent AS DWORD, BYVAL lpDialogFunc AS DWORD) AS LONG
    FUNCTION = DialogBoxParamA(hInstance, lpTemplateName, hWndParent, _
        lpDialogFunc, 0)
END FUNCTION

FUNCTION DialogBoxW (BYVAL hInstance AS DWORD, lpTemplateName AS WSTRINGZ, _
    BYVAL hwndParent AS DWORD, BYVAL lpDialogFunc AS DWORD) AS LONG
    FUNCTION = DialogBoxParamW(hInstance, lpTemplateName, hWndParent, _
        lpDialogFunc, 0)
END FUNCTION

#IF %DEF(%UNICODE)
FUNCTION DialogBox (BYVAL hInstance AS DWORD, lpTemplateName AS WSTRINGZ, _
    BYVAL hwndParent AS DWORD, BYVAL lpDialogFunc AS DWORD) AS LONG
    FUNCTION = DialogBoxParamW(hInstance, lpTemplateName, hWndParent, _
        lpDialogFunc, 0)
END FUNCTION
#ELSE
FUNCTION DialogBox (BYVAL hInstance AS DWORD, lpTemplateName AS ASCIIZ, _
    BYVAL hwndParent AS DWORD, BYVAL lpDialogFunc AS DWORD) AS LONG
    FUNCTION = DialogBoxParamA(hInstance, lpTemplateName, hWndParent, _
        lpDialogFunc, 0)
END FUNCTION
#ENDIF ' NOT %UNICODE

FUNCTION DialogBoxIndirectA (BYVAL hInstance AS DWORD, _
    hDialogTemplate AS DLGTEMPLATE, BYVAL hwndParent AS DWORD, _
    BYVAL lpDialogFunc AS DWORD) AS LONG
    FUNCTION = DialogBoxIndirectParamA(hInstance, hDialogTemplate, hWndParent, _
        lpDialogFunc, 0)
END FUNCTION

FUNCTION DialogBoxIndirectW (BYVAL hInstance AS DWORD, _
    hDialogTemplate AS DLGTEMPLATE, BYVAL hwndParent AS DWORD, _
    BYVAL lpDialogFunc AS DWORD) AS LONG
    FUNCTION = DialogBoxIndirectParamW(hInstance, hDialogTemplate, hWndParent, _
        lpDialogFunc, 0)
END FUNCTION

#IF %DEF(%UNICODE)
FUNCTION DialogBoxIndirect (BYVAL hInstance AS DWORD, _
    hDialogTemplate AS DLGTEMPLATE, BYVAL hwndParent AS DWORD, _
    BYVAL lpDialogFunc AS DWORD) AS LONG
    FUNCTION = DialogBoxIndirectParamW(hInstance, hDialogTemplate, hWndParent, _
        lpDialogFunc, 0)
END FUNCTION
#ELSE
FUNCTION DialogBoxIndirect (BYVAL hInstance AS DWORD, _
    hDialogTemplate AS DLGTEMPLATE, BYVAL hwndParent AS DWORD, _
    BYVAL lpDialogFunc AS DWORD) AS LONG
    FUNCTION = DialogBoxIndirectParamA(hInstance, hDialogTemplate, hWndParent, _
        lpDialogFunc, 0)
END FUNCTION
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EndDialog LIB "User32.dll" ALIAS "EndDialog" _
    (BYVAL hDlg AS DWORD, BYVAL nResult AS LONG) AS LONG

DECLARE FUNCTION GetDlgItem LIB "User32.dll" ALIAS "GetDlgItem" _
    (BYVAL hDlg AS DWORD, BYVAL nIDDlgItem AS LONG) AS DWORD

DECLARE FUNCTION SetDlgItemInt LIB "User32.dll" ALIAS "SetDlgItemInt" _
    (BYVAL hDlg AS DWORD, BYVAL nIDDlgItem AS LONG, BYVAL dwValue AS DWORD, _
    BYVAL bSigned AS LONG) AS LONG

DECLARE FUNCTION GetDlgItemInt LIB "User32.dll" ALIAS "GetDlgItemInt" _
    (BYVAL hDlg AS DWORD, BYVAL nIDDlgItem AS LONG, _
    lpTranslated AS LONG, BYVAL bSigned AS LONG) AS DWORD

DECLARE FUNCTION SetDlgItemTextA LIB "User32.dll" ALIAS "SetDlgItemTextA" _
    (BYVAL hDlg AS DWORD, BYVAL nIDDlgItem AS LONG, lpString AS ASCIIZ) AS LONG

DECLARE FUNCTION SetDlgItemTextW LIB "User32.dll" ALIAS "SetDlgItemTextW" _
    (BYVAL hDlg AS DWORD, BYVAL nIDDlgItem AS LONG, lpString AS WSTRINGZ) _
    AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetDlgItemText LIB "User32.dll" ALIAS "SetDlgItemTextW" _
    (BYVAL hDlg AS DWORD, BYVAL nIDDlgItem AS LONG, lpString AS WSTRINGZ) _
    AS LONG
#ELSE
DECLARE FUNCTION SetDlgItemText LIB "User32.dll" ALIAS "SetDlgItemTextA" _
    (BYVAL hDlg AS DWORD, BYVAL nIDDlgItem AS LONG, lpString AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetDlgItemTextA LIB "User32.dll" ALIAS "GetDlgItemTextA" _
    (BYVAL hDlg AS DWORD, BYVAL nIDDlgItem AS LONG, lpString AS ASCIIZ, _
    BYVAL nMaxCount AS LONG) AS DWORD

DECLARE FUNCTION GetDlgItemTextW LIB "User32.dll" ALIAS "GetDlgItemTextW" _
    (BYVAL hDlg AS DWORD, BYVAL nIDDlgItem AS LONG, lpString AS WSTRINGZ, _
    BYVAL nMaxCount AS LONG) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetDlgItemText LIB "User32.dll" ALIAS "GetDlgItemTextW" _
    (BYVAL hDlg AS DWORD, BYVAL nIDDlgItem AS LONG, lpString AS WSTRINGZ, _
    BYVAL nMaxCount AS LONG) AS DWORD
#ELSE
DECLARE FUNCTION GetDlgItemText LIB "User32.dll" ALIAS "GetDlgItemTextA" _
    (BYVAL hDlg AS DWORD, BYVAL nIDDlgItem AS LONG, lpString AS ASCIIZ, _
    BYVAL nMaxCount AS LONG) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CheckDlgButton LIB "User32.dll" ALIAS "CheckDlgButton" _
    (BYVAL hDlg AS DWORD, BYVAL nIDButton AS LONG, BYVAL uCheck AS DWORD) _
    AS LONG

DECLARE FUNCTION CheckRadioButton LIB "User32.dll" ALIAS "CheckRadioButton" _
    (BYVAL hDlg AS DWORD, BYVAL nIDFirstButton AS LONG, _
    BYVAL nIDLastButton AS LONG, BYVAL nIDCheckButton AS LONG) AS LONG

DECLARE FUNCTION IsDlgButtonChecked LIB "User32.dll" _
    ALIAS "IsDlgButtonChecked" (BYVAL hDlg AS DWORD, BYVAL nIDButton AS LONG) _
    AS DWORD

DECLARE FUNCTION SendDlgItemMessageA LIB "User32.dll" _
    ALIAS "SendDlgItemMessageA" (BYVAL hDlg AS DWORD, _
    BYVAL nIDDlgItem AS LONG, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION SendDlgItemMessageW LIB "User32.dll" _
    ALIAS "SendDlgItemMessageW" (BYVAL hDlg AS DWORD, _
    BYVAL nIDDlgItem AS LONG, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SendDlgItemMessage LIB "User32.dll" _
    ALIAS "SendDlgItemMessageW" (BYVAL hDlg AS DWORD, _
    BYVAL nIDDlgItem AS LONG, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG
#ELSE
DECLARE FUNCTION SendDlgItemMessage LIB "User32.dll" _
    ALIAS "SendDlgItemMessageA" (BYVAL hDlg AS DWORD, _
    BYVAL nIDDlgItem AS LONG, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetNextDlgGroupItem LIB "User32.dll" _
    ALIAS "GetNextDlgGroupItem" (BYVAL hDlg AS DWORD, BYVAL hCtl AS DWORD, _
    BYVAL bPrevious AS LONG) AS DWORD

DECLARE FUNCTION GetNextDlgTabItem LIB "User32.dll" ALIAS "GetNextDlgTabItem" _
    (BYVAL hDlg AS DWORD, BYVAL hCtl AS DWORD, BYVAL bPrevious AS LONG) _
    AS DWORD

DECLARE FUNCTION GetDlgCtrlID LIB "User32.dll" ALIAS "GetDlgCtrlID" _
    (BYVAL hWnd AS DWORD) AS LONG

DECLARE FUNCTION GetDialogBaseUnits LIB "User32.dll" _
    ALIAS "GetDialogBaseUnits" () AS LONG

DECLARE FUNCTION DefDlgProcA LIB "User32.dll" ALIAS "DefDlgProcA" _
    (BYVAL hDlg AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION DefDlgProcW LIB "User32.dll" ALIAS "DefDlgProcW" _
    (BYVAL hDlg AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION DefDlgProc LIB "User32.dll" ALIAS "DefDlgProcW" _
    (BYVAL hDlg AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG
#ELSE
DECLARE FUNCTION DefDlgProc LIB "User32.dll" ALIAS "DefDlgProcA" _
    (BYVAL hDlg AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

'
' Window extra byted needed for private dialog classes.
'
#IF NOT %DEF(%MAC)
%DLGWINDOWEXTRA = 30
#ELSE
%DLGWINDOWEXTRA = 48
#ENDIF

#ENDIF ' NOT %NOCTLMGR



#IF NOT %DEF(%NOMSG)

DECLARE FUNCTION CallMsgFilterA LIB "User32.dll" ALIAS "CallMsgFilterA" _
    (lpMsg AS MSG_type, BYVAL ncode AS LONG) AS LONG

DECLARE FUNCTION CallMsgFilterW LIB "User32.dll" ALIAS "CallMsgFilterW" _
    (lpMsg AS MSG_type, BYVAL ncode AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CallMsgFilter LIB "User32.dll" ALIAS "CallMsgFilterW" _
    (lpMsg AS MSG_type, BYVAL ncode AS LONG) AS LONG
#ELSE
DECLARE FUNCTION CallMsgFilter LIB "User32.dll" ALIAS "CallMsgFilterA" _
    (lpMsg AS MSG_type, BYVAL ncode AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' NOT %NOMSG

#IF NOT %DEF(%NOCLIPBOARD)

'
' Clipboard Manager Functions
'

DECLARE FUNCTION OpenClipboard LIB "User32.dll" ALIAS "OpenClipboard" _
    (OPTIONAL BYVAL hWnd AS DWORD) AS LONG

DECLARE FUNCTION CloseClipboard LIB "User32.dll" ALIAS "CloseClipboard" () _
    AS LONG



#IF (%WINVER >= &H0500)

DECLARE FUNCTION GetClipboardSequenceNumber LIB "User32.dll" _
    ALIAS "GetClipboardSequenceNumber" () AS DWORD

#ENDIF ' %WINVER >= &H0500

DECLARE FUNCTION GetClipboardOwner LIB "User32.dll" ALIAS "GetClipboardOwner" _
    () AS LONG

DECLARE FUNCTION SetClipboardViewer LIB "User32.dll" _
    ALIAS "SetClipboardViewer" (BYVAL hWnd AS DWORD) AS DWORD

DECLARE FUNCTION GetClipboardViewer LIB "User32.dll" _
    ALIAS "GetClipboardViewer" () AS DWORD

DECLARE FUNCTION ChangeClipboardChain LIB "User32.dll" _
    ALIAS "ChangeClipboardChain" (BYVAL hWnd AS DWORD, _
    BYVAL hWndNext AS DWORD) AS LONG

DECLARE FUNCTION SetClipboardData LIB "User32.dll" ALIAS "SetClipboardData" _
    (BYVAL dwFormat AS DWORD, OPTIONAL BYVAL hMem AS DWORD) AS DWORD

DECLARE FUNCTION GetClipboardData LIB "User32.dll" ALIAS "GetClipboardData" _
    (BYVAL uFormat AS DWORD) AS DWORD

DECLARE FUNCTION RegisterClipboardFormatA LIB "User32.dll" _
    ALIAS "RegisterClipboardFormatA" (lpString AS ASCIIZ) AS DWORD

DECLARE FUNCTION RegisterClipboardFormatW LIB "User32.dll" _
    ALIAS "RegisterClipboardFormatW" (lpString AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION RegisterClipboardFormat LIB "User32.dll" _
    ALIAS "RegisterClipboardFormatW" (lpString AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION RegisterClipboardFormat LIB "User32.dll" _
    ALIAS "RegisterClipboardFormatA" (lpString AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CountClipboardFormats LIB "User32.dll" _
    ALIAS "CountClipboardFormats" () AS LONG

DECLARE FUNCTION EnumClipboardFormats LIB "User32.dll" _
    ALIAS "EnumClipboardFormats" (BYVAL uFormat AS DWORD) AS DWORD

DECLARE FUNCTION GetClipboardFormatNameA LIB "User32.dll" _
    ALIAS "GetClipboardFormatNameA" (BYVAL uFormat AS DWORD, _
    lpString AS ASCIIZ, BYVAL nMaxCount AS LONG) AS LONG

DECLARE FUNCTION GetClipboardFormatNameW LIB "User32.dll" _
    ALIAS "GetClipboardFormatNameW" (BYVAL uFormat AS DWORD, _
    lpString AS WSTRINGZ, BYVAL nMaxCount AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetClipboardFormatName LIB "User32.dll" _
    ALIAS "GetClipboardFormatNameW" (BYVAL uFormat AS DWORD, _
    lpString AS WSTRINGZ, BYVAL nMaxCount AS LONG) AS LONG
#ELSE
DECLARE FUNCTION GetClipboardFormatName LIB "User32.dll" _
    ALIAS "GetClipboardFormatNameA" (BYVAL uFormat AS DWORD, _
    lpString AS ASCIIZ, BYVAL nMaxCount AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EmptyClipboard LIB "User32.dll" ALIAS "EmptyClipboard" () _
    AS LONG

DECLARE FUNCTION IsClipboardFormatAvailable LIB "User32.dll" _
    ALIAS "IsClipboardFormatAvailable" (BYVAL dwFormat AS DWORD) AS LONG

DECLARE FUNCTION GetPriorityClipboardFormat LIB "User32.dll" _
    ALIAS "GetPriorityClipboardFormat" (BYVAL lpPriorityList AS DWORD PTR, _
    BYVAL nCount AS LONG) AS LONG

DECLARE FUNCTION GetOpenClipboardWindow LIB "User32.dll" _
    ALIAS "GetOpenClipboardWindow" () AS DWORD

#IF (%WINVER >= &H0600)

DECLARE FUNCTION AddClipboardFormatListener LIB "User32.dll" _
    ALIAS "AddClipboardFormatListener" (BYVAL hwnd AS DWORD) AS LONG

DECLARE FUNCTION RemoveClipboardFormatListener LIB "User32.dll" _
    ALIAS "RemoveClipboardFormatListener" (BYVAL hwnd AS DWORD) AS LONG

DECLARE FUNCTION GetUpdatedClipboardFormats LIB "User32.dll" _
    ALIAS "GetUpdatedClipboardFormats" (BYVAL lpuiFormats AS DWORD PTR, _
    BYVAL cFormats AS DWORD, pcFormatsOut AS DWORD) AS LONG

#ENDIF ' %WINVER >= &H0600

#ENDIF ' NOT %NOCLIPBOARD

'
' Character Translation Routines
'

DECLARE FUNCTION CharToOemA LIB "User32.dll" ALIAS "CharToOemA" _
    (lpszSrc AS ASCIIZ, lpszDst AS ASCIIZ) AS LONG

DECLARE FUNCTION CharToOemW LIB "User32.dll" ALIAS "CharToOemW" _
    (lpszSrc AS WSTRINGZ, lpszDst AS ASCIIZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CharToOem LIB "User32.dll" ALIAS "CharToOemW" _
    (lpszSrc AS WSTRINGZ, lpszDst AS ASCIIZ) AS LONG
#ELSE
DECLARE FUNCTION CharToOem LIB "User32.dll" ALIAS "CharToOemA" _
    (lpszSrc AS ASCIIZ, lpszDst AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION OemToCharA LIB "User32.dll" ALIAS "OemToCharA" _
    (lpszSrc AS ASCIIZ, lpszDst AS ASCIIZ) AS LONG

DECLARE FUNCTION OemToCharW LIB "User32.dll" ALIAS "OemToCharW" _
    (lpszSrc AS ASCIIZ, lpszDst AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION OemToChar LIB "User32.dll" ALIAS "OemToCharW" _
    (lpszSrc AS ASCIIZ, lpszDst AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION OemToChar LIB "User32.dll" ALIAS "OemToCharA" _
    (lpszSrc AS ASCIIZ, lpszDst AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CharToOemBuffA LIB "User32.dll" ALIAS "CharToOemBuffA" _
    (lpszSrc AS ASCIIZ, lpszDst AS ASCIIZ, BYVAL cchDstLength AS DWORD) AS LONG

DECLARE FUNCTION CharToOemBuffW LIB "User32.dll" ALIAS "CharToOemBuffW" _
    (lpszSrc AS WSTRINGZ, lpszDst AS ASCIIZ, BYVAL cchDstLength AS DWORD) _
    AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CharToOemBuff LIB "User32.dll" ALIAS "CharToOemBuffW" _
    (lpszSrc AS WSTRINGZ, lpszDst AS ASCIIZ, BYVAL cchDstLength AS DWORD) _
    AS LONG
#ELSE
DECLARE FUNCTION CharToOemBuff LIB "User32.dll" ALIAS "CharToOemBuffA" _
    (lpszSrc AS ASCIIZ, lpszDst AS ASCIIZ, BYVAL cchDstLength AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION OemToCharBuffA LIB "User32.dll" ALIAS "OemToCharBuffA" _
    (lpszSrc AS ASCIIZ, lpszDst AS ASCIIZ, BYVAL cchDstLength AS DWORD) AS LONG

DECLARE FUNCTION OemToCharBuffW LIB "User32.dll" ALIAS "OemToCharBuffW" _
    (lpszSrc AS ASCIIZ, lpszDst AS WSTRINGZ, BYVAL cchDstLength AS DWORD) _
    AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION OemToCharBuff LIB "User32.dll" ALIAS "OemToCharBuffW" _
    (lpszSrc AS ASCIIZ, lpszDst AS WSTRINGZ, BYVAL cchDstLength AS DWORD) _
    AS LONG
#ELSE
DECLARE FUNCTION OemToCharBuff LIB "User32.dll" ALIAS "OemToCharBuffA" _
    (lpszSrc AS ASCIIZ, lpszDst AS ASCIIZ, BYVAL cchDstLength AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CharUpperA LIB "User32.dll" ALIAS "CharUpperA" _
    (lpsz AS ASCIIZ) AS DWORD

DECLARE FUNCTION CharUpperW LIB "User32.dll" ALIAS "CharUpperW" _
    (lpsz AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CharUpper LIB "User32.dll" ALIAS "CharUpperW" _
    (lpsz AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION CharUpper LIB "User32.dll" ALIAS "CharUpperA" _
    (lpsz AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CharUpperBuffA LIB "User32.dll" ALIAS "CharUpperBuffA" _
    (lpsz AS ASCIIZ, BYVAL cchLength AS DWORD) AS DWORD

DECLARE FUNCTION CharUpperBuffW LIB "User32.dll" ALIAS "CharUpperBuffW" _
    (lpsz AS WSTRINGZ, BYVAL cchLength AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CharUpperBuff LIB "User32.dll" ALIAS "CharUpperBuffW" _
    (lpsz AS WSTRINGZ, BYVAL cchLength AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION CharUpperBuff LIB "User32.dll" ALIAS "CharUpperBuffA" _
    (lpsz AS ASCIIZ, BYVAL cchLength AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CharLowerA LIB "User32.dll" ALIAS "CharLowerA" _
    (lpsz AS ASCIIZ) AS DWORD

DECLARE FUNCTION CharLowerW LIB "User32.dll" ALIAS "CharLowerW" _
    (lpsz AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CharLower LIB "User32.dll" ALIAS "CharLowerW" _
    (lpsz AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION CharLower LIB "User32.dll" ALIAS "CharLowerA" _
    (lpsz AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CharLowerBuffA LIB "User32.dll" ALIAS "CharLowerBuffA" _
    (lpsz AS ASCIIZ, BYVAL cchLength AS DWORD) AS DWORD

DECLARE FUNCTION CharLowerBuffW LIB "User32.dll" ALIAS "CharLowerBuffW" _
    (lpsz AS WSTRINGZ, BYVAL cchLength AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CharLowerBuff LIB "User32.dll" ALIAS "CharLowerBuffW" _
    (lpsz AS WSTRINGZ, BYVAL cchLength AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION CharLowerBuff LIB "User32.dll" ALIAS "CharLowerBuffA" _
    (lpsz AS ASCIIZ, BYVAL cchLength AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CharNextA LIB "User32.dll" ALIAS "CharNextA" _
    (lpsz AS ASCIIZ) AS DWORD

DECLARE FUNCTION CharNextW LIB "User32.dll" ALIAS "CharNextW" _
    (lpsz AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CharNext LIB "User32.dll" ALIAS "CharNextW" _
    (lpsz AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION CharNext LIB "User32.dll" ALIAS "CharNextA" _
    (lpsz AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CharPrevA LIB "User32.dll" ALIAS "CharPrevA" _
    (lpszStart AS ASCIIZ, lpszCurrent AS ASCIIZ) AS DWORD

DECLARE FUNCTION CharPrevW LIB "User32.dll" ALIAS "CharPrevW" _
    (lpszStart AS WSTRINGZ, lpszCurrent AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CharPrev LIB "User32.dll" ALIAS "CharPrevW" _
    (lpszStart AS WSTRINGZ, lpszCurrent AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION CharPrev LIB "User32.dll" ALIAS "CharPrevA" _
    (lpszStart AS ASCIIZ, lpszCurrent AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

#IF (%WINVER >= &H0400)

DECLARE FUNCTION CharNextExA LIB "User32.dll" ALIAS "CharNextExA" _
    (BYVAL CodePag AS WORD, lpCurrentChar AS ASCIIZ, BYVAL dwFlags AS DWORD) _
    AS DWORD

DECLARE FUNCTION CharPrevExA LIB "User32.dll" ALIAS "CharPrevExA" _
    (BYVAL CodePag AS WORD, lpStart AS ASCIIZ, lpCurrentChar AS ASCIIZ, _
    BYVAL dwFlags AS DWORD) AS DWORD

#ENDIF ' %WINVER >= &H0400

'
' Compatibility defines for character translation routines
'
MACRO AnsiToOem=CharToOemA
MACRO OemToAnsi=OemToCharA
MACRO AnsiToOemBuff=CharToOemBuffA
MACRO OemToAnsiBuff=OemToCharBuffA
MACRO AnsiUpper=CharUpperA
MACRO AnsiUpperBuff=CharUpperBuffA
MACRO AnsiLower=CharLowerA
MACRO AnsiLowerBuff=CharLowerBuffA
MACRO AnsiNext=CharNextA
MACRO AnsiPrev=CharPrevA

#IF NOT %DEF(%NOLANGUAGE)
'
' Language dependent Routines
'

DECLARE FUNCTION IsCharAlphaA LIB "User32.dll" ALIAS "IsCharAlphaA" _
    (BYVAL cChar AS BYTE) AS LONG

DECLARE FUNCTION IsCharAlphaW LIB "User32.dll" ALIAS "IsCharAlphaW" _
    (BYVAL cChar AS WORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION IsCharAlpha LIB "User32.dll" ALIAS "IsCharAlphaW" _
    (BYVAL cChar AS WORD) AS LONG
#ELSE
DECLARE FUNCTION IsCharAlpha LIB "User32.dll" ALIAS "IsCharAlphaA" _
    (BYVAL cChar AS BYTE) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION IsCharAlphaNumericA LIB "User32.dll" _
    ALIAS "IsCharAlphaNumericA" (BYVAL cChar AS BYTE) AS LONG

DECLARE FUNCTION IsCharAlphaNumericW LIB "User32.dll" _
    ALIAS "IsCharAlphaNumericW" (BYVAL cChar AS WORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION IsCharAlphaNumeric LIB "User32.dll" _
    ALIAS "IsCharAlphaNumericW" (BYVAL cChar AS WORD) AS LONG
#ELSE
DECLARE FUNCTION IsCharAlphaNumeric LIB "User32.dll" _
    ALIAS "IsCharAlphaNumericA" (BYVAL cChar AS BYTE) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION IsCharUpperA LIB "User32.dll" ALIAS "IsCharUpperA" _
    (BYVAL cChar AS BYTE) AS LONG

DECLARE FUNCTION IsCharUpperW LIB "User32.dll" ALIAS "IsCharUpperW" _
    (BYVAL cChar AS WORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION IsCharUpper LIB "User32.dll" ALIAS "IsCharUpperW" _
    (BYVAL cChar AS WORD) AS LONG
#ELSE
DECLARE FUNCTION IsCharUpper LIB "User32.dll" ALIAS "IsCharUpperA" _
    (BYVAL cChar AS BYTE) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION IsCharLowerA LIB "User32.dll" ALIAS "IsCharLowerA" _
    (BYVAL cChar AS BYTE) AS LONG

DECLARE FUNCTION IsCharLowerW LIB "User32.dll" ALIAS "IsCharLowerW" _
    (BYVAL cChar AS WORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION IsCharLower LIB "User32.dll" ALIAS "IsCharLowerW" _
    (BYVAL cChar AS WORD) AS LONG
#ELSE
DECLARE FUNCTION IsCharLower LIB "User32.dll" ALIAS "IsCharLowerA" _
    (BYVAL cChar AS BYTE) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF  ' NOT %NOLANGUAGE

DECLARE FUNCTION SetFocus LIB "User32.dll" ALIAS "SetFocus" _
    (OPTIONAL BYVAL hWnd AS DWORD) AS DWORD

DECLARE FUNCTION GetActiveWindow LIB "User32.dll" ALIAS "GetActiveWindow" () _
    AS DWORD

DECLARE FUNCTION GetFocus LIB "User32.dll" ALIAS "GetFocus" () AS DWORD

DECLARE FUNCTION GetKBCodePage LIB "User32.dll" ALIAS "GetKBCodePage" () _
    AS DWORD

DECLARE FUNCTION GetKeyState LIB "User32.dll" ALIAS "GetKeyState" _
    (BYVAL nVirtKey AS LONG) AS INTEGER

DECLARE FUNCTION GetAsyncKeyState LIB "User32.dll" ALIAS "GetAsyncKeyState" _
    (BYVAL vKey AS LONG) AS INTEGER

DECLARE FUNCTION GetKeyboardState LIB "User32.dll" ALIAS "GetKeyboardState" _
    (pbKeyState AS BYTE) AS LONG

DECLARE FUNCTION SetKeyboardState LIB "User32.dll" ALIAS "SetKeyboardState" _
    (lppbKeyState AS BYTE) AS LONG

DECLARE FUNCTION GetKeyNameTextA LIB "User32.dll" ALIAS "GetKeyNameTextA" _
    (BYVAL lParam AS LONG, lpBuffer AS ASCIIZ, BYVAL nSize AS LONG) AS LONG

DECLARE FUNCTION GetKeyNameTextW LIB "User32.dll" ALIAS "GetKeyNameTextW" _
    (BYVAL lParam AS LONG, lpBuffer AS WSTRINGZ, BYVAL nSize AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetKeyNameText LIB "User32.dll" ALIAS "GetKeyNameTextW" _
    (BYVAL lParam AS LONG, lpBuffer AS WSTRINGZ, BYVAL nSize AS LONG) AS LONG
#ELSE
DECLARE FUNCTION GetKeyNameText LIB "User32.dll" ALIAS "GetKeyNameTextA" _
    (BYVAL lParam AS LONG, lpBuffer AS ASCIIZ, BYVAL nSize AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetKeyboardType LIB "User32.dll" ALIAS "GetKeyboardType" _
    (BYVAL nTypeFlag AS LONG) AS LONG

DECLARE FUNCTION ToAscii LIB "User32.dll" ALIAS "ToAscii" _
    (BYVAL uVirtKey AS DWORD, BYVAL uScanCode AS DWORD, _
    BYVAL lpKeyState AS BYTE PTR, lpChar AS WORD, BYVAL uFlags AS DWORD) _
    AS LONG


#IF (%WINVER >= &H0400)

DECLARE FUNCTION ToAsciiEx LIB "User32.dll" ALIAS "ToAsciiEx" _
    (BYVAL uVirtKey AS DWORD, BYVAL uScanCode AS DWORD, _
    BYVAL lpKeyState AS BYTE PTR, lpChar AS WORD, BYVAL uFlags AS DWORD, _
    OPTIONAL BYVAL dwHKL AS DWORD) AS LONG

#ENDIF ' %WINVER >= &H0400

DECLARE FUNCTION ToUnicode LIB "User32.dll" ALIAS "ToUnicode" _
    (BYVAL uVirtKey AS DWORD, BYVAL uScanCode AS DWORD, _
    BYVAL lpKeyState AS BYTE PTR, pwszBuff AS WSTRINGZ, _
    BYVAL cchBuff AS LONG, BYVAL uFlags AS DWORD) AS LONG

DECLARE FUNCTION OemKeyScan LIB "User32.dll" ALIAS "OemKeyScan" _
    (BYVAL wOemChar AS WORD) AS DWORD

DECLARE FUNCTION VkKeyScanA LIB "User32.dll" ALIAS "VkKeyScanA" _
    (BYVAL cChar AS BYTE) AS INTEGER

DECLARE FUNCTION VkKeyScanW LIB "User32.dll" ALIAS "VkKeyScanW" _
    (BYVAL cChar AS WORD) AS INTEGER

#IF %DEF(%UNICODE)
DECLARE FUNCTION VkKeyScan LIB "User32.dll" ALIAS "VkKeyScanW" _
    (BYVAL cChar AS WORD) AS INTEGER
#ELSE
DECLARE FUNCTION VkKeyScan LIB "User32.dll" ALIAS "VkKeyScanA" _
    (BYVAL cChar AS BYTE) AS INTEGER
#ENDIF ' NOT %UNICODE

#IF (%WINVER >= &H0400)

DECLARE FUNCTION VkKeyScanExA LIB "User32.dll" ALIAS "VkKeyScanExA" _
    (BYVAL ch AS BYTE, BYVAL dwHKL AS DWORD) AS INTEGER

DECLARE FUNCTION VkKeyScanExW LIB "User32.dll" ALIAS "VkKeyScanExW" _
    (BYVAL ch AS WORD, BYVAL dwHKL AS DWORD) AS INTEGER

#IF %DEF(%UNICODE)
DECLARE FUNCTION VkKeyScanEx LIB "User32.dll" ALIAS "VkKeyScanExW" _
    (BYVAL ch AS WORD, BYVAL dwHKL AS DWORD) AS INTEGER
#ELSE
DECLARE FUNCTION VkKeyScanExA LIB "User32.dll" ALIAS "VkKeyScanExA" _
    (BYVAL ch AS BYTE, BYVAL dwHKL AS DWORD) AS INTEGER
#ENDIF ' NOT %UNICODE

#ENDIF ' %WINVER >= &H0400

%KEYEVENTF_EXTENDEDKEY = &H0001
%KEYEVENTF_KEYUP       = &H0002
#IF (%WIN32_WINNT >= &H0500)
%KEYEVENTF_UNICODE     = &H0004
%KEYEVENTF_SCANCODE    = &H0008
#ENDIF ' %WIN32_WINNT >= &H0500

DECLARE SUB keybd_event LIB "User32.dll" ALIAS "keybd_event" _
    (BYVAL bVk AS BYTE, BYVAL bScan AS BYTE, BYVAL dwFlags AS DWORD, _
    BYVAL dwExtraInfo AS DWORD)

%MOUSEEVENTF_MOVE        = &H0001 ' mouse move
%MOUSEEVENTF_LEFTDOWN    = &H0002 ' left button down
%MOUSEEVENTF_LEFTUP      = &H0004 ' left button up
%MOUSEEVENTF_RIGHTDOWN   = &H0008 ' right button down
%MOUSEEVENTF_RIGHTUP     = &H0010 ' right button up
%MOUSEEVENTF_MIDDLEDOWN  = &H0020 ' middle button down
%MOUSEEVENTF_MIDDLEUP    = &H0040 ' middle button up
%MOUSEEVENTF_XDOWN       = &H0080 ' x button down
%MOUSEEVENTF_XUP         = &H0100 ' x button down
%MOUSEEVENTF_WHEEL       = &H0800 ' wheel button rolled
#IF (%WIN32_WINNT >= &H0600)
%MOUSEEVENTF_HWHEEL      = &H1000 ' hwheel button rolled
#ENDIF
#IF (%WINVER >= &H0600)
%MOUSEEVENTF_MOVE_NOCOALESCE = &H2000 ' do not coalesce mouse moves
#ENDIF
%MOUSEEVENTF_VIRTUALDESK = &H4000 ' map to entire virtual desktop
%MOUSEEVENTF_ABSOLUTE    = &H8000?? ' absolute move


DECLARE SUB mouse_event LIB "User32.dll" ALIAS "mouse_event" _
    (BYVAL dwFlags AS DWORD, BYVAL dx AS DWORD, BYVAL dy AS DWORD, _
    BYVAL cButtons AS DWORD, BYVAL dwExtraInfo AS DWORD)

#IF (%WIN32_WINNT > &H0400)

TYPE MOUSEINPUT
    dx          AS LONG
    dy          AS LONG
    mouseData   AS DWORD
    dwFlags     AS DWORD
    dtime       AS DWORD
    dwExtraInfo AS DWORD
END TYPE

TYPE KEYBDINPUT
    wVk         AS WORD
    wScan       AS WORD
    dwFlags     AS DWORD
    dtime       AS DWORD
    dwExtraInfo AS DWORD
END TYPE

TYPE HARDWAREINPUT
    uMsg    AS DWORD
    wParamL AS WORD
    wParamH AS WORD
END TYPE

%INPUT_MOUSE    = 0
%INPUT_KEYBOARD = 1
%INPUT_HARDWARE = 2

UNION INPUT_union
    imi AS MOUSEINPUT
    iki AS KEYBDINPUT
    ihi AS HARDWAREINPUT
END UNION

TYPE INPUT_type
    dtype AS DWORD
    INPUT_union
END TYPE

' [legacy]
TYPE INPUTAPI
    INPUT_type
END TYPE

DECLARE FUNCTION SendInput LIB "User32.dll" ALIAS "SendInput" _
    (BYVAL cInputs AS DWORD, BYVAL pInputs AS INPUTAPI PTR, _
    BYVAL cbSize AS LONG) AS DWORD

#ENDIF ' (%WIN32_WINNT > &H0400)

#IF (%WIN32_WINNT >= &H0500)


#IF (%WINVER >= &H0601)

'
' Touch Input defines and functions
'

'
' Touch input handle
'
'DECLARE_HANDLE(HTOUCHINPUT);

TYPE TOUCHINPUT
    x           AS LONG
    y           AS LONG
    hSource     AS DWORD
    dwID        AS DWORD
    dwFlags     AS DWORD
    dwMask      AS DWORD
    dwTime      AS DWORD
    dwExtraInfo AS DWORD
    cxContact   AS DWORD
    cyContact   AS DWORD
END TYPE


'
' Conversion of touch input coordinates to pixels
'
MACRO TOUCH_COORD_TO_PIXEL(x)=((x)/100)

'
' Touch input flag values (TOUCHINPUT.dwFlags)
'
%TOUCHEVENTF_MOVE          = &H0001
%TOUCHEVENTF_DOWN          = &H0002
%TOUCHEVENTF_UP            = &H0004
%TOUCHEVENTF_INRANGE       = &H0008
%TOUCHEVENTF_PRIMARY       = &H0010
%TOUCHEVENTF_NOCOALESCE    = &H0020
%TOUCHEVENTF_PEN           = &H0040
%TOUCHEVENTF_PALM          = &H0080

'
' Touch input mask values (TOUCHINPUT.dwMask)
'
%TOUCHINPUTMASKF_TIMEFROMSYSTEM = &H0001  ' the dwTime field contains a system generated value
%TOUCHINPUTMASKF_EXTRAINFO      = &H0002  ' the dwExtraInfo field is valid
%TOUCHINPUTMASKF_CONTACTAREA    = &H0004  ' the cxContact and cyContact fields are valid

DECLARE FUNCTION GetTouchInputInfo LIB "User32.dll" _
    ALIAS "GetTouchInputInfo" ( _
    BYVAL hTouchInput AS DWORD, _        ' input event handle; from touch message lParam
    BYVAL cInputs AS DWORD, _            ' number of elements in the array
    BYVAL pInputs AS TOUCHINPUT PTR, _   ' array of touch inputs
    BYVAL cbSize AS LONG) _              ' sizeof(TOUCHINPUT)
    AS LONG

DECLARE FUNCTION CloseTouchInputHandle LIB "User32.dll" _
    ALIAS "CloseTouchInputHandle" ( _
    BYVAL hTouchInput AS DWORD) _        ' input event handle; from touch message lParam
    AS LONG


'
' RegisterTouchWindow flag values
'
%TWF_FINETOUCH     = (&H00000001)
%TWF_WANTPALM      = (&H00000002)

DECLARE FUNCTION RegisterTouchWindow LIB "User32.dll" _
    ALIAS "RegisterTouchWindow" ( _
    BYVAL hwnd AS DWORD, _
    BYVAL ulFlags AS DWORD) _
    AS LONG

DECLARE FUNCTION UnregisterTouchWindow LIB "User32.dll" _
    ALIAS "UnregisterTouchWindow" ( _
    BYVAL hwnd AS DWORD) _
    AS LONG

DECLARE FUNCTION IsTouchWindow LIB "User32.dll" ALIAS "IsTouchWindow" ( _
    BYVAL hwnd AS DWORD, _
    pulFlags AS DWORD) _
    AS LONG

#ENDIF ' %WINVER >= &H0601


TYPE LASTINPUTINFO
    cbSize AS DWORD
    dwTime AS DWORD
END TYPE

DECLARE FUNCTION GetLastInputInfo LIB "User32.dll" ALIAS "GetLastInputInfo" _
    (plii AS LASTINPUTINFO) AS LONG

#ENDIF ' %WIN32_WINNT >= &H0500

DECLARE FUNCTION MapVirtualKeyA LIB "User32.dll" ALIAS "MapVirtualKeyA" _
    (BYVAL dwCode AS DWORD, BYVAL dwMapType AS DWORD) AS DWORD

DECLARE FUNCTION MapVirtualKeyW LIB "User32.dll" ALIAS "MapVirtualKeyW" _
    (BYVAL dwCode AS DWORD, BYVAL dwMapType AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION MapVirtualKey LIB "User32.dll" ALIAS "MapVirtualKeyW" _
    (BYVAL dwCode AS DWORD, BYVAL dwMapType AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION MapVirtualKey LIB "User32.dll" ALIAS "MapVirtualKeyA" _
    (BYVAL dwCode AS DWORD, BYVAL dwMapType AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

#IF (%WINVER >= &H0400)

DECLARE FUNCTION MapVirtualKeyExA LIB "User32.dll" ALIAS "MapVirtualKeyExA" _
    (BYVAL uCode AS DWORD, BYVAL uMapType AS DWORD, _
    OPTIONAL BYVAL dwHKL AS DWORD) AS DWORD

DECLARE FUNCTION MapVirtualKeyExW LIB "User32.dll" ALIAS "MapVirtualKeyExW" _
    (BYVAL uCode AS DWORD, BYVAL uMapType AS DWORD, _
    OPTIONAL BYVAL dwHKL AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION MapVirtualKeyEx LIB "User32.dll" ALIAS "MapVirtualKeyExW" _
    (BYVAL uCode AS DWORD, BYVAL uMapType AS DWORD, _
    OPTIONAL BYVAL dwHKL AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION MapVirtualKeyEx LIB "User32.dll" ALIAS "MapVirtualKeyExA" _
    (BYVAL uCode AS DWORD, BYVAL uMapType AS DWORD, _
    OPTIONAL BYVAL dwHKL AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

%MAPVK_VK_TO_VSC    = 0
%MAPVK_VSC_TO_VK    = 1
%MAPVK_VK_TO_CHAR   = 2
%MAPVK_VSC_TO_VK_EX = 3
#ENDIF ' %WINVER >= &H0400
#IF (%WINVER >= &H0600)
%MAPVK_VK_TO_VSC_EX = 4
#ENDIF ' %WINVER >= &H0600

DECLARE FUNCTION GetInputState LIB "User32.dll" ALIAS "GetInputState" () _
    AS LONG

DECLARE FUNCTION GetQueueStatus LIB "User32.dll" ALIAS "GetQueueStatus" _
    (BYVAL fuFlags AS DWORD) AS DWORD

DECLARE FUNCTION GetCapture LIB "User32.dll" ALIAS "GetCapture" () AS DWORD

DECLARE FUNCTION SetCapture LIB "User32.dll" ALIAS "SetCapture" _
    (BYVAL hWnd AS DWORD) AS DWORD

DECLARE FUNCTION ReleaseCapture LIB "User32.dll" ALIAS "ReleaseCapture" () _
    AS LONG

DECLARE FUNCTION MsgWaitForMultipleObjects LIB "User32.dll" _
    ALIAS "MsgWaitForMultipleObjects" (BYVAL nCount AS DWORD, _
    pHandles AS DWORD, BYVAL fWaitAll AS LONG, BYVAL dwMilliseconds AS DWORD, _
    BYVAL dwWakeMask AS DWORD) AS DWORD

DECLARE FUNCTION MsgWaitForMultipleObjectsEx LIB "User32.dll" _
    ALIAS "MsgWaitForMultipleObjectsEx" (BYVAL nCount AS DWORD, _
    BYVAL pHandless AS DWORD PTR, BYVAL dwMilliseconds AS DWORD, _
    BYVAL dwWakeMask AS DWORD) AS DWORD


%MWMO_WAITALL        = &H0001
%MWMO_ALERTABLE      = &H0002
%MWMO_INPUTAVAILABLE = &H0004

'
' Queue status flags for GetQueueStatus() and MsgWaitForMultipleObjects()
'
%QS_KEY              = &H0001
%QS_MOUSEMOVE        = &H0002
%QS_MOUSEBUTTON      = &H0004
%QS_POSTMESSAGE      = &H0008
%QS_TIMER            = &H0010
%QS_PAINT            = &H0020
%QS_SENDMESSAGE      = &H0040
%QS_HOTKEY           = &H0080
%QS_ALLPOSTMESSAGE   = &H0100
#IF (%WIN32_WINNT >= &H0501)
%QS_RAWINPUT         = &H0400
#ENDIF ' %WIN32_WINNT >= &H0501

%QS_MOUSE           = (%QS_MOUSEMOVE     OR _
                           %QS_MOUSEBUTTON)

#IF (%WIN32_WINNT >= &H0501)
%QS_INPUT           = (%QS_MOUSE         OR _
                           %QS_KEY           OR _
                           %QS_RAWINPUT)
#ELSE
%QS_INPUT           = (%QS_MOUSE         OR _
                           %QS_KEY)
#ENDIF

%QS_ALLEVENTS       = (%QS_INPUT         OR _
                           %QS_POSTMESSAGE   OR _
                           %QS_TIMER         OR _
                           %QS_PAINT         OR _
                           %QS_HOTKEY)

%QS_ALLINPUT        = (%QS_INPUT         OR _
                           %QS_POSTMESSAGE   OR _
                           %QS_TIMER         OR _
                           %QS_PAINT         OR _
                           %QS_HOTKEY        OR _
                           %QS_SENDMESSAGE)


#IF (%WINVER >= &H0500)
%PM_QS_INPUT       = %QS_INPUT * 256
%PM_QS_POSTMESSAGE = (%QS_POSTMESSAGE OR %QS_HOTKEY OR %QS_TIMER) * 256
%PM_QS_PAINT       = %QS_PAINT * 256
%PM_QS_SENDMESSAGE = %QS_SENDMESSAGE * 256
#ENDIF ' %WINVER >= &H0500

%USER_TIMER_MAXIMUM = &H7FFFFFFF
%USER_TIMER_MINIMUM = &H0000000A

'
' Windows Functions
'

DECLARE FUNCTION SetTimer LIB "User32.dll" ALIAS "SetTimer" _
    (BYVAL hWnd AS DWORD, BYVAL nIDEvent AS DWORD, BYVAL uElapse AS DWORD, _
    OPTIONAL BYVAL lpTimerFunc AS DWORD) AS DWORD

DECLARE FUNCTION KillTimer LIB "User32.dll" ALIAS "KillTimer" _
    (BYVAL hWnd AS DWORD, BYVAL nIDEvent AS DWORD) AS LONG

DECLARE FUNCTION IsWindowUnicode LIB "User32.dll" ALIAS "IsWindowUnicode" _
    (BYVAL hWnd AS DWORD) AS LONG

DECLARE FUNCTION EnableWindow LIB "User32.dll" ALIAS "EnableWindow" _
    (BYVAL hWnd AS DWORD, BYVAL fEnable AS LONG) AS LONG

DECLARE FUNCTION IsWindowEnabled LIB "User32.dll" ALIAS "IsWindowEnabled" _
    (BYVAL hWnd AS DWORD) AS LONG

DECLARE FUNCTION LoadAcceleratorsA LIB "User32.dll" ALIAS "LoadAcceleratorsA" _
    (BYVAL hInstance AS DWORD, lpTableName AS ASCIIZ) AS DWORD

DECLARE FUNCTION LoadAcceleratorsW LIB "User32.dll" ALIAS "LoadAcceleratorsW" _
    (BYVAL hInstance AS DWORD, lpTableName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION LoadAccelerators LIB "User32.dll" ALIAS "LoadAcceleratorsW" _
    (BYVAL hInstance AS DWORD, lpTableName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION LoadAccelerators LIB "User32.dll" ALIAS "LoadAcceleratorsA" _
    (BYVAL hInstance AS DWORD, lpTableName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CreateAcceleratorTableA LIB "User32.dll" _
    ALIAS "CreateAcceleratorTableA" (lpaccl AS ACCELAPI, _
    BYVAL cEntries AS LONG) AS DWORD

DECLARE FUNCTION CreateAcceleratorTableW LIB "User32.dll" _
    ALIAS "CreateAcceleratorTableW" (lpaccl AS ACCELAPI, _
    BYVAL cEntries AS LONG) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateAcceleratorTable LIB "User32.dll" _
    ALIAS "CreateAcceleratorTableW" (lpaccl AS ACCELAPI, _
    BYVAL cEntries AS LONG) AS DWORD
#ELSE
DECLARE FUNCTION CreateAcceleratorTable LIB "User32.dll" _
    ALIAS "CreateAcceleratorTableA" (lpaccl AS ACCELAPI, _
    BYVAL cEntries AS LONG) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DestroyAcceleratorTable LIB "User32.dll" _
    ALIAS "DestroyAcceleratorTable" (BYVAL hAccel AS DWORD) AS LONG

DECLARE FUNCTION CopyAcceleratorTableA LIB "User32.dll" _
    ALIAS "CopyAcceleratorTableA" (BYVAL hAccelSrc AS DWORD, _
    lpAccelDst AS ACCELAPI, BYVAL cAccelEntries AS LONG) AS LONG

DECLARE FUNCTION CopyAcceleratorTableW LIB "User32.dll" _
    ALIAS "CopyAcceleratorTableW" (BYVAL hAccelSrc AS DWORD, _
    lpAccelDst AS ACCELAPI, BYVAL cAccelEntries AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CopyAcceleratorTable LIB "User32.dll" _
    ALIAS "CopyAcceleratorTableW" (BYVAL hAccelSrc AS DWORD, _
    lpAccelDst AS ACCELAPI, BYVAL cAccelEntries AS LONG) AS LONG
#ELSE
DECLARE FUNCTION CopyAcceleratorTable LIB "User32.dll" _
    ALIAS "CopyAcceleratorTableA" (BYVAL hAccelSrc AS DWORD, _
    lpAccelDst AS ACCELAPI, BYVAL cAccelEntries AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

#IF NOT %DEF(%NOMSG)

DECLARE FUNCTION TranslateAcceleratorA LIB "User32.dll" _
    ALIAS "TranslateAcceleratorA" (BYVAL hWnd AS DWORD, _
    BYVAL hAccTable AS DWORD, lpMsg AS MSG_type) AS LONG

DECLARE FUNCTION TranslateAcceleratorW LIB "User32.dll" _
    ALIAS "TranslateAcceleratorW" (BYVAL hWnd AS DWORD, _
    BYVAL hAccTable AS DWORD, lpMsg AS MSG_type) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION TranslateAccelerator LIB "User32.dll" _
    ALIAS "TranslateAcceleratorW" (BYVAL hWnd AS DWORD, _
    BYVAL hAccTable AS DWORD, lpMsg AS MSG_type) AS LONG
#ELSE
DECLARE FUNCTION TranslateAccelerator LIB "User32.dll" _
    ALIAS "TranslateAcceleratorA" (BYVAL hWnd AS DWORD, _
    BYVAL hAccTable AS DWORD, lpMsg AS MSG_type) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' NOT %NOMSG



#IF NOT %DEF(%NOSYSMETRICS)

'
' GetSystemMetrics() codes
'

%SM_CXSCREEN           = 0
%SM_CYSCREEN           = 1
%SM_CXVSCROLL          = 2
%SM_CYHSCROLL          = 3
%SM_CYCAPTION          = 4
%SM_CXBORDER           = 5
%SM_CYBORDER           = 6
%SM_CXDLGFRAME         = 7
%SM_CYDLGFRAME         = 8
%SM_CYVTHUMB           = 9
%SM_CXHTHUMB           = 10
%SM_CXICON             = 11
%SM_CYICON             = 12
%SM_CXCURSOR           = 13
%SM_CYCURSOR           = 14
%SM_CYMENU             = 15
%SM_CXFULLSCREEN       = 16
%SM_CYFULLSCREEN       = 17
%SM_CYKANJIWINDOW      = 18
%SM_MOUSEPRESENT       = 19
%SM_CYVSCROLL          = 20
%SM_CXHSCROLL          = 21
%SM_DEBUG              = 22
%SM_SWAPBUTTON         = 23
%SM_RESERVED1          = 24
%SM_RESERVED2          = 25
%SM_RESERVED3          = 26
%SM_RESERVED4          = 27
%SM_CXMIN              = 28
%SM_CYMIN              = 29
%SM_CXSIZE             = 30
%SM_CYSIZE             = 31
%SM_CXFRAME            = 32
%SM_CYFRAME            = 33
%SM_CXMINTRACK         = 34
%SM_CYMINTRACK         = 35
%SM_CXDOUBLECLK        = 36
%SM_CYDOUBLECLK        = 37
%SM_CXICONSPACING      = 38
%SM_CYICONSPACING      = 39
%SM_MENUDROPALIGNMENT  = 40
%SM_PENWINDOWS         = 41
%SM_DBCSENABLED        = 42
%SM_CMOUSEBUTTONS      = 43

#IF (%WINVER >= &H0400)
%SM_CXFIXEDFRAME       = %SM_CXDLGFRAME  ' ;win40 name change
%SM_CYFIXEDFRAME       = %SM_CYDLGFRAME  ' ;win40 name change
%SM_CXSIZEFRAME        = %SM_CXFRAME     ' ;win40 name change
%SM_CYSIZEFRAME        = %SM_CYFRAME     ' ;win40 name change

%SM_SECURE             = 44
%SM_CXEDGE             = 45
%SM_CYEDGE             = 46
%SM_CXMINSPACING       = 47
%SM_CYMINSPACING       = 48
%SM_CXSMICON           = 49
%SM_CYSMICON           = 50
%SM_CYSMCAPTION        = 51
%SM_CXSMSIZE           = 52
%SM_CYSMSIZE           = 53
%SM_CXMENUSIZE         = 54
%SM_CYMENUSIZE         = 55
%SM_ARRANGE            = 56
%SM_CXMINIMIZED        = 57
%SM_CYMINIMIZED        = 58
%SM_CXMAXTRACK         = 59
%SM_CYMAXTRACK         = 60
%SM_CXMAXIMIZED        = 61
%SM_CYMAXIMIZED        = 62
%SM_NETWORK            = 63
%SM_CLEANBOOT          = 67
%SM_CXDRAG             = 68
%SM_CYDRAG             = 69
#ENDIF ' %WINVER >= &H0400
%SM_SHOWSOUNDS         = 70
#IF (%WINVER >= &H0400)
%SM_CXMENUCHECK        = 71   ' Use instead of GetMenuCheckMarkDimensions()!
%SM_CYMENUCHECK        = 72
%SM_SLOWMACHINE        = 73
%SM_MIDEASTENABLED     = 74
#ENDIF ' %WINVER >= &H0400

#IF (%WINVER >= &H0500) OR (%WIN32_WINNT >= &H0400)
%SM_MOUSEWHEELPRESENT  = 75
#ENDIF
#IF (%WINVER >= &H0500)
%SM_XVIRTUALSCREEN     = 76
%SM_YVIRTUALSCREEN     = 77
%SM_CXVIRTUALSCREEN    = 78
%SM_CYVIRTUALSCREEN    = 79
%SM_CMONITORS          = 80
%SM_SAMEDISPLAYFORMAT  = 81
#ENDIF ' %WINVER >= &H0500
#IF (%WIN32_WINNT >= &H0500)
%SM_IMMENABLED         = 82
#ENDIF ' %WIN32_WINNT >= &H0500
#IF (%WIN32_WINNT >= &H0501)
%SM_CXFOCUSBORDER      = 83
%SM_CYFOCUSBORDER      = 84
#ENDIF ' %WIN32_WINNT >= &H0501

#IF (%WIN32_WINNT >= &H0501)
%SM_TABLETPC           = 86
%SM_MEDIACENTER        = 87
%SM_STARTER            = 88
%SM_SERVERR2           = 89
#ENDIF ' %WIN32_WINNT >= &H0501

#IF (%WIN32_WINNT >= &H0600)
%SM_MOUSEHORIZONTALWHEELPRESENT  = 91
%SM_CXPADDEDBORDER     = 92
#ENDIF ' %WIN32_WINNT >= &H0600

#IF (%WINVER >= &H0601)
%SM_DIGITIZER          = 94
%SM_MAXIMUMTOUCHES     = 95
#ENDIF  ' %WINVER >= &H0601

#IF (%WINVER < &H0500) AND (NOT %DEF(%WIN32_WINNT) OR (%WIN32_WINNT < &H0400))
%SM_CMETRICS           = 76
#ELSEIF %WINVER = &H500
%SM_CMETRICS           = 83
#ELSEIF %WINVER = &H501
%SM_CMETRICS           = 91
#ELSEIF %winver = &H600
%SM_CMETRICS           = 93
#ELSEIF %WINVER = &H600
%SM_CMETRICS           = 93
#ELSE
%SM_CMETRICS           = 97
#ENDIF

#IF (%WINVER >= &H0500)
%SM_REMOTESESSION      = &H1000

#IF (%WIN32_WINNT >= &H0501)
%SM_SHUTTINGDOWN       = &H2000
#ENDIF ' %WIN32_WINNT >= &H0501

#IF (%WINVER >= &H0501)
%SM_REMOTECONTROL      = &H2001
#ENDIF ' %WINVER >= &H0501

#IF (%WINVER >= &H0501)
%SM_CARETBLINKINGENABLED = &H2002
#ENDIF ' %WINVER >= &H0501

#ENDIF ' %WINVER >= &H0500


DECLARE FUNCTION GetSystemMetrics LIB "User32.dll" ALIAS "GetSystemMetrics" _
    (BYVAL nIndex AS LONG) AS LONG


#ENDIF ' NOT %NOSYSMETRICS

#IF NOT %DEF(%NOMENUS)

DECLARE FUNCTION LoadMenuA LIB "User32.dll" ALIAS "LoadMenuA" _
    (BYVAL hInstance AS DWORD, lpString AS ASCIIZ) AS DWORD

DECLARE FUNCTION LoadMenuW LIB "User32.dll" ALIAS "LoadMenuW" _
    (BYVAL hInstance AS DWORD, lpString AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION LoadMenu LIB "User32.dll" ALIAS "LoadMenuW" _
    (BYVAL hInstance AS DWORD, lpString AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION LoadMenu LIB "User32.dll" ALIAS "LoadMenuA" _
    (BYVAL hInstance AS DWORD, lpString AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION LoadMenuIndirectA LIB "User32.dll" ALIAS "LoadMenuIndirectA" _
    (lpMenuTemplate AS ANY) AS DWORD

DECLARE FUNCTION LoadMenuIndirectW LIB "User32.dll" ALIAS "LoadMenuIndirectW" _
    (lpMenuTemplate AS ANY) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION LoadMenuIndirect LIB "User32.dll" ALIAS "LoadMenuIndirectW" _
    (lpMenuTemplate AS ANY) AS DWORD
#ELSE
DECLARE FUNCTION LoadMenuIndirect LIB "User32.dll" ALIAS "LoadMenuIndirectA" _
    (lpMenuTemplate AS ANY) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetMenu LIB "User32.dll" ALIAS "GetMenu" _
    (BYVAL hWnd AS DWORD) AS DWORD

DECLARE FUNCTION SetMenu LIB "User32.dll" ALIAS "SetMenu" _
    (BYVAL hWnd AS DWORD, OPTIONAL BYVAL hMenu AS DWORD) AS LONG

DECLARE FUNCTION ChangeMenuA LIB "User32.dll" ALIAS "ChangeMenuA" _
    (BYVAL hMenu AS DWORD, BYVAL cmd AS DWORD, lpszNewItem AS ASCIIZ, _
    BYVAL cmdInsert AS DWORD, BYVAL flags AS DWORD) AS LONG

DECLARE FUNCTION ChangeMenuW LIB "User32.dll" ALIAS "ChangeMenuW" _
    (BYVAL hMenu AS DWORD, BYVAL cmd AS DWORD, lpszNewItem AS WSTRINGZ, _
    BYVAL cmdInsert AS DWORD, BYVAL flags AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ChangeMenu LIB "User32.dll" ALIAS "ChangeMenuW" _
    (BYVAL hMenu AS DWORD, BYVAL cmd AS DWORD, lpszNewItem AS WSTRINGZ, _
    BYVAL cmdInsert AS DWORD, BYVAL flags AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION ChangeMenu LIB "User32.dll" ALIAS "ChangeMenuA" _
    (BYVAL hMenu AS DWORD, BYVAL cmd AS DWORD, lpszNewItem AS ASCIIZ, _
    BYVAL cmdInsert AS DWORD, BYVAL flags AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION HiliteMenuItem LIB "User32.dll" ALIAS "HiliteMenuItem" _
    (BYVAL hWnd AS DWORD, BYVAL hMenu AS DWORD, _
    BYVAL dwIDHiliteItem AS DWORD, BYVAL dwHilite AS DWORD) AS LONG

DECLARE FUNCTION GetMenuStringA LIB "User32.dll" ALIAS "GetMenuStringA" _
    (BYVAL hMenu AS DWORD, BYVAL uIDItem AS DWORD, lpString AS ASCIIZ, _
    BYVAL nMaxCount AS LONG, BYVAL uFlag AS DWORD) AS LONG

DECLARE FUNCTION GetMenuStringW LIB "User32.dll" ALIAS "GetMenuStringW" _
    (BYVAL hMenu AS DWORD, BYVAL uIDItem AS DWORD, lpString AS WSTRINGZ, _
    BYVAL nMaxCount AS LONG, BYVAL uFlag AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetMenuString LIB "User32.dll" ALIAS "GetMenuStringW" _
    (BYVAL hMenu AS DWORD, BYVAL uIDItem AS DWORD, lpString AS WSTRINGZ, _
    BYVAL nMaxCount AS LONG, BYVAL uFlag AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetMenuString LIB "User32.dll" ALIAS "GetMenuStringA" _
    (BYVAL hMenu AS DWORD, BYVAL uIDItem AS DWORD, lpString AS ASCIIZ, _
    BYVAL nMaxCount AS LONG, BYVAL uFlag AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetMenuState LIB "User32.dll" ALIAS "GetMenuState" _
    (BYVAL hMenu AS DWORD, BYVAL dwID AS DWORD, BYVAL dwFlags AS DWORD) _
    AS DWORD

DECLARE FUNCTION DrawMenuBar LIB "User32.dll" ALIAS "DrawMenuBar" _
    (BYVAL hWnd AS DWORD) AS LONG

#IF (%WIN32_WINNT >= &H0501)

%PMB_ACTIVE    = &H00000001

#ENDIF ' %WIN32_WINNT >= &H0501


DECLARE FUNCTION GetSystemMenu LIB "User32.dll" ALIAS "GetSystemMenu" _
    (BYVAL hWnd AS DWORD, BYVAL bRevert AS LONG) AS DWORD

DECLARE FUNCTION CreateMenu LIB "User32.dll" ALIAS "CreateMenu" () AS DWORD

DECLARE FUNCTION CreatePopupMenu LIB "User32.dll" ALIAS "CreatePopupMenu" () _
    AS DWORD

DECLARE FUNCTION DestroyMenu LIB "User32.dll" ALIAS "DestroyMenu" _
    (BYVAL hMenu AS DWORD) AS LONG

DECLARE FUNCTION CheckMenuItem LIB "User32.dll" ALIAS "CheckMenuItem" _
    (BYVAL hMenu AS DWORD, BYVAL uIDCheckItem AS DWORD, _
    BYVAL uCheck AS DWORD) AS DWORD

DECLARE FUNCTION EnableMenuItem LIB "User32.dll" ALIAS "EnableMenuItem" _
    (BYVAL hMenu AS DWORD, BYVAL uIDEnableItem AS DWORD, _
    BYVAL uEnable AS DWORD) AS LONG

DECLARE FUNCTION GetSubMenu LIB "User32.dll" ALIAS "GetSubMenu" _
    (BYVAL hMenu AS DWORD, BYVAL nPos AS LONG) AS DWORD

DECLARE FUNCTION GetMenuItemID LIB "User32.dll" ALIAS "GetMenuItemID" _
    (BYVAL hMenu AS DWORD, BYVAL nPos AS LONG) AS DWORD

DECLARE FUNCTION GetMenuItemCount LIB "User32.dll" ALIAS "GetMenuItemCount" _
    (OPTIONAL BYVAL hMenu AS DWORD) AS LONG

DECLARE FUNCTION InsertMenuA LIB "User32.dll" ALIAS "InsertMenuA" _
    (BYVAL hMenu AS DWORD, BYVAL dwPosition AS DWORD, BYVAL dwFlags AS DWORD, _
    BYVAL dwIDNewItem AS DWORD, lpNewItem AS ASCIIZ) AS LONG

DECLARE FUNCTION InsertMenuW LIB "User32.dll" ALIAS "InsertMenuW" _
    (BYVAL hMenu AS DWORD, BYVAL dwPosition AS DWORD, BYVAL dwFlags AS DWORD, _
    BYVAL dwIDNewItem AS DWORD, lpNewItem AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION InsertMenu LIB "User32.dll" ALIAS "InsertMenuW" _
    (BYVAL hMenu AS DWORD, BYVAL dwPosition AS DWORD, BYVAL dwFlags AS DWORD, _
    BYVAL dwIDNewItem AS DWORD, lpNewItem AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION InsertMenu LIB "User32.dll" ALIAS "InsertMenuA" _
    (BYVAL hMenu AS DWORD, BYVAL dwPosition AS DWORD, BYVAL dwFlags AS DWORD, _
    BYVAL dwIDNewItem AS DWORD, lpNewItem AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION AppendMenuA LIB "User32.dll" ALIAS "AppendMenuA" _
    (BYVAL hMenu AS DWORD, BYVAL uFlags AS DWORD, BYVAL uIDNewItem AS DWORD, _
    lpNewItem AS ASCIIZ) AS LONG

DECLARE FUNCTION AppendMenuW LIB "User32.dll" ALIAS "AppendMenuW" _
    (BYVAL hMenu AS DWORD, BYVAL uFlags AS DWORD, BYVAL uIDNewItem AS DWORD, _
    lpNewItem AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION AppendMenu LIB "User32.dll" ALIAS "AppendMenuW" _
    (BYVAL hMenu AS DWORD, BYVAL uFlags AS DWORD, BYVAL uIDNewItem AS DWORD, _
    lpNewItem AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION AppendMenu LIB "User32.dll" ALIAS "AppendMenuA" _
    (BYVAL hMenu AS DWORD, BYVAL uFlags AS DWORD, BYVAL uIDNewItem AS DWORD, _
    lpNewItem AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION ModifyMenuA LIB "User32.dll" ALIAS "ModifyMenuA" _
    (BYVAL hMenu AS DWORD, BYVAL dwPosition AS DWORD, BYVAL dwFlags AS DWORD, _
    BYVAL dwIDNewItem AS DWORD, lpString AS ASCIIZ) AS LONG

DECLARE FUNCTION ModifyMenuW LIB "User32.dll" ALIAS "ModifyMenuW" _
    (BYVAL hMenu AS DWORD, BYVAL dwPosition AS DWORD, BYVAL dwFlags AS DWORD, _
    BYVAL dwIDNewItem AS DWORD, lpString AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ModifyMenu LIB "User32.dll" ALIAS "ModifyMenuW" _
    (BYVAL hMenu AS DWORD, BYVAL dwPosition AS DWORD, BYVAL dwFlags AS DWORD, _
    BYVAL dwIDNewItem AS DWORD, lpString AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION ModifyMenu LIB "User32.dll" ALIAS "ModifyMenuA" _
    (BYVAL hMenu AS DWORD, BYVAL dwPosition AS DWORD, BYVAL dwFlags AS DWORD, _
    BYVAL dwIDNewItem AS DWORD, lpString AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RemoveMenu LIB "User32.dll" ALIAS "RemoveMenu" _
    (BYVAL hMenu AS DWORD, BYVAL nPosition AS DWORD, BYVAL wFlags AS DWORD) _
    AS LONG

DECLARE FUNCTION DeleteMenu LIB "User32.dll" ALIAS "DeleteMenu" _
    (BYVAL hMenu AS DWORD, BYVAL nPosition AS DWORD, BYVAL wFlags AS DWORD) _
    AS LONG

DECLARE FUNCTION SetMenuItemBitmaps LIB "User32.dll" _
    ALIAS "SetMenuItemBitmaps" (BYVAL hMenu AS DWORD, _
    BYVAL nPosition AS DWORD, BYVAL wFlags AS DWORD, _
    OPTIONAL BYVAL hBitmapUnchecked AS DWORD, _
    OPTIONAL BYVAL hBitmapChecked AS DWORD) AS LONG

DECLARE FUNCTION GetMenuCheckMarkDimensions LIB "User32.dll" _
    ALIAS "GetMenuCheckMarkDimensions" () AS LONG

DECLARE FUNCTION TrackPopupMenu LIB "User32.dll" ALIAS "TrackPopupMenu" _
    (BYVAL hMenu AS DWORD, BYVAL uFlags AS DWORD, BYVAL x AS LONG, _
    BYVAL y AS LONG, BYVAL nReserved AS LONG, BYVAL hWnd AS DWORD, _
    lprc AS RECT) AS LONG

#IF (%WINVER >= &H0400)
' return codes for %WM_MENUCHAR
%MNC_IGNORE  = 0
%MNC_CLOSE   = 1
%MNC_EXECUTE = 2
%MNC_SELECT  = 3

TYPE TPMPARAMS
    cbSize    AS DWORD  ' Size of structure
    rcExclude AS RECT   ' Screen coordinates of rectangle to exclude when positioning
END TYPE

DECLARE FUNCTION TrackPopupMenuEx LIB "User32.dll" ALIAS "TrackPopupMenuEx" _
    (BYVAL hMenu AS DWORD, BYVAL uFlags AS DWORD, BYVAL x AS LONG, _
    BYVAL y AS LONG, BYVAL hWnd AS DWORD, lpTPMParams AS TPMPARAMS) AS LONG

#ENDIF ' %WINVER >= &H0400

#IF (%WIN32_WINNT >= &H0601)
DECLARE FUNCTION CalculatePopupWindowPosition LIB "User32.dll" _
    ALIAS "CalculatePopupWindowPosition" ( _
    anchorPoint AS POINT, _
    windowSize  AS SIZE, _
    BYVAL flags AS DWORD, _  ' %TPM_XXX values
    excludeRect AS RECT, _
    popupWindowPosition AS rect) _
    AS LONG
#ENDIF  ' %WIN32_WINNT >= &H0601

#IF (%WINVER >= &H0500)

%MNS_NOCHECK      = &H80000000???
%MNS_MODELESS     = &H40000000
%MNS_DRAGDROP     = &H20000000
%MNS_AUTODISMISS  = &H10000000
%MNS_NOTIFYBYPOS  = &H08000000
%MNS_CHECKORBMP   = &H04000000

%MIM_MAXHEIGHT            = &H00000001
%MIM_BACKGROUND           = &H00000002
%MIM_HELPID               = &H00000004
%MIM_MENUDATA             = &H00000008
%MIM_STYLE                = &H00000010
%MIM_APPLYTOSUBMENUS      = &H80000000???

TYPE MENUINFO
    cbSize          AS DWORD
    fMask           AS DWORD
    dwStyle         AS DWORD
    cyMax           AS DWORD
    hbrBack         AS DWORD
    dwContextHelpID AS DWORD
    dwMenuData      AS DWORD
END TYPE


DECLARE FUNCTION GetMenuInfo LIB "User32.dll" ALIAS "GetMenuInfo" _
    (BYVAL hmenu AS DWORD, lpcmi AS MENUINFO) AS LONG

DECLARE FUNCTION SetMenuInfo LIB "User32.dll" ALIAS "SetMenuInfo" _
    (BYVAL hmenu AS DWORD, lpcmi AS MENUINFO) AS LONG

DECLARE FUNCTION EndMenu LIB "User32.dll" ALIAS "EndMenu" () AS LONG


'
' %WM_MENUDRAG return values.
'
%MND_CONTINUE     = 0
%MND_ENDMENU      = 1

TYPE MENUGETOBJECTINFO
    dwFlags AS DWORD
    uPos    AS DWORD
    hmenu   AS DWORD
    riid    AS DWORD
    pvObj   AS DWORD
END TYPE

'
' MENUGETOBJECTINFO dwFlags values
'
%MNGOF_TOPGAP       = &H00000001
%MNGOF_BOTTOMGAP    = &H00000002

'
' %WM_MENUGETOBJECT return values
'
%MNGO_NOINTERFACE    = &H00000000
%MNGO_NOERROR        = &H00000001
#ENDIF ' %WINVER >= &H0500

#IF (%WINVER >= &H0400)
%MIIM_STATE      = &H00000001
%MIIM_ID         = &H00000002
%MIIM_SUBMENU    = &H00000004
%MIIM_CHECKMARKS = &H00000008
%MIIM_TYPE       = &H00000010
%MIIM_DATA       = &H00000020
#ENDIF ' %WINVER >= &H0400

#IF (%WINVER >= &H0500)
%MIIM_STRING     = &H00000040
%MIIM_BITMAP     = &H00000080
%MIIM_FTYPE      = &H00000100

%HBMMENU_CALLBACK            = &HFFFFFFFF???
%HBMMENU_SYSTEM              =  1
%HBMMENU_MBAR_RESTORE        =  2
%HBMMENU_MBAR_MINIMIZE       =  3
%HBMMENU_MBAR_CLOSE          =  5
%HBMMENU_MBAR_CLOSE_D        =  6
%HBMMENU_MBAR_MINIMIZE_D     =  7
%HBMMENU_POPUP_CLOSE         =  8
%HBMMENU_POPUP_RESTORE       =  9
%HBMMENU_POPUP_MAXIMIZE      = 10
%HBMMENU_POPUP_MINIMIZE      = 11
#ENDIF ' %WINVER >= &H0500

#IF (%WINVER >= &H0400)
TYPE MENUITEMINFOA
    cbSize        AS DWORD
    fMask         AS DWORD
    fType         AS DWORD      ' used if MIIM_TYPE (4.0) or MIIM_FTYPE (>4.0)
    fState        AS DWORD      ' used if MIIM_STATE
    wID           AS DWORD      ' used if MIIM_ID
    hSubMenu      AS DWORD      ' used if MIIM_SUBMENU
    hbmpChecked   AS DWORD      ' used if MIIM_CHECKMARKS
    hbmpUnchecked AS DWORD      ' used if MIIM_CHECKMARKS
    dwItemData    AS DWORD      ' used if MIIM_DATA
    dwTypeData    AS ASCIIZ PTR ' used if MIIM_TYPE (4.0) or MIIM_STRING (>4.0)
    cch           AS DWORD      ' used if MIIM_TYPE (4.0) or MIIM_STRING (>4.0)
#IF (%WINVER >= &H0500)
    hbmpItem      AS DWORD      ' used if MIIM_BITMAP
#ENDIF ' %WINVER >= &H0500
END TYPE

TYPE MENUITEMINFOW
    cbSize        AS DWORD
    fMask         AS DWORD
    fType         AS DWORD      ' used if MIIM_TYPE (4.0) or MIIM_FTYPE (>4.0)
    fState        AS DWORD      ' used if MIIM_STATE
    wID           AS DWORD      ' used if MIIM_ID
    hSubMenu      AS DWORD      ' used if MIIM_SUBMENU
    hbmpChecked   AS DWORD      ' used if MIIM_CHECKMARKS
    hbmpUnchecked AS DWORD      ' used if MIIM_CHECKMARKS
    dwItemData    AS DWORD      ' used if MIIM_DATA
    dwTypeData    AS WSTRINGZ PTR ' used if MIIM_TYPE (4.0) or MIIM_STRING (>4.0)
    cch           AS DWORD      ' used if MIIM_TYPE (4.0) or MIIM_STRING (>4.0)
#IF (%WINVER >= &H0500)
    hbmpItem      AS DWORD      ' used if MIIM_BITMAP
#ENDIF ' %WINVER >= &H0500
END TYPE

#IF %DEF(%UNICODE)
TYPE MENUITEMINFO
    MENUITEMINFOW
END TYPE
#ELSE
TYPE MENUITEMINFO
    MENUITEMINFOA
END TYPE
#ENDIF ' UNICODE

DECLARE FUNCTION InsertMenuItemA LIB "User32.dll" ALIAS "InsertMenuItemA" _
    (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG, _
    lpcMenuItemInfo AS MENUITEMINFOA) AS LONG

DECLARE FUNCTION InsertMenuItemW LIB "User32.dll" ALIAS "InsertMenuItemW" _
    (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG, _
    lpcMenuItemInfo AS MENUITEMINFOW) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION InsertMenuItem LIB "User32.dll" ALIAS "InsertMenuItemW" _
    (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG, _
    lpcMenuItemInfo AS MENUITEMINFOW) AS LONG
#ELSE
DECLARE FUNCTION InsertMenuItem LIB "User32.dll" ALIAS "InsertMenuItemA" _
    (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG, _
    lpcMenuItemInfo AS MENUITEMINFOA) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetMenuItemInfoA LIB "User32.dll" ALIAS "GetMenuItemInfoA" _
    (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG, _
    lpMenuItemInfo AS MENUITEMINFOA) AS LONG

DECLARE FUNCTION GetMenuItemInfoW LIB "User32.dll" ALIAS "GetMenuItemInfoW" _
    (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG, _
    lpMenuItemInfo AS MENUITEMINFOW) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetMenuItemInfo LIB "User32.dll" ALIAS "GetMenuItemInfoW" _
    (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG, _
    lpMenuItemInfo AS MENUITEMINFOW) AS LONG
#ELSE
DECLARE FUNCTION GetMenuItemInfo LIB "User32.dll" ALIAS "GetMenuItemInfoA" _
    (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG, _
    lpMenuItemInfo AS MENUITEMINFOA) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetMenuItemInfoA LIB "User32.dll" ALIAS "SetMenuItemInfoA" _
    (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG, _
    lpcMenuItemInfo AS MENUITEMINFO) AS LONG

DECLARE FUNCTION SetMenuItemInfoW LIB "User32.dll" ALIAS "SetMenuItemInfoW" _
    (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG, _
    lpcMenuItemInfo AS MENUITEMINFO) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetMenuItemInfo LIB "User32.dll" ALIAS "SetMenuItemInfoW" _
    (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG, _
    lpcMenuItemInfo AS MENUITEMINFO) AS LONG
#ELSE
DECLARE FUNCTION SetMenuItemInfo LIB "User32.dll" ALIAS "SetMenuItemInfoA" _
    (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG, _
    lpcMenuItemInfo AS MENUITEMINFO) AS LONG
#ENDIF ' NOT %UNICODE


%GMDI_USEDISABLED  = &H0001
%GMDI_GOINTOPOPUPS = &H0002

DECLARE FUNCTION GetMenuDefaultItem LIB "User32.dll" _
    ALIAS "GetMenuDefaultItem" (BYVAL hMenu AS DWORD, BYVAL fByPos AS DWORD, _
    BYVAL gmdiFlags AS DWORD) AS DWORD

DECLARE FUNCTION SetMenuDefaultItem LIB "User32.dll" _
    ALIAS "SetMenuDefaultItem" (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, _
    BYVAL fByPos AS DWORD) AS LONG

DECLARE FUNCTION GetMenuItemRect LIB "User32.dll" ALIAS "GetMenuItemRect" _
    (BYVAL hWnd AS DWORD, BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, _
    lprcItem AS RECT) AS LONG

DECLARE FUNCTION MenuItemFromPoint LIB "User32.dll" ALIAS "MenuItemFromPoint" _
    (BYVAL hWnd AS DWORD, BYVAL hMenu AS DWORD, BYVAL ptScreen AS POINT) _
    AS LONG

#ENDIF ' %WINVER >= &H0400

'
' Flags for TrackPopupMenu
'
%TPM_LEFTBUTTON    = &H0000
%TPM_RIGHTBUTTON   = &H0002
%TPM_LEFTALIGN     = &H0000
%TPM_CENTERALIGN   = &H0004
%TPM_RIGHTALIGN    = &H0008
#IF (%WINVER >= &H0400)
%TPM_TOPALIGN      = &H0000
%TPM_VCENTERALIGN  = &H0010
%TPM_BOTTOMALIGN   = &H0020

%TPM_HORIZONTAL    = &H0000     ' Horz alignment matters more
%TPM_VERTICAL      = &H0040     ' Vert alignment matters more
%TPM_NONOTIFY      = &H0080     ' Don't send any notification msgs
%TPM_RETURNCMD     = &H0100
#ENDIF ' %WINVER >= &H0400
#IF (%WINVER >= &H0500)
%TPM_RECURSE           = &H0001
%TPM_HORPOSANIMATION   = &H0400
%TPM_HORNEGANIMATION   = &H0800
%TPM_VERPOSANIMATION   = &H1000
%TPM_VERNEGANIMATION   = &H2000
#IF (%WIN32_WINNT >= &H0500)
%TPM_NOANIMATION       = &H4000
#ENDIF ' %WIN32_WINNT >= &H0500
#IF (%WIN32_WINNT >= &H0501)
%TPM_LAYOUTRTL         = &H8000??
#ENDIF ' %WIN32_WINNT >= &H0501
#ENDIF ' %WINVER >= &H0500
#IF (%WIN32_WINNT >= &H0601)
%TPM_WORKAREA          = &H10000
#ENDIF  ' %WIN32_WINNT >= &H0601


#ENDIF ' NOT %NOMENUS


#IF (%WINVER >= &H0400)
'
' Drag-and-drop support
' Obsolete - use OLE instead
'
TYPE DROPSTRUCT
    hwndSource    AS DWORD
    hwndSink      AS DWORD
    wFmt          AS DWORD
    dwData        AS DWORD
    ptDrop        AS POINT
    dwControlData AS DWORD
END TYPE

%DOF_EXECUTABLE    = &H00008001      ' wFmt flags
%DOF_DOCUMENT      = &H8002??
%DOF_DIRECTORY     = &H8003??
%DOF_MULTIPLE      = &H8004??
%DOF_PROGMAN       = &H0001
%DOF_SHELLDATA     = &H0002

%DO_DROPFILE       = &H454C4946
%DO_PRINTFILE      = &H544E5250


DECLARE FUNCTION DragObject LIB "User32.dll" ALIAS "DragObject" _
    (BYVAL hwnd1 AS DWORD, BYVAL hwnd2 AS DWORD, BYVAL ui AS DWORD, _
    BYVAL ui2 AS DWORD, OPTIONAL BYVAL hCursor AS DWORD) AS DWORD

DECLARE FUNCTION DragDetect LIB "User32.dll" ALIAS "DragDetect" _
    (BYVAL hWnd AS DWORD, BYVAL pt AS POINT) AS LONG

#ENDIF ' %WINVER >= &H0400

DECLARE FUNCTION DrawIcon LIB "User32.dll" ALIAS "DrawIcon" _
    (BYVAL hDC AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    BYVAL hIcon AS DWORD) AS LONG

#IF NOT %DEF(%NODRAWTEXT)

'
' DrawText() Format Flags
'
%DT_TOP                  = &H00000000
%DT_LEFT                 = &H00000000
%DT_CENTER               = &H00000001
%DT_RIGHT                = &H00000002
%DT_VCENTER              = &H00000004
%DT_BOTTOM               = &H00000008
%DT_WORDBREAK            = &H00000010
%DT_SINGLELINE           = &H00000020
%DT_EXPANDTABS           = &H00000040
%DT_TABSTOP              = &H00000080
%DT_NOCLIP               = &H00000100
%DT_EXTERNALLEADING      = &H00000200
%DT_CALCRECT             = &H00000400
%DT_NOPREFIX             = &H00000800
%DT_INTERNAL             = &H00001000

#IF (%WINVER >= &H0400)
%DT_EDITCONTROL          = &H00002000
%DT_PATH_ELLIPSIS        = &H00004000
%DT_END_ELLIPSIS         = &H00008000
%DT_MODIFYSTRING         = &H00010000
%DT_RTLREADING           = &H00020000
%DT_WORD_ELLIPSIS        = &H00040000
#IF (%WINVER >= &H0500)
%DT_NOFULLWIDTHCHARBREAK = &H00080000
#IF (%WIN32_WINNT >= &H0500)
%DT_HIDEPREFIX           = &H00100000
%DT_PREFIXONLY           = &H00200000
#ENDIF ' %WIN32_WINNT >= &H0500
#ENDIF ' %WINVER >= &H0500

TYPE DRAWTEXTPARAMS
    cbSize        AS DWORD
    iTabLength    AS LONG
    iLeftMargin   AS LONG
    iRightMargin  AS LONG
    uiLengthDrawn AS DWORD
END TYPE

#ENDIF ' %WINVER >= &H0400

DECLARE FUNCTION DrawTextA LIB "User32.dll" ALIAS "DrawTextA" _
    (BYVAL hDC AS DWORD, lpStr AS ASCIIZ, BYVAL nCount AS LONG, _
    lpRect AS RECT, BYVAL uFormat AS DWORD) AS LONG

DECLARE FUNCTION DrawTextW LIB "User32.dll" ALIAS "DrawTextW" _
    (BYVAL hDC AS DWORD, lpStr AS WSTRINGZ, BYVAL nCount AS LONG, _
    lpRect AS RECT, BYVAL uFormat AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION DrawText LIB "User32.dll" ALIAS "DrawTextW" _
    (BYVAL hDC AS DWORD, lpStr AS WSTRINGZ, BYVAL nCount AS LONG, _
    lpRect AS RECT, BYVAL uFormat AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION DrawText LIB "User32.dll" ALIAS "DrawTextA" _
    (BYVAL hDC AS DWORD, lpStr AS ASCIIZ, BYVAL nCount AS LONG, _
    lpRect AS RECT, BYVAL uFormat AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE


#IF (%WINVER >= &H0400)

DECLARE FUNCTION DrawTextExA LIB "User32.dll" ALIAS "DrawTextExA" _
    (BYVAL hDC AS DWORD, lpsz AS ASCIIZ, BYVAL n AS LONG, lpRect AS RECT, _
    BYVAL dwDTFormat AS DWORD, lpDrawTextParams AS DRAWTEXTPARAMS) AS LONG

DECLARE FUNCTION DrawTextExW LIB "User32.dll" ALIAS "DrawTextExW" _
    (BYVAL hDC AS DWORD, lpsz AS WSTRINGZ, BYVAL n AS LONG, lpRect AS RECT, _
    BYVAL dwDTFormat AS DWORD, lpDrawTextParams AS DRAWTEXTPARAMS) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION DrawTextEx LIB "User32.dll" ALIAS "DrawTextExW" _
    (BYVAL hDC AS DWORD, lpsz AS WSTRINGZ, BYVAL n AS LONG, lpRect AS RECT, _
    BYVAL dwDTFormat AS DWORD, lpDrawTextParams AS DRAWTEXTPARAMS) AS LONG
#ELSE
DECLARE FUNCTION DrawTextEx LIB "User32.dll" ALIAS "DrawTextExA" _
    (BYVAL hDC AS DWORD, lpsz AS ASCIIZ, BYVAL n AS LONG, lpRect AS RECT, _
    BYVAL dwDTFormat AS DWORD, lpDrawTextParams AS DRAWTEXTPARAMS) AS LONG
#ENDIF ' NOT %UNICODE
#ENDIF ' %WINVER >= &H0400

#ENDIF ' NOT %NODRAWTEXT

DECLARE FUNCTION GrayStringA LIB "User32.dll" ALIAS "GrayStringA" _
    (BYVAL hDC AS DWORD, BYVAL hBrush AS DWORD, BYVAL lpOutputFunc AS DWORD, _
    BYVAL lpData AS LONG, BYVAL nCount AS LONG, BYVAL X AS LONG, _
    BYVAL Y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS LONG

DECLARE FUNCTION GrayStringW LIB "User32.dll" ALIAS "GrayStringW" _
    (BYVAL hDC AS DWORD, BYVAL hBrush AS DWORD, BYVAL lpOutputFunc AS DWORD, _
    BYVAL lpData AS LONG, BYVAL nCount AS LONG, BYVAL X AS LONG, _
    BYVAL Y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GrayString LIB "User32.dll" ALIAS "GrayStringW" _
    (BYVAL hDC AS DWORD, BYVAL hBrush AS DWORD, BYVAL lpOutputFunc AS DWORD, _
    BYVAL lpData AS LONG, BYVAL nCount AS LONG, BYVAL X AS LONG, _
    BYVAL Y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS LONG
#ELSE
DECLARE FUNCTION GrayString LIB "User32.dll" ALIAS "GrayStringA" _
    (BYVAL hDC AS DWORD, BYVAL hBrush AS DWORD, BYVAL lpOutputFunc AS DWORD, _
    BYVAL lpData AS LONG, BYVAL nCount AS LONG, BYVAL X AS LONG, _
    BYVAL Y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

#IF (%WINVER >= &H0400)
' Monolithic state-drawing routine
' Image type
%DST_COMPLEX    = &H0000
%DST_TEXT       = &H0001
%DST_PREFIXTEXT = &H0002
%DST_ICON       = &H0003
%DST_BITMAP     = &H0004

' State type
%DSS_NORMAL     = &H0000
%DSS_UNION      = &H0010  ' Gray string appearance
%DSS_DISABLED   = &H0020
%DSS_MONO       = &H0080
#IF (%WIN32_WINNT >= &H0500)
%DSS_HIDEPREFIX = &H0200
%DSS_PREFIXONLY = &H0400
#ENDIF ' _WIN32_WINNT >= &H0500
%DSS_RIGHT      = &H8000??

DECLARE FUNCTION DrawStateA LIB "User32.dll" ALIAS "DrawStateA" _
    (BYVAL hDC AS DWORD, BYVAL hBrush AS DWORD, _
    BYVAL lpDrawStateProc AS DWORD, BYVAL lParam AS LONG, _
    BYVAL wParam AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    BYVAL cx AS LONG, BYVAL cy AS LONG, BYVAL fuFlags AS DWORD) AS LONG

DECLARE FUNCTION DrawStateW LIB "User32.dll" ALIAS "DrawStateW" _
    (BYVAL hDC AS DWORD, BYVAL hBrush AS DWORD, _
    BYVAL lpDrawStateProc AS DWORD, BYVAL lParam AS LONG, _
    BYVAL wParam AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    BYVAL cx AS LONG, BYVAL cy AS LONG, BYVAL fuFlags AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION DrawState LIB "User32.dll" ALIAS "DrawStateW" _
    (BYVAL hDC AS DWORD, BYVAL hBrush AS DWORD, _
    BYVAL lpDrawStateProc AS DWORD, BYVAL lParam AS LONG, _
    BYVAL wParam AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    BYVAL cx AS LONG, BYVAL cy AS LONG, BYVAL fuFlags AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION DrawState LIB "User32.dll" ALIAS "DrawStateA" _
    (BYVAL hDC AS DWORD, BYVAL hBrush AS DWORD, _
    BYVAL lpDrawStateProc AS DWORD, BYVAL lParam AS LONG, _
    BYVAL wParam AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    BYVAL cx AS LONG, BYVAL cy AS LONG, BYVAL fuFlags AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE
#ENDIF ' %WINVER >= &H0400

DECLARE FUNCTION TabbedTextOutA LIB "User32.dll" ALIAS "TabbedTextOutA" _
    (BYVAL hDC AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    lpString AS ASCIIZ, BYVAL nCount AS LONG, BYVAL nTabPositions AS LONG, _
    lpnTabStopPositions AS LONG, BYVAL nTabOrigin AS LONG) AS LONG

DECLARE FUNCTION TabbedTextOutW LIB "User32.dll" ALIAS "TabbedTextOutW" _
    (BYVAL hDC AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    lpString AS WSTRINGZ, BYVAL nCount AS LONG, BYVAL nTabPositions AS LONG, _
    lpnTabStopPositions AS LONG, BYVAL nTabOrigin AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION TabbedTextOut LIB "User32.dll" ALIAS "TabbedTextOutW" _
    (BYVAL hDC AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    lpString AS WSTRINGZ, BYVAL nCount AS LONG, BYVAL nTabPositions AS LONG, _
    lpnTabStopPositions AS LONG, BYVAL nTabOrigin AS LONG) AS LONG
#ELSE
DECLARE FUNCTION TabbedTextOut LIB "User32.dll" ALIAS "TabbedTextOutA" _
    (BYVAL hDC AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    lpString AS ASCIIZ, BYVAL nCount AS LONG, BYVAL nTabPositions AS LONG, _
    lpnTabStopPositions AS LONG, BYVAL nTabOrigin AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetTabbedTextExtentA LIB "User32.dll" _
    ALIAS "GetTabbedTextExtentA" (BYVAL hDC AS DWORD, lpString AS ASCIIZ, _
    BYVAL nCount AS LONG, BYVAL nTabPositions AS LONG, _
    lpnTabStopPositions AS LONG) AS DWORD

DECLARE FUNCTION GetTabbedTextExtentW LIB "User32.dll" _
    ALIAS "GetTabbedTextExtentW" (BYVAL hDC AS DWORD, lpString AS WSTRINGZ, _
    BYVAL nCount AS LONG, BYVAL nTabPositions AS LONG, _
    lpnTabStopPositions AS LONG) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetTabbedTextExtent LIB "User32.dll" _
    ALIAS "GetTabbedTextExtentW" (BYVAL hDC AS DWORD, lpString AS WSTRINGZ, _
    BYVAL nCount AS LONG, BYVAL nTabPositions AS LONG, _
    lpnTabStopPositions AS LONG) AS DWORD
#ELSE
DECLARE FUNCTION GetTabbedTextExtent LIB "User32.dll" _
    ALIAS "GetTabbedTextExtentA" (BYVAL hDC AS DWORD, lpString AS ASCIIZ, _
    BYVAL nCount AS LONG, BYVAL nTabPositions AS LONG, _
    lpnTabStopPositions AS LONG) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION UpdateWindow LIB "User32.dll" ALIAS "UpdateWindow" _
    (BYVAL hWnd AS DWORD) AS LONG

DECLARE FUNCTION SetActiveWindow LIB "User32.dll" ALIAS "SetActiveWindow" _
    (BYVAL hWnd AS DWORD) AS DWORD

DECLARE FUNCTION GetForegroundWindow LIB "User32.dll" _
    ALIAS "GetForegroundWindow" () AS DWORD

#IF (%WINVER >= &H0400)

DECLARE FUNCTION PaintDesktop LIB "User32.dll" ALIAS "PaintDesktop" _
    (BYVAL hDC AS DWORD) AS LONG

DECLARE SUB SwitchToThisWindow LIB "User32.dll" ALIAS "SwitchToThisWindow" _
    (BYVAL hwnd AS DWORD, BYVAL fUnknown AS LONG)

#ENDIF ' %WINVER >= &H0400

DECLARE FUNCTION SetForegroundWindow LIB "User32.dll" _
    ALIAS "SetForegroundWindow" (BYVAL hWnd AS DWORD) AS LONG

#IF (%WIN32_WINNT >= &H0500)

DECLARE FUNCTION AllowSetForegroundWindow LIB "User32.dll" _
    ALIAS "AllowSetForegroundWindow" (BYVAL dwProcessId AS DWORD) AS LONG

%ASFW_ANY = &HFFFFFFFF???

DECLARE FUNCTION LockSetForegroundWindow LIB "User32.dll" _
    ALIAS "LockSetForegroundWindow" (BYVAL uLockCode AS DWORD) AS LONG

%LSFW_LOCK     = 1
%LSFW_UNLOCK   = 2

#ENDIF ' %WIN32_WINNT >= &H0500

DECLARE FUNCTION WindowFromDC LIB "User32.dll" ALIAS "WindowFromDC" _
    (BYVAL hDC AS DWORD) AS DWORD

DECLARE FUNCTION GetDC LIB "User32.dll" ALIAS "GetDC" ( _
    OPTIONAL BYVAL hWnd AS DWORD) AS DWORD

DECLARE FUNCTION GetDCEx LIB "User32.dll" ALIAS "GetDCEx" _
    (BYVAL hWnd AS DWORD, BYVAL hRgnClip AS DWORD, BYVAL fdwOptions AS DWORD) _
    AS DWORD

'
' GetDCEx() flags
'
%DCX_WINDOW           = &H00000001
%DCX_CACHE            = &H00000002
%DCX_NORESETATTRS     = &H00000004
%DCX_CLIPCHILDREN     = &H00000008
%DCX_CLIPSIBLINGS     = &H00000010
%DCX_PARENTCLIP       = &H00000020
%DCX_EXCLUDERGN       = &H00000040
%DCX_INTERSECTRGN     = &H00000080
%DCX_EXCLUDEUPDATE    = &H00000100
%DCX_INTERSECTUPDATE  = &H00000200
%DCX_LOCKWINDOWUPDATE = &H00000400

%DCX_VALIDATE         = &H00200000

DECLARE FUNCTION GetWindowDC LIB "User32.dll" ALIAS "GetWindowDC" _
    (OPTIONAL BYVAL hWnd AS DWORD) AS DWORD

DECLARE FUNCTION ReleaseDC LIB "User32.dll" ALIAS "ReleaseDC" _
    (BYVAL hWnd AS DWORD, BYVAL hDC AS DWORD) AS LONG

DECLARE FUNCTION BeginPaint LIB "User32.dll" ALIAS "BeginPaint" _
    (BYVAL hWnd AS DWORD, lpPaint AS PAINTSTRUCT) AS DWORD

DECLARE FUNCTION EndPaint LIB "User32.dll" ALIAS "EndPaint" _
    (BYVAL hWnd AS DWORD, lpPaint AS PAINTSTRUCT) AS LONG

DECLARE FUNCTION GetUpdateRect LIB "User32.dll" ALIAS "GetUpdateRect" _
    (BYVAL hWnd AS DWORD, lpRect AS RECT, BYVAL bErase AS LONG) AS LONG

DECLARE FUNCTION GetUpdateRgn LIB "User32.dll" ALIAS "GetUpdateRgn" _
    (BYVAL hWnd AS DWORD, BYVAL hRgn AS DWORD, BYVAL fErase AS LONG) AS LONG

DECLARE FUNCTION SetWindowRgn LIB "User32.dll" ALIAS "SetWindowRgn" _
    (BYVAL hWnd AS DWORD, BYVAL hRgn AS DWORD, BYVAL bRedraw AS LONG) AS LONG

DECLARE FUNCTION GetWindowRgn LIB "User32.dll" ALIAS "GetWindowRgn" _
    (BYVAL hWnd AS DWORD, BYVAL hRgn AS DWORD) AS LONG

#IF (%WIN32_WINNT >= &H0501)

DECLARE FUNCTION GetWindowRgnBox LIB "User32.dll" ALIAS "GetWindowRgnBox" _
    (BYVAL hWnd AS DWORD, lprc AS RECT) AS LONG

#ENDIF ' %WIN32_WINNT >= &H0501

DECLARE FUNCTION ExcludeUpdateRgn LIB "User32.dll" ALIAS "ExcludeUpdateRgn" _
    (BYVAL hDC AS DWORD, BYVAL hWnd AS DWORD) AS LONG

DECLARE FUNCTION InvalidateRect LIB "User32.dll" ALIAS "InvalidateRect" _
    (BYVAL hWnd AS DWORD, lpRect AS RECT, BYVAL bErase AS LONG) AS LONG

DECLARE FUNCTION ValidateRect LIB "User32.dll" ALIAS "ValidateRect" _
    (BYVAL hWnd AS DWORD, lpRect AS RECT) AS LONG

DECLARE FUNCTION InvalidateRgn LIB "User32.dll" ALIAS "InvalidateRgn" _
    (BYVAL hWnd AS DWORD, BYVAL hRgn AS DWORD, BYVAL bErase AS LONG) AS LONG

DECLARE FUNCTION ValidateRgn LIB "User32.dll" ALIAS "ValidateRgn" _
    (BYVAL hWnd AS DWORD, OPTIONAL BYVAL hRgn AS DWORD) AS LONG

DECLARE FUNCTION RedrawWindow LIB "User32.dll" ALIAS "RedrawWindow" _
    (BYVAL hWnd AS DWORD, lprcUpdate AS RECT, BYVAL hRgnUpdate AS DWORD, _
    BYVAL fuRedraw AS DWORD) AS LONG

'
' RedrawWindow() flags
'
%RDW_INVALIDATE       = &H0001
%RDW_INTERNALPAINT    = &H0002
%RDW_ERASE            = &H0004

%RDW_VALIDATE         = &H0008
%RDW_NOINTERNALPAINT  = &H0010
%RDW_NOERASE          = &H0020

%RDW_NOCHILDREN       = &H0040
%RDW_ALLCHILDREN      = &H0080

%RDW_UPDATENOW        = &H0100
%RDW_ERASENOW         = &H0200

%RDW_FRAME            = &H0400
%RDW_NOFRAME          = &H0800


'
' LockWindowUpdate API
'

DECLARE FUNCTION LockWindowUpdate LIB "User32.dll" ALIAS "LockWindowUpdate" _
    (OPTIONAL BYVAL hWndLock AS DWORD) AS LONG

DECLARE FUNCTION ScrollWindow LIB "User32.dll" ALIAS "ScrollWindow" _
    (BYVAL hWnd AS DWORD, BYVAL XAmount AS LONG, BYVAL YAmount AS LONG, _
    lpRect AS RECT, lpClipRect AS RECT) AS LONG

DECLARE FUNCTION ScrollDC LIB "User32.dll" ALIAS "ScrollDC" _
    (BYVAL hDC AS DWORD, BYVAL dx AS LONG, BYVAL dy AS LONG, _
    lprcScroll AS RECT, lprcClip AS RECT, BYVAL hRgnUpdate AS DWORD, _
    lprcUpdate AS RECT) AS LONG

DECLARE FUNCTION ScrollWindowEx LIB "User32.dll" ALIAS "ScrollWindowEx" _
    (BYVAL hWnd AS DWORD, BYVAL dx AS LONG, BYVAL dy AS LONG, _
    lprcScroll AS RECT, lprcClip AS RECT, BYVAL hRgnUpdate AS DWORD, _
    lprcUpdate AS RECT, BYVAL fuScroll AS DWORD) AS LONG

%SW_SCROLLCHILDREN  = &H0001  ' Scroll children within *lprcScroll.
%SW_INVALIDATE      = &H0002  ' Invalidate after scrolling
%SW_ERASE           = &H0004  ' If SW_INVALIDATE, don't send %WM_ERASEBACKGROUND
#IF (%WINVER >= &H0500)
%SW_SMOOTHSCROLL    = &H0010  ' Use smooth scrolling
#ENDIF ' %WINVER >= &H0500

#IF NOT %DEF(%NOSCROLL)

DECLARE FUNCTION SetScrollPos LIB "User32.dll" ALIAS "SetScrollPos" _
    (BYVAL hWnd AS DWORD, BYVAL nBar AS LONG, BYVAL nPos AS LONG, _
    BYVAL bRedraw AS LONG) AS LONG

DECLARE FUNCTION GetScrollPos LIB "User32.dll" ALIAS "GetScrollPos" _
    (BYVAL hWnd AS DWORD, BYVAL nBar AS LONG) AS LONG

DECLARE FUNCTION SetScrollRange LIB "User32.dll" ALIAS "SetScrollRange" _
    (BYVAL hWnd AS DWORD, BYVAL nBar AS LONG, BYVAL nMinPos AS LONG, _
    BYVAL nMaxPos AS LONG, BYVAL bRedraw AS LONG) AS LONG

DECLARE FUNCTION GetScrollRange LIB "User32.dll" ALIAS "GetScrollRange" _
    (BYVAL hWnd AS DWORD, BYVAL nBar AS LONG, lpMinPos AS LONG, _
    lpMaxPos AS LONG) AS LONG

DECLARE FUNCTION ShowScrollBar LIB "User32.dll" ALIAS "ShowScrollBar" _
    (BYVAL hWnd AS DWORD, BYVAL iBar AS LONG, BYVAL bShow AS LONG) AS LONG

DECLARE FUNCTION EnableScrollBar LIB "User32.dll" ALIAS "EnableScrollBar" _
    (BYVAL hWnd AS DWORD, BYVAL uSBflags AS DWORD, BYVAL uArrows AS DWORD) _
    AS LONG


'
' EnableScrollBar() flags
'
%ESB_ENABLE_BOTH   = &H0000
%ESB_DISABLE_BOTH  = &H0003

%ESB_DISABLE_LEFT  = &H0001
%ESB_DISABLE_RIGHT = &H0002

%ESB_DISABLE_UP    = &H0001
%ESB_DISABLE_DOWN  = &H0002

%ESB_DISABLE_LTUP  = %ESB_DISABLE_LEFT
%ESB_DISABLE_RTDN  = %ESB_DISABLE_RIGHT

#ENDIF  ' NOT %NOSCROLL


DECLARE FUNCTION SetPropA LIB "User32.dll" ALIAS "SetPropA" _
    (BYVAL hWnd AS DWORD, lpString AS ASCIIZ, _
    OPTIONAL BYVAL hData AS DWORD) AS LONG

DECLARE FUNCTION SetPropW LIB "User32.dll" ALIAS "SetPropW" _
    (BYVAL hWnd AS DWORD, lpString AS WSTRINGZ, _
    OPTIONAL BYVAL hData AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetProp LIB "User32.dll" ALIAS "SetPropW" _
    (BYVAL hWnd AS DWORD, lpString AS WSTRINGZ, _
    OPTIONAL BYVAL hData AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SetProp LIB "User32.dll" ALIAS "SetPropA" _
    (BYVAL hWnd AS DWORD, lpString AS ASCIIZ, _
    OPTIONAL BYVAL hData AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetPropA LIB "User32.dll" ALIAS "GetPropA" _
    (BYVAL hWnd AS DWORD, lpString AS ASCIIZ) AS DWORD

DECLARE FUNCTION GetPropW LIB "User32.dll" ALIAS "GetPropW" _
    (BYVAL hWnd AS DWORD, lpString AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetProp LIB "User32.dll" ALIAS "GetPropW" _
    (BYVAL hWnd AS DWORD, lpString AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION GetProp LIB "User32.dll" ALIAS "GetPropA" _
    (BYVAL hWnd AS DWORD, lpString AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RemovePropA LIB "User32.dll" ALIAS "RemovePropA" _
    (BYVAL hWnd AS DWORD, lpString AS ASCIIZ) AS DWORD

DECLARE FUNCTION RemovePropW LIB "User32.dll" ALIAS "RemovePropW" _
    (BYVAL hWnd AS DWORD, lpString AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION RemoveProp LIB "User32.dll" ALIAS "RemovePropW" _
    (BYVAL hWnd AS DWORD, lpString AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION RemoveProp LIB "User32.dll" ALIAS "RemovePropA" _
    (BYVAL hWnd AS DWORD, lpString AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumPropsExA LIB "User32.dll" ALIAS "EnumPropsExA" _
    (BYVAL hWnd AS DWORD, BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG) _
    AS LONG

DECLARE FUNCTION EnumPropsExW LIB "User32.dll" ALIAS "EnumPropsExW" _
    (BYVAL hWnd AS DWORD, BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG) _
    AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION EnumPropsEx LIB "User32.dll" ALIAS "EnumPropsExW" _
    (BYVAL hWnd AS DWORD, BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG) _
    AS LONG
#ELSE
DECLARE FUNCTION EnumPropsEx LIB "User32.dll" ALIAS "EnumPropsExA" _
    (BYVAL hWnd AS DWORD, BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG) _
    AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumPropsA LIB "User32.dll" ALIAS "EnumPropsA" _
    (BYVAL hWnd AS DWORD, BYVAL lpEnumFunc AS DWORD) AS LONG

DECLARE FUNCTION EnumPropsW LIB "User32.dll" ALIAS "EnumPropsW" _
    (BYVAL hWnd AS DWORD, BYVAL lpEnumFunc AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION EnumProps LIB "User32.dll" ALIAS "EnumPropsW" _
    (BYVAL hWnd AS DWORD, BYVAL lpEnumFunc AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION EnumProps LIB "User32.dll" ALIAS "EnumPropsA" _
    (BYVAL hWnd AS DWORD, BYVAL lpEnumFunc AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetWindowTextA LIB "User32.dll" ALIAS "SetWindowTextA" _
    (BYVAL hWnd AS DWORD, lpString AS ASCIIZ) AS LONG

DECLARE FUNCTION SetWindowTextW LIB "User32.dll" ALIAS "SetWindowTextW" _
    (BYVAL hWnd AS DWORD, lpString AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetWindowText LIB "User32.dll" ALIAS "SetWindowTextW" _
    (BYVAL hWnd AS DWORD, lpString AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION SetWindowText LIB "User32.dll" ALIAS "SetWindowTextA" _
    (BYVAL hWnd AS DWORD, lpString AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetWindowTextA LIB "User32.dll" ALIAS "GetWindowTextA" _
    (BYVAL hWnd AS DWORD, lpString AS ASCIIZ, BYVAL cch AS LONG) AS LONG

DECLARE FUNCTION GetWindowTextW LIB "User32.dll" ALIAS "GetWindowTextW" _
    (BYVAL hWnd AS DWORD, lpString AS WSTRINGZ, BYVAL cch AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetWindowText LIB "User32.dll" ALIAS "GetWindowTextW" _
    (BYVAL hWnd AS DWORD, lpString AS WSTRINGZ, BYVAL cch AS LONG) AS LONG
#ELSE
DECLARE FUNCTION GetWindowText LIB "User32.dll" ALIAS "GetWindowTextA" _
    (BYVAL hWnd AS DWORD, lpString AS ASCIIZ, BYVAL cch AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetWindowTextLengthA LIB "User32.dll" _
    ALIAS "GetWindowTextLengthA" (BYVAL hWnd AS DWORD) AS LONG

DECLARE FUNCTION GetWindowTextLengthW LIB "User32.dll" _
    ALIAS "GetWindowTextLengthW" (BYVAL hWnd AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetWindowTextLength LIB "User32.dll" _
    ALIAS "GetWindowTextLengthW" (BYVAL hWnd AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetWindowTextLength LIB "User32.dll" _
    ALIAS "GetWindowTextLengthA" (BYVAL hWnd AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetClientRect LIB "User32.dll" ALIAS "GetClientRect" _
    (BYVAL hwnd AS DWORD, lpRect AS RECT) AS LONG

DECLARE FUNCTION GetWindowRect LIB "User32.dll" ALIAS "GetWindowRect" _
    (BYVAL hWnd AS DWORD, lpRect AS RECT) AS LONG

DECLARE FUNCTION AdjustWindowRect LIB "User32.dll" ALIAS "AdjustWindowRect" _
    (lpRect AS RECT, BYVAL dwStyle AS DWORD, BYVAL bMenu AS LONG) AS LONG

DECLARE FUNCTION AdjustWindowRectEx LIB "User32.dll" _
    ALIAS "AdjustWindowRectEx" (lpRect AS RECT, BYVAL dsStyle AS DWORD, _
    BYVAL bMenu AS LONG, BYVAL dwEsStyle AS DWORD) AS LONG


#IF (%WINVER >= &H0400)

%HELPINFO_WINDOW   = &H0001
%HELPINFO_MENUITEM = &H0002

TYPE HELPINFO      ' Structure pointed to by lParam of %WM_HELP
    cbSize       AS DWORD   ' Size in bytes of this struct
    iContextType AS LONG    ' Either HELPINFO_WINDOW or HELPINFO_MENUITEM
    iCtrlId      AS LONG    ' Control Id or a Menu item Id.
    hItemHandle  AS DWORD   ' hWnd of control or hMenu.
    dwContextId  AS DWORD   ' Context Id associated with this item
    MousePos     AS POINT   ' Mouse Position in screen co-ordinates
END TYPE

DECLARE FUNCTION SetWindowContextHelpId LIB "User32.dll" _
    ALIAS "SetWindowContextHelpId" (BYVAL hWnd AS DWORD, _
    BYVAL dwContextHelpId AS DWORD) AS LONG

DECLARE FUNCTION GetWindowContextHelpId LIB "User32.dll" _
    ALIAS "GetWindowContextHelpId" (BYVAL hWnd AS DWORD) AS DWORD

DECLARE FUNCTION SetMenuContextHelpId LIB "User32.dll" _
    ALIAS "SetMenuContextHelpId" (BYVAL hMenu AS DWORD, BYVAL DW AS DWORD) _
    AS LONG

DECLARE FUNCTION GetMenuContextHelpId LIB "User32.dll" _
    ALIAS "GetMenuContextHelpId" (BYVAL hMenu AS DWORD) AS DWORD

#ENDIF ' %WINVER >= &H0400


#IF NOT %DEF(%NOMB)

'
' MessageBox() Flags
'
%MB_OK                     = &H00000000
%MB_OKCANCEL               = &H00000001
%MB_ABORTRETRYIGNORE       = &H00000002
%MB_YESNOCANCEL            = &H00000003
%MB_YESNO                  = &H00000004
%MB_RETRYCANCEL            = &H00000005
#IF (%WINVER >= &H0500)
%MB_CANCELTRYCONTINUE      = &H00000006
#ENDIF ' %WINVER >= &H0500


%MB_ICONHAND               = &H00000010
%MB_ICONQUESTION           = &H00000020
%MB_ICONEXCLAMATION        = &H00000030
%MB_ICONASTERISK           = &H00000040

#IF (%WINVER >= &H0400)
%MB_USERICON               = &H00000080
%MB_ICONWARNING            = %MB_ICONEXCLAMATION
%MB_ICONERROR              = %MB_ICONHAND
#ENDIF ' %WINVER >= &H0400

%MB_ICONINFORMATION        = %MB_ICONASTERISK
%MB_ICONSTOP               = %MB_ICONHAND

%MB_DEFBUTTON1             = &H00000000
%MB_DEFBUTTON2             = &H00000100
%MB_DEFBUTTON3             = &H00000200
#IF (%WINVER >= &H0400)
%MB_DEFBUTTON4             = &H00000300
#ENDIF ' %WINVER >= &H0400

%MB_APPLMODAL              = &H00000000
%MB_SYSTEMMODAL            = &H00001000
%MB_TASKMODAL              = &H00002000
#IF (%WINVER >= &H0400)
%MB_HELP                   = &H00004000  ' Help Button
#ENDIF ' %WINVER >= &H0400

%MB_NOFOCUS                = &H00008000
%MB_SETFOREGROUND          = &H00010000
%MB_DEFAULT_DESKTOP_ONLY   = &H00020000

#IF (%WINVER >= &H0400)
%MB_TOPMOST                = &H00040000
%MB_RIGHT                  = &H00080000
%MB_RTLREADING             = &H00100000


#ENDIF ' %WINVER >= &H0400

#IF %DEF(%WIN32_WINNT)
#IF (%WIN32_WINNT >= &H0400)
%MB_SERVICE_NOTIFICATION        = &H00200000
#ELSE
%MB_SERVICE_NOTIFICATION        = &H00040000
#ENDIF
%MB_SERVICE_NOTIFICATION_NT3X   = &H00040000
#ENDIF

%MB_TYPEMASK               = &H0000000F
%MB_ICONMASK               = &H000000F0
%MB_DEFMASK                = &H00000F00
%MB_MODEMASK               = &H00003000
%MB_MISCMASK               = &H0000C000

DECLARE FUNCTION MessageBoxA LIB "User32.dll" ALIAS "MessageBoxA" _
    (BYVAL hWnd AS DWORD, lpText AS ASCIIZ, lpCaption AS ASCIIZ, _
    BYVAL dwType AS DWORD) AS LONG

DECLARE FUNCTION MessageBoxW LIB "User32.dll" ALIAS "MessageBoxW" _
    (BYVAL hWnd AS DWORD, lpText AS WSTRINGZ, lpCaption AS WSTRINGZ, _
    BYVAL dwType AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION MessageBox LIB "User32.dll" ALIAS "MessageBoxW" _
    (BYVAL hWnd AS DWORD, lpText AS WSTRINGZ, lpCaption AS WSTRINGZ, _
    BYVAL dwType AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION MessageBox LIB "User32.dll" ALIAS "MessageBoxA" _
    (BYVAL hWnd AS DWORD, lpText AS ASCIIZ, lpCaption AS ASCIIZ, _
    BYVAL dwType AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION MessageBoxExA LIB "User32.dll" ALIAS "MessageBoxExA" _
    (BYVAL hWnd AS DWORD, lpText AS ASCIIZ, lpCaption AS ASCIIZ, _
    BYVAL uType AS DWORD, BYVAL wLanguageId AS DWORD) AS LONG

DECLARE FUNCTION MessageBoxExW LIB "User32.dll" ALIAS "MessageBoxExW" _
    (BYVAL hWnd AS DWORD, lpText AS WSTRINGZ, lpCaption AS WSTRINGZ, _
    BYVAL uType AS DWORD, BYVAL wLanguageId AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION MessageBoxEx LIB "User32.dll" ALIAS "MessageBoxExW" _
    (BYVAL hWnd AS DWORD, lpText AS WSTRINGZ, lpCaption AS WSTRINGZ, _
    BYVAL uType AS DWORD, BYVAL wLanguageId AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION MessageBoxEx LIB "User32.dll" ALIAS "MessageBoxExA" _
    (BYVAL hWnd AS DWORD, lpText AS ASCIIZ, lpCaption AS ASCIIZ, _
    BYVAL uType AS DWORD, BYVAL wLanguageId AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

#IF (%WINVER >= &H0400)

'typedef VOID (CALLBACK *MSGBOXCALLBACK)(LPHELPINFO lpHelpInfo);

TYPE MSGBOXPARAMSA
    cbSize             AS DWORD
    hwndOwner          AS DWORD
    hInstance          AS DWORD
    lpszText           AS ASCIIZ PTR
    lpszCaption        AS ASCIIZ PTR
    dwStyle            AS DWORD
    lpszIcon           AS ASCIIZ PTR
    dwContextHelpId    AS DWORD
    lpfnMsgBoxCallback AS DWORD
    dwLanguageId       AS DWORD
END TYPE

TYPE MSGBOXPARAMSW
    cbSize             AS DWORD
    hwndOwner          AS DWORD
    hInstance          AS DWORD
    lpszText           AS WSTRINGZ PTR
    lpszCaption        AS WSTRINGZ PTR
    dwStyle            AS DWORD
    lpszIcon           AS WSTRINGZ PTR
    dwContextHelpId    AS DWORD
    lpfnMsgBoxCallback AS DWORD
    dwLanguageId       AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE MSGBOXPARAMS
    MSGBOXPARAMSW
END TYPE
#ELSE
TYPE MSGBOXPARAMS
    MSGBOXPARAMSA
END TYPE
#ENDIF ' UNICODE

DECLARE FUNCTION MessageBoxIndirectA LIB "User32.dll" _
    ALIAS "MessageBoxIndirectA" (lpMsgBoxParams AS MSGBOXPARAMSA) AS LONG

DECLARE FUNCTION MessageBoxIndirectW LIB "User32.dll" _
    ALIAS "MessageBoxIndirectW" (lpMsgBoxParams AS MSGBOXPARAMSW) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION MessageBoxIndirect LIB "User32.dll" _
    ALIAS "MessageBoxIndirectW" (lpMsgBoxParams AS MSGBOXPARAMSW) AS LONG
#ELSE
DECLARE FUNCTION MessageBoxIndirect LIB "User32.dll" _
    ALIAS "MessageBoxIndirectA" (lpMsgBoxParams AS MSGBOXPARAMSA) AS LONG
#ENDIF ' NOT %UNICODE
#ENDIF ' %WINVER >= &H0400

DECLARE FUNCTION MessageBeep LIB "User32.dll" ALIAS "MessageBeep" _
    (BYVAL dwType AS DWORD) AS LONG

#ENDIF ' NOT %NOMB

DECLARE FUNCTION ShowCursor LIB "User32.dll" ALIAS "ShowCursor" _
    (OPTIONAL BYVAL bShow AS LONG) AS LONG

DECLARE FUNCTION SetCursorPos LIB "User32.dll" ALIAS "SetCursorPos" _
    (BYVAL x AS LONG, BYVAL y AS LONG) AS LONG

#IF (%WINVER >= &H0600)
DECLARE FUNCTION SetPhysicalCursorPos LIB "User32.dll" _
    ALIAS "SetPhysicalCursorPos" (BYVAL X AS LONG, BYVAL Y AS LONG) AS LONG
#ENDIF  ' #IF (%WINVER >= &H0600)

DECLARE FUNCTION SetCursor LIB "User32.dll" ALIAS "SetCursor" _
    (BYVAL hCursor AS DWORD) AS DWORD

DECLARE FUNCTION GetCursorPos LIB "User32.dll" ALIAS "GetCursorPos" _
    (lpPoint AS POINT) AS LONG

#IF (%WINVER >= &H0600)
DECLARE FUNCTION GetPhysicalCursorPos LIB "User32.dll" _
    ALIAS "GetPhysicalCursorPos" (lpPoint AS POINT) AS LONG
#ENDIF  ' #IF (%WINVER >= &H0600)

DECLARE FUNCTION ClipCursor LIB "User32.dll" ALIAS "ClipCursor" _
    (lpRect AS RECT) AS LONG

DECLARE FUNCTION GetClipCursor LIB "User32.dll" ALIAS "GetClipCursor" _
    (lprc AS RECT) AS LONG

DECLARE FUNCTION GetCursor LIB "User32.dll" ALIAS "GetCursor" () AS DWORD

DECLARE FUNCTION CreateCaret LIB "User32.dll" ALIAS "CreateCaret" _
    (BYVAL hWnd AS DWORD, BYVAL hBitmap AS DWORD, BYVAL nWidth AS LONG, _
    BYVAL nHeight AS LONG) AS LONG

DECLARE FUNCTION GetCaretBlinkTime LIB "User32.dll" ALIAS "GetCaretBlinkTime" _
    () AS DWORD

DECLARE FUNCTION SetCaretBlinkTime LIB "User32.dll" ALIAS "SetCaretBlinkTime" _
    (BYVAL dwMillieconds AS DWORD) AS LONG

DECLARE FUNCTION DestroyCaret LIB "User32.dll" ALIAS "DestroyCaret" () AS LONG

DECLARE FUNCTION HideCaret LIB "User32.dll" ALIAS "HideCaret" _
    (OPTIONAL BYVAL hWnd AS DWORD) AS LONG

DECLARE FUNCTION ShowCaret LIB "User32.dll" ALIAS "ShowCaret" _
    (OPTIONAL BYVAL hWnd AS DWORD) AS LONG

DECLARE FUNCTION SetCaretPos LIB "User32.dll" ALIAS "SetCaretPos" _
    (BYVAL x AS LONG, BYVAL y AS LONG) AS LONG

DECLARE FUNCTION GetCaretPos LIB "User32.dll" ALIAS "GetCaretPos" _
    (lpPoint AS POINT) AS LONG

DECLARE FUNCTION ClientToScreen LIB "User32.dll" ALIAS "ClientToScreen" _
    (BYVAL hWnd AS DWORD, lpPoint AS POINT) AS LONG

DECLARE FUNCTION ScreenToClient LIB "User32.dll" ALIAS "ScreenToClient" _
    (BYVAL hWnd AS DWORD, lpPoint AS POINT) AS LONG

#IF (%WINVER >= &H0600)

DECLARE FUNCTION LogicalToPhysicalPoint LIB "User32.dll" _
    ALIAS "LogicalToPhysicalPoint" (BYVAL hwnd AS DWORD, lpPoint AS POINT) _
    AS LONG

DECLARE FUNCTION PhysicalToLogicalPoint LIB "User32.dll" _
    ALIAS "PhysicalToLogicalPoint" (BYVAL hwnd AS DWORD, lpPoint AS POINT) _
    AS LONG

#ENDIF ' %WINVER >= &H0600

DECLARE FUNCTION MapWindowPoints LIB "User32.dll" ALIAS "MapWindowPoints" _
    (BYVAL hWndFrom AS DWORD, BYVAL hWndTo AS DWORD, BYVAL lppt AS POINT PTR, _
    BYVAL cPoints AS DWORD) AS LONG

DECLARE FUNCTION WindowFromPoint LIB "User32.dll" ALIAS "WindowFromPoint" _
    (BYVAL pt AS POINT) AS DWORD

#IF (%WINVER >= &H0600)

DECLARE FUNCTION WindowFromPhysicalPoint LIB "User32.dll" _
    ALIAS "WindowFromPhysicalPoint" (BYVAL pt AS POINT) AS DWORD

#ENDIF ' %WINVER >= &H0600

DECLARE FUNCTION ChildWindowFromPoint LIB "User32.dll" _
    ALIAS "ChildWindowFromPoint" (BYVAL hwndParent AS DWORD, _
    BYVAL pt AS POINT) AS DWORD


#IF (%WINVER >= &H0400)

%CWP_ALL             = &H0000
%CWP_SKIPINVISIBLE   = &H0001
%CWP_SKIPDISABLED    = &H0002
%CWP_SKIPTRANSPARENT = &H0004

DECLARE FUNCTION ChildWindowFromPointEx LIB "User32.dll" _
    ALIAS "ChildWindowFromPointEx" (BYVAL hWnd AS DWORD, BYVAL pt AS POINT, _
    BYVAL uFlags AS DWORD) AS DWORD

#ENDIF ' %WINVER >= &H0400

#IF NOT %DEF(%NOCOLOR)

'
' Color Types
'
%CTLCOLOR_MSGBOX           = 0
%CTLCOLOR_EDIT             = 1
%CTLCOLOR_LISTBOX          = 2
%CTLCOLOR_BTN              = 3
%CTLCOLOR_DLG              = 4
%CTLCOLOR_SCROLLBAR        = 5
%CTLCOLOR_STATIC           = 6
%CTLCOLOR_MAX              = 7

%COLOR_SCROLLBAR           = 0
%COLOR_BACKGROUND          = 1
%COLOR_ACTIVECAPTION       = 2
%COLOR_INACTIVECAPTION     = 3
%COLOR_MENU                = 4
%COLOR_WINDOW              = 5
%COLOR_WINDOWFRAME         = 6
%COLOR_MENUTEXT            = 7
%COLOR_WINDOWTEXT          = 8
%COLOR_CAPTIONTEXT         = 9
%COLOR_ACTIVEBORDER        = 10
%COLOR_INACTIVEBORDER      = 11
%COLOR_APPWORKSPACE        = 12
%COLOR_HIGHLIGHT           = 13
%COLOR_HIGHLIGHTTEXT       = 14
%COLOR_BTNFACE             = 15
%COLOR_BTNSHADOW           = 16
%COLOR_GRAYTEXT            = 17
%COLOR_BTNTEXT             = 18
%COLOR_INACTIVECAPTIONTEXT = 19
%COLOR_BTNHIGHLIGHT        = 20

#IF (%WINVER >= &H0400)
%COLOR_3DDKSHADOW          = 21
%COLOR_3DLIGHT             = 22
%COLOR_INFOTEXT            = 23
%COLOR_INFOBK              = 24
#ENDIF ' %WINVER >= &H0400

#IF (%WINVER >= &H0500)
%COLOR_HOTLIGHT            = 26
%COLOR_GRADIENTACTIVECAPTION   = 27
%COLOR_GRADIENTINACTIVECAPTION = 28
#IF (%WINVER >= &H0501)
%COLOR_MENUHILIGHT         = 29
%COLOR_MENUBAR             = 30
#ENDIF ' %WINVER >= &H0501
#ENDIF ' %WINVER >= &H0500

#IF (%WINVER >= &H0400)
%COLOR_DESKTOP             = %COLOR_BACKGROUND
%COLOR_3DFACE              = %COLOR_BTNFACE
%COLOR_3DSHADOW            = %COLOR_BTNSHADOW
%COLOR_3DHIGHLIGHT         = %COLOR_BTNHIGHLIGHT
%COLOR_3DHILIGHT           = %COLOR_BTNHIGHLIGHT
%COLOR_BTNHILIGHT          = %COLOR_BTNHIGHLIGHT
#ENDIF ' %WINVER >= &H0400

DECLARE FUNCTION GetSysColor LIB "User32.dll" ALIAS "GetSysColor" _
    (BYVAL nIndex AS LONG) AS DWORD

#IF (%WINVER >= &H0400)

DECLARE FUNCTION GetSysColorBrush LIB "User32.dll" ALIAS "GetSysColorBrush" _
    (BYVAL nIndex AS LONG) _
    AS DWORD   ' HBRUSH

#ENDIF ' %WINVER >= &H0400

DECLARE FUNCTION SetSysColors LIB "User32.dll" ALIAS "SetSysColors" _
    (BYVAL nChanges AS LONG, BYVAL lpSysColor AS LONG PTR, _
    BYVAL lpColorValues AS DWORD PTR) AS LONG

#ENDIF ' NOT %NOCOLOR

DECLARE FUNCTION DrawFocusRect LIB "User32.dll" ALIAS "DrawFocusRect" _
    (BYVAL hDC AS DWORD, lpRect AS RECT) AS LONG

DECLARE FUNCTION FillRect LIB "User32.dll" ALIAS "FillRect" _
    (BYVAL hDC AS DWORD, lpRect AS RECT, BYVAL hBrush AS DWORD) AS LONG

DECLARE FUNCTION FrameRect LIB "User32.dll" ALIAS "FrameRect" _
    (BYVAL hDC AS DWORD, lpRect AS RECT, BYVAL hBrush AS DWORD) AS LONG

DECLARE FUNCTION InvertRect LIB "User32.dll" ALIAS "InvertRect" _
    (BYVAL hDC AS DWORD, lpRect AS RECT) AS LONG

DECLARE FUNCTION SetRect LIB "User32.dll" ALIAS "SetRect" (lpRect AS RECT, _
    BYVAL X1 AS LONG, BYVAL Y1 AS LONG, BYVAL X2 AS LONG, BYVAL Y2 AS LONG) _
    AS LONG

DECLARE FUNCTION SetRectEmpty LIB "User32.dll" ALIAS "SetRectEmpty" _
    (lpRect AS RECT) AS LONG

DECLARE FUNCTION CopyRect LIB "User32.dll" ALIAS "CopyRect" _
    (lpDestRect AS RECT, lpSourceRect AS RECT) AS LONG

DECLARE FUNCTION InflateRect LIB "User32.dll" ALIAS "InflateRect" _
    (lpRect AS RECT, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG

DECLARE FUNCTION IntersectRect LIB "User32.dll" ALIAS "IntersectRect" _
    (lpDestRect AS RECT, lpSrc1Rect AS RECT, lpSrc2Rect AS RECT) AS LONG

DECLARE FUNCTION UnionRect LIB "User32.dll" ALIAS "UnionRect" _
    (lpDestRect AS RECT, lpSrc1Rect AS RECT, lpSrc2Rect AS RECT) AS LONG

DECLARE FUNCTION SubtractRect LIB "User32.dll" ALIAS "SubtractRect" _
    (lprcDst AS RECT, lprcSrc1 AS RECT, lprcSrc2 AS RECT) AS LONG

DECLARE FUNCTION OffsetRect LIB "User32.dll" ALIAS "OffsetRect" _
    (lpRect AS RECT, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG

DECLARE FUNCTION IsRectEmpty LIB "User32.dll" ALIAS "IsRectEmpty" _
    (lpRect AS RECT) AS LONG

DECLARE FUNCTION EqualRect LIB "User32.dll" ALIAS "EqualRect" _
    (lpRect1 AS RECT, lpRect2 AS RECT) AS LONG

DECLARE FUNCTION PtInRect LIB "User32.dll" ALIAS "PtInRect" (lpRect AS RECT, _
    BYVAL pt AS POINT) AS LONG


#IF NOT %DEF(%NOWINOFFSETS)

DECLARE FUNCTION GetWindowWord LIB "User32.dll" ALIAS "GetWindowWord" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG) AS WORD

DECLARE FUNCTION SetWindowWord LIB "User32.dll" ALIAS "SetWindowWord" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG, BYVAL wNewWord AS WORD) AS WORD

DECLARE FUNCTION GetWindowLongA LIB "User32.dll" ALIAS "GetWindowLongA" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG) AS LONG

DECLARE FUNCTION GetWindowLongW LIB "User32.dll" ALIAS "GetWindowLongW" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetWindowLong LIB "User32.dll" ALIAS "GetWindowLongW" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG) AS LONG
#ELSE
DECLARE FUNCTION GetWindowLong LIB "User32.dll" ALIAS "GetWindowLongA" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetWindowLongA LIB "User32.dll" ALIAS "SetWindowLongA" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG, BYVAL lNewLong AS LONG) AS LONG

DECLARE FUNCTION SetWindowLongW LIB "User32.dll" ALIAS "SetWindowLongW" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG, BYVAL lNewLong AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetWindowLong LIB "User32.dll" ALIAS "SetWindowLongW" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG, BYVAL lNewLong AS LONG) AS LONG
#ELSE
DECLARE FUNCTION SetWindowLong LIB "User32.dll" ALIAS "SetWindowLongA" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG, BYVAL lNewLong AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

#IF %DEF(%WIN64)

'WINUSERAPI
'LONG_PTR
'WINAPI
'GetWindowLongPtrA(
'    DWORD hWnd,
'    int nIndex);
'WINUSERAPI
'LONG_PTR
'WINAPI
'GetWindowLongPtrW(
'    DWORD hWnd,
'    int nIndex);
'#IF %DEF(%UNICODE)
'MACRO GetWindowLongPtr=GetWindowLongPtrW
'#else
'MACRO GetWindowLongPtr=GetWindowLongPtrA
'#endif ' NOT %UNICODE
'
'WINUSERAPI
'LONG_PTR
'WINAPI
'SetWindowLongPtrA(
'    DWORD hWnd,
'    int nIndex,
'    LONG_PTR dwNewLong);
'WINUSERAPI
'LONG_PTR
'WINAPI
'SetWindowLongPtrW(
'    DWORD hWnd,
'    int nIndex,
'    LONG_PTR dwNewLong);
'#IF %DEF(%UNICODE)
'MACRO SetWindowLongPtr=SetWindowLongPtrW
'#else
'MACRO SetWindowLongPtr=SetWindowLongPtrA
'#endif ' NOT %UNICODE

#ELSE  ' %WIN64

DECLARE FUNCTION GetWindowLongPtrA LIB "User32.dll" ALIAS "GetWindowLongA" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG) AS LONG
DECLARE FUNCTION GetWindowLongPtrW LIB "User32.dll" ALIAS "GetWindowLongW" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG) AS LONG
#IF %DEF(%UNICODE)
DECLARE FUNCTION GetWindowLongPtr LIB "User32.dll" ALIAS "GetWindowLongW" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG) AS LONG
#ELSE
DECLARE FUNCTION GetWindowLongPtr LIB "User32.dll" ALIAS "GetWindowLongA" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetWindowLongPtrA LIB "User32.dll" ALIAS "SetWindowLongA" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG, BYVAL lNewLong AS LONG) AS LONG

DECLARE FUNCTION SetWindowLongPtrW LIB "User32.dll" ALIAS "SetWindowLongW" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG, BYVAL lNewLong AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetWindowLongPtr LIB "User32.dll" ALIAS "SetWindowLongW" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG, BYVAL lNewLong AS LONG) AS LONG
#ELSE
DECLARE FUNCTION SetWindowLongPtr LIB "User32.dll" ALIAS "SetWindowLongA" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG, BYVAL lNewLong AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' %WIN64

DECLARE FUNCTION GetClassWord LIB "User32.dll" ALIAS "GetClassWord" _
    (BYVAL hwnd AS DWORD, BYVAL nIndex AS LONG) AS WORD

DECLARE FUNCTION SetClassWord LIB "User32.dll" ALIAS "SetClassWord" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG, BYVAL wNewWord AS WORD) AS WORD

DECLARE FUNCTION GetClassLongA LIB "User32.dll" ALIAS "GetClassLongA" _
    (BYVAL hwnd AS DWORD, BYVAL nIndex AS LONG) AS DWORD

DECLARE FUNCTION GetClassLongW LIB "User32.dll" ALIAS "GetClassLongW" _
    (BYVAL hwnd AS DWORD, BYVAL nIndex AS LONG) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetClassLong LIB "User32.dll" ALIAS "GetClassLongW" _
    (BYVAL hwnd AS DWORD, BYVAL nIndex AS LONG) AS DWORD
#ELSE
DECLARE FUNCTION GetClassLong LIB "User32.dll" ALIAS "GetClassLongA" _
    (BYVAL hwnd AS DWORD, BYVAL nIndex AS LONG) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetClassLongA LIB "User32.dll" ALIAS "SetClassLongA" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG, BYVAL dwNewLong AS LONG) _
    AS DWORD

DECLARE FUNCTION SetClassLongW LIB "User32.dll" ALIAS "SetClassLongW" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG, BYVAL dwNewLong AS LONG) _
    AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetClassLong LIB "User32.dll" ALIAS "SetClassLongW" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG, BYVAL dwNewLong AS LONG) _
    AS DWORD
#ELSE
DECLARE FUNCTION SetClassLong LIB "User32.dll" ALIAS "SetClassLongA" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG, BYVAL dwNewLong AS LONG) _
    AS DWORD
#ENDIF ' NOT %UNICODE

#IF %DEF(%WIN64)

'WINUSERAPI
'ULONG_PTR
'WINAPI
'GetClassLongPtrA(
'    DWORD hWnd,
'    int nIndex);
'WINUSERAPI
'ULONG_PTR
'WINAPI
'GetClassLongPtrW(
'    DWORD hWnd,
'    int nIndex);
'#IF %DEF(%UNICODE)
'MACRO GetClassLongPtr=GetClassLongPtrW
'#else
'MACRO GetClassLongPtr=GetClassLongPtrA
'#endif ' NOT %UNICODE
'
'WINUSERAPI
'ULONG_PTR
'WINAPI
'SetClassLongPtrA(
'    DWORD hWnd,
'    int nIndex,
'    LONG_PTR dwNewLong);
'WINUSERAPI
'ULONG_PTR
'WINAPI
'SetClassLongPtrW(
'    DWORD hWnd,
'    int nIndex,
'    LONG_PTR dwNewLong);
'#IF %DEF(%UNICODE)
'MACRO SetClassLongPtr=SetClassLongPtrW
'#else
'MACRO SetClassLongPtr=SetClassLongPtrA
'#endif ' NOT %UNICODE

#ELSE  ' %WIN64

DECLARE FUNCTION GetClassLongPtrA LIB "User32.dll" ALIAS "GetClassLongA" _
    (BYVAL hwnd AS DWORD, BYVAL nIndex AS LONG) AS DWORD

DECLARE FUNCTION GetClassLongPtrW LIB "User32.dll" ALIAS "GetClassLongW" _
    (BYVAL hwnd AS DWORD, BYVAL nIndex AS LONG) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetClassLongPtr LIB "User32.dll" ALIAS "GetClassLongW" _
    (BYVAL hwnd AS DWORD, BYVAL nIndex AS LONG) AS DWORD
#ELSE
DECLARE FUNCTION GetClassLongPtr LIB "User32.dll" ALIAS "GetClassLongA" _
    (BYVAL hwnd AS DWORD, BYVAL nIndex AS LONG) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetClassLongPtrA LIB "User32.dll" ALIAS "SetClassLongA" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG, BYVAL dwNewLong AS LONG) _
    AS DWORD

DECLARE FUNCTION SetClassLongPtrW LIB "User32.dll" ALIAS "SetClassLongW" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG, BYVAL dwNewLong AS LONG) _
    AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetClassLongPtr LIB "User32.dll" ALIAS "SetClassLongW" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG, BYVAL dwNewLong AS LONG) _
    AS DWORD
#ELSE
DECLARE FUNCTION SetClassLongPtr LIB "User32.dll" ALIAS "SetClassLongA" _
    (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG, BYVAL dwNewLong AS LONG) _
    AS DWORD
#ENDIF ' NOT %UNICODE

#ENDIF ' %WIN64

#ENDIF ' NOT %NOWINOFFSETS

#IF (%WINVER >= &H0500)

DECLARE FUNCTION GetProcessDefaultLayout LIB "User32.dll" _
    ALIAS "GetProcessDefaultLayout" (pdwDefaultLayout AS DWORD) AS LONG

DECLARE FUNCTION SetProcessDefaultLayout LIB "User32.dll" _
    ALIAS "SetProcessDefaultLayout" (BYVAL dwDefaultLayout AS DWORD) AS LONG

#ENDIF ' %WINVER >= &H0500

DECLARE FUNCTION GetDesktopWindow LIB "User32.dll" ALIAS "GetDesktopWindow" _
    () AS DWORD

DECLARE FUNCTION GetParent LIB "User32.dll" ALIAS "GetParent" _
    (BYVAL hWnd AS DWORD) AS DWORD

DECLARE FUNCTION SetParent LIB "User32.dll" ALIAS "SetParent" _
    (BYVAL hWndChild AS DWORD, OPTIONAL BYVAL hWndNewParent AS DWORD) AS DWORD

DECLARE FUNCTION EnumChildWindows LIB "User32.dll" ALIAS "EnumChildWindows" _
    (BYVAL hwndParent AS DWORD, BYVAL lpEnumFunc AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION FindWindowA LIB "User32.dll" ALIAS "FindWindowA" _
    (lpClassName AS ASCIIZ, lpWindowName AS ASCIIZ) AS DWORD

DECLARE FUNCTION FindWindowW LIB "User32.dll" ALIAS "FindWindowW" _
    (lpClassName AS WSTRINGZ, lpWindowName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION FindWindow LIB "User32.dll" ALIAS "FindWindowW" _
    (lpClassName AS WSTRINGZ, lpWindowName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION FindWindow LIB "User32.dll" ALIAS "FindWindowA" _
    (lpClassName AS ASCIIZ, lpWindowName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

#IF (%WINVER >= &H0400)

DECLARE FUNCTION FindWindowExA LIB "User32.dll" ALIAS "FindWindowExA" _
    (BYVAL hWnd1 AS DWORD, BYVAL hWnd2 AS DWORD, lpsz1 AS ASCIIZ, _
    lpsz2 AS ASCIIZ) AS DWORD

DECLARE FUNCTION FindWindowExW LIB "User32.dll" ALIAS "FindWindowExW" _
    (BYVAL hWnd1 AS DWORD, BYVAL hWnd2 AS DWORD, lpsz1 AS WSTRINGZ, _
    lpsz2 AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION FindWindowEx LIB "User32.dll" ALIAS "FindWindowExW" _
    (BYVAL hWnd1 AS DWORD, BYVAL hWnd2 AS DWORD, lpsz1 AS WSTRINGZ, _
    lpsz2 AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION FindWindowEx LIB "User32.dll" ALIAS "FindWindowExA" _
    (BYVAL hWnd1 AS DWORD, BYVAL hWnd2 AS DWORD, lpsz1 AS ASCIIZ, _
    lpsz2 AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetShellWindow LIB "User32.dll" ALIAS "GetShellWindow" () _
    AS DWORD

#ENDIF ' %WINVER >= &H0400


DECLARE FUNCTION RegisterShellHookWindow LIB "User32.dll" _
    ALIAS "RegisterShellHookWindow" (BYVAL hwnd AS DWORD) AS LONG

DECLARE FUNCTION DeregisterShellHookWindow LIB "User32.dll" _
    ALIAS "DeregisterShellHookWindow" (BYVAL hwnd AS DWORD) AS LONG

DECLARE FUNCTION EnumWindows LIB "User32.dll" ALIAS "EnumWindows" _
    (BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION EnumThreadWindows LIB "User32.dll" ALIAS "EnumThreadWindows" _
    (BYVAL dwThreadId AS DWORD, BYVAL lpfn AS DWORD, BYVAL lParam AS LONG) _
    AS LONG

DECLARE FUNCTION EnumTaskWindows LIB "User32.dll" ALIAS "EnumThreadWindows" _
    (BYVAL dwThreadId AS DWORD, BYVAL lpfn AS DWORD, BYVAL lParam AS LONG) _
    AS LONG

DECLARE FUNCTION GetClassNameA LIB "User32.dll" ALIAS "GetClassNameA" _
    (BYVAL hwnd AS DWORD, lpClassName AS ASCIIZ, BYVAL nMaxCount AS LONG) _
    AS LONG

DECLARE FUNCTION GetClassNameW LIB "User32.dll" ALIAS "GetClassNameW" _
    (BYVAL hwnd AS DWORD, lpClassName AS WSTRINGZ, BYVAL nMaxCount AS LONG) _
    AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetClassName LIB "User32.dll" ALIAS "GetClassNameW" _
    (BYVAL hwnd AS DWORD, lpClassName AS WSTRINGZ, BYVAL nMaxCount AS LONG) _
    AS LONG
#ELSE
DECLARE FUNCTION GetClassName LIB "User32.dll" ALIAS "GetClassNameA" _
    (BYVAL hwnd AS DWORD, lpClassName AS ASCIIZ, BYVAL nMaxCount AS LONG) _
    AS LONG
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION GetTopWindow LIB "User32.dll" ALIAS "GetTopWindow" _
    (OPTIONAL BYVAL hWnd AS DWORD) AS DWORD

DECLARE FUNCTION GetNextWindow LIB "User32.dll" ALIAS "GetWindow" _
    (BYVAL hWnd AS DWORD, BYVAL wCmd AS DWORD) AS DWORD

FUNCTION GetSysModalWindow () AS DWORD
    FUNCTION = %NULL
END FUNCTION

FUNCTION SetSysModalWindow (BYVAL hWnd AS DWORD) AS DWORD
    FUNCTION = %NULL
END FUNCTION

DECLARE FUNCTION GetWindowThreadProcessId LIB "User32.dll" _
    ALIAS "GetWindowThreadProcessId" (BYVAL hWnd AS DWORD, _
    lpdwProcessId AS DWORD) AS DWORD

#IF (%WIN32_WINNT >= &H0501)

DECLARE FUNCTION IsGUIThread LIB "User32.dll" ALIAS "IsGUIThread" _
    (BYVAL bConvert AS LONG) AS LONG

#ENDIF ' %WIN32_WINNT >= &H0501

FUNCTION GetWindowTask (BYVAL hWnd AS DWORD) AS DWORD
    FUNCTION = GetWindowThreadProcessId(hWnd, %NULL)
END FUNCTION

DECLARE FUNCTION GetLastActivePopup LIB "User32.dll" _
    ALIAS "GetLastActivePopup" (BYVAL hWndOwner AS DWORD) AS DWORD

'
' GetWindow() Constants
'
%GW_HWNDFIRST      = 0
%GW_HWNDLAST       = 1
%GW_HWNDNEXT       = 2
%GW_HWNDPREV       = 3
%GW_OWNER          = 4
%GW_CHILD          = 5
#IF (%WINVER <= &H0400)
%GW_MAX            = 5
#ELSE
%GW_ENABLEDPOPUP   = 6
%GW_MAX            = 6
#ENDIF

DECLARE FUNCTION GetWindow LIB "User32.dll" ALIAS "GetWindow" _
    (BYVAL hWnd AS DWORD, BYVAL wCmd AS DWORD) AS DWORD

#IF NOT %DEF(%NOWH)

DECLARE FUNCTION SetWindowsHookA LIB "User32.dll" ALIAS "SetWindowsHookA" _
    (BYVAL nFilterType AS LONG, BYVAL pfnFilterProc AS DWORD) AS DWORD

DECLARE FUNCTION SetWindowsHookW LIB "User32.dll" ALIAS "SetWindowsHookW" _
    (BYVAL nFilterType AS LONG, BYVAL pfnFilterProc AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetWindowsHook LIB "User32.dll" ALIAS "SetWindowsHookW" _
    (BYVAL nFilterType AS LONG, BYVAL pfnFilterProc AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION SetWindowsHook LIB "User32.dll" ALIAS "SetWindowsHookA" _
    (BYVAL nFilterType AS LONG, BYVAL pfnFilterProc AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION UnhookWindowsHook LIB "User32.dll" ALIAS "UnhookWindowsHook" _
    (BYVAL nCode AS LONG, BYVAL pfnFilterProc AS DWORD) AS LONG

DECLARE FUNCTION SetWindowsHookExA LIB "User32.dll" ALIAS "SetWindowsHookExA" _
    (BYVAL idHook AS LONG, BYVAL lpfn AS DWORD, BYVAL hMod AS DWORD, _
    BYVAL dwThreadId AS DWORD) AS DWORD

DECLARE FUNCTION SetWindowsHookExW LIB "User32.dll" ALIAS "SetWindowsHookExW" _
    (BYVAL idHook AS LONG, BYVAL lpfn AS DWORD, BYVAL hMod AS DWORD, _
    BYVAL dwThreadId AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetWindowsHookEx LIB "User32.dll" ALIAS "SetWindowsHookExW" _
    (BYVAL idHook AS LONG, BYVAL lpfn AS DWORD, BYVAL hMod AS DWORD, _
    BYVAL dwThreadId AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION SetWindowsHookEx LIB "User32.dll" ALIAS "SetWindowsHookExA" _
    (BYVAL idHook AS LONG, BYVAL lpfn AS DWORD, BYVAL hMod AS DWORD, _
    BYVAL dwThreadId AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION UnhookWindowsHookEx LIB "User32.dll" _
    ALIAS "UnhookWindowsHookEx" (BYVAL hHook AS DWORD) AS LONG

DECLARE FUNCTION CallNextHookEx LIB "User32.dll" ALIAS "CallNextHookEx" _
    (BYVAL hHook AS DWORD, BYVAL ncode AS LONG, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

'
' Macros for source-level compatibility with old functions.
'
MACRO DefHookProc(nCode,wParam,lParam,phhk)=CallNextHookEx(phhk,nCode,wParam,lParam)

#ENDIF ' NOT %NOWH



#IF NOT %DEF(%NOMENUS)


' ;win40  -- A lot of MF_* flags have been renamed as MFT_* and MFS_* flags
'
' Menu flags for Add/Check/EnableMenuItem()
'
%MF_INSERT           = &H00000000
%MF_CHANGE           = &H00000080
%MF_APPEND           = &H00000100
%MF_DELETE           = &H00000200
%MF_REMOVE           = &H00001000

%MF_BYCOMMAND        = &H00000000
%MF_BYPOSITION       = &H00000400

%MF_SEPARATOR        = &H00000800

%MF_ENABLED          = &H00000000
%MF_GRAYED           = &H00000001
%MF_DISABLED         = &H00000002

%MF_UNCHECKED        = &H00000000
%MF_CHECKED          = &H00000008
%MF_USECHECKBITMAPS  = &H00000200

%MF_STRING           = &H00000000
%MF_BITMAP           = &H00000004
%MF_OWNERDRAW        = &H00000100

%MF_POPUP            = &H00000010
%MF_MENUBARBREAK     = &H00000020
%MF_MENUBREAK        = &H00000040

%MF_UNHILITE         = &H00000000
%MF_HILITE           = &H00000080

#IF (%WINVER >= &H0400)
%MF_DEFAULT          = &H00001000
#ENDIF ' %WINVER >= &H0400
%MF_SYSMENU          = &H00002000
%MF_HELP             = &H00004000
#IF (%WINVER >= &H0400)
%MF_RIGHTJUSTIFY     = &H00004000
#ENDIF ' %WINVER >= &H0400

%MF_MOUSESELECT      = &H00008000
#IF (%WINVER >= &H0400)
%MF_END              = &H00000080  ' Obsolete -- only used by old RES files
#ENDIF ' %WINVER >= &H0400


#IF (%WINVER >= &H0400)
%MFT_STRING         = %MF_STRING
%MFT_BITMAP         = %MF_BITMAP
%MFT_MENUBARBREAK   = %MF_MENUBARBREAK
%MFT_MENUBREAK      = %MF_MENUBREAK
%MFT_OWNERDRAW      = %MF_OWNERDRAW
%MFT_RADIOCHECK     = &H00000200
%MFT_SEPARATOR      = %MF_SEPARATOR
%MFT_RIGHTORDER     = &H00002000
%MFT_RIGHTJUSTIFY   = %MF_RIGHTJUSTIFY

' Menu flags for Add/Check/EnableMenuItem()
%MFS_GRAYED         = &H00000003
%MFS_DISABLED       = %MFS_GRAYED
%MFS_CHECKED        = %MF_CHECKED
%MFS_HILITE         = %MF_HILITE
%MFS_ENABLED        = %MF_ENABLED
%MFS_UNCHECKED      = %MF_UNCHECKED
%MFS_UNHILITE       = %MF_UNHILITE
%MFS_DEFAULT        = %MF_DEFAULT
#ENDIF ' %WINVER >= &H0400


#IF (%WINVER >= &H0400)

DECLARE FUNCTION CheckMenuRadioItem LIB "User32.dll" _
    ALIAS "CheckMenuRadioItem" (BYVAL hMenu AS DWORD, BYVAL idFirst AS DWORD, _
    BYVAL idLast AS DWORD, BYVAL idCheck AS DWORD, BYVAL uFlags AS DWORD) _
    AS LONG

#ENDIF ' %WINVER >= &H0400

'
' Menu item resource format
'
TYPE MENUITEMTEMPLATEHEADER
    versionNumber AS WORD
    offset        AS WORD
END TYPE

TYPE MENUITEMTEMPLATE       ' version 0
    mtOption AS WORD
    mtID     AS WORD
    mtString AS WSTRINGZ * 1
END TYPE

%MF_END           = &H00000080

#ENDIF ' NOT %NOMENUS



#IF NOT %DEF(%NOSYSCOMMANDS)

'
' System Menu Command Values
'
%SC_SIZE         = &HF000??
%SC_MOVE         = &HF010??
%SC_MINIMIZE     = &HF020??
%SC_MAXIMIZE     = &HF030??
%SC_NEXTWINDOW   = &HF040??
%SC_PREVWINDOW   = &HF050??
%SC_CLOSE        = &HF060??
%SC_VSCROLL      = &HF070??
%SC_HSCROLL      = &HF080??
%SC_MOUSEMENU    = &HF090??
%SC_KEYMENU      = &HF100??
%SC_ARRANGE      = &HF110??
%SC_RESTORE      = &HF120??
%SC_TASKLIST     = &HF130??
%SC_SCREENSAVE   = &HF140??
%SC_HOTKEY       = &HF150??
#IF (%WINVER >= &H0400)
%SC_DEFAULT      = &HF160??
%SC_MONITORPOWER = &HF170??
%SC_CONTEXTHELP  = &HF180??
%SC_SEPARATOR    = &HF00F??
#ENDIF ' %WINVER >= &H0400

#IF (%WINVER >= &H0600)
%SCF_ISSECURE    = &H00000001
#ENDIF ' %WINVER >= &H0600

MACRO GET_SC_WPARAM(wParam)=((wParam) AND &HFFF0??)

'
' Obsolete names
'
%SC_ICON       = %SC_MINIMIZE
%SC_ZOOM       = %SC_MAXIMIZE

#ENDIF ' NOT %NOSYSCOMMANDS

'
' Resource Loading Routines
'

DECLARE FUNCTION LoadBitmapA LIB "User32.dll" ALIAS "LoadBitmapA" _
    (BYVAL hInstance AS DWORD, lpBitmapName AS ASCIIZ) AS DWORD

DECLARE FUNCTION LoadBitmapW LIB "User32.dll" ALIAS "LoadBitmapW" _
    (BYVAL hInstance AS DWORD, lpBitmapName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION LoadBitmap LIB "User32.dll" ALIAS "LoadBitmapW" _
    (BYVAL hInstance AS DWORD, lpBitmapName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION LoadBitmap LIB "User32.dll" ALIAS "LoadBitmapA" _
    (BYVAL hInstance AS DWORD, lpBitmapName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION LoadCursorA LIB "User32.dll" ALIAS "LoadCursorA" _
    (BYVAL hInstance AS DWORD, lpCursorName AS ASCIIZ) AS DWORD

DECLARE FUNCTION LoadCursorW LIB "User32.dll" ALIAS "LoadCursorW" _
    (BYVAL hInstance AS DWORD, lpCursorName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION LoadCursor LIB "User32.dll" ALIAS "LoadCursorW" _
    (BYVAL hInstance AS DWORD, lpCursorName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION LoadCursor LIB "User32.dll" ALIAS "LoadCursorA" _
    (BYVAL hInstance AS DWORD, lpCursorName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION LoadCursorFromFileA LIB "User32.dll" _
    ALIAS "LoadCursorFromFileA" (lpFileName AS ASCIIZ) AS DWORD

DECLARE FUNCTION LoadCursorFromFileW LIB "User32.dll" _
    ALIAS "LoadCursorFromFileW" (lpFileName AS ASCIIZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION LoadCursorFromFile LIB "User32.dll" _
    ALIAS "LoadCursorFromFileW" (lpFileName AS ASCIIZ) AS DWORD
#ELSE
DECLARE FUNCTION LoadCursorFromFile LIB "User32.dll" _
    ALIAS "LoadCursorFromFileA" (lpFileName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CreateCursor LIB "User32.dll" ALIAS "CreateCursor" _
    (BYVAL hInstance AS DWORD, BYVAL nXhotspot AS LONG, _
    BYVAL nYhotspot AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
    BYVAL lpANDbitPlane AS BYTE PTR, BYVAL lpXORbitPlane AS BYTE PTR) AS DWORD

DECLARE FUNCTION DestroyCursor LIB "User32.dll" ALIAS "DestroyCursor" _
    (BYVAL hCursor AS DWORD) AS LONG

#IF NOT %DEF(%MAC)
DECLARE FUNCTION CopyCursor LIB "User32.dll" ALIAS "CopyIcon" _
    (BYVAL hIcon AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION CopyCursor LIB "User32.dll" ALIAS "CopyCursor" _
    (BYVAL hcur AS DWORD) AS DWORD
#ENDIF

'
' Standard Cursor IDs
'
%IDC_ARROW           = 32512
%IDC_IBEAM           = 32513
%IDC_WAIT            = 32514
%IDC_CROSS           = 32515
%IDC_UPARROW         = 32516
%IDC_SIZE            = 32640  ' OBSOLETE: use IDC_SIZEALL
%IDC_ICON            = 32641  ' OBSOLETE: use IDC_ARROW
%IDC_SIZENWSE        = 32642
%IDC_SIZENESW        = 32643
%IDC_SIZEWE          = 32644
%IDC_SIZENS          = 32645
%IDC_SIZEALL         = 32646
%IDC_NO              = 32648 'not in win3.1
#IF (%WINVER >= &H0500)
%IDC_HAND            = 32649
#ENDIF ' %WINVER >= &H0500
%IDC_APPSTARTING     = 32650 'not in win3.1
#IF (%WINVER >= &H0400)
%IDC_HELP            = 32651
#ENDIF ' %WINVER >= &H0400

DECLARE FUNCTION SetSystemCursor LIB "User32.dll" ALIAS "SetSystemCursor" _
    (BYVAL hCur AS DWORD, BYVAL ID AS DWORD) AS LONG

TYPE ICONINFO
    fIcon    AS LONG
    xHotspot AS DWORD
    yHotspot AS DWORD
    hbmMask  AS DWORD
    hbmColor AS DWORD
END TYPE

DECLARE FUNCTION LoadIconA LIB "User32.dll" ALIAS "LoadIconA" _
    (BYVAL hInstance AS DWORD, lpIconName AS ASCIIZ) AS DWORD

DECLARE FUNCTION LoadIconW LIB "User32.dll" ALIAS "LoadIconW" _
    (BYVAL hInstance AS DWORD, lpIconName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION LoadIcon LIB "User32.dll" ALIAS "LoadIconW" _
    (BYVAL hInstance AS DWORD, lpIconName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION LoadIcon LIB "User32.dll" ALIAS "LoadIconA" _
    (BYVAL hInstance AS DWORD, lpIconName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION PrivateExtractIconsA LIB "User32.dll" _
    ALIAS "PrivateExtractIconsA" (szFileName AS ASCIIZ, _
    BYVAL nIconIndex AS LONG, BYVAL cxIcon AS LONG, BYVAL cyIocon AS LONG, _
    phicon AS DWORD, piconid AS DWORD, BYVAL nIcons AS DWORD, _
    BYVAL flags AS DWORD) AS DWORD

DECLARE FUNCTION PrivateExtractIconsW LIB "User32.dll" _
    ALIAS "PrivateExtractIconsW" (szFileName AS WSTRINGZ, _
    BYVAL nIconIndex AS LONG, BYVAL cxIcon AS LONG, BYVAL cyIocon AS LONG, _
    phicon AS DWORD, piconid AS DWORD, BYVAL nIcons AS DWORD, _
    BYVAL flags AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION PrivateExtractIcons LIB "User32.dll" _
    ALIAS "PrivateExtractIconsW" (szFileName AS WSTRINGZ, _
    BYVAL nIconIndex AS LONG, BYVAL cxIcon AS LONG, BYVAL cyIocon AS LONG, _
    phicon AS DWORD, piconid AS DWORD, BYVAL nIcons AS DWORD, _
    BYVAL flags AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION PrivateExtractIcons LIB "User32.dll" _
    ALIAS "PrivateExtractIconsA" (szFileName AS ASCIIZ, _
    BYVAL nIconIndex AS LONG, BYVAL cxIcon AS LONG, BYVAL cyIocon AS LONG, _
    phicon AS DWORD, piconid AS DWORD, BYVAL nIcons AS DWORD, _
    BYVAL flags AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CreateIcon LIB "User32.dll" ALIAS "CreateIcon" _
    (BYVAL hInstance AS DWORD, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
    BYVAL nPlanes AS BYTE, BYVAL nBitsPixel AS BYTE, _
    BYVAL lpANDbits AS BYTE PTR, BYVAL lpXORbits AS BYTE PTR) AS DWORD

DECLARE FUNCTION DestroyIcon LIB "User32.dll" ALIAS "DestroyIcon" _
    (BYVAL hIcon AS DWORD) AS LONG

DECLARE FUNCTION LookupIconIdFromDirectory LIB "User32.dll" _
    ALIAS "LookupIconIdFromDirectory" (BYVAL presbits AS BYTE PTR, _
    BYVAL fIcon AS LONG) AS LONG

#IF (%WINVER >= &H0400)

DECLARE FUNCTION LookupIconIdFromDirectoryEx LIB "User32.dll" _
    ALIAS "LookupIconIdFromDirectoryEx" (BYVAL presbits AS BYTE PTR, _
    BYVAL fIcon AS LONG, BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, _
    BYVAL Flags AS DWORD) AS LONG

#ENDIF ' %WINVER >= &H0400

DECLARE FUNCTION CreateIconFromResource LIB "User32.dll" _
    ALIAS "CreateIconFromResource" (BYVAL presbits AS BYTE PTR, _
    BYVAL dwResSize AS DWORD, BYVAL fIcon AS LONG, BYVAL dwVer AS DWORD) _
    AS DWORD

#IF (%WINVER >= &H0400)

DECLARE FUNCTION CreateIconFromResourceEx LIB "User32.dll" _
    ALIAS "CreateIconFromResourceEx" (BYVAL presbits AS BYTE PTR, _
    BYVAL dwResSize AS DWORD, BYVAL fIcon AS LONG, BYVAL dwVer AS DWORD, _
    BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL uFlags AS DWORD) _
    AS DWORD

' Icon/Cursor header
TYPE CURSORSHAPE
    xHotSpot  AS LONG
    yHotSpot  AS LONG
    cx        AS LONG
    cy        AS LONG
    cbWidth   AS LONG
    Planes    AS BYTE
    BitsPixel AS BYTE
END TYPE

#ENDIF ' %WINVER >= &H0400

%IMAGE_BITMAP      = 0
%IMAGE_ICON        = 1
%IMAGE_CURSOR      = 2
#IF (%WINVER >= &H0400)
%IMAGE_ENHMETAFILE = 3

%LR_DEFAULTCOLOR     = &H00000000
%LR_MONOCHROME       = &H00000001
%LR_COLOR            = &H00000002
%LR_COPYRETURNORG    = &H00000004
%LR_COPYDELETEORG    = &H00000008
%LR_LOADFROMFILE     = &H00000010
%LR_LOADTRANSPARENT  = &H00000020
%LR_DEFAULTSIZE      = &H00000040
%LR_VGACOLOR         = &H00000080
%LR_LOADMAP3DCOLORS  = &H00001000
%LR_CREATEDIBSECTION = &H00002000
%LR_COPYFROMRESOURCE = &H00004000
%LR_SHARED           = &H00008000

DECLARE FUNCTION LoadImageA LIB "User32.dll" ALIAS "LoadImageA" _
    (BYVAL hInst AS DWORD, lpszName AS ASCIIZ, BYVAL uType AS DWORD, _
    BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL fuLoad AS DWORD) _
    AS DWORD

DECLARE FUNCTION LoadImageW LIB "User32.dll" ALIAS "LoadImageW" _
    (BYVAL hInst AS DWORD, lpszName AS WSTRINGZ, BYVAL uType AS DWORD, _
    BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL fuLoad AS DWORD) _
    AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION LoadImage LIB "User32.dll" ALIAS "LoadImageW" _
    (BYVAL hInst AS DWORD, lpszName AS WSTRINGZ, BYVAL uType AS DWORD, _
    BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL fuLoad AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION LoadImage LIB "User32.dll" ALIAS "LoadImageA" _
    (BYVAL hInst AS DWORD, lpszName AS ASCIIZ, BYVAL uType AS DWORD, _
    BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL fuLoad AS DWORD) _
    AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CopyImage LIB "User32.dll" ALIAS "CopyImage" _
    (BYVAL hImage AS DWORD, BYVAL uType AS DWORD, BYVAL cxDesired AS LONG, _
    BYVAL cyDesired AS LONG, BYVAL fuFlags AS DWORD) AS DWORD

%DI_MASK        = &H0001
%DI_IMAGE       = &H0002
%DI_NORMAL      = &H0003
%DI_COMPAT      = &H0004
%DI_DEFAULTSIZE = &H0008
#IF (%WIN32_WINNT >= &H0501)
%DI_NOMIRROR    = &H0010
#ENDIF ' %WIN32_WINNT >= &H0501

DECLARE FUNCTION DrawIconEx LIB "User32.dll" ALIAS "DrawIconEx" _
    (BYVAL hDC AS DWORD, BYVAL xLeft AS LONG, BYVAL yTop AS LONG, _
    BYVAL hIcon AS DWORD, BYVAL cxWidth AS LONG, BYVAL cyWidth AS LONG, _
    BYVAL istepIfAniCur AS DWORD, BYVAL hbrFlickerFreeDraw AS DWORD, _
    BYVAL diFlags AS DWORD) AS LONG

#ENDIF ' %WINVER >= &H0400

DECLARE FUNCTION CreateIconIndirect LIB "User32.dll" _
    ALIAS "CreateIconIndirect" (piconinfo AS ICONINFO) AS DWORD

DECLARE FUNCTION CopyIcon LIB "User32.dll" ALIAS "CopyIcon" _
    (BYVAL hIcon AS DWORD) AS DWORD

DECLARE FUNCTION GetIconInfo LIB "User32.dll" ALIAS "GetIconInfo" _
    (BYVAL hIcon AS DWORD, piconinfo AS ICONINFO) AS LONG

#IF (%WIN32_WINNT >= &H0600)

TYPE ICONINFOEXA
    cbSize    AS DWORD
    fIcon     AS LONG
    xHotspot  AS DWORD
    yHotspot  AS DWORD
    hbmMask   AS DWORD
    hbmColor  AS DWORD
    wResID    AS WORD
    szModName AS ASCIIZ * %MAX_PATH
    szResName AS ASCIIZ * %MAX_PATH
END TYPE

TYPE ICONINFOEXW
    cbSize    AS DWORD
    fIcon     AS LONG
    xHotspot  AS DWORD
    yHotspot  AS DWORD
    hbmMask   AS DWORD
    hbmColor  AS DWORD
    wResID    AS WORD
    szModName AS WSTRINGZ * %MAX_PATH
    szResName AS WSTRINGZ * %MAX_PATH
END TYPE

#IF %DEF(%UNICODE)
TYPE ICONINFOEX
    ICONINFOEXW
END TYPE
#ELSE
TYPE ICONINFOEX
    ICONINFOEXA
END TYPE
#ENDIF ' UNICODE

DECLARE FUNCTION GetIconInfoExA LIB "User32.dll" ALIAS "GetIconInfoExA" _
    (BYVAL hicon AS DWORD, piconinfo AS ICONINFOEXA) AS LONG

DECLARE FUNCTION GetIconInfoExW LIB "User32.dll" ALIAS "GetIconInfoExW" _
    (BYVAL hicon AS DWORD, piconinfo AS ICONINFOEXW) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetIconInfoEx LIB "User32.dll" ALIAS "GetIconInfoExW" _
    (BYVAL hicon AS DWORD, piconinfo AS ICONINFOEXW) AS LONG
#ELSE
DECLARE FUNCTION GetIconInfoEx LIB "User32.dll" ALIAS "GetIconInfoExA" _
    (BYVAL hicon AS DWORD, piconinfo AS ICONINFOEXA) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' %WIN32_WINNT >= &H0600

#IF (%WINVER >= &H0400)
%RES_ICON   = 1
%RES_CURSOR = 2
#ENDIF ' %WINVER >= &H0400

'#IF %DEF(%OEMRESOURCE)


'
' OEM Resource Ordinal Numbers
'
%OBM_CLOSE          = 32754
%OBM_UPARROW        = 32753
%OBM_DNARROW        = 32752
%OBM_RGARROW        = 32751
%OBM_LFARROW        = 32750
%OBM_REDUCE         = 32749
%OBM_ZOOM           = 32748
%OBM_RESTORE        = 32747
%OBM_REDUCED        = 32746
%OBM_ZOOMD          = 32745
%OBM_RESTORED       = 32744
%OBM_UPARROWD       = 32743
%OBM_DNARROWD       = 32742
%OBM_RGARROWD       = 32741
%OBM_LFARROWD       = 32740
%OBM_MNARROW        = 32739
%OBM_COMBO          = 32738
%OBM_UPARROWI       = 32737
%OBM_DNARROWI       = 32736
%OBM_RGARROWI       = 32735
%OBM_LFARROWI       = 32734

%OBM_OLD_CLOSE      = 32767
%OBM_SIZE           = 32766
%OBM_OLD_UPARROW    = 32765
%OBM_OLD_DNARROW    = 32764
%OBM_OLD_RGARROW    = 32763
%OBM_OLD_LFARROW    = 32762
%OBM_BTSIZE         = 32761
%OBM_CHECK          = 32760
%OBM_CHECKBOXES     = 32759
%OBM_BTNCORNERS     = 32758
%OBM_OLD_REDUCE     = 32757
%OBM_OLD_ZOOM       = 32756
%OBM_OLD_RESTORE    = 32755


%OCR_NORMAL         = 32512
%OCR_IBEAM          = 32513
%OCR_WAIT           = 32514
%OCR_CROSS          = 32515
%OCR_UP             = 32516
%OCR_SIZE           = 32640   ' OBSOLETE: use %OCR_SIZEALL
%OCR_ICON           = 32641   ' OBSOLETE: use %OCR_NORMAL
%OCR_SIZENWSE       = 32642
%OCR_SIZENESW       = 32643
%OCR_SIZEWE         = 32644
%OCR_SIZENS         = 32645
%OCR_SIZEALL        = 32646
%OCR_ICOCUR         = 32647   ' OBSOLETE: use %OIC_WINLOGO
%OCR_NO             = 32648
#IF (%WINVER >= &H0500)
%OCR_HAND           = 32649
#ENDIF ' %WINVER >= &H0500
#IF (%WINVER >= &H0400)
%OCR_APPSTARTING    = 32650
#ENDIF ' %WINVER >= &H0400


%OIC_SAMPLE         = 32512
%OIC_HAND           = 32513
%OIC_QUES           = 32514
%OIC_BANG           = 32515
%OIC_NOTE           = 32516
#IF (%WINVER >= &H0400)
%OIC_WINLOGO        = 32517
%OIC_WARNING        = %OIC_BANG
%OIC_ERROR          = %OIC_HAND
%OIC_INFORMATION    = %OIC_NOTE
#ENDIF ' %WINVER >= &H0400
#IF (%WINVER >= &H0600)
%OIC_SHIELD         = 32518
#ENDIF ' %WINVER >= &H0600

'#ENDIF ' %OEMRESOURCE

%ORD_LANGDRIVER  = 1     ' The ordinal number for the entry point of
                         ' language drivers.


#IF NOT %DEF(%NOICONS)

'
' Standard Icon IDs
'
%IDI_APPLICATION    = 32512
%IDI_HAND           = 32513
%IDI_QUESTION       = 32514
%IDI_EXCLAMATION    = 32515
%IDI_ASTERISK       = 32516
#IF (%WINVER >= &H0400)
%IDI_WINLOGO        = 32517
#ENDIF ' %WINVER >= &H0400
#IF (%WINVER >= &H0600)
%IDI_SHIELD         = 32518
#ENDIF ' %WINVER >= &H0600

#IF (%WINVER >= &H0400)
%IDI_WARNING     = %IDI_EXCLAMATION
%IDI_ERROR       = %IDI_HAND
%IDI_INFORMATION = %IDI_ASTERISK
#ENDIF ' %WINVER >= &H0400


#ENDIF ' NOT %NOICONS

DECLARE FUNCTION LoadStringA LIB "User32.dll" ALIAS "LoadStringA" _
    (BYVAL hInstance AS DWORD, BYVAL uID AS DWORD, lpBuffer AS ASCIIZ, _
    BYVAL nBufferMax AS LONG) AS LONG

DECLARE FUNCTION LoadStringW LIB "User32.dll" ALIAS "LoadStringW" _
    (BYVAL hInstance AS DWORD, BYVAL uID AS DWORD, lpBuffer AS WSTRINGZ, _
    BYVAL nBufferMax AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION LoadString LIB "User32.dll" ALIAS "LoadStringW" _
    (BYVAL hInstance AS DWORD, BYVAL uID AS DWORD, lpBuffer AS WSTRINGZ, _
    BYVAL nBufferMax AS LONG) AS LONG
#ELSE
DECLARE FUNCTION LoadString LIB "User32.dll" ALIAS "LoadStringA" _
    (BYVAL hInstance AS DWORD, BYVAL uID AS DWORD, lpBuffer AS ASCIIZ, _
    BYVAL nBufferMax AS LONG) AS LONG
#ENDIF ' NOT %UNICODE


'
' Dialog Box Command IDs
'
%IDOK              = 1
%IDCANCEL          = 2
%IDABORT           = 3
%IDRETRY           = 4
%IDIGNORE          = 5
%IDYES             = 6
%IDNO              = 7
#IF (%WINVER >= &H0400)
%IDCLOSE       = 8
%IDHELP        = 9
#ENDIF ' %WINVER >= &H0400

#IF (%WINVER >= &H0500)
%IDTRYAGAIN    = 10
%IDCONTINUE    = 11
#ENDIF ' %WINVER >= &H0500

#IF (%WINVER >= &H0501)
#IF NOT %DEF(%IDTIMEOUT)
%IDTIMEOUT = 32000
#ENDIF
#ENDIF ' %WINVER >= &H0501


#IF NOT %DEF(%NOCTLMGR)

'
' Control Manager Structures and Definitions
'

#IF NOT %DEF(%NOWINSTYLES)


'
' Edit Control Styles
'
%ES_LEFT           = &H0000
%ES_CENTER         = &H0001
%ES_RIGHT          = &H0002
%ES_MULTILINE      = &H0004
%ES_UPPERCASE      = &H0008
%ES_LOWERCASE      = &H0010
%ES_PASSWORD       = &H0020
%ES_AUTOVSCROLL    = &H0040
%ES_AUTOHSCROLL    = &H0080
%ES_NOHIDESEL      = &H0100
%ES_OEMCONVERT     = &H0400
%ES_READONLY       = &H0800
%ES_WANTRETURN     = &H1000
#IF (%WINVER >= &H0400)
%ES_NUMBER         = &H2000
#ENDIF ' %WINVER >= &H0400


#ENDIF ' NOT %NOWINSTYLES

'
' Edit Control Notification Codes
'
%EN_SETFOCUS       = &H0100
%EN_KILLFOCUS      = &H0200
%EN_CHANGE         = &H0300
%EN_UPDATE         = &H0400
%EN_ERRSPACE       = &H0500
%EN_MAXTEXT        = &H0501
%EN_HSCROLL        = &H0601
%EN_VSCROLL        = &H0602

#IF (%WIN32_WINNT >= &H0500)
%EN_ALIGN_LTR_EC   = &H0700
%EN_ALIGN_RTL_EC   = &H0701
#ENDIF ' %WIN32_WINNT >= &H0500

#IF (%WINVER >= &H0400)
' Edit control EM_SETMARGIN parameters
%EC_LEFTMARGIN     = &H0001
%EC_RIGHTMARGIN    = &H0002
%EC_USEFONTINFO    = &Hffff??
#ENDIF ' %WINVER >= &H0400

#IF (%WINVER >= &H0500)
' wParam of EM_GET/SETIMESTATUS
%EMSIS_COMPOSITIONSTRING        = &H0001

' lParam for EMSIS_COMPOSITIONSTRING
%EIMES_GETCOMPSTRATONCE         = &H0001
%EIMES_CANCELCOMPSTRINFOCUS     = &H0002
%EIMES_COMPLETECOMPSTRKILLFOCUS = &H0004
#ENDIF ' %WINVER >= &H0500

#IF NOT %DEF(%NOWINMESSAGES)


'
' Edit Control Messages
'
%EM_GETSEL               = &H00B0
%EM_SETSEL               = &H00B1
%EM_GETRECT              = &H00B2
%EM_SETRECT              = &H00B3
%EM_SETRECTNP            = &H00B4
%EM_SCROLL               = &H00B5
%EM_LINESCROLL           = &H00B6
%EM_SCROLLCARET          = &H00B7
%EM_GETMODIFY            = &H00B8
%EM_SETMODIFY            = &H00B9
%EM_GETLINECOUNT         = &H00BA
%EM_LINEINDEX            = &H00BB
%EM_SETHANDLE            = &H00BC
%EM_GETHANDLE            = &H00BD
%EM_GETTHUMB             = &H00BE
%EM_LINELENGTH           = &H00C1
%EM_REPLACESEL           = &H00C2
%EM_GETLINE              = &H00C4
%EM_LIMITTEXT            = &H00C5
%EM_CANUNDO              = &H00C6
%EM_UNDO                 = &H00C7
%EM_FMTLINES             = &H00C8
%EM_LINEFROMCHAR         = &H00C9
%EM_SETTABSTOPS          = &H00CB
%EM_SETPASSWORDCHAR      = &H00CC
%EM_EMPTYUNDOBUFFER      = &H00CD
%EM_GETFIRSTVISIBLELINE  = &H00CE
%EM_SETREADONLY          = &H00CF
%EM_SETWORDBREAKPROC     = &H00D0
%EM_GETWORDBREAKPROC     = &H00D1
%EM_GETPASSWORDCHAR      = &H00D2
#IF (%WINVER >= &H0400)
%EM_SETMARGINS           = &H00D3
%EM_GETMARGINS           = &H00D4
%EM_SETLIMITTEXT         = %EM_LIMITTEXT   ' ;win40 Name change
%EM_GETLIMITTEXT         = &H00D5
%EM_POSFROMCHAR          = &H00D6
%EM_CHARFROMPOS          = &H00D7
#ENDIF ' %WINVER >= &H0400

#IF (%WINVER >= &H0500)
%EM_SETIMESTATUS         = &H00D8
%EM_GETIMESTATUS         = &H00D9
#ENDIF ' %WINVER >= &H0500


#ENDIF ' NOT %NOWINMESSAGES

'
' EDITWORDBREAKPROC code values
'
%WB_LEFT          = 0
%WB_RIGHT         = 1
%WB_ISDELIMITER   = 2


'
' Button Control Styles
'
%BS_PUSHBUTTON      = &H00000000
%BS_DEFPUSHBUTTON   = &H00000001
%BS_CHECKBOX        = &H00000002
%BS_AUTOCHECKBOX    = &H00000003
%BS_RADIOBUTTON     = &H00000004
%BS_3STATE          = &H00000005
%BS_AUTO3STATE      = &H00000006
%BS_GROUPBOX        = &H00000007
%BS_USERBUTTON      = &H00000008
%BS_AUTORADIOBUTTON = &H00000009
%BS_PUSHBOX         = &H0000000A
%BS_OWNERDRAW       = &H0000000B
%BS_TYPEMASK        = &H0000000F
%BS_LEFTTEXT        = &H00000020
#IF (%WINVER >= &H0400)
%BS_TEXT            = &H00000000
%BS_ICON            = &H00000040
%BS_BITMAP          = &H00000080
%BS_LEFT            = &H00000100
%BS_RIGHT           = &H00000200
%BS_CENTER          = &H00000300
%BS_TOP             = &H00000400
%BS_BOTTOM          = &H00000800
%BS_VCENTER         = &H00000C00
%BS_PUSHLIKE        = &H00001000
%BS_MULTILINE       = &H00002000
%BS_NOTIFY          = &H00004000
%BS_FLAT            = &H00008000
%BS_RIGHTBUTTON     = %BS_LEFTTEXT
#ENDIF ' %WINVER >= &H0400

'
' User Button Notification Codes
'
%BN_CLICKED        = 0
%BN_PAINT          = 1
%BN_HILITE         = 2
%BN_UNHILITE       = 3
%BN_DISABLE        = 4
%BN_DOUBLECLICKED  = 5
#IF (%WINVER >= &H0400)
%BN_PUSHED         = %BN_HILITE
%BN_UNPUSHED       = %BN_UNHILITE
%BN_DBLCLK         = %BN_DOUBLECLICKED
%BN_SETFOCUS       = 6
%BN_KILLFOCUS      = 7
#ENDIF ' %WINVER >= &H0400

'
' Button Control Messages
'
%BM_GETCHECK        = &H00F0
%BM_SETCHECK        = &H00F1
%BM_GETSTATE        = &H00F2
%BM_SETSTATE        = &H00F3
%BM_SETSTYLE        = &H00F4
#IF (%WINVER >= &H0400)
%BM_CLICK           = &H00F5
%BM_GETIMAGE        = &H00F6
%BM_SETIMAGE        = &H00F7
#ENDIF ' %WINVER >= &H0400
#IF (%WINVER >= &H0600)
%BM_SETDONTCLICK    = &H00F8
#ENDIF ' %WINVER >= &H0600

#IF (%WINVER >= &H0400)
%BST_UNCHECKED      = &H0000
%BST_CHECKED        = &H0001
%BST_INDETERMINATE  = &H0002
%BST_PUSHED         = &H0004
%BST_FOCUS          = &H0008
#ENDIF ' %WINVER >= &H0400

'
' Static Control Constants
'
%SS_LEFT             = &H00000000
%SS_CENTER           = &H00000001
%SS_RIGHT            = &H00000002
%SS_ICON             = &H00000003
%SS_BLACKRECT        = &H00000004
%SS_GRAYRECT         = &H00000005
%SS_WHITERECT        = &H00000006
%SS_BLACKFRAME       = &H00000007
%SS_GRAYFRAME        = &H00000008
%SS_WHITEFRAME       = &H00000009
%SS_USERITEM         = &H0000000A
%SS_SIMPLE           = &H0000000B
%SS_LEFTNOWORDWRAP   = &H0000000C
#IF (%WINVER >= &H0400)
%SS_OWNERDRAW        = &H0000000D
%SS_BITMAP           = &H0000000E
%SS_ENHMETAFILE      = &H0000000F
%SS_ETCHEDHORZ       = &H00000010
%SS_ETCHEDVERT       = &H00000011
%SS_ETCHEDFRAME      = &H00000012
%SS_TYPEMASK         = &H0000001F
#ENDIF ' %WINVER >= &H0400
#IF (%WINVER >= &H0501)
%SS_REALSIZECONTROL  = &H00000040
#ENDIF ' %WINVER >= &H0501
%SS_NOPREFIX         = &H00000080 ' Don't do "&" character translation
#IF (%WINVER >= &H0400)
%SS_NOTIFY           = &H00000100
%SS_CENTERIMAGE      = &H00000200
%SS_RIGHTJUST        = &H00000400
%SS_REALSIZEIMAGE    = &H00000800
%SS_SUNKEN           = &H00001000
%SS_EDITCONTROL      = &H00002000
%SS_ENDELLIPSIS      = &H00004000
%SS_PATHELLIPSIS     = &H00008000
%SS_WORDELLIPSIS     = &H0000C000
%SS_ELLIPSISMASK     = &H0000C000
#ENDIF ' %WINVER >= &H0400



#IF NOT %DEF(%NOWINMESSAGES)
'
' Static Control Mesages
'
%STM_SETICON       = &H0170
%STM_GETICON       = &H0171
#IF (%WINVER >= &H0400)
%STM_SETIMAGE      = &H0172
%STM_GETIMAGE      = &H0173
%STN_CLICKED       = 0
%STN_DBLCLK        = 1
%STN_ENABLE        = 2
%STN_DISABLE       = 3
#ENDIF ' %WINVER >= &H0400
%STM_MSGMAX        = &H0174
#ENDIF ' NOT %NOWINMESSAGES

'
' Dialog window class
'
%WC_DIALOG       = &H8002??

'
' Get/SetWindowWord/Long offsets for use with WC_DIALOG windows
'
#IF NOT %DEF(%WIN64)
%DWL_MSGRESULT = 0
%DWL_DLGPROC   = 4
%DWL_USER      = 8
#ENDIF ' NOT %WIN64

%DWLP_MSGRESULT = 0
%DWLP_DLGPROC   = %DWLP_MSGRESULT + 4 ' sizeof(LRESULT)
%DWLP_USER      = %DWLP_DLGPROC + 4 'sizeof(DLGPROC)

'
' Dialog Manager Routines
'

#IF NOT %DEF(%NOMSG)

DECLARE FUNCTION IsDialogMessageA LIB "User32.dll" ALIAS "IsDialogMessageA" _
    (BYVAL hDlg AS DWORD, lpMsg AS MSG_type) AS LONG

DECLARE FUNCTION IsDialogMessageW LIB "User32.dll" ALIAS "IsDialogMessageW" _
    (BYVAL hDlg AS DWORD, lpMsg AS MSG_type) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION IsDialogMessage LIB "User32.dll" ALIAS "IsDialogMessageW" _
    (BYVAL hDlg AS DWORD, lpMsg AS MSG_type) AS LONG
#ELSE
DECLARE FUNCTION IsDialogMessage LIB "User32.dll" ALIAS "IsDialogMessageA" _
    (BYVAL hDlg AS DWORD, lpMsg AS MSG_type) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' NOT %NOMSG

DECLARE FUNCTION MapDialogRect LIB "User32.dll" ALIAS "MapDialogRect" _
    (BYVAL hDlg AS DWORD, lpRect AS RECT) AS LONG

DECLARE FUNCTION DlgDirListA LIB "User32.dll" ALIAS "DlgDirListA" _
    (BYVAL hDlg AS DWORD, lpPathSpec AS ASCIIZ, BYVAL nIDListBox AS LONG, _
    BYVAL nIDStaticPath AS LONG, BYVAL uFileType AS DWORD) AS LONG

DECLARE FUNCTION DlgDirListW LIB "User32.dll" ALIAS "DlgDirListW" _
    (BYVAL hDlg AS DWORD, lpPathSpec AS WSTRINGZ, BYVAL nIDListBox AS LONG, _
    BYVAL nIDStaticPath AS LONG, BYVAL uFileType AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION DlgDirList LIB "User32.dll" ALIAS "DlgDirListW" _
    (BYVAL hDlg AS DWORD, lpPathSpec AS WSTRINGZ, BYVAL nIDListBox AS LONG, _
    BYVAL nIDStaticPath AS LONG, BYVAL uFileType AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION DlgDirList LIB "User32.dll" ALIAS "DlgDirListA" _
    (BYVAL hDlg AS DWORD, lpPathSpec AS ASCIIZ, BYVAL nIDListBox AS LONG, _
    BYVAL nIDStaticPath AS LONG, BYVAL uFileType AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

'
' DlgDirList, DlgDirListComboBox flags values
'
%DDL_READWRITE     = &H0000
%DDL_READONLY      = &H0001
%DDL_HIDDEN        = &H0002
%DDL_SYSTEM        = &H0004
%DDL_DIRECTORY     = &H0010
%DDL_ARCHIVE       = &H0020

%DDL_POSTMSGS      = &H2000
%DDL_DRIVES        = &H4000
%DDL_EXCLUSIVE     = &H8000??

DECLARE FUNCTION DlgDirSelectExA LIB "User32.dll" ALIAS "DlgDirSelectExA" _
    (BYVAL hWndDlg AS DWORD, lpszPath AS ASCIIZ, BYVAL cbPath AS LONG, _
    BYVAL idListBox AS LONG) AS LONG

DECLARE FUNCTION DlgDirSelectExW LIB "User32.dll" ALIAS "DlgDirSelectExW" _
    (BYVAL hWndDlg AS DWORD, lpszPath AS WSTRINGZ, BYVAL cbPath AS LONG, _
    BYVAL idListBox AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION DlgDirSelectEx LIB "User32.dll" ALIAS "DlgDirSelectExW" _
    (BYVAL hWndDlg AS DWORD, lpszPath AS WSTRINGZ, BYVAL cbPath AS LONG, _
    BYVAL idListBox AS LONG) AS LONG
#ELSE
DECLARE FUNCTION DlgDirSelectEx LIB "User32.dll" ALIAS "DlgDirSelectExA" _
    (BYVAL hWndDlg AS DWORD, lpszPath AS ASCIIZ, BYVAL cbPath AS LONG, _
    BYVAL idListBox AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DlgDirListComboBoxA LIB "User32.dll" _
    ALIAS "DlgDirListComboBoxA" (BYVAL hDlg AS DWORD, lpPathSpec AS ASCIIZ, _
    BYVAL nIDComboBox AS LONG, BYVAL nIDStaticPath AS LONG, _
    BYVAL uFileType AS DWORD) AS LONG

DECLARE FUNCTION DlgDirListComboBoxW LIB "User32.dll" _
    ALIAS "DlgDirListComboBoxW" (BYVAL hDlg AS DWORD, lpPathSpec AS WSTRINGZ, _
    BYVAL nIDComboBox AS LONG, BYVAL nIDStaticPath AS LONG, _
    BYVAL uFileType AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION DlgDirListComboBox LIB "User32.dll" _
    ALIAS "DlgDirListComboBoxW" (BYVAL hDlg AS DWORD, lpPathSpec AS WSTRINGZ, _
    BYVAL nIDComboBox AS LONG, BYVAL nIDStaticPath AS LONG, _
    BYVAL uFileType AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION DlgDirListComboBox LIB "User32.dll" _
    ALIAS "DlgDirListComboBoxA" (BYVAL hDlg AS DWORD, lpPathSpec AS ASCIIZ, _
    BYVAL nIDComboBox AS LONG, BYVAL nIDStaticPath AS LONG, _
    BYVAL uFileType AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DlgDirSelectComboBoxExA LIB "User32.dll" _
    ALIAS "DlgDirSelectComboBoxExA" (BYVAL hWndDlg AS DWORD, _
    lpszPath AS ASCIIZ, BYVAL cbPath AS LONG, BYVAL idComboBox AS LONG) AS LONG

DECLARE FUNCTION DlgDirSelectComboBoxExW LIB "User32.dll" _
    ALIAS "DlgDirSelectComboBoxExW" (BYVAL hWndDlg AS DWORD, _
    lpszPath AS WSTRINGZ, BYVAL cbPath AS LONG, BYVAL idComboBox AS LONG) _
    AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION DlgDirSelectComboBoxEx LIB "User32.dll" _
    ALIAS "DlgDirSelectComboBoxExW" (BYVAL hWndDlg AS DWORD, _
    lpszPath AS WSTRINGZ, BYVAL cbPath AS LONG, BYVAL idComboBox AS LONG) _
    AS LONG
#ELSE
DECLARE FUNCTION DlgDirSelectComboBoxEx LIB "User32.dll" _
    ALIAS "DlgDirSelectComboBoxExA" (BYVAL hWndDlg AS DWORD, _
    lpszPath AS ASCIIZ, BYVAL cbPath AS LONG, BYVAL idComboBox AS LONG) AS LONG
#ENDIF ' NOT %UNICODE



'
' Dialog Styles
'
%DS_ABSALIGN         = &H01
%DS_SYSMODAL         = &H02
%DS_LOCALEDIT        = &H20    ' Edit items get Local storage.
%DS_SETFONT          = &H40    ' User specified font for Dlg controls
%DS_MODALFRAME       = &H80?   ' Can be combined with WS_CAPTION
%DS_NOIDLEMSG        = &H100   ' %WM_ENTERIDLE message will not be sent
%DS_SETFOREGROUND    = &H200   ' not in win3.1


#IF (%WINVER >= &H0400)
%DS_3DLOOK           = &H0004
%DS_FIXEDSYS         = &H0008
%DS_NOFAILCREATE     = &H0010
%DS_CONTROL          = &H0400
%DS_CENTER           = &H0800
%DS_CENTERMOUSE      = &H1000
%DS_CONTEXTHELP      = &H2000

%DS_SHELLFONT        = (%DS_SETFONT OR %DS_FIXEDSYS)
#ENDIF ' %WINVER >= &H0400

' [Microsoft never defines WIN32_WCE, so we can't test it]
'#IF (%WIN32_WCE >= &H0500)
#IF %DEF(%WIN32_WCE)
%DS_USEPIXELS        = &H8000??
#ENDIF


%DM_GETDEFID         = (%WM_USER+0)
%DM_SETDEFID         = (%WM_USER+1)

#IF (%WINVER >= &H0400)
%DM_REPOSITION       = (%WM_USER+2)
#ENDIF ' %WINVER >= &H0400
'
' Returned in HIWORD() of DM_GETDEFID result if msg is supported
'
%DC_HASDEFID         = &H534B

'
' Dialog Codes
'
%DLGC_WANTARROWS      = &H0001      ' Control wants arrow keys
%DLGC_WANTTAB         = &H0002      ' Control wants tab keys
%DLGC_WANTALLKEYS     = &H0004      ' Control wants all keys
%DLGC_WANTMESSAGE     = &H0004      ' Pass message to control
%DLGC_HASSETSEL       = &H0008      ' Understands EM_SETSEL message
%DLGC_DEFPUSHBUTTON   = &H0010      ' Default pushbutton
%DLGC_UNDEFPUSHBUTTON = &H0020      ' Non-default pushbutton
%DLGC_RADIOBUTTON     = &H0040      ' Radio button
%DLGC_WANTCHARS       = &H0080      ' Want %WM_CHAR messages
%DLGC_STATIC          = &H0100      ' Static item: don't include
%DLGC_BUTTON          = &H2000      ' Button item: can be checked

%LB_CTLCODE        = 0

'
' Listbox Return Values
'
%LB_OKAY           = 0
%LB_ERR            = -1
%LB_ERRSPACE       = -2

'
'  The idStaticPath parameter to DlgDirList can have the following values
'  ORed if the list box should show other details of the files along with
'  the name of the files;
'
                                  ' all other details also will be returned


'
' Listbox Notification Codes
'
%LBN_ERRSPACE      = -2
%LBN_SELCHANGE     = 1
%LBN_DBLCLK        = 2
%LBN_SELCANCEL     = 3
%LBN_SETFOCUS      = 4
%LBN_KILLFOCUS     = 5



#IF NOT %DEF(%NOWINMESSAGES)

'
' Listbox messages
'
%LB_ADDSTRING            = &H0180
%LB_INSERTSTRING         = &H0181
%LB_DELETESTRING         = &H0182
%LB_SELITEMRANGEEX       = &H0183
%LB_RESETCONTENT         = &H0184
%LB_SETSEL               = &H0185
%LB_SETCURSEL            = &H0186
%LB_GETSEL               = &H0187
%LB_GETCURSEL            = &H0188
%LB_GETTEXT              = &H0189
%LB_GETTEXTLEN           = &H018A
%LB_GETCOUNT             = &H018B
%LB_SELECTSTRING         = &H018C
%LB_DIR                  = &H018D
%LB_GETTOPINDEX          = &H018E
%LB_FINDSTRING           = &H018F
%LB_GETSELCOUNT          = &H0190
%LB_GETSELITEMS          = &H0191
%LB_SETTABSTOPS          = &H0192
%LB_GETHORIZONTALEXTENT  = &H0193
%LB_SETHORIZONTALEXTENT  = &H0194
%LB_SETCOLUMNWIDTH       = &H0195
%LB_ADDFILE              = &H0196
%LB_SETTOPINDEX          = &H0197
%LB_GETITEMRECT          = &H0198
%LB_GETITEMDATA          = &H0199
%LB_SETITEMDATA          = &H019A
%LB_SELITEMRANGE         = &H019B
%LB_SETANCHORINDEX       = &H019C
%LB_GETANCHORINDEX       = &H019D
%LB_SETCARETINDEX        = &H019E
%LB_GETCARETINDEX        = &H019F
%LB_SETITEMHEIGHT        = &H01A0
%LB_GETITEMHEIGHT        = &H01A1
%LB_FINDSTRINGEXACT      = &H01A2
%LB_SETLOCALE            = &H01A5
%LB_GETLOCALE            = &H01A6
%LB_SETCOUNT             = &H01A7
#IF (%WINVER >= &H0400)
%LB_INITSTORAGE          = &H01A8
%LB_ITEMFROMPOINT        = &H01A9
#ENDIF ' %WINVER >= &H0400
' [Microsoft never defines WIN32_WCE, so we can't test it]
'#IF (%WIN32_WCE >= &H0400)
#IF %DEF(%WIN32_WCE)
%LB_MULTIPLEADDSTRING    = &H01B1
#ENDIF


#IF (%WIN32_WINNT >= &H0501)
%LB_GETLISTBOXINFO       = &H01B2
#ENDIF ' %WIN32_WINNT >= &H0501

#IF (%WIN32_WINNT >= &H0501)
%LB_MSGMAX               = &H01B3
' [Microsoft never defines WIN32_WCE, so we can't test it]
'#ELSEIF (%WIN32_WCE >= &H0400)
#ELSEIF %DEF(%WIN32_WCE)
%LB_MSGMAX               = &H01B1
#ELSEIF (%WINVER >= &H0400)
%LB_MSGMAX               = &H01B0
#ELSE
%LB_MSGMAX               = &H01A8
#ENDIF

#ENDIF ' NOT %NOWINMESSAGES

#IF NOT %DEF(%NOWINSTYLES)


'
' Listbox Styles
'
%LBS_NOTIFY            = &H0001
%LBS_SORT              = &H0002
%LBS_NOREDRAW          = &H0004
%LBS_MULTIPLESEL       = &H0008
%LBS_OWNERDRAWFIXED    = &H0010
%LBS_OWNERDRAWVARIABLE = &H0020
%LBS_HASSTRINGS        = &H0040
%LBS_USETABSTOPS       = &H0080
%LBS_NOINTEGRALHEIGHT  = &H0100
%LBS_MULTICOLUMN       = &H0200
%LBS_WANTKEYBOARDINPUT = &H0400
%LBS_EXTENDEDSEL       = &H0800
%LBS_DISABLENOSCROLL   = &H1000
%LBS_NODATA            = &H2000
#IF (%WINVER >= &H0400)
%LBS_NOSEL             = &H4000
#ENDIF ' %WINVER >= &H0400
%LBS_COMBOBOX          = &H8000??

%LBS_STANDARD        = (%LBS_NOTIFY OR %LBS_SORT OR %WS_VSCROLL OR %WS_BORDER)


#ENDIF ' NOT %NOWINSTYLES


'
' Combo Box return Values
'
%CB_OKAY           = 0
%CB_ERR            = -1
%CB_ERRSPACE       = -2


'
' Combo Box Notification Codes
'
%CBN_ERRSPACE      = -1
%CBN_SELCHANGE     = 1
%CBN_DBLCLK        = 2
%CBN_SETFOCUS      = 3
%CBN_KILLFOCUS     = 4
%CBN_EDITCHANGE    = 5
%CBN_EDITUPDATE    = 6
%CBN_DROPDOWN      = 7
%CBN_CLOSEUP       = 8
%CBN_SELENDOK      = 9
%CBN_SELENDCANCEL  = 10

#IF NOT %DEF(%NOWINSTYLES)

'
' Combo Box styles
'
%CBS_SIMPLE            = &H0001
%CBS_DROPDOWN          = &H0002
%CBS_DROPDOWNLIST      = &H0003
%CBS_OWNERDRAWFIXED    = &H0010
%CBS_OWNERDRAWVARIABLE = &H0020
%CBS_AUTOHSCROLL       = &H0040
%CBS_OEMCONVERT        = &H0080
%CBS_SORT              = &H0100
%CBS_HASSTRINGS        = &H0200
%CBS_NOINTEGRALHEIGHT  = &H0400
%CBS_DISABLENOSCROLL   = &H0800
#IF (%WINVER >= &H0400)
%CBS_UPPERCASE         = &H2000
%CBS_LOWERCASE         = &H4000
#ENDIF ' %WINVER >= &H0400

#ENDIF  ' NOT %NOWINSTYLES


'
' Combo Box messages
'
#IF NOT %DEF(%NOWINMESSAGES)
%CB_GETEDITSEL              = &H0140
%CB_LIMITTEXT               = &H0141
%CB_SETEDITSEL              = &H0142
%CB_ADDSTRING               = &H0143
%CB_DELETESTRING            = &H0144
%CB_DIR                     = &H0145
%CB_GETCOUNT                = &H0146
%CB_GETCURSEL               = &H0147
%CB_GETLBTEXT               = &H0148
%CB_GETLBTEXTLEN            = &H0149
%CB_INSERTSTRING            = &H014A
%CB_RESETCONTENT            = &H014B
%CB_FINDSTRING              = &H014C
%CB_SELECTSTRING            = &H014D
%CB_SETCURSEL               = &H014E
%CB_SHOWDROPDOWN            = &H014F
%CB_GETITEMDATA             = &H0150
%CB_SETITEMDATA             = &H0151
%CB_GETDROPPEDCONTROLRECT   = &H0152
%CB_SETITEMHEIGHT           = &H0153
%CB_GETITEMHEIGHT           = &H0154
%CB_SETEXTENDEDUI           = &H0155
%CB_GETEXTENDEDUI           = &H0156
%CB_GETDROPPEDSTATE         = &H0157
%CB_FINDSTRINGEXACT         = &H0158
%CB_SETLOCALE               = &H0159
%CB_GETLOCALE               = &H015A
#IF (%WINVER >= &H0400)
%CB_GETTOPINDEX             = &H015b
%CB_SETTOPINDEX             = &H015c
%CB_GETHORIZONTALEXTENT     = &H015d
%CB_SETHORIZONTALEXTENT     = &H015e
%CB_GETDROPPEDWIDTH         = &H015f
%CB_SETDROPPEDWIDTH         = &H0160
%CB_INITSTORAGE             = &H0161
' [Microsoft never defines WIN32_WCE, so we can't test it]
'#IF (%WIN32_WCE >= &H0400)
#IF %DEF(%WIN32_WCE)
%CB_MULTIPLEADDSTRING       = &H0163
#ENDIF
#ENDIF ' %WINVER >= &H0400

#IF (%WIN32_WINNT >= &H0501)
%CB_GETCOMBOBOXINFO         = &H0164
#ENDIF ' %WIN32_WINNT >= &H0501

#IF (%WIN32_WINNT >= &H0501)
%CB_MSGMAX                  = &H0165
' [Microsoft never defines WIN32_WCE, so we can't test it]
'#ELSEIF (%WIN32_WCE >= &H0400)
#ELSEIF %DEF(%WIN32_WCE)
%CB_MSGMAX                  = &H0163
#ELSEIF (%WINVER >= &H0400)
%CB_MSGMAX                  = &H0162
#ELSE
%CB_MSGMAX                  = &H015B
#ENDIF
#ENDIF  ' NOT %NOWINMESSAGES



#IF NOT %DEF(%NOWINSTYLES)

'
' Scroll Bar Styles
'
%SBS_HORZ                    = &H0000
%SBS_VERT                    = &H0001
%SBS_TOPALIGN                = &H0002
%SBS_LEFTALIGN               = &H0002
%SBS_BOTTOMALIGN             = &H0004
%SBS_RIGHTALIGN              = &H0004
%SBS_SIZEBOXTOPLEFTALIGN     = &H0002
%SBS_SIZEBOXBOTTOMRIGHTALIGN = &H0004
%SBS_SIZEBOX                 = &H0008
#IF (%WINVER >= &H0400)
%SBS_SIZEGRIP                = &H0010
#ENDIF ' %WINVER >= &H0400


#ENDIF ' NOT %NOWINSTYLES

'
' Scroll bar messages
'
#IF NOT %DEF(%NOWINMESSAGES)
%SBM_SETPOS                  = &H00E0 ' not in win3.1
%SBM_GETPOS                  = &H00E1 ' not in win3.1
%SBM_SETRANGE                = &H00E2 ' not in win3.1
%SBM_SETRANGEREDRAW          = &H00E6 ' not in win3.1
%SBM_GETRANGE                = &H00E3 ' not in win3.1
%SBM_ENABLE_ARROWS           = &H00E4 ' not in win3.1
#IF (%WINVER >= &H0400)
%SBM_SETSCROLLINFO           = &H00E9
%SBM_GETSCROLLINFO           = &H00EA
#ENDIF ' %WINVER >= &H0400

#IF (%WIN32_WINNT >= &H0501)
%SBM_GETSCROLLBARINFO        = &H00EB
#ENDIF ' %WIN32_WINNT >= &H0501

#IF (%WINVER >= &H0400)
%SIF_RANGE           = &H0001
%SIF_PAGE            = &H0002
%SIF_POS             = &H0004
%SIF_DISABLENOSCROLL = &H0008
%SIF_TRACKPOS        = &H0010
%SIF_ALL             = (%SIF_RANGE OR %SIF_PAGE OR %SIF_POS OR %SIF_TRACKPOS)

TYPE SCROLLINFO
    cbSize    AS DWORD
    fMask     AS DWORD
    nMin      AS LONG
    nMax      AS LONG
    nPage     AS DWORD
    nPos      AS LONG
    nTrackPos AS LONG
END TYPE

DECLARE FUNCTION SetScrollInfo LIB "User32.dll" ALIAS "SetScrollInfo" _
    (BYVAL hWnd AS DWORD, BYVAL nBar AS LONG, lpcScrollInfo AS SCROLLINFO, _
    BYVAL fRedraw AS LONG) AS LONG

DECLARE FUNCTION GetScrollInfo LIB "User32.dll" ALIAS "GetScrollInfo" _
    (BYVAL hWnd AS DWORD, BYVAL nBar AS LONG, lpScrollInfo AS SCROLLINFO) _
    AS LONG

#ENDIF ' %WINVER >= &H0400
#ENDIF ' NOT %NOWINMESSAGES
#ENDIF ' NOT %NOCTLMGR



#IF NOT %DEF(%NOMDI)

'
' MDI client style bits
'
%MDIS_ALLCHILDSTYLES  = &H0001

'
' wParam Flags for %WM_MDITILE and %WM_MDICASCADE messages.
'
%MDITILE_VERTICAL     = &H0000 ' not in win3.1
%MDITILE_HORIZONTAL   = &H0001 ' not in win3.1
%MDITILE_SKIPDISABLED = &H0002 ' not in win3.1
#IF (%WIN32_WINNT >= &H0500)
%MDITILE_ZORDER       = &H0004
#ENDIF ' %WIN32_WINNT >= &H0500


TYPE MDICREATESTRUCTA
    szClass AS ASCIIZ PTR
    szTitle AS ASCIIZ PTR
    hOwner  AS DWORD
    x       AS LONG
    y       AS LONG
    cx      AS LONG
    cy      AS LONG
    STYLE   AS DWORD
    lParam  AS LONG         ' app-defined stuff
END TYPE

TYPE MDICREATESTRUCTW
    szClass AS WSTRINGZ PTR
    szTitle AS WSTRINGZ PTR
    hOwner  AS DWORD
    x       AS LONG
    y       AS LONG
    cx      AS LONG
    cy      AS LONG
    STYLE   AS DWORD
    lParam  AS LONG         ' app-defined stuff
END TYPE

#IF %DEF(%UNICODE)
TYPE MDICREATESTRUCT
    MDICREATESTRUCTW
END TYPE
#ELSE
TYPE MDICREATESTRUCT
    MDICREATESTRUCTA
END TYPE
#ENDIF ' UNICODE

TYPE CLIENTCREATESTRUCT
    hWindowMenu  AS DWORD
    idFirstChild AS DWORD
END TYPE

DECLARE FUNCTION DefFrameProcA LIB "User32.dll" ALIAS "DefFrameProcA" _
    (BYVAL hWnd AS DWORD, BYVAL hWndMDIClient AS DWORD, BYVAL uMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION DefFrameProcW LIB "User32.dll" ALIAS "DefFrameProcW" _
    (BYVAL hWnd AS DWORD, BYVAL hWndMDIClient AS DWORD, BYVAL uMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION DefFrameProc LIB "User32.dll" ALIAS "DefFrameProcW" _
    (BYVAL hWnd AS DWORD, BYVAL hWndMDIClient AS DWORD, BYVAL uMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG
#ELSE
DECLARE FUNCTION DefFrameProc LIB "User32.dll" ALIAS "DefFrameProcA" _
    (BYVAL hWnd AS DWORD, BYVAL hWndMDIClient AS DWORD, BYVAL uMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DefMDIChildProcA LIB "User32.dll" ALIAS "DefMDIChildProcA" _
    (BYVAL hWnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION DefMDIChildProcW LIB "User32.dll" ALIAS "DefMDIChildProcW" _
    (BYVAL hWnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION DefMDIChildProc LIB "User32.dll" ALIAS "DefMDIChildProcW" _
    (BYVAL hWnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG
#ELSE
DECLARE FUNCTION DefMDIChildProc LIB "User32.dll" ALIAS "DefMDIChildProcA" _
    (BYVAL hWnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

#IF NOT %DEF(%NOMSG)

DECLARE FUNCTION TranslateMDISysAccel LIB "User32.dll" _
    ALIAS "TranslateMDISysAccel" (BYVAL hWndClient AS DWORD, _
    lpMsg AS MSG_type) AS LONG

#ENDIF ' NOT %NOMSG

DECLARE FUNCTION ArrangeIconicWindows LIB "User32.dll" _
    ALIAS "ArrangeIconicWindows" (BYVAL hWnd AS DWORD) AS DWORD

DECLARE FUNCTION CreateMDIWindowA LIB "User32.dll" ALIAS "CreateMDIWindowA" _
    (lpClassName AS ASCIIZ, lpWindowName AS ASCIIZ, BYVAL dwStyle AS DWORD, _
    BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, _
    BYVAL nHeight AS LONG, BYVAL hwndParent AS DWORD, _
    BYVAL hInstance AS DWORD, BYVAL lParam AS LONG) AS DWORD

DECLARE FUNCTION CreateMDIWindowW LIB "User32.dll" ALIAS "CreateMDIWindowW" _
    (lpClassName AS WSTRINGZ, lpWindowName AS WSTRINGZ, _
    BYVAL dwStyle AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL hwndParent AS DWORD, _
    BYVAL hInstance AS DWORD, BYVAL lParam AS LONG) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateMDIWindow LIB "User32.dll" ALIAS "CreateMDIWindowW" _
    (lpClassName AS WSTRINGZ, lpWindowName AS WSTRINGZ, _
    BYVAL dwStyle AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL hwndParent AS DWORD, _
    BYVAL hInstance AS DWORD, BYVAL lParam AS LONG) AS DWORD
#ELSE
DECLARE FUNCTION CreateMDIWindow LIB "User32.dll" ALIAS "CreateMDIWindowA" _
    (lpClassName AS ASCIIZ, lpWindowName AS ASCIIZ, BYVAL dwStyle AS DWORD, _
    BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, _
    BYVAL nHeight AS LONG, BYVAL hwndParent AS DWORD, _
    BYVAL hInstance AS DWORD, BYVAL lParam AS LONG) AS DWORD
#ENDIF ' NOT %UNICODE

#IF (%WINVER >= &H0400)

DECLARE FUNCTION TileWindows LIB "User32.dll" ALIAS "TileWindows" _
    (BYVAL hwndParent AS DWORD, BYVAL dwHow AS DWORD, lpRect AS RECT, _
    BYVAL cKids AS DWORD, BYVAL lpKids AS DWORD PTR) AS WORD

DECLARE FUNCTION CascadeWindows LIB "User32.dll" ALIAS "CascadeWindows" _
    (BYVAL hwndParent AS DWORD, BYVAL uHow AS DWORD, lpRect AS RECT, _
    BYVAL cKids AS DWORD, BYVAL lpKids AS DWORD PTR) AS WORD

#ENDIF ' %WINVER >= &H0400
#ENDIF ' NOT %NOMDI

#ENDIF ' NOT %NOUSER



'****** Help support ********************************************************

#IF NOT %DEF(%NOHELP)

TYPE MULTIKEYHELPA
#IF NOT %DEF(%MAC)
    mkSize      AS DWORD
#ELSE
    mkSize      AS WORD
#ENDIF
    mkKeylist   AS STRING * 1
    szKeyphrase AS ASCIIZ * 128
END TYPE

TYPE MULTIKEYHELPW
#IF NOT %DEF(%MAC)
    mkSize      AS DWORD
#ELSE
    mkSize      AS WORD
#ENDIF
    mkKeylist   AS WSTRING * 1
    szKeyphrase AS WSTRINGZ * 128
END TYPE

#IF %DEF(%UNICODE)
TYPE MULTIKEYHELP
    MULTIKEYHELPW
END TYPE
#ELSE
TYPE MULTIKEYHELP
    MULTIKEYHELPA
END TYPE
#ENDIF ' UNICODE

TYPE HELPWININFOA
    wStructSize AS LONG
    x           AS LONG
    y           AS LONG
    dx          AS LONG
    dy          AS LONG
    wMax        AS LONG
    rgchMember  AS ASCIIZ * 128
END TYPE

TYPE HELPWININFOW
    wStructSize AS LONG
    x           AS LONG
    y           AS LONG
    dx          AS LONG
    dy          AS LONG
    wMax        AS LONG
    rgchMember  AS WSTRINGZ * 128
END TYPE

#IF %DEF(%UNICODE)
TYPE HELPWININFO
    HELPWININFOW
END TYPE
#ELSE
TYPE HELPWININFO
    HELPWININFOA
END TYPE
#ENDIF ' UNICODE


'
' Commands to pass to WinHelp()
'
%HELP_CONTEXT       = &H00000001   ' Display topic in ulTopic
%HELP_QUIT          = &H00000002   ' Terminate help
%HELP_INDEX         = &H00000003   ' Display index
%HELP_CONTENTS      = &H00000003
%HELP_HELPONHELP    = &H00000004   ' Display help on using help
%HELP_SETINDEX      = &H00000005   ' Set current Index for multi index help
%HELP_SETCONTENTS   = &H00000005
%HELP_CONTEXTPOPUP  = &H00000008
%HELP_FORCEFILE     = &H00000009
%HELP_KEY           = &H00000101   ' Display topic for keyword in offabData
%HELP_COMMAND       = &H00000102
%HELP_PARTIALKEY    = &H00000105
%HELP_MULTIKEY      = &H00000201
%HELP_SETWINPOS     = &H00000203
#IF (%WINVER >= &H0400)
%HELP_CONTEXTMENU   = &H0000000a
%HELP_FINDER        = &H0000000b
%HELP_WM_HELP       = &H0000000c
%HELP_SETPOPUP_POS  = &H0000000d

%HELP_TCARD              = &H00008000
%HELP_TCARD_DATA         = &H00000010
%HELP_TCARD_OTHER_CALLER = &H00000011

' These are in winhelp.h in Win95.
%IDH_NO_HELP             = 28440
%IDH_MISSING_CONTEXT     = 28441 ' Control doesn't have matching help context
%IDH_GENERIC_HELP_BUTTON = 28442 ' Property sheet help button
%IDH_OK                  = 28443
%IDH_CANCEL              = 28444
%IDH_HELP                = 28445

#ENDIF ' %WINVER >= &H0400


DECLARE FUNCTION WinHelpA LIB "User32.dll" ALIAS "WinHelpA" _
    (BYVAL hWnd AS DWORD, lpHelpFile AS ASCIIZ, BYVAL uCommand AS DWORD, _
    BYVAL dwData AS DWORD) AS LONG

DECLARE FUNCTION WinHelpW LIB "User32.dll" ALIAS "WinHelpW" _
    (BYVAL hWnd AS DWORD, lpHelpFile AS WSTRINGZ, BYVAL uCommand AS DWORD, _
    BYVAL dwData AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION WinHelp LIB "User32.dll" ALIAS "WinHelpW" _
    (BYVAL hWnd AS DWORD, lpHelpFile AS WSTRINGZ, BYVAL uCommand AS DWORD, _
    BYVAL dwData AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION WinHelp LIB "User32.dll" ALIAS "WinHelpA" _
    (BYVAL hWnd AS DWORD, lpHelpFile AS ASCIIZ, BYVAL uCommand AS DWORD, _
    BYVAL dwData AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' NOT %NOHELP

#IF (%WINVER >= &H0500)

%GR_GDIOBJECTS   = 0       ' Count of GDI objects
%GR_USEROBJECTS  = 1       ' Count of USER objects
#ENDIF ' %WINVER >= &H0500
#IF (%WINVER >= &H0601)
%GR_GDIOBJECTS_PEAK  = 2       ' Peak count of GDI objects
%GR_USEROBJECTS_PEAK = 4       ' Peak count of USER objects
#ENDIF  ' %WINVER >= &H0601

#IF (%WINVER >= &H0601)
%GR_GLOBAL           = &HFFFFFFFE???   ' ((HANDLE)-2)
#ENDIF ' %WINVER >= &H0601

#IF (%WINVER >= &H0500)

DECLARE FUNCTION GetGuiResources LIB "User32.dll" ALIAS "GetGuiResources" ( _
    BYVAL hProcess AS DWORD, BYVAL uiFlags AS DWORD) AS DWORD

#ENDIF ' %WINVER >= &H0500


#IF NOT %DEF(%NOSYSPARAMSINFO)

'
' Parameter for SystemParametersInfo()
'

%SPI_GETBEEP                 = &H0001
%SPI_SETBEEP                 = &H0002
%SPI_GETMOUSE                = &H0003
%SPI_SETMOUSE                = &H0004
%SPI_GETBORDER               = &H0005
%SPI_SETBORDER               = &H0006
%SPI_GETKEYBOARDSPEED        = &H000A
%SPI_SETKEYBOARDSPEED        = &H000B
%SPI_LANGDRIVER              = &H000C
%SPI_ICONHORIZONTALSPACING   = &H000D
%SPI_GETSCREENSAVETIMEOUT    = &H000E
%SPI_SETSCREENSAVETIMEOUT    = &H000F
%SPI_GETSCREENSAVEACTIVE     = &H0010
%SPI_SETSCREENSAVEACTIVE     = &H0011
%SPI_GETGRIDGRANULARITY      = &H0012
%SPI_SETGRIDGRANULARITY      = &H0013
%SPI_SETDESKWALLPAPER        = &H0014
%SPI_SETDESKPATTERN          = &H0015
%SPI_GETKEYBOARDDELAY        = &H0016
%SPI_SETKEYBOARDDELAY        = &H0017
%SPI_ICONVERTICALSPACING     = &H0018
%SPI_GETICONTITLEWRAP        = &H0019
%SPI_SETICONTITLEWRAP        = &H001A
%SPI_GETMENUDROPALIGNMENT    = &H001B
%SPI_SETMENUDROPALIGNMENT    = &H001C
%SPI_SETDOUBLECLKWIDTH       = &H001D
%SPI_SETDOUBLECLKHEIGHT      = &H001E
%SPI_GETICONTITLELOGFONT     = &H001F
%SPI_SETDOUBLECLICKTIME      = &H0020
%SPI_SETMOUSEBUTTONSWAP      = &H0021
%SPI_SETICONTITLELOGFONT     = &H0022
%SPI_GETFASTTASKSWITCH       = &H0023
%SPI_SETFASTTASKSWITCH       = &H0024
#IF (%WINVER >= &H0400)
%SPI_SETDRAGFULLWINDOWS      = &H0025
%SPI_GETDRAGFULLWINDOWS      = &H0026
%SPI_GETNONCLIENTMETRICS     = &H0029
%SPI_SETNONCLIENTMETRICS     = &H002A
%SPI_GETMINIMIZEDMETRICS     = &H002B
%SPI_SETMINIMIZEDMETRICS     = &H002C
%SPI_GETICONMETRICS          = &H002D
%SPI_SETICONMETRICS          = &H002E
%SPI_SETWORKAREA             = &H002F
%SPI_GETWORKAREA             = &H0030
%SPI_SETPENWINDOWS           = &H0031

%SPI_GETHIGHCONTRAST         = &H0042
%SPI_SETHIGHCONTRAST         = &H0043
%SPI_GETKEYBOARDPREF         = &H0044
%SPI_SETKEYBOARDPREF         = &H0045
%SPI_GETSCREENREADER         = &H0046
%SPI_SETSCREENREADER         = &H0047
%SPI_GETANIMATION            = &H0048
%SPI_SETANIMATION            = &H0049
%SPI_GETFONTSMOOTHING        = &H004A
%SPI_SETFONTSMOOTHING        = &H004B
%SPI_SETDRAGWIDTH            = &H004C
%SPI_SETDRAGHEIGHT           = &H004D
%SPI_SETHANDHELD             = &H004E
%SPI_GETLOWPOWERTIMEOUT      = &H004F
%SPI_GETPOWEROFFTIMEOUT      = &H0050
%SPI_SETLOWPOWERTIMEOUT      = &H0051
%SPI_SETPOWEROFFTIMEOUT      = &H0052
%SPI_GETLOWPOWERACTIVE       = &H0053
%SPI_GETPOWEROFFACTIVE       = &H0054
%SPI_SETLOWPOWERACTIVE       = &H0055
%SPI_SETPOWEROFFACTIVE       = &H0056
%SPI_SETCURSORS              = &H0057
%SPI_SETICONS                = &H0058
%SPI_GETDEFAULTINPUTLANG     = &H0059
%SPI_SETDEFAULTINPUTLANG     = &H005A
%SPI_SETLANGTOGGLE           = &H005B
%SPI_GETWINDOWSEXTENSION     = &H005C
%SPI_SETMOUSETRAILS          = &H005D
%SPI_GETMOUSETRAILS          = &H005E
%SPI_SETSCREENSAVERRUNNING   = &H0061
%SPI_SCREENSAVERRUNNING     = %SPI_SETSCREENSAVERRUNNING
#ENDIF ' %WINVER >= &H0400
%SPI_GETFILTERKEYS          = &H0032
%SPI_SETFILTERKEYS          = &H0033
%SPI_GETTOGGLEKEYS          = &H0034
%SPI_SETTOGGLEKEYS          = &H0035
%SPI_GETMOUSEKEYS           = &H0036
%SPI_SETMOUSEKEYS           = &H0037
%SPI_GETSHOWSOUNDS          = &H0038
%SPI_SETSHOWSOUNDS          = &H0039
%SPI_GETSTICKYKEYS          = &H003A
%SPI_SETSTICKYKEYS          = &H003B
%SPI_GETACCESSTIMEOUT       = &H003C
%SPI_SETACCESSTIMEOUT       = &H003D
#IF (%WINVER >= &H0400)
%SPI_GETSERIALKEYS          = &H003E
%SPI_SETSERIALKEYS          = &H003F
#ENDIF ' %WINVER >= &H0400
%SPI_GETSOUNDSENTRY         = &H0040
%SPI_SETSOUNDSENTRY         = &H0041
#IF (%WIN32_WINNT >= &H0400)
%SPI_GETSNAPTODEFBUTTON     = &H005F
%SPI_SETSNAPTODEFBUTTON     = &H0060
#ENDIF ' %WIN32_WINNT >= &H0400
#IF (%WIN32_WINNT >= &H0400) OR (%WIN32_WINDOWS > &H0400)
%SPI_GETMOUSEHOVERWIDTH     = &H0062
%SPI_SETMOUSEHOVERWIDTH     = &H0063
%SPI_GETMOUSEHOVERHEIGHT    = &H0064
%SPI_SETMOUSEHOVERHEIGHT    = &H0065
%SPI_GETMOUSEHOVERTIME      = &H0066
%SPI_SETMOUSEHOVERTIME      = &H0067
%SPI_GETWHEELSCROLLLINES    = &H0068
%SPI_SETWHEELSCROLLLINES    = &H0069
%SPI_GETMENUSHOWDELAY       = &H006A
%SPI_SETMENUSHOWDELAY       = &H006B

#IF (%WIN32_WINNT >= &H0600)
%SPI_GETWHEELSCROLLCHARS   = &H006C
%SPI_SETWHEELSCROLLCHARS   = &H006D
#ENDIF

%SPI_GETSHOWIMEUI          = &H006E
%SPI_SETSHOWIMEUI          = &H006F
#ENDIF


#IF (%WINVER >= &H0500)
%SPI_GETMOUSESPEED         = &H0070
%SPI_SETMOUSESPEED         = &H0071
%SPI_GETSCREENSAVERRUNNING = &H0072
%SPI_GETDESKWALLPAPER      = &H0073
#ENDIF ' %WINVER >= &H0500

#IF (%WINVER >= &H0600)
%SPI_GETAUDIODESCRIPTION   = &H0074
%SPI_SETAUDIODESCRIPTION   = &H0075

%SPI_GETSCREENSAVESECURE   = &H0076
%SPI_SETSCREENSAVESECURE   = &H0077
#ENDIF ' %WINVER >= &H0600

#IF (%WIN32_WINNT >= &H0601)
%SPI_GETHUNGAPPTIMEOUT           = &H0078
%SPI_SETHUNGAPPTIMEOUT           = &H0079
%SPI_GETWAITTOKILLTIMEOUT        = &H007A
%SPI_SETWAITTOKILLTIMEOUT        = &H007B
%SPI_GETWAITTOKILLSERVICETIMEOUT = &H007C
%SPI_SETWAITTOKILLSERVICETIMEOUT = &H007D
%SPI_GETMOUSEDOCKTHRESHOLD       = &H007E
%SPI_SETMOUSEDOCKTHRESHOLD       = &H007F
%SPI_GETPENDOCKTHRESHOLD         = &H0080
%SPI_SETPENDOCKTHRESHOLD         = &H0081
%SPI_GETWINARRANGING             = &H0082
%SPI_SETWINARRANGING             = &H0083
%SPI_GETMOUSEDRAGOUTTHRESHOLD    = &H0084
%SPI_SETMOUSEDRAGOUTTHRESHOLD    = &H0085
%SPI_GETPENDRAGOUTTHRESHOLD      = &H0086
%SPI_SETPENDRAGOUTTHRESHOLD      = &H0087
%SPI_GETMOUSESIDEMOVETHRESHOLD   = &H0088
%SPI_SETMOUSESIDEMOVETHRESHOLD   = &H0089
%SPI_GETPENSIDEMOVETHRESHOLD     = &H008A
%SPI_SETPENSIDEMOVETHRESHOLD     = &H008B
%SPI_GETDRAGFROMMAXIMIZE         = &H008C
%SPI_SETDRAGFROMMAXIMIZE         = &H008D
%SPI_GETSNAPSIZING               = &H008E
%SPI_SETSNAPSIZING               = &H008F
%SPI_GETDOCKMOVING               = &H0090
%SPI_SETDOCKMOVING               = &H0091
#ENDIF ' %WIN32_WINNT >= &H0601

#IF (%WINVER >= &H0500)
%SPI_GETACTIVEWINDOWTRACKING         = &H1000
%SPI_SETACTIVEWINDOWTRACKING         = &H1001
%SPI_GETMENUANIMATION                = &H1002
%SPI_SETMENUANIMATION                = &H1003
%SPI_GETCOMBOBOXANIMATION            = &H1004
%SPI_SETCOMBOBOXANIMATION            = &H1005
%SPI_GETLISTBOXSMOOTHSCROLLING       = &H1006
%SPI_SETLISTBOXSMOOTHSCROLLING       = &H1007
%SPI_GETGRADIENTCAPTIONS             = &H1008
%SPI_SETGRADIENTCAPTIONS             = &H1009
%SPI_GETKEYBOARDCUES                 = &H100A
%SPI_SETKEYBOARDCUES                 = &H100B
%SPI_GETMENUUNDERLINES               = %SPI_GETKEYBOARDCUES
%SPI_SETMENUUNDERLINES               = %SPI_SETKEYBOARDCUES
%SPI_GETACTIVEWNDTRKZORDER           = &H100C
%SPI_SETACTIVEWNDTRKZORDER           = &H100D
%SPI_GETHOTTRACKING                  = &H100E
%SPI_SETHOTTRACKING                  = &H100F
%SPI_GETMENUFADE                     = &H1012
%SPI_SETMENUFADE                     = &H1013
%SPI_GETSELECTIONFADE                = &H1014
%SPI_SETSELECTIONFADE                = &H1015
%SPI_GETTOOLTIPANIMATION             = &H1016
%SPI_SETTOOLTIPANIMATION             = &H1017
%SPI_GETTOOLTIPFADE                  = &H1018
%SPI_SETTOOLTIPFADE                  = &H1019
%SPI_GETCURSORSHADOW                 = &H101A
%SPI_SETCURSORSHADOW                 = &H101B
#IF (%WIN32_WINNT >= &H0501)
%SPI_GETMOUSESONAR                   = &H101C
%SPI_SETMOUSESONAR                   = &H101D
%SPI_GETMOUSECLICKLOCK               = &H101E
%SPI_SETMOUSECLICKLOCK               = &H101F
%SPI_GETMOUSEVANISH                  = &H1020
%SPI_SETMOUSEVANISH                  = &H1021
%SPI_GETFLATMENU                     = &H1022
%SPI_SETFLATMENU                     = &H1023
%SPI_GETDROPSHADOW                   = &H1024
%SPI_SETDROPSHADOW                   = &H1025
%SPI_GETBLOCKSENDINPUTRESETS         = &H1026
%SPI_SETBLOCKSENDINPUTRESETS         = &H1027
#ENDIF ' %WIN32_WINNT >= &H0501

%SPI_GETUIEFFECTS                    = &H103E
%SPI_SETUIEFFECTS                    = &H103F

#IF (%WIN32_WINNT >= &H0600)
%SPI_GETDISABLEOVERLAPPEDCONTENT     = &H1040
%SPI_SETDISABLEOVERLAPPEDCONTENT     = &H1041
%SPI_GETCLIENTAREAANIMATION          = &H1042
%SPI_SETCLIENTAREAANIMATION          = &H1043
%SPI_GETCLEARTYPE                    = &H1048
%SPI_SETCLEARTYPE                    = &H1049
%SPI_GETSPEECHRECOGNITION            = &H104A
%SPI_SETSPEECHRECOGNITION            = &H104B
#ENDIF ' %WIN32_WINNT >= &H0600

%SPI_GETFOREGROUNDLOCKTIMEOUT        = &H2000
%SPI_SETFOREGROUNDLOCKTIMEOUT        = &H2001
%SPI_GETACTIVEWNDTRKTIMEOUT          = &H2002
%SPI_SETACTIVEWNDTRKTIMEOUT          = &H2003
%SPI_GETFOREGROUNDFLASHCOUNT         = &H2004
%SPI_SETFOREGROUNDFLASHCOUNT         = &H2005
%SPI_GETCARETWIDTH                   = &H2006
%SPI_SETCARETWIDTH                   = &H2007

#IF (%WIN32_WINNT >= &H0501)
%SPI_GETMOUSECLICKLOCKTIME           = &H2008
%SPI_SETMOUSECLICKLOCKTIME           = &H2009
%SPI_GETFONTSMOOTHINGTYPE            = &H200A
%SPI_SETFONTSMOOTHINGTYPE            = &H200B

' constants for SPI_GETFONTSMOOTHINGTYPE and SPI_SETFONTSMOOTHINGTYPE:
%FE_FONTSMOOTHINGSTANDARD            = &H0001
%FE_FONTSMOOTHINGCLEARTYPE           = &H0002
%FE_FONTSMOOTHINGDOCKING             = &H8000??

%SPI_GETFONTSMOOTHINGCONTRAST        = &H200C
%SPI_SETFONTSMOOTHINGCONTRAST        = &H200D

%SPI_GETFOCUSBORDERWIDTH             = &H200E
%SPI_SETFOCUSBORDERWIDTH             = &H200F
%SPI_GETFOCUSBORDERHEIGHT            = &H2010
%SPI_SETFOCUSBORDERHEIGHT            = &H2011

%SPI_GETFONTSMOOTHINGORIENTATION     = &H2012
%SPI_SETFONTSMOOTHINGORIENTATION     = &H2013

' constants for SPI_GETFONTSMOOTHINGORIENTATION and SPI_SETFONTSMOOTHINGORIENTATION:
%FE_FONTSMOOTHINGORIENTATIONBGR   = &H0000
%FE_FONTSMOOTHINGORIENTATIONRGB   = &H0001
#ENDIF ' %WIN32_WINNT >= &H0501

#IF (%WIN32_WINNT >= &H0600)
%SPI_GETMINIMUMHITRADIUS             = &H2014
%SPI_SETMINIMUMHITRADIUS             = &H2015
%SPI_GETMESSAGEDURATION              = &H2016
%SPI_SETMESSAGEDURATION              = &H2017
#ENDIF ' %WIN32_WINNT >= &H0600

#ENDIF ' %WINVER >= &H0500

'
' Flags
'
%SPIF_UPDATEINIFILE    = &H0001
%SPIF_SENDWININICHANGE = &H0002
%SPIF_SENDCHANGE       = %SPIF_SENDWININICHANGE

%METRICS_USEDEFAULT = -1

'#IF %DEF(%WINGDI)
#IF NOT %DEF(%NOGDI)

TYPE NONCLIENTMETRICSA
    cbSize             AS DWORD
    iBorderWidth       AS LONG
    iScrollWidth       AS LONG
    iScrollHeight      AS LONG
    iCaptionWidth      AS LONG
    iCaptionHeight     AS LONG
    lfCaptionFont      AS LOGFONTA
    iSmCaptionWidth    AS LONG
    iSmCaptionHeight   AS LONG
    lfSmCaptionFont    AS LOGFONTA
    iMenuWidth         AS LONG
    iMenuHeight        AS LONG
    lfMenuFont         AS LOGFONTA
    lfStatusFont       AS LOGFONTA
    lfMessageFont      AS LOGFONTA
#IF (%WINVER >= &H0600)
    iPaddedBorderWidth AS LONG
#ENDIF ' %WINVER >= &H0600
END TYPE

TYPE NONCLIENTMETRICSW
    cbSize             AS DWORD
    iBorderWidth       AS LONG
    iScrollWidth       AS LONG
    iScrollHeight      AS LONG
    iCaptionWidth      AS LONG
    iCaptionHeight     AS LONG
    lfCaptionFont      AS LOGFONTW
    iSmCaptionWidth    AS LONG
    iSmCaptionHeight   AS LONG
    lfSmCaptionFont    AS LOGFONTW
    iMenuWidth         AS LONG
    iMenuHeight        AS LONG
    lfMenuFont         AS LOGFONTW
    lfStatusFont       AS LOGFONTW
    lfMessageFont      AS LOGFONTW
#IF (%WINVER >= &H0600)
    iPaddedBorderWidth AS LONG
#ENDIF ' %WINVER >= &H0600
END TYPE

#IF %DEF(%UNICODE)
TYPE NONCLIENTMETRICS
    NONCLIENTMETRICSW
END TYPE
#ELSE
TYPE NONCLIENTMETRICS
    NONCLIENTMETRICSA
END TYPE
#ENDIF ' UNICODE
#ENDIF ' %NOGDI
'#ENDIF ' %WINGDI

%ARW_BOTTOMLEFT       = &H0000
%ARW_BOTTOMRIGHT      = &H0001
%ARW_TOPLEFT          = &H0002
%ARW_TOPRIGHT         = &H0003
%ARW_STARTMASK        = &H0003
%ARW_STARTRIGHT       = &H0001
%ARW_STARTTOP         = &H0002

%ARW_LEFT             = &H0000
%ARW_RIGHT            = &H0000
%ARW_UP               = &H0004
%ARW_DOWN             = &H0004
%ARW_HIDE             = &H0008

TYPE MINIMIZEDMETRICS
    cbSize   AS DWORD
    iWidth   AS LONG
    iHorzGap AS LONG
    iVertGap AS LONG
    iArrange AS LONG
END TYPE

#IF %DEF(%WINGDI)
#IF NOT %DEF(%NOGDI)

TYPE ICONMETRICSA
    cbSize       AS DWORD
    iHorzSpacing AS LONG
    iVertSpacing AS LONG
    iTitleWrap   AS LONG
    lfFont       AS LOGFONTA
END TYPE

TYPE ICONMETRICSW
    cbSize       AS DWORD
    iHorzSpacing AS LONG
    iVertSpacing AS LONG
    iTitleWrap   AS LONG
    lfFont       AS LOGFONTW
END TYPE

#IF %DEF(%UNICODE)
TYPE ICONMETRICS
    ICONMETRICSW
END TYPE
#ELSE
TYPE ICONMETRICS
    ICONMETRICSA
END TYPE
#ENDIF ' UNICODE

#ENDIF ' %NOGDI
#ENDIF ' %WINGDI



TYPE ANIMATIONINFO
    cbSize      AS DWORD
    iMinAnimate AS LONG
END TYPE

TYPE SERIALKEYSA
    cbSize         AS DWORD
    dwFlags        AS DWORD
    lpszActivePort AS ASCIIZ PTR
    lpszPort       AS ASCIIZ PTR
    iBaudRate      AS DWORD
    iPortState     AS DWORD
    iActive        AS DWORD
END TYPE

TYPE SERIALKEYSW
    cbSize         AS DWORD
    dwFlags        AS DWORD
    lpszActivePort AS WSTRINGZ PTR
    lpszPort       AS WSTRINGZ PTR
    iBaudRate      AS DWORD
    iPortState     AS DWORD
    iActive        AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE SERIALKEYS
    SERIALKEYSW
END TYPE
#ELSE
TYPE SERIALKEYS
    SERIALKEYSA
END TYPE
#ENDIF ' UNICODE

' flags for SERIALKEYS dwFlags field
%SERKF_SERIALKEYSON = &H00000001
%SERKF_AVAILABLE    = &H00000002
%SERKF_INDICATOR    = &H00000004


TYPE HIGHCONTRASTA
    cbSize            AS DWORD
    dwFlags           AS DWORD
    lpszDefaultScheme AS ASCIIZ PTR
END TYPE

TYPE HIGHCONTRASTW
    cbSize            AS DWORD
    dwFlags           AS DWORD
    lpszDefaultScheme AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE HIGHCONTRAST
    HIGHCONTRASTW
END TYPE
#ELSE
TYPE HIGHCONTRAST
    HIGHCONTRASTA
END TYPE
#ENDIF ' %UNICODE

' flags for HIGHCONTRAST dwFlags field
%HCF_HIGHCONTRASTON     = &H00000001
%HCF_AVAILABLE          = &H00000002
%HCF_HOTKEYACTIVE       = &H00000004
%HCF_CONFIRMHOTKEY      = &H00000008
%HCF_HOTKEYSOUND        = &H00000010
%HCF_INDICATOR          = &H00000020
%HCF_HOTKEYAVAILABLE    = &H00000040
%HCF_LOGONDESKTOP       = &H00000100
%HCF_DEFAULTDESKTOP     = &H00000200

' Flags for ChangeDisplaySettings
%CDS_UPDATEREGISTRY           = &H00000001
%CDS_TEST                     = &H00000002
%CDS_FULLSCREEN               = &H00000004
%CDS_GLOBAL                   = &H00000008
%CDS_SET_PRIMARY              = &H00000010
%CDS_VIDEOPARAMETERS          = &H00000020
#IF (%WINVER >= &H0600)
%CDS_ENABLE_UNSAFE_MODES      = &H00000100
%CDS_DISABLE_UNSAFE_MODES     = &H00000200
#ENDIF ' %WINVER >= &H0600
%CDS_RESET                    = &H40000000
%CDS_RESET_EX                 = &H20000000
%CDS_NORESET                  = &H10000000

#INCLUDE "tvout.inc"

' Return values for ChangeDisplaySettings
%DISP_CHANGE_SUCCESSFUL    =  0
%DISP_CHANGE_RESTART       =  1
%DISP_CHANGE_FAILED        = -1
%DISP_CHANGE_BADMODE       = -2
%DISP_CHANGE_NOTUPDATED    = -3
%DISP_CHANGE_BADFLAGS      = -4
%DISP_CHANGE_BADPARAM      = -5
#IF (%WIN32_WINNT >= &H0501)
%DISP_CHANGE_BADDUALVIEW   = -6
#ENDIF ' %WIN32_WINNT >= &H0501

#IF %DEF(%WINGDI)
#IF NOT %DEF(%NOGDI)

DECLARE FUNCTION ChangeDisplaySettingsA LIB "User32.dll" _
    ALIAS "ChangeDisplaySettingsA" (lpDevMode AS DEVMODEA, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION ChangeDisplaySettingsW LIB "User32.dll" _
    ALIAS "ChangeDisplaySettingsW" (lpDevMode AS DEVMODEW, _
    BYVAL dwFlags AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ChangeDisplaySettings LIB "User32.dll" _
    ALIAS "ChangeDisplaySettingsW" (lpDevMode AS DEVMODEW, _
    BYVAL dwFlags AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION ChangeDisplaySettings LIB "User32.dll" _
    ALIAS "ChangeDisplaySettingsA" (lpDevMode AS DEVMODEA, _
    BYVAL dwFlags AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION ChangeDisplaySettingsExA LIB "User32.dll" _
    ALIAS "ChangeDisplaySettingsExA" (lpszDeviceName AS ASCIIZ, _
    lpDevMode AS DEVMODEA, BYVAL hwnd AS DWORD, BYVAL dwFlags AS DWORD, _
    lParam AS VIDEOPARAMETERS) AS LONG

DECLARE FUNCTION ChangeDisplaySettingsExW LIB "User32.dll" _
    ALIAS "ChangeDisplaySettingsExW" (lpszDeviceName AS WSTRINGZ, _
    lpDevMode AS DEVMODEW, BYVAL hwnd AS DWORD, BYVAL dwFlags AS DWORD, _
    lParam AS VIDEOPARAMETERS) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ChangeDisplaySettingsEx LIB "User32.dll" _
    ALIAS "ChangeDisplaySettingsExW" (lpszDeviceName AS WSTRINGZ, _
    lpDevMode AS DEVMODEW, BYVAL hwnd AS DWORD, BYVAL dwFlags AS DWORD, _
    lParam AS VIDEOPARAMETERS) AS LONG
#ELSE
DECLARE FUNCTION ChangeDisplaySettingsEx LIB "User32.dll" _
    ALIAS "ChangeDisplaySettingsExA" (lpszDeviceName AS ASCIIZ, _
    lpDevMode AS DEVMODEA, BYVAL hwnd AS DWORD, BYVAL dwFlags AS DWORD, _
    lParam AS VIDEOPARAMETERS) AS LONG
#ENDIF ' NOT %UNICODE

%ENUM_CURRENT_SETTINGS  = &HFFFFFFFF???  ' ((DWORD)-1)
%ENUM_REGISTRY_SETTINGS = &HFFFFFFFE???  ' ((DWORD)-2)

DECLARE FUNCTION EnumDisplaySettingsA LIB "User32.dll" _
    ALIAS "EnumDisplaySettingsA" (lpszDeviceName AS ASCIIZ, _
    BYVAL iModeNum AS DWORD, lpDevMode AS DEVMODEA) AS LONG

DECLARE FUNCTION EnumDisplaySettingsW LIB "User32.dll" _
    ALIAS "EnumDisplaySettingsW" (lpszDeviceName AS WSTRINGZ, _
    BYVAL iModeNum AS DWORD, lpDevMode AS DEVMODEW) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION EnumDisplaySettings LIB "User32.dll" _
    ALIAS "EnumDisplaySettingsW" (lpszDeviceName AS WSTRINGZ, _
    BYVAL iModeNum AS DWORD, lpDevMode AS DEVMODEW) AS LONG
#ELSE
DECLARE FUNCTION EnumDisplaySettings LIB "User32.dll" _
    ALIAS "EnumDisplaySettingsA" (lpszDeviceName AS ASCIIZ, _
    BYVAL iModeNum AS DWORD, lpDevMode AS DEVMODEA) AS LONG
#ENDIF ' NOT %UNICODE

#IF (%WINVER >= &H0500)

DECLARE FUNCTION EnumDisplaySettingsExA LIB "User32.dll" _
    ALIAS "EnumDisplaySettingsExA" (lpszDeviceName AS ASCIIZ, _
    BYVAL iModeNum AS DWORD, lpDevMode AS DEVMODEA, BYVAL dwFlags AS DWORD) _
    AS LONG

DECLARE FUNCTION EnumDisplaySettingsExW LIB "User32.dll" _
    ALIAS "EnumDisplaySettingsExW" (lpszDeviceName AS WSTRINGZ, _
    BYVAL iModeNum AS DWORD, lpDevMode AS DEVMODEW, BYVAL dwFlags AS DWORD) _
    AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION EnumDisplaySettingsEx LIB "User32.dll" _
    ALIAS "EnumDisplaySettingsExW" (lpszDeviceName AS WSTRINGZ, _
    BYVAL iModeNum AS DWORD, lpDevMode AS DEVMODEW, BYVAL dwFlags AS DWORD) _
    AS LONG
#ELSE
DECLARE FUNCTION EnumDisplaySettingsEx LIB "User32.dll" _
    ALIAS "EnumDisplaySettingsExA" (lpszDeviceName AS ASCIIZ, _
    BYVAL iModeNum AS DWORD, lpDevMode AS DEVMODEA, BYVAL dwFlags AS DWORD) _
    AS LONG
#ENDIF ' NOT %UNICODE

' Flags for EnumDisplaySettingsEx
%EDS_RAWMODE     = &H00000002
%EDS_ROTATEDMODE = &H00000004

DECLARE FUNCTION EnumDisplayDevicesA LIB "User32.dll" _
    ALIAS "EnumDisplayDevicesA" (lpszDevice AS ASCIIZ, _
    BYVAL iDevNum AS DWORD, lpDisplayDevice AS DISPLAY_DEVICEA, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION EnumDisplayDevicesW LIB "User32.dll" _
    ALIAS "EnumDisplayDevicesW" (lpszDevice AS WSTRINGZ, _
    BYVAL iDevNum AS DWORD, lpDisplayDevice AS DISPLAY_DEVICEW, _
    BYVAL dwFlags AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION EnumDisplayDevices LIB "User32.dll" _
    ALIAS "EnumDisplayDevicesW" (lpszDevice AS WSTRINGZ, _
    BYVAL iDevNum AS DWORD, lpDisplayDevice AS DISPLAY_DEVICEW, _
    BYVAL dwFlags AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION EnumDisplayDevices LIB "User32.dll" _
    ALIAS "EnumDisplayDevicesA" (lpszDevice AS ASCIIZ, _
    BYVAL iDevNum AS DWORD, lpDisplayDevice AS DISPLAY_DEVICEA, _
    BYVAL dwFlags AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

' Flags for EnumDisplayDevices
%EDD_GET_DEVICE_INTERFACE_NAME = &H00000001
#ENDIF ' %WINVER >= &H0500

#IF (%WINVER >= &H0601)

DECLARE FUNCTION GetDisplayConfigBufferSizes LIB "User32.dll" _
    ALIAS "GetDisplayConfigBufferSizes" ( _
    BYVAL flags              AS DWORD, _
    numPathArrayElements     AS DWORD, _
    numModeInfoArrayElements AS DWORD) _
    AS LONG

DECLARE FUNCTION SetDisplayConfig LIB "User32.dll" _
    ALIAS "SetDisplayConfig" ( _
    BYVAL numPathArrayElements AS DWORD, _
    BYVAL pathArray AS DISPLAYCONFIG_PATH_INFO PTR, _
    BYVAL numModeInfoArrayElements AS DWORD, _
    BYVAL modeInfoArray AS DISPLAYCONFIG_MODE_INFO PTR, _
    BYVAL flags AS DWORD) _
    AS LONG

DECLARE FUNCTION QueryDisplayConfig LIB "User32.dll" _
    ALIAS "QueryDisplayConfig" ( _
    BYVAL flags AS DWORD, _
    numPathArrayElements AS DWORD, _
    BYVAL PathArray AS DISPLAYCONFIG_PATH_INFO PTR, _
    numModeInfoArrayElements AS DWORD, _
    BYVAL modeInfoArray AS DISPLAYCONFIG_MODE_INFO PTR, _
    currentTopologyId AS DISPLAYCONFIG_TOPOLOGY_ID_enum) _
    AS LONG

DECLARE FUNCTION DisplayConfigGetDeviceInfo LIB "User32.dll" _
    ALIAS "DisplayConfigGetDeviceInfo" ( _
    requestPacket AS DISPLAYCONFIG_DEVICE_INFO_HEADER) _
    AS LONG

DECLARE FUNCTION DisplayConfigSetDeviceInfo LIB "User32.dll" _
    ALIAS "DisplayConfigSetDeviceInfo" ( _
    setPacket AS DISPLAYCONFIG_DEVICE_INFO_HEADER) _
    AS LONG

#ENDIF ' %WINVER >= &H0601

#ENDIF ' %NOGDI
#ENDIF ' %WINGDI


DECLARE FUNCTION SystemParametersInfoA LIB "User32.dll" _
    ALIAS "SystemParametersInfoA" (BYVAL uAction AS DWORD, _
    BYVAL uParam AS DWORD, lpvParam AS ANY, BYVAL fuWinIni AS DWORD) AS LONG

DECLARE FUNCTION SystemParametersInfoW LIB "User32.dll" _
    ALIAS "SystemParametersInfoW" (BYVAL uAction AS DWORD, _
    BYVAL uParam AS DWORD, lpvParam AS ANY, BYVAL fuWinIni AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SystemParametersInfo LIB "User32.dll" _
    ALIAS "SystemParametersInfoW" (BYVAL uAction AS DWORD, _
    BYVAL uParam AS DWORD, lpvParam AS ANY, BYVAL fuWinIni AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SystemParametersInfo LIB "User32.dll" _
    ALIAS "SystemParametersInfoA" (BYVAL uAction AS DWORD, _
    BYVAL uParam AS DWORD, lpvParam AS ANY, BYVAL fuWinIni AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE


#ENDIF  ' NOT %NOSYSPARAMSINFO



'
' Accessibility support
'
TYPE FILTERKEYS
    cbSize      AS DWORD
    dwFlags     AS DWORD
    iWaitMSec   AS DWORD     ' Acceptance Delay
    iDelayMSec  AS DWORD     ' Delay Until Repeat
    iRepeatMSec AS DWORD     ' Repeat Rate
    iBounceMSec AS DWORD     ' Debounce Time
END TYPE

'
' FILTERKEYS dwFlags field
'
%FKF_FILTERKEYSON  = &H00000001
%FKF_AVAILABLE     = &H00000002
%FKF_HOTKEYACTIVE  = &H00000004
%FKF_CONFIRMHOTKEY = &H00000008
%FKF_HOTKEYSOUND   = &H00000010
%FKF_INDICATOR     = &H00000020
%FKF_CLICKON       = &H00000040

TYPE STICKYKEYS
    cbSize  AS DWORD
    dwFlags AS DWORD
END TYPE

'
' STICKYKEYS dwFlags field
'
%SKF_STICKYKEYSON    = &H00000001
%SKF_AVAILABLE       = &H00000002
%SKF_HOTKEYACTIVE    = &H00000004
%SKF_CONFIRMHOTKEY   = &H00000008
%SKF_HOTKEYSOUND     = &H00000010
%SKF_INDICATOR       = &H00000020
%SKF_AUDIBLEFEEDBACK = &H00000040
%SKF_TRISTATE        = &H00000080
%SKF_TWOKEYSOFF      = &H00000100
#IF (%WIN32_WINNT >= &H0500)
%SKF_LALTLATCHED       = &H10000000
%SKF_LCTLLATCHED       = &H04000000
%SKF_LSHIFTLATCHED     = &H01000000
%SKF_RALTLATCHED       = &H20000000
%SKF_RCTLLATCHED       = &H08000000
%SKF_RSHIFTLATCHED     = &H02000000
%SKF_LWINLATCHED       = &H40000000
%SKF_RWINLATCHED       = &H80000000???
%SKF_LALTLOCKED        = &H00100000
%SKF_LCTLLOCKED        = &H00040000
%SKF_LSHIFTLOCKED      = &H00010000
%SKF_RALTLOCKED        = &H00200000
%SKF_RCTLLOCKED        = &H00080000
%SKF_RSHIFTLOCKED      = &H00020000
%SKF_LWINLOCKED        = &H00400000
%SKF_RWINLOCKED        = &H00800000
#ENDIF ' %WIN32_WINNT >= &H0500

TYPE MOUSEKEYS
    cbSize          AS DWORD
    dwFlags         AS DWORD
    iMaxSpeed       AS DWORD
    iTimeToMaxSpeed AS DWORD
    iCtrlSpeed      AS DWORD
    dwReserved1     AS DWORD
    dwReserved2     AS DWORD
END TYPE

'
' MOUSEKEYS dwFlags field
'
%MKF_MOUSEKEYSON     = &H00000001
%MKF_AVAILABLE       = &H00000002
%MKF_HOTKEYACTIVE    = &H00000004
%MKF_CONFIRMHOTKEY   = &H00000008
%MKF_HOTKEYSOUND     = &H00000010
%MKF_INDICATOR       = &H00000020
%MKF_MODIFIERS       = &H00000040
%MKF_REPLACENUMBERS  = &H00000080
#IF (%WIN32_WINNT >= &H0500)
%MKF_LEFTBUTTONSEL   = &H10000000
%MKF_RIGHTBUTTONSEL  = &H20000000
%MKF_LEFTBUTTONDOWN  = &H01000000
%MKF_RIGHTBUTTONDOWN = &H02000000
%MKF_MOUSEMODE       = &H80000000???
#ENDIF ' %WIN32_WINNT >= &H0500

TYPE ACCESSTIMEOUT
    cbSize       AS DWORD
    dwFlags      AS DWORD
    iTimeOutMSec AS DWORD
END TYPE

'
' ACCESSTIMEOUT dwFlags field
'
%ATF_TIMEOUTON     = &H00000001
%ATF_ONOFFFEEDBACK = &H00000002

' values for SOUNDSENTRY iFSGrafEffect field
%SSGF_NONE     = 0
%SSGF_DISPLAY  = 3

' values for SOUNDSENTRY iFSTextEffect field
%SSTF_NONE     = 0
%SSTF_CHARS    = 1
%SSTF_BORDER   = 2
%SSTF_DISPLAY  = 3

' values for SOUNDSENTRY iWindowsEffect field
%SSWF_NONE    = 0
%SSWF_TITLE   = 1
%SSWF_WINDOW  = 2
%SSWF_DISPLAY = 3
%SSWF_CUSTOM  = 4

TYPE SOUNDSENTRYA
    cbSize                 AS DWORD
    dwFlags                AS DWORD
    iFSTextEffect          AS DWORD
    iFSTextEffectMSec      AS DWORD
    iFSTextEffectColorBits AS DWORD
    iFSGrafEffect          AS DWORD
    iFSGrafEffectMSec      AS DWORD
    iFSGrafEffectColor     AS DWORD
    iWindowsEffect         AS DWORD
    iWindowsEffectMSec     AS DWORD
    lpszWindowsEffectDLL   AS ASCIIZ PTR
    iWindowsEffectOrdinal  AS DWORD
END TYPE

TYPE SOUNDSENTRYW
    cbSize                 AS DWORD
    dwFlags                AS DWORD
    iFSTextEffect          AS DWORD
    iFSTextEffectMSec      AS DWORD
    iFSTextEffectColorBits AS DWORD
    iFSGrafEffect          AS DWORD
    iFSGrafEffectMSec      AS DWORD
    iFSGrafEffectColor     AS DWORD
    iWindowsEffect         AS DWORD
    iWindowsEffectMSec     AS DWORD
    lpszWindowsEffectDLL   AS WSTRINGZ PTR
    iWindowsEffectOrdinal  AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE SOUNDSENTRY_type
    SOUNDSENTRYW
END TYPE
#ELSE
TYPE SOUNDSENTRY_type
    SOUNDSENTRYA
END TYPE
#ENDIF ' UNICODE

'
' SOUNDSENTRY dwFlags field
'
%SSF_SOUNDSENTRYON = &H00000001
%SSF_AVAILABLE     = &H00000002
%SSF_INDICATOR     = &H00000004

#IF (%WIN32_WINNT >= &H0600)

DECLARE FUNCTION SoundSentry LIB "User32.dll" ALIAS "SoundSentry" () AS LONG

#ENDIF ' %WIN32_WINNT >= &H0600

TYPE TOGGLEKEYS
    cbSize  AS DWORD
    dwFlags AS DWORD
END TYPE

'
' TOGGLEKEYS dwFlags field
'
%TKF_TOGGLEKEYSON   = &H00000001
%TKF_AVAILABLE      = &H00000002
%TKF_HOTKEYACTIVE   = &H00000004
%TKF_CONFIRMHOTKEY  = &H00000008
%TKF_HOTKEYSOUND    = &H00000010
%TKF_INDICATOR      = &H00000020

#IF (%WIN32_WINNT >= &H0600)

TYPE AUDIODESCRIPTION
    cbSize  AS DWORD   ' sizeof(AudioDescriptionType)
    Enabled AS LONG    ' On/Off
    Locale  AS DWORD   ' locale ID for language
END TYPE

#ENDIF ' %WIN32_WINNT >= &H0600


'
' Set debug level
'

DECLARE SUB SetDebugErrorLevel LIB "User32.dll" ALIAS "SetDebugErrorLevel" _
    (BYVAL dwLevel AS DWORD)

'
' SetLastErrorEx() types.
'

%SLE_ERROR      = &H00000001
%SLE_MINORERROR = &H00000002
%SLE_WARNING    = &H00000003

DECLARE SUB SetLastErrorEx LIB "User32.dll" ALIAS "SetLastErrorEx" _
    (BYVAL dwErrCode AS DWORD, BYVAL dwType AS DWORD)

DECLARE FUNCTION InternalGetWindowText LIB "User32.dll" _
    ALIAS "InternalGetWindowText" (BYVAL hwnd AS DWORD, pString AS WSTRINGZ, _
    BYVAL cchMaxCount AS LONG) AS LONG


#IF %DEF(%WINNT)

DECLARE FUNCTION EndTask LIB "User32.dll" ALIAS "EndTask" _
    (BYVAL hwnd AS DWORD, BYVAL fShutDown AS LONG, BYVAL fForce AS LONG) _
    AS LONG

#ENDIF

DECLARE FUNCTION CancelShutdown LIB "User32.dll" ALIAS "CancelShutdown" () _
    AS LONG



#IF (%WINVER >= &H0500)

'
' Multimonitor API.
'

%MONITOR_DEFAULTTONULL     = &H00000000
%MONITOR_DEFAULTTOPRIMARY  = &H00000001
%MONITOR_DEFAULTTONEAREST  = &H00000002

DECLARE FUNCTION MonitorFromPoint LIB "User32.dll" ALIAS "MonitorFromPoint" _
    (BYVAL pt AS POINT, BYVAL dwFlags AS DWORD) AS DWORD

DECLARE FUNCTION MonitorFromRect LIB "User32.dll" ALIAS "MonitorFromRect" _
    (lprc AS RECT, BYVAL dwFlags AS DWORD) AS DWORD

DECLARE FUNCTION MonitorFromWindow LIB "User32.dll" ALIAS "MonitorFromWindow" _
    (BYVAL hwnd AS DWORD, BYVAL dwFlags AS DWORD) AS DWORD

%MONITORINFOF_PRIMARY      = &H00000001

#IF NOT %DEF(%CCHDEVICENAME)
%CCHDEVICENAME = 32
#ENDIF

TYPE MONITORINFO
    cbSize    AS DWORD
    rcMonitor AS RECT
    rcWork    AS RECT
    dwFlags   AS DWORD
END TYPE

TYPE MONITORINFOEXA
    MONITORINFO
    szDevice AS ASCIIZ * %CCHDEVICENAME
END TYPE

TYPE MONITORINFOEXW
    MONITORINFO
    szDevice AS WSTRINGZ * %CCHDEVICENAME
END TYPE

#IF %DEF(%UNICODE)
TYPE MONITORINFOEX
    MONITORINFOEXW
END TYPE
#ELSE
TYPE MONITORINFOEX
    MONITORINFOEXA
END TYPE
#ENDIF ' %UNICODE

DECLARE FUNCTION GetMonitorInfoA LIB "User32.dll" ALIAS "GetMonitorInfoA" _
    (BYVAL hMonitor AS DWORD, lpmi AS MONITORINFO) AS LONG

DECLARE FUNCTION GetMonitorInfoW LIB "User32.dll" ALIAS "GetMonitorInfoW" _
    (BYVAL hMonitor AS DWORD, lpmi AS MONITORINFO) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetMonitorInfo LIB "User32.dll" ALIAS "GetMonitorInfoW" _
    (BYVAL hMonitor AS DWORD, lpmi AS MONITORINFO) AS LONG
#ELSE
DECLARE FUNCTION GetMonitorInfo LIB "User32.dll" ALIAS "GetMonitorInfoA" _
    (BYVAL hMonitor AS DWORD, lpmi AS MONITORINFO) AS LONG
#ENDIF ' NOT %UNICODE

'typedef BOOL (CALLBACK* MONITORENUMPROC)(HMONITOR, HDC, LPRECT, LPARAM);

DECLARE FUNCTION EnumDisplayMonitors LIB "User32.dll" _
    ALIAS "EnumDisplayMonitors" (BYVAL hdc AS DWORD, lprcClip AS RECT, _
    BYVAL lpfnEnum AS DWORD, BYVAL dwData AS LONG) AS LONG


#IF NOT %DEF(%NOWINABLE)

'
' WinEvents - Active Accessibility hooks
'

DECLARE SUB NotifyWinEvent LIB "User32.dll" ALIAS "NotifyWinEvent" _
    (BYVAL dEvent AS DWORD, BYVAL hwnd AS DWORD, BYVAL idObject AS LONG, _
    BYVAL idChild AS LONG)

'typedef VOID (CALLBACK* WINEVENTPROC)(
'    HWINEVENTHOOK hWinEventHook,
'    DWORD         event,
'    DWORD          hwnd,
'    LONG          idObject,
'    LONG          idChild,
'    DWORD         idEventThread,
'    DWORD         dwmsEventTime);

DECLARE FUNCTION SetWinEventHook LIB "User32.dll" ALIAS "SetWinEventHook" _
    (BYVAL eventMin AS DWORD, BYVAL eventMax AS DWORD, _
    BYVAL hmodWinEventProc AS DWORD, BYVAL pfnWinEventProc AS DWORD, _
    BYVAL idProcess AS DWORD, BYVAL idThread AS DWORD, _
    BYVAL dwFlags AS DWORD) AS DWORD

#IF (%WIN32_WINNT >= &H0501)

DECLARE FUNCTION IsWinEventHookInstalled LIB "User32.dll" _
    ALIAS "IsWinEventHookInstalled" (BYVAL dEvent AS DWORD) AS LONG

#ENDIF ' %WIN32_WINNT >= &H0501

'
' dwFlags for SetWinEventHook
'
%WINEVENT_OUTOFCONTEXT   = &H0000  ' Events are ASYNC
%WINEVENT_SKIPOWNTHREAD  = &H0001  ' Don't call back for events on installer's thread
%WINEVENT_SKIPOWNPROCESS = &H0002  ' Don't call back for events on installer's process
%WINEVENT_INCONTEXT      = &H0004  ' Events are SYNC, this causes your dll to be injected into every process

DECLARE FUNCTION UnhookWinEvent LIB "User32.dll" ALIAS "UnhookWinEvent" _
    (BYVAL hWinEventHook AS DWORD) AS LONG

'
' idObject values for WinEventProc and NotifyWinEvent
'

'
' hwnd + idObject can be used with OLEACC.DLL's OleGetObjectFromWindow()
' to get an interface pointer to the container.  indexChild is the item
' within the container in question.  Setup a VARIANT with vt VT_I4 and
' lVal the indexChild and pass that in to all methods.  Then you
' are raring to go.
'


'
' Common object IDs (cookies, only for sending %WM_GETOBJECT to get at the
' thing in question).  Positive IDs are reserved for apps (app specific),
' negative IDs are system things and are global, 0 means "just little old
' me".
'
%CHILDID_SELF      = 0
%INDEXID_OBJECT    = 0
%INDEXID_CONTAINER = 0

'
' Reserved IDs for system objects
'
%OBJID_WINDOW        = &H00000000
%OBJID_SYSMENU       = &HFFFFFFFF???
%OBJID_TITLEBAR      = &HFFFFFFFE???
%OBJID_MENU          = &HFFFFFFFD???
%OBJID_CLIENT        = &HFFFFFFFC???
%OBJID_VSCROLL       = &HFFFFFFFB???
%OBJID_HSCROLL       = &HFFFFFFFA???
%OBJID_SIZEGRIP      = &HFFFFFFF9???
%OBJID_CARET         = &HFFFFFFF8???
%OBJID_CURSOR        = &HFFFFFFF7???
%OBJID_ALERT         = &HFFFFFFF6???
%OBJID_SOUND         = &HFFFFFFF5???
%OBJID_QUERYCLASSNAMEIDX = &HFFFFFFF4???
%OBJID_NATIVEOM      = &HFFFFFFF0???

'
' EVENT DEFINITION
'
%EVENT_MIN         = &H00000001
%EVENT_MAX         = &H7FFFFFFF


'
'  EVENT_SYSTEM_SOUND
'  Sent when a sound is played.  Currently nothing is generating this, we
'  this event when a system sound (for menus, etc) is played.  Apps
'  generate this, if accessible, when a private sound is played.  For
'  example, if Mail plays a "New Mail" sound.
'
'  System Sounds:
'  (Generated by PlaySoundEvent in USER itself)
'      hwnd            is NULL
'      idObject        is OBJID_SOUND
'      idChild         is sound child ID if one
'  App Sounds:
'  (PlaySoundEvent won't generate notification; up to app)
'      hwnd + idObject gets interface pointer to Sound object
'      idChild identifies the sound in question
'  are going to be cleaning up the SOUNDSENTRY feature in the control panel
'  and will use this at that time.  Applications implementing WinEvents
'  are perfectly welcome to use it.  Clients of IAccessible* will simply
'  turn around and get back a non-visual object that describes the sound.
'
%EVENT_SYSTEM_SOUND            = &H0001

'
' EVENT_SYSTEM_ALERT
' System Alerts:
' (Generated by MessageBox() calls for example)
'      hwnd            is hwndMessageBox
'      idObject        is OBJID_ALERT
' App Alerts:
' (Generated whenever)
'      hwnd+idObject gets interface pointer to Alert
'
%EVENT_SYSTEM_ALERT            = &H0002

'
' EVENT_SYSTEM_FOREGROUND
' Sent when the foreground (active) window changes, even if it is changing
' to another window in the same thread as the previous one.
'      hwnd            is hwndNewForeground
'      idObject        is OBJID_WINDOW
'      idChild    is INDEXID_OBJECT
'
%EVENT_SYSTEM_FOREGROUND       = &H0003

'
' Menu
'      hwnd            is window (top level window or popup menu window)
'      idObject        is ID of control (OBJID_MENU, OBJID_SYSMENU, OBJID_SELF for popup)
'      idChild         is CHILDID_SELF
'
' EVENT_SYSTEM_MENUSTART
' EVENT_SYSTEM_MENUEND
' For MENUSTART, hwnd+idObject+idChild refers to the control with the menu bar,
'  or the control bringing up the context menu.
'
' Sent when entering into and leaving from menu mode (system, app bar, and
' track popups).
'
%EVENT_SYSTEM_MENUSTART        = &H0004
%EVENT_SYSTEM_MENUEND          = &H0005

'
' EVENT_SYSTEM_MENUPOPUPSTART
' EVENT_SYSTEM_MENUPOPUPEND
' Sent when a menu popup comes up and just before it is taken down.  Note
' that for a call to TrackPopupMenu(), a client will see EVENT_SYSTEM_MENUSTART
' followed almost immediately by EVENT_SYSTEM_MENUPOPUPSTART for the popup
' being shown.
'
' For MENUPOPUP, hwnd+idObject+idChild refers to the NEW popup coming up, not the
' parent item which is hierarchical.  You can get the parent menu/popup by
' asking for the accParent object.
'
%EVENT_SYSTEM_MENUPOPUPSTART   = &H0006
%EVENT_SYSTEM_MENUPOPUPEND     = &H0007


'
' EVENT_SYSTEM_CAPTURESTART
' EVENT_SYSTEM_CAPTUREEND
' Sent when a window takes the capture and releases the capture.
'
%EVENT_SYSTEM_CAPTURESTART     = &H0008
%EVENT_SYSTEM_CAPTUREEND       = &H0009

'
' Move Size
' EVENT_SYSTEM_MOVESIZESTART
' EVENT_SYSTEM_MOVESIZEEND
' Sent when a window enters and leaves move-size dragging mode.
'
%EVENT_SYSTEM_MOVESIZESTART    = &H000A
%EVENT_SYSTEM_MOVESIZEEND      = &H000B

'
' Context Help
' EVENT_SYSTEM_CONTEXTHELPSTART
' EVENT_SYSTEM_CONTEXTHELPEND
' Sent when a window enters and leaves context sensitive help mode.
'
%EVENT_SYSTEM_CONTEXTHELPSTART = &H000C
%EVENT_SYSTEM_CONTEXTHELPEND   = &H000D

'
' Drag & Drop
' EVENT_SYSTEM_DRAGDROPSTART
' EVENT_SYSTEM_DRAGDROPEND
' Send the START notification just before going into drag&drop loop.  Send
' the END notification just after canceling out.
' Note that it is up to apps and OLE to generate this, since the system
' doesn't know.  Like EVENT_SYSTEM_SOUND, it will be a while before this
' is prevalent.
'
%EVENT_SYSTEM_DRAGDROPSTART    = &H000E
%EVENT_SYSTEM_DRAGDROPEND      = &H000F

'
' Dialog
' Send the START notification right after the dialog is completely
'  initialized and visible.  Send the END right before the dialog
'  is hidden and goes away.
' EVENT_SYSTEM_DIALOGSTART
' EVENT_SYSTEM_DIALOGEND
'
%EVENT_SYSTEM_DIALOGSTART      = &H0010
%EVENT_SYSTEM_DIALOGEND        = &H0011

'
' EVENT_SYSTEM_SCROLLING
' EVENT_SYSTEM_SCROLLINGSTART
' EVENT_SYSTEM_SCROLLINGEND
' Sent when beginning and ending the tracking of a scrollbar in a window,
' and also for scrollbar controls.
'
%EVENT_SYSTEM_SCROLLINGSTART   = &H0012
%EVENT_SYSTEM_SCROLLINGEND     = &H0013

'
' Alt-Tab Window
' Send the START notification right after the switch window is initialized
' and visible.  Send the END right before it is hidden and goes away.
' EVENT_SYSTEM_SWITCHSTART
' EVENT_SYSTEM_SWITCHEND
'
%EVENT_SYSTEM_SWITCHSTART      = &H0014
%EVENT_SYSTEM_SWITCHEND        = &H0015

'
' EVENT_SYSTEM_MINIMIZESTART
' EVENT_SYSTEM_MINIMIZEEND
' Sent when a window minimizes and just before it restores.
'
%EVENT_SYSTEM_MINIMIZESTART    = &H0016
%EVENT_SYSTEM_MINIMIZEEND      = &H0017


#IF (%WIN32_WINNT >= &H0600)
%EVENT_SYSTEM_DESKTOPSWITCH    = &H0020
#ENDIF ' %WIN32_WINNT >= &H0600

#IF (%WIN32_WINNT >= &H0601)
%EVENT_SYSTEM_END              = &H00FF

%EVENT_OEM_DEFINED_START       = &H0101
%EVENT_OEM_DEFINED_END         = &H01FF

%EVENT_UIA_EVENTID_START       = &H4E00
%EVENT_UIA_EVENTID_END         = &H4EFF

%EVENT_UIA_PROPID_START        = &H7500
%EVENT_UIA_PROPID_END          = &H75FF
#ENDIF ' %WIN32_WINNT >= &H0601

#IF (%WIN32_WINNT >= &H0501)
%EVENT_CONSOLE_CARET             = &H4001
%EVENT_CONSOLE_UPDATE_REGION     = &H4002
%EVENT_CONSOLE_UPDATE_SIMPLE     = &H4003
%EVENT_CONSOLE_UPDATE_SCROLL     = &H4004
%EVENT_CONSOLE_LAYOUT            = &H4005
%EVENT_CONSOLE_START_APPLICATION = &H4006
%EVENT_CONSOLE_END_APPLICATION   = &H4007

'
' Flags for EVENT_CONSOLE_START/END_APPLICATION.
'
#IF %DEF(%WIN64)
%CONSOLE_APPLICATION_16BIT     = &H0000
#ELSE
%CONSOLE_APPLICATION_16BIT     = &H0001
#ENDIF

'
' Flags for EVENT_CONSOLE_CARET
'
%CONSOLE_CARET_SELECTION       = &H0001
%CONSOLE_CARET_VISIBLE         = &H0002
#ENDIF ' %WIN32_WINNT >= &H0501

#IF (%WIN32_WINNT >= &H0601)
%EVENT_CONSOLE_END        = &H40FF
#ENDIF  ' %WIN32_WINNT >= &H0601

'
' Object events
'
' The system AND apps generate these.  The system generates these for
' real windows.  Apps generate these for objects within their window which
' act like a separate control, e.g. an item in a list view.
'
' When the system generate them, dwParam2 is always WMOBJID_SELF.  When
' apps generate them, apps put the has-meaning-to-the-app-only ID value
' in dwParam2.
' For all events, if you want detailed accessibility information, callers
' should
'     ' Call AccessibleObjectFromWindow() with the hwnd, idObject parameters
'          of the event, and IID_IAccessible as the REFIID, to get back an
'          IAccessible* to talk to
'     ' Initialize and fill in a VARIANT as VT_I4 with lVal the idChild
'          parameter of the event.
'     ' If idChild isn't zero, call get_accChild() in the container to see
'          if the child is an object in its own right.  If so, you will get
'          back an IDispatch* object for the child.  You should release the
'          parent, and call QueryInterface() on the child object to get its
'          IAccessible*.  Then you talk directly to the child.  Otherwise,
'          if get_accChild() returns you nothing, you should continue to
'          use the child VARIANT.  You will ask the container for the properties
'          of the child identified by the VARIANT.  In other words, the
'          child in this case is accessible but not a full-blown object.
'          Like a button on a titlebar which is 'small' and has no children.
'

'
' For all EVENT_OBJECT events,
'      hwnd is the dude to Send the %WM_GETOBJECT message to (unless %NULL,
'          see above for system things)
'      idObject is the ID of the object that can resolve any queries a
'          client might have.  It's a way to deal with windowless controls,
'          controls that are just drawn on the screen in some larger parent
'          window (like SDM), or standard frame elements of a window.
'      idChild is the piece inside of the object that is affected.  This
'          allows clients to access things that are too small to have full
'          blown objects in their own right.  Like the thumb of a scrollbar.
'          The hwnd/idObject pair gets you to the container, the dude you
'          probably want to talk to most of the time anyway.  The idChild
'          can then be passed into the acc properties to get the name/value
'          of it as needed.
'
' Example #1:
'      System propagating a listbox selection change
'      EVENT_OBJECT_SELECTION
'          hwnd == listbox hwnd
'          idObject == OBJID_WINDOW
'          idChild == new selected item, or CHILDID_SELF if
'              nothing now selected within container.
'      Word '97 propagating a listbox selection change
'          hwnd == SDM window
'          idObject == SDM ID to get at listbox 'control'
'          idChild == new selected item, or CHILDID_SELF if
'              nothing
'
' Example #2:
'      System propagating a menu item selection on the menu bar
'      EVENT_OBJECT_SELECTION
'          hwnd == top level window
'          idObject == OBJID_MENU
'          idChild == ID of child menu bar item selected
'
' Example #3:
'      System propagating a dropdown coming off of said menu bar item
'      EVENT_OBJECT_CREATE
'          hwnd == popup item
'          idObject == OBJID_WINDOW
'          idChild == CHILDID_SELF
'
' Example #4:
'
' For EVENT_OBJECT_REORDER, the object referred to by hwnd/idObject is the
' PARENT container in which the zorder is occurring.  This is because if
' one child is zordering, all of them are changing their relative zorder.
'
%EVENT_OBJECT_CREATE            = &H8000??  ' hwnd + ID + idChild is created item
%EVENT_OBJECT_DESTROY           = &H8001??  ' hwnd + ID + idChild is destroyed item
%EVENT_OBJECT_SHOW              = &H8002??  ' hwnd + ID + idChild is shown item
%EVENT_OBJECT_HIDE              = &H8003??  ' hwnd + ID + idChild is hidden item
%EVENT_OBJECT_REORDER           = &H8004??  ' hwnd + ID + idChild is parent of zordering children
'
' NOTE:
' Minimize the number of notifications!
'
' When you are hiding a parent object, obviously all child objects are no
' longer visible on screen.  They still have the same "visible" status,
' but are not truly visible.  Hence do not send HIDE notifications for the
' children also.  One implies all.  The same goes for SHOW.
'


%EVENT_OBJECT_FOCUS             = &H8005??  ' hwnd + ID + idChild is focused item
%EVENT_OBJECT_SELECTION         = &H8006??  ' hwnd + ID + idChild is selected item (if only one), or idChild is OBJID_WINDOW if complex
%EVENT_OBJECT_SELECTIONADD      = &H8007??  ' hwnd + ID + idChild is item added
%EVENT_OBJECT_SELECTIONREMOVE   = &H8008??  ' hwnd + ID + idChild is item removed
%EVENT_OBJECT_SELECTIONWITHIN   = &H8009??  ' hwnd + ID + idChild is parent of changed selected items

'
' NOTES:
' There is only one "focused" child item in a parent.  This is the place
' keystrokes are going at a given moment.  Hence only send a notification
' about where the NEW focus is going.  A NEW item getting the focus already
' implies that the OLD item is losing it.
'
' SELECTION however can be multiple.  Hence the different SELECTION
' notifications.  Here's when to use each:
'
' (1) Send a SELECTION notification in the simple single selection
'     case (like the focus) when the item with the selection is
'     merely moving to a different item within a container.  hwnd + ID
'     is the container control, idChildItem is the new child with the
'     selection.
'
' (2) Send a SELECTIONADD notification when a new item has simply been added
'     to the selection within a container.  This is appropriate when the
'     number of newly selected items is very small.  hwnd + ID is the
'     container control, idChildItem is the new child added to the selection.
'
' (3) Send a SELECTIONREMOVE notification when a new item has simply been
'     removed from the selection within a container.  This is appropriate
'     when the number of newly selected items is very small, just like
'     SELECTIONADD.  hwnd + ID is the container control, idChildItem is the
'     new child removed from the selection.
'
' (4) Send a SELECTIONWITHIN notification when the selected items within a
'     control have changed substantially.  Rather than propagate a large
'     number of changes to reflect removal for some items, addition of
'     others, just tell somebody who cares that a lot happened.  It will
'     be faster an easier for somebody watching to just turn around and
'     query the container control what the new bunch of selected items
'     are.
'

%EVENT_OBJECT_STATECHANGE       = &H800A??  ' hwnd + ID + idChild is item w/ state change
'
' Examples of when to send an EVENT_OBJECT_STATECHANGE include
'     ' It is being enabled/disabled (USER does for windows)
'     ' It is being pressed/released (USER does for buttons)
'     ' It is being checked/unchecked (USER does for radio/check buttons)
'
%EVENT_OBJECT_LOCATIONCHANGE    = &H800B??  ' hwnd + ID + idChild is moved/sized item

'
' Note:
' A LOCATIONCHANGE is not sent for every child object when the parent
' changes shape/moves.  Send one notification for the topmost object
' that is changing.  For example, if the user resizes a top level window,
' USER will generate a LOCATIONCHANGE for it, but not for the menu bar,
' title bar, scrollbars, etc.  that are also changing shape/moving.
'
' In other words, it only generates LOCATIONCHANGE notifications for
' real windows that are moving/sizing.  It will not generate a LOCATIONCHANGE
' for every non-floating child window when the parent moves (the children are
' logically moving also on screen, but not relative to the parent).
'
' Now, if the app itself resizes child windows as a result of being
' sized, USER will generate LOCATIONCHANGEs for those dudes also because
' it doesn't know better.
'
' Note also that USER will generate LOCATIONCHANGE notifications for two
' non-window sys objects:
'      (1) System caret
'      (2) Cursor
'

%EVENT_OBJECT_NAMECHANGE            = &H800C??  ' hwnd + ID + idChild is item w/ name change
%EVENT_OBJECT_DESCRIPTIONCHANGE     = &H800D??  ' hwnd + ID + idChild is item w/ desc change
%EVENT_OBJECT_VALUECHANGE           = &H800E??  ' hwnd + ID + idChild is item w/ value change
%EVENT_OBJECT_PARENTCHANGE          = &H800F??  ' hwnd + ID + idChild is item w/ new parent
%EVENT_OBJECT_HELPCHANGE            = &H8010??  ' hwnd + ID + idChild is item w/ help change
%EVENT_OBJECT_DEFACTIONCHANGE       = &H8011??  ' hwnd + ID + idChild is item w/ def action change
%EVENT_OBJECT_ACCELERATORCHANGE     = &H8012??  ' hwnd + ID + idChild is item w/ keybd accel change

#IF (%WIN32_WINNT >= &H0600)
%EVENT_OBJECT_INVOKED               = &H8013??  ' hwnd + ID + idChild is item invoked
%EVENT_OBJECT_TEXTSELECTIONCHANGED  = &H8014??  ' hwnd + ID + idChild is item w? test selection change

'
' EVENT_OBJECT_CONTENTSCROLLED
' Sent when ending the scrolling of a window object.
'
' Unlike the similar event (EVENT_SYSTEM_SCROLLEND), this event will be
' associated with the scrolling window itself. There is no difference
' between horizontal or vertical scrolling.
'
' This event should be posted whenever scroll action is completed, including
' when it is scrolled by scroll bars, mouse wheel, or keyboard navigations.
'
'   example:
'          hwnd == window that is scrolling
'          idObject == OBJID_CLIENT
'          idChild == CHILDID_SELF
'
%EVENT_OBJECT_CONTENTSCROLLED        = &H8015??
#ENDIF ' %WIN32_WINNT >= &H0600

#IF (%WIN32_WINNT >= &H0601)
%EVENT_SYSTEM_ARRANGMENTPREVIEW      = &H8016??
#ENDIF ' %WIN32_WINNT >= &H0601

#IF (%WIN32_WINNT >= &H0601)
%EVENT_OBJECT_END                    = &H80FF??

%EVENT_AIA_START                     = &HA000??
%EVENT_AIA_END                       = &HAFFF??
#ENDIF ' %WIN32_WINNT >= &H0601

'
' Child IDs
'

'
' System Sounds (idChild of system SOUND notification)
'
%SOUND_SYSTEM_STARTUP          = 1
%SOUND_SYSTEM_SHUTDOWN         = 2
%SOUND_SYSTEM_BEEP             = 3
%SOUND_SYSTEM_ERROR            = 4
%SOUND_SYSTEM_QUESTION         = 5
%SOUND_SYSTEM_WARNING          = 6
%SOUND_SYSTEM_INFORMATION      = 7
%SOUND_SYSTEM_MAXIMIZE         = 8
%SOUND_SYSTEM_MINIMIZE         = 9
%SOUND_SYSTEM_RESTOREUP        = 10
%SOUND_SYSTEM_RESTOREDOWN      = 11
%SOUND_SYSTEM_APPSTART         = 12
%SOUND_SYSTEM_FAULT            = 13
%SOUND_SYSTEM_APPEND           = 14
%SOUND_SYSTEM_MENUCOMMAND      = 15
%SOUND_SYSTEM_MENUPOPUP        = 16
%CSOUND_SYSTEM                 = 16

'
' System Alerts (indexChild of system ALERT notification)
'
%ALERT_SYSTEM_INFORMATIONAL    = 1       ' MB_INFORMATION
%ALERT_SYSTEM_WARNING          = 2       ' MB_WARNING
%ALERT_SYSTEM_ERROR            = 3       ' MB_ERROR
%ALERT_SYSTEM_QUERY            = 4       ' MB_QUESTION
%ALERT_SYSTEM_CRITICAL         = 5       ' HardSysErrBox
%CALERT_SYSTEM                 = 6

TYPE GUITHREADINFO
    cbSize        AS DWORD
    flags         AS DWORD
    hwndActive    AS DWORD
    hwndFocus     AS DWORD
    hwndCapture   AS DWORD
    hwndMenuOwner AS DWORD
    hwndMoveSize  AS DWORD
    hwndCaret     AS DWORD
    rcCaret       AS RECT
END TYPE

%GUI_CARETBLINKING  = &H00000001
%GUI_INMOVESIZE     = &H00000002
%GUI_INMENUMODE     = &H00000004
%GUI_SYSTEMMENUMODE = &H00000008
%GUI_POPUPMENUMODE  = &H00000010
#IF (%WIN32_WINNT >= &H0501)
#IF %DEF(%WIN64)
%GUI_16BITTASK      = &H00000000
#ELSE
%GUI_16BITTASK      = &H00000020
#ENDIF
#ENDIF ' %WIN32_WINNT >= &H0501

DECLARE FUNCTION GetGUIThreadInfo LIB "User32.dll" ALIAS "GetGUIThreadInfo" _
    (BYVAL idThread AS DWORD, pgui AS GUITHREADINFO) AS LONG

DECLARE FUNCTION BlockInput LIB "User32.dll" ALIAS "BlockInput" _
    (BYVAL fBlockIt AS LONG) AS LONG

#IF (%WIN32_WINNT >= &H0600)

%USER_DEFAULT_SCREEN_DPI = 96

DECLARE FUNCTION SetProcessDPIAware LIB "User32.dll" _
    ALIAS "SetProcessDPIAware" () AS LONG

DECLARE FUNCTION IsProcessDPIAware LIB "User32.dll" ALIAS "IsProcessDPIAware" _
    () AS LONG

#ENDIF ' %WIN32_WINNT >= &H0600

DECLARE FUNCTION GetWindowModuleFileNameA LIB "User32.dll" _
    ALIAS "GetWindowModuleFileNameA" (BYVAL hWnd AS DWORD, _
    lpFileName AS ASCIIZ, BYVAL nSize AS DWORD) AS DWORD

DECLARE FUNCTION GetWindowModuleFileNameW LIB "User32.dll" _
    ALIAS "GetWindowModuleFileNameW" (BYVAL hWnd AS DWORD, _
    lpFileName AS WSTRINGZ, BYVAL nSize AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetWindowModuleFileName LIB "User32.dll" _
    ALIAS "GetWindowModuleFileNameW" (BYVAL hWnd AS DWORD, _
    lpFileName AS WSTRINGZ, BYVAL nSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetWindowModuleFileName LIB "User32.dll" _
    ALIAS "GetWindowModuleFileNameA" (BYVAL hWnd AS DWORD, _
    lpFileName AS ASCIIZ, BYVAL nSize AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

#IF NOT %DEF(%NO_STATE_FLAGS)
%STATE_SYSTEM_UNAVAILABLE     = &H00000001  ' Disabled
%STATE_SYSTEM_SELECTED        = &H00000002
%STATE_SYSTEM_FOCUSED         = &H00000004
%STATE_SYSTEM_PRESSED         = &H00000008
%STATE_SYSTEM_CHECKED         = &H00000010
%STATE_SYSTEM_MIXED           = &H00000020  ' 3-state checkbox or toolbar button
%STATE_SYSTEM_INDETERMINATE   = %STATE_SYSTEM_MIXED
%STATE_SYSTEM_READONLY        = &H00000040
%STATE_SYSTEM_HOTTRACKED      = &H00000080
%STATE_SYSTEM_DEFAULT         = &H00000100
%STATE_SYSTEM_EXPANDED        = &H00000200
%STATE_SYSTEM_COLLAPSED       = &H00000400
%STATE_SYSTEM_BUSY            = &H00000800
%STATE_SYSTEM_FLOATING        = &H00001000  ' Children "owned" not "contained" by parent
%STATE_SYSTEM_MARQUEED        = &H00002000
%STATE_SYSTEM_ANIMATED        = &H00004000
%STATE_SYSTEM_INVISIBLE       = &H00008000
%STATE_SYSTEM_OFFSCREEN       = &H00010000
%STATE_SYSTEM_SIZEABLE        = &H00020000
%STATE_SYSTEM_MOVEABLE        = &H00040000
%STATE_SYSTEM_SELFVOICING     = &H00080000
%STATE_SYSTEM_FOCUSABLE       = &H00100000
%STATE_SYSTEM_SELECTABLE      = &H00200000
%STATE_SYSTEM_LINKED          = &H00400000
%STATE_SYSTEM_TRAVERSED       = &H00800000
%STATE_SYSTEM_MULTISELECTABLE = &H01000000  ' Supports multiple selection
%STATE_SYSTEM_EXTSELECTABLE   = &H02000000  ' Supports extended selection
%STATE_SYSTEM_ALERT_LOW       = &H04000000  ' This information is of low priority
%STATE_SYSTEM_ALERT_MEDIUM    = &H08000000  ' This information is of medium priority
%STATE_SYSTEM_ALERT_HIGH      = &H10000000  ' This information is of high priority
%STATE_SYSTEM_PROTECTED       = &H20000000  ' access to this is restricted
%STATE_SYSTEM_VALID           = &H3FFFFFFF
#ENDIF

%CCHILDREN_TITLEBAR           = 5
%CCHILDREN_SCROLLBAR          = 5

'
' Information about the global cursor.
'
TYPE CURSORINFO
    cbSize      AS DWORD
    flags       AS DWORD
    hCursor     AS DWORD
    ptScreenPos AS POINT
END TYPE

%CURSOR_SHOWING   = &H00000001

DECLARE FUNCTION GetCursorInfo LIB "User32.dll" ALIAS "GetCursorInfo" _
    (pci AS CURSORINFO) AS LONG

'
' Window information snapshot
'
TYPE WINDOWINFO
    cbSize          AS DWORD
    rcWindow        AS RECT
    rcClient        AS RECT
    dwStyle         AS DWORD
    dwExStyle       AS DWORD
    dwWindowStatus  AS DWORD
    cxWindowBorders AS DWORD
    cyWindowBorders AS DWORD
    atomWindowType  AS WORD
    wCreatorVersion AS WORD
END TYPE

%WS_ACTIVECAPTION  = &H0001

DECLARE FUNCTION GetWindowInfo LIB "User32.dll" ALIAS "GetWindowInfo" _
    (BYVAL hwnd AS DWORD, pwi AS WINDOWINFO) AS LONG

'
' Titlebar information.
'
TYPE TITLEBARINFO
    cbSize     AS DWORD
    rcTitleBar AS RECT
    rgstate(%CCHILDREN_TITLEBAR) AS DWORD
END TYPE

DECLARE FUNCTION GetTitleBarInfo LIB "User32.dll" ALIAS "GetTitleBarInfo" _
    (BYVAL hwnd AS DWORD, pti AS TITLEBARINFO) AS LONG

#IF (%WINVER >= &H0600)

TYPE TITLEBARINFOEX
    cbSize     AS DWORD
    rcTitleBar AS RECT
    rgstate(%CCHILDREN_TITLEBAR) AS DWORD
    rgrect(%CCHILDREN_TITLEBAR)  AS RECT
END TYPE

#ENDIF ' %WINVER >= &H0600

'
' Menubar information
'
TYPE MENUBARINFO
    cbSize      AS DWORD
    rcBar       AS RECT       ' rect of bar, popup, item
    hMenu       AS DWORD      ' real menu handle of bar, popup
    hwndMenu    AS DWORD      ' hwnd of item submenu if one
    fBarFocused AS BIT * 1 IN DWORD  ' bar, popup has the focus
    fFocused    AS BIT * 1   ' item has the focus
END TYPE

DECLARE FUNCTION GetMenuBarInfo LIB "User32.dll" ALIAS "GetMenuBarInfo" _
    (BYVAL hwnd AS DWORD, BYVAL idObject AS LONG, BYVAL idItem AS LONG, _
    pmbi AS MENUBARINFO) AS LONG

'
' Scrollbar information
'
TYPE SCROLLBARINFO
    cbSize        AS DWORD
    rcScrollBar   AS RECT
    dxyLineButton AS LONG
    xyThumbTop    AS LONG
    xyThumbBottom AS LONG
    reserved      AS LONG
    rgstate(%CCHILDREN_SCROLLBAR) AS DWORD
END TYPE

DECLARE FUNCTION GetScrollBarInfo LIB "User32.dll" ALIAS "GetScrollBarInfo" _
    (BYVAL hwnd AS DWORD, BYVAL idObject AS LONG, psbi AS SCROLLBARINFO) _
    AS LONG

'
' Combobox information
'
TYPE COMBOBOXINFO
    cbSize      AS DWORD
    rcItem      AS RECT
    rcButton    AS RECT
    stateButton AS DWORD
    hwndCombo   AS DWORD
    hwndItem    AS DWORD
    hwndList    AS DWORD
END TYPE

DECLARE FUNCTION GetComboBoxInfo LIB "User32.dll" ALIAS "GetComboBoxInfo" _
    (BYVAL hwndCombo AS DWORD, pbci AS COMBOBOXINFO) AS LONG

'
' The "real" ancestor window
'
%GA_PARENT     = 1
%GA_ROOT       = 2
%GA_ROOTOWNER  = 3

DECLARE FUNCTION GetAncestor LIB "User32.dll" ALIAS "GetAncestor" _
    (BYVAL hwnd AS DWORD, BYVAL gaFlags AS DWORD) AS DWORD


'
' This gets the REAL child window at the point.  If it is in the dead
' space of a group box, it will try a sibling behind it.  But static
' fields will get returned.  In other words, it is kind of a cross between
' ChildWindowFromPointEx and WindowFromPoint.
'
DECLARE FUNCTION RealChildWindowFromPoint LIB "User32.dll" _
    ALIAS "RealChildWindowFromPoint" (BYVAL hwndParent AS DWORD, _
    BYVAL pt AS POINT) AS DWORD

'
' This gets the name of the window TYPE, not class.  This allows us to
' recognize ThunderButton32 et al.
'
DECLARE FUNCTION RealGetWindowClassA LIB "User32.dll" _
    ALIAS "RealGetWindowClassA" (BYVAL hwnd AS DWORD, pszType AS ASCIIZ, _
    BYVAL cchType AS DWORD) AS DWORD

'
' This gets the name of the window TYPE, not class.  This allows us to
' recognize ThunderButton32 et al.
'
DECLARE FUNCTION RealGetWindowClassW LIB "User32.dll" _
    ALIAS "RealGetWindowClassW" (BYVAL hwnd AS DWORD, pszType AS WSTRINGZ, _
    BYVAL cchType AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION RealGetWindowClass LIB "User32.dll" _
    ALIAS "RealGetWindowClassW" (BYVAL hwnd AS DWORD, pszType AS WSTRINGZ, _
    BYVAL cchType AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION RealGetWindowClass LIB "User32.dll" _
    ALIAS "RealGetWindowClassA" (BYVAL hwnd AS DWORD, pszType AS ASCIIZ, _
    BYVAL cchType AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

'
' Alt-Tab Switch window information.
'
TYPE ALTTABINFO
    cbSize    AS DWORD
    cItems    AS LONG
    cColumns  AS LONG
    cRows     AS LONG
    iColFocus AS LONG
    iRowFocus AS LONG
    cxItem    AS LONG
    cyItem    AS LONG
    ptStart   AS POINT
END TYPE

DECLARE FUNCTION GetAltTabInfoA LIB "User32.dll" ALIAS "GetAltTabInfoA" _
    (BYVAL hwnd AS DWORD, BYVAL iItem AS LONG, pati AS ALTTABINFO, _
    pszItemText AS ASCIIZ, BYVAL cchItemText AS DWORD) AS LONG

DECLARE FUNCTION GetAltTabInfoW LIB "User32.dll" ALIAS "GetAltTabInfoW" _
    (BYVAL hwnd AS DWORD, BYVAL iItem AS LONG, pati AS ALTTABINFO, _
    pszItemText AS WSTRINGZ, BYVAL cchItemText AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetAltTabInfo LIB "User32.dll" ALIAS "GetAltTabInfoW" _
    (BYVAL hwnd AS DWORD, BYVAL iItem AS LONG, pati AS ALTTABINFO, _
    pszItemText AS WSTRINGZ, BYVAL cchItemText AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetAltTabInfo LIB "User32.dll" ALIAS "GetAltTabInfoA" _
    (BYVAL hwnd AS DWORD, BYVAL iItem AS LONG, pati AS ALTTABINFO, _
    pszItemText AS ASCIIZ, BYVAL cchItemText AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

'
' Listbox information.
' Returns the number of items per row.
'
DECLARE FUNCTION GetListBoxInfo LIB "User32.dll" ALIAS "GetListBoxInfo" _
    (BYVAL hwnd AS DWORD) AS DWORD

#ENDIF ' %NOWINABLE
#ENDIF ' %WINVER >= &H0500


#IF (%WIN32_WINNT >= &H0500)

DECLARE FUNCTION LockWorkStation LIB "User32.dll" ALIAS "LockWorkStation" () _
    AS LONG

#ENDIF ' %WIN32_WINNT >= &H0500

#IF (%WIN32_WINNT >= &H0500)

DECLARE FUNCTION UserHandleGrantAccess LIB "User32.dll" _
    ALIAS "UserHandleGrantAccess" (BYVAL hUserHandle AS DWORD, _
    BYVAL hJob AS DWORD, BYVAL bGrant AS LONG) AS LONG

#ENDIF ' %WIN32_WINNT >= &H0500

#IF (%WIN32_WINNT >= &H0501)

'
' Raw Input Messages.
'

'
' %WM_INPUT wParam
'

'
' Use this macro to get the input code from wParam.
'
MACRO GET_RAWINPUT_CODE_WPARAM(wParam)=LO(BYTE,wParam)

'
' The input is in the regular message flow,
' the app is required to call DefWindowProc
' so that the system can perform clean ups.
'
%RIM_INPUT     = 0

'
' The input is sink only. The app is expected
' to behave nicely.
'
%RIM_INPUTSINK = 1


'
' Raw Input data header
'
TYPE RAWINPUTHEADER
    dwType  AS DWORD
    dwSize  AS DWORD
    hDevice AS DWORD
    wParam  AS DWORD
END TYPE

'
' Type of the raw input
'
%RIM_TYPEMOUSE     = 0
%RIM_TYPEKEYBOARD  = 1
%RIM_TYPEHID       = 2

'
' Raw format of the mouse input
'
TYPE RAWMOUSE_type
    usButtonFlags AS WORD
    usButtonData  AS WORD
END TYPE

UNION RAWMOUSE_union
    ulButtons AS DWORD
    RAWMOUSE_type
END UNION

TYPE RAWMOUSE
    usFlags            AS WORD  ' indicator flags
    RAWMOUSE_union              ' the transition state of the mouse buttons
    ulRawButtons       AS DWORD ' the raw state of the mouse buttons
    lLastX             AS LONG  ' the signed relative or absolute motion in the X direction
    lLastY             AS LONG  ' the signed relative or absolute motion in the Y direction
    ulExtraInformation AS DWORD ' device-specific additional information for the event
END TYPE


'
' Define the mouse button state indicators.
'

%RI_MOUSE_LEFT_BUTTON_DOWN   = &H0001  ' Left Button changed to down.
%RI_MOUSE_LEFT_BUTTON_UP     = &H0002  ' Left Button changed to up.
%RI_MOUSE_RIGHT_BUTTON_DOWN  = &H0004  ' Right Button changed to down.
%RI_MOUSE_RIGHT_BUTTON_UP    = &H0008  ' Right Button changed to up.
%RI_MOUSE_MIDDLE_BUTTON_DOWN = &H0010  ' Middle Button changed to down.
%RI_MOUSE_MIDDLE_BUTTON_UP   = &H0020  ' Middle Button changed to up.

%RI_MOUSE_BUTTON_1_DOWN      = %RI_MOUSE_LEFT_BUTTON_DOWN
%RI_MOUSE_BUTTON_1_UP        = %RI_MOUSE_LEFT_BUTTON_UP
%RI_MOUSE_BUTTON_2_DOWN      = %RI_MOUSE_RIGHT_BUTTON_DOWN
%RI_MOUSE_BUTTON_2_UP        = %RI_MOUSE_RIGHT_BUTTON_UP
%RI_MOUSE_BUTTON_3_DOWN      = %RI_MOUSE_MIDDLE_BUTTON_DOWN
%RI_MOUSE_BUTTON_3_UP        = %RI_MOUSE_MIDDLE_BUTTON_UP

%RI_MOUSE_BUTTON_4_DOWN      = &H0040
%RI_MOUSE_BUTTON_4_UP        = &H0080
%RI_MOUSE_BUTTON_5_DOWN      = &H0100
%RI_MOUSE_BUTTON_5_UP        = &H0200

'
' If usButtonFlags has RI_MOUSE_WHEEL, the wheel delta is stored in usButtonData.
' Take it as a signed value.
'
%RI_MOUSE_WHEEL              = &H0400

'
' Define the mouse indicator flags.
'
%MOUSE_MOVE_RELATIVE      = 0
%MOUSE_MOVE_ABSOLUTE      = 1
%MOUSE_VIRTUAL_DESKTOP    = &H02  ' the coordinates are mapped to the virtual desktop
%MOUSE_ATTRIBUTES_CHANGED = &H04  ' requery for mouse attributes
#IF (%WINVER >= &H0600)
%MOUSE_MOVE_NOCOALESCE    = &H08  ' do not coalesce mouse moves
#ENDIF ' %WINVER >= &H0600

'
' Raw format of the keyboard input
'
TYPE RAWKEYBOARD
    MakeCode AS WORD   ' the "make" scan code (key depression)
    Flags    AS WORD   ' the flags field indicates a "break" (key release) and other
    Reserved AS WORD   ' miscellaneous scan code information defined in ntddkbd.h
    VKey     AS WORD   ' Windows message compatible information
    Message  AS DWORD
    ExtraInformation AS DWORD ' device-specific additional information for the event
END TYPE


'
' Define the keyboard overrun MakeCode.
'

%KEYBOARD_OVERRUN_MAKE_CODE  = &HFF?

'
' Define the keyboard input data Flags.
'
%RI_KEY_MAKE            = 0
%RI_KEY_BREAK           = 1
%RI_KEY_E0              = 2
%RI_KEY_E1              = 4
%RI_KEY_TERMSRV_SET_LED = 8
%RI_KEY_TERMSRV_SHADOW  = &H10


'
' Raw format of the input from Human Input Devices
'
TYPE RAWHID
    dwSizeHid   AS DWORD    ' byte size of each report
    dwCount     AS DWORD    ' number of input packed
    bRawData(0) AS BYTE
END TYPE

'
' RAWINPUT data structure.
'
UNION RAWINPUT_union
    rmouse    AS RAWMOUSE
    rkeyboard AS RAWKEYBOARD
    rhid      AS RAWHID
END UNION

TYPE RAWINPUT
    HEADER AS RAWINPUTHEADER
    RAWINPUT_union
END TYPE

#IF %DEF(%WIN64)
' 8 = SIZEOF(QWORD)
MACRO RAWINPUT_ALIGN(x)=(((x)+8-1) AND NOT (8-1))
#ELSE   ' %WIN64
' 4 = SIZEOF(DWORD)
MACRO RAWINPUT_ALIGN(x)=(((x)+4-1) AND NOT (4-1))
#ENDIF  ' %WIN64

'MACRO NEXTRAWINPUTBLOCK(ptr)=((PRAWINPUT)RAWINPUT_ALIGN((ULONG_PTR)((PBYTE)(ptr) + (ptr)->header.dwSize)))

'
' Flags for GetRawInputData
'

%RID_INPUT             = &H10000003
%RID_HEADER            = &H10000005

DECLARE FUNCTION GetRawInputData LIB "User32.dll" ALIAS "GetRawInputData" _
    (BYVAL hRawInput AS DWORD, BYVAL uiCommand AS DWORD, _
    BYVAL pData AS DWORD, pcbSize AS DWORD, BYVAL cbSizeHeader AS DWORD) _
    AS DWORD

'
' Raw Input Device Information
'
%RIDI_PREPARSEDDATA    = &H20000005
%RIDI_DEVICENAME       = &H20000007  ' the return valus is the character length, not the byte size
%RIDI_DEVICEINFO       = &H2000000b

TYPE RID_DEVICE_INFO_MOUSE
    dwId              AS DWORD
    dwNumberOfButtons AS DWORD
    dwSampleRate      AS DWORD
END TYPE

TYPE RID_DEVICE_INFO_KEYBOARD
    dwType                 AS DWORD
    dwSubType              AS DWORD
    dwKeyboardMode         AS DWORD
    dwNumberOfFunctionKeys AS DWORD
    dwNumberOfIndicators   AS DWORD
    dwNumberOfKeysTotal    AS DWORD
END TYPE

TYPE RID_DEVICE_INFO_HID
    dwVendorId      AS DWORD
    dwProductId     AS DWORD
    dwVersionNumber AS DWORD
    ' Top level collection UsagePage and Usage
    usUsagePage     AS WORD
    usUsage         AS WORD
END TYPE

UNION RID_DEVICE_INFO_UNION
    rmouse    AS RID_DEVICE_INFO_MOUSE
    rkeyboard AS RID_DEVICE_INFO_KEYBOARD
    rhid      AS RID_DEVICE_INFO_HID
END UNION

TYPE RID_DEVICE_INFO
    cbSize AS DWORD
    dwType AS DWORD
    RID_DEVICE_INFO_UNION
END TYPE

DECLARE FUNCTION GetRawInputDeviceInfoA LIB "User32.dll" _
    ALIAS "GetRawInputDeviceInfoA" (BYVAL hDevice AS DWORD, _
    BYVAL uiCommand AS DWORD, BYVAL pData AS DWORD, pcbSize AS DWORD) AS DWORD

DECLARE FUNCTION GetRawInputDeviceInfoW LIB "User32.dll" _
    ALIAS "GetRawInputDeviceInfoW" (BYVAL hDevice AS DWORD, _
    BYVAL uiCommand AS DWORD, BYVAL pData AS DWORD, pcbSize AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetRawInputDeviceInfo LIB "User32.dll" _
    ALIAS "GetRawInputDeviceInfoW" (BYVAL hDevice AS DWORD, _
    BYVAL uiCommand AS DWORD, BYVAL pData AS DWORD, pcbSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetRawInputDeviceInfo LIB "User32.dll" _
    ALIAS "GetRawInputDeviceInfoA" (BYVAL hDevice AS DWORD, _
    BYVAL uiCommand AS DWORD, BYVAL pData AS DWORD, pcbSize AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE


'
' Raw Input Bulk Read: GetRawInputBuffer
'
DECLARE FUNCTION GetRawInputBuffer LIB "User32.dll" ALIAS "GetRawInputBuffer" _
    (pData AS RAWINPUT, pcbSize AS DWORD, BYVAL cbSizeHeader AS DWORD) AS DWORD

'
' Raw Input request APIs
'
TYPE RAWINPUTDEVICE
    usUsagePage AS WORD   ' Toplevel collection UsagePage
    usUsage     AS WORD   ' Toplevel collection Usage
    dwFlags     AS DWORD
    hwndTarget  AS DWORD  ' Target hwnd. %NULL = follows keyboard focus
END TYPE


%RIDEV_REMOVE           = &H00000001
%RIDEV_EXCLUDE          = &H00000010
%RIDEV_PAGEONLY         = &H00000020
%RIDEV_NOLEGACY         = &H00000030
%RIDEV_INPUTSINK        = &H00000100
%RIDEV_CAPTUREMOUSE     = &H00000200  ' effective when mouse nolegacy is specified, otherwise it would be an error
%RIDEV_NOHOTKEYS        = &H00000200  ' effective for keyboard.
%RIDEV_APPKEYS          = &H00000400  ' effective for keyboard.
#IF (%WIN32_WINNT >= &H0501)
%RIDEV_EXINPUTSINK      = &H00001000
%RIDEV_DEVNOTIFY        = &H00002000
#ENDIF ' %WIN32_WINNT >= &H0501
%RIDEV_EXMODEMASK       = &H000000F0

MACRO RIDEV_EXMODE(xMODE)=((xMODE) AND %RIDEV_EXMODEMASK)

#IF (%WIN32_WINNT >= &H0501)
'
' Flags for the %WM_INPUT_DEVICE_CHANGE message.
'
%GIDC_ARRIVAL           = 1
%GIDC_REMOVAL           = 2
#ENDIF ' %WIN32_WINNT >= &H0501

#IF (%WIN32_WINNT >= &H0601)
MACRO GET_DEVICE_CHANGE_WPARAM(wParam)=LO(WORD,wParam)
#ELSEIF (%WIN32_WINNT >= &H0501)
MACRO GET_DEVICE_CHANGE_LPARAM(lParam)=LO(WORD,lParam)
#ENDIF

DECLARE FUNCTION RegisterRawInputDevices LIB "User32.dll" _
    ALIAS "RegisterRawInputDevices" _
    (BYVAL pRawInputDevices AS RAWINPUTDEVICE PTR, _
    BYVAL uiNumDevices AS DWORD, BYVAL cbSize AS DWORD) AS LONG

DECLARE FUNCTION GetRegisteredRawInputDevices LIB "User32.dll" _
    ALIAS "GetRegisteredRawInputDevices" _
    (BYVAL pRawInputDevices AS RAWINPUTDEVICE PTR, puiNumDevices AS DWORD, _
    BYVAL cbSize AS DWORD) AS DWORD


TYPE RAWINPUTDEVICELIST
    hDevice AS DWORD
    dwType  AS DWORD
END TYPE

DECLARE FUNCTION GetRawInputDeviceList LIB "User32.dll" _
    ALIAS "GetRawInputDeviceList" _
    (BYVAL pRawInputDeviceList AS RAWINPUTDEVICELIST PTR, _
    puiNumDevices AS DWORD, _
    BYVAL cbSize AS DWORD) AS DWORD

DECLARE FUNCTION DefRawInputProc LIB "User32.dll" ALIAS "DefRawInputProc" _
    (BYVAL paRawInput AS RAWINPUT PTR, BYVAL nInput AS LONG, _
    BYVAL cbSizeHeader AS DWORD) AS LONG

#ENDIF ' %WIN32_WINNT >= &H0501


#IF (%WINVER >= &H0600)

'
' Message Filter
'

%MSGFLT_ADD    = 1
%MSGFLT_REMOVE = 2

DECLARE FUNCTION ChangeWindowMessageFilter LIB "User32.dll" _
    ALIAS "ChangeWindowMessageFilter" (BYVAL message AS DWORD, _
    BYVAL dwFlag AS DWORD) AS LONG

#ENDIF ' %WINVER >= &H0600

#IF (%WINVER >= &H0601)

'
' Message filter info values (CHANGEFILTERSTRUCT.ExtStatus)
'
%MSGFLTINFO_NONE                       = (0)
%MSGFLTINFO_ALREADYALLOWED_FORWND      = (1)
%MSGFLTINFO_ALREADYDISALLOWED_FORWND   = (2)
%MSGFLTINFO_ALLOWED_HIGHER             = (3)

TYPE CHANGEFILTERSTRUCT
    cbSize    AS DWORD
    ExtStatus AS DWORD
END TYPE

'
' Message filter action values (action parameter to ChangeWindowMessageFilterEx)
'
%MSGFLT_RESET                          = (0)
%MSGFLT_ALLOW                          = (1)
%MSGFLT_DISALLOW                       = (2)

DECLARE FUNCTION ChangeWindowMessageFilterEx LIB "User32.dll" _
    ALIAS "ChangeWindowMessageFilterEx" ( _
    BYVAL hwnd          AS DWORD, _                  ' Window
    BYVAL message       AS DWORD, _                  ' %WM_ message
    BYVAL action        AS DWORD, _                  ' Message filter action value
    pChangeFilterStruct AS CHANGEFILTERSTRUCT) _     ' Optional
    AS LONG

#ENDIF ' %WINVER >= &H0601


#IF (%WINVER >= &H0601)

'
' Gesture defines and functions
'

'
' Gesture information handle
'
'DECLARE_HANDLE(HGESTUREINFO);


'
' Gesture flags - GESTUREINFO.dwFlags
'
%GF_BEGIN           = &H00000001
%GF_INERTIA         = &H00000002
%GF_END             = &H00000004

'
' Gesture IDs
'
%GID_BEGIN          = 1
%GID_END            = 2
%GID_ZOOM           = 3
%GID_PAN            = 4
%GID_ROTATE         = 5
%GID_TWOFINGERTAP   = 6
%GID_PRESSANDTAP    = 7
%GID_ROLLOVER       = %GID_PRESSANDTAP

'
' Gesture information structure
'   - Pass the HGESTUREINFO received in the %WM_GESTURE message lParam into the
'     GetGestureInfo function to retrieve this information.
'   - If cbExtraArgs is non-zero, pass the HGESTUREINFO received in the %WM_GESTURE
'     message lParam into the GetGestureExtraArgs function to retrieve extended
'     argument information.
'
TYPE GESTUREINFO
    cbSize       AS DWORD   ' size, in bytes, of this structure (including variable length Args field)
    dwFlags      AS DWORD   ' see GF_* flags
    dwID         AS DWORD   ' gesture ID, see GID_* defines
    hwndTarget   AS DWORD   ' handle to window targeted by this gesture
    ptsLocation  AS POINTS  ' current location of this gesture
    dwInstanceID AS DWORD   ' internally used
    dwSequenceID AS DWORD   ' internally used
    ullArguments AS QUAD    ' arguments for gestures whose arguments fit in 8 BYTES
    cbExtraArgs  AS DWORD   ' size, in bytes, of extra arguments, if any, that accompany this gesture
END TYPE


'
' Gesture notification structure
'   - The %WM_GESTURENOTIFY message lParam contains a pointer to this structure.
'   - The %WM_GESTURENOTIFY message notifies a window that gesture recognition is
'     in progress and a gesture will be generated if one is recognized under the
'     current gesture settings.
'
TYPE GESTURENOTIFYSTRUCT
    cbSize       AS DWORD   ' SIZE, IN bytes, OF this structure
    dwFlags      AS DWORD   ' unused
    hwndTarget   AS DWORD   ' HANDLE TO WINDOW targeted by the gesture
    ptsLocation  AS POINTS  ' starting location
    dwInstanceID AS DWORD   ' internally used
END TYPE

'
' Gesture argument helpers
'   - Angle should be a double in the range of -2pi to +2pi
'   - Argument should be an unsigned 16-bit value
'
MACRO GID_ROTATE_ANGLE_TO_ARGUMENT(arg)=(((((arg) + 2 * 3.14159265) / (4 * 3.14159265)) * 65535) AND &H0000FFFF)
MACRO GID_ROTATE_ANGLE_FROM_ARGUMENT(arg)=((((arg) / 65535) * 4 * 3.14159265) - 2 * 3.14159265)

'
' Gesture information retrieval
'   - HGESTUREINFO is received by a window in the lParam of a %WM_GESTURE message.
'
DECLARE FUNCTION GetGestureInfo LIB "User32.dll" ALIAS "GetGestureInfo" (_
    BYVAL hGestureInfo AS DWORD, _   ' HGESTUREINFO
    pGestureInfo AS GESTUREINFO) _
    AS LONG   ' BOOL

'
' Gesture extra arguments retrieval
'   - HGESTUREINFO is received by a window in the lParam of a %WM_GESTURE message.
'   - Size, in bytes, of the extra argument data is available in the cbExtraArgs
'     field of the GESTUREINFO structure retrieved using the GetGestureInfo function.
'
DECLARE FUNCTION GetGestureExtraArgs LIB "User32.dll" _
    ALIAS "GetGestureExtraArgs" ( _
    BYVAL hGestureInfo AS DWORD, _   ' HGESTUREINFO
    BYVAL cbExtraArgs AS DWORD, _    ' UINT
    BYVAL pExtraArgs AS BYTE PTR) _
    AS LONG   ' BOOL

'
' Gesture information handle management
'   - If an application processes the %WM_GESTURE message, then once it is done
'     with the associated HGESTUREINFO, the application is responsible for
'     closing the handle using this function. Failure to do so may result in
'     process memory leaks.
'   - If the message is instead passed to DefWindowProc, or is forwarded using
'     one of the PostMessage or SendMessage class of API functions, the handle
'     is transfered with the message and need not be closed by the application.
'
DECLARE FUNCTION CloseGestureInfoHandle LIB "User32.dll" _
    ALIAS "CloseGestureInfoHandle" ( _
    BYVAL hGestureInfo AS DWORD) _   ' HGESTUREINFO
    AS LONG   ' BOOL

'
' Gesture configuration structure
'   - Used in SetGestureConfig and GetGestureConfig
'   - Note that any setting not included in either GESTURECONFIG.dwWant or
'     GESTURECONFIG.dwBlock will use the parent window's preferences or
'     system defaults.
'
TYPE GESTURECONFIG
    dwID    AS DWORD   ' gesture ID
    dwWant  AS DWORD   ' settings related to gesture ID that are to be turned ON
    dwBlock AS DWORD   ' settings related to gesture ID that are to be turned OFF
END TYPE

'
' Gesture configuration flags - GESTURECONFIG.dwWant or GESTURECONFIG.dwBlock
'

'
' Common gesture configuration flags - set GESTURECONFIG.dwID to zero
'
%GC_ALLGESTURES                            = &H00000001

'
' Zoom gesture configuration flags - set GESTURECONFIG.dwID to GID_ZOOM
'
%GC_ZOOM                                   = &H00000001

'
' Pan gesture configuration flags - set GESTURECONFIG.dwID to GID_PAN
'
%GC_PAN                                    = &H00000001
%GC_PAN_WITH_SINGLE_FINGER_VERTICALLY      = &H00000002
%GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY    = &H00000004
%GC_PAN_WITH_GUTTER                        = &H00000008
%GC_PAN_WITH_INERTIA                       = &H00000010

'
' Rotate gesture configuration flags - set GESTURECONFIG.dwID to GID_ROTATE
'
%GC_ROTATE                                 = &H00000001

'
' Two finger tap gesture configuration flags - set GESTURECONFIG.dwID to GID_TWOFINGERTAP
'
%GC_TWOFINGERTAP                           = &H00000001

'
' PressAndTap gesture configuration flags - set GESTURECONFIG.dwID to GID_PRESSANDTAP
'
%GC_PRESSANDTAP                            = &H00000001
%GC_ROLLOVER                               = %GC_PRESSANDTAP

%GESTURECONFIGMAXCOUNT         = 256       ' Maximum number of gestures that can be included
                                           ' in a single call TO SetGestureConfig / GetGestureConfig

DECLARE FUNCTION SetGestureConfig LIB "User32.dll" ALIAS "SetGestureConfig" ( _
    BYVAL hwnd           AS DWORD, _              ' window for which configuration is specified
    BYVAL dwReserved     AS DWORD, _              ' reserved, must be 0
    BYVAL cIDs           AS DWORD, _              ' count of GESTURECONFIG structures
    BYVAL pGestureConfig AS GESTURECONFIG PTR, _  ' array of GESTURECONFIG structures, dwIDs will be processed in the
    _                                             ' order specified and repeated occurances will overwrite previous ones
    BYVAL cbSize         AS DWORD) _              ' sizeof(GESTURECONFIG)
    AS LONG   ' BOOL

%GCF_INCLUDE_ANCESTORS         = &H00000001      ' IF specified, GetGestureConfig returns consolidated configuration
                                                        ' FOR the specified WINDOW AND it's parent window chain

DECLARE FUNCTION GetGestureConfig LIB "User32.dll" ALIAS "GetGestureConfig" ( _
    BYVAL hwnd           AS DWORD, _              ' window for which configuration is required
    BYVAL dwReserved     AS DWORD, _              ' reserved, must be 0
    BYVAL dwFlags        AS DWORD, _              ' see GCF_* flags
    BYVAL pcIDs          AS DWORD PTR, _          ' *pcIDs contains the size, in number of GESTURECONFIG structures,
    _                                             ' of the buffer pointed to by pGestureConfig
    BYVAL pGestureConfig AS GESTURECONFIG PTR, _
    _                                             ' pointer to buffer to receive the returned array of GESTURECONFIG structures
    BYVAL cbSize         AS DWORD) _              ' sizeof(GESTURECONFIG)
    AS LONG   ' BOOL


#ENDIF ' %WINVER >= &H0601

#IF (%WINVER >= &H0601)

'
' GetSystemMetrics(SM_DIGITIZER) flag values
'
%NID_INTEGRATED_TOUCH = &H00000001
%NID_EXTERNAL_TOUCH   = &H00000002
%NID_INTEGRATED_PEN   = &H00000004
%NID_EXTERNAL_PEN     = &H00000008
%NID_MULTI_INPUT      = &H00000040
%NID_READY            = &H00000080

#ENDIF ' %WINVER >= &H0601


%MAX_STR_BLOCKREASON = 256

DECLARE FUNCTION ShutdownBlockReasonCreate LIB "User32.dll" _
    ALIAS "ShutdownBlockReasonCreate" (BYVAL hwnd AS DWORD, _
    pwszReason AS WSTRINGZ) AS LONG

DECLARE FUNCTION ShutdownBlockReasonQuery LIB "User32.dll" _
    ALIAS "ShutdownBlockReasonQuery" (BYVAL hwnd AS DWORD, _
    pwszBuff AS WSTRINGZ, pcchBuff AS DWORD) AS LONG

DECLARE FUNCTION ShutdownBlockReasonDestroy LIB "User32.dll" _
    ALIAS "ShutdownBlockReasonDestroy" (BYVAL hwnd AS DWORD) AS LONG



'#IF %DEF(%ISOLATION_AWARE_ENABLED) AND (%ISOLATION_AWARE_ENABLED <> 0)
'#INCLUDE "winuser.inl.inc"
'#ENDIF
