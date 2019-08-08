'------------------------------------------------------------------------------
'
'  WinPerf.inc -- Header file for the Performance Monitor data.
'
'  Copyright (c) 1997-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from WinPerf.h dated 14 Jul 2009
'------------------------------------------------------------------------------
'
'   This file contains the definitions of the data structures returned
'   by the Configuration Registry in response to a request for
'   performance data.  This file is used by both the Configuration
'   Registry and the Performance Monitor to define their interface.
'   The complete interface is described here, except for the name
'   of the node to query in the registry.  It is
'
'                  HKEY_PERFORMANCE_DATA.
'
'   By querying that node with a subkey of "Global" the caller will
'   retrieve the structures described here.
'
'   There is no need to RegOpenKey() the reserved handle HKEY_PERFORMANCE_DATA,
'   but the caller should RegCloseKey() the handle so that network transports
'   and drivers can be removed or installed (which cannot happen while
'   they are open for monitoring.)  Remote requests must first
'   RegConnectRegistry().

#INCLUDE THIS ONCE

%WINPERF = 1

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "WTypes.inc"

'  Data structure definitions.

'  In order for data to be returned through the Configuration Registry
'  in a system-independent fashion, it must be self-describing.

'  In the following, all offsets are in bytes.

'
'  Data is returned through the Configuration Registry in a
'  a data block which begins with a _PERF_DATA_BLOCK structure.
'

%PERF_DATA_VERSION  = 1
%PERF_DATA_REVISION = 1


TYPE PERF_DATA_BLOCK
    Signature        AS WSTRING * 4   ' Signature: Unicode "PERF"
    LittleEndian     AS DWORD         ' 0 = Big Endian, 1 = Little Endian
    Version          AS DWORD         ' Version of these data structures
                                      ' starting at 1
    Revision         AS DWORD         ' Revision of these data structures
                                      ' starting at 0 for each Version
    TotalByteLength  AS DWORD         ' Total length of data block
    HeaderLength     AS DWORD         ' Length of this structure
    NumObjectTypes   AS DWORD         ' Number of types of objects
                                      ' being reported
    DefaultObject    AS LONG          ' Object Title Index of default
                                      ' object to display when data from
                                      ' this system is retrieved (-1 =
                                      ' none, but this is not expected to
                                      ' be used)
    SysTime          AS SYSTEMTIME    ' Time at the system under
                                      ' measurement
    PerfTime         AS QUAD          ' Performance counter value
                                      ' at the system under measurement
    PerfFreq         AS QUAD          ' Performance counter frequency
                                      ' at the system under measurement
    PerfTime100nSec  AS QUAD          ' Performance counter time in 100 nsec
                                      ' units at the system under measurement
    SystemNameLength AS DWORD         ' Length of the system name
    SystemNameOffset AS DWORD         ' Offset, from beginning of this
                                      ' structure, to name of system
                                      ' being measured
END TYPE


'
'  The _PERF_DATA_BLOCK structure is followed by NumObjectTypes of
'  data sections, one for each type of object measured.  Each object
'  type section begins with a _PERF_OBJECT_TYPE structure.
'


TYPE PERF_OBJECT_TYPE
    TotalByteLength AS DWORD            ' Length of this object definition
                                        ' including this structure, the
                                        ' counter definitions, and the
                                        ' instance definitions and the
                                        ' counter blocks for each instance:
                                        ' This is the offset from this
                                        ' structure to the next object, if
                                        ' any
    DefinitionLength AS DWORD           ' Length of object definition,
                                        ' which includes this structure
                                        ' and the counter definition
                                        ' structures for this object: this
                                        ' is the offset of the first
                                        ' instance or of the counters
                                        ' for this object if there is
                                        ' no instance
    HeaderLength AS DWORD               ' Length of this structure: this
                                        ' is the offset to the first
                                        ' counter definition for this
                                        ' object
    ObjectNameTitleIndex AS DWORD
                                        ' Index to name in Title Database
