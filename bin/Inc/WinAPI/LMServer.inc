'------------------------------------------------------------------------------
'
'  LMServer.inc -- This file contains information about NetServer APIs.
'
'  Copyright (c) 2009-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from LMServer.h build version 0007 dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%LMSERVER = 1

#INCLUDE "LmCons.inc"
#INCLUDE "WinSvc.inc"   ' SERVICE_STATUS_HANDLE

'
' Function Prototypes - SERVER
'

DECLARE FUNCTION NetServerEnum LIB "NetApi32.dll" ALIAS "NetServerEnum" ( _
    servername       AS LMCSTR, _
    BYVAL level      AS DWORD, _
    bufptr           AS ANY, _  ' BYTE PTR PTR
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    BYVAL servertype AS DWORD, _
    domain           AS LMCSTR, _
    resume_handle    AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetServerEnumEx LIB "NetApi32.dll" ALIAS "NetServerEnumEx" ( _
    ServerName        AS LMCSTR, _
    BYVAL Level       AS DWORD, _
    Bufptr            AS ANY, _  ' BYTE PTR PTR
    BYVAL PrefMaxlen  AS DWORD, _
    EntriesRead       AS DWORD, _
    totalentries      AS DWORD, _
    BYVAL servertype  AS DWORD, _
    domain            AS LMCSTR, _
    FirstNameToReturn AS LMCSTR _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetServerGetInfo LIB "NetApi32.dll" _
    ALIAS "NetServerGetInfo" ( _
    servername  AS LMSTR, _
    BYVAL level AS DWORD, _
    bufptr      AS ANY _  ' BYTE PTR PTR
    ) AS NET_API_STATUS

DECLARE FUNCTION NetServerSetInfo LIB "NetApi32.dll" _
    ALIAS "NetServerSetInfo" ( _
    servername  AS LMSTR, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    ParmError   AS DWORD _
    ) AS NET_API_STATUS

'
' Temporary hack function.
'

DECLARE FUNCTION NetServerSetInfoCommandLine LIB "NetApi32.dll" _
    ALIAS "NetServerSetInfoCommandLine" ( _
    BYVAL argc AS WORD, _
    argv       AS ANY _  ' array of LMSTR
    ) AS NET_API_STATUS

DECLARE FUNCTION NetServerDiskEnum LIB "NetApi32.dll" _
    ALIAS "NetServerDiskEnum" ( _
    servername       AS LMSTR, _
    BYVAL level      AS DWORD, _
    bufptr           AS ANY, _  ' BYTE PTR PTR
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resume_handle    AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetServerComputerNameAd LIB "NetApi32.dll" _
    ALIAS "NetServerComputerNameAd" ( _
    ServerName         AS LMSTR, _
    EmulatedDomainName AS LMSTR, _
    EmulatedServerName AS LMSTR _
) AS NET_API_STATUS

DECLARE FUNCTION NetServerComputerNameDel LIB "NetApi32.dll" _
    ALIAS "NetServerComputerNameDel" ( _
    ServerName         AS LMSTR, _
    EmulatedServerName AS LMSTR _
) AS NET_API_STATUS

DECLARE FUNCTION NetServerTransportAdd LIB "NetApi32.dll" _
    ALIAS "NetServerTransportAdd" ( _
    servername   AS LMSTR, _
    BYVAL level  AS DWORD, _
    BYVAL bufptr AS BYTE PTR _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetServerTransportAddEx LIB "NetApi32.dll" _
    ALIAS "NetServerTransportAddEx" ( _
    servername   AS LMSTR, _
    BYVAL level  AS DWORD, _
    BYVAL bufptr AS BYTE PTR _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetServerTransportDel LIB "NetApi32.dll" _
    ALIAS "NetServerTransportDel" ( _
    servername   AS LMSTR, _
    BYVAL level  AS DWORD, _
    BYVAL bufptr AS BYTE PTR _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetServerTransportEnum LIB "NetApi32.dll" _
    ALIAS "NetServerTransportEnum" ( _
    servername       AS LMSTR, _
    BYVAL level      AS DWORD, _
    bufptr           AS ANY, _  ' BYTE PTR PTR
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resumehandle     AS DWORD _
    ) AS NET_API_STATUS

'
' The following function can be called by Win NT services to register
' their service type.  This function is exported from advapi32.dll.
' Therefore, if this is the only function called by that service, then
' it is not necessary to link to netapi32.lib.
'
DECLARE FUNCTION SetServiceBits LIB "AdvApi32.dll" ALIAS "SetServiceBits" ( _
    BYVAL hServiceStatus     AS DWORD, _  ' SERVICE_STATUS_HANDLE
    BYVAL dwServiceBits      AS DWORD, _
    BYVAL bSetBitsOn         AS LONG, _  ' BOOL
    BYVAL bUpdateImmediately AS LONG _   ' BOOL
    ) AS LONG  ' BOOL

'
' Data Structures - SERVER
'

TYPE SERVER_INFO_100
    sv100_platform_id AS DWORD
    sv100_name        AS LMSTR PTR
END TYPE

TYPE SERVER_INFO_101
    sv101_platform_id   AS DWORD
    sv101_name          AS LMSTR PTR
    sv101_version_major AS DWORD
    sv101_version_minor AS DWORD
    sv101_type          AS DWORD
    sv101_comment       AS LMSTR PTR
END TYPE

TYPE SERVER_INFO_102
     sv102_platform_id   AS DWORD
     sv102_name          AS LMSTR PTR
     sv102_version_major AS DWORD
     sv102_version_minor AS DWORD
     sv102_type          AS DWORD
     sv102_comment       AS LMSTR PTR
     sv102_users         AS DWORD
     sv102_disc          AS LONG
     sv102_hidden        AS LONG  ' BOOL
     sv102_announce      AS DWORD
     sv102_anndelta      AS DWORD
     sv102_licenses      AS DWORD
     sv102_userpath      AS LMSTR PTR
END TYPE

TYPE SERVER_INFO_103
     sv103_platform_id   AS DWORD
     sv103_name          AS LMSTR PTR
     sv103_version_major AS DWORD
     sv103_version_minor AS DWORD
     sv103_type          AS DWORD
     sv103_comment       AS LMSTR PTR
     sv103_users         AS DWORD
     sv103_disc          AS LONG
     sv103_hidden        AS LONG  ' BOOL
     sv103_announce      AS DWORD
     sv103_anndelta      AS DWORD
     sv103_licenses      AS DWORD
     sv103_userpath      AS LMSTR PTR
     sv103_capabilities  AS DWORD
END TYPE

TYPE SERVER_INFO_402
     sv402_ulist_mtime   AS DWORD
     sv402_glist_mtime   AS DWORD
     sv402_alist_mtime   AS DWORD
     sv402_alerts        AS LMSTR PTR
     sv402_security      AS DWORD
     sv402_numadmin      AS DWORD
     sv402_lanmask       AS DWORD
     sv402_guestacct     AS LMSTR PTR
     sv402_chdevs        AS DWORD
     sv402_chdevq        AS DWORD
     sv402_chdevjobs     AS DWORD
     sv402_connections   AS DWORD
     sv402_shares        AS DWORD
     sv402_openfiles     AS DWORD
     sv402_sessopens     AS DWORD
     sv402_sessvcs       AS DWORD
     sv402_sessreqs      AS DWORD
     sv402_opensearch    AS DWORD
     sv402_activelocks   AS DWORD
     sv402_numreqbuf     AS DWORD
     sv402_sizreqbuf     AS DWORD
     sv402_numbigbuf     AS DWORD
     sv402_numfiletasks  AS DWORD
     sv402_alertsched    AS DWORD
     sv402_erroralert    AS DWORD
     sv402_logonalert    AS DWORD
     sv402_accessalert   AS DWORD
     sv402_diskalert     AS DWORD
     sv402_netioalert    AS DWORD
     sv402_maxauditsz    AS DWORD
     sv402_srvheuristics AS LMSTR PTR
END TYPE

TYPE SERVER_INFO_403
     sv403_ulist_mtime   AS DWORD
     sv403_glist_mtime   AS DWORD
     sv403_alist_mtime   AS DWORD
     sv403_alerts        AS LMSTR PTR
     sv403_security      AS DWORD
     sv403_numadmin      AS DWORD
     sv403_lanmask       AS DWORD
     sv403_guestacct     AS LMSTR PTR
     sv403_chdevs        AS DWORD
     sv403_chdevq        AS DWORD
     sv403_chdevjobs     AS DWORD
     sv403_connections   AS DWORD
     sv403_shares        AS DWORD
     sv403_openfiles     AS DWORD
     sv403_sessopens     AS DWORD
     sv403_sessvcs       AS DWORD
     sv403_sessreqs      AS DWORD
     sv403_opensearch    AS DWORD
     sv403_activelocks   AS DWORD
     sv403_numreqbuf     AS DWORD
     sv403_sizreqbuf     AS DWORD
     sv403_numbigbuf     AS DWORD
     sv403_numfiletasks  AS DWORD
     sv403_alertsched    AS DWORD
     sv403_erroralert    AS DWORD
     sv403_logonalert    AS DWORD
     sv403_accessalert   AS DWORD
     sv403_diskalert     AS DWORD
     sv403_netioalert    AS DWORD
     sv403_maxauditsz    AS DWORD
     sv403_srvheuristics AS LMSTR PTR
     sv403_auditedevents AS DWORD
     sv403_autoprofile   AS DWORD
     sv403_autopath      AS LMSTR PTR
END TYPE

TYPE SERVER_INFO_502
    sv502_sessopens              AS DWORD
    sv502_sessvcs                AS DWORD
    sv502_opensearch             AS DWORD
    sv502_sizreqbuf              AS DWORD
    sv502_initworkitems          AS DWORD
    sv502_maxworkitems           AS DWORD
    sv502_rawworkitems           AS DWORD
    sv502_irpstacksize           AS DWORD
    sv502_maxrawbuflen           AS DWORD
    sv502_sessusers              AS DWORD
    sv502_sessconns              AS DWORD
    sv502_maxpagedmemoryusage    AS DWORD
    sv502_maxnonpagedmemoryusage AS DWORD
    sv502_enablesoftcompat       AS LONG  ' BOOL
    sv502_enableforcedlogoff     AS LONG  ' BOOL
    sv502_timesource             AS LONG  ' BOOL
    sv502_acceptdownlevelapis    AS LONG  ' BOOL
    sv502_lmannounce             AS LONG  ' BOOL
END TYPE

TYPE SERVER_INFO_503
    sv503_sessopens               AS DWORD
    sv503_sessvcs                 AS DWORD
    sv503_opensearch              AS DWORD
    sv503_sizreqbuf               AS DWORD
    sv503_initworkitems           AS DWORD
    sv503_maxworkitems            AS DWORD
    sv503_rawworkitems            AS DWORD
    sv503_irpstacksize            AS DWORD
    sv503_maxrawbuflen            AS DWORD
    sv503_sessusers               AS DWORD
    sv503_sessconns               AS DWORD
    sv503_maxpagedmemoryusage     AS DWORD
    sv503_maxnonpagedmemoryusage  AS DWORD
    sv503_enablesoftcompat        AS LONG  ' BOOL
    sv503_enableforcedlogoff      AS LONG  ' BOOL
    sv503_timesource              AS LONG  ' BOOL
    sv503_acceptdownlevelapis     AS LONG  ' BOOL
    sv503_lmannounce              AS LONG  ' BOOL
    sv503_domain                  AS LMSTR PTR
    sv503_maxcopyreadlen          AS DWORD
    sv503_maxcopywritelen         AS DWORD
    sv503_minkeepsearch           AS DWORD
    sv503_maxkeepsearch           AS DWORD
    sv503_minkeepcomplsearch      AS DWORD
    sv503_maxkeepcomplsearch      AS DWORD
    sv503_threadcountadd          AS DWORD
    sv503_numblockthreads         AS DWORD
    sv503_scavtimeout             AS DWORD
    sv503_minrcvqueue             AS DWORD
    sv503_minfreeworkitems        AS DWORD
    sv503_xactmemsize             AS DWORD
    sv503_threadpriority          AS DWORD
    sv503_maxmpxct                AS DWORD
    sv503_oplockbreakwait         AS DWORD
    sv503_oplockbreakresponsewait AS DWORD
    sv503_enableoplocks           AS LONG  ' BOOL
    sv503_enableoplockforceclose  AS LONG  ' BOOL
    sv503_enablefcbopens          AS LONG  ' BOOL
    sv503_enableraw               AS LONG  ' BOOL
    sv503_enablesharednetdrives   AS LONG  ' BOOL
    sv503_minfreeconnections      AS DWORD
    sv503_maxfreeconnections      AS DWORD
END TYPE

TYPE SERVER_INFO_599
    sv599_sessopens               AS DWORD
    sv599_sessvcs                 AS DWORD
    sv599_opensearch              AS DWORD
    sv599_sizreqbuf               AS DWORD
    sv599_initworkitems           AS DWORD
    sv599_maxworkitems            AS DWORD
    sv599_rawworkitems            AS DWORD
    sv599_irpstacksize            AS DWORD
    sv599_maxrawbuflen            AS DWORD
    sv599_sessusers               AS DWORD
    sv599_sessconns               AS DWORD
    sv599_maxpagedmemoryusage     AS DWORD
    sv599_maxnonpagedmemoryusage  AS DWORD
    sv599_enablesoftcompat        AS LONG  ' BOOL
    sv599_enableforcedlogoff      AS LONG  ' BOOL
    sv599_timesource              AS LONG  ' BOOL
    sv599_acceptdownlevelapis     AS LONG  ' BOOL
    sv599_lmannounce              AS LONG  ' BOOL
    sv599_domain                  AS LMSTR PTR
    sv599_maxcopyreadlen          AS DWORD
    sv599_maxcopywritelen         AS DWORD
    sv599_minkeepsearch           AS DWORD
    sv599_maxkeepsearch           AS DWORD
    sv599_minkeepcomplsearch      AS DWORD
    sv599_maxkeepcomplsearch      AS DWORD
    sv599_threadcountadd          AS DWORD
    sv599_numblockthreads         AS DWORD
    sv599_scavtimeout             AS DWORD
    sv599_minrcvqueue             AS DWORD
    sv599_minfreeworkitems        AS DWORD
    sv599_xactmemsize             AS DWORD
    sv599_threadpriority          AS DWORD
    sv599_maxmpxct                AS DWORD
    sv599_oplockbreakwait         AS DWORD
    sv599_oplockbreakresponsewait AS DWORD
    sv599_enableoplocks           AS LONG  ' BOOL
    sv599_enableoplockforceclose  AS LONG  ' BOOL
    sv599_enablefcbopens          AS LONG  ' BOOL
    sv599_enableraw               AS LONG  ' BOOL
    sv599_enablesharednetdrives   AS LONG  ' BOOL
    sv599_minfreeconnections      AS DWORD
    sv599_maxfreeconnections      AS DWORD
    sv599_initsesstable           AS DWORD
    sv599_initconntable           AS DWORD
    sv599_initfiletable           AS DWORD
    sv599_initsearchtable         AS DWORD
    sv599_alertschedule           AS DWORD
    sv599_errorthreshold          AS DWORD
    sv599_networkerrorthreshold   AS DWORD
    sv599_diskspacethreshold      AS DWORD
    sv599_reserved                AS DWORD
    sv599_maxlinkdelay            AS DWORD
    sv599_minlinkthroughput       AS DWORD
    sv599_linkinfovalidtime       AS DWORD
    sv599_scavqosinfoupdatetime   AS DWORD
    sv599_maxworkitemidletime     AS DWORD
END TYPE

TYPE SERVER_INFO_598
    sv598_maxrawworkitems         AS DWORD
    sv598_maxthreadsperqueue      AS DWORD
    sv598_producttype             AS DWORD
    sv598_serversize              AS DWORD
    sv598_connectionlessautodisc  AS DWORD
    sv598_sharingviolationretries AS DWORD
    sv598_sharingviolationdelay   AS DWORD
    sv598_maxglobalopensearch     AS DWORD
    sv598_removeduplicatesearches AS DWORD
    sv598_lockviolationoffset     AS DWORD
    sv598_lockviolationdelay      AS DWORD
    sv598_mdlreadswitchover       AS DWORD
    sv598_cachedopenlimit         AS DWORD
    sv598_otherqueueaffinity      AS DWORD
    sv598_restrictnullsessaccess  AS LONG  ' BOOL
    sv598_enablewfw311directipx   AS LONG  ' BOOL
    sv598_queuesamplesecs         AS DWORD
    sv598_balancecount            AS DWORD
    sv598_preferredaffinity       AS DWORD
    sv598_maxfreerfcbs            AS DWORD
    sv598_maxfreemfcbs            AS DWORD
    sv598_maxfreelfcbs            AS DWORD
    sv598_maxfreepagedpoolchunks  AS DWORD
    sv598_minpagedpoolchunksize   AS DWORD
    sv598_maxpagedpoolchunksize   AS DWORD
    sv598_sendsfrompreferredprocessor AS LONG  ' BOOL
    sv598_cacheddirectorylimit        AS DWORD
    sv598_maxcopylength               AS DWORD
    sv598_enablecompression           AS LONG  ' BOOL
    sv598_autosharewks                AS LONG  ' BOOL
    sv598_autoshareserver             AS LONG  ' BOOL
    sv598_enablesecuritysignature     AS LONG  ' BOOL
    sv598_requiresecuritysignature    AS LONG  ' BOOL
    sv598_minclientbuffersize         AS DWORD
    sv598_serverguid                  AS GUID
    sv598_ConnectionNoSessionsTimeout AS DWORD
    sv598_IdleThreadTimeOut           AS DWORD
    sv598_enableW9xsecuritysignature  AS LONG  ' BOOL
    sv598_enforcekerberosreauthentication AS LONG  ' BOOL
    sv598_disabledos                  AS LONG    ' BOOL
    sv598_lowdiskspaceminimum         AS DWORD
    sv598_disablestrictnamechecking   AS LONG    ' BOOL
    sv598_enableauthenticateusersharing AS LONG  ' BOOL
END TYPE

TYPE SERVER_INFO_1005
    sv1005_comment AS LMSTR PTR
END TYPE

TYPE SERVER_INFO_1107
    sv1107_users AS DWORD
END TYPE

TYPE SERVER_INFO_1010
    sv1010_disc AS LONG
END TYPE

TYPE SERVER_INFO_1016
    sv1016_hidden AS LONG  ' BOOL
END TYPE

TYPE SERVER_INFO_1017
    sv1017_announce AS DWORD
END TYPE

TYPE SERVER_INFO_1018
    sv1018_anndelta AS DWORD
END TYPE

TYPE SERVER_INFO_1501
    sv1501_sessopens AS DWORD
END TYPE

TYPE SERVER_INFO_1502
    sv1502_sessvcs AS DWORD
END TYPE

TYPE SERVER_INFO_1503
    sv1503_opensearch AS DWORD
END TYPE

TYPE SERVER_INFO_1506
    sv1506_maxworkitems AS DWORD
END TYPE

TYPE SERVER_INFO_1509
    sv1509_maxrawbuflen AS DWORD
END TYPE

TYPE SERVER_INFO_1510
    sv1510_sessusers AS DWORD
END TYPE

TYPE SERVER_INFO_1511
    sv1511_sessconns AS DWORD
END TYPE

TYPE SERVER_INFO_1512
    sv1512_maxnonpagedmemoryusage AS DWORD
END TYPE

TYPE SERVER_INFO_1513
    sv1513_maxpagedmemoryusage AS DWORD
END TYPE

TYPE SERVER_INFO_1514
    sv1514_enablesoftcompat AS LONG  ' BOOL
END TYPE

TYPE SERVER_INFO_1515
    sv1515_enableforcedlogoff AS LONG  ' BOOL
END TYPE

TYPE SERVER_INFO_1516
    sv1516_timesource AS LONG  ' BOOL
END TYPE

TYPE SERVER_INFO_1518
    sv1518_lmannounce AS LONG  ' BOOL
END TYPE

TYPE SERVER_INFO_1520
    sv1520_maxcopyreadlen AS DWORD
END TYPE

TYPE SERVER_INFO_1521
    sv1521_maxcopywritelen AS DWORD
END TYPE

TYPE SERVER_INFO_1522
    sv1522_minkeepsearch AS DWORD
END TYPE

TYPE SERVER_INFO_1523
    sv1523_maxkeepsearch AS DWORD
END TYPE

TYPE SERVER_INFO_1524
    sv1524_minkeepcomplsearch AS DWORD
END TYPE

TYPE SERVER_INFO_1525
    sv1525_maxkeepcomplsearch AS DWORD
END TYPE

TYPE SERVER_INFO_1528
    sv1528_scavtimeout AS DWORD
END TYPE

TYPE SERVER_INFO_1529
    sv1529_minrcvqueue AS DWORD
END TYPE

TYPE SERVER_INFO_1530
    sv1530_minfreeworkitems AS DWORD
END TYPE

TYPE SERVER_INFO_1533
    sv1533_maxmpxct AS DWORD
END TYPE

TYPE SERVER_INFO_1534
    sv1534_oplockbreakwait AS DWORD
END TYPE

TYPE SERVER_INFO_1535
    sv1535_oplockbreakresponsewait AS DWORD
END TYPE

TYPE SERVER_INFO_1536
    sv1536_enableoplocks AS LONG  ' BOOL
END TYPE

TYPE SERVER_INFO_1537
    sv1537_enableoplockforceclose AS LONG  ' BOOL
END TYPE

TYPE SERVER_INFO_1538
    sv1538_enablefcbopens AS LONG  ' BOOL
END TYPE

TYPE SERVER_INFO_1539
    sv1539_enableraw AS LONG  ' BOOL
END TYPE

TYPE SERVER_INFO_1540
    sv1540_enablesharednetdrives AS LONG  ' BOOL
END TYPE

TYPE SERVER_INFO_1541
    sv1541_minfreeconnections AS LONG  ' BOOL
END TYPE

TYPE SERVER_INFO_1542
    sv1542_maxfreeconnections AS LONG  ' BOOL
END TYPE

TYPE SERVER_INFO_1543
    sv1543_initsesstable AS DWORD
END TYPE

TYPE SERVER_INFO_1544
    sv1544_initconntable AS DWORD
END TYPE

TYPE SERVER_INFO_1545
    sv1545_initfiletable AS DWORD
END TYPE

TYPE SERVER_INFO_1546
    sv1546_initsearchtable AS DWORD
END TYPE

TYPE SERVER_INFO_1547
    sv1547_alertschedule AS DWORD
END TYPE

TYPE SERVER_INFO_1548
    sv1548_errorthreshold AS DWORD
END TYPE

TYPE SERVER_INFO_1549
    sv1549_networkerrorthreshold AS DWORD
END TYPE

TYPE SERVER_INFO_1550
    sv1550_diskspacethreshold AS DWORD
END TYPE

TYPE SERVER_INFO_1552
    sv1552_maxlinkdelay AS DWORD
END TYPE

TYPE SERVER_INFO_1553
    sv1553_minlinkthroughput AS DWORD
END TYPE

TYPE SERVER_INFO_1554
    sv1554_linkinfovalidtime AS DWORD
END TYPE

TYPE SERVER_INFO_1555
    sv1555_scavqosinfoupdatetime AS DWORD
END TYPE

TYPE SERVER_INFO_1556
    sv1556_maxworkitemidletime AS DWORD
END TYPE

TYPE SERVER_INFO_1557
    sv1557_maxrawworkitems AS DWORD
END TYPE

TYPE SERVER_INFO_1560
    sv1560_producttype AS DWORD
END TYPE

TYPE SERVER_INFO_1561
    sv1561_serversize AS DWORD
END TYPE

TYPE SERVER_INFO_1562
    sv1562_connectionlessautodisc AS DWORD
END TYPE

TYPE SERVER_INFO_1563
    sv1563_sharingviolationretries AS DWORD
END TYPE

TYPE SERVER_INFO_1564
    sv1564_sharingviolationdelay AS DWORD
END TYPE

TYPE SERVER_INFO_1565
    sv1565_maxglobalopensearch AS DWORD
END TYPE

TYPE SERVER_INFO_1566
    sv1566_removeduplicatesearches AS LONG  ' BOOL
END TYPE

TYPE SERVER_INFO_1567
    sv1567_lockviolationretries AS DWORD
END TYPE

TYPE SERVER_INFO_1568
    sv1568_lockviolationoffset AS DWORD
END TYPE

TYPE SERVER_INFO_1569
    sv1569_lockviolationdelay AS DWORD
END TYPE

TYPE SERVER_INFO_1570
    sv1570_mdlreadswitchover AS DWORD
END TYPE

TYPE SERVER_INFO_1571
    sv1571_cachedopenlimit AS DWORD
END TYPE

TYPE SERVER_INFO_1572
    sv1572_criticalthreads AS DWORD
END TYPE

TYPE SERVER_INFO_1573
    sv1573_restrictnullsessaccess AS DWORD
END TYPE

TYPE SERVER_INFO_1574
    sv1574_enablewfw311directipx AS DWORD
END TYPE

TYPE SERVER_INFO_1575
    sv1575_otherqueueaffinity AS DWORD
END TYPE

TYPE SERVER_INFO_1576
    sv1576_queuesamplesecs AS DWORD
END TYPE

TYPE SERVER_INFO_1577
    sv1577_balancecount AS DWORD
END TYPE

TYPE SERVER_INFO_1578
    sv1578_preferredaffinity AS DWORD
END TYPE

TYPE SERVER_INFO_1579
    sv1579_maxfreerfcbs AS DWORD
END TYPE

TYPE SERVER_INFO_1580
    sv1580_maxfreemfcbs AS DWORD
END TYPE

TYPE SERVER_INFO_1581
    sv1581_maxfreemlcbs AS DWORD
END TYPE

TYPE SERVER_INFO_1582
    sv1582_maxfreepagedpoolchunks AS DWORD
END TYPE

TYPE SERVER_INFO_1583
    sv1583_minpagedpoolchunksize AS DWORD
END TYPE

TYPE SERVER_INFO_1584
    sv1584_maxpagedpoolchunksize AS DWORD
END TYPE

TYPE SERVER_INFO_1585
    sv1585_sendsfrompreferredprocessor AS LONG  ' BOOL
END TYPE

TYPE SERVER_INFO_1586
    sv1586_maxthreadsperqueue AS DWORD
END TYPE

TYPE SERVER_INFO_1587
    sv1587_cacheddirectorylimit AS DWORD
END TYPE

TYPE SERVER_INFO_1588
    sv1588_maxcopylength AS DWORD
END TYPE

TYPE SERVER_INFO_1590
    sv1590_enablecompression AS DWORD
END TYPE

TYPE SERVER_INFO_1591
    sv1591_autosharewks AS DWORD
END TYPE

TYPE SERVER_INFO_1592
    sv1592_autosharewks AS DWORD
END TYPE

TYPE SERVER_INFO_1593
    sv1593_enablesecuritysignature AS DWORD
END TYPE

TYPE SERVER_INFO_1594
    sv1594_requiresecuritysignature AS DWORD
END TYPE

TYPE SERVER_INFO_1595
    sv1595_minclientbuffersize AS DWORD
END TYPE

TYPE SERVER_INFO_1596
    sv1596_ConnectionNoSessionsTimeout AS DWORD
END TYPE

TYPE SERVER_INFO_1597
    sv1597_IdleThreadTimeOut AS DWORD
END TYPE

TYPE SERVER_INFO_1598
    sv1598_enableW9xsecuritysignature AS DWORD
END TYPE

TYPE SERVER_INFO_1599
    sv1598_enforcekerberosreauthentication AS LONG  ' BOOLEAN
END TYPE

TYPE SERVER_INFO_1600
    sv1598_disabledos AS LONG  ' BOOLEAN
END TYPE

TYPE SERVER_INFO_1601
    sv1598_lowdiskspaceminimum AS DWORD
END TYPE

TYPE SERVER_INFO_1602
    sv_1598_disablestrictnamechecking AS LONG  ' BOOL
END TYPE

TYPE SERVER_TRANSPORT_INFO_0
    svti0_numberofvcs            AS DWORD
    svti0_transportname          AS LMSTR PTR
    svti0_transportaddress       AS BYTE PTR
    svti0_transportaddresslength AS DWORD
    svti0_networkaddress         AS LMSTR PTR
END TYPE

TYPE SERVER_TRANSPORT_INFO_1
    svti1_numberofvcs            AS DWORD
    svti1_transportname          AS LMSTR PTR
    svti1_transportaddress       AS BYTE PTR
    svti1_transportaddresslength AS DWORD
    svti1_networkaddress         AS LMSTR PTR
    svti1_domain                 AS LMSTR PTR
END TYPE

TYPE SERVER_TRANSPORT_INFO_2
    svti2_numberofvcs            AS DWORD
    svti2_transportname          AS LMSTR PTR
    svti2_transportaddress       AS BYTE PTR
    svti2_transportaddresslength AS DWORD
    svti2_networkaddress         AS LMSTR PTR
    svti2_domain                 AS LMSTR PTR
    svti2_flags                  AS DWORD
END TYPE

TYPE SERVER_TRANSPORT_INFO_3
    svti3_numberofvcs            AS DWORD
    svti3_transportname          AS LMSTR PTR
    svti3_transportaddress       AS BYTE PTR
    svti3_transportaddresslength AS DWORD
    svti3_networkaddress         AS LMSTR PTR
    svti3_domain                 AS LMSTR PTR
    svti3_flags                  AS DWORD
    svti3_passwordlength         AS DWORD
    svti3_password(255)          AS BYTE
END TYPE

'
' Defines - SERVER
'

'
' The platform ID indicates the levels to use for platform-specific
' information.
'

%SV_PLATFORM_ID_OS2 = 400
%SV_PLATFORM_ID_NT  = 500

'
'      Mask to be applied to svX_version_major in order to obtain
'      the major version number.
'

%MAJOR_VERSION_MASK = &H0F

'
'      Bit-mapped values for svX_type fields. X = 1, 2 or 3.
'

%SV_TYPE_WORKSTATION       = &H00000001
%SV_TYPE_SERVER            = &H00000002
%SV_TYPE_SQLSERVER         = &H00000004
%SV_TYPE_DOMAIN_CTRL       = &H00000008
%SV_TYPE_DOMAIN_BAKCTRL    = &H00000010
%SV_TYPE_TIME_SOURCE       = &H00000020
%SV_TYPE_AFP               = &H00000040
%SV_TYPE_NOVELL            = &H00000080
%SV_TYPE_DOMAIN_MEMBER     = &H00000100
%SV_TYPE_PRINTQ_SERVER     = &H00000200
%SV_TYPE_DIALIN_SERVER     = &H00000400
%SV_TYPE_XENIX_SERVER      = &H00000800
%SV_TYPE_SERVER_UNIX       = %SV_TYPE_XENIX_SERVER
%SV_TYPE_NT                = &H00001000
%SV_TYPE_WFW               = &H00002000
%SV_TYPE_SERVER_MFPN       = &H00004000
%SV_TYPE_SERVER_NT         = &H00008000
%SV_TYPE_POTENTIAL_BROWSER = &H00010000
%SV_TYPE_BACKUP_BROWSER    = &H00020000
%SV_TYPE_MASTER_BROWSER    = &H00040000
%SV_TYPE_DOMAIN_MASTER     = &H00080000
%SV_TYPE_SERVER_OSF        = &H00100000
%SV_TYPE_SERVER_VMS        = &H00200000
%SV_TYPE_WINDOWS           = &H00400000  ' Windows95 and above
%SV_TYPE_DFS               = &H00800000  ' Root of a DFS tree
%SV_TYPE_CLUSTER_NT        = &H01000000  ' NT Cluster
%SV_TYPE_TERMINALSERVER    = &H02000000  ' Terminal Server(Hydra)
%SV_TYPE_CLUSTER_VS_NT     = &H04000000  ' NT Cluster Virtual Server Name
%SV_TYPE_DCE               = &H10000000  ' IBM DSS (Directory and Security Services) or equivalent
%SV_TYPE_ALTERNATE_XPORT   = &H20000000  ' return list for alternate transport
%SV_TYPE_LOCAL_LIST_ONLY   = &H40000000  ' Return local list only
%SV_TYPE_DOMAIN_ENUM       = &H80000000???
%SV_TYPE_ALL               = &HFFFFFFFF???  ' handy for NetServerEnum2

'
'      Special value for sv102_disc that specifies infinite disconnect
'      time.
'

%SV_NODISC         = -1  ' (-1L)  ' No autodisconnect timeout enforced

'
'      Values of svX_security field. X = 2 or 3.
'

%SV_USERSECURITY   = 1
%SV_SHARESECURITY  = 0

'
'      Values of svX_hidden field. X = 2 or 3.
'

%SV_HIDDEN     = 1
%SV_VISIBLE    = 0

'
'      Values for ParmError parameter to NetServerSetInfo.
'

%SV_PLATFORM_ID_PARMNUM        = 101
%SV_NAME_PARMNUM               = 102
%SV_VERSION_MAJOR_PARMNUM      = 103
%SV_VERSION_MINOR_PARMNUM      = 104
%SV_TYPE_PARMNUM               = 105
%SV_COMMENT_PARMNUM            = 5
%SV_USERS_PARMNUM              = 107
%SV_DISC_PARMNUM               = 10
%SV_HIDDEN_PARMNUM             = 16
%SV_ANNOUNCE_PARMNUM           = 17
%SV_ANNDELTA_PARMNUM           = 18
%SV_USERPATH_PARMNUM           = 112

%SV_ULIST_MTIME_PARMNUM        = 401
%SV_GLIST_MTIME_PARMNUM        = 402
%SV_ALIST_MTIME_PARMNUM        = 403
%SV_ALERTS_PARMNUM             = 11
%SV_SECURITY_PARMNUM           = 405
%SV_NUMADMIN_PARMNUM           = 406
%SV_LANMASK_PARMNUM            = 407
%SV_GUESTACC_PARMNUM           = 408
%SV_CHDEVQ_PARMNUM             = 410
%SV_CHDEVJOBS_PARMNUM          = 411
%SV_CONNECTIONS_PARMNUM        = 412
%SV_SHARES_PARMNUM             = 413
%SV_OPENFILES_PARMNUM          = 414
%SV_SESSREQS_PARMNUM           = 417
%SV_ACTIVELOCKS_PARMNUM        = 419
%SV_NUMREQBUF_PARMNUM          = 420
%SV_NUMBIGBUF_PARMNUM          = 422
%SV_NUMFILETASKS_PARMNUM       = 423
%SV_ALERTSCHED_PARMNUM         = 37
%SV_ERRORALERT_PARMNUM         = 38
%SV_LOGONALERT_PARMNUM         = 39
%SV_ACCESSALERT_PARMNUM        = 40
%SV_DISKALERT_PARMNUM          = 41
%SV_NETIOALERT_PARMNUM         = 42
%SV_MAXAUDITSZ_PARMNUM         = 43
%SV_SRVHEURISTICS_PARMNUM      = 431

%SV_SESSOPENS_PARMNUM                       = 501
%SV_SESSVCS_PARMNUM                         = 502
%SV_OPENSEARCH_PARMNUM                      = 503
%SV_SIZREQBUF_PARMNUM                       = 504
%SV_INITWORKITEMS_PARMNUM                   = 505
%SV_MAXWORKITEMS_PARMNUM                    = 506
%SV_RAWWORKITEMS_PARMNUM                    = 507
%SV_IRPSTACKSIZE_PARMNUM                    = 508
%SV_MAXRAWBUFLEN_PARMNUM                    = 509
%SV_SESSUSERS_PARMNUM                       = 510
%SV_SESSCONNS_PARMNUM                       = 511
%SV_MAXNONPAGEDMEMORYUSAGE_PARMNUM          = 512
%SV_MAXPAGEDMEMORYUSAGE_PARMNUM             = 513
%SV_ENABLESOFTCOMPAT_PARMNUM                = 514
%SV_ENABLEFORCEDLOGOFF_PARMNUM              = 515
%SV_TIMESOURCE_PARMNUM                      = 516
%SV_ACCEPTDOWNLEVELAPIS_PARMNUM             = 517
%SV_LMANNOUNCE_PARMNUM                      = 518
%SV_DOMAIN_PARMNUM                          = 519
%SV_MAXCOPYREADLEN_PARMNUM                  = 520
%SV_MAXCOPYWRITELEN_PARMNUM                 = 521
%SV_MINKEEPSEARCH_PARMNUM                   = 522
%SV_MAXKEEPSEARCH_PARMNUM                   = 523
%SV_MINKEEPCOMPLSEARCH_PARMNUM              = 524
%SV_MAXKEEPCOMPLSEARCH_PARMNUM              = 525
%SV_THREADCOUNTADD_PARMNUM                  = 526
%SV_NUMBLOCKTHREADS_PARMNUM                 = 527
%SV_SCAVTIMEOUT_PARMNUM                     = 528
%SV_MINRCVQUEUE_PARMNUM                     = 529
%SV_MINFREEWORKITEMS_PARMNUM                = 530
%SV_XACTMEMSIZE_PARMNUM                     = 531
%SV_THREADPRIORITY_PARMNUM                  = 532
%SV_MAXMPXCT_PARMNUM                        = 533
%SV_OPLOCKBREAKWAIT_PARMNUM                 = 534
%SV_OPLOCKBREAKRESPONSEWAIT_PARMNUM         = 535
%SV_ENABLEOPLOCKS_PARMNUM                   = 536
%SV_ENABLEOPLOCKFORCECLOSE_PARMNUM          = 537
%SV_ENABLEFCBOPENS_PARMNUM                  = 538
%SV_ENABLERAW_PARMNUM                       = 539
%SV_ENABLESHAREDNETDRIVES_PARMNUM           = 540
%SV_MINFREECONNECTIONS_PARMNUM              = 541
%SV_MAXFREECONNECTIONS_PARMNUM              = 542
%SV_INITSESSTABLE_PARMNUM                   = 543
%SV_INITCONNTABLE_PARMNUM                   = 544
%SV_INITFILETABLE_PARMNUM                   = 545
%SV_INITSEARCHTABLE_PARMNUM                 = 546
%SV_ALERTSCHEDULE_PARMNUM                   = 547
%SV_ERRORTHRESHOLD_PARMNUM                  = 548
%SV_NETWORKERRORTHRESHOLD_PARMNUM           = 549
%SV_DISKSPACETHRESHOLD_PARMNUM              = 550
%SV_MAXLINKDELAY_PARMNUM                    = 552
%SV_MINLINKTHROUGHPUT_PARMNUM               = 553
%SV_LINKINFOVALIDTIME_PARMNUM               = 554
%SV_SCAVQOSINFOUPDATETIME_PARMNUM           = 555
%SV_MAXWORKITEMIDLETIME_PARMNUM             = 556
%SV_MAXRAWWORKITEMS_PARMNUM                 = 557
%SV_PRODUCTTYPE_PARMNUM                     = 560
%SV_SERVERSIZE_PARMNUM                      = 561
%SV_CONNECTIONLESSAUTODISC_PARMNUM          = 562
%SV_SHARINGVIOLATIONRETRIES_PARMNUM         = 563
%SV_SHARINGVIOLATIONDELAY_PARMNUM           = 564
%SV_MAXGLOBALOPENSEARCH_PARMNUM             = 565
%SV_REMOVEDUPLICATESEARCHES_PARMNUM         = 566
%SV_LOCKVIOLATIONRETRIES_PARMNUM            = 567
%SV_LOCKVIOLATIONOFFSET_PARMNUM             = 568
%SV_LOCKVIOLATIONDELAY_PARMNUM              = 569
%SV_MDLREADSWITCHOVER_PARMNUM               = 570
%SV_CACHEDOPENLIMIT_PARMNUM                 = 571
%SV_CRITICALTHREADS_PARMNUM                 = 572
%SV_RESTRICTNULLSESSACCESS_PARMNUM          = 573
%SV_ENABLEWFW311DIRECTIPX_PARMNUM           = 574
%SV_OTHERQUEUEAFFINITY_PARMNUM              = 575
%SV_QUEUESAMPLESECS_PARMNUM                 = 576
%SV_BALANCECOUNT_PARMNUM                    = 577
%SV_PREFERREDAFFINITY_PARMNUM               = 578
%SV_MAXFREERFCBS_PARMNUM                    = 579
%SV_MAXFREEMFCBS_PARMNUM                    = 580
%SV_MAXFREELFCBS_PARMNUM                    = 581
%SV_MAXFREEPAGEDPOOLCHUNKS_PARMNUM          = 582
%SV_MINPAGEDPOOLCHUNKSIZE_PARMNUM           = 583
%SV_MAXPAGEDPOOLCHUNKSIZE_PARMNUM           = 584
%SV_SENDSFROMPREFERREDPROCESSOR_PARMNUM     = 585
%SV_MAXTHREADSPERQUEUE_PARMNUM              = 586
%SV_CACHEDDIRECTORYLIMIT_PARMNUM            = 587
%SV_MAXCOPYLENGTH_PARMNUM                   = 588
%SV_ENABLECOMPRESSION_PARMNUM               = 590
%SV_AUTOSHAREWKS_PARMNUM                    = 591
%SV_AUTOSHARESERVER_PARMNUM                 = 592
%SV_ENABLESECURITYSIGNATURE_PARMNUM         = 593
%SV_REQUIRESECURITYSIGNATURE_PARMNUM        = 594
%SV_MINCLIENTBUFFERSIZE_PARMNUM             = 595
%SV_CONNECTIONNOSESSIONSTIMEOUT_PARMNUM     = 596
%SV_IDLETHREADTIMEOUT_PARMNUM               = 597
%SV_ENABLEW9XSECURITYSIGNATURE_PARMNUM      = 598
%SV_ENFORCEKERBEROSREAUTHENTICATION_PARMNUM = 599
%SV_DISABLEDOS_PARMNUM                      = 600
%SV_LOWDISKSPACEMINIMUM_PARMNUM             = 601
%SV_DISABLESTRICTNAMECHECKING_PARMNUM       = 602
%SV_ENABLEAUTHENTICATEUSERSHARING_PARMNUM   = 603

'
' Single-field infolevels for NetServerSetInfo.
'

%SV_COMMENT_INFOLEVEL                    = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_COMMENT_PARMNUM)
%SV_USERS_INFOLEVEL                      = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_USERS_PARMNUM)
%SV_DISC_INFOLEVEL                       = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_DISC_PARMNUM)
%SV_HIDDEN_INFOLEVEL                     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_HIDDEN_PARMNUM)
%SV_ANNOUNCE_INFOLEVEL                   = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_ANNOUNCE_PARMNUM)
%SV_ANNDELTA_INFOLEVEL                   = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_ANNDELTA_PARMNUM)
%SV_SESSOPENS_INFOLEVEL                  = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_SESSOPENS_PARMNUM)
%SV_SESSVCS_INFOLEVEL                    = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_SESSVCS_PARMNUM)
%SV_OPENSEARCH_INFOLEVEL                 = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_OPENSEARCH_PARMNUM)
%SV_MAXWORKITEMS_INFOLEVEL               = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MAXWORKITEMS_PARMNUM)
%SV_MAXRAWBUFLEN_INFOLEVEL               = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MAXRAWBUFLEN_PARMNUM)
%SV_SESSUSERS_INFOLEVEL                  = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_SESSUSERS_PARMNUM)
%SV_SESSCONNS_INFOLEVEL                  = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_SESSCONNS_PARMNUM)
%SV_MAXNONPAGEDMEMORYUSAGE_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MAXNONPAGEDMEMORYUSAGE_PARMNUM)
%SV_MAXPAGEDMEMORYUSAGE_INFOLEVEL        = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MAXPAGEDMEMORYUSAGE_PARMNUM)
%SV_ENABLESOFTCOMPAT_INFOLEVEL           = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_ENABLESOFTCOMPAT_PARMNUM)
%SV_ENABLEFORCEDLOGOFF_INFOLEVEL         = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_ENABLEFORCEDLOGOFF_PARMNUM)
%SV_TIMESOURCE_INFOLEVEL                 = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_TIMESOURCE_PARMNUM)
%SV_LMANNOUNCE_INFOLEVEL                 = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_LMANNOUNCE_PARMNUM)
%SV_MAXCOPYREADLEN_INFOLEVEL             = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MAXCOPYREADLEN_PARMNUM)
%SV_MAXCOPYWRITELEN_INFOLEVEL            = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MAXCOPYWRITELEN_PARMNUM)
%SV_MINKEEPSEARCH_INFOLEVEL              = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MINKEEPSEARCH_PARMNUM)
%SV_MAXKEEPSEARCH_INFOLEVEL              = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MAXKEEPSEARCH_PARMNUM)
%SV_MINKEEPCOMPLSEARCH_INFOLEVEL         = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MINKEEPCOMPLSEARCH_PARMNUM)
%SV_MAXKEEPCOMPLSEARCH_INFOLEVEL         = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MAXKEEPCOMPLSEARCH_PARMNUM)
%SV_SCAVTIMEOUT_INFOLEVEL                = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_SCAVTIMEOUT_PARMNUM)
%SV_MINRCVQUEUE_INFOLEVEL                = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MINRCVQUEUE_PARMNUM)
%SV_MINFREEWORKITEMS_INFOLEVEL           = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MINFREEWORKITEMS_PARMNUM)
%SV_MAXMPXCT_INFOLEVEL                   = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MAXMPXCT_PARMNUM)
%SV_OPLOCKBREAKWAIT_INFOLEVEL            = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_OPLOCKBREAKWAIT_PARMNUM)
%SV_OPLOCKBREAKRESPONSEWAIT_INFOLEVEL    = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_OPLOCKBREAKRESPONSEWAIT_PARMNUM)
%SV_ENABLEOPLOCKS_INFOLEVEL              = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_ENABLEOPLOCKS_PARMNUM)
%SV_ENABLEOPLOCKFORCECLOSE_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_ENABLEOPLOCKFORCECLOSE_PARMNUM)
%SV_ENABLEFCBOPENS_INFOLEVEL             = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_ENABLEFCBOPENS_PARMNUM)
%SV_ENABLERAW_INFOLEVEL                  = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_ENABLERAW_PARMNUM)
%SV_ENABLESHAREDNETDRIVES_INFOLEVEL      = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_ENABLESHAREDNETDRIVES_PARMNUM)
%SV_MINFREECONNECTIONS_INFOLEVEL         = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MINFREECONNECTIONS_PARMNUM)
%SV_MAXFREECONNECTIONS_INFOLEVEL         = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MAXFREECONNECTIONS_PARMNUM)
%SV_INITSESSTABLE_INFOLEVEL              = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_INITSESSTABLE_PARMNUM)
%SV_INITCONNTABLE_INFOLEVEL              = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_INITCONNTABLE_PARMNUM)
%SV_INITFILETABLE_INFOLEVEL              = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_INITFILETABLE_PARMNUM)
%SV_INITSEARCHTABLE_INFOLEVEL            = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_INITSEARCHTABLE_PARMNUM)
%SV_ALERTSCHEDULE_INFOLEVEL              = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_ALERTSCHEDULE_PARMNUM)
%SV_ERRORTHRESHOLD_INFOLEVEL             = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_ERRORTHRESHOLD_PARMNUM)
%SV_NETWORKERRORTHRESHOLD_INFOLEVEL      = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_NETWORKERRORTHRESHOLD_PARMNUM)
%SV_DISKSPACETHRESHOLD_INFOLEVEL         = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_DISKSPACETHRESHOLD_PARMNUM)
%SV_MAXLINKDELAY_INFOLEVEL               = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MAXLINKDELAY_PARMNUM)
%SV_MINLINKTHROUGHPUT_INFOLEVEL          = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MINLINKTHROUGHPUT_PARMNUM)
%SV_LINKINFOVALIDTIME_INFOLEVEL          = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_LINKINFOVALIDTIME_PARMNUM)
%SV_SCAVQOSINFOUPDATETIME_INFOLEVEL      = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_SCAVQOSINFOUPDATETIME_PARMNUM)
%SV_MAXWORKITEMIDLETIME_INFOLEVEL        = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MAXWORKITEMIDLETIME_PARMNUM)
%SV_MAXRAWWORKITEMS_INFOLOEVEL           = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MAXRAWWORKITEMS_PARMNUM)
%SV_PRODUCTTYPE_INFOLOEVEL                = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_PRODUCTTYPE_PARMNUM)
%SV_SERVERSIZE_INFOLOEVEL                = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_SERVERSIZE_PARMNUM)
%SV_CONNECTIONLESSAUTODISC_INFOLOEVEL    = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_CONNECTIONLESSAUTODISC_PARMNUM)
%SV_SHARINGVIOLATIONRETRIES_INFOLOEVEL   = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_SHARINGVIOLATIONRETRIES_PARMNUM)
%SV_SHARINGVIOLATIONDELAY_INFOLOEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_SHARINGVIOLATIONDELAY_PARMNUM)
%SV_MAXGLOBALOPENSEARCH_INFOLOEVEL       = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MAXGLOBALOPENSEARCH_PARMNUM)
%SV_REMOVEDUPLICATESEARCHES_INFOLOEVEL       = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_REMOVEDUPLICATESEARCHES_PARMNUM)
%SV_LOCKVIOLATIONRETRIES_INFOLOEVEL   = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_LOCKVIOLATIONRETRIES_PARMNUM)
%SV_LOCKVIOLATIONOFFSET_INFOLOEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_LOCKVIOLATIONOFFSET_PARMNUM)
%SV_LOCKVIOLATIONDELAY_INFOLOEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_LOCKVIOLATIONDELAY_PARMNUM)
%SV_MDLREADSWITCHOVER_INFOLOEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MDLREADSWITCHOVER_PARMNUM)
%SV_CACHEDOPENLIMIT_INFOLOEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_CACHEDOPENLIMIT_PARMNUM)
%SV_CRITICALTHREADS_INFOLOEVEL       = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_CRITICALTHREADS_PARMNUM)
%SV_RESTRICTNULLSESSACCESS_INFOLOEVEL       = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_RESTRICTNULLSESSACCESS_PARMNUM)
%SV_ENABLEWFW311DIRECTIPX_INFOLOEVEL       = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_ENABLEWFW311DIRECTIPX_PARMNUM)
%SV_OTHERQUEUEAFFINITY_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_OTHERQUEUEAFFINITY_PARMNUM)
%SV_QUEUESAMPLESECS_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_QUEUESAMPLESECS_PARMNUM)
%SV_BALANCECOUNT_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_BALANCECOUNT_PARMNUM)
%SV_PREFERREDAFFINITY_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_PREFERREDAFFINITY_PARMNUM)
%SV_MAXFREERFCBS_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MAXFREERFCBS_PARMNUM)
%SV_MAXFREEMFCBS_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MAXFREEMFCBS_PARMNUM)
%SV_MAXFREELFCBS_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MAXFREELFCBS_PARMNUM)
%SV_MAXFREEPAGEDPOOLCHUNKS_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MAXFREEPAGEDPOOLCHUNKS_PARMNUM)
%SV_MINPAGEDPOOLCHUNKSIZE_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MINPAGEDPOOLCHUNKSIZE_PARMNUM)
%SV_MAXPAGEDPOOLCHUNKSIZE_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MAXPAGEDPOOLCHUNKSIZE_PARMNUM)
%SV_SENDSFROMPREFERREDPROCESSOR_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_SENDSFROMPREFERREDPROCESSOR_PARMNUM)
%SV_MAXTHREADSPERQUEUE_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MAXTHREADSPERQUEUE_PARMNUM)
%SV_CACHEDDIRECTORYLIMIT_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_CACHEDDIRECTORYLIMIT_PARMNUM)
%SV_MAXCOPYLENGTH_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MAXCOPYLENGTH_PARMNUM)
%SV_ENABLECOMPRESSION_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_ENABLECOMPRESSION_PARMNUM)
%SV_AUTOSHAREWKS_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_AUTOSHAREWKS_PARMNUM)
%SV_AUTOSHARESERVER_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_AUTOSHARESERVER_PARMNUM)
%SV_ENABLESECURITYSIGNATURE_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_ENABLESECURITYSIGNATURE_PARMNUM)
%SV_REQUIRESECURITYSIGNATURE_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_REQUIRESECURITYSIGNATURE_PARMNUM)
%SV_MINCLIENTBUFFERSIZE_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_MINCLIENTBUFFERSIZE_PARMNUM)
%SV_CONNECTIONNOSESSIONSTIMEOUT_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_CONNECTIONNOSESSIONSTIMEOUT_PARMNUM)
%SV_IDLETHREADTIMEOUT_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_IDLETHREADTIMEOUT_PARMNUM)
%SV_ENABLEW9XSECURITYSIGNATURE_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_ENABLEW9XSECURITYSIGNATURE_PARMNUM)
%SV_ENFORCEKERBEROSREAUTHENTICATION_INFOLEVEL = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_ENFORCEKERBEROSREAUTHENTICATION_PARMNUM)
%SV_DISABLEDOS_INFOLEVEL = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_DISABLEDOS_PARMNUM)
%SV_LOWDISKSPACEMINIMUM_INFOLEVEL = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_LOWDISKSPACEMINIMUM_PARMNUM)
%SV_DISABLESTRICTNAMECHECKING_INFOLEVEL = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_DISABLESTRICTNAMECHECKING_PARMNUM)
%SV_ENABLEAUTHENTICATEUSERSHARING_INFOLEVEL = _
            (%PARMNUM_BASE_INFOLEVEL + %SV_ENABLEAUTHENTICATEUSERSHARING_PARMNUM)

%SVI1_NUM_ELEMENTS     = 5
%SVI2_NUM_ELEMENTS     = 40
%SVI3_NUM_ELEMENTS     = 44

'
'      Maxmimum length for command string to NetServerAdminCommand.
'

%SV_MAX_CMD_LEN        = %PATHLEN

'
'      Masks describing AUTOPROFILE parameters
'

%SW_AUTOPROF_LOAD_MASK = &H1
%SW_AUTOPROF_SAVE_MASK = &H2

'
'      Max size of svX_srvheuristics.
'

%SV_MAX_SRV_HEUR_LEN   = 32      ' Max heuristics info string length.

'
'      Equate for use with sv102_licenses.
'

%SV_USERS_PER_LICENSE  = 5

'
' Equate for use with svti2_flags in NetServerTransportAddEx.
'

%SVTI2_REMAP_PIPE_NAMES = &H2
%SVTI2_SCOPED_NAME      = &H4
%SVTI2_VALID_FLAGS = (%SVTI2_REMAP_PIPE_NAMES OR %SVTI2_SCOPED_NAME)

'
' Server capability information
'

%SRV_SUPPORT_HASH_GENERATION     = &H0001
%SRV_HASH_GENERATION_ACTIVE      = &H0002
