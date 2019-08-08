'------------------------------------------------------------------------------
'
'  LMRepl.inc - definitions for the replicator APIs.
'
'  Copyright (c) 2009-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from LMRepl.h build 0004 dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%LMREPL = 1

#INCLUDE "LmCons.inc"


'
' Replicator Configuration APIs
'

%REPL_ROLE_EXPORT      = 1
%REPL_ROLE_IMPORT      = 2
%REPL_ROLE_BOTH        = 3


%REPL_INTERVAL_INFOLEVEL       = (%PARMNUM_BASE_INFOLEVEL + 0)
%REPL_PULSE_INFOLEVEL          = (%PARMNUM_BASE_INFOLEVEL + 1)
%REPL_GUARDTIME_INFOLEVEL      = (%PARMNUM_BASE_INFOLEVEL + 2)
%REPL_RANDOM_INFOLEVEL         = (%PARMNUM_BASE_INFOLEVEL + 3)


TYPE REPL_INFO_0
    rp0_role          AS DWORD
    rp0_exportpath    AS WSTRINGZ PTR
    rp0_exportlist    AS WSTRINGZ PTR
    rp0_importpath    AS WSTRINGZ PTR
    rp0_importlist    AS WSTRINGZ PTR
    rp0_logonusername AS WSTRINGZ PTR
    rp0_interval      AS DWORD
    rp0_pulse         AS DWORD
    rp0_guardtime     AS DWORD
    rp0_random        AS DWORD
END TYPE

TYPE REPL_INFO_1000
    rp1000_interval AS DWORD
END TYPE

TYPE REPL_INFO_1001
    rp1001_pulse AS DWORD
END TYPE

TYPE REPL_INFO_1002
    rp1002_guardtime AS DWORD
END TYPE

TYPE REPL_INFO_1003
    rp1003_random AS DWORD
END TYPE


DECLARE FUNCTION NetReplGetInfo LIB "NetApi32.dll" ALIAS "NetReplGetInfo" ( _
    servername  AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    bufptr      AS ANY _  ' BYTE PTR PTR
    ) AS NET_API_STATUS

DECLARE FUNCTION NetReplSetInfo LIB "NetApi32.dll" ALIAS "NetReplSetInfo" ( _
    servername  AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    parm_err    AS DWORD _
    ) AS NET_API_STATUS


'
' Replicator Export Directory APIs
'

%REPL_INTEGRITY_FILE   = 1
%REPL_INTEGRITY_TREE   = 2


%REPL_EXTENT_FILE      = 1
%REPL_EXTENT_TREE      = 2


%REPL_EXPORT_INTEGRITY_INFOLEVEL = (%PARMNUM_BASE_INFOLEVEL + 0)
%REPL_EXPORT_EXTENT_INFOLEVEL    = (%PARMNUM_BASE_INFOLEVEL + 1)


TYPE REPL_EDIR_INFO_0
    rped0_dirname AS WSTRINGZ PTR
END TYPE

TYPE REPL_EDIR_INFO_1
    rped1_dirname   AS WSTRINGZ PTR
    rped1_integrity AS DWORD
    rped1_extent    AS DWORD
END TYPE

TYPE REPL_EDIR_INFO_2
    rped2_dirname    AS WSTRINGZ PTR
    rped2_integrity  AS DWORD
    rped2_extent     AS DWORD
    rped2_lockcount  AS DWORD
    rped2_locktime   AS DWORD
END TYPE

TYPE REPL_EDIR_INFO_1000
    rped1000_integrity AS DWORD
END TYPE

TYPE REPL_EDIR_INFO_1001
    rped1001_extent AS DWORD
END TYPE


DECLARE FUNCTION NetReplExportDirAdd LIB "NetApi32.dll" _
    ALIAS "NetReplExportDirAdd" ( _
    servername  AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    parm_err    AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetReplExportDirDel LIB "NetApi32.dll" _
    ALIAS "NetReplExportDirDel" ( _
    servername AS WSTRINGZ, _
    dirname    AS WSTRINGZ _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetReplExportDirEnum LIB "NetApi32.dll" _
    ALIAS "NetReplExportDirEnum" ( _
    servername       AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    bufptr           AS ANY, _  ' BYTE PTR PTR
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resumehandle     AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetReplExportDirGetInfo LIB "NetApi32.dll" _
    ALIAS "NetReplExportDirGetInfo" ( _
    servername  AS WSTRINGZ, _
    dirname     AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    bufptr      AS ANY _  ' BYTE PTR PTR
    ) AS NET_API_STATUS

DECLARE FUNCTION NetReplExportDirSetInfo LIB "NetApi32.dll" _
    ALIAS "NetReplExportDirSetInfo" ( _
    servername  AS WSTRINGZ, _
    dirname     AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    parm_err    AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetReplExportDirLock LIB "NetApi32.dll" _
    ALIAS "NetReplExportDirLock" ( _
    servername AS WSTRINGZ, _
    dirname    AS WSTRINGZ _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetReplExportDirUnlock LIB "NetApi32.dll" _
    ALIAS "NetReplExportDirUnlock" ( _
    servername        AS WSTRINGZ, _
    dirname           AS WSTRINGZ, _
    BYVAL unlockforce AS DWORD _
    ) AS NET_API_STATUS


%REPL_UNLOCK_NOFORCE   = 0
%REPL_UNLOCK_FORCE     = 1


'
' Replicator Import Directory APIs
'


TYPE REPL_IDIR_INFO_0
    rpid0_dirname AS WSTRINGZ PTR
END TYPE

TYPE REPL_IDIR_INFO_1
    rpid1_dirname          AS WSTRINGZ PTR
    rpid1_state            AS DWORD
    rpid1_mastername       AS WSTRINGZ PTR
    rpid1_last_update_time AS DWORD
    rpid1_lockcount        AS DWORD
    rpid1_locktime         AS DWORD
END TYPE


DECLARE FUNCTION NetReplImportDirAdd LIB "NetApi32.dll" _
    ALIAS "NetReplImportDirAdd" ( _
    servername  AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    parm_err    AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetReplImportDirDel LIB "NetApi32.dll" _
    ALIAS "NetReplImportDirDel" ( _
    servername AS WSTRINGZ, _
    dirname    AS WSTRINGZ _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetReplImportDirEnum LIB "NetApi32.dll" _
    ALIAS "NetReplImportDirEnum" ( _
    servername       AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    bufptr           AS ANY, _  ' BYTE PTR PTR
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resumehandle     AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetReplImportDirGetInfo LIB "NetApi32.dll" _
    ALIAS "NetReplImportDirGetInfo" ( _
    servername  AS WSTRINGZ, _
    dirname     AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    bufptr      AS ANY _  ' BYTE PTR PTR
    ) AS NET_API_STATUS

DECLARE FUNCTION NetReplImportDirLock LIB "NetApi32.dll" _
    ALIAS "NetReplImportDirLock" ( _
    servername AS WSTRINGZ, _
    dirname    AS WSTRINGZ _
    ) AS NET_API_STATUS


DECLARE FUNCTION NetReplImportDirUnlock LIB "NetApi32.dll" _
    ALIAS "NetReplImportDirUnlock" ( _
    servername        AS WSTRINGZ, _
    dirname           AS WSTRINGZ, _
    BYVAL unlockforce AS DWORD _
    ) AS NET_API_STATUS


%REPL_STATE_OK                 = 0
%REPL_STATE_NO_MASTER          = 1
%REPL_STATE_NO_SYNC            = 2
%REPL_STATE_NEVER_REPLICATED   = 3
