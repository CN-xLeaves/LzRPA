'------------------------------------------------------------------------------
'
'  iptypes.inc
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from iptypes.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%IP_TYPES_INCLUDED = 1


#INCLUDE "time.inc"
#INCLUDE "ifdef.inc"
#INCLUDE "nldef.inc"

' Definitions and structures used by getnetworkparams and getadaptersinfo apis

%MAX_ADAPTER_DESCRIPTION_LENGTH = 128 ' arb.
%MAX_ADAPTER_NAME_LENGTH        = 256 ' arb.
%MAX_ADAPTER_ADDRESS_LENGTH     = 8   ' arb.
%DEFAULT_MINIMUM_ENTITIES       = 32  ' arb.
%MAX_HOSTNAME_LEN               = 128 ' arb.
%MAX_DOMAIN_NAME_LEN            = 128 ' arb.
%MAX_SCOPE_ID_LEN               = 256 ' arb.
%MAX_DHCPV6_DUID_LENGTH         = 130 ' RFC 3315.
%MAX_DNS_SUFFIX_STRING_LENGTH   = 256

'
' types
'

' Node Type

%BROADCAST_NODETYPE            = 1
%PEER_TO_PEER_NODETYPE         = 2
%MIXED_NODETYPE                = 4
%HYBRID_NODETYPE               = 8

'
' IP_ADDRESS_STRING - store an IP address as a dotted decimal string
'

TYPE IP_ADDRESS_STRING
    sString AS STRING * 16
END TYPE

TYPE IP_MASK_STRING
    IP_ADDRESS_STRING
END TYPE

'
' IP_ADDR_STRING - store an IP address with its corresponding subnet mask,
' both as dotted decimal strings
'

TYPE IP_ADDR_STRING
    pNext     AS IP_ADDR_STRING PTR
    IpAddress AS IP_ADDRESS_STRING
    IpMask    AS IP_MASK_STRING
    Context   AS DWORD
END TYPE

'
' ADAPTER_INFO - per-adapter information. All IP addresses are stored as
' strings
'

TYPE IP_ADAPTER_INFO
    pNext               AS IP_ADAPTER_INFO PTR
    ComboIndex          AS DWORD
    AdapterName         AS ASCIIZ * %MAX_ADAPTER_NAME_LENGTH + 4
    Description         AS ASCIIZ * %MAX_ADAPTER_DESCRIPTION_LENGTH + 4
    AddressLength       AS DWORD
    Address             AS STRING * %MAX_ADAPTER_ADDRESS_LENGTH
    Index               AS DWORD
    nType               AS DWORD
    DhcpEnabled         AS DWORD
    CurrentIpAddress    AS IP_ADDR_STRING PTR
    IpAddressList       AS IP_ADDR_STRING
    GatewayList         AS IP_ADDR_STRING
    DhcpServer          AS IP_ADDR_STRING
    HaveWins            AS LONG  ' BOOL
    PrimaryWinsServer   AS IP_ADDR_STRING
    SecondaryWinsServer AS IP_ADDR_STRING
    LeaseObtained       AS time_t
    LeaseExpires        AS time_t
END TYPE

#IF %DEF(%WINSOCK2API)

'
' The following types require Winsock2.
'

MACRO IP_PREFIX_ORIGIN_enum=NL_PREFIX_ORIGIN_enum

MACRO IP_SUFFIX_ORIGIN_enum=NL_SUFFIX_ORIGIN_enum

MACRO IP_DAD_STATE_enum=NL_DAD_STATE_enum

TYPE IP_ADAPTER_ADDRESS_type
    Length AS DWORD
    Flags  AS DWORD
END TYPE

UNION IP_ADAPTER_ADDRESS_union
    Alignment AS QUAD  ' ULONGLONG
    IP_ADAPTER_ADDRESS_type
END UNION

TYPE IP_ADAPTER_UNICAST_ADDRESS_LH
    IP_ADAPTER_ADDRESS_union
    pNext              AS IP_ADAPTER_UNICAST_ADDRESS_LH PTR
    Address            AS SOCKET_ADDRESS

    PrefixOrigin       AS IP_PREFIX_ORIGIN_enum
    SuffixOrigin       AS IP_SUFFIX_ORIGIN_enum
    DadState           AS IP_DAD_STATE_enum

    ValidLifetime      AS DWORD
    PreferredLifetime  AS DWORD
    LeaseLifetime      AS DWORD
    OnLinkPrefixLength AS BYTE
END TYPE

