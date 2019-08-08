'------------------------------------------------------------------------------
'
'  LmAlert.inc -- structures for communication with the Alerter service.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from LmAlert.h build version 0003 of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%ALERT = 1

#INCLUDE "LmCons.inc"


'
' Function Prototypes
'

DECLARE FUNCTION NetAlertRaise LIB "NetApi32.dll" ALIAS "NetAlertRaise" ( _
    AlertType        AS WSTRINGZ, _
    Buffer           AS ANY, _  ' LPVOID
    BYVAL BufferSize AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetAlertRaiseEx LIB "NetApi32.dll" ALIAS "NetAlertRaiseEx" ( _
    AlertType              AS WSTRINGZ, _
    VariableInfo           AS ANY, _  ' LPVOID
    BYVAL VariableInfoSize AS DWORD, _
    ServiceName            AS WSTRINGZ _
    ) AS NET_API_STATUS


'
'  Data Structures
'

TYPE STD_ALERT
    alrt_timestamp   AS DWORD
    alrt_eventname   AS WSTRINGZ * %EVLEN + 1
    alrt_servicename AS WSTRINGZ * %SNLEN + 1
END TYPE

TYPE ADMIN_OTHER_INFO
    alrtad_errcode    AS DWORD
    alrtad_numstrings AS DWORD
END TYPE

TYPE ERRLOG_OTHER_INFO
    alrter_errcode AS DWORD
    alrter_offset  AS DWORD
END TYPE

TYPE PRINT_OTHER_INFO
    alrtpr_jobid     AS DWORD
    alrtpr_status    AS DWORD
    alrtpr_submitted AS DWORD
    alrtpr_size      AS DWORD
END TYPE

TYPE USER_OTHER_INFO
    alrtus_errcode    AS DWORD
    alrtus_numstrings AS DWORD
END TYPE

'
' Special Values and Constants
'

'
' Name of mailslot to send alert notifications
'
$$ALERTER_MAILSLOT = "\\.\MAILSLOT\Alerter"$$

'
' The following macro gives a pointer to the other_info data.
' It takes an alert structure and returns a pointer to structure
' beyond the standard portion.
'

FUNCTION ALERT_OTHER_INFO (BYVAL x AS BYTE PTR) AS DWORD
    FUNCTION = x + SIZEOF(STD_ALERT)
END FUNCTION

'
' The following macro gives a pointer to the variable-length data.
' It takes a pointer to one of the other-info structs and returns a
' pointer to the variable data portion.
'

'#define ALERT_VAR_DATA(p)      ((LPBYTE)(p) + sizeof(*p))

'
'      Names of standard Microsoft-defined alert events.
'

$$ALERT_PRINT_EVENT        = "PRINTING"$$
$$ALERT_MESSAGE_EVENT      = "MESSAGE"$$
$$ALERT_ERRORLOG_EVENT     = "ERRORLOG"$$
$$ALERT_ADMIN_EVENT        = "ADMIN"$$
$$ALERT_USER_EVENT         = "USER"$$

'
'      Bitmap masks for prjob_status field of PRINTJOB.
'

' 2-7 bits also used in device status

%PRJOB_QSTATUS     = &H3         ' Bits 0,1
%PRJOB_DEVSTATUS   = &H1fc       ' 2-8 bits
%PRJOB_COMPLETE    = &H4         ' Bit 2
%PRJOB_INTERV      = &H8         ' Bit 3
%PRJOB_ERROR       = &H10        ' Bit 4
%PRJOB_DESTOFFLINE = &H20        ' Bit 5
%PRJOB_DESTPAUSED  = &H40        ' Bit 6
%PRJOB_NOTIFY      = &H80?       ' BIT 7
%PRJOB_DESTNOPAPER = &H100       ' BIT 8
%PRJOB_DELETED     = &H8000??    ' BIT 15

'
'      Values of PRJOB_QSTATUS bits in prjob_status field of PRINTJOB.
'

%PRJOB_QS_QUEUED   = 0
%PRJOB_QS_PAUSED   = 1
%PRJOB_QS_SPOOLING = 2
%PRJOB_QS_PRINTING = 3
