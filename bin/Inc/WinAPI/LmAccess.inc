'------------------------------------------------------------------------------
'
'  LmAccess.inc
'    This file contains structures, function prototypes, and definitions
'    for the NetUser, NetUserModals, NetGroup, NetAccess, and NetLogon API.
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from LmAccess.h build version 0002 of 14 Jul 2009
'------------------------------------------------------------------------------


'
' User Class
'

#INCLUDE THIS ONCE

#IF NOT %DEF(%LMUSER)
%LMUSER = 1

#INCLUDE "LmCons.inc"     ' unfortunately created a dependence on this


'
' Function Prototypes - User
'

DECLARE FUNCTION NetUserAdd LIB "NetAPI32.dll" ALIAS "NetUserAdd" ( _
    servername       AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    BYVAL buf        AS BYTE PTR, _
    parm_err         AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetUserEnum LIB "NetAPI32.dll" ALIAS "NetUserEnum" ( _
    servername       AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    BYVAL filter     AS DWORD, _
    BYVAL bufptr     AS BYTE PTR, _
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resume_handle    AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetUserGetInfo LIB "NetAPI32.dll" ALIAS "NetUserGetInfo" ( _
    servername       AS WSTRINGZ, _
    username         AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    BYVAL bufptr     AS BYTE PTR _
    ) AS DWORD

DECLARE FUNCTION NetUserSetInfo LIB "NetAPI32.dll" ALIAS "NetUserSetInfo" ( _
    servername       AS WSTRINGZ, _
    username         AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    BYVAL buf        AS BYTE PTR, _
    parm_err         AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetUserDel LIB "NetAPI32.dll" ALIAS "NetUserDel" ( _
    servername AS WSTRINGZ, _
    username   AS WSTRINGZ _
    ) AS DWORD

DECLARE FUNCTION NetUserGetGroups LIB "NetAPI32.dll" ALIAS "NetUserGetGroups" ( _
    servername       AS WSTRINGZ, _
    username         AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    BYVAL bufptr     AS BYTE PTR, _
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetUserSetGroups LIB "NetAPI32.dll" ALIAS "NetUserSetGroups" ( _
    servername        AS WSTRINGZ, _
    username          AS WSTRINGZ, _
    BYVAL level       AS DWORD, _
    BYVAL buf         AS BYTE PTR, _
    BYVAL num_entries AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetUserGetLocalGroups LIB "NetAPI32.dll" ALIAS "NetUserGetLocalGroups" ( _
    servername       AS WSTRINGZ, _
    username         AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    BYVAL flags      AS DWORD, _
    BYVAL bufptr     AS BYTE PTR, _
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetUserModalsGet LIB "NetAPI32.dll" ALIAS "NetUserModalsGet" ( _
    servername   AS WSTRINGZ, _
    BYVAL level  AS DWORD, _
    BYVAL bufptr AS BYTE PTR _
    ) AS DWORD

DECLARE FUNCTION NetUserModalsSet LIB "NetAPI32.dll" ALIAS "NetUserModalsSet" ( _
    servername  AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    parm_err    AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetUserChangePassword LIB "NetAPI32.dll" ALIAS "NetUserChangePassword" ( _
    domainname  AS WSTRINGZ, _
    username    AS WSTRINGZ, _
    oldpassword AS WSTRINGZ, _
    newpassword AS WSTRINGZ _
    ) AS DWORD


'
'  Data Structures - User
'

TYPE USER_INFO_0
    usri0_name AS WSTRINGZ PTR
END TYPE

TYPE USER_INFO_1
    usri1_name         AS WSTRINGZ PTR
    usri1_password     AS WSTRINGZ PTR
    usri1_password_age AS DWORD
    usri1_priv         AS DWORD
    usri1_home_dir     AS WSTRINGZ PTR
    usri1_comment      AS WSTRINGZ PTR
    usri1_flags        AS DWORD
    usri1_script_path  AS WSTRINGZ PTR
END TYPE

TYPE USER_INFO_2
    usri2_name           AS WSTRINGZ PTR
    usri2_password       AS WSTRINGZ PTR
    usri2_password_age   AS DWORD
    usri2_priv           AS DWORD
    usri2_home_dir       AS WSTRINGZ PTR
    usri2_comment        AS WSTRINGZ PTR
    usri2_flags          AS DWORD
    usri2_script_path    AS WSTRINGZ PTR
    usri2_auth_flags     AS DWORD
    usri2_full_name      AS WSTRINGZ PTR
    usri2_usr_comment    AS WSTRINGZ PTR
    usri2_parms          AS WSTRINGZ PTR
    usri2_workstations   AS WSTRINGZ PTR
    usri2_last_logon     AS DWORD
    usri2_last_logoff    AS DWORD
    usri2_acct_expires   AS DWORD
    usri2_max_storage    AS DWORD
    usri2_units_per_week AS DWORD
    usri2_logon_hours    AS BYTE PTR
    usri2_bad_pw_count   AS DWORD
    usri2_num_logons     AS DWORD
    usri2_logon_server   AS WSTRINGZ PTR
    usri2_country_code   AS DWORD
    usri2_code_page      AS DWORD
END TYPE

TYPE USER_INFO_3
    usri3_name              AS WSTRINGZ PTR
    usri3_password          AS WSTRINGZ PTR
    usri3_password_age      AS DWORD
    usri3_priv              AS DWORD
    usri3_home_dir          AS WSTRINGZ PTR
    usri3_comment           AS WSTRINGZ PTR
    usri3_flags             AS DWORD
    usri3_script_path       AS WSTRINGZ PTR
    usri3_auth_flags        AS DWORD
    usri3_full_name         AS WSTRINGZ PTR
    usri3_usr_comment       AS WSTRINGZ PTR
    usri3_parms             AS WSTRINGZ PTR
    usri3_workstations      AS WSTRINGZ PTR
    usri3_last_logon        AS DWORD
    usri3_last_logoff       AS DWORD
    usri3_acct_expires      AS DWORD
    usri3_max_storage       AS DWORD
    usri3_units_per_week    AS DWORD
    usri3_logon_hours       AS BYTE PTR
    usri3_bad_pw_count      AS DWORD
    usri3_num_logons        AS DWORD
    usri3_logon_server      AS WSTRINGZ PTR
    usri3_country_code      AS DWORD
    usri3_code_page         AS DWORD
    usri3_user_id           AS DWORD
    usri3_primary_group_id  AS DWORD
    usri3_profile           AS WSTRINGZ PTR
    usri3_home_dir_drive    AS WSTRINGZ PTR
    usri3_password_expired  AS DWORD
END TYPE

TYPE USER_INFO_4
    usri4_name             AS WSTRINGZ PTR
    usri4_password         AS WSTRINGZ PTR
    usri4_password_age     AS DWORD
    usri4_priv             AS DWORD
    usri4_home_dir         AS WSTRINGZ PTR
    usri4_comment          AS WSTRINGZ PTR
    usri4_flags            AS DWORD
    usri4_script_path      AS WSTRINGZ PTR
    usri4_auth_flags       AS DWORD
    usri4_full_name        AS WSTRINGZ PTR
    usri4_usr_comment      AS WSTRINGZ PTR
    usri4_parms            AS WSTRINGZ PTR
    usri4_workstations     AS WSTRINGZ PTR
    usri4_last_logon       AS DWORD
    usri4_last_logoff      AS DWORD
    usri4_acct_expires     AS DWORD
    usri4_max_storage      AS DWORD
    usri4_units_per_week   AS DWORD
    usri4_logon_hours      AS BYTE PTR
    usri4_bad_pw_count     AS DWORD
    usri4_num_logons       AS DWORD
    usri4_logon_server     AS WSTRINGZ PTR
    usri4_country_code     AS DWORD
    usri4_code_page        AS DWORD
    usri4_user_sid         AS SID PTR
    usri4_primary_group_id AS DWORD
    usri4_profile          AS WSTRINGZ PTR
    usri4_home_dir_drive   AS WSTRINGZ PTR
    usri4_password_expired AS DWORD
END TYPE

TYPE USER_INFO_10
    usri10_name        AS WSTRINGZ PTR
    usri10_comment     AS WSTRINGZ PTR
    usri10_usr_comment AS WSTRINGZ PTR
    usri10_full_name   AS WSTRINGZ PTR
END TYPE

TYPE USER_INFO_11
    usri11_name           AS WSTRINGZ PTR
    usri11_comment        AS WSTRINGZ PTR
    usri11_usr_comment    AS WSTRINGZ PTR
    usri11_full_name      AS WSTRINGZ PTR
    usri11_priv           AS DWORD
    usri11_auth_flags     AS DWORD
    usri11_password_age   AS DWORD
    usri11_home_dir       AS WSTRINGZ PTR
    usri11_parms          AS WSTRINGZ PTR
    usri11_last_logon     AS DWORD
    usri11_last_logoff    AS DWORD
    usri11_bad_pw_count   AS DWORD
    usri11_num_logons     AS DWORD
    usri11_logon_server   AS WSTRINGZ PTR
    usri11_country_code   AS DWORD
    usri11_workstations   AS WSTRINGZ PTR
    usri11_max_storage    AS DWORD
    usri11_units_per_week AS DWORD
    usri11_logon_hours    AS BYTE PTR
    usri11_code_page      AS DWORD
END TYPE

TYPE USER_INFO_20
    usri20_name      AS WSTRINGZ PTR
    usri20_full_name AS WSTRINGZ PTR
    usri20_comment   AS WSTRINGZ PTR
    usri20_flags     AS DWORD
    usri20_user_id   AS DWORD
END TYPE

TYPE USER_INFO_21
    usri21_password AS STRING * %ENCRYPTED_PWLEN
END TYPE

TYPE USER_INFO_22
    usri22_name           AS WSTRINGZ PTR
    usri22_password       AS STRING * %ENCRYPTED_PWLEN
    usri22_password_age   AS DWORD
    usri22_priv           AS DWORD
    usri22_home_dir       AS WSTRINGZ PTR
    usri22_comment        AS WSTRINGZ PTR
    usri22_flags          AS DWORD
    usri22_script_path    AS WSTRINGZ PTR
    usri22_auth_flags     AS DWORD
    usri22_full_name      AS WSTRINGZ PTR
    usri22_usr_comment    AS WSTRINGZ PTR
    usri22_parms          AS WSTRINGZ PTR
    usri22_workstations   AS WSTRINGZ PTR
    usri22_last_logon     AS DWORD
    usri22_last_logoff    AS DWORD
    usri22_acct_expires   AS DWORD
    usri22_max_storage    AS DWORD
    usri22_units_per_week AS DWORD
    usri22_logon_hours    AS BYTE PTR
    usri22_bad_pw_count   AS DWORD
    usri22_num_logons     AS DWORD
    usri22_logon_server   AS WSTRINGZ PTR
    usri22_country_code   AS DWORD
    usri22_code_page      AS DWORD
END TYPE

TYPE USER_INFO_23
    usri23_name      AS WSTRINGZ PTR
    usri23_full_name AS WSTRINGZ PTR
    usri23_comment   AS WSTRINGZ PTR
    usri23_flags     AS DWORD
    usri23_user_sid  AS SID PTR
END TYPE

TYPE USER_INFO_1003
     usri1003_password AS WSTRINGZ PTR
END TYPE

TYPE USER_INFO_1005
     usri1005_priv AS DWORD
END TYPE

TYPE USER_INFO_1006
     usri1006_home_dir AS WSTRINGZ PTR
END TYPE

TYPE USER_INFO_1007
     usri1007_comment AS WSTRINGZ PTR
END TYPE

TYPE USER_INFO_1008
     usri1008_flags AS DWORD
END TYPE

TYPE USER_INFO_1009
     usri1009_script_path AS WSTRINGZ PTR
END TYPE

TYPE USER_INFO_1010
     usri1010_auth_flags AS DWORD
END TYPE

TYPE USER_INFO_1011
     usri1011_full_name AS WSTRINGZ PTR
END TYPE

TYPE USER_INFO_1012
     usri1012_usr_comment AS WSTRINGZ PTR
END TYPE

TYPE USER_INFO_1013
     usri1013_parms AS WSTRINGZ PTR
END TYPE

TYPE USER_INFO_1014
     usri1014_workstations AS WSTRINGZ PTR
END TYPE

TYPE USER_INFO_1017
     usri1017_acct_expires AS DWORD
END TYPE

TYPE USER_INFO_1018
     usri1018_max_storage AS DWORD
END TYPE

TYPE USER_INFO_1020
    usri1020_units_per_week AS DWORD
    usri1020_logon_hours    AS BYTE PTR
END TYPE

TYPE USER_INFO_1023
     usri1023_logon_server AS WSTRINGZ PTR
END TYPE

TYPE USER_INFO_1024
     usri1024_country_code AS DWORD
END TYPE

TYPE USER_INFO_1025
     usri1025_code_page AS DWORD
END TYPE

TYPE USER_INFO_1051
     usri1051_primary_group_id AS DWORD
END TYPE

TYPE USER_INFO_1052
     usri1052_profile AS WSTRINGZ PTR
END TYPE

TYPE USER_INFO_1053
     usri1053_home_dir_drive AS WSTRINGZ PTR
END TYPE


'
'  Data Structures - User Modals
'

TYPE USER_MODALS_INFO_0
    usrmod0_min_passwd_len    AS DWORD
    usrmod0_max_passwd_age    AS DWORD
    usrmod0_min_passwd_age    AS DWORD
    usrmod0_force_logoff      AS DWORD
    usrmod0_password_hist_len AS DWORD
END TYPE

TYPE USER_MODALS_INFO_
    usrmod1_role    AS DWORD
    usrmod1_primary AS WSTRINGZ PTR
END TYPE

TYPE USER_MODALS_INFO_2
    usrmod2_domain_name AS WSTRINGZ PTR
    usrmod2_domain_id   AS SID PTR
END TYPE

TYPE USER_MODALS_INFO_3
    usrmod3_lockout_duration           AS DWORD
    usrmod3_lockout_observation_window AS DWORD
    usrmod3_lockout_threshold          AS DWORD
END TYPE

TYPE USER_MODALS_INFO_1001
     usrmod1001_min_passwd_len AS DWORD
END TYPE

TYPE USER_MODALS_INFO_1002
     usrmod1002_max_passwd_age AS DWORD
END TYPE

TYPE USER_MODALS_INFO_1003
     usrmod1003_min_passwd_age AS DWORD
END TYPE

TYPE USER_MODALS_INFO_1004
     usrmod1004_force_logoff AS DWORD
END TYPE

TYPE USER_MODALS_INFO_1005
     usrmod1005_password_hist_len AS DWORD
END TYPE

TYPE USER_MODALS_INFO_1006
     usrmod1006_role AS DWORD
END TYPE

TYPE USER_MODALS_INFO_1007
     usrmod1007_primary AS WSTRINGZ PTR
END TYPE


'
' Special Values and Constants - User
'

'
'  Bit masks for field usriX_flags of USER_INFO_X (X = 0/1).
'

%UF_SCRIPT                          = &H0001
%UF_ACCOUNTDISABLE                  = &H0002
%UF_HOMEDIR_REQUIRED                = &H0008
%UF_LOCKOUT                         = &H0010
%UF_PASSWD_NOTREQD                  = &H0020
%UF_PASSWD_CANT_CHANGE              = &H0040
%UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED = &H0080

'
' Account type bits as part of usri_flags.
'

%UF_TEMP_DUPLICATE_ACCOUNT       = &H0100
%UF_NORMAL_ACCOUNT               = &H0200
%UF_INTERDOMAIN_TRUST_ACCOUNT    = &H0800
%UF_WORKSTATION_TRUST_ACCOUNT    = &H1000
%UF_SERVER_TRUST_ACCOUNT         = &H2000

%UF_MACHINE_ACCOUNT_MASK = %UF_INTERDOMAIN_TRUST_ACCOUNT OR _
                           %UF_WORKSTATION_TRUST_ACCOUNT OR _
                           %UF_SERVER_TRUST_ACCOUNT

%UF_ACCOUNT_TYPE_MASK = %UF_TEMP_DUPLICATE_ACCOUNT OR _
                        %UF_NORMAL_ACCOUNT OR _
                        %UF_INTERDOMAIN_TRUST_ACCOUNT OR _
                        %UF_WORKSTATION_TRUST_ACCOUNT OR _
                        %UF_SERVER_TRUST_ACCOUNT

%UF_DONT_EXPIRE_PASSWD      = &H10000
%UF_MNS_LOGON_ACCOUNT       = &H20000
%UF_SMARTCARD_REQUIRED      = &H40000
%UF_TRUSTED_FOR_DELEGATION  = &H80000
%UF_NOT_DELEGATED           = &H100000
%UF_USE_DES_KEY_ONLY        = &H200000
%UF_DONT_REQUIRE_PREAUTH    = &H400000
%UF_PASSWORD_EXPIRED        = &H800000
%UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION = &H1000000
%UF_NO_AUTH_DATA_REQUIRED                  = &H2000000
%UF_PARTIAL_SECRETS_ACCOUNT                = &H4000000
%UF_USE_AES_KEYS                           = &H8000000



%UF_SETTABLE_BITS = %UF_SCRIPT OR _
                    %UF_ACCOUNTDISABLE OR _
                    %UF_LOCKOUT OR _
                    %UF_HOMEDIR_REQUIRED OR _
                    %UF_PASSWD_NOTREQD OR _
                    %UF_PASSWD_CANT_CHANGE OR _
                    %UF_ACCOUNT_TYPE_MASK OR _
                    %UF_DONT_EXPIRE_PASSWD OR _
                    %UF_MNS_LOGON_ACCOUNT OR _
                    %UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED OR _
                    %UF_SMARTCARD_REQUIRED OR _
                    %UF_TRUSTED_FOR_DELEGATION OR _
                    %UF_NOT_DELEGATED OR _
                    %UF_USE_DES_KEY_ONLY OR _
                    %UF_DONT_REQUIRE_PREAUTH OR _
                    %UF_PASSWORD_EXPIRED OR _
                    %UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION OR _
                    %UF_NO_AUTH_DATA_REQUIRED OR _
                    %UF_USE_AES_KEYS OR _
                    %UF_PARTIAL_SECRETS_ACCOUNT

'
' bit masks for the NetUserEnum filter parameter.
'

%FILTER_TEMP_DUPLICATE_ACCOUNT    = &H0001
%FILTER_NORMAL_ACCOUNT            = &H0002
' %FILTER_PROXY_ACCOUNT             = &H0004
%FILTER_INTERDOMAIN_TRUST_ACCOUNT = &H0008
%FILTER_WORKSTATION_TRUST_ACCOUNT = &H0010
%FILTER_SERVER_TRUST_ACCOUNT      = &H0020

'
' bit masks for the NetUserGetLocalGroups flags
'
%LG_INCLUDE_INDIRECT = &H0001

'
'  Bit masks for field usri2_auth_flags of USER_INFO_2.
'

%AF_OP_PRINT      = &H1
%AF_OP_COMM       = &H2
%AF_OP_SERVER     = &H4
%AF_OP_ACCOUNTS   = &H8
%AF_SETTABLE_BITS = %AF_OP_PRINT OR %AF_OP_COMM OR _
                    %AF_OP_SERVER OR %AF_OP_ACCOUNTS

'
'  UAS role manifests under NETLOGON
'

%UAS_ROLE_STANDALONE = 0
%UAS_ROLE_MEMBER     = 1
%UAS_ROLE_BACKUP     = 2
%UAS_ROLE_PRIMARY    = 3

'
'  Values for ParmError for NetUserSetInfo.
'

%USER_NAME_PARMNUM           = 1
%USER_PASSWORD_PARMNUM       = 3
%USER_PASSWORD_AGE_PARMNUM   = 4
%USER_PRIV_PARMNUM           = 5
%USER_HOME_DIR_PARMNUM       = 6
%USER_COMMENT_PARMNUM        = 7
%USER_FLAGS_PARMNUM          = 8
%USER_SCRIPT_PATH_PARMNUM    = 9
%USER_AUTH_FLAGS_PARMNUM     = 10
%USER_FULL_NAME_PARMNUM      = 11
%USER_USR_COMMENT_PARMNUM    = 12
%USER_PARMS_PARMNUM          = 13
%USER_WORKSTATIONS_PARMNUM   = 14
%USER_LAST_LOGON_PARMNUM     = 15
%USER_LAST_LOGOFF_PARMNUM    = 16
%USER_ACCT_EXPIRES_PARMNUM   = 17
%USER_MAX_STORAGE_PARMNUM    = 18
%USER_UNITS_PER_WEEK_PARMNUM = 19
%USER_LOGON_HOURS_PARMNUM    = 20
%USER_PAD_PW_COUNT_PARMNUM   = 21
%USER_NUM_LOGONS_PARMNUM     = 22
%USER_LOGON_SERVER_PARMNUM   = 23
%USER_COUNTRY_CODE_PARMNUM   = 24
%USER_CODE_PAGE_PARMNUM      = 25
%USER_PRIMARY_GROUP_PARMNUM  = 51
%USER_PROFILE                = 52 ' ?? Delete when convenient
%USER_PROFILE_PARMNUM        = 52
%USER_HOME_DIR_DRIVE_PARMNUM = 53

'
' the new infolevel counterparts of the old info level + parmnum
'

%USER_NAME_INFOLEVEL            = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_NAME_PARMNUM)
%USER_PASSWORD_INFOLEVEL        = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_PASSWORD_PARMNUM)
%USER_PASSWORD_AGE_INFOLEVEL    = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_PASSWORD_AGE_PARMNUM)
%USER_PRIV_INFOLEVEL            = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_PRIV_PARMNUM)
%USER_HOME_DIR_INFOLEVEL        = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_HOME_DIR_PARMNUM)
%USER_COMMENT_INFOLEVEL         = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_COMMENT_PARMNUM)
%USER_FLAGS_INFOLEVEL           = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_FLAGS_PARMNUM)
%USER_SCRIPT_PATH_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_SCRIPT_PATH_PARMNUM)
%USER_AUTH_FLAGS_INFOLEVEL      = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_AUTH_FLAGS_PARMNUM)
%USER_FULL_NAME_INFOLEVEL       = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_FULL_NAME_PARMNUM)
%USER_USR_COMMENT_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_USR_COMMENT_PARMNUM)
%USER_PARMS_INFOLEVEL           = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_PARMS_PARMNUM)
%USER_WORKSTATIONS_INFOLEVEL    = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_WORKSTATIONS_PARMNUM)
%USER_LAST_LOGON_INFOLEVEL      = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_LAST_LOGON_PARMNUM)
%USER_LAST_LOGOFF_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_LAST_LOGOFF_PARMNUM)
%USER_ACCT_EXPIRES_INFOLEVEL    = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_ACCT_EXPIRES_PARMNUM)
%USER_MAX_STORAGE_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_MAX_STORAGE_PARMNUM)
%USER_UNITS_PER_WEEK_INFOLEVEL  = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_UNITS_PER_WEEK_PARMNUM)
%USER_LOGON_HOURS_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_LOGON_HOURS_PARMNUM)
%USER_PAD_PW_COUNT_INFOLEVEL    = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_PAD_PW_COUNT_PARMNUM)
%USER_NUM_LOGONS_INFOLEVEL      = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_NUM_LOGONS_PARMNUM)
%USER_LOGON_SERVER_INFOLEVEL    = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_LOGON_SERVER_PARMNUM)
%USER_COUNTRY_CODE_INFOLEVEL    = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_COUNTRY_CODE_PARMNUM)
%USER_CODE_PAGE_INFOLEVEL       = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_CODE_PAGE_PARMNUM)
%USER_PRIMARY_GROUP_INFOLEVEL   = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_PRIMARY_GROUP_PARMNUM)
' ** Microsoft never defines %USER_POSIX_ID_PARMNUM ...!
'%USER_POSIX_ID_INFOLEVEL        = _
'            (%PARMNUM_BASE_INFOLEVEL + %USER_POSIX_ID_PARMNUM)
%USER_HOME_DIR_DRIVE_INFOLEVEL  = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_HOME_DIR_DRIVE_PARMNUM)

