'------------------------------------------------------------------------------
'
'  IpExport.inc -- Microsoft LAN Manager
'     This file contains public definitions exported to transport layer and
'     application software.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from IpExport.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%IP_EXPORT_INCLUDED = 1

#INCLUDE "SdkDdkVer.inc"

'
' IP type definitions.
'
'MACRO IPAddr=DWORD       ' An IP address.
'MACRO IPMask=DWORD       ' An IP subnet mask.
'MACRO IP_STATUS=DWORD    ' Status code returned from IP APIs.

#INCLUDE "in6addr.inc"

TYPE IPv6Addr
    in6_addr
END TYPE

#INCLUDE "inaddr.inc"

' INC

'
' The ip_option_information structure describes the options to be
' included in the header of an IP packet. The TTL, TOS, and Flags
' values are carried in specific fields in the header. The OptionsData
' bytes are carried in the options area following the standard IP header.
' With the exception of source route options, this data must be in the
' format to be transmitted on the wire as specified in RFC 791. A source
' route option should contain the full route - first hop thru final
' destination - in the route data. The first hop will be pulled out of the
' data and the option will be reformatted accordingly. Otherwise, the route
' option should be formatted as specified in RFC 791.
'

TYPE IP_OPTION_INFORMATION
    Ttl         AS BYTE        ' Time To Live
    Tos         AS BYTE        ' Type of Service
    Flags       AS BYTE        ' IP header flags
    OptionsSize AS BYTE        ' Size in bytes of options data
    OptionsData AS BYTE PTR    ' Pointer to options data
END TYPE

#IF %DEF(%WIN64)

TYPE IP_OPTION_INFORMATION32
    Ttl         AS BYTE        ' Time To Live
    Tos         AS BYTE        ' Type of Service
    Flags       AS BYTE        ' IP header flags
    OptionsSize AS BYTE        ' Size in bytes of options data
    OptionsData AS BYTE PTR    ' Pointer to options data
END TYPE

#ENDIF ' %WIN64

'
' The icmp_echo_reply structure describes the data returned in response
' to an echo request.
'

TYPE ICMP_ECHO_REPLY
    Address       AS DWORD                 ' IPAddr: Replying address
    STATUS        AS DWORD                 ' Reply IP_STATUS
    RoundTripTime AS DWORD                 ' RTT in milliseconds
    DataSize      AS WORD                  ' Reply data size in bytes
    Reserved      AS WORD                  ' Reserved for system use
    pData         AS DWORD                 ' Pointer to the reply data
    Options       AS IP_OPTION_INFORMATION ' Reply options
END TYPE

#IF %DEF(%WIN64)

TYPE ICMP_ECHO_REPLY32
    Address       AS DWORD                 ' IPAddr: Replying address
    STATUS        AS DWORD                 ' Reply IP_STATUS
    RoundTripTime AS DWORD                 ' RTT in milliseconds
    DataSize      AS WORD                  ' Reply data size in bytes
    Reserved      AS WORD                  ' Reserved for system use
    pData         AS DWORD                 ' Pointer to the reply data
    Options       AS IP_OPTION_INFORMATION ' Reply options
END TYPE

#ENDIF ' %WIN64

' [Microsoft bug]
'#if (%NTDDI_VERSION >= %NTDDI_XP)
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)

TYPE IPV6_ADDRESS_EX
    sin6_port     AS WORD
    sin6_flowinfo AS DWORD
    sin6_addr(7)  AS WORD
    sin6_scope_id AS DWORD
END TYPE

TYPE ICMPV6_ECHO_REPLY_LH
    Address       AS IPV6_ADDRESS_EX  ' Replying address.
    STATUS        AS DWORD            ' Reply IP_STATUS.
    RoundTripTime AS DWORD            ' RTT in milliseconds.
    ' Reply data follows this structure in memory.
END TYPE

TYPE ICMPV6_ECHO_REPLY
    ICMPV6_ECHO_REPLY_LH
END TYPE

