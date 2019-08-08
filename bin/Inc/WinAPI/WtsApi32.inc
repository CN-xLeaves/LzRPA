'------------------------------------------------------------------------------
'
'  WtsApi32.inc -- Windows Terminal Server public APIs
'
'  Copyright (c) 2011 PowerBASIC, Inc.
'  Portions Copyright (c) 1997-2001 Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from WtsApi32.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%INC_WTSAPI = 1

#INCLUDE "WinDef.inc"
#INCLUDE "WTypes.inc"


'====================================================================
'=   Defines
'====================================================================

'
'  Specifies the current server
'
%WTS_CURRENT_SERVER        = %NULL
%WTS_CURRENT_SERVER_HANDLE = %NULL
%WTS_CURRENT_SERVER_NAME   = %NULL

'
'  Specifies the current session (SessionId)
'
%WTS_CURRENT_SESSION = &HFFFFFFFF???  ' ((DWORD)-1)

'
'  Specifies any-session (SessionId)
'
%WTS_ANY_SESSION = &HFFFFFFFE???  ' ((DWORD)-2)

'
'  Possible pResponse values from WTSSendMessage()
'
#IF NOT %DEF(%IDTIMEOUT)
%IDTIMEOUT = 32000
#ENDIF
#IF NOT %DEF(%IDASYNC)
%IDASYNC = 32001
#ENDIF

#IF NOT %DEF(%HYDRIX_H)
%USERNAME_LENGTH        = 20
%CLIENTNAME_LENGTH      = 20
%CLIENTADDRESS_LENGTH   = 30
#ENDIF
'
'  Shutdown flags
'
%WTS_WSD_LOGOFF      = &H00000001  ' log off all users except
                                   ' current user; deletes
                                   ' WinStations (a reboot is
                                   ' required to recreate the
                                   ' WinStations)
%WTS_WSD_SHUTDOWN    = &H00000002  ' shutdown system
%WTS_WSD_REBOOT      = &H00000004  ' shutdown and reboot
%WTS_WSD_POWEROFF    = &H00000008  ' shutdown and power off (on
                                   ' machines that support power
                                   ' off through software)
%WTS_WSD_FASTREBOOT  = &H00000010  ' reboot without logging users
                                   ' off or shutting down
%MAX_ELAPSED_TIME_LENGTH  = 15
%MAX_DATE_TIME_LENGTH     = 56
%WINSTATIONNAME_LENGTH    = 32
%DOMAIN_LENGTH            = 17

%WTS_DRIVE_LENGTH         = 3
%WTS_LISTENER_NAME_LENGTH = 32
%WTS_COMMENT_LENGTH       = 60

'
'  Flags for WTSCreateListener
'
%WTS_LISTENER_CREATE = &H00000001
%WTS_LISTENER_UPDATE = &H00000010

'*********************************
'*   Listener access values
'*********************************
%WTS_SECURITY_QUERY_INFORMATION    = &H00000001
%WTS_SECURITY_SET_INFORMATION      = &H00000002
%WTS_SECURITY_RESET                = &H00000004
%WTS_SECURITY_VIRTUAL_CHANNELS     = &H00000008
%WTS_SECURITY_REMOTE_CONTROL       = &H00000010
%WTS_SECURITY_LOGON                = &H00000020
%WTS_SECURITY_LOGOFF               = &H00000040
%WTS_SECURITY_MESSAGE              = &H00000080
%WTS_SECURITY_CONNECT              = &H00000100
%WTS_SECURITY_DISCONNECT           = &H00000200

%WTS_SECURITY_GUEST_ACCESS         = (%WTS_SECURITY_LOGON)

%WTS_SECURITY_CURRENT_GUEST_ACCESS = (%WTS_SECURITY_VIRTUAL_CHANNELS OR %WTS_SECURITY_LOGOFF)

%WTS_SECURITY_USER_ACCESS          = (%WTS_SECURITY_CURRENT_GUEST_ACCESS OR %WTS_SECURITY_QUERY_INFORMATION OR %WTS_SECURITY_CONNECT)

%WTS_SECURITY_CURRENT_USER_ACCESS  = (%WTS_SECURITY_SET_INFORMATION OR %WTS_SECURITY_RESET OR _
                                      %WTS_SECURITY_VIRTUAL_CHANNELS OR %WTS_SECURITY_LOGOFF OR _
                                      %WTS_SECURITY_DISCONNECT)

%WTS_SECURITY_ALL_ACCESS           = (%STANDARD_RIGHTS_REQUIRED OR %WTS_SECURITY_QUERY_INFORMATION OR       _
                                      %WTS_SECURITY_SET_INFORMATION OR %WTS_SECURITY_RESET OR               _
                                      %WTS_SECURITY_VIRTUAL_CHANNELS OR    %WTS_SECURITY_REMOTE_CONTROL OR  _
                                      %WTS_SECURITY_LOGON OR                                              _
                                      %WTS_SECURITY_MESSAGE OR                                            _
                                      %WTS_SECURITY_CONNECT OR %WTS_SECURITY_DISCONNECT)

'====================================================================
'=   WTS_CONNECTSTATE_CLASS - Session connect state
'====================================================================

MACRO WTS_CONNECTSTATE_CLASS_enum=LONG
ENUM WTS_CONNECTSTATE_CLASS SINGULAR
    WTSActive               ' User logged on to WinStation
    WTSConnected            ' WinStation connected to client
    WTSConnectQuery         ' In the process of connecting to client
    WTSShadow               ' Shadowing another WinStation
    WTSDisconnected         ' WinStation logged on without client
    WTSIdle                 ' Waiting for client to connect
    WTSListen               ' WinStation is listening for connection
    WTSReset                ' WinStation is being reset
    WTSDown                 ' WinStation is down due to error
    WTSInit                 ' WinStation in initialization
END ENUM

'======================================================================
'=   WTS_SERVER_INFO - returned by WTSEnumerateServers (version 1)
'======================================================================

'*
'*  WTSEnumerateServers() returns two variables: pServerInfo and Count.
'*  The latter is the number of WTS_SERVER_INFO structures contained in
'*  the former.  In order to read each server, iterate i from 0 to
'*  Count-1 and reference the server name as
'*  pServerInfo[i].pServerName; for example:
'*
'*  for ( i=0; i < Count; i++ ) {
'*      _tprintf( TEXT("%s "), pServerInfo[i].pServerName );
'*  }
'*
'*  The memory returned looks like the following.  P is a pServerInfo
'*  pointer, and D is the string data for that pServerInfo:
'*
'*  P1 P2 P3 P4 ... Pn D1 D2 D3 D4 ... Dn
'*
'*  This makes it easier to iterate the servers, using code similar to
'*  the above.
'*

TYPE WTS_SERVER_INFOW
    pServerName AS WSTRINGZ PTR    ' server name
END TYPE

TYPE WTS_SERVER_INFOA
    pServerName AS ASCIIZ PTR      ' server name
END TYPE

#IF %DEF(%UNICODE)
TYPE WTS_SERVER_INFO
    WTS_SERVER_INFOW
END TYPE
#ELSE
TYPE WTS_SERVER_INFO
    WTS_SERVER_INFOA
END TYPE
#ENDIF


'======================================================================
'=   WTS_SESSION_INFO - returned by WTSEnumerateSessions (version 1)
'======================================================================

'*
'*  WTSEnumerateSessions() returns data in a similar format to the above
'*  WTSEnumerateServers().  It returns two variables: pSessionInfo and
'*  Count.  The latter is the number of WTS_SESSION_INFO structures
'*  contained in the former.  Iteration is similar, except that there
'*  are three parts to each entry, so it would look like this:
'*
'*  for ( i=0; i < Count; i++ ) {
'*      _tprintf( TEXT("%-5u  %-20s  %u\n"),
'*                pSessionInfo[i].SessionId,
'*                pSessionInfo[i].pWinStationName,
'*                pSessionInfo[i].State );
'*  }
'*
'*  The memory returned is also segmented as the above, with all the
'*  structures allocated at the start and the string data at the end.
'*  We'll use S for the SessionId, P for the pWinStationName pointer
'*  and D for the string data, and C for the connect State:
'*
'*  S1 P1 C1 S2 P2 C2 S3 P3 C3 S4 P4 C4 ... Sn Pn Cn D1 D2 D3 D4 ... Dn
'*
'*  As above, this makes it easier to iterate the sessions.
'*

TYPE WTS_SESSION_INFOW
    SessionId       AS DWORD          ' session id
    pWinStationName AS WSTRINGZ PTR   ' name of WinStation this session is
                                      ' connected to
    State AS WTS_CONNECTSTATE_CLASS_enum  ' connection state (see enum)
END TYPE

TYPE WTS_SESSION_INFOA
    SessionId       AS DWORD          ' session id
    pWinStationName AS ASCIIZ PTR     ' name of WinStation this session is
                                      ' connected to
    State AS WTS_CONNECTSTATE_CLASS_enum  ' connection state (see enum)
END TYPE

TYPE WTS_SESSION_INFO_1W
    ExecEnvId    AS DWORD
    State        AS WTS_CONNECTSTATE_CLASS_enum
    SessionId    AS DWORD
    pSessionName AS WSTRINGZ PTR
    pHostName    AS WSTRINGZ PTR
    pUserName    AS WSTRINGZ PTR
    pDomainName  AS WSTRINGZ PTR
    pFarmName    AS WSTRINGZ PTR
END TYPE

TYPE WTS_SESSION_INFO_1A
    ExecEnvId    AS DWORD
    State        AS WTS_CONNECTSTATE_CLASS_enum
    SessionId    AS DWORD
    pSessionName AS ASCIIZ PTR
    pHostName    AS ASCIIZ PTR
    pUserName    AS ASCIIZ PTR
    pDomainName  AS ASCIIZ PTR
    pFarmName    AS ASCIIZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE WTS_SESSION_INFO
    WTS_SESSION_INFOW