#IF %DEF(%WIN64)
    ObjectNameTitle AS DWORD            ' Should use this as an offset
#ELSE
    ObjectNameTitle AS WSTRINGZ PTR     ' Initially NULL, for use by
                                        ' analysis program to point to
                                        ' retrieved title string
#ENDIF
    ObjectHelpTitleIndex AS DWORD
                                        ' Index to Help in Title Database
#IF %DEF(%WIN64)
    ObjectHelpTitle AS DWORD            ' Should use this as an offset
#ELSE
    ObjectHelpTitle AS WSTRINGZ PTR     ' Initially NULL, for use by
                                        ' analysis program to point to
                                        ' retrieved title string
#ENDIF
    DetailLevel AS DWORD                ' Object level of detail (for
                                        ' controlling display complexity);
                                        ' will be min of detail levels
                                        ' for all this object's counters
    NumCounters AS DWORD                ' Number of counters in each
                                        ' counter block (one counter
                                        ' block per instance)
    DefaultCounter AS LONG              ' Default counter to display when
                                        ' this object is selected, index
                                        ' starting at 0 (-1 = none, but
                                        ' this is not expected to be used)
    NumInstances AS LONG                ' Number of object instances
                                        ' for which counters are being
                                        ' returned from the system under
                                        ' measurement. If the object defined
                                        ' will never have any instance data
                                        ' structures (%PERF_INSTANCE_DEFINITION)
                                        ' then this value should be -1, if the
                                        ' object can have 0 or more instances,
                                        ' but has none present, then this
                                        ' should be 0, otherwise this field
                                        ' contains the number of instances of
                                        ' this counter.
    CodePage AS DWORD                   ' 0 if instance strings are in
                                        ' UNICODE, else the Code Page of
                                        ' the instance names
    PerfTime AS QUAD                    ' Sample Time in "Object" units
                                        '
    PerfFreq AS QUAD                    ' Frequency of "Object" units in
                                        ' counts per second.
END TYPE

%PERF_NO_INSTANCES         = -1  ' no instances (see NumInstances above)
'
' - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
'
'  %PERF_COUNTER_DEFINITION.CounterType field values
'
'
'        Counter ID Field Definition:
'
'   3      2        2    2    2        1        1    1
'   1      8        4    2    0        6        2    0    8                0
'  +--------+--------+----+----+--------+--------+----+----+----------------+
'  |Display |Calculation  |Time|Counter |        |Ctr |Size|                |
'  |Flags   |Modifiers    |Base|SubType |Reserved|Type|Fld |   Reserved     |
'  +--------+--------+----+----+--------+--------+----+----+----------------+
'
'
'  The counter type is the "or" of the following values as described below
'
'  select one of the following to indicate the counter's data size
'
%PERF_SIZE_DWORD         = &H00000000  ' 32 bit field
%PERF_SIZE_LARGE         = &H00000100  ' 64 bit field
%PERF_SIZE_ZERO          = &H00000200  ' for Zero Length fields
%PERF_SIZE_VARIABLE_LEN  = &H00000300  ' length is in CounterLength field
                                            '  of Counter Definition struct
