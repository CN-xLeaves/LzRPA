'------------------------------------------------------------------------------
'
'  ShellApi.inc -- SHELL.DLL functions, types, and definitions
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 07 Apr 2011
'
'------------------------------------------------------------------------------
'  from ShellApi.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%INC_SHELLAPI = 1

#INCLUDE "IpHlpApi.inc"


'DECLARE_HANDLE(HDROP);

DECLARE FUNCTION DragQueryFileA LIB "Shell32.dll" ALIAS "DragQueryFileA" ( _
    BYVAL hDrop AS DWORD, BYVAL iFile AS DWORD, lpszFile AS ASCIIZ, _
    BYVAL cch AS DWORD) AS DWORD

DECLARE FUNCTION DragQueryFileW LIB "Shell32.dll" ALIAS "DragQueryFileW" ( _
    BYVAL hDrop AS DWORD, BYVAL iFile AS DWORD, lpszFile AS WSTRINGZ, _
    BYVAL cch AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION DragQueryFile LIB "Shell32.dll" ALIAS "DragQueryFileW" ( _
    BYVAL hDrop AS DWORD, BYVAL iFile AS DWORD, lpszFile AS WSTRINGZ, _
    BYVAL cch AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION DragQueryFile LIB "Shell32.dll" ALIAS "DragQueryFileA" ( _
    BYVAL hDrop AS DWORD, BYVAL iFile AS DWORD, lpszFile AS ASCIIZ, _
    BYVAL cch AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DragQueryPoint LIB "Shell32.dll" ALIAS "DragQueryPoint" ( _
    BYVAL hDrop AS DWORD, lppt AS POINT) AS LONG

DECLARE SUB DragFinish LIB "Shell32.dll" ALIAS "DragFinish" ( _
    BYVAL hDrop AS DWORD)

DECLARE SUB DragAcceptFiles LIB "Shell32.dll" ALIAS "DragAcceptFiles" ( _
    BYVAL hWnd AS DWORD, BYVAL fAccept AS LONG)

DECLARE FUNCTION ShellExecuteA LIB "Shell32.dll" ALIAS "ShellExecuteA" ( _
    BYVAL hwnd AS DWORD, lpOperation AS ASCIIZ, lpFile AS ASCIIZ, _
    lpParameters AS ASCIIZ, lpDirectory AS ASCIIZ, BYVAL nShowCmd AS LONG) _
    AS DWORD

DECLARE FUNCTION ShellExecuteW LIB "Shell32.dll" ALIAS "ShellExecuteW" ( _
    BYVAL hwnd AS DWORD, lpOperation AS WSTRINGZ, lpFile AS WSTRINGZ, _
    lpParameters AS WSTRINGZ, lpDirectory AS WSTRINGZ, BYVAL nShowCmd AS LONG) _
    AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION ShellExecute LIB "Shell32.dll" ALIAS "ShellExecuteW" ( _
    BYVAL hwnd AS DWORD, lpOperation AS WSTRINGZ, lpFile AS WSTRINGZ, _
    lpParameters AS WSTRINGZ, lpDirectory AS WSTRINGZ, BYVAL nShowCmd AS LONG) _
    AS DWORD
#ELSE
DECLARE FUNCTION ShellExecute LIB "Shell32.dll" ALIAS "ShellExecuteA" ( _
    BYVAL hwnd AS DWORD, lpOperation AS ASCIIZ, lpFile AS ASCIIZ, _
    lpParameters AS ASCIIZ, lpDirectory AS ASCIIZ, BYVAL nShowCmd AS LONG) _
    AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION FindExecutableA LIB "Shell32.dll" ALIAS "FindExecutableA" ( _
    lpFile AS ASCIIZ, lpDirectory AS ASCIIZ, lpResult AS ASCIIZ) AS DWORD

DECLARE FUNCTION FindExecutableW LIB "Shell32.dll" ALIAS "FindExecutableW" ( _
    lpFile AS WSTRINGZ, lpDirectory AS WSTRINGZ, lpResult AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION FindExecutable LIB "Shell32.dll" ALIAS "FindExecutableW" ( _
    lpFile AS WSTRINGZ, lpDirectory AS WSTRINGZ, lpResult AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION FindExecutable LIB "Shell32.dll" ALIAS "FindExecutableA" ( _
    lpFile AS ASCIIZ, lpDirectory AS ASCIIZ, lpResult AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CommandLineToArgvW LIB "Shell32.dll" _
    ALIAS "CommandLineToArgvW" (lpCmdLine AS WSTRINGZ, pNumArgs AS LONG) _
    AS DWORD  'LPWSTR *

DECLARE FUNCTION ShellAboutA LIB "Shell32.dll" ALIAS "ShellAboutA" ( _
    BYVAL hWnd AS DWORD, szApp AS ASCIIZ, szOtherStuff AS ASCIIZ, _
    BYVAL hIcon AS DWORD) AS LONG

DECLARE FUNCTION ShellAboutW LIB "Shell32.dll" ALIAS "ShellAboutW" ( _
    BYVAL hWnd AS DWORD, szApp AS WSTRINGZ, szOtherStuff AS WSTRINGZ, _
    BYVAL hIcon AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ShellAbout LIB "Shell32.dll" ALIAS "ShellAboutW" ( _
    BYVAL hWnd AS DWORD, szApp AS WSTRINGZ, szOtherStuff AS WSTRINGZ, _
    BYVAL hIcon AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION ShellAbout LIB "Shell32.dll" ALIAS "ShellAboutA" ( _
    BYVAL hWnd AS DWORD, szApp AS ASCIIZ, szOtherStuff AS ASCIIZ, _
    BYVAL hIcon AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DuplicateIcon LIB "Shell32.dll" ALIAS "DuplicateIcon" ( _
    BYVAL hInst AS DWORD, BYVAL hIcon AS DWORD) AS DWORD

DECLARE FUNCTION ExtractAssociatedIconA LIB "Shell32.dll" _
    ALIAS "ExtractAssociatedIconA" (BYVAL hInst AS DWORD, _
    pszIconPath AS ASCIIZ, piIcon AS WORD) AS DWORD

DECLARE FUNCTION ExtractAssociatedIconW LIB "Shell32.dll" _
    ALIAS "ExtractAssociatedIconW" (BYVAL hInst AS DWORD, _
    pszIconPath AS WSTRINGZ, piIcon AS WORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION ExtractAssociatedIcon LIB "Shell32.dll" _
    ALIAS "ExtractAssociatedIconW" (BYVAL hInst AS DWORD, _
    pszIconPath AS WSTRINGZ, piIcon AS WORD) AS DWORD
#ELSE
DECLARE FUNCTION ExtractAssociatedIcon LIB "Shell32.dll" _
    ALIAS "ExtractAssociatedIconA" (BYVAL hInst AS DWORD, _
    pszIconPath AS ASCIIZ, piIcon AS WORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION ExtractAssociatedIconExA LIB "Shell32.dll" _
    ALIAS "ExtractAssociatedIconExA" (BYVAL hInst AS DWORD, _
    pszIconPath AS ASCIIZ, piIconIndex AS WORD, piIconId AS WORD) AS DWORD

DECLARE FUNCTION ExtractAssociatedIconExW LIB "Shell32.dll" _
    ALIAS "ExtractAssociatedIconExW" (BYVAL hInst AS DWORD, _
    pszIconPath AS WSTRINGZ, piIconIndex AS WORD, piIconId AS WORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION ExtractAssociatedIconEx LIB "Shell32.dll" _
    ALIAS "ExtractAssociatedIconExW" (BYVAL hInst AS DWORD, _
    pszIconPath AS WSTRINGZ, piIconIndex AS WORD, piIconId AS WORD) AS DWORD
#ELSE
DECLARE FUNCTION ExtractAssociatedIconEx LIB "Shell32.dll" _
    ALIAS "ExtractAssociatedIconExA" (BYVAL hInst AS DWORD, _
    pszIconPath AS ASCIIZ, piIconIndex AS WORD, piIconId AS WORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION ExtractIconA LIB "Shell32.dll" ALIAS "ExtractIconA" ( _
    BYVAL hInst AS DWORD, lpszExeFileName AS ASCIIZ, _
    BYVAL nIconIndex AS DWORD) AS DWORD

DECLARE FUNCTION ExtractIconW LIB "Shell32.dll" ALIAS "ExtractIconW" ( _
    BYVAL hInst AS DWORD, lpszExeFileName AS WSTRINGZ, _
    BYVAL nIconIndex AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION ExtractIcon LIB "Shell32.dll" ALIAS "ExtractIconW" ( _
    BYVAL hInst AS DWORD, lpszExeFileName AS WSTRINGZ, _
    BYVAL nIconIndex AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION ExtractIcon LIB "Shell32.dll" ALIAS "ExtractIconA" ( _
    BYVAL hInst AS DWORD, lpszExeFileName AS ASCIIZ, _
    BYVAL nIconIndex AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE


#IF (%WINVER >= &H0400)

TYPE DRAGINFOA
    uSize       AS DWORD                  ' init with sizeof(DRAGINFO)
    pt          AS POINT
    fNC         AS LONG  ' BOOL
    lpFileList  AS ASCIIZ PTR
    grfKeyState AS DWORD
END TYPE

TYPE DRAGINFOW
    uSize       AS DWORD                  ' init with sizeof(DRAGINFO)
    pt          AS POINT
    fNC         AS LONG  ' BOOL
    lpFileList  AS WSTRINGZ PTR
    grfKeyState AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE DRAGINFO
    DRAGINFOW
END TYPE
#ELSE
TYPE DRAGINFO
    DRAGINFOA
END TYPE
#ENDIF ' UNICODE


''
'' AppBar stuff
''
%ABM_NEW            = &H00000000
%ABM_REMOVE         = &H00000001
%ABM_QUERYPOS       = &H00000002
%ABM_SETPOS         = &H00000003
%ABM_GETSTATE       = &H00000004
%ABM_GETTASKBARPOS  = &H00000005
%ABM_ACTIVATE       = &H00000006  ' lParam = TRUE/FALSE means activate/deactivate
%ABM_GETAUTOHIDEBAR = &H00000007
%ABM_SETAUTOHIDEBAR = &H00000008  ' this can fail at any time.  MUST check the result
                                  ' lParam = TRUE/FALSE  Set/Unset
                                  ' uEdge = what edge
%ABM_WINDOWPOSCHANGED = &H0000009
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
%ABM_SETSTATE      = &H0000000a
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WINXP)

' these are put in the wparam of callback messages
%ABN_STATECHANGE   = &H0000000
%ABN_POSCHANGED    = &H0000001
%ABN_FULLSCREENAPP = &H0000002
%ABN_WINDOWARRANGE = &H0000003 ' lParam = TRUE means hide

' flags for get state
%ABS_AUTOHIDE    = &H0000001
%ABS_ALWAYSONTOP = &H0000002

%ABE_LEFT      = 0
%ABE_TOP       = 1
%ABE_RIGHT     = 2
%ABE_BOTTOM    = 3

TYPE APPBARDATA
    cbSize           AS DWORD
    hWnd             AS DWORD  ' HWND
    uCallbackMessage AS DWORD
    uEdge            AS DWORD
    rc               AS RECT
    lParam           AS LONG   ' LPARAM  ' message specific
END TYPE


DECLARE FUNCTION SHAppBarMessage LIB "Shell32.dll" ALIAS "SHAppBarMessage" ( _
    BYVAL dwMessage AS DWORD, pData AS APPBARDATA) AS DWORD

''
''  EndAppBar
''

DECLARE FUNCTION DoEnvironmentSubstA LIB "Shell32.dll" _
    ALIAS "DoEnvironmentSubstA" (szString AS ASCIIZ, _
    BYVAL cchString AS DWORD) AS DWORD

DECLARE FUNCTION DoEnvironmentSubstW LIB "Shell32.dll" _
    ALIAS "DoEnvironmentSubstW" (szString AS WSTRINGZ, _
    BYVAL cchString AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION DoEnvironmentSubst LIB "Shell32.dll" _
    ALIAS "DoEnvironmentSubstW" (szString AS WSTRINGZ, _
    BYVAL cchString AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION DoEnvironmentSubst LIB "Shell32.dll" _
    ALIAS "DoEnvironmentSubstA" (szString AS ASCIIZ, _
    BYVAL cchString AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

MACRO EIRESID(x)=(-LO(LONG,(x)))

DECLARE FUNCTION ExtractIconExA LIB "Shell32.dll" ALIAS "ExtractIconExA" ( _
    lpszFile AS ASCIIZ, BYVAL nIconIndex AS LONG, _
    BYVAL phiconLarge AS DWORD PTR, BYVAL phiconSmall AS DWORD PTR, _
    BYVAL nIcons AS DWORD) AS DWORD

DECLARE FUNCTION ExtractIconExW LIB "Shell32.dll" ALIAS "ExtractIconExW" ( _
    lpszFile AS WSTRINGZ, BYVAL nIconIndex AS LONG, _
    BYVAL phiconLarge AS DWORD PTR, BYVAL phiconSmall AS DWORD PTR, _
    BYVAL nIcons AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION ExtractIconEx LIB "Shell32.dll" ALIAS "ExtractIconExW" ( _
    lpszFile AS WSTRINGZ, BYVAL nIconIndex AS LONG, _
    BYVAL phiconLarge AS DWORD PTR, BYVAL phiconSmall AS DWORD PTR, _
    BYVAL nIcons AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION ExtractIconEx LIB "Shell32.dll" ALIAS "ExtractIconExA" ( _
    lpszFile AS ASCIIZ, BYVAL nIconIndex AS LONG, _
    BYVAL phiconLarge AS DWORD PTR, BYVAL phiconSmall AS DWORD PTR, _
    BYVAL nIcons AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

' Shell File Operations

%FO_MOVE                   = &H0001
%FO_COPY                   = &H0002
%FO_DELETE                 = &H0003
%FO_RENAME                 = &H0004

' SHFILEOPSTRUCT.fFlags and IFileOperation::SetOperationFlags() flag values

%FOF_MULTIDESTFILES        = &H0001
%FOF_CONFIRMMOUSE          = &H0002
%FOF_SILENT                = &H0004  ' don't display progress UI (confirm prompts may be displayed still)
%FOF_RENAMEONCOLLISION     = &H0008  ' automatically rename the source files to avoid the collisions
%FOF_NOCONFIRMATION        = &H0010  ' don't display confirmation UI, assume "yes" for cases that can be bypassed, "no" for those that can not
%FOF_WANTMAPPINGHANDLE     = &H0020  ' Fill in SHFILEOPSTRUCT.hNameMappings
                                           ' Must be freed using SHFreeNameMappings
%FOF_ALLOWUNDO             = &H0040  ' enable undo including Recycle behavior for IFileOperation::Delete()
%FOF_FILESONLY             = &H0080  ' only operate on the files (non folders), both files and folders are assumed without this
%FOF_SIMPLEPROGRESS        = &H0100  ' means don't show names of files
%FOF_NOCONFIRMMKDIR        = &H0200  ' don't dispplay confirmatino UI before making any needed directories, assume "Yes" in these cases
%FOF_NOERRORUI             = &H0400  ' don't put up error UI, other UI may be displayed, progress, confirmations
#IF (%WIN32_IE >= &H0500)
%FOF_NOCOPYSECURITYATTRIBS = &H0800  ' dont copy file security attributes (ACLs)
%FOF_NORECURSION           = &H1000  ' don't recurse into directories for operations that would recurse
%FOF_NO_CONNECTED_ELEMENTS = &H2000  ' don't operate on connected elements ("xxx_files" folders that go with .htm files)
%FOF_WANTNUKEWARNING       = &H4000  ' during delete operation, warn if nuking instead of recycling (partially overrides FOF_NOCONFIRMATION)
#ENDIF ' (%WIN32_IE >= &H500)
#IF (%WIN32_WINNT >= &H0501)
%FOF_NORECURSEREPARSE      = &H8000?? ' deprecated; the operations engine always does the right thing on FolderLink objects (symlinks, reparse points, folder shortcuts)
#ENDIF ' (%WIN32_WINNT >= &H501)
%FOF_NO_UI = (%FOF_SILENT OR %FOF_NOCONFIRMATION OR %FOF_NOERRORUI _
           OR %FOF_NOCONFIRMMKDIR)  ' don't display any UI at all

MACRO FILEOP_FLAGS=WORD

%PO_DELETE     = &H0013  ' printer is being deleted
%PO_RENAME     = &H0014  ' printer is being renamed
%PO_PORTCHANGE = &H0020  ' port this printer connected to is being changed
                                ' if this id is set, the strings received by
                                ' the copyhook are a doubly-null terminated
                                ' list of strings.  The first is the printer
                                ' name and the second is the printer port.
%PO_REN_PORT   = &H0034  ' PO_RENAME and PO_PORTCHANGE at same time.

' no POF_ flags currently defined

MACRO PRINTEROP_FLAGS=WORD

' implicit parameters are:
'      if pFrom or pTo are unqualified names the current directories are
'      taken from the global current drive/directory settings managed
'      by Get/SetCurrentDrive/Directory
'
'      the global confirmation settings

TYPE SHFILEOPSTRUCTA
    hwnd                  AS DWORD         ' HWND
    wFunc                 AS DWORD
    pFrom                 AS ASCIIZ PTR
    pTo                   AS ASCIIZ PTR
    fFlags                AS FILEOP_FLAGS
    fAnyOperationsAborted AS LONG          ' BOOL
    hNameMappings         AS DWORD         ' LPVOID
    lpszProgressTitle     AS ASCIIZ PTR    ' only used if FOF_SIMPLEPROGRESS
END TYPE

TYPE SHFILEOPSTRUCTW
    hwnd                  AS DWORD         ' HWND
    wFunc                 AS DWORD
    pFrom                 AS WSTRINGZ PTR
    pTo                   AS WSTRINGZ PTR
    fFlags                AS FILEOP_FLAGS
    fAnyOperationsAborted AS LONG          ' BOOL
    hNameMappings         AS DWORD         ' LPVOID
    lpszProgressTitle     AS WSTRINGZ PTR  ' only used if FOF_SIMPLEPROGRESS
END TYPE

#IF %DEF(%UNICODE)
TYPE SHFILEOPSTRUCT
    SHFILEOPSTRUCTW
END TYPE
#ELSE
TYPE SHFILEOPSTRUCT
    SHFILEOPSTRUCTA
END TYPE
#ENDIF ' UNICODE

DECLARE FUNCTION SHFileOperationA LIB "Shell32.dll" _
    ALIAS "SHFileOperationA" (lpFileOp AS SHFILEOPSTRUCTA) AS LONG

DECLARE FUNCTION SHFileOperationW LIB "Shell32.dll" _
    ALIAS "SHFileOperationW" (lpFileOp AS SHFILEOPSTRUCTW) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHFileOperation LIB "Shell32.dll" _
    ALIAS "SHFileOperationW" (lpFileOp AS SHFILEOPSTRUCTW) AS LONG
#ELSE
DECLARE FUNCTION SHFileOperation LIB "Shell32.dll" _
    ALIAS "SHFileOperationA" (lpFileOp AS SHFILEOPSTRUCTA) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE SUB SHFreeNameMappings LIB "Shell32.dll" ALIAS "SHFreeNameMappings" ( _
    BYVAL hNameMappings AS DWORD)

TYPE SHNAMEMAPPINGA
    pszOldPath AS ASCIIZ PTR
    pszNewPath AS ASCIIZ PTR
    cchOldPath AS LONG
    cchNewPath AS LONG
END TYPE

TYPE SHNAMEMAPPINGW
    pszOldPath AS WSTRINGZ PTR
    pszNewPath AS WSTRINGZ PTR
    cchOldPath AS LONG
    cchNewPath AS LONG
END TYPE

#IF %DEF(%UNICODE)
TYPE SHNAMEMAPPING
    SHNAMEMAPPINGW
END TYPE
#ELSE
TYPE SHNAMEMAPPING
    SHNAMEMAPPINGA
END TYPE
#ENDIF ' UNICODE


''
'' End Shell File Operations
''

''
''  Begin ShellExecuteEx and family
''

' ShellExecute() and ShellExecuteEx() error codes

' regular WinExec() codes
%SE_ERR_FNF             = 2       ' file not found
%SE_ERR_PNF             = 3       ' path not found
%SE_ERR_ACCESSDENIED    = 5       ' access denied
%SE_ERR_OOM             = 8       ' out of memory
%SE_ERR_DLLNOTFOUND     = 32

#ENDIF ' %WINVER >= &H0400

' error values for ShellExecute() beyond the regular WinExec() codes
%SE_ERR_SHARE           = 26
%SE_ERR_ASSOCINCOMPLETE = 27
%SE_ERR_DDETIMEOUT      = 28
%SE_ERR_DDEFAIL         = 29
%SE_ERR_DDEBUSY         = 30
%SE_ERR_NOASSOC         = 31

#IF (%WINVER >= &H0400)

' Note CLASSKEY overrides CLASSNAME
%SEE_MASK_DEFAULT           = &H00000000
%SEE_MASK_CLASSNAME         = &H00000001   ' SHELLEXECUTEINFO.lpClass is valid
%SEE_MASK_CLASSKEY          = &H00000003   ' SHELLEXECUTEINFO.hkeyClass is valid
' Note SEE_MASK_INVOKEIDLIST(&HC) implies SEE_MASK_IDLIST(&H04)
%SEE_MASK_IDLIST            = &H00000004   ' SHELLEXECUTEINFO.lpIDList is valid
%SEE_MASK_INVOKEIDLIST      = &H0000000c   ' enable IContextMenu based verbs
#IF (%NTDDI_VERSION < %NTDDI_VISTA)
%SEE_MASK_ICON              = &H00000010   ' not used
#ENDIF ' (%NTDDI_VERSION < %NTDDI_VISTA)
%SEE_MASK_HOTKEY            = &H00000020   ' SHELLEXECUTEINFO.dwHotKey is valid
%SEE_MASK_NOCLOSEPROCESS    = &H00000040   ' SHELLEXECUTEINFO.hProcess
%SEE_MASK_CONNECTNETDRV     = &H00000080   ' enables re-connecting disconnected network drives
%SEE_MASK_NOASYNC           = &H00000100   ' block on the call until the invoke has completed, use for callers that exit after calling ShellExecuteEx()
%SEE_MASK_FLAG_DDEWAIT      = %SEE_MASK_NOASYNC ' Use SEE_MASK_NOASYNC instead of SEE_MASK_FLAG_DDEWAIT as it more accuratly describes the behavior
%SEE_MASK_DOENVSUBST        = &H00000200   ' indicates that SHELLEXECUTEINFO.lpFile contains env vars that should be expanded
%SEE_MASK_FLAG_NO_UI        = &H00000400   ' disable UI including error messages
%SEE_MASK_UNICODE           = &H00004000
%SEE_MASK_NO_CONSOLE        = &H00008000
%SEE_MASK_ASYNCOK           = &H00100000
#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)
%SEE_MASK_HMONITOR          = &H00200000   ' SHELLEXECUTEINFO.hMonitor
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WIN2K)
#IF (%NTDDI_VERSION >= %NTDDI_WINXPSP1)
%SEE_MASK_NOZONECHECKS      = &H00800000
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WINXPSP1)
#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)
%SEE_MASK_NOQUERYCLASSSTORE = &H01000000
%SEE_MASK_WAITFORINPUTIDLE  = &H02000000
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WIN2K)
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
%SEE_MASK_FLAG_LOG_USAGE    = &H04000000
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WINXP)



UNION SHELLEXECUTEINFO_union
    hIcon    AS DWORD  ' HANDLE  ' not used
#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)
    hMonitor AS DWORD  ' HANDLE  ' in, valid when SEE_MASK_HMONITOR specified
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WIN2K)
END UNION

TYPE SHELLEXECUTEINFOA
    cbSize       AS DWORD         ' in, required, sizeof of this structure
    fMask        AS DWORD         ' in, SEE_MASK_XXX values
    hwnd         AS DWORD         ' HWND   ' in, optional
    lpVerb       AS ASCIIZ PTR    ' in, optional when unspecified the default verb is choosen
    lpFile       AS ASCIIZ PTR    ' in, either this value or lpIDList must be specified
    lpParameters AS ASCIIZ PTR    ' in, optional
    lpDirectory  AS ASCIIZ PTR    ' in, optional
    nShow        AS LONG          ' in, required
    hInstApp     AS DWORD         ' HINSTANCE ' out when SEE_MASK_NOCLOSEPROCESS is specified
    lpIDList     AS DWORD         ' void *    ' in, valid when SEE_MASK_IDLIST is specified, PCIDLIST_ABSOLUTE, for use with SEE_MASK_IDLIST & SEE_MASK_INVOKEIDLIST
    lpClass      AS ASCIIZ PTR    ' in, valid when SEE_MASK_CLASSNAME is specified
    hkeyClass    AS DWORD         ' HKEY  ' in, valid when SEE_MASK_CLASSKEY is specified
    dwHotKey     AS DWORD         ' in, valid when SEE_MASK_HOTKEY is specified
    SHELLEXECUTEINFO_union
    hProcess     AS DWORD         ' HANDLE ' out, valid when SEE_MASK_NOCLOSEPROCESS specified
END TYPE

TYPE SHELLEXECUTEINFOW
    cbSize       AS DWORD         ' in, required, sizeof of this structure
    fMask        AS DWORD         ' in, SEE_MASK_XXX values
    hwnd         AS DWORD         ' HWND   ' in, optional
    lpVerb       AS WSTRINGZ PTR  ' in, optional when unspecified the default verb is choosen
    lpFile       AS WSTRINGZ PTR  ' in, either this value or lpIDList must be specified
    lpParameters AS WSTRINGZ PTR  ' in, optional
    lpDirectory  AS WSTRINGZ PTR  ' in, optional
    nShow        AS LONG          ' in, required
    hInstApp     AS DWORD         ' HINSTANCE ' out when SEE_MASK_NOCLOSEPROCESS is specified
    lpIDList     AS DWORD         ' void *    ' in, valid when SEE_MASK_IDLIST is specified, PCIDLIST_ABSOLUTE, for use with SEE_MASK_IDLIST & SEE_MASK_INVOKEIDLIST
    lpClass      AS WSTRINGZ PTR  ' in, valid when SEE_MASK_CLASSNAME is specified
    hkeyClass    AS DWORD         ' HKEY  ' in, valid when SEE_MASK_CLASSKEY is specified
    dwHotKey     AS DWORD         ' in, valid when SEE_MASK_HOTKEY is specified
    SHELLEXECUTEINFO_union
    hProcess     AS DWORD         ' HANDLE ' out, valid when SEE_MASK_NOCLOSEPROCESS specified
END TYPE

#IF %DEF(%UNICODE)
TYPE SHELLEXECUTEINFO
    SHELLEXECUTEINFOW
END TYPE
#ELSE
TYPE SHELLEXECUTEINFO
    SHELLEXECUTEINFOA
END TYPE
#ENDIF ' UNICODE

DECLARE FUNCTION ShellExecuteExA LIB "Shell32.dll" ALIAS "ShellExecuteExA" ( _
    pExecInfo AS SHELLEXECUTEINFOA) AS LONG

DECLARE FUNCTION ShellExecuteExW LIB "Shell32.dll" ALIAS "ShellExecuteExW" ( _
    pExecInfo AS SHELLEXECUTEINFOW) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ShellExecuteEx LIB "Shell32.dll" ALIAS "ShellExecuteExW" ( _
    pExecInfo AS SHELLEXECUTEINFOW) AS LONG
#ELSE
DECLARE FUNCTION ShellExecuteEx LIB "Shell32.dll" ALIAS "ShellExecuteExA" ( _
    pExecInfo AS SHELLEXECUTEINFOA) AS LONG
#ENDIF ' NOT %UNICODE

#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)
' deprecated, no longer implemented
TYPE SHCREATEPROCESSINFOW
    cbSize               AS DWORD
    fMask                AS DWORD
    hwnd                 AS DWORD  ' HWND
    pszFile              AS WSTRINGZ PTR
    pszParameters        AS WSTRINGZ PTR
    pszCurrentDirectory  AS WSTRINGZ PTR
    hUserToken           AS DWORD  ' HANDLE
    lpProcessAttributes  AS SECURITY_ATTRIBUTES PTR
    lpThreadAttributes   AS SECURITY_ATTRIBUTES PTR
    bInheritHandles      AS LONG  ' BOOL
    dwCreationFlags      AS DWORD
    lpStartupInfo        AS STARTUPINFOW PTR
    lpProcessInformation AS PROCESS_INFORMATION PTR
END TYPE

DECLARE FUNCTION SHCreateProcessAsUserW LIB "Shell32.dll" _
    ALIAS "SHCreateProcessAsUserW" (pscpi AS SHCREATEPROCESSINFOW) AS LONG

#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WIN2K)

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

DECLARE FUNCTION SHEvaluateSystemCommandTemplate LIB "Shell32.dll" _
    ALIAS "SHEvaluateSystemCommandTemplate" (pszCmdTemplate AS WSTRINGZ, _
    ppszApplication AS ANY, ppszCommandLine AS ANY, ppszParameters AS ANY) _
    AS LONG  ' HRESULT

'
'  SHEvaluateSystemCommandTemplate()
'      *   enforces stricter validation before calling CreateProcess().  may also be
'              used before calling ShellExecute().
'      *   should be used when caller wants the deterministic behavior from a command template
'              regardless of execution context.  it ignores the current process state,
'              such as the %PATH%, GetCurrentDirectory(), and parent process directory.
'      *   should be used when the command is hardcoded.
'      *   is used by ShellExecute() when handling file associations from HKCR.
'      *   reduces CreateProcess() commandline exploits
'      *   is not designed for processing user input, and may generate unexpected failures.
'
'  INPUT:
'      pszCmdTemplate =    command line, this may or may not include parameters.
'                          if the parameters are substitution parameters then this API
'                          should be called before parameters have been replaced.
'                          (check the examples below to see sample supported inputs.)
'
'  OUTPUT on return: S_OK
'      ppszApplication =   verified path to the Application.  this should be passed as the lpApplication
'                          parameter to CreateProcess() or the lpFile parameter to ShellExecute().
'                          (allocated using CoTaskMemAlloc(), free with CoTaskMemFree())
'
'      ppszCommandLine =   OPTIONAL - use if planning to call CreateProcess().
'                          resulting command line template.  parameters should be replaced based on this template,
'                          and then passed as the lpCommandLine parameter to CreateProcess().
'                          it is guaranteed to be of a form that PathGetArgs() will always succeed correctly.
'                          (allocated using CoTaskMemAlloc(), free with CoTaskMemFree())
'
'      ppszParameters  =   OPTIONAL - use if planning to call ShellExecute().
'                          resulting parameter list template.  parameters should be replaced based on this template,
'                          and then passed as the lpParameters parameter to ShellExecute().
'                          NOTE: identical to PathGetArgs(*ppszCommandLine).
'                          (allocated using CoTaskMemAlloc(), free with CoTaskMemFree())
'
'  OUTPUT on return: FAILED()
'      all outputs will be NULL'ed on failure
'
'  NOTES:  the parsing logic to determine a valid Application path is non-trivial, although
'              the extension is not required and if missing will be completed
'              in the following standard order:  { .PIF, .COM, .EXE, .BAT, .CMD }
'
'      Relative Paths are System Paths - if the first token has no path qualifiers
'              then the token is first checked to see if a key of the same name has
'              been installed under HKLM\Software\Microsoft\Windows\CurrentVersion\App Paths.
'              if the key or default value does not exist, it is assumed to be a child
'              of the system directories.  the following directories will be searched
'              in order for the relative token: { CSIDL_SYSTEM, CSIDL_WINDOWS }
'
'      Prefer Quoted Paths - if the first token in pszCmdTemplate is quoted and appears
'              to be an absolute path then the token is the only possible result.
'
'      Limit Forms of Unquoted Paths - if the first token is unquoted and appears
'              to be an absolute path, then it is subject to more stringent limitations.
'              if the token is a substring of CSIDL_PROGRAM_FILES or does not
'              exist on the file system, then SHEvaluateSystemCommandTemplate() will
'              attempt to complete using a token delimited by the first space of the
'              last valid path segment (usually the file name).  if this token also doesnt exist,
'              then the next space will be used, etc.
'
'  USAGE:      used before calling into CreateProcess() or ShellExecute(), callers
'              would typically look like the following:
' #if 0 ' SAMPLE CODE
'HRESULT MyCreateProcessPriv(PCWSTR pszCmd)
'{
'    PWSTR pszApp;
'    PWSTR pszCmdLine;
'    HRESULT hr = SHEvaluateSystemCommandTemplate(pszCmd, &pszApp, &pszCmdLine);
'    if (SUCCEEDED(hr))
'    {
'        '  if this was a real template, maybe some kind of wnsprintf() first?
'        PROCESS_INFORMATION pi;
'        STARTUPINFO si = {0};
'        si.cb = sizeof(startup);
'        si.wShowWindow = SW_SHOWNORMAL;
'
'        if (CreateProcess(pszApp, pszCmdLine, NULL, NULL, FALSE,
'                 CREATE_DEFAULT_ERROR_MODE, NULL, NULL, &si, &pi))
'        {
'            '  we are good
'            ASSERT(hr == S_OK);
'            CloseHandle(pi.hProcess);
'            CloseHandle(pi.hThread);
'        }
'        else
'        {
'            hr = HRESULT_FROM_WIN32(GetLastError());
'        }
'
'        CoTaskMemFree(pszApp);
'        CoTaskMemFree(pszCmdLine);
'    }
'    return hr;
'}
'
'HRESULT MyShellExec(PCWSTR pszCmd)
'{
'    PWSTR pszApp;
'    PWSTR pszCmdLine;
'    HRESULT hr = SHEvaluateSystemCommandTemplate(pszCmd, &pszApp, &pszCmdLine);
'    if (SUCCEEDED(hr))
'    {
'        '  if this was a real template, maybe some kind of wnsprintf() first?
'        SHELLEXECUTEINFOW sei = {
'            sizeof(sei),           ' cbSize;
'            0,                     ' fMask
'            NULL,                  ' hwnd
'            NULL,                  ' lpVerb
'            pszApp,                ' lpFile
'            PathGetArgs(pszCmdLine), ' lpParameters
'            NULL,                  ' lpDirectory
'            SW_SHOWNORMAL,         ' nShow
'            0,                     ' hInstApp
'            NULL,                  ' lpIDList
'            NULL,                  ' lpClass
'            NULL,                  ' hkeyClass
'            0,                     ' dwHotKey
'            NULL,                  ' hIcon
'            NULL                   ' hProcess
'        };
'
'        if (ShellExecuteEx(&sei))
'        {
'            '  we are good
'            ASSERT(hr == S_OK);
'        }
'        else
'        {
'            hr = HRESULT_FROM_WIN32(GetLastError());
'        }
'
'        CoTaskMemFree(pszApp);
'        CoTaskMemFree(pszCmdLine);
'    }
'    return hr;
'}
'#endif '  0 ' SAMPLE CODE


'  EXAMPLE:   Each example will show an input parameter and the results returned by
'              SHEvaluateSystemCommandTemplate().  Also included is the alternate result
'              of what CreateProcess() would have created if pszCmdTemplate were
'              passed directly as lpCommandLine and lpApplication were NULL.
'              (results marked with an asterisk (*) indicate differences.)
'
'          Assume for the examples that the following paths and values exist:
'
'      SHGetFolderPath() values:
'          CSIDL_SYSTEM            =   C:\windows\system32
'          CSIDL_WINDOWS           =   C:\windows
'          CSIDL_PROGRAM_FILES     =   C:\Program Files
'
'      Environment settings
'          GetModuleFileName(NULL) =   C:\Program Files\Example\sample.exe
'          GetCurrentDirectory()   =   \\server\share\foo
'          HKLM\...\App Paths\pbrush.exe = C:\windows\system32\mspaint.exe
'          HKLM\...\App Paths\mycl.exe = C:\Program Files\Compilers\mycl.exe
'          PATH                    =   c:\windows\system32;C:\windows;c:\;C:\Program Files\Compilers\
'
'      Valid Application paths:
'          C:\Program Files\Internet Explorer\iexplore.exe
'          C:\windows\system32\rundll32.exe
'          C:\windows\system32\notepad.exe
'          C:\windows\notepad.exe
'          C:\Program Files\Example\sample.exe
'          C:\Program Files\Compilers\cl.exe
'          C:\Other Programs\prog.exe
'
'      Suspicious (possibly hostile) Application paths:
'          C:\Program.exe
'          C:\Program Files\Internet.exe
'          C:\Program Files\Example\regedit.bat
'          C:\mycl.exe
'          \\server\share\foo\rundll32.exe
'          \\server\share\foo\myapp.exe
'
'
'  Relative Path Example #1
'      pszCmdTemplate      =   notepad.exe %1
'          SHEvaluateSystemCommandTemplate() returns: S_OK
'              pszApplication  =   C:\windows\system32\notepad.exe
'              pszCommandLine  =   "notepad.exe" %1
'          CreateProcess() would return TRUE
'              new process =   C:\windows\system32\notepad.exe
'
'  Relative Path Example #2
'      pszCmdTemplate      =   rundll32.exe shell32.dll,RunDll
'          SHEvaluateSystemCommandTemplate() returns: S_OK
'              pszApplication  =   C:\windows\system32\rundll32.exe
'              pszCommandLine  =   "rundll32.exe" shell32.dll,RunDll
'          * CreateProcess() would return TRUE
'              new process =   \\server\share\foo\rundll32.exe
'
'  Relative Path Example #3
'      pszCmdTemplate      =   regedit %1
'          SHEvaluateSystemCommandTemplate() returns: S_OK
'              pszApplication  =   C:\windows\system32\regedit.exe
'              pszCommandLine  =   "regedit.exe" %1
'          * CreateProcess() would return TRUE
'              new process =   C:\Program Files\Example\regedit.bat
'
'  Relative Path Example #4
'      pszCmdTemplate      =   pbrush "%1"
'          SHEvaluateSystemCommandTemplate() returns: S_OK
'              pszApplication  =   C:\windows\system32\mspaint.exe
'              pszCommandLine  =   "mspaint.exe" "%1"
'          * CreateProcess() would return FALSE
'
'  Relative Path Example #5
'      pszCmdTemplate      =   mycl "%1" "%2"
'          SHEvaluateSystemCommandTemplate() returns: S_OK
'              pszApplication  =   C:\Program Files\Compilers\mycl.exe
'              pszCommandLine  =   "mycl.exe" "%1" "%2"
'          * CreateProcess() would return TRUE
'              new process =   C:\mycl.exe
'
'  Relative Path Example #6
'      pszCmdTemplate      =   myapp.exe
'          SHEvaluateSystemCommandTemplate() returns: CO_E_APPNOTFOUND
'          * CreateProcess() would return TRUE
'              new process =   \\server\share\foo\myapp.exe
'
'  Quoted Path Example #1
'      pszCmdTemplate      =   "C:\Program Files\Internet Explorer\iexplore.exe" -nohome
'          SHEvaluateSystemCommandTemplate() returns: S_OK
'              pszApplication  =   C:\Program Files\Internet Explorer\iexplore.exe
'              pszCommandLine  =   "C:\Program Files\Internet Explorer\iexplore.exe" -nohome
'          CreateProcess() would return TRUE
'              new process =   C:\Program Files\Internet Explorer\iexplore.exe
'
'  Quoted Path Example #2
'      pszCmdTemplate      =   "C:\Program Files\Internet" -url
'          SHEvaluateSystemCommandTemplate() returns: S_OK
'              pszApplication  =   C:\Program Files\Internet.exe
'              pszCommandLine  =   "C:\Program Files\Internet.exe" -url
'          CreateProcess() would return TRUE
'              new process =   C:\Program Files\internet.exe
'
'  Quoted Path Example #3
'      pszCmdTemplate      =   "C:\Program" -url
'          SHEvaluateSystemCommandTemplate() returns: S_OK
'              pszApplication  =   C:\Program.exe
'              pszCommandLine  =   "C:\Program.exe" -url
'          CreateProcess() would return TRUE
'              new process =   C:\Program.exe
'
'  Unquoted Example #1
'      pszCmdTemplate      =   C:\Program Files\Internet Explorer\iexplore.exe -nohome
'          SHEvaluateSystemCommandTemplate() returns: S_OK
'              pszApplication  =   C:\Program Files\Internet Explorer\iexplore.exe
'              pszCommandLine  =   "C:\Program Files\Internet Explorer\iexplore.exe" -nohome
'          * CreateProcess() would return TRUE
'              new process =   C:\Program.exe
'
'  Unquoted Example #2
'      pszCmdTemplate      =   C:\Program Files\Internet Explorer\iexplore.exe -url fool.htm
'          SHEvaluateSystemCommandTemplate() returns: S_OK
'              pszApplication  =   C:\Program Files\Internet Explorer\iexplore.exe
'              pszCommandLine  =   "C:\Program Files\Internet Explorer\iexplore.exe" -url fool.htm
'          * CreateProcess() would return TRUE
'              new process =   C:\Program.exe
'
'  Unquoted Example #3
'      pszCmdTemplate      =   C:\Program Files\Internet Explorer\iexplore.exe -url C:\fool.htm
'          SHEvaluateSystemCommandTemplate() returns: S_OK
'              pszApplication  =   C:\Program Files\Internet Explorer\iexplore.exe
'              pszCommandLine  =   "C:\Program Files\Internet Explorer\iexplore.exe" -url C:\fool.htm
'          * CreateProcess() would return TRUE
'              new process =   C:\Program.exe
'
'  Unquoted Example #4
'      pszCmdTemplate      =   C:\Program Files\Internet -url
'          SHEvaluateSystemCommandTemplate() returns: S_OK
'              pszApplication  =   C:\Program Files\Internet.exe
'              pszCommandLine  =   "C:\Program Files\Internet.exe" -url
'          * CreateProcess() would return TRUE
'              new process =   C:\Program.exe
'
'  Unquoted Example #5
'      pszCmdTemplate      =   C:\Other Programs\prog.exe -go %1 \fool %2
'          SHEvaluateSystemCommandTemplate() returns: S_OK
'              pszApplication  =   C:\Other Programs\prog.exe
'              pszCommandLine  =   "C:\Other Programs\prog.exe" %1 \fool %2
'          * CreateProcess() would return TRUE
'              new process =   C:\Other Programs\prog.exe
'
'  Unquoted Example #6
'      pszCmdTemplate      =   C:\Other Programs\prog.exe -go "\fool" "%1"
'          SHEvaluateSystemCommandTemplate() returns: S_OK
'              pszApplication  =   C:\Other Programs\prog.exe
'              pszCommandLine  =   "C:\Other Programs\prog.exe" -go "\fool" "%1"
'          * CreateProcess() would return TRUE
'              new process =   C:\Other Programs\prog.exe
'
'  Unquoted Example #7
'      pszCmdTemplate      =   C:\Program Files\Internet Explorer\iexplore.exe -url \fool.htm
'          SHEvaluateSystemCommandTemplate() returns: CO_E_APPNOTFOUND
'          * CreateProcess() would return TRUE
'              new process =   C:\Program.exe
'
'  Unquoted Example #8
'      pszCmdTemplate      =   C:\Program -url
'          SHEvaluateSystemCommandTemplate() returns: CO_E_APPNOTFOUND
'          * CreateProcess() would return TRUE
'              new process =   C:\Program.exe
'
'  Unquoted Example #9
'      pszCmdTemplate      =   C:\Other Programs\prog.exe -go \fool us
'          SHEvaluateSystemCommandTemplate() returns: CO_E_APPNOTFOUND
'          * CreateProcess() would return TRUE
'              new process =   C:\Other Programs\prog.exe
'
'  Unquoted Example #10
'      pszCmdTemplate      =   C:\Other Programs\prog.exe -go \fool %1
'          SHEvaluateSystemCommandTemplate() returns: CO_E_APPNOTFOUND
'          * CreateProcess() would return TRUE
'              new process =   C:\Other Programs\prog.exe
'
'  Unquoted Example #11
'      pszCmdTemplate      =   C:\Program "%1"
'          SHEvaluateSystemCommandTemplate() returns: E_ACCESSDENIED
'          * CreateProcess() would return TRUE
'              new process =   C:\Program.exe
'
'  Unquoted Example #12
'      pszCmdTemplate      =   C:\Program
'          SHEvaluateSystemCommandTemplate() returns: E_ACCESSDENIED
'          * CreateProcess() would return TRUE
'              new process =   C:\Program.exe
'

'  used for implementing IShellFolder::GetUIObject(IID_IQueryAssociations)
'  designed for namespace extensions with registered extensible types
'  SHCreateDefaultContextMenu() and others use IQueryAssociations to build up data sets

MACRO ASSOCCLASS_enum=LONG
ENUM ASSOCCLASS SINGULAR
                                '  which other members are used
    ASSOCCLASS_SHELL_KEY        '  hkeyClass
    ASSOCCLASS_PROGID_KEY       '  hkeyClass
    ASSOCCLASS_PROGID_STR       '  pszClass (HKCR\pszClass)
    ASSOCCLASS_CLSID_KEY        '  hkeyClass
    ASSOCCLASS_CLSID_STR        '  pszClass (HKCR\CLSID\pszClass)
    ASSOCCLASS_APP_KEY          '  hkeyClass
    ASSOCCLASS_APP_STR          '  pszClass (HKCR\Applications\PathFindFileName(pszClass))
    ASSOCCLASS_SYSTEM_STR       '  pszClass
    ASSOCCLASS_FOLDER           '  none
    ASSOCCLASS_STAR             '  none
END ENUM

TYPE ASSOCIATIONELEMENT
    ac       AS ASSOCCLASS_enum  ' required
    hkClass  AS DWORD            ' HKEY ' may be NULL
    pszClass AS WSTRINGZ PTR     ' may be NULL
END TYPE

' the object returned from this API implements IQueryAssociations

DECLARE FUNCTION AssocCreateForClasses LIB "Shell32.dll" _
    ALIAS "AssocCreateForClasses" (BYVAL rgClasses AS ASSOCIATIONELEMENT PTR, _
    BYVAL cClasses AS DWORD, riid AS GUID, ppv AS DWORD) AS LONG  ' HRESULT

' #if 0 ' SAMPLE CODE
'HRESULT CCustomFolder::_AssocCreate(PCUITEMID_CHILD pidl, REFIID riid, void **ppv)
'{
'    *ppv = NULL;
'    ASSOCIATIONELEMENT rgAssoc[] =
'    {
'        { ASSOCCLASS_PROGID_STR, NULL, CCustomFolder::_MapChildToType(pidl)},
'        { ASSOCCLASS_FOLDER, NULL, NULL},
'    };
'    if (CCustomFolder::_IsFolder(pidl))
'    {
'        return AssocCreateForClasses(rgAssoc, ARRAYSIZE(rgAssoc), riid, ppv);
'    }
'    else
'    {
'        '  skip FOLDER at the end
'        return AssocCreateForClasses(rgAssoc, ARRAYSIZE(rgAssoc)-1, riid, ppv);
'    }
'}
'
'HRESULT CCustomFolder::GetUIObjectOf(...)
'{
'    '  validate parameters
'    if (riid == IID_IQueryAssociations)
'    {
'        hr = _AssocCreate(apidl[0], riid, ppv);
'    }
'    '  else if ...
'}
'#endif ' SAMPLE CODE


#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)

''
''  End ShellExecuteEx and family
''

#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)
'
' RecycleBin
'

' struct for query recycle bin info
TYPE SHQUERYRBINFO
    cbSize      AS DWORD
#IF NOT %DEF(%MAC) OR %DEF(%MAC_INT_64)
    i64Size     AS QUAD  ' __int64
    i64NumItems AS QUAD  ' __int64
#ELSE
    i64Size     AS QUAD  ' DWORDLONG
    i64NumItems AS QUAD  ' DWORDLONG
#ENDIF
END TYPE


' flags for SHEmptyRecycleBin
'
%SHERB_NOCONFIRMATION  = &H00000001
%SHERB_NOPROGRESSUI    = &H00000002
%SHERB_NOSOUND         = &H00000004


DECLARE FUNCTION SHQueryRecycleBinA LIB "Shell32.dll" _
    ALIAS "SHQueryRecycleBinA" ( _
    pszRootPath AS ASCIIZ, pSHQueryRBInfo AS SHQUERYRBINFO) AS LONG  ' HRESULT

DECLARE FUNCTION SHQueryRecycleBinW LIB "Shell32.dll" _
    ALIAS "SHQueryRecycleBinW" ( _
    pszRootPath AS WSTRINGZ, pSHQueryRBInfo AS SHQUERYRBINFO) AS LONG  ' HRESULT

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHQueryRecycleBin LIB "Shell32.dll" _
    ALIAS "SHQueryRecycleBinW" ( _
    pszRootPath AS WSTRINGZ, pSHQueryRBInfo AS SHQUERYRBINFO) AS LONG  ' HRESULT
#ELSE
DECLARE FUNCTION SHQueryRecycleBin LIB "Shell32.dll" _
    ALIAS "SHQueryRecycleBinA" ( _
    pszRootPath AS ASCIIZ, pSHQueryRBInfo AS SHQUERYRBINFO) AS LONG  ' HRESULT
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SHEmptyRecycleBinA LIB "Shell32.dll" _
    ALIAS "SHEmptyRecycleBinA" (BYVAL hwnd AS DWORD, pszRootPath AS ASCIIZ, _
    BYVAL dwFlags AS DWORD) AS LONG  ' HRESULT

DECLARE FUNCTION SHEmptyRecycleBinW LIB "Shell32.dll" _
    ALIAS "SHEmptyRecycleBinW" (BYVAL hwnd AS DWORD, pszRootPath AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD) AS LONG  ' HRESULT

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHEmptyRecycleBin LIB "Shell32.dll" _
    ALIAS "SHEmptyRecycleBinW" (BYVAL hwnd AS DWORD, pszRootPath AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD) AS LONG  ' HRESULT
#ELSE
DECLARE FUNCTION SHEmptyRecycleBin LIB "Shell32.dll" _
    ALIAS "SHEmptyRecycleBinA" (BYVAL hwnd AS DWORD, pszRootPath AS ASCIIZ, _
    BYVAL dwFlags AS DWORD) AS LONG  ' HRESULT
#ENDIF ' NOT %UNICODE

''
'' end of RecycleBin
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WIN2K)


''
'' Taskbar notification definitions
''

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
MACRO QUERY_USER_NOTIFICATION_STATE_enum=LONG
ENUM QUERY_USER_NOTIFICATION_STATE SINGULAR
    QUNS_NOT_PRESENT        = 1     ' The user is not present.  Heuristic check for modes like: screen saver, locked machine, non-active FUS session
    QUNS_BUSY                       ' The user is busy.  Heuristic check for modes like: full-screen app
    QUNS_RUNNING_D3D_FULL_SCREEN    ' full-screen (exlusive-mode) D3D app
    QUNS_PRESENTATION_MODE          ' Windows presentation mode (laptop feature) is turned on
    QUNS_ACCEPTS_NOTIFICATIONS      ' notifications can be freely sent
#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
    QUNS_QUIET_TIME                 ' We are in OOBE quiet period
#ENDIF
END ENUM

DECLARE FUNCTION SHQueryUserNotificationState LIB "Shell32.dll" _
    ALIAS "SHQueryUserNotificationState" _
    (pquns AS QUERY_USER_NOTIFICATION_STATE_enum) AS LONG  ' HRESULT

#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)

#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
' This api retrieves an IPropertyStore that stores the window's properties.
DECLARE FUNCTION SHGetPropertyStoreForWindow LIB "Shell32.dll" _
    ALIAS "SHGetPropertyStoreForWindow" (BYVAL hwnd AS DWORD, riid AS GUID, _
    ppv AS DWORD) AS LONG  ' HRESULT
#ENDIF


UNION NOTIFYICONDATA_union
    uTimeout AS DWORD
    uVersion AS DWORD    ' used with NIM_SETVERSION, values 0, 3 and 4
END UNION

TYPE NOTIFYICONDATAA
    cbSize           AS DWORD
    hWnd             AS DWORD  ' HWND
    uID              AS DWORD
    uFlags           AS DWORD
    uCallbackMessage AS DWORD
    hIcon            AS DWORD  ' HICON
#IF (%NTDDI_VERSION < %NTDDI_WIN2K)
    szTip            AS ASCIIZ * 64
#ENDIF
#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)
    szTip            AS ASCIIZ * 128
    dwState          AS DWORD
    dwStateMask      AS DWORD
    szInfo           AS ASCIIZ * 256
    NOTIFYICONDATA_union
    szInfoTitle      AS ASCIIZ * 64
    dwInfoFlags      AS DWORD
#ENDIF
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
    guidItem         AS GUID
#ENDIF
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
    hBalloonIcon     AS DWORD  ' HICON
#ENDIF
END TYPE

TYPE NOTIFYICONDATAW
    cbSize           AS DWORD
    hWnd             AS DWORD  ' HWND
    uID              AS DWORD
    uFlags           AS DWORD
    uCallbackMessage AS DWORD
    hIcon            AS DWORD  ' HICON
#IF (%NTDDI_VERSION < %NTDDI_WIN2K)
    szTip            AS WSTRINGZ * 64
#ENDIF
#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)
    szTip            AS WSTRINGZ * 128
    dwState          AS DWORD
    dwStateMask      AS DWORD
    szInfo           AS WSTRINGZ * 256
    NOTIFYICONDATA_union
    szInfoTitle      AS WSTRINGZ * 64
    dwInfoFlags      AS DWORD
#ENDIF
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
    guidItem         AS GUID
#ENDIF
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
    hBalloonIcon     AS DWORD  ' HICON
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
TYPE NOTIFYICONDATA
    NOTIFYICONDATAW
END TYPE
#ELSE
TYPE NOTIFYICONDATA
    NOTIFYICONDATAA
END TYPE
#ENDIF ' UNICODE


#IF %NTDDI_VERSION < %NTDDI_WIN2K
%NOTIFYICONDATAA_V1_SIZE=4+4+4+4+4+4+64 ' FIELD_OFFSET(NOTIFYICONDATAA, szTip[64])
%NOTIFYICONDATAW_V1_SIZE=4+4+4+4+4+4+64*2 ' FIELD_OFFSET(NOTIFYICONDATAW, szTip[64])
#ELSE
%NOTIFYICONDATAA_V1_SIZE=4+4+4+4+4+4+128 ' FIELD_OFFSET(NOTIFYICONDATAA, szTip[64])
%NOTIFYICONDATAW_V1_SIZE=4+4+4+4+4+4+128*2 ' FIELD_OFFSET(NOTIFYICONDATAW, szTip[64])
#ENDIF
#IF %DEF(%UNICODE)
%NOTIFYICONDATA_V1_SIZE = %NOTIFYICONDATAW_V1_SIZE
#ELSE
%NOTIFYICONDATA_V1_SIZE = %NOTIFYICONDATAA_V1_SIZE
#ENDIF

%NOTIFYICONDATAA_V2_SIZE = %NOTIFYICONDATAA_V1_SIZE + 4+4+256+64+4+16 ' FIELD_OFFSET(NOTIFYICONDATAA, guidItem)
%NOTIFYICONDATAW_V2_SIZE = %NOTIFYICONDATAW_V1_SIZE + 4+4+512+128+4+16 ' FIELD_OFFSET(NOTIFYICONDATAW, guidItem)
#IF %DEF(%UNICODE)
%NOTIFYICONDATA_V2_SIZE = %NOTIFYICONDATAW_V2_SIZE
#ELSE
%NOTIFYICONDATA_V2_SIZE = %NOTIFYICONDATAA_V2_SIZE
#ENDIF

%NOTIFYICONDATAA_V3_SIZE = %NOTIFYICONDATAA_V2_SIZE + 4 ' FIELD_OFFSET(NOTIFYICONDATAA, hBalloonIcon)
%NOTIFYICONDATAW_V3_SIZE = %NOTIFYICONDATAW_V2_SIZE + 4 ' FIELD_OFFSET(NOTIFYICONDATAW, hBalloonIcon)
#IF %DEF(%UNICODE)
%NOTIFYICONDATA_V3_SIZE = %NOTIFYICONDATAW_V3_SIZE
#ELSE
%NOTIFYICONDATA_V3_SIZE = %NOTIFYICONDATAA_V3_SIZE
#ENDIF


#IF (%WIN32_IE >= &H0500)
%NIN_SELECT         = (%WM_USER + 0)
%NINF_KEY           = &H1
%NIN_KEYSELECT      = (%NIN_SELECT OR %NINF_KEY)
#ENDIF

#IF (%WIN32_IE >= &H0501)
%NIN_BALLOONSHOW         = (%WM_USER + 2)
%NIN_BALLOONHIDE         = (%WM_USER + 3)
%NIN_BALLOONTIMEOUT      = (%WM_USER + 4)
%NIN_BALLOONUSERCLICK    = (%WM_USER + 5)
#ENDIF
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%NIN_POPUPOPEN           = (%WM_USER + 6)
%NIN_POPUPCLOSE          = (%WM_USER + 7)
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)


%NIM_ADD        = &H00000000
%NIM_MODIFY     = &H00000001
%NIM_DELETE     = &H00000002
#IF (%WIN32_IE >= &H0500)
%NIM_SETFOCUS   = &H00000003
%NIM_SETVERSION = &H00000004


' set NOTIFYICONDATA.uVersion with 0, 3 or 4
' please read the documentation on the behavior difference that the different versions imply
%NOTIFYICON_VERSION    = 3
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%NOTIFYICON_VERSION_4  = 4
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)
#ENDIF

%NIF_MESSAGE   = &H00000001
%NIF_ICON      = &H00000002
%NIF_TIP       = &H00000004
#IF (%WIN32_IE >= &H0500)
%NIF_STATE     = &H00000008
%NIF_INFO      = &H00000010
#ENDIF
#IF (%WIN32_IE >= &H600)
%NIF_GUID      = &H00000020
#ENDIF
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%NIF_REALTIME  = &H00000040
%NIF_SHOWTIP   = &H00000080
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)

#IF (%WIN32_IE >= &H0500)
%NIS_HIDDEN            = &H00000001
%NIS_SHAREDICON        = &H00000002

' says this is the source of a shared icon

' Notify Icon Infotip flags
%NIIF_NONE     = &H00000000
' icon flags are mutually exclusive
' and take only the lowest 2 bits
%NIIF_INFO     = &H00000001
%NIIF_WARNING  = &H00000002
%NIIF_ERROR    = &H00000003
' [appears to be a bug. assuming NTDDI_WINXPSP2.]
'#if (%NTDDI_VERSION >= %NTDDI_XPSP2) ' also available in %NTDDI_WS03SP1
#IF (%NTDDI_VERSION >= %NTDDI_WINXPSP2) ' also available in %NTDDI_WS03SP1
%NIIF_USER     = &H00000004
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_[WIN]XPSP2)
%NIIF_ICON_MASK = &H0000000F
#IF (%WIN32_IE >= &H0501)
%NIIF_NOSOUND  = &H00000010
#ENDIF
#ENDIF
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%NIIF_LARGE_ICON = &H00000020
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)

#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
%NIIF_RESPECT_QUIET_TIME = &H00000080
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WIN7)


TYPE NOTIFYICONIDENTIFIER
    cbSize   AS DWORD
    hWnd     AS DWORD  ' HWND
    uID      AS DWORD
    guidItem AS GUID
END TYPE


DECLARE FUNCTION Shell_NotifyIconA LIB "Shell32.dll" _
    ALIAS "Shell_NotifyIconA" (BYVAL dwMessage AS DWORD, _
    lpData AS NOTIFYICONDATAA) AS LONG

DECLARE FUNCTION Shell_NotifyIconW LIB "Shell32.dll" _
    ALIAS "Shell_NotifyIconW" (BYVAL dwMessage AS DWORD, _
    lpData AS NOTIFYICONDATAW) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION Shell_NotifyIcon LIB "Shell32.dll" _
    ALIAS "Shell_NotifyIconW" (BYVAL dwMessage AS DWORD, _
    lpData AS NOTIFYICONDATAW) AS LONG
#ELSE
DECLARE FUNCTION Shell_NotifyIcon LIB "Shell32.dll" _
    ALIAS "Shell_NotifyIconA" (BYVAL dwMessage AS DWORD, _
    lpData AS NOTIFYICONDATAA) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION Shell_NotifyIconGetRect LIB "Shell32.dll" _
    ALIAS "Shell_NotifyIconGetRect" (identifier AS NOTIFYICONIDENTIFIER, _
    iconLocation AS RECT) AS LONG  ' HRESULT

''
'' End Taskbar Notification Icons
''

#IF NOT %DEF(%SHFILEINFO_DEFINED)
%SHFILEINFO_DEFINED = 1
''
'' Begin SHGetFileInfo
''

'
' The SHGetFileInfo API provides an easy way to get attributes
' for a file given a pathname.
'
'   PARAMETERS
'
'     pszPath              file name to get info about
'     dwFileAttributes     file attribs, only used with SHGFI_USEFILEATTRIBUTES
'     psfi                 place to return file info
'     cbFileInfo           size of structure
'     uFlags               flags
'
'   RETURN
'     TRUE if things worked


TYPE SHFILEINFOA
    hIcon         AS DWORD  ' HICON      ' out: icon
    iIcon         AS LONG                ' out: icon index
    dwAttributes  AS DWORD               ' out: SFGAO_ flags
    szDisplayName AS ASCIIZ * %MAX_PATH  ' out: display name (or path)
    szTypeName    AS ASCIIZ * 80         ' out: type name
END TYPE

TYPE SHFILEINFOW
    hIcon         AS DWORD  ' HICON       ' out: icon
    iIcon         AS LONG                 ' out: icon index
    dwAttributes  AS DWORD                ' out: SFGAO_ flags
    szDisplayName AS WSTRINGZ * %MAX_PATH ' out: display name (or path)
    szTypeName    AS WSTRINGZ * 80        ' out: type name
END TYPE

#IF %DEF(%UNICODE)
TYPE SHFILEINFO
    SHFILEINFOW
END TYPE
#ELSE
TYPE SHFILEINFO
    SHFILEINFOA
END TYPE
#ENDIF ' UNICODE


' NOTE: This is also in shlwapi.h.  Please keep in synch.
#ENDIF ' NOT %SHFILEINFO_DEFINED

%SHGFI_ICON            = &H000000100     ' get icon
%SHGFI_DISPLAYNAME     = &H000000200     ' get display name
%SHGFI_TYPENAME        = &H000000400     ' get type name
%SHGFI_ATTRIBUTES      = &H000000800     ' get attributes
%SHGFI_ICONLOCATION    = &H000001000     ' get icon location
%SHGFI_EXETYPE         = &H000002000     ' return exe type
%SHGFI_SYSICONINDEX    = &H000004000     ' get system icon index
%SHGFI_LINKOVERLAY     = &H000008000     ' put a link overlay on icon
%SHGFI_SELECTED        = &H000010000     ' show icon in selected state
#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)
%SHGFI_ATTR_SPECIFIED  = &H000020000     ' get only specified attributes
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WIN2K)
%SHGFI_LARGEICON       = &H000000000     ' get large icon
%SHGFI_SMALLICON       = &H000000001     ' get small icon
%SHGFI_OPENICON        = &H000000002     ' get open icon
%SHGFI_SHELLICONSIZE   = &H000000004     ' get shell size icon
%SHGFI_PIDL            = &H000000008     ' pszPath is a pidl
%SHGFI_USEFILEATTRIBUTES = &H000000010   ' use passed dwFileAttribute

#IF (%WIN32_IE >= &H0500)
%SHGFI_ADDOVERLAYS     = &H000000020     ' apply the appropriate overlays
%SHGFI_OVERLAYINDEX    = &H000000040     ' Get the index of the overlay
                                                ' in the upper 8 bits of the iIcon
#ENDIF

DECLARE FUNCTION SHGetFileInfoA LIB "Shell32.dll" ALIAS "SHGetFileInfoA" ( _
    pszPath AS ASCIIZ, BYVAL dwFileAttributes AS DWORD, psfi AS SHFILEINFOA, _
    BYVAL cbFileInfo AS DWORD, BYVAL uFlags AS DWORD) AS DWORD

DECLARE FUNCTION SHGetFileInfoW LIB "Shell32.dll" ALIAS "SHGetFileInfoW" ( _
    pszPath AS WSTRINGZ, BYVAL dwFileAttributes AS DWORD, _
    psfi AS SHFILEINFOW, BYVAL cbFileInfo AS DWORD, BYVAL uFlags AS DWORD) _
    AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHGetFileInfo LIB "Shell32.dll" ALIAS "SHGetFileInfoW" ( _
    pszPath AS WSTRINGZ, BYVAL dwFileAttributes AS DWORD, _
    psfi AS SHFILEINFOW, BYVAL cbFileInfo AS DWORD, BYVAL uFlags AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION SHGetFileInfo LIB "Shell32.dll" ALIAS "SHGetFileInfoA" ( _
    pszPath AS ASCIIZ, BYVAL dwFileAttributes AS DWORD, psfi AS SHFILEINFOA, _
    BYVAL cbFileInfo AS DWORD, BYVAL uFlags AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
TYPE SHSTOCKICONINFO
    cbSize         AS DWORD
    hIcon          AS DWORD  ' HICON
    iSysImageIndex AS LONG
    iIcon          AS LONG
    szPath         AS WSTRINGZ * %MAX_PATH
END TYPE

%SHGSI_ICONLOCATION   = 0 ' you always get the icon location
%SHGSI_ICON           = %SHGFI_ICON
%SHGSI_SYSICONINDEX   = %SHGFI_SYSICONINDEX
%SHGSI_LINKOVERLAY    = %SHGFI_LINKOVERLAY
%SHGSI_SELECTED       = %SHGFI_SELECTED
%SHGSI_LARGEICON      = %SHGFI_LARGEICON
%SHGSI_SMALLICON      = %SHGFI_SMALLICON
%SHGSI_SHELLICONSIZE  = %SHGFI_SHELLICONSIZE

'  Shell icons


MACRO SHSTOCKICONID_enum=LONG
ENUM SHSTOCKICONID SINGULAR
    SIID_DOCNOASSOC               ' document (blank page), no associated program
    SIID_DOCASSOC                 ' document with an associated program
    SIID_APPLICATION              ' generic application with no custom icon
    SIID_FOLDER                   ' folder (closed)
    SIID_FOLDEROPEN               ' folder (open)
    SIID_DRIVE525                 ' 5.25" floppy disk drive
    SIID_DRIVE35                  ' 3.5" floppy disk drive
    SIID_DRIVEREMOVE              ' removable drive
    SIID_DRIVEFIXED               ' fixed (hard disk) drive
    SIID_DRIVENET                 ' network drive
    SIID_DRIVENETDISABLED         ' disconnected network drive
    SIID_DRIVECD                  ' CD drive
    SIID_DRIVERAM                 ' RAM disk drive
    SIID_WORLD                    ' entire network
    SIID_reserved1
    SIID_SERVER                   ' a computer on the network
    SIID_PRINTER                  ' printer
    SIID_MYNETWORK                ' My network places
    SIID_FIND                = 22 ' Find
    SIID_HELP                     ' Help
    SIID_SHARE               = 28 ' overlay for shared items
    SIID_LINK                     ' overlay for shortcuts to items
    SIID_SLOWFILE                 ' overlay for slow items
    SIID_RECYCLER                 ' empty recycle bin
    SIID_RECYCLERFULL             ' full recycle bin
    SIID_MEDIACDAUDIO        = 40 ' Audio CD Media
    SIID_LOCK                = 47 ' Security lock
    SIID_AUTOLIST            = 49 ' AutoList
    SIID_PRINTERNET               ' Network printer
    SIID_SERVERSHARE              ' Server share
    SIID_PRINTERFAX               ' Fax printer
    SIID_PRINTERFAXNET            ' Networked Fax Printer
    SIID_PRINTERFILE              ' Print to File
    SIID_STACK                    ' Stack
    SIID_MEDIASVCD                ' SVCD Media
    SIID_STUFFEDFOLDER            ' Folder containing other items
    SIID_DRIVEUNKNOWN             ' Unknown drive
    SIID_DRIVEDVD                 ' DVD Drive
    SIID_MEDIADVD                 ' DVD Media
    SIID_MEDIADVDRAM              ' DVD-RAM Media
    SIID_MEDIADVDRW               ' DVD-RW Media
    SIID_MEDIADVDR                ' DVD-R Media
    SIID_MEDIADVDROM              ' DVD-ROM Media
    SIID_MEDIACDAUDIOPLUS         ' CD+ (Enhanced CD) Media
    SIID_MEDIACDRW                ' CD-RW Media
    SIID_MEDIACDR                 ' CD-R Media
    SIID_MEDIACDBURN              ' Burning CD
    SIID_MEDIABLANKCD             ' Blank CD Media
    SIID_MEDIACDROM               ' CD-ROM Media
    SIID_AUDIOFILES               ' Audio files
    SIID_IMAGEFILES               ' Image files
    SIID_VIDEOFILES               ' Video files
    SIID_MIXEDFILES               ' Mixed files
    SIID_FOLDERBACK               ' Folder back
    SIID_FOLDERFRONT              ' Folder front
    SIID_SHIELD                   ' Security shield. Use for UAC prompts only.
    SIID_WARNING                  ' Warning
    SIID_INFO                     ' Informational
    SIID_ERROR                    ' Error
    SIID_KEY                      ' Key / Secure
    SIID_SOFTWARE                 ' Software
    SIID_RENAME                   ' Rename
    SIID_DELETE                   ' Delete
    SIID_MEDIAAUDIODVD            ' Audio DVD Media
    SIID_MEDIAMOVIEDVD            ' Movie DVD Media
    SIID_MEDIAENHANCEDCD          ' Enhanced CD Media
    SIID_MEDIAENHANCEDDVD         ' Enhanced DVD Media
    SIID_MEDIAHDDVD               ' HD-DVD Media
    SIID_MEDIABLURAY              ' BluRay Media
    SIID_MEDIAVCD                 ' VCD Media
    SIID_MEDIADVDPLUSR            ' DVD+R Media
    SIID_MEDIADVDPLUSRW           ' DVD+RW Media
    SIID_DESKTOPPC                ' desktop computer
    SIID_MOBILEPC                 ' mobile computer (laptop/notebook)
    SIID_USERS                    ' users
    SIID_MEDIASMARTMEDIA          ' Smart Media
    SIID_MEDIACOMPACTFLASH        ' Compact Flash
    SIID_DEVICECELLPHONE          ' Cell phone
    SIID_DEVICECAMERA             ' Camera
    SIID_DEVICEVIDEOCAMERA        ' Video camera
    SIID_DEVICEAUDIOPLAYER        ' Audio player
    SIID_NETWORKCONNECT           ' Connect to network
    SIID_INTERNET                 ' Internet
    SIID_ZIPFILE                  ' ZIP file
    SIID_SETTINGS                 ' Settings
    ' 107-131 are internal Vista RTM icons
    ' 132-159 for SP1 icons
    SIID_DRIVEHDDVD         = 132 ' HDDVD Drive (all types)
    SIID_DRIVEBD                  ' BluRay Drive (all types)
    SIID_MEDIAHDDVDROM            ' HDDVD-ROM Media
    SIID_MEDIAHDDVDR              ' HDDVD-R Media
    SIID_MEDIAHDDVDRAM            ' HDDVD-RAM Media
    SIID_MEDIABDROM               ' BluRay ROM Media
    SIID_MEDIABDR                 ' BluRay R Media
    SIID_MEDIABDRE                ' BluRay RE Media (Rewriable and RAM)
    SIID_CLUSTEREDDRIVE           ' Clustered disk
    ' 160+ are for Windows 7 icons
    SIID_MAX_ICONS          = 174
END ENUM  ' SHSTOCKICONID

%SIID_INVALID = -1  ' ((SHSTOCKICONID)-1)

DECLARE FUNCTION SHGetStockIconInfo LIB "Shell32.dll" _
    ALIAS "SHGetStockIconInfo" (BYVAL siid AS SHSTOCKICONID_enum, _
    BYVAL uFlags AS DWORD, psii AS SHSTOCKICONINFO) AS LONG  ' HRESULT

#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)


#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)

DECLARE FUNCTION SHGetDiskFreeSpaceExA LIB "Shell32.dll" _
    ALIAS "SHGetDiskFreeSpaceExA" (pszDirectoryName AS ASCIIZ, _
    pulFreeBytesAvailableToCaller AS QUAD, _
    pulTotalNumberOfBytes AS QUAD, _
    pulTotalNumberOfFreeBytes AS QUAD) AS LONG

DECLARE FUNCTION SHGetDiskFreeSpaceExW LIB "Shell32.dll" _
    ALIAS "SHGetDiskFreeSpaceExW" (pszDirectoryName AS WSTRINGZ, _
    pulFreeBytesAvailableToCaller AS QUAD, _
    pulTotalNumberOfBytes AS QUAD, _
    pulTotalNumberOfFreeBytes AS QUAD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHGetDiskFreeSpaceEx LIB "Shell32.dll" _
    ALIAS "SHGetDiskFreeSpaceExW" (pszDirectoryName AS WSTRINGZ, _
    pulFreeBytesAvailableToCaller AS QUAD, _
    pulTotalNumberOfBytes AS QUAD, _
    pulTotalNumberOfFreeBytes AS QUAD) AS LONG
DECLARE FUNCTION SHGetDiskFreeSpace LIB "Shell32.dll" _
    ALIAS "SHGetDiskFreeSpaceExW" (pszDirectoryName AS WSTRINGZ, _
    pulFreeBytesAvailableToCaller AS QUAD, _
    pulTotalNumberOfBytes AS QUAD, _
    pulTotalNumberOfFreeBytes AS QUAD) AS LONG
#ELSE
DECLARE FUNCTION SHGetDiskFreeSpaceEx LIB "Shell32.dll" _
    ALIAS "SHGetDiskFreeSpaceExA" (pszDirectoryName AS ASCIIZ, _
    pulFreeBytesAvailableToCaller AS QUAD, _
    pulTotalNumberOfBytes AS QUAD, _
    pulTotalNumberOfFreeBytes AS QUAD) AS LONG
DECLARE FUNCTION SHGetDiskFreeSpace LIB "Shell32.dll" _
    ALIAS "SHGetDiskFreeSpaceExA" (pszDirectoryName AS ASCIIZ, _
    pulFreeBytesAvailableToCaller AS QUAD, _
    pulTotalNumberOfBytes AS QUAD, _
    pulTotalNumberOfFreeBytes AS QUAD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SHGetNewLinkInfoA LIB "Shell32.dll" _
    ALIAS "SHGetNewLinkInfoA" (pszLinkTo AS ASCIIZ, pszDir AS ASCIIZ, _
    pszName AS ASCIIZ, pfMustCopy AS LONG, BYVAL uFlags AS DWORD) AS LONG

DECLARE FUNCTION SHGetNewLinkInfoW LIB "Shell32.dll" _
    ALIAS "SHGetNewLinkInfoW" (pszLinkTo AS WSTRINGZ, pszDir AS WSTRINGZ, _
    pszName AS WSTRINGZ, pfMustCopy AS LONG, BYVAL uFlags AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHGetNewLinkInfo LIB "Shell32.dll" _
    ALIAS "SHGetNewLinkInfoW" (pszLinkTo AS WSTRINGZ, pszDir AS WSTRINGZ, _
    pszName AS WSTRINGZ, pfMustCopy AS LONG, BYVAL uFlags AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SHGetNewLinkInfo LIB "Shell32.dll" _
    ALIAS "SHGetNewLinkInfoA" (pszLinkTo AS ASCIIZ, pszDir AS ASCIIZ, _
    pszName AS ASCIIZ, pfMustCopy AS LONG, BYVAL uFlags AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

%SHGNLI_PIDL           = &H000000001     ' pszLinkTo is a pidl
%SHGNLI_PREFIXNAME     = &H000000002     ' Make name "Shortcut to xxx"
%SHGNLI_NOUNIQUE       = &H000000004     ' don't do the unique name generation
#IF (%WIN32_IE >= &H0501)
%SHGNLI_NOLNK          = &H000000008     ' don't add ".lnk" extension
#ENDIF ' _WIN2_IE >= &H0501
#IF (%WIN32_IE >= &H0600)
%SHGNLI_NOLOCNAME      = &H000000010     ' use non localized (parsing) name from the target
#ENDIF
#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
%SHGNLI_USEURLEXT      = &H000000020     ' use ".url" extension instead of ".lnk"
#ENDIF
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WIN2K)


#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)
%PRINTACTION_OPEN             = 0   ' pszBuf1:<PrinterName>
%PRINTACTION_PROPERTIES       = 1   ' pszBuf1:<PrinterName>, pszBuf2:optional <PageName>
%PRINTACTION_NETINSTALL       = 2   ' pszBuf1:<NetPrinterName>
%PRINTACTION_NETINSTALLLINK   = 3   ' pszBuf1:<NetPrinterName>, pszBuf2:<path to store link>
%PRINTACTION_TESTPAGE         = 4   ' pszBuf1:<PrinterName>
%PRINTACTION_OPENNETPRN       = 5   ' pszBuf1:<NetPrinterName>
%PRINTACTION_DOCUMENTDEFAULTS = 6   ' pszBuf1:<PrinterName>
%PRINTACTION_SERVERPROPERTIES = 7   ' pszBuf1:<Server> or <NetPrinterName>

' deprecated, instead invoke verbs on printers/netprinters using IContextMenu or ShellExecute()

DECLARE FUNCTION SHInvokePrinterCommandA LIB "Shell32.dll" _
    ALIAS "SHInvokePrinterCommandA" (BYVAL hwnd AS DWORD, _
    BYVAL uAction AS DWORD, lpBuf1 AS ASCIIZ, lpBuf2 AS ASCIIZ, _
    BYVAL fModal AS LONG) AS LONG

DECLARE FUNCTION SHInvokePrinterCommandW LIB "Shell32.dll" _
    ALIAS "SHInvokePrinterCommandW" (BYVAL hwnd AS DWORD, _
    BYVAL uAction AS DWORD, lpBuf1 AS WSTRINGZ, lpBuf2 AS WSTRINGZ, _
    BYVAL fModal AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHInvokePrinterCommand LIB "Shell32.dll" _
    ALIAS "SHInvokePrinterCommandW" (BYVAL hwnd AS DWORD, _
    BYVAL uAction AS DWORD, lpBuf1 AS WSTRINGZ, lpBuf2 AS WSTRINGZ, _
    BYVAL fModal AS LONG) AS LONG
#ELSE
DECLARE FUNCTION SHInvokePrinterCommand LIB "Shell32.dll" _
    ALIAS "SHInvokePrinterCommandA" (BYVAL hwnd AS DWORD, _
    BYVAL uAction AS DWORD, lpBuf1 AS ASCIIZ, lpBuf2 AS ASCIIZ, _
    BYVAL fModal AS LONG) AS LONG
#ENDIF ' NOT %UNICODE
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WIN2K)

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

TYPE OPEN_PRINTER_PROPS_INFOA
    dwSize       AS DWORD
    pszSheetName AS ASCIIZ PTR
    uSheetIndex  AS DWORD
    dwFlags      AS DWORD
    bModal       AS LONG  ' BOOL
END TYPE

TYPE OPEN_PRINTER_PROPS_INFOW
    dwSize       AS DWORD
    pszSheetName AS WSTRINGZ PTR
    uSheetIndex  AS DWORD
    dwFlags      AS DWORD
    bModal       AS LONG  ' BOOL
END TYPE

#IF %DEF(%UNICODE)
TYPE OPEN_PRINTER_PROPS_INFO
    OPEN_PRINTER_PROPS_INFOW
END TYPE
#ELSE
TYPE OPEN_PRINTER_PROPS_INFO
    OPEN_PRINTER_PROPS_INFOA
END TYPE
#ENDIF ' UNICODE
%PRINT_PROP_FORCE_NAME = &H01
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WIN2K)


#ENDIF ' WINVER >= &H0400

#IF (%WIN32_WINNT >= &H0500) OR (%WIN32_WINDOWS >= &H0500)

'
' The SHLoadNonloadedIconOverlayIdentifiers API causes the shell's
' icon overlay manager to load any registered icon overlay
' identifers that are not currently loaded.  This is useful if an
' overlay identifier did not load at shell startup but is needed
' and can be loaded at a later time.  Identifiers already loaded
' are not affected.  Overlay identifiers implement the
' IShellIconOverlayIdentifier interface.
'
' Returns:
'      S_OK
'
DECLARE FUNCTION SHLoadNonloadedIconOverlayIdentifiers LIB "Shell32.dll" _
    ALIAS "SHLoadNonloadedIconOverlayIdentifiers" () AS LONG  ' HRESULT

'
' The SHIsFileAvailableOffline API determines whether a file
' or folder is available for offline use.
'
' Parameters:
'     pwszPath             file name to get info about
'     pdwStatus            (optional) OFFLINE_STATUS_* flags returned here
'
' Returns:
'     S_OK                 File/directory is available offline, unless
'                            OFFLINE_STATUS_INCOMPLETE is returned.
'     E_INVALIDARG         Path is invalid, or not a net path
'     E_FAIL               File/directory is not available offline
'
' Notes:
'     OFFLINE_STATUS_INCOMPLETE is never returned for directories.
'     Both OFFLINE_STATUS_LOCAL and OFFLINE_STATUS_REMOTE may be returned,
'     indicating "open in both places." This is common when the server is online.
'
DECLARE FUNCTION SHIsFileAvailableOffline LIB "Shell32.dll" _
    ALIAS "SHIsFileAvailableOffline" (pwszPath AS WSTRINGZ, _
    pdwStatus AS DWORD) AS LONG  ' HRESULT

%OFFLINE_STATUS_LOCAL      = &H0001  ' If open, it's open locally
%OFFLINE_STATUS_REMOTE     = &H0002  ' If open, it's open remotely
%OFFLINE_STATUS_INCOMPLETE = &H0004  ' The local copy is currently imcomplete.
                                     ' The file will not be available offline
                                     ' until it has been synchronized.

#ENDIF

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
'  sets the specified path to use the string resource
'  as the UI instead of the file system name
DECLARE FUNCTION SHSetLocalizedName LIB "Shell32.dll" _
    ALIAS "SHSetLocalizedName" (pszPath AS WSTRINGZ, _
    pszResModule AS WSTRINGZ, BYVAL idsRes AS LONG) AS LONG  ' HRESULT

#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WINXP)
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
'  sets the specified path to use the string resource
'  as the UI instead of the file system name
DECLARE FUNCTION SHRemoveLocalizedName LIB "Shell32.dll" _
    ALIAS "SHRemoveLocalizedName" (pszPath AS WSTRINGZ) AS LONG  ' HRESULT
'  gets the string resource for the specified path
DECLARE FUNCTION SHGetLocalizedName LIB "Shell32.dll" _
    ALIAS "SHGetLocalizedName" (pszPath AS WSTRINGZ, _
    pszResModule AS WSTRINGZ, BYVAL cch AS DWORD, pidsRes AS LONG) AS LONG  ' HRESULT
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)


'====== ShellMessageBox ================================================

' If lpcTitle is NULL, the title is taken from hWnd
' If lpcText is NULL, this is assumed to be an Out Of Memory message
' If the selector of lpcTitle or lpcText is NULL, the offset should be a
'     string resource ID
' The variable arguments must all be 32-bit values (even if fewer bits
'     are actually used)
' lpcText (or whatever string resource it causes to be loaded) should
'     be a formatting string similar to wsprintf except that only the
'     following formats are available:
'         %%              formats to a single '%'
'         %nn%s           the nn-th arg is a string which is inserted
'         %nn%ld          the nn-th arg is a DWORD, and formatted decimal
'         %nn%lx          the nn-th arg is a DWORD, and formatted hex
'     note that lengths are allowed on the %s, %ld, and %lx, just
'                         like wsprintf
'

DECLARE FUNCTION ShellMessageBoxA CDECL LIB "Shell32.dll" _
    ALIAS "ShellMessageBoxA" ( _
    BYVAL hAppInst AS DWORD, _   ' HINSTANCE
    BYVAL hWnd     AS DWORD, _   ' HWND
    lpcText        AS ASCIIZ, _
    lpcTitle       AS ASCIIZ, _
    BYVAL fuStyle  AS DWORD, _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD  _
    ) AS LONG

DECLARE FUNCTION ShellMessageBoxW CDECL LIB "Shell32.dll" _
    ALIAS "ShellMessageBoxW" ( _
    BYVAL hAppInst AS DWORD, _   ' HINSTANCE
    BYVAL hWnd     AS DWORD, _   ' HWND
    lpcText        AS WSTRINGZ, _
    lpcTitle       AS WSTRINGZ, _
    BYVAL fuStyle  AS DWORD, _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD  _
    ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ShellMessageBox CDECL LIB "Shell32.dll" _
    ALIAS "ShellMessageBoxW" ( _
    BYVAL hAppInst AS DWORD, _   ' HINSTANCE
    BYVAL hWnd     AS DWORD, _   ' HWND
    lpcText        AS WSTRINGZ, _
    lpcTitle       AS WSTRINGZ, _
    BYVAL fuStyle  AS DWORD, _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD  _
    ) AS LONG
#ELSE
DECLARE FUNCTION ShellMessageBox CDECL LIB "Shell32.dll" _
    ALIAS "ShellMessageBoxA" ( _
    BYVAL hAppInst AS DWORD, _   ' HINSTANCE
    BYVAL hWnd     AS DWORD, _   ' HWND
    lpcText        AS ASCIIZ, _
    lpcTitle       AS ASCIIZ, _
    BYVAL fuStyle  AS DWORD, _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD,  _
    OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD, OPTIONAL BYVAL DWORD  _
    ) AS LONG
#ENDIF ' NOT %UNICODE

#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)

DECLARE FUNCTION IsLFNDriveA LIB "Shell32.dll" ALIAS "IsLFNDriveA" ( _
    pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION IsLFNDriveW LIB "Shell32.dll" ALIAS "IsLFNDriveW" ( _
    pszPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION IsLFNDrive LIB "Shell32.dll" ALIAS "IsLFNDriveW" ( _
    pszPath AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION IsLFNDrive LIB "Shell32.dll" ALIAS "IsLFNDriveA" ( _
    pszPath AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WIN2K)


#IF %WIN32_IE >= &H0600

' [Microsoft documents and declares this function, but the ANSI version
'  does not appear to actually be exported]
DECLARE FUNCTION SHEnumerateUnreadMailAccountsA LIB "Shell32.dll" _
    ALIAS "SHEnumerateUnreadMailAccountsA" (BYVAL hKeyUser AS DWORD, _
    BYVAL dwIndex AS DWORD, lpszMailAddress AS ASCIIZ, _
    BYVAL cchMailAddress AS LONG) AS LONG  ' HRESULT

DECLARE FUNCTION SHEnumerateUnreadMailAccountsW LIB "Shell32.dll" _
    ALIAS "SHEnumerateUnreadMailAccountsW" (BYVAL hKeyUser AS DWORD, _
    BYVAL dwIndex AS DWORD, lpszMailAddress AS WSTRINGZ, _
    BYVAL cchMailAddress AS LONG) AS LONG  ' HRESULT

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHEnumerateUnreadMailAccounts LIB "Shell32.dll" _
    ALIAS "SHEnumerateUnreadMailAccountsW" (BYVAL hKeyUser AS DWORD, _
    BYVAL dwIndex AS DWORD, lpszMailAddress AS WSTRINGZ, _
    BYVAL cchMailAddress AS LONG) AS LONG  ' HRESULT
#ELSE
DECLARE FUNCTION SHEnumerateUnreadMailAccounts LIB "Shell32.dll" _
    ALIAS "SHEnumerateUnreadMailAccountsA" (BYVAL hKeyUser AS DWORD, _
    BYVAL dwIndex AS DWORD, lpszMailAddress AS ASCIIZ, _
    BYVAL cchMailAddress AS LONG) AS LONG  ' HRESULT
#ENDIF ' NOT %UNICODE

' [there does not appear to actually be an Ansi version]
'DECLARE FUNCTION SHGetUnreadMailCountA LIB "Shell32.dll" _
'    ALIAS "SHGetUnreadMailCountA" (BYVAL hKeyUser AS DWORD, _
'    pszMailAddress AS ASCIIZ, pdwCount AS DWORD, pFileTime AS FILETIME, _
'    pszShellExecuteCommand AS ASCIIZ, BYVAL cchShellExecuteCommand AS LONG) _
'    AS LONG  ' HRESULT

DECLARE FUNCTION SHGetUnreadMailCountW LIB "Shell32.dll" _
    ALIAS "SHGetUnreadMailCountW" (BYVAL hKeyUser AS DWORD, _
    pszMailAddress AS WSTRINGZ, pdwCount AS DWORD, pFileTime AS FILETIME, _
    pszShellExecuteCommand AS WSTRINGZ, BYVAL cchShellExecuteCommand AS LONG) _
    AS LONG  ' HRESULT

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHGetUnreadMailCount LIB "Shell32.dll" _
    ALIAS "SHGetUnreadMailCountW" (BYVAL hKeyUser AS DWORD, _
    pszMailAddress AS WSTRINGZ, pdwCount AS DWORD, pFileTime AS FILETIME, _
    pszShellExecuteCommand AS WSTRINGZ, BYVAL cchShellExecuteCommand AS LONG) _
    AS LONG  ' HRESULT
'#ELSE
'MACRO SHGetUnreadMailCount  =SHGetUnreadMailCountA
#ENDIF ' NOT %UNICODE

' [there does not appear to be an Ansi version]
'DECLARE FUNCTION SHSetUnreadMailCountA LIB "Shell32.dll" _
'    ALIAS "SHSetUnreadMailCountA" (pszMailAddress AS ASCIIZ, _
'    BYVAL dwCount AS DWORD, pszShellExecuteCommand AS ASCIIZ) AS LONG  ' HRESULT

DECLARE FUNCTION SHSetUnreadMailCountW LIB "Shell32.dll" _
    ALIAS "SHSetUnreadMailCountW" (pszMailAddress AS WSTRINGZ, _
    BYVAL dwCount AS DWORD, pszShellExecuteCommand AS WSTRINGZ) AS LONG  ' HRESULT

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHSetUnreadMailCount LIB "Shell32.dll" _
    ALIAS "SHSetUnreadMailCountW" (pszMailAddress AS WSTRINGZ, _
    BYVAL dwCount AS DWORD, pszShellExecuteCommand AS WSTRINGZ) AS LONG  ' HRESULT
'#ELSE
'MACRO SHSetUnreadMailCount  =SHSetUnreadMailCountA
#ENDIF ' NOT %UNICODE

#ENDIF  '  %WIN32_IE >= &H0600

#IF (%WIN32_IE >= &H0601)
DECLARE FUNCTION SHTestTokenMembership LIB "Shell32.dll" _
    ALIAS "SHTestTokenMembership" (BYVAL hToken AS DWORD, _
    BYVAL ulRID AS DWORD) AS LONG
#ENDIF ' (%WIN32_IE >= &H0601)

#IF %WIN32_IE >= &H0600

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
DECLARE FUNCTION SHGetImageList LIB "Shell32.dll" ALIAS "SHGetImageList" _
    (BYVAL iImageList AS LONG, riid AS GUID, ppvObj AS DWORD) AS LONG  ' HRESULT
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WINXP)

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
%SHIL_LARGE        = 0   ' normally 32x32
%SHIL_SMALL        = 1   ' normally 16x16
%SHIL_EXTRALARGE   = 2
%SHIL_SYSSMALL     = 3   ' like SHIL_SMALL, but tracks system small icon metric correctly
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%SHIL_JUMBO        = 4   ' normally 256x256
%SHIL_LAST         = %SHIL_JUMBO
#ELSE
%SHIL_LAST         = %SHIL_SYSSMALL
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WINXP)


' Function call types for ntshrui folder sharing helpers
DECLARE FUNCTION PFNCANSHAREFOLDERW (pszPath AS WSTRINGZ) AS LONG  ' HRESULT

DECLARE FUNCTION PFNSHOWSHAREFOLDERUIW (BYVAL hwndParent AS DWORD, _
    pszPath AS WSTRINGZ) AS LONG  ' HRESULT

#ENDIF  '  %WIN32_IE >= &H0600



#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
' API for new Network Address Control

' Instantiation
$$WC_NETADDRESS = "msctls_netaddress"$$

DECLARE FUNCTION InitNetworkAddressControl LIB "Shell32.dll" _
    ALIAS "InitNetworkAddressControl" () AS LONG

' Address Control Messages

' NCM_GETADDRESS returns the type of address that is present in the
' control (based on TBD Net Address flags).  If the input string has
' not been validated using this message will force the validation of
' the input string.  The WPARAM is a BOOL to determine to show the
' balloon tip.  The LPARAM is a pointer to the structure to fill in
' with the address type and address string.
%NCM_GETADDRESS = %WM_USER+1
MACRO NetAddr_GetAddress(hwnd,pv)=SendMessage(hwnd,%NCM_GETADDRESS,0,pv)
TYPE NC_ADDRESS WORD
    pAddrInfo    AS NET_ADDRESS_INFO PTR ' defined in iphlpapi.inc
    PortNumber   AS WORD
    PrefixLength AS BYTE
END TYPE

' NCM_SETALLOWTYPE sets the type of addresses that the control will allow.
' The address flags are defined in iphlpapi.h
%NCM_SETALLOWTYPE = %WM_USER+2
MACRO NetAddr_SetAllowType(hwnd,addrMask)=SendMessage(hwnd,%NCM_SETALLOWTYPE,addrMask,0)
' NCM_GETALLOWTYPE returns the currently allowed type mask.
%NCM_GETALLOWTYPE = %WM_USER+3
MACRO NetAddr_GetAllowType(hwnd)=SendMessage(hwnd,%NCM_GETALLOWTYPE,0,0)

' NCM_DISPLAYERRORTIP displays the error balloon tip with the correct
' error string (based on the last failure from the NCM_GETADDRESS call
%NCM_DISPLAYERRORTIP = %WM_USER+4
MACRO NetAddr_DisplayErrorTip(hwnd)=SendMessage(hwnd,%NCM_DISPLAYERRORTIP,0,0)

#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
' Returns the type of media (CD, DVD, Blank, etc) that is in the drive.
' dwMediaContent is set to a combination of ARCONTENT flags.
DECLARE FUNCTION SHGetDriveMedia LIB "Shell32.dll" ALIAS "SHGetDriveMedia" ( _
    pszDrive AS WSTRINGZ, pdwMediaContent AS DWORD) AS LONG  ' HRESULT
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)
