'------------------------------------------------------------------------------
'
'  Ws2Atm.inc -- Winsock 2 ATM Annex definitions.
'
'  Copyright (c) 2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from ws2atm.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WS2ATM_H = 1

#INCLUDE "WinSock2.inc"

%ATMPROTO_AALUSER         = &H00   ' User-defined AAL
%ATMPROTO_AAL1            = &H01   ' AAL 1
%ATMPROTO_AAL2            = &H02   ' AAL 2
%ATMPROTO_AAL34           = &H03   ' AAL 3/4
%ATMPROTO_AAL5            = &H05   ' AAL 5

%SAP_FIELD_ABSENT         = &HFFFFFFFE???
%SAP_FIELD_ANY            = &HFFFFFFFF???
%SAP_FIELD_ANY_AESA_SEL   = &HFFFFFFFA???
%SAP_FIELD_ANY_AESA_REST  = &HFFFFFFFB???

'
'  values used for AddressType in struct ATM_ADDRESS
'
%ATM_E164             = &H01   ' E.164 addressing scheme
%ATM_NSAP             = &H02   ' NSAP-style ATM Endsystem Address scheme
%ATM_AESA             = &H02   ' NSAP-style ATM Endsystem Address scheme

%ATM_ADDR_SIZE        = 20

TYPE ATM_ADDRESS DWORD FILL
    AddressType AS DWORD        ' E.164 or NSAP-style ATM Endsystem Address
    NumofDigits AS DWORD        ' number of digits
    ADDR        AS STRING * %ATM_ADDR_SIZE  ' IA5 digits for E164, BCD encoding for NSAP
                                ' format as defined in the ATM Forum UNI 3.1
END TYPE

'
'  values used for Layer2Protocol in B-LLI
'
%BLLI_L2_ISO_1745         = &H01   ' Basic mode ISO 1745
%BLLI_L2_Q921             = &H02   ' CCITT Rec. Q.921
%BLLI_L2_X25L             = &H06   ' CCITT Rec. X.25, link layer
%BLLI_L2_X25M             = &H07   ' CCITT Rec. X.25, multilink
%BLLI_L2_ELAPB            = &H08   ' Extended LAPB for half duplex operation
%BLLI_L2_HDLC_ARM         = &H09   ' HDLC ARM (ISO 4335)
%BLLI_L2_HDLC_NRM         = &H0A   ' HDLC NRM (ISO 4335)
%BLLI_L2_HDLC_ABM         = &H0B   ' HDLC ABM (ISO 4335)
%BLLI_L2_LLC              = &H0C   ' LAN logical link control (ISO 8802/2)
%BLLI_L2_X75              = &H0D   ' CCITT Rec. X.75, single link procedure
%BLLI_L2_Q922             = &H0E   ' CCITT Rec. Q.922
%BLLI_L2_USER_SPECIFIED   = &H10   ' User Specified
%BLLI_L2_ISO_7776         = &H11   ' ISO 7776 DTE-DTE operation

'
'  values used for Layer3Protocol in B-LLI
'
%BLLI_L3_X25              = &H06   ' CCITT Rec. X.25, packet layer
%BLLI_L3_ISO_8208         = &H07   ' ISO/IEC 8208 (X.25 packet layer for DTE
%BLLI_L3_X223             = &H08   ' X.223/ISO 8878
%BLLI_L3_SIO_8473         = &H09   ' ISO/IEC 8473 (OSI connectionless)
%BLLI_L3_T70              = &H0A   ' CCITT Rec. T.70 min. network layer
%BLLI_L3_ISO_TR9577       = &H0B   ' ISO/IEC TR 9577 Network Layer Protocol ID
%BLLI_L3_USER_SPECIFIED   = &H10   ' User Specified

'
'  values used for Layer3IPI in B-LLI
'
%BLLI_L3_IPI_SNAP         = &H80?  ' IEEE 802.1 SNAP identifier
%BLLI_L3_IPI_IP           = &HCC?  ' Internet Protocol (IP) identifier

