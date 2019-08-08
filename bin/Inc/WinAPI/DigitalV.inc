'------------------------------------------------------------------------------
'
'  DIGITALV.inc -- Media Control Interface / Digital Video Command Set support
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
' from digitalv.h version 1.0 "of 19 Aug 1992", dated 14 Jul 2009
'------------------------------------------------------------------------------


#INCLUDE THIS ONCE

%DIGITALV_INC = 100

#INCLUDE "MMSystem.inc"


%MCI_TEST = &H00000020

' Message values

%MCI_CAPTURE   = &H0870
%MCI_MONITOR   = &H0871
%MCI_RESERVE   = &H0872
%MCI_SETAUDIO  = &H0873
%MCI_SIGNAL    = &H0875
%MCI_SETVIDEO  = &H0876
%MCI_QUALITY   = &H0877
%MCI_LIST      = &H0878
%MCI_UNDO      = &H0879
%MCI_CONFIGURE = &H087a
%MCI_RESTORE   = &H087b

' Return and string constant values

%MCI_ON  = 1
%MCI_OFF = 0

%MCI_DGV_FILE_MODE_SAVING            = &H0001
%MCI_DGV_FILE_MODE_LOADING           = &H0002
%MCI_DGV_FILE_MODE_EDITING           = &H0003
%MCI_DGV_FILE_MODE_IDLE              = &H0004

' These identifiers are used only by device drivers

%MCI_ON_S                            = &H00008000
%MCI_OFF_S                           = &H00008001
%MCI_DGV_FILE_S                      = &H00008002
%MCI_DGV_INPUT_S                     = &H00008003

%MCI_DGV_FILE_MODE_SAVING_S          = &H00008004
%MCI_DGV_FILE_MODE_LOADING_S         = &H00008005
%MCI_DGV_FILE_MODE_EDITING_S         = &H00008006
%MCI_DGV_FILE_MODE_IDLE_S            = &H00008007

%MCI_DGV_SETVIDEO_SRC_NTSC_S         = &H00008010
%MCI_DGV_SETVIDEO_SRC_RGB_S          = &H00008011
%MCI_DGV_SETVIDEO_SRC_SVIDEO_S       = &H00008012
%MCI_DGV_SETVIDEO_SRC_PAL_S          = &H00008013
%MCI_DGV_SETVIDEO_SRC_SECAM_S        = &H00008014
%MCI_DGV_SETVIDEO_SRC_GENERIC_S      = &H00008015

%MCI_DGV_SETAUDIO_SRC_LEFT_S         = &H00008020
%MCI_DGV_SETAUDIO_SRC_RIGHT_S        = &H00008021
%MCI_DGV_SETAUDIO_SRC_AVERAGE_S      = &H00008022
%MCI_DGV_SETAUDIO_SRC_STEREO_S       = &H00008023

' Window message for signal notification

%MM_MCISIGNAL                        = &H3CB

' error values

%MCIERR_DGV_DEVICE_LIMIT             = %MCIERR_CUSTOM_DRIVER_BASE
%MCIERR_DGV_IOERR                    = %MCIERR_CUSTOM_DRIVER_BASE + 1
%MCIERR_DGV_WORKSPACE_EMPTY          = %MCIERR_CUSTOM_DRIVER_BASE + 2
%MCIERR_DGV_DISK_FULL                = %MCIERR_CUSTOM_DRIVER_BASE + 3
%MCIERR_DGV_DEVICE_MEMORY_FULL       = %MCIERR_CUSTOM_DRIVER_BASE + 4
%MCIERR_DGV_BAD_CLIPBOARD_RANGE      = %MCIERR_CUSTOM_DRIVER_BASE + 5

' defines for monitor methods

%MCI_DGV_METHOD_PRE                  = &H0000A000
%MCI_DGV_METHOD_POST                 = &H0000A001
%MCI_DGV_METHOD_DIRECT               = &H0000A002

' defines for known file formats

%MCI_DGV_FF_AVSS                     = &H00004000
%MCI_DGV_FF_AVI                      = &H00004001
%MCI_DGV_FF_DIB                      = &H00004002
%MCI_DGV_FF_RDIB                     = &H00004003
%MCI_DGV_FF_JPEG                     = &H00004004
%MCI_DGV_FF_RJPEG                    = &H00004005
%MCI_DGV_FF_JFIF                     = &H00004006
%MCI_DGV_FF_MPEG                     = &H00004007

' values for dwItem field of MCI_CAPABILITY_PARMS structure

%MCI_DGV_GETDEVCAPS_CAN_LOCK         = &H00004000
%MCI_DGV_GETDEVCAPS_CAN_STRETCH      = &H00004001
%MCI_DGV_GETDEVCAPS_CAN_FREEZE       = &H00004002
%MCI_DGV_GETDEVCAPS_MAX_WINDOWS      = &H00004003
%MCI_DGV_GETDEVCAPS_CAN_REVERSE      = &H00004004
%MCI_DGV_GETDEVCAPS_HAS_STILL        = &H00004005
%MCI_DGV_GETDEVCAPS_PALETTES         = &H00004006
%MCI_DGV_GETDEVCAPS_CAN_STR_IN       = &H00004008
%MCI_DGV_GETDEVCAPS_CAN_TEST         = &H00004009
%MCI_DGV_GETDEVCAPS_MAXIMUM_RATE     = &H0000400A
%MCI_DGV_GETDEVCAPS_MINIMUM_RATE     = &H0000400B

