'------------------------------------------------------------------------------
'
'  Ws2Def.inc
'      This file contains the core definitions for the Winsock2
'      specification that can be used by both user-mode and
'      kernel mode modules.
'
'      This file is included in WINSOCK2.H. User mode applications
'      should include WINSOCK2.H rather than including this file
'      directly. This file can not be included by a module that also
'      includes WINSOCK.H.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from Ws2Def.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WS2DEF = 1

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "WinDef.inc"

'#IF NOT %DEF(%WINSOCK2API) AND %DEF(%WINSOCKAPI)
'"Do not include winsock.h and ws2def.h in the same module. Instead include only winsock2.h."
'#ENDIF


'
' Allow Winsock components to disable PREfast errors.
'

#IF %DEF(%PREFAST) AND %DEF(%IPV6_PREFAST_SAFE)
' [not part of the SDK files]
'#include "ipv6prefast.inc"
#ENDIF ' %PREFAST

#INCLUDE "inaddr.inc"

'#if (%WIN32_WINNT >= &H0600)

'
' Address families.
'

MACRO ADDRESS_FAMILY=WORD

'#endif'(%WIN32_WINNT >= &H0600)

'
' Although AF_UNSPEC is defined for backwards compatibility, using
' AF_UNSPEC for the "af" parameter when creating a socket is STRONGLY
' DISCOURAGED.  The interpretation of the "protocol" parameter
' depends on the actual address family chosen.  As environments grow
' to include more and more address families that use overlapping
' protocol values there is more and more chance of choosing an
' undesired address family when AF_UNSPEC is used.
'
%AF_UNSPEC     = 0               ' unspecified
%AF_UNIX       = 1               ' local to host (pipes, portals)
%AF_INET       = 2               ' internetwork: UDP, TCP, etc.
%AF_IMPLINK    = 3               ' arpanet imp addresses
%AF_PUP        = 4               ' pup protocols: e.g. BSP
%AF_CHAOS      = 5               ' mit CHAOS protocols
%AF_NS         = 6               ' XEROX NS protocols
%AF_IPX        = %AF_NS          ' IPX protocols: IPX, SPX, etc.
%AF_ISO        = 7               ' ISO protocols
%AF_OSI        = %AF_ISO         ' OSI is ISO
%AF_ECMA       = 8               ' european computer manufacturers
%AF_DATAKIT    = 9               ' datakit protocols
%AF_CCITT      = 10              ' CCITT protocols, X.25 etc
%AF_SNA        = 11              ' IBM SNA
%AF_DECnet     = 12              ' DECnet
%AF_DLI        = 13              ' Direct data link interface
%AF_LAT        = 14              ' LAT
%AF_HYLINK     = 15              ' NSC Hyperchannel
%AF_APPLETALK  = 16              ' AppleTalk
%AF_NETBIOS    = 17              ' NetBios-style addresses
%AF_VOICEVIEW  = 18              ' VoiceView
%AF_FIREFOX    = 19              ' Protocols from Firefox
%AF_UNKNOWN1   = 20              ' Somebody is using this!
%AF_BAN        = 21              ' Banyan
%AF_ATM        = 22              ' Native ATM Services
%AF_INET6      = 23              ' Internetwork Version 6
%AF_CLUSTER    = 24              ' Microsoft Wolfpack
%AF_12844      = 25              ' IEEE 1284.4 WG AF
%AF_IRDA       = 26              ' IrDA
%AF_NETDES     = 28              ' Network Designers OSI & gateway

#IF (%WIN32_WINNT < &H0501)
%AF_MAX        = 29
#ELSE '(%WIN32_WINNT < &H0501)

%AF_TCNPROCESS = 29
%AF_TCNMESSAGE = 30
%AF_ICLFXBM    = 31

#IF (%WIN32_WINNT < &H0600)
%AF_MAX        = 32
#ELSE '(%WIN32_WINNT < &H0600)
%AF_BTH        = 32              ' Bluetooth RFCOMM/L2CAP protocols
#IF (%WIN32_WINNT < &H0601)
%AF_MAX        = 33
#ELSE '(%WIN32_WINNT < &H0601)
%AF_LINK       = 33
%AF_MAX        = 34
#ENDIF '(%WIN32_WINNT < &H0601)
#ENDIF '(%WIN32_WINNT < &H0600)

#ENDIF '(%WIN32_WINNT < &H0501)

'
' Socket types.
'

%SOCK_STREAM    = 1
%SOCK_DGRAM     = 2
%SOCK_RAW       = 3
%SOCK_RDM       = 4
%SOCK_SEQPACKET = 5