TYPE ATM_BLLI DWORD FILL
    Layer2Protocol              AS DWORD  ' User information layer 2 protocol
    Layer2UserSpecifiedProtocol AS DWORD  ' User specified layer 2 protocol information
    Layer3Protocol              AS DWORD  ' User information layer 3 protocol
    Layer3UserSpecifiedProtocol AS DWORD  ' User specified layer 3 protocol information
    Layer3IPI                   AS DWORD  ' ISO/IEC TR 9577 Initial Protocol Identifier
    SnapID                      AS STRING * 5  ' SNAP ID consisting of OUI and PID
END TYPE

'
'  values used for the HighLayerInfoType field in ATM_BHLI
'
%BHLI_ISO                  = &H00   ' ISO
%BHLI_UserSpecific         = &H01   ' User Specific
%BHLI_HighLayerProfile     = &H02   ' High layer profile (only in UNI3.0)
%BHLI_VendorSpecificAppId  = &H03   ' Vendor-Specific Application ID

TYPE ATM_BHLI DWORD FILL
    HighLayerInfoType    AS DWORD       ' High Layer Information Type
    HighLayerInfoLength  AS DWORD       ' number of bytes in HighLayerInfo
    HighLayerInfo        AS STRING * 8  ' the value dependent on the HighLayerInfoType field
END TYPE

TYPE SOCKADDR_ATM DWORD FILL
    satm_family AS WORD            ' address family should be AF_ATM
    satm_number AS ATM_ADDRESS     ' ATM address
    satm_blli   AS ATM_BLLI        ' B-LLI
    satm_bhli   AS ATM_BHLI        ' B-HLI
END TYPE

MACRO Q2931_IE_TYPE_enum=LONG
ENUM Q2931_IE_TYPE SINGULAR
    IE_AALParameters
    IE_TrafficDescriptor
    IE_BroadbandBearerCapability
    IE_BHLI
    IE_BLLI
    IE_CalledPartyNumber
    IE_CalledPartySubaddress
    IE_CallingPartyNumber
    IE_CallingPartySubaddress
    IE_Cause
    IE_QOSClass
    IE_TransitNetworkSelection
END ENUM

TYPE Q2931_IE DWORD FILL
    IEType   AS Q2931_IE_TYPE_enum
    IELength AS DWORD
    IE       AS BYTE
END TYPE

'
'  manifest constants for the AALType field in struct AAL_PARAMETERS_IE
'
MACRO AAL_TYPE_enum=LONG
ENUM AAL_TYPE SINGULAR
    AALTYPE_5     = 5    ' AAL 5
    AALTYPE_USER  = 16   ' user-defined AAL
END ENUM

'
'  values used for the Mode field in struct AAL5_PARAMETERS
'
%AAL5_MODE_MESSAGE           = &H01
%AAL5_MODE_STREAMING         = &H02

'
'  values used for the SSCSType field in struct AAL5_PARAMETERS
'
%AAL5_SSCS_NULL              = &H00
%AAL5_SSCS_SSCOP_ASSURED     = &H01
%AAL5_SSCS_SSCOP_NON_ASSURED = &H02
%AAL5_SSCS_FRAME_RELAY       = &H04

TYPE AAL5_PARAMETERS DWORD FILL
    ForwardMaxCPCSSDUSize  AS DWORD
    BackwardMaxCPCSSDUSize AS DWORD
    Mode                   AS BYTE     ' only available in UNI 3.0
    SSCSType               AS BYTE
END TYPE

TYPE AALUSER_PARAMETERS DWORD FILL
    UserDefined AS DWORD
END TYPE

UNION AALSpecificParameters
    AAL5Parameters    AS AAL5_PARAMETERS
    AALUserParameters AS AALUSER_PARAMETERS
END UNION

TYPE AAL_PARAMETERS_IE DWORD FILL
    AALType AS AAL_TYPE_enum
    AALSpecificParameters
END TYPE

TYPE ATM_TD DWORD FILL
    PeakCellRate_CLP0         AS DWORD
    PeakCellRate_CLP01        AS DWORD
    SustainableCellRate_CLP0  AS DWORD
    SustainableCellRate_CLP01 AS DWORD
    MaxBurstSize_CLP0         AS DWORD
    MaxBurstSize_CLP01        AS DWORD
    Tagging                   AS LONG  ' BOOL