'
'  select one of the following values to indicate the counter field usage
'
%PERF_TYPE_NUMBER        = &H00000000  ' a number (not a counter)
%PERF_TYPE_COUNTER       = &H00000400  ' an increasing numeric value
%PERF_TYPE_TEXT          = &H00000800  ' a text field
%PERF_TYPE_ZERO          = &H00000C00  ' displays a zero
'
'  If the %PERF_TYPE_NUMBER field was selected, then select one of the
'  following to describe the Number
'
%PERF_NUMBER_HEX         = &H00000000  ' display as HEX value
%PERF_NUMBER_DECIMAL     = &H00010000  ' display as a decimal integer
%PERF_NUMBER_DEC_1000    = &H00020000  ' display as a decimal/1000
'
'  If the %PERF_TYPE_COUNTER value was selected then select one of the
'  following to indicate the type of counter
'
%PERF_COUNTER_VALUE      = &H00000000  ' display counter value
%PERF_COUNTER_RATE       = &H00010000  ' divide ctr / delta time
%PERF_COUNTER_FRACTION   = &H00020000  ' divide ctr / base
%PERF_COUNTER_BASE       = &H00030000  ' base value used in fractions
%PERF_COUNTER_ELAPSED    = &H00040000  ' subtract counter from current time
%PERF_COUNTER_QUEUELEN   = &H00050000  ' Use Queuelen processing func.
%PERF_COUNTER_HISTOGRAM  = &H00060000  ' Counter begins or ends a histogram
%PERF_COUNTER_PRECISION  = &H00070000  ' divide ctr / private clock
'
'  If the %PERF_TYPE_TEXT value was selected, then select one of the
'  following to indicate the type of TEXT data.
'
%PERF_TEXT_UNICODE       = &H00000000  ' type of text in text field
%PERF_TEXT_ASCII         = &H00010000  ' ASCII using the CodePage field
'
'  Timer SubTypes
'
%PERF_TIMER_TICK         = &H00000000  ' use system perf. freq for base
%PERF_TIMER_100NS        = &H00100000  ' use 100 NS timer time base units
%PERF_OBJECT_TIMER       = &H00200000  ' use the object timer freq
'
'  Any types that have calculations performed can use one or more of
'  the following calculation modification flags listed here
'
%PERF_DELTA_COUNTER      = &H00400000  ' compute difference first
%PERF_DELTA_BASE         = &H00800000  ' compute base diff as well
%PERF_INVERSE_COUNTER    = &H01000000  ' show as 1.00-value (assumes:
%PERF_MULTI_COUNTER      = &H02000000  ' sum of multiple instances
'
'  Select one of the following values to indicate the display suffix (if any)
'
%PERF_DISPLAY_NO_SUFFIX  = &H00000000  ' no suffix
%PERF_DISPLAY_PER_SEC    = &H10000000  ' "/sec"
%PERF_DISPLAY_PERCENT    = &H20000000  ' "%"
%PERF_DISPLAY_SECONDS    = &H30000000  ' "secs"
%PERF_DISPLAY_NOSHOW     = &H40000000  ' value is not displayed
'
'  Predefined counter types
'

' 32-bit Counter.  Divide delta by delta time.  Display suffix: "/sec"
%PERF_COUNTER_COUNTER =      _
            (%PERF_SIZE_DWORD OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_RATE OR _
            %PERF_TIMER_TICK OR %PERF_DELTA_COUNTER OR %PERF_DISPLAY_PER_SEC)


' 64-bit Timer.  Divide delta by delta time.  Display suffix: "%"
%PERF_COUNTER_TIMER =        _
            (%PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_RATE OR _
            %PERF_TIMER_TICK OR %PERF_DELTA_COUNTER OR %PERF_DISPLAY_PERCENT)

' Queue Length Space-Time Product. Divide delta by delta time. No Display Suffix.
%PERF_COUNTER_QUEUELEN_TYPE = _
            (%PERF_SIZE_DWORD OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_QUEUELEN OR _
            %PERF_TIMER_TICK OR %PERF_DELTA_COUNTER OR %PERF_DISPLAY_NO_SUFFIX)

' Queue Length Space-Time Product. Divide delta by delta time. No Display Suffix.
%PERF_COUNTER_LARGE_QUEUELEN_TYPE = _
            (%PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_QUEUELEN OR _
            %PERF_TIMER_TICK OR %PERF_DELTA_COUNTER OR %PERF_DISPLAY_NO_SUFFIX)

' Queue Length Space-Time Product using 100 Ns timebase.
' Divide delta by delta time. No Display Suffix.
%PERF_COUNTER_100NS_QUEUELEN_TYPE = _
            (%PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_QUEUELEN OR _
            %PERF_TIMER_100NS OR %PERF_DELTA_COUNTER OR %PERF_DISPLAY_NO_SUFFIX)