'
'  For SetInfo call (parmnum 0) when password change not required
'

$NULL_USERSETINFO_PASSWD = "              "

%TIMEQ_FOREVER             = &HFFFFFFFF??? ' ((unsigned long) -1L)
%USER_MAXSTORAGE_UNLIMITED = &HFFFFFFFF??? ' ((unsigned long) -1L)
%USER_NO_LOGOFF            = &HFFFFFFFF??? ' ((unsigned long) -1L)
%UNITS_PER_DAY             = 24
%UNITS_PER_WEEK            = %UNITS_PER_DAY * 7

'
' Privilege levels (USER_INFO_X field usriX_priv (X = 0/1)).
'

%USER_PRIV_MASK   = &H3
%USER_PRIV_GUEST  = 0
%USER_PRIV_USER   = 1
%USER_PRIV_ADMIN  = 2

'
' user modals related defaults
'

%MAX_PASSWD_LEN    = %PWLEN
%DEF_MIN_PWLEN     = 6
%DEF_PWUNIQUENESS  = 5
%DEF_MAX_PWHIST    = 8

%DEF_MAX_PWAGE     = %TIMEQ_FOREVER  ' forever
%DEF_MIN_PWAGE     = 0               ' 0 days
%DEF_FORCE_LOGOFF  = &HFFFFFFFF???   ' never
%DEF_MAX_BADPW     = 0               ' no limit
%ONE_DAY           = 24*3600         ' 1 day

