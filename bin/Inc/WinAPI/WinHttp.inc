'------------------------------------------------------------------------------
'
'  WinHTTP.INC
'   Contains manifests, macros, types and prototypes for Windows HTTP Services
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last Update: 02 May 2011
'
'------------------------------------------------------------------------------
'  from WinHTTP.h dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WINHTTPX = 1

#INCLUDE "WinDef.inc"


%INTERNET_DEFAULT_PORT       = 0    ' use the protocol-specific default
%INTERNET_DEFAULT_HTTP_PORT  = 80   '    "     "  HTTP   "
%INTERNET_DEFAULT_HTTPS_PORT = 443  '    "     "  HTTPS  "

' flags for WinHttpOpen():
%WINHTTP_FLAG_ASYNC              = &H10000000  ' this session is asynchronous (where supported)

' flags for WinHttpOpenRequest():
%WINHTTP_FLAG_SECURE               = &H00800000  ' use SSL if applicable (HTTPS)
%WINHTTP_FLAG_ESCAPE_PERCENT       = &H00000004  ' if escaping enabled, escape percent as well
%WINHTTP_FLAG_NULL_CODEPAGE        = &H00000008  ' assume all symbols are ASCII, use fast convertion
%WINHTTP_FLAG_BYPASS_PROXY_CACHE   = &H00000100 ' add "pragma: no-cache" request header
%WINHTTP_FLAG_REFRESH              = %WINHTTP_FLAG_BYPASS_PROXY_CACHE
%WINHTTP_FLAG_ESCAPE_DISABLE       = &H00000040  ' disable escaping
%WINHTTP_FLAG_ESCAPE_DISABLE_QUERY = &H00000080  ' if escaping enabled escape path part, but do not escape query


%SECURITY_FLAG_IGNORE_UNKNOWN_CA        = &H00000100
%SECURITY_FLAG_IGNORE_CERT_DATE_INVALID = &H00002000 ' expired X509 Cert.
%SECURITY_FLAG_IGNORE_CERT_CN_INVALID   = &H00001000 ' bad common name in X509 Cert.
%SECURITY_FLAG_IGNORE_CERT_WRONG_USAGE  = &H00000200

'
' WINHTTP_ASYNC_RESULT - this structure is returned to the application via
' the callback with WINHTTP_CALLBACK_STATUS_REQUEST_COMPLETE. It is not sufficient to
' just return the result of the async operation. If the API failed then the
' app cannot call GetLastError() because the thread context will be incorrect.
' Both the value returned by the async API and any resultant error code are
' made available. The app need not check dwError if dwResult indicates that
' the API succeeded (in this case dwError will be %ERROR_SUCCESS)
'

TYPE WINHTTP_ASYNC_RESULT
    dwResult AS DWORD  ' the HINTERNET, DWORD or BOOL return code from an async API
    dwError  AS DWORD  ' the error code if the API failed
END TYPE


'
' HTTP_VERSION_INFO - query or set global HTTP version (1.0 or 1.1)
'

TYPE HTTP_VERSION_INFO
    dwMajorVersion AS DWORD
    dwMinorVersion AS DWORD
END TYPE


'
' INTERNET_SCHEME - URL scheme type
'

%INTERNET_SCHEME_HTTP  = 1
%INTERNET_SCHEME_HTTPS = 2


'
' URL_COMPONENTS - the constituent parts of an URL. Used in WinHttpCrackUrl()
' and WinHttpCreateUrl()
'
' For WinHttpCrackUrl(), if a pointer field and its corresponding length field
' are both 0 then that component is not returned. If the pointer field is %NULL
' but the length field is not zero, then both the pointer and length fields are
' returned if both pointer and corresponding length fields are non-zero then
' the pointer field points to a buffer where the component is copied. The
' component may be un-escaped, depending on dwFlags
'
' For WinHttpCreateUrl(), the pointer fields should be NULL if the component
' is not required. If the corresponding length field is zero then the pointer
' field is the address of a zero-terminated string. If the length field is not
' zero then it is the string length of the corresponding pointer field
'

TYPE URL_COMPONENTSW DWORD FILL
    dwStructSize      AS DWORD         ' size of this structure. Used in version check
    lpszScheme        AS WSTRINGZ PTR  ' pointer to scheme name
    dwSchemeLength    AS DWORD         ' length of scheme name
    nScheme           AS LONG          ' enumerated scheme type (if known)
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



'
' WINHTTP_PROXY_INFO - structure supplied with WINHTTP_OPTION_PROXY to get/
' set proxy information on a WinHttpOpen() handle
'

TYPE WINHTTP_PROXY_INFO
    dwAccessType    AS DWORD          ' see WINHTTP_ACCESS_* types below
    lpszProxy       AS WSTRINGZ PTR   ' proxy server list
    lpszProxyBypass AS WSTRINGZ PTR   ' proxy bypass list
END TYPE


TYPE WINHTTP_AUTOPROXY_OPTIONS
    dwFlags                AS DWORD
    dwAutoDetectFlags      AS DWORD
    lpszAutoConfigUrl      AS WSTRINGZ PTR
    lpvReserved            AS DWORD
    dwReserved             AS DWORD
    fAutoLogonIfChallenged AS LONG
END TYPE



%WINHTTP_AUTOPROXY_AUTO_DETECT         = &H00000001
%WINHTTP_AUTOPROXY_CONFIG_URL          = &H00000002
%WINHTTP_AUTOPROXY_HOST_KEEPCASE       = &H00000004
%WINHTTP_AUTOPROXY_HOST_LOWERCASE      = &H00000008
%WINHTTP_AUTOPROXY_RUN_INPROCESS       = &H00010000
%WINHTTP_AUTOPROXY_RUN_OUTPROCESS_ONLY = &H00020000
'
' Flags for dwAutoDetectFlags
'
%WINHTTP_AUTO_DETECT_TYPE_DHCP         = &H00000001
%WINHTTP_AUTO_DETECT_TYPE_DNS_A        = &H00000002


'
' WINHTTP_CERTIFICATE_INFO lpBuffer - contains the certificate returned from
' the server
'

TYPE WINHTTP_CERTIFICATE_INFO
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
    '  doing encryption over the secure channel (SSL) connection.
    '

    lpszEncryptionAlgName AS WSTRINGZ PTR

    '
    ' dwKeySize - size of the key.
    '

    dwKeySize AS DWORD

END TYPE



DECLARE FUNCTION WinHttpTimeFromSystemTime LIB "WinHTTP.DLL" _
    ALIAS "WinHttpTimeFromSystemTime" _
    ( _
    pst      AS SYSTEMTIME, _   ' input GMT time
    pwszTime AS WSTRING _       ' output string buffer
    ) AS LONG


'
' constants for WinHttpTimeFromSystemTime
'

%WINHTTP_TIME_FORMAT_BUFSIZE = 62

DECLARE FUNCTION WinHttpTimeToSystemTime LIB "WinHTTP.DLL" _
    ALIAS "WinHttpTimeToSystemTime" _
    ( _
    pwszTime AS WSTRINGZ, _     ' NULL terminated string
    pst      AS SYSTEMTIME _    ' output in GMT time
    ) AS LONG


'
' flags for CrackUrl() and CombineUrl()
'

