'------------------------------------------------------------------------------
'
'  IpHlpApi.inc
'    Header file for functions to interact with the IP Stack for MIB-II and
'    related functionality
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from IpHlpApi.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%IPHLPAPI_H = 1


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                          '
' IPRTRMIB.H has the definitions of the structures used to set and get     '
' information                                                              '
'                                                                          '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

#INCLUDE "ipexport.inc"
#INCLUDE "tcpestats.inc"
#INCLUDE "WinDns.inc"
#INCLUDE "Ws2Def.inc"
#INCLUDE "ws2ipdef.inc"

'
' Network String parsing API
'

%NET_STRING_IPV4_ADDRESS           = &H00000001
   ' The string identifies an IPv4 Host/router using literal address.
   ' (port or prefix not allowed)
%NET_STRING_IPV4_SERVICE           = &H00000002
   ' The string identifies an IPv4 service using literal address.
   ' (port required; prefix not allowed)
%NET_STRING_IPV4_NETWORK           = &H00000004
   ' The string identifies an IPv4 network.
   ' (prefix required; port not allowed)
%NET_STRING_IPV6_ADDRESS           = &H00000008
   ' The string identifies an IPv6 Host/router using literal address.
   ' (port or prefix not allowed; scope-id allowed)
%NET_STRING_IPV6_ADDRESS_NO_SCOPE  = &H00000010
   ' The string identifies an IPv6 Host/router using literal address
   ' where the interface context is already known.
   ' (port or prefix not allowed; scope-id not allowed)
%NET_STRING_IPV6_SERVICE           = &H00000020
   ' The string identifies an IPv6 service using literal address.
   ' (port required; prefix not allowed; scope-id allowed)
%NET_STRING_IPV6_SERVICE_NO_SCOPE  = &H00000040
   ' The string identifies an IPv6 service using literal address
   ' where the interface context is already known.
   ' (port required; prefix not allowed; scope-id not allowed)
%NET_STRING_IPV6_NETWORK           = &H00000080
   ' The string identifies an IPv6 network.
   ' (prefix required; port or scope-id not allowed)
%NET_STRING_NAMED_ADDRESS          = &H00000100
   ' The string identifies an Internet Host using DNS.
   ' (port or prefix or scope-id not allowed)
%NET_STRING_NAMED_SERVICE          = &H00000200
   ' The string identifies an Internet service using DNS.
   ' (port required; prefix or scope-id not allowed)

%NET_STRING_IP_ADDRESS             = (%NET_STRING_IPV4_ADDRESS   OR _
                                      %NET_STRING_IPV6_ADDRESS)

%NET_STRING_IP_ADDRESS_NO_SCOPE    = (%NET_STRING_IPV4_ADDRESS   OR _
                                      %NET_STRING_IPV6_ADDRESS_NO_SCOPE)

%NET_STRING_IP_SERVICE             = (%NET_STRING_IPV4_SERVICE   OR _
                                      %NET_STRING_IPV6_SERVICE)

%NET_STRING_IP_SERVICE_NO_SCOPE    = (%NET_STRING_IPV4_SERVICE   OR _
                                      %NET_STRING_IPV6_SERVICE_NO_SCOPE)

%NET_STRING_IP_NETWORK             = (%NET_STRING_IPV4_NETWORK   OR _
                                      %NET_STRING_IPV6_NETWORK)

%NET_STRING_ANY_ADDRESS            = (%NET_STRING_NAMED_ADDRESS  OR _
                                      %NET_STRING_IP_ADDRESS)

%NET_STRING_ANY_ADDRESS_NO_SCOPE   = (%NET_STRING_NAMED_ADDRESS  OR _
                                      %NET_STRING_IP_ADDRESS_NO_SCOPE)

%NET_STRING_ANY_SERVICE            = (%NET_STRING_NAMED_SERVICE  OR _
                                      %NET_STRING_IP_SERVICE)

%NET_STRING_ANY_SERVICE_NO_SCOPE   = (%NET_STRING_NAMED_SERVICE  OR _
                                      %NET_STRING_IP_SERVICE_NO_SCOPE)

MACRO NET_ADDRESS_FORMAT_enum=LONG
ENUM NET_ADDRESS_FORMAT SINGULAR
    NET_ADDRESS_FORMAT_UNSPECIFIED
    NET_ADDRESS_DNS_NAME
    NET_ADDRESS_IPV4
    NET_ADDRESS_IPV6
