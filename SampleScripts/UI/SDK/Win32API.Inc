DECLARE FUNCTION GetModuleHandleW       LIB "Kernel32.dll" ALIAS "GetModuleHandleW"     (byval lpModuleName AS WStringz) AS DWORD
DECLARE FUNCTION GetLastError           LIB "Kernel32.dll" ALIAS "GetLastError"         () AS LONG
DECLARE FUNCTION GetProcAddress         LIB "Kernel32.dll" ALIAS "GetProcAddress"       (BYVAL hModule AS DWORD, lpProcName AS ASCIIZ) AS LONG
DECLARE FUNCTION FreeLibrary            LIB "Kernel32.dll" ALIAS "FreeLibrary"          (BYVAL hLibModule AS DWORD) AS LONG
DECLARE FUNCTION LoadLibraryA           LIB "Kernel32.dll" ALIAS "LoadLibraryA"         (lpLibFileName AS Stringz) AS DWORD
DECLARE FUNCTION LoadLibraryW           LIB "Kernel32.dll" ALIAS "LoadLibraryW"         (lpLibFileName AS WStringZ) AS DWORD


DECLARE FUNCTION BeginPaint             LIB "User32.dll" ALIAS "BeginPaint"             (BYVAL hWnd AS DWORD, lpPaint AS PAINTSTRUCT) AS DWORD
DECLARE FUNCTION CallWindowProcA        LIB "User32.dll" ALIAS "CallWindowProcA"        (BYVAL lpPrevWndFunc AS DWORD, BYVAL hWnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG
DECLARE FUNCTION CallWindowProcW        LIB "User32.dll" ALIAS "CallWindowProcW"        (BYVAL lpPrevWndFunc AS DWORD, BYVAL hWnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG
DECLARE FUNCTION CreateWindowExA        LIB "User32.dll" ALIAS "CreateWindowExA"        (
                                                                                          BYVAL dwExStyle AS DWORD,
                                                                                          byval lpClassName AS ASCIIZ, 
                                                                                          byval lpWindowName AS ASCIIZ, 
                                                                                          BYVAL dwStyle AS DWORD, 
                                                                                          BYVAL x AS LONG, 
                                                                                          BYVAL y AS LONG, 
                                                                                          BYVAL nWidth AS LONG, 
                                                                                          BYVAL nHeight AS LONG, 
                                                                                          BYVAL hWndParent AS DWORD, 
                                                                                          BYVAL hMenu AS DWORD, 
                                                                                          BYVAL hInstance AS DWORD, 
                                                                                          lpParam AS ANY) AS DWORD

DECLARE FUNCTION CreateWindowExW        LIB "USER32.DLL" ALIAS "CreateWindowExW"        (
                                                                                          BYVAL dwExStyle AS DWORD, 
                                                                                          byval lpClassName AS wSTRINGz, 
                                                                                          byval lpWindowName AS wSTRINGz, 
                                                                                          BYVAL dwStyle AS DWORD, 
                                                                                          BYVAL X AS LONG, 
                                                                                          BYVAL Y AS LONG, 
                                                                                          BYVAL nWidth AS LONG, 
                                                                                          BYVAL nHeight AS LONG, 
                                                                                          BYVAL hwndParent AS DWORD, 
                                                                                          BYVAL hMenu AS DWORD, 
                                                                                          BYVAL hInstance AS DWORD, 
                                                                                          lpParam AS ANY) AS DWORD
DECLARE FUNCTION SetDlgItemTextW        LIB "USER32.DLL" ALIAS "SetDlgItemTextW"        (
                                                                                          BYVAL hDlg AS DWORD, 
                                                                                          BYVAL nIDDlgItem AS LONG, 
                                                                                          byref lpString AS wSTRINGz) AS LONG

DECLARE FUNCTION DispatchMessageA       LIB "User32.dll" ALIAS "DispatchMessageA"       (byref lpMsg AS tagMsg) AS LONG
DECLARE FUNCTION DefWindowProcA         LIB "User32.dll" ALIAS "DefWindowProcA"         (BYVAL hWnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG
DECLARE FUNCTION DestroyMenu            LIB "User32.dll" ALIAS "DestroyMenu"            (BYVAL hMenu AS DWORD) AS LONG
DECLARE FUNCTION EndPaint               LIB "User32.dll" ALIAS "EndPaint"               (BYVAL hWnd AS DWORD, lpPaint AS PAINTSTRUCT) AS LONG
DECLARE FUNCTION GetMessageA            LIB "User32.dll" ALIAS "GetMessageA"            (byref lpMsg AS tagMsg, BYVAL hWnd AS DWORD, BYVAL uMsgFilterMin AS DWORD, BYVAL uMsgFilterMax AS DWORD) AS LONG
DECLARE FUNCTION GetParent              LIB "User32.dll" ALIAS "GetParent"              (BYVAL hWnd AS DWORD) AS DWORD
DECLARE FUNCTION GetSystemMetrics       LIB "User32.dll" ALIAS "GetSystemMetrics"       (BYVAL nIndex AS LONG) AS LONG
DECLARE FUNCTION GetWindowRect          LIB "User32.dll" ALIAS "GetWindowRect"          (BYVAL hWnd AS DWORD, lpRect AS RECT) AS LONG
DECLARE FUNCTION LoadCursorA            LIB "User32.dll" ALIAS "LoadCursorA"            (BYVAL hInstance AS DWORD, lpCursorName AS ASCIIZ) AS DWORD
DECLARE FUNCTION LoadIconA              LIB "User32.dll" ALIAS "LoadIconA"              (BYVAL hInstance AS DWORD, lpIconName AS ASCIIZ) AS DWORD
DECLARE FUNCTION LoadImageA             LIB "User32.dll" ALIAS "LoadImageA"             (
                                                                                          BYVAL hInst AS DWORD, 
                                                                                          lpszName AS ASCIIZ, 
                                                                                          BYVAL uType AS DWORD,
                                                                                          BYVAL cxDesired AS LONG, 
                                                                                          BYVAL cyDesired AS LONG, 
                                                                                          BYVAL fuLoad AS DWORD) AS DWORD
DECLARE FUNCTION MessageBoxW            LIB "User32.dll" ALIAS "MessageBoxW"            (
                                                                                          BYVAL hWnd      AS DWORD  ,
                                                                                          byval lpText    AS WStringZ,
                                                                                          byval lpCaption AS WStringZ,
                                                                                          BYVAL dwType    AS DWORD
                                                                                        ) AS LONG

DECLARE FUNCTION MessageBoxA            LIB "User32.dll" ALIAS "MessageBoxA"            (
                                                                                          BYVAL hWnd      AS DWORD ,
                                                                                          byval lpText    AS Stringz,
                                                                                          byval lpCaption AS stringz,
                                                                                          BYVAL dwType    AS DWORD
                                                                                        ) AS LONG

DECLARE FUNCTION ModifyMenuA            LIB "User32.dll" ALIAS "ModifyMenuA"            (
                                                                                          BYVAL hMenu AS DWORD, 
                                                                                          BYVAL dwPosition AS DWORD, 
                                                                                          BYVAL dwFlags AS DWORD, 
                                                                                          BYVAL dwIDNewItem AS DWORD, 
                                                                                          lpString AS ASCIIZ) AS LONG
DECLARE SUB      PostQuitMessage        LIB "User32.dll" ALIAS "PostQuitMessage"        (BYVAL nExitCode AS LONG)
DECLARE FUNCTION RegisterClassExA       LIB "User32.dll" ALIAS "RegisterClassExA"       (byref pcWndClassEx AS WNDCLASSEX) AS WORD
DECLARE FUNCTION SetParent              LIB "User32.dll" ALIAS "SetParent"              (BYVAL hWndChild AS DWORD, OPTIONAL BYVAL hWndNewParent AS DWORD) AS DWORD
DECLARE FUNCTION SetWindowLongA         LIB "User32.dll" ALIAS "SetWindowLongA"         (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG, BYVAL lNewLong AS LONG) AS LONG
DECLARE FUNCTION SetWindowLongW         LIB "User32.dll" ALIAS "SetWindowLongW"         (BYVAL hWnd AS DWORD, BYVAL nIndex AS LONG, BYVAL lNewLong AS LONG) AS LONG
DECLARE FUNCTION SetWindowPos           LIB "User32.dll" ALIAS "SetWindowPos"           (
                                                                                          BYVAL hWnd AS DWORD, BYVAL hWndInsertAfter AS DWORD, BYVAL x AS LONG, _
                                                                                          BYVAL y AS LONG, BYVAL cx AS LONG, BYVAL cy AS LONG, _
                                                                                          BYVAL wFlags AS DWORD) AS LONG
DECLARE FUNCTION ShowWindow             LIB "User32.dll" ALIAS "ShowWindow"             (BYVAL hWnd AS DWORD, BYVAL nCmdShow AS LONG) AS LONG
DECLARE FUNCTION TranslateAcceleratorA  LIB "User32.dll" ALIAS "TranslateAcceleratorA"  (BYVAL hWnd AS DWORD, BYVAL hAccTable AS DWORD, lpMsg AS tagMsg) AS LONG
DECLARE FUNCTION TranslateMessage       LIB "User32.dll" ALIAS "TranslateMessage"       (byref lpMsg AS tagMsg) AS LONG
DECLARE FUNCTION UpdateWindow           LIB "User32.dll" ALIAS "UpdateWindow"           (BYVAL hWnd AS DWORD) AS LONG
DECLARE FUNCTION VkKeyScanA             LIB "User32.dll" ALIAS "VkKeyScanA"             (BYVAL cChar AS BYTE) AS INTEGER


TYPE INIT_COMMON_CONTROLSEX
    dwSize AS DWORD   ' size of this structure
    dwICC  AS DWORD   ' flags indicating which classes to be initialized
END TYPE

TYPE SYSTEMTIME
    wYear         AS WORD
    wMonth        AS WORD
    wDayOfWeek    AS WORD
    wDay          AS WORD
    wHour         AS WORD
    wMinute       AS WORD
    wSecond       AS WORD
    wMilliseconds AS WORD
END TYPE

TYPE NMDATETIMECHANGE
    hdr     AS NMHDR
    dwFlags AS DWORD        ' GDT_VALID or GDT_NONE
    st      AS SYSTEMTIME   ' valid iff dwFlags==GDT_VALID
END TYPE

%ICC_LISTVIEW_CLASSES   = &H00000001 ' listview, header
%ICC_TREEVIEW_CLASSES   = &H00000002 ' treeview, tooltips
%ICC_BAR_CLASSES        = &H00000004 ' toolbar, statusbar, trackbar, tooltips
%ICC_TAB_CLASSES        = &H00000008 ' tab, tooltips
%ICC_UPDOWN_CLASS       = &H00000010 ' updown
%ICC_PROGRESS_CLASS     = &H00000020 ' progress
%ICC_HOTKEY_CLASS       = &H00000040 ' hotkey
%ICC_ANIMATE_CLASS      = &H00000080 ' animate
%ICC_WIN95_CLASSES      = &H000000FF
%ICC_DATE_CLASSES       = &H00000100 ' month picker, date picker, time picker, updown
%ICC_USEREX_CLASSES     = &H00000200 ' comboex
%ICC_COOL_CLASSES       = &H00000400 ' rebar (coolbar) control
'#IF %WIN32_IE >= &H0400
%ICC_INTERNET_CLASSES   = &H00000800
%ICC_PAGESCROLLER_CLASS = &H00001000 ' page scroller
%ICC_NATIVEFNTCTL_CLASS = &H00002000 ' native font control
'#ENDIF  ' #IF %WIN32_IE >= &H0400
'#IF %WIN32_WINNT >= &H0501
%ICC_STANDARD_CLASSES   = &H00004000
%ICC_LINK_CLASS         = &H00008000
'#ENDIF  ' #IF %WIN32_WINNT >= &H0501

'DECLARE FUNCTION zInitCommonControlsEx (iccex AS INIT_COMMON_CONTROLSEX) AS LONG
'
''------------------------------------------------------------------------------
'' Safely initialize the Common Control Library, and return the version number
'' of the DLL as a CURRENCYX/CUX data type, e.g., 4.71.
''------------------------------------------------------------------------------
'FUNCTION InitComCtl32A (OPTIONAL BYVAL iccClasses AS DWORD) AS single
'
'    LOCAL hLib   AS DWORD
'    LOCAL dwProc AS DWORD
'    LOCAL iccex  AS INIT_COMMON_CONTROLSEX
'
'    ' Use dynamic (run-time) linking to initialize the common control library
'    ' unless only a very old version is installed. Implicit (load-time) linking
'    ' should be avoided, since this will stop the application from starting up
'    ' if the "InitCommonControlsEx" API is not available in ComCtl32.dll
'    ' (as might be true of early Windows 95 releases)
'
'    hLib = LoadLibraryA("ComCtl32.dll")
'    IF hLib THEN
'        dwProc = GetProcAddress(hLib, "InitCommonControlsEx")
'        IF dwProc THEN
'            iccex.dwSize = SIZEOF(iccex)
'            iccex.dwICC = IIF(iccClasses, iccClasses, %ICC_WIN95_CLASSES)
'            CALLDWORD dwProc USING zInitCommonControlsEx(iccex)
'        ELSE
'            InitCommonControls
'        END IF
'
'        FreeLibrary hLib
'
'        FUNCTION = GetSysFileVerA("ComCtl32.dll")
'    END IF
'
'END FUNCTION
'
''------------------------------------------------------------------------------
'' Safely initialize the Common Control Library, and return the version number
'' of the DLL as a CURRENCYX/CUX data type, e.g., 4.71.
''------------------------------------------------------------------------------
'FUNCTION InitComCtl32W (OPTIONAL BYVAL iccClasses AS DWORD) AS Single
'
'    LOCAL hLib   AS DWORD
'    LOCAL dwProc AS DWORD
'    LOCAL iccex  AS INIT_COMMON_CONTROLSEX
'
'    ' Use dynamic (run-time) linking to initialize the common control library
'    ' unless only a very old version is installed. Implicit (load-time) linking
'    ' should be avoided, since this will stop the application from starting up
'    ' if the "InitCommonControlsEx" API is not available in ComCtl32.dll
'    ' (as might be true of early Windows 95 releases)
'
'    hLib = LoadLibraryW("ComCtl32.dll")
'    IF hLib THEN
'        ' note: GetProcAddress always uses ANSI strings
'        dwProc = GetProcAddress(hLib, "InitCommonControlsEx")
'        IF dwProc THEN
'            iccex.dwSize = SIZEOF(iccex)
'            iccex.dwICC = IIF(iccClasses, iccClasses, %ICC_WIN95_CLASSES)
'            CALLDWORD dwProc USING zInitCommonControlsEx(iccex)
'        ELSE
'            InitCommonControls
'        END IF
'
'        FreeLibrary hLib
'
'        FUNCTION = GetSysFileVerW("ComCtl32.dll")
'    END IF
'
'END FUNCTION
' 