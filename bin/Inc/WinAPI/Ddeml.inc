'------------------------------------------------------------------------------
'
'  Ddeml.inc -- Common includes for new-style Win32 Access Control APIS
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from Ddeml.h version 3.10, build version 0001, of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%INC_DDEMLH = 1

#INCLUDE "WinNT.inc"


'******** public types ********

'DECLARE_HANDLE(HCONVLIST);
'DECLARE_HANDLE(HCONV);
'DECLARE_HANDLE(HSZ);
'DECLARE_HANDLE(HDDEDATA);
'#define EXPENTRY        CALLBACK

' the following structure is for use with XTYP_WILDCONNECT processing.

TYPE HSZPAIR
    hszSvc   AS DWORD  ' HSZ
    hszTopic AS DWORD  ' HSZ
END TYPE

' The following structure is used by DdeConnect() and DdeConnectList() and
' by XTYP_CONNECT and XTYP_WILDCONNECT callbacks.

TYPE CONVCONTEXT
    cb         AS DWORD    ' set to sizeof(CONVCONTEXT)
    wFlags     AS DWORD    ' none currently defined.
    wCountryID AS DWORD    ' country/region code for topic/item strings used.
    iCodePage  AS LONG     ' codepage used for topic/item strings.
    dwLangID   AS DWORD    ' language ID for topic/item strings.
    dwSecurity AS DWORD    ' Private security code.
    qos        AS SECURITY_QUALITY_OF_SERVICE ' client side's quality of service
END TYPE


' The following structure is used by DdeQueryConvInfo():

TYPE CONVINFO
    cb            AS DWORD           ' sizeof(CONVINFO)
    hUser         AS DWORD           ' user specified field
    hConvPartner  AS DWORD  ' HCONV  ' hConv on other end or 0 if non-ddemgr partner
    hszSvcPartner AS DWORD  ' HSZ    ' app name of partner if obtainable
    hszServiceReq AS DWORD  ' HSZ    ' AppName requested for connection
    hszTopic      AS DWORD  ' HSZ    ' Topic name for conversation
    hszItem       AS DWORD  ' HSZ    ' transaction item name or NULL if quiescent
    wFmt          AS DWORD           ' transaction format or NULL if quiescent
    wType         AS DWORD           ' XTYP_ for current transaction
    wStatus       AS DWORD           ' ST_ constant for current conversation
    wConvst       AS DWORD           ' XST_ constant for current transaction
    wLastError    AS DWORD           ' last transaction error.
    hConvList     AS DWORD  ' HCONVLIST ' parent hConvList if this conversation is in a list
    ConvCtxt      AS CONVCONTEXT     ' conversation context
    hwnd          AS DWORD  ' HWND   ' window handle for this conversation
    hwndPartner   AS DWORD  ' HWND   ' partner window handle for this conversation
END TYPE

'**** conversation states (usState) ****

%XST_NULL           =  0  ' quiescent states
%XST_INCOMPLETE     =  1
%XST_CONNECTED      =  2
%XST_INIT1          =  3  ' mid-initiation states
%XST_INIT2          =  4
%XST_REQSENT        =  5  ' active conversation states
%XST_DATARCVD       =  6
%XST_POKESENT       =  7
%XST_POKEACKRCVD    =  8
%XST_EXECSENT       =  9
%XST_EXECACKRCVD    = 10
%XST_ADVSENT        = 11
%XST_UNADVSENT      = 12
%XST_ADVACKRCVD     = 13
%XST_UNADVACKRCVD   = 14
%XST_ADVDATASENT    = 15
%XST_ADVDATAACKRCVD = 16

' used in LOWORD(dwData1) of XTYP_ADVREQ callbacks...
%CADV_LATEACK       = &HFFFF??

'**** conversation status bits (fsStatus) ****

%ST_CONNECTED          = &H0001
%ST_ADVISE             = &H0002
%ST_ISLOCAL            = &H0004
%ST_BLOCKED            = &H0008
%ST_CLIENT             = &H0010
%ST_TERMINATED         = &H0020
%ST_INLIST             = &H0040
%ST_BLOCKNEXT          = &H0080
%ST_ISSELF             = &H0100

' DDE constants for wStatus field