' Queue Length Space-Time Product using Object specific timebase.
' Divide delta by delta time. No Display Suffix.
%PERF_COUNTER_OBJ_TIME_QUEUELEN_TYPE = _
            (%PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_QUEUELEN OR _
            %PERF_OBJECT_TIMER OR %PERF_DELTA_COUNTER OR %PERF_DISPLAY_NO_SUFFIX)

' 64-bit Counter.  Divide delta by delta time. Display Suffix: "/sec"
%PERF_COUNTER_BULK_COUNT =   _
            (%PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_RATE OR _
            %PERF_TIMER_TICK OR %PERF_DELTA_COUNTER OR %PERF_DISPLAY_PER_SEC)

' Indicates the counter is not a  counter but rather Unicode text Display as text.
%PERF_COUNTER_TEXT =         _
            (%PERF_SIZE_VARIABLE_LEN OR %PERF_TYPE_TEXT OR %PERF_TEXT_UNICODE OR _
            %PERF_DISPLAY_NO_SUFFIX)

' Indicates the data is a counter  which should not be
' time averaged on display (such as an error counter on a serial line)
' Display as is.  No Display Suffix.
%PERF_COUNTER_RAWCOUNT =     _
            (%PERF_SIZE_DWORD OR %PERF_TYPE_NUMBER OR %PERF_NUMBER_DECIMAL OR _
            %PERF_DISPLAY_NO_SUFFIX)

' Same as %PERF_COUNTER_RAWCOUNT except its size is a large integer
%PERF_COUNTER_LARGE_RAWCOUNT =     _
            (%PERF_SIZE_LARGE OR %PERF_TYPE_NUMBER OR %PERF_NUMBER_DECIMAL OR _
            %PERF_DISPLAY_NO_SUFFIX)

' Special case for RAWCOUNT that want to be displayed in hex
' Indicates the data is a counter  which should not be
' time averaged on display (such as an error counter on a serial line)
' Display as is.  No Display Suffix.
%PERF_COUNTER_RAWCOUNT_HEX =     _
            (%PERF_SIZE_DWORD OR %PERF_TYPE_NUMBER OR %PERF_NUMBER_HEX OR _
            %PERF_DISPLAY_NO_SUFFIX)

' Same as %PERF_COUNTER_RAWCOUNT_HEX except its size is a large integer
%PERF_COUNTER_LARGE_RAWCOUNT_HEX =     _
            (%PERF_SIZE_LARGE OR %PERF_TYPE_NUMBER OR %PERF_NUMBER_HEX OR _
            %PERF_DISPLAY_NO_SUFFIX)


' A count which is either 1 or 0 on each sampling interrupt (% busy)
' Divide delta by delta base. Display Suffix: "%"
%PERF_SAMPLE_FRACTION =      _
            (%PERF_SIZE_DWORD OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_FRACTION OR _
            %PERF_DELTA_COUNTER OR %PERF_DELTA_BASE OR %PERF_DISPLAY_PERCENT)

' A count which is sampled on each sampling interrupt (queue length)
' Divide delta by delta time. No Display Suffix.
%PERF_SAMPLE_COUNTER =       _
            (%PERF_SIZE_DWORD OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_RATE OR _
            %PERF_TIMER_TICK OR %PERF_DELTA_COUNTER OR %PERF_DISPLAY_NO_SUFFIX)

' A label: no data is associated with this counter (it has 0 length)
' Do not display.
%PERF_COUNTER_NODATA =       _
            (%PERF_SIZE_ZERO OR %PERF_DISPLAY_NOSHOW)

' 64-bit Timer inverse (e.g., idle is measured, but display busy %)
' Display 100 - delta divided by delta time.  Display suffix: "%"
%PERF_COUNTER_TIMER_INV =    _
            (%PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_RATE OR _
            %PERF_TIMER_TICK OR %PERF_DELTA_COUNTER OR %PERF_INVERSE_COUNTER OR _
            %PERF_DISPLAY_PERCENT)

