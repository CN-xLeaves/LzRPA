'------------------------------------------------------------------------------
'
'  SubAuth.inc -- This defines types and macros for Subauthentication Packages.
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 17 Mar 2011
'
'------------------------------------------------------------------------------
'  From SubAuth.h build 0005 of 14 Jul 2009
'------------------------------------------------------------------------------


#INCLUDE THIS ONCE

%NTSUBAUTH = 1

'#IF NOT %DEF(%NTDEF) AND NOT %DEF(%NTSECAPI)
TYPE UNICODE_STRING
    Length        AS WORD
    MaximumLength AS WORD
    Buffer        AS WSTRINGZ PTR
END TYPE

TYPE ANSI_STRING
    Length        AS WORD
    MaximumLength AS WORD
    Buffer        AS ASCIIZ PTR
END TYPE
'#ENDIF  ' #IF NOT %DEF(%NTDEF) AND NOT %DEF(%NTSECAPI)

#IF NOT %DEF(%NTDEF)
TYPE OLD_LARGE_INTEGER
    LowPart  AS DWORD
    HighPart AS LONG
END TYPE

MACRO NT_SUCCESS(nStatus)=ABS(BITS(LONG, nStatus)>=0)
#ENDIF  ' #IF NOT %DEF(%NTDEF)

#IF NOT %DEF(%NTSAM_SAM_HANDLE)
'typedef PVOID SAM_HANDLE, *PSAM_HANDLE;
MACRO SAM_HANDLE=DWORD
%NTSAM_SAM_HANDLE = 1
#ENDIF

#IF NOT %DEF(%NTSAM_USER_ACCOUNT_FLAGS)

'
' User account control flags...
'

%USER_ACCOUNT_DISABLED                       = &H00000001
%USER_HOME_DIRECTORY_REQUIRED                = &H00000002
%USER_PASSWORD_NOT_REQUIRED                  = &H00000004
%USER_TEMP_DUPLICATE_ACCOUNT                 = &H00000008
%USER_NORMAL_ACCOUNT                         = &H00000010
%USER_MNS_LOGON_ACCOUNT                      = &H00000020
%USER_INTERDOMAIN_TRUST_ACCOUNT              = &H00000040
%USER_WORKSTATION_TRUST_ACCOUNT              = &H00000080
%USER_SERVER_TRUST_ACCOUNT                   = &H00000100
%USER_DONT_EXPIRE_PASSWORD                   = &H00000200
%USER_ACCOUNT_AUTO_LOCKED                    = &H00000400
%USER_ENCRYPTED_TEXT_PASSWORD_ALLOWED        = &H00000800
%USER_SMARTCARD_REQUIRED                     = &H00001000
%USER_TRUSTED_FOR_DELEGATION                 = &H00002000
%USER_NOT_DELEGATED                          = &H00004000
%USER_USE_DES_KEY_ONLY                       = &H00008000
%USER_DONT_REQUIRE_PREAUTH                   = &H00010000
%USER_PASSWORD_EXPIRED                       = &H00020000
%USER_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION = &H00040000
%USER_NO_AUTH_DATA_REQUIRED                  = &H00080000
%USER_PARTIAL_SECRETS_ACCOUNT                = &H00100000
%USER_USE_AES_KEYS                           = &H00200000
'  for generating ntsubauth.h file
'

' begin_ntsubauth
%NEXT_FREE_ACCOUNT_CONTROL_BIT = (%USER_USE_AES_KEYS * 2)

%USER_MACHINE_ACCOUNT_MASK =    _
            (%USER_INTERDOMAIN_TRUST_ACCOUNT OR _
             %USER_WORKSTATION_TRUST_ACCOUNT OR _
             %USER_SERVER_TRUST_ACCOUNT)

%USER_ACCOUNT_TYPE_MASK =       _
            (%USER_TEMP_DUPLICATE_ACCOUNT OR _
             %USER_NORMAL_ACCOUNT OR _
             %USER_MACHINE_ACCOUNT_MASK)

