'------------------------------------------------------------------------------
'
'  Sspi.inc - Security Support Provider Interface definitions
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from Sspi.h dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

#INCLUDE "SdkDdkVer.inc"

%SSPI_H = 1

%SECURITY_WIN32 = 1


'
' Determine environment:
'

#IF %DEF(%SECURITY_WIN32)
%ISSP_LEVEL = 32
%ISSP_MODE  = 1
#ENDIF ' %SECURITY_WIN32

#IF %DEF(%SECURITY_KERNEL)
%ISSP_LEVEL = 32

'
' SECURITY_KERNEL trumps SECURITY_WIN32.  Undefine ISSP_MODE so that
' we don't get redefine errors.
'
#IF %DEF(%ISSP_MODE)
'#undef %ISSP_MODE
#ELSE
%ISSP_MODE = 0
#ENDIF
#ENDIF ' %SECURITY_KERNEL

#IF %DEF(%SECURITY_MAC)
%ISSP_LEVEL = 32
%ISSP_MODE  = 1
#ENDIF ' %SECURITY_MAC


'#IF NOT %DEF(%ISSP_LEVEL)
'#error  You must define one of SECURITY_WIN32, SECURITY_KERNEL, or
'#error  SECURITY_MAC
'#endif ' NOT %ISSP_LEVEL


'
' Now, define platform specific mappings:
'


'typedef WCHAR SEC_WCHAR;
'typedef CHAR SEC_CHAR;

#IF NOT %DEF(%SECSTATUS_DEFINED)
MACRO SECURITY_STATUS=LONG
%SECSTATUS_DEFINED = 1
#ENDIF

'#define SEC_TEXT TEXT
'#define SEC_FAR
'#define SEC_ENTRY __stdcall


'
' Decide what a string - 32 bits only since for 16 bits it is clear.
'


'#IF %DEF(%UNICODE)
'typedef SEC_WCHAR * SECURITY_PSTR;
'typedef CONST SEC_WCHAR * SECURITY_PCSTR;
'#else ' UNICODE
'typedef SEC_CHAR * SECURITY_PSTR;
'typedef CONST SEC_CHAR * SECURITY_PCSTR;
'#endif ' UNICODE



'
' Equivalent string for rpcrt:
'

'#define __SEC_FAR SEC_FAR


'
' Okay, security specific types:
'



#IF NOT %DEF(%SECHANDLE_DEFINED)
TYPE SecHandle
    dwLower AS DWORD
    dwUpper AS DWORD
END TYPE

%SECHANDLE_DEFINED = 1
#ENDIF ' %SECHANDLE_DEFINED

'#define SecInvalidateHandle( x )     _
'            ((PSecHandle) (x))->dwLower = ((PSecHandle) (x))->dwUpper = ((ULONG_PTR) ((INT_PTR)-1)) ;
'
'#define SecIsValidHandle( x )  _
'            ( ( ((PSecHandle) (x))->dwLower <> ((ULONG_PTR) ((INT_PTR) -1 ))) AND  _
'              ( ((PSecHandle) (x))->dwUpper <> ((ULONG_PTR) ((INT_PTR) -1 ))) )

'
' pseudo handle value: the handle has already been deleted
'

%SEC_DELETED_HANDLE = &HFFFFFFFE???  ' ((ULONG_PTR) (-2))

TYPE CredHandle
    SecHandle
END TYPE
'typedef PSecHandle PCredHandle;

TYPE CtxtHandle
    SecHandle
END TYPE
'typedef PSecHandle PCtxtHandle;



'#IF %DEF(%WIN32_CHICAGO)
'
''typedef unsigned __int64 QWORD;
'MACRO SECURITY_INTEGER=QUAD
'MACRO SEC_SUCCESS(STATUS)=ABS((STATUS) >= 0)
'
'#ELSEIF %DEF(%NTDEF) OR %DEF(%WINNT)
'
'MACRO SECURITY_INTEGER=QUAD
'
'#ELSE ' %NTDEF OR %WINNT

TYPE SECURITY_INTEGER
    LowPart  AS DWORD
    HighPart AS LONG
END TYPE

'#ENDIF ' %NTDEF OR %WINNT
'
'#IF NOT %DEF(%SECURITY_MAC)

TYPE TimeStamp
    SECURITY_INTEGER
END TYPE
'typedef SECURITY_INTEGER * PTimeStamp;
'
'#ELSE ' SECURITY_MAC
'MACRO TimeStamp=DWORD
'typedef DWORD * PTimeStamp;
'#ENDIF ' SECUIRT_MAC



'
' If we are in 32 bit mode, define the SECURITY_STRING structure,
' as a clone of the base UNICODE_STRING structure.  This is used
' internally in security components, an as the string interface
' for kernel components (e.g. FSPs)
'

#IF NOT %DEF(%NTDEF)
TYPE SECURITY_STRING
    Length        AS WORD
    MaximumLength AS WORD
    Buffer        AS WORD PTR
END TYPE
#ELSE ' %NTDEF
TYPE SECURITY_STRING
    UNICODE_STRING
END TYPE
#ENDIF ' %NTDEF



'
' SecPkgInfo structure
'
'  Provides general information about a security provider
'

TYPE SecPkgInfoW
    fCapabilities AS DWORD         ' Capability bitmask
    wVersion      AS WORD          ' Version of driver
    wRPCID        AS WORD          ' ID for RPC Runtime
    cbMaxToken    AS DWORD         ' Size of authentication token (max)
    Name          AS WSTRINGZ PTR  ' Text name
    Comment       AS WSTRINGZ PTR  ' Comment
END TYPE


TYPE SecPkgInfoA
    fCapabilities AS DWORD         ' Capability bitmask
    wVersion      AS WORD          ' Version of driver
    wRPCID        AS WORD          ' ID for RPC Runtime
    cbMaxToken    AS DWORD         ' Size of authentication token (max)
    Name          AS ASCIIZ PTR    ' Text name
    Comment       AS ASCIIZ PTR    ' Comment
END TYPE

#IF %DEF(%UNICODE)
TYPE SecPkgInfo
    SecPkgInfoW
END TYPE
#ELSE
TYPE SecPkgInfo
    SecPkgInfoA
END TYPE
#ENDIF ' NOT %UNICODE


'
'  Security Package Capabilities
'
%SECPKG_FLAG_INTEGRITY              = &H00000001  ' Supports integrity on messages
%SECPKG_FLAG_PRIVACY                = &H00000002  ' Supports privacy (confidentiality)
%SECPKG_FLAG_TOKEN_ONLY             = &H00000004  ' Only security token needed
%SECPKG_FLAG_DATAGRAM               = &H00000008  ' Datagram RPC support
%SECPKG_FLAG_CONNECTION             = &H00000010  ' Connection oriented RPC support
%SECPKG_FLAG_MULTI_REQUIRED         = &H00000020  ' Full 3-leg required for re-auth.
%SECPKG_FLAG_CLIENT_ONLY            = &H00000040  ' Server side functionality not available
%SECPKG_FLAG_EXTENDED_ERROR         = &H00000080  ' Supports extended error msgs
%SECPKG_FLAG_IMPERSONATION          = &H00000100  ' Supports impersonation
%SECPKG_FLAG_ACCEPT_WIN32_NAME      = &H00000200  ' Accepts Win32 names
%SECPKG_FLAG_STREAM                 = &H00000400  ' Supports stream semantics
%SECPKG_FLAG_NEGOTIABLE             = &H00000800  ' Can be used by the negotiate package
%SECPKG_FLAG_GSS_COMPATIBLE         = &H00001000  ' GSS Compatibility Available
%SECPKG_FLAG_LOGON                  = &H00002000  ' Supports common LsaLogonUser
%SECPKG_FLAG_ASCII_BUFFERS          = &H00004000  ' Token Buffers are in ASCII
%SECPKG_FLAG_FRAGMENT               = &H00008000  ' Package can fragment to fit
%SECPKG_FLAG_MUTUAL_AUTH            = &H00010000  ' Package can perform mutual authentication
%SECPKG_FLAG_DELEGATION             = &H00020000  ' Package can delegate
%SECPKG_FLAG_READONLY_WITH_CHECKSUM = &H00040000  ' Package can delegate
%SECPKG_FLAG_RESTRICTED_TOKENS      = &H00080000  ' Package supports restricted callers
%SECPKG_FLAG_NEGO_EXTENDER          = &H00100000  ' this package extends SPNEGO, there is at most one
%SECPKG_FLAG_NEGOTIABLE2            = &H00200000  ' this package is negotiated under the NegoExtender

%SECPKG_ID_NONE    = &HFFFF??


'
' SecBuffer
'
'  Generic memory descriptors for buffers passed in to the security
'  API
'

TYPE SecBuffer
    cbBuffer   AS DWORD           ' Size of the buffer, in bytes
    BufferType AS DWORD           ' Type of the buffer (below)
    pvBuffer   AS DWORD  ' pvoid  ' Pointer to the buffer
END TYPE

TYPE SecBufferDesc
    ulVersion AS DWORD            ' Version number
    cBuffers  AS DWORD            ' Number of buffers
    pBuffers  AS SecBuffer PTR    ' Pointer to array of buffers
END TYPE

%SECBUFFER_VERSION              = 0

%SECBUFFER_EMPTY                = 0   ' Undefined, replaced by provider
%SECBUFFER_DATA                 = 1   ' Packet data
%SECBUFFER_TOKEN                = 2   ' Security token
%SECBUFFER_PKG_PARAMS           = 3   ' Package specific parameters
%SECBUFFER_MISSING              = 4   ' Missing Data indicator
%SECBUFFER_EXTRA                = 5   ' Extra data
%SECBUFFER_STREAM_TRAILER       = 6   ' Security Trailer
%SECBUFFER_STREAM_HEADER        = 7   ' Security Header
%SECBUFFER_NEGOTIATION_INFO     = 8   ' Hints from the negotiation pkg
%SECBUFFER_PADDING              = 9   ' non-data padding
%SECBUFFER_STREAM               = 10  ' whole encrypted message
%SECBUFFER_MECHLIST             = 11
%SECBUFFER_MECHLIST_SIGNATURE   = 12
%SECBUFFER_TARGET               = 13  ' obsolete
%SECBUFFER_CHANNEL_BINDINGS     = 14
%SECBUFFER_CHANGE_PASS_RESPONSE = 15
%SECBUFFER_TARGET_HOST          = 16
%SECBUFFER_ALERT                = 17

%SECBUFFER_ATTRMASK               = &HF0000000???
%SECBUFFER_READONLY               = &H80000000???  ' Buffer is read-only, no checksum
%SECBUFFER_READONLY_WITH_CHECKSUM = &H10000000  ' Buffer is read-only, and checksummed
%SECBUFFER_RESERVED               = &H60000000  ' Flags reserved to security system


TYPE SEC_NEGOTIATION_INFO
    Size       AS DWORD         ' Size of this structure
    NameLength AS DWORD         ' Length of name hint
    Name       AS WSTRINGZ PTR  ' Name hint
    Reserved   AS DWORD         ' void ptr ' Reserved
END TYPE

TYPE SEC_CHANNEL_BINDINGS
    dwInitiatorAddrType     AS DWORD
    cbInitiatorLength       AS DWORD
    dwInitiatorOffset       AS DWORD
    dwAcceptorAddrType      AS DWORD
    cbAcceptorLength        AS DWORD
    dwAcceptorOffset        AS DWORD
    cbApplicationDataLength AS DWORD
    dwApplicationDataOffset AS DWORD
END TYPE


'
'  Data Representation Constant:
'
%SECURITY_NATIVE_DREP       = &H00000010
%SECURITY_NETWORK_DREP      = &H00000000

'
'  Credential Use Flags
'
%SECPKG_CRED_INBOUND        = &H00000001
%SECPKG_CRED_OUTBOUND       = &H00000002
%SECPKG_CRED_BOTH           = &H00000003
%SECPKG_CRED_DEFAULT        = &H00000004
%SECPKG_CRED_RESERVED       = &HF0000000???

'
'  SSP SHOULD prompt the user for credentials/consent, independent
'  of whether credentials to be used are the 'logged on' credentials
'  or retrieved from credman.
'
'  An SSP may choose not to prompt, however, in circumstances determined
'  by the SSP.
'

%SECPKG_CRED_AUTOLOGON_RESTRICTED   = &H00000010

'
' auth will always fail, ISC() is called to process policy data only
'

%SECPKG_CRED_PROCESS_POLICY_ONLY    = &H00000020

'
'  InitializeSecurityContext Requirement and return flags:
'

%ISC_REQ_DELEGATE               = &H00000001
%ISC_REQ_MUTUAL_AUTH            = &H00000002
%ISC_REQ_REPLAY_DETECT          = &H00000004
%ISC_REQ_SEQUENCE_DETECT        = &H00000008
%ISC_REQ_CONFIDENTIALITY        = &H00000010
%ISC_REQ_USE_SESSION_KEY        = &H00000020
%ISC_REQ_PROMPT_FOR_CREDS       = &H00000040
%ISC_REQ_USE_SUPPLIED_CREDS     = &H00000080
%ISC_REQ_ALLOCATE_MEMORY        = &H00000100
%ISC_REQ_USE_DCE_STYLE          = &H00000200
%ISC_REQ_DATAGRAM               = &H00000400
%ISC_REQ_CONNECTION             = &H00000800
%ISC_REQ_CALL_LEVEL             = &H00001000
%ISC_REQ_FRAGMENT_SUPPLIED      = &H00002000
%ISC_REQ_EXTENDED_ERROR         = &H00004000
%ISC_REQ_STREAM                 = &H00008000
%ISC_REQ_INTEGRITY              = &H00010000
%ISC_REQ_IDENTIFY               = &H00020000
%ISC_REQ_NULL_SESSION           = &H00040000
%ISC_REQ_MANUAL_CRED_VALIDATION = &H00080000
%ISC_REQ_RESERVED1              = &H00100000
%ISC_REQ_FRAGMENT_TO_FIT        = &H00200000
' This exists only in Windows Vista and greater
%ISC_REQ_FORWARD_CREDENTIALS    = &H00400000
%ISC_REQ_NO_INTEGRITY           = &H00800000 ' honored only by SPNEGO
%ISC_REQ_USE_HTTP_STYLE         = &H01000000

%ISC_RET_DELEGATE               = &H00000001
%ISC_RET_MUTUAL_AUTH            = &H00000002
%ISC_RET_REPLAY_DETECT          = &H00000004
%ISC_RET_SEQUENCE_DETECT        = &H00000008
%ISC_RET_CONFIDENTIALITY        = &H00000010
%ISC_RET_USE_SESSION_KEY        = &H00000020
%ISC_RET_USED_COLLECTED_CREDS   = &H00000040
%ISC_RET_USED_SUPPLIED_CREDS    = &H00000080
%ISC_RET_ALLOCATED_MEMORY       = &H00000100
%ISC_RET_USED_DCE_STYLE         = &H00000200
%ISC_RET_DATAGRAM               = &H00000400
%ISC_RET_CONNECTION             = &H00000800
%ISC_RET_INTERMEDIATE_RETURN    = &H00001000
%ISC_RET_CALL_LEVEL             = &H00002000
%ISC_RET_EXTENDED_ERROR         = &H00004000
%ISC_RET_STREAM                 = &H00008000
%ISC_RET_INTEGRITY              = &H00010000
%ISC_RET_IDENTIFY               = &H00020000
%ISC_RET_NULL_SESSION           = &H00040000
%ISC_RET_MANUAL_CRED_VALIDATION = &H00080000
%ISC_RET_RESERVED1              = &H00100000
%ISC_RET_FRAGMENT_ONLY          = &H00200000
' This exists only in Windows Vista and greater
%ISC_RET_FORWARD_CREDENTIALS    = &H00400000