END TYPE

TYPE ATM_TRAFFIC_DESCRIPTOR_IE DWORD FILL
    Forward    AS ATM_TD
    Backward   AS ATM_TD
    BestEffort AS LONG  ' BOOL
END TYPE

'
'  values used for the BearerClass field in struct ATM_BROADBAND_BEARER_CAPABILITY_IE
'
%BCOB_A        = &H01   ' Bearer class A
%BCOB_C        = &H03   ' Bearer class C
%BCOB_X        = &H10   ' Bearer class X

'
'  values used for the TrafficType field in struct ATM_BROADBAND_BEARER_CAPABILITY_IE
'
%TT_NOIND      = &H00   ' No indication of traffic type
%TT_CBR        = &H04   ' Constant bit rate
%TT_VBR        = &H08   ' Variable bit rate

'
'  values used for the TimingRequirements field in struct ATM_BROADBAND_BEARER_CAPABILITY_IE
'
%TR_NOIND         = &H00   ' No timing requirement indication
%TR_END_TO_END    = &H01   ' End-to-end timing required
%TR_NO_END_TO_END = &H02   ' End-to-end timing not required

'
'  values used for the ClippingSusceptability field in struct ATM_BROADBAND_BEARER_CAPABILITY_IE
'
%CLIP_NOT      = &H00   ' Not susceptible to clipping
%CLIP_SUS      = &H20   ' Susceptible to clipping

'
'  values used for the UserPlaneConnectionConfig field in
'  struct ATM_BROADBAND_BEARER_CAPABILITY_IE
'
%UP_P2P        = &H00   ' Point-to-point connection
%UP_P2MP       = &H01   ' Point-to-multipoint connection

TYPE ATM_BROADBAND_BEARER_CAPABILITY_IE DWORD FILL
    BearerClass               AS BYTE
    TrafficType               AS BYTE
    TimingRequirements        AS BYTE
    ClippingSusceptability    AS BYTE
    UserPlaneConnectionConfig AS BYTE
END TYPE

TYPE ATM_BHLI_IE DWORD FILL
    ATM_BHLI
END TYPE

'
'  values used for the Layer2Mode field in struct ATM_BLLI_IE
'
%BLLI_L2_MODE_NORMAL    = &H40
%BLLI_L2_MODE_EXT       = &H80

'
'  values used for the Layer3Mode field in struct ATM_BLLI_IE
'
%BLLI_L3_MODE_NORMAL    = &H40
%BLLI_L3_MODE_EXT       = &H80

'
'  values used for the Layer3DefaultPacketSize field in struct ATM_BLLI_IE
'
%BLLI_L3_PACKET_16      = &H04
%BLLI_L3_PACKET_32      = &H05
%BLLI_L3_PACKET_64      = &H06
%BLLI_L3_PACKET_128     = &H07
%BLLI_L3_PACKET_256     = &H08
%BLLI_L3_PACKET_512     = &H09
%BLLI_L3_PACKET_1024    = &H0A
%BLLI_L3_PACKET_2048    = &H0B
%BLLI_L3_PACKET_4096    = &H0C

TYPE ATM_BLLI_IE DWORD FILL
    Layer2Protocol              AS DWORD       ' User information layer 2 protocol
    Layer2Mode                  AS BYTE
    Layer2WindowSize            AS BYTE
    Layer2UserSpecifiedProtocol AS DWORD       ' User specified layer 2 protocol information
    Layer3Protocol              AS DWORD       ' User information layer 3 protocol
    Layer3Mode                  AS BYTE
    Layer3DefaultPacketSize     AS BYTE
    Layer3PacketWindowSize      AS BYTE
    Layer3UserSpecifiedProtocol AS DWORD       ' User specified layer 3 protocol information
    Layer3IPI                   AS DWORD       ' ISO/IEC TR 9577 Initial Protocol Identifier
    SnapID                      AS STRING * 5  ' SNAP ID consisting of OUI and PID
END TYPE

TYPE ATM_CALLED_PARTY_NUMBER_IE DWORD FILL
    ATM_ADDRESS
END TYPE

