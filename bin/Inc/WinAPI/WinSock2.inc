'------------------------------------------------------------------------------
'
'  WinSock2.inc
'
'  Copyright (c) 1997-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from WinSock2.h dated 18 Jan 2008
'------------------------------------------------------------------------------
'  NOTE: before including this file, use #INCLUDE "Win32Api.inc"
'------------------------------------------------------------------------------

'$TAG BIZDEV
'  $IPCategory:
'  $DealPointID:    118736
'  $AgreementName:  berkeley software distribution license
'  $AgreementType:  oss license
'  $ExternalOrigin: regents of the university of california
'$ENDTAG

'$TAG ENGR
'  $Owner:    vadime
'  $Module:   published_inc
'
'$ENDTAG

' Winsock2.h -- definitions to be used with the WinSock 2 DLL and
'               WinSock 2 applications.
'
' This header file corresponds to version 2.2.x of the WinSock API
' specification.
'
' This file includes parts which are Copyright (c) 1982-1986 Regents
' of the University of California.  All rights reserved.  The
' Berkeley Software License Agreement specifies the terms and
' conditions for redistribution.
'

#IF NOT %DEF(%WINSOCK2API)
%WINSOCK2API = 1
%WINSOCKAPI = 1   ' Prevent inclusion of winsock.inc in windows.inc

#INCLUDE ONCE "WinError.inc"
#INCLUDE ONCE "WinBase.inc"

'
' Ensure structures are packed consistently.
' Not necessary for WIN32, it is already packed >=4 and there are
' no structures in this header that have alignment requirement
' higher than 4.
' For WIN64 we do not have compatibility requirement because it is
' not possible to mix 32/16 bit code with 64 bit code in the same
' process.
'

'
' Default: include function prototypes, don't include function typedefs.
'

#IF NOT %DEF(%INCL_WINSOCK_API_PROTOTYPES)
%INCL_WINSOCK_API_PROTOTYPES = 1
#ENDIF

#IF NOT %DEF(%INCL_WINSOCK_API_TYPEDEFS)
%INCL_WINSOCK_API_TYPEDEFS = 0
#ENDIF

'
' Pull in WINDOWS.H if necessary
'
' [heck, no. this can't possibly be prudent.]
'#include "windows.inc"

'
' Define the current Winsock version. To build an earlier Winsock version
' application redefine this value prior to including Winsock2.h.
'

#IF NOT %DEF(%MAKEWORD)
MACRO MAKEWORD(low,high)=MAK(WORD,low,high)
#ENDIF

#IF NOT %DEF(%WINSOCK_VERSION)
%WINSOCK_VERSION = &H0202  ' MAKEWORD(2,2)
#ENDIF

'
' Basic system type definitions, taken from the BSD file sys/types.h.
'
'typedef unsigned char   u_char;
'typedef unsigned short  u_short;
'typedef unsigned int    u_int;
'typedef unsigned long   u_long;

'#if (%WIN32_WINNT >= &H0501)
'typedef unsigned __int64 u_int64;
'#endif '(%WIN32_WINNT >= &H0501)

#INCLUDE "ws2def.inc"

'
' The new type to be used in all
' instances which refer to sockets.
'
'MACRO SOCKET=DWORD

'
' Select uses arrays of SOCKETs.  These macros manipulate such
' arrays.  FD_SETSIZE may be defined by the user before including
' this file, but the default here should be >= 64.
'
' CAVEAT IMPLEMENTOR and USER: THESE MACROS AND TYPES MUST BE
' INCLUDED IN WINSOCK2.H EXACTLY AS SHOWN HERE.
'
#IF NOT %DEF(%FD_SETSIZE)
%FD_SETSIZE    = 64
#ENDIF ' FD_SETSIZE

TYPE fd_set
    fd_count                AS DWORD   ' how many are SET?
    fd_array(%FD_SETSIZE-1) AS DWORD   ' an array of SOCKETs
END TYPE

DECLARE FUNCTION WSAFDIsSet LIB "Ws2_32.dll" ALIAS "__WSAFDIsSet" ( _
    BYVAL fd  AS DWORD, _  ' SOCKET
    BYVAL fds AS fd_set PTR _
    ) AS LONG

SUB FD_CLR (BYVAL fd AS DWORD, BYVAL fdset AS fd_set PTR)

    LOCAL i AS DWORD

    DO WHILE i < @fdset.fd_count
        IF @fdset.fd_array(i) = fd THEN
            DO WHILE i < @fdset.fd_count - 1
                @fdset.fd_array(i) = @fdset.fd_array(i+1)
                INCR i
            LOOP
            DECR @fdset.fd_count
            ITERATE DO
        END IF
        INCR i
    LOOP

END SUB

SUB FD_SET_sub (BYVAL fd AS DWORD, BYVAL fdset AS fd_set PTR)

    LOCAL i AS DWORD

    FOR i = 0 TO @fdset.fd_count - 1
        IF @fdset.fd_array(i) = fd THEN
            EXIT FOR
        END IF
    NEXT

    IF i = @fdset.fd_count THEN
        IF @fdset.fd_count < %FD_SETSIZE THEN
            @fdset.fd_array(i) = fd
            INCR @fdset.fd_count
        END IF
    END IF

END SUB


SUB FD_ZERO (BYVAL fdset AS fd_set PTR)
    @fdset.fd_count = 0
END SUB

MACRO FD_ISSET=WSAFDIsSet

'
' Structure used in select() call, taken from the BSD file sys/time.h.
'
TYPE timeval
    tv_sec  AS LONG   ' seconds
    tv_usec AS LONG   ' and microseconds
END TYPE

'
' Operations on timevals.
'
' NB: timercmp does not work for >= or <=.
'
MACRO timerisset(tvp)=(@tvp.tv_sec OR @tvp.tv_usec)

'#define timercmp(tvp, uvp, cmp)  _
'    ((tvp)->tv_sec cmp (uvp)->tv_sec OR  _
'    (tvp)->tv_sec == (uvp)->tv_sec AND (tvp)->tv_usec cmp (uvp)->tv_usec)

MACRO timerclear(tvp)
    @tvp.tv_usec = 0
    @tvp.tv_sec  = 0
END MACRO

'
' Commands for ioctlsocket(),  taken from the BSD file fcntl.h.
'
'
' Ioctls have the command encoded in the lower word,
' and the size of any in or out parameters in the upper
' word.  The high 2 bits of the upper word are used
' to encode the in/out status of the parameter; for now
' we restrict parameters to at most 128 bytes.
'
' [this stuff is already defined in ws2def.inc]
'%IOCPARM_MASK  = &H7f            ' parameters must be < 128 bytes
'%IOC_VOID      = &H20000000      ' no parameters
'%IOC_OUT       = &H40000000      ' copy out parameters
'%IOC_IN        = &H80000000???   ' copy in parameters
'%IOC_INOUT     = (%IOC_IN OR %IOC_OUT)
'                                 ' &H20000000 distinguishes new & old ioctls
'#define _IO(x,y)        (IOC_VOID|((x)<<8)|(y))
'
'#define _IOR(x,y,t)     (IOC_OUT|(((long)sizeof(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))
'
'#define _IOW(x,y,t)     (IOC_IN|(((long)sizeof(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))

%FIONREAD = &H4004667F    ' _IOR('f', 127, u_long) ' get # bytes to read
%FIONBIO  = &H8004667E??? ' _IOW('f', 126, u_long) ' set/clear non-blocking i/o
%FIOASYNC = &H8004667D??? ' _IOW('f', 125, u_long) ' set/clear async i/o

' Socket I/O Controls
%SIOCSHIWAT = &H80047300???  ' _IOW('s',  0, u_long)  ' set high watermark
%SIOCGHIWAT = &H40047301     ' _IOR('s',  1, u_long)  ' get high watermark
%SIOCSLOWAT = &H80047302???  ' _IOW('s',  2, u_long)  ' set low watermark
%SIOCGLOWAT = &H80047303???  ' _IOR('s',  3, u_long)  ' get low watermark
%SIOCATMARK = &H40047307     ' _IOR('s',  7, u_long)  ' at oob mark?

'
' Structures returned by network data base library, taken from the
' BSD file netdb.h.  All addresses are supplied in host order, and
' returned in network order (suitable for use in system calls).
'

TYPE hostent
    h_name      AS ASCIIZ PTR  ' official name of host
    h_aliases   AS DWORD       ' char ** ' alias list
    h_addrtype  AS INTEGER     ' host address type
    h_length    AS INTEGER     ' length of address
    h_addr_list AS DWORD       ' char ** ' list of addresses
END TYPE
'#define h_addr  h_addr_list[0]          ' address, for backward compat

'
' It is assumed here that a network number
' fits in 32 bits.
'
TYPE netent DWORD FILL
    n_name     AS ASCIIZ PTR  ' official name of net
    n_aliases  AS DWORD       ' ASCIIZ PTR PTR  alias list
    n_addrtype AS INTEGER     ' net address type
    n_net      AS DWORD       ' network #
END TYPE

TYPE servent DWORD FILL
    s_name     AS ASCIIZ PTR   ' official service name
    s_aliases  AS DWORD        ' ASCIIZ PTR PTR  alias list
#IF %DEF(%WIN64)
    s_proto    AS ASCIIZ PTR   ' protocol to use
    s_port     AS INTEGER      ' port #
#ELSE
    s_port     AS INTEGER      ' port #
    s_proto    AS ASCIIZ PTR   ' protocol to use
#ENDIF
END TYPE

TYPE protoent DWORD FILL
    p_name    AS ASCIIZ PTR    ' official protocol name
    p_aliases AS DWORD         ' ASCIIZ PTR PTR  alias list
    p_proto   AS INTEGER       ' protocol #
END TYPE

'
' Constants and structures defined by the internet system,
' Per RFC 790, September 1981, taken from the BSD file netinet/in.h.
' IPv6 additions per RFC 2292.
'

'
' Port/socket numbers: network standard functions
'
%IPPORT_ECHO           = 7
%IPPORT_DISCARD        = 9
%IPPORT_SYSTAT         = 11
%IPPORT_DAYTIME        = 13
%IPPORT_NETSTAT        = 15
%IPPORT_FTP            = 21
%IPPORT_TELNET         = 23
%IPPORT_SMTP           = 25
%IPPORT_TIMESERVER     = 37
%IPPORT_NAMESERVER     = 42
%IPPORT_WHOIS          = 43
%IPPORT_MTP            = 57

'
' Port/socket numbers: host specific functions
'
%IPPORT_TFTP           = 69
%IPPORT_RJE            = 77
%IPPORT_FINGER         = 79
%IPPORT_TTYLINK        = 87
%IPPORT_SUPDUP         = 95

'
' UNIX TCP sockets
'
%IPPORT_EXECSERVER     = 512
%IPPORT_LOGINSERVER    = 513
%IPPORT_CMDSERVER      = 514
%IPPORT_EFSSERVER      = 520

'
' UNIX UDP sockets
'
%IPPORT_BIFFUDP        = 512
%IPPORT_WHOSERVER      = 513
%IPPORT_ROUTESERVER    = 520
                                        ' 520+1 also used

'
' Ports < %IPPORT_RESERVED are reserved for
' privileged processes (e.g. root).
'
%IPPORT_RESERVED       = 1024

'
' Link numbers
'
%IMPLINK_IP            = 155
%IMPLINK_LOWEXPER      = 156
%IMPLINK_HIGHEXPER     = 158

'
' Internet address (old style... should be updated)
'
#INCLUDE "inaddr.inc"

%ADDR_ANY = %INADDR_ANY

%WSADESCRIPTION_LEN    = 256
%WSASYS_STATUS_LEN     = 128

TYPE WSADATA
    wVersion       AS WORD
    wHighVersion   AS WORD
#IF %DEF(%WIN64)
    iMaxSockets    AS WORD
    iMaxUdpDg      AS WORD
    lpVendorInfo   AS ASCIIZ PTR
    szDescription  AS ASCIIZ * %WSADESCRIPTION_LEN+1
    szSystemStatus AS ASCIIZ * %WSASYS_STATUS_LEN+1
#ELSE
    szDescription  AS ASCIIZ * %WSADESCRIPTION_LEN+1
    szSystemStatus AS ASCIIZ * %WSASYS_STATUS_LEN+1
    iMaxSockets    AS WORD
    iMaxUdpDg      AS WORD
    lpVendorInfo   AS ASCIIZ PTR
#ENDIF
END TYPE

'
' Definitions related to sockets: types, address families, options,
' taken from the BSD file sys/socket.h.
'

'
' This is used instead of -1, since the
' SOCKET type is unsigned.
'
%INVALID_SOCKET = &HFFFFFFFF???  ' (SOCKET)(~0)
%SOCKET_ERROR   = (-1)

'
' The  following  may  be used in place of the address family, socket type, or
' protocol  in  a  call  to WSASocket to indicate that the corresponding value
' should  be taken from the supplied WSAPROTOCOL_INFO structure instead of the
' parameter itself.
'
%FROM_PROTOCOL_INFO = (-1)


'
' Structure used by kernel to pass protocol
' information in raw sockets.
'
TYPE sockproto
    sp_family   AS WORD     ' address family
    sp_protocol AS WORD     ' protocol
END TYPE

'
' Protocol families, same as address families for now.
'
%PF_UNSPEC      = %AF_UNSPEC
%PF_UNIX        = %AF_UNIX
%PF_INET        = %AF_INET
%PF_IMPLINK     = %AF_IMPLINK
%PF_PUP         = %AF_PUP
%PF_CHAOS       = %AF_CHAOS
%PF_NS          = %AF_NS
%PF_IPX         = %AF_IPX
%PF_ISO         = %AF_ISO
%PF_OSI         = %AF_OSI
%PF_ECMA        = %AF_ECMA
%PF_DATAKIT     = %AF_DATAKIT
%PF_CCITT       = %AF_CCITT
%PF_SNA         = %AF_SNA
%PF_DECnet      = %AF_DECnet
%PF_DLI         = %AF_DLI
%PF_LAT         = %AF_LAT
%PF_HYLINK      = %AF_HYLINK
%PF_APPLETALK   = %AF_APPLETALK
%PF_VOICEVIEW   = %AF_VOICEVIEW
%PF_FIREFOX     = %AF_FIREFOX
%PF_UNKNOWN1    = %AF_UNKNOWN1
%PF_BAN         = %AF_BAN
%PF_ATM         = %AF_ATM
%PF_INET6       = %AF_INET6
#IF (%WIN32_WINNT >= &H0600)
%PF_BTH         = %AF_BTH
#ENDIF '(%WIN32_WINNT >= &H0600)

%PF_MAX         = %AF_MAX