'
' Define a level for socket I/O controls in the same numbering space as
' IPPROTO_TCP, IPPROTO_IP, etc.
'

%SOL_SOCKET = &Hffff??

'
' Define socket-level options.
'

%SO_DEBUG       = &H0001      ' turn on debugging info recording
%SO_ACCEPTCONN  = &H0002      ' socket has had listen()
%SO_REUSEADDR   = &H0004      ' allow local address reuse
%SO_KEEPALIVE   = &H0008      ' keep connections alive
%SO_DONTROUTE   = &H0010      ' just use interface addresses
%SO_BROADCAST   = &H0020      ' permit sending of broadcast msgs
%SO_USELOOPBACK = &H0040      ' bypass hardware when possible
%SO_LINGER      = &H0080      ' linger on close if data present
%SO_OOBINLINE   = &H0100      ' leave received OOB data in line

%SO_DONTLINGER  = NOT %SO_LINGER
%SO_EXCLUSIVEADDRUSE = NOT %SO_REUSEADDR  ' disallow local address reuse

%SO_SNDBUF      = &H1001      ' send buffer size
%SO_RCVBUF      = &H1002      ' receive buffer size
%SO_SNDLOWAT    = &H1003      ' send low-water mark
%SO_RCVLOWAT    = &H1004      ' receive low-water mark
%SO_SNDTIMEO    = &H1005      ' send timeout
%SO_RCVTIMEO    = &H1006      ' receive timeout
%SO_ERROR       = &H1007      ' get error status and clear
%SO_TYPE        = &H1008      ' get socket type
%SO_BSP_STATE   = &H1009      ' get socket 5-tuple state

%SO_GROUP_ID    = &H2001      ' ID of a socket group
%SO_GROUP_PRIORITY = &H2002   ' the relative priority within a group
%SO_MAX_MSG_SIZE = &H2003     ' maximum message size

%SO_CONDITIONAL_ACCEPT = &H3002 ' enable true conditional accept:
                                ' connection is not ack-ed to the
                                ' other side until conditional
                                ' function returns CF_ACCEPT
%SO_PAUSE_ACCEPT     = &H3003   ' pause accepting new connections
%SO_COMPARTMENT_ID   = &H3004   ' get/set the compartment for a socket
#IF (%WIN32_WINNT >= &H0600)
%SO_RANDOMIZE_PORT   = &H3005   ' randomize assignment of wildcard ports
%SO_PORT_SCALABILITY = &H3006   ' enable port scalability
#ENDIF '(%WIN32_WINNT >= &H0600)

'
' Base constant used for defining WSK-specific options.
'

%WSK_SO_BASE = &H4000

'
' Options to use with [gs]etsockopt at the IPPROTO_TCP level.
'

%TCP_NODELAY = &H0001

'
' Structure used to store most addresses.
'
TYPE SOCKADDR

#IF (%WIN32_WINNT < &H0600)
    sa_family AS WORD
#ELSE
    sa_family AS ADDRESS_FAMILY       ' Address family.
#ENDIF '(%WIN32_WINNT < &H0600)

    sa_data(13) AS BYTE               ' Up to 14 bytes of direct address.
END TYPE

#IF NOT %DEF(%CSADDR_DEFINED)
%CSADDR_DEFINED = 1


'
' SockAddr Information
'
TYPE SOCKET_ADDRESS
    lpSockaddr      AS SOCKADDR PTR
    iSockaddrLength AS LONG
END TYPE

'
' Address list returned via SIO_ADDRESS_LIST_QUERY
'
TYPE SOCKET_ADDRESS_LIST
    iAddressCount AS LONG
    Address(0)    AS SOCKET_ADDRESS
END TYPE

#IF (%WIN32_WINNT >= &H0600)

