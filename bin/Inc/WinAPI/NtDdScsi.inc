'------------------------------------------------------------------------------
'
'  NtDdScsi.inc -- Constants and types for accessing the SCSI port adapters.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from NtDdScsi.h build version 0001 of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

'
' Interface GUIDs
'
'

$ScsiRawInterfaceGuid = GUID$("{53f56309-b6bf-11d0-94f2-00a0c91efb8b}")
$WmiScsiAddressGuid   = GUID$("{53f5630f-b6bf-11d0-94f2-00a0c91efb8b}")

%NTDDSCSIH = 1

#INCLUDE "WinIOCtl.inc"


'
' Device Name - this string is the name of the device.  It is the name
' that should be passed to NtOpenFile when accessing the device.
'
' Note:  For devices that support multiple units, it should be suffixed
'        with the Ascii representation of the unit number.
'

%IOCTL_SCSI_BASE               = %FILE_DEVICE_CONTROLLER
%FILE_DEVICE_SCSI              = &H0000001b

$DD_SCSI_DEVICE_NAME = "\Device\ScsiPort"
$$DD_SCSI_DEVICE_NAME = "\Device\ScsiPort"$$


'
' NtDeviceIoControlFile IoControlCode values for this device.
'
' Warning:  Remember that the low two bits of the code specify how the
'           buffers are passed to the driver!
'

MACRO IOCTL_SCSI_PASS_THROUGH        = CTL_CODE(%IOCTL_SCSI_BASE, &H0401, %METHOD_BUFFERED, %FILE_READ_ACCESS OR %FILE_WRITE_ACCESS)
MACRO IOCTL_SCSI_MINIPORT            = CTL_CODE(%IOCTL_SCSI_BASE, &H0402, %METHOD_BUFFERED, %FILE_READ_ACCESS OR %FILE_WRITE_ACCESS)
MACRO IOCTL_SCSI_GET_INQUIRY_DATA    = CTL_CODE(%IOCTL_SCSI_BASE, &H0403, %METHOD_BUFFERED, %FILE_ANY_ACCESS)
MACRO IOCTL_SCSI_GET_CAPABILITIES    = CTL_CODE(%IOCTL_SCSI_BASE, &H0404, %METHOD_BUFFERED, %FILE_ANY_ACCESS)
MACRO IOCTL_SCSI_PASS_THROUGH_DIRECT = CTL_CODE(%IOCTL_SCSI_BASE, &H0405, %METHOD_BUFFERED, %FILE_READ_ACCESS OR %FILE_WRITE_ACCESS)
MACRO IOCTL_SCSI_GET_ADDRESS         = CTL_CODE(%IOCTL_SCSI_BASE, &H0406, %METHOD_BUFFERED, %FILE_ANY_ACCESS)
MACRO IOCTL_SCSI_RESCAN_BUS          = CTL_CODE(%IOCTL_SCSI_BASE, &H0407, %METHOD_BUFFERED, %FILE_ANY_ACCESS)
MACRO IOCTL_SCSI_GET_DUMP_POINTERS   = CTL_CODE(%IOCTL_SCSI_BASE, &H0408, %METHOD_BUFFERED, %FILE_ANY_ACCESS)
MACRO IOCTL_SCSI_FREE_DUMP_POINTERS  = CTL_CODE(%IOCTL_SCSI_BASE, &H0409, %METHOD_BUFFERED, %FILE_ANY_ACCESS)
MACRO IOCTL_IDE_PASS_THROUGH         = CTL_CODE(%IOCTL_SCSI_BASE, &H040a, %METHOD_BUFFERED, %FILE_READ_ACCESS OR %FILE_WRITE_ACCESS)
MACRO IOCTL_ATA_PASS_THROUGH         = CTL_CODE(%IOCTL_SCSI_BASE, &H040b, %METHOD_BUFFERED, %FILE_READ_ACCESS OR %FILE_WRITE_ACCESS)
MACRO IOCTL_ATA_PASS_THROUGH_DIRECT  = CTL_CODE(%IOCTL_SCSI_BASE, &H040c, %METHOD_BUFFERED, %FILE_READ_ACCESS OR %FILE_WRITE_ACCESS)
MACRO IOCTL_ATA_MINIPORT             = CTL_CODE(%IOCTL_SCSI_BASE, &H040d, %METHOD_BUFFERED, %FILE_READ_ACCESS OR %FILE_WRITE_ACCESS)
MACRO IOCTL_MINIPORT_PROCESS_SERVICE_IRP = CTL_CODE(%IOCTL_SCSI_BASE,  &H040e, %METHOD_BUFFERED, %FILE_READ_ACCESS OR %FILE_WRITE_ACCESS)
MACRO IOCTL_MPIO_PASS_THROUGH_PATH   = CTL_CODE(%IOCTL_SCSI_BASE, &H040f, %METHOD_BUFFERED, %FILE_READ_ACCESS OR %FILE_WRITE_ACCESS)
MACRO IOCTL_MPIO_PASS_THROUGH_PATH_DIRECT = CTL_CODE(%IOCTL_SCSI_BASE, &H0410, %METHOD_BUFFERED, %FILE_READ_ACCESS OR %FILE_WRITE_ACCESS)

