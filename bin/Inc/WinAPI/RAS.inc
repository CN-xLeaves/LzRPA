'------------------------------------------------------------------------------
'
'  RAS.inc -- Remote Access external API
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from RAS.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%RAS_H = 1

#INCLUDE "lmcons.inc"

' To use Quarantine APIs, applications should explicitly
' define USES_RAS_QUARANTINE_APIS.
#IF %DEF(%USES_RAS_QUARANTINE_APIS)
#INCLUDE "naptypes.inc"

%RASNAP_ProbationTime  = &H00000001

TYPE RASNAPSTATE
    dwSize         AS DWORD
    dwFlags        AS DWORD
    isolationState AS IsolationState_enum
    probationTime  AS FILETIME  ' ProbationTime
END TYPE
#ENDIF ' USES_RAS_QUARANTINE_APIS

#INCLUDE "inaddr.inc"
#INCLUDE "in6addr.inc"

' RAS API Version
'
MACRO RASAPIVERSION_enum=LONG
ENUM RASAPIVERSION SINGULAR
    RASAPIVERSION_500 = 1
    RASAPIVERSION_501
    RASAPIVERSION_600
    RASAPIVERSION_601
END ENUM

%RASAPIVERSION_CURRENT = %RASAPIVERSION_601

' A RAS IP address.
'
TYPE RASIPADDR
    a AS BYTE
    b AS BYTE
    c AS BYTE
    d AS BYTE
END TYPE

#IF (%WINVER >= &H600)

' A RAS IPv4 address.
'
TYPE RASIPV4ADDR
    in_addr
END TYPE

' A RAS IPv6 address.
'
TYPE RASIPV6ADDR
    in6_addr
END TYPE
#ENDIF  ' #if (%WINVER >= &H600)

#IF (%WINVER >= &H601)

%RASTUNNELENDPOINT_UNKNOWN    = 0
%RASTUNNELENDPOINT_IPv4       = 1
%RASTUNNELENDPOINT_IPv6       = 2

' RAS Tunnel endpoint address
'
UNION RASTUNNELENDPOINT_union
    ipv4 AS RASIPV4ADDR
    ipv6 AS RASIPV6ADDR
END UNION

TYPE RASTUNNELENDPOINT
    dwType AS DWORD
    RASTUNNELENDPOINT_union
END TYPE

#ENDIF  ' #if (%WINVER >= &H601)


%RAS_MaxDeviceType     = 16
%RAS_MaxPhoneNumber    = 128
%RAS_MaxIpAddress      = 15
%RAS_MaxIpxAddress     = 21

#IF (%WINVER >= &H400)
%RAS_MaxEntryName      = 256
%RAS_MaxDeviceName     = 128
%RAS_MaxCallbackNumber = %RAS_MaxPhoneNumber
#ELSE
%RAS_MaxEntryName      = 20
%RAS_MaxDeviceName     = 32
%RAS_MaxCallbackNumber = 48
#ENDIF

%RAS_MaxAreaCode       = 10
%RAS_MaxPadType        = 32
%RAS_MaxX25Address     = 200
%RAS_MaxFacilities     = 200
%RAS_MaxUserData       = 200
%RAS_MaxReplyMessage   = 1024
%RAS_MaxDnsSuffix      = 256

'DECLARE_HANDLE( DWORD );

#IF (%WINVER >= &H501)
%RASCF_AllUsers      = &H00000001
%RASCF_GlobalCreds   = &H00000002
%RASCF_OwnerKnown    = &H00000004
%RASCF_OwnerMatch    = &H00000008

MACRO RASCF_IsOwner(rascFlags)   =(((rascFlags) AND (%RASCF_OwnerKnown OR %RASCF_OwnerMatch)) = (%RASCF_OwnerKnown OR %RASCF_OwnerMatch))
MACRO RASCF_IsNotOwner(rascFlags)=(((rascFlags) AND (%RASCF_OwnerKnown OR %RASCF_OwnerMatch)) = (%RASCF_OwnerKnown))
#ENDIF

' Identifies an active RAS connection.  (See RasEnumConnections)
'
TYPE RASCONNW
    dwSize            AS DWORD
    hrasconn          AS DWORD
    szEntryName       AS WSTRINGZ * %RAS_MaxEntryName + 1

#IF (%WINVER >= &H400)
    szDeviceType      AS WSTRINGZ * %RAS_MaxDeviceType + 1
    szDeviceName      AS WSTRINGZ * %RAS_MaxDeviceName + 1
#ENDIF
#IF (%WINVER >= &H401)
    szPhonebook       AS WSTRINGZ * %MAX_PATH
    dwSubEntry        AS DWORD
#ENDIF
#IF (%WINVER >= &H500)
    guidEntry         AS GUID
#ENDIF
#IF (%WINVER >= &H501)
    dwFlags           AS DWORD
    luid              AS QUAD
#ENDIF
#IF (%WINVER >= &H600)
    guidCorrelationId AS GUID
#ENDIF
END TYPE

TYPE RASCONNA
    dwSize            AS DWORD
    hrasconn          AS DWORD
    szEntryName       AS ASCIIZ * %RAS_MaxEntryName + 1

#IF (%WINVER >= &H400)
    szDeviceType      AS ASCIIZ * %RAS_MaxDeviceType + 1
    szDeviceName      AS ASCIIZ * %RAS_MaxDeviceName + 1
#ENDIF
#IF (%WINVER >= &H401)
    szPhonebook       AS ASCIIZ * %MAX_PATH
    dwSubEntry        AS DWORD
#ENDIF
#IF (%WINVER >= &H500)
    guidEntry         AS GUID
#ENDIF
#IF (%WINVER >= &H501)
    dwFlags           AS DWORD
    luid              AS QUAD
#ENDIF
#IF (%WINVER >= &H600)
    guidCorrelationId AS GUID
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
TYPE RASCONN
    RASCONNW
END TYPE
#ELSE
TYPE RASCONN
    RASCONNA
END TYPE
#ENDIF


' Enumerates intermediate states to a connection.  (See RasDial)
'
%RASCS_PAUSED = &H1000
%RASCS_DONE   = &H2000

MACRO RASCONNSTATE_enum=LONG
ENUM RASCONNSTATE SINGULAR
    RASCS_OpenPort
    RASCS_PortOpened
    RASCS_ConnectDevice
    RASCS_DeviceConnected
    RASCS_AllDevicesConnected
    RASCS_Authenticate
    RASCS_AuthNotify
    RASCS_AuthRetry
    RASCS_AuthCallback
    RASCS_AuthChangePassword
    RASCS_AuthProject
    RASCS_AuthLinkSpeed
    RASCS_AuthAck
    RASCS_ReAuthenticate
    RASCS_Authenticated
    RASCS_PrepareForCallback
    RASCS_WaitForModemReset
    RASCS_WaitForCallback
    RASCS_Projected

#IF (%WINVER >= &H400)
    RASCS_StartAuthentication
    RASCS_CallbackComplete
    RASCS_LogonNetwork
#ENDIF
    RASCS_SubEntryConnected
    RASCS_SubEntryDisconnected
#IF (%WINVER >= &H601)
    RASCS_ApplySettings
#ENDIF

    RASCS_Interactive          = %RASCS_PAUSED
    RASCS_RetryAuthentication
    RASCS_CallbackSetByCaller
    RASCS_PasswordExpired
#IF (%WINVER >= &H500)
    RASCS_InvokeEapUI
#ENDIF

    RASCS_Connected            = %RASCS_DONE
    RASCS_Disconnected
END ENUM

#IF (%WINVER >= &H601)

%RASCSS_DONE    = &H2000

MACRO RASCONNSUBSTATE_enum=LONG
ENUM RASCONNSUBSTATE SINGULAR
    RASCSS_None
    RASCSS_Dormant
    RASCSS_Reconnecting
    RASCSS_Reconnected  = %RASCSS_DONE
END ENUM

#ENDIF


' Describes the status of a RAS connection.  (See RasConnectionStatus)
'
TYPE RASCONNSTATUSW
    dwSize        AS DWORD
    rasconnstate  AS RASCONNSTATE_enum
    dwError       AS DWORD
    szDeviceType  AS WSTRINGZ * %RAS_MaxDeviceType + 1
    szDeviceName  AS WSTRINGZ * %RAS_MaxDeviceName + 1
#IF (%WINVER >= &H401)
    szPhoneNumber AS WSTRINGZ * %RAS_MaxPhoneNumber + 1
#ENDIF
#IF (%WINVER >= &H601)
    localEndPoint   AS RASTUNNELENDPOINT
    remoteEndPoint  AS RASTUNNELENDPOINT
    rasconnsubstate AS RASCONNSUBSTATE_enum
#ENDIF
END TYPE

TYPE RASCONNSTATUSA
    dwSize          AS DWORD
    rasconnstate    AS RASCONNSTATE_enum
    dwError         AS DWORD
    szDeviceType    AS ASCIIZ * %RAS_MaxDeviceType + 1
    szDeviceName    AS ASCIIZ * %RAS_MaxDeviceName + 1
#IF (%WINVER >= &H401)
    szPhoneNumber   AS ASCIIZ * %RAS_MaxPhoneNumber + 1
#ENDIF
#IF (%WINVER >= &H601)
    localEndPoint   AS RASTUNNELENDPOINT
    remoteEndPoint  AS RASTUNNELENDPOINT
    rasconnsubstate AS RASCONNSUBSTATE_enum
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
TYPE RASCONNSTATUS
    RASCONNSTATUSW
END TYPE
#ELSE
TYPE RASCONNSTATUS
    RASCONNSTATUSA
END TYPE
#ENDIF

' Describes connection establishment parameters.  (See RasDial)
'
TYPE RASDIALPARAMSW
    dwSize           AS DWORD
    szEntryName      AS WSTRINGZ * %RAS_MaxEntryName + 1
    szPhoneNumber    AS WSTRINGZ * %RAS_MaxPhoneNumber + 1
    szCallbackNumber AS WSTRINGZ * %RAS_MaxCallbackNumber + 1
    szUserName       AS WSTRINGZ * %UNLEN + 1
    szPassword       AS WSTRINGZ * %PWLEN + 1
    szDomain         AS WSTRINGZ * %DNLEN + 1
#IF (%WINVER >= &H401)
    dwSubEntry       AS DWORD
    dwCallbackId     AS DWORD
#ENDIF
#IF (%WINVER >= &H601)
    dwIfIndex        AS DWORD
#ENDIF
END TYPE

TYPE RASDIALPARAMSA
    dwSize           AS DWORD
    szEntryName      AS ASCIIZ * %RAS_MaxEntryName + 1
    szPhoneNumber    AS ASCIIZ * %RAS_MaxPhoneNumber + 1
    szCallbackNumber AS ASCIIZ * %RAS_MaxCallbackNumber + 1
    szUserName       AS ASCIIZ * %UNLEN + 1
    szPassword       AS ASCIIZ * %PWLEN + 1
    szDomain         AS ASCIIZ * %DNLEN + 1
#IF (%WINVER >= &H401)
    dwSubEntry       AS DWORD
    dwCallbackId     AS DWORD
#ENDIF
#IF (%WINVER >= &H601)
    dwIfIndex        AS DWORD
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
TYPE RASDIALPARAMS
    RASDIALPARAMSW
END TYPE
#ELSE
TYPE RASDIALPARAMS
    RASDIALPARAMSA
END TYPE
#ENDIF

#IF (%WINVER >= &H500)

TYPE RASEAPINFO_type
    dwSizeofEapInfo AS DWORD
    pbEapInfo       AS BYTE PTR
END TYPE

#ENDIF

#IF (%WINVER >= &H601)
TYPE RASDEVSPECIFICINFO_type
    dwSize            AS DWORD
    pbDevSpecificInfo AS BYTE PTR
END TYPE
#ENDIF