TYPE IP_ADAPTER_UNICAST_ADDRESS_XP
    IP_ADAPTER_ADDRESS_union
    pNext              AS IP_ADAPTER_UNICAST_ADDRESS_XP PTR
    Address            AS SOCKET_ADDRESS

    PrefixOrigin       AS IP_PREFIX_ORIGIN_enum
    SuffixOrigin       AS IP_SUFFIX_ORIGIN_enum
    DadState           AS IP_DAD_STATE_enum

    ValidLifetime      AS DWORD
    PreferredLifetime  AS DWORD
    LeaseLifetime      AS DWORD
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
TYPE IP_ADAPTER_UNICAST_ADDRESS
    IP_ADAPTER_UNICAST_ADDRESS_LH
END TYPE
#ELSEIF (%NTDDI_VERSION >= %NTDDI_WINXP)
TYPE IP_ADAPTER_UNICAST_ADDRESS
    IP_ADAPTER_UNICAST_ADDRESS_XP
END TYPE
#ENDIF

'
' Bit values of IP_ADAPTER_UNICAST_ADDRESS Flags field.
'
%IP_ADAPTER_ADDRESS_DNS_ELIGIBLE = &H01
%IP_ADAPTER_ADDRESS_TRANSIENT    = &H02

TYPE IP_ADAPTER_ANYCAST_ADDRESS_XP
    IP_ADAPTER_ADDRESS_union
    pNext   AS IP_ADAPTER_ANYCAST_ADDRESS_XP PTR
    Address AS SOCKET_ADDRESS
END TYPE
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
TYPE IP_ADAPTER_ANYCAST_ADDRESS
    IP_ADAPTER_ANYCAST_ADDRESS_XP
END TYPE
#ENDIF

TYPE IP_ADAPTER_MULTICAST_ADDRESS_XP
    IP_ADAPTER_ADDRESS_union
    pNext   AS IP_ADAPTER_MULTICAST_ADDRESS_XP PTR
    Address AS SOCKET_ADDRESS
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
TYPE IP_ADAPTER_MULTICAST_ADDRESS
    IP_ADAPTER_MULTICAST_ADDRESS_XP
END TYPE
#ENDIF

TYPE IP_ADAPTER_ADDRESS_type2
    Length   AS DWORD
    Reserved AS DWORD
END TYPE

UNION IP_ADAPTER_ADDRESS_union2
    Alignment AS QUAD  ' ULONGLONG
    IP_ADAPTER_ADDRESS_type2
END UNION

TYPE IP_ADAPTER_DNS_SERVER_ADDRESS_XP
    IP_ADAPTER_ADDRESS_union2
    pNext   AS IP_ADAPTER_DNS_SERVER_ADDRESS_XP PTR
    Address AS SOCKET_ADDRESS
END TYPE
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
TYPE IP_ADAPTER_DNS_SERVER_ADDRESS
    IP_ADAPTER_DNS_SERVER_ADDRESS_XP
END TYPE
#ENDIF

TYPE IP_ADAPTER_WINS_SERVER_ADDRESS_LH
    IP_ADAPTER_ADDRESS_union2
    pNext   AS IP_ADAPTER_WINS_SERVER_ADDRESS_LH PTR
    Address AS SOCKET_ADDRESS
END TYPE
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
TYPE IP_ADAPTER_WINS_SERVER_ADDRESS
    IP_ADAPTER_WINS_SERVER_ADDRESS_LH
END TYPE
#ENDIF

TYPE IP_ADAPTER_GATEWAY_ADDRESS_LH
    IP_ADAPTER_ADDRESS_union2
    pNext   AS IP_ADAPTER_GATEWAY_ADDRESS_LH PTR
    Address AS SOCKET_ADDRESS
END TYPE
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
TYPE IP_ADAPTER_GATEWAY_ADDRESS
    IP_ADAPTER_GATEWAY_ADDRESS_LH
END TYPE
#ENDIF

TYPE IP_ADAPTER_PREFIX_XP
    IP_ADAPTER_ADDRESS_union
    pNext   AS IP_ADAPTER_PREFIX_XP PTR
    Address AS SOCKET_ADDRESS
    PrefixLength AS DWORD
END TYPE
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
TYPE IP_ADAPTER_PREFIX
    IP_ADAPTER_PREFIX_XP
END TYPE
#ENDIF

TYPE IP_ADAPTER_DNS_SUFFIX
    pNext   AS IP_ADAPTER_DNS_SUFFIX PTR
    sString AS WSTRING * %MAX_DNS_SUFFIX_STRING_LENGTH
END TYPE

'
' Bit values of IP_ADAPTER_ADDRESSES Flags field.
'
%IP_ADAPTER_DDNS_ENABLED               = &H00000001
%IP_ADAPTER_REGISTER_ADAPTER_SUFFIX    = &H00000002
%IP_ADAPTER_DHCP_ENABLED               = &H00000004
%IP_ADAPTER_RECEIVE_ONLY               = &H00000008
%IP_ADAPTER_NO_MULTICAST               = &H00000010
%IP_ADAPTER_IPV6_OTHER_STATEFUL_CONFIG = &H00000020
%IP_ADAPTER_NETBIOS_OVER_TCPIP_ENABLED = &H00000040
%IP_ADAPTER_IPV4_ENABLED               = &H00000080
%IP_ADAPTER_IPV6_ENABLED               = &H00000100
%IP_ADAPTER_IPV6_MANAGE_ADDRESS_CONFIG = &H00000200