'
' Non Volatile Cache support
'

%IOCTL_SCSI_MINIPORT_NVCACHE    = (%FILE_DEVICE_SCSI * 65536 + &H0600)

'
' Define the SCSI pass through structure.
'

TYPE SCSI_PASS_THROUGH DWORD FILL
    Length             AS WORD
    ScsiStatus         AS BYTE
    PathId             AS BYTE
    TargetId           AS BYTE
    Lun                AS BYTE
    CdbLength          AS BYTE
    SenseInfoLength    AS BYTE
    DataIn             AS BYTE
    DataTransferLength AS DWORD
    TimeOutValue       AS DWORD
    DataBufferOffset   AS DWORD  ' ULONG_PTR
    SenseInfoOffset    AS DWORD
    Cdb(15)            AS BYTE
END TYPE

'
' Define the SCSI pass through direct structure.
'

TYPE SCSI_PASS_THROUGH_DIRECT DWORD FILL
    Length             AS WORD
    ScsiStatus         AS BYTE
    PathId             AS BYTE
    TargetId           AS BYTE
    Lun                AS BYTE
    CdbLength          AS BYTE
    SenseInfoLength    AS BYTE
    DataIn             AS BYTE
    DataTransferLength AS DWORD
    TimeOutValue       AS DWORD
    DataBuffer         AS DWORD  ' PVOID
    SenseInfoOffset    AS DWORD
    Cdb(15)            AS BYTE
END TYPE


'
' Define the SCSI pass through direct structure for Win64 (thunking).
'
#IF %DEF(%WIN64)
TYPE SCSI_PASS_THROUGH32
    Length             AS WORD
    ScsiStatus         AS BYTE
    PathId             AS BYTE
    TargetId           AS BYTE
    Lun                AS BYTE
    CdbLength          AS BYTE
    SenseInfoLength    AS BYTE
    DataIn             AS BYTE
    DataTransferLength AS DWORD
    TimeOutValue       AS DWORD
    DataBufferOffset   AS DWORD  ' ULONG32
    SenseInfoOffset    AS DWORD
    Cdb(15)            AS BYTE
END TYPE

'
' Define the SCSI pass through direct structure.
'

TYPE SCSI_PASS_THROUGH_DIRECT32
    Length                AS WORD
    ScsiStatus            AS BYTE
    PathId                AS BYTE
    TargetId              AS BYTE
    Lun                   AS BYTE
    CdbLength             AS BYTE
    SenseInfoLength       AS BYTE
    DataIn                AS BYTE
    DataTransferLength    AS DWORD
    TimeOutValue          AS DWORD
    DataBuffer            AS DWORD  ' VOID * POINTER_32
    SenseInfoOffset       AS DWORD
    Cdb(15)               AS BYTE
END TYPE

#ENDIF ' #if %def(%WIN64)

'
' ATA pass through structure
'

TYPE ATA_PASS_THROUGH_EX DWORD FILL
    Length              AS WORD
    AtaFlags            AS WORD
    PathId              AS BYTE
    TargetId            AS BYTE
    Lun                 AS BYTE
    ReservedAsUchar     AS BYTE
    DataTransferLength  AS DWORD
    TimeOutValue        AS DWORD
    ReservedAsUlong     AS DWORD
    DataBufferOffset    AS DWORD  ' ULONG_PTR
    PreviousTaskFile(7) AS BYTE
    CurrentTaskFile(7)  AS BYTE