' Describes extended connection establishment options.  (See RasDial)
'
TYPE RASDIALEXTENSIONS
    dwSize             AS DWORD
    dwfOptions         AS DWORD
    hwndParent         AS DWORD
    reserved           AS DWORD
#IF (%WINVER >= &H500)
    reserved1          AS DWORD
    RasEapInfo         AS RASEAPINFO_type
#ENDIF
#IF (%WINVER >= &H601)
    fSkipPppAuth       AS LONG
    RavDevSpecificInfo AS RASDEVSPECIFICINFO_type
#ENDIF
END TYPE

' 'dwfOptions' bit flags.
'
%RDEOPT_UsePrefixSuffix           = &H00000001
%RDEOPT_PausedStates              = &H00000002
%RDEOPT_IgnoreModemSpeaker        = &H00000004
%RDEOPT_SetModemSpeaker           = &H00000008
%RDEOPT_IgnoreSoftwareCompression = &H00000010
%RDEOPT_SetSoftwareCompression    = &H00000020
%RDEOPT_DisableConnectedUI        = &H00000040
%RDEOPT_DisableReconnectUI        = &H00000080
%RDEOPT_DisableReconnect          = &H00000100
%RDEOPT_NoUser                    = &H00000200
%RDEOPT_PauseOnScript             = &H00000400
%RDEOPT_Router                    = &H00000800

#IF (%WINVER >= &H500)
%RDEOPT_CustomDial                = &H00001000
#ENDIF

#IF (%WINVER >= &H501)
%RDEOPT_UseCustomScripting        = &H00002000
#ENDIF


'
' This flag when set in the RASENTRYNAME structure
' indicates that the phonebook to which this entry
' belongs is a system phonebook.
'
%REN_User                         = &H00000000
%REN_AllUsers                     = &H00000001


' Describes an enumerated RAS phone book entry name.  (See RasEntryEnum)
'
TYPE RASENTRYNAMEW
    dwSize          AS DWORD
    szEntryName     AS WSTRINGZ * %RAS_MaxEntryName + 1

#IF (%WINVER >= &H500)
    '
    ' If this flag is REN_AllUsers then its a
    ' system phonebook.
    '
    dwFlags         AS DWORD
    szPhonebookPath AS WSTRINGZ * %MAX_PATH + 1
#ENDIF
END TYPE

TYPE RASENTRYNAMEA
    dwSize          AS DWORD
    szEntryName     AS ASCIIZ * %RAS_MaxEntryName + 1

#IF (%WINVER >= &H500)
    dwFlags         AS DWORD
    szPhonebookPath AS ASCIIZ * %MAX_PATH + 1
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
TYPE RASENTRYNAME
    RASENTRYNAMEW
END TYPE
#ELSE
TYPE RASENTRYNAME
    RASENTRYNAMEA
END TYPE
#ENDIF


' Protocol code to projection data structure mapping.
'
MACRO RASPROJECTION_enum=LONG
ENUM RASPROJECTION SINGULAR
    RASP_Amb     = &H10000
    RASP_PppNbf  = &H803F??
    RASP_PppIpx  = &H802B??
    RASP_PppIp   = &H8021??
#IF (%WINVER >= &H500)
    RASP_PppCcp  = &H80FD??
#ENDIF
    RASP_PppLcp  = &HC021??
#IF (%WINVER >= &H600)
    RASP_PppIpv6 = &H8057??  ' To get Ipv6 projection information
#ENDIF
#IF (%WINVER < &H600) ' SLIP
    RASP_Slip    = &H20000
#ENDIF ' (%WINVER < &H600) ' SLIP
END ENUM


' Describes the result of a RAS AMB (Authentication Message Block)
' projection.  This protocol is used with NT 3.1 and OS/2 1.3 downlevel
' RAS servers.
'
TYPE RASAMBW
    dwSize         AS DWORD
    dwError        AS DWORD
    szNetBiosError AS WSTRINGZ * %NETBIOS_NAME_LEN + 1
    bLana          AS BYTE
END TYPE

TYPE RASAMBA
    dwSize         AS DWORD
    dwError        AS DWORD
    szNetBiosError AS ASCIIZ * %NETBIOS_NAME_LEN + 1
    bLana          AS BYTE
END TYPE

#IF %DEF(%UNICODE)
TYPE RASAMB
    RASAMBW
END TYPE
#ELSE
TYPE RASAMB
    RASAMBA
END TYPE
#ENDIF


' Describes the result of a PPP NBF (NetBEUI) projection.
'
TYPE RASPPPNBFW
    dwSize            AS DWORD
    dwError           AS DWORD
    dwNetBiosError    AS DWORD
    szNetBiosError    AS WSTRINGZ * %NETBIOS_NAME_LEN + 1
    szWorkstationName AS WSTRINGZ * %NETBIOS_NAME_LEN + 1
    bLana             AS BYTE
END TYPE

TYPE RASPPPNBFA
    dwSize            AS DWORD
    dwError           AS DWORD
    dwNetBiosError    AS DWORD
    szNetBiosError    AS ASCIIZ * %NETBIOS_NAME_LEN + 1
    szWorkstationName AS ASCIIZ * %NETBIOS_NAME_LEN + 1
    bLana             AS BYTE
END TYPE

#IF %DEF(%UNICODE)
TYPE RASPPPNBF
    RASPPPNBFW
END TYPE
#ELSE
TYPE RASPPPNBF
    RASPPPNBFA
END TYPE
#ENDIF


' Describes the results of a PPP IPX (Internetwork Packet Exchange)
' projection.
'
TYPE RASPPPIPXW
    dwSize       AS DWORD
    dwError      AS DWORD
    szIpxAddress AS WSTRINGZ * %RAS_MaxIpxAddress + 1
END TYPE


TYPE RASPPPIPXA
    dwSize       AS DWORD
    dwError      AS DWORD
    szIpxAddress AS ASCIIZ * %RAS_MaxIpxAddress + 1
END TYPE

#IF %DEF(%UNICODE)
TYPE RASPPPIPX
    RASPPPIPXW
END TYPE
#ELSE
TYPE RASPPPIPX
    RASPPPIPXA
END TYPE
#ENDIF


' Describes the results of a PPP IP (Internet) projection.
'

#IF (%WINVER >= &H500)

' RASPPPIP 'dwOptions' and 'dwServerOptions' flags.
'
%RASIPO_VJ     = &H00000001

#ENDIF

TYPE RASPPPIPW
    dwSize          AS DWORD
    dwError         AS DWORD
    szIpAddress     AS WSTRINGZ * %RAS_MaxIpAddress + 1

#IF NOT %DEF(%WINNT35COMPATIBLE)

    ' This field was added between Windows NT 3.51 beta and Windows NT 3.51
    ' final, and between Windows 95 M8 beta and Windows 95 final.  If you do
    ' not require the server address and wish to retrieve PPP IP information
    ' from Windows NT 3.5 or early Windows NT 3.51 betas, or on early Windows
    ' 95 betas, define WINNT35COMPATIBLE.
    '
    ' The server IP address is not provided by all PPP implementations,
    ' though Windows NT servers do provide it.
    '
    szServerIpAddress AS WSTRINGZ * %RAS_MaxIpAddress + 1

#ENDIF
#IF (%WINVER >= &H500)
    dwOptions       AS DWORD
    dwServerOptions AS DWORD
#ENDIF
END TYPE

TYPE RASPPPIPA
    dwSize          AS DWORD
    dwError         AS DWORD
    szIpAddress     AS ASCIIZ * %RAS_MaxIpAddress + 1

#IF NOT %DEF(%WINNT35COMPATIBLE)

    ' See RASPPPIPW comment.
    '
    szServerIpAddress AS ASCIIZ * %RAS_MaxIpAddress + 1

#ENDIF
#IF (%WINVER >= &H500)
    dwOptions       AS DWORD
    dwServerOptions AS DWORD
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
TYPE RASPPPIP
    RASPPPIPW
END TYPE
#ELSE
TYPE RASPPPIP
    RASPPPIPA
END TYPE
#ENDIF

' Describes the results of a Ipv6 projection info
'
#IF (%WINVER >= &H600)

TYPE RASPPPIPV6
    dwSize                       AS DWORD
    dwError                      AS DWORD
    bLocalInterfaceIdentifier(7) AS BYTE
    bPeerInterfaceIdentifier(7)  AS BYTE
    bLocalCompressionProtocol(1) AS BYTE
    bPeerCompressionProtocol(1)  AS BYTE
END TYPE

#ENDIF


' Describes the results of a PPP LCP/multi-link negotiation.
'

#IF (%WINVER >= &H500)

' RASPPPLCP 'dwAuthenticatonProtocol' values.
'
%RASLCPAP_PAP        = &HC023??
%RASLCPAP_SPAP       = &HC027??
%RASLCPAP_CHAP       = &HC223??
%RASLCPAP_EAP        = &HC227??

' RASPPPLCP 'dwAuthenticatonData' values.
'
%RASLCPAD_CHAP_MD5   = &H05
%RASLCPAD_CHAP_MS    = &H80?
%RASLCPAD_CHAP_MSV2  = &H81?

' RASPPPLCP 'dwOptions' and 'dwServerOptions' flags.
'
%RASLCPO_PFC         = &H00000001
%RASLCPO_ACFC        = &H00000002
%RASLCPO_SSHF        = &H00000004
%RASLCPO_DES_56      = &H00000008
%RASLCPO_3_DES       = &H00000010

#IF (%WINVER >= &H600)
%RASLCPO_AES_128     = &H00000020
%RASLCPO_AES_256     = &H00000040
#ENDIF ' %WINVER >= &H0600

#ENDIF


TYPE RASPPPLCPW
    dwSize                     AS DWORD
    fBundled                   AS LONG

#IF (%WINVER >= &H500)
    dwError                    AS DWORD
    dwAuthenticationProtocol   AS DWORD
    dwAuthenticationData       AS DWORD
    dwEapTypeId                AS DWORD
    dwServerAuthenticationProtocol AS DWORD
    dwServerAuthenticationData AS DWORD
    dwServerEapTypeId          AS DWORD
    fMultilink                 AS LONG
    dwTerminateReason          AS DWORD
    dwServerTerminateReason    AS DWORD
    szReplyMessage             AS WSTRINGZ * %RAS_MaxReplyMessage
    dwOptions                  AS DWORD
    dwServerOptions            AS DWORD
#ENDIF
END TYPE

TYPE RASPPPLCPA
    dwSize                     AS DWORD
    fBundled                   AS LONG

#IF (%WINVER >= &H500)
    dwError                    AS DWORD
    dwAuthenticationProtocol   AS DWORD
    dwAuthenticationData       AS DWORD
    dwEapTypeId                AS DWORD
    dwServerAuthenticationProtocol AS DWORD
    dwServerAuthenticationData AS DWORD
    dwServerEapTypeId          AS DWORD
    fMultilink                 AS LONG
    dwTerminateReason          AS DWORD
    dwServerTerminateReason    AS DWORD
    szReplyMessage             AS ASCIIZ * %RAS_MaxReplyMessage
    dwOptions                  AS DWORD
    dwServerOptions            AS DWORD
#ENDIF
END TYPE


#IF %DEF(%UNICODE)
TYPE RASPPPLCP
    RASPPPLCPW
END TYPE
#ELSE
TYPE RASPPPLCP
    RASPPPLCPA
END TYPE
#ENDIF

#IF (%WINVER < &H600) ' SLIP

' Describes the results of a SLIP (Serial Line IP) projection.
'
TYPE RASSLIPW
    dwSize      AS DWORD
    dwError     AS DWORD
    szIpAddress AS WSTRINGZ * %RAS_MaxIpAddress + 1
END TYPE


TYPE RASSLIPA
    dwSize      AS DWORD
    dwError     AS DWORD
    szIpAddress AS ASCIIZ * %RAS_MaxIpAddress + 1
END TYPE

#IF %DEF(%UNICODE)
TYPE RASSLIP
    RASSLIPW
