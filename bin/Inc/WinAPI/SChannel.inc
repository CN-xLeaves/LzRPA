'------------------------------------------------------------------------------
'
'  SChannel.inc  - Public Definitions for SCHANNEL Security Provider
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from SChannel.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%SCHANNEL_H = 1

#INCLUDE "WinCrypt.inc"


'
' Security package names.
'

$UNISP_NAME_A     = "Microsoft Unified Security Protocol Provider"
$$UNISP_NAME_W    = "Microsoft Unified Security Protocol Provider"$$

$SSL2SP_NAME_A    = "Microsoft SSL 2.0"
$$SSL2SP_NAME_W   = "Microsoft SSL 2.0"$$

$SSL3SP_NAME_A    = "Microsoft SSL 3.0"
$$SSL3SP_NAME_W   = "Microsoft SSL 3.0"$$

$TLS1SP_NAME_A    = "Microsoft TLS 1.0"
$$TLS1SP_NAME_W   = "Microsoft TLS 1.0"$$

$PCT1SP_NAME_A    = "Microsoft PCT 1.0"
$$PCT1SP_NAME_W   = "Microsoft PCT 1.0"$$

$SCHANNEL_NAME_A  = "Schannel"
$$SCHANNEL_NAME_W = "Schannel"$$

$UNISP_NAME       = "Microsoft Unified Security Protocol Provider"
$$UNISP_NAME      = "Microsoft Unified Security Protocol Provider"$$

$SSL2SP_NAME      = "Microsoft SSL 2.0"
$$SSL2SP_NAME     = "Microsoft SSL 2.0"$$

$SSL3SP_NAME      = "Microsoft SSL 3.0"
$$SSL3SP_NAME     = "Microsoft SSL 3.0"$$

$TLS1SP_NAME      = "Microsoft TLS 1.0"
$$TLS1SP_NAME     = "Microsoft TLS 1.0"$$

$PCT1SP_NAME      = "Microsoft PCT 1.0"
$$PCT1SP_NAME     = "Microsoft PCT 1.0"$$

$SCHANNEL_NAME    = "Schannel"
$$SCHANNEL_NAME   = "Schannel"$$


'#ifdef UNICODE
'
'#define UNISP_NAME  UNISP_NAME_W
'#define PCT1SP_NAME  PCT1SP_NAME_W
'#define SSL2SP_NAME  SSL2SP_NAME_W
'#define SSL3SP_NAME  SSL3SP_NAME_W
'#define TLS1SP_NAME  TLS1SP_NAME_W
'#define SCHANNEL_NAME  SCHANNEL_NAME_W
'
'#else
'
'#define UNISP_NAME  UNISP_NAME_A
'#define PCT1SP_NAME  PCT1SP_NAME_A
'#define SSL2SP_NAME  SSL2SP_NAME_A
'#define SSL3SP_NAME  SSL3SP_NAME_A
'#define TLS1SP_NAME  TLS1SP_NAME_A
'#define SCHANNEL_NAME  SCHANNEL_NAME_A
'
'#endif


MACRO eTlsSignatureAlgorithm_enum=LONG
ENUM eTlsSignatureAlgorithm SINGULAR
    TlsSignatureAlgorithm_Anonymous
    TlsSignatureAlgorithm_Rsa
    TlsSignatureAlgorithm_Dsa
    TlsSignatureAlgorithm_Ecdsa
END ENUM

MACRO eTlsHashAlgorithm_enum=LONG
ENUM eTlsHashAlgorithm SINGULAR
    TlsHashAlgorithm_None
    TlsHashAlgorithm_Md5
    TlsHashAlgorithm_Sha1
    TlsHashAlgorithm_Sha224
    TlsHashAlgorithm_Sha256
    TlsHashAlgorithm_Sha384
    TlsHashAlgorithm_Sha512
END ENUM


'
' RPC constants.
'

%UNISP_RPC_ID  = 14


'
' QueryContextAttributes/QueryCredentialsAttribute extensions
'

