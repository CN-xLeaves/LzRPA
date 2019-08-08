'------------------------------------------------------------------------------
'
'  MCX.inc - This module defines the 32-Bit Windows MCX APIs
'
'  Copyright (c) 1997-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from MCX.h dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%MCX_H = 1


TYPE MODEMDEVCAPS
    dwActualSize              AS DWORD
    dwRequiredSize            AS DWORD
    dwDevSpecificOffset       AS DWORD
    dwDevSpecificSize         AS DWORD

    ' product and version identification
    dwModemProviderVersion    AS DWORD
    dwModemManufacturerOffset AS DWORD
    dwModemManufacturerSize   AS DWORD
    dwModemModelOffset        AS DWORD
    dwModemModelSize          AS DWORD
    dwModemVersionOffset      AS DWORD
    dwModemVersionSize        AS DWORD

    ' local option capabilities
    dwDialOptions             AS DWORD  ' bitmap of supported values
    dwCallSetupFailTimer      AS DWORD  ' maximum in seconds
    dwInactivityTimeout       AS DWORD  ' maximum in seconds
    dwSpeakerVolume           AS DWORD  ' bitmap of supported values
    dwSpeakerMode             AS DWORD  ' bitmap of supported values
    dwModemOptions            AS DWORD  ' bitmap of supported values
    dwMaxDTERate              AS DWORD  ' maximum value in bit/s
    dwMaxDCERate              AS DWORD  ' maximum value in bit/s

    ' Variable portion for proprietary expansion
    abVariablePortion(0)      AS BYTE
END TYPE

TYPE MODEMSETTINGS
    dwActualSize            AS DWORD
    dwRequiredSize          AS DWORD
    dwDevSpecificOffset     AS DWORD
    dwDevSpecificSize       AS DWORD

    ' static local options (read/write)
    dwCallSetupFailTimer    AS DWORD    ' seconds
    dwInactivityTimeout     AS DWORD    ' seconds
    dwSpeakerVolume         AS DWORD    ' level
    dwSpeakerMode           AS DWORD    ' mode
    dwPreferredModemOptions AS DWORD    ' bitmap

    ' negotiated options (read only) for current or last call
    dwNegotiatedModemOptions AS DWORD   ' bitmap
    dwNegotiatedDCERate      AS DWORD   ' bit/s

    ' Variable portion for proprietary expansion
    abVariablePortion(0)     AS BYTE
END TYPE

' Dial Options
%DIALOPTION_BILLING  = &H00000040  ' Supports wait for bong "$"
%DIALOPTION_QUIET    = &H00000080  ' Supports wait for quiet "@"
%DIALOPTION_DIALTONE = &H00000100  ' Supports wait for dial tone "W"

' SpeakerVolume for MODEMDEVCAPS
%MDMVOLFLAG_LOW      = &H00000001
%MDMVOLFLAG_MEDIUM   = &H00000002
%MDMVOLFLAG_HIGH     = &H00000004

' SpeakerVolume for MODEMSETTINGS
%MDMVOL_LOW          = &H00000000
%MDMVOL_MEDIUM       = &H00000001
%MDMVOL_HIGH         = &H00000002

' SpeakerMode for MODEMDEVCAPS
%MDMSPKRFLAG_OFF         = &H00000001
%MDMSPKRFLAG_DIAL        = &H00000002
%MDMSPKRFLAG_ON          = &H00000004
%MDMSPKRFLAG_CALLSETUP   = &H00000008

' SpeakerMode for MODEMSETTINGS
%MDMSPKR_OFF         = &H00000000
%MDMSPKR_DIAL        = &H00000001
%MDMSPKR_ON          = &H00000002
%MDMSPKR_CALLSETUP   = &H00000003

' Modem Options
%MDM_COMPRESSION      = &H00000001
%MDM_ERROR_CONTROL    = &H00000002
%MDM_FORCED_EC        = &H00000004
%MDM_CELLULAR         = &H00000008
%MDM_FLOWCONTROL_HARD = &H00000010
%MDM_FLOWCONTROL_SOFT = &H00000020
%MDM_CCITT_OVERRIDE   = &H00000040
%MDM_SPEED_ADJUST     = &H00000080
%MDM_TONE_DIAL        = &H00000100
%MDM_BLIND_DIAL       = &H00000200
%MDM_V23_OVERRIDE     = &H00000400
%MDM_DIAGNOSTICS      = &H00000800


