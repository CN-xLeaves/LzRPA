'------------------------------------------------------------------------------
'
'  RasError.inc -- RAS-specific error codes
'
'  Copyright (c) 2009-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from RasError.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%RASERROR_H = 1

#INCLUDE "SdkDdkVer.inc"

%RASBASE = 600
%SUCCESS = 0


%PENDING                              = (%RASBASE+0)
'
' An operation is pending.
'

%ERROR_INVALID_PORT_HANDLE            = (%RASBASE+1)
'
' An invalid port handle was detected.
'

%ERROR_PORT_ALREADY_OPEN              = (%RASBASE+2)
'
' The specified port is already open.
'

%ERROR_BUFFER_TOO_SMALL               = (%RASBASE+3)
'
' The caller's buffer is too small.
'

%ERROR_WRONG_INFO_SPECIFIED           = (%RASBASE+4)
'
' Incorrect information was specified.
'

#IF (%WINVER < &H600)
'
' The port information cannot be set.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_CANNOT_SET_PORT_INFO           = (%RASBASE+5)
'
'
'
#ENDIF

%ERROR_PORT_NOT_CONNECTED             = (%RASBASE+6)
'
' The specified port is not connected.
'

#IF (%WINVER < &H600)
'
' An invalid event was detected.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_EVENT_INVALID                  = (%RASBASE+7)
'
'
'
#ENDIF

%ERROR_DEVICE_DOES_NOT_EXIST          = (%RASBASE+8)
'
' A device was specified that does not exist.
'

%ERROR_DEVICETYPE_DOES_NOT_EXIST      = (%RASBASE+9)
'
' A device type was specified that does not exist.
'

%ERROR_BUFFER_INVALID                 = (%RASBASE+10)
'
' An invalid buffer was specified.
'

#IF (%WINVER < &H600)
'
' A route was specified that is not available.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_ROUTE_NOT_AVAILABLE            = (%RASBASE+11)
'
'
'
#ENDIF

%ERROR_ROUTE_NOT_ALLOCATED            = (%RASBASE+12)
'
' A route was specified that is not allocated.
'

#IF (%WINVER < &H600)
'
' An invalid compression was specified.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_INVALID_COMPRESSION_SPECIFIED  = (%RASBASE+13)
'
'
'

'
' There were insufficient buffers available.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_OUT_OF_BUFFERS                 = (%RASBASE+14)
'
'
'
#ENDIF

%ERROR_PORT_NOT_FOUND                 = (%RASBASE+15)
'
' The specified port was not found.
'

%ERROR_ASYNC_REQUEST_PENDING          = (%RASBASE+16)
'
' An asynchronous request is pending.
'

%ERROR_ALREADY_DISCONNECTING          = (%RASBASE+17)
'
' The modem (or other connecting device) is already disconnecting.
'

%ERROR_PORT_NOT_OPEN                  = (%RASBASE+18)
'
' The specified port is not open.
'

%ERROR_PORT_DISCONNECTED              = (%RASBASE+19)
'
' A connection to the remote computer could not be established, so the port used for this connection was closed.
'

#IF (%WINVER < &H600)
'
'  No endpoints could be determined.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_NO_ENDPOINTS                   = (%RASBASE+20)
'
'
'
#ENDIF

%ERROR_CANNOT_OPEN_PHONEBOOK          = (%RASBASE+21)
'
' The system could not open the phone book file.
'

%ERROR_CANNOT_LOAD_PHONEBOOK          = (%RASBASE+22)
'
' The system could not load the phone book file.
'

%ERROR_CANNOT_FIND_PHONEBOOK_ENTRY    = (%RASBASE+23)
'
' The system could not find the phone book entry for this connection.
'

%ERROR_CANNOT_WRITE_PHONEBOOK         = (%RASBASE+24)
'
' The system could not update the phone book file.
'

%ERROR_CORRUPT_PHONEBOOK              = (%RASBASE+25)
'
' The system found invalid information in the phone book file.
'

#IF (%WINVER < &H600)
'
' A string could not be loaded.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_CANNOT_LOAD_STRING             = (%RASBASE+26)
'
'
'
#ENDIF

%ERROR_KEY_NOT_FOUND                  = (%RASBASE+27)
'
' A key could not be found.
'

%ERROR_DISCONNECTION                  = (%RASBASE+28)
'
' The connection was terminated by the remote computer before it could be completed.
'

%ERROR_REMOTE_DISCONNECTION           = (%RASBASE+29)
'
' The connection was closed by the remote computer.
'

%ERROR_HARDWARE_FAILURE               = (%RASBASE+30)
'
' The modem (or other connecting device) was disconnected due to hardware failure.
'

%ERROR_USER_DISCONNECTION             = (%RASBASE+31)
'
' The user disconnected the modem (or other connecting device).
'

%ERROR_INVALID_SIZE                   = (%RASBASE+32)
'
' An incorrect structure size was detected.
'

%ERROR_PORT_NOT_AVAILABLE             = (%RASBASE+33)
'
' The modem (or other connecting device) is already in use or is not configured properly.
'

#IF (%WINVER < &H600)
'
' Your computer could not be registered on the remote network.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_CANNOT_PROJECT_CLIENT          = (%RASBASE+34)
'
'
'
#ENDIF

%ERROR_UNKNOWN                        = (%RASBASE+35)
'
' There was an unknown error.
'

%ERROR_WRONG_DEVICE_ATTACHED          = (%RASBASE+36)
'
' The device attached to the port is not the one expected.
'

#IF (%WINVER < &H600)
'
' A string was detected that could not be converted.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_BAD_STRING                     = (%RASBASE+37)
'
'
'
#ENDIF

%ERROR_REQUEST_TIMEOUT                = (%RASBASE+38)
'
' The remote server is not responding in a timely fashion.
'

