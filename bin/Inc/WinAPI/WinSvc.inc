'------------------------------------------------------------------------------
'
'  WinSvc.inc - Header file for the Service Control Manager
'
'  Copyright (c) 1997-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from WinSvc.h build version 0010 dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WINSVC = 1

#INCLUDE "WinNT.inc"

'
' Define API decoration for direct importing of DLL references.
'


'
' Constants
'

'
' Service database names
'

$$SERVICES_ACTIVE_DATABASEW   = "ServicesActive"$$
$$SERVICES_FAILED_DATABASEW   = "ServicesFailed"$$

$SERVICES_ACTIVE_DATABASEA    = "ServicesActive"
$SERVICES_FAILED_DATABASEA    = "ServicesFailed"

'
' Character to designate that a name is a group
'

%SC_GROUP_IDENTIFIERW        = &H002b  ' "+"$$
$$SC_GROUP_IDENTIFIERW       = "+"$$
%SC_GROUP_IDENTIFIERA        = &H2b    ' "+"
$SC_GROUP_IDENTIFIERA        = "+"

#IF %DEF(%UNICODE)

MACRO SERVICES_ACTIVE_DATABASE=SERVICES_ACTIVE_DATABASEW
MACRO SERVICES_FAILED_DATABASE=SERVICES_FAILED_DATABASEW


%SC_GROUP_IDENTIFIER = %SC_GROUP_IDENTIFIERW

#ELSE ' NOT %DEF UNICODE

MACRO SERVICES_ACTIVE_DATABASE=SERVICES_ACTIVE_DATABASEA
MACRO SERVICES_FAILED_DATABASE=SERVICES_FAILED_DATABASEA

%SC_GROUP_IDENTIFIER = %SC_GROUP_IDENTIFIERA
#ENDIF ' NOT %DEF UNICODE


'
' Value to indicate no change to an optional parameter
'
%SERVICE_NO_CHANGE              = &Hffffffff???

'
' Service State -- for Enum Requests (Bit Mask)
'
%SERVICE_ACTIVE                 = &H00000001
%SERVICE_INACTIVE               = &H00000002
%SERVICE_STATE_ALL              = (%SERVICE_ACTIVE OR %SERVICE_INACTIVE)

'
' Controls
'
%SERVICE_CONTROL_STOP                   = &H00000001
%SERVICE_CONTROL_PAUSE                  = &H00000002
%SERVICE_CONTROL_CONTINUE               = &H00000003
%SERVICE_CONTROL_INTERROGATE            = &H00000004
%SERVICE_CONTROL_SHUTDOWN               = &H00000005
%SERVICE_CONTROL_PARAMCHANGE            = &H00000006
%SERVICE_CONTROL_NETBINDADD             = &H00000007
%SERVICE_CONTROL_NETBINDREMOVE          = &H00000008
%SERVICE_CONTROL_NETBINDENABLE          = &H00000009
%SERVICE_CONTROL_NETBINDDISABLE         = &H0000000A
%SERVICE_CONTROL_DEVICEEVENT            = &H0000000B
%SERVICE_CONTROL_HARDWAREPROFILECHANGE  = &H0000000C
%SERVICE_CONTROL_POWEREVENT             = &H0000000D
%SERVICE_CONTROL_SESSIONCHANGE          = &H0000000E
%SERVICE_CONTROL_PRESHUTDOWN            = &H0000000F
%SERVICE_CONTROL_TIMECHANGE             = &H00000010
%SERVICE_CONTROL_TRIGGEREVENT           = &H00000020

'
' Service State -- for CurrentState
'
%SERVICE_STOPPED                        = &H00000001
%SERVICE_START_PENDING                  = &H00000002
%SERVICE_STOP_PENDING                   = &H00000003
%SERVICE_RUNNING                        = &H00000004
%SERVICE_CONTINUE_PENDING               = &H00000005
%SERVICE_PAUSE_PENDING                  = &H00000006
%SERVICE_PAUSED                         = &H00000007

'
' Controls Accepted  (Bit Mask)
'
%SERVICE_ACCEPT_STOP                    = &H00000001
%SERVICE_ACCEPT_PAUSE_CONTINUE          = &H00000002
%SERVICE_ACCEPT_SHUTDOWN                = &H00000004
%SERVICE_ACCEPT_PARAMCHANGE             = &H00000008
%SERVICE_ACCEPT_NETBINDCHANGE           = &H00000010
%SERVICE_ACCEPT_HARDWAREPROFILECHANGE   = &H00000020
%SERVICE_ACCEPT_POWEREVENT              = &H00000040
%SERVICE_ACCEPT_SESSIONCHANGE           = &H00000080
%SERVICE_ACCEPT_PRESHUTDOWN             = &H00000100
%SERVICE_ACCEPT_TIMECHANGE              = &H00000200
%SERVICE_ACCEPT_TRIGGEREVENT            = &H00000400

'
' Service Control Manager object specific access types
'
%SC_MANAGER_CONNECT             = &H0001
%SC_MANAGER_CREATE_SERVICE      = &H0002
%SC_MANAGER_ENUMERATE_SERVICE   = &H0004
%SC_MANAGER_LOCK                = &H0008
%SC_MANAGER_QUERY_LOCK_STATUS   = &H0010
%SC_MANAGER_MODIFY_BOOT_CONFIG  = &H0020

%SC_MANAGER_ALL_ACCESS          = (%STANDARD_RIGHTS_REQUIRED      OR _
                                        %SC_MANAGER_CONNECT            OR _
                                        %SC_MANAGER_CREATE_SERVICE     OR _
                                        %SC_MANAGER_ENUMERATE_SERVICE  OR _
                                        %SC_MANAGER_LOCK               OR _
                                        %SC_MANAGER_QUERY_LOCK_STATUS  OR _
                                        %SC_MANAGER_MODIFY_BOOT_CONFIG)



'
' Service object specific access type
'
%SERVICE_QUERY_CONFIG           = &H0001
%SERVICE_CHANGE_CONFIG          = &H0002
%SERVICE_QUERY_STATUS           = &H0004
%SERVICE_ENUMERATE_DEPENDENTS   = &H0008
%SERVICE_START                  = &H0010
%SERVICE_STOP                   = &H0020
%SERVICE_PAUSE_CONTINUE         = &H0040
%SERVICE_INTERROGATE            = &H0080
%SERVICE_USER_DEFINED_CONTROL   = &H0100

%SERVICE_ALL_ACCESS             = (%STANDARD_RIGHTS_REQUIRED     OR _
                                   %SERVICE_QUERY_CONFIG         OR _
                                   %SERVICE_CHANGE_CONFIG        OR _
                                   %SERVICE_QUERY_STATUS         OR _
                                   %SERVICE_ENUMERATE_DEPENDENTS OR _
                                   %SERVICE_START                OR _
                                   %SERVICE_STOP                 OR _
                                   %SERVICE_PAUSE_CONTINUE       OR _
                                   %SERVICE_INTERROGATE          OR _
                                   %SERVICE_USER_DEFINED_CONTROL)

'
' Service flags for QueryServiceStatusEx
'
%SERVICE_RUNS_IN_SYSTEM_PROCESS  = &H00000001

'
' Info levels for ChangeServiceConfig2 and QueryServiceConfig2
'
%SERVICE_CONFIG_DESCRIPTION              = 1
%SERVICE_CONFIG_FAILURE_ACTIONS          = 2
%SERVICE_CONFIG_DELAYED_AUTO_START_INFO  = 3
%SERVICE_CONFIG_FAILURE_ACTIONS_FLAG     = 4
%SERVICE_CONFIG_SERVICE_SID_INFO         = 5
%SERVICE_CONFIG_REQUIRED_PRIVILEGES_INFO = 6
%SERVICE_CONFIG_PRESHUTDOWN_INFO         = 7
%SERVICE_CONFIG_TRIGGER_INFO             = 8
%SERVICE_CONFIG_PREFERRED_NODE           = 9

'
' Info levels for NotifyServiceStatusChange
'
%SERVICE_NOTIFY_STATUS_CHANGE_1       = 1
%SERVICE_NOTIFY_STATUS_CHANGE_2       = 2

%SERVICE_NOTIFY_STATUS_CHANGE         = %SERVICE_NOTIFY_STATUS_CHANGE_2