END TYPE

'
' ATA pass through direct structure.
'

TYPE ATA_PASS_THROUGH_DIRECT DWORD FILL
    Length              AS WORD
    AtaFlags            AS WORD
    PathId              AS BYTE
    TargetId            AS BYTE
    Lun                 AS BYTE
    ReservedAsUchar     AS BYTE
    DataTransferLength  AS DWORD
    TimeOutValue        AS DWORD
    ReservedAsUlong     AS DWORD
    DataBuffer          AS DWORD  ' PVOID
    PreviousTaskFile(7) AS BYTE
    CurrentTaskFile(7)  AS BYTE
END TYPE

'
' Define the ATA pass through direct structure for Win64 (thunking).
'
#IF %DEF(%WIN64)

TYPE ATA_PASS_THROUGH_EX32
    Length              AS WORD
    AtaFlags            AS WORD
    PathId              AS BYTE
    TargetId            AS BYTE
    Lun                 AS BYTE
    ReservedAsUchar     AS BYTE
    DataTransferLength  AS DWORD
    TimeOutValue        AS DWORD
    ReservedAsUlong     AS DWORD
    DataBufferOffset    AS DWORD  ' ULONG32
    PreviousTaskFile(7) AS BYTE
    CurrentTaskFile(7)  AS BYTE
END TYPE

'
' ATA pass through direct structure.
'

TYPE ATA_PASS_THROUGH_DIRECT32
    Length              AS WORD
    AtaFlags            AS WORD
    PathId              AS BYTE
    TargetId            AS BYTE
    Lun                 AS BYTE
    ReservedAsUchar     AS BYTE
    DataTransferLength  AS DWORD
    TimeOutValue        AS DWORD
    ReservedAsUlong     AS DWORD
    DataBuffer          AS DWORD  ' VOID * POINTER_32
    PreviousTaskFile(7) AS BYTE
    CurrentTaskFile(7)  AS BYTE
END TYPE
#ENDIF ' #if %def(%WIN64)

'
' ATA Pass Through Flags
'
%ATA_FLAGS_DRDY_REQUIRED = &B1
%ATA_FLAGS_DATA_IN       = &B10
%ATA_FLAGS_DATA_OUT      = &B100
%ATA_FLAGS_48BIT_COMMAND = &B1000
%ATA_FLAGS_USE_DMA       = &B10000
%ATA_FLAGS_NO_MULTIPLE   = &B100000

'
' Define header for IOCTL_ATA_MINIPORT
'

TYPE IDE_IO_CONTROL DWORD FILL
    HeaderLength AS DWORD
    Signature(7) AS BYTE
    TIMEOUT      AS DWORD
    ControlCode  AS DWORD
    ReturnStatus AS DWORD
    DataLength   AS DWORD
END TYPE

'
' Define the structure for IOCTL_MPIO_PASS_THROUGH_PATH.
'

TYPE MPIO_PASS_THROUGH_PATH DWORD FILL
    PassThrough AS SCSI_PASS_THROUGH
    Version     AS DWORD
    Length      AS WORD
    Flags       AS BYTE
    PortNumber  AS BYTE
    MpioPathId  AS QUAD  ' ULONGLONG
END TYPE

'
' Define the structure for IOCTL_MPIO_PASS_THROUGH_PATH_DIRECT.
'

TYPE MPIO_PASS_THROUGH_PATH_DIRECT DWORD FILL
    PassThrough AS SCSI_PASS_THROUGH_DIRECT
    Version     AS DWORD
    Length      AS WORD
    Flags       AS BYTE
    PortNumber  AS BYTE
    MpioPathId  AS QUAD  ' ULONGLONG
END TYPE


'
' Define the IOCTL_MPIO_PASS_THROUGH_PATH structure for Win64 (thunking).
'

#IF %DEF(%WIN64)
TYPE MPIO_PASS_THROUGH_PATH32
    PassThrough AS SCSI_PASS_THROUGH32
    Version     AS DWORD
    Length      AS WORD
    Flags       AS BYTE
    PortNumber  AS BYTE
    MpioPathId  AS QUAD  ' ULONGLONG