%ISC_RET_USED_HTTP_STYLE        = &H01000000
%ISC_RET_NO_ADDITIONAL_TOKEN    = &H02000000  ' *INTERNAL*
%ISC_RET_REAUTHENTICATION       = &H08000000  ' *INTERNAL*

%ASC_REQ_DELEGATE               = &H00000001
%ASC_REQ_MUTUAL_AUTH            = &H00000002
%ASC_REQ_REPLAY_DETECT          = &H00000004
%ASC_REQ_SEQUENCE_DETECT        = &H00000008
%ASC_REQ_CONFIDENTIALITY        = &H00000010
%ASC_REQ_USE_SESSION_KEY        = &H00000020
%ASC_REQ_ALLOCATE_MEMORY        = &H00000100
%ASC_REQ_USE_DCE_STYLE          = &H00000200
%ASC_REQ_DATAGRAM               = &H00000400
%ASC_REQ_CONNECTION             = &H00000800
%ASC_REQ_CALL_LEVEL             = &H00001000
%ASC_REQ_EXTENDED_ERROR         = &H00008000
%ASC_REQ_STREAM                 = &H00010000
%ASC_REQ_INTEGRITY              = &H00020000
%ASC_REQ_LICENSING              = &H00040000
%ASC_REQ_IDENTIFY               = &H00080000
%ASC_REQ_ALLOW_NULL_SESSION     = &H00100000
%ASC_REQ_ALLOW_NON_USER_LOGONS  = &H00200000
%ASC_REQ_ALLOW_CONTEXT_REPLAY   = &H00400000
%ASC_REQ_FRAGMENT_TO_FIT        = &H00800000
%ASC_REQ_FRAGMENT_SUPPLIED      = &H00002000
%ASC_REQ_NO_TOKEN               = &H01000000
%ASC_REQ_PROXY_BINDINGS         = &H04000000
'      SSP_RET_REAUTHENTICATION       = &H08000000  ' *INTERNAL*
%ASC_REQ_ALLOW_MISSING_BINDINGS = &H10000000

%ASC_RET_DELEGATE               = &H00000001
%ASC_RET_MUTUAL_AUTH            = &H00000002
%ASC_RET_REPLAY_DETECT          = &H00000004
%ASC_RET_SEQUENCE_DETECT        = &H00000008
%ASC_RET_CONFIDENTIALITY        = &H00000010
%ASC_RET_USE_SESSION_KEY        = &H00000020
%ASC_RET_ALLOCATED_MEMORY       = &H00000100
%ASC_RET_USED_DCE_STYLE         = &H00000200
%ASC_RET_DATAGRAM               = &H00000400
%ASC_RET_CONNECTION             = &H00000800
%ASC_RET_CALL_LEVEL             = &H00002000 ' skipped 1000 to be like ISC_
%ASC_RET_THIRD_LEG_FAILED       = &H00004000
%ASC_RET_EXTENDED_ERROR         = &H00008000
%ASC_RET_STREAM                 = &H00010000
%ASC_RET_INTEGRITY              = &H00020000
%ASC_RET_LICENSING              = &H00040000
%ASC_RET_IDENTIFY               = &H00080000
%ASC_RET_NULL_SESSION           = &H00100000
%ASC_RET_ALLOW_NON_USER_LOGONS  = &H00200000
%ASC_RET_ALLOW_CONTEXT_REPLAY   = &H00400000  ' deprecated - don't use this flag!!!
%ASC_RET_FRAGMENT_ONLY          = &H00800000
%ASC_RET_NO_TOKEN               = &H01000000
%ASC_RET_NO_ADDITIONAL_TOKEN    = &H02000000  ' *INTERNAL*
%ASC_RET_NO_PROXY_BINDINGS      = &H04000000
'      SSP_RET_REAUTHENTICATION       = &H08000000  ' *INTERNAL*
%ASC_RET_MISSING_BINDINGS       = &H10000000

'
'  Security Credentials Attributes:
'

%SECPKG_CRED_ATTR_NAMES        = 1
%SECPKG_CRED_ATTR_SSI_PROVIDER = 2

TYPE SecPkgCredentials_NamesW
    sUserName AS WSTRINGZ PTR
END TYPE


TYPE SecPkgCredentials_NamesA
    sUserName AS ASCIIZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE SecPkgCredentials_Names
    SecPkgCredentials_NamesW
END TYPE
#ELSE
TYPE SecPkgCredentials_Names
    SecPkgCredentials_NamesA
END TYPE
#ENDIF ' NOT %UNICODE


#IF %NTDDI_VERSION > %NTDDI_WS03
TYPE SecPkgCredentials_SSIProviderW
    sProviderName      AS WSTRINGZ PTR
    ProviderInfoLength AS DWORD
    ProviderInfo       AS ASCIIZ PTR
END TYPE
#ENDIF ' End W2k3SP1 and greater

TYPE SecPkgCredentials_SSIProviderA
    sProviderName      AS ASCIIZ PTR
    ProviderInfoLength AS DWORD
    ProviderInfo       AS ASCIIZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE SecPkgCredentials_SSIProvider
    SecPkgCredentials_SSIProviderW
END TYPE
#ELSE
TYPE SecPkgCredentials_SSIProvider
    SecPkgCredentials_SSIProviderA
END TYPE
#ENDIF ' NOT %UNICODE


'
'  Security Context Attributes:
'

%SECPKG_ATTR_SIZES              = 0
%SECPKG_ATTR_NAMES              = 1
%SECPKG_ATTR_LIFESPAN           = 2
%SECPKG_ATTR_DCE_INFO           = 3
%SECPKG_ATTR_STREAM_SIZES       = 4
%SECPKG_ATTR_KEY_INFO           = 5
%SECPKG_ATTR_AUTHORITY          = 6
%SECPKG_ATTR_PROTO_INFO         = 7
%SECPKG_ATTR_PASSWORD_EXPIRY    = 8
%SECPKG_ATTR_SESSION_KEY        = 9
%SECPKG_ATTR_PACKAGE_INFO       = 10
%SECPKG_ATTR_USER_FLAGS         = 11
%SECPKG_ATTR_NEGOTIATION_INFO   = 12
%SECPKG_ATTR_NATIVE_NAMES       = 13
%SECPKG_ATTR_FLAGS              = 14
' These attributes exist only in Win XP and greater
%SECPKG_ATTR_USE_VALIDATED      = 15
%SECPKG_ATTR_CREDENTIAL_NAME    = 16
%SECPKG_ATTR_TARGET_INFORMATION = 17
%SECPKG_ATTR_ACCESS_TOKEN       = 18
' These attributes exist only in Win2K3 and greater
%SECPKG_ATTR_TARGET             = 19
%SECPKG_ATTR_AUTHENTICATION_ID  = 20
' These attributes exist only in Win2K3SP1 and greater
%SECPKG_ATTR_LOGOFF_TIME        = 21
'
' win7 or greater
'
%SECPKG_ATTR_NEGO_KEYS          = 22
%SECPKG_ATTR_PROMPTING_NEEDED   = 24
%SECPKG_ATTR_UNIQUE_BINDINGS    = 25
%SECPKG_ATTR_ENDPOINT_BINDINGS  = 26
%SECPKG_ATTR_CLIENT_SPECIFIED_TARGET = 27

%SECPKG_ATTR_LAST_CLIENT_TOKEN_STATUS = 30
%SECPKG_ATTR_NEGO_PKG_INFO      = 31 ' contains nego info of packages
%SECPKG_ATTR_NEGO_STATUS        = 32 ' contains the last error
%SECPKG_ATTR_CONTEXT_DELETED    = 33 ' a context has been deleted

%SECPKG_ATTR_SUBJECT_SECURITY_ATTRIBUTES = 128

TYPE SecPkgContext_SubjectAttributes
    AttributeInfo AS DWORD  ' void ptr ' contains a PAUTHZ_SECURITY_ATTRIBUTES_INFORMATION structure
END TYPE

%SECPKG_ATTR_NEGO_INFO_FLAG_NO_KERBEROS = &H1
%SECPKG_ATTR_NEGO_INFO_FLAG_NO_NTLM     = &H2

'
' types of credentials, used by SECPKG_ATTR_PROMPTING_NEEDED
'

MACRO SECPKG_CRED_CLASS_enum=LONG
ENUM SECPKG_CRED_CLASS SINGULAR
    SecPkgCredClass_None              = 0   ' no creds
    SecPkgCredClass_Ephemeral         = 10  ' logon creds
    SecPkgCredClass_PersistedGeneric  = 20  ' saved creds, not target specific
    SecPkgCredClass_PersistedSpecific = 30  ' saved creds, target specific
    SecPkgCredClass_Explicit          = 40  ' explicitly supplied creds
END ENUM

TYPE SecPkgContext_CredInfo
    CredClass         AS SECPKG_CRED_CLASS_enum
    IsPromptingNeeded AS DWORD
END TYPE

TYPE SecPkgContext_NegoPackageInfo
    PackageMask AS DWORD
END TYPE

TYPE SecPkgContext_NegoStatus
    LastStatus AS DWORD
END TYPE

TYPE SecPkgContext_Sizes
    cbMaxToken        AS DWORD
    cbMaxSignature    AS DWORD
    cbBlockSize       AS DWORD
    cbSecurityTrailer AS DWORD
END TYPE

TYPE SecPkgContext_StreamSizes
    cbHeader         AS DWORD
    cbTrailer        AS DWORD
    cbMaximumMessage AS DWORD
    cBuffers         AS DWORD
    cbBlockSize      AS DWORD
END TYPE

TYPE SecPkgContext_NamesW
    sUserName AS WSTRINGZ PTR
END TYPE


MACRO SECPKG_ATTR_LCT_STATUS_enum=LONG
ENUM SECPKG_ATTR_LCT_STATUS SINGULAR
    SecPkgAttrLastClientTokenYes
    SecPkgAttrLastClientTokenNo
    SecPkgAttrLastClientTokenMaybe
END ENUM


TYPE SecPkgContext_LastClientTokenStatus
    LastClientTokenStatus AS SECPKG_ATTR_LCT_STATUS_enum
END TYPE

TYPE SecPkgContext_NamesA
    sUserName AS ASCIIZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE SecPkgContext_Names
    SecPkgContext_NamesW
END TYPE
#ELSE
TYPE SecPkgContext_Names
    SecPkgContext_NamesA
END TYPE
#ENDIF ' NOT %UNICODE


TYPE SecPkgContext_Lifespan
    tsStart  AS TimeStamp
    tsExpiry AS TimeStamp
END TYPE

TYPE SecPkgContext_DceInfo
    AuthzSvc AS DWORD
    pPac     AS DWORD  ' void PTR
END TYPE


TYPE SecPkgContext_KeyInfoA
    sSignatureAlgorithmName AS ASCIIZ PTR
    sEncryptAlgorithmName   AS ASCIIZ PTR
    KeySize                 AS DWORD
    SignatureAlgorithm      AS DWORD
    EncryptAlgorithm        AS DWORD
END TYPE


TYPE SecPkgContext_KeyInfoW
    sSignatureAlgorithmName AS WSTRINGZ PTR
    sEncryptAlgorithmName   AS WSTRINGZ PTR
    KeySize                 AS DWORD
    SignatureAlgorithm      AS DWORD
    EncryptAlgorithm        AS DWORD
END TYPE


#IF %DEF(%UNICODE)
TYPE SecPkgContext_KeyInfo
    SecPkgContext_KeyInfoW
END TYPE
#ELSE
TYPE SecPkgContext_KeyInfo
    SecPkgContext_KeyInfoA
END TYPE
#ENDIF

TYPE SecPkgContext_AuthorityA
    sAuthorityName AS ASCIIZ PTR
END TYPE


TYPE SecPkgContext_AuthorityW
    sAuthorityName AS WSTRINGZ PTR
END TYPE


#IF %DEF(%UNICODE)
TYPE SecPkgContext_Authority
    SecPkgContext_AuthorityW
END TYPE
#ELSE
TYPE SecPkgContext_Authority
    SecPkgContext_AuthorityA
END TYPE
#ENDIF

TYPE SecPkgContext_ProtoInfoA
    sProtocolName AS ASCIIZ PTR
    majorVersion  AS DWORD
    minorVersion  AS DWORD
END TYPE


TYPE SecPkgContext_ProtoInfoW
    sProtocolName AS WSTRINGZ PTR
    majorVersion  AS DWORD
    minorVersion  AS DWORD
END TYPE


#IF %DEF(%UNICODE)
TYPE SecPkgContext_ProtoInfo
    SecPkgContext_ProtoInfoW
END TYPE
#ELSE
TYPE SecPkgContext_ProtoInfo
    SecPkgContext_ProtoInfoA
END TYPE
#ENDIF


TYPE SecPkgContext_PasswordExpiry
    tsPasswordExpires AS TimeStamp
END TYPE

#IF %NTDDI_VERSION > %NTDDI_WS03
TYPE SecPkgContext_LogoffTime
    tsLogoffTime AS TimeStamp
END TYPE
#ENDIF ' Greater than Windows Server 2003 RTM (SP1 and greater contains this)

TYPE SecPkgContext_SessionKey
    SessionKeyLength AS DWORD
    SessionKey       AS BYTE PTR
END TYPE

' used by nego2
TYPE SecPkgContext_NegoKeys DWORD FILL
    KeyType         AS DWORD
    KeyLength       AS WORD
    KeyValue        AS BYTE PTR
    VerifyKeyType   AS DWORD
    VerifyKeyLength AS WORD
    VerifyKeyValue  AS BYTE PTR
END TYPE

TYPE SecPkgContext_PackageInfoW
    PackageInfo AS SecPkgInfoW PTR
END TYPE


TYPE SecPkgContext_PackageInfoA
    PackageInfo AS SecPkgInfoA PTR
END TYPE


TYPE SecPkgContext_UserFlags
    UserFlags AS DWORD
END TYPE

TYPE SecPkgContext_Flags
    Flags AS DWORD
END TYPE


#IF %DEF(%UNICODE)
TYPE SecPkgContext_PackageInfo
    SecPkgContext_PackageInfoW
END TYPE
#ELSE
TYPE SecPkgContext_PackageInfo
    SecPkgContext_PackageInfoA
END TYPE
#ENDIF


TYPE SecPkgContext_NegotiationInfoA
    PackageInfo      AS SecPkgInfoA PTR
    NegotiationState AS DWORD
END TYPE

TYPE SecPkgContext_NegotiationInfoW
    PackageInfo      AS SecPkgInfoW PTR
    NegotiationState AS DWORD
END TYPE


#IF %DEF(%UNICODE)
TYPE SecPkgContext_NegotiationInfo
    SecPkgContext_NegotiationInfoW
END TYPE
#ELSE
TYPE SecPkgContext_NegotiationInfo
    SecPkgContext_NegotiationInfoA
END TYPE
#ENDIF

%SECPKG_NEGOTIATION_COMPLETE           = 0
%SECPKG_NEGOTIATION_OPTIMISTIC         = 1
%SECPKG_NEGOTIATION_IN_PROGRESS        = 2
%SECPKG_NEGOTIATION_DIRECT             = 3
%SECPKG_NEGOTIATION_TRY_MULTICRED      = 4


TYPE SecPkgContext_NativeNamesW
    sClientName AS WSTRINGZ PTR
    sServerName AS WSTRINGZ PTR
END TYPE

TYPE SecPkgContext_NativeNamesA
    sClientName AS ASCIIZ PTR
    sServerName AS ASCIIZ PTR
END TYPE


#IF %DEF(%UNICODE)
TYPE SecPkgContext_NativeNames
    SecPkgContext_NativeNamesW
