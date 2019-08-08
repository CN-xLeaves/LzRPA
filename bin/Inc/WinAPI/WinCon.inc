'------------------------------------------------------------------------------
'
'  WinCon.inc
'    This module contains the public data structures, data types,
'    and procedures exported by the NT console subsystem.
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from WinCon.h build version 0002 of 18 Jan 2008
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WINCON = 1

#INCLUDE "WTypes.inc"
#INCLUDE "WinGDI.inc"

TYPE COORD
    x AS INTEGER
    y AS INTEGER
END TYPE

' [legacy support]
TYPE SMALL_RECT1
    xLeft   AS INTEGER
    xTop    AS INTEGER
    xRight  AS INTEGER
    xBottom AS INTEGER
END TYPE

TYPE SMALL_RECT2
    nLeft   AS INTEGER
    nTop    AS INTEGER
    nRight  AS INTEGER
    nBottom AS INTEGER
END TYPE

TYPE SMALL_RECT3
    Left   AS INTEGER
    Top    AS INTEGER
    Right  AS INTEGER
    Bottom AS INTEGER
END TYPE

UNION SMALL_RECT
    SMALL_RECT1
    SMALL_RECT2
    SMALL_RECT3
END UNION

UNION EITHERCHAR
    UnicodeChar AS WSTRING * 1
    AsciiChar   AS STRING * 1
END UNION

TYPE KEY_EVENT_RECORD
    bKeyDown          AS LONG
    wRepeatCount      AS WORD
    wVirtualKeyCode   AS WORD
    wVirtualScanCode  AS WORD
    EITHERCHAR
    dwControlKeyState AS DWORD
END TYPE

'
' ControlKeyState flags
'

%RIGHT_ALT_PRESSED   = &H0001 ' the right alt key is pressed.
%LEFT_ALT_PRESSED    = &H0002 ' the left alt key is pressed.
%RIGHT_CTRL_PRESSED  = &H0004 ' the right ctrl key is pressed.
%LEFT_CTRL_PRESSED   = &H0008 ' the left ctrl key is pressed.
%SHIFT_PRESSED       = &H0010 ' the shift key is pressed.
%NUMLOCK_ON          = &H0020 ' the numlock light is on.
%SCROLLLOCK_ON       = &H0040 ' the scrolllock light is on.
%CAPSLOCK_ON         = &H0080 ' the capslock light is on.
%ENHANCED_KEY        = &H0100 ' the key is enhanced.
%NLS_DBCSCHAR        = &H00010000 ' DBCS for JPN: SBCS/DBCS mode.
%NLS_ALPHANUMERIC    = &H00000000 ' DBCS for JPN: Alphanumeric mode.
%NLS_KATAKANA        = &H00020000 ' DBCS for JPN: Katakana mode.
%NLS_HIRAGANA        = &H00040000 ' DBCS for JPN: Hiragana mode.
%NLS_ROMAN           = &H00400000 ' DBCS for JPN: Roman/Noroman mode.
%NLS_IME_CONVERSION  = &H00800000 ' DBCS for JPN: IME conversion.
%NLS_IME_DISABLE     = &H20000000 ' DBCS for JPN: IME enable/disable.

TYPE MOUSE_EVENT_RECORD
    dwMousePosition   AS COORD
    dwButtonState     AS DWORD
    dwControlKeyState AS DWORD
    dwEventFlags      AS DWORD
END TYPE

'
' ButtonState flags
'

%FROM_LEFT_1ST_BUTTON_PRESSED  = &H0001
%RIGHTMOST_BUTTON_PRESSED      = &H0002
%FROM_LEFT_2ND_BUTTON_PRESSED  = &H0004
%FROM_LEFT_3RD_BUTTON_PRESSED  = &H0008
%FROM_LEFT_4TH_BUTTON_PRESSED  = &H0010

'
' EventFlags
'

%MOUSE_MOVED   = &H0001
%DOUBLE_CLICK  = &H0002
%MOUSE_WHEELED = &H0004
#IF (%WIN32_WINNT >= &H0600)
%MOUSE_HWHEELED = &H0008
#ENDIF ' %WIN32_WINNT >= &H0600

TYPE WINDOW_BUFFER_SIZE_RECORD
    dwSize AS COORD
END TYPE

TYPE MENU_EVENT_RECORD
    dwCommandId AS DWORD
END TYPE

TYPE FOCUS_EVENT_RECORD
    bSetFocus AS LONG
END TYPE

UNION INPUT_RECORD_Event
    KeyEvent   AS KEY_EVENT_RECORD
    MouseEvent AS MOUSE_EVENT_RECORD
    WindowBufferSizeEvent AS WINDOW_BUFFER_SIZE_RECORD
    MenuEvent  AS MENU_EVENT_RECORD
    FocusEvent AS FOCUS_EVENT_RECORD
END UNION

TYPE INPUT_RECORD DWORD
    EventType AS WORD
    INPUT_RECORD_Event
END TYPE

'
'  EventType flags:
'

%KEY_EVENT         = &H0001 ' Event contains key event record
%MOUSE_EVENT       = &H0002 ' Event contains mouse event record
%WINDOW_BUFFER_SIZE_EVENT = &H0004 ' Event contains window change event record
%MENU_EVENT = &H0008 ' Event contains menu event record
%FOCUS_EVENT = &H0010 ' event contains focus change

TYPE CHAR_INFO
    EITHERCHAR
    Attributes AS WORD
END TYPE

'
' Attributes flags:
'

