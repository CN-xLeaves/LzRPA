'------------------------------------------------------------------------------
'
'  BCrypt.inc - Cryptographic Primitive API Prototypes and Definitions
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from BCrypt.h dated 18 Jan 2008
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%BCRYPT_H = 1


'
'  Alignment macros
'


'
' DeriveKey KDF Types
'
$$BCRYPT_KDF_HASH     = "HASH"$$
$$BCRYPT_KDF_HMAC     = "HMAC"$$
$$BCRYPT_KDF_TLS_PRF  = "TLS_PRF"$$

'
' DeriveKey KDF BufferTypes
'
' For BCRYPT_KDF_HASH and BCRYPT_KDF_HMAC operations, there may be an arbitrary
' number of KDF_SECRET_PREPEND and KDF_SECRET_APPEND buffertypes in the
' parameter list.  The BufferTypes are processed in order of appearence
' within the parameter list.
'
%KDF_HASH_ALGORITHM  = &H0
%KDF_SECRET_PREPEND  = &H1
%KDF_SECRET_APPEND   = &H2
%KDF_HMAC_KEY        = &H3
%KDF_TLS_PRF_LABEL   = &H4
%KDF_TLS_PRF_SEED    = &H5
%KDF_SECRET_HANDLE   = &H6

'
' DeriveKey Flags:
'
' KDF_USE_SECRET_AS_HMAC_KEY_FLAG causes the secret agreement to serve also
' as the HMAC key.  If this flag is used, the KDF_HMAC_KEY parameter should
' NOT be specified.
'
%KDF_USE_SECRET_AS_HMAC_KEY_FLAG = &H1

'
' BCrypt structs
'

TYPE BCRYPT_KEY_LENGTHS_STRUCT
    dwMinLength AS DWORD
    dwMaxLength AS DWORD
    dwIncrement AS DWORD
END TYPE

TYPE  BCRYPT_AUTH_TAG_LENGTHS_STRUCT
    BCRYPT_KEY_LENGTHS_STRUCT
END TYPE

TYPE BCRYPT_OID
    cbOID AS DWORD
    pbOID AS BYTE PTR
END TYPE

TYPE BCRYPT_OID_LIST
    dwOIDCount AS DWORD
    pOIDs      AS BCRYPT_OID PTR
END TYPE

TYPE BCRYPT_PKCS1_PADDING_INFO
    pszAlgId AS WSTRINGZ PTR
END TYPE

TYPE BCRYPT_PSS_PADDING_INFO
    pszAlgId AS WSTRINGZ PTR
    cbSalt   AS DWORD
END TYPE

TYPE BCRYPT_OAEP_PADDING_INFO
    pszAlgId AS WSTRINGZ PTR
    pbLabel  AS BYTE PTR
    cbLabel  AS DWORD
END TYPE

%BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO_VERSION = 1

%BCRYPT_AUTH_MODE_CHAIN_CALLS_FLAG   = &H00000001
%BCRYPT_AUTH_MODE_IN_PROGRESS_FLAG   = &H00000002

TYPE BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO
    cbSize        AS DWORD
    dwInfoVersion AS DWORD
    pbNonce       AS BYTE PTR
    cbNonce       AS DWORD
    pbAuthData    AS BYTE PTR
    cbAuthData    AS DWORD
    pbTag         AS BYTE PTR
    cbTag         AS DWORD
    pbMacContext  AS BYTE PTR
    cbMacContext  AS DWORD
    cbAAD         AS DWORD
    cbData        AS QUAD
    dwFlags       AS DWORD
END TYPE

MACRO BCRYPT_INIT_AUTH_MODE_INFO(AUTH_INFO_STRUCT)
    MACROTEMP bacmi
    LOCAL bacmi AS BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO
    LSET AUTH_INFO_STRUCT = STRING$(SIZEOF(AUTH_INFO_STRUCT), 0)
    AUTH_INFO_STRUCT.cbSize = SIZEOF(bacmi)
    AUTH_INFO_STRUCT.dwInfoVersion = %BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO_VERSION
END MACRO

'
' BCrypt String Properties
'

' BCrypt(Import/Export)Key BLOB types
$$BCRYPT_OPAQUE_KEY_BLOB     = "OpaqueKeyBlob"$$
$$BCRYPT_KEY_DATA_BLOB       = "KeyDataBlob"$$

' BCryptGetProperty strings
$$BCRYPT_OBJECT_LENGTH       = "ObjectLength"$$
$$BCRYPT_ALGORITHM_NAME      = "AlgorithmName"$$
$$BCRYPT_PROVIDER_HANDLE     = "ProviderHandle"$$
$$BCRYPT_CHAINING_MODE       = "ChainingMode"$$
$$BCRYPT_BLOCK_LENGTH        = "BlockLength"$$
$$BCRYPT_KEY_LENGTH          = "KeyLength"$$
$$BCRYPT_KEY_OBJECT_LENGTH   = "KeyObjectLength"$$
$$BCRYPT_KEY_STRENGTH        = "KeyStrength"$$
$$BCRYPT_KEY_LENGTHS         = "KeyLengths"$$
$$BCRYPT_BLOCK_SIZE_LIST     = "BlockSizeList"$$
$$BCRYPT_EFFECTIVE_KEY_LENGTH= "EffectiveKeyLength"$$
$$BCRYPT_HASH_LENGTH         = "HashDigestLength"$$
$$BCRYPT_HASH_OID_LIST       = "HashOIDList"$$
$$BCRYPT_PADDING_SCHEMES     = "PaddingSchemes"$$
$$BCRYPT_SIGNATURE_LENGTH    = "SignatureLength"$$
$$BCRYPT_HASH_BLOCK_LENGTH   = "HashBlockLength"$$
$$BCRYPT_AUTH_TAG_LENGTH     = "AuthTagLength"$$

