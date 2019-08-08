'------------------------------------------------------------------------------
'
'  VCR.inc -- MCI VCR services for controlling video cassette recorders
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from vcr.h of 14 Jul 2009
'------------------------------------------------------------------------------


#INCLUDE THIS ONCE

%VCR_INC = 1

#INCLUDE "MMSystem.inc"


' string resource base for vcr device type
%MCI_VCR_OFFSET = 1280

' system MCI commands
%MCI_LIST       = &H0878
%MCI_SETAUDIO   = &H0873
%MCI_SETVIDEO   = &H0876
%MCI_SIGNAL     = &H0875

' custom MCI commands for VCRs
%MCI_MARK        = %MCI_USER_MESSAGES
%MCI_INDEX       = %MCI_USER_MESSAGES + 1
%MCI_SETTUNER    = %MCI_USER_MESSAGES + 2
%MCI_SETVCR      = %MCI_USER_MESSAGES + 3
%MCI_SETTIMECODE = %MCI_USER_MESSAGES + 4

' Test is appplicable to all commands
%MCI_TEST        = &H00000020

' flags for dwItem field of MCI_GETDEVCAPS_PARMS parameter block
%MCI_VCR_GETDEVCAPS_CAN_DETECT_LENGTH    = &H00004001
%MCI_VCR_GETDEVCAPS_SEEK_ACCURACY        = &H00004002
%MCI_VCR_GETDEVCAPS_HAS_CLOCK            = &H00004003
%MCI_VCR_GETDEVCAPS_CAN_REVERSE          = &H00004004
%MCI_VCR_GETDEVCAPS_NUMBER_OF_MARKS      = &H00004005
%MCI_VCR_GETDEVCAPS_CAN_TEST             = &H00004006
%MCI_VCR_GETDEVCAPS_CAN_PREROLL          = &H00004007
%MCI_VCR_GETDEVCAPS_CAN_PREVIEW          = &H00004008
%MCI_VCR_GETDEVCAPS_CAN_MONITOR_SOURCES  = &H00004009
%MCI_VCR_GETDEVCAPS_HAS_TIMECODE         = &H0000400A
%MCI_VCR_GETDEVCAPS_CAN_FREEZE           = &H0000401B
%MCI_VCR_GETDEVCAPS_CLOCK_INCREMENT_RATE = &H0000401C

' flags for dwFlags parameter of MCI_INFO command message
%MCI_VCR_INFO_VERSION = &H00010000

' flags for dwFlags parameter of MCI_PLAY command message
%MCI_VCR_PLAY_REVERSE = &H00010000
%MCI_VCR_PLAY_AT      = &H00020000
%MCI_VCR_PLAY_SCAN    = &H00040000

' flags for dwFlags parameter of MCI_RECORD command message
%MCI_VCR_RECORD_INITIALIZE = &H00010000
%MCI_VCR_RECORD_AT         = &H00020000
%MCI_VCR_RECORD_PREVIEW    = &H00040000

' flags for dwFlags parameter of MCI_CUE command message
%MCI_VCR_CUE_INPUT   = &H00010000
%MCI_VCR_CUE_OUTPUT  = &H00020000
%MCI_VCR_CUE_PREROLL = &H00040000
%MCI_VCR_CUE_REVERSE = &H00080000

' flags for dwFlags parameter of MCI_SEEK command message
%MCI_VCR_SEEK_REVERSE = &H00010000
%MCI_VCR_SEEK_MARK    = &H00020000
%MCI_VCR_SEEK_AT      = &H00040000

' flags for dwFlags parameter of MCI_SETTUNER command message
%MCI_VCR_SETTUNER_CHANNEL           = &H00010000
%MCI_VCR_SETTUNER_CHANNEL_UP        = &H00020000
%MCI_VCR_SETTUNER_CHANNEL_DOWN      = &H00040000
%MCI_VCR_SETTUNER_CHANNEL_SEEK_UP   = &H00080000
%MCI_VCR_SETTUNER_CHANNEL_SEEK_DOWN = &H00100000
%MCI_VCR_SETTUNER_NUMBER            = &H00200000