#IF (%WINVER < &H600)
'
' No asynchronous net is available.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_CANNOT_GET_LANA                = (%RASBASE+39)
'
'
'

'
' An error has occurred involving NetBIOS.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_NETBIOS_ERROR                  = (%RASBASE+40)
'
'
'

'
' The server cannot allocate NetBIOS resources needed to support the client.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_SERVER_OUT_OF_RESOURCES        = (%RASBASE+41)
'
'
'

'
' One of your computer's NetBIOS names is already registered on the remote network.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_NAME_EXISTS_ON_NET             = (%RASBASE+42)
'
'
'

'
' A network adapter at the server failed.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_SERVER_GENERAL_NET_FAILURE     = (%RASBASE+43)
'
'
'

'
' You will not receive network message popups.
'
' This error was obsoleted in the Windows Vista release.
'
%WARNING_MSG_ALIAS_NOT_ADDED          = (%RASBASE+44)
'
'
'
#ENDIF

%ERROR_AUTH_INTERNAL                  = (%RASBASE+45)
'
' There was an internal authentication error.
'

%ERROR_RESTRICTED_LOGON_HOURS         = (%RASBASE+46)
'
' The account is not permitted to log on at this time of day.
'

%ERROR_ACCT_DISABLED                  = (%RASBASE+47)
'
' The account is disabled.
'

%ERROR_PASSWD_EXPIRED                 = (%RASBASE+48)
'
' The password for this account has expired.
'

%ERROR_NO_DIALIN_PERMISSION           = (%RASBASE+49)
'
' The account does not have permission to dial in.
'

#IF (%WINVER < &H600)
'
' The remote access server is not responding.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_SERVER_NOT_RESPONDING          = (%RASBASE+50)
'
'
'
#ENDIF

%ERROR_FROM_DEVICE                    = (%RASBASE+51)
'
' The modem (or other connecting device) has reported an error.
'

%ERROR_UNRECOGNIZED_RESPONSE          = (%RASBASE+52)
'
' There was an unrecognized response from the modem (or other connecting device).
'

%ERROR_MACRO_NOT_FOUND                = (%RASBASE+53)
'
' A macro required by the modem (or other connecting device) was not found in the device.INF file.
'

%ERROR_MACRO_NOT_DEFINED              = (%RASBASE+54)
'
' A command or response in the device.INF file section refers to an undefined macro.
'

%ERROR_MESSAGE_MACRO_NOT_FOUND        = (%RASBASE+55)
'
' The <message> macro was not found in the device.INF file section.
'

%ERROR_DEFAULTOFF_MACRO_NOT_FOUND     = (%RASBASE+56)
'
' The <defaultoff> macro in the device.INF file section contains an undefined
' macro.
'

%ERROR_FILE_COULD_NOT_BE_OPENED       = (%RASBASE+57)
'
' The device.INF file could not be opened.
'

%ERROR_DEVICENAME_TOO_LONG            = (%RASBASE+58)
'
' The device name in the device.INF or media.INI file is too long.
'

%ERROR_DEVICENAME_NOT_FOUND           = (%RASBASE+59)
'
' The media.INI file refers to an unknown device name.
'

%ERROR_NO_RESPONSES                   = (%RASBASE+60)
'
' The device.INF file contains no responses for the command.
'

%ERROR_NO_COMMAND_FOUND               = (%RASBASE+61)
'
' The device.INF file is missing a command.
'

%ERROR_WRONG_KEY_SPECIFIED            = (%RASBASE+62)
'
' There was an attempt to set a macro not listed in device.INF file section.
'

%ERROR_UNKNOWN_DEVICE_TYPE            = (%RASBASE+63)
'
' The media.INI file refers to an unknown device type.
'

%ERROR_ALLOCATING_MEMORY              = (%RASBASE+64)
'
' The system has run out of memory.
'

%ERROR_PORT_NOT_CONFIGURED            = (%RASBASE+65)
'
' The modem (or other connecting device) is not properly configured.
'

%ERROR_DEVICE_NOT_READY               = (%RASBASE+66)
'
' The modem (or other connecting device) is not functioning.
'

%ERROR_READING_INI_FILE               = (%RASBASE+67)
'
' The system was unable to read the media.INI file.
'

%ERROR_NO_CONNECTION                  = (%RASBASE+68)
'
' The connection was terminated.
'

%ERROR_BAD_USAGE_IN_INI_FILE          = (%RASBASE+69)
'
' The usage parameter in the media.INI file is invalid.
'

%ERROR_READING_SECTIONNAME            = (%RASBASE+70)
'
' The system was unable to read the section name from the media.INI file.
'

%ERROR_READING_DEVICETYPE             = (%RASBASE+71)
'
' The system was unable to read the device type from the media.INI file.
'

%ERROR_READING_DEVICENAME             = (%RASBASE+72)
'
' The system was unable to read the device name from the media.INI file.
'

%ERROR_READING_USAGE                  = (%RASBASE+73)
'
' The system was unable to read the usage from the media.INI file.
'

#IF (%WINVER < &H600)
'
' The system was unable to read the maximum connection BPS rate from the media.INI file.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_READING_MAXCONNECTBPS          = (%RASBASE+74)
'
'
'

'
' The system was unable to read the maximum carrier connection speed from the media.INI file.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_READING_MAXCARRIERBPS          = (%RASBASE+75)
'
'
'
#ENDIF

%ERROR_LINE_BUSY                      = (%RASBASE+76)
'
' The phone line is busy.
'

%ERROR_VOICE_ANSWER                   = (%RASBASE+77)
'
' A person answered instead of a modem (or other connecting device).
'

%ERROR_NO_ANSWER                      = (%RASBASE+78)
'
' The remote computer did not respond. To make sure that the server can be reached, ping the remote computer.

'

%ERROR_NO_CARRIER                     = (%RASBASE+79)
'
' The system could not detect the carrier.
'