' The divisor for a sample, used with the previous counter to form a
' sampled %.  You must check for >0 before dividing by this!  This
' counter will directly follow the  numerator counter.  It should not
' be displayed to the user.
%PERF_SAMPLE_BASE =          _
            (%PERF_SIZE_DWORD OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_BASE OR _
            %PERF_DISPLAY_NOSHOW OR _
            &H00000001)  ' for compatibility with pre-beta versions

' A timer which, when divided by an average base, produces a time
' in seconds which is the average time of some operation.  This
' timer times total operations, and  the base is the number of opera-
' tions.  Display Suffix: "sec"
%PERF_AVERAGE_TIMER =        _
            (%PERF_SIZE_DWORD OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_FRACTION OR _
            %PERF_DISPLAY_SECONDS)

' Used as the denominator in the computation of time or count
' averages.  Must directly follow the numerator counter.  Not dis-
' played to the user.
%PERF_AVERAGE_BASE =         _
            (%PERF_SIZE_DWORD OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_BASE OR _
            %PERF_DISPLAY_NOSHOW OR _
            &H00000002)  ' for compatibility with pre-beta versions


' A bulk count which, when divided (typically) by the number of
' operations, gives (typically) the number of bytes per operation.
' No Display Suffix.
%PERF_AVERAGE_BULK =         _
            (%PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_FRACTION  OR _
            %PERF_DISPLAY_NOSHOW)

' 64-bit Timer in object specific units. Display delta divided by
' delta time as returned in the object type header structure.  Display suffix: "%"
%PERF_OBJ_TIME_TIMER =  _
            (%PERF_SIZE_LARGE   OR %PERF_TYPE_COUNTER  OR %PERF_COUNTER_RATE OR _
             %PERF_OBJECT_TIMER OR %PERF_DELTA_COUNTER OR %PERF_DISPLAY_PERCENT)


' 64-bit Timer in 100 nsec units. Display delta divided by
' delta time.  Display suffix: "%"
%PERF_100NSEC_TIMER =        _
            (%PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_RATE OR _
            %PERF_TIMER_100NS OR %PERF_DELTA_COUNTER OR %PERF_DISPLAY_PERCENT)

' 64-bit Timer inverse (e.g., idle is measured, but display busy %)
' Display 100 - delta divided by delta time.  Display suffix: "%"
%PERF_100NSEC_TIMER_INV =    _
            (%PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_RATE OR _
            %PERF_TIMER_100NS OR %PERF_DELTA_COUNTER OR %PERF_INVERSE_COUNTER  OR _
            %PERF_DISPLAY_PERCENT)

' 64-bit Timer.  Divide delta by delta time.  Display suffix: "%"
' Timer for multiple instances, so result can exceed 100%.
%PERF_COUNTER_MULTI_TIMER =  _
            (%PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_RATE OR _
            %PERF_DELTA_COUNTER OR %PERF_TIMER_TICK OR %PERF_MULTI_COUNTER OR _
            %PERF_DISPLAY_PERCENT)

' 64-bit Timer inverse (e.g., idle is measured, but display busy %)
' Display 100 * _MULTI_BASE - delta divided by delta time.
' Display suffix: "%" Timer for multiple instances, so result
' can exceed 100%.  Followed by a counter of type _MULTI_BASE.
%PERF_COUNTER_MULTI_TIMER_INV = _
            (%PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_RATE OR _
            %PERF_DELTA_COUNTER OR %PERF_MULTI_COUNTER OR %PERF_TIMER_TICK OR _
            %PERF_INVERSE_COUNTER OR %PERF_DISPLAY_PERCENT)

' Number of instances to which the preceding _MULTI_..._INV counter
' applies.  Used as a factor to get the percentage.
%PERF_COUNTER_MULTI_BASE =   _
            (%PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_BASE OR _
            %PERF_MULTI_COUNTER OR %PERF_DISPLAY_NOSHOW)