' flags for dwFlags parameter of MCI_CAPTURE command message

%MCI_DGV_CAPTURE_AS                  = &H00010000
%MCI_DGV_CAPTURE_AT                  = &H00020000

' flags for dwFlags parameter of MCI_COPY command message

%MCI_DGV_COPY_AT                     = &H00010000
%MCI_DGV_COPY_AUDIO_STREAM           = &H00020000
%MCI_DGV_COPY_VIDEO_STREAM           = &H00040000

' flags for dwFlags parameter of MCI_CUE command message

%MCI_DGV_CUE_INPUT                   = &H00010000
%MCI_DGV_CUE_OUTPUT                  = &H00020000
%MCI_DGV_CUE_NOSHOW                  = &H00040000

' flags for dwFlags parameter of MCI_CUT command message

%MCI_DGV_CUT_AT                      = &H00010000
%MCI_DGV_CUT_AUDIO_STREAM            = &H00020000
%MCI_DGV_CUT_VIDEO_STREAM            = &H00040000

' flags for dwFlags parameter of MCI_DELETE command message

%MCI_DGV_DELETE_AT                   = &H00010000
%MCI_DGV_DELETE_AUDIO_STREAM         = &H00020000
%MCI_DGV_DELETE_VIDEO_STREAM         = &H00040000

' flags for dwFlags parameter of MCI_FREEZE command message

%MCI_DGV_FREEZE_AT                   = &H00010000
%MCI_DGV_FREEZE_OUTSIDE              = &H00020000

' flags for dwFlags parameter of MCI_INFO command message

%MCI_DGV_INFO_TEXT                   = &H00010000
%MCI_DGV_INFO_ITEM                   = &H00020000

' values for dwItem field of MCI_DGV_INFO_PARMS structure

%MCI_INFO_VERSION                    = &H00000400

%MCI_DGV_INFO_USAGE                  = &H00004000
%MCI_DGV_INFO_AUDIO_QUALITY          = &H00004001
%MCI_DGV_INFO_STILL_QUALITY          = &H00004002
%MCI_DGV_INFO_VIDEO_QUALITY          = &H00004003
%MCI_DGV_INFO_AUDIO_ALG              = &H00004004
%MCI_DGV_INFO_STILL_ALG              = &H00004005
%MCI_DGV_INFO_VIDEO_ALG              = &H00004006

' flags for dwFlags parameter of MCI_LIST command message

%MCI_DGV_LIST_ITEM                   = &H00010000
%MCI_DGV_LIST_COUNT                  = &H00020000
%MCI_DGV_LIST_NUMBER                 = &H00040000
%MCI_DGV_LIST_ALG                    = &H00080000

' values for dwItem field of MCI_DGV_LIST_PARMS structure

%MCI_DGV_LIST_AUDIO_ALG              = &H00004000
%MCI_DGV_LIST_AUDIO_QUALITY          = &H00004001
%MCI_DGV_LIST_AUDIO_STREAM           = &H00004002
%MCI_DGV_LIST_STILL_ALG              = &H00004003
%MCI_DGV_LIST_STILL_QUALITY          = &H00004004
%MCI_DGV_LIST_VIDEO_ALG              = &H00004005
%MCI_DGV_LIST_VIDEO_QUALITY          = &H00004006
%MCI_DGV_LIST_VIDEO_STREAM           = &H00004007
%MCI_DGV_LIST_VIDEO_SOURCE           = &H00004008


' flags for dwFlags parameter of MCI_MONITOR command message

%MCI_DGV_MONITOR_METHOD              = &H00010000
%MCI_DGV_MONITOR_SOURCE              = &H00020000

' values for dwSource parameter of the MCI_DGV_MONITOR_PARMS struture

%MCI_DGV_MONITOR_INPUT               = &H00004000
%MCI_DGV_MONITOR_FILE                = &H00004001

' flags for dwFlags parameter of MCI_OPEN command message

%MCI_DGV_OPEN_WS                     = &H00010000
%MCI_DGV_OPEN_PARENT                 = &H00020000
%MCI_DGV_OPEN_NOSTATIC               = &H00040000
%MCI_DGV_OPEN_16BIT                  = &H00080000
%MCI_DGV_OPEN_32BIT                  = &H00100000

' flags for dwFlags parameter of MCI_PASTE command message

%MCI_DGV_PASTE_AT                    = &H00010000
%MCI_DGV_PASTE_AUDIO_STREAM          = &H00020000
%MCI_DGV_PASTE_VIDEO_STREAM          = &H00040000
%MCI_DGV_PASTE_INSERT                = &H00080000
%MCI_DGV_PASTE_OVERWRITE             = &H00100000

' flags for dwFlags parameter of MCI_PLAY command message

%MCI_DGV_PLAY_REPEAT                 = &H00010000
%MCI_DGV_PLAY_REVERSE                = &H00020000

' flags for dwFlags parameter of MCI_PUT command message

%MCI_DGV_RECT                        = &H00010000
%MCI_DGV_PUT_SOURCE                  = &H00020000
%MCI_DGV_PUT_DESTINATION             = &H00040000
%MCI_DGV_PUT_FRAME                   = &H00080000
%MCI_DGV_PUT_VIDEO                   = &H00100000
%MCI_DGV_PUT_WINDOW                  = &H00200000
%MCI_DGV_PUT_CLIENT                  = &H00400000