'
' User Logon Validation (codes returned)
'

%VALIDATED_LOGON     = 0
%PASSWORD_EXPIRED    = 2
%NON_VALIDATED_LOGON = 3

%VALID_LOGOFF        = 1

'
' parmnum manifests for user modals
'

%MODALS_MIN_PASSWD_LEN_PARMNUM             = 1
%MODALS_MAX_PASSWD_AGE_PARMNUM             = 2
%MODALS_MIN_PASSWD_AGE_PARMNUM             = 3
%MODALS_FORCE_LOGOFF_PARMNUM               = 4
%MODALS_PASSWD_HIST_LEN_PARMNUM            = 5
%MODALS_ROLE_PARMNUM                       = 6
%MODALS_PRIMARY_PARMNUM                    = 7
%MODALS_DOMAIN_NAME_PARMNUM                = 8
%MODALS_DOMAIN_ID_PARMNUM                  = 9
%MODALS_LOCKOUT_DURATION_PARMNUM           = 10
%MODALS_LOCKOUT_OBSERVATION_WINDOW_PARMNUM = 11
%MODALS_LOCKOUT_THRESHOLD_PARMNUM          = 12

'
' the new infolevel counterparts of the old info level + parmnum
'

%MODALS_MIN_PASSWD_LEN_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %MODALS_MIN_PASSWD_LEN_PARMNUM)
%MODALS_MAX_PASSWD_AGE_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %MODALS_MAX_PASSWD_AGE_PARMNUM)
%MODALS_MIN_PASSWD_AGE_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %MODALS_MIN_PASSWD_AGE_PARMNUM)
%MODALS_FORCE_LOGOFF_INFOLEVEL       = _
            (%PARMNUM_BASE_INFOLEVEL + %MODALS_FORCE_LOGOFF_PARMNUM)