'#define SIZEOF_SOCKET_ADDRESS_LIST(AddressCount) \
'    (FIELD_OFFSET(SOCKET_ADDRESS_LIST, Address) + \
'     AddressCount * sizeof(SOCKET_ADDRESS))

#ENDIF '(%WIN32_WINNT >= &H0600)

'
' CSAddr Information
'
TYPE CSADDR_INFO
    LocalAddr   AS SOCKET_ADDRESS
    RemoteAddr  AS SOCKET_ADDRESS
    iSocketType AS LONG
    iProtocol   AS LONG
END TYPE

#ENDIF ' %CSADDR_DEFINED

'
' Portable socket structure (RFC 2553).
'

'
' Desired design of maximum size and alignment.
' These are implementation specific.
'
%SS_MAXSIZE   = 128                     ' Maximum size
%SS_ALIGNSIZE = 16   '(sizeof(__int64)) ' Desired alignment

'
' Definitions used for sockaddr_storage structure paddings design.
'

#IF (%WIN32_WINNT >= &H0600)
%SS_PAD1SIZE = (%SS_ALIGNSIZE - 2)   ' sizeof(USHORT))
%SS_PAD2SIZE = (%SS_MAXSIZE - (2 + %SS_PAD1SIZE + %SS_ALIGNSIZE)) ' sizeof(USHORT)
#ELSE
%SS_PAD1SIZE = (%SS_ALIGNSIZE - 2)   ' sizeof (short))
%SS_PAD2SIZE = (%SS_MAXSIZE - (2 + %SS_PAD1SIZE + %SS_ALIGNSIZE)) ' sizeof (short)
#ENDIF '(%WIN32_WINNT >= &H0600)

TYPE SOCKADDR_STORAGE_LH
    ss_family AS ADDRESS_FAMILY     ' address family

    ss_pad1(%SS_PAD1SIZE-1) AS BYTE ' 6 byte pad, this is to make
                                    '   implementation specific pad up to
                                    '   alignment field that follows explicit
                                    '   in the data structure
    ss_align AS QUAD                ' Field to force desired structure
    ss_pad2(%SS_PAD2SIZE-1) AS BYTE ' 112 byte pad to achieve desired size;
                                    '   _SS_MAXSIZE value minus size of
                                    '   ss_family, ss_pad1, and
                                    '   ss_align fields is 112
END TYPE

TYPE SOCKADDR_STORAGE_XP
    ss_family AS INTEGER            ' Address family.

    ss_pad1(%SS_PAD1SIZE-1) AS BYTE ' 6 byte pad, this is to make
                                    '   implementation specific pad up to
                                    '   alignment field that follows explicit
                                    '   in the data structure
    ss_align AS QUAD                ' Field to force desired structure
    ss_pad2(%SS_PAD2SIZE-1) AS BYTE ' 112 byte pad to achieve desired size;
                                    '   _SS_MAXSIZE value minus size of
                                    '   ss_family, ss_pad1, and
                                    '   ss_align fields is 112
END TYPE


#IF (%WIN32_WINNT >= &H0600)
MACRO SOCKADDR_STORAGE=SOCKADDR_STORAGE_LH
#ELSEIF (%WIN32_WINNT >= &H0501)
MACRO SOCKADDR_STORAGE=SOCKADDR_STORAGE_XP
#ENDIF


'
' WinSock 2 extension -- manifest constants for WSAIoctl()
'
%IOC_UNIX      = &H00000000
%IOC_WS2       = &H08000000
%IOC_PROTOCOL  = &H10000000
%IOC_VENDOR    = &H18000000

#IF (%WIN32_WINNT >= &H0600)
'
' WSK-specific IO control codes are Winsock2 codes with the highest-order
' 3 bits of the Vendor/AddressFamily-specific field set to 1.
'
%IOC_WSK                     = (%IOC_WS2 OR &H07000000)
#ENDIF '(%WIN32_WINNT >= &H0600)

MACRO WSAIO(x,y)  =(%IOC_VOID OR (x) OR (y))
MACRO WSAIOR(x,y) =(%IOC_OUT OR (x) OR (y))
MACRO WSAIOW(x,y) =(%IOC_IN OR (x) OR (y))
MACRO WSAIORW(x,y)=(%IOC_INOUT OR (x) OR (y))


%SIO_ASSOCIATE_HANDLE         = &H88000001???       ' WSAIOW(IOC_WS2,1)
%SIO_ENABLE_CIRCULAR_QUEUEING = &H28000002          ' WSAIO(IOC_WS2,2)
%SIO_FIND_ROUTE               = &H48000003          ' WSAIOR(IOC_WS2,3)
%SIO_FLUSH                    = &H28000004          ' WSAIO(IOC_WS2,4)
%SIO_GET_BROADCAST_ADDRESS    = &H48000005          ' WSAIOR(IOC_WS2,5)
%SIO_GET_EXTENSION_FUNCTION_POINTER = &HC8000006??? ' WSAIORW(IOC_WS2,6)
%SIO_GET_QOS                  = &HC8000007???       ' WSAIORW(IOC_WS2,7)
%SIO_GET_GROUP_QOS            = &HC8000008???       ' WSAIORW(IOC_WS2,8)
%SIO_MULTIPOINT_LOOPBACK      = &H88000009???       ' WSAIOW(IOC_WS2,9)
%SIO_MULTICAST_SCOPE          = &H8800000A???       ' WSAIOW(IOC_WS2,10)
%SIO_SET_QOS                  = &H8800000B???       ' WSAIOW(IOC_WS2,11)
%SIO_SET_GROUP_QOS            = &H8800000C???       ' WSAIOW(IOC_WS2,12)
%SIO_TRANSLATE_HANDLE         = &HC800000D???       ' WSAIORW(IOC_WS2,13)
%SIO_ROUTING_INTERFACE_QUERY  = &HC8000014???       ' WSAIORW(IOC_WS2,20)
%SIO_ROUTING_INTERFACE_CHANGE = &H88000015???       ' WSAIOW(IOC_WS2,21)
%SIO_ADDRESS_LIST_QUERY       = &H48000016          ' WSAIOR(IOC_WS2,22)
%SIO_ADDRESS_LIST_CHANGE      = &H28000017          ' WSAIO(IOC_WS2,23)
%SIO_QUERY_TARGET_PNP_HANDLE  = &H48000018          ' WSAIOR(IOC_WS2,24)

#IF (%WIN32_WINNT >= &H0501)
%SIO_ADDRESS_LIST_SORT        = &HC8000019???       ' WSAIORW(IOC_WS2,25)
#ENDIF '(%WIN32_WINNT >= &H0501)

#IF (%WIN32_WINNT >= &H0600)
%SIO_RESERVED_1               = &H8800001A???       ' WSAIOW(IOC_WS2,26)
%SIO_RESERVED_2               = &H88000021???       ' WSAIOW(IOC_WS2,33)
#ENDIF '(%WIN32_WINNT >= &H0600)

'
' Constants and structures defined by the internet system (RFC 790)
'

'
' N.B. required for backwards compatability to support 0 = IP for the
' level argument to get/setsockopt.
'
%IPPROTO_IP            = 0

'
' Protocols.  The IPv6 defines are specified in RFC 2292.
'
ENUM IPPROTO SINGULAR
#IF (%WIN32_WINNT >= &H0501)
    IPPROTO_HOPOPTS       = 0  ' IPv6 Hop-by-Hop options
#ENDIF ' (%WIN32_WINNT >= &H0501)
    IPPROTO_ICMP          = 1
    IPPROTO_IGMP          = 2
    IPPROTO_GGP           = 3
#IF (%WIN32_WINNT >= &H0501)
    IPPROTO_IPV4          = 4
#ENDIF ' (%WIN32_WINNT >= &H0501)
#IF (%WIN32_WINNT >= &H0600)
    IPPROTO_ST            = 5
#ENDIF ' (%WIN32_WINNT >= &H0600)
    IPPROTO_TCP           = 6
#IF (%WIN32_WINNT >= &H0600)
    IPPROTO_CBT           = 7
    IPPROTO_EGP           = 8
    IPPROTO_IGP           = 9
#ENDIF ' (%WIN32_WINNT >= &H0600)
    IPPROTO_PUP           = 12
    IPPROTO_UDP           = 17
    IPPROTO_IDP           = 22
#IF (%WIN32_WINNT >= &H0600)
    IPPROTO_RDP           = 27
#ENDIF ' (%WIN32_WINNT >= &H0600)

#IF (%WIN32_WINNT >= &H0501)
    IPPROTO_IPV6          = 41 ' IPv6 header
    IPPROTO_ROUTING       = 43 ' IPv6 Routing header
    IPPROTO_FRAGMENT      = 44 ' IPv6 fragmentation header
    IPPROTO_ESP           = 50 ' encapsulating security payload
    IPPROTO_AH            = 51 ' authentication header
    IPPROTO_ICMPV6        = 58 ' ICMPv6
    IPPROTO_NONE          = 59 ' IPv6 no next header
    IPPROTO_DSTOPTS       = 60 ' IPv6 Destination options
#ENDIF ' (%WIN32_WINNT >= &H0501)

    IPPROTO_ND            = 77
#IF (%WIN32_WINNT >= &H0501)
    IPPROTO_ICLFXBM       = 78
#ENDIF ' (%WIN32_WINNT >= &H0501)
#IF (%WIN32_WINNT >= &H0600)
    IPPROTO_PIM           = 103
    IPPROTO_PGM           = 113
    IPPROTO_L2TP          = 115
    IPPROTO_SCTP          = 132
#ENDIF ' (%WIN32_WINNT >= &H0600)
    IPPROTO_RAW           = 255

    IPPROTO_MAX           = 256
'
'  These are reserved for internal use by Windows.
'
    IPPROTO_RESERVED_RAW          = 257
    IPPROTO_RESERVED_IPSEC        = 258
    IPPROTO_RESERVED_IPSECOFFLOAD = 259
    IPPROTO_RESERVED_MAX          = 260
END ENUM  ' IPPROTO

'
' Port/socket numbers: network standard functions
'
%IPPORT_TCPMUX         = 1
%IPPORT_ECHO           = 7
%IPPORT_DISCARD        = 9
%IPPORT_SYSTAT         = 11
%IPPORT_DAYTIME        = 13
%IPPORT_NETSTAT        = 15
%IPPORT_QOTD           = 17
%IPPORT_MSP            = 18
%IPPORT_CHARGEN        = 19
%IPPORT_FTP_DATA       = 20
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
%IPPORT_POP3           = 110
%IPPORT_NTP            = 123
%IPPORT_EPMAP          = 135
%IPPORT_NETBIOS_NS     = 137
%IPPORT_NETBIOS_DGM    = 138
%IPPORT_NETBIOS_SSN    = 139
%IPPORT_IMAP           = 143
%IPPORT_SNMP           = 161
%IPPORT_SNMP_TRAP      = 162
%IPPORT_IMAP3          = 220
%IPPORT_LDAP           = 389
%IPPORT_HTTPS          = 443
%IPPORT_MICROSOFT_DS   = 445
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
#IF (%WIN32_WINNT >= &H0600)
%IPPORT_REGISTERED_MIN = %IPPORT_RESERVED
%IPPORT_REGISTERED_MAX = &Hbfff??
%IPPORT_DYNAMIC_MIN    = &Hc000??
%IPPORT_DYNAMIC_MAX    = &Hffff??
#ENDIF '(%WIN32_WINNT >= &H0600)

'
' Definitions of bits in internet address integers.
' On subnets, the decomposition of addresses to host and net parts
' is done according to subnet mask, not the masks here.
'
' N.B. RFC-compliant definitions for host-order elements are named IN_xxx,
' while network-order elements are named IN4_xxx.
'
MACRO IN_CLASSA(i) = ABS((i) AND &H80000000???) = 0)
%IN_CLASSA_NET         = &Hff000000???
%IN_CLASSA_NSHIFT      = 24
%IN_CLASSA_HOST        = &H00ffffff
%IN_CLASSA_MAX         = 128