%ERROR_NO_DIALTONE                    = (%RASBASE+80)
'
' There was no dial tone.
'

#IF (%WINVER < &H600)
'
' The modem (or other connecting device) reported a general error.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_IN_COMMAND                     = (%RASBASE+81)
'
'
'

'
' There was an error in writing the section name.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_WRITING_SECTIONNAME            = (%RASBASE+82)
'
'
'

'
' There was an error in writing the device type.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_WRITING_DEVICETYPE             = (%RASBASE+83)
'
'
'

'
' There was an error in writing the device name.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_WRITING_DEVICENAME             = (%RASBASE+84)
'
'
'

'
' There was an error in writing the maximum connection speed.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_WRITING_MAXCONNECTBPS          = (%RASBASE+85)
'
'
'

'
' There was an error in writing the maximum carrier speed.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_WRITING_MAXCARRIERBPS          = (%RASBASE+86)
'
'
'

'
' There was an error in writing the usage.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_WRITING_USAGE                  = (%RASBASE+87)
'
'
'

'
' There was an error in writing the default-off.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_WRITING_DEFAULTOFF             = (%RASBASE+88)
'
'
'

'
' There was an error in reading the default-off.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_READING_DEFAULTOFF             = (%RASBASE+89)
'
'
'

'
' ERROR_EMPTY_INI_FILE
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_EMPTY_INI_FILE                 = (%RASBASE+90)
'
'
'
#ENDIF

%ERROR_AUTHENTICATION_FAILURE         = (%RASBASE+91)
'
' The remote connection was denied because the user name and password combination you provided is not recognized, or the selected authentication protocol is not permitted on the remote access server.

'

%ERROR_PORT_OR_DEVICE                 = (%RASBASE+92)
'
' There was a hardware failure in the modem (or other connecting device).
'

%ERROR_NOT_BINARY_MACRO               = (%RASBASE+93)
'
' ERROR_NOT_BINARY_MACRO
'

%ERROR_DCB_NOT_FOUND                  = (%RASBASE+94)
'
' ERROR_DCB_NOT_FOUND
'

%ERROR_STATE_MACHINES_NOT_STARTED     = (%RASBASE+95)
'
' The state machines are not started.
'

%ERROR_STATE_MACHINES_ALREADY_STARTED = (%RASBASE+96)
'
' The state machines are already started.
'

%ERROR_PARTIAL_RESPONSE_LOOPING       = (%RASBASE+97)
'
' The response looping did not complete.
'

%ERROR_UNKNOWN_RESPONSE_KEY           = (%RASBASE+98)
'
' A response keyname in the device.INF file is not in the expected format.
'

%ERROR_RECV_BUF_FULL                  = (%RASBASE+99)
'
' The modem (or other connecting device) response caused a buffer overflow.
'

%ERROR_CMD_TOO_LONG                   = (%RASBASE+100)
'
' The expanded command in the device.INF file is too long.
'

%ERROR_UNSUPPORTED_BPS                = (%RASBASE+101)
'
' The modem moved to a connection speed not supported by the COM driver.
'

%ERROR_UNEXPECTED_RESPONSE            = (%RASBASE+102)
'
' Device response received when none expected.
'

%ERROR_INTERACTIVE_MODE               = (%RASBASE+103)
'
' The connection needs information from you, but the application does not allow user interaction.
'

%ERROR_BAD_CALLBACK_NUMBER            = (%RASBASE+104)
'
' The callback number is invalid.
'

%ERROR_INVALID_AUTH_STATE             = (%RASBASE+105)
'
' The authorization state is invalid.
'

#IF (%WINVER < &H600)
'
' ERROR_WRITING_INITBPS
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_WRITING_INITBPS                = (%RASBASE+106)
'
'
'
#ENDIF

%ERROR_X25_DIAGNOSTIC                 = (%RASBASE+107)
'
' There was an error related to the X.25 protocol.
'

%ERROR_ACCT_EXPIRED                   = (%RASBASE+108)
'
' The account has expired.
'

%ERROR_CHANGING_PASSWORD              = (%RASBASE+109)
'
' There was an error changing the password on the domain.  The password might have been too short or might have matched a previously used password.
'

%ERROR_OVERRUN                        = (%RASBASE+110)
'
' Serial overrun errors were detected while communicating with the modem.
'

%ERROR_RASMAN_CANNOT_INITIALIZE       = (%RASBASE+111)
'
' The operation could not finish because it could not start the Remote Access Connection Manager service in time. Please try the operation again.

'

#IF (%WINVER < &H600)
'
' The two-way port is initializing.  Wait a few seconds and redial.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_BIPLEX_PORT_NOT_AVAILABLE      = (%RASBASE+112)
'
'
'
#ENDIF

%ERROR_NO_ACTIVE_ISDN_LINES           = (%RASBASE+113)
'
' No active ISDN lines are available.
'

#IF (%WINVER < &H600)
'
' No ISDN channels are available to make the call.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_NO_ISDN_CHANNELS_AVAILABLE     = (%RASBASE+114)
'
'
'

'
' Too many errors occurred because of poor phone line quality.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_TOO_MANY_LINE_ERRORS           = (%RASBASE+115)
'
'
'
#ENDIF

%ERROR_IP_CONFIGURATION               = (%RASBASE+116)
'
' The Remote Access Service IP configuration is unusable.
'

%ERROR_NO_IP_ADDRESSES                = (%RASBASE+117)
'
' No IP addresses are available in the static pool of Remote Access Service IP addresses.
'

%ERROR_PPP_TIMEOUT                    = (%RASBASE+118)
'
' The connection was terminated because the remote computer did not respond in a timely manner.
'

#IF (%WINVER < &H600)
'
' The connection was terminated by the remote computer.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_PPP_REMOTE_TERMINATED          = (%RASBASE+119)
'
'
'
#ENDIF