'
' Service notification masks
'
%SERVICE_NOTIFY_STOPPED               = &H00000001
%SERVICE_NOTIFY_START_PENDING         = &H00000002
%SERVICE_NOTIFY_STOP_PENDING          = &H00000004
%SERVICE_NOTIFY_RUNNING               = &H00000008
%SERVICE_NOTIFY_CONTINUE_PENDING      = &H00000010
%SERVICE_NOTIFY_PAUSE_PENDING         = &H00000020
%SERVICE_NOTIFY_PAUSED                = &H00000040
%SERVICE_NOTIFY_CREATED               = &H00000080
%SERVICE_NOTIFY_DELETED               = &H00000100
%SERVICE_NOTIFY_DELETE_PENDING        = &H00000200

'
' The following defines are for service stop reason codes
'

'
' Stop reason flags. Update SERVICE_STOP_REASON_FLAG_MAX when
' new flags are added.
'
%SERVICE_STOP_REASON_FLAG_MIN                  = &H00000000
%SERVICE_STOP_REASON_FLAG_UNPLANNED            = &H10000000
%SERVICE_STOP_REASON_FLAG_CUSTOM               = &H20000000
%SERVICE_STOP_REASON_FLAG_PLANNED              = &H40000000
%SERVICE_STOP_REASON_FLAG_MAX                  = &H80000000???

'
' Microsoft major reasons. Update SERVICE_STOP_REASON_MAJOR_MAX when
' new codes are added.
'
%SERVICE_STOP_REASON_MAJOR_MIN                 = &H00000000
%SERVICE_STOP_REASON_MAJOR_OTHER               = &H00010000
%SERVICE_STOP_REASON_MAJOR_HARDWARE            = &H00020000
%SERVICE_STOP_REASON_MAJOR_OPERATINGSYSTEM     = &H00030000
%SERVICE_STOP_REASON_MAJOR_SOFTWARE            = &H00040000
%SERVICE_STOP_REASON_MAJOR_APPLICATION         = &H00050000
%SERVICE_STOP_REASON_MAJOR_NONE                = &H00060000
%SERVICE_STOP_REASON_MAJOR_MAX                 = &H00070000
%SERVICE_STOP_REASON_MAJOR_MIN_CUSTOM          = &H00400000
%SERVICE_STOP_REASON_MAJOR_MAX_CUSTOM          = &H00ff0000

'
' Microsoft minor reasons. Update SERVICE_STOP_REASON_MINOR_MAX when
' new codes are added.
'
%SERVICE_STOP_REASON_MINOR_MIN                           = &H00000000
%SERVICE_STOP_REASON_MINOR_OTHER                         = &H00000001
%SERVICE_STOP_REASON_MINOR_MAINTENANCE                   = &H00000002
%SERVICE_STOP_REASON_MINOR_INSTALLATION                  = &H00000003
%SERVICE_STOP_REASON_MINOR_UPGRADE                       = &H00000004
%SERVICE_STOP_REASON_MINOR_RECONFIG                      = &H00000005
%SERVICE_STOP_REASON_MINOR_HUNG                          = &H00000006
%SERVICE_STOP_REASON_MINOR_UNSTABLE                      = &H00000007
%SERVICE_STOP_REASON_MINOR_DISK                          = &H00000008
%SERVICE_STOP_REASON_MINOR_NETWORKCARD                   = &H00000009
%SERVICE_STOP_REASON_MINOR_ENVIRONMENT                   = &H0000000a
%SERVICE_STOP_REASON_MINOR_HARDWARE_DRIVER               = &H0000000b
%SERVICE_STOP_REASON_MINOR_OTHERDRIVER                   = &H0000000c
%SERVICE_STOP_REASON_MINOR_SERVICEPACK                   = &H0000000d
%SERVICE_STOP_REASON_MINOR_SOFTWARE_UPDATE               = &H0000000e
%SERVICE_STOP_REASON_MINOR_SECURITYFIX                   = &H0000000f
%SERVICE_STOP_REASON_MINOR_SECURITY                      = &H00000010
%SERVICE_STOP_REASON_MINOR_NETWORK_CONNECTIVITY          = &H00000011
%SERVICE_STOP_REASON_MINOR_WMI                           = &H00000012
%SERVICE_STOP_REASON_MINOR_SERVICEPACK_UNINSTALL         = &H00000013
%SERVICE_STOP_REASON_MINOR_SOFTWARE_UPDATE_UNINSTALL     = &H00000014
%SERVICE_STOP_REASON_MINOR_SECURITYFIX_UNINSTALL         = &H00000015
%SERVICE_STOP_REASON_MINOR_MMC                           = &H00000016
%SERVICE_STOP_REASON_MINOR_NONE                          = &H00000017
%SERVICE_STOP_REASON_MINOR_MAX                           = &H00000018
%SERVICE_STOP_REASON_MINOR_MIN_CUSTOM                    = &H00000100
%SERVICE_STOP_REASON_MINOR_MAX_CUSTOM                    = &H0000FFFF

'
' Info levels for ControlServiceEx
'
%SERVICE_CONTROL_STATUS_REASON_INFO    = 1

'
' Service SID types supported
'
%SERVICE_SID_TYPE_NONE         = &H00000000
%SERVICE_SID_TYPE_UNRESTRICTED = &H00000001
%SERVICE_SID_TYPE_RESTRICTED   = (&H00000002 OR %SERVICE_SID_TYPE_UNRESTRICTED)

'
' Service trigger types
'
%SERVICE_TRIGGER_TYPE_DEVICE_INTERFACE_ARRIVAL = 1
%SERVICE_TRIGGER_TYPE_IP_ADDRESS_AVAILABILITY  = 2
%SERVICE_TRIGGER_TYPE_DOMAIN_JOIN              = 3
%SERVICE_TRIGGER_TYPE_FIREWALL_PORT_EVENT      = 4
%SERVICE_TRIGGER_TYPE_GROUP_POLICY             = 5
%SERVICE_TRIGGER_TYPE_CUSTOM                   = 20

'
' Service trigger data types
'
%SERVICE_TRIGGER_DATA_TYPE_BINARY = 1
%SERVICE_TRIGGER_DATA_TYPE_STRING = 2

'
'  NETWORK_MANAGER_FIRST_IP_ADDRESS_ARRIVAL_GUID & NETWORK_MANAGER_LAST_IP_ADDRESS_REMOVAL_GUID are used with
'  SERVICE_TRIGGER_TYPE_IP_ADDRESS_AVAILABILITY trigger.
'
$NETWORK_MANAGER_FIRST_IP_ADDRESS_ARRIVAL_GUID = GUID$("{4f27f2de-14e2-430b-a549-7cd48cbc8245}")

$NETWORK_MANAGER_LAST_IP_ADDRESS_REMOVAL_GUID = GUID$("{cc4ba62a-162e-4648-847a-b6bdf993e335}")

'
'  DOMAIN_JOIN_GUID & DOMAIN_LEAVE_GUID are used with SERVICE_TRIGGER_TYPE_DOMAIN_JOIN trigger.
'
$DOMAIN_JOIN_GUID = GUID$("{1ce20aba-9851-4421-9430-1ddeb766e809}")

$DOMAIN_LEAVE_GUID = GUID$("{ddaf516e-58c2-4866-9574-c3b615d42ea1}")

'
'  FIREWALL_PORT_OPEN_GUID & FIREWALL_PORT_CLOSE_GUID are used with
'  SERVICE_TRIGGER_TYPE_FIREWALL_PORT_EVENT trigger.
'
$FIREWALL_PORT_OPEN_GUID = GUID$("{b7569e07-8421-4ee0-ad10-86915afdad09}")

$FIREWALL_PORT_CLOSE_GUID = GUID$("{a144ed38-8e12-4de4-9d96-e64740b1a524}")


'
'  MACHINE_POLICY_PRESENT_GUID & USER_POLICY_PRESENT_GUID are used with
'  SERVICE_TRIGGER_TYPE_GROUP_POLICY trigger.
'
$MACHINE_POLICY_PRESENT_GUID = GUID$("{659FCAE6-5BDB-4DA9-B1FF-CA2A178D46E0}")

$USER_POLICY_PRESENT_GUID = GUID$("{54FB46C8-F089-464C-B1FD-59D1B62C3B50}")


'
' Service trigger actions
'
%SERVICE_TRIGGER_ACTION_SERVICE_START = 1
%SERVICE_TRIGGER_ACTION_SERVICE_STOP  = 2

'
' argv[1] passed into ServiceMain of trigger started services
'
$$SERVICE_TRIGGER_STARTED_ARGUMENT = "TriggerStarted"$$

