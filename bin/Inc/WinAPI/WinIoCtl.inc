'------------------------------------------------------------------------------
'
'  WinIOCtl.inc - The 32-Bit Windows Device I/O control codes.
'
'  Copyright (c) 2005-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from winioctl.h Build Version 0015 of 14 Jul 2009
'------------------------------------------------------------------------------


#INCLUDE THIS ONCE

%WINIOCTL_INC = 1

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "WTypes.inc"


'
' Device interface class GUIDs.
'
' need these GUIDs outside conditional includes so that user can
'   #INCLUDE "winioctl.inc" in precompiled header
'   #INCLUDE "initguid.inc" in a single source file
'   #INCLUDE "winioctl.inc" in that source file a second time to instantiate the GUIDs
'
#IF %DEF(%DEFINE_GUID)

$GUID_DEVINTERFACE_DISK                   = GUID$("{53F56307-B6BF-11D0-94F2-00A0C91EFB8B}"
$GUID_DEVINTERFACE_CDROM                  = GUID$("{53F56308-B6BF-11D0-94F2-00A0C91EFB8B}"
$GUID_DEVINTERFACE_PARTITION              = GUID$("{53F5630A-B6BF-11D0-94F2-00A0C91EFB8B}"
$GUID_DEVINTERFACE_TAPE                   = GUID$("{53F5630B-B6BF-11D0-94F2-00A0C91EFB8B}"
$GUID_DEVINTERFACE_WRITEONCEDISK          = GUID$("{53F5630C-B6BF-11D0-94F2-00A0C91EFB8B}"
$GUID_DEVINTERFACE_VOLUME                 = GUID$("{53F5630D-B6BF-11D0-94F2-00A0C91EFB8B}"
$GUID_DEVINTERFACE_MEDIUMCHANGER          = GUID$("{53F56310-B6BF-11D0-94F2-00A0C91EFB8B}"
$GUID_DEVINTERFACE_FLOPPY                 = GUID$("{53F56311-B6BF-11D0-94F2-00A0C91EFB8B}"
$GUID_DEVINTERFACE_CDCHANGER              = GUID$("{53F56312-B6BF-11D0-94F2-00A0C91EFB8B}"
$GUID_DEVINTERFACE_STORAGEPORT            = GUID$("{2ACCFE60-C130-11D2-B082-00A0C91EFB8B}"
$GUID_DEVINTERFACE_COMPORT                = GUID$("{86E0D1E0-8089-11D0-9CE4-08003E301F73}"
$GUID_DEVINTERFACE_SERENUM_BUS_ENUMERATOR = GUID$("{4D36E978-E325-11CE-BFC1-08002BE10318}"

'
' Obsolete device interface class GUID names.
' (use of above GUID_DEVINTERFACE_* names is recommended).
'
$DiskClassGuid               = $GUID_DEVINTERFACE_DISK
$CdRomClassGuid              = $GUID_DEVINTERFACE_CDROM
$PartitionClassGuid          = $GUID_DEVINTERFACE_PARTITION
$TapeClassGuid               = $GUID_DEVINTERFACE_TAPE
$WriteOnceDiskClassGuid      = $GUID_DEVINTERFACE_WRITEONCEDISK
$VolumeClassGuid             = $GUID_DEVINTERFACE_VOLUME
$MediumChangerClassGuid      = $GUID_DEVINTERFACE_MEDIUMCHANGER
$FloppyClassGuid             = $GUID_DEVINTERFACE_FLOPPY
$CdChangerClassGuid          = $GUID_DEVINTERFACE_CDCHANGER
$StoragePortClassGuid        = $GUID_DEVINTERFACE_STORAGEPORT
$GUID_CLASS_COMPORT          = $GUID_DEVINTERFACE_COMPORT
$GUID_SERENUM_BUS_ENUMERATOR = $GUID_DEVINTERFACE_SERENUM_BUS_ENUMERATOR

#ENDIF  ' #IF %DEF(%DEFINE_GUID)



#IF NOT %DEF(%DEVIOCTL)

%DEVIOCTL = 1

' begin_ntddk begin_wdm begin_nthal begin_ntifs
'
' Define the various device type values.  Note that values used by Microsoft
' Corporation are in the range 0-32767, and 32768-65535 are reserved for use
' by customers.
'

MACRO DEVICE_TYPE=DWORD

%FILE_DEVICE_BEEP                = &H00000001
%FILE_DEVICE_CD_ROM              = &H00000002
%FILE_DEVICE_CD_ROM_FILE_SYSTEM  = &H00000003
%FILE_DEVICE_CONTROLLER          = &H00000004
%FILE_DEVICE_DATALINK            = &H00000005
%FILE_DEVICE_DFS                 = &H00000006
%FILE_DEVICE_DISK                = &H00000007
%FILE_DEVICE_DISK_FILE_SYSTEM    = &H00000008
%FILE_DEVICE_FILE_SYSTEM         = &H00000009
%FILE_DEVICE_INPORT_PORT         = &H0000000a
%FILE_DEVICE_KEYBOARD            = &H0000000b
%FILE_DEVICE_MAILSLOT            = &H0000000c
%FILE_DEVICE_MIDI_IN             = &H0000000d
%FILE_DEVICE_MIDI_OUT            = &H0000000e
%FILE_DEVICE_MOUSE               = &H0000000f
%FILE_DEVICE_MULTI_UNC_PROVIDER  = &H00000010
%FILE_DEVICE_NAMED_PIPE          = &H00000011
%FILE_DEVICE_NETWORK             = &H00000012
%FILE_DEVICE_NETWORK_BROWSER     = &H00000013
%FILE_DEVICE_NETWORK_FILE_SYSTEM = &H00000014
%FILE_DEVICE_NULL                = &H00000015
%FILE_DEVICE_PARALLEL_PORT       = &H00000016
%FILE_DEVICE_PHYSICAL_NETCARD    = &H00000017
%FILE_DEVICE_PRINTER             = &H00000018
%FILE_DEVICE_SCANNER             = &H00000019
%FILE_DEVICE_SERIAL_MOUSE_PORT   = &H0000001a
%FILE_DEVICE_SERIAL_PORT         = &H0000001b
%FILE_DEVICE_SCREEN              = &H0000001c
%FILE_DEVICE_SOUND               = &H0000001d
%FILE_DEVICE_STREAMS             = &H0000001e
%FILE_DEVICE_TAPE                = &H0000001f
%FILE_DEVICE_TAPE_FILE_SYSTEM    = &H00000020
%FILE_DEVICE_TRANSPORT           = &H00000021
%FILE_DEVICE_UNKNOWN             = &H00000022
%FILE_DEVICE_VIDEO               = &H00000023
%FILE_DEVICE_VIRTUAL_DISK        = &H00000024
%FILE_DEVICE_WAVE_IN             = &H00000025
%FILE_DEVICE_WAVE_OUT            = &H00000026
%FILE_DEVICE_8042_PORT           = &H00000027
%FILE_DEVICE_NETWORK_REDIRECTOR  = &H00000028
%FILE_DEVICE_BATTERY             = &H00000029
%FILE_DEVICE_BUS_EXTENDER        = &H0000002a
%FILE_DEVICE_MODEM               = &H0000002b
%FILE_DEVICE_VDM                 = &H0000002c
%FILE_DEVICE_MASS_STORAGE        = &H0000002d
%FILE_DEVICE_SMB                 = &H0000002e
%FILE_DEVICE_KS                  = &H0000002f
%FILE_DEVICE_CHANGER             = &H00000030
%FILE_DEVICE_SMARTCARD           = &H00000031
%FILE_DEVICE_ACPI                = &H00000032
%FILE_DEVICE_DVD                 = &H00000033
%FILE_DEVICE_FULLSCREEN_VIDEO    = &H00000034
%FILE_DEVICE_DFS_FILE_SYSTEM     = &H00000035
%FILE_DEVICE_DFS_VOLUME          = &H00000036
%FILE_DEVICE_SERENUM             = &H00000037
%FILE_DEVICE_TERMSRV             = &H00000038
%FILE_DEVICE_KSEC                = &H00000039
%FILE_DEVICE_FIPS                = &H0000003A
%FILE_DEVICE_INFINIBAND          = &H0000003B
%FILE_DEVICE_VMBUS               = &H0000003E
%FILE_DEVICE_CRYPT_PROVIDER      = &H0000003F
%FILE_DEVICE_WPD                 = &H00000040
%FILE_DEVICE_BLUETOOTH           = &H00000041
%FILE_DEVICE_MT_COMPOSITE        = &H00000042
%FILE_DEVICE_MT_TRANSPORT        = &H00000043
%FILE_DEVICE_BIOMETRIC           = &H00000044
%FILE_DEVICE_PMI                 = &H00000045

'
' Macro definition for defining IOCTL and FSCTL function control codes.  Note
' that function codes 0-2047 are reserved for Microsoft Corporation, and
' 2048-4095 are reserved for customers.
'

MACRO FUNCTION CTL_CODE(xDeviceType, xFunction, xMethod, xAccess)

    MACROTEMP dResult, dTmp

    LOCAL dResult AS DWORD
    LOCAL dTmp    AS DWORD

    dResult = xDeviceType
    SHIFT LEFT dResult, 16
    dTmp = xAccess
    SHIFT LEFT dTmp, 14
    dResult = dResult OR dTmp
    dTmp = xFunction
    SHIFT LEFT dTmp, 2
    dResult = dResult OR dTmp OR xMethod

END MACRO = dResult

'
' Macro to extract device type out of the device io control code
'
MACRO FUNCTION DEVICE_TYPE_FROM_CTL_CODE(ctrlCode)

    MACROTEMP dResult

    LOCAL dResult AS DWORD

    dResult = ctrlCode AND &H0FFFF0000
    SHIFT RIGHT dResult, 16

END MACRO = dResult

'
' Define the method codes for how buffers are passed for I/O and FS controls
'

%METHOD_BUFFERED               = 0
%METHOD_IN_DIRECT              = 1
%METHOD_OUT_DIRECT             = 2
%METHOD_NEITHER                = 3

'
' Define some easier to comprehend aliases:
'   METHOD_DIRECT_TO_HARDWARE (writes, aka METHOD_IN_DIRECT)
'   METHOD_DIRECT_FROM_HARDWARE (reads, aka METHOD_OUT_DIRECT)
'

%METHOD_DIRECT_TO_HARDWARE   = %METHOD_OUT_DIRECT
%METHOD_DIRECT_FROM_HARDWARE = %METHOD_IN_DIRECT

'
' Define the access check value for any access
'
'
' The %FILE_READ_ACCESS and %FILE_WRITE_ACCESS constants are also defined in
' ntioapi.h as %FILE_READ_DATA and %FILE_WRITE_DATA. The values for these
' constants *MUST* always be in sync.
' [PowerBASIC note: there is no NTIOAPI.H file in the Microsoft Windows SDK]
' [...the %FILE_*_DATA equates may be found in winnt.h, or our WinNT.inc]
'
'
' %FILE_SPECIAL_ACCESS is checked by the NT I/O system the same as %FILE_ANY_ACCESS.
' The file systems, however, may add additional access checks for I/O and FS controls
' that use this value.
'


%FILE_ANY_ACCESS     = 0
%FILE_SPECIAL_ACCESS = %FILE_ANY_ACCESS
%FILE_READ_ACCESS    = &H0001      ' file & pipe
%FILE_WRITE_ACCESS   = &H0002      ' file & pipe

' end_ntddk end_wdm end_nthal end_ntifs

#ENDIF  ' #IF NOT %DEF(%DEVIOCTL)



#IF NOT %DEF(%NTDDSTOR_H)

%NTDDSTOR_H = 1

'
' IoControlCode values for storage devices
'

%IOCTL_STORAGE_BASE = %FILE_DEVICE_MASS_STORAGE

'
' The following device control codes are common for all class drivers.  They
' should be used in place of the older IOCTL_DISK, IOCTL_CDROM and IOCTL_TAPE
' common codes
'

%IOCTL_STORAGE_CHECK_VERIFY            = &H002D4800  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0200, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_CHECK_VERIFY2           = &H002D0800  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0200, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_STORAGE_MEDIA_REMOVAL           = &H002D4804  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0201, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_EJECT_MEDIA             = &H002D4808  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0202, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_LOAD_MEDIA              = &H002D480C  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0203, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_LOAD_MEDIA2             = &H002D080C  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0203, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_STORAGE_RESERVE                 = &H002D4810  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0204, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_RELEASE                 = &H002D4814  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0205, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_FIND_NEW_DEVICES        = &H002D4818  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0206, METHOD_BUFFERED, FILE_READ_ACCESS)

%IOCTL_STORAGE_EJECTION_CONTROL        = &H002D0940  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0250, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_STORAGE_MCN_CONTROL             = &H002D0944  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0251, METHOD_BUFFERED, FILE_ANY_ACCESS)

%IOCTL_STORAGE_GET_MEDIA_TYPES         = &H002D0C00  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0300, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_STORAGE_GET_MEDIA_TYPES_EX      = &H002D0C04  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0301, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_STORAGE_GET_MEDIA_SERIAL_NUMBER = &H002D0C10  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0304, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_STORAGE_GET_HOTPLUG_INFO        = &H002D0C14  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0305, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_STORAGE_SET_HOTPLUG_INFO        = &H002DCC18  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0306, METHOD_BUFFERED, FILE_READ_ACCESS OR FILE_WRITE_ACCESS)

%IOCTL_STORAGE_RESET_BUS               = &H002D5000  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0400, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_RESET_DEVICE            = &H002D5004  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0401, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_BREAK_RESERVATION       = &H002D5014  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0405, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_PERSISTENT_RESERVE_IN   = &H002D5018
' CTL_CODE(IOCTL_STORAGE_BASE, &H0406, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_PERSISTENT_RESERVE_OUT  = &H002DD01C
' CTL_CODE(IOCTL_STORAGE_BASE, &H0407, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

%IOCTL_STORAGE_GET_DEVICE_NUMBER       = &H002D1080  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0420, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_STORAGE_PREDICT_FAILURE         = &H002D1100  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0440, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_STORAGE_READ_CAPACITY           = &H002D5140  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0450, METHOD_BUFFERED, FILE_READ_ACCESS)

'
' IOCTLs for bandwidth contracts on storage devices
' (Move this to ntddsfio if we decide to use a new base)
'

%IOCTL_STORAGE_GET_BC_PROPERTIES       = &H002D5800  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0600, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_ALLOCATE_BC_STREAM      = &H002DD804  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0601, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_STORAGE_FREE_BC_STREAM          = &H002DD808  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0602, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

'
' IOCTL to check for priority support
'
%IOCTL_STORAGE_CHECK_PRIORITY_HINT_SUPPORT = &H002D1880  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0620, METHOD_BUFFERED, FILE_ANY_ACCESS)

' begin_winioctl

'
' These ioctl codes are obsolete.  They are defined here to avoid reusing them
' and to allow class drivers to respond to them more easily.
'

%OBSOLETE_IOCTL_STORAGE_RESET_BUS      = &H002DD000  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0400, METHOD_BUFFERED, FILE_READ_ACCESS OR FILE_WRITE_ACCESS)
%OBSOLETE_IOCTL_STORAGE_RESET_DEVICE   = &H002DD004  ' CTL_CODE(IOCTL_STORAGE_BASE, &H0401, METHOD_BUFFERED, FILE_READ_ACCESS OR FILE_WRITE_ACCESS)

'
' IOCTLs 0x0643 to 0x0655 reserved for VHD disk support.
'

'
' %IOCTL_STORAGE_GET_HOTPLUG_INFO
'

TYPE STORAGE_HOTPLUG_INFO
    SIZE                     AS DWORD ' version
    MediaRemovable           AS BYTE  ' ie. zip, jaz, cdrom, mo, etc. vs hdd
    MediaHotplug             AS BYTE  ' ie. does the device succeed a lock even though its not lockable media?
    DeviceHotplug            AS BYTE  ' ie. 1394, USB, etc.
    WriteCacheEnableOverride AS BYTE  ' This field should not be relied upon because it is no longer used
END TYPE

'
' %IOCTL_STORAGE_GET_DEVICE_NUMBER
'
' input - none
'
' output - STORAGE_DEVICE_NUMBER structure
'          The values in the STORAGE_DEVICE_NUMBER structure are guaranteed
'          to remain unchanged until the system is rebooted.  They are not
'          guaranteed to be persistant across boots.
'

TYPE STORAGE_DEVICE_NUMBER

    '
    ' The FILE_DEVICE_XXX type for this device.
    '

    DeviceType AS DWORD  ' DEVICE_TYPE

    '
    ' The number of this device
    '

    DeviceNumber AS DWORD

    '
    ' If the device is partitionable, the partition number of the device.
    ' Otherwise -1
    '

    PartitionNumber AS DWORD
END TYPE

'
' Define the structures for scsi resets
'

TYPE STORAGE_BUS_RESET_REQUEST
    PathId AS BYTE
END TYPE

'
' %IOCTL_STORAGE_MEDIA_REMOVAL disables the mechanism
' on a storage device that ejects media. This function
' may or may not be supported on storage devices that
' support removable media.
'
' %TRUE means prevent media from being removed.
' %FALSE means allow media removal.
'

TYPE PREVENT_MEDIA_REMOVAL
    PreventMediaRemoval AS BYTE
END TYPE



'
'  This is the format of TARGET_DEVICE_CUSTOM_NOTIFICATION.CustomDataBuffer
'  passed to applications by the classpnp autorun code (via IoReportTargetDeviceChangeAsynchronous).
'
TYPE CLASS_MEDIA_CHANGE_CONTEXT
    MediaChangeCount AS DWORD
    NewState         AS DWORD  ' see MEDIA_CHANGE_DETECTION_STATE enum in classpnp.h in DDK
END TYPE


' begin_ntminitape


TYPE TAPE_STATISTICS
    Version                AS DWORD
    Flags                  AS DWORD
    RecoveredWrites        AS QUAD
    UnrecoveredWrites      AS QUAD
    RecoveredReads         AS QUAD
    UnrecoveredReads       AS QUAD
    CompressionRatioReads  AS BYTE
    CompressionRatioWrites AS BYTE
END TYPE

%RECOVERED_WRITES_VALID        = &H00000001
%UNRECOVERED_WRITES_VALID      = &H00000002
%RECOVERED_READS_VALID         = &H00000004
%UNRECOVERED_READS_VALID       = &H00000008
%WRITE_COMPRESSION_INFO_VALID  = &H00000010
%READ_COMPRESSION_INFO_VALID   = &H00000020

TYPE TAPE_GET_STATISTICS
    Operation AS DWORD
END TYPE

%TAPE_RETURN_STATISTICS = 0
%TAPE_RETURN_ENV_INFO   = 1
%TAPE_RESET_STATISTICS  = 2

'
' IOCTL_STORAGE_GET_MEDIA_TYPES_EX will return an array of DEVICE_MEDIA_INFO
' structures, one per supported type, embedded in the GET_MEDIA_TYPES struct.
'

MACRO STORAGE_MEDIA_TYPE_enum=LONG
ENUM STORAGE_MEDIA_TYPE SINGULAR
    '
    ' Following are defined in ntdddisk.h in the MEDIA_TYPE enum
    '
    ' Unknown,                ' Format is unknown
    ' F5_1Pt2_512,            ' 5.25", 1.2MB,  512 bytes/sector
    ' F3_1Pt44_512,           ' 3.5",  1.44MB, 512 bytes/sector
    ' F3_2Pt88_512,           ' 3.5",  2.88MB, 512 bytes/sector
    ' F3_20Pt8_512,           ' 3.5",  20.8MB, 512 bytes/sector
    ' F3_720_512,             ' 3.5",  720KB,  512 bytes/sector
    ' F5_360_512,             ' 5.25", 360KB,  512 bytes/sector
    ' F5_320_512,             ' 5.25", 320KB,  512 bytes/sector
    ' F5_320_1024,            ' 5.25", 320KB,  1024 bytes/sector
    ' F5_180_512,             ' 5.25", 180KB,  512 bytes/sector
    ' F5_160_512,             ' 5.25", 160KB,  512 bytes/sector
    ' RemovableMedia,         ' Removable media other than floppy
    ' FixedMedia,             ' Fixed hard disk media
    ' F3_120M_512,            ' 3.5", 120M Floppy
    ' F3_640_512,             ' 3.5" ,  640KB,  512 bytes/sector
    ' F5_640_512,             ' 5.25",  640KB,  512 bytes/sector
    ' F5_720_512,             ' 5.25",  720KB,  512 bytes/sector
    ' F3_1Pt2_512,            ' 3.5" ,  1.2Mb,  512 bytes/sector
    ' F3_1Pt23_1024,          ' 3.5" ,  1.23Mb, 1024 bytes/sector
    ' F5_1Pt23_1024,          ' 5.25",  1.23MB, 1024 bytes/sector
    ' F3_128Mb_512,           ' 3.5" MO 128Mb   512 bytes/sector
    ' F3_230Mb_512,           ' 3.5" MO 230Mb   512 bytes/sector
    ' F8_256_128,             ' 8",     256KB,  128 bytes/sector
    ' F3_200Mb_512,           ' 3.5",   200M Floppy (HiFD)
    '

    DDS_4mm            = &H20   ' Tape - DAT DDS1,2,... (all vendors)
    MiniQic                     ' Tape - miniQIC Tape
    Travan                      ' Tape - Travan TR-1,2,3,...
    QIC                         ' Tape - QIC
    MP_8mm                      ' Tape - 8mm Exabyte Metal Particle
    AME_8mm                     ' Tape - 8mm Exabyte Advanced Metal Evap
    AIT1_8mm                    ' Tape - 8mm Sony AIT
    DLT                         ' Tape - DLT Compact IIIxt, IV
    NCTP                        ' Tape - Philips NCTP
    IBM_3480                    ' Tape - IBM 3480
    IBM_3490E                   ' Tape - IBM 3490E
    IBM_Magstar_3590            ' Tape - IBM Magstar 3590
    IBM_Magstar_MP              ' Tape - IBM Magstar MP
    STK_DATA_D3                 ' Tape - STK Data D3
    SONY_DTF                    ' Tape - Sony DTF
    DV_6mm                      ' Tape - 6mm Digital Video
    DMI                         ' Tape - Exabyte DMI and compatibles
    SONY_D2                     ' Tape - Sony D2S and D2L
    CLEANER_CARTRIDGE           ' Cleaner - All Drive types that support Drive Cleaners
    CD_ROM                      ' Opt_Disk - CD
    CD_R                        ' Opt_Disk - CD-Recordable (Write Once)
    CD_RW                       ' Opt_Disk - CD-Rewriteable
    DVD_ROM                     ' Opt_Disk - DVD-ROM
    DVD_R                       ' Opt_Disk - DVD-Recordable (Write Once)
    DVD_RW                      ' Opt_Disk - DVD-Rewriteable
    MO_3_RW                     ' Opt_Disk - 3.5" Rewriteable MO Disk
    MO_5_WO                     ' Opt_Disk - MO 5.25" Write Once
    MO_5_RW                     ' Opt_Disk - MO 5.25" Rewriteable (not LIMDOW)
    MO_5_LIMDOW                 ' Opt_Disk - MO 5.25" Rewriteable (LIMDOW)
    PC_5_WO                     ' Opt_Disk - Phase Change 5.25" Write Once Optical
    PC_5_RW                     ' Opt_Disk - Phase Change 5.25" Rewriteable
    PD_5_RW                     ' Opt_Disk - PhaseChange Dual Rewriteable
    ABL_5_WO                    ' Opt_Disk - Ablative 5.25" Write Once Optical
    PINNACLE_APEX_5_RW          ' Opt_Disk - Pinnacle Apex 4.6GB Rewriteable Optical
    SONY_12_WO                  ' Opt_Disk - Sony 12" Write Once
    PHILIPS_12_WO               ' Opt_Disk - Philips/LMS 12" Write Once
    HITACHI_12_WO               ' Opt_Disk - Hitachi 12" Write Once
    CYGNET_12_WO                ' Opt_Disk - Cygnet/ATG 12" Write Once
    KODAK_14_WO                 ' Opt_Disk - Kodak 14" Write Once
    MO_NFR_525                  ' Opt_Disk - Near Field Recording (Terastor)
    NIKON_12_RW                 ' Opt_Disk - Nikon 12" Rewriteable
    IOMEGA_ZIP                  ' Mag_Disk - Iomega Zip
    IOMEGA_JAZ                  ' Mag_Disk - Iomega Jaz
    SYQUEST_EZ135               ' Mag_Disk - Syquest EZ135
    SYQUEST_EZFLYER             ' Mag_Disk - Syquest EzFlyer
    SYQUEST_SYJET               ' Mag_Disk - Syquest SyJet
    AVATAR_F2                   ' Mag_Disk - 2.5" Floppy
    MP2_8mm                     ' Tape - 8mm Hitachi
    DST_S                       ' Ampex DST Small Tapes
    DST_M                       ' Ampex DST Medium Tapes
    DST_L                       ' Ampex DST Large Tapes
    VXATape_1                   ' Ecrix 8mm Tape
    VXATape_2                   ' Ecrix 8mm Tape
#IF (%NTDDI_VERSION < %NTDDI_WINXP)
    STK_EAGLE                   ' STK Eagle
#ELSE
    STK_9840                    ' STK 9840
#ENDIF
    LTO_Ultrium                 ' IBM, HP, Seagate LTO Ultrium
    LTO_Accelis                 ' IBM, HP, Seagate LTO Accelis
    DVD_RAM                     ' Opt_Disk - DVD-RAM
    AIT_8mm                     ' AIT2 or higher
    ADR_1                       ' OnStream ADR Mediatypes
    ADR_2
    STK_9940                    ' STK 9940
    SAIT                        ' SAIT Tapes
    VXATape                     ' VXA (Ecrix 8mm) Tape
END ENUM  ' STORAGE_MEDIA_TYPE


%MEDIA_ERASEABLE         = &H00000001
%MEDIA_WRITE_ONCE        = &H00000002
%MEDIA_READ_ONLY         = &H00000004
%MEDIA_READ_WRITE        = &H00000008

%MEDIA_WRITE_PROTECTED   = &H00000100
%MEDIA_CURRENTLY_MOUNTED = &H80000000???

'
' Define the different storage bus types
' Bus types below 128 (&H80) are reserved for Microsoft use
'

MACRO STORAGE_BUS_TYPE_enum=LONG
ENUM STORAGE_BUS_TYPE SINGULAR
    BusTypeUnknown
    BusTypeScsi
    BusTypeAtapi
    BusTypeAta
    BusType1394
    BusTypeSsa
    BusTypeFibre
    BusTypeUsb
    BusTypeRAID
    BusTypeiScsi
    BusTypeSas
    BusTypeSata
    BusTypeSd
    BusTypeMmc
    BusTypeVirtual
    BusTypeFileBackedVirtual
    BusTypeMax
    BusTypeMaxReserved = &H7F
END ENUM

TYPE DMI_DiskInfo
    Cylinders            AS QUAD
    MediaType            AS LONG   ' STORAGE_MEDIA_TYPE
    TracksPerCylinder    AS DWORD
    SectorsPerTrack      AS DWORD
    BytesPerSector       AS DWORD
    NumberMediaSides     AS DWORD
    MediaCharacteristics AS DWORD  ' Bitmask of MEDIA_XXX values.
END TYPE

TYPE DMI_TapeInfo
    MediaType            AS LONG    ' STORAGE_MEDIA_TYPE
    MediaCharacteristics AS DWORD   ' Bitmask of MEDIA_XXX values.
    CurrentBlockSize     AS DWORD
    BusType              AS LONG    ' STORAGE_BUS_TYPE

    '
    ' Bus specific information describing the medium supported.
    '

    MediumType           AS BYTE
    DensityCode          AS BYTE
END TYPE


UNION DEVICE_MEDIA_INFO
    di AS DMI_DiskInfo
    ti AS DMI_TapeInfo
END UNION

TYPE GET_MEDIA_TYPES
    DeviceType     AS DWORD              ' FILE_DEVICE_XXX values
    MediaInfoCount AS DWORD
    MediaInfo(0)   AS DEVICE_MEDIA_INFO
END TYPE


'
' IOCTL_STORAGE_PREDICT_FAILURE
'
' input - none
'
' output - STORAGE_PREDICT_FAILURE structure
'          PredictFailure returns zero if no failure predicted and non zero
'                         if a failure is predicted.
'
'          VendorSpecific returns 512 bytes of vendor specific information
'                         if a failure is predicted
'
TYPE STORAGE_PREDICT_FAILURE
    PredictFailure AS DWORD
    VendorSpecific AS STRING * 512
END TYPE

' end_ntminitape

#ENDIF  ' #IF NOT %DEF(%NTDDSTOR_H)



'
' IoControlCode values for disk devices.
'

%IOCTL_DISK_BASE                = %FILE_DEVICE_DISK
%IOCTL_DISK_GET_DRIVE_GEOMETRY  = &H00070000  ' CTL_CODE(IOCTL_DISK_BASE, &H0000, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_GET_PARTITION_INFO  = &H00074004  ' CTL_CODE(IOCTL_DISK_BASE, &H0001, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_SET_PARTITION_INFO  = &H0007C008  ' CTL_CODE(IOCTL_DISK_BASE, &H0002, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_DISK_GET_DRIVE_LAYOUT    = &H0007400C  ' CTL_CODE(IOCTL_DISK_BASE, &H0003, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_SET_DRIVE_LAYOUT    = &H0007C010  ' CTL_CODE(IOCTL_DISK_BASE, &H0004, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_DISK_VERIFY              = &H00070014  ' CTL_CODE(IOCTL_DISK_BASE, &H0005, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_FORMAT_TRACKS       = &H0007C018  ' CTL_CODE(IOCTL_DISK_BASE, &H0006, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_DISK_REASSIGN_BLOCKS     = &H0007C01C  ' CTL_CODE(IOCTL_DISK_BASE, &H0007, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_DISK_PERFORMANCE         = &H00070020  ' CTL_CODE(IOCTL_DISK_BASE, &H0008, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_IS_WRITABLE         = &H00070024  ' CTL_CODE(IOCTL_DISK_BASE, &H0009, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_LOGGING             = &H00070028  ' CTL_CODE(IOCTL_DISK_BASE, &H000a, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_FORMAT_TRACKS_EX    = &H0007C02C  ' CTL_CODE(IOCTL_DISK_BASE, &H000b, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_DISK_HISTOGRAM_STRUCTURE = &H00070030  ' CTL_CODE(IOCTL_DISK_BASE, &H000c, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_HISTOGRAM_DATA      = &H00070034  ' CTL_CODE(IOCTL_DISK_BASE, &H000d, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_HISTOGRAM_RESET     = &H00070038  ' CTL_CODE(IOCTL_DISK_BASE, &H000e, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_REQUEST_STRUCTURE   = &H0007003C  ' CTL_CODE(IOCTL_DISK_BASE, &H000f, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_REQUEST_DATA        = &H00070040  ' CTL_CODE(IOCTL_DISK_BASE, &H0010, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_PERFORMANCE_OFF     = &H00070060  ' CTL_CODE(IOCTL_DISK_BASE, &H0018, METHOD_BUFFERED, FILE_ANY_ACCESS)



#IF %WIN32_WINNT >= &H0400

%IOCTL_DISK_CONTROLLER_NUMBER    = &H00070044  ' CTL_CODE(IOCTL_DISK_BASE, &H0011, METHOD_BUFFERED, FILE_ANY_ACCESS)

'
' IOCTL support for SMART drive fault prediction.
'

%SMART_GET_VERSION               = &H00074080  ' CTL_CODE(IOCTL_DISK_BASE, &H0020, METHOD_BUFFERED, FILE_READ_ACCESS)
%SMART_SEND_DRIVE_COMMAND        = &H0007C084  ' CTL_CODE(IOCTL_DISK_BASE, &H0021, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%SMART_RCV_DRIVE_DATA            = &H0007C088  ' CTL_CODE(IOCTL_DISK_BASE, &H0022, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#ENDIF  ' #IF %WIN32_WINNT >= &H0400

#IF %WIN32_WINNT >= &H0500

'
' New IOCTLs for GUID Partition tabled disks.
'

%IOCTL_DISK_GET_PARTITION_INFO_EX    = &H00070048  ' CTL_CODE(IOCTL_DISK_BASE, &H0012, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_SET_PARTITION_INFO_EX    = &H0007C04C  ' CTL_CODE(IOCTL_DISK_BASE, &H0013, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_DISK_GET_DRIVE_LAYOUT_EX      = &H00070050  ' CTL_CODE(IOCTL_DISK_BASE, &H0014, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_SET_DRIVE_LAYOUT_EX      = &H0007C054  ' CTL_CODE(IOCTL_DISK_BASE, &H0015, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_DISK_CREATE_DISK              = &H0007C058  ' CTL_CODE(IOCTL_DISK_BASE, &H0016, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_DISK_GET_LENGTH_INFO          = &H0007405C  ' CTL_CODE(IOCTL_DISK_BASE, &H0017, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_GET_DRIVE_GEOMETRY_EX    = &H000700A0  ' CTL_CODE(IOCTL_DISK_BASE, &H0028, METHOD_BUFFERED, FILE_ANY_ACCESS)

#ENDIF  ' #IF %WIN32_WINNT >= &H0500


#IF %WIN32_WINNT >= &H0500

%IOCTL_DISK_UPDATE_DRIVE_SIZE        = &H0007C0C8  ' CTL_CODE(IOCTL_DISK_BASE, &H0032, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_DISK_GROW_PARTITION           = &H0007C0D0  ' CTL_CODE(IOCTL_DISK_BASE, &H0034, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

%IOCTL_DISK_GET_CACHE_INFORMATION    = &H000740D4  ' CTL_CODE(IOCTL_DISK_BASE, &H0035, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_SET_CACHE_INFORMATION    = &H0007C0D8  ' CTL_CODE(IOCTL_DISK_BASE, &H0036, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_DISK_GET_WRITE_CACHE_STATE    = &H000740DC  ' CTL_CODE(IOCTL_DISK_BASE, &H0037, METHOD_BUFFERED, FILE_READ_ACCESS)

%IOCTL_DISK_DELETE_DRIVE_LAYOUT      = &H0007C100  ' CTL_CODE(IOCTL_DISK_BASE, &H0040, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

'
' Called to flush cached information that the driver may have about this
' device's characteristics.  Not all drivers cache characteristics, and not
' cached properties can be flushed.  This simply serves as an update to the
' driver that it may want to do an expensive reexamination of the device's
' characteristics now (fixed media size, partition table, etc...)
'

%IOCTL_DISK_UPDATE_PROPERTIES    = &H00070140  ' CTL_CODE(IOCTL_DISK_BASE, &H0050, METHOD_BUFFERED, FILE_ANY_ACCESS)

'
'  Special IOCTLs needed to support PC-98 machines in Japan
'

%IOCTL_DISK_FORMAT_DRIVE         = &H0007C3CC  ' CTL_CODE(IOCTL_DISK_BASE, &H00f3, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_DISK_SENSE_DEVICE         = &H000703E0  ' CTL_CODE(IOCTL_DISK_BASE, &H00f8, METHOD_BUFFERED, FILE_ANY_ACCESS)

#ENDIF  ' #IF %WIN32_WINNT >= &H0500

'
' The following device control codes are common for all class drivers.  The
' functions codes defined here must match all of the other class drivers.
'
' Warning: these codes will be replaced in the future by equivalent
' IOCTL_STORAGE codes
'

%IOCTL_DISK_CHECK_VERIFY     = &H00074800  ' CTL_CODE(IOCTL_DISK_BASE, &H0200, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_MEDIA_REMOVAL    = &H00074804  ' CTL_CODE(IOCTL_DISK_BASE, &H0201, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_EJECT_MEDIA      = &H00074808  ' CTL_CODE(IOCTL_DISK_BASE, &H0202, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_LOAD_MEDIA       = &H0007480C  ' CTL_CODE(IOCTL_DISK_BASE, &H0203, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_RESERVE          = &H00074810  ' CTL_CODE(IOCTL_DISK_BASE, &H0204, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_RELEASE          = &H00074814  ' CTL_CODE(IOCTL_DISK_BASE, &H0205, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_FIND_NEW_DEVICES = &H00074818  ' CTL_CODE(IOCTL_DISK_BASE, &H0206, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_GET_MEDIA_TYPES  = &H00070C00  ' CTL_CODE(IOCTL_DISK_BASE, &H0300, METHOD_BUFFERED, FILE_ANY_ACCESS)

'
' Define the partition types returnable by known disk drivers.
'

%PARTITION_ENTRY_UNUSED        = &H00      ' Entry unused
%PARTITION_FAT_12              = &H01      ' 12-bit FAT entries
%PARTITION_XENIX_1             = &H02      ' Xenix
%PARTITION_XENIX_2             = &H03      ' Xenix
%PARTITION_FAT_16              = &H04      ' 16-bit FAT entries
%PARTITION_EXTENDED            = &H05      ' Extended partition entry
%PARTITION_HUGE                = &H06      ' Huge partition MS-DOS V4
%PARTITION_IFS                 = &H07      ' IFS Partition
%PARTITION_OS2BOOTMGR          = &H0A      ' OS/2 Boot Manager/OPUS/Coherent swap
%PARTITION_FAT32               = &H0B      ' FAT32
%PARTITION_FAT32_XINT13        = &H0C      ' FAT32 using extended int13 services
%PARTITION_XINT13              = &H0E      ' Win95 partition using extended int13 services
%PARTITION_XINT13_EXTENDED     = &H0F      ' Same as type 5 but uses extended int13 services
%PARTITION_PREP                = &H41      ' PowerPC Reference Platform (PReP) Boot Partition
%PARTITION_LDM                 = &H42      ' Logical Disk Manager partition
%PARTITION_UNIX                = &H63      ' Unix

%VALID_NTFT                    = &H0C0     ' NTFT uses high order bits

'
' The high bit of the partition type code indicates that a partition
' is part of an NTFT mirror or striped array.
'

%PARTITION_NTFT                = &H080     ' NTFT partition

'
' The following macro is used to determine which partitions should be
' assigned drive letters.
'

'++
'
' BYTE
' IsRecognizedPartition(
'     IN DWORD PartitionType
'     )
'
' Routine Description:
'
'     This macro is used to determine to which partitions drive letters
'     should be assigned.
'
' Arguments:
'
'     PartitionType - Supplies the type of the partition being examined.
'
' Return Value:
'
'     The return value is %TRUE if the partition type is recognized,
'     otherwise %FALSE is returned.
'
'--

MACRO FUNCTION IsRecognizedPartition(PartitionType)

    MACROTEMP b, d, m

    LOCAL b AS BYTE
    LOCAL d AS DWORD
    LOCAL m AS DWORD

    d = PartitionType
    m = d AND NOT &H00C0

    b = (ISTRUE(d AND %PARTITION_NTFT) _
         AND ((m = %PARTITION_FAT_12) OR (m = %PARTITION_IFS)            _
           OR (m = %PARTITION_HUGE)   OR (m = %PARTITION_FAT32)          _
           OR (m = PARTITION_XINT13)  OR (m = %PARTITION_FAT32_XINT13))) _
     OR (d = PARTITION_FAT_12) OR (d = PARTITION_FAT_16)                 _
     OR (d = PARTITION_IFS)    OR (d = PARTITION_HUGE)                   _
     OR (d = PARTITION_FAT32)  OR (d = PARTITION_FAT32_XINT13)           _
     OR (d = PARTITION_XINT13))

END MACRO = ABS(b)



'++
'
' BYTE
' IsContainerPartition(
'     IN DWORD PartitionType
'     )
'
' Routine Description:
'
'     This macro is used to determine to which partition types are actually
'     containers for other partitions (ie, extended partitions).
'
' Arguments:
'
'     PartitionType - Supplies the type of the partition being examined.
'
' Return Value:
'
'     The return value is %TRUE if the partition type is a container,
'     otherwise %FALSE is returned.
'
'--

MACRO IsContainerPartition(PartitionType) = ABS(((PartitionType) = %PARTITION_EXTENDED) OR ((PartitionType) = %PARTITION_XINT13_EXTENDED)))



'++
'
' BYTE
' IsFTPartition(
'     IN DWORD PartitionType
'     )
'
' Routine Description:
'
'     This macro is used to determine if the given partition is an FT
'     partition.
'
' Arguments:
'
'     PartitionType - Supplies the type of the partition being examined.
'
' Return Value:
'
'     The return value is %TRUE if the partition type is an FT partition,
'     otherwise %FALSE is returned.
'
'--

MACRO IsFTPartition(PartitionType) = ABS(ISTRUE ((PartitionType) AND %PARTITION_NTFT) AND ISTRUE IsRecognizedPartition(PartitionType))



'
' Define the media types supported by the driver.
'

MACRO MEDIA_TYPE_enum=LONG
ENUM MEDIA_TYPE SINGULAR
    Unknown                 ' Format is unknown
    F5_1Pt2_512             ' 5.25", 1.2MB,  512 bytes/sector
    F3_1Pt44_512            ' 3.5",  1.44MB, 512 bytes/sector
    F3_2Pt88_512            ' 3.5",  2.88MB, 512 bytes/sector
    F3_20Pt8_512            ' 3.5",  20.8MB, 512 bytes/sector
    F3_720_512              ' 3.5",  720KB,  512 bytes/sector
    F5_360_512              ' 5.25", 360KB,  512 bytes/sector
    F5_320_512              ' 5.25", 320KB,  512 bytes/sector
    F5_320_1024             ' 5.25", 320KB,  1024 bytes/sector
    F5_180_512              ' 5.25", 180KB,  512 bytes/sector
    F5_160_512              ' 5.25", 160KB,  512 bytes/sector
    RemovableMedia          ' Removable media other than floppy
    FixedMedia              ' Fixed hard disk media
    F3_120M_512             ' 3.5", 120M Floppy
    F3_640_512              ' 3.5" ,  640KB,  512 bytes/sector
    F5_640_512              ' 5.25",  640KB,  512 bytes/sector
    F5_720_512              ' 5.25",  720KB,  512 bytes/sector
    F3_1Pt2_512             ' 3.5" ,  1.2Mb,  512 bytes/sector
    F3_1Pt23_1024           ' 3.5" ,  1.23Mb, 1024 bytes/sector
    F5_1Pt23_1024           ' 5.25",  1.23MB, 1024 bytes/sector
    F3_128Mb_512            ' 3.5" MO 128Mb   512 bytes/sector
    F3_230Mb_512            ' 3.5" MO 230Mb   512 bytes/sector
    F8_256_128              ' 8",     256KB,  128 bytes/sector
    F3_200Mb_512            ' 3.5",   200M Floppy  (HiFD)
    F3_240M_512             ' 3.5",   240Mb Floppy (HiFD)
    F3_32M_512              ' 3.5",   32Mb Floppy
END ENUM

'
' Define the input buffer structure for the driver, when
' it is called with IOCTL_DISK_FORMAT_TRACKS.
'

TYPE FORMAT_PARAMETERS
   MediaType           AS LONG  ' MEDIA_TYPE
   StartCylinderNumber AS DWORD
   EndCylinderNumber   AS DWORD
   StartHeadNumber     AS DWORD
   EndHeadNumber       AS DWORD
END TYPE

'
' Define the BAD_TRACK_NUMBER type. An array of elements of this type is
' returned by the driver on IOCTL_DISK_FORMAT_TRACKS requests, to indicate
' what tracks were bad during formatting. The length of that array is
' reported in the `Information' field of the I/O Status Block.
'

'typedef WORD   BAD_TRACK_NUMBER;
'typedef WORD   *PBAD_TRACK_NUMBER;

'
' Define the input buffer structure for the driver, when
' it is called with IOCTL_DISK_FORMAT_TRACKS_EX.
'

TYPE FORMAT_EX_PARAMETERS
   MediaType           AS LONG  ' MEDIA_TYPE
   StartCylinderNumber AS DWORD
   EndCylinderNumber   AS DWORD
   StartHeadNumber     AS DWORD
   EndHeadNumber       AS DWORD
   FormatGapLength     AS WORD
   SectorsPerTrack     AS WORD
   SectorNumber(0)     AS WORD
END TYPE

'
' The following structure is returned on an IOCTL_DISK_GET_DRIVE_GEOMETRY
' request and an array of them is returned on an IOCTL_DISK_GET_MEDIA_TYPES
' request.
'

TYPE DISK_GEOMETRY
    Cylinders         AS QUAD
    MediaType         AS LONG  ' MEDIA_TYPE
    TracksPerCylinder AS DWORD
    SectorsPerTrack   AS DWORD
    BytesPerSector    AS DWORD
END TYPE



'
' This wmi guid returns a DISK_GEOMETRY structure
'
$WMI_DISK_GEOMETRY_GUID = GUID$("{25007F51-57C2-11D1-A528-00A0C9062910}")



'
' The following structure is returned on an IOCTL_DISK_GET_PARTITION_INFO
' and an IOCTL_DISK_GET_DRIVE_LAYOUT request.  It is also used in a request
' to change the drive layout, IOCTL_DISK_SET_DRIVE_LAYOUT.
'

TYPE PARTITION_INFORMATION
    StartingOffset      AS QUAD
    PartitionLength     AS QUAD
    HiddenSectors       AS DWORD
    PartitionNumber     AS DWORD
    PartitionType       AS BYTE
    BootIndicator       AS BYTE
    RecognizedPartition AS BYTE
    RewritePartition    AS BYTE
END TYPE

'
' The following structure is used to change the partition type of a
' specified disk partition using an IOCTL_DISK_SET_PARTITION_INFO
' request.
'

TYPE SET_PARTITION_INFORMATION
    PartitionType AS BYTE
END TYPE

'
' The following structures is returned on an IOCTL_DISK_GET_DRIVE_LAYOUT
' request and given as input to an IOCTL_DISK_SET_DRIVE_LAYOUT request.
'

TYPE DRIVE_LAYOUT_INFORMATION
    PartitionCount    AS DWORD
    Signature         AS DWORD
    PartitionEntry(0) AS PARTITION_INFORMATION
END TYPE

'
' The following structure is passed in on an IOCTL_DISK_VERIFY request.
' The offset and length parameters are both given in bytes.
'

TYPE VERIFY_INFORMATION
    StartingOffset AS QUAD
    Length         AS DWORD
END TYPE

'
' The following structure is passed in on an IOCTL_DISK_REASSIGN_BLOCKS
' request.
'

TYPE REASSIGN_BLOCKS
    Reserved       AS WORD
    COUNT          AS WORD
    BlockNumber(0) AS DWORD
END TYPE


#IF %WIN32_WINNT >= &H0500

'
' Support for GUID Partition Table (GPT) disks.
'

'
' There are currently two ways a disk can be partitioned. With a traditional
' AT-style master boot record (PARTITION_STYLE_MBR) and with a new, GPT
' partition table (PARTITION_STYLE_GPT). RAW is for an unrecognizable
' partition style. There are a very limited number of things you can
' do with a RAW partititon.
'

MACRO PARTITION_STYLE_enum=LONG
ENUM PARTITION_STYLE SINGULAR
    PARTITION_STYLE_MBR
    PARTITION_STYLE_GPT
    PARTITION_STYLE_RAW
END ENUM


'
' The following structure defines information in a GPT partition that is
' not common to both GPT and MBR partitions.
'

TYPE PARTITION_INFORMATION_GPT
    PartitionType AS GUID          ' Partition type. See table 16-3.
    PartitionId   AS GUID          ' Unique GUID for this partition.
    Attributes    AS QUAD          ' See table 16-4.
    uName         AS STRING * 72   ' Partition Name in Unicode.
END TYPE

'
'  The following are GPT partition attributes applicable for any
'  partition type. These attributes are not OS-specific
'

%GPT_ATTRIBUTE_PLATFORM_REQUIRED          = &H0000000000000001

'
' The following are GPT partition attributes applicable when the
' PartitionType is PARTITION_BASIC_DATA_GUID.
'
' [At the time this is written, PowerBASIC does not support 64-bit hexadecimal
'  constants, so the values are expressed in decimal form.]

%GPT_BASIC_DATA_ATTRIBUTE_NO_DRIVE_LETTER = &H8000000000000000
%GPT_BASIC_DATA_ATTRIBUTE_HIDDEN          = &H4000000000000000
%GPT_BASIC_DATA_ATTRIBUTE_READ_ONLY       = &H1000000000000000

'
' The following structure defines information in an MBR partition that is not
' common to both GPT and MBR partitions.
'

TYPE PARTITION_INFORMATION_MBR
    PartitionType       AS BYTE
    BootIndicator       AS BYTE
    RecognizedPartition AS BYTE
    HiddenSectors       AS DWORD
END TYPE


'
' The structure SET_PARTITION_INFO_EX is used with the ioctl
' IOCTL_SET_PARTITION_INFO_EX to set information about a specific
' partition. Note that for MBR partitions, you can only set the partition
' signature, whereas GPT partitions allow setting of all fields that
' you can get.
'

TYPE SET_PARTITION_INFORMATION_MBR
    SET_PARTITION_INFORMATION
END TYPE

TYPE SET_PARTITION_INFORMATION_GPT
    PARTITION_INFORMATION_GPT
END TYPE

UNION SPIMSPIGunion
    Mbr AS SET_PARTITION_INFORMATION_MBR
    Gpt AS SET_PARTITION_INFORMATION_GPT
END UNION


TYPE SET_PARTITION_INFORMATION_EX
    PartitionStyle AS LONG  ' PARTITION_STYLE
    SPIMSPIGunion
END TYPE


'
' The structure CREATE_DISK_GPT with the ioctl IOCTL_DISK_CREATE_DISK
' to initialize an virgin disk with an empty GPT partition table.
'

TYPE CREATE_DISK_GPT
    DiskId            AS GUID          ' Unique disk id for the disk.
    MaxPartitionCount AS DWORD         ' Maximim number of partitions allowable.
END TYPE

'
' The structure CREATE_DISK_MBR with the ioctl IOCTL_DISK_CREATE_DISK
' to initialize an virgin disk with an empty MBR partition table.
'

TYPE CREATE_DISK_MBR
    Signature AS DWORD
END TYPE

UNION CDMCDGunion
    Mbr AS CREATE_DISK_MBR
    Gpt AS CREATE_DISK_GPT
END UNION


TYPE CREATE_DISK
    PartitionStyle AS LONG  ' PARTITION_STYLE
    CDMCDGunion
END TYPE


'
' The structure GET_LENGTH_INFORMATION is used with the ioctl
' IOCTL_DISK_GET_LENGTH_INFO to obtain the length, in bytes, of the
' disk, partition, or volume.
'

TYPE GET_LENGTH_INFORMATION
    Length AS QUAD
END TYPE

'
' The PARTITION_INFORMATION_EX structure is used with the
' IOCTL_DISK_GET_DRIVE_LAYOUT_EX, IOCTL_DISK_SET_DRIVE_LAYOUT_EX,
' IOCTL_DISK_GET_PARTITION_INFO_EX and IOCTL_DISK_GET_PARTITION_INFO_EX calls.
'

UNION PIMPIGunion
    Mbr AS PARTITION_INFORMATION_MBR
    Gpt AS PARTITION_INFORMATION_GPT
END UNION

TYPE PARTITION_INFORMATION_EX
    PartitionStyle   AS LONG  ' PARTITION_STYLE
    StartingOffset   AS QUAD
    PartitionLength  AS QUAD
    PartitionNumber  AS DWORD
    RewritePartition AS BYTE
    PIMPIGunion
END TYPE


'
' GPT specific drive layout information.
'

TYPE DRIVE_LAYOUT_INFORMATION_GPT
    DiskId               AS GUID
    StartingUsableOffset AS QUAD
    UsableLength         AS QUAD
    MaxPartitionCount    AS DWORD
END TYPE


'
' MBR specific drive layout information.
'

TYPE DRIVE_LAYOUT_INFORMATION_MBR
    Signature AS DWORD
END TYPE

'
' The structure DRIVE_LAYOUT_INFORMATION_EX is used with the
' IOCTL_SET_DRIVE_LAYOUT_EX and IOCTL_GET_DRIVE_LAYOUT_EX calls.
'

UNION DLIMDLIGunion
    Mbr AS DRIVE_LAYOUT_INFORMATION_MBR
    Gpt AS DRIVE_LAYOUT_INFORMATION_GPT
END UNION

TYPE DRIVE_LAYOUT_INFORMATION_EX
    PartitionStyle AS DWORD
    PartitionCount AS DWORD
    DLIMDLIGunion
    PartitionEntry(0) AS PARTITION_INFORMATION_EX
END TYPE

#ENDIF  ' #IF %WIN32_WINNT >= &H0500


#IF %WIN32_WINNT >= &H0500

'
' The DISK_GEOMETRY_EX structure is returned on issuing an
' IOCTL_DISK_GET_DRIVE_GEOMETRY_EX ioctl.
'

MACRO DETECTION_TYPE_enum=LONG
ENUM DETECTION_TYPE
    DetectNone
    DetectInt13
    DetectExInt13
END ENUM

TYPE DISK_INT13_INFO
    DriveSelect     AS WORD
    MaxCylinders    AS DWORD
    SectorsPerTrack AS WORD
    MaxHeads        AS WORD
    NumberDrives    AS WORD
END TYPE

TYPE DISK_EX_INT13_INFO
    ExBufferSize      AS WORD
    ExFlags           AS WORD
    ExCylinders       AS DWORD
    ExHeads           AS DWORD
    ExSectorsPerTrack AS DWORD
    ExSectorsPerDrive AS QUAD
    ExSectorSize      AS WORD
    ExReserved        AS WORD
END TYPE

TYPE DISK_DETECTION_INFO
    SizeOfDetectInfo AS DWORD
    DetectionType    AS LONG   ' DETECTION_TYPE
    '
    ' If DetectionType == DETECTION_INT13 then we have just the Int13
    ' information.
    '
    Int13            AS DISK_INT13_INFO
    '
    ' If DetectionType == DETECTION_EX_INT13, then we have the
    ' extended int 13 information.
    '
    ExInt13          AS DISK_EX_INT13_INFO  ' If DetectionType == DetectExInt13
END TYPE

TYPE MBR
    Signature AS DWORD   ' MBR Signature
    CheckSum  AS DWORD   ' MBR CheckSum
END TYPE

TYPE GPT
    DiskId AS GUID
END TYPE

UNION MBRGPTunion
    MBR    ' If PartitionStyle == MBR
    GPT    ' If PartitionStyle == GPT
END UNION


TYPE DISK_PARTITION_INFO
    SizeOfPartitionInfo AS DWORD
    PartitionStyle      AS LONG   ' PARTITION_STYLE ( = RAW, GPT or MBR)
    MBRGPTunion
END TYPE


'
' The Geometry structure is a variable length structure composed of a
' DISK_GEOMETRY_EX structure followed by a DISK_PARTITION_INFO structure
' followed by a DISK_DETECTION_DATA structure.
'

'#define DiskGeometryGetPartition(Geometry) _
'                        ((PDISK_PARTITION_INFO)((Geometry)+1))
'
'#define DiskGeometryGetDetect(Geometry) _
'                        ((PDISK_DETECTION_INFO)(((PBYTE)DiskGeometryGetPartition(Geometry)+ _
'                                        DiskGeometryGetPartition(Geometry)->SizeOfPartitionInfo)))

TYPE DISK_GEOMETRY_EX
    Geometry  AS DISK_GEOMETRY ' Standard disk geometry: may be faked by driver
    qDiskSize AS QUAD          ' Must always be correct
    bData(0)  AS BYTE          ' Partition, Detect info
END TYPE

#ENDIF  ' #IF %WIN32_WINNT >= &H0500

#IF %WIN32_WINNT >= &H0400
'
' IOCTL_DISK_CONTROLLER_NUMBER returns the controller and disk
' number for the handle.  This is used to determine if a disk
' is attached to the primary or secondary IDE controller.
'

TYPE DISK_CONTROLLER_NUMBER
    ControllerNumber AS DWORD
    DiskNumber       AS DWORD
END TYPE

#ENDIF  ' #IF %WIN32_WINNT >= &H0400

#IF %WIN32_WINNT >= &H0500


'
' IOCTL_DISK_SET_CACHE allows the caller to get or set the state of the disk
' read/write caches.
'
' If the structure is provided as the input buffer for the ioctl the read &
' write caches will be enabled or disabled depending on the parameters
' provided.
'
' If the structure is provided as an output buffer for the ioctl the state
' of the read & write caches will be returned. If both input and outut buffers
' are provided the output buffer will contain the cache state BEFORE any
' changes are made
'

MACRO DISK_CACHE_RETENTION_PRIORITY_enum=LONG
ENUM DISK_CACHE_RETENTION_PRIORITY SINGULAR
    EqualPriority
    KeepPrefetchedData
    KeepReadData
END ENUM

MACRO DISK_WRITE_CACHE_STATE_enum=LONG
ENUM DISK_WRITE_CACHE_STATE SINGULAR
    DiskWriteCacheNormal
    DiskWriteCacheForceDisable
    DiskWriteCacheDisableNotSupported
END ENUM

TYPE ScalarPrefetch
    Minimum AS WORD
    Maximum AS WORD
    '
    ' The maximum number of blocks which will be prefetched - useful
    ' with the scalar limits to set definite upper limits.
    '
    MaximumBlocks AS WORD
END TYPE

TYPE DISK_CACHE_INFORMATION

    '
    ' on return indicates that the device is capable of saving any parameters
    ' in non-volatile storage.  On send indicates that the device should
    ' save the state in non-volatile storage.
    '

    ParametersSavable AS BYTE

    '
    ' Indicates whether the write and read caches are enabled.
    '

    ReadCacheEnabled  AS BYTE
    WriteCacheEnabled AS BYTE

    '
    ' Controls the likelyhood of data remaining in the cache depending on how
    ' it got there.  Data cached from a READ or WRITE operation may be given
    ' higher, lower or equal priority to data entered into the cache for other
    ' means (like prefetch)
    '

    ReadRetentionPriority  AS LONG  ' DISK_CACHE_RETENTION_PRIORITY
    WriteRetentionPriority AS LONG  ' DISK_CACHE_RETENTION_PRIORITY

    '
    ' Requests for a larger number of blocks than this may have prefetching
    ' disabled.  If this value is set to 0 prefetch will be disabled.
    '

    DisablePrefetchTransferLength AS WORD

    '
    ' If TRUE then ScalarPrefetch (below) will be valid.  If FALSE then
    ' the minimum and maximum values should be treated as a block count
    ' (BlockPrefetch)
    '

    PrefetchScalar AS BYTE

    '
    ' Contains the minimum and maximum amount of data which will be
    ' will be prefetched into the cache on a disk operation.  This value
    ' may either be a scalar multiplier of the transfer length of the request,
    ' or an abolute number of disk blocks.  PrefetchScalar (above) indicates
    ' which interpretation is used.
    '

    ScalarPrefetch

END TYPE

'
' IOCTL_DISK_GROW_PARTITION will update the size of a partition
' by adding sectors to the length. The number of sectors must be
' predetermined by examining PARTITION_INFORMATION.
'

TYPE DISK_GROW_PARTITION
    PartitionNumber AS DWORD
    BytesToGrow     AS QUAD
END TYPE

#ENDIF  ' #IF %WIN32_WINNT >= &H0500

'''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                   '
' The following structures define disk performance  '
' statistics: specifically the locations of all the '
' reads and writes which have occured on the disk.  '
'                                                   '
' To use these structures, you must issue an IOCTL_ '
' DISK_HIST_STRUCTURE (with a DISK_HISTOGRAM) to    '
' obtain the basic histogram information. The       '
' number of buckets which must allocated is part of '
' this structure. Allocate the required number of   '
' buckets and call an IOCTL_DISK_HIST_DATA to fill  '
' in the data                                       '
'                                                   '
'''''''''''''''''''''''''''''''''''''''''''''''''''''

%HIST_NO_OF_BUCKETS = 24

TYPE HISTOGRAM_BUCKET
    Reads  AS DWORD
    Writes AS DWORD
END TYPE

%HISTOGRAM_BUCKET_SIZE = 8  ' SIZEOF(HISTOGRAM_BUCKET)

TYPE DISK_HISTOGRAM
    qDiskSize     AS QUAD
    qStart        AS QUAD
    qEnd          AS QUAD
    qAverage      AS QUAD
    qAverageRead  AS QUAD
    qAverageWrite AS QUAD
    qGranularity  AS DWORD
    qSize         AS DWORD
    qReadCount    AS DWORD
    qWriteCount   AS DWORD
    qHistogram    AS HISTOGRAM_BUCKET PTR
END TYPE

%DISK_HISTOGRAM_SIZE = 68  ' SIZEOF(DISK_HISTOGRAM)

'''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                   '
' The following structures define disk debugging    '
' capabilities. The IOCTLs are directed to one of   '
' the two disk filter drivers.                      '
'                                                   '
' DISKPERF is a utilty for collecting disk request  '
' statistics.                                       '
'                                                   '
' SIMBAD is a utility for injecting faults in       '
' IO requests to disks.                             '
'                                                   '
'''''''''''''''''''''''''''''''''''''''''''''''''''''

'
' The following structure is exchanged on an %IOCTL_DISK_GET_PERFORMANCE
' request. This ioctl collects summary disk request statistics used
' in measuring performance.
'

TYPE DISK_PERFORMANCE
    BytesRead           AS QUAD
    BytesWritten        AS QUAD
    ReadTime            AS QUAD
    WriteTime           AS QUAD
    IdleTime            AS QUAD
    ReadCount           AS DWORD
    WriteCount          AS DWORD
    QueueDepth          AS DWORD
    SplitCount          AS DWORD
    QueryTime           AS QUAD
    StorageDeviceNumber AS DWORD
    StorageManagerName  AS STRING * 16  ' 8 characters in UnicodeZ format
END TYPE

'
' This structure defines the disk logging record. When disk logging
' is enabled, one of these is written to an internal buffer for each
' disk request.
'

TYPE DISK_RECORD
    ByteOffset     AS QUAD
    StartTime      AS QUAD
    EndTime        AS QUAD
    VirtualAddress AS DWORD
    NumberOfBytes  AS DWORD
    DeviceNumber   AS BYTE
    ReadRequest    AS BYTE
END TYPE

'
' The following structure is exchanged on an IOCTL_DISK_LOG request.
' Not all fields are valid with each function type.
'

TYPE DISK_LOGGING
    bFunction     AS BYTE
    BufferAddress AS DWORD
    BufferSize    AS DWORD
END TYPE

'
' Disk logging functions
'
' Start disk logging. Only the Function and BufferSize fields are valid.
'

%DISK_LOGGING_START  = 0

'
' Stop disk logging. Only the Function field is valid.
'

%DISK_LOGGING_STOP   = 1

'
' Return disk log. All fields are valid. Data will be copied from internal
' buffer to buffer specified for the number of bytes requested.
'

%DISK_LOGGING_DUMP   = 2

'
' DISK BINNING
'
' DISKPERF will keep counters for IO that falls in each of these ranges.
' The application determines the number and size of the ranges.
' Joe Lin wanted me to keep it flexible as possible, for instance, IO
' sizes are interesting in ranges like 0-4096, 4097-16384, 16385-65536, 65537+.
'

%DISK_BINNING        = 3

'
' Bin types
'

MACRO BIN_TYPES_enum=LONG
ENUM BIN_TYPES SINGULAR
    RequestSize
    RequestLocation
END ENUM

'
' Bin ranges
'

TYPE BIN_RANGE
    StartValue AS QUAD
    Length     AS QUAD
END TYPE

'
' Bin definition
'

TYPE PERF_BIN
    NumberOfBins  AS DWORD
    TypeOfBin     AS DWORD
    BinsRanges(0) AS BIN_RANGE
END TYPE

'
' Bin count
'

TYPE BIN_COUNT
    BinRange AS BIN_RANGE
    BinCount AS DWORD
END TYPE

'
' Bin results
'

TYPE BIN_RESULTS
    NumberOfBins AS DWORD
    BinCounts(0) AS BIN_COUNT
END TYPE

#IF %WIN32_WINNT >= &H0400

'
' Data structures for SMART drive fault prediction.
'
' GETVERSIONINPARAMS contains the data returned from the
' Get Driver Version function.
'

TYPE GETVERSIONINPARAMS BYTE
    bVersion      AS BYTE    ' Binary driver version.
    bRevision     AS BYTE    ' Binary driver revision.
    bReserved     AS BYTE    ' Not used.
    bIDEDeviceMap AS BYTE    ' Bit map of IDE devices.
    fCapabilities AS DWORD   ' Bit mask of driver capabilities.
    dwReserved(3) AS DWORD   ' For future use.
END TYPE

'
' Bits returned in the fCapabilities member of GETVERSIONINPARAMS
'

%CAP_ATA_ID_CMD   = 1       ' ATA ID command supported
%CAP_ATAPI_ID_CMD = 2       ' ATAPI ID command supported
%CAP_SMART_CMD    = 4       ' SMART commannds supported

'
' IDE registers
'

TYPE IDEREGS BYTE
    bFeaturesReg     AS BYTE   ' Used for specifying SMART "commands".
    bSectorCountReg  AS BYTE   ' IDE sector count register
    bSectorNumberReg AS BYTE   ' IDE sector number register
    bCylLowReg       AS BYTE   ' IDE low order cylinder value
    bCylHighReg      AS BYTE   ' IDE high order cylinder value
    bDriveHeadReg    AS BYTE   ' IDE drive/head register
    bCommandReg      AS BYTE   ' Actual IDE command.
    bReserved        AS BYTE   ' reserved for future use.  Must be zero.
END TYPE

'
' Valid values for the bCommandReg member of IDEREGS.
'

%ATAPI_ID_CMD   = &H0A1        ' Returns ID sector for ATAPI.
%ID_CMD         = &H0EC        ' Returns ID sector for ATA.
%SMART_CMD      = &H0B0        ' Performs SMART cmd.
                               ' Requires valid bFeaturesReg,
                               ' bCylLowReg, and bCylHighReg

'
' Cylinder register defines for SMART command
'

%SMART_CYL_LOW  = &H04F
%SMART_CYL_HI   = &H0C2


'
' SENDCMDINPARAMS contains the input parameters for the
' Send Command to Drive function.
'

TYPE SENDCMDINPARAMS BYTE
    cBufferSize   AS DWORD     ' Buffer size in bytes
    irDriveRegs   AS IDEREGS   ' Structure with drive register values.
    bDriveNumber  AS BYTE      ' Physical drive number to send
                               ' command to (0,1,2,3).
    bReserved(2)  AS BYTE      ' Reserved for future expansion.
    dwReserved(3) AS DWORD     ' For future use.
    bBuffer(0)    AS BYTE      ' Input buffer.
END TYPE

'
' Status returned from driver
'

TYPE DRIVERSTATUS BYTE
    bDriverError  AS BYTE     ' Error code from driver,
                              ' or 0 if no error.
    bIDEError     AS BYTE     ' Contents of IDE Error register.
                              ' Only valid when bDriverError
                              ' is SMART_IDE_ERROR.
    bReserved(1)  AS BYTE     ' Reserved for future expansion.
    dwReserved(1) AS DWORD    ' Reserved for future expansion.
END TYPE

'
' bDriverError values
'

%SMART_NO_ERROR         = 0       ' No error
%SMART_IDE_ERROR        = 1       ' Error from IDE controller
%SMART_INVALID_FLAG     = 2       ' Invalid command flag
%SMART_INVALID_COMMAND  = 3       ' Invalid command byte
%SMART_INVALID_BUFFER   = 4       ' Bad buffer (null, invalid addr..)
%SMART_INVALID_DRIVE    = 5       ' Drive number not valid
%SMART_INVALID_IOCTL    = 6       ' Invalid IOCTL
%SMART_ERROR_NO_MEM     = 7       ' Could not lock user's buffer
%SMART_INVALID_REGISTER = 8       ' Some IDE Register not valid
%SMART_NOT_SUPPORTED    = 9       ' Invalid cmd flag set
%SMART_NO_IDE_DEVICE    = 10      ' Cmd issued to device not present
                                        ' although drive number is valid
'
' SMART sub commands for execute offline diags
'
%SMART_OFFLINE_ROUTINE_OFFLINE   = 0
%SMART_SHORT_SELFTEST_OFFLINE    = 1
%SMART_EXTENDED_SELFTEST_OFFLINE = 2
%SMART_ABORT_OFFLINE_SELFTEST    = 127
%SMART_SHORT_SELFTEST_CAPTIVE    = 129
%SMART_EXTENDED_SELFTEST_CAPTIVE = 130


TYPE SENDCMDOUTPARAMS BYTE
    cBufferSize  AS DWORD         ' Size of bBuffer in bytes
    DriverStatus AS DRIVERSTATUS  ' Driver status structure.
    bBuffer(0)   AS BYTE          ' Buffer of arbitrary length in which
                                  ' to store the data read from the drive.
END TYPE


%READ_ATTRIBUTE_BUFFER_SIZE = 512
%IDENTIFY_BUFFER_SIZE       = 512
%READ_THRESHOLD_BUFFER_SIZE = 512
%SMART_LOG_SECTOR_SIZE      = 512

'
' Feature register defines for SMART "sub commands"
'

%READ_ATTRIBUTES         = &H0D0
%READ_THRESHOLDS         = &H0D1
%ENABLE_DISABLE_AUTOSAVE = &H0D2
%SAVE_ATTRIBUTE_VALUES   = &H0D3
%EXECUTE_OFFLINE_DIAGS   = &H0D4
%SMART_READ_LOG          = &H0D5
%SMART_WRITE_LOG         = &H0D6
%ENABLE_SMART            = &H0D8
%DISABLE_SMART           = &H0D9
%RETURN_SMART_STATUS     = &H0DA
%ENABLE_DISABLE_AUTO_OFFLINE = &H0DB

#ENDIF  ' #IF %WIN32_WINNT >= &H0400


%IOCTL_CHANGER_BASE      = %FILE_DEVICE_CHANGER

%IOCTL_CHANGER_GET_PARAMETERS         = &H00304000  ' CTL_CODE(IOCTL_CHANGER_BASE, &H0000, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_CHANGER_GET_STATUS             = &H00304004  ' CTL_CODE(IOCTL_CHANGER_BASE, &H0001, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_CHANGER_GET_PRODUCT_DATA       = &H00304008  ' CTL_CODE(IOCTL_CHANGER_BASE, &H0002, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_CHANGER_SET_ACCESS             = &H0030C010  ' CTL_CODE(IOCTL_CHANGER_BASE, &H0004, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_CHANGER_GET_ELEMENT_STATUS     = &H0030C014  ' CTL_CODE(IOCTL_CHANGER_BASE, &H0005, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_CHANGER_INITIALIZE_ELEMENT_STATUS  = &H00304018  ' CTL_CODE(IOCTL_CHANGER_BASE, &H0006, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_CHANGER_SET_POSITION           = &H0030401C  ' CTL_CODE(IOCTL_CHANGER_BASE, &H0007, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_CHANGER_EXCHANGE_MEDIUM        = &H00304020  ' CTL_CODE(IOCTL_CHANGER_BASE, &H0008, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_CHANGER_MOVE_MEDIUM            = &H00304024  ' CTL_CODE(IOCTL_CHANGER_BASE, &H0009, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_CHANGER_REINITIALIZE_TRANSPORT = &H00304028  ' CTL_CODE(IOCTL_CHANGER_BASE, &H000A, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_CHANGER_QUERY_VOLUME_TAGS      = &H0030C02C  ' CTL_CODE(IOCTL_CHANGER_BASE, &H000B, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)



%MAX_VOLUME_ID_SIZE       = 36
%MAX_VOLUME_TEMPLATE_SIZE = 40

%VENDOR_ID_LENGTH         =  8
%PRODUCT_ID_LENGTH        = 16
%REVISION_LENGTH          =  4
%SERIAL_NUMBER_LENGTH     = 32

'
' Common structures describing elements.
'

MACRO ELEMENT_TYPE_enum=LONG
ENUM ELEMENT_TYPE SINGULAR
    AllElements           ' As defined by SCSI
    ChangerTransport      ' As defined by SCSI
    ChangerSlot           ' As defined by SCSI
    ChangerIEPort         ' As defined by SCSI
    ChangerDrive          ' As defined by SCSI
    ChangerDoor           ' Front panel, used to access internal of cabinet.
    ChangerKeypad         ' Keypad/input on front panel.
    ChangerMaxElement     ' Placeholder only. Not a valid type.
END ENUM

TYPE CHANGER_ELEMENT
    ElementType    AS LONG  ' ELEMENT_TYPE
    ElementAddress AS DWORD
END TYPE

TYPE CHANGER_ELEMENT_LIST
    Element          AS CHANGER_ELEMENT
    NumberOfElements AS DWORD
END TYPE


'
' Definitions for  IOCTL_CHANGER_GET_PARAMETERS
'

'
' Definitions for Features0 of GET_CHANGER_PARAMETERS
'

%CHANGER_BAR_CODE_SCANNER_INSTALLED  = &H000000001 ' The medium-changer has a bar code scanner installed.
%CHANGER_INIT_ELEM_STAT_WITH_RANGE   = &H000000002 ' The medium-changer has the ability to initialize elements within a specified range.
%CHANGER_CLOSE_IEPORT                = &H000000004 ' The medium-changer has the ability to close the i/e port door.
%CHANGER_OPEN_IEPORT                 = &H000000008 ' The medium-changer can open the i/e port door.

%CHANGER_STATUS_NON_VOLATILE         = &H000000010 ' The medium-changer uses non-volatile memory for element status information.
%CHANGER_EXCHANGE_MEDIA              = &H000000020 ' The medium-changer supports exchange operations.
%CHANGER_CLEANER_SLOT                = &H000000040 ' The medium-changer has a fixed slot designated for cleaner cartridges.
%CHANGER_LOCK_UNLOCK                 = &H000000080 ' The medium-changer can be (un)secured to (allow)prevent media removal.

%CHANGER_CARTRIDGE_MAGAZINE          = &H000000100 ' The medium-changer uses cartridge magazines for some storage slots.
%CHANGER_MEDIUM_FLIP                 = &H000000200 ' The medium-changer can flip medium.
%CHANGER_POSITION_TO_ELEMENT         = &H000000400 ' The medium-changer can position the transport to a particular element.
%CHANGER_REPORT_IEPORT_STATE         = &H000000800 ' The medium-changer can determine whether media is present
                                                       ' in the IE Port.

%CHANGER_STORAGE_DRIVE               = &H000001000 ' The medium-changer can use a drive as an independent storage element.
%CHANGER_STORAGE_IEPORT              = &H000002000 ' The medium-changer can use a i/e port as an independent storage element.
%CHANGER_STORAGE_SLOT                = &H000004000 ' The medium-changer can use a slot as an independent storage element.
%CHANGER_STORAGE_TRANSPORT           = &H000008000 ' The medium-changer can use a transport as an independent storage element.

%CHANGER_DRIVE_CLEANING_REQUIRED     = &H000010000 ' The drives controlled by the medium changer require periodic cleaning
                                                       ' initiated by an application.
%CHANGER_PREDISMOUNT_EJECT_REQUIRED  = &H000020000 ' The medium-changer requires a drive eject command to be issued, before a changer
                                                       ' move / exchange command can be issued to the drive.

%CHANGER_CLEANER_ACCESS_NOT_VALID    = &H000040000 ' The access bit in GES isn't valid for cleaner cartridges.
%CHANGER_PREMOUNT_EJECT_REQUIRED     = &H000080000 ' The medium-changer requires a drive eject command to be issued
                                                       ' before a move / exchange command can be issued with the drive as src/dst.

%CHANGER_VOLUME_IDENTIFICATION       = &H000100000 ' The medium-changer supports volume identification.
%CHANGER_VOLUME_SEARCH               = &H000200000 ' The medium-changer can search for volume information.
%CHANGER_VOLUME_ASSERT               = &H000400000 ' The medium-changer can verify volume information.
%CHANGER_VOLUME_REPLACE              = &H000800000 ' The medium-changer can replace volume information.
%CHANGER_VOLUME_UNDEFINE             = &H001000000 ' The medium-changer can undefine volume information.

%CHANGER_SERIAL_NUMBER_VALID         = &H004000000 ' The serial number reported in GetProductData is valid
                                                       ' and unique.

%CHANGER_DEVICE_REINITIALIZE_CAPABLE = &H008000000 ' The medium-changer can be issued a ChangerReinitializeUnit.
%CHANGER_KEYPAD_ENABLE_DISABLE       = &H010000000 ' Indicates that the keypad can be enabled/disabled.
%CHANGER_DRIVE_EMPTY_ON_DOOR_ACCESS  = &H020000000 ' Drives must be empty before access via the door is possible.

%CHANGER_RESERVED_BIT                = &H080000000 ' Will be used to indicate Features1 capability bits.


'
' Definitions for Features1 of GET_CHANGER_PARAMETERS
'

%CHANGER_PREDISMOUNT_ALIGN_TO_SLOT   = &H080000001 ' The transport must be prepositioned to the slot prior to ejecting the media.
%CHANGER_PREDISMOUNT_ALIGN_TO_DRIVE  = &H080000002 ' The transport must be prepositioned to the drive prior to ejecting the media.
%CHANGER_CLEANER_AUTODISMOUNT        = &H080000004 ' The device will move the cleaner cartridge back into the slot when cleaning has completed.
%CHANGER_TRUE_EXCHANGE_CAPABLE       = &H080000008 ' Device can do src -> dest2 exchanges.
%CHANGER_SLOTS_USE_TRAYS             = &H080000010 ' Slots have removable trays, requiring multiple moves for inject/eject.
%CHANGER_RTN_MEDIA_TO_ORIGINAL_ADDR  = &H080000020 ' Media must be returned to the slot from which it originated after a move to another element.
%CHANGER_CLEANER_OPS_NOT_SUPPORTED   = &H080000040 ' Automated cleaning operations are not supported on this device.
%CHANGER_IEPORT_USER_CONTROL_OPEN    = &H080000080 ' Indicates that user action is necessary to open a closed ieport.
%CHANGER_IEPORT_USER_CONTROL_CLOSE   = &H080000100 ' Indicates that user action is necessary to close an opened ieport.
%CHANGER_MOVE_EXTENDS_IEPORT         = &H080000200 ' Indicates that a move media to the ieport extends the tray.
%CHANGER_MOVE_RETRACTS_IEPORT        = &H080000400 ' Indicates that a move media from the ieport retracts the tray.


'
' Definitions for MoveFrom, ExchangeFrom, and PositionCapabilities
'

%CHANGER_TO_TRANSPORT    = &H01 ' The device can carry out the operation to a transport from the specified element.
%CHANGER_TO_SLOT         = &H02 ' The device can carry out the operation to a slot from the specified element.
%CHANGER_TO_IEPORT       = &H04 ' The device can carry out the operation to an IE Port from the specified element.
%CHANGER_TO_DRIVE        = &H08 ' The device can carry out the operation to a drive from the specified element.

'
' Definitions for LockUnlockCapabilities
'

%LOCK_UNLOCK_IEPORT      = &H01 ' The device can lock/unlock the ieport(s).
%LOCK_UNLOCK_DOOR        = &H02 ' The device can lock/unlock the door(s).
%LOCK_UNLOCK_KEYPAD      = &H04 ' The device can lock/unlock the keypad.

TYPE GET_CHANGER_PARAMETERS

    '
    ' Size of the structure. Can be used for versioning.
    '

    SIZE AS DWORD

    '
    ' Number of N element(s) as defined by the Element Address Page (or equivalent...).
    '

    NumberTransportElements AS WORD
    NumberStorageElements AS WORD                   ' for data cartridges only
    NumberCleanerSlots AS WORD                      ' for cleaner cartridges
    NumberIEElements AS WORD
    NumberDataTransferElements AS WORD

    '
    ' Number of doors/front panels (allows user entry into the cabinet).
    '

    NumberOfDoors AS WORD

    '
    ' The device-specific address (from user manual of the device) of the first N element. Used
    ' by the UI to relate the various elements to the user.
    '

    FirstSlotNumber AS WORD
    FirstDriveNumber AS WORD
    FirstTransportNumber AS WORD
    FirstIEPortNumber AS WORD
    FirstCleanerSlotAddress AS WORD

    '
    ' Indicates the capacity of each magazine, if they exist.
    '

    MagazineSize AS WORD

    '
    ' Specifies the approximate number of seconds for when a cleaning should be completed.
    ' Only applicable if drive cleaning is supported. See Features0.
    '

    DriveCleanTimeout AS DWORD

    '
    ' See features bits, above.
    '

    Features0 AS DWORD
    Features1 AS DWORD

    '
    ' Bitmask defining Move from N element to element. Defined by Device Capabilities Page (or equivalent).
    ' AND-masking with the TO_XXX values will indicate legal destinations.
    '

    MoveFromTransport AS BYTE
    MoveFromSlot AS BYTE
    MoveFromIePort AS BYTE
    MoveFromDrive AS BYTE

    '
    ' Bitmask defining Exchange from N element to element. Defined by Device Capabilities Page (or equivalent).
    ' AND-masking with the TO_XXX values will indicate legal destinations.
    '

    ExchangeFromTransport AS BYTE
    ExchangeFromSlot AS BYTE
    ExchangeFromIePort AS BYTE
    ExchangeFromDrive AS BYTE

    '
    ' Bitmask defining which elements are capable of lock/unlock. Valid only if
    ' CHANGER_LOCK_UNLOCK is set in Features0.
    '

    LockUnlockCapabilities AS BYTE

    '
    ' Bitmask defining which elements valid for positioning operations. Valid only if
    ' CHANGER_POSITION_TO_ELEMENT is set in Features0.
    '

    PositionCapabilities AS BYTE

    '
    ' For future expansion.
    '

    Reserved1(1) AS BYTE
    Reserved2(1) AS DWORD

END TYPE


'
' Definitions for IOCTL_CHANGER_GET_PRODUCT_DATA
'

TYPE CHANGER_PRODUCT_DATA

    '
    ' Device manufacturer's name - based on inquiry data
    '

    VendorId(%VENDOR_ID_LENGTH - 1) AS BYTE

    '
    ' Product identification as defined by the vendor - based on Inquiry data
    '

    ProductId(%PRODUCT_ID_LENGTH - 1) AS BYTE

    '
    ' Product revision as defined by the vendor.
    '

    Revision(%REVISION_LENGTH - 1) AS BYTE

    '
    ' Vendor unique value used to globally identify this device. Can
    ' be from Vital Product Data, for example.
    '

    SerialNumber(%SERIAL_NUMBER_LENGTH - 1) AS BYTE

    '
    ' Indicates device type of data transports, as defined by SCSI-2.
    '

    DeviceType AS BYTE

END TYPE


'
' Definitions for IOCTL_CHANGER_SET_ACCESS
'

%LOCK_ELEMENT   = 0
%UNLOCK_ELEMENT = 1
%EXTEND_IEPORT  = 2
%RETRACT_IEPORT = 3

TYPE CHANGER_SET_ACCESS

    '
    ' Element can be ChangerIEPort, ChangerDoor, ChangerKeypad
    '

    Element AS CHANGER_ELEMENT

    '
    ' See above for possible operations.
    '

    dControl AS DWORD
END TYPE


'
' Definitions for IOCTL_CHANGER_GET_ELEMENT_STATUS
'

'
' Input buffer.
'

TYPE CHANGER_READ_ELEMENT_STATUS

    '
    ' List describing the elements and range on which to return information.
    '

    ElementList AS CHANGER_ELEMENT_LIST

    '
    ' Indicates whether volume tag information is to be returned.
    '

    VolumeTagInfo AS BYTE
END TYPE

'
' Output buffer.
'

TYPE CHANGER_ELEMENT_STATUS

    '
    ' Element to which this structure refers.
    '

    Element AS CHANGER_ELEMENT

    '
    ' Address of the element from which the media was originally moved.
    ' Valid if ELEMENT_STATUS_SVALID bit of Flags DWORD is set.
    ' Needs to be converted to a zero-based offset from the device-unique value.
    '

    SrcElementAddress AS CHANGER_ELEMENT

    '
    ' See below.
    '

    Flags AS DWORD

    '
    ' See below for possible values.
    '

    ExceptionCode AS DWORD

    '
    ' Scsi Target Id of this element.
    ' Valid only if ELEMENT_STATUS_ID_VALID is set in Flags.
    '

    TargetId AS BYTE

    '
    ' LogicalUnitNumber of this element.
    ' Valid only if ELEMENT_STATUS_LUN_VALID is set in Flags.
    '

    Lun AS BYTE
    Reserved AS WORD

    '
    ' Primary volume identification for the media.
    ' Valid only if ELEMENT_STATUS_PVOLTAG bit is set in Flags.
    '

    PrimaryVolumeID(%MAX_VOLUME_ID_SIZE - 1) AS BYTE

    '
    ' Alternate volume identification for the media.
    ' Valid for two-sided media only, and pertains to the id. of the inverted side.
    ' Valid only if ELEMENT_STATUS_AVOLTAG bit is set in Flags.
    '

    AlternateVolumeID(%MAX_VOLUME_ID_SIZE - 1) AS BYTE

END TYPE

'
' Output buffer. This is same as CHANGER_ELEMENT_STATUS with
' the addition of product info fields. New applications should
' use this struct instead of the older CHANGER_ELEMENT_STATUS
'

TYPE CHANGER_ELEMENT_STATUS_EX

    '
    ' Element to which this structure refers.
    '

    Element AS CHANGER_ELEMENT

    '
    ' Address of the element from which the media was originally moved.
    ' Valid if ELEMENT_STATUS_SVALID bit of Flags DWORD is set.
    ' Needs to be converted to a zero-based offset from the device-unique value.
    '

    SrcElementAddress AS CHANGER_ELEMENT

    '
    ' See below.
    '

    Flags AS DWORD

    '
    ' See below for possible values.
    '

    ExceptionCode AS DWORD

    '
    ' Scsi Target Id of this element.
    ' Valid only if ELEMENT_STATUS_ID_VALID is set in Flags.
    '

    TargetId AS BYTE

    '
    ' LogicalUnitNumber of this element.
    ' Valid only if ELEMENT_STATUS_LUN_VALID is set in Flags.
    '

    Lun AS BYTE
    Reserved AS WORD

    '
    ' Primary volume identification for the media.
    ' Valid only if ELEMENT_STATUS_PVOLTAG bit is set in Flags.
    '

    PrimaryVolumeID(%MAX_VOLUME_ID_SIZE - 1) AS BYTE

    '
    ' Alternate volume identification for the media.
    ' Valid for two-sided media only, and pertains to the id. of the inverted side.
    ' Valid only if ELEMENT_STATUS_AVOLTAG bit is set in Flags.
    '

    AlternateVolumeID(%MAX_VOLUME_ID_SIZE - 1) AS BYTE

    '
    ' Vendor ID
    '
    VendorIdentification(%VENDOR_ID_LENGTH - 1) AS BYTE

    '
    ' Product ID
    '
    ProductIdentification(%PRODUCT_ID_LENGTH - 1) AS BYTE

    '
    ' Serial number
    '
    SerialNumber(%SERIAL_NUMBER_LENGTH - 1) AS BYTE

END TYPE

'
' Possible flag values
'

%ELEMENT_STATUS_FULL      = &H000000001 ' Element contains a unit of media.
%ELEMENT_STATUS_IMPEXP    = &H000000002 ' Media in i/e port was placed there by an operator.
%ELEMENT_STATUS_EXCEPT    = &H000000004 ' Element is in an abnormal state; check ExceptionCode field for more information.
%ELEMENT_STATUS_ACCESS    = &H000000008 ' Access to the i/e port from the medium changer is allowed.
%ELEMENT_STATUS_EXENAB    = &H000000010 ' Export of media is supported.
%ELEMENT_STATUS_INENAB    = &H000000020 ' Import of media is supported.

%ELEMENT_STATUS_PRODUCT_DATA = &H000000040 ' Serial number valid for the drive

%ELEMENT_STATUS_LUN_VALID = &H000001000 ' Lun information is valid.
%ELEMENT_STATUS_ID_VALID  = &H000002000 ' SCSI Id information is valid.
%ELEMENT_STATUS_NOT_BUS   = &H000008000 ' Lun and SCSI Id fields are not on same bus as medium changer.
%ELEMENT_STATUS_INVERT    = &H000400000 ' Media in element was inverted (valid only if ELEMENT_STATUS_SVALID bit is set)
%ELEMENT_STATUS_SVALID    = &H000800000 ' SourceElementAddress field and ELEMENT_STATUS_INVERT bit are valid.

%ELEMENT_STATUS_PVOLTAG   = &H010000000 ' Primary volume information is valid.
%ELEMENT_STATUS_AVOLTAG   = &H020000000 ' Alternate volume information is valid.

'
' ExceptionCode values.
'

%ERROR_LABEL_UNREADABLE    = &H000000001 ' Bar code scanner could not read bar code label.
%ERROR_LABEL_QUESTIONABLE  = &H000000002 ' Label could be invalid due to unit attention condition.
%ERROR_SLOT_NOT_PRESENT    = &H000000004 ' Slot is currently not addressable in the device.
%ERROR_DRIVE_NOT_INSTALLED = &H000000008 ' Drive is not installed.
%ERROR_TRAY_MALFUNCTION    = &H000000010 ' Media tray is malfunctioning/broken.
%ERROR_INIT_STATUS_NEEDED  = &H000000011 ' An Initialize Element Status command is needed.
%ERROR_UNHANDLED_ERROR     = &H0FFFFFFFF ' Unknown error condition


'
' Definitions for IOCTL_CHANGER_INITIALIZE_ELEMENT_STATUS
'

TYPE CHANGER_INITIALIZE_ELEMENT_STATUS

    '
    ' List describing the elements and range on which to initialize.
    '

    ElementList AS CHANGER_ELEMENT_LIST

    '
    ' Indicates whether a bar code scan should be used. Only applicable if
    ' CHANGER_BAR_CODE_SCANNER_INSTALLED is set in Features0 of CHANGER_GET_PARAMETERS.
    '

    BarCodeScan AS BYTE
END TYPE


'
' Definitions for IOCTL_CHANGER_SET_POSITION
'

TYPE CHANGER_SET_POSITION


    '
    ' Indicates which transport to move.
    '

    Transport AS CHANGER_ELEMENT

    '
    ' Indicates the final destination of the transport.
    '

    Destination AS CHANGER_ELEMENT

    '
    ' Indicates whether the media currently carried by Transport, should be flipped.
    '

    Flip AS BYTE
END TYPE


'
' Definitions for IOCTL_CHANGER_EXCHANGE_MEDIUM
'

TYPE CHANGER_EXCHANGE_MEDIUM

    '
    ' Indicates which transport to use for the exchange operation.
    '

    Transport AS CHANGER_ELEMENT

    '
    ' Indicates the source for the media that is to be moved.
    '

    SOURCE AS CHANGER_ELEMENT

    '
    ' Indicates the final destination of the media originally at Source.
    '

    Destination1 AS CHANGER_ELEMENT

    '
    ' Indicates the destination of the media moved from Destination1.
    '

    Destination2 AS CHANGER_ELEMENT

    '
    ' Indicates whether the medium should be flipped.
    '

    Flip1 AS BYTE
    Flip2 AS BYTE
END TYPE


'
' Definitions for IOCTL_CHANGER_MOVE_MEDIUM
'

TYPE CHANGER_MOVE_MEDIUM

    '
    ' Indicates which transport to use for the move operation.
    '

    Transport AS CHANGER_ELEMENT

    '
    ' Indicates the source for the media that is to be moved.
    '

    SOURCE AS CHANGER_ELEMENT

    '
    ' Indicates the destination of the media originally at Source.
    '

    Destination AS CHANGER_ELEMENT

    '
    ' Indicates whether the media should be flipped.
    '

    Flip AS BYTE
END TYPE



'
' Definitions for IOCTL_QUERY_VOLUME_TAGS
'

'
' Input buffer.
'

TYPE CHANGER_SEND_VOLUME_TAG_INFORMATION

    '
    ' Describes the starting element for which to return information.
    '

    StartingElement AS CHANGER_ELEMENT

    '
    ' Indicates the specific action to perform. See below.
    '

    ActionCode AS DWORD

    '
    ' Template used by the device to search for volume ids.
    '

    VolumeIDTemplate(%MAX_VOLUME_TEMPLATE_SIZE - 1) AS BYTE
END TYPE


'
' Output buffer.
'

TYPE READ_ELEMENT_ADDRESS_INFO

    '
    ' Number of elements matching criteria set forth by ActionCode.
    '

    NumberOfElements AS DWORD

    '
    ' Array of CHANGER_ELEMENT_STATUS structures, one for each element that corresponded
    ' with the information passed in with the CHANGER_SEND_VOLUME_TAG_INFORMATION structure.
    '

    ElementStatus(0) AS CHANGER_ELEMENT_STATUS
END TYPE

'
' Possible ActionCode values. See Features0 of CHANGER_GET_PARAMETERS for compatibility with
' the current device.
'

%SEARCH_ALL         = &H00 ' Translate - search all defined volume tags.
%SEARCH_PRIMARY     = &H01 ' Translate - search only primary volume tags.
%SEARCH_ALTERNATE   = &H02 ' Translate - search only alternate volume tags.
%SEARCH_ALL_NO_SEQ  = &H04 ' Translate - search all defined volume tags but ignore sequence numbers.
%SEARCH_PRI_NO_SEQ  = &H05 ' Translate - search only primary volume tags but ignore sequence numbers.
%SEARCH_ALT_NO_SEQ  = &H06 ' Translate - search only alternate volume tags but ignore sequence numbers.

%ASSERT_PRIMARY     = &H08 ' Assert - as the primary volume tag - if tag now undefined.
%ASSERT_ALTERNATE   = &H09 ' Assert - as the alternate volume tag - if tag now undefined.

%REPLACE_PRIMARY    = &H0A ' Replace - the primary volume tag - current tag ignored.
%REPLACE_ALTERNATE  = &H0B ' Replace - the alternate volume tag - current tag ignored.

%UNDEFINE_PRIMARY   = &H0C ' Undefine - the primary volume tag - current tag ignored.
%UNDEFINE_ALTERNATE = &H0D ' Undefine - the alternate volume tag - current tag ignored.


'
' Changer diagnostic test related definitions
'
MACRO CHANGER_DEVICE_PROBLEM_TYPE_enum=LONG
ENUM CHANGER_DEVICE_PROBLEM_TYPE SINGULAR
    DeviceProblemNone
    DeviceProblemHardware
    DeviceProblemCHMError
    DeviceProblemDoorOpen
    DeviceProblemCalibrationError
    DeviceProblemTargetFailure
    DeviceProblemCHMMoveError
    DeviceProblemCHMZeroError
    DeviceProblemCartridgeInsertError
    DeviceProblemPositionError
    DeviceProblemSensorError
    DeviceProblemCartridgeEjectError
    DeviceProblemGripperError
    DeviceProblemDriveError
END ENUM

%IOCTL_SERIAL_LSRMST_INSERT    = &H001B007C  ' CTL_CODE(FILE_DEVICE_SERIAL_PORT,31,METHOD_BUFFERED,FILE_ANY_ACCESS)

%IOCTL_SERENUM_EXPOSE_HARDWARE = &H00370200  ' CTL_CODE(FILE_DEVICE_SERENUM,128,METHOD_BUFFERED,FILE_ANY_ACCESS)
%IOCTL_SERENUM_REMOVE_HARDWARE = &H00370204  ' CTL_CODE(FILE_DEVICE_SERENUM,129,METHOD_BUFFERED,FILE_ANY_ACCESS)
%IOCTL_SERENUM_PORT_DESC       = &H00370208  ' CTL_CODE(FILE_DEVICE_SERENUM,130,METHOD_BUFFERED,FILE_ANY_ACCESS)
%IOCTL_SERENUM_GET_PORT_NAME   = &H0037020C  ' CTL_CODE(FILE_DEVICE_SERENUM,131,METHOD_BUFFERED,FILE_ANY_ACCESS)



'
' The following values follow the escape designator in the
' data stream if the LSRMST_INSERT mode has been turned on.
'
%SERIAL_LSRMST_ESCAPE     = &H00

'
' Following this value is the contents of the line status
' register, and then the character in the RX hardware when
' the line status register was encountered.
'
%SERIAL_LSRMST_LSR_DATA   = &H01

'
' Following this value is the contents of the line status
' register.  No error character follows
'
%SERIAL_LSRMST_LSR_NODATA = &H02

'
' Following this value is the contents of the modem status
' register.
'
%SERIAL_LSRMST_MST        = &H03

'
' Bit values for FIFO Control Register
'

%SERIAL_IOC_FCR_FIFO_ENABLE      = &H00000001
%SERIAL_IOC_FCR_RCVR_RESET       = &H00000002
%SERIAL_IOC_FCR_XMIT_RESET       = &H00000004
%SERIAL_IOC_FCR_DMA_MODE         = &H00000008
%SERIAL_IOC_FCR_RES1             = &H00000010
%SERIAL_IOC_FCR_RES2             = &H00000020
%SERIAL_IOC_FCR_RCVR_TRIGGER_LSB = &H00000040
%SERIAL_IOC_FCR_RCVR_TRIGGER_MSB = &H00000080

'
' Bit values for Modem Control Register
'

%SERIAL_IOC_MCR_DTR              = &H00000001
%SERIAL_IOC_MCR_RTS              = &H00000002
%SERIAL_IOC_MCR_OUT1             = &H00000004
%SERIAL_IOC_MCR_OUT2             = &H00000008
%SERIAL_IOC_MCR_LOOP             = &H00000010

#IF NOT %DEF(%FILESYSTEMFSCTL)

%FILESYSTEMFSCTL = 1

'
' The following is a list of the native file system fsctls followed by
' additional network file system fsctls.  Some values have been
' decommissioned.
'

%FSCTL_REQUEST_OPLOCK_LEVEL_1    = &H00090000  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  0, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_REQUEST_OPLOCK_LEVEL_2    = &H00090004  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  1, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_REQUEST_BATCH_OPLOCK      = &H00090008  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  2, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_OPLOCK_BREAK_ACKNOWLEDGE  = &H0009000C  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  3, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_OPBATCH_ACK_CLOSE_PENDING = &H00090010  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  4, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_OPLOCK_BREAK_NOTIFY       = &H00090014  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  5, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_LOCK_VOLUME               = &H00090018  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  6, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_UNLOCK_VOLUME             = &H0009001C  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  7, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_DISMOUNT_VOLUME           = &H00090020  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  8, METHOD_BUFFERED, FILE_ANY_ACCESS)
' decommissioned fsctl value                                              9
%FSCTL_IS_VOLUME_MOUNTED         = &H00090028  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 10, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_IS_PATHNAME_VALID         = &H0009002C  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 11, METHOD_BUFFERED, FILE_ANY_ACCESS) ' PATHNAME_BUFFER,
%FSCTL_MARK_VOLUME_DIRTY         = &H00090030  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 12, METHOD_BUFFERED, FILE_ANY_ACCESS)
' decommissioned fsctl value                                             13
%FSCTL_QUERY_RETRIEVAL_POINTERS  = &H0009003B  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 14,  METHOD_NEITHER, FILE_ANY_ACCESS)
%FSCTL_GET_COMPRESSION           = &H0009003C  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 15, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_SET_COMPRESSION           = &H0009C040  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 16, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA)
' decommissioned fsctl value                                             17
' decommissioned fsctl value                                             18
%FSCTL_MARK_AS_SYSTEM_HIVE       = &H0009004F  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 19,  METHOD_NEITHER, FILE_ANY_ACCESS)
%FSCTL_OPLOCK_BREAK_ACK_NO_2     = &H00090050  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 20, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_INVALIDATE_VOLUMES        = &H00090054  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 21, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_QUERY_FAT_BPB             = &H00090058  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 22, METHOD_BUFFERED, FILE_ANY_ACCESS) ' FSCTL_QUERY_FAT_BPB_BUFFER
%FSCTL_REQUEST_FILTER_OPLOCK     = &H0009005C  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 23, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_FILESYSTEM_GET_STATISTICS = &H00090060  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 24, METHOD_BUFFERED, FILE_ANY_ACCESS) ' FILESYSTEM_STATISTICS
#IF %WIN32_WINNT >= &H0400
%FSCTL_GET_NTFS_VOLUME_DATA      = &H00090064  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 25, METHOD_BUFFERED, FILE_ANY_ACCESS) ' NTFS_VOLUME_DATA_BUFFER
%FSCTL_GET_NTFS_FILE_RECORD      = &H00090068  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 26, METHOD_BUFFERED, FILE_ANY_ACCESS) ' NTFS_FILE_RECORD_INPUT_BUFFER, NTFS_FILE_RECORD_OUTPUT_BUFFER
%FSCTL_GET_VOLUME_BITMAP         = &H0009006F  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 27,  METHOD_NEITHER, FILE_ANY_ACCESS) ' STARTING_LCN_INPUT_BUFFER, VOLUME_BITMAP_BUFFER
%FSCTL_GET_RETRIEVAL_POINTERS    = &H00090073  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 28,  METHOD_NEITHER, FILE_ANY_ACCESS) ' STARTING_VCN_INPUT_BUFFER, RETRIEVAL_POINTERS_BUFFER
%FSCTL_MOVE_FILE                 = &H00090074  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 29, METHOD_BUFFERED, FILE_SPECIAL_ACCESS) ' MOVE_FILE_DATA,
%FSCTL_IS_VOLUME_DIRTY           = &H00090078  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 30, METHOD_BUFFERED, FILE_ANY_ACCESS)
' decomissioned fsctl value                                              31
%FSCTL_ALLOW_EXTENDED_DASD_IO    = &H00090083  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 32, METHOD_NEITHER,  FILE_ANY_ACCESS)

#ENDIF  ' #IF %WIN32_WINNT >= &H0400

#IF %WIN32_WINNT >= &H0500
' decommissioned fsctl value                                             33
' decommissioned fsctl value                                             34
%FSCTL_FIND_FILES_BY_SID         = &H0009008F  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 35, METHOD_NEITHER, FILE_ANY_ACCESS)
' decommissioned fsctl value                                             36
' decommissioned fsctl value                                             37
%FSCTL_SET_OBJECT_ID             = &H00090098  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 38, METHOD_BUFFERED, FILE_SPECIAL_ACCESS) ' FILE_OBJECTID_BUFFER
%FSCTL_GET_OBJECT_ID             = &H0009009C  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 39, METHOD_BUFFERED, FILE_ANY_ACCESS) ' FILE_OBJECTID_BUFFER
%FSCTL_DELETE_OBJECT_ID          = &H000900A0  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 40, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
%FSCTL_SET_REPARSE_POINT         = &H000900A4  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 41, METHOD_BUFFERED, FILE_SPECIAL_ACCESS) ' REPARSE_DATA_BUFFER,
%FSCTL_GET_REPARSE_POINT         = &H000900A8  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 42, METHOD_BUFFERED, FILE_ANY_ACCESS) ' REPARSE_DATA_BUFFER
%FSCTL_DELETE_REPARSE_POINT      = &H000900AC  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 43, METHOD_BUFFERED, FILE_SPECIAL_ACCESS) ' REPARSE_DATA_BUFFER,
%FSCTL_ENUM_USN_DATA             = &H000900B3  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 44,  METHOD_NEITHER, FILE_ANY_ACCESS) ' MFT_ENUM_DATA,
%FSCTL_SECURITY_ID_CHECK         = &H000940B7  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 45,  METHOD_NEITHER, FILE_READ_DATA)  ' BULK_SECURITY_TEST_DATA,
%FSCTL_READ_USN_JOURNAL          = &H000900BB  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 46,  METHOD_NEITHER, FILE_ANY_ACCESS) ' READ_USN_JOURNAL_DATA, USN
%FSCTL_SET_OBJECT_ID_EXTENDED    = &H000900BC  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 47, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
%FSCTL_CREATE_OR_GET_OBJECT_ID   = &H000900C0  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 48, METHOD_BUFFERED, FILE_ANY_ACCESS) ' FILE_OBJECTID_BUFFER
%FSCTL_SET_SPARSE                = &H000900C4  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 49, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
%FSCTL_SET_ZERO_DATA             = &H000980C8  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 50, METHOD_BUFFERED, FILE_WRITE_DATA) ' FILE_ZERO_DATA_INFORMATION,
%FSCTL_QUERY_ALLOCATED_RANGES    = &H000940CF  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 51,  METHOD_NEITHER, FILE_READ_DATA)  ' FILE_ALLOCATED_RANGE_BUFFER, FILE_ALLOCATED_RANGE_BUFFER
' decommissioned fsctl value                                             52
%FSCTL_SET_ENCRYPTION            = &H000900D7  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 53,  METHOD_NEITHER, FILE_ANY_ACCESS) ' ENCRYPTION_BUFFER, DECRYPTION_STATUS_BUFFER
%FSCTL_ENCRYPTION_FSCTL_IO       = &H000900DB  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 54,  METHOD_NEITHER, FILE_ANY_ACCESS)
%FSCTL_WRITE_RAW_ENCRYPTED       = &H000900DF  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 55,  METHOD_NEITHER, FILE_SPECIAL_ACCESS) ' ENCRYPTED_DATA_INFO,
%FSCTL_READ_RAW_ENCRYPTED        = &H000900E3  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 56,  METHOD_NEITHER, FILE_SPECIAL_ACCESS) ' REQUEST_RAW_ENCRYPTED_DATA, ENCRYPTED_DATA_INFO
%FSCTL_CREATE_USN_JOURNAL        = &H000900E7  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 57,  METHOD_NEITHER, FILE_ANY_ACCESS) ' CREATE_USN_JOURNAL_DATA,
%FSCTL_READ_FILE_USN_DATA        = &H000900EB  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 58,  METHOD_NEITHER, FILE_ANY_ACCESS) ' Read the Usn Record for a file
%FSCTL_WRITE_USN_CLOSE_RECORD    = &H000900EF  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 59,  METHOD_NEITHER, FILE_ANY_ACCESS) ' Generate Close Usn Record
%FSCTL_EXTEND_VOLUME             = &H000900F0  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 60, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_QUERY_USN_JOURNAL         = &H000900F4  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 61, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_DELETE_USN_JOURNAL        = &H000900F8  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 62, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_MARK_HANDLE               = &H000900FC  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 63, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_SIS_COPYFILE              = &H00090100  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 64, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_SIS_LINK_FILES            = &H0009C104  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 65, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA)
%FSCTL_HSM_MSG                   = &H0009C108  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 66, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA)
' decommissioned fsctl value                                             67
%FSCTL_HSM_DATA                  = &H0009C113  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 68, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)
%FSCTL_RECALL_FILE               = &H00090117  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 69, METHOD_NEITHER, FILE_ANY_ACCESS)
' decommissioned fsctl value                                             70
%FSCTL_READ_FROM_PLEX            = &H0009411E  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 71, METHOD_OUT_DIRECT, FILE_READ_DATA)
%FSCTL_FILE_PREFETCH             = &H00090120  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 72, METHOD_BUFFERED, FILE_SPECIAL_ACCESS) ' FILE_PREFETCH

