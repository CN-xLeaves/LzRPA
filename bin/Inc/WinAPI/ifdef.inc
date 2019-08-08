'------------------------------------------------------------------------------
'
'  IfDef.inc  - This module contains IF_* definitions.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from IfDef.h of 14 Jul 2009
'------------------------------------------------------------------------------
'  NOTE: before including this file, use #INCLUDE "Win32Api.inc"
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%IFDEF = 1

#INCLUDE "SdkDdkVer.inc"

MACRO NET_IF_OBJECT_ID=DWORD


MACRO NET_IF_ADMIN_STATUS_enum=LONG
ENUM NET_IF_ADMIN_STATUS SINGULAR  ' ifAdminStatus
    NET_IF_ADMIN_STATUS_UP = 1
    NET_IF_ADMIN_STATUS_DOWN
    NET_IF_ADMIN_STATUS_TESTING
END ENUM

MACRO NET_IF_OPER_STATUS_enum=LONG
ENUM NET_IF_OPER_STATUS SINGULAR  ' ifOperStatus
    NET_IF_OPER_STATUS_UP = 1
    NET_IF_OPER_STATUS_DOWN
    NET_IF_OPER_STATUS_TESTING
    NET_IF_OPER_STATUS_UNKNOWN
    NET_IF_OPER_STATUS_DORMANT
    NET_IF_OPER_STATUS_NOT_PRESENT
    NET_IF_OPER_STATUS_LOWER_LAYER_DOWN
END ENUM

'
' Flags to extend operational status
'
%NET_IF_OPER_STATUS_DOWN_NOT_AUTHENTICATED   = &H00000001
%NET_IF_OPER_STATUS_DOWN_NOT_MEDIA_CONNECTED = &H00000002
%NET_IF_OPER_STATUS_DORMANT_PAUSED           = &H00000004
%NET_IF_OPER_STATUS_DORMANT_LOW_POWER        = &H00000008


MACRO NET_IF_COMPARTMENT_ID=DWORD

'
' Define compartment ID type:
'
%NET_IF_COMPARTMENT_ID_UNSPECIFIED = 0
%NET_IF_COMPARTMENT_ID_PRIMARY     = 1

%NET_IF_OID_IF_ALIAS       = &H00000001  ' identifies the ifAlias string for an interface
%NET_IF_OID_COMPARTMENT_ID = &H00000002  ' identifies the compartment ID for an interface.
%NET_IF_OID_NETWORK_GUID   = &H00000003  ' identifies the NetworkGuid for an interface.
%NET_IF_OID_IF_ENTRY       = &H00000004  ' identifies statistics for an interface.

'
' Define NetworkGUID type:
'
MACRO NET_IF_NETWORK_GUID=GUID

'
' Define macros for an "unspecified" NetworkGUID value to be used in structures
' that haven't had the NET_LUID field filled in yet.
'
'macro NET_SET_UNSPECIFIED_NETWORK_GUID(pNetworkGuid)
'macro NET_IS_UNSPECIFIED_NETWORK_GUID(NetworkGuidValue)

'
' To prevent collisions between user-assigned and system-assigend site-ids,
' we partition the site-id space into two:
' 1. User-Assigned: NET_SITEID_UNSPECIFIED < SiteId < NET_SITEID_MAXUSER
' 2. System-Assigned: NET_SITEID_MAXUSER < SiteId < NET_SITEID_MAXSYSTEM
'
' Note: A network's SiteId doesn't really need to be settable.
' 1. The network profile manager creates a network per network profile.
' 2. NDIS/IF assigns a unique SiteId to each network.
'
%NET_SITEID_UNSPECIFIED = (0)
%NET_SITEID_MAXUSER     = (&H07ffffff)
%NET_SITEID_MAXSYSTEM   = (&H0fffffff)
'C_ASSERT(NET_SITEID_MAXUSER < NET_SITEID_MAXSYSTEM);

MACRO NET_IF_RCV_ADDRESS_TYPE_enum=LONG
ENUM NET_IF_RCV_ADDRESS_TYPE SINGULAR ' ifRcvAddressType
    NET_IF_RCV_ADDRESS_TYPE_OTHER        = 1
    NET_IF_RCV_ADDRESS_TYPE_VOLATILE
    NET_IF_RCV_ADDRESS_TYPE_NON_VOLATILE