' BCryptSetProperty strings
$$BCRYPT_INITIALIZATION_VECTOR   = "IV"$$


' Property Strings
$$BCRYPT_CHAIN_MODE_NA       = "ChainingModeN/A"$$
$$BCRYPT_CHAIN_MODE_CBC      = "ChainingModeCBC"$$
$$BCRYPT_CHAIN_MODE_ECB      = "ChainingModeECB"$$
$$BCRYPT_CHAIN_MODE_CFB      = "ChainingModeCFB"$$
$$BCRYPT_CHAIN_MODE_CCM      = "ChainingModeCCM"$$
$$BCRYPT_CHAIN_MODE_GCM      = "ChainingModeGCM"$$

' Supported RSA Padding Types
%BCRYPT_SUPPORTED_PAD_ROUTER     = &H00000001
%BCRYPT_SUPPORTED_PAD_PKCS1_ENC  = &H00000002
%BCRYPT_SUPPORTED_PAD_PKCS1_SIG  = &H00000004
%BCRYPT_SUPPORTED_PAD_OAEP       = &H00000008
%BCRYPT_SUPPORTED_PAD_PSS        = &H00000010

'
'      BCrypt Flags
'

%BCRYPT_PROV_DISPATCH        = &H00000001  ' BCryptOpenAlgorithmProvider

%BCRYPT_BLOCK_PADDING        = &H00000001  ' BCryptEncrypt/Decrypt

' RSA padding schemes
%BCRYPT_PAD_NONE             = &H00000001
%BCRYPT_PAD_PKCS1            = &H00000002  ' BCryptEncrypt/Decrypt BCryptSignHash/VerifySignature
%BCRYPT_PAD_OAEP             = &H00000004  ' BCryptEncrypt/Decrypt
%BCRYPT_PAD_PSS              = &H00000008  ' BCryptSignHash/VerifySignature


%BCRYPTBUFFER_VERSION        = 0

TYPE BCryptBuffer
    cbBuffer   AS DWORD          ' Length of buffer, in bytes
    BufferType AS DWORD          ' Buffer type
    pvBuffer   AS DWORD  ' PVOID ' Pointer to buffer
END TYPE

TYPE BCryptBufferDesc
    ulVersion AS DWORD            ' Version number
    cBuffers  AS DWORD            ' Number of buffers
    pBuffers  AS BCryptBuffer PTR ' Pointer to array of buffers
END TYPE


'
' Primitive handles
'

MACRO BCRYPT_HANDLE=DWORD
MACRO BCRYPT_ALG_HANDLE=DWORD
MACRO BCRYPT_KEY_HANDLE=DWORD
MACRO BCRYPT_HASH_HANDLE=DWORD
MACRO BCRYPT_SECRET_HANDLE=DWORD


'
' Structures used to represent key blobs.
'

$$BCRYPT_PUBLIC_KEY_BLOB     = "PUBLICBLOB"$$
$$BCRYPT_PRIVATE_KEY_BLOB    = "PRIVATEBLOB"$$

TYPE BCRYPT_KEY_BLOB
    Magic AS DWORD
END TYPE

' The BCRYPT_RSAPUBLIC_BLOB and BCRYPT_RSAPRIVATE_BLOB blob types are used
' to transport plaintext RSA keys. These blob types will be supported by
' all RSA primitive providers.
' The BCRYPT_RSAPRIVATE_BLOB includes the following values:
' Public Exponent
' Modulus
' Prime1
' Prime2

$$BCRYPT_RSAPUBLIC_BLOB     = "RSAPUBLICBLOB"$$
$$BCRYPT_RSAPRIVATE_BLOB    = "RSAPRIVATEBLOB"$$
$$LEGACY_RSAPUBLIC_BLOB     = "CAPIPUBLICBLOB"$$
$$LEGACY_RSAPRIVATE_BLOB    = "CAPIPRIVATEBLOB"$$

%BCRYPT_RSAPUBLIC_MAGIC     = &H31415352  ' RSA1
%BCRYPT_RSAPRIVATE_MAGIC    = &H32415352  ' RSA2

TYPE BCRYPT_RSAKEY_BLOB
    Magic       AS DWORD
    BitLength   AS DWORD
    cbPublicExp AS DWORD
    cbModulus   AS DWORD
    cbPrime1    AS DWORD
    cbPrime2    AS DWORD
END TYPE

' The BCRYPT_RSAFULLPRIVATE_BLOB blob type is used to transport
' plaintext private RSA keys.  It includes the following values:
' Public Exponent
' Modulus
' Prime1
' Prime2
' Private Exponent mod (Prime1 - 1)
' Private Exponent mod (Prime2 - 1)
' Inverse of Prime2 mod Prime1
' PrivateExponent
$$BCRYPT_RSAFULLPRIVATE_BLOB    = "RSAFULLPRIVATEBLOB"$$

%BCRYPT_RSAFULLPRIVATE_MAGIC    = &H33415352  ' RSA3

' The BCRYPT_ECCPUBLIC_BLOB and BCRYPT_ECCPRIVATE_BLOB blob types are used
' to transport plaintext ECC keys. These blob types will be supported by
' all ECC primitive providers.
$$BCRYPT_ECCPUBLIC_BLOB       = "ECCPUBLICBLOB"$$
$$BCRYPT_ECCPRIVATE_BLOB      = "ECCPRIVATEBLOB"$$

