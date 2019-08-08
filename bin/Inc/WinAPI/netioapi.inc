'------------------------------------------------------------------------------
'
'  NetIoApi.inc -- definitions for version-agnostic IP helper APIs.
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from NetIoApi.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%NETIOAPI_H = 1

#INCLUDE "ntddndis.inc"


'
' General types.
'

'
' Nameless structure/union.
'

#IF NOT %DEF(%ANY_SIZE)
%ANY_SIZE = 1
#ENDIF

#IF %DEF(%IPHLPAPI_H)

'
' User Mode.  This file should be included from iphlpapi.h
' User should include ws2ipdef.h to use these APIs.
'

MACRO NETIO_STATUS=DWORD
MACRO NETIO_SUCCESS(x)=ABS((x)=%NO_ERROR)

#ELSE

'
' Kernel Mode.
'

#INCLUDE "ws2def.inc"
#INCLUDE "ws2ipdef.inc"
#INCLUDE "ifdef.inc"
#INCLUDE "nldef.inc"

MACRO NETIO_STATUS=NTSTATUS
MACRO NETIO_SUCCESS(x)=NT_SUCCESS(x)

#ENDIF


MACRO MIB_NOTIFICATION_TYPE_enum=LONG
ENUM MIB_NOTIFICATION_TYPE SINGULAR
    '
    ' ParameterChange.
    '
    MibParameterNotification
    '
    ' Addition.
    '
    MibAddInstance
    '
    ' Deletion.
    '
    MibDeleteInstance
    '
    ' Initial notification
    '
    MibInitialNotification
END ENUM

'
' Interface management routines.
'

'
' The MIB structure for Interface management routines.
'

#IF %DEF(%WS2IPDEF)

TYPE MIB_IF_ROW2_type
    HardwareInterface AS BIT * 1 IN BYTE  ' BOOLEAN
    FilterInterface   AS BIT * 1          ' BOOLEAN
    ConnectorPresent  AS BIT * 1          ' BOOLEAN
    NotAuthenticated  AS BIT * 1          ' BOOLEAN
    NotMediaConnected AS BIT * 1          ' BOOLEAN
    Paused            AS BIT * 1          ' BOOLEAN
    LowPower          AS BIT * 1          ' BOOLEAN
    EndPointInterface AS BIT * 1          ' BOOLEAN
END TYPE

TYPE MIB_IF_ROW2
    '
    ' Key structure.  Sorted by preference.
    '
    InterfaceLuid            AS NET_LUID
    InterfaceIndex           AS NET_IFINDEX

    '
    ' Read-Only fields.
    '
    InterfaceGuid            AS GUID
    ALIAS                    AS WSTRINGZ * %IF_MAX_STRING_SIZE + 1
    Description              AS WSTRINGZ * %IF_MAX_STRING_SIZE + 1
    PhysicalAddressLength    AS DWORD
    PhysicalAddress          AS STRING * %IF_MAX_PHYS_ADDRESS_LENGTH
    PermanentPhysicalAddress AS STRING * %IF_MAX_PHYS_ADDRESS_LENGTH

    Mtu                AS DWORD
    TYPE               AS IFTYPE           ' Interface Type.
    TunnelType         AS TUNNEL_TYPE_enum ' Tunnel Type, if Type = IF_TUNNEL.
    MediaType          AS NDIS_MEDIUM_enum
    PhysicalMediumType AS NDIS_PHYSICAL_MEDIUM_enum
    AccessType         AS NET_IF_ACCESS_TYPE_enum
    DirectionType      AS NET_IF_DIRECTION_TYPE_enum
    InterfaceAndOperStatusFlags AS MIB_IF_ROW2_type

    OperStatus         AS IF_OPER_STATUS_enum
    AdminStatus        AS NET_IF_ADMIN_STATUS_enum
    MediaConnectState  AS NET_IF_MEDIA_CONNECT_STATE_enum
    NetworkGuid        AS NET_IF_NETWORK_GUID
    ConnectionType     AS NET_IF_CONNECTION_TYPE_enum

    '
    ' Statistics.
    '
    TransmitLinkSpeed  AS QUAD  ' ULONG64
    ReceiveLinkSpeed   AS QUAD  ' ULONG64

    InOctets           AS QUAD  ' ULONG64
    InUcastPkts        AS QUAD  ' ULONG64
    InNUcastPkts       AS QUAD  ' ULONG64
    InDiscards         AS QUAD  ' ULONG64
    InErrors           AS QUAD  ' ULONG64
    InUnknownProtos    AS QUAD  ' ULONG64
    InUcastOctets      AS QUAD  ' ULONG64
    InMulticastOctets  AS QUAD  ' ULONG64
    InBroadcastOctets  AS QUAD  ' ULONG64
    OutOctets          AS QUAD  ' ULONG64
    OutUcastPkts       AS QUAD  ' ULONG64
    OutNUcastPkts      AS QUAD  ' ULONG64
    OutDiscards        AS QUAD  ' ULONG64
    OutErrors          AS QUAD  ' ULONG64
    OutUcastOctets     AS QUAD  ' ULONG64
    OutMulticastOctets AS QUAD  ' ULONG64
    OutBroadcastOctets AS QUAD  ' ULONG64
    OutQLen            AS QUAD  ' ULONG64
END TYPE   ' MIB_IF_ROW2

TYPE MIB_IF_TABLE2
    NumEntries         AS DWORD
    Table(%ANY_SIZE-1) AS MIB_IF_ROW2
END TYPE

DECLARE FUNCTION GetIfEntry2 LIB "IpHlpApi.dll" ALIAS "GetIfEntry2" _
    (Row AS MIB_IF_ROW2) AS LONG

'++
'
'Routine Description:
'
'    Retrieves information for the specified interface on the local computer.
'
'Arguments:
'
'    Row - Supplies a MIB_IF_ROW2 structure with either the Luid or Index
'        initialized to that of the interface for which to retrieve
'        information.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    On input, the following key fields of Row must be initialized:
'    1.  At least one of InterfaceLuid or InterfaceIndex must be specified.
'
'    On output, the remaining fields of Row are filled in.
'
'--

DECLARE FUNCTION GetIfTable2 LIB "IpHlpApi.dll" ALIAS "GetIfTable2" _
    (ppTable AS ANY) _  ' MIB_IF_TABLE2 PTR PTR
    AS LONG

'++
'
'Routine Description:
'
'    Retrieves the MIB-II interface table.
'
'Arguments:
'
'    Table - Returns the table of interfaces in a MIB_IFTABLE2 structure.
'        Use FreeMibTable to free this buffer.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    The API allocates the buffer for Table.  Use FreeMibTable to free it.
'
'--

MACRO MIB_IF_TABLE_LEVEL_enum=LONG
ENUM MIB_IF_TABLE_LEVEL SINGULAR
    MibIfTableNormal
    MibIfTableRaw
END ENUM

DECLARE FUNCTION GetIfTable2Ex LIB "IpHlpApi.dll" ALIAS "GetIfTable2Ex" ( _
    BYVAL Level AS MIB_IF_TABLE_LEVEL_enum, _
    pTable      AS ANY _    ' MIB_IF_TABLE2 PTR PTR
    ) AS LONG

'++
'
'Routine Description:
'
'    Retrieves the MIB-II interface table.
'
'Arguments:
'
'    Table - Returns the table of interfaces in a MIB_IFTABLE2 structure.
'        Use FreeMibTable to free this buffer.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    The API allocates the buffer for Table.  Use FreeMibTable to free it.
'
'--

'
' IpInterface management routines.
'