END ENUM

'#IF %DEF(%WS2DEF) AND %DEF(%WS2IPDEF) AND %DEF(%WINDNS_INCLUDED)
    ' app must include winsock2.h, ws2ipdef.h, and windns.h to use this API

TYPE NET_ADDRESS_INFO_type
    Address AS WSTRINGZ * %DNS_MAX_NAME_BUFFER_LENGTH
    PORT    AS WSTRINGZ * 6
END TYPE

UNION NET_ADDRESS_INFO_union
    NamedAddress AS NET_ADDRESS_INFO_type
    Ipv4Address  AS SOCKADDR_IN
    Ipv6Address  AS SOCKADDR_IN6
    IpAddress    AS SOCKADDR
END UNION

TYPE NET_ADDRESS_INFO
    Format AS NET_ADDRESS_FORMAT_enum
    NET_ADDRESS_INFO_union
END TYPE

#INCLUDE "WinSock2.inc"
#INCLUDE "iprtrmib.inc"
#INCLUDE "iptypes.inc"

''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                          '
' The GetXXXTable APIs take a buffer and a size of buffer.  If the buffer  '
' is not large enough, the APIs return ERROR_INSUFFICIENT_BUFFER  and      '
' *pdwSize is the required buffer size                                     '
' The bOrder is a BOOLEAN, which if TRUE sorts the table according to      '
' MIB-II (RFC XXXX)                                                        '
'                                                                          '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                          '
' Retrieves the number of interfaces in the system. These include LAN and  '
' WAN interfaces                                                           '
'                                                                          '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''


DECLARE FUNCTION GetNumberOfInterfaces LIB "IpHlpApi.dll" _
    ALIAS "GetNumberOfInterfaces" (pdwNumIf AS DWORD) AS DWORD


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                          '
' Gets the MIB-II ifEntry                                                  '
' The dwIndex field of the MIB_IFROW should be set to the index of the     '
' interface being queried                                                  '
'                                                                          '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION GetIfEntry LIB "IpHlpApi.dll" ALIAS "GetIfEntry" _
    (pIfRow AS MIB_IFROW) AS DWORD


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                          '
' Gets the MIB-II IfTable                                                  '
'                                                                          '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION GetIfTable LIB "IpHlpApi.dll" ALIAS "GetIfTable" _
    (pIfTable AS MIB_IFTABLE, pdwSize AS DWORD, BYVAL BORDER AS LONG) AS DWORD


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                          '
' Gets the Interface to IP Address mapping                                 '
'                                                                          '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION GetIpAddrTable LIB "IpHlpApi.dll" ALIAS "GetIpAddrTable" _
    (pIpAddrTable AS MIB_IPADDRTABLE, pdwSize AS DWORD, BYVAL BORDER AS LONG) _
    AS DWORD


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                          '
' Gets the current IP Address to Physical Address (ARP) mapping            '
'                                                                          '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION GetIpNetTable LIB "IpHlpApi.dll" ALIAS "GetIpNetTable" _
    (IpNetTable AS MIB_IPNETTABLE, SizePointer AS DWORD, BYVAL Order AS LONG) _
    AS DWORD


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                          '
' Gets the IP Routing Table  (RFX XXXX)                                    '
'                                                                          '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION GetIpForwardTable LIB "IpHlpApi.dll" _
    ALIAS "GetIpForwardTable" (pIpForwardTable AS MIB_IPFORWARDTABLE, _
    pdwSize AS DWORD, BYVAL BORDER AS LONG) AS DWORD


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                          '
' Gets TCP Connection/UDP Listener Table                                   '
'                                                                          '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION GetTcpTable LIB "IpHlpApi.dll" ALIAS "GetTcpTable" _
    (TcpTable AS MIB_TCPTABLE, SizePointer AS DWORD, BYVAL Order AS LONG) _
    AS DWORD

DECLARE FUNCTION GetExtendedTcpTable LIB "IpHlpApi.dll" _
    ALIAS "GetExtendedTcpTable" (pTcpTable AS ANY, pdwSize AS DWORD, _
    BYVAL BORDER AS LONG, BYVAL ulAf AS DWORD, _
    BYVAL TableClass AS TCP_TABLE_CLASS_enum, BYVAL Reserved AS DWORD) AS DWORD

