'------------------------------------------------------------------------------
'
'  Time.inc -- C time definitions
'
'  Copyright (C) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (C) Microsoft Corporation
'  All Rights Reserved.
'
'  Last Update: 31 Jan 2011
'
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%INC_TIME = 1

#IF NOT %DEF(%TIME_T_DEFINED)
MACRO time_t=LONG
%TIME_T_DEFINED = 1
#ENDIF

#IF NOT %DEF(%CLOCK_T_DEFINED)
MACRO clock_t=LONG
%CLOCK_T_DEFINED = 1
#ENDIF

#IF NOT %DEF(%SIZE_T_DEFINED)
MACRO size_t=DWORD
%SIZE_T_DEFINED = 1
#ENDIF


#IF NOT %DEF(%NULL)
%NULL = 0
#ENDIF


#IF NOT %DEF(%TM_DEFINED)
TYPE tm_type
    tm_sec   AS LONG     ' seconds after the minute (0..59)
    tm_min   AS LONG     ' minutes after the hour (0..59)
    tm_hour  AS LONG     ' hours since midnight (0..23)
    tm_mday  AS LONG     ' day of the month (1..31)
    tm_mon   AS LONG     ' months since January (0..11)
    tm_year  AS LONG     ' years since 1900
    tm_wday  AS LONG     ' days since Sunday (0..6)
    tm_yday  AS LONG     ' days since January 1 (0..365)
    tm_isdst AS LONG     ' daylight savings time flag
END TYPE
%TM_DEFINED = 1
#ENDIF


%CLOCKS_PER_SEC = 1000
