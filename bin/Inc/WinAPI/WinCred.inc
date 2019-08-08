'------------------------------------------------------------------------------
'
'  WinCred.inc -- API definitions needed for the Credential Manager.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 21 Feb 2011
'
'------------------------------------------------------------------------------
'  from WinCred.h build version 0001 of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WINCRED_H = 1

#INCLUDE "WinError.inc"
#INCLUDE "NtStatus.inc"
#INCLUDE "WinDef.inc"


'
' Ensure PCtxtHandle is defined
'

#IF NOT %DEF(%SECHANDLE_DEFINED)
TYPE SecHandle
    dwLower AS DWORD  ' ULONG_PTR
    dwUpper AS DWORD  ' ULONG_PTR
END TYPE

%SECHANDLE_DEFINED = 1
#ENDIF

'typedef PSecHandle PCtxtHandle;
TYPE txtHandle
    SecHandle
END TYPE



'
' Ensure FILETIME is defined
'

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
#ENDIF ' %WINBASE

'
' Ensure NTSTATUS is defined
'
'#IF NOT %DEF(%NTDEF)
'MACRO NTSTATUS=LONG
'#ENDIF


'-----------------------------------------------------------------------------
' Macros
'-----------------------------------------------------------------------------

'
' Macro to determine whether CredUIPromptForCredentials should be called upon a failed
'      authentication attempt.
'
' Implemented as a macro so that the caller can delay load credui.dll only if this
'      macro returns TRUE.
'
' Include only status codes that imply the username/password are wrong or that the
'      password is expired.  In the former case, asking for a another username or password
'      is appropriate.  In the later case, we put up a different dialog asking the
'      user to change the password on the server.
'
' Don't include status codes such as ERROR_ACCOUNT_DISABLED, ERROR_ACCOUNT_RESTRICTION,
'      ERROR_ACCOUNT_LOCKED_OUT, ERROR_ACCOUNT_EXPIRED, ERROR_LOGON_TYPE_NOT_GRANTED.
'      For those, the user isn't going to have another account so prompting him
'      won't help.
'
' STATUS_DOWNGRADE_DETECTED is included to handle the case where a corporate laptop
'      is brought to another LAN.  A downgrade attack will indeed be detected,
'      but we want to popup UI to allow the user to connect to resources in the
'      other LAN.
'
' Don't use the CREDUIP_* macros directly.  Their definition is private to credui.dll.
'

' Don't require ntstatus.h
%STATUS_LOGON_FAILURE             = &HC000006D     ' ntsubauth
%STATUS_WRONG_PASSWORD            = &HC000006A     ' ntsubauth
%STATUS_PASSWORD_EXPIRED          = &HC0000071     ' ntsubauth
%STATUS_PASSWORD_MUST_CHANGE      = &HC0000224    ' ntsubauth
%STATUS_ACCESS_DENIED             = &HC0000022
%STATUS_DOWNGRADE_DETECTED        = &HC0000388
%STATUS_AUTHENTICATION_FIREWALL_FAILED = &HC0000413
%STATUS_ACCOUNT_DISABLED          = &HC0000072     ' ntsubauth
%STATUS_ACCOUNT_RESTRICTION       = &HC000006E     ' ntsubauth
%STATUS_ACCOUNT_LOCKED_OUT        = &HC0000234    ' ntsubauth
%STATUS_ACCOUNT_EXPIRED           = &HC0000193    ' ntsubauth
%STATUS_LOGON_TYPE_NOT_GRANTED    = &HC000015B

' Don't require lmerr.h
%NERR_BASE     = 2100
%NERR_PasswordExpired = (%NERR_BASE+142) ' The password of this user has expired.

FUNCTION CREDUIP_IS_USER_PASSWORD_ERROR (BYVAL s AS DWORD) AS LONG

    FUNCTION = -( _
        BITSE(s, %ERROR_LOGON_FAILURE, 32) OR _
        BITSE(s, %STATUS_LOGON_FAILURE, 32) OR _
        BITSE(s, %ERROR_ACCESS_DENIED, 32) OR _
        BITSE(s, %STATUS_ACCESS_DENIED, 32) OR _
        BITSE(s, %ERROR_INVALID_PASSWORD, 32) OR _
        BITSE(s, %STATUS_WRONG_PASSWORD, 32) OR _
        BITSE(s, %SEC_E_NO_CREDENTIALS, 32) OR _
        BITSE(s, %SEC_E_LOGON_DENIED, 32) OR _
        BITSE(s, %SEC_E_NO_CONTEXT, 32) OR _
        BITSE(s, %STATUS_NO_SECURITY_CONTEXT, 32))

END FUNCTION

FUNCTION CREDUIP_IS_DOWNGRADE_ERROR (BYVAL s  AS DWORD) AS LONG

    FUNCTION = -( _
        BITSE(s, %ERROR_DOWNGRADE_DETECTED, 32) OR _
        BITSE(s, %STATUS_DOWNGRADE_DETECTED, 32))

END FUNCTION

FUNCTION CREDUIP_IS_EXPIRED_ERROR (BYVAL s AS DWORD) AS LONG

    FUNCTION = -( _
        BITSE(s, %ERROR_PASSWORD_EXPIRED, 32) OR _
        BITSE(s, %STATUS_PASSWORD_EXPIRED, 32) OR _
        BITSE(s, %ERROR_PASSWORD_MUST_CHANGE, 32) OR _
        BITSE(s, %STATUS_PASSWORD_MUST_CHANGE, 32) OR _
        BITSE(s, %NERR_PasswordExpired, 32))

END FUNCTION

FUNCTION CREDUI_IS_AUTHENTICATION_ERROR (BYVAL s AS DWORD) AS LONG

    FUNCTION = ( _
        CREDUIP_IS_USER_PASSWORD_ERROR(s) OR _
        CREDUIP_IS_DOWNGRADE_ERROR(s) OR _
        CREDUIP_IS_EXPIRED_ERROR(s))

END FUNCTION

FUNCTION CREDUI_NO_PROMPT_AUTHENTICATION_ERROR (BYVAL s AS DWORD) AS LONG

    FUNCTION = ( _
        BITSE(s, %ERROR_AUTHENTICATION_FIREWALL_FAILED, 32) OR _
        BITSE(s, %STATUS_AUTHENTICATION_FIREWALL_FAILED, 32) OR _
        BITSE(s, %ERROR_ACCOUNT_DISABLED, 32) OR _
        BITSE(s, %STATUS_ACCOUNT_DISABLED, 32) OR _
        BITSE(s, %ERROR_ACCOUNT_RESTRICTION, 32) OR _
        BITSE(s, %STATUS_ACCOUNT_RESTRICTION, 32) OR _
        BITSE(s, %ERROR_ACCOUNT_LOCKED_OUT, 32) OR _
        BITSE(s, %STATUS_ACCOUNT_LOCKED_OUT, 32) OR _
        BITSE(s, %ERROR_ACCOUNT_EXPIRED, 32) OR _
        BITSE(s, %STATUS_ACCOUNT_EXPIRED, 32) OR _
        BITSE(s, %ERROR_LOGON_TYPE_NOT_GRANTED, 32) OR _
        BITSE(s, %STATUS_LOGON_TYPE_NOT_GRANTED, 32))

END FUNCTION

'-----------------------------------------------------------------------------
' Structures
'-----------------------------------------------------------------------------

'
' Credential Attribute
'