'
' The MIB structure for Network layer Interface management routines.
'
TYPE MIB_IPINTERFACE_ROW
    '
    ' Key Structure;
    '
    Family         AS ADDRESS_FAMILY
    InterfaceLuid  AS NET_LUID
    InterfaceIndex AS NET_IFINDEX

    '
    ' Read-Write fields.
    '

    '
    ' Fields currently not exposed.
    '
    MaxReassemblySize              AS DWORD
    InterfaceIdentifier            AS QUAD  ' ULONG64
    MinRouterAdvertisementInterval AS DWORD
    MaxRouterAdvertisementInterval AS DWORD

    '
    ' Fileds currently exposed.
    '
    AdvertisingEnabled                   AS BYTE  ' BOOLEAN
    ForwardingEnabled                    AS BYTE  ' BOOLEAN
    WeakHostSend                         AS BYTE  ' BOOLEAN
    WeakHostReceive                      AS BYTE  ' BOOLEAN
    UseAutomaticMetric                   AS BYTE  ' BOOLEAN
    UseNeighborUnreachabilityDetection   AS BYTE  ' BOOLEAN
    ManagedAddressConfigurationSupported AS BYTE  ' BOOLEAN
    OtherStatefulConfigurationSupported  AS BYTE  ' BOOLEAN
    AdvertiseDefaultRoute                AS BYTE  ' BOOLEAN

    RouterDiscoveryBehavior AS NL_ROUTER_DISCOVERY_BEHAVIOR_enum
    DadTransmits            AS DWORD  ' DupAddrDetectTransmits in RFC 2462.
    BaseReachableTime       AS DWORD
    RetransmitTime          AS DWORD
    PathMtuDiscoveryTimeout AS DWORD  ' Path MTU discovery timeout (in ms).

    LinkLocalAddressBehavior        AS NL_LINK_LOCAL_ADDRESS_BEHAVIOR_enum
    LinkLocalAddressTimeout         AS DWORD  ' In ms.
    ZoneIndices(%ScopeLevelCount-1) AS DWORD  ' Zone part of a SCOPE_ID.
    SitePrefixLength                AS DWORD
    Metric                          AS DWORD
    NlMtu                           AS DWORD

    '
    ' Read Only fields.
    '
    Connected                 AS BYTE  ' BOOLEAN
    SupportsWakeUpPatterns    AS BYTE  ' BOOLEAN
    SupportsNeighborDiscovery AS BYTE  ' BOOLEAN
    SupportsRouterDiscovery   AS BYTE  ' BOOLEAN

    ReachableTime             AS DWORD

    TransmitOffload           AS NL_INTERFACE_OFFLOAD_ROD
    ReceiveOffload            AS NL_INTERFACE_OFFLOAD_ROD

    '
    ' Disables using default route on the interface. This flag
    ' can be used by VPN clients to restrict Split tunnelling.
    '
    DisableDefaultRoutes      AS BYTE  ' BOOLEAN
END TYPE  ' MIB_IPINTERFACE_ROW

TYPE MIB_IPINTERFACE_TABLE
    NumEntries         AS DWORD
    Table(%ANY_SIZE-1) AS MIB_IPINTERFACE_ROW
END TYPE

TYPE MIB_IFSTACK_ROW
    HigherLayerInterfaceIndex AS NET_IFINDEX
    LowerLayerInterfaceIndex  AS NET_IFINDEX
END TYPE

TYPE MIB_INVERTEDIFSTACK_ROW
    LowerLayerInterfaceIndex  AS NET_IFINDEX
    HigherLayerInterfaceIndex AS NET_IFINDEX
END TYPE

TYPE MIB_IFSTACK_TABLE
    NumEntries         AS DWORD
    Table(%ANY_SIZE-1) AS MIB_IFSTACK_ROW
END TYPE

TYPE MIB_INVERTEDIFSTACK_TABLE
    NumEntries         AS DWORD
    Table(%ANY_SIZE-1) AS MIB_INVERTEDIFSTACK_ROW
END TYPE

DECLARE SUB PIPINTERFACE_CHANGE_CALLBACK ( _
    CallerContex           AS DWORD, _
    Row                    AS MIB_IPINTERFACE_ROW, _
    BYVAL NotificationType AS MIB_NOTIFICATION_TYPE_enum)

DECLARE FUNCTION GetIfStackTable LIB "IpHlpApi.dll" ALIAS "GetIfStackTable" ( _
    pTable AS ANY) _   ' MIB_IFSTACK_TABLE PTR PTR
    AS LONG

DECLARE FUNCTION GetInvertedIfStackTable LIB "IpHlpApi.dll" _
    ALIAS "GetInvertedIfStackTable" ( _
    pTable AS ANY) _   ' MIB_INVERTEDIFSTACK_TABLE PTR PTR
    AS LONG

DECLARE FUNCTION GetIpInterfaceEntry LIB "IpHlpApi.dll" _
    ALIAS "GetIpInterfaceEntry" ( _
    pRow AS MIB_IPINTERFACE_ROW) _
    AS LONG
'++
'
'Routine Description:
'
'    Retrieves IP information for the specified interface on the local computer.
'
'Arguments:
'
'    Row - Supplies a MIB_IPINTERFACE_ROW structure with either the Luid or
'        Index initialized to that of the interface for which to retrieve
'        information.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    On input, the following key fields of Row must be initialized:
'    1. Family: it must be either AF_INET or AF_INET6
'    2. At least one of InterfaceLuid or InterfaceIndex must be specified.
'
'    On output, the remaining fields of Row are filled in.
'
'--

DECLARE FUNCTION GetIpInterfaceTable LIB "IpHlpApi.dll" _
    ALIAS "GetIpInterfaceTable" ( _
    BYVAL Family AS ADDRESS_FAMILY, _
    pTable AS ANY) _   ' MIB_IPINTERFACE_TABLE PTR PTR
    AS LONG

'++
'
'Routine Description:
'
'    Retrieves the network-layer interface table.
'
'Arguments:
'
'    Family - Supplies the address family.
'
'        AF_INET: Only returns IPv4 MIB entries.
'
'        AF_INET6: Only returns IPv6 MIB entries.
'
'        AF_UNSPEC: Returns both IPv4 and IPv6 MIB entries.
'
'    Table - Returns the table of interfaces in a MIB_IPINTERFACE_TABLE
'        structure.  Use FreeMibTable to free this buffer.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    The API allocates the buffer for Table.  Use FreeMibTable to free it.
'
'--

DECLARE SUB InitializeIpInterfaceEntry LIB "IpHlpApi.dll" _
    ALIAS "InitializeIpInterfaceEntry" ( _
    pRow AS ANY)    ' MIB_IPINTERFACE_ROW PTR PTR
'++
'
'Routine Description:
'
'    Initialize the MIB_IPINTERFACE_ROW entry for use in SetIpInterfaceRow.
'
'Arguments:
'
'    Row - Returns an initialized MIB_IPINTERFACE_ROW structure.
'
'Return Value:
'
'    None.
'
'Notes:
'
'    InitializeIpInterfaceEntry must be used to initialize the fields of
'    MIB_IPINTERFACE_ROW with default values.  The caller can then update the
'    fields it wishes to modify and invoke SetIpInterfaceEntry.
'
'--

DECLARE FUNCTION NotifyIpInterfaceChange LIB "IpHlpApi.dll" _
    ALIAS "NotifyIpInterfaceChange" ( _
    BYVAL Family              AS ADDRESS_FAMILY, _
    BYVAL CALLBACK            AS DWORD, _    ' PIPINTERFACE_CHANGE_CALLBACK
    CallerContext             AS DWORD, _    ' PVOID
    BYVAL InitialNotification AS BYTE, _     ' BOOLEAN
    pNotificationHandle       AS DWORD _     ' HANDLE
    ) AS LONG
'++
'
'Routine Description:
'
'    Register for notification for IP interface changes.
'
'Arguments:
'
'    Family - Supplies the address family.
'
'        AF_INET: Only register for IPv4 change notifications.
'
'        AF_INET6: Only register for IPv6 change notifications.
'
'        AF_UNSPEC: Register for both IPv4 and IPv6 change notifications.
'
'    Callback - Supplies a callback function.  This function will be invoked
'        when an interface notification is received.
'
'    CallerContext - Provides the user specific caller context.  This context
'        will be supplied to the callback function.
'
'    InitialNotification - Supplies a boolean to indicate whether an
'        initialization notification should be provided.
'
'    NotificationHandle - Returns a handle to the notification registration.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    1. Invokation of the callback function is serialized.
'
'    2. Use CancelMibChangeNotify2 to deregister for change notifications.
'
'--

DECLARE FUNCTION SetIpInterfaceEntry LIB "IpHlpApi.dll" _
    ALIAS "SetIpInterfaceEntry" ( _
    BYVAL pRow AS MIB_IPINTERFACE_ROW PTR _
    ) AS LONG

