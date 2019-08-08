'------------------------------------------------------------------------------
'
'  MprApi.inc
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from MprApi.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%ROUTING_MPRADMIN_H = 1

#INCLUDE "lmcons.inc"
#INCLUDE "ras.inc"
#INCLUDE "in6addr.inc"
#INCLUDE "wincrypt.inc"


'
' Name of the Routing and RemoteAccess Service
'

$RRAS_SERVICE_NAME = "RemoteAccess"
$$RRAS_SERVICE_NAME = "RemoteAccess"$$

'
' Protocol IDs
'

%PID_IPX    = &H0000002B
%PID_IP     = &H00000021
%PID_IPV6   = &H00000057
%PID_NBF    = &H0000003F
%PID_ATALK  = &H00000029


%MAX_INTERFACE_NAME_LEN = 256
%MAX_TRANSPORT_NAME_LEN = 40
%MAX_MEDIA_NAME         = 16
%MAX_PORT_NAME          = 16
%MAX_DEVICE_NAME        = 128
%MAX_PHONE_NUMBER_LEN   = 128
%MAX_DEVICETYPE_NAME    = 16

'
' MPR Interface structures and definitions.
'

'
' MPR Interface types
'

MACRO ROUTER_INTERFACE_TYPE_enum=LONG
ENUM ROUTER_INTERFACE_TYPE SINGULAR
    ROUTER_IF_TYPE_CLIENT
    ROUTER_IF_TYPE_HOME_ROUTER
    ROUTER_IF_TYPE_FULL_ROUTER
    ROUTER_IF_TYPE_DEDICATED
    ROUTER_IF_TYPE_INTERNAL
    ROUTER_IF_TYPE_LOOPBACK
    ROUTER_IF_TYPE_TUNNEL1
    ROUTER_IF_TYPE_DIALOUT
    ROUTER_IF_TYPE_MAX       ' do not use.Illegal
END ENUM

MACRO ROUTER_CONNECTION_STATE_enum=LONG
ENUM ROUTER_CONNECTION_STATE SINGULAR
    ROUTER_IF_STATE_UNREACHABLE
    ROUTER_IF_STATE_DISCONNECTED
    ROUTER_IF_STATE_CONNECTING
    ROUTER_IF_STATE_CONNECTED
END ENUM

%MPR_INTERFACE_OUT_OF_RESOURCES          = &H00000001
%MPR_INTERFACE_ADMIN_DISABLED            = &H00000002
%MPR_INTERFACE_CONNECTION_FAILURE        = &H00000004
%MPR_INTERFACE_SERVICE_PAUSED            = &H00000008
%MPR_INTERFACE_DIALOUT_HOURS_RESTRICTION = &H00000010
%MPR_INTERFACE_NO_MEDIA_SENSE            = &H00000020
%MPR_INTERFACE_NO_DEVICE                 = &H00000040

TYPE MPR_INTERFACE_0
    wszInterfaceName       AS WSTRINGZ * %MAX_INTERFACE_NAME_LEN+1
    hInterface             AS DWORD   ' HANDLE
    fEnabled               AS LONG    ' BOOL
    dwIfType               AS ROUTER_INTERFACE_TYPE_enum
    dwConnectionState      AS ROUTER_CONNECTION_STATE_enum
    fUnReachabilityReasons AS DWORD
    dwLastError            AS DWORD
END TYPE

TYPE MPR_IPINIP_INTERFACE_0
    wszFriendlyName AS WSTRINGZ * %MAX_INTERFACE_NAME_LEN+1
    guidX           AS GUID
END TYPE

#IF (%WINVER >= &H0500)

TYPE MPR_INTERFACE_1
    wszInterfaceName            AS WSTRINGZ * %MAX_INTERFACE_NAME_LEN+1
    hInterface                  AS DWORD   ' HANDLE
    fEnabled                    AS LONG    ' BOOL
    dwIfType                    AS ROUTER_INTERFACE_TYPE_enum
    dwConnectionState           AS ROUTER_CONNECTION_STATE_enum
    fUnReachabilityReasons      AS DWORD
    dwLastError                 AS DWORD
    lpwsDialoutHoursRestriction AS WSTRINGZ PTR
END TYPE

'
' MPR_INTERFACE_2 definitions
'

%MPR_MaxDeviceType     = %RAS_MaxDeviceType
%MPR_MaxPhoneNumber    = %RAS_MaxPhoneNumber
%MPR_MaxIpAddress      = %RAS_MaxIpAddress
%MPR_MaxIpxAddress     = %RAS_MaxIpxAddress

%MPR_MaxEntryName      = %RAS_MaxEntryName
%MPR_MaxDeviceName     = %RAS_MaxDeviceName
%MPR_MaxCallbackNumber = %RAS_MaxCallbackNumber

%MPR_MaxAreaCode       = %RAS_MaxAreaCode
%MPR_MaxPadType        = %RAS_MaxPadType
%MPR_MaxX25Address     = %RAS_MaxX25Address
%MPR_MaxFacilities     = %RAS_MaxFacilities
%MPR_MaxUserData       = %RAS_MaxUserData

'
' MPR_INTERFACE_2 'dwfOptions' bit flags.
'

%MPRIO_SpecificIpAddr         = %RASEO_SpecificIpAddr
%MPRIO_SpecificNameServers    = %RASEO_SpecificNameServers
%MPRIO_IpHeaderCompression    = %RASEO_IpHeaderCompression
%MPRIO_RemoteDefaultGateway   = %RASEO_RemoteDefaultGateway
%MPRIO_DisableLcpExtensions   = %RASEO_DisableLcpExtensions
%MPRIO_SwCompression          = %RASEO_SwCompression
%MPRIO_RequireEncryptedPw     = %RASEO_RequireEncryptedPw
%MPRIO_RequireMsEncryptedPw   = %RASEO_RequireMsEncryptedPw
%MPRIO_RequireDataEncryption  = %RASEO_RequireDataEncryption
%MPRIO_NetworkLogon           = %RASEO_NetworkLogon
%MPRIO_PromoteAlternates      = %RASEO_PromoteAlternates
%MPRIO_SecureLocalFiles       = %RASEO_SecureLocalFiles
%MPRIO_RequireEAP             = %RASEO_RequireEAP
%MPRIO_RequirePAP             = %RASEO_RequirePAP
%MPRIO_RequireSPAP            = %RASEO_RequireSPAP
%MPRIO_SharedPhoneNumbers     = %RASEO_SharedPhoneNumbers
%MPRIO_RequireCHAP            = %RASEO_RequireCHAP
%MPRIO_RequireMsCHAP          = %RASEO_RequireMsCHAP
%MPRIO_RequireMsCHAP2         = %RASEO_RequireMsCHAP2

#IF (%WINVER >= &H501)
%MPRIO_IpSecPreSharedKey      = &H80000000???
#ENDIF

'
' MPR_INTERFACE_2 'dwProtocols' bit flags.
'

%MPRNP_Ipx                    = %RASNP_Ipx
%MPRNP_Ip                     = %RASNP_Ip
#IF (%WINVER >= &H600)
%MPRNP_Ipv6                   = %RASNP_Ipv6
#ENDIF

'
' MPR_INTERFACE_2 'szDeviceType' default strings.
'

$MPRDT_Modem      = $RASDT_Modem
$MPRDT_Isdn       = $RASDT_Isdn
$MPRDT_X25        = $RASDT_X25
$MPRDT_Vpn        = $RASDT_Vpn
$MPRDT_Pad        = $RASDT_Pad
$MPRDT_Generic    = $RASDT_Generic
$MPRDT_Serial     = $RASDT_Serial
$MPRDT_FrameRelay = $RASDT_FrameRelay
$MPRDT_Atm        = $RASDT_Atm
$MPRDT_Sonet      = $RASDT_Sonet
$MPRDT_SW56       = $RASDT_SW56
$MPRDT_Irda       = $RASDT_Irda
$MPRDT_Parallel   = $RASDT_Parallel

$$MPRDT_Modem      = $$RASDT_Modem
$$MPRDT_Isdn       = $$RASDT_Isdn
$$MPRDT_X25        = $$RASDT_X25
$$MPRDT_Vpn        = $$RASDT_Vpn
$$MPRDT_Pad        = $$RASDT_Pad
$$MPRDT_Generic    = $$RASDT_Generic
$$MPRDT_Serial     = $$RASDT_Serial
$$MPRDT_FrameRelay = $$RASDT_FrameRelay
$$MPRDT_Atm        = $$RASDT_Atm
$$MPRDT_Sonet      = $$RASDT_Sonet
$$MPRDT_SW56       = $$RASDT_SW56
$$MPRDT_Irda       = $$RASDT_Irda
$$MPRDT_Parallel   = $$RASDT_Parallel

'
' MPR_INTERFACE_2 'dwType' settings
'

%MPRET_Phone  = %RASET_Phone
%MPRET_Vpn    = %RASET_Vpn
' [the existence of %RASET_Direct depends on the Windows version]
#IF %DEF(%RASET_Direct)
%MPRET_Direct = %RASET_Direct
#ENDIF

'
' MPR_INTERFACE_2 'dwDialMode' values.
'

%MPRDM_DialFirst    = 0
%MPRDM_DialAll      = %RASEDM_DialAll
%MPRDM_DialAsNeeded = %RASEDM_DialAsNeeded

'
' MPR_INTERFACE_2 'dwIdleDisconnectSeconds' constants.
'

%MPRIDS_Disabled       = %RASIDS_Disabled
%MPRIDS_UseGlobalValue = %RASIDS_UseGlobalValue

'
' MPR_INTERFACE_2 encryption types.
'

%MPR_ET_None       = %ET_None
%MPR_ET_Require    = %ET_Require
%MPR_ET_RequireMax = %ET_RequireMax
%MPR_ET_Optional   = %ET_Optional

'
' MPR_INTERFACE_2 Vpn strategies
'

%MPR_VS_Default    = %VS_Default
%MPR_VS_PptpOnly   = %VS_PptpOnly
%MPR_VS_PptpFirst  = %VS_PptpFirst
%MPR_VS_L2tpOnly   = %VS_L2tpOnly
%MPR_VS_L2tpFirst  = %VS_L2tpFirst

'
' Used to create/get/set a demand dial interface plus its
' ras configuration.
'

TYPE MPR_INTERFACE_2
    wszInterfaceName       AS WSTRINGZ * %MAX_INTERFACE_NAME_LEN+1
    hInterface             AS DWORD   ' HANDLE
    fEnabled               AS LONG    ' BOOL
    dwIfType               AS ROUTER_INTERFACE_TYPE_enum
    dwConnectionState      AS ROUTER_CONNECTION_STATE_enum
    fUnReachabilityReasons AS DWORD
    dwLastError            AS DWORD

    '
    ' Demand dial-specific properties
    '

    dwfOptions             AS DWORD

    '
    ' Location/phone number
    '

    szLocalPhoneNumber     AS WSTRINGZ * %RAS_MaxPhoneNumber + 1
    szAlternates           AS WSTRINGZ PTR

    '
    ' PPP/Ip
    '

    ipaddr                 AS DWORD
    ipaddrDns              AS DWORD
    ipaddrDnsAlt           AS DWORD
    ipaddrWins             AS DWORD
    ipaddrWinsAlt          AS DWORD

    '
    ' NetProtocols
    '

    dwfNetProtocols        AS DWORD

    '
    ' Device
    '

    szDeviceType           AS WSTRINGZ * %MPR_MaxDeviceType + 1
    szDeviceName           AS WSTRINGZ * %MPR_MaxDeviceName + 1

    '
    ' X.25
    '

    szX25PadType           AS WSTRINGZ * %MPR_MaxPadType + 1
    szX25Address           AS WSTRINGZ * %MPR_MaxX25Address + 1
    szX25Facilities        AS WSTRINGZ * %MPR_MaxFacilities + 1
    szX25UserData          AS WSTRINGZ * %MPR_MaxUserData + 1
    dwChannels             AS DWORD

    '
    ' Multilink
    '

    dwSubEntries           AS DWORD
    dwDialMode             AS DWORD
    dwDialExtraPercent     AS DWORD
    dwDialExtraSampleSeconds   AS DWORD
    dwHangUpExtraPercent       AS DWORD
    dwHangUpExtraSampleSeconds AS DWORD

    '
    ' Idle timeout
    '

    dwIdleDisconnectSeconds    AS DWORD

    '
    ' Entry Type
    '

    dwType                 AS DWORD

    '
    ' EncryptionType
    '

    dwEncryptionType       AS DWORD

    '
    ' EAP information
    '

    dwCustomAuthKey        AS DWORD
    dwCustomAuthDataSize   AS DWORD
    lpbCustomAuthData      AS BYTE PTR

    '
    ' Guid of the connection
    '

    guidId                 AS GUID

    '
    ' Vpn Strategy
    '

    dwVpnStrategy          AS DWORD