%ICU_NO_ENCODE          = &H20000000 ' Don't convert unsafe characters to escape sequence
%ICU_DECODE             = &H10000000 ' Convert %XX escape sequences to characters
%ICU_NO_META            = &H08000000 ' Don't convert .. etc. meta path sequences
%ICU_ENCODE_SPACES_ONLY = &H04000000 ' Encode spaces only
%ICU_BROWSER_MODE       = &H02000000 ' Special encode/decode rules for browser
%ICU_ENCODE_PERCENT     = &H00001000 ' Encode any percent (ASCII25) signs encountered, default is to not encode percent.


DECLARE FUNCTION WinHttpCrackUrl LIB "WinHTTP.DLL" ALIAS "WinHttpCrackUrl" _
    ( _
    pwszUrl AS WSTRINGZ, _
    BYVAL dwUrlLength AS DWORD, _
    BYVAL dwFlags AS DWORD, _
    lpUrlComponents AS URL_COMPONENTSW _
    ) AS LONG

DECLARE FUNCTION WinHttpCreateUrl LIB "WinHTTP.DLL" ALIAS "WinHttpCreateUrl" _
    ( _
    lpUrlComponents AS URL_COMPONENTSW, _
    BYVAL dwFlags AS DWORD, _
    pwszUrl AS WSTRINGZ, _
    lpdwUrlLength AS DWORD _
    ) AS LONG

'
' flags for WinHttpCrackUrl() and WinHttpCreateUrl()
'

%ICU_ESCAPE           = &H80000000??? ' (un)escape URL characters
%ICU_ESCAPE_AUTHORITY = &H00002000    ' causes InternetCreateUrlA to escape chars in authority components (user, pwd, host)
%ICU_REJECT_USERPWD   = &H00004000    ' rejects usrls whick have username/pwd sections


DECLARE FUNCTION WinHttpCheckPlatform LIB "WinHTTP.DLL" _
    ALIAS "WinHttpCheckPlatform" () AS LONG


DECLARE FUNCTION WinHttpGetDefaultProxyConfiguration LIB "WinHTTP.DLL" _
    ALIAS "WinHttpGetDefaultProxyConfiguration" _
    (pProxyInfo AS WINHTTP_PROXY_INFO) AS LONG

DECLARE FUNCTION WinHttpSetDefaultProxyConfiguration LIB "WinHTTP.DLL" _
    ALIAS "WinHttpSetDefaultProxyConfiguration" _
    (pProxyInfo AS WINHTTP_PROXY_INFO) AS LONG


DECLARE FUNCTION WinHttpOpen LIB "WinHTTP.DLL" ALIAS "WinHttpOpen" _
    ( _
    pwszUserAgent AS WSTRINGZ, _
    BYVAL dwAccessType AS DWORD, _
    pwszProxyName AS WSTRINGZ, _
    pwszProxyBypass AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD _
    ) AS DWORD

' WinHttpOpen dwAccessType values (also for WINHTTP_PROXY_INFO::dwAccessType)
%WINHTTP_ACCESS_TYPE_DEFAULT_PROXY = 0
%WINHTTP_ACCESS_TYPE_NO_PROXY      = 1
%WINHTTP_ACCESS_TYPE_NAMED_PROXY   = 3

' WinHttpOpen prettifiers for optional parameters
%WINHTTP_NO_PROXY_NAME   = %NULL
%WINHTTP_NO_PROXY_BYPASS = %NULL

DECLARE FUNCTION WinHttpCloseHandle LIB "WinHTTP.DLL" _
    ALIAS "WinHttpCloseHandle" (BYVAL hInternet AS DWORD) AS LONG


DECLARE FUNCTION WinHttpConnect LIB "WinHTTP.DLL" ALIAS "WinHttpConnect" _
    ( _
    BYVAL hSession AS DWORD, _
    pswzServerName AS WSTRINGZ, _
    BYVAL nServerPort AS WORD, _
    BYVAL dwReserved AS DWORD _
    ) AS DWORD


DECLARE FUNCTION WinHttpReadData LIB "WinHTTP.DLL" ALIAS "WinHttpReadData" _
    ( _
    BYVAL hRequest AS DWORD, _
    BYVAL lpBuffer AS DWORD, _
    BYVAL dwNumberOfBytesToRead AS DWORD, _
    lpdwNumberOfBytesRead AS DWORD _
    ) AS LONG

DECLARE FUNCTION WinHttpWriteData LIB "WinHTTP.DLL" ALIAS "WinHttpWriteData" _
    ( _
    BYVAL hRequest AS DWORD, _
    BYVAL lpBuffer AS DWORD, _
    BYVAL dwNumberOfBytesToWrite AS DWORD, _
    lpdwNumberOfBytesWritten AS DWORD _
    ) AS LONG


DECLARE FUNCTION WinHttpQueryDataAvailable LIB "WinHTTP.DLL" _
    ALIAS "WinHttpQueryDataAvailable" _
    ( _
    BYVAL hRequest AS DWORD, _
    lpdwNumberOfBytesAvailable AS DWORD _
    ) AS LONG


DECLARE FUNCTION WinHttpQueryOption LIB "WinHTTP.DLL" _
    ALIAS "WinHttpQueryOption" _
    ( _
    BYVAL hInternet AS DWORD, _
    BYVAL dwOption AS DWORD, _
    BYVAL lpBuffer AS DWORD, _
    lpdwBufferLength AS DWORD _
    ) AS LONG

DECLARE FUNCTION WinHttpSetOption LIB "WinHTTP.DLL" ALIAS "WinHttpSetOption" _
    ( _
    BYVAL hInternet AS DWORD, _
    BYVAL dwOption AS DWORD, _
    BYVAL lpBuffer AS DWORD, _
    BYVAL dwBufferLength AS DWORD _
    ) AS LONG

DECLARE FUNCTION WinHttpSetTimeouts LIB "WinHTTP.DLL" _
    ALIAS "WinHttpSetTimeouts" _
    ( _
    BYVAL hInternet AS DWORD, _          ' Session/Request handle.
    BYVAL nResolveTimeout AS LONG, _
    BYVAL nConnectTimeout AS LONG, _
    BYVAL nSendTimeout AS LONG, _
    BYVAL nReceiveTimeout AS LONG _
    ) AS LONG

' [not documented. does not appear to be exported.]
'DECLARE FUNCTION WinHttpIsHostInProxyBypassList LIB "WinHTTP.DLL" _
'    ALIAS "WinHttpIsHostInProxyBypassList" _
'    ( _
'    pProxyInfo AS WINHTTP_PROXY_INFO, _
'    pwszHost AS WSTRINGZ, _
'    BYVAL tScheme AS LONG, _   ' INTERNET_SCHEME
'    BYVAL nPort AS LONG, _     ' INTERNET_PORT
'    pfIsInBypassList AS LONG _
'    ) AS DWORD

'
' options manifests for WinHttp{Query|Set}Option
'

%WINHTTP_OPTION_CALLBACK                     =  1
%WINHTTP_FIRST_OPTION                        = %WINHTTP_OPTION_CALLBACK

