'------------------------------------------------------------------------------
'
'  Ws2IpDef.inc
'      This file contains TCP/IP specific information for use
'      by WinSock2 compatible applications.
'
'      To provide the backward compatibility, all the TCP/IP
'      specific definitions that were included in the WINSOCK.H
'      file are now included in WINSOCK2.H file. WS2TCPIP.H
'      file includes only the definitions  introduced in the
'      "WinSock 2 Protocol-Specific Annex" document.
'
'      Rev 0.3 Nov 13, 1995
'          Rev 0.4 Dec 15, 1996
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from Ws2IpDef.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WS2IPDEF = 1

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "Ws2Def.inc"

'#ifndef WS2IPDEF_ASSERT
'#define WS2IPDEF_ASSERT(exp) ((VOID) 0)
'#endif


#INCLUDE "in6addr.inc"

'
' Old IPv6 socket address structure (retained for sockaddr_gen definition).
'

TYPE SOCKADDR_IN6_OLD
    sin6_family   AS INTEGER     ' AF_INET6.
    sin6_port     AS WORD        ' Transport level port number.
    sin6_flowinfo AS DWORD       ' IPv6 flow information.
    sin6_addr     AS IN6_ADDR    ' IPv6 address.
END TYPE

UNION SOCKADDR_GEN
    Address    AS SOCKADDR
    AddressIn  AS SOCKADDR_IN
    AddressIn6 AS SOCKADDR_IN6_OLD
END UNION

'
' Structure to keep interface specific information
'

TYPE INTERFACE_INFO
    iiFlags            AS DWORD          ' Interface flags.
    iiAddress          AS SOCKADDR_GEN   ' Interface address.
    iiBroadcastAddress AS SOCKADDR_GEN   ' Broadcast address.
    iiNetmask          AS SOCKADDR_GEN   ' Network mask.
END TYPE

'
' New structure that does not have dependency on the address size.
'

TYPE INTERFACE_INFO_EX
    iiFlags            AS DWORD           ' Interface flags.
    iiAddress          AS SOCKET_ADDRESS  ' Interface address.
    iiBroadcastAddress AS SOCKET_ADDRESS  ' Broadcast address.
    iiNetmask          AS SOCKET_ADDRESS  ' Network mask.
END TYPE

'
' Possible flags for the  iiFlags - bitmask.
'

%IFF_UP            = &H00000001 ' Interface is up.
%IFF_BROADCAST     = &H00000002 ' Broadcast is  supported.
%IFF_LOOPBACK      = &H00000004 ' This is loopback interface.
%IFF_POINTTOPOINT  = &H00000008 ' This is point-to-point interface.
%IFF_MULTICAST     = &H00000010 ' Multicast is supported.


'
' Options to use with [gs]etsockopt at the IPPROTO_IP level.
' The values should be consistent with the IPv6 equivalents.
'
%IP_OPTIONS                =  1 ' Set/get IP options.
%IP_HDRINCL                =  2 ' Header is included with data.
%IP_TOS                    =  3 ' IP type of service.
%IP_TTL                    =  4 ' IP TTL (hop limit).
%IP_MULTICAST_IF           =  9 ' IP multicast interface.
%IP_MULTICAST_TTL          = 10 ' IP multicast TTL (hop limit).
%IP_MULTICAST_LOOP         = 11 ' IP multicast loopback.
%IP_ADD_MEMBERSHIP         = 12 ' Add an IP group membership.
%IP_DROP_MEMBERSHIP        = 13 ' Drop an IP group membership.
%IP_DONTFRAGMENT           = 14 ' Don't fragment IP datagrams.
%IP_ADD_SOURCE_MEMBERSHIP  = 15 ' Join IP group/source.
%IP_DROP_SOURCE_MEMBERSHIP = 16 ' Leave IP group/source.
%IP_BLOCK_SOURCE           = 17 ' Block IP group/source.
%IP_UNBLOCK_SOURCE         = 18 ' Unblock IP group/source.
%IP_PKTINFO                = 19 ' Receive packet information.
%IP_HOPLIMIT               = 21 ' Receive packet hop limit.
%IP_RECEIVE_BROADCAST      = 22 ' Allow/block broadcast reception.
%IP_RECVIF                 = 24 ' Receive arrival interface.
%IP_RECVDSTADDR            = 25 ' Receive destination address.
%IP_IFLIST                 = 28 ' Enable/Disable an interface list.
%IP_ADD_IFLIST             = 29 ' Add an interface list entry.
%IP_DEL_IFLIST             = 30 ' Delete an interface list entry.
%IP_UNICAST_IF             = 31 ' IP unicast interface.
%IP_RTHDR                  = 32 ' Set/get IPv6 routing header.
%IP_RECVRTHDR              = 38 ' Receive the routing header.
%IP_TCLASS                 = 39 ' Packet traffic class.
%IP_RECVTCLASS             = 40 ' Receive packet traffic class.
%IP_ORIGINAL_ARRIVAL_IF    = 47 ' Original Arrival Interface Index.