#ENDIF ' #if (%NTDDI_VERSION >= %NTDDI_[WIN]XP)

TYPE ARP_SEND_REPLY
    DestAddress AS DWORD  ' IPAddr
    SrcAddress  AS DWORD  ' IPAddr
END TYPE

TYPE TCP_RESERVE_PORT_RANGE
    UpperRange AS WORD
    LowerRange AS WORD
END TYPE

%MAX_ADAPTER_NAME = 128

TYPE IP_ADAPTER_INDEX_MAP
    Index AS DWORD
    sName AS WSTRINGZ * %MAX_ADAPTER_NAME
END TYPE

TYPE IP_INTERFACE_INFO
    NumAdapters AS LONG
    Adapter(0)  AS IP_ADAPTER_INDEX_MAP
END TYPE

TYPE IP_UNIDIRECTIONAL_ADAPTER_ADDRESS
    NumAdapters AS DWORD
    Address(0)  AS DWORD ' IPAddr
END TYPE

TYPE IP_ADAPTER_ORDER_MAP
    NumAdapters     AS DWORD
    AdapterOrder(0) AS DWORD
END TYPE

TYPE IP_MCAST_COUNTER_INFO
    InMcastOctets  AS QUAD
    OutMcastOctets AS QUAD
    InMcastPkts    AS QUAD
    OutMcastPkts   AS QUAD
END TYPE

'
' IP_STATUS codes returned from IP APIs
'

%IP_STATUS_BASE              = 11000

%IP_SUCCESS                  = 0
%IP_BUF_TOO_SMALL            = (%IP_STATUS_BASE + 1)
%IP_DEST_NET_UNREACHABLE     = (%IP_STATUS_BASE + 2)
%IP_DEST_HOST_UNREACHABLE    = (%IP_STATUS_BASE + 3)
%IP_DEST_PROT_UNREACHABLE    = (%IP_STATUS_BASE + 4)
%IP_DEST_PORT_UNREACHABLE    = (%IP_STATUS_BASE + 5)
%IP_NO_RESOURCES             = (%IP_STATUS_BASE + 6)
%IP_BAD_OPTION               = (%IP_STATUS_BASE + 7)
%IP_HW_ERROR                 = (%IP_STATUS_BASE + 8)
%IP_PACKET_TOO_BIG           = (%IP_STATUS_BASE + 9)
%IP_REQ_TIMED_OUT            = (%IP_STATUS_BASE + 10)
%IP_BAD_REQ                  = (%IP_STATUS_BASE + 11)
%IP_BAD_ROUTE                = (%IP_STATUS_BASE + 12)
%IP_TTL_EXPIRED_TRANSIT      = (%IP_STATUS_BASE + 13)
%IP_TTL_EXPIRED_REASSEM      = (%IP_STATUS_BASE + 14)
%IP_PARAM_PROBLEM            = (%IP_STATUS_BASE + 15)
%IP_SOURCE_QUENCH            = (%IP_STATUS_BASE + 16)
%IP_OPTION_TOO_BIG           = (%IP_STATUS_BASE + 17)
%IP_BAD_DESTINATION          = (%IP_STATUS_BASE + 18)

'
' Variants of the above using IPv6 terminology, where different
'

%IP_DEST_NO_ROUTE            = (%IP_STATUS_BASE + 2)
%IP_DEST_ADDR_UNREACHABLE    = (%IP_STATUS_BASE + 3)
%IP_DEST_PROHIBITED          = (%IP_STATUS_BASE + 4)
%IP_DEST_PORT_UNREACHABLE    = (%IP_STATUS_BASE + 5)
%IP_HOP_LIMIT_EXCEEDED       = (%IP_STATUS_BASE + 13)
%IP_REASSEMBLY_TIME_EXCEEDED = (%IP_STATUS_BASE + 14)
%IP_PARAMETER_PROBLEM        = (%IP_STATUS_BASE + 15)

'
' IPv6-only status codes
'