%WINHTTP_OPTION_RESOLVE_TIMEOUT              =  2
%WINHTTP_OPTION_CONNECT_TIMEOUT              =  3
%WINHTTP_OPTION_CONNECT_RETRIES              =  4
%WINHTTP_OPTION_SEND_TIMEOUT                 =  5
%WINHTTP_OPTION_RECEIVE_TIMEOUT              =  6
%WINHTTP_OPTION_RECEIVE_RESPONSE_TIMEOUT     =  7
%WINHTTP_OPTION_HANDLE_TYPE                  =  9
%WINHTTP_OPTION_READ_BUFFER_SIZE             = 12
%WINHTTP_OPTION_WRITE_BUFFER_SIZE            = 13
%WINHTTP_OPTION_PARENT_HANDLE                = 21
%WINHTTP_OPTION_EXTENDED_ERROR               = 24
%WINHTTP_OPTION_SECURITY_FLAGS               = 31
%WINHTTP_OPTION_SECURITY_CERTIFICATE_STRUCT  = 32
%WINHTTP_OPTION_URL                          = 34
%WINHTTP_OPTION_SECURITY_KEY_BITNESS         = 36
%WINHTTP_OPTION_PROXY                        = 38

%WINHTTP_OPTION_USER_AGENT                   = 41
%WINHTTP_OPTION_CONTEXT_VALUE                = 45
%WINHTTP_OPTION_CLIENT_CERT_CONTEXT          = 47
%WINHTTP_OPTION_REQUEST_PRIORITY             = 58
%WINHTTP_OPTION_HTTP_VERSION                 = 59
%WINHTTP_OPTION_DISABLE_FEATURE              = 63

%WINHTTP_OPTION_CODEPAGE                     = 68
%WINHTTP_OPTION_MAX_CONNS_PER_SERVER         = 73
%WINHTTP_OPTION_MAX_CONNS_PER_1_0_SERVER     = 74
%WINHTTP_OPTION_AUTOLOGON_POLICY             = 77
%WINHTTP_OPTION_SERVER_CERT_CONTEXT          = 78
%WINHTTP_OPTION_ENABLE_FEATURE               = 79
%WINHTTP_OPTION_WORKER_THREAD_COUNT          = 80
%WINHTTP_OPTION_PASSPORT_COBRANDING_TEXT     = 81
%WINHTTP_OPTION_PASSPORT_COBRANDING_URL      = 82
%WINHTTP_OPTION_CONFIGURE_PASSPORT_AUTH      = 83
%WINHTTP_OPTION_SECURE_PROTOCOLS             = 84
%WINHTTP_OPTION_ENABLETRACING                = 85
%WINHTTP_OPTION_PASSPORT_SIGN_OUT            = 86
%WINHTTP_OPTION_PASSPORT_RETURN_URL          = 87
%WINHTTP_OPTION_REDIRECT_POLICY              = 88
%WINHTTP_OPTION_MAX_HTTP_AUTOMATIC_REDIRECTS = 89
%WINHTTP_OPTION_MAX_HTTP_STATUS_CONTINUE     = 90
%WINHTTP_OPTION_MAX_RESPONSE_HEADER_SIZE     = 91
%WINHTTP_OPTION_MAX_RESPONSE_DRAIN_SIZE      = 92
%WINHTTP_OPTION_CONNECTION_INFO              = 93
%WINHTTP_OPTION_CLIENT_CERT_ISSUER_LIST      = 94
%WINHTTP_OPTION_SPN                          = 96

%WINHTTP_OPTION_GLOBAL_PROXY_CREDS           = 97
%WINHTTP_OPTION_GLOBAL_SERVER_CREDS          = 98

%WINHTTP_OPTION_UNLOAD_NOTIFY_EVENT           = 99
%WINHTTP_OPTION_REJECT_USERPWD_IN_URL         = 100
%WINHTTP_OPTION_USE_GLOBAL_SERVER_CREDENTIALS = 101

%WINHTTP_OPTION_RECEIVE_PROXY_CONNECT_RESPONSE = 103
%WINHTTP_OPTION_IS_PROXY_CONNECT_RESPONSE      = 104

%WINHTTP_OPTION_SERVER_SPN_USED              = 106
%WINHTTP_OPTION_PROXY_SPN_USED               = 107

%WINHTTP_OPTION_SERVER_CBT                   = 108

%WINHTTP_LAST_OPTION                         = %WINHTTP_OPTION_SERVER_CBT

%WINHTTP_OPTION_USERNAME                     = &H1000
%WINHTTP_OPTION_PASSWORD                     = &H1001
%WINHTTP_OPTION_PROXY_USERNAME               = &H1002
%WINHTTP_OPTION_PROXY_PASSWORD               = &H1003


' manifest value for WINHTTP_OPTION_MAX_CONNS_PER_SERVER and WINHTTP_OPTION_MAX_CONNS_PER_1_0_SERVER
%WINHTTP_CONNS_PER_SERVER_UNLIMITED    = &HFFFFFFFF???


' values for WINHTTP_OPTION_AUTOLOGON_POLICY
%WINHTTP_AUTOLOGON_SECURITY_LEVEL_MEDIUM  = 0
%WINHTTP_AUTOLOGON_SECURITY_LEVEL_LOW     = 1
%WINHTTP_AUTOLOGON_SECURITY_LEVEL_HIGH    = 2

%WINHTTP_AUTOLOGON_SECURITY_LEVEL_DEFAULT = %WINHTTP_AUTOLOGON_SECURITY_LEVEL_MEDIUM

' values for WINHTTP_OPTION_REDIRECT_POLICY
%WINHTTP_OPTION_REDIRECT_POLICY_NEVER                  = 0
%WINHTTP_OPTION_REDIRECT_POLICY_DISALLOW_HTTPS_TO_HTTP = 1
%WINHTTP_OPTION_REDIRECT_POLICY_ALWAYS                 = 2

%WINHTTP_OPTION_REDIRECT_POLICY_LAST    = %WINHTTP_OPTION_REDIRECT_POLICY_ALWAYS
%WINHTTP_OPTION_REDIRECT_POLICY_DEFAULT = %WINHTTP_OPTION_REDIRECT_POLICY_DISALLOW_HTTPS_TO_HTTP

%WINHTTP_DISABLE_PASSPORT_AUTH    = &H00000000
%WINHTTP_ENABLE_PASSPORT_AUTH     = &H10000000
%WINHTTP_DISABLE_PASSPORT_KEYRING = &H20000000
%WINHTTP_ENABLE_PASSPORT_KEYRING  = &H40000000


' values for WINHTTP_OPTION_DISABLE_FEATURE
%WINHTTP_DISABLE_COOKIES          = &H00000001
%WINHTTP_DISABLE_REDIRECTS        = &H00000002
%WINHTTP_DISABLE_AUTHENTICATION   = &H00000004
%WINHTTP_DISABLE_KEEP_ALIVE       = &H00000008

' values for WINHTTP_OPTION_ENABLE_FEATURE
%WINHTTP_ENABLE_SSL_REVOCATION           = &H00000001
%WINHTTP_ENABLE_SSL_REVERT_IMPERSONATION = &H00000002

' values for WINHTTP_OPTION_SPN
%WINHTTP_DISABLE_SPN_SERVER_PORT  = &H00000000
%WINHTTP_ENABLE_SPN_SERVER_PORT   = &H00000001
%WINHTTP_OPTION_SPN_MASK          = %WINHTTP_ENABLE_SPN_SERVER_PORT

TYPE WINHTTP_CREDS
    lpszUserName AS ASCIIZ PTR
    lpszPassword AS ASCIIZ PTR
    lpszRealm    AS ASCIIZ PTR
    dwAuthScheme AS DWORD
    lpszHostName AS ASCIIZ PTR
    dwPort       AS DWORD
