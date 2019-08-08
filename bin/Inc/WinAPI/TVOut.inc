'------------------------------------------------------------------------------
'
'  TVOut.inc
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from TVOut.h dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%TVOUT = 1


'#IF NOT %DEF(%GUID_DEFINED)
'#INCLUDE "guiddef.inc"
'#ENDIF

TYPE VIDEOPARAMETERS
    nGuid                   AS GUID   ' GUID for this structure
    dwOffset                AS DWORD  ' leave it 0 for now.
    dwCommand               AS DWORD  ' VP_COMMAND_*            SET or GET
    dwFlags                 AS DWORD  ' bitfield, defined below SET or GET
    dwMode                  AS DWORD  ' bitfield, defined below SET or GET
    dwTVStandard            AS DWORD  ' bitfield, defined below SET or GET
    dwAvailableModes        AS DWORD  ' bitfield, defined below GET
    dwAvailableTVStandard   AS DWORD  ' bitfield, defined below GET
    dwFlickerFilter         AS DWORD  ' value                   SET or GET
    dwOverScanX             AS DWORD  ' value                   SET or GET
    dwOverScanY             AS DWORD  '                         SET or GET
    dwMaxUnscaledX          AS DWORD  ' value                   SET or GET
    dwMaxUnscaledY          AS DWORD  '                         SET or GET
    dwPositionX             AS DWORD  ' value                   SET or GET
    dwPositionY             AS DWORD  '                         SET or GET
    dwBrightness            AS DWORD  ' value                   SET or GET
    dwContrast              AS DWORD  ' value                   SET or GET
    dwCPType                AS DWORD  ' copy protection type    SET or GET
    dwCPCommand             AS DWORD  ' VP_CP_CMD_
    dwCPStandard            AS DWORD  ' what TV standards CP is available on. GET
    dwCPKey                 AS DWORD
    bCP_APSTriggerBits      AS DWORD  ' (a dword for alignment) SET(bits 0 and 1 valid).
    bOEMCopyProtection(255) AS BYTE   ' oem-specific copy protection data SET or GET
END TYPE

%VP_COMMAND_GET          = &H0001  ' size set, return caps.
                                        ' returned Flags = 0 if not supported.
%VP_COMMAND_SET          = &H0002  ' size and params set.

%VP_FLAGS_TV_MODE        = &H0001
%VP_FLAGS_TV_STANDARD    = &H0002
%VP_FLAGS_FLICKER        = &H0004
%VP_FLAGS_OVERSCAN       = &H0008
%VP_FLAGS_MAX_UNSCALED   = &H0010  ' do not use on SET
%VP_FLAGS_POSITION       = &H0020
%VP_FLAGS_BRIGHTNESS     = &H0040
%VP_FLAGS_CONTRAST       = &H0080
%VP_FLAGS_COPYPROTECT    = &H0100

%VP_MODE_WIN_GRAPHICS    = &H0001
%VP_MODE_TV_PLAYBACK     = &H0002  ' optimize for TV video playback

%VP_TV_STANDARD_NTSC_M   = &H0001  '        75 IRE Setup
%VP_TV_STANDARD_NTSC_M_J = &H0002  ' Japan,  0 IRE Setup
%VP_TV_STANDARD_PAL_B    = &H0004
%VP_TV_STANDARD_PAL_D    = &H0008
%VP_TV_STANDARD_PAL_H    = &H0010
%VP_TV_STANDARD_PAL_I    = &H0020
%VP_TV_STANDARD_PAL_M    = &H0040
%VP_TV_STANDARD_PAL_N    = &H0080
%VP_TV_STANDARD_SECAM_B  = &H0100
%VP_TV_STANDARD_SECAM_D  = &H0200
%VP_TV_STANDARD_SECAM_G  = &H0400
%VP_TV_STANDARD_SECAM_H  = &H0800
%VP_TV_STANDARD_SECAM_K  = &H1000
%VP_TV_STANDARD_SECAM_K1 = &H2000
%VP_TV_STANDARD_SECAM_L  = &H4000
%VP_TV_STANDARD_WIN_VGA  = &H8000??
' and the rest
%VP_TV_STANDARD_NTSC_433 = &H00010000
%VP_TV_STANDARD_PAL_G    = &H00020000
%VP_TV_STANDARD_PAL_60   = &H00040000
%VP_TV_STANDARD_SECAM_L1 = &H00080000

%VP_CP_TYPE_APS_TRIGGER  = &H0001  ' DVD trigger bits only
%VP_CP_TYPE_MACROVISION  = &H0002  ' full macrovision data available

%VP_CP_CMD_ACTIVATE      = &H0001  ' CP command type
%VP_CP_CMD_DEACTIVATE    = &H0002
%VP_CP_CMD_CHANGE        = &H0004