' Maximum length of the various credential string fields (in characters)
%CRED_MAX_STRING_LENGTH = 256

' Maximum length of the UserName field.  The worst case is <User>@<DnsDomain>
%CRED_MAX_USERNAME_LENGTH = (256+1+256)

' Maximum length of the TargetName field for CRED_TYPE_GENERIC (in characters)
%CRED_MAX_GENERIC_TARGET_NAME_LENGTH = 32767

' Maximum length of the TargetName field for CRED_TYPE_DOMAIN_* (in characters)
'      Largest one is <DfsRoot>\<DfsShare>
%CRED_MAX_DOMAIN_TARGET_NAME_LENGTH = (256+1+80)

' Maximum length of a target namespace
%CRED_MAX_TARGETNAME_NAMESPACE_LENGTH = (256)

' Maximum length of a target attribute
%CRED_MAX_TARGETNAME_ATTRIBUTE_LENGTH = (256)

' Maximum size of the Credential Attribute Value field (in bytes)
%CRED_MAX_VALUE_SIZE = (256)

' Maximum number of attributes per credential
%CRED_MAX_ATTRIBUTES = 64

TYPE CREDENTIAL_ATTRIBUTEA
    Keyword   AS ASCIIZ PTR
    Flags     AS DWORD
    ValueSize AS DWORD
    Value     AS BYTE PTR
END TYPE

TYPE CREDENTIAL_ATTRIBUTEW
    Keyword   AS WSTRINGZ PTR
    Flags     AS DWORD
    ValueSize AS DWORD
    Value     AS BYTE PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE CREDENTIAL_ATTRIBUTE
    CREDENTIAL_ATTRIBUTEW
END TYPE
#ELSE
TYPE CREDENTIAL_ATTRIBUTE
    CREDENTIAL_ATTRIBUTEA
END TYPE
#ENDIF ' UNICODE

'
' Special values of the TargetName field
'
$$CRED_SESSION_WILDCARD_NAME_W = "*Session"$$
$CRED_SESSION_WILDCARD_NAME_A = "*Session"

$$CRED_UNIVERSAL_WILDCARD_W = "*"$$
$CRED_UNIVERSAL_WILDCARD_A = "*"

%CRED_SESSION_WILDCARD_NAME_LENGTH=7 ' (LEN($CRED_SESSION_WILDCARD_NAME_A)-1)

$$CRED_TARGETNAME_DOMAIN_NAMESPACE_W = "Domain"$$
$CRED_TARGETNAME_DOMAIN_NAMESPACE_A = "Domain"

%CRED_TARGETNAME_DOMAIN_NAMESPACE_LENGTH=5 ' (LEN($CRED_TARGETNAME_DOMAIN_NAMESPACE_A)-1)

$$CRED_UNIVERSAL_WILDCARD_W = "*"$$
$CRED_UNIVERSAL_WILDCARD_A = "*"

$$CRED_TARGETNAME_LEGACYGENERIC_NAMESPACE_W = "LegacyGeneric"$$
$CRED_TARGETNAME_LEGACYGENERIC_NAMESPACE_A = "LegacyGeneric"

%CRED_TARGETNAME_LEGACYGENERIC_NAMESPACE_LENGTH=12 ' (LEN($CRED_TARGETNAME_LEGACYGENERIC_NAMESPACE_A)-1)

$$CRED_TARGETNAME_NAMESPACE_SEPERATOR_W = ":"$$
$CRED_TARGETNAME_NAMESPACE_SEPERATOR_A = ":"

$$CRED_TARGETNAME_ATTRIBUTE_SEPERATOR_W = "="$$
$CRED_TARGETNAME_ATTRIBUTE_SEPERATOR_A = "="

$$CRED_TARGETNAME_DOMAIN_EXTENDED_USERNAME_SEPARATOR_W = "|"$$
$CRED_TARGETNAME_DOMAIN_EXTENDED_USERNAME_SEPARATOR_A = "|"

$$CRED_TARGETNAME_ATTRIBUTE_TARGET_W = "target"$$
$CRED_TARGETNAME_ATTRIBUTE_TARGET_A = "target"

%CRED_TARGETNAME_ATTRIBUTE_TARGET_LENGTH=5 ' (LEN($CRED_TARGETNAME_ATTRIBUTE_TARGET_A)-1)

$$CRED_TARGETNAME_ATTRIBUTE_NAME_W = "name"$$
$CRED_TARGETNAME_ATTRIBUTE_NAME_A = "name"

%CRED_TARGETNAME_ATTRIBUTE_NAME_LENGTH=3 ' (LEN($CRED_TARGETNAME_ATTRIBUTE_NAME_A)-1)
$$CRED_TARGETNAME_ATTRIBUTE_BATCH_W = "batch"$$
$CRED_TARGETNAME_ATTRIBUTE_BATCH_A = "batch"

%CRED_TARGETNAME_ATTRIBUTE_BATCH_LENGTH=4 ' (LEN($CRED_TARGETNAME_ATTRIBUTE_BATCH_A)-1)

$$CRED_TARGETNAME_ATTRIBUTE_INTERACTIVE_W = "interactive"$$
$CRED_TARGETNAME_ATTRIBUTE_INTERACTIVE_A = "interactive"

%CRED_TARGETNAME_ATTRIBUTE_INTERACTIVE_LENGTH=10 ' (LEN($CRED_TARGETNAME_ATTRIBUTE_INTERACTIVE_A)-1)

$$CRED_TARGETNAME_ATTRIBUTE_SERVICE_W = "service"$$
$CRED_TARGETNAME_ATTRIBUTE_SERVICE_A = "service"

%CRED_TARGETNAME_ATTRIBUTE_SERVICE_LENGTH=6 ' (LEN($CRED_TARGETNAME_ATTRIBUTE_SERVICE_A)-1)

$$CRED_TARGETNAME_ATTRIBUTE_NETWORK_W = "network"$$
$CRED_TARGETNAME_ATTRIBUTE_NETWORK_A = "network"

%CRED_TARGETNAME_ATTRIBUTE_NETWORK_LENGTH=6 ' (LEN($CRED_TARGETNAME_ATTRIBUTE_NETWORK_A)-1)

$$CRED_TARGETNAME_ATTRIBUTE_NETWORKCLEARTEXT_W = "networkcleartext"$$
$CRED_TARGETNAME_ATTRIBUTE_NETWORKCLEARTEXT_A = "networkcleartext"

%CRED_TARGETNAME_ATTRIBUTE_NETWORKCLEARTEXT_LENGTH=15 ' (LEN($CRED_TARGETNAME_ATTRIBUTE_NETWORKCLEARTEXT_A)-1)

$$CRED_TARGETNAME_ATTRIBUTE_REMOTEINTERACTIVE_W = "remoteinteractive"$$
$CRED_TARGETNAME_ATTRIBUTE_REMOTEINTERACTIVE_A = "remoteinteractive"

%CRED_TARGETNAME_ATTRIBUTE_REMOTEINTERACTIVE_LENGTH=16 ' (LEN($CRED_TARGETNAME_ATTRIBUTE_REMOTEINTERACTIVE_A)-1)

$$CRED_TARGETNAME_ATTRIBUTE_CACHEDINTERACTIVE_W = "cachedinteractive"$$
$CRED_TARGETNAME_ATTRIBUTE_CACHEDINTERACTIVE_A = "cachedinteractive"