#ENDIF  ' #IF %WIN32_WINNT >= &H0500

'
' The following long list of structs are associated with the preceeding
' file system fsctls.
'

'
' Structure for FSCTL_IS_PATHNAME_VALID
'

TYPE PATHNAME_BUFFER
    PathNameLength AS DWORD
    wName          AS STRING * 2  ' Unicode
END TYPE

'
' Structure for FSCTL_QUERY_BPB_INFO
'

TYPE FSCTL_QUERY_FAT_BPB_BUFFER
    First0x24BytesOfBootSector(&H23) AS BYTE
END TYPE

#IF %WIN32_WINNT >= &H0400
'
' Structures for FSCTL_GET_NTFS_VOLUME_DATA.
' The user must pass the basic buffer below.  Ntfs
' will return as many fields as available in the extended
' buffer which follows immediately after the VOLUME_DATA_BUFFER.
'

TYPE NTFS_VOLUME_DATA_BUFFER
    VolumeSerialNumber           AS QUAD
    NumberSectors                AS QUAD
    TotalClusters                AS QUAD
    FreeClusters                 AS QUAD
    TotalReserved                AS QUAD
    BytesPerSector               AS DWORD
    BytesPerCluster              AS DWORD
    BytesPerFileRecordSegment    AS DWORD
    ClustersPerFileRecordSegment AS DWORD
    MftValidDataLength           AS QUAD
    MftStartLcn                  AS QUAD
    Mft2StartLcn                 AS QUAD
    MftZoneStart                 AS QUAD
    MftZoneEnd                   AS QUAD