END TYPE


#IF (%WINVER >= &H0600)

TYPE MPR_INTERFACE_3
    wszInterfaceName       AS WSTRINGZ * %MAX_INTERFACE_NAME_LEN+1
    hInterface             AS DWORD   ' HANDLE
    fEnabled               AS LONG    ' BOOL
    dwIfType               AS ROUTER_INTERFACE_TYPE_enum
    dwConnectionState      AS ROUTER_CONNECTION_STATE_enum
    fUnReachabilityReasons AS DWORD
    dwLastError            AS DWORD

    '
    ' Demand dial-specific properties
    '

    dwfOptions             AS DWORD

    '
    ' Location/phone number
    '

    szLocalPhoneNumber     AS WSTRINGZ * %RAS_MaxPhoneNumber + 1
    szAlternates           AS WSTRINGZ PTR

    '
    ' PPP/Ip
    '

    ipaddr                 AS DWORD
    ipaddrDns              AS DWORD
    ipaddrDnsAlt           AS DWORD
    ipaddrWins             AS DWORD
    ipaddrWinsAlt          AS DWORD





    '
    ' NetProtocols
    '

    dwfNetProtocols        AS DWORD

    '
    ' Device
    '

    szDeviceType           AS WSTRINGZ * %MPR_MaxDeviceType + 1
    szDeviceName           AS WSTRINGZ * %MPR_MaxDeviceName + 1

    '
    ' X.25
    '

    szX25PadType           AS WSTRINGZ * %MPR_MaxPadType + 1
    szX25Address           AS WSTRINGZ * %MPR_MaxX25Address + 1
    szX25Facilities        AS WSTRINGZ * %MPR_MaxFacilities + 1
    szX25UserData          AS WSTRINGZ * %MPR_MaxUserData + 1
    dwChannels             AS DWORD

    '
    ' Multilink
    '

    dwSubEntries           AS DWORD
    dwDialMode             AS DWORD
    dwDialExtraPercent     AS DWORD
    dwDialExtraSampleSeconds   AS DWORD
    dwHangUpExtraPercent       AS DWORD
    dwHangUpExtraSampleSeconds AS DWORD

    '
    ' Idle timeout
    '

    dwIdleDisconnectSeconds    AS DWORD

    '
    ' Entry Type
    '

    dwType                 AS DWORD

    '
    ' EncryptionType
    '

    dwEncryptionType       AS DWORD

    '
    ' EAP information
    '

    dwCustomAuthKey        AS DWORD
    dwCustomAuthDataSize   AS DWORD
    lpbCustomAuthData      AS BYTE PTR

    '
    ' Guid of the connection
    '

    guidId                 AS GUID

    '
    ' Vpn Strategy
    '

    dwVpnStrategy          AS DWORD

    AddressCount           AS DWORD
    ipv6addrDns            AS IN6_ADDR
    ipv6addrDnsAlt         AS IN6_ADDR
    ipv6addr               AS IN6_ADDR PTR
END TYPE

#ENDIF ' %WINVER >= &H0600

'
' Used to set/get per-link information for multilinked demand
' dial interfaces.
'

TYPE MPR_DEVICE_0
    '
    ' Device
    '

    szDeviceType          AS WSTRINGZ * %MPR_MaxDeviceType + 1
    szDeviceName          AS WSTRINGZ * %MPR_MaxDeviceName + 1
END TYPE


TYPE MPR_DEVICE_1
    '
    ' Device
    '

    szDeviceType          AS WSTRINGZ * %MPR_MaxDeviceType + 1
    szDeviceName          AS WSTRINGZ * %MPR_MaxDeviceName + 1

    '
    ' Phone numbers
    '

    szLocalPhoneNumber    AS WSTRINGZ * %MPR_MaxPhoneNumber + 1
    szAlternates          AS WSTRINGZ PTR
END TYPE

'
' Used to get/set extended credentials information such as
' eap credentials info.
'

TYPE MPR_CREDENTIALSEX_0
    dwSize                AS DWORD
    lpbCredentialsInfo    AS BYTE PTR
END TYPE

TYPE MPR_CREDENTIALSEX_1
    dwSize                AS DWORD
    lpbCredentialsInfo    AS BYTE PTR
END TYPE

#ENDIF ' %WINVER >= &H0500

TYPE MPR_TRANSPORT_0
    dwTransportId         AS DWORD
    hTransport            AS DWORD   ' HANDLE
    wszTransportName      AS WSTRINGZ * %MAX_TRANSPORT_NAME_LEN+1
END TYPE


TYPE MPR_IFTRANSPORT_0
    dwTransportId         AS DWORD
    hIfTransport          AS DWORD   ' HANDLE
    wszIfTransportName    AS WSTRINGZ * %MAX_TRANSPORT_NAME_LEN+1
END TYPE


TYPE MPR_SERVER_0
    fLanOnlyMode          AS LONG   ' BOOL
    dwUpTime              AS DWORD                              ' In seconds
    dwTotalPorts          AS DWORD
    dwPortsInUse          AS DWORD
END TYPE


#IF (%WINVER >= &H501)

'
' values for dwFlags in MPR_SERVER_1. This enables the ports for Ras or Routing.
'

%MPR_ENABLE_RAS_ON_DEVICE     = &H00000001
%MPR_ENABLE_ROUTING_ON_DEVICE = &H00000002

TYPE MPR_SERVER_1
    dwNumPptpPorts        AS DWORD
    dwPptpPortFlags       AS DWORD
    dwNumL2tpPorts        AS DWORD
    dwL2tpPortFlags       AS DWORD
END TYPE

#ENDIF


#IF (%WINVER >= &H600)

'
' MPR_SERVER_2 structure.
'

TYPE MPR_SERVER_2
    dwNumPptpPorts        AS DWORD
    dwPptpPortFlags       AS DWORD
    dwNumL2tpPorts        AS DWORD
    dwL2tpPortFlags       AS DWORD
    dwNumSstpPorts        AS DWORD
    dwSstpPortFlags       AS DWORD
END TYPE

#ENDIF


'
' Port condition codes
'

MACRO RAS_PORT_CONDITION_enum=LONG
ENUM RAS_PORT_CONDITION SINGULAR
    RAS_PORT_NON_OPERATIONAL
    RAS_PORT_DISCONNECTED
    RAS_PORT_CALLING_BACK
    RAS_PORT_LISTENING
    RAS_PORT_AUTHENTICATING
    RAS_PORT_AUTHENTICATED
    RAS_PORT_INITIALIZING
END ENUM

'
' Hardware condition codes
'

MACRO RAS_HARDWARE_CONDITION_enum=LONG
ENUM RAS_HARDWARE_CONDITION SINGULAR
    RAS_HARDWARE_OPERATIONAL
    RAS_HARDWARE_FAILURE
END ENUM

TYPE RAS_PORT_0
    hPort                 AS DWORD   ' HANDLE
    hConnection           AS DWORD   ' HANDLE
    dwPortCondition       AS RAS_PORT_CONDITION_enum
    dwTotalNumberOfCalls  AS DWORD
    dwConnectDuration     AS DWORD   ' In seconds
    wszPortName           AS WSTRINGZ * %MAX_PORT_NAME + 1
    wszMediaName          AS WSTRINGZ * %MAX_MEDIA_NAME + 1
    wszDeviceName         AS WSTRINGZ * %MAX_DEVICE_NAME + 1
    wszDeviceType         AS WSTRINGZ * %MAX_DEVICETYPE_NAME + 1
END TYPE

TYPE RAS_PORT_1
    hPort                 AS DWORD  ' HANDLE
    hConnection           AS DWORD  ' HANDLE
    dwHardwareCondition   AS RAS_HARDWARE_CONDITION_enum
    dwLineSpeed           AS DWORD   ' in bits/second
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
END TYPE

'
' Maximum length of address string, e.g. "255.255.255.255" for IP.
'

%IPADDRESSLEN   = 15
%IPXADDRESSLEN  = 22
%ATADDRESSLEN   = 32
%MAXIPADRESSLEN = 64


TYPE PPP_NBFCP_INFO
    dwError               AS DWORD
    wszWksta              AS WSTRINGZ * %NETBIOS_NAME_LEN + 1
END TYPE

TYPE PPP_IPCP_INFO
    dwError               AS DWORD
    wszAddress            AS WSTRINGZ * %IPADDRESSLEN + 1
    wszRemoteAddress      AS WSTRINGZ * %IPADDRESSLEN + 1
END TYPE

'
' PPP_IPCP_INFO2 dwOptions values.
'

%PPP_IPCP_VJ = &H00000001

TYPE PPP_IPCP_INFO2
    dwError               AS DWORD
    wszAddress            AS WSTRINGZ * %IPADDRESSLEN + 1
    wszRemoteAddress      AS WSTRINGZ * %IPADDRESSLEN + 1
    dwOptions             AS DWORD
    dwRemoteOptions       AS DWORD
END TYPE

TYPE PPP_IPXCP_INFO
    dwError               AS DWORD
    wszAddress            AS WSTRINGZ * %IPXADDRESSLEN + 1
END TYPE

TYPE PPP_ATCP_INFO
    dwError               AS DWORD
    wszAddress            AS WSTRINGZ * %ATADDRESSLEN + 1
END TYPE


#IF (%WINVER >= &H0600)

TYPE PPP_IPV6_CP_INFO
    dwVersion             AS DWORD
    dwSize                AS DWORD
    dwError               AS DWORD
    bInterfaceIdentifier(7)       AS BYTE
    bRemoteInterfaceIdentifier(7) AS BYTE
    dwOptions             AS DWORD
    dwRemoteOptions       AS DWORD
    bPrefix(7)            AS BYTE
    dwPrefixLength        AS DWORD
END TYPE

#ENDIF ' %WINVER >= &H0600

TYPE PPP_INFO
    nbf                   AS PPP_NBFCP_INFO
    ip                    AS PPP_IPCP_INFO
    ipx                   AS PPP_IPXCP_INFO
    AT                    AS PPP_ATCP_INFO
END TYPE


#IF (%WINVER >= &H0500)

'
' PPP_CCP dwCompressionAlgorithm values.
'

%RASCCPCA_MPPC        = &H00000006
%RASCCPCA_STAC        = &H00000005

'
' PPP_CCP dwOptions values.
'

%PPP_CCP_COMPRESSION        = &H00000001
%PPP_CCP_ENCRYPTION40BITOLD = &H00000010
%PPP_CCP_ENCRYPTION40BIT    = &H00000020
%PPP_CCP_ENCRYPTION128BIT   = &H00000040
%PPP_CCP_ENCRYPTION56BIT    = &H00000080
%PPP_CCP_HISTORYLESS        = &H01000000

TYPE PPP_CCP_INFO
    dwError                      AS DWORD
    dwCompressionAlgorithm       AS DWORD
    dwOptions                    AS DWORD
    dwRemoteCompressionAlgorithm AS DWORD
    dwRemoteOptions              AS DWORD
END TYPE

'
' PPP_LCP dwAuthenticatonProtocol values.
'

%PPP_LCP_PAP         = &H0000C023
%PPP_LCP_SPAP        = &H0000C027
%PPP_LCP_CHAP        = &H0000C223
%PPP_LCP_EAP         = &H0000C227

'
' PPP_LCP dwAuthenticatonData values.
'

%PPP_LCP_CHAP_MD5    = &H0005
%PPP_LCP_CHAP_MS     = &H0080
%PPP_LCP_CHAP_MSV2   = &H0081

'
' PPP_LCP dwOption values
'

%PPP_LCP_MULTILINK_FRAMING = &H00000001
%PPP_LCP_PFC               = &H00000002
%PPP_LCP_ACFC              = &H00000004
%PPP_LCP_SSHF              = &H00000008
%PPP_LCP_DES_56            = &H00000010
%PPP_LCP_3_DES             = &H00000020

#IF (%WINVER >= &H0600)
%PPP_LCP_AES_128           = &H00000040
%PPP_LCP_AES_256           = &H00000080
#ENDIF ' %WINVER >= &H0600

TYPE PPP_LCP_INFO
    dwError                        AS DWORD
    dwAuthenticationProtocol       AS DWORD
    dwAuthenticationData           AS DWORD
    dwRemoteAuthenticationProtocol AS DWORD
    dwRemoteAuthenticationData     AS DWORD
    dwTerminateReason              AS DWORD
    dwRemoteTerminateReason        AS DWORD
    dwOptions                      AS DWORD
    dwRemoteOptions                AS DWORD
    dwEapTypeId                    AS DWORD
    dwRemoteEapTypeId              AS DWORD
