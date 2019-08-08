'------------------------------------------------------------------------------
'
'  LMaudit.inc
'    This module defines the API function prototypes and data structures
'    for the following groups of NT API functions:
'        NetAudit
'
'  Copyright (c) 2009-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from LMaudit.h build version 0003 dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%LMAUDIT = 1

#INCLUDE "LmCons.inc"

#IF NOT %DEF(%LMHLOGDEFINED)
%LMHLOGDEFINED = 1

TYPE HLOG
    time       AS DWORD
    last_flags AS DWORD
    offset     AS DWORD
    rec_offset AS DWORD
END TYPE

%LOGFLAGS_FORWARD  = 0
%LOGFLAGS_BACKWARD = &H1
%LOGFLAGS_SEEK     = &H2

#ENDIF

'
' Function Prototypes - Audit
'

DECLARE FUNCTION NetAuditClear LIB "NetApi32.dll" ALIAS "NetAuditClear" ( _
    server     AS WSTRINGZ, _
    backupfile AS WSTRINGZ, _
    service    AS WSTRINGZ _   ' WARNING: buggy support before LM 2.0C!!
    ) AS NET_API_STATUS

DECLARE FUNCTION NetAuditRead LIB "NetApi32.dll" ALIAS "NetAuditRead" ( _
    server           AS WSTRINGZ, _
    service          AS WSTRINGZ, _  ' WARNING: buggy support before LM 2.0C!!
    auditloghandle   AS HLOG, _
    BYVAL offset     AS DWORD, _
    reserved1        AS DWORD, _
    BYVAL reserved2  AS DWORD, _
    BYVAL offsetflag AS DWORD, _
    bufptr           AS ANY, _       ' BYTE PTR PTR
    BYVAL prefmaxlen AS DWORD, _
    bytesread        AS DWORD, _
    totalavailable   AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetAuditWrite LIB "NetApi32.dll" ALIAS "NetAuditWrite" ( _
    BYVAL dtype    AS DWORD, _
    BYVAL buf      AS BYTE PTR, _
    BYVAL numbytes AS DWORD, _
    service        AS WSTRINGZ, _
    BYVAL reserved AS BYTE PTR _
    ) AS NET_API_STATUS


'
' Data Structures - Audit
'

TYPE AUDIT_ENTRY
     ae_len         AS DWORD
     ae_reserved    AS DWORD
     ae_time        AS DWORD
     ae_type        AS DWORD
     ae_data_offset AS DWORD  ' Offset from beginning address of audit_entry
     ae_data_size   AS DWORD  ' byte count of ae_data area (not incl pad).
END TYPE

%REVISED_AUDIT_ENTRY_STRUCT = 1


TYPE AE_SRVSTATUS
     ae_sv_status AS DWORD
END TYPE

TYPE AE_SESSLOGON
     ae_so_compname  AS DWORD
     ae_so_username  AS DWORD
     ae_so_privilege AS DWORD
END TYPE

TYPE AE_SESSLOGOFF
     ae_sf_compname AS DWORD
     ae_sf_username AS DWORD
     ae_sf_reason   AS DWORD
END TYPE

TYPE AE_SESSPWERR
     ae_sp_compname AS DWORD
     ae_sp_username AS DWORD
END TYPE

TYPE AE_CONNSTART
     ae_ct_compname AS DWORD
     ae_ct_username AS DWORD
     ae_ct_netname  AS DWORD
     ae_ct_connid   AS DWORD
END TYPE

TYPE AE_CONNSTOP
     ae_cp_compname AS DWORD
     ae_cp_username AS DWORD
     ae_cp_netname  AS DWORD
     ae_cp_connid   AS DWORD
     ae_cp_reason   AS DWORD
END TYPE

TYPE AE_CONNREJ
     ae_cr_compname AS DWORD
     ae_cr_username AS DWORD
     ae_cr_netname  AS DWORD
     ae_cr_reason   AS DWORD
END TYPE

TYPE AE_RESACCESS
     ae_ra_compname   AS DWORD
     ae_ra_username   AS DWORD
     ae_ra_resname    AS DWORD
     ae_ra_operation  AS DWORD
     ae_ra_returncode AS DWORD
     ae_ra_restype    AS DWORD
     ae_ra_fileid     AS DWORD
END TYPE

TYPE AE_RESACCESSREJ
     ae_rr_compname  AS DWORD
     ae_rr_username  AS DWORD
     ae_rr_resname   AS DWORD
     ae_rr_operation AS DWORD
END TYPE

TYPE AE_CLOSEFILE
     ae_cf_compname AS DWORD
     ae_cf_username AS DWORD
     ae_cf_resname  AS DWORD
     ae_cf_fileid   AS DWORD
     ae_cf_duration AS DWORD
     ae_cf_reason   AS DWORD
END TYPE

TYPE AE_SERVICESTAT
     ae_ss_compname  AS DWORD
     ae_ss_username  AS DWORD
     ae_ss_svcname   AS DWORD
     ae_ss_status    AS DWORD
     ae_ss_code      AS DWORD
     ae_ss_text      AS DWORD
     ae_ss_returnval AS DWORD
END TYPE

TYPE AE_ACLMOD
     ae_am_compname AS DWORD
     ae_am_username AS DWORD
     ae_am_resname  AS DWORD
     ae_am_action   AS DWORD
     ae_am_datalen  AS DWORD
END TYPE

TYPE AE_UASMOD
     ae_um_compname AS DWORD
     ae_um_username AS DWORD
     ae_um_resname  AS DWORD
     ae_um_rectype  AS DWORD
     ae_um_action   AS DWORD
     ae_um_datalen  AS DWORD
END TYPE

TYPE AE_NETLOGON
     ae_no_compname  AS DWORD
     ae_no_username  AS DWORD
     ae_no_privilege AS DWORD
     ae_no_authflags AS DWORD
END TYPE

TYPE AE_NETLOGOFF
     ae_nf_compname  AS DWORD
     ae_nf_username  AS DWORD
     ae_nf_reserved1 AS DWORD
     ae_nf_reserved2 AS DWORD
END TYPE

TYPE AE_ACCLIM
     ae_al_compname AS DWORD
     ae_al_username AS DWORD
     ae_al_resname  AS DWORD
     ae_al_limit    AS DWORD
END TYPE

%ACTION_LOCKOUT        = 00
%ACTION_ADMINUNLOCK    = 01

TYPE AE_LOCKOUT
    ae_lk_compname     AS DWORD   ' Ptr to computername of client.
    ae_lk_username     AS DWORD   ' Ptr to username of client (NULL
                                  '  if same as computername).
    ae_lk_action       AS DWORD   ' Action taken on account:
                                  ' 0 means locked out, 1 means not.
    ae_lk_bad_pw_count AS DWORD   ' Bad password count at the time
                                  ' of lockout.
END TYPE

TYPE AE_GENERIC
     ae_ge_msgfile AS DWORD
     ae_ge_msgnum  AS DWORD
     ae_ge_params  AS DWORD
     ae_ge_param1  AS DWORD
     ae_ge_param2  AS DWORD
     ae_ge_param3  AS DWORD
     ae_ge_param4  AS DWORD
     ae_ge_param5  AS DWORD
     ae_ge_param6  AS DWORD
     ae_ge_param7  AS DWORD
     ae_ge_param8  AS DWORD
     ae_ge_param9  AS DWORD
END TYPE

'
' Special Values and Constants - Audit
'

'
'   Audit entry types (field ae_type in audit_entry).
'

%AE_SRVSTATUS    = 0
%AE_SESSLOGON    = 1
%AE_SESSLOGOFF   = 2
%AE_SESSPWERR    = 3
%AE_CONNSTART    = 4
%AE_CONNSTOP     = 5
%AE_CONNREJ      = 6
%AE_RESACCESS    = 7
%AE_RESACCESSREJ = 8
%AE_CLOSEFILE    = 9
%AE_SERVICESTAT  = 11
%AE_ACLMOD       = 12
%AE_UASMOD       = 13
%AE_NETLOGON     = 14
%AE_NETLOGOFF    = 15
%AE_NETLOGDENIED = 16
%AE_ACCLIMITEXCD = 17
%AE_RESACCESS2   = 18
%AE_ACLMODFAIL   = 19
%AE_LOCKOUT      = 20
%AE_GENERIC_TYPE = 21
'
'   Values for ae_ss_status field of ae_srvstatus.
'

%AE_SRVSTART  = 0
%AE_SRVPAUSED = 1
%AE_SRVCONT   = 2
%AE_SRVSTOP   = 3

'
'   Values for ae_so_privilege field of ae_sesslogon.
'

%AE_GUEST  = 0
%AE_USER   = 1
%AE_ADMIN  = 2

'
'   Values for various ae_XX_reason fields.
'

%AE_NORMAL        = 0
%AE_USERLIMIT     = 0
%AE_GENERAL       = 0
%AE_ERROR         = 1
%AE_SESSDIS       = 1
%AE_BADPW         = 1
%AE_AUTODIS       = 2
%AE_UNSHARE       = 2
%AE_ADMINPRIVREQD = 2
%AE_ADMINDIS      = 3
%AE_NOACCESSPERM  = 3
%AE_ACCRESTRICT   = 4

%AE_NORMAL_CLOSE  = 0
%AE_SES_CLOSE     = 1
%AE_ADMIN_CLOSE   = 2

'
' Values for xx_subreason fields.
'

%AE_LIM_UNKNOWN     = 0
%AE_LIM_LOGONHOURS  = 1
%AE_LIM_EXPIRED     = 2
%AE_LIM_INVAL_WKSTA = 3
%AE_LIM_DISABLED    = 4
%AE_LIM_DELETED     = 5

'
' Values for xx_action fields
'

%AE_MOD    = 0
%AE_DELETE = 1
%AE_ADD    = 2

'
' Types of UAS record for um_rectype field
'

%AE_UAS_USER   = 0
%AE_UAS_GROUP  = 1
%AE_UAS_MODALS = 2

'
' Bitmasks for auditing events
'
' The parentheses around the hex constants broke h_to_inc
' and have been purged from the face of the earth.
'

%SVAUD_SERVICE         = &H1
%SVAUD_GOODSESSLOGON   = &H6
%SVAUD_BADSESSLOGON    = &H18
%SVAUD_SESSLOGON       = (%SVAUD_GOODSESSLOGON OR %SVAUD_BADSESSLOGON)
%SVAUD_GOODNETLOGON    = &H60
%SVAUD_BADNETLOGON     = &H180
%SVAUD_NETLOGON        = (%SVAUD_GOODNETLOGON OR %SVAUD_BADNETLOGON)
%SVAUD_LOGON           = (%SVAUD_NETLOGON OR %SVAUD_SESSLOGON)
%SVAUD_GOODUSE         = &H600
%SVAUD_BADUSE          = &H1800
%SVAUD_USE             = (%SVAUD_GOODUSE OR %SVAUD_BADUSE)
%SVAUD_USERLIST        = &H2000
%SVAUD_PERMISSIONS     = &H4000
%SVAUD_RESOURCE        = &H8000??
%SVAUD_LOGONLIM    = &H00010000

'
' Resource access audit bitmasks.
'

%AA_AUDIT_ALL  =     &H0001
%AA_A_OWNER    = &H0004
%AA_CLOSE      = &H0008
%AA_S_OPEN     = &H0010
%AA_S_WRITE    = &H0020
%AA_S_CREATE   = &H0020
%AA_S_DELETE   = &H0040
%AA_S_ACL      = &H0080
%AA_S_ALL      = (%AA_S_OPEN OR %AA_S_WRITE OR %AA_S_DELETE OR %AA_S_ACL)
%AA_F_OPEN     = &H0100
%AA_F_WRITE    = &H0200
%AA_F_CREATE   = &H0200
%AA_F_DELETE   = &H0400
%AA_F_ACL      = &H0800
%AA_F_ALL      = (%AA_F_OPEN OR %AA_F_WRITE OR %AA_F_DELETE OR %AA_F_ACL)

' Pinball-specific
%AA_A_OPEN     = &H1000
%AA_A_WRITE    = &H2000
%AA_A_CREATE   = &H2000
%AA_A_DELETE   = &H4000
%AA_A_ACL      = &H8000??
%AA_A_ALL      = (%AA_F_OPEN OR %AA_F_WRITE OR %AA_F_DELETE OR %AA_F_ACL)