'=========================================================================
'
'
'      EXTENDED MODEM OPTIONS INFORMATION
'
'      THE following macros define additional bits in dwPreferredModemOptions.
'
'      These bits specify information relevant to making ISDN and GSM
'      calls, such as which protocol to use.
'
'=========================================================================

%MDM_MASK_BEARERMODE  = &H0000f000
%MDM_SHIFT_BEARERMODE = 12

%MDM_MASK_PROTOCOLID   = &H000f0000
%MDM_SHIFT_PROTOCOLID  = 16

%MDM_MASK_PROTOCOLDATA  = &H0ff00000
%MDM_SHIFT_PROTOCOLDATA = 20

'
' PROTOCOLINFO is the union of PROTOCOLID and PROTOCOLDATA ...
'
%MDM_MASK_PROTOCOLINFO  = (%MDM_MASK_PROTOCOLID OR %MDM_MASK_PROTOCOLDATA)
%MDM_SHIFT_PROTOCOLINFO = %MDM_SHIFT_PROTOCOLID

'
' EXTENDEDINFO is the union of BEARERMODE and PROTOCOLINFO
'
%MDM_MASK_EXTENDEDINFO  = (%MDM_MASK_BEARERMODE OR %MDM_MASK_PROTOCOLINFO)
%MDM_SHIFT_EXTENDEDINFO = %MDM_SHIFT_BEARERMODE


MACRO FUNCTION MDM_GET_BEARERMODE(dwOptions)
    MACROTEMP dwd
    LOCAL dwd AS DWORD
    dwd = (dwOptions) AND %MDM_MASK_BEARERMODE
    SHIFT RIGHT dwd, %MDM_SHIFT_BEARERMODE
END MACRO=dwd

MACRO MDM_SET_BEARERMODE(dwOptions,bm)
    MACROTEMP dwd
    LOCAL dwd AS DWORD
    dwd = (bm)
    SHIFT LEFT dwd, %MDM_SHIFT_BEARERMODE
    dwOptions AND= NOT %MDM_MASK_BEARERMODE
    dwOptions OR= dwd AND %MDM_MASK_BEARERMODE
END MACRO

MACRO FUNCTION MDM_GET_PROTOCOLID(dwOptions)
    MACROTEMP dwd
    LOCAL dwd AS DWORD
    dwd = (dwOptions AND %MDM_MASK_PROTOCOLID)
    SHIFT RIGHT dwd, %MDM_SHIFT_PROTOCOLID
END MACRO=dwd

MACRO MDM_SET_PROTOCOLID(dwOptions,prot)
    MACROTEMP dwd
    LOCAL dwd AS DWORD
    dwOptions AND= NOT %MDM_MASM_PROTOCOLID
    dwd = (prot)
    SHIFT LEFT dwd, %MDM_SHIFT_PROTOCOLID
    dwOptions OR= dwd AND %MDM_MASK_PROTOCOLID
END MACRO

MACRO FUNCTION MDM_GET_PROTOCOLDATA(dwOptions)
    MACROTEMP dwd
    LOCAL dwd AS DWORD
    dwd = (dwOptions) AND %MDM_MASK_PROTOCOLDATA
    SHIFT RIGHT dwd, %MDM_SHIFT_PROTOCOLDATA
END MACRO=dwd

MACRO MDM_SET_PROTOCOLDATA(dwOptions,pd)
    MACROTEMP dwd
    LOCAL dwd AS DWORD
    dwOptions AND= NOT %MDM_MASK_PROTOCOLDATA
    dwd = (pd)
    SHIFT LEFT dwd, %MDM_SHIFT_PROTOCOLDATA
    dwOptions OR= dwd AND %MDM_MASK_PROTOCOLDATA
END MACRO

'
' MDM_GET_PROTOCOLINFO gets the protocol-id and info bits in
' their IN-PLACE form (preserving their place in dwModemPreferredOptions)
'
MACRO MDM_GET_PROTOCOLINFO(dwOptions)=((dwOptions) AND %MDM_MASK_PROTOCOLINFO)

