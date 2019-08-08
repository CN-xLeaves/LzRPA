'------------------------------------------------------------------------------
'
'  IpIfCons.inc  - Constants needed for the Interface Object
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from IpIfCons.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%IPIFCONS_H = 1


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''                                                                          ''
'' Media types                                                              ''
''                                                                          ''
'' These are enumerated values of the ifType object defined in MIB-II's     ''
'' ifTable.  They are registered with IANA which publishes this list        ''
'' periodically, in either the Assigned Numbers RFC, or some derivative     ''
'' of it specific to Internet Network Management number assignments.        ''
'' See ftp:''ftp.isi.edu'mib'ianaiftype.mib                                 ''
''                                                                          ''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

%MIN_IF_TYPE                     = 1

%IF_TYPE_OTHER                   = 1   ' None of the below
%IF_TYPE_REGULAR_1822            = 2
%IF_TYPE_HDH_1822                = 3
%IF_TYPE_DDN_X25                 = 4
%IF_TYPE_RFC877_X25              = 5
%IF_TYPE_ETHERNET_CSMACD         = 6
%IF_TYPE_IS088023_CSMACD         = 7
%IF_TYPE_ISO88024_TOKENBUS       = 8
%IF_TYPE_ISO88025_TOKENRING      = 9
%IF_TYPE_ISO88026_MAN            = 10
%IF_TYPE_STARLAN                 = 11
%IF_TYPE_PROTEON_10MBIT          = 12
%IF_TYPE_PROTEON_80MBIT          = 13
%IF_TYPE_HYPERCHANNEL            = 14
%IF_TYPE_FDDI                    = 15
%IF_TYPE_LAP_B                   = 16
%IF_TYPE_SDLC                    = 17
%IF_TYPE_DS1                     = 18  ' DS1-MIB
%IF_TYPE_E1                      = 19  ' Obsolete; see DS1-MIB
%IF_TYPE_BASIC_ISDN              = 20
%IF_TYPE_PRIMARY_ISDN            = 21
%IF_TYPE_PROP_POINT2POINT_SERIAL = 22  ' proprietary serial
%IF_TYPE_PPP                     = 23
%IF_TYPE_SOFTWARE_LOOPBACK       = 24
%IF_TYPE_EON                     = 25  ' CLNP over IP
%IF_TYPE_ETHERNET_3MBIT          = 26
%IF_TYPE_NSIP                    = 27  ' XNS over IP
%IF_TYPE_SLIP                    = 28  ' Generic Slip
%IF_TYPE_ULTRA                   = 29  ' ULTRA Technologies
%IF_TYPE_DS3                     = 30  ' DS3-MIB
%IF_TYPE_SIP                     = 31  ' SMDS, coffee
%IF_TYPE_FRAMERELAY              = 32  ' DTE only
%IF_TYPE_RS232                   = 33
%IF_TYPE_PARA                    = 34  ' Parallel port
%IF_TYPE_ARCNET                  = 35
%IF_TYPE_ARCNET_PLUS             = 36
%IF_TYPE_ATM                     = 37  ' ATM cells
%IF_TYPE_MIO_X25                 = 38
%IF_TYPE_SONET                   = 39  ' SONET or SDH
%IF_TYPE_X25_PLE                 = 40
%IF_TYPE_ISO88022_LLC            = 41
%IF_TYPE_LOCALTALK               = 42
%IF_TYPE_SMDS_DXI                = 43
%IF_TYPE_FRAMERELAY_SERVICE      = 44  ' FRNETSERV-MIB
%IF_TYPE_V35                     = 45
%IF_TYPE_HSSI                    = 46
%IF_TYPE_HIPPI                   = 47
%IF_TYPE_MODEM                   = 48  ' Generic Modem
%IF_TYPE_AAL5                    = 49  ' AAL5 over ATM
%IF_TYPE_SONET_PATH              = 50
%IF_TYPE_SONET_VT                = 51
%IF_TYPE_SMDS_ICIP               = 52  ' SMDS InterCarrier Interface
%IF_TYPE_PROP_VIRTUAL            = 53  ' Proprietary virtual/internal
%IF_TYPE_PROP_MULTIPLEXOR        = 54  ' Proprietary multiplexing
%IF_TYPE_IEEE80212               = 55  ' 100BaseVG
%IF_TYPE_FIBRECHANNEL            = 56
%IF_TYPE_HIPPIINTERFACE          = 57
%IF_TYPE_FRAMERELAY_INTERCONNECT = 58  ' Obsolete, use 32 or 44
%IF_TYPE_AFLANE_8023             = 59  ' ATM Emulated LAN for 802.3
%IF_TYPE_AFLANE_8025             = 60  ' ATM Emulated LAN for 802.5
%IF_TYPE_CCTEMUL                 = 61  ' ATM Emulated circuit
%IF_TYPE_FASTETHER               = 62  ' Fast Ethernet (100BaseT)
%IF_TYPE_ISDN                    = 63  ' ISDN and X.25
%IF_TYPE_V11                     = 64  ' CCITT V.11/X.21
%IF_TYPE_V36                     = 65  ' CCITT V.36
%IF_TYPE_G703_64K                = 66  ' CCITT G703 at 64Kbps
%IF_TYPE_G703_2MB                = 67  ' Obsolete; see DS1-MIB
%IF_TYPE_QLLC                    = 68  ' SNA QLLC
%IF_TYPE_FASTETHER_FX            = 69  ' Fast Ethernet (100BaseFX)
%IF_TYPE_CHANNEL                 = 70
%IF_TYPE_IEEE80211               = 71  ' Radio spread spectrum
%IF_TYPE_IBM370PARCHAN           = 72  ' IBM System 360/370 OEMI Channel
%IF_TYPE_ESCON                   = 73  ' IBM Enterprise Systems Connection
%IF_TYPE_DLSW                    = 74  ' Data Link Switching
%IF_TYPE_ISDN_S                  = 75  ' ISDN S/T interface
%IF_TYPE_ISDN_U                  = 76  ' ISDN U interface
%IF_TYPE_LAP_D                   = 77  ' Link Access Protocol D
%IF_TYPE_IPSWITCH                = 78  ' IP Switching Objects
%IF_TYPE_RSRB                    = 79  ' Remote Source Route Bridging
%IF_TYPE_ATM_LOGICAL             = 80  ' ATM Logical Port
%IF_TYPE_DS0                     = 81  ' Digital Signal Level 0
%IF_TYPE_DS0_BUNDLE              = 82  ' Group of ds0s on the same ds1
%IF_TYPE_BSC                     = 83  ' Bisynchronous Protocol
%IF_TYPE_ASYNC                   = 84  ' Asynchronous Protocol
%IF_TYPE_CNR                     = 85  ' Combat Net Radio
%IF_TYPE_ISO88025R_DTR           = 86  ' ISO 802.5r DTR
%IF_TYPE_EPLRS                   = 87  ' Ext Pos Loc Report Sys
%IF_TYPE_ARAP                    = 88  ' Appletalk Remote Access Protocol
%IF_TYPE_PROP_CNLS               = 89  ' Proprietary Connectionless Proto
%IF_TYPE_HOSTPAD                 = 90  ' CCITT-ITU X.29 PAD Protocol
%IF_TYPE_TERMPAD                 = 91  ' CCITT-ITU X.3 PAD Facility
%IF_TYPE_FRAMERELAY_MPI          = 92  ' Multiproto Interconnect over FR
%IF_TYPE_X213                    = 93  ' CCITT-ITU X213
%IF_TYPE_ADSL                    = 94  ' Asymmetric Digital Subscrbr Loop
%IF_TYPE_RADSL                   = 95  ' Rate-Adapt Digital Subscrbr Loop
%IF_TYPE_SDSL                    = 96  ' Symmetric Digital Subscriber Loop
%IF_TYPE_VDSL                    = 97  ' Very H-Speed Digital Subscrb Loop
%IF_TYPE_ISO88025_CRFPRINT       = 98  ' ISO 802.5 CRFP
%IF_TYPE_MYRINET                 = 99  ' Myricom Myrinet
%IF_TYPE_VOICE_EM                = 100 ' Voice recEive and transMit
%IF_TYPE_VOICE_FXO               = 101 ' Voice Foreign Exchange Office
%IF_TYPE_VOICE_FXS               = 102 ' Voice Foreign Exchange Station
%IF_TYPE_VOICE_ENCAP             = 103 ' Voice encapsulation
%IF_TYPE_VOICE_OVERIP            = 104 ' Voice over IP encapsulation
%IF_TYPE_ATM_DXI                 = 105 ' ATM DXI
%IF_TYPE_ATM_FUNI                = 106 ' ATM FUNI
%IF_TYPE_ATM_IMA                 = 107 ' ATM IMA
%IF_TYPE_PPPMULTILINKBUNDLE      = 108 ' PPP Multilink Bundle
%IF_TYPE_IPOVER_CDLC             = 109 ' IBM ipOverCdlc
%IF_TYPE_IPOVER_CLAW             = 110 ' IBM Common Link Access to Workstn
%IF_TYPE_STACKTOSTACK            = 111 ' IBM stackToStack
%IF_TYPE_VIRTUALIPADDRESS        = 112 ' IBM VIPA
%IF_TYPE_MPC                     = 113 ' IBM multi-proto channel support
%IF_TYPE_IPOVER_ATM              = 114 ' IBM ipOverAtm
%IF_TYPE_ISO88025_FIBER          = 115 ' ISO 802.5j Fiber Token Ring
%IF_TYPE_TDLC                    = 116 ' IBM twinaxial data link control
%IF_TYPE_GIGABITETHERNET         = 117
%IF_TYPE_HDLC                    = 118
%IF_TYPE_LAP_F                   = 119
%IF_TYPE_V37                     = 120
%IF_TYPE_X25_MLP                 = 121 ' Multi-Link Protocol
%IF_TYPE_X25_HUNTGROUP           = 122 ' X.25 Hunt Group
%IF_TYPE_TRANSPHDLC              = 123
%IF_TYPE_INTERLEAVE              = 124 ' Interleave channel
%IF_TYPE_FAST                    = 125 ' Fast channel
%IF_TYPE_IP                      = 126 ' IP (for APPN HPR in IP networks)
%IF_TYPE_DOCSCABLE_MACLAYER      = 127 ' CATV Mac Layer
%IF_TYPE_DOCSCABLE_DOWNSTREAM    = 128 ' CATV Downstream interface
%IF_TYPE_DOCSCABLE_UPSTREAM      = 129 ' CATV Upstream interface
%IF_TYPE_A12MPPSWITCH            = 130 ' Avalon Parallel Processor
%IF_TYPE_TUNNEL                  = 131 ' Encapsulation interface
%IF_TYPE_COFFEE                  = 132 ' Coffee pot
%IF_TYPE_CES                     = 133 ' Circuit Emulation Service
%IF_TYPE_ATM_SUBINTERFACE        = 134 ' ATM Sub Interface
%IF_TYPE_L2_VLAN                 = 135 ' Layer 2 Virtual LAN using 802.1Q
%IF_TYPE_L3_IPVLAN               = 136 ' Layer 3 Virtual LAN using IP
%IF_TYPE_L3_IPXVLAN              = 137 ' Layer 3 Virtual LAN using IPX
%IF_TYPE_DIGITALPOWERLINE        = 138 ' IP over Power Lines
%IF_TYPE_MEDIAMAILOVERIP         = 139 ' Multimedia Mail over IP
%IF_TYPE_DTM                     = 140 ' Dynamic syncronous Transfer Mode
%IF_TYPE_DCN                     = 141 ' Data Communications Network
%IF_TYPE_IPFORWARD               = 142 ' IP Forwarding Interface
%IF_TYPE_MSDSL                   = 143 ' Multi-rate Symmetric DSL
%IF_TYPE_IEEE1394                = 144 ' IEEE1394 High Perf Serial Bus
%IF_TYPE_IF_GSN                  = 145
%IF_TYPE_DVBRCC_MACLAYER         = 146
%IF_TYPE_DVBRCC_DOWNSTREAM       = 147
%IF_TYPE_DVBRCC_UPSTREAM         = 148
%IF_TYPE_ATM_VIRTUAL             = 149
%IF_TYPE_MPLS_TUNNEL             = 150
%IF_TYPE_SRP                     = 151
%IF_TYPE_VOICEOVERATM            = 152
%IF_TYPE_VOICEOVERFRAMERELAY     = 153
%IF_TYPE_IDSL                    = 154
%IF_TYPE_COMPOSITELINK           = 155
%IF_TYPE_SS7_SIGLINK             = 156
%IF_TYPE_PROP_WIRELESS_P2P       = 157
%IF_TYPE_FR_FORWARD              = 158
%IF_TYPE_RFC1483                 = 159
%IF_TYPE_USB                     = 160
%IF_TYPE_IEEE8023AD_LAG          = 161
%IF_TYPE_BGP_POLICY_ACCOUNTING   = 162
%IF_TYPE_FRF16_MFR_BUNDLE        = 163
%IF_TYPE_H323_GATEKEEPER         = 164
%IF_TYPE_H323_PROXY              = 165
%IF_TYPE_MPLS                    = 166
%IF_TYPE_MF_SIGLINK              = 167
%IF_TYPE_HDSL2                   = 168
%IF_TYPE_SHDSL                   = 169
%IF_TYPE_DS1_FDL                 = 170
%IF_TYPE_POS                     = 171
%IF_TYPE_DVB_ASI_IN              = 172
%IF_TYPE_DVB_ASI_OUT             = 173
%IF_TYPE_PLC                     = 174
%IF_TYPE_NFAS                    = 175
%IF_TYPE_TR008                   = 176
%IF_TYPE_GR303_RDT               = 177
%IF_TYPE_GR303_IDT               = 178
%IF_TYPE_ISUP                    = 179
%IF_TYPE_PROP_DOCS_WIRELESS_MACLAYER      = 180
%IF_TYPE_PROP_DOCS_WIRELESS_DOWNSTREAM    = 181
%IF_TYPE_PROP_DOCS_WIRELESS_UPSTREAM      = 182
%IF_TYPE_HIPERLAN2                        = 183
%IF_TYPE_PROP_BWA_P2MP                    = 184
%IF_TYPE_SONET_OVERHEAD_CHANNEL           = 185
%IF_TYPE_DIGITAL_WRAPPER_OVERHEAD_CHANNEL = 186
%IF_TYPE_AAL2                             = 187
%IF_TYPE_RADIO_MAC                        = 188
%IF_TYPE_ATM_RADIO                        = 189
%IF_TYPE_IMT                              = 190
%IF_TYPE_MVL                              = 191
%IF_TYPE_REACH_DSL                        = 192
%IF_TYPE_FR_DLCI_ENDPT                    = 193
%IF_TYPE_ATM_VCI_ENDPT                    = 194
%IF_TYPE_OPTICAL_CHANNEL                  = 195
%IF_TYPE_OPTICAL_TRANSPORT                = 196
%IF_TYPE_IEEE80216_WMAN                   = 237
%IF_TYPE_WWANPP                = 243 ' WWAN devices based on GSM technology
%IF_TYPE_WWANPP2               = 244 ' WWAN devices based on CDMA technology