END TYPE
TYPE WTS_SESSION_INFO_1
    WTS_SESSION_INFO_1W
END TYPE
#ELSE
TYPE WTS_SESSION_INFO
    WTS_SESSION_INFOA
END TYPE
TYPE WTS_SESSION_INFO_1
    WTS_SESSION_INFO_1A
END TYPE
#ENDIF


'======================================================================
'=   WTS_PROCESS_INFO - returned by WTSEnumerateProcesses (version 1)
'======================================================================

'*
'*  WTSEnumerateProcesses() also returns data similar to
'*  WTSEnumerateServers().  It returns two variables: pProcessInfo and
'*  Count.  The latter is the number of WTS_PROCESS_INFO structures
'*  contained in the former.  Iteration is similar, except that there
'*  are four parts to each entry, so it would look like this:
'*
'*  for ( i=0; i < Count; i++ ) {
'*      GetUserNameFromSid( pProcessInfo[i].pUserSid, UserName,
'*                          sizeof(UserName) );
'*      _tprintf( TEXT("%-5u  %-20s  %-5u  %s\n"),
'*              pProcessInfo[i].SessionId,
'*              UserName,
'*              pProcessInfo[i].ProcessId,
'*              pProcessInfo[i].pProcessName );
'*  }
'*
'*  The memory returned is also segmented as the above, with all the
'*  structures allocated at the start and the string data at the end.
'*  We'll use S for the SessionId, R for the ProcessId, P for the
'*  pProcessName pointer and D for the string data, and U for pUserSid:
'*
'*  S1 R1 P1 U1 S2 R2 P2 U2 S3 R3 P3 U3 ... Sn Rn Pn Un D1 D2 D3 ... Dn
'*
'*  As above, this makes it easier to iterate the processes.
'*

TYPE WTS_PROCESS_INFOW
    SessionId    AS DWORD        ' session id
    ProcessId    AS DWORD        ' process id
    pProcessName AS WSTRINGZ PTR ' name of process
    pUserSid     AS SID PTR      ' user's SID
END TYPE

TYPE WTS_PROCESS_INFOA
    SessionId    AS DWORD        ' session id
    ProcessId    AS DWORD        ' process id
    pProcessName AS ASCIIZ PTR   ' name of process
    pUserSid     AS SID PTR      ' user's SID
END TYPE

#IF %DEF(%UNICODE)
TYPE WTS_PROCESS_INFO
    WTS_PROCESS_INFOW
END TYPE
#ELSE
TYPE WTS_PROCESS_INFO
    WTS_PROCESS_INFOA
END TYPE
#ENDIF

'======================================================================
'=   WTS_INFO_CLASS - WTSQuerySessionInformation
'=    (See additional typedefs for more info on structures)
'======================================================================

%WTS_PROTOCOL_TYPE_CONSOLE       = 0    ' Console
%WTS_PROTOCOL_TYPE_ICA           = 1    ' ICA Protocol
%WTS_PROTOCOL_TYPE_RDP           = 2    ' RDP Protocol

MACRO WTS_INFO_CLASS_enum=LONG
ENUM WTS_INFO_CLASS SINGULAR
    WTSInitialProgram
    WTSApplicationName
    WTSWorkingDirectory
    WTSOEMId
    WTSSessionId
    WTSUserName
    WTSWinStationName
    WTSDomainName
    WTSConnectState
    WTSClientBuildNumber
    WTSClientName
    WTSClientDirectory
    WTSClientProductId
    WTSClientHardwareId
    WTSClientAddress
    WTSClientDisplay
    WTSClientProtocolType
    WTSIdleTime
    WTSLogonTime
    WTSIncomingBytes
    WTSOutgoingBytes
    WTSIncomingFrames
    WTSOutgoingFrames
    WTSClientInfo
    WTSSessionInfo
    WTSSessionInfoEx
    WTSConfigInfo
    WTSValidationInfo   ' Info Class value used to fetch Validation Information through the WTSQuerySessionInformation
    WTSSessionAddressV4
    WTSIsRemoteSession
END ENUM

'======================================================================
'=   WTS Config Information
'======================================================================

TYPE WTSCONFIGINFOW
    version                          AS DWORD
    fConnectClientDrivesAtLogon      AS DWORD
    fConnectPrinterAtLogon           AS DWORD
    fDisablePrinterRedirection       AS DWORD
    fDisableDefaultMainClientPrinter AS DWORD
    ShadowSettings                   AS DWORD
    LogonUserName                    AS WSTRINGZ * %USERNAME_LENGTH + 1
    LogonDomain                      AS WSTRINGZ * %DOMAIN_LENGTH + 1
    WorkDirectory                    AS WSTRINGZ * %MAX_PATH + 1
    InitialProgram                   AS WSTRINGZ * %MAX_PATH + 1
    ApplicationName                  AS WSTRINGZ * %MAX_PATH + 1
END TYPE

TYPE WTSCONFIGINFOA
    version AS DWORD
    fConnectClientDrivesAtLogon      AS DWORD
    fConnectPrinterAtLogon           AS DWORD
    fDisablePrinterRedirection       AS DWORD
    fDisableDefaultMainClientPrinter AS DWORD
    ShadowSettings                   AS DWORD
    LogonUserName                    AS ASCIIZ * %USERNAME_LENGTH + 1
    LogonDomain                      AS ASCIIZ * %DOMAIN_LENGTH + 1
    WorkDirectory                    AS ASCIIZ * %MAX_PATH + 1
    InitialProgram                   AS ASCIIZ * %MAX_PATH + 1
    ApplicationName                  AS ASCIIZ * %MAX_PATH + 1
END TYPE

'======================================================================
'=   WTS Session Information
'======================================================================
TYPE WTSINFOW
    State          AS WTS_CONNECTSTATE_CLASS_enum ' connection state (see enum)
    SessionId      AS DWORD              ' session id
    IncomingBytes  AS DWORD
    OutgoingBytes  AS DWORD
    IncomingFrames AS DWORD
    OutgoingFrames AS DWORD
    IncomingCompressedBytes AS DWORD
    OutgoingCompressedBytes AS DWORD
    WinStationName AS WSTRINGZ * %WINSTATIONNAME_LENGTH
    Domain         AS WSTRINGZ * %DOMAIN_LENGTH
    UserName       AS WSTRINGZ * %USERNAME_LENGTH+1 ' name of WinStation this session is
                                                    ' connected to
    ConnectTime    AS LARGE_INTEGER
    DisconnectTime AS LARGE_INTEGER
    LastInputTime  AS LARGE_INTEGER
    LogonTime      AS LARGE_INTEGER
    CurrentTime    AS LARGE_INTEGER

END TYPE

TYPE WTSINFOA
    State          AS WTS_CONNECTSTATE_CLASS_enum ' connection state (see enum)
    SessionId      AS DWORD              ' session id
    IncomingBytes  AS DWORD
    OutgoingBytes  AS DWORD
    IncomingFrames AS DWORD
    OutgoingFrames AS DWORD
    IncomingCompressedBytes AS DWORD
    OutgoingCompressedBytes AS DWORD
    WinStationName AS ASCIIZ * %WINSTATIONNAME_LENGTH
    Domain         AS ASCIIZ * %DOMAIN_LENGTH
    UserName       AS ASCIIZ * %USERNAME_LENGTH+1 ' name of WinStation this session is
                                                  ' connected to
    ConnectTime    AS LARGE_INTEGER
    DisconnectTime AS LARGE_INTEGER
    LastInputTime  AS LARGE_INTEGER
    LogonTime      AS LARGE_INTEGER
    CurrentTime    AS LARGE_INTEGER

END TYPE


'======================================================================
'=   WTS Extended Session State Flags
'======================================================================
%WTS_SESSIONSTATE_UNKNOWN    = &HFFFFFFFF???
%WTS_SESSIONSTATE_LOCK       = &H00000000
%WTS_SESSIONSTATE_UNLOCK     = &H00000001

'======================================================================
'=   WTS Extended Session Information
'======================================================================
TYPE WTSINFOEX_LEVEL1_W
    SessionId               AS DWORD
    SessionState            AS WTS_CONNECTSTATE_CLASS_enum
    SessionFlags            AS LONG
    WinStationName          AS WSTRINGZ * %WINSTATIONNAME_LENGTH + 1
    UserName                AS WSTRINGZ * %USERNAME_LENGTH + 1
    DomainName              AS WSTRINGZ * %DOMAIN_LENGTH + 1
    LogonTime               AS LARGE_INTEGER
    ConnectTime             AS LARGE_INTEGER
    DisconnectTime          AS LARGE_INTEGER
    LastInputTime           AS LARGE_INTEGER
    CurrentTime             AS LARGE_INTEGER
    IncomingBytes           AS DWORD
    OutgoingBytes           AS DWORD
    IncomingFrames          AS DWORD
    OutgoingFrames          AS DWORD
    IncomingCompressedBytes AS DWORD
    OutgoingCompressedBytes AS DWORD
END TYPE

TYPE WTSINFOEX_LEVEL1_A
    SessionId               AS DWORD
    SessionState            AS WTS_CONNECTSTATE_CLASS_enum
    SessionFlags            AS LONG
    WinStationName          AS ASCIIZ * %WINSTATIONNAME_LENGTH + 1
    UserName                AS ASCIIZ * %USERNAME_LENGTH + 1
    DomainName              AS ASCIIZ * %DOMAIN_LENGTH + 1
    LogonTime               AS LARGE_INTEGER
    ConnectTime             AS LARGE_INTEGER
    DisconnectTime          AS LARGE_INTEGER
    LastInputTime           AS LARGE_INTEGER
    CurrentTime             AS LARGE_INTEGER
    IncomingBytes           AS DWORD
    OutgoingBytes           AS DWORD
    IncomingFrames          AS DWORD
    OutgoingFrames          AS DWORD
    IncomingCompressedBytes AS DWORD
    OutgoingCompressedBytes AS DWORD