END TYPE
#ELSE
TYPE SecPkgContext_NativeNames
    SecPkgContext_NativeNamesA
END TYPE
#ENDIF ' NOT %UNICODE


'#if OSVER(%NTDDI_VERSION) > %NTDDI_WIN2K
#IF (%NTDDI_VERSION AND %OSVERSION_MASK) > %NTDDI_WIN2K

TYPE SecPkgContext_CredentialNameW
    CredentialType  AS DWORD
    sCredentialName AS WSTRINGZ PTR
END TYPE

#ENDIF ' Later than win2k

TYPE SecPkgContext_CredentialNameA
    CredentialType  AS DWORD
    sCredentialName AS ASCIIZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE SecPkgContext_CredentialName
    SecPkgContext_CredentialNameW
END TYPE
#ELSE
TYPE SecPkgContext_CredentialName
    SecPkgContext_CredentialNameA
END TYPE
#ENDIF ' NOT %UNICODE

TYPE SecPkgContext_AccessToken
    AccessToken AS DWORD  ' void ptr
END TYPE

TYPE SecPkgContext_TargetInformation
    MarshalledTargetInfoLength AS DWORD
    MarshalledTargetInfo       AS BYTE PTR
END TYPE

TYPE SecPkgContext_AuthzID
    AuthzIDLength AS DWORD
    AuthzID       AS ASCIIZ PTR
END TYPE

TYPE SecPkgContext_Target
    TargetLength AS DWORD
    Target       AS ASCIIZ PTR
END TYPE


TYPE SecPkgContext_ClientSpecifiedTarget
    sTargetName AS WSTRINGZ PTR
END TYPE

TYPE SecPkgContext_Bindings
    BindingsLength AS DWORD
    Bindings       AS SEC_CHANNEL_BINDINGS PTR
END TYPE


DECLARE SUB SEC_GET_KEY_FN ( _
    BYVAL Arg       AS DWORD, _           ' void ptr ' Argument passed in
    BYVAL Principal AS DWORD, _           ' void ptr ' Principal ID
    BYVAL KeyVer    AS DWORD, _           ' Key Version
    BYVAL Key       AS DWORD, _           ' void ptr ptr ' Returned ptr to key
    Status          AS SECURITY_STATUS _  ' returned status
    )

'
' Flags for ExportSecurityContext
'

%SECPKG_CONTEXT_EXPORT_RESET_NEW  = &H00000001  ' New context is reset to initial state
%SECPKG_CONTEXT_EXPORT_DELETE_OLD = &H00000002  ' Old context is deleted during export
' This is only valid in W2K3SP1 and greater
%SECPKG_CONTEXT_EXPORT_TO_KERNEL  = &H00000004  ' Context is to be transferred to the kernel


#IF %ISSP_MODE = 0    ' For Kernel mode
DECLARE FUNCTION AcquireCredentialsHandleW LIB "Secur32.dll" _
    ALIAS "AcquireCredentialsHandleW" ( _
    pPrincipal           AS SECURITY_STRING, _
    pPackage             AS SECURITY_STRING, _
    BYVAL fCredentialUse AS DWORD, _       ' Flags indicating use
    pvLogonId            AS ANY, _         ' void ptr  ' Pointer to logon ID
    pAuthData            AS ANY, _         ' void ptr  ' Package specific data
    BYVAL pGetKeyFn      AS DWORD, _       ' SEC_GET_KEY_FN  ' Pointer to GetKey() func
    pvGetKeyArgument     AS ANY, _         ' void ptr  ' Value to pass to GetKey()
    phCredential         AS CredHandle, _  ' (out) Cred Handle
    ptsExpiry            AS TimeStamp _    ' (out) Lifetime (optional)
    ) AS SECURITY_STATUS
#ELSE
DECLARE FUNCTION AcquireCredentialsHandleW LIB "Secur32.dll" _
    ALIAS "AcquireCredentialsHandleW" ( _
    pszPrincipal         AS WSTRINGZ, _    ' Name of principal
    pszPackage           AS WSTRINGZ, _    ' Name of package
    BYVAL fCredentialUse AS DWORD, _       ' Flags indicating use
    pvLogonId            AS ANY, _         ' void ptr  ' Pointer to logon ID
    pAuthData            AS ANY, _         ' void ptr  ' Package specific data
    BYVAL pGetKeyFn      AS DWORD, _       ' SEC_GET_KEY_FN  ' Pointer to GetKey() func
    pvGetKeyArgument     AS ANY, _         ' void ptr  ' Value to pass to GetKey()
    phCredential         AS CredHandle, _  ' (out) Cred Handle
    ptsExpiry            AS TimeStamp _    ' (out) Lifetime (optional)
    ) AS SECURITY_STATUS
#ENDIF

#IF %ISSP_MODE = 0
DECLARE FUNCTION ACQUIRE_CREDENTIALS_HANDLE_FN_W ( _
    SECURITY_STRING, _
    SECURITY_STRING, _
    BYVAL DWORD, _
    BYVAL DWORD, _   ' void ptr
    BYVAL DWORD, _   ' void ptr
    BYVAL DWORD, _   ' SEC_GET_KEY_FN
    BYVAL DWORD, _   ' void ptr
    CredHandle, _
    TimeStamp, _
    ) AS SECURITY_STATUS
#ELSE
DECLARE FUNCTION ACQUIRE_CREDENTIALS_HANDLE_FN_W ( _
    WSTRINGZ, _
    WSTRINGZ, _
    BYVAL DWORD, _
    BYVAL DWORD, _   ' void ptr
    BYVAL DWORD, _   ' void ptr
    BYVAL DWORD, _   ' SEC_GET_KEY_FN
    BYVAL DWORD, _   ' void ptr
    CredHandle, _
    TimeStamp _
    ) AS SECURITY_STATUS
#ENDIF


DECLARE FUNCTION AcquireCredentialsHandleA LIB "Secur32.dll" _
    ALIAS "AcquireCredentialsHandleA" ( _
    pszPrincipal         AS ASCIIZ, _      ' Name of principal
    pszPackage           AS ASCIIZ, _      ' Name of package
    BYVAL fCredentialUse AS DWORD, _       ' Flags indicating use
    pvLogonId            AS ANY, _         ' void ptr ' Pointer to logon ID
    pAuthData            AS ANY, _         ' void ptr ' Package specific data
    BYVAL pGetKeyFn      AS DWORD, _       ' SEC_GET_KEY_FN ' Pointer to GetKey() func
    pvGetKeyArgument     AS ANY, _         ' void ptr ' Value to pass to GetKey()
    phCredential         AS CredHandle, _  ' (out) Cred Handle
    ptsExpiry            AS TimeStamp _    ' (out) Lifetime (optional)
    ) AS SECURITY_STATUS

DECLARE FUNCTION ACQUIRE_CREDENTIALS_HANDLE_FN_A ( _
    ASCIIZ, _
    ASCIIZ, _
    BYVAL DWORD, _
    BYVAL DWORD, _  ' void ptr
    BYVAL DWORD, _  ' void ptr
    BYVAL DWORD, _  ' SEC_GET_KEY_FN
    BYVAL DWORD, _  ' void ptr
    CredHandle, _
    TimeStamp _
    ) AS SECURITY_STATUS

#IF %DEF(%UNICODE)
MACRO AcquireCredentialsHandle=AcquireCredentialsHandleW
MACRO ACQUIRE_CREDENTIALS_HANDLE_FN=ACQUIRE_CREDENTIALS_HANDLE_FN_W
#ELSE
MACRO AcquireCredentialsHandle=AcquireCredentialsHandleA
MACRO ACQUIRE_CREDENTIALS_HANDLE_FN=ACQUIRE_CREDENTIALS_HANDLE_FN_A
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION FreeCredentialsHandle LIB "Secur32.dll" _
    ALIAS "FreeCredentialsHandle" ( _
    phCredential AS CredHandle _    ' Handle to free
    ) AS SECURITY_STATUS

DECLARE FUNCTION FREE_CREDENTIALS_HANDLE_FN ( _
    CredHandle _
    ) AS SECURITY_STATUS

#IF %ISSP_MODE = 0      ' For Kernel mode
DECLARE FUNCTION AddCredentialsW LIB "Secur32.dll" _
    ALIAS "AddCredentialsW" ( _
    hCredentials         AS CredHandle, _
    pPrincipal           AS SECURITY_STRING, _
    pPackage             AS SECURITY_STRING, _
    BYVAL fCredentialUse AS DWORD, _     ' Flags indicating use
    pAuthData            AS ANY, _       ' void ptr ' Package specific data
    BYVAL pGetKeyFn      AS DWORD, _     ' SEC_GET_KEY_FN ' Pointer to GetKey() func
    pvGetKeyArgument     AS ANY, _       ' Value to pass to GetKey()
    ptsExpiry            AS TimeStamp _  ' (out) Lifetime (optional)
    ) AS SECURITY_STATUS
#ELSE
DECLARE FUNCTION AddCredentialsW LIB "Secur32.dll" _
    ALIAS "AddCredentialsW" ( _
    hCredentials         AS CredHandle, _
    pszPrincipal         AS WSTRINGZ, _  ' Name of principal
    pszPackage           AS WSTRINGZ, _  ' Name of package
    BYVAL fCredentialUse AS DWORD, _     ' Flags indicating use
    pAuthData            AS ANY, _       ' void ptr ' Package specific data
    BYVAL pGetKeyFn      AS DWORD, _     ' SEC_GET_KEY_FN ' Pointer to GetKey() func
    pvGetKeyArgument     AS ANY, _       ' Value to pass to GetKey()
    ptsExpiry            AS TimeStamp _  ' (out) Lifetime (optional)
    ) AS SECURITY_STATUS
#ENDIF

#IF %ISSP_MODE = 0
DECLARE FUNCTION ADD_CREDENTIALS_FN_W ( _
    CredHandle, _
    SECURITY_STRING, _
    SECURITY_STRING, _
    BYVAL DWORD, _
    BYVAL DWORD, _  ' void ptr
    BYVAL DWORD, _  ' SEC_GET_KEY_FN
    BYVAL DWORD, _  ' void ptr
    TimeStamp _
    ) AS SECURITY_STATUS
#ELSE
DECLARE FUNCTION ADD_CREDENTIALS_FN_W ( _
    CredHandle, _
    WSTRINGZ, _
    WSTRINGZ, _
    BYVAL DWORD, _
    BYVAL DWORD, _  ' void ptr
    BYVAL DWORD, _  ' SEC_GET_KEY_FN
    BYVAL DWORD, _  ' void ptr
    TimeStamp _
    ) AS SECURITY_STATUS
#ENDIF

DECLARE FUNCTION AddCredentialsA LIB "Secur32.dll" _
    ALIAS "AddCredentialsA" ( _
    hCredentials         AS CredHandle, _
    pszPrincipal         AS ASCIIZ, _    ' Name of principal
    pszPackage           AS ASCIIZ, _    ' Name of package
    BYVAL fCredentialUse AS DWORD, _     ' Flags indicating use
    pAuthData            AS ANY, _       ' void ptr ' Package specific data
    BYVAL pGetKeyFn      AS DWORD, _     ' SEC_GET_KEY_FN ' Pointer to GetKey() func
    pvGetKeyArgument     AS ANY, _       ' void ptr ' Value to pass to GetKey()
    ptsExpiry            AS TimeStamp _  ' (out) Lifetime (optional)
    ) AS SECURITY_STATUS

DECLARE FUNCTION ADD_CREDENTIALS_FN_A ( _
    CredHandle, _
    ASCIIZ, _
    ASCIIZ, _
    BYVAL DWORD, _
    BYVAL DWORD, _  ' void ptr
    BYVAL DWORD, _  ' SEC_GET_KEY_FN
    BYVAL DWORD, _  ' void ptr
    TimeStamp _
    ) AS SECURITY_STATUS

#IF %DEF(%UNICODE)
MACRO AddCredentials=AddCredentialsW
MACRO ADD_CREDENTIALS_FN=ADD_CREDENTIALS_FN_W
#ELSE
MACRO AddCredentials=AddCredentialsA
MACRO ADD_CREDENTIALS_FN=ADD_CREDENTIALS_FN_A
#ENDIF

''''''''''''''''''''''''''''''''''''
'
' Password Change Functions
'
''''''''''''''''''''''''''''''''''''

#IF %ISSP_MODE <> 0

DECLARE FUNCTION ChangeAccountPasswordW LIB "Secur32.dll" _
    ALIAS "ChangeAccountPasswordW" ( _
    pszPackageName       AS WSTRINGZ, _
    pszDomainName        AS WSTRINGZ, _
    pszAccountName       AS WSTRINGZ, _
    pszOldPassword       AS WSTRINGZ, _
    pszNewPassword       AS WSTRINGZ, _
    BYVAL bImpersonating AS BYTE, _  ' BOOLEAN
    BYVAL dwReserved     AS DWORD, _
    pOutput              AS SecBufferDesc _
    ) AS SECURITY_STATUS

DECLARE FUNCTION CHANGE_PASSWORD_FN_W ( _
    WSTRINGZ, _
    WSTRINGZ, _
    WSTRINGZ, _
    WSTRINGZ, _
    WSTRINGZ, _
    BYVAL BYTE, _  ' BOOLEAN
    BYVAL DWORD, _
    SecBufferDesc _
    ) AS SECURITY_STATUS



DECLARE FUNCTION ChangeAccountPasswordA LIB "Secur32.dll" _
    ALIAS "ChangeAccountPasswordA" ( _
    pszPackageName AS ASCIIZ, _
    pszDomainName AS ASCIIZ, _
    pszAccountName AS ASCIIZ, _
    pszOldPassword AS ASCIIZ, _
    pszNewPassword AS ASCIIZ, _
    BYVAL bImpersonating AS BYTE, _  ' BOOLEAN
    BYVAL dwReserved AS DWORD, _
    pOutput AS SecBufferDesc _
    ) AS SECURITY_STATUS

DECLARE FUNCTION CHANGE_PASSWORD_FN_A ( _
    ASCIIZ, _
    ASCIIZ, _
    ASCIIZ, _
    ASCIIZ, _
    ASCIIZ, _
    BYVAL BYTE, _  ' BOOLEAN
    BYVAL DWORD, _
    SecBufferDesc _
    ) AS SECURITY_STATUS

#IF %DEF(%UNICODE)
MACRO ChangeAccountPassword=ChangeAccountPasswordW
MACRO CHANGE_PASSWORD_FN=CHANGE_PASSWORD_FN_W
#ELSE
MACRO ChangeAccountPassword=ChangeAccountPasswordA
MACRO CHANGE_PASSWORD_FN=CHANGE_PASSWORD_FN_A
#ENDIF ' NOT %UNICODE

#ENDIF ' %ISSP_MODE


''''''''''''''''''''''''''''''''''''
'
' Context Management Functions
'
''''''''''''''''''''''''''''''''''''

#IF %ISSP_MODE = 0
DECLARE FUNCTION InitializeSecurityContextW LIB "Secur32.dll" _
    ALIAS "InitializeSecurityContextW" ( _
    phCredential        AS CredHandle, _     ' Cred to base context
    phContext           AS CtxtHandle, _     ' Existing context (OPT)
    pTargetName         AS SECURITY_STRING, _
    BYVAL fContextReq   AS DWORD, _          ' Context Requirements
    BYVAL Reserved1     AS DWORD, _          ' Reserved, MBZ
    BYVAL TargetDataRep AS DWORD, _          ' Data rep of target
    pInput              AS SecBufferDesc, _  ' Input Buffers
    BYVAL Reserved2     AS DWORD, _          ' Reserved, MBZ
    phNewContext        AS CtxtHandle, _     ' (out) New Context handle
    pOutput             AS SecBufferDesc, _  ' (inout) Output Buffers
    pfContextAttr       AS DWORD, _          ' (out) Context attrs
    ptsExpiry           AS TimeStamp _       ' (out) Life span (OPT)
    ) AS SECURITY_STATUS