'
' MDM_SET_PROTOCOLINFO takes as its argument the protocol-id and info bits in
' their IN-PLACE form (final position within dwModemPreferredOptions)
'
MACRO MDM_SET_PROTOCOLINFO(dwOptions,pinfo)
    dwOptions AND= NOT %MDM_MASK_PROTOCOLINFO
    dwOptions OR= (pinfo AND %MDM_MASK_PROTOCOLINFO)
END MACRO

'
' MDM_GEN_PROTOCOLINFO generates the  the protocol-id and info bits in
' their IN-PLACE form (final position  within dwModemPreferredOptions).
'
MACRO FUNCTION MDM_GEN_PROTOCOLINFO(pid,pdata)
    MACROTEMP dwA, dwB
    LOCAL dwA, dwB AS DWORD
    dwA = (pid)
    SHIFT LEFT dwA, %MDM_SHIFT_PROTOCOLID
    dwA AND= %MDM_MASK_PROTOCOLID
    dwB = (pdata)
    SHIFT LEFT dwB, %MDM_SHIFT_PROTOCOLDATA
    dwB AND= %MDM_MASK_PROTOCOLDATA
END MACRO=dwA OR dwB

'
' MDM_GET_EXTENDEDIONFO gets the bearermode and protocol information in
' their IN-PLACE form (preserving their place in dwModemPreferredOptions)
'
MACRO MDM_GET_EXTENDEDINFO(dwOptions)=((dwOptions) AND %MDM_MASK_EXTENDEDINFO)

'
' MDM_SET_PROTOCOLINFO takes as its argument the bearermode and
' protocol bits in their IN-PLACE form (final position within
' dwModemPreferredOptions)
'
MACRO MDM_SET_EXTENDEDINFO(dwOptions,extinfo)
    dwOptions AND= NOT %MDM_MASK_EXTENDEDINFO
    dwOptions OR= (extinfo) AND %MDM_MASK_EXTENDEDINFO
END MACRO


'
' %MDM_GEN_EXTENDEDINFO generates the bearermode and protocol information
' in their IN-PLACE form (final position within dwModemPreferredOptions0.
'
MACRO FUNCTION MDM_GEN_EXTENDEDINFO(bearermode,pinfo)
    MACROTEMP dwd
    LOCAL dwd AS DWORD
    dwd = (bearermode)
    SHIFT LEFT dwd, %MDM_SHIFT_BEARERMODE
    dwd AND= %MDM_MASK_BEARERMODE
    dwd OR= (pinfo) AND %MDM_MASK_PROTOCOLINFO
END MACRO=dwd


'=========================================================================
'  BEARER MODES
'=========================================================================
'
%MDM_BEARERMODE_ANALOG   = &H0
%MDM_BEARERMODE_ISDN     = &H1
%MDM_BEARERMODE_GSM      = &H2


'=========================================================================
'  PROTOCOL IDs
'=========================================================================
'
%MDM_PROTOCOLID_DEFAULT  = &H0
%MDM_PROTOCOLID_HDLCPPP  = &H1
%MDM_PROTOCOLID_V128     = &H2
%MDM_PROTOCOLID_X75      = &H3
%MDM_PROTOCOLID_V110     = &H4
%MDM_PROTOCOLID_V120     = &H5
%MDM_PROTOCOLID_AUTO     = &H6 ' Auto protocol detection.
%MDM_PROTOCOLID_ANALOG   = &H7 ' Applicable only to GSM
%MDM_PROTOCOLID_GPRS     = &H8
%MDM_PROTOCOLID_PIAFS    = &H9


'=========================================================================
'  HDLC PPP PROTOCOL INFORMATION
'=========================================================================
'
' Following are specific to the HDLC-PPP protocol.
' The shifts are w.r.t. the start of the PROTOCOLDATA field.

%MDM_SHIFT_HDLCPPP_SPEED    = &H0
%MDM_MASK_HDLCPPP_SPEED     = &H7  ' 3 bits

