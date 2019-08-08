'------------------------------------------------------------------------------
'
'  WinDot11.inc - Definitions for native 802.11 miniport driver specifications.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from WinDot11.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WINDOT11_H = 1


#INCLUDE "ntddndis.inc"

#INCLUDE "WlanTypes.inc"

' These are needed for wlanapi.inc for pre-vista targets
TYPE DOT11_MAC_ADDRESS
    ucDot11MacAddress(5) AS BYTE
END TYPE

' A list of DOT11_MAC_ADDRESS
%DOT11_BSSID_LIST_REVISION_1 = 1
TYPE DOT11_BSSID_LIST
    HEADER             AS NDIS_OBJECT_HEADER
    uNumOfEntries      AS DWORD
    uTotalNumOfEntries AS DWORD
    BSSIDs(0)          AS DOT11_MAC_ADDRESS
END TYPE

MACRO DOT11_PHY_TYPE_enum=LONG
ENUM DOT11_PHY_TYPE SINGULAR
    dot11_phy_type_unknown    = 0
    dot11_phy_type_any        = %dot11_phy_type_unknown
    dot11_phy_type_fhss       = 1
    dot11_phy_type_dsss
    dot11_phy_type_irbaseband
    dot11_phy_type_ofdm
    dot11_phy_type_hrdsss
    dot11_phy_type_erp
    dot11_phy_type_ht
    dot11_phy_type_IHV_start  = &H080000000
    dot11_phy_type_IHV_end    = &H0ffffffff
END ENUM

%DOT11_RATE_SET_MAX_LENGTH = 126 ' 126 bytes

TYPE DOT11_RATE_SET
    uRateSetLength AS DWORD
    ucRateSet(%DOT11_RATE_SET_MAX_LENGTH-1) AS BYTE
END TYPE

'MACRO DOT11_COUNTRY_OR_REGION_STRING=STRING * 3


#IF (%NTDDI_VERSION >= %NTDDI_WIN7 OR %NDIS_SUPPORT_NDIS620)
%NWF_EXTAP_SUPPORTED = 1
%NWF_VWIFI_SUPPORTED = 1
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WIN7 OR %NDIS_SUPPORT_NDIS620)


#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

' ntddndis.h: new Flags for OID_GEN_CURRENT_PACKET_FILTER
%NDIS_PACKET_TYPE_MEDIA_SPECIFIC_MASK       = &H0fff0000???
    ' Mask for media specific packet filters

%NDIS_PACKET_TYPE_802_11_DIRECTED_DATA      = %NDIS_PACKET_TYPE_DIRECTED

%NDIS_PACKET_TYPE_802_11_BROADCAST_DATA     = %NDIS_PACKET_TYPE_BROADCAST

%NDIS_PACKET_TYPE_802_11_MULTICAST_DATA     = %NDIS_PACKET_TYPE_MULTICAST

%NDIS_PACKET_TYPE_802_11_ALL_MULTICAST_DATA = %NDIS_PACKET_TYPE_ALL_MULTICAST

%NDIS_PACKET_TYPE_802_11_PROMISCUOUS_DATA   = %NDIS_PACKET_TYPE_PROMISCUOUS

%NDIS_PACKET_TYPE_802_11_RAW_DATA           = &H00010000???
    ' Raw 802.11 data packets (MPDU)

%NDIS_PACKET_TYPE_802_11_DIRECTED_MGMT      = &H00020000???
    ' Directed management packet

%NDIS_PACKET_TYPE_802_11_BROADCAST_MGMT     = &H00040000???
    ' Broadcast management packet

%NDIS_PACKET_TYPE_802_11_MULTICAST_MGMT     = &H00080000???
    ' Multicast management packet

%NDIS_PACKET_TYPE_802_11_ALL_MULTICAST_MGMT = &H00100000???
    ' All-multicast management packet

%NDIS_PACKET_TYPE_802_11_PROMISCUOUS_MGMT   = &H00200000???
    ' Promiscuous management packet

%NDIS_PACKET_TYPE_802_11_RAW_MGMT           = &H00400000???
    ' Raw management packet

%NDIS_PACKET_TYPE_802_11_DIRECTED_CTRL      = &H00800000???
    ' Directed CTRL packet

%NDIS_PACKET_TYPE_802_11_BROADCAST_CTRL     = &H01000000???
    ' Broadcast CTRL packet

%NDIS_PACKET_TYPE_802_11_PROMISCUOUS_CTRL   = &H02000000???
    ' Promiscuous CTRL packet

%NDIS_PACKET_TYPE_ALL_802_11_FILTERS =       _
    (%NDIS_PACKET_TYPE_DIRECTED OR                    _
     %NDIS_PACKET_TYPE_MULTICAST OR                   _
     %NDIS_PACKET_TYPE_ALL_MULTICAST OR               _
     %NDIS_PACKET_TYPE_BROADCAST OR                   _
     %NDIS_PACKET_TYPE_PROMISCUOUS OR                 _
     %NDIS_PACKET_TYPE_802_11_RAW_DATA OR             _
     %NDIS_PACKET_TYPE_802_11_DIRECTED_MGMT OR        _
     %NDIS_PACKET_TYPE_802_11_BROADCAST_MGMT OR       _
     %NDIS_PACKET_TYPE_802_11_MULTICAST_MGMT OR       _
     %NDIS_PACKET_TYPE_802_11_ALL_MULTICAST_MGMT OR   _
     %NDIS_PACKET_TYPE_802_11_PROMISCUOUS_MGMT OR     _
     %NDIS_PACKET_TYPE_802_11_RAW_MGMT OR             _
     %NDIS_PACKET_TYPE_802_11_DIRECTED_CTRL OR        _
     %NDIS_PACKET_TYPE_802_11_BROADCAST_CTRL OR       _
     %NDIS_PACKET_TYPE_802_11_PROMISCUOUS_CTRL)


'
' Max size of an 802.11 PDU, including the MAC header, frame body and FCS.
'
%DOT11_MAX_PDU_SIZE                        = 2346

'
' Min size of an 802.11 PDU, including the MAC header, frame body and FCS.
'
%DOT11_MIN_PDU_SIZE                        = (256)

%DOT11_MAX_NUM_DEFAULT_KEY                 = 4

' Macros for defining native 802.11 OIDs
%OID_DOT11_NDIS_START                      = &H0D010300

%NWF_MANDATORY_OID     = (&H01)
%NWF_OPTIONAL_OID      = (&H02)

%NWF_OPERATIONAL_OID   = (&H01)
%NWF_STATISTICS_OID    = (&H02)

MACRO FUNCTION NWF_DEFINE_OID(Seq,o,m)
    MACROTEMP d1,d2
    LOCAL d1, d2 AS DWORD
    d1 = o
    SHIFT LEFT d1, 16
    d2 = m
    SHIFT LEFT d2, 8
END MACRO=(d1 OR d2 OR Seq OR &H0E000000)

'
' Offload Capability OIDs
'

%OID_DOT11_OFFLOAD_CAPABILITY              = (%OID_DOT11_NDIS_START + 0)

' Capability flags
%DOT11_HW_WEP_SUPPORTED_TX            = &H00000001
%DOT11_HW_WEP_SUPPORTED_RX            = &H00000002
%DOT11_HW_FRAGMENTATION_SUPPORTED     = &H00000004
%DOT11_HW_DEFRAGMENTATION_SUPPORTED   = &H00000008
%DOT11_HW_MSDU_AUTH_SUPPORTED_TX      = &H00000010
%DOT11_HW_MSDU_AUTH_SUPPORTED_RX      = &H00000020
' WEP Algorithm flags
%DOT11_CONF_ALGO_WEP_RC4              = &H00000001  ' WEP RC4
%DOT11_CONF_ALGO_TKIP                 = &H00000002
' Integrity Algorithm flags
%DOT11_AUTH_ALGO_MICHAEL              = &H00000001  ' Michael

TYPE DOT11_OFFLOAD_CAPABILITY
    uReserved                AS DWORD
    uFlags                   AS DWORD
    uSupportedWEPAlgorithms  AS DWORD
    uNumOfReplayWindows      AS DWORD
    uMaxWEPKeyMappingLength  AS DWORD
    uSupportedAuthAlgorithms AS DWORD
    uMaxAuthKeyMappingLength AS DWORD
END TYPE

%OID_DOT11_CURRENT_OFFLOAD_CAPABILITY      = (%OID_DOT11_NDIS_START + 1)

TYPE DOT11_CURRENT_OFFLOAD_CAPABILITY
    uReserved AS DWORD
    uFlags    AS DWORD
END TYPE


'
' WEP Offload
'

%OID_DOT11_WEP_OFFLOAD                     = (%OID_DOT11_NDIS_START + 2)

MACRO DOT11_OFFLOAD_TYPE_enum=LONG
ENUM DOT11_OFFLOAD_TYPE SINGULAR
    dot11_offload_type_wep  = 1
    dot11_offload_type_auth
END ENUM

TYPE DOT11_IV48_COUNTER
    uIV32Counter  AS DWORD
    usIV16Counter AS WORD
END TYPE

TYPE DOT11_WEP_OFFLOAD
    uReserved             AS DWORD
    hOffloadContext       AS DWORD   ' HANDLE
    hOffload              AS DWORD   ' HANDLE
    dot11OffloadType      AS DOT11_OFFLOAD_TYPE_enum
    dwAlgorithm           AS DWORD
    bRowIsOutbound        AS BYTE    ' BOOLEAN
    bUseDefault           AS BYTE    ' BOOLEAN
    uFlags                AS DWORD
    ucMacAddress(5)       AS BYTE    ' UCHAR
    uNumOfRWsOnPeer       AS DWORD
    uNumOfRWsOnMe         AS DWORD
    dot11IV48Counters(15) AS DOT11_IV48_COUNTER
    usDot11RWBitMaps(15)  AS WORD
    usKeyLength           AS WORD
    ucKey(0)              AS BYTE    ' UCHAR  ' Must be the last field.
END TYPE

%OID_DOT11_WEP_UPLOAD                      = (%OID_DOT11_NDIS_START + 3)

TYPE DOT11_WEP_UPLOAD
    uReserved             AS DWORD
    dot11OffloadType      AS DOT11_OFFLOAD_TYPE_enum
    hOffload              AS DWORD   ' HANDLE
    uNumOfRWsUsed         AS DWORD
    dot11IV48Counters(15) AS DOT11_IV48_COUNTER
    usDot11RWBitMaps(15)  AS WORD
END TYPE

%OID_DOT11_DEFAULT_WEP_OFFLOAD             = (%OID_DOT11_NDIS_START + 4)

MACRO DOT11_KEY_DIRECTION_enum=LONG
ENUM DOT11_KEY_DIRECTION SINGULAR
    dot11_key_direction_both     = 1
    dot11_key_direction_inbound
    dot11_key_direction_outbound
END ENUM

TYPE DOT11_DEFAULT_WEP_OFFLOAD
    uReserved             AS DWORD
    hOffloadContext       AS DWORD   ' HANDLE
    hOffload              AS DWORD   ' HANDLE
    dwIndex               AS DWORD
    dot11OffloadType      AS DOT11_OFFLOAD_TYPE_enum
    dwAlgorithm           AS DWORD
    uFlags                AS DWORD
    dot11KeyDirection     AS DOT11_KEY_DIRECTION_enum
    ucMacAddress(5)       AS BYTE    ' UCHAR
    uNumOfRWsOnMe         AS DWORD
    dot11IV48Counters(15) AS DOT11_IV48_COUNTER
    usDot11RWBitMaps(15)  AS WORD
    usKeyLength           AS WORD
    ucKey(0)              AS BYTE    ' UCHAR  ' Must be the last field.
END TYPE

%OID_DOT11_DEFAULT_WEP_UPLOAD              = (%OID_DOT11_NDIS_START + 5)

TYPE DOT11_DEFAULT_WEP_UPLOAD
    uReserved             AS DWORD
    dot11OffloadType      AS DOT11_OFFLOAD_TYPE_enum
    hOffload              AS DWORD   ' HANDLE
    uNumOfRWsUsed         AS DWORD
    dot11IV48Counters(15) AS DOT11_IV48_COUNTER
    usDot11RWBitMaps(15)  AS WORD
END TYPE

'
' Fragmentation/Defragmentation Offload
'

%OID_DOT11_MPDU_MAX_LENGTH                 = (%OID_DOT11_NDIS_START + 6)
    ' DWORD (in bytes)

'
' 802.11 Configuration OIDs
'

'
' OIDs for Mandatory Functions
'

%OID_DOT11_OPERATION_MODE_CAPABILITY       = (%OID_DOT11_NDIS_START + 7)

%DOT11_OPERATION_MODE_UNKNOWN            = &H00000000
%DOT11_OPERATION_MODE_STATION            = &H00000001
%DOT11_OPERATION_MODE_AP                 = &H00000002
%DOT11_OPERATION_MODE_EXTENSIBLE_STATION = &H00000004
%DOT11_OPERATION_MODE_EXTENSIBLE_AP      = &H00000008
%DOT11_OPERATION_MODE_NETWORK_MONITOR    = &H80000000???

TYPE DOT11_OPERATION_MODE_CAPABILITY
    uReserved         AS DWORD
    uMajorVersion     AS DWORD
    uMinorVersion     AS DWORD
    uNumOfTXBuffers   AS DWORD
    uNumOfRXBuffers   AS DWORD
    uOpModeCapability AS DWORD
END TYPE

%OID_DOT11_CURRENT_OPERATION_MODE          = (%OID_DOT11_NDIS_START + 8)

TYPE DOT11_CURRENT_OPERATION_MODE
    uReserved      AS DWORD
    uCurrentOpMode AS DWORD
END TYPE

%OID_DOT11_CURRENT_PACKET_FILTER           = (%OID_DOT11_NDIS_START + 9)

%DOT11_PACKET_TYPE_DIRECTED_CTRL         = &H00000001
' Indicate all 802.11 unicast control packets.
%DOT11_PACKET_TYPE_DIRECTED_MGMT         = &H00000002
' Indicate all 802.11 unicast management packets.
%DOT11_PACKET_TYPE_DIRECTED_DATA         = &H00000004
' Indicate all 802.11 unicast data packets.
%DOT11_PACKET_TYPE_MULTICAST_CTRL        = &H00000008
' Indicate all 802.11 multicast control packets.
%DOT11_PACKET_TYPE_MULTICAST_MGMT        = &H00000010
' Indicate all 802.11 multicast management packets.
%DOT11_PACKET_TYPE_MULTICAST_DATA        = &H00000020
' Indicate all 802.11 multicast data packets.
%DOT11_PACKET_TYPE_BROADCAST_CTRL        = &H00000040
' Indicate all 802.11 broadcast control packets.
%DOT11_PACKET_TYPE_BROADCAST_MGMT        = &H00000080
' Indicate all 802.11 broadcast management packets.
%DOT11_PACKET_TYPE_BROADCAST_DATA        = &H00000100
' Indicate all 802.11 broadcast data packets.
%DOT11_PACKET_TYPE_PROMISCUOUS_CTRL      = &H00000200
' Move into promiscuous mode and indicate all 802.11 control packets.
%DOT11_PACKET_TYPE_PROMISCUOUS_MGMT      = &H00000400
' Move into promiscuous mode and indicate all 802.11 control packets.
%DOT11_PACKET_TYPE_PROMISCUOUS_DATA      = &H00000800
' Move into promiscuous mode and indicate all 802.11 control packets.
%DOT11_PACKET_TYPE_ALL_MULTICAST_CTRL    = &H00001000
' Indicate all 802.11 multicast control packets.
%DOT11_PACKET_TYPE_ALL_MULTICAST_MGMT    = &H00002000
' Indicate all 802.11 multicast management packets.
%DOT11_PACKET_TYPE_ALL_MULTICAST_DATA    = &H00004000
' Indicate all 802.11 multicast data packets.
%DOT11_PACKET_TYPE_RESERVED = (NOT (             _
        %DOT11_PACKET_TYPE_DIRECTED_CTRL OR       _
        %DOT11_PACKET_TYPE_DIRECTED_MGMT OR       _
        %DOT11_PACKET_TYPE_DIRECTED_DATA OR       _
        %DOT11_PACKET_TYPE_MULTICAST_CTRL OR      _
        %DOT11_PACKET_TYPE_MULTICAST_MGMT OR      _
        %DOT11_PACKET_TYPE_MULTICAST_DATA OR      _
        %DOT11_PACKET_TYPE_BROADCAST_CTRL OR      _
        %DOT11_PACKET_TYPE_BROADCAST_MGMT OR      _
        %DOT11_PACKET_TYPE_BROADCAST_DATA OR      _
        %DOT11_PACKET_TYPE_PROMISCUOUS_CTRL OR    _
        %DOT11_PACKET_TYPE_PROMISCUOUS_MGMT OR    _
        %DOT11_PACKET_TYPE_PROMISCUOUS_DATA OR    _
        %DOT11_PACKET_TYPE_ALL_MULTICAST_CTRL OR  _
        %DOT11_PACKET_TYPE_ALL_MULTICAST_MGMT OR  _
        %DOT11_PACKET_TYPE_ALL_MULTICAST_DATA OR  _
        0))
' All the reserved bits

%OID_DOT11_ATIM_WINDOW                     = (%OID_DOT11_NDIS_START + 10)

' DWORD (in TUs)

%OID_DOT11_SCAN_REQUEST                    = (%OID_DOT11_NDIS_START + 11)

MACRO DOT11_SCAN_TYPE_enum=LONG
ENUM DOT11_SCAN_TYPE SINGULAR
    dot11_scan_type_active  = 1
    dot11_scan_type_passive
    dot11_scan_type_auto
    dot11_scan_type_forced  = &H080000000