DECLARE FUNCTION GetOwnerModuleFromTcpEntry LIB "IpHlpApi.dll" _
    ALIAS "GetOwnerModuleFromTcpEntry" (pTcpEntry AS MIB_TCPROW_OWNER_MODULE, _
    BYVAL nClass AS TCPIP_OWNER_MODULE_INFO_CLASS_enum, pBuffer AS ANY, _
    pdwSize AS DWORD) AS DWORD

DECLARE FUNCTION GetUdpTable LIB "IpHlpApi.dll" ALIAS "GetUdpTable" _
    (UdpTable AS MIB_UDPTABLE, SizePointer AS DWORD, BYVAL Order AS LONG) _
    AS DWORD

DECLARE FUNCTION GetExtendedUdpTable LIB "IpHlpApi.dll" _
    ALIAS "GetExtendedUdpTable" (pUdpTable AS ANY, pdwSize AS DWORD, _
    BYVAL BORDER AS LONG, BYVAL ulAf AS DWORD, _
    BYVAL TableClass AS UDP_TABLE_CLASS_enum, BYVAL Reserved AS DWORD) AS DWORD

DECLARE FUNCTION GetOwnerModuleFromUdpEntry LIB "IpHlpApi.dll" _
    ALIAS "GetOwnerModuleFromUdpEntry" (pUdpEntry AS MIB_UDPROW_OWNER_MODULE, _
    BYVAL nClass AS TCPIP_OWNER_MODULE_INFO_CLASS_enum, pBuffer AS ANY, _
    pdwSize AS DWORD) AS DWORD

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

DECLARE FUNCTION GetTcpTable2 LIB "IpHlpApi.dll" ALIAS "GetTcpTable2" _
    (TcpTable AS MIB_TCPTABLE2, SizePointer AS DWORD, BYVAL BORDER AS LONG) _
    AS DWORD

#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)

#IF (%NTDDI_VERSION < %NTDDI_VISTA)
'
' Deprecated APIs, Added for documentation.
'

DECLARE FUNCTION AllocateAndGetTcpExTableFromStack LIB "IpHlpApi.dll" _
    ALIAS "AllocateAndGetTcpExTableFromStack" (ppTcpTable AS ANY, _
    BYVAL BORDER AS LONG, BYVAL hHeap AS DWORD, BYVAL dwFlags AS DWORD, _
    BYVAL dwFamily AS DWORD) AS DWORD

DECLARE FUNCTION AllocateAndGetUdpExTableFromStack LIB "IpHlpApi.dll" _
    ALIAS "AllocateAndGetUdpExTableFromStack" (ppUdpTable AS ANY, _
    BYVAL BORDER AS LONG, BYVAL hHeap AS DWORD, BYVAL dwFlags AS DWORD, _
    BYVAL dwFamily AS DWORD) AS DWORD

#ENDIF ' (%NTDDI_VERSION < %NTDDI_VISTA)

#IF %DEF(%WS2IPDEF)
'
' The following definitions require Winsock2.
'

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

DECLARE FUNCTION GetTcp6Table LIB "IpHlpApi.dll" ALIAS "GetTcp6Table" _
    (TcpTable AS MIB_TCP6TABLE, SizePointer AS DWORD, BYVAL BORDER AS LONG) _
    AS DWORD

DECLARE FUNCTION GetTcp6Table2 LIB "IpHlpApi.dll" ALIAS "GetTcp6Table2" _
    (TcpTable AS MIB_TCP6TABLE2, SizePointer AS DWORD, BYVAL BORDER AS LONG) _
    AS DWORD

#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)

#IF %DEF(%WINAPI)

DECLARE FUNCTION GetPerTcpConnectionEStats LIB "IpHlpApi.dll" _
    ALIAS "GetPerTcpConnectionEStats" (Row AS MIB_TCPROW, _
    BYVAL EstatsType AS TCP_ESTATS_TYPE_enum, Rw AS BYTE, _
    BYVAL RwVersion AS DWORD, BYVAL RwSize AS DWORD, Ros AS BYTE, _
    BYVAL RosVersion AS DWORD, BYVAL RosSize AS DWORD, Rod AS BYTE, _
    BYVAL RodVersion AS DWORD, BYVAL RodSize AS DWORD) AS DWORD

