'------------------------------------------------------------------------------
'
'  LMStats.inc -
'    This module defines the API function prototypes and data structures
'    for the following groups of NT API functions:
'        NetStatistics
'
'  Copyright (c) 2009-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from LMStats.h build version 0001 dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%LMSTATS = 1


#INCLUDE "LmCons.inc"

'
' Function Prototypes - Statistics
'

DECLARE FUNCTION NetStatisticsGet LIB "NetApi32.dll" _
    ALIAS "NetStatisticsGet" ( _
    ServerName    AS WSTRINGZ, _
    Service       AS WSTRINGZ, _
    BYVAL Level   AS DWORD, _
    BYVAL Options AS DWORD, _
    Buffer        AS ANY _  ' BYTE PTR PTR
    ) AS NET_API_STATUS

'
' Data Structures - Statistics
'

#IF %DEF(%LM20_WORKSTATION_STATISTICS)
TYPE STAT_WORKSTATION_0
     stw0_start          AS DWORD
     stw0_numNCB_r       AS DWORD
     stw0_numNCB_s       AS DWORD
     stw0_numNCB_a       AS DWORD
     stw0_fiNCB_r        AS DWORD
     stw0_fiNCB_s        AS DWORD
     stw0_fiNCB_a        AS DWORD
     stw0_fcNCB_r        AS DWORD
     stw0_fcNCB_s        AS DWORD
     stw0_fcNCB_a        AS DWORD
     stw0_sesstart       AS DWORD
     stw0_sessfailcon    AS DWORD
     stw0_sessbroke      AS DWORD
     stw0_uses           AS DWORD
     stw0_usefail        AS DWORD
     stw0_autorec        AS DWORD
     stw0_bytessent_r_lo AS DWORD
     stw0_bytessent_r_hi AS DWORD
     stw0_bytesrcvd_r_lo AS DWORD
     stw0_bytesrcvd_r_hi AS DWORD
     stw0_bytessent_s_lo AS DWORD
     stw0_bytessent_s_hi AS DWORD
     stw0_bytesrcvd_s_lo AS DWORD
     stw0_bytesrcvd_s_hi AS DWORD
     stw0_bytessent_a_lo AS DWORD
     stw0_bytessent_a_hi AS DWORD
     stw0_bytesrcvd_a_lo AS DWORD
     stw0_bytesrcvd_a_hi AS DWORD
     stw0_reqbufneed     AS DWORD
     stw0_bigbufneed     AS DWORD
END TYPE
#ELSE

'
' NB: The following structure is REDIR_STATISTICS in sdk\inc\ntddnfs.h. If you
'     change the structure, change it in both places
' [there is no such file. to be sure, Microsoft changed most of the filenames
' of the network include files.]
'

TYPE STAT_WORKSTATION_0
    StatisticsStartTime          AS QUAD  ' LARGE_INTEGER

    BytesReceived                AS QUAD  ' LARGE_INTEGER
    SmbsReceived                 AS QUAD  ' LARGE_INTEGER
    PagingReadBytesRequested     AS QUAD  ' LARGE_INTEGER
    NonPagingReadBytesRequested  AS QUAD  ' LARGE_INTEGER
    CacheReadBytesRequested      AS QUAD  ' LARGE_INTEGER
    NetworkReadBytesRequested    AS QUAD  ' LARGE_INTEGER

    BytesTransmitted             AS QUAD  ' LARGE_INTEGER
    SmbsTransmitted              AS QUAD  ' LARGE_INTEGER
    PagingWriteBytesRequested    AS QUAD  ' LARGE_INTEGER
    NonPagingWriteBytesRequested AS QUAD  ' LARGE_INTEGER
    CacheWriteBytesRequested     AS QUAD  ' LARGE_INTEGER
    NetworkWriteBytesRequested   AS QUAD  ' LARGE_INTEGER

    InitiallyFailedOperations    AS DWORD
    FailedCompletionOperations   AS DWORD

    ReadOperations               AS DWORD
    RandomReadOperations         AS DWORD
    ReadSmbs                     AS DWORD
    LargeReadSmbs                AS DWORD
    SmallReadSmbs                AS DWORD

    WriteOperations              AS DWORD
    RandomWriteOperations        AS DWORD
    WriteSmbs                    AS DWORD
    LargeWriteSmbs               AS DWORD
    SmallWriteSmbs               AS DWORD

    RawReadsDenied               AS DWORD
    RawWritesDenied              AS DWORD

    NetworkErrors                AS DWORD

    '  Connection/Session counts
    Sessions                     AS DWORD
    FailedSessions               AS DWORD
    Reconnects                   AS DWORD
    CoreConnects                 AS DWORD
    Lanman20Connects             AS DWORD
    Lanman21Connects             AS DWORD
    LanmanNtConnects             AS DWORD
    ServerDisconnects            AS DWORD
    HungSessions                 AS DWORD
    UseCount                     AS DWORD
    FailedUseCount               AS DWORD

    '
    '  Queue Lengths (updates protected by RdrMpxTableSpinLock NOT
    '  RdrStatisticsSpinlock)
    '

    CurrentCommands              AS DWORD

END TYPE
#ENDIF

TYPE STAT_SERVER_0
     sts0_start          AS DWORD
     sts0_fopens         AS DWORD
     sts0_devopens       AS DWORD
     sts0_jobsqueued     AS DWORD
     sts0_sopens         AS DWORD
     sts0_stimedout      AS DWORD
     sts0_serrorout      AS DWORD
     sts0_pwerrors       AS DWORD
     sts0_permerrors     AS DWORD
     sts0_syserrors      AS DWORD
     sts0_bytessent_low  AS DWORD
     sts0_bytessent_high AS DWORD
     sts0_bytesrcvd_low  AS DWORD
     sts0_bytesrcvd_high AS DWORD
     sts0_avresponse     AS DWORD
     sts0_reqbufneed     AS DWORD
     sts0_bigbufneed     AS DWORD
END TYPE


'
' Special Values and Constants
'

%STATSOPT_CLR   = 1
%STATS_NO_VALUE = &HFFFFFFFF???  ' ((unsigned long) -1L)
%STATS_OVERFLOW = &HFFFFFFFE???  ' ((unsigned long) -2L)