%MODALS_PASSWD_HIST_LEN_INFOLEVEL    = _
            (%PARMNUM_BASE_INFOLEVEL + %MODALS_PASSWD_HIST_LEN_PARMNUM)
%MODALS_ROLE_INFOLEVEL               = _
            (%PARMNUM_BASE_INFOLEVEL + %MODALS_ROLE_PARMNUM)
%MODALS_PRIMARY_INFOLEVEL            = _
            (%PARMNUM_BASE_INFOLEVEL + %MODALS_PRIMARY_PARMNUM)
%MODALS_DOMAIN_NAME_INFOLEVEL        = _
            (%PARMNUM_BASE_INFOLEVEL + %MODALS_DOMAIN_NAME_PARMNUM)
%MODALS_DOMAIN_ID_INFOLEVEL          = _
            (%PARMNUM_BASE_INFOLEVEL + %MODALS_DOMAIN_ID_PARMNUM)

#ENDIF  ' %LMUSER


'
' Group Class
'

#IF NOT %DEF(%LMGROUP)

%LMGROUP = 1

'
' Function Prototypes
'

DECLARE FUNCTION NetGroupAdd LIB "NetAPI32.dll" ALIAS "NetGroupAdd" ( _
    servername  AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    parm_err    AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetGroupAddUser LIB "NetAPI32.dll" ALIAS "NetGroupAddUser" ( _
    servername AS WSTRINGZ, _
    GroupName  AS WSTRINGZ, _
    username   AS WSTRINGZ _
    ) AS DWORD

DECLARE FUNCTION NetGroupEnum LIB "NetAPI32.dll" ALIAS "NetGroupEnum" ( _
    servername       AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    BYVAL bufptr     AS BYTE PTR, _
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resume_handle    AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetGroupGetInfo LIB "NetAPI32.dll" ALIAS "NetGroupGetInfo" ( _
    servername   AS WSTRINGZ, _
    GroupName    AS WSTRINGZ, _
    BYVAL level  AS DWORD, _
    BYVAL bufptr AS BYTE PTR _
    ) AS DWORD

DECLARE FUNCTION NetGroupSetInfo LIB "NetAPI32.dll" ALIAS "NetGroupSetInfo" ( _
    servername  AS WSTRINGZ, _
    GroupName   AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    parm_err    AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetGroupDel LIB "NetAPI32.dll" ALIAS "NetGroupDel" ( _
    servername AS WSTRINGZ, _
    GroupName  AS WSTRINGZ _
    ) AS DWORD

DECLARE FUNCTION NetGroupDelUser LIB "NetAPI32.dll" ALIAS "NetGroupDelUser" ( _
    servername AS WSTRINGZ, _
    GroupName  AS WSTRINGZ, _
    UserName   AS WSTRINGZ _
    ) AS DWORD

DECLARE FUNCTION NetGroupGetUsers LIB "NetAPI32.dll" _
    ALIAS "NetGroupGetUsers" ( _
    servername       AS WSTRINGZ, _
    GroupName        AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    BYVAL bufptr     AS BYTE PTR, _
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resume_handle    AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetGroupSetUsers LIB "NetAPI32.dll" _
    ALIAS "NetGroupSetUsers" ( _
    servername         AS WSTRINGZ, _
    GroupName          AS WSTRINGZ, _
    BYVAL level        AS DWORD, _
    BYVAL buf          AS BYTE PTR, _
    BYVAL totalentries AS DWORD _
    ) AS DWORD

'
'  Data Structures - Group
'

TYPE GROUP_INFO_0
    grpi0_name AS WSTRINGZ PTR
END TYPE

TYPE GROUP_INFO_1
    grpi1_name    AS WSTRINGZ PTR
    grpi1_comment AS WSTRINGZ PTR
END TYPE

TYPE GROUP_INFO_2
    grpi2_name       AS WSTRINGZ PTR
    grpi2_comment    AS WSTRINGZ PTR
    grpi2_group_id   AS DWORD
    grpi2_attributes AS DWORD
END TYPE

TYPE GROUP_INFO_3
    grpi3_name       AS WSTRINGZ PTR
    grpi3_comment    AS WSTRINGZ PTR
    grpi3_group_sid  AS SID PTR
    grpi3_attributes AS DWORD
END TYPE

TYPE GROUP_INFO_1002
     grpi1002_comment AS WSTRINGZ PTR
END TYPE

TYPE GROUP_INFO_1005
     grpi1005_attributes AS DWORD
END TYPE

TYPE GROUP_USERS_INFO_0
     grui0_name AS WSTRINGZ PTR
END TYPE

TYPE GROUP_USERS_INFO_1
     grui1_name       AS WSTRINGZ PTR
     grui1_attributes AS DWORD
END TYPE

'
' Special Values and Constants - Group
'

%GROUPIDMASK = &H00008000  ' MSB set if uid refers to a group

'
' Predefined group for all normal users, administrators and guests
' LOCAL is a special group for pinball local security.
'

$$GROUP_SPECIALGRP_USERS  = "USERS"$$
$$GROUP_SPECIALGRP_ADMINS = "ADMINS"$$
$$GROUP_SPECIALGRP_GUESTS = "GUESTS"$$
$$GROUP_SPECIALGRP_LOCAL  = "LOCAL"$$

'
' parmnum manifests for SetInfo calls (only comment is settable)
'

%GROUP_ALL_PARMNUM         = 0
%GROUP_NAME_PARMNUM        = 1
%GROUP_COMMENT_PARMNUM     = 2
%GROUP_ATTRIBUTES_PARMNUM  = 3

'
' the new infolevel counterparts of the old info level + parmnum
'

%GROUP_ALL_INFOLEVEL             = _
            (%PARMNUM_BASE_INFOLEVEL + %GROUP_ALL_PARMNUM)
%GROUP_NAME_INFOLEVEL            = _
            (%PARMNUM_BASE_INFOLEVEL + %GROUP_NAME_PARMNUM)
%GROUP_COMMENT_INFOLEVEL         = _
            (%PARMNUM_BASE_INFOLEVEL + %GROUP_COMMENT_PARMNUM)
%GROUP_ATTRIBUTES_INFOLEVEL      = _
            (%PARMNUM_BASE_INFOLEVEL + %GROUP_ATTRIBUTES_PARMNUM)
' ** Microsoft never defines %GROUP_POSIX_ID_PARMNUM ...!
'%GROUP_POSIX_ID_INFOLEVEL        = _
'            (%PARMNUM_BASE_INFOLEVEL + %GROUP_POSIX_ID_PARMNUM)

#ENDIF  ' %LMGROUP

'
' LocalGroup Class
'

#IF NOT %DEF(%LMLOCALGROUP)

%LMLOCALGROUP = 1

'
' Function Prototypes
'

DECLARE FUNCTION NetLocalGroupAdd LIB "NetAPI32.dll" _
    ALIAS "NetLocalGroupAdd" ( _
    servername  AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    parm_err    AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetLocalGroupAddMember LIB "NetAPI32.dll" _
    ALIAS "NetLocalGroupAddMember" ( _
    servername AS WSTRINGZ, _
    GroupName  AS WSTRINGZ, _
    membersid  AS SID _
    ) AS DWORD

DECLARE FUNCTION NetLocalGroupEnum LIB "NetAPI32.dll" _
    ALIAS "NetLocalGroupEnum" ( _
    servername       AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    BYVAL bufptr     AS BYTE PTR, _
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resumehandle     AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetLocalGroupGetInfo LIB "NetAPI32.dll" _
    ALIAS "NetLocalGroupGetInfo" ( _
    servername   AS WSTRINGZ, _
    GroupName    AS WSTRINGZ, _
    BYVAL level  AS DWORD, _
    BYVAL bufptr AS BYTE PTR _
    ) AS DWORD

DECLARE FUNCTION NetLocalGroupSetInfo LIB "NetAPI32.dll" _
    ALIAS "NetLocalGroupSetInfo" ( _
    servername  AS WSTRINGZ, _
    GroupName   AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    parm_err    AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetLocalGroupDel LIB "NetAPI32.dll" _
    ALIAS "NetLocalGroupDel" ( _
    servername AS WSTRINGZ, _
    GroupName  AS WSTRINGZ _
    ) AS DWORD

DECLARE FUNCTION NetLocalGroupDelMember LIB "NetAPI32.dll" _
    ALIAS "NetLocalGroupDelMember" ( _
    servername AS WSTRINGZ, _
    GroupName  AS WSTRINGZ, _
    membersid  AS SID _
    ) AS DWORD

DECLARE FUNCTION NetLocalGroupGetMembers LIB "NetAPI32.dll" _
    ALIAS "NetLocalGroupGetMembers" ( _
    servername       AS WSTRINGZ, _
    GroupName        AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    BYVAL bufptr     AS BYTE PTR, _
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resumehandle     AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetLocalGroupSetMembers LIB "NetAPI32.dll" _
    ALIAS "NetLocalGroupSetMembers" ( _
    servername         AS WSTRINGZ, _
    GroupName          AS WSTRINGZ, _
    BYVAL level        AS DWORD, _
    BYVAL buf          AS BYTE PTR, _
    BYVAL totalentries AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetLocalGroupAddMembers LIB "NetAPI32.dll" _
    ALIAS "NetLocalGroupAddMembers" ( _
    servername         AS WSTRINGZ, _
    GroupName          AS WSTRINGZ, _
    BYVAL level        AS DWORD, _
    BYVAL buf          AS BYTE PTR, _
    BYVAL totalentries AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetLocalGroupDelMembers LIB "NetAPI32.dll" _
    ALIAS "NetLocalGroupDelMembers" ( _
    servername         AS WSTRINGZ, _
    GroupName          AS WSTRINGZ, _
    BYVAL level        AS DWORD, _
    BYVAL buf          AS BYTE PTR, _
    BYVAL totalentries AS DWORD _
    ) AS DWORD

'
'  Data Structures - LocalGroup
'

TYPE LOCALGROUP_INFO_0
    lgrpi0_name AS WSTRINGZ PTR
END TYPE

TYPE LOCALGROUP_INFO_1
    lgrpi1_name    AS WSTRINGZ PTR
    lgrpi1_comment AS WSTRINGZ PTR
END TYPE

TYPE LOCALGROUP_INFO_1002
    lgrpi1002_comment AS WSTRINGZ PTR
END TYPE

TYPE LOCALGROUP_MEMBERS_INFO_0
    lgrmi0_sid AS SID PTR
END TYPE

TYPE LOCALGROUP_MEMBERS_INFO_1
    lgrmi1_sid      AS SID PTR
    lgrmi1_sidusage AS SID_NAME_USE_enum
    lgrmi1_name     AS WSTRINGZ PTR
END TYPE

TYPE LOCALGROUP_MEMBERS_INFO_2
    lgrmi2_sid           AS SID PTR
    lgrmi2_sidusage      AS SID_NAME_USE_enum
    lgrmi2_domainandname AS WSTRINGZ PTR
END TYPE

TYPE LOCALGROUP_MEMBERS_INFO_3
    lgrmi3_domainandname AS WSTRINGZ PTR
END TYPE

TYPE LOCALGROUP_USERS_INFO_0
    lgrui0_name AS WSTRINGZ PTR
END TYPE


%LOCALGROUP_NAME_PARMNUM    = 1
%LOCALGROUP_COMMENT_PARMNUM = 2

'
' Display Information APIs
'

DECLARE FUNCTION NetQueryDisplayInformation LIB "NetAPI32.dll" _
    ALIAS "NetQueryDisplayInformation" ( _
    ServerName             AS WSTRINGZ, _
    BYVAL Level            AS DWORD, _
    BYVAL Index            AS DWORD, _
    BYVAL EntriesRequested AS DWORD, _
    BYVAL PreferredMaximumLength AS DWORD, _
    ReturnedEntryCount     AS DWORD, _
    SortedBuffer           AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetGetDisplayInformationIndex LIB "NetAPI32.dll" _
    ALIAS "NetGetDisplayInformationIndex" ( _
    ServerName       AS WSTRINGZ, _
    BYVAL Level      AS DWORD, _
    Prefix           AS WSTRINGZ, _
    Index            AS DWORD _
    ) AS DWORD

'
' QueryDisplayInformation levels

TYPE NET_DISPLAY_USER
    usri1_name       AS WSTRINGZ PTR
    usri1_comment    AS WSTRINGZ PTR
    usri1_flags      AS DWORD
    usri1_full_name  AS WSTRINGZ PTR
    usri1_user_id    AS DWORD
    usri1_next_index AS DWORD
END TYPE

TYPE NET_DISPLAY_MACHINE
    usri2_name       AS WSTRINGZ PTR
    usri2_comment    AS WSTRINGZ PTR
    usri2_flags      AS DWORD
    usri2_user_id    AS DWORD
    usri2_next_index AS DWORD
END TYPE

TYPE NET_DISPLAY_GROUP
    grpi3_name       AS WSTRINGZ PTR
    grpi3_comment    AS WSTRINGZ PTR
    grpi3_group_id   AS DWORD
    grpi3_attributes AS DWORD
    grpi3_next_index AS DWORD
END TYPE

#ENDIF  ' %LMLOCALGROUP


'
' Access Class
'

#IF NOT %DEF(%LMACCESS)

%LMACCESS = 1


'
' Function Prototypes - Access
'

DECLARE FUNCTION NetAccessAdd LIB "NetAPI32.dll" ALIAS "NetAccessAdd" ( _
    servername  AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    parm_err    AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetAccessEnum LIB "NetAPI32.dll" ALIAS "NetAccessEnum" ( _
    servername       AS WSTRINGZ, _
    BasePath         AS WSTRINGZ, _
    BYVAL Recursive  AS DWORD, _
    BYVAL level      AS DWORD, _
    bufptr           AS DWORD, _
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resume_handle    AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetAccessGetInfo LIB "NetAPI32.dll" _
    ALIAS "NetAccessGetInfo" ( _
    servername   AS WSTRINGZ, _
    resource     AS WSTRINGZ, _
    BYVAL level  AS DWORD, _
    BYVAL bufptr AS BYTE PTR _
    ) AS DWORD

DECLARE FUNCTION NetAccessSetInfo LIB "NetAPI32.dll" _
    ALIAS "NetAccessSetInfo" ( _
    servername  AS WSTRINGZ, _
    resource    AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    parm_err    AS DWORD _
    ) AS DWORD

DECLARE FUNCTION NetAccessDel LIB "NetAPI32.dll" ALIAS "NetAccessDel" ( _
    servername AS WSTRINGZ, _
    resource   AS WSTRINGZ _
    ) AS DWORD

DECLARE FUNCTION NetAccessGetUserPerms LIB "NetAPI32.dll" _
    ALIAS "NetAccessGetUserPerms" ( _
    servername AS WSTRINGZ, _
    UGname     AS WSTRINGZ, _
    resource   AS WSTRINGZ, _
    Perms      AS DWORD _
    ) AS DWORD

'
' Data Structures - Access
'

TYPE ACCESS_INFO_0
    acc0_resource_name AS WSTRINGZ PTR
END TYPE

TYPE ACCESS_INFO_1
    acc1_resource_name AS WSTRINGZ PTR
    acc1_attr          AS DWORD
    acc1_count         AS DWORD
END TYPE

TYPE ACCESS_INFO_1002
     acc1002_attr AS DWORD
END TYPE


TYPE ACCESS_LIST
    acl_ugname AS WSTRINGZ PTR
    acl_access AS DWORD
END TYPE

'
' Special Values and Constants - Access
'

'
' Maximum number of permission entries for each resource.
'

%MAXPERMENTRIES = 64

'
'  Bit values for the access permissions.  ACCESS_ALL is a handy
'  way to specify maximum permissions.  These are used in
'  acl_access field of access_list structures.
'

%ACCESS_NONE   = 0
%ACCESS_READ   = &H01
%ACCESS_WRITE  = &H02
%ACCESS_CREATE = &H04
%ACCESS_EXEC   = &H08
%ACCESS_DELETE = &H10
%ACCESS_ATRIB  = &H20
%ACCESS_PERM   = &H40

%ACCESS_ALL    = %ACCESS_READ OR _
                 %ACCESS_WRITE OR _
                 %ACCESS_CREATE OR _
                 %ACCESS_EXEC OR _
                 %ACCESS_DELETE OR _
                 %ACCESS_ATRIB OR _
                 %ACCESS_PERM

%ACCESS_GROUP  = &H00008000

'
' Bit values for the acc1_attr field of the ACCESS_INFO_1 structure.
'

%ACCESS_AUDIT     = &H1

%ACCESS_SUCCESS_OPEN   = &H0010
%ACCESS_SUCCESS_WRITE  = &H0020
%ACCESS_SUCCESS_DELETE = &H0040
%ACCESS_SUCCESS_ACL    = &H0080
%ACCESS_SUCCESS_MASK   = &H00F0

%ACCESS_FAIL_OPEN      = &H0100
%ACCESS_FAIL_WRITE     = &H0200
%ACCESS_FAIL_DELETE    = &H0400
%ACCESS_FAIL_ACL       = &H0800
%ACCESS_FAIL_MASK      = &H0F00

%ACCESS_FAIL_SHIFT     = 4

'
' Parmnum value for NetAccessSetInfo.
'

%ACCESS_RESOURCE_NAME_PARMNUM = 1
%ACCESS_ATTR_PARMNUM          = 2
%ACCESS_COUNT_PARMNUM         = 3
%ACCESS_ACCESS_LIST_PARMNUM   = 4

'
' the new infolevel counterparts of the old info level + parmnum
'

%ACCESS_RESOURCE_NAME_INFOLEVEL  = _
            (%PARMNUM_BASE_INFOLEVEL + %ACCESS_RESOURCE_NAME_PARMNUM)
%ACCESS_ATTR_INFOLEVEL           = _
            (%PARMNUM_BASE_INFOLEVEL + %ACCESS_ATTR_PARMNUM)
%ACCESS_COUNT_INFOLEVEL          = _
            (%PARMNUM_BASE_INFOLEVEL + %ACCESS_COUNT_PARMNUM)
%ACCESS_ACCESS_LIST_INFOLEVEL    = _
            (%PARMNUM_BASE_INFOLEVEL + %ACCESS_ACCESS_LIST_PARMNUM)

'
' ACCESS_LETTERS defines a letter for each bit position in
' the acl_access field of struct access_list.  Note that some
' bits have a corresponding letter of ' ' (space).
'

$ACCESS_LETTERS = "RWCXDAP         "



' ********************************
'
' Password Checking API structures
'
' ********************************


'
' What kind of password checking is to be performed?
'     NetValidateAuthentication : Check if the authentication can be done
'     NetValidatePasswordChange : Check if the password can be changed
'     NetValidatePasswordReset  : Reset the password to the given value
'
MACRO NET_VALIDATE_PASSWORD_TYPE_enum=LONG
ENUM NET_VALIDATE_PASSWORD_TYPE SINGULAR
    NetValidateAuthentication = 1
    NetValidatePasswordChange
    NetValidatePasswordReset
END ENUM

'
'    Structure to keep the password hash
'
TYPE NET_VALIDATE_PASSWORD_HASH
    Length AS DWORD
    Hash   AS BYTE PTR
END TYPE

' To be used with PresentFields member of NET_VALIDATE_PERSISTED_FIELDS
%NET_VALIDATE_PASSWORD_LAST_SET        = &H00000001
%NET_VALIDATE_BAD_PASSWORD_TIME        = &H00000002
%NET_VALIDATE_LOCKOUT_TIME             = &H00000004
%NET_VALIDATE_BAD_PASSWORD_COUNT       = &H00000008
%NET_VALIDATE_PASSWORD_HISTORY_LENGTH  = &H00000010
%NET_VALIDATE_PASSWORD_HISTORY         = &H00000020

#IF NOT %DEF(%WINBASE)
#IF NOT %DEF(%FILETIME)
%FILETIME = 1

TYPE FILETIME_dword
    dwLowDateTime  AS DWORD
    dwHighDateTime AS DWORD
END TYPE

TYPE FILETIME_quad
    qDateTime      AS QUAD
END TYPE

UNION FILETIME
    FILETIME_dword
    FILETIME_quad
END UNION
#ENDIF
#ENDIF

'
'    Structure to keep information about the password and related things.
'        Present Fields: (used only in output args) which fields are changed.
'            See the constants above.
'        PasswordLastSet: When the password is last set.
'        BadPasswordTime: When the password was incorrect for the last time.
'        LockoutTime: When the account is locked out. If the account is not locked out
'            it is 0.
'        BadPasswordCount: How many times the password has given incorrectly in the
'            Observation Window.
'        PasswordHistoryLength: How many passwords are kept in the history
'        PasswordHistory: Password hashes that are in the history
'
TYPE NET_VALIDATE_PERSISTED_FIELDS
    PresentFields         AS DWORD
    PasswordLastSet       AS FILETIME
    BadPasswordTime       AS FILETIME
    LockoutTime           AS FILETIME
    BadPasswordCount      AS DWORD
    PasswordHistoryLength AS DWORD
    PasswordHistory       AS NET_VALIDATE_PASSWORD_HASH PTR
END TYPE

'
'    Output Arg
'        ChangedPersistedFields: Any changes to the password related info
'        ValidationStatus: Shows the result of the request
'
TYPE NET_VALIDATE_OUTPUT_ARG
    ChangedPersistedFields AS NET_VALIDATE_PERSISTED_FIELDS
    ValidationStatus       AS DWORD
END TYPE

'
'    If authentication type of password check is to be made,
'        this kind of input must be used
'
'    InputPersistedFields: Information about the account to be logged into
'    PasswordMatched: Indicates the result of the application's authentication of the supplied password
'
TYPE NET_VALIDATE_AUTHENTICATION_INPUT_ARG
    InputPersistedFields AS NET_VALIDATE_PERSISTED_FIELDS
    PasswordMatched      AS BYTE
END TYPE

'
'    If password change type of check is to be made,
'        this kind of input must be used
'
'    InputPersistedFields: Information about the account to be logged into
'    ClearPassword: The string which password is going to be
'    UserAccountName: Name of the user account
'    HashedPassword: Hash of the string that the password is going to be
'    PasswordMatch: denotes if the old password supplied by user matched or not
'
TYPE NET_VALIDATE_PASSWORD_CHANGE_INPUT_ARG
    InputPersistedFields AS NET_VALIDATE_PERSISTED_FIELDS
    ClearPassword        AS WSTRINGZ PTR
    UserAccountName      AS WSTRINGZ PTR
    HashedPassword       AS NET_VALIDATE_PASSWORD_HASH
    PasswordMatch        AS BYTE
END TYPE

'
'    If password reset type of check is to be made,
'        this kind of input must be used
'
'    InputPersistedFields: Information about the account to be logged into
'    ClearPassword: The string which password is going to be
'    UserAccountName: Name of the user account
'    HashedPassword: Hash of the string that the password is going to be
'    PasswordMustChangeAtNextLogon: Password must change for the user to be logged in
'    ClearLockout: If the account was locked out, this field can be used to clear lockout
'
TYPE NET_VALIDATE_PASSWORD_RESET_INPUT_ARG
    InputPersistedFields          AS NET_VALIDATE_PERSISTED_FIELDS
    ClearPassword                 AS WSTRINGZ PTR
    UserAccountName               AS WSTRINGZ PTR
    HashedPassword                AS NET_VALIDATE_PASSWORD_HASH
    PasswordMustChangeAtNextLogon AS BYTE
    ClearLockout                  AS BYTE
END TYPE

'
'    Password Checking API structures end here
'

DECLARE FUNCTION NetValidatePasswordPolicy LIB "NetAPI32.dll" _
    ALIAS "NetValidatePasswordPolicy" ( _
    ServerName           AS WSTRINGZ, _
    Qualifier            AS ANY, _
    BYVAL ValidationType AS NET_VALIDATE_PASSWORD_TYPE_enum, _
    InputArg             AS ANY, _
    OutputArg            AS ANY _
    ) AS DWORD

DECLARE FUNCTION NetValidatePasswordPolicyFree LIB "NetAPI32.dll" _
    ALIAS "NetValidatePasswordPolicyFree" (OutputArg AS ANY) AS DWORD

#ENDIF ' %LMACCESS


'
' Domain Class
'

#IF NOT %DEF(%LMDOMAIN)

%LMDOMAIN = 1

'
' Function Prototypes - Domain
'

DECLARE FUNCTION NetGetDCName LIB "NetAPI32.dll" ALIAS "NetGetDCName" ( _
    servername   AS WSTRINGZ, _
    domainname   AS WSTRINGZ, _
    BYVAL bufptr AS BYTE PTR _
    ) AS DWORD

DECLARE FUNCTION NetGetAnyDCName LIB "NetAPI32.dll" ALIAS "NetGetAnyDCName" ( _
    servername   AS WSTRINGZ, _
    domainname   AS WSTRINGZ, _
    BYVAL bufptr AS BYTE PTR _
    ) AS DWORD


DECLARE FUNCTION I_NetLogonControl LIB "NetAPI32.dll" _
    ALIAS "I_NetLogonControl" ( _
    servername         AS WSTRINGZ, _
    BYVAL FunctionCode AS DWORD, _
    BYVAL QueryLevel   AS DWORD, _
    BYVAL Buffer       AS BYTE PTR _
    ) AS DWORD

DECLARE FUNCTION I_NetLogonControl2 LIB "NetAPI32.dll" _
    ALIAS "I_NetLogonControl2" ( _
    ServerName         AS WSTRINGZ, _
    BYVAL FunctionCode AS DWORD, _
    BYVAL QueryLevel   AS DWORD, _
    BYVAL pData        AS BYTE PTR, _
    BYVAL Buffer       AS BYTE PTR _
    ) AS DWORD

#IF NOT %DEF(%NTDEF)
%NTDEF = 1
MACRO NTSTATUS=LONG
#ENDIF

DECLARE FUNCTION NetEnumerateTrustedDomains LIB "NetAPI32.dll" _
    ALIAS "NetEnumerateTrustedDomains" ( _
    ServerName  AS WSTRINGZ, _
    DomainNames AS ANY _
    ) AS DWORD



'
' Special Values and Constants - Domain
'

'
' FunctionCode values for I_NetLogonControl.
'
' NOTE : if you change the following NETLOGON_CONTROL_* values,
' change them in net\svcdlls\logonsrv\logon.idl file also.
'

%NETLOGON_CONTROL_QUERY            = 1  ' No-op: just query
%NETLOGON_CONTROL_REPLICATE        = 2  ' Force replicate on BDC
%NETLOGON_CONTROL_SYNCHRONIZE      = 3  ' Force synchronize on BDC
%NETLOGON_CONTROL_PDC_REPLICATE    = 4  ' Force PDC to broadcast change
%NETLOGON_CONTROL_REDISCOVER       = 5  ' Force to re-discover trusted domain DCs
%NETLOGON_CONTROL_TC_QUERY         = 6  ' Query status of specified trusted channel status
%NETLOGON_CONTROL_TRANSPORT_NOTIFY = 7  ' Notify netlogon that a new transport has come online
%NETLOGON_CONTROL_FIND_USER        = 8  ' Find named user in a trusted domain
%NETLOGON_CONTROL_CHANGE_PASSWORD  = 9  ' Change machine password on a secure channel to a trusted domain
%NETLOGON_CONTROL_TC_VERIFY        = 10 ' Verify status of specified trusted channel
%NETLOGON_CONTROL_FORCE_DNS_REG    = 11 ' Force DNS re-registration of all registered records
%NETLOGON_CONTROL_QUERY_DNS_REG    = 12 ' Query the status of DNS updates

' Debug function codes

%NETLOGON_CONTROL_UNLOAD_NETLOGON_DLL = &H0000FFFB
%NETLOGON_CONTROL_BACKUP_CHANGE_LOG   = &H0000FFFC
%NETLOGON_CONTROL_TRUNCATE_LOG        = &H0000FFFD
%NETLOGON_CONTROL_SET_DBFLAG          = &H0000FFFE
%NETLOGON_CONTROL_BREAKPOINT          = &H0000FFFF

'
' Query level 1 for I_NetLogonControl
'

TYPE NETLOGON_INFO_1
    netlog1_flags                 AS DWORD
    netlog1_pdc_connection_status AS DWORD
END TYPE

TYPE NETLOGON_INFO_2
    netlog2_flags AS DWORD
    '
    ' If NETLOGON_VERIFY_STATUS_RETURNED bit is set in
    '  netlog2_flags, the following field will return
    '  the status of trust verification. Otherwise,
    '  the field will return the status of the secure
    '  channel to the primary domain of the machine
    '  (useful for BDCs only).
    '
    netlog2_pdc_connection_status AS DWORD
    netlog2_trusted_dc_name       AS WSTRINGZ PTR
    netlog2_tc_connection_status  AS DWORD
END TYPE

TYPE NETLOGON_INFO_3
    netlog3_flags          AS DWORD
    netlog3_logon_attempts AS DWORD
    netlog3_reserved1      AS DWORD
    netlog3_reserved2      AS DWORD
    netlog3_reserved3      AS DWORD
    netlog3_reserved4      AS DWORD
    netlog3_reserved5      AS DWORD
END TYPE

TYPE NETLOGON_INFO_4
    netlog4_trusted_dc_name     AS WSTRINGZ PTR
    netlog4_trusted_domain_name AS WSTRINGZ PTR
END TYPE

'
' Values of netlog1_flags
'

%NETLOGON_REPLICATION_NEEDED      = &H0001 ' Database is out of date
%NETLOGON_REPLICATION_IN_PROGRESS = &H0002 ' Replication is happening now
%NETLOGON_FULL_SYNC_REPLICATION   = &H0004 ' full sync replication required/progress
%NETLOGON_REDO_NEEDED             = &H0008 ' Redo of previous replication needed
%NETLOGON_HAS_IP                  = &H0010 ' The trusted domain DC has an IP address
%NETLOGON_HAS_TIMESERV            = &H0020 ' The trusted domain DC runs the Windows Time Service
%NETLOGON_DNS_UPDATE_FAILURE      = &H0040 ' There was a failure in the last update for one of the DNS records
%NETLOGON_VERIFY_STATUS_RETURNED  = &H0080 ' Trust verification status returned in netlog2_pdc_connection_status

$SERVICE_ACCOUNT_PASSWORD      = "_SA_{262E99C9-6160-4871-ACEC-4E61736B6F21}"
$SERVICE_ACCOUNT_SECRET_PREFIX = "_SC_{262E99C9-6160-4871-ACEC-4E61736B6F21}_"

$ServiceAccountPasswordGUID = GUID$("{262e99c9-6160-4871-acec-4e61736b6f21}")

' [must load dynamically]
DECLARE FUNCTION NetAddServiceAccount (ServerName AS WSTRINGZ, _
    AccountName AS WSTRINGZ, Reserved AS WSTRINGZ, BYVAL Flags AS DWORD) _
    AS LONG

' Do not create an account by this name
' Only link this account to my computer if it exists
%SERVICE_ACCOUNT_FLAG_LINK_TO_HOST_ONLY  = &H00000001

' Do not delete the service account object from AD
' Simply unlink it from this computer and delete the local secret
%SERVICE_ACCOUNT_FLAG_UNLINK_FROM_HOST_ONLY = &H00000001

' [must load dynamically]
DECLARE FUNCTION NetRemoveServiceAccount (ServerName AS WSTRINGZ, _
    AccountName AS WSTRINGZ, BYVAL Flags AS DWORD) AS LONG

' [must load dynamically]
DECLARE FUNCTION NetEnumerateServiceAccounts (ServerName AS WSTRINGZ, _
    BYVAL Flags AS DWORD, AccountsCount AS DWORD, Accounts AS ANY) AS LONG

' [must load dynamically]
DECLARE FUNCTION NetIsServiceAccount (ServerName AS WSTRINGZ, _
    AccountName AS WSTRINGZ, IsService AS LONG) AS LONG

' [must load dynamically]
DECLARE FUNCTION NetQueryServiceAccount (ServerName AS WSTRINGZ, _
    AccountName AS WSTRINGZ, BYVAL InfoLevel AS DWORD, Buffer AS ANY) AS LONG

'
'  Data Structures - Service
'

MACRO MSA_INFO_LEVEL_enum=LONG
ENUM MSA_INFO_LEVEL SINGULAR
    MsaInfoLevel0
    MsaInfoLevelMax
END ENUM

MACRO MSA_INFO_STATE_enum=LONG
ENUM MSA_INFO_STATE SINGULAR
    MsaInfoNotExist      = 1
    MsaInfoNotService
    MsaInfoCannotInstall
    MsaInfoCanInstall
    MsaInfoInstalled
END ENUM

TYPE MSA_INFO_0
    State AS MSA_INFO_STATE_enum
END TYPE

#ENDIF ' #IF NOT %DEF(%LMDOMAIN)
