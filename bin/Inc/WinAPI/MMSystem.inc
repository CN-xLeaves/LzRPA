'------------------------------------------------------------------------------
'
'  MMSystem.inc - Include file for Multimedia APIs
'
'  Copyright (c) 1997-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from MMSystem.h Version 4.00 dated 18 Jan 2008 and 14 Jul 2009
'------------------------------------------------------------------------------
'
'  Define:         Prevent inclusion of:
'  --------------  --------------------------------------------------------
'  %MMNODRV        Installable driver support
'  %MMNOSOUND      Sound support
'  %MMNOWAVE       Waveform support
'  %MMNOMIDI       MIDI support
'  %MMNOAUX        Auxiliary audio support
'  %MMNOMIXER      Mixer support
'  %MMNOTIMER      Timer support
'  %MMNOJOY        Joystick support
'  %MMNOMCI        MCI support
'  %MMNOMMIO       Multimedia file I/O support
'  %MMNOMMSYSTEM   General MMSYSTEM functions
'
'------------------------------------------------------------------------------


#INCLUDE THIS ONCE

%INC_MMSYSTEM = 1  ' defined if mmsystem.h has been included

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "WinDef.inc"


'****************************************************************************
'
'                   General constants and data types
'
'****************************************************************************


' general constants
%MAXPNAMELEN    = 32     ' max product name length (including NULL)
%MAXERRORLENGTH = 256    ' max error text length (including NULL)
%MAX_JOYSTICKOEMVXDNAME = 260 ' max oem vxd name length (including NULL)

'
'  Microsoft Manufacturer and Product IDs (these have been moved to
'  MMREG.H for Windows 4.00 and above).
'
#IF (%WINVER <= &H0400)
#IF NOT %DEF(%MM_MICROSOFT)
%MM_MICROSOFT         =  1   ' Microsoft Corporation
#ENDIF

#IF NOT %DEF(%MM_MIDI_MAPPER)
%MM_MIDI_MAPPER       =  1   ' MIDI Mapper
%MM_WAVE_MAPPER       =  2   ' Wave Mapper
%MM_SNDBLST_MIDIOUT   =  3   ' Sound Blaster MIDI output port
%MM_SNDBLST_MIDIIN    =  4   ' Sound Blaster MIDI input port
%MM_SNDBLST_SYNTH     =  5   ' Sound Blaster internal synthesizer
%MM_SNDBLST_WAVEOUT   =  6   ' Sound Blaster waveform output
%MM_SNDBLST_WAVEIN    =  7   ' Sound Blaster waveform input
%MM_ADLIB             =  9   ' Ad Lib-compatible synthesizer
%MM_MPU401_MIDIOUT    = 10   ' MPU401-compatible MIDI output port
%MM_MPU401_MIDIIN     = 11   ' MPU401-compatible MIDI input port
%MM_PC_JOYSTICK       = 12   ' Joystick adapter
#ENDIF
#ENDIF



%MMRESULT = 1


' SMPTE
TYPE SMPTE
    hour   AS BYTE     ' hours
    MIN    AS BYTE     ' minutes
    sec    AS BYTE     ' seconds
    FRAME  AS BYTE     ' frames
    fps    AS BYTE     ' frames per second
    dummy  AS BYTE     ' pad
    pad(1) AS BYTE
END TYPE

TYPE MIDI
    songptrpos AS DWORD   ' song pointer position
END TYPE

UNION MMTIME_union
    ms     AS DWORD   ' milliseconds
    sample AS DWORD   ' samples
    cb     AS DWORD   ' byte count
    ticks  AS DWORD   ' ticks in MIDI stream
    SMPTE
    MIDI
END UNION

' MMTIME data structure
TYPE MMTIME
    wType AS DWORD  ' indicates the contents of the union
    MMTIME_union
END TYPE

' types for wType field in MMTIME struct
%TIME_MS       = &H0001  ' time in milliseconds
%TIME_SAMPLES  = &H0002  ' number of wave samples
%TIME_BYTES    = &H0004  ' current byte offset
%TIME_SMPTE    = &H0008  ' SMPTE time
%TIME_MIDI     = &H0010  ' MIDI time
%TIME_TICKS    = &H0020  ' Ticks within MIDI stream

'
'
'
'
MACRO MAKEFOURCC(ch0,ch1,ch2,ch3)=MAK(DWORD,MAK(WORD,ch0,ch1),MAK(WORD,ch2,ch3))



'****************************************************************************
'
'                   Multimedia Extensions Window Messages
'
'****************************************************************************

%MM_JOY1MOVE         = &H3A0           ' joystick
%MM_JOY2MOVE         = &H3A1
%MM_JOY1ZMOVE        = &H3A2
%MM_JOY2ZMOVE        = &H3A3
%MM_JOY1BUTTONDOWN   = &H3B5
%MM_JOY2BUTTONDOWN   = &H3B6
%MM_JOY1BUTTONUP     = &H3B7
%MM_JOY2BUTTONUP     = &H3B8

%MM_MCINOTIFY        = &H3B9           ' MCI

%MM_WOM_OPEN         = &H3BB           ' waveform output
%MM_WOM_CLOSE        = &H3BC
%MM_WOM_DONE         = &H3BD

%MM_WIM_OPEN         = &H3BE           ' waveform input
%MM_WIM_CLOSE        = &H3BF
%MM_WIM_DATA         = &H3C0

%MM_MIM_OPEN         = &H3C1           ' MIDI input
%MM_MIM_CLOSE        = &H3C2
%MM_MIM_DATA         = &H3C3
%MM_MIM_LONGDATA     = &H3C4
%MM_MIM_ERROR        = &H3C5
%MM_MIM_LONGERROR    = &H3C6

%MM_MOM_OPEN         = &H3C7           ' MIDI output
%MM_MOM_CLOSE        = &H3C8
%MM_MOM_DONE         = &H3C9

' these are also in msvideo.h
#IF NOT %DEF(%MM_DRVM_OPEN)
 %MM_DRVM_OPEN       = &H3D0           ' installable drivers
 %MM_DRVM_CLOSE      = &H3D1
 %MM_DRVM_DATA       = &H3D2
 %MM_DRVM_ERROR      = &H3D3
#ENDIF

' these are used by msacm.h
%MM_STREAM_OPEN      = &H3D4
%MM_STREAM_CLOSE     = &H3D5
%MM_STREAM_DONE      = &H3D6
%MM_STREAM_ERROR     = &H3D7

#IF (%WINVER >= &H0400)
%MM_MOM_POSITIONCB   = &H3CA           ' Callback for MEVT_POSITIONCB

#IF NOT %DEF(%MM_MCISIGNAL)
 %MM_MCISIGNAL        = &H3CB
#ENDIF

%MM_MIM_MOREDATA      = &H3CC          ' MIM_DONE w/ pending events

#ENDIF ' WINVER >= &H0400

%MM_MIXM_LINE_CHANGE     = &H3D0       ' mixer line change notify
%MM_MIXM_CONTROL_CHANGE  = &H3D1       ' mixer control change notify


'****************************************************************************
'
'               String resource number bases (internal use)
'
'****************************************************************************

%MMSYSERR_BASE        = 0
%WAVERR_BASE          = 32
%MIDIERR_BASE         = 64
%TIMERR_BASE          = 96
%JOYERR_BASE          = 160
%MCIERR_BASE          = 256
%MIXERR_BASE          = 1024

%MCI_STRING_OFFSET    = 512
%MCI_VD_OFFSET        = 1024
%MCI_CD_OFFSET        = 1088
%MCI_WAVE_OFFSET      = 1152
%MCI_SEQ_OFFSET       = 1216

'****************************************************************************
'
'                       General error return values
'
'****************************************************************************

' general error return values
%MMSYSERR_NOERROR      = 0                    ' no error
%MMSYSERR_ERROR        = %MMSYSERR_BASE + 1   ' unspecified error
%MMSYSERR_BADDEVICEID  = %MMSYSERR_BASE + 2   ' device ID out of range
%MMSYSERR_NOTENABLED   = %MMSYSERR_BASE + 3   ' driver failed enable
%MMSYSERR_ALLOCATED    = %MMSYSERR_BASE + 4   ' device already allocated
%MMSYSERR_INVALHANDLE  = %MMSYSERR_BASE + 5   ' device handle is invalid
%MMSYSERR_NODRIVER     = %MMSYSERR_BASE + 6   ' no device driver present
%MMSYSERR_NOMEM        = %MMSYSERR_BASE + 7   ' memory allocation error
%MMSYSERR_NOTSUPPORTED = %MMSYSERR_BASE + 8   ' function isn't supported
%MMSYSERR_BADERRNUM    = %MMSYSERR_BASE + 9   ' error value out of range
%MMSYSERR_INVALFLAG    = %MMSYSERR_BASE + 10  ' invalid flag passed
%MMSYSERR_INVALPARAM   = %MMSYSERR_BASE + 11  ' invalid parameter passed
%MMSYSERR_HANDLEBUSY   = %MMSYSERR_BASE + 12  ' handle being used
                                              ' simultaneously on another
                                              ' thread (eg callback)
%MMSYSERR_INVALIDALIAS = %MMSYSERR_BASE + 13  ' specified alias not found
%MMSYSERR_BADDB        = %MMSYSERR_BASE + 14  ' bad registry database
%MMSYSERR_KEYNOTFOUND  = %MMSYSERR_BASE + 15  ' registry key not found
%MMSYSERR_READERROR    = %MMSYSERR_BASE + 16  ' registry read error
%MMSYSERR_WRITEERROR   = %MMSYSERR_BASE + 17  ' registry write error
%MMSYSERR_DELETEERROR  = %MMSYSERR_BASE + 18  ' registry delete error
%MMSYSERR_VALNOTFOUND  = %MMSYSERR_BASE + 19  ' registry value not found
%MMSYSERR_NODRIVERCB   = %MMSYSERR_BASE + 20  ' driver does not call DriverCallback
%MMSYSERR_MOREDATA     = %MMSYSERR_BASE + 21  ' more data to be returned
%MMSYSERR_LASTERROR    = %MMSYSERR_BASE + 21  ' last error in range


#IF NOT %DEF(%MMNODRV)

'****************************************************************************
'
'                       Installable driver support
'
'****************************************************************************

TYPE DRVCONFIGINFOEX
    dwDCISize          AS DWORD
    lpszDCISectionName AS WSTRINGZ PTR
    lpszDCIAliasName   AS WSTRINGZ PTR
    dnDevNode          AS DWORD
END TYPE

#IF NOT %DEF(%DRV_LOAD)

' Driver messages
%DRV_LOAD              = &H0001
%DRV_ENABLE            = &H0002
%DRV_OPEN              = &H0003
%DRV_CLOSE             = &H0004
%DRV_DISABLE           = &H0005
%DRV_FREE              = &H0006
%DRV_CONFIGURE         = &H0007
%DRV_QUERYCONFIGURE    = &H0008
%DRV_INSTALL           = &H0009
%DRV_REMOVE            = &H000A
%DRV_EXITSESSION       = &H000B
%DRV_POWER             = &H000F
%DRV_RESERVED          = &H0800
%DRV_USER              = &H4000

' LPARAM of DRV_CONFIGURE message

TYPE DRVCONFIGINFO
    dwDCISize          AS DWORD
    lpszDCISectionName AS WSTRINGZ PTR
    lpszDCIAliasName   AS WSTRINGZ PTR
END TYPE

' Supported return values for DRV_CONFIGURE message
%DRVCNF_CANCEL         = &H0000
%DRVCNF_OK             = &H0001
%DRVCNF_RESTART        = &H0002

' installable driver function prototypes

'typedef LRESULT (CALLBACK* DRIVERPROC)(DWORD, HDRVR, DWORD, LPARAM, LPARAM);

DECLARE FUNCTION CloseDriver LIB "WINMM.DLL" ALIAS "CloseDriver" _
    (BYVAL hDriver AS DWORD, BYVAL lParam1 AS LONG, BYVAL lParam2 AS LONG) _
    AS LONG

DECLARE FUNCTION OpenDriver LIB "WINMM.DLL" ALIAS "OpenDriver" _
    (szDriverName AS WSTRINGZ, szSectionName AS WSTRINGZ, BYVAL lParam2 AS LONG) _
    AS DWORD

DECLARE FUNCTION SendDriverMessage LIB "WINMM.DLL" ALIAS "SendDriverMessage" _
    (BYVAL hDriver AS DWORD, BYVAL message AS DWORD, BYVAL lParam1 AS LONG, _
    BYVAL lParam2 AS LONG) AS LONG

DECLARE FUNCTION DrvGetModuleHandle LIB "WINMM.DLL" _
    ALIAS "DrvGetModuleHandle" (BYVAL hDriver AS DWORD) AS DWORD

DECLARE FUNCTION GetDriverModuleHandle LIB "WINMM.DLL" _
    ALIAS "GetDriverModuleHandle" (BYVAL hDriver AS DWORD) AS DWORD

DECLARE FUNCTION DefDriverProc LIB "WINMM.DLL" ALIAS "DefDriverProc" _
    (BYVAL dwDriverIdentifier AS DWORD, BYVAL hDriver AS DWORD, _
    BYVAL uMsg AS DWORD, BYVAL lParam1 AS LONG, BYVAL lParam2 AS LONG) AS LONG

#ENDIF ' %DRV_LOAD

#IF (%WINVER >= &H030a)
' return values from DriverProc() function
%DRV_CANCEL            = %DRVCNF_CANCEL
%DRV_OK                = %DRVCNF_OK
%DRV_RESTART           = %DRVCNF_RESTART

#ENDIF ' ifdef WINVER >= &H030a

%DRV_MCI_FIRST         = %DRV_RESERVED
%DRV_MCI_LAST          = %DRV_RESERVED + &H0FFF

#ENDIF  ' ifndef MMNODRV

'****************************************************************************
'
'                         Driver callback support
'
'****************************************************************************

' flags used with waveOutOpen(), waveInOpen(), midiInOpen(), and
' midiOutOpen() to specify the type of the dwCallback parameter.

%CALLBACK_TYPEMASK = &H00070000     ' callback type mask
%CALLBACK_NULL     = &H00000000     ' no callback
%CALLBACK_WINDOW   = &H00010000     ' dwCallback is a DWORD
%CALLBACK_TASK     = &H00020000     ' dwCallback is a DWORD
%CALLBACK_FUNCTION = &H00030000     ' dwCallback is a FARPROC
%CALLBACK_THREAD   = %CALLBACK_TASK ' thread ID replaces 16 bit task
%CALLBACK_EVENT    = &H00050000     ' dwCallback is an EVENT Handle
'typedef void (CALLBACK DRVCALLBACK)(HDRVR hdrvr, DWORD uMsg, DWORD dwUser, DWORD dw1, DWORD dw2);


#IF NOT %DEF(%MMNOMMSYSTEM)
'****************************************************************************
'
'                   General MMSYSTEM support
'
'****************************************************************************

#IF (%WINVER <= &H030A)
DECLARE FUNCTION mmsystemGetVersion LIB "WINMM.DLL" _
    ALIAS "mmsystemGetVersion" () AS DWORD
#ENDIF

MACRO OutputDebugStr=OutputDebugString

#ENDIF  ' ifndef MMNOMMSYSTEM

#IF NOT %DEF(%MMNOSOUND)
'****************************************************************************
'
'                           Sound support
'
'****************************************************************************

DECLARE FUNCTION sndPlaySoundA LIB "WINMM.DLL" ALIAS "sndPlaySoundA" _
    (lpszSoundName AS ASCIIZ, BYVAL uFlags AS DWORD) AS LONG

