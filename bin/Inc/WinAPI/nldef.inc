'------------------------------------------------------------------------------
'
'  NlDef.inc
'    This module contains basic network layer definitions.
'    Previously some of these were duplicated in both routprot.h and
'    iprtrmib.h.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from NlDef.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%NLDEF = 1

%NL_MAX_METRIC_COMPONENT = 2147483647  ' ((((ULONG) 1) << 31) - 1)

MACRO NL_PREFIX_ORIGIN_enum=LONG
ENUM NL_PREFIX_ORIGIN SINGULAR
    '
    ' These values are from iptypes.h.
    ' They need to fit in a 4 bit field.
    ' [except, apparently, when they don't]
    '
    IpPrefixOriginOther
    IpPrefixOriginManual
    IpPrefixOriginWellKnown
    IpPrefixOriginDhcp
    IpPrefixOriginRouterAdvertisement
    IpPrefixOriginUnchanged = 16 ' 1 << 4
END ENUM

'
' TODO: Remove these definitions.
'
%NlpoOther               = %IpPrefixOriginOther
%NlpoManual              = %IpPrefixOriginManual
%NlpoWellKnown           = %IpPrefixOriginWellKnown
%NlpoDhcp                = %IpPrefixOriginDhcp
%NlpoRouterAdvertisement = %IpPrefixOriginRouterAdvertisement

MACRO NL_SUFFIX_ORIGIN_enum=LONG
ENUM NL_SUFFIX_ORIGIN SINGULAR
    '
    ' TODO: Remove the Nlso* definitions.
    '
    NlsoOther
    NlsoManual
    NlsoWellKnown
    NlsoDhcp
    NlsoLinkLayerAddress
    NlsoRandom

    '
    ' These values are from in iptypes.h.
    ' They need to fit in a 4 bit field.
    ' [except, apparently, when they don't]
    '
    IpSuffixOriginOther            = 0
    IpSuffixOriginManual
    IpSuffixOriginWellKnown
    IpSuffixOriginDhcp
    IpSuffixOriginLinkLayerAddress
    IpSuffixOriginRandom
    IpSuffixOriginUnchanged        = 16 ' 1 << 4
END ENUM


MACRO NL_DAD_STATE_enum=LONG
ENUM NL_DAD_STATE SINGULAR
    '
    ' TODO: Remove the Nlds* definitions.
    '
    NldsInvalid
    NldsTentative
    NldsDuplicate
    NldsDeprecated
    NldsPreferred

    '
    ' These values are from in iptypes.h.
    '
    IpDadStateInvalid    = 0
    IpDadStateTentative
    IpDadStateDuplicate
    IpDadStateDeprecated
    IpDadStatePreferred
END ENUM

'
' MIB_IPPROTO_* values were previously in iprtrmib.h.
' PROTO_IP_* values were previously in routprot.h.
'
'#define MAKE_ROUTE_PROTOCOL(suffix, value) \
'    MIB_IPPROTO_ ## suffix = value, \
'    PROTO_IP_ ## suffix    = value

'
' Routing protocol values from RFC.
'

MACRO NL_ROUTE_PROTOCOL_enum=LONG
ENUM NL_ROUTE_PROTOCOL SINGULAR
    '
    ' TODO: Remove the RouteProtocol* definitions.
    '
    RouteProtocolOther   = 1
    RouteProtocolLocal
    RouteProtocolNetMgmt
    RouteProtocolIcmp
    RouteProtocolEgp
    RouteProtocolGgp
    RouteProtocolHello
    RouteProtocolRip
    RouteProtocolIsIs
    RouteProtocolEsIs
    RouteProtocolCisco
    RouteProtocolBbn
    RouteProtocolOspf
    RouteProtocolBgp

    MIB_IPPROTO_OTHER    = 1
    MIB_IPPROTO_LOCAL
    MIB_IPPROTO_NETMGMT
    MIB_IPPROTO_ICMP
    MIB_IPPROTO_EGP
    MIB_IPPROTO_GGP
    MIB_IPPROTO_HELLO
    MIB_IPPROTO_RIP
    MIB_IPPROTO_IS_IS
    MIB_IPPROTO_ES_IS
    MIB_IPPROTO_CISCO
    MIB_IPPROTO_BBN
    MIB_IPPROTO_OSPF
    MIB_IPPROTO_BGP

    PROTO_IP_OTHER    = 1
    PROTO_IP_LOCAL
    PROTO_IP_NETMGMT
    PROTO_IP_ICMP
    PROTO_IP_EGP
    PROTO_IP_GGP
    PROTO_IP_HELLO
    PROTO_IP_RIP
    PROTO_IP_IS_IS
    PROTO_IP_ES_IS
    PROTO_IP_CISCO
    PROTO_IP_BBN
    PROTO_IP_OSPF
    PROTO_IP_BGP

    '
    ' Windows-specific definitions.
    '
    MIB_IPPROTO_NT_AUTOSTATIC      = 10002
    MIB_IPPROTO_NT_STATIC          = 10006
    MIB_IPPROTO_NT_STATIC_NON_DOD  = 10007

    PROTO_IP_NT_AUTOSTATIC      = 10002
    PROTO_IP_NT_STATIC          = 10006
    PROTO_IP_NT_STATIC_NON_DOD  = 10007
