'------------------------------------------------------------------------------
'
'  WinSmCrd.inc
'    Smart Card class/port IOCTL codes. This file is required for all code
'    user mode and kernel mode, using Smart Card IOCTL's, defines,
'    data structures
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from WinSmCrd.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%NTDDSCRD_H2 = 1


#IF NOT %DEF(%DEVICE_TYPE_SMARTCARD)
%FILE_DEVICE_SMARTCARD         = &H00000031
#ELSE
#IF &H00000031 <> %FILE_DEVICE_SMARTCARD
'#error "Incorrect Smart Card Device Definition"
#ENDIF
#ENDIF


'
' Various constants
'

%SCARD_ATR_LENGTH = 33  ' ISO 7816-3 spec.

'
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
'  Protocol Flag definitions
'

%SCARD_PROTOCOL_UNDEFINED = &H00000000  ' There is no active protocol.
%SCARD_PROTOCOL_T0        = &H00000001  ' T=0 is the active protocol.
%SCARD_PROTOCOL_T1        = &H00000002  ' T=1 is the active protocol.
%SCARD_PROTOCOL_RAW       = &H00010000  ' Raw is the active protocol.
'
' This is the mask of ISO defined transmission protocols
'
%SCARD_PROTOCOL_Tx         = (%SCARD_PROTOCOL_T0 OR %SCARD_PROTOCOL_T1)
'
' Use the default transmission parameters / card clock freq.
'
%SCARD_PROTOCOL_DEFAULT    = &H80000000???
'
' Use optimal transmission parameters / card clock freq.
' Since using the optimal parameters is the default case no bit is defined to be 1
'
%SCARD_PROTOCOL_OPTIMAL    = &H00000000


'
' Ioctl parameters 1 for IOCTL_SMARTCARD_POWER
'
%SCARD_POWER_DOWN = 0          ' Power down the card.
%SCARD_COLD_RESET = 1          ' Cycle power and reset the card.
%SCARD_WARM_RESET = 2          ' Force a reset on the card.

'
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
'  Reader Action IOCTLs
'

MACRO SCARD_CTL_CODE(CODE)=CTL_CODE(%FILE_DEVICE_SMARTCARD,(CODE),%METHOD_BUFFERED,%FILE_ANY_ACCESS)

MACRO IOCTL_SMARTCARD_POWER          = SCARD_CTL_CODE( 1)
MACRO IOCTL_SMARTCARD_GET_ATTRIBUTE  = SCARD_CTL_CODE( 2)
MACRO IOCTL_SMARTCARD_SET_ATTRIBUTE  = SCARD_CTL_CODE( 3)
MACRO IOCTL_SMARTCARD_CONFISCATE     = SCARD_CTL_CODE( 4)
MACRO IOCTL_SMARTCARD_TRANSMIT       = SCARD_CTL_CODE( 5)
MACRO IOCTL_SMARTCARD_EJECT          = SCARD_CTL_CODE( 6)
MACRO IOCTL_SMARTCARD_SWALLOW        = SCARD_CTL_CODE( 7)
' macro IOCTL_SMARTCARD_READ           = SCARD_CTL_CODE( 8) obsolete
' macro IOCTL_SMARTCARD_WRITE          = SCARD_CTL_CODE( 9) obsolete
MACRO IOCTL_SMARTCARD_IS_PRESENT     = SCARD_CTL_CODE(10)
MACRO IOCTL_SMARTCARD_IS_ABSENT      = SCARD_CTL_CODE(11)
MACRO IOCTL_SMARTCARD_SET_PROTOCOL   = SCARD_CTL_CODE(12)
MACRO IOCTL_SMARTCARD_GET_STATE      = SCARD_CTL_CODE(14)
MACRO IOCTL_SMARTCARD_GET_LAST_ERROR = SCARD_CTL_CODE(15)
MACRO IOCTL_SMARTCARD_GET_PERF_CNTR  = SCARD_CTL_CODE(16)


'
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
' Tags for requesting card and reader attributes
'

%MAXIMUM_ATTR_STRING_LENGTH = 32   ' Nothing bigger than this from getAttr
%MAXIMUM_SMARTCARD_READERS  = 10   ' Limit the readers on the system

MACRO SCARD_ATTR_VALUE(sClass, Tag)=LO(DWORD,((sClass)*65536 OR (Tag)))

