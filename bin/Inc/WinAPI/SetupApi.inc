'------------------------------------------------------------------------------
'
'  SetupApi.inc -- Windows NT Setup and Device Installer services Dll.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from SetupApi.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%INC_SETUPAPI = 1

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "WinReg.inc"

'
' determine version of setupapi based on _WIN32_WINDOWS and %WIN32_WINNT
'
' NT4 version of setupapi   (%WIN32_WINNT_NT4) is earliest, and installed onto Win95 by IE.
' Win2k version of setupapi (%WIN32_WINNT_WIN2K) also shipped in WinME
' we'll use "&H0410" to indicate version of setupapi shipped with Win98
'
#IF NOT %DEF(%SETUPAPI_VER)
#IF %DEF(%WIN32_WINNT) AND (NOT %DEF(%WIN32_WINDOWS) OR (%WIN32_WINNT < %WIN32_WINDOWS))
%SETUPAPI_VER = %WIN32_WINNT  ' SetupAPI version follows Windows NT version
#ELSEIF %DEF(%WIN32_WINDOWS)
#IF %WIN32_WINDOWS >= &H0490
%SETUPAPI_VER = %WIN32_WINNT_WIN2K        ' WinME uses same version of SetupAPI as Win2k
#ELSEIF %WIN32_WINDOWS >= &H0410
%SETUPAPI_VER = &H0410        ' Indicates version of SetupAPI shipped with Win98
#ELSE
%SETUPAPI_VER = %WIN32_WINNT_NT4        ' Earliest SetupAPI version
#ENDIF ' %WIN32_WINDOWS
#ELSE ' %WIN32_WINNT/%WIN32_WINDOWS
%SETUPAPI_VER = %WIN32_WINNT_WINXP
#ENDIF ' %WIN32_WINNT/%WIN32_WINDOWS
#ENDIF ' not %SETUPAPI_VER

'
' Include spapidef.inc for basic definitions and flags
'
#INCLUDE "spapidef.inc"

'
' Include commctrl.inc for our use of HIMAGELIST and wizard support.
'
#INCLUDE "commctrl.inc"

'
' Include devpropdef.inc for our use of DEVPROPERTYKEY and DEVPROPTYPE.
'
#INCLUDE "devpropdef.inc"

'
' Define maximum string length constants
'
%LINE_LEN                    = 256  ' Windows 9x-compatible maximum for
                                    ' displayable strings coming from a
                                    ' device INF.
%MAX_INF_STRING_LENGTH       = 4096 ' Actual maximum size of an INF string
                                    ' (including string substitutions).
%MAX_INF_SECTION_NAME_LENGTH = 255  ' For Windows 9x compatibility, INF
                                    ' section names should be constrained
                                    ' to 32 characters.

%MAX_TITLE_LEN             =  60
%MAX_INSTRUCTION_LEN       = 256
%MAX_LABEL_LEN             =  30
%MAX_SERVICE_NAME_LEN      = 256
%MAX_SUBTITLE_LEN          = 256

'
' Define maximum length of a machine name in the format expected by ConfigMgr32
' CM_Connect_Machine (i.e., "\\MachineName"+$NUL).
'
%SP_MAX_MACHINENAME_LENGTH = (%MAX_PATH + 3)

'
' Define type for reference to loaded inf file
'
MACRO HINF=DWORD

'
' Inf context structure. Applications must not interpret or
' overwrite values in these structures.
'
TYPE INFCONTEXT
    Inf        AS DWORD  ' PVOID
    CurrentInf AS DWORD  ' PVOID
    Section    AS DWORD
    LINE       AS DWORD
END TYPE

'
' Inf file information structure.
'
TYPE SP_INF_INFORMATION
    InfStyle AS DWORD
    InfCount AS DWORD
    VersionData(%ANYSIZE_ARRAY-1) AS BYTE
END TYPE

'
' Define structure for passing alternate platform info into
' SetupSetFileQueueAlternatePlatform and SetupQueryInfOriginalFileInformation.
'
UNION SP_ALTPLATFORM_INFO_V2_union
    Reserved AS WORD  ' for compatibility with V1 structure
    Flags    AS WORD  ' indicates validity of non V1 fields
END UNION

TYPE SP_ALTPLATFORM_INFO_V2
    cbSize AS DWORD
    '
    ' platform to use (VER_PLATFORM_WIN32_WINDOWS or VER_PLATFORM_WIN32_NT)
    '
    Platform AS DWORD
    '
    ' major and minor version numbers to use
    '
    MajorVersion AS DWORD
    MinorVersion AS DWORD
    '
    ' processor architecture to use (PROCESSOR_ARCHITECTURE_INTEL,
    ' PROCESSOR_ARCHITECTURE_AMD64, or PROCESSOR_ARCHITECTURE_IA64.
    '
    ProcessorArchitecture AS WORD

    SP_ALTPLATFORM_INFO_V2_union

    '
    ' specify SP_ALTPLATFORM_FLAGS_VERSION_RANGE in Flags
    ' to use FirstValidatedMajorVersion and FirstValidatedMinorVersion
    '
    ' Major and minor versions of the oldest previous OS for which this
    ' package's digital signature may be considered valid.  For example, say
    ' the alternate platform is VER_PLATFORM_WIN32_NT, version 5.1.  However,
    ' it is wished that driver packages signed with a 5.0 osattr also be
    ' considered valid.  In this case, you'd have a  MajorVersion/MinorVersion
    ' of 5.1, and a FirstValidatedMajorVersion/FirstValidatedMinorVersion of
    ' 5.0.  To validate packages signed for any previous OS release, specify
    ' 0 for these fields.  To only validate against the target alternate
    ' platform, specify the same values as those in the MajorVersion and
    ' MinorVersion fields.
    '
    FirstValidatedMajorVersion AS DWORD
    FirstValidatedMinorVersion AS DWORD

END TYPE  ' SP_ALTPLATFORM_INFO_V2

TYPE SP_ALTPLATFORM_INFO_V1
    cbSize AS DWORD
    '
    ' platform to use (VER_PLATFORM_WIN32_WINDOWS or VER_PLATFORM_WIN32_NT)
    '
    Platform AS DWORD
    '
    ' major and minor version numbers to use
    '
    MajorVersion AS DWORD
    MinorVersion AS DWORD
    '
    ' processor architecture to use (PROCESSOR_ARCHITECTURE_INTEL,
    ' PROCESSOR_ARCHITECTURE_AMD64, or PROCESSOR_ARCHITECTURE_IA64.
    '
    ProcessorArchitecture AS WORD

    Reserved AS WORD ' must be zero.
END TYPE  ' SP_ALTPLATFORM_INFO_V1

#IF %DEF(%USE_SP_ALTPLATFORM_INFO_V1) OR (%SETUPAPI_VER < %WIN32_WINNT_WINXP) ' use version 1 altplatform info data structure

TYPE SP_ALTPLATFORM_INFO
    SP_ALTPLATFORM_INFO_V1
END TYPE

#ELSE                          ' use version 2 altplatform info data structure

TYPE SP_ALTPLATFORM_INFO
    SP_ALTPLATFORM_INFO_V2
END TYPE

'
' the following flags are available to SP_ALTPLATFORM_INFO_V2
'
%SP_ALTPLATFORM_FLAGS_VERSION_RANGE = &H0001  ' FirstValidatedMajor/MinorVersion

#ENDIF  ' use current version of altplatform info data structure


