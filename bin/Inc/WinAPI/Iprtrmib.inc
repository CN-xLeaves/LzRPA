'------------------------------------------------------------------------------
'
'  IpRtrMib.inc
'    This file contains:
'    o Definitions of the MIB_XX structures passed to and from the IP Router
'      Manager to query and set MIB variables handled by the IP Router Manager
'    o The #defines for the MIB variables IDs  handled by the IP Router Manager
'      and made accessible by the MprAdminMIBXXX APIs
'    o The Routing PID of the IP Router Manager (as mentioned in ipinfoid.h)
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from IpRtrMib.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%ROUTING_IPRTRMIB_H = 1


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''                                                                          ''
'' Included to get the value of MAX_INTERFACE_NAME_LEN                      ''
''                                                                          ''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

#INCLUDE "mprapi.inc"

''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''                                                                          ''
'' Included to get the necessary constants                                  ''
''                                                                          ''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

#INCLUDE "ipifcons.inc"

''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''                                                                          ''
'' This is the Id for IP Router Manager.  The Router Manager handles        ''
'' MIB-II, Forwarding MIB and some enterprise specific information.         ''
'' Calls made with any other ID are passed on to the corresponding protocol ''
'' For example, an MprAdminMIBXXX call with a protocol ID of PID_IP and     ''
'' a routing Id of 0xD will be sent to the IP Router Manager and then       ''
'' forwarded to OSPF                                                        ''
'' This lives in the same number space as the protocol Ids of RIP, OSPF     ''
'' etc, so any change made to it should be done keeping this in mind        ''
''                                                                          ''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''


%IPRTRMGR_PID = 10000

#IF NOT %DEF(%ANY_SIZE)

%ANY_SIZE = 1

#ENDIF

''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''                                                                          ''
'' The following #defines are the Ids of the MIB variables made accessible  ''
'' to the user via MprAdminMIBXXX Apis.  It will be noticed that these are  ''
'' not the same as RFC 1213, since the MprAdminMIBXXX APIs work on rows and ''
'' groups instead of scalar variables                                       ''
''                                                                          ''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''