%IP_DEST_UNREACHABLE         = (%IP_STATUS_BASE + 40)
%IP_TIME_EXCEEDED            = (%IP_STATUS_BASE + 41)
%IP_BAD_HEADER               = (%IP_STATUS_BASE + 42)
%IP_UNRECOGNIZED_NEXT_HEADER = (%IP_STATUS_BASE + 43)
%IP_ICMP_ERROR               = (%IP_STATUS_BASE + 44)
%IP_DEST_SCOPE_MISMATCH      = (%IP_STATUS_BASE + 45)

'
' The next group are status codes passed up on status indications to
' transport layer protocols.
'
%IP_ADDR_DELETED             = (%IP_STATUS_BASE + 19)
%IP_SPEC_MTU_CHANGE          = (%IP_STATUS_BASE + 20)
%IP_MTU_CHANGE               = (%IP_STATUS_BASE + 21)
%IP_UNLOAD                   = (%IP_STATUS_BASE + 22)
%IP_ADDR_ADDED               = (%IP_STATUS_BASE + 23)
%IP_MEDIA_CONNECT            = (%IP_STATUS_BASE + 24)
%IP_MEDIA_DISCONNECT         = (%IP_STATUS_BASE + 25)
%IP_BIND_ADAPTER             = (%IP_STATUS_BASE + 26)
%IP_UNBIND_ADAPTER           = (%IP_STATUS_BASE + 27)
%IP_DEVICE_DOES_NOT_EXIST    = (%IP_STATUS_BASE + 28)
%IP_DUPLICATE_ADDRESS        = (%IP_STATUS_BASE + 29)
%IP_INTERFACE_METRIC_CHANGE  = (%IP_STATUS_BASE + 30)
%IP_RECONFIG_SECFLTR         = (%IP_STATUS_BASE + 31)
%IP_NEGOTIATING_IPSEC        = (%IP_STATUS_BASE + 32)
%IP_INTERFACE_WOL_CAPABILITY_CHANGE  = (%IP_STATUS_BASE + 33)
%IP_DUPLICATE_IPADD          = (%IP_STATUS_BASE + 34)

%IP_GENERAL_FAILURE          = (%IP_STATUS_BASE + 50)
%MAX_IP_STATUS               = %IP_GENERAL_FAILURE
%IP_PENDING                  = (%IP_STATUS_BASE + 255)


'
' Values used in the Flags field of IP_OPTION_INFORMATION.
'
%IP_FLAG_REVERSE = &H1         ' Do a round-trip echo request.
%IP_FLAG_DF      = &H2         ' Don't fragment this packet.

'
' Supported IP Option Types.
'
' These types define the options which may be used in the OptionsData field
' of the ip_option_information structure.  See RFC 791 for a complete
' description of each.
'
%IP_OPT_EOL      = 0          ' End of list option
%IP_OPT_NOP      = 1          ' No operation
%IP_OPT_SECURITY = &H82?      ' Security option
%IP_OPT_LSRR     = &H83?      ' Loose source route
%IP_OPT_SSRR     = &H89?      ' Strict source route
%IP_OPT_RR       = &H7        ' Record route
%IP_OPT_TS       = &H44       ' Timestamp
%IP_OPT_SID      = &H88?      ' Stream ID (obsolete)
%IP_OPT_ROUTER_ALERT = &H94?  ' Router Alert Option

%MAX_OPT_SIZE   = 40         ' Maximum length of IP options in bytes

#IF %DEF(%CHICAGO)

' Ioctls code exposed by Memphis tcpip stack.
' For NT these ioctls are define in ntddip.h  (private\inc)

%IOCTL_IP_RTCHANGE_NOTIFY_REQUEST  = 101
%IOCTL_IP_ADDCHANGE_NOTIFY_REQUEST = 102
%IOCTL_ARP_SEND_REQUEST            = 103
%IOCTL_IP_INTERFACE_INFO           = 104
%IOCTL_IP_GET_BEST_INTERFACE       = 105
%IOCTL_IP_UNIDIRECTIONAL_ADAPTER_ADDRESS      = 106

#ENDIF