%BCRYPT_ECDH_PUBLIC_P256_MAGIC   = &H314B4345  ' ECK1
%BCRYPT_ECDH_PRIVATE_P256_MAGIC  = &H324B4345  ' ECK2
%BCRYPT_ECDH_PUBLIC_P384_MAGIC   = &H334B4345  ' ECK3
%BCRYPT_ECDH_PRIVATE_P384_MAGIC  = &H344B4345  ' ECK4
%BCRYPT_ECDH_PUBLIC_P521_MAGIC   = &H354B4345  ' ECK5
%BCRYPT_ECDH_PRIVATE_P521_MAGIC  = &H364B4345  ' ECK6

%BCRYPT_ECDSA_PUBLIC_P256_MAGIC  = &H31534345  ' ECS1
%BCRYPT_ECDSA_PRIVATE_P256_MAGIC = &H32534345  ' ECS2
%BCRYPT_ECDSA_PUBLIC_P384_MAGIC  = &H33534345  ' ECS3
%BCRYPT_ECDSA_PRIVATE_P384_MAGIC = &H34534345  ' ECS4
%BCRYPT_ECDSA_PUBLIC_P521_MAGIC  = &H35534345  ' ECS5
%BCRYPT_ECDSA_PRIVATE_P521_MAGIC = &H36534345  ' ECS6

TYPE BCRYPT_ECCKEY_BLOB
    dwMagic AS DWORD
    cbKey   AS DWORD
END TYPE

' The BCRYPT_DH_PUBLIC_BLOB and BCRYPT_DH_PRIVATE_BLOB blob types are used
' to transport plaintext DH keys. These blob types will be supported by
' all DH primitive providers.
$$BCRYPT_DH_PUBLIC_BLOB          = "DHPUBLICBLOB"$$
$$BCRYPT_DH_PRIVATE_BLOB         = "DHPRIVATEBLOB"$$
$$LEGACY_DH_PUBLIC_BLOB          = "CAPIDHPUBLICBLOB"$$
$$LEGACY_DH_PRIVATE_BLOB         = "CAPIDHPRIVATEBLOB"$$

%BCRYPT_DH_PUBLIC_MAGIC          = &H42504844  ' DHPB
%BCRYPT_DH_PRIVATE_MAGIC         = &H56504844  ' DHPV

TYPE BCRYPT_DH_KEY_BLOB
    dwMagic AS DWORD
    cbKey   AS DWORD
END TYPE

' Property Strings for DH
$$BCRYPT_DH_PARAMETERS           = "DHParameters"$$

%BCRYPT_DH_PARAMETERS_MAGIC      = &H4d504844  ' DHPM

TYPE BCRYPT_DH_PARAMETER_HEADER
    cbLength    AS DWORD
    dwMagic     AS DWORD
    cbKeyLength AS DWORD
END TYPE


' The BCRYPT_DSA_PUBLIC_BLOB and BCRYPT_DSA_PRIVATE_BLOB blob types are used
' to transport plaintext DSA keys. These blob types will be supported by
' all DSA primitive providers.
$$BCRYPT_DSA_PUBLIC_BLOB         = "DSAPUBLICBLOB"$$
$$BCRYPT_DSA_PRIVATE_BLOB        = "DSAPRIVATEBLOB"$$
$$LEGACY_DSA_PUBLIC_BLOB         = "CAPIDSAPUBLICBLOB"$$
$$LEGACY_DSA_PRIVATE_BLOB        = "CAPIDSAPRIVATEBLOB"$$
$$LEGACY_DSA_V2_PRIVATE_BLOB     = "V2CAPIDSAPRIVATEBLOB"$$

%BCRYPT_DSA_PUBLIC_MAGIC         = &H42505344  ' DSPB
%BCRYPT_DSA_PRIVATE_MAGIC        = &H56505344  ' DSPV

TYPE BCRYPT_DSA_KEY_BLOB
    dwMagic  AS DWORD
    cbKey    AS DWORD
    COUNT(3) AS BYTE
    Seed(19) AS BYTE
    q(19)    AS BYTE
END TYPE

TYPE BCRYPT_KEY_DATA_BLOB_HEADER
    dwMagic AS DWORD
    dwVersion AS DWORD
    cbKeyData AS DWORD
END TYPE

%BCRYPT_KEY_DATA_BLOB_MAGIC       = &H4d42444b 'Key Data Blob Magic (0 TO KDBM)

%BCRYPT_KEY_DATA_BLOB_VERSION1    = &H1

' Property Strings for DSA
$$BCRYPT_DSA_PARAMETERS      = "DSAParameters"$$

%BCRYPT_DSA_PARAMETERS_MAGIC = &H4d505344  ' DSPM

TYPE BCRYPT_DSA_PARAMETER_HEADER
    cbLength    AS DWORD
    dwMagic     AS DWORD
    cbKeyLength AS DWORD
    COUNT(3)    AS BYTE
    Seed(19)    AS BYTE
    q(19)       AS BYTE
END TYPE

'
' Microsoft built-in providers.
'

$$MS_PRIMITIVE_PROVIDER                  = "Microsoft Primitive Provider"$$

'
' Common algorithm identifiers.
'