END TYPE

' structure for WINHTTP_OPTION_GLOBAL_SERVER_CREDS and
' WINHTTP_OPTION_GLOBAL_PROXY_CREDS
TYPE WINHTTP_CREDS_EX
    lpszUserName AS ASCIIZ PTR
    lpszPassword AS ASCIIZ PTR
    lpszRealm    AS ASCIIZ PTR
    dwAuthScheme AS DWORD
    lpszHostName AS ASCIIZ PTR
    dwPort       AS DWORD
    lpszUrl      AS ASCIIZ PTR
END TYPE

'
' winhttp handle types
'
%WINHTTP_HANDLE_TYPE_SESSION    = 1
%WINHTTP_HANDLE_TYPE_CONNECT    = 2
%WINHTTP_HANDLE_TYPE_REQUEST    = 3

'
' values for auth schemes
'
%WINHTTP_AUTH_SCHEME_BASIC      = &H00000001
%WINHTTP_AUTH_SCHEME_NTLM       = &H00000002
%WINHTTP_AUTH_SCHEME_PASSPORT   = &H00000004
%WINHTTP_AUTH_SCHEME_DIGEST     = &H00000008
%WINHTTP_AUTH_SCHEME_NEGOTIATE  = &H00000010

' WinHttp supported Authentication Targets

%WINHTTP_AUTH_TARGET_SERVER = &H00000000
%WINHTTP_AUTH_TARGET_PROXY  = &H00000001

'
' values for WINHTTP_OPTION_SECURITY_FLAGS
'

' query only
%SECURITY_FLAG_SECURE                    = &H00000001 ' can query only
%SECURITY_FLAG_STRENGTH_WEAK             = &H10000000
%SECURITY_FLAG_STRENGTH_MEDIUM           = &H40000000
%SECURITY_FLAG_STRENGTH_STRONG           = &H20000000



' Secure connection error status flags
%WINHTTP_CALLBACK_STATUS_FLAG_CERT_REV_FAILED         = &H00000001???
%WINHTTP_CALLBACK_STATUS_FLAG_INVALID_CERT            = &H00000002???
%WINHTTP_CALLBACK_STATUS_FLAG_CERT_REVOKED            = &H00000004???
%WINHTTP_CALLBACK_STATUS_FLAG_INVALID_CA              = &H00000008???
%WINHTTP_CALLBACK_STATUS_FLAG_CERT_CN_INVALID         = &H00000010???
%WINHTTP_CALLBACK_STATUS_FLAG_CERT_DATE_INVALID       = &H00000020???
%WINHTTP_CALLBACK_STATUS_FLAG_CERT_WRONG_USAGE        = &H00000040???
%WINHTTP_CALLBACK_STATUS_FLAG_SECURITY_CHANNEL_ERROR  = &H80000000???


%WINHTTP_FLAG_SECURE_PROTOCOL_SSL2   = &H00000008
%WINHTTP_FLAG_SECURE_PROTOCOL_SSL3   = &H00000020
%WINHTTP_FLAG_SECURE_PROTOCOL_TLS1   = &H00000080
%WINHTTP_FLAG_SECURE_PROTOCOL_TLS1_1 = &H00000200
%WINHTTP_FLAG_SECURE_PROTOCOL_TLS1_2 = &H00000800
' [they might have meant to add the new TLS1_? flags to this...]
%WINHTTP_FLAG_SECURE_PROTOCOL_ALL    = (%WINHTTP_FLAG_SECURE_PROTOCOL_SSL2 _
                                    OR %WINHTTP_FLAG_SECURE_PROTOCOL_SSL3 _
                                    OR %WINHTTP_FLAG_SECURE_PROTOCOL_TLS1)


'
' callback function for WinHttpSetStatusCallback
'

DECLARE SUB WINHTTP_STATUS_CALLBACK (BYVAL hInternet AS DWORD, _
    BYVAL dwContext AS DWORD, BYVAL dwInternetStatus AS DWORD, _
    lpvStatusInformation AS ANY, BYVAL dwStatusInformationLength AS DWORD)


DECLARE FUNCTION WinHttpSetStatusCallback LIB "WinHTTP.DLL" _
    ALIAS "WinHttpSetStatusCallback" _
    ( _
    BYVAL hInternet AS DWORD, _
    BYVAL lpfnInternetCallback AS DWORD, _
    BYVAL dwNotificationFlags AS DWORD, _
    BYVAL dwReserved AS DWORD _
    ) AS DWORD


'
' status manifests for WinHttp status callback
'

%WINHTTP_CALLBACK_STATUS_RESOLVING_NAME        = &H00000001
%WINHTTP_CALLBACK_STATUS_NAME_RESOLVED         = &H00000002
%WINHTTP_CALLBACK_STATUS_CONNECTING_TO_SERVER  = &H00000004
%WINHTTP_CALLBACK_STATUS_CONNECTED_TO_SERVER   = &H00000008
%WINHTTP_CALLBACK_STATUS_SENDING_REQUEST       = &H00000010
%WINHTTP_CALLBACK_STATUS_REQUEST_SENT          = &H00000020
%WINHTTP_CALLBACK_STATUS_RECEIVING_RESPONSE    = &H00000040
%WINHTTP_CALLBACK_STATUS_RESPONSE_RECEIVED     = &H00000080
%WINHTTP_CALLBACK_STATUS_CLOSING_CONNECTION    = &H00000100
%WINHTTP_CALLBACK_STATUS_CONNECTION_CLOSED     = &H00000200
%WINHTTP_CALLBACK_STATUS_HANDLE_CREATED        = &H00000400
%WINHTTP_CALLBACK_STATUS_HANDLE_CLOSING        = &H00000800
%WINHTTP_CALLBACK_STATUS_DETECTING_PROXY       = &H00001000
%WINHTTP_CALLBACK_STATUS_REDIRECT              = &H00004000
%WINHTTP_CALLBACK_STATUS_INTERMEDIATE_RESPONSE = &H00008000
%WINHTTP_CALLBACK_STATUS_SECURE_FAILURE        = &H00010000
%WINHTTP_CALLBACK_STATUS_HEADERS_AVAILABLE     = &H00020000
%WINHTTP_CALLBACK_STATUS_DATA_AVAILABLE        = &H00040000
%WINHTTP_CALLBACK_STATUS_READ_COMPLETE         = &H00080000
%WINHTTP_CALLBACK_STATUS_WRITE_COMPLETE        = &H00100000
%WINHTTP_CALLBACK_STATUS_REQUEST_ERROR         = &H00200000
%WINHTTP_CALLBACK_STATUS_SENDREQUEST_COMPLETE  = &H00400000


' API Enums for WINHTTP_CALLBACK_STATUS_REQUEST_ERROR:
%API_RECEIVE_RESPONSE     = 1
%API_QUERY_DATA_AVAILABLE = 2
%API_READ_DATA            = 3
%API_WRITE_DATA           = 4
%API_SEND_REQUEST         = 5