DECLARE FUNCTION SetPerTcpConnectionEStats LIB "IpHlpApi.dll" _
    ALIAS "SetPerTcpConnectionEStats" (Row AS MIB_TCPROW, _
    BYVAL EstatsType AS TCP_ESTATS_TYPE_enum, Rw AS BYTE, _
    BYVAL RwVersion AS DWORD, BYVAL RwSize AS DWORD, BYVAL Offset AS DWORD) _
    AS DWORD

#IF %DEF(%WS2IPDEF)

DECLARE FUNCTION GetPerTcp6ConnectionEStats LIB "IpHlpApi.dll" _
    ALIAS "GetPerTcp6ConnectionEStats" (Row AS MIB_TCP6ROW, _
    BYVAL EstatsType AS TCP_ESTATS_TYPE_enum, Rw AS BYTE, _
    BYVAL RwVersion AS DWORD, BYVAL RwSize AS DWORD, Ros AS BYTE, _
    BYVAL RosVersion AS DWORD, BYVAL RosSize AS DWORD, Rod AS BYTE, _
    BYVAL RodVersion AS DWORD, BYVAL RodSize AS DWORD) AS DWORD

DECLARE FUNCTION SetPerTcp6ConnectionEStats LIB "IpHlpApi.dll" _
    ALIAS "SetPerTcp6ConnectionEStats" (Row AS MIB_TCP6ROW, _
    BYVAL EstatsType AS TCP_ESTATS_TYPE_enum, Rw AS BYTE, _
    BYVAL RwVersion AS DWORD, BYVAL RwSize AS DWORD, BYVAL Offset AS DWORD) _
    AS DWORD

#ENDIF ' %WS2IPDEF

#ENDIF ' %WINAPI


DECLARE FUNCTION GetOwnerModuleFromTcp6Entry LIB "IpHlpApi.dll" _
    ALIAS "GetOwnerModuleFromTcp6Entry" _
    (pTcpEntry AS MIB_TCP6ROW_OWNER_MODULE, _
    BYVAL nClass AS TCPIP_OWNER_MODULE_INFO_CLASS_enum, pBuffer AS ANY, _
    pdwSize AS DWORD) AS DWORD

DECLARE FUNCTION GetUdp6Table LIB "IpHlpApi.dll" ALIAS "GetUdp6Table" _
    (Udp6Table AS MIB_UDP6TABLE, SizePointer AS DWORD, BYVAL BORDER AS LONG) _
    AS DWORD

DECLARE FUNCTION GetOwnerModuleFromUdp6Entry LIB "IpHlpApi.dll" _
    ALIAS "GetOwnerModuleFromUdp6Entry" _
    (pUdpEntry AS MIB_UDP6ROW_OWNER_MODULE, _
    BYVAL nClass AS TCPIP_OWNER_MODULE_INFO_CLASS_enum, pBuffer AS ANY, _
    pdwSize AS DWORD) AS DWORD

#ENDIF ' %WS2IPDEF


DECLARE FUNCTION GetOwnerModuleFromPidAndInfo LIB "IpHlpApi.dll" _
    ALIAS "GetOwnerModuleFromPidAndInfo" (BYVAL ulPid AS DWORD, _
    pInfo AS QUAD, BYVAL nClass AS TCPIP_OWNER_MODULE_INFO_CLASS_enum, _
    pBuffer AS ANY, pdwSize AS DWORD) AS DWORD


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                          '
' Gets IP/ICMP/TCP/UDP Statistics                                          '
'                                                                          '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)

DECLARE FUNCTION GetIpStatistics LIB "IpHlpApi.dll" ALIAS "GetIpStatistics" _
    (Statistics AS MIB_IPSTATS) AS DWORD

DECLARE FUNCTION GetIcmpStatistics LIB "IpHlpApi.dll" _
    ALIAS "GetIcmpStatistics" (Statistics AS MIB_ICMP) AS DWORD

DECLARE FUNCTION GetTcpStatistics LIB "IpHlpApi.dll" _
    ALIAS "GetTcpStatistics" (Statistics AS MIB_TCPSTATS) AS DWORD

DECLARE FUNCTION GetUdpStatistics LIB "IpHlpApi.dll" _
    ALIAS "GetUdpStatistics" (Stats AS MIB_UDPSTATS) AS DWORD

#ENDIF ' #if (%NTDDI_VERSION >= %NTDDI_WIN2K)