%SECPKG_ATTR_ISSUER_LIST          = &H50   ' (OBSOLETE) returns SecPkgContext_IssuerListInfo
%SECPKG_ATTR_REMOTE_CRED          = &H51   ' (OBSOLETE) returns SecPkgContext_RemoteCredentialInfo
%SECPKG_ATTR_LOCAL_CRED           = &H52   ' (OBSOLETE) returns SecPkgContext_LocalCredentialInfo
%SECPKG_ATTR_REMOTE_CERT_CONTEXT  = &H53   ' returns PCCERT_CONTEXT
%SECPKG_ATTR_LOCAL_CERT_CONTEXT   = &H54   ' returns PCCERT_CONTEXT
%SECPKG_ATTR_ROOT_STORE           = &H55   ' returns HCERTCONTEXT to the root store
%SECPKG_ATTR_SUPPORTED_ALGS       = &H56   ' returns SecPkgCred_SupportedAlgs
%SECPKG_ATTR_CIPHER_STRENGTHS     = &H57   ' returns SecPkgCred_CipherStrengths
%SECPKG_ATTR_SUPPORTED_PROTOCOLS  = &H58   ' returns SecPkgCred_SupportedProtocols
%SECPKG_ATTR_ISSUER_LIST_EX       = &H59   ' returns SecPkgContext_IssuerListInfoEx
%SECPKG_ATTR_CONNECTION_INFO      = &H5a   ' returns SecPkgContext_ConnectionInfo
%SECPKG_ATTR_EAP_KEY_BLOCK        = &H5b   ' returns SecPkgContext_EapKeyBlock
%SECPKG_ATTR_MAPPED_CRED_ATTR     = &H5c   ' returns SecPkgContext_MappedCredAttr
%SECPKG_ATTR_SESSION_INFO         = &H5d   ' returns SecPkgContext_SessionInfo
%SECPKG_ATTR_APP_DATA             = &H5e   ' sets/returns SecPkgContext_SessionAppData
%SECPKG_ATTR_REMOTE_CERTIFICATES  = &H5F   ' returns SecPkgContext_Certificates
%SECPKG_ATTR_CLIENT_CERT_POLICY   = &H60   ' sets    SecPkgCred_ClientCertCtlPolicy
%SECPKG_ATTR_CC_POLICY_RESULT     = &H61   ' returns SecPkgContext_ClientCertPolicyResult
%SECPKG_ATTR_USE_NCRYPT           = &H62   ' Sets the CRED_FLAG_USE_NCRYPT_PROVIDER FLAG on cred group
%SECPKG_ATTR_LOCAL_CERT_INFO      = &H63   ' returns SecPkgContext_CertInfo
%SECPKG_ATTR_CIPHER_INFO          = &H64   ' returns new CNG SecPkgContext_CipherInfo
%SECPKG_ATTR_EAP_PRF_INFO         = &H65   ' sets    SecPkgContext_EapPrfInfo
%SECPKG_ATTR_SUPPORTED_SIGNATURES = &H66   ' returns SecPkgContext_SupportedSignatures


' OBSOLETE - included here for backward compatibility only
TYPE SecPkgContext_RemoteCredentialInfo
    cbCertificateChain AS DWORD
    pbCertificateChain AS BYTE PTR
    cCertificates AS DWORD
    fFlags AS DWORD
    dwBits AS DWORD
END TYPE

TYPE SecPkgContext_RemoteCredenitalInfo
    SecPkgContext_RemoteCredentialInfo
END TYPE

%RCRED_STATUS_NOCRED          = &H00000000
%RCRED_CRED_EXISTS            = &H00000001
%RCRED_STATUS_UNKNOWN_ISSUER  = &H00000002


' OBSOLETE - included here for backward compatibility only
TYPE SecPkgContext_LocalCredentialInfo
    cbCertificateChain AS DWORD
    pbCertificateChain AS BYTE PTR
    cCertificates      AS DWORD
    fFlags             AS DWORD
    dwBits             AS DWORD
END TYPE

TYPE SecPkgContext_LocalCredenitalInfo
    SecPkgContext_LocalCredentialInfo
END TYPE

%LCRED_STATUS_NOCRED          = &H00000000
%LCRED_CRED_EXISTS            = &H00000001
%LCRED_STATUS_UNKNOWN_ISSUER  = &H00000002


TYPE SecPkgCred_SupportedAlgs
    cSupportedAlgs    AS DWORD
    palgSupportedAlgs AS DWORD  ' ALG_ID PTR
END TYPE


TYPE SecPkgCred_CipherStrengths
    dwMinimumCipherStrength AS DWORD
    dwMaximumCipherStrength AS DWORD
END TYPE


TYPE SecPkgCred_SupportedProtocols
    grbitProtocol AS DWORD
END TYPE


TYPE SecPkgCred_ClientCertPolicy DWORD FILL
    dwFlags                       AS DWORD
    guidPolicyId                  AS GUID
    dwCertFlags                   AS DWORD
    dwUrlRetrievalTimeout         AS DWORD
    fCheckRevocationFreshnessTime AS LONG  ' BOOL
    dwRevocationFreshnessTime     AS DWORD
    fOmitUsageCheck               AS LONG  ' BOOL
    pwszSslCtlStoreName           AS WSTRINGZ PTR
    pwszSslCtlIdentifier          AS WSTRINGZ PTR
END TYPE


TYPE SecPkgContext_ClientCertPolicyResult DWORD FILL
    dwPolicyResult AS LONG  ' HRESULT
    guidPolicyId   AS GUID
END TYPE


TYPE SecPkgContext_IssuerListInfoEx
    aIssuers AS CERT_NAME_BLOB PTR
    cIssuers AS DWORD