%ERROR_PPP_NO_PROTOCOLS_CONFIGURED    = (%RASBASE+120)
'
' A connection to the remote computer could not be established.  You might need to change the network settings for this connection.
'

%ERROR_PPP_NO_RESPONSE                = (%RASBASE+121)
'
' The remote computer did not respond.
'

%ERROR_PPP_INVALID_PACKET             = (%RASBASE+122)
'
' Invalid data was received from the remote computer.  This data was ignored.
'

%ERROR_PHONE_NUMBER_TOO_LONG          = (%RASBASE+123)
'
' The phone number, including prefix and suffix, is too long.
'

#IF (%WINVER < &H600)
'
' The IPX protocol cannot dial out on the modem (or other connecting device) because this computer is not configured for dialing out (it is an IPX router).
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_IPXCP_NO_DIALOUT_CONFIGURED    = (%RASBASE+124)
'
'
'

'
' The IPX protocol cannot dial in on the modem (or other connecting device) because this computer is not configured for dialing in (the IPX router is not installed).
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_IPXCP_NO_DIALIN_CONFIGURED     = (%RASBASE+125)
'
'
'
#ENDIF

%ERROR_IPXCP_DIALOUT_ALREADY_ACTIVE   = (%RASBASE+126)
'
' The IPX protocol cannot be used for dialing out on more than one modem (or other connecting device) at a time.
'

#IF (%WINVER < &H600)
'
' Cannot access TCPCFG.DLL.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_ACCESSING_TCPCFGDLL            = (%RASBASE+127)
'
'
'
#ENDIF

%ERROR_NO_IP_RAS_ADAPTER              = (%RASBASE+128)
'
' The system cannot find an IP adapter.
'

%ERROR_SLIP_REQUIRES_IP               = (%RASBASE+129)
'
' SLIP cannot be used unless the IP protocol is installed.
'

#IF (%WINVER < &H600)
'
' Computer registration is not complete.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_PROJECTION_NOT_COMPLETE        = (%RASBASE+130)
'
'
'
#ENDIF

%ERROR_PROTOCOL_NOT_CONFIGURED        = (%RASBASE+131)
'
' The protocol is not configured.
'

%ERROR_PPP_NOT_CONVERGING             = (%RASBASE+132)
'
'Your computer and the remote computer could not agree on PPP control protocols.
'

%ERROR_PPP_CP_REJECTED                = (%RASBASE+133)
'
' A connection to the remote computer could not be completed.  You might need to adjust the protocols on this computer.
'

%ERROR_PPP_LCP_TERMINATED             = (%RASBASE+134)
'
' The PPP link control protocol was terminated.
'

%ERROR_PPP_REQUIRED_ADDRESS_REJECTED  = (%RASBASE+135)
'
' The requested address was rejected by the server.
'

%ERROR_PPP_NCP_TERMINATED             = (%RASBASE+136)
'
' The remote computer terminated the control protocol.
'

%ERROR_PPP_LOOPBACK_DETECTED          = (%RASBASE+137)
'
' Loopback was detected.
'

%ERROR_PPP_NO_ADDRESS_ASSIGNED        = (%RASBASE+138)
'
' The remote connection was not made because the remote access server did not assign an IP address.

'

%ERROR_CANNOT_USE_LOGON_CREDENTIALS   = (%RASBASE+139)
'
' The authentication protocol required by the remote server cannot use the stored password.  Redial, entering the password explicitly.
'

%ERROR_TAPI_CONFIGURATION             = (%RASBASE+140)
'
' An invalid dialing rule was detected.
'

%ERROR_NO_LOCAL_ENCRYPTION            = (%RASBASE+141)
'
' The local computer does not support the required data encryption type.
'

%ERROR_NO_REMOTE_ENCRYPTION           = (%RASBASE+142)
'
' The remote computer does not support the required data encryption type.
'

#IF (%WINVER < &H600)
'
' The remote computer requires data encryption.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_REMOTE_REQUIRES_ENCRYPTION     = (%RASBASE+143)
'
'
'

'
' The system cannot use the IPX network number assigned by the remote computer.  Additional information is provided in the event log.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_IPXCP_NET_NUMBER_CONFLICT      = (%RASBASE+144)
'
'
'

'
' ERROR_INVALID_SMM
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_INVALID_SMM                    = (%RASBASE+145)
'
'
'

'
' ERROR_SMM_UNINITIALIZED
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_SMM_UNINITIALIZED              = (%RASBASE+146)
'
'
'

'
' ERROR_NO_MAC_FOR_PORT
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_NO_MAC_FOR_PORT                = (%RASBASE+147)
'
'
'

'
' ERROR_SMM_TIMEOUT
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_SMM_TIMEOUT                    = (%RASBASE+148)
'
'
'
#ENDIF


%ERROR_BAD_PHONE_NUMBER               = (%RASBASE+149)
'
' The destination address or phone number is either invalid or not present.
'


#IF (%WINVER < &H600)

'
' ERROR_WRONG_MODULE
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_WRONG_MODULE                   = (%RASBASE+150)
'
'
'

'
' The callback number contains an invalid character.  Only the following 18 characters are allowed:  0 to 9, T, P, W, (, ), -, @, and space.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_INVALID_CALLBACK_NUMBER        = (%RASBASE+151)
'
'
'
#ENDIF

%ERROR_SCRIPT_SYNTAX                  = (%RASBASE+152)
'
' A syntax error was encountered while processing a script.
'

%ERROR_HANGUP_FAILED                  = (%RASBASE+153)
'
' The connection could not be disconnected because the user does not have the required permission to disconnect.
'

%ERROR_BUNDLE_NOT_FOUND               = (%RASBASE+154)
'
' The system could not find the multi-link bundle.
'