END TYPE

TYPE PPP_INFO_2
    nbf AS PPP_NBFCP_INFO
    ip  AS PPP_IPCP_INFO2
    ipx AS PPP_IPXCP_INFO
    AT  AS PPP_ATCP_INFO
    ccp AS PPP_CCP_INFO
    lcp AS PPP_LCP_INFO
END TYPE

#ENDIF ' %WINVER >= &H0500

#IF (%WINVER >= &H0600)
TYPE PPP_INFO_3
    nbf  AS PPP_NBFCP_INFO
    ip   AS PPP_IPCP_INFO2
    ipv6 AS PPP_IPV6_CP_INFO
    ccp  AS PPP_CCP_INFO
    lcp  AS PPP_LCP_INFO
END TYPE

#ENDIF ' %WINVER >= &H0600

'
' Possible bits set in Connection Flags field
'

%RAS_FLAGS_PPP_CONNECTION      = &H00000001
%RAS_FLAGS_MESSENGER_PRESENT   = &H00000002

#IF (%WINVER < &H0501)
%RAS_FLAGS_RAS_CONNECTION      = &H00000004
#ENDIF

%RAS_FLAGS_QUARANTINE_PRESENT  = &H00000008

#IF (%WINVER >= &H0601)
%RAS_FLAGS_DORMANT             = &H00000020
#ENDIF

TYPE RAS_CONNECTION_0
    hConnection       AS DWORD   ' HANDLE
    hInterface        AS DWORD   ' HANDLE
    dwConnectDuration AS DWORD                         ' In seconds
    dwInterfaceType   AS ROUTER_INTERFACE_TYPE_enum
    dwConnectionFlags AS DWORD
    wszInterfaceName  AS WSTRINGZ * %MAX_INTERFACE_NAME_LEN + 1
    wszUserName       AS WSTRINGZ * %UNLEN + 1
    wszLogonDomain    AS WSTRINGZ * %DNLEN + 1
    wszRemoteComputer AS WSTRINGZ * %NETBIOS_NAME_LEN + 1
END TYPE

TYPE RAS_CONNECTION_1
    hConnection           AS DWORD   ' HANDLE
    hInterface            AS DWORD   ' HANDLE
    PppInfo               AS PPP_INFO
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
END TYPE

#IF (%WINVER >= &H0500)

TYPE RAS_CONNECTION_2
    hConnection           AS DWORD   ' HANDLE
    wszUserName AS WSTRINGZ * %UNLEN + 1
    dwInterfaceType       AS ROUTER_INTERFACE_TYPE_enum
    guidX                 AS GUID
    PppInfo2              AS PPP_INFO_2
END TYPE

'indicates quarantine state of a client connection
MACRO RAS_QUARANTINE_STATE_enum=LONG
ENUM RAS_QUARANTINE_STATE SINGULAR
    RAS_QUAR_STATE_NORMAL
    RAS_QUAR_STATE_QUARANTINE
    RAS_QUAR_STATE_PROBATION
    RAS_QUAR_STATE_NOT_CAPABLE
END ENUM

#ENDIF ' %WINVER >= &H0500

#IF (%WINVER >= &H0600)

TYPE RAS_CONNECTION_3
    dwVersion       AS DWORD
    dwSize          AS DWORD
    hConnection     AS DWORD   ' HANDLE          ' connection handle
    wszUserName     AS WSTRINGZ * %UNLEN + 1
    dwInterfaceType AS ROUTER_INTERFACE_TYPE_enum
    guidX           AS GUID
    PppInfo3        AS PPP_INFO_3
    rasQuarState    AS RAS_QUARANTINE_STATE_enum ' Quarantine state of the connection
    TIMER           AS FILETIME                  ' Probation timer in UTC
END TYPE

#ENDIF ' %WINVER >= &H0600

'
' Structures used by the MPRADMIN USER APIs. Use level 0 to get/set this
' structure.
'
'
' Bits indicating user's Remote Access privileges and mask to isolate
' call back privilege.
'
' Note: Bit 0 MUST represent NoCallback due to a quirk of the "userparms"
'       storage method.  When a new LAN Manager user is created, bit 0 of the
'       userparms field is set to 1 and all other bits are 0.  These bits are
'       arranged so this "no Dial-In info" state maps to the "default Dial-In
'       privilege" state.

%RASPRIV_NoCallback        = &H01
%RASPRIV_AdminSetCallback  = &H02
%RASPRIV_CallerSetCallback = &H04
%RASPRIV_DialinPrivilege   = &H08

'
' The following are flags for the bfPrivilege2 member of RAS_USER_1
' structure
'
%RASPRIV2_DialinPolicy      = &H1

%RASPRIV_CallbackType = (%RASPRIV_AdminSetCallback _
                      OR %RASPRIV_CallerSetCallback _
                      OR %RASPRIV_NoCallback)

TYPE RAS_USER_0
    bfPrivilege    AS BYTE
    wszPhoneNumber AS WSTRINGZ * %MAX_PHONE_NUMBER_LEN + 1
END TYPE

TYPE RAS_USER_1
    bfPrivilege    AS BYTE
    wszPhoneNumber AS WSTRINGZ * %MAX_PHONE_NUMBER_LEN + 1
    bfPrivilege2   AS BYTE
END TYPE

#IF (%WINVER >= &H0600)
TYPE MPR_FILTER_0
    fEnable        AS LONG   ' BOOL
END TYPE

#ENDIF ' %WINVER >= &H0600

'
' Used as RPC binding handle to server
'

MACRO RAS_SERVER_HANDLE=DWORD
MACRO MPR_SERVER_HANDLE=DWORD
MACRO MIB_SERVER_HANDLE=DWORD

#IF (%WINVER >= &H0601)

TYPE MPRAPI_OBJECT_HEADER
    revision       AS BYTE
    TYPE           AS BYTE
    SIZE           AS WORD
END TYPE


MACRO MPRAPI_OBJECT_TYPE_enum=LONG
ENUM MPRAPI_OBJECT_TYPE SINGULAR
    MPRAPI_OBJECT_TYPE_RAS_CONNECTION_OBJECT        = 1
    MPRAPI_OBJECT_TYPE_MPR_SERVER_OBJECT
    MPRAPI_OBJECT_TYPE_MPR_SERVER_SET_CONFIG_OBJECT
    MPRAPI_OBJECT_TYPE_AUTH_VALIDATION_OBJECT
    MPRAPI_OBJECT_TYPE_UPDATE_CONNECTION_OBJECT
END ENUM


TYPE PPP_PROJECTION_INFO

    ' IPv4 Projection Parameters
    dwIPv4NegotiationError  AS DWORD
    wszAddress              AS WSTRINGZ * %IPADDRESSLEN + 1
    wszRemoteAddress        AS WSTRINGZ * %IPADDRESSLEN + 1
    dwIPv4Options           AS DWORD
    dwIPv4RemoteOptions     AS DWORD
    IPv4SubInterfaceIndex   AS QUAD   ' ULONG64

    ' IPv6 Projection Parameters
    dwIPv6NegotiationError         AS DWORD
    bInterfaceIdentifier(7)        AS BYTE
    bRemoteInterfaceIdentifier(7)  AS BYTE
    bPrefix(7)                     AS BYTE
    dwPrefixLength                 AS DWORD
    IPv6SubInterfaceIndex          AS QUAD    ' ULONG64
    ' LCP Options
    dwLcpError                     AS DWORD
    dwAuthenticationProtocol       AS DWORD
    dwAuthenticationData           AS DWORD
    dwRemoteAuthenticationProtocol AS DWORD
    dwRemoteAuthenticationData     AS DWORD
    dwLcpTerminateReason           AS DWORD
    dwLcpRemoteTerminateReason     AS DWORD
    dwLcpOptions                   AS DWORD
    dwLcpRemoteOptions             AS DWORD
    dwEapTypeId                    AS DWORD
    dwRemoteEapTypeId              AS DWORD

    ' CCP options:
    dwCcpError                     AS DWORD
    dwCompressionAlgorithm         AS DWORD
    dwCcpOptions                   AS DWORD
    dwRemoteCompressionAlgorithm   AS DWORD
    dwCcpRemoteOptions             AS DWORD
END TYPE

%MPRAPI_IKEV2_AUTH_USING_CERT = 1
%MPRAPI_IKEV2_AUTH_USING_EAP  = 2

TYPE IKEV2_PROJECTION_INFO
    dwIPv4NegotiationError         AS DWORD
    wszAddress                     AS WSTRINGZ * %IPADDRESSLEN + 1
    wszRemoteAddress               AS WSTRINGZ * %IPADDRESSLEN + 1
    IPv4SubInterfaceIndex          AS QUAD   ' ULONG64

    dwIPv6NegotiationError         AS DWORD
    bInterfaceIdentifier(7)        AS BYTE
    bRemoteInterfaceIdentifier(7)  AS BYTE
    bPrefix(7)                     AS BYTE
    dwPrefixLength                 AS DWORD
    IPv6SubInterfaceIndex          AS QUAD   ' ULONG64

    dwOptions                      AS DWORD

    dwAuthenticationProtocol       AS DWORD
    dwEapTypeId                    AS DWORD
    dwCompressionAlgorithm         AS DWORD
    dwEncryptionMethod             AS DWORD
END TYPE

%MPRAPI_PPP_PROJECTION_INFO_TYPE   = 1
%MPRAPI_IKEV2_PROJECTION_INFO_TYPE = 2

UNION PROJECTION_INFO_union
    PppProjectionInfo          AS PPP_PROJECTION_INFO
    Ikev2ProjectionInfo        AS IKEV2_PROJECTION_INFO
END UNION

TYPE PROJECTION_INFO
    projectionInfoType         AS BYTE
    ' Based on the connectionFlags, it should use appropriate projection info
    PROJECTION_INFO_union
END TYPE

%MPRAPI_RAS_CONNECTION_OBJECT_REVISION_1 = &H1

TYPE RAS_CONNECTION_EX
    HEADER                   AS MPRAPI_OBJECT_HEADER
    dwConnectDuration        AS DWORD
    dwInterfaceType          AS ROUTER_INTERFACE_TYPE_enum
    dwConnectionFlags        AS DWORD
    wszInterfaceName         AS WSTRINGZ * %MAX_INTERFACE_NAME_LEN + 1
    wszUserName              AS WSTRINGZ * %UNLEN + 1
    wszLogonDomain           AS WSTRINGZ * %DNLEN + 1
    wszRemoteComputer        AS WSTRINGZ * %NETBIOS_NAME_LEN + 1
    guidX                    AS GUID
    rasQuarState             AS RAS_QUARANTINE_STATE_enum
    probationTime            AS FILETIME

    ' Statistics:
    dwBytesXmited            AS DWORD
    dwBytesRcved             AS DWORD
    dwFramesXmited           AS DWORD
    dwFramesRcved            AS DWORD
    dwCrcErr                 AS DWORD
    dwTimeoutErr             AS DWORD
    dwAlignmentErr           AS DWORD
    dwHardwareOverrunErr     AS DWORD
    dwFramingErr             AS DWORD
    dwBufferOverrunErr       AS DWORD
    dwCompressionRatioIn     AS DWORD
    dwCompressionRatioOut    AS DWORD

    ' Currently valid only for IKEV2:
    dwNumSwitchOvers         AS DWORD

    ' Endpoint Information:
    wszRemoteEndpointAddress AS WSTRINGZ * %MAXIPADRESSLEN+1
    wszLocalEndpointAddress  AS WSTRINGZ * %MAXIPADRESSLEN+1


    'Projection result:
    ProjectionInfo           AS PROJECTION_INFO

    hConnection              AS DWORD   ' HANDLE
    hInterface               AS DWORD   ' HANDLE
END TYPE

'----------- MPR_SERVER_EX object

TYPE IKEV2_TUNNEL_CONFIG_PARAMS
    dwIdleTimeout                AS DWORD
    dwNetworkBlackoutTime        AS DWORD
    dwSaLifeTime                 AS DWORD
    dwSaDataSizeForRenegotiation AS DWORD
    dwConfigOptions              AS DWORD
    dwTotalCertificates          AS DWORD
    certificateNames             AS CERT_NAME_BLOB PTR
END TYPE

%MPRAPI_IKEV2_SET_TUNNEL_CONFIG_PARAMS = &H1

TYPE IKEV2_CONFIG_PARAMS
    dwNumPorts                   AS DWORD
    dwPortFlags                  AS DWORD
    dwTunnelConfigParamFlags     AS DWORD
    TunnelConfigParams           AS IKEV2_TUNNEL_CONFIG_PARAMS
END TYPE


TYPE PPTP_CONFIG_PARAMS
    dwNumPorts                   AS DWORD
    dwPortFlags                  AS DWORD