%CRED_TARGETNAME_ATTRIBUTE_CACHEDINTERACTIVE_LENGTH=16 ' (LEN($CRED_TARGETNAME_ATTRIBUTE_CACHEDINTERACTIVE_A)-1)

#IF %DEF(%UNICODE)
MACRO CRED_SESSION_WILDCARD_NAME = $$CRED_SESSION_WILDCARD_NAME_W
MACRO CRED_TARGETNAME_DOMAIN_NAMESPACE = $$CRED_TARGETNAME_DOMAIN_NAMESPACE_W
MACRO CRED_UNIVERSAL_WILDCARD = $$CRED_UNIVERSAL_WILDCARD_W
MACRO CRED_TARGETNAME_NAMESPACE_SEPERATOR = $$CRED_TARGETNAME_NAMESPACE_SEPERATOR_W
MACRO CRED_TARGETNAME_ATTRIBUTE_SEPERATOR = $$CRED_TARGETNAME_ATTRIBUTE_SEPERATOR_W
MACRO CRED_TARGETNAME_ATTRIBUTE_NAME = $$CRED_TARGETNAME_ATTRIBUTE_NAME_W
MACRO CRED_TARGETNAME_ATTRIBUTE_TARGET = $$CRED_TARGETNAME_ATTRIBUTE_TARGET_W
MACRO CRED_TARGETNAME_ATTRIBUTE_BATCH = $$CRED_TARGETNAME_ATTRIBUTE_BATCH_W
MACRO CRED_TARGETNAME_ATTRIBUTE_INTERACTIVE = $$CRED_TARGETNAME_ATTRIBUTE_INTERACTIVE_W
MACRO CRED_TARGETNAME_ATTRIBUTE_SERVICE = $$CRED_TARGETNAME_ATTRIBUTE_SERVICE_W
MACRO CRED_TARGETNAME_ATTRIBUTE_NETWORK = $$CRED_TARGETNAME_ATTRIBUTE_NETWORK_W
MACRO CRED_TARGETNAME_ATTRIBUTE_NETWORKCLEARTEXT = $$CRED_TARGETNAME_ATTRIBUTE_NETWORKCLEARTEXT_W
MACRO CRED_TARGETNAME_ATTRIBUTE_REMOTEINTERACTIVE = $$CRED_TARGETNAME_ATTRIBUTE_REMOTEINTERACTIVE_W
MACRO CRED_TARGETNAME_ATTRIBUTE_CACHEDINTERACTIVE = $$CRED_TARGETNAME_ATTRIBUTE_CACHEDINTERACTIVE_W

#ELSE
MACRO CRED_SESSION_WILDCARD_NAME = $CRED_SESSION_WILDCARD_NAME_A
MACRO CRED_TARGETNAME_DOMAIN_NAMESPACE = $CRED_TARGETNAME_DOMAIN_NAMESPACE_A
MACRO CRED_UNIVERSAL_WILDCARD = $CRED_UNIVERSAL_WILDCARD_A
MACRO CRED_TARGETNAME_NAMESPACE_SEPERATOR = $CRED_TARGETNAME_NAMESPACE_SEPERATOR_A
MACRO CRED_TARGETNAME_ATTRIBUTE_SEPERATOR = $CRED_TARGETNAME_ATTRIBUTE_SEPERATOR_A
MACRO CRED_TARGETNAME_ATTRIBUTE_NAME = $CRED_TARGETNAME_ATTRIBUTE_NAME_A
MACRO CRED_TARGETNAME_ATTRIBUTE_TARGET = $CRED_TARGETNAME_ATTRIBUTE_TARGET_A
MACRO CRED_TARGETNAME_ATTRIBUTE_BATCH = $CRED_TARGETNAME_ATTRIBUTE_BATCH_A
MACRO CRED_TARGETNAME_ATTRIBUTE_INTERACTIVE = $CRED_TARGETNAME_ATTRIBUTE_INTERACTIVE_A
MACRO CRED_TARGETNAME_ATTRIBUTE_SERVICE = $CRED_TARGETNAME_ATTRIBUTE_SERVICE_A
MACRO CRED_TARGETNAME_ATTRIBUTE_NETWORK = $CRED_TARGETNAME_ATTRIBUTE_NETWORK_A
MACRO CRED_TARGETNAME_ATTRIBUTE_NETWORKCLEARTEXT = $CRED_TARGETNAME_ATTRIBUTE_NETWORKCLEARTEXT_A
MACRO CRED_TARGETNAME_ATTRIBUTE_REMOTEINTERACTIVE = $CRED_TARGETNAME_ATTRIBUTE_REMOTEINTERACTIVE_A
MACRO CRED_TARGETNAME_ATTRIBUTE_CACHEDINTERACTIVE = $CRED_TARGETNAME_ATTRIBUTE_CACHEDINTERACTIVE_A
#ENDIF ' UNICODE


'
' Add\Extract Logon type from flags
'
%CRED_LOGON_TYPES_MASK           = &HF000??  ' Mask to get logon types

MACRO CredAppendLogonTypeToFlags(Flags, LogonType)
    Flags OR= (LogonType) *65536*256
END MACRO

MACRO CredGetLogonTypeFromFlags(Flags)=(((Flags) AND %CRED_LOGON_TYPES_MASK)/(65536*256))
MACRO CredRemoveLogonTypeFromFlags(Flags)
    Flags AND= NOT %CRED_LOGON_TYPES_MASK
END MACRO

'
' Values of the Credential Flags field.
'
%CRED_FLAGS_PASSWORD_FOR_CERT    = &H0001
%CRED_FLAGS_PROMPT_NOW           = &H0002
%CRED_FLAGS_USERNAME_TARGET      = &H0004
%CRED_FLAGS_OWF_CRED_BLOB        = &H0008
%CRED_FLAGS_REQUIRE_CONFIRMATION = &H0010

'
'  Valid only for return and only with CredReadDomainCredentials().
'  Indicates credential was returned due to wildcard match
'  of targetname with credential.
'

%CRED_FLAGS_WILDCARD_MATCH       = &H0020
%CRED_FLAGS_VALID_FLAGS          = &HF03F??  ' Mask of all valid flags

'
'  Bit mask for only those flags which can be passed to the credman
'  APIs.
'

%CRED_FLAGS_VALID_INPUT_FLAGS    = &HF01F??

'
' Values of the Credential Type field.
'
%CRED_TYPE_GENERIC                 = 1
%CRED_TYPE_DOMAIN_PASSWORD         = 2
%CRED_TYPE_DOMAIN_CERTIFICATE      = 3
%CRED_TYPE_DOMAIN_VISIBLE_PASSWORD = 4
%CRED_TYPE_GENERIC_CERTIFICATE     = 5
%CRED_TYPE_DOMAIN_EXTENDED         = 6
%CRED_TYPE_MAXIMUM                 = 7           ' Maximum supported cred type
%CRED_TYPE_MAXIMUM_EX = %CRED_TYPE_MAXIMUM+1000  ' Allow new applications to run on old OSes

'
' Maximum size of the CredBlob field (in bytes)
'

%CRED_MAX_CREDENTIAL_BLOB_SIZE = (5*512)

'
' Values of the Credential Persist field
'
%CRED_PERSIST_NONE             = 0
%CRED_PERSIST_SESSION          = 1
%CRED_PERSIST_LOCAL_MACHINE    = 2
%CRED_PERSIST_ENTERPRISE       = 3