END ENUM

TYPE DOT11_SCAN_REQUEST
    dot11BSSType      AS DOT11_BSS_TYPE_enum
    dot11BSSID        AS DOT11_MAC_ADDRESS
    dot11SSID         AS DOT11_SSID
    dot11ScanType     AS DOT11_SCAN_TYPE_enum
    bRestrictedScan   AS BYTE   ' BOOLEAN
    bUseRequestIE     AS BYTE   ' BOOLEAN
    uRequestIDsOffset AS DWORD
    uNumOfRequestIDs  AS DWORD
    uPhyTypesOffset   AS DWORD
    uNumOfPhyTypes    AS DWORD
    uIEsOffset        AS DWORD
    uIEsLength        AS DWORD
    ucBuffer(0)       AS BYTE   ' UCHAR
END TYPE

' V2 SCAN REQUEST
MACRO CH_DESCRIPTION_TYPE_enum=LONG
ENUM CH_DESCRIPTION_TYPE SINGULAR
    ch_description_type_logical          = 1
    ch_description_type_center_frequency
    ch_description_type_phy_specific
END ENUM

TYPE DOT11_PHY_TYPE_INFO
    dot11PhyType           AS DOT11_PHY_TYPE_enum
    bUseParameters         AS BYTE   ' BOOLEAN
    uProbeDelay            AS DWORD
    uMinChannelTime        AS DWORD
    uMaxChannelTime        AS DWORD
    ChDescriptionType      AS CH_DESCRIPTION_TYPE_enum
    uChannelListSize       AS DWORD
    ucChannelListBuffer(0) AS BYTE   ' UCHAR
END TYPE

TYPE DOT11_SCAN_REQUEST_V2
    dot11BSSType        AS DOT11_BSS_TYPE_enum
    dot11BSSID          AS DOT11_MAC_ADDRESS
    dot11ScanType       AS DOT11_SCAN_TYPE_enum
    bRestrictedScan     AS BYTE   ' BOOLEAN
    udot11SSIDsOffset   AS DWORD
    uNumOfdot11SSIDs    AS DWORD
    bUseRequestIE       AS BYTE   ' BOOLEAN
    uRequestIDsOffset   AS DWORD
    uNumOfRequestIDs    AS DWORD
    uPhyTypeInfosOffset AS DWORD
    uNumOfPhyTypeInfos  AS DWORD
    uIEsOffset          AS DWORD
    uIEsLength          AS DWORD
    ucBuffer(0)         AS BYTE   ' UCHAR
END TYPE

%OID_DOT11_CURRENT_PHY_TYPE                = (%OID_DOT11_NDIS_START + 12)

%DOT11_PHY_TYPE_LIST_REVISION_1         =  1

TYPE DOT11_PHY_TYPE_LIST
    HEADER             AS NDIS_OBJECT_HEADER
    uNumOfEntries      AS DWORD
    uTotalNumOfEntries AS DWORD
    dot11PhyType(0)    AS DOT11_PHY_TYPE_enum
END TYPE

%OID_DOT11_JOIN_REQUEST                    = (%OID_DOT11_NDIS_START + 13)

' Capability Information Flags - Exactly maps to the bit positions
' in the Capability Information field of the beacon and probe response frames.
%DOT11_CAPABILITY_INFO_ESS               = &H0001
%DOT11_CAPABILITY_INFO_IBSS              = &H0002
%DOT11_CAPABILITY_INFO_CF_POLLABLE       = &H0004
%DOT11_CAPABILITY_INFO_CF_POLL_REQ       = &H0008
%DOT11_CAPABILITY_INFO_PRIVACY           = &H0010
%DOT11_CAPABILITY_SHORT_PREAMBLE         = &H0020
%DOT11_CAPABILITY_PBCC                   = &H0040
%DOT11_CAPABILITY_CHANNEL_AGILITY        = &H0080
%DOT11_CAPABILITY_SHORT_SLOT_TIME        = &H0400
%DOT11_CAPABILITY_DSSSOFDM               = &H2000

TYPE DOT11_BSS_DESCRIPTION
    uReserved               AS DWORD   ' Passed-in as 0 and must be ignored for now.
    dot11BSSID              AS DOT11_MAC_ADDRESS
    dot11BSSType            AS DOT11_BSS_TYPE_enum
    usBeaconPeriod          AS WORD
    ullTimestamp            AS QUAD    ' ULONGLONG
    usCapabilityInformation AS WORD
    uBufferLength           AS DWORD
    ucBuffer(0)             AS BYTE    ' UCHAR  ' Must be the last field.
END TYPE

TYPE DOT11_JOIN_REQUEST
    uJoinFailureTimeout AS DWORD
    OperationalRateSet  AS DOT11_RATE_SET
    uChCenterFrequency  AS DWORD
    dot11BSSDescription AS DOT11_BSS_DESCRIPTION   ' Must be the last field.
END TYPE

%OID_DOT11_START_REQUEST                   = (%OID_DOT11_NDIS_START + 14)

TYPE DOT11_START_REQUEST
    uStartFailureTimeout AS DWORD
    OperationalRateSet   AS DOT11_RATE_SET
    uChCenterFrequency   AS DWORD
    dot11BSSDescription  AS DOT11_BSS_DESCRIPTION   ' Must be the last field.
END TYPE

%OID_DOT11_UPDATE_IE                       = (%OID_DOT11_NDIS_START + 15)

MACRO DOT11_UPDATE_IE_OP_enum=LONG
ENUM DOT11_UPDATE_IE_OP SINGULAR
    dot11_update_ie_op_create_replace = 1
    dot11_update_ie_op_delete
END ENUM

TYPE DOT11_UPDATE_IE
    dot11UpdateIEOp AS DOT11_UPDATE_IE_OP_enum
    uBufferLength   AS DWORD
    ucBuffer(0)     AS BYTE   ' UCHAR ' Must be the last field.
END TYPE

%OID_DOT11_RESET_REQUEST                   = (%OID_DOT11_NDIS_START + 16)

MACRO DOT11_RESET_TYPE_enum=LONG
ENUM DOT11_RESET_TYPE SINGULAR
    dot11_reset_type_phy         = 1
    dot11_reset_type_mac
    dot11_reset_type_phy_and_mac
END ENUM

TYPE DOT11_RESET_REQUEST
    dot11ResetType  AS DOT11_RESET_TYPE_enum
    dot11MacAddress AS DOT11_MAC_ADDRESS
    bSetDefaultMIB  AS BYTE   ' BOOLEAN
END TYPE

%OID_DOT11_NIC_POWER_STATE                 = (%OID_DOT11_NDIS_START + 17)
    ' BOOL

'
' OIDs for Optional Functions
'

%OID_DOT11_OPTIONAL_CAPABILITY             = (%OID_DOT11_NDIS_START + 18)

TYPE DOT11_OPTIONAL_CAPABILITY
    uReserved                    AS DWORD
    bDot11PCF                    AS BYTE   ' BOOLEAN
    bDot11PCFMPDUTransferToPC    AS BYTE   ' BOOLEAN
    bStrictlyOrderedServiceClass AS BYTE   ' BOOLEAN
END TYPE

%OID_DOT11_CURRENT_OPTIONAL_CAPABILITY     = (%OID_DOT11_NDIS_START + 19)

TYPE DOT11_CURRENT_OPTIONAL_CAPABILITY
    uReserved                    AS DWORD
    bDot11CFPollable             AS BYTE   ' BOOLEAN
    bDot11PCF                    AS BYTE   ' BOOLEAN
    bDot11PCFMPDUTransferToPC    AS BYTE   ' BOOLEAN
    bStrictlyOrderedServiceClass AS BYTE   ' BOOLEAN
END TYPE

'
' 802.11 MIB OIDs
'

'
' OIDs for dot11StationConfigEntry
'

%OID_DOT11_STATION_ID                      = (%OID_DOT11_NDIS_START + 20)
' DOT11_MAC_ADDRESS

%OID_DOT11_MEDIUM_OCCUPANCY_LIMIT          = (%OID_DOT11_NDIS_START + 21)
' DWORD (in TUs)

%OID_DOT11_CF_POLLABLE                     = (%OID_DOT11_NDIS_START + 22)
' BOOL

%OID_DOT11_CFP_PERIOD                      = (%OID_DOT11_NDIS_START + 23)
' DWORD (in DTIM intervals)

%OID_DOT11_CFP_MAX_DURATION                = (%OID_DOT11_NDIS_START + 24)
' DWORD (in TUs)

%OID_DOT11_POWER_MGMT_MODE                 = (%OID_DOT11_NDIS_START + 25)

MACRO DOT11_POWER_MODE_enum=LONG
ENUM DOT11_POWER_MODE SINGULAR
    dot11_power_mode_unknown
    dot11_power_mode_active
    dot11_power_mode_powersave
END ENUM

%DOT11_POWER_SAVE_LEVEL_MAX_PSP     =  1

' Maximum power save polling.
%DOT11_POWER_SAVE_LEVEL_FAST_PSP    =  2

' Fast power save polling.
TYPE DOT11_POWER_MGMT_MODE
    dot11PowerMode   AS DOT11_POWER_MODE_enum
    uPowerSaveLevel  AS DWORD
    usListenInterval AS WORD
    usAID            AS WORD
    bReceiveDTIMs    AS BYTE   ' BOOLEAN
END TYPE

%OID_DOT11_OPERATIONAL_RATE_SET            = (%OID_DOT11_NDIS_START + 26)
' DOT11_RATE_SET

%OID_DOT11_BEACON_PERIOD                   = (%OID_DOT11_NDIS_START + 27)
' DWORD (in TUs)

%OID_DOT11_DTIM_PERIOD                     = (%OID_DOT11_NDIS_START + 28)
' DWORD (in beacon intervals)

'
' OIDs for Dot11PrivacyEntry
'

%OID_DOT11_WEP_ICV_ERROR_COUNT             = (%OID_DOT11_NDIS_START + 29)
' DWORD

'
' OIDs for dot11OperationEntry
'

%OID_DOT11_MAC_ADDRESS                     = (%OID_DOT11_NDIS_START + 30)
' DOT11_MAC_ADDRESS

%OID_DOT11_RTS_THRESHOLD                   = (%OID_DOT11_NDIS_START + 31)
' DWORD (in number of octets)

%OID_DOT11_SHORT_RETRY_LIMIT               = (%OID_DOT11_NDIS_START + 32)
' DWORD

%OID_DOT11_LONG_RETRY_LIMIT                = (%OID_DOT11_NDIS_START + 33)
' DWORD

%OID_DOT11_FRAGMENTATION_THRESHOLD         = (%OID_DOT11_NDIS_START + 34)
' DWORD (in number of octets)

%OID_DOT11_MAX_TRANSMIT_MSDU_LIFETIME      = (%OID_DOT11_NDIS_START + 35)
' DWORD (in TUs)

%OID_DOT11_MAX_RECEIVE_LIFETIME            = (%OID_DOT11_NDIS_START + 36)
    ' DWORD (in TUs)

'
' OIDs for dot11CountersEntry
'

%OID_DOT11_COUNTERS_ENTRY                  = (%OID_DOT11_NDIS_START + 37)

TYPE DOT11_COUNTERS_ENTRY
    uTransmittedFragmentCount       AS DWORD
    uMulticastTransmittedFrameCount AS DWORD
    uFailedCount                    AS DWORD
    uRetryCount                     AS DWORD
    uMultipleRetryCount             AS DWORD
    uFrameDuplicateCount            AS DWORD
    uRTSSuccessCount                AS DWORD
    uRTSFailureCount                AS DWORD
    uACKFailureCount                AS DWORD
    uReceivedFragmentCount          AS DWORD
    uMulticastReceivedFrameCount    AS DWORD
    uFCSErrorCount                  AS DWORD
    uTransmittedFrameCount          AS DWORD
END TYPE

'
' OIDs for dot11PhyOperationEntry
'

%OID_DOT11_SUPPORTED_PHY_TYPES             = (%OID_DOT11_NDIS_START + 38)

TYPE DOT11_SUPPORTED_PHY_TYPES
    uNumOfEntries      AS DWORD
    uTotalNumOfEntries AS DWORD
    dot11PHYType(0)    AS DOT11_PHY_TYPE_enum
END TYPE

%OID_DOT11_CURRENT_REG_DOMAIN              = (%OID_DOT11_NDIS_START + 39)

%DOT11_REG_DOMAIN_OTHER                  = &H00000000
%DOT11_REG_DOMAIN_FCC                    = &H00000010
%DOT11_REG_DOMAIN_DOC                    = &H00000020
%DOT11_REG_DOMAIN_ETSI                   = &H00000030
%DOT11_REG_DOMAIN_SPAIN                  = &H00000031
%DOT11_REG_DOMAIN_FRANCE                 = &H00000032
%DOT11_REG_DOMAIN_MKK                    = &H00000040
' DWORD

%OID_DOT11_TEMP_TYPE                       = (%OID_DOT11_NDIS_START + 40)

MACRO DOT11_TEMP_TYPE_enum=LONG
ENUM DOT11_TEMP_TYPE SINGULAR
    dot11_temp_type_unknown
    dot11_temp_type_1
    dot11_temp_type_2
END ENUM

'
' OIDs for dot11PhyAntennaEntry
'

%OID_DOT11_CURRENT_TX_ANTENNA              = (%OID_DOT11_NDIS_START + 41)
' DWORD

%OID_DOT11_DIVERSITY_SUPPORT               = (%OID_DOT11_NDIS_START + 42)

MACRO DOT11_DIVERSITY_SUPPORT_enum=LONG
ENUM DOT11_DIVERSITY_SUPPORT SINGULAR
    dot11_diversity_support_unknown
    dot11_diversity_support_fixedlist
    dot11_diversity_support_notsupported
    dot11_diversity_support_dynamic
END ENUM

%OID_DOT11_CURRENT_RX_ANTENNA              = (%OID_DOT11_NDIS_START + 43)
' DWORD

'
' OIDs for dot11PhyTxPowerEntry
'

%OID_DOT11_SUPPORTED_POWER_LEVELS          = (%OID_DOT11_NDIS_START + 44)

TYPE DOT11_SUPPORTED_POWER_LEVELS
    uNumOfSupportedPowerLevels AS DWORD
    uTxPowerLevelValues(7)     AS DWORD
END TYPE

%OID_DOT11_CURRENT_TX_POWER_LEVEL          = (%OID_DOT11_NDIS_START + 45)
' DWORD

'
' OIDs for dot11PhyFHSSEntry
'

%OID_DOT11_HOP_TIME                        = (%OID_DOT11_NDIS_START + 46)
' DWORD (in microseconds)

%OID_DOT11_CURRENT_CHANNEL_NUMBER          = (%OID_DOT11_NDIS_START + 47)
' DWORD

%OID_DOT11_MAX_DWELL_TIME                  = (%OID_DOT11_NDIS_START + 48)
' DWORD (in TUs)

%OID_DOT11_CURRENT_DWELL_TIME              = (%OID_DOT11_NDIS_START + 49)
' DWORD (in TUs)

%OID_DOT11_CURRENT_SET                     = (%OID_DOT11_NDIS_START + 50)
' DWORD

%OID_DOT11_CURRENT_PATTERN                 = (%OID_DOT11_NDIS_START + 51)
' DWORD

%OID_DOT11_CURRENT_INDEX                   = (%OID_DOT11_NDIS_START + 52)
' DWORD

'
' OIDs for dot11PhyDSSSEntry
'

%OID_DOT11_CURRENT_CHANNEL                 = (%OID_DOT11_NDIS_START + 53)
' DWORD

%OID_DOT11_CCA_MODE_SUPPORTED              = (%OID_DOT11_NDIS_START + 54)

%DOT11_CCA_MODE_ED_ONLY                  = &H00000001
%DOT11_CCA_MODE_CS_ONLY                  = &H00000002
%DOT11_CCA_MODE_ED_and_CS                = &H00000004
%DOT11_CCA_MODE_CS_WITH_TIMER            = &H00000008
%DOT11_CCA_MODE_HRCS_AND_ED              = &H00000010

' DWORD

%OID_DOT11_CURRENT_CCA_MODE                = (%OID_DOT11_NDIS_START + 55)
' DWORD

%OID_DOT11_ED_THRESHOLD                    = (%OID_DOT11_NDIS_START + 56)
' LONG (in "dBm"s)

'
' OIDs for dot11PhyIREntry
'

%OID_DOT11_CCA_WATCHDOG_TIMER_MAX          = (%OID_DOT11_NDIS_START + 57)
' DWORD (in nanoseconds)

%OID_DOT11_CCA_WATCHDOG_COUNT_MAX          = (%OID_DOT11_NDIS_START + 58)
' DWORD

%OID_DOT11_CCA_WATCHDOG_TIMER_MIN          = (%OID_DOT11_NDIS_START + 59)
' DWORD (in nanoseconds)

%OID_DOT11_CCA_WATCHDOG_COUNT_MIN          = (%OID_DOT11_NDIS_START + 60)
' DWORD

'
' OIDs for dot11RegDomainsSupportEntry
'

%OID_DOT11_REG_DOMAINS_SUPPORT_VALUE       = (%OID_DOT11_NDIS_START + 61)

TYPE DOT11_REG_DOMAIN_VALUE
    uRegDomainsSupportIndex AS DWORD
    uRegDomainsSupportValue AS DWORD
END TYPE

TYPE DOT11_REG_DOMAINS_SUPPORT_VALUE
    uNumOfEntries          AS DWORD
    uTotalNumOfEntries     AS DWORD
    dot11RegDomainValue(0) AS DOT11_REG_DOMAIN_VALUE
END TYPE

'
' OIDs for dot11AntennaListEntry
'