%MDM_HDLCPPP_SPEED_DEFAULT  = &H0
%MDM_HDLCPPP_SPEED_64K      = &H1
%MDM_HDLCPPP_SPEED_56K      = &H2


%MDM_SHIFT_HDLCPPP_AUTH     = &H3
%MDM_MASK_HDLCPPP_AUTH      = (7*8)  ' 3 bits

%MDM_HDLCPPP_AUTH_DEFAULT   = &H0
%MDM_HDLCPPP_AUTH_NONE      = &H1
%MDM_HDLCPPP_AUTH_PAP       = &H2
%MDM_HDLCPPP_AUTH_CHAP      = &H3
%MDM_HDLCPPP_AUTH_MSCHAP    = &H4


%MDM_SHIFT_HDLCPPP_ML       = &H6
%MDM_MASK_HDLCPPP_ML        = (3*64)  ' 2 bits

%MDM_HDLCPPP_ML_DEFAULT     = &H0
%MDM_HDLCPPP_ML_NONE        = &H1
%MDM_HDLCPPP_ML_2           = &H2

MACRO FUNCTION MDM_GEN_HDLCPPP_PROTOCOL_DATA(SPEED,auth,ml)
    MACROTEMP dwA, dwB, dwC
    LOCAL dwA, dwB, dwC AS DWORD
    dwA = (SPEED)
    SHIFT LEFT dwA, %MDM_SHIFT_HDLCPPP_SPEED
    dwA AND= %MDM_MASK_HDLCPPP_SPEED
    dwB = (auth)
    SHIFT LEFT dwB, %MDM_SHIFT_HDLCPPP_AUTH
    dwB AND= %MDM_MASK_HDLCPPP_AUTH
    dwC = (ml)
    SHIFT LEFT dwC, %MDM_SHIFT_HDLCPPP_ML
    dwC AND= %MDM_MASK_HDLCPPP_ML
END MACRO=dwA OR dwB OR dwC


MACRO MDM_PROTOCOL_HDLCPPP_64K=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_HDLCPPP,MDM_GEN_HDLCPPP_PROTOCOL_DATA(%MDM_HDLCPPP_SPEED_64K,%MDM_HDLCPPP_AUTH_DEFAULT,%MDM_HDLCPPP_ML_DEFAULT)

MACRO MDM_PROTOCOL_HDLCPPP_56K=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_HDLCPPP,MDM_GEN_HDLCPPP_PROTOCOL_DATA(%MDM_HDLCPPP_SPEED_56K,%MDM_HDLCPPP_AUTH_DEFAULT,%MDM_HDLCPPP_ML_DEFAULT))

MACRO MDM_PROTOCOL_HDLCPPP_112K=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_HDLCPPP,MDM_GEN_HDLCPPP_PROTOCOL_DATA(%MDM_HDLCPPP_SPEED_56K,%MDM_HDLCPPP_AUTH_DEFAULT,%MDM_HDLCPPP_ML_2))

MACRO MDM_PROTOCOL_HDLCPPP_112K_PAP=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_HDLCPPP,MDM_GEN_HDLCPPP_PROTOCOL_DATA(%MDM_HDLCPPP_SPEED_56K,%MDM_HDLCPPP_AUTH_PAP,%MDM_HDLCPPP_ML_2))

MACRO MDM_PROTOCOL_HDLCPPP_112K_CHAP=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_HDLCPPP,MDM_GEN_HDLCPPP_PROTOCOL_DATA(%MDM_HDLCPPP_SPEED_56K,%MDM_HDLCPPP_AUTH_CHAP,%MDM_HDLCPPP_ML_2))

MACRO MDM_PROTOCOL_HDLCPPP_112K_MSCHAP=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_HDLCPPP,MDM_GEN_HDLCPPP_PROTOCOL_DATA(%MDM_HDLCPPP_SPEED_56K,%MDM_HDLCPPP_AUTH_MSCHAP,%MDM_HDLCPPP_ML_2))

MACRO MDM_PROTOCOL_HDLCPPP_128K=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_HDLCPPP,MDM_GEN_HDLCPPP_PROTOCOL_DATA (%MDM_HDLCPPP_SPEED_64K,%MDM_HDLCPPP_AUTH_DEFAULT,%MDM_HDLCPPP_ML_2))