END TYPE
#ELSE
TYPE RASSLIP
    RASSLIPA
END TYPE
#ENDIF

#ENDIF ' SLIP

#IF (%WINVER >= &H500)

' Describes the results of a PPP CCP (Compression Control Protocol)
' projection.
'

' RASPPPCCP 'dwCompressionAlgorithm' values.
'
%RASCCPCA_MPPC            = &H00000006
%RASCCPCA_STAC            = &H00000005

' RASPPPCCP 'dwOptions' values.
'
%RASCCPO_Compression      = &H00000001
%RASCCPO_HistoryLess      = &H00000002
%RASCCPO_Encryption56bit  = &H00000010
%RASCCPO_Encryption40bit  = &H00000020
%RASCCPO_Encryption128bit = &H00000040

TYPE RASPPPCCP
    dwSize                       AS DWORD
    dwError                      AS DWORD
    dwCompressionAlgorithm       AS DWORD
    dwOptions                    AS DWORD
    dwServerCompressionAlgorithm AS DWORD
    dwServerOptions              AS DWORD
END TYPE

#ENDIF

'
' New Projection Information structure for PPP and IKEv2
'
'
#IF (%WINVER >= &H601)

TYPE RASPPP_PROJECTION_INFO

    ' IPv4 Projection Parameters
    dwIPv4NegotiationError   AS DWORD
    ipv4Address              AS RASIPV4ADDR
    ipv4ServerAddress        AS RASIPV4ADDR
    dwIPv4Options            AS DWORD
    dwIPv4ServerOptions      AS DWORD

    ' IPv6 Projection Parameters
    dwIPv6NegotiationError   AS DWORD
    bInterfaceIdentifier(7)  AS BYTE
    bServerInterfaceIdentifier(7) AS BYTE

    ' LCP Options
    fBundled                 AS LONG  ' BOOL
    fMultilink               AS LONG  ' BOOL
    dwAuthenticationProtocol AS DWORD
    dwAuthenticationData     AS DWORD
    dwServerAuthenticationProtocol AS DWORD
    dwServerAuthenticationData AS DWORD
    dwEapTypeId              AS DWORD
    dwServerEapTypeId        AS DWORD
    dwLcpOptions             AS DWORD
    dwLcpServerOptions       AS DWORD

    ' CCP options
    dwCcpError               AS DWORD
    dwCcpCompressionAlgorithm AS DWORD
    dwCcpServerCompressionAlgorithm AS DWORD
    dwCcpOptions             AS DWORD
    dwCcpServerOptions       AS DWORD
END TYPE

' RASIKEV2_PROJECTION_INFO 'dwFlags' values.
'
%RASIKEv2_FLAGS_MOBIKESUPPORTED   = &H00000001
%RASIKEv2_FLAGS_BEHIND_NAT        = &H00000002
%RASIKEv2_FLAGS_SERVERBEHIND_NAT  = &H00000004

' RASIKEV2_PROJECTION_INFO 'dwAuthenticatonProtocol' values.
'
%RASIKEv2_AUTH_MACHINECERTIFICATES = 1
%RASIKEv2_AUTH_EAP                 = 2

TYPE RASIKEV2_PROJECTION_INFO

    ' IPv4 Projection Parameters
    dwIPv4NegotiationError AS DWORD
    ipv4Address            AS RASIPV4ADDR
    ipv4ServerAddress      AS RASIPV4ADDR

    ' IPv6 Projection Parameters
    dwIPv6NegotiationError AS DWORD
    ipv6Address            AS RASIPV6ADDR
    ipv6ServerAddress      AS RASIPV6ADDR
    dwPrefixLength         AS DWORD

    ' AUTH
    dwAuthenticationProtocol AS DWORD
    dwEapTypeId AS DWORD

    dwFlags AS DWORD
    dwEncryptionMethod     AS DWORD

    numIPv4ServerAddresses AS DWORD
    ipv4ServerAddresses    AS RASIPV4ADDR PTR
    numIPv6ServerAddresses AS DWORD
    ipv6ServerAddresses    AS RASIPV6ADDR PTR
END TYPE

MACRO RASPROJECTION_INFO_TYPE_enum=LONG
ENUM RASPROJECTION_INFO_TYPE SINGULAR
    PROJECTION_INFO_TYPE_PPP   = 1
    PROJECTION_INFO_TYPE_IKEv2
END ENUM

UNION RAS_PROJECTION_INFO_union
    ppp   AS RASPPP_PROJECTION_INFO
    ikev2 AS RASIKEV2_PROJECTION_INFO
END UNION

TYPE RAS_PROJECTION_INFO

    version AS RASAPIVERSION_enum
    ntype   AS RASPROJECTION_INFO_TYPE_enum

    ' Based on the connectionFlags, it should use appropriate projection info
    RAS_PROJECTION_INFO_union
END TYPE

#ENDIF



' If using RasDial message notifications, get the notification message code
' by passing this string to the RegisterWindowMessageA() API.
' WM_RASDIALEVENT is used only if a unique message cannot be registered.
'
$RASDIALEVENT    = "RasDialEvent"
%WM_RASDIALEVENT = &HCCCD??

' Prototypes for caller's RasDial callback handler.  Arguments are the
' message ID (currently always WM_RASDIALEVENT), the current RASCONNSTATE and
' the error that has occurred (or 0 if none).  Extended arguments are the
' handle of the RAS connection and an extended error code.
'
' For RASDIALFUNC2, subsequent callback notifications for all
' subentries can be cancelled by returning FALSE.
'
DECLARE SUB RASDIALFUNC (BYVAL unMsg AS DWORD, _
    BYVAL rcs AS RASCONNSTATE_enum, BYVAL dwError AS DWORD)

DECLARE SUB RASDIALFUNC1 (BYVAL hrasconn AS DWORD, BYVAL unMsg AS DWORD, _
    BYVAL rcs AS RASCONNSTATE_enum, BYVAL dwError AS DWORD, _
    BYVAL dwExtendedError AS DWORD)

DECLARE FUNCTION RASDIALFUNC2 (BYVAL dwCallbackId AS DWORD, _
    BYVAL dwSubEntry AS DWORD, BYVAL hrasconn AS DWORD, BYVAL unMsg AS DWORD, _
    BYVAL rcs AS RASCONNSTATE_enum, BYVAL dwError AS DWORD, _
    BYVAL dwExtendedError AS DWORD) AS DWORD


' Information describing a RAS-capable device.
'
TYPE RASDEVINFOW
    dwSize       AS DWORD
    szDeviceType AS WSTRINGZ * %RAS_MaxDeviceType + 1
    szDeviceName AS WSTRINGZ * %RAS_MaxDeviceName + 1
END TYPE

TYPE RASDEVINFOA
    dwSize       AS DWORD
    szDeviceType AS ASCIIZ * %RAS_MaxDeviceType + 1
    szDeviceName AS ASCIIZ * %RAS_MaxDeviceName + 1
END TYPE

#IF %DEF(%UNICODE)
TYPE RASDEVINFO
    RASDEVINFOW
END TYPE
#ELSE
TYPE RASDEVINFO
    RASDEVINFOA
END TYPE
#ENDIF

' RAS country information (currently retrieved from TAPI).
'
TYPE RASCTRYINFO
    dwSize              AS DWORD
    dwCountryID         AS DWORD
    dwNextCountryID     AS DWORD
    dwCountryCode       AS DWORD
    dwCountryNameOffset AS DWORD
END TYPE

' There is currently no difference between
' RASCTRYINFOA and RASCTRYINFOW.  This may
' change in the future.
'
MACRO RASCTRYINFOW = RASCTRYINFO
MACRO RASCTRYINFOA = RASCTRYINFO

#IF (%WINVER >= &H500)

%ET_None       = 0  ' No encryption
%ET_Require    = 1  ' Require Encryption
%ET_RequireMax = 2  ' Require max encryption
%ET_Optional   = 3  ' Do encryption if possible. None Ok.

#ENDIF

%VS_Default    = 0   ' default (PPTP for now)
%VS_PptpOnly   = 1   ' Only PPTP is attempted.
%VS_PptpFirst  = 2   ' PPTP is tried first.
%VS_L2tpOnly   = 3   ' Only L2TP is attempted.
%VS_L2tpFirst  = 4   ' L2TP is tried first.

#IF (%WINVER >= &H600)
%VS_SstpOnly   = 5   ' Only SSTP is attempted
%VS_SstpFirst  = 6   ' SSTP is attempted first
#ENDIF

#IF (%WINVER >= &H601)
%VS_Ikev2Only  = 7   ' Only VPN Ikev2 is attempted
%VS_Ikev2First = 8   ' VPN Ikev2 is attempted first
#ENDIF

#IF (%WINVER >= &H601)
%VS_PptpSstp   = 12  ' PPTP is attempted followed only by SSTP
%VS_L2tpSstp   = 13  ' L2TP is attempted followed only by SSTP
%VS_Ikev2Sstp  = 14  ' IKEv2 is attempted followed only by SSTP
#ENDIF


' A RAS phone book entry.
'
TYPE RASENTRYA
    dwSize              AS DWORD
    dwfOptions          AS DWORD
    '
    ' Location/phone number.
    '
    dwCountryID         AS DWORD
    dwCountryCode       AS DWORD
    szAreaCode          AS ASCIIZ * %RAS_MaxAreaCode + 1
    szLocalPhoneNumber  AS ASCIIZ * %RAS_MaxPhoneNumber + 1
    dwAlternateOffset   AS DWORD
    '
    ' PPP/Ip
    '
    ipaddr              AS RASIPADDR
    ipaddrDns           AS RASIPADDR
    ipaddrDnsAlt        AS RASIPADDR
    ipaddrWins          AS RASIPADDR
    ipaddrWinsAlt       AS RASIPADDR
    '
    ' Framing
    '
    dwFrameSize         AS DWORD
    dwfNetProtocols     AS DWORD
    dwFramingProtocol   AS DWORD
    '
    ' Scripting
    '
    szScript            AS ASCIIZ * %MAX_PATH
    '
    ' AutoDial
    '
    szAutodialDll       AS ASCIIZ * %MAX_PATH
    szAutodialFunc      AS ASCIIZ * %MAX_PATH
    '
    ' Device
    '
    szDeviceType        AS ASCIIZ * %RAS_MaxDeviceType + 1
    szDeviceName        AS ASCIIZ * %RAS_MaxDeviceName + 1
    '
    ' X.25
    '
    szX25PadType        AS ASCIIZ * %RAS_MaxPadType + 1
    szX25Address        AS ASCIIZ * %RAS_MaxX25Address + 1
    szX25Facilities     AS ASCIIZ * %RAS_MaxFacilities + 1
    szX25UserData       AS ASCIIZ * %RAS_MaxUserData + 1
    dwChannels          AS DWORD
    '
    ' Reserved
    '
    dwReserved1         AS DWORD
    dwReserved2         AS DWORD
#IF (%WINVER >= &H401)
    '
    ' Multilink
    '
    dwSubEntries        AS DWORD
    dwDialMode          AS DWORD
    dwDialExtraPercent  AS DWORD
    dwDialExtraSampleSeconds   AS DWORD
    dwHangUpExtraPercent       AS DWORD
    dwHangUpExtraSampleSeconds AS DWORD
    '
    ' Idle timeout
    '
    dwIdleDisconnectSeconds AS DWORD
#ENDIF

#IF (%WINVER >= &H500)

    '
    ' Entry Type
    '
    dwType              AS DWORD

    '
    ' Encryption type
    '
    dwEncryptionType    AS DWORD

    '
    ' CustomAuthKey to be used for EAP
    '
    dwCustomAuthKey     AS DWORD

    '
    ' Guid of the connection
    '
    guidId              AS GUID

    '
    ' Custom Dial Dll
    '
    szCustomDialDll     AS ASCIIZ * %MAX_PATH

    '
    ' DwVpnStrategy
    '
    dwVpnStrategy       AS DWORD