%FOREGROUND_BLUE      = &H0001 ' text color contains blue.
%FOREGROUND_GREEN     = &H0002 ' text color contains green.
%FOREGROUND_RED       = &H0004 ' text color contains red.
%FOREGROUND_INTENSITY = &H0008 ' text color is intensified.
%BACKGROUND_BLUE      = &H0010 ' background color contains blue.
%BACKGROUND_GREEN     = &H0020 ' background color contains green.
%BACKGROUND_RED       = &H0040 ' background color contains red.
%BACKGROUND_INTENSITY = &H0080 ' background color is intensified.
%COMMON_LVB_LEADING_BYTE    = &H0100 ' Leading Byte of DBCS
%COMMON_LVB_TRAILING_BYTE   = &H0200 ' Trailing Byte of DBCS
%COMMON_LVB_GRID_HORIZONTAL = &H0400 ' DBCS: Grid attribute: top horizontal.
%COMMON_LVB_GRID_LVERTICAL  = &H0800 ' DBCS: Grid attribute: left vertical.
%COMMON_LVB_GRID_RVERTICAL  = &H1000 ' DBCS: Grid attribute: right vertical.
%COMMON_LVB_REVERSE_VIDEO   = &H4000 ' DBCS: Reverse fore/back ground attribute.
%COMMON_LVB_UNDERSCORE      = &H8000?? ' DBCS: Underscore.

%COMMON_LVB_SBCSDBCS        = &H0300 ' SBCS or DBCS flag.

TYPE CONSOLE_SCREEN_BUFFER_INFO
    dwSize              AS COORD
    dwCursorPosition    AS COORD
    wAttributes         AS WORD
    srWindow            AS SMALL_RECT
    dwMaximumWindowSize AS COORD
END TYPE

TYPE CONSOLE_SCREEN_BUFFER_INFOEX
    cbSize               AS DWORD
    dwSize               AS COORD
    dwCursorPosition     AS COORD
    wAttributes          AS WORD
    srWindow             AS SMALL_RECT
    dwMaximumWindowSize  AS COORD
    wPopupAttributes     AS WORD
    bFullscreenSupported AS LONG
    ColorTable(15)       AS DWORD
END TYPE

TYPE CONSOLE_CURSOR_INFO
    dwSize   AS DWORD
    bVisible AS LONG
END TYPE

TYPE CONSOLE_FONT_INFO
    nFont      AS DWORD
    dwFontSize AS COORD
END TYPE

#IF NOT %DEF(%NOGDI)
TYPE CONSOLE_FONT_INFOEX
    cbSize     AS DWORD
    nFont      AS DWORD
    dwFontSize AS COORD
    FontFamily AS DWORD
    FontWeight AS DWORD
    FaceName   AS WSTRINGZ * %LF_FACESIZE
END TYPE
#ENDIF

%HISTORY_NO_DUP_FLAG = &H1

TYPE CONSOLE_HISTORY_INFO
    cbSize                 AS DWORD
    HistoryBufferSize      AS DWORD
    NumberOfHistoryBuffers AS DWORD
    dwFlags                AS DWORD
END TYPE

#IF (%WIN32_WINNT >= &H0500)
TYPE CONSOLE_SELECTION_INFO
    dwFlags           AS DWORD
    dwSelectionAnchor AS COORD
    srSelection       AS SMALL_RECT
END TYPE

'
' Selection flags
'

%CONSOLE_NO_SELECTION           = &H0000
%CONSOLE_SELECTION_IN_PROGRESS  = &H0001   ' selection has begun
%CONSOLE_SELECTION_NOT_EMPTY    = &H0002   ' non-null select rectangle
%CONSOLE_MOUSE_SELECTION        = &H0004   ' selecting with mouse
%CONSOLE_MOUSE_DOWN             = &H0008   ' mouse is down
#ENDIF ' %WIN32_WINNT >= &H0500

'
' typedef for ctrl-c handler routines
'

DECLARE FUNCTION CtrlCHandler (BYVAL CtrlType AS DWORD) AS LONG

%CTRL_C_EVENT        = 0
%CTRL_BREAK_EVENT    = 1
%CTRL_CLOSE_EVENT    = 2
' 3 is reserved!
' 4 is reserved!
%CTRL_LOGOFF_EVENT   = 5
%CTRL_SHUTDOWN_EVENT = 6

'
'  Input Mode flags:
'

%ENABLE_PROCESSED_INPUT  = &H0001
%ENABLE_LINE_INPUT       = &H0002
%ENABLE_ECHO_INPUT       = &H0004
%ENABLE_WINDOW_INPUT     = &H0008
%ENABLE_MOUSE_INPUT      = &H0010
%ENABLE_INSERT_MODE      = &H0020
%ENABLE_QUICK_EDIT_MODE  = &H0040
%ENABLE_EXTENDED_FLAGS   = &H0080
%ENABLE_AUTO_POSITION    = &H0100

'
' Output Mode flags:
'

%ENABLE_PROCESSED_OUTPUT    = &H0001
%ENABLE_WRAP_AT_EOL_OUTPUT  = &H0002

'
' direct API definitions.
'

DECLARE FUNCTION PeekConsoleInputA LIB "KERNEL32.DLL" _
    ALIAS "PeekConsoleInputA" (BYVAL hConsoleInput AS DWORD, _
    BYVAL lpBuffer AS INPUT_RECORD PTR, BYVAL nLength AS DWORD, _
    lpNumberOfEventsWritten AS DWORD) AS LONG