'
' A credential
'
TYPE CREDENTIALA
    Flags              AS DWORD
    TYPE               AS DWORD
    TargetName         AS ASCIIZ PTR
    Comment            AS ASCIIZ PTR
    LastWritten        AS FILETIME
    CredentialBlobSize AS DWORD
    CredentialBlob     AS BYTE PTR
    Persist            AS DWORD
    AttributeCount     AS DWORD
    Attributes         AS CREDENTIAL_ATTRIBUTEA PTR
    TargetAlias        AS ASCIIZ PTR
    UserName           AS ASCIIZ PTR
END TYPE

TYPE CREDENTIALW
    Flags              AS DWORD
    TYPE               AS DWORD
    TargetName         AS WSTRINGZ PTR
    Comment            AS WSTRINGZ PTR
    LastWritten        AS FILETIME
    CredentialBlobSize AS DWORD
    CredentialBlob     AS BYTE PTR
    Persist            AS DWORD
    AttributeCount     AS DWORD
    Attributes         AS CREDENTIAL_ATTRIBUTEW PTR
    TargetAlias        AS WSTRINGZ PTR
    UserName           AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE CREDENTIAL
    CREDENTIALW
END TYPE
#ELSE
TYPE CREDENTIAL
    CREDENTIALA
END TYPE
#ENDIF ' UNICODE

'
' Value of the Flags field in CREDENTIAL_TARGET_INFORMATION
'

%CRED_TI_SERVER_FORMAT_UNKNOWN  = &H0001  ' Don't know if server name is DNS or netbios format
%CRED_TI_DOMAIN_FORMAT_UNKNOWN  = &H0002  ' Don't know if domain name is DNS or netbios format
%CRED_TI_ONLY_PASSWORD_REQUIRED = &H0004  ' Server only requires a password and not a username
%CRED_TI_USERNAME_TARGET        = &H0008  ' TargetName is username
%CRED_TI_CREATE_EXPLICIT_CRED   = &H0010  ' When creating a cred, create one named TargetInfo->TargetName
%CRED_TI_WORKGROUP_MEMBER       = &H0020  ' Indicates the machine is a member of a workgroup
%CRED_TI_VALID_FLAGS            = &HF07F??


'
' A credential target
'

TYPE CREDENTIAL_TARGET_INFORMATIONA
    TargetName        AS ASCIIZ PTR
    NetbiosServerName AS ASCIIZ PTR
    DnsServerName     AS ASCIIZ PTR
    NetbiosDomainName AS ASCIIZ PTR
    DnsDomainName     AS ASCIIZ PTR
    DnsTreeName       AS ASCIIZ PTR
    PackageName       AS ASCIIZ PTR
    Flags             AS DWORD
    CredTypeCount     AS DWORD
    CredTypes         AS DWORD PTR
END TYPE

TYPE CREDENTIAL_TARGET_INFORMATIONW
    TargetName        AS WSTRINGZ PTR
    NetbiosServerName AS WSTRINGZ PTR
    DnsServerName     AS WSTRINGZ PTR
    NetbiosDomainName AS WSTRINGZ PTR
    DnsDomainName     AS WSTRINGZ PTR
    DnsTreeName       AS WSTRINGZ PTR
    PackageName       AS WSTRINGZ PTR
    Flags             AS DWORD
    CredTypeCount     AS DWORD
    CredTypes         AS DWORD PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE CREDENTIAL_TARGET_INFORMATION
    CREDENTIAL_TARGET_INFORMATIONW
END TYPE
#ELSE
TYPE CREDENTIAL_TARGET_INFORMATION
    CREDENTIAL_TARGET_INFORMATIONA
END TYPE
#ENDIF ' UNICODE

'
' Certificate credential information
'
' The cbSize should be the size of the structure, sizeof(CERT_CREDENTIAL_INFO),
' rgbHashofCert is the hash of the cert which is to be used as the credential.
'

%CERT_HASH_LENGTH      = 20  ' SHA1 hashes are used for cert hashes

TYPE CERT_CREDENTIAL_INFO
    cbSize AS DWORD
    rgbHashOfCert(%CERT_HASH_LENGTH-1) AS BYTE
END TYPE

'
' Username Target credential information
'
' This credential can be pass to LsaLogonUser to ask it to find a credential with a
' TargetName of UserName.
'

TYPE USERNAME_TARGET_CREDENTIAL_INFO
    UserName AS WSTRINGZ PTR
END TYPE

'
' Marshaled credential blob information.
'

TYPE BINARY_BLOB_CREDENTIAL_INFO
    cbBlob AS DWORD
    pbBlob AS BYTE PTR
END TYPE

'
' Credential type for credential marshaling routines
'

MACRO CRED_MARSHAL_TYPE_enum=LONG
ENUM CRED_MARSHAL_TYPE SINGULAR
    CertCredential = 1
    UsernameTargetCredential
    BinaryBlobCredential
    UsernameForPackedCredentials   ' internal only, reserved
END ENUM

'
' Protection type for credential providers secret protection routines
'

MACRO CRED_PROTECTION_TYPE_enum=LONG
ENUM CRED_PROTECTION_TYPE SINGULAR
    CredUnprotected
    CredUserProtection
    CredTrustedProtection
END ENUM

'
' Values for authentication buffers packing
'
%CRED_PACK_PROTECTED_CREDENTIALS    = &H1
%CRED_PACK_WOW_BUFFER               = &H2
%CRED_PACK_GENERIC_CREDENTIALS      = &H4

'
' Credential UI info
'

%CREDUI_INFO_DEFINED = 1

TYPE CREDUI_INFOA
    cbSize         AS DWORD
    hwndParent     AS DWORD   ' HWND
    pszMessageText AS ASCIIZ PTR
    pszCaptionText AS ASCIIZ PTR
    hbmBanner      AS DWORD   ' HBITMAP
END TYPE

TYPE CREDUI_INFOW
    cbSize         AS DWORD
    hwndParent     AS DWORD   ' HWND
    pszMessageText AS WSTRINGZ PTR
    pszCaptionText AS WSTRINGZ PTR
    hbmBanner      AS DWORD   ' HBITMAP
END TYPE

#IF %DEF(%UNICODE)
TYPE CREDUI_INFO
    CREDUI_INFOW
END TYPE
#ELSE
TYPE CREDUI_INFO
    CREDUI_INFOA
END TYPE
#ENDIF

'-----------------------------------------------------------------------------
' Values
'-----------------------------------------------------------------------------

' String length limits:

%CREDUI_MAX_MESSAGE_LENGTH        = 32767
%CREDUI_MAX_CAPTION_LENGTH        = 128
%CREDUI_MAX_GENERIC_TARGET_LENGTH = %CRED_MAX_GENERIC_TARGET_NAME_LENGTH
%CREDUI_MAX_DOMAIN_TARGET_LENGTH  = %CRED_MAX_DOMAIN_TARGET_NAME_LENGTH

'
'  Username can be in <domain>\<user> or <user>@<domain>
'  Length in characters, not including NULL termination.
'

%CREDUI_MAX_USERNAME_LENGTH       = %CRED_MAX_USERNAME_LENGTH
%CREDUI_MAX_PASSWORD_LENGTH       = (512 / 2)

'
'  Packed credential returned by SspiEncodeAuthIdentityAsStrings().
'  Length in characters, not including NULL termination.
'

%CREDUI_MAX_PACKED_CREDENTIALS_LENGTH = 65535?? / 2 - 2 ' ((MAXUSHORT / 2) - 2)

' maximum length in bytes for binary credential blobs