#ELSE
DECLARE FUNCTION InitializeSecurityContextW LIB "Secur32.dll" _
    ALIAS "InitializeSecurityContextW" ( _
    phCredential        AS CredHandle, _     ' Cred to base context
    phContext           AS CtxtHandle, _     ' Existing context (OPT)
    pszTargetName       AS WSTRINGZ, _       ' Name of target
    BYVAL fContextReq   AS DWORD, _          ' Context Requirements
    BYVAL Reserved1     AS DWORD, _          ' Reserved, MBZ
    BYVAL TargetDataRep AS DWORD, _          ' Data rep of target
    pInput              AS SecBufferDesc, _  ' Input Buffers
    BYVAL Reserved2     AS DWORD, _          ' Reserved, MBZ
    phNewContext        AS CtxtHandle, _     ' (out) New Context handle
    pOutput             AS SecBufferDesc, _  ' (inout) Output Buffers
    pfContextAttr       AS DWORD, _          ' (out) Context attrs
    ptsExpiry           AS TimeStamp _       ' (out) Life span (OPT)
    ) AS SECURITY_STATUS
#ENDIF

#IF %ISSP_MODE = 0
DECLARE FUNCTION INITIALIZE_SECURITY_CONTEXT_FN_W ( _
    CredHandle, _
    CtxtHandle, _
    SECURITY_STRING, _
    BYVAL DWORD, _
    BYVAL DWORD, _
    BYVAL DWORD, _
    SecBufferDesc, _
    BYVAL DWORD, _
    CtxtHandle, _
    SecBufferDesc, _
    DWORD, _
    TimeStamp _
    ) AS SECURITY_STATUS
#ELSE
DECLARE FUNCTION INITIALIZE_SECURITY_CONTEXT_FN_W ( _
    CredHandle, _
    CtxtHandle, _
    WSTRINGZ, _
    BYVAL DWORD, _
    BYVAL DWORD, _
    BYVAL DWORD, _
    SecBufferDesc, _
    BYVAL DWORD, _
    CtxtHandle, _
    SecBufferDesc, _
    DWORD, _
    TimeStamp _
    ) AS SECURITY_STATUS
#ENDIF

DECLARE FUNCTION InitializeSecurityContextA LIB "Secur32.dll" _
    ALIAS "InitializeSecurityContextA" ( _
    phCredential        AS CredHandle, _      ' Cred to base context
    phContext           AS CtxtHandle, _      ' Existing context (OPT)
    pszTargetName       AS ASCIIZ, _          ' Name of target
    BYVAL fContextReq   AS DWORD, _           ' Context Requirements
    BYVAL Reserved1     AS DWORD, _           ' Reserved, MBZ
    BYVAL TargetDataRep AS DWORD, _           ' Data rep of target
    pInput              AS SecBufferDesc, _   ' Input Buffers
    BYVAL Reserved2     AS DWORD, _           ' Reserved, MBZ
    phNewContext        AS CtxtHandle, _      ' (out) New Context handle
    pOutput             AS SecBufferDesc, _   ' (inout) Output Buffers
    pfContextAttr       AS DWORD, _           ' (out) Context attrs
    ptsExpiry           AS TimeStamp _        ' (out) Life span (OPT)
    ) AS SECURITY_STATUS

DECLARE FUNCTION INITIALIZE_SECURITY_CONTEXT_FN_A ( _
    CredHandle, _
    CtxtHandle, _
    ASCIIZ, _
    BYVAL DWORD, _
    BYVAL DWORD, _
    BYVAL DWORD, _
    SecBufferDesc, _
    BYVAL DWORD, _
    CtxtHandle, _
    SecBufferDesc, _
    DWORD, _
    TimeStamp _
    ) AS SECURITY_STATUS

#IF %DEF(%UNICODE)
MACRO InitializeSecurityContext=InitializeSecurityContextW
MACRO INITIALIZE_SECURITY_CONTEXT_FN=INITIALIZE_SECURITY_CONTEXT_FN_W
#ELSE
MACRO InitializeSecurityContext=InitializeSecurityContextA
MACRO INITIALIZE_SECURITY_CONTEXT_FN=INITIALIZE_SECURITY_CONTEXT_FN_A
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION AcceptSecurityContext LIB "Secur32.dll" _
    ALIAS "AcceptSecurityContext" ( _
    phCredential        AS CredHandle, _      ' Cred to base context
    phContext           AS CtxtHandle, _      ' Existing context (OPT)
    pInput              AS SecBufferDesc, _   ' Input buffer
    BYVAL fContextReq   AS DWORD, _           ' Context Requirements
    BYVAL TargetDataRep AS DWORD, _           ' Target Data Rep
    phNewContext        AS CtxtHandle, _      ' (out) New context handle
    pOutput             AS SecBufferDesc, _   ' (inout) Output buffers
    pfContextAttr       AS DWORD, _           ' (out) Context attributes
    ptsExpiry           AS TimeStamp _        ' (out) Life span (OPT)
    ) AS SECURITY_STATUS

DECLARE FUNCTION ACCEPT_SECURITY_CONTEXT_FN ( _
    CredHandle, _
    CtxtHandle, _
    SecBufferDesc, _
    BYVAL DWORD, _
    BYVAL DWORD, _
    CtxtHandle, _
    SecBufferDesc, _
    DWORD, _
    TimeStamp _
    ) AS SECURITY_STATUS



DECLARE FUNCTION CompleteAuthToken LIB "Secur32.dll" _
    ALIAS "CompleteAuthToken" ( _
    phContext AS CtxtHandle, _              ' Context to complete
    pToken    AS SecBufferDesc _            ' Token to complete
    ) AS SECURITY_STATUS

DECLARE FUNCTION COMPLETE_AUTH_TOKEN_FN ( _
    CtxtHandle, _
    SecBufferDesc _
    ) AS SECURITY_STATUS

DECLARE FUNCTION ImpersonateSecurityContext LIB "Secur32.dll" _
    ALIAS "ImpersonateSecurityContext" ( _
    phContext AS CtxtHandle _               ' Context to impersonate
    ) AS SECURITY_STATUS

DECLARE FUNCTION IMPERSONATE_SECURITY_CONTEXT_FN ( _
    CtxtHandle _
    ) AS SECURITY_STATUS


DECLARE FUNCTION RevertSecurityContext LIB "Secur32.dll" _
    ALIAS "RevertSecurityContext" ( _
    phContext AS CtxtHandle _               ' Context from which to re
    ) AS SECURITY_STATUS

DECLARE FUNCTION REVERT_SECURITY_CONTEXT_FN ( _
    CtxtHandle _
    ) AS SECURITY_STATUS


DECLARE FUNCTION QuerySecurityContextToken LIB "Secur32.dll" _
    ALIAS "QuerySecurityContextToken" ( _
    phContext   AS CtxtHandle, _
    Token       AS ANY _  ' void ptr ptr
    ) AS SECURITY_STATUS

DECLARE FUNCTION QUERY_SECURITY_CONTEXT_TOKEN_FN ( _
    CtxtHandle, _
    BYVAL DWORD _  ' void * *
    ) AS SECURITY_STATUS


DECLARE FUNCTION DeleteSecurityContext LIB "Secur32.dll" _
    ALIAS "DeleteSecurityContext" ( _
    phContext AS CtxtHandle _               ' Context to delete
    ) AS SECURITY_STATUS

DECLARE FUNCTION DELETE_SECURITY_CONTEXT_FN ( _
    CtxtHandle _
    ) AS SECURITY_STATUS


DECLARE FUNCTION ApplyControlToken LIB "Secur32.dll" _
    ALIAS "ApplyControlToken" ( _
    phContext AS CtxtHandle, _              ' Context to modify
    pInput    AS SecBufferDesc _            ' Input token to apply
    ) AS SECURITY_STATUS

DECLARE FUNCTION APPLY_CONTROL_TOKEN_FN ( _
    CtxtHandle, _
    SecBufferDesc _
    ) AS SECURITY_STATUS


DECLARE FUNCTION QueryContextAttributesW LIB "Secur32.dll" _
    ALIAS "QueryContextAttributesW" ( _
    phContext         AS CtxtHandle, _   ' Context to query
    BYVAL ulAttribute AS DWORD, _        ' Attribute to query
    pBuffer           AS ANY _           ' void ptr ' Buffer for attributes
    ) AS SECURITY_STATUS

DECLARE FUNCTION QUERY_CONTEXT_ATTRIBUTES_FN_W ( _
    CtxtHandle, _
    BYVAL DWORD, _
    BYVAL DWORD _  ' void *
    ) AS SECURITY_STATUS


DECLARE FUNCTION QueryContextAttributesA LIB "Secur32.dll" _
    ALIAS "QueryContextAttributesA" ( _
    phContext         AS CtxtHandle, _   ' Context to query
    BYVAL ulAttribute AS DWORD, _        ' Attribute to query
    pBuffer           AS ANY _           ' void ptr ' Buffer for attributes
    ) AS SECURITY_STATUS

DECLARE FUNCTION QUERY_CONTEXT_ATTRIBUTES_FN_A ( _
    CtxtHandle, _
    BYVAL DWORD, _
    BYVAL DWORD _  ' void *
    ) AS SECURITY_STATUS

#IF %DEF(%UNICODE)
MACRO QueryContextAttributes=QueryContextAttributesW
MACRO QUERY_CONTEXT_ATTRIBUTES_FN=QUERY_CONTEXT_ATTRIBUTES_FN_W
#ELSE
MACRO QueryContextAttributes=QueryContextAttributesA
MACRO QUERY_CONTEXT_ATTRIBUTES_FN=QUERY_CONTEXT_ATTRIBUTES_FN_A
#ENDIF ' NOT %UNICODE


'#if (OSVER(NTDDI_VERSION) > NTDDI_WIN2K)
#IF (%NTDDI_VERSION AND %OSVERSION_MASK) > %NTDDI_WIN2K

DECLARE FUNCTION SetContextAttributesW LIB "Secur32.dll" _
    ALIAS "SetContextAttributesW" ( _
    phContext         AS CtxtHandle, _   ' Context to Set
    BYVAL ulAttribute AS DWORD, _        ' Attribute to Set
    pBuffer           AS ANY, _          ' void ptr ' Buffer for attributes
    BYVAL cbBuffer    AS DWORD _         ' Size (in bytes) of Buffer
    ) AS SECURITY_STATUS

DECLARE FUNCTION SET_CONTEXT_ATTRIBUTES_FN_W ( _
    CtxtHandle, _
    BYVAL DWORD, _
    BYVAL DWORD, _  ' void ptr
    BYVAL DWORD _
    ) AS SECURITY_STATUS

#ENDIF ' Greater than w2k


DECLARE FUNCTION SetContextAttributesA LIB "Secur32.dll" _
    ALIAS "SetContextAttributesA" ( _
    phContext         AS CtxtHandle, _   ' Context to Set
    BYVAL ulAttribute AS DWORD, _        ' Attribute to Set
    pBuffer           AS ANY, _          ' void ptr ' Buffer for attributes
    BYVAL cbBuffer    AS DWORD _         ' Size (in bytes) of Buffer
    ) AS SECURITY_STATUS

DECLARE FUNCTION SET_CONTEXT_ATTRIBUTES_FN_A ( _
    CtxtHandle, _
    BYVAL DWORD, _
    BYVAL DWORD, _  ' void ptr
    BYVAL DWORD _
    ) AS SECURITY_STATUS

#IF %DEF(%UNICODE)
MACRO SetContextAttributes=SetContextAttributesW
MACRO SET_CONTEXT_ATTRIBUTES_FN=SET_CONTEXT_ATTRIBUTES_FN_W
#ELSE
MACRO SetContextAttributes=SetContextAttributesA
MACRO SET_CONTEXT_ATTRIBUTES_FN=SET_CONTEXT_ATTRIBUTES_FN_A
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION QueryCredentialsAttributesW LIB "Secur32.dll" _
    ALIAS "QueryCredentialsAttributesW" ( _
    phCredential      AS CredHandle, _   ' Credential to query
    BYVAL ulAttribute AS DWORD, _        ' Attribute to query
    pBuffer           AS ANY _           ' Buffer for attributes
    ) AS SECURITY_STATUS

DECLARE FUNCTION QUERY_CREDENTIALS_ATTRIBUTES_FN_W ( _
    CredHandle, _
    BYVAL DWORD, _
    BYVAL DWORD  _  ' void *
    ) AS SECURITY_STATUS


DECLARE FUNCTION QueryCredentialsAttributesA LIB "Secur32.dll" _
    ALIAS "QueryCredentialsAttributesA" ( _
    phCredential      AS CredHandle, _   ' Credential to query
    BYVAL ulAttribute AS DWORD, _        ' Attribute to query
    pBuffer           AS ANY _           ' void ptr  ' Buffer for attributes
    ) AS SECURITY_STATUS

DECLARE FUNCTION QUERY_CREDENTIALS_ATTRIBUTES_FN_A ( _
    CredHandle, _
    BYVAL DWORD, _
    BYVAL DWORD _
    ) AS SECURITY_STATUS

#IF %DEF(%UNICODE)
MACRO QueryCredentialsAttributes=QueryCredentialsAttributesW
MACRO QUERY_CREDENTIALS_ATTRIBUTES_FN=QUERY_CREDENTIALS_ATTRIBUTES_FN_W
#ELSE
MACRO QueryCredentialsAttributes=QueryCredentialsAttributesA
MACRO QUERY_CREDENTIALS_ATTRIBUTES_FN=QUERY_CREDENTIALS_ATTRIBUTES_FN_A
#ENDIF ' NOT %UNICODE


#IF %NTDDI_VERSION > %NTDDI_WS03

DECLARE FUNCTION SetCredentialsAttributesW LIB "Secur32.dll" _
    ALIAS "SetCredentialsAttributesW" ( _
    phCredential      AS CredHandle, _   ' Credential to Set
    BYVAL ulAttribute AS DWORD, _        ' Attribute to Set
    pBuffer           AS ANY, _          ' void ptr ' Buffer for attributes
    BYVAL cbBuffer    AS DWORD _         ' Size (in bytes) of Buffer
    ) AS SECURITY_STATUS

DECLARE FUNCTION SET_CREDENTIALS_ATTRIBUTES_FN_W ( _
    CredHandle, _
    BYVAL DWORD, _
    BYVAL DWORD, _  ' void ptr
    BYVAL DWORD _
    ) AS SECURITY_STATUS

#ENDIF ' For W2k3SP1 and greater


DECLARE FUNCTION SetCredentialsAttributesA LIB "Secur32.dll" _
    ALIAS "SetCredentialsAttributesA" ( _
    phCredential      AS CredHandle, _   ' Credential to Set
    BYVAL ulAttribute AS DWORD, _        ' Attribute to Set
    pBuffer           AS ANY, _          ' void *, _ ' Buffer for attributes
    BYVAL cbBuffer    AS DWORD _         ' Size (in bytes) of Buffer
    ) AS SECURITY_STATUS

DECLARE FUNCTION SET_CREDENTIALS_ATTRIBUTES_FN_A ( _
    CredHandle, _
    BYVAL DWORD, _
    BYVAL DWORD, _  ' void *,
    BYVAL DWORD _
    ) AS SECURITY_STATUS