END TYPE


TYPE SecPkgContext_ConnectionInfo
    dwProtocol       AS DWORD
    aiCipher         AS DWORD  ' ALG_ID
    dwCipherStrength AS DWORD
    aiHash           AS DWORD  ' ALG_ID
    dwHashStrength   AS DWORD
    aiExch           AS DWORD  ' ALG_ID
    dwExchStrength   AS DWORD
END TYPE

%SZ_ALG_MAX_SIZE = 64
%SECPKGCONTEXT_CIPHERINFO_V1 = 1

TYPE SecPkgContext_CipherInfo DWORD FILL
    dwVersion         AS DWORD
    dwProtocol        AS DWORD
    dwCipherSuite     AS DWORD
    dwBaseCipherSuite AS DWORD
    szCipherSuite     AS WSTRINGZ * %SZ_ALG_MAX_SIZE
    szCipher          AS WSTRINGZ * %SZ_ALG_MAX_SIZE
    dwCipherLen       AS DWORD
    dwCipherBlockLen  AS DWORD     ' in bytes
    szHash            AS WSTRINGZ * %SZ_ALG_MAX_SIZE
    dwHashLen         AS DWORD
    szExchange        AS WSTRINGZ * %SZ_ALG_MAX_SIZE
    dwMinExchangeLen  AS DWORD
    dwMaxExchangeLen  AS DWORD
    szCertificate     AS WSTRINGZ * %SZ_ALG_MAX_SIZE
    dwKeyType         AS DWORD
END TYPE


TYPE SecPkgContext_EapKeyBlock DWORD FILL
    rgbKeys(127) AS BYTE
    rgbIVs(63)   AS BYTE
END TYPE


TYPE SecPkgContext_MappedCredAttr
    dwAttribute AS DWORD
    pvBuffer    AS DWORD  ' PVOID
END TYPE


' Flag values for SecPkgContext_SessionInfo
%SSL_SESSION_RECONNECT = 1

TYPE SecPkgContext_SessionInfo DWORD FILL
    dwFlags          AS DWORD
    cbSessionId      AS DWORD
    rgbSessionId(31) AS BYTE
END TYPE


TYPE SecPkgContext_SessionAppData
    dwFlags   AS DWORD
    cbAppData AS DWORD
    pbAppData AS BYTE PTR
END TYPE

TYPE SecPkgContext_EapPrfInfo
    dwVersion AS DWORD
    cbPrfData AS DWORD
    pbPrfData AS BYTE PTR
END TYPE


TYPE SecPkgContext_SupportedSignatures
    cSignatureAndHashAlgorithms AS WORD

    '
    ' Upper byte (from TLS 1.2, RFC 4346):
    '     enum {
    '         anonymous(0), rsa(1), dsa(2), ecdsa(3), (255)
    '     } SignatureAlgorithm;
    '
    ' enum eTlsSignatureAlgorithm

    '
    ' Lower byte (from TLS 1.2, RFC 4346):
    '     enum {
    '         none(0), md5(1), sha1(2), sha224(3), sha256(4), sha384(5),
    '         sha512(6), (255)
    '     } HashAlgorithm;
    '
    '
    ' enum eTlsHashAlgorithm

    pSignatureAndHashAlgorithms AS WORD PTR
END TYPE


'
' This property returns the raw binary certificates that were received
' from the remote party. The format of the buffer that's returned is as
' follows.
'
'     <4 bytes> length of certificate #1
'     <n bytes> certificate #1
'     <4 bytes> length of certificate #2
'     <n bytes> certificate #2
'     ...
'
' After this data is processed, the caller of QueryContextAttributes
' must free the pbCertificateChain buffer using FreeContextBuffer.
'
TYPE SecPkgContext_Certificates
    cCertificates      AS DWORD
    cbCertificateChain AS DWORD
    pbCertificateChain AS BYTE PTR
END TYPE


'
' This property returns information about a certificate. In particular
' it is useful (and only available) in the kernel where CAPI2 is not
' available.
'
TYPE SecPkgContext_CertInfo
    dwVersion       AS DWORD
    cbSubjectName   AS DWORD
    pwszSubjectName AS WSTRINGZ PTR
    cbIssuerName    AS DWORD
    pwszIssuerName  AS WSTRINGZ PTR
    dwKeySize       AS DWORD
END TYPE

%KERN_CONTEXT_CERT_INFO_V1 = &H00000000

'
' Schannel credentials data structure.
'

%SCH_CRED_V1            = &H00000001
%SCH_CRED_V2            = &H00000002  ' for legacy code
%SCH_CRED_VERSION       = &H00000002  ' for legacy code
%SCH_CRED_V3            = &H00000003  ' for legacy code
%SCHANNEL_CRED_VERSION  = &H00000004


'struct _HMAPPER;