$$BCRYPT_RSA_ALGORITHM                = "RSA"$$
$$BCRYPT_RSA_SIGN_ALGORITHM           = "RSA_SIGN"$$
$$BCRYPT_DH_ALGORITHM                 = "DH"$$
$$BCRYPT_DSA_ALGORITHM                = "DSA"$$
$$BCRYPT_RC2_ALGORITHM                = "RC2"$$
$$BCRYPT_RC4_ALGORITHM                = "RC4"$$
$$BCRYPT_AES_ALGORITHM                = "AES"$$
$$BCRYPT_DES_ALGORITHM                = "DES"$$
$$BCRYPT_DESX_ALGORITHM               = "DESX"$$
$$BCRYPT_3DES_ALGORITHM               = "3DES"$$
$$BCRYPT_3DES_112_ALGORITHM           = "3DES_112"$$
$$BCRYPT_MD2_ALGORITHM                = "MD2"$$
$$BCRYPT_MD4_ALGORITHM                = "MD4"$$
$$BCRYPT_MD5_ALGORITHM                = "MD5"$$
$$BCRYPT_SHA1_ALGORITHM               = "SHA1"$$
$$BCRYPT_SHA256_ALGORITHM             = "SHA256"$$
$$BCRYPT_SHA384_ALGORITHM             = "SHA384"$$
$$BCRYPT_SHA512_ALGORITHM             = "SHA512"$$
$$BCRYPT_AES_GMAC_ALGORITHM           = "AES-GMAC"$$
$$BCRYPT_ECDSA_P256_ALGORITHM         = "ECDSA_P256"$$
$$BCRYPT_ECDSA_P384_ALGORITHM         = "ECDSA_P384"$$
$$BCRYPT_ECDSA_P521_ALGORITHM         = "ECDSA_P521"$$
$$BCRYPT_ECDH_P256_ALGORITHM          = "ECDH_P256"$$
$$BCRYPT_ECDH_P384_ALGORITHM          = "ECDH_P384"$$
$$BCRYPT_ECDH_P521_ALGORITHM          = "ECDH_P521"$$
$$BCRYPT_RNG_ALGORITHM                = "RNG"$$
$$BCRYPT_RNG_FIPS186_DSA_ALGORITHM    = "FIPS186DSARNG"$$
$$BCRYPT_RNG_DUAL_EC_ALGORITHM        = "DUALECRNG"$$

'
' Interfaces
'

%BCRYPT_CIPHER_INTERFACE                 = &H00000001
%BCRYPT_HASH_INTERFACE                   = &H00000002
%BCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE  = &H00000003
%BCRYPT_SECRET_AGREEMENT_INTERFACE       = &H00000004
%BCRYPT_SIGNATURE_INTERFACE              = &H00000005
%BCRYPT_RNG_INTERFACE                    = &H00000006

'
' Primitive algorithm provider functions.
'

%BCRYPT_ALG_HANDLE_HMAC_FLAG     = &H00000008

