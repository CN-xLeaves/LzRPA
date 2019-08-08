'------------------------------------------------------------------------------
'
'  NCrypt.inc - Cryptographic API Prototypes and Definitions
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from NCrypt.h dated 18 Jan 2008
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%NCRYPT_H = 1


'#IF NOT %DEF(%__SECSTATUS_DEFINED__
'typedef LONG SECURITY_STATUS;
'#define __SECSTATUS_DEFINED__
'#endif

#INCLUDE "BCrypt.inc"


'
' Microsoft built-in providers.
'

$$MS_KEY_STORAGE_PROVIDER            = "Microsoft Software Key Storage Provider"$$
$$MS_SMART_CARD_KEY_STORAGE_PROVIDER = "Microsoft Smart Card Key Storage Provider"$$

'
' Common algorithm identifiers.
'

$$NCRYPT_RSA_ALGORITHM          = $$BCRYPT_RSA_ALGORITHM
$$NCRYPT_RSA_SIGN_ALGORITHM     = $$BCRYPT_RSA_SIGN_ALGORITHM
$$NCRYPT_DH_ALGORITHM           = $$BCRYPT_DH_ALGORITHM
$$NCRYPT_DSA_ALGORITHM          = $$BCRYPT_DSA_ALGORITHM
$$NCRYPT_MD2_ALGORITHM          = $$BCRYPT_MD2_ALGORITHM
$$NCRYPT_MD4_ALGORITHM          = $$BCRYPT_MD4_ALGORITHM
$$NCRYPT_MD5_ALGORITHM          = $$BCRYPT_MD5_ALGORITHM
$$NCRYPT_SHA1_ALGORITHM         = $$BCRYPT_SHA1_ALGORITHM
$$NCRYPT_SHA256_ALGORITHM       = $$BCRYPT_SHA256_ALGORITHM
$$NCRYPT_SHA384_ALGORITHM       = $$BCRYPT_SHA384_ALGORITHM
$$NCRYPT_SHA512_ALGORITHM       = $$BCRYPT_SHA512_ALGORITHM
$$NCRYPT_ECDSA_P256_ALGORITHM   = $$BCRYPT_ECDSA_P256_ALGORITHM
$$NCRYPT_ECDSA_P384_ALGORITHM   = $$BCRYPT_ECDSA_P384_ALGORITHM
$$NCRYPT_ECDSA_P521_ALGORITHM   = $$BCRYPT_ECDSA_P521_ALGORITHM
$$NCRYPT_ECDH_P256_ALGORITHM    = $$BCRYPT_ECDH_P256_ALGORITHM
$$NCRYPT_ECDH_P384_ALGORITHM    = $$BCRYPT_ECDH_P384_ALGORITHM
$$NCRYPT_ECDH_P521_ALGORITHM    = $$BCRYPT_ECDH_P521_ALGORITHM

$$NCRYPT_KEY_STORAGE_ALGORITHM  = "KEY_STORAGE"$$

'
' Interfaces
'

%NCRYPT_HASH_INTERFACE                  = %BCRYPT_HASH_INTERFACE
%NCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE = %BCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE

%NCRYPT_SECRET_AGREEMENT_INTERFACE      = %BCRYPT_SECRET_AGREEMENT_INTERFACE

%NCRYPT_SIGNATURE_INTERFACE             = %BCRYPT_SIGNATURE_INTERFACE

%NCRYPT_KEY_STORAGE_INTERFACE           = &H00010001
%NCRYPT_SCHANNEL_INTERFACE              = &H00010002

'
' algorithm groups.
'

$$NCRYPT_RSA_ALGORITHM_GROUP    = $$NCRYPT_RSA_ALGORITHM
$$NCRYPT_DH_ALGORITHM_GROUP     = $$NCRYPT_DH_ALGORITHM
$$NCRYPT_DSA_ALGORITHM_GROUP    = $$NCRYPT_DSA_ALGORITHM
$$NCRYPT_ECDSA_ALGORITHM_GROUP  = "ECDSA"$$
$$NCRYPT_ECDH_ALGORITHM_GROUP   = "ECDH"$$

'
' NCrypt generic memory descriptors
'