END TYPE

TYPE NTFS_EXTENDED_VOLUME_DATA
    ByteCount    AS DWORD
    MajorVersion AS WORD
    MinorVersion AS WORD
END TYPE

#ENDIF  ' #IF %WIN32_WINNT >= &H0400


#IF %WIN32_WINNT >= &H0400
'
' Structure for FSCTL_GET_VOLUME_BITMAP
'

TYPE STARTING_LCN_INPUT_BUFFER
    StartingLcn AS QUAD
END TYPE

TYPE VOLUME_BITMAP_BUFFER
    StartingLcn AS QUAD
    BitmapSize  AS QUAD
    BUFFER(0)   AS BYTE
END TYPE

#ENDIF  ' #IF %WIN32_WINNT >= &H0400


#IF %WIN32_WINNT >= &H0400
'
' Structure for FSCTL_GET_RETRIEVAL_POINTERS
'

TYPE STARTING_VCN_INPUT_BUFFER
    StartingVcn AS QUAD
END TYPE

TYPE RPBExtents
    NextVcn AS QUAD
    Lcn AS QUAD
END TYPE

TYPE RETRIEVAL_POINTERS_BUFFER
    ExtentCount AS DWORD
    StartingVcn AS QUAD
    RPBExtents
END TYPE

#ENDIF  ' #IF %WIN32_WINNT >= &H0400


#IF %WIN32_WINNT >= &H0400
'
' Structures for FSCTL_GET_NTFS_FILE_RECORD
'

TYPE NTFS_FILE_RECORD_INPUT_BUFFER
    FileReferenceNumber AS QUAD
END TYPE

TYPE NTFS_FILE_RECORD_OUTPUT_BUFFER
    FileReferenceNumber AS QUAD
    FileRecordLength    AS DWORD
    FileRecordBuffer(0) AS BYTE
END TYPE

#ENDIF  ' #IF %WIN32_WINNT >= &H0400


#IF %WIN32_WINNT >= &H0400
'
' Structure for FSCTL_MOVE_FILE
'

TYPE MOVE_FILE_DATA
    FileHandle   AS DWORD
    StartingVcn  AS QUAD
    StartingLcn  AS QUAD
    ClusterCount AS DWORD
END TYPE

#ENDIF  ' #IF %WIN32_WINNT >= &H0400


#IF %WIN32_WINNT >= &H0500
'
' Structure for FSCTL_FIND_FILES_BY_SID
'

TYPE FIND_BY_SID_DATA
    Restart AS DWORD
    FindSid AS SID
END TYPE

#ENDIF  ' #IF %WIN32_WINNT >= &H0500


#IF %WIN32_WINNT >= &H0500
'
'  The following structures apply to Usn operations.
'