%IP_UNSPECIFIED_TYPE_OF_SERVICE = -1

'#define IPV6_ADDRESS_BITS RTL_BITS_OF(IN6_ADDR)
%IPV6_ADDRESS_BITS = 16 * 8 ' SIZEOF(IN6_ADDR) * 8

'
' IPv6 socket address structure, RFC 3493.
'

'
' NB: The LH version of sockaddr_in6 has the struct tag sockaddr_in6 rather
' than sockaddr_in6_lh.  This is to make sure that standard sockets apps
' that conform to RFC 2553 (Basic Socket Interface Extensions for IPv6).
'
UNION SOCKADDR_IN6_LH_union
    sin6_scope_id     AS DWORD      ' Set of interfaces for a scope.
    sin6_scope_struct AS SCOPE_ID
END UNION

TYPE SOCKADDR_IN6_LH
    sin6_family   AS ADDRESS_FAMILY  ' AF_INET6.
    sin6_port     AS WORD            ' Transport level port number.
    sin6_flowinfo AS DWORD           ' IPv6 flow information.
    sin6_addr     AS IN6_ADDR        ' IPv6 address.
    SOCKADDR_IN6_LH_union
END TYPE

TYPE SOCKADDR_IN6_W2KSP1
    sin6_family        AS INTEGER    '  AF_INET6
    sin6_port          AS WORD       ' Transport level port number
    sin6_flowinfo      AS DWORD      ' IPv6 flow information
    sin6_addr          AS in6_addr   ' IPv6 address
    sin6_scope_id      AS DWORD      ' set of interfaces for a scope
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
MACRO SOCKADDR_IN6=SOCKADDR_IN6_LH
#ELSEIF (%NTDDI_VERSION >= %NTDDI_WIN2KSP1)
MACRO SOCKADDR_IN6=SOCKADDR_IN6_W2KSP1
#ELSE
MACRO SOCKADDR_IN6=SOCKADDR_IN6_LH
#ENDIF

UNION SOCKADDR_INET
    Ipv4      AS SOCKADDR_IN
    Ipv6      AS SOCKADDR_IN6
    si_family AS ADDRESS_FAMILY
END UNION

'
' Structure to hold a pair of source, destination addresses.
'
TYPE SOCKADDR_IN6_PAIR
    SourceAddress      AS SOCKADDR_IN6 PTR
    DestinationAddress AS SOCKADDR_IN6 PTR
END TYPE

'
' Macro that works for both IPv4 and IPv6
'
' (((PSOCKADDR_IN)(ssp))->sin_port)
MACRO SS_PORT(ssp)=ssp.sin_port

#IF (%NTDDI_VERSION >= %NTDDI_WIN2KSP1)
'
' N.B. These addresses are in network byte order.
'

'#define IN6ADDR_ANY_INIT { 0 }
'
'#define IN6ADDR_LOOPBACK_INIT { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }
'
'#define IN6ADDR_ALLNODESONNODE_INIT { \
'    &Hff, &H01, &H00, &H00, &H00, &H00, &H00, &H00, \
'    &H00, &H00, &H00, &H00, &H00, &H00, &H00, &H01 \
'}
'
'#define IN6ADDR_ALLNODESONLINK_INIT { \
'    &Hff, &H02, &H00, &H00, &H00, &H00, &H00, &H00, \
'    &H00, &H00, &H00, &H00, &H00, &H00, &H00, &H01 \
'}
'
'#define IN6ADDR_ALLROUTERSONLINK_INIT { \
'    &Hff, &H02, &H00, &H00, &H00, &H00, &H00, &H00, \
'    &H00, &H00, &H00, &H00, &H00, &H00, &H00, &H02 \
'}
'
'#define IN6ADDR_ALLMLDV2ROUTERSONLINK_INIT { \
'    &Hff, &H02, &H00, &H00, &H00, &H00, &H00, &H00, \
'    &H00, &H00, &H00, &H00, &H00, &H00, &H00, &H16 \
'}
'
'#define IN6ADDR_TEREDOINITIALLINKLOCALADDRESS_INIT { \
'    &Hfe, &H80, &H00, &H00, &H00, &H00, &H00, &H00, \
'    &H00, &H00, &Hff, &Hff, &Hff, &Hff, &Hff, &Hfe \
'}