%WINHTTP_CALLBACK_FLAG_RESOLVE_NAME          = %WINHTTP_CALLBACK_STATUS_RESOLVING_NAME OR %WINHTTP_CALLBACK_STATUS_NAME_RESOLVED
%WINHTTP_CALLBACK_FLAG_CONNECT_TO_SERVER     = %WINHTTP_CALLBACK_STATUS_CONNECTING_TO_SERVER OR %WINHTTP_CALLBACK_STATUS_CONNECTED_TO_SERVER
%WINHTTP_CALLBACK_FLAG_SEND_REQUEST          = %WINHTTP_CALLBACK_STATUS_SENDING_REQUEST OR %WINHTTP_CALLBACK_STATUS_REQUEST_SENT
%WINHTTP_CALLBACK_FLAG_RECEIVE_RESPONSE      = %WINHTTP_CALLBACK_STATUS_RECEIVING_RESPONSE OR %WINHTTP_CALLBACK_STATUS_RESPONSE_RECEIVED
%WINHTTP_CALLBACK_FLAG_CLOSE_CONNECTION      = %WINHTTP_CALLBACK_STATUS_CLOSING_CONNECTION OR %WINHTTP_CALLBACK_STATUS_CONNECTION_CLOSED
%WINHTTP_CALLBACK_FLAG_HANDLES               = %WINHTTP_CALLBACK_STATUS_HANDLE_CREATED OR %WINHTTP_CALLBACK_STATUS_HANDLE_CLOSING
%WINHTTP_CALLBACK_FLAG_DETECTING_PROXY       = %WINHTTP_CALLBACK_STATUS_DETECTING_PROXY
%WINHTTP_CALLBACK_FLAG_REDIRECT              = %WINHTTP_CALLBACK_STATUS_REDIRECT
%WINHTTP_CALLBACK_FLAG_INTERMEDIATE_RESPONSE = %WINHTTP_CALLBACK_STATUS_INTERMEDIATE_RESPONSE
%WINHTTP_CALLBACK_FLAG_SECURE_FAILURE        = %WINHTTP_CALLBACK_STATUS_SECURE_FAILURE
%WINHTTP_CALLBACK_FLAG_SENDREQUEST_COMPLETE  = %WINHTTP_CALLBACK_STATUS_SENDREQUEST_COMPLETE
%WINHTTP_CALLBACK_FLAG_HEADERS_AVAILABLE     = %WINHTTP_CALLBACK_STATUS_HEADERS_AVAILABLE
%WINHTTP_CALLBACK_FLAG_DATA_AVAILABLE        = %WINHTTP_CALLBACK_STATUS_DATA_AVAILABLE
%WINHTTP_CALLBACK_FLAG_READ_COMPLETE         = %WINHTTP_CALLBACK_STATUS_READ_COMPLETE
%WINHTTP_CALLBACK_FLAG_WRITE_COMPLETE        = %WINHTTP_CALLBACK_STATUS_WRITE_COMPLETE
%WINHTTP_CALLBACK_FLAG_REQUEST_ERROR         = %WINHTTP_CALLBACK_STATUS_REQUEST_ERROR


%WINHTTP_CALLBACK_FLAG_ALL_COMPLETIONS       = %WINHTTP_CALLBACK_STATUS_SENDREQUEST_COMPLETE _
                                            OR %WINHTTP_CALLBACK_STATUS_HEADERS_AVAILABLE _
                                            OR %WINHTTP_CALLBACK_STATUS_DATA_AVAILABLE _
                                            OR %WINHTTP_CALLBACK_STATUS_READ_COMPLETE _
                                            OR %WINHTTP_CALLBACK_STATUS_WRITE_COMPLETE _
                                            OR %WINHTTP_CALLBACK_STATUS_REQUEST_ERROR
%WINHTTP_CALLBACK_FLAG_ALL_NOTIFICATIONS     = &HFFFFFFFF???

'
' if the following value is returned by WinHttpSetStatusCallback, then
' probably an invalid (non-code) address was supplied for the callback
'

%WINHTTP_INVALID_STATUS_CALLBACK = &HFFFFFFFF???


'
' WinHttpQueryHeaders info levels. Generally, there is one info level
' for each potential RFC822/HTTP/MIME header that an HTTP server
' may send as part of a request response.
'
' The WINHTTP_QUERY_RAW_HEADERS info level is provided for clients
' that choose to perform their own header parsing.
'


%WINHTTP_QUERY_MIME_VERSION               = 0
%WINHTTP_QUERY_CONTENT_TYPE               = 1
%WINHTTP_QUERY_CONTENT_TRANSFER_ENCODING  = 2
%WINHTTP_QUERY_CONTENT_ID                 = 3
%WINHTTP_QUERY_CONTENT_DESCRIPTION        = 4
%WINHTTP_QUERY_CONTENT_LENGTH             = 5
%WINHTTP_QUERY_CONTENT_LANGUAGE           = 6
%WINHTTP_QUERY_ALLOW                      = 7
%WINHTTP_QUERY_PUBLIC                     = 8
%WINHTTP_QUERY_DATE                       = 9
%WINHTTP_QUERY_EXPIRES                    = 10
%WINHTTP_QUERY_LAST_MODIFIED              = 11
%WINHTTP_QUERY_MESSAGE_ID                 = 12
%WINHTTP_QUERY_URI                        = 13
%WINHTTP_QUERY_DERIVED_FROM               = 14
%WINHTTP_QUERY_COST                       = 15
%WINHTTP_QUERY_LINK                       = 16
%WINHTTP_QUERY_PRAGMA                     = 17
%WINHTTP_QUERY_VERSION                    = 18  ' special: part of status line
%WINHTTP_QUERY_STATUS_CODE                = 19  ' special: part of status line
%WINHTTP_QUERY_STATUS_TEXT                = 20  ' special: part of status line
%WINHTTP_QUERY_RAW_HEADERS                = 21  ' special: all headers as ASCIIZ
%WINHTTP_QUERY_RAW_HEADERS_CRLF           = 22  ' special: all headers
%WINHTTP_QUERY_CONNECTION                 = 23
%WINHTTP_QUERY_ACCEPT                     = 24
%WINHTTP_QUERY_ACCEPT_CHARSET             = 25
%WINHTTP_QUERY_ACCEPT_ENCODING            = 26
%WINHTTP_QUERY_ACCEPT_LANGUAGE            = 27
%WINHTTP_QUERY_AUTHORIZATION              = 28
%WINHTTP_QUERY_CONTENT_ENCODING           = 29
%WINHTTP_QUERY_FORWARDED                  = 30
%WINHTTP_QUERY_FROM                       = 31
%WINHTTP_QUERY_IF_MODIFIED_SINCE          = 32
%WINHTTP_QUERY_LOCATION                   = 33
%WINHTTP_QUERY_ORIG_URI                   = 34
%WINHTTP_QUERY_REFERER                    = 35
%WINHTTP_QUERY_RETRY_AFTER                = 36
%WINHTTP_QUERY_SERVER                     = 37
%WINHTTP_QUERY_TITLE                      = 38
%WINHTTP_QUERY_USER_AGENT                 = 39
%WINHTTP_QUERY_WWW_AUTHENTICATE           = 40
%WINHTTP_QUERY_PROXY_AUTHENTICATE         = 41
%WINHTTP_QUERY_ACCEPT_RANGES              = 42
%WINHTTP_QUERY_SET_COOKIE                 = 43
%WINHTTP_QUERY_COOKIE                     = 44
%WINHTTP_QUERY_REQUEST_METHOD             = 45  ' special: GET/POST etc.
%WINHTTP_QUERY_REFRESH                    = 46
%WINHTTP_QUERY_CONTENT_DISPOSITION        = 47