DECLARE FUNCTION sndPlaySoundW LIB "WINMM.DLL" ALIAS "sndPlaySoundW" _
    (lpszSoundName AS WSTRINGZ, BYVAL uFlags AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION sndPlaySound LIB "WINMM.DLL" ALIAS "sndPlaySoundW" _
    (lpszSoundName AS WSTRINGZ, BYVAL uFlags AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION sndPlaySound LIB "WINMM.DLL" ALIAS "sndPlaySoundA" _
    (lpszSoundName AS ASCIIZ, BYVAL uFlags AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

'
'  flag values for fuSound and fdwSound arguments on [snd]PlaySound
'
%SND_SYNC            = &H0000  ' play synchronously (default)
%SND_ASYNC           = &H0001  ' play asynchronously
%SND_NODEFAULT       = &H0002  ' silence (!default) if sound not found
%SND_MEMORY          = &H0004  ' pszSound points to a memory file
%SND_LOOP            = &H0008  ' loop the sound until next sndPlaySound
%SND_NOSTOP          = &H0010  ' don't stop any currently playing sound

%SND_NOWAIT      = &H00002000  ' don't wait if the driver is busy
%SND_ALIAS       = &H00010000  ' name is a registry alias
%SND_ALIAS_ID    = &H00110000  ' alias is a predefined ID
%SND_FILENAME    = &H00020000  ' name is file name
%SND_RESOURCE    = &H00040004  ' name is resource name or atom
#IF (%WINVER >= &H0400)
%SND_PURGE           = &H0040  ' purge non-static events for task
%SND_APPLICATION     = &H0080  ' look for application specific association
#ENDIF ' WINVER >= &H0400
%SND_SENTRY      = &H00080000  ' Generate a SoundSentry event with this sound
%SND_RING        = &H00100000  ' Treat this as a "ring" from a communications app - don't duck me
%SND_SYSTEM      = &H00200000  ' Treat this as a system sound

%SND_ALIAS_START = 0           ' alias base

MACRO sndAlias(ch0,ch1)=%SND_ALIAS_START+MAK(WORD,ASC(ch0),ASC(ch1))

MACRO SND_ALIAS_SYSTEMASTERISK    = sndAlias("S","*")
MACRO SND_ALIAS_SYSTEMQUESTION    = sndAlias("S","?")
MACRO SND_ALIAS_SYSTEMHAND        = sndAlias("S","H")
MACRO SND_ALIAS_SYSTEMEXIT        = sndAlias("S","E")
MACRO SND_ALIAS_SYSTEMSTART       = sndAlias("S","S")
MACRO SND_ALIAS_SYSTEMWELCOME     = sndAlias("S","W")
MACRO SND_ALIAS_SYSTEMEXCLAMATION = sndAlias("S","!")
MACRO SND_ALIAS_SYSTEMDEFAULT     = sndAlias("S","D")

DECLARE FUNCTION PlaySoundA LIB "WINMM.DLL" ALIAS "PlaySoundA" _
    (lpszName AS ASCIIZ, BYVAL hModule AS DWORD, BYVAL dwFlags AS DWORD) _
    AS LONG

DECLARE FUNCTION PlaySoundW LIB "WINMM.DLL" ALIAS "PlaySoundW" _
    (lpszName AS WSTRINGZ, BYVAL hModule AS DWORD, BYVAL dwFlags AS DWORD) _
    AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION PlaySound LIB "WINMM.DLL" ALIAS "PlaySoundW" _
    (lpszName AS WSTRINGZ, BYVAL hModule AS DWORD, BYVAL dwFlags AS DWORD) _
    AS LONG
#ELSE
DECLARE FUNCTION PlaySound LIB "WINMM.DLL" ALIAS "PlaySoundA" _
    (lpszName AS ASCIIZ, BYVAL hModule AS DWORD, BYVAL dwFlags AS DWORD) _
    AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF  ' ifndef MMNOSOUND


#IF NOT %DEF(%MMNOWAVE)
'****************************************************************************
'
'                       Waveform audio support
'
'****************************************************************************

' waveform audio error return values
%WAVERR_BADFORMAT    = %WAVERR_BASE + 0    ' unsupported wave format
%WAVERR_STILLPLAYING = %WAVERR_BASE + 1    ' still something playing
%WAVERR_UNPREPARED   = %WAVERR_BASE + 2    ' header not prepared
%WAVERR_SYNC         = %WAVERR_BASE + 3    ' device is synchronous
%WAVERR_LASTERROR    = %WAVERR_BASE + 3    ' last error in range

' wave callback messages
%WOM_OPEN        = %MM_WOM_OPEN
%WOM_CLOSE       = %MM_WOM_CLOSE
%WOM_DONE        = %MM_WOM_DONE
%WIM_OPEN        = %MM_WIM_OPEN
%WIM_CLOSE       = %MM_WIM_CLOSE
%WIM_DATA        = %MM_WIM_DATA

' device ID for wave device mapper
%WAVE_MAPPER     = &HFFFFFFFF???    ' ((DWORD)-1)

' flags for dwFlags parameter in waveOutOpen() and waveInOpen()
%WAVE_FORMAT_QUERY        = &H0001
%WAVE_ALLOWSYNC           = &H0002
#IF (%WINVER >= &H0400)
%WAVE_MAPPED              = &H0004
%WAVE_FORMAT_DIRECT       = &H0008
%WAVE_FORMAT_DIRECT_QUERY = (%WAVE_FORMAT_QUERY OR %WAVE_FORMAT_DIRECT)
%WAVE_MAPPED_DEFAULT_COMMUNICATION_DEVICE = &H0010
#ENDIF ' WINVER >= &H0400

' wave data block header
TYPE WAVEHDR
    lpData          AS ASCIIZ PTR  ' pointer to locked data buffer
    dwBufferLength  AS DWORD       ' length of data buffer
    dwBytesRecorded AS DWORD       ' used for input only
    dwUser          AS DWORD       ' for client's use
    dwFlags         AS DWORD       ' assorted flags (see defines)
    dwLoops         AS DWORD       ' loop control counter
    lpNext          AS DWORD       ' reserved for driver
    reserved        AS DWORD       ' reserved for driver
END TYPE

' flags for dwFlags field of WAVEHDR
%WHDR_DONE      = &H00000001  ' done bit
%WHDR_PREPARED  = &H00000002  ' set if this header has been prepared
%WHDR_BEGINLOOP = &H00000004  ' loop start block
%WHDR_ENDLOOP   = &H00000008  ' loop end block
%WHDR_INQUEUE   = &H00000010  ' reserved for driver

' waveform output device capabilities structure

TYPE WAVEOUTCAPSA
    wMid           AS WORD                  ' manufacturer ID
    wPid           AS WORD                  ' product ID
    vDriverVersion AS DWORD                 ' version of the driver
    szPname        AS ASCIIZ * %MAXPNAMELEN ' product name (NULL terminated string)
    dwFormats      AS DWORD                 ' formats supported
    wChannels      AS WORD                  ' number of sources supported
    wReserved1     AS WORD                  ' packing
    dwSupport      AS DWORD                 ' functionality supported by driver
END TYPE

TYPE WAVEOUTCAPSW
    wMid           AS WORD                  ' manufacturer ID
    wPid           AS WORD                  ' product ID
    vDriverVersion AS DWORD                 ' version of the driver
    szPname        AS WSTRINGZ * %MAXPNAMELEN ' product name (NULL terminated string)
    dwFormats      AS DWORD                 ' formats supported
    wChannels      AS WORD                  ' number of sources supported
    wReserved1     AS WORD                  ' packing
    dwSupport      AS DWORD                 ' functionality supported by driver
END TYPE

#IF %DEF(%UNICODE)
TYPE WAVEOUTCAPS
    WAVEOUTCAPSW
END TYPE
#ELSE
TYPE WAVEOUTCAPS
    WAVEOUTCAPSA
END TYPE
#ENDIF ' %UNICODE

TYPE WAVEOUTCAPS2A
    wMid             AS WORD        ' manufacturer ID
    wPid             AS WORD        ' product ID
    vDriverVersion   AS DWORD       ' version of the driver
    szPname          AS ASCIIZ * %MAXPNAMELEN  ' product name (NULL terminated string)
    dwFormats        AS DWORD       ' formats supported
    wChannels        AS WORD        ' number of sources supported
    wReserved1       AS WORD        ' packing
    dwSupport        AS DWORD       ' functionality supported by driver
    ManufacturerGuid AS GUID        ' for extensible MID mapping
    ProductGuid      AS GUID        ' for extensible PID mapping
    NameGuid         AS GUID        ' for name lookup in registry
END TYPE

TYPE WAVEOUTCAPS2W
    wMid             AS WORD        ' manufacturer ID
    wPid             AS WORD        ' product ID
    vDriverVersion   AS DWORD       ' version of the driver
    szPname          AS WSTRINGZ * %MAXPNAMELEN  ' product name (NULL terminated string)
    dwFormats        AS DWORD       ' formats supported
    wChannels        AS WORD        ' number of sources supported
    wReserved1       AS WORD        ' packing
    dwSupport        AS DWORD       ' functionality supported by driver
    ManufacturerGuid AS GUID        ' for extensible MID mapping
    ProductGuid      AS GUID        ' for extensible PID mapping
    NameGuid         AS GUID        ' for name lookup in registry
END TYPE

#IF %DEF(%UNICODE)
TYPE WAVEOUTCAPS2
    WAVEOUTCAPS2W
END TYPE
#ELSE
TYPE WAVEOUTCAPS2
    WAVEOUTCAPS2A
END TYPE
#ENDIF ' %UNICODE

' flags for dwSupport field of WAVEOUTCAPS
%WAVECAPS_PITCH          = &H0001   ' supports pitch control
%WAVECAPS_PLAYBACKRATE   = &H0002   ' supports playback rate control
%WAVECAPS_VOLUME         = &H0004   ' supports volume control
%WAVECAPS_LRVOLUME       = &H0008   ' separate left-right volume control
%WAVECAPS_SYNC           = &H0010
%WAVECAPS_SAMPLEACCURATE = &H0020


' waveform input device capabilities structure

TYPE WAVEINCAPSA
    wMid           AS WORD          ' manufacturer ID
    wPid           AS WORD          ' product ID
    vDriverVersion AS DWORD         ' version of the driver
    szPname        AS ASCIIZ * %MAXPNAMELEN   ' product name (NULL terminated string)
    dwFormats      AS DWORD         ' formats supported
    wChannels      AS WORD          ' number of channels supported
    wReserved1     AS WORD          ' structure packing
END TYPE

TYPE WAVEINCAPSW
    wMid           AS WORD          ' manufacturer ID
    wPid           AS WORD          ' product ID
    vDriverVersion AS DWORD         ' version of the driver
    szPname        AS WSTRINGZ * %MAXPNAMELEN   ' product name (NULL terminated string)
    dwFormats      AS DWORD         ' formats supported
    wChannels      AS WORD          ' number of channels supported
    wReserved1     AS WORD          ' structure packing
END TYPE

#IF %DEF(%UNICODE)
TYPE WAVEINCAPS
    WAVEINCAPSW
END TYPE
#ELSE
TYPE WAVEINCAPS
    WAVEINCAPSA
END TYPE
#ENDIF ' %UNICODE

TYPE WAVEINCAPS2A
    wMid             AS WORD        ' manufacturer ID
    wPid             AS WORD        ' product ID
    vDriverVersion   AS DWORD       ' version of the driver
    szPname          AS ASCIIZ * %MAXPNAMELEN   ' product name (NULL terminated string)
    dwFormats        AS DWORD       ' formats supported
    wChannels        AS WORD        ' number of channels supported
    wReserved1       AS WORD        ' structure packing
    ManufacturerGuid AS GUID        ' for extensible MID mapping
    ProductGuid      AS GUID        ' for extensible PID mapping
    NameGuid         AS GUID        ' for name lookup in registry
END TYPE

TYPE WAVEINCAPS2W
    wMid             AS WORD        ' manufacturer ID
    wPid             AS WORD        ' product ID
    vDriverVersion   AS DWORD       ' version of the driver
    szPname          AS WSTRINGZ * %MAXPNAMELEN   ' product name (NULL terminated string)
    dwFormats        AS DWORD       ' formats supported
    wChannels        AS WORD        ' number of channels supported
    wReserved1       AS WORD        ' structure packing
    ManufacturerGuid AS GUID        ' for extensible MID mapping
    ProductGuid      AS GUID        ' for extensible PID mapping
    NameGuid         AS GUID        ' for name lookup in registry
END TYPE

#IF %DEF(%UNICODE)
TYPE WAVEINCAPS2
    WAVEINCAPS2W
END TYPE
#ELSE
TYPE WAVEINCAPS2
    WAVEINCAPS2A
END TYPE
#ENDIF ' %UNICODE

' defines for dwFormat field of WAVEINCAPS and WAVEOUTCAPS
%WAVE_INVALIDFORMAT   = &H00000000       ' invalid format
%WAVE_FORMAT_1M08     = &H00000001       ' 11.025 kHz, Mono,   8-bit
%WAVE_FORMAT_1S08     = &H00000002       ' 11.025 kHz, Stereo, 8-bit
%WAVE_FORMAT_1M16     = &H00000004       ' 11.025 kHz, Mono,   16-bit
%WAVE_FORMAT_1S16     = &H00000008       ' 11.025 kHz, Stereo, 16-bit
%WAVE_FORMAT_2M08     = &H00000010       ' 22.05  kHz, Mono,   8-bit
%WAVE_FORMAT_2S08     = &H00000020       ' 22.05  kHz, Stereo, 8-bit
%WAVE_FORMAT_2M16     = &H00000040       ' 22.05  kHz, Mono,   16-bit
%WAVE_FORMAT_2S16     = &H00000080       ' 22.05  kHz, Stereo, 16-bit
%WAVE_FORMAT_4M08     = &H00000100       ' 44.1   kHz, Mono,   8-bit
%WAVE_FORMAT_4S08     = &H00000200       ' 44.1   kHz, Stereo, 8-bit
%WAVE_FORMAT_4M16     = &H00000400       ' 44.1   kHz, Mono,   16-bit
%WAVE_FORMAT_4S16     = &H00000800       ' 44.1   kHz, Stereo, 16-bit

%WAVE_FORMAT_44M08    = &H00000100       ' 44.1   kHz, Mono,   8-bit
%WAVE_FORMAT_44S08    = &H00000200       ' 44.1   kHz, Stereo, 8-bit
%WAVE_FORMAT_44M16    = &H00000400       ' 44.1   kHz, Mono,   16-bit
%WAVE_FORMAT_44S16    = &H00000800       ' 44.1   kHz, Stereo, 16-bit
%WAVE_FORMAT_48M08    = &H00001000       ' 48     kHz, Mono,   8-bit
%WAVE_FORMAT_48S08    = &H00002000       ' 48     kHz, Stereo, 8-bit
%WAVE_FORMAT_48M16    = &H00004000       ' 48     kHz, Mono,   16-bit
%WAVE_FORMAT_48S16    = &H00008000       ' 48     kHz, Stereo, 16-bit
%WAVE_FORMAT_96M08    = &H00010000       ' 96     kHz, Mono,   8-bit
%WAVE_FORMAT_96S08    = &H00020000       ' 96     kHz, Stereo, 8-bit
%WAVE_FORMAT_96M16    = &H00040000       ' 96     kHz, Mono,   16-bit
%WAVE_FORMAT_96S16    = &H00080000       ' 96     kHz, Stereo, 16-bit


#IF NOT %DEF(%WAVE_FORMAT_PCM)

' OLD general waveform format structure (information common to all formats)
TYPE WAVEFORMAT
    wFormatTag      AS WORD    ' format type
    nChannels       AS WORD    ' number of channels (i.e. mono, stereo, etc.)
    nSamplesPerSec  AS DWORD   ' sample rate
    nAvgBytesPerSec AS DWORD   ' for buffer estimation
    nBlockAlign     AS WORD    ' block size of data
END TYPE

' flags for wFormatTag field of WAVEFORMAT
%WAVE_FORMAT_PCM   = 1


' specific waveform format structure for PCM data
TYPE PCMWAVEFORMAT
    wf             AS WAVEFORMAT
    wBitsPerSample AS WORD
END TYPE

#ENDIF ' %WAVE_FORMAT_PCM

#IF NOT %DEF(%WAVEFORMATEX)

%WAVEFORMATEX = 1

'
'  extended waveform format structure used for all non-PCM formats. this
'  structure is common to all non-PCM formats.

TYPE WAVEFORMATEX
    wFormatTag      AS WORD    ' format type
    nChannels       AS WORD    ' number of channels (i.e. mono, stereo...)
    nSamplesPerSec  AS DWORD   ' sample rate
    nAvgBytesPerSec AS DWORD   ' for buffer estimation
    nBlockAlign     AS WORD    ' block size of data
    wBitsPerSample  AS WORD    ' number of bits per sample of mono data
    cbSize          AS WORD    ' the count in bytes of the size of
                               ' extra information (after cbSize)
END TYPE

#ENDIF ' %WAVEFORMATEX

' waveform audio function prototypes

DECLARE FUNCTION waveOutGetNumDevs LIB "WINMM.DLL" ALIAS "waveOutGetNumDevs" _
    () AS DWORD

DECLARE FUNCTION waveOutGetDevCapsA LIB "WINMM.DLL" _
    ALIAS "waveOutGetDevCapsA" (BYVAL uDeviceID AS DWORD, _
    lpCaps AS WAVEOUTCAPSA, BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION waveOutGetDevCapsW LIB "WINMM.DLL" _
    ALIAS "waveOutGetDevCapsW" (BYVAL uDeviceID AS DWORD, _
    lpCaps AS WAVEOUTCAPSW, BYVAL uSize AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION waveOutGetDevCaps LIB "WINMM.DLL" _
    ALIAS "waveOutGetDevCapsW" (BYVAL uDeviceID AS DWORD, _
    lpCaps AS WAVEOUTCAPSW, BYVAL uSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION waveOutGetDevCaps LIB "WINMM.DLL" _
    ALIAS "waveOutGetDevCapsA" (BYVAL uDeviceID AS DWORD, _
    lpCaps AS WAVEOUTCAPSA, BYVAL uSize AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION waveOutGetVolume LIB "WINMM.DLL" ALIAS "waveOutGetVolume" _
    (BYVAL uDeviceID AS DWORD, lpdwVolume AS DWORD) AS DWORD

DECLARE FUNCTION waveOutSetVolume LIB "WINMM.DLL" ALIAS "waveOutSetVolume" _
    (BYVAL uDeviceID AS DWORD, BYVAL dwVolume AS DWORD) AS LONG

DECLARE FUNCTION waveOutGetErrorTextA LIB "WINMM.DLL" _
    ALIAS "waveOutGetErrorTextA" (BYVAL xerr AS DWORD, lpText AS ASCIIZ, _
    BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION waveOutGetErrorTextW LIB "WINMM.DLL" _
    ALIAS "waveOutGetErrorTextW" (BYVAL xerr AS DWORD, lpText AS WSTRINGZ, _
    BYVAL uSize AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION waveOutGetErrorText LIB "WINMM.DLL" _
    ALIAS "waveOutGetErrorTextW" (BYVAL xerr AS DWORD, lpText AS WSTRINGZ, _
    BYVAL uSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION waveOutGetErrorText LIB "WINMM.DLL" _
    ALIAS "waveOutGetErrorTextA" (BYVAL xerr AS DWORD, lpText AS ASCIIZ, _
    BYVAL uSize AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION waveOutOpen LIB "WINMM.DLL" ALIAS "waveOutOpen" _
    (lphWaveOut AS DWORD, BYVAL uDeviceID AS DWORD, lpFormat AS WAVEFORMATEX, _
    BYVAL dwCallback AS DWORD, BYVAL dwInstance AS DWORD, _
    BYVAL dwFlags AS DWORD) AS DWORD

DECLARE FUNCTION waveOutClose LIB "WINMM.DLL" ALIAS "waveOutClose" _
    (BYVAL hWaveOut AS DWORD) AS DWORD

DECLARE FUNCTION waveOutPrepareHeader LIB "WINMM.DLL" _
    ALIAS "waveOutPrepareHeader" (BYVAL hWaveOut AS DWORD, _
    lpWaveOutHdr AS WAVEHDR, BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION waveOutUnprepareHeader LIB "WINMM.DLL" _
    ALIAS "waveOutUnprepareHeader" (BYVAL hWaveOut AS DWORD, _
    lpWaveOutHdr AS WAVEHDR, BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION waveOutWrite LIB "WINMM.DLL" ALIAS "waveOutWrite" _
    (BYVAL hWaveOut AS DWORD, lpWaveOutHdr AS WAVEHDR, BYVAL uSize AS DWORD) _
    AS DWORD

DECLARE FUNCTION waveOutPause LIB "WINMM.DLL" ALIAS "waveOutPause" _
    (BYVAL hWaveOut AS DWORD) AS DWORD

DECLARE FUNCTION waveOutRestart LIB "WINMM.DLL" ALIAS "waveOutRestart" _
    (BYVAL hWaveOut AS DWORD) AS DWORD

DECLARE FUNCTION waveOutReset LIB "WINMM.DLL" ALIAS "waveOutReset" _
    (BYVAL hWaveOut AS DWORD) AS DWORD

DECLARE FUNCTION waveOutBreakLoop LIB "WINMM.DLL" ALIAS "waveOutBreakLoop" _
    (BYVAL hWaveOut AS DWORD) AS DWORD

DECLARE FUNCTION waveOutGetPosition LIB "WINMM.DLL" _
    ALIAS "waveOutGetPosition" (BYVAL hWaveOut AS DWORD, lpInfo AS MMTIME, _
    BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION waveOutGetPitch LIB "WINMM.DLL" ALIAS "waveOutGetPitch" _
    (BYVAL hWaveOut AS DWORD, lpdwPitch AS DWORD) AS DWORD

DECLARE FUNCTION waveOutSetPitch LIB "WINMM.DLL" ALIAS "waveOutSetPitch" _
    (BYVAL hWaveOut AS DWORD, BYVAL dwPitch AS DWORD) AS DWORD

DECLARE FUNCTION waveOutGetPlaybackRate LIB "WINMM.DLL" _
    ALIAS "waveOutGetPlaybackRate" (BYVAL hWaveOut AS DWORD, _
    lpdwRate AS DWORD) AS DWORD

DECLARE FUNCTION waveOutSetPlaybackRate LIB "WINMM.DLL" _
    ALIAS "waveOutSetPlaybackRate" (BYVAL hWaveOut AS DWORD, _
    BYVAL dwRate AS DWORD) AS DWORD

DECLARE FUNCTION waveOutGetID LIB "WINMM.DLL" ALIAS "waveOutGetID" _
    (BYVAL hWaveOut AS DWORD, lpuDeviceID AS DWORD) AS DWORD

#IF (%WINVER >= &H030a)
DECLARE FUNCTION waveOutMessage LIB "WINMM.DLL" ALIAS "waveOutMessage" _
    (BYVAL hWaveOut AS DWORD, BYVAL uMsg AS DWORD, BYVAL dwParam1 AS DWORD, _
    BYVAL dwParam2 AS DWORD) AS DWORD
#ENDIF ' ifdef WINVER >= &H030a

DECLARE FUNCTION waveInGetNumDevs LIB "WINMM.DLL" ALIAS "waveInGetNumDevs" () _
    AS DWORD

DECLARE FUNCTION waveInGetDevCapsA LIB "WINMM.DLL" ALIAS "waveInGetDevCapsA" _
    (BYVAL uDeviceID AS DWORD, lpCaps AS WAVEINCAPSA, BYVAL uSize AS DWORD) _
    AS DWORD

DECLARE FUNCTION waveInGetDevCapsW LIB "WINMM.DLL" ALIAS "waveInGetDevCapsW" _
    (BYVAL uDeviceID AS DWORD, lpCaps AS WAVEINCAPSW, BYVAL uSize AS DWORD) _
    AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION waveInGetDevCaps LIB "WINMM.DLL" ALIAS "waveInGetDevCapsW" _
    (BYVAL uDeviceID AS DWORD, lpCaps AS WAVEINCAPSW, BYVAL uSize AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION waveInGetDevCaps LIB "WINMM.DLL" ALIAS "waveInGetDevCapsA" _
    (BYVAL uDeviceID AS DWORD, lpCaps AS WAVEINCAPSA, BYVAL uSize AS DWORD) _
    AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION waveInGetErrorTextA LIB "WINMM.DLL" _
    ALIAS "waveInGetErrorTextA" (BYVAL xerr AS DWORD, lpText AS ASCIIZ, _
    BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION waveInGetErrorTextW LIB "WINMM.DLL" _
    ALIAS "waveInGetErrorTextW" (BYVAL xerr AS DWORD, lpText AS WSTRINGZ, _
    BYVAL uSize AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION waveInGetErrorText LIB "WINMM.DLL" _
    ALIAS "waveInGetErrorTextW" (BYVAL xerr AS DWORD, lpText AS WSTRINGZ, _
    BYVAL uSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION waveInGetErrorText LIB "WINMM.DLL" _
    ALIAS "waveInGetErrorTextA" (BYVAL xerr AS DWORD, lpText AS ASCIIZ, _
    BYVAL uSize AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION waveInOpen LIB "WINMM.DLL" ALIAS "waveInOpen" _
    (lphWaveIn AS DWORD, BYVAL uDeviceID AS DWORD, lpFormat AS WAVEFORMATEX, _
    BYVAL dwCallback AS DWORD, BYVAL dwInstance AS DWORD, _
    BYVAL dwFlags AS DWORD) AS DWORD

DECLARE FUNCTION waveInClose LIB "WINMM.DLL" ALIAS "waveInClose" _
    (BYVAL hWaveIn AS DWORD) AS DWORD

DECLARE FUNCTION waveInPrepareHeader LIB "WINMM.DLL" _
    ALIAS "waveInPrepareHeader" (BYVAL hWaveIn AS DWORD, _
    lpWaveInHdr AS WAVEHDR, BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION waveInUnprepareHeader LIB "WINMM.DLL" _
    ALIAS "waveInUnprepareHeader" (BYVAL hWaveIn AS DWORD, _
    lpWaveInHdr AS WAVEHDR, BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION waveInAddBuffer LIB "WINMM.DLL" ALIAS "waveInAddBuffer" _
    (BYVAL hWaveIn AS DWORD, lpWaveInHdr AS WAVEHDR, BYVAL uSize AS DWORD) _
    AS DWORD

DECLARE FUNCTION waveInStart LIB "WINMM.DLL" ALIAS "waveInStart" _
    (BYVAL hWaveIn AS DWORD) AS DWORD

DECLARE FUNCTION waveInStop LIB "WINMM.DLL" ALIAS "waveInStop" _
    (BYVAL hWaveIn AS DWORD) AS DWORD

DECLARE FUNCTION waveInReset LIB "WINMM.DLL" ALIAS "waveInReset" _
    (BYVAL hWaveIn AS DWORD) AS DWORD

DECLARE FUNCTION waveInGetPosition LIB "WINMM.DLL" ALIAS "waveInGetPosition" _
    (BYVAL hWaveIn AS DWORD, lpInfo AS MMTIME, BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION waveInGetID LIB "WINMM.DLL" ALIAS "waveInGetID" _
    (BYVAL hWaveIn AS DWORD, lpuDeviceId AS DWORD) AS DWORD

#IF (%WINVER >= &H030a)

DECLARE FUNCTION waveInMessage LIB "WINMM.DLL" ALIAS "waveInMessage" _
    (BYVAL hWaveIn AS DWORD, BYVAL uMsg AS DWORD, BYVAL dwParam1 AS DWORD, _
    BYVAL dwParam2 AS DWORD) AS DWORD

#ENDIF ' ifdef WINVER >= &H030a

#ENDIF  ' ifndef MMNOWAVE


#IF NOT %DEF(%MMNOMIDI)
'****************************************************************************
'
'                           MIDI audio support
'
'****************************************************************************

' MIDI error return values
%MIDIERR_UNPREPARED    = %MIDIERR_BASE + 0   ' header not prepared
%MIDIERR_STILLPLAYING  = %MIDIERR_BASE + 1   ' still something playing
%MIDIERR_NOMAP         = %MIDIERR_BASE + 2   ' no configured instruments
%MIDIERR_NOTREADY      = %MIDIERR_BASE + 3   ' hardware is still busy
%MIDIERR_NODEVICE      = %MIDIERR_BASE + 4   ' port no longer connected
%MIDIERR_INVALIDSETUP  = %MIDIERR_BASE + 5   ' invalid MIF
%MIDIERR_BADOPENMODE   = %MIDIERR_BASE + 6   ' operation unsupported w/ open mode
%MIDIERR_DONT_CONTINUE = %MIDIERR_BASE + 7   ' thru device 'eating' a message
%MIDIERR_LASTERROR     = %MIDIERR_BASE + 7   ' last error in range

' MIDI audio data types
%MIDIPATCHSIZE = 128

'typedef WORD PATCHARRAY[MIDIPATCHSIZE];
'typedef WORD FAR *LPPATCHARRAY;
'typedef WORD KEYARRAY[MIDIPATCHSIZE];
'typedef WORD FAR *LPKEYARRAY;

' MIDI callback messages
%MIM_OPEN        = %MM_MIM_OPEN
%MIM_CLOSE       = %MM_MIM_CLOSE
%MIM_DATA        = %MM_MIM_DATA
%MIM_LONGDATA    = %MM_MIM_LONGDATA
%MIM_ERROR       = %MM_MIM_ERROR
%MIM_LONGERROR   = %MM_MIM_LONGERROR
%MOM_OPEN        = %MM_MOM_OPEN
%MOM_CLOSE       = %MM_MOM_CLOSE
%MOM_DONE        = %MM_MOM_DONE

#IF (%WINVER >= &H0400)
%MIM_MOREDATA      = %MM_MIM_MOREDATA
%MOM_POSITIONCB    = %MM_MOM_POSITIONCB
#ENDIF ' WINVER >= &H0400

' device ID for MIDI mapper
%MIDIMAPPER   = &HFFFFFFFF???  '  ((DWORD)-1)
%MIDI_MAPPER  = &HFFFFFFFF???  '  ((DWORD)-1)

#IF (%WINVER >= &H0400)
' flags for dwFlags parm of midiInOpen()
%MIDI_IO_STATUS    = &H00000020
#ENDIF ' WINVER >= &H0400

' flags for wFlags parm of midiOutCachePatches(), midiOutCacheDrumPatches()
%MIDI_CACHE_ALL     = 1
%MIDI_CACHE_BESTFIT = 2
%MIDI_CACHE_QUERY   = 3
%MIDI_UNCACHE       = 4

' MIDI output device capabilities structure
TYPE MIDIOUTCAPSA
    wMid           AS WORD      ' manufacturer ID
    wPid           AS WORD      ' product ID
    vDriverVersion AS DWORD     ' version of the driver
    szPname        AS ASCIIZ * %MAXPNAMELEN  ' product name (NULL terminated string)
    wTechnology    AS WORD      ' type of device
    wVoices        AS WORD      ' # of voices (internal synth only)
    wNotes         AS WORD      ' max # of notes (internal synth only)
    wChannelMask   AS WORD      ' channels used (internal synth only)
    dwSupport      AS DWORD     ' functionality supported by driver
END TYPE

TYPE MIDIOUTCAPSW
    wMid           AS WORD      ' manufacturer ID
    wPid           AS WORD      ' product ID
    vDriverVersion AS DWORD     ' version of the driver
    szPname        AS WSTRINGZ * %MAXPNAMELEN  ' product name (NULL terminated string)
    wTechnology    AS WORD      ' type of device
    wVoices        AS WORD      ' # of voices (internal synth only)
    wNotes         AS WORD      ' max # of notes (internal synth only)
    wChannelMask   AS WORD      ' channels used (internal synth only)
    dwSupport      AS DWORD     ' functionality supported by driver
END TYPE

#IF %DEF(%UNICODE)
TYPE MIDIOUTCAPS
    MIDIOUTCAPSW
END TYPE
#ELSE
TYPE MIDIOUTCAPS
    MIDIOUTCAPSA
END TYPE
#ENDIF ' %UNICODE

TYPE MIDIOUTCAPS2A
    wMid             AS WORD     ' manufacturer ID
    wPid             AS WORD     ' product ID
    vDriverVersion   AS DWORD    ' version of the driver
    szPname          AS ASCIIZ * %MAXPNAMELEN  ' product name (NULL terminated string)
    wTechnology      AS WORD     ' type of device
    wVoices          AS WORD     ' # of voices (internal synth only)
    wNotes           AS WORD     ' max # of notes (internal synth only)
    wChannelMask     AS WORD     ' channels used (internal synth only)
    dwSupport        AS DWORD    ' functionality supported by driver
    ManufacturerGuid AS GUID     ' for extensible MID mapping
    ProductGuid      AS GUID     ' for extensible PID mapping
    NameGuid         AS GUID     ' for name lookup in registry
END TYPE

TYPE MIDIOUTCAPS2W
    wMid             AS WORD     ' manufacturer ID
    wPid             AS WORD     ' product ID
    vDriverVersion   AS DWORD    ' version of the driver
    szPname          AS WSTRINGZ * %MAXPNAMELEN  ' product name (NULL terminated string)
    wTechnology      AS WORD     ' type of device
    wVoices          AS WORD     ' # of voices (internal synth only)
    wNotes           AS WORD     ' max # of notes (internal synth only)
    wChannelMask     AS WORD     ' channels used (internal synth only)
    dwSupport        AS DWORD    ' functionality supported by driver
    ManufacturerGuid AS GUID     ' for extensible MID mapping
    ProductGuid      AS GUID     ' for extensible PID mapping
    NameGuid         AS GUID     ' for name lookup in registry
END TYPE

#IF %DEF(%UNICODE)
TYPE MIDIOUTCAPS2
    MIDIOUTCAPS2W
END TYPE
#ELSE
TYPE MIDIOUTCAPS2
    MIDIOUTCAPS2A
END TYPE
#ENDIF ' %UNICODE

' flags for wTechnology field of MIDIOUTCAPS structure
%MOD_MIDIPORT  = 1  ' output port
%MOD_SYNTH     = 2  ' generic internal synth
%MOD_SQSYNTH   = 3  ' square wave internal synth
%MOD_FMSYNTH   = 4  ' FM internal synth
%MOD_MAPPER    = 5  ' MIDI mapper
%MOD_WAVETABLE = 6  ' hardware wavetable synth
%MOD_SWSYNTH   = 7  ' software synth

' flags for dwSupport field of MIDIOUTCAPS structure
%MIDICAPS_VOLUME       = &H0001  ' supports volume control
%MIDICAPS_LRVOLUME     = &H0002  ' separate left-right volume control
%MIDICAPS_CACHE        = &H0004
#IF (%WINVER >= &H0400)
%MIDICAPS_STREAM       = &H0008  ' driver supports midiStreamOut directly
#ENDIF ' WINVER >= &H0400

' MIDI input device capabilities structure

TYPE MIDIINCAPSA
    wMid           AS WORD    ' manufacturer ID
    wPid           AS WORD    ' product ID
    vDriverVersion AS DWORD   ' version of the driver
    szPname        AS ASCIIZ * %MAXPNAMELEN   ' product name (NULL terminated string)
#IF (%WINVER >= &H0400)
    dwSupport      AS DWORD   ' functionality supported by driver
#ENDIF
END TYPE

TYPE MIDIINCAPSW
    wMid           AS WORD    ' manufacturer ID
    wPid           AS WORD    ' product ID
    vDriverVersion AS DWORD   ' version of the driver
    szPname        AS WSTRINGZ * %MAXPNAMELEN   ' product name (NULL terminated string)
#IF (%WINVER >= &H0400)
    dwSupport      AS DWORD   ' functionality supported by driver
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
TYPE MIDIINCAPS
    MIDIINCAPSW
END TYPE
#ELSE
TYPE MIDIINCAPS
    MIDIINCAPSA
END TYPE
#ENDIF ' %UNICODE

TYPE MIDIINCAPS2A
    wMid             AS WORD     ' manufacturer ID
    wPid             AS WORD     ' product ID
    vDriverVersion   AS DWORD    ' version of the driver
    szPname          AS ASCIIZ * %MAXPNAMELEN   ' product name (NULL terminated string)
#IF (%WINVER >= &H0400)
    dwSupport        AS DWORD    ' functionality supported by driver
#ENDIF
    ManufacturerGuid AS GUID     ' for extensible MID mapping
    ProductGuid      AS GUID     ' for extensible PID mapping
    NameGuid         AS GUID     ' for name lookup in registry
END TYPE

TYPE MIDIINCAPS2W
    wMid             AS WORD     ' manufacturer ID
    wPid             AS WORD     ' product ID
    vDriverVersion   AS DWORD    ' version of the driver
    szPname          AS WSTRINGZ * %MAXPNAMELEN   ' product name (NULL terminated string)
#IF (%WINVER >= &H0400)
    dwSupport        AS DWORD    ' functionality supported by driver
#ENDIF
    ManufacturerGuid AS GUID     ' for extensible MID mapping
    ProductGuid      AS GUID     ' for extensible PID mapping
    NameGuid         AS GUID     ' for name lookup in registry
END TYPE

#IF %DEF(%UNICODE)
TYPE MIDIINCAPS2
    MIDIINCAPS2W
END TYPE
#ELSE
TYPE MIDIINCAPS2
    MIDIINCAPS2A
END TYPE
#ENDIF ' %UNICODE


' MIDI data block header
TYPE MIDIHDR
    lpData          AS ASCIIZ PTR     ' pointer to locked data block
    dwBufferLength  AS DWORD          ' length of data in data block
    dwBytesRecorded AS DWORD          ' used for input only
    dwUser          AS DWORD          ' for client's use
    dwFlags         AS DWORD          ' assorted flags (see defines)
    lpNext          AS DWORD          ' reserved for driver
    reserved        AS DWORD          ' reserved for driver
#IF (%WINVER >= &H0400)
    dwOffset        AS DWORD          ' Callback offset into buffer
    dwReserved(7)   AS DWORD          ' Reserved for MMSYSTEM
#ENDIF
END TYPE


#IF (%WINVER >= &H0400)
TYPE MIDIEVENT
    dwDeltaTime AS DWORD        ' Ticks since last event
    dwStreamID  AS DWORD        ' Reserved; must be zero
    dwEvent     AS DWORD        ' Event type and parameters
    dwParms(0)  AS DWORD        ' Parameters if this is a long event
END TYPE

TYPE MIDISTRMBUFFER
    dwVersion    AS DWORD       ' Stream buffer format version
    dwMid        AS DWORD       ' Manufacturer ID as defined in MMREG.H
    dwOEMVersion AS DWORD       ' Manufacturer version for custom ext
END TYPE
#ENDIF ' WINVER >= &H0400

' flags for dwFlags field of MIDIHDR structure
%MHDR_DONE     = &H00000001       ' done bit
%MHDR_PREPARED = &H00000002       ' set if header prepared
%MHDR_INQUEUE  = &H00000004       ' reserved for driver
%MHDR_ISSTRM   = &H00000008       ' Buffer is stream buffer

#IF (%WINVER >= &H0400)
'
' Type codes which go in the high byte of the event DWORD of a stream buffer
'
' Type codes 00-7F contain parameters within the low 24 bits
' Type codes 80-FF contain a length of their parameter in the low 24
' bits, followed by their parameter data in the buffer. The event
' DWORD contains the exact byte length; the parm data itself must be
' padded to be an even multiple of 4 bytes long.
'

%MEVT_F_SHORT      = &H00000000
%MEVT_F_LONG       = &H80000000???
%MEVT_F_CALLBACK   = &H40000000

MACRO FUNCTION MEVT_EVENTTYPE(x)=HI(BYTE,HI(WORD,x))
MACRO MEVT_EVENTPARM(x)=((x) AND &H00FFFFFF)

%MEVT_SHORTMSG       = &H00    ' parm = shortmsg for midiOutShortMsg
%MEVT_TEMPO          = &H01    ' parm = new tempo in microsec/qn
%MEVT_NOP            = &H02    ' parm = unused; does nothing

' &H04-&H7F reserved

%MEVT_LONGMSG        = &H80?   ' parm = bytes to send verbatim
%MEVT_COMMENT        = &H82?   ' parm = comment data
%MEVT_VERSION        = &H84?   ' parm = MIDISTRMBUFFVER struct

' &H81-&HFF reserved

%MIDISTRM_ERROR      = -2

'
' Structures and defines for midiStreamProperty
'
%MIDIPROP_SET      = &H80000000???
%MIDIPROP_GET      = &H40000000

' These are intentionally both non-zero so the app cannot accidentally
' leave the operation off and happen to appear to work due to default
' action.

%MIDIPROP_TIMEDIV  = &H00000001
%MIDIPROP_TEMPO    = &H00000002

TYPE MIDIPROPTIMEDIV
    cbStruct  AS DWORD
    dwTimeDiv AS DWORD
END TYPE

TYPE MIDIPROPTEMPO
    cbStruct AS DWORD
    dwTempo  AS DWORD
END TYPE

#ENDIF ' WINVER >= &H0400

' MIDI function prototypes

DECLARE FUNCTION midiOutGetNumDevs LIB "WINMM.DLL" ALIAS "midiOutGetNumDevs" _
    () AS DWORD

#IF (%WINVER >= &H0400)

DECLARE FUNCTION midiStreamOpen LIB "WINMM.DLL" ALIAS "midiStreamOpen" _
    (phms AS DWORD, puDeviceId AS DWORD, BYVAL cMidi AS DWORD, _
    BYVAL dwCallback AS DWORD, BYVAL dwInstance AS DWORD, _
    BYVAL fdwOpen AS DWORD) AS DWORD

DECLARE FUNCTION midiStreamClose LIB "WINMM.DLL" ALIAS "midiStreamClose" _
    (BYVAL hms AS DWORD) AS DWORD

DECLARE FUNCTION midiStreamProperty LIB "WINMM.DLL" _
    ALIAS "midiStreamProperty" (BYVAL hms AS DWORD, _
    BYVAL lppropdata AS BYTE PTR, BYVAL dwProperty AS DWORD) AS DWORD

DECLARE FUNCTION midiStreamPosition LIB "WINMM.DLL" _
    ALIAS "midiStreamPosition" (BYVAL hms AS DWORD, _
    BYVAL lpmmt AS MMTIME PTR, BYVAL cbmmt AS DWORD) AS DWORD

DECLARE FUNCTION midiStreamOut LIB "WINMM.DLL" ALIAS "midiStreamOut" _
    (BYVAL hms AS DWORD, BYVAL pmh AS MIDIHDR PTR, BYVAL cbMidiHdr AS DWORD) _
    AS LONG

DECLARE FUNCTION midiStreamPause LIB "WINMM.DLL" ALIAS "midiStreamPause" _
    (BYVAL hms AS DWORD) AS DWORD

DECLARE FUNCTION midiStreamRestart LIB "WINMM.DLL" ALIAS "midiStreamRestart" _
    (BYVAL hms AS DWORD) AS DWORD

DECLARE FUNCTION midiStreamStop LIB "WINMM.DLL" ALIAS "midiStreamStop" _
    (BYVAL hms AS DWORD) AS DWORD

DECLARE FUNCTION midiConnect LIB "WINMM.DLL" ALIAS "midiConnect" _
    (BYVAL hmi AS DWORD, BYVAL hmo AS DWORD, pReserved AS DWORD) AS DWORD

DECLARE FUNCTION midiDisconnect LIB "WINMM.DLL" ALIAS "midiDisconnect" _
    (BYVAL hmi AS DWORD, BYVAL hmo AS DWORD, pReserved AS DWORD) AS DWORD

#ENDIF ' WINVER >= &H0400

DECLARE FUNCTION midiOutGetDevCapsA LIB "WINMM.DLL" _
    ALIAS "midiOutGetDevCapsA" (BYVAL uDeviceID AS DWORD, _
    BYVAL lpCaps AS MIDIOUTCAPSA PTR, BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION midiOutGetDevCapsW LIB "WINMM.DLL" _
    ALIAS "midiOutGetDevCapsW" (BYVAL uDeviceID AS DWORD, _
    BYVAL lpCaps AS MIDIOUTCAPSW PTR, BYVAL uSize AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION midiOutGetDevCaps LIB "WINMM.DLL" _
    ALIAS "midiOutGetDevCapsW" (BYVAL uDeviceID AS DWORD, _
    BYVAL lpCaps AS MIDIOUTCAPSW PTR, BYVAL uSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION midiOutGetDevCaps LIB "WINMM.DLL" _
    ALIAS "midiOutGetDevCapsA" (BYVAL uDeviceID AS DWORD, _
    BYVAL lpCaps AS MIDIOUTCAPSA PTR, BYVAL uSize AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION midiOutGetVolume LIB "WINMM.DLL" ALIAS "midiOutGetVolume" _
    (BYVAL uDeviceID AS DWORD, lpdwVolume AS DWORD) AS DWORD

DECLARE FUNCTION midiOutSetVolume LIB "WINMM.DLL" ALIAS "midiOutSetVolume" _
    (BYVAL uDeviceID AS DWORD, BYVAL dwVolume AS DWORD) AS DWORD

DECLARE FUNCTION midiOutGetErrorTextA LIB "WINMM.DLL" _
    ALIAS "midiOutGetErrorTextA" (BYVAL xerr AS DWORD, lpText AS ASCIIZ, _
    BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION midiOutGetErrorTextW LIB "WINMM.DLL" _
    ALIAS "midiOutGetErrorTextW" (BYVAL xerr AS DWORD, lpText AS WSTRINGZ, _
    BYVAL uSize AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION midiOutGetErrorText LIB "WINMM.DLL" _
    ALIAS "midiOutGetErrorTextW" (BYVAL xerr AS DWORD, lpText AS WSTRINGZ, _
    BYVAL uSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION midiOutGetErrorText LIB "WINMM.DLL" _
    ALIAS "midiOutGetErrorTextA" (BYVAL xerr AS DWORD, lpText AS ASCIIZ, _
    BYVAL uSize AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION midiOutOpen LIB "WINMM.DLL" ALIAS "midiOutOpen" _
    (lphMidiOut AS DWORD, BYVAL uDeviceID AS DWORD, _
    BYVAL dwCallback AS DWORD, BYVAL dwInstance AS DWORD, _
    BYVAL dwFlags AS DWORD) AS DWORD

DECLARE FUNCTION midiOutClose LIB "WINMM.DLL" ALIAS "midiOutClose" _
    (BYVAL hMidiOut AS DWORD) AS DWORD

DECLARE FUNCTION midiOutPrepareHeader LIB "WINMM.DLL" _
    ALIAS "midiOutPrepareHeader" (BYVAL hMidiOut AS DWORD, _
    lpMidiOutHdr AS MIDIHDR, BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION midiOutUnprepareHeader LIB "WINMM.DLL" _
    ALIAS "midiOutUnprepareHeader" (BYVAL hMidiOut AS DWORD, _
    lpMidiOutHdr AS MIDIHDR, BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION midiOutShortMsg LIB "WINMM.DLL" ALIAS "midiOutShortMsg" _
    (BYVAL hMidiOut AS DWORD, BYVAL dwMsg AS DWORD) AS DWORD

DECLARE FUNCTION midiOutLongMsg LIB "WINMM.DLL" ALIAS "midiOutLongMsg" _
    (BYVAL hMidiOut AS DWORD, BYVAL lpMidiOutHdr AS MIDIHDR PTR, _
    BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION midiOutReset LIB "WINMM.DLL" ALIAS "midiOutReset" _
    (BYVAL hMidiOut AS DWORD) AS DWORD

DECLARE FUNCTION midiOutCachePatches LIB "WINMM.DLL" _
    ALIAS "midiOutCachePatches" (BYVAL hMidiOut AS DWORD, _
    BYVAL uBank AS DWORD, BYVAL lpPatchArray AS WORD PTR, _
    BYVAL uFlags AS DWORD) AS DWORD

DECLARE FUNCTION midiOutCacheDrumPatches LIB "WINMM.DLL" _
    ALIAS "midiOutCacheDrumPatches" (BYVAL hMidiOut AS DWORD, _
    BYVAL uPatch AS DWORD, BYVAL lpKeyArray AS WORD PTR, _
    BYVAL uFlags AS DWORD) AS DWORD

DECLARE FUNCTION midiOutGetID LIB "WINMM.DLL" ALIAS "midiOutGetID" _
    (BYVAL hMidiOut AS DWORD, lpuDeviceId AS DWORD) AS DWORD

#IF (%WINVER >= &H030a)

DECLARE FUNCTION midiOutMessage LIB "WINMM.DLL" ALIAS "midiOutMessage" _
    (BYVAL hMidiOut AS DWORD, BYVAL msg AS DWORD, BYVAL dw1 AS DWORD, _
    BYVAL dw2 AS DWORD) AS DWORD

#ENDIF ' ifdef WINVER >= &H030a

DECLARE FUNCTION midiInGetNumDevs LIB "WINMM.DLL" ALIAS "midiInGetNumDevs" () _
    AS DWORD

DECLARE FUNCTION midiInGetDevCapsA LIB "WINMM.DLL" ALIAS "midiInGetDevCapsA" _
    (BYVAL uDeviceID AS DWORD, lpCaps AS MIDIINCAPSA, BYVAL uSize AS DWORD) _
    AS DWORD

DECLARE FUNCTION midiInGetDevCapsW LIB "WINMM.DLL" ALIAS "midiInGetDevCapsW" _
    (BYVAL uDeviceID AS DWORD, lpCaps AS MIDIINCAPSW, BYVAL uSize AS DWORD) _
    AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION midiInGetDevCaps LIB "WINMM.DLL" ALIAS "midiInGetDevCapsW" _
    (BYVAL uDeviceID AS DWORD, lpCaps AS MIDIINCAPSW, BYVAL uSize AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION midiInGetDevCaps LIB "WINMM.DLL" ALIAS "midiInGetDevCapsA" _
    (BYVAL uDeviceID AS DWORD, lpCaps AS MIDIINCAPSA, BYVAL uSize AS DWORD) _
    AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION midiInGetErrorTextA LIB "WINMM.DLL" _
    ALIAS "midiInGetErrorTextA" (BYVAL xerr AS DWORD, lpText AS ASCIIZ, _
    BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION midiInGetErrorTextW LIB "WINMM.DLL" _
    ALIAS "midiInGetErrorTextW" (BYVAL xerr AS DWORD, lpText AS WSTRINGZ, _
    BYVAL uSize AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION midiInGetErrorText LIB "WINMM.DLL" _
    ALIAS "midiInGetErrorTextW" (BYVAL xerr AS DWORD, lpText AS WSTRINGZ, _
    BYVAL uSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION midiInGetErrorText LIB "WINMM.DLL" _
    ALIAS "midiInGetErrorTextA" (BYVAL xerr AS DWORD, lpText AS ASCIIZ, _
    BYVAL uSize AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION midiInOpen LIB "WINMM.DLL" ALIAS "midiInOpen" _
    (lphMidiIn AS DWORD, BYVAL uDeviceID AS DWORD, BYVAL dwCallback AS DWORD, _
    BYVAL dwInstance AS DWORD, BYVAL dwFlags AS DWORD) AS DWORD

DECLARE FUNCTION midiInClose LIB "WINMM.DLL" ALIAS "midiInClose" _
    (BYVAL hMidiIn AS DWORD) AS DWORD

DECLARE FUNCTION midiInPrepareHeader LIB "WINMM.DLL" _
    ALIAS "midiInPrepareHeader" (BYVAL hMidiIn AS DWORD, _
    lpMidiInHdr AS MIDIHDR, BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION midiInUnprepareHeader LIB "WINMM.DLL" _
    ALIAS "midiInUnprepareHeader" (BYVAL hMidiIn AS DWORD, _
    lpMidiInHdr AS MIDIHDR, BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION midiInAddBuffer LIB "WINMM.DLL" ALIAS "midiInAddBuffer" _
    (BYVAL hMidiIn AS DWORD, lpMidiInHdr AS MIDIHDR, BYVAL uSize AS DWORD) _
    AS DWORD

DECLARE FUNCTION midiInStart LIB "WINMM.DLL" ALIAS "midiInStart" _
    (BYVAL hMidiIn AS DWORD) AS DWORD

DECLARE FUNCTION midiInStop LIB "WINMM.DLL" ALIAS "midiInStop" _
    (BYVAL hMidiIn AS DWORD) AS DWORD

DECLARE FUNCTION midiInReset LIB "WINMM.DLL" ALIAS "midiInReset" _
    (BYVAL hMidiIn AS DWORD) AS DWORD

DECLARE FUNCTION midiInGetID LIB "WINMM.DLL" ALIAS "midiInGetID" _
    (BYVAL hMidiIn AS DWORD, lpuDeviceId AS DWORD) AS DWORD

#IF (%WINVER >= &H030a)

DECLARE FUNCTION midiInMessage LIB "WINMM.DLL" ALIAS "midiInMessage" _
    (BYVAL hMidiIn AS DWORD, BYVAL msg AS DWORD, BYVAL dw1 AS DWORD, _
    BYVAL dw2 AS DWORD) AS DWORD

#ENDIF ' ifdef WINVER >= &H030a


#ENDIF  ' ifndef MMNOMIDI


#IF NOT %DEF(%MMNOAUX)
'****************************************************************************
'
'                       Auxiliary audio support
'
'****************************************************************************

' device ID for aux device mapper
%AUX_MAPPER = &HFFFFFFFF???   '    ((DWORD)-1)


' Auxiliary audio device capabilities structure

TYPE AUXCAPSA
    wMid           AS WORD      ' manufacturer ID
    wPid           AS WORD      ' product ID
    vDriverVersion AS DWORD     ' version of the driver
    szPname        AS ASCIIZ * %MAXPNAMELEN ' product name (NULL terminated string)
    wTechnology    AS WORD      ' type of device
    wReserved1     AS WORD      ' padding
    dwSupport      AS DWORD     ' functionality supported by driver
END TYPE

TYPE AUXCAPSW
    wMid           AS WORD      ' manufacturer ID
    wPid           AS WORD      ' product ID
    vDriverVersion AS DWORD     ' version of the driver
    szPname        AS WSTRINGZ * %MAXPNAMELEN ' product name (NULL terminated string)
    wTechnology    AS WORD      ' type of device
    wReserved1     AS WORD      ' padding
    dwSupport      AS DWORD     ' functionality supported by driver
END TYPE

#IF %DEF(%UNICODE)
TYPE AUXCAPS
    AUXCAPSW
END TYPE
#ELSE
TYPE AUXCAPS
    AUXCAPSA
END TYPE
#ENDIF ' %UNICODE

TYPE AUXCAPS2A
    wMid             AS WORD     ' manufacturer ID
    wPid             AS WORD     ' product ID
    vDriverVersion   AS DWORD    ' version of the driver
    szPname          AS ASCIIZ * %MAXPNAMELEN ' product name (NULL terminated string)
    wTechnology      AS WORD     ' type of device
    wReserved1       AS WORD     ' padding
    dwSupport        AS DWORD    ' functionality supported by driver
    ManufacturerGuid AS GUID     ' for extensible MID mapping
    ProductGuid      AS GUID     ' for extensible PID mapping
    NameGuid         AS GUID     ' for name lookup in registry
END TYPE

TYPE AUXCAPS2W
    wMid             AS WORD     ' manufacturer ID
    wPid             AS WORD     ' product ID
    vDriverVersion   AS DWORD    ' version of the driver
    szPname          AS WSTRINGZ * %MAXPNAMELEN ' product name (NULL terminated string)
    wTechnology      AS WORD     ' type of device
    wReserved1       AS WORD     ' padding
    dwSupport        AS DWORD    ' functionality supported by driver
    ManufacturerGuid AS GUID     ' for extensible MID mapping
    ProductGuid      AS GUID     ' for extensible PID mapping
    NameGuid         AS GUID     ' for name lookup in registry
END TYPE

#IF %DEF(%UNICODE)
TYPE AUXCAPS2
    AUXCAPS2W
END TYPE
#ELSE
TYPE AUXCAPS2
    AUXCAPS2A
END TYPE
#ENDIF ' %UNICODE

' flags for wTechnology field in AUXCAPS structure
%AUXCAPS_CDAUDIO  = 1       ' audio from internal CD-ROM drive
%AUXCAPS_AUXIN    = 2       ' audio from auxiliary input jacks

' flags for dwSupport field in AUXCAPS structure
%AUXCAPS_VOLUME       = &H0001  ' supports volume control
%AUXCAPS_LRVOLUME     = &H0002  ' separate left-right volume control

' auxiliary audio function prototypes
DECLARE FUNCTION auxGetNumDevs LIB "WINMM.DLL" ALIAS "auxGetNumDevs" () _
    AS DWORD

DECLARE FUNCTION auxGetDevCapsA LIB "WINMM.DLL" ALIAS "auxGetDevCapsA" _
    (BYVAL uDeviceID AS DWORD, lpCaps AS AUXCAPSA, BYVAL uSize AS DWORD) _
    AS DWORD

DECLARE FUNCTION auxGetDevCapsW LIB "WINMM.DLL" ALIAS "auxGetDevCapsW" _
    (BYVAL uDeviceID AS DWORD, lpCaps AS AUXCAPSW, BYVAL uSize AS DWORD) _
    AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION auxGetDevCaps LIB "WINMM.DLL" ALIAS "auxGetDevCapsW" _
    (BYVAL uDeviceID AS DWORD, lpCaps AS AUXCAPSW, BYVAL uSize AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION auxGetDevCaps LIB "WINMM.DLL" ALIAS "auxGetDevCapsA" _
    (BYVAL uDeviceID AS DWORD, lpCaps AS AUXCAPSA, BYVAL uSize AS DWORD) _
    AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION auxSetVolume LIB "WINMM.DLL" ALIAS "auxSetVolume" _
    (BYVAL uDeviceID AS DWORD, BYVAL dwVolume AS DWORD) AS DWORD

DECLARE FUNCTION auxGetVolume LIB "WINMM.DLL" ALIAS "auxGetVolume" _
    (BYVAL uDeviceID AS DWORD, lpdwVolume AS DWORD) AS DWORD

#IF (%WINVER >= &H030a)

DECLARE FUNCTION auxOutMessage LIB "WINMM.DLL" ALIAS "auxOutMessage" _
    (BYVAL uDeviceID AS DWORD, BYVAL uMsg AS DWORD, BYVAL dwParam1 AS DWORD, _
    BYVAL dwParam2 AS DWORD) AS DWORD

#ENDIF ' ifdef WINVER >= &H030a

#ENDIF  ' ifndef MMNOAUX


#IF NOT %DEF(%MMNOMIXER)
'****************************************************************************
'
'                           Mixer Support
'
'****************************************************************************


%MIXER_SHORT_NAME_CHARS = 16
%MIXER_LONG_NAME_CHARS  = 64

'
'  DWORD error return values specific to the mixer API
'
'
%MIXERR_INVALLINE            = (%MIXERR_BASE + 0)
%MIXERR_INVALCONTROL         = (%MIXERR_BASE + 1)
%MIXERR_INVALVALUE           = (%MIXERR_BASE + 2)
%MIXERR_LASTERROR            = (%MIXERR_BASE + 2)


%MIXER_OBJECTF_HANDLE    = &H80000000???
%MIXER_OBJECTF_MIXER     = &H00000000
%MIXER_OBJECTF_HMIXER    = (%MIXER_OBJECTF_HANDLE OR %MIXER_OBJECTF_MIXER)
%MIXER_OBJECTF_WAVEOUT   = &H10000000
%MIXER_OBJECTF_HWAVEOUT  = (%MIXER_OBJECTF_HANDLE OR %MIXER_OBJECTF_WAVEOUT)
%MIXER_OBJECTF_WAVEIN    = &H20000000
%MIXER_OBJECTF_HWAVEIN   = (%MIXER_OBJECTF_HANDLE OR %MIXER_OBJECTF_WAVEIN)
%MIXER_OBJECTF_MIDIOUT   = &H30000000
%MIXER_OBJECTF_HMIDIOUT  = (%MIXER_OBJECTF_HANDLE OR %MIXER_OBJECTF_MIDIOUT)
%MIXER_OBJECTF_MIDIIN    = &H40000000
%MIXER_OBJECTF_HMIDIIN   = (%MIXER_OBJECTF_HANDLE OR %MIXER_OBJECTF_MIDIIN)
%MIXER_OBJECTF_AUX       = &H50000000

DECLARE FUNCTION mixerGetNumDevs LIB "WINMM.DLL" ALIAS "mixerGetNumDevs" () _
    AS DWORD

TYPE MIXERCAPSA
    wMid           AS WORD       ' manufacturer id
    wPid           AS WORD       ' product id
    vDriverVersion AS DWORD      ' version of the driver
    szPname        AS ASCIIZ * %MAXPNAMELEN   ' product name
    fdwSupport     AS DWORD      ' misc. support bits
    cDestinations  AS DWORD      ' count of destinations
END TYPE

TYPE MIXERCAPSW
    wMid           AS WORD       ' manufacturer id
    wPid           AS WORD       ' product id
    vDriverVersion AS DWORD      ' version of the driver
    szPname        AS WSTRINGZ * %MAXPNAMELEN   ' product name
    fdwSupport     AS DWORD      ' misc. support bits
    cDestinations  AS DWORD      ' count of destinations
END TYPE

#IF %DEF(%UNICODE)
TYPE MIXERCAPS
    MIXERCAPSW
END TYPE
#ELSE
TYPE MIXERCAPS
    MIXERCAPSA
END TYPE
#ENDIF ' %UNICODE

TYPE MIXERCAPS2A
    wMid             AS WORD      ' manufacturer id
    wPid             AS WORD      ' product id
    vDriverVersion   AS DWORD     ' version of the driver
    szPname          AS ASCIIZ * %MAXPNAMELEN   ' product name
    fdwSupport       AS DWORD     ' misc. support bits
    cDestinations    AS DWORD     ' count of destinations
    ManufacturerGuid AS GUID      ' for extensible MID mapping
    ProductGuid      AS GUID      ' for extensible PID mapping
    NameGuid         AS GUID      ' for name lookup in registry
END TYPE

TYPE MIXERCAPS2W
    wMid             AS WORD      ' manufacturer id
    wPid             AS WORD      ' product id
    vDriverVersion   AS DWORD     ' version of the driver
    szPname          AS WSTRINGZ * %MAXPNAMELEN   ' product name
    fdwSupport       AS DWORD     ' misc. support bits
    cDestinations    AS DWORD     ' count of destinations
    ManufacturerGuid AS GUID      ' for extensible MID mapping
    ProductGuid      AS GUID      ' for extensible PID mapping
    NameGuid         AS GUID      ' for name lookup in registry
END TYPE

#IF %DEF(%UNICODE)
TYPE MIXERCAPS2
    MIXERCAPS2W
END TYPE
#ELSE
TYPE MIXERCAPS2
    MIXERCAPS2A
END TYPE
#ENDIF ' %UNICODE

DECLARE FUNCTION mixerGetDevCapsA LIB "WINMM.DLL" ALIAS "mixerGetDevCapsA" _
    (BYVAL uMxId AS DWORD, pmxcaps AS MIXERCAPSA, BYVAL cbmxcaps AS DWORD) _
    AS DWORD

DECLARE FUNCTION mixerGetDevCapsW LIB "WINMM.DLL" ALIAS "mixerGetDevCapsW" _
    (BYVAL uMxId AS DWORD, pmxcaps AS MIXERCAPSW, BYVAL cbmxcaps AS DWORD) _
    AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION mixerGetDevCaps LIB "WINMM.DLL" ALIAS "mixerGetDevCapsW" _
    (BYVAL uMxId AS DWORD, pmxcaps AS MIXERCAPSW, BYVAL cbmxcaps AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION mixerGetDevCaps LIB "WINMM.DLL" ALIAS "mixerGetDevCapsA" _
    (BYVAL uMxId AS DWORD, pmxcaps AS MIXERCAPSA, BYVAL cbmxcaps AS DWORD) _
    AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION mixerOpen LIB "WINMM.DLL" ALIAS "mixerOpen" (phmx AS DWORD, _
    BYVAL uMxId AS DWORD, BYVAL dwCallback AS DWORD, _
    BYVAL dwInstance AS DWORD, BYVAL fdwOpen AS DWORD) AS DWORD

DECLARE FUNCTION mixerClose LIB "WINMM.DLL" ALIAS "mixerClose" _
    (BYVAL hmx AS DWORD) AS DWORD

DECLARE FUNCTION mixerMessage LIB "WINMM.DLL" ALIAS "mixerMessage" _
    (BYVAL hmx AS DWORD, BYVAL uMsg AS DWORD, BYVAL dwParam1 AS DWORD, _
    BYVAL dwParam2 AS DWORD) AS DWORD

TYPE MIXERLINEA_type
    dwType         AS DWORD       ' MIXERLINE_TARGETTYPE_xxxx
    dwDeviceID     AS DWORD       ' target device ID of device type
    wMid           AS WORD        ' of target device
    wPid           AS WORD        '      "
    vDriverVersion AS DWORD       '      "
    szPname        AS ASCIIZ * %MAXPNAMELEN   '    "
END TYPE

TYPE MIXERLINEA
    cbStruct        AS DWORD        ' size of MIXERLINE structure
    dwDestination   AS DWORD        ' zero based destination index
    dwSource        AS DWORD        ' zero based source index (if source)
    dwLineID        AS DWORD        ' unique line id for mixer device
    fdwLine         AS DWORD        ' state/information about line
    dwUser          AS DWORD        ' driver specific information
    dwComponentType AS DWORD        ' component type line connects to
    cChannels       AS DWORD        ' number of channels line supports
    cConnections    AS DWORD        ' number of connections [possible]
    cControls       AS DWORD        ' number of controls at this line
    szShortName     AS ASCIIZ * %MIXER_SHORT_NAME_CHARS
    szName          AS ASCIIZ * %MIXER_LONG_NAME_CHARS
    Target          AS MIXERLINEA_type
END TYPE

TYPE MIXERLINEW_type
    dwType         AS DWORD       ' MIXERLINE_TARGETTYPE_xxxx
    dwDeviceID     AS DWORD       ' target device ID of device type
    wMid           AS WORD        ' of target device
    wPid           AS WORD        '      "
    vDriverVersion AS DWORD       '      "
    szPname        AS WSTRINGZ * %MAXPNAMELEN   '    "
END TYPE

TYPE MIXERLINEW
    cbStruct        AS DWORD        ' size of MIXERLINE structure
    dwDestination   AS DWORD        ' zero based destination index
    dwSource        AS DWORD        ' zero based source index (if source)
    dwLineID        AS DWORD        ' unique line id for mixer device
    fdwLine         AS DWORD        ' state/information about line
    dwUser          AS DWORD        ' driver specific information
    dwComponentType AS DWORD        ' component type line connects to
    cChannels       AS DWORD        ' number of channels line supports
    cConnections    AS DWORD        ' number of connections [possible]
    cControls       AS DWORD        ' number of controls at this line
    szShortName     AS WSTRINGZ * %MIXER_SHORT_NAME_CHARS
    szName          AS WSTRINGZ * %MIXER_LONG_NAME_CHARS
    Target          AS MIXERLINEW_type
END TYPE

#IF %DEF(%UNICODE)
TYPE MIXERLINE
    MIXERLINEW
END TYPE
TYPE MIXERLINE_type
    MIXERLINEW_type
END TYPE
#ELSE
TYPE MIXERLINE
    MIXERLINEA
END TYPE
TYPE MIXERLINE_type
    MIXERLINEA_type
END TYPE
#ENDIF ' %UNICODE

'
'  MIXERLINE.fdwLine
'
'
%MIXERLINE_LINEF_ACTIVE            = &H00000001
%MIXERLINE_LINEF_DISCONNECTED      = &H00008000
%MIXERLINE_LINEF_SOURCE            = &H80000000???


'
'  MIXERLINE.dwComponentType
'
'  component types for destinations and sources
'
'
%MIXERLINE_COMPONENTTYPE_DST_FIRST     = &H00000000
%MIXERLINE_COMPONENTTYPE_DST_UNDEFINED   = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 0
%MIXERLINE_COMPONENTTYPE_DST_DIGITAL     = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 1
%MIXERLINE_COMPONENTTYPE_DST_LINE        = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 2
%MIXERLINE_COMPONENTTYPE_DST_MONITOR     = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 3
%MIXERLINE_COMPONENTTYPE_DST_SPEAKERS    = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 4
%MIXERLINE_COMPONENTTYPE_DST_HEADPHONES  = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 5
%MIXERLINE_COMPONENTTYPE_DST_TELEPHONE   = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 6
%MIXERLINE_COMPONENTTYPE_DST_WAVEIN      = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 7
%MIXERLINE_COMPONENTTYPE_DST_VOICEIN     = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 8
%MIXERLINE_COMPONENTTYPE_DST_LAST        = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 8

%MIXERLINE_COMPONENTTYPE_SRC_FIRST     = &H00001000
%MIXERLINE_COMPONENTTYPE_SRC_UNDEFINED   = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 0
%MIXERLINE_COMPONENTTYPE_SRC_DIGITAL     = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 1
%MIXERLINE_COMPONENTTYPE_SRC_LINE        = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 2
%MIXERLINE_COMPONENTTYPE_SRC_MICROPHONE  = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 3
%MIXERLINE_COMPONENTTYPE_SRC_SYNTHESIZER = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 4
%MIXERLINE_COMPONENTTYPE_SRC_COMPACTDISC = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 5
%MIXERLINE_COMPONENTTYPE_SRC_TELEPHONE   = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 6
%MIXERLINE_COMPONENTTYPE_SRC_PCSPEAKER   = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 7
%MIXERLINE_COMPONENTTYPE_SRC_WAVEOUT     = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 8
%MIXERLINE_COMPONENTTYPE_SRC_AUXILIARY   = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 9
%MIXERLINE_COMPONENTTYPE_SRC_ANALOG      = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 10
%MIXERLINE_COMPONENTTYPE_SRC_LAST        = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 10


'
'  MIXERLINE.Target.dwType
'
'
%MIXERLINE_TARGETTYPE_UNDEFINED    = 0
%MIXERLINE_TARGETTYPE_WAVEOUT      = 1
%MIXERLINE_TARGETTYPE_WAVEIN       = 2
%MIXERLINE_TARGETTYPE_MIDIOUT      = 3
%MIXERLINE_TARGETTYPE_MIDIIN       = 4
%MIXERLINE_TARGETTYPE_AUX          = 5

DECLARE FUNCTION mixerGetLineInfoA LIB "WINMM.DLL" ALIAS "mixerGetLineInfoA" _
    (BYVAL hmxobj AS DWORD, pmxl AS MIXERLINEA, BYVAL fdwInfo AS DWORD) _
    AS DWORD

DECLARE FUNCTION mixerGetLineInfoW LIB "WINMM.DLL" ALIAS "mixerGetLineInfoW" _
    (BYVAL hmxobj AS DWORD, pmxl AS MIXERLINEW, BYVAL fdwInfo AS DWORD) _
    AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION mixerGetLineInfo LIB "WINMM.DLL" ALIAS "mixerGetLineInfoW" _
    (BYVAL hmxobj AS DWORD, pmxl AS MIXERLINEW, BYVAL fdwInfo AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION mixerGetLineInfo LIB "WINMM.DLL" ALIAS "mixerGetLineInfoA" _
    (BYVAL hmxobj AS DWORD, pmxl AS MIXERLINEA, BYVAL fdwInfo AS DWORD) _
    AS DWORD
#ENDIF ' NOT %UNICODE

%MIXER_GETLINEINFOF_DESTINATION    = &H00000000
%MIXER_GETLINEINFOF_SOURCE         = &H00000001
%MIXER_GETLINEINFOF_LINEID         = &H00000002
%MIXER_GETLINEINFOF_COMPONENTTYPE  = &H00000003
%MIXER_GETLINEINFOF_TARGETTYPE     = &H00000004

%MIXER_GETLINEINFOF_QUERYMASK      = &H0000000F


DECLARE FUNCTION mixerGetID LIB "WINMM.DLL" ALIAS "mixerGetID" _
    (BYVAL hmxobj AS DWORD, pumxId AS DWORD, BYVAL fdwId AS DWORD) AS DWORD


'
'  MIXERCONTROL
'
'

TYPE MIXERCONTROL_type1
    lMinimum AS LONG               ' signed minimum for this control
    lMaximum AS LONG               ' signed maximum for this control
END TYPE

TYPE MIXERCONTROL_type2
    dwMinimum AS DWORD             ' unsigned minimum for this control
    dwMaximum AS DWORD             ' unsigned maximum for this control
END TYPE

UNION MIXERCONTROL_Bounds
    MIXERCONTROL_type1
    MIXERCONTROL_type2
    dwReserved(5) AS DWORD
END UNION

UNION MIXERCONTROL_Metrics
    cSteps AS DWORD               ' # of steps between min & max
    cbCustomData AS DWORD         ' size in bytes of custom data
    dwReserved(5) AS DWORD        ' !!! needed? we have cbStruct....
END UNION

TYPE MIXERCONTROLA
    cbStruct       AS DWORD            ' size in bytes of MIXERCONTROL
    dwControlID    AS DWORD            ' unique control id for mixer device
    dwControlType  AS DWORD            ' MIXERCONTROL_CONTROLTYPE_xxx
    fdwControl     AS DWORD            ' MIXERCONTROL_CONTROLF_xxx
    cMultipleItems AS DWORD            ' if MIXERCONTROL_CONTROLF_MULTIPLE set
    szShortName    AS ASCIIZ * %MIXER_SHORT_NAME_CHARS
    szName         AS ASCIIZ * %MIXER_LONG_NAME_CHARS
    Bounds         AS MIXERCONTROL_Bounds
    Metrics        AS MIXERCONTROL_Metrics
END TYPE

TYPE MIXERCONTROLW
    cbStruct       AS DWORD            ' size in bytes of MIXERCONTROL
    dwControlID    AS DWORD            ' unique control id for mixer device
    dwControlType  AS DWORD            ' MIXERCONTROL_CONTROLTYPE_xxx
    fdwControl     AS DWORD            ' MIXERCONTROL_CONTROLF_xxx
    cMultipleItems AS DWORD            ' if MIXERCONTROL_CONTROLF_MULTIPLE set
    szShortName    AS WSTRINGZ * %MIXER_SHORT_NAME_CHARS
    szName         AS WSTRINGZ * %MIXER_LONG_NAME_CHARS
    Bounds         AS MIXERCONTROL_Bounds
    Metrics        AS MIXERCONTROL_Metrics
END TYPE

#IF %DEF(%UNICODE)
TYPE MIXERCONTROL
    MIXERCONTROLW
END TYPE
#ELSE
TYPE MIXERCONTROL
    MIXERCONTROLA
END TYPE
#ENDIF ' %UNICODE

'
'  MIXERCONTROL.fdwControl
'
'
%MIXERCONTROL_CONTROLF_UNIFORM  = &H00000001
%MIXERCONTROL_CONTROLF_MULTIPLE = &H00000002
%MIXERCONTROL_CONTROLF_DISABLED = &H80000000???


'
'  MIXERCONTROL_CONTROLTYPE_xxx building block defines
'
'
%MIXERCONTROL_CT_CLASS_MASK         = &HF0000000???
%MIXERCONTROL_CT_CLASS_CUSTOM       = &H00000000
%MIXERCONTROL_CT_CLASS_METER        = &H10000000
%MIXERCONTROL_CT_CLASS_SWITCH       = &H20000000
%MIXERCONTROL_CT_CLASS_NUMBER       = &H30000000
%MIXERCONTROL_CT_CLASS_SLIDER       = &H40000000
%MIXERCONTROL_CT_CLASS_FADER        = &H50000000
%MIXERCONTROL_CT_CLASS_TIME         = &H60000000
%MIXERCONTROL_CT_CLASS_LIST         = &H70000000


%MIXERCONTROL_CT_SUBCLASS_MASK      = &H0F000000

%MIXERCONTROL_CT_SC_SWITCH_BOOLEAN  = &H00000000
%MIXERCONTROL_CT_SC_SWITCH_BUTTON   = &H01000000

%MIXERCONTROL_CT_SC_METER_POLLED    = &H00000000

%MIXERCONTROL_CT_SC_TIME_MICROSECS  = &H00000000
%MIXERCONTROL_CT_SC_TIME_MILLISECS  = &H01000000

%MIXERCONTROL_CT_SC_LIST_SINGLE     = &H00000000
%MIXERCONTROL_CT_SC_LIST_MULTIPLE   = &H01000000


%MIXERCONTROL_CT_UNITS_MASK         = &H00FF0000
%MIXERCONTROL_CT_UNITS_CUSTOM       = &H00000000
%MIXERCONTROL_CT_UNITS_BOOLEAN      = &H00010000
%MIXERCONTROL_CT_UNITS_SIGNED       = &H00020000
%MIXERCONTROL_CT_UNITS_UNSIGNED     = &H00030000
%MIXERCONTROL_CT_UNITS_DECIBELS     = &H00040000 ' in 10ths
%MIXERCONTROL_CT_UNITS_PERCENT      = &H00050000 ' in 10ths


'
'  Commonly used control types for specifying MIXERCONTROL.dwControlType
'

%MIXERCONTROL_CONTROLTYPE_CUSTOM         = %MIXERCONTROL_CT_CLASS_CUSTOM OR %MIXERCONTROL_CT_UNITS_CUSTOM
%MIXERCONTROL_CONTROLTYPE_BOOLEANMETER   = %MIXERCONTROL_CT_CLASS_METER OR %MIXERCONTROL_CT_SC_METER_POLLED OR %MIXERCONTROL_CT_UNITS_BOOLEAN
%MIXERCONTROL_CONTROLTYPE_SIGNEDMETER    = %MIXERCONTROL_CT_CLASS_METER OR %MIXERCONTROL_CT_SC_METER_POLLED OR %MIXERCONTROL_CT_UNITS_SIGNED
%MIXERCONTROL_CONTROLTYPE_PEAKMETER      = %MIXERCONTROL_CONTROLTYPE_SIGNEDMETER + 1
%MIXERCONTROL_CONTROLTYPE_UNSIGNEDMETER  = %MIXERCONTROL_CT_CLASS_METER OR %MIXERCONTROL_CT_SC_METER_POLLED OR %MIXERCONTROL_CT_UNITS_UNSIGNED
%MIXERCONTROL_CONTROLTYPE_BOOLEAN        = %MIXERCONTROL_CT_CLASS_SWITCH OR %MIXERCONTROL_CT_SC_SWITCH_BOOLEAN OR %MIXERCONTROL_CT_UNITS_BOOLEAN
%MIXERCONTROL_CONTROLTYPE_ONOFF          = %MIXERCONTROL_CONTROLTYPE_BOOLEAN + 1
%MIXERCONTROL_CONTROLTYPE_MUTE           = %MIXERCONTROL_CONTROLTYPE_BOOLEAN + 2
%MIXERCONTROL_CONTROLTYPE_MONO           = %MIXERCONTROL_CONTROLTYPE_BOOLEAN + 3
%MIXERCONTROL_CONTROLTYPE_LOUDNESS       = %MIXERCONTROL_CONTROLTYPE_BOOLEAN + 4
%MIXERCONTROL_CONTROLTYPE_STEREOENH      = %MIXERCONTROL_CONTROLTYPE_BOOLEAN + 5
%MIXERCONTROL_CONTROLTYPE_BASS_BOOST     = %MIXERCONTROL_CONTROLTYPE_BOOLEAN + &H00002277
%MIXERCONTROL_CONTROLTYPE_BUTTON         = %MIXERCONTROL_CT_CLASS_SWITCH OR %MIXERCONTROL_CT_SC_SWITCH_BUTTON OR %MIXERCONTROL_CT_UNITS_BOOLEAN
%MIXERCONTROL_CONTROLTYPE_DECIBELS       = %MIXERCONTROL_CT_CLASS_NUMBER OR %MIXERCONTROL_CT_UNITS_DECIBELS
%MIXERCONTROL_CONTROLTYPE_SIGNED         = %MIXERCONTROL_CT_CLASS_NUMBER OR %MIXERCONTROL_CT_UNITS_SIGNED
%MIXERCONTROL_CONTROLTYPE_UNSIGNED       = %MIXERCONTROL_CT_CLASS_NUMBER OR %MIXERCONTROL_CT_UNITS_UNSIGNED
%MIXERCONTROL_CONTROLTYPE_PERCENT        = %MIXERCONTROL_CT_CLASS_NUMBER OR %MIXERCONTROL_CT_UNITS_PERCENT
%MIXERCONTROL_CONTROLTYPE_SLIDER         = %MIXERCONTROL_CT_CLASS_SLIDER OR %MIXERCONTROL_CT_UNITS_SIGNED
%MIXERCONTROL_CONTROLTYPE_PAN            = %MIXERCONTROL_CONTROLTYPE_SLIDER + 1
%MIXERCONTROL_CONTROLTYPE_QSOUNDPAN      = %MIXERCONTROL_CONTROLTYPE_SLIDER + 2
%MIXERCONTROL_CONTROLTYPE_FADER          = %MIXERCONTROL_CT_CLASS_FADER OR %MIXERCONTROL_CT_UNITS_UNSIGNED
%MIXERCONTROL_CONTROLTYPE_VOLUME         = %MIXERCONTROL_CONTROLTYPE_FADER + 1
%MIXERCONTROL_CONTROLTYPE_BASS           = %MIXERCONTROL_CONTROLTYPE_FADER + 2
%MIXERCONTROL_CONTROLTYPE_TREBLE         = %MIXERCONTROL_CONTROLTYPE_FADER + 3
%MIXERCONTROL_CONTROLTYPE_EQUALIZER      = %MIXERCONTROL_CONTROLTYPE_FADER + 4
%MIXERCONTROL_CONTROLTYPE_SINGLESELECT   = %MIXERCONTROL_CT_CLASS_LIST OR %MIXERCONTROL_CT_SC_LIST_SINGLE OR %MIXERCONTROL_CT_UNITS_BOOLEAN
%MIXERCONTROL_CONTROLTYPE_MUX            = %MIXERCONTROL_CONTROLTYPE_SINGLESELECT + 1
%MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT = %MIXERCONTROL_CT_CLASS_LIST OR %MIXERCONTROL_CT_SC_LIST_MULTIPLE OR %MIXERCONTROL_CT_UNITS_BOOLEAN
%MIXERCONTROL_CONTROLTYPE_MIXER          = %MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT + 1
%MIXERCONTROL_CONTROLTYPE_MICROTIME      = %MIXERCONTROL_CT_CLASS_TIME OR %MIXERCONTROL_CT_SC_TIME_MICROSECS OR %MIXERCONTROL_CT_UNITS_UNSIGNED
%MIXERCONTROL_CONTROLTYPE_MILLITIME      = %MIXERCONTROL_CT_CLASS_TIME OR %MIXERCONTROL_CT_SC_TIME_MILLISECS OR %MIXERCONTROL_CT_UNITS_UNSIGNED

'
'  MIXERLINECONTROLS
'
UNION MIXERLINECONTROLS_union
    dwControlID   AS DWORD         ' MIXER_GETLINECONTROLSF_ONEBYID
    dwControlType AS DWORD         ' MIXER_GETLINECONTROLSF_ONEBYTYPE
END UNION

TYPE MIXERLINECONTROLSA
    cbStruct  AS DWORD             ' size in bytes of MIXERLINECONTROLS
    dwLineID  AS DWORD             ' line id (from MIXERLINE.dwLineID)
    MIXERLINECONTROLS_union
    cControls AS DWORD             ' count of controls pmxctrl points to
    cbmxctrl  AS DWORD             ' size in bytes of _one_ MIXERCONTROL
    pamxctrl  AS MIXERCONTROLA PTR ' pointer to first MIXERCONTROL array
END TYPE

TYPE MIXERLINECONTROLSW
    cbStruct  AS DWORD             ' size in bytes of MIXERLINECONTROLS
    dwLineID  AS DWORD             ' line id (from MIXERLINE.dwLineID)
    MIXERLINECONTROLS_union
    cControls AS DWORD             ' count of controls pmxctrl points to
    cbmxctrl  AS DWORD             ' size in bytes of _one_ MIXERCONTROL
    pamxctrl  AS MIXERCONTROLW PTR ' pointer to first MIXERCONTROL array
END TYPE

#IF %DEF(%UNICODE)
TYPE MIXERLINECONTROLS
    MIXERLINECONTROLSW
END TYPE
#ELSE
TYPE MIXERLINECONTROLS
    MIXERLINECONTROLSA
END TYPE
#ENDIF ' %UNICODE


'
'
'

DECLARE FUNCTION mixerGetLineControlsA LIB "WINMM.DLL" _
    ALIAS "mixerGetLineControlsA" (BYVAL hmxobj AS DWORD, _
    pmxlc AS MIXERLINECONTROLSA, BYVAL fdwControls AS DWORD) AS DWORD

DECLARE FUNCTION mixerGetLineControlsW LIB "WINMM.DLL" _
    ALIAS "mixerGetLineControlsW" (BYVAL hmxobj AS DWORD, _
    pmxlc AS MIXERLINECONTROLSW, BYVAL fdwControls AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION mixerGetLineControls LIB "WINMM.DLL" _
    ALIAS "mixerGetLineControlsW" (BYVAL hmxobj AS DWORD, _
    pmxlc AS MIXERLINECONTROLSW, BYVAL fdwControls AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION mixerGetLineControls LIB "WINMM.DLL" _
    ALIAS "mixerGetLineControlsA" (BYVAL hmxobj AS DWORD, _
    pmxlc AS MIXERLINECONTROLSA, BYVAL fdwControls AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

%MIXER_GETLINECONTROLSF_ALL         = &H00000000
%MIXER_GETLINECONTROLSF_ONEBYID     = &H00000001
%MIXER_GETLINECONTROLSF_ONEBYTYPE   = &H00000002

%MIXER_GETLINECONTROLSF_QUERYMASK   = &H0000000F


UNION MIXERCONTROLDETAILS_union
    hwndOwner AS DWORD              ' for MIXER_SETCONTROLDETAILSF_CUSTOM
    cMultipleItems AS DWORD        ' if _MULTIPLE, the number of items per channel
END UNION

TYPE MIXERCONTROLDETAILS
    cbStruct    AS DWORD           ' size in bytes of MIXERCONTROLDETAILS
    dwControlID AS DWORD           ' control id to get/set details on
    cChannels   AS DWORD           ' number of channels in paDetails array
    MIXERCONTROLDETAILS_union
    cbDetails   AS DWORD           ' size of _one_ details_XX struct
    paDetails   AS DWORD           ' pointer to array of details_XX structs
END TYPE


'
'  MIXER_GETCONTROLDETAILSF_LISTTEXT
'
'
TYPE MIXERCONTROLDETAILS_LISTTEXTA
    dwParam1 AS DWORD
    dwParam2 AS DWORD
    szName   AS ASCIIZ * %MIXER_LONG_NAME_CHARS
END TYPE

TYPE MIXERCONTROLDETAILS_LISTTEXTW
    dwParam1 AS DWORD
    dwParam2 AS DWORD
    szName   AS WSTRINGZ * %MIXER_LONG_NAME_CHARS
END TYPE

#IF %DEF(%UNICODE)
TYPE MIXERCONTROLDETAILS_LISTTEXT
    MIXERCONTROLDETAILS_LISTTEXTW
END TYPE
#ELSE
TYPE MIXERCONTROLDETAILS_LISTTEXT
    MIXERCONTROLDETAILS_LISTTEXTA
END TYPE
#ENDIF ' %UNICODE

'
'  MIXER_GETCONTROLDETAILSF_VALUE
'
'
TYPE MIXERCONTROLDETAILS_BOOLEAN
    fValue AS LONG
END TYPE

TYPE MIXERCONTROLDETAILS_SIGNED
    lValue AS LONG
END TYPE


TYPE MIXERCONTROLDETAILS_UNSIGNED
    dwValue AS DWORD
END TYPE

DECLARE FUNCTION mixerGetControlDetailsA LIB "WINMM.DLL" _
    ALIAS "mixerGetControlDetailsA" (BYVAL hmxobj AS DWORD, _
    pmxcd AS MIXERCONTROLDETAILS, BYVAL fdwDetails AS DWORD) AS DWORD

DECLARE FUNCTION mixerGetControlDetailsW LIB "WINMM.DLL" _
    ALIAS "mixerGetControlDetailsW" (BYVAL hmxobj AS DWORD, _
    pmxcd AS MIXERCONTROLDETAILS, BYVAL fdwDetails AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION mixerGetControlDetails LIB "WINMM.DLL" _
    ALIAS "mixerGetControlDetailsW" (BYVAL hmxobj AS DWORD, _
    pmxcd AS MIXERCONTROLDETAILS, BYVAL fdwDetails AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION mixerGetControlDetails LIB "WINMM.DLL" _
    ALIAS "mixerGetControlDetailsA" (BYVAL hmxobj AS DWORD, _
    pmxcd AS MIXERCONTROLDETAILS, BYVAL fdwDetails AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

%MIXER_GETCONTROLDETAILSF_VALUE      = &H00000000
%MIXER_GETCONTROLDETAILSF_LISTTEXT   = &H00000001

%MIXER_GETCONTROLDETAILSF_QUERYMASK  = &H0000000F

DECLARE FUNCTION mixerSetControlDetails LIB "WINMM.DLL" _
    ALIAS "mixerSetControlDetails" (BYVAL hmxobj AS DWORD, _
    pmxcd AS MIXERCONTROLDETAILS, BYVAL fdwDetails AS DWORD) AS DWORD

%MIXER_SETCONTROLDETAILSF_VALUE      = &H00000000
%MIXER_SETCONTROLDETAILSF_CUSTOM     = &H00000001

%MIXER_SETCONTROLDETAILSF_QUERYMASK  = &H0000000F


#ENDIF ' ifndef MMNOMIXER


#IF NOT %DEF(%MMNOTIMER)
'****************************************************************************
'
'                           Timer support
'
'****************************************************************************

' timer error return values
%TIMERR_NOERROR      = 0                   ' no error
%TIMERR_NOCANDO      = %TIMERR_BASE+1      ' request not completed
%TIMERR_STRUCT       = %TIMERR_BASE+33     ' time struct size

' timer data types
'typedef void (CALLBACK TIMECALLBACK)(DWORD uTimerID, DWORD uMsg, DWORD dwUser, DWORD dw1, DWORD dw2);

' flags for fuEvent parameter of timeSetEvent() function
%TIME_ONESHOT   = &H0000   ' program timer for single event
%TIME_PERIODIC  = &H0001   ' program for continuous periodic event

%TIME_CALLBACK_FUNCTION     = &H0000  ' callback is function
%TIME_CALLBACK_EVENT_SET    = &H0010  ' callback is event - use SetEvent
%TIME_CALLBACK_EVENT_PULSE  = &H0020  ' callback is event - use PulseEvent

#IF %WINVER >= &H0501
%TIME_KILL_SYNCHRONOUS  = &H0100  ' This flag prevents the event from occurring
                                        ' after the user calls timeKillEvent() to
                                        ' destroy it.
#ENDIF ' %WINVER >= &H0501



' timer device capabilities data structure
TYPE TIMECAPS
    wPeriodMin AS DWORD         ' minimum period supported
    wPeriodMax AS DWORD         ' maximum period supported
END TYPE

' timer function prototypes

DECLARE FUNCTION timeGetSystemTime LIB "WINMM.DLL" ALIAS "timeGetSystemTime" _
    (lpTime AS MMTIME, BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION timeGetTime LIB "WINMM.DLL" ALIAS "timeGetTime" () AS DWORD

DECLARE FUNCTION timeSetEvent LIB "WINMM.DLL" ALIAS "timeSetEvent" _
    (BYVAL uDelay AS DWORD, BYVAL uResolution AS DWORD, _
    BYVAL lpFunction AS DWORD, BYVAL dwUser AS DWORD, BYVAL uFlags AS DWORD) _
    AS DWORD

DECLARE FUNCTION timeKillEvent LIB "WINMM.DLL" ALIAS "timeKillEvent" _
    (BYVAL uId AS DWORD) AS DWORD

DECLARE FUNCTION timeGetDevCaps LIB "WINMM.DLL" ALIAS "timeGetDevCaps" _
    (lpTimeCaps AS TIMECAPS, BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION timeBeginPeriod LIB "WINMM.DLL" ALIAS "timeBeginPeriod" _
    (BYVAL uPeriod AS DWORD) AS DWORD

DECLARE FUNCTION timeEndPeriod LIB "WINMM.DLL" ALIAS "timeEndPeriod" _
    (BYVAL uPeriod AS DWORD) AS DWORD

#ENDIF  ' ifndef MMNOTIMER


#IF NOT %DEF(%MMNOJOY)
'****************************************************************************
'
'                           Joystick support
'
'****************************************************************************

' joystick error return values
%JOYERR_NOERROR      = 0                   ' no error
%JOYERR_PARMS        = %JOYERR_BASE+5      ' bad parameters
%JOYERR_NOCANDO      = %JOYERR_BASE+6      ' request not completed
%JOYERR_UNPLUGGED    = %JOYERR_BASE+7      ' joystick is unplugged

' constants used with JOYINFO and JOYINFOEX structures and MM_JOY* messages
%JOY_BUTTON1       = &H0001
%JOY_BUTTON2       = &H0002
%JOY_BUTTON3       = &H0004
%JOY_BUTTON4       = &H0008
%JOY_BUTTON1CHG    = &H0100
%JOY_BUTTON2CHG    = &H0200
%JOY_BUTTON3CHG    = &H0400
%JOY_BUTTON4CHG    = &H0800

' constants used with JOYINFOEX
%JOY_BUTTON5       = &H00000010
%JOY_BUTTON6       = &H00000020
%JOY_BUTTON7       = &H00000040
%JOY_BUTTON8       = &H00000080
%JOY_BUTTON9       = &H00000100
%JOY_BUTTON10      = &H00000200
%JOY_BUTTON11      = &H00000400
%JOY_BUTTON12      = &H00000800
%JOY_BUTTON13      = &H00001000
%JOY_BUTTON14      = &H00002000
%JOY_BUTTON15      = &H00004000
%JOY_BUTTON16      = &H00008000
%JOY_BUTTON17      = &H00010000
%JOY_BUTTON18      = &H00020000
%JOY_BUTTON19      = &H00040000
%JOY_BUTTON20      = &H00080000
%JOY_BUTTON21      = &H00100000
%JOY_BUTTON22      = &H00200000
%JOY_BUTTON23      = &H00400000
%JOY_BUTTON24      = &H00800000
%JOY_BUTTON25      = &H01000000
%JOY_BUTTON26      = &H02000000
%JOY_BUTTON27      = &H04000000
%JOY_BUTTON28      = &H08000000
%JOY_BUTTON29      = &H10000000
%JOY_BUTTON30      = &H20000000
%JOY_BUTTON31      = &H40000000
%JOY_BUTTON32      = &H80000000???

' constants used with JOYINFOEX structure
%JOY_POVCENTERED       = &HFFFF??  ' (WORD) -1
%JOY_POVFORWARD        = 0
%JOY_POVRIGHT          = 9000
%JOY_POVBACKWARD       = 18000
%JOY_POVLEFT           = 27000

%JOY_RETURNX           = &H00000001
%JOY_RETURNY           = &H00000002
%JOY_RETURNZ           = &H00000004
%JOY_RETURNR           = &H00000008
%JOY_RETURNU           = &H00000010     ' axis 5
%JOY_RETURNV           = &H00000020     ' axis 6
%JOY_RETURNPOV         = &H00000040
%JOY_RETURNBUTTONS     = &H00000080
%JOY_RETURNRAWDATA     = &H00000100
%JOY_RETURNPOVCTS      = &H00000200
%JOY_RETURNCENTERED    = &H00000400
%JOY_USEDEADZONE       = &H00000800
%JOY_RETURNALL         =  (%JOY_RETURNX OR %JOY_RETURNY OR %JOY_RETURNZ OR _
                           %JOY_RETURNR OR %JOY_RETURNU OR %JOY_RETURNV OR _
                           %JOY_RETURNPOV OR %JOY_RETURNBUTTONS)
%JOY_CAL_READALWAYS    = &H00010000
%JOY_CAL_READXYONLY    = &H00020000
%JOY_CAL_READ3         = &H00040000
%JOY_CAL_READ4         = &H00080000
%JOY_CAL_READXONLY     = &H00100000
%JOY_CAL_READYONLY     = &H00200000
%JOY_CAL_READ5         = &H00400000
%JOY_CAL_READ6         = &H00800000
%JOY_CAL_READZONLY     = &H01000000
%JOY_CAL_READRONLY     = &H02000000
%JOY_CAL_READUONLY     = &H04000000
%JOY_CAL_READVONLY     = &H08000000

' joystick ID constants
%JOYSTICKID1       = 0
%JOYSTICKID2       = 1

' joystick driver capabilites
%JOYCAPS_HASZ          = &H0001
%JOYCAPS_HASR          = &H0002
%JOYCAPS_HASU          = &H0004
%JOYCAPS_HASV          = &H0008
%JOYCAPS_HASPOV        = &H0010
%JOYCAPS_POV4DIR       = &H0020
%JOYCAPS_POVCTS        = &H0040



' joystick device capabilities data structure

TYPE JOYCAPSA
    wMid        AS WORD              ' manufacturer ID
    wPid        AS WORD              ' product ID
    szPname     AS ASCIIZ * %MAXPNAMELEN  ' product name (NULL terminated string)
    wXmin       AS DWORD             ' minimum x position value
    wXmax       AS DWORD             ' maximum x position value
    wYmin       AS DWORD             ' minimum y position value
    wYmax       AS DWORD             ' maximum y position value
    wZmin       AS DWORD             ' minimum z position value
    wZmax       AS DWORD             ' maximum z position value
    wNumButtons AS DWORD             ' number of buttons
    wPeriodMin  AS DWORD             ' minimum message period when captured
    wPeriodMax  AS DWORD             ' maximum message period when captured
#IF (%WINVER >= &H0400)
    wRmin       AS DWORD             ' minimum r position value
    wRmax       AS DWORD             ' maximum r position value
    wUmin       AS DWORD             ' minimum u (5th axis) position value
    wUmax       AS DWORD             ' maximum u (5th axis) position value
    wVmin       AS DWORD             ' minimum v (6th axis) position value
    wVmax       AS DWORD             ' maximum v (6th axis) position value
    wCaps       AS DWORD             ' joystick capabilites
    wMaxAxes    AS DWORD             ' maximum number of axes supported
    wNumAxes    AS DWORD             ' number of axes in use
    wMaxButtons AS DWORD             ' maximum number of buttons supported
    szRegKey    AS ASCIIZ * %MAXPNAMELEN             ' registry key
    szOEMVxD    AS ASCIIZ * %MAX_JOYSTICKOEMVXDNAME  ' OEM VxD in use
#ENDIF
END TYPE

TYPE JOYCAPSW
    wMid        AS WORD              ' manufacturer ID
    wPid        AS WORD              ' product ID
    szPname     AS WSTRINGZ * %MAXPNAMELEN  ' product name (NULL terminated string)
    wXmin       AS DWORD             ' minimum x position value
    wXmax       AS DWORD             ' maximum x position value
    wYmin       AS DWORD             ' minimum y position value
    wYmax       AS DWORD             ' maximum y position value
    wZmin       AS DWORD             ' minimum z position value
    wZmax       AS DWORD             ' maximum z position value
    wNumButtons AS DWORD             ' number of buttons
    wPeriodMin  AS DWORD             ' minimum message period when captured
    wPeriodMax  AS DWORD             ' maximum message period when captured
#IF (%WINVER >= &H0400)
    wRmin       AS DWORD             ' minimum r position value
    wRmax       AS DWORD             ' maximum r position value
    wUmin       AS DWORD             ' minimum u (5th axis) position value
    wUmax       AS DWORD             ' maximum u (5th axis) position value
    wVmin       AS DWORD             ' minimum v (6th axis) position value
    wVmax       AS DWORD             ' maximum v (6th axis) position value
    wCaps       AS DWORD             ' joystick capabilites
    wMaxAxes    AS DWORD             ' maximum number of axes supported
    wNumAxes    AS DWORD             ' number of axes in use
    wMaxButtons AS DWORD             ' maximum number of buttons supported
    szRegKey    AS WSTRINGZ * %MAXPNAMELEN             ' registry key
    szOEMVxD    AS WSTRINGZ * %MAX_JOYSTICKOEMVXDNAME  ' OEM VxD in use
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
TYPE JOYCAPS
    JOYCAPSW
END TYPE
#ELSE
TYPE JOYCAPS
    JOYCAPSA
END TYPE
#ENDIF ' %UNICODE

TYPE JOYCAPS2A
    wMid        AS WORD              ' manufacturer ID
    wPid        AS WORD              ' product ID
    szPname     AS ASCIIZ * %MAXPNAMELEN    ' product name (NULL terminated string)
    wXmin       AS DWORD             ' minimum x position value
    wXmax       AS DWORD             ' maximum x position value
    wYmin       AS DWORD             ' minimum y position value
    wYmax       AS DWORD             ' maximum y position value
    wZmin       AS DWORD             ' minimum z position value
    wZmax       AS DWORD             ' maximum z position value
    wNumButtons AS DWORD             ' number of buttons
    wPeriodMin  AS DWORD             ' minimum message period when captured
    wPeriodMax  AS DWORD             ' maximum message period when captured
    wRmin       AS DWORD             ' minimum r position value
    wRmax       AS DWORD             ' maximum r position value
    wUmin       AS DWORD             ' minimum u (5th axis) position value
    wUmax       AS DWORD             ' maximum u (5th axis) position value
    wVmin       AS DWORD             ' minimum v (6th axis) position value
    wVmax       AS DWORD             ' maximum v (6th axis) position value
    wCaps       AS DWORD             ' joystick capabilites
    wMaxAxes    AS DWORD             ' maximum number of axes supported
    wNumAxes    AS DWORD             ' number of axes in use
    wMaxButtons AS DWORD             ' maximum number of buttons supported
    szRegKey    AS ASCIIZ * %MAXPNAMELEN    ' registry key
    szOEMVxD    AS ASCIIZ * %MAX_JOYSTICKOEMVXDNAME   ' OEM VxD in use
    ManufacturerGuid AS GUID         ' for extensible MID mapping
    ProductGuid AS GUID              ' for extensible PID mapping
    NameGuid    AS GUID              ' for name lookup in registry
END TYPE

TYPE JOYCAPS2W
    wMid        AS WORD              ' manufacturer ID
    wPid        AS WORD              ' product ID
    szPname     AS WSTRINGZ * %MAXPNAMELEN    ' product name (NULL terminated string)
    wXmin       AS DWORD             ' minimum x position value
    wXmax       AS DWORD             ' maximum x position value
    wYmin       AS DWORD             ' minimum y position value
    wYmax       AS DWORD             ' maximum y position value
    wZmin       AS DWORD             ' minimum z position value
    wZmax       AS DWORD             ' maximum z position value
    wNumButtons AS DWORD             ' number of buttons
    wPeriodMin  AS DWORD             ' minimum message period when captured
    wPeriodMax  AS DWORD             ' maximum message period when captured
    wRmin       AS DWORD             ' minimum r position value
    wRmax       AS DWORD             ' maximum r position value
    wUmin       AS DWORD             ' minimum u (5th axis) position value
    wUmax       AS DWORD             ' maximum u (5th axis) position value
    wVmin       AS DWORD             ' minimum v (6th axis) position value
    wVmax       AS DWORD             ' maximum v (6th axis) position value
    wCaps       AS DWORD             ' joystick capabilites
    wMaxAxes    AS DWORD             ' maximum number of axes supported
    wNumAxes    AS DWORD             ' number of axes in use
    wMaxButtons AS DWORD             ' maximum number of buttons supported
    szRegKey    AS WSTRINGZ * %MAXPNAMELEN    ' registry key
    szOEMVxD    AS WSTRINGZ * %MAX_JOYSTICKOEMVXDNAME   ' OEM VxD in use
    ManufacturerGuid AS GUID         ' for extensible MID mapping
    ProductGuid AS GUID              ' for extensible PID mapping
    NameGuid    AS GUID              ' for name lookup in registry
END TYPE

#IF %DEF(%UNICODE)
TYPE JOYCAPS2
    JOYCAPS2W
END TYPE
#ELSE
TYPE JOYCAPS2
    JOYCAPS2A
END TYPE
#ENDIF ' %UNICODE


' joystick information data structure
TYPE JOYINFO
    wXpos    AS DWORD               ' x position
    wYpos    AS DWORD               ' y position
    wZpos    AS DWORD               ' z position
    wButtons AS DWORD               ' button states
END TYPE

#IF (%WINVER >= &H0400)
TYPE JOYINFOEX
    dwSize         AS DWORD         ' size of structure
    dwFlags        AS DWORD         ' flags to indicate what to return
    dwXpos         AS DWORD         ' x position
    dwYpos         AS DWORD         ' y position
    dwZpos         AS DWORD         ' z position
    dwRpos         AS DWORD         ' rudder/4th axis position
    dwUpos         AS DWORD         ' 5th axis position
    dwVpos         AS DWORD         ' 6th axis position
    dwButtons      AS DWORD         ' button states
    dwButtonNumber AS DWORD         ' current button number pressed
    dwPOV          AS DWORD         ' point of view state
    dwReserved1    AS DWORD         ' reserved for communication between winmm & driver
    dwReserved2    AS DWORD         ' reserved for future expansion
END TYPE
#ENDIF ' WINVER >= &H0400

' joystick function prototypes

DECLARE FUNCTION joyGetNumDevs LIB "WINMM.DLL" ALIAS "joyGetNumDevs" () _
    AS DWORD

DECLARE FUNCTION joyGetDevCapsA LIB "WINMM.DLL" ALIAS "joyGetDevCapsA" _
    (BYVAL ID AS DWORD, lpCaps AS JOYCAPSA, BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION joyGetDevCapsW LIB "WINMM.DLL" ALIAS "joyGetDevCapsW" _
    (BYVAL ID AS DWORD, lpCaps AS JOYCAPSW, BYVAL uSize AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION joyGetDevCaps LIB "WINMM.DLL" ALIAS "joyGetDevCapsW" _
    (BYVAL ID AS DWORD, lpCaps AS JOYCAPSW, BYVAL uSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION joyGetDevCaps LIB "WINMM.DLL" ALIAS "joyGetDevCapsA" _
    (BYVAL ID AS DWORD, lpCaps AS JOYCAPSA, BYVAL uSize AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION joyGetPos LIB "WINMM.DLL" ALIAS "joyGetPos" _
    (BYVAL uJoyId AS DWORD, pji AS JOYINFO) AS DWORD

#IF (%WINVER >= &H0400)

DECLARE FUNCTION joyGetPosEx LIB "WINMM.DLL" ALIAS "joyGetPosEx" _
    (BYVAL uJoyId AS DWORD, pji AS JOYINFOEX) AS DWORD

#ENDIF ' WINVER >= &H0400

DECLARE FUNCTION joyGetThreshold LIB "WINMM.DLL" ALIAS "joyGetThreshold" _
    (BYVAL uJoyID AS DWORD, lpuThreshold AS DWORD) AS DWORD

DECLARE FUNCTION joyReleaseCapture LIB "WINMM.DLL" ALIAS "joyReleaseCapture" _
    (BYVAL uJoyID AS DWORD) AS DWORD

DECLARE FUNCTION joySetCapture LIB "WINMM.DLL" ALIAS "joySetCapture" _
    (BYVAL hWnd AS DWORD, BYVAL uId AS DWORD, BYVAL uPeriod AS DWORD, _
    BYVAL bChanged AS LONG) AS DWORD

DECLARE FUNCTION joySetThreshold LIB "WINMM.DLL" ALIAS "joySetThreshold" _
    (BYVAL uJoyID AS LONG, BYVAL uThreshold AS DWORD) AS DWORD


#ENDIF  ' ifndef MMNOJOY


#IF NOT %DEF(%MMNOMMIO)
'****************************************************************************
'
'                       Multimedia File I/O support
'
'****************************************************************************

' MMIO error return values
%MMIOERR_BASE               = 256
%MMIOERR_FILENOTFOUND       = %MMIOERR_BASE + 1   ' file not found
%MMIOERR_OUTOFMEMORY        = %MMIOERR_BASE + 2   ' out of memory
%MMIOERR_CANNOTOPEN         = %MMIOERR_BASE + 3   ' cannot open
%MMIOERR_CANNOTCLOSE        = %MMIOERR_BASE + 4   ' cannot close
%MMIOERR_CANNOTREAD         = %MMIOERR_BASE + 5   ' cannot read
%MMIOERR_CANNOTWRITE        = %MMIOERR_BASE + 6   ' cannot write
%MMIOERR_CANNOTSEEK         = %MMIOERR_BASE + 7   ' cannot seek
%MMIOERR_CANNOTEXPAND       = %MMIOERR_BASE + 8   ' cannot expand file
%MMIOERR_CHUNKNOTFOUND      = %MMIOERR_BASE + 9   ' chunk not found
%MMIOERR_UNBUFFERED         = %MMIOERR_BASE + 10  '
%MMIOERR_PATHNOTFOUND       = %MMIOERR_BASE + 11  ' path incorrect
%MMIOERR_ACCESSDENIED       = %MMIOERR_BASE + 12  ' file was protected
%MMIOERR_SHARINGVIOLATION   = %MMIOERR_BASE + 13  ' file in use
%MMIOERR_NETWORKERROR       = %MMIOERR_BASE + 14  ' network not responding
%MMIOERR_TOOMANYOPENFILES   = %MMIOERR_BASE + 15  ' no more file handles
%MMIOERR_INVALIDFILE        = %MMIOERR_BASE + 16  ' default error file error

' MMIO constants
$CFSEPCHAR     = "+"             ' compound file name separator char.

' MMIO data types

'typedef LRESULT (CALLBACK MMIOPROC)(LPSTR lpmmioinfo, DWORD uMsg,
'            LPARAM lParam1, LPARAM lParam2);


' general MMIO information data structure
TYPE MMIOINFO
    ' general fields
    dwFlags     AS DWORD        ' general status flags
    fccIOProc   AS DWORD        ' pointer to I/O procedure
    pIOProc     AS DWORD        ' pointer to I/O procedure
    wErrorRet   AS DWORD        ' place for error to be returned
    htask       AS DWORD        ' alternate local task

    ' fields maintained by MMIO functions during buffered I/O
    cchBuffer   AS LONG         ' size of I/O buffer (or 0L)
    pchBuffer   AS ASCIIZ PTR   ' start of I/O buffer (or NULL)
    pchNext     AS ASCIIZ PTR   ' pointer to next byte to read/write
    pchEndRead  AS ASCIIZ PTR   ' pointer to last valid byte to read
    pchEndWrite AS ASCIIZ PTR   ' pointer to last byte to write
    lBufOffset  AS LONG         ' disk offset of start of buffer

    ' fields maintained by I/O procedure
    lDiskOffset AS LONG         ' disk offset of next read or write
    adwInfo(2)  AS DWORD        ' data specific to type of MMIOPROC

    ' other fields maintained by MMIO
    dwReserved1 AS DWORD        ' reserved for MMIO use
    dwReserved2 AS DWORD        ' reserved for MMIO use
    hmmio       AS DWORD        ' handle to open file
END TYPE

' RIFF chunk information data structure
TYPE MMCKINFO
    ckid         AS DWORD       ' chunk ID
    cksize       AS DWORD       ' chunk size
    fccType      AS DWORD       ' form type or list type
    dwDataOffset AS DWORD       ' offset of data portion of chunk
    dwFlags      AS DWORD       ' flags used by MMIO functions
END TYPE

' bit field masks
%MMIO_RWMODE     = &H00000003      ' open file for reading/writing/both
%MMIO_SHAREMODE  = &H00000070      ' file sharing mode number

' constants for dwFlags field of = %MMIOINFO
%MMIO_CREATE     = &H00001000      ' create new file (or truncate file)
%MMIO_PARSE      = &H00000100      ' parse new file returning path
%MMIO_DELETE     = &H00000200      ' create new file (or truncate file)
%MMIO_EXIST      = &H00004000      ' checks for existence of file
%MMIO_ALLOCBUF   = &H00010000      ' mmioOpen() should allocate a buffer
%MMIO_GETTEMP    = &H00020000      ' mmioOpen() should retrieve temp name

%MMIO_DIRTY      = &H10000000      ' I/O buffer is dirty


' read/write mode numbers (bit field = %MMIO_RWMODE)
%MMIO_READ       = &H00000000      ' open file for reading only
%MMIO_WRITE      = &H00000001      ' open file for writing only
%MMIO_READWRITE  = &H00000002      ' open file for reading and writing

' share mode numbers (bit field = %MMIO_SHAREMODE)
%MMIO_COMPAT     = &H00000000      ' compatibility mode
%MMIO_EXCLUSIVE  = &H00000010      ' exclusive-access mode
%MMIO_DENYWRITE  = &H00000020      ' deny writing to other processes
%MMIO_DENYREAD   = &H00000030      ' deny reading to other processes
%MMIO_DENYNONE   = &H00000040      ' deny nothing to other processes

' various = %MMIO flags
%MMIO_FHOPEN             = &H0010  ' mmioClose: keep file handle open
%MMIO_EMPTYBUF           = &H0010  ' mmioFlush: empty the I/O buffer
%MMIO_TOUPPER            = &H0010  ' mmioStringToFOURCC: to u-case
%MMIO_INSTALLPROC    = &H00010000  ' mmioInstallIOProc: install = %MMIOProc
%MMIO_GLOBALPROC     = &H10000000  ' mmioInstallIOProc: install globally
%MMIO_REMOVEPROC     = &H00020000  ' mmioInstallIOProc: remove = %MMIOProc
%MMIO_UNICODEPROC    = &H01000000  ' mmioInstallIOProc: Unicode = %MMIOProc
%MMIO_FINDPROC       = &H00040000  ' mmioInstallIOProc: find an = %MMIOProc
%MMIO_FINDCHUNK          = &H0010  ' mmioDescend: find a chunk by ID
%MMIO_FINDRIFF           = &H0020  ' mmioDescend: find a LIST chunk
%MMIO_FINDLIST           = &H0040  ' mmioDescend: find a RIFF chunk
%MMIO_CREATERIFF         = &H0020  ' mmioCreateChunk: make a LIST chunk
%MMIO_CREATELIST         = &H0040  ' mmioCreateChunk: make a RIFF chunk


' message numbers for = %MMIOPROC I/O procedure functions
%MMIOM_READ      = %MMIO_READ       ' read
%MMIOM_WRITE    = %MMIO_WRITE       ' write
%MMIOM_SEEK            = 2       ' seek to a new position in file
%MMIOM_OPEN            = 3       ' open file
%MMIOM_CLOSE           = 4       ' close file
%MMIOM_WRITEFLUSH      = 5       ' write and flush

#IF (%WINVER >= &H030a)
%MMIOM_RENAME          = 6       ' rename specified file
#ENDIF ' ifdef WINVER >= &H030a

%MMIOM_USER         = &H8000??     ' beginning of user-defined messages

' standard four character codes
MACRO FOURCC_RIFF=mmioFOURCC("R", "I", "F", "F")
MACRO FOURCC_LIST=mmioFOURCC("L", "I", "S", "T")

' four character codes used to identify standard built-in I/O procedures
MACRO FOURCC_DOS=mmioFOURCC("D", "O", "S", " ")
MACRO FOURCC_MEM=mmioFOURCC("M", "E", "M", " ")

' flags for mmioSeek()
#IF NOT %DEF(%SEEK_SET)
%SEEK_SET      = 0               ' seek to an absolute position
%SEEK_CUR      = 1               ' seek relative to current position
%SEEK_END      = 2               ' seek relative to end of file
#ENDIF  ' ifndef SEEK_SET

' other constants
%MMIO_DEFAULTBUFFER    = 8192    ' default buffer size

' MMIO macros
MACRO mmioFOURCC(ch0,ch1,ch2,ch3)=MAKEFOURCC(ch0,ch1,ch2,ch3)

' MMIO function prototypes

DECLARE FUNCTION mmioStringToFOURCCA LIB "WINMM.DLL" _
    ALIAS "mmioStringToFOURCCA" (sz AS ASCIIZ, BYVAL uFlags AS DWORD) AS DWORD

DECLARE FUNCTION mmioStringToFOURCCW LIB "WINMM.DLL" _
    ALIAS "mmioStringToFOURCCW" (sz AS WSTRINGZ, BYVAL uFlags AS DWORD) _
    AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION mmioStringToFOURCC LIB "WINMM.DLL" _
    ALIAS "mmioStringToFOURCCW" (sz AS WSTRINGZ, BYVAL uFlags AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION mmioStringToFOURCC LIB "WINMM.DLL" _
    ALIAS "mmioStringToFOURCCA" (sz AS ASCIIZ, BYVAL uFlags AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION mmioInstallIOProcA LIB "WINMM.DLL" _
    ALIAS "mmioInstallIOProcA" (BYVAL fccIOProc AS DWORD, _
    BYVAL pIOProc AS DWORD, BYVAL dwFlags AS DWORD) AS DWORD

DECLARE FUNCTION mmioInstallIOProcW LIB "WINMM.DLL" _
    ALIAS "mmioInstallIOProcW" (BYVAL fccIOProc AS DWORD, _
    BYVAL pIOProc AS DWORD, BYVAL dwFlags AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION mmioInstallIOProc LIB "WINMM.DLL" _
    ALIAS "mmioInstallIOProcW" (BYVAL fccIOProc AS DWORD, _
    BYVAL pIOProc AS DWORD, BYVAL dwFlags AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION mmioInstallIOProc LIB "WINMM.DLL" _
    ALIAS "mmioInstallIOProcA" (BYVAL fccIOProc AS DWORD, _
    BYVAL pIOProc AS DWORD, BYVAL dwFlags AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION mmioOpenA LIB "WINMM.DLL" ALIAS "mmioOpenA" _
    (szFileName AS ASCIIZ, lpmmioinfo AS MMIOINFO, _
    BYVAL dwOpenFlags AS DWORD) AS DWORD

DECLARE FUNCTION mmioOpenW LIB "WINMM.DLL" ALIAS "mmioOpenW" _
    (szFileName AS WSTRINGZ, lpmmioinfo AS MMIOINFO, _
    BYVAL dwOpenFlags AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION mmioOpen LIB "WINMM.DLL" ALIAS "mmioOpenW" _
    (szFileName AS WSTRINGZ, lpmmioinfo AS MMIOINFO, _
    BYVAL dwOpenFlags AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION mmioOpen LIB "WINMM.DLL" ALIAS "mmioOpenA" _
    (szFileName AS ASCIIZ, lpmmioinfo AS MMIOINFO, _
    BYVAL dwOpenFlags AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION mmioRenameA LIB "WINMM.DLL" ALIAS "mmioRenameA" _
    (szFileName AS ASCIIZ, SzNewFileName AS ASCIIZ, lpmmioinfo AS MMIOINFO, _
    BYVAL dwRenameFlags AS DWORD) AS DWORD

DECLARE FUNCTION mmioRenameW LIB "WINMM.DLL" ALIAS "mmioRenameW" _
    (szFileName AS WSTRINGZ, SzNewFileName AS WSTRINGZ, _
    lpmmioinfo AS MMIOINFO, BYVAL dwRenameFlags AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION mmioRename LIB "WINMM.DLL" ALIAS "mmioRenameW" _
    (szFileName AS WSTRINGZ, SzNewFileName AS WSTRINGZ, _
    lpmmioinfo AS MMIOINFO, BYVAL dwRenameFlags AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION mmioRename LIB "WINMM.DLL" ALIAS "mmioRenameA" _
    (szFileName AS ASCIIZ, SzNewFileName AS ASCIIZ, lpmmioinfo AS MMIOINFO, _
    BYVAL dwRenameFlags AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION mmioClose LIB "WINMM.DLL" ALIAS "mmioClose" _
    (BYVAL hmmio AS DWORD, BYVAL uFlags AS DWORD) AS DWORD

DECLARE FUNCTION mmioRead LIB "WINMM.DLL" ALIAS "mmioRead" _
    (BYVAL hmmio AS DWORD, pch AS ASCIIZ, BYVAL cch AS LONG) AS LONG

DECLARE FUNCTION mmioWrite LIB "WINMM.DLL" ALIAS "mmioWrite" _
    (BYVAL hmmio AS DWORD, pch AS ASCIIZ, BYVAL cch AS LONG) AS LONG

DECLARE FUNCTION mmioSeek LIB "WINMM.DLL" ALIAS "mmioSeek" _
    (BYVAL hmmio AS DWORD, BYVAL lOffset AS LONG, BYVAL iOrigin AS LONG) _
    AS LONG

DECLARE FUNCTION mmioGetInfo LIB "WINMM.DLL" ALIAS "mmioGetInfo" _
    (BYVAL hmmio AS DWORD, lpmmioinfo AS MMIOINFO, BYVAL uFlags AS DWORD) _
    AS DWORD

DECLARE FUNCTION mmioSetInfo LIB "WINMM.DLL" ALIAS "mmioSetInfo" _
    (BYVAL hmmio AS DWORD, lpmmioinfo AS MMIOINFO, BYVAL uFlags AS DWORD) _
    AS DWORD

DECLARE FUNCTION mmioSetBuffer LIB "WINMM.DLL" ALIAS "mmioSetBuffer" _
    (BYVAL hmmio AS DWORD, pchBuffer AS ASCIIZ, BYVAL cchBuffer AS LONG, _
    BYVAL uFlags AS DWORD) AS DWORD

DECLARE FUNCTION mmioFlush LIB "WINMM.DLL" ALIAS "mmioFlush" _
    (BYVAL hmmio AS DWORD, BYVAL uFlags AS DWORD) AS DWORD

DECLARE FUNCTION mmioAdvance LIB "WINMM.DLL" ALIAS "mmioAdvance" _
    (BYVAL hmmio AS DWORD, lpmmioinfo AS MMIOINFO, BYVAL uFlags AS DWORD) _
    AS DWORD

DECLARE FUNCTION mmioSendMessage LIB "WINMM.DLL" ALIAS "mmioSendMessage" _
    (BYVAL hmmio AS DWORD, BYVAL uMsg AS DWORD, BYVAL lParam1 AS LONG, _
    BYVAL lParam2 AS LONG) AS LONG

DECLARE FUNCTION mmioDescend LIB "WINMM.DLL" ALIAS "mmioDescend" _
    (BYVAL hmmio AS DWORD, lpck AS MMCKINFO, lpckParent AS MMCKINFO, _
    BYVAL uFlags AS DWORD) AS DWORD

DECLARE FUNCTION mmioAscend LIB "WINMM.DLL" ALIAS "mmioAscend" _
    (BYVAL hmmio AS DWORD, lpck AS MMCKINFO, BYVAL uFlags AS DWORD) AS DWORD

DECLARE FUNCTION mmioCreateChunk LIB "WINMM.DLL" ALIAS "mmioCreateChunk" _
    (BYVAL hmmio AS DWORD, lpck AS MMCKINFO, BYVAL uFlags AS DWORD) AS DWORD

#ENDIF  ' ifndef MMNOMMIO

#IF NOT %DEF(%MMNOMCI)
'****************************************************************************
'
'                           MCI support
'
'****************************************************************************

'typedef DWORD (CALLBACK *YIELDPROC)(DWORD mciId, DWORD dwYieldData);

' MCI function prototypes

DECLARE FUNCTION mciSendCommandA LIB "WINMM.DLL" ALIAS "mciSendCommandA" _
    (BYVAL wDeviceId AS DWORD, BYVAL uMessage AS DWORD, _
    BYVAL dwParam1 AS DWORD, BYVAL dwParam2 AS DWORD) AS DWORD

DECLARE FUNCTION mciSendCommandW LIB "WINMM.DLL" ALIAS "mciSendCommandW" _
    (BYVAL wDeviceId AS DWORD, BYVAL uMessage AS DWORD, _
    BYVAL dwParam1 AS DWORD, BYVAL dwParam2 AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION mciSendCommand LIB "WINMM.DLL" ALIAS "mciSendCommandW" _
    (BYVAL wDeviceId AS DWORD, BYVAL uMessage AS DWORD, _
    BYVAL dwParam1 AS DWORD, BYVAL dwParam2 AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION mciSendCommand LIB "WINMM.DLL" ALIAS "mciSendCommandA" _
    (BYVAL wDeviceId AS DWORD, BYVAL uMessage AS DWORD, _
    BYVAL dwParam1 AS DWORD, BYVAL dwParam2 AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION mciSendStringA LIB "WINMM.DLL" ALIAS "mciSendStringA" _
    (lpstrCommand AS ASCIIZ, lpstrReturnString AS ASCIIZ, _
    BYVAL uReturnLength AS DWORD, BYVAL hwndCallback AS DWORD) AS DWORD

DECLARE FUNCTION mciSendStringW LIB "WINMM.DLL" ALIAS "mciSendStringW" _
    (lpstrCommand AS WSTRINGZ, lpstrReturnString AS WSTRINGZ, _
    BYVAL uReturnLength AS DWORD, BYVAL hwndCallback AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION mciSendString LIB "WINMM.DLL" ALIAS "mciSendStringW" _
    (lpstrCommand AS WSTRINGZ, lpstrReturnString AS WSTRINGZ, _
    BYVAL uReturnLength AS DWORD, BYVAL hwndCallback AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION mciSendString LIB "WINMM.DLL" ALIAS "mciSendStringA" _
    (lpstrCommand AS ASCIIZ, lpstrReturnString AS ASCIIZ, _
    BYVAL uReturnLength AS DWORD, BYVAL hwndCallback AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION mciGetDeviceIDA LIB "WINMM.DLL" ALIAS "mciGetDeviceIDA" _
    (lpstrName AS ASCIIZ) AS DWORD

DECLARE FUNCTION mciGetDeviceIDW LIB "WINMM.DLL" ALIAS "mciGetDeviceIDW" _
    (lpstrName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION mciGetDeviceID LIB "WINMM.DLL" ALIAS "mciGetDeviceIDW" _
    (lpstrName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION mciGetDeviceID LIB "WINMM.DLL" ALIAS "mciGetDeviceIDA" _
    (lpstrName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION mciGetDeviceIDFromElementIDA LIB "WINMM.DLL" _
    ALIAS "mciGetDeviceIDFromElementIDA" (BYVAL dwElementId AS DWORD, _
    lpstrType AS ASCIIZ) AS DWORD

DECLARE FUNCTION mciGetDeviceIDFromElementIDW LIB "WINMM.DLL" _
    ALIAS "mciGetDeviceIDFromElementIDW" (BYVAL dwElementId AS DWORD, _
    lpstrType AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION mciGetDeviceIDFromElementID LIB "WINMM.DLL" _
    ALIAS "mciGetDeviceIDFromElementIDW" (BYVAL dwElementId AS DWORD, _
    lpstrType AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION mciGetDeviceIDFromElementID LIB "WINMM.DLL" _
    ALIAS "mciGetDeviceIDFromElementIDA" (BYVAL dwElementId AS DWORD, _
    lpstrType AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION mciGetErrorStringA LIB "WINMM.DLL" _
    ALIAS "mciGetErrorStringA" (BYVAL dwError AS DWORD, _
    lpstrBuffer AS ASCIIZ, BYVAL uLength AS DWORD) AS LONG

DECLARE FUNCTION mciGetErrorStringW LIB "WINMM.DLL" _
    ALIAS "mciGetErrorStringW" (BYVAL dwError AS DWORD, _
    lpstrBuffer AS WSTRINGZ, BYVAL uLength AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION mciGetErrorString LIB "WINMM.DLL" _
    ALIAS "mciGetErrorStringW" (BYVAL dwError AS DWORD, _
    lpstrBuffer AS WSTRINGZ, BYVAL uLength AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION mciGetErrorString LIB "WINMM.DLL" _
    ALIAS "mciGetErrorStringA" (BYVAL dwError AS DWORD, _
    lpstrBuffer AS ASCIIZ, BYVAL uLength AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION mciSetYieldProc LIB "WINMM.DLL" ALIAS "mciSetYieldProc" _
    (BYVAL mciId AS DWORD, BYVAL fpYieldProc AS DWORD, _
    BYVAL dwYieldData AS DWORD) AS LONG

#IF (%WINVER >= &H030a)

DECLARE FUNCTION mciGetCreatorTask LIB "WINMM.DLL" ALIAS "mciGetCreatorTask" _
    (BYVAL wDeviceId AS DWORD) AS DWORD

DECLARE FUNCTION mciGetYieldProc LIB "WINMM.DLL" ALIAS "mciGetYieldProc" _
    (BYVAL mciId AS DWORD, pdwYieldData AS DWORD) AS DWORD

#ENDIF ' ifdef WINVER >= &H030a

#IF (%WINVER < &H030a)

DECLARE FUNCTION mciExecute LIB "WINMM.DLL" ALIAS "mciExecute" _
    (lpstrCommand AS ASCIIZ) AS LONG

#ENDIF ' ifdef WINVER < &H030a

' MCI error return values
%MCIERR_INVALID_DEVICE_ID        = %MCIERR_BASE + 1
%MCIERR_UNRECOGNIZED_KEYWORD     = %MCIERR_BASE + 3
%MCIERR_UNRECOGNIZED_COMMAND     = %MCIERR_BASE + 5
%MCIERR_HARDWARE                 = %MCIERR_BASE + 6
%MCIERR_INVALID_DEVICE_NAME      = %MCIERR_BASE + 7
%MCIERR_OUT_OF_MEMORY            = %MCIERR_BASE + 8
%MCIERR_DEVICE_OPEN              = %MCIERR_BASE + 9
%MCIERR_CANNOT_LOAD_DRIVER       = %MCIERR_BASE + 10
%MCIERR_MISSING_COMMAND_STRING   = %MCIERR_BASE + 11
%MCIERR_PARAM_OVERFLOW           = %MCIERR_BASE + 12
%MCIERR_MISSING_STRING_ARGUMENT  = %MCIERR_BASE + 13
%MCIERR_BAD_INTEGER              = %MCIERR_BASE + 14
%MCIERR_PARSER_INTERNAL          = %MCIERR_BASE + 15
%MCIERR_DRIVER_INTERNAL          = %MCIERR_BASE + 16
%MCIERR_MISSING_PARAMETER        = %MCIERR_BASE + 17
%MCIERR_UNSUPPORTED_FUNCTION     = %MCIERR_BASE + 18
%MCIERR_FILE_NOT_FOUND           = %MCIERR_BASE + 19
%MCIERR_DEVICE_NOT_READY         = %MCIERR_BASE + 20
%MCIERR_INTERNAL                 = %MCIERR_BASE + 21
%MCIERR_DRIVER                   = %MCIERR_BASE + 22
%MCIERR_CANNOT_USE_ALL           = %MCIERR_BASE + 23
%MCIERR_MULTIPLE                 = %MCIERR_BASE + 24
%MCIERR_EXTENSION_NOT_FOUND      = %MCIERR_BASE + 25
%MCIERR_OUTOFRANGE               = %MCIERR_BASE + 26
%MCIERR_FLAGS_NOT_COMPATIBLE     = %MCIERR_BASE + 28
%MCIERR_FILE_NOT_SAVED           = %MCIERR_BASE + 30
%MCIERR_DEVICE_TYPE_REQUIRED     = %MCIERR_BASE + 31
%MCIERR_DEVICE_LOCKED            = %MCIERR_BASE + 32
%MCIERR_DUPLICATE_ALIAS          = %MCIERR_BASE + 33
%MCIERR_BAD_CONSTANT             = %MCIERR_BASE + 34
%MCIERR_MUST_USE_SHAREABLE       = %MCIERR_BASE + 35
%MCIERR_MISSING_DEVICE_NAME      = %MCIERR_BASE + 36
%MCIERR_BAD_TIME_FORMAT          = %MCIERR_BASE + 37
%MCIERR_NO_CLOSING_QUOTE         = %MCIERR_BASE + 38
%MCIERR_DUPLICATE_FLAGS          = %MCIERR_BASE + 39
%MCIERR_INVALID_FILE             = %MCIERR_BASE + 40
%MCIERR_NULL_PARAMETER_BLOCK     = %MCIERR_BASE + 41
%MCIERR_UNNAMED_RESOURCE         = %MCIERR_BASE + 42
%MCIERR_NEW_REQUIRES_ALIAS       = %MCIERR_BASE + 43
%MCIERR_NOTIFY_ON_AUTO_OPEN      = %MCIERR_BASE + 44
%MCIERR_NO_ELEMENT_ALLOWED       = %MCIERR_BASE + 45
%MCIERR_NONAPPLICABLE_FUNCTION   = %MCIERR_BASE + 46
%MCIERR_ILLEGAL_FOR_AUTO_OPEN    = %MCIERR_BASE + 47
%MCIERR_FILENAME_REQUIRED        = %MCIERR_BASE + 48
%MCIERR_EXTRA_CHARACTERS         = %MCIERR_BASE + 49
%MCIERR_DEVICE_NOT_INSTALLED     = %MCIERR_BASE + 50
%MCIERR_GET_CD                   = %MCIERR_BASE + 51
%MCIERR_SET_CD                   = %MCIERR_BASE + 52
%MCIERR_SET_DRIVE                = %MCIERR_BASE + 53
%MCIERR_DEVICE_LENGTH            = %MCIERR_BASE + 54
%MCIERR_DEVICE_ORD_LENGTH        = %MCIERR_BASE + 55
%MCIERR_NO_INTEGER               = %MCIERR_BASE + 56

%MCIERR_WAVE_OUTPUTSINUSE        = %MCIERR_BASE + 64
%MCIERR_WAVE_SETOUTPUTINUSE      = %MCIERR_BASE + 65
%MCIERR_WAVE_INPUTSINUSE         = %MCIERR_BASE + 66
%MCIERR_WAVE_SETINPUTINUSE       = %MCIERR_BASE + 67
%MCIERR_WAVE_OUTPUTUNSPECIFIED   = %MCIERR_BASE + 68
%MCIERR_WAVE_INPUTUNSPECIFIED    = %MCIERR_BASE + 69
%MCIERR_WAVE_OUTPUTSUNSUITABLE   = %MCIERR_BASE + 70
%MCIERR_WAVE_SETOUTPUTUNSUITABLE = %MCIERR_BASE + 71
%MCIERR_WAVE_INPUTSUNSUITABLE    = %MCIERR_BASE + 72
%MCIERR_WAVE_SETINPUTUNSUITABLE  = %MCIERR_BASE + 73

%MCIERR_SEQ_DIV_INCOMPATIBLE     = %MCIERR_BASE + 80
%MCIERR_SEQ_PORT_INUSE           = %MCIERR_BASE + 81
%MCIERR_SEQ_PORT_NONEXISTENT     = %MCIERR_BASE + 82
%MCIERR_SEQ_PORT_MAPNODEVICE     = %MCIERR_BASE + 83
%MCIERR_SEQ_PORT_MISCERROR       = %MCIERR_BASE + 84
%MCIERR_SEQ_TIMER                = %MCIERR_BASE + 85
%MCIERR_SEQ_PORTUNSPECIFIED      = %MCIERR_BASE + 86
%MCIERR_SEQ_NOMIDIPRESENT        = %MCIERR_BASE + 87

%MCIERR_NO_WINDOW                = %MCIERR_BASE + 90
%MCIERR_CREATEWINDOW             = %MCIERR_BASE + 91
%MCIERR_FILE_READ                = %MCIERR_BASE + 92
%MCIERR_FILE_WRITE               = %MCIERR_BASE + 93

%MCIERR_NO_IDENTITY              = %MCIERR_BASE + 94

' all custom device driver errors must be >= than this value
%MCIERR_CUSTOM_DRIVER_BASE       = %MCIERR_BASE + 256

%MCI_FIRST                       = %DRV_MCI_FIRST   ' &H0800
' MCI command message identifiers
%MCI_OPEN                   = &H0803
%MCI_CLOSE                  = &H0804
%MCI_ESCAPE                 = &H0805
%MCI_PLAY                   = &H0806
%MCI_SEEK                   = &H0807
%MCI_STOP                   = &H0808
%MCI_PAUSE                  = &H0809
%MCI_INFO                   = &H080A
%MCI_GETDEVCAPS             = &H080B
%MCI_SPIN                   = &H080C
%MCI_SET                    = &H080D
%MCI_STEP                   = &H080E
%MCI_RECORD                 = &H080F
%MCI_SYSINFO                = &H0810
%MCI_BREAK                  = &H0811
%MCI_SAVE                   = &H0813
%MCI_STATUS                 = &H0814
%MCI_CUE                    = &H0830
%MCI_REALIZE                = &H0840
%MCI_WINDOW                 = &H0841
%MCI_PUT                    = &H0842
%MCI_WHERE                  = &H0843
%MCI_FREEZE                 = &H0844
%MCI_UNFREEZE               = &H0845
%MCI_LOAD                   = &H0850
%MCI_CUT                    = &H0851
%MCI_COPY                   = &H0852
%MCI_PASTE                  = &H0853
%MCI_UPDATE                 = &H0854
%MCI_RESUME                 = &H0855
%MCI_DELETE                 = &H0856

' all custom MCI command messages must be >= than this value
%MCI_USER_MESSAGES          = (%DRV_MCI_FIRST + &H400)
%MCI_LAST                   = &H0FFF


' device ID for "all devices"
%MCI_ALL_DEVICE_ID              = &HFFFFFFFF???  '  ((DWORD)-1)

' constants for predefined MCI device types
%MCI_DEVTYPE_VCR                = 513 ' (MCI_STRING_OFFSET + 1)
%MCI_DEVTYPE_VIDEODISC          = 514 ' (MCI_STRING_OFFSET + 2)
%MCI_DEVTYPE_OVERLAY            = 515 ' (MCI_STRING_OFFSET + 3)
%MCI_DEVTYPE_CD_AUDIO           = 516 ' (MCI_STRING_OFFSET + 4)
%MCI_DEVTYPE_DAT                = 517 ' (MCI_STRING_OFFSET + 5)
%MCI_DEVTYPE_SCANNER            = 518 ' (MCI_STRING_OFFSET + 6)
%MCI_DEVTYPE_ANIMATION          = 519 ' (MCI_STRING_OFFSET + 7)
%MCI_DEVTYPE_DIGITAL_VIDEO      = 520 ' (MCI_STRING_OFFSET + 8)
%MCI_DEVTYPE_OTHER              = 521 ' (MCI_STRING_OFFSET + 9)
%MCI_DEVTYPE_WAVEFORM_AUDIO     = 522 ' (MCI_STRING_OFFSET + 10)
%MCI_DEVTYPE_SEQUENCER          = 523 ' (MCI_STRING_OFFSET + 11)

%MCI_DEVTYPE_FIRST              = %MCI_DEVTYPE_VCR
%MCI_DEVTYPE_LAST               = %MCI_DEVTYPE_SEQUENCER

%MCI_DEVTYPE_FIRST_USER         = &H1000
' return values for 'status mode' command
%MCI_MODE_NOT_READY             = %MCI_STRING_OFFSET + 12
%MCI_MODE_STOP                  = %MCI_STRING_OFFSET + 13
%MCI_MODE_PLAY                  = %MCI_STRING_OFFSET + 14
%MCI_MODE_RECORD                = %MCI_STRING_OFFSET + 15
%MCI_MODE_SEEK                  = %MCI_STRING_OFFSET + 16
%MCI_MODE_PAUSE                 = %MCI_STRING_OFFSET + 17
%MCI_MODE_OPEN                  = %MCI_STRING_OFFSET + 18

' constants used in 'set time format' and 'status time format' commands
%MCI_FORMAT_MILLISECONDS        = 0
%MCI_FORMAT_HMS                 = 1
%MCI_FORMAT_MSF                 = 2
%MCI_FORMAT_FRAMES              = 3
%MCI_FORMAT_SMPTE_24            = 4
%MCI_FORMAT_SMPTE_25            = 5
%MCI_FORMAT_SMPTE_30            = 6
%MCI_FORMAT_SMPTE_30DROP        = 7
%MCI_FORMAT_BYTES               = 8
%MCI_FORMAT_SAMPLES             = 9
%MCI_FORMAT_TMSF                = 10

' MCI time format conversion macros
MACRO MCI_MSF_MINUTE(msf)=LO(BYTE,msf)
MACRO MCI_MSF_SECOND(msf)=HI(BYTE,LO(WORD,msf))
MACRO MCI_MSF_FRAME(msf)=LO(BYTE,HI(WORD,msf))

MACRO FUNCTION MCI_MAKE_MSF(m,s,f)
    MACROTEMP d1,d2,d3
    LOCAL d1,d2,d3 AS DWORD
    d1 = LO(BYTE, m)
    d2 = LO(WORD, s)
    SHIFT LEFT d2, 8
    d3 = LO(BYTE, f)
    SHIFT LEFT d3, 16
END MACRO=(d1 OR d2 OR d3)

MACRO MCI_TMSF_TRACK(tmsf)=LO(BYTE,tmsf)
MACRO MCI_TMSF_MINUTE(tmsf)=HI(BYTE,LO(WORD,tmsf))
MACRO MCI_TMSF_SECOND(tmsf)=LO(BYTE,HI(WORD,tmsf))
MACRO MCI_TMSF_FRAME(tmsf)=HI(BYTE,HI(WORD,tmsf))

MACRO FUNCTION MCI_MAKE_TMSF(t,m,s,f)
    MACROTEMP d1,d2,d3,d4
    LOCAL d1,d2,d3,d4 AS DWORD
    d1 = LO(BYTE, t)
    d2 = LO(WORD, m)
    SHIFT LEFT d2, 8
    d3 = LO(BYTE, s)
    d4 = LO(WORD, f)
    SHIFT LEFT d4, 8
    d3 OR= d4
    SHIFT LEFT d3, 16
END MACRO=(d1 OR d2 OR d3)

MACRO MCI_HMS_HOUR(hms)=LO(BYTE,hms)
MACRO MCI_HMS_MINUTE(hms)=HI(BYTE,LO(WORD,hms))
MACRO MCI_HMS_SECOND(hms)=LO(BYTE,HI(WORD,hms))

MACRO FUNCTION MCI_MAKE_HMS(h, m, s)
    MACROTEMP d1,d2,d3
    LOCAL d1,d2,d3 AS DWORD
    d1 = LO(BYTE, h)
    d2 = LO(WORD, m)
    SHIFT LEFT d2, 8
    d3 = LO(BYTE, s)
    SHIFT LEFT d3, 16
END MACRO=(d1 OR d2 OR d3)


' flags for wParam of MM_MCINOTIFY message
%MCI_NOTIFY_SUCCESSFUL           = &H0001
%MCI_NOTIFY_SUPERSEDED           = &H0002
%MCI_NOTIFY_ABORTED              = &H0004
%MCI_NOTIFY_FAILURE              = &H0008


' common flags for dwFlags parameter of MCI command messages
%MCI_NOTIFY                      = &H00000001
%MCI_WAIT                        = &H00000002
%MCI_FROM                        = &H00000004
%MCI_TO                          = &H00000008
%MCI_TRACK                       = &H00000010

' flags for dwFlags parameter of MCI_OPEN command message
%MCI_OPEN_SHAREABLE              = &H00000100
%MCI_OPEN_ELEMENT                = &H00000200
%MCI_OPEN_ALIAS                  = &H00000400
%MCI_OPEN_ELEMENT_ID             = &H00000800
%MCI_OPEN_TYPE_ID                = &H00001000
%MCI_OPEN_TYPE                   = &H00002000

' flags for dwFlags parameter of MCI_SEEK command message
%MCI_SEEK_TO_START               = &H00000100
%MCI_SEEK_TO_END                 = &H00000200

' flags for dwFlags parameter of MCI_STATUS command message
%MCI_STATUS_ITEM                 = &H00000100
%MCI_STATUS_START                = &H00000200

' flags for dwItem field of the MCI_STATUS_PARMS parameter block
%MCI_STATUS_LENGTH               = &H00000001
%MCI_STATUS_POSITION             = &H00000002
%MCI_STATUS_NUMBER_OF_TRACKS     = &H00000003
%MCI_STATUS_MODE                 = &H00000004
%MCI_STATUS_MEDIA_PRESENT        = &H00000005
%MCI_STATUS_TIME_FORMAT          = &H00000006
%MCI_STATUS_READY                = &H00000007
%MCI_STATUS_CURRENT_TRACK        = &H00000008

' flags for dwFlags parameter of MCI_INFO command message
%MCI_INFO_PRODUCT                = &H00000100
%MCI_INFO_FILE                   = &H00000200
%MCI_INFO_MEDIA_UPC              = &H00000400
%MCI_INFO_MEDIA_IDENTITY         = &H00000800
%MCI_INFO_NAME                   = &H00001000
%MCI_INFO_COPYRIGHT              = &H00002000

' flags for dwFlags parameter of MCI_GETDEVCAPS command message
%MCI_GETDEVCAPS_ITEM             = &H00000100

' flags for dwItem field of the MCI_GETDEVCAPS_PARMS parameter block
%MCI_GETDEVCAPS_CAN_RECORD       = &H00000001
%MCI_GETDEVCAPS_HAS_AUDIO        = &H00000002
%MCI_GETDEVCAPS_HAS_VIDEO        = &H00000003
%MCI_GETDEVCAPS_DEVICE_TYPE      = &H00000004
%MCI_GETDEVCAPS_USES_FILES       = &H00000005
%MCI_GETDEVCAPS_COMPOUND_DEVICE  = &H00000006
%MCI_GETDEVCAPS_CAN_EJECT        = &H00000007
%MCI_GETDEVCAPS_CAN_PLAY         = &H00000008
%MCI_GETDEVCAPS_CAN_SAVE         = &H00000009

' flags for dwFlags parameter of MCI_SYSINFO command message
%MCI_SYSINFO_QUANTITY            = &H00000100
%MCI_SYSINFO_OPEN                = &H00000200
%MCI_SYSINFO_NAME                = &H00000400
%MCI_SYSINFO_INSTALLNAME         = &H00000800

' flags for dwFlags parameter of MCI_SET command message
%MCI_SET_DOOR_OPEN               = &H00000100
%MCI_SET_DOOR_CLOSED             = &H00000200
%MCI_SET_TIME_FORMAT             = &H00000400
%MCI_SET_AUDIO                   = &H00000800
%MCI_SET_VIDEO                   = &H00001000
%MCI_SET_ON                      = &H00002000
%MCI_SET_OFF                     = &H00004000

' flags for dwAudio field of MCI_SET_PARMS or MCI_SEQ_SET_PARMS
%MCI_SET_AUDIO_ALL               = &H00000000
%MCI_SET_AUDIO_LEFT              = &H00000001
%MCI_SET_AUDIO_RIGHT             = &H00000002

' flags for dwFlags parameter of MCI_BREAK command message
%MCI_BREAK_KEY                   = &H00000100
%MCI_BREAK_HWND                  = &H00000200
%MCI_BREAK_OFF                   = &H00000400

' flags for dwFlags parameter of MCI_RECORD command message
%MCI_RECORD_INSERT               = &H00000100
%MCI_RECORD_OVERWRITE            = &H00000200

' flags for dwFlags parameter of MCI_SAVE command message
%MCI_SAVE_FILE                   = &H00000100

' flags for dwFlags parameter of MCI_LOAD command message
%MCI_LOAD_FILE                   = &H00000100


' generic parameter block for MCI command messages with no special parameters
TYPE MCI_GENERIC_PARMS
    dwCallback AS DWORD
END TYPE


' parameter block for MCI_OPEN command message

TYPE MCI_OPEN_PARMSA
    dwCallback       AS DWORD
    wDeviceID        AS DWORD
    lpstrDeviceType  AS ASCIIZ PTR
    lpstrElementName AS ASCIIZ PTR
    lpstrAlias       AS ASCIIZ PTR
END TYPE

TYPE MCI_OPEN_PARMSW
    dwCallback       AS DWORD
    wDeviceID        AS DWORD
    lpstrDeviceType  AS WSTRINGZ PTR
    lpstrElementName AS WSTRINGZ PTR
    lpstrAlias       AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_OPEN_PARMS
    MCI_OPEN_PARMSW
END TYPE
#ELSE
TYPE MCI_OPEN_PARMS
    MCI_OPEN_PARMSA
END TYPE
#ENDIF ' %UNICODE


' parameter block for MCI_PLAY command message
TYPE MCI_PLAY_PARMS
    dwCallback AS DWORD
    dwFrom     AS DWORD
    dwTo       AS DWORD
END TYPE


' parameter block for MCI_SEEK command message
TYPE MCI_SEEK_PARMS
    dwCallback AS DWORD
    dwTo       AS DWORD
END TYPE


' parameter block for MCI_STATUS command message
TYPE MCI_STATUS_PARMS
    dwCallback AS DWORD
    dwReturn   AS DWORD
    dwItem     AS DWORD
    dwTrack    AS DWORD
END TYPE


' parameter block for MCI_INFO command message

TYPE MCI_INFO_PARMSA
    dwCallback  AS DWORD
    lpstrReturn AS ASCIIZ PTR
    dwRetSize   AS DWORD
END TYPE

TYPE MCI_INFO_PARMSW
    dwCallback  AS DWORD
    lpstrReturn AS WSTRINGZ PTR
    dwRetSize   AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_INFO_PARMS
    MCI_INFO_PARMSW
END TYPE
#ELSE
TYPE MCI_INFO_PARMS
    MCI_INFO_PARMSA
END TYPE
#ENDIF ' %UNICODE


' parameter block for MCI_GETDEVCAPS command message
TYPE MCI_GETDEVCAPS_PARMS
    dwCallback AS DWORD
    dwReturn   AS DWORD
    dwItem     AS DWORD
END TYPE


' parameter block for MCI_SYSINFO command message

TYPE MCI_SYSINFO_PARMSA
    dwCallback  AS DWORD
    lpstrReturn AS ASCIIZ PTR
    dwRetSize   AS DWORD
    dwNumber    AS DWORD
    wDeviceType AS DWORD
END TYPE

TYPE MCI_SYSINFO_PARMSW
    dwCallback  AS DWORD
    lpstrReturn AS WSTRINGZ PTR
    dwRetSize   AS DWORD
    dwNumber    AS DWORD
    wDeviceType AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_SYSINFO_PARMS
    MCI_SYSINFO_PARMSW
END TYPE
#ELSE
TYPE MCI_SYSINFO_PARMS
    MCI_SYSINFO_PARMSA
END TYPE
#ENDIF ' %UNICODE


' parameter block for MCI_SET command message
TYPE MCI_SET_PARMS
    dwCallback   AS DWORD
    dwTimeFormat AS DWORD
    dwAudio      AS DWORD
END TYPE


' parameter block for MCI_BREAK command message
TYPE MCI_BREAK_PARMS
    dwCallback AS DWORD
    nVirtKey   AS LONG
    hwndBreak  AS DWORD
END TYPE


' parameter block for MCI_SAVE command message

TYPE MCI_SAVE_PARMSA
    dwCallback AS DWORD
    lpfilename AS ASCIIZ PTR
END TYPE

TYPE MCI_SAVE_PARMSW
    dwCallback AS DWORD
    lpfilename AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_SAVE_PARMS
    MCI_SAVE_PARMSW
END TYPE
#ELSE
TYPE MCI_SAVE_PARMS
    MCI_SAVE_PARMSA
END TYPE
#ENDIF ' %UNICODE


' parameter block for MCI_LOAD command message

TYPE MCI_LOAD_PARMSA
    dwCallback AS DWORD
    lpfilename AS ASCIIZ PTR
END TYPE

TYPE MCI_LOAD_PARMSW
    dwCallback AS DWORD
    lpfilename AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_LOAD_PARMS
    MCI_LOAD_PARMSW
END TYPE
#ELSE
TYPE MCI_LOAD_PARMS
    MCI_LOAD_PARMSA
END TYPE
#ENDIF ' %UNICODE


' parameter block for MCI_RECORD command message
TYPE MCI_RECORD_PARMS
    dwCallback AS DWORD
    dwFrom     AS DWORD
    dwTo       AS DWORD
END TYPE


' MCI extensions for videodisc devices

' flag for dwReturn field of MCI_STATUS_PARMS
' MCI_STATUS command, (dwItem == MCI_STATUS_MODE)
%MCI_VD_MODE_PARK                = %MCI_VD_OFFSET + 1

' flag for dwReturn field of MCI_STATUS_PARMS
' MCI_STATUS command, (dwItem == MCI_VD_STATUS_MEDIA_TYPE)
%MCI_VD_MEDIA_CLV                = %MCI_VD_OFFSET + 2
%MCI_VD_MEDIA_CAV                = %MCI_VD_OFFSET + 3
%MCI_VD_MEDIA_OTHER              = %MCI_VD_OFFSET + 4

%MCI_VD_FORMAT_TRACK             = &H4001

' flags for dwFlags parameter of MCI_PLAY command message
%MCI_VD_PLAY_REVERSE             = &H00010000
%MCI_VD_PLAY_FAST                = &H00020000
%MCI_VD_PLAY_SPEED               = &H00040000
%MCI_VD_PLAY_SCAN                = &H00080000
%MCI_VD_PLAY_SLOW                = &H00100000

' flag for dwFlags parameter of MCI_SEEK command message
%MCI_VD_SEEK_REVERSE             = &H00010000

' flags for dwItem field of MCI_STATUS_PARMS parameter block
%MCI_VD_STATUS_SPEED             = &H00004002
%MCI_VD_STATUS_FORWARD           = &H00004003
%MCI_VD_STATUS_MEDIA_TYPE        = &H00004004
%MCI_VD_STATUS_SIDE              = &H00004005
%MCI_VD_STATUS_DISC_SIZE         = &H00004006

' flags for dwFlags parameter of MCI_GETDEVCAPS command message
%MCI_VD_GETDEVCAPS_CLV           = &H00010000
%MCI_VD_GETDEVCAPS_CAV           = &H00020000

%MCI_VD_SPIN_UP                  = &H00010000
%MCI_VD_SPIN_DOWN                = &H00020000

' flags for dwItem field of MCI_GETDEVCAPS_PARMS parameter block
%MCI_VD_GETDEVCAPS_CAN_REVERSE   = &H00004002
%MCI_VD_GETDEVCAPS_FAST_RATE     = &H00004003
%MCI_VD_GETDEVCAPS_SLOW_RATE     = &H00004004
%MCI_VD_GETDEVCAPS_NORMAL_RATE   = &H00004005

' flags for the dwFlags parameter of MCI_STEP command message
%MCI_VD_STEP_FRAMES              = &H00010000
%MCI_VD_STEP_REVERSE             = &H00020000

' flag for the MCI_ESCAPE command message
%MCI_VD_ESCAPE_STRING            = &H00000100


' parameter block for MCI_PLAY command message
TYPE MCI_VD_PLAY_PARMS
    dwCallback AS DWORD
    dwFrom     AS DWORD
    dwTo       AS DWORD
    dwSpeed    AS DWORD
END TYPE


' parameter block for MCI_STEP command message
TYPE MCI_VD_STEP_PARMS
    dwCallback AS DWORD
    dwFrames   AS DWORD
END TYPE


' parameter block for MCI_ESCAPE command message

TYPE MCI_VD_ESCAPE_PARMSA
    dwCallback   AS DWORD
    lpstrCommand AS ASCIIZ PTR
END TYPE

TYPE MCI_VD_ESCAPE_PARMSW
    dwCallback   AS DWORD
    lpstrCommand AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_VD_ESCAPE_PARMS
    MCI_VD_ESCAPE_PARMSW
END TYPE
#ELSE
TYPE MCI_VD_ESCAPE_PARMS
    MCI_VD_ESCAPE_PARMSA
END TYPE
#ENDIF ' %UNICODE

' MCI extensions for CD audio devices

' flags for the dwItem field of the MCI_STATUS_PARMS parameter block
%MCI_CDA_STATUS_TYPE_TRACK       = &H00004001

' flags for the dwReturn field of MCI_STATUS_PARMS parameter block
' MCI_STATUS command, (dwItem == MCI_CDA_STATUS_TYPE_TRACK)
%MCI_CDA_TRACK_AUDIO             = %MCI_CD_OFFSET + 0
%MCI_CDA_TRACK_OTHER             = %MCI_CD_OFFSET + 1

' MCI extensions for waveform audio devices

%MCI_WAVE_PCM                    = %MCI_WAVE_OFFSET + 0
%MCI_WAVE_MAPPER                 = %MCI_WAVE_OFFSET + 1

' flags for the dwFlags parameter of MCI_OPEN command message
%MCI_WAVE_OPEN_BUFFER            = &H00010000

' flags for the dwFlags parameter of MCI_SET command message
%MCI_WAVE_SET_FORMATTAG          = &H00010000
%MCI_WAVE_SET_CHANNELS           = &H00020000
%MCI_WAVE_SET_SAMPLESPERSEC      = &H00040000
%MCI_WAVE_SET_AVGBYTESPERSEC     = &H00080000
%MCI_WAVE_SET_BLOCKALIGN         = &H00100000
%MCI_WAVE_SET_BITSPERSAMPLE      = &H00200000

' flags for the dwFlags parameter of MCI_STATUS, MCI_SET command messages
%MCI_WAVE_INPUT                  = &H00400000
%MCI_WAVE_OUTPUT                 = &H00800000

' flags for the dwItem field of MCI_STATUS_PARMS parameter block
%MCI_WAVE_STATUS_FORMATTAG       = &H00004001
%MCI_WAVE_STATUS_CHANNELS        = &H00004002
%MCI_WAVE_STATUS_SAMPLESPERSEC   = &H00004003
%MCI_WAVE_STATUS_AVGBYTESPERSEC  = &H00004004
%MCI_WAVE_STATUS_BLOCKALIGN      = &H00004005
%MCI_WAVE_STATUS_BITSPERSAMPLE   = &H00004006
%MCI_WAVE_STATUS_LEVEL           = &H00004007

' flags for the dwFlags parameter of MCI_SET command message
%MCI_WAVE_SET_ANYINPUT           = &H04000000
%MCI_WAVE_SET_ANYOUTPUT          = &H08000000

' flags for the dwFlags parameter of MCI_GETDEVCAPS command message
%MCI_WAVE_GETDEVCAPS_INPUTS      = &H00004001
%MCI_WAVE_GETDEVCAPS_OUTPUTS     = &H00004002


' parameter block for MCI_OPEN command message

TYPE MCI_WAVE_OPEN_PARMSA
    dwCallback       AS DWORD
    wDeviceID        AS DWORD
    lpstrDeviceType  AS ASCIIZ PTR
    lpstrElementName AS ASCIIZ PTR
    lpstrAlias       AS ASCIIZ PTR
    dwBufferSeconds  AS DWORD
END TYPE

TYPE MCI_WAVE_OPEN_PARMSW
    dwCallback       AS DWORD
    wDeviceID        AS DWORD
    lpstrDeviceType  AS WSTRINGZ PTR
    lpstrElementName AS WSTRINGZ PTR
    lpstrAlias       AS WSTRINGZ PTR
    dwBufferSeconds  AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_WAVE_OPEN_PARMS
    MCI_WAVE_OPEN_PARMSW
END TYPE
#ELSE
TYPE MCI_WAVE_OPEN_PARMS
    MCI_WAVE_OPEN_PARMSA
END TYPE
#ENDIF ' %UNICODE


' parameter block for MCI_DELETE command message
TYPE MCI_WAVE_DELETE_PARMS
    dwCallback AS DWORD
    dwFrom     AS DWORD
    dwTo       AS DWORD
END TYPE


' parameter block for MCI_SET command message
TYPE MCI_WAVE_SET_PARMS
    dwCallback      AS DWORD
    dwTimeFormat    AS DWORD
    dwAudio         AS DWORD
    wInput          AS DWORD
    wOutput         AS DWORD
    wFormatTag      AS WORD
    wReserved2      AS WORD
    nChannels       AS WORD
    wReserved3      AS WORD
    nSamplesPerSec  AS DWORD
    nAvgBytesPerSec AS DWORD
    nBlockAlign     AS WORD
    wReserved4      AS WORD
    wBitsPerSample  AS WORD
    wReserved5      AS WORD
END TYPE


' MCI extensions for MIDI sequencer devices

' flags for the dwReturn field of MCI_STATUS_PARMS parameter block
' MCI_STATUS command, (dwItem == MCI_SEQ_STATUS_DIVTYPE)
%MCI_SEQ_DIV_PPQN            = 0 + %MCI_SEQ_OFFSET
%MCI_SEQ_DIV_SMPTE_24        = 1 + %MCI_SEQ_OFFSET
%MCI_SEQ_DIV_SMPTE_25        = 2 + %MCI_SEQ_OFFSET
%MCI_SEQ_DIV_SMPTE_30DROP    = 3 + %MCI_SEQ_OFFSET
%MCI_SEQ_DIV_SMPTE_30        = 4 + %MCI_SEQ_OFFSET

' flags for the dwMaster field of MCI_SEQ_SET_PARMS parameter block
' MCI_SET command, (dwFlags == MCI_SEQ_SET_MASTER)
%MCI_SEQ_FORMAT_SONGPTR   = &H4001
%MCI_SEQ_FILE             = &H4002
%MCI_SEQ_MIDI             = &H4003
%MCI_SEQ_SMPTE            = &H4004
%MCI_SEQ_NONE             = 65533
%MCI_SEQ_MAPPER           = 65535

' flags for the dwItem field of MCI_STATUS_PARMS parameter block
%MCI_SEQ_STATUS_TEMPO         = &H00004002
%MCI_SEQ_STATUS_PORT          = &H00004003
%MCI_SEQ_STATUS_SLAVE         = &H00004007
%MCI_SEQ_STATUS_MASTER        = &H00004008
%MCI_SEQ_STATUS_OFFSET        = &H00004009
%MCI_SEQ_STATUS_DIVTYPE       = &H0000400A
%MCI_SEQ_STATUS_NAME          = &H0000400B
%MCI_SEQ_STATUS_COPYRIGHT     = &H0000400C

' flags for the dwFlags parameter of MCI_SET command message
%MCI_SEQ_SET_TEMPO            = &H00010000
%MCI_SEQ_SET_PORT             = &H00020000
%MCI_SEQ_SET_SLAVE            = &H00040000
%MCI_SEQ_SET_MASTER           = &H00080000
%MCI_SEQ_SET_OFFSET           = &H01000000


' parameter block for MCI_SET command message
TYPE MCI_SEQ_SET_PARMS
    dwCallback   AS DWORD
    dwTimeFormat AS DWORD
    dwAudio      AS DWORD
    dwTempo      AS DWORD
    dwPort       AS DWORD
    dwSlave      AS DWORD
    dwMaster     AS DWORD
    dwOffset     AS DWORD
END TYPE


' MCI extensions for animation devices

' flags for dwFlags parameter of MCI_OPEN command message
%MCI_ANIM_OPEN_WS                = &H00010000
%MCI_ANIM_OPEN_PARENT            = &H00020000
%MCI_ANIM_OPEN_NOSTATIC          = &H00040000

' flags for dwFlags parameter of MCI_PLAY command message
%MCI_ANIM_PLAY_SPEED             = &H00010000
%MCI_ANIM_PLAY_REVERSE           = &H00020000
%MCI_ANIM_PLAY_FAST              = &H00040000
%MCI_ANIM_PLAY_SLOW              = &H00080000
%MCI_ANIM_PLAY_SCAN              = &H00100000

' flags for dwFlags parameter of MCI_STEP command message
%MCI_ANIM_STEP_REVERSE           = &H00010000
%MCI_ANIM_STEP_FRAMES            = &H00020000

' flags for dwItem field of MCI_STATUS_PARMS parameter block
%MCI_ANIM_STATUS_SPEED           = &H00004001
%MCI_ANIM_STATUS_FORWARD         = &H00004002
%MCI_ANIM_STATUS_HWND            = &H00004003
%MCI_ANIM_STATUS_HPAL            = &H00004004
%MCI_ANIM_STATUS_STRETCH         = &H00004005

' flags for the dwFlags parameter of MCI_INFO command message
%MCI_ANIM_INFO_TEXT              = &H00010000

' flags for dwItem field of MCI_GETDEVCAPS_PARMS parameter block
%MCI_ANIM_GETDEVCAPS_CAN_REVERSE = &H00004001
%MCI_ANIM_GETDEVCAPS_FAST_RATE   = &H00004002
%MCI_ANIM_GETDEVCAPS_SLOW_RATE   = &H00004003
%MCI_ANIM_GETDEVCAPS_NORMAL_RATE = &H00004004
%MCI_ANIM_GETDEVCAPS_PALETTES    = &H00004006
%MCI_ANIM_GETDEVCAPS_CAN_STRETCH = &H00004007
%MCI_ANIM_GETDEVCAPS_MAX_WINDOWS = &H00004008

' flags for the MCI_REALIZE command message
%MCI_ANIM_REALIZE_NORM           = &H00010000
%MCI_ANIM_REALIZE_BKGD           = &H00020000

' flags for dwFlags parameter of MCI_WINDOW command message
%MCI_ANIM_WINDOW_HWND            = &H00010000
%MCI_ANIM_WINDOW_STATE           = &H00040000
%MCI_ANIM_WINDOW_TEXT            = &H00080000
%MCI_ANIM_WINDOW_ENABLE_STRETCH  = &H00100000
%MCI_ANIM_WINDOW_DISABLE_STRETCH = &H00200000

' flags for hWnd field of MCI_ANIM_WINDOW_PARMS parameter block
' MCI_WINDOW command message, (dwFlags == MCI_ANIM_WINDOW_HWND)
%MCI_ANIM_WINDOW_DEFAULT         = &H00000000

' flags for dwFlags parameter of MCI_PUT command message
%MCI_ANIM_RECT                   = &H00010000
%MCI_ANIM_PUT_SOURCE             = &H00020000
%MCI_ANIM_PUT_DESTINATION        = &H00040000

' flags for dwFlags parameter of MCI_WHERE command message
%MCI_ANIM_WHERE_SOURCE           = &H00020000
%MCI_ANIM_WHERE_DESTINATION      = &H00040000

' flags for dwFlags parameter of MCI_UPDATE command message
%MCI_ANIM_UPDATE_HDC             = &H00020000


' parameter block for MCI_OPEN command message

TYPE MCI_ANIM_OPEN_PARMSA
    dwCallback       AS DWORD
    wDeviceID        AS DWORD
    lpstrDeviceType  AS ASCIIZ PTR
    lpstrElementName AS ASCIIZ PTR
    lpstrAlias       AS ASCIIZ PTR
    dwStyle          AS DWORD
    hWndParent       AS DWORD
END TYPE

TYPE MCI_ANIM_OPEN_PARMSW
    dwCallback       AS DWORD
    wDeviceID        AS DWORD
    lpstrDeviceType  AS WSTRINGZ PTR
    lpstrElementName AS WSTRINGZ PTR
    lpstrAlias       AS WSTRINGZ PTR
    dwStyle          AS DWORD
    hWndParent       AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_ANIM_OPEN_PARMS
    MCI_ANIM_OPEN_PARMSW
END TYPE
#ELSE
TYPE MCI_ANIM_OPEN_PARMS
    MCI_ANIM_OPEN_PARMSA
END TYPE
#ENDIF ' %UNICODE



' parameter block for MCI_PLAY command message
TYPE MCI_ANIM_PLAY_PARMS
    dwCallback AS DWORD
    dwFrom     AS DWORD
    dwTo       AS DWORD
    dwSpeed    AS DWORD
END TYPE


' parameter block for MCI_STEP command message
TYPE MCI_ANIM_STEP_PARMS
    dwCallback AS DWORD
    dwFrames   AS DWORD
END TYPE


' parameter block for MCI_WINDOW command message

TYPE MCI_ANIM_WINDOW_PARMSA
    dwCallback AS DWORD
    hWnd       AS DWORD
    nCmdShow   AS DWORD
    lpstrText  AS ASCIIZ PTR
END TYPE

TYPE MCI_ANIM_WINDOW_PARMSW
    dwCallback AS DWORD
    hWnd       AS DWORD
    nCmdShow   AS DWORD
    lpstrText  AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_ANIM_WINDOW_PARMS
    MCI_ANIM_WINDOW_PARMSW
END TYPE
#ELSE
TYPE MCI_ANIM_WINDOW_PARMS
    MCI_ANIM_WINDOW_PARMSA
END TYPE
#ENDIF ' %UNICODE



' parameter block for MCI_PUT, MCI_UPDATE, MCI_WHERE command messages
TYPE MCI_ANIM_RECT_PARMS
    dwCallback AS DWORD
#IF %DEF(%MCI_USE_OFFEXT)
    ptOffset   AS POINT
    ptExtent   AS POINT
#ELSE   ' ifdef MCI_USE_OFFEXT
    rc         AS RECT
#ENDIF  ' ifdef MCI_USE_OFFEXT
END TYPE


' parameter block for MCI_UPDATE PARMS
TYPE MCI_ANIM_UPDATE_PARMS
    dwCallback AS DWORD
    rc         AS RECT
    hDC        AS DWORD  ' HDC
END TYPE


' MCI extensions for video overlay devices

' flags for dwFlags parameter of MCI_OPEN command message
%MCI_OVLY_OPEN_WS                = &H00010000
%MCI_OVLY_OPEN_PARENT            = &H00020000

' flags for dwFlags parameter of MCI_STATUS command message
%MCI_OVLY_STATUS_HWND            = &H00004001
%MCI_OVLY_STATUS_STRETCH         = &H00004002

' flags for dwFlags parameter of MCI_INFO command message
%MCI_OVLY_INFO_TEXT              = &H00010000

' flags for dwItem field of MCI_GETDEVCAPS_PARMS parameter block
%MCI_OVLY_GETDEVCAPS_CAN_STRETCH = &H00004001
%MCI_OVLY_GETDEVCAPS_CAN_FREEZE  = &H00004002
%MCI_OVLY_GETDEVCAPS_MAX_WINDOWS = &H00004003

' flags for dwFlags parameter of MCI_WINDOW command message
%MCI_OVLY_WINDOW_HWND            = &H00010000
%MCI_OVLY_WINDOW_STATE           = &H00040000
%MCI_OVLY_WINDOW_TEXT            = &H00080000
%MCI_OVLY_WINDOW_ENABLE_STRETCH  = &H00100000
%MCI_OVLY_WINDOW_DISABLE_STRETCH = &H00200000

' flags for hWnd parameter of MCI_OVLY_WINDOW_PARMS parameter block
%MCI_OVLY_WINDOW_DEFAULT         = &H00000000

' flags for dwFlags parameter of MCI_PUT command message
%MCI_OVLY_RECT                   = &H00010000
%MCI_OVLY_PUT_SOURCE             = &H00020000
%MCI_OVLY_PUT_DESTINATION        = &H00040000
%MCI_OVLY_PUT_FRAME              = &H00080000
%MCI_OVLY_PUT_VIDEO              = &H00100000

' flags for dwFlags parameter of MCI_WHERE command message
%MCI_OVLY_WHERE_SOURCE           = &H00020000
%MCI_OVLY_WHERE_DESTINATION      = &H00040000
%MCI_OVLY_WHERE_FRAME            = &H00080000
%MCI_OVLY_WHERE_VIDEO            = &H00100000


' parameter block for MCI_OPEN command message

TYPE MCI_OVLY_OPEN_PARMSA
    dwCallback       AS DWORD
    wDeviceID        AS DWORD
    lpstrDeviceType  AS ASCIIZ PTR
    lpstrElementName AS ASCIIZ PTR
    lpstrAlias       AS ASCIIZ PTR
    dwStyle          AS DWORD
    hWndParent       AS DWORD
END TYPE

TYPE MCI_OVLY_OPEN_PARMSW
    dwCallback       AS DWORD
    wDeviceID        AS DWORD
    lpstrDeviceType  AS WSTRINGZ PTR
    lpstrElementName AS WSTRINGZ PTR
    lpstrAlias       AS WSTRINGZ PTR
    dwStyle          AS DWORD
    hWndParent       AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_OVLY_OPEN_PARMS
    MCI_OVLY_OPEN_PARMSW
END TYPE
#ELSE
TYPE MCI_OVLY_OPEN_PARMS
    MCI_OVLY_OPEN_PARMSA
END TYPE
#ENDIF ' %UNICODE



' parameter block for MCI_WINDOW command message

TYPE MCI_OVLY_WINDOW_PARMSA
    dwCallback AS DWORD
    hWnd       AS DWORD
    nCmdShow   AS DWORD
    lpstrText  AS ASCIIZ PTR
END TYPE

TYPE MCI_OVLY_WINDOW_PARMSW
    dwCallback AS DWORD
    hWnd       AS DWORD
    nCmdShow   AS DWORD
    lpstrText  AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_OVLY_WINDOW_PARMS
    MCI_OVLY_WINDOW_PARMSW
END TYPE
#ELSE
TYPE MCI_OVLY_WINDOW_PARMS
    MCI_OVLY_WINDOW_PARMSA
END TYPE
#ENDIF ' %UNICODE


' parameter block for MCI_PUT, MCI_UPDATE, and MCI_WHERE command messages
TYPE MCI_OVLY_RECT_PARMS
    dwCallback AS DWORD
#IF %DEF(%MCI_USE_OFFEXT)
    ptOffset  AS POINT
    ptExtent  AS POINT
#ELSE   ' ifdef MCI_USE_OFFEXT
    rc        AS RECT
#ENDIF  ' ifdef MCI_USE_OFFEXT
END TYPE


' parameter block for MCI_SAVE command message

TYPE MCI_OVLY_SAVE_PARMSA
    dwCallback AS DWORD
    lpfilename AS ASCIIZ PTR
    rc         AS RECT
END TYPE

TYPE MCI_OVLY_SAVE_PARMSW
    dwCallback AS DWORD
    lpfilename AS WSTRINGZ PTR
    rc         AS RECT
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_OVLY_SAVE_PARMS
    MCI_OVLY_SAVE_PARMSW
END TYPE
#ELSE
TYPE MCI_OVLY_SAVE_PARMS
    MCI_OVLY_SAVE_PARMSA
END TYPE
#ENDIF ' %UNICODE



' parameter block for MCI_LOAD command message

TYPE MCI_OVLY_LOAD_PARMSA
    dwCallback AS DWORD
    lpfilename AS ASCIIZ PTR
    rc         AS RECT
END TYPE

TYPE MCI_OVLY_LOAD_PARMSW
    dwCallback AS DWORD
    lpfilename AS WSTRINGZ PTR
    rc         AS RECT
END TYPE

#IF %DEF(%UNICODE)
TYPE MCI_OVLY_LOAD_PARMS
    MCI_OVLY_LOAD_PARMSW
END TYPE
#ELSE
TYPE MCI_OVLY_LOAD_PARMS
    MCI_OVLY_LOAD_PARMSA
END TYPE
#ENDIF ' %UNICODE

#ENDIF  ' ifndef MMNOMCI

'****************************************************************************
'
'                       DISPLAY Driver extensions
'
'****************************************************************************

#IF NOT %DEF(%NEWTRANSPARENT)
%NEWTRANSPARENT = 3           ' use with SetBkMode()
%QUERYROPSUPPORT = 40          ' use to determine ROP support
#ENDIF  ' ifndef NEWTRANSPARENT

'****************************************************************************
'
'                       DIB Driver extensions
'
'****************************************************************************

%SELECTDIB     = 41                      ' DIB.DRV select dib escape

MACRO DIBINDEX(n)=MAK(LONG,n,&H10FF)


'****************************************************************************
'
'                       ScreenSaver support
'
'   The current application will receive a syscommand of SC_SCREENSAVE just
'   before the screen saver is invoked.  If the app wishes to prevent a
'   screen save, return non-zero value, otherwise call DefWindowProc().
'
'****************************************************************************

#IF NOT %DEF(%SC_SCREENSAVE)

%SC_SCREENSAVE = &HF140

#ENDIF  ' ifndef SC_SCREENSAVE