TYPE SCHANNEL_CRED
    dwVersion         AS DWORD  ' always SCHANNEL_CRED_VERSION
    cCreds            AS DWORD
    paCred            AS DWORD  ' CERT_CONTEXT PTR PTR
    hRootStore        AS DWORD  ' HCERTSTORE

    cMappers          AS DWORD
    aphMappers        AS DWORD  ' _HMAPPER PTR PTR

    cSupportedAlgs    AS DWORD
    palgSupportedAlgs AS DWORD PTR  ' ALG_ID PTR

    grbitEnabledProtocols   AS DWORD
    dwMinimumCipherStrength AS DWORD
    dwMaximumCipherStrength AS DWORD
    dwSessionLifespan       AS DWORD
    dwFlags                 AS DWORD
    dwCredFormat            AS DWORD
END TYPE


' Values for SCHANNEL_CRED dwCredFormat field.
%SCH_CRED_FORMAT_CERT_CONTEXT  = &H00000000
%SCH_CRED_FORMAT_CERT_HASH     = &H00000001
%SCH_CRED_FORMAT_CERT_HASH_STORE = &H00000002

%SCH_CRED_MAX_STORE_NAME_SIZE  = 128
%SCH_CRED_MAX_SUPPORTED_ALGS   = 256
%SCH_CRED_MAX_SUPPORTED_CERTS  = 100

TYPE SCHANNEL_CERT_HASH
    dwLength    AS DWORD
    dwFlags     AS DWORD
    hProv       AS DWORD  ' HCRYPTPROV
    ShaHash(19) AS BYTE
END TYPE

TYPE SCHANNEL_CERT_HASH_STORE DWORD FILL
    dwLength      AS DWORD
    dwFlags       AS DWORD
    hProv         AS DWORD  ' HCRYPTPROV
    ShaHash(19)   AS BYTE
    pwszStoreName AS WSTRINGZ * %SCH_CRED_MAX_STORE_NAME_SIZE
END TYPE

' Values for SCHANNEL_CERT_HASH dwFlags field.
%SCH_MACHINE_CERT_HASH         = &H00000001


'+-------------------------------------------------------------------------
' Flags for use with SCHANNEL_CRED
'
' SCH_CRED_NO_SYSTEM_MAPPER
'      This flag is intended for use by server applications only. If this
'      flag is set, then schannel does *not* attempt to map received client
'      certificate chains to an NT user account using the built-in system
'      certificate mapper.This flag is ignored by non-NT5 versions of
'      schannel.
'
' SCH_CRED_NO_SERVERNAME_CHECK
'      This flag is intended for use by client applications only. If this
'      flag is set, then when schannel validates the received server
'      certificate chain, is does *not* compare the passed in target name
'      with the subject name embedded in the certificate. This flag is
'      ignored by non-NT5 versions of schannel. This flag is also ignored
'      if the SCH_CRED_MANUAL_CRED_VALIDATION flag is set.
'
' SCH_CRED_MANUAL_CRED_VALIDATION
'      This flag is intended for use by client applications only. If this
'      flag is set, then schannel will *not* automatically attempt to
'      validate the received server certificate chain. This flag is
'      ignored by non-NT5 versions of schannel, but all client applications
'      that wish to validate the certificate chain themselves should
'      specify this flag, so that there's at least a chance they'll run
'      correctly on NT5.
'
' SCH_CRED_NO_DEFAULT_CREDS
'      This flag is intended for use by client applications only. If this
'      flag is set, and the server requests client authentication, then
'      schannel will *not* attempt to automatically acquire a suitable
'      default client certificate chain. This flag is ignored by non-NT5
'      versions of schannel, but all client applications that wish to
'      manually specify their certicate chains should specify this flag,
'      so that there's at least a chance they'll run correctly on NT5.
'
' SCH_CRED_AUTO_CRED_VALIDATION
'      This flag is the opposite of SCH_CRED_MANUAL_CRED_VALIDATION.
'      Conservatively written client applications will always specify one
'      flag or the other.
'
' SCH_CRED_USE_DEFAULT_CREDS
'      This flag is the opposite of SCH_CRED_NO_DEFAULT_CREDS.
'      Conservatively written client applications will always specify one
'      flag or the other.
'
' SCH_CRED_DISABLE_RECONNECTS
'      This flag is intended for use by server applications only. If this
'      flag is set, then full handshakes performed with this credential
'      will not be marked suitable for reconnects. A cache entry will still
'      be created, however, so the session can be made resumable later
'      via a call to ApplyControlToken.
'
'
' SCH_CRED_REVOCATION_CHECK_END_CERT
' SCH_CRED_REVOCATION_CHECK_CHAIN
' SCH_CRED_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT
'      These flags specify that when schannel automatically validates a
'      received certificate chain, some or all of the certificates are to
'      be checked for revocation. Only one of these flags may be specified.
'      See the CertGetCertificateChain function. These flags are ignored by
'      non-NT5 versions of schannel.
'
' SCH_CRED_IGNORE_NO_REVOCATION_CHECK
' SCH_CRED_IGNORE_REVOCATION_OFFLINE
'      These flags instruct schannel to ignore the
'      CRYPT_E_NO_REVOCATION_CHECK and CRYPT_E_REVOCATION_OFFLINE errors
'      respectively if they are encountered when attempting to check the
'      revocation status of a received certificate chain. These flags are
'      ignored if none of the above flags are set.
'
' SCH_CRED_CACHE_ONLY_URL_RETRIEVAL_ON_CREATE
'      This flag instructs schannel to pass CERT_CHAIN_CACHE_ONLY_URL_RETRIEVAL
'      flags to CertGetCertificateChain when validating the specified
'      credentials during a call to AcquireCredentialsHandle. The default for
'      vista is to not specify CERT_CHAIN_CACHE_ONLY_URL_RETRIEVAL. Use
'      SCH_CRED_CACHE_ONLY_URL_RETRIEVAL_ON_CREATE to override this behavior.
'      NOTE: Prior to Vista, this flag(CERT_CHAIN_CACHE_ONLY_URL_RETRIEVAL) was
'      specified by default.
'
'  SCH_SEND_ROOT_CERT
'      This flag instructs schannel to send the root cert as part of the
'      certificate message.
'+-------------------------------------------------------------------------
%SCH_CRED_NO_SYSTEM_MAPPER                    = &H00000002
%SCH_CRED_NO_SERVERNAME_CHECK                 = &H00000004
%SCH_CRED_MANUAL_CRED_VALIDATION              = &H00000008
%SCH_CRED_NO_DEFAULT_CREDS                    = &H00000010
%SCH_CRED_AUTO_CRED_VALIDATION                = &H00000020
%SCH_CRED_USE_DEFAULT_CREDS                   = &H00000040
%SCH_CRED_DISABLE_RECONNECTS                  = &H00000080