'++
'
'Routine Description:
'
'    Set the properties of an IP interface.
'
'Arguments:
'
'    Row - Supplies a MIB_IPINTERFACE_ROW structure.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    InitializeIpInterfaceEntry must be used to initialize the fields of
'    MIB_IPINTERFACE_ROW with default values.  The caller can then update the
'    fields it wishes to modify and invoke SetIpInterfaceEntry.
'
'    On input, the following key fields of Row must be initialized after
'    invoking InitializeIpInterfaceEntry:
'    1. Family: To AF_INET or AF_INET6.
'    2. At least one of InterfaceLuid or InterfaceIndex must be specified.
'
'--


'
' Unicast address management routines.
'

'
' The structure for unicast IP Address management.
'
TYPE MIB_UNICASTIPADDRESS_ROW
    '
    ' Key Structure.
    '
    Address            AS SOCKADDR_INET
    InterfaceLuid      AS NET_LUID
    InterfaceIndex     AS NET_IFINDEX

    '
    ' Read-Write Fileds.
    '
    PrefixOrigin       AS NL_PREFIX_ORIGIN_enum
    SuffixOrigin       AS NL_SUFFIX_ORIGIN_enum
    ValidLifetime      AS DWORD
    PreferredLifetime  AS DWORD
    OnLinkPrefixLength AS BYTE
    SkipAsSource       AS BYTE  ' BOOLEAN

    '
    ' Read-Only Fields.
    '
    DadState           AS NL_DAD_STATE_enum
    ScopeId            AS SCOPE_ID
    CreationTimeStamp  AS QUAD  ' LARGE_INTEGER
END TYPE  ' MIB_UNICASTIPADDRESS_ROW

TYPE MIB_UNICASTIPADDRESS_TABLE
    NumEntries         AS DWORD
    Table(%ANY_SIZE-1) AS MIB_UNICASTIPADDRESS_ROW
END TYPE

DECLARE SUB PUNICAST_IPADDRESS_CHANGE_CALLBACK ( _
    CallerContext          AS DWORD, _  ' PVOID
    BYVAL Row              AS MIB_UNICASTIPADDRESS_ROW PTR, _
    BYVAL NotificationType AS MIB_NOTIFICATION_TYPE_enum _
    )

DECLARE FUNCTION CreateUnicastIpAddressEntry LIB "IpHlpApi.dll" _
    ALIAS "CreateUnicastIpAddressEntry" ( _
    BYVAL Row AS MIB_UNICASTIPADDRESS_ROW PTR _
    ) AS LONG

'++
'
'Routine Description:
'
'    Create a unicast IP address entry on the local computer.
'
'Arguments:
'
'    Row - Supplies a MIB_UNICASTIPADDRESS_ROW structure.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    InitializeUnicastIpAddressEntry must be used to initialize the fields of
'    MIB_UNICASTIPADDRESS_ROW with default values.  The caller can then update
'    the fields it wishes to modify and invoke CreateIpInterfaceEntry.
'
'    On input, the following key fields of Row must be initialized after
'    invoking InitializeUnicastIpAddressEntry:
'    1. Address to a valid IPv4 or IPv6 unicast address.
'    2. At least one of InterfaceLuid or InterfaceIndex must be specified.
'
'--

DECLARE FUNCTION DeleteUnicastIpAddressEntry LIB "IpHlpApi.dll" _
    ALIAS "DeleteUnicastIpAddressEntry" ( _
    BYVAL Row AS MIB_UNICASTIPADDRESS_ROW PTR _
    ) AS LONG
'++
'
'Routine Description:
'
'    Delete a unicast IP address entry on the local computer.
'
'Arguments:
'
'    Row - Supplies a MIB_UNICASTIPADDRESS_ROW structure.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    On input, the following key fields of Row must be initialized:
'    1. Address to a valid IPv4 or IPv6 unicast address.
'    2. At least one of InterfaceLuid or InterfaceIndex must be specified.
'
'--

DECLARE FUNCTION GetUnicastIpAddressEntry LIB "IpHlpApi.dll" _
    ALIAS "GetUnicastIpAddressEntry" ( _
    BYVAL Row AS MIB_UNICASTIPADDRESS_ROW PTR _
    ) AS LONG
'++
'
'Routine Description:
'
'    Retrieves information for the specified unicast IP address entry on the
'        local computer.
'
'Arguments:
'
'    Address - Supplies a MIB_UNICASTIPADDRESS_ROW structure.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    On input, the following key fields of Row must be initialized:
'    1. Address to a valid IPv4 or IPv6 unicast address.
'    2. At least one of InterfaceLuid or InterfaceIndex must be specified.
'
'    On output, the remaining fields of Row are filled in.
'
'--

DECLARE FUNCTION GetUnicastIpAddressTable LIB "IpHlpApi.dll" _
    ALIAS "GetUnicastIpAddressTable" ( _
    BYVAL Family AS ADDRESS_FAMILY, _
    BYVAL Table  AS DWORD _  ' MIB_UNICASTIPADDRESS_TABLE PTR PTR
    ) AS LONG
'++
'
'Routine Description:
'
'    Retrieves the unicast IP address table on a local computer.
'
'Arguments:
'
'    Family - Supplies the address family.
'
'        AF_INET: Only returns IPv4 unicast addresses.
'
'        AF_INET6: Only returns IPv6 unicast addresses.
'
'        AF_UNSPEC: Returns both IPv4 and IPv6 unicast addresses.
'
'    Table - Returns the table of unicast IP addresses in a
'        MIB_UNICASTIPADDRESS_TABLE Structure.  Use FreeMibTable to free this
'        buffer.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    The API allocates the buffer for Table.  Use FreeMibTable to free it.
'
'--

DECLARE SUB InitializeUnicastIpAddressEntry LIB "IpHlpApi.dll" _
    ALIAS "InitializeUnicastIpAddressEntry" ( _
    BYVAL Row AS MIB_UNICASTIPADDRESS_ROW PTR _
    )
'++
'
'Routine Description:
'
'    Initialize the MIB_UNICASTIPADDRESS_ROW entry for use in
'    CreateUnicastIpAddressEntry and SetUnicastIpAddressEntry.
'
'Arguments:
'
'    Address - Returns an initialized MIB_UNICASTIPADDRESS_ROW structure.
'
'Return Value:
'
'    None.
'
'Notes:
'
'    InitializeUnicastIpAddressEntry must be used to initialize the fields of
'    MIB_UNICASTIPADDRESS_ROW with default values.  The caller can then update
'    the fields it wishes to modify and invoke CreateUnicastIpAddressEntry or
'    SetUnicastIpAddressEntry.
'
'--


DECLARE FUNCTION NotifyUnicastIpAddressChange LIB "IpHlpApi.dll" _
    ALIAS "NotifyUnicastIpAddressChange" ( _
    BYVAL Family              AS ADDRESS_FAMILY, _
    BYVAL pCallback           AS DWORD, _  ' PUNICAST_IPADDRESS_CHANGE_CALLBACK
    BYVAL CallerContext       AS DWORD, _  ' PVOID
    BYVAL InitialNotification AS BYTE, _   ' BOOLEAN
    NotificationHandle        AS DWORD _   ' HANDLE
    ) AS LONG
'++
'
'Routine Description:
'
'    Register for notification for unicast IP address changes.
'
'Arguments:
'
'    Family - Supplies the address family.
'
'        AF_INET: Only register for IPv4 change notifications.
'
'        AF_INET6: Only register for IPv6 change notifications.
'
'        AF_UNSPEC: Register for both IPv4 and IPv6 change notifications.
'
'    Callback - Supplies a callback function.  This function will be invoked
'        when an unicast IP address notification is received.
'
'    CallerContext - Provides the user specific caller context.  This context
'        will be supplied to the callback function.
'
'    InitialNotification - Supplies a boolean to indicate whether an
'        initialization notification should be provided.
'
'    NotificationHandle - Returns a handle to the notification registration.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    1. Invokation of the callback function is serialized.
'
'    2. Use CancelMibChangeNotify2 to deregister for change notifications.
'
'--

DECLARE FUNCTION PSTABLE_UNICAST_IPADDRESS_TABLE_CALLBACK ( _
    BYVAL CallerContext AS DWORD, _  ' PVOID
    BYVAL AddressTable  AS MIB_UNICASTIPADDRESS_TABLE PTR _
    ) AS LONG

