'------------------------------------------------------------------------------
'
'  LmWksta.inc
'    This file contains structures, function prototypes, and definitions
'    for the NetWorkstation and NetWkstaTransport API.
'
'  Copyright (c) 2002-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from LmWkSta.h build version 0006 of 14 Jul 2009
'------------------------------------------------------------------------------


#INCLUDE THIS ONCE

%LMWKSTA = 1


#INCLUDE "lmcons.inc"

#INCLUDE "lmuseflg.inc"                   ' Deletion force level flags

'
' Function Prototypes
'

DECLARE FUNCTION NetWkstaGetInfo LIB "NETAPI32.DLL" ALIAS "NetWkstaGetInfo" ( _
    servername   AS LMSTR, _
    BYVAL level  AS DWORD, _
    BYVAL bufptr AS BYTE PTR _
    ) AS DWORD

DECLARE FUNCTION NetWkstaSetInfo LIB "NETAPI32.DLL" ALIAS "NetWkstaSetInfo" ( _
    servername   AS LMSTR, _
    BYVAL level  AS DWORD, _
    BYVAL buffer AS BYTE PTR, _
    parm_err AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetWkstaUserGetInfo LIB "NETAPI32.DLL" ALIAS "NetWkstaUserGetInfo" ( _
    reserved     AS LMSTR, _
    BYVAL level  AS DWORD, _
    BYVAL bufptr AS BYTE PTR _
    ) AS DWORD

DECLARE FUNCTION NetWkstaUserSetInfo LIB "NETAPI32.DLL" ALIAS "NetWkstaUserSetInfo" ( _
    reserved    AS LMSTR, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    parm_err    AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetWkstaUserEnum LIB "NETAPI32.DLL" ALIAS "NetWkstaUserEnum" ( _
    servername       AS LMSTR, _
    BYVAL level      AS DWORD, _
    BYVAL bufptr     AS BYTE PTR, _
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resumehandle     AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetWkstaTransportAdd LIB "NETAPI32.DLL" ALIAS "NetWkstaTransportAdd" ( _
    servername  AS LMSTR, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    parm_err    AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetWkstaTransportDel LIB "NETAPI32.DLL" ALIAS "NetWkstaTransportDel" ( _
    servername    AS LMSTR, _
    transportname AS LMSTR, _
    BYVAL ucond   AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetWkstaTransportEnum LIB "NETAPI32.DLL" ALIAS "NetWkstaTransportEnum" ( _
    servername       AS LMSTR, _
    BYVAL level      AS DWORD, _
    BYVAL bufptr     AS BYTE PTR, _
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resumehandle     AS DWORD _
    ) AS DWORD

'
'  Data Structures
'

'
' NetWkstaGetInfo and NetWkstaSetInfo
'

'
' NetWkstaGetInfo only.  System information - guest access
'
TYPE WKSTA_INFO_100
    wki100_platform_id  AS DWORD
    wki100_computername AS LMSTR PTR
    wki100_langroup     AS LMSTR PTR
    wki100_ver_major    AS DWORD
    wki100_ver_minor    AS DWORD
END TYPE

'
' NetWkstaGetInfo only.  System information - user access
'
TYPE WKSTA_INFO_101
    wki101_platform_id  AS DWORD
    wki101_computername AS LMSTR PTR
    wki101_langroup     AS LMSTR PTR
    wki101_ver_major    AS DWORD
    wki101_ver_minor    AS DWORD
    wki101_lanroot      AS LMSTR PTR
END TYPE

'
' NetWkstaGetInfo only.  System information - admin or operator access
'
TYPE WKSTA_INFO_102
    wki102_platform_id     AS DWORD
    wki102_computername    AS LMSTR PTR
    wki102_langroup        AS LMSTR PTR
    wki102_ver_major       AS DWORD
    wki102_ver_minor       AS DWORD
    wki102_lanroot         AS LMSTR PTR
    wki102_logged_on_users AS DWORD
END TYPE

'
' Down-level NetWkstaGetInfo and NetWkstaSetInfo.
'
' DOS specific workstation information -
'    admin or domain operator access
'
TYPE WKSTA_INFO_302
    wki302_char_wait                AS DWORD
    wki302_collection_time          AS DWORD
    wki302_maximum_collection_count AS DWORD
    wki302_keep_conn                AS DWORD
    wki302_keep_search              AS DWORD
    wki302_max_cmds                 AS DWORD
    wki302_num_work_buf             AS DWORD
    wki302_siz_work_buf             AS DWORD
    wki302_max_wrk_cache            AS DWORD
    wki302_sess_timeout             AS DWORD
    wki302_siz_error                AS DWORD
    wki302_num_alerts               AS DWORD
    wki302_num_services             AS DWORD
    wki302_errlog_sz                AS DWORD
    wki302_print_buf_time           AS DWORD
    wki302_num_char_buf             AS DWORD
    wki302_siz_char_buf             AS DWORD
    wki302_wrk_heuristics           AS LMSTR PTR
    wki302_mailslots                AS DWORD
    wki302_num_dgram_buf            AS DWORD
END TYPE

'
' Down-level NetWkstaGetInfo and NetWkstaSetInfo
'
' OS/2 specific workstation information -
'    admin or domain operator access
'
TYPE WKSTA_INFO_402
    wki402_char_wait                AS DWORD
    wki402_collection_time          AS DWORD
    wki402_maximum_collection_count AS DWORD
    wki402_keep_conn                AS DWORD
    wki402_keep_search              AS DWORD
    wki402_max_cmds                 AS DWORD
    wki402_num_work_buf             AS DWORD
    wki402_siz_work_buf             AS DWORD
    wki402_max_wrk_cache            AS DWORD
    wki402_sess_timeout             AS DWORD
    wki402_siz_error                AS DWORD
    wki402_num_alerts               AS DWORD
    wki402_num_services             AS DWORD
    wki402_errlog_sz                AS DWORD
    wki402_print_buf_time           AS DWORD
    wki402_num_char_buf             AS DWORD
    wki402_siz_char_buf             AS DWORD
    wki402_wrk_heuristics           AS LMSTR PTR
    wki402_mailslots                AS DWORD
    wki402_num_dgram_buf            AS DWORD
    wki402_max_threads              AS DWORD
END TYPE

'
' Same-level NetWkstaGetInfo and NetWkstaSetInfo.
'
' NT specific workstation information -
'    admin or domain operator access
'
TYPE WKSTA_INFO_502
    wki502_char_wait                   AS DWORD
    wki502_collection_time             AS DWORD
    wki502_maximum_collection_count    AS DWORD
    wki502_keep_conn                   AS DWORD
    wki502_max_cmds                    AS DWORD
    wki502_sess_timeout                AS DWORD
    wki502_siz_char_buf                AS DWORD
    wki502_max_threads                 AS DWORD

    wki502_lock_quota                  AS DWORD
    wki502_lock_increment              AS DWORD
    wki502_lock_maximum                AS DWORD
    wki502_pipe_increment              AS DWORD
    wki502_pipe_maximum                AS DWORD
    wki502_cache_file_timeout          AS DWORD
    wki502_dormant_file_limit          AS DWORD
    wki502_read_ahead_throughput       AS DWORD

    wki502_num_mailslot_buffers        AS DWORD
    wki502_num_srv_announce_buffers    AS DWORD
    wki502_max_illegal_datagram_events AS DWORD
    wki502_illegal_datagram_event_reset_frequency AS DWORD
    wki502_log_election_packets        AS LONG

    wki502_use_opportunistic_locking   AS LONG
    wki502_use_unlock_behind           AS LONG
    wki502_use_close_behind            AS LONG
    wki502_buf_named_pipes             AS LONG
    wki502_use_lock_read_unlock        AS LONG
    wki502_utilize_nt_caching          AS LONG
    wki502_use_raw_read                AS LONG
    wki502_use_raw_write               AS LONG
    wki502_use_write_raw_data          AS LONG
    wki502_use_encryption              AS LONG
    wki502_buf_files_deny_write        AS LONG
    wki502_buf_read_only_files         AS LONG
    wki502_force_core_create_mode      AS LONG
    wki502_use_512_byte_max_transfer   AS LONG
END TYPE


'
' The following info-levels are only valid for NetWkstaSetInfo
'

'
' The following levels are supported on down-level systems (LAN Man 2.x)
' as well as NT systems:
'
TYPE WKSTA_INFO_1010
     wki1010_char_wait AS DWORD
END TYPE

TYPE WKSTA_INFO_1011
     wki1011_collection_time AS DWORD
END TYPE

TYPE WKSTA_INFO_1012
     wki1012_maximum_collection_count AS DWORD
END TYPE

'
' The following level are supported on down-level systems (LAN Man 2.x)
' only:
'
TYPE WKSTA_INFO_1027
     wki1027_errlog_sz AS DWORD
END TYPE

TYPE WKSTA_INFO_1028
     wki1028_print_buf_time AS DWORD
END TYPE

TYPE WKSTA_INFO_1032
     wki1032_wrk_heuristics AS DWORD
END TYPE

'
' The following levels are settable on NT systems, and have no
' effect on down-level systems (i.e. LANMan 2.x) since these
' fields cannot be set on them:
'
TYPE WKSTA_INFO_1013
     wki1013_keep_conn AS DWORD
END TYPE

TYPE WKSTA_INFO_1018
     wki1018_sess_timeout AS DWORD
END TYPE

TYPE WKSTA_INFO_1023
     wki1023_siz_char_buf AS DWORD
END TYPE

TYPE WKSTA_INFO_1033
     wki1033_max_threads AS DWORD
END TYPE

'
' The following levels are only supported on NT systems:
'
TYPE WKSTA_INFO_1041
    wki1041_lock_quota AS DWORD
END TYPE

TYPE WKSTA_INFO_1042
    wki1042_lock_increment AS DWORD
END TYPE

TYPE WKSTA_INFO_1043
    wki1043_lock_maximum AS DWORD
END TYPE

TYPE WKSTA_INFO_1044
    wki1044_pipe_increment AS DWORD
END TYPE

TYPE WKSTA_INFO_1045
    wki1045_pipe_maximum AS DWORD
END TYPE

TYPE WKSTA_INFO_1046
    wki1046_dormant_file_limit AS DWORD
END TYPE

TYPE WKSTA_INFO_1047
    wki1047_cache_file_timeout AS DWORD
END TYPE

TYPE WKSTA_INFO_1048
    wki1048_use_opportunistic_locking AS LONG
END TYPE

TYPE WKSTA_INFO_1049
    wki1049_use_unlock_behind AS LONG
END TYPE

TYPE WKSTA_INFO_1050
    wki1050_use_close_behind AS LONG
END TYPE

TYPE WKSTA_INFO_1051
    wki1051_buf_named_pipes AS LONG
END TYPE

TYPE WKSTA_INFO_1052
    wki1052_use_lock_read_unlock AS LONG
END TYPE

TYPE WKSTA_INFO_1053
    wki1053_utilize_nt_caching AS LONG
END TYPE

TYPE WKSTA_INFO_1054
    wki1054_use_raw_read AS LONG
END TYPE

TYPE WKSTA_INFO_1055
    wki1055_use_raw_write AS LONG
END TYPE

TYPE WKSTA_INFO_1056
    wki1056_use_write_raw_data AS LONG
END TYPE

TYPE WKSTA_INFO_1057
    wki1057_use_encryption AS LONG
END TYPE

TYPE WKSTA_INFO_1058
    wki1058_buf_files_deny_write AS LONG
END TYPE

TYPE WKSTA_INFO_1059
    wki1059_buf_read_only_files AS LONG
END TYPE

TYPE WKSTA_INFO_1060
    wki1060_force_core_create_mode AS LONG
END TYPE

TYPE WKSTA_INFO_1061
    wki1061_use_512_byte_max_transfer AS LONG
END TYPE

TYPE WKSTA_INFO_1062
    wki1062_read_ahead_throughput AS DWORD
END TYPE


'
' NetWkstaUserGetInfo (local only) and NetWkstaUserEnum -
'     no access restrictions.
'
TYPE WKSTA_USER_INFO_0
    wkui0_username AS LMSTR PTR
END TYPE

'
' NetWkstaUserGetInfo (local only) and NetWkstaUserEnum -
'     no access restrictions.
'
TYPE WKSTA_USER_INFO_1
    wkui1_username     AS LMSTR PTR
    wkui1_logon_domain AS LMSTR PTR
    wkui1_oth_domains  AS LMSTR PTR
    wkui1_logon_server AS LMSTR PTR
END TYPE

'
' NetWkstaUserSetInfo - local access.
'
TYPE WKSTA_USER_INFO_1101
     wkui1101_oth_domains AS LMSTR PTR
END TYPE


'
' NetWkstaTransportAdd - admin access
'
TYPE WKSTA_TRANSPORT_INFO_0
    wkti0_quality_of_service AS DWORD
    wkti0_number_of_vcs      AS DWORD
    wkti0_transport_name     AS LMSTR PTR
    wkti0_transport_address  AS LMSTR PTR
    wkti0_wan_ish            AS LONG
END TYPE


'
' Special Values and Constants
'

'
'  Identifiers for use as NetWkstaSetInfo parmnum parameter
'

'
' One of these values indicates the parameter within an information
' structure that is invalid when ERROR_INVALID_PARAMETER is returned by
' NetWkstaSetInfo.
'

%WKSTA_PLATFORM_ID_PARMNUM             = 100
%WKSTA_COMPUTERNAME_PARMNUM            = 1
%WKSTA_LANGROUP_PARMNUM                = 2
%WKSTA_VER_MAJOR_PARMNUM               = 4
%WKSTA_VER_MINOR_PARMNUM               = 5
%WKSTA_LOGGED_ON_USERS_PARMNUM         = 6
%WKSTA_LANROOT_PARMNUM                 = 7
%WKSTA_LOGON_DOMAIN_PARMNUM            = 8
%WKSTA_LOGON_SERVER_PARMNUM            = 9
%WKSTA_CHARWAIT_PARMNUM                = 10  ' Supported by down-level.
%WKSTA_CHARTIME_PARMNUM                = 11  ' Supported by down-level.
%WKSTA_CHARCOUNT_PARMNUM               = 12  ' Supported by down-level.
%WKSTA_KEEPCONN_PARMNUM                = 13
%WKSTA_KEEPSEARCH_PARMNUM              = 14
%WKSTA_MAXCMDS_PARMNUM                 = 15
%WKSTA_NUMWORKBUF_PARMNUM              = 16
%WKSTA_MAXWRKCACHE_PARMNUM             = 17
%WKSTA_SESSTIMEOUT_PARMNUM             = 18
%WKSTA_SIZERROR_PARMNUM                = 19
%WKSTA_NUMALERTS_PARMNUM               = 20
%WKSTA_NUMSERVICES_PARMNUM             = 21
%WKSTA_NUMCHARBUF_PARMNUM              = 22
%WKSTA_SIZCHARBUF_PARMNUM              = 23
%WKSTA_ERRLOGSZ_PARMNUM                = 27  ' Supported by down-level.
%WKSTA_PRINTBUFTIME_PARMNUM            = 28  ' Supported by down-level.
%WKSTA_SIZWORKBUF_PARMNUM              = 29
%WKSTA_MAILSLOTS_PARMNUM               = 30
%WKSTA_NUMDGRAMBUF_PARMNUM             = 31
%WKSTA_WRKHEURISTICS_PARMNUM           = 32  ' Supported by down-level.
%WKSTA_MAXTHREADS_PARMNUM              = 33

%WKSTA_LOCKQUOTA_PARMNUM               = 41
%WKSTA_LOCKINCREMENT_PARMNUM           = 42
%WKSTA_LOCKMAXIMUM_PARMNUM             = 43
%WKSTA_PIPEINCREMENT_PARMNUM           = 44
%WKSTA_PIPEMAXIMUM_PARMNUM             = 45
%WKSTA_DORMANTFILELIMIT_PARMNUM        = 46
%WKSTA_CACHEFILETIMEOUT_PARMNUM        = 47
%WKSTA_USEOPPORTUNISTICLOCKING_PARMNUM = 48
%WKSTA_USEUNLOCKBEHIND_PARMNUM         = 49
%WKSTA_USECLOSEBEHIND_PARMNUM          = 50
%WKSTA_BUFFERNAMEDPIPES_PARMNUM        = 51
%WKSTA_USELOCKANDREADANDUNLOCK_PARMNUM = 52
%WKSTA_UTILIZENTCACHING_PARMNUM        = 53
%WKSTA_USERAWREAD_PARMNUM              = 54
%WKSTA_USERAWWRITE_PARMNUM             = 55
%WKSTA_USEWRITERAWWITHDATA_PARMNUM     = 56
%WKSTA_USEENCRYPTION_PARMNUM           = 57
%WKSTA_BUFFILESWITHDENYWRITE_PARMNUM   = 58
%WKSTA_BUFFERREADONLYFILES_PARMNUM     = 59
%WKSTA_FORCECORECREATEMODE_PARMNUM     = 60
%WKSTA_USE512BYTESMAXTRANSFER_PARMNUM  = 61
%WKSTA_READAHEADTHRUPUT_PARMNUM        = 62


'
' One of these values indicates the parameter within an information
' structure that is invalid when %ERROR_INVALID_PARAMETER is returned by
' NetWkstaUserSetInfo.
'

%WKSTA_OTH_DOMAINS_PARMNUM             = 101


'
' One of these values indicates the parameter within an information
' structure that is invalid when %ERROR_INVALID_PARAMETER is returned by
' NetWkstaTransportAdd.
'

%TRANSPORT_QUALITYOFSERVICE_PARMNUM    = 201
%TRANSPORT_NAME_PARMNUM                = 202