'
' The old link local address for XP-SP2/Win2K3 machines.
'
'#define IN6ADDR_TEREDOOLDLINKLOCALADDRESSXP_INIT {   \
'    &Hfe, &H80, &H00, &H00, &H00, &H00, &H00, &H00, \
'    &H00, &H00,  'T',   'E',  'R',  'E',  'D',  'O' \
'}

'
' The old link local address for Vista Beta-2 and earlier machines.
'
'#define IN6ADDR_TEREDOOLDLINKLOCALADDRESSVISTA_INIT {       \
'    &Hfe, &H80, &H00, &H00, &H00, &H00, &H00, &H00, \
'    &H00, &H00, &Hff, &Hff, &Hff, &Hff, &Hff, &Hff \
'}
'
'#define IN6ADDR_LINKLOCALPREFIX_INIT { &Hfe, &H80, }
'
'#define IN6ADDR_MULTICASTPREFIX_INIT { &Hff, &H00, }
'
'#define IN6ADDR_SOLICITEDNODEMULTICASTPREFIX_INIT { \
'    &Hff, &H02, &H00, &H00, &H00, &H00, &H00, &H00, \
'    &H00, &H00, &H00, &H01, &Hff, \
'}
'
'#define IN6ADDR_V4MAPPEDPREFIX_INIT { \
'    &H00, &H00, &H00, &H00, &H00, &H00, &H00, &H00, \
'    &H00, &H00, &Hff, &Hff, \
'}
'
'#define IN6ADDR_6TO4PREFIX_INIT { &H20, &H02, }
'
'#define IN6ADDR_TEREDOPREFIX_INIT { &H20, &H01, &H00, &H00, }
'
'#define IN6ADDR_TEREDOPREFIX_INIT_OLD { &H3f, &Hfe, &H83, &H1f, }

%IN6ADDR_LINKLOCALPREFIX_LENGTH              = 64

%IN6ADDR_MULTICASTPREFIX_LENGTH              = 8

%IN6ADDR_SOLICITEDNODEMULTICASTPREFIX_LENGTH = 104

%IN6ADDR_V4MAPPEDPREFIX_LENGTH               = 96

%IN6ADDR_6TO4PREFIX_LENGTH                   = 16

%IN6ADDR_TEREDOPREFIX_LENGTH                 = 32

'
' N.B. These addresses are in network byte order.
'
'extern CONST SCOPE_ID scopeid_unspecified;
'
'extern CONST IN_ADDR in4addr_any;
'extern CONST IN_ADDR in4addr_loopback;
'extern CONST IN_ADDR in4addr_broadcast;
'extern CONST IN_ADDR in4addr_allnodesonlink;
'extern CONST IN_ADDR in4addr_allroutersonlink;
'extern CONST IN_ADDR in4addr_alligmpv3routersonlink;
'extern CONST IN_ADDR in4addr_allteredohostsonlink;
'extern CONST IN_ADDR in4addr_linklocalprefix;
'extern CONST IN_ADDR in4addr_multicastprefix;
'
'extern CONST IN6_ADDR in6addr_any;
'extern CONST IN6_ADDR in6addr_loopback;
'extern CONST IN6_ADDR in6addr_allnodesonnode;
'extern CONST IN6_ADDR in6addr_allnodesonlink;
'extern CONST IN6_ADDR in6addr_allroutersonlink;
'extern CONST IN6_ADDR in6addr_allmldv2routersonlink;
'extern CONST IN6_ADDR in6addr_teredoinitiallinklocaladdress;
'extern CONST IN6_ADDR in6addr_linklocalprefix;
'extern CONST IN6_ADDR in6addr_multicastprefix;
'extern CONST IN6_ADDR in6addr_solicitednodemulticastprefix;
'extern CONST IN6_ADDR in6addr_v4mappedprefix;
'extern CONST IN6_ADDR in6addr_6to4prefix;
'extern CONST IN6_ADDR in6addr_teredoprefix;
'extern CONST IN6_ADDR in6addr_teredoprefix_old;