'
' HTTP 1.1 defined headers
'

%WINHTTP_QUERY_AGE                        = 48
%WINHTTP_QUERY_CACHE_CONTROL              = 49
%WINHTTP_QUERY_CONTENT_BASE               = 50
%WINHTTP_QUERY_CONTENT_LOCATION           = 51
%WINHTTP_QUERY_CONTENT_MD5                = 52
%WINHTTP_QUERY_CONTENT_RANGE              = 53
%WINHTTP_QUERY_ETAG                       = 54
%WINHTTP_QUERY_HOST                       = 55
%WINHTTP_QUERY_IF_MATCH                   = 56
%WINHTTP_QUERY_IF_NONE_MATCH              = 57
%WINHTTP_QUERY_IF_RANGE                   = 58
%WINHTTP_QUERY_IF_UNMODIFIED_SINCE        = 59
%WINHTTP_QUERY_MAX_FORWARDS               = 60
%WINHTTP_QUERY_PROXY_AUTHORIZATION        = 61
%WINHTTP_QUERY_RANGE                      = 62
%WINHTTP_QUERY_TRANSFER_ENCODING          = 63
%WINHTTP_QUERY_UPGRADE                    = 64
%WINHTTP_QUERY_VARY                       = 65
%WINHTTP_QUERY_VIA                        = 66
%WINHTTP_QUERY_WARNING                    = 67
%WINHTTP_QUERY_EXPECT                     = 68
%WINHTTP_QUERY_PROXY_CONNECTION           = 69
%WINHTTP_QUERY_UNLESS_MODIFIED_SINCE      = 70



%WINHTTP_QUERY_PROXY_SUPPORT              = 75
%WINHTTP_QUERY_AUTHENTICATION_INFO        = 76
%WINHTTP_QUERY_PASSPORT_URLS              = 77
%WINHTTP_QUERY_PASSPORT_CONFIG            = 78

%WINHTTP_QUERY_MAX                        = 78

'
' WINHTTP_QUERY_CUSTOM - if this special value is supplied as the dwInfoLevel
' parameter of WinHttpQueryHeaders() then the lpBuffer parameter contains the name
' of the header we are to query
'

%WINHTTP_QUERY_CUSTOM                     = 65535

'
' WINHTTP_QUERY_FLAG_REQUEST_HEADERS - if this bit is set in the dwInfoLevel
' parameter of WinHttpQueryHeaders() then the request headers will be queried for the
' request information
'

%WINHTTP_QUERY_FLAG_REQUEST_HEADERS       = &H80000000???

'
' WINHTTP_QUERY_FLAG_SYSTEMTIME - if this bit is set in the dwInfoLevel parameter
' of WinHttpQueryHeaders() AND the header being queried contains date information,
' e.g. the "Expires:" header then lpBuffer will contain a SYSTEMTIME structure
' containing the date and time information converted from the header string
'

%WINHTTP_QUERY_FLAG_SYSTEMTIME            = &H40000000

'
' WINHTTP_QUERY_FLAG_NUMBER - if this bit is set in the dwInfoLevel parameter of
' HttpQueryHeader(), then the value of the header will be converted to a number
' before being returned to the caller, if applicable
'

%WINHTTP_QUERY_FLAG_NUMBER                = &H20000000



'
' HTTP Response Status Codes:
'

%HTTP_STATUS_CONTINUE            = 100 ' OK to continue with request
%HTTP_STATUS_SWITCH_PROTOCOLS    = 101 ' server has switched protocols in upgrade header

%HTTP_STATUS_OK                  = 200 ' request completed
%HTTP_STATUS_CREATED             = 201 ' object created, reason = new URI
%HTTP_STATUS_ACCEPTED            = 202 ' async completion (TBS)
%HTTP_STATUS_PARTIAL             = 203 ' partial completion
%HTTP_STATUS_NO_CONTENT          = 204 ' no info to return
%HTTP_STATUS_RESET_CONTENT       = 205 ' request completed, but clear form
%HTTP_STATUS_PARTIAL_CONTENT     = 206 ' partial GET fulfilled
%HTTP_STATUS_WEBDAV_MULTI_STATUS = 207 ' WebDAV Multi-Status

%HTTP_STATUS_AMBIGUOUS           = 300 ' server couldn't decide what to return
%HTTP_STATUS_MOVED               = 301 ' object permanently moved
%HTTP_STATUS_REDIRECT            = 302 ' object temporarily moved
%HTTP_STATUS_REDIRECT_METHOD     = 303 ' redirection w/ new access method
%HTTP_STATUS_NOT_MODIFIED        = 304 ' if-modified-since was not modified
%HTTP_STATUS_USE_PROXY           = 305 ' redirection to proxy, location header specifies proxy to use
%HTTP_STATUS_REDIRECT_KEEP_VERB  = 307 ' HTTP/1.1: keep same verb

%HTTP_STATUS_BAD_REQUEST         = 400 ' invalid syntax
%HTTP_STATUS_DENIED              = 401 ' access denied
%HTTP_STATUS_PAYMENT_REQ         = 402 ' payment required
%HTTP_STATUS_FORBIDDEN           = 403 ' request forbidden
%HTTP_STATUS_NOT_FOUND           = 404 ' object not found
%HTTP_STATUS_BAD_METHOD          = 405 ' method is not allowed
%HTTP_STATUS_NONE_ACCEPTABLE     = 406 ' no response acceptable to client found
%HTTP_STATUS_PROXY_AUTH_REQ      = 407 ' proxy authentication required
%HTTP_STATUS_REQUEST_TIMEOUT     = 408 ' server timed out waiting for request
%HTTP_STATUS_CONFLICT            = 409 ' user should resubmit with more info
%HTTP_STATUS_GONE                = 410 ' the resource is no longer available
%HTTP_STATUS_LENGTH_REQUIRED     = 411 ' the server refused to accept request w/o a length
%HTTP_STATUS_PRECOND_FAILED      = 412 ' precondition given in request failed
%HTTP_STATUS_REQUEST_TOO_LARGE   = 413 ' request entity was too large
%HTTP_STATUS_URI_TOO_LONG        = 414 ' request URI too long
%HTTP_STATUS_UNSUPPORTED_MEDIA   = 415 ' unsupported media type
%HTTP_STATUS_RETRY_WITH          = 449 ' retry after doing the appropriate action.

%HTTP_STATUS_SERVER_ERROR        = 500 ' internal server error
%HTTP_STATUS_NOT_SUPPORTED       = 501 ' required not supported
%HTTP_STATUS_BAD_GATEWAY         = 502 ' error response received from gateway
%HTTP_STATUS_SERVICE_UNAVAIL     = 503 ' temporarily overloaded
%HTTP_STATUS_GATEWAY_TIMEOUT     = 504 ' timed out waiting for gateway
%HTTP_STATUS_VERSION_NOT_SUP     = 505 ' HTTP version not supported

%HTTP_STATUS_FIRST               = %HTTP_STATUS_CONTINUE
%HTTP_STATUS_LAST                = %HTTP_STATUS_VERSION_NOT_SUP

'
' prototypes
'

DECLARE FUNCTION WinHttpOpenRequest LIB "WinHTTP.DLL" _
    ALIAS "WinHttpOpenRequest" _
    ( _
    BYVAL hConnect AS DWORD, _
    pwszVerb AS WSTRINGZ, _
    pwszObjectName AS WSTRINGZ, _
    pwszVersion AS WSTRINGZ, _
    pwszReferrer AS WSTRINGZ, _
    ppwszAcceptTypes AS DWORD, _
    BYVAL dwFlags AS DWORD _
    ) AS DWORD