' 64-bit Timer in 100 nsec units. Display delta divided by delta time.
' Display suffix: "%" Timer for multiple instances, so result can exceed 100%.
%PERF_100NSEC_MULTI_TIMER = _
            (%PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_DELTA_COUNTER  OR _
            %PERF_COUNTER_RATE OR %PERF_TIMER_100NS OR %PERF_MULTI_COUNTER OR _
            %PERF_DISPLAY_PERCENT)

' 64-bit Timer inverse (e.g., idle is measured, but display busy %)
' Display 100 * _MULTI_BASE - delta divided by delta time.
' Display suffix: "%" Timer for multiple instances, so result
' can exceed 100%.  Followed by a counter of type _MULTI_BASE.
%PERF_100NSEC_MULTI_TIMER_INV = _
            (%PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_DELTA_COUNTER  OR _
            %PERF_COUNTER_RATE OR %PERF_TIMER_100NS OR %PERF_MULTI_COUNTER OR _
            %PERF_INVERSE_COUNTER OR %PERF_DISPLAY_PERCENT)

' Indicates the data is a fraction of the following counter  which
' should not be time averaged on display (such as free space over
' total space.) Display as is.  Display the quotient as "%".
%PERF_RAW_FRACTION =         _
            (%PERF_SIZE_DWORD OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_FRACTION OR _
            %PERF_DISPLAY_PERCENT)

%PERF_LARGE_RAW_FRACTION =         _
            (%PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_FRACTION OR _
            %PERF_DISPLAY_PERCENT)

' Indicates the data is a base for the preceding counter which should
' not be time averaged on display (such as free space over total space.)
%PERF_RAW_BASE =             _
            (%PERF_SIZE_DWORD OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_BASE OR _
            %PERF_DISPLAY_NOSHOW OR _
            &H00000003)  ' for compatibility with pre-beta versions

%PERF_LARGE_RAW_BASE =             _
            (%PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_BASE OR _
            %PERF_DISPLAY_NOSHOW )

' The data collected in this counter is actually the start time of the
' item being measured. For display, this data is subtracted from the
' sample time to yield the elapsed time as the difference between the two.
' In the definition below, the PerfTime field of the Object contains
' the sample time as indicated by the %PERF_OBJECT_TIMER bit and the
' difference is scaled by the PerfFreq of the Object to convert the time
' units into seconds.
%PERF_ELAPSED_TIME =         _
            (%PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_ELAPSED OR _
            %PERF_OBJECT_TIMER OR %PERF_DISPLAY_SECONDS)
'
'  The following counter type can be used with the preceding types to
'  define a range of values to be displayed in a histogram.
'

%PERF_COUNTER_HISTOGRAM_TYPE = &H80000000???
                                        ' Counter begins or ends a histogram
'
'  This counter is used to display the difference from one sample
'  to the next. The counter value is a constantly increasing number
'  and the value displayed is the difference between the current
'  value and the previous value. Negative numbers are not allowed
'  which shouldn't be a problem as long as the counter value is
'  increasing or unchanged.
'
%PERF_COUNTER_DELTA =    _
            (%PERF_SIZE_DWORD OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_VALUE OR _
            %PERF_DELTA_COUNTER OR %PERF_DISPLAY_NO_SUFFIX)

%PERF_COUNTER_LARGE_DELTA =    _
            (%PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_VALUE OR _
            %PERF_DELTA_COUNTER OR %PERF_DISPLAY_NO_SUFFIX)
'
'  The precision counters are timers that consist of two counter values:
'      1) the count of elapsed time of the event being monitored
'      2) the "clock" time in the same units
'
'  the precition timers are used where the standard system timers are not
'  precise enough for accurate readings. It's assumed that the service
'  providing the data is also providing a timestamp at the same time which
'  will eliminate any error that may occur since some small and variable
'  time elapses between the time the system timestamp is captured and when
'  the data is collected from the performance DLL. Only in extreme cases
'  has this been observed to be problematic.
'
'  when using this type of timer, the definition of the
'      %PERF_PRECISION_TIMESTAMP counter must immediately follow the
'      definition of the %PERF_PRECISION_*_TIMER in the Object header
'
' The timer used has the same frequency as the System Performance Timer
%PERF_PRECISION_SYSTEM_TIMER = _
        (%PERF_SIZE_LARGE    OR %PERF_TYPE_COUNTER     OR %PERF_COUNTER_PRECISION    OR _
         %PERF_TIMER_TICK    OR %PERF_DELTA_COUNTER    OR %PERF_DISPLAY_PERCENT   )