#ENDIF

#IF (%WINVER >= &H501)
    '
    ' More RASEO_* options
    '
    dwfOptions2         AS DWORD

    '
    ' For future use
    '
    dwfOptions3         AS DWORD
    szDnsSuffix         AS ASCIIZ * %RAS_MaxDnsSuffix
    dwTcpWindowSize     AS DWORD
    szPrerequisitePbk   AS ASCIIZ * %MAX_PATH
    szPrerequisiteEntry AS ASCIIZ * %RAS_MaxEntryName + 1
    dwRedialCount       AS DWORD
    dwRedialPause       AS DWORD
#ENDIF

#IF (%WINVER >= &H600)
    '
    ' PPP/IPv6
    '
    ipv6addrDns           AS RASIPV6ADDR
    ipv6addrDnsAlt        AS RASIPV6ADDR
    dwIPv4InterfaceMetric AS DWORD
    dwIPv6InterfaceMetric AS DWORD
#ENDIF

#IF (%WINVER >= &H601)
    ' Fields required for supporting static IPv6 address
    ' configuration for a vpn interface by the user
    ipv6addr            AS RASIPV6ADDR
    dwIPv6PrefixLength  AS DWORD

    '
    ' IKEv2 related
    dwNetworkOutageTime AS DWORD
#ENDIF

END TYPE

TYPE RASENTRYW
    dwSize              AS DWORD
    dwfOptions          AS DWORD
    '
    ' Location/phone number
    '
    dwCountryID         AS DWORD
    dwCountryCode       AS DWORD
    szAreaCode          AS WSTRINGZ * %RAS_MaxAreaCode + 1
    szLocalPhoneNumber  AS WSTRINGZ * %RAS_MaxPhoneNumber + 1
    dwAlternateOffset   AS DWORD
    '
    ' PPP/Ip
    '
    ipaddr              AS RASIPADDR
    ipaddrDns           AS RASIPADDR
    ipaddrDnsAlt        AS RASIPADDR
    ipaddrWins          AS RASIPADDR
    ipaddrWinsAlt       AS RASIPADDR
    '
    ' Framing
    '
    dwFrameSize         AS DWORD
    dwfNetProtocols     AS DWORD
    dwFramingProtocol   AS DWORD
    '
    ' Scripting
    '
    szScript            AS WSTRINGZ * %MAX_PATH
    '
    ' AutoDial
    '
    szAutodialDll       AS WSTRINGZ * %MAX_PATH
    szAutodialFunc      AS WSTRINGZ * %MAX_PATH
    '
    ' Device
    '
    szDeviceType        AS WSTRINGZ * %RAS_MaxDeviceType + 1
    szDeviceName        AS WSTRINGZ * %RAS_MaxDeviceName + 1
    '
    ' X.25
    '
    szX25PadType        AS WSTRINGZ * %RAS_MaxPadType + 1
    szX25Address        AS WSTRINGZ * %RAS_MaxX25Address + 1
    szX25Facilities     AS WSTRINGZ * %RAS_MaxFacilities + 1
    szX25UserData       AS WSTRINGZ * %RAS_MaxUserData + 1
    dwChannels          AS DWORD
    '
    ' Reserved
    '
    dwReserved1         AS DWORD
    dwReserved2         AS DWORD
#IF (%WINVER >= &H401)
    '
    ' Multilink
    '
    dwSubEntries        AS DWORD
    dwDialMode          AS DWORD
    dwDialExtraPercent  AS DWORD
    dwDialExtraSampleSeconds   AS DWORD
    dwHangUpExtraPercent       AS DWORD
    dwHangUpExtraSampleSeconds AS DWORD
    '
    ' Idle timeout
    '
    dwIdleDisconnectSeconds    AS DWORD
#ENDIF

#IF (%WINVER >= &H500)
    '
    ' Entry Type
    '
    dwType              AS DWORD

    '
    ' EncryptionType
    '
    dwEncryptionType    AS DWORD

    '
    ' CustomAuthKey to be used for EAP
    '
    dwCustomAuthKey     AS DWORD

    '
    ' Guid of the connection
    '
    guidId              AS GUID

    '
    ' Custom Dial Dll
    '
    szCustomDialDll     AS WSTRINGZ * %MAX_PATH

    '
    ' Vpn Strategy
    '
    dwVpnStrategy       AS DWORD
#ENDIF

#IF (%WINVER >= &H501)
    '
    ' More RASEO_* options
    '
    dwfOptions2         AS DWORD

    '
    ' For future use
    '
    dwfOptions3         AS DWORD
    szDnsSuffix         AS WSTRINGZ * %RAS_MaxDnsSuffix
    dwTcpWindowSize     AS DWORD
    szPrerequisitePbk   AS WSTRINGZ * %MAX_PATH
    szPrerequisiteEntry AS WSTRINGZ * %RAS_MaxEntryName + 1
    dwRedialCount       AS DWORD
    dwRedialPause       AS DWORD
#ENDIF

#IF (%WINVER >= &H600)
    '
    ' PPP/IPv6
    '
    ipv6addrDns           AS RASIPV6ADDR
    ipv6addrDnsAlt        AS RASIPV6ADDR
    dwIPv4InterfaceMetric AS DWORD
    dwIPv6InterfaceMetric AS DWORD
#ENDIF

#IF (%WINVER >= &H601)
    ' Fields required for supporting static IPv6 address
    ' configuration for a vpn interface by the user
    ipv6addr            AS RASIPV6ADDR
    dwIPv6PrefixLength  AS DWORD

    '
    ' IKEv2 related
    dwNetworkOutageTime AS DWORD
#ENDIF

END TYPE

#IF %DEF(%UNICODE)
TYPE RASENTRY
    RASENTRYW
END TYPE
#ELSE
TYPE RASENTRY
    RASENTRYA
END TYPE
#ENDIF


' RASENTRY 'dwfOptions' bit flags.
'
%RASEO_UseCountryAndAreaCodes    = &H00000001
%RASEO_SpecificIpAddr            = &H00000002
%RASEO_SpecificNameServers       = &H00000004
%RASEO_IpHeaderCompression       = &H00000008
%RASEO_RemoteDefaultGateway      = &H00000010
%RASEO_DisableLcpExtensions      = &H00000020
%RASEO_TerminalBeforeDial        = &H00000040
%RASEO_TerminalAfterDial         = &H00000080
%RASEO_ModemLights               = &H00000100
%RASEO_SwCompression             = &H00000200
%RASEO_RequireEncryptedPw        = &H00000400
%RASEO_RequireMsEncryptedPw      = &H00000800
%RASEO_RequireDataEncryption     = &H00001000
%RASEO_NetworkLogon              = &H00002000
%RASEO_UseLogonCredentials       = &H00004000
%RASEO_PromoteAlternates         = &H00008000

#IF (%WINVER >= &H401)
%RASEO_SecureLocalFiles          = &H00010000
#ENDIF

#IF (%WINVER >= &H500)
%RASEO_RequireEAP                = &H00020000
%RASEO_RequirePAP                = &H00040000
%RASEO_RequireSPAP               = &H00080000
%RASEO_Custom                    = &H00100000

%RASEO_PreviewPhoneNumber        = &H00200000
%RASEO_SharedPhoneNumbers        = &H00800000
%RASEO_PreviewUserPw             = &H01000000
%RASEO_PreviewDomain             = &H02000000
%RASEO_ShowDialingProgress       = &H04000000
%RASEO_RequireCHAP               = &H08000000
%RASEO_RequireMsCHAP             = &H10000000
%RASEO_RequireMsCHAP2            = &H20000000
%RASEO_RequireW95MSCHAP          = &H40000000
%RASEO_CustomScript              = &H80000000???
#ENDIF

#IF (%WINVER >= &H501)
'
' RASENTRY dwfOptions2 bit flags
'
%RASEO2_SecureFileAndPrint       = &H00000001
%RASEO2_SecureClientForMSNet     = &H00000002
%RASEO2_DontNegotiateMultilink   = &H00000004
%RASEO2_DontUseRasCredentials    = &H00000008
%RASEO2_UsePreSharedKey          = &H00000010
%RASEO2_Internet                 = &H00000020
%RASEO2_DisableNbtOverIP         = &H00000040
%RASEO2_UseGlobalDeviceSettings  = &H00000080
%RASEO2_ReconnectIfDropped       = &H00000100
%RASEO2_SharePhoneNumbers        = &H00000200
#ENDIF

#IF (%WINVER >= &H600)
%RASEO2_SecureRoutingCompartment     = &H00000400
%RASEO2_UseTypicalSettings           = &H00000800
%RASEO2_IPv6SpecificNameServers      = &H00001000
%RASEO2_IPv6RemoteDefaultGateway     = &H00002000
%RASEO2_RegisterIpWithDNS            = &H00004000
%RASEO2_UseDNSSuffixForRegistration  = &H00008000
%RASEO2_IPv4ExplicitMetric           = &H00010000
%RASEO2_IPv6ExplicitMetric           = &H00020000
%RASEO2_DisableIKENameEkuCheck       = &H00040000
#ENDIF

#IF (%WINVER >= &H601)
%RASEO2_DisableClassBasedStaticRoute = &H00080000
%RASEO2_SpecificIPv6Addr             = &H00100000
%RASEO2_DisableMobility              = &H00200000
%RASEO2_RequireMachineCertificates   = &H00400000
#ENDIF

' RASENTRY 'dwProtocols' bit flags.
'
%RASNP_NetBEUI                   = &H00000001
%RASNP_Ipx                       = &H00000002
%RASNP_Ip                        = &H00000004
#IF (%WINVER >= &H600)
%RASNP_Ipv6                      = &H00000008
#ENDIF

' RASENTRY 'dwFramingProtocols' bit flags.
'
%RASFP_Ppp                       = &H00000001
%RASFP_Slip                      = &H00000002
%RASFP_Ras                       = &H00000004

' RASENTRY 'szDeviceType' default strings.
'
$RASDT_Modem       = "modem"
$RASDT_Isdn        = "isdn"
$RASDT_X25         = "x25"
$RASDT_Vpn         = "vpn"
$RASDT_Pad         = "pad"
$RASDT_Generic     = "GENERIC"
$RASDT_Serial      = "SERIAL"
$RASDT_FrameRelay  = "FRAMERELAY"
$RASDT_Atm         = "ATM"
$RASDT_Sonet       = "SONET"
$RASDT_SW56        = "SW56"
$RASDT_Irda        = "IRDA"
$RASDT_Parallel    = "PARALLEL"
#IF (%WINVER >= &H501)
$RASDT_PPPoE       = "PPPoE"
#ENDIF

$$RASDT_Modem       = "modem"$$
$$RASDT_Isdn        = "isdn"$$
$$RASDT_X25         = "x25"$$
$$RASDT_Vpn         = "vpn"$$
$$RASDT_Pad         = "pad"$$
$$RASDT_Generic     = "GENERIC"$$
$$RASDT_Serial      = "SERIAL"$$
$$RASDT_FrameRelay  = "FRAMERELAY"$$
$$RASDT_Atm         = "ATM"$$
$$RASDT_Sonet       = "SONET"$$
$$RASDT_SW56        = "SW56"$$
$$RASDT_Irda        = "IRDA"$$
$$RASDT_Parallel    = "PARALLEL"$$
#IF (%WINVER >= &H501)
$$RASDT_PPPoE       = "PPPoE"$$
#ENDIF