%SCH_CRED_REVOCATION_CHECK_END_CERT           = &H00000100
%SCH_CRED_REVOCATION_CHECK_CHAIN              = &H00000200
%SCH_CRED_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT = &H00000400
%SCH_CRED_IGNORE_NO_REVOCATION_CHECK          = &H00000800
%SCH_CRED_IGNORE_REVOCATION_OFFLINE           = &H00001000

%SCH_CRED_RESTRICTED_ROOTS                    = &H00002000
%SCH_CRED_REVOCATION_CHECK_CACHE_ONLY         = &H00004000
%SCH_CRED_CACHE_ONLY_URL_RETRIEVAL            = &H00008000

%SCH_CRED_MEMORY_STORE_CERT                   = &H00010000

%SCH_CRED_CACHE_ONLY_URL_RETRIEVAL_ON_CREATE  = &H00020000

%SCH_SEND_ROOT_CERT                           = &H00040000

'
'
' ApplyControlToken PkgParams types
'
' These identifiers are the DWORD types
' to be passed into ApplyControlToken
' through a PkgParams buffer.

%SCHANNEL_RENEGOTIATE = 0   ' renegotiate a connection
%SCHANNEL_SHUTDOWN    = 1   ' gracefully close down a connection
%SCHANNEL_ALERT       = 2   ' build an error message
%SCHANNEL_SESSION     = 3   ' session control


' Alert token structure.
TYPE SCHANNEL_ALERT_TOKEN
    dwTokenType   AS DWORD               ' SCHANNEL_ALERT
    dwAlertType   AS DWORD
    dwAlertNumber AS DWORD
END TYPE

' Alert types.
%TLS1_ALERT_WARNING             = 1
%TLS1_ALERT_FATAL               = 2

' Alert messages.
%TLS1_ALERT_CLOSE_NOTIFY        = 0       ' warning
%TLS1_ALERT_UNEXPECTED_MESSAGE  = 10      ' error
%TLS1_ALERT_BAD_RECORD_MAC      = 20      ' error
%TLS1_ALERT_DECRYPTION_FAILED   = 21      ' reserved
%TLS1_ALERT_RECORD_OVERFLOW     = 22      ' error
%TLS1_ALERT_DECOMPRESSION_FAIL  = 30      ' error
%TLS1_ALERT_HANDSHAKE_FAILURE   = 40      ' error
%TLS1_ALERT_BAD_CERTIFICATE     = 42      ' warning or error
%TLS1_ALERT_UNSUPPORTED_CERT    = 43      ' warning or error
%TLS1_ALERT_CERTIFICATE_REVOKED = 44      ' warning or error
%TLS1_ALERT_CERTIFICATE_EXPIRED = 45      ' warning or error
%TLS1_ALERT_CERTIFICATE_UNKNOWN = 46      ' warning or error
%TLS1_ALERT_ILLEGAL_PARAMETER   = 47      ' error
%TLS1_ALERT_UNKNOWN_CA          = 48      ' error
%TLS1_ALERT_ACCESS_DENIED       = 49      ' error
%TLS1_ALERT_DECODE_ERROR        = 50      ' error
%TLS1_ALERT_DECRYPT_ERROR       = 51      ' error
%TLS1_ALERT_EXPORT_RESTRICTION  = 60      ' reserved
%TLS1_ALERT_PROTOCOL_VERSION    = 70      ' error
%TLS1_ALERT_INSUFFIENT_SECURITY = 71      ' error
%TLS1_ALERT_INTERNAL_ERROR      = 80      ' error
%TLS1_ALERT_USER_CANCELED       = 90      ' warning or error
%TLS1_ALERT_NO_RENEGOTIATION    =100      ' warning
%TLS1_ALERT_UNSUPPORTED_EXT     =110      ' error


