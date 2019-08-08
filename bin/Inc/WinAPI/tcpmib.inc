'------------------------------------------------------------------------------
'
'  TcpMib.inc
'    This module contains the public definitions and structures for the
'    TCP-specific parts of MIB-II.  These definitions were previously
'    in iprtrmib.h, which now #includes this file.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from TcpMib.h build version 0001 of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%TCPMIB = 1

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "WinDef.inc"

#IF NOT %DEF(%ANY_SIZE)
%ANY_SIZE = 1
#ENDIF

%TCPIP_OWNING_MODULE_SIZE = 16

'
' TCP states, as defined in the MIB.
'
MACRO MIB_TCP_STATE_enum=LONG
ENUM MIB_TCP_STATE SINGULAR
    MIB_TCP_STATE_CLOSED  = 1
    MIB_TCP_STATE_LISTEN
    MIB_TCP_STATE_SYN_SENT
    MIB_TCP_STATE_SYN_RCVD
    MIB_TCP_STATE_ESTAB
    MIB_TCP_STATE_FIN_WAIT1
    MIB_TCP_STATE_FIN_WAIT2
    MIB_TCP_STATE_CLOSE_WAIT
    MIB_TCP_STATE_CLOSING
    MIB_TCP_STATE_LAST_ACK
    MIB_TCP_STATE_TIME_WAIT
    MIB_TCP_STATE_DELETE_TCB
END ENUM


'
' Various Offload states a TCP connection can be in.
'
MACRO TCP_CONNECTION_OFFLOAD_STATE_enum=LONG
ENUM TCP_CONNECTION_OFFLOAD_STATE SINGULAR
    TcpConnectionOffloadStateInHost
    TcpConnectionOffloadStateOffloading
    TcpConnectionOffloadStateOffloaded
    TcpConnectionOffloadStateUploading
    TcpConnectionOffloadStateMax
END ENUM

UNION MIB_TCPROW_LH_union
    dwState AS DWORD               ' Old field used DWORD type.
    STATE   AS MIB_TCP_STATE_enum  ' New field uses enum type.
END UNION

TYPE MIB_TCPROW_LH
    MIB_TCPROW_LH_union
    dwLocalAddr  AS DWORD
    dwLocalPort  AS DWORD
    dwRemoteAddr AS DWORD
    dwRemotePort AS DWORD
END TYPE

TYPE MIB_TCPROW_W2K
    dwState      AS DWORD
    dwLocalAddr  AS DWORD
    dwLocalPort  AS DWORD
    dwRemoteAddr AS DWORD
    dwRemotePort AS DWORD
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
MACRO MIB_TCPROW = MIB_TCPROW_LH
#ELSEIF (%NTDDI_VERSION >= %NTDDI_WIN2K)
MACRO MIB_TCPROW = MIB_TCPROW_W2K
#ELSE
MACRO MIB_TCPROW = MIB_TCPROW_LH
#ENDIF

TYPE MIB_TCPTABLE
    dwNumEntries       AS DWORD
    table(%ANY_SIZE-1) AS MIB_TCPROW
END TYPE

'#define SIZEOF_TCPTABLE(X) (FIELD_OFFSET(MIB_TCPTABLE,table[0]) + \
'                            ((X) * sizeof(MIB_TCPROW)) + ALIGN_SIZE)

TYPE MIB_TCPROW2
    dwState        AS DWORD
    dwLocalAddr    AS DWORD
    dwLocalPort    AS DWORD
    dwRemoteAddr   AS DWORD
    dwRemotePort   AS DWORD
    dwOwningPid    AS DWORD
    dwOffloadState AS TCP_CONNECTION_OFFLOAD_STATE_enum
END TYPE

TYPE MIB_TCPTABLE2
    dwNumEntries       AS DWORD
    table(%ANY_SIZE-1) AS MIB_TCPROW2
END TYPE

'#define SIZEOF_TCPTABLE2(X) (FIELD_OFFSET(MIB_TCPTABLE2,table[0]) + \
'                            ((X) * sizeof(MIB_TCPROW2)) + ALIGN_SIZE)