END TYPE

'
' Define the IOCTL_MPIO_PASS_THROUGH_PATH_DIRECT structure for Win64 (thunking).
'

TYPE MPIO_PASS_THROUGH_PATH_DIRECT32
    PassThrough AS SCSI_PASS_THROUGH_DIRECT32
    Version     AS DWORD
    Length      AS WORD
    Flags       AS BYTE
    PortNumber  AS BYTE
    MpioPathId  AS QUAD  ' ULONGLONG
END TYPE

#ENDIF  ' #if %def(%WIN64)

'
' Define SCSI information.
' Used with the IOCTL_SCSI_GET_INQUIRY_DATA IOCTL.
'

TYPE SCSI_BUS_DATA DWORD FILL
    NumberOfLogicalUnits AS BYTE
    InitiatorBusId       AS BYTE
    InquiryDataOffset    AS DWORD
END TYPE

'
' Define SCSI adapter bus information structure..
' Used with the IOCTL_SCSI_GET_INQUIRY_DATA IOCTL.
'

TYPE SCSI_ADAPTER_BUS_INFO DWORD FILL
    NumberOfBuses AS BYTE
    BusData(0)    AS SCSI_BUS_DATA
END TYPE

'
' Define SCSI adapter bus information.
' Used with the IOCTL_SCSI_GET_INQUIRY_DATA IOCTL.
'

TYPE SCSI_INQUIRY_DATA DWORD FILL
    PathId                AS BYTE
    TargetId              AS BYTE
    Lun                   AS BYTE
    DeviceClaimed         AS BYTE  ' BOOLEAN
    InquiryDataLength     AS DWORD
    NextInquiryDataOffset AS DWORD
    InquiryData(0)        AS BYTE
END TYPE

'
' Define header for I/O control SRB.
'

TYPE SRB_IO_CONTROL DWORD FILL
    HeaderLength AS DWORD
    Signature(7) AS BYTE
    TIMEOUT      AS DWORD
    ControlCode  AS DWORD
    ReturnCode   AS DWORD
    Length       AS DWORD
END TYPE

TYPE NVCACHE_REQUEST_BLOCK DWORD FILL
    NRBSize          AS DWORD
    FUNCTION         AS WORD
    NRBFlags         AS DWORD
    NRBStatus        AS DWORD
    COUNT            AS DWORD
    LBA              AS QUAD  ' ULONGLONG
    DataBufSize      AS DWORD
    NVCacheStatus    AS DWORD
    NVCacheSubStatus AS DWORD
END TYPE

%NRB_FUNCTION_NVCACHE_INFO              = &HEC?
%NRB_FUNCTION_SPINDLE_STATUS                = &HE5?
%NRB_FUNCTION_NVCACHE_POWER_MODE_SET        = &H00
%NRB_FUNCTION_NVCACHE_POWER_MODE_RETURN = &H01
%NRB_FUNCTION_FLUSH_NVCACHE             = &H14
%NRB_FUNCTION_QUERY_PINNED_SET          = &H12
%NRB_FUNCTION_QUERY_CACHE_MISS          = &H13
%NRB_FUNCTION_ADD_LBAS_PINNED_SET       = &H10
%NRB_FUNCTION_REMOVE_LBAS_PINNED_SET    = &H11
%NRB_FUNCTION_QUERY_ASCENDER_STATUS     = &HD0?
%NRB_FUNCTION_QUERY_HYBRID_DISK_STATUS  = &HD1?

%NRB_SUCCESS                           = 0
%NRB_ILLEGAL_REQUEST                   = 1
%NRB_INVALID_PARAMETER                 = 2
%NRB_INPUT_DATA_OVERRUN                = 3
%NRB_INPUT_DATA_UNDERRUN               = 4
%NRB_OUTPUT_DATA_OVERRUN               = 5
%NRB_OUTPUT_DATA_UNDERRUN              = 6

TYPE NV_FEATURE_PARAMETER DWORD FILL
    NVPowerModeEnabled AS WORD
    NVParameterReserv1 AS WORD
    NVCmdEnabled       AS WORD
    NVParameterReserv2 AS WORD
    NVPowerModeVer     AS WORD
    NVCmdVer           AS WORD
    NVSize             AS DWORD    ' in number of LBA
    NVReadSpeed        AS WORD     ' in MB/s
    NVWrtSpeed         AS WORD
    DeviceSpinUpTime   AS DWORD    ' in second