%MAX_IF_TYPE                   = 244

MACRO IFTYPE=DWORD

''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''                                                                          ''
'' Access types                                                             ''
''                                                                          ''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

MACRO IF_ACCESS_TYPE_enum=LONG
ENUM IF_ACCESS_TYPE SINGULAR
    IF_ACCESS_LOOPBACK             = 1
    IF_ACCESS_BROADCAST            = 2
    IF_ACCESS_POINT_TO_POINT       = 3  ' New definition.
    IF_ACCESS_POINTTOPOINT         = 3  ' Old definition.
    IF_ACCESS_POINT_TO_MULTI_POINT = 4  ' New definition.
    IF_ACCESS_POINTTOMULTIPOINT    = 4  ' Old definition.
END ENUM


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''                                                                          ''
'' Interface Capabilities (bit flags)                                       ''
''                                                                          ''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

%IF_CHECK_NONE                 = &H00
%IF_CHECK_MCAST                = &H01
%IF_CHECK_SEND                 = &H02


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''                                                                          ''
'' Connection Types                                                         ''
''                                                                          ''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

%IF_CONNECTION_DEDICATED       = 1
%IF_CONNECTION_PASSIVE         = 2
%IF_CONNECTION_DEMAND          = 3


%IF_ADMIN_STATUS_UP            = 1
%IF_ADMIN_STATUS_DOWN          = 2
%IF_ADMIN_STATUS_TESTING       = 3