%ERROR_CANNOT_DO_CUSTOMDIAL           = (%RASBASE+155)
'
' The system cannot perform automated dial because this connection has a custom dialer specified.
'

%ERROR_DIAL_ALREADY_IN_PROGRESS       = (%RASBASE+156)
'
' This connection is already being dialed.
'

%ERROR_RASAUTO_CANNOT_INITIALIZE      = (%RASBASE+157)
'
' Remote Access Services could not be started automatically.  Additional information is provided in the event log.
'

#IF (%WINVER < &H600)
'
' Internet Connection Sharing is already enabled on the connection.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_CONNECTION_ALREADY_SHARED      = (%RASBASE+158)
'
'
'

'
' An error occurred while the existing Internet Connection Sharing settings were being changed.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_SHARING_CHANGE_FAILED          = (%RASBASE+159)
'
'
'

'
' An error occurred while routing capabilities were being enabled.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_SHARING_ROUTER_INSTALL         = (%RASBASE+160)
'
'
'

'
' An error occurred while Internet Connection Sharing was being enabled for the connection.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_SHARE_CONNECTION_FAILED        = (%RASBASE+161)
'
'
'

'
' An error occurred while the local network was being configured for sharing.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_SHARING_PRIVATE_INSTALL        = (%RASBASE+162)
'
'
'

'
' Internet Connection Sharing cannot be enabled.  There is more than one LAN connection other than the connection to be shared.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_CANNOT_SHARE_CONNECTION        = (%RASBASE+163)
'
'
'
#ENDIF

%ERROR_NO_SMART_CARD_READER           = (%RASBASE+164)
'
' No smart card reader is installed.
'

%ERROR_NO_CERTIFICATE                 = (%RASBASE+166)
'
' A certificate could not be found.  Connections that use the L2TP protocol over IPSec require the installation of a machine certificate, also known as a computer certificate.
'

%ERROR_FAILED_TO_ENCRYPT              = (%RASBASE+168)
'
' The connection attempt failed because of failure to encrypt data.
'

%ERROR_BAD_ADDRESS_SPECIFIED          = (%RASBASE+169)
'
' The specified destination is not reachable.
'

%ERROR_CONNECTION_REJECT              = (%RASBASE+170)
'
' The remote computer rejected the connection attempt.
'

%ERROR_CONGESTION                     = (%RASBASE+171)
'
' The connection attempt failed because the network is busy.
'

%ERROR_INCOMPATIBLE                   = (%RASBASE+172)
'
' The remote computer's network hardware is incompatible with the type of call requested.
'

%ERROR_NUMBERCHANGED                  = (%RASBASE+173)
'
' The connection attempt failed because the destination number has changed.
'

%ERROR_TEMPFAILURE                    = (%RASBASE+174)
'
' The connection attempt failed because of a temporary failure.  Try connecting again.
'

%ERROR_BLOCKED                        = (%RASBASE+175)
'
' The call was blocked by the remote computer.
'

%ERROR_DONOTDISTURB                   = (%RASBASE+176)
'
' The call could not be connected because the remote computer has invoked the Do Not Disturb feature.
'

%ERROR_OUTOFORDER                     = (%RASBASE+177)
'
' The connection attempt failed because the modem (or other connecting device) on the remote computer is out of order.
'

%ERROR_UNABLE_TO_AUTHENTICATE_SERVER  = (%RASBASE+178)
'
' It was not possible to verify the identity of the server.
'

#IF (%WINVER < &H600)
'
' To dial out using this connection you must use a smart card.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_SMART_CARD_REQUIRED            = (%RASBASE+179)
'
'
'
#ENDIF

%ERROR_INVALID_FUNCTION_FOR_ENTRY     = (%RASBASE+180)
'
' An attempted function is not valid for this connection.
'

#IF (%WINVER < &H600)
'
' The connection requires a certificate, and no valid certificate was found.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_CERT_FOR_ENCRYPTION_NOT_FOUND  = (%RASBASE+181)
'
'
'
#ENDIF

%ERROR_NO_DIFF_USER_AT_LOGON          = (%RASBASE+184)
'
' You cannot dial using this connection at logon time, because it is configured to use a user name different than the one on the smart card.  If you want to use it at logon time, you must configure it to use the user name on the smart card.
'

%ERROR_NO_REG_CERT_AT_LOGON           = (%RASBASE+185)
'
' You cannot dial using this connection at logon time, because it is not configured to use a smart card.  If you want to use it at logon time, you must edit the properties of this connection so that it uses a smart card.
'

%ERROR_OAKLEY_NO_CERT                 = (%RASBASE+186)
'
' The connection attempt failed because there is no valid machine certificate on your computer for security authentication.
'

%ERROR_OAKLEY_AUTH_FAIL               = (%RASBASE+187)
'
' The L2TP connection attempt failed because the security layer could not authenticate the remote computer.
'

%ERROR_OAKLEY_ATTRIB_FAIL             = (%RASBASE+188)
'
' The L2TP connection attempt failed because the security layer could not negotiate compatible parameters with the remote computer.
'

%ERROR_OAKLEY_GENERAL_PROCESSING      = (%RASBASE+189)
'
' The L2TP connection attempt failed because the security layer encountered a processing error during initial negotiations with the remote computer.
'

%ERROR_OAKLEY_NO_PEER_CERT            = (%RASBASE+190)
'
' The L2TP connection attempt failed because certificate validation on the remote computer failed.
'

%ERROR_OAKLEY_NO_POLICY               = (%RASBASE+191)
'
' The L2TP connection attempt failed because security policy for the connection was not found.
'

%ERROR_OAKLEY_TIMED_OUT               = (%RASBASE+192)
'
' The L2TP connection attempt failed because security negotiation timed out.
'

%ERROR_OAKLEY_ERROR                   = (%RASBASE+193)
'
' The L2TP connection attempt failed because an error occurred while negotiating security.
'