'#if not %def(%midl)
'
'WS2TCPIP_INLINE
'BOOLEAN
'IN6_ADDR_EQUAL(CONST IN6_ADDR *x, CONST IN6_ADDR *y)
'{
'    __int64 UNALIGNED *a;
'    __int64 UNALIGNED *b;
'
'    a = (__int64 UNALIGNED *)x;
'    b = (__int64 UNALIGNED *)y;
'
'    return (BOOLEAN)((a[1] == b[1]) && (a[0] == b[0]));
'}
'
''
'' RFC 3542 uses IN6_ARE_ADDR_EQUAL().
''
'macro IN6_ARE_ADDR_EQUAL=IN6_ADDR_EQUAL
'
'WS2TCPIP_INLINE
'BOOLEAN
'IN6_IS_ADDR_UNSPECIFIED(CONST IN6_ADDR *a)
'{
'    '
'    ' We can't use the in6addr_any variable, since that would
'    ' require existing callers to link with a specific library.
'    '
'    return (BOOLEAN)((a->s6_words[0] == 0) &&
'                     (a->s6_words[1] == 0) &&
'                     (a->s6_words[2] == 0) &&
'                     (a->s6_words[3] == 0) &&
'                     (a->s6_words[4] == 0) &&
'                     (a->s6_words[5] == 0) &&
'                     (a->s6_words[6] == 0) &&
'                     (a->s6_words[7] == 0));
'}
'
'WS2TCPIP_INLINE
'BOOLEAN
'IN6_IS_ADDR_LOOPBACK(CONST IN6_ADDR *a)
'{
'    '
'    ' We can't use the in6addr_loopback variable, since that would
'    ' require existing callers to link with a specific library.
'    '
'    return (BOOLEAN)((a->s6_words[0] == 0) &&
'                     (a->s6_words[1] == 0) &&
'                     (a->s6_words[2] == 0) &&
'                     (a->s6_words[3] == 0) &&
'                     (a->s6_words[4] == 0) &&
'                     (a->s6_words[5] == 0) &&
'                     (a->s6_words[6] == 0) &&
'                     (a->s6_words[7] == &H0100));
'}
'
'WS2TCPIP_INLINE
'BOOLEAN
'IN6_IS_ADDR_MULTICAST(CONST IN6_ADDR *a)
'{
'    return (BOOLEAN)(a->s6_bytes[0] == &Hff);
'}
'
''
''  Does the address have a format prefix
''  that indicates it uses EUI-64 interface identifiers?
''
'WS2TCPIP_INLINE
'BOOLEAN
'IN6_IS_ADDR_EUI64(CONST IN6_ADDR *a)
'{
'    '
'    ' Format prefixes 001 through 111, except for multicast.
'    '
'    return (BOOLEAN)(((a->s6_bytes[0] & &He0) != 0) &&
'                     !IN6_IS_ADDR_MULTICAST(a));
'}
'
''
''  Is this the subnet router anycast address?
''  See RFC 2373.
''
'WS2TCPIP_INLINE
'BOOLEAN
'IN6_IS_ADDR_SUBNET_ROUTER_ANYCAST(CONST IN6_ADDR *a)
'{
'    return (BOOLEAN)(IN6_IS_ADDR_EUI64(a) &&
'                     (a->s6_words[4] == 0) &&
'                     (a->s6_words[5] == 0) &&
'                     (a->s6_words[6] == 0) &&
'                     (a->s6_words[7] == 0));
'}
'
''
''  Is this a subnet reserved anycast address?
''  See RFC 2526. It talks about non-EUI-64
''  addresses as well, but IMHO that part
''  of the RFC doesn't make sense. For example,
''  it shouldn't apply to multicast or v4-compatible
''  addresses.
''
'WS2TCPIP_INLINE
'BOOLEAN
'IN6_IS_ADDR_SUBNET_RESERVED_ANYCAST(CONST IN6_ADDR *a)
'{
'    return (BOOLEAN)(IN6_IS_ADDR_EUI64(a) &&
'                     (a->s6_words[4] == &Hfffd) &&
'                     (a->s6_words[5] == &Hffff) &&
'                     (a->s6_words[6] == &Hffff) &&
'                     ((a->s6_words[7] & &H80ff) == &H80ff));
'}
'
''
''  As best we can tell from simple inspection,
''  is this an anycast address?
''
'WS2TCPIP_INLINE
'BOOLEAN
'IN6_IS_ADDR_ANYCAST(CONST IN6_ADDR *a)
'{
'    return (IN6_IS_ADDR_SUBNET_RESERVED_ANYCAST(a) ||
'            IN6_IS_ADDR_SUBNET_ROUTER_ANYCAST(a));
'}
'
'WS2TCPIP_INLINE
'BOOLEAN
'IN6_IS_ADDR_LINKLOCAL(CONST IN6_ADDR *a)
'{
'    return (BOOLEAN)((a->s6_bytes[0] == &Hfe) &&
'                     ((a->s6_bytes[1] & &Hc0) == &H80));
'}
'
'WS2TCPIP_INLINE
'BOOLEAN
'IN6_IS_ADDR_SITELOCAL(CONST IN6_ADDR *a)
'{
'    return (BOOLEAN)((a->s6_bytes[0] == &Hfe) &&
'                     ((a->s6_bytes[1] & &Hc0) == &Hc0));
'}
'
'WS2TCPIP_INLINE
'BOOLEAN
'IN6_IS_ADDR_GLOBAL(CONST IN6_ADDR *a)
'{
'    '
'    ' Check the format prefix and exclude addresses
'    ' whose high 4 bits are all zero or all one.
'    ' This is a cheap way of excluding v4-compatible,
'    ' v4-mapped, loopback, multicast, link-local, site-local.
'    '
'    DWORD High = (a->s6_bytes[0] & &Hf0);
'    return (BOOLEAN)((High != 0) && (High != &Hf0));
'}
'
'WS2TCPIP_INLINE
'BOOLEAN
'IN6_IS_ADDR_V4MAPPED(CONST IN6_ADDR *a)
'{
'    return (BOOLEAN)((a->s6_words[0] == 0) &&
'                     (a->s6_words[1] == 0) &&
'                     (a->s6_words[2] == 0) &&
'                     (a->s6_words[3] == 0) &&
'                     (a->s6_words[4] == 0) &&
'                     (a->s6_words[5] == &Hffff));
'}
'
'WS2TCPIP_INLINE
'BOOLEAN
'IN6_IS_ADDR_V4COMPAT(CONST IN6_ADDR *a)
'{
'    return (BOOLEAN)((a->s6_words[0] == 0) &&
'                     (a->s6_words[1] == 0) &&
'                     (a->s6_words[2] == 0) &&
'                     (a->s6_words[3] == 0) &&
'                     (a->s6_words[4] == 0) &&
'                     (a->s6_words[5] == 0) &&
'                     !((a->s6_words[6] == 0) &&
'                       (a->s6_addr[14] == 0) &&
'                       ((a->s6_addr[15] == 0) || (a->s6_addr[15] == 1))));
'}
'
'WS2TCPIP_INLINE
'BOOLEAN
'IN6_IS_ADDR_V4TRANSLATED(CONST IN6_ADDR *a)
'{
'    return (BOOLEAN)((a->s6_words[0] == 0) &&
'                     (a->s6_words[1] == 0) &&
'                     (a->s6_words[2] == 0) &&
'                     (a->s6_words[3] == 0) &&
'                     (a->s6_words[4] == &Hffff) &&
'                     (a->s6_words[5] == 0));
'}
'
'WS2TCPIP_INLINE
'BOOLEAN
'IN6_IS_ADDR_MC_NODELOCAL(CONST IN6_ADDR *a)
'{
'    return (BOOLEAN)(IN6_IS_ADDR_MULTICAST(a) &&
'                     ((a->s6_bytes[1] & &Hf) == 1));
'}
'
'WS2TCPIP_INLINE
'BOOLEAN
'IN6_IS_ADDR_MC_LINKLOCAL(CONST IN6_ADDR *a)
'{
'    return (BOOLEAN)(IN6_IS_ADDR_MULTICAST(a) &&
'                     ((a->s6_bytes[1] & &Hf) == 2));
'}
'
'WS2TCPIP_INLINE
'BOOLEAN
'IN6_IS_ADDR_MC_SITELOCAL(CONST IN6_ADDR *a)
'{
'    return (BOOLEAN)(IN6_IS_ADDR_MULTICAST(a) &&
'                     ((a->s6_bytes[1] & &Hf) == 5));
'}
'
'WS2TCPIP_INLINE
'BOOLEAN
'IN6_IS_ADDR_MC_ORGLOCAL(CONST IN6_ADDR *a)
'{
'    return (BOOLEAN)(IN6_IS_ADDR_MULTICAST(a) &&
'                     ((a->s6_bytes[1] & &Hf) == 8));
'}
'
'WS2TCPIP_INLINE
'BOOLEAN
'IN6_IS_ADDR_MC_GLOBAL(CONST IN6_ADDR *a)
'{
'    return (BOOLEAN)(IN6_IS_ADDR_MULTICAST(a) &&
'                     ((a->s6_bytes[1] & &Hf) == &He));
'}
'
'WS2TCPIP_INLINE
'VOID
'IN6_SET_ADDR_UNSPECIFIED(PIN6_ADDR a)
'{
'    '
'    ' We can't use the in6addr_any variable, since that would
'    ' require existing callers to link with a specific library.
'    '
'    memset(a->s6_bytes, 0, sizeof(IN6_ADDR));
'}
'
'WS2TCPIP_INLINE
'VOID
'IN6_SET_ADDR_LOOPBACK(PIN6_ADDR a)
'{
'    '
'    ' We can't use the in6addr_loopback variable, since that would
'    ' require existing callers to link with a specific library.
'    '
'    memset(a->s6_bytes, 0, sizeof(IN6_ADDR));
'    a->s6_bytes[15] = 1;
'}
'
'WS2TCPIP_INLINE
'VOID
'IN6ADDR_SETANY(PSOCKADDR_IN6 a)
'{
'    a->sin6_family = AF_INET6;
'    a->sin6_port = 0;
'    a->sin6_flowinfo = 0;
'    IN6_SET_ADDR_UNSPECIFIED(&a->sin6_addr);
'    a->sin6_scope_id = 0;
'}
'
'WS2TCPIP_INLINE
'VOID
'IN6ADDR_SETLOOPBACK(PSOCKADDR_IN6 a)
'{
'    a->sin6_family = AF_INET6;
'    a->sin6_port = 0;
'    a->sin6_flowinfo = 0;
'    IN6_SET_ADDR_LOOPBACK(&a->sin6_addr);
'    a->sin6_scope_id = 0;
'}
'
'WS2TCPIP_INLINE
'BOOLEAN
'IN6ADDR_ISANY(CONST SOCKADDR_IN6 *a)
'{
'    WS2IPDEF_ASSERT(a->sin6_family == AF_INET6);
'    return IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr);
'}
'
'WS2TCPIP_INLINE
'BOOLEAN
'IN6ADDR_ISLOOPBACK(CONST SOCKADDR_IN6 *a)
'{
'    WS2IPDEF_ASSERT(a->sin6_family == AF_INET6);
'    return IN6_IS_ADDR_LOOPBACK(&a->sin6_addr);
'}
'
'WS2TCPIP_INLINE
'BOOLEAN
'IN6ADDR_ISEQUAL(CONST SOCKADDR_IN6 *a, CONST SOCKADDR_IN6 *b)
'{
'    WS2IPDEF_ASSERT(a->sin6_family == AF_INET6);
'    return (BOOLEAN)(a->sin6_scope_id == b->sin6_scope_id &&
'                     IN6_ADDR_EQUAL(&a->sin6_addr, &b->sin6_addr));
'}
'
'WS2TCPIP_INLINE
'BOOLEAN
'IN6ADDR_ISUNSPECIFIED(CONST SOCKADDR_IN6 *a)
'{
'    WS2IPDEF_ASSERT(a->sin6_family == AF_INET6);
'    return (BOOLEAN)(a->sin6_scope_id == 0 &&
'                     IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr));
'}
'
'#endif ' %midl