END TYPE

UNION WTSINFOEX_LEVEL_W
    WTSInfoExLevel1 AS WTSINFOEX_LEVEL1_W
END UNION

UNION WTSINFOEX_LEVEL_A
    WTSInfoExLevel1 AS WTSINFOEX_LEVEL1_A
END UNION

TYPE WTSINFOEXW
    Level AS DWORD
    Data  AS WTSINFOEX_LEVEL_W
END TYPE

TYPE WTSINFOEXA
    Level AS DWORD
    Data  AS WTSINFOEX_LEVEL_A
END TYPE


'======================================================================
'=   WTS Client Information
'======================================================================
TYPE WTSCLIENTW
    ClientName          AS WSTRINGZ * %CLIENTNAME_LENGTH + 1
    Domain              AS WSTRINGZ * %DOMAIN_LENGTH + 1
    UserName            AS WSTRINGZ * %USERNAME_LENGTH + 1
    WorkDirectory       AS WSTRINGZ * %MAX_PATH + 1
    InitialProgram      AS WSTRINGZ * %MAX_PATH + 1
    EncryptionLevel     AS BYTE      ' security level of encryption pd
    ClientAddressFamily AS DWORD
    ClientAddress(%CLIENTADDRESS_LENGTH) AS WORD
    HRes                AS WORD
    VRes                AS WORD
    ColorDepth          AS WORD
    ClientDirectory     AS WSTRINGZ * %MAX_PATH + 1
    ClientBuildNumber   AS DWORD
    ClientHardwareId    AS DWORD     ' client software serial number
    ClientProductId     AS WORD      ' client software product id
    OutBufCountHost     AS WORD      ' number of outbufs on host
    OutBufCountClient   AS WORD      ' number of outbufs on client
    OutBufLength        AS WORD      ' length of outbufs in bytes
    DeviceId            AS WSTRINGZ * %MAX_PATH + 1
END TYPE


'======================================================================
'=   WTS Client Information
'======================================================================
TYPE WTSCLIENTA
    ClientName          AS ASCIIZ * %CLIENTNAME_LENGTH + 1
    Domain              AS ASCIIZ * %DOMAIN_LENGTH + 1
    UserName            AS ASCIIZ * %USERNAME_LENGTH + 1
    WorkDirectory       AS ASCIIZ * %MAX_PATH + 1
    InitialProgram      AS ASCIIZ * %MAX_PATH + 1
    EncryptionLevel     AS BYTE      ' security level of encryption pd
    ClientAddressFamily AS DWORD
    ClientAddress(%CLIENTADDRESS_LENGTH) AS WORD
    HRes                AS WORD
    VRes                AS WORD
    ColorDepth          AS WORD
    ClientDirectory     AS ASCIIZ * %MAX_PATH + 1
    ClientBuildNumber   AS DWORD
    ClientHardwareId    AS DWORD     ' client software serial number
    ClientProductId     AS WORD      ' client software product id
    OutBufCountHost     AS WORD      ' number of outbufs on host
    OutBufCountClient   AS WORD      ' number of outbufs on client
    OutBufLength        AS WORD      ' length of outbufs in bytes
    DeviceId            AS ASCIIZ * %MAX_PATH + 1
END TYPE

'======================================================================
'=   WTS License Validation Information - Product Information
'======================================================================

%PRODUCTINFO_COMPANYNAME_LENGTH = 256
%PRODUCTINFO_PRODUCTID_LENGTH = 4

TYPE PRODUCT_INFOA
    CompanyName AS ASCIIZ * %PRODUCTINFO_COMPANYNAME_LENGTH
    ProductID   AS ASCIIZ * %PRODUCTINFO_PRODUCTID_LENGTH
END TYPE

TYPE PRODUCT_INFOW
    CompanyName AS WSTRINGZ * %PRODUCTINFO_COMPANYNAME_LENGTH
    ProductID   AS WSTRINGZ * %PRODUCTINFO_PRODUCTID_LENGTH
END TYPE

'======================================================================
'    WTS License Validation Information
'    This structure will be returned from WTSQuerySessionInformation
'    when the user queries for license validation information.
'======================================================================

%VALIDATIONINFORMATION_LICENSE_LENGTH = 16384 '16 Kb
%VALIDATIONINFORMATION_HARDWAREID_LENGTH = 20

TYPE WTS_VALIDATION_INFORMATIONA
    ProductInfo      AS PRODUCT_INFOA
    License(%VALIDATIONINFORMATION_LICENSE_LENGTH-1) AS BYTE
    LicenseLength    AS DWORD
    HardwareID(%VALIDATIONINFORMATION_HARDWAREID_LENGTH-1) AS BYTE
    HardwareIDLength AS DWORD
END TYPE

TYPE WTS_VALIDATION_INFORMATIONW
    ProductInfo      AS PRODUCT_INFOW
    License(%VALIDATIONINFORMATION_LICENSE_LENGTH-1) AS BYTE
    LicenseLength    AS DWORD
    HardwareID(%VALIDATIONINFORMATION_HARDWAREID_LENGTH-1) AS BYTE
    HardwareIDLength AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE WTSCONFIGINFO
    WTSCONFIGINFOW
END TYPE
TYPE PRODUCT_INFO
    PRODUCT_INFOW
END TYPE
TYPE WTS_VALIDATION_INFORMATION
    WTS_VALIDATION_INFORMATIONW
END TYPE
TYPE WTSINFO
    WTSINFOW
END TYPE
TYPE WTSINFOEX
    WTSINFOEXW
END TYPE
TYPE WTSINFOEX_LEVEL
    WTSINFOEX_LEVEL_W
END TYPE
TYPE WTSINFOEX_LEVEL1
    WTSINFOEX_LEVEL1_W
END TYPE
TYPE WTSCLIENT
    WTSCLIENTW
END TYPE
#ELSE
TYPE WTSCONFIGINFO
    WTSCONFIGINFOA
END TYPE
TYPE PRODUCT_INFO
    PRODUCT_INFOA
END TYPE
TYPE WTS_VALIDATION_INFORMATION
    WTS_VALIDATION_INFORMATIONA
END TYPE
TYPE WTSINFO
    WTSINFOA
END TYPE
TYPE WTSINFOEX
    WTSINFOEXA
END TYPE
TYPE WTSINFOEX_LEVEL
    WTSINFOEX_LEVEL_A
END TYPE
TYPE WTSINFOEX_LEVEL1
    WTSINFOEX_LEVEL1_A
END TYPE
TYPE WTSCLIENT
    WTSCLIENTA
END TYPE

#ENDIF


'======================================================================
'=   WTSQuerySessionInformation - (WTSClientAddress)
'======================================================================

TYPE WTS_CLIENT_ADDRESS
    AddressFamily AS DWORD ' AF_INET, AF_INET6, AF_IPX, AF_NETBIOS, AF_UNSPEC
    Address(19)   AS BYTE  ' client network address
END TYPE


'======================================================================
'=   WTSQuerySessionInformation - (WTSClientDisplay)
'======================================================================

TYPE WTS_CLIENT_DISPLAY
    HorizontalResolution AS DWORD  ' horizontal dimensions, in pixels
    VerticalResolution   AS DWORD  ' vertical dimensions, in pixels
    ColorDepth           AS DWORD  ' 1=16, 2=256, 4=64K, 8=16M
END TYPE


'======================================================================
'=   WTS_CONFIG_CLASS - WTSQueryUserConfig/WTSSetUserConfig
'======================================================================


MACRO WTS_CONFIG_CLASS_enum=LONG
ENUM WTS_CONFIG_CLASS SINGULAR
    'Initial program settings
    WTSUserConfigInitialProgram             ' string returned/expected
    WTSUserConfigWorkingDirectory           ' string returned/expected
    WTSUserConfigfInheritInitialProgram     ' DWORD returned/expected
    '
    WTSUserConfigfAllowLogonTerminalServer      'DWORD returned/expected
    'Timeout settings
    WTSUserConfigTimeoutSettingsConnections     'DWORD returned/expected
    WTSUserConfigTimeoutSettingsDisconnections  'DWORD returned/expected
    WTSUserConfigTimeoutSettingsIdle            'DWORD returned/expected
    'Client device settings
    WTSUserConfigfDeviceClientDrives        'DWORD returned/expected
    WTSUserConfigfDeviceClientPrinters          'DWORD returned/expected
    WTSUserConfigfDeviceClientDefaultPrinter    'DWORD returned/expected
    'Connection settings
    WTSUserConfigBrokenTimeoutSettings          'DWORD returned/expected
    WTSUserConfigReconnectSettings              'DWORD returned/expected
    'Modem settings
    WTSUserConfigModemCallbackSettings          'DWORD returned/expected
    WTSUserConfigModemCallbackPhoneNumber       ' string returned/expected
    'Shadow settings
    WTSUserConfigShadowingSettings              'DWORD returned/expected
    'User Profile settings
    WTSUserConfigTerminalServerProfilePath      ' string returned/expected
    'Terminal Server home directory
    WTSUserConfigTerminalServerHomeDir        ' string returned/expected
    WTSUserConfigTerminalServerHomeDirDrive     ' string returned/expected
    WTSUserConfigfTerminalServerRemoteHomeDir   ' DWORD 0:LOCAL 1:REMOTE

    WTSUserConfigUser                           ' returns WTSUSERCONFIG struct
