'------------------------------------------------------------------------------
'
'  IpMib.inc
'    This module contains the public definitions and structures for the
'    IP-specific parts of MIB-II.  These definitions were previously
'    in iprtrmib.h, which now #includes this file.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from IpMib.h build version 0001 of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%IPMIB = 1

#INCLUDE "SdkDdkVer.inc"

#IF NOT %DEF(%ANY_SIZE)
%ANY_SIZE = 1
#ENDIF

'
' Pick up definitions of MAXLEN_PHYSADDR, etc.
'
#INCLUDE "ifmib.inc"

#INCLUDE "nldef.inc"

%MIB_IPADDR_PRIMARY      = &H0001 ' Primary ipaddr
%MIB_IPADDR_DYNAMIC      = &H0004 ' Dynamic ipaddr
%MIB_IPADDR_DISCONNECTED = &H0008 ' Address is on disconnected interface
%MIB_IPADDR_DELETED      = &H0040 ' Address being deleted
%MIB_IPADDR_TRANSIENT    = &H0080 ' Transient address
%MIB_IPADDR_DNS_ELIGIBLE = &H0100 ' Address is published in DNS.

TYPE MIB_IPADDRROW_XP
    dwAddr AS DWORD
    dwIndex AS IF_INDEX
    dwMask AS DWORD
    dwBCastAddr AS DWORD
    dwReasmSize AS DWORD
    unused1 AS WORD
    wType AS WORD
END TYPE

TYPE MIB_IPADDRROW_W2K
    dwAddr      AS DWORD
    dwIndex     AS DWORD
    dwMask      AS DWORD
    dwBCastAddr AS DWORD
    dwReasmSize AS DWORD
    unused1     AS WORD
    unused2     AS WORD
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
TYPE MIB_IPADDRROW
    MIB_IPADDRROW_XP
END TYPE
#ELSEIF (%NTDDI_VERSION >= %NTDDI_WIN2K)
TYPE MIB_IPADDRROW
    MIB_IPADDRROW_W2K
END TYPE
#ELSE
TYPE MIB_IPADDRROW
    MIB_IPADDRROW_XP
END TYPE
#ENDIF

TYPE MIB_IPADDRTABLE
    dwNumEntries AS DWORD
    table(%ANY_SIZE-1) AS MIB_IPADDRROW
END TYPE


'#define SIZEOF_IPADDRTABLE(X) (FIELD_OFFSET(MIB_IPADDRTABLE,table[0]) + \
'                               ((X) * sizeof(MIB_IPADDRROW)) + ALIGN_SIZE)

TYPE MIB_IPFORWARDNUMBER
    dwValue AS DWORD
END TYPE

MACRO MIB_IPFORWARD_PROTO=NL_ROUTE_PROTOCOL_enum

MACRO MIB_IPFORWARD_TYPE_enum=LONG
ENUM MIB_IPFORWARD_TYPE SINGULAR
    MIB_IPROUTE_TYPE_OTHER    = 1
    MIB_IPROUTE_TYPE_INVALID
    MIB_IPROUTE_TYPE_DIRECT
    MIB_IPROUTE_TYPE_INDIRECT
END ENUM

UNION MIB_IPFORWARDROW_union1
    dwForwardType AS DWORD                   ' Old field name uses DWORD type.
    ForwardType   AS MIB_IPFORWARD_TYPE_enum ' New field name uses enum type.
END UNION

UNION MIB_IPFORWARDROW_union2
    dwForwardProto AS DWORD                  ' Old field name uses DWORD type.
    ForwardProto   AS MIB_IPFORWARD_PROTO    ' New field name uses enum type.
END UNION