' flags for dwFlags parameter of MCI_SET command message
%MCI_VCR_SET_TIME_MODE         = &H00010000
%MCI_VCR_SET_POWER             = &H00020000
%MCI_VCR_SET_RECORD_FORMAT     = &H00040000
%MCI_VCR_SET_COUNTER_FORMAT    = &H00080000
%MCI_VCR_SET_INDEX             = &H00100000
%MCI_VCR_SET_ASSEMBLE_RECORD   = &H00200000
%MCI_VCR_SET_TRACKING          = &H00400000
%MCI_VCR_SET_SPEED             = &H00800000
%MCI_VCR_SET_TAPE_LENGTH       = &H01000000
%MCI_VCR_SET_COUNTER_VALUE     = &H02000000
%MCI_VCR_SET_CLOCK             = &H04000000
%MCI_VCR_SET_PAUSE_TIMEOUT     = &H08000000
%MCI_VCR_SET_PREROLL_DURATION  = &H10000000
%MCI_VCR_SET_POSTROLL_DURATION = &H20000000

' flags for dwItem parameter of MCI_SETTIMECODE commmand message
%MCI_VCR_SETTIMECODE_RECORD = &H00010000

' flags for dwItem field of MCI_STATUS_PARMS parameter block
%MCI_VCR_STATUS_FRAME_RATE             = &H00004001  ' Frame rate
%MCI_VCR_STATUS_SPEED                  = &H00004002  ' Speed
%MCI_VCR_STATUS_MEDIA_TYPE             = &H00004003
%MCI_VCR_STATUS_RECORD_FORMAT          = &H00004004
%MCI_VCR_STATUS_PLAY_FORMAT            = &H00004005
%MCI_VCR_STATUS_AUDIO_SOURCE           = &H00004006
%MCI_VCR_STATUS_AUDIO_SOURCE_NUMBER    = &H00004007
%MCI_VCR_STATUS_VIDEO_SOURCE           = &H00004008
%MCI_VCR_STATUS_VIDEO_SOURCE_NUMBER    = &H00004009
%MCI_VCR_STATUS_AUDIO_MONITOR          = &H0000400A
%MCI_VCR_STATUS_AUDIO_MONITOR_NUMBER   = &H0000400B
%MCI_VCR_STATUS_VIDEO_MONITOR          = &H0000400C
%MCI_VCR_STATUS_VIDEO_MONITOR_NUMBER   = &H0000400D
%MCI_VCR_STATUS_INDEX_ON               = &H0000400E
%MCI_VCR_STATUS_INDEX                  = &H0000400F
%MCI_VCR_STATUS_COUNTER_FORMAT         = &H00004010
%MCI_VCR_STATUS_COUNTER_RESOLUTION     = &H00004011
%MCI_VCR_STATUS_TIMECODE_TYPE          = &H00004012
%MCI_VCR_STATUS_COUNTER_VALUE          = &H00004013
%MCI_VCR_STATUS_TUNER_CHANNEL          = &H00004014
%MCI_VCR_STATUS_WRITE_PROTECTED        = &H00004015
%MCI_VCR_STATUS_TIMECODE_RECORD        = &H00004016
%MCI_VCR_STATUS_VIDEO_RECORD           = &H00004017
%MCI_VCR_STATUS_AUDIO_RECORD           = &H00004018
%MCI_VCR_STATUS_TIME_TYPE              = &H00004019
%MCI_VCR_STATUS_TIME_MODE              = &H0000401A
%MCI_VCR_STATUS_POWER_ON               = &H0000401B
%MCI_VCR_STATUS_CLOCK                  = &H0000401C
%MCI_VCR_STATUS_ASSEMBLE_RECORD        = &H0000401D
%MCI_VCR_STATUS_TIMECODE_PRESENT       = &H0000401E
%MCI_VCR_STATUS_NUMBER_OF_VIDEO_TRACKS = &H0000401F
%MCI_VCR_STATUS_NUMBER_OF_AUDIO_TRACKS = &H00004020
%MCI_VCR_STATUS_CLOCK_ID               = &H00004021
%MCI_VCR_STATUS_PAUSE_TIMEOUT          = &H00004022
%MCI_VCR_STATUS_PREROLL_DURATION       = &H00004023
%MCI_VCR_STATUS_POSTROLL_DURATION      = &H00004024
%MCI_VCR_STATUS_VIDEO                  = &H00004025
%MCI_VCR_STATUS_AUDIO                  = &H00004026

%MCI_VCR_STATUS_NUMBER                 = &H00080000

' flags for dwFlags parameter of MCI_ESCAPE command message
%MCI_VCR_ESCAPE_STRING = &H00000100

' flags for dwFlags parameter of MCI_LIST command message
%MCI_VCR_LIST_VIDEO_SOURCE = &H00010000
%MCI_VCR_LIST_AUDIO_SOURCE = &H00020000
%MCI_VCR_LIST_COUNT        = &H00040000
%MCI_VCR_LIST_NUMBER       = &H00080000