%NCRYPTBUFFER_VERSION              = 0

%NCRYPTBUFFER_EMPTY                = 0
%NCRYPTBUFFER_DATA                 = 1
%NCRYPTBUFFER_SSL_CLIENT_RANDOM    = 20
%NCRYPTBUFFER_SSL_SERVER_RANDOM    = 21
%NCRYPTBUFFER_SSL_HIGHEST_VERSION  = 22
%NCRYPTBUFFER_SSL_CLEAR_KEY        = 23
%NCRYPTBUFFER_SSL_KEY_ARG_DATA     = 24

%NCRYPTBUFFER_PKCS_OID             = 40
%NCRYPTBUFFER_PKCS_ALG_OID         = 41
%NCRYPTBUFFER_PKCS_ALG_PARAM       = 42
%NCRYPTBUFFER_PKCS_ALG_ID          = 43
%NCRYPTBUFFER_PKCS_ATTRS           = 44
%NCRYPTBUFFER_PKCS_KEY_NAME        = 45
%NCRYPTBUFFER_PKCS_SECRET          = 46

%NCRYPTBUFFER_CERT_BLOB            = 47

' NCRYPT shares the same BCRYPT definitions
TYPE NCryptBuffer
    BCryptBuffer
END TYPE

TYPE NCryptBufferDesc
    BCryptBufferDesc
END TYPE

'
' NCrypt handles
'

MACRO NCRYPT_HANDLE=DWORD
MACRO NCRYPT_PROV_HANDLE=DWORD
MACRO NCRYPT_KEY_HANDLE=DWORD
MACRO NCRYPT_HASH_HANDLE=DWORD
MACRO NCRYPT_SECRET_HANDLE=DWORD


'
' NCrypt API Flags
'

%NCRYPT_NO_PADDING_FLAG     = %BCRYPT_PAD_NONE
%NCRYPT_PAD_PKCS1_FLAG      = %BCRYPT_PAD_PKCS1  ' NCryptEncrypt/Decrypt NCryptSignHash/VerifySignature
%NCRYPT_PAD_OAEP_FLAG       = %BCRYPT_PAD_OAEP   ' BCryptEncrypt/Decrypt
%NCRYPT_PAD_PSS_FLAG        = %BCRYPT_PAD_PSS    ' BCryptSignHash/VerifySignature
%NCRYPT_NO_KEY_VALIDATION   = %BCRYPT_NO_KEY_VALIDATION
%NCRYPT_MACHINE_KEY_FLAG                = &H00000020  ' same as CAPI CRYPT_MACHINE_KEYSET
%NCRYPT_SILENT_FLAG                     = &H00000040  ' same as CAPI CRYPT_SILENT
%NCRYPT_OVERWRITE_KEY_FLAG              = &H00000080
%NCRYPT_WRITE_KEY_TO_LEGACY_STORE_FLAG  = &H00000200
%NCRYPT_DO_NOT_FINALIZE_FLAG            = &H00000400
%NCRYPT_PERSIST_ONLY_FLAG               = &H40000000
%NCRYPT_PERSIST_FLAG                    = &H80000000???
%NCRYPT_REGISTER_NOTIFY_FLAG            = &H00000001
%NCRYPT_UNREGISTER_NOTIFY_FLAG          = &H00000002


'
' Functions used to manage persisted keys.
'

DECLARE FUNCTION NCryptOpenStorageProvider LIB "NCrypt.dll" _
    ALIAS "NCryptOpenStorageProvider" (phProvider AS DWORD, _
    pszProviderName AS WSTRINGZ, BYVAL dwFlags AS DWORD) AS LONG


' AlgOperations flags for use with NCryptEnumAlgorithms()
%NCRYPT_CIPHER_OPERATION                = %BCRYPT_CIPHER_OPERATION
%NCRYPT_HASH_OPERATION                  = %BCRYPT_HASH_OPERATION
%NCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION = %BCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION
%NCRYPT_SECRET_AGREEMENT_OPERATION      = %BCRYPT_SECRET_AGREEMENT_OPERATION
%NCRYPT_SIGNATURE_OPERATION             = %BCRYPT_SIGNATURE_OPERATION
%NCRYPT_RNG_OPERATION                   = %BCRYPT_RNG_OPERATION