TYPE MIB_TCPROW_OWNER_PID
    dwState      AS DWORD
    dwLocalAddr  AS DWORD
    dwLocalPort  AS DWORD
    dwRemoteAddr AS DWORD
    dwRemotePort AS DWORD
    dwOwningPid  AS DWORD
END TYPE

TYPE MIB_TCPTABLE_OWNER_PID
    dwNumEntries       AS DWORD
    table(%ANY_SIZE-1) AS MIB_TCPROW_OWNER_PID
END TYPE

'#define SIZEOF_TCPTABLE_OWNER_PID(X) (FIELD_OFFSET(MIB_TCPTABLE_OWNER_PID, table[0]) + \
'                                      ((X) * sizeof(MIB_TCPROW_OWNER_PID)) + ALIGN_SIZE)


TYPE MIB_TCPROW_OWNER_MODULE
    dwState           AS DWORD
    dwLocalAddr       AS DWORD
    dwLocalPort       AS DWORD
    dwRemoteAddr      AS DWORD
    dwRemotePort      AS DWORD
    dwOwningPid       AS DWORD
    liCreateTimestamp AS QUAD  ' LARGE_INTEGER
    OwningModuleInfo(%TCPIP_OWNING_MODULE_SIZE-1) AS QUAD  ' ULONGLONG
END TYPE


TYPE MIB_TCPTABLE_OWNER_MODULE
    dwNumEntries       AS DWORD
    table(%ANY_SIZE-1) AS MIB_TCPROW_OWNER_MODULE
END TYPE

'#define SIZEOF_TCPTABLE_OWNER_MODULE(X) (FIELD_OFFSET(MIB_TCPTABLE_OWNER_MODULE, table[0]) + \
'                                         ((X) * sizeof(MIB_TCPROW_OWNER_MODULE)) + ALIGN_SIZE)


#IF %DEF(%WS2IPDEF)
'
' The following definitions require Winsock2.
'

TYPE MIB_TCP6ROW
    STATE           AS MIB_TCP_STATE_enum
    LocalAddr       AS IN6_ADDR
    dwLocalScopeId  AS DWORD
    dwLocalPort     AS DWORD
    RemoteAddr      AS IN6_ADDR
    dwRemoteScopeId AS DWORD
    dwRemotePort    AS DWORD
END TYPE

TYPE MIB_TCP6TABLE
    dwNumEntries       AS DWORD
    table(%ANY_SIZE-1) AS MIB_TCP6ROW
END TYPE

'#define SIZEOF_TCP6TABLE(X) (FIELD_OFFSET(MIB_TCP6TABLE,table[0]) + \
'                             ((X) * sizeof(MIB_TCP6ROW)) + ALIGN_SIZE)

TYPE MIB_TCP6ROW2
    LocalAddr       AS IN6_ADDR
    dwLocalScopeId  AS DWORD
    dwLocalPort     AS DWORD
    RemoteAddr      AS IN6_ADDR
    dwRemoteScopeId AS DWORD
    dwRemotePort    AS DWORD
    STATE           AS MIB_TCP_STATE_enum
    dwOwningPid     AS DWORD
    dwOffloadState  AS TCP_CONNECTION_OFFLOAD_STATE_enum
END TYPE

TYPE MIB_TCP6TABLE2
    dwNumEntries       AS DWORD
    table(%ANY_SIZE-1) AS MIB_TCP6ROW2
END TYPE

'#define SIZEOF_TCP6TABLE2(X) (FIELD_OFFSET(MIB_TCP6TABLE2,table[0]) + \
'                              ((X) * sizeof(MIB_TCP6ROW2)) + ALIGN_SIZE)


TYPE MIB_TCP6ROW_OWNER_PID
    ucLocalAddr(15)  AS BYTE
    dwLocalScopeId   AS DWORD
    dwLocalPort      AS DWORD
    ucRemoteAddr(15) AS BYTE
    dwRemoteScopeId  AS DWORD
    dwRemotePort     AS DWORD
    dwState          AS DWORD
    dwOwningPid      AS DWORD
END TYPE

TYPE MIB_TCP6TABLE_OWNER_PID
    dwNumEntries       AS DWORD
    table(%ANY_SIZE-1) AS MIB_TCP6ROW_OWNER_PID
END TYPE