MACRO MDM_PROTOCOL_HDLCPPP_128K_PAP=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_HDLCPPP,MDM_GEN_HDLCPPP_PROTOCOL_DATA(%MDM_HDLCPPP_SPEED_64K,%MDM_HDLCPPP_AUTH_PAP,%MDM_HDLCPPP_ML_2))

MACRO MDM_PROTOCOL_HDLCPPP_128K_CHAP=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_HDLCPPP,MDM_GEN_HDLCPPP_PROTOCOL_DATA(%MDM_HDLCPPP_SPEED_64K,%MDM_HDLCPPP_AUTH_CHAP,%MDM_HDLCPPP_ML_2))

MACRO MDM_PROTOCOL_HDLCPPP_128K_MSCHAP=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_HDLCPPP,MDM_GEN_HDLCPPP_PROTOCOL_DATA(%MDM_HDLCPPP_SPEED_64K,%MDM_HDLCPPP_AUTH_MSCHAP,%MDM_HDLCPPP_ML_2))

'=========================================================================
'  V120 PROTOCOL INFORMATION
'
' The shifts are w.r.t. the start of the PROTOCOLDATA field.
'
'=========================================================================

%MDM_SHIFT_V120_SPEED    = &H0
%MDM_MASK_V120_SPEED     = &H7  ' 3 bits

%MDM_V120_SPEED_DEFAULT  = &H0
%MDM_V120_SPEED_64K      = &H1
%MDM_V120_SPEED_56K      = &H2


%MDM_SHIFT_V120_ML       = &H6
%MDM_MASK_V120_ML        = (3*64)  ' 2 bits

%MDM_V120_ML_DEFAULT     = &H0
%MDM_V120_ML_NONE        = &H1
%MDM_V120_ML_2           = &H2


MACRO FUNCTION MDM_GEN_V120_PROTOCOL_DATA(SPEED,ml)
    MACROTEMP dwA, dwB
    LOCAL dwA, dwB AS DWORD
    dwA = (SPEED)
    SHIFT LEFT dwA, %MDM_SHIFT_V120_SPEED
    dwA AND= %MDM_MASK_V120_SPEED
    dwB = (ml)
    SHIFT LEFT dwB, %MDM_SHIFT_V120_ML
    dwB AND= %MDM_MASK_V120_ML
END MACRO=dwA OR dwB


MACRO MDM_PROTOCOL_V120_64K=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_V120,MDM_GEN_V120_PROTOCOL_DATA(%MDM_V120_SPEED_64K,%MDM_V120_ML_NONE))

MACRO MDM_PROTOCOL_V120_56K=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_V120,MDM_GEN_V120_PROTOCOL_DATA(%MDM_V120_SPEED_56K,%MDM_V120_ML_NONE))

MACRO MDM_PROTOCOL_V120_112K=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_V120,MDM_GEN_V120_PROTOCOL_DATA(%MDM_V120_SPEED_56K,%MDM_V120_ML_2))

MACRO MDM_PROTOCOL_V120_128K=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_V120,MDM_GEN_V120_PROTOCOL_DATA(%MDM_V120_SPEED_64K,%MDM_V120_ML_2))


'=========================================================================
'  X75 PROTOCOL INFORMATION
'
' The shifts are w.r.t. the start of the PROTOCOLDATA field.
'
'=========================================================================


%MDM_SHIFT_X75_DATA    = &H0
%MDM_MASK_X75_DATA     = &H7  ' 3 bits

%MDM_X75_DATA_DEFAULT  = &H0
%MDM_X75_DATA_64K      = &H1
%MDM_X75_DATA_128K     = &H2
%MDM_X75_DATA_T_70     = &H3
%MDM_X75_DATA_BTX      = &H4

MACRO FUNCTION MDM_GEN_X75_PROTOCOL_DATA(ndata)
    MACROTEMP dwd
    LOCAL dwd AS DWORD
    dwd = (ndata)
    SHIFT LEFT dwd, %MDM_SHIFT_X75_DATA
    dwd AND= %MDM_MASK_X75_DATA
END MACRO=dwd