' [Microsoft bug]
'#IF (%NTDDI_VERSION >= %NTDDI_XP)
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)

DECLARE FUNCTION GetIpStatisticsEx LIB "IpHlpApi.dll" _
    ALIAS "GetIpStatisticsEx" (Statistics AS MIB_IPSTATS, _
    BYVAL Family AS DWORD) AS DWORD

DECLARE FUNCTION SetIpStatisticsEx LIB "IpHlpApi.dll" _
    ALIAS "SetIpStatisticsEx" (Statistics AS MIB_IPSTATS, _
    BYVAL Family AS DWORD) AS DWORD

DECLARE FUNCTION GetIcmpStatisticsEx LIB "IpHlpApi.dll" _
    ALIAS "GetIcmpStatisticsEx" (Statistics AS MIB_ICMP_EX, _
    BYVAL Family AS DWORD) AS DWORD

DECLARE FUNCTION GetTcpStatisticsEx LIB "IpHlpApi.dll" _
    ALIAS "GetTcpStatisticsEx" (Statistics AS MIB_TCPSTATS, _
    BYVAL Family AS DWORD) AS DWORD

DECLARE FUNCTION GetUdpStatisticsEx LIB "IpHlpApi.dll" _
    ALIAS "GetUdpStatisticsEx" (Statistics AS MIB_UDPSTATS, _
    BYVAL Family AS DWORD) AS DWORD

#ENDIF ' #if (%NTDDI_VERSION >= %NTDDI_[WIN]XP)



''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                          '
' Used to set the ifAdminStatus on an interface.  The only fields of the   '
' MIB_IFROW that are relevant are the dwIndex (index of the interface      '
' whose status needs to be set) and the dwAdminStatus which can be either  '
' MIB_IF_ADMIN_STATUS_UP or MIB_IF_ADMIN_STATUS_DOWN                       '
'                                                                          '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION SetIfEntry LIB "IpHlpApi.dll" ALIAS "SetIfEntry" _
    (pIfRow AS MIB_IFROW) AS DWORD



''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                          '
' Used to create, modify or delete a route.  In all cases the              '
' dwForwardIfIndex, dwForwardDest, dwForwardMask, dwForwardNextHop and     '
' dwForwardPolicy MUST BE SPECIFIED. Currently dwForwardPolicy is unused   '
' and MUST BE 0.                                                           '
' For a set, the complete MIB_IPFORWARDROW structure must be specified     '
'                                                                          '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION CreateIpForwardEntry LIB "IpHlpApi.dll" _
    ALIAS "CreateIpForwardEntry" (pRoute AS MIB_IPFORWARDROW) AS DWORD

DECLARE FUNCTION SetIpForwardEntry LIB "IpHlpApi.dll" _
    ALIAS "SetIpForwardEntry" (pRoute AS MIB_IPFORWARDROW) AS DWORD

DECLARE FUNCTION DeleteIpForwardEntry LIB "IpHlpApi.dll" _
    ALIAS "DeleteIpForwardEntry" (pRoute AS MIB_IPFORWARDROW) AS DWORD


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                          '
' Used to set the ipForwarding to ON or OFF (currently only ON->OFF is     '
' allowed) and to set the defaultTTL.  If only one of the fields needs to  '
' be modified and the other needs to be the same as before the other field '
' needs to be set to MIB_USE_CURRENT_TTL or MIB_USE_CURRENT_FORWARDING as  '
' the case may be                                                          '
'                                                                          '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)

DECLARE FUNCTION SetIpStatistics LIB "IpHlpApi.dll" ALIAS "SetIpStatistics" _
    (pIpStats AS MIB_IPSTATS) AS DWORD

#ENDIF


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                          '
' Used to set the defaultTTL.                                              '
'                                                                          '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION SetIpTTL LIB "IpHlpApi.dll" ALIAS "SetIpTTL" _
    (BYVAL nTTL AS DWORD) AS DWORD


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                          '
' Used to create, modify or delete an ARP entry.  In all cases the dwIndex '
' dwAddr field MUST BE SPECIFIED.                                          '
' For a set, the complete MIB_IPNETROW structure must be specified         '
'                                                                          '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION CreateIpNetEntry LIB "IpHlpApi.dll" _
    ALIAS "CreateIpNetEntry" (pArpEntry AS MIB_IPNETROW) AS DWORD