#IF %DEF(%UNICODE)
MACRO SetCredentialsAttributes=SetCredentialsAttributesW
MACRO SET_CREDENTIALS_ATTRIBUTES_FN=SET_CREDENTIALS_ATTRIBUTES_FN_W
#ELSE
MACRO SetCredentialsAttributes=SetCredentialsAttributesA
MACRO SET_CREDENTIALS_ATTRIBUTES_FN=SET_CREDENTIALS_ATTRIBUTES_FN_A
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION FreeContextBuffer LIB "Secur32.dll" _
    ALIAS "FreeContextBuffer" ( _
    pvContextBuffer AS ANY _  ' void ptr ' buffer to free
    ) AS SECURITY_STATUS

DECLARE FUNCTION FREE_CONTEXT_BUFFER_FN ( _
    BYVAL DWORD _  ' VOID PTR
    ) AS SECURITY_STATUS


'''''''''''''''''''''''''''''''''
''
''    Message Support API
''
'''''''''''''''''''''''''''''''''

DECLARE FUNCTION MakeSignature LIB "Secur32.dll" _
    ALIAS "MakeSignature" ( _
    phContext          AS CtxtHandle, _     ' Context to use
    BYVAL fQOP         AS DWORD, _          ' Quality of Protection
    pMessage           AS SecBufferDesc, _  ' Message to sign
    BYVAL MessageSeqNo AS DWORD _           ' Message Sequence Num.
    ) AS SECURITY_STATUS

DECLARE FUNCTION MAKE_SIGNATURE_FN ( _
    CtxtHandle, _
    BYVAL DWORD, _
    SecBufferDesc, _
    BYVAL DWORD _
    ) AS SECURITY_STATUS


DECLARE FUNCTION VerifySignature LIB "Secur32.dll" _
    ALIAS "VerifySignature" ( _
    phContext          AS CtxtHandle, _     ' Context to use
    pMessage           AS SecBufferDesc, _  ' Message to verify
    BYVAL MessageSeqNo AS DWORD, _          ' Sequence Num.
    pfQOP              AS DWORD _           ' QOP used
    ) AS SECURITY_STATUS

DECLARE FUNCTION VERIFY_SIGNATURE_FN ( _
    CtxtHandle, _
    SecBufferDesc, _
    BYVAL DWORD, _
    DWORD _
    ) AS SECURITY_STATUS

' This only exists win Win2k3 and Greater
%SECQOP_WRAP_NO_ENCRYPT    = &H80000001???
%SECQOP_WRAP_OOB_DATA      = &H40000000

DECLARE FUNCTION EncryptMessage LIB "Secur32.dll" _
    ALIAS "EncryptMessage" ( _
    phContext          AS CtxtHandle, _
    BYVAL fQOP         AS DWORD, _
    pMessage           AS SecBufferDesc, _
    BYVAL MessageSeqNo AS DWORD _
    ) AS SECURITY_STATUS

DECLARE FUNCTION ENCRYPT_MESSAGE_FN ( _
    CtxtHandle, _
    BYVAL DWORD, _
    SecBufferDesc, _
    BYVAL DWORD _
    ) AS SECURITY_STATUS


DECLARE FUNCTION DecryptMessage LIB "Secur32.dll" _
    ALIAS "DecryptMessage" ( _
    phContext          AS CtxtHandle, _
    pMessage           AS SecBufferDesc, _
    BYVAL MessageSeqNo AS DWORD, _
    pfQOP              AS DWORD _
    ) AS SECURITY_STATUS


DECLARE FUNCTION DECRYPT_MESSAGE_FN ( _
    CtxtHandle, _
    SecBufferDesc, _
    BYVAL DWORD, _
    DWORD _
    ) AS SECURITY_STATUS