' USE EXTREME CAUTION: editing comments that contain "certenrolls_*" tokens
' could break building CertEnroll idl files:
' certenrolls_begin -- NCryptAlgorithmName
TYPE NCryptAlgorithmName
    pszName         AS WSTRINGZ PTR
    dwClass         AS DWORD    ' the CNG interface that supports this algorithm
    dwAlgOperations AS DWORD    ' the types of operations supported by this algorithm
    dwFlags         AS DWORD
END TYPE
' certenrolls_end

DECLARE FUNCTION NCryptEnumAlgorithms LIB "NCrypt.dll" _
    ALIAS "NCryptEnumAlgorithms" (hProvider AS DWORD, _
    BYVAL dwAlgOperations AS DWORD, pdwAlgCount AS DWORD, _
    ppAlgList AS ANY, BYVAL dwFlags AS DWORD) AS LONG


DECLARE FUNCTION NCryptIsAlgSupported LIB "NCrypt.dll" _
    ALIAS "NCryptIsAlgSupported" (hProvider AS DWORD, pszAlgId AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD) AS LONG



' NCryptEnumKeys flags
%NCRYPT_MACHINE_KEY_FLAG       = &H00000020

TYPE NCryptKeyName
    pszName         AS WSTRINGZ PTR
    pszAlgid        AS WSTRINGZ PTR
    dwLegacyKeySpec AS DWORD
    dwFlags         AS DWORD
END TYPE

DECLARE FUNCTION NCryptEnumKeys LIB "NCrypt.dll" ALIAS "NCryptEnumKeys" _
    (hProvider AS DWORD, pszScope AS WSTRINGZ, ppKeyName AS ANY, _
    ppEnumState AS DWORD, BYVAL dwFlags AS DWORD) AS LONG



TYPE NCryptProviderName
    pszName    AS WSTRINGZ PTR
    pszComment AS WSTRINGZ PTR
END TYPE

DECLARE FUNCTION NCryptEnumStorageProviders LIB "NCrypt.dll" _
    ALIAS "NCryptEnumStorageProviders" (pdwProviderCount AS DWORD, _
    ppProviderList AS ANY, BYVAL dwFlags AS DWORD) AS LONG



DECLARE FUNCTION NCryptFreeBuffer LIB "NCrypt.dll" ALIAS "NCryptFreeBuffer" _
    (pvInput AS DWORD) AS LONG


' NCryptOpenKey flags
%NCRYPT_MACHINE_KEY_FLAG       = &H00000020
%NCRYPT_SILENT_FLAG            = &H00000040

DECLARE FUNCTION NCryptOpenKey LIB "NCrypt.dll" ALIAS "NCryptOpenKey" _
    (BYVAL hProvider AS DWORD, phKey AS DWORD, pszKeyName AS WSTRINGZ, _
    BYVAL dwLegacyKeySpec AS DWORD, BYVAL dwFlags AS DWORD) AS LONG



' NCryptCreatePersistedKey flags
%NCRYPT_MACHINE_KEY_FLAG       = &H00000020
%NCRYPT_OVERWRITE_KEY_FLAG     = &H00000080

DECLARE FUNCTION NCryptCreatePersistedKey LIB "NCrypt.dll" _
    ALIAS "NCryptCreatePersistedKey" (BYVAL hProvider AS DWORD, _
    phKey AS DWORD, pszAlgId AS WSTRINGZ, pszKeyName AS WSTRINGZ, _
    BYVAL dwLegacyKeySpec AS DWORD, BYVAL dwFlags AS DWORD) AS LONG