'
' Structure for FSCTL_ENUM_USN_DATA
'

TYPE MFT_ENUM_DATA
    StartFileReferenceNumber AS QUAD ' DWORDLONG
    LowUsn                   AS QUAD ' USN
    HighUsn                  AS QUAD ' USN
END TYPE

'
' Structure for FSCTL_CREATE_USN_JOURNAL
'

TYPE CREATE_USN_JOURNAL_DATA
    MaximumSize AS QUAD ' DWORDLONG
    AllocationDelta AS QUAD ' DWORDLONG
END TYPE

'
' Structure for FSCTL_READ_USN_JOURNAL
'

TYPE READ_USN_JOURNAL_DATA
    StartUsn          AS QUAD ' USN
    ReasonMask        AS DWORD
    ReturnOnlyOnClose AS DWORD
    qTimeout          AS QUAD ' DWORDLONG
    BytesToWaitFor    AS QUAD ' DWORDLONG
    UsnJournalID      AS QUAD ' DWORDLONG
END TYPE

'
'  The initial Major.Minor version of the Usn record will be 2.0.
'  In general, the MinorVersion may be changed if fields are added
'  to this structure in such a way that the previous version of the
'  software can still correctly the fields it knows about.  The
'  MajorVersion should only be changed if the previous version of
'  any software using this structure would incorrectly handle new
'  records due to structure changes.
'
'  The first update to this will force the structure to version 2.0.
'  This will add the extended information about the source as
'  well as indicate the file name offset within the structure.
'
'  The following structure is returned with these fsctls.
'
'      FSCTL_READ_USN_JOURNAL
'      FSCTL_READ_FILE_USN_DATA
'      FSCTL_ENUM_USN_DATA
'