%DDE_FACK              = &H8000??
%DDE_FBUSY             = &H4000
%DDE_FDEFERUPD         = &H4000
%DDE_FACKREQ           = &H8000??
%DDE_FRELEASE          = &H2000
%DDE_FREQUESTED        = &H1000
%DDE_FAPPSTATUS        = &H00ff
%DDE_FNOTPROCESSED     = &H0000

%DDE_FACKRESERVED = (NOT (%DDE_FACK OR %DDE_FBUSY OR %DDE_FAPPSTATUS))
%DDE_FADVRESERVED = (NOT (%DDE_FACKREQ OR %DDE_FDEFERUPD))
%DDE_FDATRESERVED = (NOT (%DDE_FACKREQ OR %DDE_FRELEASE OR %DDE_FREQUESTED))
%DDE_FPOKRESERVED = (NOT (%DDE_FRELEASE))

'**** message filter hook types ****

%MSGF_DDEMGR           = &H8001??

'**** codepage constants ***

%CP_WINANSI    = 1004    ' default codepage for windows & old DDE convs.
%CP_WINUNICODE = 1200
#IF %DEF(%UNICODE)
%CP_WINNEUTRAL = %CP_WINUNICODE
#ELSE  ' NOT %UNICODE
%CP_WINNEUTRAL = %CP_WINANSI
#ENDIF ' NOT %UNICODE

'**** transaction types ****

%XTYPF_NOBLOCK          = &H0002  ' CBR_BLOCK will not work
%XTYPF_NODATA           = &H0004  ' DDE_FDEFERUPD
%XTYPF_ACKREQ           = &H0008  ' DDE_FACKREQ

%XCLASS_MASK            = &HFC00??
%XCLASS_BOOL            = &H1000
%XCLASS_DATA            = &H2000
%XCLASS_FLAGS           = &H4000
%XCLASS_NOTIFICATION    = &H8000??

%XTYP_ERROR            = (&H0000 OR %XCLASS_NOTIFICATION OR %XTYPF_NOBLOCK )
%XTYP_ADVDATA          = (&H0010 OR %XCLASS_FLAGS         )
%XTYP_ADVREQ           = (&H0020 OR %XCLASS_DATA OR %XTYPF_NOBLOCK )
%XTYP_ADVSTART         = (&H0030 OR %XCLASS_BOOL          )
%XTYP_ADVSTOP          = (&H0040 OR %XCLASS_NOTIFICATION)
%XTYP_EXECUTE          = (&H0050 OR %XCLASS_FLAGS         )
%XTYP_CONNECT          = (&H0060 OR %XCLASS_BOOL OR %XTYPF_NOBLOCK)
%XTYP_CONNECT_CONFIRM  = (&H0070 OR %XCLASS_NOTIFICATION OR %XTYPF_NOBLOCK)
%XTYP_XACT_COMPLETE    = (&H0080 OR %XCLASS_NOTIFICATION  )
%XTYP_POKE             = (&H0090 OR %XCLASS_FLAGS         )
%XTYP_REGISTER         = (&H00A0 OR %XCLASS_NOTIFICATION OR %XTYPF_NOBLOCK)
%XTYP_REQUEST          = (&H00B0 OR %XCLASS_DATA          )
%XTYP_DISCONNECT       = (&H00C0 OR %XCLASS_NOTIFICATION OR %XTYPF_NOBLOCK)
%XTYP_UNREGISTER       = (&H00D0 OR %XCLASS_NOTIFICATION OR %XTYPF_NOBLOCK)
%XTYP_WILDCONNECT      = (&H00E0 OR %XCLASS_DATA OR %XTYPF_NOBLOCK)

%XTYP_MASK             =  &H00F0
%XTYP_SHIFT            =  4  ' shift to turn XTYP_ into an index

'**** Timeout constants ****

%TIMEOUT_ASYNC         = &HFFFFFFFF???

'**** Transaction ID constants ****

%QID_SYNC              = &HFFFFFFFF???

'***** public strings used in DDE *****

$$SZDDESYS_TOPIC         = "System"$$
$$SZDDESYS_ITEM_TOPICS   = "Topics"$$
$$SZDDESYS_ITEM_SYSITEMS = "SysItems"$$
$$SZDDESYS_ITEM_RTNMSG   = "ReturnMessage"$$
$$SZDDESYS_ITEM_STATUS   = "Status"$$
$$SZDDESYS_ITEM_FORMATS  = "Formats"$$
$$SZDDESYS_ITEM_HELP     = "Help"$$
$$SZDDE_ITEM_ITEMLIST    = "TopicItemList"$$