%SCARD_CLASS_VENDOR_INFO    = 1   ' Vendor information definitions
%SCARD_CLASS_COMMUNICATIONS = 2   ' Communication definitions
%SCARD_CLASS_PROTOCOL       = 3   ' Protocol definitions
%SCARD_CLASS_POWER_MGMT     = 4   ' Power Management definitions
%SCARD_CLASS_SECURITY       = 5   ' Security Assurance definitions
%SCARD_CLASS_MECHANICAL     = 6   ' Mechanical characteristic definitions
%SCARD_CLASS_VENDOR_DEFINED = 7   ' Vendor specific definitions
%SCARD_CLASS_IFD_PROTOCOL   = 8   ' Interface Device Protocol options
%SCARD_CLASS_ICC_STATE      = 9   ' ICC State specific definitions
%SCARD_CLASS_PERF     = &H7ffe   ' performace counters
%SCARD_CLASS_SYSTEM   = &H7fff   ' System-specific definitions

MACRO SCARD_ATTR_VENDOR_NAME = SCARD_ATTR_VALUE(%SCARD_CLASS_VENDOR_INFO, &H0100)
MACRO SCARD_ATTR_VENDOR_IFD_TYPE = SCARD_ATTR_VALUE(%SCARD_CLASS_VENDOR_INFO, &H0101)
MACRO SCARD_ATTR_VENDOR_IFD_VERSION = SCARD_ATTR_VALUE(%SCARD_CLASS_VENDOR_INFO, &H0102)
MACRO SCARD_ATTR_VENDOR_IFD_SERIAL_NO = SCARD_ATTR_VALUE(%SCARD_CLASS_VENDOR_INFO, &H0103)
MACRO SCARD_ATTR_CHANNEL_ID = SCARD_ATTR_VALUE(%SCARD_CLASS_COMMUNICATIONS, &H0110)
MACRO SCARD_ATTR_PROTOCOL_TYPES = SCARD_ATTR_VALUE(%SCARD_CLASS_PROTOCOL, &H0120)
' macro SCARD_ATTR_ASYNC_PROTOCOL_TYPES = SCARD_ATTR_VALUE(%SCARD_CLASS_PROTOCOL, &H0120)
MACRO SCARD_ATTR_DEFAULT_CLK = SCARD_ATTR_VALUE(%SCARD_CLASS_PROTOCOL, &H0121)
MACRO SCARD_ATTR_MAX_CLK = SCARD_ATTR_VALUE(%SCARD_CLASS_PROTOCOL, &H0122)
MACRO SCARD_ATTR_DEFAULT_DATA_RATE = SCARD_ATTR_VALUE(%SCARD_CLASS_PROTOCOL, &H0123)
MACRO SCARD_ATTR_MAX_DATA_RATE = SCARD_ATTR_VALUE(%SCARD_CLASS_PROTOCOL, &H0124)
MACRO SCARD_ATTR_MAX_IFSD = SCARD_ATTR_VALUE(%SCARD_CLASS_PROTOCOL, &H0125)
' macro SCARD_ATTR_SYNC_PROTOCOL_TYPES = SCARD_ATTR_VALUE(%SCARD_CLASS_PROTOCOL, &H0126)
MACRO SCARD_ATTR_POWER_MGMT_SUPPORT = SCARD_ATTR_VALUE(%SCARD_CLASS_POWER_MGMT, &H0131)
MACRO SCARD_ATTR_USER_TO_CARD_AUTH_DEVICE = SCARD_ATTR_VALUE(%SCARD_CLASS_SECURITY, &H0140)
MACRO SCARD_ATTR_USER_AUTH_INPUT_DEVICE = SCARD_ATTR_VALUE(%SCARD_CLASS_SECURITY, &H0142)
MACRO SCARD_ATTR_CHARACTERISTICS = SCARD_ATTR_VALUE(%SCARD_CLASS_MECHANICAL, &H0150)