' flags for dwFlags parameter of MCI_QUALITY command message

%MCI_QUALITY_ITEM                    = &H00010000
%MCI_QUALITY_NAME                    = &H00020000
%MCI_QUALITY_ALG                     = &H00040000
%MCI_QUALITY_DIALOG                  = &H00080000
%MCI_QUALITY_HANDLE                  = &H00100000

' values for dwItem field of MCI_QUALITY_PARMS structure

%MCI_QUALITY_ITEM_AUDIO              = &H00004000
%MCI_QUALITY_ITEM_STILL              = &H00004001
%MCI_QUALITY_ITEM_VIDEO              = &H00004002

' flags for dwFlags parameter of MCI_REALIZE command message

%MCI_DGV_REALIZE_NORM                = &H00010000
%MCI_DGV_REALIZE_BKGD                = &H00020000

' flags for dwFlags parameter of MCI_RECORD command message

%MCI_DGV_RECORD_HOLD                 = &H00020000
%MCI_DGV_RECORD_AUDIO_STREAM         = &H00040000
%MCI_DGV_RECORD_VIDEO_STREAM         = &H00080000

' flags for dwFlags parameters of MCI_RESERVE command message

%MCI_DGV_RESERVE_IN                  = &H00010000
%MCI_DGV_RESERVE_SIZE                = &H00020000

' flags for dwFlags parameter of MCI_RESTORE command message

%MCI_DGV_RESTORE_FROM                = &H00010000
%MCI_DGV_RESTORE_AT                  = &H00020000

' flags for dwFlags parameters of MCI_SAVE command message

%MCI_DGV_SAVE_ABORT                  = &H00020000
%MCI_DGV_SAVE_KEEPRESERVE            = &H00040000

' flags for dwFlags parameters of MCI_SET command message

%MCI_DGV_SET_SEEK_EXACTLY            = &H00010000
%MCI_DGV_SET_SPEED                   = &H00020000
%MCI_DGV_SET_STILL                   = &H00040000
%MCI_DGV_SET_FILEFORMAT              = &H00080000

' flags for the dwFlags parameter of MCI_SETAUDIO command message

%MCI_DGV_SETAUDIO_OVER               = &H00010000
%MCI_DGV_SETAUDIO_CLOCKTIME          = &H00020000
%MCI_DGV_SETAUDIO_ALG                = &H00040000
%MCI_DGV_SETAUDIO_QUALITY            = &H00080000
%MCI_DGV_SETAUDIO_RECORD             = &H00100000
%MCI_DGV_SETAUDIO_LEFT               = &H00200000
%MCI_DGV_SETAUDIO_RIGHT              = &H00400000
%MCI_DGV_SETAUDIO_ITEM               = &H00800000
%MCI_DGV_SETAUDIO_VALUE              = &H01000000
%MCI_DGV_SETAUDIO_INPUT              = &H02000000
%MCI_DGV_SETAUDIO_OUTPUT             = &H04000000

' values for the dwItem parameter of MCI_DGV_SETAUDIO_PARMS

%MCI_DGV_SETAUDIO_TREBLE             = &H00004000
%MCI_DGV_SETAUDIO_BASS               = &H00004001
%MCI_DGV_SETAUDIO_VOLUME             = &H00004002
%MCI_DGV_SETAUDIO_STREAM             = &H00004003
%MCI_DGV_SETAUDIO_SOURCE             = &H00004004
%MCI_DGV_SETAUDIO_SAMPLESPERSEC      = &H00004005
%MCI_DGV_SETAUDIO_AVGBYTESPERSEC     = &H00004006
%MCI_DGV_SETAUDIO_BLOCKALIGN         = &H00004007
%MCI_DGV_SETAUDIO_BITSPERSAMPLE      = &H00004008

' values for the dwValue parameter of MCI_DGV_SETAUDIO_PARMS
' used with MCI_DGV_SETAUDIO_SOURCE

%MCI_DGV_SETAUDIO_SOURCE_STEREO      = &H00000000
%MCI_DGV_SETAUDIO_SOURCE_LEFT        = &H00000001
%MCI_DGV_SETAUDIO_SOURCE_RIGHT       = &H00000002
%MCI_DGV_SETAUDIO_SOURCE_AVERAGE     = &H00004000

' flags for the dwFlags parameter of MCI_SETVIDEO command

%MCI_DGV_SETVIDEO_QUALITY            = &H00010000
%MCI_DGV_SETVIDEO_ALG                = &H00020000
%MCI_DGV_SETVIDEO_CLOCKTIME          = &H00040000
%MCI_DGV_SETVIDEO_SRC_NUMBER         = &H00080000
%MCI_DGV_SETVIDEO_ITEM               = &H00100000
%MCI_DGV_SETVIDEO_OVER               = &H00200000
%MCI_DGV_SETVIDEO_RECORD             = &H00400000
%MCI_DGV_SETVIDEO_STILL              = &H00800000
%MCI_DGV_SETVIDEO_VALUE              = &H01000000
%MCI_DGV_SETVIDEO_INPUT              = &H02000000
%MCI_DGV_SETVIDEO_OUTPUT             = &H04000000

