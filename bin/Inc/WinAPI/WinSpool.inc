'------------------------------------------------------------------------------
'
'  WinSpool.inc -- Header file for Print APIs
'
'  Copyright (c) 1997-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from WinSpool.h build version 0001 of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WINSPOOL = 1

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "WinError.inc"
#INCLUDE "WinGDI.inc"
#INCLUDE "WinNT.inc"

#IF %DEF(%WINUSER)
#INCLUDE "PrSht.inc"
#ENDIF


#IF NOT %DEF(%OSVERSION_MASK)

%OSVERSION_MASK    =  &HFFFF0000???
%SPVERSION_MASK    =  &H0000FF00
%SUBVERSION_MASK   =  &H000000FF

'
' macros to extract various version fields from the NTDDI version
'
'
' macros to extract various version fields from the NTDDI version
'
MACRO OSVER(Version)=((Version) AND %OSVERSION_MASK)

MACRO SPVER(Version)=(((Version) AND %SPVERSION_MASK) / 256)

MACRO SUBVER(Version)=((Version) AND %SUBVERSION_MASK)

#ENDIF   ' %OSVERSION_MASK


TYPE PRINTER_INFO_1A
    Flags        AS DWORD
    pDescription AS ASCIIZ PTR
    pName        AS ASCIIZ PTR
    pComment     AS ASCIIZ PTR
END TYPE

TYPE PRINTER_INFO_1W
    Flags        AS DWORD
    pDescription AS WSTRINGZ PTR
    pName        AS WSTRINGZ PTR
    pComment     AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE PRINTER_INFO_1
    PRINTER_INFO_1W
END TYPE
#ELSE
TYPE PRINTER_INFO_1
    PRINTER_INFO_1A
END TYPE
#ENDIF ' %UNICODE

TYPE PRINTER_INFO_2A
    pServerName         AS ASCIIZ PTR
    pPrinterName        AS ASCIIZ PTR
    pShareName          AS ASCIIZ PTR
    pPortName           AS ASCIIZ PTR
    pDriverName         AS ASCIIZ PTR
    pComment            AS ASCIIZ PTR
    pLocation           AS ASCIIZ PTR
    pDevMode            AS DEVMODEA PTR
    pSepFile            AS ASCIIZ PTR
    pPrintProcessor     AS ASCIIZ PTR
    pDatatype           AS ASCIIZ PTR
    pParameters         AS ASCIIZ PTR
    pSecurityDescriptor AS SECURITY_DESCRIPTOR PTR
    Attributes          AS DWORD
    PRIORITY            AS DWORD
    DefaultPriority     AS DWORD
    StartTime           AS DWORD
    UntilTime           AS DWORD
    STATUS              AS DWORD
    cJobs               AS DWORD
    AveragePPM          AS DWORD
END TYPE

TYPE PRINTER_INFO_2W
    pServerName         AS WSTRINGZ PTR
    pPrinterName        AS WSTRINGZ PTR
    pShareName          AS WSTRINGZ PTR
    pPortName           AS WSTRINGZ PTR
    pDriverName         AS WSTRINGZ PTR
    pComment            AS WSTRINGZ PTR
    pLocation           AS WSTRINGZ PTR
    pDevMode            AS DEVMODEW PTR
    pSepFile            AS WSTRINGZ PTR
    pPrintProcessor     AS WSTRINGZ PTR
    pDatatype           AS WSTRINGZ PTR
    pParameters         AS WSTRINGZ PTR
    pSecurityDescriptor AS SECURITY_DESCRIPTOR PTR
    Attributes          AS DWORD
    PRIORITY            AS DWORD
    DefaultPriority     AS DWORD
    StartTime           AS DWORD
    UntilTime           AS DWORD
    STATUS              AS DWORD
    cJobs               AS DWORD
    AveragePPM          AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE PRINTER_INFO_2
    PRINTER_INFO_2W
END TYPE
#ELSE
TYPE PRINTER_INFO_2
    PRINTER_INFO_2A
END TYPE
#ENDIF ' %UNICODE

TYPE PRINTER_INFO_3
    pSecurityDescriptor AS SECURITY_DESCRIPTOR PTR
END TYPE

TYPE PRINTER_INFO_4A
    pPrinterName AS ASCIIZ PTR
    pServerName  AS ASCIIZ PTR
    Attributes   AS DWORD
END TYPE

TYPE PRINTER_INFO_4W
    pPrinterName AS WSTRINGZ PTR
    pServerName  AS WSTRINGZ PTR
    Attributes   AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE PRINTER_INFO_4
    PRINTER_INFO_4W
END TYPE
#ELSE
TYPE PRINTER_INFO_4
    PRINTER_INFO_4A
END TYPE
#ENDIF ' %UNICODE

TYPE PRINTER_INFO_5A
    pPrinterName             AS ASCIIZ PTR
    pPortName                AS ASCIIZ PTR
    Attributes               AS DWORD
    DeviceNotSelectedTimeout AS DWORD
    TransmissionRetryTimeout AS DWORD
END TYPE

TYPE PRINTER_INFO_5W
    pPrinterName             AS WSTRINGZ PTR
    pPortName                AS WSTRINGZ PTR
    Attributes               AS DWORD
    DeviceNotSelectedTimeout AS DWORD
    TransmissionRetryTimeout AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE PRINTER_INFO_5
    PRINTER_INFO_5W
END TYPE
#ELSE
TYPE PRINTER_INFO_5
    PRINTER_INFO_5A
END TYPE
#ENDIF ' %UNICODE

TYPE PRINTER_INFO_6
    dwStatus AS DWORD
END TYPE


TYPE PRINTER_INFO_7A
    pszObjectGUID AS ASCIIZ PTR
    dwAction      AS DWORD
END TYPE

TYPE PRINTER_INFO_7W
    pszObjectGUID AS WSTRINGZ PTR
    dwAction      AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE PRINTER_INFO_7
    PRINTER_INFO_7W
END TYPE
#ELSE
TYPE PRINTER_INFO_7
    PRINTER_INFO_7A
END TYPE
#ENDIF ' %UNICODE

%DSPRINT_PUBLISH     = &H00000001
%DSPRINT_UPDATE      = &H00000002
%DSPRINT_UNPUBLISH   = &H00000004
%DSPRINT_REPUBLISH   = &H00000008
%DSPRINT_PENDING     = &H80000000???

TYPE PRINTER_INFO_8A
    pDevMode AS DEVMODEA PTR
END TYPE

TYPE PRINTER_INFO_8W
    pDevMode AS DEVMODEW PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE PRINTER_INFO_8
    PRINTER_INFO_8W
END TYPE
#ELSE
TYPE PRINTER_INFO_8
    PRINTER_INFO_8A
END TYPE
#ENDIF ' %UNICODE

TYPE PRINTER_INFO_9A
    pDevMode AS DEVMODEA PTR
END TYPE

TYPE PRINTER_INFO_9W
    pDevMode AS DEVMODEW PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE PRINTER_INFO_9
    PRINTER_INFO_9W
END TYPE
#ELSE
TYPE PRINTER_INFO_9
    PRINTER_INFO_9A
END TYPE
#ENDIF ' %UNICODE

%PRINTER_CONTROL_PAUSE          = 1
%PRINTER_CONTROL_RESUME         = 2
%PRINTER_CONTROL_PURGE          = 3
%PRINTER_CONTROL_SET_STATUS     = 4

%PRINTER_STATUS_PAUSED            =  &H00000001
%PRINTER_STATUS_ERROR             =  &H00000002
%PRINTER_STATUS_PENDING_DELETION  =  &H00000004
%PRINTER_STATUS_PAPER_JAM         =  &H00000008
%PRINTER_STATUS_PAPER_OUT         =  &H00000010
%PRINTER_STATUS_MANUAL_FEED       =  &H00000020
%PRINTER_STATUS_PAPER_PROBLEM     =  &H00000040
%PRINTER_STATUS_OFFLINE           =  &H00000080
%PRINTER_STATUS_IO_ACTIVE         =  &H00000100
%PRINTER_STATUS_BUSY              =  &H00000200
%PRINTER_STATUS_PRINTING          =  &H00000400
%PRINTER_STATUS_OUTPUT_BIN_FULL   =  &H00000800
%PRINTER_STATUS_NOT_AVAILABLE     =  &H00001000
%PRINTER_STATUS_WAITING           =  &H00002000
%PRINTER_STATUS_PROCESSING        =  &H00004000
%PRINTER_STATUS_INITIALIZING      =  &H00008000
%PRINTER_STATUS_WARMING_UP        =  &H00010000
%PRINTER_STATUS_TONER_LOW         =  &H00020000
%PRINTER_STATUS_NO_TONER          =  &H00040000
%PRINTER_STATUS_PAGE_PUNT         =  &H00080000
%PRINTER_STATUS_USER_INTERVENTION =  &H00100000
%PRINTER_STATUS_OUT_OF_MEMORY     =  &H00200000
%PRINTER_STATUS_DOOR_OPEN         =  &H00400000
%PRINTER_STATUS_SERVER_UNKNOWN    =  &H00800000
%PRINTER_STATUS_POWER_SAVE        =  &H01000000
%PRINTER_STATUS_SERVER_OFFLINE    =  &H02000000
%PRINTER_STATUS_DRIVER_UPDATE_NEEDED    =  &H04000000

%PRINTER_ATTRIBUTE_QUEUED         =  &H00000001
%PRINTER_ATTRIBUTE_DIRECT         =  &H00000002
%PRINTER_ATTRIBUTE_DEFAULT        =  &H00000004
%PRINTER_ATTRIBUTE_SHARED         =  &H00000008
%PRINTER_ATTRIBUTE_NETWORK        =  &H00000010
%PRINTER_ATTRIBUTE_HIDDEN         =  &H00000020
%PRINTER_ATTRIBUTE_LOCAL          =  &H00000040

%PRINTER_ATTRIBUTE_ENABLE_DEVQ       =  &H00000080
%PRINTER_ATTRIBUTE_KEEPPRINTEDJOBS   =  &H00000100
%PRINTER_ATTRIBUTE_DO_COMPLETE_FIRST =  &H00000200

%PRINTER_ATTRIBUTE_WORK_OFFLINE      =  &H00000400
%PRINTER_ATTRIBUTE_ENABLE_BIDI       =  &H00000800
%PRINTER_ATTRIBUTE_RAW_ONLY          =  &H00001000
%PRINTER_ATTRIBUTE_PUBLISHED         =  &H00002000

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
%PRINTER_ATTRIBUTE_FAX           =  &H00004000
#ENDIF ' (%NTDDI_VERSION >= NTDDI_WINXP)

#IF ((%NTDDI_VERSION >= %NTDDI_WS03) OR _
     ((OSVER(%NTDDI_VERSION) = %NTDDI_WIN2K) AND (SPVER(%NTDDI_VERSION) >= 4)))
%PRINTER_ATTRIBUTE_TS            =  &H00008000
#ENDIF ' ((%NTDDI_VERSION >= NTDDI_WS03) OR _ ...

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

'
' The printer attribute pushed xxx bits below are used by the
' pushing printer connection code to keep track of the type
' of printer connection.  These bits are per user resources
' hence the local print provider has no knowledge about these
' bit and will not accepts them.  The remote print provider
' is responsible for storeing and persisting these bits.
'
%PRINTER_ATTRIBUTE_PUSHED_USER     = &H00020000
%PRINTER_ATTRIBUTE_PUSHED_MACHINE  = &H00040000
%PRINTER_ATTRIBUTE_MACHINE         = &H00080000

%PRINTER_ATTRIBUTE_FRIENDLY_NAME   = &H00100000

'
' If the redirected TS printer is installed with generic
' TS printer driver (TSPRINT.dll) then this attribute is set
' by the UMRDP service and passed on to the spooler
'
%PRINTER_ATTRIBUTE_TS_GENERIC_DRIVER = &H00200000

#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)


%NO_PRIORITY  =  0
%MAX_PRIORITY = 99
%MIN_PRIORITY =  1
%DEF_PRIORITY =  1

TYPE JOB_INFO_1A
    JobId        AS DWORD
    pPrinterName AS ASCIIZ PTR
    pMachineName AS ASCIIZ PTR
    pUserName    AS ASCIIZ PTR
    pDocument    AS ASCIIZ PTR
    pDatatype    AS ASCIIZ PTR
    pStatus      AS ASCIIZ PTR
    STATUS       AS DWORD
    PRIORITY     AS DWORD
    Position     AS DWORD
    TotalPages   AS DWORD
    PagesPrinted AS DWORD
    Submitted    AS SYSTEMTIME
END TYPE

TYPE JOB_INFO_1W
    JobId        AS DWORD
    pPrinterName AS WSTRINGZ PTR
    pMachineName AS WSTRINGZ PTR
    pUserName    AS WSTRINGZ PTR
    pDocument    AS WSTRINGZ PTR
    pDatatype    AS WSTRINGZ PTR
    pStatus      AS WSTRINGZ PTR
    STATUS       AS DWORD
    PRIORITY     AS DWORD
    Position     AS DWORD
    TotalPages   AS DWORD
    PagesPrinted AS DWORD
    Submitted    AS SYSTEMTIME
END TYPE

#IF %DEF(%UNICODE)
TYPE JOB_INFO_1
    JOB_INFO_1W
END TYPE
#ELSE
TYPE JOB_INFO_1
    JOB_INFO_1A
END TYPE
#ENDIF ' %UNICODE

TYPE JOB_INFO_2A
    JobId               AS DWORD
    pPrinterName        AS ASCIIZ PTR
    pMachineName        AS ASCIIZ PTR
    pUserName           AS ASCIIZ PTR
    pDocument           AS ASCIIZ PTR
    pNotifyName         AS ASCIIZ PTR
    pDatatype           AS ASCIIZ PTR
    pPrintProcessor     AS ASCIIZ PTR
    pParameters         AS ASCIIZ PTR
    pDriverName         AS ASCIIZ PTR
    pDevMode            AS DEVMODEA PTR
    pStatus             AS ASCIIZ PTR
    pSecurityDescriptor AS SECURITY_DESCRIPTOR PTR
    STATUS              AS DWORD
    PRIORITY            AS DWORD
    Position            AS DWORD
    StartTime           AS DWORD
    UntilTime           AS DWORD
    TotalPages          AS DWORD
    SIZE                AS DWORD
    Submitted           AS SYSTEMTIME     ' Time the job was spooled
    Time                AS DWORD               ' How many miliseconds the job has been printing
    PagesPrinted        AS DWORD
END TYPE

TYPE JOB_INFO_2W
    JobId               AS DWORD
    pPrinterName        AS WSTRINGZ PTR
    pMachineName        AS WSTRINGZ PTR
    pUserName           AS WSTRINGZ PTR
    pDocument           AS WSTRINGZ PTR
    pNotifyName         AS WSTRINGZ PTR
    pDatatype           AS WSTRINGZ PTR
    pPrintProcessor     AS WSTRINGZ PTR
    pParameters         AS WSTRINGZ PTR
    pDriverName         AS WSTRINGZ PTR
    pDevMode            AS DEVMODEW PTR
    pStatus             AS WSTRINGZ PTR
    pSecurityDescriptor AS SECURITY_DESCRIPTOR PTR
    STATUS              AS DWORD
    PRIORITY            AS DWORD
    Position            AS DWORD
    StartTime           AS DWORD
    UntilTime           AS DWORD
    TotalPages          AS DWORD
    SIZE                AS DWORD
    Submitted           AS SYSTEMTIME     ' Time the job was spooled
    Time                AS DWORD               ' How many miliseconds the job has been printing
    PagesPrinted        AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE JOB_INFO_2
    JOB_INFO_2W
END TYPE
#ELSE
TYPE JOB_INFO_2
    JOB_INFO_2A
END TYPE
#ENDIF ' %UNICODE

TYPE JOB_INFO_3
    JobId     AS DWORD
    NextJobId AS DWORD
    Reserved  AS DWORD
END TYPE

TYPE JOB_INFO_4A
    JobId               AS DWORD
    pPrinterName        AS ASCIIZ PTR
    pMachineName        AS ASCIIZ PTR
    pUserName           AS ASCIIZ PTR
    pDocument           AS ASCIIZ PTR
    pNotifyName         AS ASCIIZ PTR
    pDatatype           AS ASCIIZ PTR
    pPrintProcessor     AS ASCIIZ PTR
    pParameters         AS ASCIIZ PTR
    pDriverName         AS ASCIIZ PTR
    pDevMode            AS DEVMODEA PTR
    pStatus             AS ASCIIZ PTR
    pSecurityDescriptor AS SECURITY_DESCRIPTOR PTR
    STATUS              AS DWORD
    PRIORITY            AS DWORD
    Position            AS DWORD
    StartTime           AS DWORD
    UntilTime           AS DWORD
    TotalPages          AS DWORD
    SIZE                AS DWORD
    Submitted           AS SYSTEMTIME
    Time                AS DWORD
    PagesPrinted        AS DWORD
    SizeHigh            AS LONG
END TYPE

TYPE JOB_INFO_4W
    JobId               AS DWORD
    pPrinterName        AS WSTRINGZ PTR
    pMachineName        AS WSTRINGZ PTR
    pUserName           AS WSTRINGZ PTR
    pDocument           AS WSTRINGZ PTR
    pNotifyName         AS WSTRINGZ PTR
    pDatatype           AS WSTRINGZ PTR
    pPrintProcessor     AS WSTRINGZ PTR
    pParameters         AS WSTRINGZ PTR
    pDriverName         AS WSTRINGZ PTR
    pDevMode            AS DEVMODEW PTR
    pStatus             AS WSTRINGZ PTR
    pSecurityDescriptor AS SECURITY_DESCRIPTOR PTR
    STATUS              AS DWORD
    PRIORITY            AS DWORD
    Position            AS DWORD
    StartTime           AS DWORD
    UntilTime           AS DWORD
    TotalPages          AS DWORD
    SIZE                AS DWORD
    Submitted           AS SYSTEMTIME
    Time                AS DWORD
    PagesPrinted        AS DWORD
    SizeHigh            AS LONG
END TYPE