TYPE MIB_IPFORWARDROW
    dwForwardDest      AS DWORD
    dwForwardMask      AS DWORD
    dwForwardPolicy    AS DWORD
    dwForwardNextHop   AS DWORD
    dwForwardIfIndex   AS IF_INDEX
    MIB_IPFORWARDROW_union1
    MIB_IPFORWARDROW_union2
    dwForwardAge       AS DWORD
    dwForwardNextHopAS AS DWORD
    dwForwardMetric1   AS DWORD
    dwForwardMetric2   AS DWORD
    dwForwardMetric3   AS DWORD
    dwForwardMetric4   AS DWORD
    dwForwardMetric5   AS DWORD
END TYPE

%MIB_IPROUTE_TYPE_OTHER    = 1
%MIB_IPROUTE_TYPE_INVALID  = 2
%MIB_IPROUTE_TYPE_DIRECT   = 3
%MIB_IPROUTE_TYPE_INDIRECT = 4

%MIB_IPROUTE_METRIC_UNUSED = &HFFFFFFFF??? '   (DWORD)-1


TYPE MIB_IPFORWARDTABLE
    dwNumEntries AS DWORD
    table(%ANY_SIZE-1) AS MIB_IPFORWARDROW
END TYPE

'#define SIZEOF_IPFORWARDTABLE(X) \
'            (FIELD_OFFSET(MIB_IPFORWARDTABLE,table[0]) + \
'             ((X) * sizeof(MIB_IPFORWARDROW)) + ALIGN_SIZE)

MACRO MIB_IPNET_TYPE_enum=LONG
ENUM MIB_IPNET_TYPE SINGULAR
    MIB_IPNET_TYPE_OTHER   = 1
    MIB_IPNET_TYPE_INVALID
    MIB_IPNET_TYPE_DYNAMIC
    MIB_IPNET_TYPE_STATIC
END ENUM

UNION MIB_IPNETROW_LH_union
    dwType AS DWORD                ' Old field name was just a DWORD.
    nType  AS MIB_IPNET_TYPE_enum  ' New field name uses the enum type.
END UNION

TYPE MIB_IPNETROW_LH
    dwIndex                       AS IF_INDEX
    dwPhysAddrLen                 AS DWORD
    bPhysAddr(%MAXLEN_PHYSADDR-1) AS BYTE
    dwAddr                        AS DWORD
    MIB_IPNETROW_LH_union
END TYPE

TYPE MIB_IPNETROW_W2K
    dwIndex                       AS IF_INDEX
    dwPhysAddrLen                 AS DWORD
    bPhysAddr(%MAXLEN_PHYSADDR-1) AS BYTE
    dwAddr                        AS DWORD
    dwType                        AS DWORD
END TYPE


#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
TYPE MIB_IPNETROW
    MIB_IPNETROW_LH
END TYPE
#ELSEIF (%NTDDI_VERSION >= %NTDDI_WIN2K)
TYPE MIB_IPNETROW
    MIB_IPNETROW_W2K
END TYPE
#ELSE
TYPE MIB_IPNETROW
    MIB_IPNETROW_LH
END TYPE
#ENDIF

TYPE MIB_IPNETTABLE
    dwNumEntries       AS DWORD
    table(%ANY_SIZE-1) AS MIB_IPNETROW
END TYPE

'#define SIZEOF_IPNETTABLE(X) (FIELD_OFFSET(MIB_IPNETTABLE, table[0]) + \
'                              ((X) * sizeof(MIB_IPNETROW)) + ALIGN_SIZE)

MACRO MIB_IPSTATS_FORWARDING_enum=LONG
ENUM MIB_IPSTATS_FORWARDING SINGULAR
    MIB_IP_FORWARDING     = 1
    MIB_IP_NOT_FORWARDING
END ENUM

%MIB_USE_CURRENT_TTL        = &HFFFFFFFF???  ' ((DWORD)-1)
%MIB_USE_CURRENT_FORWARDING = &HFFFFFFFF???  ' ((DWORD)-1)

UNION MIB_IPSTATS_LH_union
    dwForwarding AS DWORD
    Forwarding   AS MIB_IPSTATS_FORWARDING_enum