'
' Structure used for manipulating linger option.
'
TYPE linger
    l_onoff  AS WORD        ' option on/off
    l_linger AS WORD        ' linger time
END TYPE

'
' Maximum queue length specifiable by listen.
'
%SOMAXCONN     = &H7fffffff

%MSG_OOB       = &H1             ' process out-of-band data
%MSG_PEEK      = &H2             ' peek at incoming message
%MSG_DONTROUTE = &H4             ' send without using routing tables

#IF (%WIN32_WINNT >= &H0502)
%MSG_WAITALL   = &H8             ' do not complete until packet is completely filled
#ENDIF '(%WIN32_WINNT >= &H0502)

%MSG_PARTIAL   = &H8000??        ' partial send or recv for message xport

'
' WinSock 2 extension -- new flags for WSASend(), WSASendTo(), WSARecv() and
'                          WSARecvFrom()
'
%MSG_INTERRUPT = &H10            ' send/recv in the interrupt context

%MSG_MAXIOVLEN = 16

'
' Define constant based on rfc883, used by gethostbyxxxx() calls.
'
%MAXGETHOSTSTRUCT      = 1024

'
' WinSock 2 extension -- bit values and indices for FD_XXX network events
'
%FD_READ_BIT      = 0
%FD_READ          = &B1          ' (1 << FD_READ_BIT)

%FD_WRITE_BIT     = 1
%FD_WRITE         = &B10         ' (1 << FD_WRITE_BIT)

%FD_OOB_BIT       = 2
%FD_OOB           = &B100        ' (1 << FD_OOB_BIT)

%FD_ACCEPT_BIT    = 3
%FD_ACCEPT        = &B1000       ' (1 << FD_ACCEPT_BIT)

%FD_CONNECT_BIT   = 4
%FD_CONNECT       = &B10000      ' (1 << FD_CONNECT_BIT)

%FD_CLOSE_BIT     = 5
%FD_CLOSE         = &B100000     ' (1 << FD_CLOSE_BIT)

%FD_QOS_BIT       = 6
%FD_QOS           = &B1000000    ' (1 << FD_QOS_BIT)

%FD_GROUP_QOS_BIT = 7
%FD_GROUP_QOS     = &B10000000   ' (1 << FD_GROUP_QOS_BIT)

%FD_ROUTING_INTERFACE_CHANGE_BIT = 8
%FD_ROUTING_INTERFACE_CHANGE     = &B100000000
                                 ' (1 << FD_ROUTING_INTERFACE_CHANGE_BIT)

%FD_ADDRESS_LIST_CHANGE_BIT      = 9
%FD_ADDRESS_LIST_CHANGE          = &B1000000000
                                 ' (1 << FD_ADDRESS_LIST_CHANGE_BIT)

%FD_MAX_EVENTS    = 10
%FD_ALL_EVENTS    = &B10000000000 - 1   ' ((1 << FD_MAX_EVENTS) - 1)


'
' WinSock error codes are also defined in winerror.h
' Hence the IFDEF.
'
#IF NOT %DEF(%WSABASEERR)

'
' All Windows Sockets error constants are biased by WSABASEERR from
' the "normal"
'
%WSABASEERR             = 10000

'
' Windows Sockets definitions of regular Microsoft C error constants
'
%WSAEINTR               = (%WSABASEERR+4)
%WSAEBADF               = (%WSABASEERR+9)
%WSAEACCES              = (%WSABASEERR+13)
%WSAEFAULT              = (%WSABASEERR+14)
%WSAEINVAL              = (%WSABASEERR+22)
%WSAEMFILE              = (%WSABASEERR+24)

'
' Windows Sockets definitions of regular Berkeley error constants
'
%WSAEWOULDBLOCK         = (%WSABASEERR+35)
%WSAEINPROGRESS         = (%WSABASEERR+36)
%WSAEALREADY            = (%WSABASEERR+37)
%WSAENOTSOCK            = (%WSABASEERR+38)
%WSAEDESTADDRREQ        = (%WSABASEERR+39)
%WSAEMSGSIZE            = (%WSABASEERR+40)
%WSAEPROTOTYPE          = (%WSABASEERR+41)
%WSAENOPROTOOPT         = (%WSABASEERR+42)
%WSAEPROTONOSUPPORT     = (%WSABASEERR+43)
%WSAESOCKTNOSUPPORT     = (%WSABASEERR+44)
%WSAEOPNOTSUPP          = (%WSABASEERR+45)
%WSAEPFNOSUPPORT        = (%WSABASEERR+46)
%WSAEAFNOSUPPORT        = (%WSABASEERR+47)
%WSAEADDRINUSE          = (%WSABASEERR+48)
%WSAEADDRNOTAVAIL       = (%WSABASEERR+49)
%WSAENETDOWN            = (%WSABASEERR+50)
%WSAENETUNREACH         = (%WSABASEERR+51)
%WSAENETRESET           = (%WSABASEERR+52)
%WSAECONNABORTED        = (%WSABASEERR+53)
%WSAECONNRESET          = (%WSABASEERR+54)
%WSAENOBUFS             = (%WSABASEERR+55)
%WSAEISCONN             = (%WSABASEERR+56)
%WSAENOTCONN            = (%WSABASEERR+57)
%WSAESHUTDOWN           = (%WSABASEERR+58)
%WSAETOOMANYREFS        = (%WSABASEERR+59)
%WSAETIMEDOUT           = (%WSABASEERR+60)
%WSAECONNREFUSED        = (%WSABASEERR+61)
%WSAELOOP               = (%WSABASEERR+62)
%WSAENAMETOOLONG        = (%WSABASEERR+63)
%WSAEHOSTDOWN           = (%WSABASEERR+64)
%WSAEHOSTUNREACH        = (%WSABASEERR+65)
%WSAENOTEMPTY           = (%WSABASEERR+66)
%WSAEPROCLIM            = (%WSABASEERR+67)
%WSAEUSERS              = (%WSABASEERR+68)
%WSAEDQUOT              = (%WSABASEERR+69)
%WSAESTALE              = (%WSABASEERR+70)
%WSAEREMOTE             = (%WSABASEERR+71)

'
' Extended Windows Sockets error constant definitions
'
%WSASYSNOTREADY         = (%WSABASEERR+91)
%WSAVERNOTSUPPORTED     = (%WSABASEERR+92)
%WSANOTINITIALISED      = (%WSABASEERR+93)
%WSAEDISCON             = (%WSABASEERR+101)
%WSAENOMORE             = (%WSABASEERR+102)
%WSAECANCELLED          = (%WSABASEERR+103)
%WSAEINVALIDPROCTABLE   = (%WSABASEERR+104)
%WSAEINVALIDPROVIDER    = (%WSABASEERR+105)
%WSAEPROVIDERFAILEDINIT = (%WSABASEERR+106)
%WSASYSCALLFAILURE      = (%WSABASEERR+107)
%WSASERVICE_NOT_FOUND   = (%WSABASEERR+108)
%WSATYPE_NOT_FOUND      = (%WSABASEERR+109)
%WSA_E_NO_MORE          = (%WSABASEERR+110)
%WSA_E_CANCELLED        = (%WSABASEERR+111)
%WSAEREFUSED            = (%WSABASEERR+112)

'
' Error return codes from gethostbyname() and gethostbyaddr()
' (when using the resolver). Note that these errors are
' retrieved via WSAGetLastError() and must therefore follow
' the rules for avoiding clashes with error numbers from
' specific implementations or language run-time systems.
' For this reason the codes are based at WSABASEERR+1001.
' Note also that [WSA]NO_ADDRESS is defined only for
' compatibility purposes.
'

' Authoritative Answer: Host not found
%WSAHOST_NOT_FOUND       = (%WSABASEERR+1001)

' Non-Authoritative: Host not found, or SERVERFAIL
%WSATRY_AGAIN            = (%WSABASEERR+1002)

' Non-recoverable errors, FORMERR, REFUSED, NOTIMP
%WSANO_RECOVERY          = (%WSABASEERR+1003)

' Valid name, no data record of requested type
%WSANO_DATA              = (%WSABASEERR+1004)

'
' Define QOS related error return codes
'
'
%WSA_QOS_RECEIVERS              = (%WSABASEERR + 1005)
         ' at least one Reserve has arrived
%WSA_QOS_SENDERS                = (%WSABASEERR + 1006)
         ' at least one Path has arrived
%WSA_QOS_NO_SENDERS             = (%WSABASEERR + 1007)
         ' there are no senders
%WSA_QOS_NO_RECEIVERS           = (%WSABASEERR + 1008)
         ' there are no receivers
%WSA_QOS_REQUEST_CONFIRMED      = (%WSABASEERR + 1009)
         ' Reserve has been confirmed
%WSA_QOS_ADMISSION_FAILURE      = (%WSABASEERR + 1010)
         ' error due to lack of resources
%WSA_QOS_POLICY_FAILURE         = (%WSABASEERR + 1011)
         ' rejected for administrative reasons - bad credentials
%WSA_QOS_BAD_STYLE              = (%WSABASEERR + 1012)
         ' unknown or conflicting style
%WSA_QOS_BAD_OBJECT             = (%WSABASEERR + 1013)
         ' problem with some part of the filterspec or providerspecific
         ' buffer in general
%WSA_QOS_TRAFFIC_CTRL_ERROR     = (%WSABASEERR + 1014)
         ' problem with some part of the flowspec
%WSA_QOS_GENERIC_ERROR          = (%WSABASEERR + 1015)
         ' general error
%WSA_QOS_ESERVICETYPE           = (%WSABASEERR + 1016)
         ' invalid service type in flowspec
%WSA_QOS_EFLOWSPEC              = (%WSABASEERR + 1017)
         ' invalid flowspec
%WSA_QOS_EPROVSPECBUF           = (%WSABASEERR + 1018)
         ' invalid provider specific buffer
%WSA_QOS_EFILTERSTYLE           = (%WSABASEERR + 1019)
         ' invalid filter style
%WSA_QOS_EFILTERTYPE            = (%WSABASEERR + 1020)
         ' invalid filter type
%WSA_QOS_EFILTERCOUNT           = (%WSABASEERR + 1021)
         ' incorrect number of filters
%WSA_QOS_EOBJLENGTH             = (%WSABASEERR + 1022)
         ' invalid object length
%WSA_QOS_EFLOWCOUNT             = (%WSABASEERR + 1023)
         ' incorrect number of flows
%WSA_QOS_EUNKOWNPSOBJ           = (%WSABASEERR + 1024)
         ' unknown object in provider specific buffer
%WSA_QOS_EPOLICYOBJ             = (%WSABASEERR + 1025)
         ' invalid policy object in provider specific buffer
%WSA_QOS_EFLOWDESC              = (%WSABASEERR + 1026)
         ' invalid flow descriptor in the list
%WSA_QOS_EPSFLOWSPEC            = (%WSABASEERR + 1027)
         ' inconsistent flow spec in provider specific buffer
%WSA_QOS_EPSFILTERSPEC          = (%WSABASEERR + 1028)
         ' invalid filter spec in provider specific buffer
%WSA_QOS_ESDMODEOBJ             = (%WSABASEERR + 1029)
         ' invalid shape discard mode object in provider specific buffer
%WSA_QOS_ESHAPERATEOBJ          = (%WSABASEERR + 1030)
         ' invalid shaping rate object in provider specific buffer
%WSA_QOS_RESERVED_PETYPE        = (%WSABASEERR + 1031)
         ' reserved policy element in provider specific buffer



'
' WinSock error codes are also defined in winerror.inc
' Hence the IFDEF.
'
#ENDIF ' if %def(%WSABASEERR)

'
' Compatibility macros.
'

MACRO h_errno = WSAGetLastError()
%HOST_NOT_FOUND         = %WSAHOST_NOT_FOUND
%TRY_AGAIN              = %WSATRY_AGAIN
%NO_RECOVERY            = %WSANO_RECOVERY
%NO_DATA                = %WSANO_DATA
' no address, look for MX record
%WSANO_ADDRESS          = %WSANO_DATA
%NO_ADDRESS             = %WSANO_ADDRESS



'
' Windows Sockets errors redefined as regular Berkeley error constants.
' These are commented out in Windows NT to avoid conflicts with errno.h.
' Use the WSA constants instead.
'
#IF 0
%EWOULDBLOCK           = %WSAEWOULDBLOCK
%EINPROGRESS           = %WSAEINPROGRESS
%EALREADY              = %WSAEALREADY
%ENOTSOCK              = %WSAENOTSOCK
%EDESTADDRREQ          = %WSAEDESTADDRREQ
%EMSGSIZE              = %WSAEMSGSIZE
%EPROTOTYPE            = %WSAEPROTOTYPE
%ENOPROTOOPT           = %WSAENOPROTOOPT
%EPROTONOSUPPORT       = %WSAEPROTONOSUPPORT
%ESOCKTNOSUPPORT       = %WSAESOCKTNOSUPPORT
%EOPNOTSUPP            = %WSAEOPNOTSUPP
%EPFNOSUPPORT          = %WSAEPFNOSUPPORT
%EAFNOSUPPORT          = %WSAEAFNOSUPPORT
%EADDRINUSE            = %WSAEADDRINUSE
%EADDRNOTAVAIL         = %WSAEADDRNOTAVAIL
%ENETDOWN              = %WSAENETDOWN
%ENETUNREACH           = %WSAENETUNREACH
%ENETRESET             = %WSAENETRESET
%ECONNABORTED          = %WSAECONNABORTED
%ECONNRESET            = %WSAECONNRESET
%ENOBUFS               = %WSAENOBUFS
%EISCONN               = %WSAEISCONN
%ENOTCONN              = %WSAENOTCONN
%ESHUTDOWN             = %WSAESHUTDOWN
%ETOOMANYREFS          = %WSAETOOMANYREFS
%ETIMEDOUT             = %WSAETIMEDOUT
%ECONNREFUSED          = %WSAECONNREFUSED
%ELOOP                 = %WSAELOOP
%ENAMETOOLONG          = %WSAENAMETOOLONG
%EHOSTDOWN             = %WSAEHOSTDOWN
%EHOSTUNREACH          = %WSAEHOSTUNREACH
%ENOTEMPTY             = %WSAENOTEMPTY
%EPROCLIM              = %WSAEPROCLIM
%EUSERS                = %WSAEUSERS
%EDQUOT                = %WSAEDQUOT
%ESTALE                = %WSAESTALE
%EREMOTE               = %WSAEREMOTE
#ENDIF

'
' WinSock 2 extension -- new error codes and type definition
'

#IF %DEF(%WIN32)

'#define WSAAPI                  FAR PASCAL

MACRO WSAEVENT=DWORD
'              HANDLE

'#define LPWSAEVENT              LPHANDLE

TYPE WSAOVERLAPPED
    OVERLAPPED