' flags for dwFlags parameter of MCI_MARK command message
%MCI_VCR_MARK_WRITE = &H00010000
%MCI_VCR_MARK_ERASE = &H00020000

' flags for dwFlags parameter for MCI_SETAUDIO command message
%MCI_VCR_SETAUDIO_RECORD  = &H00010000
%MCI_VCR_SETAUDIO_SOURCE  = &H00020000
%MCI_VCR_SETAUDIO_MONITOR = &H00040000
%MCI_VCR_SETAUDIO_TO      = &H00200000
%MCI_VCR_SETAUDIO_NUMBER  = &H00400000

' flags for dwFlags parameter for MCI_SETVIDEO command message
%MCI_VCR_SETVIDEO_RECORD  = &H00010000
%MCI_VCR_SETVIDEO_SOURCE  = &H00020000
%MCI_VCR_SETVIDEO_MONITOR = &H00040000
%MCI_VCR_SETVIDEO_TO      = &H00100000
%MCI_VCR_SETVIDEO_NUMBER  = &H00200000

' The following is the function digitalvideo drivers must use
' to signal when a frame marked by the SIGNAL command has been rendered:
'
'  SEND_VCRSIGNAL(dwFlags, dwCallback, hDriver, wDeviceID, dwUser, dwPos)
'
' The following is a description of the parameters:
'
'  dwFlags    - the dwFlags parameter passed when the signal was set
'  dwCallback - the dwCallback value from the MCI_VCR_SIGNAL_PARMS struct
'               used to set the signal
'  hDriver    - the handle assigned to the driver by MMSYSTEM when the
'               device was opened
'  wDeviceID  - the device ID
'  dwUser     - the dwUserParm value from the MCI_VCR_SIGNAL_PARMS struct
'               used to set the signal
'  dwPos      - the position at which the signal was sent, in the current
'               time format.
'
' The window indicated by the handle in the dwCallback field is notified
' by means of a Windows message with the following form:
'
' msg    = MM_MCISIGNAL
' wParam = wDeviceID of the sending driver
' lParam = the uservalue specified or the position the signal was sent
'          at; the latter if the MCI_VCR_SIGNAL_POSITION flag was set
'          in the dwFlags parameter when the signal was created.
'

'#define SEND_VCRSIGNAL(dwFlags, dwCallback, hDriver, wDeviceID, dwUser, dwPos) \
'  DriverCallback( (dwCallback), DCB_WINDOW, (HANDLE)(wDeviceID), MM_MCISIGNAL,\
'  hDriver, ((dwFlags) & MCI_VCR_SIGNAL_POSITION) ? (dwPos):(dwUser),\
'  ((dwFlags) & MCI_VCR_SIGNAL_POSITION) ? (dwUser):(dwPos))

' Window message for signal notification
%MM_MCISIGNAL = &H3CB

' flags for dwFlags parameter of MCI_SIGNAL command message
%MCI_VCR_SIGNAL_AT       = &H00010000
%MCI_VCR_SIGNAL_EVERY    = &H00020000
%MCI_VCR_SIGNAL_USERVAL  = &H00040000
%MCI_VCR_SIGNAL_CANCEL   = &H00080000
%MCI_VCR_SIGNAL_POSITION = &H00100000

' flags for dwFlags parameter of MCI_STEP command message
%MCI_VCR_STEP_FRAMES  = &H00010000
%MCI_VCR_STEP_REVERSE = &H00020000

' flags for dwFlags parameter of MCI_FREEZE command message
%MCI_VCR_FREEZE_INPUT  = &H00010000
%MCI_VCR_FREEZE_OUTPUT = &H00020000
%MCI_VCR_FREEZE_FIELD  = &H00040000
%MCI_VCR_FREEZE_FRAME  = &H00080000

' flags for dwFlags parameter of MCI_UNFREEZE command message
%MCI_VCR_UNFREEZE_INPUT  = &H00010000
%MCI_VCR_UNFREEZE_OUTPUT = &H00020000

' string resource values for vcr media types
%MCI_VCR_MEDIA_8MM    = %MCI_VCR_OFFSET + 1
%MCI_VCR_MEDIA_HI8    = %MCI_VCR_OFFSET + 2
%MCI_VCR_MEDIA_VHS    = %MCI_VCR_OFFSET + 3
%MCI_VCR_MEDIA_SVHS   = %MCI_VCR_OFFSET + 4
%MCI_VCR_MEDIA_BETA   = %MCI_VCR_OFFSET + 5
%MCI_VCR_MEDIA_EDBETA = %MCI_VCR_OFFSET + 6
%MCI_VCR_MEDIA_OTHER  = %MCI_VCR_OFFSET + 7