MACRO MDM_PROTOCOL_X75_64K=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_X75,MDM_GEN_X75_PROTOCOL_DATA(%MDM_X75_DATA_64K))

MACRO MDM_PROTOCOL_X75_128K=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_X75,MDM_GEN_X75_PROTOCOL_DATA(%MDM_X75_DATA_128K))

MACRO MDM_PROTOCOL_X75_T_70=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_X75,MDM_GEN_X75_PROTOCOL_DATA(%MDM_X75_DATA_T_70))

MACRO MDM_PROTOCOL_X75_BTX=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_X75,MDM_GEN_X75_PROTOCOL_DATA(%MDM_X75_DATA_BTX))


'=========================================================================
'  V110 PROTOCOL INFORMATION
'
' The shifts are w.r.t. the start of the PROTOCOLDATA field.
'
'=========================================================================


%MDM_SHIFT_V110_SPEED   = &H0
%MDM_MASK_V110_SPEED    = &Hf  ' 4 bits

%MDM_V110_SPEED_DEFAULT = &H0
%MDM_V110_SPEED_1DOT2K  = &H1
%MDM_V110_SPEED_2DOT4K  = &H2
%MDM_V110_SPEED_4DOT8K  = &H3
%MDM_V110_SPEED_9DOT6K  = &H4
%MDM_V110_SPEED_12DOT0K = &H5
%MDM_V110_SPEED_14DOT4K = &H6
%MDM_V110_SPEED_19DOT2K = &H7
%MDM_V110_SPEED_28DOT8K = &H8
%MDM_V110_SPEED_38DOT4K = &H9
%MDM_V110_SPEED_57DOT6K = &HA

MACRO FUNCTION MDM_GEN_V110_PROTOCOL_DATA(ndata)
    MACROTEMP dwd
    LOCAL dwd AS DWORD
    dwd = ndata
    SHIFT LEFT dwd, %MDM_SHIFT_V110_SPEED
    dwd AND= %MDM_MASK_V110_SPEED
END MACRO=dwd

MACRO MDM_PROTOCOL_V110_1DOT2K=MDM_GET_PROTOCOLINFO(%MDM_PROTOCOLID_V110,MDM_GEN_V110_PROTOCOL_DATA(_%MDM_V110_SPEED_1DOT2K))

MACRO MDM_PROTOCOL_V110_2DOT4K=MDM_GET_PROTOCOLINFO(%MDM_PROTOCOLID_V110,MDM_GEN_V110_PROTOCOL_DATA(_%MDM_V110_SPEED_2DOT4K))

MACRO MDM_PROTOCOL_V110_4DOT8K=MDM_GET_PROTOCOLINFO(%MDM_PROTOCOLID_V110,MDM_GEN_V110_PROTOCOL_DATA(_%MDM_V110_SPEED_4DOT8K))

MACRO MDM_PROTOCOL_V110_9DOT6K=MDM_GET_PROTOCOLINFO(%MDM_PROTOCOLID_V110,MDM_GEN_V110_PROTOCOL_DATA(_%MDM_V110_SPEED_9DOT6K))

MACRO MDM_PROTOCOL_V110_12DOT0K=MDM_GET_PROTOCOLINFO(%MDM_PROTOCOLID_V110,MDM_GEN_V110_PROTOCOL_DATA(_%MDM_V110_SPEED_12DOT0K))

MACRO MDM_PROTOCOL_V110_14DOT4K=MDM_GET_PROTOCOLINFO(%MDM_PROTOCOLID_V110,MDM_GEN_V110_PROTOCOL_DATA(_%MDM_V110_SPEED_14DOT4K))

MACRO MDM_PROTOCOL_V110_19DOT2K=MDM_GET_PROTOCOLINFO(%MDM_PROTOCOLID_V110,MDM_GEN_V110_PROTOCOL_DATA(_%MDM_V110_SPEED_19DOT2K))

MACRO MDM_PROTOCOL_V110_28DOT8K=MDM_GET_PROTOCOLINFO(%MDM_PROTOCOLID_V110,MDM_GEN_V110_PROTOCOL_DATA(_%MDM_V110_SPEED_28DOT8K))