%ERROR_UNKNOWN_FRAMED_PROTOCOL        = (%RASBASE+194)
'
' The Framed Protocol RADIUS attribute for this user is not PPP.
'

%ERROR_WRONG_TUNNEL_TYPE              = (%RASBASE+195)
'
' The Tunnel Type RADIUS attribute for this user is not correct.
'

%ERROR_UNKNOWN_SERVICE_TYPE           = (%RASBASE+196)
'
' The Service Type RADIUS attribute for this user is neither Framed nor Callback Framed.
'

%ERROR_CONNECTING_DEVICE_NOT_FOUND    = (%RASBASE+197)
'
' A connection to the remote computer could not be established because the modem was not found or was busy.
'

%ERROR_NO_EAPTLS_CERTIFICATE          = (%RASBASE+198)
'
' A certificate could not be found that can be used with this Extensible Authentication Protocol.
'

' #if (%WINVER < &H600) bugbug - see 657989
'
' Internet Connection Sharing (ICS) cannot be enabled due to an IP address conflict on the network.  ICS requires the host be configured to use 192.168.0.1.  Please ensure that no other client on the network is configured to use 192.168.0.1.
'
' This error was obsoleted in the Windows Vista release.
'
%ERROR_SHARING_HOST_ADDRESS_CONFLICT  = (%RASBASE+199)
'
'
'
' #endif

%ERROR_AUTOMATIC_VPN_FAILED           = (%RASBASE+200)
'
' The remote connection was not made because the attempted VPN tunnels failed. The VPN server might be unreachable.
' If this connection is attempting to use an L2TP/IPsec tunnel, the security parameters required for IPsec negotiation might not be configured properly.
'

%ERROR_VALIDATING_SERVER_CERT         = (%RASBASE+201)
'
' This connection is configured to validate the identity of the access server, but Windows cannot verify the digital certificate sent by the server.
'

%ERROR_READING_SCARD                  = (%RASBASE+202)
'
' The card supplied was not recognized.  Please check that the card is inserted correctly, and fits tightly.
'

%ERROR_INVALID_PEAP_COOKIE_CONFIG     = (%RASBASE+203)
'
' The PEAP configuration stored in the session cookie does not match the current session configuration.
'

%ERROR_INVALID_PEAP_COOKIE_USER       = (%RASBASE+204)
'
' The PEAP identity stored in the session cookie does not match the current identity.
'

%ERROR_INVALID_MSCHAPV2_CONFIG        = (%RASBASE+205)
'
' You cannot dial using this connection at logon time, because it is configured to use logged on user's credentials.
'

'
' New Windows Vista Errors
'
%ERROR_VPN_GRE_BLOCKED                 = (%RASBASE+206)
'
' The VPN connection between your computer and the VPN server could not be
' completed. The most common cause for this failure is that at least one
' Internet device (for example, a firewall or a router) between your computer
' and the VPN server is not configured to allow Generic Routing Encapsulation
' (GRE) protocol packets. If the problem persists, contact your network
' administrator or Internet Service Provider.
'

%ERROR_VPN_DISCONNECT                 = (%RASBASE+207)
'
' The network connection between your computer and the VPN server was
' interrupted. This can be caused by a problem in the VPN transmission and is
' commonly the result of internet latency or simply that your VPN server has
' reached capacity. Please try to reconnect to the VPN server. If this problem
' persists, contact the VPN administrator and analyze quality of network
' connectivity.
'

%ERROR_VPN_REFUSED                    = (%RASBASE+208)
'
' The network connection between your computer and the VPN server could not be
' established because the remote server refused the connection. This is
' typically caused by a mismatch between the server's configuration and your
' connection settings. Please contact the remote server's Administrator to
' verify the server configuration and your connection settings.
'

%ERROR_VPN_TIMEOUT                    = (%RASBASE+209)
'
' The network connection between your computer and the VPN server could not be
' established because the remote server is not responding. This could be because
' one of the network devices (e.g, firewalls, NAT, routers, etc) between your
' computer and the remote server is not configured to allow VPN connections.
' Please contact your Administrator or your service provider to determine which
' device may be causing the problem.
'

%ERROR_VPN_BAD_CERT                   = (%RASBASE+210)
'
' A network connection between your computer and the VPN server was started,
' but the VPN connection was not completed. This is typically caused by the use
' of an incorrect or expired certificate for authentication between the client
' and the server. Please contact your Administrator to ensure that the
' certificate being used for authentication is valid.
'

%ERROR_VPN_BAD_PSK                    = (%RASBASE+211)
'
' The network conection between your computer and the VPN server could not be
' established because the remote server is not responding. This is typically
' caused by a pre-shared key problem between the client and server. A pre-shared
' key is used to guarantee you are who you say you are in an IP Security (IPSec)
' communication cycle. Please get the assistance of your administrator to
' determine where the pre-shared key problem is originating.
'

%ERROR_SERVER_POLICY                  = (%RASBASE+212)
'
'The connection was prevented because of a policy configured on your RAS/VPN
' server. Specifically, the authentication method used by the server to verify
' your username and password may not match the authentication method configured
' in your connection profile. Please contact the Administrator of the RAS server
' and notify them of this error.
'

%ERROR_BROADBAND_ACTIVE               = (%RASBASE+213)
'
' You have attempted to establish a second broadband connection while a
' previous broadband connection is already established using the same device or
' port. Please disconnect the earlier connection and then reestablish the
' connection.
'

%ERROR_BROADBAND_NO_NIC               = (%RASBASE+214)
'
' The underlying Ethernet connectivity required for the broadband connection
' was not found. Please install and enable the Ethernet adapter on your computer
' via the Network Connections folder before attempting this connection.
'