#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WIN2KSP1)


' TCP/IP specific Ioctl codes.
'
%SIO_GET_INTERFACE_LIST    = &H4004747F     ' _IOR('t', 127, DWORD)
%SIO_GET_INTERFACE_LIST_EX = &H4004747E     ' _IOR('t', 126, DWORD)
%SIO_SET_MULTICAST_FILTER  = &H8004747D???  ' _IOW('t', 125, DWORD)
%SIO_GET_MULTICAST_FILTER  = &H8004747C???  ' _IOW('t', 124 | IOC_IN, DWORD)
%SIOCSIPMSFILTER           = %SIO_SET_MULTICAST_FILTER
%SIOCGIPMSFILTER           = %SIO_GET_MULTICAST_FILTER

'
' Protocol independent ioctls for setting and retrieving multicast filters.
'


%SIOCSMSFILTER   = &H8004747E???   ' _IOW('t', 126, DWORD)
%SIOCGMSFILTER   = &H8004747F???   ' _IOW('t', 127 | IOC_IN, DWORD)

#IF (%NTDDI_VERSION >= %NTDDI_VISTASP1)

%IDEAL_SEND_BACKLOG_IOCTLS = 1

'
' Query and change notification ioctls for the ideal send backlog size
' for a given connection. Clients should use the wrappers defined in
' ws2tcpip.h rather than using these ioctls directly.
'