#IF %DEF(%UNICODE)
TYPE JOB_INFO_4
    JOB_INFO_4W
END TYPE
#ELSE
TYPE JOB_INFO_4
    JOB_INFO_4A
END TYPE
#ENDIF ' %UNICODE

%JOB_CONTROL_PAUSE             = 1
%JOB_CONTROL_RESUME            = 2
%JOB_CONTROL_CANCEL            = 3
%JOB_CONTROL_RESTART           = 4
%JOB_CONTROL_DELETE            = 5
%JOB_CONTROL_SENT_TO_PRINTER   = 6
%JOB_CONTROL_LAST_PAGE_EJECTED = 7

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%JOB_CONTROL_RETAIN            = 8
%JOB_CONTROL_RELEASE           = 9
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)

%JOB_STATUS_PAUSED             = &H00000001
%JOB_STATUS_ERROR              = &H00000002
%JOB_STATUS_DELETING           = &H00000004
%JOB_STATUS_SPOOLING           = &H00000008
%JOB_STATUS_PRINTING           = &H00000010
%JOB_STATUS_OFFLINE            = &H00000020
%JOB_STATUS_PAPEROUT           = &H00000040
%JOB_STATUS_PRINTED            = &H00000080
%JOB_STATUS_DELETED            = &H00000100
%JOB_STATUS_BLOCKED_DEVQ       = &H00000200
%JOB_STATUS_USER_INTERVENTION  = &H00000400
%JOB_STATUS_RESTART            = &H00000800

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
%JOB_STATUS_COMPLETE           = &H00001000
#ENDIF ' (%NTDDI_VERSION >= NTDDI_WINXP)

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%JOB_STATUS_RETAINED           = &H00002000
%JOB_STATUS_RENDERING_LOCALLY  = &H00004000
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)

%JOB_POSITION_UNSPECIFIED     = 0

TYPE ADDJOB_INFO_1A
    PATH  AS ASCIIZ PTR
    JobId AS DWORD
END TYPE

TYPE ADDJOB_INFO_1W
    PATH  AS WSTRINGZ PTR
    JobId AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE ADDJOB_INFO_1
    ADDJOB_INFO_1W
END TYPE
#ELSE
TYPE ADDJOB_INFO_1
    ADDJOB_INFO_1A
END TYPE
#ENDIF ' %UNICODE


TYPE DRIVER_INFO_1A
    pName AS ASCIIZ PTR                   ' QMS 810
END TYPE

TYPE DRIVER_INFO_1W
    pName AS WSTRINGZ PTR                 ' QMS 810
END TYPE

#IF %DEF(%UNICODE)
TYPE DRIVER_INFO_1
    DRIVER_INFO_1W
END TYPE
#ELSE
TYPE DRIVER_INFO_1
    DRIVER_INFO_1A
END TYPE
#ENDIF ' %UNICODE

TYPE DRIVER_INFO_2A
    cVersion     AS DWORD
    pName        AS ASCIIZ PTR        ' QMS 810
    pEnvironment AS ASCIIZ PTR        ' Win32 x86
    pDriverPath  AS ASCIIZ PTR        ' c:\drivers\pscript.dll
    pDataFile    AS ASCIIZ PTR        ' c:\drivers\QMS810.PPD
    pConfigFile  AS ASCIIZ PTR        ' c:\drivers\PSCRPTUI.DLL
END TYPE

TYPE DRIVER_INFO_2W
    cVersion     AS DWORD
    pName        AS WSTRINGZ PTR      ' QMS 810
    pEnvironment AS WSTRINGZ PTR      ' Win32 x86
    pDriverPath  AS WSTRINGZ PTR      ' c:\drivers\pscript.dll
    pDataFile    AS WSTRINGZ PTR      ' c:\drivers\QMS810.PPD
    pConfigFile  AS WSTRINGZ PTR      ' c:\drivers\PSCRPTUI.DLL
END TYPE

#IF %DEF(%UNICODE)
TYPE DRIVER_INFO_2
    DRIVER_INFO_2W
END TYPE
#ELSE
TYPE DRIVER_INFO_2
    DRIVER_INFO_2A
END TYPE
#ENDIF ' %UNICODE

TYPE DRIVER_INFO_3A
    cVersion         AS DWORD
    pName            AS ASCIIZ PTR     ' QMS 810
    pEnvironment     AS ASCIIZ PTR     ' Win32 x86
    pDriverPath      AS ASCIIZ PTR     ' c:\drivers\pscript.dll
    pDataFile        AS ASCIIZ PTR     ' c:\drivers\QMS810.PPD
    pConfigFile      AS ASCIIZ PTR     ' c:\drivers\PSCRPTUI.DLL
    pHelpFile        AS ASCIIZ PTR     ' c:\drivers\PSCRPTUI.HLP
    pDependentFiles  AS ASCIIZ PTR     ' PSCRIPT.DLL\0QMS810.PPD\0PSCRIPTUI.DLL\0PSCRIPTUI.HLP\0PSTEST.TXT\0\0
    pMonitorName     AS ASCIIZ PTR     ' "PJL monitor"
    pDefaultDataType AS ASCIIZ PTR     ' "EMF"
END TYPE

TYPE DRIVER_INFO_3W
    cVersion         AS DWORD
    pName            AS WSTRINGZ PTR   ' QMS 810
    pEnvironment     AS WSTRINGZ PTR   ' Win32 x86
    pDriverPath      AS WSTRINGZ PTR   ' c:\drivers\pscript.dll
    pDataFile        AS WSTRINGZ PTR   ' c:\drivers\QMS810.PPD
    pConfigFile      AS WSTRINGZ PTR   ' c:\drivers\PSCRPTUI.DLL
    pHelpFile        AS WSTRINGZ PTR   ' c:\drivers\PSCRPTUI.HLP
    pDependentFiles  AS WSTRINGZ PTR   ' PSCRIPT.DLL\0QMS810.PPD\0PSCRIPTUI.DLL\0PSCRIPTUI.HLP\0PSTEST.TXT\0\0
    pMonitorName     AS WSTRINGZ PTR   ' "PJL monitor"
    pDefaultDataType AS WSTRINGZ PTR   ' "EMF"
END TYPE

#IF %DEF(%UNICODE)
TYPE DRIVER_INFO_3
    DRIVER_INFO_3W
END TYPE
#ELSE
TYPE DRIVER_INFO_3
    DRIVER_INFO_3A
END TYPE
#ENDIF ' %UNICODE

TYPE DRIVER_INFO_4A
    cVersion          AS DWORD
    pName             AS ASCIIZ PTR    ' QMS 810
    pEnvironment      AS ASCIIZ PTR    ' Win32 x86
    pDriverPath       AS ASCIIZ PTR    ' c:\drivers\pscript.dll
    pDataFile         AS ASCIIZ PTR    ' c:\drivers\QMS810.PPD
    pConfigFile       AS ASCIIZ PTR    ' c:\drivers\PSCRPTUI.DLL
    pHelpFile         AS ASCIIZ PTR    ' c:\drivers\PSCRPTUI.HLP
    pDependentFiles   AS ASCIIZ PTR    ' PSCRIPT.DLL\0QMS810.PPD\0PSCRIPTUI.DLL\0PSCRIPTUI.HLP\0PSTEST.TXT\0\0
    pMonitorName      AS ASCIIZ PTR    ' "PJL monitor"
    pDefaultDataType  AS ASCIIZ PTR    ' "EMF"
    pszzPreviousNames AS ASCIIZ PTR    ' "OldName1\0OldName2\0\0
END TYPE

TYPE DRIVER_INFO_4W
    cVersion          AS DWORD
    pName             AS WSTRINGZ PTR  ' QMS 810
    pEnvironment      AS WSTRINGZ PTR  ' Win32 x86
    pDriverPath       AS WSTRINGZ PTR  ' c:\drivers\pscript.dll
    pDataFile         AS WSTRINGZ PTR  ' c:\drivers\QMS810.PPD
    pConfigFile       AS WSTRINGZ PTR  ' c:\drivers\PSCRPTUI.DLL
    pHelpFile         AS WSTRINGZ PTR  ' c:\drivers\PSCRPTUI.HLP
    pDependentFiles   AS WSTRINGZ PTR  ' PSCRIPT.DLL\0QMS810.PPD\0PSCRIPTUI.DLL\0PSCRIPTUI.HLP\0PSTEST.TXT\0\0
    pMonitorName      AS WSTRINGZ PTR  ' "PJL monitor"
    pDefaultDataType  AS WSTRINGZ PTR  ' "EMF"
    pszzPreviousNames AS WSTRINGZ PTR  ' "OldName1\0OldName2\0\0
END TYPE

#IF %DEF(%UNICODE)
TYPE DRIVER_INFO_4
    DRIVER_INFO_4W
END TYPE
#ELSE
TYPE DRIVER_INFO_4
    DRIVER_INFO_4A
END TYPE
#ENDIF ' %UNICODE

TYPE DRIVER_INFO_5A
    cVersion           AS DWORD
    pName              AS ASCIIZ PTR      ' QMS 810
    pEnvironment       AS ASCIIZ PTR      ' Win32 x86
    pDriverPath        AS ASCIIZ PTR      ' c:\drivers\pscript.dll
    pDataFile          AS ASCIIZ PTR      ' c:\drivers\QMS810.PPD
    pConfigFile        AS ASCIIZ PTR      ' c:\drivers\PSCRPTUI.DLL
    dwDriverAttributes AS DWORD           ' driver attributes (like UMPD/KMPD)
    dwConfigVersion    AS DWORD           ' version number of the config file since reboot
    dwDriverVersion    AS DWORD           ' version number of the driver file since reboot
END TYPE

TYPE DRIVER_INFO_5W
    cVersion           AS DWORD
    pName              AS WSTRINGZ PTR    ' QMS 810
    pEnvironment       AS WSTRINGZ PTR    ' Win32 x86
    pDriverPath        AS WSTRINGZ PTR    ' c:\drivers\pscript.dll
    pDataFile          AS WSTRINGZ PTR    ' c:\drivers\QMS810.PPD
    pConfigFile        AS WSTRINGZ PTR    ' c:\drivers\PSCRPTUI.DLL
    dwDriverAttributes AS DWORD           ' driver attributes (like UMPD/KMPD)
    dwConfigVersion    AS DWORD           ' version number of the config file since reboot
    dwDriverVersion    AS DWORD           ' version number of the driver file since reboot
END TYPE

#IF %DEF(%UNICODE)
TYPE DRIVER_INFO_5
    DRIVER_INFO_5W
END TYPE
#ELSE
TYPE DRIVER_INFO_5
    DRIVER_INFO_5A
END TYPE
#ENDIF ' %UNICODE

TYPE DRIVER_INFO_6A
    cVersion          AS DWORD
    pName             AS ASCIIZ PTR     ' QMS 810
    pEnvironment      AS ASCIIZ PTR     ' Win32 x86
    pDriverPath       AS ASCIIZ PTR     ' c:\drivers\pscript.dll
    pDataFile         AS ASCIIZ PTR     ' c:\drivers\QMS810.PPD
    pConfigFile       AS ASCIIZ PTR     ' c:\drivers\PSCRPTUI.DLL
    pHelpFile         AS ASCIIZ PTR     ' c:\drivers\PSCRPTUI.HLP
    pDependentFiles   AS ASCIIZ PTR     ' PSCRIPT.DLL\0QMS810.PPD\0PSCRIPTUI.DLL\0PSCRIPTUI.HLP\0PSTEST.TXT\0\0
    pMonitorName      AS ASCIIZ PTR     ' "PJL monitor"
    pDefaultDataType  AS ASCIIZ PTR     ' "EMF"
    pszzPreviousNames AS ASCIIZ PTR     ' "OldName1\0OldName2\0\0
    ftDriverDate      AS FILETIME
    dwlDriverVersion  AS QUAD           ' DWORDLONG
    pszMfgName        AS ASCIIZ PTR
    pszOEMUrl         AS ASCIIZ PTR
    pszHardwareID     AS ASCIIZ PTR
    pszProvider       AS ASCIIZ PTR
END TYPE

TYPE DRIVER_INFO_6W
    cVersion          AS DWORD
    pName             AS WSTRINGZ PTR   ' QMS 810
    pEnvironment      AS WSTRINGZ PTR   ' Win32 x86
    pDriverPath       AS WSTRINGZ PTR   ' c:\drivers\pscript.dll
    pDataFile         AS WSTRINGZ PTR   ' c:\drivers\QMS810.PPD
    pConfigFile       AS WSTRINGZ PTR   ' c:\drivers\PSCRPTUI.DLL
    pHelpFile         AS WSTRINGZ PTR   ' c:\drivers\PSCRPTUI.HLP
    pDependentFiles   AS WSTRINGZ PTR   ' PSCRIPT.DLL\0QMS810.PPD\0PSCRIPTUI.DLL\0PSCRIPTUI.HLP\0PSTEST.TXT\0\0
    pMonitorName      AS WSTRINGZ PTR   ' "PJL monitor"
    pDefaultDataType  AS WSTRINGZ PTR   ' "EMF"
    pszzPreviousNames AS WSTRINGZ PTR   ' "OldName1\0OldName2\0\0
    ftDriverDate      AS FILETIME
    dwlDriverVersion  AS QUAD           ' DWORDLONG
    pszMfgName        AS WSTRINGZ PTR
    pszOEMUrl         AS WSTRINGZ PTR
    pszHardwareID     AS WSTRINGZ PTR
    pszProvider       AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE DRIVER_INFO_6
    DRIVER_INFO_6W
END TYPE
#ELSE
TYPE DRIVER_INFO_6
    DRIVER_INFO_6A
END TYPE
#ENDIF ' %UNICODE

%PRINTER_DRIVER_PACKAGE_AWARE   = &H00000001
%PRINTER_DRIVER_SANDBOX_ENABLED = &H00000004

TYPE DRIVER_INFO_8A
    cVersion                    AS DWORD
    pName                       AS ASCIIZ PTR    ' QMS 810
    pEnvironment                AS ASCIIZ PTR    ' Win32 x86
    pDriverPath                 AS ASCIIZ PTR    ' c:\drivers\pscript.dll
    pDataFile                   AS ASCIIZ PTR    ' c:\drivers\QMS810.PPD
    pConfigFile                 AS ASCIIZ PTR    ' c:\drivers\PSCRPTUI.DLL
    pHelpFile                   AS ASCIIZ PTR    ' c:\drivers\PSCRPTUI.HLP
    pDependentFiles             AS ASCIIZ PTR    ' PSCRIPT.DLL\0QMS810.PPD\0PSCRIPTUI.DLL\0PSCRIPTUI.HLP\0PSTEST.TXT\0\0
    pMonitorName                AS ASCIIZ PTR    ' "PJL monitor"
    pDefaultDataType            AS ASCIIZ PTR    ' "EMF"
    pszzPreviousNames           AS ASCIIZ PTR    ' "OldName1\0OldName2\0\0
    ftDriverDate                AS FILETIME
    dwlDriverVersion            AS QUAD          ' DWORDLONG
    pszMfgName                  AS ASCIIZ PTR
    pszOEMUrl                   AS ASCIIZ PTR
    pszHardwareID               AS ASCIIZ PTR
    pszProvider                 AS ASCIIZ PTR
    pszPrintProcessor           AS ASCIIZ PTR
    pszVendorSetup              AS ASCIIZ PTR
    pszzColorProfiles           AS ASCIIZ PTR
    pszInfPath                  AS ASCIIZ PTR
    dwPrinterDriverAttributes   AS DWORD
    pszzCoreDriverDependencies  AS ASCIIZ PTR
    ftMinInboxDriverVerDate     AS FILETIME
    dwlMinInboxDriverVerVersion AS QUAD          ' DWORDLONG
END TYPE

TYPE DRIVER_INFO_8W
    cVersion                    AS DWORD
    pName                       AS WSTRINGZ PTR  ' QMS 810
    pEnvironment                AS WSTRINGZ PTR  ' Win32 x86
    pDriverPath                 AS WSTRINGZ PTR  ' c:\drivers\pscript.dll
    pDataFile                   AS WSTRINGZ PTR  ' c:\drivers\QMS810.PPD
    pConfigFile                 AS WSTRINGZ PTR  ' c:\drivers\PSCRPTUI.DLL
    pHelpFile                   AS WSTRINGZ PTR  ' c:\drivers\PSCRPTUI.HLP
    pDependentFiles             AS WSTRINGZ PTR  ' PSCRIPT.DLL\0QMS810.PPD\0PSCRIPTUI.DLL\0PSCRIPTUI.HLP\0PSTEST.TXT\0\0
    pMonitorName                AS WSTRINGZ PTR  ' "PJL monitor"
    pDefaultDataType            AS WSTRINGZ PTR  ' "EMF"
    pszzPreviousNames           AS WSTRINGZ PTR  ' "OldName1\0OldName2\0\0
    ftDriverDate                AS FILETIME
    dwlDriverVersion            AS QUAD          ' DWORDLONG
    pszMfgName                  AS WSTRINGZ PTR
    pszOEMUrl                   AS WSTRINGZ PTR
    pszHardwareID               AS WSTRINGZ PTR
    pszProvider                 AS WSTRINGZ PTR
    pszPrintProcessor           AS WSTRINGZ PTR
    pszVendorSetup              AS WSTRINGZ PTR
    pszzColorProfiles           AS WSTRINGZ PTR
    pszInfPath                  AS WSTRINGZ PTR
    dwPrinterDriverAttributes   AS DWORD
    pszzCoreDriverDependencies  AS WSTRINGZ PTR
    ftMinInboxDriverVerDate     AS FILETIME
    dwlMinInboxDriverVerVersion AS QUAD          ' DWORDLONG
END TYPE

#IF %DEF(%UNICODE)
TYPE DRIVER_INFO_8
    DRIVER_INFO_8W
END TYPE
#ELSE
TYPE DRIVER_INFO_8
    DRIVER_INFO_8A
END TYPE
#ENDIF ' %UNICODE


' FLAGS for dwDriverAttributes
%DRIVER_KERNELMODE              = &H00000001
%DRIVER_USERMODE                = &H00000002