%OID_DOT11_SUPPORTED_TX_ANTENNA            = (%OID_DOT11_NDIS_START + 62)

TYPE DOT11_SUPPORTED_ANTENNA
    uAntennaListIndex AS DWORD                     ' Between 1 and 255.
    bSupportedAntenna AS BYTE   ' BOOLEAN
END TYPE

TYPE DOT11_SUPPORTED_ANTENNA_LIST
    uNumOfEntries            AS DWORD
    uTotalNumOfEntries       AS DWORD
    dot11SupportedAntenna(0) AS DOT11_SUPPORTED_ANTENNA
END TYPE

%OID_DOT11_SUPPORTED_RX_ANTENNA            = (%OID_DOT11_NDIS_START + 63)
' DOT11_SUPPORTED_ANTENNA_LIST

%OID_DOT11_DIVERSITY_SELECTION_RX          = (%OID_DOT11_NDIS_START + 64)

TYPE DOT11_DIVERSITY_SELECTION_RX
    uAntennaListIndex     AS DWORD   ' Between 1 and 255.
    bDiversitySelectionRX AS BYTE    ' BOOLEAN
END TYPE

TYPE DOT11_DIVERSITY_SELECTION_RX_LIST
    uNumOfEntries                AS DWORD
    uTotalNumOfEntries           AS DWORD
    dot11DiversitySelectionRx(0) AS DOT11_DIVERSITY_SELECTION_RX
END TYPE

'
' OIDs for dot11SupportedDataRatesTxEntry and dot11SupportedDataRatesRxEntry
'

%OID_DOT11_SUPPORTED_DATA_RATES_VALUE      = (%OID_DOT11_NDIS_START + 65)

%MAX_NUM_SUPPORTED_RATES                =  8       ' 8 data rates
%MAX_NUM_SUPPORTED_RATES_V2             =  255     ' 255 data rates

TYPE DOT11_SUPPORTED_DATA_RATES_VALUE
    ucSupportedTxDataRatesValue(%MAX_NUM_SUPPORTED_RATES-1) AS BYTE   ' UCHAR
    ucSupportedRxDataRatesValue(%MAX_NUM_SUPPORTED_RATES-1) AS BYTE   ' UCHAR
END TYPE

TYPE DOT11_SUPPORTED_DATA_RATES_VALUE_V2
    ucSupportedTxDataRatesValue(%MAX_NUM_SUPPORTED_RATES_V2-1) AS BYTE  ' UCHAR
    ucSupportedRxDataRatesValue(%MAX_NUM_SUPPORTED_RATES_V2-1) AS BYTE  ' UCHAR
END TYPE

' keep the incorrect struct name to avoid build break
MACRO DOT11_SUPPORTED_DATA_RATES_VALUE_V1=DOT11_SUPPORTED_DATA_RATES_VALUE_V2

'
' OIDs for dot11PhyOFDMEntry
'

%OID_DOT11_CURRENT_FREQUENCY               = (%OID_DOT11_NDIS_START + 66)
' DWORD

%OID_DOT11_TI_THRESHOLD                    = (%OID_DOT11_NDIS_START + 67)
' LONG

%OID_DOT11_FREQUENCY_BANDS_SUPPORTED       = (%OID_DOT11_NDIS_START + 68)
%DOT11_FREQUENCY_BANDS_LOWER    = &H00000001
%DOT11_FREQUENCY_BANDS_MIDDLE   = &H00000002
%DOT11_FREQUENCY_BANDS_UPPER    = &H00000004
' DWORD

'
' OIDs for dot11PhyHRDSSSEntry
'

%OID_DOT11_SHORT_PREAMBLE_OPTION_IMPLEMENTD= (%OID_DOT11_NDIS_START + 69)
' BOOL

%OID_DOT11_PBCC_OPTION_IMPLEMENTED         = (%OID_DOT11_NDIS_START + 70)
' BOOL

%OID_DOT11_CHANNEL_AGILITY_PRESENT         = (%OID_DOT11_NDIS_START + 71)
' BOOL

%OID_DOT11_CHANNEL_AGILITY_ENABLED         = (%OID_DOT11_NDIS_START + 72)
' BOOL

%OID_DOT11_HR_CCA_MODE_SUPPORTED           = (%OID_DOT11_NDIS_START + 73)
' HR-CCA mode bits
%DOT11_HR_CCA_MODE_ED_ONLY        = &H00000001
%DOT11_HR_CCA_MODE_CS_ONLY        = &H00000002
%DOT11_HR_CCA_MODE_CS_AND_ED      = &H00000004
%DOT11_HR_CCA_MODE_CS_WITH_TIMER  = &H00000008
%DOT11_HR_CCA_MODE_HRCS_AND_ED    = &H00000010
' DWORD


'
' OIDs for dot11StationConfigEntry (Cont)
'

%OID_DOT11_MULTI_DOMAIN_CAPABILITY_IMPLEMENTED = (%OID_DOT11_NDIS_START + 74)
' BOOL

%OID_DOT11_MULTI_DOMAIN_CAPABILITY_ENABLED     = (%OID_DOT11_NDIS_START + 75)
' BOOL

%OID_DOT11_COUNTRY_STRING                      = (%OID_DOT11_NDIS_START + 76)
' UCHAR[3]

'
' OIDs for dot11MultiDomainCapabilityEntry
'

TYPE DOT11_MULTI_DOMAIN_CAPABILITY_ENTRY
    uMultiDomainCapabilityIndex AS DWORD
    uFirstChannelNumber         AS DWORD
    uNumberOfChannels           AS DWORD
    lMaximumTransmitPowerLevel  AS LONG
END TYPE

TYPE DOT11_MD_CAPABILITY_ENTRY_LIST
    uNumOfEntries             AS DWORD
    uTotalNumOfEntries        AS DWORD
    dot11MDCapabilityEntry(0) AS DOT11_MULTI_DOMAIN_CAPABILITY_ENTRY
END TYPE


%OID_DOT11_MULTI_DOMAIN_CAPABILITY         = (%OID_DOT11_NDIS_START + 77)
' DOT11_MD_CAPABILITY_ENTRY_LIST

'
' OIDs for dot11PhyFHSSEntry
'

%OID_DOT11_EHCC_PRIME_RADIX                = (%OID_DOT11_NDIS_START + 78)
' DWORD

%OID_DOT11_EHCC_NUMBER_OF_CHANNELS_FAMILY_INDE = (%OID_DOT11_NDIS_START + 79)
' DWORD

%OID_DOT11_EHCC_CAPABILITY_IMPLEMENTED     = (%OID_DOT11_NDIS_START + 80)
' BOOL

%OID_DOT11_EHCC_CAPABILITY_ENABLED         = (%OID_DOT11_NDIS_START + 81)
' BOOL

%OID_DOT11_HOP_ALGORITHM_ADOPTED           = (%OID_DOT11_NDIS_START + 82)

MACRO DOT11_HOP_ALGO_ADOPTED_enum=LONG
ENUM DOT11_HOP_ALGO_ADOPTED SINGULAR
    dot11_hop_algo_current
    dot11_hop_algo_hop_index
    dot11_hop_algo_hcc
END ENUM

%OID_DOT11_RANDOM_TABLE_FLAG               = (%OID_DOT11_NDIS_START + 83)
' BOOL

%OID_DOT11_NUMBER_OF_HOPPING_SETS          = (%OID_DOT11_NDIS_START + 84)
' DWORD

%OID_DOT11_HOP_MODULUS                     = (%OID_DOT11_NDIS_START + 85)
' DWORD

%OID_DOT11_HOP_OFFSET                      = (%OID_DOT11_NDIS_START + 86)
' DWORD


'
' OIDs for dot11HoppingPatternEntry
'
%OID_DOT11_HOPPING_PATTERN                 = (%OID_DOT11_NDIS_START + 87)

TYPE DOT11_HOPPING_PATTERN_ENTRY
    uHoppingPatternIndex    AS DWORD
    uRandomTableFieldNumber AS DWORD
END TYPE

TYPE DOT11_HOPPING_PATTERN_ENTRY_LIST
    uNumOfEntries               AS DWORD
    uTotalNumOfEntries          AS DWORD
    dot11HoppingPatternEntry(0) AS DOT11_HOPPING_PATTERN_ENTRY
END TYPE


%OID_DOT11_RANDOM_TABLE_FIELD_NUMBER       = (%OID_DOT11_NDIS_START + 88)
' DWORD

'
' WPA Extensions
'

%OID_DOT11_WPA_TSC                         = (%OID_DOT11_NDIS_START + 89)

TYPE DOT11_WPA_TSC
    uReserved        AS DWORD
    dot11OffloadType AS DOT11_OFFLOAD_TYPE_enum
    hOffload         AS BYTE   ' HANDLE
    dot11IV48Counter AS DOT11_IV48_COUNTER
END TYPE

'
' dot11.
'

%OID_DOT11_RSSI_RANGE                      = (%OID_DOT11_NDIS_START + 90)

TYPE DOT11_RSSI_RANGE
    dot11PhyType AS DOT11_PHY_TYPE_enum
    uRSSIMin     AS DWORD  ' Minimum caliberation value of RSSI in the NIC.
    uRSSIMax     AS DWORD  ' Maximum caliberation value of RSSI in the NIC.
END TYPE

%OID_DOT11_RF_USAGE                        = (%OID_DOT11_NDIS_START + 91)
'DWORD

%OID_DOT11_NIC_SPECIFIC_EXTENSION          = (%OID_DOT11_NDIS_START + 92)

TYPE DOT11_NIC_SPECIFIC_EXTENSION
    uBufferLength      AS DWORD
    uTotalBufferLength AS DWORD
    ucBuffer(0)        AS BYTE
END TYPE

'
' AP join request
'

%OID_DOT11_AP_JOIN_REQUEST                 = (%OID_DOT11_NDIS_START + 93)

TYPE DOT11_AP_JOIN_REQUEST
    uJoinFailureTimeout AS DWORD
    OperationalRateSet  AS DOT11_RATE_SET
    uChCenterFrequency  AS DWORD
    dot11BSSDescription AS DOT11_BSS_DESCRIPTION   ' Must be the last field.
END TYPE

'
' dot11PhyERPEntry
'
%OID_DOT11_ERP_PBCC_OPTION_IMPLEMENTED     = (%OID_DOT11_NDIS_START + 94)
' BOOL

%OID_DOT11_ERP_PBCC_OPTION_ENABLED         = (%OID_DOT11_NDIS_START + 95)
' BOOL

%OID_DOT11_DSSS_OFDM_OPTION_IMPLEMENTED    = (%OID_DOT11_NDIS_START + 96)
' BOOL

%OID_DOT11_DSSS_OFDM_OPTION_ENABLED        = (%OID_DOT11_NDIS_START + 97)
' BOOL

%OID_DOT11_SHORT_SLOT_TIME_OPTION_IMPLEMENTED  = (%OID_DOT11_NDIS_START + 98)
' BOOL

%OID_DOT11_SHORT_SLOT_TIME_OPTION_ENABLED  = (%OID_DOT11_NDIS_START + 99)
' BOOL

%OID_DOT11_MAX_MAC_ADDRESS_STATES          = (%OID_DOT11_NDIS_START + 100)
' DWORD

%OID_DOT11_RECV_SENSITIVITY_LIST           = (%OID_DOT11_NDIS_START + 101)
' DOT11_RECV_SENSITIVITY_LIST

TYPE DOT11_RECV_SENSITIVITY
    ucDataRate AS BYTE   ' UCHAR
    lRSSIMin   AS LONG
    lRSSIMax   AS LONG
END TYPE

UNION DOT11_RECV_SENSITIVITY_LIST_union
    dot11PhyType AS DOT11_PHY_TYPE_enum
    uPhyId       AS DWORD
END UNION

TYPE DOT11_RECV_SENSITIVITY_LIST
    DOT11_RECV_SENSITIVITY_LIST_union
    uNumOfEntries           AS DWORD
    uTotalNumOfEntries      AS DWORD
    dot11RecvSensitivity(0) AS DOT11_RECV_SENSITIVITY
END TYPE


'
' WME
'

%OID_DOT11_WME_IMPLEMENTED                 = (%OID_DOT11_NDIS_START + 102)
' BOOL

%OID_DOT11_WME_ENABLED                     = (%OID_DOT11_NDIS_START + 103)
' BOOL

%OID_DOT11_WME_AC_PARAMETERS               = (%OID_DOT11_NDIS_START + 104)

MACRO DOT11_AC_PARAM_enum=LONG
ENUM DOT11_AC_PARAM SINGULAR
    dot11_AC_param_BE           ' Best Effort
    dot11_AC_param_BK           ' Background
    dot11_AC_param_VI           ' Video
    dot11_AC_param_VO           ' Voice
    dot11_AC_param_max
END ENUM

TYPE DOT11_WME_AC_PARAMETERS
    ucAccessCategoryIndex AS BYTE   ' UCHAR
    ucAIFSN               AS BYTE   ' UCHAR
    ucECWmin              AS BYTE   ' UCHAR
    ucECWmax              AS BYTE   ' UCHAR
    usTXOPLimit           AS WORD
END TYPE

TYPE DOT11_WME_AC_PARAMTERS_LIST
    uNumOfEntries           AS DWORD
    uTotalNumOfEntries      AS DWORD
    dot11WMEACParameters(0) AS DOT11_WME_AC_PARAMETERS
END TYPE

%OID_DOT11_WME_UPDATE_IE                  = (%OID_DOT11_NDIS_START + 105)

TYPE DOT11_WME_UPDATE_IE
    uParamElemMinBeaconIntervals AS DWORD
    uWMEInfoElemOffset           AS DWORD
    uWMEInfoElemLength           AS DWORD
    uWMEParamElemOffset          AS DWORD
    uWMEParamElemLength          AS DWORD
    ucBuffer(0)                  AS BYTE   ' UCHAR  ' Must be the last field.
END TYPE

'
' QoS
'
%OID_DOT11_QOS_TX_QUEUES_SUPPORTED        = (%OID_DOT11_NDIS_START + 106)
' DWORD

%OID_DOT11_QOS_TX_DURATION                = (%OID_DOT11_NDIS_START + 107)

TYPE DOT11_QOS_TX_DURATION
    uNominalMSDUSize AS DWORD
    uMinPHYRate      AS DWORD
    uDuration        AS DWORD
END TYPE

%OID_DOT11_QOS_TX_MEDIUM_TIME             = (%OID_DOT11_NDIS_START + 108)

TYPE DOT11_QOS_TX_MEDIUM_TIME
    dot11PeerAddress   AS DOT11_MAC_ADDRESS
    ucQoSPriority      AS BYTE   ' UCHAR
    uMediumTimeAdmited AS DWORD
END TYPE

'
' NIC supported channel/center frequency list
'
%OID_DOT11_SUPPORTED_OFDM_FREQUENCY_LIST  = (%OID_DOT11_NDIS_START + 109)

TYPE DOT11_SUPPORTED_OFDM_FREQUENCY
    uCenterFrequency AS DWORD
END TYPE

TYPE DOT11_SUPPORTED_OFDM_FREQUENCY_LIST
    uNumOfEntries                  AS DWORD
    uTotalNumOfEntries             AS DWORD
    dot11SupportedOFDMFrequency(0) AS DOT11_SUPPORTED_OFDM_FREQUENCY
END TYPE

%OID_DOT11_SUPPORTED_DSSS_CHANNEL_LIST    = (%OID_DOT11_NDIS_START + 110)

TYPE DOT11_SUPPORTED_DSSS_CHANNEL
    uChannel AS DWORD
END TYPE

TYPE DOT11_SUPPORTED_DSSS_CHANNEL_LIST
    uNumOfEntries                AS DWORD
    uTotalNumOfEntries           AS DWORD
    dot11SupportedDSSSChannel(0) AS DOT11_SUPPORTED_DSSS_CHANNEL
END TYPE


'
' Extensible STA
'

TYPE DOT11_BYTE_ARRAY
    HEADER           AS NDIS_OBJECT_HEADER
    uNumOfBytes      AS DWORD
    uTotalNumOfBytes AS DWORD
    ucBuffer(0)      AS BYTE   ' UCHAR
END TYPE

MACRO OID_DOT11_AUTO_CONFIG_ENABLED=NWF_DEFINE_OID(120,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)

' DWORD
%DOT11_PHY_AUTO_CONFIG_ENABLED_FLAG        = &H00000001
%DOT11_MAC_AUTO_CONFIG_ENABLED_FLAG        = &H00000002

MACRO OID_DOT11_ENUM_BSS_LIST=NWF_DEFINE_OID(121,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)

' DOT11_BYTE_ARRAY with DOT11_BSS_ENTRY
%DOT11_BSS_ENTRY_BYTE_ARRAY_REVISION_1  =  1

' This structure is not supposed to be midl compliant because of
' DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO. The selection of union is
' *indirectly* determined from uPhyId. MIDL will not work here.

TYPE DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO_type
    uHopPattern AS DWORD
    uHopSet     AS DWORD
    uDwellTime  AS DWORD
END TYPE

UNION DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO
    uChCenterFrequency AS DWORD
    FHSS               AS DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO_type
END UNION

TYPE DOT11_BSS_ENTRY
    uPhyId                  AS DWORD
    PhySpecificInfo         AS DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO
    dot11BSSID              AS DOT11_MAC_ADDRESS
    dot11BSSType            AS DOT11_BSS_TYPE_enum
    lRSSI                   AS LONG
    uLinkQuality            AS DWORD
    bInRegDomain            AS BYTE   ' BOOLEAN
    usBeaconPeriod          AS WORD
    ullTimestamp            AS QUAD   ' ULONGLONG
    ullHostTimestamp        AS QUAD   ' ULONGLONG
    usCapabilityInformation AS WORD
    uBufferLength           AS DWORD
    ucBuffer(0)             AS BYTE   ' UCHAR  ' Must be the last field.