' values for the dwTo field of MCI_SETVIDEO_PARMS
' used with MCI_DGV_SETVIDEO_SOURCE

%MCI_DGV_SETVIDEO_SRC_NTSC           = &H00004000
%MCI_DGV_SETVIDEO_SRC_RGB            = &H00004001
%MCI_DGV_SETVIDEO_SRC_SVIDEO         = &H00004002
%MCI_DGV_SETVIDEO_SRC_PAL            = &H00004003
%MCI_DGV_SETVIDEO_SRC_SECAM          = &H00004004
%MCI_DGV_SETVIDEO_SRC_GENERIC        = &H00004005

' values for the dwItem field of MCI_SETVIDEO_PARMS

%MCI_DGV_SETVIDEO_BRIGHTNESS         = &H00004000
%MCI_DGV_SETVIDEO_COLOR              = &H00004001
%MCI_DGV_SETVIDEO_CONTRAST           = &H00004002
%MCI_DGV_SETVIDEO_TINT               = &H00004003
%MCI_DGV_SETVIDEO_SHARPNESS          = &H00004004
%MCI_DGV_SETVIDEO_GAMMA              = &H00004005
%MCI_DGV_SETVIDEO_STREAM             = &H00004006
%MCI_DGV_SETVIDEO_PALHANDLE          = &H00004007
%MCI_DGV_SETVIDEO_FRAME_RATE         = &H00004008
%MCI_DGV_SETVIDEO_SOURCE             = &H00004009
%MCI_DGV_SETVIDEO_KEY_INDEX          = &H0000400A
%MCI_DGV_SETVIDEO_KEY_COLOR          = &H0000400B
%MCI_DGV_SETVIDEO_BITSPERPEL         = &H0000400C

' flags for the dwFlags parameter of MCI_SIGNAL

%MCI_DGV_SIGNAL_AT                   = &H00010000
%MCI_DGV_SIGNAL_EVERY                = &H00020000
%MCI_DGV_SIGNAL_USERVAL              = &H00040000
%MCI_DGV_SIGNAL_CANCEL               = &H00080000
%MCI_DGV_SIGNAL_POSITION             = &H00100000

' The following is the function digitalvideo drivers must use
' to signal when a frame marked by the SIGNAL command has been rendered:
'
'  SEND_DGVSIGNAL(dwFlags, dwCallback, hDriver, wDeviceID, dwUser, dwPos )
'
' The following is a description of the parameters:
'
'  dwFlags    - the dwFlags parameter passed when the signal was set
'  dwCallback - the dwCallback value from the MCI_DGV_SIGNAL_PARMS struct
'               used to set the signal
'  hDriver    - the handle assigned to the driver by MMSYSTEM when the
'               device was opened
'  wDeviceID  - the device ID
'  dwUser     - the dwUserParm value from the MCI_DGV_SIGNAL_PARMS struct
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
'          at; the latter if the MCI_DGV_SIGNAL_POSITION flag was set
'          in the dwFlags parameter when the signal was created.
'

'#define SEND_DGVSIGNAL(dwFlags, dwCallback, hDriver, wDeviceID, dwUser, dwPos ) \
'  DriverCallback( (dwCallback), DCB_WINDOW, (HANDLE)(wDeviceID), MM_MCISIGNAL,\
'  hDriver, ((dwFlags) & MCI_DGV_SIGNAL_POSITION) ? (dwPos):(dwUser),\
'  ((dwFlags) & MCI_DGV_SIGNAL_POSITION) ? (dwUser):(dwPos))

' flags for the dwFlags parameter of MCI_STATUS command

%MCI_DGV_STATUS_NOMINAL              = &H00020000
%MCI_DGV_STATUS_REFERENCE            = &H00040000
%MCI_DGV_STATUS_LEFT                 = &H00080000
%MCI_DGV_STATUS_RIGHT                = &H00100000
%MCI_DGV_STATUS_DISKSPACE            = &H00200000
%MCI_DGV_STATUS_INPUT                = &H00400000
%MCI_DGV_STATUS_OUTPUT               = &H00800000
%MCI_DGV_STATUS_RECORD               = &H01000000

' values for dwItem field of MCI_STATUS_PARMS structure