MACRO MDM_PROTOCOL_V110_38DOT4K=MDM_GET_PROTOCOLINFO(%MDM_PROTOCOLID_V110,MDM_GEN_V110_PROTOCOL_DATA(_%MDM_V110_SPEED_38DOT4K))

MACRO MDM_PROTOCOL_V110_57DOT6K=MDM_GET_PROTOCOLINFO(%MDM_PROTOCOLID_V110,MDM_GEN_V110_PROTOCOL_DATA(_%MDM_V110_SPEED_57DOT6K))

'=========================================================================
'  AUTO PROTOCOL INFORMATION (ie, when the protocol is detected automatically)
'
' The shifts are w.r.t. the start of the PROTOCOLDATA field.
'
'=========================================================================
'
' Following are specific to the AUTO-protocol
'

%MDM_SHIFT_AUTO_SPEED    = &H0
%MDM_MASK_AUTO_SPEED     = &H7  ' 3 bits
%MDM_AUTO_SPEED_DEFAULT  = &H0

%MDM_SHIFT_AUTO_ML       = &H6
%MDM_MASK_AUTO_ML        = (3*64)  ' 2 bits
%MDM_AUTO_ML_DEFAULT     = &H0
%MDM_AUTO_ML_NONE        = &H1
%MDM_AUTO_ML_2           = &H2

MACRO FUNCTION MDM_GEN_AUTO_PROTOCOL_DATA(SPEED,ml)
    MACROTEMP dwA, dwB
    LOCAL dwA, dwB AS DWORD
    dwA = SPEED
    SHIFT LEFT dwA, %MDM_SHIFT_AUTO_SPEED
    dwA AND= %MDM_MASK_AUTO_SPEED
    dwB = ml
    SHIFT LEFT dwB, %MDM_SHIFT_AUTO_ML
    dwB AND= %MDM_MASK_AUTO_ML
END MACRO=dwA OR dwB


MACRO MDM_PROTOCOL_AUTO_1CH=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_AUTO,MDM_GEN_AUTO_PROTOCOL_DATA(%MDM_AUTO_SPEED_DEFAULT,%MDM_AUTO_ML_NONE))

MACRO MDM_PROTOCOL_AUTO_2CH=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_AUTO,MDM_GEN_AUTO_PROTOCOL_DATA(%MDM_AUTO_SPEED_DEFAULT,%MDM_AUTO_ML_2))

'=========================================================================
'  ANALOG PROTOCOL INFORMATION (Applicable only to GSM)
'=========================================================================
'
' Following are specific to GSM Analog protocol
'

%MDM_ANALOG_RLP_ON       = &H0
%MDM_ANALOG_RLP_OFF      = &H1
%MDM_ANALOG_V34          = &H2

MACRO MDM_GEN_ANALOG_PROTOCOL_DATA(rlp)=(rlp)


MACRO MDM_PROTOCOL_ANALOG_RLP=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_ANALOG,MDM_GEN_ANALOG_PROTOCOL_DATA(%MDM_ANALOG_RLP_ON))

MACRO MDM_PROTOCOL_ANALOG_NRLP=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_ANALOG,MDM_GEN_ANALOG_PROTOCOL_DATA(%MDM_ANALOG_RLP_OFF))

'
'  v34 analog for isdn
'
MACRO MDM_PROTOCOL_ANALOG_V34=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_ANALOG,MDM_GEN_ANALOG_PROTOCOL_DATA(%MDM_ANALOG_V34))


'=========================================================================
'  GPRS PROTOCOL INFORMATION (Applicable only to GSM)
'=========================================================================
'
' Following are specific to GPRS protocol
'

MACRO MDM_PROTOCOL_GPRS=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_GPRS,0)


'=========================================================================
'  PIAFS PROTOCOL INFORMATION
'=========================================================================
'
' Following are specific to PIAFS protocol
'

%MDM_PIAFS_INCOMING          = 0
%MDM_PIAFS_OUTGOING          = 1

MACRO MDM_PROTOCOL_PIAFS_INCOMING=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_PIAFS,%MDM_PIAFS_INCOMING)

MACRO MDM_PROTOCOL_PIAFS_OUTGOING=MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_PIAFS,%MDM_PIAFS_OUTGOING)