END ENUM

TYPE NET_IF_RCV_ADDRESS_LH
    ifRcvAddressType   AS NET_IF_RCV_ADDRESS_TYPE_enum
    ifRcvAddressLength AS WORD
    ifRcvAddressOffset AS WORD ' from beginning of this struct
END TYPE

TYPE NET_IF_ALIAS_LH
    ifAliasLength AS WORD  ' in bytes, of ifAlias string
    ifAliasOffset AS WORD  ' in bytes, from beginning of this struct
END TYPE

TYPE NET_LUID_LH_type
'    Reserved     AS BIT * 24 IN QUAD
'    NetLuidIndex AS BIT * 24
'    IfType       AS BIT * 16   ' equal to IANA IF type
    Reserved(2)     AS BYTE
    NetLuidIndex(2) AS BYTE
    IfType          AS WORD   ' equal to IANA IF type
END TYPE

UNION NET_LUID_LH
    Value AS QUAD  ' ULONG64
    Info  AS NET_LUID_LH_type
END UNION

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
TYPE NET_IF_RCV_ADDRESS
    NET_IF_RCV_ADDRESS_LH
END TYPE
TYPE NET_IF_ALIAS
    NET_IF_ALIAS_LH
END TYPE
#ENDIF ' %NTDDI_VISTA

'
' Need to make this visible on all platforms (for the purpose of IF_LUID).
'
TYPE NET_LUID
    NET_LUID_LH
END TYPE

'
' IF_LUID
'
' Define the locally unique datalink interface identifier type.
' This type is persistable.
'
TYPE IF_LUID
    NET_LUID
END TYPE

MACRO NET_IFINDEX=DWORD           ' Interface Index (ifIndex)
MACRO NET_IFTYPE=WORD             ' Interface Type (IANA ifType)

%NET_IFINDEX_UNSPECIFIED = (0)    ' Not a valid ifIndex
%NET_IFLUID_UNSPECIFIED  = (0)    ' Not a valid if Luid

'
' Definitions for NET_IF_INFORMATION.Flags
'
%NIIF_HARDWARE_INTERFACE       = &H00000001  ' Set iff hardware
%NIIF_FILTER_INTERFACE         = &H00000002
%NIIF_NDIS_RESERVED1           = &H00000004
%NIIF_NDIS_RESERVED2           = &H00000008
%NIIF_NDIS_RESERVED3           = &H00000010
%NIIF_NDIS_WDM_INTERFACE       = &H00000020
%NIIF_NDIS_ENDPOINT_INTERFACE  = &H00000040
%NIIF_NDIS_ISCSI_INTERFACE     = &H00000080

%NIIF_WAN_TUNNEL_TYPE_UNKNOWN  = &HFFFFFFFF??? ' ((ULONG)(-1))

'
' Define datalink interface access types.
'
MACRO NET_IF_ACCESS_TYPE_enum=LONG
ENUM NET_IF_ACCESS_TYPE SINGULAR
    NET_IF_ACCESS_LOOPBACK = 1
    NET_IF_ACCESS_BROADCAST
    NET_IF_ACCESS_POINT_TO_POINT
    NET_IF_ACCESS_POINT_TO_MULTI_POINT
    NET_IF_ACCESS_MAXIMUM
END ENUM


'
' Define datalink interface direction types.
'
MACRO NET_IF_DIRECTION_TYPE_enum=LONG
ENUM NET_IF_DIRECTION_TYPE SINGULAR
    NET_IF_DIRECTION_SENDRECEIVE
    NET_IF_DIRECTION_SENDONLY
    NET_IF_DIRECTION_RECEIVEONLY
    NET_IF_DIRECTION_MAXIMUM
END ENUM


MACRO NET_IF_CONNECTION_TYPE_enum=LONG
ENUM NET_IF_CONNECTION_TYPE SINGULAR
    NET_IF_CONNECTION_DEDICATED = 1
    NET_IF_CONNECTION_PASSIVE
    NET_IF_CONNECTION_DEMAND
    NET_IF_CONNECTION_MAXIMUM
END ENUM