%CREDUI_MAX_CREDENTIALS_BLOB_SIZE     = 65535??  '  (MAXUSHORT)

'
' Flags for CredUIPromptForCredentials and/or CredUICmdLinePromptForCredentials
'

%CREDUI_FLAGS_INCORRECT_PASSWORD     = &H00001     ' indicates the username is valid, but password is not
%CREDUI_FLAGS_DO_NOT_PERSIST         = &H00002     ' Do not show "Save" checkbox, and do not persist credentials
%CREDUI_FLAGS_REQUEST_ADMINISTRATOR  = &H00004     ' Populate list box with admin accounts
%CREDUI_FLAGS_EXCLUDE_CERTIFICATES   = &H00008     ' do not include certificates in the drop list
%CREDUI_FLAGS_REQUIRE_CERTIFICATE    = &H00010
%CREDUI_FLAGS_SHOW_SAVE_CHECK_BOX    = &H00040
%CREDUI_FLAGS_ALWAYS_SHOW_UI         = &H00080
%CREDUI_FLAGS_REQUIRE_SMARTCARD      = &H00100
%CREDUI_FLAGS_PASSWORD_ONLY_OK       = &H00200
%CREDUI_FLAGS_VALIDATE_USERNAME      = &H00400
%CREDUI_FLAGS_COMPLETE_USERNAME      = &H00800     '
%CREDUI_FLAGS_PERSIST                = &H01000     ' Do not show "Save" checkbox, but persist credentials anyway
%CREDUI_FLAGS_SERVER_CREDENTIAL      = &H04000
%CREDUI_FLAGS_EXPECT_CONFIRMATION    = &H20000     ' do not persist unless caller later confirms credential via CredUIConfirmCredential() api
%CREDUI_FLAGS_GENERIC_CREDENTIALS    = &H40000     ' Credential is a generic credential
%CREDUI_FLAGS_USERNAME_TARGET_CREDENTIALS = &H80000 ' Credential has a username as the target
%CREDUI_FLAGS_KEEP_USERNAME         = &H100000      ' don't allow the user to change the supplied username


'
' Mask of flags valid for CredUIPromptForCredentials
'
%CREDUI_FLAGS_PROMPT_VALID = _
    %CREDUI_FLAGS_INCORRECT_PASSWORD OR _
    %CREDUI_FLAGS_DO_NOT_PERSIST OR _
    %CREDUI_FLAGS_REQUEST_ADMINISTRATOR OR _
    %CREDUI_FLAGS_EXCLUDE_CERTIFICATES OR _
    %CREDUI_FLAGS_REQUIRE_CERTIFICATE OR _
    %CREDUI_FLAGS_SHOW_SAVE_CHECK_BOX OR _
    %CREDUI_FLAGS_ALWAYS_SHOW_UI OR _
    %CREDUI_FLAGS_REQUIRE_SMARTCARD OR _
    %CREDUI_FLAGS_PASSWORD_ONLY_OK OR _
    %CREDUI_FLAGS_VALIDATE_USERNAME OR _
    %CREDUI_FLAGS_COMPLETE_USERNAME OR _
    %CREDUI_FLAGS_PERSIST OR _
    %CREDUI_FLAGS_SERVER_CREDENTIAL OR _
    %CREDUI_FLAGS_EXPECT_CONFIRMATION OR _
    %CREDUI_FLAGS_GENERIC_CREDENTIALS OR _
    %CREDUI_FLAGS_USERNAME_TARGET_CREDENTIALS OR _
    %CREDUI_FLAGS_KEEP_USERNAME


'
' Flags for CredUIPromptForWindowsCredentials and CPUS_CREDUI Usage Scenarios
'

%CREDUIWIN_GENERIC                = &H00000001  ' Plain text username/password is being requested
%CREDUIWIN_CHECKBOX               = &H00000002  ' Show the Save Credential checkbox
%CREDUIWIN_AUTHPACKAGE_ONLY       = &H00000010  ' Only Cred Providers that support the input auth package should enumerate
%CREDUIWIN_IN_CRED_ONLY           = &H00000020  ' Only the incoming cred for the specific auth package should be enumerated
%CREDUIWIN_ENUMERATE_ADMINS       = &H00000100  ' Cred Providers should enumerate administrators only
%CREDUIWIN_ENUMERATE_CURRENT_USER = &H00000200  ' Only the incoming cred for the specific auth package should be enumerated
%CREDUIWIN_SECURE_PROMPT          = &H00001000  ' The Credui prompt should be displayed on the secure desktop
%CREDUIWIN_PACK_32_WOW            = &H10000000  ' Tell the credential provider it should be packing its Auth Blob 32 bit even though it is running 64 native

%CREDUIWIN_VALID_FLAGS            = _
    %CREDUIWIN_GENERIC                OR _
    %CREDUIWIN_CHECKBOX               OR _
    %CREDUIWIN_AUTHPACKAGE_ONLY       OR _
    %CREDUIWIN_IN_CRED_ONLY           OR _
    %CREDUIWIN_ENUMERATE_ADMINS       OR _
    %CREDUIWIN_ENUMERATE_CURRENT_USER OR _
    %CREDUIWIN_SECURE_PROMPT          OR _
    %CREDUIWIN_PACK_32_WOW

'-----------------------------------------------------------------------------
' Functions
'-----------------------------------------------------------------------------


'
' Values of flags to CredWrite and CredWriteDomainCredentials
'

%CRED_PRESERVE_CREDENTIAL_BLOB = &H1

DECLARE FUNCTION CredWriteW LIB "AdvApi32.dll" ALIAS "CredWriteW" ( _
    BYVAL Cred  AS CREDENTIALW, _
    BYVAL Flags AS DWORD) _
    AS LONG  ' BOOL

DECLARE FUNCTION CredWriteA LIB "AdvApi32.dll" ALIAS "CredWriteA" ( _
    BYVAL Cred  AS CREDENTIALA, _
    BYVAL Flags AS DWORD) _
    AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO CredWrite=CredWriteW
#ELSE
MACRO CredWrite=CredWriteA
#ENDIF ' UNICODE


DECLARE FUNCTION CredReadW LIB "AdvApi32.dll" ALIAS "CredReadW" ( _
    TargetName  AS WSTRINGZ, _
    BYVAL dType AS DWORD, _
    BYVAL Flags AS DWORD, _
    pCred       AS CREDENTIALW) _
    AS LONG   ' BOOL

DECLARE FUNCTION CredReadA LIB "AdvApi32.dll" ALIAS "CredReadA" ( _
    TargetName  AS ASCIIZ, _
    BYVAL dType AS DWORD, _
    BYVAL Flags AS DWORD, _
    pCred       AS CREDENTIALA) _
    AS LONG   ' BOOL

#IF %DEF(%UNICODE)
MACRO CredRead=CredReadW
#ELSE
MACRO CredRead=CredReadA
#ENDIF ' UNICODE


'
' Values of flags to CredEnumerate
'

%CRED_ENUMERATE_ALL_CREDENTIALS = &H1

DECLARE FUNCTION CredEnumerateW LIB "AdvApi32.dll" ALIAS "CredEnumerateW" ( _
    Filter      AS WSTRINGZ, _
    BYVAL Flags AS DWORD, _
    COUNT       AS DWORD, _
    Cred        AS ANY) _   ' CREDENTIALW PTR PTR PTR
    AS LONG  ' BOOL