'
' The timer used has the same frequency as the 100 NanoSecond Timer
%PERF_PRECISION_100NS_TIMER = _
        (%PERF_SIZE_LARGE    OR %PERF_TYPE_COUNTER     OR %PERF_COUNTER_PRECISION    OR _
         %PERF_TIMER_100NS   OR %PERF_DELTA_COUNTER    OR %PERF_DISPLAY_PERCENT   )
'
' The timer used is of the frequency specified in the Object header's
'  PerfFreq field (PerfTime is ignored)
%PERF_PRECISION_OBJECT_TIMER = _
        (%PERF_SIZE_LARGE    OR %PERF_TYPE_COUNTER     OR %PERF_COUNTER_PRECISION    OR _
         %PERF_OBJECT_TIMER  OR %PERF_DELTA_COUNTER    OR %PERF_DISPLAY_PERCENT   )
'
' This is the timestamp to use in the computation of the timer specified
' in the previous description block
%PERF_PRECISION_TIMESTAMP  = %PERF_LARGE_RAW_BASE
'
'  The following are used to determine the level of detail associated
'  with the counter.  The user will be setting the level of detail
'  that should be displayed at any given time.
'
'
%PERF_DETAIL_NOVICE        = 100 ' The uninformed can understand it
%PERF_DETAIL_ADVANCED      = 200 ' For the advanced user
%PERF_DETAIL_EXPERT        = 300 ' For the expert user
%PERF_DETAIL_WIZARD        = 400 ' For the system designer
'
'
'  There is one of the following for each of the
'  %PERF_OBJECT_TYPE.NumCounters.  The Unicode names in this structure MUST
'  come from a message file.
'
'
TYPE PERF_COUNTER_DEFINITION
    ByteLength AS DWORD                 ' Length in bytes of this structure
    CounterNameTitleIndex AS DWORD
                                        ' Index of Counter name into
                                        ' Title Database
#IF %DEF(%WIN64)
    CounterNameTitle AS DWORD
#ELSE
    CounterNameTitle AS WSTRINGZ PTR    ' Initially NULL, for use by
                                        ' analysis program to point to
                                        ' retrieved title string
#ENDIF
    CounterHelpTitleIndex AS DWORD
                                        ' Index of Counter Help into
                                        ' Title Database
#IF %DEF(%WIN64)
    CounterHelpTitle AS DWORD
#ELSE
    CounterHelpTitle AS WSTRINGZ PTR    ' Initially NULL, for use by
                                        ' analysis program to point to
                                        ' retrieved title string
#ENDIF
    DefaultScale AS LONG                ' Power of 10 by which to scale
                                        ' chart line if vertical axis is 100
                                        ' 0 ==> 1, 1 ==> 10, -1 ==>1/10, etc.
    DetailLevel AS DWORD                ' Counter level of detail (for
                                        ' controlling display complexity)
    CounterType AS DWORD                ' Type of counter
    CounterSize AS DWORD                ' Size of counter in bytes
    CounterOffset AS DWORD              ' Offset from the start of the
                                        ' %PERF_COUNTER_BLOCK to the first
                                        ' byte of this counter
END TYPE
'
'
'  If (%PERF_DATA_BLOCK.NumInstances >= 0) then there will be
'  %PERF_DATA_BLOCK.NumInstances of a (%PERF_INSTANCE_DEFINITION
'  followed by a %PERF_COUNTER_BLOCK followed by the counter data fields)
'  for each instance.
'
'  If (%PERF_DATA_BLOCK.NumInstances < 0) then the counter definition
'  strucutre above will be followed by only a %PERF_COUNTER_BLOCK and the
'  counter data for that COUNTER.
'