DECLARE FUNCTION NotifyStableUnicastIpAddressTable LIB "IpHlpApi.dll" _
    ALIAS "NotifyStableUnicastIpAddressTable" ( _
    BYVAL Family         AS ADDRESS_FAMILY, _
    Table                AS ANY, _   ' PMIB_UNICASTIPADDRESS_TABLE*
    BYVAL CallerCallback AS DWORD, _ ' PSTABLE_UNICAST_IPADDRESS_TABLE_CALLBACK
    CallerContext        AS ANY, _   ' PVOID
    NotificationHandle   AS DWORD _  ' HANDLE *
    ) AS LONG

DECLARE FUNCTION SetUnicastIpAddressEntry LIB "IpHlpApi.dll" _
    ALIAS "SetUnicastIpAddressEntry" ( _
    BYVAL Row AS MIB_UNICASTIPADDRESS_ROW PTR _
    ) AS LONG

'++
'
'Routine Description:
'
'    Set the properties of an unicast IP address.
'
'Arguments:
'
'    Address - Supplies a MIB_UNICASTIPADDRESS_ROW structure.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    InitializeUnicastIpAddressEntry must be used to initialize the fields of
'    MIB_UNICASTIPADDRESS_ROW with default values.  The caller can then update
'    the fields it wishes to modify and invoke SetUnicastIpAddressEntry.
'
'    On input, the following key fields of Row must be initialized after
'    invoking InitializeUnicastIpAddressEntry:
'    1. Address to a valid IPv4 or IPv6 unicast address.
'    2. At least one of InterfaceLuid or InterfaceIndex must be specified.
'
'--

'
' Anycast address management routines.
'

TYPE MIB_ANYCASTIPADDRESS_ROW
    '
    ' Key Structure.
    '
    Address        AS SOCKADDR_INET
    InterfaceLuid  AS NET_LUID
    InterfaceIndex AS NET_IFINDEX

    '
    ' Read-Only Fields.
    '
    ScopeId        AS SCOPE_ID
END TYPE

TYPE MIB_ANYCASTIPADDRESS_TABLE
    NumEntries         AS DWORD
    Table(%ANY_SIZE-1) AS MIB_ANYCASTIPADDRESS_ROW
END TYPE

DECLARE FUNCTION CreateAnycastIpAddressEntry LIB "IpHlpApi.dll" _
    ALIAS "CreateAnycastIpAddressEntry" ( _
    BYVAL Row AS MIB_ANYCASTIPADDRESS_ROW PTR _
    ) AS LONG

'++
'
'Routine Description:
'
'    Create an anycast IP address entry on the local computer.
'
'Arguments:
'
'    Address - Supplies a MIB_ANYCASTIPADDRESS_ROW structure.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    On input, the following key fields of Row must be initialized:
'    1. Address to a valid IPv4 or IPv6 anycast address.
'    2. At least one of InterfaceLuid or InterfaceIndex must be specified.
'
'--

DECLARE FUNCTION DeleteAnycastIpAddressEntry LIB "IpHlpApi.dll" _
    ALIAS "DeleteAnycastIpAddressEntry" ( _
    BYVAL Row AS MIB_ANYCASTIPADDRESS_ROW PTR _
    ) AS LONG

'++
'
'Routine Description:
'
'    Delete an anycast IP address entry on the local computer.
'
'Arguments:
'
'    Address - Supplies a MIB_ANYCASTIPADDRESS_ROW structure.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    On input, the following key fields of Row must be initialized:
'    1. Address to a valid IPv4 or IPv6 anycast address.
'    2. At least one of InterfaceLuid or InterfaceIndex must be specified.
'
'--

DECLARE FUNCTION GetAnycastIpAddressEntry LIB "IpHlpApi.dll" _
    ALIAS "GetAnycastIpAddressEntry" ( _
    BYVAL Row AS MIB_ANYCASTIPADDRESS_ROW PTR _
    ) AS LONG

'++
'
'Routine Description:
'
'    Retrieves information for the specified anycast IP address entry on the
'    local computer.
'
'Arguments:
'
'    Address - Supplies a MIB_ANYCASTIPADDRESS_ROW structure.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    On input, the following key fields of Row must be initialized:
'    1. Address to a valid IPv4 or IPv6 anycast address.
'    2. At least one of InterfaceLuid or InterfaceIndex must be specified.
'
'    On output, the remaining fields of Row are filled in.
'
'--

DECLARE FUNCTION GetAnycastIpAddressTable LIB "IpHlpApi.dll" _
    ALIAS "GetAnycastIpAddressTable" ( _
    BYVAL Family AS ADDRESS_FAMILY, _
    Table        AS ANY _  ' PMIB_ANYCASTIPADDRESS_TABLE *
    ) AS LONG

'++
'
'Routine Description:
'
'    Retrieves the anycast IP address table.
'
'Arguments:
'
'    Family - Supplies the address family.
'
'        AF_INET: Only returns IPv4 anycast addresses.
'
'        AF_INET6: Only returns IPv6 anycast addresses.
'
'        AF_UNSPEC: Returns both IPv4 and IPv6 anycast addresses.
'
'    Table - Returns the table of anycast IP addresses in a
'        MIB_ANYCASTIPADDRESS_TABLE Structure.  Use FreeMibTable to free this
'        buffer.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    The API allocates the buffer for Table.  Use FreeMibTable to free it.
'
'--


'
' Multicast address management routines.
'
TYPE MIB_MULTICASTIPADDRESS_ROW
    '
    ' Key Structure.
    '
    Address        AS SOCKADDR_INET
    InterfaceIndex AS NET_IFINDEX
    InterfaceLuid  AS NET_LUID

    '
    ' Read-Only Fields.
    '
    ScopeId        AS SCOPE_ID
END TYPE

TYPE MIB_MULTICASTIPADDRESS_TABLE
    NumEntries         AS DWORD
    Table(%ANY_SIZE-1) AS MIB_MULTICASTIPADDRESS_ROW
END TYPE

DECLARE FUNCTION GetMulticastIpAddressEntry LIB "IpHlpApi.dll" _
    ALIAS "GetMulticastIpAddressEntry" ( _
    Row AS MIB_MULTICASTIPADDRESS_ROW _
    ) AS LONG

'++
'
'Routine Description:
'
'    Retrieves information for the specified mulitcast IP address entry on the
'    local computer.
'
'Arguments:
'
'    Row - Supplies a MIB_MULTICASTIPADDRESS_ROW structure.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    On input, the following key fields of Row must be initialized.
'    1. Address to a valid IPv4 or IPv6 multicast address.
'    2. At least one of InterfaceLuid or InterfaceIndex must be specified.
'
'    On output, the remaining fields of Row are filled in.
'
'--

DECLARE FUNCTION GetMulticastIpAddressTable LIB "IpHlpApi.dll" _
    ALIAS "GetMulticastIpAddressTable" ( _
    BYVAL Family AS ADDRESS_FAMILY, _
    Table        AS ANY _  ' PMIB_MULTICASTIPADDRESS_TABLE *
    ) AS LONG

'++
'
'Routine Description:
'
'    Retrieves the multicast IP address table on the local computer.
'
'Arguments:
'
'    Family - Supplies the address family.
'
'        AF_INET: Only returns IPv4 multicast addresses.
'
'        AF_INET6: Only returns IPv6 multicast addresses.
'
'        AF_UNSPEC: Returns both IPv4 and IPv6 multicast addresses.
'
'    Table - Returns the table of multicast IP addresses in a
'        MIB_MULTICASTIPADDRESS_TABLE Structure.  Use FreeMibTable to free this
'        buffer.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    The API allocates the buffer for Table.  Use FreeMibTable to free it.
'
'--

'
' Route management routines.
'

TYPE IP_ADDRESS_PREFIX
    Prefix       AS SOCKADDR_INET
    PrefixLength AS BYTE
END TYPE

TYPE MIB_IPFORWARD_ROW2
    '
    ' Key Structure.
    '
    InterfaceLuid        AS NET_LUID
    InterfaceIndex       AS NET_IFINDEX
    DestinationPrefix    AS IP_ADDRESS_PREFIX
    NextHop              AS SOCKADDR_INET

    '
    ' Read-Write Fields.
    '
    SitePrefixLength     AS BYTE
    ValidLifetime        AS DWORD
    PreferredLifetime    AS DWORD
    Metric               AS DWORD
    Protocol             AS NL_ROUTE_PROTOCOL_enum

    Loopback             AS BYTE  ' BOOLEAN
    AutoconfigureAddress AS BYTE  ' BOOLEAN
    Publish              AS BYTE  ' BOOLEAN
    Immortal             AS BYTE  ' BOOLEAN

    '
    ' Read-Only Fields.
    '
    Age                  AS DWORD
    Origin               AS NL_ROUTE_ORIGIN_enum