'
' Service description string
'
TYPE SERVICE_DESCRIPTIONA
    lpDescription AS ASCIIZ PTR
END TYPE
'
' Service description string
'
TYPE SERVICE_DESCRIPTIONW
    lpDescription AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE SERVICE_DESCRIPTION
    SERVICE_DESCRIPTIONW
END TYPE
#ELSE
TYPE SERVICE_DESCRIPTION
    SERVICE_DESCRIPTIONA
END TYPE
#ENDIF ' UNICODE

'
' Actions to take on service failure
'
' enum _SC_ACTION_TYPE
%SC_ACTION_NONE          = 0
%SC_ACTION_RESTART       = 1
%SC_ACTION_REBOOT        = 2
%SC_ACTION_RUN_COMMAND   = 3

TYPE SC_ACTION
    aType AS LONG  ' SC_ACTION_TYPE
    Delay AS DWORD
END TYPE

TYPE SERVICE_FAILURE_ACTIONSA
    dwResetPeriod AS DWORD
    lpRebootMsg   AS ASCIIZ PTR
    lpCommand     AS ASCIIZ PTR
    cActions      AS DWORD
    lpsaActions   AS LONG PTR  ' SC_ACTION *
END TYPE

TYPE SERVICE_FAILURE_ACTIONSW
    dwResetPeriod AS DWORD
    lpRebootMsg   AS WSTRINGZ PTR
    lpCommand     AS WSTRINGZ PTR
    cActions      AS DWORD
    lpsaActions   AS LONG PTR  ' SC_ACTION *
END TYPE

#IF %DEF(%UNICODE)
TYPE SERVICE_FAILURE_ACTIONS
    SERVICE_FAILURE_ACTIONSW
END TYPE
#ELSE
TYPE SERVICE_FAILURE_ACTIONS
    SERVICE_FAILURE_ACTIONSA
END TYPE
#ENDIF ' UNICODE

'
' Service delayed autostart info setting
'
TYPE SERVICE_DELAYED_AUTO_START_INFO
    fDelayedAutostart AS LONG    ' Delayed autostart flag
END TYPE

'
' Service failure actions flag setting
'
TYPE SERVICE_FAILURE_ACTIONS_FLAG
    fFailureActionsOnNonCrashFailures AS LONG   ' Failure actions flag
END TYPE

'
' Service SID info setting
'
TYPE SERVICE_SID_INFO
    dwServiceSidType AS DWORD    ' Service SID type
END TYPE

'
' Service required privileges information
'
TYPE SERVICE_REQUIRED_PRIVILEGES_INFOA
    pmszRequiredPrivileges AS ASCIIZ PTR    ' Required privileges multi-sz
END TYPE

'
' Service required privileges information
'
TYPE SERVICE_REQUIRED_PRIVILEGES_INFOW
    pmszRequiredPrivileges AS WSTRINGZ PTR    ' Required privileges multi-sz
END TYPE

#IF %DEF(%UNICODE)
TYPE SERVICE_REQUIRED_PRIVILEGES_INFO
    SERVICE_REQUIRED_PRIVILEGES_INFOW
END TYPE
#ELSE
TYPE SERVICE_REQUIRED_PRIVILEGES_INFO
    SERVICE_REQUIRED_PRIVILEGES_INFOA
END TYPE
#ENDIF ' UNICODE

'
' Service preshutdown timeout setting
'
TYPE SERVICE_PRESHUTDOWN_INFO
    dwPreshutdownTimeout AS DWORD   ' Timeout in msecs
END TYPE

'
'  Service trigger data item
'
TYPE SERVICE_TRIGGER_SPECIFIC_DATA_ITEM
    dwDataType AS DWORD    ' Data type -- one of SERVICE_TRIGGER_DATA_TYPE_* constants
    cbData     AS DWORD    ' Size of trigger specific data
    pData      AS BYTE PTR ' Trigger specific data
END TYPE

'
'  Trigger-specific information
'
TYPE SERVICE_TRIGGER
    dwTriggerType   AS DWORD     ' One of SERVICE_TRIGGER_TYPE_* constants
    dwAction        AS DWORD     ' One of SERVICE_TRIGGER_ACTION_* constants
    pTriggerSubtype AS GUID PTR  ' Provider GUID if the trigger type is SERVICE_TRIGGER_TYPE_CUSTOM
                                 ' Device class interface GUID if the trigger type is
                                 ' SERVICE_TRIGGER_TYPE_DEVICE_INTERFACE_ARRIVAL
    cDataItems AS DWORD          ' Number of data items in pDataItems array
    pDataItems AS SERVICE_TRIGGER_SPECIFIC_DATA_ITEM PTR ' Trigger specific data
END TYPE

'
' Service trigger information
'
TYPE SERVICE_TRIGGER_INFO
    cTriggers AS DWORD                ' Number of triggers in the pTriggers array
    pTriggers AS SERVICE_TRIGGER PTR  ' Array of triggers
    pReserved AS BYTE PTR             ' Reserved, must be NULL
END TYPE

'
' Preferred node information
'
TYPE SERVICE_PREFERRED_NODE_INFO
    usPreferredNode AS WORD  ' Preferred node
    fDelete         AS BYTE  ' BOOLEAN  ' Delete the preferred node setting
END TYPE

'
' Time change information
'
TYPE SERVICE_TIMECHANGE_INFO
    liNewTime AS QUAD  ' LARGE_INTEGER         ' New time
    liOldTime AS QUAD  ' LARGE_INTEGER         ' Old time
END TYPE


'
' Handle Types
'

'DECLARE_HANDLE(DWORD);
'typedef DWORD   *LPSC_HANDLE;

'DECLARE_HANDLE(SERVICE_STATUS_HANDLE);

'
' Info levels for QueryServiceStatusEx
'

MACRO SC_STATUS_TYPE_enum=LONG
ENUM SC_STATUS_TYPE SINGULAR
    SC_STATUS_PROCESS_INFO
END ENUM

'
' Info levels for EnumServicesStatusEx
'
MACRO SC_ENUM_TYPE_enum=LONG
ENUM SC_ENUM_TYPE
    SC_ENUM_PROCESS_INFO
END ENUM


'
' Service Status Structures
'

TYPE SERVICE_STATUS_TYPE
    dwServiceType             AS DWORD
    dwCurrentState            AS DWORD
    dwControlsAccepted        AS DWORD
    dwWin32ExitCode           AS DWORD
    dwServiceSpecificExitCode AS DWORD
    dwCheckPoint              AS DWORD
    dwWaitHint                AS DWORD
END TYPE

TYPE SERVICE_STATUS_PROCESS_TYPE
    dwServiceType             AS DWORD
    dwCurrentState            AS DWORD
    dwControlsAccepted        AS DWORD
    dwWin32ExitCode           AS DWORD
    dwServiceSpecificExitCode AS DWORD
    dwCheckPoint              AS DWORD
    dwWaitHint                AS DWORD
    dwProcessId               AS DWORD
    dwServiceFlags            AS DWORD
END TYPE


'
' Service Status Enumeration Structure
'

TYPE ENUM_SERVICE_STATUSA
    lpServiceName AS ASCIIZ PTR
    lpDisplayName AS ASCIIZ PTR
    ServiceStatus AS SERVICE_STATUS_TYPE
END TYPE

TYPE ENUM_SERVICE_STATUSW
    lpServiceName AS WSTRINGZ PTR
    lpDisplayName AS WSTRINGZ PTR
    ServiceStatus AS SERVICE_STATUS_TYPE
END TYPE

#IF %DEF(%UNICODE)
TYPE ENUM_SERVICE_STATUS
    ENUM_SERVICE_STATUSW
END TYPE
#ELSE
TYPE ENUM_SERVICE_STATUS
    ENUM_SERVICE_STATUSA
END TYPE
#ENDIF ' UNICODE

TYPE ENUM_SERVICE_STATUS_PROCESSA
    lpServiceName AS ASCIIZ PTR
    lpDisplayName AS ASCIIZ PTR
    ServiceStatusProcess AS SERVICE_STATUS_PROCESS_TYPE
END TYPE

TYPE ENUM_SERVICE_STATUS_PROCESSW
    lpServiceName AS WSTRINGZ PTR
    lpDisplayName AS WSTRINGZ PTR
    ServiceStatusProcess AS SERVICE_STATUS_PROCESS_TYPE
END TYPE

#IF %DEF(%UNICODE)
TYPE ENUM_SERVICE_STATUS_PROCESS
    ENUM_SERVICE_STATUS_PROCESSW
