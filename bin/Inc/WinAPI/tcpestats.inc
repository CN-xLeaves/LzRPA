'------------------------------------------------------------------------------
'
'  TcpEStats.inc
'    This module contains the definitions and structures for TCP extended
'    statistics.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from TcpEStats.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%TCPESTATS = 1

#INCLUDE "BaseTSD.inc"

'
' Please don't change the order of this enum. The order defined in this
' enum needs to match the order in EstatsToTcpObjectMappingTable.
'
MACRO TCP_ESTATS_TYPE_enum=LONG
ENUM TCP_ESTATS_TYPE SINGULAR
    TcpConnectionEstatsSynOpts
    TcpConnectionEstatsData
    TcpConnectionEstatsSndCong
    TcpConnectionEstatsPath
    TcpConnectionEstatsSendBuff
    TcpConnectionEstatsRec
    TcpConnectionEstatsObsRec
    TcpConnectionEstatsBandwidth
    TcpConnectionEstatsFineRtt
    TcpConnectionEstatsMaximum
END ENUM

'
' TCP_BOOLEAN_OPTIONAL
'
' Define the states that a caller can specify when updating a boolean field.
'

MACRO TCP_BOOLEAN_OPTIONAL_enum=LONG
ENUM TCP_BOOLEAN_OPTIONAL SINGULAR
    TcpBoolOptUnchanged = -1
    TcpBoolOptDisabled
    TcpBoolOptEnabled
END ENUM

'
' TCP_ESTATS_SYN_OPTS_ROS
'
' Define extended SYN-exchange information maintained for TCP connections.
'

TYPE TCP_ESTATS_SYN_OPTS_ROS_v0
    ActiveOpen AS BYTE  ' BYTE  ' BOOLEAN
    MssRcvd    AS DWORD
    MssSent    AS DWORD
END TYPE


'
' TCP_SOFT_ERROR
'
' Enumerate the non-fatal errors recorded on each connection.
'

MACRO TCP_SOFT_ERROR_enum=LONG
ENUM TCP_SOFT_ERROR SINGULAR
    TcpErrorNone
    TcpErrorBelowDataWindow
    TcpErrorAboveDataWindow
    TcpErrorBelowAckWindow
    TcpErrorAboveAckWindow
    TcpErrorBelowTsWindow
    TcpErrorAboveTsWindow
    TcpErrorDataChecksumError
    TcpErrorDataLengthError
    TcpErrorMaxSoftError
END ENUM

'
' TCP_ESTATS_DATA_ROD
'
' Define extended data-transfer information for TCP connections.
'

TYPE TCP_ESTATS_DATA_ROD_v0
    DataBytesOut      AS QUAD  ' ULONG64
    DataSegsOut       AS QUAD  ' ULONG64
    DataBytesIn       AS QUAD  ' ULONG64
    DataSegsIn        AS QUAD  ' ULONG64
    SegsOut           AS QUAD  ' ULONG64
    SegsIn            AS QUAD  ' ULONG64
    SoftErrors        AS DWORD
    SoftErrorReason   AS DWORD
    SndUna            AS DWORD
    SndNxt            AS DWORD
    SndMax            AS DWORD
    ThruBytesAcked    AS QUAD  ' ULONG64
    RcvNxt            AS DWORD
    ThruBytesReceived AS QUAD  ' ULONG64
END TYPE

'
' TCP_ESTATS_DATA_RW
'
' Define structure for enabling extended data-transfer information.
'

TYPE TCP_ESTATS_DATA_RW_v0
    EnableCollection AS BYTE  ' BOOLEAN
END TYPE


'
' TCP_ESTATS_SND_CONG_ROD
'
' Define extended sender-congestion information for TCP connections.
'

TYPE TCP_ESTATS_SND_CONG_ROD_v0
    SndLimTransRwin AS DWORD
    SndLimTimeRwin  AS DWORD
    SndLimBytesRwin AS SIZE_T
    SndLimTransCwnd AS DWORD
    SndLimTimeCwnd  AS DWORD
    SndLimBytesCwnd AS SIZE_T
    SndLimTransSnd  AS DWORD
    SndLimTimeSnd   AS DWORD
    SndLimBytesSnd  AS SIZE_T
    SlowStart       AS DWORD
    CongAvoid       AS DWORD
    OtherReductions AS DWORD
    CurCwnd         AS DWORD
    MaxSsCwnd       AS DWORD
    MaxCaCwnd       AS DWORD
    CurSsthresh     AS DWORD
    MaxSsthresh     AS DWORD
    MinSsthresh     AS DWORD
END TYPE

'
' TCP_ESTATS_SND_CONG_ROS
'
' Define static extended sender-congestion information for TCP connections.

TYPE TCP_ESTATS_SND_CONG_ROS_v0
    LimCwnd AS DWORD
END TYPE

'
' TCP_ESTATS_SND_CONG_RW
'
' Define structure for enabling extended sender-congestion information.
'

TYPE TCP_ESTATS_SND_CONG_RW_v0
    EnableCollection AS BYTE  ' BOOLEAN
END TYPE

'
' TCP_ESTATS_PATH_ROD
'
' Define extended path-measurement information for TCP connections.
'