' Standard property names.
$$NCRYPT_NAME_PROPERTY                    = "Name"$$
$$NCRYPT_UNIQUE_NAME_PROPERTY             = "Unique Name"$$
$$NCRYPT_ALGORITHM_PROPERTY               = "Algorithm Name"$$
$$NCRYPT_LENGTH_PROPERTY                  = "Length"$$
$$NCRYPT_LENGTHS_PROPERTY                 = "Lengths"$$
$$NCRYPT_BLOCK_LENGTH_PROPERTY            = "Block Length"$$
$$NCRYPT_UI_POLICY_PROPERTY               = "UI Policy"$$
$$NCRYPT_EXPORT_POLICY_PROPERTY           = "Export Policy"$$
$$NCRYPT_WINDOW_HANDLE_PROPERTY           = "HWND Handle"$$
$$NCRYPT_USE_CONTEXT_PROPERTY             = "Use Context"$$
$$NCRYPT_IMPL_TYPE_PROPERTY               = "Impl Type"$$
$$NCRYPT_KEY_USAGE_PROPERTY               = "Key Usage"$$
$$NCRYPT_KEY_TYPE_PROPERTY                = "Key Type"$$
$$NCRYPT_VERSION_PROPERTY                 = "Version"$$
$$NCRYPT_SECURITY_DESCR_SUPPORT_PROPERTY  = "Security Descr Support"$$
$$NCRYPT_SECURITY_DESCR_PROPERTY          = "Security Descr"$$
$$NCRYPT_USE_COUNT_ENABLED_PROPERTY       = "Enabled Use Count"$$
$$NCRYPT_USE_COUNT_PROPERTY               = "Use Count"$$
$$NCRYPT_LAST_MODIFIED_PROPERTY           = "Modified"$$
$$NCRYPT_MAX_NAME_LENGTH_PROPERTY         = "Max Name Length"$$
$$NCRYPT_ALGORITHM_GROUP_PROPERTY         = "Algorithm Group"$$
$$NCRYPT_DH_PARAMETERS_PROPERTY           = $$BCRYPT_DH_PARAMETERS
$$NCRYPT_PROVIDER_HANDLE_PROPERTY         = "Provider Handle"$$
$$NCRYPT_PIN_PROPERTY                     = "SmartCardPin"$$
$$NCRYPT_READER_PROPERTY                  = "SmartCardReader"$$
$$NCRYPT_SMARTCARD_GUID_PROPERTY          = "SmartCardGuid"$$
$$NCRYPT_CERTIFICATE_PROPERTY             = "SmartCardKeyCertificate"$$
$$NCRYPT_PIN_PROMPT_PROPERTY              = "SmartCardPinPrompt"$$
$$NCRYPT_USER_CERTSTORE_PROPERTY          = "SmartCardUserCertStore"$$
$$NCRYPT_ROOT_CERTSTORE_PROPERTY          = "SmartcardRootCertStore"$$
$$NCRYPT_SECURE_PIN_PROPERTY              = "SmartCardSecurePin"$$

' Maximum length of property name (in characters)
%NCRYPT_MAX_PROPERTY_NAME      = 64

' Maximum length of property data (in bytes)
%NCRYPT_MAX_PROPERTY_DATA       = &H100000

' NCRYPT_EXPORT_POLICY_PROPERTY property flags.
%NCRYPT_ALLOW_EXPORT_FLAG               = &H00000001
%NCRYPT_ALLOW_PLAINTEXT_EXPORT_FLAG     = &H00000002
%NCRYPT_ALLOW_ARCHIVING_FLAG            = &H00000004
%NCRYPT_ALLOW_PLAINTEXT_ARCHIVING_FLAG  = &H00000008

' NCRYPT_IMPL_TYPE_PROPERTY property flags.
%NCRYPT_IMPL_HARDWARE_FLAG              = &H00000001
%NCRYPT_IMPL_SOFTWARE_FLAG              = &H00000002
%NCRYPT_IMPL_REMOVABLE_FLAG             = &H00000008
%NCRYPT_IMPL_HARDWARE_RNG_FLAG          = &H00000010

' NCRYPT_KEY_USAGE_PROPERTY property flags.
%NCRYPT_ALLOW_DECRYPT_FLAG              = &H00000001
%NCRYPT_ALLOW_SIGNING_FLAG              = &H00000002
%NCRYPT_ALLOW_KEY_AGREEMENT_FLAG        = &H00000004
%NCRYPT_ALLOW_ALL_USAGES                = &H00ffffff

' NCRYPT_UI_POLICY_PROPERTY property flags and structure
%NCRYPT_UI_PROTECT_KEY_FLAG             = &H00000001
%NCRYPT_UI_FORCE_HIGH_PROTECTION_FLAG   = &H00000002