''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''                                                                          ''
'' The following are the the operational states for WAN and LAN interfaces. ''
'' The order of the states seems weird, but is done for a purpose. All      ''
'' states >= CONNECTED can transmit data right away. States >= DISCONNECTED ''
'' can tx data but some set up might be needed. States < DISCONNECTED can   ''
'' not transmit data.                                                       ''
'' A card is marked UNREACHABLE if DIM calls InterfaceUnreachable for       ''
'' reasons other than failure to connect.                                   ''
''                                                                          ''
'' NON_OPERATIONAL -- Valid for LAN Interfaces. Means the card is not       ''
''                      working or not plugged in or has no address.        ''
'' UNREACHABLE     -- Valid for WAN Interfaces. Means the remote site is    ''
''                      not reachable at this time.                         ''
'' DISCONNECTED    -- Valid for WAN Interfaces. Means the remote site is    ''
''                      not connected at this time.                         ''
'' CONNECTING      -- Valid for WAN Interfaces. Means a connection attempt  ''
''                      has been initiated to the remote site.              ''
'' CONNECTED       -- Valid for WAN Interfaces. Means the remote site is    ''
''                      connected.                                          ''
'' OPERATIONAL     -- Valid for LAN Interfaces. Means the card is plugged   ''
''                      in and working.                                     ''
''                                                                          ''
'' It is the users duty to convert these values to MIB-II values if they    ''
'' are to be used by a subagent                                             ''
''                                                                          ''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