END ENUM

MACRO WTS_CONFIG_SOURCE_enum=LONG
ENUM WTS_CONFIG_SOURCE SINGULAR
    WTSUserConfigSourceSAM
END ENUM

TYPE WTSUSERCONFIGA
    Source                        AS DWORD
    InheritInitialProgram         AS DWORD
    AllowLogonTerminalServer      AS DWORD
    TimeoutSettingsConnections    AS DWORD
    TimeoutSettingsDisconnections AS DWORD
    TimeoutSettingsIdle           AS DWORD
    DeviceClientDrives            AS DWORD
    DeviceClientPrinters          AS DWORD
    ClientDefaultPrinter          AS DWORD
    BrokenTimeoutSettings         AS DWORD
    ReconnectSettings             AS DWORD
    ShadowingSettings             AS DWORD
    TerminalServerRemoteHomeDir   AS DWORD
    InitialProgram                AS ASCIIZ * %MAX_PATH + 1
    WorkDirectory                 AS ASCIIZ * %MAX_PATH + 1
    TerminalServerProfilePath     AS ASCIIZ * %MAX_PATH + 1
    TerminalServerHomeDir         AS ASCIIZ * %MAX_PATH + 1
    TerminalServerHomeDirDrive    AS ASCIIZ * %WTS_DRIVE_LENGTH + 1
END TYPE

TYPE WTSUSERCONFIGW
    Source                        AS DWORD
    InheritInitialProgram         AS DWORD
    AllowLogonTerminalServer      AS DWORD
    TimeoutSettingsConnections    AS DWORD
    TimeoutSettingsDisconnections AS DWORD
    TimeoutSettingsIdle           AS DWORD
    DeviceClientDrives            AS DWORD
    DeviceClientPrinters          AS DWORD
    ClientDefaultPrinter          AS DWORD
    BrokenTimeoutSettings         AS DWORD
    ReconnectSettings             AS DWORD
    ShadowingSettings             AS DWORD
    TerminalServerRemoteHomeDir   AS DWORD
    InitialProgram                AS WSTRINGZ * %MAX_PATH + 1
    WorkDirectory                 AS WSTRINGZ * %MAX_PATH + 1
    TerminalServerProfilePath     AS WSTRINGZ * %MAX_PATH + 1
    TerminalServerHomeDir         AS WSTRINGZ * %MAX_PATH + 1
    TerminalServerHomeDirDrive    AS WSTRINGZ * %WTS_DRIVE_LENGTH + 1
END TYPE

#IF %DEF(%UNICODE)
TYPE WTSUSERCONFIG
    WTSUSERCONFIGW
END TYPE
#ELSE
TYPE WTSUSERCONFIG
    WTSUSERCONFIGA
END TYPE
#ENDIF


'======================================================================
'=   WTS_EVENT - Event flags for WTSWaitSystemEvent
'======================================================================

%WTS_EVENT_NONE         = &H00000000 ' return no event
%WTS_EVENT_CREATE       = &H00000001 ' new WinStation created
%WTS_EVENT_DELETE       = &H00000002 ' existing WinStation deleted
%WTS_EVENT_RENAME       = &H00000004 ' existing WinStation renamed
%WTS_EVENT_CONNECT      = &H00000008 ' WinStation connect to client
%WTS_EVENT_DISCONNECT   = &H00000010 ' WinStation logged on without
                                          '     client
%WTS_EVENT_LOGON        = &H00000020 ' user logged on to existing
                                          '     WinStation
%WTS_EVENT_LOGOFF       = &H00000040 ' user logged off from
                                          '     existing WinStation
%WTS_EVENT_STATECHANGE  = &H00000080 ' WinStation state change
%WTS_EVENT_LICENSE      = &H00000100 ' license state change
%WTS_EVENT_ALL          = &H7fffffff ' wait for all event types
%WTS_EVENT_FLUSH        = &H80000000??? ' unblock all waiters

'======================================================================
'=   Flags for HotkeyModifiers in WTSStartRemoteControlSession
'======================================================================

%REMOTECONTROL_KBDSHIFT_HOTKEY   = &H1    ' Shift key
%REMOTECONTROL_KBDCTRL_HOTKEY    = &H2    ' Ctrl key
%REMOTECONTROL_KBDALT_HOTKEY     = &H4    ' Alt key

'======================================================================
'=   WTS_VIRTUAL_CLASS - WTSVirtualChannelQuery
'======================================================================
MACRO WTS_VIRTUAL_CLASS_enum=LONG
ENUM WTS_VIRTUAL_CLASS SINGULAR
    WTSVirtualClientData   ' Virtual channel client module data
                           '     (C2H data)
    WTSVirtualFileHandle
END ENUM

'======================================================================
'=   WTSQuerySessionInformation - (WTSSessionAddress)
'======================================================================

TYPE WTS_SESSION_ADDRESS
    AddressFamily AS DWORD  ' AF_INET only.
    Address(19)   AS BYTE   ' client network address
END TYPE


'======================================================================
'=   Windows Terminal Server public APIs
'======================================================================