DECLARE FUNCTION SetIpNetEntry LIB "IpHlpApi.dll" _
    ALIAS "SetIpNetEntry" (pArpEntry AS MIB_IPNETROW) AS DWORD

DECLARE FUNCTION DeleteIpNetEntry LIB "IpHlpApi.dll" _
    ALIAS "DeleteIpNetEntry" (pArpEntry AS MIB_IPNETROW) AS DWORD

DECLARE FUNCTION FlushIpNetTable LIB "IpHlpApi.dll" _
    ALIAS "FlushIpNetTable" (BYVAL dwIfIndex AS DWORD) AS DWORD


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                          '
' Used to create or delete a Proxy ARP entry. The dwIndex is the index of  '
' the interface on which to PARP for the dwAddress.  If the interface is   '
' of a type that doesnt support ARP, e.g. PPP, then the call will fail     '
'                                                                          '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION CreateProxyArpEntry LIB "IpHlpApi.dll" _
    ALIAS "CreateProxyArpEntry" (BYVAL dwAddress AS DWORD, _
    BYVAL dwMask AS DWORD, BYVAL dwIfIndex AS DWORD) AS DWORD

DECLARE FUNCTION DeleteProxyArpEntry LIB "IpHlpApi.dll" _
    ALIAS "DeleteProxyArpEntry" (BYVAL dwAddress AS DWORD, _
    BYVAL dwMask AS DWORD, BYVAL dwIfIndex AS DWORD) AS DWORD


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                          '
' Used to set the state of a TCP Connection. The only state that it can be '
' set to is MIB_TCP_STATE_DELETE_TCB.  The complete MIB_TCPROW structure   '
' MUST BE SPECIFIED                                                        '
'                                                                          '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION SetTcpEntry LIB "IpHlpApi.dll" ALIAS "SetTcpEntry" _
    (pTcpRow AS MIB_TCPROW) AS DWORD

DECLARE FUNCTION GetInterfaceInfo LIB "IpHlpApi.dll" _
    ALIAS "GetInterfaceInfo" (pIfTable AS IP_INTERFACE_INFO, _
    dwOutBufLen AS DWORD) AS DWORD

DECLARE FUNCTION GetUniDirectionalAdapterInfo LIB "IpHlpApi.dll" _
    ALIAS "GetUniDirectionalAdapterInfo" _
    (pIPIfInfo AS IP_UNIDIRECTIONAL_ADAPTER_ADDRESS, _
    dwOutBufLen AS DWORD) AS DWORD


#IF (%NTDDI_VERSION >= %NTDDI_WIN2KSP1)
#IF NOT %DEF(%NHPALLOCATEANDGETINTERFACEINFOFROMSTACK_DEFINED)
%NHPALLOCATEANDGETINTERFACEINFOFROMSTACK_DEFINED = 1

DECLARE FUNCTION NhpAllocateAndGetInterfaceInfoFromStack LIB "IpHlpApi.dll" _
    ALIAS "NhpAllocateAndGetInterfaceInfoFromStack" (ppTable AS ANY, _
    pdwCount AS DWORD, BYVAL BORDER AS LONG, BYVAL hHeap AS DWORD, _
    BYVAL dwFlags AS DWORD) AS DWORD

#ENDIF ' #IF NOT %DEF(%NHPALLOCATEANDGETINTERFACEINFOFROMSTACK_DEFINED)
#ENDIF ' (NTDDI_VERSION >= NTDDI_WIN2KSP1)


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                          '
' Gets the "best" outgoing interface for the specified destination address '
'                                                                          '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION GetBestInterface LIB "IpHlpApi.dll" ALIAS "GetBestInterface" _
    (BYVAL dwDestAddr AS DWORD, pdwBestIfIndex AS DWORD) AS DWORD

DECLARE FUNCTION GetBestInterfaceEx LIB "IpHlpApi.dll" _
    ALIAS "GetBestInterfaceEx" (pDestAddr AS ANY, pdwBestIfIndex AS DWORD) _
    AS DWORD


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                          '
' Gets the best (longest matching prefix) route for the given destination  '
' If the source address is also specified (i.e. is not &H00000000), and    '
' there are multiple "best" routes to the given destination, the returned  '
' route will be one that goes out over the interface which has an address  '
' that matches the source address.                                         '
'                                                                          '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION GetBestRoute LIB "IpHlpApi.dll" ALIAS "GetBestRoute" _
    (BYVAL dwDestAddr AS DWORD, BYVAL dwSourceAddr AS DWORD, _
    pBestRoute AS MIB_IPFORWARDROW) AS DWORD