END TYPE
#ELSE
TYPE ENUM_SERVICE_STATUS_PROCESS
    ENUM_SERVICE_STATUS_PROCESSA
END TYPE
#ENDIF ' UNICODE

'
' Structures for the Lock API functions
'

'typedef LPVOID  DWORD;

TYPE QUERY_SERVICE_LOCK_STATUSA
    fIsLocked      AS DWORD
    lpLockOwner    AS ASCIIZ PTR
    dwLockDuration AS DWORD
END TYPE

TYPE QUERY_SERVICE_LOCK_STATUSW
    fIsLocked      AS DWORD
    lpLockOwner    AS WSTRINGZ PTR
    dwLockDuration AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE QUERY_SERVICE_LOCK_STATUS
    QUERY_SERVICE_LOCK_STATUSW
END TYPE
#ELSE
TYPE QUERY_SERVICE_LOCK_STATUS
    QUERY_SERVICE_LOCK_STATUSA
END TYPE
#ENDIF ' UNICODE



'
' Query Service Configuration Structure
'

TYPE QUERY_SERVICE_CONFIGA
    dwServiceType      AS DWORD
    dwStartType        AS DWORD
    dwErrorControl     AS DWORD
    lpBinaryPathName   AS ASCIIZ PTR
    lpLoadOrderGroup   AS ASCIIZ PTR
    dwTagId            AS DWORD
    lpDependencies     AS ASCIIZ PTR
    lpServiceStartName AS ASCIIZ PTR
    lpDisplayName      AS ASCIIZ PTR
END TYPE

TYPE QUERY_SERVICE_CONFIGW
    dwServiceType      AS DWORD
    dwStartType        AS DWORD
    dwErrorControl     AS DWORD
    lpBinaryPathName   AS WSTRINGZ PTR
    lpLoadOrderGroup   AS WSTRINGZ PTR
    dwTagId            AS DWORD
    lpDependencies     AS WSTRINGZ PTR
    lpServiceStartName AS WSTRINGZ PTR
    lpDisplayName      AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE QUERY_SERVICE_CONFIG
    QUERY_SERVICE_CONFIGW
END TYPE
#ELSE
TYPE QUERY_SERVICE_CONFIG
    QUERY_SERVICE_CONFIGA
END TYPE
#ENDIF ' UNICODE



'
' Function Prototype for the Service Main Function
'

DECLARE SUB LPSERVICE_MAIN_FUNCTIONW (BYVAL dwNumServicesArgs AS DWORD, _
    lpServiceArgVectors AS ANY)

DECLARE SUB LPSERVICE_MAIN_FUNCTIONA (BYVAL dwNumServicesArgs AS DWORD, _
    lpServiceArgVectors AS ANY)

#IF %DEF(%UNICODE)
DECLARE SUB LPSERVICE_MAIN_FUNCTION (BYVAL dwNumServicesArgs AS DWORD, _
    lpServiceArgVectors AS ANY)
#ELSE
DECLARE SUB LPSERVICE_MAIN_FUNCTION (BYVAL dwNumServicesArgs AS DWORD, _
    lpServiceArgVectors AS ANY)
#ENDIF 'UNICODE


'
' Service Start Table
'

TYPE SERVICE_TABLE_ENTRYA
    lpServiceName AS ASCIIZ PTR
    lpServiceProc AS DWORD   ' LPSERVICE_MAIN_FUNCTIONA
END TYPE

TYPE SERVICE_TABLE_ENTRYW
    lpServiceName AS WSTRINGZ PTR
    lpServiceProc AS DWORD   ' LPSERVICE_MAIN_FUNCTIONA
END TYPE

#IF %DEF(%UNICODE)
TYPE SERVICE_TABLE_ENTRY
    SERVICE_TABLE_ENTRYW
END TYPE
#ELSE
TYPE SERVICE_TABLE_ENTRY
    SERVICE_TABLE_ENTRYA
END TYPE
#ENDIF ' UNICODE

'
' Prototype for the Service Control Handler Function
'

DECLARE SUB LPHANDLER_FUNCTION (BYVAL dwControl AS DWORD)

DECLARE FUNCTION LPHANDLER_FUNCTION_EX (BYVAL dwControl AS DWORD, _
    BYVAL dwEventType AS DWORD, lpEventData AS ANY, lpContext AS ANY) AS DWORD

'
' Service notification parameters
'

DECLARE FUNCTION PFN_SC_NOTIFY_CALLBACK (pParameter AS ANY) AS DWORD

'
'  Each new notify structure is a superset of the older version
'
TYPE SERVICE_NOTIFY_1
    dwVersion               AS DWORD
    pfnNotifyCallback       AS DWORD  ' PFN_SC_NOTIFY_CALLBACK
    pContext                AS DWORD
    dwNotificationStatus    AS DWORD
    ServiceStatus           AS SERVICE_STATUS_PROCESS_TYPE
END TYPE

TYPE SERVICE_NOTIFY_2A
    SERVICE_NOTIFY_1
    dwNotificationTriggered AS DWORD
    pszServiceNames         AS ASCIIZ PTR
END TYPE

TYPE SERVICE_NOTIFY_2W
    SERVICE_NOTIFY_1
    dwNotificationTriggered AS DWORD
    pszServiceNames         AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE SERVICE_NOTIFY_2
    SERVICE_NOTIFY_2W
END TYPE
#ELSE
TYPE SERVICE_NOTIFY_2
    SERVICE_NOTIFY_2A
END TYPE
#ENDIF ' UNICODE

TYPE SERVICE_NOTIFYA
    SERVICE_NOTIFY_2A
END TYPE
TYPE SERVICE_NOTIFYW
    SERVICE_NOTIFY_2W
END TYPE

#IF %DEF(%UNICODE)
TYPE SERVICE_NOTIFY
    SERVICE_NOTIFYW
END TYPE
#ELSE
TYPE SERVICE_NOTIFY
    SERVICE_NOTIFYA
END TYPE
#ENDIF ' UNICODE

'
' Service control status reason parameters
'
TYPE SERVICE_CONTROL_STATUS_REASON_PARAMSA
    dwReason      AS DWORD
    pszComment    AS ASCIIZ PTR
    ServiceStatus AS SERVICE_STATUS_PROCESS_TYPE
END TYPE

'
' Service control status reason parameters
'
TYPE SERVICE_CONTROL_STATUS_REASON_PARAMSW
    dwReason      AS DWORD
    pszComment    AS WSTRINGZ PTR
    ServiceStatus AS SERVICE_STATUS_PROCESS_TYPE
END TYPE

#IF %DEF(%UNICODE)
TYPE SERVICE_CONTROL_STATUS_REASON_PARAMS
    SERVICE_CONTROL_STATUS_REASON_PARAMSW
END TYPE
#ELSE
TYPE SERVICE_CONTROL_STATUS_REASON_PARAMS
    SERVICE_CONTROL_STATUS_REASON_PARAMSA
END TYPE
#ENDIF ' UNICODE

''''''''''''''''''''''''''''''''''''''
' API Function Prototypes
''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION ChangeServiceConfigA LIB "AdvApi32.dll" _
    ALIAS "ChangeServiceConfigA" ( _
    BYVAL hService       AS DWORD, _
    BYVAL dwServiceType  AS DWORD, _
    BYVAL dwStartType    AS DWORD, _
    BYVAL dwErrorControl AS DWORD, _
    lpBinaryPathName     AS ASCIIZ, _
    lpLoadOrderGroup     AS ASCIIZ, _
    lpdwTagId            AS DWORD, _
    lpDependencies       AS ASCIIZ, _
    lpServiceStartName   AS ASCIIZ, _
    lpPassword           AS ASCIIZ, _
    lpDisplayName        AS ASCIIZ _
    ) AS LONG