' string resource values for vcr play/record formats
%MCI_VCR_FORMAT_SP    = %MCI_VCR_OFFSET + 8
%MCI_VCR_FORMAT_LP    = %MCI_VCR_OFFSET + 9
%MCI_VCR_FORMAT_EP    = %MCI_VCR_OFFSET + 10
%MCI_VCR_FORMAT_OTHER = %MCI_VCR_OFFSET + 11

' string resource values for timecode types
%MCI_VCR_TIME_TIMECODE = %MCI_VCR_OFFSET + 12
%MCI_VCR_TIME_COUNTER  = %MCI_VCR_OFFSET + 13
%MCI_VCR_TIME_DETECT   = %MCI_VCR_OFFSET + 14

' string resource values for src types
%MCI_VCR_SRC_TYPE_TUNER   = %MCI_VCR_OFFSET + 15
%MCI_VCR_SRC_TYPE_LINE    = %MCI_VCR_OFFSET + 16
%MCI_VCR_SRC_TYPE_SVIDEO  = %MCI_VCR_OFFSET + 17
%MCI_VCR_SRC_TYPE_RGB     = %MCI_VCR_OFFSET + 18
%MCI_VCR_SRC_TYPE_AUX     = %MCI_VCR_OFFSET + 19
%MCI_VCR_SRC_TYPE_GENERIC = %MCI_VCR_OFFSET + 20
%MCI_VCR_SRC_TYPE_MUTE    = %MCI_VCR_OFFSET + 21
%MCI_VCR_SRC_TYPE_OUTPUT  = %MCI_VCR_OFFSET + 22

' string resource values for vcr counters
%MCI_VCR_INDEX_TIMECODE = %MCI_VCR_OFFSET + 23
%MCI_VCR_INDEX_COUNTER  = %MCI_VCR_OFFSET + 24
%MCI_VCR_INDEX_DATE     = %MCI_VCR_OFFSET + 25
%MCI_VCR_INDEX_TIME     = %MCI_VCR_OFFSET + 26

' string resources for timecode type and counter resolution
%MCI_VCR_COUNTER_RES_SECONDS = %MCI_VCR_OFFSET + 27
%MCI_VCR_COUNTER_RES_FRAMES  = %MCI_VCR_OFFSET + 28

%MCI_VCR_TIMECODE_TYPE_SMPTE      = %MCI_VCR_OFFSET + 29
%MCI_VCR_TIMECODE_TYPE_SMPTE_DROP = %MCI_VCR_OFFSET + 30
%MCI_VCR_TIMECODE_TYPE_OTHER      = %MCI_VCR_OFFSET + 31
%MCI_VCR_TIMECODE_TYPE_NONE       = %MCI_VCR_OFFSET + 32

%MCI_VCR_PLUS  = %MCI_VCR_OFFSET + 33
%MCI_VCR_MINUS = %MCI_VCR_OFFSET + 34
%MCI_VCR_RESET = %MCI_VCR_OFFSET + 35

' parameter block for MCI_SEEK command message
TYPE MCI_VCR_SEEK_PARMS
    dwCallback AS DWORD
    dwTo       AS DWORD
    dwMark     AS DWORD
    dwAt       AS DWORD
END TYPE

' parameter block for MCI_SET command message
TYPE MCI_VCR_SET_PARMS
    dwCallback         AS DWORD
    dwTimeFormat       AS DWORD
    dwAudio            AS DWORD
    dwTimeMode         AS DWORD
    dwRecordFormat     AS DWORD
    dwCounterFormat    AS DWORD
    dwIndex            AS DWORD
    dwTracking         AS DWORD
    dwSpeed            AS DWORD
    dwLength           AS DWORD
    dwCounter          AS DWORD
    dwClock            AS DWORD
    dwPauseTimeout     AS DWORD
    dwPrerollDuration  AS DWORD
    dwPostrollDuration AS DWORD
END TYPE

' parameter block for MCI_VCR_SETTUNER command message
TYPE MCI_VCR_SETTUNER_PARMS
    dwCallback AS DWORD
    dwChannel  AS DWORD
    dwNumber   AS DWORD
END TYPE

' parameter block for MCI_ESCAPE command message
TYPE MCI_VCR_ESCAPE_PARMS
    dwCallback   AS DWORD
    lpstrCommand AS ASCIIZ PTR
END TYPE

