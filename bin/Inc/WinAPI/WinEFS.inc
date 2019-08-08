'------------------------------------------------------------------------------
'
'  WinEFS.inc - EFS Data and prototypes.
'
'  Copyright (c) 2009-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from WinEFS.h dated 18 Jan 2008
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WINEFS_H = 1

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "WinDef.inc"
#INCLUDE "WinNT.inc"
#INCLUDE "WTypes.inc"

' winefs.h was not available at all pre-W2K
#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)


%WINEFS_SETUSERKEY_SET_CAPABILITIES   = &H00000001
%WINEFS_SETUSERKEY_BLOCK_CACHE_FLUSH  = &H00000002

'+---------------------------------------------------------------------------------/
'                                                                                  /
'                                                                                  /
'                          Data Structures                                         /
'                                                                                  /
'                                                                                  /
'----------------------------------------------------------------------------------/

' ALG_ID define is used as part of EFS_KEY_INFO (not available pre-WXP)
'#if (%NTDDI_VERSION >= %NTDDI_WINXP)
'
'#IF NOT %DEF(%ALGIDDEF)
'#define ALGIDDEF
'typedef unsigned int ALG_ID;
'#endif
'
'#endif

'
'  Encoded Certificate
'


TYPE EFS_CERTIFICATE_BLOB
    dwCertEncodingType AS DWORD
    cbData             AS DWORD
    pbData             AS BYTE PTR
END TYPE

'
'  Certificate Hash
'

TYPE EFS_HASH_BLOB
    cbData AS DWORD
    pbData AS BYTE PTR
END TYPE


' EFS_RPC_BLOB was not available pre-WXP
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)

'
'  RPC blob
'

TYPE EFS_RPC_BLOB
    cbData AS DWORD
    pbData AS BYTE PTR
END TYPE

#ENDIF ' #if (%NTDDI_VERSION >= %NTDDI_WINXP)

' EFS_PIN_BLOB was not available pre-LH
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

TYPE EFS_PIN_BLOB
    cbPadding AS DWORD
    cbData    AS DWORD
    pbData    AS BYTE PTR
END TYPE

#ENDIF ' #if (%NTDDI_VERSION >= %NTDDI_VISTA)


' EFS_KEY_INFO was not available pre-WXP
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)

TYPE EFS_KEY_INFO
    dwVersion AS DWORD
    Entropy   AS DWORD
    Algorithm AS DWORD
    KeyLength AS DWORD
END TYPE

#ENDIF ' #if (%NTDDI_VERSION >= %NTDDI_WINXP)

' EFS_(EN/DE)CRYPTION_STATUS_INFO was not available pre-LH
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

TYPE EFS_DECRYPTION_STATUS_INFO
    dwDecryptionError AS DWORD
    dwHashOffset      AS DWORD
    cbHash            AS DWORD
END TYPE

TYPE EFS_ENCRYPTION_STATUS_INFO
    bHasCurrentKey    AS LONG
    dwEncryptionError AS DWORD
END TYPE

#ENDIF ' #if (%NTDDI_VERSION >= %NTDDI_VISTA)

'
' Input to add a user to an encrypted file
'

TYPE ENCRYPTION_CERTIFICATE
    cbTotalLength AS DWORD
    pUserSid      AS SID PTR
    pCertBlob     AS EFS_CERTIFICATE_BLOB PTR
END TYPE

%MAX_SID_SIZE = 256


TYPE ENCRYPTION_CERTIFICATE_HASH
    cbTotalLength        AS DWORD
    pUserSid             AS SID PTR
    pHash                AS EFS_HASH_BLOB PTR
    lpDisplayInformation AS WSTRINGZ PTR
END TYPE

TYPE ENCRYPTION_CERTIFICATE_HASH_LIST
    nCert_Hash AS DWORD
    pUsers     AS DWORD  ' ENCRYPTION_CERTIFICATE_HASH PTR PTR
END TYPE


TYPE ENCRYPTION_CERTIFICATE_LIST
    nUsers AS DWORD
    pUsers AS DWORD  ' ENCRYPTION_CERTIFICATE PTR PTR
END TYPE

' ENCRYPTED_FILE_METADATA_SIGNATURE was not available pre-LH
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

%EFS_METADATA_ADD_USER      = &H00000001
%EFS_METADATA_REMOVE_USER   = &H00000002
%EFS_METADATA_REPLACE_USER  = &H00000004
%EFS_METADATA_GENERAL_OP    = &H00000008

TYPE ENCRYPTED_FILE_METADATA_SIGNATURE
    dwEfsAccessType        AS DWORD
    pCertificatesAdded     AS ENCRYPTION_CERTIFICATE_HASH_LIST PTR
    pEncryptionCertificate AS ENCRYPTION_CERTIFICATE PTR
    pEfsStreamSignature    AS EFS_RPC_BLOB PTR
END TYPE

#ENDIF ' #if (%NTDDI_VERSION >= %NTDDI_VISTA)

'+---------------------------------------------------------------------------------/
'                                                                                  /
'                                                                                  /
'                               Prototypes                                         /
'                                                                                  /
'                                                                                  /
'----------------------------------------------------------------------------------/