END TYPE

MACRO OID_DOT11_FLUSH_BSS_LIST=NWF_DEFINE_OID(122,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)
' VOID

MACRO OID_DOT11_POWER_MGMT_REQUEST=NWF_DEFINE_OID(123,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)

' DWORD
%DOT11_POWER_SAVING_NO_POWER_SAVING =  0
%DOT11_POWER_SAVING_FAST_PSP        =  8
%DOT11_POWER_SAVING_MAX_PSP         =  16
%DOT11_POWER_SAVING_MAXIMUM_LEVEL   =  24

MACRO OID_DOT11_DESIRED_SSID_LIST=NWF_DEFINE_OID(124,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)

' A list of DOT11_SSID
%DOT11_SSID_LIST_REVISION_1 =  1
TYPE DOT11_SSID_LIST
    HEADER             AS NDIS_OBJECT_HEADER
    uNumOfEntries      AS DWORD
    uTotalNumOfEntries AS DWORD
    SSIDs(0)           AS DOT11_SSID
END TYPE

MACRO OID_DOT11_EXCLUDED_MAC_ADDRESS_LIST=NWF_DEFINE_OID(125,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)

' A list of DOT11_MAC_ADDRESS

%DOT11_MAC_ADDRESS_LIST_REVISION_1 =  1

TYPE DOT11_MAC_ADDRESS_LIST
    HEADER             AS NDIS_OBJECT_HEADER
    uNumOfEntries      AS DWORD
    uTotalNumOfEntries AS DWORD
    MacAddrs(0)        AS DOT11_MAC_ADDRESS
END TYPE

MACRO OID_DOT11_DESIRED_BSSID_LIST=NWF_DEFINE_OID(126,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)

MACRO OID_DOT11_DESIRED_BSS_TYPE=NWF_DEFINE_OID(127,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)
    ' DOT11_BSS_TYPE

MACRO OID_DOT11_PMKID_LIST=NWF_DEFINE_OID(128,%NWF_OPERATIONAL_OID,%NWF_OPTIONAL_OID)

' A list of DOT11_PMKID_ENTRY

MACRO DOT11_PMKID_VALUE=STRING * 16

TYPE DOT11_PMKID_ENTRY
    BSSID  AS DOT11_MAC_ADDRESS
    PMKID  AS DOT11_PMKID_VALUE
    uFlags AS DWORD
END TYPE

%DOT11_PMKID_LIST_REVISION_1 =  1

TYPE DOT11_PMKID_LIST
    HEADER             AS NDIS_OBJECT_HEADER
    uNumOfEntries      AS DWORD
    uTotalNumOfEntries AS DWORD
    PMKIDs(0)          AS DOT11_PMKID_ENTRY
END TYPE

MACRO OID_DOT11_CONNECT_REQUEST=NWF_DEFINE_OID(129,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)
    ' no data type

MACRO OID_DOT11_EXCLUDE_UNENCRYPTED=NWF_DEFINE_OID(130,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)
    ' BOOLEAN

MACRO OID_DOT11_STATISTICS=NWF_DEFINE_OID(131,%NWF_STATISTICS_OID,%NWF_MANDATORY_OID)

' DOT11_STATISTICS structure
%DOT11_STATISTICS_UNKNOWN = &HFFFFFFFFFFFFFFFF  ' (ULONGLONG)(-1LL)

TYPE DOT11_PHY_FRAME_STATISTICS
    ' TX counters (MSDU/MMPDU)
    ullTransmittedFrameCount            AS QUAD   ' ULONGLONG
    ullMulticastTransmittedFrameCount   AS QUAD   ' ULONGLONG
    ullFailedCount                      AS QUAD   ' ULONGLONG
    ullRetryCount                       AS QUAD   ' ULONGLONG
    ullMultipleRetryCount               AS QUAD   ' ULONGLONG
    ullMaxTXLifetimeExceededCount       AS QUAD   ' ULONGLONG

    ' TX counters (MPDU)
    ullTransmittedFragmentCount         AS QUAD   ' ULONGLONG
    ullRTSSuccessCount                  AS QUAD   ' ULONGLONG
    ullRTSFailureCount                  AS QUAD   ' ULONGLONG
    ullACKFailureCount                  AS QUAD   ' ULONGLONG

    ' RX counters (MSDU/MMPDU)
    ullReceivedFrameCount               AS QUAD   ' ULONGLONG
    ullMulticastReceivedFrameCount      AS QUAD   ' ULONGLONG
    ullPromiscuousReceivedFrameCount    AS QUAD   ' ULONGLONG
    ullMaxRXLifetimeExceededCount       AS QUAD   ' ULONGLONG

    ' RX counters (MPDU)
    ullFrameDuplicateCount              AS QUAD   ' ULONGLONG
    ullReceivedFragmentCount            AS QUAD   ' ULONGLONG
    ullPromiscuousReceivedFragmentCount AS QUAD   ' ULONGLONG
    ullFCSErrorCount                    AS QUAD   ' ULONGLONG
END TYPE

TYPE DOT11_MAC_FRAME_STATISTICS
    ullTransmittedFrameCount        AS QUAD   ' ULONGLONG
    ullReceivedFrameCount           AS QUAD   ' ULONGLONG
    ullTransmittedFailureFrameCount AS QUAD   ' ULONGLONG
    ullReceivedFailureFrameCount    AS QUAD   ' ULONGLONG

    ullWEPExcludedCount             AS QUAD   ' ULONGLONG
    ullTKIPLocalMICFailures         AS QUAD   ' ULONGLONG
    ullTKIPReplays                  AS QUAD   ' ULONGLONG
    ullTKIPICVErrorCount            AS QUAD   ' ULONGLONG
    ullCCMPReplays                  AS QUAD   ' ULONGLONG
    ullCCMPDecryptErrors            AS QUAD   ' ULONGLONG
    ullWEPUndecryptableCount        AS QUAD   ' ULONGLONG
    ullWEPICVErrorCount             AS QUAD   ' ULONGLONG
    ullDecryptSuccessCount          AS QUAD   ' ULONGLONG
    ullDecryptFailureCount          AS QUAD   ' ULONGLONG
END TYPE

%DOT11_STATISTICS_REVISION_1 =  1

TYPE DOT11_STATISTICS
    HEADER                        AS NDIS_OBJECT_HEADER
    ullFourWayHandshakeFailures   AS QUAD   ' ULONGLONG
    ullTKIPCounterMeasuresInvoked AS QUAD   ' ULONGLONG
    ullReserved                   AS QUAD   ' ULONGLONG

    MacUcastCounters              AS DOT11_MAC_FRAME_STATISTICS
    MacMcastCounters              AS DOT11_MAC_FRAME_STATISTICS
    PhyCounters(0)                AS DOT11_PHY_FRAME_STATISTICS
END TYPE

MACRO OID_DOT11_PRIVACY_EXEMPTION_LIST=NWF_DEFINE_OID(132,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)

' A list of DOT11_PRIVACY_EXEMPTION
%DOT11_EXEMPT_NO_EXEMPTION      =  0   ' used only in DOT11_EXTSTA_SEND_CONTEXT
%DOT11_EXEMPT_ALWAYS            =  1
%DOT11_EXEMPT_ON_KEY_MAPPING_KEY_UNAVAILABLE = 2

%DOT11_EXEMPT_UNICAST   =  1
%DOT11_EXEMPT_MULTICAST =  2
%DOT11_EXEMPT_BOTH      =  3

TYPE DOT11_PRIVACY_EXEMPTION
    usEtherType           AS WORD
    usExemptionActionType AS WORD
    usExemptionPacketType AS WORD
END TYPE

%DOT11_PRIVACY_EXEMPTION_LIST_REVISION_1 =  1

TYPE DOT11_PRIVACY_EXEMPTION_LIST
    HEADER                     AS NDIS_OBJECT_HEADER
    uNumOfEntries              AS DWORD
    uTotalNumOfEntries         AS DWORD
    PrivacyExemptionEntries(0) AS DOT11_PRIVACY_EXEMPTION
END TYPE

MACRO OID_DOT11_ENABLED_AUTHENTICATION_ALGORITHM=NWF_DEFINE_OID(133,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)

%DOT11_AUTH_ALGORITHM_LIST_REVISION_1 =  1

TYPE DOT11_AUTH_ALGORITHM_LIST
    HEADER             AS NDIS_OBJECT_HEADER
    uNumOfEntries      AS DWORD
    uTotalNumOfEntries AS DWORD
    AlgorithmIds(0)    AS DOT11_AUTH_ALGORITHM_enum
END TYPE

MACRO OID_DOT11_SUPPORTED_UNICAST_ALGORITHM_PAIR=NWF_DEFINE_OID(134,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)

%DOT11_AUTH_CIPHER_PAIR_LIST_REVISION_1 =  1

TYPE DOT11_AUTH_CIPHER_PAIR_LIST
    HEADER             AS NDIS_OBJECT_HEADER
    uNumOfEntries      AS DWORD
    uTotalNumOfEntries AS DWORD
    AuthCipherPairs(0) AS DOT11_AUTH_CIPHER_PAIR
END TYPE

MACRO OID_DOT11_ENABLED_UNICAST_CIPHER_ALGORITHM=NWF_DEFINE_OID(135,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)

' DOT11_CIPHER_ALGO_LIST
%DOT11_CIPHER_ALGORITHM_LIST_REVISION_1 =  1

TYPE DOT11_CIPHER_ALGORITHM_LIST
    HEADER             AS NDIS_OBJECT_HEADER
    uNumOfEntries      AS DWORD
    uTotalNumOfEntries AS DWORD
    AlgorithmIds(0)    AS DOT11_CIPHER_ALGORITHM_enum
END TYPE

MACRO OID_DOT11_SUPPORTED_MULTICAST_ALGORITHM_PAIR=NWF_DEFINE_OID(136,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)

MACRO OID_DOT11_ENABLED_MULTICAST_CIPHER_ALGORITHM=NWF_DEFINE_OID(137,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)
' DOT11_CIPHER_ALGORITHM_LIST

MACRO OID_DOT11_CIPHER_DEFAULT_KEY_ID=NWF_DEFINE_OID(138,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)
' DWORD

MACRO OID_DOT11_CIPHER_DEFAULT_KEY=NWF_DEFINE_OID(139,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)

%DOT11_CIPHER_DEFAULT_KEY_VALUE_REVISION_1 =  1

TYPE DOT11_CIPHER_DEFAULT_KEY_VALUE
    HEADER      AS NDIS_OBJECT_HEADER
    uKeyIndex   AS DWORD
    AlgorithmId AS DOT11_CIPHER_ALGORITHM_enum
    MacAddr     AS DOT11_MAC_ADDRESS
    bDelete     AS BYTE  ' BOOLEAN
    bStatic     AS BYTE  ' BOOLEAN
    usKeyLength AS WORD
    ucKey(0)    AS BYTE  ' UCHAR        ' Must be the last field
END TYPE

TYPE DOT11_KEY_ALGO_TKIP_MIC
    ucIV48Counter(5) AS BYTE   ' UCHAR
    ulTKIPKeyLength  AS DWORD
    ulMICKeyLength   AS DWORD
    ucTKIPMICKeys(0) AS BYTE   ' UCHAR  ' Must be the last field.
END TYPE

TYPE DOT11_KEY_ALGO_CCMP
    ucIV48Counter(5) AS BYTE   ' UCHAR
    ulCCMPKeyLength  AS DWORD
    ucCCMPKey(0)     AS BYTE   ' UCHAR
END TYPE

MACRO OID_DOT11_CIPHER_KEY_MAPPING_KEY=NWF_DEFINE_OID(140,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)

' DOT11_BYTE_ARRAY
MACRO DOT11_DIRECTION_enum=LONG
ENUM DOT11_DIRECTION SINGULAR
    DOT11_DIR_INBOUND = 1
    DOT11_DIR_OUTBOUND
    DOT11_DIR_BOTH
END ENUM

%DOT11_CIPHER_KEY_MAPPING_KEY_VALUE_BYTE_ARRAY_REVISION_1 =  1

TYPE DOT11_CIPHER_KEY_MAPPING_KEY_VALUE
    PeerMacAddr AS DOT11_MAC_ADDRESS
    AlgorithmId AS DOT11_CIPHER_ALGORITHM_enum
    Direction   AS DOT11_DIRECTION_enum
    bDelete     AS BYTE   ' BOOLEAN
    bStatic     AS BYTE   ' BOOLEAN
    usKeyLength AS WORD
    ucKey(0)    AS BYTE   ' UCHAR  ' Must be the last field
END TYPE

MACRO OID_DOT11_ENUM_ASSOCIATION_INFO=NWF_DEFINE_OID(141,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)

' a list of DOT11_ASSOCIATION_INFO
MACRO DOT11_ASSOCIATION_STATE_enum=LONG
ENUM DOT11_ASSOCIATION_STATE SINGULAR
    dot11_assoc_state_zero
    dot11_assoc_state_unauth_unassoc
    dot11_assoc_state_auth_unassoc
    dot11_assoc_state_auth_assoc
END ENUM

TYPE DOT11_ASSOCIATION_INFO_EX
    PeerMacAddress            AS DOT11_MAC_ADDRESS
    BSSID                     AS DOT11_MAC_ADDRESS
    usCapabilityInformation   AS WORD
    usListenInterval          AS WORD
    ucPeerSupportedRates(%MAX_NUM_SUPPORTED_RATES_V2-1) AS BYTE  ' UCHAR
    usAssociationID           AS WORD
    dot11AssociationState     AS DOT11_ASSOCIATION_STATE_enum
    dot11PowerMode            AS DOT11_POWER_MODE_enum
    liAssociationUpTime       AS QUAD  ' LARGE_INTEGER
    ullNumOfTxPacketSuccesses AS QUAD   ' ULONGLONG
    ullNumOfTxPacketFailures  AS QUAD   ' ULONGLONG
    ullNumOfRxPacketSuccesses AS QUAD   ' ULONGLONG
    ullNumOfRxPacketFailures  AS QUAD   ' ULONGLONG
END TYPE

%DOT11_ASSOCIATION_INFO_LIST_REVISION_1 =  1

TYPE DOT11_ASSOCIATION_INFO_LIST
    HEADER             AS NDIS_OBJECT_HEADER
    uNumOfEntries      AS DWORD
    uTotalNumOfEntries AS DWORD
    dot11AssocInfo(0)  AS DOT11_ASSOCIATION_INFO_EX
END TYPE


MACRO OID_DOT11_DISCONNECT_REQUEST=NWF_DEFINE_OID(142,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)

MACRO OID_DOT11_UNICAST_USE_GROUP_ENABLED=NWF_DEFINE_OID(143,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)
' BOOLEAN

MACRO OID_DOT11_HARDWARE_PHY_STATE=NWF_DEFINE_OID(144,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)
' BOOLEAN

MACRO OID_DOT11_DESIRED_PHY_LIST=NWF_DEFINE_OID(145,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)

' DOT11_PHY_ID_LIST
%DOT11_PHY_ID_LIST_REVISION_1 =  1

TYPE DOT11_PHY_ID_LIST
    HEADER             AS NDIS_OBJECT_HEADER
    uNumOfEntries      AS DWORD
    uTotalNumOfEntries AS DWORD
    dot11PhyId(0)      AS DWORD
END TYPE

%DOT11_PHY_ID_ANY        = &Hffffffff???

MACRO OID_DOT11_CURRENT_PHY_ID=NWF_DEFINE_OID(146,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)
' DWORD

MACRO OID_DOT11_MEDIA_STREAMING_ENABLED=NWF_DEFINE_OID(147,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)
' BOOLEAN

MACRO OID_DOT11_UNREACHABLE_DETECTION_THRESHOLD=NWF_DEFINE_OID(148,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)
' DWORD

MACRO OID_DOT11_ACTIVE_PHY_LIST=NWF_DEFINE_OID(149,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)
' DOT11_PHY_ID_LIST

MACRO OID_DOT11_EXTSTA_CAPABILITY=NWF_DEFINE_OID(150,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)

' DOT11_EXTSTA_CAPABILITY
%DOT11_EXTSTA_CAPABILITY_REVISION_1 =  1

TYPE DOT11_EXTSTA_CAPABILITY
    HEADER                        AS NDIS_OBJECT_HEADER
    uScanSSIDListSize             AS DWORD
    uDesiredBSSIDListSize         AS DWORD
    uDesiredSSIDListSize          AS DWORD
    uExcludedMacAddressListSize   AS DWORD
    uPrivacyExemptionListSize     AS DWORD
    uKeyMappingTableSize          AS DWORD
    uDefaultKeyTableSize          AS DWORD
    uWEPKeyValueMaxLength         AS DWORD
    uPMKIDCacheSize               AS DWORD
    uMaxNumPerSTADefaultKeyTables AS DWORD
END TYPE

MACRO OID_DOT11_DATA_RATE_MAPPING_TABLE=NWF_DEFINE_OID(151,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)

' DOT11_DATA_RATE_MAPPING_ENTRY
TYPE DOT11_DATA_RATE_MAPPING_ENTRY
    ucDataRateIndex AS BYTE   ' UCHAR
    ucDataRateFlag  AS BYTE   ' UCHAR
    usDataRateValue AS WORD
END TYPE

%DOT11_DATA_RATE_MAPPING_TABLE_REVISION_1 =  1

TYPE DOT11_DATA_RATE_MAPPING_TABLE
    HEADER                 AS NDIS_OBJECT_HEADER
    uDataRateMappingLength AS DWORD
    DataRateMappingEntries(%DOT11_RATE_SET_MAX_LENGTH-1) AS DOT11_DATA_RATE_MAPPING_ENTRY