DECLARE FUNCTION PeekConsoleInputW LIB "KERNEL32.DLL" _
    ALIAS "PeekConsoleInputW" (BYVAL hConsoleInput AS DWORD, _
    BYVAL lpBuffer AS INPUT_RECORD PTR, BYVAL nLength AS DWORD, _
    lpNumberOfEventsWritten AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION PeekConsoleInput LIB "KERNEL32.DLL" _
    ALIAS "PeekConsoleInputW" (BYVAL hConsoleInput AS DWORD, _
    BYVAL lpBuffer AS INPUT_RECORD PTR, BYVAL nLength AS DWORD, _
    lpNumberOfEventsWritten AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION PeekConsoleInput LIB "KERNEL32.DLL" _
    ALIAS "PeekConsoleInputA" (BYVAL hConsoleInput AS DWORD, _
    BYVAL lpBuffer AS INPUT_RECORD PTR, BYVAL nLength AS DWORD, _
    lpNumberOfEventsWritten AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION ReadConsoleInputA LIB "KERNEL32.DLL" _
    ALIAS "ReadConsoleInputA" (BYVAL hConsoleInput AS DWORD, _
    BYVAL lpBuffer AS INPUT_RECORD PTR, BYVAL nNumberOfCharsToRead AS LONG, _
    lpNumberOfCharsRead AS LONG) AS LONG

DECLARE FUNCTION ReadConsoleInputW LIB "KERNEL32.DLL" _
    ALIAS "ReadConsoleInputW" (BYVAL hConsoleInput AS DWORD, _
    BYVAL lpBuffer AS INPUT_RECORD PTR, BYVAL nNumberOfCharsToRead AS LONG, _
    lpNumberOfCharsRead AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ReadConsoleInput LIB "KERNEL32.DLL" _
    ALIAS "ReadConsoleInputW" (BYVAL hConsoleInput AS DWORD, _
    BYVAL lpBuffer AS INPUT_RECORD PTR, BYVAL nNumberOfCharsToRead AS LONG, _
    lpNumberOfCharsRead AS LONG) AS LONG
#ELSE
DECLARE FUNCTION ReadConsoleInput LIB "KERNEL32.DLL" _
    ALIAS "ReadConsoleInputA" (BYVAL hConsoleInput AS DWORD, _
    BYVAL lpBuffer AS INPUT_RECORD PTR, BYVAL nNumberOfCharsToRead AS LONG, _
    lpNumberOfCharsRead AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION WriteConsoleInputA LIB "KERNEL32.DLL" _
    ALIAS "WriteConsoleInputA" (BYVAL hConsoleInput AS DWORD, _
    BYVAL lpBuffer AS INPUT_RECORD PTR, BYVAL nLength AS DWORD, _
    lpNumberOfEventsWritten AS DWORD) AS LONG

DECLARE FUNCTION WriteConsoleInputW LIB "KERNEL32.DLL" _
    ALIAS "WriteConsoleInputW" (BYVAL hConsoleInput AS DWORD, _
    BYVAL lpBuffer AS INPUT_RECORD PTR, BYVAL nLength AS DWORD, _
    lpNumberOfEventsWritten AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION WriteConsoleInput LIB "KERNEL32.DLL" _
    ALIAS "WriteConsoleInputW" (BYVAL hConsoleInput AS DWORD, _
    BYVAL lpBuffer AS INPUT_RECORD PTR, BYVAL nLength AS DWORD, _
    lpNumberOfEventsWritten AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION WriteConsoleInput LIB "KERNEL32.DLL" _
    ALIAS "WriteConsoleInputA" (BYVAL hConsoleInput AS DWORD, _
    BYVAL lpBuffer AS INPUT_RECORD PTR, BYVAL nLength AS DWORD, _
    lpNumberOfEventsWritten AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION ReadConsoleOutputA LIB "KERNEL32.DLL" _
    ALIAS "ReadConsoleOutputA" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL lpBuffer AS CHAR_INFO PTR, BYVAL dwBufferSize AS DWORD, _
    BYVAL dwBufferCoord AS DWORD, lpReadRegion AS SMALL_RECT) AS LONG

DECLARE FUNCTION ReadConsoleOutputW LIB "KERNEL32.DLL" _
    ALIAS "ReadConsoleOutputW" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL lpBuffer AS CHAR_INFO PTR, BYVAL dwBufferSize AS DWORD, _
    BYVAL dwBufferCoord AS DWORD, lpReadRegion AS SMALL_RECT) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ReadConsoleOutput LIB "KERNEL32.DLL" _
    ALIAS "ReadConsoleOutputW" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL lpBuffer AS CHAR_INFO PTR, BYVAL dwBufferSize AS DWORD, _
    BYVAL dwBufferCoord AS DWORD, lpReadRegion AS SMALL_RECT) AS LONG
#ELSE
DECLARE FUNCTION ReadConsoleOutput LIB "KERNEL32.DLL" _
    ALIAS "ReadConsoleOutputA" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL lpBuffer AS CHAR_INFO PTR, BYVAL dwBufferSize AS DWORD, _
    BYVAL dwBufferCoord AS DWORD, lpReadRegion AS SMALL_RECT) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION WriteConsoleOutputA LIB "KERNEL32.DLL" _
    ALIAS "WriteConsoleOutputA" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL lpBuffer AS CHAR_INFO PTR, BYVAL dwBufferSize AS DWORD, _
    BYVAL dwBufferCoord AS DWORD, lpWriteRegion AS SMALL_RECT) AS LONG

DECLARE FUNCTION WriteConsoleOutputW LIB "KERNEL32.DLL" _
    ALIAS "WriteConsoleOutputW" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL lpBuffer AS CHAR_INFO PTR, BYVAL dwBufferSize AS DWORD, _
    BYVAL dwBufferCoord AS DWORD, lpWriteRegion AS SMALL_RECT) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION WriteConsoleOutput LIB "KERNEL32.DLL" _
    ALIAS "WriteConsoleOutputW" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL lpBuffer AS CHAR_INFO PTR, BYVAL dwBufferSize AS DWORD, _
    BYVAL dwBufferCoord AS DWORD, lpWriteRegion AS SMALL_RECT) AS LONG
#ELSE
DECLARE FUNCTION WriteConsoleOutput LIB "KERNEL32.DLL" _
    ALIAS "WriteConsoleOutputA" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL lpBuffer AS CHAR_INFO PTR, BYVAL dwBufferSize AS DWORD, _
    BYVAL dwBufferCoord AS DWORD, lpWriteRegion AS SMALL_RECT) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION ReadConsoleOutputCharacterA LIB "KERNEL32.DLL" _
    ALIAS "ReadConsoleOutputCharacterA" (BYVAL hConsoleOutput AS DWORD, _
    szCharacter AS ASCIIZ, BYVAL nLength AS DWORD, _
    BYVAL dwReadCoord AS DWORD, lpNumberOfCharsRead AS DWORD) AS LONG