DECLARE FUNCTION NotifyAddrChange LIB "IpHlpApi.dll" ALIAS "NotifyAddrChange" _
    (HANDLE AS DWORD, lpOverlapped AS OVERLAPPED) AS DWORD

DECLARE FUNCTION NotifyRouteChange LIB "IpHlpApi.dll" _
    ALIAS "NotifyRouteChange" (HANDLE AS DWORD, lpOverlapped AS OVERLAPPED) _
    AS DWORD

DECLARE FUNCTION CancelIPChangeNotify LIB "IpHlpApi.dll" _
    ALIAS "CancelIPChangeNotify" (notifyOverlapped AS OVERLAPPED) AS LONG

DECLARE FUNCTION GetAdapterIndex LIB "IpHlpApi.dll" ALIAS "GetAdapterIndex" _
    (AdapterName AS WSTRINGZ, IfIndex AS DWORD) AS DWORD

DECLARE FUNCTION AddIPAddress LIB "IpHlpApi.dll" ALIAS "AddIPAddress" _
    (BYVAL Address AS DWORD, BYVAL IpMask AS DWORD, BYVAL IfIndex AS DWORD, _
    NTEContext AS DWORD, NTEInstance AS DWORD) AS DWORD

DECLARE FUNCTION DeleteIPAddress LIB "IpHlpApi.dll" _
    ALIAS "DeleteIPAddress" (BYVAL NTEContext AS DWORD) AS DWORD


#IF (%NTDDI_VERSION >= %NTDDI_WIN2KSP1)

DECLARE FUNCTION GetNetworkParams LIB "IpHlpApi.dll" _
    ALIAS "GetNetworkParams" (pFixedInfo AS FIXED_INFO, pOutBufLen AS DWORD) _
    AS DWORD

#ENDIF

DECLARE FUNCTION GetAdaptersInfo LIB "IpHlpApi.dll" _
    ALIAS "GetAdaptersInfo" (AdapterInfo AS IP_ADAPTER_INFO, _
    SizePointer AS DWORD) AS DWORD

DECLARE FUNCTION GetAdapterOrderMap LIB "IpHlpApi.dll" _
    ALIAS "GetAdapterOrderMap" () AS DWORD


#IF %DEF(%WINSOCK2API)

'
' The following functions require Winsock2.
'

DECLARE FUNCTION GetAdaptersAddresses LIB "IpHlpApi.dll" _
    ALIAS "GetAdaptersAddresses" (BYVAL Family AS DWORD, _
    BYVAL Flags AS DWORD, Reserved AS ANY, _
    AdapterAddresses AS IP_ADAPTER_ADDRESSES, SizePointer AS DWORD) AS DWORD

#ENDIF

#IF (%NTDDI_VERSION >= %NTDDI_WIN2KSP1)

DECLARE FUNCTION GetPerAdapterInfo LIB "IpHlpApi.dll" _
    ALIAS "GetPerAdapterInfo" (BYVAL IfIndex AS DWORD, _
    BYVAL pPerAdapterInfo AS IP_PER_ADAPTER_INFO PTR, pOutBufLen AS DWORD) _
    AS DWORD

#ENDIF

DECLARE FUNCTION IpReleaseAddress LIB "IpHlpApi.dll" _
    ALIAS "IpReleaseAddress" (AdapterInfo AS IP_ADAPTER_INDEX_MAP) AS DWORD

DECLARE FUNCTION IpRenewAddress LIB "IpHlpApi.dll" _
    ALIAS "IpRenewAddress" (AdapterInfo AS IP_ADAPTER_INDEX_MAP) AS DWORD


DECLARE FUNCTION SendARP LIB "IpHlpApi.dll" ALIAS "SendARP" _
    (BYVAL DestIP AS DWORD, BYVAL SrcIP AS DWORD, pMacAddr AS ANY, _
    PhyAddrLen AS DWORD) AS DWORD

DECLARE FUNCTION GetRTTAndHopCount LIB "IpHlpApi.dll" _
    ALIAS "GetRTTAndHopCount" (BYVAL DestIpAddress AS DWORD, _
    HopCount AS DWORD, BYVAL MaxHops AS DWORD, RTT AS DWORD) AS LONG