END TYPE

%DOT11_DATA_RATE_NON_STANDARD        = &H01
%DOT11_DATA_RATE_INDEX_MASK          = &H7f

MACRO OID_DOT11_SUPPORTED_COUNTRY_OR_REGION_STRING=NWF_DEFINE_OID(152,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)

%DOT11_COUNTRY_OR_REGION_STRING_LIST_REVISION_1 =  1

TYPE DOT11_COUNTRY_OR_REGION_STRING_LIST
    HEADER             AS NDIS_OBJECT_HEADER
    uNumOfEntries      AS DWORD
    uTotalNumOfEntries AS DWORD
    CountryOrRegionStrings(0) AS STRING * 3 ' DOT11_COUNTRY_OR_REGION_STRING
END TYPE

MACRO OID_DOT11_DESIRED_COUNTRY_OR_REGION_STRING=NWF_DEFINE_OID(153,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)
' DOT11_COUNTRY_OR_REGION_STRING

MACRO OID_DOT11_PORT_STATE_NOTIFICATION=NWF_DEFINE_OID(154,%NWF_OPERATIONAL_OID,%NWF_OPTIONAL_OID)

' DOT11_PORT_STATE_NOTIFICATION
%DOT11_PORT_STATE_NOTIFICATION_REVISION_1 =  1

TYPE DOT11_PORT_STATE_NOTIFICATION
    HEADER  AS NDIS_OBJECT_HEADER
    PeerMac AS DOT11_MAC_ADDRESS
    bOpen   AS BYTE   ' BOOLEAN
END TYPE

MACRO OID_DOT11_IBSS_PARAMS=NWF_DEFINE_OID(155,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)

' DOT11_IBSS_PARAMS
%DOT11_IBSS_PARAMS_REVISION_1 =  1

TYPE DOT11_IBSS_PARAMS
    HEADER     AS NDIS_OBJECT_HEADER
    bJoinOnly  AS LONG   ' BOOLEAN
    uIEsOffset AS DWORD
    uIEsLength AS DWORD
END TYPE

MACRO OID_DOT11_QOS_PARAMS=NWF_DEFINE_OID(156,%NWF_OPERATIONAL_OID,%NWF_OPTIONAL_OID)

%DOT11_QOS_PARAMS_REVISION_1    =  1
%DOT11_QOS_PROTOCOL_FLAG_WMM     = &H01         ' WMM QoS protocol
%DOT11_QOS_PROTOCOL_FLAG_11E     = &H02         ' 802.11e QoS protocol

TYPE DOT11_QOS_PARAMS
    HEADER                    AS NDIS_OBJECT_HEADER

    ' Flags of the enabled QoS protocols.
    ' It is either 0 or combination of DOT11_QOS_PROTOCOL_FLAG_WMM
    ' and/or DOT11_QOS_PROTOCOL_FLAG_11E
    ucEnabledQoSProtocolFlags AS BYTE   ' UCHAR
END TYPE

MACRO OID_DOT11_SAFE_MODE_ENABLED=NWF_DEFINE_OID(157,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)
' BOOLEAN

MACRO OID_DOT11_HIDDEN_NETWORK_ENABLED=NWF_DEFINE_OID(158,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)
' BOOLEAN

MACRO OID_DOT11_ASSOCIATION_PARAMS=NWF_DEFINE_OID(159,%NWF_OPERATIONAL_OID,%NWF_MANDATORY_OID)

' DOT11_ASSOCIATION_PARAMS
%DOT11_ASSOCIATION_PARAMS_REVISION_1 = 1

TYPE DOT11_ASSOCIATION_PARAMS
    HEADER                 AS NDIS_OBJECT_HEADER
    BSSID                  AS DOT11_MAC_ADDRESS
    uAssocRequestIEsOffset AS DWORD
    uAssocRequestIEsLength AS DWORD
END TYPE

'
' 802.11 Extensions to Standard NDIS Functions
'

'
' Miniport Send Path Extension
'

' Only 4 bits are present in the 802.11 header to track fragments.
%DOT11_MAX_NUM_OF_FRAGMENTS                 =  16
' Priority Classes.
%DOT11_PRIORITY_CONTENTION                  =  0
%DOT11_PRIORITY_CONTENTION_FREE             =  1

' Service Classes.
%DOT11_SERVICE_CLASS_REORDERABLE_MULTICAST  =  0
%DOT11_SERVICE_CLASS_STRICTLY_ORDERED       =  1
' Flags.
%DOT11_FLAGS_80211B_SHORT_PREAMBLE          = &H00000001
%DOT11_FLAGS_80211B_PBCC                    = &H00000002
%DOT11_FLAGS_80211B_CHANNEL_AGILITY         = &H00000004
%DOT11_FLAGS_PS_ON                          = &H00000008
%DOT11_FLAGS_80211G_DSSS_OFDM               = &H00000010
%DOT11_FLAGS_80211G_USE_PROTECTION          = &H00000020
%DOT11_FLAGS_80211G_NON_ERP_PRESENT         = &H00000040
%DOT11_FLAGS_80211G_BARKER_PREAMBLE_MODE    = &H00000080
%DOT11_WME_PACKET                           = &H00000100

TYPE DOT11_FRAGMENT_DESCRIPTOR
    uOffset AS DWORD
    uLength AS DWORD
END TYPE

TYPE DOT11_PER_MSDU_COUNTERS
    uTransmittedFragmentCount AS DWORD
    uRetryCount AS DWORD
    uRTSSuccessCount AS DWORD
    uRTSFailureCount AS DWORD
    uACKFailureCount AS DWORD
END TYPE

TYPE DOT11_HRDSSS_PHY_ATTRIBUTES
    bShortPreambleOptionImplemented AS BYTE  ' BOOLEAN
    bPBCCOptionImplemented          AS BYTE  ' BOOLEAN
    bChannelAgilityPresent          AS BYTE  ' BOOLEAN
    uHRCCAModeSupported             AS DWORD
END TYPE

TYPE DOT11_OFDM_PHY_ATTRIBUTES
    uFrequencyBandsSupported AS DWORD
END TYPE

TYPE DOT11_ERP_PHY_ATTRIBUTES
    DOT11_HRDSSS_PHY_ATTRIBUTES
    bERPPBCCOptionImplemented       AS BYTE  ' BOOLEAN
    bDSSSOFDMOptionImplemented      AS BYTE  ' BOOLEAN
    bShortSlotTimeOptionImplemented AS BYTE  ' BOOLEAN
END TYPE

%DOT11_PHY_ATTRIBUTES_REVISION_1 =  1

UNION DOT11_PHY_ATTRIBUTES_union
    HRDSSSAttributes AS DOT11_HRDSSS_PHY_ATTRIBUTES
    OFDMAttributes   AS DOT11_OFDM_PHY_ATTRIBUTES
    ERPAttributes    AS DOT11_ERP_PHY_ATTRIBUTES
END UNION

TYPE DOT11_PHY_ATTRIBUTES
    HEADER            AS NDIS_OBJECT_HEADER

    PhyType           AS DOT11_PHY_TYPE_enum
    bHardwarePhyState AS BYTE  ' BOOLEAN
    bSoftwarePhyState AS BYTE  ' BOOLEAN

    bCFPollable       AS BYTE  ' BOOLEAN
    uMPDUMaxLength    AS DWORD
    TempType          AS DOT11_TEMP_TYPE_enum
    DiversitySupport  AS DOT11_DIVERSITY_SUPPORT_enum
    DOT11_PHY_ATTRIBUTES_union

    uNumberSupportedPowerLevels AS DWORD
    TxPowerLevels(7) AS DWORD

    uNumDataRateMappingEntries AS DWORD
    DataRateMappingEntries(%DOT11_RATE_SET_MAX_LENGTH-1) AS DOT11_DATA_RATE_MAPPING_ENTRY

    SupportedDataRatesValue AS DOT11_SUPPORTED_DATA_RATES_VALUE_V2
END TYPE

%DOT11_EXTSTA_ATTRIBUTES_SAFEMODE_OID_SUPPORTED  = &H1
%DOT11_EXTSTA_ATTRIBUTES_SAFEMODE_CERTIFIED      = &H2
%DOT11_EXTSTA_ATTRIBUTES_SAFEMODE_RESERVED       = &HC

#IF %DEF(%NDIS_SUPPORT_NDIS6)

%DOT11_EXTSTA_ATTRIBUTES_REVISION_1 =  1
%DOT11_EXTSTA_ATTRIBUTES_REVISION_2 =  2

TYPE DOT11_EXTSTA_ATTRIBUTES

    HEADER                        AS NDIS_OBJECT_HEADER

    uScanSSIDListSize             AS DWORD
    uDesiredBSSIDListSize         AS DWORD
    uDesiredSSIDListSize          AS DWORD
    uExcludedMacAddressListSize   AS DWORD
    uPrivacyExemptionListSize     AS DWORD
    uKeyMappingTableSize          AS DWORD
    uDefaultKeyTableSize          AS DWORD
    uWEPKeyValueMaxLength         AS DWORD
    uPMKIDCacheSize               AS DWORD
    uMaxNumPerSTADefaultKeyTables AS DWORD

    bStrictlyOrderedServiceClassImplemented AS BYTE  ' BOOLEAN

    ' Flags of the supported QoS protocols.
    ' It is either 0 or combination of DOT11_QOS_PROTOCOL_FLAG_WMM
    ' and/or DOT11_QOS_PROTOCOL_FLAG_11E
    ucSupportedQoSProtocolFlags   AS BYTE

    bSafeModeImplemented          AS BYTE  ' BOOLEAN

    ' Supported Country Strings
    uNumSupportedCountryOrRegionStrings AS DWORD
    pSupportedCountryOrRegionStrings AS DWORD  ' STRING * 3 PTR

    ' Infra Capabilities
    uInfraNumSupportedUcastAlgoPairs AS DWORD
    pInfraSupportedUcastAlgoPairs AS DOT11_AUTH_CIPHER_PAIR PTR

    uInfraNumSupportedMcastAlgoPairs AS DWORD
    pInfraSupportedMcastAlgoPairs AS DOT11_AUTH_CIPHER_PAIR PTR

    ' Ad hoc Capabilities
    uAdhocNumSupportedUcastAlgoPairs AS DWORD
    pAdhocSupportedUcastAlgoPairs AS DOT11_AUTH_CIPHER_PAIR PTR

    uAdhocNumSupportedMcastAlgoPairs AS DWORD
    pAdhocSupportedMcastAlgoPairs AS DOT11_AUTH_CIPHER_PAIR PTR
END TYPE

#ENDIF ' NDIS_SUPPORT_NDIS6

#IF (%DEF(%NDIS) OR %DEF(%NDIS_WRAPPER)) ' To avoid build break since NDIS_PACKET isn't defined for user mode app.

#IF %DEF(%NDIS_SUPPORT_NDIS6)
' Send path extension for NativeWiFi NDIS 6.0 miniport driver

%DOT11_SEND_CONTEXT_REVISION_1 =  1

TYPE DOT11_SEND_CONTEXT
    HEADER                  AS NDIS_OBJECT_HEADER
    pvReserved              AS DWORD  ' PVOID
    uFlags                  AS DWORD
    uPSLifetime             AS DWORD
    uDelayedSleepValue      AS DWORD
    ucTXDataRates(7)        AS BYTE
    bIndicateAssociatedACKs AS BYTE   ' BOOLEAN
    bIndicateTXStatus       AS BYTE   ' BOOLEAN
    ucPriority              AS BYTE
    bDontFragment           AS BYTE   ' BOOLEAN
    dwExtendedStatus        AS DWORD
    hIntegrityOffload       AS DWORD  ' HANDLE
    hWEPOffload             AS DWORD  ' HANDLE
    ucWPAMSDUPriority       AS BYTE
    ucNumOfRWsOnPeer        AS BYTE
    usAID                   AS WORD
    pDot11PerMSDUCounters   AS DOT11_PER_MSDU_COUNTERS PTR
END TYPE


MACRO DOT11_SEND_CONTEXT_SIZE =((SIZEOF(DOT11_SEND_CONTEXT) + %MEMORY_ALLOCATION_ALIGNMENT - 1) AND NOT (%MEMORY_ALLOCATION_ALIGNMENT-1))



' Send path extension for NativeWiFi NDIS 5.1 miniport driver
TYPE DOT11_SEND_EXTENSION_INFO
    uVersion                AS DWORD
    HEADER                  AS NDIS_OBJECT_HEADER
    pvReserved              AS DWORD  ' PVOID
    uFlags                  AS DWORD
    uPSLifetime             AS DWORD
    uDelayedSleepValue      AS DWORD
    ucTXDataRates(7)        AS BYTE
    bIndicateAssociatedACKs AS BYTE   ' BOOLEAN
    bIndicateTXStatus       AS BYTE   ' BOOLEAN
    ucPriority              AS BYTE
    bDontFragment           AS BYTE   ' BOOLEAN
    dwExtendedStatus        AS DWORD
    hIntegrityOffload       AS DWORD  ' HANDLE
    hWEPOffload             AS DWORD  ' HANDLE
    ucWPAMSDUPriority       AS BYTE
    ucNumOfRWsOnPeer        AS BYTE
    usAID                   AS WORD
    pDot11PerMSDUCounters   AS DOT11_PER_MSDU_COUNTERS PTR
    usNumberOfFragments     AS WORD
    Dot11FragmentDescriptors(0) AS DOT11_FRAGMENT_DESCRIPTOR
END TYPE

MACRO DOT11_ACK_POLICY_enum=LONG
ENUM DOT11_ACK_POLICY SINGULAR
    dot11_ack_policy_none
    dot11_ack_policy_acknowledge
    dot11_ack_policy_do_not_acknowledge
END ENUM

' Send path extension for NativeWiFi NDIS 5.1 miniport driver
TYPE DOT11_SEND_EXTENSION_INFO_V2
    ucQoSPriority               AS BIT * 4 OF BYTE
    ucAckPolicy                 AS BIT * 4
    usExtendedTXDataRatesOffset AS WORD
    ucNumOfExtendedTXDataRates  AS BYTE
    ucBuffer(0) AS BYTE  ' UCHAR
END TYPE

'
' Miniport Receive Path Extension
'

' Recv path extension for NativeWiFi NDIS 6.0 miniport driver

%DOT11_RECV_CONTEXT_REVISION_1 =  1

TYPE DOT11_RECV_CONTEXT
    HEADER                  AS NDIS_OBJECT_HEADER
    pvReserved              AS DWORD  ' PVOID
    dot11PhyType            AS DOT11_PHY_TYPE_enum
    uChCenterFrequency      AS DWORD
    lRSSI                   AS LONG
    uRSSI                   AS DWORD
    ucPriority              AS BYTE
    ucDataRate              AS BYTE
    ucPeerMacAddress(5)     AS BYTE
    dwExtendedStatus        AS DWORD
    hWEPOffloadContext      AS DWORD  ' HANDLE
    hAuthOffloadContext     AS DWORD  ' HANDLE
    usWEPAppliedMask        AS WORD
    usWPAMSDUPriority       AS WORD
    dot11LowestIV48Counter  AS DOT11_IV48_COUNTER
    usDot11LeftRWBitMap     AS WORD
    dot11HighestIV48Counter AS DOT11_IV48_COUNTER
    usDot11RightRWBitMap    AS WORD
    usNumberOfMPDUsReceived AS WORD
END TYPE

MACRO DOT11_RECV_CONTEXT_SIZE=((SIZEOF(DOT11_RECV_CONTEXT) + %MEMORY_ALLOCATION_ALIGNMENT - 1) AND NOT (%MEMORY_ALLOCATION_ALIGNMENT-1))

#ELSE

' Recv path extension for NativeWiFi NDIS 5.1 miniport driver

TYPE DOT11_RECV_EXTENSION_INFO
    uVersion                AS DWORD
    pvReserved              AS DWORD  ' PVOID
    dot11PhyType            AS DOT11_PHY_TYPE_enum
    uChCenterFrequency      AS DWORD
    lRSSI                   AS LONG
    lRSSIMin                AS LONG
    lRSSIMax                AS LONG
    uRSSI                   AS DWORD
    ucPriority              AS BYTE
    ucDataRate              AS BYTE
    ucPeerMacAddress(5)     AS BYTE
    dwExtendedStatus        AS DWORD
    hWEPOffloadContext      AS DWORD  ' HANDLE
    hAuthOffloadContext     AS DWORD  ' HANDLE
    usWEPAppliedMask        AS WORD
    usWPAMSDUPriority       AS WORD
    dot11LowestIV48Counter  AS DOT11_IV48_COUNTER
    usDot11LeftRWBitMap     AS WORD
    dot11HighestIV48Counter AS DOT11_IV48_COUNTER
    usDot11RightRWBitMap    AS WORD
    usNumberOfMPDUsReceived AS WORD
    usNumberOfFragments     AS WORD
    ' PNDIS_PACKET pNdisPackets[1];        ' Must be the last field.
    pNdisPackets(0)         AS DWORD  ' PVOID ' Must be the last field.
END TYPE

TYPE DOT11_RECV_EXTENSION_INFO_V2
    uVersion                AS DWORD
    pvReserved              AS DWORD  ' PVOID
    dot11PhyType            AS DOT11_PHY_TYPE_enum
    uChCenterFrequency      AS DWORD
    lRSSI                   AS LONG
    uRSSI                   AS DWORD
    ucPriority              AS BYTE
    ucDataRate              AS BYTE
    ucPeerMacAddress(5)     AS BYTE
    dwExtendedStatus        AS DWORD
    hWEPOffloadContext      AS DWORD  ' HANDLE
    hAuthOffloadContext     AS DWORD  ' HANDLE
    usWEPAppliedMask        AS WORD
    usWPAMSDUPriority       AS WORD
    dot11LowestIV48Counter  AS DOT11_IV48_COUNTER
    usDot11LeftRWBitMap     AS WORD
    dot11HighestIV48Counter AS DOT11_IV48_COUNTER
    usDot11RightRWBitMap    AS WORD
    usNumberOfMPDUsReceived AS WORD
    usNumberOfFragments     AS WORD
    ' PNDIS_PACKET pNdisPackets[1];        ' Must be the last field.
    pNdisPackets(0)         AS DWORD  ' PVOID  ' Must be the last field.