DECLARE FUNCTION ReadConsoleOutputCharacterW LIB "KERNEL32.DLL" _
    ALIAS "ReadConsoleOutputCharacterW" (BYVAL hConsoleOutput AS DWORD, _
    szCharacter AS WSTRINGZ, BYVAL nLength AS DWORD, _
    BYVAL dwReadCoord AS DWORD, lpNumberOfCharsRead AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ReadConsoleOutputCharacter LIB "KERNEL32.DLL" _
    ALIAS "ReadConsoleOutputCharacterW" (BYVAL hConsoleOutput AS DWORD, _
    szCharacter AS WSTRINGZ, BYVAL nLength AS DWORD, _
    BYVAL dwReadCoord AS DWORD, lpNumberOfCharsRead AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION ReadConsoleOutputCharacter LIB "KERNEL32.DLL" _
    ALIAS "ReadConsoleOutputCharacterA" (BYVAL hConsoleOutput AS DWORD, _
    szCharacter AS ASCIIZ, BYVAL nLength AS DWORD, _
    BYVAL dwReadCoord AS DWORD, lpNumberOfCharsRead AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION ReadConsoleOutputAttribute LIB "KERNEL32.DLL" _
    ALIAS "ReadConsoleOutputAttribute" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL lpAttribute AS WORD PTR, BYVAL nLength AS DWORD, _
    BYVAL dwReadCoord AS DWORD, lpNumberOfAttrsRead AS DWORD) AS LONG

DECLARE FUNCTION WriteConsoleOutputCharacterA LIB "KERNEL32.DLL" _
    ALIAS "WriteConsoleOutputCharacterA" (BYVAL hConsoleOutput AS DWORD, _
    szCharacter AS ASCIIZ, BYVAL nLength AS DWORD, _
    BYVAL dwWriteCoord AS DWORD, lpNumberOfCharsWritten AS DWORD) AS LONG

DECLARE FUNCTION WriteConsoleOutputCharacterW LIB "KERNEL32.DLL" _
    ALIAS "WriteConsoleOutputCharacterW" (BYVAL hConsoleOutput AS DWORD, _
    szCharacter AS WSTRINGZ, BYVAL nLength AS DWORD, _
    BYVAL dwWriteCoord AS DWORD, lpNumberOfCharsWritten AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION WriteConsoleOutputCharacter LIB "KERNEL32.DLL" _
    ALIAS "WriteConsoleOutputCharacterW" (BYVAL hConsoleOutput AS DWORD, _
    szCharacter AS WSTRINGZ, BYVAL nLength AS DWORD, _
    BYVAL dwWriteCoord AS DWORD, lpNumberOfCharsWritten AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION WriteConsoleOutputCharacter LIB "KERNEL32.DLL" _
    ALIAS "WriteConsoleOutputCharacterA" (BYVAL hConsoleOutput AS DWORD, _
    szCharacter AS ASCIIZ, BYVAL nLength AS DWORD, _
    BYVAL dwWriteCoord AS DWORD, lpNumberOfCharsWritten AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION WriteConsoleOutputAttribute LIB "KERNEL32.DLL" _
    ALIAS "WriteConsoleOutputAttribute" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL lpAttribute AS WORD PTR, BYVAL nLength AS DWORD, _
    BYVAL dwWriteCoord AS DWORD, lpNumberOfAttrsWritten AS DWORD) AS LONG

DECLARE FUNCTION FillConsoleOutputCharacterA LIB "KERNEL32.DLL" _
    ALIAS "FillConsoleOutputCharacterA" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL bCharacter AS BYTE, BYVAL nLength AS DWORD, _
    BYVAL dwWriteCoord AS DWORD, lpNumberOfCharsWritten AS DWORD) AS LONG

DECLARE FUNCTION FillConsoleOutputCharacterW LIB "KERNEL32.DLL" _
    ALIAS "FillConsoleOutputCharacterW" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL bCharacter AS WORD, BYVAL nLength AS DWORD, _
    BYVAL dwWriteCoord AS DWORD, lpNumberOfCharsWritten AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION FillConsoleOutputCharacter LIB "KERNEL32.DLL" _
    ALIAS "FillConsoleOutputCharacterW" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL bCharacter AS WORD, BYVAL nLength AS DWORD, _
    BYVAL dwWriteCoord AS DWORD, lpNumberOfCharsWritten AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION FillConsoleOutputCharacter LIB "KERNEL32.DLL" _
    ALIAS "FillConsoleOutputCharacterA" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL bCharacter AS BYTE, BYVAL nLength AS DWORD, _
    BYVAL dwWriteCoord AS DWORD, lpNumberOfCharsWritten AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION FillConsoleOutputAttribute LIB "KERNEL32.DLL" _
    ALIAS "FillConsoleOutputAttribute" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL wAttribute AS WORD, BYVAL nLength AS DWORD, _
    BYVAL dwWriteCoord AS DWORD, lpNumberOfAttrsWritten AS DWORD) AS LONG

DECLARE FUNCTION GetConsoleMode LIB "KERNEL32.DLL" ALIAS "GetConsoleMode" _
    (BYVAL hConsoleHandle AS DWORD, lpMode AS DWORD) AS LONG

DECLARE FUNCTION GetNumberOfConsoleInputEvents LIB "KERNEL32.DLL" _
    ALIAS "GetNumberOfConsoleInputEvents" (BYVAL hConsoleInput AS DWORD, _
    lpNumberOfEvents AS DWORD) AS LONG

%CONSOLE_REAL_OUTPUT_HANDLE = -2
%CONSOLE_REAL_INPUT_HANDLE  = -3

DECLARE FUNCTION GetConsoleScreenBufferInfo LIB "KERNEL32.DLL" _
    ALIAS "GetConsoleScreenBufferInfo" (BYVAL hConsoleOutput AS DWORD, _
    lpConsoleScreenBufferInfo AS CONSOLE_SCREEN_BUFFER_INFO) AS LONG

DECLARE FUNCTION GetConsoleScreenBufferInfoEx LIB "KERNEL32.DLL" _
    ALIAS "GetConsoleScreenBufferInfoEx" (BYVAL hConsoleOutput AS DWORD, _
    lpConsoleScreenBufferInfoEx AS CONSOLE_SCREEN_BUFFER_INFOEX) AS LONG

DECLARE FUNCTION SetConsoleScreenBufferInfoEx LIB "KERNEL32.DLL" _
    ALIAS "SetConsoleScreenBufferInfoEx" (BYVAL hConsoleOutput AS DWORD, _
    lpConsoleScreenBufferInfoEx AS CONSOLE_SCREEN_BUFFER_INFOEX) AS LONG

DECLARE FUNCTION GetLargestConsoleWindowSize LIB "KERNEL32.DLL" _
    ALIAS "GetLargestConsoleWindowSize" (BYVAL hConsoleOutput AS DWORD) _
    AS DWORD

DECLARE FUNCTION GetConsoleCursorInfo LIB "KERNEL32.DLL" _
    ALIAS "GetConsoleCursorInfo" (BYVAL hConsoleOutput AS DWORD, _
    lpConsoleCursorInfo AS CONSOLE_CURSOR_INFO) AS LONG

#IF (%WIN32_WINNT >= &H0500)

DECLARE FUNCTION GetCurrentConsoleFont LIB "Kernel32.dll" _
    ALIAS "GetCurrentConsoleFont" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL bMaximumWindow AS LONG, lpConsoleCurrentFont AS CONSOLE_FONT_INFO) _
    AS LONG

#IF NOT %DEF(%NOGDI)

DECLARE FUNCTION GetCurrentConsoleFontEx LIB "Kernel32.dll" _
    ALIAS "GetCurrentConsoleFontEx" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL bMaximumWindow AS LONG, _
    lpConsoleCurrentFontEx AS CONSOLE_FONT_INFOEX) AS LONG