'#define SIZEOF_TCP6TABLE_OWNER_PID(X) (FIELD_OFFSET(MIB_TCP6TABLE_OWNER_PID, table[0]) + \
'                                       ((X) * sizeof(MIB_TCP6ROW_OWNER_PID)) + ALIGN_SIZE)

TYPE MIB_TCP6ROW_OWNER_MODULE
    ucLocalAddr(15)   AS BYTE
    dwLocalScopeId    AS DWORD
    dwLocalPort       AS DWORD
    ucRemoteAddr(15)  AS BYTE
    dwRemoteScopeId   AS DWORD
    dwRemotePort      AS DWORD
    dwState           AS DWORD
    dwOwningPid       AS DWORD
    liCreateTimestamp AS QUAD  ' LARGE_INTEGER
    OwningModuleInfo(%TCPIP_OWNING_MODULE_SIZE-1) AS QUAD  ' ULONGLONG
END TYPE

TYPE MIB_TCP6TABLE_OWNER_MODULE
    dwNumEntries       AS DWORD
    table(%ANY_SIZE-1) AS MIB_TCP6ROW_OWNER_MODULE
END TYPE

'#define SIZEOF_TCP6TABLE_OWNER_MODULE(X) (FIELD_OFFSET(MIB_TCP6TABLE_OWNER_MODULE, table[0]) + \
'                                          ((X) * sizeof(MIB_TCP6ROW_OWNER_MODULE)) + ALIGN_SIZE)

#ENDIF ' %WS2IPDEF

%MIB_TCP_MAXCONN_DYNAMIC = &HFFFFFFFF???  ' ((ULONG)-1)

'
' The algorithm used to determine the timeout value used for retransmitting
' unacknowledged octets.
'
' REVIEW: This enum adds another version of the defines that already
' exist in iprtrmib.h (MIB_TCP_RTO_*).  Shouldn't we just use the
' public names that already exist?
'
MACRO TCP_RTO_ALGORITHM_enum=LONG
ENUM TCP_RTO_ALGORITHM SINGULAR
    TcpRtoAlgorithmOther
    TcpRtoAlgorithmConstant
    TcpRtoAlgorithmRsre
    TcpRtoAlgorithmVanj

    MIB_TCP_RTO_OTHER    = 1
    MIB_TCP_RTO_CONSTANT
    MIB_TCP_RTO_RSRE
    MIB_TCP_RTO_VANJ
END ENUM

UNION MIB_TCPSTATS_LH_union
    dwRtoAlgorithm AS DWORD
    RtoAlgorithm   AS TCP_RTO_ALGORITHM_enum
END UNION

TYPE MIB_TCPSTATS_LH
    MIB_TCPSTATS_LH_union
    dwRtoMin       AS DWORD
    dwRtoMax       AS DWORD
    dwMaxConn      AS DWORD
    dwActiveOpens  AS DWORD
    dwPassiveOpens AS DWORD
    dwAttemptFails AS DWORD
    dwEstabResets  AS DWORD
    dwCurrEstab    AS DWORD
    dwInSegs       AS DWORD
    dwOutSegs      AS DWORD
    dwRetransSegs  AS DWORD
    dwInErrs       AS DWORD
    dwOutRsts      AS DWORD
    dwNumConns     AS DWORD
END TYPE

TYPE MIB_TCPSTATS_W2K
    dwRtoAlgorithm AS DWORD
    dwRtoMin       AS DWORD
    dwRtoMax       AS DWORD
    dwMaxConn      AS DWORD
    dwActiveOpens  AS DWORD
    dwPassiveOpens AS DWORD
    dwAttemptFails AS DWORD
    dwEstabResets  AS DWORD
    dwCurrEstab    AS DWORD
    dwInSegs       AS DWORD
    dwOutSegs      AS DWORD
    dwRetransSegs  AS DWORD
    dwInErrs       AS DWORD
    dwOutRsts      AS DWORD
    dwNumConns     AS DWORD
END TYPE


#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
MACRO MIB_TCPSTATS = MIB_TCPSTATS_LH
#ELSEIF (%NTDDI_VERSION >= %NTDDI_WIN2K)
MACRO MIB_TCPSTATS = MIB_TCPSTATS_W2K
#ENDIF