DECLARE FUNCTION WTSStopRemoteControlSession LIB "WtsApi32.dll" _
    ALIAS "WTSStopRemoteControlSession" ( _
    BYVAL LogonId AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSStartRemoteControlSessionW LIB "WtsApi32.dll" _
    ALIAS "WTSStartRemoteControlSessionW" ( _
    pTargetServerName     AS WSTRINGZ, _
    BYVAL TargetLogonId   AS DWORD, _
    BYVAL HotkeyVk        AS BYTE, _
    BYVAL HotkeyModifiers AS WORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSStartRemoteControlSessionA LIB "WtsApi32.dll" _
    ALIAS "WTSStartRemoteControlSessionA" ( _
    pTargetServerName     AS ASCIIZ, _
    BYVAL TargetLogonId   AS DWORD, _
    BYVAL HotkeyVk        AS BYTE, _
    BYVAL HotkeyModifiers AS WORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION WTSStartRemoteControlSession LIB "WtsApi32.dll" _
    ALIAS "WTSStartRemoteControlSessionW" ( _
    pTargetServerName     AS WSTRINGZ, _
    BYVAL TargetLogonId   AS DWORD, _
    BYVAL HotkeyVk        AS BYTE, _
    BYVAL HotkeyModifiers AS WORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION WTSStartRemoteControlSession LIB "WtsApi32.dll" _
    ALIAS "WTSStartRemoteControlSessionA" ( _
    pTargetServerName     AS ASCIIZ, _
    BYVAL TargetLogonId   AS DWORD, _
    BYVAL HotkeyVk        AS BYTE, _
    BYVAL HotkeyModifiers AS WORD _
    ) AS LONG  ' BOOL
#ENDIF

DECLARE FUNCTION WTSConnectSessionA LIB "WtsApi32.dll" _
    ALIAS "WTSConnectSessionA" ( _
    BYVAL LogonId       AS DWORD, _
    BYVAL TargetLogonId AS DWORD, _
    pPassword           AS ASCIIZ, _
    BYVAL bWait         AS LONG _  ' BOOL
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSConnectSessionW LIB "WtsApi32.dll" _
    ALIAS "WTSConnectSessionW" ( _
    BYVAL LogonId       AS DWORD, _
    BYVAL TargetLogonId AS DWORD, _
    pPassword           AS WSTRINGZ, _
    BYVAL bWait         AS LONG _  ' BOOL
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION WTSConnectSession LIB "WtsApi32.dll" _
    ALIAS "WTSConnectSessionW" ( _
    BYVAL LogonId       AS DWORD, _
    BYVAL TargetLogonId AS DWORD, _
    pPassword           AS WSTRINGZ, _
    BYVAL bWait         AS LONG _  ' BOOL
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION WTSConnectSession LIB "WtsApi32.dll" _
    ALIAS "WTSConnectSessionA" ( _
    BYVAL LogonId       AS DWORD, _
    BYVAL TargetLogonId AS DWORD, _
    pPassword           AS ASCIIZ, _
    BYVAL bWait         AS LONG _  ' BOOL
    ) AS LONG  ' BOOL
#ENDIF

DECLARE FUNCTION WTSEnumerateServersW LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateServersW" ( _
    pDomainName    AS WSTRINGZ, _
    BYVAL Reserved AS DWORD, _
    BYVAL Version  AS DWORD, _
    ppServerInfo   AS ANY, _  ' WTS_SERVER_INFOW PTR PTR
    pCount         AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSEnumerateServersA LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateServersA" ( _
    pDomainName    AS ASCIIZ, _
    BYVAL Reserved AS DWORD, _
    BYVAL Version  AS DWORD, _
    ppServerInfo   AS ANY, _  ' WTS_SERVER_INFOA PTR PTR
    pCount         AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION WTSEnumerateServers LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateServersW" ( _
    pDomainName    AS WSTRINGZ, _
    BYVAL Reserved AS DWORD, _
    BYVAL Version  AS DWORD, _
    ppServerInfo   AS ANY, _
    pCount         AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION WTSEnumerateServers LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateServersA" ( _
    pDomainName    AS ASCIIZ, _
    BYVAL Reserved AS DWORD, _
    BYVAL Version  AS DWORD, _
    ppServerInfo   AS ANY, _
    pCount         AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

'-------------------------------------------------

DECLARE FUNCTION WTSOpenServerW LIB "WtsApi32.dll" _
    ALIAS "WTSOpenServerW" ( _
    pServerName AS WSTRINGZ _
    ) AS DWORD  ' HANDLE

DECLARE FUNCTION WTSOpenServerA LIB "WtsApi32.dll" _
    ALIAS "WTSOpenServerA" ( _
    pServerName AS ASCIIZ _
    ) AS DWORD  ' HANDLE

DECLARE FUNCTION WTSOpenServerExW LIB "WtsApi32.dll" _
    ALIAS "WTSOpenServerExW" ( _
    pServerName AS WSTRINGZ _
    ) AS DWORD  ' HANDLE

DECLARE FUNCTION WTSOpenServerExA LIB "WtsApi32.dll" _
    ALIAS "WTSOpenServerExA" ( _
    pServerName AS ASCIIZ _
    ) AS DWORD  ' HANDLE

#IF %DEF(%UNICODE)
DECLARE FUNCTION WTSOpenServer LIB "WtsApi32.dll" _
    ALIAS "WTSOpenServerW" ( _
    pServerName AS WSTRINGZ _
    ) AS DWORD  ' HANDLE
DECLARE FUNCTION WTSOpenServerEx LIB "WtsApi32.dll" _
    ALIAS "WTSOpenServerExW" ( _
    pServerName AS WSTRINGZ _
    ) AS DWORD  ' HANDLE
#ELSE
DECLARE FUNCTION WTSOpenServer LIB "WtsApi32.dll" _
    ALIAS "WTSOpenServerA" ( _
    pServerName AS ASCIIZ _
    ) AS DWORD  ' HANDLE
DECLARE FUNCTION WTSOpenServerEx LIB "WtsApi32.dll" _
    ALIAS "WTSOpenServerExA" ( _
    pServerName AS ASCIIZ _
    ) AS DWORD  ' HANDLE
#ENDIF

'-------------------------------------------------

DECLARE SUB WTSCloseServer LIB "WtsApi32.dll" ALIAS "WTSCloseServer" ( _
    BYVAL hServer AS DWORD _  ' HANDLE
    )

'-------------------------------------------------

DECLARE FUNCTION WTSEnumerateSessionsW LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateSessionsW" ( _
    BYVAL hServer  AS DWORD, _  ' HANDLE
    BYVAL Reserved AS DWORD, _
    BYVAL Version  AS DWORD, _
    ppSessionInfo  AS ANY, _  ' WTS_SESSION_INFOW PTR PTR
    pCount         AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSEnumerateSessionsA LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateSessionsA" ( _
    BYVAL hServer  AS DWORD, _  ' HANDLE
    BYVAL Reserved AS DWORD, _
    BYVAL Version  AS DWORD, _
    ppSessionInfo  AS ANY, _  ' WTS_SESSION_INFOA PTR PTR
    pCount         AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSEnumerateSessionsExW LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateSessionsExW" ( _
    BYVAL hServer AS DWORD, _  ' HANDLE
    pLevel        AS DWORD, _
    BYVAL Filter  AS DWORD, _
    ppSessionInfo AS ANY, _  ' WTS_SESSION_INFO_1W PTR PTR
    pCount        AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSEnumerateSessionsExA LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateSessionsExA" ( _
    BYVAL hServer AS DWORD, _  ' HANDLE
    pLevel        AS DWORD, _
    BYVAL Filter  AS DWORD, _
    ppSessionInfo AS ANY, _  ' WTS_SESSION_INFO_1A PTR PTR
    pCount        AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION WTSEnumerateSessions LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateSessionsW" ( _
    BYVAL hServer  AS DWORD, _  ' HANDLE
    BYVAL Reserved AS DWORD, _
    BYVAL Version  AS DWORD, _
    ppSessionInfo  AS ANY, _  ' WTS_SESSION_INFOW PTR PTR
    pCount         AS DWORD _
    ) AS LONG  ' BOOL
DECLARE FUNCTION WTSEnumerateSessionsEx LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateSessionsExW" ( _
    BYVAL hServer AS DWORD, _  ' HANDLE
    pLevel        AS DWORD, _
    BYVAL Filter  AS DWORD, _
    ppSessionInfo AS ANY, _  ' WTS_SESSION_INFO_1W PTR PTR
    pCount        AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION WTSEnumerateSessions LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateSessionsA" ( _
    BYVAL hServer  AS DWORD, _  ' HANDLE
    BYVAL Reserved AS DWORD, _
    BYVAL Version  AS DWORD, _
    ppSessionInfo  AS ANY, _  ' WTS_SESSION_INFOA PTR PTR
    pCount         AS DWORD _
    ) AS LONG  ' BOOL
DECLARE FUNCTION WTSEnumerateSessionsEx LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateSessionsExA" ( _
    BYVAL hServer AS DWORD, _  ' HANDLE
    pLevel        AS DWORD, _
    BYVAL Filter  AS DWORD, _
    ppSessionInfo AS ANY, _  ' WTS_SESSION_INFO_1A PTR PTR
    pCount        AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

'-------------------------------------------------

DECLARE FUNCTION WTSEnumerateProcessesW LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateProcessesW" ( _
    BYVAL hServer  AS DWORD, _  ' HANDLE
    BYVAL Reserved AS DWORD, _
    BYVAL Version  AS DWORD, _
    ppProcessInfo  AS ANY, _  ' WTS_PROCESS_INFOW PTR PTR
    pCount         AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSEnumerateProcessesA LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateProcessesA" ( _
    BYVAL hServer  AS DWORD, _  ' HANDLE
    BYVAL Reserved AS DWORD, _
    BYVAL Version  AS DWORD, _
    ppProcessInfo  AS ANY, _  ' WTS_PROCESS_INFOA PTR PTR
    pCount         AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION WTSEnumerateProcesses LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateProcessesW" ( _
    BYVAL hServer  AS DWORD, _  ' HANDLE
    BYVAL Reserved AS DWORD, _
    BYVAL Version  AS DWORD, _
    ppProcessInfo  AS ANY, _  ' WTS_PROCESS_INFOW PTR PTR
    pCount         AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION WTSEnumerateProcesses LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateProcessesA" ( _
    BYVAL hServer  AS DWORD, _  ' HANDLE
    BYVAL Reserved AS DWORD, _
    BYVAL Version  AS DWORD, _
    ppProcessInfo  AS ANY, _  ' WTS_PROCESS_INFOA PTR PTR
    pCount         AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

'-------------------------------------------------

DECLARE FUNCTION WTSTerminateProcess LIB "WtsApi32.dll" _
    ALIAS "WTSTerminateProcess" ( _
    BYVAL hServer   AS DWORD, _
    BYVAL ProcessId AS DWORD, _
    BYVAL ExitCode  AS DWORD _
    ) AS LONG  ' BOOL


'-------------------------------------------------

DECLARE FUNCTION WTSQuerySessionInformationW LIB "WtsApi32.dll" _
    ALIAS "WTSQuerySessionInformationW" ( _
    BYVAL hServer      AS DWORD, _  ' HANDLE
    BYVAL SessionId    AS DWORD, _
    BYVAL WTSInfoClass AS WTS_INFO_CLASS_enum, _
    ppBuffer           AS ANY, _  ' WSTRINGZ PTR PTR
    pBytesReturned     AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSQuerySessionInformationA LIB "WtsApi32.dll" _
    ALIAS "WTSQuerySessionInformationA" ( _
    BYVAL hServer      AS DWORD, _  ' HANDLE
    BYVAL SessionId    AS DWORD, _
    BYVAL WTSInfoClass AS WTS_INFO_CLASS_enum, _
    ppBuffer           AS ANY, _  ' ASCIIZ PTR PTR
    pBytesReturned     AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION WTSQuerySessionInformation LIB "WtsApi32.dll" _
    ALIAS "WTSQuerySessionInformationW" ( _
    BYVAL hServer      AS DWORD, _  ' HANDLE
    BYVAL SessionId    AS DWORD, _
    BYVAL WTSInfoClass AS WTS_INFO_CLASS_enum, _
    ppBuffer           AS ANY, _  ' WSTRINGZ PTR PTR
    pBytesReturned     AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION WTSQuerySessionInformation LIB "WtsApi32.dll" _
    ALIAS "WTSQuerySessionInformationA" ( _
    BYVAL hServer      AS DWORD, _  ' HANDLE
    BYVAL SessionId    AS DWORD, _
    BYVAL WTSInfoClass AS WTS_INFO_CLASS_enum, _
    ppBuffer           AS ANY, _  ' ASCIIZ PTR PTR
    pBytesReturned     AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

'-------------------------------------------------

DECLARE FUNCTION WTSQueryUserConfigW LIB "WtsApi32.dll" _
    ALIAS "WTSQueryUserConfigW" ( _
    pServerName          AS WSTRINGZ, _
    pUserName            AS WSTRINGZ, _
    BYVAL WTSConfigClass AS WTS_CONFIG_CLASS_enum, _
    ppBuffer             AS ANY, _  ' LPWSTR *
    pBytesReturned       AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSQueryUserConfigA LIB "WtsApi32.dll" _
    ALIAS "WTSQueryUserConfigA" ( _
    pServerName          AS ASCIIZ, _
    pUserName            AS ASCIIZ, _
    BYVAL WTSConfigClass AS WTS_CONFIG_CLASS_enum, _
    ppBuffer             AS ANY, _  ' LPSTR *
    pBytesReturned       AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION WTSQueryUserConfig LIB "WtsApi32.dll" _
    ALIAS "WTSQueryUserConfigW" ( _
    pServerName          AS WSTRINGZ, _
    pUserName            AS WSTRINGZ, _
    BYVAL WTSConfigClass AS WTS_CONFIG_CLASS_enum, _
    ppBuffer             AS ANY, _  ' LPWSTR *
    pBytesReturned       AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION WTSQueryUserConfig LIB "WtsApi32.dll" _
    ALIAS "WTSQueryUserConfigA" ( _
    pServerName          AS ASCIIZ, _
    pUserName            AS ASCIIZ, _
    BYVAL WTSConfigClass AS WTS_CONFIG_CLASS_enum, _
    ppBuffer             AS ANY, _  ' LPSTR *
    pBytesReturned       AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

'-------------------------------------------------

DECLARE FUNCTION WTSSetUserConfigW LIB "WtsApi32.dll" _
    ALIAS "WTSSetUserConfigW" ( _
    pServerName          AS WSTRINGZ, _
    pUserName            AS WSTRINGZ, _
    BYVAL WTSConfigClass AS WTS_CONFIG_CLASS_enum, _
    pBuffer              AS WSTRINGZ, _
    BYVAL DataLength     AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSSetUserConfigA LIB "WtsApi32.dll" _
    ALIAS "WTSSetUserConfigA" ( _
    pServerName          AS ASCIIZ, _
    pUserName            AS ASCIIZ, _
    BYVAL WTSConfigClass AS WTS_CONFIG_CLASS_enum, _
    pBuffer              AS ASCIIZ, _
    BYVAL DataLength     AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION WTSSetUserConfig LIB "WtsApi32.dll" _
    ALIAS "WTSSetUserConfigW" ( _
    pServerName          AS WSTRINGZ, _
    pUserName            AS WSTRINGZ, _
    BYVAL WTSConfigClass AS WTS_CONFIG_CLASS_enum, _
    pBuffer              AS WSTRINGZ, _
    BYVAL DataLength     AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION WTSSetUserConfig LIB "WtsApi32.dll" _
    ALIAS "WTSSetUserConfigA" ( _
    pServerName          AS ASCIIZ, _
    pUserName            AS ASCIIZ, _
    BYVAL WTSConfigClass AS WTS_CONFIG_CLASS_enum, _
    pBuffer              AS ASCIIZ, _
    BYVAL DataLength     AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

'-------------------------------------------------

DECLARE FUNCTION WTSSendMessageW LIB "WtsApi32.dll" _
    ALIAS "WTSSendMessageW" ( _
    BYVAL hServer       AS DWORD, _  ' HANDLE
    BYVAL SessionId     AS DWORD, _
    pTitle              AS WSTRINGZ, _
    BYVAL TitleLength   AS DWORD, _
    pMessage            AS WSTRINGZ, _
    BYVAL MessageLength AS DWORD, _
    BYVAL Style         AS DWORD, _
    BYVAL Timeout       AS DWORD, _
    pResponse           AS DWORD, _
    BYVAL bWait         AS LONG _  ' BOOL
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSSendMessageA LIB "WtsApi32.dll" _
    ALIAS "WTSSendMessageA" ( _
    BYVAL hServer       AS DWORD, _  ' HANDLE
    BYVAL SessionId     AS DWORD, _
    pTitle              AS ASCIIZ, _
    BYVAL TitleLength   AS DWORD, _
    pMessage            AS ASCIIZ, _
    BYVAL MessageLength AS DWORD, _
    BYVAL Style         AS DWORD, _
    BYVAL Timeout       AS DWORD, _
    pResponse           AS DWORD, _
    BYVAL bWait         AS LONG _  ' BOOL
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION WTSSendMessage LIB "WtsApi32.dll" _
    ALIAS "WTSSendMessageW" ( _
    BYVAL hServer       AS DWORD, _  ' HANDLE
    BYVAL SessionId     AS DWORD, _
    pTitle              AS WSTRINGZ, _
    BYVAL TitleLength   AS DWORD, _
    pMessage            AS WSTRINGZ, _
    BYVAL MessageLength AS DWORD, _
    BYVAL Style         AS DWORD, _
    BYVAL Timeout       AS DWORD, _
    pResponse           AS DWORD, _
    BYVAL bWait         AS LONG _  ' BOOL
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION WTSSendMessage LIB "WtsApi32.dll" _
    ALIAS "WTSSendMessageA" ( _
    BYVAL hServer       AS DWORD, _  ' HANDLE
    BYVAL SessionId     AS DWORD, _
    pTitle              AS ASCIIZ, _
    BYVAL TitleLength   AS DWORD, _
    pMessage            AS ASCIIZ, _
    BYVAL MessageLength AS DWORD, _
    BYVAL Style         AS DWORD, _
    BYVAL Timeout       AS DWORD, _
    pResponse           AS DWORD, _
    BYVAL bWait         AS LONG _  ' BOOL
    ) AS LONG  ' BOOL
#ENDIF

'-------------------------------------------------

DECLARE FUNCTION WTSDisconnectSession LIB "WtsApi32.dll" _
    ALIAS "WTSDisconnectSession" ( _
    BYVAL hServer   AS DWORD, _  ' HANDLE
    BYVAL SessionId AS DWORD, _
    BYVAL bWait     AS LONG _
    ) AS LONG  ' BOOL

'-------------------------------------------------

DECLARE FUNCTION WTSLogoffSession LIB "WtsApi32.dll" _
    ALIAS "WTSLogoffSession" ( _
    BYVAL hServer   AS DWORD, _  ' HANDLE
    BYVAL SessionId AS DWORD, _
    BYVAL bWait     AS LONG _
    ) AS LONG  ' BOOL

'-------------------------------------------------

DECLARE FUNCTION WTSShutdownSystem LIB "WtsApi32.dll" _
    ALIAS "WTSShutdownSystem" ( _
    BYVAL hServer      AS DWORD, _  ' HANDLE
    BYVAL ShutdownFlag AS DWORD _
    ) AS LONG  ' BOOL

'-------------------------------------------------

DECLARE FUNCTION WTSWaitSystemEvent LIB "WtsApi32.dll" _
    ALIAS "WTSWaitSystemEvent" ( _
    BYVAL hServer   AS DWORD, _  ' HANDLE
    BYVAL EventMask AS DWORD, _
    pEventFlags     AS DWORD _
    ) AS LONG  ' BOOL

'-------------------------------------------------

DECLARE FUNCTION WTSVirtualChannelOpen LIB "WtsApi32.dll" _
    ALIAS "WTSVirtualChannelOpen" ( _
    BYVAL hServer   AS DWORD, _  ' HANDLE
    BYVAL SessionId AS DWORD, _
    pVirtualName    AS ASCIIZ _   ' ascii name
    ) AS DWORD  ' HANDLE

%WTS_CHANNEL_OPTION_DYNAMIC             = &H00000001   ' dynamic channel
%WTS_CHANNEL_OPTION_DYNAMIC_PRI_LOW     = &H00000000   ' priorities
%WTS_CHANNEL_OPTION_DYNAMIC_PRI_MED     = &H00000002
%WTS_CHANNEL_OPTION_DYNAMIC_PRI_HIGH    = &H00000004
%WTS_CHANNEL_OPTION_DYNAMIC_PRI_REAL    = &H00000006
%WTS_CHANNEL_OPTION_DYNAMIC_NO_COMPRESS = &H00000008

DECLARE FUNCTION WTSVirtualChannelOpenEx LIB "WtsApi32.dll" _
    ALIAS "WTSVirtualChannelOpenEx" ( _
    BYVAL SessionId AS DWORD, _
    pVirtualName    AS ASCIIZ, _   ' ascii name
    BYVAL flags     AS DWORD _
    ) AS DWORD  ' HANDLE

DECLARE FUNCTION WTSVirtualChannelClose LIB "WtsApi32.dll" _
    ALIAS "WTSVirtualChannelClose" ( _
    BYVAL hChannelHandle AS DWORD _  ' HANDLE
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSVirtualChannelRead LIB "WtsApi32.dll" _
    ALIAS "WTSVirtualChannelRead" ( _
    BYVAL hChannelHandle AS DWORD, _  ' HANDLE
    BYVAL TimeOut        AS DWORD, _
    BYVAL Buffer         AS BYTE PTR, _
    BYVAL BufferSize     AS DWORD, _
    pBytesRead           AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSVirtualChannelWrite LIB "WtsApi32.dll" _
    ALIAS "WTSVirtualChannelWrite" ( _
    BYVAL hChannelHandle AS DWORD, _  ' HANDLE
    BYVAL Buffer         AS BYTE PTR, _
    BYVAL Length         AS DWORD, _
    pBytesWritten        AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSVirtualChannelPurgeInput LIB "WtsApi32.dll" _
    ALIAS "WTSVirtualChannelPurgeInput" ( _
    BYVAL hChannelHandle AS DWORD _  ' HANDLE
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSVirtualChannelPurgeOutput LIB "WtsApi32.dll" _
    ALIAS "WTSVirtualChannelPurgeOutput" ( _
    BYVAL hChannelHandle AS DWORD _  ' HANDLE
    ) AS LONG  ' BOOL


DECLARE FUNCTION WTSVirtualChannelQuery LIB "WtsApi32.dll" _
    ALIAS "WTSVirtualChannelQuery" ( _
    BYVAL hChannelHandle AS DWORD, _  ' HANDLE
    BYVAL WtsVirualClass AS WTS_VIRTUAL_CLASS_enum, _
    ppBuffer             AS ANY, _
    pBytesReturned       AS DWORD _
    ) AS LONG  ' BOOL

'-------------------------------------------------


DECLARE SUB WTSFreeMemory LIB "WtsApi32.dll" ALIAS "WTSFreeMemory" ( _
    BYVAL pMemory AS DWORD _
    )

' Flags for Console Notification

%NOTIFY_FOR_ALL_SESSIONS   = 1
%NOTIFY_FOR_THIS_SESSION   = 0


DECLARE FUNCTION WTSRegisterSessionNotification LIB "WtsApi32.dll" _
    ALIAS "WTSRegisterSessionNotification" ( _
    BYVAL hWnd    AS DWORD, _  ' HWND
    BYVAL dwFlags AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSUnRegisterSessionNotification LIB "WtsApi32.dll" _
    ALIAS "WTSUnRegisterSessionNotification" ( _
    BYVAL hWnd AS DWORD _  ' HWND
    ) AS LONG  ' BOOL


DECLARE FUNCTION WTSRegisterSessionNotificationEx LIB "WtsApi32.dll" _
    ALIAS "WTSRegisterSessionNotificationEx" ( _
    BYVAL hServer AS DWORD, _  ' HANDLE
    BYVAL hWnd    AS DWORD, _  ' HWND
    BYVAL dwFlags AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSUnRegisterSessionNotificationEx LIB "WtsApi32.dll" _
    ALIAS "WTSUnRegisterSessionNotificationEx" ( _
    BYVAL hServer AS DWORD, _  ' HANDLE
    BYVAL hWnd    AS DWORD _   ' HWND
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSQueryUserToken LIB "WtsApi32.dll" _
    ALIAS "WTSQueryUserToken" ( _
    BYVAL SessionId AS DWORD, _
    phToken         AS DWORD _  HANDLE PTR
    ) AS LONG  ' BOOL

%WTS_PROCESS_INFO_LEVEL_0 = 0
%WTS_PROCESS_INFO_LEVEL_1 = 1

'
'   WTS_PROCESS_INFO_EX - returned by WTSEnumerateProcessesEX
'

TYPE WTS_PROCESS_INFO_EXW
    SessionId          AS DWORD
    ProcessId          AS DWORD
    pProcessName       AS WSTRINGZ PTR
    pUserSid           AS SID PTR
    NumberOfThreads    AS DWORD
    HandleCount        AS DWORD
    PagefileUsage      AS DWORD
    PeakPagefileUsage  AS DWORD
    WorkingSetSize     AS DWORD
    PeakWorkingSetSize AS DWORD
    UserTime           AS LARGE_INTEGER
    KernelTime         AS LARGE_INTEGER
END TYPE

TYPE WTS_PROCESS_INFO_EXA
    SessionId          AS DWORD
    ProcessId          AS DWORD
    pProcessName       AS ASCIIZ PTR
    pUserSid           AS SID PTR
    NumberOfThreads    AS DWORD
    HandleCount        AS DWORD
    PagefileUsage      AS DWORD
    PeakPagefileUsage  AS DWORD
    WorkingSetSize     AS DWORD
    PeakWorkingSetSize AS DWORD
    UserTime           AS LARGE_INTEGER
    KernelTime         AS LARGE_INTEGER
END TYPE

#IF %DEF(%UNICODE)
TYPE WTS_PROCESS_INFO_EX
    WTS_PROCESS_INFO_EXW
END TYPE
#ELSE
TYPE WTS_PROCESS_INFO_EX
    WTS_PROCESS_INFO_EXA
END TYPE
#ENDIF

'-------------------------------------------------

MACRO WTS_TYPE_CLASS_enum=LONG
ENUM WTS_TYPE_CLASS SINGULAR
    WTSTypeProcessInfoLevel0
    WTSTypeProcessInfoLevel1
    WTSTypeSessionInfoLevel1
END ENUM

DECLARE FUNCTION WTSFreeMemoryExW LIB "WtsApi32.dll" _
    ALIAS "WTSFreeMemoryExW" ( _
    BYVAL WTSTypeClass    AS WTS_TYPE_CLASS_enum, _
    BYVAL pMemory         AS DWORD, _
    BYVAL NumberOfEntries AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSFreeMemoryExA LIB "WtsApi32.dll" _
    ALIAS "WTSFreeMemoryExA" ( _
    BYVAL WTSTypeClass    AS WTS_TYPE_CLASS_enum, _
    BYVAL pMemory         AS DWORD, _
    BYVAL NumberOfEntries AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION WTSFreeMemoryEx LIB "WtsApi32.dll" _
    ALIAS "WTSFreeMemoryExW" ( _
    BYVAL WTSTypeClass    AS WTS_TYPE_CLASS_enum, _
    BYVAL pMemory         AS DWORD, _
    BYVAL NumberOfEntries AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION WTSFreeMemoryEx LIB "WtsApi32.dll" _
    ALIAS "WTSFreeMemoryExA" ( _
    BYVAL WTSTypeClass    AS WTS_TYPE_CLASS_enum, _
    BYVAL pMemory         AS DWORD, _
    BYVAL NumberOfEntries AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

'-------------------------------------------------

DECLARE FUNCTION WTSEnumerateProcessesExW LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateProcessesExW" ( _
    BYVAL hServer   AS DWORD, _  ' HANDLE
    pLevel          AS DWORD, _
    BYVAL SessionId AS DWORD, _
    ppProcessInfo   AS ANY, _  ' LPWSTR *
    pCount          AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSEnumerateProcessesExA LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateProcessesExA" ( _
    BYVAL hServer   AS DWORD, _  ' HANDLE
    pLevel          AS DWORD, _
    BYVAL SessionId AS DWORD, _
    ppProcessInfo   AS ANY, _  ' LPSTR *
    pCount          AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION WTSEnumerateProcessesEx LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateProcessesExW" ( _
    BYVAL hServer   AS DWORD, _  ' HANDLE
    pLevel          AS DWORD, _
    BYVAL SessionId AS DWORD, _
    ppProcessInfo   AS ANY, _  ' LPWSTR *
    pCount          AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION WTSEnumerateProcessesEx LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateProcessesExA" ( _
    BYVAL hServer   AS DWORD, _  ' HANDLE
    pLevel          AS DWORD, _
    BYVAL SessionId AS DWORD, _
    ppProcessInfo   AS ANY, _  ' LPSTR *
    pCount          AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


'-------------------------------------------------
' Listener management APIs

MACRO WTSLISTENERNAMEW=WSTRINGZ * %WTS_LISTENER_NAME_LENGTH + 1
MACRO WTSLISTENERNAMEA=ASCIIZ * %WTS_LISTENER_NAME_LENGTH + 1

#IF %DEF(%UNICODE)
MACRO WTSLISTENERNAME=WTSLISTENERNAMEW
#ELSE
MACRO WTSLISTENERNAME=WTSLISTENERNAMEA
#ENDIF

DECLARE FUNCTION WTSEnumerateListenersW LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateListenersW" ( _
    BYVAL hServer    AS DWORD, _  ' HANDLE
    BYVAL pReserved  AS DWORD, _  ' PVOID
    BYVAL Reserved   AS DWORD, _
    BYVAL pListeners AS DWORD, _  ' WTSLISTENERNAMEW PTR
    pCount           AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSEnumerateListenersA LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateListenersA" ( _
    BYVAL hServer    AS DWORD, _  ' HANDLE
    BYVAL pReserved  AS DWORD, _  ' PVOID
    BYVAL Reserved   AS DWORD, _
    BYVAL pListeners AS DWORD, _  ' WTSLISTENERNAMEA PTR
    pCount           AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION WTSEnumerateListeners LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateListenersW" ( _
    BYVAL hServer    AS DWORD, _  ' HANDLE
    BYVAL pReserved  AS DWORD, _  ' PVOID
    BYVAL Reserved   AS DWORD, _
    BYVAL pListeners AS DWORD, _  ' WTSLISTENERNAMEW PTR
    pCount           AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION WTSEnumerateListeners LIB "WtsApi32.dll" _
    ALIAS "WTSEnumerateListenersA" ( _
    BYVAL hServer    AS DWORD, _  ' HANDLE
    BYVAL pReserved  AS DWORD, _  ' PVOID
    BYVAL Reserved   AS DWORD, _
    BYVAL pListeners AS DWORD, _  ' WTSLISTENERNAMEA PTR
    pCount           AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

'---------------------------------------------------
' Listener Config, used by WTSQueryListenerConfig and WTSCreateListener

TYPE WTSLISTENERCONFIGW
    version                          AS DWORD
    fEnableListener                  AS DWORD
    MaxConnectionCount               AS DWORD
    fPromptForPassword               AS DWORD
    fInheritColorDepth               AS DWORD
    ColorDepth                       AS DWORD
    fInheritBrokenTimeoutSettings    AS DWORD
    BrokenTimeoutSettings            AS DWORD

    fDisablePrinterRedirection       AS DWORD
    fDisableDriveRedirection         AS DWORD
    fDisableComPortRedirection       AS DWORD
    fDisableLPTPortRedirection       AS DWORD
    fDisableClipboardRedirection     AS DWORD
    fDisableAudioRedirection         AS DWORD
    fDisablePNPRedirection           AS DWORD
    fDisableDefaultMainClientPrinter AS DWORD

    LanAdapter                       AS DWORD
    PortNumber                       AS DWORD

    fInheritShadowSettings           AS DWORD
    ShadowSettings                   AS DWORD

    TimeoutSettingsConnection        AS DWORD
    TimeoutSettingsDisconnection     AS DWORD
    TimeoutSettingsIdle              AS DWORD

    SecurityLayer                    AS DWORD
    MinEncryptionLevel               AS DWORD
    UserAuthentication               AS DWORD

    Comment                          AS WSTRINGZ * %WTS_COMMENT_LENGTH + 1
    LogonUserName                    AS WSTRINGZ * %USERNAME_LENGTH + 1
    LogonDomain                      AS WSTRINGZ * %DOMAIN_LENGTH + 1

    WorkDirectory                    AS WSTRINGZ * %MAX_PATH + 1
    InitialProgram                   AS WSTRINGZ * %MAX_PATH + 1
END TYPE

TYPE WTSLISTENERCONFIGA
    version                          AS DWORD
    fEnableListener                  AS DWORD
    MaxConnectionCount               AS DWORD
    fPromptForPassword               AS DWORD
    fInheritColorDepth               AS DWORD
    ColorDepth                       AS DWORD
    fInheritBrokenTimeoutSettings    AS DWORD
    BrokenTimeoutSettings            AS DWORD

    fDisablePrinterRedirection       AS DWORD
    fDisableDriveRedirection         AS DWORD
    fDisableComPortRedirection       AS DWORD
    fDisableLPTPortRedirection       AS DWORD
    fDisableClipboardRedirection     AS DWORD
    fDisableAudioRedirection         AS DWORD
    fDisablePNPRedirection           AS DWORD
    fDisableDefaultMainClientPrinter AS DWORD

    LanAdapter                       AS DWORD
    PortNumber                       AS DWORD

    fInheritShadowSettings           AS DWORD
    ShadowSettings                   AS DWORD

    TimeoutSettingsConnection        AS DWORD
    TimeoutSettingsDisconnection     AS DWORD
    TimeoutSettingsIdle              AS DWORD

    SecurityLayer                    AS DWORD
    MinEncryptionLevel               AS DWORD
    UserAuthentication               AS DWORD

    Comment                          AS ASCIIZ * %WTS_COMMENT_LENGTH + 1
    LogonUserName                    AS ASCIIZ * %USERNAME_LENGTH + 1
    LogonDomain                      AS ASCIIZ * %DOMAIN_LENGTH + 1

    WorkDirectory                    AS ASCIIZ * %MAX_PATH + 1
    InitialProgram                   AS ASCIIZ * %MAX_PATH + 1
END TYPE

DECLARE FUNCTION WTSQueryListenerConfigW LIB "WtsApi32.dll" _
    ALIAS "WTSQueryListenerConfigW" ( _
    BYVAL hServer   AS DWORD, _  ' HANDLE
    BYVAL pReserved AS DWORD, _  ' PVOID
    BYVAL Reserved  AS DWORD, _
    pListenerName   AS WSTRINGZ, _
    pBuffer         AS WTSLISTENERCONFIGW _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSQueryListenerConfigA LIB "WtsApi32.dll" _
    ALIAS "WTSQueryListenerConfigA" ( _
    BYVAL hServer   AS DWORD, _  ' HANDLE
    BYVAL pReserved AS DWORD, _  ' PVOID
    BYVAL Reserved  AS DWORD, _
    pListenerName   AS ASCIIZ, _
    pBuffer         AS WTSLISTENERCONFIGA _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSCreateListenerW LIB "WtsApi32.dll" _
    ALIAS "WTSCreateListenerW" ( _
    BYVAL hServer   AS DWORD, _  ' HANDLE
    BYVAL pReserved AS DWORD, _  ' PVOID
    BYVAL Reserved  AS DWORD, _
    pListenerName   AS WSTRINGZ, _
    pBuffer         AS WTSLISTENERCONFIGW, _
    BYVAL flag      AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSCreateListenerA LIB "WtsApi32.dll" _
    ALIAS "WTSCreateListenerA" ( _
    BYVAL hServer   AS DWORD, _  ' HANDLE
    BYVAL pReserved AS DWORD, _  ' PVOID
    BYVAL Reserved  AS DWORD, _
    pListenerName   AS ASCIIZ, _
    pBuffer         AS WTSLISTENERCONFIGA, _
    BYVAL flag      AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSSetListenerSecurityW LIB "WtsApi32.dll" _
    ALIAS "WTSSetListenerSecurityW" ( _
    BYVAL hServer       AS DWORD, _  ' HANDLE
    BYVAL pReserved     AS DWORD, _  ' PVOID
    BYVAL Reserved      AS DWORD, _
    pListenerName       AS WSTRINGZ, _
    SecurityInformation AS SECURITY_INFORMATION, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSSetListenerSecurityA LIB "WtsApi32.dll" _
    ALIAS "WTSSetListenerSecurityA" ( _
    BYVAL hServer       AS DWORD, _  ' HANDLE
    BYVAL pReserved     AS DWORD, _  ' PVOID
    BYVAL Reserved      AS DWORD, _
    pListenerName       AS ASCIIZ, _
    SecurityInformation AS SECURITY_INFORMATION, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION WTSGetListenerSecurityW LIB "WtsApi32.dll" _
    ALIAS "WTSGetListenerSecurityW" ( _
    BYVAL hServer       AS DWORD, _  ' HANDLE
    BYVAL pReserved     AS DWORD, _  ' PVOID
    BYVAL Reserved      AS DWORD, _
    pListenerName       AS WSTRINGZ, _
    SecurityInformation AS SECURITY_INFORMATION, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    BYVAL nLength       AS DWORD, _
    lpnLengthNeeded     AS DWORD _
    ) AS LONG  ' BOOL


DECLARE FUNCTION WTSGetListenerSecurityA LIB "WtsApi32.dll" _
    ALIAS "WTSGetListenerSecurityA" ( _
    BYVAL hServer       AS DWORD, _  ' HANDLE
    BYVAL pReserved     AS DWORD, _  ' PVOID
    BYVAL Reserved      AS DWORD, _
    pListenerName       AS ASCIIZ, _
    SecurityInformation AS SECURITY_INFORMATION, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    BYVAL nLength       AS DWORD, _
    lpnLengthNeeded     AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
TYPE WTSLISTENERCONFIG
    WTSLISTENERCONFIGW
END TYPE
DECLARE FUNCTION WTSQueryListenerConfig LIB "WtsApi32.dll" _
    ALIAS "WTSQueryListenerConfigW" ( _
    BYVAL hServer   AS DWORD, _  ' HANDLE
    BYVAL pReserved AS DWORD, _  ' PVOID
    BYVAL Reserved  AS DWORD, _
    pListenerName   AS WSTRINGZ, _
    pBuffer         AS WTSLISTENERCONFIGW _
    ) AS LONG  ' BOOL
DECLARE FUNCTION WTSCreateListener LIB "WtsApi32.dll" _
    ALIAS "WTSCreateListenerW" ( _
    BYVAL hServer   AS DWORD, _  ' HANDLE
    BYVAL pReserved AS DWORD, _  ' PVOID
    BYVAL Reserved  AS DWORD, _
    pListenerName   AS WSTRINGZ, _
    pBuffer         AS WTSLISTENERCONFIGW, _
    BYVAL flag      AS DWORD _
    ) AS LONG  ' BOOL
DECLARE FUNCTION WTSSetListenerSecurity LIB "WtsApi32.dll" _
    ALIAS "WTSSetListenerSecurityW" ( _
    BYVAL hServer       AS DWORD, _  ' HANDLE
    BYVAL pReserved     AS DWORD, _  ' PVOID
    BYVAL Reserved      AS DWORD, _
    pListenerName       AS WSTRINGZ, _
    SecurityInformation AS SECURITY_INFORMATION, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR _
    ) AS LONG  ' BOOL
DECLARE FUNCTION WTSGetListenerSecurity LIB "WtsApi32.dll" _
    ALIAS "WTSGetListenerSecurityW" ( _
    BYVAL hServer       AS DWORD, _  ' HANDLE
    BYVAL pReserved     AS DWORD, _  ' PVOID
    BYVAL Reserved      AS DWORD, _
    pListenerName       AS WSTRINGZ, _
    SecurityInformation AS SECURITY_INFORMATION, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    BYVAL nLength       AS DWORD, _
    lpnLengthNeeded     AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
TYPE WTSLISTENERCONFIG
    WTSLISTENERCONFIGA
END TYPE
DECLARE FUNCTION WTSQueryListenerConfig LIB "WtsApi32.dll" _
    ALIAS "WTSQueryListenerConfigA" ( _
    BYVAL hServer   AS DWORD, _  ' HANDLE
    BYVAL pReserved AS DWORD, _  ' PVOID
    BYVAL Reserved  AS DWORD, _
    pListenerName   AS ASCIIZ, _
    pBuffer         AS WTSLISTENERCONFIGA _
    ) AS LONG  ' BOOL
DECLARE FUNCTION WTSCreateListener LIB "WtsApi32.dll" _
    ALIAS "WTSCreateListenerA" ( _
    BYVAL hServer   AS DWORD, _  ' HANDLE
    BYVAL pReserved AS DWORD, _  ' PVOID
    BYVAL Reserved  AS DWORD, _
    pListenerName   AS ASCIIZ, _
    pBuffer         AS WTSLISTENERCONFIGA, _
    BYVAL flag      AS DWORD _
    ) AS LONG  ' BOOL
DECLARE FUNCTION WTSSetListenerSecurity LIB "WtsApi32.dll" _
    ALIAS "WTSSetListenerSecurityA" ( _
    BYVAL hServer       AS DWORD, _  ' HANDLE
    BYVAL pReserved     AS DWORD, _  ' PVOID
    BYVAL Reserved      AS DWORD, _
    pListenerName       AS ASCIIZ, _
    SecurityInformation AS SECURITY_INFORMATION, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR _
    ) AS LONG  ' BOOL
DECLARE FUNCTION WTSGetListenerSecurity LIB "WtsApi32.dll" _
    ALIAS "WTSGetListenerSecurityA" ( _
    BYVAL hServer       AS DWORD, _  ' HANDLE
    BYVAL pReserved     AS DWORD, _  ' PVOID
    BYVAL Reserved      AS DWORD, _
    pListenerName       AS ASCIIZ, _
    SecurityInformation AS SECURITY_INFORMATION, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    BYVAL nLength       AS DWORD, _
    lpnLengthNeeded     AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF
