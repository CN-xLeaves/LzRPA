'------------------------------------------------------------------------------
'
'  PowrProf.inc -- Common includes for the Power Policy applicator
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from powrprof.h version 1.0 of 14 Jul 2009
'------------------------------------------------------------------------------


#INCLUDE THIS ONCE

%POWRPROF_INC = 1

#INCLUDE "WinNT.inc"



' Registry storage structures for the GLOBAL_POWER_POLICY data. There are two
' structures, GLOBAL_MACHINE_POWER_POLICY and GLOBAL_USER_POWER_POLICY. the
' GLOBAL_MACHINE_POWER_POLICY stores per machine data for which there is no UI.
' GLOBAL_USER_POWER_POLICY stores the per user data.

TYPE GLOBAL_MACHINE_POWER_POLICY
    Revision      AS DWORD
    LidOpenWakeAc AS LONG  ' SYSTEM_POWER_STATE
    LidOpenWakeDc AS LONG  ' SYSTEM_POWER_STATE
    BroadcastCapacityResolution AS DWORD
END TYPE

TYPE GLOBAL_USER_POWER_POLICY
    Revision      AS DWORD
    PowerButtonAc AS POWER_ACTION_POLICY
    PowerButtonDc AS POWER_ACTION_POLICY
    SleepButtonAc AS POWER_ACTION_POLICY
    SleepButtonDc AS POWER_ACTION_POLICY
    LidCloseAc    AS POWER_ACTION_POLICY
    LidCloseDc    AS POWER_ACTION_POLICY
    DischargePolicy(0 TO %NUM_DISCHARGE_POLICIES - 1) AS SYSTEM_POWER_LEVEL
    GlobalFlags   AS DWORD
END TYPE

' Structure to manage global power policies at the user level. This structure
' contains data which is common across all power policy profiles.

TYPE GLOBAL_POWER_POLICY
    user AS GLOBAL_USER_POWER_POLICY
    mach AS GLOBAL_MACHINE_POWER_POLICY
END TYPE


' Registry storage structures for the POWER_POLICY data. There are three
' structures, MACHINE_POWER_POLICY, MACHINE_PROCESSOR_POWER_POLICY and USER_POWER_POLICY. the
' MACHINE_POWER_POLICY stores per machine data for which there is no UI.
' USER_POWER_POLICY stores the per user data.

TYPE MACHINE_POWER_POLICY
    Revision        AS DWORD                          ' 1

    ' meaning of power action "sleep"
    MinSleepAc            AS LONG  ' SYSTEM_POWER_STATE
    MinSleepDc            AS LONG  ' SYSTEM_POWER_STATE
    ReducedLatencySleepAc AS LONG  ' SYSTEM_POWER_STATE
    ReducedLatencySleepDc AS LONG  ' SYSTEM_POWER_STATE

    ' parameters for dozing
    DozeTimeoutAc   AS DWORD
    DozeTimeoutDc   AS DWORD
    DozeS4TimeoutAc AS DWORD
    DozeS4TimeoutDc AS DWORD

    ' processor policies
    MinThrottleAc   AS BYTE
    MinThrottleDc   AS BYTE
    pad1(0 TO 1)    AS BYTE
    OverThrottledAc AS POWER_ACTION_POLICY
    OverThrottledDc AS POWER_ACTION_POLICY
END TYPE


'
' deprecated
'
TYPE MACHINE_PROCESSOR_POWER_POLICY
    Revision          AS DWORD                          ' 1
    ProcessorPolicyAC AS PROCESSOR_POWER_POLICY
    ProcessorPolicyDC AS PROCESSOR_POWER_POLICY
END TYPE


TYPE USER_POWER_POLICY
    Revision           AS DWORD                          ' 1

    ' "system idle" detection
    IdleAc             AS POWER_ACTION_POLICY
    IdleDc             AS POWER_ACTION_POLICY
    IdleTimeoutAc      AS DWORD
    IdleTimeoutDc      AS DWORD
    IdleSensitivityAc  AS BYTE
    IdleSensitivityDc  AS BYTE

    ' Throttling Policy
    ThrottlePolicyAc   AS BYTE
    ThrottlePolicyDc   AS BYTE

    ' meaning of power action "sleep"
    MaxSleepAc         AS LONG  ' SYSTEM_POWER_STATE
    MaxSleepDc         AS LONG  ' SYSTEM_POWER_STATE

    ' For future use
    Reserved(0 TO 1)   AS DWORD

    ' video policies
    VideoTimeoutAc     AS DWORD
    VideoTimeoutDc     AS DWORD

    ' hard disk policies
    SpindownTimeoutAc  AS DWORD
    SpindownTimeoutDc  AS DWORD

    ' processor policies
    OptimizeForPowerAc AS BYTE
    OptimizeForPowerDc AS BYTE
    FanThrottleToleranceAc AS BYTE
    FanThrottleToleranceDc AS BYTE
    ForcedThrottleAc   AS BYTE
    ForcedThrottleDc   AS BYTE