#IF %DEF(%UNICODE)
MACRO RASDT_Modem=$$RASDT_Modem
MACRO RASDT_Isdn=$$RASDT_Isdn
MACRO RASDT_X25=$$RASDT_X25
MACRO RASDT_Vpn=$$RASDT_Vpn
MACRO RASDT_Pad=$$RASDT_Pad
MACRO RASDT_Generic=$$RASDT_Generic
MACRO RASDT_Serial=$$RASDT_Serial
MACRO RASDT_FrameRelay=$$RASDT_FrameRelay
MACRO RASDT_Atm=$$RASDT_Atm
MACRO RASDT_Sonet=$$RASDT_Sonet
MACRO RASDT_SW56=$$RASDT_SW56
MACRO RASDT_Irda=$$RASDT_Irda
MACRO RASDT_Parallel=$$RASDT_Parallel
#IF (%WINVER >= &H501)
MACRO RASDT_PPPoE=$$RASDT_PPPoE
#ENDIF
#ELSE
MACRO RASDT_Modem=$RASDT_Modem
MACRO RASDT_Isdn=$RASDT_Isdn
MACRO RASDT_X25=$RASDT_X25
MACRO RASDT_Vpn=$RASDT_Vpn
MACRO RASDT_Pad=$RASDT_Pad
MACRO RASDT_Generic=$RASDT_Generic
MACRO RASDT_Serial=$RASDT_Serial
MACRO RASDT_FrameRelay=$RASDT_FrameRelay
MACRO RASDT_Atm=$RASDT_Atm
MACRO RASDT_Sonet=$RASDT_Sonet
MACRO RASDT_SW56=$RASDT_SW56
MACRO RASDT_Irda=$RASDT_Irda
MACRO RASDT_Parallel=$RASDT_Parallel
#IF (%WINVER >= &H501)
MACRO RASDT_PPPoE=$RASDT_PPPoE
#ENDIF
#ENDIF


' The entry type used to determine which UI properties
' are to be presented to user.  This generally corresponds
' to a Connections "add" wizard selection.
'
%RASET_Phone     = 1  ' Phone lines: modem, ISDN, X.25, etc
%RASET_Vpn       = 2  ' Virtual private network

#IF (%WINVER < &H600)
%RASET_Direct    = 3  ' Direct connect: serial, parallel
#ENDIF ' (%WINVER < &H600)

%RASET_Internet  = 4  ' BaseCamp internet
#IF (%WINVER >= &H501)
%RASET_Broadband = 5  ' Broadband
#ENDIF

' Old AutoDial DLL function prototype.
'
' This prototype is documented for backward-compatibility
' purposes only.  It is superceded by the RASADFUNCA
' and RASADFUNCW definitions below.  DO NOT USE THIS
' PROTOTYPE IN NEW CODE.  SUPPORT FOR IT MAY BE REMOVED
' IN FUTURE VERSIONS OF RAS.
'
DECLARE FUNCTION ORASADFUNC (BYVAL DWORD, ASCIIZ, BYVAL DWORD, BYREF DWORD) AS LONG

#IF (%WINVER >= &H400)

' Flags for RasConnectionNotification().
'
%RASCN_Connection       = &H00000001
%RASCN_Disconnection    = &H00000002
%RASCN_BandwidthAdded   = &H00000004
%RASCN_BandwidthRemoved = &H00000008
%RASCN_Dormant          = &H00000010
%RASCN_ReConnection     = &H00000020

#ENDIF

#IF (%WINVER >= &H401)
' RASENTRY 'dwDialMode' values.
'
%RASEDM_DialAll        = 1
%RASEDM_DialAsNeeded   = 2

' RASENTRY 'dwIdleDisconnectSeconds' constants.
'
%RASIDS_Disabled       = &Hffffffff???
%RASIDS_UseGlobalValue = 0

' AutoDial DLL function parameter block.
'
TYPE RASADPARAMS
    dwSize    AS DWORD
    hwndOwner AS DWORD
    dwFlags   AS DWORD
    xDlg      AS LONG
    yDlg      AS LONG
END TYPE

' AutoDial DLL function parameter block 'dwFlags.'
'
%RASADFLG_PositionDlg = &H00000001

' Prototype AutoDial DLL function.
'
DECLARE FUNCTION RASADFUNCA (lpszPhonebook AS ASCIIZ, lpszEntry AS ASCIIZ, _
    lpAutoDialParams AS RASADPARAMS, lpdwRetCode AS DWORD) AS LONG

DECLARE FUNCTION RASADFUNCW (lpszPhonebook AS WSTRINGZ, _
    lpszEntry AS WSTRINGZ, lpAutoDialParams AS RASADPARAMS, _
    lpdwRetCode AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO RASADFUNC=RASADFUNCW
#ELSE
MACRO RASADFUNC=RASADFUNCA
#ENDIF

' A RAS phone book multilinked sub-entry.
'
TYPE RASSUBENTRYA
    dwSize             AS DWORD
    dwfFlags           AS DWORD
    '
    ' Device
    '
    szDeviceType       AS ASCIIZ * %RAS_MaxDeviceType + 1
    szDeviceName       AS ASCIIZ * %RAS_MaxDeviceName + 1
    '
    ' Phone numbers
    '
    szLocalPhoneNumber AS ASCIIZ * %RAS_MaxPhoneNumber + 1
    dwAlternateOffset  AS DWORD
END TYPE

TYPE RASSUBENTRYW
    dwSize             AS DWORD
    dwfFlags           AS DWORD
    '
    ' Device
    '
    szDeviceType       AS WSTRINGZ * %RAS_MaxDeviceType + 1
    szDeviceName       AS WSTRINGZ * %RAS_MaxDeviceName + 1
    '
    ' Phone numbers
    '
    szLocalPhoneNumber AS WSTRINGZ * %RAS_MaxPhoneNumber + 1
    dwAlternateOffset  AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE RASSUBENTRY
    RASSUBENTRYW
END TYPE
#ELSE
TYPE RASSUBENTRY
    RASSUBENTRYA
END TYPE
#ENDIF


' Ras{Get,Set}Credentials structure.  These calls
' supercede Ras{Get,Set}EntryDialParams.
'
TYPE RASCREDENTIALSA
    dwSize     AS DWORD
    dwMask     AS DWORD
    szUserName AS ASCIIZ * %UNLEN + 1
    szPassword AS ASCIIZ * %PWLEN + 1
    szDomain   AS ASCIIZ * %DNLEN + 1
END TYPE

TYPE RASCREDENTIALSW
    dwSize     AS DWORD
    dwMask     AS DWORD
    szUserName AS WSTRINGZ * %UNLEN + 1
    szPassword AS WSTRINGZ * %PWLEN + 1
    szDomain   AS WSTRINGZ * %DNLEN + 1
END TYPE

#IF %DEF(%UNICODE)
TYPE RASCREDENTIALS
    RASCREDENTIALSW
END TYPE
#ELSE
TYPE RASCREDENTIALS
    RASCREDENTIALSA
END TYPE
#ENDIF

' RASCREDENTIALS 'dwMask' values.
'
%RASCM_UserName           = &H00000001
%RASCM_Password           = &H00000002
%RASCM_Domain             = &H00000004
'#if (%WINVER >= 501)   [this is the original, but it's wrong]
#IF (%WINVER >= &H501)
%RASCM_DefaultCreds       = &H00000008
%RASCM_PreSharedKey       = &H00000010
%RASCM_ServerPreSharedKey = &H00000020
%RASCM_DDMPreSharedKey    = &H00000040
#ENDIF

' AutoDial address properties.
'
TYPE RASAUTODIALENTRYA
    dwSize            AS DWORD
    dwFlags           AS DWORD
    dwDialingLocation AS DWORD
    szEntry           AS ASCIIZ * %RAS_MaxEntryName + 1
END TYPE

TYPE RASAUTODIALENTRYW
    dwSize            AS DWORD
    dwFlags           AS DWORD
    dwDialingLocation AS DWORD
    szEntry           AS WSTRINGZ * %RAS_MaxEntryName + 1
END TYPE

#IF %DEF(%UNICODE)
TYPE RASAUTODIALENTRY
    RASAUTODIALENTRYW
END TYPE
#ELSE
TYPE RASAUTODIALENTRY
    RASAUTODIALENTRYA
END TYPE
#ENDIF

' AutoDial control parameter values for
' Ras{Get,Set}AutodialParam.
'
%RASADP_DisableConnectionQuery  = 0
%RASADP_LoginSessionDisable     = 1
%RASADP_SavedAddressesLimit     = 2
%RASADP_FailedConnectionTimeout = 3
%RASADP_ConnectionQueryTimeout  = 4

#ENDIF ' (%WINVER >= &H401)

#IF (%WINVER >= &H500)

' RasGetEapUserIdentity bit flags.
' These have the same values as the RAS_EAP_FLAG_ flags in raseapif.h
'
%RASEAPF_NonInteractive = &H00000002
%RASEAPF_Logon          = &H00000004
%RASEAPF_Preview        = &H00000008

' RasGetEapUserIdentity structure.
'
TYPE RASEAPUSERIDENTITYA
    szUserName      AS ASCIIZ * %UNLEN + 1
    dwSizeofEapInfo AS DWORD
    pbEapInfo(0)    AS BYTE
END TYPE

TYPE RASEAPUSERIDENTITYW
    szUserName      AS WSTRINGZ * %UNLEN + 1
    dwSizeofEapInfo AS DWORD
    pbEapInfo(0)    AS BYTE
END TYPE

#IF %DEF(%UNICODE)
TYPE RASEAPUSERIDENTITY
    RASEAPUSERIDENTITYW
END TYPE
#ELSE
TYPE RASEAPUSERIDENTITY
    RASEAPUSERIDENTITYA
END TYPE
#ENDIF

DECLARE FUNCTION PFNRASGETBUFFER (BYVAL ppBuffer AS BYTE PTR, _
    pdwSize AS DWORD) AS DWORD

DECLARE FUNCTION PFNRASFREEBUFFER (BYVAL pBuffer AS BYTE PTR) AS DWORD

DECLARE FUNCTION PFNRASSENDBUFFER (BYVAL hPort AS DWORD, _
    BYVAL pBuffer AS BYTE PTR, BYVAL dwSize AS DWORD) AS DWORD

DECLARE FUNCTION PFNRASRECEIVEBUFFER (BYVAL hPort AS DWORD, _
    BYVAL pBuffer AS BYTE PTR, pdwSize AS DWORD, BYVAL dwTimeOut AS DWORD, _
    BYVAL hEvent AS DWORD) AS DWORD

DECLARE FUNCTION PFNRASRETRIEVEBUFFER (BYVAL hPort AS DWORD, _
    BYVAL pBuffer AS BYTE PTR, pdwSize AS DWORD) AS DWORD

DECLARE FUNCTION RasCustomScriptExecuteFn (BYVAL hPort AS DWORD, _
    lpszPhonebook AS WSTRINGZ, lpszEntryName AS WSTRINGZ, _
    BYVAL pfnRasGetBuffer AS DWORD, BYVAL pfnRasFreeBuffer AS DWORD, _
    BYVAL pfnRasSendBuffer AS DWORD, BYVAL pfnRasReceiveBuffer AS DWORD, _
    BYVAL pfnRasRetrieveBuffer AS DWORD, BYVAL hWnd AS DWORD, _
    pRasDialParams AS RASDIALPARAMS, pvReserved AS ANY) AS DWORD

#ENDIF ' (%WINVER >= &H500)

#IF (%WINVER >= &H0501)

TYPE RASCOMMSETTINGS
    dwSize    AS DWORD
    bParity   AS BYTE
    bStop     AS BYTE
    bByteSize AS BYTE
    bAlign    AS BYTE
END TYPE

DECLARE FUNCTION PFNRASSETCOMMSETTINGS (BYVAL hPort AS DWORD, _
    pRasCommSettings AS RASCOMMSETTINGS, pvReserved AS ANY) AS DWORD

TYPE RASCUSTOMSCRIPTEXTENSIONS
    dwSize                AS DWORD
    pfnRasSetCommSettings AS DWORD  ' PFNRASSETCOMMSETTINGS
END TYPE

#ENDIF