END TYPE

TYPE L2TP_CONFIG_PARAMS
    dwNumPorts                   AS DWORD
    dwPortFlags                  AS DWORD
END TYPE

%MAX_SSTP_HASH_SIZE = 32 ' SHA-256 Certificate hash size

TYPE SSTP_CERT_INFO
    ' Whether it is the default node [no cert config]
    isDefault                    AS LONG   ' BOOL
    certBlob                     AS CRYPT_HASH_BLOB
END TYPE

TYPE SSTP_CONFIG_PARAMS
    dwNumPorts                   AS DWORD
    dwPortFlags                  AS DWORD
    isUseHttps                   AS LONG   ' BOOL
    certAlgorithm                AS DWORD                        ' Should always be CALG_SHA_256
    sstpCertDetails              AS SSTP_CERT_INFO
END TYPE

TYPE MPRAPI_TUNNEL_CONFIG_PARAMS
    IkeConfigParams              AS IKEV2_CONFIG_PARAMS
    PptpConfigParams             AS PPTP_CONFIG_PARAMS
    L2tpConfigParams             AS L2TP_CONFIG_PARAMS
    SstpConfigParams             AS SSTP_CONFIG_PARAMS
END TYPE

%MPRAPI_MPR_SERVER_OBJECT_REVISION_1 = &H1

TYPE MPR_SERVER_EX
    HEADER                       AS MPRAPI_OBJECT_HEADER
    fLanOnlyMode                 AS DWORD
    dwUpTime                     AS DWORD
    dwTotalPorts                 AS DWORD
    dwPortsInUse                 AS DWORD
    Reserved                     AS DWORD                        ' Added so that the structure is 8 byte aligned
    ConfigParams                 AS MPRAPI_TUNNEL_CONFIG_PARAMS
END TYPE

%MPRAPI_MPR_SERVER_SET_CONFIG_OBJECT_REVISION_1 = &H1

%MPRAPI_SET_CONFIG_PROTOCOL_FOR_PPTP  = &H1
%MPRAPI_SET_CONFIG_PROTOCOL_FOR_L2TP  = &H2
%MPRAPI_SET_CONFIG_PROTOCOL_FOR_SSTP  = &H4
%MPRAPI_SET_CONFIG_PROTOCOL_FOR_IKEV2 = &H8


TYPE MPR_SERVER_SET_CONFIG_EX
    HEADER                       AS MPRAPI_OBJECT_HEADER
    setConfigForProtocols        AS DWORD
    ConfigParams                 AS MPRAPI_TUNNEL_CONFIG_PARAMS
END TYPE

%ALLOW_NO_AUTH        = 1
%DO_NOT_ALLOW_NO_AUTH = 0

TYPE AUTH_VALIDATION_EX
    HEADER                       AS MPRAPI_OBJECT_HEADER
    hRasConnection               AS DWORD   ' HANDLE
    wszUserName                  AS WSTRINGZ * %UNLEN + 1
    wszLogonDomain               AS WSTRINGZ * %DNLEN + 1
    AuthInfoSize                 AS DWORD
    AuthInfo(0)                  AS BYTE
END TYPE

%MPRAPI_RAS_UPDATE_CONNECTION_OBJECT_REVISION_1 = &H1

TYPE RAS_UPDATE_CONNECTION
    HEADER                       AS MPRAPI_OBJECT_HEADER
    dwIfIndex                    AS DWORD
    wszLocalEndpointAddress      AS WSTRINGZ * %MAXIPADRESSLEN+1
    wszRemoteEndpointAddress     AS WSTRINGZ * %MAXIPADRESSLEN+1
END TYPE

' RAS Admin Functions:
DECLARE FUNCTION MprAdminConnectionEnumEx LIB "MprApi.dll" _
    ALIAS "MprAdminConnectionEnumEx" ( _
    BYVAL hRasServer       AS RAS_SERVER_HANDLE, _
    pObjectHeader          AS MPRAPI_OBJECT_HEADER, _
    BYVAL dwPreferedMaxLen AS DWORD, _
    lpdwEntriesRead        AS DWORD, _
    lpdwTotalEntries       AS DWORD, _
    ppRasConn              AS ANY, _   'RAS_CONNECTION_EX PTR PTR,
    lpdwResumeHandle       AS DWORD) _
    AS DWORD


DECLARE FUNCTION MprAdminConnectionGetInfoEx LIB "MprApi.dll" _
    ALIAS "MprAdminConnectionGetInfoEx" ( _
    BYVAL hRasServer     AS RAS_SERVER_HANDLE, _
    BYVAL hRasConnection AS DWORD, _   ' HANDLE
    pRasConnection       AS RAS_CONNECTION_EX) _
    _ ' Use MprAdminBufferFree for freeing pRASCONN
    AS DWORD

' Router Admin Functions:
DECLARE FUNCTION MprAdminServerGetInfoEx LIB "MprApi.dll" _
    ALIAS "MprAdminServerGetInfoEx" ( _
    BYVAL hMprServer AS MPR_SERVER_HANDLE, _
    pServerInfo      AS MPR_SERVER_EX) _
    AS DWORD


DECLARE FUNCTION MprAdminServerSetInfoEx LIB "MprApi.dll" _
    ALIAS "MprAdminServerSetInfoEx" ( _
    BYVAL hMprServer AS MPR_SERVER_HANDLE, _
    pServerInfo      AS MPR_SERVER_SET_CONFIG_EX) _
    AS DWORD


' Router Config Functions:

DECLARE FUNCTION MprConfigServerGetInfoEx LIB "MprApi.dll" _
    ALIAS "MprConfigServerGetInfoEx" ( _
    BYVAL hMprConfig AS DWORD, _   ' HANDLE
    pServerInfo      AS MPR_SERVER_EX) _
    AS DWORD


DECLARE FUNCTION MprConfigServerSetInfoEx LIB "MprApi.dll" _
    ALIAS "MprConfigServerSetInfoEx" ( _
    BYVAL hMprConfig AS DWORD, _   ' HANDLE
    pSetServerConfig AS MPR_SERVER_SET_CONFIG_EX) _
    AS DWORD

DECLARE FUNCTION MprAdminUpdateConnection LIB "MprApi.dll" _
    ALIAS "MprAdminUpdateConnection" ( _
    BYVAL hRasServer     AS RAS_SERVER_HANDLE, _
    BYVAL hRasConnection AS DWORD, _   ' HANDLE
    pRasUpdateConnection AS RAS_UPDATE_CONNECTION) _
    AS DWORD

' Admin DLLs:
%MPRAPI_ADMIN_DLL_VERSION_1 = &H1
%MPRAPI_ADMIN_DLL_VERSION_2 = &H2 ' If the version is 2: it can use RAS_CONNECTION_EX supported in Windows 7.0

DECLARE FUNCTION PMPRADMINGETIPADDRESSFORUSER (WSTRINGZ, WSTRINGZ, BYREF DWORD, BYREF LONG) AS DWORD

DECLARE SUB PMPRADMINRELEASEIPADRESS (WSTRINGZ, WSTRINGZ, BYREF DWORD)

DECLARE FUNCTION PMPRADMINGETIPV6ADDRESSFORUSER (WSTRINGZ, WSTRINGZ, BYREF IN6_ADDR, BYREF LONG) AS DWORD

DECLARE SUB PMPRADMINRELEASEIPV6ADDRESSFORUSER (WSTRINGZ, WSTRINGZ, BYREF IN6_ADDR)

DECLARE FUNCTION PMPRADMINACCEPTNEWCONNECTION (BYREF RAS_CONNECTION_0, BYREF RAS_CONNECTION_1) AS LONG   ' BOOL

DECLARE FUNCTION PMPRADMINACCEPTNEWCONNECTION2 (BYREF RAS_CONNECTION_0, BYREF RAS_CONNECTION_1, BYREF RAS_CONNECTION_2) AS LONG   ' BOOL

DECLARE FUNCTION PMPRADMINACCEPTNEWCONNECTION3 (BYREF RAS_CONNECTION_0, BYREF RAS_CONNECTION_1, BYREF RAS_CONNECTION_2, BYREF RAS_CONNECTION_3) AS LONG   ' BOOL

DECLARE FUNCTION PMPRADMINACCEPTNEWLINK (BYREF RAS_PORT_0, BYREF RAS_PORT_1) AS LONG   ' BOOL

DECLARE SUB PMPRADMINCONNECTIONHANGUPNOTIFICATION (BYREF RAS_CONNECTION_0, BYREF RAS_CONNECTION_1)

DECLARE SUB PMPRADMINCONNECTIONHANGUPNOTIFICATION2 (BYREF RAS_CONNECTION_0, BYREF RAS_CONNECTION_1, BYREF RAS_CONNECTION_2)

DECLARE SUB PMPRADMINCONNECTIONHANGUPNOTIFICATION3 (BYREF RAS_CONNECTION_0, BYREF RAS_CONNECTION_1, BYREF RAS_CONNECTION_2, BYVAL RAS_CONNECTION_3)

DECLARE SUB PMPRADMINLINKHANGUPNOTIFICATION (BYREF RAS_PORT_0, BYREF RAS_PORT_1)

DECLARE FUNCTION PMPRADMINTERMINATEDLL () AS DWORD

DECLARE FUNCTION PMPRADMINACCEPTREAUTHENTICATION (BYREF RAS_CONNECTION_0, BYREF RAS_CONNECTION_1, BYREF RAS_CONNECTION_2, BYREF RAS_CONNECTION_3) AS LONG   ' BOOL


DECLARE FUNCTION PMPRADMINACCEPTNEWCONNECTIONEX (BYREF RAS_CONNECTION_EX) AS LONG   ' BOOL

DECLARE FUNCTION PMPRADMINACCEPTREAUTHENTICATIONEX (BYREF RAS_CONNECTION_EX) AS LONG   ' BOOL

DECLARE FUNCTION PMPRADMINACCEPTTUNNELENDPOINTCHANGEEX (BYREF RAS_CONNECTION_EX) AS LONG   ' BOOL

DECLARE SUB PMPRADMINCONNECTIONHANGUPNOTIFICATIONEX (BYREF RAS_CONNECTION_EX)

DECLARE FUNCTION PMPRADMINRASVALIDATEPREAUTHENTICATEDCONNECTIONEX (BYREF AUTH_VALIDATION_EX) AS DWORD


TYPE MPRAPI_ADMIN_DLL_CALLBACKS
    revision                                    AS BYTE
    lpfnMprAdminGetIpAddressForUser             AS DWORD  ' PMPRADMINGETIPADDRESSFORUSER
    lpfnMprAdminReleaseIpAddress                AS DWORD  ' PMPRADMINRELEASEIPADRESS
    lpfnMprAdminGetIpv6AddressForUser           AS DWORD  ' PMPRADMINGETIPV6ADDRESSFORUSER
    lpfnMprAdminReleaseIpV6AddressForUser       AS DWORD  ' PMPRADMINRELEASEIPV6ADDRESSFORUSER
    lpfnRasAdminAcceptNewLink                   AS DWORD  ' PMPRADMINACCEPTNEWLINK
    lpfnRasAdminLinkHangupNotification          AS DWORD  ' PMPRADMINLINKHANGUPNOTIFICATION
    lpfnRasAdminTerminateDll                    AS DWORD  ' PMPRADMINTERMINATEDLL
    lpfnRasAdminAcceptNewConnectionEx           AS DWORD  ' PMPRADMINACCEPTNEWCONNECTIONEX
    lpfnRasAdminAcceptEndpointChangeEx          AS DWORD  ' PMPRADMINACCEPTTUNNELENDPOINTCHANGEEX
    lpfnRasAdminAcceptReauthenticationEx        AS DWORD  ' PMPRADMINACCEPTREAUTHENTICATIONEX
    lpfnRasAdminConnectionHangupNotificationEx  AS DWORD  ' PMPRADMINCONNECTIONHANGUPNOTIFICATIONEX
    lpfnRASValidatePreAuthenticatedConnectionEx AS DWORD  ' PMPRADMINRASVALIDATEPREAUTHENTICATEDCONNECTIONEX
END TYPE

DECLARE FUNCTION MprAdminAcceptNewConnectionEx ( _
    pRasConn AS RAS_CONNECTION_EX _
    ) AS LONG   ' BOOL

DECLARE FUNCTION MprAdminAcceptReauthenticationEx ( _
    pRasConn AS RAS_CONNECTION_EX _
    ) AS LONG   ' BOOL

DECLARE SUB MprAdminConnectionHangupNotificationEx ( _
    pRasConn AS RAS_CONNECTION_EX _
    )

DECLARE FUNCTION MprAdminInitializeDllEx ( _
    pAdminCallbacks AS MPRAPI_ADMIN_DLL_CALLBACKS _
    ) AS DWORD