%SIO_IDEAL_SEND_BACKLOG_QUERY  = &H4004747B  ' _IOR('t', 123, DWORD)
%SIO_IDEAL_SEND_BACKLOG_CHANGE = &H2000747A  '  _IO('t', 122)

#ENDIF

'
' Protocol independent multicast source filter options.
'
%MCAST_JOIN_GROUP          = 41  ' Join all sources for a group.
%MCAST_LEAVE_GROUP         = 42  ' Drop all sources for a group.
%MCAST_BLOCK_SOURCE        = 43  ' Block IP group/source.
%MCAST_UNBLOCK_SOURCE      = 44  ' Unblock IP group/source.
%MCAST_JOIN_SOURCE_GROUP   = 45  ' Join IP group/source.
%MCAST_LEAVE_SOURCE_GROUP  = 46  ' Leave IP group/source.

'
' Definitions of MCAST_INCLUDE and MCAST_EXCLUDE for multicast source filter.
'
MACRO MULTICAST_MODE_TYPE_enum=LONG
ENUM MULTICAST_MODE_TYPE SINGULAR
    MCAST_INCLUDE
    MCAST_EXCLUDE
END ENUM

'
' Structure for IP_MREQ (used by IP_ADD_MEMBERSHIP and IP_DROP_MEMBERSHIP).
'
TYPE IP_MREQ
    imr_multiaddr AS IN_ADDR   ' IP multicast address of group.
    imr_interface AS IN_ADDR   ' Local IP address of interface.