END TYPE


' Structure to manage power policies at the user level. This structure
' contains data which is unique across power policy profiles.

TYPE POWER_POLICY
    user AS USER_POWER_POLICY
    mach AS MACHINE_POWER_POLICY
END TYPE


' Constants for GlobalFlags

%EnableSysTrayBatteryMeter = &H01
%EnableMultiBatteryDisplay = &H02
%EnablePasswordLogon       = &H04
%EnableWakeOnRing          = &H08
%EnableVideoDimDisplay     = &H10

' This constant is passed as a uiID to WritePwrScheme.
%NEWSCHEME = &H0FFFFFFFF  ' (DWORD)-1

' Prototype for EnumPwrSchemes callback procedures.

'DECLARE FUNCTION PWRSCHEMESENUMPROC_V1 (BYVAL Index AS DWORD, _
'    BYVAL NameSize AS DWORD, Name AS ASCIIZ, _
'    BYVAL DescriptionSize AS DWORD, Description AS ASCIIZ, _
'    Policy AS POWER_POLICY, Context AS LONG) AS LONG
'
'DECLARE FUNCTION PWRSCHEMESENUMPROC_V2 (BYVAL Index AS DWORD, _
'    BYVAL NameSize AS DWORD, Name AS WSTRINGZ, _
'    BYVAL DescriptionSize AS DWORD, Description AS WSTRINGZ, _
'    Policy AS POWER_POLICY, Context AS LONG) AS LONG
'
'#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
'DECLARE FUNCTION PWRSCHEMESENUMPROC (BYVAL u AS DWORD, BYVAL d1 AS DWORD, _
'    psz AS WSTRINGZ, BYVAL d2 AS DWORD, psz2 AS WSTRINGZ, _
'    ppp AS POWER_POLICY, BYVAL l AS LONG) AS BYTE
'#ELSEIF %DEF(%UNICODE)
'DECLARE FUNCTION PWRSCHEMESENUMPROC (BYVAL u AS DWORD, BYVAL d1 AS DWORD, _
'    psz AS WSTRINGZ, BYVAL d2 AS DWORD, psz2 AS WSTRINGZ, _
'    ppp AS POWER_POLICY, BYVAL l AS LONG) AS BYTE
'#ELSE
'DECLARE FUNCTION PWRSCHEMESENUMPROC (BYVAL u AS DWORD, BYVAL d1 AS DWORD, _
'    psz AS ASCIIZ, BYVAL d2 AS DWORD, psz2 AS ASCIIZ, _
'    ppp AS POWER_POLICY, BYVAL l AS LONG) AS BYTE
'#ENDIF
'
'DECLARE FUNCTION PFNNTINITIATEPWRACTION (BYVAL l1 AS LONG, BYVAL sps AS LONG, _
'    BYVAL d AS DWORD, BYVAL l2 AS LONG) AS BYTE

' Public function prototypes

DECLARE FUNCTION GetPwrDiskSpindownRange LIB "PowrProf.dll" _
    ALIAS "GetPwrDiskSpindownRange" (RangeMax AS DWORD, RangeMin AS DWORD) _
    AS BYTE

DECLARE FUNCTION EnumPwrSchemes LIB "PowrProf.dll" ALIAS "EnumPwrSchemes" _
    (BYVAL lpfnPwrSchemesEnumProc AS DWORD, BYVAL lParam AS LONG) AS BYTE

DECLARE FUNCTION ReadGlobalPwrPolicy LIB "PowrProf.dll" _
    ALIAS "ReadGlobalPwrPolicy" (pGlobalPowerPolicy AS GLOBAL_POWER_POLICY) _
    AS BYTE

DECLARE FUNCTION ReadPwrScheme LIB "PowrProf.dll" ALIAS "ReadPwrScheme" _
    (BYVAL uiID AS DWORD, pPowerPolicy AS POWER_POLICY) AS BYTE

DECLARE FUNCTION WritePwrScheme LIB "PowrProf.dll" ALIAS "WritePwrScheme" _
    (puiID AS DWORD, lpszName AS WSTRINGZ, lpszDescription AS WSTRINGZ, _
    pPowerPolicy AS POWER_POLICY) AS BYTE

DECLARE FUNCTION WriteGlobalPwrPolicy LIB "PowrProf.dll" _
    ALIAS "WriteGlobalPwrPolicy" (pGlobalPowerPolicy AS GLOBAL_POWER_POLICY) _
    AS BYTE

DECLARE FUNCTION DeletePwrScheme LIB "PowrProf.dll" ALIAS "DeletePwrScheme" _
    (BYVAL uiIndex AS DWORD) AS BYTE

DECLARE FUNCTION GetActivePwrScheme LIB "PowrProf.dll" _
    ALIAS "GetActivePwrScheme" (puiID AS DWORD) AS BYTE

DECLARE FUNCTION SetActivePwrScheme LIB "PowrProf.dll" _
    ALIAS "SetActivePwrScheme" (BYVAL uiID AS DWORD, _
    pGlobalPowerPolicy AS GLOBAL_POWER_POLICY, pPowerPolicy AS POWER_POLICY) _
    AS LONG

DECLARE FUNCTION GetPwrCapabilities LIB "PowrProf.dll" _
    ALIAS "GetPwrCapabilities" _
    (pSystemPowerCapabilities AS SYSTEM_POWER_CAPABILITIES) AS BYTE

DECLARE FUNCTION IsPwrSuspendAllowed LIB "PowrProf.dll" _
    ALIAS "IsPwrSuspendAllowed" () AS BYTE

DECLARE FUNCTION IsPwrHibernateAllowed LIB "PowrProf.dll" _
    ALIAS "IsPwrHibernateAllowed" () AS BYTE

DECLARE FUNCTION IsPwrShutdownAllowed LIB "PowrProf.dll" _
    ALIAS "IsPwrShutdownAllowed" () AS BYTE

' [undocumented function]
DECLARE FUNCTION IsAdminOverrideActive LIB "PowrProf.dll" _
    ALIAS "IsAdminOverrideActive" _
    (pAdministratorPowerPolicy AS ADMINISTRATOR_POWER_POLICY) AS BYTE

DECLARE FUNCTION SetSuspendState LIB "PowrProf.dll" ALIAS "SetSuspendState" _
    (BYVAL Hibernate AS LONG, BYVAL ForceCritical AS LONG, _
    BYVAL DisableWakeEvent AS LONG) AS BYTE

DECLARE FUNCTION GetCurrentPowerPolicies LIB "PowrProf.dll" _
    ALIAS "GetCurrentPowerPolicies" _
    (pGlobalPowerPolicy AS GLOBAL_POWER_POLICY, pPowerPolicy AS POWER_POLICY) _
    AS LONG

DECLARE FUNCTION CanUserWritePwrScheme LIB "PowrProf.dll" _
    ALIAS "CanUserWritePwrScheme" () AS BYTE

#IF (%NTDDI_VERSION >= %NTDDI_WINXP) ' Windows XP Version
'
' deprecated.
'
DECLARE FUNCTION ReadProcessorPwrScheme LIB "PowrProf.dll" _
    ALIAS "ReadProcessorPwrScheme" (BYVAL uiID AS DWORD, _
    pMachineProcessorPowerPolicy AS MACHINE_PROCESSOR_POWER_POLICY) AS BYTE

'
' deprecated.
'
DECLARE FUNCTION WriteProcessorPwrScheme LIB "PowrProf.dll" _
    ALIAS "WriteProcessorPwrScheme" (BYVAL uiID AS DWORD, _
    pMachineProcessorPowerPolicy AS MACHINE_PROCESSOR_POWER_POLICY) AS BYTE
#ENDIF  ' (%NTDDI_VERSION >= %NTDDI_WINXP) ' Windows XP Version

' [undocumented function]
DECLARE FUNCTION ValidatePowerPolicies LIB "PowrProf.dll" _
    ALIAS "ValidatePowerPolicies" (pGlobalPowerPolicy AS GLOBAL_POWER_POLICY, _
    pPowerPolicy AS POWER_POLICY) AS BYTE

DECLARE FUNCTION CallNtPowerInformation LIB "PowrProf.dll" _
    ALIAS "CallNtPowerInformation" _
    (BYVAL InformationLevel AS LONG, BYVAL pvin AS DWORD, _
    BYVAL cbIn AS DWORD, BYVAL pvout AS DWORD, BYVAL cbOut AS DWORD) AS LONG


#IF %NTDDI_VERSION >= %NTDDI_VISTA
'
' Enum which defines which field inside of a
' power setting is being accessed.
'
MACRO POWER_DATA_ACCESSOR_enum=LONG
ENUM POWER_DATA_ACCESSOR SINGULAR

    '
    ' Used by read/write and enumeration engines
    '
    ACCESS_AC_POWER_SETTING_INDEX   = 0
    ACCESS_DC_POWER_SETTING_INDEX
    ACCESS_FRIENDLY_NAME
    ACCESS_DESCRIPTION
    ACCESS_POSSIBLE_POWER_SETTING
    ACCESS_POSSIBLE_POWER_SETTING_FRIENDLY_NAME
    ACCESS_POSSIBLE_POWER_SETTING_DESCRIPTION
    ACCESS_DEFAULT_AC_POWER_SETTING
    ACCESS_DEFAULT_DC_POWER_SETTING
    ACCESS_POSSIBLE_VALUE_MIN
    ACCESS_POSSIBLE_VALUE_MAX
    ACCESS_POSSIBLE_VALUE_INCREMENT
    ACCESS_POSSIBLE_VALUE_UNITS
    ACCESS_ICON_RESOURCE
    ACCESS_DEFAULT_SECURITY_DESCRIPTOR
    ACCESS_ATTRIBUTES

    '
    ' Used by enumeration engine.
    '
    ACCESS_SCHEME
    ACCESS_SUBGROUP
    ACCESS_INDIVIDUAL_SETTING

    '
    ' Used by access check
    '
    ACCESS_ACTIVE_SCHEME
    ACCESS_CREATE_SCHEME

    '
    ' Used by override ranges.
    '

    ACCESS_AC_POWER_SETTING_MAX
    ACCESS_DC_POWER_SETTING_MAX
    ACCESS_AC_POWER_SETTING_MIN
    ACCESS_DC_POWER_SETTING_MIN
END ENUM

'
' =========================================
' Power Scheme APIs
' =========================================
'

#IF NOT %DEF(%HPOWERNOTIFY_DEF)

%HPOWERNOTIFY_DEF = 1

'typedef  PVOID           HPOWERNOTIFY;
'typedef  HPOWERNOTIFY   *PHPOWERNOTIFY;

#ENDIF

#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
DECLARE FUNCTION PowerSettingRegisterNotification LIB "PowrProf.dll" _
    ALIAS "PowerSettingRegisterNotification" ( _
    SettingGuid AS GUID, _
    BYVAL Flags AS DWORD, _
    BYVAL Recipient AS DWORD, _  ' HANDLE
    RegistrationHandle AS ANY _  ' PHPOWERNOTIFY
    ) AS LONG
#ENDIF

#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
DECLARE FUNCTION PowerSettingUnregisterNotification LIB "PowrProf.dll" _
    ALIAS "PowerSettingUnregisterNotification" ( _
    RegistrationHandle AS ANY _  ' HPOWERNOTIFY
    ) AS DWORD
#ENDIF

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
DECLARE FUNCTION PowerSettingAccessCheck LIB "PowrProf.dll" _
    ALIAS "PowerSettingAccessCheck" ( _
    BYVAL AccessFlags AS POWER_DATA_ACCESSOR_enum, _
    PowerGuid AS GUID _
    ) AS DWORD
#ENDIF



'
' Read functions.
'

DECLARE FUNCTION PowerReadACValueIndex LIB "PowrProf.dll" _
    ALIAS "PowerReadACValueIndex" (BYVAL RootPowerKey AS DWORD, _
    SchemeGuid AS GUID, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, AcValueIndex AS DWORD) AS DWORD

DECLARE FUNCTION PowerReadDCValueIndex LIB "PowrProf.dll" _
    ALIAS "PowerReadDCValueIndex" (BYVAL RootPowerKey AS DWORD, _
    SchemeGuid AS GUID, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, DcValueIndex AS DWORD) AS DWORD

DECLARE FUNCTION PowerReadACValue LIB "PowrProf.dll" ALIAS "PowerReadACValue" _
    (BYVAL RootPowerKey AS DWORD, SchemeGuid AS GUID, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID, _
    dType AS DWORD, bBuffer AS DWORD, BufferSize AS DWORD) AS DWORD

DECLARE FUNCTION PowerReadDCValue LIB "PowrProf.dll" ALIAS "PowerReadDCValue" _
    (BYVAL RootPowerKey AS DWORD, SchemeGuid AS GUID, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID, _
    dType AS DWORD, bBuffer AS DWORD, BufferSize AS DWORD) AS DWORD

DECLARE FUNCTION PowerReadFriendlyName LIB "PowrProf.dll" _
    ALIAS "PowerReadFriendlyName" (BYVAL RootPowerKey AS DWORD, _
    SchemeGuid AS GUID, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, bBuffer AS DWORD, BufferSize AS DWORD) AS DWORD

DECLARE FUNCTION PowerReadDescription LIB "PowrProf.dll" _
    ALIAS "PowerReadDescription" (BYVAL RootPowerKey AS DWORD, _
    SchemeGuid AS GUID, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, bBuffer AS DWORD, BufferSize AS DWORD) AS DWORD

DECLARE FUNCTION PowerReadPossibleValue LIB "PowrProf.dll" _
    ALIAS "PowerReadPossibleValue" (BYVAL RootPowerKey AS DWORD, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID, _
    dType AS DWORD, BYVAL PossibleSettingIndex AS DWORD, _
    bBuffer AS DWORD, BufferSize AS DWORD) AS DWORD

DECLARE FUNCTION PowerReadPossibleFriendlyName LIB "PowrProf.dll" _
    ALIAS "PowerReadPossibleFriendlyName" (BYVAL RootPowerKey AS DWORD, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID, _
    BYVAL PossibleSettingIndex AS DWORD, _
    bBuffer AS DWORD, BufferSize AS DWORD) AS DWORD

DECLARE FUNCTION PowerReadPossibleDescription LIB "PowrProf.dll" _
    ALIAS "PowerReadPossibleDescription" (BYVAL RootPowerKey AS DWORD, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID, _
    BYVAL PossibleSettingIndex AS DWORD, _
    bBuffer AS DWORD, BufferSize AS DWORD) AS DWORD

DECLARE FUNCTION PowerReadValueMin LIB "PowrProf.dll" _
    ALIAS "PowerReadValueMin" _
    (BYVAL RootPowerKey AS DWORD, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, ValueMinimum AS DWORD) AS DWORD

DECLARE FUNCTION PowerReadValueMax LIB "PowrProf.dll" ALIAS "PowerReadValueMax" _
    (BYVAL RootPowerKey AS DWORD, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, ValueMaximum AS DWORD) AS DWORD

DECLARE FUNCTION PowerReadValueIncrement LIB "PowrProf.dll" _
    ALIAS "PowerReadValueIncrement" _
    (BYVAL RootPowerKey AS DWORD, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, ValueIncrement AS DWORD) AS DWORD

DECLARE FUNCTION PowerReadValueUnitsSpecifier LIB "PowrProf.dll" _
    ALIAS "PowerReadValueUnitsSpecifier" _
    (BYVAL RootPowerKey AS DWORD, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, bBuffer AS DWORD, BufferSize AS DWORD) AS DWORD

DECLARE FUNCTION PowerReadACDefaultIndex LIB "PowrProf.dll" _
    ALIAS "PowerReadACDefaultIndex" _
    (BYVAL RootPowerKey AS DWORD, SchemePersonalityGuid AS GUID, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID, _
    AcDefaultIndex AS DWORD) AS DWORD

DECLARE FUNCTION PowerReadDCDefaultIndex LIB "PowrProf.dll" _
    ALIAS "PowerReadDCDefaultIndex" _
    (BYVAL RootPowerKey AS DWORD, SchemePersonalityGuid AS GUID, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID, _
    DcDefaultIndex AS DWORD) AS DWORD

DECLARE FUNCTION PowerReadIconResourceSpecifier LIB "PowrProf.dll" _
    ALIAS "PowerReadIconResourceSpecifier" (BYVAL RootPowerKey AS DWORD, _
    SchemeGuid AS GUID, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, _
    bBuffer AS DWORD, BufferSize AS DWORD) AS DWORD

DECLARE FUNCTION PowerReadSettingAttributes LIB "PowrProf.dll" _
    ALIAS "PowerReadSettingAttributes" (SubGroupGuid AS GUID, _
    PowerSettingGuid AS GUID) AS DWORD

'
' Write functions.
'

DECLARE FUNCTION PowerWriteACValueIndex LIB "PowrProf.dll" _
    ALIAS "PowerWriteACValueIndex" (BYVAL RootPowerKey AS DWORD, _
    SchemeGuid AS GUID, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, BYVAL AcValueIndex AS DWORD) AS DWORD

DECLARE FUNCTION PowerWriteDCValueIndex LIB "PowrProf.dll" _
    ALIAS "PowerWriteDCValueIndex" (BYVAL RootPowerKey AS DWORD, _
    SchemeGuid AS GUID, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, BYVAL DcValueIndex AS DWORD) AS DWORD

DECLARE FUNCTION PowerWriteFriendlyName LIB "PowrProf.dll" _
    ALIAS "PowerWriteFriendlyName" (BYVAL RootPowerKey AS DWORD, _
    SchemeGuid AS GUID, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, bBuffer AS DWORD, BYVAL BufferSize AS DWORD) _
    AS DWORD

DECLARE FUNCTION PowerWriteDescription LIB "PowrProf.dll" _
    ALIAS "PowerWriteDescription" (BYVAL RootPowerKey AS DWORD, _
    SchemeGuid AS GUID, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, bBuffer AS DWORD, BYVAL BufferSize AS DWORD) _
    AS DWORD

DECLARE FUNCTION PowerWritePossibleValue LIB "PowrProf.dll" _
    ALIAS "PowerWritePossibleValue" (BYVAL RootPowerKey AS DWORD, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID, _
    dType AS DWORD, BYVAL PossibleSettingIndex AS DWORD, _
    bBuffer AS DWORD, BYVAL BufferSize AS DWORD) AS DWORD

DECLARE FUNCTION PowerWritePossibleFriendlyName LIB "PowrProf.dll" _
    ALIAS "PowerWritePossibleFriendlyName" (BYVAL RootPowerKey AS DWORD, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID, _
    BYVAL PossibleSettingIndex AS DWORD, _
    bBuffer AS DWORD, BYVAL BufferSize AS DWORD) AS DWORD

DECLARE FUNCTION PowerWritePossibleDescription LIB "PowrProf.dll" _
    ALIAS "PowerWritePossibleDescription" (BYVAL RootPowerKey AS DWORD, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID, _
    BYVAL PossibleSettingIndex AS DWORD, _
    bBuffer AS DWORD, BYVAL BufferSize AS DWORD) AS DWORD

DECLARE FUNCTION PowerWriteValueMin LIB "PowrProf.dll" _
    ALIAS "PowerWriteValueMin" _
    (BYVAL RootPowerKey AS DWORD, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, BYVAL ValueMinimum AS DWORD) AS DWORD

DECLARE FUNCTION PowerWriteValueMax LIB "PowrProf.dll" ALIAS "PowerWriteValueMax" _
    (BYVAL RootPowerKey AS DWORD, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, BYVAL ValueMaximum AS DWORD) AS DWORD

DECLARE FUNCTION PowerWriteValueIncrement LIB "PowrProf.dll" _
    ALIAS "PowerWriteValueIncrement" _
    (BYVAL RootPowerKey AS DWORD, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, BYVAL ValueIncrement AS DWORD) AS DWORD

DECLARE FUNCTION PowerWriteValueUnitsSpecifier LIB "PowrProf.dll" _
    ALIAS "PowerWriteValueUnitsSpecifier" _
    (BYVAL RootPowerKey AS DWORD, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, bBuffer AS DWORD, BYVAL BufferSize AS DWORD) _
    AS DWORD

DECLARE FUNCTION PowerWriteACDefaultIndex LIB "PowrProf.dll" _
    ALIAS "PowerWriteACDefaultIndex" _
    (BYVAL RootPowerKey AS DWORD, SchemePersonalityGuid AS GUID, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID, _
    BYVAL AcDefaultIndex AS DWORD) AS DWORD

DECLARE FUNCTION PowerWriteDCDefaultIndex LIB "PowrProf.dll" _
    ALIAS "PowerWriteDCDefaultIndex" _
    (BYVAL RootPowerKey AS DWORD, SchemePersonalityGuid AS GUID, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID, _
    BYVAL DcDefaultIndex AS DWORD) AS DWORD

DECLARE FUNCTION PowerWriteIconResourceSpecifier LIB "PowrProf.dll" _
    ALIAS "PowerWriteIconResourceSpecifier" (BYVAL RootPowerKey AS DWORD, _
    SchemeGuid AS GUID, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, _
    bBuffer AS DWORD, BYVAL BufferSize AS DWORD) AS DWORD

DECLARE FUNCTION PowerWriteSettingAttributes LIB "PowrProf.dll" _
    ALIAS "PowerWriteSettingAttributes" (SubGroupGuid AS GUID, _
    PowerSettingGuid AS GUID, BYVAL Attributes AS DWORD) AS DWORD

DECLARE FUNCTION PowerDuplicateScheme LIB "PowrProf.dll" _
    ALIAS "PowerDuplicateScheme" (BYVAL RootPowerKey AS DWORD, _
    SourceSchemeGuid AS GUID, DestinationSchemeGuid AS DWORD) AS DWORD

DECLARE FUNCTION PowerImportPowerScheme LIB "PowrProf.dll" _
    ALIAS "PowerImportPowerScheme" (BYVAL RootPowerKey AS DWORD, _
    ImportFileNamePath AS WSTRINGZ, DestinationSchemeGuid AS DWORD) AS DWORD

DECLARE FUNCTION PowerDeleteScheme LIB "PowrProf.dll" _
    ALIAS "PowerDeleteScheme" (BYVAL RootPowerKey AS DWORD, _
    SchemeGuid AS GUID) AS DWORD