DECLARE FUNCTION CredEnumerateA LIB "AdvApi32.dll" ALIAS "CredEnumerateA" ( _
    Filter      AS ASCIIZ, _
    BYVAL Flags AS DWORD, _
    COUNT       AS DWORD, _
    Cred        AS ANY) _   ' CREDENTIALA PTR PTR PTR
    AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO CredEnumerate=CredEnumerateW
#ELSE
MACRO CredEnumerate=CredEnumerateA
#ENDIF ' UNICODE


DECLARE FUNCTION CredWriteDomainCredentialsW LIB "AdvApi32.dll" _
    ALIAS "CredWriteDomainCredentialsW" ( _
    TargetInfo  AS CREDENTIAL_TARGET_INFORMATIONW, _
    Cred        AS CREDENTIALW, _
    BYVAL Flags AS DWORD) _
    AS LONG

DECLARE FUNCTION CredWriteDomainCredentialsA LIB "AdvApi32.dll" _
    ALIAS "CredWriteDomainCredentialsA" ( _
    TargetInfo  AS CREDENTIAL_TARGET_INFORMATIONA, _
    Cred        AS CREDENTIALA, _
    BYVAL Flags AS DWORD) _
    AS LONG

#IF %DEF(%UNICODE)
MACRO CredWriteDomainCredentials=CredWriteDomainCredentialsW
#ELSE
MACRO CredWriteDomainCredentials=CredWriteDomainCredentialsA
#ENDIF ' UNICODE



'
' Values of flags to CredReadDomainCredentials
'

%CRED_CACHE_TARGET_INFORMATION = &H1


DECLARE FUNCTION CredReadDomainCredentialsW LIB "AdvApi32.dll" _
    ALIAS "CredReadDomainCredentialsW" ( _
    TargetInfo  AS CREDENTIAL_TARGET_INFORMATIONW, _
    BYVAL Flags AS DWORD, _
    COUNT       AS DWORD, _
    Cred        AS ANY) _  ' CREDENTIALW PTR PTR PTR
    AS LONG  ' BOOL

DECLARE FUNCTION CredReadDomainCredentialsA LIB "AdvApi32.dll" _
    ALIAS "CredReadDomainCredentialsA" ( _
    TargetInfo  AS CREDENTIAL_TARGET_INFORMATIONA, _
    BYVAL Flags AS DWORD, _
    COUNT       AS DWORD, _
    Cred        AS ANY) _  ' CREDENTIALA PTR PTR PTR
    AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO CredReadDomainCredentials=CredReadDomainCredentialsW
#ELSE
MACRO CredReadDomainCredentials=CredReadDomainCredentialsA
#ENDIF ' UNICODE


DECLARE FUNCTION CredDeleteW LIB "AdvApi32.dll" ALIAS "CredDeleteW" ( _
    TargetName  AS WSTRINGZ, _
    BYVAL dType AS DWORD, _
    Flags       AS DWORD) _
    AS LONG  ' BOOL

DECLARE FUNCTION CredDeleteA LIB "AdvApi32.dll" ALIAS "CredDeleteA" ( _
    TargetName  AS ASCIIZ, _
    BYVAL dType AS DWORD, _
    Flags       AS DWORD) _
    AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO CredDelete=CredDeleteW
#ELSE
MACRO CredDelete=CredDeleteA
#ENDIF ' UNICODE


DECLARE FUNCTION CredRenameW LIB "AdvApi32.dll" ALIAS "CredRenameW" ( _
    OldTargetName AS WSTRINGZ, _
    NewTargetName AS WSTRINGZ, _
    BYVAL dType   AS DWORD, _
    BYVAL Flags   AS DWORD) _
    AS LONG  ' BOOL

DECLARE FUNCTION CredRenameA LIB "AdvApi32.dll" ALIAS "CredRenameA" ( _
    OldTargetName AS ASCIIZ, _
    NewTargetName AS ASCIIZ, _
    BYVAL dType   AS DWORD, _
    BYVAL Flags   AS DWORD) _
    AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO CredRename=CredRenameW
#ELSE
MACRO CredRename=CredRenameA
#ENDIF ' UNICODE

'
' Values of flags to CredGetTargetInfo
'

%CRED_ALLOW_NAME_RESOLUTION = &H1


DECLARE FUNCTION CredGetTargetInfoW LIB "AdvApi32.dll" _
    ALIAS "CredGetTargetInfoW" ( _
    TargetName  AS WSTRINGZ, _
    BYVAL Flags AS DWORD, _
    TargetInfo  AS ANY) _    ' CREDENTIAL_TARGET_INFORMATIONW PTR PTR
    AS LONG  ' BOOL

DECLARE FUNCTION CredGetTargetInfoA LIB "AdvApi32.dll" _
    ALIAS "CredGetTargetInfoA" ( _
    TargetName  AS ASCIIZ, _
    BYVAL Flags AS DWORD, _
    TargetInfo  AS ANY) _    ' CREDENTIAL_TARGET_INFORMATIONA PTR PTR
    AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO CredGetTargetInfo=CredGetTargetInfoW
#ELSE
MACRO CredGetTargetInfo=CredGetTargetInfoA
#ENDIF ' UNICODE

DECLARE FUNCTION CredMarshalCredentialW LIB "AdvApi32.dll" _
    ALIAS "CredMarshalCredentialW" ( _
    BYVAL CredType AS CRED_MARSHAL_TYPE_enum, _
    Cred           AS ANY, _       ' PVOID
    MarshaledCredential AS ANY) _  ' WSTRINGZ PTR PTR
    AS LONG  ' BOOL

DECLARE FUNCTION CredMarshalCredentialA LIB "AdvApi32.dll" _
    ALIAS "CredMarshalCredentialA" ( _
    BYVAL CredType AS CRED_MARSHAL_TYPE_enum, _
    Cred           AS ANY, _       ' PVOID
    MarshaledCredential AS ANY) _  ' ASCIIZ PTR PTR
    AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO CredMarshalCredential=CredMarshalCredentialW
#ELSE
MACRO CredMarshalCredential=CredMarshalCredentialA
#ENDIF ' UNICODE

DECLARE FUNCTION CredUnmarshalCredentialW LIB "AdvApi32.dll" _
    ALIAS "CredUnmarshalCredentialW" ( _
    MarshaledCredential AS WSTRINGZ, _
    CredType            AS CRED_MARSHAL_TYPE_enum, _
    Cred                AS ANY) _   ' PVOID *
    AS LONG  ' BOOL

DECLARE FUNCTION CredUnmarshalCredentialA LIB "AdvApi32.dll" _
    ALIAS "CredUnmarshalCredentialA" ( _
    MarshaledCredential AS ASCIIZ, _
    CredType            AS CRED_MARSHAL_TYPE_enum, _
    Cred                AS ANY) _   ' PVOID *
    AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO CredUnmarshalCredential=CredUnmarshalCredentialW
#ELSE
MACRO CredUnmarshalCredential=CredUnmarshalCredentialA
#ENDIF ' UNICODE

DECLARE FUNCTION CredIsMarshaledCredentialW LIB "AdvApi32.dll" _
    ALIAS "CredIsMarshaledCredentialW" _
    (MarshaledCredential AS WSTRINGZ) _
    AS LONG  ' BOOL

DECLARE FUNCTION CredIsMarshaledCredentialA LIB "AdvApi32.dll" _
    ALIAS "CredIsMarshaledCredentialA" _
    (MarshaledCredential AS ASCIIZ) _
    AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO CredIsMarshaledCredential=CredIsMarshaledCredentialW
