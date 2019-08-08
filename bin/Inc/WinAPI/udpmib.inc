'------------------------------------------------------------------------------
'
'  UdpMib.inc
'    This module contains the public definitions and structures for the
'    UDP-specific parts of MIB-II.  These definitions were previously
'    in iprtrmib.h, which now #includes this file.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from UdpMib.h build version 0001 of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%UDPMIB = 1

#IF NOT %DEF(%ANY_SIZE)
%ANY_SIZE = 1
#ENDIF

%TCPIP_OWNING_MODULE_SIZE = 16

TYPE MIB_UDPROW
    dwLocalAddr AS DWORD
    dwLocalPort AS DWORD
END TYPE

TYPE MIB_UDPTABLE
    dwNumEntries       AS DWORD
    table(%ANY_SIZE-1) AS MIB_UDPROW
END TYPE

'#define SIZEOF_UDPTABLE(X) (FIELD_OFFSET(MIB_UDPTABLE, table[0]) + \
'                            ((X) * sizeof(MIB_UDPROW)) + ALIGN_SIZE)

TYPE MIB_UDPROW_OWNER_PID
    dwLocalAddr AS DWORD
    dwLocalPort AS DWORD
    dwOwningPid AS DWORD
END TYPE

TYPE MIB_UDPTABLE_OWNER_PID
    dwNumEntries AS DWORD
    table(%ANY_SIZE-1) AS MIB_UDPROW_OWNER_PID
END TYPE

'#define SIZEOF_UDPTABLE_OWNER_PID(X) (FIELD_OFFSET(MIB_UDPTABLE_OWNER_PID, table[0]) + \
'                                      ((X) * sizeof(MIB_UDPROW_OWNER_PID)) + ALIGN_SIZE)

UNION MIB_UDPROW_OWNER_MODULE_union
    SpecificPortBind AS BIT * 1 IN DWORD
    dwFlags          AS LONG
END UNION

TYPE MIB_UDPROW_OWNER_MODULE
    dwLocalAddr       AS DWORD
    dwLocalPort       AS DWORD
    dwOwningPid       AS DWORD
    liCreateTimestamp AS QUAD  ' LARGE_INTEGER
    MIB_UDPROW_OWNER_MODULE_union
    OwningModuleInfo(%TCPIP_OWNING_MODULE_SIZE-1) AS QUAD  ' ULONGLONG
END TYPE

TYPE MIB_UDPTABLE_OWNER_MODULE
    dwNumEntries       AS DWORD
    table(%ANY_SIZE-1) AS MIB_UDPROW_OWNER_MODULE
END TYPE

'#define SIZEOF_UDPTABLE_OWNER_MODULE(X) (FIELD_OFFSET(MIB_UDPTABLE_OWNER_MODULE, table[0]) + \
'                                         ((X) * sizeof(MIB_UDPROW_OWNER_MODULE)) + ALIGN_SIZE)

#IF %DEF(%WS2IPDEF)
'
' The following definitions require Winsock2.
'

TYPE MIB_UDP6ROW
    dwLocalAddr    AS IN6_ADDR
    dwLocalScopeId AS DWORD
    dwLocalPort    AS DWORD
END TYPE

TYPE MIB_UDP6TABLE
    dwNumEntries       AS DWORD
    table(%ANY_SIZE-1) AS MIB_UDP6ROW
END TYPE

'#define SIZEOF_UDP6TABLE(X) (FIELD_OFFSET(MIB_UDP6TABLE, table[0]) + \
'                             ((X) * sizeof(MIB_UDP6ROW)) + ALIGN_SIZE)

TYPE MIB_UDP6ROW_OWNER_PID
    ucLocalAddr(15) AS BYTE
    dwLocalScopeId  AS DWORD
    dwLocalPort     AS DWORD
    dwOwningPid     AS DWORD
END TYPE

TYPE MIB_UDP6TABLE_OWNER_PID
    dwNumEntries       AS DWORD
    table(%ANY_SIZE-1) AS MIB_UDP6ROW_OWNER_PID
END TYPE

'#define SIZEOF_UDP6TABLE_OWNER_PID(X) (FIELD_OFFSET(MIB_UDP6TABLE_OWNER_PID, table[0]) + \
'                                       ((X) * sizeof(MIB_UDP6ROW_OWNER_PID)) + ALIGN_SIZE)

UNION MIB_UDP6ROW_OWNER_MODULE_union
    SpecificPortBind AS BIT * 1 IN DWORD
    dwFlags          AS LONG
END UNION

TYPE MIB_UDP6ROW_OWNER_MODULE
    ucLocalAddr(15)   AS BYTE
    dwLocalScopeId    AS DWORD
    dwLocalPort       AS DWORD
    dwOwningPid       AS DWORD
    liCreateTimestamp AS QUAD  ' LARGE_INTEGER
    MIB_UDP6ROW_OWNER_MODULE_union
    OwningModuleInfo(%TCPIP_OWNING_MODULE_SIZE-1) AS QUAD  ' ULONGLONG
END TYPE

TYPE MIB_UDP6TABLE_OWNER_MODULE
    dwNumEntries       AS DWORD
    table(%ANY_SIZE-1) AS MIB_UDP6ROW_OWNER_MODULE
END TYPE

'#define SIZEOF_UDP6TABLE_OWNER_MODULE(X) (FIELD_OFFSET(MIB_UDP6TABLE_OWNER_MODULE, table[0]) + \
'                                          ((X) * sizeof(MIB_UDP6ROW_OWNER_MODULE)) + ALIGN_SIZE)

#ENDIF ' %WS2IPDEF

TYPE MIB_UDPSTATS
    dwInDatagrams  AS DWORD
    dwNoPorts      AS DWORD
    dwInErrors     AS DWORD
    dwOutDatagrams AS DWORD
    dwNumAddrs     AS DWORD
END TYPE