%MCI_DGV_STATUS_AUDIO_INPUT          = &H00004000
%MCI_DGV_STATUS_HWND                 = &H00004001
%MCI_DGV_STATUS_SPEED                = &H00004003
%MCI_DGV_STATUS_HPAL                 = &H00004004
%MCI_DGV_STATUS_BRIGHTNESS           = &H00004005
%MCI_DGV_STATUS_COLOR                = &H00004006
%MCI_DGV_STATUS_CONTRAST             = &H00004007
%MCI_DGV_STATUS_FILEFORMAT           = &H00004008
%MCI_DGV_STATUS_AUDIO_SOURCE         = &H00004009
%MCI_DGV_STATUS_GAMMA                = &H0000400A
%MCI_DGV_STATUS_MONITOR              = &H0000400B
%MCI_DGV_STATUS_MONITOR_METHOD       = &H0000400C
%MCI_DGV_STATUS_FRAME_RATE           = &H0000400E
%MCI_DGV_STATUS_BASS                 = &H0000400F
%MCI_DGV_STATUS_SIZE                 = &H00004010
%MCI_DGV_STATUS_SEEK_EXACTLY         = &H00004011
%MCI_DGV_STATUS_SHARPNESS            = &H00004012
%MCI_DGV_STATUS_SMPTE                = &H00004013
%MCI_DGV_STATUS_AUDIO                = &H00004014
%MCI_DGV_STATUS_TINT                 = &H00004015
%MCI_DGV_STATUS_TREBLE               = &H00004016
%MCI_DGV_STATUS_UNSAVED              = &H00004017
%MCI_DGV_STATUS_VIDEO                = &H00004018
%MCI_DGV_STATUS_VOLUME               = &H00004019
%MCI_DGV_STATUS_AUDIO_RECORD         = &H0000401A
%MCI_DGV_STATUS_VIDEO_SOURCE         = &H0000401B
%MCI_DGV_STATUS_VIDEO_RECORD         = &H0000401C
%MCI_DGV_STATUS_STILL_FILEFORMAT     = &H0000401D
%MCI_DGV_STATUS_VIDEO_SRC_NUM        = &H0000401E
%MCI_DGV_STATUS_FILE_MODE            = &H0000401F
%MCI_DGV_STATUS_FILE_COMPLETION      = &H00004020
%MCI_DGV_STATUS_WINDOW_VISIBLE       = &H00004021
%MCI_DGV_STATUS_WINDOW_MINIMIZED     = &H00004022
%MCI_DGV_STATUS_WINDOW_MAXIMIZED     = &H00004023
%MCI_DGV_STATUS_KEY_INDEX            = &H00004024
%MCI_DGV_STATUS_KEY_COLOR            = &H00004025
%MCI_DGV_STATUS_PAUSE_MODE           = &H00004026
%MCI_DGV_STATUS_SAMPLESPERSEC        = &H00004027
%MCI_DGV_STATUS_AVGBYTESPERSEC       = &H00004028
%MCI_DGV_STATUS_BLOCKALIGN           = &H00004029
%MCI_DGV_STATUS_BITSPERSAMPLE        = &H0000402A
%MCI_DGV_STATUS_BITSPERPEL           = &H0000402B
%MCI_DGV_STATUS_FORWARD              = &H0000402C
%MCI_DGV_STATUS_AUDIO_STREAM         = &H0000402D
%MCI_DGV_STATUS_VIDEO_STREAM         = &H0000402E

' flags for dwFlags parameter of MCI_STEP command message

%MCI_DGV_STEP_REVERSE                = &H00010000
%MCI_DGV_STEP_FRAMES                 = &H00020000

' flags for dwFlags parameter of MCI_STOP command message

%MCI_DGV_STOP_HOLD                   = &H00010000

' flags for dwFlags parameter of MCI_UPDATE command message

%MCI_DGV_UPDATE_HDC                  = &H00020000
%MCI_DGV_UPDATE_PAINT                = &H00040000

' flags for dwFlags parameter of MCI_WHERE command message

%MCI_DGV_WHERE_SOURCE                = &H00020000
%MCI_DGV_WHERE_DESTINATION           = &H00040000
%MCI_DGV_WHERE_FRAME                 = &H00080000
%MCI_DGV_WHERE_VIDEO                 = &H00100000
%MCI_DGV_WHERE_WINDOW                = &H00200000
%MCI_DGV_WHERE_MAX                   = &H00400000

' flags for dwFlags parameter of MCI_WINDOW command message

%MCI_DGV_WINDOW_HWND                 = &H00010000
%MCI_DGV_WINDOW_STATE                = &H00040000
%MCI_DGV_WINDOW_TEXT                 = &H00080000

' flags for hWnd parameter of MCI_DGV_WINDOW_PARMS parameter block

%MCI_DGV_WINDOW_DEFAULT              = &H00000000

' parameter block for MCI_WHERE, MCI_PUT, MCI_FREEZE, MCI_UNFREEZE cmds

TYPE MCI_DGV_RECT_PARMS
    dwCallback AS DWORD
#IF %DEF(%MCI_USR_OFFEXT)
    ptOffset   AS POINT
    ptExtent   AS POINT
#ELSE
    rc         AS RECT
#ENDIF
END TYPE

' parameter block for MCI_CAPTURE command message

TYPE MCI_DGV_CAPTURE_PARMSA
    dwCallback    AS DWORD
    lpstrFileName AS ASCIIZ PTR
#IF %DEF(%MCI_USR_OFFEXT)
    ptOffset   AS POINT
    ptExtent   AS POINT
#ELSE
    rc         AS RECT
#ENDIF
END TYPE

TYPE MCI_DGV_CAPTURE_PARMSW
    dwCallback    AS DWORD
    lpstrFileName AS WSTRINGZ PTR
#IF %DEF(%MCI_USR_OFFEXT)
    ptOffset   AS POINT
    ptExtent   AS POINT
#ELSE
    rc         AS RECT
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_DGV_CAPTURE_PARMS
    MCI_DGV_CAPTURE_PARMSW
END TYPE
#ELSE
TYPE MCI_DGV_CAPTURE_PARMS
    MCI_DGV_CAPTURE_PARMSA
END TYPE
#ENDIF

' parameter block for MCI_CLOSE command message

TYPE MCI_CLOSE_PARMS
    dwCallback AS DWORD
END TYPE

' parameter block for MCI_COPY command message

TYPE MCI_DGV_COPY_PARMS
    dwCallback    AS DWORD
    dwFrom        AS DWORD
    dwTo          AS DWORD
