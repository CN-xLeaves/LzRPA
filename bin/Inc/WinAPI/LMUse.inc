'------------------------------------------------------------------------------
'
'  LmUse.inc -- definitions for the NetUse API.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from LmUse.h build version 0001 of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%LMUSE = 1


#INCLUDE "lmcons.inc"
#INCLUDE "lmuseflg.inc"                   ' Deletion force level flags

'
' Function Prototypes
'

DECLARE FUNCTION NetUseAdd LIB "NetApi32.dll" ALIAS "NetUseAdd" ( _
    UncServerName AS LMSTR, _
    BYVAL Level   AS DWORD, _
    BYVAL Buf     AS BYTE PTR, _
    ParmError     AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetUseDel LIB "NetApi32.dll" ALIAS "NetUseDel" ( _
    UncServerName   AS LMSTR, _
    UseName         AS LMSTR, _
    BYVAL ForceCond AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetUseEnum LIB "NetApi32.dll" ALIAS "NetUseEnum" ( _
    UncServerName             AS LMSTR, _
    BYVAL Level               AS DWORD, _
    BufPtr                    AS ANY, _  ' BYTE PTR PTR
    BYVAL PreferedMaximumSize AS DWORD, _
    EntriesRead               AS DWORD, _
    TotalEntries              AS DWORD, _
    ResumeHandle              AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetUseGetInfo LIB "NetApi32.dll" ALIAS "NetUseGetInfo" ( _
    UncServerName AS LMSTR, _
    UseName       AS LMSTR, _
    BYVAL Level   AS DWORD, _
    BufPtr        AS ANY _  ' BYTE PTR PTR
    ) AS NET_API_STATUS

'
'  Data Structures
'

TYPE USE_INFO_0
    ui0_local  AS LMSTR PTR
    ui0_remote AS LMSTR PTR
END TYPE

TYPE USE_INFO_1
    ui1_local    AS LMSTR PTR
    ui1_remote   AS LMSTR PTR
    ui1_password AS LMSTR PTR
    ui1_status   AS DWORD
    ui1_asg_type AS DWORD
    ui1_refcount AS DWORD
    ui1_usecount AS DWORD
END TYPE

TYPE USE_INFO_2
    ui2_local      AS LMSTR PTR
    ui2_remote     AS LMSTR PTR
    ui2_password   AS LMSTR PTR
    ui2_status     AS DWORD
    ui2_asg_type   AS DWORD
    ui2_refcount   AS DWORD
    ui2_usecount   AS DWORD
    ui2_username   AS LMSTR PTR
    ui2_domainname AS LMSTR PTR
END TYPE

TYPE USE_INFO_3
    ui3_ui2   AS USE_INFO_2
    ui3_flags AS DWORD
END TYPE

TYPE USE_INFO_4
    ui4_ui3                  AS USE_INFO_3
    ui4_auth_identity_length AS DWORD
    ui4_auth_identity        AS BYTE PTR
END TYPE

'
' Special Values and Constants
'

'
' One of these values indicates the parameter within an information
' structure that is invalid when ERROR_INVALID_PARAMETER is returned by
' NetUseAdd.
'

%USE_LOCAL_PARMNUM      = 1
%USE_REMOTE_PARMNUM     = 2
%USE_PASSWORD_PARMNUM   = 3
%USE_ASGTYPE_PARMNUM    = 4
%USE_USERNAME_PARMNUM   = 5
%USE_DOMAINNAME_PARMNUM = 6

'
' Values appearing in the ui1_status field of use_info_1 structure.
' Note that USE_SESSLOST and USE_DISCONN are synonyms.
'

%USE_OK                = 0
%USE_PAUSED            = 1
%USE_SESSLOST          = 2
%USE_DISCONN           = 2
%USE_NETERR            = 3
%USE_CONN              = 4
%USE_RECONN            = 5


'
' Values of the ui1_asg_type field of use_info_1 structure
'

%USE_WILDCARD          = &HFFFFFFFF???  ' ( (DWORD) (-1) )
%USE_DISKDEV           = 0
%USE_SPOOLDEV          = 1
%USE_CHARDEV           = 2
%USE_IPC               = 3

'
' Flags defined in the use_info_3 structure
'

%CREATE_NO_CONNECT = &H1  ' creation flags
%CREATE_BYPASS_CSC = &H2  ' force connection to server, bypassing CSC
                          '  all ops on this connection go to the server,
                          '  never to the cache
%CREATE_CRED_RESET = &H4  ' Create a connection with credentials passed in
                          '  this netuse if none exist. If connection already
                          '  exists then update credentials after issuing
                          '  remote tree connection. This is needed as CSC
                          '  cannot verify credentials while offline.

%USE_DEFAULT_CREDENTIALS = &H4  ' No explicit credentials passed to NetUseAdd