END TYPE

'
' Structure for IP_MREQ_SOURCE (used by IP_BLOCK_SOURCE, IP_UNBLOCK_SOURCE
' etc.).
'
TYPE IP_MREQ_SOURCE
    imr_multiaddr  AS IN_ADDR   ' IP multicast address of group.
    imr_sourceaddr AS IN_ADDR   ' IP address of source.
    imr_interface  AS IN_ADDR   ' Local IP address of interface.
END TYPE

'
' Structure for IP_MSFILTER (used by SIOCSIPMSFILTER and SIOCGIPMSFILTER).
'
TYPE IP_MSFILTER
    imsf_multiaddr AS IN_ADDR   ' IP multicast address of group.
    imsf_interface AS IN_ADDR   ' Local IP address of interface.
    imsf_fmode     AS MULTICAST_MODE_TYPE_enum   ' Filter mode.
    imsf_numsrc    AS DWORD     ' Number of sources in src_list.
    imsf_slist(0)  AS IN_ADDR   ' Start of source list.
END TYPE

MACRO IP_MSFILTER_SIZE(NumSources)=(SIZEOF(IP_MSFILTER) - SIZEOF(IN_ADDR) + (NumSources) * SIZEOF(IN_ADDR))

'
' Options to use with [gs]etsockopt at the IPPROTO_IPV6 level.
' These are specified in RFCs 3493 and 3542.
' The values should be consistent with the IPv6 equivalents.
'
%IPV6_HOPOPTS          =  1 ' Set/get IPv6 hop-by-hop options.
%IPV6_HDRINCL          =  2 ' Header is included with data.
%IPV6_UNICAST_HOPS     =  4 ' IP unicast hop limit.
%IPV6_MULTICAST_IF     =  9 ' IP multicast interface.
%IPV6_MULTICAST_HOPS   = 10 ' IP multicast hop limit.
%IPV6_MULTICAST_LOOP   = 11 ' IP multicast loopback.
%IPV6_ADD_MEMBERSHIP   = 12 ' Add an IP group membership.
%IPV6_JOIN_GROUP       = %IPV6_ADD_MEMBERSHIP
%IPV6_DROP_MEMBERSHIP  = 13 ' Drop an IP group membership.
%IPV6_LEAVE_GROUP      = %IPV6_DROP_MEMBERSHIP
%IPV6_DONTFRAG         = 14 ' Don't fragment IP datagrams.
%IPV6_PKTINFO          = 19 ' Receive packet information.
%IPV6_HOPLIMIT         = 21 ' Receive packet hop limit.
%IPV6_PROTECTION_LEVEL = 23 ' Set/get IPv6 protection level.
%IPV6_RECVIF           = 24 ' Receive arrival interface.
%IPV6_RECVDSTADDR      = 25 ' Receive destination address.
%IPV6_CHECKSUM         = 26 ' Offset to checksum for raw IP socket send.
%IPV6_V6ONLY           = 27 ' Treat wildcard bind as AF_INET6-only.
%IPV6_IFLIST           = 28 ' Enable/Disable an interface list.
%IPV6_ADD_IFLIST       = 29 ' Add an interface list entry.
%IPV6_DEL_IFLIST       = 30 ' Delete an interface list entry.
%IPV6_UNICAST_IF       = 31 ' IP unicast interface.
%IPV6_RTHDR            = 32 ' Set/get IPv6 routing header.
%IPV6_RECVRTHDR        = 38 ' Receive the routing header.
%IPV6_TCLASS           = 39 ' Packet traffic class.
%IPV6_RECVTCLASS       = 40 ' Receive packet traffic class.

%IP_UNSPECIFIED_HOP_LIMIT = -1

%IP_PROTECTION_LEVEL = %IPV6_PROTECTION_LEVEL
'
' Values of IPV6_PROTECTION_LEVEL.
'
%PROTECTION_LEVEL_UNRESTRICTED   = 10 ' For peer-to-peer apps.
%PROTECTION_LEVEL_EDGERESTRICTED = 20 ' Same as unrestricted. Except for
                                           ' Teredo.
%PROTECTION_LEVEL_RESTRICTED     = 30 ' For Intranet apps.