%PERF_NO_UNIQUE_ID = -1

TYPE PERF_INSTANCE_DEFINITION
    ByteLength AS DWORD                 ' Length in bytes of this structure,
                                        ' including the subsequent name
    ParentObjectTitleIndex AS DWORD
                                        ' Title Index to name of "parent"
                                        ' object (e.g., if thread, then
                                        ' process is parent object type);
                                        ' if logical drive, the physical
                                        ' drive is parent object type
    ParentObjectInstance AS DWORD
                                        ' Index to instance of parent object
                                        ' type which is the parent of this
                                        ' instance.
    UniqueID AS LONG                    ' A unique ID used instead of
                                        ' matching the name to identify
                                        ' this instance, -1 = none
    NameOffset AS DWORD                 ' Offset from beginning of
                                        ' this struct to the Unicode name
                                        ' of this instance
    NameLength AS DWORD                 ' Length in bytes of name; 0 = none
                                        ' this length includes the characters
                                        ' in the string plus the size of the
                                        ' terminating NULL char. It does not
                                        ' include any additional pad bytes to
                                        ' correct structure alignment
END TYPE
'
'  If .ParentObjectName is 0, there
'  is no parent-child hierarchy for this object type.  Otherwise,
'   the .ParentObjectInstance is an index, starting at 0, into the
'  instances reported for the parent object type.  It is only
'  meaningful if .ParentObjectName is not 0.  The purpose of all this
'  is to permit reporting/summation of object instances like threads
'  within processes, and logical drives within physical drives.
'
'
'  The %PERF_INSTANCE_DEFINITION will be followed by a %PERF_COUNTER_BLOCK.
'

TYPE PERF_COUNTER_BLOCK
    ByteLength AS DWORD         ' Length in bytes of this structure,
                                ' including the following counters
END TYPE

'
'  The %PERF_COUNTER_BLOCK is followed by %PERF_OBJECT_TYPE.NumCounters
'  number of counters.
'

'
' Support for New Extensible API starting with NT 5.0
'
%PERF_QUERY_OBJECTS      = &H80000000???
%PERF_QUERY_GLOBAL       = &H80000001???
%PERF_QUERY_COSTLY       = &H80000002???

'
'  function typedefs for extensible counter function prototypes
'
DECLARE FUNCTION PERF_PM_OPEN_PROC (lpwsz AS WSTRINGZ) AS DWORD

DECLARE FUNCTION PERF_PM_COLLECT_PROC (lpwsz AS WSTRINGZ, lpvoid AS ANY, _
    lpd1 AS DWORD, lpd2 AS DWORD) AS DWORD

DECLARE FUNCTION PERF_PM_CLOSE_PROC () AS DWORD

DECLARE FUNCTION PERF_PM_QUERY_PROC (lpd1 AS DWORD, lpvoid AS ANY, _
    lpd2 AS DWORD, lpd3 AS DWORD) AS DWORD


#IF (%WIN32_WINDOWS >= &H0501 OR %WIN32_WINNT >= &H0501 OR (%DEF(%NTDDI_VERSION) AND %NTDDI_VERSION >= %NTDDI_WINXP))
%MAX_PERF_OBJECTS_IN_QUERY_FUNCTION    = 64

'
' The following are the possible values for
' HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Perflib\EventLogLevel
' The default is WINPERF_LOG_NONE if the registry value is not defined.
' This should be adopted by all perfdlls to avoid flooding the application
' event log.
'

%WINPERF_LOG_NONE     = 0           ' No event reported
%WINPERF_LOG_USER     = 1           ' Report only errors
%WINPERF_LOG_DEBUG    = 2           ' Report debug errors as well
%WINPERF_LOG_VERBOSE  = 3           ' Report everything
#ELSE
%MAX_PERF_OBJECTS_IN_QUERY_FUNCTION    = 8
#ENDIF