END UNION

TYPE MIB_IPSTATS_LH
    MIB_IPSTATS_LH_union
    dwDefaultTTL      AS DWORD
    dwInReceives      AS DWORD
    dwInHdrErrors     AS DWORD
    dwInAddrErrors    AS DWORD
    dwForwDatagrams   AS DWORD
    dwInUnknownProtos AS DWORD
    dwInDiscards      AS DWORD
    dwInDelivers      AS DWORD
    dwOutRequests     AS DWORD
    dwRoutingDiscards AS DWORD
    dwOutDiscards     AS DWORD
    dwOutNoRoutes     AS DWORD
    dwReasmTimeout    AS DWORD
    dwReasmReqds      AS DWORD
    dwReasmOks        AS DWORD
    dwReasmFails      AS DWORD
    dwFragOks         AS DWORD
    dwFragFails       AS DWORD
    dwFragCreates     AS DWORD
    dwNumIf           AS DWORD
    dwNumAddr         AS DWORD
    dwNumRoutes       AS DWORD
END TYPE

TYPE MIB_IPSTATS_W2K
    dwForwarding      AS DWORD
    dwDefaultTTL      AS DWORD
    dwInReceives      AS DWORD
    dwInHdrErrors     AS DWORD
    dwInAddrErrors    AS DWORD
    dwForwDatagrams   AS DWORD
    dwInUnknownProtos AS DWORD
    dwInDiscards      AS DWORD
    dwInDelivers      AS DWORD
    dwOutRequests     AS DWORD
    dwRoutingDiscards AS DWORD
    dwOutDiscards     AS DWORD
    dwOutNoRoutes     AS DWORD
    dwReasmTimeout    AS DWORD
    dwReasmReqds      AS DWORD
    dwReasmOks        AS DWORD
    dwReasmFails      AS DWORD
    dwFragOks         AS DWORD
    dwFragFails       AS DWORD
    dwFragCreates     AS DWORD
    dwNumIf           AS DWORD
    dwNumAddr         AS DWORD
    dwNumRoutes       AS DWORD
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
TYPE MIB_IPSTATS
    MIB_IPSTATS_LH
END TYPE
#ELSEIF (%NTDDI_VERSION >= %NTDDI_WIN2K)
TYPE MIB_IPSTATS
    MIB_IPSTATS_W2K
END TYPE
#ENDIF

TYPE MIBICMPSTATS
    dwMsgs          AS DWORD
    dwErrors        AS DWORD
    dwDestUnreachs  AS DWORD
    dwTimeExcds     AS DWORD
    dwParmProbs     AS DWORD
    dwSrcQuenchs    AS DWORD
    dwRedirects     AS DWORD
    dwEchos         AS DWORD
    dwEchoReps      AS DWORD
    dwTimestamps    AS DWORD
    dwTimestampReps AS DWORD
    dwAddrMasks     AS DWORD
    dwAddrMaskReps  AS DWORD
END TYPE

TYPE MIBICMPINFO
    icmpInStats  AS MIBICMPSTATS
    icmpOutStats AS MIBICMPSTATS
END TYPE

TYPE MIB_ICMP
    stats AS MIBICMPINFO
END TYPE

TYPE MIBICMPSTATS_EX_XPSP1
    dwMsgs             AS DWORD
    dwErrors           AS DWORD
    rgdwTypeCount(255) AS DWORD
END TYPE

' [another Microsoft bug]
'#IF (%NTDDI_VERSION >= %NTDDI_XPSP1)
#IF (%NTDDI_VERSION >= %NTDDI_WINXPSP1)
TYPE MIBICMPSTATS_EX
    MIBICMPSTATS_EX_XPSP1
END TYPE
#ENDIF

TYPE MIB_ICMP_EX_XPSP1
    icmpInStats  AS MIBICMPSTATS_EX
    icmpOutStats AS MIBICMPSTATS_EX