END TYPE  ' MIB_IPFORWARD_ROW2

TYPE MIB_IPFORWARD_TABLE2
    NumEntries         AS DWORD
    Table(%ANY_SIZE-1) AS MIB_IPFORWARD_ROW2
END TYPE


DECLARE SUB PIPFORWARD_CHANGE_CALLBACK ( _
    CallerContext          AS ANY, _  ' PVOID
    Row                    AS MIB_IPFORWARD_ROW2, _
    BYVAL NotificationType AS MIB_NOTIFICATION_TYPE_enum _
    )

DECLARE FUNCTION CreateIpForwardEntry2 LIB "IpHlpApi.dll" _
    ALIAS "CreateIpForwardEntry2" ( _
    Row AS MIB_IPFORWARD_ROW2 _
    ) AS LONG

'++
'
'Routine Description:
'
'    Create a route on the local computer.
'
'Arguments:
'
'    Row - Supplies a MIB_IPFORWARD_ROW2 structure.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    InitializeIpForwardEntry must be used to initialize the fields of
'    MIB_IPFORWARD_ROW2 with default values.  The caller can then update the
'    fields it wishes to modify and invoke CreateIpForwardEntry2.
'
'    On input, the following key fields of Row must be initialized after
'    invoking InitializeIpForwardEntry:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. DestinationPrefix.
'    3. NextHop.
'
'--

DECLARE FUNCTION DeleteIpForwardEntry2 LIB "IpHlpApi.dll" _
    ALIAS "DeleteIpForwardEntry2" ( _
    Row AS MIB_IPFORWARD_ROW2 _
    ) AS LONG

'++
'
'Routine Description:
'
'    Delete a route on the local computer.
'
'Arguments:
'
'    Row - Supplies a MIB_IPFORWARD_ROW2 structure.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    On input, the following key fields of Row must be initialized:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. DestinationPrefix.
'    3. NextHop.
'
'--

DECLARE FUNCTION GetBestRoute2 LIB "IpHlpApi.dll" ALIAS "GetBestRoute2" ( _
    InterfaceLuid            AS NET_LUID, _
    BYVAL InterfaceIndex     AS NET_IFINDEX, _
    SourceAddress            AS SOCKADDR_INET, _
    DestinationAddress       AS SOCKADDR_INET, _
    BYVAL AddressSortOptions AS DWORD, _
    BestRoute                AS MIB_IPFORWARD_ROW2, _
    BestSourceAddress        AS SOCKADDR_INET _
    ) AS LONG

'++
'
'Routine Description:
'
'    Retrieve the best route between source and destination address on a local
'        computer.
'
'Arguments:
'
'    InterfaceLuid - Supplies Luid to specify an interface.
'
'    InterfaceIndex - Supplies Index to specify an interface.
'
'    SourceAddress - Supplies source address.
'
'    DestinationAddress - Supplies destination address.
'
'    AddressSortOptions - Supplies AddressSortOptions.
'
'    BestRoute - Returns the MIB structure that holds the best route.
'
'    BestSourceAddress - Returns the source address of the best route.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    On input, the following parameters must be supplied:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. SourceAddress.
'    3. DestinationAddress.
'
'--

DECLARE FUNCTION GetIpForwardEntry2 LIB "IpHlpApi.dll" _
    ALIAS "GetIpForwardEntry2" ( _
    Row AS MIB_IPFORWARD_ROW2 _
    ) AS LONG

'++
'
'Routine Description:
'
'    Retrieves information for the specified route entry on the local computer.
'
'Arguments:
'
'    Route - Supplies a MIB_IPFORWARD_ROW2 structure.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    On input, the following key fields of Row must be initialized:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. DestinationPrefix and NextHop can be specified.
'
'    On output, the remaining fields of Row are filled in.
'
'    If one or more routes matches the specified criteria,
'    this API matches the first entry.
'
'--

DECLARE FUNCTION GetIpForwardTable2 LIB "IpHlpApi.dll" _
    ALIAS "GetIpForwardTable2" ( _
    BYVAL Family AS ADDRESS_FAMILY, _
    Table        AS ANY _  ' PMIB_IPFORWARD_TABLE2 *
    ) AS LONG

'++
'
'Routine Description:
'
'    Retrieves the route table on a local computer.
'
'Arguments:
'
'    Family - Supplies the address family.
'
'        AF_INET: Only returns IPv4 route entries.
'
'        AF_INET6: Only returns IPv6 route entries.
'
'        AF_UNSPEC: Returns both IPv4 and IPv6 route entries.
'
'    Table - Returns the table of routes in a MIB_IPFORWARD_TABLE2 Structure.
'        Use FreeMibTable to free this buffer.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    The API allocates the buffer for Table.  Use FreeMibTable to free it.
'
'--

DECLARE SUB InitializeIpForwardEntry LIB "IpHlpApi.dll" _
    ALIAS "InitializeIpForwardEntry" ( _
    Row AS MIB_IPFORWARD_ROW2 _
    )

'++
'
'Routine Description:
'
'    Initialize the MIB_IPFORWARD_ROW2 entry for use in SetIpForwardEntry2.
'
'Arguments:
'
'    Row - Returns an initialized PMIB_IPFORWARD_ROW2 structure.
'
'Return Value:
'
'    None.
'
'Notes:
'
'    InitializeIpForwardEntry must be used to initialize the fields of
'        MIB_IPFORWARD_ROW2 with default values.  The caller can then update the
'        fields it wishes to modify and invoke SetIpForwardEntry2.
'
'--

DECLARE FUNCTION NotifyRouteChange2 LIB "IpHlpApi.dll" _
    ALIAS "NotifyRouteChange2" ( _
    BYVAL AddressFamily       AS ADDRESS_FAMILY, _
    BYVAL CALLBACK            AS DWORD, _  ' PIPFORWARD_CHANGE_CALLBACK
    CallerContext             AS ANY, _    ' PVOID
    BYVAL InitialNotification AS BYTE, _   ' BOOLEAN
    NotificationHandle        AS DWORD _   ' HANDLE *
    ) AS LONG

'++
'
'Routine Description:
'
'    Register for notification for route changes.
'
'Arguments:
'
'    Family - Supplies the address family.
'
'        AF_INET: Only register for IPv4 route change notifications.
'
'        AF_INET6: Only register for IPv6 route change notifications.
'
'        AF_UNSPEC: Register for both IPv4 and IPv6 route change notifications.
'
'    Callback - Supplies a callback function. This function will be invoked when
'        an unicast IP address notification is received.
'
'    CallerContext - Provides the user specific caller context. This context
'        will be supplied to the callback function.
'
'    InitialNotification - Supplies a boolean to indicate whether an
'        initialization notification should be provided.
'
'    NotificationHandle - Returns a handle to the notification registration.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    1. Invokation of the callback function is serialized.
'
'    2. Use CancelMibChangeNotify2 to deregister for change notifications.
'
'--

DECLARE FUNCTION SetIpForwardEntry2 LIB "IpHlpApi.dll" _
    ALIAS "SetIpForwardEntry2" ( _
    Route AS MIB_IPFORWARD_ROW2 _
    ) AS LONG

'++
'
'Routine Description:
'
'    Set the properties of a route entry.
'
'Arguments:
'
'    Route - Supplies a MIB_UNICASTIPADDRESS_ROW structure.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    InitializeIpForwardEntry must be used to initialize the fields of
'    MIB_IPFORWARD_ROW2 with default values.  The caller can then update the
'    fields it wishes to modify and invoke SetIpForwardEntry2.
'
'    On input, the following key fields of Row must be initialized after
'    invoking InitializeIpForwardEntry:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. DestinationPrefix.
'    3. NextHop.
'
'--

'
' Path management routines.
'

UNION MIB_IPPATH_ROW_union
    LastReachable   AS DWORD   ' Milliseconds.
    LastUnreachable AS DWORD   ' Milliseconds.
END UNION