#IF %DEF(%MCI_USR_OFFEXT)
    ptOffset   AS POINT
    ptExtent   AS POINT
#ELSE
    rc         AS RECT
#ENDIF
    dwAudioStream AS DWORD
    dwVideoStream AS DWORD
END TYPE

' parameter block for MCI_CUE command message

TYPE MCI_DGV_CUE_PARMS
    dwCallback AS DWORD
    dwTo       AS DWORD
END TYPE

' parameter block for MCI_CUT command message

TYPE MCI_DGV_CUT_PARMS
    dwCallback    AS DWORD
    dwFrom        AS DWORD
    dwTo          AS DWORD
#IF %DEF(%MCI_USR_OFFEXT)
    ptOffset   AS POINT
    ptExtent   AS POINT
#ELSE
    rc         AS RECT
#ENDIF
    dwAudioStream AS DWORD
    dwVideoStream AS DWORD
END TYPE

' parameter block for MCI_DELETE command message

TYPE MCI_DGV_DELETE_PARMS
    dwCallback    AS DWORD
    dwFrom        AS DWORD
    dwTo          AS DWORD
#IF %DEF(%MCI_USR_OFFEXT)
    ptOffset   AS POINT
    ptExtent   AS POINT
#ELSE
    rc         AS RECT
#ENDIF
    dwAudioStream AS DWORD
    dwVideoStream AS DWORD
END TYPE

' parameter block for MCI_FREEZE command message

TYPE MCI_DGV_FREEZE_PARMS
    dwCallback AS DWORD
#IF %DEF(%MCI_USR_OFFEXT)
    ptOffset   AS POINT
    ptExtent   AS POINT
#ELSE
    rc         AS RECT
#ENDIF
END TYPE

' parameter block for MCI_INFO command message

TYPE MCI_DGV_INFO_PARMSA
    dwCallback  AS DWORD
    lpstrReturn AS ASCIIZ PTR
    dwRetSize   AS DWORD
    dwItem      AS DWORD
END TYPE

TYPE MCI_DGV_INFO_PARMSW
    dwCallback  AS DWORD
    lpstrReturn AS WSTRINGZ PTR
    dwRetSize   AS DWORD
    dwItem      AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_DGV_INFO_PARMS
    MCI_DGV_INFO_PARMSW
END TYPE
#ELSE
TYPE MCI_DGV_INFO_PARMS
    MCI_DGV_INFO_PARMSA
END TYPE
#ENDIF

' parameter block for MCI_LIST command message

TYPE MCI_DGV_LIST_PARMSA
    dwCallback     AS DWORD
    lpstrReturn    AS ASCIIZ PTR
    dwLength       AS DWORD
    dwNumber       AS DWORD
    dwItem         AS DWORD
    lpstrAlgorithm AS ASCIIZ PTR
END TYPE

TYPE MCI_DGV_LIST_PARMSW
    dwCallback     AS DWORD
    lpstrReturn    AS WSTRINGZ PTR
    dwLength       AS DWORD
    dwNumber       AS DWORD
    dwItem         AS DWORD
    lpstrAlgorithm AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_DGV_LIST_PARMS
    MCI_DGV_LIST_PARMSW
END TYPE
#ELSE
TYPE MCI_DGV_LIST_PARMS
    MCI_DGV_LIST_PARMSA
END TYPE
#ENDIF

' parameter block for MCI_LOAD command message

TYPE MCI_DGV_LOAD_PARMSA
    dwCallback AS DWORD
    lpFileName AS ASCIIZ PTR
END TYPE

TYPE MCI_DGV_LOAD_PARMSW
    dwCallback AS DWORD
    lpFileName AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_DGV_LOAD_PARMS
    MCI_DGV_LOAD_PARMSW
END TYPE
#ELSE
TYPE MCI_DGV_LOAD_PARMS
    MCI_DGV_LOAD_PARMSA
END TYPE
#ENDIF

' parameter block for MCI_MONITOR command message

TYPE MCI_DGV_MONITOR_PARMS
    dwCallback AS DWORD
    dwSource   AS DWORD
    dwMethod   AS DWORD
END TYPE

' parameter block for MCI_OPEN command message

TYPE MCI_DGV_OPEN_PARMSA
    dwCallback       AS DWORD
    wDeviceID        AS DWORD
    lpstrDeviceType  AS ASCIIZ PTR
    lpstrElementName AS ASCIIZ PTR
    lpstrAlias       AS ASCIIZ PTR
    dwStyle          AS DWORD
    hWndParent       AS DWORD
END TYPE

TYPE MCI_DGV_OPEN_PARMSW
    dwCallback       AS DWORD
    wDeviceID        AS DWORD
    lpstrDeviceType  AS WSTRINGZ PTR
    lpstrElementName AS WSTRINGZ PTR
    lpstrAlias       AS WSTRINGZ PTR
    dwStyle          AS DWORD
    hWndParent       AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_DGV_OPEN_PARMS
    MCI_DGV_OPEN_PARMSW
END TYPE
#ELSE
TYPE MCI_DGV_OPEN_PARMS
    MCI_DGV_OPEN_PARMSA
END TYPE
#ENDIF

' parameter block for MCI_PAUSE command message

TYPE MCI_DGV_PAUSE_PARMS
    dwCallback AS DWORD