DECLARE FUNCTION GetFriendlyIfIndex LIB "IpHlpApi.dll" _
    ALIAS "GetFriendlyIfIndex" (BYVAL IfIndex AS DWORD) AS DWORD

DECLARE FUNCTION EnableRouter LIB "IpHlpApi.dll" ALIAS "EnableRouter" _
    (pHandle AS DWORD, pOverlapped AS OVERLAPPED) AS DWORD

DECLARE FUNCTION UnenableRouter LIB "IpHlpApi.dll" ALIAS "UnenableRouter" _
    (pOverlapped AS OVERLAPPED, lpdwEnableCount AS DWORD) AS DWORD

DECLARE FUNCTION DisableMediaSense LIB "IpHlpApi.dll" _
    ALIAS "DisableMediaSense" (pHandle AS DWORD, pOverlapped AS OVERLAPPED) _
    AS DWORD

DECLARE FUNCTION RestoreMediaSense LIB "IpHlpApi.dll" _
    ALIAS "RestoreMediaSense" (pOverlapped AS OVERLAPPED, _
    lpdwEnableCount AS DWORD) AS DWORD


#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

DECLARE FUNCTION GetIpErrorString LIB "IpHlpApi.dll" _
    ALIAS "GetIpErrorString" (BYVAL ErrorCode AS DWORD, _
    Buffer AS WSTRINGZ, dSize AS DWORD) AS DWORD

#IF %DEF(%WS2DEF)

DECLARE FUNCTION ResolveNeighbor LIB "IpHlpApi.dll" _
    ALIAS "ResolveNeighbor" (NetworkAddress AS SOCKADDR, _
    PhysicalAddress AS ANY, PhysicalAddressLength AS DWORD) AS DWORD

#ENDIF ' #IF %DEF(%WS2DEF)

'
' Port reservation API routines.
'

DECLARE FUNCTION CreatePersistentTcpPortReservation LIB "IpHlpApi.dll" _
    ALIAS "CreatePersistentTcpPortReservation" (BYVAL StartPort AS WORD, _
    BYVAL NumberOfPorts AS WORD, Token AS QUAD) AS DWORD

DECLARE FUNCTION CreatePersistentUdpPortReservation LIB "IpHlpApi.dll" _
    ALIAS "CreatePersistentUdpPortReservation" (BYVAL StartPort AS WORD, _
    BYVAL NumberOfPorts AS WORD, Token AS QUAD) AS DWORD

DECLARE FUNCTION DeletePersistentTcpPortReservation LIB "IpHlpApi.dll" _
    ALIAS "DeletePersistentTcpPortReservation" (BYVAL StartPort AS WORD, _
    BYVAL NumberOfPorts AS WORD) AS DWORD

DECLARE FUNCTION DeletePersistentUdpPortReservation LIB "IpHlpApi.dll" _
    ALIAS "DeletePersistentUdpPortReservation" (BYVAL StartPort AS WORD, _
    BYVAL NumberOfPorts AS WORD) AS DWORD

DECLARE FUNCTION LookupPersistentTcpPortReservation LIB "IpHlpApi.dll" _
    ALIAS "LookupPersistentTcpPortReservation" (BYVAL StartPort AS WORD, _
    BYVAL NumberOfPorts AS WORD, Token AS QUAD) AS DWORD

DECLARE FUNCTION LookupPersistentUdpPortReservation LIB "IpHlpApi.dll" _
    ALIAS "LookupPersistentUdpPortReservation" (BYVAL StartPort AS WORD, _
    BYVAL NumberOfPorts AS WORD, Token AS QUAD) AS DWORD


DECLARE FUNCTION ParseNetworkString LIB "IpHlpApi.dll" _
    ALIAS "ParseNetworkString" (NetworkString AS WSTRINGZ, _
    BYVAL dTypes AS DWORD, AddressInfo AS NET_ADDRESS_INFO, _
    PortNumber AS WORD, PrefixLength AS BYTE) AS DWORD

'#ENDIF ' #IF %DEF(%WS2DEF) AND %DEF(%WS2IPDEF) AND %DEF(%WINDNS_INCLUDED)


#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

#INCLUDE "netioapi.inc"

#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)