TYPE IP_ADAPTER_ADDRESS_type3
    Length  AS DWORD
    IfIndex AS IF_INDEX
END TYPE

UNION IP_ADAPTER_ADDRESS_union3
    Alignment AS QUAD  ' ULONGLONG
    IP_ADAPTER_ADDRESS_type3
END UNION

TYPE IP_ADAPTER_ADDRESSES_LH_type
    DdnsEnabled             AS BIT * 1 IN DWORD
    RegisterAdapterSuffix   AS BIT * 1
    Dhcpv4Enabled           AS BIT * 1
    ReceiveOnly             AS BIT * 1
    NoMulticast             AS BIT * 1
    Ipv6OtherStatefulConfig AS BIT * 1
    NetbiosOverTcpipEnabled AS BIT * 1
    Ipv4Enabled             AS BIT * 1
    Ipv6Enabled             AS BIT * 1
    Ipv6ManagedAddressConfigurationSupported AS BIT * 1
END TYPE

UNION IP_ADAPTER_ADDRESSES_LH_union
    Flags AS DWORD
    IP_ADAPTER_ADDRESSES_LH_type
END UNION

TYPE IP_ADAPTER_ADDRESSES_LH
    IP_ADAPTER_ADDRESS_union3
    pNext                  AS IP_ADAPTER_ADDRESSES_LH PTR
    AdapterName            AS ASCIIZ PTR
    FirstUnicastAddress    AS IP_ADAPTER_UNICAST_ADDRESS_LH PTR
    FirstAnycastAddress    AS IP_ADAPTER_ANYCAST_ADDRESS_XP PTR
    FirstMulticastAddress  AS IP_ADAPTER_MULTICAST_ADDRESS_XP PTR
    FirstDnsServerAddress  AS IP_ADAPTER_DNS_SERVER_ADDRESS_XP PTR
    DnsSuffix              AS WSTRINGZ PTR
    Description            AS WSTRINGZ PTR
    FriendlyName           AS WSTRINGZ PTR
    PhysicalAddress(%MAX_ADAPTER_ADDRESS_LENGTH-1) AS BYTE
    PhysicalAddressLength  AS DWORD
    IP_ADAPTER_ADDRESSES_LH_union
    Mtu                    AS DWORD
    IfType                 AS IFTYPE
    OperStatus             AS IF_OPER_STATUS_enum
    Ipv6IfIndex            AS IF_INDEX
    ZoneIndices(15)        AS DWORD
    FirstPrefix            AS IP_ADAPTER_PREFIX_XP PTR

    TransmitLinkSpeed      AS QUAD  ' ULONG64
    ReceiveLinkSpeed       AS QUAD  ' ULONG64
    FirstWinsServerAddress AS IP_ADAPTER_WINS_SERVER_ADDRESS_LH PTR
    FirstGatewayAddress    AS IP_ADAPTER_GATEWAY_ADDRESS_LH PTR
    Ipv4Metric             AS DWORD
    Ipv6Metric             AS DWORD
    Luid                   AS IF_LUID
    Dhcpv4Server           AS SOCKET_ADDRESS
    CompartmentId          AS NET_IF_COMPARTMENT_ID
    NetworkGuid            AS NET_IF_NETWORK_GUID
    ConnectionType         AS NET_IF_CONNECTION_TYPE_enum
    TunnelType             AS TUNNEL_TYPE_enum
    '
    ' DHCP v6 Info.
    '
    Dhcpv6Server           AS SOCKET_ADDRESS
    Dhcpv6ClientDuid(%MAX_DHCPV6_DUID_LENGTH-1) AS BYTE
    Dhcpv6ClientDuidLength AS DWORD
    Dhcpv6Iaid             AS DWORD
#IF (%NTDDI_VERSION >= %NTDDI_VISTASP1)
    FirstDnsSuffix AS IP_ADAPTER_DNS_SUFFIX PTR
#ENDIF
END TYPE

