'------------------------------------------------------------------------------
'
'  MCIAVI.inc -- Multimedia Systems Media Control Interface / AVI support
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
' from mciavi.h version 1.00 "of 16-JUL-1992", dated 14 Jul 2009.
'------------------------------------------------------------------------------


#INCLUDE THIS ONCE

%MCIAVI_INC = 1

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "WinDef.inc"
#INCLUDE "MMSystem.inc"



'
' These three flags apply to the 'play' command:
'  play <alias> window             Play in normal window
'  play <alias> fullscreen         Play in 320x240 full-screen mode
'  play <alias> fullscreen by 2    Play fullscreen, zoomed by 2
'
%MCI_MCIAVI_PLAY_WINDOW     = &H01000000
%MCI_MCIAVI_PLAY_FULLSCREEN = &H02000000
%MCI_MCIAVI_PLAY_FULLBY2    = &H04000000
'
' Debugging constants for AVI diagnostics
'
'
' Returns number of frames not drawn during last play.  If this number
' is more than a small fraction of the number of frames that should have
' been displayed, things aren't looking good.
'
%MCI_AVI_STATUS_FRAMES_SKIPPED     = &H00008001
'
' Returns a number representing how well the last AVI play worked.
' A result of 1000 indicates that the AVI sequence took the amount
' of time to play that it should have; a result of 2000, for instance,
' would indicate that a 5-second AVI sequence took 10 seconds to play,
' implying that the audio and video were badly broken up.
'
%MCI_AVI_STATUS_LAST_PLAY_SPEED    = &H00008002
'
' Returns the number of times that the audio definitely broke up.
' (We count one for every time we're about to write some audio data
' to the driver, and we notice that it's already played all of the
' data we have.
'
%MCI_AVI_STATUS_AUDIO_BREAKS       = &H00008003


%MCI_AVI_SETVIDEO_DRAW_PROCEDURE   = &H00008000

%MCI_AVI_SETVIDEO_PALETTE_COLOR    = &H00008100


'
' This constant specifies that the "halftone" palette should be
' used, rather than the default palette.
'
%MCI_AVI_SETVIDEO_PALETTE_HALFTONE = &H0000FFFF

'
'  Custom error return values
'
%MCIERR_AVI_OLDAVIFORMAT       = %MCIERR_CUSTOM_DRIVER_BASE + 100
%MCIERR_AVI_NOTINTERLEAVED     = %MCIERR_CUSTOM_DRIVER_BASE + 101
%MCIERR_AVI_NODISPDIB          = %MCIERR_CUSTOM_DRIVER_BASE + 102
%MCIERR_AVI_CANTPLAYFULLSCREEN = %MCIERR_CUSTOM_DRIVER_BASE + 103
%MCIERR_AVI_TOOBIGFORVGA       = %MCIERR_CUSTOM_DRIVER_BASE + 104
%MCIERR_AVI_NOCOMPRESSOR       = %MCIERR_CUSTOM_DRIVER_BASE + 105
%MCIERR_AVI_DISPLAYERROR       = %MCIERR_CUSTOM_DRIVER_BASE + 106
%MCIERR_AVI_AUDIOERROR         = %MCIERR_CUSTOM_DRIVER_BASE + 107
%MCIERR_AVI_BADPALETTE         = %MCIERR_CUSTOM_DRIVER_BASE + 108