END TYPE

#ENDIF ' NDIS_SUPPORT_NDIS6

#ENDIF ' NDIS_MINIPORT_DRIVER

'
' 802.11 Status Codes
'

%DOT11_STATUS_SUCCESS                        = &H00000001

%DOT11_STATUS_RETRY_LIMIT_EXCEEDED           = &H00000002

%DOT11_STATUS_UNSUPPORTED_PRIORITY           = &H00000004

%DOT11_STATUS_UNSUPPORTED_SERVICE_CLASS      = &H00000008

%DOT11_STATUS_UNAVAILABLE_PRIORITY           = &H00000010

%DOT11_STATUS_UNAVAILABLE_SERVICE_CLASS      = &H00000020

%DOT11_STATUS_XMIT_MSDU_TIMER_EXPIRED        = &H00000040

%DOT11_STATUS_UNAVAILABLE_BSS                = &H00000080

%DOT11_STATUS_EXCESSIVE_DATA_LENGTH          = &H00000100

%DOT11_STATUS_ENCRYPTION_FAILED              = &H00000200

%DOT11_STATUS_WEP_KEY_UNAVAILABLE            = &H00000400

%DOT11_STATUS_ICV_VERIFIED                   = &H00000800

%DOT11_STATUS_PACKET_REASSEMBLED             = &H00001000

%DOT11_STATUS_PACKET_NOT_REASSEMBLED         = &H00002000

%DOT11_STATUS_GENERATE_AUTH_FAILED           = &H00004000

%DOT11_STATUS_AUTH_NOT_VERIFIED              = &H00008000

%DOT11_STATUS_AUTH_VERIFIED                  = &H00010000

%DOT11_STATUS_AUTH_FAILED                    = &H00020000

%DOT11_STATUS_PS_LIFETIME_EXPIRED            = &H00040000

'
' Flags for NDIS_STATUS_MEDIA_SPECIFIC_INDICATION
'
TYPE DOT11_STATUS_INDICATION
    uStatusType AS DWORD
    ndisStatus  AS NDIS_STATUS
END TYPE

%DOT11_STATUS_RESET_CONFIRM                     =  4

' #IF NOT %DEF(%NDIS_SUPPORT_NDIS6)
    %DOT11_STATUS_SCAN_CONFIRM                  =  1
    %DOT11_STATUS_JOIN_CONFIRM                  =  2
    %DOT11_STATUS_START_CONFIRM                 =  3
    %DOT11_STATUS_AP_JOIN_CONFIRM               =  5
    %DOT11_STATUS_MPDU_MAX_LENGTH_CHANGED       =  6
' #endif  ' %NDIS_SUPPORT_NDIS6

#IF %DEF(%NDIS_SUPPORT_NDIS6)
%DOT11_MPDU_MAX_LENGTH_INDICATION_REVISION_1 =  1
TYPE DOT11_MPDU_MAX_LENGTH_INDICATION
    HEADER         AS NDIS_OBJECT_HEADER
    uPhyId         AS DWORD
    uMPDUMaxLength AS DWORD
END TYPE
#ELSE
TYPE DOT11_MPDU_MAX_LENGTH_INDICATION
    uStatusType    AS DWORD
    uVersion       AS DWORD
    uPhyId         AS DWORD
    uMPDUMaxLength AS DWORD
TYPE
#ENDIF ' NDIS_SUPPORT_NDIS6

%DOT11_ASSOCIATION_START_PARAMETERS_REVISION_1 =  1
TYPE DOT11_ASSOCIATION_START_PARAMETERS
    HEADER         AS NDIS_OBJECT_HEADER
    MacAddr        AS DOT11_MAC_ADDRESS
    SSID           AS DOT11_SSID
    uIHVDataOffset AS DWORD
    uIHVDataSize   AS DWORD
END TYPE

%DOT11_ENCAP_RFC_1042    =  1
%DOT11_ENCAP_802_1H      =  2

TYPE DOT11_ENCAP_ENTRY
    usEtherType AS WORD
    usEncapType AS WORD  ' either DOT11_ENCAP_RFC_1042 or DOT11_ENCAP_802_1H
END TYPE

MACRO DOT11_DS_INFO_enum=LONG
ENUM DOT11_DS_INFO SINGULAR
    DOT11_DS_CHANGED
    DOT11_DS_UNCHANGED
    DOT11_DS_UNKNOWN
END ENUM