TYPE IP_ADAPTER_ADDRESSES_XP
    IP_ADAPTER_ADDRESS_union3
    pNext                 AS IP_ADAPTER_ADDRESSES_XP PTR
    AdapterName           AS ASCIIZ PTR
    FirstUnicastAddress   AS IP_ADAPTER_UNICAST_ADDRESS_XP PTR
    FirstAnycastAddress   AS IP_ADAPTER_ANYCAST_ADDRESS_XP PTR
    FirstMulticastAddress AS IP_ADAPTER_MULTICAST_ADDRESS_XP PTR
    FirstDnsServerAddress AS IP_ADAPTER_DNS_SERVER_ADDRESS_XP PTR
    DnsSuffix             AS WSTRINGZ PTR
    Description           AS WSTRINGZ PTR
    FriendlyName          AS WSTRINGZ PTR
    PhysicalAddress(%MAX_ADAPTER_ADDRESS_LENGTH-1) AS BYTE
    PhysicalAddressLength AS DWORD
    Flags                 AS DWORD
    Mtu                   AS DWORD
    IfType                AS DWORD
    OperStatus            AS IF_OPER_STATUS_enum
    Ipv6IfIndex           AS DWORD
    ZoneIndices(15)       AS DWORD
    FirstPrefix           AS IP_ADAPTER_PREFIX_XP PTR
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
TYPE IP_ADAPTER_ADDRESSES
    IP_ADAPTER_ADDRESSES_LH
END TYPE
#ELSEIF (%NTDDI_VERSION >= %NTDDI_WINXP)
TYPE IP_ADAPTER_ADDRESSES
    IP_ADAPTER_ADDRESSES_XP
END TYPE
#ELSE
'
' For platforms other platforms that are including
' the file but not using the types.
'
TYPE IP_ADAPTER_ADDRESSES
    IP_ADAPTER_ADDRESSES_XP
END TYPE
#ENDIF


'
' Flags used as argument to GetAdaptersAddresses().
' "SKIP" flags are added when the default is to include the information.
' "INCLUDE" flags are added when the default is to skip the information.
'
%GAA_FLAG_SKIP_UNICAST                = &H0001
%GAA_FLAG_SKIP_ANYCAST                = &H0002
%GAA_FLAG_SKIP_MULTICAST              = &H0004
%GAA_FLAG_SKIP_DNS_SERVER             = &H0008
%GAA_FLAG_INCLUDE_PREFIX              = &H0010
%GAA_FLAG_SKIP_FRIENDLY_NAME          = &H0020
%GAA_FLAG_INCLUDE_WINS_INFO           = &H0040
%GAA_FLAG_INCLUDE_GATEWAYS            = &H0080
%GAA_FLAG_INCLUDE_ALL_INTERFACES      = &H0100
%GAA_FLAG_INCLUDE_ALL_COMPARTMENTS    = &H0200
%GAA_FLAG_INCLUDE_TUNNEL_BINDINGORDER = &H0400

#ENDIF ' %WINSOCK2API

'
' IP_PER_ADAPTER_INFO - per-adapter IP information such as DNS server list.
'

TYPE IP_PER_ADAPTER_INFO_W2KSP1
    AutoconfigEnabled AS DWORD
    AutoconfigActive  AS DWORD
    CurrentDnsServer  AS IP_ADDR_STRING PTR
    DnsServerList     AS IP_ADDR_STRING
END TYPE
#IF (%NTDDI_VERSION >= %NTDDI_WIN2KSP1)
TYPE IP_PER_ADAPTER_INFO
    IP_PER_ADAPTER_INFO_W2KSP1
END TYPE
#ENDIF


'
' FIXED_INFO - the set of IP-related information which does not depend on DHCP
'

TYPE FIXED_INFO_W2KSP1
    HostName         AS ASCIIZ * %MAX_HOSTNAME_LEN + 4
    DomainName       AS ASCIIZ * %MAX_DOMAIN_NAME_LEN + 4
    CurrentDnsServer AS IP_ADDR_STRING PTR
    DnsServerList    AS IP_ADDR_STRING
    NodeType         AS DWORD
    ScopeId          AS ASCIIZ * %MAX_SCOPE_ID_LEN + 4
    EnableRouting    AS DWORD
    EnableProxy      AS DWORD
    EnableDns        AS DWORD
END TYPE
#IF (%NTDDI_VERSION >= %NTDDI_WIN2KSP1)
TYPE FIXED_INFO
    FIXED_INFO_W2KSP1
END TYPE
#ENDIF


#IF NOT %DEF(%IP_INTERFACE_NAME_INFO_DEFINED)
%IP_INTERFACE_NAME_INFO_DEFINED = 1

TYPE IP_INTERFACE_NAME_INFO_W2KSP1
    Index          AS DWORD   ' Interface Index
    MediaType      AS DWORD   ' Interface Types - see ipifcons.h
    ConnectionType AS BYTE
    AccessType     AS BYTE
    DeviceGuid     AS GUID    ' Device GUID is the guid of the device
                              ' that IP exposes
    InterfaceGuid  AS GUID    ' Interface GUID, if not GUID_NULL is the
                              ' GUID for the interface mapped to the device.
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_WIN2KSP1)
TYPE IP_INTERFACE_NAME_INFO
    IP_INTERFACE_NAME_INFO_W2KSP1
END TYPE
#ENDIF

#ENDIF