' FLAGS for DeletePrinterDriverEx.
%DPD_DELETE_UNUSED_FILES        = &H00000001
%DPD_DELETE_SPECIFIC_VERSION    = &H00000002
%DPD_DELETE_ALL_FILES           = &H00000004

' FLAGS for AddPrinterDriverEx.
%APD_STRICT_UPGRADE             = &H00000001
%APD_STRICT_DOWNGRADE           = &H00000002
%APD_COPY_ALL_FILES             = &H00000004
%APD_COPY_NEW_FILES             = &H00000008

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
%APD_COPY_FROM_DIRECTORY        = &H00000010
#ENDIF ' (%NTDDI_VERSION >= NTDDI_WINXP)


' String for EnumPrinterDrivers. Used by Windows Update

TYPE DOC_INFO_1A
    pDocName    AS ASCIIZ PTR
    pOutputFile AS ASCIIZ PTR
    pDatatype   AS ASCIIZ PTR
END TYPE

TYPE DOC_INFO_1W
    pDocName    AS WSTRINGZ PTR
    pOutputFile AS WSTRINGZ PTR
    pDatatype   AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE DOC_INFO_1
    DOC_INFO_1W
END TYPE
#ELSE
TYPE DOC_INFO_1
    DOC_INFO_1A
END TYPE
#ENDIF ' %UNICODE

TYPE FORM_INFO_1A
    Flags         AS DWORD
    pName         AS ASCIIZ PTR
    SIZE          AS SIZEL
    ImageableArea AS RECTL
END TYPE

TYPE FORM_INFO_1W
    Flags         AS DWORD
    pName         AS WSTRINGZ PTR
    SIZE          AS SIZEL
    ImageableArea AS RECTL
END TYPE

#IF %DEF(%UNICODE)
TYPE FORM_INFO_1
    FORM_INFO_1W
END TYPE
#ELSE
TYPE FORM_INFO_1
    FORM_INFO_1A
END TYPE
#ENDIF ' %UNICODE

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%STRING_NONE     = &H00000001
%STRING_MUIDLL   = &H00000002
%STRING_LANGPAIR = &H00000004

%MAX_FORM_KEYWORD_LENGTH = 63+1

TYPE FORM_INFO_2A
    Flags         AS DWORD
    pName         AS ASCIIZ PTR
    SIZE          AS SIZEL
    ImageableArea AS RECTL
    pKeyword      AS ASCIIZ PTR
    StringType    AS DWORD
    pMuiDll       AS ASCIIZ PTR
    dwResourceId  AS DWORD
    pDisplayName  AS ASCIIZ PTR
    wLangId       AS WORD  ' LANGID
END TYPE

TYPE FORM_INFO_2W
    Flags         AS DWORD
    pName         AS WSTRINGZ PTR
    SIZE          AS SIZEL
    ImageableArea AS RECTL
    pKeyword      AS WSTRINGZ PTR
    StringType    AS DWORD
    pMuiDll       AS WSTRINGZ PTR
    dwResourceId  AS DWORD
    pDisplayName  AS WSTRINGZ PTR
    wLangId       AS WORD  ' LANGID
END TYPE

#IF %DEF(%UNICODE)
TYPE FORM_INFO_2
    FORM_INFO_2W
END TYPE
#ELSE
TYPE FORM_INFO_2
    FORM_INFO_2A
END TYPE
#ENDIF ' %UNICODE
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)

TYPE DOC_INFO_2A
    pDocName    AS ASCIIZ PTR
    pOutputFile AS ASCIIZ PTR
    pDatatype   AS ASCIIZ PTR
    dwMode      AS DWORD
    JobId       AS DWORD
END TYPE

TYPE DOC_INFO_2W
    pDocName    AS WSTRINGZ PTR
    pOutputFile AS WSTRINGZ PTR
    pDatatype   AS WSTRINGZ PTR
    dwMode      AS DWORD
    JobId       AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE DOC_INFO_2
    DOC_INFO_2W
END TYPE
#ELSE
TYPE DOC_INFO_2
    DOC_INFO_2A
END TYPE
#ENDIF ' %UNICODE

%DI_CHANNEL            = 1    ' start direct read/write channel,


%DI_READ_SPOOL_JOB     = 3

TYPE DOC_INFO_3A
    pDocName    AS ASCIIZ PTR
    pOutputFile AS ASCIIZ PTR
    pDatatype   AS ASCIIZ PTR
    dwFlags     AS DWORD
END TYPE

TYPE DOC_INFO_3W
    pDocName    AS WSTRINGZ PTR
    pOutputFile AS WSTRINGZ PTR
    pDatatype   AS WSTRINGZ PTR
    dwFlags     AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE DOC_INFO_3
    DOC_INFO_3W
END TYPE
#ELSE
TYPE DOC_INFO_3
    DOC_INFO_3A
END TYPE
#ENDIF ' %UNICODE

%DI_MEMORYMAP_WRITE = &H00000001

%FORM_USER     = &H00000000
%FORM_BUILTIN  = &H00000001
%FORM_PRINTER  = &H00000002

TYPE PRINTPROCESSOR_INFO_1A
    pName AS ASCIIZ PTR
END TYPE

TYPE PRINTPROCESSOR_INFO_1W
    pName AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE PRINTPROCESSOR_INFO_1
    PRINTPROCESSOR_INFO_1W
END TYPE
#ELSE
TYPE PRINTPROCESSOR_INFO_1
    PRINTPROCESSOR_INFO_1A
END TYPE
#ENDIF ' %UNICODE

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
TYPE PRINTPROCESSOR_CAPS_1
    dwLevel          AS DWORD
    dwNupOptions     AS DWORD
    dwPageOrderFlags AS DWORD
    dwNumberOfCopies AS DWORD
END TYPE

%NORMAL_PRINT          = &H00000000
%REVERSE_PRINT         = &H00000001
#ENDIF ' (%NTDDI_VERSION >= NTDDI_WINXP)

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
TYPE PRINTPROCESSOR_CAPS_2
    dwLevel               AS DWORD
    dwNupOptions          AS DWORD
    dwPageOrderFlags      AS DWORD
    dwNumberOfCopies      AS DWORD

    ' \PRINTPROCESSOR_CAPS_2 specific fields.
    dwDuplexHandlingCaps  AS DWORD
    dwNupDirectionCaps    AS DWORD
    dwNupBorderCaps       AS DWORD
    dwBookletHandlingCaps AS DWORD
    dwScalingCaps         AS DWORD
END TYPE

'Flags for dwNupDirectionCaps.
%PPCAPS_RIGHT_THEN_DOWN                 = &H00000001
%PPCAPS_DOWN_THEN_RIGHT                 = &H00000002
%PPCAPS_LEFT_THEN_DOWN                  = &H00000004
%PPCAPS_DOWN_THEN_LEFT                  = &H00000008

'dwNupBorderCaps
%PPCAPS_BORDER_PRINT                    = &H00000001

'dwBookletHandlingCaps
%PPCAPS_BOOKLET_EDGE                    = &H00000001

'dwDuplexHandlingCaps
' The below flag tells that print processor can flip page order within sheet
' while printing reverse duplex.
' e.g. Instead of playing pages in order 4,3,2,1,
'          print processor can play them 3,4,1,2
%PPCAPS_REVERSE_PAGES_FOR_REVERSE_DUPLEX = &H00000001
%PPCAPS_DONT_SEND_EXTRA_PAGES_FOR_DUPLEX = &H00000002

'dwScalingCaps
%PPCAPS_SQUARE_SCALING                  = &H00000001


#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)

TYPE PORT_INFO_1A
    pName AS ASCIIZ PTR
END TYPE

TYPE PORT_INFO_1W
    pName AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE PORT_INFO_1
    PORT_INFO_1W
END TYPE
#ELSE
TYPE PORT_INFO_1
    PORT_INFO_1A
END TYPE
#ENDIF ' %UNICODE

TYPE PORT_INFO_2A
    pPortName    AS ASCIIZ PTR
    pMonitorName AS ASCIIZ PTR
    pDescription AS ASCIIZ PTR
    fPortType    AS DWORD
    Reserved     AS DWORD
END TYPE

TYPE PORT_INFO_2W
    pPortName    AS WSTRINGZ PTR
    pMonitorName AS WSTRINGZ PTR
    pDescription AS WSTRINGZ PTR
    fPortType    AS DWORD
    Reserved     AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE PORT_INFO_2
    PORT_INFO_2W
END TYPE
#ELSE
TYPE PORT_INFO_2
    PORT_INFO_2A
END TYPE
#ENDIF ' %UNICODE

%PORT_TYPE_WRITE        = &H0001
%PORT_TYPE_READ         = &H0002
%PORT_TYPE_REDIRECTED   = &H0004
%PORT_TYPE_NET_ATTACHED = &H0008

TYPE PORT_INFO_3A
    dwStatus   AS DWORD
    pszStatus  AS ASCIIZ PTR
    dwSeverity AS DWORD
END TYPE

TYPE PORT_INFO_3W
    dwStatus   AS DWORD
    pszStatus  AS WSTRINGZ PTR
    dwSeverity AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE PORT_INFO_3
    PORT_INFO_3W
END TYPE
#ELSE
TYPE PORT_INFO_3
    PORT_INFO_3A
END TYPE
#ENDIF ' %UNICODE

%PORT_STATUS_TYPE_ERROR    = 1
%PORT_STATUS_TYPE_WARNING  = 2
%PORT_STATUS_TYPE_INFO     = 3

%PORT_STATUS_OFFLINE              =  1
%PORT_STATUS_PAPER_JAM            =  2
%PORT_STATUS_PAPER_OUT            =  3
%PORT_STATUS_OUTPUT_BIN_FULL      =  4
%PORT_STATUS_PAPER_PROBLEM        =  5
%PORT_STATUS_NO_TONER             =  6
%PORT_STATUS_DOOR_OPEN            =  7
%PORT_STATUS_USER_INTERVENTION    =  8
%PORT_STATUS_OUT_OF_MEMORY        =  9

%PORT_STATUS_TONER_LOW            = 10

%PORT_STATUS_WARMING_UP           = 11
%PORT_STATUS_POWER_SAVE           = 12


TYPE MONITOR_INFO_1A
    pName AS ASCIIZ PTR
END TYPE

TYPE MONITOR_INFO_1W
    pName AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE MONITOR_INFO_1
    MONITOR_INFO_1W
END TYPE
#ELSE
TYPE MONITOR_INFO_1
    MONITOR_INFO_1A
END TYPE
#ENDIF ' %UNICODE

TYPE MONITOR_INFO_2A
    pName        AS ASCIIZ PTR
    pEnvironment AS ASCIIZ PTR
    pDLLName     AS ASCIIZ PTR
END TYPE

TYPE MONITOR_INFO_2W
    pName        AS WSTRINGZ PTR
    pEnvironment AS WSTRINGZ PTR
    pDLLName     AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE MONITOR_INFO_2
    MONITOR_INFO_2W
END TYPE
#ELSE
TYPE MONITOR_INFO_2
    MONITOR_INFO_2A
END TYPE
#ENDIF ' %UNICODE

TYPE DATATYPES_INFO_1A
    pName AS ASCIIZ PTR
END TYPE

TYPE DATATYPES_INFO_1W
    pName AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE DATATYPES_INFO_1
    DATATYPES_INFO_1W
END TYPE
#ELSE
TYPE DATATYPES_INFO_1
    DATATYPES_INFO_1A
END TYPE
#ENDIF ' %UNICODE

TYPE PRINTER_DEFAULTSA
    pDatatype     AS ASCIIZ PTR
    pDevMode      AS DEVMODEA PTR
    DesiredAccess AS ACCESS_MASK
END TYPE

TYPE PRINTER_DEFAULTSW
    pDatatype     AS WSTRINGZ PTR
    pDevMode      AS DEVMODEW PTR
    DesiredAccess AS ACCESS_MASK
END TYPE

#IF %DEF(%UNICODE)
TYPE PRINTER_DEFAULTS
    PRINTER_DEFAULTSW
END TYPE
#ELSE
TYPE PRINTER_DEFAULTS
    PRINTER_DEFAULTSA
END TYPE
#ENDIF ' %UNICODE

TYPE PRINTER_ENUM_VALUESA
    pValueName  AS ASCIIZ PTR
    cbValueName AS DWORD
    dwType      AS DWORD
    pData       AS BYTE PTR
    cbData      AS DWORD
END TYPE

TYPE PRINTER_ENUM_VALUESW
    pValueName  AS WSTRINGZ PTR
    cbValueName AS DWORD
    dwType      AS DWORD
    pData       AS BYTE PTR
    cbData      AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE PRINTER_ENUM_VALUES
    PRINTER_ENUM_VALUESW
END TYPE
#ELSE
TYPE PRINTER_ENUM_VALUES
    PRINTER_ENUM_VALUESA
END TYPE
#ENDIF ' %UNICODE