' parameter block for MCI_LIST command message
TYPE MCI_VCR_LIST_PARMS
    dwCallback AS DWORD
    dwReturn   AS DWORD
    dwNumber   AS DWORD
END TYPE

' parameter block for MCI_RECORD command message
TYPE MCI_VCR_RECORD_PARMS
    dwCallback AS DWORD
    dwFrom     AS DWORD
    dwTo       AS DWORD
    dwAt       AS DWORD
END TYPE

' parameter block for MCI_PLAY command message
TYPE MCI_VCR_PLAY_PARMS
    dwCallback AS DWORD
    dwFrom     AS DWORD
    dwTo       AS DWORD
    dwAt       AS DWORD
END TYPE

' parameter block for MCI_SETAUDIO command message
TYPE MCI_VCR_SETAUDIO_PARMS
    dwCallback AS DWORD
    dwTrack    AS DWORD
    dwTo       AS DWORD
    dwNumber   AS DWORD
END TYPE

' parameter block for MCI_SIGNAL command message
TYPE MCI_VCR_SIGNAL_PARMS
    dwCallback AS DWORD
    dwPosition AS DWORD
    dwPeriod   AS DWORD
    dwUserParm AS DWORD
END TYPE

' parameter block for MCI_VCR_STATUS command message
TYPE MCI_VCR_STATUS_PARMS
    dwCallback AS DWORD
    dwReturn   AS DWORD
    dwItem     AS DWORD
    dwTrack    AS DWORD
    dwNumber   AS DWORD
END TYPE

' parameter block for MCI_SETVIDEO command message
TYPE MCI_VCR_SETVIDEO_PARMS
    dwCallback AS DWORD
    dwTrack    AS DWORD
    dwTo       AS DWORD
    dwNumber   AS DWORD
END TYPE

' parameter block for MCI_STEP command message
TYPE MCI_VCR_STEP_PARMS
    dwCallback AS DWORD
    dwFrames   AS DWORD
END TYPE

' parameter block for MCI_CUE command message
TYPE MCI_VCR_CUE_PARMS
    dwCallback AS DWORD
    dwFrom     AS DWORD
    dwTo       AS DWORD
END TYPE



' VCR error codes
%MCIERR_VCR_CANNOT_OPEN_COMM    = %MCIERR_CUSTOM_DRIVER_BASE + 1
%MCIERR_VCR_CANNOT_WRITE_COMM   = %MCIERR_CUSTOM_DRIVER_BASE + 2
%MCIERR_VCR_READ_TIMEOUT        = %MCIERR_CUSTOM_DRIVER_BASE + 3
%MCIERR_VCR_COMMAND_BUFFER_FULL = %MCIERR_CUSTOM_DRIVER_BASE + 4
%MCIERR_VCR_COMMAND_CANCELLED   = %MCIERR_CUSTOM_DRIVER_BASE + 5
%MCIERR_VCR_POWER_OFF           = %MCIERR_CUSTOM_DRIVER_BASE + 6
%MCIERR_VCR_COMMAND_FAILED      = %MCIERR_CUSTOM_DRIVER_BASE + 7
%MCIERR_VCR_SEARCH              = %MCIERR_CUSTOM_DRIVER_BASE + 8
%MCIERR_VCR_CONDITION           = %MCIERR_CUSTOM_DRIVER_BASE + 9
%MCIERR_VCR_CAMERA_MODE         = %MCIERR_CUSTOM_DRIVER_BASE + 10
%MCIERR_VCR_VCR_MODE            = %MCIERR_CUSTOM_DRIVER_BASE + 11
%MCIERR_VCR_COUNTER_TYPE        = %MCIERR_CUSTOM_DRIVER_BASE + 12
%MCIERR_VCR_TUNER               = %MCIERR_CUSTOM_DRIVER_BASE + 13
%MCIERR_VCR_EMERGENCY_STOP      = %MCIERR_CUSTOM_DRIVER_BASE + 14
%MCIERR_VCR_MEDIA_UNMOUNTED     = %MCIERR_CUSTOM_DRIVER_BASE + 15
%MCIERR_VCR_REGISTER            = %MCIERR_CUSTOM_DRIVER_BASE + 16
%MCIERR_VCR_TRACK_FAILURE       = %MCIERR_CUSTOM_DRIVER_BASE + 17
%MCIERR_VCR_CUE_FAILED_FLAGS    = %MCIERR_CUSTOM_DRIVER_BASE + 18
%MCIERR_VCR_ISWRITEPROTECTED    = %MCIERR_CUSTOM_DRIVER_BASE + 19