' External RAS API function prototypes.
'
DECLARE FUNCTION RasDialA LIB "RasApi32.dll" ALIAS "RasDialA" _
    (lpRasDialExtensions AS RASDIALEXTENSIONS, lpszPhoneBook AS ASCIIZ, _
    lpRasDialParams AS RASDIALPARAMSA, BYVAL dwNotiferTYPE AS DWORD, _
    lpvNotifier AS ANY, lphRasConn AS DWORD) AS DWORD

DECLARE FUNCTION RasDialW LIB "RasApi32.dll" ALIAS "RasDialW" _
    (lpRasDialExtensions AS RASDIALEXTENSIONS, lpszPhoneBook AS WSTRINGZ, _
    lpRasDialParams AS RASDIALPARAMSW, BYVAL dwNotiferTYPE AS DWORD, _
    lpvNotifier AS ANY, lphRasConn AS DWORD) AS DWORD

DECLARE FUNCTION RasEnumConnectionsA LIB "RasApi32.dll" _
    ALIAS "RasEnumConnectionsA" (lpRasConn AS RASCONNA, lpcb AS DWORD, _
    lpcConnections AS DWORD) AS DWORD

DECLARE FUNCTION RasEnumConnectionsW LIB "RasApi32.dll" _
    ALIAS "RasEnumConnectionsW" (lpRasConn AS RASCONNW, lpcb AS DWORD, _
    lpcConnections AS DWORD) AS DWORD

DECLARE FUNCTION RasEnumEntriesA LIB "RasApi32.dll" ALIAS "RasEnumEntriesA" _
    (szReserved AS ASCIIZ, szPhoneBook AS ASCIIZ, _
    lpRasEntry AS RASENTRYNAMEA, lpCb AS DWORD, lpcEntries AS DWORD) AS DWORD

DECLARE FUNCTION RasEnumEntriesW LIB "RasApi32.dll" ALIAS "RasEnumEntriesW" _
    (szReserved AS WSTRINGZ, szPhoneBook AS WSTRINGZ, _
    lpRasEntry AS RASENTRYNAMEW, lpCb AS DWORD, lpcEntries AS DWORD) AS DWORD

DECLARE FUNCTION RasGetConnectStatusA LIB "RasApi32.dll" _
    ALIAS "RasGetConnectStatusA" (BYVAL hRasConn AS DWORD, _
    lpRasConnStatus AS RASCONNSTATUSA) AS DWORD

DECLARE FUNCTION RasGetConnectStatusW LIB "RasApi32.dll" _
    ALIAS "RasGetConnectStatusW" (BYVAL hRasConn AS DWORD, _
    lpRasConnStatus AS RASCONNSTATUSW) AS DWORD

DECLARE FUNCTION RasGetErrorStringA LIB "RasApi32.dll" _
    ALIAS "RasGetErrorStringA" (BYVAL uErrorValue AS DWORD, _
    lpszErrorString AS ASCIIZ, BYVAL cBufSize AS DWORD) AS DWORD

DECLARE FUNCTION RasGetErrorStringW LIB "RasApi32.dll" _
    ALIAS "RasGetErrorStringW" (BYVAL uErrorValue AS DWORD, _
    lpszErrorString AS WSTRINGZ, BYVAL cBufSize AS DWORD) AS DWORD

DECLARE FUNCTION RasHangUpA LIB "RasApi32.dll" ALIAS "RasHangUpA" _
    (BYVAL hRasConn AS DWORD) AS DWORD

DECLARE FUNCTION RasHangUpW LIB "RasApi32.dll" ALIAS "RasHangUpW" _
    (BYVAL hRasConn AS DWORD) AS DWORD

DECLARE FUNCTION RasGetProjectionInfoA LIB "RasApi32.dll" _
    ALIAS "RasGetProjectionInfoA" (BYVAL hrasconn AS DWORD, _
    BYVAL rasprojection AS RASPROJECTION_enum, lpprojection AS ANY, _
    lpcb AS DWORD) AS DWORD

DECLARE FUNCTION RasGetProjectionInfoW LIB "RasApi32.dll" _
    ALIAS "RasGetProjectionInfoW" (BYVAL hrasconn AS DWORD, _
    BYVAL rasprojection AS RASPROJECTION_enum, lpprojection AS ANY, _
    lpcb AS DWORD) AS DWORD

DECLARE FUNCTION RasCreatePhonebookEntryA LIB "RasApi32.dll" _
    ALIAS "RasCreatePhonebookEntryA" (BYVAL hwnd AS DWORD, _
    lpszPhonebook AS ASCIIZ) AS DWORD

DECLARE FUNCTION RasCreatePhonebookEntryW LIB "RasApi32.dll" _
    ALIAS "RasCreatePhonebookEntryW" (BYVAL hwnd AS DWORD, _
    lpszPhonebook AS WSTRINGZ) AS DWORD

DECLARE FUNCTION RasEditPhonebookEntryA LIB "RasApi32.dll" _
    ALIAS "RasEditPhonebookEntryA" (BYVAL hwnd AS DWORD, _
    lpszPhonebook AS ASCIIZ, lpszEntryName AS ASCIIZ) AS DWORD

DECLARE FUNCTION RasEditPhonebookEntryW LIB "RasApi32.dll" _
    ALIAS "RasEditPhonebookEntryW" (BYVAL hwnd AS DWORD, _
    lpszPhonebook AS WSTRINGZ, lpszEntryName AS WSTRINGZ) AS DWORD

DECLARE FUNCTION RasSetEntryDialParamsA LIB "RasApi32.dll" _
    ALIAS "RasSetEntryDialParamsA" (lpszPhonebook AS ASCIIZ, _
    rdpa AS RASDIALPARAMSA, BYVAL fRemovePassword AS LONG) AS DWORD

DECLARE FUNCTION RasSetEntryDialParamsW LIB "RasApi32.dll" _
    ALIAS "RasSetEntryDialParamsW" (lpszPhonebook AS WSTRINGZ, _
    rdpa AS RASDIALPARAMSW, BYVAL fRemovePassword AS LONG) AS DWORD

DECLARE FUNCTION RasGetEntryDialParamsA LIB "RasApi32.dll" _
    ALIAS "RasGetEntryDialParamsA" (lpszPhonebook AS ASCIIZ, _
    rdpa AS RASDIALPARAMSA, lpfPassword AS LONG) AS DWORD

DECLARE FUNCTION RasGetEntryDialParamsW LIB "RasApi32.dll" _
    ALIAS "RasGetEntryDialParamsW" (lpszPhonebook AS WSTRINGZ, _
    rdpa AS RASDIALPARAMSW, lpfPassword AS LONG) AS DWORD

DECLARE FUNCTION RasEnumDevicesA LIB "RasApi32.dll" _
    ALIAS "RasEnumDevicesA" (lpRasDevInfo AS RASDEVINFOA, lpcb AS DWORD, _
    lpcDevices AS DWORD) AS DWORD

DECLARE FUNCTION RasEnumDevicesW LIB "RasApi32.dll" _
    ALIAS "RasEnumDevicesW" (lpRasDevInfo AS RASDEVINFOW, lpcb AS DWORD, _
    lpcDevices AS DWORD) AS DWORD

DECLARE FUNCTION RasGetCountryInfoA LIB "RasApi32.dll" _
    ALIAS "RasGetCountryInfoA" (lpRasCtryInfo AS RASCTRYINFOA, _
    lpdwSize AS DWORD) AS DWORD

DECLARE FUNCTION RasGetCountryInfoW LIB "RasApi32.dll" _
    ALIAS "RasGetCountryInfoW" (lpRasCtryInfo AS RASCTRYINFOW, _
    lpdwSize AS DWORD) AS DWORD

DECLARE FUNCTION RasGetEntryPropertiesA LIB "RasApi32.dll" _
    ALIAS "RasGetEntryPropertiesA" (lpszPhonebook AS ASCIIZ, _
    lpszEntry AS ASCIIZ, lpRasEntry AS RASENTRYA, lpdwEntryInfoSize AS DWORD, _
    BYVAL lpvDeviceInfo AS BYTE PTR, lpdwDeviceInfoSize AS DWORD) AS DWORD

DECLARE FUNCTION RasGetEntryPropertiesW LIB "RasApi32.dll" _
    ALIAS "RasGetEntryPropertiesW" (lpszPhonebook AS WSTRINGZ, _
    lpszEntry AS WSTRINGZ, lpRasEntry AS RASENTRYW, _
    lpdwEntryInfoSize AS DWORD, BYVAL lpvDeviceInfo AS BYTE PTR, _
    lpdwDeviceInfoSize AS DWORD) AS DWORD

DECLARE FUNCTION RasSetEntryPropertiesA LIB "RasApi32.dll" _
    ALIAS "RasSetEntryPropertiesA" (lpszPhonebook AS ASCIIZ, _
    lpszEntry AS ASCIIZ, lpRasEntry AS RASENTRYA, _
    BYVAL dwEntryInfoSize AS DWORD, BYVAL lpbDeviceInfo AS BYTE PTR, _
    BYVAL dwDeviceInfoSize AS DWORD) AS DWORD

DECLARE FUNCTION RasSetEntryPropertiesW LIB "RasApi32.dll" _
    ALIAS "RasSetEntryPropertiesW" (lpszPhonebook AS WSTRINGZ, _
    lpszEntry AS WSTRINGZ, lpRasEntry AS RASENTRYW, _
    BYVAL dwEntryInfoSize AS DWORD, BYVAL lpbDeviceInfo AS BYTE PTR, _
    BYVAL dwDeviceInfoSize AS DWORD) AS DWORD

DECLARE FUNCTION RasRenameEntryA LIB "RasApi32.dll" ALIAS "RasRenameEntryA" _
    (lpszPhonebook AS ASCIIZ, lpszOldEntry AS ASCIIZ, _
    lpszNewEntry AS ASCIIZ) AS DWORD

DECLARE FUNCTION RasRenameEntryW LIB "RasApi32.dll" ALIAS "RasRenameEntryW" _
    (lpszPhonebook AS WSTRINGZ, lpszOldEntry AS WSTRINGZ, _
    lpszNewEntry AS WSTRINGZ) AS DWORD

DECLARE FUNCTION RasDeleteEntryA LIB "RasApi32.dll" ALIAS "RasDeleteEntryA" _
    (lpszPhonebook AS ASCIIZ, lpszEntry AS ASCIIZ) AS DWORD

DECLARE FUNCTION RasDeleteEntryW LIB "RasApi32.dll" ALIAS "RasDeleteEntryW" _
    (lpszPhonebook AS WSTRINGZ, lpszEntry AS WSTRINGZ) AS DWORD

DECLARE FUNCTION RasValidateEntryNameA LIB "RasApi32.dll" _
    ALIAS "RasValidateEntryNameA" _
    (lpszPhonebook AS ASCIIZ, lpszEntry AS ASCIIZ) AS DWORD

DECLARE FUNCTION RasValidateEntryNameW LIB "RasApi32.dll" _
    ALIAS "RasValidateEntryNameW" _
    (lpszPhonebook AS WSTRINGZ, lpszEntry AS WSTRINGZ) AS DWORD

DECLARE FUNCTION RasConnectionNotificationA LIB "RasApi32.dll" _
    ALIAS "RasConnectionNotificationA" (BYVAL hrasconn AS DWORD, _
    BYVAL hEvent AS DWORD, BYVAL dwFlags AS DWORD) AS DWORD

DECLARE FUNCTION RasConnectionNotificationW LIB "RasApi32.dll" _
    ALIAS "RasConnectionNotificationW" (BYVAL hrasconn AS DWORD, _
    BYVAL hEvent AS DWORD, BYVAL dwFlags AS DWORD) AS DWORD

#IF (%WINVER >= &H401)

DECLARE FUNCTION RasGetSubEntryHandleA LIB "RasApi32.dll" _
    ALIAS "RasGetSubEntryHandleA" (BYVAL hRasConn AS DWORD, _
    BYVAL dwSubEntry AS DWORD, lphRasConn AS DWORD) AS DWORD