MACRO IN_CLASSB(i) = ABS(((i) AND &Hc0000000???) = &H80000000???)
%IN_CLASSB_NET         = &Hffff0000???
%IN_CLASSB_NSHIFT      = 16
%IN_CLASSB_HOST        = &H0000ffff
%IN_CLASSB_MAX         = 65536

MACRO IN_CLASSC(i) = ABS(((i) AND &He0000000???) = &Hc0000000???)
%IN_CLASSC_NET         = &Hffffff00???
%IN_CLASSC_NSHIFT      = 8
%IN_CLASSC_HOST        = &H000000ff

MACRO IN_CLASSD(i) = ABS(((i) AND &Hf0000000???) = &He0000000???)
%IN_CLASSD_NET         = &Hf0000000???   ' These ones aren't really
%IN_CLASSD_NSHIFT      = 28               ' net and host fields, but
%IN_CLASSD_HOST        = &H0fffffff       ' routing needn't know.
MACRO IN_MULTICAST(i)  = IN_CLASSD(i)

%INADDR_ANY            = &H00000000???
%INADDR_LOOPBACK       = &H7f000001
%INADDR_BROADCAST      = &Hffffffff???
%INADDR_NONE           = &Hffffffff???


'
' Scope ID definition
'
MACRO SCOPE_LEVEL_enum=LONG
ENUM SCOPE_LEVEL SINGULAR
    ScopeLevelInterface    = 1
    ScopeLevelLink
    ScopeLevelSubnet
    ScopeLevelAdmin
    ScopeLevelSite
    ScopeLevelOrganization = 8
    ScopeLevelGlobal       = 14
    ScopeLevelCount        = 16