END TYPE

'typedef struct _OVERLAPPED *    LPWSAOVERLAPPED;

%WSA_IO_PENDING         = (%ERROR_IO_PENDING)
%WSA_IO_INCOMPLETE      = (%ERROR_IO_INCOMPLETE)
%WSA_INVALID_HANDLE     = (%ERROR_INVALID_HANDLE)
%WSA_INVALID_PARAMETER  = (%ERROR_INVALID_PARAMETER)
%WSA_NOT_ENOUGH_MEMORY  = (%ERROR_NOT_ENOUGH_MEMORY)
%WSA_OPERATION_ABORTED  = (%ERROR_OPERATION_ABORTED)

%WSA_INVALID_EVENT       = (%NULL)
%WSA_MAXIMUM_WAIT_EVENTS = (%MAXIMUM_WAIT_OBJECTS)
%WSA_WAIT_FAILED         = (%WAIT_FAILED)
%WSA_WAIT_EVENT_0        = (%WAIT_OBJECT_0)
%WSA_WAIT_IO_COMPLETION  = (%WAIT_IO_COMPLETION)
%WSA_WAIT_TIMEOUT        = (%WAIT_TIMEOUT)
%WSA_INFINITE            = (%INFINITE)

#ELSE ' WIN16

'#define WSAAPI                  FAR PASCAL
MACRO WSAEVENT=DWORD

TYPE WSAOVERLAPPED
    Internal     AS DWORD
    InternalHigh AS DWORD
    Offset       AS DWORD
    OffsetHigh   AS DWORD
    hEvent       AS WSAEVENT
END TYPE

%WSA_IO_PENDING          = (%WSAEWOULDBLOCK)
%WSA_IO_INCOMPLETE       = (%WSAEWOULDBLOCK)
%WSA_INVALID_HANDLE      = (%WSAENOTSOCK)
%WSA_INVALID_PARAMETER   = (%WSAEINVAL)
%WSA_NOT_ENOUGH_MEMORY   = (%WSAENOBUFS)
%WSA_OPERATION_ABORTED   = (%WSAEINTR)

%WSA_INVALID_EVENT       = (%(WSAEVENT)NULL)
%WSA_MAXIMUM_WAIT_EVENTS = (%MAXIMUM_WAIT_OBJECTS)
%WSA_WAIT_FAILED         = &HFFFFFFFF??? ' ((DWORD)-1L)
%WSA_WAIT_EVENT_0        = 0
%WSA_WAIT_TIMEOUT        = H102
%WSA_INFINITE            = &HFFFFFFFF??? ' ((DWORD)-1L)

#ENDIF  ' WIN32

'
' Include qos.h to pull in FLOWSPEC and related definitions
'
#INCLUDE "qos.inc"

TYPE QOS
    SendingFlowspec   AS FLOWSPEC   ' the flow spec for data sending
    ReceivingFlowspec AS FLOWSPEC   ' the flow spec for data receiving
    ProviderSpecific  AS WSABUF     ' additional provider specific stuff
END TYPE

'
' WinSock 2 extension -- manifest constants for return values of the condition function
'
%CF_ACCEPT     = &H0000
%CF_REJECT     = &H0001
%CF_DEFER      = &H0002

'
' WinSock 2 extension -- manifest constants for shutdown()
'
%SD_RECEIVE    = &H00
%SD_SEND       = &H01
%SD_BOTH       = &H02

'
' WinSock 2 extension -- data type and manifest constants for socket groups
'
'macro GROUP=DWORD

%SG_UNCONSTRAINED_GROUP = &H01
%SG_CONSTRAINED_GROUP   = &H02

'
' WinSock 2 extension -- data type for WSAEnumNetworkEvents()
'
TYPE WSANETWORKEVENTS
    lNetworkEvents               AS LONG
    iErrorCode(%FD_MAX_EVENTS-1) AS LONG
END TYPE

'
' WinSock 2 extension -- WSAPROTOCOL_INFO structure and associated
' manifest constants
'

'#include "guiddef.inc"

%MAX_PROTOCOL_CHAIN = 7

%BASE_PROTOCOL      = 1
%LAYERED_PROTOCOL   = 0

TYPE WSAPROTOCOLCHAIN
    ChainLen AS LONG   ' the length of the chain,
                       ' length = 0 means layered protocol,
                       ' length = 1 means base protocol,
                       ' length > 1 means protocol chain
    ChainEntries(%MAX_PROTOCOL_CHAIN-1) AS DWORD  ' a list of dwCatalogEntryIds
END TYPE

%WSAPROTOCOL_LEN = 255

TYPE WSAPROTOCOL_INFOA
    dwServiceFlags1    AS DWORD
    dwServiceFlags2    AS DWORD
    dwServiceFlags3    AS DWORD
    dwServiceFlags4    AS DWORD
    dwProviderFlags    AS DWORD
    ProviderId         AS GUID
    dwCatalogEntryId   AS DWORD
    ProtocolChain      AS WSAPROTOCOLCHAIN
    iVersion           AS LONG
    iAddressFamily     AS LONG
    iMaxSockAddr       AS LONG
    iMinSockAddr       AS LONG
    iSocketType        AS LONG
    iProtocol          AS LONG
    iProtocolMaxOffset AS LONG
    iNetworkByteOrder  AS LONG
    iSecurityScheme    AS LONG
    dwMessageSize      AS DWORD
    dwProviderReserved AS DWORD
    szProtocol         AS ASCIIZ * %WSAPROTOCOL_LEN+1
END TYPE

TYPE WSAPROTOCOL_INFOW
    dwServiceFlags1    AS DWORD
    dwServiceFlags2    AS DWORD
    dwServiceFlags3    AS DWORD
    dwServiceFlags4    AS DWORD
    dwProviderFlags    AS DWORD
    ProviderId         AS GUID
    dwCatalogEntryId   AS DWORD
    ProtocolChain      AS WSAPROTOCOLCHAIN
    iVersion           AS LONG
    iAddressFamily     AS LONG
    iMaxSockAddr       AS LONG
    iMinSockAddr       AS LONG
    iSocketType        AS LONG
    iProtocol          AS LONG
    iProtocolMaxOffset AS LONG
    iNetworkByteOrder  AS LONG
    iSecurityScheme    AS LONG
    dwMessageSize      AS DWORD
    dwProviderReserved AS DWORD
    szProtocol         AS WSTRINGZ * %WSAPROTOCOL_LEN+1
END TYPE

#IF %DEF(%UNICODE)
TYPE WSAPROTOCOL_INFO
    WSAPROTOCOL_INFOW
END TYPE
#ELSE
TYPE WSAPROTOCOL_INFO
    WSAPROTOCOL_INFOA
END TYPE
#ENDIF ' UNICODE

' Flag bit definitions for dwProviderFlags
%PFL_MULTIPLE_PROTO_ENTRIES        = &H00000001
%PFL_RECOMMENDED_PROTO_ENTRY       = &H00000002
%PFL_HIDDEN                        = &H00000004
%PFL_MATCHES_PROTOCOL_ZERO         = &H00000008
%PFL_NETWORKDIRECT_PROVIDER        = &H00000010

' Flag bit definitions for dwServiceFlags1
%XP1_CONNECTIONLESS                = &H00000001
%XP1_GUARANTEED_DELIVERY           = &H00000002
%XP1_GUARANTEED_ORDER              = &H00000004
%XP1_MESSAGE_ORIENTED              = &H00000008
%XP1_PSEUDO_STREAM                 = &H00000010
%XP1_GRACEFUL_CLOSE                = &H00000020
%XP1_EXPEDITED_DATA                = &H00000040
%XP1_CONNECT_DATA                  = &H00000080
%XP1_DISCONNECT_DATA               = &H00000100
%XP1_SUPPORT_BROADCAST             = &H00000200
%XP1_SUPPORT_MULTIPOINT            = &H00000400
%XP1_MULTIPOINT_CONTROL_PLANE      = &H00000800
%XP1_MULTIPOINT_DATA_PLANE         = &H00001000
%XP1_QOS_SUPPORTED                 = &H00002000
%XP1_INTERRUPT                     = &H00004000
%XP1_UNI_SEND                      = &H00008000
%XP1_UNI_RECV                      = &H00010000
%XP1_IFS_HANDLES                   = &H00020000
%XP1_PARTIAL_MESSAGE               = &H00040000
%XP1_SAN_SUPPORT_SDP               = &H00080000

%BIGENDIAN                         = &H0000
%LITTLEENDIAN                      = &H0001

%SECURITY_PROTOCOL_NONE            = &H0000

'
' WinSock 2 extension -- manifest constants for WSAJoinLeaf()
'
%JL_SENDER_ONLY   = &H01
%JL_RECEIVER_ONLY = &H02
%JL_BOTH          = &H04

'
' WinSock 2 extension -- manifest constants for WSASocket()
'
%WSA_FLAG_OVERLAPPED            = &H01
%WSA_FLAG_MULTIPOINT_C_ROOT     = &H02
%WSA_FLAG_MULTIPOINT_C_LEAF     = &H04
%WSA_FLAG_MULTIPOINT_D_ROOT     = &H08
%WSA_FLAG_MULTIPOINT_D_LEAF     = &H10
%WSA_FLAG_ACCESS_SYSTEM_SECURITY= &H40

'
' WinSock 2 extensions -- data types for the condition function in
' WSAAccept() and overlapped I/O completion routine.
'

DECLARE FUNCTION LPCONDITIONPROC ( _
    lpCallerId     AS WSABUF, _
    lpCallerData   AS WSABUF, _
    lpSQOS         AS QOS, _
    lpGQOS         AS QOS, _
    lpCalleeIf     AS WSABUF, _
    lpCalleeData   AS WSABUF, _
    g              AS DWORD, _  ' GROUP *
    dwCallbackData AS DWORD _
    ) AS LONG

DECLARE SUB LPWSAOVERLAPPED_COMPLETION_ROUTINE ( _
    BYVAL dwError       AS DWORD, _
    BYVAL cbTransferred AS DWORD, _
    lpOverlapped        AS WSAOVERLAPPED, _
    BYVAL dwFlags       AS DWORD _
    )

#IF (%WIN32_WINNT >= &H0501)

'
' WinSock 2 extension -- manifest constants and associated structures
' for WSANSPIoctl()
'

%SIO_NSP_NOTIFY_CHANGE = &H88000019???   ' _WSAIOW(IOC_WS2,25)

MACRO WSACOMPLETIONTYPE_enum=LONG
ENUM WSACOMPLETIONTYPE SINGULAR
    NSP_NOTIFY_IMMEDIATELY
    NSP_NOTIFY_HWND
    NSP_NOTIFY_EVENT
    NSP_NOTIFY_PORT
    NSP_NOTIFY_APC
END ENUM

TYPE WSACOMPLETION_union_type1
    hWnd    AS DWORD  ' HWND
    uMsg    AS DWORD
    context AS DWORD  ' WPARAM
END TYPE

TYPE WSACOMPLETION_union_type2
    lpOverlapped AS WSAOVERLAPPED PTR
END TYPE

TYPE WSACOMPLETION_union_type3
    lpOverlapped       AS WSAOVERLAPPED PTR
    lpfnCompletionProc AS DWORD  ' LPWSAOVERLAPPED_COMPLETION_ROUTINE
END TYPE

TYPE WSACOMPLETION_union_type4
    lpOverlapped AS WSAOVERLAPPED PTR
    hPort        AS DWORD  ' HANDLE
    KEY          AS DWORD  ' ULONG_PTR
END TYPE

UNION WSACOMPLETION_union
    WindowMessage AS WSACOMPLETION_union_type1
    EVENT         AS WSACOMPLETION_union_type2
    Apc           AS WSACOMPLETION_union_type3
    PORT          AS WSACOMPLETION_union_type4
END UNION

TYPE WSACOMPLETION
    TYPE       AS WSACOMPLETIONTYPE_enum
    Parameters AS WSACOMPLETION_union
END TYPE

#ENDIF '(%WIN32_WINNT >= &H0501)

'
' WinSock 2 extension -- manifest constants for SIO_TRANSLATE_HANDLE ioctl
'
%TH_NETDEV       = &H00000001
%TH_TAPI         = &H00000002

'
' Manifest constants and type definitions related to name resolution and
' registration (RNR) API
'

#IF NOT %DEF(%tagBLOB_DEFINED)
%tagBLOB_DEFINED = 1
%BLOB_DEFINED    = 1
%LPBLOB_DEFINED  = 1
TYPE BLOB
    cbSize    AS DWORD
    pBlobData AS BYTE PTR
END TYPE
#ENDIF

'
' Service Install Flags
'

%SERVICE_MULTIPLE     = (&H00000001)

'
'& Name Spaces
'

%NS_ALL                    = (0)

%NS_SAP                    = (1)
%NS_NDS                    = (2)
%NS_PEER_BROWSE            = (3)
%NS_SLP                    = (5)
%NS_DHCP                   = (6)

%NS_TCPIP_LOCAL            = (10)
%NS_TCPIP_HOSTS            = (11)
%NS_DNS                    = (12)
%NS_NETBT                  = (13)
%NS_WINS                   = (14)

#IF (%WIN32_WINNT >= &H0501)
%NS_NLA                    = (15)    ' Network Location Awareness
#ENDIF '(%WIN32_WINNT >= &H0501)

#IF (%WIN32_WINNT >= &H0600)
%NS_BTH                    = (16)    ' Bluetooth SDP Namespace
#ENDIF '(%WIN32_WINNT >= &H0600)

%NS_NBP                    = (20)

%NS_MS                     = (30)
%NS_STDA                   = (31)
%NS_NTDS                   = (32)

#IF (%WIN32_WINNT >= &H0600)
%NS_EMAIL                  = (37)
%NS_PNRPNAME               = (38)
%NS_PNRPCLOUD              = (39)
#ENDIF '(%WIN32_WINNT >= &H0600)

%NS_X500                   = (40)
%NS_NIS                    = (41)
%NS_NISPLUS                = (42)

%NS_WRQ                    = (50)

%NS_NETDES                 = (60)    ' Network Designers Limited

'
'& Name Spaces
'

%NS_ALL                    = (0)

%NS_SAP                    = (1)
%NS_NDS                    = (2)
%NS_PEER_BROWSE            = (3)
%NS_SLP                    = (5)
%NS_DHCP                   = (6)

%NS_TCPIP_LOCAL            = (10)
%NS_TCPIP_HOSTS            = (11)
%NS_DNS                    = (12)
%NS_NETBT                  = (13)
%NS_WINS                   = (14)

#IF (%WIN32_WINNT >= &H0501)
%NS_NLA                    = (15)    ' Network Location Awareness
#ENDIF '(%WIN32_WINNT >= &H0501)