DECLARE FUNCTION SetCurrentConsoleFontEx LIB "Kernel32.dll" _
    ALIAS "SetCurrentConsoleFontEx" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL bMaximumWindow AS LONG, _
    lpConsoleCurrentFontEx AS CONSOLE_FONT_INFOEX) AS LONG

#ENDIF  ' #IF NOT %DEF(%NOGDI)

DECLARE FUNCTION GetConsoleHistoryInfo LIB "Kernel32.dll" _
    ALIAS "GetConsoleHistoryInfo" _
    (lpConsoleHistoryInfo AS CONSOLE_HISTORY_INFO) AS LONG

DECLARE FUNCTION SetConsoleHistoryInfo LIB "Kernel32.dll" _
    ALIAS "SetConsoleHistoryInfo" _
    (lpConsoleHistoryInfo AS CONSOLE_HISTORY_INFO) AS LONG

DECLARE FUNCTION GetConsoleFontSize LIB "Kernel32.dll" _
    ALIAS "GetConsoleFontSize" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL nFont AS DWORD) AS DWORD

DECLARE FUNCTION GetConsoleSelectionInfo LIB "Kernel32.dll" _
    ALIAS "GetConsoleSelectionInfo" _
    (lpConsoleSelectionInfo AS CONSOLE_SELECTION_INFO) AS LONG

#ENDIF ' %WIN32_WINNT >= &H0500

DECLARE FUNCTION GetNumberOfConsoleMouseButtons LIB "KERNEL32.DLL" _
    ALIAS "GetNumberOfConsoleMouseButtons" (lpNumberOfMouseButtons AS LONG) _
    AS LONG

DECLARE FUNCTION SetConsoleMode LIB "KERNEL32.DLL" ALIAS "SetConsoleMode" _
    (BYVAL hConsoleHandle AS DWORD, BYVAL dwMode AS DWORD) AS LONG

DECLARE FUNCTION SetConsoleActiveScreenBuffer LIB "KERNEL32.DLL" _
    ALIAS "SetConsoleActiveScreenBuffer" (BYVAL hConsoleOutput AS DWORD) _
    AS LONG

DECLARE FUNCTION FlushConsoleInputBuffer LIB "KERNEL32.DLL" _
    ALIAS "FlushConsoleInputBuffer" (BYVAL hConsoleInput AS DWORD) AS LONG

DECLARE FUNCTION SetConsoleScreenBufferSize LIB "KERNEL32.DLL" _
    ALIAS "SetConsoleScreenBufferSize" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL dwSize AS DWORD) AS LONG

DECLARE FUNCTION SetConsoleCursorPosition LIB "KERNEL32.DLL" _
    ALIAS "SetConsoleCursorPosition" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL dwCursorPosition AS DWORD) AS LONG