DECLARE FUNCTION QueryUsersOnEncryptedFile LIB "ADVAPI32.DLL" _
    ALIAS "QueryUsersOnEncryptedFile" (lpFileName AS WSTRINGZ, _
    pUsers AS ANY) AS DWORD


DECLARE FUNCTION QueryRecoveryAgentsOnEncryptedFile LIB "ADVAPI32.DLL" _
    ALIAS "QueryRecoveryAgentsOnEncryptedFile" (lpFileName AS WSTRINGZ, _
    pRecoveryAgents AS ANY) AS DWORD


DECLARE FUNCTION RemoveUsersFromEncryptedFile LIB "ADVAPI32.DLL" _
    ALIAS "RemoveUsersFromEncryptedFile" (lpFileName AS WSTRINGZ, _
    BYVAL pHashes AS ENCRYPTION_CERTIFICATE_HASH_LIST PTR) AS DWORD

DECLARE FUNCTION AddUsersToEncryptedFile LIB "ADVAPI32.DLL" _
    ALIAS "AddUsersToEncryptedFile" (lpFileName AS WSTRINGZ, _
    BYVAL pEncryptionCertificates AS ENCRYPTION_CERTIFICATE_LIST PTR) AS DWORD

DECLARE FUNCTION SetUserFileEncryptionKey LIB "ADVAPI32.DLL" _
    ALIAS "SetUserFileEncryptionKey" _
    (pEncryptionCertificate AS ENCRYPTION_CERTIFICATE) AS DWORD

' SetUserFileEncryptionKeyEx was not available pre-LH
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

DECLARE FUNCTION SetUserFileEncryptionKeyEx LIB "ADVAPI32.DLL" _
    ALIAS "SetUserFileEncryptionKeyEx" _
    (pEncryptionCertificate AS ENCRYPTION_CERTIFICATE, _
    BYVAL dwCapabilities AS DWORD, BYVAL dwFlags AS DWORD, pvReserved AS ANY) _
    AS DWORD

#ENDIF ' #if (%NTDDI_VERSION >= %NTDDI_VISTA)

DECLARE SUB FreeEncryptionCertificateHashList LIB "ADVAPI32.DLL" _
    ALIAS "FreeEncryptionCertificateHashList" _
    (BYVAL pUsers AS ENCRYPTION_CERTIFICATE_HASH_LIST PTR)

DECLARE FUNCTION EncryptionDisable LIB "ADVAPI32.DLL" _
    ALIAS "EncryptionDisable" (DirPath AS WSTRINGZ, BYVAL fDisable AS LONG) _
    AS LONG  ' BOOL


' DuplicateEncryptionInfoFile signature changed
' in WS03 to use a CONST SECURITY_ATTRIBUTES structure
#IF (%NTDDI_VERSION >= %NTDDI_WS03)

DECLARE FUNCTION DuplicateEncryptionInfoFile LIB "ADVAPI32.DLL" _
    ALIAS "DuplicateEncryptionInfoFile" (SrcFileName AS WSTRINGZ, _
    DstFileName AS WSTRINGZ, BYVAL dwCreationDistribution AS DWORD, _
    BYVAL dwAttributes AS DWORD, lpSecurityAttributes AS SECURITY_ATTRIBUTES) _
    AS DWORD

' DuplicateEncryptionInfoFile didn't exist pre-WXP
#ELSEIF (%NTDDI_VERSION >= %NTDDI_WINXP)


DECLARE FUNCTION DuplicateEncryptionInfoFile LIB "ADVAPI32.DLL" _
    ALIAS "DuplicateEncryptionInfoFile" (SrcFileName AS WSTRINGZ, _
    DstFileName AS WSTRINGZ, BYVAL dwCreationDistribution AS DWORD, _
    BYVAL dwAttributes AS DWORD, lpSecurityAttributes AS SECURITY_ATTRIBUTES) _
    AS DWORD


#ENDIF

' *EncryptedFileMetadata routines were not available pre-LH
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

DECLARE FUNCTION GetEncryptedFileMetadata LIB "ADVAPI32.DLL" _
    ALIAS "GetEncryptedFileMetadata" (lpFileName AS WSTRINGZ, _
    pcbMetadata AS DWORD, ppbMetadata AS ANY) AS DWORD

DECLARE FUNCTION SetEncryptedFileMetadata LIB "ADVAPI32.DLL" _
    ALIAS "SetEncryptedFileMetadata" (lpFileName AS WSTRINGZ, _
    BYVAL pbOldMetadata AS BYTE PTR, BYVAL pbNewMetadata AS BYTE PTR, _
    pOwnerHash AS ENCRYPTION_CERTIFICATE_HASH, BYVAL dwOperation AS DWORD, _
    BYVAL pCertificatesAddes AS ENCRYPTION_CERTIFICATE_HASH_LIST PTR) AS DWORD

DECLARE SUB FreeEncryptedFileMetadata LIB "ADVAPI32.DLL" _
    ALIAS "FreeEncryptedFileMetadata" (BYVAL pbMetadata AS BYTE PTR)

#ENDIF ' #if (%NTDDI_VERSION >= %NTDDI_VISTA)


#ENDIF ' #if (%NTDDI_VERSION >= %NTDDI_WIN2K)