END TYPE

' [another Microsoft bug]
'#IF (%NTDDI_VERSION >= %NTDDI_XPSP1)
#IF (%NTDDI_VERSION >= %NTDDI_WINXPSP1)
TYPE MIB_ICMP_EX
    MIB_ICMP_EX_XPSP1
END TYPE
#ELSE
'
' Still need these in case application does not set
' %NTDDI_VERSION to one of the above.
'
TYPE MIB_ICMP_EX
    MIB_ICMP_EX_XPSP1
END TYPE
#ENDIF

'
' ICMP6_TYPE
'
' ICMPv6 Type Values from RFC 2292, 2461 (ND), and 3810 (MLDv2)
'
MACRO ICMP6_TYPE_enum=LONG
ENUM ICMP6_TYPE SINGULAR
    ICMP6_DST_UNREACH          = 1
    ICMP6_PACKET_TOO_BIG
    ICMP6_TIME_EXCEEDED
    ICMP6_PARAM_PROB
    ICMP6_ECHO_REQUEST         = 128
    ICMP6_ECHO_REPLY
    ICMP6_MEMBERSHIP_QUERY
    ICMP6_MEMBERSHIP_REPORT
    ICMP6_MEMBERSHIP_REDUCTION
    ND_ROUTER_SOLICIT
    ND_ROUTER_ADVERT
    ND_NEIGHBOR_SOLICIT
    ND_NEIGHBOR_ADVERT
    ND_REDIRECT
    ICMP6_V2_MEMBERSHIP_REPORT = 143
END ENUM


'
' Used to identify informational/error messages.
'
%ICMP6_INFOMSG_MASK = &H0080
MACRO ICMP6_ISTYPEINFORMATIONAL(nType)=(-ISTRUE ((nType) AND %ICMP6_INFOMSG_MASK))
MACRO ICMP6_ISTYPEERROR(nType)=(-ISFALSE ICMP6_ISTYPEINFORMATIONAL(nType))

'
' ICMP4_TYPE
'
' There are no RFC-specified defines for ICMPv4 message types, so we try to
' use the ICMP6 values from RFC 2292 modified to be prefixed with ICMP4.
'
MACRO ICMP4_TYPE_enum=LONG
ENUM ICMP4_TYPE SINGULAR
    ICMP4_ECHO_REPLY        =  0  ' Echo Reply.
    ICMP4_DST_UNREACH       =  3  ' Destination Unreachable.
    ICMP4_SOURCE_QUENCH           ' Source Quench.
    ICMP4_REDIRECT                ' Redirect.
    ICMP4_ECHO_REQUEST      =  8  ' Echo Request.
    ICMP4_ROUTER_ADVERT           ' Router Advertisement.
    ICMP4_ROUTER_SOLICIT          ' Router Solicitation.
    ICMP4_TIME_EXCEEDED           ' Time Exceeded.
    ICMP4_PARAM_PROB              ' Parameter Problem.
    ICMP4_TIMESTAMP_REQUEST       ' Timestamp Request.
    ICMP4_TIMESTAMP_REPLY         ' Timestamp Reply.
    ICMP4_MASK_REQUEST      = 17  ' Address Mask Request.
    ICMP4_MASK_REPLY              ' Address Mask Reply.
END ENUM

'
' See RFC 1812, section 4.3.1.
'
MACRO ICMP4_ISTYPEERROR(nType)=ABS((nType)=%ICMP4_DST_UNREACH OR (nType)=%ICMP4_SOURCE_QUENCH OR (nType)=%ICMP4_REDIRECT OR (nType)=%ICMP4_PARAM_PROB OR (nType)=%ICMP4_TIME_EXCEEDED)

TYPE MIB_IPMCAST_OIF_XP
    dwOutIfIndex  AS DWORD
    dwNextHopAddr AS DWORD
    dwReserved    AS DWORD
    dwReserved1   AS DWORD