DECLARE FUNCTION SetConsoleCursorInfo LIB "KERNEL32.DLL" _
    ALIAS "SetConsoleCursorInfo" (BYVAL hConsoleOutput AS DWORD, _
    lpConsoleCursorInfo AS CONSOLE_CURSOR_INFO) AS LONG

DECLARE FUNCTION ScrollConsoleScreenBufferA LIB "KERNEL32.DLL" _
    ALIAS "ScrollConsoleScreenBufferA" (BYVAL hConsoleOutput AS DWORD, _
    lpScrollRectangle AS SMALL_RECT, lpClipRectangle AS SMALL_RECT, _
    BYVAL dwDestinationOrigin AS DWORD, lpFill AS CHAR_INFO) AS LONG

DECLARE FUNCTION ScrollConsoleScreenBufferW LIB "KERNEL32.DLL" _
    ALIAS "ScrollConsoleScreenBufferW" (BYVAL hConsoleOutput AS DWORD, _
    lpScrollRectangle AS SMALL_RECT, lpClipRectangle AS SMALL_RECT, _
    BYVAL dwDestinationOrigin AS DWORD, lpFill AS CHAR_INFO) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ScrollConsoleScreenBuffer LIB "KERNEL32.DLL" _
    ALIAS "ScrollConsoleScreenBufferW" (BYVAL hConsoleOutput AS DWORD, _
    lpScrollRectangle AS SMALL_RECT, lpClipRectangle AS SMALL_RECT, _
    BYVAL dwDestinationOrigin AS DWORD, lpFill AS CHAR_INFO) AS LONG
#ELSE
DECLARE FUNCTION ScrollConsoleScreenBuffer LIB "KERNEL32.DLL" _
    ALIAS "ScrollConsoleScreenBufferA" (BYVAL hConsoleOutput AS DWORD, _
    lpScrollRectangle AS SMALL_RECT, lpClipRectangle AS SMALL_RECT, _
    BYVAL dwDestinationOrigin AS DWORD, lpFill AS CHAR_INFO) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetConsoleWindowInfo LIB "KERNEL32.DLL" _
    ALIAS "SetConsoleWindowInfo" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL bAbsolute AS LONG, lpConsoleWindow AS SMALL_RECT) AS LONG

DECLARE FUNCTION SetConsoleTextAttribute LIB "KERNEL32.DLL" _
    ALIAS "SetConsoleTextAttribute" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL dwAttributes AS DWORD) AS LONG

DECLARE FUNCTION SetConsoleCtrlHandler LIB "KERNEL32.DLL" _
    ALIAS "SetConsoleCtrlHandler" (BYVAL HandlerRoutine AS DWORD, _
    BYVAL nAdd AS LONG) AS LONG

DECLARE FUNCTION GenerateConsoleCtrlEvent LIB "KERNEL32.DLL" _
    ALIAS "GenerateConsoleCtrlEvent" (BYVAL dwCtrlEvent AS DWORD, _
    BYVAL dwProcessGroupId AS DWORD) AS LONG

DECLARE FUNCTION AllocConsole LIB "KERNEL32.DLL" ALIAS "AllocConsole" () _
    AS LONG

DECLARE FUNCTION FreeConsole LIB "KERNEL32.DLL" ALIAS "FreeConsole" () AS LONG

#IF (%WIN32_WINNT >= &H0500)

DECLARE FUNCTION AttachConsole LIB "Kernel32.dll" ALIAS "AttachConsole" _
    (BYVAL dwProcessId AS DWORD) AS LONG

%ATTACH_PARENT_PROCESS = &HFFFFFFFF??? ' ((DWORD)-1)

#ENDIF ' %WIN32_WINNT >= &H0500

DECLARE FUNCTION GetConsoleTitleA LIB "KERNEL32.DLL" ALIAS "GetConsoleTitleA" _
    (lpConsoleTitle AS ASCIIZ, BYVAL nSize AS DWORD) AS DWORD