DECLARE FUNCTION MprAdminIsServiceInitialized ( _
    lpwsServerName        AS WSTRINGZ, _
    fIsServiceInitialized AS LONG _   ' BOOL
    ) AS DWORD

#ENDIF ' %WINVER >= &H0601

'
'  RAS ADMIN APIs
'

DECLARE FUNCTION MprAdminConnectionEnum LIB "MprApi.dll" _
    ALIAS "MprAdminConnectionEnum" ( _
    BYVAL hRasServer       AS RAS_SERVER_HANDLE, _
    BYVAL dwLevel          AS DWORD, _
    lplpbBuffer            AS ANY, _    ' BYTE PTR PTR
    BYVAL dwPrefMaxLen     AS DWORD, _
    lpdwEntriesRead        AS DWORD, _
    lpdwTotalEntries       AS DWORD, _
    lpdwResumeHandle       AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprAdminPortEnum LIB "MprApi.dll" _
    ALIAS "MprAdminPortEnum" ( _
    BYVAL hRasServer     AS RAS_SERVER_HANDLE, _
    BYVAL dwLevel        AS DWORD, _
    BYVAL hRasConnection AS DWORD, _    ' HANDLE
    lplpbBuffer          AS ANY, _      ' BYTE PTR PTR
    BYVAL dwPrefMaxLen   AS DWORD, _
    lpdwEntriesRead      AS DWORD, _
    lpdwTotalEntries     AS DWORD, _
    lpdwResumeHandle     AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprAdminConnectionGetInfo LIB "MprApi.dll" _
    ALIAS "MprAdminConnectionGetInfo" ( _
    BYVAL hRasServer     AS RAS_SERVER_HANDLE, _
    BYVAL dwLevel        AS DWORD, _
    BYVAL hRasConnection AS DWORD, _    ' HANDLE
    lplpbBuffer          AS ANY _       ' BYTE PTR PTR
    ) AS DWORD

DECLARE FUNCTION MprAdminPortGetInfo LIB "MprApi.dll" _
    ALIAS "MprAdminPortGetInfo" ( _
    BYVAL hRasServer AS RAS_SERVER_HANDLE, _
    BYVAL dwLevel    AS DWORD, _
    BYVAL hPort      AS DWORD, _        ' HANDLE
    lplpbBuffer      AS ANY _           ' BYTE PTR PTR
    ) AS DWORD

DECLARE FUNCTION MprAdminConnectionClearStats LIB "MprApi.dll" _
    ALIAS "MprAdminConnectionClearStats" ( _
    BYVAL hRasServer     AS RAS_SERVER_HANDLE, _
    BYVAL hRasConnection AS DWORD _     ' HANDLE
    ) AS DWORD

DECLARE FUNCTION MprAdminPortClearStats LIB "MprApi.dll" _
    ALIAS "MprAdminPortClearStats" ( _
    BYVAL hRasServer AS RAS_SERVER_HANDLE, _
    BYVAL hPort      AS DWORD _         ' HANDLE
    ) AS DWORD

DECLARE FUNCTION MprAdminPortReset LIB "MprApi.dll" _
    ALIAS "MprAdminPortReset" ( _
    BYVAL hRasServer AS RAS_SERVER_HANDLE, _
    BYVAL hPort      AS DWORD _         ' HANDLE
    ) AS DWORD

DECLARE FUNCTION MprAdminPortDisconnect LIB "MprApi.dll" _
    ALIAS "MprAdminPortDisconnect" ( _
    BYVAL hRasServer AS RAS_SERVER_HANDLE, _
    BYVAL hPort      AS DWORD _         ' HANDLE
    ) AS DWORD

DECLARE FUNCTION MprAdminAcceptNewConnection LIB "MprApi.dll" _
    ALIAS "MprAdminAcceptNewConnection" ( _
    pRasConnection0 AS RAS_CONNECTION_0, _
    pRasConnection1 AS RAS_CONNECTION_1 _
    ) AS LONG   ' BOOL

#IF (%WINVER >= &H0500)

DECLARE FUNCTION MprAdminAcceptNewConnection2 LIB "MprApi.dll" _
    ALIAS "MprAdminAcceptNewConnection2" ( _
    pRasConnection0 AS RAS_CONNECTION_0, _
    pRasConnection1 AS RAS_CONNECTION_1, _
    pRasConnection2 AS RAS_CONNECTION_2 _
    ) AS LONG   ' BOOL

#ENDIF ' %WINVER >= &H0500

#IF (%WINVER >= &H0600)

DECLARE FUNCTION MprAdminAcceptNewConnection3 LIB "MprApi.dll" _
    ALIAS "MprAdminAcceptNewConnection3" ( _
    pRasConnection0 AS RAS_CONNECTION_0, _
    pRasConnection1 AS RAS_CONNECTION_1, _
    pRasConnection2 AS RAS_CONNECTION_2, _
    pRasConnection3 AS RAS_CONNECTION_3 _
    ) AS LONG   ' BOOL

DECLARE FUNCTION MprAdminAcceptReauthentication LIB "MprApi.dll" _
    ALIAS "MprAdminAcceptReauthentication" ( _
    pRasConnection0 AS RAS_CONNECTION_0, _
    pRasConnection1 AS RAS_CONNECTION_1, _
    pRasConnection2 AS RAS_CONNECTION_2, _
    pRasConnection3 AS RAS_CONNECTION_3 _
    ) AS LONG   ' BOOL

#ENDIF ' %WINVER >= &H0600

DECLARE FUNCTION MprAdminAcceptNewLink LIB "MprApi.dll" _
    ALIAS "MprAdminAcceptNewLink" ( _
    pRasPort0 AS RAS_PORT_0, _
    pRasPort1 AS RAS_PORT_1 _
    ) AS LONG   ' BOOL

DECLARE SUB MprAdminConnectionHangupNotification LIB "MprApi.dll" _
    ALIAS "MprAdminConnectionHangupNotification" ( _
    pRasConnection0 AS RAS_CONNECTION_0, _
    pRasConnection1 AS RAS_CONNECTION_1 _
    )

#IF (%WINVER >= &H0500)

DECLARE SUB MprAdminConnectionHangupNotification2 LIB "MprApi.dll" _
    ALIAS "MprAdminConnectionHangupNotification2" ( _
    pRasConnection0 AS RAS_CONNECTION_0, _
    pRasConnection1 AS RAS_CONNECTION_1, _
    pRasConnection2 AS RAS_CONNECTION_2 _
    )

#ENDIF ' %WINVER >= &H0500

#IF (%WINVER >= &H0600)

DECLARE SUB MprAdminConnectionHangupNotification3 LIB "MprApi.dll" _
    ALIAS "MprAdminConnectionHangupNotification3" ( _
    pRasConnection0 AS RAS_CONNECTION_0, _
    pRasConnection1 AS RAS_CONNECTION_1, _
    pRasConnection2 AS RAS_CONNECTION_2, _
    pRasConnection3 AS RAS_CONNECTION_3 _
    )

#ENDIF ' %WINVER >= &H0600

#IF (%WINVER >= &H501)

DECLARE FUNCTION MprAdminConnectionRemoveQuarantine LIB "MprApi.dll" _
    ALIAS "MprAdminConnectionRemoveQuarantine" ( _
    BYVAL hRasServer     AS DWORD, _    ' HANDLE
    BYVAL hRasConnection AS DWORD, _    ' HANDLE
    BYVAL fIsIpAddress   AS LONG _      ' BOOL
    ) AS DWORD

#ENDIF

DECLARE SUB MprAdminLinkHangupNotification LIB "MprApi.dll" _
    ALIAS "MprAdminLinkHangupNotification" ( _
    pRasPort0 AS RAS_PORT_0, _
    pRasPort1 AS RAS_PORT_1 _
    )

DECLARE FUNCTION MprAdminGetIpAddressForUser LIB "MprApi.dll" _
    ALIAS "MprAdminGetIpAddressForUser" ( _
    lpwszUserName  AS WSTRINGZ, _
    lpwszPortName  AS WSTRINGZ, _
    lpdwIpAddress  AS DWORD, _
    bNotifyRelease AS LONG _        ' BOOL
    ) AS DWORD



DECLARE SUB MprAdminReleaseIpAddress LIB "MprApi.dll" _
    ALIAS "MprAdminReleaseIpAddress" ( _
    lpszUserName  AS WSTRINGZ, _
    lpszPortName  AS WSTRINGZ, _
    lpdwIpAddress AS DWORD _
    )


#IF (%WINVER >= &H0600)

DECLARE SUB MprAdminGetIpv6AddressForUser LIB "MprApi.dll" _
    ALIAS "MprAdminGetIpv6AddressForUser" ( _
    lpwszUserName   AS WSTRINGZ, _
    lpwszPortName   AS WSTRINGZ, _
    lpdwIpv6Address AS IN6_ADDR, _   ' Currently Only 64 Bit Identifier is supported
    bNotifyRelease  AS LONG _        ' BOOL
    )

DECLARE SUB MprAdminReleaseIpv6AddressForUser LIB "MprApi.dll" _
    ALIAS "MprAdminReleaseIpv6AddressForUser" ( _
    lpszUserName    AS WSTRINGZ, _
    lpszPortName    AS WSTRINGZ, _
    lpdwIpv6Address AS IN6_ADDR _
    )

#ENDIF ' %WINVER >= &H0600

#IF (%WINVER >= &H0500)

DECLARE FUNCTION MprAdminInitializeDll LIB "MprApi.dll" _
    ALIAS "MprAdminInitializeDll" () AS DWORD

DECLARE FUNCTION MprAdminTerminateDll LIB "MprApi.dll" _
    ALIAS "MprAdminTerminateDll" () AS DWORD

#ENDIF

'
' MprAdminUser APIs
'

DECLARE FUNCTION MprAdminUserGetInfo LIB "MprApi.dll" _
    ALIAS "MprAdminUserGetInfo" ( _
    lpszServer      AS WSTRINGZ, _
    lpszUser        AS WSTRINGZ, _
    BYVAL dwLevel   AS DWORD, _
    BYVAL lpbBuffer AS BYTE PTR _
    ) AS DWORD


DECLARE FUNCTION MprAdminUserSetInfo LIB "MprApi.dll" _
    ALIAS "MprAdminUserSetInfo" ( _
    lpszServer      AS WSTRINGZ, _
    lpszUser        AS WSTRINGZ, _
    BYVAL dwLevel   AS DWORD, _
    BYVAL lpbBuffer AS BYTE PTR _
    ) AS DWORD


#IF (%WINVER >= &H0500)

DECLARE FUNCTION MprAdminSendUserMessage LIB "MprApi.dll" _
    ALIAS "MprAdminSendUserMessage" ( _
    BYVAL hMprServer  AS MPR_SERVER_HANDLE, _
    BYVAL hConnection AS DWORD, _    ' HANDLE
    lpwszMessage      AS WSTRINGZ _
    ) AS DWORD

#ENDIF ' %WINVER >= &H0500

DECLARE FUNCTION MprAdminGetPDCServer LIB "MprApi.dll" _
    ALIAS "MprAdminGetPDCServer" ( _
    lpszDomain    AS WSTRINGZ, _
    lpszServer    AS WSTRINGZ, _
    lpszPDCServer AS WSTRINGZ _
    ) AS DWORD

'
' Router APIs
'

DECLARE FUNCTION MprAdminIsServiceRunning LIB "MprApi.dll" _
    ALIAS "MprAdminIsServiceRunning" ( _
    lpwsServerName AS WSTRINGZ _
    ) AS LONG   ' BOOL

DECLARE FUNCTION MprAdminServerConnect LIB "MprApi.dll" _
    ALIAS "MprAdminServerConnect" ( _
    lpwsServerName AS WSTRINGZ, _
    phMprServer    AS MPR_SERVER_HANDLE _
    ) AS DWORD

DECLARE FUNCTION MprAdminServerDisconnect LIB "MprApi.dll" _
    ALIAS "MprAdminServerDisconnect" ( _
    BYVAL hMprServer AS MPR_SERVER_HANDLE _
    ) AS LONG

#IF (%WINVER >= &H501)
DECLARE FUNCTION MprAdminServerGetCredentials LIB "MprApi.dll" _
    ALIAS "MprAdminServerGetCredentials" ( _
    BYVAL hMprServer  AS MPR_SERVER_HANDLE, _
    BYVAL dwLevel     AS DWORD, _
    lplpbBuffer       AS ANY _      ' BYTE PTR PTR
    ) AS DWORD

DECLARE FUNCTION MprAdminServerSetCredentials LIB "MprApi.dll" _
    ALIAS "MprAdminServerSetCredentials" ( _
    BYVAL hMprServer AS MPR_SERVER_HANDLE, _
    BYVAL dwLevel    AS DWORD, _
    BYVAL lpbBuffer  AS BYTE PTR _
    ) AS DWORD

#ENDIF

DECLARE FUNCTION MprAdminBufferFree LIB "MprApi.dll" _
    ALIAS "MprAdminBufferFree" ( _
    BYVAL pBuffer AS DWORD _           ' LPVOID
    ) AS DWORD

DECLARE FUNCTION MprAdminGetErrorString LIB "MprApi.dll" _
    ALIAS "MprAdminGetErrorString" ( _
    BYVAL dwError     AS DWORD, _
    lplpwsErrorString AS ANY _         ' LPWSTR PTR
    ) AS DWORD

DECLARE FUNCTION MprAdminServerGetInfo LIB "MprApi.dll" _
    ALIAS "MprAdminServerGetInfo" ( _
    BYVAL hMprServer AS MPR_SERVER_HANDLE, _
    BYVAL dwLevel    AS DWORD, _
    lplpbBuffer      AS ANY _          ' BYTE PTR PTR
    ) AS DWORD

#IF (%WINVER >= &H501)

DECLARE FUNCTION MprAdminServerSetInfo LIB "MprApi.dll" _
    ALIAS "MprAdminServerSetInfo" ( _
    BYVAL hMprServer AS MPR_SERVER_HANDLE, _
    BYVAL dwLevel    AS DWORD, _
    BYVAL lpbBuffer  AS BYTE PTR _
    ) AS DWORD


DECLARE FUNCTION MprAdminEstablishDomainRasServer LIB "MprApi.dll" _
    ALIAS "MprAdminEstablishDomainRasServer" ( _
    pszDomain     AS WSTRINGZ, _
    pszMachine    AS WSTRINGZ, _
    BYVAL bEnable AS LONG _         ' BOOL
    ) AS DWORD

DECLARE FUNCTION MprAdminIsDomainRasServer LIB "MprApi.dll" _
    ALIAS "MprAdminIsDomainRasServer" ( _
    pszDomain     AS WSTRINGZ, _
    pszMachine    AS WSTRINGZ, _
    pbIsRasServer AS LONG _         ' BOOL
    ) AS DWORD

#ENDIF

#IF (%WINVER >= &H0500)

DECLARE FUNCTION MprAdminTransportCreate LIB "MprApi.dll" _
    ALIAS "MprAdminTransportCreate" ( _
    BYVAL hMprServer                AS MPR_SERVER_HANDLE, _
    BYVAL dwTransportId             AS DWORD, _
    lpwsTransportName               AS WSTRINGZ, _
    BYVAL pGlobalInfo               AS BYTE PTR, _
    BYVAL dwGlobalInfoSize          AS DWORD, _
    BYVAL pClientInterfaceInfo      AS BYTE PTR, _
    BYVAL dwClientInterfaceInfoSize AS DWORD, _
    lpwsDLLPath                     AS WSTRINGZ _
    ) AS DWORD

#ENDIF ' %WINVER >= &H0500 */

DECLARE FUNCTION MprAdminTransportSetInfo LIB "MprApi.dll" _
    ALIAS "MprAdminTransportSetInfo" ( _
    BYVAL hMprServer                AS MPR_SERVER_HANDLE, _
    BYVAL dwTransportId             AS DWORD, _
    BYVAL pGlobalInfo               AS BYTE PTR, _
    BYVAL dwGlobalInfoSize          AS DWORD, _
    BYVAL pClientInterfaceInfo      AS BYTE PTR, _
    BYVAL dwClientInterfaceInfoSize AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprAdminTransportGetInfo LIB "MprApi.dll" _
    ALIAS "MprAdminTransportGetInfo" ( _
    BYVAL hMprServer            AS MPR_SERVER_HANDLE, _
    BYVAL dwTransportId         AS DWORD, _
    ppGlobalInfo                AS ANY, _      ' BYTE PTR PTR
    lpdwGlobalInfoSize          AS DWORD, _
    ppClientInterfaceInfo       AS ANY, _      ' BYTE PTR PTR
    lpdwClientInterfaceInfoSize AS DWORD _
    ) AS DWORD

#IF (%WINVER >= &H0500)

DECLARE FUNCTION MprAdminDeviceEnum LIB "MprApi.dll" _
    ALIAS "MprAdminDeviceEnum" ( _
    BYVAL hMprServer AS MPR_SERVER_HANDLE, _
    BYVAL dwLevel    AS DWORD, _
    lplpbBuffer      AS ANY, _     ' BYTE PTR PTR
    lpdwTotalEntries AS DWORD _
    ) AS DWORD

#ENDIF ' %WINVER >= &H0500

DECLARE FUNCTION MprAdminInterfaceGetHandle LIB "MprApi.dll" _
    ALIAS "MprAdminInterfaceGetHandle" ( _
    BYVAL hMprServer               AS MPR_SERVER_HANDLE, _
    lpwsInterfaceName              AS WSTRINGZ, _
    phInterface                    AS DWORD, _    ' HANDLE
    BYVAL fIncludeClientInterfaces AS LONG _      ' BOOL
    ) AS DWORD

DECLARE FUNCTION MprAdminInterfaceCreate LIB "MprApi.dll" _
    ALIAS "MprAdminInterfaceCreate" ( _
    BYVAL hMprServer AS MPR_SERVER_HANDLE, _
    BYVAL dwLevel    AS DWORD, _
    BYVAL lpbBuffer  AS BYTE PTR, _
    phInterface      AS DWORD _         ' HANDLE
    ) AS DWORD

DECLARE FUNCTION MprAdminInterfaceGetInfo LIB "MprApi.dll" _
    ALIAS "MprAdminInterfaceGetInfo" ( _
    BYVAL hMprServer AS MPR_SERVER_HANDLE, _
    BYVAL hInterface AS DWORD, _        ' HANDLE
    BYVAL dwLevel    AS DWORD, _
    lplpbBuffer      AS ANY _           ' BYTE PTR PTR
    ) AS DWORD

DECLARE FUNCTION MprAdminInterfaceSetInfo LIB "MprApi.dll" _
    ALIAS "MprAdminInterfaceSetInfo" ( _
    BYVAL hMprServer AS MPR_SERVER_HANDLE, _
    BYVAL hInterface AS DWORD, _        ' HANDLE
    BYVAL dwLevel    AS DWORD, _
    BYVAL lpbBuffer  AS BYTE PTR _
    ) AS DWORD

DECLARE FUNCTION MprAdminInterfaceDelete LIB "MprApi.dll" _
    ALIAS "MprAdminInterfaceDelete" ( _
    BYVAL hMprServer AS MPR_SERVER_HANDLE, _
    BYVAL hInterface AS DWORD _         ' HANDLE
    ) AS DWORD

#IF (%WINVER >= &H0500)

DECLARE FUNCTION MprAdminInterfaceDeviceGetInfo LIB "MprApi.dll" _
    ALIAS "MprAdminInterfaceDeviceGetInfo" ( _
    BYVAL hMprServer AS MPR_SERVER_HANDLE, _
    BYVAL hInterface AS DWORD, _        ' HANDLE
    BYVAL dwIndex    AS DWORD, _
    BYVAL dwLevel    AS DWORD, _
    lplpBuffer       AS ANY _           ' BYTE PTR PTR
    ) AS DWORD

DECLARE FUNCTION MprAdminInterfaceDeviceSetInfo LIB "MprApi.dll" _
    ALIAS "MprAdminInterfaceDeviceSetInfo" ( _
    BYVAL hMprServer AS MPR_SERVER_HANDLE, _
    BYVAL hInterface AS DWORD, _        ' HANDLE
    BYVAL dwIndex    AS DWORD, _
    BYVAL dwLevel    AS DWORD, _
    BYVAL lpbBuffer  AS BYTE PTR _
    ) AS DWORD

#ENDIF ' %WINVER >= &H0500

DECLARE FUNCTION MprAdminInterfaceTransportRemove LIB "MprApi.dll" _
    ALIAS "MprAdminInterfaceTransportRemove" ( _
    BYVAL hMprServer    AS MPR_SERVER_HANDLE, _
    BYVAL hInterface    AS DWORD, _        ' HANDLE
    BYVAL dwTransportId AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprAdminInterfaceTransportAdd LIB "MprApi.dll" _
    ALIAS "MprAdminInterfaceTransportAdd" ( _
    BYVAL hMprServer          AS MPR_SERVER_HANDLE, _
    BYVAL hInterface          AS DWORD, _    ' HANDLE
    BYVAL dwTransportId       AS DWORD, _
    BYVAL pInterfaceInfo      AS BYTE PTR, _
    BYVAL dwInterfaceInfoSize AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprAdminInterfaceTransportGetInfo LIB "MprApi.dll" _
    ALIAS "MprAdminInterfaceTransportGetInfo" ( _
    BYVAL hMprServer      AS MPR_SERVER_HANDLE, _
    BYVAL hInterface      AS DWORD, _         ' HANDLE
    BYVAL dwTransportId   AS DWORD, _
    ppInterfaceInfo       AS ANY, _           ' BYTE PTR PTR
    lpdwInterfaceInfoSize AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprAdminInterfaceTransportSetInfo LIB "MprApi.dll" _
    ALIAS "MprAdminInterfaceTransportSetInfo" ( _
    BYVAL hMprServer          AS MPR_SERVER_HANDLE, _
    BYVAL hInterface          AS DWORD, _     ' HANDLE
    BYVAL dwTransportId       AS DWORD, _
    BYVAL pInterfaceInfo      AS BYTE PTR, _
    BYVAL dwInterfaceInfoSize AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprAdminInterfaceEnum LIB "MprApi.dll" _
    ALIAS "MprAdminInterfaceEnum" ( _
    BYVAL hMprServer       AS MPR_SERVER_HANDLE, _
    BYVAL dwLevel          AS DWORD, _
    lplpbBuffer            AS ANY, _          ' BYTE PTR PTR
    BYVAL dwPrefMaxLen     AS DWORD, _
    lpdwEntriesRead        AS DWORD, _
    lpdwTotalEntries       AS DWORD, _
    lpdwResumeHandle       AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprSetupIpInIpInterfaceFriendlyNameEnum LIB "MprApi.dll" _
    ALIAS "MprSetupIpInIpInterfaceFriendlyNameEnum" ( _
    pwszMachineName AS WSTRINGZ, _
    lplpBuffer      AS ANY, _        ' BYTE PTR PTR
    lpdwEntriesRead AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprSetupIpInIpInterfaceFriendlyNameFree LIB "MprApi.dll" _
    ALIAS "MprSetupIpInIpInterfaceFriendlyNameFree" ( _
    BYVAL lpBuffer AS DWORD _        ' LPVOID
    ) AS DWORD

DECLARE FUNCTION MprSetupIpInIpInterfaceFriendlyNameCreate LIB "MprApi.dll" _
    ALIAS "MprSetupIpInIpInterfaceFriendlyNameCreate" ( _
    pwszMachineName        AS WSTRINGZ, _
    BYVAL pNameInformation AS MPR_IPINIP_INTERFACE_0 PTR _
    ) AS DWORD

DECLARE FUNCTION MprSetupIpInIpInterfaceFriendlyNameDelete LIB "MprApi.dll" _
    ALIAS "MprSetupIpInIpInterfaceFriendlyNameDelete" ( _
    pwszMachineName AS WSTRINGZ, _
    pGuid           AS GUID _
    ) AS DWORD

DECLARE FUNCTION MprAdminInterfaceSetCredentials LIB "MprApi.dll" _
    ALIAS "MprAdminInterfaceSetCredentials" ( _
    lpwsServer        AS WSTRINGZ, _
    lpwsInterfaceName AS WSTRINGZ, _
    lpwsUserName      AS WSTRINGZ, _
    lpwsDomainName    AS WSTRINGZ, _
    lpwsPassword      AS WSTRINGZ _
    ) AS DWORD

DECLARE FUNCTION MprAdminInterfaceGetCredentials LIB "MprApi.dll" _
    ALIAS "MprAdminInterfaceGetCredentials" ( _
    lpwsServer        AS WSTRINGZ, _
    lpwsInterfaceName AS WSTRINGZ, _
    lpwsUserName      AS WSTRINGZ, _
    lpwsPassword      AS WSTRINGZ, _
    lpwsDomainName    AS WSTRINGZ _
    ) AS DWORD

#IF (%WINVER >= &H0500)

DECLARE FUNCTION MprAdminInterfaceSetCredentialsEx LIB "MprApi.dll" _
    ALIAS "MprAdminInterfaceSetCredentialsEx" ( _
    BYVAL hMprServer AS MPR_SERVER_HANDLE, _
    BYVAL hInterface AS DWORD, _     ' HANDLE
    BYVAL dwLevel    AS DWORD, _
    BYVAL lpbBuffer  AS BYTE PTR _
    ) AS DWORD

DECLARE FUNCTION MprAdminInterfaceGetCredentialsEx LIB "MprApi.dll" _
    ALIAS "MprAdminInterfaceGetCredentialsEx" ( _
    BYVAL hMprServer AS MPR_SERVER_HANDLE, _
    BYVAL hInterface AS DWORD, _     ' HANDLE
    BYVAL dwLevel    AS DWORD, _
    lplpbBuffer      AS ANY _        ' BYTE PTR PTR
    ) AS DWORD

#ENDIF ' %WINVER >= &H0500

DECLARE FUNCTION MprAdminInterfaceConnect LIB "MprApi.dll" _
    ALIAS "MprAdminInterfaceConnect" ( _
    BYVAL hMprServer   AS MPR_SERVER_HANDLE, _
    BYVAL hInterface   AS DWORD, _   ' HANDLE
    BYVAL hEvent       AS DWORD, _   ' HANDLE
    BYVAL fSynchronous AS LONG _     ' BOOL
    ) AS DWORD

DECLARE FUNCTION MprAdminInterfaceDisconnect LIB "MprApi.dll" _
    ALIAS "MprAdminInterfaceDisconnect" ( _
    BYVAL hMprServer AS MPR_SERVER_HANDLE, _
    BYVAL hInterface AS DWORD _      ' HANDLE
    ) AS DWORD

DECLARE FUNCTION MprAdminInterfaceUpdateRoutes LIB "MprApi.dll" _
    ALIAS "MprAdminInterfaceUpdateRoutes" ( _
    BYVAL hMprServer   AS MPR_SERVER_HANDLE, _
    BYVAL hInterface   AS DWORD, _   ' HANDLE
    BYVAL dwProtocolId AS DWORD, _
    BYVAL hEvent       AS DWORD _    ' HANDLE
    ) AS DWORD

DECLARE FUNCTION MprAdminInterfaceQueryUpdateResult LIB "MprApi.dll" _
    ALIAS "MprAdminInterfaceQueryUpdateResult" ( _
    BYVAL hMprServer   AS MPR_SERVER_HANDLE, _
    BYVAL hInterface   AS DWORD, _   ' HANDLE
    BYVAL dwProtocolId AS DWORD, _
    lpdwUpdateResult   AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprAdminInterfaceUpdatePhonebookInfo LIB "MprApi.dll" _
    ALIAS "MprAdminInterfaceUpdatePhonebookInfo" ( _
    BYVAL hMprServer AS MPR_SERVER_HANDLE, _
    BYVAL hInterface AS DWORD _      ' HANDLE
    ) AS DWORD

#IF (%WINVER >= &H0500)

DECLARE FUNCTION MprAdminRegisterConnectionNotification LIB "MprApi.dll" _
    ALIAS "MprAdminRegisterConnectionNotification" ( _
    BYVAL hMprServer         AS MPR_SERVER_HANDLE, _
    BYVAL hEventNotification AS DWORD _    ' HANDLE
    ) AS DWORD

DECLARE FUNCTION MprAdminDeregisterConnectionNotification LIB "MprApi.dll" _
    ALIAS "MprAdminDeregisterConnectionNotification" ( _
    BYVAL hMprServer         AS MPR_SERVER_HANDLE, _
    BYVAL hEventNotification AS DWORD _    ' HANDLE
    ) AS DWORD

#ENDIF ' %WINVER >= &H0500

'
' MIB APIs
'

DECLARE FUNCTION MprAdminMIBServerConnect LIB "MprApi.dll" _
    ALIAS "MprAdminMIBServerConnect" ( _
    lpwsServerName AS WSTRINGZ, _
    phMibServer    AS MIB_SERVER_HANDLE _
    ) AS DWORD

DECLARE FUNCTION MprAdminMIBServerDisconnect LIB "MprApi.dll" _
    ALIAS "MprAdminMIBServerDisconnect" ( _
    BYVAL hMibServer AS MIB_SERVER_HANDLE _
    ) AS DWORD

DECLARE FUNCTION MprAdminMIBEntryCreate LIB "MprApi.dll" _
    ALIAS "MprAdminMIBEntryCreate" ( _
    BYVAL hMibServer   AS MIB_SERVER_HANDLE, _
    BYVAL dwPid        AS DWORD, _
    BYVAL dwRoutingPid AS DWORD, _
    BYVAL lpEntry      AS DWORD, _    ' LPVOID
    BYVAL dwEntrySize  AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprAdminMIBEntryDelete LIB "MprApi.dll" _
    ALIAS "MprAdminMIBEntryDelete" ( _
    BYVAL hMibServer   AS MIB_SERVER_HANDLE, _
    BYVAL dwProtocolId AS DWORD, _
    BYVAL dwRoutingPid AS DWORD, _
    BYVAL lpEntry      AS DWORD, _    ' LPVOID
    BYVAL dwEntrySize  AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprAdminMIBEntrySet LIB "MprApi.dll" _
    ALIAS "MprAdminMIBEntrySet" ( _
    BYVAL hMibServer   AS MIB_SERVER_HANDLE, _
    BYVAL dwProtocolId AS DWORD, _
    BYVAL dwRoutingPid AS DWORD, _
    BYVAL lpEntry      AS DWORD, _    ' LPVOID
    BYVAL dwEntrySize  AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprAdminMIBEntryGet LIB "MprApi.dll" _
    ALIAS "MprAdminMIBEntryGet" ( _
    BYVAL hMibServer     AS MIB_SERVER_HANDLE, _
    BYVAL dwProtocolId   AS DWORD, _
    BYVAL dwRoutingPid   AS DWORD, _
    BYVAL lpInEntry      AS DWORD, _    ' LPVOID
    BYVAL dwInEntrySize  AS DWORD, _
    lplpOutEntry         AS ANY, _      ' LPVOID*
    lpOutEntrySize       AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprAdminMIBEntryGetFirst LIB "MprApi.dll" _
    ALIAS "MprAdminMIBEntryGetFirst" ( _
    BYVAL hMibServer    AS MIB_SERVER_HANDLE, _
    BYVAL dwProtocolId  AS DWORD, _
    BYVAL dwRoutingPid  AS DWORD, _
    BYVAL lpInEntry     AS DWORD, _     ' LPVOID
    BYVAL dwInEntrySize AS DWORD, _
    lplpOutEntry        AS ANY, _       ' LPVOID*
    lpOutEntrySize      AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprAdminMIBEntryGetNext LIB "MprApi.dll" _
    ALIAS "MprAdminMIBEntryGetNext" ( _
    BYVAL hMibServer    AS MIB_SERVER_HANDLE, _
    BYVAL dwProtocolId  AS DWORD, _
    BYVAL dwRoutingPid  AS DWORD, _
    BYVAL lpInEntry     AS DWORD, _    ' LPVOID
    BYVAL dwInEntrySize AS DWORD, _
    lplpOutEntry        AS ANY, _      ' LPVOID*
    lpOutEntrySize      AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprAdminMIBGetTrapInfo LIB "MprApi.dll" _
    ALIAS "MprAdminMIBGetTrapInfo" ( _
    BYVAL hMibServer    AS MIB_SERVER_HANDLE, _
    BYVAL dwProtocolId  AS DWORD, _
    BYVAL dwRoutingPid  AS DWORD, _
    BYVAL lpInData      AS DWORD, _    ' LPVOID
    BYVAL dwInDataSize  AS DWORD, _
    lplpOutData         AS ANY, _      ' LPVOID*
    lpOutDataSize       AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprAdminMIBSetTrapInfo LIB "MprApi.dll" _
    ALIAS "MprAdminMIBSetTrapInfo" ( _
    BYVAL dwProtocolId AS DWORD, _
    BYVAL dwRoutingPid AS DWORD, _
    BYVAL hEvent       AS DWORD, _    ' HANDLE
    BYVAL lpInData     AS DWORD, _    ' LPVOID
    BYVAL dwInDataSize AS DWORD, _
    lplpOutData        AS ANY, _      ' LPVOID*
    lpOutDataSize      AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprAdminMIBBufferFree LIB "MprApi.dll" _
    ALIAS "MprAdminMIBBufferFree" ( _
    BYVAL pBuffer AS DWORD _          ' LPVOID
    ) AS DWORD

'
' Configuration APIs
'

DECLARE FUNCTION MprConfigServerInstall LIB "MprApi.dll" _
    ALIAS "MprConfigServerInstall" ( _
    BYVAL dwLevel AS DWORD, _
    BYVAL pBuffer AS DWORD _          ' PVOID
    ) AS DWORD

DECLARE FUNCTION MprConfigServerConnect LIB "MprApi.dll" _
    ALIAS "MprConfigServerConnect" ( _
    lpwsServerName AS WSTRINGZ, _
    phMprConfig    AS DWORD _         ' DWORD
    ) AS DWORD

DECLARE FUNCTION MprConfigServerDisconnect LIB "MprApi.dll" _
    ALIAS "MprConfigServerDisconnect" ( _
    BYVAL hMprConfig AS DWORD _       ' HANDLE
    ) AS DWORD

DECLARE FUNCTION MprConfigServerRefresh LIB "MprApi.dll" _
    ALIAS "MprConfigServerRefresh" ( _
    BYVAL hMprConfig AS DWORD _       ' HANDLE
    ) AS DWORD

DECLARE FUNCTION MprConfigBufferFree LIB "MprApi.dll" _
    ALIAS "MprConfigBufferFree" ( _
    BYVAL pBuffer AS DWORD _          ' LPVOID
    ) AS DWORD

DECLARE FUNCTION MprConfigServerGetInfo LIB "MprApi.dll" _
    ALIAS "MprConfigServerGetInfo" ( _
    BYVAL hMprConfig AS DWORD, _      ' HANDLE
    BYVAL dwLevel    AS DWORD, _
    lplpbBuffer      AS ANY _         ' BYTE PTR PTR
    ) AS DWORD

#IF (%WINVER >= &H501)
DECLARE FUNCTION MprConfigServerSetInfo LIB "MprApi.dll" _
    ALIAS "MprConfigServerSetInfo" ( _
    BYVAL hMprServer AS MPR_SERVER_HANDLE, _
    BYVAL dwLevel    AS DWORD, _
    BYVAL lpbBuffer  AS BYTE PTR _
    ) AS DWORD
#ENDIF

DECLARE FUNCTION MprConfigServerBackup LIB "MprApi.dll" _
    ALIAS "MprConfigServerBackup" ( _
    BYVAL hMprConfig AS DWORD, _    ' HANDLE
    lpwsPath         AS WSTRINGZ _
    ) AS DWORD

DECLARE FUNCTION MprConfigServerRestore LIB "MprApi.dll" _
    ALIAS "MprConfigServerRestore" ( _
    BYVAL hMprConfig AS DWORD, _    ' HANDLE
    lpwsPath         AS WSTRINGZ _
    ) AS DWORD

DECLARE FUNCTION MprConfigTransportCreate LIB "MprApi.dll" _
    ALIAS "MprConfigTransportCreate" ( _
    BYVAL hMprConfig                AS DWORD, _      ' HANDLE
    BYVAL dwTransportId             AS DWORD, _
    lpwsTransportName               AS WSTRINGZ, _
    BYVAL pGlobalInfo               AS BYTE PTR, _
    BYVAL dwGlobalInfoSize          AS DWORD, _
    BYVAL pClientInterfaceInfo      AS BYTE PTR, _
    BYVAL dwClientInterfaceInfoSize AS DWORD, _
    lpwsDLLPath                     AS WSTRINGZ, _
    phRouterTransport               AS DWORD _       ' HANDLE
    ) AS DWORD

DECLARE FUNCTION MprConfigTransportDelete LIB "MprApi.dll" _
    ALIAS "MprConfigTransportDelete" ( _
    BYVAL hMprConfig       AS DWORD, _     ' HANDLE
    BYVAL hRouterTransport AS DWORD _      ' HANDLE
    ) AS DWORD

DECLARE FUNCTION MprConfigTransportGetHandle LIB "MprApi.dll" _
    ALIAS "MprConfigTransportGetHandle" ( _
    BYVAL hMprConfig    AS DWORD, _        ' HANDLE
    BYVAL dwTransportId AS DWORD, _
    phRouterTransport   AS DWORD _         ' HANDLE
    ) AS DWORD

DECLARE FUNCTION MprConfigTransportSetInfo LIB "MprApi.dll" _
    ALIAS "MprConfigTransportSetInfo" ( _
    BYVAL hMprConfig                AS DWORD, _      ' HANDLE
    BYVAL hRouterTransport          AS DWORD, _      ' HANDLE
    BYVAL pGlobalInfo               AS BYTE PTR, _
    BYVAL dwGlobalInfoSize          AS DWORD, _
    BYVAL pClientInterfaceInfo      AS BYTE PTR, _
    BYVAL dwClientInterfaceInfoSize AS DWORD, _
    lpwsDLLPath                     AS WSTRINGZ _
    ) AS DWORD

DECLARE FUNCTION MprConfigTransportGetInfo LIB "MprApi.dll" _
    ALIAS "MprConfigTransportGetInfo" ( _
    BYVAL hMprConfig            AS DWORD, _   ' HANDLE
    BYVAL hRouterTransport      AS DWORD, _   ' HANDLE
    ppGlobalInfo                AS ANY, _     ' BYTE PTR PTR
    lpdwGlobalInfoSize          AS DWORD, _
    ppClientInterfaceInfo       AS ANY, _     ' BYTE PTR PTR
    lpdwClientInterfaceInfoSize AS DWORD, _
    lplpwsDLLPath               AS ANY _      ' LPWSTR*
    ) AS DWORD

DECLARE FUNCTION MprConfigTransportEnum LIB "MprApi.dll" _
    ALIAS "MprConfigTransportEnum" ( _
    BYVAL hMprConfig   AS DWORD, _            ' HANDLE
    BYVAL dwLevel      AS DWORD, _
    lplpBuffer         AS ANY, _              ' BYTE PTR PTR
    BYVAL dwPrefMaxLen AS DWORD, _
    lpdwEntriesRead    AS DWORD, _
    lpdwTotalEntries   AS DWORD, _
    lpdwResumeHandle   AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprConfigInterfaceCreate LIB "MprApi.dll" _
    ALIAS "MprConfigInterfaceCreate" ( _
    BYVAL hMprConfig  AS DWORD, _             ' HANDLE
    BYVAL dwLevel     AS DWORD, _
    BYVAL lpbBuffer   AS BYTE PTR, _
    phRouterInterface AS DWORD _              ' HANDLE
    ) AS DWORD

DECLARE FUNCTION MprConfigInterfaceDelete LIB "MprApi.dll" _
    ALIAS "MprConfigInterfaceDelete" ( _
    BYVAL hMprConfig       AS DWORD, _        ' HANDLE
    BYVAL hRouterInterface AS DWORD _         ' HANDLE
    ) AS DWORD

DECLARE FUNCTION MprConfigInterfaceGetHandle LIB "MprApi.dll" _
    ALIAS "MprConfigInterfaceGetHandle" ( _
    BYVAL hMprConfig  AS DWORD, _             ' HANDLE
    lpwsInterfaceName AS WSTRINGZ, _
    phRouterInterface AS DWORD _              ' HANDLE
    ) AS DWORD

DECLARE FUNCTION MprConfigInterfaceGetInfo LIB "MprApi.dll" _
    ALIAS "MprConfigInterfaceGetInfo" ( _
    BYVAL hMprConfig       AS DWORD, _        ' HANDLE
    BYVAL hRouterInterface AS DWORD, _        ' HANDLE
    BYVAL dwLevel          AS DWORD, _
    lplpBuffer             AS ANY, _          ' BYTE PTR PTR
    lpdwBufferSize         AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprConfigInterfaceSetInfo LIB "MprApi.dll" _
    ALIAS "MprConfigInterfaceSetInfo" ( _
    BYVAL hMprConfig       AS DWORD, _        ' HANDLE
    BYVAL hRouterInterface AS DWORD, _        ' HANDLE
    BYVAL dwLevel          AS DWORD, _
    BYVAL lpbBuffer        AS BYTE PTR _
    ) AS DWORD

DECLARE FUNCTION MprConfigInterfaceEnum LIB "MprApi.dll" _
    ALIAS "MprConfigInterfaceEnum" ( _
    BYVAL hMprConfig   AS DWORD, _            ' HANDLE
    BYVAL dwLevel      AS DWORD, _
    lplpBuffer         AS ANY, _              ' BYTE PTR PTR
    BYVAL dwPrefMaxLen AS DWORD, _
    lpdwEntriesRead    AS DWORD, _
    lpdwTotalEntries   AS DWORD, _
    lpdwResumeHandle   AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprConfigInterfaceTransportAdd LIB "MprApi.dll" _
    ALIAS "MprConfigInterfaceTransportAdd" ( _
    BYVAL hMprConfig          AS DWORD, _     ' HANDLE
    BYVAL hRouterInterface    AS DWORD, _     ' HANDLE
    BYVAL dwTransportId       AS DWORD, _
    lpwsTransportName         AS WSTRINGZ, _
    BYVAL pInterfaceInfo      AS BYTE PTR, _
    BYVAL dwInterfaceInfoSize AS DWORD, _
    phRouterIfTransport       AS DWORD _      ' HANDLE
    ) AS DWORD

DECLARE FUNCTION MprConfigInterfaceTransportRemove LIB "MprApi.dll" _
    ALIAS "MprConfigInterfaceTransportRemove" ( _
    BYVAL hMprConfig         AS DWORD, _      ' HANDLE
    BYVAL hRouterInterface   AS DWORD, _      ' HANDLE
    BYVAL hRouterIfTransport AS DWORD _       ' HANDLE
    ) AS DWORD

DECLARE FUNCTION MprConfigInterfaceTransportGetHandle LIB "MprApi.dll" _
    ALIAS "MprConfigInterfaceTransportGetHandle" ( _
    BYVAL hMprConfig       AS DWORD, _        ' HANDLE
    BYVAL hRouterInterface AS DWORD, _        ' HANDLE
    BYVAL dwTransportId    AS DWORD, _
    phRouterIfTransport    AS DWORD _         ' HANDLE
    ) AS DWORD

DECLARE FUNCTION MprConfigInterfaceTransportGetInfo LIB "MprApi.dll" _
    ALIAS "MprConfigInterfaceTransportGetInfo" ( _
    BYVAL hMprConfig         AS DWORD, _      ' HANDLE
    BYVAL hRouterInterface   AS DWORD, _      ' HANDLE
    BYVAL hRouterIfTransport AS DWORD, _      ' HANDLE
    ppInterfaceInfo          AS ANY, _        ' BYTE PTR PTR
    lpdwInterfaceInfoSize    AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprConfigInterfaceTransportSetInfo LIB "MprApi.dll" _
    ALIAS "MprConfigInterfaceTransportSetInfo" ( _
    BYVAL hMprConfig          AS DWORD, _     ' HANDLE
    BYVAL hRouterInterface    AS DWORD, _     ' HANDLE
    BYVAL hRouterIfTransport  AS DWORD, _     ' HANDLE
    BYVAL pInterfaceInfo      AS BYTE PTR, _
    BYVAL dwInterfaceInfoSize AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprConfigInterfaceTransportEnum LIB "MprApi.dll" _
    ALIAS "MprConfigInterfaceTransportEnum" ( _
    BYVAL hMprConfig       AS DWORD, _        ' HANDLE
    BYVAL hRouterInterface AS DWORD, _        ' HANDLE
    BYVAL dwLevel          AS DWORD, _
    lplpBuffer             AS ANY,   _        ' BYTE PTR PTR 'MPR_IFTRANSPORT_0
    BYVAL dwPrefMaxLen     AS DWORD, _
    lpdwEntriesRead        AS DWORD, _
    lpdwTotalEntries       AS DWORD, _
    lpdwResumeHandle       AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprConfigGetFriendlyName LIB "MprApi.dll" _
    ALIAS "MprConfigGetFriendlyName" ( _
    BYVAL hMprConfig   AS DWORD, _       ' HANDLE
    pszGuidName        AS WSTRINGZ, _
    pszBuffer          AS WSTRINGZ, _
    BYVAL dwBufferSize AS DWORD _
    ) AS DWORD

DECLARE FUNCTION MprConfigGetGuidName LIB "MprApi.dll" _
    ALIAS "MprConfigGetGuidName" ( _
    BYVAL hMprConfig   AS DWORD, _       ' HANDLE
    pszFriendlyName    AS WSTRINGZ, _
    pszBuffer          AS WSTRINGZ, _
    BYVAL dwBufferSize AS DWORD _
    ) AS DWORD

#IF (%WINVER >= &H0600)

DECLARE FUNCTION MprConfigFilterGetInfo LIB "MprApi.dll" _
    ALIAS "MprConfigFilterGetInfo" ( _
    BYVAL hMprConfig    AS DWORD, _      ' HANDLE
    BYVAL dwLevel       AS DWORD, _
    BYVAL dwTransportId AS DWORD, _
    BYVAL lpBuffer      AS BYTE PTR _
    ) AS DWORD

DECLARE FUNCTION MprConfigFilterSetInfo LIB "MprApi.dll" _
    ALIAS "MprConfigFilterSetInfo" ( _
    BYVAL hMprConfig       AS DWORD, _   ' HANDLE
    BYVAL dwLevel          AS DWORD, _
    BYVAL dwTransportId    AS DWORD, _
    BYVAL lpBuffer         AS BYTE PTR _
    ) AS DWORD

#ENDIF ' %WINVER >= &H0600

'
' Information block APIs
'

DECLARE FUNCTION MprInfoCreate LIB "MprApi.dll" _
    ALIAS "MprInfoCreate" ( _
    BYVAL dwVersion AS DWORD, _
    lplpNewHeader   AS ANY _         ' LPVOID*
    ) AS DWORD

DECLARE FUNCTION MprInfoDelete LIB "MprApi.dll" _
    ALIAS "MprInfoDelete" ( _
    BYVAL lpHeader AS DWORD _        ' LPVOID
    ) AS DWORD

DECLARE FUNCTION MprInfoRemoveAll LIB "MprApi.dll" _
    ALIAS "MprInfoRemoveAll" ( _
    BYVAL lpHeader AS DWORD, _       ' LPVOID
    lplpNewHeader  AS ANY _          ' LPVOID*
    ) AS DWORD

DECLARE FUNCTION MprInfoDuplicate LIB "MprApi.dll" _
    ALIAS "MprInfoDuplicate" ( _
    BYVAL lpHeader AS DWORD, _       ' LPVOID
    lplpNewHeader  AS ANY _          ' LPVOID*
    ) AS DWORD

DECLARE FUNCTION MprInfoBlockAdd LIB "MprApi.dll" _
    ALIAS "MprInfoBlockAdd" ( _
    BYVAL lpHeader    AS DWORD, _    ' LPVOID
    BYVAL dwInfoType  AS DWORD, _
    BYVAL dwItemSize  AS DWORD, _
    BYVAL dwItemCount AS DWORD, _
    BYVAL lpItemData  AS BYTE PTR, _
    lplpNewHeader     AS ANY _       ' LPVOID*
) AS DWORD

DECLARE FUNCTION MprInfoBlockRemove LIB "MprApi.dll" _
    ALIAS "MprInfoBlockRemove" ( _
    BYVAL lpHeader   AS DWORD, _     ' LPVOID
    BYVAL dwInfoType AS DWORD, _
    lplpNewHeader    AS ANY _        ' LPVOID*
    ) AS DWORD

DECLARE FUNCTION MprInfoBlockSet LIB "MprApi.dll" _
    ALIAS "MprInfoBlockSet" ( _
    BYVAL lpHeader    AS DWORD, _    ' LPVOID
    BYVAL dwInfoType  AS DWORD, _
    BYVAL dwItemSize  AS DWORD, _
    BYVAL dwItemCount AS DWORD, _
    BYVAL lpItemData  AS BYTE PTR, _
    lplpNewHeader     AS ANY _       ' LPVOID*
    ) AS DWORD

DECLARE FUNCTION MprInfoBlockFind LIB "MprApi.dll" _
    ALIAS "MprInfoBlockFind" ( _
    BYVAL lpHeader   AS DWORD, _
    BYVAL dwInfoType AS DWORD, _
    lpdwItemSize     AS DWORD, _     ' OPTIONAL
    lpdwItemCount    AS DWORD, _     ' OPTIONAL
    lplpItemData     AS ANY _        ' OPTIONAL BYTE PTR PTR
    ) AS DWORD

DECLARE FUNCTION MprInfoBlockQuerySize LIB "MprApi.dll" _
    ALIAS "MprInfoBlockQuerySize" ( _
    BYVAL lpHeader AS DWORD _        ' LPVOID
    ) AS DWORD

'
' BOOL APIENTRY
' MprInfoBlockExists(
'     LPVOID                  lpHeader,
'     DWORD                   dwInfoType
' );
'


MACRO MprInfoBlockExists(h,t)=ABS(MprInfoBlockFind(h,t,%NULL,%NULL,%NULL)=%NO_ERROR)