DECLARE FUNCTION EnumPrintersA LIB "WinSpool.drv" ALIAS "EnumPrintersA" ( _
    BYVAL Flags        AS DWORD, _
    sName              AS ASCIIZ, _
    BYVAL Level        AS DWORD, _
    BYVAL pPrinterEnum AS BYTE PTR, _
    BYVAL cbBuf        AS DWORD, _
    pcbNeeded          AS DWORD, _
    pcReturned         AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION EnumPrintersW LIB "WinSpool.drv" ALIAS "EnumPrintersW" ( _
    BYVAL Flags        AS DWORD, _
    sName              AS WSTRINGZ, _
    BYVAL Level        AS DWORD, _
    BYVAL pPrinterEnum AS BYTE PTR, _
    BYVAL cbBuf        AS DWORD, _
    pcbNeeded          AS DWORD, _
    pcReturned         AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO EnumPrinters=EnumPrintersW
#ELSE
MACRO EnumPrinters=EnumPrintersA
#ENDIF ' NOT %UNICODE

%PRINTER_ENUM_DEFAULT     = &H00000001
%PRINTER_ENUM_LOCAL       = &H00000002
%PRINTER_ENUM_CONNECTIONS = &H00000004
%PRINTER_ENUM_FAVORITE    = &H00000004
%PRINTER_ENUM_NAME        = &H00000008
%PRINTER_ENUM_REMOTE      = &H00000010
%PRINTER_ENUM_SHARED      = &H00000020
%PRINTER_ENUM_NETWORK     = &H00000040


%PRINTER_ENUM_EXPAND      = &H00004000
%PRINTER_ENUM_CONTAINER   = &H00008000

%PRINTER_ENUM_ICONMASK    = &H00ff0000
%PRINTER_ENUM_ICON1       = &H00010000
%PRINTER_ENUM_ICON2       = &H00020000
%PRINTER_ENUM_ICON3       = &H00040000
%PRINTER_ENUM_ICON4       = &H00080000
%PRINTER_ENUM_ICON5       = &H00100000
%PRINTER_ENUM_ICON6       = &H00200000
%PRINTER_ENUM_ICON7       = &H00400000
%PRINTER_ENUM_ICON8       = &H00800000
%PRINTER_ENUM_HIDE        = &H01000000



%SPOOL_FILE_PERSISTENT    = &H00000001
%SPOOL_FILE_TEMPORARY     = &H00000002

DECLARE FUNCTION GetSpoolFileHandle LIB "WinSpool.drv" _
    ALIAS "GetSpoolFileHandle" ( _
    BYVAL hPrinter AS DWORD _  ' HANDLE
    ) AS DWORD  ' HANDLE

DECLARE FUNCTION CommitSpoolData LIB "WinSpool.drv" _
    ALIAS "CommitSpoolData" ( _
    BYVAL hPrinter   AS DWORD, _   ' HANDLE
    BYVAL hSpoolFile AS DWORD, _   ' HANDLE
    BYVAL cbCommit   AS DWORD _
    ) AS DWORD  ' HANDLE

DECLARE FUNCTION CloseSpoolFileHandle LIB "WinSpool.drv" _
    ALIAS "CloseSpoolFileHandle" ( _
    BYVAL hPrinter   AS DWORD, _  ' HANDLE
    BYVAL hSpoolFile AS DWORD _   ' HANDLE
    ) AS LONG  ' BOOL

DECLARE FUNCTION OpenPrinterA LIB "WinSpool.drv" ALIAS "OpenPrinterA" ( _
    pPrinterName AS ASCIIZ, _
    phPrinter    AS DWORD, _  ' HANDLE
    pDefault     AS PRINTER_DEFAULTSA _
    ) AS LONG  ' BOOL

DECLARE FUNCTION OpenPrinterW LIB "WinSpool.drv" ALIAS "OpenPrinterW" ( _
    pPrinterName AS WSTRINGZ, _
    phPrinter    AS DWORD, _  ' HANDLE
    pDefault     AS PRINTER_DEFAULTSW _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO OpenPrinter=OpenPrinterW
#ELSE
MACRO OpenPrinter=OpenPrinterA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION ResetPrinterA LIB "WinSpool.drv" ALIAS "ResetPrinterA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pDefault       AS PRINTER_DEFAULTSA _
    ) AS LONG  ' BOOL

DECLARE FUNCTION ResetPrinterW LIB "WinSpool.drv" ALIAS "ResetPrinterW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pDefault       AS PRINTER_DEFAULTSW _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO ResetPrinter=ResetPrinterW
#ELSE
MACRO ResetPrinter=ResetPrinterA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetJobA LIB "WinSpool.drv" ALIAS "SetJobA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL JobId    AS DWORD, _
    BYVAL Level    AS DWORD, _
    BYVAL pJob     AS BYTE PTR, _
    BYVAL COMMAND  AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetJobW LIB "WinSpool.drv" ALIAS "SetJobW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL JobId    AS DWORD, _
    BYVAL Level    AS DWORD, _
    BYVAL pJob     AS BYTE PTR, _
    BYVAL COMMAND  AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO SetJob=SetJobW
#ELSE
MACRO SetJob=SetJobA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetJobA LIB "WinSpool.drv" ALIAS "GetJobA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL JobId    AS DWORD, _
    BYVAL Level    AS DWORD, _
    BYVAL pJob     AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION GetJobW LIB "WinSpool.drv" ALIAS "GetJobW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL JobId    AS DWORD, _
    BYVAL Level    AS DWORD, _
    BYVAL pJob     AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO GetJob=GetJobW
#ELSE
MACRO GetJob=GetJobA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumJobsA LIB "WinSpool.drv" ALIAS "EnumJobsA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL FirstJob AS DWORD, _
    BYVAL NoJobs   AS DWORD, _
    BYVAL Level    AS DWORD, _
    BYVAL pJob     AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD, _
    pcReturned     AS DWORD  _
    ) AS LONG  ' BOOL

DECLARE FUNCTION EnumJobsW LIB "WinSpool.drv" ALIAS "EnumJobsW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL FirstJob AS DWORD, _
    BYVAL NoJobs   AS DWORD, _
    BYVAL Level    AS DWORD, _
    BYVAL pJob     AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD, _
    pcReturned     AS DWORD  _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO EnumJobs=EnumJobsW
#ELSE
MACRO EnumJobs=EnumJobsA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION AddPrinterA LIB "WinSpool.drv" ALIAS "AddPrinterA" ( _
    pName          AS ASCIIZ, _
    BYVAL Level    AS DWORD, _
    BYVAL pPrinter AS BYTE PTR _
    ) AS DWORD  ' HANDLE

DECLARE FUNCTION AddPrinterW LIB "WinSpool.drv" ALIAS "AddPrinterW" ( _
    pName          AS WSTRINGZ, _
    BYVAL Level    AS DWORD, _
    BYVAL pPrinter AS BYTE PTR _
    ) AS DWORD  ' HANDLE

#IF %DEF(%UNICODE)
MACRO AddPrinter=AddPrinterW
#ELSE
MACRO AddPrinter=AddPrinterA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DeletePrinter LIB "WinSpool.drv" ALIAS "DeletePrinter" ( _
    BYVAL hPrinter AS DWORD _  ' HANDLE
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetPrinterA LIB "WinSpool.drv" ALIAS "SetPrinterA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pPrinter AS BYTE PTR, _
    BYVAL COMMAND  AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetPrinterW LIB "WinSpool.drv" ALIAS "SetPrinterW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pPrinter AS BYTE PTR, _
    BYVAL COMMAND  AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO SetPrinter=SetPrinterW
#ELSE
MACRO SetPrinter=SetPrinterA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetPrinterA LIB "WinSpool.drv" ALIAS "GetPrinterA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pPrinter AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION GetPrinterW LIB "WinSpool.drv" ALIAS "GetPrinterW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pPrinter AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO GetPrinter=GetPrinterW
#ELSE
MACRO GetPrinter=GetPrinterA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION AddPrinterDriverA LIB "WinSpool.drv" _
    ALIAS "AddPrinterDriverA" ( _
    pName             AS ASCIIZ, _
    BYVAL Level       AS DWORD, _
    BYVAL pDriverInfo AS BYTE PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION AddPrinterDriverW LIB "WinSpool.drv" _
    ALIAS "AddPrinterDriverW" ( _
    pName             AS WSTRINGZ, _
    BYVAL Level       AS DWORD, _
    BYVAL pDriverInfo AS BYTE PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO AddPrinterDriver=AddPrinterDriverW
#ELSE
MACRO AddPrinterDriver=AddPrinterDriverA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION AddPrinterDriverExA LIB "WinSpool.drv" _
    ALIAS "AddPrinterDriverExA" ( _
    pName                 AS ASCIIZ, _
    BYVAL Level           AS DWORD, _
    BYVAL pDriverInfo     AS BYTE PTR, _
    BYVAL dwFileCopyFlags AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION AddPrinterDriverExW LIB "WinSpool.drv" _
    ALIAS "AddPrinterDriverExW" ( _
    pName                 AS WSTRINGZ, _
    BYVAL Level           AS DWORD, _
    BYVAL pDriverInfo     AS BYTE PTR, _
    BYVAL dwFileCopyFlags AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO AddPrinterDriverEx=AddPrinterDriverExW
#ELSE
MACRO AddPrinterDriverEx=AddPrinterDriverExA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumPrinterDriversA LIB "WinSpool.drv" _
    ALIAS "EnumPrinterDriversA" ( _
    pName             AS ASCIIZ, _
    pEnvironment      AS ASCIIZ, _
    BYVAL Level       AS DWORD, _
    BYVAL pDriverInfo AS BYTE PTR, _
    BYVAL cbBuf       AS DWORD, _
    pcbNeeded         AS DWORD, _
    pcReturned        AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION EnumPrinterDriversW LIB "WinSpool.drv" _
    ALIAS "EnumPrinterDriversW" ( _
    pName             AS WSTRINGZ, _
    pEnvironment      AS WSTRINGZ, _
    BYVAL Level       AS DWORD, _
    BYVAL pDriverInfo AS BYTE PTR, _
    BYVAL cbBuf       AS DWORD, _
    pcbNeeded         AS DWORD, _
    pcReturned        AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO EnumPrinterDrivers=EnumPrinterDriversW
#ELSE
MACRO EnumPrinterDrivers=EnumPrinterDriversA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetPrinterDriverA LIB "WinSpool.drv" _
    ALIAS "GetPrinterDriverA" ( _
    BYVAL hPrinter    AS DWORD, _  ' HANDLE
    pEnvironment      AS ASCIIZ, _
    BYVAL Level       AS DWORD, _
    BYVAL pDriverInfo AS BYTE PTR, _
    BYVAL cbBuf       AS DWORD, _
    pcbNeeded         AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION GetPrinterDriverW LIB "WinSpool.drv" _
    ALIAS "GetPrinterDriverW" ( _
    BYVAL hPrinter    AS DWORD, _  ' HANDLE
    pEnvironment      AS WSTRINGZ, _
    BYVAL Level       AS DWORD, _
    BYVAL pDriverInfo AS BYTE PTR, _
    BYVAL cbBuf       AS DWORD, _
    pcbNeeded         AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO GetPrinterDriver=GetPrinterDriverW
#ELSE
MACRO GetPrinterDriver=GetPrinterDriverA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetPrinterDriverDirectoryA LIB "WinSpool.drv" _
    ALIAS "GetPrinterDriverDirectoryA" ( _
    pName                  AS ASCIIZ, _
    pEnvironment           AS ASCIIZ, _
    BYVAL Level            AS DWORD, _
    BYVAL pDriverDirectory AS BYTE PTR, _
    BYVAL cbBuf            AS DWORD, _
    pcbNeeded              AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION GetPrinterDriverDirectoryW LIB "WinSpool.drv" _
    ALIAS "GetPrinterDriverDirectoryW" ( _
    pName                  AS WSTRINGZ, _
    pEnvironment           AS WSTRINGZ, _
    BYVAL Level            AS DWORD, _
    BYVAL pDriverDirectory AS BYTE PTR, _
    BYVAL cbBuf            AS DWORD, _
    pcbNeeded              AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO GetPrinterDriverDirectory=GetPrinterDriverDirectoryW
#ELSE
MACRO GetPrinterDriverDirectory=GetPrinterDriverDirectoryA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DeletePrinterDriverA LIB "WinSpool.drv" _
    ALIAS "DeletePrinterDriverA" ( _
    pName        AS ASCIIZ, _
    pEnvironment AS ASCIIZ, _
    pDriverName  AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION DeletePrinterDriverW LIB "WinSpool.drv" _
    ALIAS "DeletePrinterDriverW" ( _
    pName        AS WSTRINGZ, _
    pEnvironment AS WSTRINGZ, _
    pDriverName  AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO DeletePrinterDriver=DeletePrinterDriverW
#ELSE
MACRO DeletePrinterDriver=DeletePrinterDriverA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DeletePrinterDriverExA LIB "WinSpool.drv" _
    ALIAS "DeletePrinterDriverExA" ( _
    pName               AS ASCIIZ, _
    pEnvironment        AS ASCIIZ, _
    pDriverName         AS ASCIIZ, _
    BYVAL dwDeleteFlag  AS DWORD, _
    BYVAL dwVersionFlag AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION DeletePrinterDriverExW LIB "WinSpool.drv" _
    ALIAS "DeletePrinterDriverExW" ( _
    pName               AS WSTRINGZ, _
    pEnvironment        AS WSTRINGZ, _
    pDriverName         AS WSTRINGZ, _
    BYVAL dwDeleteFlag  AS DWORD, _
    BYVAL dwVersionFlag AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO DeletePrinterDriverEx=DeletePrinterDriverExW
#ELSE
MACRO DeletePrinterDriverEx=DeletePrinterDriverExA
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION AddPrintProcessorA LIB "WinSpool.drv" _
    ALIAS "AddPrintProcessorA" ( _
    pName               AS ASCIIZ, _
    pEnvironment        AS ASCIIZ, _
    pPathName           AS ASCIIZ, _
    pPrintProcessorName AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION AddPrintProcessorW LIB "WinSpool.drv" _
    ALIAS "AddPrintProcessorW" ( _
    pName               AS WSTRINGZ, _
    pEnvironment        AS WSTRINGZ, _
    pPathName           AS WSTRINGZ, _
    pPrintProcessorName AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO AddPrintProcessor=AddPrintProcessorW
#ELSE
MACRO AddPrintProcessor=AddPrintProcessorA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumPrintProcessorsA LIB "WinSpool.drv" _
    ALIAS "EnumPrintProcessorsA" ( _
    pName                     AS ASCIIZ, _
    pEnvironment              AS ASCIIZ, _
    BYVAL Level               AS DWORD, _
    BYVAL pPrintProcessorInfo AS BYTE PTR, _
    BYVAL cbBuf               AS DWORD, _
    pcbNeeded                 AS DWORD, _
    pcReturned                AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION EnumPrintProcessorsW LIB "WinSpool.drv" _
    ALIAS "EnumPrintProcessorsW" ( _
    pName                     AS WSTRINGZ, _
    pEnvironment              AS WSTRINGZ, _
    BYVAL Level               AS DWORD, _
    BYVAL pPrintProcessorInfo AS BYTE PTR, _
    BYVAL cbBuf               AS DWORD, _
    pcbNeeded                 AS DWORD, _
    pcReturned                AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO EnumPrintProcessors=EnumPrintProcessorsW
#ELSE
MACRO EnumPrintProcessors=EnumPrintProcessorsA
#ENDIF ' NOT %UNICODE



DECLARE FUNCTION GetPrintProcessorDirectoryA LIB "WinSpool.drv" _
    ALIAS "GetPrintProcessorDirectoryA" ( _
    pName                     AS ASCIIZ, _
    pEnvironment              AS ASCIIZ, _
    BYVAL Level               AS DWORD, _
    BYVAL pPrintProcessorInfo AS BYTE PTR, _
    BYVAL cbBuf               AS DWORD, _
    pcbNeeded                 AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION GetPrintProcessorDirectoryW LIB "WinSpool.drv" _
    ALIAS "GetPrintProcessorDirectoryW" ( _
    pName                     AS WSTRINGZ, _
    pEnvironment              AS WSTRINGZ, _
    BYVAL Level               AS DWORD, _
    BYVAL pPrintProcessorInfo AS BYTE PTR, _
    BYVAL cbBuf               AS DWORD, _
    pcbNeeded                 AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO GetPrintProcessorDirectory=GetPrintProcessorDirectoryW
#ELSE
MACRO GetPrintProcessorDirectory=GetPrintProcessorDirectoryA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumPrintProcessorDatatypesA LIB "WinSpool.drv" _
    ALIAS "EnumPrintProcessorDatatypesA" ( _
    pName               AS ASCIIZ, _
    pPrintProcessorName AS ASCIIZ, _
    BYVAL Level         AS DWORD, _
    BYVAL pDatatypes    AS BYTE PTR, _
    BYVAL cbBuf         AS DWORD, _
    pcbNeeded           AS DWORD, _
    pcReturned          AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION EnumPrintProcessorDatatypesW LIB "WinSpool.drv" _
    ALIAS "EnumPrintProcessorDatatypesW" ( _
    pName               AS WSTRINGZ, _
    pPrintProcessorName AS WSTRINGZ, _
    BYVAL Level         AS DWORD, _
    BYVAL pDatatypes    AS BYTE PTR, _
    BYVAL cbBuf         AS DWORD, _
    pcbNeeded           AS DWORD, _
    pcReturned          AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO EnumPrintProcessorDatatypes=EnumPrintProcessorDatatypesW
#ELSE
MACRO EnumPrintProcessorDatatypes=EnumPrintProcessorDatatypesA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DeletePrintProcessorA LIB "WinSpool.drv" _
    ALIAS "DeletePrintProcessorA" ( _
    pName               AS ASCIIZ, _
    pEnvironment        AS ASCIIZ, _
    pPrintProcessorName AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION DeletePrintProcessorW LIB "WinSpool.drv" _
    ALIAS "DeletePrintProcessorW" ( _
    pName               AS WSTRINGZ, _
    pEnvironment        AS WSTRINGZ, _
    pPrintProcessorName AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO DeletePrintProcessor=DeletePrintProcessorW
#ELSE
MACRO DeletePrintProcessor=DeletePrintProcessorA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION StartDocPrinterA LIB "WinSpool.drv" _
    ALIAS "StartDocPrinterA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pDocInfo AS BYTE PTR _
    ) AS DWORD

DECLARE FUNCTION StartDocPrinterW LIB "WinSpool.drv" _
    ALIAS "StartDocPrinterW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pDocInfo AS BYTE PTR _
    ) AS DWORD

#IF %DEF(%UNICODE)
MACRO StartDocPrinter=StartDocPrinterW
#ELSE
MACRO StartDocPrinter=StartDocPrinterA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION StartPagePrinter LIB "WinSpool.drv" _
    ALIAS "StartPagePrinter" ( _
    BYVAL hPrinter AS DWORD _  ' HANDLE
    ) AS LONG  ' BOOL

DECLARE FUNCTION WritePrinter LIB "WinSpool.drv" ALIAS "WritePrinter" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pBuf           AS ANY, _    ' LPVOID
    BYVAL cbBuf    AS DWORD, _
    pcWritten      AS DWORD _
    ) AS LONG  ' BOOL


DECLARE FUNCTION FlushPrinter LIB "WinSpool.drv" ALIAS "FlushPrinter" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pBuf           AS ANY, _    ' LPVOID
    BYVAL cbBuf    AS DWORD, _
    pcWritten      AS DWORD, _
    BYVAL cSleep   AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION EndPagePrinter LIB "WinSpool.drv" ALIAS "EndPagePrinter" ( _
    BYVAL hPrinter AS DWORD _  ' HANDLE
    ) AS LONG  ' BOOL

DECLARE FUNCTION AbortPrinter LIB "WinSpool.drv" ALIAS "AbortPrinter" ( _
    BYVAL hPrinter AS DWORD _  ' HANDLE
    ) AS LONG  ' BOOL

DECLARE FUNCTION ReadPrinter LIB "WinSpool.drv" ALIAS "ReadPrinter" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pBuf           AS ANY, _    ' LPVOID
    BYVAL cbBuf    AS DWORD, _
    pNoBytesRead   AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION EndDocPrinter LIB "WinSpool.drv" ALIAS "EndDocPrinter" ( _
    BYVAL hPrinter AS DWORD _  ' HANDLE
    ) AS LONG  ' BOOL

DECLARE FUNCTION AddJobA LIB "WinSpool.drv" ALIAS "AddJobA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pData    AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION AddJobW LIB "WinSpool.drv" ALIAS "AddJobW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pData    AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO AddJob=AddJobW
#ELSE
MACRO AddJob=AddJobA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION ScheduleJob LIB "WinSpool.drv" ALIAS "ScheduleJob" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL JobId    AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION PrinterProperties LIB "WinSpool.drv" _
    ALIAS "PrinterProperties" ( _
    BYVAL hWnd     AS DWORD, _  ' HWND
    BYVAL hPrinter AS DWORD _   ' HANDLE
    ) AS LONG  ' BOOL

DECLARE FUNCTION DocumentPropertiesA LIB "WinSpool.drv" _
    ALIAS "DocumentPropertiesA" ( _
    BYVAL hWnd     AS DWORD, _  ' HWND
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pDeviceName    AS ASCIIZ, _
    pDevModeOutput AS DEVMODEA, _
    pDevModeInput  AS DEVMODEA, _
    BYVAL fMode     AS DWORD _
    ) AS LONG

DECLARE FUNCTION DocumentPropertiesW LIB "WinSpool.drv" _
    ALIAS "DocumentPropertiesW" ( _
    BYVAL hWnd     AS DWORD, _  ' HWND
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pDeviceName    AS WSTRINGZ, _
    pDevModeOutput AS DEVMODEW, _
    pDevModeInput  AS DEVMODEW, _
    BYVAL fMode     AS DWORD _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO DocumentProperties=DocumentPropertiesW
#ELSE
MACRO DocumentProperties=DocumentPropertiesA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION AdvancedDocumentPropertiesA LIB "WinSpool.drv" _
    ALIAS "AdvancedDocumentPropertiesA" ( _
    BYVAL hWnd     AS DWORD, _  ' HWND
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pDeviceName    AS ASCIIZ, _
    pDevModeOutput AS DEVMODEA, _
    pDevModeInput  AS DEVMODEA _
    ) AS LONG

DECLARE FUNCTION AdvancedDocumentPropertiesW LIB "WinSpool.drv" _
    ALIAS "AdvancedDocumentPropertiesW" ( _
    BYVAL hWnd     AS DWORD, _  ' HWND
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pDeviceName    AS WSTRINGZ, _
    pDevModeOutput AS DEVMODEW, _
    pDevModeInput  AS DEVMODEW _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO AdvancedDocumentProperties=AdvancedDocumentPropertiesW
#ELSE
MACRO AdvancedDocumentProperties=AdvancedDocumentPropertiesA
#ENDIF ' NOT %UNICODE

#IF (%NTDDI_VERSION >= %NTDDI_WINXPSP1)
DECLARE FUNCTION ExtDeviceMode LIB "WinSpool.drv" ALIAS "ExtDeviceMode" ( _
    BYVAL hWnd     AS DWORD, _  ' HWND
    BYVAL hInst    AS DWORD, _  ' HANDLE
    pDevModeOutput AS DEVMODEA, _
    pDeviceName    AS ASCIIZ, _
    pPort          AS ASCIIZ, _
    pDevModeInput  AS DEVMODEA, _
    pProfile       AS ASCIIZ, _
    BYVAL fMode    AS DWORD _
    ) AS LONG

#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WINXPSP1)


DECLARE FUNCTION GetPrinterDataA LIB "WinSpool.drv" ALIAS "GetPrinterDataA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pValueName     AS ASCIIZ, _
    pType          AS DWORD, _
    BYVAL pData    AS BYTE PTR, _
    BYVAL nSize    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS DWORD

DECLARE FUNCTION GetPrinterDataW LIB "WinSpool.drv" ALIAS "GetPrinterDataW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pValueName     AS WSTRINGZ, _
    pType          AS DWORD, _
    BYVAL pData    AS BYTE PTR, _
    BYVAL nSize    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
MACRO GetPrinterData=GetPrinterDataW
#ELSE
MACRO GetPrinterData=GetPrinterDataA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetPrinterDataExA LIB "WinSpool.drv" _
    ALIAS "GetPrinterDataExA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pKeyName       AS ASCIIZ, _
    pValueName     AS ASCIIZ, _
    pType          AS DWORD, _
    BYVAL pData    AS BYTE PTR, _
    BYVAL nSize    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS DWORD

DECLARE FUNCTION GetPrinterDataExW LIB "WinSpool.drv" _
    ALIAS "GetPrinterDataExW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pKeyName       AS WSTRINGZ, _
    pValueName     AS WSTRINGZ, _
    pType          AS DWORD, _
    BYVAL pData    AS BYTE PTR, _
    BYVAL nSize    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
MACRO GetPrinterDataEx=GetPrinterDataExW
#ELSE
MACRO GetPrinterDataEx=GetPrinterDataExA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumPrinterDataA LIB "WinSpool.drv" _
    ALIAS "EnumPrinterDataA" ( _
    BYVAL hPrinter    AS DWORD, _  ' HANDLE
    BYVAL dwIndex     AS DWORD, _
    pValueName        AS ASCIIZ, _
    BYVAL cbValueName AS DWORD, _
    pcbValueName      AS DWORD, _
    pType             AS DWORD, _
    BYVAL pData       AS BYTE PTR, _
    BYVAL cbData      AS DWORD, _
    pcbData           AS DWORD _
    ) AS DWORD

DECLARE FUNCTION EnumPrinterDataW LIB "WinSpool.drv" _
    ALIAS "EnumPrinterDataW" ( _
    BYVAL hPrinter    AS DWORD, _  ' HANDLE
    BYVAL dwIndex     AS DWORD, _
    pValueName        AS WSTRINGZ, _
    BYVAL cbValueName AS DWORD, _
    pcbValueName      AS DWORD, _
    pType             AS DWORD, _
    BYVAL pData       AS BYTE PTR, _
    BYVAL cbData      AS DWORD, _
    pcbData           AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
MACRO EnumPrinterData=EnumPrinterDataW
#ELSE
MACRO EnumPrinterData=EnumPrinterDataA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumPrinterDataExA LIB "WinSpool.drv" _
    ALIAS "EnumPrinterDataExA" ( _
    BYVAL hPrinter     AS DWORD, _  ' HANDLE
    pKeyName           AS ASCIIZ, _
    BYVAL pEnumValues  AS BYTE PTR, _
    BYVAL cbEnumValues AS DWORD, _
    pcbEnumValues      AS DWORD, _
    pnEnumValues       AS DWORD _
    ) AS DWORD

DECLARE FUNCTION EnumPrinterDataExW LIB "WinSpool.drv" _
    ALIAS "EnumPrinterDataExW" ( _
    BYVAL hPrinter     AS DWORD, _  ' HANDLE
    pKeyName           AS WSTRINGZ, _
    BYVAL pEnumValues  AS BYTE PTR, _
    BYVAL cbEnumValues AS DWORD, _
    pcbEnumValues      AS DWORD, _
    pnEnumValues       AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
MACRO EnumPrinterDataEx=EnumPrinterDataExW
#ELSE
MACRO EnumPrinterDataEx=EnumPrinterDataExA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumPrinterKeyA LIB "WinSpool.drv" ALIAS "EnumPrinterKeyA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pKeyName       AS ASCIIZ, _
    pSubkey        AS ASCIIZ, _
    BYVAL cbSubkey AS DWORD, _
    pcbSubkey      AS DWORD _
    ) AS DWORD

DECLARE FUNCTION EnumPrinterKeyW LIB "WinSpool.drv" ALIAS "EnumPrinterKeyW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pKeyName       AS WSTRINGZ, _
    pSubkey        AS WSTRINGZ, _
    BYVAL cbSubkey AS DWORD, _
    pcbSubkey      AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
MACRO EnumPrinterKey=EnumPrinterKeyW
#ELSE
MACRO EnumPrinterKey=EnumPrinterKeyA
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION SetPrinterDataA LIB "WinSpool.drv" ALIAS "SetPrinterDataA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pValueName     AS ASCIIZ, _
    BYVAL TYPE     AS DWORD, _
    BYVAL pData    AS BYTE PTR, _
    BYVAL cbData   AS DWORD _
    ) AS DWORD

DECLARE FUNCTION SetPrinterDataW LIB "WinSpool.drv" ALIAS "SetPrinterDataW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pValueName     AS WSTRINGZ, _
    BYVAL TYPE     AS DWORD, _
    BYVAL pData    AS BYTE PTR, _
    BYVAL cbData   AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
MACRO SetPrinterData=SetPrinterDataW
#ELSE
MACRO SetPrinterData=SetPrinterDataA
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION SetPrinterDataExA LIB "WinSpool.drv" _
    ALIAS "SetPrinterDataExA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pKeyName       AS ASCIIZ, _
    pValueName     AS ASCIIZ, _
    BYVAL TYPE     AS DWORD, _
    BYVAL pData    AS BYTE PTR, _
    BYVAL cbData   AS DWORD _
    ) AS DWORD

DECLARE FUNCTION SetPrinterDataExW LIB "WinSpool.drv" _
    ALIAS "SetPrinterDataExW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pKeyName       AS WSTRINGZ, _
    pValueName     AS WSTRINGZ, _
    BYVAL TYPE     AS DWORD, _
    BYVAL pData    AS BYTE PTR, _
    BYVAL cbData   AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
MACRO SetPrinterDataEx=SetPrinterDataExW
#ELSE
MACRO SetPrinterDataEx=SetPrinterDataExA
#ENDIF ' NOT %UNICODE



DECLARE FUNCTION DeletePrinterDataA LIB "WinSpool.drv" _
    ALIAS "DeletePrinterDataA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pValueName     AS ASCIIZ _
    ) AS DWORD

DECLARE FUNCTION DeletePrinterDataW LIB "WinSpool.drv" _
    ALIAS "DeletePrinterDataW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pValueName     AS WSTRINGZ _
    ) AS DWORD

#IF %DEF(%UNICODE)
MACRO DeletePrinterData=DeletePrinterDataW
#ELSE
MACRO DeletePrinterData=DeletePrinterDataA
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION DeletePrinterDataExA LIB "WinSpool.drv" _
    ALIAS "DeletePrinterDataExA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pKeyName       AS ASCIIZ, _
    pValueName     AS ASCIIZ _
    ) AS DWORD

DECLARE FUNCTION DeletePrinterDataExW LIB "WinSpool.drv" _
    ALIAS "DeletePrinterDataExW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pKeyName       AS WSTRINGZ, _
    pValueName     AS WSTRINGZ _
    ) AS DWORD

#IF %DEF(%UNICODE)
MACRO DeletePrinterDataEx=DeletePrinterDataExW
#ELSE
MACRO DeletePrinterDataEx=DeletePrinterDataExA
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION DeletePrinterKeyA LIB "WinSpool.drv" _
    ALIAS "DeletePrinterKeyA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pKeyName       AS ASCIIZ _
    ) AS DWORD

DECLARE FUNCTION DeletePrinterKeyW LIB "WinSpool.drv" _
    ALIAS "DeletePrinterKeyW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pKeyName       AS WSTRINGZ _
    ) AS DWORD

#IF %DEF(%UNICODE)
MACRO DeletePrinterKey=DeletePrinterKeyW
#ELSE
MACRO DeletePrinterKey=DeletePrinterKeyA
#ENDIF ' NOT %UNICODE


%PRINTER_NOTIFY_TYPE = &H00
%JOB_NOTIFY_TYPE     = &H01
%SERVER_NOTIFY_TYPE  = &H02

%PRINTER_NOTIFY_FIELD_SERVER_NAME           = &H00
%PRINTER_NOTIFY_FIELD_PRINTER_NAME          = &H01
%PRINTER_NOTIFY_FIELD_SHARE_NAME            = &H02
%PRINTER_NOTIFY_FIELD_PORT_NAME             = &H03
%PRINTER_NOTIFY_FIELD_DRIVER_NAME           = &H04
%PRINTER_NOTIFY_FIELD_COMMENT               = &H05
%PRINTER_NOTIFY_FIELD_LOCATION              = &H06
%PRINTER_NOTIFY_FIELD_DEVMODE               = &H07
%PRINTER_NOTIFY_FIELD_SEPFILE               = &H08
%PRINTER_NOTIFY_FIELD_PRINT_PROCESSOR       = &H09
%PRINTER_NOTIFY_FIELD_PARAMETERS            = &H0A
%PRINTER_NOTIFY_FIELD_DATATYPE              = &H0B
%PRINTER_NOTIFY_FIELD_SECURITY_DESCRIPTOR   = &H0C
%PRINTER_NOTIFY_FIELD_ATTRIBUTES            = &H0D
%PRINTER_NOTIFY_FIELD_PRIORITY              = &H0E
%PRINTER_NOTIFY_FIELD_DEFAULT_PRIORITY      = &H0F
%PRINTER_NOTIFY_FIELD_START_TIME            = &H10
%PRINTER_NOTIFY_FIELD_UNTIL_TIME            = &H11
%PRINTER_NOTIFY_FIELD_STATUS                = &H12
%PRINTER_NOTIFY_FIELD_STATUS_STRING         = &H13
%PRINTER_NOTIFY_FIELD_CJOBS                 = &H14
%PRINTER_NOTIFY_FIELD_AVERAGE_PPM           = &H15
%PRINTER_NOTIFY_FIELD_TOTAL_PAGES           = &H16
%PRINTER_NOTIFY_FIELD_PAGES_PRINTED         = &H17
%PRINTER_NOTIFY_FIELD_TOTAL_BYTES           = &H18
%PRINTER_NOTIFY_FIELD_BYTES_PRINTED         = &H19
%PRINTER_NOTIFY_FIELD_OBJECT_GUID           = &H1A

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%PRINTER_NOTIFY_FIELD_FRIENDLY_NAME         = &H1B
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)

%JOB_NOTIFY_FIELD_PRINTER_NAME              = &H00
%JOB_NOTIFY_FIELD_MACHINE_NAME              = &H01
%JOB_NOTIFY_FIELD_PORT_NAME                 = &H02
%JOB_NOTIFY_FIELD_USER_NAME                 = &H03
%JOB_NOTIFY_FIELD_NOTIFY_NAME               = &H04
%JOB_NOTIFY_FIELD_DATATYPE                  = &H05
%JOB_NOTIFY_FIELD_PRINT_PROCESSOR           = &H06
%JOB_NOTIFY_FIELD_PARAMETERS                = &H07
%JOB_NOTIFY_FIELD_DRIVER_NAME               = &H08
%JOB_NOTIFY_FIELD_DEVMODE                   = &H09
%JOB_NOTIFY_FIELD_STATUS                    = &H0A
%JOB_NOTIFY_FIELD_STATUS_STRING             = &H0B
%JOB_NOTIFY_FIELD_SECURITY_DESCRIPTOR       = &H0C
%JOB_NOTIFY_FIELD_DOCUMENT                  = &H0D
%JOB_NOTIFY_FIELD_PRIORITY                  = &H0E
%JOB_NOTIFY_FIELD_POSITION                  = &H0F
%JOB_NOTIFY_FIELD_SUBMITTED                 = &H10
%JOB_NOTIFY_FIELD_START_TIME                = &H11
%JOB_NOTIFY_FIELD_UNTIL_TIME                = &H12
%JOB_NOTIFY_FIELD_TIME                      = &H13
%JOB_NOTIFY_FIELD_TOTAL_PAGES               = &H14
%JOB_NOTIFY_FIELD_PAGES_PRINTED             = &H15
%JOB_NOTIFY_FIELD_TOTAL_BYTES               = &H16
%JOB_NOTIFY_FIELD_BYTES_PRINTED             = &H17
%JOB_NOTIFY_FIELD_REMOTE_JOB_ID             = &H18

#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
%SERVER_NOTIFY_FIELD_PRINT_DRIVER_ISOLATION_GROUP  = &H00
#ENDIF


TYPE PRINTER_NOTIFY_OPTIONS_TYPE
    TYPE      AS WORD
    Reserved0 AS WORD
    Reserved1 AS DWORD
    Reserved2 AS DWORD
    COUNT     AS DWORD
    pFields   AS WORD PTR
END TYPE


%PRINTER_NOTIFY_OPTIONS_REFRESH= &H01

TYPE PRINTER_NOTIFY_OPTIONS
    Version AS DWORD
    Flags   AS DWORD
    COUNT   AS DWORD
    pTypes  AS PRINTER_NOTIFY_OPTIONS_TYPE PTR
END TYPE



%PRINTER_NOTIFY_INFO_DISCARDED     = &H01

TYPE PRINTER_NOTIFY_INFO_DATA_union_type1
    cbBuf AS DWORD
    pBuf  AS DWORD  ' LPVOID
END TYPE

UNION PRINTER_NOTIFY_INFO_DATA_union
    adwData(1) AS DWORD
    DATA       AS PRINTER_NOTIFY_INFO_DATA_union_type1
END UNION

TYPE PRINTER_NOTIFY_INFO_DATA
    TYPE       AS WORD
    FIELD      AS WORD
    Reserved   AS DWORD
    ID         AS DWORD
    NotifyData AS PRINTER_NOTIFY_INFO_DATA_union
END TYPE

TYPE PRINTER_NOTIFY_INFO
    Version  AS DWORD
    Flags    AS DWORD
    COUNT    AS DWORD
    aData(0) AS PRINTER_NOTIFY_INFO_DATA
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
TYPE BINARY_CONTAINER
    cbBuf AS DWORD
    pData AS BYTE PTR
END TYPE

UNION BIDI_DATA_union
    bData  AS LONG  ' BOOL
    iData  AS LONG
    sData  AS WSTRINGZ PTR
    fData  AS SINGLE
    biData AS BINARY_CONTAINER
END UNION

TYPE BIDI_DATA
    dwBidiType AS DWORD
    u          AS BIDI_DATA_union
END TYPE


TYPE BIDI_REQUEST_DATA
    dwReqNumber AS DWORD
    pSchema     AS WSTRINGZ PTR
    DATA        AS BIDI_DATA
END TYPE


TYPE BIDI_REQUEST_CONTAINER
    Version  AS DWORD
    Flags    AS DWORD
    COUNT    AS DWORD
    aData(0) AS BIDI_REQUEST_DATA
END TYPE

TYPE BIDI_RESPONSE_DATA
    dwResult    AS DWORD
    dwReqNumber AS DWORD
    pSchema     AS WSTRINGZ PTR
    DATA        AS BIDI_DATA
END TYPE

TYPE BIDI_RESPONSE_CONTAINER
    Version  AS DWORD
    Flags    AS DWORD
    COUNT    AS DWORD
    aData(0) AS BIDI_RESPONSE_DATA
END TYPE

$$BIDI_ACTION_ENUM_SCHEMA  = "EnumSchema"$$
$$BIDI_ACTION_GET          = "Get"$$
$$BIDI_ACTION_SET          = "Set"$$
$$BIDI_ACTION_GET_ALL      = "GetAll"$$

MACRO BIDI_TYPE_enum=LONG
ENUM BIDI_TYPE SINGULAR
    BIDI_NULL
    BIDI_INT
    BIDI_FLOAT
    BIDI_BOOL
    BIDI_STRING
    BIDI_TEXT
    BIDI_ENUM
    BIDI_BLOB
END ENUM

%BIDI_ACCESS_ADMINISTRATOR = &H1
%BIDI_ACCESS_USER          = &H2


'
'  Error code for bidi apis
'

%ERROR_BIDI_STATUS_OK              = 0
%ERROR_BIDI_NOT_SUPPORTED          = %ERROR_NOT_SUPPORTED

%ERROR_BIDI_ERROR_BASE = 13000
%ERROR_BIDI_STATUS_WARNING         = (%ERROR_BIDI_ERROR_BASE + 1)
%ERROR_BIDI_SCHEMA_READ_ONLY       = (%ERROR_BIDI_ERROR_BASE + 2)
%ERROR_BIDI_SERVER_OFFLINE         = (%ERROR_BIDI_ERROR_BASE + 3)
%ERROR_BIDI_DEVICE_OFFLINE         = (%ERROR_BIDI_ERROR_BASE + 4)
%ERROR_BIDI_SCHEMA_NOT_SUPPORTED   = (%ERROR_BIDI_ERROR_BASE + 5)

#ENDIF ' (%NTDDI_VERSION >= NTDDI_WINXP)

DECLARE FUNCTION WaitForPrinterChange LIB "WinSpool.drv" _
    ALIAS "WaitForPrinterChange" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Flags    AS DWORD _
    ) AS DWORD

DECLARE FUNCTION FindFirstPrinterChangeNotification LIB "WinSpool.drv" _
    ALIAS "FindFirstPrinterChangeNotification" ( _
    BYVAL hPrinter        AS DWORD, _  ' HANDLE
    BYVAL fdwFilter       AS DWORD, _
    BYVAL fdwOptions      AS DWORD, _
    pPrinterNotifyOptions AS ANY _  ' PVOID
    ) AS DWORD  ' HANDLE


DECLARE FUNCTION FindNextPrinterChangeNotification LIB "WinSpool.drv" _
    ALIAS "FindNextPrinterChangeNotification" ( _
    BYVAL hChange       AS DWORD, _  ' HANDLE
    pdwChange           AS DWORD, _
    pvReserved          AS ANY, _    ' LPVOID
    ppPrinterNotifyInfo AS ANY _     ' LPVOID *
    ) AS LONG  ' BOOL

DECLARE FUNCTION FreePrinterNotifyInfo LIB "WinSpool.drv" _
    ALIAS "FreePrinterNotifyInfo" ( _
    pPrinterNotifyInfo AS PRINTER_NOTIFY_INFO _
    ) AS LONG  ' BOOL

DECLARE FUNCTION FindClosePrinterChangeNotification LIB "WinSpool.drv" _
    ALIAS "FindClosePrinterChangeNotification" ( _
    BYVAL hChange AS DWORD _  ' HANDLE
    ) AS LONG  ' BOOL

%PRINTER_CHANGE_ADD_PRINTER            = &H00000001
%PRINTER_CHANGE_SET_PRINTER            = &H00000002
%PRINTER_CHANGE_DELETE_PRINTER         = &H00000004
%PRINTER_CHANGE_FAILED_CONNECTION_PRINTER  = &H00000008
%PRINTER_CHANGE_PRINTER                = &H000000FF
%PRINTER_CHANGE_ADD_JOB                = &H00000100
%PRINTER_CHANGE_SET_JOB                = &H00000200
%PRINTER_CHANGE_DELETE_JOB             = &H00000400
%PRINTER_CHANGE_WRITE_JOB              = &H00000800
%PRINTER_CHANGE_JOB                    = &H0000FF00
%PRINTER_CHANGE_ADD_FORM               = &H00010000
%PRINTER_CHANGE_SET_FORM               = &H00020000
%PRINTER_CHANGE_DELETE_FORM            = &H00040000
%PRINTER_CHANGE_FORM                   = &H00070000
%PRINTER_CHANGE_ADD_PORT               = &H00100000
%PRINTER_CHANGE_CONFIGURE_PORT         = &H00200000
%PRINTER_CHANGE_DELETE_PORT            = &H00400000
%PRINTER_CHANGE_PORT                   = &H00700000
%PRINTER_CHANGE_ADD_PRINT_PROCESSOR    = &H01000000
%PRINTER_CHANGE_DELETE_PRINT_PROCESSOR = &H04000000
%PRINTER_CHANGE_PRINT_PROCESSOR        = &H07000000
#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
%PRINTER_CHANGE_SERVER                 = &H08000000
#ENDIF
%PRINTER_CHANGE_ADD_PRINTER_DRIVER     = &H10000000
%PRINTER_CHANGE_SET_PRINTER_DRIVER     = &H20000000
%PRINTER_CHANGE_DELETE_PRINTER_DRIVER  = &H40000000
%PRINTER_CHANGE_PRINTER_DRIVER         = &H70000000
%PRINTER_CHANGE_TIMEOUT                = &H80000000???
%PRINTER_CHANGE_ALL                    = &H7777FFFF

DECLARE FUNCTION PrinterMessageBoxA LIB "WinSpool.drv" _
    ALIAS "PrinterMessageBoxA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL ERROR    AS DWORD, _
    BYVAL hWnd     AS DWORD, _  ' HWND
    pText          AS ASCIIZ, _
    pCaption       AS ASCIIZ, _
    BYVAL dwType   AS DWORD _
    ) AS DWORD

DECLARE FUNCTION PrinterMessageBoxW LIB "WinSpool.drv" _
    ALIAS "PrinterMessageBoxW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL ERROR    AS DWORD, _
    BYVAL hWnd     AS DWORD, _  ' HWND
    pText          AS WSTRINGZ, _
    pCaption       AS WSTRINGZ, _
    BYVAL dwType   AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
MACRO PrinterMessageBox=PrinterMessageBoxW
#ELSE
MACRO PrinterMessageBox=PrinterMessageBoxA
#ENDIF ' NOT %UNICODE



%PRINTER_ERROR_INFORMATION = &H80000000???
%PRINTER_ERROR_WARNING     = &H40000000
%PRINTER_ERROR_SEVERE      = &H20000000

%PRINTER_ERROR_OUTOFPAPER  = &H00000001
%PRINTER_ERROR_JAM         = &H00000002
%PRINTER_ERROR_OUTOFTONER  = &H00000004

DECLARE FUNCTION ClosePrinter LIB "WinSpool.drv" ALIAS "ClosePrinter" ( _
    BYVAL hPrinter AS DWORD _  ' HANDLE
    ) AS LONG  ' BOOL

DECLARE FUNCTION AddFormA LIB "WinSpool.drv" ALIAS "AddFormA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pForm    AS BYTE PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION AddFormW LIB "WinSpool.drv" ALIAS "AddFormW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pForm    AS BYTE PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO AddForm=AddFormW
#ELSE
MACRO AddForm=AddFormA
#ENDIF ' NOT %UNICODE



DECLARE FUNCTION DeleteFormA LIB "WinSpool.drv" ALIAS "DeleteFormA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pFormName      AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION DeleteFormW LIB "WinSpool.drv" ALIAS "DeleteFormW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pFormName      AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO DeleteForm=DeleteFormW
#ELSE
MACRO DeleteForm=DeleteFormA
#ENDIF ' NOT %UNICODE



DECLARE FUNCTION GetFormA LIB "WinSpool.drv" ALIAS "GetFormA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pFormName      AS ASCIIZ, _
    BYVAL Level    AS DWORD, _
    BYVAL pForm    AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION GetFormW LIB "WinSpool.drv" ALIAS "GetFormW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pFormName      AS WSTRINGZ, _
    BYVAL Level    AS DWORD, _
    BYVAL pForm    AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO GetForm=GetFormW
#ELSE
MACRO GetForm=GetFormA
#ENDIF ' NOT %UNICODE



DECLARE FUNCTION SetFormA LIB "WinSpool.drv" ALIAS "SetFormA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pFormName      AS ASCIIZ, _
    BYVAL Level    AS DWORD, _
    BYVAL pForm    AS BYTE PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetFormW LIB "WinSpool.drv" ALIAS "SetFormW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pFormName      AS WSTRINGZ, _
    BYVAL Level    AS DWORD, _
    BYVAL pForm    AS BYTE PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO SetForm=SetFormW
#ELSE
MACRO SetForm=SetFormA
#ENDIF ' NOT %UNICODE



DECLARE FUNCTION EnumFormsA LIB "WinSpool.drv" ALIAS "EnumFormsA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pForm    AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD, _
    pcReturned     AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION EnumFormsW LIB "WinSpool.drv" ALIAS "EnumFormsW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pForm    AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD, _
    pcReturned     AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO EnumForms=EnumFormsW
#ELSE
MACRO EnumForms=EnumFormsA
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION EnumMonitorsA LIB "WinSpool.drv" ALIAS "EnumMonitorsA" ( _
    pName          AS ASCIIZ, _
    BYVAL Level    AS DWORD, _
    BYVAL pMonitor AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD, _
    pcReturned     AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION EnumMonitorsW LIB "WinSpool.drv" ALIAS "EnumMonitorsW" ( _
    pName          AS WSTRINGZ, _
    BYVAL Level    AS DWORD, _
    BYVAL pMonitor AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD, _
    pcReturned     AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO EnumMonitors=EnumMonitorsW
#ELSE
MACRO EnumMonitors=EnumMonitorsA
#ENDIF ' NOT %UNICODE



DECLARE FUNCTION AddMonitorA LIB "WinSpool.drv" ALIAS "AddMonitorA" ( _
    pName           AS ASCIIZ, _
    BYVAL Level     AS DWORD, _
    BYVAL pMonitors AS BYTE PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION AddMonitorW LIB "WinSpool.drv" ALIAS "AddMonitorW" ( _
    pName           AS WSTRINGZ, _
    BYVAL Level     AS DWORD, _
    BYVAL pMonitors AS BYTE PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO AddMonitor=AddMonitorW
#ELSE
MACRO AddMonitor=AddMonitorA
#ENDIF ' NOT %UNICODE



DECLARE FUNCTION DeleteMonitorA LIB "WinSpool.drv" ALIAS "DeleteMonitorA" ( _
    pName        AS ASCIIZ, _
    pEnvironment AS ASCIIZ, _
    pMonitorName AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION DeleteMonitorW LIB "WinSpool.drv" ALIAS "DeleteMonitorW" ( _
    pName        AS WSTRINGZ, _
    pEnvironment AS WSTRINGZ, _
    pMonitorName AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO DeleteMonitor=DeleteMonitorW
#ELSE
MACRO DeleteMonitor=DeleteMonitorA
#ENDIF ' NOT %UNICODE



DECLARE FUNCTION EnumPortsA LIB "WinSpool.drv" ALIAS "EnumPortsA" ( _
    pName       AS ASCIIZ, _
    BYVAL Level AS DWORD, _
    BYVAL pPort AS BYTE PTR, _
    BYVAL cbBuf AS DWORD, _
    pcbNeeded   AS DWORD, _
    pcReturned  AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION EnumPortsW LIB "WinSpool.drv" ALIAS "EnumPortsW" ( _
    pName       AS WSTRINGZ, _
    BYVAL Level AS DWORD, _
    BYVAL pPort AS BYTE PTR, _
    BYVAL cbBuf AS DWORD, _
    pcbNeeded   AS DWORD, _
    pcReturned  AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO EnumPorts=EnumPortsW
#ELSE
MACRO EnumPorts=EnumPortsA
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION AddPortA LIB "WinSpool.drv" ALIAS "AddPortA" ( _
    pName        AS ASCIIZ, _
    BYVAL hWnd   AS DWORD, _  ' HWND
    pMonitorName AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION AddPortW LIB "WinSpool.drv" ALIAS "AddPortW" ( _
    pName        AS WSTRINGZ, _
    BYVAL hWnd   AS DWORD, _  ' HWND
    pMonitorName AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO AddPort=AddPortW
#ELSE
MACRO AddPort=AddPortA
#ENDIF ' NOT %UNICODE



DECLARE FUNCTION ConfigurePortA LIB "WinSpool.drv" ALIAS "ConfigurePortA" ( _
    pName      AS ASCIIZ, _
    BYVAL hWnd AS DWORD, _  ' HWND
    pPortName  AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION ConfigurePortW LIB "WinSpool.drv" ALIAS "ConfigurePortW" ( _
    pName      AS WSTRINGZ, _
    BYVAL hWnd AS DWORD, _  ' HWND
    pPortName  AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO ConfigurePort=ConfigurePortW
#ELSE
MACRO ConfigurePort=ConfigurePortA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DeletePortA LIB "WinSpool.drv" ALIAS "DeletePortA" ( _
    pName      AS ASCIIZ, _
    BYVAL hWnd AS DWORD, _  ' HWND
    pPortName  AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION DeletePortW LIB "WinSpool.drv" ALIAS "DeletePortW" ( _
    pName      AS WSTRINGZ, _
    BYVAL hWnd AS DWORD, _  ' HWND
    pPortName  AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO DeletePort=DeletePortW
#ELSE
MACRO DeletePort=DeletePortA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION XcvDataW LIB "WinSpool.drv" ALIAS "XcvDataW" ( _
    BYVAL hXcv         AS DWORD, _  ' HANDLE
    pszDataName        AS WSTRINGZ, _
    BYVAL pInputData   AS BYTE PTR, _
    BYVAL cbInputData  AS DWORD, _
    BYVAL pOutputData  AS BYTE PTR, _
    BYVAL cbOutputData AS DWORD, _
    pcbOutputNeeded    AS DWORD, _
    pdwStatus          AS DWORD _
    ) AS LONG  ' BOOL

MACRO XcvData=XcvDataW

DECLARE FUNCTION GetDefaultPrinterA LIB "WinSpool.drv" _
    ALIAS "GetDefaultPrinterA" ( _
    pszBuffer  AS ASCIIZ, _
    pcchBuffer AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION GetDefaultPrinterW LIB "WinSpool.drv" _
    ALIAS "GetDefaultPrinterW" ( _
    pszBuffer  AS WSTRINGZ, _
    pcchBuffer AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO GetDefaultPrinter=GetDefaultPrinterW
#ELSE
MACRO GetDefaultPrinter=GetDefaultPrinterA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetDefaultPrinterA LIB "WinSpool.drv" _
    ALIAS "SetDefaultPrinterA" ( _
    pszPrinter AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetDefaultPrinterW LIB "WinSpool.drv" _
    ALIAS "SetDefaultPrinterW" ( _
    pszPrinter AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO SetDefaultPrinter=SetDefaultPrinterW
#ELSE
MACRO SetDefaultPrinter=SetDefaultPrinterA
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION SetPortA LIB "WinSpool.drv" ALIAS "SetPortA" ( _
    pName           AS ASCIIZ, _
    pPortName       AS ASCIIZ, _
    BYVAL dwLevel   AS DWORD, _
    BYVAL pPortInfo AS BYTE PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetPortW LIB "WinSpool.drv" ALIAS "SetPortW" ( _
    pName           AS WSTRINGZ, _
    pPortName       AS WSTRINGZ, _
    BYVAL dwLevel   AS DWORD, _
    BYVAL pPortInfo AS BYTE PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO SetPort=SetPortW
#ELSE
MACRO SetPort=SetPortA
#ENDIF ' NOT %UNICODE



DECLARE FUNCTION AddPrinterConnectionA LIB "WinSpool.drv" _
    ALIAS "AddPrinterConnectionA" ( _
    pName AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION AddPrinterConnectionW LIB "WinSpool.drv" _
    ALIAS "AddPrinterConnectionW" ( _
    pName AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO AddPrinterConnection=AddPrinterConnectionW
#ELSE
MACRO AddPrinterConnection=AddPrinterConnectionA
#ENDIF ' NOT %UNICODE



DECLARE FUNCTION DeletePrinterConnectionA LIB "WinSpool.drv" _
    ALIAS "DeletePrinterConnectionA" ( _
    pName AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION DeletePrinterConnectionW LIB "WinSpool.drv" _
    ALIAS "DeletePrinterConnectionW" ( _
    pName AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO DeletePrinterConnection=DeletePrinterConnectionW
#ELSE
MACRO DeletePrinterConnection=DeletePrinterConnectionA
#ENDIF ' NOT %UNICODE



DECLARE FUNCTION ConnectToPrinterDlg LIB "WinSpool.drv" _
    ALIAS "ConnectToPrinterDlg" ( _
    BYVAL hwnd  AS DWORD, _  ' HWND
    BYVAL Flags AS DWORD _
    ) AS DWORD  ' HANDLE

TYPE PROVIDOR_INFO_1A
    pName        AS ASCIIZ PTR
    pEnvironment AS ASCIIZ PTR
    pDLLName     AS ASCIIZ PTR
END TYPE

TYPE PROVIDOR_INFO_1W
    pName        AS WSTRINGZ PTR
    pEnvironment AS WSTRINGZ PTR
    pDLLName     AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE PROVIDOR_INFO_1
    PROVIDOR_INFO_1W
END TYPE
#ELSE
TYPE PROVIDOR_INFO_1
    PROVIDOR_INFO_1A
END TYPE
#ENDIF ' %UNICODE

TYPE PROVIDOR_INFO_2A
    pOrder AS ASCIIZ PTR
END TYPE

TYPE PROVIDOR_INFO_2W
    pOrder AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE PROVIDOR_INFO_2
    PROVIDOR_INFO_2W
END TYPE
#ELSE
TYPE PROVIDOR_INFO_2
    PROVIDOR_INFO_2A
END TYPE
#ENDIF ' %UNICODE

DECLARE FUNCTION AddPrintProvidorA LIB "WinSpool.drv" _
    ALIAS "AddPrintProvidorA" ( _
    pName               AS ASCIIZ, _
    BYVAL level         AS DWORD, _
    BYVAL pProvidorInfo AS BYTE PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION AddPrintProvidorW LIB "WinSpool.drv" _
    ALIAS "AddPrintProvidorW" ( _
    pName               AS WSTRINGZ, _
    BYVAL level         AS DWORD, _
    BYVAL pProvidorInfo AS BYTE PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO AddPrintProvidor=AddPrintProvidorW
#ELSE
MACRO AddPrintProvidor=AddPrintProvidorA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DeletePrintProvidorA LIB "WinSpool.drv" _
    ALIAS "DeletePrintProvidorA" ( _
    pName              AS ASCIIZ, _
    pEnvironment       AS ASCIIZ, _
    pPrintProvidorName AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION DeletePrintProvidorW LIB "WinSpool.drv" _
    ALIAS "DeletePrintProvidorW" ( _
    pName              AS WSTRINGZ, _
    pEnvironment       AS WSTRINGZ, _
    pPrintProvidorName AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO DeletePrintProvidor=DeletePrintProvidorW
#ELSE
MACRO DeletePrintProvidor=DeletePrintProvidorA
#ENDIF ' NOT %UNICODE

#IF (%NTDDI_VERSION >= %NTDDI_WINXPSP2)

DECLARE FUNCTION IsValidDevmodeA LIB "WinSpool.drv" ALIAS "IsValidDevmodeA" ( _
    pDevmode          AS DEVMODEA, _
    BYVAL DevmodeSize AS size_t _
    ) AS LONG  ' BOOL

DECLARE FUNCTION IsValidDevmodeW LIB "WinSpool.drv" ALIAS "IsValidDevmodeW" ( _
    pDevmode          AS DEVMODEW, _
    BYVAL DevmodeSize AS size_t _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO IsValidDevmode=IsValidDevmodeW
#ELSE
MACRO IsValidDevmode=IsValidDevmodeA
#ENDIF ' NOT %UNICODE

#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WINXPSP2)


'
' SetPrinterData and GetPrinterData Server Handle Key values
'

$SPLREG_DEFAULT_SPOOL_DIRECTORY             = "DefaultSpoolDirectory"
$SPLREG_PORT_THREAD_PRIORITY_DEFAULT        = "PortThreadPriorityDefault"
$SPLREG_PORT_THREAD_PRIORITY                = "PortThreadPriority"
$SPLREG_SCHEDULER_THREAD_PRIORITY_DEFAULT   = "SchedulerThreadPriorityDefault"
$SPLREG_SCHEDULER_THREAD_PRIORITY           = "SchedulerThreadPriority"
$SPLREG_BEEP_ENABLED                        = "BeepEnabled"
$SPLREG_NET_POPUP                           = "NetPopup"
$SPLREG_RETRY_POPUP                         = "RetryPopup"
$SPLREG_NET_POPUP_TO_COMPUTER               = "NetPopupToComputer"
$SPLREG_EVENT_LOG                           = "EventLog"
$SPLREG_MAJOR_VERSION                       = "MajorVersion"
$SPLREG_MINOR_VERSION                       = "MinorVersion"
$SPLREG_ARCHITECTURE                        = "Architecture"
$$SPLREG_DEFAULT_SPOOL_DIRECTORY            = "DefaultSpoolDirectory"$$
$$SPLREG_PORT_THREAD_PRIORITY_DEFAULT       = "PortThreadPriorityDefault"$$
$$SPLREG_PORT_THREAD_PRIORITY               = "PortThreadPriority"$$
$$SPLREG_SCHEDULER_THREAD_PRIORITY_DEFAULT  = "SchedulerThreadPriorityDefault"$$
$$SPLREG_SCHEDULER_THREAD_PRIORITY          = "SchedulerThreadPriority"$$
$$SPLREG_BEEP_ENABLED                       = "BeepEnabled"$$
$$SPLREG_NET_POPUP                          = "NetPopup"$$
$$SPLREG_RETRY_POPUP                        = "RetryPopup"$$
$$SPLREG_NET_POPUP_TO_COMPUTER              = "NetPopupToComputer"$$
$$SPLREG_EVENT_LOG                          = "EventLog"$$
$$SPLREG_MAJOR_VERSION                      = "MajorVersion"$$
$$SPLREG_MINOR_VERSION                      = "MinorVersion"$$
$$SPLREG_ARCHITECTURE                       = "Architecture"$$

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
$SPLREG_OS_VERSION                      = "OSVersion"
$$SPLREG_OS_VERSION                     = "OSVersion"$$
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WINXP)

$SPLREG_OS_VERSIONEX                        = "OSVersionEx"
$SPLREG_DS_PRESENT                          = "DsPresent"
$SPLREG_DS_PRESENT_FOR_USER                 = "DsPresentForUser"
$SPLREG_REMOTE_FAX                          = "RemoteFax"
$SPLREG_RESTART_JOB_ON_POOL_ERROR           = "RestartJobOnPoolError"
$SPLREG_RESTART_JOB_ON_POOL_ENABLED         = "RestartJobOnPoolEnabled"
$SPLREG_DNS_MACHINE_NAME                    = "DNSMachineName"
$$SPLREG_OS_VERSIONEX                       = "OSVersionEx"$$
$$SPLREG_DS_PRESENT                         = "DsPresent"$$
$$SPLREG_DS_PRESENT_FOR_USER                = "DsPresentForUser"$$
$$SPLREG_REMOTE_FAX                         = "RemoteFax"$$
$$SPLREG_RESTART_JOB_ON_POOL_ERROR          = "RestartJobOnPoolError"$$
$$SPLREG_RESTART_JOB_ON_POOL_ENABLED        = "RestartJobOnPoolEnabled"$$
$$SPLREG_DNS_MACHINE_NAME                   = "DNSMachineName"$$

#IF ((OSVER(%NTDDI_VERSION) = %NTDDI_WINXP) AND (SPVER(%NTDDI_VERSION) >= 2) OR  _
    (%NTDDI_VERSION >= %NTDDI_WS03SP1))
$SPLREG_ALLOW_USER_MANAGEFORMS          = "AllowUserManageForms"
$$SPLREG_ALLOW_USER_MANAGEFORMS         = "AllowUserManageForms"$$
#ENDIF ' ((OSVER(%NTDDI_VERSION) = %NTDDI_WINXP) ...

#IF (%NTDDI_VERSION >= %NTDDI_WS03)
$SPLREG_WEBSHAREMGMT                    = "WebShareMgmt"
$$SPLREG_WEBSHAREMGMT                   = "WebShareMgmt"$$
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WS03)


#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
$$SPLREG_PRINT_DRIVER_ISOLATION_GROUPS_SEPARATOR          = "\"$$
$SPLREG_PRINT_DRIVER_ISOLATION_GROUPS                     = "PrintDriverIsolationGroups"
$SPLREG_PRINT_DRIVER_ISOLATION_TIME_BEFORE_RECYCLE        = "PrintDriverIsolationTimeBeforeRecycle"
$SPLREG_PRINT_DRIVER_ISOLATION_MAX_OBJECTS_BEFORE_RECYCLE = "PrintDriverIsolationMaxobjsBeforeRecycle"
$SPLREG_PRINT_DRIVER_ISOLATION_IDLE_TIMEOUT               = "PrintDriverIsolationIdleTimeout"
$SPLREG_PRINT_DRIVER_ISOLATION_EXECUTION_POLICY           = "PrintDriverIsolationExecutionPolicy"
$SPLREG_PRINT_DRIVER_ISOLATION_OVERRIDE_POLICY            = "PrintDriverIsolationOverrideCompat"
$$SPLREG_PRINT_DRIVER_ISOLATION_GROUPS                     = "PrintDriverIsolationGroups"$$
$$SPLREG_PRINT_DRIVER_ISOLATION_TIME_BEFORE_RECYCLE        = "PrintDriverIsolationTimeBeforeRecycle"$$
$$SPLREG_PRINT_DRIVER_ISOLATION_MAX_OBJECTS_BEFORE_RECYCLE = "PrintDriverIsolationMaxobjsBeforeRecycle"$$
$$SPLREG_PRINT_DRIVER_ISOLATION_IDLE_TIMEOUT               = "PrintDriverIsolationIdleTimeout"$$
$$SPLREG_PRINT_DRIVER_ISOLATION_EXECUTION_POLICY           = "PrintDriverIsolationExecutionPolicy"$$
$$SPLREG_PRINT_DRIVER_ISOLATION_OVERRIDE_POLICY            = "PrintDriverIsolationOverrideCompat"$$
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WIN7)

%SERVER_ACCESS_ADMINISTER  = &H00000001
%SERVER_ACCESS_ENUMERATE   = &H00000002

%PRINTER_ACCESS_ADMINISTER = &H00000004
%PRINTER_ACCESS_USE        = &H00000008

%JOB_ACCESS_ADMINISTER     = &H00000010

#IF ((%NTDDI_VERSION >= %NTDDI_WINXPSP1) OR  _
     ((OSVER(%NTDDI_VERSION) = %NTDDI_WIN2K) AND (SPVER(%NTDDI_VERSION) >= 3)))
    %JOB_ACCESS_READ       = &H00000020
#ENDIF ' ((%NTDDI_VERSION >= %NTDDI_WINXPSP1) ...

'
' Access rights for print servers
'

%SERVER_ALL_ACCESS  = (%STANDARD_RIGHTS_REQUIRED      OR _
                       %SERVER_ACCESS_ADMINISTER      OR _
                       %SERVER_ACCESS_ENUMERATE)

%SERVER_READ        = (%STANDARD_RIGHTS_READ          OR _
                       %SERVER_ACCESS_ENUMERATE)

%SERVER_WRITE       = (%STANDARD_RIGHTS_WRITE         OR _
                       %SERVER_ACCESS_ADMINISTER      OR _
                       %SERVER_ACCESS_ENUMERATE)

%SERVER_EXECUTE     = (%STANDARD_RIGHTS_EXECUTE       OR _
                       %SERVER_ACCESS_ENUMERATE)

'
' Access rights for printers
'

%PRINTER_ALL_ACCESS = (%STANDARD_RIGHTS_REQUIRED     OR _
                       %PRINTER_ACCESS_ADMINISTER    OR _
                       %PRINTER_ACCESS_USE)

%PRINTER_READ       = (%STANDARD_RIGHTS_READ         OR _
                       %PRINTER_ACCESS_USE)

%PRINTER_WRITE      = (%STANDARD_RIGHTS_WRITE        OR _
                       %PRINTER_ACCESS_USE)

%PRINTER_EXECUTE    = (%STANDARD_RIGHTS_EXECUTE      OR _
                       %PRINTER_ACCESS_USE)

'
' Access rights for jobs
'

#IF ((%NTDDI_VERSION >= %NTDDI_WINXPSP1) OR  _
     (((%NTDDI_VERSION AND %OSVERSION_MASK) = %NTDDI_WIN2K) _
     AND ((%NTDDI_VERSION AND %SPVERSION_MASK) / 256 >= 3)))
%JOB_ALL_ACCESS       = (%STANDARD_RIGHTS_REQUIRED    OR _
                         %JOB_ACCESS_ADMINISTER       OR _
                         %JOB_ACCESS_READ)
#ELSE
%JOB_ALL_ACCESS       = (%STANDARD_RIGHTS_REQUIRED    OR _
                         %JOB_ACCESS_ADMINISTER)
#ENDIF

#IF ((%NTDDI_VERSION >= %NTDDI_WINXPSP1) OR  _
     (((%NTDDI_VERSION AND %OSVERSION_MASK) = %NTDDI_WIN2K) _
     AND ((%NTDDI_VERSION AND %SPVERSION_MASK) / 256 >= 3)))
%JOB_READ             = (%STANDARD_RIGHTS_READ        OR _
                         %JOB_ACCESS_READ)
#ELSE
%JOB_READ             = (%STANDARD_RIGHTS_READ        OR _
                         %JOB_ACCESS_ADMINISTER)

#ENDIF

%JOB_WRITE            = (%STANDARD_RIGHTS_WRITE       OR _
                         %JOB_ACCESS_ADMINISTER)

%JOB_EXECUTE          = (%STANDARD_RIGHTS_EXECUTE     OR _
                         %JOB_ACCESS_ADMINISTER)


'
' DS Print-Queue property tables
'


' Predefined Registry Keys used by Set/GetPrinterDataEx
$SPLDS_SPOOLER_KEY                       = "DsSpooler"
$SPLDS_DRIVER_KEY                        = "DsDriver"
$SPLDS_USER_KEY                          = "DsUser"


' DS Print-Queue properties

$SPLDS_ASSET_NUMBER                      = "assetNumber"
$SPLDS_BYTES_PER_MINUTE                  = "bytesPerMinute"
$SPLDS_DESCRIPTION                       = "description"
$SPLDS_DRIVER_NAME                       = "driverName"
$SPLDS_DRIVER_VERSION                    = "driverVersion"
$SPLDS_LOCATION                          = "location"
$SPLDS_PORT_NAME                         = "portName"
$SPLDS_PRINT_ATTRIBUTES                  = "printAttributes"
$SPLDS_PRINT_BIN_NAMES                   = "printBinNames"
$SPLDS_PRINT_COLLATE                     = "printCollate"
$SPLDS_PRINT_COLOR                       = "printColor"
$SPLDS_PRINT_DUPLEX_SUPPORTED            = "printDuplexSupported"
$SPLDS_PRINT_END_TIME                    = "printEndTime"
$SPLDS_PRINTER_CLASS                     = "printQueue"
$SPLDS_PRINTER_NAME                      = "printerName"
$SPLDS_PRINT_KEEP_PRINTED_JOBS           = "printKeepPrintedJobs"
$SPLDS_PRINT_LANGUAGE                    = "printLanguage"
$SPLDS_PRINT_MAC_ADDRESS                 = "printMACAddress"
$SPLDS_PRINT_MAX_X_EXTENT                = "printMaxXExtent"
$SPLDS_PRINT_MAX_Y_EXTENT                = "printMaxYExtent"
$SPLDS_PRINT_MAX_RESOLUTION_SUPPORTED    = "printMaxResolutionSupported"
$SPLDS_PRINT_MEDIA_READY                 = "printMediaReady"
$SPLDS_PRINT_MEDIA_SUPPORTED             = "printMediaSupported"
$SPLDS_PRINT_MEMORY                      = "printMemory"
$SPLDS_PRINT_MIN_X_EXTENT                = "printMinXExtent"
$SPLDS_PRINT_MIN_Y_EXTENT                = "printMinYExtent"
$SPLDS_PRINT_NETWORK_ADDRESS             = "printNetworkAddress"
$SPLDS_PRINT_NOTIFY                      = "printNotify"
$SPLDS_PRINT_NUMBER_UP                   = "printNumberUp"
$SPLDS_PRINT_ORIENTATIONS_SUPPORTED      = "printOrientationsSupported"
$SPLDS_PRINT_OWNER                       = "printOwner"
$SPLDS_PRINT_PAGES_PER_MINUTE            = "printPagesPerMinute"
$SPLDS_PRINT_RATE                        = "printRate"
$SPLDS_PRINT_RATE_UNIT                   = "printRateUnit"
$SPLDS_PRINT_SEPARATOR_FILE              = "printSeparatorFile"
$SPLDS_PRINT_SHARE_NAME                  = "printShareName"
$SPLDS_PRINT_SPOOLING                    = "printSpooling"
$SPLDS_PRINT_STAPLING_SUPPORTED          = "printStaplingSupported"
$SPLDS_PRINT_START_TIME                  = "printStartTime"
$SPLDS_PRINT_STATUS                      = "printStatus"
$SPLDS_PRIORITY                          = "priority"
$SPLDS_SERVER_NAME                       = "serverName"
$SPLDS_SHORT_SERVER_NAME                 = "shortServerName"
$SPLDS_UNC_NAME                          = "uNCName"
$SPLDS_URL                               = "url"
$SPLDS_FLAGS                             = "flags"
$SPLDS_VERSION_NUMBER                    = "versionNumber"

'
' -- Additional Print-Queue properties --
'
' These properties are not defined in the default Directory Services Schema,
' but should be used when extending the Schema so a consistent interface is
' maintained.
'
'

$SPLDS_PRINTER_NAME_ALIASES              = "printerNameAliases"      ' MULTI_SZ
$SPLDS_PRINTER_LOCATIONS                 = "printerLocations"        ' MULTI_SZ
$SPLDS_PRINTER_MODEL                     = "printerModel"            ' SZ


' Predefined Registry Keys used by Set/GetPrinterDataEx
$$SPLDS_SPOOLER_KEY                       = "DsSpooler"$$
$$SPLDS_DRIVER_KEY                        = "DsDriver"$$
$$SPLDS_USER_KEY                          = "DsUser"$$


' DS Print-Queue properties

$$SPLDS_ASSET_NUMBER                      = "assetNumber"$$
$$SPLDS_BYTES_PER_MINUTE                  = "bytesPerMinute"$$
$$SPLDS_DESCRIPTION                       = "description"$$
$$SPLDS_DRIVER_NAME                       = "driverName"$$
$$SPLDS_DRIVER_VERSION                    = "driverVersion"$$
$$SPLDS_LOCATION                          = "location"$$
$$SPLDS_PORT_NAME                         = "portName"$$
$$SPLDS_PRINT_ATTRIBUTES                  = "printAttributes"$$
$$SPLDS_PRINT_BIN_NAMES                   = "printBinNames"$$
$$SPLDS_PRINT_COLLATE                     = "printCollate"$$
$$SPLDS_PRINT_COLOR                       = "printColor"$$
$$SPLDS_PRINT_DUPLEX_SUPPORTED            = "printDuplexSupported"$$
$$SPLDS_PRINT_END_TIME                    = "printEndTime"$$
$$SPLDS_PRINTER_CLASS                     = "printQueue"$$
$$SPLDS_PRINTER_NAME                      = "printerName"$$
$$SPLDS_PRINT_KEEP_PRINTED_JOBS           = "printKeepPrintedJobs"$$
$$SPLDS_PRINT_LANGUAGE                    = "printLanguage"$$
$$SPLDS_PRINT_MAC_ADDRESS                 = "printMACAddress"$$
$$SPLDS_PRINT_MAX_X_EXTENT                = "printMaxXExtent"$$
$$SPLDS_PRINT_MAX_Y_EXTENT                = "printMaxYExtent"$$
$$SPLDS_PRINT_MAX_RESOLUTION_SUPPORTED    = "printMaxResolutionSupported"$$
$$SPLDS_PRINT_MEDIA_READY                 = "printMediaReady"$$
$$SPLDS_PRINT_MEDIA_SUPPORTED             = "printMediaSupported"$$
$$SPLDS_PRINT_MEMORY                      = "printMemory"$$
$$SPLDS_PRINT_MIN_X_EXTENT                = "printMinXExtent"$$
$$SPLDS_PRINT_MIN_Y_EXTENT                = "printMinYExtent"$$
$$SPLDS_PRINT_NETWORK_ADDRESS             = "printNetworkAddress"$$
$$SPLDS_PRINT_NOTIFY                      = "printNotify"$$
$$SPLDS_PRINT_NUMBER_UP                   = "printNumberUp"$$
$$SPLDS_PRINT_ORIENTATIONS_SUPPORTED      = "printOrientationsSupported"$$
$$SPLDS_PRINT_OWNER                       = "printOwner"$$
$$SPLDS_PRINT_PAGES_PER_MINUTE            = "printPagesPerMinute"$$
$$SPLDS_PRINT_RATE                        = "printRate"$$
$$SPLDS_PRINT_RATE_UNIT                   = "printRateUnit"$$
$$SPLDS_PRINT_SEPARATOR_FILE              = "printSeparatorFile"$$
$$SPLDS_PRINT_SHARE_NAME                  = "printShareName"$$
$$SPLDS_PRINT_SPOOLING                    = "printSpooling"$$
$$SPLDS_PRINT_STAPLING_SUPPORTED          = "printStaplingSupported"$$
$$SPLDS_PRINT_START_TIME                  = "printStartTime"$$
$$SPLDS_PRINT_STATUS                      = "printStatus"$$
$$SPLDS_PRIORITY                          = "priority"$$
$$SPLDS_SERVER_NAME                       = "serverName"$$
$$SPLDS_SHORT_SERVER_NAME                 = "shortServerName"$$
$$SPLDS_UNC_NAME                          = "uNCName"$$
$$SPLDS_URL                               = "url"$$
$$SPLDS_FLAGS                             = "flags"$$
$$SPLDS_VERSION_NUMBER                    = "versionNumber"$$

'
' -- Additional Print-Queue properties --
'
' These properties are not defined in the default Directory Services Schema,
' but should be used when extending the Schema so a consistent interface is
' maintained.
'
'

$$SPLDS_PRINTER_NAME_ALIASES              = "printerNameAliases"$$   ' MULTI_SZ
$$SPLDS_PRINTER_LOCATIONS                 = "printerLocations"$$     ' MULTI_SZ
$$SPLDS_PRINTER_MODEL                     = "printerModel"$$         ' SZ



#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
'
' Printer option flags that can be passed to OpenPrinter2 for
' controlling whether the cached or non cached handle is used.
'
MACRO PRINTER_OPTION_FLAGS_enum=LONG
ENUM PRINTER_OPTION_FLAGS BITS SINGULAR
    PRINTER_OPTION_NO_CACHE       = 1
    PRINTER_OPTION_CACHE
    PRINTER_OPTION_CLIENT_CHANGE
    PRINTER_OPTION_NO_CLIENT_DATA
END ENUM


TYPE PRINTER_OPTIONSA
    cbSize  AS DWORD
    dwFlags AS DWORD
END TYPE

TYPE PRINTER_OPTIONSW
    cbSize  AS DWORD
    dwFlags AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE PRINTER_OPTIONS
    PRINTER_OPTIONSW
END TYPE
#ELSE
TYPE PRINTER_OPTIONS
    PRINTER_OPTIONSA
END TYPE
#ENDIF ' %UNICODE

DECLARE FUNCTION OpenPrinter2A LIB "WinSpool.drv" ALIAS "OpenPrinter2A" ( _
    pPrinterName AS ASCIIZ, _
    phPrinter    AS DWORD, _  ' HANDLE
    pDefault     AS PRINTER_DEFAULTSA, _
    pOptions     AS PRINTER_OPTIONSA _
    ) AS LONG  ' BOOL

DECLARE FUNCTION OpenPrinter2W LIB "WinSpool.drv" ALIAS "OpenPrinter2W" ( _
    pPrinterName AS WSTRINGZ, _
    phPrinter    AS DWORD, _  ' HANDLE
    pDefault     AS PRINTER_DEFAULTSW, _
    pOptions     AS PRINTER_OPTIONSW _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO OpenPrinter2=OpenPrinter2W
#ELSE
MACRO OpenPrinter2=OpenPrinter2A
#ENDIF ' NOT %UNICODE

%PRINTER_CONNECTION_MISMATCH = &H00000020  ' printer should be mismatched
%PRINTER_CONNECTION_NO_UI    = &H00000040  ' Fail call if UI is needed in order to install printer driver

TYPE PRINTER_CONNECTION_INFO_1A
    dwFlags       AS DWORD
    pszDriverName AS ASCIIZ PTR
END TYPE

TYPE PRINTER_CONNECTION_INFO_1W
    dwFlags       AS DWORD
    pszDriverName AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE PRINTER_CONNECTION_INFO_1
    PRINTER_CONNECTION_INFO_1W
END TYPE
#ELSE
TYPE PRINTER_CONNECTION_INFO_1
    PRINTER_CONNECTION_INFO_1A
END TYPE
#ENDIF ' %UNICODE

DECLARE FUNCTION AddPrinterConnection2A LIB "WinSpool.drv" _
    ALIAS "AddPrinterConnection2A" ( _
    BYVAL hWnd      AS DWORD, _  ' HWND
    pszName         AS ASCIIZ, _
    BYVAL dwLevel   AS DWORD, _
    pConnectionInfo AS ANY _     ' PVOID
    ) AS LONG  ' BOOL

DECLARE FUNCTION AddPrinterConnection2W LIB "WinSpool.drv" _
    ALIAS "AddPrinterConnection2W" ( _
    BYVAL hWnd      AS DWORD, _  ' HWND
    pszName         AS WSTRINGZ, _
    BYVAL dwLevel   AS DWORD, _
    pConnectionInfo AS ANY _     ' PVOID
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO AddPrinterConnection2=AddPrinterConnection2W
#ELSE
MACRO AddPrinterConnection2=AddPrinterConnection2A
#ENDIF ' NOT %UNICODE


'
' Unless IPDFP_COPY_ALL_FILES is specified it is always
' assumed that we use the latest files (APD_COPY_NEW_FILES)
'
%IPDFP_COPY_ALL_FILES = &H00000001

DECLARE FUNCTION InstallPrinterDriverFromPackageA LIB "WinSpool.drv" _
    ALIAS "InstallPrinterDriverFromPackageA" ( _
    pszServer      AS ASCIIZ, _
    pszInfPath     AS ASCIIZ, _
    pszDriverName  AS ASCIIZ, _
    pszEnvironment AS ASCIIZ, _
    BYVAL dwFlags  AS DWORD _
    ) AS LONG  ' HRESULT

DECLARE FUNCTION InstallPrinterDriverFromPackageW LIB "WinSpool.drv" _
    ALIAS "InstallPrinterDriverFromPackageW" ( _
    pszServer      AS WSTRINGZ, _
    pszInfPath     AS WSTRINGZ, _
    pszDriverName  AS WSTRINGZ, _
    pszEnvironment AS WSTRINGZ, _
    BYVAL dwFlags  AS DWORD _
    ) AS LONG  ' HRESULT

#IF %DEF(%UNICODE)
MACRO InstallPrinterDriverFromPackage=InstallPrinterDriverFromPackageW
#ELSE
MACRO InstallPrinterDriverFromPackage=InstallPrinterDriverFromPackageA
#ENDIF ' NOT %UNICODE

%UPDP_SILENT_UPLOAD     = &H00000001  ' If specified we will not show UI during UploadPrinterDriverPackage API.
%UPDP_UPLOAD_ALWAYS     = &H00000002  ' Will not do the optimization of not uploading the files if the
                                      ' driver package is already present on remote machine.
%UPDP_CHECK_DRIVERSTORE = &H00000004  ' Check whether the given package exists in driver store or not.

DECLARE FUNCTION UploadPrinterDriverPackageA LIB "WinSpool.drv" _
    ALIAS "UploadPrinterDriverPackageA" ( _
    pszServer       AS ASCIIZ, _
    pszInfPath      AS ASCIIZ, _
    pszEnvironment  AS ASCIIZ, _
    BYVAL dwFlags   AS DWORD, _
    BYVAL hwnd      AS DWORD, _  ' HWND
    pszDestInfPath  AS ASCIIZ, _
    pcchDestInfPath AS DWORD _
    ) AS LONG  ' HRESULT

DECLARE FUNCTION UploadPrinterDriverPackageW LIB "WinSpool.drv" _
    ALIAS "UploadPrinterDriverPackageW" ( _
    pszServer       AS WSTRINGZ, _
    pszInfPath      AS WSTRINGZ, _
    pszEnvironment  AS WSTRINGZ, _
    BYVAL dwFlags   AS DWORD, _
    BYVAL hwnd      AS DWORD, _  ' HWND
    pszDestInfPath  AS WSTRINGZ, _
    pcchDestInfPath AS DWORD _
    ) AS LONG  ' HRESULT

#IF %DEF(%UNICODE)
MACRO UploadPrinterDriverPackage=UploadPrinterDriverPackageW
#ELSE
MACRO UploadPrinterDriverPackage=UploadPrinterDriverPackageA
#ENDIF ' NOT %UNICODE

TYPE CORE_PRINTER_DRIVERA
    CoreDriverGUID   AS GUID
    ftDriverDate     AS FILETIME
    dwlDriverVersion AS QUAD  ' DWORDLONG
    szPackageID      AS ASCIIZ * %MAX_PATH
END TYPE

TYPE CORE_PRINTER_DRIVERW
    CoreDriverGUID   AS GUID
    ftDriverDate     AS FILETIME
    dwlDriverVersion AS QUAD  ' DWORDLONG
    szPackageID      AS WSTRINGZ * %MAX_PATH
END TYPE

#IF %DEF(%UNICODE)
TYPE CORE_PRINTER_DRIVER
    CORE_PRINTER_DRIVERW
END TYPE
#ELSE
TYPE CORE_PRINTER_DRIVER
    CORE_PRINTER_DRIVERA
END TYPE
#ENDIF ' %UNICODE

DECLARE FUNCTION GetCorePrinterDriversA LIB "WinSpool.drv" _
    ALIAS "GetCorePrinterDriversA" ( _
    pszServer                  AS ASCIIZ, _
    pszEnvironment             AS ASCIIZ, _
    pszzCoreDriverDependencies AS ASCIIZ, _
    BYVAL cCorePrinterDrivers  AS DWORD, _
    BYVAL pCorePrinterDrivers  AS CORE_PRINTER_DRIVERA PTR _
    ) AS LONG  ' HRESULT

DECLARE FUNCTION GetCorePrinterDriversW LIB "WinSpool.drv" _
    ALIAS "GetCorePrinterDriversW" ( _
    pszServer                  AS WSTRINGZ, _
    pszEnvironment             AS WSTRINGZ, _
    pszzCoreDriverDependencies AS WSTRINGZ, _
    BYVAL cCorePrinterDrivers  AS DWORD, _
    BYVAL pCorePrinterDrivers  AS CORE_PRINTER_DRIVERW PTR _
    ) AS LONG  ' HRESULT

#IF %DEF(%UNICODE)
MACRO GetCorePrinterDrivers=GetCorePrinterDriversW
#ELSE
MACRO GetCorePrinterDrivers=GetCorePrinterDriversA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CorePrinterDriverInstalledA LIB "WinSpool.drv" _
    ALIAS "CorePrinterDriverInstalledA" ( _
    pszServer              AS ASCIIZ, _
    pszEnvironment         AS ASCIIZ, _
    BYVAL CoreDriverGUID   AS GUID, _
    BYVAL ftDriverDate     AS FILETIME, _
    BYVAL dwlDriverVersion AS QUAD, _  ' DWORDLONG
    pbDriverInstalled      AS LONG _   ' BOOL
    ) AS LONG  ' HRESULT

DECLARE FUNCTION CorePrinterDriverInstalledW LIB "WinSpool.drv" _
    ALIAS "CorePrinterDriverInstalledW" ( _
    pszServer              AS WSTRINGZ, _
    pszEnvironment         AS WSTRINGZ, _
    BYVAL CoreDriverGUID   AS GUID, _
    BYVAL ftDriverDate     AS FILETIME, _
    BYVAL dwlDriverVersion AS QUAD, _  ' DWORDLONG
    pbDriverInstalled      AS LONG _   ' BOOL
    ) AS LONG  ' HRESULT

#IF %DEF(%UNICODE)
MACRO CorePrinterDriverInstalled=CorePrinterDriverInstalledW
#ELSE
MACRO CorePrinterDriverInstalled=CorePrinterDriverInstalledA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetPrinterDriverPackagePathA LIB "WinSpool.drv" _
    ALIAS "GetPrinterDriverPackagePathA" ( _
    pszServer                 AS ASCIIZ, _
    pszEnvironment            AS ASCIIZ, _
    pszLanguage               AS ASCIIZ, _
    pszPackageID              AS ASCIIZ, _
    pszDriverPackageCab       AS ASCIIZ, _
    BYVAL cchDriverPackageCab AS DWORD, _
    pcchRequiredSize          AS DWORD _
    ) AS LONG  ' HRESULT

DECLARE FUNCTION GetPrinterDriverPackagePathW LIB "WinSpool.drv" _
    ALIAS "GetPrinterDriverPackagePathW" ( _
    pszServer                 AS WSTRINGZ, _
    pszEnvironment            AS WSTRINGZ, _
    pszLanguage               AS WSTRINGZ, _
    pszPackageID              AS WSTRINGZ, _
    pszDriverPackageCab       AS WSTRINGZ, _
    BYVAL cchDriverPackageCab AS DWORD, _
    pcchRequiredSize          AS DWORD _
    ) AS LONG  ' HRESULT

#IF %DEF(%UNICODE)
MACRO GetPrinterDriverPackagePath=GetPrinterDriverPackagePathW
#ELSE
MACRO GetPrinterDriverPackagePath=GetPrinterDriverPackagePathA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DeletePrinterDriverPackageA LIB "WinSpool.drv" _
    ALIAS "DeletePrinterDriverPackageA" ( _
    pszServer      AS ASCIIZ, _
    pszInfPath     AS ASCIIZ, _
    pszEnvironment AS ASCIIZ _
    ) AS LONG  ' HRESULT

DECLARE FUNCTION DeletePrinterDriverPackageW LIB "WinSpool.drv" _
    ALIAS "DeletePrinterDriverPackageW" ( _
    pszServer      AS WSTRINGZ, _
    pszInfPath     AS WSTRINGZ, _
    pszEnvironment AS WSTRINGZ _
    ) AS LONG  ' HRESULT

#IF %DEF(%UNICODE)
MACRO DeletePrinterDriverPackage=DeletePrinterDriverPackageW
#ELSE
MACRO DeletePrinterDriverPackage=DeletePrinterDriverPackageA
#ENDIF ' NOT %UNICODE

MACRO EPrintPropertyType_enum=LONG
ENUM EPrintPropertyType SINGULAR
    kPropertyTypeString = 1
    kPropertyTypeInt32
    kPropertyTypeInt64
    kPropertyTypeByte
    kPropertyTypeTime
    kPropertyTypeDevMode
    kPropertyTypeSD
    kPropertyTypeNotificationReply
    kPropertyTypeNotificationOptions
    kPropertyTypeBuffer
END ENUM

MACRO EPrintXPSJobProgress_enum=LONG
ENUM EPrintXPSJobProgress SINGULAR
    kAddingDocumentSequence
    kDocumentSequenceAdded
    kAddingFixedDocument
    kFixedDocumentAdded
    kAddingFixedPage
    kFixedPageAdded
    kResourceAdded
    kFontAdded
    kImageAdded
    kXpsDocumentCommitted
END ENUM

MACRO EPrintXPSJobOperation_enum=LONG
ENUM EPrintXPSJobOperation SINGULAR
    kJobProduction = 1
    kJobConsumption
END ENUM

TYPE PrintPropertyValue_union_type
    cbBuf AS DWORD
    pBuf  AS DWORD  ' LPVOID
END TYPE

UNION PrintPropertyValue_union
    propertyByte   AS BYTE
    propertyString AS WSTRINGZ PTR
    propertyInt32  AS LONG
    propertyInt64  AS QUAD
    propertyBlob   AS PrintPropertyValue_union_type
END UNION

TYPE PrintPropertyValue
    ePropertyType AS EPrintPropertyType_enum
    value         AS PrintPropertyValue_union
END TYPE

TYPE PrintNamedProperty
    propertyName  AS WSTRINGZ PTR
    propertyValue AS PrintPropertyValue
END TYPE

TYPE PrintPropertiesCollection
    numberOfProperties   AS DWORD
    propertiesCollection AS PrintNamedProperty PTR
END TYPE

DECLARE FUNCTION ReportJobProcessingProgress LIB "WinSpool.drv" _
    ALIAS "ReportJobProcessingProgress" ( _
    BYVAL printerHandle AS DWORD, _  ' HANDLE
    BYVAL jobId         AS DWORD, _
    BYVAL jobOperation  AS EPrintXPSJobOperation_enum, _
    BYVAL jobProgress   AS EPrintXPSJobProgress_enum _
    ) AS LONG  ' HRESULT

DECLARE FUNCTION GetPrinterDriver2A LIB "WinSpool.drv" _
    ALIAS "GetPrinterDriver2A" ( _
    BYVAL hWnd        AS DWORD, _  ' HWND
    BYVAL hPrinter    AS DWORD, _  ' HANDLE
    pEnvironment      AS ASCIIZ, _
    BYVAL Level       AS DWORD, _
    BYVAL pDriverInfo AS BYTE PTR, _
    BYVAL cbBuf       AS DWORD, _
    pcbNeeded         AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION GetPrinterDriver2W LIB "WinSpool.drv" _
    ALIAS "GetPrinterDriver2W" ( _
    BYVAL hWnd        AS DWORD, _  ' HWND
    BYVAL hPrinter    AS DWORD, _  ' HANDLE
    pEnvironment      AS WSTRINGZ, _
    BYVAL Level       AS DWORD, _
    BYVAL pDriverInfo AS BYTE PTR, _
    BYVAL cbBuf       AS DWORD, _
    pcbNeeded         AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO GetPrinterDriver2=GetPrinterDriver2W
#ELSE
MACRO GetPrinterDriver2=GetPrinterDriver2A
#ENDIF ' NOT %UNICODE

#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)

#IF (%NTDDI_VERSION >= %NTDDI_WIN7)

MACRO PRINT_EXECUTION_CONTEXT_enum=LONG
ENUM PRINT_EXECUTION_CONTEXT SINGULAR
    PRINT_EXECUTION_CONTEXT_APPLICATION
    PRINT_EXECUTION_CONTEXT_SPOOLER_SERVICE
    PRINT_EXECUTION_CONTEXT_SPOOLER_ISOLATION_HOST
    PRINT_EXECUTION_CONTEXT_FILTER_PIPELINE
    PRINT_EXECUTION_CONTEXT_WOW64
END ENUM

TYPE PRINT_EXECUTION_DATA
    context      AS PRINT_EXECUTION_CONTEXT_enum
    clientAppPID AS DWORD
END TYPE

DECLARE FUNCTION GetPrintExecutionData LIB "WinSpool.drv" _
    ALIAS "GetPrintExecutionData" ( _
    pData AS PRINT_EXECUTION_DATA _
    ) AS LONG  ' BOOL


#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WIN7)