#IF (%WIN32_WINNT >= &H0600)
%NS_BTH                    = (16)    ' Bluetooth SDP Namespace
#ENDIF '(%WIN32_WINNT >= &H0600)

%NS_LOCALNAME              = (19)    ' Windows Live

%NS_NBP                    = (20)

%NS_MS                     = (30)
%NS_STDA                   = (31)
%NS_NTDS                   = (32)

#IF (%WIN32_WINNT >= &H0600)
%NS_EMAIL                  = (37)
%NS_PNRPNAME               = (38)
%NS_PNRPCLOUD              = (39)
#ENDIF '(%WIN32_WINNT >= &H0600)

%NS_X500                   = (40)
%NS_NIS                    = (41)
%NS_NISPLUS                = (42)

%NS_WRQ                    = (50)

%NS_NETDES                 = (60)    ' Network Designers Limited

'
' Resolution flags for WSAGetAddressByName().
' Note these are also used by the 1.1 API GetAddressByName, so
' leave them around.
'
%RES_UNUSED_1                = &H00000001
%RES_FLUSH_CACHE             = &H00000002
#IF NOT %DEF(%RES_SERVICE)
%RES_SERVICE                 = &H00000004
#ENDIF ' %RES_SERVICE

'
' Well known value names for Service Types
'

$SERVICE_TYPE_VALUE_IPXPORTA    = "IpxSocket"
$$SERVICE_TYPE_VALUE_IPXPORTW   = "IpxSocket"$$
$SERVICE_TYPE_VALUE_SAPIDA      = "SapId"
$$SERVICE_TYPE_VALUE_SAPIDW     = "SapId"$$

$SERVICE_TYPE_VALUE_TCPPORTA    = "TcpPort"
$$SERVICE_TYPE_VALUE_TCPPORTW   = "TcpPort"$$

$SERVICE_TYPE_VALUE_UDPPORTA    = "UdpPort"
$$SERVICE_TYPE_VALUE_UDPPORTW   = "UdpPort"$$

$SERVICE_TYPE_VALUE_OBJECTIDA   = "ObjectId"
$$SERVICE_TYPE_VALUE_OBJECTIDW  = "ObjectId"$$

#IF %DEF(%UNICODE)

MACRO SERVICE_TYPE_VALUE_SAPID    = $$SERVICE_TYPE_VALUE_SAPIDW
MACRO SERVICE_TYPE_VALUE_TCPPORT  = $$SERVICE_TYPE_VALUE_TCPPORTW
MACRO SERVICE_TYPE_VALUE_UDPPORT  = $$SERVICE_TYPE_VALUE_UDPPORTW
MACRO SERVICE_TYPE_VALUE_OBJECTID = $$SERVICE_TYPE_VALUE_OBJECTIDW

#ELSE ' not UNICODE

MACRO SERVICE_TYPE_VALUE_SAPID    =  $SERVICE_TYPE_VALUE_SAPIDA
MACRO SERVICE_TYPE_VALUE_TCPPORT  =  $SERVICE_TYPE_VALUE_TCPPORTA
MACRO SERVICE_TYPE_VALUE_UDPPORT  =  $SERVICE_TYPE_VALUE_UDPPORTA
MACRO SERVICE_TYPE_VALUE_OBJECTID =  $SERVICE_TYPE_VALUE_OBJECTIDA

#ENDIF

'
'  Address Family/Protocol Tuples
'
TYPE AFPROTOCOLS
    iAddressFamily AS LONG
    iProtocol      AS LONG
END TYPE

'
' Client Query API Typedefs
'

'
' The comparators
'
MACRO WSAECOMPARATOR_enum=LONG
ENUM WSAECOMPARATOR SINGULAR
    COMP_EQUAL
    COMP_NOTLESS
END ENUM

TYPE WSAVERSION
    dwVersion AS DWORD
    ecHow     AS WSAECOMPARATOR_enum
END TYPE

TYPE WSAQUERYSETA
    dwSize                  AS DWORD
    lpszServiceInstanceName AS ASCIIZ PTR
    lpServiceClassId        AS GUID PTR
    lpVersion               AS WSAVERSION PTR
    lpszComment             AS ASCIIZ PTR
    dwNameSpace             AS DWORD
    lpNSProviderId          AS GUID PTR
    lpszContext             AS ASCIIZ PTR
    dwNumberOfProtocols     AS DWORD
    lpafpProtocols          AS AFPROTOCOLS PTR
    lpszQueryString         AS ASCIIZ PTR
    dwNumberOfCsAddrs       AS DWORD
    lpcsaBuffer             AS CSADDR_INFO PTR
    dwOutputFlags           AS DWORD
    lpBlob                  AS BLOB PTR
END TYPE

TYPE WSAQUERYSETW
    dwSize                  AS DWORD
    lpszServiceInstanceName AS WSTRINGZ PTR
    lpServiceClassId        AS GUID PTR
    lpVersion               AS WSAVERSION PTR
    lpszComment             AS WSTRINGZ PTR
    dwNameSpace             AS DWORD
    lpNSProviderId          AS GUID PTR
    lpszContext             AS WSTRINGZ PTR
    dwNumberOfProtocols     AS DWORD
    lpafpProtocols          AS AFPROTOCOLS PTR
    lpszQueryString         AS WSTRINGZ PTR
    dwNumberOfCsAddrs       AS DWORD
    lpcsaBuffer             AS CSADDR_INFO PTR
    dwOutputFlags           AS DWORD
    lpBlob                  AS BLOB PTR
END TYPE

TYPE WSAQUERYSET2A
    dwSize                  AS DWORD
    lpszServiceInstanceName AS ASCIIZ PTR
    lpVersion               AS WSAVERSION PTR
    lpszComment             AS ASCIIZ PTR
    dwNameSpace             AS DWORD
    lpNSProviderId          AS GUID PTR
    lpszContext             AS ASCIIZ PTR
    dwNumberOfProtocols     AS DWORD
    lpafpProtocols          AS AFPROTOCOLS PTR
    lpszQueryString         AS ASCIIZ PTR
    dwNumberOfCsAddrs       AS DWORD
    lpcsaBuffer             AS CSADDR_INFO PTR
    dwOutputFlags           AS DWORD
    lpBlob                  AS BLOB PTR
END TYPE

TYPE WSAQUERYSET2W
    dwSize                  AS DWORD
    lpszServiceInstanceName AS WSTRINGZ PTR
    lpVersion               AS WSAVERSION PTR
    lpszComment             AS WSTRINGZ PTR
    dwNameSpace             AS DWORD
    lpNSProviderId          AS GUID PTR
    lpszContext             AS WSTRINGZ PTR
    dwNumberOfProtocols     AS DWORD
    lpafpProtocols          AS AFPROTOCOLS PTR
    lpszQueryString         AS WSTRINGZ PTR
    dwNumberOfCsAddrs       AS DWORD
    lpcsaBuffer             AS CSADDR_INFO PTR
    dwOutputFlags           AS DWORD
    lpBlob                  AS BLOB PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE WSAQUERYSET
    WSAQUERYSETW
END TYPE
TYPE WSAQUERYSET2
    WSAQUERYSET2W
END TYPE
#ELSE
TYPE WSAQUERYSET
    WSAQUERYSETA
END TYPE
TYPE WSAQUERYSET2
    WSAQUERYSET2A
END TYPE
#ENDIF ' UNICODE

%LUP_DEEP                   = &H0001
%LUP_CONTAINERS             = &H0002
%LUP_NOCONTAINERS           = &H0004
%LUP_NEAREST                = &H0008
%LUP_RETURN_NAME            = &H0010
%LUP_RETURN_TYPE            = &H0020
%LUP_RETURN_VERSION         = &H0040
%LUP_RETURN_COMMENT         = &H0080
%LUP_RETURN_ADDR            = &H0100
%LUP_RETURN_BLOB            = &H0200
%LUP_RETURN_ALIASES         = &H0400
%LUP_RETURN_QUERY_STRING    = &H0800
%LUP_RETURN_ALL             = &H0FF0
%LUP_RES_SERVICE            = &H8000??

%LUP_FLUSHCACHE             = &H1000
%LUP_FLUSHPREVIOUS          = &H2000

%LUP_NON_AUTHORITATIVE      = &H4000
%LUP_SECURE                 = &H8000??
%LUP_RETURN_PREFERRED_NAMES = &H10000

%LUP_ADDRCONFIG             = &H00100000
%LUP_DUAL_ADDR              = &H00200000
%LUP_FILESERVER             = &H00400000


'
' Return flags
'

%RESULT_IS_ALIAS       = &H0001
#IF (%WIN32_WINNT >= &H0501)
%RESULT_IS_ADDED       = &H0010
%RESULT_IS_CHANGED     = &H0020
%RESULT_IS_DELETED     = &H0040
#ENDIF '(%WIN32_WINNT >= &H0501)

'
' Service Address Registration and Deregistration Data Types.
'

MACRO WSAESETSERVICEOP_enum=LONG
ENUM WSAESETSERVICEOP SINGULAR
    RNRSERVICE_REGISTER
    RNRSERVICE_DEREGISTER
    RNRSERVICE_DELETE
END ENUM

'
' Service Installation/Removal Data Types.
'

TYPE WSANSCLASSINFOA
    lpszName    AS ASCIIZ PTR
    dwNameSpace AS DWORD
    dwValueType AS DWORD
    dwValueSize AS DWORD
    lpValue     AS DWORD  ' LPVOID
END TYPE

TYPE WSANSCLASSINFOW
    lpszName    AS WSTRINGZ PTR
    dwNameSpace AS DWORD
    dwValueType AS DWORD
    dwValueSize AS DWORD
    lpValue     AS DWORD  ' LPVOID
END TYPE

#IF %DEF(%UNICODE)
TYPE WSANSCLASSINFO
    WSANSCLASSINFOW
END TYPE
#ELSE
TYPE WSANSCLASSINFO
    WSANSCLASSINFOA
END TYPE
#ENDIF ' UNICODE

TYPE WSASERVICECLASSINFOA
    lpServiceClassId     AS GUID PTR
    lpszServiceClassName AS ASCIIZ PTR
    dwCount              AS DWORD
    lpClassInfos         AS WSANSCLASSINFOA PTR
END TYPE

TYPE WSASERVICECLASSINFOW
    lpServiceClassId     AS GUID PTR
    lpszServiceClassName AS WSTRINGZ PTR
    dwCount              AS DWORD
    lpClassInfos         AS WSANSCLASSINFOA PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE WSASERVICECLASSINFO
    WSASERVICECLASSINFOW
END TYPE
#ELSE
TYPE WSASERVICECLASSINFO
    WSASERVICECLASSINFOA
END TYPE
#ENDIF ' UNICODE

TYPE WSANAMESPACE_INFOA
    NSProviderId   AS GUID
    dwNameSpace    AS DWORD
    fActive        AS LONG  ' BOOL
    dwVersion      AS DWORD
    lpszIdentifier AS ASCIIZ PTR
END TYPE

TYPE WSANAMESPACE_INFOW
    NSProviderId   AS GUID
    dwNameSpace    AS DWORD
    fActive        AS LONG  ' BOOL
    dwVersion      AS DWORD
    lpszIdentifier AS WSTRINGZ PTR
END TYPE

TYPE WSANAMESPACE_INFOEXA
    NSProviderId     AS GUID
    dwNameSpace      AS DWORD
    fActive          AS LONG  ' BOOL
    dwVersion        AS DWORD
    lpszIdentifier   AS ASCIIZ PTR
    ProviderSpecific AS BLOB
END TYPE

TYPE WSANAMESPACE_INFOEXW
    NSProviderId     AS GUID
    dwNameSpace      AS DWORD
    fActive          AS LONG  ' BOOL
    dwVersion        AS DWORD
    lpszIdentifier   AS WSTRINGZ PTR
    ProviderSpecific AS BLOB
END TYPE

#IF %DEF(%UNICODE)
TYPE WSANAMESPACE_INFO
    WSANAMESPACE_INFOW
END TYPE
TYPE WSANAMESPACE_INFOEX
    WSANAMESPACE_INFOEXW
END TYPE
#ELSE
TYPE WSANAMESPACE_INFO
    WSANAMESPACE_INFOA
END TYPE
TYPE WSANAMESPACE_INFOEX
    WSANAMESPACE_INFOEXA
END TYPE
#ENDIF ' UNICODE


#IF (%WIN32_WINNT >= &H0600)

' Event flag definitions for WSAPoll().

%POLLRDNORM = &H0100
%POLLRDBAND = &H0200
%POLLIN     = (%POLLRDNORM OR %POLLRDBAND)
%POLLPRI    = &H0400

%POLLWRNORM = &H0010
%POLLOUT    = (%POLLWRNORM)
%POLLWRBAND = &H0020

%POLLERR    = &H0001
%POLLHUP    = &H0002
%POLLNVAL   = &H0004

TYPE WSAPOLLFD
    fd      AS DWORD    ' SOCKET
    EVENTS  AS INTEGER
    revents AS INTEGER
END TYPE

#ENDIF ' (%WIN32_WINNT >= &H0600)