MACRO NET_IF_MEDIA_CONNECT_STATE_enum=LONG
ENUM NET_IF_MEDIA_CONNECT_STATE SINGULAR
    MediaConnectStateUnknown
    MediaConnectStateConnected
    MediaConnectStateDisconnected
END ENUM

%NET_IF_LINK_SPEED_UNKNOWN = &HFFFFFFFFFFFFFFFF  ' ((ULONG64)(-1))

'
' Defines the duplex state of media
'
MACRO NET_IF_MEDIA_DUPLEX_STATE_enum=LONG
ENUM NET_IF_MEDIA_DUPLEX_STATE SINGULAR
    MediaDuplexStateUnknown
    MediaDuplexStateHalf
    MediaDuplexStateFull
END ENUM


' Special values for fields in NET_PHYSICAL_LOCATION
%NIIF_BUS_NUMBER_UNKNOWN      = &HFFFFFFFF???  '  ((ULONG)(-1))
%NIIF_SLOT_NUMBER_UNKNOWN     = &HFFFFFFFF???  '  ((ULONG)(-1))
%NIIF_FUNCTION_NUMBER_UNKNOWN = &HFFFFFFFF???  '  ((ULONG)(-1))

TYPE NET_PHYSICAL_LOCATION_LH
    BusNumber      AS DWORD     ' Physical location
    SlotNumber     AS DWORD     ' ... for hardware
    FunctionNumber AS DWORD     ' ... devices.
END TYPE

'
' maximum string size in -wchar- units
'
%IF_MAX_STRING_SIZE = 256

TYPE IF_COUNTED_STRING_LH
    Length AS WORD  ' in -Bytes-
    STRING AS WSTRING * %IF_MAX_STRING_SIZE + 1
END TYPE

%IF_MAX_PHYS_ADDRESS_LENGTH = 32

TYPE IF_PHYSICAL_ADDRESS_LH
    Length  AS WORD
    Address AS STRING * %IF_MAX_PHYS_ADDRESS_LENGTH
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
TYPE NET_PHYSICAL_LOCATION
    NET_PHYSICAL_LOCATION_LH
END TYPE

TYPE IF_COUNTED_STRING
    IF_COUNTED_STRING_LH
END TYPE

TYPE IF_PHYSICAL_ADDRESS
    IF_PHYSICAL_ADDRESS_LH
END TYPE
#ENDIF


'
' IF_INDEX
'
' Define the interface index type.
' This type is not persistable.
' This must be unsigned (not an enum) to replace previous uses of
' an index that used a DWORD type.
'

MACRO IF_INDEX=NET_IFINDEX

%IFI_UNSPECIFIED = %NET_IFINDEX_UNSPECIFIED


'
' Get definitions for IFTYPE and IF_ACCESS_TYPE.
'
#INCLUDE "ipifcons.inc"


'
' Types of tunnels (sub-type of IF_TYPE when IF_TYPE is IF_TYPE_TUNNEL).
' See http:'www.iana.org/assignments/ianaiftype-mib.
'
MACRO TUNNEL_TYPE_enum=LONG
ENUM TUNNEL_TYPE SINGULAR
    TUNNEL_TYPE_NONE
    TUNNEL_TYPE_OTHER
    TUNNEL_TYPE_DIRECT
    TUNNEL_TYPE_6TO4    = 11
    TUNNEL_TYPE_ISATAP  = 13
    TUNNEL_TYPE_TEREDO
    TUNNEL_TYPE_IPHTTPS
END ENUM

'
' IF_ADMINISTRATIVE_STATE
'
' Datalink Interface Administrative State.
' Indicates whether the interface has been administratively enabled.
'

MACRO IF_ADMINISTRATIVE_STATE_enum=LONG
ENUM IF_ADMINISTRATIVE_STATE SINGULAR
    IF_ADMINISTRATIVE_DISABLED
    IF_ADMINISTRATIVE_ENABLED
    IF_ADMINISTRATIVE_DEMANDDIAL
END ENUM


'
' Note: Interface is Operational iff
' ((MediaSense is Connected) and (AdministrativeState is Enabled))
' or
' ((MediaSense is Connected) and (AdministrativeState is OnDemand))
'
' !Operational iff
' ((MediaSense != Connected) or (AdministrativeState is Disabled))
'