END ENUM  ' SCOPE_LEVEL

TYPE SCOPE_ID_type
    Zone  AS BIT * 28 IN DWORD
    Level AS BIT * 4
END TYPE

UNION SCOPE_ID
    SCOPE_ID_type
    Value AS DWORD
END UNION

%SCOPEID_UNSPECIFIED_INIT = 0

'
' IPv4 Socket address, Internet style
'

TYPE SOCKADDR_IN

#IF (%WIN32_WINNT < &H0600)
    sin_family  AS INTEGER
#ELSE '(%WIN32_WINNT < &H0600)
    sin_family  AS ADDRESS_FAMILY
#ENDIF '(%WIN32_WINNT < &H0600)

    sin_port    AS WORD
    sin_addr    AS IN_ADDR
    sin_zero(7) AS BYTE
END TYPE  ' SOCKADDR_IN

'
' Datalink (MAC) address
'
' If you don't use the entire sdl_data field, then fill it starting with the low
' bytes...
'

#IF (%WIN32_WINNT >= &H0601)

TYPE SOCKADDR_DL
    sdl_family  AS ADDRESS_FAMILY
    sdl_data(7) AS BYTE
    sdl_zero(3) AS BYTE
END TYPE  ' SOCKADDR_DL

#ENDIF '(%WIN32_WINNT >= &H0601)