TYPE MIB_IPPATH_ROW
    '
    ' Key.
    '

    SOURCE         AS SOCKADDR_INET
    Destination    AS SOCKADDR_INET
    InterfaceLuid  AS NET_LUID
    InterfaceIndex AS NET_IFINDEX

    '
    ' RO.
    '
    '
    ' The current next hop.  This can change over the lifetime of a path.
    '
    CurrentNextHop AS SOCKADDR_INET

    '
    ' MTU of path to destination. Includes the IP header length.
    '
    PathMtu        AS DWORD

    '
    ' Estimated mean RTT.
    '
    RttMean        AS DWORD

    '
    ' Mean deviation of RTT.
    '
    RttDeviation   AS DWORD
    MIB_IPPATH_ROW_union
    IsReachable    AS BYTE  ' BOOLEAN

    '
    ' Estimated speed.
    '
    LinkTransmitSpeed AS QUAD  ' ULONG64
    LinkReceiveSpeed  AS QUAD  ' ULONG64

END TYPE  ' MIB_IPPATH_ROW

TYPE MIB_IPPATH_TABLE
    NumEntries         AS DWORD
    Table(%ANY_SIZE-1) AS MIB_IPPATH_ROW
END TYPE


DECLARE FUNCTION FlushIpPathTable LIB "IpHlpApi.dll" _
    ALIAS "FlushIpPathTable" ( _
    BYVAL Family AS ADDRESS_FAMILY _
    ) AS LONG

'++
'
'Routine Description:
'
'    Flush the IP Path table on the local computer.
'
'Arguments:
'
'    Family - Supplies the address family.
'
'        AF_INET: Only flush the IPv4 path table.
'
'        AF_INET6: Only flush the IPv6 path table.
'
'        AF_UNSPEC: Flush both IPv4 and IPv6 path table.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'--

DECLARE FUNCTION GetIpPathEntry LIB "IpHlpApi.dll" _
    ALIAS "GetIpPathEntry" ( _
    Row AS MIB_IPPATH_ROW _
    ) AS LONG

'++
'
'Routine Description:
'
'    Retrieves information for the specified path entry on the local computer.
'
'Arguments:
'
'    Row - Supplies a MIB_IPPATH_ROW structure.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    On input, the following key fields of Row must be initialized:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. Source.
'    3. Destination.
'
'    On output, the remaining fields of Row are filled in.
'
'--

DECLARE FUNCTION GetIpPathTable LIB "IpHlpApi.dll" _
    ALIAS "GetIpPathTable" ( _
    BYVAL Family AS ADDRESS_FAMILY, _
    Table        AS ANY _  ' PMIB_IPPATH_TABLE *
    ) AS LONG

'++
'
'Routine Description:
'
'    Retrieves the path table on a local computer.
'
'Arguments:
'
'    Family - Supplies the address family.
'
'        AF_INET: Only returns IPv4 paths.
'
'        AF_INET6: Only returns IPv6 paths.
'
'        AF_UNSPEC: Returns both IPv4 and IPv6 paths.
'
'    Table - Returns the table of paths in a MIB_IPPATH_TABLE
'        structure.  Use FreeMibTable to free this buffer.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    The API allocates the buffer for Table.  Use FreeMibTable to free it.
'
'--

'
' ARP and IPv6 Neighbor management routines.
'

TYPE MIB_IPNET_ROW2_type
    IsRouter      AS BIT * 1 IN BYTE  ' BOOLEAN
    IsUnreachable AS BIT * 1          ' BOOLEAN
END TYPE

UNION MIB_IPNET_ROW2_union
    MIB_IPNET_ROW2_type
    Flags AS BYTE
END UNION

TYPE MIB_IPNET_ROW2
    '
    ' Key Struture.
    '
    Address         AS SOCKADDR_INET
    InterfaceIndex  AS NET_IFINDEX
    InterfaceLuid   AS NET_LUID

    '
    ' Read-Write.
    '
    PhysicalAddress AS STRING * %IF_MAX_PHYS_ADDRESS_LENGTH

    '
    ' Read-Only.
    '
    PhysicalAddressLength AS DWORD
    STATE                 AS NL_NEIGHBOR_STATE_enum

    MIB_IPNET_ROW2_union

    ReachabilityTime      AS MIB_IPPATH_ROW_union
END TYPE  ' MIB_IPNET_ROW2

TYPE MIB_IPNET_TABLE2
    NumEntries         AS DWORD
    Table(%ANY_SIZE-1) AS MIB_IPNET_ROW2
END TYPE

DECLARE FUNCTION CreateIpNetEntry2 LIB "IpHlpApi.dll" _
    ALIAS "CreateIpNetEntry2" ( _
    Row AS MIB_IPNET_ROW2 _
    ) AS LONG

'++
'
'Routine Description:
'
'    Create a neighbor entry on the local computer.
'
'Arguments:
'
'    Row - Supplies a MIB_IPNET_ROW2 structure.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    On input, the following key fields of Row must be initialized:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. Address.
'    3. PhysicalAddress.
'
'--

DECLARE FUNCTION DeleteIpNetEntry2 LIB "IpHlpApi.dll" _
    ALIAS "DeleteIpNetEntry2" ( _
    Row AS MIB_IPNET_ROW2 _
    ) AS LONG

'++
'
'Routine Description:
'
'    Delete a neighbor entry on the local computer.
'
'Arguments:
'
'    Row - Supplies a MIB_IPNET_ROW2 structure.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    On input, the following key fields of Row must be initialized:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. Address.
'
'--


DECLARE FUNCTION FlushIpNetTable2 LIB "IpHlpApi.dll" _
    ALIAS "FlushIpNetTable2" ( _
    BYVAL Family         AS ADDRESS_FAMILY, _
    BYVAL InterfaceIndex AS NET_IFINDEX _
    ) AS LONG

'++
'
'Routine Description:
'
'    Flush the neighbor entry table on the local computer.
'
'Arguments:
'
'    Family - Supplies the address family.
'
'        AF_INET: Only flush the IPv4 neighbor table.
'
'        AF_INET6: Only flush the IPv6 neighbor table.
'
'        AF_UNSPEC: Flush both IPv4 and IPv6 neighbor table.
'
'    InterfaceIndex - Supplies the Interface index.  If the index is specified,
'        flush the neighbor entries on a specific interface, otherwise flush the
'        neighbor entries on all the interfaces.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'--

DECLARE FUNCTION GetIpNetEntry2 LIB "IpHlpApi.dll" _
    ALIAS "GetIpNetEntry2" ( _
    Row AS MIB_IPNET_ROW2 _
    ) AS LONG

'++
'
'Routine Description:
'
'    Retrieves information for the specified neighbor entry on the local
'    computer.
'
'Arguments:
'
'    Row - Supplies a MIB_IPNET_ROW2 structure.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    On input, the following key fields of Row must be initialized:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. Address.
'
'    On output, the remaining fields of Row are filled in.
'
'--

DECLARE FUNCTION GetIpNetTable2 LIB "IpHlpApi.dll" _
    ALIAS "GetIpNetTable2" ( _
    BYVAL Family AS ADDRESS_FAMILY, _
    Table        AS ANY _  ' PMIB_IPNET_TABLE2 *
    ) AS LONG

'++
'
'Routine Description:
'
'    Retrieves the neighbor table on the local computer.
'
'Arguments:
'
'    Family - Supplies the address family.
'
'        AF_INET: Only returns IPv4 neighbor entries.
'
'        AF_INET6: Only returns IPv6 neighbor entries.
'
'        AF_UNSPEC: Returns both IPv4 and IPv6 neighbor entries.
'
'    Table - Returns the table of neighbor entries in a MIB_IPNET_TABLE2
'        structure.  Use FreeMibTable to free this buffer.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    The API allocates the buffer for Table.  Use FreeMibTable to free it.
'
'--

DECLARE FUNCTION ResolveIpNetEntry2 LIB "IpHlpApi.dll" _
    ALIAS "ResolveIpNetEntry2" ( _
    Row           AS MIB_IPNET_ROW2, _
    SourceAddress AS SOCKADDR_INET _
    ) AS LONG

'++
'
'Routine Description:
'
'    Resolve the physical address of a specific neighbor.
'
'Arguments:
'
'    NetEntry - Supplies a MIB_IPNET_ROW2 structure.
'
'    SourceAddress - Supplies the source address.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    This API flushes any existing neighbor entry and resolves the MAC address
'    by sending ARP requests (IPv4) or Neighbor Solicitation (IPv6).
'    If source address is not provided, the API will automatically select the
'    best interface to send the request on.
'
'    On input, the following key fields of Row must be initialized:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. Address.
'
'    On output, the remaining fields of Row are filled in.
'
'--

