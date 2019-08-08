'------------------------------------------------------------------------------
'
'  WinNetWk.inc -- Standard WINNET Header File for WIN32
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from WinNetWk.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE
%WINNETWK = 1

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "WinError.inc"

'
' Network types
'
#INCLUDE "wnnc.inc"

'
'  Network Resources.
'

%RESOURCE_CONNECTED    = &H00000001
%RESOURCE_GLOBALNET    = &H00000002
%RESOURCE_REMEMBERED   = &H00000003
#IF (%WINVER >= &H0400)
%RESOURCE_RECENT       = &H00000004
%RESOURCE_CONTEXT      = &H00000005
#ENDIF ' %WINVER >= &H0400

%RESOURCETYPE_ANY      = &H00000000
%RESOURCETYPE_DISK     = &H00000001
%RESOURCETYPE_PRINT    = &H00000002
#IF (%WINVER >= &H0400)
%RESOURCETYPE_RESERVED = &H00000008
#ENDIF ' %WINVER >= &H0400
%RESOURCETYPE_UNKNOWN  = &HFFFFFFFF???

%RESOURCEUSAGE_CONNECTABLE = &H00000001
%RESOURCEUSAGE_CONTAINER   = &H00000002
#IF (%WINVER >= &H0400)
%RESOURCEUSAGE_NOLOCALDEVICE = &H00000004
%RESOURCEUSAGE_SIBLING     = &H00000008
%RESOURCEUSAGE_ATTACHED    = &H00000010
%RESOURCEUSAGE_ALL         = (%RESOURCEUSAGE_CONNECTABLE OR %RESOURCEUSAGE_CONTAINER OR %RESOURCEUSAGE_ATTACHED)
#ENDIF ' %WINVER >= &H0400
%RESOURCEUSAGE_RESERVED    = &H80000000???

%RESOURCEDISPLAYTYPE_GENERIC      = &H00000000
%RESOURCEDISPLAYTYPE_DOMAIN       = &H00000001
%RESOURCEDISPLAYTYPE_SERVER       = &H00000002
%RESOURCEDISPLAYTYPE_SHARE        = &H00000003
%RESOURCEDISPLAYTYPE_FILE         = &H00000004
%RESOURCEDISPLAYTYPE_GROUP        = &H00000005
#IF (%WINVER >= &H0400)
%RESOURCEDISPLAYTYPE_NETWORK      = &H00000006
%RESOURCEDISPLAYTYPE_ROOT         = &H00000007
%RESOURCEDISPLAYTYPE_SHAREADMIN   = &H00000008
%RESOURCEDISPLAYTYPE_DIRECTORY    = &H00000009
#ENDIF ' %WINVER >= &H0400
%RESOURCEDISPLAYTYPE_TREE         = &H0000000A
#IF (%WINVER >= &H0400)
%RESOURCEDISPLAYTYPE_NDSCONTAINER = &H0000000B
#ENDIF ' %WINVER >= &H0400

TYPE NETRESOURCEA
    dwScope       AS DWORD
    dwType        AS DWORD
    dwDisplayType AS DWORD
    dwUsage       AS DWORD
    lpLocalName   AS ASCIIZ PTR
    lpRemoteName  AS ASCIIZ PTR
    lpComment     AS ASCIIZ PTR
    lpProvider    AS ASCIIZ PTR
END TYPE

TYPE NETRESOURCEW
    dwScope       AS DWORD
    dwType        AS DWORD
    dwDisplayType AS DWORD
    dwUsage       AS DWORD
    lpLocalName   AS WSTRINGZ PTR
    lpRemoteName  AS WSTRINGZ PTR
    lpComment     AS WSTRINGZ PTR
    lpProvider    AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE NETRESOURCE
    NETRESOURCEW
END TYPE
#ELSE
TYPE NETRESOURCE
    NETRESOURCEA
END TYPE
#ENDIF ' %UNICODE


'
'  Network Connections.
'

%NETPROPERTY_PERSISTENT     = 1

%CONNECT_UPDATE_PROFILE    = &H00000001
%CONNECT_UPDATE_RECENT     = &H00000002
%CONNECT_TEMPORARY         = &H00000004
%CONNECT_INTERACTIVE       = &H00000008
%CONNECT_PROMPT            = &H00000010
%CONNECT_NEED_DRIVE        = &H00000020
#IF (%WINVER >= &H0400)
%CONNECT_REFCOUNT          = &H00000040
%CONNECT_REDIRECT          = &H00000080
%CONNECT_LOCALDRIVE        = &H00000100
%CONNECT_CURRENT_MEDIA     = &H00000200
%CONNECT_DEFERRED          = &H00000400
%CONNECT_RESERVED          = &HFF000000
#ENDIF ' %WINVER >= &H0400
#IF (%WINVER >= &H0500)
%CONNECT_COMMANDLINE       = &H00000800
%CONNECT_CMD_SAVECRED      = &H00001000
#ENDIF ' %WINVER >= &H0500
#IF (%WINVER >= &H0600)
%CONNECT_CRED_RESET        = &H00002000
#ENDIF ' %WINVER >= &H0600