'
' Define structure that is filled in by SetupQueryInfOriginalFileInformation
' to indicate the INF's original name and the original name of the (potentially
' platform-specific) catalog file specified by that INF.
'
TYPE SP_ORIGINAL_FILE_INFO_A
    cbSize              AS DWORD
    OriginalInfName     AS ASCIIZ * %MAX_PATH
    OriginalCatalogName AS ASCIIZ * %MAX_PATH
END TYPE

TYPE SP_ORIGINAL_FILE_INFO_W
    cbSize              AS DWORD
    OriginalInfName     AS WSTRINGZ * %MAX_PATH
    OriginalCatalogName AS WSTRINGZ * %MAX_PATH
END TYPE

#IF %DEF(%UNICODE)
TYPE SP_ORIGINAL_FILE_INFO
    SP_ORIGINAL_FILE_INFO_W
END TYPE
#ELSE
TYPE SP_ORIGINAL_FILE_INFO
    SP_ORIGINAL_FILE_INFO_A
END TYPE
#ENDIF

'
' SP_INF_INFORMATION.InfStyle values
'
%INF_STYLE_NONE         = &H00000000       ' unrecognized or non-existent
%INF_STYLE_OLDNT        = &H00000001       ' winnt 3.x
%INF_STYLE_WIN4         = &H00000002       ' Win95

'
' Additional InfStyle flags that may be specified when calling SetupOpenInfFile.
'
'
%INF_STYLE_CACHE_ENABLE  = &H00000010 ' always cache INF, even outside of %windir%\Inf
%INF_STYLE_CACHE_DISABLE = &H00000020 ' delete cached INF information
#IF %SETUPAPI_VER >= %WIN32_WINNT_WS03
%INF_STYLE_CACHE_IGNORE  = &H00000040 ' ignore any cached INF information
#ENDIF


'
' Target directory specs.
'
%DIRID_ABSOLUTE        = -1              ' real 32-bit -1
%DIRID_ABSOLUTE_16BIT  =  &Hffff??       ' 16-bit -1 for compat w/setupx
%DIRID_NULL            =  0
%DIRID_SRCPATH         =  1
%DIRID_WINDOWS         = 10
%DIRID_SYSTEM          = 11              ' system32
%DIRID_DRIVERS         = 12
%DIRID_IOSUBSYS        = %DIRID_DRIVERS
%DIRID_INF             = 17
%DIRID_HELP            = 18
%DIRID_FONTS           = 20
%DIRID_VIEWERS         = 21
%DIRID_COLOR           = 23
%DIRID_APPS            = 24
%DIRID_SHARED          = 25
%DIRID_BOOT            = 30

%DIRID_SYSTEM16        = 50
%DIRID_SPOOL           = 51
%DIRID_SPOOLDRIVERS    = 52
%DIRID_USERPROFILE     = 53
%DIRID_LOADER          = 54
%DIRID_PRINTPROCESSOR  = 55

%DIRID_DEFAULT         = %DIRID_SYSTEM

'
' The following DIRIDs are for commonly-used shell "special folders".  The
' complete list of such folders is contained in shlobj.h.  In that headerfile,
' each folder is assigned a CSIDL_* value.  The DIRID values below are created
' by taking the CSIDL value in shlobj.h and OR'ing it with &H4000.  Thus, if
' an INF needs to reference other special folders not defined below, it may
' generate one using the above mechanism, and setupapi will automatically deal
' with it and use the corresponding shell's path where appropriate.  (Remember
' that DIRIDs must be specified in decimal, not hex, in an INF when used for
' string substitution.)
'
%DIRID_COMMON_STARTMENU        = 16406  ' All Users\Start Menu
%DIRID_COMMON_PROGRAMS         = 16407  ' All Users\Start Menu\Programs
%DIRID_COMMON_STARTUP          = 16408  ' All Users\Start Menu\Programs\Startup
%DIRID_COMMON_DESKTOPDIRECTORY = 16409  ' All Users\Desktop
%DIRID_COMMON_FAVORITES        = 16415  ' All Users\Favorites
%DIRID_COMMON_APPDATA          = 16419  ' All Users\Application Data

%DIRID_PROGRAM_FILES           = 16422  ' Program Files
%DIRID_SYSTEM_X86              = 16425  ' system32 for WOW
%DIRID_PROGRAM_FILES_X86       = 16426  ' Program Files for WOW
%DIRID_PROGRAM_FILES_COMMON    = 16427  ' Program Files\Common
%DIRID_PROGRAM_FILES_COMMONX86 = 16428  ' x86 Program Files\Common for WOW

%DIRID_COMMON_TEMPLATES        = 16429  ' All Users\Templates
%DIRID_COMMON_DOCUMENTS        = 16430  ' All Users\Documents


'
' First user-definable dirid. See SetupSetDirectoryId().
'
%DIRID_USER            = &H8000??


'
' Setup callback notification routine type
'
DECLARE FUNCTION PSP_FILE_CALLBACK_A (Context AS ANY, _
    BYVAL Notification AS DWORD, BYVAL Param1 AS DWORD, _
    BYVAL Param2 AS DWORD) AS DWORD

DECLARE FUNCTION PSP_FILE_CALLBACK_W (Context AS ANY, _
    BYVAL Notification AS DWORD, BYVAL Param1 AS DWORD, _
    BYVAL Param2 AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION PSP_FILE_CALLBACK (Context AS ANY, _
    BYVAL Notification AS DWORD, BYVAL Param1 AS DWORD, _
    BYVAL Param2 AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION PSP_FILE_CALLBACK (Context AS ANY, _
    BYVAL Notification AS DWORD, BYVAL Param1 AS DWORD, _
    BYVAL Param2 AS DWORD) AS DWORD
#ENDIF


'
' Operation/queue start/end notification. These are ordinal values.
'
%SPFILENOTIFY_STARTQUEUE        = &H00000001
%SPFILENOTIFY_ENDQUEUE          = &H00000002
%SPFILENOTIFY_STARTSUBQUEUE     = &H00000003
%SPFILENOTIFY_ENDSUBQUEUE       = &H00000004
%SPFILENOTIFY_STARTDELETE       = &H00000005
%SPFILENOTIFY_ENDDELETE         = &H00000006
%SPFILENOTIFY_DELETEERROR       = &H00000007
%SPFILENOTIFY_STARTRENAME       = &H00000008
%SPFILENOTIFY_ENDRENAME         = &H00000009
%SPFILENOTIFY_RENAMEERROR       = &H0000000a
%SPFILENOTIFY_STARTCOPY         = &H0000000b
%SPFILENOTIFY_ENDCOPY           = &H0000000c
%SPFILENOTIFY_COPYERROR         = &H0000000d
%SPFILENOTIFY_NEEDMEDIA         = &H0000000e
%SPFILENOTIFY_QUEUESCAN         = &H0000000f
'
' These are used with SetupIterateCabinet().
'
%SPFILENOTIFY_CABINETINFO       = &H00000010
%SPFILENOTIFY_FILEINCABINET     = &H00000011
%SPFILENOTIFY_NEEDNEWCABINET    = &H00000012
%SPFILENOTIFY_FILEEXTRACTED     = &H00000013
%SPFILENOTIFY_FILEOPDELAYED     = &H00000014
'
' These are used for backup operations
'
%SPFILENOTIFY_STARTBACKUP       = &H00000015
%SPFILENOTIFY_BACKUPERROR       = &H00000016
%SPFILENOTIFY_ENDBACKUP         = &H00000017
'
' Extended notification for SetupScanFileQueue(Flags=SPQ_SCAN_USE_CALLBACKEX)
'
%SPFILENOTIFY_QUEUESCAN_EX      = &H00000018

%SPFILENOTIFY_STARTREGISTRATION = &H00000019
%SPFILENOTIFY_ENDREGISTRATION   = &H00000020

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

'
' Extended notification for SetupScanFileQueue(Flags=SPQ_SCAN_USE_CALLBACK_SIGNERINFO)
'
%SPFILENOTIFY_QUEUESCAN_SIGNERINFO = &H00000040

#ENDIF

'
' Copy notification. These are bit flags that may be combined.
'
%SPFILENOTIFY_LANGMISMATCH     = &H00010000
%SPFILENOTIFY_TARGETEXISTS     = &H00020000
%SPFILENOTIFY_TARGETNEWER      = &H00040000

'
' File operation codes and callback outcomes.
'
%FILEOP_COPY                   = 0
%FILEOP_RENAME                 = 1
%FILEOP_DELETE                 = 2
%FILEOP_BACKUP                 = 3

%FILEOP_ABORT                  = 0
%FILEOP_DOIT                   = 1
%FILEOP_SKIP                   = 2
%FILEOP_RETRY                  = %FILEOP_DOIT
%FILEOP_NEWPATH                = 4

'
' Flags in inf copy sections
'
%COPYFLG_WARN_IF_SKIP          = &H00000001  ' warn if user tries to skip file
%COPYFLG_NOSKIP                = &H00000002  ' disallow skipping this file
%COPYFLG_NOVERSIONCHECK        = &H00000004  ' ignore versions and overwrite target
%COPYFLG_FORCE_FILE_IN_USE     = &H00000008  ' force file-in-use behavior
%COPYFLG_NO_OVERWRITE          = &H00000010  ' do not copy if file exists on target
%COPYFLG_NO_VERSION_DIALOG     = &H00000020  ' do not copy if target is newer
%COPYFLG_OVERWRITE_OLDER_ONLY  = &H00000040  ' leave target alone if version same as source
%COPYFLG_PROTECTED_WINDOWS_DRIVER_FILE = &H00000100  ' a Windows driver file
                            ' to be protected as other Windows system files

%COPYFLG_REPLACEONLY           = &H00000400  ' copy only if file exists on target
%COPYFLG_NODECOMP              = &H00000800  ' don't attempt to decompress file; copy as-is
%COPYFLG_REPLACE_BOOT_FILE     = &H00001000  ' file must be present upon reboot (i.e., it's
                                             ' needed by the loader); this flag implies a reboot
%COPYFLG_NOPRUNE               = &H00002000  ' never prune this file
%COPYFLG_IN_USE_TRY_RENAME     = &H00004000  ' If file in use, try to rename the target first

'
' Flags in inf delete sections
' New flags go in high word
'
%DELFLG_IN_USE                 = &H00000001  ' queue in-use file for delete
%DELFLG_IN_USE1                = &H00010000  ' high-word version of %DELFLG_IN_USE

'
' Source and file paths. Used when notifying queue callback
' of SPFILENOTIFY_STARTxxx, SPFILENOTIFY_ENDxxx, and SPFILENOTIFY_xxxERROR.
'
TYPE FILEPATHS_A
    Target     AS ASCIIZ PTR
    SOURCE     AS ASCIIZ PTR   ' not used for delete operations
    Win32Error AS DWORD
    Flags      AS DWORD        ' such as SP_COPY_NOSKIP for copy errors
END TYPE

TYPE FILEPATHS_W
    Target     AS WSTRINGZ PTR
    SOURCE     AS WSTRINGZ PTR ' not used for delete operations
    Win32Error AS DWORD
    Flags      AS DWORD        ' such as SP_COPY_NOSKIP for copy errors
END TYPE

#IF %DEF(%UNICODE)
TYPE FILEPATHS
    FILEPATHS_W
END TYPE
#ELSE
TYPE FILEPATHS
    FILEPATHS_A
END TYPE
#ENDIF

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

TYPE FILEPATHS_SIGNERINFO_A
    Target        AS ASCIIZ PTR
    SOURCE        AS ASCIIZ PTR   ' not used for delete operations
    Win32Error    AS DWORD
    Flags         AS DWORD        ' such as SP_COPY_NOSKIP for copy errors
    DigitalSigner AS ASCIIZ PTR
    Version       AS ASCIIZ PTR
    CatalogFile   AS ASCIIZ PTR
END TYPE

TYPE FILEPATHS_SIGNERINFO_W
    Target        AS WSTRINGZ PTR
    SOURCE        AS WSTRINGZ PTR   ' not used for delete operations
    Win32Error    AS DWORD
    Flags         AS DWORD          ' such as SP_COPY_NOSKIP for copy errors
    DigitalSigner AS WSTRINGZ PTR
    Version       AS WSTRINGZ PTR
    CatalogFile   AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE FILEPATHS_SIGNERINFO
    FILEPATHS_SIGNERINFO_W
END TYPE
#ELSE
TYPE FILEPATHS_SIGNERINFO
    FILEPATHS_SIGNERINFO_A
END TYPE
#ENDIF

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

'
' Structure used with SPFILENOTIFY_NEEDMEDIA
'
TYPE SOURCE_MEDIA_A
    Reserved    AS ASCIIZ PTR
    Tagfile     AS ASCIIZ PTR        ' may be NULL
    Description AS ASCIIZ PTR
    '
    ' Pathname part and filename part of source file
    ' that caused us to need the media.
    '
    SourcePath  AS ASCIIZ PTR
    SourceFile  AS ASCIIZ PTR
    Flags       AS DWORD             ' subset of SP_COPY_xxx
END TYPE

TYPE SOURCE_MEDIA_W
    Reserved    AS WSTRINGZ PTR
    Tagfile     AS WSTRINGZ PTR        ' may be NULL
    Description AS WSTRINGZ PTR
    '
    ' Pathname part and filename part of source file
    ' that caused us to need the media.
    '
    SourcePath  AS WSTRINGZ PTR
    SourceFile  AS WSTRINGZ PTR
    Flags       AS DWORD             ' subset of SP_COPY_xxx
END TYPE

#IF %DEF(%UNICODE)
TYPE SOURCE_MEDIA
    SOURCE_MEDIA_W
END TYPE
#ELSE
TYPE SOURCE_MEDIA
    SOURCE_MEDIA_A
END TYPE
#ENDIF

'
' Structure used with SPFILENOTIFY_CABINETINFO and
' SPFILENOTIFY_NEEDNEWCABINET
'
TYPE CABINET_INFO_A
    CabinetPath   AS ASCIIZ PTR
    CabinetFile   AS ASCIIZ PTR
    DiskName      AS ASCIIZ PTR
    SetId         AS WORD
    CabinetNumber AS WORD
END TYPE

TYPE CABINET_INFO_W
    CabinetPath   AS WSTRINGZ PTR
    CabinetFile   AS WSTRINGZ PTR
    DiskName      AS WSTRINGZ PTR
    SetId         AS WORD
    CabinetNumber AS WORD
END TYPE

#IF %DEF(%UNICODE)
TYPE CABINET_INFO
    CABINET_INFO_W
END TYPE
#ELSE
TYPE CABINET_INFO
    CABINET_INFO_A
END TYPE
#ENDIF

'
' Structure used with SPFILENOTIFY_FILEINCABINET
'
TYPE FILE_IN_CABINET_INFO_A
    NameInCabinet  AS ASCIIZ PTR
    FileSize       AS DWORD
    Win32Error     AS DWORD
    DosDate        AS WORD
    DosTime        AS WORD
    DosAttribs     AS WORD
    FullTargetName AS ASCIIZ * %MAX_PATH
END TYPE

TYPE FILE_IN_CABINET_INFO_W
    NameInCabinet  AS WSTRINGZ PTR
    FileSize       AS DWORD
    Win32Error     AS DWORD
    DosDate        AS WORD
    DosTime        AS WORD
    DosAttribs     AS WORD
    FullTargetName AS WSTRINGZ * %MAX_PATH
END TYPE

#IF %DEF(%UNICODE)
TYPE FILE_IN_CABINET_INFO
    FILE_IN_CABINET_INFO_W
END TYPE
#ELSE
TYPE FILE_IN_CABINET_INFO
    FILE_IN_CABINET_INFO_A
END TYPE
#ENDIF

'
' Structure used for SPFILENOTIFY_***REGISTRATION
' callback
'

TYPE SP_REGISTER_CONTROL_STATUSA
    cbSize      AS DWORD
    FileName    AS ASCIIZ PTR
    Win32Error  AS DWORD
    FailureCode AS DWORD
END TYPE

TYPE SP_REGISTER_CONTROL_STATUSW
    cbSize      AS DWORD
    FileName    AS WSTRINGZ PTR
    Win32Error  AS DWORD
    FailureCode AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE SP_REGISTER_CONTROL_STATUS
    SP_REGISTER_CONTROL_STATUSW
END TYPE
#ELSE
TYPE SP_REGISTER_CONTROL_STATUS
    SP_REGISTER_CONTROL_STATUSW
END TYPE
#ENDIF


'
' valid values for SP_REGISTER_CONTROL_STATUS.FailureCode field
'

%SPREG_SUCCESS     = &H00000000
%SPREG_LOADLIBRARY = &H00000001
%SPREG_GETPROCADDR = &H00000002
%SPREG_REGSVR      = &H00000003
%SPREG_DLLINSTALL  = &H00000004
%SPREG_TIMEOUT     = &H00000005
%SPREG_UNKNOWN     = &HFFFFFFFF???

'
' Define type for setup file queue
'
MACRO HSPFILEQ=DWORD

'
' Structure used with SetupQueueCopyIndirect
'
TYPE SP_FILE_COPY_PARAMS_A
    cbSize             AS DWORD
    QueueHandle        AS HSPFILEQ
    SourceRootPath     AS ASCIIZ PTR
    SourcePath         AS ASCIIZ PTR
    SourceFilename     AS ASCIIZ PTR
    SourceDescription  AS ASCIIZ PTR
    SourceTagfile      AS ASCIIZ PTR
    TargetDirectory    AS ASCIIZ PTR
    TargetFilename     AS ASCIIZ PTR
    CopyStyle          AS DWORD
    LayoutInf          AS HINF
    SecurityDescriptor AS ASCIIZ PTR
END TYPE

TYPE SP_FILE_COPY_PARAMS_W
    cbSize             AS DWORD
    QueueHandle        AS HSPFILEQ
    SourceRootPath     AS WSTRINGZ PTR
    SourcePath         AS WSTRINGZ PTR
    SourceFilename     AS WSTRINGZ PTR
    SourceDescription  AS WSTRINGZ PTR
    SourceTagfile      AS WSTRINGZ PTR
    TargetDirectory    AS WSTRINGZ PTR
    TargetFilename     AS WSTRINGZ PTR
    CopyStyle          AS DWORD
    LayoutInf          AS HINF
    SecurityDescriptor AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE SP_FILE_COPY_PARAMS
    SP_FILE_COPY_PARAMS_W
END TYPE
#ELSE
TYPE SP_FILE_COPY_PARAMS
    SP_FILE_COPY_PARAMS_A
END TYPE
#ENDIF


'
' Define type for setup disk space list
'
MACRO HDSKSPC=DWORD

'
' Define type for reference to device information set
'
MACRO HDEVINFO=DWORD

'
' Device information structure (references a device instance
' that is a member of a device information set)
'
TYPE SP_DEVINFO_DATA
    cbSize    AS DWORD
    ClassGuid AS GUID
    DevInst   AS DWORD  ' DEVINST handle
    Reserved  AS DWORD  ' ULONG_PTR
END TYPE

'
' Device interface information structure (references a device
' interface that is associated with the device information
' element that owns it).
'
TYPE SP_DEVICE_INTERFACE_DATA
    cbSize             AS DWORD
    InterfaceClassGuid AS GUID
    Flags              AS DWORD
    Reserved           AS DWORD  ' ULONG_PTR
END TYPE

'
' Flags for SP_DEVICE_INTERFACE_DATA.Flags field.
'
%SPINT_ACTIVE  = &H00000001
%SPINT_DEFAULT = &H00000002
%SPINT_REMOVED = &H00000004

'
' Backward compatibility--do not use.
'
MACRO SP_INTERFACE_DEVICE_DATA=SP_DEVICE_INTERFACE_DATA

%SPID_ACTIVE            = %SPINT_ACTIVE
%SPID_DEFAULT           = %SPINT_DEFAULT
%SPID_REMOVED           = %SPINT_REMOVED


TYPE SP_DEVICE_INTERFACE_DETAIL_DATA_A
    cbSize     AS DWORD
    DevicePath AS ASCIIZ * %ANYSIZE_ARRAY
END TYPE

TYPE SP_DEVICE_INTERFACE_DETAIL_DATA_W
    cbSize     AS DWORD
    DevicePath AS WSTRINGZ * %ANYSIZE_ARRAY
END TYPE

#IF %DEF(%UNICODE)
TYPE SP_DEVICE_INTERFACE_DETAIL_DATA
    SP_DEVICE_INTERFACE_DETAIL_DATA_W
END TYPE
#ELSE
TYPE SP_DEVICE_INTERFACE_DETAIL_DATA
    SP_DEVICE_INTERFACE_DETAIL_DATA_A
END TYPE
#ENDIF

'
' Backward compatibility--do not use.
'
TYPE SP_INTERFACE_DEVICE_DETAIL_DATA_W
    SP_DEVICE_INTERFACE_DETAIL_DATA_W
END TYPE
TYPE SP_INTERFACE_DEVICE_DETAIL_DATA_A
    SP_DEVICE_INTERFACE_DETAIL_DATA_A
END TYPE
#IF %DEF(%UNICODE)
TYPE SP_INTERFACE_DEVICE_DETAIL_DATA
    SP_INTERFACE_DEVICE_DETAIL_DATA_W
END TYPE
#ELSE
TYPE SP_INTERFACE_DEVICE_DETAIL_DATA
    SP_INTERFACE_DEVICE_DETAIL_DATA_A
END TYPE
#ENDIF


'
' Structure for detailed information on a device information set (used for
' SetupDiGetDeviceInfoListDetail which supercedes the functionality of
' SetupDiGetDeviceInfoListClass).
'
TYPE SP_DEVINFO_LIST_DETAIL_DATA_A
    cbSize              AS DWORD
    ClassGuid           AS GUID
    RemoteMachineHandle AS DWORD  ' HANDLE
    RemoteMachineName   AS ASCIIZ * %SP_MAX_MACHINENAME_LENGTH
END TYPE

TYPE SP_DEVINFO_LIST_DETAIL_DATA_W
    cbSize              AS DWORD
    ClassGuid           AS GUID
    RemoteMachineHandle AS DWORD  ' HANDLE
    RemoteMachineName   AS WSTRINGZ * %SP_MAX_MACHINENAME_LENGTH
END TYPE

#IF %DEF(%UNICODE)
TYPE SP_DEVINFO_LIST_DETAIL_DATA
    SP_DEVINFO_LIST_DETAIL_DATA_W
END TYPE
#ELSE
TYPE SP_DEVINFO_LIST_DETAIL_DATA
    SP_DEVINFO_LIST_DETAIL_DATA_A
END TYPE
#ENDIF

'
' Class installer function codes
'
%DIF_SELECTDEVICE                    = &H00000001
%DIF_INSTALLDEVICE                   = &H00000002
%DIF_ASSIGNRESOURCES                 = &H00000003
%DIF_PROPERTIES                      = &H00000004
%DIF_REMOVE                          = &H00000005
%DIF_FIRSTTIMESETUP                  = &H00000006
%DIF_FOUNDDEVICE                     = &H00000007
%DIF_SELECTCLASSDRIVERS              = &H00000008
%DIF_VALIDATECLASSDRIVERS            = &H00000009
%DIF_INSTALLCLASSDRIVERS             = &H0000000A
%DIF_CALCDISKSPACE                   = &H0000000B
%DIF_DESTROYPRIVATEDATA              = &H0000000C
%DIF_VALIDATEDRIVER                  = &H0000000D
%DIF_DETECT                          = &H0000000F
%DIF_INSTALLWIZARD                   = &H00000010
%DIF_DESTROYWIZARDDATA               = &H00000011
%DIF_PROPERTYCHANGE                  = &H00000012
%DIF_ENABLECLASS                     = &H00000013
%DIF_DETECTVERIFY                    = &H00000014
%DIF_INSTALLDEVICEFILES              = &H00000015
%DIF_UNREMOVE                        = &H00000016
%DIF_SELECTBESTCOMPATDRV             = &H00000017
%DIF_ALLOW_INSTALL                   = &H00000018
%DIF_REGISTERDEVICE                  = &H00000019
%DIF_NEWDEVICEWIZARD_PRESELECT       = &H0000001A
%DIF_NEWDEVICEWIZARD_SELECT          = &H0000001B
%DIF_NEWDEVICEWIZARD_PREANALYZE      = &H0000001C
%DIF_NEWDEVICEWIZARD_POSTANALYZE     = &H0000001D
%DIF_NEWDEVICEWIZARD_FINISHINSTALL   = &H0000001E
%DIF_UNUSED1                         = &H0000001F
%DIF_INSTALLINTERFACES               = &H00000020
%DIF_DETECTCANCEL                    = &H00000021
%DIF_REGISTER_COINSTALLERS           = &H00000022
%DIF_ADDPROPERTYPAGE_ADVANCED        = &H00000023
%DIF_ADDPROPERTYPAGE_BASIC           = &H00000024
%DIF_RESERVED1                       = &H00000025
%DIF_TROUBLESHOOTER                  = &H00000026
%DIF_POWERMESSAGEWAKE                = &H00000027
%DIF_ADDREMOTEPROPERTYPAGE_ADVANCED  = &H00000028
%DIF_UPDATEDRIVER_UI                 = &H00000029
%DIF_FINISHINSTALL_ACTION            = &H0000002A
%DIF_RESERVED2                       = &H00000030

'
' Obsoleted DIF codes (do not use)
'
%DIF_MOVEDEVICE                      = &H0000000E


MACRO DI_FUNCTION=DWORD    ' Function type for device installer


'
' Device installation parameters structure (associated with a
' particular device information element, or globally with a device
' information set)
'
TYPE SP_DEVINSTALL_PARAMS_A
    cbSize                   AS DWORD
    Flags                    AS DWORD
    FlagsEx                  AS DWORD
    hwndParent               AS DWORD  ' HWND
    InstallMsgHandler        AS DWORD  ' PSP_FILE_CALLBACK_A
    InstallMsgHandlerContext AS DWORD  ' PVOID
    FileQueue                AS HSPFILEQ
    ClassInstallReserved     AS DWORD  ' ULONG_PTR
    Reserved                 AS DWORD
    DriverPath               AS ASCIIZ * %MAX_PATH
END TYPE

TYPE SP_DEVINSTALL_PARAMS_W
    cbSize                   AS DWORD
    Flags                    AS DWORD
    FlagsEx                  AS DWORD
    hwndParent               AS DWORD  ' HWND
    InstallMsgHandler        AS DWORD  ' PSP_FILE_CALLBACK_W
    InstallMsgHandlerContext AS DWORD  ' PVOID
    FileQueue                AS HSPFILEQ
    ClassInstallReserved     AS DWORD  ' ULONG_PTR
    Reserved                 AS DWORD
    DriverPath               AS WSTRINGZ * %MAX_PATH
END TYPE

#IF %DEF(%UNICODE)
TYPE SP_DEVINSTALL_PARAMS
    SP_DEVINSTALL_PARAMS_W
END TYPE
#ELSE
TYPE SP_DEVINSTALL_PARAMS
    SP_DEVINSTALL_PARAMS_A
END TYPE
#ENDIF


'
' SP_DEVINSTALL_PARAMS.Flags values
'
' Flags for choosing a device
'
%DI_SHOWOEM                  = &H00000001   ' support Other... button
%DI_SHOWCOMPAT               = &H00000002   ' show compatibility list
%DI_SHOWCLASS                = &H00000004   ' show class list
%DI_SHOWALL                  = &H00000007   ' both class & compat list shown
%DI_NOVCP                    = &H00000008   ' don't create a new copy queue--use
                                            ' caller-supplied FileQueue
%DI_DIDCOMPAT                = &H00000010   ' Searched for compatible devices
%DI_DIDCLASS                 = &H00000020   ' Searched for class devices
%DI_AUTOASSIGNRES            = &H00000040   ' No UI for resources if possible

' flags returned by DiInstallDevice to indicate need to reboot/restart
%DI_NEEDRESTART              = &H00000080   ' Reboot required to take effect
%DI_NEEDREBOOT               = &H00000100   ' ""

' flags for device installation
%DI_NOBROWSE                 = &H00000200   ' no Browse... in InsertDisk

' Flags set by DiBuildDriverInfoList
%DI_MULTMFGS                 = &H00000400   ' Set if multiple manufacturers in
                                                    ' class driver list

' Flag indicates that device is disabled
%DI_DISABLED                 = &H00000800   ' Set if device disabled

' Flags for Device/Class Properties
%DI_GENERALPAGE_ADDED        = &H00001000
%DI_RESOURCEPAGE_ADDED       = &H00002000

' Flag to indicate the setting properties for this Device (or class) caused a change
' so the Dev Mgr UI probably needs to be updatd.
%DI_PROPERTIES_CHANGE        = &H00004000

' Flag to indicate that the sorting from the INF file should be used.
%DI_INF_IS_SORTED            = &H00008000

' Flag to indicate that only the the INF specified by SP_DEVINSTALL_PARAMS.DriverPath
' should be searched.
%DI_ENUMSINGLEINF            = &H00010000

' Flag that prevents ConfigMgr from removing/re-enumerating devices during device
' registration, installation, and deletion.
%DI_DONOTCALLCONFIGMG        = &H00020000

' The following flag can be used to install a device disabled
%DI_INSTALLDISABLED          = &H00040000

' Flag that causes SetupDiBuildDriverInfoList to build a device's compatible driver
' list from its existing class driver list, instead of the normal INF search.
%DI_COMPAT_FROM_CLASS        = &H00080000

' This flag is set if the Class Install params should be used.
%DI_CLASSINSTALLPARAMS       = &H00100000

' This flag is set if the caller of DiCallClassInstaller does NOT
' want the internal default action performed if the Class installer
' returns ERROR_DI_DO_DEFAULT.
%DI_NODI_DEFAULTACTION       = &H00200000

' The setupx flag, %DI_NOSYNCPROCESSING (&H00400000) is not support in the Setup APIs.

' flags for device installation
%DI_QUIETINSTALL             = &H00800000      ' don't confuse the user with
                                               ' questions or excess info
%DI_NOFILECOPY               = &H01000000      ' No file Copy necessary
%DI_FORCECOPY                = &H02000000      ' Force files to be copied from install path
%DI_DRIVERPAGE_ADDED         = &H04000000      ' Prop provider added Driver page.
%DI_USECI_SELECTSTRINGS      = &H08000000      ' Use Class Installer Provided strings in the Select Device Dlg
%DI_OVERRIDE_INFFLAGS        = &H10000000      ' Override INF flags
%DI_PROPS_NOCHANGEUSAGE      = &H20000000      ' No Enable/Disable in General Props

%DI_NOSELECTICONS            = &H40000000      ' No small icons in select device dialogs

%DI_NOWRITE_IDS              = &H80000000???   ' Don't write HW & Compat IDs on install


'
' SP_DEVINSTALL_PARAMS.FlagsEx values
'

%DI_FLAGSEX_RESERVED2                = &H00000001   ' %DI_FLAGSEX_USEOLDINFSEARCH is obsolete
%DI_FLAGSEX_RESERVED3                = &H00000002   ' %DI_FLAGSEX_AUTOSELECTRANK0 is obsolete
%DI_FLAGSEX_CI_FAILED                = &H00000004   ' Failed to Load/Call class installer

#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

%DI_FLAGSEX_FINISHINSTALL_ACTION     = &H00000008   ' Class/co-installer wants to get a DIF_FINISH_INSTALL action in client context.

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

%DI_FLAGSEX_DIDINFOLIST              = &H00000010   ' Did the Class Info List
%DI_FLAGSEX_DIDCOMPATINFO            = &H00000020   ' Did the Compat Info List

%DI_FLAGSEX_FILTERCLASSES            = &H00000040
%DI_FLAGSEX_SETFAILEDINSTALL         = &H00000080
%DI_FLAGSEX_DEVICECHANGE             = &H00000100
%DI_FLAGSEX_ALWAYSWRITEIDS           = &H00000200
%DI_FLAGSEX_PROPCHANGE_PENDING       = &H00000400   ' One or more device property sheets have had changes made
                                                    ' to them, and need to have a DIF_PROPERTYCHANGE occur.
%DI_FLAGSEX_ALLOWEXCLUDEDDRVS        = &H00000800
%DI_FLAGSEX_NOUIONQUERYREMOVE        = &H00001000
%DI_FLAGSEX_USECLASSFORCOMPAT        = &H00002000   ' Use the device's class when building compat drv list.
                                                    ' (Ignored if DI_COMPAT_FROM_CLASS flag is specified.)

%DI_FLAGSEX_RESERVED4                = &H00004000   ' %DI_FLAGSEX_OLDINF_IN_CLASSLIST is obsolete

%DI_FLAGSEX_NO_DRVREG_MODIFY         = &H00008000   ' Don't run AddReg and DelReg for device's software (driver) key.
%DI_FLAGSEX_IN_SYSTEM_SETUP          = &H00010000   ' Installation is occurring during initial system setup.
%DI_FLAGSEX_INET_DRIVER              = &H00020000   ' Driver came from Windows Update
%DI_FLAGSEX_APPENDDRIVERLIST         = &H00040000   ' Cause SetupDiBuildDriverInfoList to append
                                                    ' a new driver list to an existing list.
%DI_FLAGSEX_PREINSTALLBACKUP         = &H00080000   ' not used
%DI_FLAGSEX_BACKUPONREPLACE          = &H00100000   ' not used
%DI_FLAGSEX_DRIVERLIST_FROM_URL      = &H00200000   ' build driver list from INF(s) retrieved from URL specified
                                                    ' in SP_DEVINSTALL_PARAMS.DriverPath (empty string means
                                                    ' Windows Update website)
%DI_FLAGSEX_RESERVED1                = &H00400000
%DI_FLAGSEX_EXCLUDE_OLD_INET_DRIVERS = &H00800000   ' Don't include old Internet drivers when building
                                                    ' a driver list.
                                                    ' Ignored on Windows Vista and later.
%DI_FLAGSEX_POWERPAGE_ADDED          = &H01000000   ' class installer added their own power page

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

%DI_FLAGSEX_FILTERSIMILARDRIVERS     = &H02000000   ' only include similar drivers in class list
%DI_FLAGSEX_INSTALLEDDRIVER          = &H04000000   ' only add the installed driver to the class or compat
                                                    ' driver list.  Used in calls to SetupDiBuildDriverInfoList
%DI_FLAGSEX_NO_CLASSLIST_NODE_MERGE  = &H08000000   ' Don't remove identical driver nodes from the class list
%DI_FLAGSEX_ALTPLATFORM_DRVSEARCH    = &H10000000   ' Build driver list based on alternate platform information
                                                    ' specified in associated file queue
%DI_FLAGSEX_RESTART_DEVICE_ONLY      = &H20000000   ' only restart the device drivers are being installed on as
                                                    ' opposed to restarting all devices using those drivers.

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

%DI_FLAGSEX_RECURSIVESEARCH          = &H40000000    ' Tell SetupDiBuildDriverInfoList to do a recursive search
%DI_FLAGSEX_SEARCH_PUBLISHED_INFS    = &H80000000??? ' Tell SetupDiBuildDriverInfoList to do a "published INF" search

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

'
' Class installation parameters header.  This must be the first field of any
' class install parameter structure.  The InstallFunction field must be set to
' the function code corresponding to the structure, and the cbSize field must
' be set to the size of the header structure.  E.g.,
'
' SP_ENABLECLASS_PARAMS EnableClassParams;
'
' EnableClassParams.ClassInstallHeader.cbSize = sizeof(SP_CLASSINSTALL_HEADER);
' EnableClassParams.ClassInstallHeader.InstallFunction = DIF_ENABLECLASS;
'
TYPE SP_CLASSINSTALL_HEADER
    cbSize          AS DWORD
    InstallFunction AS DI_FUNCTION
END TYPE


'
' Structure corresponding to a DIF_ENABLECLASS install function.
'
TYPE SP_ENABLECLASS_PARAMS
    ClassInstallHeader AS SP_CLASSINSTALL_HEADER
    ClassGuid          AS GUID
    EnableMessage      AS DWORD
END TYPE

%ENABLECLASS_QUERY   = 0
%ENABLECLASS_SUCCESS = 1
%ENABLECLASS_FAILURE = 2


'
' Values indicating a change in a device's state
'
%DICS_ENABLE     = &H00000001
%DICS_DISABLE    = &H00000002
%DICS_PROPCHANGE = &H00000003
%DICS_START      = &H00000004
%DICS_STOP       = &H00000005
'
' Values specifying the scope of a device property change
'
%DICS_FLAG_GLOBAL         = &H00000001  ' make change in all hardware profiles
%DICS_FLAG_CONFIGSPECIFIC = &H00000002  ' make change in specified profile only
%DICS_FLAG_CONFIGGENERAL  = &H00000004  ' 1 or more hardware profile-specific
                                             ' changes to follow.
'
' Structure corresponding to a DIF_PROPERTYCHANGE install function.
'
TYPE SP_PROPCHANGE_PARAMS
    ClassInstallHeader AS SP_CLASSINSTALL_HEADER
    StateChange        AS DWORD
    Scope              AS DWORD
    HwProfile          AS DWORD
END TYPE


'
' Structure corresponding to a DIF_REMOVE install function.
'
TYPE SP_REMOVEDEVICE_PARAMS
    ClassInstallHeader AS SP_CLASSINSTALL_HEADER
    Scope              AS DWORD
    HwProfile          AS DWORD
END TYPE

%DI_REMOVEDEVICE_GLOBAL                = &H00000001
%DI_REMOVEDEVICE_CONFIGSPECIFIC        = &H00000002


'
' Structure corresponding to a DIF_UNREMOVE install function.
'
TYPE SP_UNREMOVEDEVICE_PARAMS
    ClassInstallHeader AS SP_CLASSINSTALL_HEADER
    Scope              AS DWORD
    HwProfile          AS DWORD
END TYPE

%DI_UNREMOVEDEVICE_CONFIGSPECIFIC      = &H00000002


'
' Structure corresponding to a DIF_SELECTDEVICE install function.
'
TYPE SP_SELECTDEVICE_PARAMS_A
    ClassInstallHeader AS SP_CLASSINSTALL_HEADER
    Title              AS ASCIIZ * %MAX_TITLE_LEN
    Instructions       AS ASCIIZ * %MAX_INSTRUCTION_LEN
    ListLabel          AS ASCIIZ * %MAX_LABEL_LEN
    SubTitle           AS ASCIIZ * %MAX_SUBTITLE_LEN
    Reserved(1)        AS BYTE         ' DWORD size alignment
END TYPE

TYPE SP_SELECTDEVICE_PARAMS_W
    ClassInstallHeader AS SP_CLASSINSTALL_HEADER
    Title              AS WSTRINGZ * %MAX_TITLE_LEN
    Instructions       AS WSTRINGZ * %MAX_INSTRUCTION_LEN
    ListLabel          AS WSTRINGZ * %MAX_LABEL_LEN
    SubTitle           AS WSTRINGZ * %MAX_SUBTITLE_LEN
END TYPE

#IF %DEF(%UNICODE)
TYPE SP_SELECTDEVICE_PARAMS
    SP_SELECTDEVICE_PARAMS_W
END TYPE
#ELSE
TYPE SP_SELECTDEVICE_PARAMS
    SP_SELECTDEVICE_PARAMS_A
END TYPE
#ENDIF


'
' Callback routine for giving progress notification during detection
'
DECLARE FUNCTION PDETECT_PROGRESS_NOTIFY ( _
     ProgressNotifyParam  AS ANY, _   ' PVOID
     BYVAL DetectComplete AS DWORD _
     ) AS LONG ' BOOL

' where:
'     ProgressNotifyParam - value supplied by caller requesting detection.
'     DetectComplete - Percent completion, to be incremented by class
'                      installer, as it steps thru its detection.
'
' Return Value - If TRUE, then detection is cancelled.  Allows caller
'                requesting detection to stop detection asap.
'

'
' Structure corresponding to a DIF_DETECT install function.
'
TYPE SP_DETECTDEVICE_PARAMS
    ClassInstallHeader   AS SP_CLASSINSTALL_HEADER
    DetectProgressNotify AS DWORD  ' PDETECT_PROGRESS_NOTIFY
    ProgressNotifyParam  AS DWORD  ' PVOID
END TYPE


'
' 'Add New Device' installation wizard structure (backward-compatibility
' only--respond to DIF_NEWDEVICEWIZARD_* requests instead).
'
' Structure corresponding to a DIF_INSTALLWIZARD install function.
' (NOTE: This structure is also applicable for DIF_DESTROYWIZARDDATA,
' but DIF_INSTALLWIZARD is the associated function code in the class
' installation parameter structure in both cases.)
'
' Define maximum number of dynamic wizard pages that can be added to
' hardware install wizard.
'
%MAX_INSTALLWIZARD_DYNAPAGES           = 20

TYPE SP_INSTALLWIZARD_DATA
    ClassInstallHeader AS SP_CLASSINSTALL_HEADER
    Flags              AS DWORD
    DynamicPages(%MAX_INSTALLWIZARD_DYNAPAGES-1) AS DWORD  ' HPROPSHEETPAGE
    NumDynamicPages    AS DWORD
    DynamicPageFlags   AS DWORD
    PrivateFlags       AS DWORD
    PrivateData        AS LONG   ' LPARAM
    hwndWizardDlg      AS DWORD  ' HWND
END TYPE

'
' SP_INSTALLWIZARD_DATA.Flags values
'
%NDW_INSTALLFLAG_DIDFACTDEFS        = &H00000001
%NDW_INSTALLFLAG_HARDWAREALLREADYIN = &H00000002
%NDW_INSTALLFLAG_NEEDRESTART        = %DI_NEEDRESTART
%NDW_INSTALLFLAG_NEEDREBOOT         = %DI_NEEDREBOOT
%NDW_INSTALLFLAG_NEEDSHUTDOWN       = &H00000200
%NDW_INSTALLFLAG_EXPRESSINTRO       = &H00000400
%NDW_INSTALLFLAG_SKIPISDEVINSTALLED = &H00000800
%NDW_INSTALLFLAG_NODETECTEDDEVS     = &H00001000
%NDW_INSTALLFLAG_INSTALLSPECIFIC    = &H00002000
%NDW_INSTALLFLAG_SKIPCLASSLIST      = &H00004000
%NDW_INSTALLFLAG_CI_PICKED_OEM      = &H00008000
%NDW_INSTALLFLAG_PCMCIAMODE         = &H00010000
%NDW_INSTALLFLAG_PCMCIADEVICE       = &H00020000
%NDW_INSTALLFLAG_USERCANCEL         = &H00040000
%NDW_INSTALLFLAG_KNOWNCLASS         = &H00080000


'
' SP_INSTALLWIZARD_DATA.DynamicPageFlags values
'
' This flag is set if a Class installer has added pages to the install wizard.
'
%DYNAWIZ_FLAG_PAGESADDED             = &H00000001

'
' Set this flag if you jump to the analyze page, and want it to
' handle conflicts for you.  NOTE.  You will not get control back
' in the event of a conflict if you set this flag.
'
%DYNAWIZ_FLAG_ANALYZE_HANDLECONFLICT = &H00000008

'
' The following flags are not used by the Windows NT hardware wizard.
'
%DYNAWIZ_FLAG_INSTALLDET_NEXT        = &H00000002
%DYNAWIZ_FLAG_INSTALLDET_PREV        = &H00000004


'
' Reserve a range of wizard page resource IDs for internal use.  Some of
' these IDs are for use by class installers that respond to the obsolete
' DIF_INSTALLWIZARD/DIF_DESTROYWIZARDDATA messages.  These IDs are listed
' below.
'
%MIN_IDD_DYNAWIZ_RESOURCE_ID           = 10000
%MAX_IDD_DYNAWIZ_RESOURCE_ID           = 11000

'
' Define wizard page resource IDs to be used when adding custom pages to the
' hardware install wizard via DIF_INSTALLWIZARD.  Pages marked with
' (CLASS INSTALLER PROVIDED) _must_ be supplied by the class installer if it
' responds to the DIF_INSTALLWIZARD request.
'

'
' Resource ID for the first page that the install wizard will go to after
' adding the class installer pages.  (CLASS INSTALLER PROVIDED)
'
%IDD_DYNAWIZ_FIRSTPAGE                 = 10000

'
' Resource ID for the page that the Select Device page will go back to.
' (CLASS INSTALLER PROVIDED)
'
%IDD_DYNAWIZ_SELECT_PREVPAGE           = 10001

'
' Resource ID for the page that the Select Device page will go forward to.
' (CLASS INSTALLER PROVIDED)
'
%IDD_DYNAWIZ_SELECT_NEXTPAGE           = 10002

'
' Resource ID for the page that the Analyze dialog should go back to
' This will only be used in the event that there is a problem, and the user
' selects Back from the analyze proc. (CLASS INSTALLER PROVIDED)
'
%IDD_DYNAWIZ_ANALYZE_PREVPAGE          = 10003

'
' Resource ID for the page that the Analyze dialog should go to if it
' continues from the analyze proc. (CLASS INSTALLER PROVIDED)
'
%IDD_DYNAWIZ_ANALYZE_NEXTPAGE          = 10004

'
' Resource ID of the hardware install wizard's select device page.
' This ID can be used to go directly to the hardware install wizard's select
' device page.  (This is the resource ID of the Select Device wizard page
' retrieved via SetupDiGetWizardPage when SPWPT_SELECTDEVICE is the requested
' PageType.)
'
%IDD_DYNAWIZ_SELECTDEV_PAGE            = 10009

'
' Resource ID of the hardware install wizard's device analysis page.
' This ID can be use to go directly to the hardware install wizard's analysis
' page.
'
%IDD_DYNAWIZ_ANALYZEDEV_PAGE           = 10010

'
' Resource ID of the hardware install wizard's install detected devices page.
' This ID can be use to go directly to the hardware install wizard's install
' detected devices page.
'
%IDD_DYNAWIZ_INSTALLDETECTEDDEVS_PAGE  = 10011

'
' Resource ID of the hardware install wizard's select class page.
' This ID can be use to go directly to the hardware install wizard's select
' class page.
'
%IDD_DYNAWIZ_SELECTCLASS_PAGE          = 10012

'
' The following class installer-provided wizard page resource IDs are not used
' by the Windows NT hardware wizard.
'
%IDD_DYNAWIZ_INSTALLDETECTED_PREVPAGE  = 10006
%IDD_DYNAWIZ_INSTALLDETECTED_NEXTPAGE  = 10007
%IDD_DYNAWIZ_INSTALLDETECTED_NODEVS    = 10008


'
' Structure corresponding to the following DIF_NEWDEVICEWIZARD_* install
' functions:
'
'     DIF_NEWDEVICEWIZARD_PRESELECT
'     DIF_NEWDEVICEWIZARD_SELECT
'     DIF_NEWDEVICEWIZARD_PREANALYZE
'     DIF_NEWDEVICEWIZARD_POSTANALYZE
'     DIF_NEWDEVICEWIZARD_FINISHINSTALL
'
TYPE SP_NEWDEVICEWIZARD_DATA
    ClassInstallHeader AS SP_CLASSINSTALL_HEADER
    Flags              AS DWORD   ' presently unused--must be zero.
    DynamicPages(%MAX_INSTALLWIZARD_DYNAPAGES-1) AS DWORD  ' HPROPSHEETPAGE
    NumDynamicPages    AS DWORD
    hwndWizardDlg      AS DWORD   ' HWND
END TYPE

'
' The same structure is also used for retrieval of property pages via the
' following install functions:
'
'     DIF_ADDPROPERTYPAGE_ADVANCED
'     DIF_ADDPROPERTYPAGE_BASIC
'     DIF_ADDREMOTEPROPERTYPAGE_ADVANCED
'
TYPE SP_ADDPROPERTYPAGE_DATA
    SP_NEWDEVICEWIZARD_DATA
END TYPE


'
' Structure corresponding to the DIF_TROUBLESHOOTER install function
'
TYPE SP_TROUBLESHOOTER_PARAMS_A
    ClassInstallHeader AS SP_CLASSINSTALL_HEADER
    ChmFile            AS ASCIIZ * %MAX_PATH
    HtmlTroubleShooter AS ASCIIZ * %MAX_PATH
END TYPE

TYPE SP_TROUBLESHOOTER_PARAMS_W
    ClassInstallHeader AS SP_CLASSINSTALL_HEADER
    ChmFile            AS WSTRINGZ * %MAX_PATH
    HtmlTroubleShooter AS WSTRINGZ * %MAX_PATH
END TYPE

#IF %DEF(%UNICODE)
TYPE SP_TROUBLESHOOTER_PARAMS
    SP_TROUBLESHOOTER_PARAMS_W
END TYPE
#ELSE
TYPE SP_TROUBLESHOOTER_PARAMS
    SP_TROUBLESHOOTER_PARAMS_A
END TYPE
#ENDIF


'
' Structure corresponding to the DIF_POWERMESSAGEWAKE install function
'
TYPE SP_POWERMESSAGEWAKE_PARAMS_A
    ClassInstallHeader AS SP_CLASSINSTALL_HEADER
    PowerMessageWake   AS ASCIIZ * %LINE_LEN*2
END TYPE

TYPE SP_POWERMESSAGEWAKE_PARAMS_W
    ClassInstallHeader AS SP_CLASSINSTALL_HEADER
    PowerMessageWake   AS WSTRINGZ * %LINE_LEN*2
END TYPE

#IF %DEF(%UNICODE)
TYPE SP_POWERMESSAGEWAKE_PARAMS
    SP_POWERMESSAGEWAKE_PARAMS_W
END TYPE
#ELSE
TYPE SP_POWERMESSAGEWAKE_PARAMS
    SP_POWERMESSAGEWAKE_PARAMS_A
END TYPE
#ENDIF

'
' Driver information structure (member of a driver info list that may be associated
' with a particular device instance, or (globally) with a device information set)
'
TYPE SP_DRVINFO_DATA_V2_A
    cbSize        AS DWORD
    DriverType    AS DWORD
    Reserved      AS DWORD  ' ULONG_PTR
    Description   AS ASCIIZ * %LINE_LEN
    MfgName       AS ASCIIZ * %LINE_LEN
    ProviderName  AS ASCIIZ * %LINE_LEN
    DriverDate    AS FILETIME
    DriverVersion AS QUAD  ' DWORDLONG
END TYPE

TYPE SP_DRVINFO_DATA_V2_W
    cbSize        AS DWORD
    DriverType    AS DWORD
    Reserved      AS DWORD  ' ULONG_PTR
    Description   AS WSTRINGZ * %LINE_LEN
    MfgName       AS WSTRINGZ * %LINE_LEN
    ProviderName  AS WSTRINGZ * %LINE_LEN
    DriverDate    AS FILETIME
    DriverVersion AS QUAD  ' DWORDLONG
END TYPE

'
' Version 1 of the SP_DRVINFO_DATA structures, used only for compatibility
' with Windows NT 4.0/Windows 95/98 SETUPAPI.DLL
'
TYPE SP_DRVINFO_DATA_V1_A
    cbSize       AS DWORD
    DriverType   AS DWORD
    Reserved     AS DWORD  ' ULONG_PTR
    Description  AS ASCIIZ * %LINE_LEN
    MfgName      AS ASCIIZ * %LINE_LEN
    ProviderName AS ASCIIZ * %LINE_LEN
END TYPE

TYPE SP_DRVINFO_DATA_V1_W
    cbSize       AS DWORD
    DriverType   AS DWORD
    Reserved     AS DWORD  ' ULONG_PTR
    Description  AS WSTRINGZ * %LINE_LEN
    MfgName      AS WSTRINGZ * %LINE_LEN
    ProviderName AS WSTRINGZ * %LINE_LEN
END TYPE

#IF %DEF(%UNICODE)
TYPE SP_DRVINFO_DATA_V1
    SP_DRVINFO_DATA_V1_W
END TYPE
TYPE SP_DRVINFO_DATA_V2
    SP_DRVINFO_DATA_V2_W
END TYPE
#ELSE
TYPE SP_DRVINFO_DATA_V1
    SP_DRVINFO_DATA_V1_A
END TYPE
TYPE SP_DRVINFO_DATA_V2
    SP_DRVINFO_DATA_V2_A
END TYPE
#ENDIF

#IF %DEF(%USE_SP_DRVINFO_DATA_V1) OR (%SETUPAPI_VER < %WIN32_WINNT_WIN2K)  ' use version 1 driver info data structure

TYPE SP_DRVINFO_DATA_A
    SP_DRVINFO_DATA_V1_A
END TYPE
TYPE SP_DRVINFO_DATA_W
    SP_DRVINFO_DATA_V1_W
END TYPE
TYPE SP_DRVINFO_DATA
    SP_DRVINFO_DATA_V1
END TYPE

#ELSE                       ' use version 2 driver info data structure

TYPE SP_DRVINFO_DATA_A
    SP_DRVINFO_DATA_V2_A
END TYPE
TYPE SP_DRVINFO_DATA_W
    SP_DRVINFO_DATA_V2_W
END TYPE
TYPE SP_DRVINFO_DATA
    SP_DRVINFO_DATA_V2
END TYPE

#ENDIF  ' use current version of driver info data structure

'
' Driver information details structure (provides detailed information about a
' particular driver information structure)
'
TYPE SP_DRVINFO_DETAIL_DATA_A
    cbSize          AS DWORD
    InfDate         AS FILETIME
    CompatIDsOffset AS DWORD
    CompatIDsLength AS DWORD
    Reserved        AS DWORD  ' ULONG_PTR
    SectionName     AS ASCIIZ * %LINE_LEN
    InfFileName     AS ASCIIZ * %MAX_PATH
    DrvDescription  AS ASCIIZ * %LINE_LEN
    HardwareID      AS ASCIIZ * %ANYSIZE_ARRAY
END TYPE

TYPE SP_DRVINFO_DETAIL_DATA_W
    cbSize          AS DWORD
    InfDate         AS FILETIME
    CompatIDsOffset AS DWORD
    CompatIDsLength AS DWORD
    Reserved        AS DWORD  ' ULONG_PTR
    SectionName     AS WSTRINGZ * %LINE_LEN
    InfFileName     AS WSTRINGZ * %MAX_PATH
    DrvDescription  AS WSTRINGZ * %LINE_LEN
    HardwareID      AS WSTRINGZ * %ANYSIZE_ARRAY
END TYPE

#IF %DEF(%UNICODE)
TYPE SP_DRVINFO_DETAIL_DATA
    SP_DRVINFO_DETAIL_DATA_W
END TYPE
#ELSE
TYPE SP_DRVINFO_DETAIL_DATA
    SP_DRVINFO_DETAIL_DATA_A
END TYPE
#ENDIF


'
' Driver installation parameters (associated with a particular driver
' information element)
'
TYPE SP_DRVINSTALL_PARAMS
    cbSize      AS DWORD
    Rank        AS DWORD
    Flags       AS DWORD
    PrivateData AS DWORD  ' DWORD_PTR
    Reserved    AS DWORD
END TYPE

'
' SP_DRVINSTALL_PARAMS.Flags values
'

%DNF_DUPDESC             = &H00000001  ' Multiple providers have same desc
%DNF_OLDDRIVER           = &H00000002  ' Driver node specifies old/current driver
%DNF_EXCLUDEFROMLIST     = &H00000004  ' If set, this driver node will not be
                                       ' displayed in any driver select dialogs.
%DNF_NODRIVER            = &H00000008  ' if we want to install no driver
                                       ' (e.g no mouse drv)
%DNF_LEGACYINF           = &H00000010  ' Driver node came from an old-style INF (obsolete)
%DNF_CLASS_DRIVER        = &H00000020  ' Driver node represents a class driver
%DNF_COMPATIBLE_DRIVER   = &H00000040  ' Driver node represents a compatible driver
%DNF_INET_DRIVER         = &H00000080  ' Driver comes from an internet source
%DNF_UNUSED1             = &H00000100
%DNF_UNUSED2             = &H00000200
%DNF_OLD_INET_DRIVER     = &H00000400  ' Driver came from the Internet, but we don't currently
                                       ' have access to it's source files.  Never attempt to
                                       ' install a driver with this flag!
                                       ' Note used on Windows Vista and Later.
%DNF_BAD_DRIVER          = &H00000800  ' Driver node should not be used at all
%DNF_DUPPROVIDER         = &H00001000  ' Multiple drivers have the same provider and desc

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP
%DNF_INF_IS_SIGNED         = &H00002000  ' If file is digitally signed
%DNF_OEM_F6_INF            = &H00004000  ' INF specified from F6 during textmode setup.
%DNF_DUPDRIVERVER          = &H00008000  ' Multipe drivers have the same desc, provider, and DriverVer values
%DNF_BASIC_DRIVER          = &H00010000  ' Driver provides basic functionality, but should
                                         ' not be chosen if other signed drivers exist.
#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

#IF %SETUPAPI_VER >= %WIN32_WINNT_WS03
%DNF_AUTHENTICODE_SIGNED   = &H00020000  ' Inf file is signed by an Authenticode(tm) catalog.
#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WS03

#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN
%DNF_INSTALLEDDRIVER       = &H00040000  ' This driver node is currently installed on the device.
%DNF_ALWAYSEXCLUDEFROMLIST = &H00080000  ' If set, this driver is not even displayed in
                                         ' alternative platform either.
%DNF_INBOX_DRIVER          = &H00100000  ' This driver node came from an INF that shipped with Windows.
#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

#IF %SETUPAPI_VER >= %WIN32_WINNT_WIN7
%DNF_REQUESTADDITIONALSOFTWARE   = &H00200000  ' This driver is only part of a software solution needed
                                               ' by this device
#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WIN7

%DNF_UNUSED_22             = &H00400000
%DNF_UNUSED_23             = &H00800000
%DNF_UNUSED_24             = &H01000000
%DNF_UNUSED_25             = &H02000000
%DNF_UNUSED_26             = &H04000000
%DNF_UNUSED_27             = &H08000000
%DNF_UNUSED_28             = &H10000000
%DNF_UNUSED_29             = &H20000000
%DNF_UNUSED_30             = &H40000000
%DNF_UNUSED_31             = &H80000000???


'
' Rank values (the lower the Rank number, the better the Rank)
'
#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN
%DRIVER_HARDWAREID_RANK  = &H00000FFF  ' Any rank less than or equal to
                                       ' this value is a gold
                                       ' HardwareID match

%DRIVER_HARDWAREID_MASK  = &H80000FFF???  ' If you mask these bits off (AND)
                                       ' from the Rank and the result is 0
                                       ' then the Rank is a trusted HardwareID
                                       ' match

%DRIVER_UNTRUSTED_RANK   = &H80000000???  ' Any rank with this bit set is an
                                       ' "untrusted" rank, meaning that
                                       ' the INF was unsigned.

%DRIVER_W9X_SUSPECT_RANK = &HC0000000???  ' Any rank that is greater than
                                       ' or equal to this value, and lesser
                                       ' than or equal to = &HFFFF is suspected
                                       ' to be a Win9x-only driver, because
                                       ' (a) it isn't signed, and (b) there
                                       ' is no NT-specific decoration to
                                       ' explicitly indicate that the INF
                                       ' supports Windows NT/2000/XP

#ELSE
%DRIVER_HARDWAREID_RANK  = &H00000FFF  ' Any rank less than or equal to
                                       ' this value is a trusted
                                       ' HardwareID match

%DRIVER_COMPATID_RANK    = &H00003FFF  ' Any rank less than or equal to
                                       ' this (and greater than
                                       ' DRIVER_HARDWAREID_RANK) is a
                                       ' trusted CompatibleID match

%DRIVER_UNTRUSTED_RANK   = &H00008000  ' Any rank with this bit set is an
                                       ' "untrusted" rank, meaning that
                                       ' the INF was unsigned.

%DRIVER_UNTRUSTED_HARDWAREID_RANK  = &H00008FFF  ' Any rank less than or equal to
                                                 ' this value (and greater than
                                                 ' or equal to DRIVER_UNTRUSTED_RANK)
                                                 ' is an untrusted HardwareID match

%DRIVER_UNTRUSTED_COMPATID_RANK    = &H0000BFFF  ' Any rank less than or equal to
                                                 ' this value (and greater than
                                                 ' DRIVER_UNTRUSTED_HARDWAREID_RANK)
                                                 ' is an untrusted CompatibleID match

%DRIVER_W9X_SUSPECT_RANK            = &H0000C000 ' Any rank that is greater than
                                                 ' or equal to this value, and lesser
                                                 ' than or equal to = &HFFFF is suspected
                                                 ' to be a Win9x-only driver, because
                                                 ' (a) it isn't signed, and (b) there
                                                 ' is no NT-specific decoration to
                                                 ' explicitly indicate that the INF
                                                 ' supports Windows NT/2000/XP

%DRIVER_W9X_SUSPECT_HARDWAREID_RANK = &H0000CFFF ' Any rank less than or equal to this
                                                 ' (and greater than or equal to
                                                 ' DRIVER_W9X_SUSPECT_RANK) is a
                                                 ' hardware ID match suspected of being
                                                 ' only for Windows 9x platforms.

%DRIVER_W9X_SUSPECT_COMPATID_RANK   = &H0000FFFF ' Any rank less than or equal to
                                                 ' this (and greater than
                                                 ' DRIVER_W9X_SUSPECT_HARDWAREID_RANK)
                                                 ' is a compatible ID match suspected
                                                 ' of being only for Windows 9x
                                                 ' platforms.
#ENDIF ' %SETUPAPI_VER < %WIN32_WINNT_LONGHORN

'
' Setup callback routine for comparing detection signatures
'
DECLARE FUNCTION PSP_DETSIG_CMPPROC ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    NewDeviceData       AS SP_DEVINFO_DATA, _
    ExistingDeviceData  AS SP_DEVINFO_DATA, _
    CompareContext      AS ANY _    ' PVOID
    ) AS DWORD


'
' Define context structure handed to co-installers
'
TYPE COINSTALLER_CONTEXT_DATA
    PostProcessing AS LONG   ' BOOL
    InstallResult  AS DWORD
    PrivateData    AS DWORD  ' PVOID
END TYPE


'
' Structure containing class image list information.
'
TYPE SP_CLASSIMAGELIST_DATA
    cbSize    AS DWORD
    IMAGELIST AS DWORD  ' HIMAGELIST
    Reserved  AS DWORD  ' ULONG_PTR
END TYPE


'
' Structure to be passed as first parameter (LPVOID lpv) to ExtensionPropSheetPageProc
' entry point in setupapi.dll or to "EnumPropPages32" or "BasicProperties32" entry
' points provided by class/device property page providers.  Used to retrieve a handle
' (or, potentially, multiple handles) to property pages for a specified property page type.
'
TYPE SP_PROPSHEETPAGE_REQUEST
    cbSize         AS DWORD
    PageRequested  AS DWORD
    DeviceInfoSet  AS HDEVINFO
    DeviceInfoData AS SP_DEVINFO_DATA PTR
END TYPE

'
' Property sheet codes used in SP_PROPSHEETPAGE_REQUEST.PageRequested
'
%SPPSR_SELECT_DEVICE_RESOURCES      = 1  ' supplied by setupapi.dll
%SPPSR_ENUM_BASIC_DEVICE_PROPERTIES = 2  ' supplied by device's BasicProperties32 provider
%SPPSR_ENUM_ADV_DEVICE_PROPERTIES   = 3  ' supplied by class and/or device's EnumPropPages32 provider


'
' Structure used with SetupGetBackupInformation/SetupSetBackupInformation
'
TYPE SP_BACKUP_QUEUE_PARAMS_V2_A
    cbSize            AS DWORD                ' size of structure
    FullInfPath       AS ASCIIZ * %MAX_PATH   ' buffer to hold ANSI pathname of INF file
    FilenameOffset    AS LONG                 ' offset in CHARs of filename part (after '\')
    ReinstallInstance AS ASCIIZ * %MAX_PATH   ' Instance ID (if present)
END TYPE

TYPE SP_BACKUP_QUEUE_PARAMS_V2_W
    cbSize            AS DWORD                 ' size of structure
    FullInfPath       AS WSTRINGZ * %MAX_PATH  ' buffer to hold UNICODE pathname of INF file
    FilenameOffset    AS LONG                  ' offset in WCHARs of filename part (after '\')
    ReinstallInstance AS WSTRINGZ * %MAX_PATH  ' Instance ID (if present)
END TYPE

'
' Version 1 of the SP_BACKUP_QUEUE_PARAMS structures, used only for compatibility
' with Windows 2000/Windows 95/98/ME SETUPAPI.DLL
'
TYPE SP_BACKUP_QUEUE_PARAMS_V1_A
    cbSize         AS DWORD                   ' size of structure
    FullInfPath    AS ASCIIZ * %MAX_PATH      ' buffer to hold ANSI pathname of INF file
    FilenameOffset AS LONG                    ' offset in CHARs of filename part (after '\')
END TYPE

TYPE SP_BACKUP_QUEUE_PARAMS_V1_W
    cbSize         AS DWORD                   ' size of structure
    FullInfPath    AS WSTRINGZ * %MAX_PATH    ' buffer to hold UNICODE pathname of INF file
    FilenameOffset AS LONG                    ' offset in WCHARs of filename part (after '\')
END TYPE

#IF %DEF(%UNICODE)
TYPE SP_BACKUP_QUEUE_PARAMS_V1
    SP_BACKUP_QUEUE_PARAMS_V1_W
END TYPE
TYPE SP_BACKUP_QUEUE_PARAMS_V2
    SP_BACKUP_QUEUE_PARAMS_V2_W
END TYPE
#ELSE
TYPE SP_BACKUP_QUEUE_PARAMS_V1
    SP_BACKUP_QUEUE_PARAMS_V1_A
END TYPE
TYPE SP_BACKUP_QUEUE_PARAMS_V2
    SP_BACKUP_QUEUE_PARAMS_V2_A
END TYPE
#ENDIF


#IF %DEF(%USE_SP_BACKUP_QUEUE_PARAMS_V1) OR (%SETUPAPI_VER < %WIN32_WINNT_WINXP)  ' use version 1 driver info data structure

TYPE SP_BACKUP_QUEUE_PARAMS_A
    SP_BACKUP_QUEUE_PARAMS_V1_A
END TYPE
TYPE SP_BACKUP_QUEUE_PARAMS_W
    SP_BACKUP_QUEUE_PARAMS_V1_W
END TYPE
TYPE SP_BACKUP_QUEUE_PARAMS
    SP_BACKUP_QUEUE_PARAMS_V1
END TYPE

#ELSE                       ' use version 2 driver info data structure

TYPE SP_BACKUP_QUEUE_PARAMS_A
    SP_BACKUP_QUEUE_PARAMS_V2_A
END TYPE
TYPE SP_BACKUP_QUEUE_PARAMS_W
    SP_BACKUP_QUEUE_PARAMS_V2_W
END TYPE
TYPE SP_BACKUP_QUEUE_PARAMS
    SP_BACKUP_QUEUE_PARAMS_V2
END TYPE

#ENDIF  ' use current version of driver info data structure





'
' Setupapi-specific error codes
'
' Inf parse outcomes
'
%ERROR_EXPECTED_SECTION_NAME  = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR 0)
%ERROR_BAD_SECTION_NAME_LINE  = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR 1)
%ERROR_SECTION_NAME_TOO_LONG  = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR 2)
%ERROR_GENERAL_SYNTAX         = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR 3)
'
' Inf runtime errors
'
%ERROR_WRONG_INF_STYLE        = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H100)
%ERROR_SECTION_NOT_FOUND      = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H101)
%ERROR_LINE_NOT_FOUND         = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H102)
%ERROR_NO_BACKUP              = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H103)
'
' Device Installer/other errors
'
%ERROR_NO_ASSOCIATED_CLASS                = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H200)
%ERROR_CLASS_MISMATCH                     = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H201)
%ERROR_DUPLICATE_FOUND                    = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H202)
%ERROR_NO_DRIVER_SELECTED                 = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H203)
%ERROR_KEY_DOES_NOT_EXIST                 = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H204)
%ERROR_INVALID_DEVINST_NAME               = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H205)
%ERROR_INVALID_CLASS                      = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H206)
%ERROR_DEVINST_ALREADY_EXISTS             = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H207)
%ERROR_DEVINFO_NOT_REGISTERED             = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H208)
%ERROR_INVALID_REG_PROPERTY               = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H209)
%ERROR_NO_INF                             = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H20A)
%ERROR_NO_SUCH_DEVINST                    = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H20B)
%ERROR_CANT_LOAD_CLASS_ICON               = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H20C)
%ERROR_INVALID_CLASS_INSTALLER            = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H20D)
%ERROR_DI_DO_DEFAULT                      = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H20E)
%ERROR_DI_NOFILECOPY                      = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H20F)
%ERROR_INVALID_HWPROFILE                  = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H210)
%ERROR_NO_DEVICE_SELECTED                 = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H211)
%ERROR_DEVINFO_LIST_LOCKED                = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H212)
%ERROR_DEVINFO_DATA_LOCKED                = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H213)
%ERROR_DI_BAD_PATH                        = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H214)
%ERROR_NO_CLASSINSTALL_PARAMS             = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H215)
%ERROR_FILEQUEUE_LOCKED                   = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H216)
%ERROR_BAD_SERVICE_INSTALLSECT            = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H217)
%ERROR_NO_CLASS_DRIVER_LIST               = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H218)
%ERROR_NO_ASSOCIATED_SERVICE              = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H219)
%ERROR_NO_DEFAULT_DEVICE_INTERFACE        = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H21A)
%ERROR_DEVICE_INTERFACE_ACTIVE            = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H21B)
%ERROR_DEVICE_INTERFACE_REMOVED           = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H21C)
%ERROR_BAD_INTERFACE_INSTALLSECT          = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H21D)
%ERROR_NO_SUCH_INTERFACE_CLASS            = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H21E)
%ERROR_INVALID_REFERENCE_STRING           = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H21F)
%ERROR_INVALID_MACHINENAME                = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H220)
%ERROR_REMOTE_COMM_FAILURE                = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H221)
%ERROR_MACHINE_UNAVAILABLE                = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H222)
%ERROR_NO_CONFIGMGR_SERVICES              = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H223)
%ERROR_INVALID_PROPPAGE_PROVIDER          = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H224)
%ERROR_NO_SUCH_DEVICE_INTERFACE           = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H225)
%ERROR_DI_POSTPROCESSING_REQUIRED         = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H226)
%ERROR_INVALID_COINSTALLER                = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H227)
%ERROR_NO_COMPAT_DRIVERS                  = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H228)
%ERROR_NO_DEVICE_ICON                     = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H229)
%ERROR_INVALID_INF_LOGCONFIG              = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H22A)
%ERROR_DI_DONT_INSTALL                    = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H22B)
%ERROR_INVALID_FILTER_DRIVER              = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H22C)
%ERROR_NON_WINDOWS_NT_DRIVER              = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H22D)
%ERROR_NON_WINDOWS_DRIVER                 = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H22E)
%ERROR_NO_CATALOG_FOR_OEM_INF             = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H22F)
%ERROR_DEVINSTALL_QUEUE_NONNATIVE         = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H230)
%ERROR_NOT_DISABLEABLE                    = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H231)
%ERROR_CANT_REMOVE_DEVINST                = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H232)
%ERROR_INVALID_TARGET                     = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H233)
%ERROR_DRIVER_NONNATIVE                   = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H234)
%ERROR_IN_WOW64                           = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H235)
%ERROR_SET_SYSTEM_RESTORE_POINT           = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H236)