MACRO SCARD_ATTR_CURRENT_PROTOCOL_TYPE = SCARD_ATTR_VALUE(%SCARD_CLASS_IFD_PROTOCOL, &H0201)
MACRO SCARD_ATTR_CURRENT_CLK = SCARD_ATTR_VALUE(%SCARD_CLASS_IFD_PROTOCOL, &H0202)
MACRO SCARD_ATTR_CURRENT_F = SCARD_ATTR_VALUE(%SCARD_CLASS_IFD_PROTOCOL, &H0203)
MACRO SCARD_ATTR_CURRENT_D = SCARD_ATTR_VALUE(%SCARD_CLASS_IFD_PROTOCOL, &H0204)
MACRO SCARD_ATTR_CURRENT_N = SCARD_ATTR_VALUE(%SCARD_CLASS_IFD_PROTOCOL, &H0205)
MACRO SCARD_ATTR_CURRENT_W = SCARD_ATTR_VALUE(%SCARD_CLASS_IFD_PROTOCOL, &H0206)
MACRO SCARD_ATTR_CURRENT_IFSC = SCARD_ATTR_VALUE(%SCARD_CLASS_IFD_PROTOCOL, &H0207)
MACRO SCARD_ATTR_CURRENT_IFSD = SCARD_ATTR_VALUE(%SCARD_CLASS_IFD_PROTOCOL, &H0208)
MACRO SCARD_ATTR_CURRENT_BWT = SCARD_ATTR_VALUE(%SCARD_CLASS_IFD_PROTOCOL, &H0209)
MACRO SCARD_ATTR_CURRENT_CWT = SCARD_ATTR_VALUE(%SCARD_CLASS_IFD_PROTOCOL, &H020a)
MACRO SCARD_ATTR_CURRENT_EBC_ENCODING = SCARD_ATTR_VALUE(%SCARD_CLASS_IFD_PROTOCOL, &H020b)
MACRO SCARD_ATTR_EXTENDED_BWT = SCARD_ATTR_VALUE(%SCARD_CLASS_IFD_PROTOCOL, &H020c)

MACRO SCARD_ATTR_ICC_PRESENCE = SCARD_ATTR_VALUE(%SCARD_CLASS_ICC_STATE, &H0300)
MACRO SCARD_ATTR_ICC_INTERFACE_STATUS = SCARD_ATTR_VALUE(%SCARD_CLASS_ICC_STATE, &H0301)
MACRO SCARD_ATTR_CURRENT_IO_STATE = SCARD_ATTR_VALUE(%SCARD_CLASS_ICC_STATE, &H0302)
MACRO SCARD_ATTR_ATR_STRING = SCARD_ATTR_VALUE(%SCARD_CLASS_ICC_STATE, &H0303)
MACRO SCARD_ATTR_ICC_TYPE_PER_ATR = SCARD_ATTR_VALUE(%SCARD_CLASS_ICC_STATE, &H0304)

MACRO SCARD_ATTR_ESC_RESET = SCARD_ATTR_VALUE(%SCARD_CLASS_VENDOR_DEFINED, &HA000)
MACRO SCARD_ATTR_ESC_CANCEL = SCARD_ATTR_VALUE(%SCARD_CLASS_VENDOR_DEFINED, &HA003)
MACRO SCARD_ATTR_ESC_AUTHREQUEST = SCARD_ATTR_VALUE(%SCARD_CLASS_VENDOR_DEFINED, &HA005)
MACRO SCARD_ATTR_MAXINPUT = SCARD_ATTR_VALUE(%SCARD_CLASS_VENDOR_DEFINED, &HA007)

MACRO SCARD_ATTR_DEVICE_UNIT = SCARD_ATTR_VALUE(%SCARD_CLASS_SYSTEM, &H0001)
MACRO SCARD_ATTR_DEVICE_IN_USE = SCARD_ATTR_VALUE(%SCARD_CLASS_SYSTEM, &H0002)
MACRO SCARD_ATTR_DEVICE_FRIENDLY_NAME_A = SCARD_ATTR_VALUE(%SCARD_CLASS_SYSTEM, &H0003)
MACRO SCARD_ATTR_DEVICE_SYSTEM_NAME_A = SCARD_ATTR_VALUE(%SCARD_CLASS_SYSTEM, &H0004)
MACRO SCARD_ATTR_DEVICE_FRIENDLY_NAME_W = SCARD_ATTR_VALUE(%SCARD_CLASS_SYSTEM, &H0005)
MACRO SCARD_ATTR_DEVICE_SYSTEM_NAME_W = SCARD_ATTR_VALUE(%SCARD_CLASS_SYSTEM, &H0006)
MACRO SCARD_ATTR_SUPRESS_T1_IFS_REQUEST = SCARD_ATTR_VALUE(%SCARD_CLASS_SYSTEM, &H0007)

MACRO SCARD_PERF_NUM_TRANSMISSIONS = SCARD_ATTR_VALUE(%SCARD_CLASS_PERF, &H0001)
MACRO SCARD_PERF_BYTES_TRANSMITTED = SCARD_ATTR_VALUE(%SCARD_CLASS_PERF, &H0002)
MACRO SCARD_PERF_TRANSMISSION_TIME = SCARD_ATTR_VALUE(%SCARD_CLASS_PERF, &H0003)