DECLARE FUNCTION WNetAddConnectionA LIB "Mpr.dll" ALIAS "WNetAddConnectionA" _
    (lpRemoteName AS ASCIIZ, lpPassword AS ASCIIZ, lpLocalName AS ASCIIZ) _
    AS DWORD

DECLARE FUNCTION WNetAddConnectionW LIB "Mpr.dll" ALIAS "WNetAddConnectionW" _
    (lpRemoteName AS WSTRINGZ, lpPassword AS WSTRINGZ, _
    lpLocalName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION WNetAddConnection LIB "Mpr.dll" ALIAS "WNetAddConnectionW" _
    (lpRemoteName AS WSTRINGZ, lpPassword AS WSTRINGZ, _
    lpLocalName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION WNetAddConnection LIB "Mpr.dll" ALIAS "WNetAddConnectionA" _
    (lpRemoteName AS ASCIIZ, lpPassword AS ASCIIZ, lpLocalName AS ASCIIZ) _
    AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION WNetAddConnection2A LIB "Mpr.dll" _
    ALIAS "WNetAddConnection2A" ( _
    lpNetResource AS NETRESOURCEA, _
    lpPassword    AS ASCIIZ, _
    lpUserName    AS ASCIIZ, _
    BYVAL dwFlags AS DWORD _
    ) AS DWORD

DECLARE FUNCTION WNetAddConnection2W LIB "Mpr.dll" _
    ALIAS "WNetAddConnection2W" ( _
    lpNetResource AS NETRESOURCEW, _
    lpPassword    AS WSTRINGZ, _
    lpUserName    AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION WNetAddConnection2 LIB "Mpr.dll" _
    ALIAS "WNetAddConnection2W" ( _
    lpNetResource AS NETRESOURCEW, _
    lpPassword    AS WSTRINGZ, _
    lpUserName    AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetAddConnection2 LIB "Mpr.dll" _
    ALIAS "WNetAddConnection2A" ( _
    lpNetResource AS NETRESOURCEA, _
    lpPassword    AS ASCIIZ, _
    lpUserName    AS ASCIIZ, _
    BYVAL dwFlags AS DWORD _
    ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION WNetAddConnection3A LIB "Mpr.dll" _
    ALIAS "WNetAddConnection3A" ( _
    hwndOwner     AS DWORD, _   ' HWND
    lpNetResource AS NETRESOURCEA, _
    lpPassword    AS ASCIIZ, _
    lpUserName    AS ASCIIZ, _
    BYVAL dwFlags AS DWORD _
    ) AS DWORD

DECLARE FUNCTION WNetAddConnection3W LIB "Mpr.dll" _
    ALIAS "WNetAddConnection3W" ( _
    hwndOwner     AS DWORD, _   ' HWND
    lpNetResource AS NETRESOURCEA, _
    lpPassword    AS WSTRINGZ, _
    lpUserName    AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION WNetAddConnection3 LIB "Mpr.dll" _
    ALIAS "WNetAddConnection3W" ( _
    hwndOwner     AS DWORD, _   ' HWND
    lpNetResource AS NETRESOURCEA, _
    lpPassword    AS WSTRINGZ, _
    lpUserName    AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetAddConnection3 LIB "Mpr.dll" _
    ALIAS "WNetAddConnection3A" ( _
    hwndOwner     AS DWORD, _   ' HWND
    lpNetResource AS NETRESOURCEA, _
    lpPassword    AS ASCIIZ, _
    lpUserName    AS ASCIIZ, _
    BYVAL dwFlags AS DWORD _
    ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION WNetCancelConnectionA LIB "Mpr.dll" _
    ALIAS "WNetCancelConnectionA" ( _
    lpName AS ASCIIZ, _
    fForce AS LONG _   ' BOOL
    ) AS DWORD

DECLARE FUNCTION WNetCancelConnectionW LIB "Mpr.dll" _
    ALIAS "WNetCancelConnectionW" ( _
    lpName AS WSTRINGZ, _
    fForce AS LONG _   ' BOOL
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION WNetCancelConnection LIB "Mpr.dll" _
    ALIAS "WNetCancelConnectionW" ( _
    lpName AS WSTRINGZ, _
    fForce AS LONG _   ' BOOL
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetCancelConnection LIB "Mpr.dll" _
    ALIAS "WNetCancelConnectionA" ( _
    lpName AS ASCIIZ, _
    fForce AS LONG _   ' BOOL
    ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION WNetCancelConnection2A LIB "Mpr.dll" _
    ALIAS "WNetCancelConnection2A" ( _
    lpName        AS ASCIIZ, _
    BYVAL dwFlags AS DWORD, _
    BYVAL fForce  AS LONG _  ' BOOL
    ) AS DWORD

DECLARE FUNCTION WNetCancelConnection2W LIB "Mpr.dll" _
    ALIAS "WNetCancelConnection2W" ( _
    lpName        AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD, _
    BYVAL fForce  AS LONG _  ' BOOL
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION WNetCancelConnection2 LIB "Mpr.dll" _
    ALIAS "WNetCancelConnection2W" ( _
    lpName        AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD, _
    BYVAL fForce  AS LONG _  ' BOOL
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetCancelConnection2 LIB "Mpr.dll" _
    ALIAS "WNetCancelConnection2A" ( _
    lpName        AS ASCIIZ, _
    BYVAL dwFlags AS DWORD, _
    BYVAL fForce  AS LONG _  ' BOOL
    ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION WNetGetConnectionA LIB "Mpr.dll" _
    ALIAS "WNetGetConnectionA" ( _
    lpLocalName  AS ASCIIZ, _
    lpRemoteName AS ASCIIZ, _
    lpnLength    AS DWORD _
    ) AS DWORD

DECLARE FUNCTION WNetGetConnectionW LIB "Mpr.dll" _
    ALIAS "WNetGetConnectionW" ( _
    lpLocalName  AS WSTRINGZ, _
    lpRemoteName AS WSTRINGZ, _
    lpnLength    AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION WNetGetConnection LIB "Mpr.dll" _
    ALIAS "WNetGetConnectionW" ( _
    lpLocalName  AS WSTRINGZ, _
    lpRemoteName AS WSTRINGZ, _
    lpnLength    AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetGetConnection LIB "Mpr.dll" _
    ALIAS "WNetGetConnectionA" ( _
    lpLocalName  AS ASCIIZ, _
    lpRemoteName AS ASCIIZ, _
    lpnLength    AS DWORD _
    ) AS DWORD
#ENDIF ' NOT %UNICODE


#IF (%WIN32_WINNT >= %WIN32_WINNT_LONGHORN)

DECLARE FUNCTION WNetRestoreSingleConnectionW LIB "Mpr.dll" _
    ALIAS "WNetRestoreSingleConnectionW" ( _
    BYVAL hwndParent AS DWORD, _  ' HWND
    lpDevice         AS WSTRINGZ, _
    BYVAL fUseUI     AS LONG _    ' BOOL
    ) AS DWORD

#ELSE

DECLARE FUNCTION WNetRestoreConnectionW LIB "Mpr.dll" _
    ALIAS "WNetRestoreConnectionW" ( _
    BYVAL hWnd AS DWORD, _   ' HWND
    lpDevice   AS WSTRINGZ _
    ) AS DWORD

#ENDIF


#IF (%WINVER >= &H0400)

DECLARE FUNCTION WNetUseConnectionA LIB "Mpr.dll" _
    ALIAS "WNetUseConnectionA" ( _
    BYVAL hwndOwner AS DWORD, _   ' HWND
    lpNetResource   AS NETRESOURCEA, _
    lpPassword      AS ASCIIZ, _
    lpUserId        AS ASCIIZ, _
    BYVAL dwFlags   AS DWORD, _
    lpAccessName    AS ASCIIZ, _
    lpBufferSize    AS DWORD, _
    lpResult        AS DWORD _
    ) AS DWORD

DECLARE FUNCTION WNetUseConnectionW LIB "Mpr.dll" _
    ALIAS "WNetUseConnectionW" ( _
    BYVAL hwndOwner AS DWORD, _   ' HWND
    lpNetResource   AS NETRESOURCEW, _
    lpPassword      AS WSTRINGZ, _
    lpUserId        AS WSTRINGZ, _
    BYVAL dwFlags   AS DWORD, _
    lpAccessName    AS WSTRINGZ, _
    lpBufferSize    AS DWORD, _
    lpResult        AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION WNetUseConnection LIB "Mpr.dll" _
    ALIAS "WNetUseConnectionW" ( _
    BYVAL hwndOwner AS DWORD, _   ' HWND
    lpNetResource   AS NETRESOURCEW, _
    lpPassword      AS WSTRINGZ, _
    lpUserId        AS WSTRINGZ, _
    BYVAL dwFlags   AS DWORD, _
    lpAccessName    AS WSTRINGZ, _
    lpBufferSize    AS DWORD, _
    lpResult        AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetUseConnection LIB "Mpr.dll" _
    ALIAS "WNetUseConnectionA" ( _
    BYVAL hwndOwner AS DWORD, _   ' HWND
    lpNetResource   AS NETRESOURCEA, _
    lpPassword      AS ASCIIZ, _
    lpUserId        AS ASCIIZ, _
    BYVAL dwFlags   AS DWORD, _
    lpAccessName    AS ASCIIZ, _
    lpBufferSize    AS DWORD, _
    lpResult        AS DWORD _
    ) AS DWORD
#ENDIF ' NOT %UNICODE
#ENDIF ' %WINVER >= &H0400


'
'  Network Connection Dialogs.
'
DECLARE FUNCTION WNetConnectionDialog LIB "Mpr.dll" _
    ALIAS "WNetConnectionDialog" ( _
    BYVAL hwnd   AS DWORD, _  ' HWND
    BYVAL dwType AS DWORD _
    ) AS DWORD

DECLARE FUNCTION WNetDisconnectDialog LIB "Mpr.dll" _
    ALIAS "WNetDisconnectDialog" ( _
    BYVAL hwnd   AS DWORD, _   ' HWND
    BYVAL dwType AS DWORD _
    ) AS DWORD

#IF (%WINVER >= &H0400)

TYPE CONNECTDLGSTRUCTA
    cbStructure AS DWORD            ' size of this structure in bytes
    hwndOwner   AS DWORD  ' HWND      owner window for the dialog
    lpConnRes   AS NETRESOURCEA PTR ' Requested Resource info
    dwFlags     AS DWORD            ' flags (see below)
    dwDevNum    AS DWORD            ' number of devices connected to
END TYPE

TYPE CONNECTDLGSTRUCTW
    cbStructure AS DWORD            ' size of this structure in bytes
    hwndOwner   AS DWORD  ' HWND      owner window for the dialog
    lpConnRes   AS NETRESOURCEW PTR ' Requested Resource info
    dwFlags     AS DWORD            ' flags (see below)
    dwDevNum    AS DWORD            ' number of devices connected to
END TYPE

#IF %DEF(%UNICODE)
TYPE CONNECTDLGSTRUCT
    CONNECTDLGSTRUCTW
END TYPE
#ELSE
TYPE CONNECTDLGSTRUCT
    CONNECTDLGSTRUCTA
END TYPE
#ENDIF ' %UNICODE

%CONNDLG_RO_PATH     = &H00000001 ' Resource path should be read-only
%CONNDLG_CONN_POINT  = &H00000002 ' Netware -style movable connection point enabled
%CONNDLG_USE_MRU     = &H00000004 ' Use MRU combobox
%CONNDLG_HIDE_BOX    = &H00000008 ' Hide persistent connect checkbox

'
' NOTE:  Set at most ONE of the below flags.  If neither flag is set,
'        then the persistence is set to whatever the user chose during
'        a previous connection
'
%CONNDLG_PERSIST     = &H00000010 ' Force persistent connection
%CONNDLG_NOT_PERSIST = &H00000020 ' Force connection NOT persistent

DECLARE FUNCTION WNetConnectionDialog1A LIB "Mpr.dll" _
    ALIAS "WNetConnectionDialog1A" ( _
    lpConnDlgStruct AS CONNECTDLGSTRUCTA _
    ) AS DWORD

DECLARE FUNCTION WNetConnectionDialog1W LIB "Mpr.dll" _
    ALIAS "WNetConnectionDialog1W" ( _
    lpConnDlgStruct AS CONNECTDLGSTRUCTW _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION WNetConnectionDialog1 LIB "Mpr.dll" _
    ALIAS "WNetConnectionDialog1W" ( _
    lpConnDlgStruct AS CONNECTDLGSTRUCTW _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetConnectionDialog1 LIB "Mpr.dll" _
    ALIAS "WNetConnectionDialog1A" ( _
    lpConnDlgStruct AS CONNECTDLGSTRUCTA _
    ) AS DWORD
#ENDIF ' NOT %UNICODE

TYPE DISCDLGSTRUCTA
    cbStructure  AS DWORD           ' size of this structure in bytes
    hwndOwner    AS DWORD   ' HWND    owner window for the dialog
    lpLocalName  AS ASCIIZ PTR      ' local device name
    lpRemoteName AS ASCIIZ PTR      ' network resource name
    dwFlags      AS DWORD           ' flags
END TYPE

TYPE DISCDLGSTRUCTW
    cbStructure  AS DWORD           ' size of this structure in bytes
    hwndOwner    AS DWORD   ' HWND    owner window for the dialog
    lpLocalName  AS WSTRINGZ PTR    ' local device name
    lpRemoteName AS WSTRINGZ PTR    ' network resource name
    dwFlags      AS DWORD           ' flags
END TYPE

#IF %DEF(%UNICODE)
TYPE DISCDLGSTRUCT
    DISCDLGSTRUCTW
END TYPE
#ELSE
TYPE DISCDLGSTRUCT
    DISCDLGSTRUCTA
END TYPE
#ENDIF ' %UNICODE

%DISC_UPDATE_PROFILE       = &H00000001
%DISC_NO_FORCE             = &H00000040

DECLARE FUNCTION WNetDisconnectDialog1A LIB "Mpr.dll" _
    ALIAS "WNetDisconnectDialog1A" ( _
    lpConnDlgStruct AS DISCDLGSTRUCTA _
    ) AS DWORD

DECLARE FUNCTION WNetDisconnectDialog1W LIB "Mpr.dll" _
    ALIAS "WNetDisconnectDialog1W" ( _
    lpConnDlgStruct AS DISCDLGSTRUCTW _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION WNetDisconnectDialog1 LIB "Mpr.dll" _
    ALIAS "WNetDisconnectDialog1W" ( _
    lpConnDlgStruct AS DISCDLGSTRUCTW _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetDisconnectDialog1 LIB "Mpr.dll" _
    ALIAS "WNetDisconnectDialog1A" ( _
    lpConnDlgStruct AS DISCDLGSTRUCTA _
    ) AS DWORD
#ENDIF ' NOT %UNICODE
#ENDIF ' %WINVER >= &H0400

'
'  Network Browsing.
'

DECLARE FUNCTION WNetOpenEnumA LIB "Mpr.dll" ALIAS "WNetOpenEnumA" ( _
    BYVAL dwScope AS DWORD, _
    BYVAL dwType  AS DWORD, _
    BYVAL dwUsage AS DWORD, _
    lpNetResource AS NETRESOURCEA, _
    lphEnum AS DWORD _  ' LPHANDLE
    ) AS DWORD

DECLARE FUNCTION WNetOpenEnumW LIB "Mpr.dll" ALIAS "WNetOpenEnumW" ( _
    BYVAL dwScope AS DWORD, _
    BYVAL dwType  AS DWORD, _
    BYVAL dwUsage AS DWORD, _
    lpNetResource AS NETRESOURCEW, _
    lphEnum AS DWORD _  ' LPHANDLE
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION WNetOpenEnum LIB "Mpr.dll" ALIAS "WNetOpenEnumW" ( _
    BYVAL dwScope AS DWORD, _
    BYVAL dwType  AS DWORD, _
    BYVAL dwUsage AS DWORD, _
    lpNetResource AS NETRESOURCEW, _
    lphEnum AS DWORD _  ' LPHANDLE
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetOpenEnum LIB "Mpr.dll" ALIAS "WNetOpenEnumA" ( _
    BYVAL dwScope AS DWORD, _
    BYVAL dwType  AS DWORD, _
    BYVAL dwUsage AS DWORD, _
    lpNetResource AS NETRESOURCEA, _
    lphEnum AS DWORD _  ' LPHANDLE
    ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION WNetEnumResourceA LIB "Mpr.dll" ALIAS "WNetEnumResourceA" ( _
    BYVAL hEnum    AS DWORD, _  ' HANDLE
    lpcCount       AS DWORD, _
    BYVAL lpBuffer AS DWORD, _  ' LPVOID
    lpBufferSize   AS DWORD _
    ) AS DWORD

DECLARE FUNCTION WNetEnumResourceW LIB "Mpr.dll" ALIAS "WNetEnumResourceW" ( _
    BYVAL hEnum    AS DWORD, _  ' HANDLE
    lpcCount       AS DWORD, _
    BYVAL lpBuffer AS DWORD, _  ' LPVOID
    lpBufferSize   AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION WNetEnumResource LIB "Mpr.dll" ALIAS "WNetEnumResourceW" ( _
    BYVAL hEnum    AS DWORD, _  ' HANDLE
    lpcCount       AS DWORD, _
    BYVAL lpBuffer AS DWORD, _  ' LPVOID
    lpBufferSize   AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetEnumResource LIB "Mpr.dll" ALIAS "WNetEnumResourceA" ( _
    BYVAL hEnum    AS DWORD, _  ' HANDLE
    lpcCount       AS DWORD, _
    BYVAL lpBuffer AS DWORD, _  ' LPVOID
    lpBufferSize   AS DWORD _
    ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION WNetCloseEnum LIB "Mpr.dll" ALIAS "WNetCloseEnum" ( _
    BYVAL hEnum AS DWORD _   ' HANDLE
    ) AS DWORD

#IF (%WINVER >= &H0400)

DECLARE FUNCTION WNetGetResourceParentA LIB "Mpr.dll" _
    ALIAS "WNetGetResourceParentA" ( _
    lpNetResource  AS NETRESOURCEA, _
    BYVAL lpBuffer AS DWORD, _   ' LPVOID
    lpcbBuffer     AS DWORD _
    ) AS DWORD

DECLARE FUNCTION WNetGetResourceParentW LIB "Mpr.dll" _
    ALIAS "WNetGetResourceParentW" ( _
    lpNetResource  AS NETRESOURCEW, _
    BYVAL lpBuffer AS DWORD, _   ' LPVOID
    lpcbBuffer     AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION WNetGetResourceParent LIB "Mpr.dll" _
    ALIAS "WNetGetResourceParentW" ( _
    lpNetResource  AS NETRESOURCEW, _
    BYVAL lpBuffer AS DWORD, _   ' LPVOID
    lpcbBuffer     AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetGetResourceParent LIB "Mpr.dll" _
    ALIAS "WNetGetResourceParentA" ( _
    lpNetResource  AS NETRESOURCEA, _
    BYVAL lpBuffer AS DWORD, _   ' LPVOID
    lpcbBuffer     AS DWORD _
    ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION WNetGetResourceInformationA LIB "Mpr.dll" _
    ALIAS "WNetGetResourceInformationA" ( _
    lpNetResource  AS NETRESOURCEA, _
    BYVAL lpBuffer AS DWORD, _   ' LPVOID
    lpcbBuffer     AS DWORD, _
    lplpSystem     AS ANY _      ' LPSTR *
    ) AS DWORD

DECLARE FUNCTION WNetGetResourceInformationW LIB "Mpr.dll" _
    ALIAS "WNetGetResourceInformationW" ( _
    lpNetResource  AS NETRESOURCEW, _
    BYVAL lpBuffer AS DWORD, _   ' LPVOID
    lpcbBuffer     AS DWORD, _
    lplpSystem     AS ANY _      ' LPSTR *
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION WNetGetResourceInformation LIB "Mpr.dll" _
    ALIAS "WNetGetResourceInformationW" ( _
    lpNetResource  AS NETRESOURCEW, _
    BYVAL lpBuffer AS DWORD, _   ' LPVOID
    lpcbBuffer     AS DWORD, _
    lplpSystem     AS ANY _      ' LPSTR *
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetGetResourceInformation LIB "Mpr.dll" _
    ALIAS "WNetGetResourceInformationA" ( _
    lpNetResource  AS NETRESOURCEA, _
    BYVAL lpBuffer AS DWORD, _   ' LPVOID
    lpcbBuffer     AS DWORD, _
    lplpSystem     AS ANY _      ' LPSTR *
    ) AS DWORD
#ENDIF ' NOT %UNICODE
#ENDIF ' %WINVER >= &H0400

'
'  Universal Naming.
'

%UNIVERSAL_NAME_INFO_LEVEL = &H00000001
%REMOTE_NAME_INFO_LEVEL    = &H00000002

TYPE UNIVERSAL_NAME_INFOA
    lpUniversalName AS ASCIIZ PTR
END TYPE

TYPE UNIVERSAL_NAME_INFOW
    lpUniversalName AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE UNIVERSAL_NAME_INFO
    UNIVERSAL_NAME_INFOW
END TYPE
#ELSE
TYPE UNIVERSAL_NAME_INFO
    UNIVERSAL_NAME_INFOA
END TYPE
#ENDIF ' %UNICODE

TYPE REMOTE_NAME_INFOA
    lpUniversalName  AS ASCIIZ PTR
    lpConnectionName AS ASCIIZ PTR
    lpRemainingPath  AS ASCIIZ PTR
END TYPE

TYPE REMOTE_NAME_INFOW
    lpUniversalName  AS WSTRINGZ PTR
    lpConnectionName AS WSTRINGZ PTR
    lpRemainingPath  AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE REMOTE_NAME_INFO
    REMOTE_NAME_INFOW
END TYPE
#ELSE
TYPE REMOTE_NAME_INFO
    REMOTE_NAME_INFOA
END TYPE
#ENDIF ' %UNICODE

DECLARE FUNCTION WNetGetUniversalNameA LIB "Mpr.dll" _
    ALIAS "WNetGetUniversalNameA" ( _
    lpLocalPath       AS ASCIIZ, _
    BYVAL dwInfoLevel AS DWORD, _
    BYVAL lpBuffer    AS DWORD, _   ' LPVOID
    lpBufferSize      AS DWORD _
    ) AS DWORD

DECLARE FUNCTION WNetGetUniversalNameW LIB "Mpr.dll" _
    ALIAS "WNetGetUniversalNameW" ( _
    lpLocalPath       AS WSTRINGZ, _
    BYVAL dwInfoLevel AS DWORD, _
    BYVAL lpBuffer    AS DWORD, _   ' LPVOID
    lpBufferSize      AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION WNetGetUniversalName LIB "Mpr.dll" _
    ALIAS "WNetGetUniversalNameW" ( _
    lpLocalPath       AS WSTRINGZ, _
    BYVAL dwInfoLevel AS DWORD, _
    BYVAL lpBuffer    AS DWORD, _   ' LPVOID
    lpBufferSize      AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetGetUniversalName LIB "Mpr.dll" _
    ALIAS "WNetGetUniversalNameA" ( _
    lpLocalPath       AS ASCIIZ, _
    BYVAL dwInfoLevel AS DWORD, _
    BYVAL lpBuffer    AS DWORD, _   ' LPVOID
    lpBufferSize      AS DWORD _
    ) AS DWORD
#ENDIF ' NOT %UNICODE

'
'  Authentication and Logon/Logoff.
'
DECLARE FUNCTION WNetGetUserA LIB "Mpr.dll" ALIAS "WNetGetUserA" ( _
    lpName     AS ASCIIZ, _
    lpUserName AS ASCIIZ, _
    lpnLength  AS DWORD _
    ) AS DWORD

'
'  Authentication and Logon/Logoff.
'
DECLARE FUNCTION WNetGetUserW LIB "Mpr.dll" ALIAS "WNetGetUserW" ( _
    lpName     AS WSTRINGZ, _
    lpUserName AS WSTRINGZ, _
    lpnLength  AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION WNetGetUser LIB "Mpr.dll" ALIAS "WNetGetUserW" ( _
    lpName     AS WSTRINGZ, _
    lpUserName AS WSTRINGZ, _
    lpnLength  AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetGetUser LIB "Mpr.dll" ALIAS "WNetGetUserA" ( _
    lpName     AS ASCIIZ, _
    lpUserName AS ASCIIZ, _
    lpnLength  AS DWORD _
    ) AS DWORD
#ENDIF ' NOT %UNICODE



'
' Other.
'

#IF (%WINVER >= &H0400)
%WNFMT_MULTILINE       = &H01
%WNFMT_ABBREVIATED     = &H02
%WNFMT_INENUM          = &H10
%WNFMT_CONNECTION      = &H20
#ENDIF ' %WINVER >= &H0400


#IF (%WINVER >= &H0400)

DECLARE FUNCTION WNetGetProviderNameA LIB "Mpr.dll" _
    ALIAS "WNetGetProviderNameA" ( _
    BYVAL dwNetType AS DWORD, _
    lpProviderName  AS ASCIIZ, _
    lpBufferSize    AS DWORD _
    ) AS DWORD

DECLARE FUNCTION WNetGetProviderNameW LIB "Mpr.dll" _
    ALIAS "WNetGetProviderNameW" ( _
    BYVAL dwNetType AS DWORD, _
    lpProviderName  AS WSTRINGZ, _
    lpBufferSize    AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION WNetGetProviderName LIB "Mpr.dll" _
    ALIAS "WNetGetProviderNameW" ( _
    BYVAL dwNetType AS DWORD, _
    lpProviderName  AS WSTRINGZ, _
    lpBufferSize    AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetGetProviderName LIB "Mpr.dll" _
    ALIAS "WNetGetProviderNameA" ( _
    BYVAL dwNetType AS DWORD, _
    lpProviderName  AS ASCIIZ, _
    lpBufferSize    AS DWORD _
    ) AS DWORD
#ENDIF ' NOT %UNICODE

TYPE NETINFOSTRUCT DWORD
    cbStructure       AS DWORD
    dwProviderVersion AS DWORD
    dwStatus          AS DWORD
    dwCharacteristics AS DWORD
    dwHandle          AS DWORD  ' ULONG_PTR
    wNetType          AS WORD
    dwPrinters        AS DWORD
    dwDrives          AS DWORD
END TYPE

%NETINFO_DLL16      = &H00000001  ' Provider running as 16 bit Winnet Driver
%NETINFO_DISKRED    = &H00000004  ' Provider requires disk redirections to connect
%NETINFO_PRINTERRED = &H00000008  ' Provider requires printer redirections to connect

DECLARE FUNCTION WNetGetNetworkInformationA LIB "Mpr.dll" _
    ALIAS "WNetGetNetworkInformationA" ( _
    lpProvider      AS ASCIIZ, _
    lpNetInfoStruct AS NETINFOSTRUCT _
    ) AS DWORD

DECLARE FUNCTION WNetGetNetworkInformationW LIB "Mpr.dll" _
    ALIAS "WNetGetNetworkInformationW" ( _
    lpProvider      AS WSTRINGZ, _
    lpNetInfoStruct AS NETINFOSTRUCT _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION WNetGetNetworkInformation LIB "Mpr.dll" _
    ALIAS "WNetGetNetworkInformationW" ( _
    lpProvider      AS WSTRINGZ, _
    lpNetInfoStruct AS NETINFOSTRUCT _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetGetNetworkInformation LIB "Mpr.dll" _
    ALIAS "WNetGetNetworkInformationA" ( _
    lpProvider      AS ASCIIZ, _
    lpNetInfoStruct AS NETINFOSTRUCT _
    ) AS DWORD
#ENDIF ' NOT %UNICODE

#ENDIF ' %WINVER >= &H0400

'
'  Error handling.
'

DECLARE FUNCTION WNetGetLastErrorA LIB "Mpr.dll" ALIAS "WNetGetLastErrorA" ( _
    lpError             AS DWORD, _
    lpErrorBuf          AS ASCIIZ, _
    BYVAL nErrorBufSize AS DWORD, _
    lpNameBuf           AS ASCIIZ, _
    BYVAL nNameBufSize  AS DWORD _
    ) AS DWORD

DECLARE FUNCTION WNetGetLastErrorW LIB "Mpr.dll" ALIAS "WNetGetLastErrorW" ( _
    lpError             AS DWORD, _
    lpErrorBuf          AS WSTRINGZ, _
    BYVAL nErrorBufSize AS DWORD, _
    lpNameBuf           AS WSTRINGZ, _
    BYVAL nNameBufSize  AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION WNetGetLastError LIB "Mpr.dll" ALIAS "WNetGetLastErrorW" ( _
    lpError             AS DWORD, _
    lpErrorBuf          AS WSTRINGZ, _
    BYVAL nErrorBufSize AS DWORD, _
    lpNameBuf           AS WSTRINGZ, _
    BYVAL nNameBufSize  AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetGetLastError LIB "Mpr.dll" ALIAS "WNetGetLastErrorA" ( _
    lpError             AS DWORD, _
    lpErrorBuf          AS ASCIIZ, _
    BYVAL nErrorBufSize AS DWORD, _
    lpNameBuf           AS ASCIIZ, _
    BYVAL nNameBufSize  AS DWORD _
    ) AS DWORD
#ENDIF ' NOT %UNICODE

'
'  STATUS CODES
'

' General

%WN_SUCCESS                     = %NO_ERROR
%WN_NO_ERROR                    = %NO_ERROR
%WN_NOT_SUPPORTED               = %ERROR_NOT_SUPPORTED
%WN_CANCEL                      = %ERROR_CANCELLED
%WN_RETRY                       = %ERROR_RETRY
%WN_NET_ERROR                   = %ERROR_UNEXP_NET_ERR
%WN_MORE_DATA                   = %ERROR_MORE_DATA
%WN_BAD_POINTER                 = %ERROR_INVALID_ADDRESS
%WN_BAD_VALUE                   = %ERROR_INVALID_PARAMETER
%WN_BAD_USER                    = %ERROR_BAD_USERNAME
%WN_BAD_PASSWORD                = %ERROR_INVALID_PASSWORD
%WN_ACCESS_DENIED               = %ERROR_ACCESS_DENIED
%WN_FUNCTION_BUSY               = %ERROR_BUSY
%WN_WINDOWS_ERROR               = %ERROR_UNEXP_NET_ERR
%WN_OUT_OF_MEMORY               = %ERROR_NOT_ENOUGH_MEMORY
%WN_NO_NETWORK                  = %ERROR_NO_NETWORK
%WN_EXTENDED_ERROR              = %ERROR_EXTENDED_ERROR
%WN_BAD_LEVEL                   = %ERROR_INVALID_LEVEL
%WN_BAD_HANDLE                  = %ERROR_INVALID_HANDLE
#IF (%WINVER >= &H0400)
%WN_NOT_INITIALIZING            = %ERROR_ALREADY_INITIALIZED
%WN_NO_MORE_DEVICES             = %ERROR_NO_MORE_DEVICES
#ENDIF ' %WINVER >= &H0400

' Connection

%WN_NOT_CONNECTED                      = %ERROR_NOT_CONNECTED
%WN_OPEN_FILES                         = %ERROR_OPEN_FILES
%WN_DEVICE_IN_USE                      = %ERROR_DEVICE_IN_USE
%WN_BAD_NETNAME                        = %ERROR_BAD_NET_NAME
%WN_BAD_LOCALNAME                      = %ERROR_BAD_DEVICE
%WN_ALREADY_CONNECTED                  = %ERROR_ALREADY_ASSIGNED
%WN_DEVICE_ERROR                       = %ERROR_GEN_FAILURE
%WN_CONNECTION_CLOSED                  = %ERROR_CONNECTION_UNAVAIL
%WN_NO_NET_OR_BAD_PATH                 = %ERROR_NO_NET_OR_BAD_PATH
%WN_BAD_PROVIDER                       = %ERROR_BAD_PROVIDER
%WN_CANNOT_OPEN_PROFILE                = %ERROR_CANNOT_OPEN_PROFILE
%WN_BAD_PROFILE                        = %ERROR_BAD_PROFILE
%WN_BAD_DEV_TYPE                       = %ERROR_BAD_DEV_TYPE
%WN_DEVICE_ALREADY_REMEMBERED          = %ERROR_DEVICE_ALREADY_REMEMBERED
%WN_CONNECTED_OTHER_PASSWORD           = %ERROR_CONNECTED_OTHER_PASSWORD
#IF (%WINVER >= &H0501)
%WN_CONNECTED_OTHER_PASSWORD_DEFAULT   = %ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT
#ENDIF ' %WINVER >= &H0501

' Enumeration

%WN_NO_MORE_ENTRIES             = %ERROR_NO_MORE_ITEMS
%WN_NOT_CONTAINER               = %ERROR_NOT_CONTAINER

#IF (%WINVER >= &H0400)
' Authentication

%WN_NOT_AUTHENTICATED           = %ERROR_NOT_AUTHENTICATED
%WN_NOT_LOGGED_ON               = %ERROR_NOT_LOGGED_ON
%WN_NOT_VALIDATED               = %ERROR_NO_LOGON_SERVERS
#ENDIF ' %WINVER >= &H0400

'
'  For Shell
'

#IF (%WINVER >= &H0400)

TYPE NETCONNECTINFOSTRUCT
    cbStructure   AS DWORD
    dwFlags       AS DWORD
    dwSpeed       AS DWORD
    dwDelay       AS DWORD
    dwOptDataSize AS DWORD
END TYPE

%WNCON_FORNETCARD      = &H00000001
%WNCON_NOTROUTED       = &H00000002
%WNCON_SLOWLINK        = &H00000004
%WNCON_DYNAMIC         = &H00000008

DECLARE FUNCTION MultinetGetConnectionPerformanceA LIB "Mpr.dll" _
    ALIAS "MultinetGetConnectionPerformanceA" ( _
    lpNetResource          AS NETRESOURCEA, _
    lpNetConnectInfoStruct AS NETCONNECTINFOSTRUCT _
    ) AS DWORD

DECLARE FUNCTION MultinetGetConnectionPerformanceW LIB "Mpr.dll" _
    ALIAS "MultinetGetConnectionPerformanceW" ( _
    lpNetResource          AS NETRESOURCEW, _
    lpNetConnectInfoStruct AS NETCONNECTINFOSTRUCT _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION MultinetGetConnectionPerformance LIB "Mpr.dll" _
    ALIAS "MultinetGetConnectionPerformanceW" ( _
    lpNetResource          AS NETRESOURCEW, _
    lpNetConnectInfoStruct AS NETCONNECTINFOSTRUCT _
    ) AS DWORD
#ELSE
DECLARE FUNCTION MultinetGetConnectionPerformance LIB "Mpr.dll" _
    ALIAS "MultinetGetConnectionPerformanceA" ( _
    lpNetResource          AS NETRESOURCEA, _
    lpNetConnectInfoStruct AS NETCONNECTINFOSTRUCT _
    ) AS DWORD
#ENDIF ' NOT %UNICODE

#ENDIF ' %WINVER >= &H0400