END TYPE

' parameter block for MCI_PASTE command message

TYPE MCI_DGV_PASTE_PARMS
    dwCallback    AS DWORD
    dwTo          AS DWORD
#IF %DEF(%MCI_USR_OFFEXT)
    ptOffset   AS POINT
    ptExtent   AS POINT
#ELSE
    rc         AS RECT
#ENDIF
    dwAudioStream AS DWORD
    dwVideoStream AS DWORD
END TYPE

' parameter block for MCI_PLAY command message

TYPE MCI_DGV_PLAY_PARMS
    MCI_PLAY_PARMS
END TYPE

' parameter block for MCI_PUT command message

TYPE MCI_DGV_PUT_PARMS
    MCI_DGV_RECT_PARMS
END TYPE

' parameter block for MCI_QUALITY command message

TYPE MCI_DGV_QUALITY_PARMSA
    dwCallback     AS DWORD
    dwItem         AS DWORD
    lpstrName      AS ASCIIZ PTR
    lpstrAlgorithm AS DWORD
    dwHandle       AS DWORD
END TYPE

TYPE MCI_DGV_QUALITY_PARMSW
    dwCallback     AS DWORD
    dwItem         AS DWORD
    lpstrName      AS WSTRINGZ PTR
    lpstrAlgorithm AS DWORD
    dwHandle       AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_DGV_QUALITY_PARMS
    MCI_DGV_QUALITY_PARMSW
END TYPE
#ELSE
TYPE MCI_DGV_QUALITY_PARMS
    MCI_DGV_QUALITY_PARMSA
END TYPE
#ENDIF

' parameter block for MCI_REALIZE command message

TYPE MCI_REALIZE_PARMS
    MCI_GENERIC_PARMS
END TYPE

' parameter block for MCI_RECORD command message

TYPE MCI_DGV_RECORD_PARMS
    dwCallback    AS DWORD
    dwFrom        AS DWORD
    dwTo          AS DWORD
#IF %DEF(%MCI_USR_OFFEXT)
    ptOffset   AS POINT
    ptExtent   AS POINT
#ELSE
    rc         AS RECT
#ENDIF
    dwAudioStream AS DWORD
    dwVideoStream AS DWORD
END TYPE

' parameter block for MCI_RESERVE command message

TYPE MCI_DGV_RESERVE_PARMSA
    dwCallback AS DWORD
    lpstrPath  AS ASCIIZ PTR
    dwSize     AS DWORD
END TYPE

TYPE MCI_DGV_RESERVE_PARMSW
    dwCallback AS DWORD
    lpstrPath  AS WSTRINGZ PTR
    dwSize     AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_DGV_RESERVE_PARMS
    MCI_DGV_RESERVE_PARMSW
END TYPE
#ELSE
TYPE MCI_DGV_RESERVE_PARMS
    MCI_DGV_RESERVE_PARMSA
END TYPE
#ENDIF

' parameter block for MCI_RESTORE command message

TYPE MCI_DGV_RESTORE_PARMSA
    dwCallback    AS DWORD
    lpstrFileName AS ASCIIZ PTR
#IF %DEF(%MCI_USR_OFFEXT)
    ptOffset   AS POINT
    ptExtent   AS POINT
#ELSE
    rc         AS RECT
#ENDIF
END TYPE

TYPE MCI_DGV_RESTORE_PARMSW
    dwCallback    AS DWORD
    lpstrFileName AS WSTRINGZ PTR
#IF %DEF(%MCI_USR_OFFEXT)
    ptOffset   AS POINT
    ptExtent   AS POINT
#ELSE
    rc         AS RECT
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_DGV_RESTORE_PARMS
    MCI_DGV_RESTORE_PARMSW
END TYPE
#ELSE
TYPE MCI_DGV_RESTORE_PARMS
    MCI_DGV_RESTORE_PARMSA
END TYPE
#ENDIF

' parameter block for MCI_RESUME command message

TYPE MCI_DGV_RESUME_PARMS
    MCI_GENERIC_PARMS
END TYPE

' parameter block for MCI_SAVE command message

TYPE MCI_DGV_SAVE_PARMSA
    dwCallback    AS DWORD
    lpstrFileName AS ASCIIZ PTR
#IF %DEF(%MCI_USR_OFFEXT)
    ptOffset   AS POINT
    ptExtent   AS POINT
#ELSE
    rc         AS RECT
#ENDIF
END TYPE

TYPE MCI_DGV_SAVE_PARMSW
    dwCallback    AS DWORD
    lpstrFileName AS WSTRINGZ PTR
#IF %DEF(%MCI_USR_OFFEXT)
    ptOffset   AS POINT
    ptExtent   AS POINT
#ELSE
    rc         AS RECT
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_DGV_SAVE_PARMS
    MCI_DGV_SAVE_PARMSW
END TYPE
#ELSE
TYPE MCI_DGV_SAVE_PARMS
    MCI_DGV_SAVE_PARMSA
END TYPE
#ENDIF

' parameter block for MCI_SET command message

TYPE MCI_DGV_SET_PARMS
    dwCallback   AS DWORD
    dwTimeFormat AS DWORD
    dwAudio      AS DWORD
    dwFileFormat AS DWORD
    dwSpeed      AS DWORD
END TYPE

' parameter block for MCI_SETAUDIO command message

