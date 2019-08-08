'------------------------------------------------------------------------------
'
'  LMShare.inc
'    This module defines the API function prototypes and data structures
'    for the following groups of NT API functions:
'        NetShare
'        NetSession
'        NetFile
'        NetConnection
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from LMShare.h build version 0001 dated 18 Jan 2008
'------------------------------------------------------------------------------


#INCLUDE THIS ONCE

#IF NOT %DEF(%LMSHARE)
%LMSHARE = 1

#INCLUDE "WinDef.inc"
#INCLUDE "LmCons.inc"

'
' Function Prototypes - Share
'

DECLARE FUNCTION NetShareAdd LIB "NetApi32.dll" ALIAS "NetShareAdd" ( _
    servername       AS LMSTR, _
    BYVAL level      AS DWORD, _
    BYVAL buf        AS BYTE PTR, _
    parm_err         AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetShareEnum LIB "NetApi32.dll" ALIAS "NetShareEnum" ( _
    servername       AS LMSTR, _
    BYVAL level      AS DWORD, _
    bufptr           AS ANY, _  ' BYTE PTR PTR
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resume_handle    AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetShareEnumSticky LIB "NetApi32.dll" _
    ALIAS "NetShareEnumSticky" ( _
    servername       AS LMSTR, _
    BYVAL level      AS DWORD, _
    bufptr           AS ANY, _  ' BYTE PTR PTR
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resume_handle    AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetShareGetInfo LIB "NetApi32.dll" ALIAS "NetShareGetInfo" ( _
    servername   AS LMSTR, _
    netname      AS LMSTR, _
    BYVAL level  AS DWORD, _
    bufptr       AS ANY _  ' BYTE PTR PTR
    ) AS NET_API_STATUS

DECLARE FUNCTION NetShareSetInfo LIB "NetApi32.dll" ALIAS "NetShareSetInfo" ( _
    servername  AS LMSTR, _
    netname     AS LMSTR, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    parm_err    AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetShareDel LIB "NetApi32.dll" ALIAS "NetShareDel" ( _
    servername     AS LMSTR, _
    netname        AS LMSTR, _
    BYVAL reserved AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetShareDelSticky LIB "NetApi32.dll" _
    ALIAS "NetShareDelSticky" ( _
    servername     AS LMSTR, _
    netname        AS LMSTR, _
    BYVAL reserved AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetShareCheck LIB "NetApi32.dll" ALIAS "NetShareCheck" ( _
    servername AS LMSTR, _
    device     AS LMSTR, _
    type       AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetShareDelEx LIB "NetApi32.dll" ALIAS "NetShareDelEx" ( _
    servername  AS LMSTR, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR _
    ) AS NET_API_STATUS

'
' Data Structures - Share
'

TYPE SHARE_INFO_0
    shi0_netname AS LMSTR PTR
END TYPE

TYPE SHARE_INFO_1
    shi1_netname AS LMSTR PTR
    shi1_type    AS DWORD
    shi1_remark  AS LMSTR PTR
END TYPE

TYPE SHARE_INFO_2
    shi2_netname      AS LMSTR PTR
    shi2_type         AS DWORD
    shi2_remark       AS LMSTR PTR
    shi2_permissions  AS DWORD
    shi2_max_uses     AS DWORD
    shi2_current_uses AS DWORD
    shi2_path         AS LMSTR PTR
    shi2_passwd       AS LMSTR PTR
END TYPE

TYPE SHARE_INFO_501
    shi501_netname AS LMSTR PTR
    shi501_type    AS DWORD
    shi501_remark  AS LMSTR PTR
    shi501_flags   AS DWORD
END TYPE

TYPE SHARE_INFO_502
    shi502_netname      AS LMSTR PTR
    shi502_type         AS DWORD
    shi502_remark       AS LMSTR PTR
    shi502_permissions  AS DWORD
    shi502_max_uses     AS DWORD
    shi502_current_uses AS DWORD
    shi502_path         AS LMSTR PTR
    shi502_passwd       AS LMSTR PTR
    shi502_reserved     AS DWORD
    shi502_security_descriptor AS SECURITY_DESCRIPTOR PTR
END TYPE

TYPE SHARE_INFO_503
    shi503_netname      AS LMSTR PTR
    shi503_type         AS DWORD
    shi503_remark       AS LMSTR PTR
    shi503_permissions  AS DWORD
    shi503_max_uses     AS DWORD
    shi503_current_uses AS DWORD
    shi503_path         AS LMSTR PTR
    shi503_passwd       AS LMSTR PTR
    shi503_servername   AS LMSTR PTR
    shi503_reserved     AS DWORD
    shi503_security_descriptor AS SECURITY_DESCRIPTOR PTR
END TYPE

TYPE SHARE_INFO_1004
    shi1004_remark AS LMSTR PTR
END TYPE

TYPE SHARE_INFO_1005
    shi1005_flags AS DWORD
END TYPE

TYPE SHARE_INFO_1006
    shi1006_max_uses AS DWORD
END TYPE

TYPE SHARE_INFO_1501
    shi1501_reserved AS DWORD
    shi1501_security_descriptor AS SECURITY_DESCRIPTOR PTR
END TYPE

TYPE SHARE_INFO_1503
    shi1503_sharefilter AS GUID
END TYPE

'
' NetShareAlias functions
'
DECLARE FUNCTION NetServerAliasAdd LIB "NetApi32.dll" _
    ALIAS "NetServerAliasAdd" ( _
    servername  AS LMSTR, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetServerAliasDel LIB "NetApi32.dll" _
    ALIAS "NetServerAliasDel" ( _
    servername  AS LMSTR, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetServerAliasEnum LIB "NetApi32.dll" _
    ALIAS "NetServerAliasEnum" ( _
    servername       AS LMSTR, _
    BYVAL level      AS DWORD, _
    bufptr           AS ANY, _  ' BYTE PTR PTR
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resumehandle     AS DWORD _
    ) AS NET_API_STATUS

TYPE SERVER_ALIAS_INFO_0
    srvai0_alias    AS LMSTR PTR
    srvai0_target   AS LMSTR PTR
    srvai0_default  AS BYTE  ' BOOLEAN
    srvai0_reserved AS DWORD
END TYPE

'
' Special Values and Constants - Share
'

'
' Values for parm_err parameter.
'

%SHARE_NETNAME_PARMNUM      =   1
%SHARE_TYPE_PARMNUM         =   3
%SHARE_REMARK_PARMNUM       =   4
%SHARE_PERMISSIONS_PARMNUM  =   5
%SHARE_MAX_USES_PARMNUM     =   6
%SHARE_CURRENT_USES_PARMNUM =   7
%SHARE_PATH_PARMNUM         =   8
%SHARE_PASSWD_PARMNUM       =   9
%SHARE_FILE_SD_PARMNUM      = 501
%SHARE_SERVER_PARMNUM       = 503

'
' Single-field infolevels for NetShareSetInfo.
'

%SHARE_REMARK_INFOLEVEL         = _
            (%PARMNUM_BASE_INFOLEVEL + %SHARE_REMARK_PARMNUM)
%SHARE_MAX_USES_INFOLEVEL       = _
            (%PARMNUM_BASE_INFOLEVEL + %SHARE_MAX_USES_PARMNUM)
%SHARE_FILE_SD_INFOLEVEL        = _
            (%PARMNUM_BASE_INFOLEVEL + %SHARE_FILE_SD_PARMNUM)

%SHI1_NUM_ELEMENTS     = 4
%SHI2_NUM_ELEMENTS     = 10


'
' Share types (shi1_type and shi2_type fields).
'

%STYPE_DISKTREE        = 0
%STYPE_PRINTQ          = 1
%STYPE_DEVICE          = 2
%STYPE_IPC             = 3

%STYPE_TEMPORARY       = &H40000000
%STYPE_SPECIAL         = &H80000000???

%SHI_USES_UNLIMITED    = &HFFFFFFFF??? ' (DWORD)-1

'
' Flags values for the 501 and 1005 levels
'
%SHI1005_FLAGS_DFS      = &H01    ' Share is in the DFS
%SHI1005_FLAGS_DFS_ROOT = &H02    ' Share is root of DFS

%CSC_MASK               = &H30    ' Used to mask off the following states

%CSC_CACHE_MANUAL_REINT = &H00    ' No automatic file by file reintegration
%CSC_CACHE_AUTO_REINT   = &H10    ' File by file reintegration is OK
%CSC_CACHE_VDO          = &H20    ' no need to flow opens
%CSC_CACHE_NONE         = &H30    ' no CSC for this share

%SHI1005_FLAGS_RESTRICT_EXCLUSIVE_OPENS    = &H0100  ' Used to disallow read-deny read behavior
%SHI1005_FLAGS_FORCE_SHARED_DELETE         = &H0200  ' Used to allows force shared delete
%SHI1005_FLAGS_ALLOW_NAMESPACE_CACHING     = &H0400  ' The clients may cache the namespace
%SHI1005_FLAGS_ACCESS_BASED_DIRECTORY_ENUM = &H0800  ' Trim visible files in enumerations based on access

'
' The subset of 1005 infolevel flags that can be set via the API
'

%SHI1005_VALID_FLAGS_SET = (%CSC_MASK OR                                     _
                            %SHI1005_FLAGS_RESTRICT_EXCLUSIVE_OPENS OR       _
                            %SHI1005_FLAGS_FORCE_SHARED_DELETE OR            _
                            %SHI1005_FLAGS_ALLOW_NAMESPACE_CACHING OR        _
                            %SHI1005_FLAGS_ACCESS_BASED_DIRECTORY_ENUM)

#ENDIF ' %LMSHARE

'
' SESSION API
'

#IF NOT %DEF(%LMSESSION)
%LMSESSION = 1

'
' Function Prototypes Session
'

DECLARE FUNCTION NetSessionEnum LIB "NetApi32.dll" ALIAS "NetSessionEnum" ( _
    servername       AS LMSTR, _
    UncClientName    AS LMSTR, _
    username         AS LMSTR, _
    BYVAL level      AS DWORD, _
    bufptr           AS ANY, _  ' BYTE PTR PTR
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resume_handle    AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetSessionDel LIB "NetApi32.dll" ALIAS "NetSessionDel" ( _
    servername    AS LMSTR, _
    UncClientName AS LMSTR, _
    username      AS LMSTR _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetSessionGetInfo LIB "NetApi32.dll" _
    ALIAS "NetSessionGetInfo" ( _
    servername    AS LMSTR, _
    UncClientName AS LMSTR, _
    username      AS LMSTR, _
    BYVAL level   AS DWORD, _
    bufptr        AS ANY _  ' BYTE PTR PTR
    ) AS NET_API_STATUS


'
' Data Structures - Session
'

TYPE SESSION_INFO_0
    sesi0_cname AS LMSTR PTR               ' client name (no backslashes)
END TYPE

TYPE SESSION_INFO_1
    sesi1_cname      AS LMSTR PTR          ' client name (no backslashes)
    sesi1_username   AS LMSTR PTR
    sesi1_num_opens  AS DWORD
    sesi1_time       AS DWORD
    sesi1_idle_time  AS DWORD
    sesi1_user_flags AS DWORD
END TYPE

TYPE SESSION_INFO_2
    sesi2_cname       AS LMSTR PTR         ' client name (no backslashes)
    sesi2_username    AS LMSTR PTR
    sesi2_num_opens   AS DWORD
    sesi2_time        AS DWORD
    sesi2_idle_time   AS DWORD
    sesi2_user_flags  AS DWORD
    sesi2_cltype_name AS LMSTR PTR
END TYPE

TYPE SESSION_INFO_10
    sesi10_cname     AS LMSTR PTR          ' client name (no backslashes)
    sesi10_username  AS LMSTR PTR
    sesi10_time      AS DWORD
    sesi10_idle_time AS DWORD
END TYPE

TYPE SESSION_INFO_502
    sesi502_cname       AS LMSTR PTR       ' client name (no backslashes)
    sesi502_username    AS LMSTR PTR
    sesi502_num_opens   AS DWORD
    sesi502_time        AS DWORD
    sesi502_idle_time   AS DWORD
    sesi502_user_flags  AS DWORD
    sesi502_cltype_name AS LMSTR PTR
    sesi502_transport   AS LMSTR PTR
END TYPE


'
' Special Values and Constants - Session
'


'
' Bits defined in sesi1_user_flags.
'

%SESS_GUEST         = &H00000001  ' session is logged on as a guest
%SESS_NOENCRYPTION  = &H00000002  ' session is not using encryption

%SESI1_NUM_ELEMENTS = 8
%SESI2_NUM_ELEMENTS = 9

#ENDIF ' %LMSESSION

'
' CONNECTION API
'

#IF NOT %DEF(%LMCONNECTION)

%LMCONNECTION = 1

'
' Function Prototypes - CONNECTION
'

DECLARE FUNCTION NetConnectionEnum LIB "NetApi32.dll" _
    ALIAS "NetConnectionEnum" ( _
    servername       AS LMSTR, _
    qualifier        AS LMSTR, _
    BYVAL level      AS DWORD, _
    bufptr           AS ANY, _  ' BYTE PTR PTR
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resume_handle    AS DWORD _
    ) AS NET_API_STATUS


'
' Data Structures - CONNECTION
'

TYPE CONNECTION_INFO_0
    coni0_id AS DWORD
END TYPE

TYPE CONNECTION_INFO_1
    coni1_id        AS DWORD
    coni1_type      AS DWORD
    coni1_num_opens AS DWORD
    coni1_num_users AS DWORD
    coni1_time      AS DWORD
    coni1_username  AS LMSTR PTR
    coni1_netname   AS LMSTR PTR
END TYPE

#ENDIF ' %LMCONNECTION




'
' FILE API
'

#IF NOT %DEF(%LMFILE)
%LMFILE = 1

'
' Function Prototypes - FILE
'

DECLARE FUNCTION NetFileClose LIB "NetApi32.dll" ALIAS "NetFileClose" ( _
    servername   AS LMSTR, _
    BYVAL fileid AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetFileEnum LIB "NetApi32.dll" ALIAS "NetFileEnum" ( _
    servername       AS LMSTR, _
    basepath         AS LMSTR, _
    username         AS LMSTR, _
    BYVAL level      AS DWORD, _
    bufptr           AS ANY, _  ' BYTE PTR PTR
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resume_handle    AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetFileGetInfo LIB "NetApi32.dll" ALIAS "NetFileGetInfo" ( _
    servername   AS LMSTR, _
    BYVAL fileid AS DWORD, _
    BYVAL level  AS DWORD, _
    bufptr       AS ANY _  ' BYTE PTR PTR
    ) AS NET_API_STATUS

'
' Data Structures - File
'

'  File APIs are available at information levels 2 & 3 only. Levels 0 &
'  1 are not supported.
'

TYPE FILE_INFO_2
    fi2_id AS DWORD
END TYPE

TYPE FILE_INFO_3
    fi3_id          AS DWORD
    fi3_permissions AS DWORD
    fi3_num_locks   AS DWORD
    fi3_pathname    AS LMSTR PTR
    fi3_username    AS LMSTR PTR
END TYPE

'
' Special Values and Constants - File
'

'
' bit values for permissions
'

%PERM_FILE_READ    = &H1 ' user has read access
%PERM_FILE_WRITE   = &H2 ' user has write access
%PERM_FILE_CREATE  = &H4 ' user has create access

#ENDIF ' #IF NOT %DEF(%LMFILE)