%IF_NUMBER           = 0
%IF_TABLE            = (%IF_NUMBER          + 1)
%IF_ROW              = (%IF_TABLE           + 1)
%IP_STATS            = (%IF_ROW             + 1)
%IP_ADDRTABLE        = (%IP_STATS           + 1)
%IP_ADDRROW          = (%IP_ADDRTABLE       + 1)
%IP_FORWARDNUMBER    = (%IP_ADDRROW         + 1)
%IP_FORWARDTABLE     = (%IP_FORWARDNUMBER   + 1)
%IP_FORWARDROW       = (%IP_FORWARDTABLE    + 1)
%IP_NETTABLE         = (%IP_FORWARDROW      + 1)
%IP_NETROW           = (%IP_NETTABLE        + 1)
%ICMP_STATS          = (%IP_NETROW          + 1)
%TCP_STATS           = (%ICMP_STATS         + 1)
%TCP_TABLE           = (%TCP_STATS          + 1)
%TCP_ROW             = (%TCP_TABLE          + 1)
%UDP_STATS           = (%TCP_ROW            + 1)
%UDP_TABLE           = (%UDP_STATS          + 1)
%UDP_ROW             = (%UDP_TABLE          + 1)
%MCAST_MFE           = (%UDP_ROW            + 1)
%MCAST_MFE_STATS     = (%MCAST_MFE          + 1)
%BEST_IF             = (%MCAST_MFE_STATS    + 1)
%BEST_ROUTE          = (%BEST_IF            + 1)
%PROXY_ARP           = (%BEST_ROUTE         + 1)
%MCAST_IF_ENTRY      = (%PROXY_ARP          + 1)
%MCAST_GLOBAL        = (%MCAST_IF_ENTRY     + 1)
%IF_STATUS           = (%MCAST_GLOBAL       + 1)
%MCAST_BOUNDARY      = (%IF_STATUS          + 1)
%MCAST_SCOPE         = (%MCAST_BOUNDARY     + 1)
%DEST_MATCHING       = (%MCAST_SCOPE        + 1)
%DEST_LONGER         = (%DEST_MATCHING      + 1)
%DEST_SHORTER        = (%DEST_LONGER        + 1)
%ROUTE_MATCHING      = (%DEST_SHORTER       + 1)
%ROUTE_LONGER        = (%ROUTE_MATCHING     + 1)
%ROUTE_SHORTER       = (%ROUTE_LONGER       + 1)
%ROUTE_STATE         = (%ROUTE_SHORTER      + 1)
%MCAST_MFE_STATS_EX  = (%ROUTE_STATE        + 1)
%IP6_STATS           = (%MCAST_MFE_STATS_EX + 1)
%UDP6_STATS          = (%IP6_STATS          + 1)
%TCP6_STATS          = (%UDP6_STATS         + 1)

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%NUMBER_OF_EXPORTED_VARIABLES    = (%TCP6_STATS + 1)
#ELSE
%NUMBER_OF_EXPORTED_VARIABLES    = (%ROUTE_STATE + 1)
#ENDIF


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''                                                                          ''
'' MIB_OPAQUE_QUERY is the structure filled in by the user to identify a    ''
'' MIB variable                                                             ''
''                                                                          ''
''  dwVarId     ID of MIB Variable (One of the Ids #defined above)          ''
''  dwVarIndex  Variable sized array containing the indices needed to       ''
''              identify a variable. NOTE: Unlike SNMP we dont require that ''
''              a scalar variable be indexed by 0                           ''
''                                                                          ''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

TYPE MIB_OPAQUE_QUERY
    dwVarId AS DWORD
    rgdwVarIndex(%ANY_SIZE-1) AS DWORD
END TYPE

''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''                                                                          ''
'' The following are the structures which are filled in and returned to the ''
'' user when a query is made, OR  are filled in BY THE USER when a set is   ''
'' done                                                                     ''
''                                                                          ''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

#INCLUDE "ipmib.inc"
#INCLUDE "tcpmib.inc"
#INCLUDE "udpmib.inc"

MACRO TCP_TABLE_CLASS_enum=LONG
ENUM TCP_TABLE_CLASS SINGULAR
    TCP_TABLE_BASIC_LISTENER
    TCP_TABLE_BASIC_CONNECTIONS
    TCP_TABLE_BASIC_ALL
    TCP_TABLE_OWNER_PID_LISTENER
    TCP_TABLE_OWNER_PID_CONNECTIONS
    TCP_TABLE_OWNER_PID_ALL
    TCP_TABLE_OWNER_MODULE_LISTENER
    TCP_TABLE_OWNER_MODULE_CONNECTIONS
    TCP_TABLE_OWNER_MODULE_ALL
END ENUM

MACRO UDP_TABLE_CLASS_enum=LONG
ENUM UDP_TABLE_CLASS SINGULAR
    UDP_TABLE_BASIC
    UDP_TABLE_OWNER_PID
    UDP_TABLE_OWNER_MODULE
END ENUM

MACRO TCPIP_OWNER_MODULE_INFO_CLASS_enum=LONG
ENUM TCPIP_OWNER_MODULE_INFO_CLASS SINGULAR
    TCPIP_OWNER_MODULE_INFO_BASIC
END ENUM

TYPE TCPIP_OWNER_MODULE_BASIC_INFO
    pModuleName AS WSTRINGZ PTR
    pModulePath AS WSTRINGZ PTR
END TYPE

TYPE MIB_IPMCAST_BOUNDARY
    dwIfIndex      AS DWORD
    dwGroupAddress AS DWORD
    dwGroupMask    AS DWORD
    dwStatus       AS DWORD
END TYPE

TYPE MIB_IPMCAST_BOUNDARY_TABLE
    dwNumEntries AS DWORD
    table(%ANY_SIZE-1) AS MIB_IPMCAST_BOUNDARY
END TYPE

'#define SIZEOF_BOUNDARY_TABLE(X) (FIELD_OFFSET(MIB_IPMCAST_BOUNDARY_TABLE,table[0]) + ((X) * sizeof(MIB_IPMCAST_BOUNDARY)) + ALIGN_SIZE)

TYPE MIB_BOUNDARYROW
    dwGroupAddress AS DWORD
    dwGroupMask    AS DWORD
END TYPE

' Structure matching what goes in the registry in a block of type
' IP_MCAST_LIMIT_INFO.  This contains the fields of
' MIB_IPMCAST_IF_ENTRY which are configurable.

TYPE MIB_MCAST_LIMIT_ROW
    dwTtl       AS DWORD
    dwRateLimit AS DWORD
END TYPE

%MAX_SCOPE_NAME_LEN = 255

'
' Scope names are unicode.  SNMP and MZAP use UTF-8 encoding.
'

%SN_UNICODE = 1
'typedef WCHAR   SN_CHAR;
'typedef SN_CHAR SCOPE_NAME_BUFFER[MAX_SCOPE_NAME_LEN+1], *SCOPE_NAME;

TYPE MIB_IPMCAST_SCOPE
    dwGroupAddress AS DWORD
    dwGroupMask    AS DWORD
    snNameBuffer   AS WSTRINGZ * %MAX_SCOPE_NAME_LEN + 1  ' SCOPE_NAME_BUFFER
    dwStatus       AS DWORD
END TYPE

TYPE MIB_IPDESTROW
    MIB_IPFORWARDROW
    dwForwardPreference AS DWORD
    dwForwardViewSet    AS DWORD
END TYPE

TYPE MIB_IPDESTTABLE
    dwNumEntries AS DWORD
    table(%ANY_SIZE-1) AS MIB_IPDESTROW
END TYPE

TYPE MIB_BEST_IF
    dwDestAddr AS DWORD
    dwIfIndex  AS DWORD
END TYPE

TYPE MIB_PROXYARP
    dwAddress AS DWORD
    dwMask    AS DWORD
    dwIfIndex AS DWORD
END TYPE

TYPE MIB_IFSTATUS
    dwIfIndex           AS DWORD
    dwAdminStatus       AS DWORD
    dwOperationalStatus AS DWORD
    bMHbeatActive       AS LONG
    bMHbeatAlive        AS LONG
END TYPE

TYPE MIB_ROUTESTATE
    bRoutesSetToStack AS LONG
END TYPE

''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''                                                                          ''
'' All the info passed to (SET/CREATE) and from (GET/GETNEXT/GETFIRST)      ''
'' IP Router Manager is encapsulated in the following "discriminated"       ''
'' union.  To pass, say MIB_IFROW, use the following code                   ''
''                                                                          ''
''  PMIB_OPAQUE_INFO    pInfo;                                              ''
''  PMIB_IFROW          pIfRow;                                             ''
''  DWORD rgdwBuff[(MAX_MIB_OFFSET + sizeof(MIB_IFROW))/sizeof(DWORD) + 1]; ''
''                                                                          ''
''  pInfo   = (PMIB_OPAQUE_INFO)rgdwBuffer;                                 ''
''  pIfRow  = (MIB_IFROW *)(pInfo->rgbyData);                               ''
''                                                                          ''
''  This can also be accomplished by using the following macro              ''
''                                                                          ''
''  DEFINE_MIB_BUFFER(pInfo,MIB_IFROW, pIfRow);                             ''
''                                                                          ''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''


UNION MIB_OPAQUE_INFO_union
    ullAlign    AS QUAD
    rgbyData(0) AS BYTE
END UNION

TYPE MIB_OPAQUE_INFO
    dwId AS DWORD
    MIB_OPAQUE_INFO_union
END TYPE

%MAX_MIB_OFFSET    = 8

MACRO MIB_INFO_SIZE(S)=(%MAX_MIB_OFFSET + SIZEOF(S))

MACRO MIB_INFO_SIZE_IN_DWORDS(S)=((MIB_INFO_SIZE(S))/SIZEOF(DWORD) + 1)

'#define DEFINE_MIB_BUFFER(X,Y,Z)                                        \
'    DWORD        __rgdwBuff[MIB_INFO_SIZE_IN_DWORDS(Y)]; \
'    PMIB_OPAQUE_INFO    X = (PMIB_OPAQUE_INFO)__rgdwBuff;               \
'    Y *                 Z = (Y *)(X->rgbyData)


'#define CAST_MIB_INFO(X,Y,Z)    Z = (Y)(X->rgbyData)