TYPE MCI_DGV_SETAUDIO_PARMSA
    dwCallback     AS DWORD
    dwItem         AS DWORD
    dwValue        AS DWORD
    dwOver         AS DWORD
    lpstrAlgorithm AS ASCIIZ PTR
    lpstrQuality   AS ASCIIZ PTR
END TYPE

TYPE MCI_DGV_SETAUDIO_PARMSW
    dwCallback     AS DWORD
    dwItem         AS DWORD
    dwValue        AS DWORD
    dwOver         AS DWORD
    lpstrAlgorithm AS WSTRINGZ PTR
    lpstrQuality   AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_DGV_SETAUDIO_PARMS
    MCI_DGV_SETAUDIO_PARMSW
END TYPE
#ELSE
TYPE MCI_DGV_SETAUDIO_PARMS
    MCI_DGV_SETAUDIO_PARMSA
END TYPE
#ENDIF

' parameter block for MCI_SIGNAL command message

TYPE MCI_DGV_SIGNAL_PARMS
    dwCallback AS DWORD
    dwPosition AS DWORD
    dwPeriod   AS DWORD
    dwUserParm AS DWORD
END TYPE

' parameter block for MCI_SETVIDEO command message

TYPE MCI_DGV_SETVIDEO_PARMSA
    dwCallback     AS DWORD
    dwItem         AS DWORD
    dwValue        AS DWORD
    dwOver         AS DWORD
    lpstrAlgorithm AS ASCIIZ PTR
    lpstrQuality   AS ASCIIZ PTR
    dwSourceNumber AS DWORD
END TYPE

TYPE MCI_DGV_SETVIDEO_PARMSW
    dwCallback     AS DWORD
    dwItem         AS DWORD
    dwValue        AS DWORD
    dwOver         AS DWORD
    lpstrAlgorithm AS WSTRINGZ PTR
    lpstrQuality   AS WSTRINGZ PTR
    dwSourceNumber AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_DGV_SETVIDEO_PARMS
    MCI_DGV_SETVIDEO_PARMSW
END TYPE
#ELSE
TYPE MCI_DGV_SETVIDEO_PARMS
    MCI_DGV_SETVIDEO_PARMSA
END TYPE
#ENDIF

' parameter block for MCI_STATUS command message

TYPE MCI_DGV_STATUS_PARMSA
    dwCallback  AS DWORD
    dwReturn    AS DWORD
    dwItem      AS DWORD
    dwTrack     AS DWORD
    lpstrDrive  AS ASCIIZ PTR
    dwReference AS DWORD
END TYPE

TYPE MCI_DGV_STATUS_PARMSW
    dwCallback  AS DWORD
    dwReturn    AS DWORD
    dwItem      AS DWORD
    dwTrack     AS DWORD
    lpstrDrive  AS WSTRINGZ PTR
    dwReference AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_DGV_STATUS_PARMS
    MCI_DGV_STATUS_PARMSW
END TYPE
#ELSE
TYPE MCI_DGV_STATUS_PARMS
    MCI_DGV_STATUS_PARMSA
END TYPE
#ENDIF

' parameter block for MCI_STEP command message

TYPE MCI_DGV_STEP_PARMS
    dwCallback AS DWORD
    dwFrames   AS DWORD
END TYPE

' parameter block for MCI_STOP command message

TYPE MCI_DGV_STOP_PARMS
    MCI_GENERIC_PARMS
END TYPE

' parameter block for MCI_UNFREEZE command message

TYPE MCI_DGV_UNFREEZE_PARMS
    MCI_DGV_RECT_PARMS
END TYPE

' parameter block for MCI_UPDATE command message

TYPE MCI_DGV_UPDATE_PARMS
    dwCallback AS DWORD
#IF %DEF(%MCI_USR_OFFEXT)
    ptOffset   AS POINT
    ptExtent   AS POINT
#ELSE
    rc         AS RECT
#ENDIF
    hDC        AS DWORD
#IF NOT %DEF(%WIN32)
    wReserved0 AS WORD
#ENDIF
END TYPE

' parameter block for MCI_WHERE command message

TYPE MCI_DGV_WHERE_PARMS
    MCI_DGV_RECT_PARMS
END TYPE

' parameter block for MCI_WINDOW command message

TYPE MCI_DGV_WINDOW_PARMSA
    dwCallback AS DWORD
    hWnd       AS DWORD
#IF NOT %DEF(%WIN32)
    wReserved1 AS WORD
#ENDIF
    nCmdShow   AS DWORD
#IF NOT %DEF(%WIN32)
    wReserved2 AS WORD
#ENDIF
    lpstrText  AS ASCIIZ PTR
END TYPE

TYPE MCI_DGV_WINDOW_PARMSW
    dwCallback AS DWORD
    hWnd       AS DWORD
#IF NOT %DEF(%WIN32)
    wReserved1 AS WORD
#ENDIF
    nCmdShow   AS DWORD
#IF NOT %DEF(%WIN32)
    wReserved2 AS WORD
#ENDIF
    lpstrText  AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_DGV_WINDOW_PARMS
    MCI_DGV_WINDOW_PARMSW
END TYPE
#ELSE
TYPE MCI_DGV_WINDOW_PARMS
    MCI_DGV_WINDOW_PARMSA
END TYPE
#ENDIF ' %UNICODE