%IOCPARM_MASK  = &H7f            ' parameters must be < 128 bytes
%IOC_VOID      = &H20000000      ' no parameters
%IOC_OUT       = &H40000000      ' copy out parameters
%IOC_IN        = &H80000000???   ' copy in parameters
%IOC_INOUT     = (%IOC_IN OR %IOC_OUT)
                                 ' &H20000000 distinguishes new & old ioctls

MACRO mac_IO(x,y)   = (%IOC_VOID OR ((x)*256) OR (y))

MACRO mac_IOR(x,y,t)=(%IOC_OUT OR (((LONG)SIZEOF(t) AND %IOCPARM_MASK)*65536) OR ((x)*256) OR (y))

MACRO mac_IOW(x,y,t)=(%IOC_IN OR (((LONG)SIZEOF(t) AND %IOCPARM_MASK)*65536) OR ((x)*256) OR (y))

'
' WinSock 2 extension -- WSABUF and QOS struct, include qos.h
' to pull in FLOWSPEC and related definitions
'

TYPE WSABUF
    dlen AS DWORD     ' the length of the buffer
    buf  AS BYTE PTR  ' the pointer to the buffer
END TYPE  ' WSABUF

'
' WSAMSG -- for WSASendMsg
'

TYPE WSAMSG
    saName        AS SOCKADDR PTR    ' Remote address
    namelen       AS LONG            ' Remote address length
    lpBuffers     AS WSABUF PTR      ' Data buffer array
    dwBufferCount AS DWORD           ' Number of elements in the array
    CONTROL       AS WSABUF          ' Control buffer
    dwFlags       AS DWORD           ' Flags
END TYPE  ' WSAMSG

'
' Layout of ancillary data objects in the control buffer (RFC 2292).
'
'#IF (%WIN32_WINNT >= &H0600)
'MACRO cmsghdr=WSACMSGHDR
'#ENDIF '(%WIN32_WINNT>=&H0600)

TYPE WSACMSGHDR
    cmsg_len   AS SIZE_T
    cmsg_level AS LONG
    cmsg_type  AS LONG
    ' followed by UCHAR cmsg_data[]
END TYPE  ' WSACMSGHDR

'#IF (%WIN32_WINNT >= &H0600)
'MACRO CMSGHDR=WSACMSGHDR
'#ENDIF '(%WIN32_WINNT>=&H0600)