TYPE USN_RECORD
    RecordLength              AS DWORD
    MajorVersion              AS WORD
    MinorVersion              AS WORD
    FileReferenceNumber       AS QUAD ' DWORDLONG
    ParentFileReferenceNumber AS QUAD ' DWORDLONG
    Usn                       AS QUAD  ' USN
    TimeStamp                 AS QUAD
    Reason                    AS DWORD
    SourceInfo                AS DWORD
    SecurityId                AS DWORD
    FileAttributes            AS DWORD
    FileNameLength            AS WORD
    FileNameOffset            AS WORD
    FileName                  AS WSTRINGZ * 1
END TYPE

%USN_PAGE_SIZE                    = &H01000

%USN_REASON_DATA_OVERWRITE        = &H000000001
%USN_REASON_DATA_EXTEND           = &H000000002
%USN_REASON_DATA_TRUNCATION       = &H000000004
%USN_REASON_NAMED_DATA_OVERWRITE  = &H000000010
%USN_REASON_NAMED_DATA_EXTEND     = &H000000020
%USN_REASON_NAMED_DATA_TRUNCATION = &H000000040
%USN_REASON_FILE_CREATE           = &H000000100
%USN_REASON_FILE_DELETE           = &H000000200
%USN_REASON_EA_CHANGE             = &H000000400
%USN_REASON_SECURITY_CHANGE       = &H000000800
%USN_REASON_RENAME_OLD_NAME       = &H000001000
%USN_REASON_RENAME_NEW_NAME       = &H000002000
%USN_REASON_INDEXABLE_CHANGE      = &H000004000
%USN_REASON_BASIC_INFO_CHANGE     = &H000008000
%USN_REASON_HARD_LINK_CHANGE      = &H000010000
%USN_REASON_COMPRESSION_CHANGE    = &H000020000
%USN_REASON_ENCRYPTION_CHANGE     = &H000040000
%USN_REASON_OBJECT_ID_CHANGE      = &H000080000
%USN_REASON_REPARSE_POINT_CHANGE  = &H000100000
%USN_REASON_STREAM_CHANGE         = &H000200000