#IF (%NTDDI_VERSION < %NTDDI_VISTA)
%PROTECTION_LEVEL_DEFAULT     = %PROTECTION_LEVEL_EDGERESTRICTED
#ELSE
%PROTECTION_LEVEL_DEFAULT     = &HFFFFFFFF???   ' ((UINT)-1)
#ENDIF
'
' Structure for IPV6_JOIN_GROUP and IPV6_LEAVE_GROUP (also,
' IPV6_ADD_MEMBERSHIP and IPV6_DROP_MEMBERSHIP).
'
TYPE IPV6_MREQ
    ipv6mr_multiaddr AS IN6_ADDR   ' IPv6 multicast address.
    ipv6mr_interface AS DWORD      ' Interface index.
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
'
' Structure for GROUP_REQ used by protocol independent source filters
' (MCAST_JOIN_GROUP and MCAST_LEAVE_GROUP).
'
TYPE GROUP_REQ
    gr_interface AS DWORD             ' Interface index.
    gr_group     AS SOCKADDR_STORAGE  ' Multicast address.
END TYPE

'
' Structure for GROUP_SOURCE_REQ used by protocol independent source filters
' (MCAST_JOIN_SOURCE_GROUP, MCAST_LEAVE_SOURCE_GROUP etc.).
'
TYPE GROUP_SOURCE_REQ
    gsr_interface AS DWORD             ' Interface index.
    gsr_group     AS SOCKADDR_STORAGE  ' Group address.
    gsr_source    AS SOCKADDR_STORAGE  ' Source address.
END TYPE

'
' Structure for GROUP_FILTER used by protocol independent source filters
' (SIOCSMSFILTER and SIOCGMSFILTER).
'
TYPE GROUP_FILTER
    gf_interface AS DWORD          ' Interface index.
    gf_group     AS SOCKADDR_STORAGE   ' Multicast address.
    gf_fmode     AS MULTICAST_MODE_TYPE_enum  ' Filter mode.
    gf_numsrc    AS DWORD             ' Number of sources.
    gf_slist(0)  AS SOCKADDR_STORAGE  ' Source address.
END TYPE

'#define GROUP_FILTER_SIZE(numsrc) \
'   (sizeof(GROUP_FILTER) - sizeof(SOCKADDR_STORAGE) \
'   + (numsrc) * sizeof(SOCKADDR_STORAGE))
#ENDIF

'
' Structure for IP_PKTINFO option.
'
TYPE IN_PKTINFO
    ipi_addr    AS IN_ADDR   ' Source/destination IPv4 address.
    ipi_ifindex AS DWORD     ' Send/receive interface index.
END TYPE

'C_ASSERT(sizeof(IN_PKTINFO) == 8);

'
' Structure for IPV6_PKTINFO option.
'
TYPE IN6_PKTINFO
    ipi6_addr AS IN6_ADDR     ' Source/destination IPv6 address.
    ipi6_ifindex AS DWORD     ' Send/receive interface index.
END TYPE

'C_ASSERT(sizeof(IN6_PKTINFO) == 20);

'
' Maximum length of address literals (potentially including a port number)
' generated by any address-to-string conversion routine.  This length can
' be used when declaring buffers used with getnameinfo, WSAAddressToString,
' inet_ntoa, etc.  We just provide one define, rather than one per api,
' to avoid confusion.
'
' The totals are derived from the following data:
'  15: IPv4 address
'  45: IPv6 address including embedded IPv4 address
'  11: Scope Id
'   2: Brackets around IPv6 address when port is present
'   6: Port (including colon)
'   1: Terminating null byte
'
%INET_ADDRSTRLEN  = 22
%INET6_ADDRSTRLEN = 65



'
' Options to use with [gs]etsockopt at the IPPROTO_TCP level.
' TCP_NODELAY is defined in ws2def.h for historical reasons.
'

'
' Offload preferences supported.
'
%TCP_OFFLOAD_NO_PREFERENCE = 0
%TCP_OFFLOAD_NOT_PREFERRED = 1
%TCP_OFFLOAD_PREFERRED     = 2

'     %TCP_NODELAY              = &H0001
%TCP_EXPEDITED_1122       = &H0002
%TCP_KEEPALIVE            = 3
%TCP_MAXSEG               = 4
%TCP_MAXRT                = 5
%TCP_STDURG               = 6
%TCP_NOURG                = 7
%TCP_ATMARK               = 8
%TCP_NOSYNRETRIES         = 9
%TCP_TIMESTAMPS           = 10
%TCP_OFFLOAD_PREFERENCE   = 11
%TCP_CONGESTION_ALGORITHM = 12
%TCP_DELAY_FIN_ACK        = 13