'''''''''''''''''''''''''''''''''''''''''''''
' Definitions of association status codes
'
MACRO DOT11_ASSOC_STATUS=DWORD

' The association is successful
%DOT11_ASSOC_STATUS_SUCCESS                         =  0

' Generic association failure
%DOT11_ASSOC_STATUS_FAILURE                          = &H00000001

' The association fails because the peer is not responding.
' Scenarios:
'    1. the peer doesn't respond to 802.11 authentication frames or
'       802.11 association request frames or probe request frames.
'    2. the NIC hasn't received beacon from the peer for substantial
'       amount of time. The timeout value here is NIC specific.
'    3. any other cases in which NIC determines that the peer is not
'       responsive.
%DOT11_ASSOC_STATUS_UNREACHABLE                      = &H00000002

' The association fails because the radio is turned off
%DOT11_ASSOC_STATUS_RADIO_OFF                        = &H00000003

' The association fails because the PHY is disabled. Here the PHY
' entity becomes unavailable to the OS. But the radio itself is not
' necessarily turned off.
%DOT11_ASSOC_STATUS_PHY_DISABLED                     = &H00000004

' The association is cancelled (for example, the NIC is reset)
%DOT11_ASSOC_STATUS_CANCELLED                        = &H00000005

' The connection fails because all the candidate AP has been tried
' and none of the attempts succeeds.
%DOT11_ASSOC_STATUS_CANDIDATE_LIST_EXHAUSTED         = &H00000006

' The current association is disassociated as requested by the OS
' (through either a OID_DOT11_RESET_REQUEST or OID_DOT11_DISCONNECT request)
%DOT11_ASSOC_STATUS_DISASSOCIATED_BY_OS              = &H00000007

' The current association is disassociated because the NIC roams
' to new AP.
' This error code is used for indicating the implicit dissassociation
' done by the nwifi.sys. Miniport driver usually doesn't generate
' this error code (since the disassociation is automatically done
' by the nwifi.sys).
%DOT11_ASSOC_STATUS_DISASSOCIATED_BY_ROAMING         = &H00000008

' The current association is disassocated because the NIC is reset
%DOT11_ASSOC_STATUS_DISASSOCIATED_BY_RESET           = &H00000009

' The current association is disassocated because the NIC is reset
%DOT11_ASSOC_STATUS_SYSTEM_ERROR                     = &H0000000a

' Roaming reason: find a better AP
%DOT11_ASSOC_STATUS_ROAMING_BETTER_AP_FOUND          = &H0000000b

' Roaming reason: the association to the current BSS is lost
%DOT11_ASSOC_STATUS_ROAMING_ASSOCIATION_LOST         = &H0000000c

' Roaming reason: adhoc roaming (network Coalescing)
%DOT11_ASSOC_STATUS_ROAMING_ADHOC                    = &H0000000d

' The new association fails or the current association is disassocated
' because the NIC receives an 802.11 de-authentication frame from the
' peer. The lowest 16-bits are the reason code (2-byte) copied from
' the 802.11 DeAuthentication frame.
%DOT11_ASSOC_STATUS_PEER_DEAUTHENTICATED            = &H00010000
%DOT11_ASSOC_STATUS_PEER_DEAUTHENTICATED_START      = %DOT11_ASSOC_STATUS_PEER_DEAUTHENTICATED
%DOT11_ASSOC_STATUS_PEER_DEAUTHENTICATED_END        = &H0001ffff

' The new association fails or the current association is disassocated
' because the NIC receives an 802.11 disassociation frame from the
' peer. The lowest 16-bits are the reason code (2-byte) copied from
' the 802.11 DisAssociation frame.
%DOT11_ASSOC_STATUS_PEER_DISASSOCIATED              = &H00020000
%DOT11_ASSOC_STATUS_PEER_DISASSOCIATED_START        = %DOT11_ASSOC_STATUS_PEER_DISASSOCIATED
%DOT11_ASSOC_STATUS_PEER_DISASSOCIATED_END          = &H0002ffff

%DOT11_ASSOC_STATUS_ASSOCIATION_RESPONSE            = &H00030000???
%DOT11_ASSOC_STATUS_ASSOCIATION_RESPONSE_START      = %DOT11_ASSOC_STATUS_ASSOCIATION_RESPONSE
%DOT11_ASSOC_STATUS_ASSOCIATION_RESPONSE_END        = &H0003ffff???

' The mask for extracting 802.11 deauthentication and disassociation
' reason code.
%DOT11_ASSOC_STATUS_REASON_CODE_MASK                 = &H0000ffff

' Define the range of IHV specific association status codes
%DOT11_ASSOC_STATUS_IHV_START                        = &H80000000???
%DOT11_ASSOC_STATUS_IHV_END                          = &Hffffffff???

%DOT11_ASSOCIATION_COMPLETION_PARAMETERS_REVISION_1 =  1
TYPE DOT11_ASSOCIATION_COMPLETION_PARAMETERS
    HEADER                AS NDIS_OBJECT_HEADER
    MacAddr               AS DOT11_MAC_ADDRESS

    uStatus               AS DOT11_ASSOC_STATUS

    bReAssocReq           AS LONG  ' BOOLEAN
    bReAssocResp          AS LONG  ' BOOLEAN
    uAssocReqOffset       AS DWORD
    uAssocReqSize         AS DWORD
    uAssocRespOffset      AS DWORD
    uAssocRespSize        AS DWORD
    uBeaconOffset         AS DWORD
    uBeaconSize           AS DWORD
    uIHVDataOffset        AS DWORD
    uIHVDataSize          AS DWORD

    ' The following fields are applicable for successful association.
    ' For association failure, they must be zero-ed out.
    AuthAlgo              AS DOT11_AUTH_ALGORITHM_enum
    UnicastCipher         AS DOT11_CIPHER_ALGORITHM_enum
    MulticastCipher       AS DOT11_CIPHER_ALGORITHM_enum
    uActivePhyListOffset  AS DWORD
    uActivePhyListSize    AS DWORD
    bFourAddressSupported AS LONG  ' BOOLEAN
    bPortAuthorized       AS LONG  ' BOOLEAN

    ' The QoS protocol which is used in this association.
    ' It is zero or combination of DOT11_QOS_PROTOCOL_FLAG_WMM and/or DOT11_QOS_PROTOCOL_FLAG_11E
    ucActiveQoSProtocol   AS BYTE  ' UCHAR

    DSInfo                AS DOT11_DS_INFO_enum
    uEncapTableOffset     AS DWORD
    uEncapTableSize       AS DWORD
END TYPE

%DOT11_CONNECTION_START_PARAMETERS_REVISION_1 =  1
TYPE DOT11_CONNECTION_START_PARAMETERS
    HEADER     AS NDIS_OBJECT_HEADER
    BSSType    AS DOT11_BSS_TYPE_enum

    AdhocBSSID AS DOT11_MAC_ADDRESS   ' applicable to adhoc mode only
    AdhocSSID  AS DOT11_SSID          ' applicable to adhoc mode only
END TYPE

' For uStatus in DOT11_CONNECTION_COMPLETION_PARAMETERS and DOT11_ROAMING_COMPLETION_PARAMETERS
%DOT11_CONNECTION_STATUS_SUCCESS                  = %DOT11_ASSOC_STATUS_SUCCESS
%DOT11_CONNECTION_STATUS_FAILURE                  = %DOT11_ASSOC_STATUS_FAILURE
%DOT11_CONNECTION_STATUS_CANDIDATE_LIST_EXHAUSTED = %DOT11_ASSOC_STATUS_CANDIDATE_LIST_EXHAUSTED
%DOT11_CONNECTION_STATUS_PHY_POWER_DOWN           = %DOT11_ASSOC_STATUS_RADIO_OFF
%DOT11_CONNECTION_STATUS_CANCELLED                = %DOT11_ASSOC_STATUS_CANCELLED
%DOT11_CONNECTION_STATUS_IHV_START                = %DOT11_ASSOC_STATUS_IHV_START
%DOT11_CONNECTION_STATUS_IHV_END                  = %DOT11_ASSOC_STATUS_IHV_END
%DOT11_CONNECTION_COMPLETION_PARAMETERS_REVISION_1 = 1

TYPE DOT11_CONNECTION_COMPLETION_PARAMETERS
    HEADER  AS NDIS_OBJECT_HEADER
    uStatus AS DOT11_ASSOC_STATUS   ' DOT11_CONNECTION_STATUS_XXXX
END TYPE

%DOT11_ROAMING_REASON_BETTER_AP_FOUND  = %DOT11_ASSOC_STATUS_ROAMING_BETTER_AP_FOUND
%DOT11_ROAMING_REASON_ASSOCIATION_LOST = %DOT11_ASSOC_STATUS_ROAMING_ASSOCIATION_LOST
%DOT11_ROAMING_REASON_ADHOC            = %DOT11_ASSOC_STATUS_ROAMING_ADHOC
%DOT11_ROAMING_REASON_IHV_START        = %DOT11_ASSOC_STATUS_IHV_START
%DOT11_ROAMING_REASON_IHV_END          = %DOT11_ASSOC_STATUS_IHV_END
%DOT11_ROAMING_START_PARAMETERS_REVISION_1 = 1

TYPE DOT11_ROAMING_START_PARAMETERS
    HEADER         AS NDIS_OBJECT_HEADER
    AdhocBSSID     AS DOT11_MAC_ADDRESS    ' applicable to adhoc mode only
    AdhocSSID      AS DOT11_SSID           ' applicable to adhoc mode only
    uRoamingReason AS DOT11_ASSOC_STATUS
END TYPE

%DOT11_ROAMING_COMPLETION_PARAMETERS_REVISION_1 =  1
TYPE DOT11_ROAMING_COMPLETION_PARAMETERS
    HEADER  AS NDIS_OBJECT_HEADER
    uStatus AS DOT11_ASSOC_STATUS   ' DOT11_CONNECTION_STATUS_XXXX
END TYPE

' Disassociation Reason Code
%DOT11_DISASSOC_REASON_OS                 = %DOT11_ASSOC_STATUS_DISASSOCIATED_BY_OS
%DOT11_DISASSOC_REASON_PEER_UNREACHABLE   = %DOT11_ASSOC_STATUS_UNREACHABLE

' Current association is disassocated because the NIC receives an
' 802.11 de-authentication frame from the peer. The lowest 16-bits
' are the reason code (2-byte) copied from the 802.11 DeAuthentication frame.
%DOT11_DISASSOC_REASON_PEER_DEAUTHENTICATED = %DOT11_ASSOC_STATUS_PEER_DEAUTHENTICATED

' Current association is disassocated because the NIC receives an
' 802.11 disassociation frame from the peer. The lowest 16-bits
' are the reason code (2-byte) copied from the 802.11 disassociation frame.
%DOT11_DISASSOC_REASON_PEER_DISASSOCIATED   = %DOT11_ASSOC_STATUS_PEER_DISASSOCIATED

%DOT11_DISASSOC_REASON_RADIO_OFF            = %DOT11_ASSOC_STATUS_RADIO_OFF
%DOT11_DISASSOC_REASON_PHY_DISABLED         = %DOT11_ASSOC_STATUS_PHY_DISABLED
%DOT11_DISASSOC_REASON_IHV_START            = %DOT11_ASSOC_STATUS_IHV_START
%DOT11_DISASSOC_REASON_IHV_END              = %DOT11_ASSOC_STATUS_IHV_END
%DOT11_DISASSOCIATION_PARAMETERS_REVISION_1 =  1

TYPE DOT11_DISASSOCIATION_PARAMETERS
    HEADER         AS NDIS_OBJECT_HEADER
    MacAddr        AS DOT11_MAC_ADDRESS
    uReason        AS DOT11_ASSOC_STATUS
    uIHVDataOffset AS DWORD
    uIHVDataSize   AS DWORD
END TYPE

%DOT11_TKIPMIC_FAILURE_PARAMETERS_REVISION_1 =  1
TYPE DOT11_TKIPMIC_FAILURE_PARAMETERS
    HEADER             AS NDIS_OBJECT_HEADER
    bDefaultKeyFailure AS BYTE  ' BOOLEAN
    uKeyIndex          AS DWORD
    PeerMac            AS DOT11_MAC_ADDRESS
END TYPE

%DOT11_PMKID_CANDIDATE_LIST_PARAMETERS_REVISION_1 =  1
TYPE DOT11_PMKID_CANDIDATE_LIST_PARAMETERS
    HEADER               AS NDIS_OBJECT_HEADER
    uCandidateListSize   AS DWORD
    uCandidateListOffset AS DWORD
END TYPE

%DOT11_PMKID_CANDIDATE_PREAUTH_ENABLED   = &H00000001???
TYPE DOT11_BSSID_CANDIDATE
    BSSID AS DOT11_MAC_ADDRESS
    uFlags AS DWORD
END TYPE

%DOT11_PHY_STATE_PARAMETERS_REVISION_1 =  1
TYPE DOT11_PHY_STATE_PARAMETERS
    HEADER            AS NDIS_OBJECT_HEADER
    uPhyId            AS DWORD
    bHardwarePhyState AS BYTE  ' BOOLEAN
    bSoftwarePhyState AS BYTE  ' BOOLEAN
END TYPE

TYPE DOT11_LINK_QUALITY_ENTRY
    PeerMacAddr   AS DOT11_MAC_ADDRESS
    ucLinkQuality AS BYTE
END TYPE

%DOT11_LINK_QUALITY_PARAMETERS_REVISION_1 =  1

TYPE DOT11_LINK_QUALITY_PARAMETERS
    HEADER                 AS NDIS_OBJECT_HEADER
    uLinkQualityListSize   AS DWORD
    uLinkQualityListOffset AS DWORD
END TYPE


' Send OOB data for ExtSTA mode
%DOT11_EXTSTA_SEND_CONTEXT_REVISION_1 =  1
TYPE DOT11_EXTSTA_SEND_CONTEXT
    HEADER                AS NDIS_OBJECT_HEADER
    usExemptionActionType AS WORD
    uPhyId                AS DWORD
    uDelayedSleepValue    AS DWORD

    pvMediaSpecificInfo   AS DWORD  ' PVOID

    uSendFlags            AS DWORD  ' reserved field for safe mode wireless
END TYPE

' Recv OOB data for ExtSTA mode
%DOT11_RECV_FLAG_RAW_PACKET              = &H00000001
%DOT11_RECV_FLAG_RAW_PACKET_FCS_FAILURE  = &H00000002
%DOT11_RECV_FLAG_RAW_PACKET_TIMESTAMP    = &H00000004
%DOT11_EXTSTA_RECV_CONTEXT_REVISION_1 =  1

TYPE DOT11_EXTSTA_RECV_CONTEXT
    HEADER                  AS NDIS_OBJECT_HEADER
    uReceiveFlags           AS DWORD
    uPhyId                  AS DWORD
    uChCenterFrequency      AS DWORD
    usNumberOfMPDUsReceived AS WORD
    lRSSI                   AS LONG
    ucDataRate              AS BYTE
    uSizeMediaSpecificInfo  AS DWORD
    pvMediaSpecificInfo     AS DWORD  ' PVOID
    ullTimestamp            AS QUAD   ' ULONGLONG
END TYPE

'
' Private 802.11 OIDs: this should be the last section
'
' We reserve 1024 entries for real DOT11 OIDs
'

%OID_DOT11_PRIVATE_OIDS_START              = (%OID_DOT11_NDIS_START + 1024)

%OID_DOT11_CURRENT_ADDRESS                 = (%OID_DOT11_PRIVATE_OIDS_START + 2)
' DOT11_MAC_ADDRESS

%OID_DOT11_PERMANENT_ADDRESS               = (%OID_DOT11_PRIVATE_OIDS_START + 3)
' DOT11_MAC_ADDRESS

%OID_DOT11_MULTICAST_LIST                  = (%OID_DOT11_PRIVATE_OIDS_START + 4)
' OID_802_3_MULTICAST_LIST

%OID_DOT11_MAXIMUM_LIST_SIZE               = (%OID_DOT11_PRIVATE_OIDS_START + 5)


' GUIDs for WMI

'MACRO DEFINE_NWF_GUID(gname,ord)
'    gname = GUID$("{"+HEX$(&H6cb9a43e+(ord),8)+"-c45f-4039-9fe6-d08cb057184c}")
'END MACRO


MACRO GUID_NWF_OFFLOAD_CAPABILITY=GUID$("{"+HEX$(&H6CB9A43E+0,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CURRENT_OFFLOAD_CAPABILITY=GUID$("{"+HEX$(&H6CB9A43E+1,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_WEP_OFFLOAD=GUID$("{"+HEX$(&H6CB9A43E+2,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_WEP_UPLOAD=GUID$("{"+HEX$(&H6CB9A43E+3,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_DEFAULT_WEP_OFFLOAD=GUID$("{"+HEX$(&H6CB9A43E+4,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_DEFAULT_WEP_UPLOAD=GUID$("{"+HEX$(&H6CB9A43E+5,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_MPDU_MAX_LENGTH=GUID$("{"+HEX$(&H6CB9A43E+6,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_OPERATION_MODE_CAPABILITY=GUID$("{"+HEX$(&H6CB9A43E+7,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CURRENT_OPERATION_MODE=GUID$("{"+HEX$(&H6CB9A43E+8,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CURRENT_PACKET_FILTER=GUID$("{"+HEX$(&H6CB9A43E+9,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_ATIM_WINDOW=GUID$("{"+HEX$(&H6CB9A43E+10,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_SCAN_REQUEST=GUID$("{"+HEX$(&H6CB9A43E+11,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CURRENT_PHY_TYPE=GUID$("{"+HEX$(&H6CB9A43E+12,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_JOIN_REQUEST=GUID$("{"+HEX$(&H6CB9A43E+13,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_START_REQUEST=GUID$("{"+HEX$(&H6CB9A43E+14,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_UPDATE_IE=GUID$("{"+HEX$(&H6CB9A43E+15,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_RESET_REQUEST=GUID$("{"+HEX$(&H6CB9A43E+16,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_NIC_POWER_STATE=GUID$("{"+HEX$(&H6CB9A43E+17,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_OPTIONAL_CAPABILITY=GUID$("{"+HEX$(&H6CB9A43E+18,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CURRENT_OPTIONAL_CAPABILITY=GUID$("{"+HEX$(&H6CB9A43E+19,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_STATION_ID=GUID$("{"+HEX$(&H6CB9A43E+20,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_MEDIUM_OCCUPANCY_LIMIT=GUID$("{"+HEX$(&H6CB9A43E+21,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CF_POLLABLE=GUID$("{"+HEX$(&H6CB9A43E+22,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CFP_PERIOD=GUID$("{"+HEX$(&H6CB9A43E+23,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CFP_MAX_DURATION=GUID$("{"+HEX$(&H6CB9A43E+24,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_POWER_MGMT_MODE=GUID$("{"+HEX$(&H6CB9A43E+25,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_OPERATIONAL_RATE_SET=GUID$("{"+HEX$(&H6CB9A43E+26,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_BEACON_PERIOD=GUID$("{"+HEX$(&H6CB9A43E+27,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_DTIM_PERIOD=GUID$("{"+HEX$(&H6CB9A43E+28,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_WEP_ICV_ERROR_COUNT=GUID$("{"+HEX$(&H6CB9A43E+29,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_MAC_ADDRESS=GUID$("{"+HEX$(&H6CB9A43E+30,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_RTS_THRESHOLD=GUID$("{"+HEX$(&H6CB9A43E+31,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_SHORT_RETRY_LIMIT=GUID$("{"+HEX$(&H6CB9A43E+32,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_LONG_RETRY_LIMIT=GUID$("{"+HEX$(&H6CB9A43E+33,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_FRAGMENTATION_THRESHOLD=GUID$("{"+HEX$(&H6CB9A43E+34,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_MAX_TRANSMIT_MSDU_LIFETIME=GUID$("{"+HEX$(&H6CB9A43E+35,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_MAX_RECEIVE_LIFETIME=GUID$("{"+HEX$(&H6CB9A43E+36,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_COUNTERS_ENTRY=GUID$("{"+HEX$(&H6CB9A43E+37,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_SUPPORTED_PHY_TYPES=GUID$("{"+HEX$(&H6CB9A43E+38,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CURRENT_REG_DOMAIN=GUID$("{"+HEX$(&H6CB9A43E+39,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_TEMP_TYPE=GUID$("{"+HEX$(&H6CB9A43E+40,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CURRENT_TX_ANTENNA=GUID$("{"+HEX$(&H6CB9A43E+41,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_DIVERSITY_SUPPORT=GUID$("{"+HEX$(&H6CB9A43E+42,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CURRENT_RX_ANTENNA=GUID$("{"+HEX$(&H6CB9A43E+43,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_SUPPORTED_POWER_LEVELS=GUID$("{"+HEX$(&H6CB9A43E+44,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CURRENT_TX_POWER_LEVEL=GUID$("{"+HEX$(&H6CB9A43E+45,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_HOP_TIME=GUID$("{"+HEX$(&H6CB9A43E+46,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CURRENT_CHANNEL_NUMBER=GUID$("{"+HEX$(&H6CB9A43E+47,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_MAX_DWELL_TIME=GUID$("{"+HEX$(&H6CB9A43E+48,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CURRENT_DWELL_TIME=GUID$("{"+HEX$(&H6CB9A43E+49,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CURRENT_SET=GUID$("{"+HEX$(&H6CB9A43E+50,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CURRENT_PATTERN=GUID$("{"+HEX$(&H6CB9A43E+51,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CURRENT_INDEX=GUID$("{"+HEX$(&H6CB9A43E+52,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CURRENT_CHANNEL=GUID$("{"+HEX$(&H6CB9A43E+53,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CCA_MODE_SUPPORTED=GUID$("{"+HEX$(&H6CB9A43E+54,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CURRENT_CCA_MODE=GUID$("{"+HEX$(&H6CB9A43E+55,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_ED_THRESHOLD=GUID$("{"+HEX$(&H6CB9A43E+56,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CCA_WATCHDOG_TIMER_MAX=GUID$("{"+HEX$(&H6CB9A43E+57,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CCA_WATCHDOG_COUNT_MAX=GUID$("{"+HEX$(&H6CB9A43E+58,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CCA_WATCHDOG_TIMER_MIN=GUID$("{"+HEX$(&H6CB9A43E+59,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CCA_WATCHDOG_COUNT_MIN=GUID$("{"+HEX$(&H6CB9A43E+60,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_REG_DOMAINS_SUPPORT_VALUE=GUID$("{"+HEX$(&H6CB9A43E+61,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_SUPPORTED_TX_ANTENNA=GUID$("{"+HEX$(&H6CB9A43E+62,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_SUPPORTED_RX_ANTENNA=GUID$("{"+HEX$(&H6CB9A43E+63,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_DIVERSITY_SELECTION_RX=GUID$("{"+HEX$(&H6CB9A43E+64,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_SUPPORTED_DATA_RATES_VALUE=GUID$("{"+HEX$(&H6CB9A43E+65,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CURRENT_FREQUENCY=GUID$("{"+HEX$(&H6CB9A43E+66,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_TI_THRESHOLD=GUID$("{"+HEX$(&H6CB9A43E+67,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_FREQUENCY_BANDS_SUPPORTED=GUID$("{"+HEX$(&H6CB9A43E+68,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_SHORT_PREAMBLE_OPTION_IMPLEMENTED=GUID$("{"+HEX$(&H6CB9A43E+69,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_PBCC_OPTION_IMPLEMENTED=GUID$("{"+HEX$(&H6CB9A43E+70,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CHANNEL_AGILITY_PRESENT=GUID$("{"+HEX$(&H6CB9A43E+71,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CHANNEL_AGILITY_ENABLED=GUID$("{"+HEX$(&H6CB9A43E+72,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_HR_CCA_MODE_SUPPORTED=GUID$("{"+HEX$(&H6CB9A43E+73,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_MULTI_DOMAIN_CAPABILITY_IMPLEMENTED=GUID$("{"+HEX$(&H6CB9A43E+74,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_MULTI_DOMAIN_CAPABILITY_ENABLED=GUID$("{"+HEX$(&H6CB9A43E+75,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_COUNTRY_STRING=GUID$("{"+HEX$(&H6CB9A43E+76,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_MULTI_DOMAIN_CAPABILITY=GUID$("{"+HEX$(&H6CB9A43E+77,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_EHCC_PRIME_RADIX=GUID$("{"+HEX$(&H6CB9A43E+78,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_EHCC_NUMBER_OF_CHANNELS_FAMILY_INDEX=GUID$("{"+HEX$(&H6CB9A43E+79,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_EHCC_CAPABILITY_IMPLEMENTED=GUID$("{"+HEX$(&H6CB9A43E+80,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_EHCC_CAPABILITY_ENABLED=GUID$("{"+HEX$(&H6CB9A43E+81,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_HOP_ALGORITHM_ADOPTED=GUID$("{"+HEX$(&H6CB9A43E+82,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_RANDOM_TABLE_FLAG=GUID$("{"+HEX$(&H6CB9A43E+83,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_NUMBER_OF_HOPPING_SETS=GUID$("{"+HEX$(&H6CB9A43E+84,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_HOP_MODULUS=GUID$("{"+HEX$(&H6CB9A43E+85,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_HOP_OFFSET=GUID$("{"+HEX$(&H6CB9A43E+86,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_HOPPING_PATTERN=GUID$("{"+HEX$(&H6CB9A43E+87,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_RANDOM_TABLE_FIELD_NUMBER=GUID$("{"+HEX$(&H6CB9A43E+88,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_WPA_TSC=GUID$("{"+HEX$(&H6CB9A43E+89,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_RSSI_RANGE=GUID$("{"+HEX$(&H6CB9A43E+90,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_RF_USAGE=GUID$("{"+HEX$(&H6CB9A43E+91,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_NIC_SPECIFIC_EXTENSION=GUID$("{"+HEX$(&H6CB9A43E+92,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_AP_JOIN_REQUEST=GUID$("{"+HEX$(&H6CB9A43E+93,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_ERP_PBCC_OPTION_IMPLEMENTED=GUID$("{"+HEX$(&H6CB9A43E+94,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_ERP_PBCC_OPTION_ENABLED=GUID$("{"+HEX$(&H6CB9A43E+95,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_DSSS_OFDM_OPTION_IMPLEMENTED=GUID$("{"+HEX$(&H6CB9A43E+96,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_DSSS_OFDM_OPTION_ENABLED=GUID$("{"+HEX$(&H6CB9A43E+97,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_SHORT_SLOT_TIME_OPTION_IMPLEMENTED=GUID$("{"+HEX$(&H6CB9A43E+98,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_SHORT_SLOT_TIME_OPTION_ENABLED=GUID$("{"+HEX$(&H6CB9A43E+99,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_MAX_MAC_ADDRESS_STATES=GUID$("{"+HEX$(&H6CB9A43E+100,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_RECV_SENSITIVITY_LIST=GUID$("{"+HEX$(&H6CB9A43E+101,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_WME_IMPLEMENTED=GUID$("{"+HEX$(&H6CB9A43E+102,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_WME_ENABLED=GUID$("{"+HEX$(&H6CB9A43E+103,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_WME_AC_PARAMETERS=GUID$("{"+HEX$(&H6CB9A43E+104,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_WME_UPDATE_IE=GUID$("{"+HEX$(&H6CB9A43E+105,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_QOS_TX_QUEUES_SUPPORTED=GUID$("{"+HEX$(&H6CB9A43E+106,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_QOS_TX_DURATION=GUID$("{"+HEX$(&H6CB9A43E+107,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_QOS_TX_MEDIUM_TIME=GUID$("{"+HEX$(&H6CB9A43E+108,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_SUPPORTED_OFDM_FREQUENCY_LIST=GUID$("{"+HEX$(&H6CB9A43E+109,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_SUPPORTED_DSSS_CHANNEL_LIST=GUID$("{"+HEX$(&H6CB9A43E+110,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_AUTO_CONFIG_ENABLED=GUID$("{"+HEX$(&H6CB9A43E+120,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_ENUM_BSS_LIST=GUID$("{"+HEX$(&H6CB9A43E+121,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_FLUSH_BSS_LIST=GUID$("{"+HEX$(&H6CB9A43E+122,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_POWER_MGMT_REQUEST=GUID$("{"+HEX$(&H6CB9A43E+123,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_DESIRED_SSID_LIST=GUID$("{"+HEX$(&H6CB9A43E+124,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_EXCLUDED_MAC_ADDRESS_LIST=GUID$("{"+HEX$(&H6CB9A43E+125,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_DESIRED_BSSID_LIST=GUID$("{"+HEX$(&H6CB9A43E+126,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_DESIRED_BSS_TYPE=GUID$("{"+HEX$(&H6CB9A43E+127,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_PMKID_LIST=GUID$("{"+HEX$(&H6CB9A43E+128,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CONNECT_REQUEST=GUID$("{"+HEX$(&H6CB9A43E+129,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_EXCLUDE_UNENCRYPTED=GUID$("{"+HEX$(&H6CB9A43E+130,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_STATISTICS=GUID$("{"+HEX$(&H6CB9A43E+131,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_PRIVACY_EXEMPTION_LIST=GUID$("{"+HEX$(&H6CB9A43E+132,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_ENABLED_AUTHENTICATION_ALGORITHM=GUID$("{"+HEX$(&H6CB9A43E+133,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_SUPPORTED_UNICAST_ALGORITHM_PAIR=GUID$("{"+HEX$(&H6CB9A43E+134,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_ENABLED_UNICAST_CIPHER_ALGORITHM=GUID$("{"+HEX$(&H6CB9A43E+135,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_SUPPORTED_MULTICAST_ALGORITHM_PAIR=GUID$("{"+HEX$(&H6CB9A43E+136,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_ENABLED_MULTICAST_CIPHER_ALGORITHM=GUID$("{"+HEX$(&H6CB9A43E+137,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CIPHER_DEFAULT_KEY_ID=GUID$("{"+HEX$(&H6CB9A43E+138,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CIPHER_DEFAULT_KEY=GUID$("{"+HEX$(&H6CB9A43E+139,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CIPHER_KEY_MAPPING_KEY=GUID$("{"+HEX$(&H6CB9A43E+140,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_ENUM_ASSOCIATION_INFO=GUID$("{"+HEX$(&H6CB9A43E+141,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_DISCONNECT_REQUEST=GUID$("{"+HEX$(&H6CB9A43E+142,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_UNICAST_USE_GROUP_ENABLED=GUID$("{"+HEX$(&H6CB9A43E+143,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_PHY_STATE=GUID$("{"+HEX$(&H6CB9A43E+144,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_DESIRED_PHY_LIST=GUID$("{"+HEX$(&H6CB9A43E+145,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_CURRENT_PHY_ID=GUID$("{"+HEX$(&H6CB9A43E+146,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_MEDIA_STREAMING_ENABLED=GUID$("{"+HEX$(&H6CB9A43E+147,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_UNREACHABLE_DETECTION_THRESHOLD=GUID$("{"+HEX$(&H6CB9A43E+148,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_ACTIVE_PHY_LIST=GUID$("{"+HEX$(&H6CB9A43E+149,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_EXTSTA_CAPABILITY=GUID$("{"+HEX$(&H6CB9A43E+150,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_DATA_RATE_MAPPING_TABLE=GUID$("{"+HEX$(&H6CB9A43E+151,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_SUPPORTED_COUNTRY_OR_REGION_STRING=GUID$("{"+HEX$(&H6CB9A43E+152,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_DESIRED_COUNTRY_OR_REGION_STRING=GUID$("{"+HEX$(&H6CB9A43E+153,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_PORT_STATE_NOTIFICATION=GUID$("{"+HEX$(&H6CB9A43E+154,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_IBSS_PARAMS=GUID$("{"+HEX$(&H6CB9A43E+155,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_QOS_PARAMS=GUID$("{"+HEX$(&H6CB9A43E+156,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_SAFE_MODE_ENABLED=GUID$("{"+HEX$(&H6CB9A43E+157,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_HIDDEN_NETWORK_ENABLED=GUID$("{"+HEX$(&H6CB9A43E+158,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_ASSOCIATION_PARAMS=GUID$("{"+HEX$(&H6CB9A43E+159,8)+"-c45f-4039-9fe6-d08cb057184c}")

MACRO GUID_NWF_CURRENT_ADDRESS=GUID$("{"+HEX$(&H6CB9A43E+1024+2,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_PERMANENT_ADDRESS=GUID$("{"+HEX$(&H6CB9A43E+1024+3,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_MULTICAST_LIST=GUID$("{"+HEX$(&H6CB9A43E+1024+4,8)+"-c45f-4039-9fe6-d08cb057184c}")
MACRO GUID_NWF_MAXIMUM_LIST_SIZE=GUID$("{"+HEX$(&H6CB9A43E+1024+5,8)+"-c45f-4039-9fe6-d08cb057184c}")

#ENDIF  ' (%NTDDI_VERSION > %NTDDI_VISTA)




#IF %DEF(%NWF_EXTAP_SUPPORTED)



%DOT11_EXTAP_ATTRIBUTES_REVISION_1 =  1

TYPE DOT11_EXTAP_ATTRIBUTES DWORD FILL
    HEADER                    AS NDIS_OBJECT_HEADER  ' [4 bytes]

    uScanSSIDListSize         AS DWORD
    uDesiredSSIDListSize      AS DWORD
    uPrivacyExemptionListSize AS DWORD
    uAssociationTableSize     AS DWORD
    uDefaultKeyTableSize      AS DWORD
    uWEPKeyValueMaxLength     AS DWORD
    bStrictlyOrderedServiceClassImplemented AS BYTE  ' BOOLEAN

    ' Supported Country Strings
    uNumSupportedCountryOrRegionStrings AS DWORD
    pSupportedCountryOrRegionStrings    AS DWORD  ' STRING * 3 PTR



    ' Unicast algorithm capabilities
    uInfraNumSupportedUcastAlgoPairs AS DWORD
    pInfraSupportedUcastAlgoPairs    AS DOT11_AUTH_CIPHER_PAIR PTR


    ' Multicast algorithm capabilities
    uInfraNumSupportedMcastAlgoPairs AS DWORD
    pInfraSupportedMcastAlgoPairs    AS DOT11_AUTH_CIPHER_PAIR PTR

END TYPE

%NDIS_SIZEOF_DOT11_EXTAP_ATTRIBUTES_REVISION_1 = 13*4+1 ' sizeof(DOT11_EXTAP_ATTRIBUTES)



' NDIS indications for Ext AP mode.



' Data type for NDIS_STATUS_DOT11_INCOMING_ASSOC_STARTED

%DOT11_INCOMING_ASSOC_STARTED_PARAMETERS_REVISION_1 =  1

TYPE DOT11_INCOMING_ASSOC_STARTED_PARAMETERS
    HEADER      AS NDIS_OBJECT_HEADER
    PeerMacAddr AS DOT11_MAC_ADDRESS
END TYPE



' Data type for NDIS_STATUS_DOT11_INCOMING_ASSOC_REQUEST_RECEIVED

%DOT11_INCOMING_ASSOC_REQUEST_RECEIVED_PARAMETERS_REVISION_1 =  1

TYPE DOT11_INCOMING_ASSOC_REQUEST_RECEIVED_PARAMETERS
    HEADER          AS NDIS_OBJECT_HEADER
    PeerMacAddr     AS DOT11_MAC_ADDRESS
    bReAssocReq     AS BYTE  ' BOOLEAN
    uAssocReqOffset AS DWORD
    uAssocReqSize   AS DWORD
END TYPE




' Data type for NDIS_STATUS_DOT11_INCOMING_ASSOC_COMPLETION

%DOT11_ASSOC_ERROR_SOURCE_OS         = &H0000
%DOT11_ASSOC_ERROR_SOURCE_REMOTE     = &H0001
%DOT11_ASSOC_ERROR_SOURCE_OTHER      = &H00FF


%DOT11_INCOMING_ASSOC_COMPLETION_PARAMETERS_REVISION_1 =  1

TYPE DOT11_INCOMING_ASSOC_COMPLETION_PARAMETERS
    HEADER           AS NDIS_OBJECT_HEADER
    PeerMacAddr      AS DOT11_MAC_ADDRESS

    uStatus          AS DWORD
    ucErrorSource    AS BYTE

    bReAssocReq      AS BYTE  ' BOOLEAN
    bReAssocResp     AS BYTE  ' BOOLEAN

    uAssocReqOffset  AS DWORD
    uAssocReqSize    AS DWORD

    uAssocRespOffset AS DWORD
    uAssocRespSize   AS DWORD

    ' The following fields are applicable for successful association.
    ' For association failure, they must be zero-ed out.

    AuthAlgo             AS DOT11_AUTH_ALGORITHM_enum
    UnicastCipher        AS DOT11_CIPHER_ALGORITHM_enum
    MulticastCipher      AS DOT11_CIPHER_ALGORITHM_enum
    uActivePhyListOffset AS DWORD
    uActivePhyListSize   AS DWORD

    uBeaconOffset    AS DWORD
    uBeaconSize      AS DWORD
END TYPE   ' DOT11_INCOMING_ASSOC_COMPLETION_PARAMETERS


' Data type for NDIS_STATUS_DOT11_STOP_AP

%DOT11_STOP_AP_PARAMETERS_REVISION_1 =  1

TYPE DOT11_STOP_AP_PARAMETERS
    HEADER   AS NDIS_OBJECT_HEADER
    ulReason AS DWORD
END TYPE


%DOT11_STOP_AP_REASON_FREQUENCY_NOT_AVAILABLE    = &H1
%DOT11_STOP_AP_REASON_CHANNEL_NOT_AVAILABLE      = &H2
%DOT11_STOP_AP_REASON_AP_ACTIVE                  = &H3


%DOT11_STOP_AP_REASON_IHV_START  = &HFF000000???
%DOT11_STOP_AP_REASON_IHV_END    = &HFFFFFFFF???




' Data type for NDIS_STATUS_DOT11_PHY_FREQUENCY_ADOPTED


%DOT11_PHY_FREQUENCY_ADOPTED_PARAMETERS_REVISION_1 =  1

UNION DOT11_PHY_FREQUENCY_ADOPTED_PARAMETERS_union
    ulChannel   AS DWORD
    ulFrequency AS DWORD
END UNION

TYPE DOT11_PHY_FREQUENCY_ADOPTED_PARAMETERS
    HEADER  AS NDIS_OBJECT_HEADER
    ulPhyId AS DWORD
    DOT11_PHY_FREQUENCY_ADOPTED_PARAMETERS_union
END TYPE



' Data type for NDIS_STATUS_DOT11_CAN_SUSTAIN_AP

%DOT11_CAN_SUSTAIN_AP_PARAMETERS_REVISION_1 =  1

TYPE DOT11_CAN_SUSTAIN_AP_PARAMETERS
    HEADER   AS NDIS_OBJECT_HEADER
    ulReason AS DWORD
END TYPE


%DOT11_CAN_SUSTAIN_AP_REASON_IHV_START   = &HFF000000???
%DOT11_CAN_SUSTAIN_AP_REASON_IHV_END     = &HFFFFFFFF???



' TAG for Ext AP specific OIDs.
%NWF_EXTAP_OID      = &H03



MACRO OID_DOT11_WPS_ENABLED=NWF_DEFINE_OID(&H01,%NWF_EXTAP_OID,%NWF_MANDATORY_OID)
' BOOLEAN



MACRO OID_DOT11_START_AP_REQUEST=NWF_DEFINE_OID(&H02,%NWF_EXTAP_OID,%NWF_MANDATORY_OID)
' VOID



MACRO OID_DOT11_AVAILABLE_CHANNEL_LIST=NWF_DEFINE_OID(&H03,%NWF_EXTAP_OID,%NWF_MANDATORY_OID)
' DOT11_AVAILABLE_CHANNEL_LIST

%DOT11_AVAILABLE_CHANNEL_LIST_REVISION_1 = 1

TYPE DOT11_AVAILABLE_CHANNEL_LIST
    HEADER             AS NDIS_OBJECT_HEADER
    uNumOfEntries      AS DWORD
    uTotalNumOfEntries AS DWORD
    uChannelNumber(0)  AS DWORD
END TYPE



MACRO OID_DOT11_AVAILABLE_FREQUENCY_LIST=NWF_DEFINE_OID(&H04,%NWF_EXTAP_OID,%NWF_MANDATORY_OID)
' DOT11_AVAILABLE_FREQUENCY_LIST


%DOT11_AVAILABLE_FREQUENCY_LIST_REVISION_1 = 1

TYPE DOT11_AVAILABLE_FREQUENCY_LIST
    HEADER             AS NDIS_OBJECT_HEADER
    uNumOfEntries      AS DWORD
    uTotalNumOfEntries AS DWORD
    uFrequencyValue(0) AS DWORD
END TYPE



MACRO OID_DOT11_DISASSOCIATE_PEER_REQUEST=NWF_DEFINE_OID(&H05,%NWF_EXTAP_OID,%NWF_MANDATORY_OID)
' DOT11_DISASSOCIATE_PEER_REQUEST

%DOT11_DISASSOCIATE_PEER_REQUEST_REVISION_1 = 1

TYPE DOT11_DISASSOCIATE_PEER_REQUEST
    HEADER      AS NDIS_OBJECT_HEADER
    PeerMacAddr AS DOT11_MAC_ADDRESS
    usReason    AS WORD
END TYPE



MACRO OID_DOT11_INCOMING_ASSOCIATION_DECISION=NWF_DEFINE_OID(&H06,%NWF_EXTAP_OID,%NWF_MANDATORY_OID)
    ' DOT11_INCOMING_ASSOC_DECISION

%DOT11_INCOMING_ASSOC_DECISION_REVISION_1 = 1

TYPE DOT11_INCOMING_ASSOC_DECISION
    HEADER                  AS NDIS_OBJECT_HEADER
    PeerMacAddr             AS DOT11_MAC_ADDRESS
    bAccept                 AS BYTE  ' BOOLEAN
    usReasonCode            AS WORD
    uAssocResponseIEsOffset AS DWORD
    uAssocResponseIEsLength AS DWORD
END TYPE




MACRO OID_DOT11_ADDITIONAL_IE=NWF_DEFINE_OID(&H07,%NWF_EXTAP_OID,%NWF_MANDATORY_OID)
' DOT11_ADDITIONAL_IE

%DOT11_ADDITIONAL_IE_REVISION_1 = 1

TYPE DOT11_ADDITIONAL_IE
    HEADER             AS NDIS_OBJECT_HEADER
    uBeaconIEsOffset   AS DWORD
    uBeaconIEsLength   AS DWORD
    uResponseIEsOffset AS DWORD
    uResponseIEsLength AS DWORD
END TYPE



'
' Ext AP Send context
'
%DOT11_EXTAP_SEND_CONTEXT_REVISION_1 =  1


'typedef
'struct DOT11_EXTSTA_SEND_CONTEXT
'DOT11_EXTAP_SEND_CONTEXT, *PDOT11_EXTAP_SEND_CONTEXT;



'
' Ext AP Receive context
'
%DOT11_EXTAP_RECV_CONTEXT_REVISION_1 =  1


'typedef
'struct DOT11_EXTSTA_RECV_CONTEXT
'DOT11_EXTAP_RECV_CONTEXT, *PDOT11_EXTAP_RECV_CONTEXT;




MACRO OID_DOT11_ENUM_PEER_INFO=NWF_DEFINE_OID(&H08,%NWF_EXTAP_OID,%NWF_MANDATORY_OID)
' DOT11_PEER_INFO_LIST

TYPE DOT11_PEER_STATISTICS
    ullDecryptSuccessCount  AS QUAD  ' ULONGLONG
    ullDecryptFailureCount  AS QUAD  ' ULONGLONG
    ullTxPacketSuccessCount AS QUAD  ' ULONGLONG
    ullTxPacketFailureCount AS QUAD  ' ULONGLONG
    ullRxPacketSuccessCount AS QUAD  ' ULONGLONG
    ullRxPacketFailureCount AS QUAD  ' ULONGLONG
END TYPE

TYPE DOT11_PEER_INFO
    MacAddress              AS DOT11_MAC_ADDRESS
    usCapabilityInformation AS WORD
    AuthAlgo                AS DOT11_AUTH_ALGORITHM_enum
    UnicastCipherAlgo       AS DOT11_CIPHER_ALGORITHM_enum
    MulticastCipherAlgo     AS DOT11_CIPHER_ALGORITHM_enum
    bWpsEnabled             AS BYTE  ' BOOLEAN
    usListenInterval        AS WORD
    ucSupportedRates(%MAX_NUM_SUPPORTED_RATES_V2-1) AS BYTE
    usAssociationID         AS WORD
    AssociationState        AS DOT11_ASSOCIATION_STATE_enum
    PowerMode               AS DOT11_POWER_MODE_enum
    liAssociationUpTime     AS QUAD  ' LARGE_INTEGER
    Statistics              AS DOT11_PEER_STATISTICS
END TYPE


%DOT11_PEER_INFO_LIST_REVISION_1 =  1

TYPE DOT11_PEER_INFO_LIST
    HEADER             AS NDIS_OBJECT_HEADER
    uNumOfEntries      AS DWORD
    uTotalNumOfEntries AS DWORD
    PeerInfo(0)        AS DOT11_PEER_INFO
END TYPE



#ENDIF ' NWF_EXTAP_SUPPORTED

#IF %DEF(%NWF_VWIFI_SUPPORTED)

%DOT11_VWIFI_COMBINATION_REVISION_1    =  1

TYPE DOT11_VWIFI_COMBINATION
    HEADER             AS NDIS_OBJECT_HEADER  ' [4 bytes]
    uNumInfrastructure AS DWORD
    uNumAdhoc          AS DWORD
    uNumSoftAP         AS DWORD
END TYPE

%DOT11_SIZEOF_VWIFI_COMBINATION_REVISION_1 = 4*4 ' sizeof(DOT11_VWIFI_COMBINATION)

%DOT11_VWIFI_COMBINATION_REVISION_2   = 2

TYPE DOT11_VWIFI_COMBINATION_V2
    HEADER             AS NDIS_OBJECT_HEADER  ' [4 bytes]
    uNumInfrastructure AS DWORD
    uNumAdhoc          AS DWORD
    uNumSoftAP         AS DWORD
    uNumVirtualStation AS DWORD
END TYPE

%DOT11_SIZEOF_VWIFI_COMBINATION_REVISION_2 = 5*4 ' sizeof(DOT11_VWIFI_COMBINATION_V2)

%DOT11_VWIFI_ATTRIBUTES_REVISION_1    = 1

TYPE DOT11_VWIFI_ATTRIBUTES
    HEADER             AS NDIS_OBJECT_HEADER  ' [4 bytes]
    uTotalNumOfEntries AS DWORD
    Combinations(0)    AS DOT11_VWIFI_COMBINATION
END TYPE

' TAG for Virtual WiFi specific OIDs.
%NWF_VWIFI_OID    = (&H04)


MACRO OID_DOT11_CREATE_MAC=NWF_DEFINE_OID(&H01,%NWF_VWIFI_OID,%NWF_MANDATORY_OID)

TYPE DOT11_MAC_INFO
    uReserved       AS DWORD
    uNdisPortNumber AS DWORD
    MacAddr         AS DOT11_MAC_ADDRESS
END TYPE

MACRO OID_DOT11_DELETE_MAC=NWF_DEFINE_OID(&H02,%NWF_VWIFI_OID,%NWF_MANDATORY_OID)

MACRO OID_DOT11_PREFERRED_MAC=NWF_DEFINE_OID(&H03,%NWF_VWIFI_OID,%NWF_MANDATORY_OID)

MACRO OID_DOT11_VIRTUAL_STATION_CAPABILITY=NWF_DEFINE_OID(&H04,%NWF_VWIFI_OID,%NWF_OPTIONAL_OID)

#ENDIF ' %NWF_VWIFI_SUPPORTED