DECLARE FUNCTION GetConsoleTitleW LIB "KERNEL32.DLL" ALIAS "GetConsoleTitleW" _
    (lpConsoleTitle AS WSTRINGZ, BYVAL nSize AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetConsoleTitle LIB "KERNEL32.DLL" ALIAS "GetConsoleTitleW" _
    (lpConsoleTitle AS WSTRINGZ, BYVAL nSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetConsoleTitle LIB "KERNEL32.DLL" ALIAS "GetConsoleTitleA" _
    (lpConsoleTitle AS ASCIIZ, BYVAL nSize AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

#IF (%WIN32_WINNT >= &H0600)

DECLARE FUNCTION GetConsoleOriginalTitleA LIB "Kernel32.dll" _
    ALIAS "GetConsoleOriginalTitleA" (lpConsoleTitle AS ASCIIZ, _
    BYVAL nSize AS DWORD) AS DWORD

DECLARE FUNCTION GetConsoleOriginalTitleW LIB "Kernel32.dll" _
    ALIAS "GetConsoleOriginalTitleW" (lpConsoleTitle AS WSTRINGZ, _
    BYVAL nSize AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetConsoleOriginalTitle LIB "Kernel32.dll" _
    ALIAS "GetConsoleOriginalTitleW" (lpConsoleTitle AS WSTRINGZ, _
    BYVAL nSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetConsoleOriginalTitle LIB "Kernel32.dll" _
    ALIAS "GetConsoleOriginalTitleA" (lpConsoleTitle AS ASCIIZ, _
    BYVAL nSize AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

#ENDIF ' %WIN32_WINNT >= &H0600

DECLARE FUNCTION SetConsoleTitleA LIB "KERNEL32.DLL" ALIAS "SetConsoleTitleA" _
    (lpConsoleTitle AS ASCIIZ) AS LONG

DECLARE FUNCTION SetConsoleTitleW LIB "KERNEL32.DLL" ALIAS "SetConsoleTitleW" _
    (lpConsoleTitle AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetConsoleTitle LIB "KERNEL32.DLL" ALIAS "SetConsoleTitleW" _
    (lpConsoleTitle AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION SetConsoleTitle LIB "KERNEL32.DLL" ALIAS "SetConsoleTitleA" _
    (lpConsoleTitle AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

TYPE CONSOLE_READCONSOLE_CONTROL
    nLength           AS DWORD    ' sizeof( CONSOLE_READCONSOLE_CONTROL )
    nInitialChars     AS DWORD
    dwCtrlWakeupMask  AS DWORD
    dwControlKeyState AS DWORD
END TYPE

DECLARE FUNCTION ReadConsoleA LIB "KERNEL32.DLL" ALIAS "ReadConsoleA" _
    (BYVAL hConsoleInput AS DWORD, lpBuffer AS ANY, _
    BYVAL nNumberOfCharsToRead AS DWORD, lpNumberOfCharsRead AS DWORD, _
    pInputControl AS CONSOLE_READCONSOLE_CONTROL) AS LONG

DECLARE FUNCTION ReadConsoleW LIB "KERNEL32.DLL" ALIAS "ReadConsoleW" _
    (BYVAL hConsoleInput AS DWORD, lpBuffer AS ANY, _
    BYVAL nNumberOfCharsToRead AS DWORD, lpNumberOfCharsRead AS DWORD, _
    pInputControl AS CONSOLE_READCONSOLE_CONTROL) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ReadConsole LIB "KERNEL32.DLL" ALIAS "ReadConsoleW" _
    (BYVAL hConsoleInput AS DWORD, lpBuffer AS ANY, _
    BYVAL nNumberOfCharsToRead AS DWORD, lpNumberOfCharsRead AS DWORD, _
    pInputControl AS CONSOLE_READCONSOLE_CONTROL) AS LONG
#ELSE
DECLARE FUNCTION ReadConsole LIB "KERNEL32.DLL" ALIAS "ReadConsoleA" _
    (BYVAL hConsoleInput AS DWORD, lpBuffer AS ANY, _
    BYVAL nNumberOfCharsToRead AS DWORD, lpNumberOfCharsRead AS DWORD, _
    pInputControl AS CONSOLE_READCONSOLE_CONTROL) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION WriteConsoleA LIB "KERNEL32.DLL" ALIAS "WriteConsoleA" _
    (BYVAL hConsoleOutput AS DWORD, lpBuffer AS ASCIIZ, _
    BYVAL nNumberOfCharsToWrite AS DWORD, lpNumberOfCharsWritten AS DWORD, _
    BYVAL lpReserved AS LONG) AS LONG

DECLARE FUNCTION WriteConsoleW LIB "KERNEL32.DLL" ALIAS "WriteConsoleW" _
    (BYVAL hConsoleOutput AS DWORD, lpBuffer AS WSTRINGZ, _
    BYVAL nNumberOfCharsToWrite AS DWORD, lpNumberOfCharsWritten AS DWORD, _
    BYVAL lpReserved AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION WriteConsole LIB "KERNEL32.DLL" ALIAS "WriteConsoleW" _
    (BYVAL hConsoleOutput AS DWORD, lpBuffer AS WSTRINGZ, _
    BYVAL nNumberOfCharsToWrite AS DWORD, lpNumberOfCharsWritten AS DWORD, _
    BYVAL lpReserved AS LONG) AS LONG
#ELSE
DECLARE FUNCTION WriteConsole LIB "KERNEL32.DLL" ALIAS "WriteConsoleA" _
    (BYVAL hConsoleOutput AS DWORD, lpBuffer AS ASCIIZ, _
    BYVAL nNumberOfCharsToWrite AS DWORD, lpNumberOfCharsWritten AS DWORD, _
    BYVAL lpReserved AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

%CONSOLE_TEXTMODE_BUFFER = 1

DECLARE FUNCTION CreateConsoleScreenBuffer LIB "KERNEL32.DLL" _
    ALIAS "CreateConsoleScreenBuffer" (BYVAL dwDesiredAccess AS DWORD, _
    BYVAL dwShareMode AS DWORD, lpSecurityAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL dwFlags AS DWORD, BYVAL lpScreenBufferData AS DWORD) AS DWORD

DECLARE FUNCTION GetConsoleCP LIB "KERNEL32.DLL" ALIAS "GetConsoleCP" () _
    AS DWORD

DECLARE FUNCTION SetConsoleCP LIB "KERNEL32.DLL" ALIAS "SetConsoleCP" _
    (BYVAL dwCodePageID AS DWORD) AS LONG

DECLARE FUNCTION GetConsoleOutputCP LIB "KERNEL32.DLL" _
    ALIAS "GetConsoleOutputCP" () AS DWORD

DECLARE FUNCTION SetConsoleOutputCP LIB "KERNEL32.DLL" _
    ALIAS "SetConsoleOutputCP" (BYVAL dwCodePageID AS DWORD) AS LONG

#IF (%WIN32_WINNT >= &H0500)

%CONSOLE_FULLSCREEN          = 1   ' fullscreen console
%CONSOLE_FULLSCREEN_HARDWARE = 2   ' console owns the hardware

DECLARE FUNCTION GetConsoleDisplayMode LIB "Kernel32.dll" _
    ALIAS "GetConsoleDisplayMode" (lpModeFlags AS DWORD) AS LONG

%CONSOLE_FULLSCREEN_MODE = 1
%CONSOLE_WINDOWED_MODE   = 2

DECLARE FUNCTION SetConsoleDisplayMode LIB "Kernel32.dll" _
    ALIAS "SetConsoleDisplayMode" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL dwFlags AS DWORD, lpNewScreenBufferDimensions AS COORD) AS LONG

DECLARE FUNCTION GetConsoleWindow LIB "Kernel32.dll" ALIAS "GetConsoleWindow" _
    () AS DWORD

#ENDIF ' %WIN32_WINNT >= &H0500

#IF (%WIN32_WINNT >= &H0501)

DECLARE FUNCTION GetConsoleProcessList LIB "Kernel32.dll" _
    ALIAS "GetConsoleProcessList" (lpdwProcessList AS DWORD, _
    BYVAL dwProcessCount AS DWORD) AS DWORD

'
' Aliasing apis.
'

DECLARE FUNCTION AddConsoleAliasA LIB "Kernel32.dll" ALIAS "AddConsoleAliasA" _
    (Source AS ASCIIZ, Target AS ASCIIZ, ExeName AS ASCIIZ) AS LONG

DECLARE FUNCTION AddConsoleAliasW LIB "Kernel32.dll" ALIAS "AddConsoleAliasW" _
    (Source AS WSTRINGZ, Target AS WSTRINGZ, ExeName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION AddConsoleAlias LIB "Kernel32.dll" ALIAS "AddConsoleAliasW" _
    (Source AS WSTRINGZ, Target AS WSTRINGZ, ExeName AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION AddConsoleAlias LIB "Kernel32.dll" ALIAS "AddConsoleAliasA" _
    (Source AS ASCIIZ, Target AS ASCIIZ, ExeName AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetConsoleAliasA LIB "Kernel32.dll" ALIAS "GetConsoleAliasA" _
    (Source AS ASCIIZ, TargetBuffer AS ASCIIZ, _
    BYVAL TargetBufferLength AS DWORD, ExeName AS ASCIIZ) AS DWORD

DECLARE FUNCTION GetConsoleAliasW LIB "Kernel32.dll" ALIAS "GetConsoleAliasW" _
    (Source AS WSTRINGZ, TargetBuffer AS WSTRINGZ, _
    BYVAL TargetBufferLength AS DWORD, ExeName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetConsoleAlias LIB "Kernel32.dll" ALIAS "GetConsoleAliasW" _
    (Source AS WSTRINGZ, TargetBuffer AS WSTRINGZ, _
    BYVAL TargetBufferLength AS DWORD, ExeName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION GetConsoleAlias LIB "Kernel32.dll" ALIAS "GetConsoleAliasA" _
    (Source AS ASCIIZ, TargetBuffer AS ASCIIZ, _
    BYVAL TargetBufferLength AS DWORD, ExeName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetConsoleAliasesLengthA LIB "Kernel32.dll" _
    ALIAS "GetConsoleAliasesLengthA" (ExeName AS ASCIIZ) AS DWORD

DECLARE FUNCTION GetConsoleAliasesLengthW LIB "Kernel32.dll" _
    ALIAS "GetConsoleAliasesLengthW" (ExeName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetConsoleAliasesLength LIB "Kernel32.dll" _
    ALIAS "GetConsoleAliasesLengthW" (ExeName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION GetConsoleAliasesLength LIB "Kernel32.dll" _
    ALIAS "GetConsoleAliasesLengthA" (ExeName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetConsoleAliasExesLengthA LIB "Kernel32.dll" _
    ALIAS "GetConsoleAliasExesLengthA" () AS DWORD

DECLARE FUNCTION GetConsoleAliasExesLengthW LIB "Kernel32.dll" _
    ALIAS "GetConsoleAliasExesLengthW" () AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetConsoleAliasExesLength LIB "Kernel32.dll" _
    ALIAS "GetConsoleAliasExesLengthW" () AS DWORD
#ELSE
DECLARE FUNCTION GetConsoleAliasExesLength LIB "Kernel32.dll" _
    ALIAS "GetConsoleAliasExesLengthA" () AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetConsoleAliasesA LIB "Kernel32.dll" _
    ALIAS "GetConsoleAliasesA" (BYVAL AliasBuffer AS DWORD, _
    BYVAL AliasBufferLength AS DWORD, ExeName AS ASCIIZ) AS DWORD

DECLARE FUNCTION GetConsoleAliasesW LIB "Kernel32.dll" _
    ALIAS "GetConsoleAliasesW" (BYVAL AliasBuffer AS DWORD, _
    BYVAL AliasBufferLength AS DWORD, ExeName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetConsoleAliases LIB "Kernel32.dll" _
    ALIAS "GetConsoleAliasesW" (BYVAL AliasBuffer AS DWORD, _
    BYVAL AliasBufferLength AS DWORD, ExeName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION GetConsoleAliases LIB "Kernel32.dll" _
    ALIAS "GetConsoleAliasesA" (BYVAL AliasBuffer AS DWORD, _
    BYVAL AliasBufferLength AS DWORD, ExeName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetConsoleAliasExesA LIB "Kernel32.dll" _
    ALIAS "GetConsoleAliasExesA" (ExeNameBuffer AS ASCIIZ, _
    BYVAL ExeNameBufferLength AS DWORD) AS DWORD

DECLARE FUNCTION GetConsoleAliasExesW LIB "Kernel32.dll" _
    ALIAS "GetConsoleAliasExesW" (ExeNameBuffer AS WSTRINGZ, _
    BYVAL ExeNameBufferLength AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetConsoleAliasExes LIB "Kernel32.dll" _
    ALIAS "GetConsoleAliasExesW" (ExeNameBuffer AS WSTRINGZ, _
    BYVAL ExeNameBufferLength AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetConsoleAliasExes LIB "Kernel32.dll" _
    ALIAS "GetConsoleAliasExesA" (ExeNameBuffer AS ASCIIZ, _
    BYVAL ExeNameBufferLength AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

#ENDIF ' %WIN32_WINNT >= &H0501