$SZDDESYS_TOPIC         = "System"
$SZDDESYS_ITEM_TOPICS   = "Topics"
$SZDDESYS_ITEM_SYSITEMS = "SysItems"
$SZDDESYS_ITEM_RTNMSG   = "ReturnMessage"
$SZDDESYS_ITEM_STATUS   = "Status"
$SZDDESYS_ITEM_FORMATS  = "Formats"
$SZDDESYS_ITEM_HELP     = "Help"
$SZDDE_ITEM_ITEMLIST    = "TopicItemList"


'***** API entry points *****

DECLARE FUNCTION DDEFNCALLBACK ( _
    BYVAL wType   AS DWORD, _
    BYVAL wFmt    AS DWORD, _
    BYVAL hConv   AS DWORD, _  ' HCONV
    BYVAL hsz1    AS DWORD, _  ' HSZ
    BYVAL hsz2    AS DWORD, _  ' HSZ
    BYVAL hData   AS DWORD, _  ' HDDEDATA
    BYVAL dwData1 AS DWORD, _
    BYVAL dwData2 AS DWORD _
    ) AS DWORD  ' HDDEDATA

%CBR_BLOCK = &HFFFFFFFF???  ' ((HDDEDATA)-1)

' DLL registration functions

DECLARE FUNCTION DdeInitializeA LIB "User32.dll" ALIAS "DdeInitializeA" ( _
    pidInst           AS DWORD, _
    BYVAL pfnCallback AS DWORD, _  ' PFNCALLBACK
    BYVAL afCmd       AS DWORD, _
    BYVAL ulRes       AS DWORD _
    ) AS DWORD

