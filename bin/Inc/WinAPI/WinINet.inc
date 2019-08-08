'------------------------------------------------------------------------------
'
'  WinINet.inc
'    Contains manifests, macros, types and prototypes for Microsoft Windows
'    Internet Extensions.
'
'  Copyright (C) 1999-2011 PowerBASIC, Inc.
'  Portions Copyright (C) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from wininet.h and winineti.h of 14 Jul 2009
'------------------------------------------------------------------------------
' The two #include files were combined to avoid circular reference problems.
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WININET_INC = 1

#INCLUDE "WinHttp.inc"


'
' internet types
'

'typedef LPVOID HINTERNET;
'typedef HINTERNET * LPHINTERNET;

MACRO INTERNET_PORT=WORD
'typedef INTERNET_PORT * LPINTERNET_PORT;

'
' Internet APIs
'

'
' manifests
'

%INTERNET_INVALID_PORT_NUMBER  = 0       ' use the protocol-specific default

%INTERNET_DEFAULT_FTP_PORT     = 21      ' default for FTP servers
%INTERNET_DEFAULT_GOPHER_PORT  = 70      '    "     "  gopher "
%INTERNET_DEFAULT_HTTP_PORT    = 80      '    "     "  HTTP   "
%INTERNET_DEFAULT_HTTPS_PORT   = 443     '    "     "  HTTPS  "
%INTERNET_DEFAULT_SOCKS_PORT   = 1080    ' default for SOCKS firewall servers.


'
' maximum field lengths (arbitrary)
'

%INTERNET_MAX_HOST_NAME_LENGTH   = 256
%INTERNET_MAX_USER_NAME_LENGTH   = 128
%INTERNET_MAX_PASSWORD_LENGTH    = 128
%INTERNET_MAX_PORT_NUMBER_LENGTH = 5           ' INTERNET_PORT is WORD
%INTERNET_MAX_PORT_NUMBER_VALUE  = 65535       ' maximum unsigned short value
%INTERNET_MAX_PATH_LENGTH        = 2048
%INTERNET_MAX_SCHEME_LENGTH      = 32          ' longest protocol name length
%INTERNET_MAX_URL_LENGTH         = (%INTERNET_MAX_SCHEME_LENGTH _
                                        + 2 _  ' + sizeof(":'") _
                                        + %INTERNET_MAX_PATH_LENGTH)


'
' values returned by InternetQueryOption() with INTERNET_OPTION_KEEP_CONNECTION:
'

%INTERNET_KEEP_ALIVE_UNKNOWN     = &HFFFFFFFF???   ' ((DWORD)-1)
%INTERNET_KEEP_ALIVE_ENABLED     = 1
%INTERNET_KEEP_ALIVE_DISABLED    = 0

'
' flags returned by InternetQueryOption() with INTERNET_OPTION_REQUEST_FLAGS
'

%INTERNET_REQFLAG_FROM_CACHE     = &H00000001  ' response came from cache
%INTERNET_REQFLAG_ASYNC          = &H00000002  ' request was made asynchronously
%INTERNET_REQFLAG_VIA_PROXY      = &H00000004  ' request was made via a proxy
%INTERNET_REQFLAG_NO_HEADERS     = &H00000008  ' orginal response contained no headers
%INTERNET_REQFLAG_PASSIVE        = &H00000010  ' FTP: passive-mode connection
%INTERNET_REQFLAG_CACHE_WRITE_DISABLED = &H00000040  ' HTTPS: this request not cacheable
%INTERNET_REQFLAG_NET_TIMEOUT    = &H00000080  ' w/ _FROM_CACHE: net request timed out

'
' flags for IDN enable/disable via INTERNET_OPTION_IDN
'

%INTERNET_FLAG_IDN_DIRECT        = &H00000001  ' IDN enabled for direct connections
%INTERNET_FLAG_IDN_PROXY         = &H00000002  ' IDN enabled for proxy

'
' flags common to open functions (not InternetOpen()):
'

%INTERNET_FLAG_RELOAD            = &H80000000???  ' retrieve the original item

'
' flags for InternetOpenUrl():
'

%INTERNET_FLAG_RAW_DATA          = &H40000000  ' FTP/gopher find: receive the item as raw (structured) data
%INTERNET_FLAG_EXISTING_CONNECT  = &H20000000  ' FTP: use existing InternetConnect handle for server if possible

'
' flags for InternetOpen():
'

%INTERNET_FLAG_ASYNC             = &H10000000  ' this request is asynchronous (where supported)

'
' protocol-specific flags:
'

%INTERNET_FLAG_PASSIVE           = &H08000000  ' used for FTP connections

'
' additional cache flags
'

%INTERNET_FLAG_NO_CACHE_WRITE    = &H04000000  ' don't write this item to the cache
%INTERNET_FLAG_DONT_CACHE        = %INTERNET_FLAG_NO_CACHE_WRITE
%INTERNET_FLAG_MAKE_PERSISTENT   = &H02000000  ' make this item persistent in cache
%INTERNET_FLAG_FROM_CACHE        = &H01000000  ' use offline semantics
%INTERNET_FLAG_OFFLINE           = %INTERNET_FLAG_FROM_CACHE

'
' additional flags
'

%INTERNET_FLAG_SECURE            = &H00800000  ' use PCT/SSL if applicable (HTTP)
%INTERNET_FLAG_KEEP_CONNECTION   = &H00400000  ' use keep-alive semantics
%INTERNET_FLAG_NO_AUTO_REDIRECT  = &H00200000  ' don't handle redirections automatically
%INTERNET_FLAG_READ_PREFETCH     = &H00100000  ' do background read prefetch
%INTERNET_FLAG_NO_COOKIES        = &H00080000  ' no automatic cookie handling
%INTERNET_FLAG_NO_AUTH           = &H00040000  ' no automatic authentication handling
%INTERNET_FLAG_RESTRICTED_ZONE   = &H00020000  ' apply restricted zone policies for cookies, auth
%INTERNET_FLAG_CACHE_IF_NET_FAIL = &H00010000  ' return cache file if net request fails

'
' Security Ignore Flags, Allow HttpOpenRequest to overide
'  Secure Channel (SSL/PCT) failures of the following types.
'

%INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTP   = &H00008000 ' ex: https:' to http:'
%INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTPS  = &H00004000 ' ex: http:' to https:'
%INTERNET_FLAG_IGNORE_CERT_DATE_INVALID  = &H00002000 ' expired X509 Cert.
%INTERNET_FLAG_IGNORE_CERT_CN_INVALID    = &H00001000 ' bad common name in X509 Cert.

'
' more caching flags
'

%INTERNET_FLAG_RESYNCHRONIZE      = &H00000800  ' asking wininet to update an item if it is newer
%INTERNET_FLAG_HYPERLINK          = &H00000400  ' asking wininet to do hyperlinking semantic which works right for scripts
%INTERNET_FLAG_NO_UI              = &H00000200  ' no cookie popup
%INTERNET_FLAG_PRAGMA_NOCACHE     = &H00000100  ' asking wininet to add "pragma: no-cache"
%INTERNET_FLAG_CACHE_ASYNC        = &H00000080  ' ok to perform lazy cache-write
%INTERNET_FLAG_FORMS_SUBMIT       = &H00000040  ' this is a forms submit
%INTERNET_FLAG_FWD_BACK           = &H00000020  ' fwd-back button op
%INTERNET_FLAG_NEED_FILE          = &H00000010  ' need a file for this request
%INTERNET_FLAG_MUST_CACHE_REQUEST = %INTERNET_FLAG_NEED_FILE

%FTP_TRANSFER_TYPE_UNKNOWN = &H00000000
%FTP_TRANSFER_TYPE_ASCII   = &H00000001
%FTP_TRANSFER_TYPE_BINARY  = &H00000002

%FTP_TRANSFER_TYPE_MASK    = (%FTP_TRANSFER_TYPE_ASCII OR %FTP_TRANSFER_TYPE_BINARY)

'
' flags for FTP
'

%INTERNET_FLAG_TRANSFER_ASCII    = %FTP_TRANSFER_TYPE_ASCII     ' &H00000001
%INTERNET_FLAG_TRANSFER_BINARY   = %FTP_TRANSFER_TYPE_BINARY    ' &H00000002

'
' flags field masks
'

%SECURITY_INTERNET_MASK  = %INTERNET_FLAG_IGNORE_CERT_CN_INVALID    OR _
                           %INTERNET_FLAG_IGNORE_CERT_DATE_INVALID  OR _
                           %INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTPS  OR _
                           %INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTP

'%SECURITY_IGNORE_ERROR_MASK = (%INTERNET_FLAG_IGNORE_CERT_CN_INVALID   OR _
'                               %INTERNET_FLAG_IGNORE_CERT_DATE_INVALID OR _
'                               %SECURITY_FLAG_IGNORE_UNKNOWN_CA        OR _
'                               %SECURITY_FLAG_IGNORE_REVOCATION)

%INTERNET_FLAG_BGUPDATE  = &H00000008

%INTERNET_FLAGS_MASK     = %INTERNET_FLAG_RELOAD               _
                           OR %INTERNET_FLAG_RAW_DATA          _
                           OR %INTERNET_FLAG_EXISTING_CONNECT  _
                           OR %INTERNET_FLAG_ASYNC             _
                           OR %INTERNET_FLAG_PASSIVE           _
                           OR %INTERNET_FLAG_NO_CACHE_WRITE    _
                           OR %INTERNET_FLAG_MAKE_PERSISTENT   _
                           OR %INTERNET_FLAG_FROM_CACHE        _
                           OR %INTERNET_FLAG_SECURE            _
                           OR %INTERNET_FLAG_KEEP_CONNECTION   _
                           OR %INTERNET_FLAG_NO_AUTO_REDIRECT  _
                           OR %INTERNET_FLAG_READ_PREFETCH     _
                           OR %INTERNET_FLAG_NO_COOKIES        _
                           OR %INTERNET_FLAG_NO_AUTH           _
                           OR %INTERNET_FLAG_CACHE_IF_NET_FAIL _
                           OR %SECURITY_INTERNET_MASK          _
                           OR %INTERNET_FLAG_RESYNCHRONIZE     _
                           OR %INTERNET_FLAG_HYPERLINK         _
                           OR %INTERNET_FLAG_NO_UI             _
                           OR %INTERNET_FLAG_PRAGMA_NOCACHE    _
                           OR %INTERNET_FLAG_CACHE_ASYNC       _
                           OR %INTERNET_FLAG_FORMS_SUBMIT      _
                           OR %INTERNET_FLAG_NEED_FILE         _
                           OR %INTERNET_FLAG_RESTRICTED_ZONE   _
                           OR %INTERNET_FLAG_TRANSFER_BINARY   _
                           OR %INTERNET_FLAG_TRANSFER_ASCII    _
                           OR %INTERNET_FLAG_FWD_BACK          _
                           OR %INTERNET_FLAG_BGUPDATE

DECLARE FUNCTION InternetConnectA LIB "WinINet.dll" ALIAS "InternetConnectA" _
   ( _
    BYVAL hInternet AS DWORD, _   ' in
    lpszServerName AS ASCIIZ, _   ' in
    BYVAL nServerPort AS WORD, _  ' in
    lpszUserName AS ASCIIZ, _     ' in
    lpszPassword AS ASCIIZ, _     ' in
    BYVAL dwService AS DWORD, _   ' in
    BYVAL dwFlags AS DWORD, _     ' in
    BYVAL dwContext AS DWORD _    ' in
   ) _
   AS DWORD

DECLARE FUNCTION InternetConnectW LIB "WinINet.dll" ALIAS "InternetConnectW" _
   ( _
    BYVAL hInternet AS DWORD, _   ' in
    lpszServerName AS WSTRINGZ, _ ' in
    BYVAL nServerPort AS WORD, _  ' in
    lpszUserName AS WSTRINGZ, _   ' in
    lpszPassword AS WSTRINGZ, _   ' in
    BYVAL dwService AS DWORD, _   ' in
    BYVAL dwFlags AS DWORD, _     ' in
    BYVAL dwContext AS DWORD _    ' in
   ) _
   AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetConnect LIB "WinINet.dll" ALIAS "InternetConnectW" _
   ( _
    BYVAL hInternet AS DWORD, _   ' in
    lpszServerName AS WSTRINGZ, _ ' in
    BYVAL nServerPort AS WORD, _  ' in
    lpszUserName AS WSTRINGZ, _   ' in
    lpszPassword AS WSTRINGZ, _   ' in
    BYVAL dwService AS DWORD, _   ' in
    BYVAL dwFlags AS DWORD, _     ' in
    BYVAL dwContext AS DWORD _    ' in
   ) _
   AS DWORD
#ELSE
DECLARE FUNCTION InternetConnect LIB "WinINet.dll" ALIAS "InternetConnectA" _
   ( _
    BYVAL hInternet AS DWORD, _   ' in
    lpszServerName AS ASCIIZ, _   ' in
    BYVAL nServerPort AS WORD, _  ' in
    lpszUserName AS ASCIIZ, _     ' in
    lpszPassword AS ASCIIZ, _     ' in
    BYVAL dwService AS DWORD, _   ' in
    BYVAL dwFlags AS DWORD, _     ' in
    BYVAL dwContext AS DWORD _    ' in
   ) _
   AS DWORD
#ENDIF

'
' INTERNET_BUFFERS - combines headers and data. May be chained for e.g. file
' upload or scatter/gather operations. For chunked read/write, lpcszHeader
' contains the chunked-ext
'

TYPE INTERNET_BUFFERSA
    dwStructSize    AS DWORD       ' used for API versioning. Set to sizeof(INTERNET_BUFFERS)
    pNext           AS INTERNET_BUFFERSA PTR  ' chain of buffers
    lpcszHeader     AS ASCIIZ PTR  ' pointer to headers (may be NULL)
    dwHeadersLength AS DWORD       ' length of headers if not NULL
    dwHeadersTotal  AS DWORD       ' size of headers if not enough buffer
    lpvBuffer       AS BYTE PTR    ' pointer to data buffer (may be NULL)
    dwBufferLength  AS DWORD       ' length of data buffer if not NULL
    dwBufferTotal   AS DWORD       ' total size of chunk, or content-length if not chunked
    dwOffsetLow     AS DWORD       ' used for read-ranges (only used in HttpSendRequest2)
    dwOffsetHigh    AS DWORD
END TYPE

TYPE INTERNET_BUFFERSW
    dwStructSize    AS DWORD       ' used for API versioning. Set to sizeof(INTERNET_BUFFERS)
    pNext           AS INTERNET_BUFFERSW PTR  ' chain of buffers
    lpcszHeader     AS WSTRINGZ PTR  ' pointer to headers (may be NULL)
    dwHeadersLength AS DWORD        ' length of headers if not NULL
    dwHeadersTotal  AS DWORD        ' size of headers if not enough buffer
    lpvBuffer       AS BYTE PTR     ' pointer to data buffer (may be NULL)
    dwBufferLength  AS DWORD        ' length of data buffer if not NULL
    dwBufferTotal   AS DWORD        ' total size of chunk, or content-length if not chunked
    dwOffsetLow     AS DWORD        ' used for read-ranges (only used in HttpSendRequest2)
    dwOffsetHigh    AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE INTERNET_BUFFERS
    INTERNET_BUFFERSW
END TYPE
#ELSE
TYPE INTERNET_BUFFERS
    INTERNET_BUFFERSA
END TYPE
#ENDIF

TYPE INTERNET_CACHE_ENTRY_INFOA
    dwStructSize      AS DWORD      ' version of cache system.
    lpszSourceUrlName AS ASCIIZ PTR ' embedded pointer to the URL name string.
    lpszLocalFileName AS ASCIIZ PTR ' embedded pointer to the local file name.
    CacheEntryType    AS DWORD      ' cache type bit mask.
    dwUseCount        AS DWORD      ' current users count of the cache entry.
    dwHitRate         AS DWORD      ' num of times the cache entry was retrieved.
    dwSizeLow         AS DWORD      ' low DWORD of the file size.
    dwSizeHigh        AS DWORD      ' high DWORD of the file size.
    LastModifiedTime  AS FILETIME   ' last modified time of the file in GMT format.
    ExpireTime        AS FILETIME   ' expire time of the file in GMT format
    LastAccessTime    AS FILETIME   ' last accessed time in GMT format
    LastSyncTime      AS FILETIME   ' last time the URL was synchronized with the source
    lpHeaderInfo      AS BYTE PTR   ' embedded pointer to the header info.
    dwHeaderInfoSize  AS DWORD      ' size of the above header.
    lpszFileExtension AS ASCIIZ PTR ' File extension used to retrieve the urldata as a file.
    dwExemptDelta     AS DWORD      ' Exemption delta from last access time.
END TYPE

TYPE INTERNET_CACHE_ENTRY_INFOW
    dwStructSize      AS DWORD      ' version of cache system.
    lpszSourceUrlName AS WSTRINGZ PTR ' embedded pointer to the URL name string.
    lpszLocalFileName AS WSTRINGZ PTR ' embedded pointer to the local file name.
    CacheEntryType    AS DWORD      ' cache type bit mask.
    dwUseCount        AS DWORD      ' current users count of the cache entry.
    dwHitRate         AS DWORD      ' num of times the cache entry was retrieved.
    dwSizeLow         AS DWORD      ' low DWORD of the file size.
    dwSizeHigh        AS DWORD      ' high DWORD of the file size.
    LastModifiedTime  AS FILETIME   ' last modified time of the file in GMT format.
    ExpireTime        AS FILETIME   ' expire time of the file in GMT format
    LastAccessTime    AS FILETIME   ' last accessed time in GMT format
    LastSyncTime      AS FILETIME   ' last time the URL was synchronized with the source
    lpHeaderInfo      AS BYTE PTR   ' embedded pointer to the header info.
    dwHeaderInfoSize  AS DWORD      ' size of the above header.
    lpszFileExtension AS WSTRINGZ PTR ' File extension used to retrieve the urldata as a file.
    dwExemptDelta     AS DWORD      ' Exemption delta from last access time.
END TYPE

#IF %DEF(%UNICODE)
TYPE INTERNET_CACHE_ENTRY_INFO
    INTERNET_CACHE_ENTRY_INFOW
END TYPE
#ELSE
TYPE INTERNET_CACHE_ENTRY_INFO
    INTERNET_CACHE_ENTRY_INFOA
END TYPE
#ENDIF

#INCLUDE "iedial.inc"
#INCLUDE "schannel.inc"

%SECURITY_WIN32 = 1

#INCLUDE "sspi.inc"

%WININETEX = 1


%MAX_CACHE_ENTRY_INFO_SIZE     = 4096

'
' These two flags should really be included in a new mask called INTERNET_FLAGS_INTERNAL_MASK.
' Since BGUPDATE is included in INTERNET_FLAGS_MASK already it will cause compile
' errors when used without winineti.h.  FTP_FOLDER_VIEW is not being included
' so as to not compound the problem.
'

%INTERNET_FLAG_BGUPDATE        = &H00000008
%INTERNET_FLAG_FTP_FOLDER_VIEW = &H00000004
%INTERNET_FLAGS_MASK_INTERNAL  = (%INTERNET_FLAGS_MASK OR _
                                  %INTERNET_FLAG_FTP_FOLDER_VIEW)

'
' INTERNET_PREFETCH_STATUS -
'

TYPE INTERNET_PREFETCH_STATUS

    '
    ' dwStatus - status of download. See INTERNET_PREFETCH_ flags
    '

    dwStatus AS DWORD

    '
    ' dwSize - size of file downloaded so far
    '

    dwSize   AS DWORD
END TYPE

'
' INTERNET_PREFETCH_STATUS - dwStatus values
'

%INTERNET_PREFETCH_PROGRESS = 0
%INTERNET_PREFETCH_COMPLETE = 1
%INTERNET_PREFETCH_ABORTED  = 2

TYPE INTERNET_CONNECTED_INFO
    '
    ' dwConnectedState - new connected/disconnected state.
    ' See INTERNET_STATE_CONNECTED, etc.
    '
    dwConnectedState AS DWORD
    '
    ' dwFlags - flags controlling connected->disconnected (or disconnected->
    ' connected) transition. See below
    '
    dwFlags          AS DWORD
END TYPE


TYPE INTERNET_ONLINE_OFFLINE_INFO
    INTERNET_CONNECTED_INFO
END TYPE

MACRO dwOfflineState=dwConnectedState

%ISO_FORCE_DISCONNECTED = &H00000001

%ISO_FORCE_OFFLINE     = %ISO_FORCE_DISCONNECTED


' These flags keep track of security errors on a cached certificate entry
' from WinVerify that was ignored in order to complete the security handshake.
' These flags should not use the same bits as any other SECURITY_FLAGS.

%DLG_FLAGS_INVALID_CA                  = &H01000000
%DLG_FLAGS_SEC_CERT_CN_INVALID         = &H02000000
%DLG_FLAGS_SEC_CERT_DATE_INVALID       = &H04000000
%DLG_FLAGS_SEC_CERT_REV_FAILED         = &H00800000

#IF %DEF(%WINCRYPT_H)
#IF %DEF(%ALGIDDEF)

'
' INTERNET_SECURITY_INFO - contains information about certificate
' and encryption settings for a connection.
'

%INTERNET_SECURITY_INFO_DEFINED = 1

TYPE INTERNET_SECURITY_INFO

    '
    ' dwSize - Size of INTERNET_SECURITY_INFO structure.
    '
    dwSize AS DWORD

    '
    ' pCertificate - Cert context pointing to leaf of certificate chain.
    '
    pCertificate AS CERT_CONTEXT PTR


    '
    ' pcCertChain - Certificate chain for the certificate
    '

    pcCertChain AS CERT_CHAIN_CONTEXT PTR


    ' SECPKG_ATTR_CONNECTION_INFO
    connectionInfo AS SecPkgContext_ConnectionInfo

    ' SECPKG_ATTR_CIPHER_INFO (Supported on >= LH)
    cipherInfo AS SecPkgContext_CipherInfo

    '
    ' pcUnverifiedCertChain - Cert chain from initial WinVerifyTrust state
    '
    pcUnverifiedCertChain AS CERT_CHAIN_CONTEXT

    '
    ' Channel Binding Token
    '

    channelBindingToken AS SecPkgContext_Bindings

END TYPE


TYPE INTERNET_SECURITY_CONNECTION_INFO
    '
    ' dwSize - size of INTERNET_SECURITY_CONNECTION_INFO
    '
    dwSize AS DWORD

    ' fSecure - Is this a secure connection.
    fSecure AS LONG  ' BOOL

    ' SECPKG_ATTR_CONNECTION_INFO
    connectionInfo AS SecPkgContext_ConnectionInfo

    ' SECPKG_ATTR_CIPHER_INFO (Supported on >= LH)
    cipherInfo AS SecPkgContext_CipherInfo
END TYPE


DECLARE FUNCTION InternetAlgIdToStringA LIB "WinINet.dll" _
    ALIAS "InternetAlgIdToStringA" ( _
    BYVAL ai         AS ALG_ID, _
    lpstr            AS ASCIIZ, _
    lpdwBufferLength AS DWORD, _
    BYVAL dwReserved AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION InternetAlgIdToStringW LIB "WinINet.dll" _
    ALIAS "InternetAlgIdToStringW" ( _
    BYVAL ai         AS ALG_ID, _
    lpstr            AS WSTRINGZ, _
    lpdwBufferLength AS DWORD, _
    BYVAL dwReserved AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetAlgIdToString LIB "WinINet.dll" _
    ALIAS "InternetAlgIdToStringW" ( _
    BYVAL ai         AS ALG_ID, _
    lpstr            AS WSTRINGZ, _
    lpdwBufferLength AS DWORD, _
    BYVAL dwReserved AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION InternetAlgIdToString LIB "WinINet.dll" _
    ALIAS "InternetAlgIdToStringA" ( _
    BYVAL ai         AS ALG_ID, _
    lpstr            AS ASCIIZ, _
    lpdwBufferLength AS DWORD, _
    BYVAL dwReserved AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION InternetSecurityProtocolToStringA LIB "WinINet.dll" _
    ALIAS "InternetSecurityProtocolToStringA" ( _
    BYVAL dwProtocol AS DWORD, _
    lpstr            AS ASCIIZ, _
    lpdwBufferLength AS DWORD, _
    BYVAL dwReserved AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION InternetSecurityProtocolToStringW LIB "WinINet.dll" _
    ALIAS "InternetSecurityProtocolToStringW" ( _
    BYVAL dwProtocol AS DWORD, _
    lpstr            AS WSTRINGZ, _
    lpdwBufferLength AS DWORD, _
    BYVAL dwReserved AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetSecurityProtocolToString LIB "WinINet.dll" _
    ALIAS "InternetSecurityProtocolToStringW" ( _
    BYVAL dwProtocol AS DWORD, _
    lpstr            AS WSTRINGZ, _
    lpdwBufferLength AS DWORD, _
    BYVAL dwReserved AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION InternetSecurityProtocolToString LIB "WinINet.dll" _
    ALIAS "InternetSecurityProtocolToStringA" ( _
    BYVAL dwProtocol AS DWORD, _
    lpstr            AS ASCIIZ, _
    lpdwBufferLength AS DWORD, _
    BYVAL dwReserved AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF ' NOT %UNICODE

#IF (%WIN32_IE >= %WIN32_IE_IE70)

'
' This is an API for BrowseUI.  It retrieves
' security info based on a URL
'

DECLARE FUNCTION InternetGetSecurityInfoByURLA LIB "WinINet.dll" _
    ALIAS "InternetGetSecurityInfoByURLA" ( _
    lpszURL        AS ASCIIZ, _
    ppCertChain    AS ANY, _  ' PCCERT_CHAIN_CONTEXT PTR
    pdwSecureFlags AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION InternetGetSecurityInfoByURLW LIB "WinINet.dll" _
    ALIAS "InternetGetSecurityInfoByURLW" ( _
    lpszURL        AS WSTRINGZ, _
    ppCertChain    AS ANY, _  ' PCCERT_CHAIN_CONTEXT PTR
    pdwSecureFlags AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetGetSecurityInfoByURL LIB "WinINet.dll" _
    ALIAS "InternetGetSecurityInfoByURLW" ( _
    lpszURL        AS WSTRINGZ, _
    ppCertChain    AS ANY, _  ' PCCERT_CHAIN_CONTEXT PTR
    pdwSecureFlags AS DWORD _
    ) AS LONG  ' BOOL
#ELSEIF %DEF(%WINX32)
DECLARE FUNCTION InternetGetSecurityInfoByURL LIB "WinINet.dll" _
    ALIAS "InternetGetSecurityInfoByURLA" ( _
    lpszURL        AS ASCIIZ, _
    ppCertChain    AS ANY, _  ' PCCERT_CHAIN_CONTEXT PTR
    pdwSecureFlags AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION InternetGetSecurityInfoByURL LIB "WinINet.dll" _
    ALIAS "InternetGetSecurityInfoByURL" ( _
    lpszURL        AS ASCIIZ, _
    ppCertChain    AS ANY, _  ' PCCERT_CHAIN_CONTEXT PTR
    pdwSecureFlags AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

#ENDIF ' %WIN32_IE >= %WIN32_IE_IE70

#ENDIF ' %ALGIDDEF
#ENDIF ' %WINCRYPT_H

#IF %DEF(%INTERNET_SECURITY_INFO_DEFINED)

DECLARE FUNCTION ShowSecurityInfo LIB "WinINet.dll" _
    ALIAS "ShowSecurityInfo" ( _
    BYVAL hWndParent AS DWORD, _  ' HWND
    pSecurityInfo    AS INTERNET_SECURITY_INFO _
    ) AS DWORD
#ENDIF ' INTERNET_SECURITY_INFO_DEFINED



DECLARE FUNCTION ShowX509EncodedCertificate LIB "WinINet.dll" _
    ALIAS "ShowX509EncodedCertificate" ( _
    BYVAL hWndParent AS DWORD, _  ' HWND
    BYVAL lpCert     AS BYTE PTR, _
    BYVAL cbCert     AS DWORD _
    ) AS DWORD

DECLARE FUNCTION ShowClientAuthCerts LIB "WinINet.dll" _
    ALIAS "ShowClientAuthCerts" ( _
    BYVAL hWndParent AS DWORD _  ' HWND
    ) AS DWORD

DECLARE FUNCTION ParseX509EncodedCertificateForListBoxEntry LIB "WinINet.dll" _
    ALIAS "ParseX509EncodedCertificateForListBoxEntry" ( _
    BYVAL lpCert     AS BYTE PTR, _
    BYVAL cbCert     AS DWORD, _
    lpszListBoxEntry AS ASCIIZ, _
    lpdwListBoxEntry AS DWORD _
    ) AS DWORD

'
' This is a private API for Trident.  It displays
' security info based on a URL
'

DECLARE FUNCTION InternetShowSecurityInfoByURLA LIB "WinINet.dll" _
    ALIAS "InternetShowSecurityInfoByURLA" ( _
    lpszURL          AS ASCIIZ, _
    BYVAL hwndParent AS DWORD _  ' HWND
    ) AS LONG  ' BOOL

DECLARE FUNCTION InternetShowSecurityInfoByURLW LIB "WinINet.dll" _
    ALIAS "InternetShowSecurityInfoByURLW" ( _
    lpszURL          AS WSTRINGZ, _
    BYVAL hwndParent AS DWORD _  ' HWND
    ) AS LONG  ' BOOL

' The InternetGetCertByURL function was never declared in the wininet header
' files.  It is obsolete and deprecated. An attempt was made to add it for
' completeness since it is still exported from wininet.dll. However other
' code has declared it incorrectly.  This causes compiler errors because
' the function ends up with two different declarations in the same compilation
' unit.  It is again not included in the header as anything but this comment.
'
' DECLARE FUNCTION InternetGetCertByURL LIB "WinINet.dll" _
'    ALIAS "InternetGetCertByURL" ( _
'    lpszURL            AS ASCIIZ, _
'    lpszCertText       AS ASCIIZ, _
'    BYVAL dwcbCertText AS DWORD _
'    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetShowSecurityInfoByURL LIB "WinINet.dll" _
    ALIAS "InternetShowSecurityInfoByURLW" ( _
    lpszURL          AS WSTRINGZ, _
    BYVAL hwndParent AS DWORD _  ' HWND
    ) AS LONG  ' BOOL
#ELSEIF %DEF(%WINX32)
DECLARE FUNCTION InternetShowSecurityInfoByURL LIB "WinINet.dll" _
    ALIAS "InternetShowSecurityInfoByURLA" ( _
    lpszURL          AS ASCIIZ, _
    BYVAL hwndParent AS DWORD _  ' HWND
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION InternetShowSecurityInfoByURL LIB "WinINet.dll" _
    ALIAS "InternetShowSecurityInfoByURL" ( _
    lpszURL          AS ASCIIZ, _
    BYVAL hwndParent AS DWORD _  ' HWND
    ) AS LONG  ' BOOL
#ENDIF

'Fortezza related exports. not public

' The commands that InternetFortezzaCommand supports.

MACRO FORTCMD_enum=LONG
ENUM FORTCMD SINGULAR
    FORTCMD_LOGON           = 1
    FORTCMD_LOGOFF
    FORTCMD_CHG_PERSONALITY
END ENUM


DECLARE FUNCTION InternetFortezzaCommand LIB "WinINet.dll" _
    ALIAS "InternetFortezzaCommand" ( _
    BYVAL dwCommand  AS DWORD, _
    BYVAL hwnd       AS DWORD, _  ' HWND
    BYVAL dwReserved AS DWORD _
    ) AS LONG  ' BOOL

MACRO FORTSTAT_enum=LONG
ENUM FORTSTAT SINGULAR
    FORTSTAT_INSTALLED = &H00000001
    FORTSTAT_LOGGEDON
END ENUM

DECLARE FUNCTION InternetQueryFortezzaStatus LIB "WinINet.dll" _
    ALIAS "InternetQueryFortezzaStatus" ( _
    pdwStatus        AS DWORD, _
    BYVAL dwReserved AS DWORD _
    ) AS LONG  ' BOOL


DECLARE FUNCTION InternetDebugGetLocalTime LIB "WinINet.dll" _
    ALIAS "InternetDebugGetLocalTime" ( _
    pstLocalTime AS SYSTEMTIME, _
    pdwReserved  AS DWORD _
    ) AS LONG  ' BOOL


' causes InternetCreateUrlA to escape chars in authority components
' (user, pwd, host)
%ICU_ESCAPE_AUTHORITY = &H00002000

%INTERNET_SERVICE_URL = 0
'
' InternetConnectUrl() - a macro which allows you to specify an URL instead of
' the component parts to InternetConnect(). If any API which uses the returned
' connect handle specifies a NULL path then the URL-path part of the URL
' specified in InternetConnectUrl() will be used
'

FUNCTION InternetConnectUrlA (BYVAL hInternet AS DWORD, _
                             lpszUrl AS ASCIIZ, _
                             BYVAL dwFlags AS DWORD, _
                             BYVAL dwContext AS DWORD) AS DWORD
    FUNCTION = InternetConnectA(hInternet, lpszUrl, _
       %INTERNET_INVALID_PORT_NUMBER, BYVAL %NULL, BYVAL %NULL, _
       %INTERNET_SERVICE_URL, dwFlags, dwContext)
END FUNCTION

FUNCTION InternetConnectUrlW (BYVAL hInternet AS DWORD, _
                             lpszUrl AS WSTRINGZ, _
                             BYVAL dwFlags AS DWORD, _
                             BYVAL dwContext AS DWORD) AS DWORD
    FUNCTION = InternetConnectW(hInternet, lpszUrl, _
       %INTERNET_INVALID_PORT_NUMBER, BYVAL %NULL, BYVAL %NULL, _
       %INTERNET_SERVICE_URL, dwFlags, dwContext)
END FUNCTION

#IF %DEF(%UNICODE)
FUNCTION InternetConnectUrl (BYVAL hInternet AS DWORD, _
                             lpszUrl AS WSTRINGZ, _
                             BYVAL dwFlags AS DWORD, _
                             BYVAL dwContext AS DWORD) AS DWORD
    FUNCTION = InternetConnectW(hInternet, lpszUrl, _
       %INTERNET_INVALID_PORT_NUMBER, BYVAL %NULL, BYVAL %NULL, _
       %INTERNET_SERVICE_URL, dwFlags, dwContext)
END FUNCTION
#ELSE
FUNCTION InternetConnectUrl (BYVAL hInternet AS DWORD, _
                             lpszUrl AS ASCIIZ, _
                             BYVAL dwFlags AS DWORD, _
                             BYVAL dwContext AS DWORD) AS DWORD
    FUNCTION = InternetConnectA(hInternet, lpszUrl, _
       %INTERNET_INVALID_PORT_NUMBER, BYVAL %NULL, BYVAL %NULL, _
       %INTERNET_SERVICE_URL, dwFlags, dwContext)
END FUNCTION
#ENDIF

DECLARE FUNCTION InternetWriteFileExA LIB "WinINet.dll" _
    ALIAS "InternetWriteFileExA" ( _
    BYVAL hFile       AS DWORD, _  ' HINTERNET
    BYVAL lpBuffersIn AS INTERNET_BUFFERSA PTR, _
    BYVAL dwFlags     AS DWORD, _
    BYVAL dwContext   AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION InternetWriteFileExW LIB "WinINet.dll" _
    ALIAS "InternetWriteFileExW" ( _
    BYVAL hFile       AS DWORD, _  ' HINTERNET
    BYVAL lpBuffersIn AS INTERNET_BUFFERSW PTR, _
    BYVAL dwFlags     AS DWORD, _
    BYVAL dwContext   AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetWriteFileEx LIB "WinINet.dll" _
    ALIAS "InternetWriteFileExW" ( _
    BYVAL hFile       AS DWORD, _  ' HINTERNET
    BYVAL lpBuffersIn AS INTERNET_BUFFERSW PTR, _
    BYVAL dwFlags     AS DWORD, _
    BYVAL dwContext   AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION InternetWriteFileEx LIB "WinINet.dll" _
    ALIAS "InternetWriteFileExA" ( _
    BYVAL hFile       AS DWORD, _  ' HINTERNET
    BYVAL lpBuffersIn AS INTERNET_BUFFERSA PTR, _
    BYVAL dwFlags     AS DWORD, _
    BYVAL dwContext   AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF ' NOT %UNICODE

%INTERNET_OPTION_CONTEXT_VALUE_OLD      = 10
%INTERNET_OPTION_NET_SPEED              = 61
' Pass in pointer to INTERNET_SECURITY_CONNECTION_INFO to be filled in.
%INTERNET_OPTION_SECURITY_CONNECTION_INFO = 66
%INTERNET_OPTION_DETECT_POST_SEND       = 71
%INTERNET_OPTION_DISABLE_NTLM_PREAUTH   = 72
%INTERNET_OPTION_ORIGINAL_CONNECT_FLAGS = 97


%INTERNET_OPTION_CERT_ERROR_FLAGS             = 98
%INTERNET_OPTION_IGNORE_CERT_ERROR_FLAGS      = 99

%INTERNET_OPTION_SESSION_START_TIME           = 106
%INTERNET_OPTION_PROXY_CREDENTIALS            = 107
%INTERNET_OPTION_EXTENDED_CALLBACKS           = 108
%INTERNET_OPTION_PROXY_FROM_REQUEST           = 109
%INTERNET_OPTION_ALLOW_FAILED_CONNECT_CONTENT = 110
%INTERNET_OPTION_CACHE_PARTITION              = 111
%INTERNET_OPTION_AUTODIAL_HWND                = 112
%INTERNET_OPTION_SERVER_CREDENTIALS           = 113
%INTERNET_OPTION_WPAD_SLEEP                   = 114
%INTERNET_LAST_OPTION_INTERNAL        = %INTERNET_OPTION_WPAD_SLEEP

%INTERNET_OPTION_DISCONNECTED_TIMEOUT    = 49
%INTERNET_OPTION_CONNECTED_STATE         = 50


%INTERNET_OPTION_OFFLINE_TIMEOUT = %INTERNET_OPTION_DISCONNECTED_TIMEOUT
%INTERNET_OPTION_LINE_STATE      = %INTERNET_OPTION_CONNECTED_STATE

%AUTH_FLAG_RESET                       = &H00000000  ' let registry decide

'
' Extended callbacks.
'
' They can happen outside the context of the registered session's API calls.
'

%INTERNET_STATUS_PROXY_CREDENTIALS       = 400
%INTERNET_STATUS_SERVER_CREDENTIALS      = 401
%INTERNET_STATUS_SERVER_CONNECTION_STATE = 410
%INTERNET_STATUS_END_BROWSER_SESSION     = 420
%INTERNET_STATUS_COOKIE                  = 430

'
' Extended callback data structures.
'

TYPE INTERNET_SERVER_CONNECTION_STATE
    lpcwszHostName        AS WSTRINGZ PTR
    fProxy                AS LONG   ' BOOL ' Is this a proxy?
    dwCounter             AS DWORD  ' Server connection state callback counter.
    dwConnectionLimit     AS DWORD  ' Current Limit.
    dwAvailableCreates    AS DWORD  ' Connections allowed to be created.
    dwAvailableKeepAlives AS DWORD  ' Keep alive connections available to be used.
    dwActiveConnections   AS DWORD  ' Current number of active connections.
    dwWaiters             AS DWORD  ' Number of request waiting on connections.
END TYPE

TYPE INTERNET_END_BROWSER_SESSION_DATA
    lpBuffer       AS DWORD  ' LPVOID
    dwBufferLength AS DWORD
END TYPE

TYPE INTERNET_CALLBACK_COOKIE
    pcwszName   AS WSTRINGZ PTR
    pcwszValue  AS WSTRINGZ PTR
    pcwszDomain AS WSTRINGZ PTR
    pcwszPath   AS WSTRINGZ PTR
    ftExpires   AS FILETIME
    dwFlags     AS DWORD
END TYPE


TYPE INTERNET_CREDENTIALS_type
    lpcwszUserName AS WSTRINGZ PTR
    lpcwszPassword AS WSTRINGZ PTR
END TYPE

UNION INTERNET_CREDENTIALS_union
    INTERNET_CREDENTIALS_type
    pAuthIdentityOpaque AS DWORD  ' PVOID
END UNION

TYPE INTERNET_CREDENTIALS
    lpcwszHostName AS WSTRINGZ PTR
    dwPort         AS DWORD
    dwScheme       AS DWORD
    lpcwszUrl      AS WSTRINGZ PTR
    lpcwszRealm    AS WSTRINGZ PTR
    fAuthIdentity  AS LONG  ' BOOL ' TRUE if pAuthIdentityOpaque is used in below struct.
    INTERNET_CREDENTIALS_union
END TYPE


'
' !!! NOTE !!!
'
' these defines are needed beecause PREFAST donesn't understand enums in
' range specifications. Make sure that these are always in sync with any
' changes to the InternetCookieState enum, above.
'
%COOKIE_STATE_LB   = 0   ' COOKIE_STATE_UNKNOWN
%COOKIE_STATE_UB   = 5   ' COOKIE_STATE_MAX

' maximum length of privacy settings in Unicode characters
%MaxPrivacySettings    = &H4000

' Utility for mapping P3P compact-policy tokens to unique indexes
DECLARE FUNCTION FindP3PPolicySymbol LIB "WinINet.dll" _
    ALIAS "FindP3PPolicySymbol" ( _
    pszSymbol AS ASCIIZ _
    ) AS LONG


%INTERNET_STATE_CONNECTED              = &H00000001  ' connected state (mutually exclusive with disconnected)
%INTERNET_STATE_DISCONNECTED           = &H00000002  ' disconnected from network
%INTERNET_STATE_DISCONNECTED_BY_USER   = &H00000010  ' disconnected by user request
%INTERNET_STATE_IDLE                   = &H00000100  ' no network requests being made (by Wininet)
%INTERNET_STATE_BUSY                   = &H00000200  ' network requests being made (by Wininet)


%INTERNET_STATE_ONLINE       = %INTERNET_STATE_CONNECTED
%INTERNET_STATE_OFFLINE      = %INTERNET_STATE_DISCONNECTED
%INTERNET_STATE_OFFLINE_USER = %INTERNET_STATE_DISCONNECTED_BY_USER
%INTERNET_LINE_STATE_MASK    = (%INTERNET_STATE_ONLINE OR %INTERNET_STATE_OFFLINE)
%INTERNET_BUSY_STATE_MASK    = (%INTERNET_STATE_IDLE OR %INTERNET_STATE_BUSY)



'
' the following are used with InternetSetOption(..., INTERNET_OPTION_CALLBACK_FILTER, ...)
' to filter out unrequired callbacks. INTERNET_STATUS_REQUEST_COMPLETE cannot
' be filtered out
'

%INTERNET_STATUS_FILTER_RESOLVING      = &H00000001
%INTERNET_STATUS_FILTER_RESOLVED       = &H00000002
%INTERNET_STATUS_FILTER_CONNECTING     = &H00000004
%INTERNET_STATUS_FILTER_CONNECTED      = &H00000008
%INTERNET_STATUS_FILTER_SENDING        = &H00000010
%INTERNET_STATUS_FILTER_SENT           = &H00000020
%INTERNET_STATUS_FILTER_RECEIVING      = &H00000040
%INTERNET_STATUS_FILTER_RECEIVED       = &H00000080
%INTERNET_STATUS_FILTER_CLOSING        = &H00000100
%INTERNET_STATUS_FILTER_CLOSED         = &H00000200
%INTERNET_STATUS_FILTER_HANDLE_CREATED = &H00000400
%INTERNET_STATUS_FILTER_HANDLE_CLOSING = &H00000800
%INTERNET_STATUS_FILTER_PREFETCH       = &H00001000
%INTERNET_STATUS_FILTER_REDIRECT       = &H00002000
%INTERNET_STATUS_FILTER_STATE_CHANGE   = &H00004000


'
' Note that adding any HTTP_QUERY_* codes here must be followed
'   by an equivlent line in wininet\http\hashgen\hashgen.cpp
'   please see that file for further information regarding
'   the addition of new HTTP headers
'


' These are not part of HTTP 1.1 yet. We will propose these to the
' HTTP extensions working group. These are required for the client-caps support
' we are doing in conjuntion with IIS.

TYPE INTERNET_COOKIE
    cbSize       AS DWORD
    pszName      AS ASCIIZ PTR
    pszData      AS ASCIIZ PTR
    pszDomain    AS ASCIIZ PTR
    pszPath      AS ASCIIZ PTR
    pftExpires   AS FILETIME PTR
    dwFlags      AS DWORD
    pszUrl       AS ASCIIZ PTR
    pszP3PPolicy AS ASCIIZ PTR
END TYPE

'
' Support for handling cookie policy
'

TYPE COOKIE_DLG_INFO
    pszServer     AS WSTRINGZ PTR
    pic           AS INTERNET_COOKIE PTR
    dwStopWarning AS DWORD
    cx            AS LONG
    cy            AS LONG
    pszHeader     AS WSTRINGZ PTR
    dwOperation   AS DWORD
END TYPE

' values returned from cookie UI, for dwStopWarning member
%COOKIE_DONT_ALLOW     = 1
%COOKIE_ALLOW          = 2
%COOKIE_ALLOW_ALL      = 4
%COOKIE_DONT_ALLOW_ALL = 8

' values for dwOperation member
%COOKIE_OP_SET         = &H01
%COOKIE_OP_MODIFY      = &H02
%COOKIE_OP_GET         = &H04
%COOKIE_OP_SESSION     = &H08
%COOKIE_OP_PERSISTENT  = &H10
%COOKIE_OP_3RD_PARTY   = &H20


' INTERNET_COOKIE_RESTRICTED_ZONE is the same as INTERNET_FLAG_RESTRICTED_ZONE
%INTERNET_COOKIE_RESTRICTED_ZONE = &H00020000
%INTERNET_COOKIE_NO_CALLBACK     = &H40000000
%INTERNET_COOKIE_ECTX_3RDPARTY   = &H80000000???
'
' DAV Detection
'
' [these functions are not documented and do not appear to be exported]
'DECLARE FUNCTION HttpCheckDavComplianceA LIB "WinINet.dll" _
'    ALIAS "HttpCheckDavComplianceA" ( _
'    lpszUrl             AS ASCIIZ, _
'    lpszComplianceToken AS ASCIIZ, _
'    lpfFound            AS LONG, _   ' BOOL
'    BYVAL hWnd          AS DWORD, _  ' HWND
'    lpvReserved         AS ANY _     ' LPVOID
'    ) AS LONG  ' BOOL
' INTERNET_COOKIE_RESTRICTED_ZONE is the same as INTERNET_FLAG_RESTRICTED_ZONE
%INTERNET_COOKIE_RESTRICTED_ZONE = &H00020000
%INTERNET_COOKIE_NO_CALLBACK     = &H40000000
%INTERNET_COOKIE_ECTX_3RDPARTY   = &H80000000???
'
' DAV Detection
'
' [these functions are not documented and do not appear to be exported]
'DECLARE FUNCTION HttpCheckDavComplianceW LIB "WinINet.dll" _
'    ALIAS "HttpCheckDavComplianceW" ( _
'    lpszUrl             AS WSTRINGZ, _
'    lpszComplianceToken AS WSTRINGZ, _
'    lpfFound            AS LONG, _   ' BOOL
'    BYVAL hWnd          AS DWORD, _  ' HWND
'    lpvReserved         AS ANY _     ' LPVOID
'    ) AS LONG  ' BOOL
'#IF %DEF(%UNICODE)
'MACRO HttpCheckDavCompliance=HttpCheckDavComplianceW
'#ELSE
'MACRO HttpCheckDavCompliance=HttpCheckDavComplianceA
'#ENDIF ' NOT %UNICODE

' [these functions are not documented and do not appear to be exported]
'DECLARE FUNCTION HttpCheckCachedDavStatusA LIB "WinINet.dll" _
'    ALIAS "HttpCheckCachedDavStatusA" ( _
'    lpszUrl    AS ASCIIZ, _
'    lpdwStatus AS DWORD _
'    ) AS LONG  ' BOOL
'DECLARE FUNCTION HttpCheckCachedDavStatusW LIB "WinINet.dll" _
'    ALIAS "HttpCheckCachedDavStatusW" ( _
'    lpszUrl    AS WSTRINGZ, _
'    lpdwStatus AS DWORD _
'    ) AS LONG  ' BOOL
'#IF %DEF(%UNICODE)
'MACRO HttpCheckCachedDavStatus=HttpCheckCachedDavStatusW
'#ELSE
'MACRO HttpCheckCachedDavStatus=HttpCheckCachedDavStatusA
'#ENDIF ' NOT %UNICODE

' [these functions are not documented and do not appear to be exported]
'DECLARE FUNCTION HttpCheckDavCollectionA LIB "WinINet.dll" _
'    ALIAS "HttpCheckDavCollectionA" ( _
'    lpszUrl     AS ASCIIZ, _
'    lpfFound    AS LONG, _   ' BOOL
'    BYVAL hWnd  AS DWORD, _  ' HWND
'    lpvReserved AS ANY _     ' LPVOID
'    ) AS LONG  ' BOOL
'DECLARE FUNCTION HttpCheckDavCollectionW LIB "WinINet.dll" _
'    ALIAS "HttpCheckDavCollectionW" ( _
'    lpszUrl     AS WSTRINGZ, _
'    lpfFound    AS LONG, _   ' BOOL
'    BYVAL hWnd  AS DWORD, _  ' HWND
'    lpvReserved AS ANY _     ' LPVOID
'    ) AS LONG  ' BOOL
'#IF %DEF(%UNICODE)
'MACRO HttpCheckDavCollection=HttpCheckDavCollectionW
'#ELSE
'MACRO HttpCheckDavCollection=HttpCheckDavCollectionA
'#ENDIF ' NOT %UNICODE

%INTERNET_ERROR_BASE                     = 12000
%ERROR_INTERNET_DISCONNECTED             = (%INTERNET_ERROR_BASE + 163)


' DAV detection defines
%DAV_LEVEL1_STATUS                = &H00000001
%DAV_COLLECTION_STATUS            = &H00004000
%DAV_DETECTION_REQUIRED           = &H00008000
%FLAGS_ERROR_UI_SHOW_IDN_HOSTNAME = &H20
%ERROR_INTERNET_NO_NEW_CONTAINERS = (%INTERNET_ERROR_BASE + 51)

%ERROR_INTERNET_OFFLINE = %ERROR_INTERNET_DISCONNECTED

'
' internal error codes that are used to communicate specific information inside
' of Wininet but which are meaningless at the interface
'

%INTERNET_INTERNAL_ERROR_BASE            = (%INTERNET_ERROR_BASE + 900)

%ERROR_INTERNET_INTERNAL_SOCKET_ERROR    = (%INTERNET_INTERNAL_ERROR_BASE + 1)
%ERROR_INTERNET_CONNECTION_AVAILABLE     = (%INTERNET_INTERNAL_ERROR_BASE + 2)
%ERROR_INTERNET_NO_KNOWN_SERVERS         = (%INTERNET_INTERNAL_ERROR_BASE + 3)
%ERROR_INTERNET_PING_FAILED              = (%INTERNET_INTERNAL_ERROR_BASE + 4)
%ERROR_INTERNET_NO_PING_SUPPORT          = (%INTERNET_INTERNAL_ERROR_BASE + 5)
%ERROR_INTERNET_CACHE_SUCCESS            = (%INTERNET_INTERNAL_ERROR_BASE + 6)
%ERROR_HTTP_COOKIE_NEEDS_CONFIRMATION_EX = (%INTERNET_INTERNAL_ERROR_BASE + 7)
%HTTP_1_1_CACHE_ENTRY            = &H00000040
%STATIC_CACHE_ENTRY              = &H00000080
%MUST_REVALIDATE_CACHE_ENTRY     = &H00000100
%SHORTPATH_CACHE_ENTRY           = &H00000200
%COOKIE_ACCEPTED_CACHE_ENTRY     = &H00001000
%COOKIE_LEASHED_CACHE_ENTRY      = &H00002000
%COOKIE_DOWNGRADED_CACHE_ENTRY   = &H00004000
%COOKIE_REJECTED_CACHE_ENTRY     = &H00008000
%PRIVACY_MODE_CACHE_ENTRY        = &H00020000
%XDR_CACHE_ENTRY                 = &H00040000
%PENDING_DELETE_CACHE_ENTRY      = &H00400000
%OTHER_USER_CACHE_ENTRY          = &H00800000
%PRIVACY_IMPACTED_CACHE_ENTRY    = &H02000000
%POST_RESPONSE_CACHE_ENTRY       = &H04000000
%INSTALLED_CACHE_ENTRY           = &H10000000
%POST_CHECK_CACHE_ENTRY          = &H20000000
%IDENTITY_CACHE_ENTRY            = &H80000000???
%ANY_CACHE_ENTRY                 = &HFFFFFFFF???

' We include some entry types even if app doesn't specifically ask for them.
%INCLUDE_BY_DEFAULT_CACHE_ENTRY = _
    (%HTTP_1_1_CACHE_ENTRY _
    OR %STATIC_CACHE_ENTRY _
    OR %MUST_REVALIDATE_CACHE_ENTRY _
    OR %PRIVACY_IMPACTED_CACHE_ENTRY _
    OR %POST_CHECK_CACHE_ENTRY _
    OR %COOKIE_ACCEPTED_CACHE_ENTRY _
    OR %COOKIE_LEASHED_CACHE_ENTRY _
    OR %COOKIE_DOWNGRADED_CACHE_ENTRY _
    OR %COOKIE_REJECTED_CACHE_ENTRY _
    OR %SHORTPATH_CACHE_ENTRY _
    )

%CACHEGROUP_FLAG_VALID               = &H00000007

'
' Well known sticky group ID
'
%CACHEGROUP_ID_BUILTIN_STICKY       = &H1000000000000007

'
' INTERNET_CACHE_CONFIG_PATH_ENTRY
'

TYPE INTERNET_CACHE_CONFIG_PATH_ENTRYA
    CachePath   AS ASCIIZ * %MAX_PATH
    dwCacheSize AS DWORD   ' in KBytes
END TYPE

TYPE INTERNET_CACHE_CONFIG_PATH_ENTRYW
    CachePath   AS WSTRINGZ * %MAX_PATH
    dwCacheSize AS DWORD   ' in KBytes
END TYPE

#IF %DEF(%UNICODE)
TYPE INTERNET_CACHE_CONFIG_PATH_ENTRY
    INTERNET_CACHE_CONFIG_PATH_ENTRYW
END TYPE
#ELSE
TYPE INTERNET_CACHE_CONFIG_PATH_ENTRY
    INTERNET_CACHE_CONFIG_PATH_ENTRYA
END TYPE
#ENDIF ' %UNICODE

'
' INTERNET_CACHE_CONFIG_INFO
'

TYPE INTERNET_CACHE_CONFIG_INFOA_type
    CachePath   AS ASCIIZ * %MAX_PATH
    dwCacheSize AS DWORD
END TYPE

UNION INTERNET_CACHE_CONFIG_INFOA_union
    INTERNET_CACHE_CONFIG_INFOA_type
    CachePaths(%ANYSIZE_ARRAY-1) AS INTERNET_CACHE_CONFIG_PATH_ENTRYA
END UNION

TYPE INTERNET_CACHE_CONFIG_INFOA
    dwStructSize    AS DWORD
    dwContainer     AS DWORD
    dwQuota         AS DWORD
    dwReserved4     AS DWORD
    fPerUser        AS LONG  ' BOOL
    dwSyncMode      AS DWORD
    dwNumCachePaths AS DWORD
    INTERNET_CACHE_CONFIG_INFOA_union
    dwNormalUsage   AS DWORD
    dwExemptUsage   AS DWORD
END TYPE

TYPE INTERNET_CACHE_CONFIG_INFOW_type
    CachePath   AS WSTRINGZ * %MAX_PATH
    dwCacheSize AS DWORD
END TYPE

UNION INTERNET_CACHE_CONFIG_INFOW_union
    INTERNET_CACHE_CONFIG_INFOW_type
    CachePaths(%ANYSIZE_ARRAY-1) AS INTERNET_CACHE_CONFIG_PATH_ENTRYW
END UNION

TYPE INTERNET_CACHE_CONFIG_INFOW
    dwStructSize    AS DWORD
    dwContainer     AS DWORD
    dwQuota         AS DWORD
    dwReserved4     AS DWORD
    fPerUser        AS LONG  ' BOOL
    dwSyncMode      AS DWORD
    dwNumCachePaths AS DWORD
    INTERNET_CACHE_CONFIG_INFOW_union
    dwNormalUsage   AS DWORD
    dwExemptUsage   AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE INTERNET_CACHE_CONFIG_INFO
    INTERNET_CACHE_CONFIG_INFOW
END TYPE
#ELSE
TYPE INTERNET_CACHE_CONFIG_INFO
    INTERNET_CACHE_CONFIG_INFOA
END TYPE
#ENDIF ' %UNICODE



DECLARE FUNCTION IsUrlCacheEntryExpiredA LIB "WinINet.dll" _
    ALIAS "IsUrlCacheEntryExpiredA" ( _
    lpszUrlName     AS ASCIIZ, _
    BYVAL dwFlags   AS DWORD, _
    pftLastModified AS FILETIME _
    ) AS LONG  ' BOOL

DECLARE FUNCTION IsUrlCacheEntryExpiredW LIB "WinINet.dll" _
    ALIAS "IsUrlCacheEntryExpiredW" ( _
    lpszUrlName     AS WSTRINGZ, _
    BYVAL dwFlags   AS DWORD, _
    pftLastModified AS FILETIME _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION IsUrlCacheEntryExpired LIB "WinINet.dll" _
    ALIAS "IsUrlCacheEntryExpiredW" ( _
    lpszUrlName     AS WSTRINGZ, _
    BYVAL dwFlags   AS DWORD, _
    pftLastModified AS FILETIME _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION IsUrlCacheEntryExpiredA LIB "WinINet.dll" _
    ALIAS "IsUrlCacheEntryExpiredA" ( _
    lpszUrlName     AS ASCIIZ, _
    BYVAL dwFlags   AS DWORD, _
    pftLastModified AS FILETIME _
    ) AS LONG  ' BOOL
#ENDIF ' NOT %UNICODE


%INTERNET_CACHE_FLAG_ALLOW_COLLISIONS     = &H00000100
%INTERNET_CACHE_FLAG_INSTALLED_ENTRY      = &H00000200
%INTERNET_CACHE_FLAG_ENTRY_OR_MAPPING     = &H00000400
%INTERNET_CACHE_FLAG_ADD_FILENAME_ONLY    = &H00000800
%INTERNET_CACHE_FLAG_GET_STRUCT_ONLY      = &H00001000
%CACHE_ENTRY_TYPE_FC         = &H00001000
%CACHE_ENTRY_MODIFY_DATA_FC  = &H80000000??? ' this appears unused

' Flags for CreateContainer

%INTERNET_CACHE_CONTAINER_NOSUBDIRS     = &H1
%INTERNET_CACHE_CONTAINER_AUTODELETE    = &H2
%INTERNET_CACHE_CONTAINER_RESERVED1     = &H4
%INTERNET_CACHE_CONTAINER_NODESKTOPINIT = &H8
%INTERNET_CACHE_CONTAINER_MAP_ENABLED   = &H10

DECLARE FUNCTION CreateUrlCacheContainerA LIB "WinINet.dll" _
    ALIAS "CreateUrlCacheContainerA" ( _
    Name                  AS ASCIIZ, _
    lpCachePrefix         AS ASCIIZ, _
    lpszCachePath         AS ASCIIZ, _
    BYVAL KBCacheLimit    AS DWORD, _
    BYVAL dwContainerType AS DWORD, _
    BYVAL dwOptions       AS DWORD, _
    pvBuffer              AS ANY, _  ' LPVOID
    cbBuffer              AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION CreateUrlCacheContainerW LIB "WinINet.dll" _
    ALIAS "CreateUrlCacheContainerW" ( _
    Name                  AS WSTRINGZ, _
    lpCachePrefix         AS WSTRINGZ, _
    lpszCachePath         AS WSTRINGZ, _
    BYVAL KBCacheLimit    AS DWORD, _
    BYVAL dwContainerType AS DWORD, _
    BYVAL dwOptions       AS DWORD, _
    pvBuffer              AS ANY, _  ' LPVOID
    cbBuffer              AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateUrlCacheContainer LIB "WinINet.dll" _
    ALIAS "CreateUrlCacheContainerW" ( _
    Name                  AS WSTRINGZ, _
    lpCachePrefix         AS WSTRINGZ, _
    lpszCachePath         AS WSTRINGZ, _
    BYVAL KBCacheLimit    AS DWORD, _
    BYVAL dwContainerType AS DWORD, _
    BYVAL dwOptions       AS DWORD, _
    pvBuffer              AS ANY, _  ' LPVOID
    cbBuffer              AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CreateUrlCacheContainer LIB "WinINet.dll" _
    ALIAS "CreateUrlCacheContainerA" ( _
    Name                  AS ASCIIZ, _
    lpCachePrefix         AS ASCIIZ, _
    lpszCachePath         AS ASCIIZ, _
    BYVAL KBCacheLimit    AS DWORD, _
    BYVAL dwContainerType AS DWORD, _
    BYVAL dwOptions       AS DWORD, _
    pvBuffer              AS ANY, _  ' LPVOID
    cbBuffer              AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DeleteUrlCacheContainerA LIB "WinINet.dll" _
    ALIAS "DeleteUrlCacheContainerA" ( _
    Name            AS ASCIIZ, _
    BYVAL dwOptions AS DWORD _
    ) AS LONG  ' BOOL
DECLARE FUNCTION DeleteUrlCacheContainerW LIB "WinINet.dll" _
    ALIAS "DeleteUrlCacheContainerW" ( _
    Name            AS WSTRINGZ, _
    BYVAL dwOptions AS DWORD _
    ) AS LONG  ' BOOL
#IF %DEF(%UNICODE)
DECLARE FUNCTION DeleteUrlCacheContainer LIB "WinINet.dll" _
    ALIAS "DeleteUrlCacheContainerW" ( _
    Name            AS WSTRINGZ, _
    BYVAL dwOptions AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION DeleteUrlCacheContainer LIB "WinINet.dll" _
    ALIAS "DeleteUrlCacheContainerA" ( _
    Name            AS ASCIIZ, _
    BYVAL dwOptions AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF ' NOT %UNICODE

'
' INTERNET_CACHE_ENTRY_INFO -
'


TYPE INTERNET_CACHE_CONTAINER_INFOA
    dwCacheVersion  AS DWORD       ' version of software
    lpszName        AS ASCIIZ PTR  ' embedded pointer to the container name string.
    lpszCachePrefix AS ASCIIZ PTR  ' embedded pointer to the container URL prefix
    lpszVolumeLabel AS ASCIIZ PTR  ' embedded pointer to the container volume label if any.
    lpszVolumeTitle AS ASCIIZ PTR  ' embedded pointer to the container volume title if any.
END TYPE

TYPE INTERNET_CACHE_CONTAINER_INFOW
    dwCacheVersion  AS DWORD        ' version of software
    lpszName        AS WSTRINGZ PTR ' embedded pointer to the container name string.
    lpszCachePrefix AS WSTRINGZ PTR ' embedded pointer to the container URL prefix
    lpszVolumeLabel AS WSTRINGZ PTR ' embedded pointer to the container volume label if any.
    lpszVolumeTitle AS WSTRINGZ PTR ' embedded pointer to the container volume title if any.
END TYPE

#IF %DEF(%UNICODE)
TYPE INTERNET_CACHE_CONTAINER_INFO
    INTERNET_CACHE_CONTAINER_INFOW
END TYPE
#ELSE
TYPE INTERNET_CACHE_CONTAINER_INFO
    INTERNET_CACHE_CONTAINER_INFOA
END TYPE
#ENDIF ' UNICODE

'  FindFirstContainer options
%CACHE_FIND_CONTAINER_RETURN_NOCHANGE = &H1

DECLARE FUNCTION FindFirstUrlCacheContainerA LIB "WinINet.dll" _
    ALIAS "FindFirstUrlCacheContainerA" ( _
    pdwModified       AS DWORD, _
    lpContainerInfo   AS INTERNET_CACHE_CONTAINER_INFOA, _
    lpcbContainerInfo AS DWORD, _
    BYVAL dwOptions   AS DWORD _
    ) AS DWORD  ' HANDLE
DECLARE FUNCTION FindFirstUrlCacheContainerW LIB "WinINet.dll" _
    ALIAS "FindFirstUrlCacheContainerW" ( _
    pdwModified       AS DWORD, _
    lpContainerInfo   AS INTERNET_CACHE_CONTAINER_INFOW, _
    lpcbContainerInfo AS DWORD, _
    BYVAL dwOptions   AS DWORD _
    ) AS DWORD  ' HANDLE
#IF %DEF(%UNICODE)
DECLARE FUNCTION FindFirstUrlCacheContainer LIB "WinINet.dll" _
    ALIAS "FindFirstUrlCacheContainerW" ( _
    pdwModified       AS DWORD, _
    lpContainerInfo   AS INTERNET_CACHE_CONTAINER_INFOW, _
    lpcbContainerInfo AS DWORD, _
    BYVAL dwOptions   AS DWORD _
    ) AS DWORD  ' HANDLE
#ELSE
DECLARE FUNCTION FindFirstUrlCacheContainer LIB "WinINet.dll" _
    ALIAS "FindFirstUrlCacheContainerA" ( _
    pdwModified       AS DWORD, _
    lpContainerInfo   AS INTERNET_CACHE_CONTAINER_INFOA, _
    lpcbContainerInfo AS DWORD, _
    BYVAL dwOptions   AS DWORD _
    ) AS DWORD  ' HANDLE
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION FindNextUrlCacheContainerA LIB "WinINet.dll" _
    ALIAS "FindNextUrlCacheContainerA" ( _
    BYVAL hEnumHandle AS DWORD, _  ' HANDLE
    lpContainerInfo   AS INTERNET_CACHE_CONTAINER_INFOA, _
    lpcbContainerInfo AS DWORD _
    ) AS LONG  ' BOOL
DECLARE FUNCTION FindNextUrlCacheContainerW LIB "WinINet.dll" _
    ALIAS "FindNextUrlCacheContainerW" ( _
    BYVAL hEnumHandle AS DWORD, _  ' HANDLE
    lpContainerInfo   AS INTERNET_CACHE_CONTAINER_INFOW, _
    lpcbContainerInfo AS DWORD _
    ) AS LONG  ' BOOL
#IF %DEF(%UNICODE)
DECLARE FUNCTION FindNextUrlCacheContainer LIB "WinINet.dll" _
    ALIAS "FindNextUrlCacheContainerW" ( _
    BYVAL hEnumHandle AS DWORD, _  ' HANDLE
    lpContainerInfo   AS INTERNET_CACHE_CONTAINER_INFOW, _
    lpcbContainerInfo AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION FindNextUrlCacheContainer LIB "WinINet.dll" _
    ALIAS "FindNextUrlCacheContainerA" ( _
    BYVAL hEnumHandle AS DWORD, _  ' HANDLE
    lpContainerInfo   AS INTERNET_CACHE_CONTAINER_INFOA, _
    lpcbContainerInfo AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF ' NOT %UNICODE


MACRO WININET_SYNC_MODE_enum=LONG
ENUM WININET_SYNC_MODE SINGULAR
    WININET_SYNC_MODE_NEVER
    WININET_SYNC_MODE_ON_EXPIRY  ' bogus
    WININET_SYNC_MODE_ONCE_PER_SESSION
    WININET_SYNC_MODE_ALWAYS
    WININET_SYNC_MODE_AUTOMATIC
    WININET_SYNC_MODE_DEFAULT = %WININET_SYNC_MODE_AUTOMATIC
END ENUM


DECLARE FUNCTION FreeUrlCacheSpaceA LIB "WinINet.dll" _
    ALIAS "FreeUrlCacheSpaceA" ( _
    lpszCachePath  AS ASCIIZ, _
    BYVAL dwSize   AS DWORD, _
    BYVAL dwFilter AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION FreeUrlCacheSpaceW LIB "WinINet.dll" _
    ALIAS "FreeUrlCacheSpaceW" ( _
    lpszCachePath  AS WSTRINGZ, _
    BYVAL dwSize   AS DWORD, _
    BYVAL dwFilter AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION FreeUrlCacheSpace LIB "WinINet.dll" _
    ALIAS "FreeUrlCacheSpaceW" ( _
    lpszCachePath  AS WSTRINGZ, _
    BYVAL dwSize   AS DWORD, _
    BYVAL dwFilter AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION FreeUrlCacheSpace LIB "WinINet.dll" _
    ALIAS "FreeUrlCacheSpaceA" ( _
    lpszCachePath  AS ASCIIZ, _
    BYVAL dwSize   AS DWORD, _
    BYVAL dwFilter AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF ' NOT %UNICODE

'
' config APIs.
'

%CACHE_CONFIG_FORCE_CLEANUP_FC         = &H00000020
%CACHE_CONFIG_DISK_CACHE_PATHS_FC      = &H00000040
%CACHE_CONFIG_SYNC_MODE_FC             = &H00000080
%CACHE_CONFIG_CONTENT_PATHS_FC         = &H00000100
%CACHE_CONFIG_COOKIES_PATHS_FC         = &H00000200
%CACHE_CONFIG_HISTORY_PATHS_FC         = &H00000400
%CACHE_CONFIG_QUOTA_FC                 = &H00000800
%CACHE_CONFIG_USER_MODE_FC             = &H00001000
%CACHE_CONFIG_CONTENT_USAGE_FC         = &H00002000
%CACHE_CONFIG_STICKY_CONTENT_USAGE_FC  = &H00004000

DECLARE FUNCTION GetUrlCacheConfigInfoA LIB "WinINet.dll" _
    ALIAS "GetUrlCacheConfigInfoA" ( _
    lpCacheConfigInfo    AS INTERNET_CACHE_CONFIG_INFOA, _
    lpcbCacheConfigInfo  AS DWORD, _
    BYVAL dwFieldControl AS DWORD _
    ) AS LONG  ' BOOL
DECLARE FUNCTION GetUrlCacheConfigInfoW LIB "WinINet.dll" _
    ALIAS "GetUrlCacheConfigInfoW" ( _
    lpCacheConfigInfo    AS INTERNET_CACHE_CONFIG_INFOW, _
    lpcbCacheConfigInfo  AS DWORD, _
    BYVAL dwFieldControl AS DWORD _
    ) AS LONG  ' BOOL
#IF %DEF(%UNICODE)
DECLARE FUNCTION GetUrlCacheConfigInfo LIB "WinINet.dll" _
    ALIAS "GetUrlCacheConfigInfoW" ( _
    lpCacheConfigInfo    AS INTERNET_CACHE_CONFIG_INFOW, _
    lpcbCacheConfigInfo  AS DWORD, _
    BYVAL dwFieldControl AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION GetUrlCacheConfigInfo LIB "WinINet.dll" _
    ALIAS "GetUrlCacheConfigInfoA" ( _
    lpCacheConfigInfo    AS INTERNET_CACHE_CONFIG_INFOA, _
    lpcbCacheConfigInfo  AS DWORD, _
    BYVAL dwFieldControl AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetUrlCacheConfigInfoA LIB "WinINet.dll" _
    ALIAS "SetUrlCacheConfigInfoA" ( _
    lpCacheConfigInfo AS INTERNET_CACHE_CONFIG_INFOA, _
    BYVAL dwFieldControl AS DWORD _
    ) AS LONG  ' BOOL
DECLARE FUNCTION SetUrlCacheConfigInfoW LIB "WinINet.dll" _
    ALIAS "SetUrlCacheConfigInfoW" ( _
    lpCacheConfigInfo AS INTERNET_CACHE_CONFIG_INFOW, _
    BYVAL dwFieldControl AS DWORD _
    ) AS LONG  ' BOOL
#IF %DEF(%UNICODE)
DECLARE FUNCTION SetUrlCacheConfigInfo LIB "WinINet.dll" _
    ALIAS "SetUrlCacheConfigInfoW" ( _
    lpCacheConfigInfo AS INTERNET_CACHE_CONFIG_INFOW, _
    BYVAL dwFieldControl AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetUrlCacheConfigInfo LIB "WinINet.dll" _
    ALIAS "SetUrlCacheConfigInfoA" ( _
    lpCacheConfigInfo AS INTERNET_CACHE_CONFIG_INFOA, _
    BYVAL dwFieldControl AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RunOnceUrlCache LIB "WinINet.dll" _
    ALIAS "RunOnceUrlCache" ( _
    BYVAL hwnd     AS DWORD, _  ' HWND
    BYVAL hinst    AS DWORD, _  ' HINSTANCE
    lpszCmd        AS ASCIIZ, _
    BYVAL nCmdShow AS LONG _
    ) AS DWORD

DECLARE FUNCTION DeleteIE3Cache LIB "WinINet.dll" _
    ALIAS "DeleteIE3Cache" ( _
    BYVAL hwnd     AS DWORD, _  ' HWND
    BYVAL hinst    AS DWORD, _  ' HINSTANCE
    lpszCmd        AS ASCIIZ, _
    BYVAL nCmdShow AS LONG _
    ) AS DWORD

DECLARE FUNCTION UpdateUrlCacheContentPath LIB "WinINet.dll" _
    ALIAS "UpdateUrlCacheContentPath" ( _
    szNewPath AS ASCIIZ _
    ) AS LONG  ' BOOL

' Cache header data defines.

%CACHE_HEADER_DATA_CURRENT_SETTINGS_VERSION = 0
%CACHE_HEADER_DATA_CONLIST_CHANGE_COUNT     = 1
%CACHE_HEADER_DATA_COOKIE_CHANGE_COUNT      = 2


%CACHE_HEADER_DATA_NOTIFICATION_HWND       = 3
%CACHE_HEADER_DATA_NOTIFICATION_MESG       = 4
%CACHE_HEADER_DATA_ROOTGROUP_OFFSET        = 5
%CACHE_HEADER_DATA_GID_LOW                 = 6
%CACHE_HEADER_DATA_GID_HIGH                = 7

%CACHE_HEADER_DATA_CACHE_RESERVED_8        = 8
%CACHE_HEADER_DATA_CACHE_RESERVED_9        = 9
%CACHE_HEADER_DATA_CACHE_RESERVED_10       = 10
%CACHE_HEADER_DATA_CACHE_RESERVED_11       = 11
%CACHE_HEADER_DATA_CACHE_RESERVED_12       = 12
%CACHE_HEADER_DATA_CACHE_RESERVED_13       = 13


%CACHE_HEADER_DATA_SSL_STATE_COUNT         = 14
' legacy alias for ssl state count
%CACHE_HEADER_DATA_DOWNLOAD_PARTIAL = %CACHE_HEADER_DATA_SSL_STATE_COUNT


%CACHE_HEADER_DATA_CACHE_RESERVED_15       = 15
%CACHE_HEADER_DATA_CACHE_RESERVED_16       = 16
%CACHE_HEADER_DATA_CACHE_RESERVED_17       = 17
%CACHE_HEADER_DATA_CACHE_RESERVED_18       = 18
%CACHE_HEADER_DATA_CACHE_RESERVED_19       = 19
%CACHE_HEADER_DATA_CACHE_RESERVED_20       = 20

%CACHE_HEADER_DATA_NOTIFICATION_FILTER     = 21
%CACHE_HEADER_DATA_ROOT_LEAK_OFFSET        = 22

%CACHE_HEADER_DATA_CACHE_RESERVED_23       = 23
%CACHE_HEADER_DATA_CACHE_RESERVED_24       = 24
%CACHE_HEADER_DATA_CACHE_RESERVED_25       = 25
%CACHE_HEADER_DATA_CACHE_RESERVED_26       = 26

%CACHE_HEADER_DATA_ROOT_GROUPLIST_OFFSET   = 27 ' offset to group list

%CACHE_HEADER_DATA_CACHE_RESERVED_28       = 28
%CACHE_HEADER_DATA_CACHE_RESERVED_29       = 29
%CACHE_HEADER_DATA_CACHE_RESERVED_30       = 30
%CACHE_HEADER_DATA_CACHE_RESERVED_31       = 31

%CACHE_HEADER_DATA_LAST                    = 31

' options for cache notification filter
%CACHE_NOTIFY_ADD_URL                      = &H00000001
%CACHE_NOTIFY_DELETE_URL                   = &H00000002
%CACHE_NOTIFY_UPDATE_URL                   = &H00000004
%CACHE_NOTIFY_DELETE_ALL                   = &H00000008
%CACHE_NOTIFY_URL_SET_STICKY               = &H00000010
%CACHE_NOTIFY_URL_UNSET_STICKY             = &H00000020
%CACHE_NOTIFY_SET_ONLINE                   = &H00000100
%CACHE_NOTIFY_SET_OFFLINE                  = &H00000200

%CACHE_NOTIFY_FILTER_CHANGED               = &H10000000

DECLARE FUNCTION RegisterUrlCacheNotification LIB "WinINet.dll" _
    ALIAS "RegisterUrlCacheNotification" ( _
    BYVAL hWnd        AS DWORD, _  ' HWND
    BYVAL uMsg        AS DWORD, _
    BYVAL gid         AS QUAD, _   ' GROUPID
    BYVAL dwOpsFilter AS DWORD, _
    BYVAL dwReserved  AS DWORD _
    ) AS LONG  ' BOOL


DECLARE FUNCTION GetUrlCacheHeaderData LIB "WinINet.dll" _
    ALIAS "GetUrlCacheHeaderData" ( _
    BYVAL nIdx AS DWORD, _
    lpdwData   AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetUrlCacheHeaderData LIB "WinINet.dll" _
    ALIAS "SetUrlCacheHeaderData" ( _
    BYVAL nIdx   AS DWORD, _
    BYVAL dwData AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION IncrementUrlCacheHeaderData LIB "WinINet.dll" _
    ALIAS "IncrementUrlCacheHeaderData" ( _
    BYVAL nIdx AS DWORD, _
    lpdwData   AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION LoadUrlCacheContent LIB "WinINet.dll" _
    ALIAS "LoadUrlCacheContent" () AS LONG  ' BOOL

' [these functions are not documented and do not appear to be exported]
'DECLARE FUNCTION GetUrlCacheContainerInfoA LIB "WinINet.dll" _
'    ALIAS "GetUrlCacheContainerInfoA" ( _
'    lpszUrlName                 AS ASCIIZ, _
'    lpContainerInfo             AS INTERNET_CACHE_CONTAINER_INFOA, _
'    lpdwContainerInfoBufferSize AS DWORD, _
'    BYVAL dwOptions             AS DWORD _
'    ) AS LONG  ' BOOL
'
'DECLARE FUNCTION GetUrlCacheContainerInfoW LIB "WinINet.dll" _
'    ALIAS "GetUrlCacheContainerInfoW" ( _
'    lpszUrlName                 AS WSTRINGZ, _
'    lpContainerInfo             AS INTERNET_CACHE_CONTAINER_INFOW, _
'    lpdwContainerInfoBufferSize AS DWORD, _
'    BYVAL dwOptions             AS DWORD _
'    ) AS LONG  ' BOOL
'
'#IF %DEF(%UNICODE)
'MACRO GetUrlCacheContainerInfo=GetUrlCacheContainerInfoW
'#ELSE
'MACRO GetUrlCacheContainerInfo=GetUrlCacheContainerInfoA
'#ENDIF ' NOT %UNICODE


' [these functions are not documented and do not appear to be exported]
'DECLARE FUNCTION InternetGetDialEngineW LIB "WinINet.dll" _
'    ALIAS "InternetGetDialEngineW" ( _
'    pwzConnectoid AS WSTRINGZ, _
'    pdes          AS ANY, _  ' IDialEventSink PTR
'    ppde          AS ANY _   ' IDialEngine PTR PTR
'    ) AS LONG

' [these functions are not documented and do not appear to be exported]
'DECLARE FUNCTION InternetGetDialBrandingW LIB "WinINet.dll" _
'    ALIAS "InternetGetDialBrandingW" ( _
'    pwzConnectoid AS WSTRINGZ, _
'    ppdb          AS ANY _   ' IDialBranding PTR PTR
'    ) AS LONG


' [these functions are not documented and do not appear to be exported]
'DECLARE FUNCTION ReadGuidsForConnectedNetworks LIB "WinINet.dll" _
'    ALIAS "ReadGuidsForConnectedNetworks" ( _
'    pcNetworks          AS DWORD, _
'    pppwszNetworkGuids  AS ANY, _  ' PWSTR PTR PTR
'    pppbstrNetworkNames AS ANY, _  ' BSTR  PTR PTR
'    pppwszGWMacs        AS ANY, _  ' PWSTR PTR PTR
'    pcGatewayMacs       AS DWORD, _
'    pdwFlags            AS DWORD _
'    ) AS LONG  ' BOOL

'
' INTERNET_AUTOPROXY_INIT_FLAGS - Flags for InternetInitializeAutoProxyDll
'
%INTERNET_AUTOPROXY_INIT_DEFAULT      = &H1
%INTERNET_AUTOPROXY_INIT_DOWNLOADSYNC = &H2
%INTERNET_AUTOPROXY_INIT_QUERYSTATE   = &H4
%INTERNET_AUTOPROXY_INIT_ONLYQUERY    = &H8

%INTERNET_AUTOPROXY_INIT_MASK = (%INTERNET_AUTOPROXY_INIT_DEFAULT _
                              OR %INTERNET_AUTOPROXY_INIT_DOWNLOADSYNC _
                              OR %INTERNET_AUTOPROXY_INIT_QUERYSTATE _
                              OR %INTERNET_AUTOPROXY_INIT_ONLYQUERY)


DECLARE FUNCTION InternetInitializeAutoProxyDll LIB "WinINet.dll" _
    ALIAS "InternetInitializeAutoProxyDll" ( _
    BYVAL dwReserved AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION DetectAutoProxyUrl LIB "WinINet.dll" _
    ALIAS "DetectAutoProxyUrl" ( _
    lpszAutoProxyUrl           AS ASCIIZ, _
    BYVAL dwAutoProxyUrlLength AS DWORD, _
    BYVAL dwDetectFlags        AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION CreateMD5SSOHash LIB "WinINet.dll" _
    ALIAS "CreateMD5SSOHash" ( _
    pszChallengeInfo AS WSTRINGZ, _
    pwszRealm        AS WSTRINGZ, _
    pwszTarget       AS WSTRINGZ, _
    BYVAL pbHexHash  AS BYTE PTR _
    ) AS LONG  ' BOOL

' States for InternetSetDialState
%INTERNET_DIALSTATE_DISCONNECTED = 1

' Registry entries used by the dialing code
' All of these entries are in:
' HKCU\software\microsoft\windows\current version\internet settings

$REGSTR_DIAL_AUTOCONNECT     = "AutoConnect"

' Registry entries for legacy cookies
$REGSTR_LEASH_LEGACY_COOKIES = "LeashLegacyCookies"



' Used by security manager.

DECLARE FUNCTION IsHostInProxyBypassList LIB "WinINet.dll" _
    ALIAS "IsHostInProxyBypassList" ( _
    BYVAL tScheme AS INTERNET_SCHEME_enum, _
    lpszHost      AS ASCIIZ, _
    BYVAL cchHost AS DWORD _
    ) AS LONG  ' BOOL

' Used by Shell to determine if anyone has loaded wininet yet
' Shell code calls OpenMutex with this name and if no mutex is
' obtained, we know that no copy of wininet has been loaded yet
#IF %WIN32_WINNT >= %WIN32_WINNT_WINXP
$LOCAL_NAMESPACE_PREFIX = "Local\"
$WININET_STARTUP_MUTEX = "Local\WininetStartupMutex"
#ELSE
$LOCAL_NAMESPACE_PREFIX = ""
$WININET_STARTUP_MUTEX "WininetStartupMutex"
#ENDIF


' [these functions are not documented and do not appear to be exported]
'' Returns TRUE if any RAS connectoids exist and FALSE otherwise
'DECLARE FUNCTION DoConnectoidsExist LIB "WinINet.dll" _
'    ALIAS "DoConnectoidsExist" ( _
'    ) AS LONG  ' BOOL
'
' [these functions are not documented and do not appear to be exported]
'DECLARE FUNCTION GetDiskInfoA LIB "WinINet.dll" _
'    ALIAS "GetDiskInfoA" ( _
'    pszPath        AS ASCIIZ, _
'    pdwClusterSize AS DWORD, _
'    pdlAvail       AS QUAD, _  ' DWORDLONG
'    pdlTotal       AS QUAD  _  ' DWORDLONG
'    ) AS LONG  ' BOOL

'DECLARE FUNCTION CACHE_OPERATOR ( _
'    pcei          AS INTERNET_CACHE_ENTRY_INFO, _
'    pcbcei        AS DWORD, _
'    BYVAL pOpData AS DWORD _  ' PVOID
'    ) AS LONG  ' BOOL

' [these functions are not documented and do not appear to be exported]
'DECLARE FUNCTION PerformOperationOverUrlCacheA LIB "WinINet.dll" _
'    ALIAS "PerformOperationOverUrlCacheA" ( _
'    pszUrlSearchPattern AS ASCIIZ, _
'    BYVAL dwFlags       AS DWORD, _
'    BYVAL dwFilter      AS DWORD, _
'    BYVAL GroupId       AS QUAD, _   ' GROUPID
'    pReserved1          AS ANY, _    ' PVOID
'    pdwReserved2        AS DWORD, _
'    pReserved3          AS ANY, _    ' PVOID
'    BYVAL op            AS DWORD, _  ' CACHE_OPERATOR, _
'    pOperatorData       AS ANY _     ' PVOID
'    ) AS LONG  ' BOOL

' [these functions are not documented and do not appear to be exported]
'DECLARE FUNCTION IsProfilesEnabled LIB "WinINet.dll" _
'    ALIAS "IsProfilesEnabled" ( _
'    ) AS LONG  ' BOOL

DECLARE FUNCTION GetFileExtensionFromUrl LIB "WinINet.dll" _
    ALIAS "_GetFileExtensionFromUrl" ( _
    lpszUrl       AS ASCIIZ, _
    BYVAL dwFlags AS DWORD, _
    lpszExt       AS ASCIIZ, _
    pcchExt       AS DWORD _
    ) AS DWORD

' [these functions are not documented and do not appear to be exported]
'DECLARE FUNCTION InternalInternetGetCookie LIB "WinINet.dll" _
'    ALIAS "InternalInternetGetCookie" ( _
'    lpszUrl        AS ASCIIZ, _
'    lpszCookieData AS ASCIIZ, _
'    lpdwDataSize   AS DWORD _
'    ) AS DWORD


' [these functions are not documented and do not appear to be exported]
''  in cookimp.cxx and cookexp.cxx
'DECLARE FUNCTION ImportCookieFileA LIB "WinINet.dll" _
'    ALIAS "ImportCookieFileA" ( _
'    szFilename AS ASCIIZ _
'    ) AS LONG  ' BOOL

' [these functions are not documented and do not appear to be exported]
''  in cookimp.cxx and cookexp.cxx
'DECLARE FUNCTION ImportCookieFileW LIB "WinINet.dll" _
'    ALIAS "ImportCookieFileW" ( _
'    szFilename AS WSTRINGZ _
'    ) AS LONG  ' BOOL

'#IF %DEF(%UNICODE)
'MACRO ImportCookieFile=ImportCookieFileW
'#ELSE
'MACRO ImportCookieFile=ImportCookieFileA
'#ENDIF ' NOT %UNICODE

' [these functions are not documented and do not appear to be exported]
'DECLARE FUNCTION ExportCookieFileA LIB "WinINet.dll" _
'    ALIAS "ExportCookieFileA" ( _
'    szFilename    AS ASCIIZ, _
'    BYVAL fAppend AS LONG _  ' BOOL
'    ) AS LONG  ' BOOL

' [these functions are not documented and do not appear to be exported]
'DECLARE FUNCTION ExportCookieFileW LIB "WinINet.dll" _
'    ALIAS "ExportCookieFileW" ( _
'    szFilename    AS WSTRINGZ, _
'    BYVAL fAppend AS LONG _  ' BOOL
'    ) AS LONG  ' BOOL

'#IF %DEF(%UNICODE)
'MACRO ExportCookieFile=ExportCookieFileW
'#ELSE
'MACRO ExportCookieFile=ExportCookieFileA
'#ENDIF ' NOT %UNICODE

' [these functions are not documented and do not appear to be exported]
'' in "wininet\http\cookie.cxx"
'DECLARE FUNCTION IsDomainLegalCookieDomainA LIB "WinINet.dll" _
'    ALIAS "IsDomainLegalCookieDomainA" ( _
'    pchDomain     AS ASCIIZ, _
'    pchFullDomain AS ASCIIZ _
'    ) AS LONG  ' BOOL

' [these functions are not documented and do not appear to be exported]
'' in "wininet\http\cookie.cxx"
'DECLARE FUNCTION IsDomainLegalCookieDomainW LIB "WinINet.dll" _
'    ALIAS "IsDomainLegalCookieDomainW" ( _
'    pchDomain     AS WSTRINGZ, _
'    pchFullDomain AS WSTRINGZ _
'    ) AS LONG  ' BOOL

'#IF %DEF(%UNICODE)
'MACRO IsDomainLegalCookieDomain=IsDomainLegalCookieDomainW
'#ELSE
'MACRO IsDomainLegalCookieDomain=IsDomainLegalCookieDomainA
'#ENDIF ' NOT %UNICODE


DECLARE FUNCTION InternetEnumPerSiteCookieDecisionA LIB "WinINet.dll" _
    ALIAS "InternetEnumPerSiteCookieDecisionA" ( _
    pszSiteName    AS ASCIIZ, _
    pcSiteNameSize AS DWORD, _
    pdwDecision    AS DWORD, _
    BYVAL dwIndex  AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION InternetEnumPerSiteCookieDecisionW LIB "WinINet.dll" _
    ALIAS "InternetEnumPerSiteCookieDecisionW" ( _
    pszSiteName    AS WSTRINGZ, _
    pcSiteNameSize AS DWORD, _
    pdwDecision    AS DWORD, _
    BYVAL dwIndex  AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetEnumPerSiteCookieDecision LIB "WinINet.dll" _
    ALIAS "InternetEnumPerSiteCookieDecisionW" ( _
    pszSiteName    AS WSTRINGZ, _
    pcSiteNameSize AS DWORD, _
    pdwDecision    AS DWORD, _
    BYVAL dwIndex  AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION InternetEnumPerSiteCookieDecision LIB "WinINet.dll" _
    ALIAS "InternetEnumPerSiteCookieDecisionA" ( _
    pszSiteName    AS ASCIIZ, _
    pcSiteNameSize AS DWORD, _
    pdwDecision    AS DWORD, _
    BYVAL dwIndex  AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF ' NOT %UNICODE

%INTERNET_SUPPRESS_COOKIE_PERSIST          = &H03
%INTERNET_SUPPRESS_COOKIE_PERSIST_RESET    = &H04
'
' Privacy settings values and APIs
'

%PRIVACY_TEMPLATE_NO_COOKIES   = 0
%PRIVACY_TEMPLATE_HIGH         = 1
%PRIVACY_TEMPLATE_MEDIUM_HIGH  = 2
%PRIVACY_TEMPLATE_MEDIUM       = 3
%PRIVACY_TEMPLATE_MEDIUM_LOW   = 4
%PRIVACY_TEMPLATE_LOW          = 5
%PRIVACY_TEMPLATE_CUSTOM       = 100
%PRIVACY_TEMPLATE_ADVANCED     = 101

%PRIVACY_TEMPLATE_MAX          = %PRIVACY_TEMPLATE_LOW

%PRIVACY_TYPE_FIRST_PARTY      = 0
%PRIVACY_TYPE_THIRD_PARTY      = 1

DECLARE FUNCTION PrivacySetZonePreferenceW LIB "WinINet.dll" _
    ALIAS "PrivacySetZonePreferenceW" ( _
    BYVAL dwZone     AS DWORD, _
    BYVAL dwType     AS DWORD, _
    BYVAL dwTemplate AS DWORD, _
    pszPreference    AS WSTRINGZ _
    ) AS DWORD

DECLARE FUNCTION PrivacyGetZonePreferenceW LIB "WinINet.dll" _
    ALIAS "PrivacyGetZonePreferenceW" ( _
    BYVAL dwZone    AS DWORD, _
    BYVAL dwType    AS DWORD, _
    pdwTemplate     AS DWORD, _
    pszBuffer       AS WSTRINGZ, _
    pdwBufferLength AS DWORD _
    ) AS DWORD

%P3PGLOBAL_H = 1

'typedef char  P3PCHAR;
'typedef char *P3PURL;
'typedef char *P3PVERB;
'typedef const char *P3PCURL;
'typedef BSTR P3PCXSL;
'typedef void *P3PHANDLE;

%URL_LIMIT = %INTERNET_MAX_URL_LENGTH

TYPE P3PResource
    pszLocation     AS ASCIIZ PTR  ' P3PCURL
    pszVerb         AS ASCIIZ PTR  ' P3PVERB

    pszP3PHeaderRef AS ASCIIZ PTR  ' P3PCURL
    pszLinkTagRef   AS ASCIIZ PTR  ' P3PCURL

    pContainer      AS P3PResource PTR
END TYPE

TYPE P3PSignal

    ' Window handle for PostMessage and corresponding msg value
    hwnd     AS DWORD  ' HWND
    message  AS DWORD

    ' Event handle to signal
    hEvent   AS DWORD  ' HANDLE

    ' Application-defined context
    pContext AS DWORD  ' void PTR

    ' OUT: request handle
    hRequest AS DWORD  ' P3PHANDLE
END TYPE

MACRO P3PStatus_enum=LONG
ENUM P3PStatus SINGULAR
    P3P_Done
    P3P_Success    = 0

    P3P_NoPolicy   = &H2
    P3P_InProgress
    P3P_Failed
    P3P_NotFound
    P3P_FormatErr
    P3P_Cancelled
    P3P_NotStarted
    P3P_XMLError
    P3P_Expired

    P3P_Error      = &HFF
END ENUM

' [these functions are not documented and do not appear to be exported]
'DECLARE FUNCTION MapResourceToPolicy LIB "WinINet.dll" _
'    ALIAS "MapResourceToPolicy" ( _
'    pResource    AS P3PResource, _
'    pszPolicy    AS ASCIIZ, _  ' P3PURL
'    BYVAL dwSize AS DWORD, _
'    pSignal      AS P3PSignal _
'    ) AS LONG

' [these functions are not documented and do not appear to be exported]
'DECLARE FUNCTION GetP3PPolicy LIB "WinINet.dll" _
'    ALIAS "GetP3PPolicy" ( _
'    pszPolicyURL       AS ASCIIZ, _  ' P3PCURL
'    BYVAL hDestination AS DWORD, _   '  HANDLE
'    pszXSLtransform    AS STRING, _  ' P3PCXSL
'    pSignal            AS P3PSignal _
'    ) AS LONG

' [these functions are not documented and do not appear to be exported]
'DECLARE FUNCTION FreeP3PObject LIB "WinINet.dll" _
'    ALIAS "FreeP3PObject" ( _
'    BYVAL hObject AS DWORD _  ' P3PHANDLE
'    ) AS LONG

' [these functions are not documented and do not appear to be exported]
'DECLARE FUNCTION GetP3PRequestStatus LIB "WinINet.dll" _
'    ALIAS "GetP3PRequestStatus" ( _
'    BYVAL hObject AS DWORD _  ' P3PHANDLE
'    ) AS LONG


%INTERNET_ERROR_MASK_INSERT_CDROM                      = &H1
%INTERNET_ERROR_MASK_COMBINED_SEC_CERT                 = &H2
%INTERNET_ERROR_MASK_NEED_MSN_SSPI_PKG                 = &H4
%INTERNET_ERROR_MASK_LOGIN_FAILURE_DISPLAY_ENTITY_BODY = &H8

%INTERNET_OPTIONS_MASK    = NOT %INTERNET_FLAGS_MASK

'
' common per-API flags (new APIs)
'

%WININET_API_FLAG_ASYNC       = &H00000001  ' force async operation
%WININET_API_FLAG_SYNC        = &H00000004  ' force sync operation
%WININET_API_FLAG_USE_CONTEXT = &H00000008  ' use value supplied in dwContext (even if 0)

'
' INTERNET_NO_CALLBACK - if this value is presented as the dwContext parameter
' then no call-backs will be made for that API
'

%INTERNET_NO_CALLBACK            = 0

'
' structures/types
'

'
' INTERNET_SCHEME - enumerated URL scheme type
'

MACRO INTERNET_SCHEME_enum=LONG
ENUM INTERNET_SCHEME SINGULAR
    IS_INTERNET_SCHEME_PARTIAL = -2
    IS_INTERNET_SCHEME_UNKNOWN
    IS_INTERNET_SCHEME_DEFAULT
    IS_INTERNET_SCHEME_FTP
    IS_INTERNET_SCHEME_GOPHER
    IS_INTERNET_SCHEME_HTTP
    IS_INTERNET_SCHEME_HTTPS
    IS_INTERNET_SCHEME_FILE
    IS_INTERNET_SCHEME_NEWS
    IS_INTERNET_SCHEME_MAILTO
    IS_INTERNET_SCHEME_SOCKS
    IS_INTERNET_SCHEME_JAVASCRIPT
    IS_INTERNET_SCHEME_VBSCRIPT
    IS_INTERNET_SCHEME_RES
    IS_INTERNET_SCHEME_FIRST      = %IS_INTERNET_SCHEME_FTP
    IS_INTERNET_SCHEME_LAST       = %IS_INTERNET_SCHEME_RES
END ENUM

' INTERNET_ASYNC_RESULT - this structure is returned to the application via
' the callback with INTERNET_STATUS_REQUEST_COMPLETE. It is not sufficient to
' just return the result of the async operation. If the API failed then the
' app cannot call GetLastError() because the thread context will be incorrect.
' Both the value returned by the async API and any resultant error code are
' made available. The app need not check dwError if dwResult indicates that
' the API succeeded (in this case dwError will be ERROR_SUCCESS)

TYPE INTERNET_ASYNC_RESULT
    dwResult AS DWORD   ' the HINTERNET, DWORD, or BOOL return code from an async API
    dwError  AS DWORD   ' the error code if the API failed
END TYPE


'
' INTERNET_DIAGNOSTIC_SOCKET_INFO - info about the socket in use
'

TYPE INTERNET_DIAGNOSTIC_SOCKET_INFO
    Socket     AS DWORD
    SourcePort AS DWORD
    DestPort   AS DWORD
    Flags      AS DWORD
END TYPE

'
' INTERNET_DIAGNOSTIC_SOCKET_INFO.Flags definitions
'

%IDSI_FLAG_KEEP_ALIVE  = &H00000001  ' set if from keep-alive pool
%IDSI_FLAG_SECURE      = &H00000002  ' set if secure connection
%IDSI_FLAG_PROXY       = &H00000004  ' set if using proxy
%IDSI_FLAG_TUNNEL      = &H00000008  ' set if tunnelling through proxy


' INTERNET_PROXY_INFO - structure supplied with INTERNET_OPTION_PROXY to get/
' set proxy information on a InternetOpen() handle

TYPE INTERNET_PROXY_INFOA
    dwAccessType    AS DWORD      ' dwAccessType - INTERNET_OPEN_TYPE_DIRECT,
                                  '                INTERNET_OPEN_TYPE_PROXY,
                                  '             or INTERNET_OPEN_TYPE_PRECONFIG
                                  ' (set only)
    lpszProxy       AS ASCIIZ PTR ' lpszProxy - proxy server list
    lpszProxyBypass AS ASCIIZ PTR ' lpszProxyBypass - proxy bypass list
END TYPE

TYPE INTERNET_PROXY_INFOW
    dwAccessType    AS DWORD      ' dwAccessType - INTERNET_OPEN_TYPE_DIRECT,
                                  '                INTERNET_OPEN_TYPE_PROXY,
                                  '             or INTERNET_OPEN_TYPE_PRECONFIG
                                  ' (set only)
    lpszProxy       AS WSTRINGZ PTR ' lpszProxy - proxy server list
    lpszProxyBypass AS WSTRINGZ PTR ' lpszProxyBypass - proxy bypass list
END TYPE

#IF %DEF(%UNICODE)
TYPE INTERNET_PROXY_INFO
    INTERNET_PROXY_INFOW
END TYPE
#ELSE
TYPE INTERNET_PROXY_INFO
    INTERNET_PROXY_INFOA
END TYPE
#ENDIF

'
' INTERNET_PER_CONN_OPTION_LIST - set per-connection options such as proxy
' and autoconfig info
'
' Set and queried using Internet[Set|Query]Option with
' INTERNET_OPTION_PER_CONNECTION_OPTION
'

UNION INTERNET_PER_CONN_OPTIONA_union
    dwValue  AS DWORD        ' dword value for the option
    pszValue AS ASCIIZ PTR   ' pointer to string value for the option
    ftValue  AS FILETIME     ' file-time value for the option
END UNION

TYPE INTERNET_PER_CONN_OPTIONA
    dwOption AS DWORD        ' option to be queried or set
    Value    AS INTERNET_PER_CONN_OPTIONA_union
END TYPE

UNION INTERNET_PER_CONN_OPTIONW_union
    dwValue  AS DWORD        ' dword value for the option
    pszValue AS WSTRINGZ PTR ' pointer to string value for the option
    ftValue  AS FILETIME     ' file-time value for the option
END UNION

TYPE INTERNET_PER_CONN_OPTIONW
    dwOption AS DWORD        ' option to be queried or set
    Value    AS INTERNET_PER_CONN_OPTIONW_union
END TYPE

#IF %DEF(%UNICODE)
TYPE INTERNET_PER_CONN_OPTION
    INTERNET_PER_CONN_OPTIONW
END TYPE
#ELSE
TYPE INTERNET_PER_CONN_OPTION
    INTERNET_PER_CONN_OPTIONA
END TYPE
#ENDIF

TYPE INTERNET_PER_CONN_OPTION_LISTA
    dwSize        AS DWORD      ' size of the INTERNET_PER_CONN_OPTION_LIST struct
    pszConnection AS ASCIIZ PTR ' connection name to set/query options
    dwOptionCount AS DWORD      ' number of options to set/query
    dwOptionError AS DWORD      ' on error, which option failed
    pOptions AS INTERNET_PER_CONN_OPTIONA PTR ' array of options to set/query
END TYPE

TYPE INTERNET_PER_CONN_OPTION_LISTW
    dwSize        AS DWORD      ' size of the INTERNET_PER_CONN_OPTION_LIST struct
    pszConnection AS WSTRINGZ PTR ' connection name to set/query options
    dwOptionCount AS DWORD      ' number of options to set/query
    dwOptionError AS DWORD      ' on error, which option failed
    pOptions AS INTERNET_PER_CONN_OPTIONW PTR ' array of options to set/query
END TYPE

#IF %DEF(%UNICODE)
TYPE INTERNET_PER_CONN_OPTION_LIST
     INTERNET_PER_CONN_OPTION_LISTW
END TYPE
#ELSE
TYPE INTERNET_PER_CONN_OPTION_LIST
     INTERNET_PER_CONN_OPTION_LISTA
END TYPE
#ENDIF

'
' Options used in INTERNET_PER_CONN_OPTION struct
'
%INTERNET_PER_CONN_FLAGS                        = 1
%INTERNET_PER_CONN_PROXY_SERVER                 = 2
%INTERNET_PER_CONN_PROXY_BYPASS                 = 3
%INTERNET_PER_CONN_AUTOCONFIG_URL               = 4
%INTERNET_PER_CONN_AUTODISCOVERY_FLAGS          = 5
%INTERNET_PER_CONN_AUTOCONFIG_SECONDARY_URL     = 6
%INTERNET_PER_CONN_AUTOCONFIG_RELOAD_DELAY_MINS = 7
%INTERNET_PER_CONN_AUTOCONFIG_LAST_DETECT_TIME  = 8
%INTERNET_PER_CONN_AUTOCONFIG_LAST_DETECT_URL   = 9
%INTERNET_PER_CONN_FLAGS_UI                     = 10

'
' PER_CONN_FLAGS
'
%PROXY_TYPE_DIRECT         = &H00000001   ' direct to net
%PROXY_TYPE_PROXY          = &H00000002   ' via named proxy
%PROXY_TYPE_AUTO_PROXY_URL = &H00000004   ' autoproxy URL
%PROXY_TYPE_AUTO_DETECT    = &H00000008   ' use autoproxy detection

'
' PER_CONN_AUTODISCOVERY_FLAGS
'
%AUTO_PROXY_FLAG_USER_SET                = &H00000001 ' user changed this setting
%AUTO_PROXY_FLAG_ALWAYS_DETECT           = &H00000002 ' force detection even when its not needed
%AUTO_PROXY_FLAG_DETECTION_RUN           = &H00000004 ' detection has been run
%AUTO_PROXY_FLAG_MIGRATED                = &H00000008 ' migration has just been done
%AUTO_PROXY_FLAG_DONT_CACHE_PROXY_RESULT = &H00000010 ' don't cache result of host=proxy name
%AUTO_PROXY_FLAG_CACHE_INIT_RUN          = &H00000020 ' don't initalize and run unless URL expired
%AUTO_PROXY_FLAG_DETECTION_SUSPECT       = &H00000040 ' if we're on a LAN & Modem, with only one IP, bad?!?

'
' INTERNET_VERSION_INFO - version information returned via
' InternetQueryOption(..., INTERNET_OPTION_VERSION, ...)
'

TYPE INTERNET_VERSION_INFO
    dwMajorVersion AS DWORD
    dwMinorVersion AS DWORD
END TYPE


'
' HTTP_VERSION_INFO - query or set global HTTP version (1.0 or 1.1)
'

TYPE HTTP_VERSION_INFO
    dwMajorVersion AS DWORD
    dwMinorVersion AS DWORD
END TYPE

'
' INTERNET_CONNECTED_INFO - information used to set the global connected state
'

TYPE INTERNET_CONNECTED_INFO
    '
    ' dwConnectedState - new connected/disconnected state.
    ' See INTERNET_STATE_CONNECTED, etc.
    '
    dwConnectedState AS DWORD
    '
    ' dwFlags - flags controlling connected->disconnected (or disconnected->
    ' connected) transition. See below
    '
    dwFlags AS DWORD
END TYPE

'
' flags for INTERNET_CONNECTED_INFO dwFlags
'

'
' ISO_FORCE_DISCONNECTED - if set when putting Wininet into disconnected mode,
' all outstanding requests will be aborted with a cancelled error
'

%ISO_FORCE_DISCONNECTED = &H00000001

'
' URL_COMPONENTS - the constituent parts of an URL. Used in InternetCrackUrl()
' and InternetCreateUrl()
'
' For InternetCrackUrl(), if a pointer field and its corresponding length field
' are both 0 then that component is not returned. If the pointer field is NULL
' but the length field is not zero, then both the pointer and length fields are
' returned if both pointer and corresponding length fields are non-zero then
' the pointer field points to a buffer where the component is copied. The
' component may be un-escaped, depending on dwFlags
'
' For InternetCreateUrl(), the pointer fields should be NULL if the component
' is not required. If the corresponding length field is zero then the pointer
' field is the address of a zero-terminated string. If the length field is not
' zero then it is the string length of the corresponding pointer field
'

TYPE URL_COMPONENTSA DWORD FILL
    dwStructSize      AS DWORD       ' size of this structure. Used in version check
    lpszScheme        AS ASCIIZ PTR  ' pointer to scheme name
    dwSchemeLength    AS DWORD       ' length of scheme name
    nScheme           AS INTERNET_SCHEME_enum ' enumerated scheme type (if known)
    lpszHostName      AS ASCIIZ PTR  ' pointer to host name
    dwHostNameLength  AS DWORD       ' length of host name
    nPort             AS WORD        ' converted port number
    lpszUserName      AS ASCIIZ PTR  ' pointer to user name
    dwUserNameLength  AS DWORD       ' length of user name
    lpszPassword      AS ASCIIZ PTR  ' pointer to password
    dwPasswordLength  AS DWORD       ' length of password
    lpszUrlPath       AS ASCIIZ PTR  ' pointer to URL-path
    dwUrlPathLength   AS DWORD       ' length of URL-path
    lpszExtraInfo     AS ASCIIZ PTR  ' pointer to extra information (e.g. ?foo or #foo)
    dwExtraInfoLength AS DWORD       ' length of extra information
END TYPE

TYPE URL_COMPONENTSW DWORD FILL
    dwStructSize      AS DWORD         ' size of this structure. Used in version check
    lpszScheme        AS WSTRINGZ PTR  ' pointer to scheme name
    dwSchemeLength    AS DWORD         ' length of scheme name
    nScheme           AS INTERNET_SCHEME_enum ' enumerated scheme type (if known)
    lpszHostName      AS WSTRINGZ PTR  ' pointer to host name
    dwHostNameLength  AS DWORD         ' length of host name
    nPort             AS WORD          ' converted port number
    lpszUserName      AS WSTRINGZ PTR  ' pointer to user name
    dwUserNameLength  AS DWORD         ' length of user name
    lpszPassword      AS WSTRINGZ PTR  ' pointer to password
    dwPasswordLength  AS DWORD         ' length of password
    lpszUrlPath       AS WSTRINGZ PTR  ' pointer to URL-path
    dwUrlPathLength   AS DWORD         ' length of URL-path
    lpszExtraInfo     AS WSTRINGZ PTR  ' pointer to extra information (e.g. ?foo or #foo)
    dwExtraInfoLength AS DWORD         ' length of extra information
END TYPE

#IF %DEF(%UNICODE)
TYPE URL_COMPONENTS
    URL_COMPONENTSW
END TYPE
#ELSE
TYPE URL_COMPONENTS
    URL_COMPONENTSA
END TYPE
#ENDIF

'
' INTERNET_CERTIFICATE_INFO lpBuffer - contains the certificate returned from
' the server
'

TYPE INTERNET_CERTIFICATE_INFOA
    '
    ' ftExpiry - date the certificate expires.
    '

    ftExpiry AS FILETIME

    '
    ' ftStart - date the certificate becomes valid.
    '

    ftStart AS FILETIME

    '
    ' lpszSubjectInfo - the name of organization, site, and server
    '   the cert. was issued for.
    '

    lpszSubjectInfo AS ASCIIZ PTR

    '
    ' lpszIssuerInfo - the name of orgainzation, site, and server
    '   the cert was issues by.
    '

    lpszIssuerInfo AS ASCIIZ PTR

    '
    ' lpszProtocolName - the name of the protocol used to provide the secure
    '   connection.
    '

    lpszProtocolName AS ASCIIZ PTR

    '
    ' lpszSignatureAlgName - the name of the algorithm used for signing
    '  the certificate.
    '

    lpszSignatureAlgName AS ASCIIZ PTR

    '
    ' lpszEncryptionAlgName - the name of the algorithm used for
    '  doing encryption over the secure channel (SSL/PCT) connection.
    '

    lpszEncryptionAlgName AS ASCIIZ PTR

    '
    ' dwKeySize - size of the key.
    '

    dwKeySize AS DWORD

END TYPE

TYPE INTERNET_CERTIFICATE_INFOW
    '
    ' ftExpiry - date the certificate expires.
    '

    ftExpiry AS FILETIME

    '
    ' ftStart - date the certificate becomes valid.
    '

    ftStart AS FILETIME

    '
    ' lpszSubjectInfo - the name of organization, site, and server
    '   the cert. was issued for.
    '

    lpszSubjectInfo AS WSTRINGZ PTR

    '
    ' lpszIssuerInfo - the name of orgainzation, site, and server
    '   the cert was issues by.
    '

    lpszIssuerInfo AS WSTRINGZ PTR

    '
    ' lpszProtocolName - the name of the protocol used to provide the secure
    '   connection.
    '

    lpszProtocolName AS WSTRINGZ PTR

    '
    ' lpszSignatureAlgName - the name of the algorithm used for signing
    '  the certificate.
    '

    lpszSignatureAlgName AS WSTRINGZ PTR

    '
    ' lpszEncryptionAlgName - the name of the algorithm used for
    '  doing encryption over the secure channel (SSL/PCT) connection.
    '

    lpszEncryptionAlgName AS WSTRINGZ PTR

    '
    ' dwKeySize - size of the key.
    '

    dwKeySize AS DWORD

END TYPE

#IF %DEF(%UNICODE)
TYPE INTERNET_CERTIFICATE_INFO
    INTERNET_CERTIFICATE_INFOW
END TYPE
#ELSE
TYPE INTERNET_CERTIFICATE_INFO
    INTERNET_CERTIFICATE_INFOA
END TYPE
#ENDIF

'
' prototypes
'

DECLARE FUNCTION InternetTimeFromSystemTimeA LIB "WinINet.dll" _
   ALIAS "InternetTimeFromSystemTimeA" _
   ( _
    pst AS SYSTEMTIME, _     ' input GMT time
    BYVAL dwRFC AS DWORD,_   ' RFC format
    lpszTime AS ASCIIZ, _    ' output string buffer
    BYVAL cbTime AS DWORD _  ' output buffer size
   ) _
   AS LONG

DECLARE FUNCTION InternetTimeFromSystemTimeW LIB "WinINet.dll" _
   ALIAS "InternetTimeFromSystemTimeW" _
   ( _
    pst AS SYSTEMTIME, _     ' input GMT time
    BYVAL dwRFC AS DWORD,_   ' RFC format
    lpszTime AS WSTRINGZ, _  ' output string buffer
    BYVAL cbTime AS DWORD _  ' output buffer size
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetTimeFromSystemTime LIB "WinINet.dll" _
   ALIAS "InternetTimeFromSystemTimeW" _
   ( _
    pst AS SYSTEMTIME, _     ' input GMT time
    BYVAL dwRFC AS DWORD,_   ' RFC format
    lpszTime AS WSTRINGZ, _  ' output string buffer
    BYVAL cbTime AS DWORD _  ' output buffer size
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION InternetTimeFromSystemTime LIB "WinINet.dll" _
   ALIAS "InternetTimeFromSystemTimeA" _
   ( _
    pst AS SYSTEMTIME, _     ' input GMT time
    BYVAL dwRFC AS DWORD,_   ' RFC format
    lpszTime AS ASCIIZ, _    ' output string buffer
    BYVAL cbTime AS DWORD _  ' output buffer size
   ) _
   AS LONG
#ENDIF

'
' constants for InternetTimeFromSystemTime
'

%INTERNET_RFC1123_FORMAT     = 0
%INTERNET_RFC1123_BUFSIZE   = 30

DECLARE FUNCTION InternetTimeToSystemTimeA LIB "WinINet.dll" _
   ALIAS "InternetTimeToSystemTimeA" _
   ( _
    lpszTime AS ASCIIZ, _    ' NULL terminated string
    pst AS SYSTEMTIME, _     ' output in GMT time
    BYVAL dwReserved AS DWORD _
   ) _
   AS LONG

DECLARE FUNCTION InternetTimeToSystemTimeW LIB "WinINet.dll" _
   ALIAS "InternetTimeToSystemTimeW" _
   ( _
    lpszTime AS WSTRINGZ, _  ' NULL terminated string
    pst AS SYSTEMTIME, _     ' output in GMT time
    BYVAL dwReserved AS DWORD _
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetTimeToSystemTime LIB "WinINet.dll" _
   ALIAS "InternetTimeToSystemTimeW" _
   ( _
    lpszTime AS WSTRINGZ, _  ' NULL terminated string
    pst AS SYSTEMTIME, _     ' output in GMT time
    BYVAL dwReserved AS DWORD _
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION InternetTimeToSystemTime LIB "WinINet.dll" _
   ALIAS "InternetTimeToSystemTimeA" _
   ( _
    lpszTime AS ASCIIZ, _    ' NULL terminated string
    pst AS SYSTEMTIME, _     ' output in GMT time
    BYVAL dwReserved AS DWORD _
   ) _
   AS LONG
#ENDIF

DECLARE FUNCTION InternetCrackUrlA LIB "WinINet.dll" _
    ALIAS "InternetCrackUrlA" _
   ( _
    lpszUrl           AS ASCIIZ, _         ' in
    BYVAL dwUrlLength AS DWORD, _          ' in
    BYVAL dwFlags     AS DWORD, _          ' in
    lpUrlComponents   AS URL_COMPONENTS _  ' in/out
   ) _
   AS LONG

DECLARE FUNCTION InternetCrackUrlW LIB "WinINet.dll" _
    ALIAS "InternetCrackUrlW" _
   ( _
    lpszUrl           AS WSTRINGZ, _       ' in
    BYVAL dwUrlLength AS DWORD, _          ' in
    BYVAL dwFlags     AS DWORD, _          ' in
    lpUrlComponents   AS URL_COMPONENTS _  ' in/out
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetCrackUrl LIB "WinINet.dll" _
    ALIAS "InternetCrackUrlW" _
   ( _
    lpszUrl           AS WSTRINGZ, _       ' in
    BYVAL dwUrlLength AS DWORD, _          ' in
    BYVAL dwFlags     AS DWORD, _          ' in
    lpUrlComponents   AS URL_COMPONENTS _  ' in/out
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION InternetCrackUrl LIB "WinINet.dll" _
    ALIAS "InternetCrackUrlA" _
   ( _
    lpszUrl           AS ASCIIZ, _         ' in
    BYVAL dwUrlLength AS DWORD, _          ' in
    BYVAL dwFlags     AS DWORD, _          ' in
    lpUrlComponents   AS URL_COMPONENTS _  ' in/out
   ) _
   AS LONG
#ENDIF

DECLARE FUNCTION InternetCreateUrlA LIB "WinINet.dll" _
   ALIAS "InternetCreateUrlA" _
   ( _
    lpUrlComponents AS URL_COMPONENTS, _ ' in
    BYVAL dwFlags AS DWORD, _            ' in
    lpszUrl AS ASCIIZ, _                 ' out
    lpdwUrlLength AS DWORD _             ' in/out
   ) _
   AS LONG

DECLARE FUNCTION InternetCreateUrlW LIB "WinINet.dll" _
   ALIAS "InternetCreateUrlW" _
   ( _
    lpUrlComponents AS URL_COMPONENTS, _ ' in
    BYVAL dwFlags AS DWORD, _            ' in
    lpszUrl AS WSTRINGZ, _               ' out
    lpdwUrlLength AS DWORD _             ' in/out
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetCreateUrl LIB "WinINet.dll" _
   ALIAS "InternetCreateUrlW" _
   ( _
    lpUrlComponents AS URL_COMPONENTS, _ ' in
    BYVAL dwFlags AS DWORD, _            ' in
    lpszUrl AS WSTRINGZ, _               ' out
    lpdwUrlLength AS DWORD _             ' in/out
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION InternetCreateUrl LIB "WinINet.dll" _
   ALIAS "InternetCreateUrlA" _
   ( _
    lpUrlComponents AS URL_COMPONENTS, _ ' in
    BYVAL dwFlags AS DWORD, _            ' in
    lpszUrl AS ASCIIZ, _                 ' out
    lpdwUrlLength AS DWORD _             ' in/out
   ) _
   AS LONG
#ENDIF

DECLARE FUNCTION InternetCanonicalizeUrlA LIB "WinINet.dll" _
   ALIAS "InternetCanonicalizeUrlA" _
   ( _
    lpszUrl AS ASCIIZ, _                 ' in
    lpszBuffer AS ASCIIZ, _              ' out
    lpdwBufferLength AS DWORD, _         ' in/out
    BYVAL dwFlags AS DWORD _             ' in
   ) _
   AS LONG

DECLARE FUNCTION InternetCanonicalizeUrlW LIB "WinINet.dll" _
   ALIAS "InternetCanonicalizeUrlW" _
   ( _
    lpszUrl AS WSTRINGZ, _               ' in
    lpszBuffer AS WSTRINGZ, _            ' out
    lpdwBufferLength AS DWORD, _         ' in/out
    BYVAL dwFlags AS DWORD _             ' in
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetCanonicalizeUrl LIB "WinINet.dll" _
   ALIAS "InternetCanonicalizeUrlW" _
   ( _
    lpszUrl AS WSTRINGZ, _               ' in
    lpszBuffer AS WSTRINGZ, _            ' out
    lpdwBufferLength AS DWORD, _         ' in/out
    BYVAL dwFlags AS DWORD _             ' in
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION InternetCanonicalizeUrl LIB "WinINet.dll" _
   ALIAS "InternetCanonicalizeUrlA" _
   ( _
    lpszUrl AS ASCIIZ, _                 ' in
    lpszBuffer AS ASCIIZ, _              ' out
    lpdwBufferLength AS DWORD, _         ' in/out
    BYVAL dwFlags AS DWORD _             ' in
   ) _
   AS LONG
#ENDIF

DECLARE FUNCTION InternetCombineUrlA LIB "WinINet.dll" _
   ALIAS "InternetCombineUrlA" _
   ( _
    lpszBaseUrl AS ASCIIZ, _             ' in
    lpszRelativeUrl AS ASCIIZ, _         ' in
    lpszBuffer AS ASCIIZ, _              ' out
    lpdwBufferLength AS DWORD, _         ' in/out
    BYVAL dwFlags AS DWORD _             ' in
   ) _
   AS LONG

DECLARE FUNCTION InternetCombineUrlW LIB "WinINet.dll" _
   ALIAS "InternetCombineUrlW" _
   ( _
    lpszBaseUrl AS WSTRINGZ, _             ' in
    lpszRelativeUrl AS WSTRINGZ, _         ' in
    lpszBuffer AS WSTRINGZ, _              ' out
    lpdwBufferLength AS DWORD, _         ' in/out
    BYVAL dwFlags AS DWORD _             ' in
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetCombineUrl LIB "WinINet.dll" _
   ALIAS "InternetCombineUrlW" _
   ( _
    lpszBaseUrl AS WSTRINGZ, _             ' in
    lpszRelativeUrl AS WSTRINGZ, _         ' in
    lpszBuffer AS WSTRINGZ, _              ' out
    lpdwBufferLength AS DWORD, _         ' in/out
    BYVAL dwFlags AS DWORD _             ' in
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION InternetCombineUrl LIB "WinINet.dll" _
   ALIAS "InternetCombineUrlA" _
   ( _
    lpszBaseUrl AS ASCIIZ, _             ' in
    lpszRelativeUrl AS ASCIIZ, _         ' in
    lpszBuffer AS ASCIIZ, _              ' out
    lpdwBufferLength AS DWORD, _         ' in/out
    BYVAL dwFlags AS DWORD _             ' in
   ) _
   AS LONG
#ENDIF

'
' flags for InternetCrackUrl() and InternetCreateUrl()
'

%ICU_ESCAPE      = &H80000000???  ' (un)escape URL characters
%ICU_USERNAME    = &H40000000???  ' use internal username & password

'
' flags for InternetCanonicalizeUrl() and InternetCombineUrl()
'

%ICU_NO_ENCODE          = &H20000000 ' Don't convert unsafe characters to escape sequence
%ICU_DECODE             = &H10000000 ' Convert %XX escape sequences to characters
%ICU_NO_META            = &H08000000 ' Don't convert .. etc. meta path sequences
%ICU_ENCODE_SPACES_ONLY = &H04000000 ' Encode spaces only
%ICU_BROWSER_MODE       = &H02000000 ' Special encode/decode rules for browser
%ICU_ENCODE_PERCENT     = &H00001000 ' Encode any percent (ASCII &H25) signs
                                     ' (default is to not encode percent).

DECLARE FUNCTION InternetOpenA LIB "WinINet.dll" ALIAS "InternetOpenA" _
   ( _
    lpszAgent AS ASCIIZ, _               ' in
    BYVAL dwAccessType AS DWORD, _       ' in
    lpszProxy AS ASCIIZ, _               ' in
    lpszProxyBypass AS ASCIIZ, _         ' in
    BYVAL dwFlags AS DWORD _             ' in
   ) _
   AS DWORD

DECLARE FUNCTION InternetOpenW LIB "WinINet.dll" ALIAS "InternetOpenW" _
   ( _
    lpszAgent AS WSTRINGZ, _             ' in
    BYVAL dwAccessType AS DWORD, _       ' in
    lpszProxy AS WSTRINGZ, _             ' in
    lpszProxyBypass AS WSTRINGZ, _       ' in
    BYVAL dwFlags AS DWORD _             ' in
   ) _
   AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetOpen LIB "WinINet.dll" ALIAS "InternetOpenW" _
   ( _
    lpszAgent AS WSTRINGZ, _             ' in
    BYVAL dwAccessType AS DWORD, _       ' in
    lpszProxy AS WSTRINGZ, _             ' in
    lpszProxyBypass AS WSTRINGZ, _       ' in
    BYVAL dwFlags AS DWORD _             ' in
   ) _
   AS DWORD
#ELSE
DECLARE FUNCTION InternetOpen LIB "WinINet.dll" ALIAS "InternetOpenA" _
   ( _
    lpszAgent AS ASCIIZ, _               ' in
    BYVAL dwAccessType AS DWORD, _       ' in
    lpszProxy AS ASCIIZ, _               ' in
    lpszProxyBypass AS ASCIIZ, _         ' in
    BYVAL dwFlags AS DWORD _             ' in
   ) _
   AS DWORD
#ENDIF

'
' access types for InternetOpen()
'

%INTERNET_OPEN_TYPE_PRECONFIG                   = 0 ' use registry configuration
%INTERNET_OPEN_TYPE_DIRECT                      = 1 ' direct to net
%INTERNET_OPEN_TYPE_PROXY                       = 3 ' via named proxy
%INTERNET_OPEN_TYPE_PRECONFIG_WITH_NO_AUTOPROXY = 4 ' prevent using java/script/INS

'
' old names for access types
'

%PRE_CONFIG_INTERNET_ACCESS  = %INTERNET_OPEN_TYPE_PRECONFIG
%LOCAL_INTERNET_ACCESS       = %INTERNET_OPEN_TYPE_DIRECT
%CERN_PROXY_INTERNET_ACCESS  = %INTERNET_OPEN_TYPE_PROXY

DECLARE FUNCTION InternetCloseHandle LIB "WinINet.dll" _
   ALIAS "InternetCloseHandle" _
   ( _
    BYVAL hInternet AS DWORD _    ' in
   ) _
   AS LONG

'
' service types for InternetConnect()
'

%INTERNET_SERVICE_FTP    = 1
%INTERNET_SERVICE_GOPHER = 2
%INTERNET_SERVICE_HTTP   = 3

DECLARE FUNCTION InternetOpenUrlA LIB "WinINet.dll" ALIAS "InternetOpenUrlA" _
   ( _
    BYVAL hInternet AS DWORD, _          ' in
    lpszUrl AS ASCIIZ, _                 ' in
    lpszHeaders AS ASCIIZ, _             ' in
    BYVAL dwHeadersLength AS DWORD, _    ' in
    BYVAL dwFlags AS DWORD, _            ' in
    BYVAL dwContext AS DWORD _           ' in
   ) _
   AS DWORD

DECLARE FUNCTION InternetOpenUrlW LIB "WinINet.dll" ALIAS "InternetOpenUrlW" _
   ( _
    BYVAL hInternet AS DWORD, _          ' in
    lpszUrl AS WSTRINGZ, _               ' in
    lpszHeaders AS WSTRINGZ, _           ' in
    BYVAL dwHeadersLength AS DWORD, _    ' in
    BYVAL dwFlags AS DWORD, _            ' in
    BYVAL dwContext AS DWORD _           ' in
   ) _
   AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetOpenUrl LIB "WinINet.dll" ALIAS "InternetOpenUrlW" _
   ( _
    BYVAL hInternet AS DWORD, _          ' in
    lpszUrl AS WSTRINGZ, _               ' in
    lpszHeaders AS WSTRINGZ, _           ' in
    BYVAL dwHeadersLength AS DWORD, _    ' in
    BYVAL dwFlags AS DWORD, _            ' in
    BYVAL dwContext AS DWORD _           ' in
   ) _
   AS DWORD
#ELSE
DECLARE FUNCTION InternetOpenUrl LIB "WinINet.dll" ALIAS "InternetOpenUrlA" _
   ( _
    BYVAL hInternet AS DWORD, _          ' in
    lpszUrl AS ASCIIZ, _                 ' in
    lpszHeaders AS ASCIIZ, _             ' in
    BYVAL dwHeadersLength AS DWORD, _    ' in
    BYVAL dwFlags AS DWORD, _            ' in
    BYVAL dwContext AS DWORD _           ' in
   ) _
   AS DWORD
#ENDIF

DECLARE FUNCTION InternetReadFile LIB "WinINet.dll" ALIAS "InternetReadFile" _
   ( _
    BYVAL hFile AS DWORD, _                  ' in
    BYVAL lpBuffer AS BYTE PTR, _            ' in
    BYVAL dwNumberOfBytesToRead AS DWORD, _  ' in
    lpdwNumberOfBytesRead AS DWORD _         ' out
   ) _
   AS LONG

DECLARE FUNCTION InternetReadFileExA LIB "WinINet.dll" _
   ALIAS "InternetReadFileExA" _
   ( _
    BYVAL hFile AS DWORD, _                  ' in
    lpBuffersOut AS INTERNET_BUFFERSA, _     ' out
    BYVAL dwFlags AS DWORD, _                ' in
    BYVAL dwContext AS DWORD _               ' in
   ) _
   AS LONG

DECLARE FUNCTION InternetReadFileExW LIB "WinINet.dll" _
   ALIAS "InternetReadFileExW" _
   ( _
    BYVAL hFile AS DWORD, _                  ' in
    lpBuffersOut AS INTERNET_BUFFERSW, _     ' out
    BYVAL dwFlags AS DWORD, _                ' in
    BYVAL dwContext AS DWORD _               ' in
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetReadFileEx LIB "WinINet.dll" _
   ALIAS "InternetReadFileExW" _
   ( _
    BYVAL hFile AS DWORD, _                  ' in
    lpBuffersOut AS INTERNET_BUFFERSW, _     ' out
    BYVAL dwFlags AS DWORD, _                ' in
    BYVAL dwContext AS DWORD _               ' in
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION InternetReadFileEx LIB "WinINet.dll" _
   ALIAS "InternetReadFileExA" _
   ( _
    BYVAL hFile AS DWORD, _                  ' in
    lpBuffersOut AS INTERNET_BUFFERSA, _     ' out
    BYVAL dwFlags AS DWORD, _                ' in
    BYVAL dwContext AS DWORD _               ' in
   ) _
   AS LONG
#ENDIF

'
' flags for InternetReadFileEx()
'

%IRF_ASYNC       = %WININET_API_FLAG_ASYNC
%IRF_SYNC        = %WININET_API_FLAG_SYNC
%IRF_USE_CONTEXT = %WININET_API_FLAG_USE_CONTEXT
%IRF_NO_WAIT     = &H00000008

DECLARE FUNCTION InternetSetFilePointer LIB "WinINet.dll" _
   ALIAS "InternetSetFilePointer" _
   ( _
    BYVAL hFile AS DWORD, _               ' in
    BYVAL lDistanceToMove AS LONG, _      ' in
    BYVAL lpDistanceToMoveHigh AS LONG, _ ' in/out
    BYVAL dwMoveMethod AS DWORD, _        ' in
    BYVAL dwContext AS DWORD _            ' in
   ) _
   AS DWORD

DECLARE FUNCTION InternetWriteFile LIB "WinINet.dll" _
   ALIAS "InternetWriteFile" _
   ( _
    BYVAL hFile AS DWORD, _                   ' in
    BYVAL lpBuffer AS BYTE PTR, _             ' in
    BYVAL dwNumberOfBytesToWrite AS DWORD, _  ' in
    lpdwNumberOfBytesWritten AS DWORD _       ' out
   ) _
   AS LONG

DECLARE FUNCTION InternetQueryDataAvailable LIB "WinINet.dll" _
   ALIAS "InternetQueryDataAvailable" _
   ( _
    BYVAL hFile AS DWORD, _                   ' in
    lpdwNumberOfBytesAvailable AS DWORD, _    ' out
    BYVAL dwFlags AS DWORD, _                 ' in
    BYVAL dwContext AS DWORD _                ' in
   ) _
   AS LONG

DECLARE FUNCTION InternetFindNextFileA LIB "WinINet.dll" _
   ALIAS "InternetFindNextFileA" _
   ( _
    BYVAL hFind AS DWORD, _         ' in
    BYVAL lpvFindData AS BYTE PTR _ ' out
   ) _
   AS LONG

DECLARE FUNCTION InternetFindNextFileW LIB "WinINet.dll" _
   ALIAS "InternetFindNextFileW" _
   ( _
    BYVAL hFind AS DWORD, _         ' in
    BYVAL lpvFindData AS BYTE PTR _ ' out
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetFindNextFile LIB "WinINet.dll" _
   ALIAS "InternetFindNextFileW" _
   ( _
    BYVAL hFind AS DWORD, _         ' in
    BYVAL lpvFindData AS BYTE PTR _ ' out
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION InternetFindNextFile LIB "WinINet.dll" _
   ALIAS "InternetFindNextFileA" _
   ( _
    BYVAL hFind AS DWORD, _         ' in
    BYVAL lpvFindData AS BYTE PTR _ ' out
   ) _
   AS LONG
#ENDIF

DECLARE FUNCTION InternetQueryOptionA LIB "WinINet.dll" _
   ALIAS "InternetQueryOptionA" _
   ( _
    BYVAL hInternet AS DWORD, _        ' in
    BYVAL dwOption AS DWORD, _         ' in
    BYVAL lpBuffer AS BYTE PTR, _      ' out
    lpdwBufferLength AS DWORD _        ' in, out
   ) _
   AS LONG

DECLARE FUNCTION InternetQueryOptionW LIB "WinINet.dll" _
   ALIAS "InternetQueryOptionW" _
   ( _
    BYVAL hInternet AS DWORD, _        ' in
    BYVAL dwOption AS DWORD, _         ' in
    BYVAL lpBuffer AS BYTE PTR, _      ' out
    lpdwBufferLength AS DWORD _        ' in, out
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetQueryOption LIB "WinINet.dll" _
   ALIAS "InternetQueryOptionW" _
   ( _
    BYVAL hInternet AS DWORD, _        ' in
    BYVAL dwOption AS DWORD, _         ' in
    BYVAL lpBuffer AS BYTE PTR, _      ' out
    lpdwBufferLength AS DWORD _        ' in, out
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION InternetQueryOption LIB "WinINet.dll" _
   ALIAS "InternetQueryOptionA" _
   ( _
    BYVAL hInternet AS DWORD, _        ' in
    BYVAL dwOption AS DWORD, _         ' in
    BYVAL lpBuffer AS BYTE PTR, _      ' out
    lpdwBufferLength AS DWORD _        ' in, out
   ) _
   AS LONG
#ENDIF

DECLARE FUNCTION InternetSetOptionA LIB "WinINet.dll" _
   ALIAS "InternetSetOptionA" _
   ( _
    BYVAL hInternet AS DWORD, _        ' in
    BYVAL dwOption AS DWORD, _         ' in
    BYVAL lpBuffer AS BYTE PTR, _      ' in
    BYVAL dwBufferLength AS DWORD _    ' in
   ) _
   AS LONG

DECLARE FUNCTION InternetSetOptionW LIB "WinINet.dll" _
   ALIAS "InternetSetOptionW" _
   ( _
    BYVAL hInternet AS DWORD, _        ' in
    BYVAL dwOption AS DWORD, _         ' in
    BYVAL lpBuffer AS BYTE PTR, _      ' in
    BYVAL dwBufferLength AS DWORD _    ' in
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetSetOption LIB "WinINet.dll" _
   ALIAS "InternetSetOptionW" _
   ( _
    BYVAL hInternet AS DWORD, _        ' in
    BYVAL dwOption AS DWORD, _         ' in
    BYVAL lpBuffer AS BYTE PTR, _      ' in
    BYVAL dwBufferLength AS DWORD _    ' in
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION InternetSetOption LIB "WinINet.dll" _
   ALIAS "InternetSetOptionA" _
   ( _
    BYVAL hInternet AS DWORD, _        ' in
    BYVAL dwOption AS DWORD, _         ' in
    BYVAL lpBuffer AS BYTE PTR, _      ' in
    BYVAL dwBufferLength AS DWORD _    ' in
   ) _
   AS LONG
#ENDIF

DECLARE FUNCTION InternetSetOptionExA LIB "WinINet.dll" _
   ALIAS "InternetSetOptionExA" _
   ( _
    BYVAL hInternet AS DWORD, _        ' in
    BYVAL dwOption AS DWORD, _         ' in
    BYVAL lpBuffer AS BYTE PTR, _      ' in
    BYVAL dwBufferLength AS DWORD, _   ' in
    BYVAL dwFlags AS DWORD _           ' in
   ) _
   AS LONG

DECLARE FUNCTION InternetSetOptionExW LIB "WinINet.dll" _
   ALIAS "InternetSetOptionExW" _
   ( _
    BYVAL hInternet AS DWORD, _        ' in
    BYVAL dwOption AS DWORD, _         ' in
    BYVAL lpBuffer AS BYTE PTR, _      ' in
    BYVAL dwBufferLength AS DWORD, _   ' in
    BYVAL dwFlags AS DWORD _           ' in
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetSetOptionEx LIB "WinINet.dll" _
   ALIAS "InternetSetOptionExW" _
   ( _
    BYVAL hInternet AS DWORD, _        ' in
    BYVAL dwOption AS DWORD, _         ' in
    BYVAL lpBuffer AS BYTE PTR, _      ' in
    BYVAL dwBufferLength AS DWORD, _   ' in
    BYVAL dwFlags AS DWORD _           ' in
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION InternetSetOptionEx LIB "WinINet.dll" _
   ALIAS "InternetSetOptionExA" _
   ( _
    BYVAL hInternet AS DWORD, _        ' in
    BYVAL dwOption AS DWORD, _         ' in
    BYVAL lpBuffer AS BYTE PTR, _      ' in
    BYVAL dwBufferLength AS DWORD, _   ' in
    BYVAL dwFlags AS DWORD _           ' in
   ) _
   AS LONG
#ENDIF

DECLARE FUNCTION InternetLockRequestFile LIB "WinINet.dll" _
   ALIAS "InternetLockRequestFile" _
   ( _
    BYVAL hInternet AS LONG, _         ' in
    lphLockRequestInfo AS DWORD _      ' out
   ) _
   AS LONG

DECLARE FUNCTION InternetUnlockRequestFile LIB "WinINet.dll" _
   ALIAS "InternetUnlockRequestFile" _
   ( _
    BYVAL hLockRequestInfo AS DWORD _  ' in
   ) _
   AS LONG

'
' flags for InternetSetOptionEx()
'

%ISO_GLOBAL      = &H00000001  ' modify option globally
%ISO_REGISTRY    = &H00000002  ' write option to registry (where applicable)

%ISO_VALID_FLAGS = %ISO_GLOBAL OR %ISO_REGISTRY

'
' options manifests for Internet{Query OR Set}Option
'

%INTERNET_OPTION_CALLBACK                = 1
%INTERNET_OPTION_CONNECT_TIMEOUT         = 2
%INTERNET_OPTION_CONNECT_RETRIES         = 3
%INTERNET_OPTION_CONNECT_BACKOFF         = 4
%INTERNET_OPTION_SEND_TIMEOUT            = 5
%INTERNET_OPTION_CONTROL_SEND_TIMEOUT    = %INTERNET_OPTION_SEND_TIMEOUT
%INTERNET_OPTION_RECEIVE_TIMEOUT         = 6
%INTERNET_OPTION_CONTROL_RECEIVE_TIMEOUT = %INTERNET_OPTION_RECEIVE_TIMEOUT
%INTERNET_OPTION_DATA_SEND_TIMEOUT       = 7
%INTERNET_OPTION_DATA_RECEIVE_TIMEOUT    = 8
%INTERNET_OPTION_HANDLE_TYPE             = 9
%INTERNET_OPTION_LISTEN_TIMEOUT          = 11
%INTERNET_OPTION_READ_BUFFER_SIZE        = 12
%INTERNET_OPTION_WRITE_BUFFER_SIZE       = 13

%INTERNET_OPTION_ASYNC_ID                = 15
%INTERNET_OPTION_ASYNC_PRIORITY          = 16

%INTERNET_OPTION_PARENT_HANDLE           = 21
%INTERNET_OPTION_KEEP_CONNECTION         = 22
%INTERNET_OPTION_REQUEST_FLAGS           = 23
%INTERNET_OPTION_EXTENDED_ERROR          = 24

%INTERNET_OPTION_OFFLINE_MODE            = 26
%INTERNET_OPTION_CACHE_STREAM_HANDLE     = 27
%INTERNET_OPTION_USERNAME                = 28
%INTERNET_OPTION_PASSWORD                = 29
%INTERNET_OPTION_ASYNC                   = 30
%INTERNET_OPTION_SECURITY_FLAGS          = 31
%INTERNET_OPTION_SECURITY_CERTIFICATE_STRUCT = 32
%INTERNET_OPTION_DATAFILE_NAME           = 33
%INTERNET_OPTION_URL                     = 34
%INTERNET_OPTION_SECURITY_CERTIFICATE    = 35
%INTERNET_OPTION_SECURITY_KEY_BITNESS    = 36
%INTERNET_OPTION_REFRESH                 = 37
%INTERNET_OPTION_PROXY                   = 38
%INTERNET_OPTION_SETTINGS_CHANGED        = 39
%INTERNET_OPTION_VERSION                 = 40
%INTERNET_OPTION_USER_AGENT              = 41
%INTERNET_OPTION_END_BROWSER_SESSION     = 42
%INTERNET_OPTION_PROXY_USERNAME          = 43
%INTERNET_OPTION_PROXY_PASSWORD          = 44
%INTERNET_OPTION_CONTEXT_VALUE           = 45
%INTERNET_OPTION_CONNECT_LIMIT           = 46
%INTERNET_OPTION_SECURITY_SELECT_CLIENT_CERT = 47
%INTERNET_OPTION_POLICY                  = 48
%INTERNET_OPTION_DISCONNECTED_TIMEOUT    = 49
%INTERNET_OPTION_CONNECTED_STATE         = 50
%INTERNET_OPTION_IDLE_STATE              = 51
%INTERNET_OPTION_OFFLINE_SEMANTICS       = 52
%INTERNET_OPTION_SECONDARY_CACHE_KEY     = 53
%INTERNET_OPTION_CALLBACK_FILTER         = 54
%INTERNET_OPTION_CONNECT_TIME            = 55
%INTERNET_OPTION_SEND_THROUGHPUT         = 56
%INTERNET_OPTION_RECEIVE_THROUGHPUT      = 57
%INTERNET_OPTION_REQUEST_PRIORITY        = 58
%INTERNET_OPTION_HTTP_VERSION            = 59
%INTERNET_OPTION_RESET_URLCACHE_SESSION  = 60
%INTERNET_OPTION_ERROR_MASK              = 62
%INTERNET_OPTION_FROM_CACHE_TIMEOUT      = 63
%INTERNET_OPTION_BYPASS_EDITED_ENTRY     = 64

%INTERNET_OPTION_HTTP_DECODING           = 65

%INTERNET_OPTION_DIAGNOSTIC_SOCKET_INFO  = 67
%INTERNET_OPTION_CODEPAGE                = 68
%INTERNET_OPTION_CACHE_TIMESTAMPS        = 69
%INTERNET_OPTION_DISABLE_AUTODIAL        = 70
%INTERNET_OPTION_MAX_CONNS_PER_SERVER     = 73
%INTERNET_OPTION_MAX_CONNS_PER_1_0_SERVER = 74
%INTERNET_OPTION_PER_CONNECTION_OPTION    = 75
%INTERNET_OPTION_DIGEST_AUTH_UNLOAD       = 76
%INTERNET_OPTION_IGNORE_OFFLINE           = 77
%INTERNET_OPTION_IDENTITY                 = 78
%INTERNET_OPTION_REMOVE_IDENTITY          = 79
%INTERNET_OPTION_ALTER_IDENTITY           = 80
%INTERNET_OPTION_SUPPRESS_BEHAVIOR        = 81
%INTERNET_OPTION_AUTODIAL_MODE            = 82
%INTERNET_OPTION_AUTODIAL_CONNECTION      = 83
%INTERNET_OPTION_CLIENT_CERT_CONTEXT      = 84
%INTERNET_OPTION_AUTH_FLAGS               = 85
%INTERNET_OPTION_COOKIES_3RD_PARTY        = 86
%INTERNET_OPTION_DISABLE_PASSPORT_AUTH    = 87
%INTERNET_OPTION_SEND_UTF8_SERVERNAME_TO_PROXY = 88
%INTERNET_OPTION_EXEMPT_CONNECTION_LIMIT  = 89
%INTERNET_OPTION_ENABLE_PASSPORT_AUTH     = 90

%INTERNET_OPTION_HIBERNATE_INACTIVE_WORKER_THREADS = 91
%INTERNET_OPTION_ACTIVATE_WORKER_THREADS           = 92
%INTERNET_OPTION_RESTORE_WORKER_THREAD_DEFAULTS    = 93
%INTERNET_OPTION_SOCKET_SEND_BUFFER_LENGTH         = 94
%INTERNET_OPTION_PROXY_SETTINGS_CHANGED            = 95

%INTERNET_OPTION_DATAFILE_EXT                      = 96

%INTERNET_OPTION_CODEPAGE_PATH              = 100
%INTERNET_OPTION_CODEPAGE_EXTRA             = 101
%INTERNET_OPTION_IDN                        = 102
%INTERNET_OPTION_MAX_CONNS_PER_PROXY        = 103
%INTERNET_OPTION_SUPPRESS_SERVER_AUTH       = 104
%INTERNET_OPTION_SERVER_CERT_CHAIN_CONTEXT  = 105

%INTERNET_FIRST_OPTION = %INTERNET_OPTION_CALLBACK
%INTERNET_LAST_OPTION  = %INTERNET_OPTION_SERVER_CERT_CHAIN_CONTEXT


'
' values for INTERNET_OPTION_PRIORITY
'

%INTERNET_PRIORITY_FOREGROUND = 1000

'
' handle types
'

%INTERNET_HANDLE_TYPE_INTERNET         = 1
%INTERNET_HANDLE_TYPE_CONNECT_FTP      = 2
%INTERNET_HANDLE_TYPE_CONNECT_GOPHER   = 3
%INTERNET_HANDLE_TYPE_CONNECT_HTTP     = 4
%INTERNET_HANDLE_TYPE_FTP_FIND         = 5
%INTERNET_HANDLE_TYPE_FTP_FIND_HTML    = 6
%INTERNET_HANDLE_TYPE_FTP_FILE         = 7
%INTERNET_HANDLE_TYPE_FTP_FILE_HTML    = 8
%INTERNET_HANDLE_TYPE_GOPHER_FIND      = 9
%INTERNET_HANDLE_TYPE_GOPHER_FIND_HTML = 10
%INTERNET_HANDLE_TYPE_GOPHER_FILE      = 11
%INTERNET_HANDLE_TYPE_GOPHER_FILE_HTML = 12
%INTERNET_HANDLE_TYPE_HTTP_REQUEST     = 13
%INTERNET_HANDLE_TYPE_FILE_REQUEST     = 14

'
' values for INTERNET_OPTION_AUTH_FLAGS
'

%AUTH_FLAG_DISABLE_NEGOTIATE = &H00000001
%AUTH_FLAG_ENABLE_NEGOTIATE  = &H00000002
%AUTH_FLAG_DISABLE_BASIC_CLEARCHANNEL = &H00000004

'
' values for %INTERNET_OPTION_SECURITY_FLAGS
'

' query only
%SECURITY_FLAG_SECURE                    = &H00000001 ' can query only
%SECURITY_FLAG_STRENGTH_WEAK             = &H10000000
%SECURITY_FLAG_STRENGTH_MEDIUM           = &H40000000
%SECURITY_FLAG_STRENGTH_STRONG           = &H20000000
%SECURITY_FLAG_UNKNOWNBIT                = &H80000000???
%SECURITY_FLAG_FORTEZZA                  = &H08000000
%SECURITY_FLAG_NORMALBITNESS             = %SECURITY_FLAG_STRENGTH_WEAK


' The following are unused
%SECURITY_FLAG_SSL                       = &H00000002
%SECURITY_FLAG_SSL3                      = &H00000004
%SECURITY_FLAG_PCT                       = &H00000008
%SECURITY_FLAG_PCT4                      = &H00000010
%SECURITY_FLAG_IETFSSL4                  = &H00000020

' The following are for backwards compatability only.
%SECURITY_FLAG_40BIT                     = %SECURITY_FLAG_STRENGTH_WEAK
%SECURITY_FLAG_128BIT                    = %SECURITY_FLAG_STRENGTH_STRONG
%SECURITY_FLAG_56BIT                     = %SECURITY_FLAG_STRENGTH_MEDIUM


' settable flags
%SECURITY_FLAG_IGNORE_REVOCATION         = &H00000080
%SECURITY_FLAG_IGNORE_UNKNOWN_CA         = &H00000100
%SECURITY_FLAG_IGNORE_WRONG_USAGE        = &H00000200

%SECURITY_FLAG_IGNORE_CERT_CN_INVALID    = %INTERNET_FLAG_IGNORE_CERT_CN_INVALID
%SECURITY_FLAG_IGNORE_CERT_DATE_INVALID  = %INTERNET_FLAG_IGNORE_CERT_DATE_INVALID


%SECURITY_FLAG_IGNORE_REDIRECT_TO_HTTPS  = %INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTPS
%SECURITY_FLAG_IGNORE_REDIRECT_TO_HTTP   = %INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTP

%SECURITY_SET_MASK       = %SECURITY_FLAG_IGNORE_REVOCATION  OR _
                           %SECURITY_FLAG_IGNORE_UNKNOWN_CA  OR _
                           %SECURITY_FLAG_IGNORE_CERT_CN_INVALID  OR _
                           %SECURITY_FLAG_IGNORE_CERT_DATE_INVALID  OR _
                           %SECURITY_FLAG_IGNORE_WRONG_USAGE

%SECURITY_IGNORE_ERROR_MASK = (%INTERNET_FLAG_IGNORE_CERT_CN_INVALID   OR _
                               %INTERNET_FLAG_IGNORE_CERT_DATE_INVALID OR _
                               %SECURITY_FLAG_IGNORE_UNKNOWN_CA        OR _
                               %SECURITY_FLAG_IGNORE_REVOCATION    )


' valid autodial modes
%AUTODIAL_MODE_NEVER              = 1
%AUTODIAL_MODE_ALWAYS             = 2
%AUTODIAL_MODE_NO_NETWORK_PRESENT = 4

DECLARE FUNCTION InternetGetLastResponseInfoA LIB "WinINet.dll" _
   ALIAS "InternetGetLastResponseInfoA" _
   ( _
    lpdwError AS DWORD, _         ' out
    lpszBuffer AS ASCIIZ, _       ' out
    lpdwBufferLength AS DWORD _   ' in, out
   ) _
   AS LONG

DECLARE FUNCTION InternetGetLastResponseInfoW LIB "WinINet.dll" _
   ALIAS "InternetGetLastResponseInfoW" _
   ( _
    lpdwError AS DWORD, _         ' out
    lpszBuffer AS WSTRINGZ, _     ' out
    lpdwBufferLength AS DWORD _   ' in, out
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetGetLastResponseInfo LIB "WinINet.dll" _
   ALIAS "InternetGetLastResponseInfoW" _
   ( _
    lpdwError AS DWORD, _         ' out
    lpszBuffer AS WSTRINGZ, _     ' out
    lpdwBufferLength AS DWORD _   ' in, out
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION InternetGetLastResponseInfo LIB "WinINet.dll" _
   ALIAS "InternetGetLastResponseInfoA" _
   ( _
    lpdwError AS DWORD, _         ' out
    lpszBuffer AS ASCIIZ, _       ' out
    lpdwBufferLength AS DWORD _   ' in, out
   ) _
   AS LONG
#ENDIF

'
' callback function for InternetSetStatusCallback
'

'DECLARE SUB INTERNET_STATUS_CALLBACK ( _
'    BYVAL hInternet                 AS DWORD, _  ' HINTERNET
'    BYVAL dwContext                 AS DWORD, _  ' DWORD_PTR
'    BYVAL dwInternetStatus          AS DWORD, _
'    BYVAL lpvStatusInformation      AS DWORD, _  ' LPVOID
'    BYVAL dwStatusInformationLength AS DWORD _
'    )

DECLARE FUNCTION InternetSetStatusCallbackA LIB "WinINet.dll" _
   ALIAS "InternetSetStatusCallbackA" _
   ( _
    BYVAL hInternet AS DWORD, _              ' in
    BYVAL lpfnInternetCallback AS DWORD _    ' in
   ) _
   AS DWORD

DECLARE FUNCTION InternetSetStatusCallbackW LIB "WinINet.dll" _
   ALIAS "InternetSetStatusCallbackW" _
   ( _
    BYVAL hInternet AS DWORD, _              ' in
    BYVAL lpfnInternetCallback AS DWORD _    ' in
   ) _
   AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetSetStatusCallback LIB "WinINet.dll" _
   ALIAS "InternetSetStatusCallbackW" _
   ( _
    BYVAL hInternet AS DWORD, _              ' in
    BYVAL lpfnInternetCallback AS DWORD _    ' in
   ) _
   AS DWORD
#ELSEIF %DEF(%WINX32)
DECLARE FUNCTION InternetSetStatusCallback LIB "WinINet.dll" _
   ALIAS "InternetSetStatusCallbackA" _
   ( _
    BYVAL hInternet AS DWORD, _              ' in
    BYVAL lpfnInternetCallback AS DWORD _    ' in
   ) _
   AS DWORD
#ELSE
DECLARE FUNCTION InternetSetStatusCallback LIB "WinINet.dll" _
    ALIAS "InternetSetStatusCallback" ( _
    BYVAL hInternet AS DWORD, _  ' HINTERNET
    BYVAL lpfnInternetCallback AS DWORD _  ' INTERNET_STATUS_CALLBACK
    ) AS DWORD
#ENDIF

'
' status manifests for Internet status callback
'

%INTERNET_STATUS_RESOLVING_NAME        = 10
%INTERNET_STATUS_NAME_RESOLVED         = 11
%INTERNET_STATUS_CONNECTING_TO_SERVER  = 20
%INTERNET_STATUS_CONNECTED_TO_SERVER   = 21
%INTERNET_STATUS_SENDING_REQUEST       = 30
%INTERNET_STATUS_REQUEST_SENT          = 31
%INTERNET_STATUS_RECEIVING_RESPONSE    = 40
%INTERNET_STATUS_RESPONSE_RECEIVED     = 41
%INTERNET_STATUS_CTL_RESPONSE_RECEIVED = 42
%INTERNET_STATUS_PREFETCH              = 43
%INTERNET_STATUS_CLOSING_CONNECTION    = 50
%INTERNET_STATUS_CONNECTION_CLOSED     = 51
%INTERNET_STATUS_HANDLE_CREATED        = 60
%INTERNET_STATUS_HANDLE_CLOSING        = 70
%INTERNET_STATUS_DETECTING_PROXY       = 80
%INTERNET_STATUS_REQUEST_COMPLETE      = 100
%INTERNET_STATUS_REDIRECT              = 110
%INTERNET_STATUS_INTERMEDIATE_RESPONSE = 120
%INTERNET_STATUS_USER_INPUT_REQUIRED   = 140
%INTERNET_STATUS_STATE_CHANGE          = 200
%INTERNET_STATUS_COOKIE_SENT           = 320
%INTERNET_STATUS_COOKIE_RECEIVED       = 321
%INTERNET_STATUS_PRIVACY_IMPACTED      = 324
%INTERNET_STATUS_P3P_HEADER            = 325
%INTERNET_STATUS_P3P_POLICYREF         = 326
%INTERNET_STATUS_COOKIE_HISTORY        = 327


'
' the following can be indicated in a state change notification:
'

%INTERNET_STATE_CONNECTED              = &H00000001  ' connected state (mutually exclusive with disconnected)
%INTERNET_STATE_DISCONNECTED           = &H00000002  ' disconnected from network
%INTERNET_STATE_DISCONNECTED_BY_USER   = &H00000010  ' disconnected by user request
%INTERNET_STATE_IDLE                   = &H00000100  ' no network requests being made (by Wininet)
%INTERNET_STATE_BUSY                   = &H00000200  ' network requests being made (by Wininet)

'
' the following values are used for cookie state:
' (InternetCookieState enumerated type)
'

MACRO InternetCookieState_enum=LONG
ENUM InternetCookieState SINGULAR
    COOKIE_STATE_UNKNOWN
    COOKIE_STATE_ACCEPT
    COOKIE_STATE_PROMPT
    COOKIE_STATE_LEASH
    COOKIE_STATE_DOWNGRADE
    COOKIE_STATE_REJECT
    COOKIE_STATE_MAX       = %COOKIE_STATE_REJECT
END ENUM

TYPE IncomingCookieState
    cSession    AS LONG       ' Session cookies received
    cPersistent AS LONG       ' Persistent cookies received

    cAccepted   AS LONG       ' Number of cookies accepted
    cLeashed    AS LONG       '               ... leashed
    cDowngraded AS LONG       '               ... converted to session-cookies
    cBlocked    AS LONG       '               ... rejected

    pszLocation AS ASCIIZ PTR ' Optional: URL associated with reported cookie events
                              ' This can be used to override request URL
END TYPE

TYPE OutgoingCookieState
    cSent       AS LONG
    cSuppressed AS LONG
    pszLocation AS ASCIIZ PTR ' Optional: URL associated with reported cookie events
                              ' This can be used to override request URL
END TYPE

TYPE InternetCookieHistory
    fAccepted   AS LONG       ' BOOL
    fLeashed    AS LONG       ' BOOL
    fDowngraded AS LONG       ' BOOL
    fRejected   AS LONG       ' BOOL
END TYPE


TYPE CookieDecision
    dwCookieState AS DWORD
    fAllowSession AS LONG     ' BOOL
END TYPE

'
' if the following value is returned by InternetSetStatusCallback, then
' probably an invalid (non-code) address was supplied for the callback
'

%INTERNET_INVALID_STATUS_CALLBACK = &HFFFFFFFF???  ' (DWORD)(-1)

'
' FTP
'

'
' prototypes
'

DECLARE FUNCTION FtpFindFirstFileA LIB "WinINet.dll" _
   ALIAS "FtpFindFirstFileA" _
   ( _
    BYVAL hConnect  AS DWORD, _             ' in
    lpszSearchFile  AS ASCIIZ, _            ' in
    lpFindFileData  AS WIN32_FIND_DATAA, _  ' out
    BYVAL dwFlags   AS DWORD, _             ' in
    BYVAL dwContext AS DWORD _
   ) AS DWORD

DECLARE FUNCTION FtpFindFirstFileW LIB "WinINet.dll" _
   ALIAS "FtpFindFirstFileW" _
   ( _
    BYVAL hConnect  AS DWORD, _             ' in
    lpszSearchFile  AS WSTRINGZ, _          ' in
    lpFindFileData  AS WIN32_FIND_DATAW, _  ' out
    BYVAL dwFlags   AS DWORD, _             ' in
    BYVAL dwContext AS DWORD _
   ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION FtpFindFirstFile LIB "WinINet.dll" _
   ALIAS "FtpFindFirstFileW" _
   ( _
    BYVAL hConnect  AS DWORD, _             ' in
    lpszSearchFile  AS WSTRINGZ, _          ' in
    lpFindFileData  AS WIN32_FIND_DATAW, _  ' out
    BYVAL dwFlags   AS DWORD, _             ' in
    BYVAL dwContext AS DWORD _
   ) AS DWORD
#ELSE
DECLARE FUNCTION FtpFindFirstFile LIB "WinINet.dll" _
   ALIAS "FtpFindFirstFileA" _
   ( _
    BYVAL hConnect  AS DWORD, _             ' in
    lpszSearchFile  AS ASCIIZ, _            ' in
    lpFindFileData  AS WIN32_FIND_DATAA, _  ' out
    BYVAL dwFlags   AS DWORD, _             ' in
    BYVAL dwContext AS DWORD _
   ) AS DWORD
#ENDIF

DECLARE FUNCTION FtpGetFileA LIB "WinINet.dll" ALIAS "FtpGetFileA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszRemoteFile AS ASCIIZ, _             ' in
    lpszNewFile AS ASCIIZ, _                ' in
    BYVAL fFailIfExists AS LONG, _          ' in
    BYVAL dwFlagsAndAttributes AS DWORD, _  ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS LONG

DECLARE FUNCTION FtpGetFileW LIB "WinINet.dll" ALIAS "FtpGetFileW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszRemoteFile AS WSTRINGZ, _           ' in
    lpszNewFile AS WSTRINGZ, _              ' in
    BYVAL fFailIfExists AS LONG, _          ' in
    BYVAL dwFlagsAndAttributes AS DWORD, _  ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION FtpGetFile LIB "WinINet.dll" ALIAS "FtpGetFileW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszRemoteFile AS WSTRINGZ, _           ' in
    lpszNewFile AS WSTRINGZ, _              ' in
    BYVAL fFailIfExists AS LONG, _          ' in
    BYVAL dwFlagsAndAttributes AS DWORD, _  ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS LONG
#ELSE
DECLARE FUNCTION FtpGetFile LIB "WinINet.dll" ALIAS "FtpGetFileA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszRemoteFile AS ASCIIZ, _             ' in
    lpszNewFile AS ASCIIZ, _                ' in
    BYVAL fFailIfExists AS LONG, _          ' in
    BYVAL dwFlagsAndAttributes AS DWORD, _  ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS LONG
#ENDIF

DECLARE FUNCTION FtpPutFileA LIB "WinINet.dll" ALIAS "FtpPutFileA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszLocalFile AS ASCIIZ, _              ' in
    lpszNewRemoteFile AS ASCIIZ, _          ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS LONG

DECLARE FUNCTION FtpPutFileW LIB "WinINet.dll" ALIAS "FtpPutFileW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszLocalFile AS WSTRINGZ, _            ' in
    lpszNewRemoteFile AS WSTRINGZ, _        ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION FtpPutFile LIB "WinINet.dll" ALIAS "FtpPutFileW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszLocalFile AS WSTRINGZ, _            ' in
    lpszNewRemoteFile AS WSTRINGZ, _        ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS LONG
#ELSE
DECLARE FUNCTION FtpPutFile LIB "WinINet.dll" ALIAS "FtpPutFileA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszLocalFile AS ASCIIZ, _              ' in
    lpszNewRemoteFile AS ASCIIZ, _          ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS LONG
#ENDIF

DECLARE FUNCTION FtpGetFileEx LIB "WinINet.dll" ALIAS "FtpGetFileEx" _
   ( _
    BYVAL hFtpSession AS DWORD, _           ' in
    lpszRemoteFile AS ASCIIZ, _             ' in
    lpszNewFile AS WSTRINGZ, _              ' in
    BYVAL fFailIfExists AS LONG, _          ' in
    BYVAL dwFlagsAndAttributes AS DWORD, _  ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) _
   AS LONG

DECLARE FUNCTION FtpPutFileEx LIB "WinINet.dll" ALIAS "FtpPutFileEx" _
   ( _
    BYVAL hFtpSession AS DWORD, _           ' in
    lpszLocalFile AS WSTRINGZ, _            ' in
    lpszNewRemoteFile AS ASCIIZ, _          ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) _
   AS LONG

DECLARE FUNCTION FtpDeleteFileA LIB "WinINet.dll" ALIAS "FtpDeleteFileA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszFileName AS ASCIIZ _                ' in
   ) AS LONG

DECLARE FUNCTION FtpDeleteFileW LIB "WinINet.dll" ALIAS "FtpDeleteFileW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszFileName AS WSTRINGZ _              ' in
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION FtpDeleteFile LIB "WinINet.dll" ALIAS "FtpDeleteFileW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszFileName AS WSTRINGZ _              ' in
   ) AS LONG
#ELSE
DECLARE FUNCTION FtpDeleteFile LIB "WinINet.dll" ALIAS "FtpDeleteFileA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszFileName AS ASCIIZ _                ' in
   ) AS LONG
#ENDIF

DECLARE FUNCTION FtpRenameFileA LIB "WinINet.dll" ALIAS "FtpRenameFileA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszExisting AS ASCIIZ, _               ' in
    lpszNew AS ASCIIZ _                     ' in
   ) AS LONG

DECLARE FUNCTION FtpRenameFileW LIB "WinINet.dll" ALIAS "FtpRenameFileW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszExisting AS WSTRINGZ, _             ' in
    lpszNew AS WSTRINGZ _                   ' in
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION FtpRenameFile LIB "WinINet.dll" ALIAS "FtpRenameFileW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszExisting AS WSTRINGZ, _             ' in
    lpszNew AS WSTRINGZ _                   ' in
   ) AS LONG
#ELSE
DECLARE FUNCTION FtpRenameFile LIB "WinINet.dll" ALIAS "FtpRenameFileA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszExisting AS ASCIIZ, _               ' in
    lpszNew AS ASCIIZ _                     ' in
   ) AS LONG
#ENDIF

DECLARE FUNCTION FtpOpenFileA LIB "WinINet.dll" ALIAS "FtpOpenFileA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszFileName AS ASCIIZ, _               ' in
    BYVAL dwAccess AS DWORD, _              ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS DWORD

DECLARE FUNCTION FtpOpenFileW LIB "WinINet.dll" ALIAS "FtpOpenFileW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszFileName AS WSTRINGZ, _             ' in
    BYVAL dwAccess AS DWORD, _              ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION FtpOpenFile LIB "WinINet.dll" ALIAS "FtpOpenFileW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszFileName AS WSTRINGZ, _             ' in
    BYVAL dwAccess AS DWORD, _              ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS DWORD
#ELSE
DECLARE FUNCTION FtpOpenFile LIB "WinINet.dll" ALIAS "FtpOpenFileA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszFileName AS ASCIIZ, _               ' in
    BYVAL dwAccess AS DWORD, _              ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS DWORD
#ENDIF

DECLARE FUNCTION FtpCreateDirectoryA LIB "WinINet.dll" _
   ALIAS "FtpCreateDirectoryA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszDirectory AS ASCIIZ _               ' in
   ) AS LONG

DECLARE FUNCTION FtpCreateDirectoryW LIB "WinINet.dll" _
   ALIAS "FtpCreateDirectoryW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszDirectory AS WSTRINGZ _             ' in
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION FtpCreateDirectory LIB "WinINet.dll" _
   ALIAS "FtpCreateDirectoryW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszDirectory AS WSTRINGZ _             ' in
   ) AS LONG
#ELSE
DECLARE FUNCTION FtpCreateDirectory LIB "WinINet.dll" _
   ALIAS "FtpCreateDirectoryA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszDirectory AS ASCIIZ _               ' in
   ) AS LONG
#ENDIF

DECLARE FUNCTION FtpRemoveDirectoryA LIB "WinINet.dll" _
   ALIAS "FtpRemoveDirectoryA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszDirectory AS ASCIIZ _               ' in
   ) AS LONG

DECLARE FUNCTION FtpRemoveDirectoryW LIB "WinINet.dll" _
   ALIAS "FtpRemoveDirectoryW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszDirectory AS WSTRINGZ _             ' in
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION FtpRemoveDirectory LIB "WinINet.dll" _
   ALIAS "FtpRemoveDirectoryW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszDirectory AS WSTRINGZ _             ' in
   ) AS LONG
#ELSE
DECLARE FUNCTION FtpRemoveDirectory LIB "WinINet.dll" _
   ALIAS "FtpRemoveDirectoryA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszDirectory AS ASCIIZ _               ' in
   ) AS LONG
#ENDIF

DECLARE FUNCTION FtpSetCurrentDirectoryA LIB "WinINet.dll" _
   ALIAS "FtpSetCurrentDirectoryA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszDirectory AS ASCIIZ _               ' in
   ) AS LONG

DECLARE FUNCTION FtpSetCurrentDirectoryW LIB "WinINet.dll" _
   ALIAS "FtpSetCurrentDirectoryW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszDirectory AS WSTRINGZ _             ' in
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION FtpSetCurrentDirectory LIB "WinINet.dll" _
   ALIAS "FtpSetCurrentDirectoryW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszDirectory AS WSTRINGZ _             ' in
   ) AS LONG
#ELSE
DECLARE FUNCTION FtpSetCurrentDirectory LIB "WinINet.dll" _
   ALIAS "FtpSetCurrentDirectoryA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszDirectory AS ASCIIZ _               ' in
   ) AS LONG
#ENDIF

DECLARE FUNCTION FtpGetCurrentDirectoryA LIB "WinINet.dll" _
   ALIAS "FtpGetCurrentDirectoryA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszCurrentDirectory AS ASCIIZ, _       ' out
    lpdwCurrentDirectory AS DWORD _         ' in, out
   ) AS LONG

DECLARE FUNCTION FtpGetCurrentDirectoryW LIB "WinINet.dll" _
   ALIAS "FtpGetCurrentDirectoryW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszCurrentDirectory AS WSTRINGZ, _     ' out
    lpdwCurrentDirectory AS DWORD _         ' in, out
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION FtpGetCurrentDirectory LIB "WinINet.dll" _
   ALIAS "FtpGetCurrentDirectoryW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszCurrentDirectory AS WSTRINGZ, _     ' out
    lpdwCurrentDirectory AS DWORD _         ' in, out
   ) AS LONG
#ELSE
DECLARE FUNCTION FtpGetCurrentDirectory LIB "WinINet.dll" _
   ALIAS "FtpGetCurrentDirectoryA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszCurrentDirectory AS ASCIIZ, _       ' out
    lpdwCurrentDirectory AS DWORD _         ' in, out
   ) AS LONG
#ENDIF

DECLARE FUNCTION FtpCommandA LIB "WinINet.dll" ALIAS "FtpCommandA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    BYVAL fExpectResponse AS LONG, _        ' in
    BYVAL dwFlags AS DWORD, _               ' in
    lpszCommand AS ASCIIZ, _                ' in
    BYVAL dwContext AS DWORD, _             ' in
    phFtpCommand AS DWORD _                 ' out
   ) AS LONG

DECLARE FUNCTION FtpCommandW LIB "WinINet.dll" ALIAS "FtpCommandW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    BYVAL fExpectResponse AS LONG, _        ' in
    BYVAL dwFlags AS DWORD, _               ' in
    lpszCommand AS WSTRINGZ, _              ' in
    BYVAL dwContext AS DWORD, _             ' in
    phFtpCommand AS DWORD _                 ' out
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION FtpCommand LIB "WinINet.dll" ALIAS "FtpCommandW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    BYVAL fExpectResponse AS LONG, _        ' in
    BYVAL dwFlags AS DWORD, _               ' in
    lpszCommand AS WSTRINGZ, _              ' in
    BYVAL dwContext AS DWORD, _             ' in
    phFtpCommand AS DWORD _                 ' out
   ) AS LONG
#ELSE
DECLARE FUNCTION FtpCommand LIB "WinINet.dll" ALIAS "FtpCommandA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    BYVAL fExpectResponse AS LONG, _        ' in
    BYVAL dwFlags AS DWORD, _               ' in
    lpszCommand AS ASCIIZ, _                ' in
    BYVAL dwContext AS DWORD, _             ' in
    phFtpCommand AS DWORD _                 ' out
   ) AS LONG
#ENDIF

DECLARE FUNCTION FtpGetFileSize LIB "WinINet.dll" ALIAS "FtpGetFileSize" _
   ( _
    BYVAL hFile AS DWORD, _                 ' in
    lpdwFileSizeHigh AS DWORD _             ' out
   ) AS DWORD


'
' Gopher
'

'
' manifests
'

'
' string field lengths (in characters, not bytes)
'

%MAX_GOPHER_DISPLAY_TEXT     = 128
%MAX_GOPHER_SELECTOR_TEXT    = 256
%MAX_GOPHER_HOST_NAME        = %INTERNET_MAX_HOST_NAME_LENGTH
%MAX_GOPHER_LOCATOR_LENGTH   = 1                                   _
                               + %MAX_GOPHER_DISPLAY_TEXT          _
                               + 1                                 _
                               + %MAX_GOPHER_SELECTOR_TEXT         _
                               + 1                                 _
                               + %MAX_GOPHER_HOST_NAME             _
                               + 1                                 _
                               + %INTERNET_MAX_PORT_NUMBER_LENGTH  _
                               + 1                                 _
                               + 1                                 _
                               + 2

'
' structures/types
'

'
' GOPHER_FIND_DATA - returns the results of a GopherFindFirstFile()/
' InternetFindNextFile() request
'

TYPE GOPHER_FIND_DATAA
    DisplayString        AS ASCIIZ * %MAX_GOPHER_DISPLAY_TEXT + 1
    GopherType           AS DWORD
    SizeLow              AS DWORD
    SizeHigh             AS DWORD
    LastModificationTime AS FILETIME
    Locator              AS ASCIIZ * %MAX_GOPHER_LOCATOR_LENGTH + 1
END TYPE

TYPE GOPHER_FIND_DATAW
    DisplayString        AS WSTRINGZ * %MAX_GOPHER_DISPLAY_TEXT + 1
    GopherType           AS DWORD
    SizeLow              AS DWORD
    SizeHigh             AS DWORD
    LastModificationTime AS FILETIME
    Locator              AS WSTRINGZ * %MAX_GOPHER_LOCATOR_LENGTH + 1
END TYPE

#IF %DEF(%UNICODE)
TYPE GOPHER_FIND_DATA
    GOPHER_FIND_DATAW
END TYPE
#ELSE
TYPE GOPHER_FIND_DATA
    GOPHER_FIND_DATAA
END TYPE
#ENDIF


'
' manifests for GopherType
'

%GOPHER_TYPE_TEXT_FILE       = &H00000001???
%GOPHER_TYPE_DIRECTORY       = &H00000002???
%GOPHER_TYPE_CSO             = &H00000004???
%GOPHER_TYPE_ERROR           = &H00000008???
%GOPHER_TYPE_MAC_BINHEX      = &H00000010???
%GOPHER_TYPE_DOS_ARCHIVE     = &H00000020???
%GOPHER_TYPE_UNIX_UUENCODED  = &H00000040???
%GOPHER_TYPE_INDEX_SERVER    = &H00000080???
%GOPHER_TYPE_TELNET          = &H00000100???
%GOPHER_TYPE_BINARY          = &H00000200???
%GOPHER_TYPE_REDUNDANT       = &H00000400???
%GOPHER_TYPE_TN3270          = &H00000800???
%GOPHER_TYPE_GIF             = &H00001000???
%GOPHER_TYPE_IMAGE           = &H00002000???
%GOPHER_TYPE_BITMAP          = &H00004000???
%GOPHER_TYPE_MOVIE           = &H00008000???
%GOPHER_TYPE_SOUND           = &H00010000???
%GOPHER_TYPE_HTML            = &H00020000???
%GOPHER_TYPE_PDF             = &H00040000???
%GOPHER_TYPE_CALENDAR        = &H00080000???
%GOPHER_TYPE_INLINE          = &H00100000???
%GOPHER_TYPE_UNKNOWN         = &H20000000???
%GOPHER_TYPE_ASK             = &H40000000???
%GOPHER_TYPE_GOPHER_PLUS     = &H80000000???

'
' GOPHER_TYPE_FILE_MASK - use this to determine if a locator identifies a
' (known) file type
'

%GOPHER_TYPE_FILE_MASK = %GOPHER_TYPE_TEXT_FILE          _
                       OR %GOPHER_TYPE_MAC_BINHEX        _
                       OR %GOPHER_TYPE_DOS_ARCHIVE       _
                       OR %GOPHER_TYPE_UNIX_UUENCODED    _
                       OR %GOPHER_TYPE_BINARY            _
                       OR %GOPHER_TYPE_GIF               _
                       OR %GOPHER_TYPE_IMAGE             _
                       OR %GOPHER_TYPE_BITMAP            _
                       OR %GOPHER_TYPE_MOVIE             _
                       OR %GOPHER_TYPE_SOUND             _
                       OR %GOPHER_TYPE_HTML              _
                       OR %GOPHER_TYPE_PDF               _
                       OR %GOPHER_TYPE_CALENDAR          _
                       OR %GOPHER_TYPE_INLINE

' gopher type macros
'

MACRO IS_GOPHER_FILE (nType) = ABS(((nType) AND %GOPHER_TYPE_FILE_MASK) <> 0)
MACRO IS_GOPHER_DIRECTORY (nType) = ABS(((nType) AND %GOPHER_TYPE_DIRECTORY) <> 0)
MACRO IS_GOPHER_PHONE_SERVER (nType) = ABS(((nType) AND %GOPHER_TYPE_CSO) <> 0)
MACRO IS_GOPHER_ERROR (nType) = ABS(((nType) AND %GOPHER_TYPE_ERROR) <> 0)
MACRO IS_GOPHER_INDEX_SERVER (nType) = ABS(((nType) AND %GOPHER_TYPE_INDEX_SERVER) <> 0)
MACRO IS_GOPHER_TELNET_SESSION (nType) = ABS(((nType) AND %GOPHER_TYPE_TELNET) <> 0)
MACRO IS_GOPHER_BACKUP_SERVER (nType) = ABS(((nType) AND %GOPHER_TYPE_REDUNDANT) <> 0)
MACRO IS_GOPHER_TN3280_SESSION (nType) = ABS(((nType) AND %GOPHER_TYPE_TN3270) <> 0)
MACRO IS_GOPHER_ASK (nType) = ABS(((nType) AND %GOPHER_TYPE_ASK) <> 0)
MACRO IS_GOPHER_PLUS (nType) = ABS(((nType) AND %GOPHER_TYPE_GOPHER_PLUS) <> 0)
MACRO IS_GOPHER_TYPE_KNOWN (nType) = ABS(((nType) AND %GOPHER_TYPE_UNKNOWN) = 0)

'
' structured gopher attributes (as defined in gopher+ protocol document)
'

TYPE GOPHER_ADMIN_ATTRIBUTE_TYPEA
    Comment      AS ASCIIZ PTR
    EmailAddress AS ASCIIZ PTR
END TYPE

TYPE GOPHER_ADMIN_ATTRIBUTE_TYPEW
    Comment      AS WSTRINGZ PTR
    EmailAddress AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE GOPHER_ADMIN_ATTRIBUTE_TYPE
    GOPHER_ADMIN_ATTRIBUTE_TYPEW
END TYPE
#ELSE
TYPE GOPHER_ADMIN_ATTRIBUTE_TYPE
    GOPHER_ADMIN_ATTRIBUTE_TYPEA
END TYPE
#ENDIF

TYPE GOPHER_MOD_DATE_ATTRIBUTE_TYPE
    DateAndTime AS FILETIME
END TYPE

TYPE GOPHER_TTL_ATTRIBUTE_TYPE
    Ttl AS DWORD
END TYPE

TYPE GOPHER_SCORE_ATTRIBUTE_TYPE
    Score AS LONG
END TYPE

TYPE GOPHER_SCORE_RANGE_ATTRIBUTE_TYPE
    LowerBound AS LONG
    UpperBound AS LONG
END TYPE

TYPE GOPHER_SITE_ATTRIBUTE_TYPEA
    Site AS ASCIIZ PTR
END TYPE

TYPE GOPHER_SITE_ATTRIBUTE_TYPEW
    Site AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE GOPHER_SITE_ATTRIBUTE_TYPE
    GOPHER_SITE_ATTRIBUTE_TYPEW
END TYPE
#ELSE
TYPE GOPHER_SITE_ATTRIBUTE_TYPE
    GOPHER_SITE_ATTRIBUTE_TYPEA
END TYPE
#ENDIF

TYPE GOPHER_ORGANIZATION_ATTRIBUTE_TYPEA
    Organization AS ASCIIZ PTR
END TYPE

TYPE GOPHER_ORGANIZATION_ATTRIBUTE_TYPEW
    Organization AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE GOPHER_ORGANIZATION_ATTRIBUTE_TYPE
    GOPHER_ORGANIZATION_ATTRIBUTE_TYPEW
END TYPE
#ELSE
TYPE GOPHER_ORGANIZATION_ATTRIBUTE_TYPE
    GOPHER_ORGANIZATION_ATTRIBUTE_TYPEA
END TYPE
#ENDIF

TYPE GOPHER_LOCATION_ATTRIBUTE_TYPEA
    Location AS ASCIIZ PTR
END TYPE

TYPE GOPHER_LOCATION_ATTRIBUTE_TYPEW
    Location AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE GOPHER_LOCATION_ATTRIBUTE_TYPE
    GOPHER_LOCATION_ATTRIBUTE_TYPEW
END TYPE
#ELSE
TYPE GOPHER_LOCATION_ATTRIBUTE_TYPE
    GOPHER_LOCATION_ATTRIBUTE_TYPEA
END TYPE
#ENDIF

TYPE GOPHER_GEOGRAPHICAL_LOCATION_ATTRIBUTE_TYPE
    DegreesNorth AS LONG
    MinutesNorth AS LONG
    SecondsNorth AS LONG
    DegreesEast  AS LONG
    MinutesEast  AS LONG
    SecondsEast  AS LONG
END TYPE

TYPE GOPHER_TIMEZONE_ATTRIBUTE_TYPE
    Zone AS LONG
END TYPE

TYPE GOPHER_PROVIDER_ATTRIBUTE_TYPEA
    Provider AS ASCIIZ PTR
END TYPE

TYPE GOPHER_PROVIDER_ATTRIBUTE_TYPEW
    Provider AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE GOPHER_PROVIDER_ATTRIBUTE_TYPE
    GOPHER_PROVIDER_ATTRIBUTE_TYPEW
END TYPE
#ELSE
TYPE GOPHER_PROVIDER_ATTRIBUTE_TYPE
    GOPHER_PROVIDER_ATTRIBUTE_TYPEA
END TYPE
#ENDIF

TYPE GOPHER_VERSION_ATTRIBUTE_TYPEA
    Version AS ASCIIZ PTR
END TYPE

TYPE GOPHER_VERSION_ATTRIBUTE_TYPEW
    Version AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE GOPHER_VERSION_ATTRIBUTE_TYPE
    GOPHER_VERSION_ATTRIBUTE_TYPEW
END TYPE
#ELSE
TYPE GOPHER_VERSION_ATTRIBUTE_TYPE
    GOPHER_VERSION_ATTRIBUTE_TYPEA
END TYPE
#ENDIF

TYPE GOPHER_ABSTRACT_ATTRIBUTE_TYPEA
    ShortAbstract AS ASCIIZ PTR
    AbstractFile  AS ASCIIZ PTR
END TYPE

TYPE GOPHER_ABSTRACT_ATTRIBUTE_TYPEW
    ShortAbstract AS WSTRINGZ PTR
    AbstractFile  AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE GOPHER_ABSTRACT_ATTRIBUTE_TYPE
    GOPHER_ABSTRACT_ATTRIBUTE_TYPEW
END TYPE
#ELSE
TYPE GOPHER_ABSTRACT_ATTRIBUTE_TYPE
    GOPHER_ABSTRACT_ATTRIBUTE_TYPEA
END TYPE
#ENDIF

TYPE GOPHER_VIEW_ATTRIBUTE_TYPEA
    ContentType AS ASCIIZ PTR
    Language    AS ASCIIZ PTR
    Size        AS DWORD
END TYPE

TYPE GOPHER_VIEW_ATTRIBUTE_TYPEW
    ContentType AS WSTRINGZ PTR
    Language    AS WSTRINGZ PTR
    Size        AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE GOPHER_VIEW_ATTRIBUTE_TYPE
    GOPHER_VIEW_ATTRIBUTE_TYPEW
END TYPE
#ELSE
TYPE GOPHER_VIEW_ATTRIBUTE_TYPE
    GOPHER_VIEW_ATTRIBUTE_TYPEA
END TYPE
#ENDIF

TYPE GOPHER_VERONICA_ATTRIBUTE_TYPE
    TreeWalk AS LONG  ' BOOL
END TYPE

TYPE GOPHER_ASK_ATTRIBUTE_TYPEA
    QuestionType AS ASCIIZ PTR
    QuestionText AS ASCIIZ PTR
END TYPE

TYPE GOPHER_ASK_ATTRIBUTE_TYPEW
    QuestionType AS WSTRINGZ PTR
    QuestionText AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE GOPHER_ASK_ATTRIBUTE_TYPE
    GOPHER_ASK_ATTRIBUTE_TYPEW
END TYPE
#ELSE
TYPE GOPHER_ASK_ATTRIBUTE_TYPE
    GOPHER_ASK_ATTRIBUTE_TYPEA
END TYPE
#ENDIF

'
' GOPHER_UNKNOWN_ATTRIBUTE_TYPE - this is returned if we retrieve an attribute
' that is not specified in the current gopher/gopher+ documentation. It is up
' to the application to parse the information
'

TYPE GOPHER_UNKNOWN_ATTRIBUTE_TYPEA
    Text AS ASCIIZ PTR
END TYPE

TYPE GOPHER_UNKNOWN_ATTRIBUTE_TYPEW
    Text AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE GOPHER_UNKNOWN_ATTRIBUTE_TYPE
    GOPHER_UNKNOWN_ATTRIBUTE_TYPEW
END TYPE
#ELSE
TYPE GOPHER_UNKNOWN_ATTRIBUTE_TYPE
    GOPHER_UNKNOWN_ATTRIBUTE_TYPEA
END TYPE
#ENDIF

' GOPHER_ATTRIBUTE_TYPE - returned in the user's buffer when an enumerated
' GopherGetAttribute call is made
'

UNION GOPHER_ATTRIBUTE_TYPE_UNION
    Admin                AS GOPHER_ADMIN_ATTRIBUTE_TYPE
    ModDate              AS GOPHER_MOD_DATE_ATTRIBUTE_TYPE
    Ttl                  AS GOPHER_TTL_ATTRIBUTE_TYPE
    Score                AS GOPHER_SCORE_ATTRIBUTE_TYPE
    ScoreRange           AS GOPHER_SCORE_RANGE_ATTRIBUTE_TYPE
    Site                 AS GOPHER_SITE_ATTRIBUTE_TYPE
    Organization         AS GOPHER_ORGANIZATION_ATTRIBUTE_TYPE
    Location             AS GOPHER_LOCATION_ATTRIBUTE_TYPE
    GeographicalLocation AS GOPHER_GEOGRAPHICAL_LOCATION_ATTRIBUTE_TYPE
    TimeZone             AS GOPHER_TIMEZONE_ATTRIBUTE_TYPE
    Provider             AS GOPHER_PROVIDER_ATTRIBUTE_TYPE
    Version              AS GOPHER_VERSION_ATTRIBUTE_TYPE
    Abstract             AS GOPHER_ABSTRACT_ATTRIBUTE_TYPE
    View                 AS GOPHER_VIEW_ATTRIBUTE_TYPE
    Veronica             AS GOPHER_VERONICA_ATTRIBUTE_TYPE
    Ask                  AS GOPHER_ASK_ATTRIBUTE_TYPE
    Unknown              AS GOPHER_UNKNOWN_ATTRIBUTE_TYPE
END UNION

TYPE GOPHER_ATTRIBUTE_TYPE DWORD FILL
    CategoryId    AS DWORD   ' e.g. %GOPHER_CATEGORY_ID_ADMIN
    AttributeId   AS DWORD   ' e.g. %GOPHER_ATTRIBUTE_ID_ADMIN
    AttributeType AS GOPHER_ATTRIBUTE_TYPE_UNION
END TYPE

%MAX_GOPHER_CATEGORY_NAME    = 128     ' arbitrary
%MAX_GOPHER_ATTRIBUTE_NAME   = 128     '     "
%MIN_GOPHER_ATTRIBUTE_LENGTH = 256     '     "

'
' known gopher attribute categories. See below for ordinals
'

$GOPHER_INFO_CATEGORY        = "+INFO"
$GOPHER_ADMIN_CATEGORY       = "+ADMIN"
$GOPHER_VIEWS_CATEGORY       = "+VIEWS"
$GOPHER_ABSTRACT_CATEGORY    = "+ABSTRACT"
$GOPHER_VERONICA_CATEGORY    = "+VERONICA"

$$GOPHER_INFO_CATEGORY        = "+INFO"$$
$$GOPHER_ADMIN_CATEGORY       = "+ADMIN"$$
$$GOPHER_VIEWS_CATEGORY       = "+VIEWS"$$
$$GOPHER_ABSTRACT_CATEGORY    = "+ABSTRACT"$$
$$GOPHER_VERONICA_CATEGORY    = "+VERONICA"$$

'
' known gopher attributes. These are the attribute names as defined in the
' gopher+ protocol document
'

$GOPHER_ADMIN_ATTRIBUTE      = "Admin"
$GOPHER_MOD_DATE_ATTRIBUTE   = "Mod-Date"
$GOPHER_TTL_ATTRIBUTE        = "TTL"
$GOPHER_SCORE_ATTRIBUTE      = "Score"
$GOPHER_RANGE_ATTRIBUTE      = "Score-range"
$GOPHER_SITE_ATTRIBUTE       = "Site"
$GOPHER_ORG_ATTRIBUTE        = "Org"
$GOPHER_LOCATION_ATTRIBUTE   = "Loc"
$GOPHER_GEOG_ATTRIBUTE       = "Geog"
$GOPHER_TIMEZONE_ATTRIBUTE   = "TZ"
$GOPHER_PROVIDER_ATTRIBUTE   = "Provider"
$GOPHER_VERSION_ATTRIBUTE    = "Version"
$GOPHER_ABSTRACT_ATTRIBUTE   = "Abstract"
$GOPHER_VIEW_ATTRIBUTE       = "View"
$GOPHER_TREEWALK_ATTRIBUTE   = "treewalk"

$$GOPHER_ADMIN_ATTRIBUTE      = "Admin"$$
$$GOPHER_MOD_DATE_ATTRIBUTE   = "Mod-Date"$$
$$GOPHER_TTL_ATTRIBUTE        = "TTL"$$
$$GOPHER_SCORE_ATTRIBUTE      = "Score"$$
$$GOPHER_RANGE_ATTRIBUTE      = "Score-range"$$
$$GOPHER_SITE_ATTRIBUTE       = "Site"$$
$$GOPHER_ORG_ATTRIBUTE        = "Org"$$
$$GOPHER_LOCATION_ATTRIBUTE   = "Loc"$$
$$GOPHER_GEOG_ATTRIBUTE       = "Geog"$$
$$GOPHER_TIMEZONE_ATTRIBUTE   = "TZ"$$
$$GOPHER_PROVIDER_ATTRIBUTE   = "Provider"$$
$$GOPHER_VERSION_ATTRIBUTE    = "Version"$$
$$GOPHER_ABSTRACT_ATTRIBUTE   = "Abstract"$$
$$GOPHER_VIEW_ATTRIBUTE       = "View"$$
$$GOPHER_TREEWALK_ATTRIBUTE   = "treewalk"$$

'
' identifiers for attribute strings
'

%GOPHER_ATTRIBUTE_ID_BASE     = &Habcccc00???

%GOPHER_CATEGORY_ID_ALL       = %GOPHER_ATTRIBUTE_ID_BASE + 1

%GOPHER_CATEGORY_ID_INFO      = %GOPHER_ATTRIBUTE_ID_BASE + 2
%GOPHER_CATEGORY_ID_ADMIN     = %GOPHER_ATTRIBUTE_ID_BASE + 3
%GOPHER_CATEGORY_ID_VIEWS     = %GOPHER_ATTRIBUTE_ID_BASE + 4
%GOPHER_CATEGORY_ID_ABSTRACT  = %GOPHER_ATTRIBUTE_ID_BASE + 5
%GOPHER_CATEGORY_ID_VERONICA  = %GOPHER_ATTRIBUTE_ID_BASE + 6
%GOPHER_CATEGORY_ID_ASK       = %GOPHER_ATTRIBUTE_ID_BASE + 7

%GOPHER_CATEGORY_ID_UNKNOWN   = %GOPHER_ATTRIBUTE_ID_BASE + 8

%GOPHER_ATTRIBUTE_ID_ALL      = %GOPHER_ATTRIBUTE_ID_BASE + 9

%GOPHER_ATTRIBUTE_ID_ADMIN    = %GOPHER_ATTRIBUTE_ID_BASE + 10
%GOPHER_ATTRIBUTE_ID_MOD_DATE = %GOPHER_ATTRIBUTE_ID_BASE + 11
%GOPHER_ATTRIBUTE_ID_TTL      = %GOPHER_ATTRIBUTE_ID_BASE + 12
%GOPHER_ATTRIBUTE_ID_SCORE    = %GOPHER_ATTRIBUTE_ID_BASE + 13
%GOPHER_ATTRIBUTE_ID_RANGE    = %GOPHER_ATTRIBUTE_ID_BASE + 14
%GOPHER_ATTRIBUTE_ID_SITE     = %GOPHER_ATTRIBUTE_ID_BASE + 15
%GOPHER_ATTRIBUTE_ID_ORG      = %GOPHER_ATTRIBUTE_ID_BASE + 16
%GOPHER_ATTRIBUTE_ID_LOCATION = %GOPHER_ATTRIBUTE_ID_BASE + 17
%GOPHER_ATTRIBUTE_ID_GEOG     = %GOPHER_ATTRIBUTE_ID_BASE + 18
%GOPHER_ATTRIBUTE_ID_TIMEZONE = %GOPHER_ATTRIBUTE_ID_BASE + 19
%GOPHER_ATTRIBUTE_ID_PROVIDER = %GOPHER_ATTRIBUTE_ID_BASE + 20
%GOPHER_ATTRIBUTE_ID_VERSION  = %GOPHER_ATTRIBUTE_ID_BASE + 21
%GOPHER_ATTRIBUTE_ID_ABSTRACT = %GOPHER_ATTRIBUTE_ID_BASE + 22
%GOPHER_ATTRIBUTE_ID_VIEW     = %GOPHER_ATTRIBUTE_ID_BASE + 23
%GOPHER_ATTRIBUTE_ID_TREEWALK = %GOPHER_ATTRIBUTE_ID_BASE + 24

%GOPHER_ATTRIBUTE_ID_UNKNOWN  = %GOPHER_ATTRIBUTE_ID_BASE + 25

'
' prototypes
'

DECLARE FUNCTION GopherCreateLocatorA LIB "WinINet.dll" _
   ALIAS "GopherCreateLocatorA" _
   ( _
    lpszHost AS ASCIIZ, _                   ' in
    BYVAL nServerPost AS WORD, _            ' in
    lpszDisplayString AS ASCIIZ, _          ' in
    lpszSelectorString AS ASCIIZ, _         ' in
    BYVAL dwGopherType AS DWORD, _          ' in
    lpszLocator AS ASCIIZ, _                ' out
    lpdwBufferLength AS DWORD _             ' in, out
   ) _
   AS LONG

DECLARE FUNCTION GopherCreateLocatorW LIB "WinINet.dll" _
   ALIAS "GopherCreateLocatorW" _
   ( _
    lpszHost AS WSTRINGZ, _                 ' in
    BYVAL nServerPost AS WORD, _            ' in
    lpszDisplayString AS WSTRINGZ, _        ' in
    lpszSelectorString AS WSTRINGZ, _       ' in
    BYVAL dwGopherType AS DWORD, _          ' in
    lpszLocator AS WSTRINGZ, _              ' out
    lpdwBufferLength AS DWORD _             ' in, out
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GopherCreateLocator LIB "WinINet.dll" _
   ALIAS "GopherCreateLocatorW" _
   ( _
    lpszHost AS WSTRINGZ, _                 ' in
    BYVAL nServerPost AS WORD, _            ' in
    lpszDisplayString AS WSTRINGZ, _        ' in
    lpszSelectorString AS WSTRINGZ, _       ' in
    BYVAL dwGopherType AS DWORD, _          ' in
    lpszLocator AS WSTRINGZ, _              ' out
    lpdwBufferLength AS DWORD _             ' in, out
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION GopherCreateLocator LIB "WinINet.dll" _
   ALIAS "GopherCreateLocatorA" _
   ( _
    lpszHost AS ASCIIZ, _                   ' in
    BYVAL nServerPost AS WORD, _            ' in
    lpszDisplayString AS ASCIIZ, _          ' in
    lpszSelectorString AS ASCIIZ, _         ' in
    BYVAL dwGopherType AS DWORD, _          ' in
    lpszLocator AS ASCIIZ, _                ' out
    lpdwBufferLength AS DWORD _             ' in, out
   ) _
   AS LONG
#ENDIF

DECLARE FUNCTION GopherGetLocatorTypeA LIB "WinINet.dll" _
   ALIAS "GopherGetLocatorTypeA" _
   ( _
    lpszLocator AS ASCIIZ, _                ' in
    lpdwGopherType AS DWORD _               ' out
   ) _
   AS LONG

DECLARE FUNCTION GopherGetLocatorTypeW LIB "WinINet.dll" _
   ALIAS "GopherGetLocatorTypeW" _
   ( _
    lpszLocator AS WSTRINGZ, _              ' in
    lpdwGopherType AS DWORD _               ' out
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GopherGetLocatorType LIB "WinINet.dll" _
   ALIAS "GopherGetLocatorTypeW" _
   ( _
    lpszLocator AS WSTRINGZ, _              ' in
    lpdwGopherType AS DWORD _               ' out
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION GopherGetLocatorType LIB "WinINet.dll" _
   ALIAS "GopherGetLocatorTypeA" _
   ( _
    lpszLocator AS ASCIIZ, _                ' in
    lpdwGopherType AS DWORD _               ' out
   ) _
   AS LONG
#ENDIF

DECLARE FUNCTION GopherFindFirstFileA LIB "WinINet.dll" _
   ALIAS "GopherFindFirstFileA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszLocator AS ASCIIZ, _                ' in
    lpszSearchString AS ASCIIZ, _           ' in
    lpFindData AS GOPHER_FIND_DATA, _       ' out
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS DWORD

DECLARE FUNCTION GopherFindFirstFileW LIB "WinINet.dll" _
   ALIAS "GopherFindFirstFileW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszLocator AS WSTRINGZ, _              ' in
    lpszSearchString AS WSTRINGZ, _         ' in
    lpFindData AS GOPHER_FIND_DATA, _       ' out
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GopherFindFirstFile LIB "WinINet.dll" _
   ALIAS "GopherFindFirstFileW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszLocator AS WSTRINGZ, _              ' in
    lpszSearchString AS WSTRINGZ, _         ' in
    lpFindData AS GOPHER_FIND_DATA, _       ' out
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS DWORD
#ELSE
DECLARE FUNCTION GopherFindFirstFile LIB "WinINet.dll" _
   ALIAS "GopherFindFirstFileA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszLocator AS ASCIIZ, _                ' in
    lpszSearchString AS ASCIIZ, _           ' in
    lpFindData AS GOPHER_FIND_DATA, _       ' out
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS DWORD
#ENDIF

DECLARE FUNCTION GopherOpenFileA LIB "WinINet.dll" ALIAS "GopherOpenFileA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszLocator AS ASCIIZ, _                ' in
    lpszView AS ASCIIZ, _                   ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS DWORD

DECLARE FUNCTION GopherOpenFileW LIB "WinINet.dll" ALIAS "GopherOpenFileW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszLocator AS WSTRINGZ, _              ' in
    lpszView AS WSTRINGZ, _                 ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GopherOpenFile LIB "WinINet.dll" ALIAS "GopherOpenFileW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszLocator AS WSTRINGZ, _              ' in
    lpszView AS WSTRINGZ, _                 ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS DWORD
#ELSE
DECLARE FUNCTION GopherOpenFile LIB "WinINet.dll" ALIAS "GopherOpenFileA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszLocator AS ASCIIZ, _                ' in
    lpszView AS ASCIIZ, _                   ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS DWORD
#ENDIF

'DECLARE FUNCTION GOPHER_ATTRIBUTE_ENUMERATOR ( _
'    lpAttributeInfo AS GOPHER_ATTRIBUTE_TYPE, _
'    BYVAL dwError   AS DWORD _
'    ) AS LONG  ' BOOL

DECLARE FUNCTION GopherGetAttributeA LIB "WinINet.dll" _
   ALIAS "GopherGetAttributeA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszLocator AS ASCIIZ, _                ' in
    lpszAttributeName AS ASCIIZ, _          ' in
    BYVAL lpBuffer AS BYTE PTR, _           ' out
    BYVAL dwBufferLength AS DWORD, _        ' in
    lpdwCharactersReturned AS DWORD, _      ' out
    BYVAL lpfnEnumerator AS DWORD, _        ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS LONG

DECLARE FUNCTION GopherGetAttributeW LIB "WinINet.dll" _
   ALIAS "GopherGetAttributeW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszLocator AS WSTRINGZ, _              ' in
    lpszAttributeName AS WSTRINGZ, _        ' in
    BYVAL lpBuffer AS BYTE PTR, _           ' out
    BYVAL dwBufferLength AS DWORD, _        ' in
    lpdwCharactersReturned AS DWORD, _      ' out
    BYVAL lpfnEnumerator AS DWORD, _        ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GopherGetAttribute LIB "WinINet.dll" _
   ALIAS "GopherGetAttributeW" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszLocator AS WSTRINGZ, _              ' in
    lpszAttributeName AS WSTRINGZ, _        ' in
    BYVAL lpBuffer AS BYTE PTR, _           ' out
    BYVAL dwBufferLength AS DWORD, _        ' in
    lpdwCharactersReturned AS DWORD, _      ' out
    BYVAL lpfnEnumerator AS DWORD, _        ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS LONG
#ELSE
DECLARE FUNCTION GopherGetAttribute LIB "WinINet.dll" _
   ALIAS "GopherGetAttributeA" _
   ( _
    BYVAL hConnect AS DWORD, _              ' in
    lpszLocator AS ASCIIZ, _                ' in
    lpszAttributeName AS ASCIIZ, _          ' in
    BYVAL lpBuffer AS BYTE PTR, _           ' out
    BYVAL dwBufferLength AS DWORD, _        ' in
    lpdwCharactersReturned AS DWORD, _      ' out
    BYVAL lpfnEnumerator AS DWORD, _        ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS LONG
#ENDIF

'
' HTTP
'

'
' manifests
'

'
' the default major/minor HTTP version numbers
'

%HTTP_MAJOR_VERSION      = 1
%HTTP_MINOR_VERSION      = 0

$HTTP_VERSIONA           = "HTTP/1.0"
$HTTP_VERSION            = "HTTP/1.0"
$$HTTP_VERSIONW          = "HTTP/1.0"$$
$$HTTP_VERSION           = "HTTP/1.0"$$

'
' HttpQueryInfo info levels. Generally, there is one info level
' for each potential RFC822/HTTP/MIME header that an HTTP server
' may send as part of a request response.
'
' The HTTP_QUERY_RAW_HEADERS info level is provided for clients
' that choose to perform their own header parsing.
'

%HTTP_QUERY_MIME_VERSION              = 0
%HTTP_QUERY_CONTENT_TYPE              = 1
%HTTP_QUERY_CONTENT_TRANSFER_ENCODING = 2
%HTTP_QUERY_CONTENT_ID                = 3
%HTTP_QUERY_CONTENT_DESCRIPTION       = 4
%HTTP_QUERY_CONTENT_LENGTH            = 5
%HTTP_QUERY_CONTENT_LANGUAGE          = 6
%HTTP_QUERY_ALLOW                     = 7
%HTTP_QUERY_PUBLIC                    = 8
%HTTP_QUERY_DATE                      = 9
%HTTP_QUERY_EXPIRES                   = 10
%HTTP_QUERY_LAST_MODIFIED             = 11
%HTTP_QUERY_MESSAGE_ID                = 12
%HTTP_QUERY_URI                       = 13
%HTTP_QUERY_DERIVED_FROM              = 14
%HTTP_QUERY_COST                      = 15
%HTTP_QUERY_LINK                      = 16
%HTTP_QUERY_PRAGMA                    = 17
%HTTP_QUERY_VERSION                   = 18  ' special: part of status line
%HTTP_QUERY_STATUS_CODE               = 19  ' special: part of status line
%HTTP_QUERY_STATUS_TEXT               = 20  ' special: part of status line
%HTTP_QUERY_RAW_HEADERS               = 21  ' special: all headers as ASCIIZ
%HTTP_QUERY_RAW_HEADERS_CRLF          = 22  ' special: all headers
%HTTP_QUERY_CONNECTION                = 23
%HTTP_QUERY_ACCEPT                    = 24
%HTTP_QUERY_ACCEPT_CHARSET            = 25
%HTTP_QUERY_ACCEPT_ENCODING           = 26
%HTTP_QUERY_ACCEPT_LANGUAGE           = 27
%HTTP_QUERY_AUTHORIZATION             = 28
%HTTP_QUERY_CONTENT_ENCODING          = 29
%HTTP_QUERY_FORWARDED                 = 30
%HTTP_QUERY_FROM                      = 31
%HTTP_QUERY_IF_MODIFIED_SINCE         = 32
%HTTP_QUERY_LOCATION                  = 33
%HTTP_QUERY_ORIG_URI                  = 34
%HTTP_QUERY_REFERER                   = 35
%HTTP_QUERY_RETRY_AFTER               = 36
%HTTP_QUERY_SERVER                    = 37
%HTTP_QUERY_TITLE                     = 38
%HTTP_QUERY_USER_AGENT                = 39
%HTTP_QUERY_WWW_AUTHENTICATE          = 40
%HTTP_QUERY_PROXY_AUTHENTICATE        = 41
%HTTP_QUERY_ACCEPT_RANGES             = 42
%HTTP_QUERY_SET_COOKIE                = 43
%HTTP_QUERY_COOKIE                    = 44
%HTTP_QUERY_REQUEST_METHOD            = 45  ' special: GET/POST etc.
%HTTP_QUERY_REFRESH                   = 46
%HTTP_QUERY_CONTENT_DISPOSITION       = 47

'
' HTTP 1.1 defined headers
'

%HTTP_QUERY_AGE                       = 48
%HTTP_QUERY_CACHE_CONTROL             = 49
%HTTP_QUERY_CONTENT_BASE              = 50
%HTTP_QUERY_CONTENT_LOCATION          = 51
%HTTP_QUERY_CONTENT_MD5               = 52
%HTTP_QUERY_CONTENT_RANGE             = 53
%HTTP_QUERY_ETAG                      = 54
%HTTP_QUERY_HOST                      = 55
%HTTP_QUERY_IF_MATCH                  = 56
%HTTP_QUERY_IF_NONE_MATCH             = 57
%HTTP_QUERY_IF_RANGE                  = 58
%HTTP_QUERY_IF_UNMODIFIED_SINCE       = 59
%HTTP_QUERY_MAX_FORWARDS              = 60
%HTTP_QUERY_PROXY_AUTHORIZATION       = 61
%HTTP_QUERY_RANGE                     = 62
%HTTP_QUERY_TRANSFER_ENCODING         = 63
%HTTP_QUERY_UPGRADE                   = 64
%HTTP_QUERY_VARY                      = 65
%HTTP_QUERY_VIA                       = 66
%HTTP_QUERY_WARNING                   = 67
%HTTP_QUERY_EXPECT                    = 68
%HTTP_QUERY_PROXY_CONNECTION          = 69
%HTTP_QUERY_UNLESS_MODIFIED_SINCE     = 70

%HTTP_QUERY_ECHO_REQUEST              = 71
%HTTP_QUERY_ECHO_REPLY                = 72

' These are the set of headers that should be added back to a request when
' re-doing a request after a RETRY_WITH response.
%HTTP_QUERY_ECHO_HEADERS              = 73
%HTTP_QUERY_ECHO_HEADERS_CRLF         = 74

%HTTP_QUERY_PROXY_SUPPORT             = 75
%HTTP_QUERY_AUTHENTICATION_INFO       = 76
%HTTP_QUERY_PASSPORT_URLS             = 77
%HTTP_QUERY_PASSPORT_CONFIG           = 78

%HTTP_QUERY_MAX                       = 78

'
' HTTP_QUERY_CUSTOM - if this special value is supplied as the dwInfoLevel
' parameter of HttpQueryInfo() then the lpBuffer parameter contains the name
' of the header we are to query
'

%HTTP_QUERY_CUSTOM                    = 65535

'
' HTTP_QUERY_FLAG_REQUEST_HEADERS - if this bit is set in the dwInfoLevel
' parameter of HttpQueryInfo() then the request headers will be queried for the
' request information
'

%HTTP_QUERY_FLAG_REQUEST_HEADERS      = &H80000000???

'
' HTTP_QUERY_FLAG_SYSTEMTIME - if this bit is set in the dwInfoLevel parameter
' of HttpQueryInfo() AND the header being queried contains date information,
' e.g. the "Expires:" header then lpBuffer will contain a SYSTEMTIME structure
' containing the date and time information converted from the header string
'

%HTTP_QUERY_FLAG_SYSTEMTIME           = &H40000000

'
' HTTP_QUERY_FLAG_NUMBER - if this bit is set in the dwInfoLevel parameter of
' HttpQueryInfo(), then the value of the header will be converted to a 32-bit
' number before being returned to the caller, if applicable
'

%HTTP_QUERY_FLAG_NUMBER               = &H20000000

'
' HTTP_QUERY_FLAG_COALESCE - combine the values from several headers of the
' same name into the output buffer
'

%HTTP_QUERY_FLAG_COALESCE             = &H10000000

'
' HTTP_QUERY_FLAG_NUMBER64 - if this bit is set in the dwInfoLevel parameter of
' HttpQueryInfo(), then the value of the header will be converted to a 64bit
' number before being returned to the caller, if applicable
'

%HTTP_QUERY_FLAG_NUMBER64             = &H08000000

%HTTP_QUERY_MODIFIER_FLAGS_MASK       = %HTTP_QUERY_FLAG_REQUEST_HEADERS _
                                      OR %HTTP_QUERY_FLAG_SYSTEMTIME     _
                                      OR %HTTP_QUERY_FLAG_NUMBER         _
                                      OR %HTTP_QUERY_FLAG_COALESCE       _
                                      OR %HTTP_QUERY_FLAG_NUMBER64

%HTTP_QUERY_HEADER_MASK               = NOT %HTTP_QUERY_MODIFIER_FLAGS_MASK

'
' HTTP Response Status Codes:
'

%HTTP_STATUS_CONTINUE           = 100 ' OK to continue with request
%HTTP_STATUS_SWITCH_PROTOCOLS   = 101 ' server has switched protocols in upgrade header

%HTTP_STATUS_OK                 = 200 ' request completed
%HTTP_STATUS_CREATED            = 201 ' object created, reason = new URI
%HTTP_STATUS_ACCEPTED           = 202 ' async completion (TBS)
%HTTP_STATUS_PARTIAL            = 203 ' partial completion
%HTTP_STATUS_NO_CONTENT         = 204 ' no info to return
%HTTP_STATUS_RESET_CONTENT      = 205 ' request completed, but clear form
%HTTP_STATUS_PARTIAL_CONTENT    = 206 ' partial GET furfilled

%HTTP_STATUS_AMBIGUOUS          = 300 ' server couldn't decide what to return
%HTTP_STATUS_MOVED              = 301 ' object permanently moved
%HTTP_STATUS_REDIRECT           = 302 ' object temporarily moved
%HTTP_STATUS_REDIRECT_METHOD    = 303 ' redirection w/ new access method
%HTTP_STATUS_NOT_MODIFIED       = 304 ' if-modified-since was not modified
%HTTP_STATUS_USE_PROXY          = 305 ' redirection to proxy, location header specifies proxy to use
%HTTP_STATUS_REDIRECT_KEEP_VERB = 307 ' HTTP/1.1: keep same verb

%HTTP_STATUS_BAD_REQUEST        = 400 ' invalid syntax
%HTTP_STATUS_DENIED             = 401 ' access denied
%HTTP_STATUS_PAYMENT_REQ        = 402 ' payment required
%HTTP_STATUS_FORBIDDEN          = 403 ' request forbidden
%HTTP_STATUS_NOT_FOUND          = 404 ' object not found
%HTTP_STATUS_BAD_METHOD         = 405 ' method is not allowed
%HTTP_STATUS_NONE_ACCEPTABLE    = 406 ' no response acceptable to client found
%HTTP_STATUS_PROXY_AUTH_REQ     = 407 ' proxy authentication required
%HTTP_STATUS_REQUEST_TIMEOUT    = 408 ' server timed out waiting for request
%HTTP_STATUS_CONFLICT           = 409 ' user should resubmit with more info
%HTTP_STATUS_GONE               = 410 ' the resource is no longer available
%HTTP_STATUS_LENGTH_REQUIRED    = 411 ' the server refused to accept request w/o a length
%HTTP_STATUS_PRECOND_FAILED     = 412 ' precondition given in request failed
%HTTP_STATUS_REQUEST_TOO_LARGE  = 413 ' request entity was too large
%HTTP_STATUS_URI_TOO_LONG       = 414 ' request URI too long
%HTTP_STATUS_UNSUPPORTED_MEDIA  = 415 ' unsupported media type
%HTTP_STATUS_RETRY_WITH         = 449 ' retry after doing the appropriate action.

%HTTP_STATUS_SERVER_ERROR       = 500 ' internal server error
%HTTP_STATUS_NOT_SUPPORTED      = 501 ' required not supported
%HTTP_STATUS_BAD_GATEWAY        = 502 ' error response received from gateway
%HTTP_STATUS_SERVICE_UNAVAIL    = 503 ' temporarily overloaded
%HTTP_STATUS_GATEWAY_TIMEOUT    = 504 ' timed out waiting for gateway
%HTTP_STATUS_VERSION_NOT_SUP    = 505 ' HTTP version not supported

%HTTP_STATUS_FIRST              = %HTTP_STATUS_CONTINUE
%HTTP_STATUS_LAST               = %HTTP_STATUS_VERSION_NOT_SUP

'
' prototypes
'

DECLARE FUNCTION HttpOpenRequestA LIB "WinINet.dll" _
   ALIAS "HttpOpenRequestA" _
   ( _
    BYVAL hConnect    AS DWORD, _             ' in
    lpszVerb          AS ASCIIZ, _            ' in
    lpszObjectName    AS ASCIIZ, _            ' in
    lpszVersion       AS ASCIIZ, _            ' in
    lpszReferrer      AS ASCIIZ, _            ' in
    lplpszAcceptTypes AS ANY, _               ' in (ptr to an AsciiZZ list)
    BYVAL dwFlags     AS DWORD, _             ' in
    BYVAL dwContext   AS DWORD _              ' in
   ) AS DWORD

DECLARE FUNCTION HttpOpenRequestW LIB "WinINet.dll" _
   ALIAS "HttpOpenRequestW" _
   ( _
    BYVAL hConnect    AS DWORD, _             ' in
    lpszVerb          AS WSTRINGZ, _          ' in
    lpszObjectName    AS WSTRINGZ, _          ' in
    lpszVersion       AS WSTRINGZ, _          ' in
    lpszReferrer      AS WSTRINGZ, _          ' in
    lplpszAcceptTypes AS ANY, _               ' in (ptr to an WSTRINGZZ list)
    BYVAL dwFlags     AS DWORD, _             ' in
    BYVAL dwContext   AS DWORD _              ' in
   ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION HttpOpenRequest LIB "WinINet.dll" _
   ALIAS "HttpOpenRequestW" _
   ( _
    BYVAL hConnect    AS DWORD, _             ' in
    lpszVerb          AS WSTRINGZ, _          ' in
    lpszObjectName    AS WSTRINGZ, _          ' in
    lpszVersion       AS WSTRINGZ, _          ' in
    lpszReferrer      AS WSTRINGZ, _          ' in
    lplpszAcceptTypes AS ANY, _               ' in (ptr to an WSTRINGZZ list)
    BYVAL dwFlags     AS DWORD, _             ' in
    BYVAL dwContext   AS DWORD _              ' in
   ) AS DWORD
#ELSE
DECLARE FUNCTION HttpOpenRequest LIB "WinINet.dll" _
   ALIAS "HttpOpenRequestA" _
   ( _
    BYVAL hConnect    AS DWORD, _             ' in
    lpszVerb          AS ASCIIZ, _            ' in
    lpszObjectName    AS ASCIIZ, _            ' in
    lpszVersion       AS ASCIIZ, _            ' in
    lpszReferrer      AS ASCIIZ, _            ' in
    lplpszAcceptTypes AS ANY, _               ' in (ptr to an AsciiZZ list)
    BYVAL dwFlags     AS DWORD, _             ' in
    BYVAL dwContext   AS DWORD _              ' in
   ) AS DWORD
#ENDIF

DECLARE FUNCTION HttpAddRequestHeadersA LIB "WinINet.dll" _
   ALIAS "HttpAddRequestHeadersA" _
   ( _
    BYVAL hRequest        AS DWORD, _       ' in
    lpszHeaders           AS ASCIIZ, _      ' in
    BYVAL dwHeadersLength AS DWORD, _       ' in
    BYVAL dwModifiers     AS DWORD _        ' in
   ) AS LONG

DECLARE FUNCTION HttpAddRequestHeadersW LIB "WinINet.dll" _
   ALIAS "HttpAddRequestHeadersW" _
   ( _
    BYVAL hRequest        AS DWORD, _       ' in
    lpszHeaders           AS WSTRINGZ, _    ' in
    BYVAL dwHeadersLength AS DWORD, _       ' in
    BYVAL dwModifiers     AS DWORD _        ' in
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION HttpAddRequestHeaders LIB "WinINet.dll" _
   ALIAS "HttpAddRequestHeadersW" _
   ( _
    BYVAL hRequest        AS DWORD, _       ' in
    lpszHeaders           AS WSTRINGZ, _    ' in
    BYVAL dwHeadersLength AS DWORD, _       ' in
    BYVAL dwModifiers     AS DWORD _        ' in
   ) AS LONG
#ELSE
DECLARE FUNCTION HttpAddRequestHeaders LIB "WinINet.dll" _
   ALIAS "HttpAddRequestHeadersA" _
   ( _
    BYVAL hRequest        AS DWORD, _       ' in
    lpszHeaders           AS ASCIIZ, _      ' in
    BYVAL dwHeadersLength AS DWORD, _       ' in
    BYVAL dwModifiers     AS DWORD _        ' in
   ) AS LONG
#ENDIF

'
' values for dwModifiers parameter of HttpAddRequestHeaders()
'

%HTTP_ADDREQ_INDEX_MASK      = &H0000FFFF???
%HTTP_ADDREQ_FLAGS_MASK      = &HFFFF0000???

'
' HTTP_ADDREQ_FLAG_ADD_IF_NEW - the header will only be added if it doesn't
' already exist
'

%HTTP_ADDREQ_FLAG_ADD_IF_NEW = &H10000000

'
' HTTP_ADDREQ_FLAG_ADD - if HTTP_ADDREQ_FLAG_REPLACE is set but the header is
' not found then if this flag is set, the header is added anyway, so long as
' there is a valid header-value
'

%HTTP_ADDREQ_FLAG_ADD        = &H20000000

'
' HTTP_ADDREQ_FLAG_COALESCE - coalesce headers with same name. e.g.
' "Accept: text/*" and "Accept: audio/*" with this flag results in a single
' header: "Accept: text/*, audio/*"
'

%HTTP_ADDREQ_FLAG_COALESCE_WITH_COMMA     = &H40000000
%HTTP_ADDREQ_FLAG_COALESCE_WITH_SEMICOLON = &H01000000
%HTTP_ADDREQ_FLAG_COALESCE                = %HTTP_ADDREQ_FLAG_COALESCE_WITH_COMMA

'
' HTTP_ADDREQ_FLAG_REPLACE - replaces the specified header. Only one header can
' be supplied in the buffer. If the header to be replaced is not the first
' in a list of headers with the same name, then the relative index should be
' supplied in the low 8 bits of the dwModifiers parameter. If the header-value
' part is missing, then the header is removed
'

%HTTP_ADDREQ_FLAG_REPLACE    = &H80000000???

DECLARE FUNCTION HttpSendRequestA LIB "WinINet.dll" ALIAS "HttpSendRequestA" _
   ( _
    BYVAL hRequest AS DWORD, _              ' in
    lpszHeaders AS ASCIIZ, _                ' in
    BYVAL dwHeadersLength AS DWORD, _       ' in
    BYVAL lpOptional AS BYTE PTR, _         ' in
    BYVAL dwOptionalLength AS DWORD _       ' in
   ) AS LONG

DECLARE FUNCTION HttpSendRequestW LIB "WinINet.dll" ALIAS "HttpSendRequestW" _
   ( _
    BYVAL hRequest AS DWORD, _              ' in
    lpszHeaders AS WSTRINGZ, _              ' in
    BYVAL dwHeadersLength AS DWORD, _       ' in
    BYVAL lpOptional AS BYTE PTR, _         ' in
    BYVAL dwOptionalLength AS DWORD _       ' in
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION HttpSendRequest LIB "WinINet.dll" ALIAS "HttpSendRequestW" _
   ( _
    BYVAL hRequest AS DWORD, _              ' in
    lpszHeaders AS WSTRINGZ, _              ' in
    BYVAL dwHeadersLength AS DWORD, _       ' in
    BYVAL lpOptional AS BYTE PTR, _         ' in
    BYVAL dwOptionalLength AS DWORD _       ' in
   ) AS LONG
#ELSE
DECLARE FUNCTION HttpSendRequest LIB "WinINet.dll" ALIAS "HttpSendRequestA" _
   ( _
    BYVAL hRequest AS DWORD, _              ' in
    lpszHeaders AS ASCIIZ, _                ' in
    BYVAL dwHeadersLength AS DWORD, _       ' in
    BYVAL lpOptional AS BYTE PTR, _         ' in
    BYVAL dwOptionalLength AS DWORD _       ' in
   ) AS LONG
#ENDIF

DECLARE FUNCTION HttpSendRequestExA LIB "WinINet.dll" _
   ALIAS "HttpSendRequestExA" _
   ( _
    BYVAL hRequest AS DWORD, _              ' in
    lpBuffersIn AS INTERNET_BUFFERSA, _     ' in
    lpBuffersOut AS INTERNET_BUFFERSA, _    ' out
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS LONG

DECLARE FUNCTION HttpSendRequestExW LIB "WinINet.dll" _
   ALIAS "HttpSendRequestExW" _
   ( _
    BYVAL hRequest AS DWORD, _              ' in
    lpBuffersIn AS INTERNET_BUFFERSW, _     ' in
    lpBuffersOut AS INTERNET_BUFFERSW, _    ' out
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION HttpSendRequestEx LIB "WinINet.dll" _
   ALIAS "HttpSendRequestExW" _
   ( _
    BYVAL hRequest AS DWORD, _              ' in
    lpBuffersIn AS INTERNET_BUFFERSW, _     ' in
    lpBuffersOut AS INTERNET_BUFFERSW, _    ' out
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS LONG
#ELSE
DECLARE FUNCTION HttpSendRequestEx LIB "WinINet.dll" _
   ALIAS "HttpSendRequestExA" _
   ( _
    BYVAL hRequest AS DWORD, _              ' in
    lpBuffersIn AS INTERNET_BUFFERSA, _     ' in
    lpBuffersOut AS INTERNET_BUFFERSA, _    ' out
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS LONG
#ENDIF

'
' flags for HttpSendRequestEx(), HttpEndRequest()
'

%HSR_ASYNC       = %WININET_API_FLAG_ASYNC         ' force async
%HSR_SYNC        = %WININET_API_FLAG_SYNC          ' force sync
%HSR_USE_CONTEXT = %WININET_API_FLAG_USE_CONTEXT   ' use dwContext value
%HSR_INITIATE    = &H00000008                      ' iterative operation (completed by HttpEndRequest)
%HSR_DOWNLOAD    = &H00000010                      ' download to file
%HSR_CHUNKED     = &H00000020                      ' operation is send of chunked data

DECLARE FUNCTION HttpEndRequestA LIB "WinINet.dll" ALIAS "HttpEndRequestA" _
   ( _
    BYVAL hRequest AS DWORD, _              ' in
    lpBuffersOut AS INTERNET_BUFFERSA, _    ' out
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS LONG

DECLARE FUNCTION HttpEndRequestW LIB "WinINet.dll" ALIAS "HttpEndRequestW" _
   ( _
    BYVAL hRequest AS DWORD, _              ' in
    lpBuffersOut AS INTERNET_BUFFERSW, _    ' out
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION HttpEndRequest LIB "WinINet.dll" ALIAS "HttpEndRequestW" _
   ( _
    BYVAL hRequest AS DWORD, _              ' in
    lpBuffersOut AS INTERNET_BUFFERSW, _    ' out
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS LONG
#ELSE
DECLARE FUNCTION HttpEndRequest LIB "WinINet.dll" ALIAS "HttpEndRequestA" _
   ( _
    BYVAL hRequest AS DWORD, _              ' in
    lpBuffersOut AS INTERNET_BUFFERSA, _    ' out
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwContext AS DWORD _              ' in
   ) AS LONG
#ENDIF

DECLARE FUNCTION HttpQueryInfoA LIB "WinINet.dll" ALIAS "HttpQueryInfoA" _
   ( _
    BYVAL hRequest AS DWORD, _              ' in
    BYVAL dwInfoLevel AS DWORD, _           ' in
    BYVAL lpBuffer AS BYTE PTR, _           ' in, out
    lpdwBufferLength AS DWORD, _            ' in, out
    BYVAL lpdwIndex AS DWORD PTR _          ' in, out
   ) AS LONG

DECLARE FUNCTION HttpQueryInfoW LIB "WinINet.dll" ALIAS "HttpQueryInfoW" _
   ( _
    BYVAL hRequest AS DWORD, _              ' in
    BYVAL dwInfoLevel AS DWORD, _           ' in
    BYVAL lpBuffer AS BYTE PTR, _           ' in, out
    lpdwBufferLength AS DWORD, _            ' in, out
    BYVAL lpdwIndex AS DWORD PTR _          ' in, out
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION HttpQueryInfo LIB "WinINet.dll" ALIAS "HttpQueryInfoW" _
   ( _
    BYVAL hRequest AS DWORD, _              ' in
    BYVAL dwInfoLevel AS DWORD, _           ' in
    BYVAL lpBuffer AS BYTE PTR, _           ' in, out
    lpdwBufferLength AS DWORD, _            ' in, out
    BYVAL lpdwIndex AS DWORD PTR _          ' in, out
   ) AS LONG
#ELSE
DECLARE FUNCTION HttpQueryInfo LIB "WinINet.dll" ALIAS "HttpQueryInfoA" _
   ( _
    BYVAL hRequest AS DWORD, _              ' in
    BYVAL dwInfoLevel AS DWORD, _           ' in
    BYVAL lpBuffer AS BYTE PTR, _           ' in, out
    lpdwBufferLength AS DWORD, _            ' in, out
    BYVAL lpdwIndex AS DWORD PTR _          ' in, out
   ) AS LONG
#ENDIF

'
' Cookie APIs
'

%INTERNET_COOKIE_IS_SECURE       = &H01
%INTERNET_COOKIE_IS_SESSION      = &H02

%INTERNET_COOKIE_THIRD_PARTY     = &H10
%INTERNET_COOKIE_PROMPT_REQUIRED = &H20
%INTERNET_COOKIE_EVALUATE_P3P    = &H40
%INTERNET_COOKIE_APPLY_P3P       = &H80?

%INTERNET_COOKIE_P3P_ENABLED     = &H100
%INTERNET_COOKIE_IS_RESTRICTED   = &H200
%INTERNET_COOKIE_IE6             = &H400
%INTERNET_COOKIE_IS_LEGACY       = &H800

%INTERNET_COOKIE_NON_SCRIPT      = &H00001000
%INTERNET_COOKIE_HTTPONLY        = &H00002000


DECLARE FUNCTION InternetSetCookieA LIB "WinINet.dll" _
   ALIAS "InternetSetCookieA" _
   ( _
    lpszUrl AS ASCIIZ, _                    ' in
    lpszCookieName AS ASCIIZ, _             ' in
    lpszCookieData AS ASCIIZ _              ' in
   ) AS LONG

DECLARE FUNCTION InternetSetCookieW LIB "WinINet.dll" _
   ALIAS "InternetSetCookieW" _
   ( _
    lpszUrl AS WSTRINGZ, _                  ' in
    lpszCookieName AS WSTRINGZ, _           ' in
    lpszCookieData AS WSTRINGZ _            ' in
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetSetCookie LIB "WinINet.dll" _
   ALIAS "InternetSetCookieW" _
   ( _
    lpszUrl AS WSTRINGZ, _                  ' in
    lpszCookieName AS WSTRINGZ, _           ' in
    lpszCookieData AS WSTRINGZ _            ' in
   ) AS LONG
#ELSE
DECLARE FUNCTION InternetSetCookie LIB "WinINet.dll" _
   ALIAS "InternetSetCookieA" _
   ( _
    lpszUrl AS ASCIIZ, _                    ' in
    lpszCookieName AS ASCIIZ, _             ' in
    lpszCookieData AS ASCIIZ _              ' in
   ) AS LONG
#ENDIF

DECLARE FUNCTION InternetGetCookieA LIB "WinINet.dll" _
   ALIAS "InternetGetCookieA" _
   ( _
    lpszUrl AS ASCIIZ, _                    ' in
    lpszCookieName AS ASCIIZ, _             ' in
    lpCookieData AS ASCIIZ, _               ' out
    lpdwSize AS DWORD _                     ' in, out
   ) _
   AS LONG

DECLARE FUNCTION InternetGetCookieW LIB "WinINet.dll" _
   ALIAS "InternetGetCookieW" _
   ( _
    lpszUrl AS WSTRINGZ, _                  ' in
    lpszCookieName AS WSTRINGZ, _           ' in
    lpCookieData AS WSTRINGZ, _             ' out
    lpdwSize AS DWORD _                     ' in, out
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetGetCookie LIB "WinINet.dll" _
   ALIAS "InternetGetCookieW" _
   ( _
    lpszUrl AS WSTRINGZ, _                  ' in
    lpszCookieName AS WSTRINGZ, _           ' in
    lpCookieData AS WSTRINGZ, _             ' out
    lpdwSize AS DWORD _                     ' in, out
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION InternetGetCookie LIB "WinINet.dll" _
   ALIAS "InternetGetCookieA" _
   ( _
    lpszUrl AS ASCIIZ, _                    ' in
    lpszCookieName AS ASCIIZ, _             ' in
    lpCookieData AS ASCIIZ, _               ' out
    lpdwSize AS DWORD _                     ' in, out
   ) _
   AS LONG
#ENDIF

DECLARE FUNCTION InternetSetCookieExA LIB "WinINet.dll" _
   ALIAS "InternetSetCookieExA" _
   ( _
    lpszUrl AS ASCIIZ, _
    lpszCookieName AS ASCIIZ, _
    lpszCookieData AS ASCIIZ, _
    BYVAL dwFlags AS DWORD, _
    BYVAL dwReserved AS DWORD _
   ) AS DWORD

DECLARE FUNCTION InternetSetCookieExW LIB "WinINet.dll" _
   ALIAS "InternetSetCookieExW" _
   ( _
    lpszUrl AS WSTRINGZ, _
    lpszCookieName AS WSTRINGZ, _
    lpszCookieData AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD, _
    BYVAL dwReserved AS DWORD _
   ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetSetCookieEx LIB "WinINet.dll" _
   ALIAS "InternetSetCookieExW" _
   ( _
    lpszUrl AS WSTRINGZ, _
    lpszCookieName AS WSTRINGZ, _
    lpszCookieData AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD, _
    BYVAL dwReserved AS DWORD _
   ) AS DWORD
#ELSE
DECLARE FUNCTION InternetSetCookieEx LIB "WinINet.dll" _
   ALIAS "InternetSetCookieExA" _
   ( _
    lpszUrl AS ASCIIZ, _
    lpszCookieName AS ASCIIZ, _
    lpszCookieData AS ASCIIZ, _
    BYVAL dwFlags AS DWORD, _
    BYVAL dwReserved AS DWORD _
   ) AS DWORD
#ENDIF

DECLARE FUNCTION InternetGetCookieExA LIB "WinINet.dll" _
   ALIAS "InternetGetCookieExA" _
   ( _
    lpszUrl AS ASCIIZ, _
    lpszCookieName AS ASCIIZ, _
    lpCookieData AS ASCIIZ, _
    pcchCookieData AS DWORD, _
    BYVAL dwFlags AS DWORD, _
    BYVAL lpReserved AS DWORD _
   ) AS LONG

DECLARE FUNCTION InternetGetCookieExW LIB "WinINet.dll" _
   ALIAS "InternetGetCookieExW" _
   ( _
    lpszUrl AS WSTRINGZ, _
    lpszCookieName AS WSTRINGZ, _
    lpCookieData AS WSTRINGZ, _
    pcchCookieData AS DWORD, _
    BYVAL dwFlags AS DWORD, _
    BYVAL lpReserved AS DWORD _
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetGetCookieEx LIB "WinINet.dll" _
   ALIAS "InternetGetCookieExW" _
   ( _
    lpszUrl AS WSTRINGZ, _
    lpszCookieName AS WSTRINGZ, _
    lpCookieData AS WSTRINGZ, _
    pcchCookieData AS DWORD, _
    BYVAL dwFlags AS DWORD, _
    BYVAL lpReserved AS DWORD _
   ) AS LONG
#ELSE
DECLARE FUNCTION InternetGetCookieEx LIB "WinINet.dll" _
   ALIAS "InternetGetCookieExA" _
   ( _
    lpszUrl AS ASCIIZ, _
    lpszCookieName AS ASCIIZ, _
    lpCookieData AS ASCIIZ, _
    pcchCookieData AS DWORD, _
    BYVAL dwFlags AS DWORD, _
    BYVAL lpReserved AS DWORD _
   ) AS LONG
#ENDIF

'
' offline browsing
'

DECLARE FUNCTION InternetAttemptConnect LIB "WinINet.dll" _
   ALIAS "InternetAttemptConnect" _
   ( _
    BYVAL dwReserved AS DWORD _             ' in
   ) AS DWORD

DECLARE FUNCTION InternetCheckConnectionA LIB "WinINet.dll" _
   ALIAS "InternetCheckConnectionA" _
   ( _
    lpszUrl AS ASCIIZ, _                    ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwReserved AS DWORD _             ' in
   ) AS LONG

DECLARE FUNCTION InternetCheckConnectionW LIB "WinINet.dll" _
   ALIAS "InternetCheckConnectionW" _
   ( _
    lpszUrl AS WSTRINGZ, _                  ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwReserved AS DWORD _             ' in
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetCheckConnection LIB "WinINet.dll" _
   ALIAS "InternetCheckConnectionW" _
   ( _
    lpszUrl AS WSTRINGZ, _                  ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwReserved AS DWORD _             ' in
   ) AS LONG
#ELSE
DECLARE FUNCTION InternetCheckConnection LIB "WinINet.dll" _
   ALIAS "InternetCheckConnectionA" _
   ( _
    lpszUrl AS ASCIIZ, _                    ' in
    BYVAL dwFlags AS DWORD, _               ' in
    BYVAL dwReserved AS DWORD _             ' in
   ) AS LONG
#ENDIF

%FLAG_ICC_FORCE_CONNECTION       = &H00000001

'
' Internet UI
'

'
' InternetErrorDlg - Provides UI for certain Errors.
'

%FLAGS_ERROR_UI_FILTER_FOR_ERRORS        = &H01
%FLAGS_ERROR_UI_FLAGS_CHANGE_OPTIONS     = &H02
%FLAGS_ERROR_UI_FLAGS_GENERATE_DATA      = &H04
%FLAGS_ERROR_UI_FLAGS_NO_UI              = &H08
%FLAGS_ERROR_UI_SERIALIZE_DIALOGS        = &H10

'
' If SERIALIZE_DIALOGS flag set, client should implement thread-safe
' non-blocking callback...
'

DECLARE FUNCTION InternetAuthNotifyCallback ( _
    BYVAL dwContext  AS DWORD, _  ' as passed to InternetErrorDlg
    BYVAL dwReturn   AS DWORD, _  ' error code: success, resend, or cancel
    BYVAL lpReserved AS DWORD _   ' reserved: will be set to null
    ) AS DWORD

DECLARE FUNCTION PFN_AUTH_NOTIFY (BYVAL DWORD, BYVAL DWORD, BYVAL DWORD) _
    AS DWORD

'
' ... and last parameter of InternetErrorDlg should point to...
'

TYPE INTERNET_AUTH_NOTIFY_DATA
    cbStruct  AS DWORD   ' size of this structure
    dwOptions AS DWORD   ' reserved: must be set to 0
    pfnNotify AS DWORD   ' notification callback to retry InternetErrorDlg
    dwContext AS DWORD   ' context to pass to to notification function
END TYPE

DECLARE FUNCTION ResumeSuspendedDownload LIB "WinINet.dll" _
   ALIAS "ResumeSuspendedDownload" _
   ( _
    BYVAL hRequest AS DWORD, _              ' in
    BYVAL dwResultCode AS DWORD _           ' in
   ) AS LONG  ' BOOL

DECLARE FUNCTION InternetErrorDlg LIB "WinINet.dll" _
   ALIAS "InternetErrorDlg" _
   ( _
    BYVAL hWnd     AS DWORD, _              ' in
    hRequest       AS DWORD, _              ' in, out
    BYVAL dwError  AS DWORD, _              ' in
    BYVAL dwFlags  AS DWORD, _              ' in
    BYVAL lppvData AS BYTE PTR _            ' in, out
   ) AS DWORD


DECLARE FUNCTION InternetConfirmZoneCrossingA LIB "WinINet.dll" _
   ALIAS "InternetConfirmZoneCrossingA" _
   ( _
    BYVAL hWnd  AS DWORD, _                 ' in
    szUrlPrev   AS ASCIIZ, _                ' in
    szUrlNew    AS ASCIIZ, _                ' in
    BYVAL bPost AS LONG _                   ' in
   ) AS DWORD

DECLARE FUNCTION InternetConfirmZoneCrossingW LIB "WinINet.dll" _
   ALIAS "InternetConfirmZoneCrossingW" _
   ( _
    BYVAL hWnd  AS DWORD, _                 ' in
    szUrlPrev   AS WSTRINGZ, _              ' in
    szUrlNew    AS WSTRINGZ, _              ' in
    BYVAL bPost AS LONG _                   ' in
   ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetConfirmZoneCrossing LIB "WinINet.dll" _
   ALIAS "InternetConfirmZoneCrossingW" _
   ( _
    BYVAL hWnd  AS DWORD, _                 ' in
    szUrlPrev   AS WSTRINGZ, _              ' in
    szUrlNew    AS WSTRINGZ, _              ' in
    BYVAL bPost AS LONG _                   ' in
   ) AS DWORD
#ELSEIF %DEF(%WINX32)
DECLARE FUNCTION InternetConfirmZoneCrossing LIB "WinINet.dll" _
   ALIAS "InternetConfirmZoneCrossingA" _
   ( _
    BYVAL hWnd  AS DWORD, _                 ' in
    szUrlPrev   AS ASCIIZ, _                ' in
    szUrlNew    AS ASCIIZ, _                ' in
    BYVAL bPost AS LONG _                   ' in
   ) AS DWORD
#ELSE
DECLARE FUNCTION InternetConfirmZoneCrossing LIB "WinINet.dll" _
   ALIAS "InternetConfirmZoneCrossing" _
   ( _
    BYVAL hWnd  AS DWORD, _                 ' in
    szUrlPrev   AS ASCIIZ, _                ' in
    szUrlNew    AS ASCIIZ, _                ' in
    BYVAL bPost AS LONG _                   ' in
   ) AS DWORD
#ENDIF

'
' Internet API error returns
'

%INTERNET_ERROR_BASE                     = 12000

%ERROR_INTERNET_OUT_OF_HANDLES           = (%INTERNET_ERROR_BASE + 1)
%ERROR_INTERNET_TIMEOUT                  = (%INTERNET_ERROR_BASE + 2)
%ERROR_INTERNET_EXTENDED_ERROR           = (%INTERNET_ERROR_BASE + 3)
%ERROR_INTERNET_INTERNAL_ERROR           = (%INTERNET_ERROR_BASE + 4)
%ERROR_INTERNET_INVALID_URL              = (%INTERNET_ERROR_BASE + 5)
%ERROR_INTERNET_UNRECOGNIZED_SCHEME      = (%INTERNET_ERROR_BASE + 6)
%ERROR_INTERNET_NAME_NOT_RESOLVED        = (%INTERNET_ERROR_BASE + 7)
%ERROR_INTERNET_PROTOCOL_NOT_FOUND       = (%INTERNET_ERROR_BASE + 8)
%ERROR_INTERNET_INVALID_OPTION           = (%INTERNET_ERROR_BASE + 9)
%ERROR_INTERNET_BAD_OPTION_LENGTH        = (%INTERNET_ERROR_BASE + 10)
%ERROR_INTERNET_OPTION_NOT_SETTABLE      = (%INTERNET_ERROR_BASE + 11)
%ERROR_INTERNET_SHUTDOWN                 = (%INTERNET_ERROR_BASE + 12)
%ERROR_INTERNET_INCORRECT_USER_NAME      = (%INTERNET_ERROR_BASE + 13)
%ERROR_INTERNET_INCORRECT_PASSWORD       = (%INTERNET_ERROR_BASE + 14)
%ERROR_INTERNET_LOGIN_FAILURE            = (%INTERNET_ERROR_BASE + 15)
%ERROR_INTERNET_INVALID_OPERATION        = (%INTERNET_ERROR_BASE + 16)
%ERROR_INTERNET_OPERATION_CANCELLED      = (%INTERNET_ERROR_BASE + 17)
%ERROR_INTERNET_INCORRECT_HANDLE_TYPE    = (%INTERNET_ERROR_BASE + 18)
%ERROR_INTERNET_INCORRECT_HANDLE_STATE   = (%INTERNET_ERROR_BASE + 19)
%ERROR_INTERNET_NOT_PROXY_REQUEST        = (%INTERNET_ERROR_BASE + 20)
%ERROR_INTERNET_REGISTRY_VALUE_NOT_FOUND = (%INTERNET_ERROR_BASE + 21)
%ERROR_INTERNET_BAD_REGISTRY_PARAMETER   = (%INTERNET_ERROR_BASE + 22)
%ERROR_INTERNET_NO_DIRECT_ACCESS         = (%INTERNET_ERROR_BASE + 23)
%ERROR_INTERNET_NO_CONTEXT               = (%INTERNET_ERROR_BASE + 24)
%ERROR_INTERNET_NO_CALLBACK              = (%INTERNET_ERROR_BASE + 25)
%ERROR_INTERNET_REQUEST_PENDING          = (%INTERNET_ERROR_BASE + 26)
%ERROR_INTERNET_INCORRECT_FORMAT         = (%INTERNET_ERROR_BASE + 27)
%ERROR_INTERNET_ITEM_NOT_FOUND           = (%INTERNET_ERROR_BASE + 28)
%ERROR_INTERNET_CANNOT_CONNECT           = (%INTERNET_ERROR_BASE + 29)
%ERROR_INTERNET_CONNECTION_ABORTED       = (%INTERNET_ERROR_BASE + 30)
%ERROR_INTERNET_CONNECTION_RESET         = (%INTERNET_ERROR_BASE + 31)
%ERROR_INTERNET_FORCE_RETRY              = (%INTERNET_ERROR_BASE + 32)
%ERROR_INTERNET_INVALID_PROXY_REQUEST    = (%INTERNET_ERROR_BASE + 33)
%ERROR_INTERNET_NEED_UI                  = (%INTERNET_ERROR_BASE + 34)

%ERROR_INTERNET_HANDLE_EXISTS            = (%INTERNET_ERROR_BASE + 36)
%ERROR_INTERNET_SEC_CERT_DATE_INVALID    = (%INTERNET_ERROR_BASE + 37)
%ERROR_INTERNET_SEC_CERT_CN_INVALID      = (%INTERNET_ERROR_BASE + 38)
%ERROR_INTERNET_HTTP_TO_HTTPS_ON_REDIR   = (%INTERNET_ERROR_BASE + 39)
%ERROR_INTERNET_HTTPS_TO_HTTP_ON_REDIR   = (%INTERNET_ERROR_BASE + 40)
%ERROR_INTERNET_MIXED_SECURITY           = (%INTERNET_ERROR_BASE + 41)
%ERROR_INTERNET_CHG_POST_IS_NON_SECURE   = (%INTERNET_ERROR_BASE + 42)
%ERROR_INTERNET_POST_IS_NON_SECURE       = (%INTERNET_ERROR_BASE + 43)
%ERROR_INTERNET_CLIENT_AUTH_CERT_NEEDED  = (%INTERNET_ERROR_BASE + 44)
%ERROR_INTERNET_INVALID_CA               = (%INTERNET_ERROR_BASE + 45)
%ERROR_INTERNET_CLIENT_AUTH_NOT_SETUP    = (%INTERNET_ERROR_BASE + 46)
%ERROR_INTERNET_ASYNC_THREAD_FAILED      = (%INTERNET_ERROR_BASE + 47)
%ERROR_INTERNET_REDIRECT_SCHEME_CHANGE   = (%INTERNET_ERROR_BASE + 48)
%ERROR_INTERNET_DIALOG_PENDING           = (%INTERNET_ERROR_BASE + 49)
%ERROR_INTERNET_RETRY_DIALOG             = (%INTERNET_ERROR_BASE + 50)
%ERROR_INTERNET_HTTPS_HTTP_SUBMIT_REDIR  = (%INTERNET_ERROR_BASE + 52)
%ERROR_INTERNET_INSERT_CDROM             = (%INTERNET_ERROR_BASE + 53)
%ERROR_INTERNET_FORTEZZA_LOGIN_NEEDED    = (%INTERNET_ERROR_BASE + 54)
%ERROR_INTERNET_SEC_CERT_ERRORS          = (%INTERNET_ERROR_BASE + 55)
%ERROR_INTERNET_SEC_CERT_NO_REV          = (%INTERNET_ERROR_BASE + 56)
%ERROR_INTERNET_SEC_CERT_REV_FAILED      = (%INTERNET_ERROR_BASE + 57)

'
' FTP API errors
'

%ERROR_FTP_TRANSFER_IN_PROGRESS          = (%INTERNET_ERROR_BASE + 110)
%ERROR_FTP_DROPPED                       = (%INTERNET_ERROR_BASE + 111)
%ERROR_FTP_NO_PASSIVE_MODE               = (%INTERNET_ERROR_BASE + 112)

'
' gopher API errors
'

%ERROR_GOPHER_PROTOCOL_ERROR             = (%INTERNET_ERROR_BASE + 130)
%ERROR_GOPHER_NOT_FILE                   = (%INTERNET_ERROR_BASE + 131)
%ERROR_GOPHER_DATA_ERROR                 = (%INTERNET_ERROR_BASE + 132)
%ERROR_GOPHER_END_OF_DATA                = (%INTERNET_ERROR_BASE + 133)
%ERROR_GOPHER_INVALID_LOCATOR            = (%INTERNET_ERROR_BASE + 134)
%ERROR_GOPHER_INCORRECT_LOCATOR_TYPE     = (%INTERNET_ERROR_BASE + 135)
%ERROR_GOPHER_NOT_GOPHER_PLUS            = (%INTERNET_ERROR_BASE + 136)
%ERROR_GOPHER_ATTRIBUTE_NOT_FOUND        = (%INTERNET_ERROR_BASE + 137)
%ERROR_GOPHER_UNKNOWN_LOCATOR            = (%INTERNET_ERROR_BASE + 138)

'
' HTTP API errors
'

%ERROR_HTTP_HEADER_NOT_FOUND             = (%INTERNET_ERROR_BASE + 150)
%ERROR_HTTP_DOWNLEVEL_SERVER             = (%INTERNET_ERROR_BASE + 151)
%ERROR_HTTP_INVALID_SERVER_RESPONSE      = (%INTERNET_ERROR_BASE + 152)
%ERROR_HTTP_INVALID_HEADER               = (%INTERNET_ERROR_BASE + 153)
%ERROR_HTTP_INVALID_QUERY_REQUEST        = (%INTERNET_ERROR_BASE + 154)
%ERROR_HTTP_HEADER_ALREADY_EXISTS        = (%INTERNET_ERROR_BASE + 155)
%ERROR_HTTP_REDIRECT_FAILED              = (%INTERNET_ERROR_BASE + 156)
%ERROR_HTTP_NOT_REDIRECTED               = (%INTERNET_ERROR_BASE + 160)
%ERROR_HTTP_COOKIE_NEEDS_CONFIRMATION    = (%INTERNET_ERROR_BASE + 161)
%ERROR_HTTP_COOKIE_DECLINED              = (%INTERNET_ERROR_BASE + 162)
%ERROR_HTTP_REDIRECT_NEEDS_CONFIRMATION  = (%INTERNET_ERROR_BASE + 168)

'
' additional Internet API error codes
'

%ERROR_INTERNET_SECURITY_CHANNEL_ERROR   = (%INTERNET_ERROR_BASE + 157)
%ERROR_INTERNET_UNABLE_TO_CACHE_FILE     = (%INTERNET_ERROR_BASE + 158)
%ERROR_INTERNET_TCPIP_NOT_INSTALLED      = (%INTERNET_ERROR_BASE + 159)
%ERROR_INTERNET_DISCONNECTED             = (%INTERNET_ERROR_BASE + 163)
%ERROR_INTERNET_SERVER_UNREACHABLE       = (%INTERNET_ERROR_BASE + 164)
%ERROR_INTERNET_PROXY_SERVER_UNREACHABLE = (%INTERNET_ERROR_BASE + 165)

%ERROR_INTERNET_BAD_AUTO_PROXY_SCRIPT    = (%INTERNET_ERROR_BASE + 166)
%ERROR_INTERNET_UNABLE_TO_DOWNLOAD_SCRIPT = (%INTERNET_ERROR_BASE + 167)
%ERROR_INTERNET_SEC_INVALID_CERT         = (%INTERNET_ERROR_BASE + 169)
%ERROR_INTERNET_SEC_CERT_REVOKED         = (%INTERNET_ERROR_BASE + 170)

' InternetAutodial specific errors

%ERROR_INTERNET_FAILED_DUETOSECURITYCHECK  = (%INTERNET_ERROR_BASE + 171)
%ERROR_INTERNET_NOT_INITIALIZED            = (%INTERNET_ERROR_BASE + 172)
%ERROR_INTERNET_NEED_MSN_SSPI_PKG          = (%INTERNET_ERROR_BASE + 173)
%ERROR_INTERNET_LOGIN_FAILURE_DISPLAY_ENTITY_BODY = (%INTERNET_ERROR_BASE + 174)

' Decoding/Decompression specific errors

%ERROR_INTERNET_DECODING_FAILED          = (%INTERNET_ERROR_BASE + 175)


%INTERNET_ERROR_LAST = %ERROR_INTERNET_LOGIN_FAILURE_DISPLAY_ENTITY_BODY


'
' URLCACHE APIs
'

'
' datatype definitions.
'

'
' cache entry type flags.
'

%NORMAL_CACHE_ENTRY              = &H00000001
%STICKY_CACHE_ENTRY              = &H00000004
%EDITED_CACHE_ENTRY              = &H00000008
%TRACK_OFFLINE_CACHE_ENTRY       = &H00000010
%TRACK_ONLINE_CACHE_ENTRY        = &H00000020
%SPARSE_CACHE_ENTRY              = &H00010000
%COOKIE_CACHE_ENTRY              = &H00100000
%URLHISTORY_CACHE_ENTRY          = &H00200000



%URLCACHE_FIND_DEFAULT_FILTER    = %NORMAL_CACHE_ENTRY _
                                   OR %COOKIE_CACHE_ENTRY _
                                   OR %URLHISTORY_CACHE_ENTRY _
                                   OR %TRACK_OFFLINE_CACHE_ENTRY _
                                   OR %TRACK_ONLINE_CACHE_ENTRY _
                                   OR %STICKY_CACHE_ENTRY

TYPE INTERNET_CACHE_TIMESTAMPS
    ftExpires      AS FILETIME
    ftLastModified AS FILETIME
END TYPE

'
' Cache Group
'
'MACRO GROUPID=QUAD

'
' Cache Group Flags
'
%CACHEGROUP_ATTRIBUTE_GET_ALL      = &Hffffffff???
%CACHEGROUP_ATTRIBUTE_BASIC        = &H00000001
%CACHEGROUP_ATTRIBUTE_FLAG         = &H00000002
%CACHEGROUP_ATTRIBUTE_TYPE         = &H00000004
%CACHEGROUP_ATTRIBUTE_QUOTA        = &H00000008
%CACHEGROUP_ATTRIBUTE_GROUPNAME    = &H00000010
%CACHEGROUP_ATTRIBUTE_STORAGE      = &H00000020

%CACHEGROUP_FLAG_NONPURGEABLE      = &H00000001
%CACHEGROUP_FLAG_GIDONLY           = &H00000004

%CACHEGROUP_FLAG_FLUSHURL_ONDELETE = &H00000002

%CACHEGROUP_SEARCH_ALL             = &H00000000
%CACHEGROUP_SEARCH_BYURL           = &H00000001

%CACHEGROUP_TYPE_INVALID           = &H00000001

'
' updatable cache group fields
'
%CACHEGROUP_READWRITE_MASK =                 _
           %CACHEGROUP_ATTRIBUTE_TYPE        _
        OR %CACHEGROUP_ATTRIBUTE_QUOTA       _
        OR %CACHEGROUP_ATTRIBUTE_GROUPNAME   _
        OR %CACHEGROUP_ATTRIBUTE_STORAGE

'
' INTERNET_CACHE_GROUP_INFO
'

%GROUPNAME_MAX_LENGTH     = 120
%GROUP_OWNER_STORAGE_SIZE = 4

TYPE INTERNET_CACHE_GROUP_INFOA
    dwGroupSize  AS DWORD
    dwGroupFlags AS DWORD
    dwGroupType  AS DWORD
    dwDiskUsage  AS DWORD    ' in KB
    dwDiskQuota  AS DWORD    ' in KB
    dwOwnerStorage(%GROUP_OWNER_STORAGE_SIZE - 1) AS DWORD
    szGroupName AS ASCIIZ * %GROUPNAME_MAX_LENGTH
END TYPE

TYPE INTERNET_CACHE_GROUP_INFOW
    dwGroupSize  AS DWORD
    dwGroupFlags AS DWORD
    dwGroupType  AS DWORD
    dwDiskUsage  AS DWORD    ' in KB
    dwDiskQuota  AS DWORD    ' in KB
    dwOwnerStorage(%GROUP_OWNER_STORAGE_SIZE - 1) AS DWORD
    szGroupName AS WSTRINGZ * %GROUPNAME_MAX_LENGTH
END TYPE

#IF %DEF(%UNICODE)
TYPE INTERNET_CACHE_GROUP_INFO
    INTERNET_CACHE_GROUP_INFOW
END TYPE
#ELSE
TYPE INTERNET_CACHE_GROUP_INFO
    INTERNET_CACHE_GROUP_INFOA
END TYPE
#ENDIF


'
' Cache APIs
'

DECLARE FUNCTION CreateUrlCacheEntryA LIB "WinINet.dll" _
   ALIAS "CreateUrlCacheEntryA" _
   ( _
    lpszUrlName              AS ASCIIZ, _   ' in
    BYVAL dwExpectedFileSize AS DWORD, _    ' in
    lpszFileExtension        AS ASCIIZ, _   ' in
    lpszFileName             AS ASCIIZ, _   ' out
    BYVAL dwReserved         AS DWORD _
   ) AS LONG

DECLARE FUNCTION CreateUrlCacheEntryW LIB "WinINet.dll" _
   ALIAS "CreateUrlCacheEntryW" _
   ( _
    lpszUrlName              AS WSTRINGZ, _ ' in
    BYVAL dwExpectedFileSize AS DWORD, _    ' in
    lpszFileExtension        AS WSTRINGZ, _ ' in
    lpszFileName             AS WSTRINGZ, _ ' out
    BYVAL dwReserved         AS DWORD _
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateUrlCacheEntry LIB "WinINet.dll" _
   ALIAS "CreateUrlCacheEntryW" _
   ( _
    lpszUrlName              AS WSTRINGZ, _ ' in
    BYVAL dwExpectedFileSize AS DWORD, _    ' in
    lpszFileExtension        AS WSTRINGZ, _ ' in
    lpszFileName             AS WSTRINGZ, _ ' out
    BYVAL dwReserved         AS DWORD _
   ) AS LONG
#ELSE
DECLARE FUNCTION CreateUrlCacheEntry LIB "WinINet.dll" _
   ALIAS "CreateUrlCacheEntryA" _
   ( _
    lpszUrlName              AS ASCIIZ, _   ' in
    BYVAL dwExpectedFileSize AS DWORD, _    ' in
    lpszFileExtension        AS ASCIIZ, _   ' in
    lpszFileName             AS ASCIIZ, _   ' out
    BYVAL dwReserved         AS DWORD _
   ) AS LONG
#ENDIF

#IF NOT %DEF(%USE_FIXED_COMMIT_URL_CACHE_ENTRY)
' Temporary state of affairs until we reconcile our apis.

' Why are we doing this? HeaderInfo _should_ be string data.
' However, one group is passing binary data instead. For the
' unicode api, we've decided to disallow this, but this
' brings up an inconsistency between the u and a apis, which
' is undesirable.

' For Beta 1, we'll go with this behaviour, but in future releases
' we want to make these apis consistent.

DECLARE FUNCTION CommitUrlCacheEntryA LIB "WinINet.dll" _
   ALIAS "CommitUrlCacheEntryA" _
   ( _
    lpszUrlName            AS ASCIIZ, _    ' in
    lpszLocalFileName      AS ASCIIZ, _    ' in
    BYVAL ExpireTime       AS FILETIME, _  ' in
    BYVAL LastModifiedTime AS FILETIME, _  ' in
    BYVAL CacheEntryType   AS DWORD, _     ' in
    BYVAL lpHeaderInfo     AS BYTE PTR, _   ' in
    dwHeaderSize           AS DWORD, _     ' in
    lpszFileExtension      AS ASCIIZ, _    ' in
    lpszOriginalUrl        AS ASCIIZ _     ' in
   ) AS LONG

DECLARE FUNCTION CommitUrlCacheEntryW LIB "WinINet.dll" _
   ALIAS "CommitUrlCacheEntryW" _
   ( _
    lpszUrlName            AS WSTRINGZ, _  ' in
    lpszLocalFileName      AS WSTRINGZ, _  ' in
    BYVAL ExpireTime       AS FILETIME, _  ' in
    BYVAL LastModifiedTime AS FILETIME, _  ' in
    BYVAL CacheEntryType   AS DWORD, _     ' in
    lpHeaderInfo           AS WSTRINGZ, _  ' in
    dwHeaderSize           AS DWORD, _     ' in
    lpszFileExtension      AS WSTRINGZ, _  ' in
    lpszOriginalUrl        AS WSTRINGZ _   ' in
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CommitUrlCacheEntry LIB "WinINet.dll" _
   ALIAS "CommitUrlCacheEntryW" _
   ( _
    lpszUrlName            AS WSTRINGZ, _  ' in
    lpszLocalFileName      AS WSTRINGZ, _  ' in
    BYVAL ExpireTime       AS FILETIME, _  ' in
    BYVAL LastModifiedTime AS FILETIME, _  ' in
    BYVAL CacheEntryType   AS DWORD, _     ' in
    lpHeaderInfo           AS WSTRINGZ, _  ' in
    dwHeaderSize           AS DWORD, _     ' in
    lpszFileExtension      AS WSTRINGZ, _  ' in
    lpszOriginalUrl        AS WSTRINGZ _   ' in
   ) AS LONG
#ELSE
DECLARE FUNCTION CommitUrlCacheEntry LIB "WinINet.dll" _
   ALIAS "CommitUrlCacheEntryA" _
   ( _
    lpszUrlName            AS ASCIIZ, _    ' in
    lpszLocalFileName      AS ASCIIZ, _    ' in
    BYVAL ExpireTime       AS FILETIME, _  ' in
    BYVAL LastModifiedTime AS FILETIME, _  ' in
    BYVAL CacheEntryType   AS DWORD, _     ' in
    BYVAL lpHeaderInfo     AS BYTE PTR, _   ' in
    dwHeaderSize           AS DWORD, _     ' in
    lpszFileExtension      AS ASCIIZ, _    ' in
    lpszOriginalUrl        AS ASCIIZ _     ' in
   ) AS LONG
#ENDIF

#ELSE
DECLARE FUNCTION CommitUrlCacheEntryA LIB "WinINet.dll" _
   ALIAS "CommitUrlCacheEntryA" _
   ( _
    lpszUrlName            AS ASCIIZ, _    ' in
    lpszLocalFileName      AS ASCIIZ, _    ' in
    BYVAL ExpireTime       AS FILETIME, _  ' in
    BYVAL LastModifiedTime AS FILETIME, _  ' in
    BYVAL CacheEntryType   AS DWORD, _     ' in
    lpHeaderInfo           AS ASCIIZ, _    ' in
    dwHeaderSize           AS DWORD, _     ' in
    lpszFileExtension      AS ASCIIZ, _    ' in
    lpszOriginalUrl        AS ASCIIZ _     ' in
   ) AS LONG

DECLARE FUNCTION CommitUrlCacheEntryW LIB "WinINet.dll" _
   ALIAS "CommitUrlCacheEntryW" _
   ( _
    lpszUrlName            AS WSTRINGZ, _  ' in
    lpszLocalFileName      AS WSTRINGZ, _  ' in
    BYVAL ExpireTime       AS FILETIME, _  ' in
    BYVAL LastModifiedTime AS FILETIME, _  ' in
    BYVAL CacheEntryType   AS DWORD, _     ' in
    lpHeaderInfo           AS WSTRINGZ, _  ' in
    dwHeaderSize           AS DWORD, _     ' in
    lpszFileExtension      AS WSTRINGZ, _  ' in
    lpszOriginalUrl        AS WSTRINGZ _   ' in
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CommitUrlCacheEntry LIB "WinINet.dll" _
   ALIAS "CommitUrlCacheEntryW" _
   ( _
    lpszUrlName            AS WSTRINGZ, _  ' in
    lpszLocalFileName      AS WSTRINGZ, _  ' in
    BYVAL ExpireTime       AS FILETIME, _  ' in
    BYVAL LastModifiedTime AS FILETIME, _  ' in
    BYVAL CacheEntryType   AS DWORD, _     ' in
    lpHeaderInfo           AS WSTRINGZ, _  ' in
    dwHeaderSize           AS DWORD, _     ' in
    lpszFileExtension      AS WSTRINGZ, _  ' in
    lpszOriginalUrl        AS WSTRINGZ _   ' in
   ) AS LONG
#ELSE
DECLARE FUNCTION CommitUrlCacheEntry LIB "WinINet.dll" _
   ALIAS "CommitUrlCacheEntryA" _
   ( _
    lpszUrlName            AS ASCIIZ, _    ' in
    lpszLocalFileName      AS ASCIIZ, _    ' in
    BYVAL ExpireTime       AS FILETIME, _  ' in
    BYVAL LastModifiedTime AS FILETIME, _  ' in
    BYVAL CacheEntryType   AS DWORD, _     ' in
    lpHeaderInfo           AS ASCIIZ, _    ' in
    dwHeaderSize           AS DWORD, _     ' in
    lpszFileExtension      AS ASCIIZ, _    ' in
    lpszOriginalUrl        AS ASCIIZ _     ' in
   ) AS LONG
#ENDIF

#ENDIF  ' #IF NOT %DEF(%USE_FIXED_COMMIT_URL_CACHE_ENTRY)


DECLARE FUNCTION RetrieveUrlCacheEntryFileA LIB "WinINet.dll" _
   ALIAS "RetrieveUrlCacheEntryFileA" _
   ( _
    lpszUrlName                  AS ASCIIZ, _  ' in
    lpCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFO, _  ' out
    lpdwCacheEntryInfoBufferSize AS DWORD, _   ' in, out
    BYVAL dwReserved             AS DWORD _    ' in
   ) AS LONG

DECLARE FUNCTION RetrieveUrlCacheEntryFileW LIB "WinINet.dll" _
   ALIAS "RetrieveUrlCacheEntryFileW" _
   ( _
    lpszUrlName                  AS WSTRINGZ, _  ' in
    lpCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFO, _  ' out
    lpdwCacheEntryInfoBufferSize AS DWORD, _     ' in, out
    BYVAL dwReserved             AS DWORD _      ' in
   ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION RetrieveUrlCacheEntryFile LIB "WinINet.dll" _
   ALIAS "RetrieveUrlCacheEntryFileW" _
   ( _
    lpszUrlName                  AS WSTRINGZ, _  ' in
    lpCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFO, _  ' out
    lpdwCacheEntryInfoBufferSize AS DWORD, _     ' in, out
    BYVAL dwReserved             AS DWORD _      ' in
   ) AS LONG
#ELSE
DECLARE FUNCTION RetrieveUrlCacheEntryFile LIB "WinINet.dll" _
   ALIAS "RetrieveUrlCacheEntryFileA" _
   ( _
    lpszUrlName                  AS ASCIIZ, _  ' in
    lpCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFO, _  ' out
    lpdwCacheEntryInfoBufferSize AS DWORD, _   ' in, out
    BYVAL dwReserved             AS DWORD _    ' in
   ) AS LONG
#ENDIF

DECLARE FUNCTION UnlockUrlCacheEntryFileA LIB "WinINet.dll" _
   ALIAS "UnlockUrlCacheEntryFileA" _
   ( _
    lpszUrlName      AS ASCIIZ, _      ' in
    BYVAL dwReserved AS DWORD _        ' in
   ) _
   AS LONG

DECLARE FUNCTION UnlockUrlCacheEntryFileW LIB "WinINet.dll" _
   ALIAS "UnlockUrlCacheEntryFileW" _
   ( _
    lpszUrlName      AS WSTRINGZ, _    ' in
    BYVAL dwReserved AS DWORD _        ' in
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION UnlockUrlCacheEntryFile LIB "WinINet.dll" _
   ALIAS "UnlockUrlCacheEntryFileW" _
   ( _
    lpszUrlName      AS WSTRINGZ, _    ' in
    BYVAL dwReserved AS DWORD _        ' in
   ) _
   AS LONG
#ELSEIF %DEF(%WINX32)
DECLARE FUNCTION UnlockUrlCacheEntryFile LIB "WinINet.dll" _
   ALIAS "UnlockUrlCacheEntryFileA" _
   ( _
    lpszUrlName      AS ASCIIZ, _      ' in
    BYVAL dwReserved AS DWORD _        ' in
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION UnlockUrlCacheEntryFile LIB "WinINet.dll" _
   ALIAS "UnlockUrlCacheEntryFile" _
   ( _
    lpszUrlName      AS ASCIIZ, _      ' in
    BYVAL dwReserved AS DWORD _        ' in
   ) _
   AS LONG
#ENDIF


DECLARE FUNCTION RetrieveUrlCacheEntryStreamA LIB "WinINet.dll" _
   ALIAS "RetrieveUrlCacheEntryStreamA" _
   ( _
    lpszUrlName                  AS ASCIIZ, _   ' in
    lpCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFO, _  ' out
    lpdwCacheEntryInfoBufferSize AS DWORD, _    ' in, out
    BYVAL fRandomRead            AS LONG, _     ' in
    BYVAL dwReserved             AS DWORD _     ' in
   ) _
   AS DWORD

DECLARE FUNCTION RetrieveUrlCacheEntryStreamW LIB "WinINet.dll" _
   ALIAS "RetrieveUrlCacheEntryStreamW" _
   ( _
    lpszUrlName                  AS WSTRINGZ, _ ' in
    lpCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFO, _  ' out
    lpdwCacheEntryInfoBufferSize AS DWORD, _    ' in, out
    BYVAL fRandomRead            AS LONG, _     ' in
    BYVAL dwReserved             AS DWORD _     ' in
   ) _
   AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION RetrieveUrlCacheEntryStream LIB "WinINet.dll" _
   ALIAS "RetrieveUrlCacheEntryStreamW" _
   ( _
    lpszUrlName                  AS WSTRINGZ, _ ' in
    lpCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFO, _  ' out
    lpdwCacheEntryInfoBufferSize AS DWORD, _    ' in, out
    BYVAL fRandomRead            AS LONG, _     ' in
    BYVAL dwReserved             AS DWORD _     ' in
   ) _
   AS DWORD
#ELSE
DECLARE FUNCTION RetrieveUrlCacheEntryStream LIB "WinINet.dll" _
   ALIAS "RetrieveUrlCacheEntryStreamA" _
   ( _
    lpszUrlName                  AS ASCIIZ, _   ' in
    lpCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFO, _  ' out
    lpdwCacheEntryInfoBufferSize AS DWORD, _    ' in, out
    BYVAL fRandomRead            AS LONG, _     ' in
    BYVAL dwReserved             AS DWORD _     ' in
   ) _
   AS DWORD
#ENDIF

DECLARE FUNCTION ReadUrlCacheEntryStream LIB "WinINet.dll" _
   ALIAS "ReadUrlCacheEntryStream" _
   ( _
    BYVAL hUrlCacheStream AS DWORD, _      ' in
    BYVAL dwLocation      AS DWORD, _      ' in
    BYVAL lpBuffer        AS BYTE PTR, _   ' in, out
    lpdwLen               AS DWORD, _      ' in, out
    BYVAL dwReserved      AS DWORD _       ' in
   ) _
   AS LONG

DECLARE FUNCTION ReadUrlCacheEntryStreamEx LIB "WinINet.dll" _
   ALIAS "ReadUrlCacheEntryStreamEx" _
   ( _
    BYVAL hUrlCacheStream AS DWORD, _      ' in
    BYVAL dwLocation      AS QUAD, _       ' in
    BYVAL lpBuffer        AS BYTE PTR, _   ' in, out
    lpdwLen               AS DWORD _       ' in, out
   ) _
   AS LONG

DECLARE FUNCTION UnlockUrlCacheEntryStream LIB "WinINet.dll" _
   ALIAS "UnlockUrlCacheEntryStream" _
   ( _
    BYVAL hUrlCacheStream AS DWORD, _  ' in
    BYVAL dwReserved      AS DWORD _   ' in
   ) _
   AS LONG

DECLARE FUNCTION GetUrlCacheEntryInfoA LIB "WinINet.dll" _
   ALIAS "GetUrlCacheEntryInfoA" _
   ( _
    lpszUrlName                  AS ASCIIZ, _  ' in
    lpCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFO, _  ' out
    lpdwCacheEntryInfoBufferSize AS DWORD _    ' in, out
   ) _
   AS LONG

DECLARE FUNCTION GetUrlCacheEntryInfoW LIB "WinINet.dll" _
   ALIAS "GetUrlCacheEntryInfoW" _
   ( _
    lpszUrlName                  AS WSTRINGZ, _ ' in
    lpCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFO, _  ' out
    lpdwCacheEntryInfoBufferSize AS DWORD _     ' in, out
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetUrlCacheEntryInfo LIB "WinINet.dll" _
   ALIAS "GetUrlCacheEntryInfoW" _
   ( _
    lpszUrlName                  AS WSTRINGZ, _ ' in
    lpCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFO, _  ' out
    lpdwCacheEntryInfoBufferSize AS DWORD _     ' in, out
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION GetUrlCacheEntryInfo LIB "WinINet.dll" _
   ALIAS "GetUrlCacheEntryInfoA" _
   ( _
    lpszUrlName                  AS ASCIIZ, _  ' in
    lpCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFO, _  ' out
    lpdwCacheEntryInfoBufferSize AS DWORD _    ' in, out
   ) _
   AS LONG
#ENDIF

DECLARE FUNCTION FindFirstUrlCacheGroup LIB "WinINet.dll" _
   ALIAS "FindFirstUrlCacheGroup" _
   ( _
    BYVAL dwFlags           AS DWORD, _    ' in
    BYVAL dwFilter          AS DWORD, _    ' in
    BYVAL lpSearchCondition AS DWORD, _    ' must pass %NULL
    BYVAL dwSearchCondition AS DWORD, _    ' must pass 0
    GroupId                 AS QUAD, _     ' out
    BYVAL lpReserved        AS DWORD _     ' must pass %NULL
   ) _
   AS DWORD

DECLARE FUNCTION FindNextUrlCacheGroup LIB "WinINet.dll" _
   ALIAS "FindNextUrlCacheGroup" _
   ( _
    BYVAL hFind AS DWORD, _       ' in
    lpGroupId   AS QUAD, _        ' out
    BYVAL lpReserved AS DWORD _   ' must pass %NULL
   ) _
   AS LONG

DECLARE FUNCTION GetUrlCacheGroupAttributeA LIB "WinINet.dll" _
   ALIAS "GetUrlCacheGroupAttributeA" _
   ( _
    BYVAL gid          AS QUAD, _     ' in
    BYVAL dwFlags      AS DWORD, _    ' must be 0
    BYVAL dwAttributes AS DWORD, _    ' in
    lpGroupInfo        AS INTERNET_CACHE_GROUP_INFOA, _  ' out
    lpdwGroupInfo      AS DWORD, _    ' out
    BYVAL lpReserved   AS DWORD _     ' must pass %NULL
   ) _
   AS LONG

DECLARE FUNCTION GetUrlCacheGroupAttributeW LIB "WinINet.dll" _
   ALIAS "GetUrlCacheGroupAttributeW" _
   ( _
    BYVAL gid          AS QUAD, _     ' in
    BYVAL dwFlags      AS DWORD, _    ' must be 0
    BYVAL dwAttributes AS DWORD, _    ' in
    lpGroupInfo        AS INTERNET_CACHE_GROUP_INFOW, _  ' out
    lpdwGroupInfo      AS DWORD, _    ' out
    BYVAL lpReserved   AS DWORD _     ' must pass %NULL
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetUrlCacheGroupAttribute LIB "WinINet.dll" _
   ALIAS "GetUrlCacheGroupAttributeW" _
   ( _
    BYVAL gid          AS QUAD, _     ' in
    BYVAL dwFlags      AS DWORD, _    ' must be 0
    BYVAL dwAttributes AS DWORD, _    ' in
    lpGroupInfo        AS INTERNET_CACHE_GROUP_INFOW, _  ' out
    lpdwGroupInfo      AS DWORD, _    ' out
    BYVAL lpReserved   AS DWORD _     ' must pass %NULL
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION GetUrlCacheGroupAttribute LIB "WinINet.dll" _
   ALIAS "GetUrlCacheGroupAttributeA" _
   ( _
    BYVAL gid          AS QUAD, _     ' in
    BYVAL dwFlags      AS DWORD, _    ' must be 0
    BYVAL dwAttributes AS DWORD, _    ' in
    lpGroupInfo        AS INTERNET_CACHE_GROUP_INFOA, _  ' out
    lpdwGroupInfo      AS DWORD, _    ' out
    BYVAL lpReserved   AS DWORD _     ' must pass %NULL
   ) _
   AS LONG
#ENDIF

DECLARE FUNCTION SetUrlCacheGroupAttributeA LIB "WinINet.dll" _
   ALIAS "SetUrlCacheGroupAttributeA" _
   ( _
    BYVAL gid          AS QUAD, _     ' in
    BYVAL dwFlags      AS DWORD, _    ' must be 0
    BYVAL dwAttributes AS DWORD, _    ' in
    lpGroupInfo        AS INTERNET_CACHE_GROUP_INFOA, _  ' out
    lpdwGroupInfo      AS DWORD, _    ' out
    BYVAL lpReserved   AS DWORD _     ' must pass %NULL
   ) _
   AS LONG

DECLARE FUNCTION SetUrlCacheGroupAttributeW LIB "WinINet.dll" _
   ALIAS "SetUrlCacheGroupAttributeW" _
   ( _
    BYVAL gid          AS QUAD, _     ' in
    BYVAL dwFlags      AS DWORD, _    ' must be 0
    BYVAL dwAttributes AS DWORD, _    ' in
    lpGroupInfo        AS INTERNET_CACHE_GROUP_INFOW, _  ' out
    lpdwGroupInfo      AS DWORD, _    ' out
    BYVAL lpReserved   AS DWORD _     ' must pass %NULL
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetUrlCacheGroupAttribute LIB "WinINet.dll" _
   ALIAS "SetUrlCacheGroupAttributeW" _
   ( _
    BYVAL gid          AS QUAD, _     ' in
    BYVAL dwFlags      AS DWORD, _    ' must be 0
    BYVAL dwAttributes AS DWORD, _    ' in
    lpGroupInfo        AS INTERNET_CACHE_GROUP_INFOW, _  ' out
    lpdwGroupInfo      AS DWORD, _    ' out
    BYVAL lpReserved   AS DWORD _     ' must pass %NULL
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION SetUrlCacheGroupAttribute LIB "WinINet.dll" _
   ALIAS "SetUrlCacheGroupAttributeA" _
   ( _
    BYVAL gid          AS QUAD, _     ' in
    BYVAL dwFlags      AS DWORD, _    ' must be 0
    BYVAL dwAttributes AS DWORD, _    ' in
    lpGroupInfo        AS INTERNET_CACHE_GROUP_INFOA, _  ' out
    lpdwGroupInfo      AS DWORD, _    ' out
    BYVAL lpReserved   AS DWORD _     ' must pass %NULL
   ) _
   AS LONG
#ENDIF

DECLARE FUNCTION GetUrlCacheEntryInfoExA LIB "WinINet.dll" _
   ALIAS "GetUrlCacheEntryInfoExA" _
   ( _
    lpszUrl                   AS ASCIIZ, _   ' in
    lpCacheEntryInfo          AS INTERNET_CACHE_ENTRY_INFOA, _  ' out
    lpdwCacheEntryInfoBufSize AS DWORD, _    ' in, out
    BYVAL lpszReserved        AS DWORD, _    ' must pass %NULL
    BYVAL lpdwReserved        AS DWORD, _    ' must pass %NULL
    BYVAL lpReserved          AS DWORD, _    ' must pass %NULL
    BYVAL dwFlags             AS DWORD _     ' must pass %NULL
   ) _
   AS LONG

DECLARE FUNCTION GetUrlCacheEntryInfoExW LIB "WinINet.dll" _
   ALIAS "GetUrlCacheEntryInfoExW" _
   ( _
    lpszUrl                   AS WSTRINGZ, _   ' in
    lpCacheEntryInfo          AS INTERNET_CACHE_ENTRY_INFOW, _  ' out
    lpdwCacheEntryInfoBufSize AS DWORD, _    ' in, out
    BYVAL lpszReserved        AS DWORD, _    ' must pass %NULL
    BYVAL lpdwReserved        AS DWORD, _    ' must pass %NULL
    BYVAL lpReserved          AS DWORD, _    ' must pass %NULL
    BYVAL dwFlags             AS DWORD _     ' must pass %NULL
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetUrlCacheEntryInfoEx LIB "WinINet.dll" _
   ALIAS "GetUrlCacheEntryInfoExW" _
   ( _
    lpszUrl                   AS WSTRINGZ, _   ' in
    lpCacheEntryInfo          AS INTERNET_CACHE_ENTRY_INFOW, _  ' out
    lpdwCacheEntryInfoBufSize AS DWORD, _    ' in, out
    BYVAL lpszReserved        AS DWORD, _    ' must pass %NULL
    BYVAL lpdwReserved        AS DWORD, _    ' must pass %NULL
    BYVAL lpReserved          AS DWORD, _    ' must pass %NULL
    BYVAL dwFlags             AS DWORD _     ' must pass %NULL
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION GetUrlCacheEntryInfoEx LIB "WinINet.dll" _
   ALIAS "GetUrlCacheEntryInfoExA" _
   ( _
    lpszUrl                   AS ASCIIZ, _   ' in
    lpCacheEntryInfo          AS INTERNET_CACHE_ENTRY_INFOA, _  ' out
    lpdwCacheEntryInfoBufSize AS DWORD, _    ' in, out
    BYVAL lpszReserved        AS DWORD, _    ' must pass %NULL
    BYVAL lpdwReserved        AS DWORD, _    ' must pass %NULL
    BYVAL lpReserved          AS DWORD, _    ' must pass %NULL
    BYVAL dwFlags             AS DWORD _     ' must pass %NULL
   ) _
   AS LONG
#ENDIF

%CACHE_ENTRY_ATTRIBUTE_FC    = &H00000004
%CACHE_ENTRY_HITRATE_FC      = &H00000010
%CACHE_ENTRY_MODTIME_FC      = &H00000040
%CACHE_ENTRY_EXPTIME_FC      = &H00000080
%CACHE_ENTRY_ACCTIME_FC      = &H00000100
%CACHE_ENTRY_SYNCTIME_FC     = &H00000200
%CACHE_ENTRY_HEADERINFO_FC   = &H00000400
%CACHE_ENTRY_EXEMPT_DELTA_FC = &H00000800

DECLARE FUNCTION SetUrlCacheEntryInfoA LIB "WinINet.dll" _
   ALIAS "SetUrlCacheEntryInfoA" _
   ( _
    lpszUrlName          AS ASCIIZ, _                      ' in
    lpCacheEntryInfo     AS INTERNET_CACHE_ENTRY_INFO, _   ' in
    BYVAL dwFieldControl AS DWORD _                        ' in
   ) _
   AS LONG

DECLARE FUNCTION SetUrlCacheEntryInfoW LIB "WinINet.dll" _
   ALIAS "SetUrlCacheEntryInfoW" _
   ( _
    lpszUrlName          AS WSTRINGZ, _                    ' in
    lpCacheEntryInfo     AS INTERNET_CACHE_ENTRY_INFO, _   ' in
    BYVAL dwFieldControl AS DWORD _                        ' in
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetUrlCacheEntryInfo LIB "WinINet.dll" _
   ALIAS "SetUrlCacheEntryInfoW" _
   ( _
    lpszUrlName          AS WSTRINGZ, _                    ' in
    lpCacheEntryInfo     AS INTERNET_CACHE_ENTRY_INFO, _   ' in
    BYVAL dwFieldControl AS DWORD _                        ' in
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION SetUrlCacheEntryInfo LIB "WinINet.dll" _
   ALIAS "SetUrlCacheEntryInfoA" _
   ( _
    lpszUrlName          AS ASCIIZ, _                      ' in
    lpCacheEntryInfo     AS INTERNET_CACHE_ENTRY_INFO, _   ' in
    BYVAL dwFieldControl AS DWORD _                        ' in
   ) _
   AS LONG
#ENDIF

'
' Cache Group Functions
'

DECLARE FUNCTION CreateUrlCacheGroup LIB "WinINet.dll" _
   ALIAS "CreateUrlCacheGroup" _
   ( _
    BYVAL dwFlags AS DWORD, _    ' in
    BYVAL lpReserved AS DWORD _  ' must pass %NULL
   ) _
   AS QUAD

DECLARE FUNCTION DeleteUrlCacheGroup LIB "WinINet.dll" _
   ALIAS "DeleteUrlCacheGroup" _
   ( _
    BYVAL GroupId AS QUAD, _     ' in
    BYVAL dwFlags AS DWORD, _    ' must pass 0
    BYVAL lpReserved AS DWORD _  ' must pass %NULL
   ) _
   AS LONG

' Flags for SetUrlCacheEntryGroup
%INTERNET_CACHE_GROUP_ADD      = 0
%INTERNET_CACHE_GROUP_REMOVE   = 1

DECLARE FUNCTION SetUrlCacheEntryGroupA LIB "WinINet.dll" _
   ALIAS "SetUrlCacheEntryGroupA" _
   ( _
    lpszUrlName             AS ASCIIZ, _   ' in
    BYVAL dwFlags           AS DWORD, _    ' in
    BYVAL GroupId           AS QUAD, _     ' in
    pbGroupAttributes       AS DWORD, _    ' must pass %NULL
    BYVAL cbGroupAttributes AS DWORD, _    ' must pass 0
    BYVAL lpReserved        AS DWORD _     ' must pass %NULL
   ) _
   AS LONG

DECLARE FUNCTION SetUrlCacheEntryGroupW LIB "WinINet.dll" _
   ALIAS "SetUrlCacheEntryGroupW" _
   ( _
    lpszUrlName             AS WSTRINGZ, _ ' in
    BYVAL dwFlags           AS DWORD, _    ' in
    BYVAL GroupId           AS QUAD, _     ' in
    pbGroupAttributes       AS DWORD, _    ' must pass %NULL
    BYVAL cbGroupAttributes AS DWORD, _    ' must pass 0
    BYVAL lpReserved        AS DWORD _     ' must pass %NULL
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetUrlCacheEntryGroup LIB "WinINet.dll" _
   ALIAS "SetUrlCacheEntryGroupW" _
   ( _
    lpszUrlName             AS WSTRINGZ, _ ' in
    BYVAL dwFlags           AS DWORD, _    ' in
    BYVAL GroupId           AS QUAD, _     ' in
    pbGroupAttributes       AS DWORD, _    ' must pass %NULL
    BYVAL cbGroupAttributes AS DWORD, _    ' must pass 0
    BYVAL lpReserved        AS DWORD _     ' must pass %NULL
   ) _
   AS LONG
#ELSEIF %DEF(%WINX32)
DECLARE FUNCTION SetUrlCacheEntryGroup LIB "WinINet.dll" _
   ALIAS "SetUrlCacheEntryGroupA" _
   ( _
    lpszUrlName             AS ASCIIZ, _   ' in
    BYVAL dwFlags           AS DWORD, _    ' in
    BYVAL GroupId           AS QUAD, _     ' in
    pbGroupAttributes       AS DWORD, _    ' must pass %NULL
    BYVAL cbGroupAttributes AS DWORD, _    ' must pass 0
    BYVAL lpReserved        AS DWORD _     ' must pass %NULL
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION SetUrlCacheEntryGroup LIB "WinINet.dll" _
   ALIAS "SetUrlCacheEntryGroup" _
   ( _
    lpszUrlName             AS ASCIIZ, _   ' in
    BYVAL dwFlags           AS DWORD, _    ' in
    BYVAL GroupId           AS QUAD, _     ' in
    pbGroupAttributes       AS DWORD, _    ' must pass %NULL
    BYVAL cbGroupAttributes AS DWORD, _    ' must pass 0
    BYVAL lpReserved        AS DWORD _     ' must pass %NULL
   ) _
   AS LONG
#ENDIF

DECLARE FUNCTION FindFirstUrlCacheEntryExA LIB "WinINet.dll" _
   ALIAS "FindFirstUrlCacheEntryExA" _
   ( _
    lpszUrlSearchPattern              AS ASCIIZ, _  ' in
    BYVAL dwFlags                     AS DWORD, _   ' in
    BYVAL dwFilter                    AS DWORD, _   ' in
    BYVAL GroupId                     AS QUAD, _    ' in
    lpFirstCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFO, _  ' out
    lpdwFirstCacheEntryInfoBufferSize AS DWORD, _   ' in, out
    BYVAL lpGroupAttributes           AS DWORD, _   ' must pass %NULL
    BYVAL pcbGroupAttributes          AS DWORD, _   ' must pass %NULL
    BYVAL lpReserved                  AS DWORD _    ' must pass %NULL
   ) _
   AS LONG

DECLARE FUNCTION FindFirstUrlCacheEntryExW LIB "WinINet.dll" _
   ALIAS "FindFirstUrlCacheEntryExW" _
   ( _
    lpszUrlSearchPattern              AS WSTRINGZ, _ ' in
    BYVAL dwFlags                     AS DWORD, _   ' in
    BYVAL dwFilter                    AS DWORD, _   ' in
    BYVAL GroupId                     AS QUAD, _    ' in
    lpFirstCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFO, _  ' out
    lpdwFirstCacheEntryInfoBufferSize AS DWORD, _   ' in, out
    BYVAL lpGroupAttributes           AS DWORD, _   ' must pass %NULL
    BYVAL pcbGroupAttributes          AS DWORD, _   ' must pass %NULL
    BYVAL lpReserved                  AS DWORD _    ' must pass %NULL
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION FindFirstUrlCacheEntryEx LIB "WinINet.dll" _
   ALIAS "FindFirstUrlCacheEntryExW" _
   ( _
    lpszUrlSearchPattern              AS WSTRINGZ, _ ' in
    BYVAL dwFlags                     AS DWORD, _   ' in
    BYVAL dwFilter                    AS DWORD, _   ' in
    BYVAL GroupId                     AS QUAD, _    ' in
    lpFirstCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFO, _  ' out
    lpdwFirstCacheEntryInfoBufferSize AS DWORD, _   ' in, out
    BYVAL lpGroupAttributes           AS DWORD, _   ' must pass %NULL
    BYVAL pcbGroupAttributes          AS DWORD, _   ' must pass %NULL
    BYVAL lpReserved                  AS DWORD _    ' must pass %NULL
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION FindFirstUrlCacheEntryEx LIB "WinINet.dll" _
   ALIAS "FindFirstUrlCacheEntryExA" _
   ( _
    lpszUrlSearchPattern              AS ASCIIZ, _  ' in
    BYVAL dwFlags                     AS DWORD, _   ' in
    BYVAL dwFilter                    AS DWORD, _   ' in
    BYVAL GroupId                     AS QUAD, _    ' in
    lpFirstCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFO, _  ' out
    lpdwFirstCacheEntryInfoBufferSize AS DWORD, _   ' in, out
    BYVAL lpGroupAttributes           AS DWORD, _   ' must pass %NULL
    BYVAL pcbGroupAttributes          AS DWORD, _   ' must pass %NULL
    BYVAL lpReserved                  AS DWORD _    ' must pass %NULL
   ) _
   AS LONG
#ENDIF

DECLARE FUNCTION FindNextUrlCacheEntryExA LIB "WinINet.dll" _
   ALIAS "FindNextUrlCacheEntryExA" _
   ( _
    BYVAL hEnumHandle                 AS DWORD, _   ' in
    lpFirstCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFOA, _  ' out
    lpdwFirstCacheEntryInfoBufferSize AS DWORD, _   ' in, out
    BYVAL lpGroupAttributes           AS DWORD, _   ' must pass %NULL
    BYVAL pcbGroupAttributes          AS DWORD, _   ' must pass %NULL
    BYVAL lpReserved                  AS DWORD _    ' must pass %NULL
   ) _
   AS LONG

DECLARE FUNCTION FindNextUrlCacheEntryExW LIB "WinINet.dll" _
   ALIAS "FindNextUrlCacheEntryExW" _
   ( _
    BYVAL hEnumHandle                 AS DWORD, _   ' in
    lpFirstCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFOW, _  ' out
    lpdwFirstCacheEntryInfoBufferSize AS DWORD, _   ' in, out
    BYVAL lpGroupAttributes           AS DWORD, _   ' must pass %NULL
    BYVAL pcbGroupAttributes          AS DWORD, _   ' must pass %NULL
    BYVAL lpReserved                  AS DWORD _    ' must pass %NULL
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION FindNextUrlCacheEntryEx LIB "WinINet.dll" _
   ALIAS "FindNextUrlCacheEntryExW" _
   ( _
    BYVAL hEnumHandle                 AS DWORD, _   ' in
    lpFirstCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFOW, _  ' out
    lpdwFirstCacheEntryInfoBufferSize AS DWORD, _   ' in, out
    BYVAL lpGroupAttributes           AS DWORD, _   ' must pass %NULL
    BYVAL pcbGroupAttributes          AS DWORD, _   ' must pass %NULL
    BYVAL lpReserved                  AS DWORD _    ' must pass %NULL
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION FindNextUrlCacheEntryEx LIB "WinINet.dll" _
   ALIAS "FindNextUrlCacheEntryExA" _
   ( _
    BYVAL hEnumHandle                 AS DWORD, _   ' in
    lpFirstCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFOA, _  ' out
    lpdwFirstCacheEntryInfoBufferSize AS DWORD, _   ' in, out
    BYVAL lpGroupAttributes           AS DWORD, _   ' must pass %NULL
    BYVAL pcbGroupAttributes          AS DWORD, _   ' must pass %NULL
    BYVAL lpReserved                  AS DWORD _    ' must pass %NULL
   ) _
   AS LONG
#ENDIF

DECLARE FUNCTION FindFirstUrlCacheEntryA LIB "WinINet.dll" _
   ALIAS "FindFirstUrlCacheEntryA" _
   ( _
    lpszUrlSearchPattern              AS ASCIIZ, _   ' in
    lpFirstCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFOA, _  ' out
    lpdwFirstCacheEntryInfoBufferSize AS DWORD _     ' in, out
   ) _
   AS LONG

DECLARE FUNCTION FindFirstUrlCacheEntryW LIB "WinINet.dll" _
   ALIAS "FindFirstUrlCacheEntryW" _
   ( _
    lpszUrlSearchPattern              AS WSTRINGZ, _   ' in
    lpFirstCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFOW, _  ' out
    lpdwFirstCacheEntryInfoBufferSize AS DWORD _     ' in, out
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION FindFirstUrlCacheEntry LIB "WinINet.dll" _
   ALIAS "FindFirstUrlCacheEntryW" _
   ( _
    lpszUrlSearchPattern              AS WSTRINGZ, _   ' in
    lpFirstCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFOW, _  ' out
    lpdwFirstCacheEntryInfoBufferSize AS DWORD _     ' in, out
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION FindFirstUrlCacheEntry LIB "WinINet.dll" _
   ALIAS "FindFirstUrlCacheEntryA" _
   ( _
    lpszUrlSearchPattern              AS ASCIIZ, _   ' in
    lpFirstCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFOA, _  ' out
    lpdwFirstCacheEntryInfoBufferSize AS DWORD _     ' in, out
   ) _
   AS LONG
#ENDIF

DECLARE FUNCTION FindNextUrlCacheEntryA LIB "WinINet.dll" _
   ALIAS "FindNextUrlCacheEntryA" _
   ( _
    BYVAL hEnumHandle                AS DWORD, _    ' in
    lpNextCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFOA, _   ' out
    lpdwNextCacheEntryInfoBufferSize AS DWORD _     ' in, out
   ) _
   AS LONG

DECLARE FUNCTION FindNextUrlCacheEntryW LIB "WinINet.dll" _
   ALIAS "FindNextUrlCacheEntryW" _
   ( _
    BYVAL hEnumHandle                AS DWORD, _    ' in
    lpNextCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFOW, _   ' out
    lpdwNextCacheEntryInfoBufferSize AS DWORD _     ' in, out
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION FindNextUrlCacheEntry LIB "WinINet.dll" _
   ALIAS "FindNextUrlCacheEntryW" _
   ( _
    BYVAL hEnumHandle                AS DWORD, _    ' in
    lpNextCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFOW, _   ' out
    lpdwNextCacheEntryInfoBufferSize AS DWORD _     ' in, out
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION FindNextUrlCacheEntry LIB "WinINet.dll" _
   ALIAS "FindNextUrlCacheEntryA" _
   ( _
    BYVAL hEnumHandle                AS DWORD, _    ' in
    lpNextCacheEntryInfo             AS INTERNET_CACHE_ENTRY_INFOA, _   ' out
    lpdwNextCacheEntryInfoBufferSize AS DWORD _     ' in, out
   ) _
   AS LONG
#ENDIF

DECLARE FUNCTION FindCloseUrlCache LIB "WinINet.dll" _
   ALIAS "FindCloseUrlCache" _
   ( _
    BYVAL hEnumHandle AS DWORD _       ' in
   ) _
   AS LONG

DECLARE FUNCTION DeleteUrlCacheEntryA LIB "WinINet.dll" _
   ALIAS "DeleteUrlCacheEntryA" _
   ( _
    lpszUrlName AS ASCIIZ _            ' in
   ) _
   AS LONG

DECLARE FUNCTION DeleteUrlCacheEntryW LIB "WinINet.dll" _
   ALIAS "DeleteUrlCacheEntryW" _
   ( _
    lpszUrlName AS WSTRINGZ _          ' in
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION DeleteUrlCacheEntry LIB "WinINet.dll" _
   ALIAS "DeleteUrlCacheEntryW" _
   ( _
    lpszUrlName AS WSTRINGZ _          ' in
   ) _
   AS LONG
#ELSEIF %DEF(%WINX32)
DECLARE FUNCTION DeleteUrlCacheEntry LIB "WinINet.dll" _
   ALIAS "DeleteUrlCacheEntryA" _
   ( _
    lpszUrlName AS ASCIIZ _            ' in
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION DeleteUrlCacheEntry LIB "WinINet.dll" _
   ALIAS "DeleteUrlCacheEntry" _
   ( _
    lpszUrlName AS ASCIIZ _            ' in
   ) _
   AS LONG

#ENDIF

'
' Autodial APIs
'

DECLARE FUNCTION InternetDialA LIB "WinINet.dll" _
   ALIAS "InternetDialA" _
   ( _
    BYVAL hwndParent AS DWORD, _    ' in
    lpszConnectoid   AS ASCIIZ, _   ' in
    BYVAL dwFlags    AS DWORD, _    ' in
    lpdwConnection   AS DWORD, _    ' out
    BYVAL dwReserved AS DWORD _     ' in
   ) _
   AS DWORD

DECLARE FUNCTION InternetDialW LIB "WinINet.dll" _
   ALIAS "InternetDialW" _
   ( _
    BYVAL hwndParent AS DWORD, _    ' in
    lpszConnectoid   AS WSTRINGZ, _ ' in
    BYVAL dwFlags    AS DWORD, _    ' in
    lpdwConnection   AS DWORD, _    ' out
    BYVAL dwReserved AS DWORD _     ' in
   ) _
   AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetDial LIB "WinINet.dll" _
   ALIAS "InternetDialW" _
   ( _
    BYVAL hwndParent AS DWORD, _    ' in
    lpszConnectoid   AS WSTRINGZ, _ ' in
    BYVAL dwFlags    AS DWORD, _    ' in
    lpdwConnection   AS DWORD, _    ' out
    BYVAL dwReserved AS DWORD _     ' in
   ) _
   AS DWORD
#ELSEIF %DEF(%WINX32)
DECLARE FUNCTION InternetDial LIB "WinINet.dll" _
   ALIAS "InternetDialA" _
   ( _
    BYVAL hwndParent AS DWORD, _    ' in
    lpszConnectoid   AS ASCIIZ, _   ' in
    BYVAL dwFlags    AS DWORD, _    ' in
    lpdwConnection   AS DWORD, _    ' out
    BYVAL dwReserved AS DWORD _     ' in
   ) _
   AS DWORD
#ELSE
DECLARE FUNCTION InternetDial LIB "WinINet.dll" _
   ALIAS "InternetDial" _
   ( _
    BYVAL hwndParent AS DWORD, _    ' in
    lpszConnectoid   AS ASCIIZ, _   ' in
    BYVAL dwFlags    AS DWORD, _    ' in
    lpdwConnection   AS DWORD, _    ' out
    BYVAL dwReserved AS DWORD _     ' in
   ) _
   AS DWORD
#ENDIF

' Flags for InternetDial - must not conflict with InternetAutodial flags
'                          as they are valid here also.

%INTERNET_DIAL_FORCE_PROMPT = &H2000
%INTERNET_DIAL_SHOW_OFFLINE = &H4000
%INTERNET_DIAL_UNATTENDED   = &H8000??

DECLARE FUNCTION InternetHangUp LIB "WinINet.dll" _
   ALIAS "InternetHangUp" _
   ( _
    BYVAL dwConnection AS DWORD, _     ' in
    BYVAL dwReserved   AS DWORD _      ' in
   ) _
   AS DWORD

%INTERENT_GOONLINE_REFRESH = &H00000001
%INTERENT_GOONLINE_MASK    = &H00000001

DECLARE FUNCTION InternetGoOnlineA LIB "WinINet.dll" _
   ALIAS "InternetGoOnlineA" _
   ( _
    lpszURL          AS ASCIIZ, _   ' in
    BYVAL hwndParent AS DWORD, _    ' in
    BYVAL dwFlags    AS DWORD _     ' in
   ) _
   AS LONG

DECLARE FUNCTION InternetGoOnlineW LIB "WinINet.dll" _
   ALIAS "InternetGoOnlineW" _
   ( _
    lpszURL          AS WSTRINGZ, _ ' in
    BYVAL hwndParent AS DWORD, _    ' in
    BYVAL dwFlags    AS DWORD _     ' in
   ) _
   AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetGoOnline LIB "WinINet.dll" _
   ALIAS "InternetGoOnlineW" _
   ( _
    lpszURL          AS WSTRINGZ, _ ' in
    BYVAL hwndParent AS DWORD, _    ' in
    BYVAL dwFlags    AS DWORD _     ' in
   ) _
   AS LONG
#ELSEIF %DEF(%WINX32)
DECLARE FUNCTION InternetGoOnline LIB "WinINet.dll" _
   ALIAS "InternetGoOnlineA" _
   ( _
    lpszURL          AS ASCIIZ, _   ' in
    BYVAL hwndParent AS DWORD, _    ' in
    BYVAL dwFlags    AS DWORD _     ' in
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION InternetGoOnline LIB "WinINet.dll" _
   ALIAS "InternetGoOnline" _
   ( _
    lpszURL          AS ASCIIZ, _   ' in
    BYVAL hwndParent AS DWORD, _    ' in
    BYVAL dwFlags    AS DWORD _     ' in
   ) _
   AS LONG
#ENDIF

DECLARE FUNCTION InternetAutodial LIB "WinINet.dll" _
   ALIAS "InternetAutodial" _
   ( _
    BYVAL dwFlags    AS DWORD, _    ' in
    BYVAL dwReserved AS DWORD _     ' in
   ) _
   AS LONG

' Flags for InternetAutodial
%INTERNET_AUTODIAL_FORCE_ONLINE         = 1
%INTERNET_AUTODIAL_FORCE_UNATTENDED     = 2
%INTERNET_AUTODIAL_FAILIFSECURITYCHECK  = 4
%INTERNET_AUTODIAL_OVERRIDE_NET_PRESENT = 8

%INTERNET_AUTODIAL_FLAGS_MASK = %INTERNET_AUTODIAL_FORCE_ONLINE _
                             OR %INTERNET_AUTODIAL_FORCE_UNATTENDED _
                             OR %INTERNET_AUTODIAL_FAILIFSECURITYCHECK _
                             OR %INTERNET_AUTODIAL_OVERRIDE_NET_PRESENT

DECLARE FUNCTION InternetAutodialHangup LIB "WinINet.dll" _
   ALIAS "InternetAutodialHangup" _
   ( _
    BYVAL dwReserved AS DWORD _        ' in
   ) _
   AS LONG

DECLARE FUNCTION InternetGetConnectedState LIB "WinINet.dll" _
   ALIAS "InternetGetConnectedState" _
   ( _
    lpdwFlags        AS DWORD, _       ' out
    BYVAL dwReserved AS DWORD _        ' in
   ) _
   AS LONG

DECLARE FUNCTION InternetGetConnectedStateExA LIB "WinINet.dll" _
   ALIAS "InternetGetConnectedStateExA" _
   ( _
    lpdwFlags          AS DWORD, _     ' out
    lpszConnectionName AS ASCIIZ, _    ' out
    BYVAL dwNameLen    AS DWORD, _     ' in
    BYVAL dwReserved   AS DWORD _      ' in
   ) AS LONG  ' BOOL

DECLARE FUNCTION InternetGetConnectedStateExW LIB "WinINet.dll" _
   ALIAS "InternetGetConnectedStateExW" _
   ( _
    lpdwFlags          AS DWORD, _     ' out
    lpszConnectionName AS WSTRINGZ, _  ' out
    BYVAL dwNameLen    AS DWORD, _     ' in
    BYVAL dwReserved   AS DWORD _      ' in
   ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetGetConnectedStateEx LIB "WinINet.dll" _
   ALIAS "InternetGetConnectedStateExW" _
   ( _
    lpdwFlags          AS DWORD, _     ' out
    lpszConnectionName AS WSTRINGZ, _  ' out
    BYVAL dwNameLen    AS DWORD, _     ' in
    BYVAL dwReserved   AS DWORD _      ' in
   ) AS LONG  ' BOOL
#ELSEIF %DEF(%WINX32)
DECLARE FUNCTION InternetGetConnectedStateEx LIB "WinINet.dll" _
   ALIAS "InternetGetConnectedStateExA" _
   ( _
    lpdwFlags          AS DWORD, _     ' out
    lpszConnectionName AS ASCIIZ, _    ' out
    BYVAL dwNameLen    AS DWORD, _     ' in
    BYVAL dwReserved   AS DWORD _      ' in
   ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION InternetGetConnectedStateEx LIB "WinINet.dll" _
   ALIAS "InternetGetConnectedStateEx" _
   ( _
    lpdwFlags          AS DWORD, _     ' out
    lpszConnectionName AS ASCIIZ, _    ' out
    BYVAL dwNameLen    AS DWORD, _     ' in
    BYVAL dwReserved   AS DWORD _      ' in
   ) AS LONG  ' BOOL
#ENDIF

%PROXY_AUTO_DETECT_TYPE_DHCP  = 1
%PROXY_AUTO_DETECT_TYPE_DNS_A = 2

'struct AutoProxyHelperFunctions;
'
'typedef struct AutoProxyHelperVtbl
'{
'    BOOL ( __stdcall *IsResolvable )(
'            LPSTR   lpszHost);
'
'    DWORD ( __stdcall *GetIPAddress )(
'           LPSTR   lpszIPAddress,
'           LPDWORD lpdwIPAddressSize);
'
'    DWORD ( __stdcall *ResolveHostName )(
'           LPSTR   lpszHostName,
'           LPSTR   lpszIPAddress,
'           LPDWORD lpdwIPAddressSize);
'
'    BOOL ( __stdcall *IsInNet )(
'            LPSTR   lpszIPAddress,
'            LPSTR   lpszDest,
'            LPSTR   lpszMask);
'
'    BOOL ( __stdcall *IsResolvableEx )(
'            LPSTR lpszHost
'        );
'
'    DWORD ( __stdcall *GetIPAddressEx )(
'            LPSTR     lpszIPAddress,
'            LPDWORD lpdwIPAddressSize
'        );
'
'    DWORD ( __stdcall *ResolveHostNameEx )(
'            LPSTR lpszHostName,
'            LPSTR lpszIPAddress,
'            LPDWORD lpdwIPAddressSize
'        );
'
'    BOOL ( __stdcall *IsInNetEx )(
'            LPSTR lpszIPAddress,
'            LPSTR lpszIPPrefix
'        );
'
'    DWORD ( __stdcall *SortIpList )(
'            LPSTR lpszIPAddressList,
'            LPSTR lpszIPSortedList,
'            LPDWORD lpdwIPSortedListSize
'        );
'
'
'}AutoProxyHelperVtbl;

TYPE AUTO_PROXY_SCRIPT_BUFFER
    dwStructSize       AS DWORD       ' Size of struct
    lpszScriptBuffer   AS ASCIIZ PTR  ' Buffer to Pass
    dwScriptBufferSize AS DWORD       ' Size of buffer above
END TYPE

'type AutoProxyHelperFunctions
'    lpVtbl as AutoProxyHelperVtbl ptr
'end type


DECLARE FUNCTION pfnInternetInitializeAutoProxyDll ( _
    BYVAL dwVersion            AS DWORD, _
    lpszDownloadedTempFile     AS ASCIIZ, _
    lpszMime                   AS ASCIIZ, _
    BYVAL lpAutoProxyCallbacks AS DWORD, _ ' AutoProxyHelperFunctions*
    lpAutoProxyScriptBuffer    AS AUTO_PROXY_SCRIPT_BUFFER _
    ) AS LONG  ' BOOL

DECLARE FUNCTION pfnInternetDeInitializeAutoProxyDll ( _
    lpszMime         AS ASCIIZ, _
    BYVAL dwReserved AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION pfnInternetGetProxyInfo ( _
    lpszUrl                   AS ASCIIZ, _
    BYVAL dwUrlLength         AS DWORD, _
    lpszUrlHostName           AS ASCIIZ, _
    BYVAL dwUrlHostNameLength AS DWORD, _
    lplpszProxyHostName       AS ANY, _  ' LPSTR *
    lpdwProxyHostNameLength   AS DWORD _
    ) AS LONG  ' BOOL

MACRO WPAD_CACHE_DELETE_enum=LONG
ENUM WPAD_CACHE_DELETE SINGULAR
    WPAD_CACHE_DELETE_CURRENT
    WPAD_CACHE_DELETE_ALL
END ENUM

DECLARE FUNCTION DeleteWpadCacheForNetworks LIB "WinINet.dll" _
    ALIAS "DeleteWpadCacheForNetworks" ( _
    BYVAL wpcd AS WPAD_CACHE_DELETE_enum _
    ) AS LONG  ' BOOL

DECLARE FUNCTION InternetInitializeAutoProxyDll LIB "WinINet.dll" _
    ALIAS "InternetInitializeAutoProxyDll" ( _
    BYVAL dwReserved AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION DetectAutoProxyUrl LIB "WinINet.dll" _
    ALIAS "DetectAutoProxyUrl" ( _
    lpszAutoProxyUrl           AS ASCIIZ, _
    BYVAL dwAutoProxyUrlLength AS DWORD, _
    BYVAL dwDetectFlags        AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION CreateMD5SSOHash LIB "WinINet.dll" _
    ALIAS "CreateMD5SSOHash" ( _
    pszChallengeInfo AS WSTRINGZ, _
    pwszRealm        AS WSTRINGZ, _
    pwszTarget       AS WSTRINGZ, _
    BYVAL pbHexHash AS BYTE PTR _
    ) AS LONG  ' BOOL


' Flags for InternetGetConnectedState
%INTERNET_CONNECTION_MODEM       = &H01
%INTERNET_CONNECTION_LAN         = &H02
%INTERNET_CONNECTION_PROXY       = &H04
%INTERNET_CONNECTION_MODEM_BUSY  = &H08  ' no longer used
%INTERNET_RAS_INSTALLED          = &H10
%INTERNET_CONNECTION_OFFLINE     = &H20
%INTERNET_CONNECTION_CONFIGURED  = &H40

'
' Custom dial handler functions
'

' Custom dial handler prototype
'DECLARE FUNCTION PFN_DIAL_HANDLERA (BYVAL DWORD, ASCIIZ, BYVAL DWORD, DWORD) _
'    AS DWORD
'DECLARE FUNCTION PFN_DIAL_HANDLERW (BYVAL DWORD, WSTRINGZ, BYVAL DWORD, _
'    DWORD) AS DWORD
'#IF %DEF(%UNICODE)
'MACRO PFN_DIAL_HANDLER=PFN_DIAL_HANDLERW
'#ELSE
'MACRO PFN_DIAL_HANDLER=PFN_DIAL_HANDLERA
'#ENDIF


' Flags for custom dial handler
%INTERNET_CUSTOMDIAL_CONNECT     = 0
%INTERNET_CUSTOMDIAL_UNATTENDED  = 1
%INTERNET_CUSTOMDIAL_DISCONNECT  = 2
%INTERNET_CUSTOMDIAL_SHOWOFFLINE = 4

' Custom dial handler supported functionality flags
%INTERNET_CUSTOMDIAL_SAFE_FOR_UNATTENDED = 1
%INTERNET_CUSTOMDIAL_WILL_SUPPLY_STATE   = 2
%INTERNET_CUSTOMDIAL_CAN_HANGUP          = 4

DECLARE FUNCTION InternetSetDialStateA LIB "WinINet.dll" _
   ALIAS "InternetSetDialStateA" _
   ( _
    lpszConnectoid   AS ASCIIZ, _   ' in
    BYVAL dwState    AS DWORD, _    ' in
    BYVAL dwReserved AS DWORD _     ' in
   ) AS LONG  ' BOOL

DECLARE FUNCTION InternetSetDialStateW LIB "WinINet.dll" _
   ALIAS "InternetSetDialStateW" _
   ( _
    lpszConnectoid   AS WSTRINGZ, _ ' in
    BYVAL dwState    AS DWORD, _    ' in
    BYVAL dwReserved AS DWORD _     ' in
   ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetSetDialState LIB "WinINet.dll" _
   ALIAS "InternetSetDialStateW" _
   ( _
    lpszConnectoid   AS WSTRINGZ, _ ' in
    BYVAL dwState    AS DWORD, _    ' in
    BYVAL dwReserved AS DWORD _     ' in
   ) AS LONG  ' BOOL
#ELSEIF %DEF(%WINX32)
DECLARE FUNCTION InternetSetDialState LIB "WinINet.dll" _
   ALIAS "InternetSetDialStateA" _
   ( _
    lpszConnectoid   AS ASCIIZ, _   ' in
    BYVAL dwState    AS DWORD, _    ' in
    BYVAL dwReserved AS DWORD _     ' in
   ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION InternetSetDialState LIB "WinINet.dll" _
   ALIAS "InternetSetDialState" _
   ( _
    lpszConnectoid   AS ASCIIZ, _   ' in
    BYVAL dwState    AS DWORD, _    ' in
    BYVAL dwReserved AS DWORD _     ' in
   ) AS LONG  ' BOOL
#ENDIF


' States for InternetSetDialState
%INTERNET_DIALSTATE_DISCONNECTED = 1

DECLARE FUNCTION InternetSetPerSiteCookieDecisionA LIB "WinINet.dll" _
    ALIAS "InternetSetPerSiteCookieDecisionA" ( _
    pszHostName      AS ASCIIZ, _   ' in
    BYVAL dwDecision AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION InternetSetPerSiteCookieDecisionW LIB "WinINet.dll" _
    ALIAS "InternetSetPerSiteCookieDecisionW" ( _
    pszHostName      AS WSTRINGZ, _   ' in
    BYVAL dwDecision AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetSetPerSiteCookieDecision LIB "WinINet.dll" _
    ALIAS "InternetSetPerSiteCookieDecisionW" ( _
    pszHostName      AS WSTRINGZ, _   ' in
    BYVAL dwDecision AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION InternetSetPerSiteCookieDecision LIB "WinINet.dll" _
    ALIAS "InternetSetPerSiteCookieDecisionA" ( _
    pszHostName      AS ASCIIZ, _   ' in
    BYVAL dwDecision AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

DECLARE FUNCTION InternetGetPerSiteCookieDecisionA LIB "WinINet.dll" _
    ALIAS "InternetGetPerSiteCookieDecisionA" ( _
    pResult AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION InternetGetPerSiteCookieDecisionW LIB "WinINet.dll" _
    ALIAS "InternetGetPerSiteCookieDecisionW" ( _
    pResult AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION InternetGetPerSiteCookieDecision LIB "WinINet.dll" _
    ALIAS "InternetGetPerSiteCookieDecisionW" ( _
    pResult AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION InternetGetPerSiteCookieDecision LIB "WinINet.dll" _
    ALIAS "InternetGetPerSiteCookieDecisionA" ( _
    pResult AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

DECLARE FUNCTION InternetClearAllPerSiteCookieDecisions LIB "WinINet.dll" _
   ALIAS "InternetClearAllPerSiteCookieDecisions" () AS LONG  ' BOOL

%INTERNET_IDENTITY_FLAG_PRIVATE_CACHE    = &H01
%INTERNET_IDENTITY_FLAG_SHARED_CACHE     = &H02
%INTERNET_IDENTITY_FLAG_CLEAR_DATA       = &H04
%INTERNET_IDENTITY_FLAG_CLEAR_COOKIES    = &H08
%INTERNET_IDENTITY_FLAG_CLEAR_HISTORY    = &H10
%INTERNET_IDENTITY_FLAG_CLEAR_CONTENT    = &H20

%INTERNET_SUPPRESS_RESET_ALL             = &H00
%INTERNET_SUPPRESS_COOKIE_POLICY         = &H01
%INTERNET_SUPPRESS_COOKIE_POLICY_RESET   = &H02

'
' Privacy settings values and APIs
'

%PRIVACY_TEMPLATE_NO_COOKIES   = 0
%PRIVACY_TEMPLATE_HIGH         = 1
%PRIVACY_TEMPLATE_MEDIUM_HIGH  = 2
%PRIVACY_TEMPLATE_MEDIUM       = 3
%PRIVACY_TEMPLATE_MEDIUM_LOW   = 4
%PRIVACY_TEMPLATE_LOW          = 5
%PRIVACY_TEMPLATE_CUSTOM       = 100
%PRIVACY_TEMPLATE_ADVANCED     = 101

%PRIVACY_TEMPLATE_MAX          = %PRIVACY_TEMPLATE_LOW

%PRIVACY_TYPE_FIRST_PARTY      = 0
%PRIVACY_TYPE_THIRD_PARTY      = 1

DECLARE FUNCTION PrivacySetZonePreferenceW LIB "WinINet.dll" _
    ALIAS "PrivacySetZonePreferenceW" ( _
    BYVAL dwZone     AS DWORD, _
    BYVAL dwType     AS DWORD, _
    BYVAL dwTemplate AS DWORD, _
    pszPreference    AS WSTRINGZ _
    ) AS DWORD

DECLARE FUNCTION PrivacyGetZonePreferenceW LIB "WinINet.dll" _
    ALIAS "PrivacyGetZonePreferenceW" ( _
    BYVAL dwZone    AS DWORD, _
    BYVAL dwType    AS DWORD, _
    pdwTemplate     AS DWORD, _
    pszBuffer       AS WSTRINGZ, _
    pdwBufferLength AS DWORD _
    ) AS DWORD