END ENUM

MACRO NL_ADDRESS_TYPE_enum=LONG
ENUM NL_ADDRESS_TYPE SINGULAR
    NlatUnspecified
    NlatUnicast
    NlatAnycast
    NlatMulticast
    NlatBroadcast
    NlatInvalid
END ENUM

'
' NL_ROUTE_ORIGIN
'
' Define route origin values.
'

MACRO NL_ROUTE_ORIGIN_enum=LONG
ENUM NL_ROUTE_ORIGIN SINGULAR
    NlroManual
    NlroWellKnown
    NlroDHCP
    NlroRouterAdvertisement
    Nlro6to4
END ENUM

'
' NL_NEIGHBOR_STATE
'
' Define network layer neighbor state.  RFC 2461, section 7.3.2 has details.
' Note: Only state names are documented, we chose the values used here.
'

MACRO NL_NEIGHBOR_STATE_enum=LONG
ENUM NL_NEIGHBOR_STATE SINGULAR
    NlnsUnreachable
    NlnsIncomplete
    NlnsProbe
    NlnsDelay
    NlnsStale
    NlnsReachable
    NlnsPermanent
    NlnsMaximum
END ENUM

MACRO NL_LINK_LOCAL_ADDRESS_BEHAVIOR_enum=LONG
ENUM NL_LINK_LOCAL_ADDRESS_BEHAVIOR SINGULAR
    LinkLocalUnchanged = -1
    LinkLocalAlwaysOff        ' Never use link locals.
    LinkLocalDelayed          ' Use link locals only if no other addresses.
                              ' (default for IPv4).
                              ' Legacy mapping: IPAutoconfigurationEnabled.
    LinkLocalAlwaysOn         ' Always use link locals (default for IPv6).
END ENUM


TYPE NL_INTERFACE_OFFLOAD_ROD
    NlChecksumSupported         AS BIT * 1 IN BYTE  ' BOOLEAN
    NlOptionsSupported          AS BIT * 1
    TlDatagramChecksumSupported AS BIT * 1
    TlStreamChecksumSupported   AS BIT * 1
    TlStreamOptionsSupported    AS BIT * 1
    FastPathCompatible          AS BIT * 1
    TlLargeSendOffloadSupported AS BIT * 1
    TlGiantSendOffloadSupported AS BIT * 1
END TYPE


MACRO NL_ROUTER_DISCOVERY_BEHAVIOR_enum=LONG
ENUM NL_ROUTER_DISCOVERY_BEHAVIOR SINGULAR
    RouterDiscoveryUnchanged = -1
    RouterDiscoveryDisabled
    RouterDiscoveryEnabled
    RouterDiscoveryDhcp
END ENUM

MACRO NL_BANDWIDTH_FLAG_enum=LONG
ENUM NL_BANDWIDTH_FLAG SINGULAR
    NlbwUnchanged = -1
    NlbwDisabled
    NlbwEnabled
END ENUM

TYPE NL_PATH_BANDWIDTH_ROD
    Bandwidth       AS QUAD  ' ULONG64
    Instability     AS QUAD  ' ULONG64
    BandwidthPeaked AS BYTE  ' BOOLEAN
END TYPE

MACRO NL_NETWORK_CATEGORY_enum=LONG
ENUM NL_NETWORK_CATEGORY SINGULAR
    NetworkCategoryPublic
    NetworkCategoryPrivate
    NetworkCategoryDomainAuthenticated
    NetworkCategoryUnchanged = -1           ' used in a set operation
    NetworkCategoryUnknown   = -1           ' returned in a query operation
END ENUM

%NET_IF_CURRENT_SESSION = &HFFFFFFFF???  ' ((ULONG)-1)