DECLARE FUNCTION SetIpNetEntry2 LIB "IpHlpApi.dll" _
    ALIAS "SetIpNetEntry2" ( _
    Row AS MIB_IPNET_ROW2 _
    ) AS LONG

'++
'
'Routine Description:
'
'    Set the physical address of a neighbor entry.
'
'Arguments:
'
'    NetEntry - Supplies a MIB_IPNET_ROW2 structure.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    On input, the following key fields of Row must be initialized:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. Address.
'    3. PhysicalAddress.
'
'--

'
' Teredo APIs.
'
%MIB_INVALID_TEREDO_PORT_NUMBER = 0

DECLARE SUB PTEREDO_PORT_CHANGE_CALLBACK ( _
    CallerContext          AS ANY, _  ' PVOID
    BYVAL PORT             AS WORD, _
    BYVAL NotificationType AS MIB_NOTIFICATION_TYPE_enum _
    )

DECLARE FUNCTION NotifyTeredoPortChange LIB "IpHlpApi.dll" _
    ALIAS "NotifyTeredoPortChange" ( _
    BYVAL CALLBACK            AS DWORD, _  ' PTEREDO_PORT_CHANGE_CALLBACK
    CallerContext             AS ANY, _    ' PVOID
    BYVAL InitialNotification AS BYTE, _   ' BOOLEAN
    NotificationHandle        AS DWORD _   ' HANDLE *
    ) AS LONG

DECLARE FUNCTION GetTeredoPort LIB "IpHlpApi.dll" ALIAS "GetTeredoPort" ( _
    PORT AS WORD _
    ) AS LONG

'++
'
'Routine Description:
'
'    Get the Teredo client port.
'
'Arguments:
'
'    Port - returns the Teredo port.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'--

#IF NOT %DEF(%TEREDO_API_NO_DEPRECATE)

'
' Deprecate all of the unsafe functions to generate compiletime errors.
' Use the following routines instead : FwpmSystemPortsGet
'

'#pragma deprecated(NotifyTeredoPortChange)
'#pragma deprecated(GetTeredoPort)

#ENDIF ' %TEREDO_API_NO_DEPRECATE

'
' Generic (not IP-specific) interface definitions.
'

DECLARE FUNCTION CancelMibChangeNotify2 LIB "IpHlpApi.dll" _
    ALIAS "CancelMibChangeNotify2" ( _
    BYVAL NotificationHandle AS DWORD _  ' HANDLE
    ) AS LONG

'++
'
'Routine Description:
'
'    Deregister for change notifications.
'
'Arguments:
'
'    NotificationHandle - Supplies the handle returned from a notification
'        registration.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'Notes:
'
'    Blocks until all callback have returned.
'
'--

DECLARE SUB FreeMibTable LIB "IpHlpApi.dll" ALIAS "FreeMibTable" ( _
    Memory AS ANY _  ' PVOID
    )
'++
'
'Routine Description:
'
'    Free the buffer allocated by Get*Table APIs.
'
'Arguments:
'
'    Memory - Supplies the buffer to free.
'
'Return Value:
'
'    None.
'
'--

DECLARE FUNCTION CreateSortedAddressPairs LIB "IpHlpApi.dll" _
    ALIAS "CreateSortedAddressPairs" ( _
    BYVAL SourceAddressList       AS SOCKADDR_IN6 PTR, _
    BYVAL SourceAddressCount      AS DWORD, _
    BYVAL DestinationAddressList  AS SOCKADDR_IN6 PTR, _
    BYVAL DestinationAddressCount AS DWORD, _
    BYVAL AddressSortOptions      AS DWORD, _
    SortedAddressPairList         AS ANY, _  ' PSOCKADDR_IN6_PAIR *
    SortedAddressPairCount        AS DWORD _
    ) AS LONG

'++
'
'Routine Description:
'
'    Given a list of source and destination addresses, returns a list of
'    pairs of addresses in sorted order.  The list is sorted by which address
'    pair is best suited for communication between two peers.
'
'    The list of source addresses is optional, in which case the function
'    automatically uses all the host machine's local addresses.
'
'Arguments:
'
'    SourceAddressList - Supplies list of potential source addresses.
'        If NULL the routine automatically uses all local addresses.
'        IPv4 addresses can be specified in IPv4-mapped format.
'        Reserved for future use.  Must be NULL.
'
'    SourceAddressCount - Supplies the number of addresses in the
'        SourceAddressList.
'        Reserved for future use.  Must be 0.
'
'    DestinationAddressList - Supplies list of potential destination addresses.
'        IPv4 addresses can be specified in IPv4-mapped format.
'
'    DestinationAddressCount -  Supplies the number of addresses in the
'        DestinationAddressList.
'
'    AddressSortOptions - Reserved for future use.  Must be 0.
'
'    SortedAddressPairList - Returns a sorted list of pairs of addresses
'        in prefered order of communication.  The list must be freed with a
'        single call to NetioFreeMemory.
'
'    SortedAddressPairCount - Returns the number of address pairs in
'        SortedAddressPairList.
'
'Return Value:
'
'    ERROR_SUCCESS on success.  WIN32 error code on error.
'
'--

#ENDIF ' %WS2IPDEF

DECLARE FUNCTION ConvertInterfaceNameToLuidA LIB "IpHlpApi.dll" _
    ALIAS "ConvertInterfaceNameToLuidA" ( _
    InterfaceName AS ASCIIZ, _
    InterfaceLuid AS NET_LUID _
    ) AS LONG

'++
'
'Routine Description:
'
'    Convert an Interface Name to Luid.
'
'Arguments:
'
'    InterfaceName - Supplies the interface name to be converted.
'
'    InterfaceLuid - Returns the interface Luid.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'--

DECLARE FUNCTION ConvertInterfaceNameToLuidW LIB "IpHlpApi.dll" _
    ALIAS "ConvertInterfaceNameToLuidW" ( _
    InterfaceName AS WSTRINGZ, _
    InterfaceLuid AS NET_LUID _
    ) AS LONG

'++
'
'Routine Description:
'
'    Convert an Interface Name to Luid.
'
'Arguments:
'
'    InterfaceName - Supplies the interface name to be converted.
'
'    InterfaceLuid - Returns the interface Luid.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'--

DECLARE FUNCTION ConvertInterfaceLuidToNameA LIB "IpHlpApi.dll" _
    ALIAS "ConvertInterfaceLuidToNameA" ( _
    InterfaceLuid AS NET_LUID, _
    InterfaceName AS ASCIIZ, _
    BYVAL Length  AS SIZE_T _
    ) AS LONG

'++
'
'Routine Description:
'
'    Convert an Interface Luid to Name.
'
'Arguments:
'
'    InterfaceLuid - Supplies the interface Luid to be converted.
'
'    InterfaceName - Returns the interface name.
'
'    Lenght - Supplies the length of the InterfaceName buffer.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'--

DECLARE FUNCTION ConvertInterfaceLuidToNameW LIB "IpHlpApi.dll" _
    ALIAS "ConvertInterfaceLuidToNameW" ( _
    InterfaceLuid AS NET_LUID, _
    InterfaceName AS ASCIIZ, _
    BYVAL Length AS SIZE_T _
    ) AS LONG

'++
'
'Routine Description:
'
'    Convert an Interface Luid to Name.
'
'Arguments:
'
'    InterfaceLuid - Supplies the interface Luid to be converted.
'
'    InterfaceName - Returns the interface name.
'
'    Length - Supplies the length of the InterfaceName buffer.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'--

DECLARE FUNCTION ConvertInterfaceLuidToIndex LIB "IpHlpApi.dll" _
    ALIAS "ConvertInterfaceLuidToIndex" ( _
    InterfaceLuid  AS NET_LUID, _
    InterfaceIndex AS NET_IFINDEX _
    ) AS LONG

'++
'
'Routine Description:
'
'    Convert an Interface Luid to Index.
'
'Arguments:
'
'    InterfaceLuid - Supplies the interface Luid to be converted.
'
'    InterfaceName - Returns the interface Index.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'--