' Session control flags
%SSL_SESSION_ENABLE_RECONNECTS  = 1
%SSL_SESSION_DISABLE_RECONNECTS = 2

' Session control token structure.
TYPE SCHANNEL_SESSION_TOKEN
    dwTokenType AS DWORD           ' SCHANNEL_SESSION
    dwFlags     AS DWORD
END TYPE


TYPE SCHANNEL_CLIENT_SIGNATURE DWORD FILL
    cbLength           AS DWORD
    aiHash             AS DWORD  ' ALG_ID
    cbHash             AS DWORD
    HashValue(35)      AS BYTE
    CertThumbprint(19) AS BYTE
END TYPE


'
' Flags for identifying the various different protocols.
'

' flag/identifiers for protocols we support
%SP_PROT_PCT1_SERVER         = &H00000001
%SP_PROT_PCT1_CLIENT         = &H00000002
%SP_PROT_PCT1                = (%SP_PROT_PCT1_SERVER OR %SP_PROT_PCT1_CLIENT)

%SP_PROT_SSL2_SERVER         = &H00000004
%SP_PROT_SSL2_CLIENT         = &H00000008
%SP_PROT_SSL2                = (%SP_PROT_SSL2_SERVER OR %SP_PROT_SSL2_CLIENT)

%SP_PROT_SSL3_SERVER         = &H00000010
%SP_PROT_SSL3_CLIENT         = &H00000020
%SP_PROT_SSL3                = (%SP_PROT_SSL3_SERVER OR %SP_PROT_SSL3_CLIENT)

%SP_PROT_TLS1_SERVER         = &H00000040
%SP_PROT_TLS1_CLIENT         = &H00000080
%SP_PROT_TLS1                = (%SP_PROT_TLS1_SERVER OR %SP_PROT_TLS1_CLIENT)

%SP_PROT_SSL3TLS1_CLIENTS    = (%SP_PROT_TLS1_CLIENT OR %SP_PROT_SSL3_CLIENT)
%SP_PROT_SSL3TLS1_SERVERS    = (%SP_PROT_TLS1_SERVER OR %SP_PROT_SSL3_SERVER)
%SP_PROT_SSL3TLS1            = (%SP_PROT_SSL3 OR %SP_PROT_TLS1)

%SP_PROT_UNI_SERVER          = &H40000000
%SP_PROT_UNI_CLIENT          = &H80000000???
%SP_PROT_UNI                 = (%SP_PROT_UNI_SERVER OR %SP_PROT_UNI_CLIENT)

%SP_PROT_ALL                 = &Hffffffff???
%SP_PROT_NONE                = 0
%SP_PROT_CLIENTS             = (%SP_PROT_PCT1_CLIENT OR %SP_PROT_SSL2_CLIENT OR %SP_PROT_SSL3_CLIENT OR %SP_PROT_UNI_CLIENT OR %SP_PROT_TLS1_CLIENT)
%SP_PROT_SERVERS             = (%SP_PROT_PCT1_SERVER OR %SP_PROT_SSL2_SERVER OR %SP_PROT_SSL3_SERVER OR %SP_PROT_UNI_SERVER OR %SP_PROT_TLS1_SERVER)


%SP_PROT_TLS1_0_SERVER       = %SP_PROT_TLS1_SERVER
%SP_PROT_TLS1_0_CLIENT       = %SP_PROT_TLS1_CLIENT
%SP_PROT_TLS1_0              = (%SP_PROT_TLS1_0_SERVER OR _
                                %SP_PROT_TLS1_0_CLIENT)

%SP_PROT_TLS1_1_SERVER       = &H00000100
%SP_PROT_TLS1_1_CLIENT       = &H00000200
%SP_PROT_TLS1_1              = (%SP_PROT_TLS1_1_SERVER OR _
                                %SP_PROT_TLS1_1_CLIENT)