TYPE ATM_CALLED_PARTY_SUBADDRESS_IE DWORD FILL
    ATM_ADDRESS
END TYPE

'
'  values used for the Presentation_Indication field in
'  struct ATM_CALLING_PARTY_NUMBER_IE
'
%PI_ALLOWED               = &H00
%PI_RESTRICTED            = &H40
%PI_NUMBER_NOT_AVAILABLE  = &H80

'
'  values used for the Screening_Indicator field in
'  struct ATM_CALLING_PARTY_NUMBER_IE
'
%SI_USER_NOT_SCREENED     = &H00
%SI_USER_PASSED           = &H01
%SI_USER_FAILED           = &H02
%SI_NETWORK               = &H03

TYPE ATM_CALLING_PARTY_NUMBER_IE DWORD FILL
    ATM_Number              AS ATM_ADDRESS
    Presentation_Indication AS BYTE
    Screening_Indicator     AS BYTE
END TYPE

TYPE ATM_CALLING_PARTY_SUBADDRESS_IE DWORD FILL
    ATM_ADDRESS
END TYPE

'
'  values used for the Location field in struct ATM_CAUSE_IE
'
%CAUSE_LOC_USER                   = &H00
%CAUSE_LOC_PRIVATE_LOCAL          = &H01
%CAUSE_LOC_PUBLIC_LOCAL           = &H02
%CAUSE_LOC_TRANSIT_NETWORK        = &H03
%CAUSE_LOC_PUBLIC_REMOTE          = &H04
%CAUSE_LOC_PRIVATE_REMOTE         = &H05
%CAUSE_LOC_INTERNATIONAL_NETWORK  = &H07
%CAUSE_LOC_BEYOND_INTERWORKING    = &H0A

'
'  values used for the Cause field in struct ATM_CAUSE_IE
'
%CAUSE_UNALLOCATED_NUMBER                = &H01
%CAUSE_NO_ROUTE_TO_TRANSIT_NETWORK       = &H02
%CAUSE_NO_ROUTE_TO_DESTINATION           = &H03
%CAUSE_VPI_VCI_UNACCEPTABLE              = &H0A
%CAUSE_NORMAL_CALL_CLEARING              = &H10
%CAUSE_USER_BUSY                         = &H11
%CAUSE_NO_USER_RESPONDING                = &H12
%CAUSE_CALL_REJECTED                     = &H15
%CAUSE_NUMBER_CHANGED                    = &H16
%CAUSE_USER_REJECTS_CLIR                 = &H17
%CAUSE_DESTINATION_OUT_OF_ORDER          = &H1B
%CAUSE_INVALID_NUMBER_FORMAT             = &H1C
%CAUSE_STATUS_ENQUIRY_RESPONSE           = &H1E
%CAUSE_NORMAL_UNSPECIFIED                = &H1F
%CAUSE_VPI_VCI_UNAVAILABLE               = &H23
%CAUSE_NETWORK_OUT_OF_ORDER              = &H26
%CAUSE_TEMPORARY_FAILURE                 = &H29
%CAUSE_ACCESS_INFORMAION_DISCARDED       = &H2B
%CAUSE_NO_VPI_VCI_AVAILABLE              = &H2D
%CAUSE_RESOURCE_UNAVAILABLE              = &H2F
%CAUSE_QOS_UNAVAILABLE                   = &H31
%CAUSE_USER_CELL_RATE_UNAVAILABLE        = &H33
%CAUSE_BEARER_CAPABILITY_UNAUTHORIZED    = &H39
%CAUSE_BEARER_CAPABILITY_UNAVAILABLE     = &H3A
%CAUSE_OPTION_UNAVAILABLE                = &H3F
%CAUSE_BEARER_CAPABILITY_UNIMPLEMENTED   = &H41
%CAUSE_UNSUPPORTED_TRAFFIC_PARAMETERS    = &H49
%CAUSE_INVALID_CALL_REFERENCE            = &H51
%CAUSE_CHANNEL_NONEXISTENT               = &H52
%CAUSE_INCOMPATIBLE_DESTINATION          = &H58
%CAUSE_INVALID_ENDPOINT_REFERENCE        = &H59
%CAUSE_INVALID_TRANSIT_NETWORK_SELECTION = &H5B
%CAUSE_TOO_MANY_PENDING_ADD_PARTY        = &H5C
%CAUSE_AAL_PARAMETERS_UNSUPPORTED        = &H5D
%CAUSE_MANDATORY_IE_MISSING              = &H60
%CAUSE_UNIMPLEMENTED_MESSAGE_TYPE        = &H61
%CAUSE_UNIMPLEMENTED_IE                  = &H63
%CAUSE_INVALID_IE_CONTENTS               = &H64
%CAUSE_INVALID_STATE_FOR_MESSAGE         = &H65
%CAUSE_RECOVERY_ON_TIMEOUT               = &H66
%CAUSE_INCORRECT_MESSAGE_LENGTH          = &H68
%CAUSE_PROTOCOL_ERROR                    = &H6F