#ELSE
MACRO CredIsMarshaledCredential=CredIsMarshaledCredentialA
#ENDIF ' UNICODE

DECLARE FUNCTION CredUnPackAuthenticationBufferW LIB "CredUI.dll" _
    ALIAS "CredUnPackAuthenticationBufferW" ( _
    BYVAL dwFlags      AS DWORD, _
    pAuthBuffer        AS ANY, _
    BYVAL cbAuthBuffer AS DWORD, _
    pszUserName        AS WSTRINGZ, _
    pcchMaxUserName    AS DWORD, _
    pszDomainName      AS WSTRINGZ, _
    pcchMaxDomainName  AS DWORD, _
    pszPassword        AS WSTRINGZ, _
    pcchMaxPassword    AS DWORD) _
    AS LONG  ' BOOL

DECLARE FUNCTION CredUnPackAuthenticationBufferA LIB "CredUI.dll" _
    ALIAS "CredUnPackAuthenticationBufferA" ( _
    BYVAL dwFlags      AS DWORD, _
    pAuthBuffer        AS ANY, _
    BYVAL cbAuthBuffer AS DWORD, _
    pszUserName        AS ASCIIZ, _
    pcchMaxUserName    AS DWORD, _
    pszDomainName      AS ASCIIZ, _
    pcchMaxDomainName  AS DWORD, _
    pszPassword        AS ASCIIZ, _
    pcchMaxPassword    AS DWORD) _
    AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO CredUnPackAuthenticationBuffer=CredUnPackAuthenticationBufferW
#ELSE
MACRO CredUnPackAuthenticationBuffer=CredUnPackAuthenticationBufferA
#ENDIF 'UNICODE

DECLARE FUNCTION CredPackAuthenticationBufferW LIB "CredUI.dll" _
    ALIAS "CredPackAuthenticationBufferW" ( _
    BYVAL dwFlags            AS DWORD, _
    pszUserName              AS WSTRINGZ, _
    pszPassword              AS WSTRINGZ, _
    BYVAL pPackedCredentials AS BYTE PTR, _
    pcbPackedCredentials     AS DWORD) _
    AS LONG  ' BOOL

DECLARE FUNCTION CredPackAuthenticationBufferA LIB "CredUI.dll" _
    ALIAS "CredPackAuthenticationBufferA" ( _
    BYVAL dwFlags            AS DWORD, _
    pszUserName              AS ASCIIZ, _
    pszPassword              AS ASCIIZ, _
    BYVAL pPackedCredentials AS BYTE PTR, _
    pcbPackedCredentials     AS DWORD) _
    AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO CredPackAuthenticationBuffer=CredPackAuthenticationBufferW
#ELSE
MACRO CredPackAuthenticationBuffer=CredPackAuthenticationBufferA
#ENDIF 'UNICODE

DECLARE FUNCTION CredProtectW LIB "AdvApi32.dll" ALIAS "CredProtectW" ( _
    BYVAL fAsSelf           AS LONG, _   ' BOOL
    pszCredentials          AS WSTRINGZ, _
    BYVAL cchCredentials    AS DWORD, _
    pszProtectedCredentials AS WSTRINGZ, _
    pcchMaxChars            AS DWORD, _
    ProtectionType          AS CRED_PROTECTION_TYPE_enum) _
    AS LONG  ' BOOL

DECLARE FUNCTION CredProtectA LIB "AdvApi32.dll" ALIAS "CredProtectA" ( _
    BYVAL fAsSelf           AS LONG, _   ' BOOL
    pszCredentials          AS ASCIIZ, _
    BYVAL cchCredentials    AS DWORD, _
    pszProtectedCredentials AS ASCIIZ, _
    pcchMaxChars            AS DWORD, _
    ProtectionType          AS CRED_PROTECTION_TYPE_enum) _
    AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO CredProtect=CredProtectW
#ELSE
MACRO CredProtect=CredProtectA
#ENDIF 'UNICODE

DECLARE FUNCTION CredUnprotectW LIB "AdvApi32.dll" ALIAS "CredUnprotectW" ( _
    BYVAL fAsSelf                 AS LONG, _   ' BOOL
    pszProtectionCredentials      AS WSTRINGZ, _
    BYVAL cchProtectedCredentials AS DWORD, _
    pszCredentials                AS WSTRINGZ, _
    pcchMaxChars                  AS DWORD) _
    AS LONG  ' BOOL

DECLARE FUNCTION CredUnprotectA LIB "AdvApi32.dll" ALIAS "CredUnprotectA" ( _
    BYVAL fAsSelf                 AS LONG, _   ' BOOL
    pszProtectionCredentials      AS ASCIIZ, _
    BYVAL cchProtectedCredentials AS DWORD, _
    pszCredentials                AS ASCIIZ, _
    pcchMaxChars                  AS DWORD) _
    AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO CredUnprotect=CredUnprotectW
#ELSE
MACRO CredUnprotect=CredUnprotectA
#ENDIF 'UNICODE

DECLARE FUNCTION CredIsProtectedW LIB "AdvApi32.dll" _
    ALIAS "CredIsProtectedW" ( _
    pszProtectedCredentials AS WSTRINGZ, _
    pProtectionType AS CRED_PROTECTION_TYPE_enum) _
    AS LONG  ' BOOL

DECLARE FUNCTION CredIsProtectedA LIB "AdvApi32.dll" _
    ALIAS "CredIsProtectedA" ( _
    pszProtectedCredentials AS ASCIIZ, _
    pProtectionType AS CRED_PROTECTION_TYPE_enum) _
    AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO CredIsProtected=CredIsProtectedW
#ELSE
MACRO CredIsProtected=CredIsProtectedA
#ENDIF 'UNICODE


DECLARE FUNCTION CredFindBestCredentialW LIB "AdvApi32.dll" _
    ALIAS "CredFindBestCredentialW" ( _
    TargetName  AS WSTRINGZ, _
    BYVAL dType AS DWORD, _
    BYVAL Flags AS DWORD, _
    Cred        AS ANY) _   ' CREDENTIALW PTR PTR
    AS LONG  ' BOOL

DECLARE FUNCTION CredFindBestCredentialA LIB "AdvApi32.dll" _
    ALIAS "CredFindBestCredentialA" ( _
    TargetName  AS ASCIIZ, _
    BYVAL dType AS DWORD, _
    BYVAL Flags AS DWORD, _
    Cred        AS ANY) _   ' CREDENTIALA PTR PTR
    AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO CredFindBestCredential=CredFindBestCredentialW
#ELSE
MACRO CredFindBestCredential=CredFindBestCredentialA
#ENDIF ' UNICODE


DECLARE FUNCTION CredGetSessionTypes LIB "AdvApi32.dll" _
    ALIAS "CredGetSessionTypes" ( _
    BYVAL MaximumPersistCount AS DWORD, _
    MaximumPersist AS DWORD) _
    AS LONG  ' BOOL


DECLARE SUB CredFree LIB "AdvApi32.dll" ALIAS "CredFree" ( _
    Buffer AS ANY) ' PVOID