' WinHttpOpenRequest prettifers for optional parameters
%WINHTTP_NO_REFERER           = %NULL
%WINHTTP_DEFAULT_ACCEPT_TYPES = %NULL

DECLARE FUNCTION WinHttpAddRequestHeaders LIB "WinHTTP.DLL" _
    ALIAS "WinHttpAddRequestHeaders" _
    ( _
    BYVAL hRequest AS DWORD, _
    pwszHeaders AS WSTRINGZ, _
    BYVAL dwHeadersLength AS DWORD, _
    BYVAL dwModifiers AS DWORD _
    ) AS LONG

'
' values for dwModifiers parameter of WinHttpAddRequestHeaders()
'

%WINHTTP_ADDREQ_INDEX_MASK = &H0000FFFF
%WINHTTP_ADDREQ_FLAGS_MASK = &HFFFF0000???

'
' WINHTTP_ADDREQ_FLAG_ADD_IF_NEW - the header will only be added if it doesn't
' already exist
'

%WINHTTP_ADDREQ_FLAG_ADD_IF_NEW = &H10000000

'
' WINHTTP_ADDREQ_FLAG_ADD - if WINHTTP_ADDREQ_FLAG_REPLACE is set but the header is
' not found then if this flag is set, the header is added anyway, so long as
' there is a valid header-value
'

%WINHTTP_ADDREQ_FLAG_ADD        = &H20000000

'
' WINHTTP_ADDREQ_FLAG_COALESCE - coalesce headers with same name. e.g.
' "Accept: text/*" and "Accept: audio/*" with this flag results in a single
' header: "Accept: text/*, audio/*"
'

%WINHTTP_ADDREQ_FLAG_COALESCE_WITH_COMMA     = &H40000000
%WINHTTP_ADDREQ_FLAG_COALESCE_WITH_SEMICOLON = &H01000000
%WINHTTP_ADDREQ_FLAG_COALESCE                = %WINHTTP_ADDREQ_FLAG_COALESCE_WITH_COMMA

'
' WINHTTP_ADDREQ_FLAG_REPLACE - replaces the specified header. Only one header can
' be supplied in the buffer. If the header to be replaced is not the first
' in a list of headers with the same name, then the relative index should be
' supplied in the low 8 bits of the dwModifiers parameter. If the header-value
' part is missing, then the header is removed
'

%WINHTTP_ADDREQ_FLAG_REPLACE    = &H80000000???

%WINHTTP_IGNORE_REQUEST_TOTAL_LENGTH = 0


DECLARE FUNCTION WinHttpSendRequest LIB "WinHTTP.DLL" _
    ALIAS "WinHttpSendRequest" _
    ( _
    BYVAL hRequest AS DWORD, _
    pwszHeaders AS WSTRINGZ, _
    BYVAL dwHeadersLength AS DWORD, _
    BYVAL lpOptional AS DWORD, _
    BYVAL dwOptionalLength AS DWORD, _
    BYVAL dwTotalLength AS DWORD, _
    BYVAL dwContext AS DWORD _
    ) AS LONG

' WinHttpSendRequest prettifiers for optional parameters.
%WINHTTP_NO_ADDITIONAL_HEADERS = %NULL
%WINHTTP_NO_REQUEST_DATA       = %NULL


DECLARE FUNCTION WinHttpSetCredentials LIB "WinHTTP.DLL" _
    ALIAS "WinHttpSetCredentials" _
    ( _
    BYVAL hRequest AS DWORD, _        ' HINTERNET handle returned by WinHttpOpenRequest.
    BYVAL AuthTargets AS DWORD, _     ' Only WINHTTP_AUTH_TARGET_SERVER and
    _                                 ' WINHTTP_AUTH_TARGET_PROXY are supported
    _                                 ' in this version and they are mutually
    _                                 ' exclusive
    BYVAL AuthScheme AS DWORD, _      ' must be one of the supported Auth Schemes
    _                                 ' returned from WinHttpQueryAuthSchemes()
    pwszUserName AS WSTRINGZ, _       ' 1) %NULL if default creds is to be used, in
    _                                 ' which case pszPassword will be ignored
    pwszPassword AS WSTRINGZ, _       ' 1) "" == Blank Password; 2)Parameter ignored
    _                                 ' if pszUserName is %NULL; 3) Invalid to pass in
    _                                 ' %NULL if pszUserName is not %NULL
    BYVAL pAuthParams AS DWORD _
    ) AS LONG

DECLARE FUNCTION WinHttpQueryAuthSchemes LIB "WinHTTP.DLL" _
    ALIAS "WinHttpQueryAuthSchemes" _
    ( _
    BYVAL hRequest AS DWORD, _        ' HINTERNET handle returned by WinHttpOpenRequest
    lpdwSupportedSchemes AS DWORD, _  ' a bitmap of available Authentication Schemes
    lpdwFirstScheme AS DWORD, _       ' returns the first auth scheme returned by the server
    pdwAuthTarget AS DWORD _
    ) AS LONG

' [not documented. does not appear to be exported.]
'DECLARE FUNCTION WinHttpQueryAuthParams LIB "WinHTTP.DLL" _
'    ALIAS "WinHttpQueryAuthParams" _
'    ( _
'    BYVAL hRequest AS DWORD, _     ' HINTERNET handle returned by WinHttpOpenRequest
'    BYVAL AuthScheme AS DWORD, _
'    pAuthParams AS DWORD _         ' Scheme-specific Advanced auth parameters
'    ) AS LONG


DECLARE FUNCTION WinHttpReceiveResponse LIB "WinHTTP.DLL" _
    ALIAS "WinHttpReceiveResponse" _
    ( _
    BYVAL hRequest AS DWORD, _
    BYVAL lpReserved AS DWORD _
    ) AS LONG


DECLARE FUNCTION WinHttpQueryHeaders LIB "WinHTTP.DLL" _
    ALIAS "WinHttpQueryHeaders" _
    ( _
    BYVAL hRequest AS DWORD, _
    BYVAL dwInfoLevel AS DWORD, _
    pwszName AS WSTRINGZ, _
    BYVAL lpBuffer AS DWORD, _
    lpdwBufferLength AS DWORD, _
    lpdwIndex AS DWORD _
    ) AS LONG

' WinHttpQueryHeaders prettifiers for optional parameters.
%WINHTTP_HEADER_NAME_BY_INDEX = %NULL
%WINHTTP_NO_OUTPUT_BUFFER     = %NULL
%WINHTTP_NO_HEADER_INDEX      = %NULL


DECLARE FUNCTION WinHttpDetectAutoProxyConfigUrl LIB "WinHTTP.DLL" _
    ALIAS "WinHttpDetectAutoProxyConfigUrl" _
    ( _
    BYVAL dwAutoDetectFlags AS DWORD, _
    ppwszAutoConfigUrl AS DWORD _
    ) AS LONG

DECLARE FUNCTION WinHttpGetProxyForUrl LIB "WinHTTP.DLL" _
    ALIAS "WinHttpGetProxyForUrl" _
    ( _
    BYVAL hSession AS DWORD, _
    lpcwszUrl AS WSTRINGZ, _
    pAutoProxyOptions AS WINHTTP_AUTOPROXY_OPTIONS, _
    pProxyInfo AS WINHTTP_PROXY_INFO _
    ) AS LONG