%ERROR_SCE_DISABLED                       = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H238)
%ERROR_UNKNOWN_EXCEPTION                  = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H239)
%ERROR_PNP_REGISTRY_ERROR                 = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H23A)
%ERROR_REMOTE_REQUEST_UNSUPPORTED         = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H23B)
%ERROR_NOT_AN_INSTALLED_OEM_INF           = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H23C)
%ERROR_INF_IN_USE_BY_DEVICES              = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H23D)
%ERROR_DI_FUNCTION_OBSOLETE               = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H23E)
%ERROR_NO_AUTHENTICODE_CATALOG            = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H23F)
%ERROR_AUTHENTICODE_DISALLOWED            = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H240)
%ERROR_AUTHENTICODE_TRUSTED_PUBLISHER     = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H241)
%ERROR_AUTHENTICODE_TRUST_NOT_ESTABLISHED = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H242)
%ERROR_AUTHENTICODE_PUBLISHER_NOT_TRUSTED = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H243)
%ERROR_SIGNATURE_OSATTRIBUTE_MISMATCH     = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H244)
%ERROR_ONLY_VALIDATE_VIA_AUTHENTICODE     = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H245)
%ERROR_DEVICE_INSTALLER_NOT_READY         = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H246)
%ERROR_DRIVER_STORE_ADD_FAILED            = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H247)
%ERROR_DEVICE_INSTALL_BLOCKED             = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H248)
%ERROR_DRIVER_INSTALL_BLOCKED             = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H249)
%ERROR_WRONG_INF_TYPE                     = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H24A)
%ERROR_FILE_HASH_NOT_IN_CATALOG           = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H24B)
%ERROR_DRIVER_STORE_DELETE_FAILED         = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H24C)

'
' Setupapi exception codes
'
%ERROR_UNRECOVERABLE_STACK_OVERFLOW = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H300)
%EXCEPTION_SPAPI_UNRECOVERABLE_STACK_OVERFLOW = %ERROR_UNRECOVERABLE_STACK_OVERFLOW

'
' Backward compatibility--do not use.
'
%ERROR_NO_DEFAULT_INTERFACE_DEVICE = %ERROR_NO_DEFAULT_DEVICE_INTERFACE
%ERROR_INTERFACE_DEVICE_ACTIVE     = %ERROR_DEVICE_INTERFACE_ACTIVE
%ERROR_INTERFACE_DEVICE_REMOVED    = %ERROR_DEVICE_INTERFACE_REMOVED
%ERROR_NO_SUCH_INTERFACE_DEVICE    = %ERROR_NO_SUCH_DEVICE_INTERFACE


'
' Win9x migration DLL error code
'
%ERROR_NOT_INSTALLED = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H1000)