%ERROR_BROADBAND_TIMEOUT              = (%RASBASE+215)
'
' The broadband network conection could not be established on your computer
' because the remote server is not responding. This could be caused by an
' invalid value for the 'Service Name' field for this connection. Please contact
' your Internet Service Provider and inquire about the correct value for this
' field and update it in the Connection Properties.
'

%ERROR_FEATURE_DEPRECATED             = (%RASBASE+216)
'
' A feature or setting you have tried to enable is no longer supported by the
' remote access service.
'

%ERROR_CANNOT_DELETE                  = (%RASBASE+217)
'
' Cannot delete a connection while it is connected.
'

#IF (%WINVER <= &H600)

%ERROR_RASQEC_RESOURCE_CREATION_FAILED = (%RASBASE+218)
'
' The Network Access Protection (NAP) enforcement client could not create
' system resources for remote access connections. Some network services or
' resources might not be available. If the problem persists, disconnect and
' retry the remote access connection or contact the administrator for the remote
' access server.
'

%ERROR_RASQEC_NAPAGENT_NOT_ENABLED    = (%RASBASE+219)
'
' The Network Access Protection Agent (NAPAgent) service has been disabled or
' is not installed on this computer. Some network services or resources might
' not be available. If the problem persists, disconnect and retry the remote
' access connection or contact the administrator for the remote access server.
'

%ERROR_RASQEC_NAPAGENT_NOT_CONNECTED  = (%RASBASE+220)
'
' The Network Access Protection (NAP) enforcement client failed to register
' with the Network Access Protection Agent (NAPAgent) service. Some network
' services or resources might not be available. If the problem persists,
' disconnect and retry the remote access connection or contact the administrator
' for the remote access server.
'

%ERROR_RASQEC_CONN_DOESNOTEXIST       = (%RASBASE+221)
'
' The Network Access Protection (NAP) enforcement client was unable to process
' the request because the remote access connection does not exist. Retry the
' remote access connection. If the problem persists, make sure that you can
' connect to the Internet, and then contact the administrator for the remote
' access server.
'

%ERROR_RASQEC_TIMEOUT                 = (%RASBASE+222)
'
' The Network Access Protection (NAP) enforcement client did not respond. Some
' network services or resources might not be available. If the problem persists,
' disconnect and retry the remote access connection or contact the administrator
' for the remote access server.
'

#ENDIF  ' #IF (%WINVER <= &H600)

%ERROR_PEAP_CRYPTOBINDING_INVALID    = (%RASBASE+223)
'
' Received Crypto-Binding TLV is invalid.
'

%ERROR_PEAP_CRYPTOBINDING_NOTRECEIVED   = (%RASBASE+224)
'
' Crypto-Binding TLV is not received.
'

#IF (%WINVER >= &H0600)

%ERROR_INVALID_VPNSTRATEGY   = (%RASBASE+225)
'
' The remote connection was not made because Point-to-Point Tunneling Protocol (PPTP) is incompatible with IPv6. Use any other tunneling protocol.

'

#ENDIF

%ERROR_EAPTLS_CACHE_CREDENTIALS_INVALID   = (%RASBASE+226)
'
' EAPTLS validation of the cached credentials failed. Please discard
' cached credentials.
'

%ERROR_IPSEC_SERVICE_STOPPED                 = (%RASBASE+227)
'
' The L2TP/IPsec connection cannot be completed because the IKE and AuthIP
' IPSec Keying Modules service and/or the Base Filtering Engine service is not
' running. These services are required to establish an L2TP/IPSec connection.
' Please ensure that these services have been started before dialing the
' connection.
'

#IF (%WINVER >= &H0600)

%ERROR_IDLE_TIMEOUT               = (%RASBASE+228)
'
' The connection was terminated because of idle timeout.
'

%ERROR_LINK_FAILURE               = (%RASBASE+229)
'
' The modem (or other connecting device) was disconnected due to link failure.
'

%ERROR_USER_LOGOFF                = (%RASBASE+230)
'
' The connection was terminated because user logged off.
'

%ERROR_FAST_USER_SWITCH           = (%RASBASE+231)
'
' The connection was terminated because user switch happened.
'

%ERROR_HIBERNATION                 = (%RASBASE+232)
'
' The connection was terminated because of hibernation.
'

%ERROR_SYSTEM_SUSPENDED            = (%RASBASE+233)
'
' The connection was terminated because the system got suspended.
'

%ERROR_RASMAN_SERVICE_STOPPED      = (%RASBASE+234)
'
' The connection was terminated because Remote Access Connection manager stopped.
'

%ERROR_INVALID_SERVER_CERT         = (%RASBASE+235)
'
' The L2TP connection attempt failed because the security layer could not
' authenticate the remote computer. This could be because one or more fields of
' the certificate presented by the remote server could not be validated as
' belonging to the target destination.
'

%ERROR_NOT_NAP_CAPABLE             = (%RASBASE+236)
'
' The Network Access Protection (NAP) health state of the computer cannot be determined.
' Contact your administrator to verify that the NAP enforcement client is enabled, the
' NAP Agent service is running, and NAP is enforced in the Protected
' Extensible Authentication Protocol (PEAP) properties of the remote access connection.
'

#ENDIF


#IF (%WINVER >= &H601)

%ERROR_INVALID_TUNNELID           = (%RASBASE+237)
'
' Invalid Tunnel ID.
'

%ERROR_UPDATECONNECTION_REQUEST_IN_PROCESS    = (%RASBASE+238)
'
' Another Update connection request is in progress. RAS allows only one Update Connection request at a time.
'

%ERROR_PROTOCOL_ENGINE_DISABLED    = (%RASBASE+239)
'
' Negotiating using configured protocol is disable. Edit connection properties and select different protocol for negotiation and try again.
'

%ERROR_INTERNAL_ADDRESS_FAILURE    = (%RASBASE+240)
'
'  Internal address negotiation failed.
'