END TYPE

TYPE MIB_IPMCAST_OIF_W2K
    dwOutIfIndex  AS DWORD
    dwNextHopAddr AS DWORD
    pvReserved    AS DWORD  ' PVOID
    dwReserved    AS DWORD
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
TYPE MIB_IPMCAST_OIF
    MIB_IPMCAST_OIF_XP
END TYPE
#ELSEIF (%NTDDI_VERSION >= %NTDDI_WIN2K)
TYPE MIB_IPMCAST_OIF
    MIB_IPMCAST_OIF_W2K
END TYPE
#ELSE
TYPE MIB_IPMCAST_OIF
    MIB_IPMCAST_OIF_XP
END TYPE
#ENDIF

TYPE MIB_IPMCAST_MFE
    dwGroup         AS DWORD
    dwSource        AS DWORD
    dwSrcMask       AS DWORD
    dwUpStrmNgbr    AS DWORD
    dwInIfIndex     AS DWORD
    dwInIfProtocol  AS DWORD
    dwRouteProtocol AS DWORD
    dwRouteNetwork  AS DWORD
    dwRouteMask     AS DWORD
    ulUpTime        AS DWORD
    ulExpiryTime    AS DWORD
    ulTimeOut       AS DWORD
    ulNumOutIf      AS DWORD
    fFlags          AS DWORD
    dwReserved      AS DWORD
    rgmioOutInfo(%ANY_SIZE-1) AS MIB_IPMCAST_OIF
END TYPE

TYPE MIB_MFE_TABLE
    dwNumEntries    AS DWORD
    table(%ANY_SIZE-1) AS MIB_IPMCAST_MFE
END TYPE


'#define SIZEOF_BASIC_MIB_MFE          \
'    (DWORD)(FIELD_OFFSET(MIB_IPMCAST_MFE, rgmioOutInfo[0]))

'#define SIZEOF_MIB_MFE(X)             \
'    (SIZEOF_BASIC_MIB_MFE + ((X) * sizeof(MIB_IPMCAST_OIF)))


TYPE MIB_IPMCAST_OIF_STATS_LH
    dwOutIfIndex  AS DWORD
    dwNextHopAddr AS DWORD
    dwDialContext AS DWORD
    ulTtlTooLow   AS DWORD
    ulFragNeeded  AS DWORD
    ulOutPackets  AS DWORD
    ulOutDiscards AS DWORD
END TYPE

TYPE MIB_IPMCAST_OIF_STATS_W2K
    dwOutIfIndex  AS DWORD
    dwNextHopAddr AS DWORD
    pvDialContext AS DWORD  ' PVOID
    ulTtlTooLow   AS DWORD
    ulFragNeeded  AS DWORD
    ulOutPackets  AS DWORD
    ulOutDiscards AS DWORD
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
TYPE MIB_IPMCAST_OIF_STATS
    MIB_IPMCAST_OIF_STATS_LH
END TYPE
#ELSEIF (%NTDDI_VERSION >= %NTDDI_WIN2K)
TYPE MIB_IPMCAST_OIF_STATS
    MIB_IPMCAST_OIF_STATS_W2K
END TYPE
#ELSE
TYPE MIB_IPMCAST_OIF_STATS
    MIB_IPMCAST_OIF_STATS_LH
END TYPE
#ENDIF

TYPE MIB_IPMCAST_MFE_STATS
    dwGroup           AS DWORD
    dwSource          AS DWORD
    dwSrcMask         AS DWORD
    dwUpStrmNgbr      AS DWORD
    dwInIfIndex       AS DWORD
    dwInIfProtocol    AS DWORD
    dwRouteProtocol   AS DWORD
    dwRouteNetwork    AS DWORD
    dwRouteMask       AS DWORD
    ulUpTime          AS DWORD
    ulExpiryTime      AS DWORD
    ulNumOutIf        AS DWORD
    ulInPkts          AS DWORD
    ulInOctets        AS DWORD
    ulPktsDifferentIf AS DWORD
    ulQueueOverflow   AS DWORD

    rgmiosOutStats(%ANY_SIZE-1) AS MIB_IPMCAST_OIF_STATS