DECLARE FUNCTION SetupGetInfInformationA LIB "SetupApi.dll" _
    ALIAS "SetupGetInfInformationA" (_
    InfSpec                AS ANY, _   ' LPCVOID
    BYVAL SearchControl    AS DWORD, _
    BYVAL ReturnBuffer     AS SP_INF_INFORMATION PTR, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize           AS DWORD  _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupGetInfInformationW LIB "SetupApi.dll" _
    ALIAS "SetupGetInfInformationW" (_
    InfSpec                AS ANY, _   ' LPCVOID
    BYVAL SearchControl    AS DWORD, _
    BYVAL ReturnBuffer     AS SP_INF_INFORMATION PTR, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize           AS DWORD  _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupGetInfInformation LIB "SetupApi.dll" _
    ALIAS "SetupGetInfInformationW" (_
    InfSpec                AS ANY, _   ' LPCVOID
    BYVAL SearchControl    AS DWORD, _
    BYVAL ReturnBuffer     AS SP_INF_INFORMATION PTR, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize           AS DWORD  _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupGetInfInformation LIB "SetupApi.dll" _
    ALIAS "SetupGetInfInformationA" (_
    InfSpec                AS ANY, _   ' LPCVOID
    BYVAL SearchControl    AS DWORD, _
    BYVAL ReturnBuffer     AS SP_INF_INFORMATION PTR, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize           AS DWORD  _
    ) AS LONG  ' BOOL
#ENDIF


'
' SearchControl flags for SetupGetInfInformation
'
%INFINFO_INF_SPEC_IS_HINF       = 1
%INFINFO_INF_NAME_IS_ABSOLUTE   = 2
%INFINFO_DEFAULT_SEARCH         = 3
%INFINFO_REVERSE_DEFAULT_SEARCH = 4
%INFINFO_INF_PATH_LIST_SEARCH   = 5


DECLARE FUNCTION SetupQueryInfFileInformationA LIB "SetupApi.dll" _
    ALIAS "SetupQueryInfFileInformationA" ( _
    BYVAL InfInformation   AS SP_INF_INFORMATION PTR, _
    BYVAL InfIndex         AS DWORD, _
    ReturnBuffer           AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize           AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupQueryInfFileInformationW LIB "SetupApi.dll" _
    ALIAS "SetupQueryInfFileInformationW" ( _
    BYVAL InfInformation   AS SP_INF_INFORMATION PTR, _
    BYVAL InfIndex         AS DWORD, _
    ReturnBuffer           AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize           AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupQueryInfFileInformation LIB "SetupApi.dll" _
    ALIAS "SetupQueryInfFileInformationW" ( _
    BYVAL InfInformation   AS SP_INF_INFORMATION PTR, _
    BYVAL InfIndex         AS DWORD, _
    ReturnBuffer           AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize           AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupQueryInfFileInformation LIB "SetupApi.dll" _
    ALIAS "SetupQueryInfFileInformationA" ( _
    BYVAL InfInformation   AS SP_INF_INFORMATION PTR, _
    BYVAL InfIndex         AS DWORD, _
    ReturnBuffer           AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize           AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupQueryInfOriginalFileInformationA LIB "SetupApi.dll" _
    ALIAS "SetupQueryInfOriginalFileInformationA" ( _
    BYVAL InfInformation        AS SP_INF_INFORMATION PTR, _
    BYVAL InfIndex              AS DWORD, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    BYVAL OriginalFileInfo      AS SP_ORIGINAL_FILE_INFO_A PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupQueryInfOriginalFileInformationW LIB "SetupApi.dll" _
    ALIAS "SetupQueryInfOriginalFileInformationW" ( _
    BYVAL InfInformation        AS SP_INF_INFORMATION PTR, _
    BYVAL InfIndex              AS DWORD, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    BYVAL OriginalFileInfo      AS SP_ORIGINAL_FILE_INFO_W PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupQueryInfOriginalFileInformation LIB "SetupApi.dll" _
    ALIAS "SetupQueryInfOriginalFileInformationW" ( _
    BYVAL InfInformation        AS SP_INF_INFORMATION PTR, _
    BYVAL InfIndex              AS DWORD, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    BYVAL OriginalFileInfo      AS SP_ORIGINAL_FILE_INFO_W PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupQueryInfOriginalFileInformation LIB "SetupApi.dll" _
    ALIAS "SetupQueryInfOriginalFileInformationA" ( _
    BYVAL InfInformation        AS SP_INF_INFORMATION PTR, _
    BYVAL InfIndex              AS DWORD, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    BYVAL OriginalFileInfo      AS SP_ORIGINAL_FILE_INFO_A PTR _
    ) AS LONG  ' BOOL
#ENDIF

DECLARE FUNCTION SetupQueryInfVersionInformationA LIB "SetupApi.dll" _
    ALIAS "SetupQueryInfVersionInformationA" ( _
    BYVAL InfInformation   AS SP_INF_INFORMATION PTR, _
    BYVAL InfIndex         AS DWORD, _
    KEY                    AS ASCIIZ, _
    ReturnBuffer           AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize           AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupQueryInfVersionInformationW LIB "SetupApi.dll" _
    ALIAS "SetupQueryInfVersionInformationW" ( _
    BYVAL InfInformation   AS SP_INF_INFORMATION PTR, _
    BYVAL InfIndex         AS DWORD, _
    KEY                    AS WSTRINGZ, _
    ReturnBuffer           AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize           AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupQueryInfVersionInformation LIB "SetupApi.dll" _
    ALIAS "SetupQueryInfVersionInformationW" ( _
    BYVAL InfInformation   AS SP_INF_INFORMATION PTR, _
    BYVAL InfIndex         AS DWORD, _
    KEY                    AS WSTRINGZ, _
    ReturnBuffer           AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize           AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupQueryInfVersionInformation LIB "SetupApi.dll" _
    ALIAS "SetupQueryInfVersionInformationA" ( _
    BYVAL InfInformation   AS SP_INF_INFORMATION PTR, _
    BYVAL InfIndex         AS DWORD, _
    KEY                    AS ASCIIZ, _
    ReturnBuffer           AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize           AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

DECLARE FUNCTION SetupGetInfDriverStoreLocationA LIB "SetupApi.dll" _
    ALIAS "SetupGetInfDriverStoreLocationA" ( _
    FileName                    AS ASCIIZ, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    LocaleName                  AS ASCIIZ, _
    ReturnBuffer                AS ASCIIZ, _
    BYVAL ReturnBufferSize      AS DWORD, _
    RequiredSize                AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupGetInfDriverStoreLocationW LIB "SetupApi.dll" _
    ALIAS "SetupGetInfDriverStoreLocationW" ( _
    FileName                    AS WSTRINGZ, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    LocaleName                  AS WSTRINGZ, _
    ReturnBuffer                AS WSTRINGZ, _
    BYVAL ReturnBufferSize      AS DWORD, _
    RequiredSize                AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupGetInfDriverStoreLocation LIB "SetupApi.dll" _
    ALIAS "SetupGetInfDriverStoreLocationW" ( _
    FileName                    AS WSTRINGZ, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    LocaleName                  AS WSTRINGZ, _
    ReturnBuffer                AS WSTRINGZ, _
    BYVAL ReturnBufferSize      AS DWORD, _
    RequiredSize                AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupGetInfDriverStoreLocation LIB "SetupApi.dll" _
    ALIAS "SetupGetInfDriverStoreLocationA" ( _
    FileName                    AS ASCIIZ, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    LocaleName                  AS ASCIIZ, _
    ReturnBuffer                AS ASCIIZ, _
    BYVAL ReturnBufferSize      AS DWORD, _
    RequiredSize                AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

DECLARE FUNCTION SetupGetInfPublishedNameA LIB "SetupApi.dll" _
    ALIAS "SetupGetInfPublishedNameA" ( _
    DriverStoreLocation AS ASCIIZ, _
    ReturnBuffer AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupGetInfPublishedNameW LIB "SetupApi.dll" _
    ALIAS "SetupGetInfPublishedNameW" ( _
    DriverStoreLocation AS WSTRINGZ, _
    ReturnBuffer AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupGetInfPublishedName LIB "SetupApi.dll" _
    ALIAS "SetupGetInfPublishedNameW" ( _
    DriverStoreLocation AS WSTRINGZ, _
    ReturnBuffer AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupGetInfPublishedName LIB "SetupApi.dll" _
    ALIAS "SetupGetInfPublishedNameA" ( _
    DriverStoreLocation AS ASCIIZ, _
    ReturnBuffer AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN


DECLARE FUNCTION SetupGetInfFileListA LIB "SetupApi.dll" _
    ALIAS "SetupGetInfFileListA" ( _
    DirectoryPath AS ASCIIZ, _
    BYVAL InfStyle AS DWORD, _
    ReturnBuffer AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupGetInfFileListW LIB "SetupApi.dll" _
    ALIAS "SetupGetInfFileListW" ( _
    DirectoryPath AS WSTRINGZ, _
    BYVAL InfStyle AS DWORD, _
    ReturnBuffer AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupGetInfFileList LIB "SetupApi.dll" _
    ALIAS "SetupGetInfFileListW" ( _
    DirectoryPath AS WSTRINGZ, _
    BYVAL InfStyle AS DWORD, _
    ReturnBuffer AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupGetInfFileList LIB "SetupApi.dll" _
    ALIAS "SetupGetInfFileListA" ( _
    DirectoryPath AS ASCIIZ, _
    BYVAL InfStyle AS DWORD, _
    ReturnBuffer AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupOpenInfFileW LIB "SetupApi.dll" _
    ALIAS "SetupOpenInfFileW" ( _
    FileName AS WSTRINGZ, _
    InfClass AS WSTRINGZ, _
    BYVAL InfStyle AS DWORD, _
    ErrorLine AS DWORD _
    ) AS HINF

DECLARE FUNCTION SetupOpenInfFileA LIB "SetupApi.dll" _
    ALIAS "SetupOpenInfFileA" ( _
    FileName AS ASCIIZ, _
    InfClass AS ASCIIZ, _
    BYVAL InfStyle AS DWORD, _
    ErrorLine AS DWORD _
    ) AS HINF

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupOpenInfFile LIB "SetupApi.dll" _
    ALIAS "SetupOpenInfFileW" ( _
    FileName AS WSTRINGZ, _
    InfClass AS WSTRINGZ, _
    BYVAL InfStyle AS DWORD, _
    ErrorLine AS DWORD _
    ) AS HINF
#ELSE
DECLARE FUNCTION SetupOpenInfFile LIB "SetupApi.dll" _
    ALIAS "SetupOpenInfFileA" ( _
    FileName AS ASCIIZ, _
    InfClass AS ASCIIZ, _
    BYVAL InfStyle AS DWORD, _
    ErrorLine AS DWORD _
    ) AS HINF
#ENDIF


DECLARE FUNCTION SetupOpenMasterInf LIB "SetupApi.dll" _
    ALIAS "SetupOpenMasterInf" () AS HINF


DECLARE FUNCTION SetupOpenAppendInfFileW LIB "SetupApi.dll" _
    ALIAS "SetupOpenAppendInfFileW" ( _
    FileName AS WSTRINGZ, _
    BYVAL InfHandle AS HINF, _
    ErrorLine AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupOpenAppendInfFileA LIB "SetupApi.dll" _
    ALIAS "SetupOpenAppendInfFileA" ( _
    FileName AS ASCIIZ, _
    BYVAL InfHandle AS HINF, _
    ErrorLine AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupOpenAppendInfFile LIB "SetupApi.dll" _
    ALIAS "SetupOpenAppendInfFileW" ( _
    FileName AS WSTRINGZ, _
    BYVAL InfHandle AS HINF, _
    ErrorLine AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupOpenAppendInfFile LIB "SetupApi.dll" _
    ALIAS "SetupOpenAppendInfFileA" ( _
    FileName AS ASCIIZ, _
    BYVAL InfHandle AS HINF, _
    ErrorLine AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE SUB SetupCloseInfFile LIB "SetupApi.dll" ALIAS "SetupCloseInfFile" _
    (BYVAL InfHandle AS HINF)


DECLARE FUNCTION SetupFindFirstLineA LIB "SetupApi.dll" _
    ALIAS "SetupFindFirstLineA" ( _
    BYVAL InfHandle AS HINF, _
    Section         AS ASCIIZ, _
    KEY             AS ASCIIZ, _
    Context         AS INFCONTEXT _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupFindFirstLineW LIB "SetupApi.dll" _
    ALIAS "SetupFindFirstLineW" ( _
    BYVAL InfHandle AS HINF, _
    Section         AS WSTRINGZ, _
    KEY             AS WSTRINGZ, _
    Context         AS INFCONTEXT _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupFindFirstLine LIB "SetupApi.dll" _
    ALIAS "SetupFindFirstLineW" ( _
    BYVAL InfHandle AS HINF, _
    Section         AS WSTRINGZ, _
    KEY             AS WSTRINGZ, _
    Context         AS INFCONTEXT _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupFindFirstLine LIB "SetupApi.dll" _
    ALIAS "SetupFindFirstLineA" ( _
    BYVAL InfHandle AS HINF, _
    Section         AS ASCIIZ, _
    KEY             AS ASCIIZ, _
    Context         AS INFCONTEXT _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupFindNextLine LIB "SetupApi.dll" _
    ALIAS "SetupFindNextLine" ( _
    ContextIn AS INFCONTEXT, _
    ContextOut AS INFCONTEXT _
    ) AS LONG  ' BOOL


DECLARE FUNCTION SetupFindNextMatchLineA LIB "SetupApi.dll" _
    ALIAS "SetupFindNextMatchLineA" ( _
    ContextIn AS INFCONTEXT, _
    KEY AS ASCIIZ, _
    ContextOut AS INFCONTEXT _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupFindNextMatchLineW LIB "SetupApi.dll" _
    ALIAS "SetupFindNextMatchLineW" ( _
    ContextIn AS INFCONTEXT, _
    KEY AS WSTRINGZ, _
    ContextOut AS INFCONTEXT _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupFindNextMatchLine LIB "SetupApi.dll" _
    ALIAS "SetupFindNextMatchLineW" ( _
    ContextIn AS INFCONTEXT, _
    KEY AS WSTRINGZ, _
    ContextOut AS INFCONTEXT _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupFindNextMatchLine LIB "SetupApi.dll" _
    ALIAS "SetupFindNextMatchLineA" ( _
    ContextIn AS INFCONTEXT, _
    KEY AS ASCIIZ, _
    ContextOut AS INFCONTEXT _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupGetLineByIndexA LIB "SetupApi.dll" _
    ALIAS "SetupGetLineByIndexA" ( _
    BYVAL InfHandle AS HINF, _
    Section AS ASCIIZ, _
    BYVAL Index AS DWORD, _
    Context AS INFCONTEXT _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupGetLineByIndexW LIB "SetupApi.dll" _
    ALIAS "SetupGetLineByIndexW" ( _
    BYVAL InfHandle AS HINF, _
    Section AS WSTRINGZ, _
    BYVAL Index AS DWORD, _
    Context AS INFCONTEXT _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupGetLineByIndex LIB "SetupApi.dll" _
    ALIAS "SetupGetLineByIndexW" ( _
    BYVAL InfHandle AS HINF, _
    Section AS WSTRINGZ, _
    BYVAL Index AS DWORD, _
    Context AS INFCONTEXT _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupGetLineByIndex LIB "SetupApi.dll" _
    ALIAS "SetupGetLineByIndexA" ( _
    BYVAL InfHandle AS HINF, _
    Section AS ASCIIZ, _
    BYVAL Index AS DWORD, _
    Context AS INFCONTEXT _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupGetLineCountA LIB "SetupApi.dll" _
    ALIAS "SetupGetLineCountA" ( _
    BYVAL InfHandle AS HINF, _
    Section AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupGetLineCountW LIB "SetupApi.dll" _
    ALIAS "SetupGetLineCountW" ( _
    BYVAL InfHandle AS HINF, _
    Section AS WSTRINGZ _
    ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupGetLineCount LIB "SetupApi.dll" _
    ALIAS "SetupGetLineCountW" ( _
    BYVAL InfHandle AS HINF, _
    Section AS WSTRINGZ _
    ) AS LONG
#ELSE
DECLARE FUNCTION SetupGetLineCount LIB "SetupApi.dll" _
    ALIAS "SetupGetLineCountA" ( _
    BYVAL InfHandle AS HINF, _
    Section AS ASCIIZ _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupGetLineTextA LIB "SetupApi.dll" _
    ALIAS "SetupGetLineTextA" ( _
    Context AS INFCONTEXT, _
    BYVAL InfHandle AS HINF, _
    Section AS ASCIIZ, _
    KEY AS ASCIIZ, _
    ReturnBuffer AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupGetLineTextW LIB "SetupApi.dll" _
    ALIAS "SetupGetLineTextW" ( _
    Context AS INFCONTEXT, _
    BYVAL InfHandle AS HINF, _
    Section AS WSTRINGZ, _
    KEY AS WSTRINGZ, _
    ReturnBuffer AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupGetLineText LIB "SetupApi.dll" _
    ALIAS "SetupGetLineTextW" ( _
    Context AS INFCONTEXT, _
    BYVAL InfHandle AS HINF, _
    Section AS WSTRINGZ, _
    KEY AS WSTRINGZ, _
    ReturnBuffer AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupGetLineText LIB "SetupApi.dll" _
    ALIAS "SetupGetLineTextA" ( _
    Context AS INFCONTEXT, _
    BYVAL InfHandle AS HINF, _
    Section AS ASCIIZ, _
    KEY AS ASCIIZ, _
    ReturnBuffer AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupGetFieldCount LIB "SetupApi.dll" _
    ALIAS "SetupGetFieldCount" ( _
    Context AS INFCONTEXT _
    ) AS DWORD


DECLARE FUNCTION SetupGetStringFieldA LIB "SetupApi.dll" _
    ALIAS "SetupGetStringFieldA" ( _
    Context AS INFCONTEXT, _
    BYVAL FieldIndex AS DWORD, _
    ReturnBuffer AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupGetStringFieldW LIB "SetupApi.dll" _
    ALIAS "SetupGetStringFieldW" ( _
    Context AS INFCONTEXT, _
    BYVAL FieldIndex AS DWORD, _
    ReturnBuffer AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupGetStringField LIB "SetupApi.dll" _
    ALIAS "SetupGetStringFieldW" ( _
    Context AS INFCONTEXT, _
    BYVAL FieldIndex AS DWORD, _
    ReturnBuffer AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupGetStringField LIB "SetupApi.dll" _
    ALIAS "SetupGetStringFieldA" ( _
    Context AS INFCONTEXT, _
    BYVAL FieldIndex AS DWORD, _
    ReturnBuffer AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupGetIntField LIB "SetupApi.dll" _
    ALIAS "SetupGetIntField" ( _
    Context AS INFCONTEXT, _
    BYVAL FieldIndex AS DWORD, _
    IntegerValue AS LONG _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupGetMultiSzFieldA LIB "SetupApi.dll" _
    ALIAS "SetupGetMultiSzFieldA" ( _
    Context AS INFCONTEXT, _
    BYVAL FieldIndex AS DWORD, _
    ReturnBuffer AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupGetMultiSzFieldW LIB "SetupApi.dll" _
    ALIAS "SetupGetMultiSzFieldW" ( _
    Context AS INFCONTEXT, _
    BYVAL FieldIndex AS DWORD, _
    ReturnBuffer AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupGetMultiSzField LIB "SetupApi.dll" _
    ALIAS "SetupGetMultiSzFieldW" ( _
    Context AS INFCONTEXT, _
    BYVAL FieldIndex AS DWORD, _
    ReturnBuffer AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupGetMultiSzField LIB "SetupApi.dll" _
    ALIAS "SetupGetMultiSzFieldA" ( _
    Context AS INFCONTEXT, _
    BYVAL FieldIndex AS DWORD, _
    ReturnBuffer AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupGetBinaryField LIB "SetupApi.dll" _
    ALIAS "SetupGetBinaryField" ( _
    Context AS INFCONTEXT, _
    BYVAL FieldIndex AS DWORD, _
    BYVAL ReturnBuffer AS BYTE PTR, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

'
' SetupGetFileCompressionInfo is depreciated
' use SetupGetFileCompressionInfoEx instead
'
' ActualSourceFileName returned by SetupGetFileCompressionInfo
' must be freed by the export setupapi!MyFree (NT4+ Win95+)
' or LocalFree (Win2k+)
'
DECLARE FUNCTION SetupGetFileCompressionInfoA LIB "SetupApi.dll" _
    ALIAS "SetupGetFileCompressionInfoA" ( _
    SourceFileName AS ASCIIZ, _
    BYVAL ActualSourceFileName AS DWORD, _  ' PSTR *
    SourceFileSize AS DWORD, _
    TargetFileSize AS DWORD, _
    CompressionType AS DWORD _
    ) AS DWORD

DECLARE FUNCTION SetupGetFileCompressionInfoW LIB "SetupApi.dll" _
    ALIAS "SetupGetFileCompressionInfoW" ( _
    SourceFileName AS WSTRINGZ, _
    BYVAL ActualSourceFileName AS DWORD, _  ' PWSTR *
    SourceFileSize AS DWORD, _
    TargetFileSize AS DWORD, _
    CompressionType AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupGetFileCompressionInfo LIB "SetupApi.dll" _
    ALIAS "SetupGetFileCompressionInfoW" ( _
    SourceFileName AS WSTRINGZ, _
    BYVAL ActualSourceFileName AS DWORD, _  ' PWSTR *
    SourceFileSize AS DWORD, _
    TargetFileSize AS DWORD, _
    CompressionType AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetupGetFileCompressionInfo LIB "SetupApi.dll" _
    ALIAS "SetupGetFileCompressionInfoA" ( _
    SourceFileName AS ASCIIZ, _
    BYVAL ActualSourceFileName AS DWORD, _  ' PSTR *
    SourceFileSize AS DWORD, _
    TargetFileSize AS DWORD, _
    CompressionType AS DWORD _
    ) AS DWORD
#ENDIF

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

'
' SetupGetFileCompressionInfoEx is the preferred API over
' SetupGetFileCompressionInfo. It follows the normal
' conventions of returning BOOL and writing to user-supplied
' buffer.
'

DECLARE FUNCTION SetupGetFileCompressionInfoExA LIB "SetupApi.dll" _
    ALIAS "SetupGetFileCompressionInfoExA" ( _
    SourceFileName AS ASCIIZ, _
    ActualSourceFileNameBuffer AS ASCIIZ, _
    BYVAL ActualSourceFileNameBufferLen AS DWORD, _
    RequiredBufferLen AS DWORD, _
    SourceFileSize AS DWORD, _
    TargetFileSize AS DWORD, _
    CompressionType AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupGetFileCompressionInfoExW LIB "SetupApi.dll" _
    ALIAS "SetupGetFileCompressionInfoExW" ( _
    SourceFileName AS WSTRINGZ, _
    ActualSourceFileNameBuffer AS WSTRINGZ, _
    BYVAL ActualSourceFileNameBufferLen AS DWORD, _
    RequiredBufferLen AS DWORD, _
    SourceFileSize AS DWORD, _
    TargetFileSize AS DWORD, _
    CompressionType AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupGetFileCompressionInfoEx LIB "SetupApi.dll" _
    ALIAS "SetupGetFileCompressionInfoExW" ( _
    SourceFileName AS WSTRINGZ, _
    ActualSourceFileNameBuffer AS WSTRINGZ, _
    BYVAL ActualSourceFileNameBufferLen AS DWORD, _
    RequiredBufferLen AS DWORD, _
    SourceFileSize AS DWORD, _
    TargetFileSize AS DWORD, _
    CompressionType AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupGetFileCompressionInfoEx LIB "SetupApi.dll" _
    ALIAS "SetupGetFileCompressionInfoExA" ( _
    SourceFileName AS ASCIIZ, _
    ActualSourceFileNameBuffer AS ASCIIZ, _
    BYVAL ActualSourceFileNameBufferLen AS DWORD, _
    RequiredBufferLen AS DWORD, _
    SourceFileSize AS DWORD, _
    TargetFileSize AS DWORD, _
    CompressionType AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

'
' Compression types
'
%FILE_COMPRESSION_NONE     = 0
%FILE_COMPRESSION_WINLZA   = 1
%FILE_COMPRESSION_MSZIP    = 2
%FILE_COMPRESSION_NTCAB    = 3


DECLARE FUNCTION SetupDecompressOrCopyFileA LIB "SetupApi.dll" _
    ALIAS "SetupDecompressOrCopyFileA" ( _
    SourceFileName AS ASCIIZ, _
    TargetFileName AS ASCIIZ, _
    CompressionType AS DWORD _
    ) AS DWORD

DECLARE FUNCTION SetupDecompressOrCopyFileW LIB "SetupApi.dll" _
    ALIAS "SetupDecompressOrCopyFileW" ( _
    SourceFileName AS WSTRINGZ, _
    TargetFileName AS WSTRINGZ, _
    CompressionType AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDecompressOrCopyFile LIB "SetupApi.dll" _
    ALIAS "SetupDecompressOrCopyFileW" ( _
    SourceFileName AS WSTRINGZ, _
    TargetFileName AS WSTRINGZ, _
    CompressionType AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetupDecompressOrCopyFile LIB "SetupApi.dll" _
    ALIAS "SetupDecompressOrCopyFileA" ( _
    SourceFileName AS ASCIIZ, _
    TargetFileName AS ASCIIZ, _
    CompressionType AS DWORD _
    ) AS DWORD
#ENDIF


DECLARE FUNCTION SetupGetSourceFileLocationA LIB "SetupApi.dll" _
    ALIAS "SetupGetSourceFileLocationA" ( _
    BYVAL InfHandle AS HINF, _
    InfContext AS INFCONTEXT, _
    FileName AS ASCIIZ, _
    SourceId AS DWORD, _
    ReturnBuffer AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupGetSourceFileLocationW LIB "SetupApi.dll" _
    ALIAS "SetupGetSourceFileLocationW" ( _
    BYVAL InfHandle AS HINF, _
    InfContext AS INFCONTEXT, _
    FileName AS WSTRINGZ, _
    SourceId AS DWORD, _
    ReturnBuffer AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupGetSourceFileLocation LIB "SetupApi.dll" _
    ALIAS "SetupGetSourceFileLocationW" ( _
    BYVAL InfHandle AS HINF, _
    InfContext AS INFCONTEXT, _
    FileName AS WSTRINGZ, _
    SourceId AS DWORD, _
    ReturnBuffer AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupGetSourceFileLocation LIB "SetupApi.dll" _
    ALIAS "SetupGetSourceFileLocationA" ( _
    BYVAL InfHandle AS HINF, _
    InfContext AS INFCONTEXT, _
    FileName AS ASCIIZ, _
    SourceId AS DWORD, _
    ReturnBuffer AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupGetSourceFileSizeA LIB "SetupApi.dll" _
    ALIAS "SetupGetSourceFileSizeA" ( _
    BYVAL InfHandle AS HINF, _
    InfContext AS INFCONTEXT, _
    FileName AS ASCIIZ, _
    Section AS ASCIIZ, _
    FileSize AS DWORD, _
    BYVAL RoundingFactor AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupGetSourceFileSizeW LIB "SetupApi.dll" _
    ALIAS "SetupGetSourceFileSizeW" ( _
    BYVAL InfHandle AS HINF, _
    InfContext AS INFCONTEXT, _
    FileName AS WSTRINGZ, _
    Section AS WSTRINGZ, _
    FileSize AS DWORD, _
    BYVAL RoundingFactor AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupGetSourceFileSize LIB "SetupApi.dll" _
    ALIAS "SetupGetSourceFileSizeW" ( _
    BYVAL InfHandle AS HINF, _
    InfContext AS INFCONTEXT, _
    FileName AS WSTRINGZ, _
    Section AS WSTRINGZ, _
    FileSize AS DWORD, _
    BYVAL RoundingFactor AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupGetSourceFileSize LIB "SetupApi.dll" _
    ALIAS "SetupGetSourceFileSizeA" ( _
    BYVAL InfHandle AS HINF, _
    InfContext AS INFCONTEXT, _
    FileName AS ASCIIZ, _
    Section AS ASCIIZ, _
    FileSize AS DWORD, _
    BYVAL RoundingFactor AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupGetTargetPathA LIB "SetupApi.dll" _
    ALIAS "SetupGetTargetPathA" ( _
    BYVAL InfHandle AS HINF, _
    InfContext AS INFCONTEXT, _
    Section AS ASCIIZ, _
    ReturnBuffer AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupGetTargetPathW LIB "SetupApi.dll" _
    ALIAS "SetupGetTargetPathW" ( _
    BYVAL InfHandle AS HINF, _
    InfContext AS INFCONTEXT, _
    Section AS WSTRINGZ, _
    ReturnBuffer AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupGetTargetPath LIB "SetupApi.dll" _
    ALIAS "SetupGetTargetPathW" ( _
    BYVAL InfHandle AS HINF, _
    InfContext AS INFCONTEXT, _
    Section AS WSTRINGZ, _
    ReturnBuffer AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION SetupGetTargetPath LIB "SetupApi.dll" _
    ALIAS "SetupGetTargetPathA" ( _
    BYVAL InfHandle AS HINF, _
    InfContext AS INFCONTEXT, _
    Section AS ASCIIZ, _
    ReturnBuffer AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


'
' Define flags for SourceList APIs.
'
%SRCLIST_TEMPORARY       = &H00000001
%SRCLIST_NOBROWSE        = &H00000002
%SRCLIST_SYSTEM          = &H00000010
%SRCLIST_USER            = &H00000020
%SRCLIST_SYSIFADMIN      = &H00000040
%SRCLIST_SUBDIRS         = &H00000100
%SRCLIST_APPEND          = &H00000200
%SRCLIST_NOSTRIPPLATFORM = &H00000400


DECLARE FUNCTION SetupSetSourceListA LIB "SetupApi.dll" _
    ALIAS "SetupSetSourceListA" ( _
    BYVAL Flags AS DWORD, _
    BYVAL SourceList AS DWORD, _  ' PCSTR *
    BYVAL SourceCount AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupSetSourceListW LIB "SetupApi.dll" _
    ALIAS "SetupSetSourceListW" ( _
    BYVAL Flags AS DWORD, _
    BYVAL SourceList AS DWORD, _  ' PCWSTR *
    BYVAL SourceCount AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupSetSourceList LIB "SetupApi.dll" _
    ALIAS "SetupSetSourceListW" ( _
    BYVAL Flags AS DWORD, _
    BYVAL SourceList AS DWORD, _  ' PCWSTR *
    BYVAL SourceCount AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupSetSourceList LIB "SetupApi.dll" _
    ALIAS "SetupSetSourceListA" ( _
    BYVAL Flags AS DWORD, _
    BYVAL SourceList AS DWORD, _  ' PCSTR *
    BYVAL SourceCount AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupCancelTemporarySourceList LIB "SetupApi.dll" _
    ALIAS "SetupCancelTemporarySourceList" () AS LONG  ' BOOL


DECLARE FUNCTION SetupAddToSourceListA LIB "SetupApi.dll" _
    ALIAS "SetupAddToSourceListA" ( _
    BYVAL Flags AS DWORD, _
    SOURCE AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupAddToSourceListW LIB "SetupApi.dll" _
    ALIAS "SetupAddToSourceListW" ( _
    BYVAL Flags AS DWORD, _
    SOURCE AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupAddToSourceList LIB "SetupApi.dll" _
    ALIAS "SetupAddToSourceListW" ( _
    BYVAL Flags AS DWORD, _
    SOURCE AS WSTRINGZ _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupAddToSourceList LIB "SetupApi.dll" _
    ALIAS "SetupAddToSourceListA" ( _
    BYVAL Flags AS DWORD, _
    SOURCE AS ASCIIZ _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupRemoveFromSourceListA LIB "SetupApi.dll" _
    ALIAS "SetupRemoveFromSourceListA" ( _
    BYVAL Flags AS DWORD, _
    SOURCE AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupRemoveFromSourceListW LIB "SetupApi.dll" _
    ALIAS "SetupRemoveFromSourceListW" ( _
    BYVAL Flags AS DWORD, _
    SOURCE AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupRemoveFromSourceList LIB "SetupApi.dll" _
    ALIAS "SetupRemoveFromSourceListW" ( _
    BYVAL Flags AS DWORD, _
    SOURCE AS WSTRINGZ _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupRemoveFromSourceList LIB "SetupApi.dll" _
    ALIAS "SetupRemoveFromSourceListA" ( _
    BYVAL Flags AS DWORD, _
    SOURCE AS ASCIIZ _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupQuerySourceListA LIB "SetupApi.dll" _
    ALIAS "SetupQuerySourceListA" ( _
    BYVAL Flags AS DWORD, _
    List AS ANY, _    ' PCSTR **
    COUNT AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupQuerySourceListW LIB "SetupApi.dll" _
    ALIAS "SetupQuerySourceListW" ( _
    BYVAL Flags AS DWORD, _
    List AS ANY, _    ' PCWSTR **
    COUNT AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupQuerySourceList LIB "SetupApi.dll" _
    ALIAS "SetupQuerySourceListW" ( _
    BYVAL Flags AS DWORD, _
    List AS ANY, _    ' PCWSTR **
    COUNT AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupQuerySourceList LIB "SetupApi.dll" _
    ALIAS "SetupQuerySourceListA" ( _
    BYVAL Flags AS DWORD, _
    List AS ANY, _    ' PCSTR **
    COUNT AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupFreeSourceListA LIB "SetupApi.dll" _
    ALIAS "SetupFreeSourceListA" ( _
    List AS ANY, _     ' PCSTR **
    BYVAL COUNT AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupFreeSourceListW LIB "SetupApi.dll" _
    ALIAS "SetupFreeSourceListW" ( _
    List AS ANY, _    ' PCWSTR **
    BYVAL COUNT AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupFreeSourceList LIB "SetupApi.dll" _
    ALIAS "SetupFreeSourceListW" ( _
    List AS ANY, _    ' PCWSTR **
    BYVAL COUNT AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupFreeSourceList LIB "SetupApi.dll" _
    ALIAS "SetupFreeSourceListA" ( _
    List AS ANY, _     ' PCSTR **
    BYVAL COUNT AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupPromptForDiskA LIB "SetupApi.dll" _
    ALIAS "SetupPromptForDiskA" ( _
    BYVAL hwndParent AS DWORD, _   ' HWND
    DialogTitle AS ASCIIZ, _
    DiskName AS ASCIIZ, _
    PathToSource AS ASCIIZ, _
    FileSought AS ASCIIZ, _
    TagFile AS ASCIIZ, _
    BYVAL DiskPromptStyle AS DWORD, _
    PathBuffer AS ASCIIZ, _
    BYVAL PathBufferSize AS DWORD, _
    PathRequiredSize AS DWORD _
    ) AS DWORD

DECLARE FUNCTION SetupPromptForDiskW LIB "SetupApi.dll" _
    ALIAS "SetupPromptForDiskW" ( _
    BYVAL hwndParent AS DWORD, _   ' HWND
    DialogTitle AS WSTRINGZ, _
    DiskName AS WSTRINGZ, _
    PathToSource AS WSTRINGZ, _
    FileSought AS WSTRINGZ, _
    TagFile AS WSTRINGZ, _
    BYVAL DiskPromptStyle AS DWORD, _
    PathBuffer AS WSTRINGZ, _
    BYVAL PathBufferSize AS DWORD, _
    PathRequiredSize AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupPromptForDisk LIB "SetupApi.dll" _
    ALIAS "SetupPromptForDiskW" ( _
    BYVAL hwndParent AS DWORD, _   ' HWND
    DialogTitle AS WSTRINGZ, _
    DiskName AS WSTRINGZ, _
    PathToSource AS WSTRINGZ, _
    FileSought AS WSTRINGZ, _
    TagFile AS WSTRINGZ, _
    BYVAL DiskPromptStyle AS DWORD, _
    PathBuffer AS WSTRINGZ, _
    BYVAL PathBufferSize AS DWORD, _
    PathRequiredSize AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetupPromptForDisk LIB "SetupApi.dll" _
    ALIAS "SetupPromptForDiskA" ( _
    BYVAL hwndParent AS DWORD, _   ' HWND
    DialogTitle AS ASCIIZ, _
    DiskName AS ASCIIZ, _
    PathToSource AS ASCIIZ, _
    FileSought AS ASCIIZ, _
    TagFile AS ASCIIZ, _
    BYVAL DiskPromptStyle AS DWORD, _
    PathBuffer AS ASCIIZ, _
    BYVAL PathBufferSize AS DWORD, _
    PathRequiredSize AS DWORD _
    ) AS DWORD
#ENDIF


DECLARE FUNCTION SetupCopyErrorA LIB "SetupApi.dll" _
    ALIAS "SetupCopyErrorA" ( _
    BYVAL hwndParent AS DWORD, _   ' HWND
    DialogTitle AS ASCIIZ, _
    DiskName AS ASCIIZ, _
    PathToSource AS ASCIIZ, _
    SourceFile AS ASCIIZ, _
    TargetPathFile AS ASCIIZ, _
    BYVAL Win32ErrorCode AS DWORD, _
    BYVAL STYLE AS DWORD, _
    PathBuffer AS ASCIIZ, _
    BYVAL PathBufferSize AS DWORD, _
    PathRequiredSize AS DWORD _
    ) AS DWORD

DECLARE FUNCTION SetupCopyErrorW LIB "SetupApi.dll" _
    ALIAS "SetupCopyErrorW" ( _
    BYVAL hwndParent AS DWORD, _   ' HWND
    DialogTitle AS WSTRINGZ, _
    DiskName AS WSTRINGZ, _
    PathToSource AS WSTRINGZ, _
    SourceFile AS WSTRINGZ, _
    TargetPathFile AS WSTRINGZ, _
    BYVAL Win32ErrorCode AS DWORD, _
    BYVAL STYLE AS DWORD, _
    PathBuffer AS WSTRINGZ, _
    BYVAL PathBufferSize AS DWORD, _
    PathRequiredSize AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupCopyError LIB "SetupApi.dll" _
    ALIAS "SetupCopyErrorW" ( _
    BYVAL hwndParent AS DWORD, _   ' HWND
    DialogTitle AS WSTRINGZ, _
    DiskName AS WSTRINGZ, _
    PathToSource AS WSTRINGZ, _
    SourceFile AS WSTRINGZ, _
    TargetPathFile AS WSTRINGZ, _
    BYVAL Win32ErrorCode AS DWORD, _
    BYVAL STYLE AS DWORD, _
    PathBuffer AS WSTRINGZ, _
    BYVAL PathBufferSize AS DWORD, _
    PathRequiredSize AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetupCopyError LIB "SetupApi.dll" _
    ALIAS "SetupCopyErrorA" ( _
    BYVAL hwndParent AS DWORD, _   ' HWND
    DialogTitle AS ASCIIZ, _
    DiskName AS ASCIIZ, _
    PathToSource AS ASCIIZ, _
    SourceFile AS ASCIIZ, _
    TargetPathFile AS ASCIIZ, _
    BYVAL Win32ErrorCode AS DWORD, _
    BYVAL STYLE AS DWORD, _
    PathBuffer AS ASCIIZ, _
    BYVAL PathBufferSize AS DWORD, _
    PathRequiredSize AS DWORD _
    ) AS DWORD
#ENDIF


DECLARE FUNCTION SetupRenameErrorA LIB "SetupApi.dll" _
    ALIAS "SetupRenameErrorA" ( _
    BYVAL hwndParent AS DWORD, _   ' HWND
    DialogTitle AS ASCIIZ, _
    SourceFile AS ASCIIZ, _
    TargetFile AS ASCIIZ, _
    BYVAL Win32ErrorCode AS DWORD, _
    BYVAL STYLE AS DWORD _
    ) AS DWORD

DECLARE FUNCTION SetupRenameErrorW LIB "SetupApi.dll" _
    ALIAS "SetupRenameErrorW" ( _
    BYVAL hwndParent AS DWORD, _    ' HWND
    DialogTitle AS WSTRINGZ, _
    SourceFile AS WSTRINGZ, _
    TargetFile AS WSTRINGZ, _
    BYVAL Win32ErrorCode AS DWORD, _
    BYVAL STYLE AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupRenameError LIB "SetupApi.dll" _
    ALIAS "SetupRenameErrorW" ( _
    BYVAL hwndParent AS DWORD, _    ' HWND
    DialogTitle AS WSTRINGZ, _
    SourceFile AS WSTRINGZ, _
    TargetFile AS WSTRINGZ, _
    BYVAL Win32ErrorCode AS DWORD, _
    BYVAL STYLE AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetupRenameError LIB "SetupApi.dll" _
    ALIAS "SetupRenameErrorA" ( _
    BYVAL hwndParent AS DWORD, _   ' HWND
    DialogTitle AS ASCIIZ, _
    SourceFile AS ASCIIZ, _
    TargetFile AS ASCIIZ, _
    BYVAL Win32ErrorCode AS DWORD, _
    BYVAL STYLE AS DWORD _
    ) AS DWORD
#ENDIF


DECLARE FUNCTION SetupDeleteErrorA LIB "SetupApi.dll" _
    ALIAS "SetupDeleteErrorA" ( _
    BYVAL hwndParent AS DWORD, _   ' HWND
    DialogTitle AS ASCIIZ, _
    File AS ASCIIZ, _
    BYVAL Win32ErrorCode AS DWORD, _
    BYVAL STYLE AS DWORD _
    ) AS DWORD

DECLARE FUNCTION SetupDeleteErrorW LIB "SetupApi.dll" _
    ALIAS "SetupDeleteErrorW" ( _
    BYVAL hwndParent AS DWORD, _   ' HWND
    DialogTitle AS WSTRINGZ, _
    File AS WSTRINGZ, _
    BYVAL Win32ErrorCode AS DWORD, _
    BYVAL STYLE AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDeleteError LIB "SetupApi.dll" _
    ALIAS "SetupDeleteErrorW" ( _
    BYVAL hwndParent AS DWORD, _   ' HWND
    DialogTitle AS WSTRINGZ, _
    File AS WSTRINGZ, _
    BYVAL Win32ErrorCode AS DWORD, _
    BYVAL STYLE AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetupDeleteError LIB "SetupApi.dll" _
    ALIAS "SetupDeleteErrorA" ( _
    BYVAL hwndParent AS DWORD, _   ' HWND
    DialogTitle AS ASCIIZ, _
    File AS ASCIIZ, _
    BYVAL Win32ErrorCode AS DWORD, _
    BYVAL STYLE AS DWORD _
    ) AS DWORD
#ENDIF

DECLARE FUNCTION SetupBackupErrorA LIB "SetupApi.dll" _
    ALIAS "SetupBackupErrorA" ( _
    BYVAL hwndParent AS DWORD, _   ' HWND
    DialogTitle AS ASCIIZ, _
    SourceFile AS ASCIIZ, _
    TargetFile AS ASCIIZ, _
    BYVAL Win32ErrorCode AS DWORD, _
    BYVAL STYLE AS DWORD _
    ) AS DWORD

DECLARE FUNCTION SetupBackupErrorW LIB "SetupApi.dll" _
    ALIAS "SetupBackupErrorW" ( _
    BYVAL hwndParent AS DWORD, _   ' HWND
    DialogTitle AS WSTRINGZ, _
    SourceFile AS WSTRINGZ, _
    TargetFile AS WSTRINGZ, _
    BYVAL Win32ErrorCode AS DWORD, _
    BYVAL STYLE AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupBackupError LIB "SetupApi.dll" _
    ALIAS "SetupBackupErrorW" ( _
    BYVAL hwndParent AS DWORD, _   ' HWND
    DialogTitle AS WSTRINGZ, _
    SourceFile AS WSTRINGZ, _
    TargetFile AS WSTRINGZ, _
    BYVAL Win32ErrorCode AS DWORD, _
    BYVAL STYLE AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetupBackupError LIB "SetupApi.dll" _
    ALIAS "SetupBackupErrorA" ( _
    BYVAL hwndParent AS DWORD, _   ' HWND
    DialogTitle AS ASCIIZ, _
    SourceFile AS ASCIIZ, _
    TargetFile AS ASCIIZ, _
    BYVAL Win32ErrorCode AS DWORD, _
    BYVAL STYLE AS DWORD _
    ) AS DWORD
#ENDIF


'
' Styles for SetupPromptForDisk, SetupCopyError,
' SetupRenameError, SetupDeleteError
'
%IDF_NOBROWSE                  = &H00000001
%IDF_NOSKIP                    = &H00000002
%IDF_NODETAILS                 = &H00000004
%IDF_NOCOMPRESSED              = &H00000008
%IDF_CHECKFIRST                = &H00000100
%IDF_NOBEEP                    = &H00000200
%IDF_NOFOREGROUND              = &H00000400
%IDF_WARNIFSKIP                = &H00000800

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

%IDF_NOREMOVABLEMEDIAPROMPT    = &H00001000
%IDF_USEDISKNAMEASPROMPT       = &H00002000
%IDF_OEMDISK                   = &H80000000???

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

'
' Return values for SetupPromptForDisk, SetupCopyError,
' SetupRenameError, SetupDeleteError, SetupBackupError
'
%DPROMPT_SUCCESS        = 0
%DPROMPT_CANCEL         = 1
%DPROMPT_SKIPFILE       = 2
%DPROMPT_BUFFERTOOSMALL = 3
%DPROMPT_OUTOFMEMORY    = 4


DECLARE FUNCTION SetupSetDirectoryIdA LIB "SetupApi.dll" _
    ALIAS "SetupSetDirectoryIdA" ( _
    BYVAL InfHandle AS HINF, _
    BYVAL ID AS DWORD, _
    Directory AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupSetDirectoryIdW LIB "SetupApi.dll" _
    ALIAS "SetupSetDirectoryIdW" ( _
    BYVAL InfHandle AS HINF, _
    BYVAL ID AS DWORD, _
    Directory AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupSetDirectoryId LIB "SetupApi.dll" _
    ALIAS "SetupSetDirectoryIdW" ( _
    BYVAL InfHandle AS HINF, _
    BYVAL ID AS DWORD, _
    Directory AS WSTRINGZ _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupSetDirectoryId LIB "SetupApi.dll" _
    ALIAS "SetupSetDirectoryIdA" ( _
    BYVAL InfHandle AS HINF, _
    BYVAL ID AS DWORD, _
    Directory AS ASCIIZ _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupSetDirectoryIdExA LIB "SetupApi.dll" _
    ALIAS "SetupSetDirectoryIdExA" ( _
    BYVAL InfHandle AS HINF, _
    BYVAL ID AS DWORD, _
    Directory AS ASCIIZ, _
    BYVAL Flags AS DWORD, _
    BYVAL Reserved1 AS DWORD, _
    BYVAL Reserved2 AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupSetDirectoryIdExW LIB "SetupApi.dll" _
    ALIAS "SetupSetDirectoryIdExW" ( _
    BYVAL InfHandle AS HINF, _
    BYVAL ID AS DWORD, _
    Directory AS WSTRINGZ, _
    BYVAL Flags AS DWORD, _
    BYVAL Reserved1 AS DWORD, _
    BYVAL Reserved2 AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupSetDirectoryIdEx LIB "SetupApi.dll" _
    ALIAS "SetupSetDirectoryIdExW" ( _
    BYVAL InfHandle AS HINF, _
    BYVAL ID AS DWORD, _
    Directory AS WSTRINGZ, _
    BYVAL Flags AS DWORD, _
    BYVAL Reserved1 AS DWORD, _
    BYVAL Reserved2 AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupSetDirectoryIdEx LIB "SetupApi.dll" _
    ALIAS "SetupSetDirectoryIdExA" ( _
    BYVAL InfHandle AS HINF, _
    BYVAL ID AS DWORD, _
    Directory AS ASCIIZ, _
    BYVAL Flags AS DWORD, _
    BYVAL Reserved1 AS DWORD, _
    BYVAL Reserved2 AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ENDIF

'
' Flags for SetupSetDirectoryIdEx
'
%SETDIRID_NOT_FULL_PATH    = &H00000001


DECLARE FUNCTION SetupGetSourceInfoA LIB "SetupApi.dll" _
    ALIAS "SetupGetSourceInfoA" ( _
    BYVAL InfHandle AS HINF, _
    BYVAL SourceId AS DWORD, _
    BYVAL InfoDesired AS DWORD, _
    ReturnBuffer AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupGetSourceInfoW LIB "SetupApi.dll" _
    ALIAS "SetupGetSourceInfoW" ( _
    BYVAL InfHandle AS HINF, _
    BYVAL SourceId AS DWORD, _
    BYVAL InfoDesired AS DWORD, _
    ReturnBuffer AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupGetSourceInfo LIB "SetupApi.dll" _
    ALIAS "SetupGetSourceInfoW" ( _
    BYVAL InfHandle AS HINF, _
    BYVAL SourceId AS DWORD, _
    BYVAL InfoDesired AS DWORD, _
    ReturnBuffer AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupGetSourceInfo LIB "SetupApi.dll" _
    ALIAS "SetupGetSourceInfoA" ( _
    BYVAL InfHandle AS HINF, _
    BYVAL SourceId AS DWORD, _
    BYVAL InfoDesired AS DWORD, _
    ReturnBuffer AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

'
' InfoDesired values for SetupGetSourceInfo
'

%SRCINFO_PATH          = 1
%SRCINFO_TAGFILE       = 2
%SRCINFO_DESCRIPTION   = 3
%SRCINFO_FLAGS         = 4

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP
'
' SRC_FLAGS allow special treatment of source
' lower 4 bits are reserved for OS use
' the flags may determine what other parameters exist
'
%SRCINFO_TAGFILE2      = 5  ' alternate tagfile, when SRCINFO_TAGFILE is a cabfile

%SRC_FLAGS_CABFILE     = (&H0010) ' if set, treat SRCINFO_TAGFILE as a cabfile and specify alternate tagfile

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

DECLARE FUNCTION SetupInstallFileA LIB "SetupApi.dll" _
    ALIAS "SetupInstallFileA" ( _
    BYVAL InfHandle AS HINF, _
    InfContext AS INFCONTEXT, _
    SourceFile AS ASCIIZ, _
    SourcePathRoot AS ASCIIZ, _
    DestinationName AS ASCIIZ, _
    BYVAL CopyStyle AS DWORD, _
    BYVAL CopyMsgHandler AS DWORD, _  ' PSP_FILE_CALLBACK_A
    Context AS ANY _
    ) AS LONG  ' BOOOL

DECLARE FUNCTION SetupInstallFileW LIB "SetupApi.dll" _
    ALIAS "SetupInstallFileW" ( _
    BYVAL InfHandle AS HINF, _
    InfContext AS INFCONTEXT, _
    SourceFile AS WSTRINGZ, _
    SourcePathRoot AS WSTRINGZ, _
    DestinationName AS WSTRINGZ, _
    BYVAL CopyStyle AS DWORD, _
    BYVAL CopyMsgHandler AS DWORD, _  ' PSP_FILE_CALLBACK_W
    Context AS ANY _
    ) AS LONG   ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupInstallFile LIB "SetupApi.dll" _
    ALIAS "SetupInstallFileW" ( _
    BYVAL InfHandle AS HINF, _
    InfContext AS INFCONTEXT, _
    SourceFile AS WSTRINGZ, _
    SourcePathRoot AS WSTRINGZ, _
    DestinationName AS WSTRINGZ, _
    BYVAL CopyStyle AS DWORD, _
    BYVAL CopyMsgHandler AS DWORD, _  ' PSP_FILE_CALLBACK_W
    Context AS ANY _
    ) AS LONG   ' BOOL
#ELSE
DECLARE FUNCTION SetupInstallFile LIB "SetupApi.dll" _
    ALIAS "SetupInstallFileA" ( _
    BYVAL InfHandle AS HINF, _
    InfContext AS INFCONTEXT, _
    SourceFile AS ASCIIZ, _
    SourcePathRoot AS ASCIIZ, _
    DestinationName AS ASCIIZ, _
    BYVAL CopyStyle AS DWORD, _
    BYVAL CopyMsgHandler AS DWORD, _  ' PSP_FILE_CALLBACK_A
    Context AS ANY _
    ) AS LONG  ' BOOOL
#ENDIF

DECLARE FUNCTION SetupInstallFileExA LIB "SetupApi.dll" _
    ALIAS "SetupInstallFileExA" ( _
    BYVAL InfHandle AS HINF, _
    InfContext AS INFCONTEXT, _
    SourceFile AS ASCIIZ, _
    SourcePathRoot AS ASCIIZ, _
    DestinationName AS ASCIIZ, _
    BYVAL CopyStyle AS DWORD, _
    BYVAL CopyMsgHandler AS DWORD, _  ' PSP_FILE_CALLBACK_A
    Context AS ANY, _
    FileWasInUse AS LONG _  ' PBOOL
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupInstallFileExW LIB "SetupApi.dll" _
    ALIAS "SetupInstallFileExW" ( _
    BYVAL InfHandle AS HINF, _
    InfContext AS INFCONTEXT, _
    SourceFile AS WSTRINGZ, _
    SourcePathRoot AS WSTRINGZ, _
    DestinationName AS WSTRINGZ, _
    BYVAL CopyStyle AS DWORD, _
    BYVAL CopyMsgHandler AS DWORD, _   ' PSP_FILE_CALLBACK_W
    Context AS ANY, _
    FileWasInUse AS LONG _  ' PBOOL
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupInstallFileEx LIB "SetupApi.dll" _
    ALIAS "SetupInstallFileExW" ( _
    BYVAL InfHandle AS HINF, _
    InfContext AS INFCONTEXT, _
    SourceFile AS WSTRINGZ, _
    SourcePathRoot AS WSTRINGZ, _
    DestinationName AS WSTRINGZ, _
    BYVAL CopyStyle AS DWORD, _
    BYVAL CopyMsgHandler AS DWORD, _   ' PSP_FILE_CALLBACK_W
    Context AS ANY, _
    FileWasInUse AS LONG _  ' PBOOL
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupInstallFileEx LIB "SetupApi.dll" _
    ALIAS "SetupInstallFileExA" ( _
    BYVAL InfHandle AS HINF, _
    InfContext AS INFCONTEXT, _
    SourceFile AS ASCIIZ, _
    SourcePathRoot AS ASCIIZ, _
    DestinationName AS ASCIIZ, _
    BYVAL CopyStyle AS DWORD, _
    BYVAL CopyMsgHandler AS DWORD, _  ' PSP_FILE_CALLBACK_A
    Context AS ANY, _
    FileWasInUse AS LONG _  ' PBOOL
    ) AS LONG  ' BOOL
#ENDIF

'
' CopyStyle values for copy and queue-related APIs
'
%SP_COPY_DELETESOURCE        = &H0000001   ' delete source file on successful copy
%SP_COPY_REPLACEONLY         = &H0000002   ' copy only if target file already present
%SP_COPY_NEWER               = &H0000004   ' copy only if source newer than or same as target
%SP_COPY_NEWER_OR_SAME       = %SP_COPY_NEWER
%SP_COPY_NOOVERWRITE         = &H0000008   ' copy only if target doesn't exist
%SP_COPY_NODECOMP            = &H0000010   ' don't decompress source file while copying
%SP_COPY_LANGUAGEAWARE       = &H0000020   ' don't overwrite file of different language
%SP_COPY_SOURCE_ABSOLUTE     = &H0000040   ' SourceFile is a full source path
%SP_COPY_SOURCEPATH_ABSOLUTE = &H0000080   ' SourcePathRoot is the full path
%SP_COPY_IN_USE_NEEDS_REBOOT = &H0000100   ' System needs reboot if file in use
%SP_COPY_FORCE_IN_USE        = &H0000200   ' Force target-in-use behavior
%SP_COPY_NOSKIP              = &H0000400   ' Skip is disallowed for this file or section
%SP_FLAG_CABINETCONTINUATION = &H0000800   ' Used with need media notification
%SP_COPY_FORCE_NOOVERWRITE   = &H0001000   ' like NOOVERWRITE but no callback nofitication
%SP_COPY_FORCE_NEWER         = &H0002000   ' like NEWER but no callback nofitication
%SP_COPY_WARNIFSKIP          = &H0004000   ' system critical file: warn if user tries to skip
%SP_COPY_NOBROWSE            = &H0008000   ' Browsing is disallowed for this file or section
%SP_COPY_NEWER_ONLY          = &H0010000   ' copy only if source file newer than target
%SP_COPY_RESERVED            = &H0020000   ' was: SP_COPY_SOURCE_SIS_MASTER (deprecated)
%SP_COPY_OEMINF_CATALOG_ONLY = &H0040000   ' (SetupCopyOEMInf only) don't copy INF--just catalog
%SP_COPY_REPLACE_BOOT_FILE   = &H0080000   ' file must be present upon reboot (i.e., it's
                                           ' needed by the loader); this flag implies a reboot
%SP_COPY_NOPRUNE             = &H0100000   ' never prune this file

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

%SP_COPY_OEM_F6_INF          = &H0200000   ' Used when calling SetupCopyOemInf

#ENDIF '%SETUPAPI_VER >= %WIN32_WINNT_WINXP

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

%SP_COPY_ALREADYDECOMP       = &H0400000   ' similar to SP_COPY_NODECOMP

#ENDIF '%SETUPAPI_VER >= %WIN32_WINNT_WINXP

#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

%SP_COPY_WINDOWS_SIGNED      = &H1000000    ' BuildLab or WinSE signed
%SP_COPY_PNPLOCKED           = &H2000000    ' Used with the signature flag
%SP_COPY_IN_USE_TRY_RENAME   = &H4000000    ' If file in use, try to rename the target first
%SP_COPY_INBOX_INF           = &H8000000??? ' Referred by CopyFiles of inbox inf

#ENDIF '%SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

#IF %SETUPAPI_VER >= %WIN32_WINNT_WIN7

%SP_COPY_HARDLINK            = &H10000000  ' Copy using hardlink, if possible

#ENDIF

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

'
' Flags passed to Backup notification
'
%SP_BACKUP_BACKUPPASS        = &H00000001  ' file backed up during backup pass
%SP_BACKUP_DEMANDPASS        = &H00000002  ' file backed up on demand
%SP_BACKUP_SPECIAL           = &H00000004  ' if set, special type of backup
%SP_BACKUP_BOOTFILE          = &H00000008  ' file marked with COPYFLG_REPLACE_BOOT_FILE


#ENDIF '%SETUPAPI_VER >= %WIN32_WINNT_WINXP


DECLARE FUNCTION SetupOpenFileQueue LIB "SetupApi.dll" _
    ALIAS "SetupOpenFileQueue" () AS HSPFILEQ

DECLARE FUNCTION SetupCloseFileQueue LIB "SetupApi.dll" _
    ALIAS "SetupCloseFileQueue" ( _
    BYVAL QueueHandle AS HSPFILEQ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupSetFileQueueAlternatePlatformA LIB "SetupApi.dll" _
    ALIAS "SetupSetFileQueueAlternatePlatformA" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    AlternatePlatformInfo AS SP_ALTPLATFORM_INFO, _
    AlternateDefaultCatalogFile AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupSetFileQueueAlternatePlatformW LIB "SetupApi.dll" _
    ALIAS "SetupSetFileQueueAlternatePlatformW" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    AlternatePlatformInfo AS SP_ALTPLATFORM_INFO, _
    AlternateDefaultCatalogFile AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupSetFileQueueAlternatePlatform LIB "SetupApi.dll" _
    ALIAS "SetupSetFileQueueAlternatePlatformW" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    AlternatePlatformInfo AS SP_ALTPLATFORM_INFO, _
    AlternateDefaultCatalogFile AS WSTRINGZ _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupSetFileQueueAlternatePlatform LIB "SetupApi.dll" _
    ALIAS "SetupSetFileQueueAlternatePlatformA" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    AlternatePlatformInfo AS SP_ALTPLATFORM_INFO, _
    AlternateDefaultCatalogFile AS ASCIIZ _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupSetPlatformPathOverrideA LIB "SetupApi.dll" _
    ALIAS "SetupSetPlatformPathOverrideA" ( _
    OVERRIDE AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupSetPlatformPathOverrideW LIB "SetupApi.dll" _
    ALIAS "SetupSetPlatformPathOverrideW" ( _
    OVERRIDE AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupSetPlatformPathOverride LIB "SetupApi.dll" _
    ALIAS "SetupSetPlatformPathOverrideW" ( _
    OVERRIDE AS WSTRINGZ _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupSetPlatformPathOverride LIB "SetupApi.dll" _
    ALIAS "SetupSetPlatformPathOverrideA" ( _
    OVERRIDE AS ASCIIZ _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupQueueCopyA LIB "SetupApi.dll" _
    ALIAS "SetupQueueCopyA" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    SourceRootPath AS ASCIIZ, _
    SourcePath AS ASCIIZ, _
    SourceFilename AS ASCIIZ, _
    SourceDescription AS ASCIIZ, _
    SourceTagfile AS ASCIIZ, _
    TargetDirectory AS ASCIIZ, _
    TargetFilename AS ASCIIZ, _
    BYVAL CopyStyle AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupQueueCopyW LIB "SetupApi.dll" _
    ALIAS "SetupQueueCopyW" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    SourceRootPath AS WSTRINGZ, _
    SourcePath AS WSTRINGZ, _
    SourceFilename AS WSTRINGZ, _
    SourceDescription AS WSTRINGZ, _
    SourceTagfile AS WSTRINGZ, _
    TargetDirectory AS WSTRINGZ, _
    TargetFilename AS WSTRINGZ, _
    BYVAL CopyStyle AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupQueueCopy LIB "SetupApi.dll" _
    ALIAS "SetupQueueCopyW" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    SourceRootPath AS WSTRINGZ, _
    SourcePath AS WSTRINGZ, _
    SourceFilename AS WSTRINGZ, _
    SourceDescription AS WSTRINGZ, _
    SourceTagfile AS WSTRINGZ, _
    TargetDirectory AS WSTRINGZ, _
    TargetFilename AS WSTRINGZ, _
    BYVAL CopyStyle AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupQueueCopy LIB "SetupApi.dll" _
    ALIAS "SetupQueueCopyA" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    SourceRootPath AS ASCIIZ, _
    SourcePath AS ASCIIZ, _
    SourceFilename AS ASCIIZ, _
    SourceDescription AS ASCIIZ, _
    SourceTagfile AS ASCIIZ, _
    TargetDirectory AS ASCIIZ, _
    TargetFilename AS ASCIIZ, _
    BYVAL CopyStyle AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupQueueCopyIndirectA LIB "SetupApi.dll" _
    ALIAS "SetupQueueCopyIndirectA" ( _
    BYVAL CopyParams AS SP_FILE_COPY_PARAMS_A PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupQueueCopyIndirectW LIB "SetupApi.dll" _
    ALIAS "SetupQueueCopyIndirectW" ( _
    BYVAL CopyParams AS SP_FILE_COPY_PARAMS_W PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupQueueCopyIndirect LIB "SetupApi.dll" _
    ALIAS "SetupQueueCopyIndirectW" ( _
    BYVAL CopyParams AS SP_FILE_COPY_PARAMS_W PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupQueueCopyIndirect LIB "SetupApi.dll" _
    ALIAS "SetupQueueCopyIndirectA" ( _
    BYVAL CopyParams AS SP_FILE_COPY_PARAMS_A PTR _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupQueueDefaultCopyA LIB "SetupApi.dll" _
    ALIAS "SetupQueueDefaultCopyA" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    BYVAL InfHandle AS HINF, _
    SourceRootPath AS ASCIIZ, _
    SourceFilename AS ASCIIZ, _
    TargetFilename AS ASCIIZ, _
    BYVAL CopyStyle AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupQueueDefaultCopyW LIB "SetupApi.dll" _
    ALIAS "SetupQueueDefaultCopyW" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    BYVAL InfHandle AS HINF, _
    SourceRootPath AS WSTRINGZ, _
    SourceFilename AS WSTRINGZ, _
    TargetFilename AS WSTRINGZ, _
    BYVAL CopyStyle AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupQueueDefaultCopy LIB "SetupApi.dll" _
    ALIAS "SetupQueueDefaultCopyW" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    BYVAL InfHandle AS HINF, _
    SourceRootPath AS WSTRINGZ, _
    SourceFilename AS WSTRINGZ, _
    TargetFilename AS WSTRINGZ, _
    BYVAL CopyStyle AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupQueueDefaultCopy LIB "SetupApi.dll" _
    ALIAS "SetupQueueDefaultCopyA" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    BYVAL InfHandle AS HINF, _
    SourceRootPath AS ASCIIZ, _
    SourceFilename AS ASCIIZ, _
    TargetFilename AS ASCIIZ, _
    BYVAL CopyStyle AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupQueueCopySectionA LIB "SetupApi.dll" _
    ALIAS "SetupQueueCopySectionA" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    SourceRootPath AS ASCIIZ, _
    BYVAL InfHandle AS HINF, _
    BYVAL ListInfHandle AS HINF, _
    Section AS ASCIIZ, _
    BYVAL CopyStyle AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupQueueCopySectionW LIB "SetupApi.dll" _
    ALIAS "SetupQueueCopySectionW" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    SourceRootPath AS WSTRINGZ, _
    BYVAL InfHandle AS HINF, _
    BYVAL ListInfHandle AS HINF, _
    Section AS WSTRINGZ, _
    BYVAL CopyStyle AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupQueueCopySection LIB "SetupApi.dll" _
    ALIAS "SetupQueueCopySectionW" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    SourceRootPath AS WSTRINGZ, _
    BYVAL InfHandle AS HINF, _
    BYVAL ListInfHandle AS HINF, _
    Section AS WSTRINGZ, _
    BYVAL CopyStyle AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupQueueCopySection LIB "SetupApi.dll" _
    ALIAS "SetupQueueCopySectionA" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    SourceRootPath AS ASCIIZ, _
    BYVAL InfHandle AS HINF, _
    BYVAL ListInfHandle AS HINF, _
    Section AS ASCIIZ, _
    BYVAL CopyStyle AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupQueueDeleteA LIB "SetupApi.dll" _
    ALIAS "SetupQueueDeleteA" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    PathPart1 AS ASCIIZ, _
    PathPart2 AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupQueueDeleteW LIB "SetupApi.dll" _
    ALIAS "SetupQueueDeleteW" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    PathPart1 AS WSTRINGZ, _
    PathPart2 AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupQueueDelete LIB "SetupApi.dll" _
    ALIAS "SetupQueueDeleteW" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    PathPart1 AS WSTRINGZ, _
    PathPart2 AS WSTRINGZ _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupQueueDelete LIB "SetupApi.dll" _
    ALIAS "SetupQueueDeleteA" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    PathPart1 AS ASCIIZ, _
    PathPart2 AS ASCIIZ _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupQueueDeleteSectionA LIB "SetupApi.dll" _
    ALIAS "SetupQueueDeleteSectionA" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    BYVAL InfHandle AS HINF, _
    BYVAL ListInfHandle AS HINF, _
    Section AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupQueueDeleteSectionW LIB "SetupApi.dll" _
    ALIAS "SetupQueueDeleteSectionW" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    BYVAL InfHandle AS HINF, _
    BYVAL ListInfHandle AS HINF, _
    Section AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupQueueDeleteSectionW LIB "SetupApi.dll" _
    ALIAS "SetupQueueDeleteSectionW" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    BYVAL InfHandle AS HINF, _
    BYVAL ListInfHandle AS HINF, _
    Section AS WSTRINGZ _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupQueueDeleteSection LIB "SetupApi.dll" _
    ALIAS "SetupQueueDeleteSectionA" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    BYVAL InfHandle AS HINF, _
    BYVAL ListInfHandle AS HINF, _
    Section AS ASCIIZ _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupQueueRenameA LIB "SetupApi.dll" _
    ALIAS "SetupQueueRenameA" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    SourcePath AS ASCIIZ, _
    SourceFilename AS ASCIIZ, _
    TargetPath AS ASCIIZ, _
    TargetFilename AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupQueueRenameW LIB "SetupApi.dll" _
    ALIAS "SetupQueueRenameW" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    SourcePath AS WSTRINGZ, _
    SourceFilename AS WSTRINGZ, _
    TargetPath AS WSTRINGZ, _
    TargetFilename AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupQueueRename LIB "SetupApi.dll" _
    ALIAS "SetupQueueRenameW" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    SourcePath AS WSTRINGZ, _
    SourceFilename AS WSTRINGZ, _
    TargetPath AS WSTRINGZ, _
    TargetFilename AS WSTRINGZ _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupQueueRename LIB "SetupApi.dll" _
    ALIAS "SetupQueueRenameA" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    SourcePath AS ASCIIZ, _
    SourceFilename AS ASCIIZ, _
    TargetPath AS ASCIIZ, _
    TargetFilename AS ASCIIZ _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupQueueRenameSectionA LIB "SetupApi.dll" _
    ALIAS "SetupQueueRenameSectionA" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    BYVAL InfHandle AS HINF, _
    BYVAL ListInfHandle AS HINF, _
    Section AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupQueueRenameSectionW LIB "SetupApi.dll" _
    ALIAS "SetupQueueRenameSectionW" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    BYVAL InfHandle AS HINF, _
    BYVAL ListInfHandle AS HINF, _
    Section AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupQueueRenameSection LIB "SetupApi.dll" _
    ALIAS "SetupQueueRenameSectionW" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    BYVAL InfHandle AS HINF, _
    BYVAL ListInfHandle AS HINF, _
    Section AS WSTRINGZ _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupQueueRenameSection LIB "SetupApi.dll" _
    ALIAS "SetupQueueRenameSectionA" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    BYVAL InfHandle AS HINF, _
    BYVAL ListInfHandle AS HINF, _
    Section AS ASCIIZ _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupCommitFileQueueA LIB "SetupApi.dll" _
    ALIAS "SetupCommitFileQueueA" ( _
    BYVAL Owner AS DWORD, _  ' HWND
    BYVAL QueueHandle AS HSPFILEQ, _
    BYVAL MsgHandler AS DWORD, _   ' PSP_FILE_CALLBACK_A
    Context AS ANY _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupCommitFileQueueW LIB "SetupApi.dll" _
    ALIAS "SetupCommitFileQueueW" ( _
    BYVAL Owner AS DWORD, _  ' HWND
    BYVAL QueueHandle AS HSPFILEQ, _
    BYVAL MsgHandler AS DWORD, _   ' PSP_FILE_CALLBACK_W
    Context AS ANY _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupCommitFileQueue LIB "SetupApi.dll" _
    ALIAS "SetupCommitFileQueueW" ( _
    BYVAL Owner AS DWORD, _  ' HWND
    BYVAL QueueHandle AS HSPFILEQ, _
    BYVAL MsgHandler AS DWORD, _   ' PSP_FILE_CALLBACK_W
    Context AS ANY _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupCommitFileQueue LIB "SetupApi.dll" _
    ALIAS "SetupCommitFileQueueA" ( _
    BYVAL Owner AS DWORD, _  ' HWND
    BYVAL QueueHandle AS HSPFILEQ, _
    BYVAL MsgHandler AS DWORD, _   ' PSP_FILE_CALLBACK_A
    Context AS ANY _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupScanFileQueueA LIB "SetupApi.dll" _
    ALIAS "SetupScanFileQueueA" ( _
    BYVAL FileQueue AS HSPFILEQ, _
    BYVAL Flags AS DWORD, _
    BYVAL WINDOW AS DWORD, _  ' HWND
    BYVAL CallbackRoutine AS DWORD, _  ' PSP_FILE_CALLBACK_A
    BYVAL CallbackContext AS DWORD, _  ' PVOID
    Result AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupScanFileQueueW LIB "SetupApi.dll" _
    ALIAS "SetupScanFileQueueW" ( _
    BYVAL FileQueue AS HSPFILEQ, _
    BYVAL Flags AS DWORD, _
    BYVAL WINDOW AS DWORD, _  ' HWND
    BYVAL CallbackRoutine AS DWORD, _  ' PSP_FILE_CALLBACK_W
    BYVAL CallbackContext AS DWORD, _  ' PVOID
    Result AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupScanFileQueue LIB "SetupApi.dll" _
    ALIAS "SetupScanFileQueueW" ( _
    BYVAL FileQueue AS HSPFILEQ, _
    BYVAL Flags AS DWORD, _
    BYVAL WINDOW AS DWORD, _  ' HWND
    BYVAL CallbackRoutine AS DWORD, _  ' PSP_FILE_CALLBACK_W
    BYVAL CallbackContext AS DWORD, _  ' PVOID
    Result AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupScanFileQueue LIB "SetupApi.dll" _
    ALIAS "SetupScanFileQueueA" ( _
    BYVAL FileQueue AS HSPFILEQ, _
    BYVAL Flags AS DWORD, _
    BYVAL WINDOW AS DWORD, _  ' HWND
    BYVAL CallbackRoutine AS DWORD, _  ' PSP_FILE_CALLBACK_A
    BYVAL CallbackContext AS DWORD, _  ' PVOID
    Result AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

'
' Define flags for SetupScanFileQueue.
'
%SPQ_SCAN_FILE_PRESENCE                = &H00000001
%SPQ_SCAN_FILE_VALIDITY                = &H00000002
%SPQ_SCAN_USE_CALLBACK                 = &H00000004
%SPQ_SCAN_USE_CALLBACKEX               = &H00000008
%SPQ_SCAN_INFORM_USER                  = &H00000010
%SPQ_SCAN_PRUNE_COPY_QUEUE             = &H00000020

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

%SPQ_SCAN_USE_CALLBACK_SIGNERINFO      = &H00000040
%SPQ_SCAN_PRUNE_DELREN                 = &H00000080 ' remote Delete/Rename queue

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP


#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

%SPQ_SCAN_FILE_PRESENCE_WITHOUT_SOURCE = &H00000100
%SPQ_SCAN_FILE_COMPARISON              = &H00000200
%SPQ_SCAN_ACTIVATE_DRP                 = &H00000400

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN


'
' Define flags used with Param2 for SPFILENOTIFY_QUEUESCAN
'
%SPQ_DELAYED_COPY                      = &H00000001  ' file was in use; registered for delayed copy

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

DECLARE FUNCTION SetupGetFileQueueCount LIB "SetupApi.dll" _
    ALIAS "SetupGetFileQueueCount" ( _
    BYVAL FileQueue AS HSPFILEQ, _
    BYVAL SubQueueFileOp AS DWORD, _
    NumOperations AS DWORD, _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupGetFileQueueFlags LIB "SetupApi.dll" _
    ALIAS "SetupGetFileQueueFlags" ( _
    BYVAL FileQueue AS HSPFILEQ, _
    Flags AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupSetFileQueueFlags LIB "SetupApi.dll" _
    ALIAS "SetupSetFileQueueFlags" ( _
    BYVAL FileQueue AS HSPFILEQ, _
    BYVAL FlagMask AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL

'
' Flags/FlagMask for use with SetupSetFileQueueFlags and returned by SetupGetFileQueueFlags
'
%SPQ_FLAG_BACKUP_AWARE      = &H00000001  ' If set, SetupCommitFileQueue will
                                          ' issue backup notifications.

%SPQ_FLAG_ABORT_IF_UNSIGNED = &H00000002  ' If set, SetupCommitFileQueue will
                                          ' fail with %ERROR_SET_SYSTEM_RESTORE_POINT
                                          ' if the user elects to proceed with an
                                          ' unsigned queue committal.  This allows
                                          ' the caller to set a system restore point,
                                          ' then re-commit the file queue.

%SPQ_FLAG_FILES_MODIFIED    = &H00000004  ' If set, at least one file was
                                          ' replaced by a different version

%SPQ_FLAG_DO_SHUFFLEMOVE    = &H00000008  ' If set then always do a shuffle move. A shuffle
                                          ' move will first try to copy the source over the
                                          ' destination file, but if the destination file is
                                          ' in use it will rename the destination file to a
                                          ' temp name and queue the temp name for deletion.
                                          ' It will then be free to copy the source to the
                                          ' destination name.  It is considered an error if
                                          ' the destination file can't be renamed for some
                                          ' reason.

%SPQ_FLAG_VALID             = &H0000000F  ' mask of valid flags (can be passed as FlagMask)

#ENDIF  ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

'
' Define OEM Source Type values for use in SetupCopyOEMInf.
'
%SPOST_NONE = 0
%SPOST_PATH = 1
%SPOST_URL  = 2
%SPOST_MAX  = 3

DECLARE FUNCTION SetupCopyOEMInfA LIB "SetupApi.dll" _
    ALIAS "SetupCopyOEMInfA" ( _
    SourceInfFileName AS ASCIIZ, _
    OEMSourceMediaLocation AS ASCIIZ, _
    BYVAL OEMSourceMediaType AS DWORD, _
    BYVAL CopyStyle AS DWORD, _
    DestinationInfFileName AS ASCIIZ, _
    BYVAL DestinationInfFileNameSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL DestinationInfFileNameComponent AS DWORD _  ' PSTR *
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupCopyOEMInfW LIB "SetupApi.dll" _
    ALIAS "SetupCopyOEMInfW" ( _
    SourceInfFileName AS WSTRINGZ, _
    OEMSourceMediaLocation AS WSTRINGZ, _
    BYVAL OEMSourceMediaType AS DWORD, _
    BYVAL CopyStyle AS DWORD, _
    DestinationInfFileName AS WSTRINGZ, _
    BYVAL DestinationInfFileNameSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL DestinationInfFileNameComponent AS DWORD _  ' PWSTR *
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupCopyOEMInf LIB "SetupApi.dll" _
    ALIAS "SetupCopyOEMInfW" ( _
    SourceInfFileName AS WSTRINGZ, _
    OEMSourceMediaLocation AS WSTRINGZ, _
    BYVAL OEMSourceMediaType AS DWORD, _
    BYVAL CopyStyle AS DWORD, _
    DestinationInfFileName AS WSTRINGZ, _
    BYVAL DestinationInfFileNameSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL DestinationInfFileNameComponent AS DWORD _  ' PWSTR *
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupCopyOEMInf LIB "SetupApi.dll" _
    ALIAS "SetupCopyOEMInfA" ( _
    SourceInfFileName AS ASCIIZ, _
    OEMSourceMediaLocation AS ASCIIZ, _
    BYVAL OEMSourceMediaType AS DWORD, _
    BYVAL CopyStyle AS DWORD, _
    DestinationInfFileName AS ASCIIZ, _
    BYVAL DestinationInfFileNameSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL DestinationInfFileNameComponent AS DWORD _  ' PSTR *
    ) AS LONG  ' BOOL
#ENDIF

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

'
' Flags used by SetupUninstallOEMInf
'
%SUOI_FORCEDELETE   = &H00000001

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

%SUOI_INTERNAL1    = &H00000002

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN


#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

DECLARE FUNCTION SetupUninstallOEMInfA LIB "SetupApi.dll" _
    ALIAS "SetupUninstallOEMInfA" ( _
    InfFileName AS ASCIIZ, _
    BYVAL Flags AS DWORD, _
    BYVAL Reserved AS DWORD,  ' PVOID
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupUninstallOEMInfW LIB "SetupApi.dll" _
    ALIAS "SetupUninstallOEMInfW" ( _
    InfFileName AS WSTRINGZ, _
    BYVAL Flags AS DWORD, _
    BYVAL Reserved AS DWORD,  ' PVOID
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupUninstallOEMInf LIB "SetupApi.dll" _
    ALIAS "SetupUninstallOEMInfW" ( _
    InfFileName AS WSTRINGZ, _
    BYVAL Flags AS DWORD, _
    BYVAL Reserved AS DWORD,  ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupUninstallOEMInf LIB "SetupApi.dll" _
    ALIAS "SetupUninstallOEMInfA" ( _
    InfFileName AS ASCIIZ, _
    BYVAL Flags AS DWORD, _
    BYVAL Reserved AS DWORD,  ' PVOID
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupUninstallNewlyCopiedInfs LIB "SetupApi.dll" _
    ALIAS "SetupUninstallNewlyCopiedInfs" ( _
    BYVAL FileQueue AS HSPFILEQ, _
    BYVAL Flags AS DWORD, _
    BYVAL Reserved AS DWORD, _   ' PVOID
    ) AS LONG  ' BOOL

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP


'
' Disk space list APIs
'
DECLARE FUNCTION SetupCreateDiskSpaceListA LIB "SetupApi.dll" _
    ALIAS "SetupCreateDiskSpaceListA" ( _
    BYVAL Reserved1 AS DWORD, _   ' PVOID
    BYVAL Reserved2 AS DWORD, _
    BYVAL Flags     AS DWORD _
    ) AS DWORD  ' HDSKSPC

DECLARE FUNCTION SetupCreateDiskSpaceListW LIB "SetupApi.dll" _
    ALIAS "SetupCreateDiskSpaceListW" ( _
    BYVAL Reserved1 AS DWORD, _   ' PVOID
    BYVAL Reserved2 AS DWORD, _
    BYVAL Flags     AS DWORD _
    ) AS DWORD  ' HDSKSPC

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupCreateDiskSpaceList LIB "SetupApi.dll" _
    ALIAS "SetupCreateDiskSpaceListW" ( _
    BYVAL Reserved1 AS DWORD, _   ' PVOID
    BYVAL Reserved2 AS DWORD, _
    BYVAL Flags     AS DWORD _
    ) AS DWORD  ' HDSKSPC
#ELSE
DECLARE FUNCTION SetupCreateDiskSpaceList LIB "SetupApi.dll" _
    ALIAS "SetupCreateDiskSpaceListA" ( _
    BYVAL Reserved1 AS DWORD, _   ' PVOID
    BYVAL Reserved2 AS DWORD, _
    BYVAL Flags     AS DWORD _
    ) AS DWORD  ' HDSKSPC
#ENDIF

'
' Flags for SetupCreateDiskSpaceList
'
%SPDSL_IGNORE_DISK              = &H00000001  ' ignore deletes and on-disk files in copies
%SPDSL_DISALLOW_NEGATIVE_ADJUST = &H00000002


DECLARE FUNCTION SetupDuplicateDiskSpaceListA LIB "SetupApi.dll" _
    ALIAS "SetupDuplicateDiskSpaceListA" ( _
    BYVAL DiskSpace AS DWORD, _  ' HDSKSPC
    BYVAL Reserved1 AS DWORD, _  ' PVOID
    BYVAL Reserved2 AS DWORD, _
    BYVAL Flags     AS DWORD _
    ) AS DWORD  ' HDSKSPC

DECLARE FUNCTION SetupDuplicateDiskSpaceListW LIB "SetupApi.dll" _
    ALIAS "SetupDuplicateDiskSpaceListW" ( _
    BYVAL DiskSpace AS DWORD, _  ' HDSKSPC
    BYVAL Reserved1 AS DWORD, _  ' PVOID
    BYVAL Reserved2 AS DWORD, _
    BYVAL Flags     AS DWORD _
    ) AS DWORD  ' HDSKSPC

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDuplicateDiskSpaceList LIB "SetupApi.dll" _
    ALIAS "SetupDuplicateDiskSpaceListW" ( _
    BYVAL DiskSpace AS DWORD, _  ' HDSKSPC
    BYVAL Reserved1 AS DWORD, _  ' PVOID
    BYVAL Reserved2 AS DWORD, _
    BYVAL Flags     AS DWORD _
    ) AS DWORD  ' HDSKSPC
#ELSE
DECLARE FUNCTION SetupDuplicateDiskSpaceList LIB "SetupApi.dll" _
    ALIAS "SetupDuplicateDiskSpaceListA" ( _
    BYVAL DiskSpace AS DWORD, _  ' HDSKSPC
    BYVAL Reserved1 AS DWORD, _  ' PVOID
    BYVAL Reserved2 AS DWORD, _
    BYVAL Flags     AS DWORD _
    ) AS DWORD  ' HDSKSPC
#ENDIF


DECLARE FUNCTION SetupDestroyDiskSpaceList LIB "SetupApi.dll" _
    ALIAS "SetupDestroyDiskSpaceList" ( _
    BYVAL DiskSpace AS DWORD _  ' HDSKSPC
    ) AS LONG  ' BOOL


DECLARE FUNCTION SetupQueryDrivesInDiskSpaceListA LIB "SetupApi.dll" _
    ALIAS "SetupQueryDrivesInDiskSpaceListA" ( _
    BYVAL DiskSpace        AS DWORD, _  ' HDSKSPC
    ReturnBuffer           AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize           AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupQueryDrivesInDiskSpaceListW LIB "SetupApi.dll" _
    ALIAS "SetupQueryDrivesInDiskSpaceListW" ( _
    BYVAL DiskSpace        AS DWORD, _  ' HDSKSPC
    ReturnBuffer           AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize           AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupQueryDrivesInDiskSpaceList LIB "SetupApi.dll" _
    ALIAS "SetupQueryDrivesInDiskSpaceListW" ( _
    BYVAL DiskSpace        AS DWORD, _  ' HDSKSPC
    ReturnBuffer           AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize           AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupQueryDrivesInDiskSpaceList LIB "SetupApi.dll" _
    ALIAS "SetupQueryDrivesInDiskSpaceListA" ( _
    BYVAL DiskSpace        AS DWORD, _  ' HDSKSPC
    ReturnBuffer           AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize           AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupQuerySpaceRequiredOnDriveA LIB "SetupApi.dll" _
    ALIAS "SetupQuerySpaceRequiredOnDriveA" ( _
    BYVAL DiskSpace AS DWORD, _   ' HDSKSPC
    DriveSpec       AS ASCIIZ, _
    SpaceRequired   AS QUAD, _    ' LONGLONG *
    BYVAL Reserved1 AS DWORD, _   ' PVOID
    BYVAL Reserved2 AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupQuerySpaceRequiredOnDriveW LIB "SetupApi.dll" _
    ALIAS "SetupQuerySpaceRequiredOnDriveW" ( _
    BYVAL DiskSpace AS DWORD, _   ' HDSKSPC
    DriveSpec       AS WSTRINGZ, _
    SpaceRequired   AS QUAD, _    ' LONGLONG *
    BYVAL Reserved1 AS DWORD, _   ' PVOID
    BYVAL Reserved2 AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupQuerySpaceRequiredOnDrive LIB "SetupApi.dll" _
    ALIAS "SetupQuerySpaceRequiredOnDriveW" ( _
    BYVAL DiskSpace AS DWORD, _   ' HDSKSPC
    DriveSpec       AS WSTRINGZ, _
    SpaceRequired   AS QUAD, _    ' LONGLONG *
    BYVAL Reserved1 AS DWORD, _   ' PVOID
    BYVAL Reserved2 AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupQuerySpaceRequiredOnDrive LIB "SetupApi.dll" _
    ALIAS "SetupQuerySpaceRequiredOnDriveA" ( _
    BYVAL DiskSpace AS DWORD, _   ' HDSKSPC
    DriveSpec       AS ASCIIZ, _
    SpaceRequired   AS QUAD, _    ' LONGLONG *
    BYVAL Reserved1 AS DWORD, _   ' PVOID
    BYVAL Reserved2 AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupAdjustDiskSpaceListA LIB "SetupApi.dll" _
    ALIAS "SetupAdjustDiskSpaceListA" ( _
    BYVAL DiskSpace AS DWORD, _  ' HDSKSPC
    DriveRoot       AS ASCIIZ, _
    BYVAL Amount    AS QUAD, _   ' LONGLONG
    BYVAL Reserved1 AS DWORD, _  ' PVOID
    BYVAL Reserved2 AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupAdjustDiskSpaceListW LIB "SetupApi.dll" _
    ALIAS "SetupAdjustDiskSpaceListW" ( _
    BYVAL DiskSpace AS DWORD, _  ' HDSKSPC
    DriveRoot       AS WSTRINGZ, _
    BYVAL Amount    AS QUAD, _   ' LONGLONG
    BYVAL Reserved1 AS DWORD, _  ' PVOID
    BYVAL Reserved2 AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupAdjustDiskSpaceList LIB "SetupApi.dll" _
    ALIAS "SetupAdjustDiskSpaceListW" ( _
    BYVAL DiskSpace AS DWORD, _  ' HDSKSPC
    DriveRoot       AS WSTRINGZ, _
    BYVAL Amount    AS QUAD, _   ' LONGLONG
    BYVAL Reserved1 AS DWORD, _  ' PVOID
    BYVAL Reserved2 AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupAdjustDiskSpaceList LIB "SetupApi.dll" _
    ALIAS "SetupAdjustDiskSpaceListA" ( _
    BYVAL DiskSpace AS DWORD, _  ' HDSKSPC
    DriveRoot       AS ASCIIZ, _
    BYVAL Amount    AS QUAD, _   ' LONGLONG
    BYVAL Reserved1 AS DWORD, _  ' PVOID
    BYVAL Reserved2 AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupAddToDiskSpaceListA LIB "SetupApi.dll" _
    ALIAS "SetupAddToDiskSpaceListA" ( _
    BYVAL DiskSpace AS DWORD, _ ' HDSKSPC
    TargetFilespec  AS ASCIIZ, _
    BYVAL FileSize  AS QUAD, _   ' LONGLONG
    BYVAL Operation AS DWORD, _
    BYVAL Reserved1 AS DWORD, _ ' PVOID
    BYVAL Reserved2 AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupAddToDiskSpaceListW LIB "SetupApi.dll" _
    ALIAS "SetupAddToDiskSpaceListW" ( _
    BYVAL DiskSpace AS DWORD, _ ' HDSKSPC
    TargetFilespec  AS WSTRINGZ, _
    BYVAL FileSize  AS QUAD, _   ' LONGLONG
    BYVAL Operation AS DWORD, _
    BYVAL Reserved1 AS DWORD, _ ' PVOID
    BYVAL Reserved2 AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupAddToDiskSpaceListW LIB "SetupApi.dll" _
    ALIAS "SetupAddToDiskSpaceListW" ( _
    BYVAL DiskSpace AS DWORD, _ ' HDSKSPC
    TargetFilespec  AS WSTRINGZ, _
    BYVAL FileSize  AS QUAD, _   ' LONGLONG
    BYVAL Operation AS DWORD, _
    BYVAL Reserved1 AS DWORD, _ ' PVOID
    BYVAL Reserved2 AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupAddToDiskSpaceList LIB "SetupApi.dll" _
    ALIAS "SetupAddToDiskSpaceListA" ( _
    BYVAL DiskSpace AS DWORD, _ ' HDSKSPC
    TargetFilespec  AS ASCIIZ, _
    BYVAL FileSize  AS QUAD, _   ' LONGLONG
    BYVAL Operation AS DWORD, _
    BYVAL Reserved1 AS DWORD, _ ' PVOID
    BYVAL Reserved2 AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupAddSectionToDiskSpaceListA LIB "SetupApi.dll" _
    ALIAS "SetupAddSectionToDiskSpaceListA" ( _
    BYVAL DiskSpace AS DWORD, _ ' HDSKSPC
    BYVAL InfHandle AS HINF, _
    BYVAL ListInfHandle AS HINF, _
    SectionName AS ASCIIZ, _
    BYVAL Operation AS DWORD, _
    BYVAL Reserved1 AS DWORD, _  ' PVOID
    BYVAL Reserved2 AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupAddSectionToDiskSpaceListW LIB "SetupApi.dll" _
    ALIAS "SetupAddSectionToDiskSpaceListW" ( _
    BYVAL DiskSpace AS DWORD, _ ' HDSKSPC
    BYVAL InfHandle AS HINF, _
    BYVAL ListInfHandle AS HINF, _
    SectionName AS WSTRINGZ, _
    BYVAL Operation AS DWORD, _
    BYVAL Reserved1 AS DWORD, _  ' PVOID
    BYVAL Reserved2 AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupAddSectionToDiskSpaceList LIB "SetupApi.dll" _
    ALIAS "SetupAddSectionToDiskSpaceListW" ( _
    BYVAL DiskSpace AS DWORD, _ ' HDSKSPC
    BYVAL InfHandle AS HINF, _
    BYVAL ListInfHandle AS HINF, _
    SectionName AS WSTRINGZ, _
    BYVAL Operation AS DWORD, _
    BYVAL Reserved1 AS DWORD, _  ' PVOID
    BYVAL Reserved2 AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupAddSectionToDiskSpaceList LIB "SetupApi.dll" _
    ALIAS "SetupAddSectionToDiskSpaceListA" ( _
    BYVAL DiskSpace AS DWORD, _ ' HDSKSPC
    BYVAL InfHandle AS HINF, _
    BYVAL ListInfHandle AS HINF, _
    SectionName AS ASCIIZ, _
    BYVAL Operation AS DWORD, _
    BYVAL Reserved1 AS DWORD, _  ' PVOID
    BYVAL Reserved2 AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupAddInstallSectionToDiskSpaceListA LIB "SetupApi.dll" _
    ALIAS "SetupAddInstallSectionToDiskSpaceListA" ( _
    BYVAL DiskSpace       AS DWORD, _ ' HDSKSPC
    BYVAL InfHandle       AS HINF, _
    BYVAL LayoutInfHandle AS HINF, _
    SectionName           AS ASCIIZ, _
    BYVAL Reserved1       AS DWORD, _  ' PVOID
    BYVAL Reserved2       AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupAddInstallSectionToDiskSpaceListW LIB "SetupApi.dll" _
    ALIAS "SetupAddInstallSectionToDiskSpaceListW" ( _
    BYVAL DiskSpace       AS DWORD, _ ' HDSKSPC
    BYVAL InfHandle       AS HINF, _
    BYVAL LayoutInfHandle AS HINF, _
    SectionName           AS WSTRINGZ, _
    BYVAL Reserved1       AS DWORD, _  ' PVOID
    BYVAL Reserved2       AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupAddInstallSectionToDiskSpaceList LIB "SetupApi.dll" _
    ALIAS "SetupAddInstallSectionToDiskSpaceListW" ( _
    BYVAL DiskSpace       AS DWORD, _ ' HDSKSPC
    BYVAL InfHandle       AS HINF, _
    BYVAL LayoutInfHandle AS HINF, _
    SectionName           AS WSTRINGZ, _
    BYVAL Reserved1       AS DWORD, _  ' PVOID
    BYVAL Reserved2       AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupAddInstallSectionToDiskSpaceList LIB "SetupApi.dll" _
    ALIAS "SetupAddInstallSectionToDiskSpaceListA" ( _
    BYVAL DiskSpace       AS DWORD, _ ' HDSKSPC
    BYVAL InfHandle       AS HINF, _
    BYVAL LayoutInfHandle AS HINF, _
    SectionName           AS ASCIIZ, _
    BYVAL Reserved1       AS DWORD, _  ' PVOID
    BYVAL Reserved2       AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupRemoveFromDiskSpaceListA LIB "SetupApi.dll" _
    ALIAS "SetupRemoveFromDiskSpaceListA" ( _
    BYVAL DiskSpace AS DWORD, _ ' HDSKSPC
    TargetFilespec  AS ASCIIZ, _
    BYVAL Operation AS DWORD, _
    BYVAL Reserved1 AS DWORD, _ ' PVOID
    BYVAL Reserved2 AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupRemoveFromDiskSpaceListW LIB "SetupApi.dll" _
    ALIAS "SetupRemoveFromDiskSpaceListW" ( _
    BYVAL DiskSpace AS DWORD, _ ' HDSKSPC
    TargetFilespec  AS WSTRINGZ, _
    BYVAL Operation AS DWORD, _
    BYVAL Reserved1 AS DWORD, _ ' PVOID
    BYVAL Reserved2 AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupRemoveFromDiskSpaceList LIB "SetupApi.dll" _
    ALIAS "SetupRemoveFromDiskSpaceListW" ( _
    BYVAL DiskSpace AS DWORD, _ ' HDSKSPC
    TargetFilespec  AS WSTRINGZ, _
    BYVAL Operation AS DWORD, _
    BYVAL Reserved1 AS DWORD, _ ' PVOID
    BYVAL Reserved2 AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupRemoveFromDiskSpaceList LIB "SetupApi.dll" _
    ALIAS "SetupRemoveFromDiskSpaceListA" ( _
    BYVAL DiskSpace AS DWORD, _ ' HDSKSPC
    TargetFilespec  AS ASCIIZ, _
    BYVAL Operation AS DWORD, _
    BYVAL Reserved1 AS DWORD, _ ' PVOID
    BYVAL Reserved2 AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupRemoveSectionFromDiskSpaceListA LIB "SetupApi.dll" _
    ALIAS "SetupRemoveSectionFromDiskSpaceListA" ( _
    BYVAL DiskSpace     AS DWORD, _ ' HDSKSPC
    BYVAL InfHandle     AS HINF, _
    BYVAL ListInfHandle AS HINF, _
    SectionName         AS ASCIIZ, _
    BYVAL Operation     AS DWORD, _
    BYVAL Reserved1     AS DWORD, _  ' PVOID
    BYVAL Reserved2     AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupRemoveSectionFromDiskSpaceListW LIB "SetupApi.dll" _
    ALIAS "SetupRemoveSectionFromDiskSpaceListW" ( _
    BYVAL DiskSpace     AS DWORD, _ ' HDSKSPC
    BYVAL InfHandle     AS HINF, _
    BYVAL ListInfHandle AS HINF, _
    SectionName         AS WSTRINGZ, _
    BYVAL Operation     AS DWORD, _
    BYVAL Reserved1     AS DWORD, _  ' PVOID
    BYVAL Reserved2     AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupRemoveSectionFromDiskSpaceList LIB "SetupApi.dll" _
    ALIAS "SetupRemoveSectionFromDiskSpaceListW" ( _
    BYVAL DiskSpace     AS DWORD, _ ' HDSKSPC
    BYVAL InfHandle     AS HINF, _
    BYVAL ListInfHandle AS HINF, _
    SectionName         AS WSTRINGZ, _
    BYVAL Operation     AS DWORD, _
    BYVAL Reserved1     AS DWORD, _  ' PVOID
    BYVAL Reserved2     AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupRemoveSectionFromDiskSpaceList LIB "SetupApi.dll" _
    ALIAS "SetupRemoveSectionFromDiskSpaceListA" ( _
    BYVAL DiskSpace     AS DWORD, _ ' HDSKSPC
    BYVAL InfHandle     AS HINF, _
    BYVAL ListInfHandle AS HINF, _
    SectionName         AS ASCIIZ, _
    BYVAL Operation     AS DWORD, _
    BYVAL Reserved1     AS DWORD, _  ' PVOID
    BYVAL Reserved2     AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupRemoveInstallSectionFromDiskSpaceListA LIB "SetupApi.dll" _
    ALIAS "SetupRemoveInstallSectionFromDiskSpaceListA" ( _
    BYVAL DiskSpace       AS DWORD, _ ' HDSKSPC
    BYVAL InfHandle       AS HINF, _
    BYVAL LayoutInfHandle AS HINF, _
    SectionName           AS ASCIIZ, _
    BYVAL Reserved1       AS DWORD, _  ' PVOID
    BYVAL Reserved2       AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupRemoveInstallSectionFromDiskSpaceListW LIB "SetupApi.dll" _
    ALIAS "SetupRemoveInstallSectionFromDiskSpaceListW" ( _
    BYVAL DiskSpace       AS DWORD, _ ' HDSKSPC
    BYVAL InfHandle       AS HINF, _
    BYVAL LayoutInfHandle AS HINF, _
    SectionName           AS WSTRINGZ, _
    BYVAL Reserved1       AS DWORD, _  ' PVOID
    BYVAL Reserved2       AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupRemoveInstallSectionFromDiskSpaceList LIB "SetupApi.dll" _
    ALIAS "SetupRemoveInstallSectionFromDiskSpaceListW" ( _
    BYVAL DiskSpace       AS DWORD, _ ' HDSKSPC
    BYVAL InfHandle       AS HINF, _
    BYVAL LayoutInfHandle AS HINF, _
    SectionName           AS WSTRINGZ, _
    BYVAL Reserved1       AS DWORD, _  ' PVOID
    BYVAL Reserved2       AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupRemoveInstallSectionFromDiskSpaceList LIB "SetupApi.dll" _
    ALIAS "SetupRemoveInstallSectionFromDiskSpaceListA" ( _
    BYVAL DiskSpace       AS DWORD, _ ' HDSKSPC
    BYVAL InfHandle       AS HINF, _
    BYVAL LayoutInfHandle AS HINF, _
    SectionName           AS ASCIIZ, _
    BYVAL Reserved1       AS DWORD, _  ' PVOID
    BYVAL Reserved2       AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


'
' Cabinet APIs
'

DECLARE FUNCTION SetupIterateCabinetA LIB "SetupApi.dll" _
    ALIAS "SetupIterateCabinetA" ( _
    CabinetFile      AS ASCIIZ, _
    BYVAL Reserved   AS DWORD, _
    BYVAL MsgHandler AS DWORD, _   ' PSP_FILE_CALLBACK_A
    Context          AS ANY _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupIterateCabinetW LIB "SetupApi.dll" _
    ALIAS "SetupIterateCabinetW" ( _
    CabinetFile      AS WSTRINGZ, _
    BYVAL Reserved   AS DWORD, _
    BYVAL MsgHandler AS DWORD, _   ' PSP_FILE_CALLBACK_W
    Context          AS ANY _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupIterateCabinet LIB "SetupApi.dll" _
    ALIAS "SetupIterateCabinetW" ( _
    CabinetFile      AS WSTRINGZ, _
    BYVAL Reserved   AS DWORD, _
    BYVAL MsgHandler AS DWORD, _   ' PSP_FILE_CALLBACK_W
    Context          AS ANY _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupIterateCabinet LIB "SetupApi.dll" _
    ALIAS "SetupIterateCabinetA" ( _
    CabinetFile      AS ASCIIZ, _
    BYVAL Reserved   AS DWORD, _
    BYVAL MsgHandler AS DWORD, _   ' PSP_FILE_CALLBACK_A
    Context          AS ANY _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupPromptReboot LIB "SetupApi.dll" _
    ALIAS "SetupPromptReboot" ( _
    BYVAL FileQueue AS HSPFILEQ, _
    BYVAL Owner     AS DWORD, _   ' HWND
    BYVAL ScanOnly  AS LONG _  ' BOOL
    ) AS LONG

'
' Define flags that are returned by SetupPromptReboot
'
%SPFILEQ_FILE_IN_USE        = &H00000001
%SPFILEQ_REBOOT_RECOMMENDED = &H00000002
%SPFILEQ_REBOOT_IN_PROGRESS = &H00000004


DECLARE FUNCTION SetupInitDefaultQueueCallback LIB "SetupApi.dll" _
    ALIAS "SetupInitDefaultQueueCallback" ( _
    BYVAL OwnerWindow AS DWORD _  ' HWND
    ) AS DWORD  ' PVOID

DECLARE FUNCTION SetupInitDefaultQueueCallbackEx LIB "SetupApi.dll" _
    ALIAS "SetupInitDefaultQueueCallbackEx" ( _
    BYVAL OwnerWindow             AS DWORD, _  ' HWND
    BYVAL AlternateProgressWindow AS DWORD, _  ' HWND
    BYVAL ProgressMessage         AS DWORD, _
    BYVAL Reserved1               AS DWORD, _
    BYVAL Reserved2               AS DWORD _   ' PVOID
    ) AS DWORD  ' PVOID

DECLARE SUB SetupTermDefaultQueueCallback LIB "SetupApi.dll" _
    ALIAS "SetupTermDefaultQueueCallback" (Context AS ANY)

DECLARE FUNCTION SetupDefaultQueueCallbackA LIB "SetupApi.dll" _
    ALIAS "SetupDefaultQueueCallbackA" ( _
    Context            AS ANY, _
    BYVAL Notification AS DWORD, _
    BYVAL Param1       AS DWORD, _  ' UINT_PTR, _
    BYVAL Param2       AS DWORD _   ' UINT_PTR, _
    ) AS DWORD

DECLARE FUNCTION SetupDefaultQueueCallbackW LIB "SetupApi.dll" _
    ALIAS "SetupDefaultQueueCallbackW" ( _
    Context            AS ANY, _
    BYVAL Notification AS DWORD, _
    BYVAL Param1       AS DWORD, _  ' UINT_PTR, _
    BYVAL Param2       AS DWORD _   ' UINT_PTR, _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDefaultQueueCallback LIB "SetupApi.dll" _
    ALIAS "SetupDefaultQueueCallbackW" ( _
    Context            AS ANY, _
    BYVAL Notification AS DWORD, _
    BYVAL Param1       AS DWORD, _  ' UINT_PTR, _
    BYVAL Param2       AS DWORD _   ' UINT_PTR, _
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetupDefaultQueueCallback LIB "SetupApi.dll" _
    ALIAS "SetupDefaultQueueCallbackA" ( _
    Context            AS ANY, _
    BYVAL Notification AS DWORD, _
    BYVAL Param1       AS DWORD, _  ' UINT_PTR, _
    BYVAL Param2       AS DWORD _   ' UINT_PTR, _
    ) AS DWORD
#ENDIF


'
' Flags for AddReg section lines in INF.  The corresponding value
' is <ValueType> in the AddReg line format given below:
'
' <RegRootString>,<SubKey>,<ValueName>,<ValueType>,<Value>...
'
' The low word contains basic flags concerning the general data type
' and AddReg action. The high word contains values that more specifically
' identify the data type of the registry value.  The high word is ignored
' by the 16-bit Windows 95 SETUPX APIs.
'
' If <ValueType> has FLG_ADDREG_DELREG_BIT set, it will be ignored by AddReg
' (not supported by SetupX).
'

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

%FLG_ADDREG_DELREG_BIT       = &H00008000 ' if set, interpret as DELREG, see below

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

%FLG_ADDREG_BINVALUETYPE     = &H00000001
%FLG_ADDREG_NOCLOBBER        = &H00000002
%FLG_ADDREG_DELVAL           = &H00000004
%FLG_ADDREG_APPEND           = &H00000008 ' Currently supported only
                                                   ' for REG_MULTI_SZ values.
%FLG_ADDREG_KEYONLY          = &H00000010 ' Just create the key, ignore value
%FLG_ADDREG_OVERWRITEONLY    = &H00000020 ' Set only if value already exists

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

%FLG_ADDREG_64BITKEY         = &H00001000 ' make this change in the 64 bit registry.
%FLG_ADDREG_KEYONLY_COMMON   = &H00002000 ' same as FLG_ADDREG_KEYONLY but also works for DELREG
%FLG_ADDREG_32BITKEY         = &H00004000 ' make this change in the 32 bit registry.

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

'
' The INF may supply any arbitrary data type ordinal in the highword except
' for the following: REG_NONE, REG_SZ, REG_EXPAND_SZ, REG_MULTI_SZ.  If this
' technique is used, then the data is given in binary format, one byte per
' field.
'
%FLG_ADDREG_TYPE_MASK        = &HFFFF0000??? OR %FLG_ADDREG_BINVALUETYPE
%FLG_ADDREG_TYPE_SZ          = &H00000000
%FLG_ADDREG_TYPE_MULTI_SZ    = &H00010000
%FLG_ADDREG_TYPE_EXPAND_SZ   = &H00020000
%FLG_ADDREG_TYPE_BINARY      = &H00000000 OR %FLG_ADDREG_BINVALUETYPE
%FLG_ADDREG_TYPE_DWORD       = &H00010000 OR %FLG_ADDREG_BINVALUETYPE
%FLG_ADDREG_TYPE_NONE        = &H00020000 OR %FLG_ADDREG_BINVALUETYPE

'
' Flags for DelReg section lines in INF.  The corresponding value
' is <Operation> in the extended DelReg line format given below:
'
' <RegRootString>,<SubKey>,<ValueName>,<Operation>[,...]
'
' In SetupX and some versions of SetupAPI, <Operation> will be ignored and <ValueName> will
' be deleted. Use with care.
'
' The bits determined by mask FLG_DELREG_TYPE_MASK indicates type of data expected.
' <Operation> must have FLG_ADDREG_DELREG_BIT set, otherwise it is ignored and specified
' value will be deleted (allowing an AddReg section to also be used as a DelReg section)
' if <Operation> is not specified, <ValueName> will be deleted (if specified) otherwise
' <SubKey> will be deleted.
'
' the compatability flag
'
%FLG_DELREG_VALUE          = &H00000000

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

%FLG_DELREG_TYPE_MASK      = %FLG_ADDREG_TYPE_MASK        ' &HFFFF0001
%FLG_DELREG_TYPE_SZ        = %FLG_ADDREG_TYPE_SZ          ' &H00000000
%FLG_DELREG_TYPE_MULTI_SZ  = %FLG_ADDREG_TYPE_MULTI_SZ    ' &H00010000
%FLG_DELREG_TYPE_EXPAND_SZ = %FLG_ADDREG_TYPE_EXPAND_SZ   ' &H00020000
%FLG_DELREG_TYPE_BINARY    = %FLG_ADDREG_TYPE_BINARY      ' &H00000001
%FLG_DELREG_TYPE_DWORD     = %FLG_ADDREG_TYPE_DWORD       ' &H00010001
%FLG_DELREG_TYPE_NONE      = %FLG_ADDREG_TYPE_NONE        ' &H00020001
%FLG_DELREG_64BITKEY       = %FLG_ADDREG_64BITKEY         ' &H00001000
%FLG_DELREG_KEYONLY_COMMON = %FLG_ADDREG_KEYONLY_COMMON   ' &H00002000
%FLG_DELREG_32BITKEY       = %FLG_ADDREG_32BITKEY         ' &H00004000

'
' <Operation> = FLG_DELREG_MULTI_SZ_DELSTRING
'               <RegRootString>,<SubKey>,<ValueName>,&H00018002,<String>
'               removes all entries matching <String> (case ignored) from multi-sz registry value
'

%FLG_DELREG_OPERATION_MASK     = &H000000FE
%FLG_DELREG_MULTI_SZ_DELSTRING = %FLG_DELREG_TYPE_MULTI_SZ OR %FLG_ADDREG_DELREG_BIT OR &H00000002 ' &H00018002

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

'
' Flags for BitReg section lines in INF.
'
%FLG_BITREG_CLEARBITS        = &H00000000
%FLG_BITREG_SETBITS          = &H00000001

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

%FLG_BITREG_64BITKEY         = &H00001000
%FLG_BITREG_32BITKEY         = &H00004000

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

'
' Flags for Ini2Reg section lines in INF.
'
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

%FLG_INI2REG_64BITKEY        = &H00001000
%FLG_INI2REG_32BITKEY        = &H00004000

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

'
' Flags for RegSvr section lines in INF
'
%FLG_REGSVR_DLLREGISTER      = &H00000001
%FLG_REGSVR_DLLINSTALL       = &H00000002

' Flags for RegSvr section lines in INF
'

%FLG_PROFITEM_CURRENTUSER    = &H00000001
%FLG_PROFITEM_DELETE         = &H00000002
%FLG_PROFITEM_GROUP          = &H00000004
%FLG_PROFITEM_CSIDL          = &H00000008

'
' Flags for AddProperty section lines in the INF
'

%FLG_ADDPROPERTY_NOCLOBBER       = &H00000001
%FLG_ADDPROPERTY_OVERWRITEONLY   = &H00000002
%FLG_ADDPROPERTY_APPEND          = &H00000004
%FLG_ADDPROPERTY_OR              = &H00000008
%FLG_ADDPROPERTY_AND             = &H00000010

'
' Flags for DelProperty section lines in the INF
'

%FLG_DELPROPERTY_MULTI_SZ_DELSTRING  = &H00000001


DECLARE FUNCTION SetupInstallFromInfSectionA LIB "SetupApi.dll" _
    ALIAS "SetupInstallFromInfSectionA" ( _
    BYVAL Owner AS DWORD, _  ' HWND
    BYVAL InfHandle AS HINF, _
    SectionName AS ASCIIZ, _
    BYVAL Flags AS DWORD, _
    BYVAL RelativeKeyRoot AS DWORD, _  ' HKEY
    SourceRootPath AS ASCIIZ, _
    BYVAL CopyFlags AS DWORD, _
    BYVAL MsgHandler AS DWORD, _   ' PSP_FILE_CALLBACK_A
    Context AS ANY, _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupInstallFromInfSectionW LIB "SetupApi.dll" _
    ALIAS "SetupInstallFromInfSectionW" ( _
    BYVAL Owner AS DWORD, _   ' HWND
    BYVAL InfHandle AS HINF, _
    SectionName AS WSTRINGZ, _
    BYVAL Flags AS DWORD, _
    BYVAL RelativeKeyRoot AS DWORD, _  ' HKEY
    SourceRootPath AS WSTRINGZ, _
    BYVAL CopyFlags AS DWORD, _
    BYVAL MsgHandler AS DWORD, _   ' PSP_FILE_CALLBACK_W
    Context AS ANY, _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupInstallFromInfSection LIB "SetupApi.dll" _
    ALIAS "SetupInstallFromInfSectionW" ( _
    BYVAL Owner AS DWORD, _   ' HWND
    BYVAL InfHandle AS HINF, _
    SectionName AS WSTRINGZ, _
    BYVAL Flags AS DWORD, _
    BYVAL RelativeKeyRoot AS DWORD, _  ' HKEY
    SourceRootPath AS WSTRINGZ, _
    BYVAL CopyFlags AS DWORD, _
    BYVAL MsgHandler AS DWORD, _   ' PSP_FILE_CALLBACK_W
    Context AS ANY, _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupInstallFromInfSection LIB "SetupApi.dll" _
    ALIAS "SetupInstallFromInfSectionA" ( _
    BYVAL Owner AS DWORD, _  ' HWND
    BYVAL InfHandle AS HINF, _
    SectionName AS ASCIIZ, _
    BYVAL Flags AS DWORD, _
    BYVAL RelativeKeyRoot AS DWORD, _  ' HKEY
    SourceRootPath AS ASCIIZ, _
    BYVAL CopyFlags AS DWORD, _
    BYVAL MsgHandler AS DWORD, _   ' PSP_FILE_CALLBACK_A
    Context AS ANY, _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ENDIF

'
' Flags for SetupInstallFromInfSection
'
%SPINST_LOGCONFIG                = &H00000001
%SPINST_INIFILES                 = &H00000002
%SPINST_REGISTRY                 = &H00000004
%SPINST_INI2REG                  = &H00000008
%SPINST_FILES                    = &H00000010
%SPINST_BITREG                   = &H00000020
%SPINST_REGSVR                   = &H00000040
%SPINST_UNREGSVR                 = &H00000080
%SPINST_PROFILEITEMS             = &H00000100

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

%SPINST_COPYINF                  = &H00000200

#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

%SPINST_PROPERTIES               = &H00000400
%SPINST_ALL                      = &H000007ff

#ELSE

%SPINST_ALL                      = &H000003ff

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

#ELSE

%SPINST_ALL                      = &H000001ff

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

%SPINST_SINGLESECTION            = &H00010000
%SPINST_LOGCONFIG_IS_FORCED      = &H00020000
%SPINST_LOGCONFIGS_ARE_OVERRIDES = &H00040000

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

%SPINST_REGISTERCALLBACKAWARE    = &H00080000

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

%SPINST_DEVICEINSTALL            = &H00100000

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

DECLARE FUNCTION SetupInstallFilesFromInfSectionA LIB "SetupApi.dll" _
    ALIAS "SetupInstallFilesFromInfSectionA" ( _
    BYVAL InfHandle AS HINF, _
    BYVAL LayoutInfHandle AS HINF, _
    BYVAL FileQueue AS HSPFILEQ, _
    SectionName AS ASCIIZ, _
    SourceRootPath AS ASCIIZ, _
    BYVAL CopyFlags AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupInstallFilesFromInfSectionW LIB "SetupApi.dll" _
    ALIAS "SetupInstallFilesFromInfSectionW" ( _
    BYVAL InfHandle AS HINF, _
    BYVAL LayoutInfHandle AS HINF, _
    BYVAL FileQueue AS HSPFILEQ, _
    SectionName AS WSTRINGZ, _
    SourceRootPath AS WSTRINGZ, _
    BYVAL CopyFlags AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupInstallFilesFromInfSection LIB "SetupApi.dll" _
    ALIAS "SetupInstallFilesFromInfSectionW" ( _
    BYVAL InfHandle AS HINF, _
    BYVAL LayoutInfHandle AS HINF, _
    BYVAL FileQueue AS HSPFILEQ, _
    SectionName AS WSTRINGZ, _
    SourceRootPath AS WSTRINGZ, _
    BYVAL CopyFlags AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupInstallFilesFromInfSection LIB "SetupApi.dll" _
    ALIAS "SetupInstallFilesFromInfSectionA" ( _
    BYVAL InfHandle AS HINF, _
    BYVAL LayoutInfHandle AS HINF, _
    BYVAL FileQueue AS HSPFILEQ, _
    SectionName AS ASCIIZ, _
    SourceRootPath AS ASCIIZ, _
    BYVAL CopyFlags AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


'
' Flags for SetupInstallServicesFromInfSection(Ex).  These flags are also used
' in the flags field of AddService or DelService lines in a device INF.  Some
' of these flags are not permitted in the non-Ex API.  These flags are marked
' as such below.
'

'
' (AddService) move service's tag to front of its group order list
'
%SPSVCINST_TAGTOFRONT                   = &H00000001

'
' (AddService) **Ex API only** mark this service as the function driver for the
' device being installed
'
%SPSVCINST_ASSOCSERVICE                 = &H00000002

'
' (DelService) delete the associated event log entry for a service specified in
' a DelService entry
'
%SPSVCINST_DELETEEVENTLOGENTRY          = &H00000004

'
' (AddService) don't overwrite display name if it already exists
'
%SPSVCINST_NOCLOBBER_DISPLAYNAME        = &H00000008

'
' (AddService) don't overwrite start type value if service already exists
'
%SPSVCINST_NOCLOBBER_STARTTYPE          = &H00000010

'
' (AddService) don't overwrite error control value if service already exists
'
%SPSVCINST_NOCLOBBER_ERRORCONTROL       = &H00000020

'
' (AddService) don't overwrite load order group if it already exists
'
%SPSVCINST_NOCLOBBER_LOADORDERGROUP     = &H00000040

'
' (AddService) don't overwrite dependencies list if it already exists
'
%SPSVCINST_NOCLOBBER_DEPENDENCIES       = &H00000080

'
' (AddService) don't overwrite description if it already exists
'
%SPSVCINST_NOCLOBBER_DESCRIPTION        = &H00000100
'
' (DelService) stop the associated service specified in
' a DelService entry before deleting the service
'
%SPSVCINST_STOPSERVICE                  = &H00000200

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP
'
' (AddService) force overwrite of security settings
'
%SPSVCINST_CLOBBER_SECURITY             = &H00000400

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN
'
' (Start Service) start a service manually after install
'
%SPSVCINST_STARTSERVICE                 = &H00000800

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

#IF %SETUPAPI_VER >= %WIN32_WINNT_WIN7
'
' (AddService) don't overwrite required privileges list if it already exists
'
%SPSVCINST_NOCLOBBER_REQUIREDPRIVILEGES = &H00001000

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WIN7



DECLARE FUNCTION SetupInstallServicesFromInfSectionA LIB "SetupApi.dll" _
    ALIAS "SetupInstallServicesFromInfSectionA" ( _
    BYVAL InfHandle AS HINF, _
    SectionName AS ASCIIZ, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupInstallServicesFromInfSectionW LIB "SetupApi.dll" _
    ALIAS "SetupInstallServicesFromInfSectionW" ( _
    BYVAL InfHandle AS HINF, _
    SectionName AS WSTRINGZ, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupInstallServicesFromInfSection LIB "SetupApi.dll" _
    ALIAS "SetupInstallServicesFromInfSectionW" ( _
    BYVAL InfHandle AS HINF, _
    SectionName AS WSTRINGZ, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupInstallServicesFromInfSection LIB "SetupApi.dll" _
    ALIAS "SetupInstallServicesFromInfSectionA" ( _
    BYVAL InfHandle AS HINF, _
    SectionName AS ASCIIZ, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupInstallServicesFromInfSectionExA LIB "SetupApi.dll" _
    ALIAS "SetupInstallServicesFromInfSectionExA" ( _
    BYVAL InfHandle AS HINF, _
    SectionName AS ASCIIZ, _
    BYVAL Flags AS DWORD, _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL Reserved1 AS DWORD, _  ' PVOID
    BYVAL Reserved2 AS DWORD _  ' PVOID
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupInstallServicesFromInfSectionExW LIB "SetupApi.dll" _
    ALIAS "SetupInstallServicesFromInfSectionExW" ( _
    BYVAL InfHandle AS HINF, _
    SectionName AS WSTRINGZ, _
    BYVAL Flags AS DWORD, _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL Reserved1 AS DWORD, _  ' PVOID
    BYVAL Reserved2 AS DWORD _  ' PVOID
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupInstallServicesFromInfSectionEx LIB "SetupApi.dll" _
    ALIAS "SetupInstallServicesFromInfSectionExW" ( _
    BYVAL InfHandle AS HINF, _
    SectionName AS WSTRINGZ, _
    BYVAL Flags AS DWORD, _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL Reserved1 AS DWORD, _  ' PVOID
    BYVAL Reserved2 AS DWORD _  ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupInstallServicesFromInfSectionEx LIB "SetupApi.dll" _
    ALIAS "SetupInstallServicesFromInfSectionExA" ( _
    BYVAL InfHandle AS HINF, _
    SectionName AS ASCIIZ, _
    BYVAL Flags AS DWORD, _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL Reserved1 AS DWORD, _  ' PVOID
    BYVAL Reserved2 AS DWORD _  ' PVOID
    ) AS LONG  ' BOOL
#ENDIF



'
' High level routine, usually used via rundll32.dll
' to perform right-click install action on INFs
' May be called directly:
'
' wsprintf(CmdLineBuffer,TEXT("DefaultInstall 132 %s"),InfPath);
' InstallHinfSection(NULL,NULL,CmdLineBuffer,0);
'
DECLARE SUB InstallHinfSectionA LIB "SetupApi.dll" _
    ALIAS "InstallHinfSectionA" ( _
    BYVAL WINDOW AS DWORD, _   ' HWND
    BYVAL ModuleHandle AS DWORD, _  ' HINSTANCE
    CommandLine AS ASCIIZ, _
    BYVAL ShowCommand AS LONG _
    )

DECLARE SUB InstallHinfSectionW LIB "SetupApi.dll" _
    ALIAS "InstallHinfSectionW" ( _
    BYVAL WINDOW AS DWORD, _   ' HWND
    BYVAL ModuleHandle AS DWORD, _  ' HINSTANCE
    CommandLine AS WSTRINGZ, _
    BYVAL ShowCommand AS LONG _
    )

#IF %DEF(%UNICODE)
DECLARE SUB InstallHinfSection LIB "SetupApi.dll" _
    ALIAS "InstallHinfSectionW" ( _
    BYVAL WINDOW AS DWORD, _   ' HWND
    BYVAL ModuleHandle AS DWORD, _  ' HINSTANCE
    CommandLine AS WSTRINGZ, _
    BYVAL ShowCommand AS LONG _
    )
#ELSE
DECLARE SUB InstallHinfSection LIB "SetupApi.dll" _
    ALIAS "InstallHinfSectionA" ( _
    BYVAL WINDOW AS DWORD, _   ' HWND
    BYVAL ModuleHandle AS DWORD, _  ' HINSTANCE
    CommandLine AS ASCIIZ, _
    BYVAL ShowCommand AS LONG _
    )
#ENDIF




'
' Define handle type for Setup file log.
'
MACRO HSPFILELOG=DWORD

DECLARE FUNCTION SetupInitializeFileLogA LIB "SetupApi.dll" _
    ALIAS "SetupInitializeFileLogA" ( _
    LogFileName AS ASCIIZ, _
    BYVAL Flags AS DWORD _
    ) AS HSPFILELOG

DECLARE FUNCTION SetupInitializeFileLogW LIB "SetupApi.dll" _
    ALIAS "SetupInitializeFileLogW" ( _
    LogFileName AS WSTRINGZ, _
    BYVAL Flags AS DWORD _
    ) AS HSPFILELOG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupInitializeFileLog LIB "SetupApi.dll" _
    ALIAS "SetupInitializeFileLogW" ( _
    LogFileName AS WSTRINGZ, _
    BYVAL Flags AS DWORD _
    ) AS HSPFILELOG
#ELSE
DECLARE FUNCTION SetupInitializeFileLog LIB "SetupApi.dll" _
    ALIAS "SetupInitializeFileLogA" ( _
    LogFileName AS ASCIIZ, _
    BYVAL Flags AS DWORD _
    ) AS HSPFILELOG
#ENDIF

'
' Flags for SetupInitializeFileLog
'
%SPFILELOG_SYSTEMLOG = &H00000001  ' use system log -- must be Administrator
%SPFILELOG_FORCENEW  = &H00000002  ' not valid with SPFILELOG_SYSTEMLOG
%SPFILELOG_QUERYONLY = &H00000004  ' allows non-administrators to read system log


DECLARE FUNCTION SetupTerminateFileLog LIB "SetupApi.dll" _
    ALIAS "SetupTerminateFileLog" ( _
    BYVAL FileLogHandle AS HSPFILELOG _
    ) AS LONG  ' BOOL


DECLARE FUNCTION SetupLogFileA LIB "SetupApi.dll" _
    ALIAS "SetupLogFileA" ( _
    BYVAL FileLogHandle AS HSPFILELOG, _
    LogSectionName AS ASCIIZ, _
    SourceFilename AS ASCIIZ, _
    TargetFilename AS ASCIIZ, _
    BYVAL Checksum AS DWORD, _
    DiskTagfile AS ASCIIZ, _
    DiskDescription AS ASCIIZ, _
    OtherInfo AS ASCIIZ, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupLogFileW LIB "SetupApi.dll" _
    ALIAS "SetupLogFileW" ( _
    BYVAL FileLogHandle AS HSPFILELOG, _
    LogSectionName AS WSTRINGZ, _
    SourceFilename AS WSTRINGZ, _
    TargetFilename AS WSTRINGZ, _
    BYVAL Checksum AS DWORD, _
    DiskTagfile AS WSTRINGZ, _
    DiskDescription AS WSTRINGZ, _
    OtherInfo AS WSTRINGZ, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupLogFile LIB "SetupApi.dll" _
    ALIAS "SetupLogFileW" ( _
    BYVAL FileLogHandle AS HSPFILELOG, _
    LogSectionName AS WSTRINGZ, _
    SourceFilename AS WSTRINGZ, _
    TargetFilename AS WSTRINGZ, _
    BYVAL Checksum AS DWORD, _
    DiskTagfile AS WSTRINGZ, _
    DiskDescription AS WSTRINGZ, _
    OtherInfo AS WSTRINGZ, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupLogFile LIB "SetupApi.dll" _
    ALIAS "SetupLogFileA" ( _
    BYVAL FileLogHandle AS HSPFILELOG, _
    LogSectionName AS ASCIIZ, _
    SourceFilename AS ASCIIZ, _
    TargetFilename AS ASCIIZ, _
    BYVAL Checksum AS DWORD, _
    DiskTagfile AS ASCIIZ, _
    DiskDescription AS ASCIIZ, _
    OtherInfo AS ASCIIZ, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

'
' Flags for SetupLogFile
'
%SPFILELOG_OEMFILE = &H00000001


DECLARE FUNCTION SetupRemoveFileLogEntryA LIB "SetupApi.dll" _
    ALIAS "SetupRemoveFileLogEntryA" ( _
    BYVAL FileLogHandle AS HSPFILELOG, _
    LogSectionName AS ASCIIZ, _
    TargetFilename AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupRemoveFileLogEntryW LIB "SetupApi.dll" _
    ALIAS "SetupRemoveFileLogEntryW" ( _
    BYVAL FileLogHandle AS HSPFILELOG, _
    LogSectionName AS WSTRINGZ, _
    TargetFilename AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupRemoveFileLogEntry LIB "SetupApi.dll" _
    ALIAS "SetupRemoveFileLogEntryW" ( _
    BYVAL FileLogHandle AS HSPFILELOG, _
    LogSectionName AS WSTRINGZ, _
    TargetFilename AS WSTRINGZ _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupRemoveFileLogEntry LIB "SetupApi.dll" _
    ALIAS "SetupRemoveFileLogEntryA" ( _
    BYVAL FileLogHandle AS HSPFILELOG, _
    LogSectionName AS ASCIIZ, _
    TargetFilename AS ASCIIZ _
    ) AS LONG  ' BOOL
#ENDIF


'
' Items retrievable from SetupQueryFileLog()
'
MACRO SetupFileLogInfo_enum=LONG
ENUM SetupFileLogInfo SINGULAR
    SetupFileLogSourceFilename
    SetupFileLogChecksum
    SetupFileLogDiskTagfile
    SetupFileLogDiskDescription
    SetupFileLogOtherInfo
    SetupFileLogMax
END ENUM

DECLARE FUNCTION SetupQueryFileLogA LIB "SetupApi.dll" _
    ALIAS "SetupQueryFileLogA" ( _
    BYVAL FileLogHandle AS HSPFILELOG, _
    LogSectionName AS ASCIIZ, _
    TargetFilename AS ASCIIZ, _
    BYVAL DesiredInfo AS SetupFileLogInfo_enum, _
    DataOut AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupQueryFileLogW LIB "SetupApi.dll" _
    ALIAS "SetupQueryFileLogW" ( _
    BYVAL FileLogHandle AS HSPFILELOG, _
    LogSectionName AS WSTRINGZ, _
    TargetFilename AS WSTRINGZ, _
    BYVAL DesiredInfo AS SetupFileLogInfo_enum, _
    DataOut AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupQueryFileLog LIB "SetupApi.dll" _
    ALIAS "SetupQueryFileLogW" ( _
    BYVAL FileLogHandle AS HSPFILELOG, _
    LogSectionName AS WSTRINGZ, _
    TargetFilename AS WSTRINGZ, _
    BYVAL DesiredInfo AS SetupFileLogInfo_enum, _
    DataOut AS WSTRINGZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupQueryFileLog LIB "SetupApi.dll" _
    ALIAS "SetupQueryFileLogA" ( _
    BYVAL FileLogHandle AS HSPFILELOG, _
    LogSectionName AS ASCIIZ, _
    TargetFilename AS ASCIIZ, _
    BYVAL DesiredInfo AS SetupFileLogInfo_enum, _
    DataOut AS ASCIIZ, _
    BYVAL ReturnBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

'
' Text logging APIs
'
MACRO LogSeverity          = DWORD
%LogSevInformation         = &H00000000
%LogSevWarning             = &H00000001
%LogSevError               = &H00000002
%LogSevFatalError          = &H00000003
%LogSevMaximum             = &H00000004

DECLARE FUNCTION SetupOpenLog LIB "SetupApi.dll" _
    ALIAS "SetupOpenLog" ( _
    BYVAL ERASE AS LONG _  ' BOOL
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupLogErrorA LIB "SetupApi.dll" _
    ALIAS "SetupLogErrorA" ( _
    MessageString AS ASCIIZ, _
    BYVAL Severity AS LogSeverity _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupLogErrorW LIB "SetupApi.dll" _
    ALIAS "SetupLogErrorW" ( _
    MessageString AS WSTRINGZ, _
    BYVAL Severity AS LogSeverity _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupLogError LIB "SetupApi.dll" _
    ALIAS "SetupLogErrorW" ( _
    MessageString AS WSTRINGZ, _
    BYVAL Severity AS LogSeverity _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupLogError LIB "SetupApi.dll" _
    ALIAS "SetupLogErrorA" ( _
    MessageString AS ASCIIZ, _
    BYVAL Severity AS LogSeverity _
    ) AS LONG  ' BOOL
#ENDIF

DECLARE SUB SetupCloseLog LIB "SetupApi.dll" ALIAS "SetupCloseLog" ()

'
' Text log for INF debugging
'

#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN


DECLARE FUNCTION SetupGetThreadLogToken LIB "SetupApi.dll" _
    ALIAS "SetupGetThreadLogToken" () AS SP_LOG_TOKEN

DECLARE SUB SetupSetThreadLogToken LIB "SetupApi.dll" _
    ALIAS "SetupSetThreadLogToken" ( _
    BYVAL LogToken AS SP_LOG_TOKEN _
    )

DECLARE SUB SetupWriteTextLog LIB "SetupApi.dll" _
    ALIAS "SetupWriteTextLog" ( _
    BYVAL LogToken AS SP_LOG_TOKEN, _
    BYVAL Category AS DWORD, _
    BYVAL Flags AS DWORD, _
    BYREF MessageStr AS ASCIIZ, _
    OPTIONAL BYREF ANY _
    OPTIONAL BYREF ANY _
    OPTIONAL BYREF ANY _
    OPTIONAL BYREF ANY _
    OPTIONAL BYREF ANY _
    OPTIONAL BYREF ANY _
    OPTIONAL BYREF ANY _
    OPTIONAL BYREF ANY _
    OPTIONAL BYREF ANY _
    OPTIONAL BYREF ANY _
    )

DECLARE SUB SetupWriteTextLogError LIB "SetupApi.dll" _
    ALIAS "SetupWriteTextLogError" ( _
    BYVAL LogToken AS SP_LOG_TOKEN, _
    BYVAL Category AS DWORD, _
    BYVAL LogFlags AS DWORD, _
    BYVAL ERROR AS DWORD, _
    BYREF MessageStr AS ASCIIZ, _
    OPTIONAL BYREF ANY _
    OPTIONAL BYREF ANY _
    OPTIONAL BYREF ANY _
    OPTIONAL BYREF ANY _
    OPTIONAL BYREF ANY _
    OPTIONAL BYREF ANY _
    OPTIONAL BYREF ANY _
    OPTIONAL BYREF ANY _
    OPTIONAL BYREF ANY _
    OPTIONAL BYREF ANY _    
    )

DECLARE SUB SetupWriteTextLogInfLine LIB "SetupApi.dll" _
    ALIAS "SetupWriteTextLogInfLine" ( _
    BYVAL LogToken AS SP_LOG_TOKEN, _
    BYVAL Flags AS DWORD, _
    BYVAL InfHandle AS HINF, _
    Context AS INFCONTEXT _
    )

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN


'
' Backup Information API's
'

DECLARE FUNCTION SetupGetBackupInformationA LIB "SetupApi.dll" _
    ALIAS "SetupGetBackupInformationA" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    BYVAL BackupParams AS SP_BACKUP_QUEUE_PARAMS_A PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupGetBackupInformationW LIB "SetupApi.dll" _
    ALIAS "SetupGetBackupInformationW" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    BYVAL BackupParams AS SP_BACKUP_QUEUE_PARAMS_W PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupGetBackupInformation LIB "SetupApi.dll" _
    ALIAS "SetupGetBackupInformationW" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    BYVAL BackupParams AS SP_BACKUP_QUEUE_PARAMS_W PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupGetBackupInformation LIB "SetupApi.dll" _
    ALIAS "SetupGetBackupInformationA" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    BYVAL BackupParams AS SP_BACKUP_QUEUE_PARAMS_A PTR _
    ) AS LONG  ' BOOL
#ENDIF

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

DECLARE FUNCTION SetupPrepareQueueForRestoreA LIB "SetupApi.dll" _
    ALIAS "SetupPrepareQueueForRestoreA" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    BackupPath AS ASCIIZ, _
    BYVAL RestoreFlags AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupPrepareQueueForRestoreW LIB "SetupApi.dll" _
    ALIAS "SetupPrepareQueueForRestoreW" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    BackupPath AS WSTRINGZ, _
    BYVAL RestoreFlags AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupPrepareQueueForRestore LIB "SetupApi.dll" _
    ALIAS "SetupPrepareQueueForRestoreW" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    BackupPath AS WSTRINGZ, _
    BYVAL RestoreFlags AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupPrepareQueueForRestore LIB "SetupApi.dll" _
    ALIAS "SetupPrepareQueueForRestoreA" ( _
    BYVAL QueueHandle AS HSPFILEQ, _
    BackupPath AS ASCIIZ, _
    BYVAL RestoreFlags AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

'
' Control forcing of Non-Interactive Mode
' Overriden if SetupAPI is run in non-interactive window session
'

DECLARE FUNCTION SetupSetNonInteractiveMode LIB "SetupApi.dll" _
    ALIAS "SetupSetNonInteractiveMode" ( _
    BYVAL NonInteractiveFlag AS LONG _  ' BOOL
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupGetNonInteractiveMode LIB "SetupApi.dll" _
    ALIAS "SetupGetNonInteractiveMode" () AS LONG  ' bool

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

'
' Device Installer APIs
'

DECLARE FUNCTION SetupDiCreateDeviceInfoList LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInfoList" ( _
    ClassGuid AS GUID, _
    hwndParent AS DWORD _    ' HWND
    ) AS HDEVINFO


DECLARE FUNCTION SetupDiCreateDeviceInfoListExA LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInfoListExA" ( _
    ClassGuid AS GUID, _
    BYVAL hwndParent AS DWORD, _  ' HWND
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _     ' PVOID
    ) AS HDEVINFO

DECLARE FUNCTION SetupDiCreateDeviceInfoListExW LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInfoListExW" ( _
    ClassGuid AS GUID, _
    BYVAL hwndParent AS DWORD, _  ' HWND
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _     ' PVOID
    ) AS HDEVINFO

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiCreateDeviceInfoListEx LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInfoListExW" ( _
    ClassGuid AS GUID, _
    BYVAL hwndParent AS DWORD, _  ' HWND
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _     ' PVOID
    ) AS HDEVINFO
#ELSE
DECLARE FUNCTION SetupDiCreateDeviceInfoListEx LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInfoListExA" ( _
    ClassGuid AS GUID, _
    BYVAL hwndParent AS DWORD, _  ' HWND
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _     ' PVOID
    ) AS HDEVINFO
#ENDIF


DECLARE FUNCTION SetupDiGetDeviceInfoListClass LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInfoListClass" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    ClassGuid AS GUID _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetDeviceInfoListDetailA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInfoListDetailA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoSetDetailData AS SP_DEVINFO_LIST_DETAIL_DATA_A PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetDeviceInfoListDetailW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInfoListDetailW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoSetDetailData AS SP_DEVINFO_LIST_DETAIL_DATA_W PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetDeviceInfoListDetail LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInfoListDetailW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoSetDetailData AS SP_DEVINFO_LIST_DETAIL_DATA_W PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDeviceInfoListDetail LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInfoListDetailA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoSetDetailData AS SP_DEVINFO_LIST_DETAIL_DATA_A PTR _
    ) AS LONG  ' BOOL
#ENDIF


'
' Flags for SetupDiCreateDeviceInfo
'
%DICD_GENERATE_ID       = &H00000001
%DICD_INHERIT_CLASSDRVS = &H00000002

DECLARE FUNCTION SetupDiCreateDeviceInfoA LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInfoA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    DeviceName AS ASCIIZ, _
    ClassGuid AS GUID, _
    DeviceDescription AS ASCIIZ, _
    BYVAL hwndParent AS DWORD, _   ' HWND
    BYVAL CreationFlags AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiCreateDeviceInfoW LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInfoW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    DeviceName AS WSTRINGZ, _
    ClassGuid AS GUID, _
    DeviceDescription AS WSTRINGZ, _
    BYVAL hwndParent AS DWORD, _   ' HWND
    BYVAL CreationFlags AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiCreateDeviceInfo LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInfoW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    DeviceName AS WSTRINGZ, _
    ClassGuid AS GUID, _
    DeviceDescription AS WSTRINGZ, _
    BYVAL hwndParent AS DWORD, _   ' HWND
    BYVAL CreationFlags AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiCreateDeviceInfo LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInfoA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    DeviceName AS ASCIIZ, _
    ClassGuid AS GUID, _
    DeviceDescription AS ASCIIZ, _
    BYVAL hwndParent AS DWORD, _   ' HWND
    BYVAL CreationFlags AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ENDIF


'
' Flags for SetupDiOpenDeviceInfo
'
%DIOD_INHERIT_CLASSDRVS = &H00000002
%DIOD_CANCEL_REMOVE     = &H00000004

DECLARE FUNCTION SetupDiOpenDeviceInfoA LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenDeviceInfoA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    DeviceInstanceId AS ASCIIZ, _
    BYVAL hwndParent AS DWORD, _   ' HWND
    BYVAL OpenFlags AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiOpenDeviceInfoW LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenDeviceInfoW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    DeviceInstanceId AS WSTRINGZ, _
    BYVAL hwndParent AS DWORD, _   ' HWND
    BYVAL OpenFlags AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiOpenDeviceInfo LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenDeviceInfoW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    DeviceInstanceId AS WSTRINGZ, _
    BYVAL hwndParent AS DWORD, _   ' HWND
    BYVAL OpenFlags AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiOpenDeviceInfo LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenDeviceInfoA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    DeviceInstanceId AS ASCIIZ, _
    BYVAL hwndParent AS DWORD, _   ' HWND
    BYVAL OpenFlags AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiGetDeviceInstanceIdA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInstanceIdA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    DeviceInstanceId AS ASCIIZ, _
    BYVAL DeviceInstanceIdSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetDeviceInstanceIdW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInstanceIdW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    DeviceInstanceId AS WSTRINGZ, _
    BYVAL DeviceInstanceIdSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetDeviceInstanceId LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInstanceIdW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    DeviceInstanceId AS WSTRINGZ, _
    BYVAL DeviceInstanceIdSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDeviceInstanceId LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInstanceIdA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    DeviceInstanceId AS ASCIIZ, _
    BYVAL DeviceInstanceIdSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiDeleteDeviceInfo LIB "SetupApi.dll" _
    ALIAS "SetupDiDeleteDeviceInfo" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL


DECLARE FUNCTION SetupDiEnumDeviceInfo LIB "SetupApi.dll" _
    ALIAS "SetupDiEnumDeviceInfo" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL MemberIndex AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL


DECLARE FUNCTION SetupDiDestroyDeviceInfoList LIB "SetupApi.dll" _
    ALIAS "SetupDiDestroyDeviceInfoList" ( _
    BYVAL DeviceInfoSet AS HDEVINFO _
    ) AS LONG  ' BOOL


DECLARE FUNCTION SetupDiEnumDeviceInterfaces LIB "SetupApi.dll" _
    ALIAS "SetupDiEnumDeviceInterfaces" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    InterfaceClassGuid AS GUID, _
    BYVAL MemberIndex AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL

'
' Backward compatibility--do not use
'
DECLARE FUNCTION SetupDiEnumInterfaceDevice LIB "SetupApi.dll" _
    ALIAS "SetupDiEnumDeviceInterfaces" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    InterfaceClassGuid AS GUID, _
    BYVAL MemberIndex AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL



DECLARE FUNCTION SetupDiCreateDeviceInterfaceA LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInterfaceA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    InterfaceClassGuid AS GUID, _
    ReferenceString AS ASCIIZ, _
    BYVAL CreationFlags AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiCreateDeviceInterfaceW LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInterfaceW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    InterfaceClassGuid AS GUID, _
    ReferenceString AS WSTRINGZ, _
    BYVAL CreationFlags AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiCreateDeviceInterface LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInterfaceW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    InterfaceClassGuid AS GUID, _
    ReferenceString AS WSTRINGZ, _
    BYVAL CreationFlags AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiCreateDeviceInterface LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInterfaceA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    InterfaceClassGuid AS GUID, _
    ReferenceString AS ASCIIZ, _
    BYVAL CreationFlags AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL
#ENDIF

'
' Backward compatibility--do not use.
'
DECLARE FUNCTION SetupDiCreateInterfaceDeviceA LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInterfaceA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    InterfaceClassGuid AS GUID, _
    ReferenceString AS ASCIIZ, _
    BYVAL CreationFlags AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiCreateInterfaceDeviceW LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInterfaceW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    InterfaceClassGuid AS GUID, _
    ReferenceString AS WSTRINGZ, _
    BYVAL CreationFlags AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiCreateInterfaceDevice LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInterfaceW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    InterfaceClassGuid AS GUID, _
    ReferenceString AS WSTRINGZ, _
    BYVAL CreationFlags AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiCreateInterfaceDevice LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInterfaceA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    InterfaceClassGuid AS GUID, _
    ReferenceString AS ASCIIZ, _
    BYVAL CreationFlags AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL
#ENDIF


'
' Flags for SetupDiOpenDeviceInterface
'
%DIODI_NO_ADD  = &H00000001

DECLARE FUNCTION SetupDiOpenDeviceInterfaceA LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenDeviceInterfaceA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    DevicePath AS ASCIIZ, _
    BYVAL OpenFlags AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiOpenDeviceInterfaceW LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenDeviceInterfaceW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    DevicePath AS WSTRINGZ, _
    BYVAL OpenFlags AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiOpenDeviceInterface LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenDeviceInterfaceW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    DevicePath AS WSTRINGZ, _
    BYVAL OpenFlags AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiOpenDeviceInterface LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenDeviceInterfaceA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    DevicePath AS ASCIIZ, _
    BYVAL OpenFlags AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL
#ENDIF

'
' Backward compatibility--do not use
'
DECLARE FUNCTION SetupDiOpenInterfaceDeviceA LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenDeviceInterfaceA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    DevicePath AS ASCIIZ, _
    BYVAL OpenFlags AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiOpenInterfaceDeviceW LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenDeviceInterfaceW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    DevicePath AS WSTRINGZ, _
    BYVAL OpenFlags AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL
#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiOpenInterfaceDevice LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenDeviceInterfaceW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    DevicePath AS WSTRINGZ, _
    BYVAL OpenFlags AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiOpenInterfaceDevice LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenDeviceInterfaceA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    DevicePath AS ASCIIZ, _
    BYVAL OpenFlags AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiGetDeviceInterfaceAlias LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInterfaceAlias" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    AliasInterfaceClassGuid AS GUID, _
    BYVAL AliasDeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL

'
' Backward compatibility--do not use.
'
DECLARE FUNCTION SetupDiGetInterfaceDeviceAlias LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInterfaceAlias" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    AliasInterfaceClassGuid AS GUID, _
    BYVAL AliasDeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL


DECLARE FUNCTION SetupDiDeleteDeviceInterfaceData LIB "SetupApi.dll" _
    ALIAS "SetupDiDeleteDeviceInterfaceData" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL

'
' Backward compatibility--do not use.
'
DECLARE FUNCTION SetupDiDeleteInterfaceDeviceData LIB "SetupApi.dll" _
    ALIAS "SetupDiDeleteDeviceInterfaceData" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL


DECLARE FUNCTION SetupDiRemoveDeviceInterface LIB "SetupApi.dll" _
    ALIAS "SetupDiRemoveDeviceInterface" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL

'
' Backward compatibility--do not use.
'
DECLARE FUNCTION SetupDiRemoveInterfaceDevice LIB "SetupApi.dll" _
    ALIAS "SetupDiRemoveDeviceInterface" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL


DECLARE FUNCTION SetupDiGetDeviceInterfaceDetailA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInterfaceDetailA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL DeviceInterfaceDetailData AS SP_DEVICE_INTERFACE_DETAIL_DATA_A PTR, _
    BYVAL DeviceInterfaceDetailDataSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetDeviceInterfaceDetailW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInterfaceDetailW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL DeviceInterfaceDetailData AS SP_DEVICE_INTERFACE_DETAIL_DATA_W PTR, _
    BYVAL DeviceInterfaceDetailDataSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetDeviceInterfaceDetail LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInterfaceDetailW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL DeviceInterfaceDetailData AS SP_DEVICE_INTERFACE_DETAIL_DATA_W PTR, _
    BYVAL DeviceInterfaceDetailDataSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDeviceInterfaceDetail LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInterfaceDetailA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL DeviceInterfaceDetailData AS SP_DEVICE_INTERFACE_DETAIL_DATA_A PTR, _
    BYVAL DeviceInterfaceDetailDataSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ENDIF

'
' Backward compatibility--do not use.
'
DECLARE FUNCTION SetupDiGetInterfaceDeviceDetailA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInterfaceDetailA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL DeviceInterfaceDetailData AS SP_DEVICE_INTERFACE_DETAIL_DATA_A PTR, _
    BYVAL DeviceInterfaceDetailDataSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetInterfaceDeviceDetailW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInterfaceDetailW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL DeviceInterfaceDetailData AS SP_DEVICE_INTERFACE_DETAIL_DATA_W PTR, _
    BYVAL DeviceInterfaceDetailDataSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetInterfaceDeviceDetail LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInterfaceDetailW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL DeviceInterfaceDetailData AS SP_DEVICE_INTERFACE_DETAIL_DATA_W PTR, _
    BYVAL DeviceInterfaceDetailDataSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetInterfaceDeviceDetail LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInterfaceDetailA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL DeviceInterfaceDetailData AS SP_DEVICE_INTERFACE_DETAIL_DATA_A PTR, _
    BYVAL DeviceInterfaceDetailDataSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ENDIF


'
' Default install handler for DIF_INSTALLINTERFACES.
'
DECLARE FUNCTION SetupDiInstallDeviceInterfaces LIB "SetupApi.dll" _
    ALIAS "SetupDiInstallDeviceInterfaces" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL

'
' Backward compatibility--do not use.
'
DECLARE FUNCTION SetupDiInstallInterfaceDevices LIB "SetupApi.dll" _
    ALIAS "SetupDiInstallDeviceInterfaces" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL


#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

DECLARE FUNCTION SetupDiSetDeviceInterfaceDefault LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDeviceInterfaceDefault" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL Flags AS DWORD, _
    BYVAL Reserved AS DWORD _  ' PVOID
    ) AS LONG  ' BOOL

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP


'
' Default install handler for DIF_REGISTERDEVICE
'

'
' Flags for SetupDiRegisterDeviceInfo
'
%SPRDI_FIND_DUPS      = &H00000001

DECLARE FUNCTION SetupDiRegisterDeviceInfo LIB "SetupApi.dll" _
    ALIAS "SetupDiRegisterDeviceInfo" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL Flags AS DWORD, _
    BYVAL CompareProc AS DWORD, _  ' PSP_DETSIG_CMPPROC callback
    BYVAL CompareContext AS DWORD, _   ' PVOID
    BYVAL DupDeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL


'
' Ordinal values distinguishing between class drivers and
' device drivers.
' (Passed in 'DriverType' parameter of driver information list APIs)
'
%SPDIT_NODRIVER          = &H00000000
%SPDIT_CLASSDRIVER       = &H00000001
%SPDIT_COMPATDRIVER      = &H00000002

DECLARE FUNCTION SetupDiBuildDriverInfoList LIB "SetupApi.dll" _
    ALIAS "SetupDiBuildDriverInfoList" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverType AS DWORD _
    ) AS LONG  ' BOOL


DECLARE FUNCTION SetupDiCancelDriverInfoSearch LIB "SetupApi.dll" _
    ALIAS "SetupDiCancelDriverInfoSearch" ( _
    BYVAL DeviceInfoSet AS HDEVINFO _
    ) AS LONG  ' BOOL


DECLARE FUNCTION SetupDiEnumDriverInfoA LIB "SetupApi.dll" _
    ALIAS "SetupDiEnumDriverInfoA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverType AS DWORD, _
    BYVAL MemberIndex AS DWORD, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_A PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiEnumDriverInfoW LIB "SetupApi.dll" _
    ALIAS "SetupDiEnumDriverInfoW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverType AS DWORD, _
    BYVAL MemberIndex AS DWORD, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_W PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiEnumDriverInfo LIB "SetupApi.dll" _
    ALIAS "SetupDiEnumDriverInfoW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverType AS DWORD, _
    BYVAL MemberIndex AS DWORD, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_W PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiEnumDriverInfo LIB "SetupApi.dll" _
    ALIAS "SetupDiEnumDriverInfoA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverType AS DWORD, _
    BYVAL MemberIndex AS DWORD, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_A PTR _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiGetSelectedDriverA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetSelectedDriverA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_A PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetSelectedDriverW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetSelectedDriverW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_W PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetSelectedDriver LIB "SetupApi.dll" _
    ALIAS "SetupDiGetSelectedDriverW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_W PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetSelectedDriver LIB "SetupApi.dll" _
    ALIAS "SetupDiGetSelectedDriverA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_A PTR _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiSetSelectedDriverA LIB "SetupApi.dll" _
    ALIAS "SetupDiSetSelectedDriverA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_A PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiSetSelectedDriverW LIB "SetupApi.dll" _
    ALIAS "SetupDiSetSelectedDriverW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_W PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiSetSelectedDriver LIB "SetupApi.dll" _
    ALIAS "SetupDiSetSelectedDriverW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_W PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSetSelectedDriver LIB "SetupApi.dll" _
    ALIAS "SetupDiSetSelectedDriverA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_A PTR _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiGetDriverInfoDetailA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDriverInfoDetailA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_A PTR, _
    BYVAL DriverInfoDetailData AS SP_DRVINFO_DETAIL_DATA_A PTR, _
    BYVAL DriverInfoDetailDataSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetDriverInfoDetailW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDriverInfoDetailW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_W PTR, _
    BYVAL DriverInfoDetailData AS SP_DRVINFO_DETAIL_DATA_W PTR, _
    BYVAL DriverInfoDetailDataSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetDriverInfoDetail LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDriverInfoDetailW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_W PTR, _
    BYVAL DriverInfoDetailData AS SP_DRVINFO_DETAIL_DATA_W PTR, _
    BYVAL DriverInfoDetailDataSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDriverInfoDetail LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDriverInfoDetailA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_A PTR, _
    BYVAL DriverInfoDetailData AS SP_DRVINFO_DETAIL_DATA_A PTR, _
    BYVAL DriverInfoDetailDataSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiDestroyDriverInfoList LIB "SetupApi.dll" _
    ALIAS "SetupDiDestroyDriverInfoList" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverType AS DWORD _
    ) AS LONG  ' BOOL


'
' Flags controlling what is included in the device information set built
' by SetupDiGetClassDevs
'
%DIGCF_DEFAULT         = &H00000001  ' only valid with DIGCF_DEVICEINTERFACE
%DIGCF_PRESENT         = &H00000002
%DIGCF_ALLCLASSES      = &H00000004
%DIGCF_PROFILE         = &H00000008
%DIGCF_DEVICEINTERFACE = &H00000010

'
' Backward compatibility--do not use.
'
%DIGCF_INTERFACEDEVICE=%DIGCF_DEVICEINTERFACE


DECLARE FUNCTION SetupDiGetClassDevsA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDevsA" ( _
    ClassGuid AS GUID, _
    Enumerator AS ASCIIZ, _
    BYVAL hwndParent AS DWORD, _  ' HWND
    BYVAL Flags AS DWORD _
    ) AS HDEVINFO

DECLARE FUNCTION SetupDiGetClassDevsW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDevsW" ( _
    ClassGuid AS GUID, _
    Enumerator AS WSTRINGZ, _
    BYVAL hwndParent AS DWORD, _   ' HWND
    BYVAL Flags AS DWORD _
    ) AS HDEVINFO

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetClassDevs LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDevsW" ( _
    ClassGuid AS GUID, _
    Enumerator AS WSTRINGZ, _
    BYVAL hwndParent AS DWORD, _   ' HWND
    BYVAL Flags AS DWORD _
    ) AS HDEVINFO
#ELSE
DECLARE FUNCTION SetupDiGetClassDevs LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDevsA" ( _
    ClassGuid AS GUID, _
    Enumerator AS ASCIIZ, _
    BYVAL hwndParent AS DWORD, _  ' HWND
    BYVAL Flags AS DWORD _
    ) AS HDEVINFO
#ENDIF


DECLARE FUNCTION SetupDiGetClassDevsExA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDevsExA" ( _
    ClassGuid AS GUID, _
    Enumerator AS ASCIIZ, _
    BYVAL hwndParent AS DWORD, _  ' HWND
    BYVAL Flags AS DWORD, _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _     ' PVOID
    ) AS HDEVINFO

DECLARE FUNCTION SetupDiGetClassDevsExW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDevsExW" ( _
    ClassGuid AS GUID, _
    Enumerator AS WSTRINGZ, _
    BYVAL hwndParent AS DWORD, _  ' HWND
    BYVAL Flags AS DWORD, _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _     ' PVOID
    ) AS HDEVINFO

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetClassDevsEx LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDevsExW" ( _
    ClassGuid AS GUID, _
    Enumerator AS WSTRINGZ, _
    BYVAL hwndParent AS DWORD, _  ' HWND
    BYVAL Flags AS DWORD, _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _     ' PVOID
    ) AS HDEVINFO
#ELSE
DECLARE FUNCTION SetupDiGetClassDevsEx LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDevsExA" ( _
    ClassGuid AS GUID, _
    Enumerator AS ASCIIZ, _
    BYVAL hwndParent AS DWORD, _  ' HWND
    BYVAL Flags AS DWORD, _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _     ' PVOID
    ) AS HDEVINFO
#ENDIF


DECLARE FUNCTION SetupDiGetINFClassA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetINFClassA" ( _
    InfName AS ASCIIZ, _
    ClassGuid AS GUID, _
    ClassName AS ASCIIZ, _
    BYVAL ClassNameSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetINFClassW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetINFClassW" ( _
    InfName AS WSTRINGZ, _
    ClassGuid AS GUID, _
    ClassName AS WSTRINGZ, _
    BYVAL ClassNameSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetINFClass LIB "SetupApi.dll" _
    ALIAS "SetupDiGetINFClassW" ( _
    InfName AS WSTRINGZ, _
    ClassGuid AS GUID, _
    ClassName AS WSTRINGZ, _
    BYVAL ClassNameSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetINFClass LIB "SetupApi.dll" _
    ALIAS "SetupDiGetINFClassA" ( _
    InfName AS ASCIIZ, _
    ClassGuid AS GUID, _
    ClassName AS ASCIIZ, _
    BYVAL ClassNameSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


'
' Flags controlling exclusion from the class information list built
' by SetupDiBuildClassInfoList(Ex)
'
%DIBCI_NOINSTALLCLASS = &H00000001
%DIBCI_NODISPLAYCLASS = &H00000002

DECLARE FUNCTION SetupDiBuildClassInfoList LIB "SetupApi.dll" _
    ALIAS "SetupDiBuildClassInfoList" ( _
    BYVAL Flags AS DWORD, _
    ClassGuidList AS GUID, _
    BYVAL ClassGuidListSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL


DECLARE FUNCTION SetupDiBuildClassInfoListExA LIB "SetupApi.dll" _
    ALIAS "SetupDiBuildClassInfoListExA" ( _
    BYVAL Flags AS DWORD, _
    ClassGuidList AS GUID, _
    BYVAL ClassGuidListSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiBuildClassInfoListExW LIB "SetupApi.dll" _
    ALIAS "SetupDiBuildClassInfoListExW" ( _
    BYVAL Flags AS DWORD, _
    ClassGuidList AS GUID, _
    BYVAL ClassGuidListSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiBuildClassInfoListEx LIB "SetupApi.dll" _
    ALIAS "SetupDiBuildClassInfoListExW" ( _
    BYVAL Flags AS DWORD, _
    ClassGuidList AS GUID, _
    BYVAL ClassGuidListSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiBuildClassInfoListEx LIB "SetupApi.dll" _
    ALIAS "SetupDiBuildClassInfoListExA" ( _
    BYVAL Flags AS DWORD, _
    ClassGuidList AS GUID, _
    BYVAL ClassGuidListSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiGetClassDescriptionA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDescriptionA" ( _
    ClassGuid AS GUID, _
    ClassDescription AS ASCIIZ, _
    BYVAL ClassDescriptionSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetClassDescriptionW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDescriptionW" ( _
    ClassGuid AS GUID, _
    ClassDescription AS WSTRINGZ, _
    BYVAL ClassDescriptionSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetClassDescription LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDescriptionW" ( _
    ClassGuid AS GUID, _
    ClassDescription AS WSTRINGZ, _
    BYVAL ClassDescriptionSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetClassDescription LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDescriptionA" ( _
    ClassGuid AS GUID, _
    ClassDescription AS ASCIIZ, _
    BYVAL ClassDescriptionSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiGetClassDescriptionExA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDescriptionExA" ( _
    ClassGuid AS GUID, _
    ClassDescription AS ASCIIZ, _
    BYVAL ClassDescriptionSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _    ' PVOID
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetClassDescriptionExW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDescriptionExW" ( _
    ClassGuid AS GUID, _
    ClassDescription AS WSTRINGZ, _
    BYVAL ClassDescriptionSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetClassDescriptionEx LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDescriptionExW" ( _
    ClassGuid AS GUID, _
    ClassDescription AS WSTRINGZ, _
    BYVAL ClassDescriptionSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetClassDescriptionEx LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDescriptionExA" ( _
    ClassGuid AS GUID, _
    ClassDescription AS ASCIIZ, _
    BYVAL ClassDescriptionSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _    ' PVOID
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiCallClassInstaller LIB "SetupApi.dll" _
    ALIAS "SetupDiCallClassInstaller" ( _
    BYVAL InstallFunction AS DI_FUNCTION, _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL


'
' Default install handler for DIF_SELECTDEVICE
'
DECLARE FUNCTION SetupDiSelectDevice LIB "SetupApi.dll" _
    ALIAS "SetupDiSelectDevice" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL


'
' Default install handler for DIF_SELECTBESTCOMPATDRV
'
DECLARE FUNCTION SetupDiSelectBestCompatDrv LIB "SetupApi.dll" _
    ALIAS "SetupDiSelectBestCompatDrv" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL


'
' Default install handler for DIF_INSTALLDEVICE
'
DECLARE FUNCTION SetupDiInstallDevice LIB "SetupApi.dll" _
    ALIAS "SetupDiInstallDevice" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL


'
' Default install handler for DIF_INSTALLDEVICEFILES
'
DECLARE FUNCTION SetupDiInstallDriverFiles LIB "SetupApi.dll" _
    ALIAS "SetupDiInstallDriverFiles" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL


'
' Default install handler for DIF_REGISTER_COINSTALLERS
'
DECLARE FUNCTION SetupDiRegisterCoDeviceInstallers LIB "SetupApi.dll" _
    ALIAS "SetupDiRegisterCoDeviceInstallers" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL


'
' Default install handler for DIF_REMOVE
'
DECLARE FUNCTION SetupDiRemoveDevice LIB "SetupApi.dll" _
    ALIAS "SetupDiRemoveDevice" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL


'
' Default install handler for DIF_UNREMOVE
'
DECLARE FUNCTION SetupDiUnremoveDevice LIB "SetupApi.dll" _
    ALIAS "SetupDiUnremoveDevice" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL

#IF %SETUPAPI_VER >= %WIN32_WINNT_WS03

DECLARE FUNCTION SetupDiRestartDevices LIB "SetupApi.dll" _
    ALIAS "SetupDiRestartDevices" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WS03

'
' Default install handler for DIF_PROPERTYCHANGE
'
DECLARE FUNCTION SetupDiChangeState LIB "SetupApi.dll" _
    ALIAS "SetupDiChangeState" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL


' [does not appear to be exported]
'#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN
'
''
'' Default install handler for DIF_FINISHINSTALL_ACTION
''
'DECLARE FUNCTION SetupDiFinishInstallAction LIB "SetupApi.dll" _
'    ALIAS "SetupDiFinishInstallAction" ( _
'    BYVAL DeviceInfoSet AS HDEVINFO, _
'    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
'    ) AS LONG  ' BOOL
'
'#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN


DECLARE FUNCTION SetupDiInstallClassA LIB "SetupApi.dll" _
    ALIAS "SetupDiInstallClassA" ( _
    BYVAL hwndParent AS DWORD, _  ' HWND
    InfFileName AS ASCIIZ, _
    BYVAL Flags AS DWORD, _
    BYVAL FileQueue AS HSPFILEQ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiInstallClassW LIB "SetupApi.dll" _
    ALIAS "SetupDiInstallClassW" ( _
    BYVAL hwndParent AS DWORD, _  ' HWND
    InfFileName AS WSTRINGZ, _
    BYVAL Flags AS DWORD, _
    BYVAL FileQueue AS HSPFILEQ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiInstallClass LIB "SetupApi.dll" _
    ALIAS "SetupDiInstallClassW" ( _
    BYVAL hwndParent AS DWORD, _  ' HWND
    InfFileName AS WSTRINGZ, _
    BYVAL Flags AS DWORD, _
    BYVAL FileQueue AS HSPFILEQ _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiInstallClass LIB "SetupApi.dll" _
    ALIAS "SetupDiInstallClassA" ( _
    BYVAL hwndParent AS DWORD, _  ' HWND
    InfFileName AS ASCIIZ, _
    BYVAL Flags AS DWORD, _
    BYVAL FileQueue AS HSPFILEQ _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiInstallClassExA LIB "SetupApi.dll" _
    ALIAS "SetupDiInstallClassExA" ( _
    BYVAL hwndParent AS DWORD, _  ' HWND
    InfFileName AS ASCIIZ, _
    BYVAL Flags AS DWORD, _
    BYVAL FileQueue AS HSPFILEQ, _
    InterfaceClassGuid AS GUID, _
    BYVAL Reserved1 AS DWORD, _   ' PVOID
    BYVAL Reserved2 AS DWORD _    ' PVOID
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiInstallClassExW LIB "SetupApi.dll" _
    ALIAS "SetupDiInstallClassExW" ( _
    BYVAL hwndParent AS DWORD, _  ' HWND
    InfFileName AS WSTRINGZ, _
    BYVAL Flags AS DWORD, _
    BYVAL FileQueue AS HSPFILEQ, _
    InterfaceClassGuid AS GUID, _
    BYVAL Reserved1 AS DWORD, _   ' PVOID
    BYVAL Reserved2 AS DWORD _    ' PVOID
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiInstallClassEx LIB "SetupApi.dll" _
    ALIAS "SetupDiInstallClassExW" ( _
    BYVAL hwndParent AS DWORD, _  ' HWND
    InfFileName AS WSTRINGZ, _
    BYVAL Flags AS DWORD, _
    BYVAL FileQueue AS HSPFILEQ, _
    InterfaceClassGuid AS GUID, _
    BYVAL Reserved1 AS DWORD, _   ' PVOID
    BYVAL Reserved2 AS DWORD _    ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiInstallClassEx LIB "SetupApi.dll" _
    ALIAS "SetupDiInstallClassExA" ( _
    BYVAL hwndParent AS DWORD, _  ' HWND
    InfFileName AS ASCIIZ, _
    BYVAL Flags AS DWORD, _
    BYVAL FileQueue AS HSPFILEQ, _
    InterfaceClassGuid AS GUID, _
    BYVAL Reserved1 AS DWORD, _   ' PVOID
    BYVAL Reserved2 AS DWORD _    ' PVOID
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiOpenClassRegKey LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenClassRegKey" ( _
    ClassGuid AS GUID, _
    BYVAL samDesired AS REGSAM _
    ) AS DWORD  ' HKEY


'
' Flags for SetupDiOpenClassRegKeyEx
'
%DIOCR_INSTALLER = &H00000001    ' class installer registry branch
%DIOCR_INTERFACE = &H00000002    ' interface class registry branch

DECLARE FUNCTION SetupDiOpenClassRegKeyExA LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenClassRegKeyExA" ( _
    ClassGuid AS GUID, _
    BYVAL samDesired AS REGSAM, _
    BYVAL Flags AS DWORD, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS DWORD  ' HKEY

DECLARE FUNCTION SetupDiOpenClassRegKeyExW LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenClassRegKeyExW" ( _
    ClassGuid AS GUID, _
    BYVAL samDesired AS REGSAM, _
    BYVAL Flags AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS DWORD  ' HKEY

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiOpenClassRegKeyEx LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenClassRegKeyExW" ( _
    ClassGuid AS GUID, _
    BYVAL samDesired AS REGSAM, _
    BYVAL Flags AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS DWORD  ' HKEY
#ELSE
DECLARE FUNCTION SetupDiOpenClassRegKeyEx LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenClassRegKeyExA" ( _
    ClassGuid AS GUID, _
    BYVAL samDesired AS REGSAM, _
    BYVAL Flags AS DWORD, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS DWORD  ' HKEY
#ENDIF


DECLARE FUNCTION SetupDiCreateDeviceInterfaceRegKeyA LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInterfaceRegKeyA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL Reserved AS DWORD, _
    BYVAL samDesired AS REGSAM, _
    BYVAL InfHandle AS HINF, _
    InfSectionName AS ASCIIZ _
    ) AS DWORD  ' HKEY

DECLARE FUNCTION SetupDiCreateDeviceInterfaceRegKeyW LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInterfaceRegKeyW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL Reserved AS DWORD, _
    BYVAL samDesired AS REGSAM, _
    BYVAL InfHandle AS HINF, _
    InfSectionName AS WSTRINGZ _
    ) AS DWORD  ' HKEY

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiCreateDeviceInterfaceRegKey LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInterfaceRegKeyW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL Reserved AS DWORD, _
    BYVAL samDesired AS REGSAM, _
    BYVAL InfHandle AS HINF, _
    InfSectionName AS WSTRINGZ _
    ) AS DWORD  ' HKEY
#ELSE
DECLARE FUNCTION SetupDiCreateDeviceInterfaceRegKey LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInterfaceRegKeyA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL Reserved AS DWORD, _
    BYVAL samDesired AS REGSAM, _
    BYVAL InfHandle AS HINF, _
    InfSectionName AS ASCIIZ _
    ) AS DWORD  ' HKEY
#ENDIF

'
' Backward compatibility--do not use.
'
DECLARE FUNCTION SetupDiCreateInterfaceDeviceRegKeyA LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInterfaceRegKeyA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL Reserved AS DWORD, _
    BYVAL samDesired AS REGSAM, _
    BYVAL InfHandle AS HINF, _
    InfSectionName AS ASCIIZ _
    ) AS DWORD  ' HKEY

DECLARE FUNCTION SetupDiCreateInterfaceDeviceRegKeyW LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInterfaceRegKeyW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL Reserved AS DWORD, _
    BYVAL samDesired AS REGSAM, _
    BYVAL InfHandle AS HINF, _
    InfSectionName AS WSTRINGZ _
    ) AS DWORD  ' HKEY

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiCreateInterfaceDeviceRegKey LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInterfaceRegKeyW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL Reserved AS DWORD, _
    BYVAL samDesired AS REGSAM, _
    BYVAL InfHandle AS HINF, _
    InfSectionName AS WSTRINGZ _
    ) AS DWORD  ' HKEY
#ELSE
DECLARE FUNCTION SetupDiCreateInterfaceDeviceRegKey LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInterfaceRegKeyA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL Reserved AS DWORD, _
    BYVAL samDesired AS REGSAM, _
    BYVAL InfHandle AS HINF, _
    InfSectionName AS ASCIIZ _
    ) AS DWORD  ' HKEY
#ENDIF


DECLARE FUNCTION SetupDiOpenDeviceInterfaceRegKey LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenDeviceInterfaceRegKey" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL Reserved AS DWORD, _
    BYVAL samDesired AS REGSAM _
    ) AS DWORD  ' HKEY

'
' Backward compatibility--do not use.
'
DECLARE FUNCTION SetupDiOpenInterfaceDeviceRegKey LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenDeviceInterfaceRegKey" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL Reserved AS DWORD, _
    BYVAL samDesired AS REGSAM _
    ) AS DWORD  ' HKEY


DECLARE FUNCTION SetupDiDeleteDeviceInterfaceRegKey LIB "SetupApi.dll" _
    ALIAS "SetupDiDeleteDeviceInterfaceRegKey" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL Reserved AS DWORD _
    ) AS LONG  ' BOOL

'
' Backward compatibility--do not use.
'
DECLARE FUNCTION SetupDiDeleteInterfaceDeviceRegKey LIB "SetupApi.dll" _
    ALIAS "SetupDiDeleteDeviceInterfaceRegKey" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL Reserved AS DWORD _
    ) AS LONG  ' BOOL


'
' KeyType values for SetupDiCreateDevRegKey, SetupDiOpenDevRegKey, and
' SetupDiDeleteDevRegKey.
'
%DIREG_DEV     = &H00000001          ' Open/Create/Delete device key
%DIREG_DRV     = &H00000002          ' Open/Create/Delete driver key
%DIREG_BOTH    = &H00000004          ' Delete both driver and Device key

DECLARE FUNCTION SetupDiCreateDevRegKeyA LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDevRegKeyA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL Scope AS DWORD, _
    BYVAL HwProfile AS DWORD, _
    BYVAL KeyType AS DWORD, _
    BYVAL InfHandle AS HINF, _
    InfSectionName AS ASCIIZ _
    ) AS DWORD  ' HKEY

DECLARE FUNCTION SetupDiCreateDevRegKeyW LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDevRegKeyW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL Scope AS DWORD, _
    BYVAL HwProfile AS DWORD, _
    BYVAL KeyType AS DWORD, _
    BYVAL InfHandle AS HINF, _
    InfSectionName AS WSTRINGZ _
    ) AS DWORD  ' HKEY

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiCreateDevRegKey LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDevRegKeyW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL Scope AS DWORD, _
    BYVAL HwProfile AS DWORD, _
    BYVAL KeyType AS DWORD, _
    BYVAL InfHandle AS HINF, _
    InfSectionName AS WSTRINGZ _
    ) AS DWORD  ' HKEY
#ELSE
DECLARE FUNCTION SetupDiCreateDevRegKey LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDevRegKeyA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL Scope AS DWORD, _
    BYVAL HwProfile AS DWORD, _
    BYVAL KeyType AS DWORD, _
    BYVAL InfHandle AS HINF, _
    InfSectionName AS ASCIIZ _
    ) AS DWORD  ' HKEY
#ENDIF


DECLARE FUNCTION SetupDiOpenDevRegKey LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenDevRegKey" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL Scope AS DWORD, _
    BYVAL HwProfile AS DWORD, _
    BYVAL KeyType AS DWORD, _
    BYVAL samDesired AS REGSAM _
    ) AS DWORD  ' HKEY


DECLARE FUNCTION SetupDiDeleteDevRegKey LIB "SetupApi.dll" _
    ALIAS "SetupDiDeleteDevRegKey" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL Scope AS DWORD, _
    BYVAL HwProfile AS DWORD, _
    BYVAL KeyType AS DWORD _
    ) AS LONG  ' BOOL


DECLARE FUNCTION SetupDiGetHwProfileList LIB "SetupApi.dll" _
    ALIAS "SetupDiGetHwProfileList" ( _
    HwProfileList AS DWORD, _
    BYVAL HwProfileListSize AS DWORD, _
    RequiredSize AS DWORD, _
    CurrentlyActiveIndex AS DWORD _
    ) AS LONG  ' BOOL


DECLARE FUNCTION SetupDiGetHwProfileListExA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetHwProfileListExA" ( _
    HwProfileList AS DWORD, _
    BYVAL HwProfileListSize AS DWORD, _
    RequiredSize AS DWORD, _
    CurrentlyActiveIndex AS DWORD, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetHwProfileListExW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetHwProfileListExW" ( _
    HwProfileList AS DWORD, _
    BYVAL HwProfileListSize AS DWORD, _
    RequiredSize AS DWORD, _
    CurrentlyActiveIndex AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetHwProfileListEx LIB "SetupApi.dll" _
    ALIAS "SetupDiGetHwProfileListExW" ( _
    HwProfileList AS DWORD, _
    BYVAL HwProfileListSize AS DWORD, _
    RequiredSize AS DWORD, _
    CurrentlyActiveIndex AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetHwProfileListEx LIB "SetupApi.dll" _
    ALIAS "SetupDiGetHwProfileListExA" ( _
    HwProfileList AS DWORD, _
    BYVAL HwProfileListSize AS DWORD, _
    RequiredSize AS DWORD, _
    CurrentlyActiveIndex AS DWORD, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ENDIF

#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

DECLARE FUNCTION SetupDiGetDevicePropertyKeys LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDevicePropertyKeys" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL PropertyKeyArray AS DEVPROPKEY PTR, _
    BYVAL PropertyKeyCount AS DWORD, _
    RequiredPropertyKeyCount AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetDevicePropertyW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDevicePropertyW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DEVPROPTYPE PTR, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetDeviceProperty LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDevicePropertyW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DEVPROPTYPE PTR, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

DECLARE FUNCTION SetupDiSetDevicePropertyW LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDevicePropertyW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DEVPROPTYPE, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiSetDeviceProperty LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDevicePropertyW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DEVPROPTYPE, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

DECLARE FUNCTION SetupDiGetDeviceInterfacePropertyKeys LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInterfacePropertyKeys" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL PropertyKeyArray AS DEVPROPKEY PTR, _
    BYVAL PropertyKeyCount AS DWORD, _
    RequiredPropertyKeyCount AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetDeviceInterfacePropertyW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInterfacePropertyW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DEVPROPTYPE PTR, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetDeviceInterfaceProperty LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInterfacePropertyW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DEVPROPTYPE PTR, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

DECLARE FUNCTION SetupDiSetDeviceInterfacePropertyW LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDeviceInterfacePropertyW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DEVPROPTYPE, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiSetDeviceInterfaceProperty LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDeviceInterfacePropertyW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DEVPROPTYPE, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

'
' Flags for SetupDiGetClassPropertyKeys, SetupDiGetClassProperty, and
' SetupDiSetClassProperty.
'
%DICLASSPROP_INSTALLER = &H00000001    ' device setup class property
%DICLASSPROP_INTERFACE = &H00000002    ' device interface class property

DECLARE FUNCTION SetupDiGetClassPropertyKeys LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassPropertyKeys" ( _
    ClassGuid AS GUID, _
    BYVAL PropertyKeyArray AS DEVPROPKEY PTR, _
    BYVAL PropertyKeyCount AS DWORD, _
    RequiredPropertyKeyCount AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetClassPropertyKeysExW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassPropertyKeysExW" ( _
    ClassGuid AS GUID, _
    BYVAL PropertyKeyArray AS DEVPROPKEY PTR, _
    BYVAL PropertyKeyCount AS DWORD, _
    RequiredPropertyKeyCount AS DWORD, _
    BYVAL Flags AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetClassPropertyKeysEx LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassPropertyKeysExW" ( _
    ClassGuid AS GUID, _
    BYVAL PropertyKeyArray AS DEVPROPKEY PTR, _
    BYVAL PropertyKeyCount AS DWORD, _
    RequiredPropertyKeyCount AS DWORD, _
    BYVAL Flags AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ENDIF

DECLARE FUNCTION SetupDiGetClassPropertyW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassPropertyW" ( _
    ClassGuid AS GUID, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DEVPROPTYPE PTR, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetClassProperty LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassPropertyW" ( _
    ClassGuid AS GUID, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DEVPROPTYPE PTR, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

DECLARE FUNCTION SetupDiGetClassPropertyExW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassPropertyExW" ( _
    ClassGuid AS GUID, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DEVPROPTYPE PTR, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Flags AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetClassPropertyEx LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassPropertyExW" ( _
    ClassGuid AS GUID, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DEVPROPTYPE PTR, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Flags AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ENDIF

DECLARE FUNCTION SetupDiSetClassPropertyW LIB "SetupApi.dll" _
    ALIAS "SetupDiSetClassPropertyW" ( _
    ClassGuid AS GUID, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DEVPROPTYPE, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiSetClassProperty LIB "SetupApi.dll" _
    ALIAS "SetupDiSetClassPropertyW" ( _
    ClassGuid AS GUID, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DEVPROPTYPE, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

DECLARE FUNCTION SetupDiSetClassPropertyExW LIB "SetupApi.dll" _
    ALIAS "SetupDiSetClassPropertyExW" ( _
    ClassGuid AS GUID, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DEVPROPTYPE, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    BYVAL Flags AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiSetClassPropertyEx LIB "SetupApi.dll" _
    ALIAS "SetupDiSetClassPropertyExW" ( _
    ClassGuid AS GUID, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DEVPROPTYPE, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    BYVAL Flags AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ENDIF

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN


'
' Device registry property codes
' (Codes marked as read-only (R) may only be used for
' SetupDiGetDeviceRegistryProperty)
'
' These values should cover the same set of registry properties
' as defined by the CM_DRP codes in cfgmgr32.h.
'
' Note that SPDRP codes are zero based while CM_DRP codes are one based!
'
%SPDRP_DEVICEDESC                  = &H00000000  ' DeviceDesc (R/W)
%SPDRP_HARDWAREID                  = &H00000001  ' HardwareID (R/W)
%SPDRP_COMPATIBLEIDS               = &H00000002  ' CompatibleIDs (R/W)
%SPDRP_UNUSED0                     = &H00000003  ' unused
%SPDRP_SERVICE                     = &H00000004  ' Service (R/W)
%SPDRP_UNUSED1                     = &H00000005  ' unused
%SPDRP_UNUSED2                     = &H00000006  ' unused
%SPDRP_CLASS                       = &H00000007  ' Class (R--tied to ClassGUID)
%SPDRP_CLASSGUID                   = &H00000008  ' ClassGUID (R/W)
%SPDRP_DRIVER                      = &H00000009  ' Driver (R/W)
%SPDRP_CONFIGFLAGS                 = &H0000000A  ' ConfigFlags (R/W)
%SPDRP_MFG                         = &H0000000B  ' Mfg (R/W)
%SPDRP_FRIENDLYNAME                = &H0000000C  ' FriendlyName (R/W)
%SPDRP_LOCATION_INFORMATION        = &H0000000D  ' LocationInformation (R/W)
%SPDRP_PHYSICAL_DEVICE_OBJECT_NAME = &H0000000E  ' PhysicalDeviceObjectName (R)
%SPDRP_CAPABILITIES                = &H0000000F  ' Capabilities (R)
%SPDRP_UI_NUMBER                   = &H00000010  ' UiNumber (R)
%SPDRP_UPPERFILTERS                = &H00000011  ' UpperFilters (R/W)
%SPDRP_LOWERFILTERS                = &H00000012  ' LowerFilters (R/W)
%SPDRP_BUSTYPEGUID                 = &H00000013  ' BusTypeGUID (R)
%SPDRP_LEGACYBUSTYPE               = &H00000014  ' LegacyBusType (R)
%SPDRP_BUSNUMBER                   = &H00000015  ' BusNumber (R)
%SPDRP_ENUMERATOR_NAME             = &H00000016  ' Enumerator Name (R)
%SPDRP_SECURITY                    = &H00000017  ' Security (R/W, binary form)
%SPDRP_SECURITY_SDS                = &H00000018  ' Security (W, SDS form)
%SPDRP_DEVTYPE                     = &H00000019  ' Device Type (R/W)
%SPDRP_EXCLUSIVE                   = &H0000001A  ' Device is exclusive-access (R/W)
%SPDRP_CHARACTERISTICS             = &H0000001B  ' Device Characteristics (R/W)
%SPDRP_ADDRESS                     = &H0000001C  ' Device Address (R)
%SPDRP_UI_NUMBER_DESC_FORMAT       = &H0000001D  ' UiNumberDescFormat (R/W)
%SPDRP_DEVICE_POWER_DATA           = &H0000001E  ' Device Power Data (R)
%SPDRP_REMOVAL_POLICY              = &H0000001F  ' Removal Policy (R)
%SPDRP_REMOVAL_POLICY_HW_DEFAULT   = &H00000020  ' Hardware Removal Policy (R)
%SPDRP_REMOVAL_POLICY_OVERRIDE     = &H00000021  ' Removal Policy Override (RW)
%SPDRP_INSTALL_STATE               = &H00000022  ' Device Install State (R)
%SPDRP_LOCATION_PATHS              = &H00000023  ' Device Location Paths (R)
%SPDRP_BASE_CONTAINERID            = &H00000024  ' Base ContainerID (R)

%SPDRP_MAXIMUM_PROPERTY            = &H00000025  ' Upper bound on ordinals

'
' Class registry property codes
' (Codes marked as read-only (R) may only be used for
' SetupDiGetClassRegistryProperty)
'
' These values should cover the same set of registry properties
' as defined by the CM_CRP codes in cfgmgr32.h.
' they should also have a 1:1 correspondence with Device registers, where applicable
' but no overlap otherwise
'
%SPCRP_UPPERFILTERS         = &H00000011  ' UpperFilters (R/W)
%SPCRP_LOWERFILTERS         = &H00000012  ' LowerFilters (R/W)
%SPCRP_SECURITY             = &H00000017  ' Security (R/W, binary form)
%SPCRP_SECURITY_SDS         = &H00000018  ' Security (W, SDS form)
%SPCRP_DEVTYPE              = &H00000019  ' Device Type (R/W)
%SPCRP_EXCLUSIVE            = &H0000001A  ' Device is exclusive-access (R/W)
%SPCRP_CHARACTERISTICS      = &H0000001B  ' Device Characteristics (R/W)
%SPCRP_MAXIMUM_PROPERTY     = &H0000001C  ' Upper bound on ordinals


DECLARE FUNCTION SetupDiGetDeviceRegistryPropertyA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceRegistryPropertyA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL PROPERTY AS DWORD, _
    PropertyRegDataType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetDeviceRegistryPropertyW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceRegistryPropertyW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL PROPERTY AS DWORD, _
    PropertyRegDataType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetDeviceRegistryProperty LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceRegistryPropertyW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL PROPERTY AS DWORD, _
    PropertyRegDataType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDeviceRegistryProperty LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceRegistryPropertyA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL PROPERTY AS DWORD, _
    PropertyRegDataType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

DECLARE FUNCTION SetupDiGetClassRegistryPropertyA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassRegistryPropertyA" ( _
    ClassGuid AS GUID, _
    BYVAL PROPERTY AS DWORD, _
    PropertyRegDataType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetClassRegistryPropertyW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassRegistryPropertyW" ( _
    ClassGuid AS GUID, _
    BYVAL PROPERTY AS DWORD, _
    PropertyRegDataType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetClassRegistryProperty LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassRegistryPropertyW" ( _
    ClassGuid AS GUID, _
    BYVAL PROPERTY AS DWORD, _
    PropertyRegDataType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetClassRegistryProperty LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassRegistryPropertyA" ( _
    ClassGuid AS GUID, _
    BYVAL PROPERTY AS DWORD, _
    PropertyRegDataType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ENDIF

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

DECLARE FUNCTION SetupDiSetDeviceRegistryPropertyA LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDeviceRegistryPropertyA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL PROPERTY AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiSetDeviceRegistryPropertyW LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDeviceRegistryPropertyW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL PROPERTY AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiSetDeviceRegistryProperty LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDeviceRegistryPropertyW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL PROPERTY AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSetDeviceRegistryProperty LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDeviceRegistryPropertyA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL PROPERTY AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

DECLARE FUNCTION SetupDiSetClassRegistryPropertyA LIB "SetupApi.dll" _
    ALIAS "SetupDiSetClassRegistryPropertyA" ( _
    ClassGuid AS GUID, _
    BYVAL PROPERTY AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiSetClassRegistryPropertyW LIB "SetupApi.dll" _
    ALIAS "SetupDiSetClassRegistryPropertyW" ( _
    ClassGuid AS GUID, _
    BYVAL PROPERTY AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiSetClassRegistryProperty LIB "SetupApi.dll" _
    ALIAS "SetupDiSetClassRegistryPropertyW" ( _
    ClassGuid AS GUID, _
    BYVAL PROPERTY AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSetClassRegistryProperty LIB "SetupApi.dll" _
    ALIAS "SetupDiSetClassRegistryPropertyA" ( _
    ClassGuid AS GUID, _
    BYVAL PROPERTY AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ENDIF

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

DECLARE FUNCTION SetupDiGetDeviceInstallParamsA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInstallParamsA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DeviceInstallParams AS SP_DEVINSTALL_PARAMS_A PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetDeviceInstallParamsW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInstallParamsW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DeviceInstallParams AS SP_DEVINSTALL_PARAMS_W PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetDeviceInstallParams LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInstallParamsW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DeviceInstallParams AS SP_DEVINSTALL_PARAMS_W PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDeviceInstallParams LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInstallParamsA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DeviceInstallParams AS SP_DEVINSTALL_PARAMS_A PTR _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiGetClassInstallParamsA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassInstallParamsA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL ClassInstallParams AS SP_CLASSINSTALL_HEADER PTR, _
    BYVAL ClassInstallParamsSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetClassInstallParamsW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassInstallParamsW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL ClassInstallParams AS SP_CLASSINSTALL_HEADER PTR, _
    BYVAL ClassInstallParamsSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetClassInstallParams LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassInstallParamsW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL ClassInstallParams AS SP_CLASSINSTALL_HEADER PTR, _
    BYVAL ClassInstallParamsSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetClassInstallParams LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassInstallParamsA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL ClassInstallParams AS SP_CLASSINSTALL_HEADER PTR, _
    BYVAL ClassInstallParamsSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiSetDeviceInstallParamsA LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDeviceInstallParamsA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DeviceInstallParams AS SP_DEVINSTALL_PARAMS_A PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiSetDeviceInstallParamsW LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDeviceInstallParamsW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DeviceInstallParams AS SP_DEVINSTALL_PARAMS_W PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiSetDeviceInstallParams LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDeviceInstallParamsW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DeviceInstallParams AS SP_DEVINSTALL_PARAMS_W PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSetDeviceInstallParams LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDeviceInstallParamsA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DeviceInstallParams AS SP_DEVINSTALL_PARAMS_A PTR _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiSetClassInstallParamsA LIB "SetupApi.dll" _
    ALIAS "SetupDiSetClassInstallParamsA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL ClassInstallParams AS SP_CLASSINSTALL_HEADER PTR, _
    BYVAL ClassInstallParamsSize AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiSetClassInstallParamsW LIB "SetupApi.dll" _
    ALIAS "SetupDiSetClassInstallParamsW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL ClassInstallParams AS SP_CLASSINSTALL_HEADER PTR, _
    BYVAL ClassInstallParamsSize AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiSetClassInstallParams LIB "SetupApi.dll" _
    ALIAS "SetupDiSetClassInstallParamsW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL ClassInstallParams AS SP_CLASSINSTALL_HEADER PTR, _
    BYVAL ClassInstallParamsSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSetClassInstallParams LIB "SetupApi.dll" _
    ALIAS "SetupDiSetClassInstallParamsA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL ClassInstallParams AS SP_CLASSINSTALL_HEADER PTR, _
    BYVAL ClassInstallParamsSize AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiGetDriverInstallParamsA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDriverInstallParamsA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_A PTR, _
    BYVAL DriverInstallParams AS SP_DRVINSTALL_PARAMS PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetDriverInstallParamsW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDriverInstallParamsW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_W PTR, _
    BYVAL DriverInstallParams AS SP_DRVINSTALL_PARAMS PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetDriverInstallParams LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDriverInstallParamsW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_W PTR, _
    BYVAL DriverInstallParams AS SP_DRVINSTALL_PARAMS PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDriverInstallParams LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDriverInstallParamsA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_A PTR, _
    BYVAL DriverInstallParams AS SP_DRVINSTALL_PARAMS PTR _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiSetDriverInstallParamsA LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDriverInstallParamsA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_A PTR, _
    BYVAL DriverInstallParams AS SP_DRVINSTALL_PARAMS PTR _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiSetDriverInstallParamsW LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDriverInstallParamsW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_W PTR, _
    BYVAL DriverInstallParams AS SP_DRVINSTALL_PARAMS PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiSetDriverInstallParams LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDriverInstallParamsW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_W PTR, _
    BYVAL DriverInstallParams AS SP_DRVINSTALL_PARAMS PTR _
    ) AS LONG  ' BOOL

#ELSE
DECLARE FUNCTION SetupDiSetDriverInstallParams LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDriverInstallParamsA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_A PTR, _
    BYVAL DriverInstallParams AS SP_DRVINSTALL_PARAMS PTR _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiLoadClassIcon LIB "SetupApi.dll" _
    ALIAS "SetupDiLoadClassIcon" ( _
    ClassGuid AS GUID, _
    LargeIcon AS DWORD, _  ' HICON
    MiniIconIndex AS LONG _
    ) AS LONG  ' BOOL

#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

DECLARE FUNCTION SetupDiLoadDeviceIcon LIB "SetupApi.dll" _
    ALIAS "SetupDiLoadDeviceIcon" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL cxIcon AS DWORD, _
    BYVAL cyIcon AS DWORD, _
    BYVAL Flags AS DWORD, _
    hIcon AS DWORD _  ' HICON
    ) AS LONG  ' BOOL

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN


'
' Flags controlling the drawing of mini-icons
'
%DMI_MASK    = &H00000001
%DMI_BKCOLOR = &H00000002
%DMI_USERECT = &H00000004

DECLARE FUNCTION SetupDiDrawMiniIcon LIB "SetupApi.dll" _
    ALIAS "SetupDiDrawMiniIcon" ( _
    BYVAL hdc AS DWORD, _  ' HDC
    BYVAL rc AS RECT, _
    BYVAL MiniIconIndex AS LONG, _
    BYVAL Flags AS DWORD _
    ) AS LONG


DECLARE FUNCTION SetupDiGetClassBitmapIndex LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassBitmapIndex" ( _
    ClassGuid AS GUID, _
    MiniIconIndex AS LONG _
    ) AS LONG  ' BOOL


DECLARE FUNCTION SetupDiGetClassImageList LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassImageList" ( _
    BYVAL ClassImageListData AS SP_CLASSIMAGELIST_DATA PTR _
    ) AS LONG  ' BOOL


DECLARE FUNCTION SetupDiGetClassImageListExA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassImageListExA" ( _
    BYVAL ClassImageListData AS SP_CLASSIMAGELIST_DATA PTR, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetClassImageListExW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassImageListExW" ( _
    BYVAL ClassImageListData AS SP_CLASSIMAGELIST_DATA PTR, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetClassImageListEx LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassImageListExW" ( _
    BYVAL ClassImageListData AS SP_CLASSIMAGELIST_DATA PTR, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetClassImageListEx LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassImageListExA" ( _
    BYVAL ClassImageListData AS SP_CLASSIMAGELIST_DATA PTR, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiGetClassImageIndex LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassImageIndex" ( _
    BYVAL ClassImageListData AS SP_CLASSIMAGELIST_DATA PTR, _
    ClassGuid AS GUID, _
    ImageIndex AS LONG _
    ) AS LONG  ' BOOL


DECLARE FUNCTION SetupDiDestroyClassImageList LIB "SetupApi.dll" _
    ALIAS "SetupDiDestroyClassImageList" ( _
    BYVAL ClassImageListData AS SP_CLASSIMAGELIST_DATA PTR _
    ) AS LONG  ' BOOL


'
' PropertySheetType values for the SetupDiGetClassDevPropertySheets API
'
%DIGCDP_FLAG_BASIC           = &H00000001
%DIGCDP_FLAG_ADVANCED        = &H00000002

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

%DIGCDP_FLAG_REMOTE_BASIC    = &H00000003  ' not presently implemented
%DIGCDP_FLAG_REMOTE_ADVANCED = &H00000004

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

DECLARE FUNCTION SetupDiGetClassDevPropertySheetsA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDevPropertySheetsA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    PropertySheetHeader AS PROPSHEETHEADERA, _
    BYVAL PropertySheetHeaderPageListSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL PropertySheetType AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetClassDevPropertySheetsW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDevPropertySheetsW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    PropertySheetHeader AS PROPSHEETHEADERW, _
    BYVAL PropertySheetHeaderPageListSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL PropertySheetType AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetClassDevPropertySheets LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDevPropertySheetsW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    PropertySheetHeader AS PROPSHEETHEADERW, _
    BYVAL PropertySheetHeaderPageListSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL PropertySheetType AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetClassDevPropertySheets LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDevPropertySheetsA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    PropertySheetHeader AS PROPSHEETHEADERA, _
    BYVAL PropertySheetHeaderPageListSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL PropertySheetType AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


'
' Define ICON IDs publicly exposed from setupapi.
'
%IDI_RESOURCEFIRST          = 159
%IDI_RESOURCE               = 159
%IDI_RESOURCELAST           = 161
%IDI_RESOURCEOVERLAYFIRST   = 161
%IDI_RESOURCEOVERLAYLAST    = 161
%IDI_CONFLICT               = 161

%IDI_CLASSICON_OVERLAYFIRST = 500
%IDI_CLASSICON_OVERLAYLAST  = 502
%IDI_PROBLEM_OVL            = 500
%IDI_DISABLED_OVL           = 501
%IDI_FORCED_OVL             = 502


DECLARE FUNCTION SetupDiAskForOEMDisk LIB "SetupApi.dll" _
    ALIAS "SetupDiAskForOEMDisk" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL


DECLARE FUNCTION SetupDiSelectOEMDrv LIB "SetupApi.dll" _
    ALIAS "SetupDiSelectOEMDrv" ( _
    BYVAL hwndParent AS DWORD, _  ' HWND
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL


DECLARE FUNCTION SetupDiClassNameFromGuidA LIB "SetupApi.dll" _
    ALIAS "SetupDiClassNameFromGuidA" ( _
    ClassGuid AS GUID, _
    ClassName AS ASCIIZ, _
    BYVAL ClassNameSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiClassNameFromGuidW LIB "SetupApi.dll" _
    ALIAS "SetupDiClassNameFromGuidW" ( _
    ClassGuid AS GUID, _
    ClassName AS WSTRINGZ, _
    BYVAL ClassNameSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiClassNameFromGuid LIB "SetupApi.dll" _
    ALIAS "SetupDiClassNameFromGuidW" ( _
    ClassGuid AS GUID, _
    ClassName AS WSTRINGZ, _
    BYVAL ClassNameSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiClassNameFromGuid LIB "SetupApi.dll" _
    ALIAS "SetupDiClassNameFromGuidA" ( _
    ClassGuid AS GUID, _
    ClassName AS ASCIIZ, _
    BYVAL ClassNameSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiClassNameFromGuidExA LIB "SetupApi.dll" _
    ALIAS "SetupDiClassNameFromGuidExA" ( _
    ClassGuid AS GUID, _
    ClassName AS ASCIIZ, _
    BYVAL ClassNameSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiClassNameFromGuidExW LIB "SetupApi.dll" _
    ALIAS "SetupDiClassNameFromGuidExW" ( _
    ClassGuid AS GUID, _
    ClassName AS WSTRINGZ, _
    BYVAL ClassNameSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiClassNameFromGuidEx LIB "SetupApi.dll" _
    ALIAS "SetupDiClassNameFromGuidExW" ( _
    ClassGuid AS GUID, _
    ClassName AS WSTRINGZ, _
    BYVAL ClassNameSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiClassNameFromGuidEx LIB "SetupApi.dll" _
    ALIAS "SetupDiClassNameFromGuidExA" ( _
    ClassGuid AS GUID, _
    ClassName AS ASCIIZ, _
    BYVAL ClassNameSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiClassGuidsFromNameA LIB "SetupApi.dll" _
    ALIAS "SetupDiClassGuidsFromNameA" ( _
    ClassName AS ASCIIZ, _
    ClassGuidList AS GUID, _
    BYVAL ClassGuidListSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiClassGuidsFromNameW LIB "SetupApi.dll" _
    ALIAS "SetupDiClassGuidsFromNameW" ( _
    ClassName AS WSTRINGZ, _
    ClassGuidList AS GUID, _
    BYVAL ClassGuidListSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiClassGuidsFromName LIB "SetupApi.dll" _
    ALIAS "SetupDiClassGuidsFromNameW" ( _
    ClassName AS WSTRINGZ, _
    ClassGuidList AS GUID, _
    BYVAL ClassGuidListSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiClassGuidsFromName LIB "SetupApi.dll" _
    ALIAS "SetupDiClassGuidsFromNameA" ( _
    ClassName AS ASCIIZ, _
    ClassGuidList AS GUID, _
    BYVAL ClassGuidListSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiClassGuidsFromNameExA LIB "SetupApi.dll" _
    ALIAS "SetupDiClassGuidsFromNameExA" ( _
    ClassName AS ASCIIZ, _
    ClassGuidList AS GUID, _
    BYVAL ClassGuidListSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiClassGuidsFromNameExW LIB "SetupApi.dll" _
    ALIAS "SetupDiClassGuidsFromNameExW" ( _
    ClassName AS WSTRINGZ, _
    ClassGuidList AS GUID, _
    BYVAL ClassGuidListSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiClassGuidsFromNameEx LIB "SetupApi.dll" _
    ALIAS "SetupDiClassGuidsFromNameExW" ( _
    ClassName AS WSTRINGZ, _
    ClassGuidList AS GUID, _
    BYVAL ClassGuidListSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiClassGuidsFromNameEx LIB "SetupApi.dll" _
    ALIAS "SetupDiClassGuidsFromNameExA" ( _
    ClassName AS ASCIIZ, _
    ClassGuidList AS GUID, _
    BYVAL ClassGuidListSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiGetHwProfileFriendlyNameA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetHwProfileFriendlyNameA" ( _
    BYVAL HwProfile AS DWORD, _
    FriendlyName AS ASCIIZ, _
    BYVAL FriendlyNameSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetHwProfileFriendlyNameW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetHwProfileFriendlyNameW" ( _
    BYVAL HwProfile AS DWORD, _
    FriendlyName AS WSTRINGZ, _
    BYVAL FriendlyNameSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetHwProfileFriendlyName LIB "SetupApi.dll" _
    ALIAS "SetupDiGetHwProfileFriendlyNameW" ( _
    BYVAL HwProfile AS DWORD, _
    FriendlyName AS WSTRINGZ, _
    BYVAL FriendlyNameSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetHwProfileFriendlyName LIB "SetupApi.dll" _
    ALIAS "SetupDiGetHwProfileFriendlyNameA" ( _
    BYVAL HwProfile AS DWORD, _
    FriendlyName AS ASCIIZ, _
    BYVAL FriendlyNameSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


DECLARE FUNCTION SetupDiGetHwProfileFriendlyNameExA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetHwProfileFriendlyNameExA" ( _
    BYVAL HwProfile AS DWORD, _
    FriendlyName AS ASCIIZ, _
    BYVAL FriendlyNameSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetHwProfileFriendlyNameExW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetHwProfileFriendlyNameExW" ( _
    BYVAL HwProfile AS DWORD, _
    FriendlyName AS WSTRINGZ, _
    BYVAL FriendlyNameSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetHwProfileFriendlyNameEx LIB "SetupApi.dll" _
    ALIAS "SetupDiGetHwProfileFriendlyNameExW" ( _
    BYVAL HwProfile AS DWORD, _
    FriendlyName AS WSTRINGZ, _
    BYVAL FriendlyNameSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetHwProfileFriendlyNameEx LIB "SetupApi.dll" _
    ALIAS "SetupDiGetHwProfileFriendlyNameExA" ( _
    BYVAL HwProfile AS DWORD, _
    FriendlyName AS ASCIIZ, _
    BYVAL FriendlyNameSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ENDIF


'
' PageType values for SetupDiGetWizardPage API
'
%SPWPT_SELECTDEVICE    = &H00000001

'
' Flags for SetupDiGetWizardPage API
'
%SPWP_USE_DEVINFO_DATA = &H00000001

DECLARE FUNCTION SetupDiGetWizardPage LIB "SetupApi.dll" _
    ALIAS "SetupDiGetWizardPage" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL InstallWizardData AS SP_INSTALLWIZARD_DATA PTR, _
    BYVAL PageType AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS DWORD  ' HPROPSHEETPAGE


DECLARE FUNCTION SetupDiGetSelectedDevice LIB "SetupApi.dll" _
    ALIAS "SetupDiGetSelectedDevice" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL


DECLARE FUNCTION SetupDiSetSelectedDevice LIB "SetupApi.dll" _
    ALIAS "SetupDiSetSelectedDevice" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL


#IF %SETUPAPI_VER >= %WIN32_WINNT_WS03

DECLARE FUNCTION SetupDiGetActualModelsSectionA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetActualModelsSectionA" ( _
    Context AS INFCONTEXT, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    InfSectionWithExt AS ASCIIZ, _
    BYVAL InfSectionWithExtSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetActualModelsSectionW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetActualModelsSectionW" ( _
    Context AS INFCONTEXT, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    InfSectionWithExt AS WSTRINGZ, _
    BYVAL InfSectionWithExtSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetActualModelsSection LIB "SetupApi.dll" _
    ALIAS "SetupDiGetActualModelsSectionW" ( _
    Context AS INFCONTEXT, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    InfSectionWithExt AS WSTRINGZ, _
    BYVAL InfSectionWithExtSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetActualModelsSection LIB "SetupApi.dll" _
    ALIAS "SetupDiGetActualModelsSectionA" ( _
    Context AS INFCONTEXT, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    InfSectionWithExt AS ASCIIZ, _
    BYVAL InfSectionWithExtSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ENDIF

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WS03


DECLARE FUNCTION SetupDiGetActualSectionToInstallA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetActualSectionToInstallA" ( _
    BYVAL InfHandle AS HINF, _
    InfSectionName AS ASCIIZ, _
    InfSectionWithExt AS ASCIIZ, _
    BYVAL InfSectionWithExtSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Extension AS DWORD _   ' PSTR *
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetActualSectionToInstallW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetActualSectionToInstallW" ( _
    BYVAL InfHandle AS HINF, _
    InfSectionName AS WSTRINGZ, _
    InfSectionWithExt AS WSTRINGZ, _
    BYVAL InfSectionWithExtSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Extension AS DWORD _   ' PWSTR *
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetActualSectionToInstall LIB "SetupApi.dll" _
    ALIAS "SetupDiGetActualSectionToInstallW" ( _
    BYVAL InfHandle AS HINF, _
    InfSectionName AS WSTRINGZ, _
    InfSectionWithExt AS WSTRINGZ, _
    BYVAL InfSectionWithExtSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Extension AS DWORD _   ' PWSTR *
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetActualSectionToInstall LIB "SetupApi.dll" _
    ALIAS "SetupDiGetActualSectionToInstallA" ( _
    BYVAL InfHandle AS HINF, _
    InfSectionName AS ASCIIZ, _
    InfSectionWithExt AS ASCIIZ, _
    BYVAL InfSectionWithExtSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Extension AS DWORD _   ' PSTR *
    ) AS LONG  ' BOOL
#ENDIF


#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

DECLARE FUNCTION SetupDiGetActualSectionToInstallExA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetActualSectionToInstallExA" ( _
    BYVAL InfHandle AS HINF, _
    InfSectionName AS ASCIIZ, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    InfSectionWithExt AS ASCIIZ, _
    BYVAL InfSectionWithExtSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Extension AS DWORD, _  ' PSTR *
    BYVAL Reserved AS DWORD _    ' PVOID
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetActualSectionToInstallExW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetActualSectionToInstallExW" ( _
    BYVAL InfHandle AS HINF, _
    InfSectionName AS WSTRINGZ, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    InfSectionWithExt AS WSTRINGZ, _
    BYVAL InfSectionWithExtSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Extension AS DWORD, _   ' PWSTR *
    BYVAL Reserved AS DWORD _     ' PVOID
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetActualSectionToInstallEx LIB "SetupApi.dll" _
    ALIAS "SetupDiGetActualSectionToInstallExW" ( _
    BYVAL InfHandle AS HINF, _
    InfSectionName AS WSTRINGZ, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    InfSectionWithExt AS WSTRINGZ, _
    BYVAL InfSectionWithExtSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Extension AS DWORD, _   ' PWSTR *
    BYVAL Reserved AS DWORD _     ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetActualSectionToInstallEx LIB "SetupApi.dll" _
    ALIAS "SetupDiGetActualSectionToInstallExA" ( _
    BYVAL InfHandle AS HINF, _
    InfSectionName AS ASCIIZ, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    InfSectionWithExt AS ASCIIZ, _
    BYVAL InfSectionWithExtSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Extension AS DWORD, _  ' PSTR *
    BYVAL Reserved AS DWORD _    ' PVOID
    ) AS LONG  ' BOOL
#ENDIF

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP


#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

'
' SetupEnumInfSections is for low-level parsing of an INF
'
DECLARE FUNCTION SetupEnumInfSectionsA LIB "SetupApi.dll" _
    ALIAS "SetupEnumInfSectionsA" ( _
    BYVAL InfHandle AS HINF, _
    BYVAL Index AS DWORD, _
    Buffer AS ASCIIZ, _
    BYVAL SIZE AS DWORD, _
    SizeNeeded AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupEnumInfSectionsW LIB "SetupApi.dll" _
    ALIAS "SetupEnumInfSectionsW" ( _
    BYVAL InfHandle AS HINF, _
    BYVAL Index AS DWORD, _
    Buffer AS WSTRINGZ, _
    BYVAL SIZE AS DWORD, _
    SizeNeeded AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupEnumInfSections LIB "SetupApi.dll" _
    ALIAS "SetupEnumInfSectionsW" ( _
    BYVAL InfHandle AS HINF, _
    BYVAL Index AS DWORD, _
    Buffer AS WSTRINGZ, _
    BYVAL SIZE AS DWORD, _
    SizeNeeded AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupEnumInfSections LIB "SetupApi.dll" _
    ALIAS "SetupEnumInfSectionsA" ( _
    BYVAL InfHandle AS HINF, _
    BYVAL Index AS DWORD, _
    Buffer AS ASCIIZ, _
    BYVAL SIZE AS DWORD, _
    SizeNeeded AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

TYPE SP_INF_SIGNER_INFO_V1_A
    cbSize               AS DWORD
    CatalogFile          AS ASCIIZ * %MAX_PATH
    DigitalSigner        AS ASCIIZ * %MAX_PATH
    DigitalSignerVersion AS ASCIIZ * %MAX_PATH
END TYPE

TYPE SP_INF_SIGNER_INFO_V1_W
    cbSize               AS DWORD
    CatalogFile          AS WSTRINGZ * %MAX_PATH
    DigitalSigner        AS WSTRINGZ * %MAX_PATH
    DigitalSignerVersion AS WSTRINGZ * %MAX_PATH
END TYPE

#IF %DEF(%UNICODE)
TYPE SP_INF_SIGNER_INFO_V1
    SP_INF_SIGNER_INFO_V1_W
END TYPE
#ELSE
TYPE SP_INF_SIGNER_INFO_V1
    SP_INF_SIGNER_INFO_V1_A
END TYPE
#ENDIF

#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

TYPE SP_INF_SIGNER_INFO_V2_A
    cbSize               AS DWORD
    CatalogFile          AS ASCIIZ * %MAX_PATH
    DigitalSigner        AS ASCIIZ * %MAX_PATH
    DigitalSignerVersion AS ASCIIZ * %MAX_PATH
    SignerScore          AS DWORD
END TYPE

TYPE SP_INF_SIGNER_INFO_V2_W
    cbSize               AS DWORD
    CatalogFile          AS WSTRINGZ * %MAX_PATH
    DigitalSigner        AS WSTRINGZ * %MAX_PATH
    DigitalSignerVersion AS WSTRINGZ * %MAX_PATH
    SignerScore          AS DWORD
END TYPE

#IF %DEF(%UNICODE )
TYPE SP_INF_SIGNER_INFO_V2
    SP_INF_SIGNER_INFO_V2_W
END TYPE
#ELSE
TYPE SP_INF_SIGNER_INFO_V2
    SP_INF_SIGNER_INFO_V2_A
END TYPE
#ENDIF

'
' Driver signer scores (high order bit of the signing byte means unsigned)
'
%SIGNERSCORE_UNKNOWN       = &HFF000000???
%SIGNERSCORE_W9X_SUSPECT   = &HC0000000???
%SIGNERSCORE_UNSIGNED      = &H80000000???
%SIGNERSCORE_AUTHENTICODE  = &H0F000000
%SIGNERSCORE_WHQL          = &H0D000005  ' base WHQL.
%SIGNERSCORE_UNCLASSIFIED  = &H0D000004  ' UNCLASSIFIED == INBOX == STANDARD == PREMIUM when the SIGNERSCORE_MASK
%SIGNERSCORE_INBOX         = &H0D000003  ' filter is applied.
%SIGNERSCORE_LOGO_STANDARD = &H0D000002
%SIGNERSCORE_LOGO_PREMIUM  = &H0D000001

%SIGNERSCORE_MASK          = &HFF000000??? ' Mask out all but the upper BYTE which contains the ranking signer information
%SIGNERSCORE_SIGNED_MASK   = &HF0000000??? ' Mask out only the upper nibble, which tells us if the package is signed or not.

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

#IF %DEF(%USE_SP_INF_SIGNER_INFO_V1) OR (%SETUPAPI_VER < %WIN32_WINNT_LONGHORN)  ' use version 1 signer info structure

TYPE SP_INF_SIGNER_INFO_A
    SP_INF_SIGNER_INFO_V1_A
END TYPE
TYPE SP_INF_SIGNER_INFO_W
    SP_INF_SIGNER_INFO_V1_W
END TYPE
TYPE SP_INF_SIGNER_INFO
    SP_INF_SIGNER_INFO_V1
END TYPE

#ELSE                       ' use version 2 signer info structure

TYPE SP_INF_SIGNER_INFO_A
    SP_INF_SIGNER_INFO_V2_A
END TYPE
TYPE SP_INF_SIGNER_INFO_W
    SP_INF_SIGNER_INFO_V2_W
END TYPE
TYPE SP_INF_SIGNER_INFO
    SP_INF_SIGNER_INFO_V2
END TYPE

#ENDIF  ' use current version of signer info structure


DECLARE FUNCTION SetupVerifyInfFileA LIB "SetupApi.dll" _
    ALIAS "SetupVerifyInfFileA" ( _
    InfName AS ASCIIZ, _
    BYVAL AltPlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    BYVAL InfSignerInfo AS SP_INF_SIGNER_INFO_A PTR, _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupVerifyInfFileW LIB "SetupApi.dll" _
    ALIAS "SetupVerifyInfFileW" ( _
    InfName AS WSTRINGZ, _
    BYVAL AltPlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    BYVAL InfSignerInfo AS SP_INF_SIGNER_INFO_W PTR _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupVerifyInfFileW LIB "SetupApi.dll" _
    ALIAS "SetupVerifyInfFileW" ( _
    InfName AS WSTRINGZ, _
    BYVAL AltPlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    BYVAL InfSignerInfo AS SP_INF_SIGNER_INFO_W PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupVerifyInfFile LIB "SetupApi.dll" _
    ALIAS "SetupVerifyInfFileA" ( _
    InfName AS ASCIIZ, _
    BYVAL AltPlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    BYVAL InfSignerInfo AS SP_INF_SIGNER_INFO_A PTR, _
    ) AS LONG  ' BOOL
#ENDIF

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

'
' Flags for use by SetupDiGetCustomDeviceProperty
'
%DICUSTOMDEVPROP_MERGE_MULTISZ  = &H00000001

DECLARE FUNCTION SetupDiGetCustomDevicePropertyA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetCustomDevicePropertyA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    CustomPropertyName AS ASCIIZ, _
    BYVAL Flags AS DWORD, _
    PropertyRegDataType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupDiGetCustomDevicePropertyW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetCustomDevicePropertyW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    CustomPropertyName AS WSTRINGZ, _
    BYVAL Flags AS DWORD, _
    PropertyRegDataType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupDiGetCustomDeviceProperty LIB "SetupApi.dll" _
    ALIAS "SetupDiGetCustomDevicePropertyW" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    CustomPropertyName AS WSTRINGZ, _
    BYVAL Flags AS DWORD, _
    PropertyRegDataType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetCustomDeviceProperty LIB "SetupApi.dll" _
    ALIAS "SetupDiGetCustomDevicePropertyA" ( _
    BYVAL DeviceInfoSet AS HDEVINFO, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    CustomPropertyName AS ASCIIZ, _
    BYVAL Flags AS DWORD, _
    PropertyRegDataType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP


#IF %SETUPAPI_VER >= %WIN32_WINNT_WS03

'
' To configure WMI security for downlevel platforms where the [DDInstall.WMI]
' section isn't natively supported by setupapi, a redistributable co-installer
' is supplied in the DDK for use on those platforms.
'

'
' Flags for use by SetupConfigureWmiFromInfSection
'
%SCWMI_CLOBBER_SECURITY = &H00000001

DECLARE FUNCTION SetupConfigureWmiFromInfSectionA LIB "SetupApi.dll" _
    ALIAS "SetupConfigureWmiFromInfSectionA" ( _
    BYVAL InfHandle AS HINF, _
    SectionName AS ASCIIZ, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION SetupConfigureWmiFromInfSectionW LIB "SetupApi.dll" _
    ALIAS "SetupConfigureWmiFromInfSectionW" ( _
    BYVAL InfHandle AS HINF, _
    SectionName AS WSTRINGZ, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetupConfigureWmiFromInfSection LIB "SetupApi.dll" _
    ALIAS "SetupConfigureWmiFromInfSectionW" ( _
    BYVAL InfHandle AS HINF, _
    SectionName AS WSTRINGZ, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupConfigureWmiFromInfSection LIB "SetupApi.dll" _
    ALIAS "SetupConfigureWmiFromInfSectionA" ( _
    BYVAL InfHandle AS HINF, _
    SectionName AS ASCIIZ, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL
#ENDIF


#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WS03