DECLARE FUNCTION RasGetSubEntryHandleW LIB "RasApi32.dll" _
    ALIAS "RasGetSubEntryHandleW" (BYVAL hRasConn AS DWORD, _
    BYVAL dwSubEntry AS DWORD, lphRasConn AS DWORD) AS DWORD

DECLARE FUNCTION RasGetCredentialsA LIB "RasApi32.dll" _
    ALIAS "RasGetCredentialsA" (lpszPhonebook AS ASCIIZ, _
    lpszEntry AS ASCIIZ, lpCredentials AS RASCREDENTIALSA) AS DWORD

DECLARE FUNCTION RasGetCredentialsW LIB "RasApi32.dll" _
    ALIAS "RasGetCredentialsW" (lpszPhonebook AS WSTRINGZ, _
    lpszEntry AS WSTRINGZ, lpCredentials AS RASCREDENTIALSW) AS DWORD

DECLARE FUNCTION RasSetCredentialsA LIB "RasApi32.dll" _
    ALIAS "RasSetCredentialsA" (lpszPhonebook AS ASCIIZ, _
    lpszEntry AS ASCIIZ, lpCredentials AS RASCREDENTIALSA, _
    BYVAL fClearCredentials AS LONG) AS DWORD

DECLARE FUNCTION RasSetCredentialsW LIB "RasApi32.dll" _
    ALIAS "RasSetCredentialsW" (lpszPhonebook AS WSTRINGZ, _
    lpszEntry AS WSTRINGZ, lpCredentials AS RASCREDENTIALSW, _
    BYVAL fClearCredentials AS LONG) AS DWORD

DECLARE FUNCTION RasGetSubEntryPropertiesA LIB "RasApi32.dll" _
    ALIAS "RasGetSubEntryPropertiesA" (lpszPhonebook AS ASCIIZ, _
    lpszEntry AS ASCIIZ, BYVAL dwSubEntry AS DWORD, _
    lpRasSubEntry AS RASSUBENTRYA, lpdwcb AS DWORD, lpbDeviceConfig AS BYTE, _
    pd2 AS DWORD) AS DWORD

DECLARE FUNCTION RasGetSubEntryPropertiesW LIB "RasApi32.dll" _
    ALIAS "RasGetSubEntryPropertiesW" (lpszPhonebook AS WSTRINGZ, _
    lpszEntry AS WSTRINGZ, BYVAL dwSubEntry AS DWORD, _
    lpRasSubEntry AS RASSUBENTRYW, lpdwcb AS DWORD, lpbDeviceConfig AS BYTE, _
    pd2 AS DWORD) AS DWORD

DECLARE FUNCTION RasSetSubEntryPropertiesA LIB "RasApi32.dll" _
    ALIAS "RasSetSubEntryPropertiesA" (lpszPhonebook AS ASCIIZ, _
    lpszEntry AS ASCIIZ, BYVAL dwSubEntry AS DWORD, _
    lpRasSubEntry AS RASSUBENTRYA, BYVAL d1 AS DWORD, _
    lpbDeviceConfig AS BYTE, BYVAL lpcbDeviceConfig AS DWORD) AS DWORD

DECLARE FUNCTION RasSetSubEntryPropertiesW LIB "RasApi32.dll" _
    ALIAS "RasSetSubEntryPropertiesW" (lpszPhonebook AS WSTRINGZ, _
    lpszEntry AS WSTRINGZ, BYVAL dwSubEntry AS DWORD, _
    lpRasSubEntry AS RASSUBENTRYW, BYVAL d1 AS DWORD, _
    lpbDeviceConfig AS BYTE, BYVAL lpcbDeviceConfig AS DWORD) AS DWORD

DECLARE FUNCTION RasGetAutodialAddressA LIB "RasApi32.dll" _
    ALIAS "RasGetAutodialAddressA" (lpszAddress AS ASCIIZ, _
    lpdwReserved AS DWORD, BYVAL lpAutoDialEntries AS RASAUTODIALENTRYA PTR, _
    lpdwcbAutoDialEntries AS DWORD, lpdwcAutoDialEntries AS DWORD) AS DWORD

DECLARE FUNCTION RasGetAutodialAddressW LIB "RasApi32.dll" _
    ALIAS "RasGetAutodialAddressW" (lpszAddress AS WSTRINGZ, _
    lpdwReserved AS DWORD, BYVAL lpAutoDialEntries AS RASAUTODIALENTRYW PTR, _
    lpdwcbAutoDialEntries AS DWORD, lpdwcAutoDialEntries AS DWORD) AS DWORD

DECLARE FUNCTION RasSetAutodialAddressA LIB "RasApi32.dll" _
    ALIAS "RasSetAutodialAddressA" (lpszAddress AS ASCIIZ, _
    BYVAL dwReserved AS DWORD, _
    BYVAL lpAutoDialEntries AS RASAUTODIALENTRYA PTR, _
    BYVAL dwcbAutoDialEntries AS DWORD, BYVAL dwcAutoDialEntries AS DWORD) _
    AS DWORD

DECLARE FUNCTION RasSetAutodialAddressW LIB "RasApi32.dll" _
    ALIAS "RasSetAutodialAddressW" (lpszAddress AS WSTRINGZ, _
    BYVAL dwReserved AS DWORD, _
    BYVAL lpAutoDialEntries AS RASAUTODIALENTRYW PTR, _
    BYVAL dwcbAutoDialEntries AS DWORD, BYVAL dwcAutoDialEntries AS DWORD) _
    AS DWORD

DECLARE FUNCTION RasEnumAutodialAddressesA LIB "RasApi32.dll" _
    ALIAS "RasEnumAutodialAddressesA" ( _
    lppRasAutodialAddresses    AS ANY, _
    lpdwcbRasAutodialAddresses AS DWORD, _
    lpdwcRasAutodialAddresses  AS DWORD) AS DWORD

DECLARE FUNCTION RasEnumAutodialAddressesW LIB "RasApi32.dll" _
    ALIAS "RasEnumAutodialAddressesW" ( _
    lppRasAutodialAddresses    AS ANY, _
    lpdwcbRasAutodialAddresses AS DWORD, _
    lpdwcRasAutodialAddresses  AS DWORD) AS DWORD

DECLARE FUNCTION RasGetAutodialEnableA LIB "RasApi32.dll" _
    ALIAS "RasGetAutodialEnableA" (BYVAL dwDialingLocation AS DWORD, _
    lpfEnabled AS LONG) AS DWORD

DECLARE FUNCTION RasGetAutodialEnableW LIB "RasApi32.dll" _
    ALIAS "RasGetAutodialEnableW" (BYVAL dwDialingLocation AS DWORD, _
    lpfEnabled AS LONG) AS DWORD

DECLARE FUNCTION RasSetAutodialEnableA LIB "RasApi32.dll" _
    ALIAS "RasSetAutodialEnableA" (BYVAL dwDialingLocation AS DWORD, _
    BYVAL fEnabled AS LONG) AS DWORD

DECLARE FUNCTION RasSetAutodialEnableW LIB "RasApi32.dll" _
    ALIAS "RasSetAutodialEnableW" (BYVAL dwDialingLocation AS DWORD, _
    BYVAL fEnabled AS LONG) AS DWORD

DECLARE FUNCTION RasGetAutodialParamA LIB "RasApi32.dll" _
    ALIAS "RasGetAutodialParamA" (BYVAL dwKey AS DWORD, lpvValue AS ANY, _
    lpdwcbValue AS DWORD) AS DWORD

DECLARE FUNCTION RasGetAutodialParamW LIB "RasApi32.dll" _
    ALIAS "RasGetAutodialParamW" (BYVAL dwKey AS DWORD, lpvValue AS ANY, _
    lpdwcbValue AS DWORD) AS DWORD

DECLARE FUNCTION RasSetAutodialParamA LIB "RasApi32.dll" _
    ALIAS "RasSetAutodialParamA" (BYVAL dwKey AS DWORD, lpvValue AS ANY, _
    BYVAL dwcbValue AS DWORD) AS DWORD

DECLARE FUNCTION RasSetAutodialParamW LIB "RasApi32.dll" _
    ALIAS "RasSetAutodialParamW" (BYVAL dwKey AS DWORD, lpvValue AS ANY, _
    BYVAL dwcbValue AS DWORD) AS DWORD

#ENDIF

#IF (%WINVER >= &H500)

TYPE RAS_STATS
    dwSize                AS DWORD
    dwBytesXmited         AS DWORD
    dwBytesRcved          AS DWORD
    dwFramesXmited        AS DWORD
    dwFramesRcved         AS DWORD
    dwCrcErr              AS DWORD
    dwTimeoutErr          AS DWORD
    dwAlignmentErr        AS DWORD
    dwHardwareOverrunErr  AS DWORD
    dwFramingErr          AS DWORD
    dwBufferOverrunErr    AS DWORD
    dwCompressionRatioIn  AS DWORD
    dwCompressionRatioOut AS DWORD
    dwBps                 AS DWORD
    dwConnectDuration     AS DWORD
END TYPE

DECLARE FUNCTION RasCustomHangUpFn (BYVAL hRasConn AS DWORD) AS DWORD

DECLARE FUNCTION RasCustomDialFn (BYVAL hInstDll AS DWORD, _
    lpRasDialExtensions AS RASDIALEXTENSIONS, lpszPhonebook AS WSTRINGZ, _
    lpRasDialParams AS RASDIALPARAMS, BYVAL dwNotifierType AS DWORD, _
    lpvNotifier AS ANY, lphRasConn AS DWORD, BYVAL dwFlags AS DWORD) AS DWORD

DECLARE FUNCTION RasCustomDeleteEntryNotifyFn (lpszPhonebook AS WSTRINGZ, _
    lpszEntry AS WSTRINGZ, BYVAL dwFlags AS DWORD) AS DWORD

%RCD_SingleUser = 0
%RCD_AllUsers   = &H00000001
%RCD_Eap        = &H00000002
%RCD_Logon      = &H00000004

DECLARE FUNCTION RasInvokeEapUI LIB "RasApi32.dll" ALIAS "RasInvokeEapUI" _
    (BYVAL hRasConn AS DWORD, BYVAL dwSubEntry AS DWORD, _
    lpExtensions AS RASDIALEXTENSIONS, BYVAL hwnd AS DWORD) AS DWORD

DECLARE FUNCTION RasGetLinkStatistics LIB "RasApi32.dll" _
    ALIAS "RasGetLinkStatistics" (BYVAL hRasConn AS DWORD, _
    BYVAL dwSubEntry AS DWORD, lpStatistics AS RAS_STATS) AS DWORD

DECLARE FUNCTION RasGetConnectionStatistics LIB "RasApi32.dll" _
    ALIAS "RasGetConnectionStatistics" (BYVAL hRasConn AS DWORD, _
    lpStatistics AS RAS_STATS) AS DWORD

DECLARE FUNCTION RasClearLinkStatistics LIB "RasApi32.dll" _
    ALIAS "RasClearLinkStatistics" (BYVAL hRasConn AS DWORD, _
    BYVAL dwSubEntry AS DWORD) AS DWORD

DECLARE FUNCTION RasClearConnectionStatistics LIB "RasApi32.dll" _
    ALIAS "RasClearConnectionStatistics" (BYVAL hRasConn AS DWORD) AS DWORD

DECLARE FUNCTION RasGetEapUserDataA LIB "RasApi32.dll" _
    ALIAS "RasGetEapUserDataA" (BYVAL hToken AS DWORD, _
    pszPhonebook AS ASCIIZ, pszEntry AS ASCIIZ, _
    BYVAL pbEapData AS BYTE PTR, pdwSizeOfEapData AS DWORD) AS DWORD