END TYPE

TYPE MIB_MFE_STATS_TABLE
    dwNumEntries       AS DWORD
    table(%ANY_SIZE-1) AS MIB_IPMCAST_MFE_STATS
END TYPE

'#define SIZEOF_BASIC_MIB_MFE_STATS    \
'    (DWORD)(FIELD_OFFSET(MIB_IPMCAST_MFE_STATS, rgmiosOutStats[0]))

'#define SIZEOF_MIB_MFE_STATS(X)       \
'    (SIZEOF_BASIC_MIB_MFE_STATS + ((X) * sizeof(MIB_IPMCAST_OIF_STATS)))


TYPE MIB_IPMCAST_MFE_STATS_EX_XP
    dwGroup           AS DWORD
    dwSource          AS DWORD
    dwSrcMask         AS DWORD
    dwUpStrmNgbr      AS DWORD
    dwInIfIndex       AS DWORD
    dwInIfProtocol    AS DWORD
    dwRouteProtocol   AS DWORD
    dwRouteNetwork    AS DWORD
    dwRouteMask       AS DWORD
    ulUpTime          AS DWORD
    ulExpiryTime      AS DWORD
    ulNumOutIf        AS DWORD
    ulInPkts          AS DWORD
    ulInOctets        AS DWORD
    ulPktsDifferentIf AS DWORD
    ulQueueOverflow   AS DWORD
    ulUninitMfe       AS DWORD
    ulNegativeMfe     AS DWORD
    ulInDiscards      AS DWORD
    ulInHdrErrors     AS DWORD
    ulTotalOutPackets AS DWORD

    rgmiosOutStats(%ANY_SIZE-1) AS MIB_IPMCAST_OIF_STATS
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
TYPE MIB_IPMCAST_MFE_STATS_EX
    MIB_IPMCAST_MFE_STATS_EX_XP
END TYPE
#ENDIF

TYPE MIB_MFE_STATS_TABLE_EX_XP
    dwNumEntries       AS DWORD
    table(%ANY_SIZE-1) AS MIB_IPMCAST_MFE_STATS_EX_XP PTR
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
TYPE MIB_MFE_STATS_TABLE_EX
    MIB_MFE_STATS_TABLE_EX_XP
END TYPE

'#define SIZEOF_BASIC_MIB_MFE_STATS_EX    \
'    (DWORD)(FIELD_OFFSET(MIB_IPMCAST_MFE_STATS_EX, rgmiosOutStats[0]))

'#define SIZEOF_MIB_MFE_STATS_EX(X)       \
'    (SIZEOF_BASIC_MIB_MFE_STATS_EX + ((X) * sizeof(MIB_IPMCAST_OIF_STATS)))
#ENDIF

TYPE MIB_IPMCAST_GLOBAL
    dwEnable AS DWORD
END TYPE

TYPE MIB_IPMCAST_IF_ENTRY
    dwIfIndex        AS DWORD
    dwTtl            AS DWORD
    dwProtocol       AS DWORD
    dwRateLimit      AS DWORD
    ulInMcastOctets  AS DWORD
    ulOutMcastOctets AS DWORD
END TYPE

TYPE MIB_IPMCAST_IF_TABLE
    dwNumEntries       AS DWORD
    table(%ANY_SIZE-1) AS MIB_IPMCAST_IF_ENTRY
END TYPE


'#define SIZEOF_MCAST_IF_TABLE(X) \
'    (FIELD_OFFSET(MIB_IPMCAST_IF_TABLE, table[0]) +  \
'     ((X) * sizeof(MIB_IPMCAST_IF_ENTRY)) +  \
'     ALIGN_SIZE)