%USER_COMPUTED_ACCOUNT_CONTROL_BITS =  _
            (%USER_ACCOUNT_AUTO_LOCKED OR _
             %USER_PASSWORD_EXPIRED)



'
' Logon times may be expressed in day, hour, or minute granularity.
'
'              Days per week    = 7
'              Hours per week   = 168
'              Minutes per week = 10080
'

%SAM_DAYS_PER_WEEK    = 7
%SAM_HOURS_PER_WEEK   = 24 * %SAM_DAYS_PER_WEEK
%SAM_MINUTES_PER_WEEK = 60 * %SAM_HOURS_PER_WEEK

TYPE LOGON_HOURS

    UnitsPerWeek AS WORD

    '
    ' UnitsPerWeek is the number of equal length time units the week is
    ' divided into.  This value is used to compute the length of the bit
    ' string in logon_hours.  Must be less than or equal to
    ' SAM_UNITS_PER_WEEK (10080) for this release.
    '
    ' LogonHours is a bit map of valid logon times.  Each bit represents
    ' a unique division in a week.  The largest bit map supported is 1260
    ' bytes (10080 bits), which represents minutes per week.  In this case
    ' the first bit (bit 0, byte 0) is Sunday, 00:00:00 - 00-00:59; bit 1,
    ' byte 0 is Sunday, 00:01:00 - 00:01:59, etc.  A %NULL pointer means
    ' %DONT_CHANGE for SamSetInformationUser() calls.
    '

    LogonHours AS BYTE PTR

END TYPE

TYPE SR_SECURITY_DESCRIPTOR
    Length             AS DWORD
    SecurityDescriptor AS BYTE PTR
END TYPE

' Microsoft drops the final "S" on this definition, but the equate is clearly
' intended to match the #IF block, so...
%NTSAM_USER_ACCOUNT_FLAGS = 1
%NTSAM_USER_ACCOUNT_FLAG = 1

#ENDIF  ' #IF NOT %DEF(%NTSAM_USER_ACCOUNT_FLAGS)



#IF NOT %DEF(%NTSAM_USER_ALL_INFO)

TYPE USER_ALL_INFORMATION
    LastLogon            AS QUAD
    LastLogoff           AS QUAD
    PasswordLastSet      AS QUAD
    AccountExpires       AS QUAD
    PasswordCanChange    AS QUAD
    PasswordMustChange   AS QUAD
    UserName             AS UNICODE_STRING
    FullName             AS UNICODE_STRING
    HomeDirectory        AS UNICODE_STRING
    HomeDirectoryDrive   AS UNICODE_STRING
    ScriptPath           AS UNICODE_STRING
    ProfilePath          AS UNICODE_STRING
    AdminComment         AS UNICODE_STRING
    WorkStations         AS UNICODE_STRING
    UserComment          AS UNICODE_STRING
    Parameters           AS UNICODE_STRING
    LmPassword           AS UNICODE_STRING
    NtPassword           AS UNICODE_STRING
    PrivateData          AS UNICODE_STRING
    SecurityDescriptor   AS SR_SECURITY_DESCRIPTOR
    UserId               AS DWORD
    PrimaryGroupId       AS DWORD
    UserAccountControl   AS DWORD
    WhichFields          AS DWORD
    LogonHours           AS LOGON_HOURS
    BadPasswordCount     AS WORD
    LogonCount           AS WORD
    CountryCode          AS WORD
    CodePage             AS WORD
    LmPasswordPresent    AS BYTE
    NtPasswordPresent    AS BYTE
    PasswordExpired      AS BYTE
    PrivateDataSensitive AS BYTE
END TYPE

%NTSAM_USER_ALL_INFO = 1

#ENDIF  ' #IF NOT %DEF(%NTSAM_USER_ALL_INFO)


#IF NOT %DEF(%NTSAM_SAM_USER_PARMS)
%USER_ALL_PARAMETERS  = &H00200000
%NTSAM_SAM_USER_PARMS = 1
#ENDIF

%CLEAR_BLOCK_LENGTH = 8

TYPE CLEAR_BLOCK
    cdata AS STRING * %CLEAR_BLOCK_LENGTH
END TYPE


%CYPHER_BLOCK_LENGTH = 8

TYPE CYPHER_BLOCK
    cdata AS STRING * %CYPHER_BLOCK_LENGTH
END TYPE

TYPE LM_OWF_PASSWORD
    cdata(1) AS CYPHER_BLOCK
END TYPE

MACRO LM_CHALLENGE=CLEAR_BLOCK
MACRO NT_OWF_PASSWORD=LM_OWF_PASSWORD
MACRO NT_CHALLENGE=LM_CHALLENGE

%USER_SESSION_KEY_LENGTH = %CYPHER_BLOCK_LENGTH * 2

TYPE USER_SESSION_KEY
    cdata(1) AS CYPHER_BLOCK
END TYPE


' enumerated type NETLOGON_LOGON_INFO_CLASS
%NetlogonInteractiveInformation           = 1
%NetlogonNetworkInformation               = 2
%NetlogonServiceInformation               = 3
%NetlogonGenericInformation               = 4
%NetlogonInteractiveTransitiveInformation = 5
%NetlogonNetworkTransitiveInformation     = 6
%NetlogonServiceTransitiveInformation     = 7

TYPE NETLOGON_LOGON_IDENTITY_INFO
    LogonDomainName  AS UNICODE_STRING
    ParameterControl AS DWORD
    LogonId          AS QUAD
    UserName         AS UNICODE_STRING
    Workstation      AS UNICODE_STRING
END TYPE

TYPE NETLOGON_INTERACTIVE_INFO
    Identity      AS NETLOGON_LOGON_IDENTITY_INFO
    LmOwfPassword AS LM_OWF_PASSWORD
    NtOwfPassword AS NT_OWF_PASSWORD
END TYPE

TYPE NETLOGON_SERVICE_INFO
    Identity      AS NETLOGON_LOGON_IDENTITY_INFO
    LmOwfPassword AS LM_OWF_PASSWORD
    NtOwfPassword AS NT_OWF_PASSWORD
END TYPE

TYPE NETLOGON_NETWORK_INFO
    Identity            AS NETLOGON_LOGON_IDENTITY_INFO
    LmChallenge         AS LM_CHALLENGE
    NtChallengeResponse AS ANSI_STRING
    LmChallengeResponse AS ANSI_STRING
END TYPE

TYPE NETLOGON_GENERIC_INFO
    Identity    AS NETLOGON_LOGON_IDENTITY_INFO
    PackageName AS UNICODE_STRING
    DataLength  AS DWORD
    LogonData   AS BYTE PTR
END TYPE


' Values for Flags
%MSV1_0_PASSTHRU    = &H01
%MSV1_0_GUEST_LOGON = &H02

DECLARE FUNCTION Msv1_0SubAuthenticationRoutine _
   ALIAS "Msv1_0SubAuthenticationRoutine" _
   ( _
    BYVAL LogonLevel AS LONG, _
    LogonInformation AS NETLOGON_LOGON_IDENTITY_INFO, _
    BYVAL Flags      AS DWORD, _
    UserAll          AS USER_ALL_INFORMATION, _
    WhichFields      AS DWORD, _
    UserFlags        AS DWORD, _
    Authoritative    AS BYTE, _
    LogoffTime       AS QUAD, _
    KickoffTime      AS QUAD _
   ) AS LONG

TYPE MSV1_0_VALIDATION_INFO
    LogoffTime      AS QUAD
    KickoffTime     AS QUAD
    LogonServer     AS UNICODE_STRING
    LogonDomainName AS UNICODE_STRING
    SessionKey      AS USER_SESSION_KEY
    Authoritative   AS BYTE
    UserFlags       AS DWORD
    WhichFields     AS DWORD
    UserId          AS DWORD
END TYPE

' values for WhichFields
%MSV1_0_VALIDATION_LOGOFF_TIME  = &H00000001
%MSV1_0_VALIDATION_KICKOFF_TIME = &H00000002
%MSV1_0_VALIDATION_LOGON_SERVER = &H00000004
%MSV1_0_VALIDATION_LOGON_DOMAIN = &H00000008
%MSV1_0_VALIDATION_SESSION_KEY  = &H00000010
%MSV1_0_VALIDATION_USER_FLAGS   = &H00000020
%MSV1_0_VALIDATION_USER_ID      = &H00000040

' legal values for ActionsPerformed
%MSV1_0_SUBAUTH_ACCOUNT_DISABLED = &H00000001
%MSV1_0_SUBAUTH_PASSWORD         = &H00000002
%MSV1_0_SUBAUTH_WORKSTATIONS     = &H00000004
%MSV1_0_SUBAUTH_LOGON_HOURS      = &H00000008
%MSV1_0_SUBAUTH_ACCOUNT_EXPIRY   = &H00000010
%MSV1_0_SUBAUTH_PASSWORD_EXPIRY  = &H00000020
%MSV1_0_SUBAUTH_ACCOUNT_TYPE     = &H00000040
%MSV1_0_SUBAUTH_LOCKOUT          = &H00000080

DECLARE FUNCTION Msv1_0SubAuthenticationRoutineEx _
   ALIAS "Msv1_0SubAuthenticationRoutineEx" _
   ( _
    BYVAL LogonLevel AS LONG, _
    LogonInformation AS ANY, _
    BYVAL Flags      AS DWORD, _
    UserAll          AS USER_ALL_INFORMATION, _
    UserHandle       AS ANY, _
    ValidationInfo   AS MSV1_0_VALIDATION_INFO, _
    ActionsPerformed AS DWORD _
   ) AS LONG

DECLARE FUNCTION Msv1_0SubAuthenticationRoutineGeneric _
   ALIAS "Msv1_0SubAuthenticationRoutineGeneric" _
   ( _
    BYVAL SubmitBuffer       AS DWORD, _
    BYVAL SubmitBufferLength AS DWORD, _
    ReturnBufferLength       AS DWORD, _
    ReturnBuffer             AS DWORD _
   ) AS LONG

DECLARE FUNCTION Msv1_0SubAuthenticationFilter _
   ALIAS "Msv1_0SubAuthenticationFilter" _
   ( _
    BYVAL LogonLevel       AS LONG, _
    BYVAL LogonInformation AS DWORD, _
    BYVAL Flags            AS DWORD, _
    UserAll                AS USER_ALL_INFORMATION, _
    WhichFields            AS DWORD, _
    UserFlags              AS DWORD, _
    Authoritative          AS BYTE, _
    LogoffTime             AS QUAD, _
    KickoffTime            AS QUAD _
   ) AS LONG

%STATUS_SUCCESS                = &H00000000
%STATUS_INVALID_INFO_CLASS     = &HC0000003
%STATUS_NO_SUCH_USER           = &HC0000064
%STATUS_WRONG_PASSWORD         = &HC000006A
%STATUS_PASSWORD_RESTRICTION   = &HC000006C
%STATUS_LOGON_FAILURE          = &HC000006D
%STATUS_ACCOUNT_RESTRICTION    = &HC000006E
%STATUS_INVALID_LOGON_HOURS    = &HC000006F
%STATUS_INVALID_WORKSTATION    = &HC0000070
%STATUS_PASSWORD_EXPIRED       = &HC0000071
%STATUS_ACCOUNT_DISABLED       = &HC0000072
%STATUS_INSUFFICIENT_RESOURCES = &HC000009A
%STATUS_ACCOUNT_EXPIRED        = &HC0000193
%STATUS_PASSWORD_MUST_CHANGE   = &HC0000224
%STATUS_ACCOUNT_LOCKED_OUT     = &HC0000234