%SP_PROT_TLS1_2_SERVER       = &H00000400
%SP_PROT_TLS1_2_CLIENT       = &H00000800
%SP_PROT_TLS1_2              = (%SP_PROT_TLS1_2_SERVER OR _
                                %SP_PROT_TLS1_2_CLIENT)

%SP_PROT_TLS1_1PLUS_SERVER   = (%SP_PROT_TLS1_1_SERVER OR _
                                %SP_PROT_TLS1_2_SERVER)
%SP_PROT_TLS1_1PLUS_CLIENT   = (%SP_PROT_TLS1_1_CLIENT OR _
                                %SP_PROT_TLS1_2_CLIENT)
%SP_PROT_TLS1_1PLUS          = (%SP_PROT_TLS1_1PLUS_SERVER OR _
                                %SP_PROT_TLS1_1PLUS_CLIENT)

%SP_PROT_TLS1_X_SERVER       = (%SP_PROT_TLS1_0_SERVER OR _
                                %SP_PROT_TLS1_1_SERVER OR _
                                %SP_PROT_TLS1_2_SERVER)
%SP_PROT_TLS1_X_CLIENT       = (%SP_PROT_TLS1_0_CLIENT OR _
                                %SP_PROT_TLS1_1_CLIENT OR _
                                %SP_PROT_TLS1_2_CLIENT)
%SP_PROT_TLS1_X              = (%SP_PROT_TLS1_X_SERVER OR _
                                %SP_PROT_TLS1_X_CLIENT)

%SP_PROT_SSL3TLS1_X_CLIENTS  = (%SP_PROT_TLS1_X_CLIENT OR _
                                %SP_PROT_SSL3_CLIENT)
%SP_PROT_SSL3TLS1_X_SERVERS  = (%SP_PROT_TLS1_X_SERVER OR _
                                %SP_PROT_SSL3_SERVER)
%SP_PROT_SSL3TLS1_X          = (%SP_PROT_SSL3 OR %SP_PROT_TLS1_X)

%SP_PROT_X_CLIENTS           = (%SP_PROT_CLIENTS OR _
                                %SP_PROT_TLS1_X_CLIENT)
%SP_PROT_X_SERVERS           = (%SP_PROT_SERVERS OR _
                                %SP_PROT_TLS1_X_SERVER)

'
' Helper function used to flush the SSL session cache.
'