'''''''''''''''''''''''''''''''''''''
''
''    Misc.
''
'''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION EnumerateSecurityPackagesW LIB "Secur32.dll" _
    ALIAS "EnumerateSecurityPackagesW" ( _
    BYVAL pcPackages    AS DWORD PTR, _  ' Receives num. packages
    BYVAL ppPackageInfo AS DWORD _       ' SecPkgInfoW PTR PTR ' Receives array of info
    ) AS SECURITY_STATUS

DECLARE FUNCTION ENUMERATE_SECURITY_PACKAGES_FN_W ( _
    DWORD, _
    BYVAL DWORD _   ' SecPkgInfoW PTR PTR
    ) AS SECURITY_STATUS


DECLARE FUNCTION EnumerateSecurityPackagesA LIB "Secur32.dll" _
    ALIAS "EnumerateSecurityPackagesA" ( _
    BYVAL pcPackages    AS DWORD PTR, _   ' Receives num. packages
    BYVAL ppPackageInfo AS DWORD _        ' SecPkgInfoA PTR PTR  ' Receives array of info
    ) AS SECURITY_STATUS

DECLARE FUNCTION ENUMERATE_SECURITY_PACKAGES_FN_A ( _
    DWORD, _
    BYVAL DWORD _  ' SecPkgInfoA PTR PTR
    ) AS SECURITY_STATUS

#IF %DEF(%UNICODE)
MACRO EnumerateSecurityPackages=EnumerateSecurityPackagesW
MACRO ENUMERATE_SECURITY_PACKAGES_FN=ENUMERATE_SECURITY_PACKAGES_FN_W
#ELSE
MACRO EnumerateSecurityPackages=EnumerateSecurityPackagesA
MACRO ENUMERATE_SECURITY_PACKAGES_FN=ENUMERATE_SECURITY_PACKAGES_FN_A
#ENDIF ' NOT %UNICODE


#IF %ISSP_MODE = 0
DECLARE FUNCTION QuerySecurityPackageInfoW LIB "Secur32.dll" _
    ALIAS "QuerySecurityPackageInfoW" ( _
    pPackageName        AS SECURITY_STRING, _
    BYVAL ppPackageInfo AS DWORD _      ' SecPkgInfoW PTR PTR ' Receives package info
    ) AS SECURITY_STATUS
#ELSE
DECLARE FUNCTION QuerySecurityPackageInfoW LIB "Secur32.dll" _
    ALIAS "QuerySecurityPackageInfoW" ( _
    pszPackageName      AS WSTRINGZ, _  ' Name of package
    BYVAL ppPackageInfo AS DWORD _      ' SecPkgInfoW PTR PTR ' Receives package info
    ) AS SECURITY_STATUS
#ENDIF

#IF %ISSP_MODE = 0
DECLARE FUNCTION QUERY_SECURITY_PACKAGE_INFO_FN_W ( _
    SECURITY_STRING, _
    BYVAL DWORD _  ' SecPkgInfoW ptr ptr
    ) AS SECURITY_STATUS
#ELSE
DECLARE FUNCTION QUERY_SECURITY_PACKAGE_INFO_FN_W ( _
    WSTRINGZ, _
    BYVAL DWORD _  ' SecPkgInfoW ptr ptr
    ) AS SECURITY_STATUS
#ENDIF

DECLARE FUNCTION QuerySecurityPackageInfoA LIB "Secur32.dll" _
    ALIAS "QuerySecurityPackageInfoA" ( _
    pszPackageName      AS ASCIIZ, _  ' Name of package
    BYVAL ppPackageInfo AS DWORD _    ' SecPkgInfoA PTR PTR ' Receives package info
    ) AS SECURITY_STATUS

DECLARE FUNCTION QUERY_SECURITY_PACKAGE_INFO_FN_A ( _
    ASCIIZ, _
    BYVAL DWORD _  ' SecPkgInfoA ptr ptr
    ) AS SECURITY_STATUS

#IF %DEF(%UNICODE)
MACRO QuerySecurityPackageInfo=QuerySecurityPackageInfoW
MACRO QUERY_SECURITY_PACKAGE_INFO_FN=QUERY_SECURITY_PACKAGE_INFO_FN_W
#ELSE
MACRO QuerySecurityPackageInfo=QuerySecurityPackageInfoA
MACRO QUERY_SECURITY_PACKAGE_INFO_FN=QUERY_SECURITY_PACKAGE_INFO_FN_A
#ENDIF ' NOT %UNICODE


MACRO SecDelegationType_enum=LONG
ENUM SecDelegationType SINGULAR
    SecFull
    SecService
    SecTree
    SecDirectory
    SecObject
END ENUM

#IF %ISSP_MODE = 0
DECLARE FUNCTION DelegateSecurityContext LIB "Secur32.dll" _
    ALIAS "DelegateSecurityContext" ( _
    phContext            AS CtxtHandle, _        ' IN Active context to delegate
    pTarget              AS SECURITY_STRING, _   ' IN Target path
    BYVAL DelegationType AS SecDelegationType_enum, _  ' IN Type of delegation
    pExpiry              AS TimeStamp, _      ' IN time limit
    pPackageParameters   AS SecBuffer, _      ' IN package specific
    pOutput              AS SecBufferDesc _   ' OUT Token for applycontroltoken.
    ) AS SECURITY_STATUS
#ELSE
DECLARE FUNCTION DelegateSecurityContext LIB "Secur32.dll" _
    ALIAS "DelegateSecurityContext" ( _
    phContext            AS CtxtHandle, _        ' IN Active context to delegate
    pszTarget            AS ASCIIZ, _
    BYVAL DelegationType AS SecDelegationType_enum, _  ' IN Type of delegation
    pExpiry              AS TimeStamp, _      ' IN time limit
    pPackageParameters   AS SecBuffer, _      ' IN package specific
    pOutput              AS SecBufferDesc _   ' OUT Token for applycontroltoken.
    ) AS SECURITY_STATUS
#ENDIF


'''''''''''''''''''''''''''''''''''''
''
''    Proxies
''
'''''''''''''''''''''''''''''''''''''


'
' Proxies are only available on NT platforms
'


'''''''''''''''''''''''''''''''''''''
''
''    Context export/import
''
'''''''''''''''''''''''''''''''''''''


DECLARE FUNCTION ExportSecurityContext LIB "Secur32.dll" _
    ALIAS "ExportSecurityContext" ( _
    phContext      AS CtxtHandle, _  ' (in) context to export
    BYVAL fFlags   AS DWORD, _       ' (in) option flags
    pPackedContext AS SecBuffer, _   ' (out) marshalled context
    pToken         AS ANY _          ' void ptr ptr ' (out, optional) token handle for impersonation
    ) AS SECURITY_STATUS

DECLARE FUNCTION EXPORT_SECURITY_CONTEXT_FN ( _
    CtxtHandle, _
    BYVAL DWORD, _
    SecBuffer, _
    BYVAL DWORD _  ' void * *
    ) AS SECURITY_STATUS

#IF %ISSP_MODE = 0
DECLARE FUNCTION ImportSecurityContextW LIB "Secur32.dll" _
    ALIAS "ImportSecurityContextW" ( _
    pszPackage     AS SECURITY_STRING, _
    pPackedContext AS SecBuffer, _  ' (in) marshalled context
    Token          AS ANY, _        ' void *, ' (in, optional) handle to token for context
    phContext AS CtxtHandle _       ' (out) new context handle
    ) AS SECURITY_STATUS
#ELSE
DECLARE FUNCTION ImportSecurityContextW LIB "Secur32.dll" _
    ALIAS "ImportSecurityContextW" ( _
    pszPackage     AS WSTRINGZ, _
    pPackedContext AS SecBuffer, _  ' (in) marshalled context
    Token          AS ANY, _        ' void *, ' (in, optional) handle to token for context
    phContext AS CtxtHandle _       ' (out) new context handle
    ) AS SECURITY_STATUS
#ENDIF

#IF %ISSP_MODE = 0
DECLARE FUNCTION IMPORT_SECURITY_CONTEXT_FN_W ( _
    SECURITY_STRING, _
    SecBuffer, _
    BYVAL DWORD, _  ' VOID ptr
    CtxtHandle _
    ) AS SECURITY_STATUS
#ELSE
DECLARE FUNCTION IMPORT_SECURITY_CONTEXT_FN_W ( _
    WSTRINGZ, _
    SecBuffer, _
    BYVAL DWORD, _  ' VOID ptr
    CtxtHandle _
    ) AS SECURITY_STATUS
#ENDIF

DECLARE FUNCTION ImportSecurityContextA LIB "Secur32.dll" _
    ALIAS "ImportSecurityContextA" ( _
    pszPackage     AS ASCIIZ, _
    pPackedContext AS SecBuffer, _  ' (in) marshalled context
    Token          AS ANY, _        ' void ptr ' (in, optional) handle to token for context
    phContext      AS CtxtHandle _  ' (out) new context handle
    ) AS SECURITY_STATUS

DECLARE FUNCTION IMPORT_SECURITY_CONTEXT_FN_A ( _
    ASCIIZ, _
    SecBuffer, _
    BYVAL DWORD, _  ' void ptr
    CtxtHandle _
    ) AS SECURITY_STATUS

#IF %DEF(%UNICODE)
MACRO ImportSecurityContext=ImportSecurityContextW
MACRO IMPORT_SECURITY_CONTEXT_FN=IMPORT_SECURITY_CONTEXT_FN_W
#ELSE
MACRO ImportSecurityContext=ImportSecurityContextA
MACRO IMPORT_SECURITY_CONTEXT_FN=IMPORT_SECURITY_CONTEXT_FN_A
#ENDIF ' NOT %UNICODE


#IF %ISSP_MODE = 0
DECLARE FUNCTION SecMakeSPN LIB "Secur32.dll" _
    ALIAS "SecMakeSPN" ( _
    ServiceClass       AS UNICODE_STRING, _
    ServiceName        AS UNICODE_STRING, _
    InstanceName       AS UNICODE_STRING, _
    BYVAL InstancePort AS WORD, _
    Referrer           AS UNICODE_STRING, _
    Spn                AS UNICODE_STRING, _
    Length             AS DWORD, _
    BYVAL Allocate     AS BYTE _    ' BOOLEAN
    ) AS SECURITY_STATUS

'#if OSVER(NTDDI_VERSION) > NTDD_WIN2K  ' [evident typo]
#IF (%NTDDI_VERSION AND %OSVERSION_MASK) > %NTDDI_WIN2K

DECLARE FUNCTION SecMakeSPNEx LIB "Secur32.dll" _
    ALIAS "SecMakeSPNEx" ( _
    ServiceClass       AS UNICODE_STRING, _
    ServiceName        AS UNICODE_STRING, _
    InstanceName       AS UNICODE_STRING, _
    BYVAL InstancePort AS WORD, _
    Referrer           AS UNICODE_STRING, _
    TargetInfo         AS UNICODE_STRING, _
    Spn                AS UNICODE_STRING, _
    Length             AS DWORD, _
    BYVAL Allocate     AS BYTE _    ' BOOLEAN
    ) AS SECURITY_STATUS

'#if OSVER(NTDDI_VERSION) > NTDDI_WS03
#IF (%NTDDI_VERSION AND %OSVERSION_MASK) > %NTDDI_WS03

DECLARE FUNCTION SecMakeSPNEx2 LIB "Secur32.dll" _
    ALIAS "SecMakeSPNEx2" ( _
    ServiceClass       AS UNICODE_STRING, _
    ServiceName        AS UNICODE_STRING, _
    InstanceName       AS UNICODE_STRING, _
    BYVAL InstancePort AS WORD, _
    Referrer           AS UNICODE_STRING, _
    InTargetInfo       AS UNICODE_STRING, _
    Spn                AS UNICODE_STRING, _
    TotalSize          AS DWORD, _
    BYVAL Allocate     AS BYTE, _  ' BOOLEAN
    BYVAL IsTargetInfoMarshaled AS BYTE _  ' BOOLEAN
    ) AS SECURITY_STATUS

#ENDIF ' Windows Vista and greater

DECLARE FUNCTION SecLookupAccountSid LIB "Secur32.dll" _
    ALIAS "SecLookupAccountSid" ( _
    pSid         AS SID, _
    NameSize     AS DWORD, _
    NameBuffer   AS UNICODE_STRING, _
    DomainSize   AS DWORD, _
    DomainBuffer AS UNICODE_STRING, _
    NameUse      AS SID_NAME_USE _
    ) AS SECURITY_STATUS

DECLARE FUNCTION SecLookupAccountName LIB "Secur32.dll" _
    ALIAS "SecLookupAccountName" ( _
    Name             AS UNICODE_STRING, _
    SidSize          AS DWORD, _
    pSid             AS SID, _
    NameUse          AS SID_NAME_USE, _
    DomainSize       AS DWORD, _
    ReferencedDomain AS UNICODE_STRING _
    ) AS SECURITY_STATUS

#ENDIF ' Greater than W2k

'#if OSVER(NTDDI_VERSION) > NTDDI_WINXP
#IF (%NTDDI_VERSION AND %OSVERSION_MASK) > %NTDDI_WINXP

DECLARE FUNCTION SecLookupWellKnownSid LIB "Secur32.dll" _
    ALIAS "SecLookupWellKnownSid" ( _
    BYVAL SidType       AS WELL_KNOWN_SID_TYPE, _
    pSid                AS SID, _
    BYVAL SidBufferSize AS DWORD, _
    SidSize             AS DWORD _
    ) AS SECURITY_STATUS

#ENDIF ' Greater than XP


#ENDIF


'''''''''''''''''''''''''''''''''''''''
''
''  Fast access for RPC:
''
'''''''''''''''''''''''''''''''''''''''

$SECURITY_ENTRYPOINT_ANSIW = "InitSecurityInterfaceW"
$SECURITY_ENTRYPOINT_ANSIA = "InitSecurityInterfaceA"
$SECURITY_ENTRYPOINTW = "InitSecurityInterfaceW"
$SECURITY_ENTRYPOINTA = "InitSecurityInterfaceA"
$SECURITY_ENTRYPOINT16 = "INITSECURITYINTERFACEA"

$$SECURITY_ENTRYPOINT_ANSIW = "InitSecurityInterfaceW"$$
$$SECURITY_ENTRYPOINT_ANSIA = "InitSecurityInterfaceA"$$
$$SECURITY_ENTRYPOINTW = "InitSecurityInterfaceW"$$
$$SECURITY_ENTRYPOINTA = "InitSecurityInterfaceA"$$
$$SECURITY_ENTRYPOINT16 = "INITSECURITYINTERFACEA"$$

#IF %DEF(%SECURITY_WIN32)
#IF %DEF(%UNICODE)
$$SECURITY_ENTRYPOINT = $$SECURITY_ENTRYPOINTW
$$SECURITY_ENTRYPOINT_ANSI = $$SECURITY_ENTRYPOINT_ANSIW
#ELSE ' UNICODE
$SECURITY_ENTRYPOINT = $SECURITY_ENTRYPOINTA
$SECURITY_ENTRYPOINT_ANSI = $SECURITY_ENTRYPOINT_ANSIA
#ENDIF ' UNICODE
#ELSE ' SECURITY_WIN32
$SECURITY_ENTRYPOINT = $SECURITY_ENTRYPOINT16
$SECURITY_ENTRYPOINT_ANSI = $SECURITY_ENTRYPOINT16
#ENDIF ' SECURITY_WIN32


MACRO FreeCredentialHandle=FreeCredentialsHandle

TYPE SecurityFunctionTableW
    dwVersion                   AS DWORD
    EnumerateSecurityPackagesW  AS DWORD  ' ENUMERATE_SECURITY_PACKAGES_FN_W
    QueryCredentialsAttributesW AS DWORD  ' QUERY_CREDENTIALS_ATTRIBUTES_FN_W
    AcquireCredentialsHandleW   AS DWORD  ' ACQUIRE_CREDENTIALS_HANDLE_FN_W
    FreeCredentialsHandle       AS DWORD  ' FREE_CREDENTIALS_HANDLE_FN
    Reserved2                   AS DWORD  ' void ptr
    InitializeSecurityContextW  AS DWORD  ' INITIALIZE_SECURITY_CONTEXT_FN_W
    AcceptSecurityContext       AS DWORD  ' ACCEPT_SECURITY_CONTEXT_FN
    CompleteAuthToken           AS DWORD  ' COMPLETE_AUTH_TOKEN_FN
    DeleteSecurityContext       AS DWORD  ' DELETE_SECURITY_CONTEXT_FN
    ApplyControlToken           AS DWORD  ' APPLY_CONTROL_TOKEN_FN
    QueryContextAttributesW     AS DWORD  ' QUERY_CONTEXT_ATTRIBUTES_FN_W
    ImpersonateSecurityContext  AS DWORD  ' IMPERSONATE_SECURITY_CONTEXT_FN
    RevertSecurityContext       AS DWORD  ' REVERT_SECURITY_CONTEXT_FN
    MakeSignature               AS DWORD  ' MAKE_SIGNATURE_FN
    VerifySignature             AS DWORD  ' VERIFY_SIGNATURE_FN
    FreeContextBuffer           AS DWORD  ' FREE_CONTEXT_BUFFER_FN
    QuerySecurityPackageInfoW   AS DWORD  ' QUERY_SECURITY_PACKAGE_INFO_FN_W
    Reserved3                   AS DWORD  ' void *
    Reserved4                   AS DWORD  ' void *
    ExportSecurityContext       AS DWORD  ' EXPORT_SECURITY_CONTEXT_FN
    ImportSecurityContextW      AS DWORD  ' IMPORT_SECURITY_CONTEXT_FN_W
    AddCredentialsW             AS DWORD  ' ADD_CREDENTIALS_FN_W
    Reserved8                   AS DWORD  ' void *
    QuerySecurityContextToken   AS DWORD  ' QUERY_SECURITY_CONTEXT_TOKEN_FN
    EncryptMessage              AS DWORD  ' ENCRYPT_MESSAGE_FN
    DecryptMessage              AS DWORD  ' DECRYPT_MESSAGE_FN
'#if OSVER(NTDDI_VERSION) > NTDDI_WIN2K
#IF (%NTDDI_VERSION AND %OSVERSION_MASK) > %NTDDI_WIN2K

    ' Fields below this are available in OSes after w2k
    SetContextAttributesW       AS DWORD  ' SET_CONTEXT_ATTRIBUTES_FN_W
#ENDIF ' greater thean 2K

#IF %NTDDI_VERSION > %NTDDI_WS03SP1
    ' Fields below this are available in OSes after W2k3SP1
    SetCredentialsAttributesW   AS DWORD  ' SET_CREDENTIALS_ATTRIBUTES_FN_W
#ENDIF
#IF %ISSP_MODE <> 0
    ChangeAccountPasswordW      AS DWORD  ' CHANGE_PASSWORD_FN_W
#ELSE
    Reserved9                   AS DWORD  ' void *
#ENDIF
END TYPE


TYPE SecurityFunctionTableA
    dwVersion                   AS DWORD
    EnumerateSecurityPackagesA  AS DWORD  ' ENUMERATE_SECURITY_PACKAGES_FN_A
    QueryCredentialsAttributesA AS DWORD  ' QUERY_CREDENTIALS_ATTRIBUTES_FN_A
    AcquireCredentialsHandleA   AS DWORD  ' ACQUIRE_CREDENTIALS_HANDLE_FN_A
    FreeCredentialHandle        AS DWORD  ' FREE_CREDENTIALS_HANDLE_FN
    Reserved2                   AS DWORD  ' void *
    InitializeSecurityContextA  AS DWORD  ' INITIALIZE_SECURITY_CONTEXT_FN_A
    AcceptSecurityContext       AS DWORD  ' ACCEPT_SECURITY_CONTEXT_FN
    CompleteAuthToken           AS DWORD  ' COMPLETE_AUTH_TOKEN_FN
    DeleteSecurityContext       AS DWORD  ' DELETE_SECURITY_CONTEXT_FN
    ApplyControlToken           AS DWORD  ' APPLY_CONTROL_TOKEN_FN
    QueryContextAttributesA     AS DWORD  ' QUERY_CONTEXT_ATTRIBUTES_FN_A
    ImpersonateSecurityContext  AS DWORD  ' IMPERSONATE_SECURITY_CONTEXT_FN
    RevertSecurityContext       AS DWORD  ' REVERT_SECURITY_CONTEXT_FN
    MakeSignature               AS DWORD  ' MAKE_SIGNATURE_FN
    VerifySignature             AS DWORD  ' VERIFY_SIGNATURE_FN
    FreeContextBuffer           AS DWORD  ' FREE_CONTEXT_BUFFER_FN
    QuerySecurityPackageInfoA   AS DWORD  ' QUERY_SECURITY_PACKAGE_INFO_FN_A
    Reserved3                   AS DWORD  ' void *
    Reserved4                   AS DWORD  ' void *
    ExportSecurityContext       AS DWORD  ' EXPORT_SECURITY_CONTEXT_FN
    ImportSecurityContextA      AS DWORD  ' IMPORT_SECURITY_CONTEXT_FN_A
    AddCredentialsA             AS DWORD  ' ADD_CREDENTIALS_FN_A
    Reserved8                   AS DWORD  ' void *
    QuerySecurityContextToken   AS DWORD  ' QUERY_SECURITY_CONTEXT_TOKEN_FN
    EncryptMessage              AS DWORD  ' ENCRYPT_MESSAGE_FN
    DecryptMessage              AS DWORD  ' DECRYPT_MESSAGE_FN
    SetContextAttributesA       AS DWORD  ' SET_CONTEXT_ATTRIBUTES_FN_A
    SetCredentialsAttributesA   AS DWORD  ' SET_CREDENTIALS_ATTRIBUTES_FN_A
#IF %ISSP_MODE <> 0
    ChangeAccountPasswordA      AS DWORD  ' CHANGE_PASSWORD_FN_A
#ELSE
    Reserved9                   AS DWORD  ' void *
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
TYPE SecurityFunctionTable
    SecurityFunctionTableW
END TYPE
'#define PSecurityFunctionTable PSecurityFunctionTableW
#ELSE
TYPE SecurityFunctionTable
    SecurityFunctionTableA
END TYPE
'#define PSecurityFunctionTable PSecurityFunctionTableA
#ENDIF ' NOT %UNICODE

%SECURITY = 1

' Function table has all routines through DecryptMessage
%SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION   = 1

' Function table has all routines through SetContextAttributes
%SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION_2 = 2

' Function table has all routines through SetCredentialsAttributes
%SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION_3 = 3

' Function table has all routines through ChangeAccountPassword
%SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION_4 = 4


DECLARE FUNCTION InitSecurityInterfaceA LIB "Secur32.dll" _
    ALIAS "InitSecurityInterfaceA" ( _
    ) AS DWORD  ' SecurityFunctionTableA PTR

DECLARE FUNCTION INIT_SECURITY_INTERFACE_A ( _
    ) AS DWORD  ' SecurityFunctionTableA PTR


DECLARE FUNCTION InitSecurityInterfaceW LIB "Secur32.dll" _
    ALIAS "InitSecurityInterfaceW" ( _
    ) AS DWORD  ' SecurityFunctionTableW PTR

DECLARE FUNCTION INIT_SECURITY_INTERFACE_W ( _
    ) AS DWORD  ' SecurityFunctionTableW PTR


#IF %DEF(%UNICODE)
MACRO InitSecurityInterface=InitSecurityInterfaceW
MACRO INIT_SECURITY_INTERFACE=INIT_SECURITY_INTERFACE_W
#ELSE
MACRO InitSecurityInterface=InitSecurityInterfaceA
MACRO INIT_SECURITY_INTERFACE=INIT_SECURITY_INTERFACE_A
#ENDIF ' NOT %UNICODE


#IF %DEF(%SECURITY_WIN32)

'
' SASL Profile Support
'


DECLARE FUNCTION SaslEnumerateProfilesA LIB "Secur32.dll" _
    ALIAS "SaslEnumerateProfilesA" ( _
    ProfileList  AS ANY, _  ' asciiz ptr ptr
    ProfileCount AS DWORD _
    ) AS SECURITY_STATUS

DECLARE FUNCTION SaslEnumerateProfilesW LIB "Secur32.dll" _
    ALIAS "SaslEnumerateProfilesW" ( _
    ProfileList  AS ANY, _  ' wstringz ptr ptr
    ProfileCount AS DWORD _
    ) AS SECURITY_STATUS

#IF %DEF(%UNICODE)
MACRO SaslEnumerateProfiles=SaslEnumerateProfilesW
#ELSE
MACRO SaslEnumerateProfiles=SaslEnumerateProfilesA
#ENDIF


DECLARE FUNCTION SaslGetProfilePackageA LIB "Secur32.dll" _
    ALIAS "SaslGetProfilePackageA" ( _
    ProfileName AS ASCIIZ, _
    PackageInfo AS ANY _  ' SecPkgInfoA ptr ptr
    ) AS SECURITY_STATUS


DECLARE FUNCTION SaslGetProfilePackageW LIB "Secur32.dll" _
    ALIAS "SaslGetProfilePackageW" ( _
    ProfileName AS WSTRINGZ, _
    PackageInfo AS ANY _  ' SecPkgInfoW ptr ptr
    ) AS SECURITY_STATUS

#IF %DEF(%UNICODE)
MACRO SaslGetProfilePackage=SaslGetProfilePackageW
#ELSE
MACRO SaslGetProfilePackage=SaslGetProfilePackageA
#ENDIF

DECLARE FUNCTION SaslIdentifyPackageA LIB "Secur32.dll" _
    ALIAS "SaslIdentifyPackageA" ( _
    pInput      AS SecBufferDesc, _
    PackageInfo AS ANY _  ' SecPkgInfoA ptr ptr
    ) AS SECURITY_STATUS

DECLARE FUNCTION SaslIdentifyPackageW LIB "Secur32.dll" _
    ALIAS "SaslIdentifyPackageW" ( _
    pInput      AS SecBufferDesc, _
    PackageInfo AS ANY _  ' SecPkgInfoW ptr ptr
    ) AS SECURITY_STATUS

#IF %DEF(%UNICODE)
MACRO SaslIdentifyPackage=SaslIdentifyPackageW
#ELSE
MACRO SaslIdentifyPackage=SaslIdentifyPackageA
#ENDIF

DECLARE FUNCTION SaslInitializeSecurityContextW LIB "Secur32.dll" _
    ALIAS "SaslInitializeSecurityContextW" ( _
    phCredential        AS CredHandle, _     ' Cred to base context
    phContext           AS CtxtHandle, _     ' Existing context (OPT)
    pszTargetName       AS WSTRINGZ, _       ' Name of target
    BYVAL fContextReq   AS DWORD, _          ' Context Requirements
    BYVAL Reserved1     AS DWORD, _          ' Reserved, MBZ
    BYVAL TargetDataRep AS DWORD, _          ' Data rep of target
    pInput              AS SecBufferDesc, _  ' Input Buffers
    BYVAL Reserved2     AS DWORD, _          ' Reserved, MBZ
    phNewContext        AS CtxtHandle, _     ' (out) New Context handle
    pOutput             AS SecBufferDesc, _  ' (inout) Output Buffers
    pfContextAttr       AS DWORD, _          ' (out) Context attrs
    ptsExpiry           AS TimeStamp _       ' (out) Life span (OPT)
    ) AS SECURITY_STATUS

DECLARE FUNCTION SaslInitializeSecurityContextA LIB "Secur32.dll" _
    ALIAS "SaslInitializeSecurityContextA" ( _
    phCredential        AS CredHandle, _     ' Cred to base context
    phContext           AS CtxtHandle, _     ' Existing context (OPT)
    pszTargetName       AS ASCIIZ, _         ' Name of target
    BYVAL fContextReq   AS DWORD, _          ' Context Requirements
    BYVAL Reserved1     AS DWORD, _          ' Reserved, MBZ
    BYVAL TargetDataRep AS DWORD, _          ' Data rep of target
    pInput              AS SecBufferDesc, _  ' Input Buffers
    BYVAL Reserved2     AS DWORD, _          ' Reserved, MBZ
    phNewContext        AS CtxtHandle, _     ' (out) New Context handle
    pOutput             AS SecBufferDesc, _  ' (inout) Output Buffers
    pfContextAttr       AS DWORD, _          ' (out) Context attrs
    ptsExpiry           AS TimeStamp _       ' (out) Life span (OPT)
    ) AS SECURITY_STATUS

#IF %DEF(%UNICODE)
MACRO SaslInitializeSecurityContext=SaslInitializeSecurityContextW
#ELSE
MACRO SaslInitializeSecurityContext=SaslInitializeSecurityContextA
#ENDIF


DECLARE FUNCTION SaslAcceptSecurityContext LIB "Secur32.dll" _
    ALIAS "SaslAcceptSecurityContext" ( _
    phCredential        AS CredHandle, _     ' Cred to base context
    phContext           AS CtxtHandle, _     ' Existing context (OPT)
    pInput              AS SecBufferDesc, _  ' Input buffer
    BYVAL fContextReq   AS DWORD, _          ' Context Requirements
    BYVAL TargetDataRep AS DWORD, _          ' Target Data Rep
    phNewContext        AS CtxtHandle, _     ' (out) New context handle
    pOutput             AS SecBufferDesc, _  ' (inout) Output buffers
    pfContextAttr       AS DWORD, _          ' (out) Context attributes
    ptsExpiry           AS TimeStamp _       ' (out) Life span (OPT)
    ) AS SECURITY_STATUS


%SASL_OPTION_SEND_SIZE        = 1  ' Maximum size to send to peer
%SASL_OPTION_RECV_SIZE        = 2  ' Maximum size willing to receive
%SASL_OPTION_AUTHZ_STRING     = 3  ' Authorization string
%SASL_OPTION_AUTHZ_PROCESSING = 4  ' Authorization string processing

MACRO SASL_AUTHZID_STATE_enum=LONG
ENUM SASL_AUTHZID_STATE SINGULAR
    Sasl_AuthZIDForbidden    ' allow no AuthZID strings to be specified - error out (default)
    Sasl_AuthZIDProcessed    ' AuthZID Strings processed by Application or SSP
END ENUM

DECLARE FUNCTION SaslSetContextOption LIB "Secur32.dll" _
    ALIAS "SaslSetContextOption" ( _
    ContextHandle AS CtxtHandle, _
    BYVAL Option  AS DWORD, _
    Value         AS ANY, _  ' VOID PTR
    BYVAL Size    AS DWORD _
    ) AS SECURITY_STATUS


DECLARE FUNCTION SaslGetContextOption LIB "Secur32.dll" _
    ALIAS "SaslGetContextOption" ( _
    ContextHandle AS CtxtHandle, _
    BYVAL Option  AS DWORD, _
    Value         AS ANY, _  ' VOID ptr
    BYVAL Size    AS DWORD, _
    Needed        AS DWORD _
    ) AS SECURITY_STATUS

#ENDIF

'
' This is the legacy credentials structure.
' The EX version below is preferred.


#IF NOT %DEF(%AUTH_IDENTITY_EX2_DEFINED)
%AUTH_IDENTITY_EX2_DEFINED = 1

%SEC_WINNT_AUTH_IDENTITY_VERSION_2 = &H201

TYPE SEC_WINNT_AUTH_IDENTITY_EX2 DWORD FILL
   Version                 AS DWORD  ' contains SEC_WINNT_AUTH_IDENTITY_VERSION_2
   cbHeaderLength          AS WORD
   cbStructureLength       AS DWORD
   UserOffset              AS DWORD  ' Non-NULL terminated string, unicode only
   UserLength              AS WORD   ' # of bytes (NOT WCHARs), not including NULL.
   DomainOffset            AS DWORD  ' Non-NULL terminated string, unicode only
   DomainLength            AS WORD   ' # of bytes (NOT WCHARs), not including NULL.
   PackedCredentialsOffset AS DWORD  ' Non-NULL terminated string, unicode only
   PackedCredentialsLength AS WORD   ' # of bytes (NOT WCHARs), not including NULL.
   Flags                   AS DWORD
   PackageListOffset       AS DWORD  ' Non-NULL terminated string, unicode only
   PackageListLength       AS WORD
END TYPE

#ENDIF ' %AUTH_IDENTITY_EX2_DEFINED

#IF NOT %DEF(%AUTH_IDENTITY_DEFINED)
%AUTH_IDENTITY_DEFINED = 1

'
' This was not defined in NTIFS.h for windows 2000 however
' this struct has always been there and are safe to use
' in windows 2000 and above.
'

%SEC_WINNT_AUTH_IDENTITY_ANSI    = &H1
%SEC_WINNT_AUTH_IDENTITY_UNICODE = &H2

TYPE SEC_WINNT_AUTH_IDENTITY_W
    User           AS WORD PTR  '  Non-NULL terminated string.
    UserLength     AS DWORD     '  # of characters (NOT bytes), not including NULL.
    Domain         AS WORD PTR  '  Non-NULL terminated string.
    DomainLength   AS DWORD     '  # of characters (NOT bytes), not including NULL.
    Password       AS WORD PTR  '  Non-NULL terminated string.
    PasswordLength AS DWORD     '  # of characters (NOT bytes), not including NULL.
    Flags          AS DWORD
END TYPE


%AUTH_IDENTITY_A_DEFINED = 1

TYPE SEC_WINNT_AUTH_IDENTITY_A
    User           AS BYTE PTR  '  Non-NULL terminated string.
    UserLength     AS DWORD     '  # of characters (NOT bytes), not including NULL.
    Domain         AS BYTE PTR  '  Non-NULL terminated string.
    DomainLength   AS DWORD     '  # of characters (NOT bytes), not including NULL.
    Password       AS BYTE PTR  '  Non-NULL terminated string.
    PasswordLength AS DWORD     '  # of characters (NOT bytes), not including NULL.
    Flags          AS DWORD
END TYPE


#IF %DEF(%UNICODE)
TYPE SEC_WINNT_AUTH_IDENTITY
    SEC_WINNT_AUTH_IDENTITY_W
END TYPE
'#define PSEC_WINNT_AUTH_IDENTITY PSEC_WINNT_AUTH_IDENTITY_W
'#define _SEC_WINNT_AUTH_IDENTITY _SEC_WINNT_AUTH_IDENTITY_W
#ELSE ' UNICODE
TYPE SEC_WINNT_AUTH_IDENTITY
    SEC_WINNT_AUTH_IDENTITY_A
END TYPE
'#define PSEC_WINNT_AUTH_IDENTITY PSEC_WINNT_AUTH_IDENTITY_A
'#define _SEC_WINNT_AUTH_IDENTITY _SEC_WINNT_AUTH_IDENTITY_A
#ENDIF ' UNICODE


#ENDIF ' %AUTH_IDENTITY_DEFINED

'
' This is the combined authentication identity structure that may be
' used with the negotiate package, NTLM, Kerberos, or SCHANNEL
'

#IF NOT %DEF(%SEC_WINNT_AUTH_IDENTITY_VERSION)
%SEC_WINNT_AUTH_IDENTITY_VERSION = &H200

TYPE SEC_WINNT_AUTH_IDENTITY_EXW
    Version           AS DWORD
    Length            AS DWORD
    User              AS WORD PTR  '  Non-NULL terminated string.
    UserLength        AS DWORD     '  # of characters (NOT bytes), not including NULL.
    Domain            AS WORD PTR  '  Non-NULL terminated string.
    DomainLength      AS DWORD     '  # of characters (NOT bytes), not including NULL.
    Password          AS WORD PTR  '  Non-NULL terminated string.
    PasswordLength    AS DWORD     '  # of characters (NOT bytes), not including NULL.
    Flags             AS DWORD
    PackageList       AS WORD PTR
    PackageListLength AS DWORD
END TYPE


TYPE SEC_WINNT_AUTH_IDENTITY_EXA
    Version           AS DWORD
    Length            AS DWORD
    User              AS BYTE PTR  '  Non-NULL terminated string.
    UserLength        AS DWORD     '  # of characters (NOT bytes), not including NULL.
    Domain            AS BYTE PTR  '  Non-NULL terminated string.
    DomainLength      AS DWORD     '  # of characters (NOT bytes), not including NULL.
    Password          AS BYTE PTR  '  Non-NULL terminated string.
    PasswordLength    AS DWORD     '  # of characters (NOT bytes), not including NULL.
    Flags             AS DWORD
    PackageList       AS BYTE PTR
    PackageListLength AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE SEC_WINNT_AUTH_IDENTITY_EX
    SEC_WINNT_AUTH_IDENTITY_EXW
END TYPE
'#define PSEC_WINNT_AUTH_IDENTITY_EX PSEC_WINNT_AUTH_IDENTITY_EXW
#ELSE
TYPE SEC_WINNT_AUTH_IDENTITY_EX
    SEC_WINNT_AUTH_IDENTITY_EXA
END TYPE
#ENDIF


#ENDIF ' SEC_WINNT_AUTH_IDENTITY_VERSION


#IF NOT %DEF(%AUTH_IDENTITY_INFO_DEFINED)
%AUTH_IDENTITY_INFO_DEFINED = 1

'
' the procedure for how to parse a SEC_WINNT_AUTH_IDENTITY_INFO structure:
'
' 1) First check the first DWORD of SEC_WINNT_AUTH_IDENTITY_INFO, if the first
'   DWORD is &H200, it is either an AuthIdExw or AuthIdExA, otherwise if the first
'   DWORD is &H201, the structure is an AuthIdEx2 structure. Otherwise the structure
'   is either an AuthId_a or an AuthId_w.
'
' 2) Secondly check the flags for SEC_WINNT_AUTH_IDENTITY_ANSI or
'   SEC_WINNT_AUTH_IDENTITY_UNICODE, the presence of the former means the structure
'   is an ANSI structure. Otherwise, the structure is the wide version.  Note that
'   AuthIdEx2 does not have an ANSI version so this check does not apply to it.
'

UNION SEC_WINNT_AUTH_IDENTITY_INFO
    AuthIdExw AS SEC_WINNT_AUTH_IDENTITY_EXW
    AuthIdExa AS SEC_WINNT_AUTH_IDENTITY_EXA
    AuthId_a  AS SEC_WINNT_AUTH_IDENTITY_A
    AuthId_w  AS SEC_WINNT_AUTH_IDENTITY_W
    AuthIdEx2 AS SEC_WINNT_AUTH_IDENTITY_EX2
END UNION

' the credential structure is encrypted via
' RtlEncryptMemory(OptionFlags = 0)
%SEC_WINNT_AUTH_IDENTITY_FLAGS_PROCESS_ENCRYPTED = &H10

' the credential structure is protected by local system via
' RtlEncryptMemory(OptionFlags =
' IOCTL_KSEC_ENCRYPT_MEMORY_SAME_LOGON)
%SEC_WINNT_AUTH_IDENTITY_FLAGS_SYSTEM_PROTECTED  = &H20

%SEC_WINNT_AUTH_IDENTITY_FLAGS_RESERVED    = &H10000
%SEC_WINNT_AUTH_IDENTITY_FLAGS_NULL_USER   = &H20000
%SEC_WINNT_AUTH_IDENTITY_FLAGS_NULL_DOMAIN = &H40000

'
'  These bits are for communication between SspiPromptForCredentials()
'  and the credential providers. Do not use these bits for any other
'  purpose.
'

%SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_USE_MASK  = &HFF000000???

'
'  Instructs the credential provider to not save credentials itself
'  when caller selects the "Remember my credential" checkbox.
'

%SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_SAVE_CRED_BY_CALLER = &H80000000???

'
'  State of the "Remember my credentials" checkbox.
'  When set, indicates checked; when cleared, indicates unchecked.
'

%SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_SAVE_CRED_CHECKED   = &H40000000

%SEC_WINNT_AUTH_IDENTITY_FLAGS_VALID_SSPIPFC_FLAGS =  _
    (%SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_SAVE_CRED_BY_CALLER OR _
    %SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_SAVE_CRED_CHECKED)


#ENDIF ' %AUTH_IDENTITY_INFO_DEFINED

#IF NOT %DEF(%SSPIPFC_NONE) ' the public view


'typedef PVOID PSEC_WINNT_AUTH_IDENTITY_OPAQUE; ' the credential structure is opaque


#ELSE  ' the internal view

'typedef PSEC_WINNT_AUTH_IDENTITY_INFO PSEC_WINNT_AUTH_IDENTITY_OPAQUE;

#ENDIF ' %SSPIPFC_NONE

'
'  dwFlags parameter of SspiPromptForCredentials():
'

'
'  Indicates that the credentials should not be saved if
'  the user selects the 'save' (or 'remember my password')
'  checkbox in the credential dialog box. The location pointed
'  to by the pfSave parameter indicates whether or not the user
'  selected the checkbox.
'
'  Note that some credential providers won't honour this flag and
'  may save the credentials in a persistent manner anyway if the
'  user selects the 'save' checbox.
'

%SSPIPFC_SAVE_CRED_BY_CALLER   = &H00000001

%SSPIPFC_VALID_FLAGS = %SSPIPFC_SAVE_CRED_BY_CALLER

#IF NOT %DEF(%SSPIPFC_NONE) ' the public view

' Use SspiFreeAuthIdentity() to free the buffer returned
' in ppAuthIdentity.

#IF %DEF(%CREDUI_INFO_DEFINED)
DECLARE FUNCTION SspiPromptForCredentialsW LIB "Secur32.dll" _
    ALIAS "SspiPromptForCredentialsW" ( _
    pszTargetName      AS WSTRINGZ, _
    pUiInfo            AS CREDUI_INFOW, _
    BYVAL dwAuthError  AS DWORD, _
    pszPackage         AS WSTRINGZ, _
    pInputAuthIdentity AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE, _
    ppAuthIdentity     AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE PTR PTR
    pfSave             AS LONG, _
    BYVAL dwFlags      AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION SspiPromptForCredentialsW LIB "Secur32.dll" _
    ALIAS "SspiPromptForCredentialsW" ( _
    pszTargetName      AS WSTRINGZ, _
    pUiInfo            AS ANY, _  ' VOID ptr
    BYVAL dwAuthError  AS DWORD, _
    pszPackage         AS WSTRINGZ, _
    pInputAuthIdentity AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE, _
    ppAuthIdentity     AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE PTR PTR
    pfSave             AS LONG, _
    BYVAL dwFlags      AS DWORD _
    ) AS DWORD
#ENDIF ' CREDUI_INFO_DEFINED

' Use SspiFreeAuthIdentity() to free the buffer returned
' in ppAuthIdentity.

#IF %DEF(%CREDUI_INFO_DEFINED)
DECLARE FUNCTION SspiPromptForCredentialsA LIB "Secur32.dll" _
    ALIAS "SspiPromptForCredentialsA" ( _
    pszTargetName      AS ASCIIZ, _
    pUiInfo            AS CREDUI_INFOA, _
    BYVAL dwAuthError  AS DWORD, _
    pszPackage         AS ASCIIZ, _
    pInputAuthIdentity AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE, _
    ppAuthIdentity     AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE PTR PTR
    pfSave             AS LONG, _
    BYVAL dwFlags      AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION SspiPromptForCredentialsA LIB "Secur32.dll" _
    ALIAS "SspiPromptForCredentialsA" ( _
    pszTargetName      AS ASCIIZ, _
    pUiInfo            AS ANY, _   ' VOID PTR
    BYVAL dwAuthError  AS DWORD, _
    pszPackage         AS ASCIIZ, _
    pInputAuthIdentity AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE, _
    ppAuthIdentity     AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE PTR PTR
    pfSave             AS LONG, _
    BYVAL dwFlags      AS DWORD _
    ) AS DWORD
#ENDIF ' CREDUI_INFO_DEFINED

#ENDIF ' %SSPIPFC_NONE

#IF %DEF(%UNICODE)
MACRO SspiPromptForCredentials=SspiPromptForCredentialsW
#ELSE
MACRO SspiPromptForCredentials=SspiPromptForCredentialsA
#ENDIF

#IF %DEF(%SEC_WINNT_AUTH_TYPES)

TYPE SEC_WINNT_AUTH_BYTE_VECTOR DWORD FILL
    ByteArrayOffset AS DWORD  ' each element is a byte
    ByteArrayLength AS WORD   '
END TYPE

TYPE SEC_WINNT_AUTH_DATA DWORD FILL
   CredType AS GUID
   CredData AS SEC_WINNT_AUTH_BYTE_VECTOR
END TYPE

TYPE SEC_WINNT_AUTH_PACKED_CREDENTIALS
   cbHeaderLength    AS WORD   ' the length of the header
   cbStructureLength AS WORD   ' pay load length including the header
   AuthData          AS SEC_WINNT_AUTH_DATA
END TYPE

$SEC_WINNT_AUTH_DATA_TYPE_PASSWORD = GUID$("{28BFC32F-10F6-4738-98D1-1AC061DF716A}")

$SEC_WINNT_AUTH_DATA_TYPE_CERT = GUID$("{235F69AD-73FB-4dbc-8203-0629E739339B}")

TYPE SEC_WINNT_AUTH_DATA_PASSWORD
    UnicodePassword AS SEC_WINNT_AUTH_BYTE_VECTOR
END TYPE

'
' smartcard cred data
'

$SEC_WINNT_AUTH_DATA_TYPE_CSP_DATA = GUID$("{68FD9879-079C-4dfe-8281-578AADC1C100}")

TYPE SEC_WINNT_AUTH_CERTIFICATE_DATA
   cbHeaderLength    AS WORD
   cbStructureLength AS WORD
   Certificate       AS SEC_WINNT_AUTH_BYTE_VECTOR
END TYPE

TYPE SEC_WINNT_CREDUI_CONTEXT_VECTOR DWORD FILL
   CredUIContextArrayOffset AS DWORD  ' offset starts at the beginning of
   ' this structure, and each element is a SEC_WINNT_AUTH_BYTE_VECTOR that
   ' describes the flat CredUI context returned by SpGetCredUIContext()
   CredUIContextCount       AS WORD
END TYPE

TYPE SEC_WINNT_AUTH_SHORT_VECTOR DWORD FILL
    ShortArrayOffset AS DWORD   ' each element is a short
    ShortArrayCount  AS WORD  ' number of characters
END TYPE

' free the returned memory using SspiLocalFree

DECLARE FUNCTION SspiGetCredUIContext LIB "Secur32.dll" _
    ALIAS "SspiGetCredUIContext" ( _
   BYVAL ContextHandle AS DWORD, _  ' HANDLE
   CredType            AS GUID, _
   LogonId             AS QUAD, _   ' LUID ' use this LogonId, the caller must be localsystem to supply a logon id
   CredUIContexts      AS ANY, _    ' SEC_WINNT_CREDUI_CONTEXT_VECTOR PTR PTR
   TokenHandle         AS DWORD _   ' HANDLE
   ) AS SECURITY_STATUS

DECLARE FUNCTION SspiUpdateCredentials LIB "Secur32.dll" _
    ALIAS "SspiUpdateCredentials" ( _
   BYVAL ContextHandle           AS DWORD, _  ' HANDLE
   CredType                      AS GUID, _
   BYVAL FlatCredUIContextLength AS DWORD, _
   BYVAL FlatCredUIContext       AS BYTE PTR _
   ) AS SECURITY_STATUS

TYPE CREDUIWIN_MARSHALED_CONTEXT DWORD FILL
    StructureType       AS GUID
    cbHeaderLength      AS WORD
    LogonId             AS QUAD  ' LUID  ' user's logon id
    MarshaledDataType   AS GUID
    MarshaledDataOffset AS DWORD
    MarshaledDataLength AS WORD
END TYPE

TYPE SEC_WINNT_CREDUI_CONTEXT DWORD FILL
    cbHeaderLength      AS WORD
    CredUIContextHandle AS DWORD  ' HANDLE  ' the handle to call SspiGetCredUIContext()
#IF %DEF(%CREDUI_INFO_DEFINED)
    UIInfo              AS CREDUI_INFOW PTR ' input from SspiPromptForCredentials()
#ELSE
    UIInfo              AS DWORD  ' PVOID
#ENDIF ' _CREDUI_INFO_DEFINED
    dwAuthError         AS DWORD  ' the authentication error
    pInputAuthIdentity  AS DWORD  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE PTR
    TargetName          AS UNICODE_STRING PTR
END TYPE

$CREDUIWIN_STRUCTURE_TYPE_SSPIPFC = GUID$("{3C3E93D9-D96B-49b5-94A7-458592088337}")

$SSPIPFC_STRUCTURE_TYPE_CREDUI_CONTEXT = GUID$("{C2FFFE6F-503D-4c3d-A95E-BCE821213D44}")

TYPE SEC_WINNT_AUTH_PACKED_CREDENTIALS_EX DWORD FILL
    cbHeaderLength    AS WORD
    Flags             AS DWORD  ' contains the Flags field in
                                ' SEC_WINNT_AUTH_IDENTITY_EX
    PackedCredentials AS SEC_WINNT_AUTH_BYTE_VECTOR
    PackageList       AS SEC_WINNT_AUTH_SHORT_VECTOR
END TYPE

'
' free the returned memory using SspiLocalFree
'

DECLARE FUNCTION SspiUnmarshalCredUIContext LIB "Secur32.dll" _
    ALIAS "SspiUnmarshalCredUIContext" ( _
    BYVAL MarshaledCredUIContext       AS BYTE PTR, _
    BYVAL MarshaledCredUIContextLength AS DWORD, _
    CredUIContext                      AS ANY _  ' SEC_WINNT_CREDUI_CONTEXT PTR PTR
    ) AS SECURITY_STATUS

#ENDIF ' %SEC_WINNT_AUTH_TYPES

DECLARE FUNCTION SspiPrepareForCredRead LIB "Secur32.dll" _
    ALIAS "SspiPrepareForCredRead" ( _
    AuthIdentity           AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    pszTargetName          AS WSTRINGZ, _
    pCredmanCredentialType AS DWORD, _
    ppszCredmanTargetName  AS ANY _  ' PCWSTR*
    ) AS SECURITY_STATUS

DECLARE FUNCTION SspiPrepareForCredWrite LIB "Secur32.dll" _
    ALIAS "SspiPrepareForCredWrite" ( _
    AuthIdentity           AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE, _
    pszTargetName          AS WSTRINGZ, _ ' supply NULL for username-target credentials
    pCredmanCredentialType AS DWORD, _
    ppszCredmanTargetName  AS ANY, _  ' PCWSTR*
    ppszCredmanUserName    AS ANY, _  ' PCWSTR*
    ppCredentialBlob       AS ANY, _  ' PUCHAR *
    pCredentialBlobSize    AS DWORD _
    ) AS SECURITY_STATUS

DECLARE FUNCTION SspiEncryptAuthIdentity LIB "Secur32.dll" _
    ALIAS "SspiEncryptAuthIdentity" ( _
    AuthData AS ANY _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    ) AS SECURITY_STATUS

DECLARE FUNCTION SspiDecryptAuthIdentity LIB "Secur32.dll" _
    ALIAS "SspiDecryptAuthIdentity" ( _
    EncryptedAuthData AS ANY _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    ) AS SECURITY_STATUS

DECLARE FUNCTION SspiIsAuthIdentityEncrypted LIB "Secur32.dll" _
    ALIAS "SspiIsAuthIdentityEncrypted" ( _
    EncryptedAuthData AS ANY _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    ) AS BYTE  ' BOOLEAN


#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
'
'  Convert the _OPAQUE structure passed in to the
'  3 tuple <username, domainname, 'password'>.
'
'  Note: The 'strings' returned need not necessarily be
'  in user recognisable form. The purpose of this API
'  is to 'flatten' the _OPAQUE structure into the 3 tuple.
'  User recognisable <username, domainname> can always be
'  obtained by passing NULL to the pszPackedCredentialsString
'  parameter.
'
' zero out the pszPackedCredentialsString then
' free the returned memory using SspiLocalFree()
'

DECLARE FUNCTION SspiEncodeAuthIdentityAsStrings LIB "Secur32.dll" _
    ALIAS "SspiEncodeAuthIdentityAsStrings" ( _
    pAuthIdentity               AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    ppszUserName                AS ANY, _  ' PCWSTR*
    ppszDomainName              AS ANY, _  ' PCWSTR*
    ppszPackedCredentialsString AS ANY _   ' PCWSTR*
    ) AS SECURITY_STATUS

DECLARE FUNCTION SspiValidateAuthIdentity LIB "Secur32.dll" _
    ALIAS "SspiValidateAuthIdentity" ( _
    AuthData AS ANY _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    ) AS SECURITY_STATUS

'
' free the returned memory using SspiFreeAuthIdentity()
'

DECLARE FUNCTION SspiCopyAuthIdentity LIB "Secur32.dll" _
    ALIAS "SspiCopyAuthIdentity" ( _
    AuthData     AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE, _
    AuthDataCopy AS ANY _   ' SEC_WINNT_AUTH_IDENTITY_OPAQUE ptr ptr
    ) AS SECURITY_STATUS

'
' use only for the memory returned by SspiCopyAuthIdentity().
' Internally calls SspiZeroAuthIdentity().
'

DECLARE SUB SspiFreeAuthIdentity LIB "Secur32.dll" _
    ALIAS "SspiFreeAuthIdentity" ( _
    AuthData AS ANY _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    )

DECLARE SUB SspiZeroAuthIdentity LIB "Secur32.dll" _
    ALIAS "SspiZeroAuthIdentity" ( _
    AuthData AS ANY _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    )

DECLARE SUB SspiLocalFree LIB "Secur32.dll" ALIAS "SspiLocalFree" ( _
    DataBuffer AS ANY _  ' VOID PTR
    )

'
' call SspiFreeAuthIdentity to free the returned AuthIdentity
' which zeroes out the credentials blob before freeing it
'

DECLARE FUNCTION SspiEncodeStringsAsAuthIdentity LIB "Secur32.dll" _
    ALIAS "SspiEncodeStringsAsAuthIdentity" ( _
    pszUserName                AS WSTRINGZ, _
    pszDomainName              AS WSTRINGZ, _
    pszPackedCredentialsString AS WSTRINGZ, _
    ppAuthIdentity             AS ANY _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE ptr ptr
    ) AS SECURITY_STATUS

DECLARE FUNCTION SspiCompareAuthIdentities LIB "Secur32.dll" _
    ALIAS "SspiCompareAuthIdentities" ( _
    AuthIdentity1        AS ANY, _   ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    AuthIdentity2        AS ANY, _   ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    SameSuppliedUser     AS BYTE, _  ' BOOLEAN
    SameSuppliedIdentity AS BYTE _   ' BOOLEAN
    ) AS SECURITY_STATUS

'
' zero out the returned AuthIdentityByteArray then
' free the returned memory using SspiLocalFree()
'

DECLARE FUNCTION SspiMarshalAuthIdentity LIB "Secur32.dll" _
    ALIAS "SspiMarshalAuthIdentity" ( _
    AuthIdentity          AS ANY, _ ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    AuthIdentityLength    AS DWORD, _
    AuthIdentityByteArray AS ANY _  ' char**
    ) AS SECURITY_STATUS

'
' free the returned auth identity using SspiFreeAuthIdentity()
'

DECLARE FUNCTION SspiUnmarshalAuthIdentity LIB "Secur32.dll" _
    ALIAS "SspiUnmarshalAuthIdentity" ( _
    BYVAL AuthIdentityLength    AS DWORD, _
    BYVAL AuthIdentityByteArray AS BYTE PTR, _
    ppAuthIdentity              AS ANY _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE ptr ptr
    ) AS SECURITY_STATUS

DECLARE FUNCTION SspiIsPromptingNeeded LIB "Secur32.dll" _
    ALIAS "SspiIsPromptingNeeded" ( _
    BYVAL ErrorOrNtStatus AS DWORD _
    ) AS BYTE  ' BOOLEAN

DECLARE FUNCTION SspiGetTargetHostName LIB "Secur32.dll" _
    ALIAS "SspiGetTargetHostName" ( _
    pszTargetName AS WSTRINGZ, _
    pszHostName   AS ANY _  ' PWSTR*
    ) AS SECURITY_STATUS

DECLARE FUNCTION SspiExcludePackage LIB "Secur32.dll" _
    ALIAS "SspiExcludePackage" ( _
    AuthIdentity      AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    pszPackageName    AS WSTRINGZ, _
    ppNewAuthIdentity AS ANY _   ' SEC_WINNT_AUTH_IDENTITY_OPAQUE ptr ptr
    ) AS SECURITY_STATUS

'
' Common types used by negotiable security packages
'
' These are defined after W2K
'

%SEC_WINNT_AUTH_IDENTITY_MARSHALLED = &H4  ' all data is in one buffer
%SEC_WINNT_AUTH_IDENTITY_ONLY       = &H8  ' these credentials are for identity only - no PAC needed

#ENDIF ' %NTDDI_VERSION

'
' Routines for manipulating packages
'

TYPE SECURITY_PACKAGE_OPTIONS
    Size          AS DWORD
    Type          AS DWORD
    Flags         AS DWORD
    SignatureSize AS DWORD
    Signature     AS DWORD  ' void *
END TYPE

%SECPKG_OPTIONS_TYPE_UNKNOWN = 0
%SECPKG_OPTIONS_TYPE_LSA     = 1
%SECPKG_OPTIONS_TYPE_SSPI    = 2

%SECPKG_OPTIONS_PERMANENT    = &H00000001

DECLARE FUNCTION AddSecurityPackageA LIB "Secur32.dll" _
    ALIAS "AddSecurityPackageA" ( _
    pszPackageName AS ASCIIZ, _
    pOptions       AS SECURITY_PACKAGE_OPTIONS _
    ) AS SECURITY_STATUS

DECLARE FUNCTION AddSecurityPackageW LIB "Secur32.dll" _
    ALIAS "AddSecurityPackageW" ( _
    pszPackageName AS WSTRINGZ, _
    pOptions       AS SECURITY_PACKAGE_OPTIONS _
    ) AS SECURITY_STATUS

#IF %DEF(%UNICODE)
MACRO AddSecurityPackage=AddSecurityPackageW
#ELSE
MACRO AddSecurityPackage=AddSecurityPackageA
#ENDIF

DECLARE FUNCTION DeleteSecurityPackageA LIB "Secur32.dll" _
    ALIAS "DeleteSecurityPackageA" ( _
    pszPackageName AS ASCIIZ _
    ) AS SECURITY_STATUS

DECLARE FUNCTION DeleteSecurityPackageW LIB "Secur32.dll" _
    ALIAS "DeleteSecurityPackageW" ( _
    pszPackageName AS WSTRINGZ _
    ) AS SECURITY_STATUS

#IF %DEF(%UNICODE)
MACRO DeleteSecurityPackage=DeleteSecurityPackageW
#ELSE
MACRO DeleteSecurityPackage=DeleteSecurityPackageA
#ENDIF