DECLARE FUNCTION PowerRemovePowerSetting LIB "PowrProf.dll" _
    ALIAS "PowerRemovePowerSetting" (PowerSettingSubKeyGuid AS GUID, _
    PowerSettingGuid AS GUID) AS DWORD

DECLARE FUNCTION PowerCreateSetting LIB "PowrProf.dll" _
    ALIAS "PowerCreateSetting" (BYVAL RootSystemPowerKey AS DWORD, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID) AS DWORD

DECLARE FUNCTION PowerCreatePossibleSetting LIB "PowrProf.dll" _
    ALIAS "PowerCreatePossibleSetting" (BYVAL RootSystemPowerKey AS DWORD, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID, _
    PossibleSettingIndex AS DWORD) AS DWORD

'
' Enumerate Functions.
'
DECLARE FUNCTION PowerEnumerate LIB "PowrProf.dll" ALIAS "PowerEnumerate" _
    (BYVAL RootPowerKey AS DWORD, SchemeGuid AS GUID, _
    SubGroupOfPowerSettingsGuid AS GUID, _
    BYVAL AccessFlags AS POWER_DATA_ACCESSOR_enum, _
    BYVAL nIndex AS DWORD, Buffer AS DWORD, BufferSize AS DWORD) AS DWORD

'
' Activate Functions.
'
DECLARE FUNCTION PowerSetActiveScheme LIB "PowrProf.dll" _
    ALIAS "PowerSetActiveScheme" (BYVAL UserRootPowerKey AS DWORD, _
    SchemeGuid AS GUID) AS DWORD

DECLARE FUNCTION PowerGetActiveScheme LIB "PowrProf.dll" _
    ALIAS "PowerGetActiveScheme" (BYVAL UserRootPowerKey AS DWORD, _
    SchemeGuid AS DWORD) AS DWORD

DECLARE FUNCTION PowerOpenUserPowerKey LIB "PowrProf.dll" _
    ALIAS "PowerOpenUserPowerKey" (phUserPowerKey AS DWORD, _
    BYVAL nAccess AS DWORD, BYVAL OpenExisting AS LONG) AS DWORD

DECLARE FUNCTION PowerOpenSystemPowerKey LIB "PowrProf.dll" _
    ALIAS "PowerOpenSystemPowerKey" (phSystemPowerKey AS DWORD, _
    BYVAL nAccess AS DWORD, BYVAL OpenExisting AS LONG) AS DWORD

DECLARE FUNCTION PowerCanRestoreIndividualDefaultPowerScheme _
    LIB "PowrProf.dll" ALIAS "PowerCanRestoreIndividualDefaultPowerScheme" _
    (SchemeGuid AS GUID) AS DWORD

DECLARE FUNCTION PowerRestoreIndividualDefaultPowerScheme _
    LIB "PowrProf.dll" ALIAS "PowerRestoreIndividualDefaultPowerScheme" _
    (SchemeGuid AS GUID) AS DWORD

DECLARE FUNCTION PowerRestoreDefaultPowerSchemes LIB "PowrProf.dll" _
    ALIAS "PowerRestoreDefaultPowerSchemes" () AS DWORD

DECLARE FUNCTION PowerReplaceDefaultPowerSchemes LIB "PowrProf.dll" _
    ALIAS "PowerReplaceDefaultPowerSchemes" () AS DWORD

DECLARE FUNCTION PowerDeterminePlatformRole LIB "PowrProf.dll" _
    ALIAS "PowerDeterminePlatformRole" () AS LONG

#ENDIF ' #if (NTDDI_VERSION >= NTDDI_VISTA)




#IF %NTDDI_VERSION >= %NTDDI_WS03 ' Windows server03

'
' =========================================
' Device Power APIs
' =========================================
'
'
' ========================================================
' These flags tell us how to interpret a query of
' device power.  Use these (or a combination of these)
' for the QueryInterpretationFlags parameter sent into
' DevicePowerEnumDevices().
'
' They'll ask us for some devices that supports some
' D state.  These flags help us determine what the
' user really wants.  I.e. does he want the device
' name, or the hardware ID.  Does he want some device
' that supports some D state, or does he want us to
' go see if that devices supports some S state? ...
' ========================================================
'

'
' Return HardwareID instead of the friendly device name, which
' is the default.
'
%DEVICEPOWER_HARDWAREID             = &H80000000???

'
'
' 'and' the requested power states.  I.e. if the user requested
' that we query devices supporting D1 and D3, this flag says
' "give me devices that support D1 *and* D3".  Without this
' flag, the query would be interpreted as "give me devices
' that support D1 *or* D3".
'
%DEVICEPOWER_AND_OPERATION          = &H40000000