DECLARE FUNCTION RasGetEapUserDataW LIB "RasApi32.dll" _
    ALIAS "RasGetEapUserDataW" (BYVAL hToken AS DWORD, _
    pszPhonebook AS WSTRINGZ, pszEntry AS WSTRINGZ, _
    BYVAL pbEapData AS BYTE PTR, pdwSizeOfEapData AS DWORD) AS DWORD

DECLARE FUNCTION RasSetEapUserDataA LIB "RasApi32.dll" _
    ALIAS "RasSetEapUserDataA" (BYVAL hToken AS DWORD, _
    pszPhonebook AS ASCIIZ, pszEntry AS ASCIIZ, _
    BYVAL pbEapData AS BYTE PTR, BYVAL dwSizeOfEapData AS DWORD) AS DWORD

DECLARE FUNCTION RasSetEapUserDataW LIB "RasApi32.dll" _
    ALIAS "RasSetEapUserDataW" (BYVAL hToken AS DWORD, _
    pszPhonebook AS WSTRINGZ, pszEntry AS WSTRINGZ, _
    BYVAL pbEapData AS BYTE PTR, BYVAL dwSizeOfEapData AS DWORD) AS DWORD

DECLARE FUNCTION RasGetCustomAuthDataA LIB "RasApi32.dll" _
    ALIAS "RasGetCustomAuthDataA" (pszPhonebook AS ASCIIZ, _
    pszEntry AS ASCIIZ, BYVAL pbCustomAuthData AS BYTE PTR, _
    pdwSizeOfCustomAuthData AS DWORD) AS DWORD

DECLARE FUNCTION RasGetCustomAuthDataW LIB "RasApi32.dll" _
    ALIAS "RasGetCustomAuthDataW" (pszPhonebook AS WSTRINGZ, _
    pszEntry AS WSTRINGZ, BYVAL pbCustomAuthData AS BYTE PTR, _
    pdwSizeOfCustomAuthData AS DWORD) AS DWORD

DECLARE FUNCTION RasSetCustomAuthDataA LIB "RasApi32.dll" _
    ALIAS "RasSetCustomAuthDataA" (pszPhonebook AS ASCIIZ, _
    pszEntry AS ASCIIZ, BYVAL pbCustomAuthData AS BYTE PTR, _
    BYVAL dwSizeOfCustomAuthData AS DWORD) AS DWORD

DECLARE FUNCTION RasSetCustomAuthDataW LIB "RasApi32.dll" _
    ALIAS "RasSetCustomAuthDataW" (pszPhonebook AS WSTRINGZ, _
    pszEntry AS WSTRINGZ, BYVAL pbCustomAuthData AS BYTE PTR, _
    BYVAL dwSizeOfCustomAuthData AS DWORD) AS DWORD

DECLARE FUNCTION RasGetEapUserIdentityW LIB "RasApi32.dll" _
    ALIAS "RasGetEapUserIdentityW" (pszPhonebook AS WSTRINGZ, _
    pszEntry AS WSTRINGZ, BYVAL dwFlags AS DWORD, BYVAL hwnd AS DWORD, _
    ppRasEapUserIdentity AS ANY) AS DWORD

DECLARE FUNCTION RasGetEapUserIdentityA LIB "RasApi32.dll" _
    ALIAS "RasGetEapUserIdentityA" (pszPhonebook AS ASCIIZ, _
    pszEntry AS ASCIIZ, BYVAL dwFlags AS DWORD, BYVAL hwnd AS DWORD, _
    ppRasEapUserIdentity AS ANY) AS DWORD

DECLARE SUB RasFreeEapUserIdentityW LIB "RasApi32.dll" _
    ALIAS "RasFreeEapUserIdentityW" _
    (pRasEapUserIdentity AS RASEAPUSERIDENTITYW)

DECLARE SUB RasFreeEapUserIdentityA LIB "RasApi32.dll" _
    ALIAS "RasFreeEapUserIdentityA" _
    (pRasEapUserIdentity AS RASEAPUSERIDENTITYA)
#ENDIF

#IF (%WINVER >= &H501)

DECLARE FUNCTION RasDeleteSubEntryA LIB "RasApi32.dll" _
    ALIAS "RasDeleteSubEntryA" (pszPhonebook AS ASCIIZ, _
    pszEntry AS ASCIIZ, BYVAL dwSubentryId AS DWORD) AS DWORD

DECLARE FUNCTION RasDeleteSubEntryW LIB "RasApi32.dll" _
    ALIAS "RasDeleteSubEntryW" (pszPhonebook AS WSTRINGZ, _
    pszEntry AS WSTRINGZ, BYVAL dwSubentryId AS DWORD) AS DWORD

' To use Quarantine APIs, applications should explicitly
' define USES_RAS_QUARANTINE_APIS.

#IF %DEF(%USES_RAS_QUARANTINE_APIS)

DECLARE FUNCTION RasGetNapStatus LIB "RasApi32.dll" ALIAS "RasGetNapStatus" _
    (BYVAL hRasconn AS DWORD, pRasNapState AS RASNAPSTATE) AS DWORD

#ENDIF ' USES_RAS_QUARANTINE_APIS


#ENDIF ' #IF (%WINVER >= &H501)

#IF (%WINVER >= &H601)

' Update an active RAS connection.Localendpoint if specified is used for performing
' mobike update.If not specified then dwIfIndex value is used for performing mobike.
' (See RasUpdateConnection)
'
TYPE RASUPDATECONN
    version        AS RASAPIVERSION_enum
    dwSize         AS DWORD
    dwFlags        AS DWORD
    dwIfIndex      AS DWORD
    localEndPoint  AS RASTUNNELENDPOINT
    remoteEndPoint AS RASTUNNELENDPOINT
END TYPE

DECLARE FUNCTION RasUpdateConnection LIB "RasApi32.dll" _
    ALIAS "RasUpdateConnection" (BYVAL hrasconn AS DWORD, _
    lprasupdateconn AS RASUPDATECONN) AS DWORD

' Ras Projection information for PPP or IKEv2
'
DECLARE FUNCTION RasGetProjectionInfoEx LIB "RasApi32.dll" _
    ALIAS "RasGetProjectionInfoEx" (BYVAL hrasconn AS DWORD, _
    pRasProjection AS RAS_PROJECTION_INFO, lpdwSize AS DWORD) AS DWORD

#ENDIF


#IF %DEF(%UNICODE)
MACRO RasDial                   = RasDialW
MACRO RasEnumConnections        = RasEnumConnectionsW
MACRO RasEnumEntries            = RasEnumEntriesW
MACRO RasGetConnectStatus       = RasGetConnectStatusW
MACRO RasGetErrorString         = RasGetErrorStringW
MACRO RasHangUp                 = RasHangUpW
MACRO RasGetProjectionInfo      = RasGetProjectionInfoW
MACRO RasCreatePhonebookEntry   = RasCreatePhonebookEntryW
MACRO RasEditPhonebookEntry     = RasEditPhonebookEntryW
MACRO RasSetEntryDialParams     = RasSetEntryDialParamsW
MACRO RasGetEntryDialParams     = RasGetEntryDialParamsW
MACRO RasEnumDevices            = RasEnumDevicesW
MACRO RasGetCountryInfo         = RasGetCountryInfoW
MACRO RasGetEntryProperties     = RasGetEntryPropertiesW
MACRO RasSetEntryProperties     = RasSetEntryPropertiesW
MACRO RasRenameEntry            = RasRenameEntryW
MACRO RasDeleteEntry            = RasDeleteEntryW
MACRO RasValidateEntryName      = RasValidateEntryNameW
#IF (%WINVER >= &H401)
MACRO RasGetSubEntryHandle      = RasGetSubEntryHandleW
MACRO RasConnectionNotification = RasConnectionNotificationW
MACRO RasGetSubEntryProperties  = RasGetSubEntryPropertiesW
MACRO RasSetSubEntryProperties  = RasSetSubEntryPropertiesW
MACRO RasGetCredentials         = RasGetCredentialsW
MACRO RasSetCredentials         = RasSetCredentialsW
MACRO RasGetAutodialAddress     = RasGetAutodialAddressW
MACRO RasSetAutodialAddress     = RasSetAutodialAddressW
MACRO RasEnumAutodialAddresses  = RasEnumAutodialAddressesW
MACRO RasGetAutodialEnable      = RasGetAutodialEnableW
MACRO RasSetAutodialEnable      = RasSetAutodialEnableW
MACRO RasGetAutodialParam       = RasGetAutodialParamW
MACRO RasSetAutodialParam       = RasSetAutodialParamW
#ENDIF
#IF (%WINVER >= &H500)
MACRO RasGetEapUserData         = RasGetEapUserDataW
MACRO RasSetEapUserData         = RasSetEapUserDataW
MACRO RasGetCustomAuthData      = RasGetCustomAuthDataW
MACRO RasSetCustomAuthData      = RasSetCustomAuthDataW
MACRO RasGetEapUserIdentity     = RasGetEapUserIdentityW
MACRO RasFreeEapUserIdentity    = RasFreeEapUserIdentityW
#ENDIF
#IF (%WINVER >= &H501)
MACRO RasDeleteSubEntry         = RasDeleteSubEntryW
#ENDIF
#ELSE
MACRO RasDial                   = RasDialA
MACRO RasEnumConnections        = RasEnumConnectionsA
MACRO RasEnumEntries            = RasEnumEntriesA
MACRO RasGetConnectStatus       = RasGetConnectStatusA
MACRO RasGetErrorString         = RasGetErrorStringA
MACRO RasHangUp                 = RasHangUpA
MACRO RasGetProjectionInfo      = RasGetProjectionInfoA
MACRO RasCreatePhonebookEntry   = RasCreatePhonebookEntryA
MACRO RasEditPhonebookEntry     = RasEditPhonebookEntryA
MACRO RasSetEntryDialParams     = RasSetEntryDialParamsA
MACRO RasGetEntryDialParams     = RasGetEntryDialParamsA
MACRO RasEnumDevices            = RasEnumDevicesA
MACRO RasGetCountryInfo         = RasGetCountryInfoA
MACRO RasGetEntryProperties     = RasGetEntryPropertiesA
MACRO RasSetEntryProperties     = RasSetEntryPropertiesA
MACRO RasRenameEntry            = RasRenameEntryA
MACRO RasDeleteEntry            = RasDeleteEntryA
MACRO RasValidateEntryName      = RasValidateEntryNameA
#IF (%WINVER >= &H401)
MACRO RasGetSubEntryHandle      = RasGetSubEntryHandleA
MACRO RasConnectionNotification = RasConnectionNotificationA
MACRO RasGetSubEntryProperties  = RasGetSubEntryPropertiesA
MACRO RasSetSubEntryProperties  = RasSetSubEntryPropertiesA
MACRO RasGetCredentials         = RasGetCredentialsA
MACRO RasSetCredentials         = RasSetCredentialsA
MACRO RasGetAutodialAddress     = RasGetAutodialAddressA
MACRO RasSetAutodialAddress     = RasSetAutodialAddressA
MACRO RasEnumAutodialAddresses  = RasEnumAutodialAddressesA
MACRO RasGetAutodialEnable      = RasGetAutodialEnableA
MACRO RasSetAutodialEnable      = RasSetAutodialEnableA
MACRO RasGetAutodialParam       = RasGetAutodialParamA
MACRO RasSetAutodialParam       = RasSetAutodialParamA
#ENDIF
#IF (%WINVER >= &H500)
MACRO RasGetEapUserData         = RasGetEapUserDataA
MACRO RasSetEapUserData         = RasSetEapUserDataA
MACRO RasGetCustomAuthData      = RasGetCustomAuthDataA
MACRO RasSetCustomAuthData      = RasSetCustomAuthDataA
MACRO RasGetEapUserIdentity     = RasGetEapUserIdentityA
MACRO RasFreeEapUserIdentity    = RasFreeEapUserIdentityA
#ENDIF
#IF (%WINVER >= &H501)
MACRO RasDeleteSubEntry         = RasDeleteSubEntryA
#ENDIF
#ENDIF