'
'  values used for the Condition portion of the Diagnostics field
'  in struct ATM_CAUSE_IE, for certain Cause values
'
%CAUSE_COND_UNKNOWN                  = &H00
%CAUSE_COND_PERMANENT                = &H01
%CAUSE_COND_TRANSIENT                = &H02

'
'  values used for the Rejection Reason portion of the Diagnostics field
'  in struct ATM_CAUSE_IE, for certain Cause values
'
%CAUSE_REASON_USER                   = &H00
%CAUSE_REASON_IE_MISSING             = &H04
%CAUSE_REASON_IE_INSUFFICIENT        = &H08

'
'  values used for the P-U flag of the Diagnostics field
'  in struct ATM_CAUSE_IE, for certain Cause values
'
%CAUSE_PU_PROVIDER                   = &H00
%CAUSE_PU_USER                       = &H08

'
'  values used for the N-A flag of the Diagnostics field
'  in struct ATM_CAUSE_IE, for certain Cause values
'
%CAUSE_NA_NORMAL                     = &H00
%CAUSE_NA_ABNORMAL                   = &H04

TYPE ATM_CAUSE_IE DWORD FILL
    Location          AS BYTE
    Cause             AS BYTE
    DiagnosticsLength AS BYTE
    Diagnostics       AS STRING * 4
END TYPE

'
'  values used for the QOSClassForward and QOSClassBackward
'  field in struct ATM_QOS_CLASS_IE
'
%QOS_CLASS0           = &H00
%QOS_CLASS1           = &H01
%QOS_CLASS2           = &H02
%QOS_CLASS3           = &H03
%QOS_CLASS4           = &H04

TYPE ATM_QOS_CLASS_IE DWORD FILL
    QOSClassForward  AS BYTE
    QOSClassBackward AS BYTE
END TYPE

'
'  values used for the TypeOfNetworkId field in struct ATM_TRANSIT_NETWORK_SELECTION_IE
'
%TNS_TYPE_NATIONAL        = &H40

'
'  values used for the NetworkIdPlan field in struct ATM_TRANSIT_NETWORK_SELECTION_IE
'
%TNS_PLAN_CARRIER_ID_CODE = &H01

TYPE ATM_TRANSIT_NETWORK_SELECTION_IE DWORD FILL
    TypeOfNetworkId AS BYTE
    NetworkIdPlan   AS BYTE
    NetworkIdLength AS BYTE
    NetworkId       AS BYTE
END TYPE

'
'  ATM specific Ioctl codes
'
%SIO_GET_NUMBER_OF_ATM_DEVICES  = &H50160001???
%SIO_GET_ATM_ADDRESS            = &Hd0160002???
%SIO_ASSOCIATE_PVC              = &H90160003???
%SIO_GET_ATM_CONNECTION_ID      = &H50160004???

' ATM Connection Identifier

TYPE ATM_CONNECTION_ID DWORD FILL
    DeviceNumber AS DWORD
    VPI          AS DWORD
    VCI          AS DWORD
END TYPE

'
' Input buffer format for SIO_ASSOCIATE_PVC
'

TYPE ATM_PVC_PARAMS DWORD FILL
    PvcConnectionId AS ATM_CONNECTION_ID
    PvcQos          AS QOS
END TYPE