TYPE NCRYPT_UI_POLICY_BLOB
    dwVersion       AS DWORD
    dwFlags         AS DWORD
    cbCreationTitle AS DWORD
    cbFriendlyName  AS DWORD
    cbDescription   AS DWORD
    ' creation title string
    ' friendly name string
    ' description string
END TYPE

TYPE NCRYPT_UI_POLICY
    dwVersion        AS DWORD
    dwFlags          AS DWORD
    pszCreationTitle AS WSTRINGZ PTR
    pszFriendlyName  AS WSTRINGZ PTR
    pszDescription   AS WSTRINGZ PTR
END TYPE


' NCRYPT_LENGTHS_PROPERTY property structure.
TYPE NCRYPT_SUPPORTED_LENGTHS
    dwMinLength     AS DWORD
    dwMaxLength     AS DWORD
    dwIncrement     AS DWORD
    dwDefaultLength AS DWORD
END TYPE

' NCryptGetProperty flags
%NCRYPT_PERSIST_ONLY_FLAG      = &H40000000

DECLARE FUNCTION NCryptGetProperty LIB "NCrypt.dll" ALIAS "NCryptGetProperty" _
    (BYVAL hObject AS DWORD, pszProperty AS WSTRINGZ, _
    BYVAL pbOutput AS BYTE PTR, BYVAL cbOutput AS DWORD, pcbResult AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG



' NCryptSetProperty flags
%NCRYPT_PERSIST_FLAG           = &H80000000???
%NCRYPT_PERSIST_ONLY_FLAG      = &H40000000

DECLARE FUNCTION NCryptSetProperty LIB "NCrypt.dll" ALIAS "NCryptSetProperty" _
    (BYVAL hObject AS DWORD, pszProperty AS WSTRINGZ, _
    BYVAL pbInput AS BYTE PTR, BYVAL cbInput AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG



%NCRYPT_WRITE_KEY_TO_LEGACY_STORE_FLAG = &H00000200

DECLARE FUNCTION NCryptFinalizeKey LIB "NCrypt.dll" ALIAS "NCryptFinalizeKey" _
    (BYVAL hKey AS DWORD, BYVAL dwFlags AS DWORD) AS LONG



DECLARE FUNCTION NCryptEncrypt LIB "NCrypt.dll" ALIAS "NCryptEncrypt" _
    (BYVAL hKey AS DWORD, BYVAL pbInput AS BYTE PTR, BYVAL cbInput AS DWORD, _
    pPaddingInfo AS DWORD, BYVAL pbOutput AS BYTE PTR, _
    BYVAL cbOutput AS DWORD, pcbResult AS DWORD, BYVAL dwFlags AS DWORD) _
    AS LONG



DECLARE FUNCTION NCryptDecrypt LIB "NCrypt.dll" ALIAS "NCryptDecrypt" _
     (BYVAL hKey AS DWORD, BYVAL pbInput AS BYTE PTR, cbInput AS DWORD, _
     pPaddingInfo AS DWORD, BYVAL pbOutput AS BYTE PTR, _
     BYVAL cbOutput AS DWORD, pcbResult AS DWORD, BYVAL dwFlags AS DWORD) _
     AS LONG


$$NCRYPT_PKCS7_ENVELOPE_BLOB     = "PKCS7_ENVELOPE"$$
$$NCRYPT_PKCS8_PRIVATE_KEY_BLOB  = "PKCS8_PRIVATEKEY"$$
$$NCRYPT_OPAQUETRANSPORT_BLOB    = "OpaqueTransport"$$

%NCRYPT_MACHINE_KEY_FLAG       = &H00000020
%NCRYPT_DO_NOT_FINALIZE_FLAG   = &H00000400
%NCRYPT_EXPORT_LEGACY_FLAG     = &H00000800

DECLARE FUNCTION NCryptImportKey LIB "NCrypt.dll" ALIAS "NCryptImportKey" _
    (BYVAL hProvider AS DWORD, BYVAL hImportKey AS DWORD, _
    pszBlobType AS WSTRINGZ, pParameterList AS NCryptBufferDesc, _
    phKey AS DWORD, BYVAL pbData AS BYTE PTR, BYVAL cbData AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG



DECLARE FUNCTION NCryptExportKey LIB "NCrypt.dll" ALIAS "NCryptExportKey" _
    (BYVAL hKey AS DWORD, BYVAL hExportKey AS DWORD, pszBlobType AS WSTRINGZ, _
    pParameterList AS NCryptBufferDesc, BYVAL pbOutput AS BYTE PTR, _
    BYVAL cbOutput AS DWORD, pcbResult AS DWORD, BYVAL dwFlags AS DWORD) _
    AS LONG



DECLARE FUNCTION NCryptSignHash LIB "NCrypt.dll" ALIAS "NCryptSignHash" _
    (BYVAL hKey AS DWORD, pPaddingInfo AS DWORD, _
    BYVAL pbHashValue AS BYTE PTR, BYVAL cbHashValue AS DWORD, _
    BYVAL pbSignature AS BYTE PTR, BYVAL cbSignature AS DWORD, _
    pcbResult AS DWORD, BYVAL dwFlags AS DWORD) AS LONG



DECLARE FUNCTION NCryptVerifySignature LIB "NCrypt.dll" _
    ALIAS "NCryptVerifySignature" (BYVAL hKey AS DWORD, _
    pPaddingInfo AS DWORD, BYVAL pbHashValue AS DWORD, _
    BYVAL cbHashValue AS DWORD, BYVAL pbSignature AS BYTE PTR, _
    BYVAL cbSignature AS DWORD, BYVAL dwFlags AS DWORD) AS LONG



DECLARE FUNCTION NCryptDeleteKey LIB "NCrypt.dll" ALIAS "NCryptDeleteKey" _
    (BYVAL hKey AS DWORD, BYVAL dwFlags AS DWORD) AS LONG



DECLARE FUNCTION NCryptFreeObject LIB "NCrypt.dll" ALIAS "NCryptFreeObject" _
    (BYVAL hObject AS DWORD) AS LONG



DECLARE FUNCTION NCryptIsKeyHandle LIB "NCrypt.dll" ALIAS "NCryptIsKeyHandle" _
    (BYVAL hKey AS DWORD) AS LONG

DECLARE FUNCTION NCryptTranslateHandle LIB "NCrypt.dll" _
    ALIAS "NCryptTranslateHandle" (phProvider AS DWORD, phKey AS DWORD, _
    BYVAL hLegacyProv AS DWORD, BYVAL hLegacyKey AS DWORD, _
    BYVAL dwLegacyKeySpec AS DWORD, BYVAL dwFlags AS DWORD) AS LONG



' NCryptNotifyChangeKey flags
%NCRYPT_REGISTER_NOTIFY_FLAG   = &H00000001
%NCRYPT_UNREGISTER_NOTIFY_FLAG = &H00000002
%NCRYPT_MACHINE_KEY_FLAG       = &H00000020

DECLARE FUNCTION NCryptNotifyChangeKey LIB "NCrypt.dll" _
    ALIAS "NCryptNotifyChangeKey" (BYVAL hProvider AS DWORD, _
    phEvent AS DWORD, BYVAL dwFlags AS DWORD) AS LONG



DECLARE FUNCTION NCryptSecretAgreement LIB "NCrypt.dll" _
    ALIAS "NCryptSecretAgreement" (BYVAL hPrivKey AS DWORD, _
    BYVAL hPubKey AS DWORD, phAgreedSecret AS DWORD, BYVAL dwFlags AS DWORD) _
    AS LONG



DECLARE FUNCTION NCryptDeriveKey LIB "NCrypt.dll" ALIAS "NCryptDeriveKey" _
    (BYVAL hSharedSecret AS DWORD, pwszKDF AS WSTRINGZ, _
    pParameterList AS DWORD, BYVAL pbDerivedKey AS BYTE PTR, _
    BYVAL cbDerivedKey AS DWORD, pcbResult AS DWORD, BYVAL dwFlags AS DWORD) _
    AS LONG



%NCRYPT_KEY_STORAGE_INTERFACE_VERSION = &H00000001 ' BCRYPT_MAKE_INTERFACE_VERSION(1,0)