DECLARE FUNCTION CredUIPromptForCredentialsW LIB "CredUI.dll" _
    ALIAS "CredUIPromptForCredentialsW" ( _
    pUiInfo                    AS CREDUI_INFOW, _
    pszTargetName              AS WSTRINGZ, _
    pContext                   AS txtHandle, _
    BYVAL dwAuthError          AS DWORD, _
    pszUserName                AS WSTRINGZ, _
    ulUserNameBufferSize       AS DWORD, _
    pszPassword                AS WSTRINGZ, _
    BYVAL ulPasswordBufferSize AS DWORD, _
    fsave                      AS LONG, _  ' BOOL
    BYVAL dwFlags              AS DWORD) _
    AS DWORD

DECLARE FUNCTION CredUIPromptForCredentialsA LIB "CredUI.dll" _
    ALIAS "CredUIPromptForCredentialsA" ( _
    pUiInfo                    AS CREDUI_INFOA, _
    pszTargetName              AS ASCIIZ, _
    pContext                   AS txtHandle, _
    BYVAL dwAuthError          AS DWORD, _
    pszUserName                AS ASCIIZ, _
    ulUserNameBufferSize       AS DWORD, _
    pszPassword                AS ASCIIZ, _
    BYVAL ulPasswordBufferSize AS DWORD, _
    fsave                      AS LONG, _  ' BOOL
    BYVAL dwFlags              AS DWORD) _
    AS DWORD

#IF %DEF(%UNICODE)
MACRO CredUIPromptForCredentials=CredUIPromptForCredentialsW
#ELSE
MACRO CredUIPromptForCredentials=CredUIPromptForCredentialsA
#ENDIF

DECLARE FUNCTION CredUIPromptForWindowsCredentialsW LIB "CredUI.dll" _
    ALIAS "CredUIPromptForWindowsCredentialsW" ( _
    pUiInfo                  AS CREDUI_INFOW, _
    BYVAL dwAuthError        AS DWORD, _
    pulAuthPackage           AS DWORD, _
    pvInAuthBuffer           AS ANY, _   ' LPCVOID
    BYVAL ulInAuthBufferSize AS DWORD, _
    ppvOutAuthBuffer         AS ANY, _   ' LPVOID *
    pulOutAuthBufferSize     AS DWORD, _
    pfSave                   AS LONG, _   ' BOOL
    BYVAL dwFlags            AS DWORD) _
    AS DWORD

DECLARE FUNCTION CredUIPromptForWindowsCredentialsA LIB "CredUI.dll" _
    ALIAS "CredUIPromptForWindowsCredentialsA" ( _
    pUiInfo                  AS CREDUI_INFOA, _
    BYVAL dwAuthError        AS DWORD, _
    pulAuthPackage           AS DWORD, _
    pvInAuthBuffer           AS ANY, _   ' LPCVOID
    BYVAL ulInAuthBufferSize AS DWORD, _
    ppvOutAuthBuffer         AS ANY, _   ' LPVOID *
    pulOutAuthBufferSize     AS DWORD, _
    pfSave                   AS LONG, _   ' BOOL
    BYVAL dwFlags            AS DWORD) _
    AS DWORD

#IF %DEF(%UNICODE)
MACRO CredUIPromptForWindowsCredentials=CredUIPromptForWindowsCredentialsW
#ELSE
MACRO CredUIPromptForWindowsCredentials=CredUIPromptForWindowsCredentialsA
#ENDIF


DECLARE FUNCTION CredUIParseUserNameW LIB "CredUI.dll" _
    ALIAS "CredUIParseUserNameW" ( _
    UserName               AS WSTRINGZ, _
    USER                   AS WSTRINGZ, _
    BYVAL userBufferSize   AS DWORD, _
    domain                 AS WSTRINGZ, _
    BYVAL domainBufferSize AS DWORD) _
    AS DWORD

DECLARE FUNCTION CredUIParseUserNameA LIB "CredUI.dll" _
    ALIAS "CredUIParseUserNameA" ( _
    UserName               AS ASCIIZ, _
    USER                   AS ASCIIZ, _
    BYVAL userBufferSize   AS DWORD, _
    domain                 AS ASCIIZ, _
    BYVAL domainBufferSize AS DWORD) _
    AS DWORD

#IF %DEF(%UNICODE)
MACRO CredUIParseUserName=CredUIParseUserNameW
#ELSE
MACRO CredUIParseUserName=CredUIParseUserNameA
#ENDIF


DECLARE FUNCTION CredUICmdLinePromptForCredentialsW LIB "CredUI.dll" _
    ALIAS "CredUICmdLinePromptForCredentialsW" ( _
    pszTargetName              AS WSTRINGZ, _
    pContext                   AS txtHandle, _
    BYVAL dwAuthError          AS DWORD, _
    UserName                   AS WSTRINGZ, _
    BYVAL ulUserBufferSize     AS DWORD, _
    pszPassword                AS WSTRINGZ, _
    BYVAL ulPasswordBufferSize AS DWORD, _
    pfSave                     AS LONG, _   ' BOOL
    BYVAL dwFlags              AS DWORD) _
    AS DWORD

DECLARE FUNCTION CredUICmdLinePromptForCredentialsA LIB "CredUI.dll" _
    ALIAS "CredUICmdLinePromptForCredentialsA" ( _
    pszTargetName              AS ASCIIZ, _
    pContext                   AS txtHandle, _
    BYVAL dwAuthError          AS DWORD, _
    UserName                   AS ASCIIZ, _
    BYVAL ulUserBufferSize     AS DWORD, _
    pszPassword                AS ASCIIZ, _
    BYVAL ulPasswordBufferSize AS DWORD, _
    pfSave                     AS LONG, _   ' BOOL
    BYVAL dwFlags              AS DWORD) _
    AS DWORD

#IF %DEF(%UNICODE)
MACRO CredUICmdLinePromptForCredentials=CredUICmdLinePromptForCredentialsW
#ELSE
MACRO CredUICmdLinePromptForCredentials=CredUICmdLinePromptForCredentialsA
#ENDIF

'
' Call this API with bConfirm set to TRUE to confirm that the credential (previously created
' via CredUIGetCredentials or CredUIPromptForCredentials worked, or with bConfirm set to FALSE
' to indicate it didn't

DECLARE FUNCTION CredUIConfirmCredentialsW LIB "CredUI.dll" _
    ALIAS "CredUIConfirmCredentialsW" ( _
    pszTargetName  AS WSTRINGZ, _
    BYVAL bConfirm AS LONG) _
    AS DWORD

DECLARE FUNCTION CredUIConfirmCredentialsA LIB "CredUI.dll" _
    ALIAS "CredUIConfirmCredentialsA" ( _
    pszTargetName  AS ASCIIZ, _
    BYVAL bConfirm AS LONG) _
    AS DWORD

#IF %DEF(%UNICODE)
MACRO CredUIConfirmCredentials=CredUIConfirmCredentialsW
#ELSE
MACRO CredUIConfirmCredentials=CredUIConfirmCredentialsA
#ENDIF


DECLARE FUNCTION CredUIStoreSSOCredW LIB "CredUI.dll" _
    ALIAS "CredUIStoreSSOCredW" ( _
    pszRealm       AS WSTRINGZ, _
    pszUsername    AS WSTRINGZ, _
    pszPassword    AS WSTRINGZ, _
    BYVAL bPersist AS LONG) _   ' BOOL
    AS DWORD

DECLARE FUNCTION CredUIReadSSOCredW LIB "CredUI.dll" _
    ALIAS "CredUIReadSSOCredW" ( _
    pszRealm     AS WSTRINGZ, _
    ppszUsername AS ANY) _   ' PWSTR *
    AS DWORD