MACRO INTERNAL_IF_OPER_STATUS_enum=LONG
ENUM INTERNAL_IF_OPER_STATUS SINGULAR
    IF_OPER_STATUS_NON_OPERATIONAL
    IF_OPER_STATUS_UNREACHABLE
    IF_OPER_STATUS_DISCONNECTED
    IF_OPER_STATUS_CONNECTING
    IF_OPER_STATUS_CONNECTED
    IF_OPER_STATUS_OPERATIONAL
END ENUM

%MIB_IF_TYPE_OTHER             = 1
%MIB_IF_TYPE_ETHERNET          = 6
%MIB_IF_TYPE_TOKENRING         = 9
%MIB_IF_TYPE_FDDI              = 15
%MIB_IF_TYPE_PPP               = 23
%MIB_IF_TYPE_LOOPBACK          = 24
%MIB_IF_TYPE_SLIP              = 28

%MIB_IF_ADMIN_STATUS_UP        = 1
%MIB_IF_ADMIN_STATUS_DOWN      = 2
%MIB_IF_ADMIN_STATUS_TESTING   = 3

'
' N.B. The name is a misnomer.  These are NOT the values used by MIB-II.
'
%MIB_IF_OPER_STATUS_NON_OPERATIONAL   = %IF_OPER_STATUS_NON_OPERATIONAL
%MIB_IF_OPER_STATUS_UNREACHABLE       = %IF_OPER_STATUS_UNREACHABLE
%MIB_IF_OPER_STATUS_DISCONNECTED      = %IF_OPER_STATUS_DISCONNECTED
%MIB_IF_OPER_STATUS_CONNECTING        = %IF_OPER_STATUS_CONNECTING
%MIB_IF_OPER_STATUS_CONNECTED         = %IF_OPER_STATUS_CONNECTED
%MIB_IF_OPER_STATUS_OPERATIONAL       = %IF_OPER_STATUS_OPERATIONAL