DECLARE FUNCTION DdeInitializeW LIB "User32.dll" ALIAS "DdeInitializeW" ( _
    pidInst           AS DWORD, _
    BYVAL pfnCallback AS DWORD, _  ' PFNCALLBACK
    BYVAL afCmd       AS DWORD, _
    BYVAL ulRes       AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION DdeInitialize LIB "User32.dll" ALIAS "DdeInitializeW" ( _
    pidInst           AS DWORD, _
    BYVAL pfnCallback AS DWORD, _  ' PFNCALLBACK
    BYVAL afCmd       AS DWORD, _
    BYVAL ulRes       AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION DdeInitialize LIB "User32.dll" ALIAS "DdeInitializeA" ( _
    pidInst           AS DWORD, _
    BYVAL pfnCallback AS DWORD, _  ' PFNCALLBACK
    BYVAL afCmd       AS DWORD, _
    BYVAL ulRes       AS DWORD _
    ) AS DWORD
#ENDIF ' NOT %UNICODE

'
' Callback filter flags for use with standard apps.
'

%CBF_FAIL_SELFCONNECTIONS   = &H00001000
%CBF_FAIL_CONNECTIONS       = &H00002000
%CBF_FAIL_ADVISES           = &H00004000
%CBF_FAIL_EXECUTES          = &H00008000
%CBF_FAIL_POKES             = &H00010000
%CBF_FAIL_REQUESTS          = &H00020000
%CBF_FAIL_ALLSVRXACTIONS    = &H0003f000

%CBF_SKIP_CONNECT_CONFIRMS  = &H00040000
%CBF_SKIP_REGISTRATIONS     = &H00080000
%CBF_SKIP_UNREGISTRATIONS   = &H00100000
%CBF_SKIP_DISCONNECTS       = &H00200000
%CBF_SKIP_ALLNOTIFICATIONS  = &H003c0000

'
' Application command flags
'
%APPCMD_CLIENTONLY          = &H00000010
%APPCMD_FILTERINITS         = &H00000020
%APPCMD_MASK                = &H00000FF0

'
' Application classification flags
'
%APPCLASS_STANDARD          = &H00000000
%APPCLASS_MASK              = &H0000000F

DECLARE FUNCTION DdeUninitialize LIB "User32.dll" ALIAS "DdeUninitialize" ( _
    BYVAL idInst AS DWORD _
    ) AS LONG  ' BOOL

'
' conversation enumeration functions
'
DECLARE FUNCTION DdeConnectList LIB "User32.dll" ALIAS "DdeConnectList" ( _
    BYVAL idInst        AS DWORD, _
    BYVAL hszService    AS DWORD, _  ' HSZ
    BYVAL hszTopic      AS DWORD, _  ' HSZ
    BYVAL hConvList     AS DWORD, _  ' HCONVLIST
    OPTIONAL BYVAL pCC  AS CONVCONTEXT PTR _
    ) AS DWORD  ' HCONVLIST

DECLARE FUNCTION DdeQueryNextServer LIB "User32.dll" _
    ALIAS "DdeQueryNextServer" ( _
    BYVAL hConvList AS DWORD, _  ' HCONVLIST
    BYVAL hConvPrev AS DWORD _   ' HCONV
    ) AS DWORD  ' HCONV

DECLARE FUNCTION DdeDisconnectList LIB "User32.dll" _
    ALIAS "DdeDisconnectList" ( _
    BYVAL hConvList  AS DWORD _  ' HCONVLIST
    ) AS LONG  ' BOOL

'
' conversation control functions
'
DECLARE FUNCTION DdeConnect LIB "User32.dll" ALIAS "DdeConnect" ( _
    BYVAL idInst       AS DWORD, _
    BYVAL hszService   AS DWORD, _  ' HSZ
    BYVAL hszTopic     AS DWORD, _  ' HSZ
    OPTIONAL BYVAL pCC AS CONVCONTEXT PTR _
    ) AS DWORD  ' HCONV

DECLARE FUNCTION DdeDisconnect LIB "User32.dll" ALIAS "DdeDisconnect" ( _
    BYVAL hConv AS DWORD _  ' HCONV
    ) AS LONG  ' BOOL

DECLARE FUNCTION DdeReconnect LIB "User32.dll" ALIAS "DdeReconnect" ( _
    BYVAL hConv AS DWORD _  ' HCONV
    ) AS DWORD  ' HCONV

DECLARE FUNCTION DdeQueryConvInfo LIB "User32.dll" ALIAS "DdeQueryConvInfo" ( _
    BYVAL hConv         AS DWORD, _  ' HCONV
    BYVAL idTransaction AS DWORD, _
    pConvInfo           AS CONVINFO _
    ) AS DWORD

DECLARE FUNCTION DdeSetUserHandle LIB "User32.dll" ALIAS "DdeSetUserHandle" ( _
    BYVAL hConv AS DWORD, _  ' HCONV
    BYVAL ID    AS DWORD, _
    BYVAL hUser AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION DdeAbandonTransaction LIB "User32.dll" _
    ALIAS "DdeAbandonTransaction" ( _
    BYVAL idInst        AS DWORD, _
    BYVAL hConv         AS DWORD, _ ' HCONV
    BYVAL idTransaction AS DWORD _
    ) AS LONG  ' BOOL


'
' app server interface functions
'
DECLARE FUNCTION DdePostAdvise LIB "User32.dll" ALIAS "DdePostAdvise" ( _
    BYVAL idInst   AS DWORD, _
    BYVAL hszTopic AS DWORD, _  ' HSZ
    BYVAL hszItem  AS DWORD _   ' HSZ
    ) AS LONG  ' BOOL

DECLARE FUNCTION DdeEnableCallback LIB "User32.dll" _
    ALIAS "DdeEnableCallback" ( _
    BYVAL idInst AS DWORD, _
    BYVAL hConv  AS DWORD, _  ' HCONV
    BYVAL wCmd   AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION DdeImpersonateClient LIB "User32.dll" _
    ALIAS "DdeImpersonateClient" ( _
    BYVAL hConv AS DWORD _  ' HCONV
    ) AS LONG  ' BOOL


%EC_ENABLEALL          = 0
%EC_ENABLEONE          = %ST_BLOCKNEXT
%EC_DISABLE            = %ST_BLOCKED
%EC_QUERYWAITING       = 2

DECLARE FUNCTION DdeNameService LIB "User32.dll" ALIAS "DdeNameService" ( _
    BYVAL idInst AS DWORD, _
    BYVAL hsz1   AS DWORD, _  ' HSZ
    BYVAL hsz2   AS DWORD, _  ' HSZ
    BYVAL afCmd  AS DWORD _
    ) AS DWORD  ' HDDEDATA

%DNS_REGISTER      = &H0001
%DNS_UNREGISTER    = &H0002
%DNS_FILTERON      = &H0004
%DNS_FILTEROFF     = &H0008

'
' app client interface functions
'
DECLARE FUNCTION DdeClientTransaction LIB "User32.dll" _
    ALIAS "DdeClientTransaction" ( _
    BYVAL pData     AS BYTE PTR, _
    BYVAL cbData    AS DWORD, _
    BYVAL hConv     AS DWORD, _  ' HCONV
    BYVAL hszItem   AS DWORD, _  ' HSZ
    BYVAL wFmt      AS DWORD, _
    BYVAL wType     AS DWORD, _
    BYVAL dwTimeout AS DWORD, _
    pdwResult       AS DWORD _
    ) AS DWORD  ' HDDEDATA


'
' data transfer functions
'

DECLARE FUNCTION DdeCreateDataHandle LIB "User32.dll" _
    ALIAS "DdeCreateDataHandle" ( _
    BYVAL idInst  AS DWORD, _
    BYVAL pSrc    AS BYTE PTR, _
    BYVAL cb      AS DWORD, _
    BYVAL cbOff   AS DWORD, _
    BYVAL hszItem AS DWORD, _  ' HSZ
    BYVAL wFmt    AS DWORD, _
    BYVAL afCmd   AS DWORD _
    ) AS DWORD  ' HDDEDATA

DECLARE FUNCTION DdeAddData LIB "User32.dll" ALIAS "DdeAddData" ( _
    BYVAL hData AS DWORD, _  ' HDDEDATA
    BYVAL pSrc  AS BYTE PTR, _
    BYVAL cb    AS DWORD, _
    BYVAL cbOff AS DWORD _
    ) AS DWORD  ' HDDEDATA

DECLARE FUNCTION DdeGetData LIB "User32.dll" ALIAS "DdeGetData" ( _
    BYVAL hData AS DWORD, _   ' HDDEDATA
    BYVAL pDst  AS BYTE PTR, _
    BYVAL cbMax AS DWORD, _
    BYVAL cbOff AS DWORD _
    ) AS DWORD

DECLARE FUNCTION DdeAccessData LIB "User32.dll" ALIAS "DdeAccessData" ( _
    BYVAL hData AS DWORD, _  ' HDDEDATA
    pcbDataSize AS DWORD _
    ) AS DWORD  ' BYTE PTR

DECLARE FUNCTION DdeUnaccessData LIB "User32.dll" ALIAS "DdeUnaccessData" ( _
    BYVAL hData AS DWORD _  ' HDDEDATA
    ) AS LONG  ' BOOL

DECLARE FUNCTION DdeFreeDataHandle LIB "User32.dll" _
    ALIAS "DdeFreeDataHandle" ( _
    hData AS DWORD _  ' HDDEDATA
    ) AS LONG  ' BOOL

%HDATA_APPOWNED        = &H0001


DECLARE FUNCTION DdeGetLastError LIB "User32.dll" ALIAS "DdeGetLastError" ( _
    BYVAL idInst AS DWORD _
    ) AS DWORD


%DMLERR_NO_ERROR                  = 0       ' must be 0

%DMLERR_FIRST                     = &H4000

%DMLERR_ADVACKTIMEOUT             = &H4000
%DMLERR_BUSY                      = &H4001
%DMLERR_DATAACKTIMEOUT            = &H4002
%DMLERR_DLL_NOT_INITIALIZED       = &H4003
%DMLERR_DLL_USAGE                 = &H4004
%DMLERR_EXECACKTIMEOUT            = &H4005
%DMLERR_INVALIDPARAMETER          = &H4006
%DMLERR_LOW_MEMORY                = &H4007
%DMLERR_MEMORY_ERROR              = &H4008
%DMLERR_NOTPROCESSED              = &H4009
%DMLERR_NO_CONV_ESTABLISHED       = &H400a
%DMLERR_POKEACKTIMEOUT            = &H400b
%DMLERR_POSTMSG_FAILED            = &H400c
%DMLERR_REENTRANCY                = &H400d
%DMLERR_SERVER_DIED               = &H400e
%DMLERR_SYS_ERROR                 = &H400f
%DMLERR_UNADVACKTIMEOUT           = &H4010
%DMLERR_UNFOUND_QUEUE_ID          = &H4011

%DMLERR_LAST                      = &H4011

DECLARE FUNCTION DdeCreateStringHandleA LIB "User32.dll" _
    ALIAS "DdeCreateStringHandleA" ( _
    BYVAL idInst    AS DWORD, _
    psz             AS ASCIIZ, _
    BYVAL iCodePage AS LONG _
    ) AS DWORD  ' HSZ

DECLARE FUNCTION DdeCreateStringHandleW LIB "User32.dll" _
    ALIAS "DdeCreateStringHandleW" ( _
    BYVAL idInst    AS DWORD, _
    psz             AS WSTRINGZ, _
    BYVAL iCodePage AS LONG _
    ) AS DWORD  ' HSZ

#IF %DEF(%UNICODE)
DECLARE FUNCTION DdeCreateStringHandle LIB "User32.dll" _
    ALIAS "DdeCreateStringHandleW" ( _
    BYVAL idInst    AS DWORD, _
    psz             AS WSTRINGZ, _
    BYVAL iCodePage AS LONG _
    ) AS DWORD  ' HSZ
#ELSE
DECLARE FUNCTION DdeCreateStringHandle LIB "User32.dll" _
    ALIAS "DdeCreateStringHandleA" ( _
    BYVAL idInst    AS DWORD, _
    psz             AS ASCIIZ, _
    BYVAL iCodePage AS LONG _
    ) AS DWORD  ' HSZ
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION DdeQueryStringA LIB "User32.dll" ALIAS "DdeQueryStringA" ( _
    BYVAL idInst    AS DWORD, _
    BYVAL hsz       AS DWORD, _  ' HSZ
    psz             AS ASCIIZ, _
    BYVAL cchMax    AS DWORD, _
    BYVAL iCodePage AS LONG _
    ) AS DWORD

DECLARE FUNCTION DdeQueryStringW LIB "User32.dll" ALIAS "DdeQueryStringW" ( _
    BYVAL idInst    AS DWORD, _
    BYVAL hsz       AS DWORD, _  ' HSZ
    psz             AS WSTRINGZ, _
    BYVAL cchMax    AS DWORD, _
    BYVAL iCodePage AS LONG _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION DdeQueryString LIB "User32.dll" ALIAS "DdeQueryStringW" ( _
    BYVAL idInst    AS DWORD, _
    BYVAL hsz       AS DWORD, _  ' HSZ
    psz             AS WSTRINGZ, _
    BYVAL cchMax    AS DWORD, _
    BYVAL iCodePage AS LONG _
    ) AS DWORD
#ELSE
DECLARE FUNCTION DdeQueryString LIB "User32.dll" ALIAS "DdeQueryStringA" ( _
    BYVAL idInst    AS DWORD, _
    BYVAL hsz       AS DWORD, _  ' HSZ
    psz             AS ASCIIZ, _
    BYVAL cchMax    AS DWORD, _
    BYVAL iCodePage AS LONG _
    ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DdeFreeStringHandle LIB "User32.dll" _
    ALIAS "DdeFreeStringHandle" ( _
    BYVAL idInst AS DWORD, _
    BYVAL hsz    AS DWORD _
    ) AS LONG

DECLARE FUNCTION DdeKeepStringHandle LIB "User32.dll" _
    ALIAS "DdeKeepStringHandle" ( _
    BYVAL idInst AS DWORD, _
    BYVAL hsz    AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION DdeCmpStringHandles LIB "User32.dll" _
    ALIAS "DdeCmpStringHandles" ( _
    BYVAL hsz1 AS DWORD, _
    BYVAL hsz2 AS DWORD _
    ) AS LONG

#IF NOT %DEF(%NODDEMLSPY)
'
' DDEML public debugging header file info
'

TYPE DDEML_MSG_HOOK_DATA     ' new for NT
    uiLo    AS DWORD   ' unpacked lo and hi parts of lParam
    uiHi    AS DWORD
    cbData  AS DWORD   ' amount of data in message, if any. May be > 32 bytes.
    DATA(7) as DWORD   ' data peeking by DDESPY is limited to 32 bytes.
END TYPE


TYPE MONMSGSTRUCT
    cb     AS DWORD
    hwndTo AS DWORD  ' HWND
    dwTime AS DWORD
    hTask  AS DWORD  ' HANDLE
    wMsg   AS DWORD
    wParam AS DWORD  ' WPARAM
    lParam AS LONG   ' LPARAM
    dmhd   AS DDEML_MSG_HOOK_DATA        ' new for NT
END TYPE

TYPE MONCBSTRUCT
    cb      AS DWORD
    dwTime  AS DWORD
    hTask   AS DWORD  ' HANDLE
    dwRet   AS DWORD
    wType   AS DWORD
    wFmt    AS DWORD
    hConv   AS DWORD  ' HCONV
    hsz1    AS DWORD  ' HSZ
    hsz2    AS DWORD  ' HSZ
    hData   AS DWORD  ' HDDEDATA
    dwData1 AS DWORD
    dwData2 AS DWORD
    cc      AS CONVCONTEXT    ' new for NT for XTYP_CONNECT callbacks
    cbData  AS DWORD          ' new for NT for data peeking
    DATA(7) as DWORD          ' new for NT for data peeking
END TYPE

TYPE MONHSZSTRUCTA
    cb       AS DWORD
    fsAction AS LONG   ' BOOL  ' %MH_ value
    dwTime   AS DWORD
    hsz      AS DWORD  ' HSZ
    hTask    AS DWORD  ' HANDLE
    str      AS ASCIIZ * 1
END TYPE

TYPE MONHSZSTRUCTW
    cb       AS DWORD
    fsAction AS LONG   ' BOOL  ' %MH_ value
    dwTime   AS DWORD
    hsz      AS DWORD  ' HSZ
    hTask    AS DWORD  ' HANDLE
    str      AS WSTRINGZ * 1
END TYPE

#IF %DEF(%UNICODE)
TYPE MONHSZSTRUCT
    MONHSZSTRUCTW
END TYPE
#ELSE
TYPE MONHSZSTRUCT
    MONHSZSTRUCTA
END TYPE
#ENDIF ' %UNICODE

%MH_CREATE  = 1
%MH_KEEP    = 2
%MH_DELETE  = 3
%MH_CLEANUP = 4

TYPE MONERRSTRUCT
    cb         AS DWORD
    wLastError AS DWORD
    dwTime     AS DWORD
    hTask      AS DWORD  ' HANDLE
END TYPE

TYPE MONLINKSTRUCT
    cb           AS DWORD
    dwTime       AS DWORD
    hTask        AS DWORD  ' HANDLE
    fEstablished AS LONG   ' BOOL
    fNoData      AS LONG   ' BOOL
    hszSvc       AS DWORD  ' HSZ
    hszTopic     AS DWORD  ' HSZ
    hszItem      AS DWORD  ' HSZ
    wFmt         AS DWORD
    fServer      AS LONG   ' BOOL
    hConvServer  AS DWORD  ' HCONV
    hConvClient  AS DWORD  ' HCONV
END TYPE

TYPE MONCONVSTRUCT
    cb          AS DWORD
    fConnect    AS LONG   ' BOOL
    dwTime      AS DWORD
    hTask       AS DWORD  ' HANDLE
    hszSvc      AS DWORD  ' HSZ
    hszTopic    AS DWORD  ' HSZ
    hConvClient AS DWORD  ' HCONV  ' Globally unique value <> apps local hConv
    hConvServer AS DWORD  ' HCONV  ' Globally unique value <> apps local hConv
END TYPE

%MAX_MONITORS          = 4
'#define     APPCLASS_MONITOR       * 0x00000001L
%XTYP_MONITOR          = (&H00F0 OR %XCLASS_NOTIFICATION OR %XTYPF_NOBLOCK)

'
' Callback filter flags for use with MONITOR apps - 0 implies no monitor
' callbacks.
'
%MF_HSZ_INFO                = &H01000000
%MF_SENDMSGS                = &H02000000
%MF_POSTMSGS                = &H04000000
%MF_CALLBACKS               = &H08000000
%MF_ERRORS                  = &H10000000
%MF_LINKS                   = &H20000000
%MF_CONV                    = &H40000000

%MF_MASK                    = &HFF000000???
#ENDIF ' %NODDEMLSPY