END TYPE

'
' SCSI port driver capabilities structure.
'

TYPE IO_SCSI_CAPABILITIES DWORD FILL

    '
    ' Length of this structure
    '

    Length AS DWORD

    '
    ' Maximum transfer size in single SRB
    '

    MaximumTransferLength AS DWORD

    '
    ' Maximum number of physical pages per data buffer
    '

    MaximumPhysicalPages AS DWORD

    '
    ' Async calls from port to class
    '

    SupportedAsynchronousEvents AS DWORD

    '
    ' Alignment mask for data transfers.
    '

    AlignmentMask AS DWORD

    '
    ' Supports tagged queuing
    '

    TaggedQueuing AS BYTE  ' BOOLEAN

    '
    ' Host adapter scans down for bios devices.
    '

    AdapterScansDown AS BYTE  ' BOOLEAN

    '
    ' The host adapter uses programmed I/O.
    '

    AdapterUsesPio AS BYTE  ' BOOLEAN

END TYPE  ' IO_SCSI_CAPABILITIES


TYPE SCSI_ADDRESS DWORD FILL
    Length     AS DWORD
    PortNumber AS BYTE
    PathId     AS BYTE
    TargetId   AS BYTE
    Lun        AS BYTE
END TYPE

'
' Define structure for returning crash dump pointers.
'

'struct _ADAPTER_OBJECT;
%DUMP_POINTERS_VERSION_1       = 1
%DUMP_POINTERS_VERSION_2       = 2
%DUMP_DRIVER_NAME_LENGTH       = 15

TYPE DUMP_POINTERS_VERSION
    '
    ' Dump pointers structure version
    '
    Version AS DWORD

    '
    ' Dump pointers structure size
    '
    SIZE AS DWORD

END TYPE


TYPE DUMP_POINTERS DWORD FILL
    AdapterObject         AS DWORD  ' struct _ADAPTER_OBJECT *
    MappedRegisterBase    AS DWORD  ' PVOID
    DumpData              AS DWORD  ' PVOID
    CommonBufferVa        AS DWORD  ' PVOID
    CommonBufferPa        AS QUAD  ' LARGE_INTEGER
    CommonBufferSize      AS DWORD
    AllocateCommonBuffers AS BYTE   ' BOOLEAN
#IF (%NTDDI_VERSION < %NTDDI_WINXP)
    Spare1(3)             AS BYTE
#ELSE
    UseDiskDump           AS BYTE   ' BOOLEAN
    Spare1(2)             AS BYTE
#ENDIF
    DeviceObject          AS DWORD  ' PVOID
END TYPE


TYPE DUMP_POINTERS_EX DWORD FILL
    HEADER                AS DUMP_POINTERS_VERSION
    DumpData              AS DWORD  ' PVOID
    CommonBufferVa        AS DWORD  ' PVOID
    CommonBufferSize      AS DWORD
    AllocateCommonBuffers AS BYTE   ' BOOLEAN
    DeviceObject          AS DWORD  ' PVOID
    DriverList            AS DWORD  ' PVOID
END TYPE


TYPE DUMP_DRIVER DWORD FILL

    '
    ' Dump driver list from port driver
    '
    DumpDriverList AS DWORD  ' PVOID

    '
    ' Name of the driver to be loaded
    '
    DriverName AS WSTRINGZ * %DUMP_DRIVER_NAME_LENGTH

    '
    ' Driver base name
    '
    BaseName AS WSTRINGZ * %DUMP_DRIVER_NAME_LENGTH

END TYPE


'
' Define values for pass-through DataIn field.
'

%SCSI_IOCTL_DATA_OUT         = 0
%SCSI_IOCTL_DATA_IN          = 1
%SCSI_IOCTL_DATA_UNSPECIFIED = 2

'
' Define values for MPIO-pass-through-path Flags field.
'

%MPIO_IOCTL_FLAG_USE_PATHID      = 1
%MPIO_IOCTL_FLAG_USE_SCSIADDRESS = 2
%MPIO_IOCTL_FLAG_INVOLVE_DSM     = 4