TYPE WINHTTP_CURRENT_USER_IE_PROXY_CONFIG
    fAutoDetect       AS LONG
    lpszAutoConfigUrl AS WSTRINGZ PTR
    lpszProxy         AS WSTRINGZ PTR
    lpszProxyBypass   AS WSTRINGZ PTR
END TYPE


DECLARE FUNCTION WinHttpGetIEProxyConfigForCurrentUser LIB "WinHTTP.DLL" _
    ALIAS "WinHttpGetIEProxyConfigForCurrentUser" _
    (pProxyConfig AS WINHTTP_CURRENT_USER_IE_PROXY_CONFIG) AS LONG


'
' WinHttp API error returns
'

%WINHTTP_ERROR_BASE                    = 12000

%ERROR_WINHTTP_OUT_OF_HANDLES          = %WINHTTP_ERROR_BASE + 1
%ERROR_WINHTTP_TIMEOUT                 = %WINHTTP_ERROR_BASE + 2
%ERROR_WINHTTP_INTERNAL_ERROR          = %WINHTTP_ERROR_BASE + 4
%ERROR_WINHTTP_INVALID_URL             = %WINHTTP_ERROR_BASE + 5
%ERROR_WINHTTP_UNRECOGNIZED_SCHEME     = %WINHTTP_ERROR_BASE + 6
%ERROR_WINHTTP_NAME_NOT_RESOLVED       = %WINHTTP_ERROR_BASE + 7
%ERROR_WINHTTP_INVALID_OPTION          = %WINHTTP_ERROR_BASE + 9
%ERROR_WINHTTP_OPTION_NOT_SETTABLE     = %WINHTTP_ERROR_BASE + 11
%ERROR_WINHTTP_SHUTDOWN                = %WINHTTP_ERROR_BASE + 12


%ERROR_WINHTTP_LOGIN_FAILURE           = %WINHTTP_ERROR_BASE + 15
%ERROR_WINHTTP_OPERATION_CANCELLED     = %WINHTTP_ERROR_BASE + 17
%ERROR_WINHTTP_INCORRECT_HANDLE_TYPE   = %WINHTTP_ERROR_BASE + 18
%ERROR_WINHTTP_INCORRECT_HANDLE_STATE  = %WINHTTP_ERROR_BASE + 19
%ERROR_WINHTTP_CANNOT_CONNECT          = %WINHTTP_ERROR_BASE + 29
%ERROR_WINHTTP_CONNECTION_ERROR        = %WINHTTP_ERROR_BASE + 30
%ERROR_WINHTTP_RESEND_REQUEST          = %WINHTTP_ERROR_BASE + 32

%ERROR_WINHTTP_CLIENT_AUTH_CERT_NEEDED = %WINHTTP_ERROR_BASE + 44

'
' WinHttpRequest Component errors
'
%ERROR_WINHTTP_CANNOT_CALL_BEFORE_OPEN = %WINHTTP_ERROR_BASE + 100
%ERROR_WINHTTP_CANNOT_CALL_BEFORE_SEND = %WINHTTP_ERROR_BASE + 101
%ERROR_WINHTTP_CANNOT_CALL_AFTER_SEND  = %WINHTTP_ERROR_BASE + 102
%ERROR_WINHTTP_CANNOT_CALL_AFTER_OPEN  = %WINHTTP_ERROR_BASE + 103


'
' HTTP API errors
'

%ERROR_WINHTTP_HEADER_NOT_FOUND        = %WINHTTP_ERROR_BASE + 150
%ERROR_WINHTTP_INVALID_SERVER_RESPONSE = %WINHTTP_ERROR_BASE + 152
%ERROR_WINHTTP_INVALID_HEADER          = %WINHTTP_ERROR_BASE + 153
%ERROR_WINHTTP_INVALID_QUERY_REQUEST   = %WINHTTP_ERROR_BASE + 154
%ERROR_WINHTTP_HEADER_ALREADY_EXISTS   = %WINHTTP_ERROR_BASE + 155
%ERROR_WINHTTP_REDIRECT_FAILED         = %WINHTTP_ERROR_BASE + 156



'
' additional WinHttp API error codes
'

'
' additional WinHttp API error codes
'
%ERROR_WINHTTP_AUTO_PROXY_SERVICE_ERROR  = %WINHTTP_ERROR_BASE + 178
%ERROR_WINHTTP_BAD_AUTO_PROXY_SCRIPT     = %WINHTTP_ERROR_BASE + 166
%ERROR_WINHTTP_UNABLE_TO_DOWNLOAD_SCRIPT = %WINHTTP_ERROR_BASE + 167

%ERROR_WINHTTP_NOT_INITIALIZED          = %WINHTTP_ERROR_BASE + 172
%ERROR_WINHTTP_SECURE_FAILURE           = %WINHTTP_ERROR_BASE + 175


'
' Certificate security errors. These are raised only by the WinHttpRequest
' component. The WinHTTP Win32 API will return ERROR_WINHTTP_SECURE_FAILE and
' provide additional information via the WINHTTP_CALLBACK_STATUS_SECURE_FAILURE
' callback notification.
'
%ERROR_WINHTTP_SECURE_CERT_DATE_INVALID = %WINHTTP_ERROR_BASE + 37
%ERROR_WINHTTP_SECURE_CERT_CN_INVALID   = %WINHTTP_ERROR_BASE + 38
%ERROR_WINHTTP_SECURE_INVALID_CA        = %WINHTTP_ERROR_BASE + 45
%ERROR_WINHTTP_SECURE_CERT_REV_FAILED   = %WINHTTP_ERROR_BASE + 57
%ERROR_WINHTTP_SECURE_CHANNEL_ERROR     = %WINHTTP_ERROR_BASE + 157
%ERROR_WINHTTP_SECURE_INVALID_CERT      = %WINHTTP_ERROR_BASE + 169
%ERROR_WINHTTP_SECURE_CERT_REVOKED      = %WINHTTP_ERROR_BASE + 170
%ERROR_WINHTTP_SECURE_CERT_WRONG_USAGE  = %WINHTTP_ERROR_BASE + 179


%ERROR_WINHTTP_AUTODETECTION_FAILED                  = %WINHTTP_ERROR_BASE + 180
%ERROR_WINHTTP_HEADER_COUNT_EXCEEDED                 = %WINHTTP_ERROR_BASE + 181
%ERROR_WINHTTP_HEADER_SIZE_OVERFLOW                  = %WINHTTP_ERROR_BASE + 182
%ERROR_WINHTTP_CHUNKED_ENCODING_HEADER_SIZE_OVERFLOW = %WINHTTP_ERROR_BASE + 183
%ERROR_WINHTTP_RESPONSE_DRAIN_OVERFLOW               = %WINHTTP_ERROR_BASE + 184
%ERROR_WINHTTP_CLIENT_CERT_NO_PRIVATE_KEY            = %WINHTTP_ERROR_BASE + 185
%ERROR_WINHTTP_CLIENT_CERT_NO_ACCESS_PRIVATE_KEY     = %WINHTTP_ERROR_BASE + 186

%WINHTTP_ERROR_LAST                                  = %WINHTTP_ERROR_BASE + 186