DECLARE FUNCTION BCryptOpenAlgorithmProvider LIB "BCrypt.dll" _
    ALIAS "BCryptOpenAlgorithmProvider" (phAlgorithm AS DWORD, _
    pszAlgId AS WSTRINGZ, pszImplementation AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION BCryptOpenAlgorithmProviderFn (phAlgorithm AS DWORD, _
    pszAlgId AS WSTRINGZ, BYVAL dwFlags AS DWORD) AS LONG


' AlgOperations flags for use with BCryptEnumAlgorithms()
%BCRYPT_CIPHER_OPERATION                 = &H00000001
%BCRYPT_HASH_OPERATION                   = &H00000002
%BCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION  = &H00000004
%BCRYPT_SECRET_AGREEMENT_OPERATION       = &H00000008
%BCRYPT_SIGNATURE_OPERATION              = &H00000010
%BCRYPT_RNG_OPERATION                    = &H00000020

' USE EXTREME CAUTION: editing comments that contain "certenrolls_*" tokens
' could break building CertEnroll idl files:
' certenrolls_begin -- BCRYPT_ALGORITHM_IDENTIFIER
TYPE BCRYPT_ALGORITHM_IDENTIFIER
    pszName AS WSTRINGZ PTR
    dwClass AS DWORD
    dwFlags AS DWORD
END TYPE
' certenrolls_end

DECLARE FUNCTION BCryptEnumAlgorithms LIB "BCrypt.dll" _
    ALIAS "BCryptEnumAlgorithms" (dwAlgOperations AS DWORD, _
    pAlgCount AS DWORD, ppAlgList AS ANY, BYVAL dwFlags AS DWORD) AS LONG


TYPE BCRYPT_PROVIDER_NAME
    pszProviderName AS WSTRINGZ PTR
END TYPE

DECLARE FUNCTION BCryptEnumProviders LIB "BCrypt.dll" _
    ALIAS "BCryptEnumProviders" (pszAlgId AS WSTRINGZ, pImplCount AS DWORD, _
    ppImplList AS ANY, BYVAL dwFlags AS DWORD) AS LONG


' Flags for use with BCryptGetProperty and BCryptSetProperty
%BCRYPT_PUBLIC_KEY_FLAG          = &H00000001
%BCRYPT_PRIVATE_KEY_FLAG         = &H00000002


DECLARE FUNCTION BCryptGetProperty LIB "BCrypt.dll" _
    ALIAS "BCryptGetProperty" (BYVAL hObject AS DWORD, _
    pszProperty AS WSTRINGZ, BYVAL pbOutput AS BYTE PTR, _
    BYVAL cbOutput AS DWORD, pcbResult AS DWORD, BYVAL dwFlags AS DWORD) _
    AS LONG


DECLARE FUNCTION BCryptSetProperty LIB "BCrypt.dll" _
    ALIAS "BCryptSetProperty" (BYVAL hObject AS DWORD, _
    pszProperty AS WSTRINGZ, BYVAL pbInput AS BYTE PTR, _
    BYVAL cbInput AS DWORD, BYVAL dwFlags AS DWORD) AS LONG


DECLARE FUNCTION BCryptCloseAlgorithmProvider LIB "BCrypt.dll" _
    ALIAS "BCryptCloseAlgorithmProvider" (BYVAL hAlgorithm AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG


DECLARE SUB BCryptFreeBuffer LIB "BCrypt.dll" ALIAS "BCryptFreeBuffer" _
    (pvBuffer AS ANY)


'
' Primitive encryption functions.
'

DECLARE FUNCTION BCryptGenerateSymmetricKey LIB "BCrypt.dll" _
    ALIAS "BCryptGenerateSymmetricKey" (BYVAL hAlgorithm AS DWORD, _
    phKey AS DWORD, BYVAL pbKeyObject AS BYTE PTR, _
    BYVAL cbKeyObject AS DWORD, BYVAL pbSecret AS BYTE PTR, _
    BYVAL cbSecret AS DWORD, BYVAL dwFlags AS DWORD) AS LONG


DECLARE FUNCTION BCryptGenerateKeyPair LIB "BCrypt.dll" _
    ALIAS "BCryptGenerateKeyPair" (BYVAL hAlgorithm AS DWORD, _
    phKey AS DWORD, BYVAL dwLength AS DWORD, BYVAL dwFlags AS DWORD) AS LONG


DECLARE FUNCTION BCryptEncrypt LIB "BCrypt.dll" _
    ALIAS "BCryptEncrypt" (BYVAL hKey AS DWORD, BYVAL pbInput AS BYTE PTR, _
    BYVAL cbInput AS DWORD, pPaddingInfo AS ANY, _
    BYVAL pbIV AS BYTE PTR, BYVAL cbIV AS DWORD, BYVAL pbOutput AS BYTE PTR, _
    BYVAL cbOutput AS DWORD, pcbResult AS DWORD, BYVAL dwFlags AS DWORD) _
    AS LONG


DECLARE FUNCTION BCryptDecrypt LIB "BCrypt.dll" _
    ALIAS "BCryptDecrypt" (BYVAL hKey AS DWORD, BYVAL pbInput AS BYTE PTR, _
    BYVAL cbInput AS DWORD, pPaddingInfo AS ANY, BYVAL pbIV AS BYTE PTR, _
    BYVAL cbIV AS DWORD, BYVAL pbOutput AS BYTE PTR, BYVAL cbOutput AS DWORD, _
    pcbResult AS DWORD, BYVAL dwFlags AS DWORD) AS LONG


DECLARE FUNCTION BCryptExportKey LIB "BCrypt.dll" _
    ALIAS "BCryptExportKey" (BYVAL hKey AS DWORD, BYVAL hExportKey AS DWORD, _
    pszBlobType AS WSTRINGZ, BYVAL pbOutput AS BYTE PTR, _
    BYVAL cbOutput AS DWORD, pcbResult AS DWORD, BYVAL dwFlags AS DWORD) _
    AS LONG


DECLARE FUNCTION BCryptImportKey LIB "BCrypt.dll" _
    ALIAS "BCryptImportKey" (BYVAL hAlgorithm AS DWORD, _
    BYVAL hImportKey AS DWORD, pszBlobType AS WSTRINGZ, phKey AS DWORD, _
    BYVAL pbKeyObject AS BYTE PTR, BYVAL cbKeyObject AS DWORD, _
    BYVAL pbInput AS BYTE PTR, BYVAL cbInput AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG


%BCRYPT_NO_KEY_VALIDATION  = &H00000008

DECLARE FUNCTION BCryptImportKeyPair LIB "BCrypt.dll" _
    ALIAS "BCryptImportKeyPair" (BYVAL hAlgorithm AS DWORD, _
    BYVAL hImportKey AS DWORD, pszBlobType AS WSTRINGZ, phKey AS DWORD, _
    BYVAL pbInput AS BYTE PTR, BYVAL cbInput AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG


DECLARE FUNCTION BCryptDuplicateKey LIB "BCrypt.dll" _
    ALIAS "BCryptDuplicateKey" (BYVAL hKey AS DWORD, phNewKey AS DWORD, _
    BYVAL pbKeyObject AS BYTE PTR, BYVAL cbKeyObject AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG


DECLARE FUNCTION BCryptFinalizeKeyPair LIB "BCrypt.dll" _
    ALIAS "BCryptFinalizeKeyPair" (BYVAL hKey AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG


DECLARE FUNCTION BCryptDestroyKey LIB "BCrypt.dll" _
    ALIAS "BCryptDestroyKey" (BYVAL hKey AS DWORD) AS LONG


DECLARE FUNCTION BCryptDestroySecret LIB "BCrypt.dll" _
    ALIAS "BCryptDestroySecret" (BYVAL hSecret AS DWORD) AS LONG


DECLARE FUNCTION BCryptSignHash LIB "BCrypt.dll" _
    ALIAS "BCryptSignHash" (BYVAL hKey AS DWORD, pPaddingInfo AS ANY, _
    BYVAL pbInput AS BYTE PTR, BYVAL cbInput AS DWORD, _
    BYVAL pbOutput AS BYTE PTR, BYVAL cbOutput AS DWORD, pcbResult AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG


DECLARE FUNCTION BCryptVerifySignature LIB "BCrypt.dll" _
    ALIAS "BCryptVerifySignature" (BYVAL hKey AS DWORD, pPaddingInfo AS ANY, _
    BYVAL pbHash AS BYTE PTR, BYVAL cbHash AS DWORD, _
    BYVAL pbSignature AS BYTE PTR, BYVAL cbSignature AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG


DECLARE FUNCTION BCryptSecretAgreement LIB "BCrypt.dll" _
    ALIAS "BCryptSecretAgreement" (BYVAL hPrivKey AS DWORD, _
    BYVAL hPubKey AS DWORD, phAgreedSecret AS DWORD, BYVAL dwFlags AS DWORD) _
    AS LONG


DECLARE FUNCTION BCryptDeriveKey LIB "BCrypt.dll" _
    ALIAS "BCryptDeriveKey" (BYVAL hSharedSecret AS DWORD, _
    pwszKDF AS WSTRINGZ, BYVAL pParameterList AS BCryptBufferDesc PTR, _
    BYVAL pbDerivedKey AS BYTE PTR, BYVAL cbDerivedKey AS DWORD, _
    pcbResult AS DWORD, BYVAL dwFlags AS DWORD) AS LONG


'
' Primitive hashing functions.
'

DECLARE FUNCTION BCryptCreateHash LIB "BCrypt.dll" _
    ALIAS "BCryptCreateHash" (BYVAL hAlgorithm AS DWORD, phHash AS DWORD, _
    BYVAL pbHashObject AS BYTE PTR, BYVAL cbHashObject AS DWORD, _
    BYVAL pbSecret AS BYTE PTR, BYVAL cbSecret AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG


DECLARE FUNCTION BCryptHashData LIB "BCrypt.dll" _
    ALIAS "BCryptHashData" (BYVAL hHash AS DWORD, BYVAL pbInput AS BYTE PTR, _
    BYVAL cbInput AS DWORD, BYVAL dwFlags AS DWORD) AS LONG


DECLARE FUNCTION BCryptFinishHash LIB "BCrypt.dll" _
    ALIAS "BCryptFinishHash" (BYVAL hHash AS DWORD, _
    BYVAL pbOutput AS BYTE PTR, BYVAL cbOutput AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG


DECLARE FUNCTION BCryptDuplicateHash LIB "BCrypt.dll" _
    ALIAS "BCryptDuplicateHash" (BYVAL hHash AS DWORD, phNewHash AS DWORD, _
    BYVAL pbHashObject AS BYTE PTR, BYVAL cbHashObject AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG


DECLARE FUNCTION BCryptDestroyHash LIB "BCrypt.dll" _
    ALIAS "BCryptDestroyHash" (BYVAL hHash AS DWORD) AS LONG


'
' Primitive random number generation.
'

' Flags to BCryptGenRandom
%BCRYPT_RNG_USE_ENTROPY_IN_BUFFER    = &H00000001
%BCRYPT_USE_SYSTEM_PREFERRED_RNG     = &H00000002

DECLARE FUNCTION BCryptGenRandom LIB "BCrypt.dll" _
    ALIAS "BCryptGenRandom" (BYVAL hAlgorithm AS DWORD, _
    BYVAL pbBuffer AS BYTE PTR, BYVAL cbBuffer AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG


'
' Interface version control...
'
TYPE BCRYPT_INTERFACE_VERSION
    MajorVersion AS WORD
    MinorVersion AS WORD
END TYPE

'MACRO BCRYPT_MAKE_INTERFACE_VERSION(major,minor)= {(WORD)major, (WORD)minor}

MACRO BCRYPT_IS_INTERFACE_VERSION_COMPATIBLE(loader, provider)= _
  (loader.MajorVersion <= provider.MajorVersion)

'
' Primitive provider interfaces.
'

'MACRO BCRYPT_CIPHER_INTERFACE_VERSION_1=BCRYPT_MAKE_INTERFACE_VERSION(1,0)
'
'
'MACRO BCRYPT_HASH_INTERFACE_VERSION_1=BCRYPT_MAKE_INTERFACE_VERSION(1,0)
'
'
'MACRO BCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE_VERSION_1=BCRYPT_MAKE_INTERFACE_VERSION(1,0)
'
'
'MACRO BCRYPT_SECRET_AGREEMENT_INTERFACE_VERSION_1=BCRYPT_MAKE_INTERFACE_VERSION(1,0)
'
'
'MACRO BCRYPT_SIGNATURE_INTERFACE_VERSION_1=BCRYPT_MAKE_INTERFACE_VERSION(1,0)
'
'
'MACRO BCRYPT_RNG_INTERFACE_VERSION_1=BCRYPT_MAKE_INTERFACE_VERSION(1,0)


'''''''''''''''''''''''''''''''''''''''
' CryptoConfig Definitions '''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''

' Interface registration flags
%CRYPT_MIN_DEPENDENCIES      = &H00000001
%CRYPT_PROCESS_ISOLATE       = &H00010000  ' User-mode only

' Processor modes supported by a provider
'
' (Valid for BCryptQueryProviderRegistration and BCryptResolveProviders):
'
%CRYPT_UM                    = &H00000001    ' User mode only
%CRYPT_KM                    = &H00000002    ' Kernel mode only
%CRYPT_MM                    = &H00000003    ' Multi-mode: Must support BOTH UM and KM
'
' (Valid only for BCryptQueryProviderRegistration):
'
%CRYPT_ANY                   = &H00000004    ' Wildcard: Either UM, or KM, or both


' Write behavior flags
%CRYPT_OVERWRITE             = &H00000001

' Configuration tables
%CRYPT_LOCAL                 = &H00000001
%CRYPT_DOMAIN                = &H00000002

' Context configuration flags
%CRYPT_EXCLUSIVE             = &H00000001
%CRYPT_OVERRIDE              = &H00010000  ' Enterprise table only

' Resolution and enumeration flags
%CRYPT_ALL_FUNCTIONS         = &H00000001
%CRYPT_ALL_PROVIDERS         = &H00000002

' Priority list positions
%CRYPT_PRIORITY_TOP          = &H00000000
%CRYPT_PRIORITY_BOTTOM       = &HFFFFFFFF

' Default system-wide context
$$CRYPT_DEFAULT_CONTEXT      = "Default"$$

'''''''''''''''''''''''''''''''''''''''
' CryptoConfig Structures '''''''''''''
'''''''''''''''''''''''''''''''''''''''

'
' Provider Registration Structures
'

TYPE CRYPT_INTERFACE_REG
    dwInterface    AS DWORD
    dwFlags        AS DWORD

    cFunctions     AS DWORD
    rgpszFunctions AS WSTRINGZ PTR
END TYPE

TYPE CRYPT_IMAGE_REG
    pszImage      AS WSTRINGZ PTR

    cInterfaces   AS DWORD
    rgpInterfaces AS DWORD
END TYPE

TYPE CRYPT_PROVIDER_REG
    cAliases     AS DWORD
    rgpszAliases AS DWORD

    pUM          AS CRYPT_IMAGE_REG PTR
    pKM          AS CRYPT_IMAGE_REG PTR
END TYPE

TYPE CRYPT_PROVIDERS
    cProviders     AS DWORD
    rgpszProviders AS DWORD
END TYPE

'
' Context Configuration Structures
'

TYPE CRYPT_CONTEXT_CONFIG
    dwFlags    AS DWORD
    dwReserved AS DWORD
END TYPE

TYPE CRYPT_CONTEXT_FUNCTION_CONFIG
    dwFlags    AS DWORD
    dwReserved AS DWORD
END TYPE

TYPE CRYPT_CONTEXTS
    cContexts     AS DWORD
    rgpszContexts AS DWORD
END TYPE

TYPE CRYPT_CONTEXT_FUNCTIONS
    cFunctions     AS DWORD
    rgpszFunctions AS DWORD
END TYPE

TYPE CRYPT_CONTEXT_FUNCTION_PROVIDERS
    cProviders     AS DWORD
    rgpszProviders AS DWORD
END TYPE

'
' Provider Resolution Structures
'

TYPE CRYPT_PROPERTY_REF
    pszProperty AS WSTRINGZ PTR

    cbValue     AS DWORD
    pbValue     AS BYTE PTR
END TYPE

TYPE CRYPT_IMAGE_REF
    pszImage AS WSTRINGZ PTR
    dwFlags  AS DWORD
END TYPE

TYPE CRYPT_PROVIDER_REF
    dwInterface   AS DWORD
    pszFunction   AS WSTRINGZ PTR
    pszProvider   AS WSTRINGZ PTR

    cProperties   AS DWORD
    rgpProperties AS DWORD

    pUM           AS CRYPT_IMAGE_REF PTR
    pKM           AS CRYPT_IMAGE_REF PTR
END TYPE

TYPE CRYPT_PROVIDER_REFS
    cProviders   AS DWORD
    rgpProviders AS DWORD
END TYPE

'''''''''''''''''''''''''''''''''''''''
' CryptoConfig Functions ''''''''''''''
'''''''''''''''''''''''''''''''''''''''

#IF NOT %DEF(%KERNEL_MODE_CNG)

DECLARE FUNCTION BCryptQueryProviderRegistration LIB "BCrypt.dll" _
    ALIAS "BCryptQueryProviderRegistration" (pszProvider AS WSTRINGZ, _
    BYVAL dwMode AS DWORD, BYVAL dwInterface AS DWORD, pcbBuffer AS DWORD, _
    ppBuffer AS ANY) AS LONG

DECLARE FUNCTION BCryptEnumRegisteredProviders LIB "BCrypt.dll" _
    ALIAS "BCryptEnumRegisteredProviders" (pcbBuffer AS DWORD, _
    ppBuffer AS ANY) AS LONG

'
' Context Configuration Functions
'

DECLARE FUNCTION BCryptCreateContext LIB "BCrypt.dll" _
    ALIAS "BCryptCreateContext" (BYVAL dwTable AS DWORD, _
    pszContext AS WSTRINGZ, pConfig AS CRYPT_CONTEXT_CONFIG) AS LONG

DECLARE FUNCTION BCryptDeleteContext LIB "BCrypt.dll" _
    ALIAS "BCryptDeleteContext" (BYVAL dwTable AS DWORD, _
    pszContext AS WSTRINGZ) AS LONG

DECLARE FUNCTION BCryptEnumContexts LIB "BCrypt.dll" _
    ALIAS "BCryptEnumContexts" (BYVAL dwTable AS DWORD, pcbBuffer AS DWORD, _
    ppBuffer AS ANY) AS LONG

DECLARE FUNCTION BCryptConfigureContext LIB "BCrypt.dll" _
    ALIAS "BCryptConfigureContext" (BYVAL dwTable AS DWORD, _
    pszContext AS WSTRINGZ, pConfig AS CRYPT_CONTEXT_CONFIG) AS LONG

DECLARE FUNCTION BCryptQueryContextConfiguration LIB "BCrypt.dll" _
    ALIAS "BCryptQueryContextConfiguration" (BYVAL dwTable AS DWORD, _
    pszContext AS WSTRINGZ, pcbBuffer AS DWORD, ppBuffer AS ANY) AS LONG

DECLARE FUNCTION BCryptAddContextFunction LIB "BCrypt.dll" _
    ALIAS "BCryptAddContextFunction" (BYVAL dwTable AS DWORD, _
    pszContext AS WSTRINGZ, BYVAL dwInterface AS DWORD, _
    pszFunction AS WSTRINGZ, BYVAL dwPosition AS DWORD) AS LONG

DECLARE FUNCTION BCryptRemoveContextFunction LIB "BCrypt.dll" _
    ALIAS "BCryptRemoveContextFunction" (BYVAL dwTable AS DWORD, _
    pszContext AS WSTRINGZ, BYVAL dwInterface AS DWORD, _
    pszFunction AS WSTRINGZ) AS LONG

DECLARE FUNCTION BCryptEnumContextFunctions LIB "BCrypt.dll" _
    ALIAS "BCryptEnumContextFunctions" (BYVAL dwTable AS DWORD, _
    pszContext AS WSTRINGZ, BYVAL dwInterface AS DWORD, _
    pcbBuffer AS DWORD, ppBuffer AS ANY) AS LONG

DECLARE FUNCTION BCryptConfigureContextFunction LIB "BCrypt.dll" _
    ALIAS "BCryptConfigureContextFunction" (BYVAL dwTable AS DWORD, _
    pszContext AS WSTRINGZ, BYVAL dwInterface AS DWORD, _
    pszFunction AS WSTRINGZ, pConfig AS CRYPT_CONTEXT_FUNCTION_CONFIG) AS LONG

DECLARE FUNCTION BCryptQueryContextFunctionConfiguration LIB "BCrypt.dll" _
    ALIAS "BCryptQueryContextFunctionConfiguration" (BYVAL dwTable AS DWORD, _
    pszContext AS WSTRINGZ, BYVAL dwInterface AS DWORD, _
    pszFunction AS WSTRINGZ, pcbBuffer AS DWORD, ppBuffer AS ANY) AS LONG


DECLARE FUNCTION BCryptEnumContextFunctionProviders LIB "BCrypt.dll" _
    ALIAS "BCryptEnumContextFunctionProviders" (BYVAL dwTable AS DWORD, _
    pszContext AS WSTRINGZ, BYVAL dwInterface AS DWORD, _
    pszFunction AS WSTRINGZ, pcbBuffer AS DWORD, ppBuffer AS ANY) AS LONG

DECLARE FUNCTION BCryptSetContextFunctionProperty LIB "BCrypt.dll" _
    ALIAS "BCryptSetContextFunctionProperty" (BYVAL dwTable AS DWORD, _
    pszContext AS WSTRINGZ, BYVAL dwInterface AS DWORD, _
    pszFunction AS WSTRINGZ, pszProperty AS WSTRINGZ, BYVAL cbValue AS DWORD, _
    BYVAL pbValue AS BYTE PTR) AS LONG

DECLARE FUNCTION BCryptQueryContextFunctionProperty LIB "BCrypt.dll" _
    ALIAS "BCryptQueryContextFunctionProperty" (BYVAL dwTable AS DWORD, _
    pszContext AS WSTRINGZ, BYVAL dwInterface AS DWORD, _
    pszFunction AS WSTRINGZ, pszProperty AS WSTRINGZ, pcbValue AS DWORD, _
    ppbValue AS ANY) AS LONG

#ENDIF '#IF NOT %DEF(%KERNEL_MODE_CNG)

'
' Configuration Change Notification Functions
'

#IF %DEF(%KERNEL_MODE_CNG)
DECLARE FUNCTION BCryptRegisterConfigChangeNotify LIB "BCrypt.dll" _
    ALIAS "BCryptRegisterConfigChangeNotify" (pEvent AS ANY) AS LONG
#ELSE
DECLARE FUNCTION BCryptRegisterConfigChangeNotify LIB "BCrypt.dll" _
    ALIAS "BCryptRegisterConfigChangeNotify" (phEvent AS DWORD) AS LONG
#ENDIF

#IF %DEF(%KERNEL_MODE_CNG)
DECLARE FUNCTION BCryptUnregisterConfigChangeNotify LIB "BCrypt.dll" _
    ALIAS "BCryptUnregisterConfigChangeNotify" (pEvent AS ANY) AS LONG
#ELSE
DECLARE FUNCTION BCryptUnregisterConfigChangeNotify LIB "BCrypt.dll" _
    ALIAS "BCryptUnregisterConfigChangeNotify" (BYVAL hEvent AS DWORD) AS LONG
#ENDIF

'
' Provider Resolution Functions
'

DECLARE FUNCTION BCryptResolveProviders LIB "BCrypt.dll" _
    ALIAS "BCryptResolveProviders" (pszContext AS WSTRINGZ, _
    BYVAL dwInterface AS DWORD, pszFunction AS WSTRINGZ, _
    pszProvider AS WSTRINGZ, BYVAL dwMode AS DWORD, BYVAL dwFlags AS DWORD, _
    ppBuffer AS ANY) AS LONG


'
' Miscellaneous queries about the crypto environment
'

DECLARE FUNCTION BCryptGetFipsAlgorithmMode LIB "BCrypt.dll" _
    ALIAS "BCryptGetFipsAlgorithmMode" (pfEnabled AS LONG) AS LONG