DECLARE FUNCTION SSL_EMPTY_CACHE_FN_A ( _
    pszTargetName AS ASCIIZ, _
    BYVAL dwFlags AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SslEmptyCacheA LIB "SChannel.dll" ALIAS "SslEmptyCacheA" ( _
    pszTargetName AS ASCIIZ, _
    BYVAL dwFlags AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SSL_EMPTY_CACHE_FN_W ( _
    pszTargetName AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SslEmptyCacheW LIB "SChannel.dll" ALIAS "SslEmptyCacheW" ( _
    pszTargetName AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO SSL_EMPTY_CACHE_FN=SSL_EMPTY_CACHE_FN_W
MACRO SslEmptyCache=SslEmptyCacheW
#ELSE
MACRO SSL_EMPTY_CACHE_FN=SSL_EMPTY_CACHE_FN_A
MACRO SslEmptyCache=SslEmptyCacheA
#ENDIF



' Structures for compatability with the
' NT 4.0 SP2 / IE 3.0 schannel interface, do
' not use.

TYPE SSL_CREDENTIAL_CERTIFICATE
    cbPrivateKey  AS DWORD
    pPrivateKey   AS BYTE PTR
    cbCertificate AS DWORD
    pCertificate  AS BYTE PTR
    pszPassword   AS STRING PTR
END TYPE




' Structures for use with the
' NT 4.0 SP3 Schannel interface,
' do not use.
%SCHANNEL_SECRET_TYPE_CAPI = &H00000001
%SCHANNEL_SECRET_PRIVKEY   = &H00000002
%SCH_CRED_X509_CERTCHAIN   = &H00000001
%SCH_CRED_X509_CAPI        = &H00000002
%SCH_CRED_CERT_CONTEXT     = &H00000003

'struct _HMAPPER;
TYPE SCH_CRED
    dwVersion  AS DWORD  ' always SCH_CRED_VERSION.
    cCreds     AS DWORD  ' Number of credentials.
    paSecret   AS DWORD  ' PVOID PTR  ' Array of SCH_CRED_SECRET_* pointers
    paPublic   AS DWORD  ' PVOID PTR  ' Array of SCH_CRED_PUBLIC_* pointers
    cMappers   AS DWORD  ' Number of credential mappers.
    aphMappers AS DWORD  ' _HMAPPER PTR PTR ' pointer to an array of pointers to credential mappers
END TYPE

' Structures for use with the
' NT 4.0 SP3 Schannel interface,
' do not use.
TYPE SCH_CRED_SECRET_CAPI
    dwType AS DWORD                 ' SCHANNEL_SECRET_TYPE_CAPI
    hProv  AS DWORD  ' HCRYPTPROV   ' credential secret information.
END TYPE


' Structures for use with the
' NT 4.0 SP3 Schannel interface,
' do not use.
TYPE SCH_CRED_SECRET_PRIVKEY
    dwType       AS DWORD            ' SCHANNEL_SECRET_PRIVKEY
    pPrivateKey  AS BYTE PTR         ' Der encoded private key
    cbPrivateKey AS DWORD
    pszPassword  AS STRING PTR       ' Password to crack the private key.
END TYPE


' Structures for use with the
' NT 4.0 SP3 Schannel interface,
' do not use.
TYPE SCH_CRED_PUBLIC_CERTCHAIN
    dwType      AS DWORD
    cbCertChain AS DWORD
    pCertChain  AS BYTE PTR
END TYPE


' Structures needed for Pre NT4.0 SP2 calls.
TYPE PctPublicKey
    Type    AS DWORD
    cbKey   AS DWORD
    pKey(0) AS BYTE
END TYPE

TYPE X509Certificate
    Version            AS DWORD
    SerialNumber(3)    AS DWORD
    SignatureAlgorithm AS DWORD  ' ALG_ID
    ValidFrom          AS FILETIME
    ValidUntil         AS FILETIME
    pszIssuer          AS STRING PTR
    pszSubject         AS STRING PTR
    pPublicKey         AS PctPublicKey PTR
END TYPE



' Pre NT4.0 SP2 calls.  Call CAPI1 or CAPI2
' to get the same functionality instead.
DECLARE FUNCTION SslGenerateKeyPair LIB "SChannel.dll" _
    ALIAS "SslGenerateKeyPair" ( _
    pCerts      AS SSL_CREDENTIAL_CERTIFICATE , _
    pszDN       AS STRING, _
    pszPassword AS STRING, _
    BYVAL Bits  AS DWORD _
    ) AS LONG  ' BOOL

' Pre NT4.0 SP2 calls.  Call CAPI1 or CAPI2
' to get the same functionality instead.
DECLARE SUB SslGenerateRandomBits LIB "SChannel.dll" _
    ALIAS "SslGenerateRandomBits" ( _
    BYVAL pRandomData AS BYTE PTR, _
    BYVAL cRandomData AS LONG _
    )

' Pre NT4.0 SP2 calls.  Call CAPI1 or CAPI2
' to get the same functionality instead.
DECLARE FUNCTION SslCrackCertificate LIB "SChannel.dll" _
    ALIAS "SslCrackCertificate" ( _
    BYVAL pbCertificate AS BYTE PTR, _
    BYVAL cbCertificate AS DWORD, _
    BYVAL dwFlags       AS DWORD, _
    ppCertificate       AS ANY _  ' X509Certificate PTR PTR
    ) AS LONG  ' BOOL

' Pre NT4.0 SP2 calls.  Call CAPI1 or CAPI2
' to get the same functionality instead.
DECLARE SUB SslFreeCertificate LIB "SChannel.dll" _
    ALIAS "SslFreeCertificate" ( _
    pCertificate AS X509Certificate _
    )

DECLARE FUNCTION SslGetMaximumKeySize LIB "SChannel.dll" _
    ALIAS "SslGetMaximumKeySize" ( _
    BYVAL Reserved AS DWORD _
    ) AS DWORD

DECLARE FUNCTION SslGetDefaultIssuers LIB "SChannel.dll" _
    ALIAS "SslGetDefaultIssuers" ( _
    BYVAL pbIssuers AS BYTE PTR, _
    pcbIssuers      AS DWORD _
    ) AS LONG  ' BOOL

$SSL_CRACK_CERTIFICATE_NAME = "SslCrackCertificate"
$SSL_FREE_CERTIFICATE_NAME  = "SslFreeCertificate"
$$SSL_CRACK_CERTIFICATE_NAME = "SslCrackCertificate"$$
$$SSL_FREE_CERTIFICATE_NAME  = "SslFreeCertificate"$$

' Pre NT4.0 SP2 calls.  Call CAPI1 or CAPI2
' to get the same functionality instead.
DECLARE FUNCTION SSL_CRACK_CERTIFICATE_FN ( _
    BYVAL pbCertificate   AS BYTE PTR, _
    BYVAL cbCertificate   AS DWORD, _
    BYVAL VerifySignature AS LONG, _    ' BOOL
    BYVAL ppCertificate   AS DWORD _    ' X509Certificate PTR PTR
    ) AS LONG  ' BOOL


' Pre NT4.0 SP2 calls.  Call CAPI1 or CAPI2
' to get the same functionality instead.
DECLARE SUB SSL_FREE_CERTIFICATE_FN ( _
    pCertificate AS X509Certificate _
    )