%ERROR_FAILED_CP_REQUIRED          = (%RASBASE+241)
'
' Client has to request a Internal IPv4 or IPv6 address.
'

%ERROR_TS_UNACCEPTABLE             = (%RASBASE+242)
'
'  Traffic Selectors negotiation failed.
'

%ERROR_MOBIKE_DISABLED             = (%RASBASE+243)
'
' Mobility is disabled for this connection.
'

%ERROR_CANNOT_INITIATE_MOBIKE_UPDATE  = (%RASBASE+244)
'
' The VPN Connection is still connecting or reauthenticating because of Quarantine state change. Initiate mobike update only when connection state is 'Connected'.
'

%ERROR_PEAP_SERVER_REJECTED_CLIENT_TLV           = (%RASBASE+245)
'
' Server rejected client authentication, due unexpected TLV or value mismatch for a TLV.
'

%ERROR_INVALID_PREFERENCES           = (%RASBASE+246)
'
' Either VPN Destination preference is not selected by the user or it is no longer valid.
'

%ERROR_EAPTLS_SCARD_CACHE_CREDENTIALS_INVALID = (%RASBASE+247)
'
' Cached smart card credential is invalid.
'

%ERROR_SSTP_COOKIE_SET_FAILURE             = (%RASBASE + 248)
'
' VPN connection attempt failed due to internal error occurred while adding cookies to the Secure Socket Tunneling Protocol (SSTP). Please see the System Event Log for the detailed information.
'
%ERROR_INVALID_PEAP_COOKIE_ATTRIBUTES = (%RASBASE+249)
'
' The PEAP inner method attributes stored in the cookie is invalid
'

%ERROR_EAP_METHOD_NOT_INSTALLED            = (%RASBASE+250)
'
' The Extensible Authentication Protocol type required for authentication of the remote access connection is not installed on your computer.
'

%ERROR_EAP_METHOD_DOES_NOT_SUPPORT_SSO     = (%RASBASE+251)
'
' The Extensible Authentication Protocol type configured on the remote access connection does not support single sign-on.
'

%ERROR_EAP_METHOD_OPERATION_NOT_SUPPORTED  = (%RASBASE+252)
'
' The Extensible Authentication Protocol type configured on the remote access connection does not support the requested operation.
'

%ERROR_EAP_USER_CERT_INVALID               = (%RASBASE+253)
'
' The remote access connection completed, but authentication failed because the certificate that authenticates the client to the server is not valid. Ensure that the certificate used for authentication is valid.
'

%ERROR_EAP_USER_CERT_EXPIRED               = (%RASBASE+254)
'
' The remote access connection completed, but authentication failed because the certificate that authenticates the client to the server is expired. Renew the certificate.
'

%ERROR_EAP_USER_CERT_REVOKED               = (%RASBASE+255)
'
' The remote access connection completed, but authentication failed because the certificate that authenticates the client to the server is revoked.
'

%ERROR_EAP_USER_CERT_OTHER_ERROR           = (%RASBASE+256)
'
' The remote access connection completed, but authentication failed because of an error in the certificate that authenticates the client to the server.
'

%ERROR_EAP_SERVER_CERT_INVALID             = (%RASBASE+257)
'
' The remote access connection completed, but authentication failed because the certificate that the client uses to authenticate the server is not valid.
'

%ERROR_EAP_SERVER_CERT_EXPIRED             = (%RASBASE+258)
'
' The remote access connection completed, but authentication failed because the certificate that the client uses to authenticate the server is expired.
'

%ERROR_EAP_SERVER_CERT_REVOKED             = (%RASBASE+259)
'
' The remote access connection completed, but authentication failed because the certificate that the client uses to authenticate the server is revoked.
'

%ERROR_EAP_SERVER_CERT_OTHER_ERROR         = (%RASBASE+260)
'
' The remote access connection completed, but authentication failed because of an error in the certificate that the client uses to authenticate the server.
'

%ERROR_EAP_USER_ROOT_CERT_NOT_FOUND        = (%RASBASE+261)
'
' The remote access connection completed, but authentication failed because a trusted root certificate that validates the user certificate was not found in the Trusted Root Certification Authorities certificate store.
'

%ERROR_EAP_USER_ROOT_CERT_INVALID          = (%RASBASE+262)
'
' The remote access connection completed, but authentication failed because the trusted root certificate that is used to validate the user certificate is not valid.
'

%ERROR_EAP_USER_ROOT_CERT_EXPIRED          = (%RASBASE+263)
'
' The remote access connection completed, but authentication failed because the certificate in the Trusted Root Certification Authorities certificate store that authenticates the user certificate is expired. Renew the certificate.
'

%ERROR_EAP_SERVER_ROOT_CERT_NOT_FOUND      = (%RASBASE+264)
'
' The remote access connection completed, but authentication failed because a certificate that validates the server certificate was not found in the Trusted Root Certification Authorities certificate store.
'

%ERROR_EAP_SERVER_ROOT_CERT_INVALID        = (%RASBASE+265)
'
' The remote zccess connection completed, but authentication failed because the certificate in the Trusted Root Certification Authorities certificate store that validates the server certificate is not valid.
'

%ERROR_EAP_SERVER_ROOT_CERT_NAME_REQUIRED  = (%RASBASE+266)
'
' The remote access connection completed, but authentication failed because the certificate on the server computer does not have a server name specified.
'

%ERROR_PEAP_IDENTITY_MISMATCH = (%RASBASE+267)
'
' The PEAP outer identity is not same as the inner identity when identity privacy is turned OFF.
'

%ERROR_DNSNAME_NOT_RESOLVABLE = (%RASBASE+268)
'
' The remote connection was not made because the name of the remote access server did not resolve.
'

#ENDIF



%RASBASEEND                          = (%RASBASE+268)