DECLARE FUNCTION ConvertInterfaceIndexToLuid LIB "IpHlpApi.dll" _
    ALIAS "ConvertInterfaceIndexToLuid" ( _
    BYVAL InterfaceIndex AS NET_IFINDEX, _
    InterfaceLuid        AS NET_LUID _
    ) AS LONG

'++
'
'Routine Description:
'
'    Convert an Interface Index to Luid.
'
'Arguments:
'
'    InterfaceName - Supplies the interface Index to be converted.
'
'    InterfaceLuid - Returns the interface Luid.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'--

DECLARE FUNCTION ConvertInterfaceLuidToAlias LIB "IpHlpApi.dll" _
    ALIAS "ConvertInterfaceLuidToAlias" ( _
    InterfaceLuid  AS NET_LUID, _
    InterfaceAlias AS WSTRINGZ, _
    BYVAL Length   AS SIZE_T _
    ) AS LONG

'++
'
'Routine Description:
'
'    Convert an Interface Luid to Alias.
'
'Arguments:
'
'    InterfaceLuid - Supplies the interface Luid to be converted.
'
'    InterfaceAlias - Returns the interface Alias.
'
'    Length - Supplies the length of InterfaceAlias buffer.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'--

DECLARE FUNCTION ConvertInterfaceAliasToLuid LIB "IpHlpApi.dll" _
    ALIAS "ConvertInterfaceAliasToLuid" ( _
    InterfaceAlias AS WSTRINGZ, _
    InterfaceLuid AS NET_LUID _
    ) AS LONG

'++
'
'Routine Description:
'
'    Convert an Interface Alias to Luid.
'
'Arguments:
'
'    InterfaceAlias - Supplies the null terminated interface Alias.
'
'    InterfaceLuid - Returns the interface Luid.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'--

DECLARE FUNCTION ConvertInterfaceLuidToGuid LIB "IpHlpApi.dll" _
    ALIAS "ConvertInterfaceLuidToGuid" ( _
    InterfaceLuid AS NET_LUID, _
    InterfaceGuid AS GUID _
    ) AS LONG

'++
'
'Routine Description:
'
'    Convert an Interface Luid to Guid.
'
'Arguments:
'
'    InterfaceLuid - Supplies the interface Luid to be converted.
'
'    InterfaceGuid - Returns the interface Guid.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'--

DECLARE FUNCTION ConvertInterfaceGuidToLuid LIB "IpHlpApi.dll" _
    ALIAS "ConvertInterfaceGuidToLuid" ( _
    InterfaceGuid AS GUID, _
    InterfaceLuid AS NET_LUID _
    ) AS LONG

'++
'
'Routine Description:
'
'    Convert an Interface Luid to Guid.
'
'Arguments:
'
'    InterfaceGuid - Supplies the interface Guid to be converted.
'
'    InterfaceGuid - Returns the interface Luid.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'--

%IF_NAMESIZE=%NDIS_IF_MAX_STRING_SIZE

DECLARE FUNCTION if_nametoindex LIB "IpHlpApi.dll" _
    ALIAS "if_nametoindex" ( _
    InterfaceName AS ASCIIZ _
    ) AS LONG

'++
'
'Routine Description:
'
'    Convert an Interface name to Index.
'
'Arguments:
'
'    InterfaceName - Supplies the null terminated interface name to convert.
'
'Return Value:
'
'    Interface index on success, 0 otherwise.
'
'--

DECLARE FUNCTION if_indextoname LIB "IpHlpApi.dll" _
    ALIAS "if_indextoname" ( _
    BYVAL InterfaceIndex AS NET_IFINDEX, _
    InterfaceName        AS ASCIIZ _
    ) AS DWORD  ' ASCIIZ PTR

'++
'
'Routine Description:
'
'    Convert an Interface index to Name.
'
'Arguments:
'
'    InterfaceIndex - Supplies the Interface index to convert.
'
'    InterfaceName - Returns the null terminated interface name.
'
'Return Value:
'
'    Interface name on success, NULL otherwise.
'
'Notes:
'
'    The length of InterfaceName buffer must be equal to or greater than
'        IF_NAMESIZE.
'
'--

DECLARE FUNCTION GetCurrentThreadCompartmentId LIB "IpHlpApi.dll" _
    ALIAS "GetCurrentThreadCompartmentId" () AS LONG

'++
'
'Routine Description:
'
'    Get the compartment ID of current thread.
'
'Arguments:
'
'    None.
'
'Return Value:
'
'    The compartment ID of current thread.
'
'--

DECLARE FUNCTION SetCurrentThreadCompartmentId LIB "IpHlpApi.dll" _
    ALIAS "SetCurrentThreadCompartmentId" ( _
    BYVAL CompartmentId AS NET_IF_COMPARTMENT_ID _
    ) AS LONG

'++
'
'Routine Description:
'
'    Set the compartment ID of current thread.
'
'Arguments:
'
'    CompartmentId - Supplies the compartment ID to be set.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'
'--

DECLARE FUNCTION GetSessionCompartmentId LIB "IpHlpApi.dll" _
    ALIAS "GetSessionCompartmentId" ( _
    BYVAL SessionId AS DWORD _
    ) AS LONG

'++
'
'Routine Description:
'
'    Get the compartment ID of the session.
'
'Arguments:
'
'    SessionId - Supplies the session ID.
'
'Return Value:
'
'    The compartment ID of the session.
'
'--

DECLARE FUNCTION SetSessionCompartmentId LIB "IpHlpApi.dll" _
    ALIAS "SetSessionCompartmentId" ( _
    BYVAL SessionId AS DWORD, _
    BYVAL CompartmentId AS NET_IF_COMPARTMENT_ID _
    ) AS LONG

'++
'
'Routine Description:
'
'    Set the compartment ID of the session.
'
'Arguments:
'
'    SessionId - Supplies the session ID.
'
'    CompartmentId - Supplies the compartment ID to be set.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'--

DECLARE FUNCTION GetNetworkInformation LIB "IpHlpApi.dll" _
    ALIAS "GetNetworkInformation" ( _
    NetworkGuid   AS NET_IF_NETWORK_GUID, _
    CompartmentId AS NET_IF_COMPARTMENT_ID, _
    SiteId        AS DWORD, _
    NetworkName   AS WSTRINGZ, _
    BYVAL Length  AS DWORD _
    ) AS LONG

'++
'
'Routine Description:
'
'    Get the network information.
'
'Arguments:
'
'    NetworkGuid - Supplies the Network GUID.
'
'    CompartmentId - Returns the compartment ID.
'
'    SiteId - Returns Site ID.
'
'    NetowrkName - Returns the network name.
'
'    Length - Supplies the length of NetworkName buffer.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'--

DECLARE FUNCTION SetNetworkInformation LIB "IpHlpApi.dll" _
    ALIAS "SetNetworkInformation" ( _
    NetworkGuid         AS NET_IF_NETWORK_GUID, _
    BYVAL CompartmentId AS NET_IF_COMPARTMENT_ID, _
    NetworkName         AS WSTRINGZ _
    ) AS LONG

'++
'
'Routine Description:
'
'    Set the Network Information.
'
'Arguments:
'
'    NetworkGuid - Supplies the session ID.
'
'    CompartmentId - Supplies the compartment ID to be set.
'
'    NetworkName - Supplies the Network name to be set.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'--


DECLARE FUNCTION ConvertLengthToIpv4Mask LIB "IpHlpApi.dll" _
    ALIAS "ConvertLengthToIpv4Mask" ( _
    BYVAL MaskLength AS DWORD, _
    Mask AS DWORD _
    ) AS LONG

'++
'
'Routine Description:
'
'    Converts a prefixLength to a subnet mask.
'
'Arguments:
'
'    MaskLength - Prefix Length.
'
'    Mask - Mask generated.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'--

DECLARE FUNCTION ConvertIpv4MaskToLength LIB "IpHlpApi.dll" _
    ALIAS "ConvertIpv4MaskToLength" ( _
    BYVAL Mask AS DWORD, _
    MaskLength AS BYTE _
    ) AS LONG

'++
'
'Routine Description:
'
'    Converts a subnet mask to a prefix length.
'
'Arguments:
'
'    Mask - Subnet mask to use.
'
'    MaskLength - Prefix length computed.
'
'Return Value:
'
'    User-Mode: %NO_ERROR on success, error code on failure.
'
'    Kernel-Mode: %STATUS_SUCCESS on success, error code on failure.
'
'--

'
'4201.
'
