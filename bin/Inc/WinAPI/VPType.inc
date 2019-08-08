'------------------------------------------------------------------------------
'
'  VPType.inc -- all the data structures defined for the IVPConfig interface.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from VPType.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%IVPType = 1

#INCLUDE "WinDef.inc"

' enum to specify the criterion, which the vpmixer is supposed to use
' in order to select the video format
MACRO AMVP_SELECT_FORMAT_BY_enum=LONG
ENUM AMVP_SELECT_FORMAT_BY SINGULAR
    AMVP_DO_NOT_CARE
    AMVP_BEST_BANDWIDTH
    AMVP_INPUT_SAME_AS_OUTPUT
END ENUM

' enum to specify the various mode
MACRO AMVP_MODE_enum=LONG
ENUM AMVP_MODE SINGULAR
    AMVP_MODE_WEAVE
    AMVP_MODE_BOBINTERLEAVED
    AMVP_MODE_BOBNONINTERLEAVED
    AMVP_MODE_SKIPEVEN
    AMVP_MODE_SKIPODD
END ENUM

' struct to specify the width and height. The context could be anything
' such as scaling cropping etc.
TYPE AMVPSIZE
    dwWidth  AS DWORD         ' the width
    dwHeight AS DWORD         ' the height
END TYPE

' struct to specify the dimensional characteristics of the input stream
TYPE AMVPDIMINFO_type
    dwFieldWidth  AS DWORD    ' Field height of the data
    dwFieldHeight AS DWORD    ' Field width of the data
    dwVBIWidth    AS DWORD    ' Width of the VBI data
    dwVBIHeight   AS DWORD    ' Height of the VBI data
    rcValidRegion AS RECT     ' The vaild rectangle, used for cropping
END TYPE

' struct to specify the various data specific characteristics of the input stream
TYPE AMVPDATAINFO
    dwSize                 AS DWORD             ' Size of the struct
    dwMicrosecondsPerField AS DWORD             ' Time taken by each field
    amvpDimInfo            AS AMVPDIMINFO_type  ' Dimensional Information
    dwPictAspectRatioX     AS DWORD             ' X dimension of Picture Aspect Ratio
    dwPictAspectRatioY     AS DWORD             ' Y dimension of Picture Aspect Ratio
    bEnableDoubleClock     AS LONG  ' BOOL      ' Videoport should enable double clocking
    bEnableVACT            AS LONG  ' BOOL      ' Videoport should use an external VACT signal
    bDataIsInterlaced      AS LONG  ' BOOL      ' Indicates that the signal is interlaced
    lHalfLinesOdd          AS LONG              ' number of halflines in the odd field
    bFieldPolarityInverted AS LONG  ' BOOL      ' Device inverts the polarity by default
    dwNumLinesInVREF       AS DWORD             ' Number of lines of data in VREF
    lHalfLinesEven         AS LONG              ' number of halflines in the even field
    dwReserved1            AS DWORD             ' Reserved for future use
END TYPE