%USN_REASON_CLOSE                 = &H080000000

'
'  Structure for FSCTL_QUERY_USN_JOUNAL
'

TYPE USN_JOURNAL_DATA
    UsnJournalID    AS QUAD  ' DWORDLONG
    FirstUsn        AS QUAD  ' USN
    NextUsn         AS QUAD  ' USN
    LowestValidUsn  AS QUAD  ' USN
    MaxUsn          AS QUAD  ' USN
    MaximumSize     AS QUAD  ' DWORDLONG
    AllocationDelta AS QUAD  ' DWORDLONG
END TYPE

'
'  Structure for FSCTL_DELETE_USN_JOURNAL
'

TYPE DELETE_USN_JOURNAL_DATA
    UsnJournalID AS QUAD ' DWORDLONG
    DeleteFlags  AS DWORD
END TYPE

%USN_DELETE_FLAG_DELETE = &H00000001
%USN_DELETE_FLAG_NOTIFY = &H00000002

%USN_DELETE_VALID_FLAGS = &H00000003

'
'  Structure for FSCTL_MARK_HANDLE
'

TYPE MARK_HANDLE_INFO
    UsnSourceInfo AS DWORD
    VolumeHandle  AS DWORD
    HandleInfo    AS DWORD
END TYPE


'
' Flags for the additional source information above.
'
'     USN_SOURCE_DATA_MANAGEMENT - Service is not modifying the external view
'         of any part of the file.  Typical case is HSM moving data to
'         and from external storage.
'
'     USN_SOURCE_AUXILIARY_DATA - Service is not modifying the external view
'         of the file with regard to the application that created this file.
'         Can be used to add private data streams to a file.
'
'     USN_SOURCE_REPLICATION_MANAGEMENT - Service is modifying a file to match
'         the contents of the same file which exists in another member of the
'         replica set.
'

%USN_SOURCE_DATA_MANAGEMENT         = &H00000001
%USN_SOURCE_AUXILIARY_DATA          = &H00000002
%USN_SOURCE_REPLICATION_MANAGEMENT  = &H00000004

'
'  Flags for the HandleInfo field above
'
'  MARK_HANDLE_PROTECT_CLUSTERS - disallow any defragmenting (FSCTL_MOVE_FILE)
'      until the handle is closed
'

%MARK_HANDLE_PROTECT_CLUSTERS       = &H00000001

#ENDIF  ' #IF %WIN32_WINNT >= &H0500


#IF %WIN32_WINNT >= &H0500
'
' Structure for FSCTL_SECURITY_ID_CHECK
'