'
' OperStatus values from RFC 2863
'
MACRO IF_OPER_STATUS_enum=LONG
ENUM IF_OPER_STATUS SINGULAR
    IfOperStatusUp         = 1
    IfOperStatusDown
    IfOperStatusTesting
    IfOperStatusUnknown
    IfOperStatusDormant
    IfOperStatusNotPresent
    IfOperStatusLowerLayerDown
END ENUM

TYPE NDIS_INTERFACE_INFORMATION
    '
    '  rod fields
    '
    ifOperStatus           AS NET_IF_OPER_STATUS_enum
    ifOperStatusFlags      AS DWORD
    MediaConnectState      AS NET_IF_MEDIA_CONNECT_STATE_enum
    MediaDuplexState       AS NET_IF_MEDIA_DUPLEX_STATE_enum
    ifMtu                  AS DWORD
    ifPromiscuousMode      AS BYTE  ' BOOLEAN
    ifDeviceWakeUpEnable   AS BYTE  ' BOOLEAN
    XmitLinkSpeed          AS QUAD  ' ULONG64
    RcvLinkSpeed           AS QUAD  ' ULONG64

    ifLastChange           AS QUAD  ' ULONG64
    ifCounterDiscontinuityTime AS QUAD  ' ULONG64
    ifInUnknownProtos      AS QUAD  ' ULONG64

    '
    ' OID_GEN_STATISTICS
    '
    ifInDiscards           AS QUAD  ' ULONG64 ' OID_GEN_RCV_DISCARDS = OID_GEN_RCV_ERROR + OID_GEN_RCV_NO_BUFFER
    ifInErrors             AS QUAD  ' ULONG64 ' OID_GEN_RCV_ERROR
    ifHCInOctets           AS QUAD  ' ULONG64 ' OID_GEN_BYTES_RCV = OID_GEN_DIRECTED_BYTES_RCV + OID_GEN_MULTICAST_BYTES_RCV + OID_GEN_BROADCAST_BYTES_RCV
    ifHCInUcastPkts        AS QUAD  ' ULONG64 ' OID_GEN_DIRECTED_FRAMES_RCV
    ifHCInMulticastPkts    AS QUAD  ' ULONG64 ' OID_GEN_MULTICAST_FRAMES_RCV
    ifHCInBroadcastPkts    AS QUAD  ' ULONG64 ' OID_GEN_BROADCAST_FRAMES_RCV
    ifHCOutOctets          AS QUAD  ' ULONG64 ' OID_GEN_BYTES_XMIT = OID_GEN_DIRECTED_BYTES_XMIT + OID_GEN_MULTICAST_BYTES_XMIT + OID_GEN_BROADCAST_BYTES_XMIT
    ifHCOutUcastPkts       AS QUAD  ' ULONG64 ' OID_GEN_DIRECTED_FRAMES_XMIT
    ifHCOutMulticastPkts   AS QUAD  ' ULONG64 ' OID_GEN_MULTICAST_FRAMES_XMIT
    ifHCOutBroadcastPkts   AS QUAD  ' ULONG64 ' OID_GEN_BROADCAST_FRAMES_XMIT
    ifOutErrors            AS QUAD  ' ULONG64 ' OID_GEN_XMIT_ERROR
    ifOutDiscards          AS QUAD  ' ULONG64 ' OID_GEN_XMIT_DISCARDS
    ifHCInUcastOctets      AS QUAD  ' ULONG64 ' OID_GEN_DIRECTED_BYTES_RCV
    ifHCInMulticastOctets  AS QUAD  ' ULONG64 ' OID_GEN_MULTICAST_BYTES_RCV
    ifHCInBroadcastOctets  AS QUAD  ' ULONG64 ' OID_GEN_BROADCAST_BYTES_RCV
    ifHCOutUcastOctets     AS QUAD  ' ULONG64 ' OID_GEN_DIRECTED_BYTES_XMIT
    ifHCOutMulticastOctets AS QUAD  ' ULONG64 ' OID_GEN_MULTICAST_BYTES_XMIT
    ifHCOutBroadcastOctets AS QUAD  ' ULONG64 ' OID_GEN_BROADCAST_BYTES_XMIT
    CompartmentId          AS NET_IF_COMPARTMENT_ID
    SupportedStatistics    AS DWORD
END TYPE