' Only preform the query on devices that are present in the system.
'
%DEVICEPOWER_FILTER_DEVICES_PRESENT = &H20000000

'
' Only preform the query on devices that are actual hardware.
'
%DEVICEPOWER_FILTER_HARDWARE        = &H10000000

'
' Only preform the query on devices that are armed to wake the
' system from a sleep state.
'
%DEVICEPOWER_FILTER_WAKEENABLED     = &H08000000

'
' Only preform the query on devices that are capable of being programmed
' to wake the system from a sleep state.
'
%DEVICEPOWER_FILTER_WAKEPROGRAMMABLE = &H04000000

'
' Go find the device who's name is specifed by an input
' parameter, then see if it's got the capabilities specified
' in QueryFlags.
'
%DEVICEPOWER_FILTER_ON_NAME         = &H02000000



'
' Define flags to set/clear capabilities in the devices.
'

'
' Enable the device to wake the system from a sleep state.
'
%DEVICEPOWER_SET_WAKEENABLED = &H00000001

'
' Disable the device from waking the system from a sleep
' state.
'
%DEVICEPOWER_CLEAR_WAKEENABLED = &H00000002




'
' For the QueryFlags parameter, the user should send in
' one of the PDCAP_D*_SUPPORTED flags found in ntpoapi.h.
'
' %PDCAP_D0_SUPPORTED              = &H00000001
' %PDCAP_D1_SUPPORTED              = &H00000002
' %PDCAP_D2_SUPPORTED              = &H00000004
' %PDCAP_D3_SUPPORTED              = &H00000008
' %PDCAP_WAKE_FROM_D0_SUPPORTED    = &H00000010
' %PDCAP_WAKE_FROM_D1_SUPPORTED    = &H00000020
' %PDCAP_WAKE_FROM_D2_SUPPORTED    = &H00000040
' %PDCAP_WAKE_FROM_D3_SUPPORTED    = &H00000080
' %PDCAP_WARM_EJECT_SUPPORTED      = &H00000100
'
' The user can also send in a combination of these values
' to do queries that match either or both of the specified
' flags.  E.g. if the user used (PDCAP_D1_SUPPORTED | PDCAP_D3_SUPPORTED),
' then the query would return a device that supported *either*
' D1 or D3.  The user could specify QUERY_AND_OPERATION in
' QueryInterpretationFlags to get a device that supported
' D1 *and* D3.
'

'
' We also support querying on S states.  Although devices don't
' really understand system states, we can use the D-to-S state
' mappings to derive this.  For example, if we ask a device if
' he supports S2, we can derive that by looking at his D-to-S
' mappings.  Suppose the device has a D-to-S state mapping
' that looks like this:
' S0 -> D0
' S1 -> D3
' S2 -> D3
' S3 -> D3
' S4 -> D3
' S5 -> D3
'
' We see that S2 maps to D3 on this device.  Does this device
' actually support D3?  We can find that out.  If so, then we
' say that this device supports S2.
'
' We have to make up the S-state vectors because there's no
' existing values like the PDCAP_D* values.
'
%PDCAP_S0_SUPPORTED              = &H00010000
%PDCAP_S1_SUPPORTED              = &H00020000
%PDCAP_S2_SUPPORTED              = &H00040000
%PDCAP_S3_SUPPORTED              = &H00080000
%PDCAP_WAKE_FROM_S0_SUPPORTED    = &H00100000
%PDCAP_WAKE_FROM_S1_SUPPORTED    = &H00200000
%PDCAP_WAKE_FROM_S2_SUPPORTED    = &H00400000
%PDCAP_WAKE_FROM_S3_SUPPORTED    = &H00800000
%PDCAP_S4_SUPPORTED              = &H01000000
%PDCAP_S5_SUPPORTED              = &H02000000


'
' Function prototypes
'

DECLARE FUNCTION DevicePowerEnumDevices ( _
    BYVAL QueryIndex               AS DWORD, _
    BYVAL QueryInterpretationFlags AS DWORD, _
    BYVAL QueryFlags               AS DWORD, _
    BYVAL pReturnBuffer            AS BYTE PTR, _
    pBufferSize                    AS DWORD _
    ) AS BYTE

DECLARE FUNCTION DevicePowerSetDeviceStats ( _
    DeviceDescription AS WSTRINGZ, _
    BYVAL SetFlags    AS DWORD, _
    SetData           AS ANY _
    ) AS DWORD

DECLARE FUNCTION DevicePowerOpen ( _
    BYVAL DebugMask AS DWORD _
    ) AS BYTE


DECLARE FUNCTION DevicePowerClose () AS BYTE



#ENDIF  ' (NTDDI_VERSION >= NTDDI_WS03) Windows server03 version