'
' Alignment macros for header and data members of
' the control buffer.
'
'#define WSA_CMSGHDR_ALIGN(length)                           \
'            ( ((length) + TYPE_ALIGNMENT(WSACMSGHDR)-1) &   \
'                (~(TYPE_ALIGNMENT(WSACMSGHDR)-1)) )         \

'#define WSA_CMSGDATA_ALIGN(length)                          \
'            ( ((length) + MAX_NATURAL_ALIGNMENT-1) &        \
'                (~(MAX_NATURAL_ALIGNMENT-1)) )

#IF (%WIN32_WINNT >= &H0600)
'macro CMSGHDR_ALIGN=WSA_CMSGHDR_ALIGN
'macro CMSGDATA_ALIGN=WSA_CMSGDATA_ALIGN
#ENDIF '(%WIN32_WINNT>=&H0600)

'
'  WSA_CMSG_FIRSTHDR
'
'  Returns a pointer to the first ancillary data object,
'  or a null pointer if there is no ancillary data in the
'  control buffer of the WSAMSG structure.
'
'  LPCMSGHDR
'  WSA_CMSG_FIRSTHDR (
'      LPWSAMSG    msg
'      );
'
'#define WSA_CMSG_FIRSTHDR(msg) \
'    ( ((msg)->Control.len >= sizeof(WSACMSGHDR))            \
'        ? (LPWSACMSGHDR)(msg)->Control.buf                  \
'        : (LPWSACMSGHDR)NULL )

#IF (%WIN32_WINNT >= &H0600)
'macro CMSG_FIRSTHDR=WSA_CMSG_FIRSTHDR
#ENDIF '(%WIN32_WINNT>=&H0600)

'
'  WSA_CMSG_NXTHDR
'
'  Returns a pointer to the next ancillary data object,
'  or a null if there are no more data objects.
'
'  LPCMSGHDR
'  WSA_CMSG_NEXTHDR (
'      LPWSAMSG        msg,
'      LPWSACMSGHDR    cmsg
'      );
'
'#define WSA_CMSG_NXTHDR(msg, cmsg)                          \
'    ( ((cmsg) == NULL)                                      \
'        ? WSA_CMSG_FIRSTHDR(msg)                            \
'        : ( ( ((PUCHAR)(cmsg) +                             \
'                    WSA_CMSGHDR_ALIGN((cmsg)->cmsg_len) +   \
'                    sizeof(WSACMSGHDR) ) >                  \
'                (PUCHAR)((msg)->Control.buf) +              \
'                    (msg)->Control.len )                    \
'            ? (LPWSACMSGHDR)NULL                            \
'            : (LPWSACMSGHDR)((PUCHAR)(cmsg) +               \
'                WSA_CMSGHDR_ALIGN((cmsg)->cmsg_len)) ) )

#IF (%WIN32_WINNT >= &H0600)
'macro CMSG_NXTHDR=WSA_CMSG_NXTHDR
#ENDIF '(%WIN32_WINNT>=&H0600)

'
'  WSA_CMSG_DATA
'
'  Returns a pointer to the first byte of data (what is referred
'  to as the cmsg_data member though it is not defined in
'  the structure).
'
'  Note that RFC 2292 defines this as CMSG_DATA, but that name
'  is already used by wincrypt.h, and so Windows has used WSA_CMSG_DATA.
'
'  PUCHAR
'  WSA_CMSG_DATA (
'      LPWSACMSGHDR   pcmsg
'      );
'
'#define WSA_CMSG_DATA(cmsg)             \
'            ( (PUCHAR)(cmsg) + WSA_CMSGDATA_ALIGN(sizeof(WSACMSGHDR)) )

'
'  WSA_CMSG_SPACE
'
'  Returns total size of an ancillary data object given
'  the amount of data. Used to allocate the correct amount
'  of space.
'
'  SIZE_T
'  WSA_CMSG_SPACE (
'      SIZE_T length
'      );
'
'#define WSA_CMSG_SPACE(length)  \
'        (WSA_CMSGDATA_ALIGN(sizeof(WSACMSGHDR) + WSA_CMSGHDR_ALIGN(length)))

#IF (%WIN32_WINNT >= &H0600)
'macro CMSG_SPACE=WSA_CMSG_SPACE
#ENDIF '(%WIN32_WINNT>=&H0600)

'
'  WSA_CMSG_LEN
'
'  Returns the value to store in cmsg_len given the amount of data.
'
'  SIZE_T
'  WSA_CMSG_LEN (
'      SIZE_T length
'  );
'
'#define WSA_CMSG_LEN(length)    \
'         (WSA_CMSGDATA_ALIGN(sizeof(WSACMSGHDR)) + length)

#IF (%WIN32_WINNT >= &H0600)
'macro CMSG_LEN = WSA_CMSG_LEN
#ENDIF '(%WIN32_WINNT>=&H0600)

'
' Definition for flags member of the WSAMSG structure
' This is in addition to other MSG_xxx flags defined
' for recv/recvfrom/send/sendto.
'
%MSG_TRUNC     = &H0100
%MSG_CTRUNC    = &H0200
%MSG_BCAST     = &H0400
%MSG_MCAST     = &H0800

'
'  Flags used in "hints" argument to getaddrinfo()
'      - AI_ADDRCONFIG is supported starting with Vista
'      - default is AI_ADDRCONFIG ON whether the flag is set or not
'        because the performance penalty in not having ADDRCONFIG in
'        the multi-protocol stack environment is severe;
'        this defaulting may be disabled by specifying the AI_ALL flag,
'        in that case AI_ADDRCONFIG must be EXPLICITLY specified to
'        enable ADDRCONFIG behavior
'

%AI_PASSIVE                = &H00000001  ' Socket address will be used in bind() call
%AI_CANONNAME              = &H00000002  ' Return canonical name in first ai_canonname
%AI_NUMERICHOST            = &H00000004  ' Nodename must be a numeric address string
%AI_NUMERICSERV            = &H00000008  ' Servicename must be a numeric port number

%AI_ALL                    = &H00000100  ' Query both IP6 and IP4 with AI_V4MAPPED
%AI_ADDRCONFIG             = &H00000400  ' Resolution only if global address configured
%AI_V4MAPPED               = &H00000800  ' On v6 failure, query v4 and convert to V4MAPPED format

%AI_NON_AUTHORITATIVE      = &H00004000  ' LUP_NON_AUTHORITATIVE
%AI_SECURE                 = &H00008000  ' LUP_SECURE
%AI_RETURN_PREFERRED_NAMES = &H00010000  ' LUP_RETURN_PREFERRED_NAMES

%AI_FQDN                   = &H00020000  ' Return the FQDN in ai_canonname
%AI_FILESERVER             = &H00040000  ' Resolving fileserver name resolution

'
'  Structure used in getaddrinfo() call
'

TYPE ADDRINFOA
    ai_flags     AS LONG            ' AI_PASSIVE, AI_CANONNAME, AI_NUMERICHOST
    ai_family    AS LONG            ' PF_xxx
    ai_socktype  AS LONG            ' SOCK_xxx
    ai_protocol  AS LONG            ' 0 or IPPROTO_xxx for IPv4 and IPv6
    ai_addrlen   AS SIZE_T          ' Length of ai_addr
    ai_canonname AS ASCIIZ PTR      ' Canonical name for nodename
    ai_addr      AS SOCKADDR PTR    ' Binary address
    ai_next      AS ADDRINFOA PTR   ' Next structure in linked list
END TYPE   ' ADDRINFOA

TYPE ADDRINFOW
    ai_flags     AS LONG            ' AI_PASSIVE, AI_CANONNAME, AI_NUMERICHOST
    ai_family    AS LONG            ' PF_xxx
    ai_socktype  AS LONG            ' SOCK_xxx
    ai_protocol  AS LONG            ' 0 or IPPROTO_xxx for IPv4 and IPv6
    ai_addrlen   AS SIZE_T          ' Length of ai_addr
    ai_canonname AS WSTRINGZ PTR    ' Canonical name for nodename
    ai_addr      AS SOCKADDR PTR    ' Binary address
    ai_next      AS ADDRINFOW PTR   ' Next structure in linked list
END TYPE ADDRINFOW

#IF (%WIN32_WINNT >= &H0600)

TYPE ADDRINFOEXA
    ai_flags     AS LONG            ' AI_PASSIVE, AI_CANONNAME, AI_NUMERICHOST
    ai_family    AS LONG            ' PF_xxx
    ai_socktype  AS LONG            ' SOCK_xxx
    ai_protocol  AS LONG            ' 0 or IPPROTO_xxx for IPv4 and IPv6
    ai_addrlen   AS SIZE_T          ' Length of ai_addr
    ai_canonname AS ASCIIZ PTR      ' Canonical name for nodename
    ai_addr      AS SOCKADDR PTR    ' Binary address
    ai_blob      AS DWORD
    ai_bloblen   AS SIZE_T
    ai_provider  AS GUID PTR
    ai_next      AS ADDRINFOEXA PTR ' Next structure in linked list
END TYPE   ' ADDRINFOEXA

TYPE ADDRINFOEXW
    ai_flags     AS LONG            ' AI_PASSIVE, AI_CANONNAME, AI_NUMERICHOST
    ai_family    AS LONG            ' PF_xxx
    ai_socktype  AS LONG            ' SOCK_xxx
    ai_protocol  AS LONG            ' 0 or IPPROTO_xxx for IPv4 and IPv6
    ai_addrlen   AS SIZE_T          ' Length of ai_addr
    ai_canonname AS WSTRINGZ PTR    ' Canonical name for nodename
    ai_addr      AS SOCKADDR PTR    ' Binary address
    ai_blob      AS DWORD
    ai_bloblen   AS SIZE_T
    ai_provider  AS GUID PTR
    ai_next      AS ADDRINFOEXW PTR ' Next structure in linked list
END TYPE   ' ADDRINFOEXW

#ENDIF

'
' Flags for getaddrinfo()
'

' Name Spaces

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
%NS_NLA                    = (15)    ' Network Location Awareness */
#ENDIF '(%WIN32_WINNT >= &H0501)

#IF (%WIN32_WINNT >= &H0600)
%NS_BTH                    = (16)    ' Bluetooth SDP Namespace */
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

%NS_NETDES                 = (60)    ' Network Designers Limited */

'
' Flags for getnameinfo()
'

%NI_NOFQDN      = &H01  ' Only return nodename portion for local hosts */
%NI_NUMERICHOST = &H02  ' Return numeric form of the host's address */
%NI_NAMEREQD    = &H04  ' Error if the host's name not in DNS */
%NI_NUMERICSERV = &H08  ' Return numeric form of the service (port #) */
%NI_DGRAM       = &H10  ' Service is a datagram service */

%NI_MAXHOST     = 1025  ' Max size of a fully-qualified domain name */
%NI_MAXSERV     = 32    ' Max size of a service name */