#IF %DEF(%UNICODE)
MACRO SCARD_ATTR_DEVICE_FRIENDLY_NAME=SCARD_ATTR_DEVICE_FRIENDLY_NAME_W
MACRO SCARD_ATTR_DEVICE_SYSTEM_NAME=SCARD_ATTR_DEVICE_SYSTEM_NAME_W
#ELSE
MACRO SCARD_ATTR_DEVICE_FRIENDLY_NAME=SCARD_ATTR_DEVICE_FRIENDLY_NAME_A
MACRO SCARD_ATTR_DEVICE_SYSTEM_NAME=SCARD_ATTR_DEVICE_SYSTEM_NAME_A
#ENDIF


'
' T=0 Protocol Defines
'

%SCARD_T0_HEADER_LENGTH = 7
%SCARD_T0_CMD_LENGTH = 5


'
' T=1 Protocol Defines
'

%SCARD_T1_PROLOGUE_LENGTH = 3
%SCARD_T1_EPILOGUE_LENGTH = 2
%SCARD_T1_MAX_IFS = 254


'
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
'  Reader states
'

%SCARD_UNKNOWN    = 0   ' This value implies the driver is unaware
                        ' of the current state of the reader.
%SCARD_ABSENT     = 1   ' This value implies there is no card in
                        ' the reader.
%SCARD_PRESENT    = 2   ' This value implies there is a card is
                        ' present in the reader, but that it has
                        ' not been moved into position for use.
%SCARD_SWALLOWED  = 3   ' This value implies there is a card in the
                        ' reader in position for use.  The card is
                        ' not powered.
%SCARD_POWERED    = 4   ' This value implies there is power is
                        ' being provided to the card, but the
                        ' Reader Driver is unaware of the mode of
                        ' the card.
%SCARD_NEGOTIABLE = 5   ' This value implies the card has been
                        ' reset and is awaiting PTS negotiation.
%SCARD_SPECIFIC   = 6   ' This value implies the card has been
                        ' reset and specific communication
                        ' protocols have been established.

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
'  I/O Services
'
'      The following services provide access to the I/O capabilities of the
'      reader drivers.  Services of the Smart Card are requested by placing the
'      following structure into the protocol buffer:
'


TYPE SCARD_IO_REQUEST
    dwProtocol  AS DWORD   ' Protocol identifier
    cbPciLength AS DWORD   ' Protocol Control Information Length
END TYPE


'
' T=0 protocol services.
'

TYPE SCARD_T0_COMMAND
    bCla AS BYTE   ' The instruction class
    bIns AS BYTE   ' The instruction code within the instruction class
    bP1  AS BYTE
    bP2  AS BYTE   ' Parameters to the instruction
    bP3  AS BYTE   ' Size of I/O Transfer
END TYPE

UNION SCARD_T0_REQUEST_union
    CmdBytes     AS SCARD_T0_COMMAND
    rgbHeader(4) AS BYTE
END UNION

TYPE SCARD_T0_REQUEST
    ioRequest AS SCARD_IO_REQUEST
    bSw1      AS BYTE
    bSw2      AS BYTE    ' Return codes from the instruction
    SCARD_T0_REQUEST
END TYPE


'
'  T=1 Protocol Services
'

TYPE SCARD_T1_REQUEST
    ioRequest AS SCARD_IO_REQUEST
END TYPE


'
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
'  Driver attribute flags
'

%SCARD_READER_SWALLOWS      = &H00000001  ' Reader has a card swallowing
                                          ' mechanism.
%SCARD_READER_EJECTS        = &H00000002  ' Reader has a card ejection
                                          ' mechanism.
%SCARD_READER_CONFISCATES   = &H00000004  ' Reader has a card capture
                                          ' mechanism.

'
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
' Type of reader
'
%SCARD_READER_TYPE_SERIAL   = &H01
%SCARD_READER_TYPE_PARALELL = &H02
%SCARD_READER_TYPE_KEYBOARD = &H04
%SCARD_READER_TYPE_SCSI     = &H08
%SCARD_READER_TYPE_IDE      = &H10
%SCARD_READER_TYPE_USB      = &H20
%SCARD_READER_TYPE_PCMCIA   = &H40
%SCARD_READER_TYPE_VENDOR   = &HF0?