TYPE BULK_SECURITY_TEST_DATA
    DesiredAccess  AS DWORD  ' ACCESS_MASK
    SecurityIds(0) AS DWORD
END TYPE

#ENDIF  ' #IF %WIN32_WINNT >= &H0500


#IF %WIN32_WINNT >= &H0500
'
'  Output flags for the FSCTL_IS_VOLUME_DIRTY
'

%VOLUME_IS_DIRTY                 = &H00000001
%VOLUME_UPGRADE_SCHEDULED        = &H00000002

#ENDIF  ' #IF %WIN32_WINNT >= &H0500


'
' Structures for FSCTL_FILE_PREFETCH
'

TYPE FILE_PREFETCH
    dType       AS DWORD
    COUNT       AS DWORD
    Prefetch(0) AS QUAD ' DWORDLONG
END TYPE

%FILE_PREFETCH_TYPE_FOR_CREATE = &H1

' Structures for FSCTL_FILESYSTEM_GET_STATISTICS
'
' Filesystem performance counters
'

TYPE FILESYSTEM_STATISTICS

    FileSystemType     AS WORD
    Version            AS WORD             ' currently version 1

    SizeOfCompleteStructure AS DWORD       ' must by a mutiple of 64 bytes

    UserFileReads      AS DWORD
    UserFileReadBytes  AS DWORD
    UserDiskReads      AS DWORD
    UserFileWrites     AS DWORD
    UserFileWriteBytes AS DWORD
    UserDiskWrites     AS DWORD

    MetaDataReads      AS DWORD
    MetaDataReadBytes  AS DWORD
    MetaDataDiskReads  AS DWORD
    MetaDataWrites     AS DWORD
    MetaDataWriteBytes AS DWORD
    MetaDataDiskWrites AS DWORD

    '
    '  The file system's private structure is appended here.
    '

END TYPE

' values for FS_STATISTICS.FileSystemType

%FILESYSTEM_STATISTICS_TYPE_NTFS = 1
%FILESYSTEM_STATISTICS_TYPE_FAT  = 2

'
'  File System Specific Statistics Data
'

TYPE FAT_STATISTICS
    CreateHits          AS DWORD
    SuccessfulCreates   AS DWORD
    FailedCreates       AS DWORD

    NonCachedReads      AS DWORD
    NonCachedReadBytes  AS DWORD
    NonCachedWrites     AS DWORD
    NonCachedWriteBytes AS DWORD

    NonCachedDiskReads  AS DWORD
    NonCachedDiskWrites AS DWORD
END TYPE

TYPE MftWritesUserLevel
    wWrite   AS WORD
    wCreate  AS WORD
    wSetInfo AS WORD
    wFlush   AS WORD
END TYPE

TYPE Mft2WritesUserLevel
    wWrite2   AS WORD
    wCreate2  AS WORD
    wSetInfo2 AS WORD
    wFlush2   AS WORD
END TYPE

TYPE BitmapWritesUserLevel
    wWriteB   AS WORD
    wCreateB  AS WORD
    wSetInfoB AS WORD
END TYPE

TYPE MftBitmapWritesUserLevel
    wWriteMB   AS WORD
    wCreateMB  AS WORD
    wSetInfoMB AS WORD
    wFlushMB   AS WORD
END TYPE

TYPE NTFSStats_Allocate
    Calls             AS DWORD   ' number of individual calls to allocate clusters
    Clusters          AS DWORD   ' number of clusters allocated
    Hints             AS DWORD   ' number of times a hint was specified

    RunsReturned      AS DWORD   ' number of runs used to satisify all the requests

    HintsHonored      AS DWORD   ' number of times the hint was useful
    HintsClusters     AS DWORD   ' number of clusters allocated via the hint
    Cache             AS DWORD   ' number of times the cache was useful other than the hint
    CacheClusters     AS DWORD   ' number of clusters allocated via the cache other than the hint
    CacheMiss         AS DWORD   ' number of times the cache wasn't useful
    CacheMissClusters AS DWORD   ' number of clusters allocated without the cache
END TYPE

TYPE NTFS_STATISTICS
    LogFileFullExceptions AS DWORD
    OtherExceptions       AS DWORD

    '
    ' Other meta data io's
    '

    MftReads      AS DWORD
    MftReadBytes  AS DWORD
    MftWrites     AS DWORD
    MftWriteBytes AS DWORD
    MftWritesUserLevel

    MftWritesFlushForLogFileFull AS WORD
    MftWritesLazyWriter          AS WORD
    MftWritesUserRequest         AS WORD

    Mft2Writes     AS DWORD
    Mft2WriteBytes AS DWORD
    Mft2WritesUserLevel

    Mft2WritesFlushForLogFileFull AS WORD
    Mft2WritesLazyWriter          AS WORD
    Mft2WritesUserRequest         AS WORD

    RootIndexReads      AS DWORD
    RootIndexReadBytes  AS DWORD
    RootIndexWrites     AS DWORD
    RootIndexWriteBytes AS DWORD

    BitmapReads      AS DWORD
    BitmapReadBytes  AS DWORD
    BitmapWrites     AS DWORD
    BitmapWriteBytes AS DWORD

    BitmapWritesFlushForLogFileFull AS WORD
    BitmapWritesLazyWriter          AS WORD
    BitmapWritesUserRequest         AS WORD
    BitmapWritesUserLevel

    MftBitmapReads      AS DWORD
    MftBitmapReadBytes  AS DWORD
    MftBitmapWrites     AS DWORD
    MftBitmapWriteBytes AS DWORD

    MftBitmapWritesFlushForLogFileFull AS WORD
    MftBitmapWritesLazyWriter          AS WORD
    MftBitmapWritesUserRequest         AS WORD
    MftBitmapWritesUserLevel

    UserIndexReads      AS DWORD
    UserIndexReadBytes  AS DWORD
    UserIndexWrites     AS DWORD
    UserIndexWriteBytes AS DWORD

    '
    ' Additions for NT 5.0
    '

    LogFileReads      AS DWORD
    LogFileReadBytes  AS DWORD
    LogFileWrites     AS DWORD
    LogFileWriteBytes AS DWORD
    NTFSStats_Allocate
END TYPE


#IF %WIN32_WINNT >= &H0500
'
' Structure for FSCTL_SET_OBJECT_ID, FSCTL_GET_OBJECT_ID, and FSCTL_CREATE_OR_GET_OBJECT_ID
'

TYPE FILE_OBJECTID_BUFFER_inner
    BirthVolumeId(15) AS BYTE
    BirthObjectId(15) AS BYTE
    DomainId(15)      AS BYTE
END TYPE

TYPE FILE_OBJECTID_BUFFER_union
    FILE_OBJECTID_BUFFER_inner
    ExtendedInfo(47) AS BYTE
END TYPE

TYPE FILE_OBJECTID_BUFFER

    '
    '  This is the portion of the object id that is indexed.
    '

    ObjectId(15) AS BYTE

    '
    '  This portion of the object id is not indexed, it's just
    '  some metadata for the user's benefit.
    '
    FILE_OBJECTID_BUFFER_union

END TYPE

#ENDIF  ' #IF %WIN32_WINNT >= &H0500


#IF %WIN32_WINNT >= &H0500
'
' Structure for FSCTL_SET_SPARSE
'

TYPE FILE_SET_SPARSE_BUFFER
    SetSparse AS BYTE
END TYPE

#ENDIF  ' #IF %WIN32_WINNT >= &H0500


#IF %WIN32_WINNT >= &H0500
'
' Structure for FSCTL_SET_ZERO_DATA
'

TYPE FILE_ZERO_DATA_INFORMATION
    FileOffset      AS QUAD
    BeyondFinalZero AS QUAD
END TYPE

#ENDIF  ' #IF %WIN32_WINNT >= &H0500


#IF %WIN32_WINNT >= &H0500
'
' Structure for FSCTL_QUERY_ALLOCATED_RANGES
'

'
' Querying the allocated ranges requires an output buffer to store the
' allocated ranges and an input buffer to specify the range to query.
' The input buffer contains a single entry, the output buffer is an
' array of the following structure.
'

TYPE FILE_ALLOCATED_RANGE_BUFFER
    FileOffset AS QUAD
    Length     AS QUAD
END TYPE

#ENDIF  ' #IF %WIN32_WINNT >= &H0500


#IF %WIN32_WINNT >= &H0500
'
' Structures for FSCTL_SET_ENCRYPTION, FSCTL_WRITE_RAW_ENCRYPTED, and FSCTL_READ_RAW_ENCRYPTED
'

'
'  The input buffer to set encryption indicates whether we are to encrypt/decrypt a file
'  or an individual stream.
'

TYPE ENCRYPTION_BUFFER
    EncryptionOperation AS DWORD
    PRIVATE(0)          AS BYTE
END TYPE

%FILE_SET_ENCRYPTION       = &H00000001
%FILE_CLEAR_ENCRYPTION     = &H00000002
%STREAM_SET_ENCRYPTION     = &H00000003
%STREAM_CLEAR_ENCRYPTION   = &H00000004

%MAXIMUM_ENCRYPTION_VALUE  = &H00000004

'
'  The optional output buffer to set encryption indicates that the last encrypted
'  stream in a file has been marked as decrypted.
'

TYPE DECRYPTION_STATUS_BUFFER
    NoEncryptedStreams AS BYTE
END TYPE

%ENCRYPTION_FORMAT_DEFAULT = &H01

%COMPRESSION_FORMAT_SPARSE = &H4000

'
'  Request Encrypted Data structure.  This is used to indicate
'  the range of the file to read.  It also describes the
'  output buffer used to return the data.
'

TYPE REQUEST_RAW_ENCRYPTED_DATA

    '
    '  Requested file offset and requested length to read.
    '  The fsctl will round the starting offset down
    '  to a file system boundary.  It will also
    '  round the length up to a file system boundary.
    '

    FileOffset AS QUAD
    Length     AS DWORD

END TYPE

'
'  Encrypted Data Information structure.  This structure
'  is used to return raw encrypted data from a file in
'  order to perform off-line recovery.  The data will be
'  encrypted or encrypted and compressed.  The off-line
'  service will need to use the encryption and compression
'  format information to recover the file data.  In the
'  event that the data is both encrypted and compressed then
'  the decryption must occur before decompression.  All
'  the data units below must be encrypted and compressed
'  with the same format.
'
'  The data will be returned in units.  The data unit size
'  will be fixed per request.  If the data is compressed
'  then the data unit size will be the compression unit size.
'
'  This structure is at the beginning of the buffer used to
'  return the encrypted data.  The actual raw bytes from
'  the file will follow this buffer.  The offset of the
'  raw bytes from the beginning of this structure is
'  specified in the REQUEST_RAW_ENCRYPTED_DATA structure
'  described above.
'

TYPE ENCRYPTED_DATA_INFO

    '
    '  This is the file offset for the first entry in the
    '  data block array.  The file system will round
    '  the requested start offset down to a boundary
    '  that is consistent with the format of the file.
    '

    StartingFileOffset AS QUAD ' DWORDLONG

    '
    '  Data offset in output buffer.  The output buffer
    '  begins with an ENCRYPTED_DATA_INFO structure.
    '  The file system will then store the raw bytes from
    '  disk beginning at the following offset within the
    '  output buffer.
    '

    OutputBufferOffset AS DWORD

    '
    '  The number of bytes being returned that are within
    '  the size of the file.  If this value is less than
    '  (NumberOfDataBlocks << DataUnitShift), it means the
    '  end of the file occurs within this transfer.  Any
    '  data beyond file size is invalid and was never
    '  passed to the encryption driver.
    '

    BytesWithinFileSize AS DWORD

    '
    '  The number of bytes being returned that are below
    '  valid data length.  If this value is less than
    '  (NumberOfDataBlocks << DataUnitShift), it means the
    '  end of the valid data occurs within this transfer.
    '  After decrypting the data from this transfer, any
    '  byte(s) beyond valid data length must be zeroed.
    '

    BytesWithinValidDataLength AS DWORD

    '
    '  Code for the compression format as defined in
    '  ntrtl.h.  Note that COMPRESSION_FORMAT_NONE
    '  and COMPRESSION_FORMAT_DEFAULT are invalid if
    '  any of the described chunks are compressed.
    '

    CompressionFormat AS WORD

    '
    '  The DataUnit is the granularity used to access the
    '  disk.  It will be the same as the compression unit
    '  size for a compressed file.  For an uncompressed
    '  file, it will be some cluster-aligned power of 2 that
    '  the file system deems convenient.  A caller should
    '  not expect that successive calls will have the
    '  same data unit shift value as the previous call.
    '
    '  Since chunks and compression units are expected to be
    '  powers of 2 in size, we express them log2.  So, for
    '  example (1 << ChunkShift) == ChunkSizeInBytes.  The
    '  ClusterShift indicates how much space must be saved
    '  to successfully compress a compression unit - each
    '  successfully compressed data unit must occupy
    '  at least one cluster less in bytes than an uncompressed
    '  data block unit.
    '

    DataUnitShift AS BYTE
    ChunkShift    AS BYTE
    ClusterShift  AS BYTE

    '
    '  The format for the encryption.
    '

    EncryptionFormat AS BYTE

    '
    '  This is the number of entries in the data block size
    '  array.
    '

    NumberOfDataBlocks AS WORD

    '
    '  This is an array of sizes in the data block array.  There
    '  must be one entry in this array for each data block
    '  read from disk.  The size has a different meaning
    '  depending on whether the file is compressed.
    '
    '  A size of zero always indicates that the final data consists entirely
    '  of zeroes.  There is no decryption or decompression to
    '  perform.
    '
    '  If the file is compressed then the data block size indicates
    '  whether this block is compressed.  A size equal to
    '  the block size indicates that the corresponding block did
    '  not compress.  Any other non-zero size indicates the
    '  size of the compressed data which needs to be
    '  decrypted/decompressed.
    '
    '  If the file is not compressed then the data block size
    '  indicates the amount of data within the block that
    '  needs to be decrypted.  Any other non-zero size indicates
    '  that the remaining bytes in the data unit within the file
    '  consists of zeros.  An example of this is when the
    '  the read spans the valid data length of the file.  There
    '  is no data to decrypt past the valid data length.
    '

    DataBlockSize(0) AS DWORD  ' ANYSIZE_ARRAY

END TYPE

#ENDIF  ' #IF %WIN32_WINNT >= &H0500


#IF %WIN32_WINNT >= &H0500
'
'  FSCTL_READ_FROM_PLEX support
'  Request Plex Read Data structure.  This is used to indicate
'  the range of the file to read.  It also describes
'  which plex to perform the read from.
'

TYPE PLEX_READ_DATA_REQUEST

    '
    '  Requested offset and length to read.
    '  The offset can be the virtual offset (vbo) in to a file,
    '  or a volume. In the case of a file offset,
    '  the fsd will round the starting offset down
    '  to a file system boundary.  It will also
    '  round the length up to a file system boundary and
    '  enforce any other applicable limits.
    '

    ByteOffset AS QUAD
    ByteLength AS DWORD
    PlexNumber AS DWORD

END TYPE
#ENDIF  ' #IF %WIN32_WINNT >= &H0500


#IF %WIN32_WINNT >= &H0500
'
' FSCTL_SIS_COPYFILE support
' Source and destination file names are passed in the FileNameBuffer.
' Both strings are null terminated, with the source name starting at
' the beginning of FileNameBuffer, and the destination name immediately
' following.  Length fields include terminating nulls.
'

TYPE SI_COPYFILE
    SourceFileNameLength      AS DWORD
    DestinationFileNameLength AS DWORD
    Flags                     AS DWORD
    FileNameBuffer(0)         AS WSTRINGZ PTR
END TYPE

%COPYFILE_SIS_LINK    = &H0001  ' Copy only if source is SIS
%COPYFILE_SIS_REPLACE = &H0002  ' Replace destination if it exists, else don't.
%COPYFILE_SIS_FLAGS   = &H0003

#ENDIF  ' #IF %WIN32_WINNT >= &H0500

#ENDIF  ' #IF NOT %DEF(%FILESYSTEMFSCTL)


'
' These IOCTLs are handled by hard disk volumes.
'

%IOCTL_VOLUME_BASE = 86  ' ((DWORD) 'V')
$$IOCTL_VOLUME_BASE = "V"$$

%IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS = &H00560000  ' CTL_CODE(IOCTL_VOLUME_BASE, 0, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_VOLUME_IS_CLUSTERED            = &H00560030  ' CTL_CODE(IOCTL_VOLUME_BASE, 12, METHOD_BUFFERED, FILE_ANY_ACCESS)

'
' Disk extent definition.
'

TYPE DISK_EXTENT
    DiskNumber     AS DWORD
    StartingOffset AS QUAD
    ExtentLength   AS QUAD
END TYPE

'
' Output structure for IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS.
'

TYPE VOLUME_DISK_EXTENTS
    NumberOfDiskExtents AS DWORD
    Extents(0)          AS DISK_EXTENT
END TYPE