' Socket function prototypes

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION aaccept LIB "ws2_32.dll" ALIAS "accept" ( _
    BYVAL s AS DWORD, _   ' SOCKET
    saAddr  AS SOCKADDR, _
    addrlen AS LONG _
    ) AS DWORD    ' SOCKET

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_ACCEPT ( _
    BYVAL s AS DWORD, _  ' SOCKET
    saAddr  AS SOCKADDR, _
    addrlen AS LONG _
    ) AS DWORD  ' SOCKET

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION bind LIB "ws2_32.dll" ALIAS "bind" ( _
    BYVAL s       AS DWORD, _   ' SOCKET
    sname         AS SOCKADDR, _
    BYVAL namelen AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_BIND ( _
    BYVAL s       AS DWORD, _   ' SOCKET
    sname         AS SOCKADDR, _
    BYVAL namelen AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION closesocket LIB "ws2_32.dll" ALIAS "closesocket" ( _
    BYVAL s AS DWORD _   ' SOCKET
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_CLOSESOCKET ( _
    BYVAL s AS DWORD _   ' SOCKET
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION cconnect LIB "ws2_32.dll" ALIAS "connect" ( _
    BYVAL s       AS DWORD, _  ' SOCKET
    sname         AS SOCKADDR, _
    BYVAL namelen AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_CONNECT ( _
    BYVAL s       AS DWORD, _  ' SOCKET
    sname         AS SOCKADDR, _
    BYVAL namelen AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION ioctlsocket LIB "ws2_32.dll" ALIAS "ioctlsocket" ( _
    BYVAL s   AS DWORD, _  ' SOCKET
    BYVAL cmd AS LONG, _
    argp      AS DWORD _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_IOCTLSOCKET ( _
    BYVAL s   AS DWORD, _  ' SOCKET
    BYVAL cmd AS LONG, _
    argp      AS DWORD _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION getpeername LIB "ws2_32.dll" ALIAS "getpeername" ( _
    BYVAL s AS DWORD, _   ' SOCKET
    sname   AS SOCKADDR, _
    namelen AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_GETPEERNAME ( _
    BYVAL s AS DWORD, _   ' SOCKET
    sname   AS SOCKADDR, _
    namelen AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION getsockname LIB "ws2_32.dll" ALIAS "getsockname" ( _
    BYVAL s AS DWORD, _   ' SOCKET
    sname   AS SOCKADDR, _
    namelen AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_GETSOCKNAME ( _
    BYVAL s AS DWORD, _   ' SOCKET
    sname   AS SOCKADDR, _
    namelen AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION getsockopt LIB "ws2_32.dll" ALIAS "getsockopt" ( _
    BYVAL s       AS DWORD, _   ' SOCKET
    BYVAL level   AS LONG, _
    BYVAL optname AS LONG, _
    optval        AS ASCIIZ, _
    optlen        AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_GETSOCKOPT ( _
    BYVAL s       AS DWORD, _   ' SOCKET
    BYVAL level   AS LONG, _
    BYVAL optname AS LONG, _
    optval        AS ASCIIZ, _
    optlen        AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION htonl LIB "ws2_32.dll" ALIAS "htonl" ( _
    BYVAL hostlong AS DWORD _
    ) AS DWORD

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_HTONL ( _
    BYVAL hostlong AS DWORD _
    ) AS DWORD

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION htons LIB "ws2_32.dll" ALIAS "htons" ( _
    BYVAL hostshort AS WORD _
    ) AS WORD

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_HTONS ( _
    BYVAL hostshort AS WORD _
    ) AS WORD

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION inet_addr LIB "ws2_32.dll" ALIAS "inet_addr" ( _
    cp AS ASCIIZ _
    ) AS DWORD

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_INET_ADDR ( _
    cp AS ASCIIZ _
    ) AS DWORD

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION inet_ntoa LIB "ws2_32.dll" ALIAS "inet_ntoa" ( _
    BYVAL inn AS in_addr _
    ) AS DWORD   ' ASCIIZ PTR

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_INET_NTOA ( _
    BYVAL inn AS in_addr _
    ) AS DWORD   ' ASCIIZ PTR

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION listen LIB "ws2_32.dll" ALIAS "listen" ( _
    BYVAL s       AS DWORD, _   ' SOCKET
    BYVAL backlog AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_LISTEN ( _
    BYVAL s       AS DWORD, _   ' SOCKET
    BYVAL backlog AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION ntohl LIB "ws2_32.dll" ALIAS "ntohl" ( _
    BYVAL netlong AS DWORD _
    ) AS DWORD

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_NTOHL ( _
    BYVAL netlong AS DWORD _
    ) AS DWORD

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION ntohs LIB "ws2_32.dll" ALIAS "ntohs" ( _
    BYVAL netshort AS WORD _
    ) AS WORD

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_NTOHS ( _
    BYVAL netshort AS WORD _
    ) AS WORD

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION rrecv LIB "ws2_32.dll" ALIAS "recv" ( _
    BYVAL s      AS DWORD, _   ' SOCKET
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG, _
    BYVAL flags  AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_RECV ( _
    BYVAL s      AS DWORD, _   ' SOCKET
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG, _
    BYVAL flags  AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION recvfrom LIB "ws2_32.dll" ALIAS "recvfrom" ( _
    BYVAL s      AS DWORD, _   ' SOCKET
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG, _
    BYVAL flags  AS LONG, _
    saFrom       AS SOCKADDR, _
    fromlen      AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_RECVFROM ( _
    BYVAL s      AS DWORD, _   ' SOCKET
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG, _
    BYVAL flags  AS LONG, _
    saFrom       AS SOCKADDR, _
    fromlen      AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION sselect LIB "ws2_32.dll" ALIAS "select" ( _
    BYVAL nfds AS LONG, _
    readfds    AS fd_set, _
    writefds   AS fd_set, _
    exceptfds  AS FD_SET, _
    tymeout    AS timeval _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_SELECT ( _
    BYVAL nfds AS LONG, _
    readfds    AS fd_set, _
    writefds   AS fd_set, _
    exceptfds  AS FD_SET, _
    tymeout    AS timeval _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION ssend LIB "ws2_32.dll" ALIAS "send" ( _
    BYVAL s      AS DWORD, _  ' SOCKET
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG, _
    BYVAL flags  AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_SEND ( _
    BYVAL s      AS DWORD, _  ' SOCKET
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG, _
    BYVAL flags  AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION sendto LIB "ws2_32.dll" ALIAS "sendto" ( _
    BYVAL s      AS DWORD, _
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG, _
    BYVAL flags  AS LONG, _
    to_addr      AS SOCKADDR, _
    BYVAL tolen  AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_SENDTO ( _
    BYVAL s      AS DWORD, _
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG, _
    BYVAL flags  AS LONG, _
    to_addr      AS SOCKADDR, _
    BYVAL tolen  AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION setsockopt LIB "ws2_32.dll" ALIAS "setsockopt" ( _
    BYVAL s       AS DWORD, _   ' SOCKET
    BYVAL level   AS LONG, _
    BYVAL optname AS LONG, _
    BYVAL optval  AS BYTE PTR, _
    BYVAL optlen  AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_SETSOCKOPT ( _
    BYVAL s       AS DWORD, _   ' SOCKET
    BYVAL level   AS LONG, _
    BYVAL optname AS LONG, _
    BYVAL optval  AS BYTE PTR, _
    BYVAL optlen  AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION shutdown LIB "ws2_32.dll" ALIAS "shutdown" ( _
    BYVAL s   AS DWORD, _  ' SOCKET
    BYVAL how AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_SHUTDOWN ( _
    BYVAL s   AS DWORD, _  ' SOCKET
    BYVAL how AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION socket LIB "ws2_32.dll" ALIAS "socket" ( _
    BYVAL af     AS LONG, _
    BYVAL s_type AS LONG, _
    BYVAL protocol AS LONG _
    ) AS DWORD   ' SOCKET

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_SOCKET ( _
    BYVAL af     AS LONG, _
    BYVAL s_type AS LONG, _
    BYVAL protocol AS LONG _
    ) AS DWORD   ' SOCKET

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

' Database function prototypes

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION gethostbyaddr LIB "ws2_32.dll"  ALIAS "gethostbyaddr" ( _
    BYVAL saAddr    AS BYTE PTR, _
    BYVAL addr_len  AS LONG, _
    BYVAL addr_type AS LONG _
    ) AS DWORD   ' hostent PTR

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_GETHOSTBYADDR ( _
    BYVAL saAddr    AS BYTE PTR, _
    BYVAL addr_len  AS LONG, _
    BYVAL addr_type AS LONG _
    ) AS DWORD   ' hostent PTR

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION gethostbyname LIB "ws2_32.dll" ALIAS "gethostbyname" ( _
    hname AS ASCIIZ _
    ) AS DWORD   ' hostent PTR

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_GETHOSTBYNAME ( _
    hname AS ASCIIZ _
    ) AS DWORD   ' hostent PTR

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION gethostname LIB "ws2_32.dll" ALIAS "gethostname" ( _
    host_name     AS ASCIIZ, _
    BYVAL namelen AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_GETHOSTNAME ( _
    host_name     AS ASCIIZ, _
    BYVAL namelen AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION getservbyport LIB "ws2_32.dll" ALIAS "getservbyport" ( _
    BYVAL lPort AS LONG, _
    proto       AS ASCIIZ _
    ) AS DWORD  ' servent PTR

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_GETSERVBYPORT ( _
    BYVAL lPort AS LONG, _
    proto       AS ASCIIZ _
    ) AS DWORD  ' servent PTR

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION getservbyname LIB "ws2_32.dll" ALIAS "getservbyname" ( _
    serv_name AS ASCIIZ, _
    proto AS ASCIIZ _
    ) AS DWORD  ' servent PTR

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_GETSERVBYNAME ( _
    serv_name AS ASCIIZ, _
    proto AS ASCIIZ _
    ) AS DWORD  ' servent PTR

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION getprotobynumber LIB "ws2_32.dll" ALIAS "getprotobynumber" ( _
    BYVAL proto AS LONG _
    ) AS DWORD  ' protoent PTR

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_GETPROTOBYNUMBER ( _
    BYVAL proto AS LONG _
    ) AS DWORD  ' protoent PTR

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION getprotobyname LIB "ws2_32.dll" ALIAS "getprotobyname" ( _
    proto_name AS ASCIIZ _
    ) AS DWORD  ' protoent PTR

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_GETPROTOBYNAME ( _
    proto_name AS ASCIIZ _
    ) AS DWORD  ' protoent PTR

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

' Microsoft Windows Extension function prototypes

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAStartup LIB "ws2_32.dll" ALIAS "WSAStartup" ( _
    BYVAL wVR AS WORD, _
    lpWSAD AS WSADATA _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSASTARTUP ( _
    BYVAL wVR AS WORD, _
    lpWSAD AS WSADATA _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSACleanup LIB "ws2_32.dll" ALIAS "WSACleanup" () AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSACLEANUP () AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE SUB WSASetLastError LIB "ws2_32.dll" ALIAS "WSASetLastError" ( _
    BYVAL iError AS LONG _
    )

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE SUB LPFN_WSASETLASTERROR ( _
    BYVAL iError AS LONG _
    )

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAGetLastError LIB "ws2_32.dll" ALIAS "WSAGetLastError" ( _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAGETLASTERROR () AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAIsBlocking LIB "ws2_32.dll" ALIAS "WSAIsBlocking" ( _
    ) AS LONG  ' BOOL

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAISBLOCKING () AS LONG  ' BOOL

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAUnhookBlockingHook LIB "ws2_32.dll" _
    ALIAS "WSAUnhookBlockingHook" () AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAUNHOOKBLOCKINGHOOK () AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSASetBlockingHook LIB "ws2_32.dll" _
    ALIAS "WSASetBlockingHook" ( _
    BYVAL lpBlockFunc AS DWORD _  ' FARPROC
    ) AS DWORD  ' FARPROC

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSASETBLOCKINGHOOK (_
    BYVAL lpBlockFunc AS DWORD _  ' FARPROC
    ) AS DWORD  ' FARPROC

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSACancelBlockingCall LIB "ws2_32.dll" _
    ALIAS "WSACancelBlockingCall" () AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSACANCELBLOCKINGCALL () AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAAsyncGetServByName LIB "ws2_32.dll" _
    ALIAS "WSAAsyncGetServByName" ( _
    BYVAL hWnd   AS DWORD, _   ' HWND
    BYVAL wMsg   AS DWORD, _
    serv_name    AS ASCIIZ, _
    proto        AS ASCIIZ, _
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG _
    ) AS DWORD   ' HANDLE

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAASYNCGETSERVBYNAME ( _
    BYVAL hWnd   AS DWORD, _   ' HWND
    BYVAL wMsg   AS DWORD, _
    serv_name    AS ASCIIZ, _
    proto        AS ASCIIZ, _
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG _
    ) AS DWORD   ' HANDLE

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAAsyncGetServByPort LIB "ws2_32.dll" _
    ALIAS "WSAAsyncGetServByPort" ( _
    BYVAL hWnd   AS DWORD, _  ' HWND
    BYVAL wMsg   AS DWORD, _
    BYVAL lPort  AS LONG, _
    proto        AS ASCIIZ, _
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG _
    ) AS DWORD   ' HANDLE

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAASYNCGETSERVBYPORT ( _
    BYVAL hWnd   AS DWORD, _  ' HWND
    BYVAL wMsg   AS DWORD, _
    BYVAL lPort  AS LONG, _
    proto        AS ASCIIZ, _
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG _
    ) AS DWORD   ' HANDLE

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAAsyncGetProtoByName LIB "ws2_32.dll" _
    ALIAS "WSAAsyncGetProtoByName" ( _
    BYVAL hWnd   AS DWORD, _  ' HWND
    BYVAL wMsg   AS DWORD, _
    proto_name   AS ASCIIZ, _
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG _
    ) AS DWORD  ' HANDLE

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAASYNCGETPROTOBYNAME ( _
    BYVAL hWnd   AS DWORD, _  ' HWND
    BYVAL wMsg   AS DWORD, _
    proto_name   AS ASCIIZ, _
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG _
    ) AS DWORD  ' HANDLE

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAAsyncGetProtoByNumber LIB "ws2_32.dll" _
    ALIAS "WSAAsyncGetProtoByNumber" ( _
    BYVAL hWnd   AS DWORD, _   ' HWND
    BYVAL wMsg   AS DWORD, _
    BYVAL number AS LONG, _
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG _
    ) AS DWORD  ' HANDLE

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAASYNCGETPROTOBYNUMBER ( _
    BYVAL hWnd   AS DWORD, _   ' HWND
    BYVAL wMsg   AS DWORD, _
    BYVAL number AS LONG, _
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG _
    ) AS DWORD  ' HANDLE

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAAsyncGetHostByName LIB "ws2_32.dll" _
    ALIAS "WSAAsyncGetHostByName" ( _
    BYVAL hWnd   AS DWORD, _
    BYVAL wMsg   AS DWORD, _
    host_name    AS ASCIIZ, _
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG _
    ) AS DWORD  ' HANDLE

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAASYNCGETHOSTBYNAME ( _
    BYVAL hWnd   AS DWORD, _
    BYVAL wMsg   AS DWORD, _
    host_name    AS ASCIIZ, _
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG _
    ) AS DWORD  ' HANDLE

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAAsyncGetHostByAddr LIB "ws2_32.dll" _
    ALIAS "WSAAsyncGetHostByAddr" ( _
    BYVAL hWnd      AS DWORD, _   ' HWND
    BYVAL wMsg      AS DWORD, _
    BYVAL address   AS BYTE PTR, _
    BYVAL addr_len  AS LONG, _
    BYVAL addr_type AS LONG, _
    BYVAL buf       AS BYTE PTR, _
    BYVAL buflen    AS LONG _
    ) AS DWORD  ' HANDLE

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAASYNCGETHOSTBYADDR ( _
    BYVAL hWnd      AS DWORD, _   ' HWND
    BYVAL wMsg      AS DWORD, _
    BYVAL address   AS BYTE PTR, _
    BYVAL addr_len  AS LONG, _
    BYVAL addr_type AS LONG, _
    BYVAL buf       AS BYTE PTR, _
    BYVAL buflen    AS LONG _
    ) AS DWORD  ' HANDLE

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSACancelAsyncRequest LIB "ws2_32.dll" _
    ALIAS "WSACancelAsyncRequest" ( _
    BYVAL hAsyncTaskHandle AS DWORD _   ' HANDLE
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSACANCELASYNCREQUEST ( _
    BYVAL hAsyncTaskHandle AS DWORD _   ' HANDLE
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAAsyncSelect LIB "ws2_32.dll" ALIAS "WSAAsyncSelect" ( _
    BYVAL s      AS DWORD, _   ' SOCKET
    BYVAL hWnd   AS DWORD, _   ' HWND
    BYVAL wMsg   AS DWORD, _
    BYVAL lEvent AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAASYNCSELECT ( _
    BYVAL s      AS DWORD, _   ' SOCKET
    BYVAL hWnd   AS DWORD, _   ' HWND
    BYVAL wMsg   AS DWORD, _
    BYVAL lEvent AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

' WinSock 2 API new function prototypes

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAAccept LIB "ws2_32.dll" ALIAS "WSAAccept" ( _
    BYVAL s              AS DWORD, _
    saAddr               AS SOCKADDR, _
    addrlen              AS LONG, _
    BYVAL lpfnCondition  AS DWORD, _   ' LPCONDITIONPROC
    BYVAL dwCallbackData AS DWORD _
    ) AS DWORD  ' SOCKET

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAACCEPT ( _
    BYVAL s              AS DWORD, _
    saAddr               AS SOCKADDR, _
    addrlen              AS LONG, _
    BYVAL lpfnCondition  AS DWORD, _   ' LPCONDITIONPROC
    BYVAL dwCallbackData AS DWORD _
    ) AS DWORD  ' SOCKET

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSACloseEvent LIB "ws2_32.dll" ALIAS "WSACloseEvent" ( _
    BYVAL hEvent AS WSAEVENT _
    ) AS LONG   ' BOOL

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSACLOSEEVENT ( _
    BYVAL hEvent AS WSAEVENT _
    ) AS LONG   ' BOOL

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAConnect LIB "ws2_32.dll" ALIAS "WSAConnect" ( _
     BYVAL s       AS DWORD, _  ' SOCKET
     sname         AS SOCKADDR, _
     BYVAL namelen AS LONG, _
     lpCallerData  AS WSABUF, _
     lpCalleeData  AS WSABUF, _
     lpSQOS        AS QOS, _
     lpGQOS        AS QOS _
     ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_PROTOTYPES

#IF %DEF(%UNICODE)
MACRO WSAConnectByName=WSAConnectByNameW
#ELSE
MACRO WSAConnectByName=WSAConnectByNameA
#ENDIF

DECLARE FUNCTION WSAConnectByNameW LIB "Ws2_32.dll" _
    ALIAS "WSAConnectByNameW" ( _
    BYVAL s             AS DWORD, _  ' SOCKET
    nodename            AS WSTRINGZ, _
    servicename         AS WSTRINGZ, _
    LocalAddressLength  AS DWORD, _
    LocalAddress        AS SOCKADDR, _
    RemoteAddressLength AS DWORD, _
    RemoteAddress       AS SOCKADDR, _
    TIMEOUT             AS timeval, _
    Reserved            AS WSAOVERLAPPED _
    ) AS LONG

DECLARE FUNCTION WSAConnectByNameA LIB "Ws2_32.dll" _
    ALIAS "WSAConnectByNameA" ( _
    BYVAL s             AS DWORD, _  ' SOCKET
    nodename            AS ASCIIZ, _
    servicename         AS ASCIIZ, _
    LocalAddressLength  AS DWORD, _
    LocalAddress        AS SOCKADDR, _
    RemoteAddressLength AS DWORD, _
    RemoteAddress       AS SOCKADDR, _
    TIMEOUT             AS timeval, _
    Reserved            AS WSAOVERLAPPED _
    ) AS LONG

DECLARE FUNCTION WSAConnectByList LIB "ws2_32.dll" _
    ALIAS "WSAConnectByList" ( _
    BYVAL s             AS DWORD, _  ' SOCKET
    BYVAL SocketAddress AS SOCKET_ADDRESS_LIST PTR, _
    LocalAddressLength  AS DWORD, _
    LocalAddress        AS SOCKADDR, _
    RemoteAddressLength AS DWORD, _
    RemoteAddress       AS SOCKADDR, _
    TIMEOUT             AS timeval, _
    Reserved            AS WSAOVERLAPPED _
    ) AS LONG  ' BOOL

#ENDIF

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSACONNECT ( _
     BYVAL s       AS DWORD, _  ' SOCKET
     sname         AS SOCKADDR, _
     BYVAL namelen AS LONG, _
     lpCallerData  AS WSABUF, _
     lpCalleeData  AS WSABUF, _
     lpSQOS        AS QOS, _
     lpGQOS        AS QOS _
     ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSACreateEvent LIB "ws2_32.dll" ALIAS "WSACreateEvent" ( _
    ) AS WSAEVENT

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSACREATEEVENT ( _
    ) AS WSAEVENT

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSADuplicateSocketA LIB "ws2_32.dll" _
    ALIAS "WSADuplicateSocketA" ( _
    BYVAL s           AS DWORD, _    ' SOCKET
    BYVAL dwProcessId AS DWORD, _
    lpProtocolInfo    AS WSAPROTOCOL_INFOA _
    ) AS LONG

DECLARE FUNCTION WSADuplicateSocketW LIB "ws2_32.dll" _
    ALIAS "WSADuplicateSocketW" ( _
    BYVAL s           AS DWORD, _    ' SOCKET
    BYVAL dwProcessId AS DWORD, _
    lpProtocolInfo    AS WSAPROTOCOL_INFOW _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO WSADuplicateSocket=WSADuplicateSocketW
#ELSE
MACRO WSADuplicateSocket=WSADuplicateSocketA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSADUPLICATESOCKETA ( _
    BYVAL s           AS DWORD, _    ' SOCKET
    BYVAL dwProcessId AS DWORD, _
    lpProtocolInfo    AS WSAPROTOCOL_INFOA _
    ) AS LONG

DECLARE FUNCTION LPFN_WSADUPLICATESOCKETW ( _
    BYVAL s           AS DWORD, _    ' SOCKET
    BYVAL dwProcessId AS DWORD, _
    lpProtocolInfo    AS WSAPROTOCOL_INFOW _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO LPFN_WSADUPLICATESOCKET=LPFN_WSADUPLICATESOCKETW
#ELSE
MACRO LPFN_WSADUPLICATESOCKET=LPFN_WSADUPLICATESOCKETA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAEnumNetworkEvents LIB "ws2_32.dll" _
    ALIAS "WSAEnumNetworkEvents" ( _
    BYVAL s            AS DWORD, _  ' SOCKET
    BYVAL hEventObject AS WSAEVENT, _
    lpNetworkEvents    AS WSANETWORKEVENTS _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAENUMNETWORKEVENTS ( _
    BYVAL s            AS DWORD, _  ' SOCKET
    BYVAL hEventObject AS WSAEVENT, _
    lpNetworkEvents    AS WSANETWORKEVENTS _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAEnumProtocolsA LIB "ws2_32.dll" _
    ALIAS "WSAEnumProtocolsA" ( _
    lpiProtocols     AS LONG, _
    lpProtocolBuffer AS WSAPROTOCOL_INFOA, _
    lpdwBufferLength AS DWORD _
    ) AS LONG

DECLARE FUNCTION WSAEnumProtocolsW LIB "ws2_32.dll" _
    ALIAS "WSAEnumProtocolsW" ( _
    lpiProtocols     AS LONG, _
    lpProtocolBuffer AS WSAPROTOCOL_INFOW, _
    lpdwBufferLength AS DWORD _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO WSAEnumProtocols=WSAEnumProtocolsW
#ELSE
MACRO WSAEnumProtocols=WSAEnumProtocolsA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAENUMPROTOCOLSA ( _
    lpiProtocols     AS LONG, _
    lpProtocolBuffer AS WSAPROTOCOL_INFOA, _
    lpdwBufferLength AS DWORD _
    ) AS LONG

DECLARE FUNCTION LPFN_WSAENUMPROTOCOLSW ( _
    lpiProtocols     AS LONG, _
    lpProtocolBuffer AS WSAPROTOCOL_INFOW, _
    lpdwBufferLength AS DWORD _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO LPFN_WSAENUMPROTOCOLS=LPFN_WSAENUMPROTOCOLSW
#ELSE
MACRO LPFN_WSAENUMPROTOCOLS=LPFN_WSAENUMPROTOCOLSA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAEventSelect LIB "ws2_32.dll" ALIAS "WSAEventSelect" ( _
    BYVAL s              AS DWORD, _   ' SOCKET
    BYVAL hEventObject   AS WSAEVENT, _
    BYVAL lNetworkEvents AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAEVENTSELECT ( _
    BYVAL s              AS DWORD, _   ' SOCKET
    BYVAL hEventObject   AS WSAEVENT, _
    BYVAL lNetworkEvents AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAGetOverlappedResult LIB "ws2_32.dll" _
    ALIAS "WSAGetOverlappedResult" ( _
    BYVAL s      AS DWORD, _   ' SOCKET
    lpOverlapped AS WSAOVERLAPPED, _
    lpcbTransfer AS DWORD, _
    BYVAL fWait  AS LONG, _    ' BOOL
    lpdwFlags    AS DWORD _
    ) AS LONG   ' BOOL

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAGETOVERLAPPEDRESULT ( _
    BYVAL s      AS DWORD, _   ' SOCKET
    lpOverlapped AS WSAOVERLAPPED, _
    lpcbTransfer AS DWORD, _
    BYVAL fWait  AS LONG, _    ' BOOL
    lpdwFlags    AS DWORD _
    ) AS LONG   ' BOOL

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAGetQOSByName LIB "ws2_32.dll" ALIAS "WSAGetQOSByName" ( _
    BYVAL s   AS DWORD, _   ' SOCKET
    lpQOSName AS WSABUF, _
    lpQOS     AS QOS _
    ) AS LONG   ' BOOL

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAGETQOSBYNAME ( _
    BYVAL s   AS DWORD, _   ' SOCKET
    lpQOSName AS WSABUF, _
    lpQOS     AS QOS _
    ) AS LONG   ' BOOL

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAHtonl LIB "ws2_32.dll" ALIAS "WSAHtonl" ( _
    BYVAL s        AS DWORD, _   ' SOCKET
    BYVAL hostlong AS DWORD, _
    lpnetlong      AS DWORD _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAHTONL ( _
    BYVAL s        AS DWORD, _   ' SOCKET
    BYVAL hostlong AS DWORD, _
    lpnetlong      AS DWORD _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAHtons LIB "ws2_32.dll" ALIAS "WSAHtons" ( _
    BYVAL s         AS DWORD, _   ' SOCKET
    BYVAL hostshort AS WORD, _
    lpnetshort      AS WORD _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAHTONS ( _
    BYVAL s         AS DWORD, _   ' SOCKET
    BYVAL hostshort AS WORD, _
    lpnetshort      AS WORD _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAIoctl LIB "ws2_32.dll" ALIAS "WSAIoctl" ( _
    BYVAL s                   AS DWORD, _  ' SOCKET
    BYVAL dwIoControlCode     AS DWORD, _
    lpvInBuffer               AS ANY, _    ' LPVOID
    BYVAL cbInBuffer          AS DWORD, _
    lpvOutBuffer              AS ANY, _    ' LPVOID
    BYVAL cbOutBuffer         AS DWORD, _
    lpcbBytesReturned         AS DWORD, _
    lpOverlapped              AS WSAOVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD _   ' LPWSAOVERLAPPED_COMPLETION_ROUTINE
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAIOCTL ( _
    BYVAL s                   AS DWORD, _  ' SOCKET
    BYVAL dwIoControlCode     AS DWORD, _
    lpvInBuffer               AS ANY, _    ' LPVOID
    BYVAL cbInBuffer          AS DWORD, _
    lpvOutBuffer              AS ANY, _    ' LPVOID
    BYVAL cbOutBuffer         AS DWORD, _
    lpcbBytesReturned         AS DWORD, _
    lpOverlapped              AS WSAOVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD _   ' LPWSAOVERLAPPED_COMPLETION_ROUTINE
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAJoinLeaf LIB "ws2_32.dll" ALIAS "WSAJoinLeaf" ( _
    BYVAL s       AS DWORD, _   ' SOCKET
    sname         AS SOCKADDR, _
    BYVAL namelen AS LONG, _
    lpCallerData  AS WSABUF, _
    lpCalleeData  AS WSABUF, _
    lpSQOS        AS QOS, _
    lpGQOS        AS QOS, _
    BYVAL dwFlags AS DWORD _
    ) AS DWORD   ' SOCKET

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAJOINLEAF ( _
    BYVAL s       AS DWORD, _   ' SOCKET
    sname         AS SOCKADDR, _
    BYVAL namelen AS LONG, _
    lpCallerData  AS WSABUF, _
    lpCalleeData  AS WSABUF, _
    lpSQOS        AS QOS, _
    lpGQOS        AS QOS, _
    BYVAL dwFlags AS DWORD _
    ) AS DWORD   ' SOCKET

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSANtohl LIB "ws2_32.dll" ALIAS "WSANtohl" ( _
    BYVAL s       AS DWORD, _   ' SOCKET
    BYVAL netlong AS DWORD, _
    lphostlong    AS DWORD _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSANTOHL ( _
    BYVAL s       AS DWORD, _   ' SOCKET
    BYVAL netlong AS DWORD, _
    lphostlong    AS DWORD _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSANtohs LIB "ws2_32.dll" ALIAS "WSANtohs" ( _
    BYVAL s        AS DWORD, _   ' SOCKET
    BYVAL netshort AS WORD, _
    lphostshort    AS WORD _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSANTOHS ( _
    BYVAL s        AS DWORD, _   ' SOCKET
    BYVAL netshort AS WORD, _
    lphostshort    AS WORD _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSARecv LIB "ws2_32.dll" ALIAS "WSARecv" ( _
    BYVAL s                   AS DWORD, _ ' SOCKET
    lpBuffers                 AS WSABUF, _
    BYVAL dwBufferCount       AS DWORD, _
    lpNumberOfBytesRecvd      AS DWORD, _
    lpFlags                   AS DWORD, _
    lpOverlapped              AS WSAOVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD _  ' LPWSAOVERLAPPED_COMPLETION_ROUTINE
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSARECV ( _
    BYVAL s                   AS DWORD, _ ' SOCKET
    lpBuffers                 AS WSABUF, _
    BYVAL dwBufferCount       AS DWORD, _
    lpNumberOfBytesRecvd      AS DWORD, _
    lpFlags                   AS DWORD, _
    lpOverlapped              AS WSAOVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD _  ' LPWSAOVERLAPPED_COMPLETION_ROUTINE
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSARecvDisconnect LIB "ws2_32.dll" _
    ALIAS "WSARecvDisconnect" ( _
    BYVAL s                 AS DWORD, _   ' SOCKET
    lpInboundDisconnectData AS WSABUF _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSARECVDISCONNECT ( _
    ALIAS "WSARecvDisconnect" ( _
    BYVAL s                 AS DWORD, _   ' SOCKET
    lpInboundDisconnectData AS WSABUF _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSARecvFrom LIB "ws2_32.dll" ALIAS "WSARecvFrom" ( _
    BYVAL s                   AS DWORD, _  ' SOCKET
    BYVAL lpBuffers           AS WSABUF PTR, _
    BYVAL dwBufferCount       AS DWORD, _
    lpNumberOfBytesRecvd      AS DWORD, _
    lpFlags                   AS DWORD, _
    lpFrom                    AS SOCKADDR, _
    lpFromlen                 AS LONG, _
    lpOverlapped              AS WSAOVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD _   ' LPWSAOVERLAPPED_COMPLETION_ROUTINE
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSARECVFROM ( _
    BYVAL s                   AS DWORD, _  ' SOCKET
    BYVAL lpBuffers           AS WSABUF PTR, _
    BYVAL dwBufferCount       AS DWORD, _
    lpNumberOfBytesRecvd      AS DWORD, _
    lpFlags                   AS DWORD, _
    lpFrom                    AS SOCKADDR, _
    lpFromlen                 AS LONG, _
    lpOverlapped              AS WSAOVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD _   ' LPWSAOVERLAPPED_COMPLETION_ROUTINE
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAResetEvent LIB "ws2_32.dll" ALIAS "WSAResetEvent" ( _
    BYVAL hEvent AS WSAEVENT _
    ) AS LONG  ' BOOL

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSARESETEVENT ( _
    BYVAL hEvent AS WSAEVENT _
    ) AS LONG  ' BOOL

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSASend LIB "ws2_32.dll" ALIAS "WSASend" ( _
    BYVAL s                   AS DWORD, _  ' SOCKET
    lpBuffers                 AS WSABUF, _
    BYVAL dwBufferCount       AS DWORD, _
    lpNumberOfBytesSent       AS DWORD, _
    BYVAL dwFlags             AS DWORD, _
    lpOverlapped              AS WSAOVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD _   ' LPWSAOVERLAPPED_COMPLETION_ROUTINE
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSASEND ( _
    BYVAL s                   AS DWORD, _  ' SOCKET
    lpBuffers                 AS WSABUF, _
    BYVAL dwBufferCount       AS DWORD, _
    lpNumberOfBytesSent       AS DWORD, _
    BYVAL dwFlags             AS DWORD, _
    lpOverlapped              AS WSAOVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD _   ' LPWSAOVERLAPPED_COMPLETION_ROUTINE
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF (%WIN32_WINNT >= &H0600)
#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSASendMsg LIB "ws2_32.dll" ALIAS "WSASendMsg" ( _
    BYVAL handl               AS DWORD, _  ' SOCKET
    lpMsg                     AS WSAMSG, _
    BYVAL dwFlags             AS DWORD, _
    lpNumberOfBytesSent       AS DWORD, _
    lpOverlapped              AS WSAOVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD _   ' LPWSAOVERLAPPED_COMPLETION_ROUTINE
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES
#ENDIF ' (%WIN32_WINNT >= &H0600)

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSASendDisconnect LIB "ws2_32.dll" _
    ALIAS "WSASendDisconnect" ( _
    BYVAL s                  AS DWORD, _  ' SOCKET
    lpOutboundDisconnectData AS WSABUF _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSASENDDISCONNECT ( _
    BYVAL s                  AS DWORD, _  ' SOCKET
    lpOutboundDisconnectData AS WSABUF _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSASendTo LIB "ws2_32.dll" ALIAS "WSASendTo" ( _
    BYVAL s                   AS DWORD, _  ' SOCKET
    BYVAL lpBuffers           AS WSABUF PTR, _
    BYVAL dwBufferCount       AS DWORD, _
    lpNumberOfBytesSent       AS DWORD, _
    BYVAL dwFlags             AS DWORD, _
    lpTo                      AS SOCKADDR, _
    BYVAL iTolen              AS LONG, _
    lpOverlapped              AS WSAOVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD _   ' LPWSAOVERLAPPED_COMPLETION_ROUTINE
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSASENDTO ( _
    BYVAL s                   AS DWORD, _  ' SOCKET
    BYVAL lpBuffers           AS WSABUF PTR, _
    BYVAL dwBufferCount       AS DWORD, _
    lpNumberOfBytesSent       AS DWORD, _
    BYVAL dwFlags             AS DWORD, _
    lpTo                      AS SOCKADDR, _
    BYVAL iTolen              AS LONG, _
    lpOverlapped              AS WSAOVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD _   ' LPWSAOVERLAPPED_COMPLETION_ROUTINE
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSASetEvent LIB "ws2_32.dll" ALIAS "WSASetEvent" ( _
    BYVAL hEvent AS WSAEVENT _
    ) AS LONG   ' BOOL

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSASETEVENT ( _
    BYVAL hEvent AS WSAEVENT _
    ) AS LONG   ' BOOL

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSASocketA LIB "ws2_32.dll" ALIAS "WSASocketA" ( _
    BYVAL af       AS LONG, _
    BYVAL ltype    AS LONG, _
    BYVAL protocol AS LONG, _
    lpProtocolInfo AS WSAPROTOCOL_INFOA, _
    BYVAL g        AS DWORD, _  ' GROUP
    BYVAL dwFlags  AS DWORD _
    ) AS DWORD  ' SOCKET

DECLARE FUNCTION WSASocketW LIB "ws2_32.dll" ALIAS "WSASocketW" ( _
    BYVAL af       AS LONG, _
    BYVAL ltype    AS LONG, _
    BYVAL protocol AS LONG, _
    lpProtocolInfo AS WSAPROTOCOL_INFOW, _
    BYVAL g        AS DWORD, _  ' GROUP
    BYVAL dwFlags  AS DWORD _
    ) AS DWORD  ' SOCKET

#IF %DEF(%UNICODE)
MACRO WSASocket=WSASocketW
#ELSE
MACRO WSASocket=WSASocketA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS


DECLARE FUNCTION LPFN_WSASOCKETA ( _
    BYVAL af       AS LONG, _
    BYVAL ltype    AS LONG, _
    BYVAL protocol AS LONG, _
    lpProtocolInfo AS WSAPROTOCOL_INFOA, _
    BYVAL g        AS DWORD, _  ' GROUP
    BYVAL dwFlags  AS DWORD _
    ) AS DWORD  ' SOCKET

DECLARE FUNCTION LPFN_WSASOCKETW ( _
    BYVAL af       AS LONG, _
    BYVAL ltype    AS LONG, _
    BYVAL protocol AS LONG, _
    lpProtocolInfo AS WSAPROTOCOL_INFOW, _
    BYVAL g        AS DWORD, _  ' GROUP
    BYVAL dwFlags  AS DWORD _
    ) AS DWORD  ' SOCKET

#IF %DEF(%UNICODE)
MACRO LPFN_WSASOCKET=LPFN_WSASOCKETW
#ELSE
MACRO LPFN_WSASOCKET=LPFN_WSASOCKETA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAWaitForMultipleEvents LIB "ws2_32.dll" _
    ALIAS "WSAWaitForMultipleEvents" ( _
    BYVAL cEvents    AS DWORD, _
    BYVAL lphEvents  AS WSAEVENT PTR, _
    BYVAL fWaitAll   AS LONG, _  ' BOOL
    BYVAL dwTimeout  AS DWORD, _
    BYVAL fAlertable AS LONG _   ' BOOL
    ) AS DWORD

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAWAITFORMULTIPLEEVENTS ( _
    BYVAL cEvents    AS DWORD, _
    BYVAL lphEvents  AS WSAEVENT PTR, _
    BYVAL fWaitAll   AS LONG, _  ' BOOL
    BYVAL dwTimeout  AS DWORD, _
    BYVAL fAlertable AS LONG _   ' BOOL
    ) AS DWORD

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAAddressToStringA LIB "ws2_32.dll" _
    ALIAS "WSAAddressToStringA" ( _
    lpsaAddress             AS SOCKADDR, _
    BYVAL dwAddressLength   AS DWORD, _
    lpProtocolInfo          AS WSAPROTOCOL_INFOA, _
    lpszAddressString       AS ASCIIZ, _
    lpdwAddressStringLength AS DWORD _
    ) AS LONG

DECLARE FUNCTION WSAAddressToStringW LIB "ws2_32.dll" _
    ALIAS "WSAAddressToStringW" ( _
    lpsaAddress             AS SOCKADDR, _
    BYVAL dwAddressLength   AS DWORD, _
    lpProtocolInfo          AS WSAPROTOCOL_INFOW, _
    lpszAddressString       AS WSTRINGZ, _
    lpdwAddressStringLength AS DWORD _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO WSAAddressToString=WSAAddressToStringW
#ELSE
MACRO WSAAddressToString=WSAAddressToStringA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAADDRESSTOSTRINGA ( _
    lpsaAddress             AS SOCKADDR, _
    BYVAL dwAddressLength   AS DWORD, _
    lpProtocolInfo          AS WSAPROTOCOL_INFOA, _
    lpszAddressString       AS ASCIIZ, _
    lpdwAddressStringLength AS DWORD _
    ) AS LONG

DECLARE FUNCTION LPFN_WSAADDRESSTOSTRINGW ( _
    lpsaAddress             AS SOCKADDR, _
    BYVAL dwAddressLength   AS DWORD, _
    lpProtocolInfo          AS WSAPROTOCOL_INFOW, _
    lpszAddressString       AS WSTRINGZ, _
    lpdwAddressStringLength AS DWORD _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO LPFN_WSAADDRESSTOSTRING=LPFN_WSAADDRESSTOSTRINGW
#ELSE
MACRO LPFN_WSAADDRESSTOSTRING=LPFN_WSAADDRESSTOSTRINGA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAStringToAddressA LIB "ws2_32.dll" _
    ALIAS "WSAStringToAddressA" ( _
    AddressString       AS ASCIIZ, _
    BYVAL AddressFamily AS LONG, _
    lpProtocolInfo      AS WSAPROTOCOL_INFOA, _
    lpAddress           AS SOCKADDR, _
    lpAddressLength     AS LONG _
    ) AS LONG

DECLARE FUNCTION WSAStringToAddressW LIB "ws2_32.dll" _
    ALIAS "WSAStringToAddressW" ( _
    AddressString       AS WSTRINGZ, _
    BYVAL AddressFamily AS LONG, _
    lpProtocolInfo      AS WSAPROTOCOL_INFOW, _
    lpAddress           AS SOCKADDR, _
    lpAddressLength     AS LONG _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO WSAStringToAddress=WSAStringToAddressW
#ELSE
MACRO WSAStringToAddress=WSAStringToAddressA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSASTRINGTOADDRESSA ( _
    AddressString       AS ASCIIZ, _
    BYVAL AddressFamily AS LONG, _
    lpProtocolInfo      AS WSAPROTOCOL_INFOA, _
    lpAddress           AS SOCKADDR, _
    lpAddressLength     AS LONG _
    ) AS LONG

DECLARE FUNCTION LPFN_WSASTRINGTOADDRESSW ( _
    AddressString       AS WSTRINGZ, _
    BYVAL AddressFamily AS LONG, _
    lpProtocolInfo      AS WSAPROTOCOL_INFOW, _
    lpAddress           AS SOCKADDR, _
    lpAddressLength     AS LONG _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO LPFN_WSASTRINGTOADDRESS=LPFN_WSASTRINGTOADDRESSW
#ELSE
MACRO LPFN_WSASTRINGTOADDRESS=LPFN_WSASTRINGTOADDRESSA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

' Registration and Name Resolution API functions


#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSALookupServiceBeginA LIB "ws2_32.dll" _
    ALIAS "WSALookupServiceBeginA" ( _
    lpqsRestrictions     AS WSAQUERYSETA, _
    BYVAL dwControlFlags AS DWORD, _
    lphLookup            AS DWORD _
    ) AS LONG

DECLARE FUNCTION WSALookupServiceBeginW LIB "ws2_32.dll" _
    ALIAS "WSALookupServiceBeginW" ( _
    lpqsRestrictions     AS WSAQUERYSETW, _
    BYVAL dwControlFlags AS DWORD, _
    lphLookup            AS DWORD _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO WSALookupServiceBegin=WSALookupServiceBeginW
#ELSE
MACRO WSALookupServiceBegin=WSALookupServiceBeginA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSALOOKUPSERVICEBEGINA ( _
    lpqsRestrictions     AS WSAQUERYSETA, _
    BYVAL dwControlFlags AS DWORD, _
    lphLookup            AS DWORD _
    ) AS LONG

DECLARE FUNCTION LPFN_WSALOOKUPSERVICEBEGINW ( _
    lpqsRestrictions     AS WSAQUERYSETW, _
    BYVAL dwControlFlags AS DWORD, _
    lphLookup            AS DWORD _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO LPFN_WSALOOKUPSERVICEBEGIN=LPFN_WSALOOKUPSERVICEBEGINW
#ELSE
MACRO LPFN_WSALOOKUPSERVICEBEGIN=LPFN_WSALOOKUPSERVICEBEGINA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSALookupServiceNextA LIB "ws2_32.dll" _
    ALIAS "WSALookupServiceNextA" ( _
    BYVAL hLookup        AS DWORD, _   ' HANDLE
    BYVAL dwControlFlags AS DWORD, _
    lpdwBufferLength     AS DWORD, _
    lpsqResults          AS WSAQUERYSETA _
    ) AS LONG

DECLARE FUNCTION WSALookupServiceNextW LIB "ws2_32.dll" _
    ALIAS "WSALookupServiceNextW" ( _
    BYVAL hLookup        AS DWORD, _   ' HANDLE
    BYVAL dwControlFlags AS DWORD, _
    lpdwBufferLength     AS DWORD, _
    lpsqResults          AS WSAQUERYSETW _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO WSALookupServiceNext=WSALookupServiceNextW
#ELSE
MACRO WSALookupServiceNext=WSALookupServiceNextA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSALOOKUPSERVICENEXTA ( _
    BYVAL hLookup        AS DWORD, _   ' HANDLE
    BYVAL dwControlFlags AS DWORD, _
    lpdwBufferLength     AS DWORD, _
    lpsqResults          AS WSAQUERYSETA _
    ) AS LONG

DECLARE FUNCTION LPFN_WSALOOKUPSERVICENEXTW ( _
    BYVAL hLookup        AS DWORD, _   ' HANDLE
    BYVAL dwControlFlags AS DWORD, _
    lpdwBufferLength     AS DWORD, _
    lpsqResults          AS WSAQUERYSETW _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO LPFN_WSALOOKUPSERVICENEXT=LPFN_WSALOOKUPSERVICENEXTW
#ELSE
MACRO LPFN_WSALOOKUPSERVICENEXT=LPFN_WSALOOKUPSERVICENEXTA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF (%WIN32_WINNT >= &H0501)
#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSANSPIoctl LIB "ws2_32.dll" ALIAS "WSANSPIoctl" ( _
    BYVAL hLookup       AS DWORD, _  ' HANDLE
    BYVAL dwControlCode AS DWORD, _
    lpvInBuffer         AS ANY, _    ' LPVOID
    BYVAL cbInBuffer    AS DWORD, _
    lpvOutBuffer        AS ANY, _    ' LPVOID
    BYVAL cbOutBuffer   AS DWORD, _
    lpcbBytesReturned   AS DWORD, _
    lpCompletion        AS WSACOMPLETION _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSANSPIoctl ( _
    BYVAL hLookup       AS DWORD, _  ' HANDLE
    BYVAL dwControlCode AS DWORD, _
    lpvInBuffer         AS ANY, _    ' LPVOID
    BYVAL cbInBuffer    AS DWORD, _
    lpvOutBuffer        AS ANY, _    ' LPVOID
    BYVAL cbOutBuffer   AS DWORD, _
    lpcbBytesReturned   AS DWORD, _
    lpCompletion        AS WSACOMPLETION _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS
#ENDIF '(%WIN32_WINNT >= &H0501)

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSALookupServiceEnd LIB "ws2_32.dll" _
    ALIAS "WSALookupServiceEnd" ( _
    BYVAL hLookup AS DWORD _   ' HANDLE
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSALOOKUPSERVICEEND ( _
    BYVAL hLookup AS DWORD _   ' HANDLE
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAInstallServiceClassA LIB "ws2_32.dll" _
    ALIAS "WSAInstallServiceClassA" ( _
    lpServiceClassInfo AS WSASERVICECLASSINFOA _
    ) AS LONG

DECLARE FUNCTION WSAInstallServiceClassW LIB "ws2_32.dll" _
    ALIAS "WSAInstallServiceClassW" ( _
    lpServiceClassInfo AS WSASERVICECLASSINFOW _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO WSAInstallServiceClass=WSAInstallServiceClassW
#ELSE
MACRO WSAInstallServiceClass=WSAInstallServiceClassA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAINSTALLSERVICECLASSA ( _
    lpServiceClassInfo AS WSASERVICECLASSINFOA _
    ) AS LONG

DECLARE FUNCTION LPFN_WSAINSTALLSERVICECLASSW ( _
    lpServiceClassInfo AS WSASERVICECLASSINFOW _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO LPFN_WSAINSTALLSERVICECLASS=LPFN_WSAINSTALLSERVICECLASSW
#ELSE
MACRO LPFN_WSAINSTALLSERVICECLASS=LPFN_WSAINSTALLSERVICECLASSA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSARemoveServiceClass LIB "ws2_32.dll" _
    ALIAS "WSARemoveServiceClass" ( _
    lpServiceClassId AS GUID _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAREMOVESERVICECLASS ( _
    lpServiceClassId AS GUID _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAGetServiceClassInfoA LIB "ws2_32.dll" _
    ALIAS "WSAGetServiceClassInfoA" ( _
    lpProviderId       AS GUID, _
    lpServiceClassId   AS GUID, _
    lpdwBufSize        AS DWORD, _
    lpServiceClassInfo AS WSASERVICECLASSINFOA _
    ) AS LONG

DECLARE FUNCTION WSAGetServiceClassInfoW LIB "ws2_32.dll" _
    ALIAS "WSAGetServiceClassInfoW" ( _
    lpProviderId       AS GUID, _
    lpServiceClassId   AS GUID, _
    lpdwBufSize        AS DWORD, _
    lpServiceClassInfo AS WSASERVICECLASSINFOW _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO WSAGetServiceClassInfo=WSAGetServiceClassInfoW
#ELSE
MACRO WSAGetServiceClassInfo=WSAGetServiceClassInfoA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAGETSERVICECLASSINFOA ( _
    lpProviderId       AS GUID, _
    lpServiceClassId   AS GUID, _
    lpdwBufSize        AS DWORD, _
    lpServiceClassInfo AS WSASERVICECLASSINFOA _
    ) AS LONG

DECLARE FUNCTION LPFN_WSAGETSERVICECLASSINFOW ( _
    lpProviderId       AS GUID, _
    lpServiceClassId   AS GUID, _
    lpdwBufSize        AS DWORD, _
    lpServiceClassInfo AS WSASERVICECLASSINFOW _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO LPFN_WSAGETSERVICECLASSINFO=LPFN_WSAGETSERVICECLASSINFOW
#ELSE
MACRO LPFN_WSAGETSERVICECLASSINFO=LPFN_WSAGETSERVICECLASSINFOA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAEnumNameSpaceProvidersA LIB "ws2_32.dll" _
    ALIAS "WSAEnumNameSpaceProvidersA" ( _
    lpdwBufferLength AS DWORD, _
    lpnspBuffer      AS WSANAMESPACE_INFOA _
    ) AS LONG

DECLARE FUNCTION WSAEnumNameSpaceProvidersW LIB "ws2_32.dll" _
    ALIAS "WSAEnumNameSpaceProvidersW" ( _
    lpdwBufferLength AS DWORD, _
    lpnspBuffer      AS WSANAMESPACE_INFOW _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO WSAEnumNameSpaceProviders=WSAEnumNameSpaceProvidersW
#ELSE
MACRO WSAEnumNameSpaceProviders=WSAEnumNameSpaceProvidersA
#ENDIF ' NOT %DEF(%UNICODE)

#IF (%WIN32_WINNT >= &H0600)

DECLARE FUNCTION WSAEnumNameSpaceProvidersExA LIB "ws2_32.dll" _
    ALIAS "WSAEnumNameSpaceProvidersExA" ( _
    lpdwBufferLength AS DWORD, _
    lpnspBuffer      AS WSANAMESPACE_INFOEXA _
    ) AS LONG

DECLARE FUNCTION WSAEnumNameSpaceProvidersExW LIB "ws2_32.dll" _
    ALIAS "WSAEnumNameSpaceProvidersExW" ( _
    lpdwBufferLength AS DWORD, _
    lpnspBuffer      AS WSANAMESPACE_INFOEXW _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO WSAEnumNameSpaceProvidersEx=WSAEnumNameSpaceProvidersExW
#ELSE
MACRO WSAEnumNameSpaceProvidersEx=WSAEnumNameSpaceProvidersExA
#ENDIF ' NOT %DEF(%UNICODE)

#ENDIF '(%WIN32_WINNT >= &H0600 )


#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAENUMNAMESPACEPROVIDERSA ( _
    lpdwBufferLength AS DWORD, _
    lpnspBuffer      AS WSANAMESPACE_INFOA _
    ) AS LONG

DECLARE FUNCTION LPFN_WSAENUMNAMESPACEPROVIDERSW ( _
    lpdwBufferLength AS DWORD, _
    lpnspBuffer      AS WSANAMESPACE_INFOW _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO LPFN_WSAENUMNAMESPACEPROVIDERS=LPFN_WSAENUMNAMESPACEPROVIDERSW
#ELSE
MACRO LPFN_WSAENUMNAMESPACEPROVIDERS=LPFN_WSAENUMNAMESPACEPROVIDERSA
#ENDIF ' NOT %DEF(%UNICODE)

#IF (%WIN32_WINNT >= &H0600)

DECLARE FUNCTION LPFN_WSAENUMNAMESPACEPROVIDERSEXA ( _
    lpdwBufferLength AS DWORD, _
    lpnspBuffer      AS WSANAMESPACE_INFOEXA _
    ) AS LONG

DECLARE FUNCTION LPFN_WSAENUMNAMESPACEPROVIDERSEXW ( _
    lpdwBufferLength AS DWORD, _
    lpnspBuffer      AS WSANAMESPACE_INFOEXW _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO LPFN_WSAENUMNAMESPACEPROVIDERSEX=LPFN_WSAENUMNAMESPACEPROVIDERSEXW
#ELSE
MACRO LPFN_WSAENUMNAMESPACEPROVIDERSEX=LPFN_WSAENUMNAMESPACEPROVIDERSEXA
#ENDIF ' NOT %DEF(%UNICODE)

#ENDIF '(%WIN32_WINNT >= &H600)

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAGetServiceClassNameByClassIdA LIB "ws2_32.dll" _
    ALIAS "WSAGetServiceClassNameByClassIdA" ( _
    lpServiceClassId     AS GUID, _
    lpszServiceClassName AS ASCIIZ, _
    lpdwBufferLength     AS DWORD _
    ) AS LONG

DECLARE FUNCTION WSAGetServiceClassNameByClassIdW LIB "ws2_32.dll" _
    ALIAS "WSAGetServiceClassNameByClassIdW" ( _
    lpServiceClassId     AS GUID, _
    lpszServiceClassName AS WSTRINGZ, _
    lpdwBufferLength     AS DWORD _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO WSAGetServiceClassNameByClassId=WSAGetServiceClassNameByClassIdW
#ELSE
MACRO WSAGetServiceClassNameByClassId=WSAGetServiceClassNameByClassIdA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA ( _
    lpServiceClassId     AS GUID, _
    lpszServiceClassName AS ASCIIZ, _
    lpdwBufferLength     AS DWORD _
    ) AS LONG

DECLARE FUNCTION LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW ( _
    lpServiceClassId     AS GUID, _
    lpszServiceClassName AS WSTRINGZ, _
    lpdwBufferLength     AS DWORD _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO LPFN_WSAGETSERVICECLASSNAMEBYCLASSID=LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW
#ELSE
MACRO LPFN_WSAGETSERVICECLASSNAMEBYCLASSID=LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSASetServiceA LIB "ws2_32.dll" ALIAS "WSASetServiceA" ( _
    lpqsRegInfo          AS WSAQUERYSETA, _
    BYVAL essoperation   AS WSAESETSERVICEOP_enum, _
    BYVAL dwControlFlags AS DWORD _
    ) AS LONG

DECLARE FUNCTION WSASetServiceW LIB "ws2_32.dll" ALIAS "WSASetServiceW" ( _
    lpqsRegInfo          AS WSAQUERYSETW, _
    BYVAL essoperation   AS WSAESETSERVICEOP_enum, _
    BYVAL dwControlFlags AS DWORD _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO WSASetService=WSASetServiceW
#ELSE
MACRO WSASetService=WSASetServiceA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSASETSERVICEA ( _
    lpqsRegInfo          AS WSAQUERYSETA, _
    BYVAL essoperation   AS WSAESETSERVICEOP_enum, _
    BYVAL dwControlFlags AS DWORD _
    ) AS LONG

DECLARE FUNCTION LPFN_WSASETSERVICEW ( _
    lpqsRegInfo          AS WSAQUERYSETW, _
    BYVAL essoperation   AS WSAESETSERVICEOP_enum, _
    BYVAL dwControlFlags AS DWORD _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO LPFN_WSASETSERVICE=LPFN_WSASETSERVICEW
#ELSE
MACRO LPFN_WSASETSERVICE=LPFN_WSASETSERVICEA
#ENDIF ' NOT %DEF(%UNICODE)
#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAProviderConfigChange LIB "ws2_32.dll" _
    ALIAS "WSAProviderConfigChange" ( _
    lpNotificationHandle      AS DWORD, _
    lpOverlapped              AS WSAOVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD _  ' LPWSAOVERLAPPED_COMPLETION_ROUTINE
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES

#IF %INCL_WINSOCK_API_TYPEDEFS

DECLARE FUNCTION LPFN_WSAPROVIDERCONFIGCHANGE ( _
    lpNotificationHandle      AS DWORD, _
    lpOverlapped              AS WSAOVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD _  ' LPWSAOVERLAPPED_COMPLETION_ROUTINE
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_TYPEDEFS

#IF (%WIN32_WINNT >= &H0600)
#IF %INCL_WINSOCK_API_PROTOTYPES

DECLARE FUNCTION WSAPoll LIB "ws2_32.dll" ALIAS "WSAPoll" ( _
    BYVAL fdArray AS WSAPOLLFD PTR, _
    BYVAL fds     AS DWORD, _
    BYVAL TIMEOUT AS LONG _
    ) AS LONG

#ENDIF ' %INCL_WINSOCK_API_PROTOTYPES
#ENDIF ' (%WIN32_WINNT >= &H0600)



'
' Windows message parameter composition and decomposition
' macros.
'
' WSAMAKEASYNCREPLY is intended for use by the Windows Sockets implementation
' when constructing the response to a WSAAsyncGetXByY() routine.
'
MACRO WSAMAKEASYNCREPLY(buflen,nERROR) = MAK(LONG,buflen,nERROR)
'
' WSAMAKESELECTREPLY is intended for use by the Windows Sockets implementation
' when constructing the response to WSAAsyncSelect().
'
MACRO WSAMAKESELECTREPLY(nEVENT,nERROR) = MAK(LONG,nEVENT,nERROR)
'
' WSAGETASYNCBUFLEN is intended for use by the Windows Sockets application
' to extract the buffer length from the lParam in the response
' to a WSAAsyncGetXByY().
'
MACRO WSAGETASYNCBUFLEN(lParam)       = LO(WORD,lParam)
'
' WSAGETASYNCERROR is intended for use by the Windows Sockets application
' to extract the error code from the lParam in the response
' to a WSAGetXByY().
'
MACRO WSAGETASYNCERROR(lParam)        = HI(WORD,lParam)
'
' WSAGETSELECTEVENT is intended for use by the Windows Sockets application
' to extract the event code from the lParam in the response
' to a WSAAsyncSelect().
'
MACRO WSAGETSELECTEVENT(lParam)       = LO(WORD,lParam)
'
' WSAGETSELECTERROR is intended for use by the Windows Sockets application
' to extract the error code from the lParam in the response
' to a WSAAsyncSelect().
'
MACRO WSAGETSELECTERROR(lParam)       = HI(WORD,lParam)

'#if (%WIN32_WINNT >= &H0501)
'#IF %DEF(%IPV6STRICT)
'#include "wsipv6ok.inc"
'#endif ' %IPV6STRICT
'#endif '(%WIN32_WINNT >= &H0501)

#ENDIF  ' %WINSOCK2API