DECLARE FUNCTION ChangeServiceConfigW LIB "AdvApi32.dll" _
    ALIAS "ChangeServiceConfigW" ( _
    BYVAL hService       AS DWORD, _
    BYVAL dwServiceType  AS DWORD, _
    BYVAL dwStartType    AS DWORD, _
    BYVAL dwErrorControl AS DWORD, _
    lpBinaryPathName     AS WSTRINGZ, _
    lpLoadOrderGroup     AS WSTRINGZ, _
    lpdwTagId            AS DWORD, _
    lpDependencies       AS WSTRINGZ, _
    lpServiceStartName   AS WSTRINGZ, _
    lpPassword           AS WSTRINGZ, _
    lpDisplayName        AS WSTRINGZ _
    ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ChangeServiceConfig LIB "AdvApi32.dll" _
    ALIAS "ChangeServiceConfigW" ( _
    BYVAL hService       AS DWORD, _
    BYVAL dwServiceType  AS DWORD, _
    BYVAL dwStartType    AS DWORD, _
    BYVAL dwErrorControl AS DWORD, _
    lpBinaryPathName     AS WSTRINGZ, _
    lpLoadOrderGroup     AS WSTRINGZ, _
    lpdwTagId            AS DWORD, _
    lpDependencies       AS WSTRINGZ, _
    lpServiceStartName   AS WSTRINGZ, _
    lpPassword           AS WSTRINGZ, _
    lpDisplayName        AS WSTRINGZ _
    ) AS LONG
#ELSE
DECLARE FUNCTION ChangeServiceConfig LIB "AdvApi32.dll" _
    ALIAS "ChangeServiceConfigA" ( _
    BYVAL hService       AS DWORD, _
    BYVAL dwServiceType  AS DWORD, _
    BYVAL dwStartType    AS DWORD, _
    BYVAL dwErrorControl AS DWORD, _
    lpBinaryPathName     AS ASCIIZ, _
    lpLoadOrderGroup     AS ASCIIZ, _
    lpdwTagId            AS DWORD, _
    lpDependencies       AS ASCIIZ, _
    lpServiceStartName   AS ASCIIZ, _
    lpPassword           AS ASCIIZ, _
    lpDisplayName        AS ASCIIZ _
    ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION ChangeServiceConfig2A LIB "AdvApi32.dll" _
    ALIAS "ChangeServiceConfig2A" ( _
    BYVAL hService    AS DWORD, _
    dwInfoLevel AS DWORD, _
    lpInfo      AS DWORD _
    ) AS LONG

DECLARE FUNCTION ChangeServiceConfig2W LIB "AdvApi32.dll" _
    ALIAS "ChangeServiceConfig2W" ( _
    BYVAL hService    AS DWORD, _
    dwInfoLevel AS DWORD, _
    lpInfo      AS DWORD _
    ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ChangeServiceConfig2 LIB "AdvApi32.dll" _
    ALIAS "ChangeServiceConfig2W" ( _
    BYVAL hService    AS DWORD, _
    dwInfoLevel AS DWORD, _
    lpInfo      AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION ChangeServiceConfig2 LIB "AdvApi32.dll" _
    ALIAS "ChangeServiceConfig2A" ( _
    BYVAL hService    AS DWORD, _
    dwInfoLevel AS DWORD, _
    lpInfo      AS DWORD _
    ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CloseServiceHandle LIB "AdvApi32.dll" _
    ALIAS "CloseServiceHandle" ( _
    BYVAL hSCObject AS DWORD _
    ) AS LONG

DECLARE FUNCTION ControlService LIB "AdvApi32.dll" _
    ALIAS "ControlService" ( _
    BYVAL hService  AS DWORD, _
    dwControl AS DWORD, _
    lpServiceStatus AS SERVICE_STATUS_TYPE _
    ) AS LONG

DECLARE FUNCTION CreateServiceA LIB "AdvApi32.dll" _
    ALIAS "CreateServiceA" ( _
    BYVAL hSCManager      AS DWORD, _
    lpServiceName         AS ASCIIZ, _
    lpDisplayName         AS ASCIIZ, _
    BYVAL dwDesiredAccess AS DWORD, _
    BYVAL dwServiceType   AS DWORD, _
    BYVAL dwStartType     AS DWORD, _
    BYVAL dwErrorControl  AS DWORD, _
    lpBinaryPathName      AS ASCIIZ, _
    lpLoadOrderGroup      AS ASCIIZ, _
    lpdwTagId             AS DWORD, _
    lpDependencies        AS ASCIIZ, _
    lpServiceStartName    AS ASCIIZ, _
    lpPassword            AS ASCIIZ _
    ) AS DWORD

DECLARE FUNCTION CreateServiceW LIB "AdvApi32.dll" _
    ALIAS "CreateServiceW" ( _
    BYVAL hSCManager      AS DWORD, _
    lpServiceName         AS WSTRINGZ, _
    lpDisplayName         AS WSTRINGZ, _
    BYVAL dwDesiredAccess AS DWORD, _
    BYVAL dwServiceType   AS DWORD, _
    BYVAL dwStartType     AS DWORD, _
    BYVAL dwErrorControl  AS DWORD, _
    lpBinaryPathName      AS WSTRINGZ, _
    lpLoadOrderGroup      AS WSTRINGZ, _
    lpdwTagId             AS DWORD, _
    lpDependencies        AS WSTRINGZ, _
    lpServiceStartName    AS WSTRINGZ, _
    lpPassword            AS WSTRINGZ _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateService LIB "AdvApi32.dll" _
    ALIAS "CreateServiceW" ( _
    BYVAL hSCManager      AS DWORD, _
    lpServiceName         AS WSTRINGZ, _
    lpDisplayName         AS WSTRINGZ, _
    BYVAL dwDesiredAccess AS DWORD, _
    BYVAL dwServiceType   AS DWORD, _
    BYVAL dwStartType     AS DWORD, _
    BYVAL dwErrorControl  AS DWORD, _
    lpBinaryPathName      AS WSTRINGZ, _
    lpLoadOrderGroup      AS WSTRINGZ, _
    lpdwTagId             AS DWORD, _
    lpDependencies        AS WSTRINGZ, _
    lpServiceStartName    AS WSTRINGZ, _
    lpPassword            AS WSTRINGZ _
    ) AS DWORD
#ELSE
DECLARE FUNCTION CreateService LIB "AdvApi32.dll" _
    ALIAS "CreateServiceA" ( _
    BYVAL hSCManager      AS DWORD, _
    lpServiceName         AS ASCIIZ, _
    lpDisplayName         AS ASCIIZ, _
    BYVAL dwDesiredAccess AS DWORD, _
    BYVAL dwServiceType   AS DWORD, _
    BYVAL dwStartType     AS DWORD, _
    BYVAL dwErrorControl  AS DWORD, _
    lpBinaryPathName      AS ASCIIZ, _
    lpLoadOrderGroup      AS ASCIIZ, _
    lpdwTagId             AS DWORD, _
    lpDependencies        AS ASCIIZ, _
    lpServiceStartName    AS ASCIIZ, _
    lpPassword            AS ASCIIZ _
    ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DeleteService LIB "AdvApi32.dll" _
    ALIAS "DeleteService" (BYVAL hService AS DWORD) AS LONG

DECLARE FUNCTION EnumDependentServicesA LIB "AdvApi32.dll" _
    ALIAS "EnumDependentServicesA" ( _
    BYVAL hService       AS DWORD, _
    BYVAL dwServiceState AS DWORD, _
    lpServices           AS ENUM_SERVICE_STATUSA, _
    BYVAL cbBufSize      AS DWORD, _
    pcbBytesNeeded       AS DWORD, _
    lpServicesReturned   AS DWORD _
    ) AS LONG

DECLARE FUNCTION EnumDependentServicesW LIB "AdvApi32.dll" _
    ALIAS "EnumDependentServicesW" ( _
    BYVAL hService       AS DWORD, _
    BYVAL dwServiceState AS DWORD, _
    lpServices           AS ENUM_SERVICE_STATUSW, _
    BYVAL cbBufSize      AS DWORD, _
    pcbBytesNeeded       AS DWORD, _
    lpServicesReturned   AS DWORD _
    ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION EnumDependentServices LIB "AdvApi32.dll" _
    ALIAS "EnumDependentServicesW" ( _
    BYVAL hService       AS DWORD, _
    BYVAL dwServiceState AS DWORD, _
    lpServices           AS ENUM_SERVICE_STATUSW, _
    BYVAL cbBufSize      AS DWORD, _
    pcbBytesNeeded       AS DWORD, _
    lpServicesReturned   AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION EnumDependentServices LIB "AdvApi32.dll" _
    ALIAS "EnumDependentServicesA" ( _
    BYVAL hService       AS DWORD, _
    BYVAL dwServiceState AS DWORD, _
    lpServices           AS ENUM_SERVICE_STATUSA, _
    BYVAL cbBufSize      AS DWORD, _
    pcbBytesNeeded       AS DWORD, _
    lpServicesReturned   AS DWORD _
    ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumServicesStatusA LIB "AdvApi32.dll" _
    ALIAS "EnumServicesStatusA" ( _
    BYVAL hSCManager     AS DWORD, _
    BYVAL dwServiceType  AS DWORD, _
    BYVAL dwServiceState AS DWORD, _
    lpServices           AS ENUM_SERVICE_STATUSA, _
    BYVAL cbBufSize      AS DWORD, _
    pcbBytesNeeded       AS DWORD, _
    lpServicesReturned   AS DWORD, _
    lpResumeHandle       AS DWORD _
    ) AS LONG

DECLARE FUNCTION EnumServicesStatusW LIB "AdvApi32.dll" _
    ALIAS "EnumServicesStatusW" ( _
    BYVAL hSCManager     AS DWORD, _
    BYVAL dwServiceType  AS DWORD, _
    BYVAL dwServiceState AS DWORD, _
    lpServices           AS ENUM_SERVICE_STATUSW, _
    BYVAL cbBufSize      AS DWORD, _
    pcbBytesNeeded       AS DWORD, _
    lpServicesReturned   AS DWORD, _
    lpResumeHandle       AS DWORD _
    ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION EnumServicesStatus LIB "AdvApi32.dll" _
    ALIAS "EnumServicesStatusW" ( _
    BYVAL hSCManager     AS DWORD, _
    BYVAL dwServiceType  AS DWORD, _
    BYVAL dwServiceState AS DWORD, _
    lpServices           AS ENUM_SERVICE_STATUSW, _
    BYVAL cbBufSize      AS DWORD, _
    pcbBytesNeeded       AS DWORD, _
    lpServicesReturned   AS DWORD, _
    lpResumeHandle       AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION EnumServicesStatus LIB "AdvApi32.dll" _
    ALIAS "EnumServicesStatusA" ( _
    BYVAL hSCManager     AS DWORD, _
    BYVAL dwServiceType  AS DWORD, _
    BYVAL dwServiceState AS DWORD, _
    lpServices           AS ENUM_SERVICE_STATUSA, _
    BYVAL cbBufSize      AS DWORD, _
    pcbBytesNeeded       AS DWORD, _
    lpServicesReturned   AS DWORD, _
    lpResumeHandle       AS DWORD _
    ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumServicesStatusExA LIB "AdvApi32.dll" _
    ALIAS "EnumServicesStatusExA" ( _
    BYVAL hSCManager     AS DWORD, _
    BYVAL InfoLevel      AS LONG, _      ' SC_ENUM_TYPE
    BYVAL dwServiceType  AS DWORD, _
    BYVAL dwServiceState AS DWORD, _
    BYVAL lpServices     AS BYTE PTR, _
    BYVAL cbBufSize      AS DWORD, _
    pcbBytesNeeded       AS DWORD, _
    lpServicesReturned   AS DWORD, _
    lpResumeHandle       AS DWORD, _
    pszGroupName         AS ASCIIZ _
    ) AS LONG

DECLARE FUNCTION EnumServicesStatusExW LIB "AdvApi32.dll" _
    ALIAS "EnumServicesStatusExW" ( _
    BYVAL hSCManager     AS DWORD, _
    BYVAL InfoLevel      AS LONG, _      ' SC_ENUM_TYPE
    BYVAL dwServiceType  AS DWORD, _
    BYVAL dwServiceState AS DWORD, _
    BYVAL lpServices     AS BYTE PTR, _
    BYVAL cbBufSize      AS DWORD, _
    pcbBytesNeeded       AS DWORD, _
    lpServicesReturned   AS DWORD, _
    lpResumeHandle       AS DWORD, _
    pszGroupName         AS WSTRINGZ _
    ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION EnumServicesStatusEx LIB "AdvApi32.dll" _
    ALIAS "EnumServicesStatusExW" ( _
    BYVAL hSCManager     AS DWORD, _
    BYVAL InfoLevel      AS LONG, _      ' SC_ENUM_TYPE
    BYVAL dwServiceType  AS DWORD, _
    BYVAL dwServiceState AS DWORD, _
    BYVAL lpServices     AS BYTE PTR, _
    BYVAL cbBufSize      AS DWORD, _
    pcbBytesNeeded       AS DWORD, _
    lpServicesReturned   AS DWORD, _
    lpResumeHandle       AS DWORD, _
    pszGroupName         AS WSTRINGZ _
    ) AS LONG
#ELSE
DECLARE FUNCTION EnumServicesStatusEx LIB "AdvApi32.dll" _
    ALIAS "EnumServicesStatusExA" ( _
    BYVAL hSCManager     AS DWORD, _
    BYVAL InfoLevel      AS LONG, _      ' SC_ENUM_TYPE
    BYVAL dwServiceType  AS DWORD, _
    BYVAL dwServiceState AS DWORD, _
    BYVAL lpServices     AS BYTE PTR, _
    BYVAL cbBufSize      AS DWORD, _
    pcbBytesNeeded       AS DWORD, _
    lpServicesReturned   AS DWORD, _
    lpResumeHandle       AS DWORD, _
    pszGroupName         AS ASCIIZ _
    ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetServiceKeyNameA LIB "AdvApi32.dll" _
    ALIAS "GetServiceKeyNameA" ( _
    BYVAL hSCManager AS DWORD, _
    lpDisplayName    AS ASCIIZ, _
    lpServiceName    AS ASCIIZ, _
    lpcchBuffer      AS DWORD _
    ) AS LONG

DECLARE FUNCTION GetServiceKeyNameW LIB "AdvApi32.dll" _
    ALIAS "GetServiceKeyNameW" ( _
    BYVAL hSCManager AS DWORD, _
    lpDisplayName    AS WSTRINGZ, _
    lpServiceName    AS WSTRINGZ, _
    lpcchBuffer      AS DWORD _
    ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetServiceKeyName LIB "AdvApi32.dll" _
    ALIAS "GetServiceKeyNameW" ( _
    BYVAL hSCManager AS DWORD, _
    lpDisplayName    AS WSTRINGZ, _
    lpServiceName    AS WSTRINGZ, _
    lpcchBuffer      AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION GetServiceKeyName LIB "AdvApi32.dll" _
    ALIAS "GetServiceKeyNameA" ( _
    BYVAL hSCManager AS DWORD, _
    lpDisplayName    AS ASCIIZ, _
    lpServiceName    AS ASCIIZ, _
    lpcchBuffer      AS DWORD _
    ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetServiceDisplayNameA LIB "AdvApi32.dll" _
    ALIAS "GetServiceDisplayNameA" ( _
    BYVAL hSCManager AS DWORD, _
    lpServiceName    AS ASCIIZ, _
    lpDisplayName    AS ASCIIZ, _
    lpcchBuffer      AS DWORD _
    ) AS LONG

DECLARE FUNCTION GetServiceDisplayNameW LIB "AdvApi32.dll" _
    ALIAS "GetServiceDisplayNameW" ( _
    BYVAL hSCManager AS DWORD, _
    lpServiceName    AS WSTRINGZ, _
    lpDisplayName    AS WSTRINGZ, _
    lpcchBuffer      AS DWORD _
    ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetServiceDisplayName LIB "AdvApi32.dll" _
    ALIAS "GetServiceDisplayNameW" ( _
    BYVAL hSCManager AS DWORD, _
    lpServiceName    AS WSTRINGZ, _
    lpDisplayName    AS WSTRINGZ, _
    lpcchBuffer      AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION GetServiceDisplayName LIB "AdvApi32.dll" _
    ALIAS "GetServiceDisplayNameA" ( _
    BYVAL hSCManager AS DWORD, _
    lpServiceName    AS ASCIIZ, _
    lpDisplayName    AS ASCIIZ, _
    lpcchBuffer      AS DWORD _
    ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION LockServiceDatabase LIB "AdvApi32.dll" _
    ALIAS "LockServiceDatabase" (BYVAL hSCManager AS DWORD) AS DWORD

DECLARE FUNCTION NotifyBootConfigStatus LIB "AdvApi32.dll" _
    ALIAS "NotifyBootConfigStatus" (BYVAL BootAcceptable AS LONG) AS LONG

DECLARE FUNCTION OpenSCManagerA LIB "AdvApi32.dll" _
    ALIAS "OpenSCManagerA" ( _
    lpMachineName         AS ASCIIZ, _
    lpDatabaseName        AS ASCIIZ, _
    BYVAL dwDesiredAccess AS DWORD _
    ) AS DWORD

DECLARE FUNCTION OpenSCManagerW LIB "AdvApi32.dll" _
    ALIAS "OpenSCManagerW" ( _
    lpMachineName         AS WSTRINGZ, _
    lpDatabaseName        AS WSTRINGZ, _
    BYVAL dwDesiredAccess AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION OpenSCManager LIB "AdvApi32.dll" _
    ALIAS "OpenSCManagerW" ( _
    lpMachineName         AS WSTRINGZ, _
    lpDatabaseName        AS WSTRINGZ, _
    BYVAL dwDesiredAccess AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION OpenSCManager LIB "AdvApi32.dll" _
    ALIAS "OpenSCManagerA" ( _
    lpMachineName         AS ASCIIZ, _
    lpDatabaseName        AS ASCIIZ, _
    BYVAL dwDesiredAccess AS DWORD _
    ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION OpenServiceA LIB "AdvApi32.dll" _
    ALIAS "OpenServiceA" ( _
    BYVAL hSCManager      AS DWORD, _
    lpServiceName         AS ASCIIZ, _
    BYVAL dwDesiredAccess AS DWORD _
    ) AS DWORD

DECLARE FUNCTION OpenServiceW LIB "AdvApi32.dll" _
    ALIAS "OpenServiceW" ( _
    BYVAL hSCManager      AS DWORD, _
    lpServiceName         AS WSTRINGZ, _
    BYVAL dwDesiredAccess AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION OpenService LIB "AdvApi32.dll" _
    ALIAS "OpenServiceW" ( _
    BYVAL hSCManager      AS DWORD, _
    lpServiceName         AS WSTRINGZ, _
    BYVAL dwDesiredAccess AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION OpenService LIB "AdvApi32.dll" _
    ALIAS "OpenServiceA" ( _
    BYVAL hSCManager      AS DWORD, _
    lpServiceName         AS ASCIIZ, _
    BYVAL dwDesiredAccess AS DWORD _
    ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION QueryServiceConfigA LIB "AdvApi32.dll" _
    ALIAS "QueryServiceConfigA" ( _
    BYVAL hService  AS DWORD, _
    lpServiceConfig AS QUERY_SERVICE_CONFIGA, _
    BYVAL cbBufSize AS DWORD, _
    pcbBytesNeeded  AS DWORD _
    ) AS LONG

DECLARE FUNCTION QueryServiceConfigW LIB "AdvApi32.dll" _
    ALIAS "QueryServiceConfigW" ( _
    BYVAL hService  AS DWORD, _
    lpServiceConfig AS QUERY_SERVICE_CONFIGW, _
    BYVAL cbBufSize AS DWORD, _
    pcbBytesNeeded  AS DWORD _
    ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION QueryServiceConfig LIB "AdvApi32.dll" _
    ALIAS "QueryServiceConfigW" ( _
    BYVAL hService  AS DWORD, _
    lpServiceConfig AS QUERY_SERVICE_CONFIGW, _
    BYVAL cbBufSize AS DWORD, _
    pcbBytesNeeded  AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION QueryServiceConfig LIB "AdvApi32.dll" _
    ALIAS "QueryServiceConfigA" ( _
    BYVAL hService  AS DWORD, _
    lpServiceConfig AS QUERY_SERVICE_CONFIGA, _
    BYVAL cbBufSize AS DWORD, _
    pcbBytesNeeded  AS DWORD _
    ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION QueryServiceConfig2A LIB "AdvApi32.dll" _
    ALIAS "QueryServiceConfig2A" ( _
    BYVAL hService    AS DWORD, _
    BYVAL dwInfoLevel AS DWORD, _
    BYVAL lpBuffer    AS BYTE PTR, _
    BYVAL cbBufSize   AS DWORD, _
    pcbBytesNeeded    AS DWORD _
    ) AS LONG

DECLARE FUNCTION QueryServiceConfig2W LIB "AdvApi32.dll" _
    ALIAS "QueryServiceConfig2W" ( _
    BYVAL hService    AS DWORD, _
    BYVAL dwInfoLevel AS DWORD, _
    BYVAL lpBuffer    AS BYTE PTR, _
    BYVAL cbBufSize   AS DWORD, _
    pcbBytesNeeded    AS DWORD _
    ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION QueryServiceConfig2 LIB "AdvApi32.dll" _
    ALIAS "QueryServiceConfig2W" ( _
    BYVAL hService    AS DWORD, _
    BYVAL dwInfoLevel AS DWORD, _
    BYVAL lpBuffer    AS BYTE PTR, _
    BYVAL cbBufSize   AS DWORD, _
    pcbBytesNeeded    AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION QueryServiceConfig2 LIB "AdvApi32.dll" _
    ALIAS "QueryServiceConfig2A" ( _
    BYVAL hService    AS DWORD, _
    BYVAL dwInfoLevel AS DWORD, _
    BYVAL lpBuffer    AS BYTE PTR, _
    BYVAL cbBufSize   AS DWORD, _
    pcbBytesNeeded    AS DWORD _
    ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION QueryServiceLockStatusA LIB "AdvApi32.dll" _
    ALIAS "QueryServiceLockStatusA" ( _
    BYVAL hSCManager AS DWORD, _
    lpLockStatus     AS QUERY_SERVICE_LOCK_STATUSA, _
    BYVAL cbBufSize  AS DWORD, _
    pcbBytesNeeded   AS DWORD _
    ) AS LONG

DECLARE FUNCTION QueryServiceLockStatusW LIB "AdvApi32.dll" _
    ALIAS "QueryServiceLockStatusW" ( _
    BYVAL hSCManager AS DWORD, _
    lpLockStatus     AS QUERY_SERVICE_LOCK_STATUSW, _
    BYVAL cbBufSize  AS DWORD, _
    pcbBytesNeeded   AS DWORD _
    ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION QueryServiceLockStatus LIB "AdvApi32.dll" _
    ALIAS "QueryServiceLockStatusW" ( _
    BYVAL hSCManager AS DWORD, _
    lpLockStatus     AS QUERY_SERVICE_LOCK_STATUSW, _
    BYVAL cbBufSize  AS DWORD, _
    pcbBytesNeeded   AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION QueryServiceLockStatus LIB "AdvApi32.dll" _
    ALIAS "QueryServiceLockStatusA" ( _
    BYVAL hSCManager AS DWORD, _
    lpLockStatus     AS QUERY_SERVICE_LOCK_STATUSA, _
    BYVAL cbBufSize  AS DWORD, _
    pcbBytesNeeded   AS DWORD _
    ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION QueryServiceObjectSecurity LIB "AdvApi32.dll" _
    ALIAS "QueryServiceObjectSecurity" ( _
    BYVAL hService              AS DWORD, _
    BYVAL dwSecurityInformation AS DWORD, _   ' SECURITY_INFORMATION
    lpSecurityDescriptor        AS DWORD, _   ' PSECURITY_DESCRIPTOR
    BYVAL cbBufSize             AS DWORD, _
    pcbBytesNeeded              AS DWORD _
    ) AS LONG

DECLARE FUNCTION QueryServiceStatus LIB "AdvApi32.dll" _
    ALIAS "QueryServiceStatus" ( _
    BYVAL hService  AS DWORD, _
    lpServiceStatus AS SERVICE_STATUS_TYPE _
    ) AS LONG

DECLARE FUNCTION QueryServiceStatusEx LIB "AdvApi32.dll" _
    ALIAS "QueryServiceStatusEx" ( _
    BYVAL hService  AS DWORD, _
    BYVAL InfoLevel AS SC_STATUS_TYPE_enum, _
    BYVAL lpBuffer  AS BYTE PTR, _
    BYVAL cbBufSize AS DWORD, _
    pcbBytesNeeded  AS DWORD _
    ) AS LONG

DECLARE FUNCTION RegisterServiceCtrlHandlerA LIB "AdvApi32.dll" _
    ALIAS "RegisterServiceCtrlHandlerA" ( _
    lpServiceName       AS ASCIIZ, _
    BYVAL lpHandlerProc AS DWORD _   'HANDLER_FUNCTION
    ) AS DWORD  ' SERVICE_STATUS_HANDLE

DECLARE FUNCTION RegisterServiceCtrlHandlerW LIB "AdvApi32.dll" _
    ALIAS "RegisterServiceCtrlHandlerW" ( _
    lpServiceName       AS WSTRINGZ, _
    BYVAL lpHandlerProc AS DWORD _   'HANDLER_FUNCTION
    ) AS DWORD  ' SERVICE_STATUS_HANDLE

#IF %DEF(%UNICODE)
DECLARE FUNCTION RegisterServiceCtrlHandler LIB "AdvApi32.dll" _
    ALIAS "RegisterServiceCtrlHandlerW" ( _
    lpServiceName       AS WSTRINGZ, _
    BYVAL lpHandlerProc AS DWORD _   'HANDLER_FUNCTION
    ) AS DWORD  ' SERVICE_STATUS_HANDLE
#ELSE
DECLARE FUNCTION RegisterServiceCtrlHandler LIB "AdvApi32.dll" _
    ALIAS "RegisterServiceCtrlHandlerA" ( _
    lpServiceName       AS ASCIIZ, _
    BYVAL lpHandlerProc AS DWORD _   'HANDLER_FUNCTION
    ) AS DWORD  ' SERVICE_STATUS_HANDLE
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegisterServiceCtrlHandlerExA LIB "AdvApi32.dll" _
    ALIAS "RegisterServiceCtrlHandlerExA" ( _
    lpServiceName       AS ASCIIZ, _
    BYVAL lpHandlerProc AS DWORD, _   ' LPHANDLER_FUNCTION_EX
    lpContext           AS ANY _
    ) AS DWORD  ' SERVICE_STATUS_HANDLE

DECLARE FUNCTION RegisterServiceCtrlHandlerExW LIB "AdvApi32.dll" _
    ALIAS "RegisterServiceCtrlHandlerExW" ( _
    lpServiceName       AS WSTRINGZ, _
    BYVAL lpHandlerProc AS DWORD, _   ' LPHANDLER_FUNCTION_EX
    lpContext           AS ANY _
    ) AS DWORD  ' SERVICE_STATUS_HANDLE

#IF %DEF(%UNICODE)
DECLARE FUNCTION RegisterServiceCtrlHandlerEx LIB "AdvApi32.dll" _
    ALIAS "RegisterServiceCtrlHandlerExW" ( _
    lpServiceName       AS WSTRINGZ, _
    BYVAL lpHandlerProc AS DWORD, _   ' LPHANDLER_FUNCTION_EX
    lpContext           AS ANY _
    ) AS DWORD  ' SERVICE_STATUS_HANDLE
#ELSE
DECLARE FUNCTION RegisterServiceCtrlHandlerEx LIB "AdvApi32.dll" _
    ALIAS "RegisterServiceCtrlHandlerExA" ( _
    lpServiceName       AS ASCIIZ, _
    BYVAL lpHandlerProc AS DWORD, _   ' LPHANDLER_FUNCTION_EX
    lpContext           AS ANY _
    ) AS DWORD  ' SERVICE_STATUS_HANDLE
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetServiceObjectSecurity LIB "AdvApi32.dll" _
    ALIAS "SetServiceObjectSecurity" ( _
    BYVAL hService              AS DWORD, _
    BYVAL dwSecurityInformation AS DWORD, _   ' SECURITY_INFORMATION
    BYVAL lpSecurityDescriptor  AS DWORD _    ' PSECURITY_DESCRIPTOR
    ) AS LONG

DECLARE FUNCTION SetServiceStatus LIB "AdvApi32.dll" _
    ALIAS "SetServiceStatus" ( _
    BYVAL hServiceStatus AS DWORD, _  ' SERVICE_STATUS_HANDLE
    lpServiceStatus      AS DWORD _   ' LPSERVICE_STATUS
    ) AS LONG

DECLARE FUNCTION StartServiceCtrlDispatcherA LIB "AdvApi32.dll" _
    ALIAS "StartServiceCtrlDispatcherA" ( _
    BYVAL lpServiceStartTable AS SERVICE_TABLE_ENTRYA PTR _
    ) AS LONG

DECLARE FUNCTION StartServiceCtrlDispatcherW LIB "AdvApi32.dll" _
    ALIAS "StartServiceCtrlDispatcherW" ( _
    BYVAL lpServiceStartTable AS SERVICE_TABLE_ENTRYW PTR _
    ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION StartServiceCtrlDispatcher LIB "AdvApi32.dll" _
    ALIAS "StartServiceCtrlDispatcherW" ( _
    BYVAL lpServiceStartTable AS SERVICE_TABLE_ENTRYW PTR _
    ) AS LONG
#ELSE
DECLARE FUNCTION StartServiceCtrlDispatcher LIB "AdvApi32.dll" _
    ALIAS "StartServiceCtrlDispatcherA" ( _
    BYVAL lpServiceStartTable AS SERVICE_TABLE_ENTRYA PTR _
    ) AS LONG
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION StartServiceA LIB "AdvApi32.dll" _
    ALIAS "StartServiceA" ( _
    BYVAL hService            AS DWORD, _
    BYVAL dwNumServiceArgs    AS DWORD, _
    lpServiceArgVectors       AS ANY _
    ) AS LONG

DECLARE FUNCTION StartServiceW LIB "AdvApi32.dll" _
    ALIAS "StartServiceW" ( _
    BYVAL hService            AS DWORD, _
    BYVAL dwNumServiceArgs    AS DWORD, _
    lpServiceArgVectors       AS ANY _
    ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION StartService LIB "AdvApi32.dll" _
    ALIAS "StartServiceW" ( _
    BYVAL hService            AS DWORD, _
    BYVAL dwNumServiceArgs    AS DWORD, _
    lpServiceArgVectors       AS ANY _
    ) AS LONG
#ELSE
DECLARE FUNCTION StartService LIB "AdvApi32.dll" _
    ALIAS "StartServiceA" ( _
    BYVAL hService            AS DWORD, _
    BYVAL dwNumServiceArgs    AS DWORD, _
    lpServiceArgVectors       AS ANY _
    ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION UnlockServiceDatabase LIB "AdvApi32.dll" _
    ALIAS "UnlockServiceDatabase" (BYVAL ScLock AS DWORD) AS LONG

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

DECLARE FUNCTION NotifyServiceStatusChangeA LIB "AdvApi32.dll" _
    ALIAS "NotifyServiceStatusChangeA" ( _
    BYVAL hService      AS DWORD, _
    BYVAL dwNotifyMask  AS DWORD, _
    BYVAL pNotifyBuffer AS SERVICE_NOTIFYA PTR _
    ) AS DWORD

DECLARE FUNCTION NotifyServiceStatusChangeW LIB "AdvApi32.dll" _
    ALIAS "NotifyServiceStatusChangeW" ( _
    BYVAL hService      AS DWORD, _
    BYVAL dwNotifyMask  AS DWORD, _
    BYVAL pNotifyBuffer AS SERVICE_NOTIFYW PTR _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION NotifyServiceStatusChange LIB "AdvApi32.dll" _
    ALIAS "NotifyServiceStatusChangeW" ( _
    BYVAL hService      AS DWORD, _
    BYVAL dwNotifyMask  AS DWORD, _
    BYVAL pNotifyBuffer AS SERVICE_NOTIFYW PTR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NotifyServiceStatusChange LIB "AdvApi32.dll" _
    ALIAS "NotifyServiceStatusChangeA" ( _
    BYVAL hService      AS DWORD, _
    BYVAL dwNotifyMask  AS DWORD, _
    BYVAL pNotifyBuffer AS SERVICE_NOTIFYA PTR _
    ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION ControlServiceExA LIB "AdvApi32.dll" _
    ALIAS "ControlServiceExA" ( _
    BYVAL hService    AS DWORD, _
    BYVAL dwControl   AS DWORD, _
    BYVAL dwInfoLevel AS DWORD, _
    pControlParams    AS ANY _
    ) AS LONG

DECLARE FUNCTION ControlServiceExW LIB "AdvApi32.dll" _
    ALIAS "ControlServiceExW" ( _
    BYVAL hService    AS DWORD, _
    BYVAL dwControl   AS DWORD, _
    BYVAL dwInfoLevel AS DWORD, _
    pControlParams    AS ANY _
    ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ControlServiceEx LIB "AdvApi32.dll" _
    ALIAS "ControlServiceExW" ( _
    BYVAL hService    AS DWORD, _
    BYVAL dwControl   AS DWORD, _
    BYVAL dwInfoLevel AS DWORD, _
    pControlParams    AS ANY _
    ) AS LONG
#ELSE
DECLARE FUNCTION ControlServiceEx LIB "AdvApi32.dll" _
    ALIAS "ControlServiceExA" ( _
    BYVAL hService    AS DWORD, _
    BYVAL dwControl   AS DWORD, _
    BYVAL dwInfoLevel AS DWORD, _
    pControlParams    AS ANY _
    ) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' NTDDI_VERSION >= NTDDI_VISTA