TYPE TCP_ESTATS_PATH_ROD_v0
    FastRetran            AS DWORD
    Timeouts              AS DWORD
    SubsequentTimeouts    AS DWORD
    CurTimeoutCount       AS DWORD
    AbruptTimeouts        AS DWORD
    PktsRetrans           AS DWORD
    BytesRetrans          AS DWORD
    DupAcksIn             AS DWORD
    SacksRcvd             AS DWORD
    SackBlocksRcvd        AS DWORD
    CongSignals           AS DWORD
    PreCongSumCwnd        AS DWORD
    PreCongSumRtt         AS DWORD
    PostCongSumRtt        AS DWORD
    PostCongCountRtt      AS DWORD
    EcnSignals            AS DWORD
    EceRcvd               AS DWORD
    SendStall             AS DWORD
    QuenchRcvd            AS DWORD
    RetranThresh          AS DWORD
    SndDupAckEpisodes     AS DWORD
    SumBytesReordered     AS DWORD
    NonRecovDa            AS DWORD
    NonRecovDaEpisodes    AS DWORD
    AckAfterFr            AS DWORD
    DsackDups             AS DWORD
    SampleRtt             AS DWORD
    SmoothedRtt           AS DWORD
    RttVar                AS DWORD
    MaxRtt                AS DWORD
    MinRtt                AS DWORD
    SumRtt                AS DWORD
    CountRtt              AS DWORD
    CurRto                AS DWORD
    MaxRto                AS DWORD
    MinRto                AS DWORD
    CurMss                AS DWORD
    MaxMss                AS DWORD
    MinMss                AS DWORD
    SpuriousRtoDetections AS DWORD
END TYPE  ' TCP_ESTATS_PATH_ROD_v0

'
' TCP_ESTATS_PATH_ROS
'
' Define structure for enabling path-measurement information.
'

TYPE TCP_ESTATS_PATH_RW_v0
    EnableCollection AS BYTE  ' BOOLEAN
END TYPE

'
' TCP_ESTATS_SEND_BUFF_ROD
'
' Define extended output-queuing information for TCP connections.
'

TYPE TCP_ESTATS_SEND_BUFF_ROD_v0
    CurRetxQueue AS SIZE_T
    MaxRetxQueue AS SIZE_T
    CurAppWQueue AS SIZE_T
    MaxAppWQueue AS SIZE_T
END TYPE

'
' TCP_ESTATS_SEND_BUFF_RW
'
' Define structure for enabling output-queuing information.
'

TYPE TCP_ESTATS_SEND_BUFF_RW_v0
    EnableCollection AS BYTE  ' BOOLEAN
END TYPE


'
' TCP_ESTATS_REC_ROD
'
' Define extended local-receiver information for TCP connections.
'

TYPE TCP_ESTATS_REC_ROD_v0
    CurRwinSent    AS DWORD
    MaxRwinSent    AS DWORD
    MinRwinSent    AS DWORD
    LimRwin        AS DWORD
    DupAckEpisodes AS DWORD
    DupAcksOut     AS DWORD
    CeRcvd         AS DWORD
    EcnSent        AS DWORD
    EcnNoncesRcvd  AS DWORD
    CurReasmQueue  AS DWORD
    MaxReasmQueue  AS DWORD
    CurAppRQueue   AS SIZE_T
    MaxAppRQueue   AS SIZE_T
    WinScaleSent   AS BYTE
END TYPE

'
' TCP_ESTATS_REC_RW
'
' Define structure for enabling local-receiver information.
'

TYPE TCP_ESTATS_REC_RW_v0
    EnableCollection AS BYTE  ' BOOLEAN
END TYPE


'
' TCP_ESTATS_OBS_REC_ROD
'
' Define extended remote-receiver information for TCP connections.
'

TYPE TCP_ESTATS_OBS_REC_ROD_v0
    CurRwinRcvd  AS DWORD
    MaxRwinRcvd  AS DWORD
    MinRwinRcvd  AS DWORD
    WinScaleRcvd AS BYTE
END TYPE


'
' TCP_ESTATS_OBS_REC_RW
'
' Define structure for enabling remote-receiver information.
'

TYPE TCP_ESTATS_OBS_REC_RW_v0
    EnableCollection AS BYTE  ' BOOLEAN
END TYPE


'
' TCP_ESTATS_BW_RW
'
' Define the structure for enabling bandwidth estimation for TCP connections.
'

TYPE TCP_ESTATS_BANDWIDTH_RW_v0
    EnableCollectionOutbound AS TCP_BOOLEAN_OPTIONAL_enum
    EnableCollectionInbound  AS TCP_BOOLEAN_OPTIONAL_enum
END TYPE

'
' TCP_ESTATS_BW_ROD
'
' Define bandwidth estimation statistics for TCP connections.
'
' Bandwidth and Instability metrics are expressed as bits per second.
'

TYPE TCP_ESTATS_BANDWIDTH_ROD_v0
    OutboundBandwidth       AS QUAD  ' ULONG64
    InboundBandwidth        AS QUAD  ' ULONG64
    OutboundInstability     AS QUAD  ' ULONG64
    InboundInstability      AS QUAD  ' ULONG64
    OutboundBandwidthPeaked AS BYTE  ' BOOLEAN
    InboundBandwidthPeaked  AS BYTE  ' BOOLEAN
END TYPE

'
' TCP_ESTATS_FINE_RTT_RW
'
' Define the structure for enabling fine-grained RTT estimation for TCP
' connections.
'

TYPE TCP_ESTATS_FINE_RTT_RW_v0
    EnableCollection AS BYTE  ' BOOLEAN
END TYPE


'
' TCP_ESTATS_FINE_RTT_ROD
'
' Define fine-grained RTT estimation statistics for TCP connections.
'

TYPE TCP_ESTATS_FINE_RTT_ROD_v0
    RttVar AS DWORD
    MaxRtt AS DWORD
    MinRtt AS DWORD
    SumRtt AS DWORD
END TYPE
