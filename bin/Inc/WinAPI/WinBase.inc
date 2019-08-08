'------------------------------------------------------------------------------
'
'  WinBase.inc - This file defines the 32-bit Windows base APIs.
'
'  Copyright (c) 1997-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last Update: 02 May 2011
'
'------------------------------------------------------------------------------
'  Based on WinBase.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WINBASE = 1

#INCLUDE "WinNT.inc"

%INVALID_HANDLE_VALUE     = &HFFFFFFFF???
%INVALID_FILE_SIZE        = &HFFFFFFFF???
%INVALID_SET_FILE_POINTER = &HFFFFFFFF???
%INVALID_FILE_ATTRIBUTES  = &HFFFFFFFF???

%FILE_BEGIN   = 0
%FILE_CURRENT = 1
%FILE_END     = 2

%TIME_ZONE_ID_INVALID  = &HFFFFFFFF???

%WAIT_FAILED      = &HFFFFFFFF???
%WAIT_OBJECT_0    = %STATUS_WAIT_0
%WAIT_ABANDONED   = %STATUS_ABANDONED_WAIT_0
%WAIT_ABANDONED_0 = %STATUS_ABANDONED_WAIT_0

%WAIT_IO_COMPLETION              = %STATUS_USER_APC
%STILL_ACTIVE                    = %STATUS_PENDING
%EXCEPTION_ACCESS_VIOLATION      = %STATUS_ACCESS_VIOLATION
%EXCEPTION_DATATYPE_MISALIGNMENT = %STATUS_DATATYPE_MISALIGNMENT
%EXCEPTION_BREAKPOINT            = %STATUS_BREAKPOINT
%EXCEPTION_SINGLE_STEP           = %STATUS_SINGLE_STEP
%EXCEPTION_ARRAY_BOUNDS_EXCEEDED = %STATUS_ARRAY_BOUNDS_EXCEEDED
%EXCEPTION_FLT_DENORMAL_OPERAND  = %STATUS_FLOAT_DENORMAL_OPERAND
%EXCEPTION_FLT_DIVIDE_BY_ZERO    = %STATUS_FLOAT_DIVIDE_BY_ZERO
%EXCEPTION_FLT_INEXACT_RESULT    = %STATUS_FLOAT_INEXACT_RESULT
%EXCEPTION_FLT_INVALID_OPERATION = %STATUS_FLOAT_INVALID_OPERATION
%EXCEPTION_FLT_OVERFLOW          = %STATUS_FLOAT_OVERFLOW
%EXCEPTION_FLT_STACK_CHECK       = %STATUS_FLOAT_STACK_CHECK
%EXCEPTION_FLT_UNDERFLOW         = %STATUS_FLOAT_UNDERFLOW
%EXCEPTION_INT_DIVIDE_BY_ZERO    = %STATUS_INTEGER_DIVIDE_BY_ZERO
%EXCEPTION_INT_OVERFLOW          = %STATUS_INTEGER_OVERFLOW
%EXCEPTION_PRIV_INSTRUCTION      = %STATUS_PRIVILEGED_INSTRUCTION
%EXCEPTION_IN_PAGE_ERROR         = %STATUS_IN_PAGE_ERROR

%EXCEPTION_ILLEGAL_INSTRUCTION   = %STATUS_ILLEGAL_INSTRUCTION
%EXCEPTION_NONCONTINUABLE_EXCEPTION = %STATUS_NONCONTINUABLE_EXCEPTION
%EXCEPTION_STACK_OVERFLOW        = %STATUS_STACK_OVERFLOW
%EXCEPTION_INVALID_DISPOSITION   = %STATUS_INVALID_DISPOSITION
%EXCEPTION_GUARD_PAGE            = %STATUS_GUARD_PAGE_VIOLATION
%EXCEPTION_INVALID_HANDLE        = %STATUS_INVALID_HANDLE
%EXCEPTION_POSSIBLE_DEADLOCK     = %STATUS_POSSIBLE_DEADLOCK
%CONTROL_C_EXIT                  = %STATUS_CONTROL_C_EXIT

SUB MoveMemory (BYVAL pDest AS DWORD, BYVAL pSrc AS DWORD, BYVAL ncBytes AS LONG)
    MEMORY COPY pSrc, pDest, ncBytes
END SUB

SUB CopyMemory (BYVAL pDest AS DWORD, BYVAL pSrc AS DWORD, BYVAL ncBytes AS LONG)
    MEMORY COPY pSrc, pDest, ncBytes
END SUB

SUB FillMemory (BYVAL pDest AS DWORD, BYVAL ncBytes AS DWORD, BYVAL nValue AS BYTE)
    MEMORY FILL pDest, ncBytes, BYTE nValue
END SUB

SUB ZeroMemory (BYVAL pDest AS DWORD, BYVAL ncBytes AS LONG)
    MEMORY FILL pDest, ncBytes, BYTE 0
END SUB

SUB SecureZeroMemory (BYVAL pDest AS DWORD, BYVAL ncBytes AS LONG)
    MEMORY FILL pDest, ncBytes, BYTE 0
END SUB

DECLARE FUNCTION CaptureStackBackTrace LIB "Kernel32.dll" _
    ALIAS "RtlCaptureStackBackTrace" ( _
    BYVAL FramesToSkip           AS DWORD, _
    BYVAL FramesToCapture        AS DWORD, _
    BYVAL BackTrace              AS DWORD, _   ' PVOID *
    OPTIONAL BYVAL BackTraceHash AS DWORD _    ' DWORD PTR
    ) AS WORD

'
' File creation flags must start at the high end since they
' are combined with the attributes
'

%FILE_FLAG_WRITE_THROUGH       = &H080000000
%FILE_FLAG_OVERLAPPED          = &H040000000
%FILE_FLAG_NO_BUFFERING        = &H020000000
%FILE_FLAG_RANDOM_ACCESS       = &H010000000
%FILE_FLAG_SEQUENTIAL_SCAN     = &H008000000
%FILE_FLAG_DELETE_ON_CLOSE     = &H004000000
%FILE_FLAG_BACKUP_SEMANTICS    = &H002000000
%FILE_FLAG_POSIX_SEMANTICS     = &H001000000
%FILE_FLAG_OPEN_REPARSE_POINT  = &H000200000
%FILE_FLAG_OPEN_NO_RECALL      = &H000100000
%FILE_FLAG_FIRST_PIPE_INSTANCE = &H000080000

%CREATE_NEW        = 1
%CREATE_ALWAYS     = 2
%OPEN_EXISTING     = 3
%OPEN_ALWAYS       = 4
%TRUNCATE_EXISTING = 5

#IF (%WIN32_WINNT >= &H0400)
'
' Define possible return codes from the CopyFileEx callback routine
'

%PROGRESS_CONTINUE = 0
%PROGRESS_CANCEL   = 1
%PROGRESS_STOP     = 2
%PROGRESS_QUIET    = 3

'
' Define CopyFileEx callback routine state change values
'

%CALLBACK_CHUNK_FINISHED  = &H00000000
%CALLBACK_STREAM_SWITCH   = &H00000001

'
' Define CopyFileEx option flags
'

%COPY_FILE_FAIL_IF_EXISTS              = &H00000001
%COPY_FILE_RESTARTABLE                 = &H00000002
%COPY_FILE_OPEN_SOURCE_FOR_WRITE       = &H00000004
%COPY_FILE_ALLOW_DECRYPTED_DESTINATION = &H00000008

'
'  Gap for private copyfile flags
'

#IF (%WIN32_WINNT >= &H0600)
%COPY_FILE_COPY_SYMLINK                = &H00000800
%COPY_FILE_NO_BUFFERING                = &H00001000
#ENDIF  ' #IF (%WIN32_WINNT >= &H0600)
#ENDIF  ' %WIN32_WINNT >= &H0400

#IF (%WIN32_WINNT >= &H0500)
'
' Define ReplaceFile option flags
'

%REPLACEFILE_WRITE_THROUGH       = &H00000001
%REPLACEFILE_IGNORE_MERGE_ERRORS = &H00000002

#IF (%WIN32_WINNT >= &H0600)
%REPLACEFILE_IGNORE_ACL_ERRORS   = &H00000004
#ENDIF
#ENDIF ' #if (%WIN32_WINNT >= &H0500)

'
' Define the NamedPipe definitions
'


'
' Define the dwOpenMode values for CreateNamedPipe
'

%PIPE_ACCESS_INBOUND  = &H1
%PIPE_ACCESS_OUTBOUND = &H2
%PIPE_ACCESS_DUPLEX   = &H3

'
' Define the Named Pipe End flags for GetNamedPipeInfo
'

%PIPE_CLIENT_END      = &H0
%PIPE_SERVER_END      = &H1

'
' Define the dwPipeMode values for CreateNamedPipe
'

%PIPE_WAIT             = &H0
%PIPE_NOWAIT           = &H1
%PIPE_READMODE_BYTE    = &H0
%PIPE_READMODE_MESSAGE = &H2
%PIPE_TYPE_BYTE        = &H0
%PIPE_TYPE_MESSAGE     = &H4

%PIPE_ACCEPT_REMOTE_CLIENTS = &H00000000
%PIPE_REJECT_REMOTE_CLIENTS = &H00000008

'
' Define the well known values for CreateNamedPipe nMaxInstances
'

%PIPE_UNLIMITED_INSTANCES = 255

'
' Define the Security Quality of Service bits to be passed
' into CreateFile
'

'#define SECURITY_ANONYMOUS          ( SecurityAnonymous      << 16 )
'#define SECURITY_IDENTIFICATION     ( SecurityIdentification << 16 )
'#define SECURITY_IMPERSONATION      ( SecurityImpersonation  << 16 )
'#define SECURITY_DELEGATION         ( SecurityDelegation     << 16 )

%SECURITY_CONTEXT_TRACKING = &H00040000
%SECURITY_EFFECTIVE_ONLY   = &H00080000

%SECURITY_SQOS_PRESENT     = &H00100000
%SECURITY_VALID_SQOS_FLAGS = &H001F0000

'
'  File structures
'

TYPE OVERLAPPED_type
    Offset     AS DWORD
    OffsetHigh AS DWORD
END TYPE

UNION OVERLAPPED_union
    OVERLAPPED_type
    pPointer AS DWORD
END UNION

TYPE OVERLAPPED
    Internal     AS DWORD
    InternalHigh AS DWORD
    OVERLAPPED_union
    hEvent       AS DWORD
END TYPE

TYPE OVERLAPPED_ENTRY
    lpCompletionKey AS DWORD
    lpOverlapped    AS OVERLAPPED PTR
    Internal        AS DWORD
    dwNumberOfBytesTransferred AS DWORD
END TYPE

TYPE SECURITY_ATTRIBUTES
    nLength              AS DWORD
    lpSecurityDescriptor AS DWORD
    bInheritHandle       AS LONG
END TYPE

TYPE PROCESS_INFORMATION
    hProcess    AS DWORD
    hThread     AS DWORD
    dwProcessId AS DWORD
    dwThreadId  AS DWORD
END TYPE

'
'  File System time stamps are represented with the following structure:
'

#IF NOT %DEF(%FILETIME)
%FILETIME = 1

TYPE FILETIME_dword
    dwLowDateTime  AS DWORD
    dwHighDateTime AS DWORD
END TYPE

TYPE FILETIME_quad
    qDateTime      AS QUAD
END TYPE

UNION FILETIME
    FILETIME_dword
    FILETIME_quad
END UNION
#ENDIF

'
' System time is represented with the following structure:
'

TYPE SYSTEMTIME
    wYear         AS WORD
    wMonth        AS WORD
    wDayOfWeek    AS WORD
    wDay          AS WORD
    wHour         AS WORD
    wMinute       AS WORD
    wSecond       AS WORD
    wMilliseconds AS WORD
END TYPE

DECLARE FUNCTION PTHREAD_START_ROUTINE (BYVAL lpThreadParameter AS DWORD) AS DWORD

#IF (%WIN32_WINNT >= &H0400)
DECLARE SUB PFIBER_START_ROUTINE (BYVAL lpFiberParameter AS DWORD)
#ENDIF

TYPE CRITICAL_SECTION
    RTL_CRITICAL_SECTION
END TYPE

TYPE CRITICAL_SECTION_DEBUG
    RTL_CRITICAL_SECTION_DEBUG
END TYPE

#IF (%WIN32_WINNT >= &H0600)

'
' Define one-time initialization primitive
'

UNION INIT_ONCE
    RTL_RUN_ONCE
END UNION

%INIT_ONCE_STATIC_INIT=%RTL_RUN_ONCE_INIT

'
' Run once flags
'

%INIT_ONCE_CHECK_ONLY  = %RTL_RUN_ONCE_CHECK_ONLY
%INIT_ONCE_ASYNC       = %RTL_RUN_ONCE_ASYNC
%INIT_ONCE_INIT_FAILED = %RTL_RUN_ONCE_INIT_FAILED

'
' The context stored in the run once structure must leave the following number
' of low order bits unused.
'

%INIT_ONCE_CTX_RESERVED_BITS = %RTL_RUN_ONCE_CTX_RESERVED_BITS

'
' FailFast Exception Flags
'

%FAIL_FAST_GENERATE_EXCEPTION_ADDRESS  = &H1
%FAIL_FAST_NO_HARD_ERROR_DLG           = &H2

DECLARE FUNCTION PINIT_ONCE_FN (InitOnce AS INIT_ONCE, _
    BYVAL Parameter AS DWORD, BYVAL Context AS DWORD) AS LONG

DECLARE SUB InitOnceInitialize LIB "Kernel32.dll" ALIAS "InitOnceInitialize" _
    (InitOnce AS INIT_ONCE)

DECLARE FUNCTION InitOnceExecuteOnce LIB "Kernel32.dll" _
    ALIAS "InitOnceExecuteOnce" (InitOnce AS INIT_ONCE, _
    BYVAL InitFn AS DWORD, Parameter AS ANY, Context AS ANY) AS LONG

DECLARE FUNCTION InitOnceBeginInitialize LIB "Kernel32.dll" _
    ALIAS "InitOnceBeginInitialize" (lpInitOnce AS INIT_ONCE, _
    BYVAL dwFlags AS DWORD, fPending AS LONG, lpContext AS ANY) AS LONG

DECLARE FUNCTION InitOnceComplete LIB "Kernel32.dll" ALIAS "InitOnceComplete" _
    (lpInitOnce AS INIT_ONCE, BYVAL dwFlags AS DWORD, lpContext AS ANY) AS LONG

#ENDIF

'
' Define the slim r/w lock
'

TYPE SRWLOCK
    RTL_SRWLOCK
END TYPE

%SRWLOCK_INIT = %RTL_SRWLOCK_INIT

DECLARE SUB InitializeSRWLock LIB "Kernel32.dll" ALIAS "InitializeSRWLock" _
    (srw AS SRWLOCK)

DECLARE SUB ReleaseSRWLockExclusive LIB "Kernel32.dll" _
    ALIAS "ReleaseSRWLockExclusive" (srw AS SRWLOCK)

DECLARE SUB ReleaseSRWLockShared LIB "Kernel32.dll" _
    ALIAS "ReleaseSRWLockShared" (srw AS SRWLOCK)

DECLARE SUB AcquireSRWLockExclusive LIB "Kernel32.dll" _
    ALIAS "AcquireSRWLockExclusive" (srw AS SRWLOCK)

DECLARE SUB AcquireSRWLockShared LIB "Kernel32.dll" _
    ALIAS "AcquireSRWLockShared" (srw AS SRWLOCK)

DECLARE FUNCTION TryAcquireSRWLockExclusive LIB "Kernel32.dll" _
    ALIAS "TryAcquireSRWLockExclusive" (srw AS SRWLOCK) AS BYTE

DECLARE FUNCTION TryAcquireSRWLockShared LIB "Kernel32.dll" _
    ALIAS "TryAcquireSRWLockShared" (srw AS SRWLOCK) AS BYTE

'
' Define condition variable
'

TYPE CONDITION_VARIABLE
    RTL_CONDITION_VARIABLE
END TYPE

DECLARE SUB InitializeConditionVariable LIB "Kernel32.dll" _
    ALIAS "InitializeConditionVariable" (ConditionVariable AS CONDITION_VARIABLE)

DECLARE SUB WakeConditionVariable LIB "Kernel32.dll" _
    ALIAS "WakeConditionVariable" (ConditionVariable AS CONDITION_VARIABLE)

DECLARE SUB WakeAllConditionVariable LIB "Kernel32.dll" _
    ALIAS "WakeAllConditionVariable" (ConditionVariable AS CONDITION_VARIABLE)

DECLARE FUNCTION SleepConditionVariableCS LIB "Kernel32.dll" _
    ALIAS "SleepConditionVariableCS" (ConditionVariable AS CONDITION_VARIABLE, _
    CriticalSection AS DWORD, BYVAL dwMilliseconds AS DWORD) AS LONG

DECLARE FUNCTION SleepConditionVariableSRW LIB "Kernel32.dll" _
    ALIAS "SleepConditionVariableSRW" (ConditionVariable AS CONDITION_VARIABLE, _
    srw AS SRWLOCK, BYVAL dwMilliseconds AS DWORD, BYVAL uFlags AS DWORD) _
    AS LONG

'
' Static initializer for the condition variable
'

%CONDITION_VARIABLE_INIT = %RTL_CONDITION_VARIABLE_INIT

'
' Flags for condition variables
'
%CONDITION_VARIABLE_LOCKMODE_SHARED = %RTL_CONDITION_VARIABLE_LOCKMODE_SHARED


DECLARE FUNCTION EncodePointer LIB "Kernel32.dll" ALIAS "EncodePointer" _
    (BYVAL p AS DWORD) AS DWORD

DECLARE FUNCTION DecodePointer LIB "Kernel32.dll" ALIAS "DecodePointer" _
    (BYVAL p AS DWORD) AS DWORD

DECLARE FUNCTION EncodeSystemPointer LIB "Kernel32.dll" _
    ALIAS "EncodeSystemPointer" (BYVAL p AS DWORD) AS DWORD

DECLARE FUNCTION DecodeSystemPointer LIB "Kernel32.dll" _
    ALIAS "DecodeSystemPointer" (BYVAL p AS DWORD) AS DWORD

%MUTEX_MODIFY_STATE = %MUTANT_QUERY_STATE
%MUTEX_ALL_ACCESS = %MUTANT_ALL_ACCESS

'
' Serial provider type.
'

%SP_SERIALCOMM = &H00000001???

'
' Provider SubTypes
'

%PST_UNSPECIFIED    = &H00000000???
%PST_RS232          = &H00000001???
%PST_PARALLELPORT   = &H00000002???
%PST_RS422          = &H00000003???
%PST_RS423          = &H00000004???
%PST_RS449          = &H00000005???
%PST_MODEM          = &H00000006???
%PST_FAX            = &H00000021???
%PST_SCANNER        = &H00000022???
%PST_NETWORK_BRIDGE = &H00000100???
%PST_LAT            = &H00000101???
%PST_TCPIP_TELNET   = &H00000102???
%PST_X25            = &H00000103???

'
' Provider capabilities flags.
'

%PCF_DTRDSR        = &H0001???
%PCF_RTSCTS        = &H0002???
%PCF_RLSD          = &H0004???
%PCF_PARITY_CHECK  = &H0008???
%PCF_XONXOFF       = &H0010???
%PCF_SETXCHAR      = &H0020???
%PCF_TOTALTIMEOUTS = &H0040???
%PCF_INTTIMEOUTS   = &H0080???
%PCF_SPECIALCHARS  = &H0100???
%PCF_16BITMODE     = &H0200???

'
' Comm provider settable parameters.
'

%SP_PARITY       = &H0001???
%SP_BAUD         = &H0002???
%SP_DATABITS     = &H0004???
%SP_STOPBITS     = &H0008???
%SP_HANDSHAKING  = &H0010???
%SP_PARITY_CHECK = &H0020???
%SP_RLSD         = &H0040???

'
' Settable baud rates in the provider.
'

%BAUD_075          = &H00000001???
%BAUD_110          = &H00000002???
%BAUD_134_5        = &H00000004???
%BAUD_150          = &H00000008???
%BAUD_300          = &H00000010???
%BAUD_600          = &H00000020???
%BAUD_1200         = &H00000040???
%BAUD_1800         = &H00000080???
%BAUD_2400         = &H00000100???
%BAUD_4800         = &H00000200???
%BAUD_7200         = &H00000400???
%BAUD_9600         = &H00000800???
%BAUD_14400        = &H00001000???
%BAUD_19200        = &H00002000???
%BAUD_38400        = &H00004000???
%BAUD_56K          = &H00008000???
%BAUD_128K         = &H00010000???
%BAUD_115200       = &H00020000???
%BAUD_57600        = &H00040000???
%BAUD_USER         = &H10000000???

'
' Settable Data Bits
'

%DATABITS_5        = &H0001
%DATABITS_6        = &H0002
%DATABITS_7        = &H0004
%DATABITS_8        = &H0008
%DATABITS_16       = &H0010
%DATABITS_16X      = &H0020

'
' Settable Stop and Parity bits.
'

%STOPBITS_10       = &H0001
%STOPBITS_15       = &H0002
%STOPBITS_20       = &H0004
%PARITY_NONE       = &H0100
%PARITY_ODD        = &H0200
%PARITY_EVEN       = &H0400
%PARITY_MARK       = &H0800
%PARITY_SPACE      = &H1000

TYPE COMMPROP
    wPacketLength       AS WORD
    wPacketVersion      AS WORD
    dwServiceMask       AS DWORD
    dwReserved1         AS DWORD
    dwMaxTxQueue        AS DWORD
    dwMaxRxQueue        AS DWORD
    dwMaxBaud           AS DWORD
    dwProvSubType       AS DWORD
    dwProvCapabilities  AS DWORD
    dwSettableParams    AS DWORD
    dwSettableBaud      AS DWORD
    wSettableData       AS WORD
    wSettableStopParity AS WORD
    dwCurrentTxQueue    AS DWORD
    dwCurrentRxQueue    AS DWORD
    dwProvSpec1         AS DWORD
    dwProvSpec2         AS DWORD
'    wcProvChar(0)       AS WORD
END TYPE

'
' Set dwProvSpec1 to COMMPROP_INITIALIZED to indicate that wPacketLength
' is valid before a call to GetCommProperties().
'
%COMMPROP_INITIALIZED = &HE73CF52E???

TYPE COMSTAT_type
    fCtsHold  AS BIT * 1 IN DWORD
    fDsrHold  AS BIT * 1
    fRlsdHold AS BIT * 1
    fXoffHold AS BIT * 1
    fXoffSent AS BIT * 1
    fEof      AS BIT * 1
    fTxim     AS BIT * 1
    fReserved AS BIT * 25
END TYPE

UNION COMSTAT_union
    fBits AS DWORD
    COMSTAT_type
END UNION

TYPE COMSTAT
    COMSTAT_union
    cbInQue  AS DWORD
    cbOutQue AS DWORD
END TYPE

'
' DTR Control Flow Values.
'
%DTR_CONTROL_DISABLE   = &H00
%DTR_CONTROL_ENABLE    = &H01
%DTR_CONTROL_HANDSHAKE = &H02

'
' RTS Control Flow Values
'
%RTS_CONTROL_DISABLE   = &H00
%RTS_CONTROL_ENABLE    = &H01
%RTS_CONTROL_HANDSHAKE = &H02
%RTS_CONTROL_TOGGLE    = &H03

TYPE DCB_type
    fBinary           AS BIT * 1 IN DWORD   ' Binary Mode (skip EOF check)
    fParity           AS BIT * 1            ' Enable parity checking
    fOutxCtsFlow      AS BIT * 1            ' CTS handshaking on output
    fOutxDsrFlow      AS BIT * 1            ' DSR handshaking on output
    fDtrControl       AS BIT * 2            ' DTR Flow control
    fDsrSensitivity   AS BIT * 1            ' DSR Sensitivity
    fTXContinueOnXoff AS BIT * 1            ' Continue TX when Xoff sent
    fOutX             AS BIT * 1            ' Enable output X-ON/X-OFF
    fInX              AS BIT * 1            ' Enable input X-ON/X-OFF
    fErrorChar        AS BIT * 1            ' Enable Err Replacement
    fNull             AS BIT * 1            ' Enable Null stripping
    fRtsControl       AS BIT * 2            ' Rts Flow control
    fAbortOnError     AS BIT * 1            ' Abort all reads and writes on Error
    fDummy2           AS BIT * 17           ' Reserved
END TYPE

UNION DCB_union
    fBits AS DWORD
    DCB_type
END UNION

TYPE DCB
    DCBlength AS DWORD      ' sizeof(DCB)
    BaudRate AS DWORD       ' Baudrate at which running
    DCB_union
    wReserved AS WORD       ' Not currently used
    XonLim AS WORD          ' Transmit X-ON threshold
    XoffLim AS WORD         ' Transmit X-OFF threshold
    ByteSize AS BYTE        ' Number of bits/byte, 4-8
    PARITY AS BYTE          ' 0-4=None,Odd,Even,Mark,Space
    StopBits AS BYTE        ' 0,1,2 = 1, 1.5, 2
    XonChar AS BYTE         ' Tx and Rx X-ON character
    XoffChar AS BYTE        ' Tx and Rx X-OFF character
    ErrorChar AS BYTE       ' Error replacement char
    EofChar AS BYTE         ' End of Input character
    EvtChar AS BYTE         ' Received Event character
    wReserved1 AS WORD      ' Fill for now.
END TYPE

TYPE COMMTIMEOUTS
    ReadIntervalTimeout         AS DWORD   ' Maximum time between read chars.
    ReadTotalTimeoutMultiplier  AS DWORD   ' Multiplier of characters.
    ReadTotalTimeoutConstant    AS DWORD   ' Constant in milliseconds.
    WriteTotalTimeoutMultiplier AS DWORD   ' Multiplier of characters.
    WriteTotalTimeoutConstant   AS DWORD   ' Constant in milliseconds.
END TYPE

TYPE COMMCONFIG
    dwSize            AS DWORD  ' Size of the entire struct
    wVersion          AS WORD   ' version of the structure
    wReserved         AS WORD   ' alignment
    dcbx              AS DCB    ' device control block
    dwProviderSubType AS DWORD  ' ordinal value for identifying
                                '   provider-defined data structure format
    dwProviderOffset  AS DWORD  ' Specifies the offset of provider specific
                                '   data field in bytes from the start
    dwProviderSize    AS DWORD  ' size of the provider-specific data field
'    wcProviderData(0) AS WORD   ' provider-specific data
END TYPE

' [PowerBASIC legacy]
TYPE COMMCONFIGWITHMODEMSETTINGS
    dwSize            AS DWORD  ' Size of the entire struct
    wVersion          AS WORD   ' version of the structure
    wReserved         AS WORD   ' alignment
    dcbx              AS DCB    ' device control block
    dwProviderSubType AS DWORD  ' ordinal value for identifying
                                '   provider-defined data structure format
    dwProviderOffset  AS DWORD  ' Specifies the offset of provider specific
                                '   data field in bytes from the start
    dwProviderSize    AS DWORD  ' size of the provider-specific data field

    dwActualSize         AS DWORD
    dwRequiredSize       AS DWORD
    dwDevSpecificOffset  AS DWORD
    dwDevSpecificSize    AS DWORD

    ' static local options (read/write)
    dwCallSetupFailTimer AS DWORD        ' seconds
    dwInactivityTimeout  AS DWORD        ' seconds
    dwSpeakerVolume      AS DWORD        ' level
    dwSpeakerMode        AS DWORD        ' mode
    dwPreferredModemOptions AS DWORD     ' bitmap

    ' negotiated options (read only) for current or last call
    dwNegotiatedModemOptions AS DWORD    ' bitmap
    dwNegotiatedDCERate  AS DWORD        ' bit/s

    ' Variable portion for proprietary expansion
    abVariablePortion(0 TO 0) AS BYTE    ' array size may vary
END TYPE

TYPE SYSTEM_INFO_type
    wProcessorArchitecture AS WORD
    wReserved              AS WORD
END TYPE

UNION SYSTEM_INFO_union
    dwOemId AS DWORD  ' Obsolete field...do not use
    SYSTEM_INFO_type
END UNION

TYPE SYSTEM_INFO
    SYSTEM_INFO_union
    dwPageSize                  AS DWORD
    lpMinimumApplicationAddress AS DWORD
    lpMaximumApplicationAddress AS DWORD
    dwActiveProcessorMask       AS DWORD
    dwNumberOfProcessors        AS DWORD
    dwProcessorType             AS DWORD
    dwAllocationGranularity     AS DWORD
    wProcessorLevel             AS WORD
    wProcessorRevision          AS WORD
END TYPE

' Global Memory Flags
%GMEM_FIXED         = &H0000
%GMEM_MOVEABLE      = &H0002
%GMEM_NOCOMPACT     = &H0010
%GMEM_NODISCARD     = &H0020
%GMEM_ZEROINIT      = &H0040
%GMEM_MODIFY        = &H0080
%GMEM_DISCARDABLE   = &H0100
%GMEM_NOT_BANKED    = &H1000
%GMEM_SHARE         = &H2000
%GMEM_DDESHARE      = &H2000
%GMEM_NOTIFY        = &H4000
%GMEM_LOWER         = %GMEM_NOT_BANKED
%GMEM_VALID_FLAGS   = &H7F72
%GMEM_INVALID_HANDLE = &H08000

%GHND               = (%GMEM_ZEROINIT OR %GMEM_MOVEABLE)
%GPTR               = (%GMEM_ZEROINIT OR %GMEM_FIXED)

MACRO GlobalLRUNewest(h) = (h)
MACRO GlobalLRUOldest(h) = (h)

FUNCTION GlobalDiscard (BYVAL hMem AS DWORD) AS DWORD
    FUNCTION = GlobalReAlloc(hMem, 0, %GMEM_MOVEABLE)
END FUNCTION

' Flags returned by GlobalFlags (in addition to GMEM_DISCARDABLE)
%GMEM_DISCARDED     = &H4000
%GMEM_LOCKCOUNT     = &H00FF

TYPE MEMORYSTATUS
    dwLength        AS DWORD
    dwMemoryLoad    AS DWORD
    dwTotalPhys     AS DWORD
    dwAvailPhys     AS DWORD
    dwTotalPageFile AS DWORD
    dwAvailPageFile AS DWORD
    dwTotalVirtual  AS DWORD
    dwAvailVirtual  AS DWORD
END TYPE

' Local Memory Flags
%LMEM_FIXED         = &H0000
%LMEM_MOVEABLE      = &H0002
%LMEM_NOCOMPACT     = &H0010
%LMEM_NODISCARD     = &H0020
%LMEM_ZEROINIT      = &H0040
%LMEM_MODIFY        = &H0080
%LMEM_DISCARDABLE   = &H0F00
%LMEM_VALID_FLAGS   = &H0F72
%LMEM_INVALID_HANDLE = &H08000

%LHND               = (%LMEM_ZEROINIT OR %LMEM_MOVEABLE)
%LPTR               = (%LMEM_ZEROINIT OR %LMEM_FIXED)

%NONZEROLHND        = %LMEM_MOVEABLE
%NONZEROLPTR        = %LMEM_FIXED

FUNCTION LocalDiscard (BYVAL hMem AS DWORD) AS DWORD
    FUNCTION = LocalReAlloc(hMem, 0, %LMEM_MOVEABLE)
END FUNCTION

' Flags returned by LocalFlags (in addition to LMEM_DISCARDABLE)
%LMEM_DISCARDED     = &H4000
%LMEM_LOCKCOUNT     = &H00FF

'
' NUMA values
'
%NUMA_NO_PREFERRED_NODE = &HFFFFFFFF???

'
' Process dwCreationFlag values
'

%DEBUG_PROCESS                     = &H00000001
%DEBUG_ONLY_THIS_PROCESS           = &H00000002

%CREATE_SUSPENDED                  = &H00000004

%DETACHED_PROCESS                  = &H00000008

%CREATE_NEW_CONSOLE                = &H00000010

%NORMAL_PRIORITY_CLASS             = &H00000020
%IDLE_PRIORITY_CLASS               = &H00000040
%HIGH_PRIORITY_CLASS               = &H00000080
%REALTIME_PRIORITY_CLASS           = &H00000100

%CREATE_NEW_PROCESS_GROUP          = &H00000200
%CREATE_UNICODE_ENVIRONMENT        = &H00000400

%CREATE_SEPARATE_WOW_VDM           = &H00000800
%CREATE_SHARED_WOW_VDM             = &H00001000
%CREATE_FORCEDOS                   = &H00002000

%BELOW_NORMAL_PRIORITY_CLASS       = &H00004000
%ABOVE_NORMAL_PRIORITY_CLASS       = &H00008000

%INHERIT_PARENT_AFFINITY           = &H00010000

%INHERIT_CALLER_PRIORITY           = &H00020000  ' deprecated
%CREATE_PROTECTED_PROCESS          = &H00040000
%EXTENDED_STARTUPINFO_PRESENT      = &H00080000

%PROCESS_MODE_BACKGROUND_BEGIN     = &H00100000
%PROCESS_MODE_BACKGROUND_END       = &H00200000

%CREATE_BREAKAWAY_FROM_JOB         = &H01000000
%CREATE_PRESERVE_CODE_AUTHZ_LEVEL  = &H02000000

%CREATE_DEFAULT_ERROR_MODE         = &H04000000

%CREATE_NO_WINDOW                  = &H08000000

%PROFILE_USER                      = &H10000000
%PROFILE_KERNEL                    = &H20000000
%PROFILE_SERVER                    = &H40000000

%CREATE_IGNORE_SYSTEM_DEFAULT      = &H80000000???

'
' Thread dwCreationFlag values
'

'%CREATE_SUSPENDED                  = &H00000004

%STACK_SIZE_PARAM_IS_A_RESERVATION = &H00010000    ' Threads only

'
' Priority flags
'
%THREAD_PRIORITY_LOWEST          = %THREAD_BASE_PRIORITY_MIN
%THREAD_PRIORITY_BELOW_NORMAL    = (%THREAD_PRIORITY_LOWEST + 1)
%THREAD_PRIORITY_NORMAL          = 0
%THREAD_PRIORITY_HIGHEST         = %THREAD_BASE_PRIORITY_MAX
%THREAD_PRIORITY_ABOVE_NORMAL    = (%THREAD_PRIORITY_HIGHEST - 1)
%THREAD_PRIORITY_ERROR_RETURN    = &H7FFFFFFF&

%THREAD_PRIORITY_TIME_CRITICAL   = %THREAD_BASE_PRIORITY_LOWRT
%THREAD_PRIORITY_IDLE            = %THREAD_BASE_PRIORITY_IDLE

%THREAD_MODE_BACKGROUND_BEGIN   = &H00010000
%THREAD_MODE_BACKGROUND_END     = &H00020000

'
' GetFinalPathNameByHandle
'

%VOLUME_NAME_DOS  = &H0      ' default
%VOLUME_NAME_GUID = &H1
%VOLUME_NAME_NT   = &H2
%VOLUME_NAME_NONE = &H4

%FILE_NAME_NORMALIZED = &H0  'default
%FILE_NAME_OPENED     = &H8

'
' Debug APIs
'
%EXCEPTION_DEBUG_EVENT      = 1
%CREATE_THREAD_DEBUG_EVENT  = 2
%CREATE_PROCESS_DEBUG_EVENT = 3
%EXIT_THREAD_DEBUG_EVENT    = 4
%EXIT_PROCESS_DEBUG_EVENT   = 5
%LOAD_DLL_DEBUG_EVENT       = 6
%UNLOAD_DLL_DEBUG_EVENT     = 7
%OUTPUT_DEBUG_STRING_EVENT  = 8
%RIP_EVENT                  = 9

TYPE EXCEPTION_DEBUG_INFO
    ExceptionRecord AS EXCEPTION_RECORD
    dwFirstChance   AS DWORD
END TYPE

TYPE CREATE_THREAD_DEBUG_INFO
    hThread           AS DWORD
    lpThreadLocalBase AS DWORD
    lpStartAddress    AS DWORD
END TYPE

TYPE CREATE_PROCESS_DEBUG_INFO
    hFile                 AS DWORD
    hProcess              AS DWORD
    hThread               AS DWORD
    lpBaseOfImage         AS DWORD
    dwDebugInfoFileOffset AS DWORD
    nDebugInfoSize        AS DWORD
    lpThreadLocalBase     AS DWORD
    lpStartAddress        AS DWORD
    lpImageName           AS DWORD
    fUnicode              AS WORD
END TYPE

TYPE EXIT_THREAD_DEBUG_INFO
    dwExitCode AS DWORD
END TYPE

TYPE EXIT_PROCESS_DEBUG_INFO
    dwExitCode AS DWORD
END TYPE

TYPE LOAD_DLL_DEBUG_INFO
    hFile                 AS DWORD
    lpBaseOfDll           AS DWORD
    dwDebugInfoFileOffset AS DWORD
    nDebugInfoSize        AS DWORD
    lpImageName           AS DWORD
    fUnicode              AS WORD
END TYPE

TYPE UNLOAD_DLL_DEBUG_INFO
    lpBaseOfDll AS DWORD
END TYPE

TYPE OUTPUT_DEBUG_STRING_INFO
    lpDebugStringData  AS ASCIIZ PTR
    fUnicode           AS WORD ' [unused. string is always ASCIIZ.]
    nDebugStringLength AS WORD
END TYPE

TYPE RIP_INFO
    dwError AS DWORD
    dwType  AS DWORD
END TYPE

UNION DEBUGEVENT_union
    deuException         AS EXCEPTION_DEBUG_INFO
    deuCreateThread      AS CREATE_THREAD_DEBUG_INFO
    deuCreateProcessInfo AS CREATE_PROCESS_DEBUG_INFO
    deuExitThread        AS EXIT_THREAD_DEBUG_INFO
    deuExitProcess       AS EXIT_PROCESS_DEBUG_INFO
    deuLoadDll           AS LOAD_DLL_DEBUG_INFO
    deuUnloadDll         AS UNLOAD_DLL_DEBUG_INFO
    deuDebugString       AS OUTPUT_DEBUG_STRING_INFO
    deuRipInfo           AS RIP_INFO
END UNION

' [PowerBASIC legacy]
MACRO DEBUGEVENTUNION=DebugEvent_Union

TYPE DEBUG_EVENT
    dwDebugEventCode AS DWORD
    dwProcessId      AS DWORD
    dwThreadId       AS DWORD
    u                AS DebugEvent_Union
END TYPE


'
' JIT Debugging Info. This structure is defined to have constant size in
' both the emulated and native environment.
'

TYPE JIT_DEBUG_INFO
    dwSize                  AS DWORD
    dwProcessorArchitecture AS DWORD
    dwThreadID              AS DWORD
    dwReserved0             AS DWORD
    lpExceptionAddress      AS QUAD
    lpExceptionRecord       AS QUAD
    lpContextRecord         AS QUAD
END TYPE

%DRIVE_UNKNOWN     = 0
%DRIVE_NO_ROOT_DIR = 1
%DRIVE_REMOVABLE   = 2
%DRIVE_FIXED       = 3
%DRIVE_REMOTE      = 4
%DRIVE_CDROM       = 5
%DRIVE_RAMDISK     = 6


#IF NOT %DEF(%MAC)
FUNCTION GetFreeSpace (BYVAL w AS DWORD) AS LONG
    FUNCTION = &H100000&
END FUNCTION
#ENDIF


%FILE_TYPE_UNKNOWN  = &H0000
%FILE_TYPE_DISK     = &H0001
%FILE_TYPE_CHAR     = &H0002
%FILE_TYPE_PIPE     = &H0003
%FILE_TYPE_REMOTE   = &H08000


%STD_INPUT_HANDLE  = &HFFFFFFF6???  '(DWORD)-10
%STD_OUTPUT_HANDLE = &HFFFFFFF5???  '(DWORD)-11
%STD_ERROR_HANDLE  = &HFFFFFFF4???  '(DWORD)-12

%NOPARITY          = 0
%ODDPARITY         = 1
%EVENPARITY        = 2
%MARKPARITY        = 3
%SPACEPARITY       = 4

%ONESTOPBIT        = 0
%ONE5STOPBITS      = 1
%TWOSTOPBITS       = 2

%IGNORE   = 0               ' Ignore signal
%INFINITE = &HFFFFFFFF???   ' Infinite timeout

'
' Baud rates at which the communication device operates
'

%CBR_110           = 110
%CBR_300           = 300
%CBR_600           = 600
%CBR_1200          = 1200
%CBR_2400          = 2400
%CBR_4800          = 4800
%CBR_9600          = 9600
%CBR_14400         = 14400
%CBR_19200         = 19200
%CBR_38400         = 38400
%CBR_56000         = 56000
%CBR_57600         = 57600
%CBR_115200        = 115200
%CBR_128000        = 128000
%CBR_256000        = 256000

'
' Error Flags
'

%CE_RXOVER          = &H0001  ' Receive Queue overflow
%CE_OVERRUN         = &H0002  ' Receive Overrun Error
%CE_RXPARITY        = &H0004  ' Receive Parity Error
%CE_FRAME           = &H0008  ' Receive Framing error
%CE_BREAK           = &H0010  ' Break Detected
%CE_TXFULL          = &H0100  ' TX Queue is full
%CE_PTO             = &H0200  ' LPTx Timeout
%CE_IOE             = &H0400  ' LPTx I/O Error
%CE_DNS             = &H0800  ' LPTx Device not selected
%CE_OOP             = &H1000  ' LPTx Out-Of-Paper
%CE_MODE            = &H08000 ' Requested mode unsupported

%IE_BADID           = (-1)    ' Invalid or unsupported id
%IE_OPEN            = (-2)    ' Device Already Open
%IE_NOPEN           = (-3)    ' Device Not Open
%IE_MEMORY          = (-4)    ' Unable to allocate queues
%IE_DEFAULT         = (-5)    ' Error in default parameters
%IE_HARDWARE        = (-10)   ' Hardware Not Present
%IE_BYTESIZE        = (-11)   ' Illegal Byte Size
%IE_BAUDRATE        = (-12)   ' Unsupported BaudRate

'
' Events
'

%EV_RXCHAR          = &H0001  ' Any Character received
%EV_RXFLAG          = &H0002  ' Received certain character
%EV_TXEMPTY         = &H0004  ' Transmitt Queue Empty
%EV_CTS             = &H0008  ' CTS changed state
%EV_DSR             = &H0010  ' DSR changed state
%EV_RLSD            = &H0020  ' RLSD changed state
%EV_BREAK           = &H0040  ' BREAK received
%EV_ERR             = &H0080  ' Line status error occurred
%EV_RING            = &H0100  ' Ring signal detected
%EV_PERR            = &H0200  ' Printer error occured
%EV_RX80FULL        = &H0400  ' Receive buffer is 80 percent full
%EV_EVENT1          = &H0800  ' Provider specific event 1
%EV_EVENT2          = &H1000  ' Provider specific event 2

'
' Escape Functions
'

%SETXOFF           = 1       ' Simulate XOFF received
%SETXON            = 2       ' Simulate XON received
%SETRTS            = 3       ' Set RTS high
%CLRRTS            = 4       ' Set RTS low
%SETDTR            = 5       ' Set DTR high
%CLRDTR            = 6       ' Set DTR low
%RESETDEV          = 7       ' Reset device if possible
%SETBREAK          = 8       ' Set the device break line.
%CLRBREAK          = 9       ' Clear the device break line.

'
' PURGE function flags.
'
%PURGE_TXABORT      = &H0001  ' Kill the pending/current writes to the comm port.
%PURGE_RXABORT      = &H0002  ' Kill the pending/current reads to the comm port.
%PURGE_TXCLEAR      = &H0004  ' Kill the transmit queue if there.
%PURGE_RXCLEAR      = &H0008  ' Kill the typeahead buffer if there.

%LPTx               = &H80?   ' Set if ID is for LPT device

'
' Modem Status Flags
'
%MS_CTS_ON          = &H0010
%MS_DSR_ON          = &H0020
%MS_RING_ON         = &H0040
%MS_RLSD_ON         = &H0080

'
' WaitSoundState() Constants
'

%S_QUEUEEMPTY       = 0
%S_THRESHOLD        = 1
%S_ALLTHRESHOLD     = 2

'
' Accent Modes
'

%S_NORMAL     = 0
%S_LEGATO     = 1
%S_STACCATO   = 2

'
' SetSoundNoise() Sources
'

%S_PERIOD512   = 0     ' Freq = N/512 high pitch, less coarse hiss
%S_PERIOD1024  = 1     ' Freq = N/1024
%S_PERIOD2048  = 2     ' Freq = N/2048 low pitch, more coarse hiss
%S_PERIODVOICE = 3     ' Source is frequency from voice channel (3)
%S_WHITE512    = 4     ' Freq = N/512 high pitch, less coarse hiss
%S_WHITE1024   = 5     ' Freq = N/1024
%S_WHITE2048   = 6     ' Freq = N/2048 low pitch, more coarse hiss
%S_WHITEVOICE  = 7     ' Source is frequency from voice channel (3)

%S_SERDVNA     = (-1)  ' Device not available
%S_SEROFM      = (-2)  ' Out of memory
%S_SERMACT     = (-3)  ' Music active
%S_SERQFUL     = (-4)  ' Queue full
%S_SERBDNT     = (-5)  ' Invalid note
%S_SERDLN      = (-6)  ' Invalid note length
%S_SERDCC      = (-7)  ' Invalid note count
%S_SERDTP      = (-8)  ' Invalid tempo
%S_SERDVL      = (-9)  ' Invalid volume
%S_SERDMD      = (-10) ' Invalid mode
%S_SERDSH      = (-11) ' Invalid shape
%S_SERDPT      = (-12) ' Invalid pitch
%S_SERDFQ      = (-13) ' Invalid frequency
%S_SERDDR      = (-14) ' Invalid duration
%S_SERDSR      = (-15) ' Invalid source
%S_SERDST      = (-16) ' Invalid state

%NMPWAIT_WAIT_FOREVER           = &Hffffffff???
%NMPWAIT_NOWAIT                 = &H00000001
%NMPWAIT_USE_DEFAULT_WAIT       = &H00000000

%FS_CASE_IS_PRESERVED           = %FILE_CASE_PRESERVED_NAMES
%FS_CASE_SENSITIVE              = %FILE_CASE_SENSITIVE_SEARCH
%FS_UNICODE_STORED_ON_DISK      = %FILE_UNICODE_ON_DISK
%FS_PERSISTENT_ACLS             = %FILE_PERSISTENT_ACLS
%FS_VOL_IS_COMPRESSED           = %FILE_VOLUME_IS_COMPRESSED
%FS_FILE_COMPRESSION            = %FILE_FILE_COMPRESSION
%FS_FILE_ENCRYPTION             = %FILE_SUPPORTS_ENCRYPTION

%FILE_MAP_COPY       = %SECTION_QUERY
%FILE_MAP_WRITE      = %SECTION_MAP_WRITE
%FILE_MAP_READ       = %SECTION_MAP_READ
%FILE_MAP_ALL_ACCESS = %SECTION_ALL_ACCESS
%FILE_MAP_EXECUTE    = %SECTION_MAP_EXECUTE_EXPLICIT    ' not included in FILE_MAP_ALL_ACCESS

%OF_READ            = &H00000000
%OF_WRITE           = &H00000001
%OF_READWRITE       = &H00000002
%OF_SHARE_COMPAT    = &H00000000
%OF_SHARE_EXCLUSIVE = &H00000010
%OF_SHARE_DENY_WRITE= &H00000020
%OF_SHARE_DENY_READ = &H00000030
%OF_SHARE_DENY_NONE = &H00000040
%OF_PARSE           = &H00000100
%OF_DELETE          = &H00000200
%OF_VERIFY          = &H00000400
%OF_CANCEL          = &H00000800
%OF_CREATE          = &H00001000
%OF_PROMPT          = &H00002000
%OF_EXIST           = &H00004000
%OF_REOPEN          = &H00008000

%OFS_MAXPATHNAME = 128

TYPE OFSTRUCT
    cBytes     AS BYTE
    fFixedDisk AS BYTE
    nErrCode   AS WORD
    Reserved1  AS WORD
    Reserved2  AS WORD
    szPathName AS ASCIIZ * %OFS_MAXPATHNAME
END TYPE

DECLARE FUNCTION InterlockedIncrement LIB "Kernel32.dll" _
    ALIAS "InterlockedIncrement" (lpAddend AS LONG) AS LONG

DECLARE FUNCTION InterlockedDecrement LIB "Kernel32.dll" _
    ALIAS "InterlockedDecrement" (lpAddend AS LONG) AS LONG

DECLARE FUNCTION InterlockedExchange LIB "Kernel32.dll" _
    ALIAS "InterlockedExchange" (xTarget AS LONG, BYVAL xValue AS LONG) AS LONG

DECLARE FUNCTION InterlockedExchangePointer LIB "Kernel32.dll" _
    ALIAS "InterlockedExchange" (xTarget AS LONG, BYVAL xValue AS LONG) AS LONG

DECLARE FUNCTION InterlockedExchangeAdd LIB "Kernel32.dll" _
    ALIAS "InterlockedExchangeAdd" (Addend AS LONG, BYVAL xValue AS LONG) _
    AS LONG

DECLARE FUNCTION InterlockedCompareExchange LIB "Kernel32.dll" _
    ALIAS "InterlockedCompareExchange" (Destination AS LONG, _
    BYVAL Exchange AS LONG, BYVAL Comperand AS LONG) AS LONG

#IF %WIN32_WINNT >= &H0502

DECLARE FUNCTION InterlockedCompareExchange64 LIB "Kernel32.dll" _
    ALIAS "InterlockedCompareExchange64" (Destination AS QUAD, _
    BYVAL Exchange AS QUAD, BYVAL Comperand AS QUAD) AS QUAD

#ENDIF

#IF (%WIN32_WINNT >= &H0502)

MACRO FUNCTION InterlockedAnd64 (qDestination, qValue)
    MACROTEMP qOld
    LOCAL qOld AS QUAD
    DO
        qOld = PEEK(QUAD,qDestination)
    LOOP WHILE InterlockedCompareExchange64(qDestination, qOld AND qValue, qOld) <> qOld
END MACRO=qOld

MACRO FUNCTION InterlockedOr64 (qDestination, qValue)
    MACROTEMP qOld
    LOCAL qOld AS QUAD
    DO
        qOld = PEEK(QUAD,qDestination)
    LOOP WHILE InterlockedCompareExchange64(qDestination, qOld OR qValue, qOld) <> qOld
END MACRO=qOld

MACRO FUNCTION InterlockedXor64 (qDestination, qValue)
    MACROTEMP qOld
    LOCAL qOld AS QUAD
    DO
        qOld = PEEK(QUAD,qDestination)
    LOOP WHILE InterlockedCompareExchange64(qDestination, qOld XOR qValue, qOld) <> qOld
END MACRO=qOld

MACRO FUNCTION InterlockedIncrement64 (qDestination)
    MACROTEMP qOld
    LOCAL qOld AS QUAD
    DO
        qOld = PEEK(QUAD,qDestination)
    LOOP WHILE InterlockedCompareExchange64(qDestination, qOld + 1, qOld) <> qOld
END MACRO=(qOld+1)

MACRO FUNCTION InterlockedDecrement64 (qDestination)
    MACROTEMP qOld
    LOCAL qOld AS QUAD
    DO
        qOld = PEEK(QUAD,qDestination)
    LOOP WHILE InterlockedCompareExchange64(qDestination, qOld - 1, qOld) <> qOld
END MACRO=(qOld-1)

MACRO FUNCTION InterlockedExchange64 (qDestination, qValue)
    MACROTEMP qOld
    LOCAL qOld AS QUAD
    DO
        qOld = PEEK(QUAD,qDestination)
    LOOP WHILE InterlockedCompareExchange64(qDestination, qValue, qOld) <> qOld
END MACRO=qOld

MACRO FUNCTION InterlockedExchangeAdd64 (qDestination, qValue)
    MACROTEMP qOld
    LOCAL qOld AS QUAD
    DO
        qOld = PEEK(QUAD,qDestination)
    LOOP WHILE InterlockedCompareExchange64(qDestination, qOld + qValue, qOld) <> qOld
END MACRO=qOld

#ENDIF  ' #IF (%WIN32_WINNT >= &H0502)


DECLARE FUNCTION FreeResource LIB "Kernel32.dll" ALIAS "FreeResource" _
    (BYVAL hResData AS DWORD) AS LONG

DECLARE FUNCTION LockResource LIB "Kernel32.dll" ALIAS "LockResource" _
    (BYVAL hResData AS DWORD) AS DWORD

%MAXINTATOM = &H0C000
%INVALID_ATOM = 0

DECLARE FUNCTION FreeLibrary LIB "Kernel32.dll" ALIAS "FreeLibrary" _
    (BYVAL hLibModule AS DWORD) AS LONG

DECLARE SUB FreeLibraryAndExitThread LIB "Kernel32.dll" _
    ALIAS "FreeLibraryAndExitThread" (BYVAL hLibModule AS DWORD, _
    BYVAL dwExitCode AS DWORD)

DECLARE FUNCTION DisableThreadLibraryCalls LIB "Kernel32.dll" _
    ALIAS "DisableThreadLibraryCalls" (BYVAL hLibModule AS DWORD) AS LONG

DECLARE FUNCTION GetProcAddress LIB "Kernel32.dll" ALIAS "GetProcAddress" _
    (BYVAL hModule AS DWORD, lpProcName AS ASCIIZ) AS LONG

DECLARE FUNCTION GetVersion LIB "Kernel32.dll" ALIAS "GetVersion" () AS DWORD

DECLARE FUNCTION GlobalAlloc LIB "Kernel32.dll" ALIAS "GlobalAlloc" _
    (BYVAL uFlags AS DWORD, BYVAL dwBytes AS DWORD) AS DWORD

DECLARE FUNCTION GlobalReAlloc LIB "Kernel32.dll" ALIAS "GlobalReAlloc" _
    (BYVAL hMem AS DWORD, BYVAL dwBytes AS DWORD, BYVAL uFlags AS DWORD) AS DWORD

DECLARE FUNCTION GlobalSize LIB "Kernel32.dll" ALIAS "GlobalSize" _
    (BYVAL hMem AS DWORD) AS DWORD

DECLARE FUNCTION GlobalFlags LIB "Kernel32.dll" ALIAS "GlobalFlags" _
    (BYVAL hMem AS DWORD) AS DWORD

DECLARE FUNCTION GlobalLock LIB "Kernel32.dll" ALIAS "GlobalLock" _
    (BYVAL hMem AS DWORD) AS DWORD

DECLARE FUNCTION GlobalHandle LIB "Kernel32.dll" ALIAS "GlobalHandle" _
    (BYVAL pMem AS DWORD) AS DWORD

DECLARE FUNCTION GlobalUnlock LIB "Kernel32.dll" ALIAS "GlobalUnlock" _
    (BYVAL hMem AS DWORD) AS LONG

DECLARE FUNCTION GlobalFree LIB "Kernel32.dll" ALIAS "GlobalFree" _
    (BYVAL hMem AS DWORD) AS DWORD

DECLARE FUNCTION GlobalCompact LIB "Kernel32.dll" ALIAS "GlobalCompact" _
    (BYVAL dwMinFree AS DWORD) AS DWORD

DECLARE SUB GlobalFix LIB "Kernel32.dll" ALIAS "GlobalFix" (BYVAL hMem AS DWORD)

DECLARE SUB GlobalUnfix LIB "Kernel32.dll" ALIAS "GlobalUnfix" _
    (BYVAL hMem AS DWORD)

DECLARE FUNCTION GlobalWire LIB "Kernel32.dll" ALIAS "GlobalWire" _
    (BYVAL hMem AS DWORD) AS DWORD

DECLARE FUNCTION GlobalUnWire LIB "Kernel32.dll" ALIAS "GlobalUnWire" _
    (BYVAL hMem AS DWORD) AS LONG

DECLARE SUB GlobalMemoryStatus LIB "Kernel32.dll" ALIAS "GlobalMemoryStatus" _
    (lpBuffer AS MEMORYSTATUS)

TYPE MEMORYSTATUSEX
    dwLength         AS DWORD
    dwMemoryLoad     AS DWORD
    ullTotalPhys     AS QUAD
    ullAvailPhys     AS QUAD
    ullTotalPageFile AS QUAD
    ullAvailPageFile AS QUAD
    ullTotalVirtual  AS QUAD
    ullAvailVirtual  AS QUAD
    ullAvailExtendedVirtual AS QUAD
END TYPE

DECLARE FUNCTION GlobalMemoryStatusEx LIB "Kernel32.dll" _
    ALIAS "GlobalMemoryStatusEx" (lpBuffer AS MEMORYSTATUSEX) AS LONG

DECLARE FUNCTION LocalAlloc LIB "Kernel32.dll" ALIAS "LocalAlloc" _
    (BYVAL uFlags AS DWORD, BYVAL lBytes AS DWORD) AS DWORD

DECLARE FUNCTION LocalReAlloc LIB "Kernel32.dll" ALIAS "LocalReAlloc" _
    (BYVAL hMem AS DWORD, BYVAL lBytes AS DWORD, BYVAL uFlags AS DWORD) AS DWORD

DECLARE FUNCTION LocalLock LIB "Kernel32.dll" ALIAS "LocalLock" _
    (BYVAL hMem AS DWORD) AS DWORD

DECLARE FUNCTION LocalHandle LIB "Kernel32.dll" ALIAS "LocalHandle" _
    (BYVAL pMem AS DWORD) AS DWORD

DECLARE FUNCTION LocalUnlock LIB "Kernel32.dll" ALIAS "LocalUnlock" _
    (BYVAL hMem AS DWORD) AS LONG

DECLARE FUNCTION LocalSize LIB "Kernel32.dll" ALIAS "LocalSize" _
    (BYVAL hMem AS DWORD) AS DWORD

DECLARE FUNCTION LocalFlags LIB "Kernel32.dll" ALIAS "LocalFlags" _
    (BYVAL hMem AS DWORD) AS DWORD

DECLARE FUNCTION LocalFree LIB "Kernel32.dll" ALIAS "LocalFree" _
    (BYVAL hMem AS DWORD) AS DWORD

DECLARE FUNCTION LocalShrink LIB "Kernel32.dll" ALIAS "LocalShrink" _
    (BYVAL hMem AS DWORD, BYVAL cbNewSize AS DWORD) AS DWORD

DECLARE FUNCTION LocalCompact LIB "Kernel32.dll" ALIAS "LocalCompact" _
    (BYVAL uMinFree AS DWORD) AS DWORD

DECLARE FUNCTION FlushInstructionCache LIB "Kernel32.dll" _
    ALIAS "FlushInstructionCache" (BYVAL hProcess AS DWORD, _
    BYVAL lpBaseAddress AS DWORD, BYVAL dwSize AS DWORD) AS LONG

#IF (%WIN32_WINNT >= &H0600)

DECLARE SUB FlushProcessWriteBuffers LIB "Kernel32.dll" _
    ALIAS "FlushProcessWriteBuffers" ()

DECLARE FUNCTION QueryThreadCycleTime LIB "Kernel32.dll" _
    ALIAS "QueryThreadCycleTime" (BYVAL ThreadHandle AS DWORD, _
    CycleTime AS QUAD) AS LONG

DECLARE FUNCTION QueryIdleProcessorCycleTime LIB "Kernel32.dll" _
    ALIAS "QueryIdleProcessorCycleTime" (BufferLength AS DWORD, _
    BYVAL ProcessorIdleCycleTime AS QUAD PTR) AS LONG

#ENDIF

#IF (%WIN32_WINNT >= &H0601)

DECLARE FUNCTION QueryIdleProcessorCycleTimeEx LIB "Kernel32.dll" _
    ALIAS "QueryIdleProcessorCycleTimeEx" (BYVAL Group AS WORD, _
    BufferLength AS DWORD, _
    BYVAL ProcessorIdleCycleTime AS QUAD PTR) AS LONG

DECLARE FUNCTION QueryUnbiasedInterruptTime LIB "Kernel32.dll" _
    ALIAS "QueryUnbiasedInterruptTime" (UnbiasedTime AS QUAD) AS LONG

DECLARE FUNCTION GetProcessorSystemCycleTime LIB "Kernel32.dll" _
    ALIAS "GetProcessorSystemCycleTime" (BYVAL Group AS WORD, _
    Buffer AS SYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION, _
    ReturnedLength AS DWORD) AS LONG

#ENDIF  ' (%WIN32_WINNT >= &H0601)

DECLARE FUNCTION VirtualAlloc LIB "Kernel32.dll" ALIAS "VirtualAlloc" _
    (BYVAL lpAddress AS DWORD, BYVAL dwSize AS DWORD, _
    BYVAL flAllocationType AS DWORD, BYVAL flProtect AS DWORD) AS DWORD

DECLARE FUNCTION VirtualFree LIB "Kernel32.dll" ALIAS "VirtualFree" _
    (BYVAL lpAddress AS DWORD, BYVAL dwSize AS DWORD, _
    BYVAL dwFreeType AS DWORD) AS LONG

DECLARE FUNCTION VirtualProtect LIB "Kernel32.dll" ALIAS "VirtualProtect" _
    (BYVAL lpAddress AS DWORD, BYVAL dwSize AS DWORD, _
    BYVAL flNewProtect AS DWORD, lpflOldProtect AS LONG) AS LONG

DECLARE FUNCTION VirtualQuery LIB "Kernel32.dll" ALIAS "VirtualQuery" _
    (BYVAL lpAddress AS DWORD, lpBuffer AS MEMORY_BASIC_INFORMATION, _
    BYVAL dwLength AS DWORD) AS DWORD

DECLARE FUNCTION VirtualAllocEx LIB "Kernel32.dll" ALIAS "VirtualAllocEx" _
    (BYVAL hProcess AS DWORD, BYVAL lpAddress AS DWORD, BYVAL dwSize AS DWORD, _
    BYVAL flAllocationType AS DWORD, BYVAL flProtect AS DWORD) AS DWORD

#IF %WIN32_WINNT >= &H0600

DECLARE FUNCTION VirtualAllocExNuma LIB "Kernel32.dll" _
    ALIAS "VirtualAllocExNuma" (BYVAL hprocess AS DWORD, _
    BYVAL lpAddress AS DWORD, BYVAL dwSize AS DWORD, _
    BYVAL flAllocationType AS DWORD, BYVAL flProtect AS DWORD, _
    BYVAL nndPreferred AS DWORD) AS DWORD

#ENDIF ' %WIN32_WINNT >= &H0600

DECLARE FUNCTION GetWriteWatch LIB "Kernel32.dll" ALIAS "GetWriteWatch" _
    (BYVAL dwFlags AS DWORD, BYVAL lpBaseAddress AS DWORD, _
    BYVAL dwRegionSize AS DWORD, lpAddresses AS DWORD, lpdwCount AS DWORD, _
    lpdwGranularity AS DWORD) AS DWORD

DECLARE FUNCTION ResetWriteWatch LIB "Kernel32.dll" ALIAS "ResetWriteWatch" _
    (BYVAL lpBaseAddress AS DWORD, BYVAL dwRegionSize AS DWORD) AS DWORD

DECLARE FUNCTION GetLargePageMinimum LIB "Kernel32.dll" _
    ALIAS "GetLargePageMinimum" () AS DWORD

DECLARE FUNCTION EnumSystemFirmwareTables LIB "Kernel32.dll" _
    ALIAS "EnumSystemFirmwareTables" _
    (BYVAL FirmwareTableProviderSignature AS DWORD, _
    BYVAL pFirmwareTableEnumBuffer AS DWORD, BYVAL BufferSize AS DWORD) AS DWORD

DECLARE FUNCTION GetSystemFirmwareTable LIB "Kernel32.dll" _
    ALIAS "GetSystemFirmwareTable" _
    (BYVAL FirmwareTableProviderSignature AS DWORD, _
    BYVAL FirmwareTableID AS DWORD, BYVAL pFirmwareTableBuffer AS DWORD, _
    BYVAL BufferSize AS DWORD) AS DWORD

DECLARE FUNCTION GetPhysicallyInstalledSystemMemory LIB "Kernel32.dll" _
    ALIAS "GetPhysicallyInstalledSystemMemory" _
    (TotalMemoryInKilobytes AS QUAD) AS LONG

DECLARE FUNCTION VirtualFreeEx LIB "Kernel32.dll" ALIAS "VirtualFreeEx" _
    (BYVAL hProcess AS DWORD, BYVAL lpAddress AS DWORD, BYVAL dwSize AS DWORD, _
    BYVAL dwFreeType AS DWORD) AS LONG

DECLARE FUNCTION VirtualProtectEx LIB "Kernel32.dll" ALIAS "VirtualProtectEx" _
    (BYVAL hProcess AS DWORD, BYVAL lpAddress AS DWORD, BYVAL dwSize AS DWORD, _
    BYVAL flNewProtect AS DWORD, lpflOldProtect AS DWORD) AS LONG

DECLARE FUNCTION VirtualQueryEx LIB "Kernel32.dll" ALIAS "VirtualQueryEx" _
    (BYVAL hProcess AS DWORD, BYVAL lpAddress AS DWORD, _
    lpBuffer AS MEMORY_BASIC_INFORMATION, BYVAL dwLength AS DWORD) AS LONG

DECLARE FUNCTION HeapCreate LIB "Kernel32.dll" ALIAS "HeapCreate" _
    (BYVAL flOptions AS DWORD, BYVAL dwInitialSize AS DWORD, _
    BYVAL dwMaximumSize AS DWORD) AS DWORD

DECLARE FUNCTION HeapDestroy LIB "Kernel32.dll" ALIAS "HeapDestroy" _
    (BYVAL hHeap AS DWORD) AS LONG

DECLARE FUNCTION HeapAlloc LIB "Kernel32.dll" ALIAS "HeapAlloc" _
    (BYVAL hHeap AS DWORD, BYVAL dwFlags AS DWORD, BYVAL dwBytes AS DWORD) _
    AS DWORD

DECLARE FUNCTION HeapReAlloc LIB "Kernel32.dll" ALIAS "HeapReAlloc" _
    (BYVAL hHeap AS DWORD, BYVAL dwFlags AS DWORD, BYVAL lpMem AS DWORD, _
    BYVAL dwBytes AS DWORD) AS DWORD

DECLARE FUNCTION HeapFree LIB "Kernel32.dll" ALIAS "HeapFree" _
    (BYVAL hHeap AS DWORD, BYVAL dwFlags AS DWORD, BYVAL lpMem AS DWORD) AS LONG

DECLARE FUNCTION HeapSize LIB "Kernel32.dll" ALIAS "HeapSize" _
    (BYVAL hHeap AS DWORD, BYVAL dwFlags AS DWORD, BYVAL lpMem AS DWORD) AS DWORD

DECLARE FUNCTION HeapValidate LIB "Kernel32.dll" ALIAS "HeapValidate" _
    (BYVAL hHeap AS DWORD, BYVAL dwFlags AS DWORD, BYVAL lpMem AS DWORD) AS LONG

DECLARE FUNCTION HeapCompact LIB "Kernel32.dll" ALIAS "HeapCompact" _
    (BYVAL hHeap AS DWORD, BYVAL dwFlags AS DWORD) AS DWORD

DECLARE FUNCTION GetProcessHeap LIB "Kernel32.dll" ALIAS "GetProcessHeap" _
    () AS DWORD

DECLARE FUNCTION GetProcessHeaps LIB "Kernel32.dll" ALIAS "GetProcessHeaps" _
    (BYVAL NumberOfHeaps AS DWORD, BYVAL ProcessHeaps AS DWORD) AS DWORD

TYPE pheBlock
    hMem          AS DWORD
    dwReserved(2) AS DWORD
END TYPE

TYPE pheRegion
    dwCommittedSize   AS DWORD
    dwUnCommittedSize AS DWORD
    lpFirstBlock      AS DWORD
    lpLastBlock       AS DWORD
END TYPE

UNION pheUnion
    pheBlock
    pheRegion
END UNION

TYPE PROCESS_HEAP_ENTRY
    lpData       AS DWORD
    cbData       AS DWORD
    cbOverhead   AS BYTE
    iRegionIndex AS BYTE
    wFlags       AS WORD
    pheUnion
END TYPE

%PROCESS_HEAP_REGION            = &H0001
%PROCESS_HEAP_UNCOMMITTED_RANGE = &H0002
%PROCESS_HEAP_ENTRY_BUSY        = &H0004
%PROCESS_HEAP_ENTRY_MOVEABLE    = &H0010
%PROCESS_HEAP_ENTRY_DDESHARE    = &H0020

DECLARE FUNCTION HeapLock LIB "Kernel32.dll" ALIAS "HeapLock" _
    (BYVAL hHeap AS DWORD) AS LONG

DECLARE FUNCTION HeapUnlock LIB "Kernel32.dll" ALIAS "HeapUnlock" _
    (BYVAL hHeap AS DWORD) AS LONG

DECLARE FUNCTION HeapWalk LIB "Kernel32.dll" ALIAS "HeapWalk" _
    (BYVAL hHelp AS DWORD, lpEntry AS PROCESS_HEAP_ENTRY) AS LONG

DECLARE FUNCTION HeapSetInformation LIB "Kernel32.dll" _
    ALIAS "HeapSetInformation" (BYVAL HeapHandle AS DWORD, _
    BYVAL HeapInformationClass AS DWORD, HeapInformation AS DWORD, _
    BYVAL HeapInformationLength AS DWORD) AS LONG

DECLARE FUNCTION HeapQueryInformation LIB "Kernel32.dll" _
    ALIAS "HeapQueryInformation" (BYVAL HeapHandle AS DWORD, _
    BYVAL HeapInformationClass AS DWORD, HeapInformation AS DWORD, _
    BYVAL HeapInformationLength AS DWORD, ReturnLength AS DWORD) AS LONG

' GetBinaryType return values.

%SCS_32BIT_BINARY   = 0
%SCS_DOS_BINARY     = 1
%SCS_WOW_BINARY     = 2
%SCS_PIF_BINARY     = 3
%SCS_POSIX_BINARY   = 4
%SCS_OS216_BINARY   = 5
%SCS_64BIT_BINARY   = 6

#IF %DEF(%WIN64)
%SCS_THIS_PLATFORM_BINARY = %SCS_64BIT_BINARY
#ELSE
%SCS_THIS_PLATFORM_BINARY = %SCS_32BIT_BINARY
#ENDIF

DECLARE FUNCTION GetBinaryTypeA LIB "Kernel32.dll" ALIAS "GetBinaryTypeA" _
    (lpApplicationName AS ASCIIZ, lpBinaryType AS DWORD) AS LONG

DECLARE FUNCTION GetBinaryTypeW LIB "Kernel32.dll" ALIAS "GetBinaryTypeW" _
    (lpApplicationName AS WSTRINGZ, lpBinaryType AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetBinaryType LIB "Kernel32.dll" ALIAS "GetBinaryTypeW" _
    (lpApplicationName AS WSTRINGZ, lpBinaryType AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetBinaryType LIB "Kernel32.dll" ALIAS "GetBinaryTypeA" _
    (lpApplicationName AS ASCIIZ, lpBinaryType AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetShortPathNameA LIB "Kernel32.dll" _
    ALIAS "GetShortPathNameA" (lpszLongPath AS ASCIIZ, _
    lpszShortPath AS ASCIIZ, BYVAL cchBuffer AS DWORD) AS DWORD

DECLARE FUNCTION GetShortPathNameW LIB "Kernel32.dll" _
    ALIAS "GetShortPathNameW" (lpszLongPath AS WSTRINGZ, _
    lpszShortPath AS WSTRINGZ, BYVAL cchBuffer AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetShortPathName LIB "Kernel32.dll" _
    ALIAS "GetShortPathNameW" (lpszLongPath AS WSTRINGZ, _
    lpszShortPath AS WSTRINGZ, BYVAL cchBuffer AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetShortPathName LIB "Kernel32.dll" _
    ALIAS "GetShortPathNameA" (lpszLongPath AS ASCIIZ, _
    lpszShortPath AS ASCIIZ, BYVAL cchBuffer AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetLongPathNameA LIB "Kernel32.dll" ALIAS "GetLongPathNameA" _
    (lpszShortPath AS ASCIIZ, lpszLongPath AS ASCIIZ, _
    BYVAL cchBuffer AS DWORD) AS DWORD

DECLARE FUNCTION GetLongPathNameW LIB "Kernel32.dll" ALIAS "GetLongPathNameW" _
    (lpszShortPath AS WSTRINGZ, lpszLongPath AS WSTRINGZ, _
    BYVAL cchBuffer AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetLongPathName LIB "Kernel32.dll" ALIAS "GetLongPathNameW" _
    (lpszShortPath AS WSTRINGZ, lpszLongPath AS WSTRINGZ, _
    BYVAL cchBuffer AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetLongPathName LIB "Kernel32.dll" ALIAS "GetLongPathNameA" _
    (lpszShortPath AS ASCIIZ, lpszLongPath AS ASCIIZ, _
    BYVAL cchBuffer AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

#IF %WIN32_WINNT >= &H0600

DECLARE FUNCTION GetLongPathNameTransactedA LIB "Kernel32.dll" _
    ALIAS "GetLongPathNameTransactedA" (lpszShortPath AS ASCIIZ, _
    lpszLongPath AS ASCIIZ, BYVAL cchBuffer AS DWORD, _
    BYVAL hTransaction AS DWORD) AS DWORD

DECLARE FUNCTION GetLongPathNameTransactedW LIB "Kernel32.dll" _
    ALIAS "GetLongPathNameTransactedW" (lpszShortPath AS WSTRINGZ, _
    lpszLongPath AS WSTRINGZ, BYVAL cchBuffer AS DWORD, _
    BYVAL hTransaction AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetLongPathNameTransacted LIB "Kernel32.dll" _
    ALIAS "GetLongPathNameTransactedW" (lpszShortPath AS WSTRINGZ, _
    lpszLongPath AS WSTRINGZ, BYVAL cchBuffer AS DWORD, _
    BYVAL hTransaction AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetLongPathNameTransacted LIB "Kernel32.dll" _
    ALIAS "GetLongPathNameTransactedA" (lpszShortPath AS ASCIIZ, _
    lpszLongPath AS ASCIIZ, BYVAL cchBuffer AS DWORD, _
    BYVAL hTransaction AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

#ENDIF ' %WIN32_WINNT >= &H0600

DECLARE FUNCTION GetProcessAffinityMask LIB "Kernel32.dll" _
    ALIAS "GetProcessAffinityMask" (BYVAL hProcess AS DWORD, _
    lpProcessAffinityMask AS DWORD, lpSystemAffinityMask AS DWORD) AS LONG

DECLARE FUNCTION SetProcessAffinityMask LIB "Kernel32.dll" _
    ALIAS "SetProcessAffinityMask" (BYVAL hProcess AS DWORD, _
    BYVAL dwProcessAffinityMask AS DWORD) AS LONG

#IF %WIN32_WINNT >= &H0601

DECLARE FUNCTION GetProcessGroupAffinity LIB "Kernel32.dll" _
    ALIAS "GetProcessGroupAffinity" (BYVAL hProcess AS DWORD, _
    GroupCount AS WORD, BYVAL GroupArray AS WORD PTR) AS LONG

#ENDIF ' %WIN32_WINNT >= &H0601

#IF %WIN32_WINNT >= &H0501

DECLARE FUNCTION GetProcessHandleCount LIB "Kernel32.dll" _
    ALIAS "GetProcessHandleCount" (BYVAL hProcess AS DWORD, _
    pdwHandleCount AS DWORD) AS LONG

#ENDIF ' (%WIN32_WINNT >= &H0501)

DECLARE FUNCTION GetProcessTimes LIB "Kernel32.dll" ALIAS "GetProcessTimes" _
    (BYVAL hProcess AS DWORD, lpCreationTime AS FILETIME, _
    lpExitTime AS FILETIME, lpKernelTime AS FILETIME, lpUserTime AS FILETIME) _
    AS LONG

DECLARE FUNCTION GetProcessIoCounters LIB "Kernel32.dll" _
    ALIAS "GetProcessIoCounters" (BYVAL hProcess AS DWORD, _
    lpIoCounters AS IO_COUNTERS) AS LONG

DECLARE FUNCTION GetProcessWorkingSetSize LIB "Kernel32.dll" _
    ALIAS "GetProcessWorkingSetSize" (BYVAL hProcess AS DWORD, _
    lpMinimumWorkingSetSize AS DWORD, lpMaximumWorkingSetSize AS DWORD) AS LONG

DECLARE FUNCTION GetProcessWorkingSetSizeEx LIB "Kernel32.dll" _
    ALIAS "GetProcessWorkingSetSizeEx" (BYVAL hProcess AS DWORD, _
    lpMinimumWorkingSetSize AS DWORD, lpMaximumWorkingSetSize AS DWORD, _
    dFlags AS DWORD) AS LONG

DECLARE FUNCTION SetProcessWorkingSetSize LIB "Kernel32.dll" _
    ALIAS "SetProcessWorkingSetSize" (BYVAL hProcess AS DWORD, _
    BYVAL dwMinimumWorkingSetSize AS DWORD, _
    BYVAL dwMaximumWorkingSetSize AS DWORD) AS LONG

DECLARE FUNCTION SetProcessWorkingSetSizeEx LIB "Kernel32.dll" _
    ALIAS "SetProcessWorkingSetSizeEx" (BYVAL hProcess AS DWORD, _
    BYVAL dwMinimumWorkingSetSize AS DWORD, _
    BYVAL dwMaximumWorkingSetSize AS DWORD, BYVAL dFlags AS DWORD) AS LONG

#IF (%WIN32_WINNT >= &H0600)

%PROCESS_AFFINITY_ENABLE_AUTO_UPDATE = &H00000001

DECLARE FUNCTION SetProcessAffinityUpdateMode LIB "Kernel32.dll" _
    ALIAS "SetProcessAffinityUpdateMode" (BYVAL hProcess AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION QueryProcessAffinityUpdateMode LIB "Kernel32.dll" _
    ALIAS "QueryProcessAffinityUpdateMode" (BYVAL hProcess AS DWORD, _
    lpdwFlags AS DWORD) AS LONG

#ENDIF ' %WIN32_WINNT >= &H0600

DECLARE FUNCTION OpenProcess LIB "Kernel32.dll" ALIAS "OpenProcess" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    BYVAL dwProcessId AS DWORD) AS DWORD

DECLARE FUNCTION GetCurrentProcess LIB "Kernel32.dll" _
    ALIAS "GetCurrentProcess" () AS DWORD

DECLARE FUNCTION GetCurrentProcessId LIB "Kernel32.dll" _
    ALIAS "GetCurrentProcessId" () AS DWORD

DECLARE SUB ExitProcess LIB "Kernel32.dll" ALIAS "ExitProcess" _
    (BYVAL uExitCode AS DWORD)

DECLARE FUNCTION TerminateProcess LIB "Kernel32.dll" ALIAS "TerminateProcess" _
    (BYVAL hProcess AS DWORD, BYVAL uExitCode AS DWORD) AS LONG

DECLARE FUNCTION GetExitCodeProcess LIB "Kernel32.dll" _
    ALIAS "GetExitCodeProcess" (BYVAL hProcess AS DWORD, _
    lpExitCode AS DWORD) AS LONG

DECLARE SUB FatalExit LIB "Kernel32.dll" ALIAS "FatalExit" _
    (BYVAL nExitCode AS LONG)

DECLARE FUNCTION GetEnvironmentStringsA LIB "Kernel32.dll" _
    ALIAS "GetEnvironmentStringsA" () AS DWORD

DECLARE FUNCTION GetEnvironmentStringsW LIB "Kernel32.dll" _
    ALIAS "GetEnvironmentStringsW" () AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetEnvironmentStrings LIB "Kernel32.dll" _
    ALIAS "GetEnvironmentStringsW" () AS DWORD
#ELSE
DECLARE FUNCTION GetEnvironmentStrings LIB "Kernel32.dll" _
    ALIAS "GetEnvironmentStringsA" () AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION FreeEnvironmentStringsA LIB "Kernel32.dll" _
    ALIAS "FreeEnvironmentStringsA" (BYVAL lpsz AS DWORD) AS LONG

DECLARE FUNCTION FreeEnvironmentStringsW LIB "Kernel32.dll" _
    ALIAS "FreeEnvironmentStringsW" (BYVAL lpsz AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION FreeEnvironmentStrings LIB "Kernel32.dll" _
    ALIAS "FreeEnvironmentStringsW" (BYVAL lpsz AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION FreeEnvironmentStrings LIB "Kernel32.dll" _
    ALIAS "FreeEnvironmentStringsA" (BYVAL lpsz AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE SUB RaiseException LIB "Kernel32.dll" ALIAS "RaiseException" _
    (BYVAL dwExceptionCode AS DWORD, BYVAL dwExceptionFlags AS DWORD, _
    BYVAL nNumberOfArguments AS DWORD, BYVAL lpArguments AS DWORD)

DECLARE SUB RaiseFailFastException LIB "Kernel32.dll" _
    ALIAS "RaiseFailFastException" (pExceptionRecord AS EXCEPTION_RECORD, _
    pContextRecord AS CONTEXT, BYVAL dwFlags AS DWORD)

DECLARE FUNCTION UnhandledExceptionFilter LIB "Kernel32.dll" _
    ALIAS "UnhandledExceptionFilter" _
    (ExceptionInfo AS EXCEPTION_POINTERS) AS LONG

DECLARE FUNCTION SetUnhandledExceptionFilter LIB "Kernel32.dll" _
    ALIAS "SetUnhandledExceptionFilter" _
    (BYVAL lpTopLevelExceptionFilter AS DWORD) AS DWORD

#IF (%WIN32_WINNT >= &H0400)

'
' Fiber creation flags
'

%FIBER_FLAG_FLOAT_SWITCH = 1     ' context switch floating point

DECLARE FUNCTION CreateFiber LIB "Kernel32.dll" ALIAS "CreateFiber" _
    (BYVAL dwStackSize AS DWORD, BYVAL lpStartAddress AS DWORD, _
    BYVAL lpParameter AS DWORD) AS DWORD

DECLARE FUNCTION CreateFiberEx LIB "Kernel32.dll" ALIAS "CreateFiberEx" _
    (BYVAL dwStackCommitSize AS DWORD, BYVAL dwStackReserveSize AS DWORD, _
    BYVAL dwFlags AS DWORD, BYVAL lpStartAddress AS DWORD, _
    BYVAL lpParameter AS DWORD) AS DWORD

DECLARE SUB DeleteFiber LIB "Kernel32.dll" ALIAS "DeleteFiber" _
    (BYVAL lpFiber AS DWORD)

DECLARE FUNCTION ConvertThreadToFiber LIB "Kernel32.dll" _
    ALIAS "ConvertThreadToFiber" (BYVAL lpParameter AS DWORD) AS DWORD

DECLARE FUNCTION ConvertThreadToFiberEx LIB "Kernel32.dll" _
    ALIAS "ConvertThreadToFiberEx" (BYVAL lpParameter AS DWORD, _
    BYVAL dwFlags AS DWORD) AS DWORD

#IF (%WIN32_WINNT >= &H0501)

DECLARE FUNCTION ConvertFiberToThread LIB "Kernel32.dll" _
    ALIAS "ConvertFiberToThread" () AS LONG

#ENDIF

#IF (%WIN32_WINNT >= &H0600)

DECLARE FUNCTION IsThreadAFiber LIB "Kernel32.dll" ALIAS "IsThreadAFiber" () _
    AS LONG

#ENDIF

DECLARE SUB SwitchToFiber LIB "Kernel32.dll" ALIAS "SwitchToFiber" _
    (BYVAL lpFiber AS DWORD)

DECLARE FUNCTION SwitchToThread LIB "Kernel32.dll" ALIAS "SwitchToThread" () _
    AS LONG

'
' UMS begin
'

#IF (%WIN32_WINNT >= &H0601) AND (NOT %DEF(%MIDL_PASS))

%UMS_VERSION = %RTL_UMS_VERSION

'typedef void *PUMS_CONTEXT;
MACRO PUMS_CONTEXT=DWORD

'typedef void *PUMS_COMPLETION_LIST;
MACRO PUMS_COMPLETION_LIST=DWORD

'typedef enum _RTL_UMS_THREAD_INFO_CLASS UMS_THREAD_INFO_CLASS, *PUMS_THREAD_INFO_CLASS;
'
'typedef enum _RTL_UMS_SCHEDULER_REASON UMS_SCHEDULER_REASON;
'
'typedef PRTL_UMS_SCHEDULER_ENTRY_POINT PUMS_SCHEDULER_ENTRY_POINT;

TYPE UMS_SCHEDULER_STARTUP_INFO

    '
    ' UMS Version the application was built to. Should be set to UMS_VERSION
    '
    UmsVersion     AS DWORD

    '
    ' Completion List to associate the new User Scheduler to.
    '
    CompletionList AS PUMS_COMPLETION_LIST

    '
    ' A pointer to the application-defined function that represents the starting
    ' address of the Sheduler.
    '
    SchedulerProc  AS DWORD  ' PUMS_SCHEDULER_ENTRY_POINT  [not defined]

    '
    ' pointer to a variable to be passed to the scheduler uppon first activation.
    '
    SchedulerParam AS DWORD  ' PVOID

END TYPE

DECLARE FUNCTION CreateUmsCompletionList LIB "Kernel32.dll" _
    ALIAS "CreateUmsCompletionList" (UmsCompletionList AS ANY) AS LONG

DECLARE FUNCTION DequeueUmsCompletionListItems LIB "Kernel32.dll" _
    ALIAS "DequeueUmsCompletionListItems" (UmsCompletionList AS ANY, _
    BYVAL WaitTimeOut AS DWORD, UmsThreadList AS ANY) AS LONG

DECLARE FUNCTION GetUmsCompletionListEvent LIB "Kernel32.dll" _
    ALIAS "GetUmsCompletionListEvent" (UmsCompletionList AS ANY, _
    UmsCompletionEvent AS DWORD) AS LONG

DECLARE FUNCTION ExecuteUmsThread LIB "Kernel32.dll" _
    ALIAS "ExecuteUmsThread" (UmsThread AS ANY) AS LONG

DECLARE FUNCTION UmsThreadYield LIB "Kernel32.dll" ALIAS "UmsThreadYield" _
    (SchedulerParam AS ANY) AS LONG

DECLARE FUNCTION DeleteUmsCompletionList LIB "Kernel32.dll" _
    ALIAS "DeleteUmsCompletionList" (UmsCompletionList AS ANY) AS LONG

DECLARE FUNCTION GetCurrentUmsThread LIB "Kernel32.dll" _
    ALIAS "GetCurrentUmsThread" () AS DWORD

DECLARE FUNCTION GetNextUmsListItem LIB "Kernel32.dll" _
    ALIAS "GetNextUmsListItem" (UmsContext AS ANY) AS DWORD

DECLARE FUNCTION QueryUmsThreadInformation LIB "Kernel32.dll" _
    ALIAS "QueryUmsThreadInformation" (UmsThread AS ANY, _
    BYVAL UmsThreadInfoClass AS LONG, UmsThreadInformation AS ANY, _
    BYVAL UmsThreadInformationLength AS DWORD, ReturnLength AS DWORD) AS LONG

DECLARE FUNCTION SetUmsThreadInformation LIB "Kernel32.dll" _
    ALIAS "SetUmsThreadInformation" (UmsThread AS ANY, _
    BYVAL UmsThreadInfoClass AS LONG, UmsThreadInformation AS ANY, _
    BYVAL UmsThreadInformationLength AS DWORD) AS LONG

DECLARE FUNCTION DeleteUmsThreadContext LIB "Kernel32.dll" _
    ALIAS "DeleteUmsThreadContext" (UmsThread AS ANY) AS LONG

DECLARE FUNCTION CreateUmsThreadContext LIB "Kernel32.dll" _
    ALIAS "CreateUmsThreadContext" (lpUmsThread AS ANY) AS LONG

DECLARE FUNCTION EnterUmsSchedulingMode LIB "Kernel32.dll" _
    ALIAS "EnterUmsSchedulingMode" _
    (SchedulerStartupInfo AS UMS_SCHEDULER_STARTUP_INFO) AS LONG

#ENDIF  ' (%WIN32_WINNT >= &H0601) AND NOT %DEF(%MIDL_PASS)

'
' UMS end
'

#ENDIF ' %WIN32_WINNT >= &H0400

DECLARE FUNCTION CreateThread LIB "Kernel32.dll" ALIAS "CreateThread" _
    (lpThreadAttributes AS SECURITY_ATTRIBUTES, BYVAL dwStackSize AS DWORD, _
    BYVAL StartAddress AS DWORD, BYVAL lpParameter AS DWORD, _
    BYVAL dwCreationFlags AS DWORD, lpThreadId AS DWORD) AS DWORD

DECLARE FUNCTION CreateRemoteThread LIB "Kernel32.dll" _
    ALIAS "CreateRemoteThread" (BYVAL hProcess AS DWORD, _
    lpThreadAttributes AS SECURITY_ATTRIBUTES, BYVAL dwStackSize AS DWORD, _
    BYVAL lpStartAddress AS DWORD, BYVAL lpParameter AS DWORD, _
    BYVAL dwCreationFlags AS DWORD, lpThreadId AS DWORD) AS DWORD

DECLARE FUNCTION CreateRemoteThreadEx LIB "Kernel32.dll" _
    ALIAS "CreateRemoteThreadEx" (BYVAL hProcess AS DWORD, _
    lpThreadAttributes AS SECURITY_ATTRIBUTES, BYVAL dwStackSize AS DWORD, _
    BYVAL lpStartAddress AS DWORD, BYVAL lpParameter AS DWORD, _
    BYVAL dwCreationFlags AS DWORD, BYVAL lpAttributeList AS DWORD, _
    lpThreadId AS DWORD) AS DWORD

DECLARE FUNCTION GetCurrentThread LIB "Kernel32.dll" ALIAS "GetCurrentThread" _
    () AS DWORD

DECLARE FUNCTION GetCurrentThreadId LIB "Kernel32.dll" _
    ALIAS "GetCurrentThreadId" () AS DWORD

DECLARE FUNCTION SetThreadStackGuarantee LIB "Kernel32.dll" _
    ALIAS "SetThreadStackGuarantee" (StackSizeInBytes AS DWORD) AS LONG

DECLARE FUNCTION GetProcessIdOfThread LIB "Kernel32.dll" _
    ALIAS "GetProcessIdOfThread" (BYVAL hThread AS DWORD) AS DWORD

#IF (%WIN32_WINNT >= &H0502)

DECLARE FUNCTION GetThreadId LIB "Kernel32.dll" ALIAS "GetThreadId" _
    (BYVAL hThread AS DWORD) AS DWORD

#ENDIF ' %WIN32_WINNT >= &H0502

DECLARE FUNCTION GetProcessId LIB "Kernel32.dll" ALIAS "GetProcessId" _
    (BYVAL hProcess AS DWORD) AS DWORD

DECLARE FUNCTION GetCurrentProcessorNumber LIB "Kernel32.dll" _
    ALIAS "GetCurrentProcessorNumber" () AS DWORD

#IF (%WIN32_WINNT >= &H0601)
DECLARE SUB GetCurrentProcessorNumberEx LIB "Kernel32.dll" _
    ALIAS "GetCurrentProcessorNumberEx" (ProcNumber AS PROCESSOR_NUMBER)
#ENDIF  ' #IF (%WIN32_WINNT >= &H0601)

#IF (%WIN32_WINNT >= &H0601)
DECLARE FUNCTION GetThreadGroupAffinity LIB "Kernel32.dll" _
    ALIAS "GetThreadGroupAffinity" (BYVAL hThread AS DWORD, _
    GroupAffinity AS GROUP_AFFINITY) AS LONG
#ENDIF  ' #IF (%WIN32_WINNT >= &H0601)

DECLARE FUNCTION SetThreadAffinityMask LIB "Kernel32.dll" _
    ALIAS "SetThreadAffinityMask" (BYVAL hThread AS DWORD, _
    BYVAL dwThreadAffinityMask AS DWORD) AS DWORD

#IF (%WIN32_WINNT >= &H0601)

DECLARE FUNCTION SetThreadGroupAffinity LIB "Kernel32.dll" _
    ALIAS "SetThreadGroupAffinity" (BYVAL hThread AS DWORD, _
    GroupAffinity AS GROUP_AFFINITY, _
    PreviousGroupAffinity AS GROUP_AFFINITY) AS LONG

DECLARE FUNCTION SetThreadIdealProcessorEx LIB "Kernel32.dll" _
    ALIAS "SetThreadIdealProcessorEx" (BYVAL hThread AS DWORD, _
    lpIdealProcessor AS PROCESSOR_NUMBER, _
    lpPreviousIdealProcessor AS PROCESSOR_NUMBER) AS LONG

DECLARE FUNCTION GetThreadIdealProcessorEx LIB "Kernel32.dll" _
    ALIAS "GetThreadIdealProcessorEx" (BYVAL hThread AS DWORD, _
    lpIdealProcessor AS PROCESSOR_NUMBER) AS LONG

#ENDIF  ' %WIN32_WINNT >= &H0601

#IF (%WIN32_WINNT >= &H0400)

DECLARE FUNCTION SetThreadIdealProcessor LIB "Kernel32.dll" _
   ALIAS "SetThreadIdealProcessor" (BYVAL hThread AS DWORD, _
   BYVAL dwIdealProcessor AS DWORD) AS DWORD

#ENDIF ' %WIN32_WINNT >= &H0400

#IF (%WIN32_WINNT >= &H0600)

%PROCESS_DEP_ENABLE                         = &H00000001
%PROCESS_DEP_DISABLE_ATL_THUNK_EMULATION    = &H00000002

DECLARE FUNCTION SetProcessDEPPolicy LIB "Kernel32.dll" _
    ALIAS "SetProcessDEPPolicy" (BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION GetProcessDEPPolicy LIB "Kernel32.dll" _
    ALIAS "GetProcessDEPPolicy" (BYVAL hProcess AS DWORD, lpFlags AS DWORD, _
    lpPermanent AS LONG) AS LONG

#ENDIF ' %WIN32_WINNT >= &H0600

DECLARE FUNCTION SetProcessPriorityBoost LIB "Kernel32.dll" _
    ALIAS "SetProcessPriorityBoost" (BYVAL hProcess AS DWORD, _
    BYVAL bDisablePriorityBoost AS LONG) AS LONG

DECLARE FUNCTION GetProcessPriorityBoost LIB "Kernel32.dll" _
    ALIAS "GetProcessPriorityBoost" (BYVAL hProcess AS DWORD, _
    pDisablePriorityBoost AS LONG) AS LONG

DECLARE FUNCTION RequestWakeupLatency LIB "Kernel32.dll" _
    ALIAS "RequestWakeupLatency" (BYVAL latency AS LONG) AS LONG

DECLARE FUNCTION IsSystemResumeAutomatic LIB "Kernel32.dll" _
    ALIAS "IsSystemResumeAutomatic" () AS LONG

DECLARE FUNCTION OpenThread LIB "Kernel32.dll" ALIAS "OpenThread" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    BYVAL dwThreadId AS DWORD) AS DWORD

DECLARE FUNCTION SetThreadPriority LIB "Kernel32.dll" _
    ALIAS "SetThreadPriority" (BYVAL hThread AS DWORD, _
    BYVAL nPriority AS LONG) AS LONG

DECLARE FUNCTION SetThreadPriorityBoost LIB "Kernel32.dll" _
    ALIAS "SetThreadPriorityBoost" (BYVAL hThread AS DWORD, _
    BYVAL bDisablePriorityBoost AS LONG) AS LONG

DECLARE FUNCTION GetThreadPriorityBoost LIB "Kernel32.dll" _
    ALIAS "GetThreadPriorityBoost" (BYVAL hThread AS DWORD, _
    pDisablePriorityBoost AS LONG) AS LONG

DECLARE FUNCTION GetThreadPriority LIB "Kernel32.dll" _
    ALIAS "GetThreadPriority" (BYVAL hThread AS DWORD) AS LONG

DECLARE FUNCTION GetThreadTimes LIB "Kernel32.dll" ALIAS "GetThreadTimes" _
    (BYVAL hThread AS DWORD, lpCreationTime AS FILETIME, _
    lpExitTime AS FILETIME, lpKernelTime AS FILETIME, lpUserTime AS FILETIME) _
    AS LONG

#IF %WIN32_WINNT >= &H0501

DECLARE FUNCTION GetThreadIOPendingFlag LIB "Kernel32.dll" _
    ALIAS "GetThreadIOPendingFlag" (BYVAL hThread AS DWORD, _
    lpIOIsPending AS LONG) AS LONG

#ENDIF ' (%WIN32_WINNT >= &H0501)

DECLARE SUB ExitThread LIB "Kernel32.dll" ALIAS "ExitThread" _
    (BYVAL dwExitCode AS DWORD)

DECLARE FUNCTION TerminateThread LIB "Kernel32.dll" ALIAS "TerminateThread" _
    (BYVAL hThread AS DWORD, BYVAL dwExitCode AS DWORD) AS LONG

DECLARE FUNCTION GetExitCodeThread LIB "Kernel32.dll" _
    ALIAS "GetExitCodeThread" (BYVAL hThread AS DWORD, lpExitCode AS DWORD) _
    AS LONG

DECLARE FUNCTION GetThreadSelectorEntry LIB "Kernel32.dll" _
    ALIAS "GetThreadSelectorEntry" (BYVAL hThread AS DWORD, _
    BYVAL dwSelector AS DWORD, lpSelectorEntry AS LDT_ENTRY) AS LONG

DECLARE FUNCTION SetThreadExecutionState LIB "Kernel32.dll" _
    ALIAS "SetThreadExecutionState" (BYVAL esFlags AS DWORD) AS DWORD

#IF (%WIN32_WINNT >= %WIN32_WINNT_WIN7)

TYPE REASON_CONTEXT_type
    LocalizedReasonModule AS DWORD  ' HMODULE
    LocalizedReasonId     AS DWORD
    ReasonStringCount     AS DWORD
    ReasonStrings         AS DWORD  ' WSTRINGZ PTR PTR
END TYPE

UNION REASON_CONTEXT_union
    Detailed           AS REASON_CONTEXT_type
    SimpleReasonString AS WSTRINGZ PTR
END UNION

TYPE REASON_CONTEXT
    Version AS DWORD
    Flags   AS DWORD
    Reason  AS REASON_CONTEXT_union
END TYPE

'
' Power Request APIs
'

TYPE POWER_REQUEST_CONTEXT
    REASON_CONTEXT
END TYPE

DECLARE FUNCTION PowerCreateRequest LIB "Kernel32.dll" _
    ALIAS "PowerCreateRequest" (Context AS REASON_CONTEXT) AS DWORD

DECLARE FUNCTION PowerSetRequest LIB "Kernel32.dll" _
    ALIAS "PowerSetRequest" (BYVAL PowerRequest AS DWORD, _
    BYVAL RequestType AS POWER_REQUEST_TYPE_enum) AS LONG

DECLARE FUNCTION PowerClearRequest LIB "Kernel32.dll" _
    ALIAS "PowerClearRequest" (BYVAL PowerRequest AS DWORD, _
    BYVAL RequestType AS POWER_REQUEST_TYPE_enum) AS LONG

#ENDIF ' (%WIN32_WINNT >= %WIN32_WINNT_WIN7)

DECLARE FUNCTION GetLastError LIB "Kernel32.dll" ALIAS "GetLastError" () AS LONG

DECLARE SUB SetLastError LIB "Kernel32.dll" ALIAS "SetLastError" _
    (BYVAL dwErrCode AS DWORD)

#IF NOT %DEF(%RC_INVOKED)
#IF %DEF(%WINBASE_DECLARE_RESTORE_LAST_ERROR)

DECLARE SUB RestoreLastError LIB "Kernel32.dll" ALIAS "RestoreLastError" _
    (BYVAL dwErrCode AS DWORD)

' [callback is not documented]
'typedef VOID (WINAPI* PRESTORE_LAST_ERROR)(DWORD);

$RESTORE_LAST_ERROR_NAME_A  = "RestoreLastError"
$$RESTORE_LAST_ERROR_NAME_W = "RestoreLastError"$$

#ENDIF  ' #IF %DEF(%WINBASE_DECLARE_RESTORE_LAST_ERROR)
#ENDIF  ' #IF NOT %DEF(%RC_INVOKED)

DECLARE FUNCTION GetOverlappedResult LIB "Kernel32.dll" _
    ALIAS "GetOverlappedResult" (BYVAL hFile AS DWORD, _
    lpOverlapped AS OVERLAPPED, lpNumberOfBytesTransferred AS DWORD, _
    BYVAL bWait AS LONG) AS LONG

DECLARE FUNCTION CreateIoCompletionPort LIB "Kernel32.dll" _
    ALIAS "CreateIoCompletionPort" (BYVAL FileHandle AS DWORD, _
    BYVAL ExistingCompletionPort AS DWORD, BYVAL CompletionKey AS DWORD, _
    BYVAL NumberOfConcurrentThreads AS DWORD) AS DWORD

DECLARE FUNCTION GetQueuedCompletionStatus LIB "Kernel32.dll" _
    ALIAS "GetQueuedCompletionStatus" (BYVAL CompletionPort AS DWORD, _
    lpNumberOfBytesTransferred AS DWORD, lpCompletionKey AS DWORD, _
    lpOverlapped AS OVERLAPPED, BYVAL dwMilliseconds AS DWORD) AS LONG

#IF (%WIN32_WINNT >= &H0600)

DECLARE FUNCTION GetQueuedCompletionStatusEx LIB "Kernel32.dll" _
    ALIAS "GetQueuedCompletionStatusEx" (BYVAL CompletionPort AS DWORD, _
    lpCompletionPortEntries AS DWORD, BYVAL ulCount AS DWORD, _
    ulNumEntriesRemoved AS DWORD, BYVAL dwMilliseconds AS DWORD, _
    BYVAL fAlertable AS LONG) AS LONG

#ENDIF ' %WIN32_WINNT >= &H0600

DECLARE FUNCTION PostQueuedCompletionStatus LIB "Kernel32.dll" _
    ALIAS "PostQueuedCompletionStatus" (BYVAL CompletionPort AS DWORD, _
    BYVAL dwNumberOfBytesTransferred AS DWORD, BYVAL dwCompletionKey AS DWORD, _
    lpOverlapped AS DWORD) AS LONG

#IF (%WIN32_WINNT >= &H0600)

'
' The following flags allows an application to change
' the semantics of IO completion notification.
'

'
' Don't queue an entry to an associated completion port if returning success
' synchronously.
'
%FILE_SKIP_COMPLETION_PORT_ON_SUCCESS   = &H1

'
' Don't set the file handle event on IO completion.
'
%FILE_SKIP_SET_EVENT_ON_HANDLE          = &H2

DECLARE FUNCTION SetFileCompletionNotificationModes LIB "Kernel32.dll" _
    ALIAS "SetFileCompletionNotificationModes" (BYVAL hFile AS DWORD, _
    BYVAL bFlags AS BYTE) AS LONG

DECLARE FUNCTION SetFileIoOverlappedRange LIB "Kernel32.dll" _
    ALIAS "SetFileIoOverlappedRange" (BYVAL hFile AS DWORD, _
    BYVAL OverlappedRangeStart AS DWORD, BYVAL dLength AS DWORD) AS LONG

#ENDIF ' %WIN32_WINNT >= &H0600

%SEM_FAILCRITICALERRORS     = &H0001
%SEM_NOGPFAULTERRORBOX      = &H0002
%SEM_NOALIGNMENTFAULTEXCEPT = &H0004
%SEM_NOOPENFILEERRORBOX     = &H8000??

DECLARE FUNCTION GetErrorMode LIB "Kernel32.dll" ALIAS "GetErrorMode" () _
    AS DWORD

DECLARE FUNCTION SetErrorMode LIB "Kernel32.dll" ALIAS "SetErrorMode" _
    (BYVAL uMode AS DWORD) AS DWORD

'
' Thread error mode support
'

DECLARE FUNCTION GetThreadErrorMode LIB "Kernel32.dll" _
    ALIAS "GetThreadErrorMode" () AS DWORD

DECLARE FUNCTION SetThreadErrorMode LIB "Kernel32.dll" _
    ALIAS "SetThreadErrorMode" (BYVAL dwNewMode AS DWORD, _
    lpOldMode AS DWORD) AS LONG

DECLARE FUNCTION ReadProcessMemory LIB "Kernel32.dll" _
    ALIAS "ReadProcessMemory" (BYVAL hProcess AS DWORD, _
    BYVAL lpBaseAddress AS DWORD, lpBuffer AS ANY, _
    BYVAL nSize AS DWORD, lpNumberOfBytesWritten AS DWORD) AS LONG

DECLARE FUNCTION WriteProcessMemory LIB "Kernel32.dll" _
    ALIAS "WriteProcessMemory" (BYVAL hProcess AS DWORD, _
    BYVAL lpBaseAddress AS DWORD, lpBuffer AS ANY, _
    BYVAL nSize AS DWORD, lpNumberOfBytesWritten AS DWORD) AS LONG

#IF NOT %DEF(%MIDL_PASS)
DECLARE FUNCTION GetThreadContext LIB "Kernel32.dll" ALIAS "GetThreadContext" _
    (BYVAL hThread AS DWORD, lpContext AS CONTEXT) AS LONG

DECLARE FUNCTION SetThreadContext LIB "Kernel32.dll" ALIAS "SetThreadContext" _
    (BYVAL hThread AS DWORD, lpContext AS CONTEXT) AS LONG

'DECLARE FUNCTION Wow64GetThreadContext LIB "Kernel32.dll" _
'    ALIAS "Wow64GetThreadContext" (BYVAL hThread AS DWORD, _
'    lpContext AS WOW64_CONTEXT) AS LONG

#IF (%WIN32_WINNT >= &H0601)

'DECLARE FUNCTION Wow64GetThreadSelectorEntry LIB "Kernel32.dll" _
'    ALIAS "Wow64GetThreadSelectorEntry" (BYVAL hThread AS DWORD, _
'    BYVAL dwSelector AS DWORD, lpSelectorEntry AS WOW64_LDT_ENTRY) AS LONG

#ENDIF  ' #IF (%WIN32_WINNT >= &H0601)

'DECLARE FUNCTION Wow64SetThreadContext LIB "Kernel32.dll" _
'    ALIAS "Wow64SetThreadContext" (BYVAL hThread AS DWORD, _
'    lpContext AS WOW64_CONTEXT) AS LONG

#ENDIF ' #IF NOT %DEF(%MIDL_PASS)

DECLARE FUNCTION SuspendThread LIB "Kernel32.dll" ALIAS "SuspendThread" _
    (BYVAL hThread AS DWORD) AS DWORD

DECLARE FUNCTION Wow64SuspendThread LIB "Kernel32.dll" _
    ALIAS "Wow64SuspendThread" (BYVAL hThread AS DWORD) AS DWORD

DECLARE FUNCTION ResumeThread LIB "Kernel32.dll" ALIAS "ResumeThread" _
    (BYVAL hThread AS DWORD) AS DWORD

#IF (%WIN32_WINNT >= &H0400) OR (%WIN32_WINDOWS > &H0400)

DECLARE SUB PAPCFUNC (BYVAL dwParam AS DWORD)

DECLARE FUNCTION QueueUserAPC LIB "Kernel32.dll" ALIAS "QueueUserAPC" _
    (BYVAL pfnAPC AS DWORD, BYVAL hThread AS DWORD, BYVAL dwData AS DWORD) _
    AS DWORD

#ENDIF ' %WIN32_WINNT >= &H0400 OR _WIN32_WINDOWS > &H0400

#IF (%WIN32_WINNT >= &H0400) OR (%WIN32_WINDOWS > &H0400)

DECLARE FUNCTION IsDebuggerPresent LIB "Kernel32.dll" _
    ALIAS "IsDebuggerPresent" () AS LONG

#ENDIF

#IF %WIN32_WINNT >= &H0501

DECLARE FUNCTION CheckRemoteDebuggerPresent LIB "Kernel32.dll" _
    ALIAS "CheckRemoteDebuggerPresent" (BYVAL hProcess AS DWORD, _
    pbDebuggerPresent AS LONG) AS LONG

#ENDIF ' (%WIN32_WINNT >= &H0501)

DECLARE SUB DebugBreak LIB "Kernel32.dll" ALIAS "DebugBreak" ()

DECLARE FUNCTION WaitForDebugEvent LIB "Kernel32.dll" _
    ALIAS "WaitForDebugEvent" (lpde AS DEBUG_EVENT, BYVAL dwTimeout AS DWORD) _
    AS LONG

DECLARE FUNCTION ContinueDebugEvent LIB "Kernel32.dll" _
    ALIAS "ContinueDebugEvent" (BYVAL dwProcessId AS DWORD, _
    BYVAL dwThreadId AS DWORD, BYVAL dwContinueStatus AS DWORD) AS LONG

DECLARE FUNCTION DebugActiveProcess LIB "Kernel32.dll" _
    ALIAS "DebugActiveProcess" (BYVAL dwProcessId AS DWORD) AS LONG

DECLARE FUNCTION DebugActiveProcessStop LIB "Kernel32.dll" _
    ALIAS "DebugActiveProcessStop" (BYVAL dwProcessId AS DWORD) AS LONG

DECLARE FUNCTION DebugSetProcessKillOnExit LIB "Kernel32.dll" _
    ALIAS "DebugSetProcessKillOnExit" (BYVAL bKillOnExit AS LONG) AS LONG

DECLARE FUNCTION DebugBreakProcess LIB "Kernel32.dll" _
    ALIAS "DebugBreakProcess" (BYVAL dwProcess AS DWORD) AS LONG

DECLARE SUB InitializeCriticalSection LIB "Kernel32.dll" _
    ALIAS "InitializeCriticalSection" (lpCriticalSection AS CRITICAL_SECTION)

DECLARE SUB EnterCriticalSection LIB "Kernel32.dll" _
    ALIAS "EnterCriticalSection" (lpCriticalSection AS CRITICAL_SECTION)

DECLARE SUB LeaveCriticalSection LIB "Kernel32.dll" _
    ALIAS "LeaveCriticalSection" (lpCriticalSection AS CRITICAL_SECTION)

#IF (%WIN32_WINNT >= &H0403)

%CRITICAL_SECTION_NO_DEBUG_INFO = %RTL_CRITICAL_SECTION_FLAG_NO_DEBUG_INFO

DECLARE FUNCTION InitializeCriticalSectionAndSpinCount LIB "Kernel32.dll" _
    ALIAS "InitializeCriticalSectionAndSpinCount" _
    (lpCriticalSection AS CRITICAL_SECTION, BYVAL dwSpinCount AS DWORD) AS LONG

DECLARE FUNCTION InitializeCriticalSectionEx LIB "Kernel32.dll" _
    ALIAS "InitializeCriticalSectionEx" _
    (lpCriticalSection AS CRITICAL_SECTION, BYVAL dwSpinCount AS DWORD, _
    BYVAL dFlags AS DWORD) AS LONG

DECLARE FUNCTION SetCriticalSectionSpinCount LIB "Kernel32.dll" _
    ALIAS "SetCriticalSectionSpinCount" _
    (lpCriticalSection AS CRITICAL_SECTION, BYVAL dwSpinCount AS DWORD) _
    AS DWORD

#ENDIF

#IF (%WIN32_WINNT >= &H0400)

DECLARE FUNCTION TryEnterCriticalSection LIB "Kernel32.dll" _
    ALIAS "TryEnterCriticalSection" (lpCriticalSection AS CRITICAL_SECTION) _
    AS LONG

#ENDIF ' %WIN32_WINNT >= &H0400

DECLARE SUB DeleteCriticalSection LIB "Kernel32.dll" _
    ALIAS "DeleteCriticalSection" (lpCriticalSection AS CRITICAL_SECTION)

DECLARE FUNCTION SetEvent LIB "Kernel32.dll" ALIAS "SetEvent" _
    (BYVAL hEvent AS DWORD) AS LONG

DECLARE FUNCTION ResetEvent LIB "Kernel32.dll" ALIAS "ResetEvent" _
    (BYVAL hEvent AS DWORD) AS LONG

DECLARE FUNCTION PulseEvent LIB "Kernel32.dll" ALIAS "PulseEvent" _
    (BYVAL hEvent AS DWORD) AS LONG

DECLARE FUNCTION ReleaseSemaphore LIB "Kernel32.dll" ALIAS "ReleaseSemaphore" _
    (BYVAL hSemaphore AS DWORD, BYVAL lReleaseCount AS LONG, _
    lpPreviousCount AS LONG) AS LONG

DECLARE FUNCTION ReleaseMutex LIB "Kernel32.dll" ALIAS "ReleaseMutex" _
    (BYVAL hMutex AS DWORD) AS LONG

DECLARE FUNCTION WaitForSingleObject LIB "Kernel32.dll" _
    ALIAS "WaitForSingleObject" (BYVAL hHandle AS DWORD, _
    BYVAL dwMilliseconds AS DWORD) AS DWORD

DECLARE FUNCTION WaitForMultipleObjects LIB "Kernel32.dll" _
    ALIAS "WaitForMultipleObjects" (BYVAL nCount AS DWORD, _
    lpHandles AS DWORD, BYVAL bWaitAll AS LONG, _
    BYVAL dwMilliseconds AS DWORD) AS DWORD

DECLARE SUB apiSleep LIB "Kernel32.dll" ALIAS "Sleep" _
    (BYVAL dwMilliseconds AS DWORD)

DECLARE FUNCTION LoadResource LIB "Kernel32.dll" ALIAS "LoadResource" _
    (BYVAL hInstance AS DWORD, BYVAL hResInfo AS DWORD) AS DWORD

DECLARE FUNCTION SizeofResource LIB "Kernel32.dll" ALIAS "SizeofResource" _
    (BYVAL hInstance AS DWORD, BYVAL hResInfo AS DWORD) AS DWORD

DECLARE FUNCTION GlobalDeleteAtom LIB "Kernel32.dll" _
    ALIAS "GlobalDeleteAtom" (BYVAL nAtom AS WORD) AS WORD

DECLARE FUNCTION InitAtomTable LIB "Kernel32.dll" ALIAS "InitAtomTable" _
    (BYVAL nSize AS DWORD) AS LONG

DECLARE FUNCTION DeleteAtom LIB "Kernel32.dll" ALIAS "DeleteAtom" _
    (BYVAL nAtom AS WORD) AS WORD

DECLARE FUNCTION SetHandleCount LIB "Kernel32.dll" ALIAS "SetHandleCount" _
    (BYVAL uNumber AS DWORD) AS DWORD

DECLARE FUNCTION GetLogicalDrives LIB "Kernel32.dll" _
    ALIAS "GetLogicalDrives" () AS DWORD

DECLARE FUNCTION LockFile LIB "Kernel32.dll" ALIAS "LockFile" _
    (BYVAL hFile AS DWORD, BYVAL dwFileOffsetLow AS DWORD, _
    BYVAL dwFileOffsetHigh AS DWORD, BYVAL nNumberOfBytesToLockLow AS LONG, _
    BYVAL nNumberOfBytesToLockHigh AS DWORD) AS LONG

DECLARE FUNCTION UnlockFile LIB "Kernel32.dll" ALIAS "UnlockFile" _
    (BYVAL hFile AS DWORD, BYVAL dwFileOffsetLow AS DWORD, _
    BYVAL dwFileOffsetHigh AS DWORD, _
    BYVAL nNumberOfBytesToUnlockLow AS DWORD, _
    BYVAL nNumberOfBytesToUnlockHigh AS DWORD) AS LONG

DECLARE FUNCTION LockFileEx LIB "Kernel32.dll" ALIAS "LockFileEx" _
    (BYVAL hFile AS DWORD, BYVAL dwFlags AS DWORD, BYVAL dwReserved AS DWORD, _
    BYVAL nNumberOfBytesToLockLow AS DWORD, _
    BYVAL nNumberOfBytesToLockHigh AS DWORD, _
    lpOverlapped AS OVERLAPPED) AS LONG

%LOCKFILE_FAIL_IMMEDIATELY  = &H00000001
%LOCKFILE_EXCLUSIVE_LOCK    = &H00000002

DECLARE FUNCTION UnlockFileEx LIB "Kernel32.dll" ALIAS "UnlockFileEx" _
    (BYVAL hFile AS DWORD, BYVAL dwReserved AS DWORD, _
    BYVAL nNumberOfBytesToUnlockLow AS DWORD, _
    BYVAL nNumberOfBytesToUnlockHigh AS DWORD, lpOverlapped AS OVERLAPPED) _
    AS LONG

TYPE BY_HANDLE_FILE_INFORMATION
    dwFileAttributes     AS DWORD
    ftCreationTime       AS FILETIME
    ftLastAccessTime     AS FILETIME
    ftLastWriteTime      AS FILETIME
    dwVolumeSerialNumber AS DWORD
    nFileSizeHigh        AS DWORD
    nFileSizeLow         AS DWORD
    nNumberOfLinks       AS DWORD
    nFileIndexHigh       AS DWORD
    nFileIndexLow        AS DWORD
END TYPE

DECLARE FUNCTION GetFileInformationByHandle LIB "Kernel32.dll" _
    ALIAS "GetFileInformationByHandle" (BYVAL hFile AS DWORD, _
    lpFileInformation AS BY_HANDLE_FILE_INFORMATION) AS LONG

DECLARE FUNCTION GetFileType LIB "Kernel32.dll" ALIAS "GetFileType" _
    (BYVAL hFile AS DWORD) AS DWORD

DECLARE FUNCTION GetFileSize LIB "Kernel32.dll" ALIAS "GetFileSize" _
    (BYVAL hFile AS DWORD, lpFileSizeHigh AS DWORD) AS DWORD

DECLARE FUNCTION GetFileSizeEx LIB "Kernel32.dll" ALIAS "GetFileSizeEx" _
    (BYVAL hFile AS DWORD, lpFileSize AS QUAD) AS LONG

DECLARE FUNCTION GetStdHandle LIB "Kernel32.dll" ALIAS "GetStdHandle" _
    (BYVAL nStdHandle AS DWORD) AS DWORD

DECLARE FUNCTION SetStdHandle LIB "Kernel32.dll" ALIAS "SetStdHandle" _
    (BYVAL nStdHandle AS DWORD, BYVAL nHandle AS DWORD) AS LONG

#IF (%WIN32_WINNT >= &H0600)

DECLARE FUNCTION SetStdHandleEx LIB "Kernel32.dll" ALIAS "SetStdHandleEx" _
    (BYVAL nStdHandle AS DWORD, BYVAL nHandle AS DWORD, _
    phPrevValue AS DWORD) AS LONG

#ENDIF ' %WIN32_WINNT >= &H0600

DECLARE FUNCTION WriteFile LIB "Kernel32.dll" ALIAS "WriteFile" _
    (BYVAL hFile AS DWORD, BYVAL lpBuffer AS DWORD, _
    BYVAL nNumberOfBytesToWrite AS DWORD, lpNumberOfBytesWritten AS DWORD, _
    lpOverlapped AS OVERLAPPED) AS LONG

DECLARE FUNCTION ReadFile LIB "Kernel32.dll" ALIAS "ReadFile" _
    (BYVAL hFile AS DWORD, BYVAL lpBuffer AS DWORD, _
    BYVAL nNumberOfBytesToRead AS DWORD, lpNumberOfBytesRead AS DWORD, _
    lpOverlapped AS OVERLAPPED) AS LONG

DECLARE FUNCTION FlushFileBuffers LIB "Kernel32.dll" _
    ALIAS "FlushFileBuffers" (BYVAL hFile AS DWORD) AS LONG

DECLARE FUNCTION DeviceIoControl LIB "Kernel32.dll" ALIAS "DeviceIoControl" _
    (BYVAL hDevice AS DWORD, BYVAL dwIoControlCode AS DWORD, _
    BYVAL lpInBuffer AS DWORD, BYVAL nInBufferSize AS DWORD, _
    BYVAL lpOutBuffer AS DWORD, BYVAL nOutBufferSize AS DWORD, _
    lpBytesReturned AS LONG, lpOverlapped AS OVERLAPPED) AS LONG

DECLARE FUNCTION RequestDeviceWakeup LIB "Kernel32.dll" _
    ALIAS "RequestDeviceWakeup" (BYVAL hDevice AS DWORD) AS LONG

DECLARE FUNCTION CancelDeviceWakeupRequest LIB "Kernel32.dll" _
    ALIAS "CancelDeviceWakeupRequest" (BYVAL hDevice AS DWORD) AS LONG

DECLARE FUNCTION GetDevicePowerState LIB "Kernel32.dll" _
    ALIAS "GetDevicePowerState" (BYVAL hDevice AS DWORD, pfOn AS LONG) AS LONG

DECLARE FUNCTION SetMessageWaitingIndicator LIB "Kernel32.dll" _
    ALIAS "SetMessageWaitingIndicator" (BYVAL hMsgIndicator AS DWORD, _
    BYVAL ulMsgCount AS DWORD) AS LONG

DECLARE FUNCTION SetEndOfFile LIB "Kernel32.dll" ALIAS "SetEndOfFile" _
    (BYVAL hFile AS DWORD) AS LONG

DECLARE FUNCTION SetFilePointer LIB "Kernel32.dll" ALIAS "SetFilePointer" _
    (BYVAL hFile AS DWORD, BYVAL lDistanceToMove AS LONG, _
    lpDistanceToMoveHigh AS LONG, BYVAL dwMoveMethod AS DWORD) AS DWORD

DECLARE FUNCTION SetFilePointerEx LIB "Kernel32.dll" _
    ALIAS "SetFilePointerEx" (BYVAL hFile AS DWORD, _
    BYVAL liDistanceToMove AS QUAD, lpNewFilePointer AS QUAD, _
    BYVAL dwMoveMethod AS DWORD) AS LONG

DECLARE FUNCTION FindClose LIB "Kernel32.dll" ALIAS "FindClose" _
    (BYVAL hFindFile AS DWORD) AS LONG

DECLARE FUNCTION GetFileTime LIB "Kernel32.dll" ALIAS "GetFileTime" _
    (BYVAL hFile AS DWORD, lpCreationTime AS FILETIME, _
    lpLastAccessTime AS FILETIME, lpLastWriteTime AS FILETIME) AS LONG

DECLARE FUNCTION SetFileTime LIB "Kernel32.dll" ALIAS "SetFileTime" _
    (BYVAL hFile AS DWORD, lpCreationTime AS FILETIME, _
    lpLastAccessTime AS FILETIME, lpLastWriteTime AS FILETIME) AS LONG

#IF %WIN32_WINNT >= &H0501

DECLARE FUNCTION SetFileValidData LIB "Kernel32.dll" _
    ALIAS "SetFileValidData" (BYVAL hFile AS DWORD, _
    BYVAL ValidDataLength AS QUAD) AS LONG

#ENDIF ' (%WIN32_WINNT >= &H0501)

DECLARE FUNCTION SetFileShortNameA LIB "Kernel32.dll" _
    ALIAS "SetFileShortNameA" (BYVAL hFile AS DWORD, _
    lpShortName AS ASCIIZ) AS LONG

DECLARE FUNCTION SetFileShortNameW LIB "Kernel32.dll" _
    ALIAS "SetFileShortNameW" (BYVAL hFile AS DWORD, _
    lpShortName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetFileShortName LIB "Kernel32.dll" _
    ALIAS "SetFileShortNameW" (BYVAL hFile AS DWORD, _
    lpShortName AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION SetFileShortName LIB "Kernel32.dll" _
    ALIAS "SetFileShortNameA" (BYVAL hFile AS DWORD, _
    lpShortName AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CloseHandle LIB "Kernel32.dll" ALIAS "CloseHandle" _
    (BYVAL hObject AS DWORD) AS LONG

DECLARE FUNCTION DuplicateHandle LIB "Kernel32.dll" ALIAS "DuplicateHandle" _
    (BYVAL hSourceProcessHandle AS DWORD, BYVAL hSourceHandle AS DWORD, _
    BYVAL hTargetProcessHandle AS DWORD, lpTargetHandle AS DWORD, _
    BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    BYVAL dwOptions AS DWORD) AS LONG

DECLARE FUNCTION GetHandleInformation LIB "Kernel32.dll" _
    ALIAS "GetHandleInformation" (BYVAL hObject AS DWORD, _
    lpdwFlags AS DWORD) AS LONG

DECLARE FUNCTION SetHandleInformation LIB "Kernel32.dll" _
    ALIAS "SetHandleInformation" (BYVAL hObject AS DWORD, _
    BYVAL dwMask AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

%HANDLE_FLAG_INHERIT            = &H00000001
%HANDLE_FLAG_PROTECT_FROM_CLOSE = &H00000002

%HINSTANCE_ERROR = 32

DECLARE FUNCTION LoadModule LIB "Kernel32.dll" ALIAS "LoadModule" _
    (lpModuleName AS ASCIIZ, BYVAL lpParameterBlock AS DWORD) AS DWORD

DECLARE FUNCTION WinExec LIB "Kernel32.dll" ALIAS "WinExec" _
    (lpCmdLine AS ASCIIZ, BYVAL nCmdShow AS DWORD) AS DWORD

DECLARE FUNCTION ClearCommBreak LIB "Kernel32.dll" ALIAS "ClearCommBreak" _
    (BYVAL hFile AS DWORD) AS LONG

DECLARE FUNCTION ClearCommError LIB "Kernel32.dll" ALIAS "ClearCommError" _
    (BYVAL hFile AS DWORD, lpErrors AS DWORD, lpStat AS COMSTAT) AS LONG

DECLARE FUNCTION SetupComm LIB "Kernel32.dll" ALIAS "SetupComm" _
    (BYVAL hFile AS DWORD, BYVAL dwInQueue AS DWORD, _
    BYVAL dwOutQueue AS DWORD) AS LONG

DECLARE FUNCTION EscapeCommFunction LIB "Kernel32.dll" _
    ALIAS "EscapeCommFunction" (BYVAL hFile AS DWORD, BYVAL nFunc AS DWORD) _
    AS LONG

DECLARE FUNCTION GetCommConfig LIB "Kernel32.dll" ALIAS "GetCommConfig" _
    (BYVAL hCommDev AS DWORD, lpCC AS COMMCONFIG, lpdwSize AS DWORD) AS LONG

DECLARE FUNCTION GetCommMask LIB "Kernel32.dll" ALIAS "GetCommMask" _
    (BYVAL hFile AS DWORD, lpEvtMask AS DWORD) AS LONG

DECLARE FUNCTION GetCommProperties LIB "Kernel32.dll" _
    ALIAS "GetCommProperties" (BYVAL hFile AS DWORD, _
    BYVAL lpCommProp AS DWORD) AS LONG

DECLARE FUNCTION GetCommModemStatus LIB "Kernel32.dll" _
    ALIAS "GetCommModemStatus" (BYVAL hFile AS DWORD, lpModemStat AS DWORD) _
    AS LONG

DECLARE FUNCTION GetCommState LIB "Kernel32.dll" ALIAS "GetCommState" _
    (BYVAL hFile AS DWORD, lpDCB AS DCB) AS LONG

DECLARE FUNCTION GetCommTimeouts LIB "Kernel32.dll" ALIAS "GetCommTimeouts" _
    (BYVAL hFile AS DWORD, lpCommTimeouts AS COMMTIMEOUTS) AS LONG

DECLARE FUNCTION PurgeComm LIB "Kernel32.dll" ALIAS "PurgeComm" _
    (BYVAL hFile AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION SetCommBreak LIB "Kernel32.dll" ALIAS "SetCommBreak" _
    (BYVAL hFile AS DWORD) AS LONG

DECLARE FUNCTION SetCommConfig LIB "Kernel32.dll" ALIAS "SetCommConfig" _
    (BYVAL hCommDev AS DWORD, lpCC AS COMMCONFIG, BYVAL dwSize AS DWORD) _
    AS LONG

DECLARE FUNCTION SetCommMask LIB "Kernel32.dll" ALIAS "SetCommMask" _
    (BYVAL hFile AS DWORD, BYVAL dwEventMask AS DWORD) AS LONG

DECLARE FUNCTION SetCommState LIB "Kernel32.dll" ALIAS "SetCommState" _
    (BYVAL hCommDev AS DWORD, lpDCB AS DCB) AS LONG

DECLARE FUNCTION SetCommTimeouts LIB "Kernel32.dll" ALIAS "SetCommTimeouts" _
    (BYVAL hFile AS DWORD, lpCommTimeouts AS COMMTIMEOUTS) AS LONG

DECLARE FUNCTION TransmitCommChar LIB "Kernel32.dll" _
    ALIAS "TransmitCommChar" (BYVAL hFile AS DWORD, BYVAL cChar AS BYTE) _
    AS LONG

DECLARE FUNCTION WaitCommEvent LIB "Kernel32.dll" ALIAS "WaitCommEvent" _
    (BYVAL hFile AS DWORD, lpEvtMask AS DWORD, lpOverlapped AS OVERLAPPED) _
    AS LONG

DECLARE FUNCTION SetTapePosition LIB "Kernel32.dll" ALIAS "SetTapePosition" _
    (BYVAL hDevice AS DWORD, BYVAL dwPositionMethod AS DWORD, _
    BYVAL dwPartition AS DWORD, BYVAL dwOffsetLow AS DWORD, _
    BYVAL dwOffsetHigh AS DWORD, BYVAL bimmediate AS LONG) AS DWORD

DECLARE FUNCTION GetTapePosition LIB "Kernel32.dll" ALIAS "GetTapePosition" _
    (BYVAL hDevice AS DWORD, BYVAL dwPositionType AS DWORD, _
    lpdwPartition AS DWORD, lpdwOffsetLow AS DWORD, lpdwOffsetHigh AS DWORD) _
    AS DWORD

DECLARE FUNCTION PrepareTape LIB "Kernel32.dll" ALIAS "PrepareTape" _
    (BYVAL hDevice AS DWORD, BYVAL dwOperation AS DWORD, _
    BYVAL bimmediate AS LONG) AS DWORD

DECLARE FUNCTION EraseTape LIB "Kernel32.dll" ALIAS "EraseTape" _
    (BYVAL hDevice AS DWORD, BYVAL dwEraseType AS DWORD, _
    BYVAL bimmediate AS LONG) AS DWORD

DECLARE FUNCTION CreateTapePartition LIB "Kernel32.dll" _
    ALIAS "CreateTapePartition" (BYVAL hDevice AS DWORD, _
    BYVAL dwPartitionMethod AS DWORD, BYVAL dwCount AS DWORD, _
    BYVAL dwSize AS DWORD) AS DWORD

DECLARE FUNCTION WriteTapemark LIB "Kernel32.dll" ALIAS "WriteTapemark" _
    (BYVAL hDevice AS DWORD, BYVAL dwTapeMarkType AS DWORD, _
    BYVAL dwTapeMarkCount AS DWORD, BYVAL bimmediate AS LONG) AS DWORD

DECLARE FUNCTION GetTapeStatus LIB "Kernel32.dll" ALIAS "GetTapeStatus" _
    (BYVAL hDevice AS DWORD) AS DWORD

DECLARE FUNCTION GetTapeParameters LIB "Kernel32.dll" _
    ALIAS "GetTapeParameters" (BYVAL hDevice AS DWORD, _
    BYVAL dwOperation AS DWORD, lpdwSize AS DWORD, _
    BYVAL lpTapeInformation AS DWORD) AS DWORD

%GET_TAPE_MEDIA_INFORMATION = 0
%GET_TAPE_DRIVE_INFORMATION = 1

DECLARE FUNCTION SetTapeParameters LIB "Kernel32.dll" _
    ALIAS "SetTapeParameters" (BYVAL hDevice AS DWORD, _
    BYVAL dwOperation AS DWORD, BYVAL lpTapeInformation AS DWORD) AS DWORD

%SET_TAPE_MEDIA_INFORMATION = 0
%SET_TAPE_DRIVE_INFORMATION = 1

DECLARE FUNCTION WinBeep LIB "Kernel32.dll" ALIAS "Beep" _
    (BYVAL dwFreq AS DWORD, BYVAL dwDuration AS DWORD) AS LONG

DECLARE FUNCTION MulDiv LIB "Kernel32.dll" ALIAS "MulDiv" _
    (BYVAL nNumber AS LONG, BYVAL nNumerator AS LONG, _
    BYVAL nDenominator AS LONG) AS LONG

DECLARE SUB GetSystemTime LIB "Kernel32.dll" ALIAS "GetSystemTime" _
    (lpSystemTime AS SYSTEMTIME)

DECLARE SUB GetSystemTimeAsFileTime LIB "Kernel32.dll" _
    ALIAS "GetSystemTimeAsFileTime" (lpFileTime AS FILETIME)

DECLARE FUNCTION SetSystemTime LIB "Kernel32.dll" ALIAS "SetSystemTime" _
    (lpSystemTime AS SYSTEMTIME) AS LONG

DECLARE SUB GetLocalTime LIB "Kernel32.dll" ALIAS "GetLocalTime" _
    (lpSystemTime AS SYSTEMTIME)

DECLARE FUNCTION SetLocalTime LIB "Kernel32.dll" ALIAS "SetLocalTime" _
    (lpSystemTime AS SYSTEMTIME) AS LONG

DECLARE SUB GetSystemInfo LIB "Kernel32.dll" ALIAS "GetSystemInfo" _
    (lpSystemInfo AS SYSTEM_INFO)

MACRO DEP_SYSTEM_POLICY_TYPE_enum=LONG
ENUM DEP_SYSTEM_POLICY_TYPE SINGULAR
    DEPPolicyAlwaysOff
    DEPPolicyAlwaysOn
    DEPPolicyOptIn
    DEPPolicyOptOut
    DEPTotalPolicyCount
END ENUM

DECLARE FUNCTION GetSystemDEPPolicy LIB "Kernel32.dll" _
    ALIAS "GetSystemDEPPolicy" () AS DEP_SYSTEM_POLICY_TYPE_enum

#IF %WIN32_WINNT >= &H0502

%FILE_CACHE_FLAGS_DEFINED = 1

%FILE_CACHE_MAX_HARD_ENABLE     = &H00000001
%FILE_CACHE_MAX_HARD_DISABLE    = &H00000002
%FILE_CACHE_MIN_HARD_ENABLE     = &H00000004
%FILE_CACHE_MIN_HARD_DISABLE    = &H00000008

DECLARE FUNCTION SetSystemFileCacheSize LIB "Kernel32.dll" _
    ALIAS "SetSystemFileCacheSize" (BYVAL MinimumFileCacheSize AS DWORD, _
    BYVAL MaximumFileCacheSize AS DWORD, BYVAL dFlags AS DWORD) AS LONG

DECLARE FUNCTION GetSystemFileCacheSize LIB "Kernel32.dll" _
    ALIAS "GetSystemFileCacheSize" (MinimumFileCacheSize AS DWORD, _
    MaximumFileCacheSize AS DWORD, dFlags AS DWORD) AS LONG

#ENDIF ' (%WIN32_WINNT >= &H0502)

#IF %WIN32_WINNT >= &H0501

DECLARE FUNCTION GetSystemRegistryQuota LIB "Kernel32.dll" _
    ALIAS "GetSystemRegistryQuota" (pdwQuotaAllowed AS DWORD, _
    pdwQuotaUsed AS DWORD) AS LONG

DECLARE FUNCTION GetSystemTimes LIB "Kernel32.dll" ALIAS "GetSystemTimes" _
    (lpIdleTime AS FILETIME, lpKernelTime AS FILETIME, _
    lpUserTime AS FILETIME) AS LONG

DECLARE SUB GetNativeSystemInfo LIB "Kernel32.dll" _
    ALIAS "GetNativeSystemInfo" (lpSystemInfo AS SYSTEM_INFO)

#ENDIF ' (%WIN32_WINNT >= &H0501)

DECLARE FUNCTION IsProcessorFeaturePresent LIB "Kernel32.dll" _
    ALIAS "IsProcessorFeaturePresent" (BYVAL ProcessorFeature AS DWORD) AS LONG

TYPE TIME_ZONE_INFORMATION
    Bias         AS LONG
    StandardName AS WSTRINGZ * 32
    StandardDate AS SYSTEMTIME
    StandardBias AS LONG
    DaylightName AS WSTRINGZ * 32
    DaylightDate AS SYSTEMTIME
    DaylightBias AS LONG
END TYPE

TYPE DYNAMIC_TIME_ZONE_INFORMATION
    Bias            AS LONG
    StandardName    AS WSTRINGZ * 32
    StandardDate    AS SYSTEMTIME
    StandardBias    AS LONG
    DaylightName    AS WSTRINGZ * 32
    DaylightDate    AS SYSTEMTIME
    DaylightBias    AS LONG
    TimeZoneKeyName AS WSTRINGZ * 128
    DynamicDaylightTimeDisabled AS BYTE
END TYPE

DECLARE FUNCTION SystemTimeToTzSpecificLocalTime LIB "Kernel32.dll" _
    ALIAS "SystemTimeToTzSpecificLocalTime" _
    (lpTimeZoneInformation AS TIME_ZONE_INFORMATION, _
    lpUniversalTime AS SYSTEMTIME, lpLocalTime AS SYSTEMTIME) AS LONG

DECLARE FUNCTION TzSpecificLocalTimeToSystemTime LIB "Kernel32.dll" _
    ALIAS "TzSpecificLocalTimeToSystemTime" _
    (lpTimeZoneInformation AS TIME_ZONE_INFORMATION, _
    lpLocalTime AS SYSTEMTIME, lpUniversalTime AS SYSTEMTIME) AS LONG

DECLARE FUNCTION GetTimeZoneInformationForYear LIB "Kernel32.dll" _
    ALIAS "GetTimeZoneInformationForYear" (BYVAL wYear AS WORD, _
    pdtzi AS DYNAMIC_TIME_ZONE_INFORMATION, ptzi AS TIME_ZONE_INFORMATION) _
    AS LONG

DECLARE FUNCTION GetTimeZoneInformation LIB "Kernel32.dll" _
    ALIAS "GetTimeZoneInformation" _
    (lpTimeZoneInformation AS TIME_ZONE_INFORMATION) AS DWORD

DECLARE FUNCTION SetTimeZoneInformation LIB "Kernel32.dll" _
    ALIAS "SetTimeZoneInformation" _
    (lpTimeZoneInformation AS TIME_ZONE_INFORMATION) AS LONG

DECLARE FUNCTION GetDynamicTimeZoneInformation LIB "Kernel32.dll" _
    ALIAS "GetDynamicTimeZoneInformation" _
    (pTimeZoneInformation AS DYNAMIC_TIME_ZONE_INFORMATION) AS DWORD

DECLARE FUNCTION SetDynamicTimeZoneInformation LIB "Kernel32.dll" _
    ALIAS "SetDynamicTimeZoneInformation" _
    (pTimeZoneInformation AS DYNAMIC_TIME_ZONE_INFORMATION) AS LONG

'
' Routines to convert back and forth between system time and file time
'

DECLARE FUNCTION SystemTimeToFileTime LIB "Kernel32.dll" _
    ALIAS "SystemTimeToFileTime" (lpSystemTime AS SYSTEMTIME, _
    lpFileTime AS FILETIME) AS LONG

DECLARE FUNCTION FileTimeToLocalFileTime LIB "Kernel32.dll" _
    ALIAS "FileTimeToLocalFileTime" (lpFileTime AS FILETIME, _
    lpLocalFileTime AS FILETIME) AS LONG

DECLARE FUNCTION LocalFileTimeToFileTime LIB "Kernel32.dll" _
    ALIAS "LocalFileTimeToFileTime" (lpLocalFileTime AS FILETIME, _
    lpFileTime AS FILETIME) AS LONG

DECLARE FUNCTION FileTimeToSystemTime LIB "Kernel32.dll" _
    ALIAS "FileTimeToSystemTime" (lpFileTime AS FILETIME, _
    lpSystemTime AS SYSTEMTIME) AS LONG

DECLARE FUNCTION CompareFileTime LIB "Kernel32.dll" ALIAS "CompareFileTime" _
    (lpFileTime1 AS FILETIME, lpFileTime2 AS FILETIME) AS LONG

DECLARE FUNCTION FileTimeToDosDateTime LIB "Kernel32.dll" _
    ALIAS "FileTimeToDosDateTime" (lpFileTime AS FILETIME, _
    lpFatDate AS WORD, lpFatTime AS WORD) AS LONG

DECLARE FUNCTION DosDateTimeToFileTime LIB "Kernel32.dll" _
    ALIAS "DosDateTimeToFileTime" (BYVAL wFatDate AS WORD, _
    BYVAL wFatTime AS WORD, lpFileTime AS FILETIME) AS LONG

DECLARE FUNCTION GetTickCount LIB "Kernel32.dll" ALIAS "GetTickCount" () _
    AS DWORD

#IF (%WIN32_WINNT >= &H0600)

DECLARE FUNCTION GetTickCount64 LIB "Kernel32.dll" ALIAS "GetTickCount64" _
    AS QUAD   ' *** should be unsigned

#ENDIF

DECLARE FUNCTION SetSystemTimeAdjustment LIB "Kernel32.dll" _
    ALIAS "SetSystemTimeAdjustment" (BYVAL dwTimeAdjustment AS DWORD, _
    BYVAL bTimeAdjustmentDisabled AS LONG) AS LONG

DECLARE FUNCTION GetSystemTimeAdjustment LIB "Kernel32.dll" _
    ALIAS "GetSystemTimeAdjustment" (lpTimeAdjustment AS DWORD, _
    lpTimeIncrement AS DWORD, lpTimeAdjustmentDisabled AS LONG) AS LONG

DECLARE FUNCTION FormatMessageA LIB "Kernel32.dll" ALIAS "FormatMessageA" _
    (BYVAL dwFlags AS DWORD, BYVAL lpSource AS DWORD, _
    BYVAL dwMessageId AS DWORD, BYVAL dwLanguageId AS DWORD, _
    lpBuffer AS ASCIIZ, BYVAL nSize AS DWORD, BYVAL Arguments AS DWORD) _
    AS DWORD

DECLARE FUNCTION FormatMessageW LIB "Kernel32.dll" ALIAS "FormatMessageW" _
    (BYVAL dwFlags AS DWORD, BYVAL lpSource AS DWORD, _
    BYVAL dwMessageId AS DWORD, BYVAL dwLanguageId AS DWORD, _
    lpBuffer AS WSTRINGZ, BYVAL nSize AS DWORD, BYVAL Arguments AS DWORD) _
    AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION FormatMessage LIB "Kernel32.dll" ALIAS "FormatMessageW" _
    (BYVAL dwFlags AS DWORD, BYVAL lpSource AS DWORD, _
    BYVAL dwMessageId AS DWORD, BYVAL dwLanguageId AS DWORD, _
    lpBuffer AS WSTRINGZ, BYVAL nSize AS DWORD, BYVAL Arguments AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION FormatMessage LIB "Kernel32.dll" ALIAS "FormatMessageA" _
    (BYVAL dwFlags AS DWORD, BYVAL lpSource AS DWORD, _
    BYVAL dwMessageId AS DWORD, BYVAL dwLanguageId AS DWORD, _
    lpBuffer AS ASCIIZ, BYVAL nSize AS DWORD, BYVAL Arguments AS DWORD) _
    AS DWORD
#ENDIF ' NOT %UNICODE

%FORMAT_MESSAGE_ALLOCATE_BUFFER= &H00000100
%FORMAT_MESSAGE_IGNORE_INSERTS = &H00000200
%FORMAT_MESSAGE_FROM_STRING    = &H00000400
%FORMAT_MESSAGE_FROM_HMODULE   = &H00000800
%FORMAT_MESSAGE_FROM_SYSTEM    = &H00001000
%FORMAT_MESSAGE_ARGUMENT_ARRAY = &H00002000
%FORMAT_MESSAGE_MAX_WIDTH_MASK = &H000000FF

DECLARE FUNCTION CreatePipe LIB "Kernel32.dll" ALIAS "CreatePipe" _
    (phReadPipe AS DWORD, phWritePipe AS DWORD, _
    lpPipeAttributes AS SECURITY_ATTRIBUTES, BYVAL nSize AS DWORD) AS LONG

DECLARE FUNCTION ConnectNamedPipe LIB "Kernel32.dll" _
    ALIAS "ConnectNamedPipe" (BYVAL hNamedPipe AS DWORD, _
    lpOverlapped AS OVERLAPPED) AS LONG

DECLARE FUNCTION DisconnectNamedPipe LIB "Kernel32.dll" _
    ALIAS "DisconnectNamedPipe" (BYVAL hNamedPipe AS DWORD) AS LONG

DECLARE FUNCTION SetNamedPipeHandleState LIB "Kernel32.dll" _
    ALIAS "SetNamedPipeHandleState" (BYVAL hNamedPipe AS DWORD, _
    lpMode AS DWORD, lpMaxCollectionCount AS DWORD, _
    lpCollectDataTimeout AS DWORD) AS LONG

DECLARE FUNCTION GetNamedPipeInfo LIB "Kernel32.dll" _
    ALIAS "GetNamedPipeInfo" (BYVAL hNamedPipe AS DWORD, lpFlags AS DWORD, _
    lpOutBufferSize AS DWORD, lpInBufferSize AS DWORD, _
    lpMaxInstances AS DWORD) AS LONG

DECLARE FUNCTION PeekNamedPipe LIB "Kernel32.dll" ALIAS "PeekNamedPipe" _
    (BYVAL hNamedPipe AS DWORD, BYVAL lpBuffer AS DWORD, _
    BYVAL nBufferSize AS DWORD, lpBytesRead AS DWORD, _
    lpTotalBytesAvail AS DWORD, lpBytesLeftThisMessage AS DWORD) AS LONG

DECLARE FUNCTION TransactNamedPipe LIB "Kernel32.dll" _
    ALIAS "TransactNamedPipe" (BYVAL hNamedPipe AS DWORD, _
    BYVAL lpInBuffer AS DWORD, BYVAL nInBufferSize AS DWORD, _
    BYVAL lpOutBuffer AS DWORD, BYVAL nOutBufferSize AS DWORD, _
    lpBytesRead AS DWORD, lpOverlapped AS OVERLAPPED) AS LONG

DECLARE FUNCTION CreateMailslotA LIB "Kernel32.dll" ALIAS "CreateMailslotA" _
    (lpName AS ASCIIZ, BYVAL nMaxMessageSize AS DWORD, _
    BYVAL lReadTimeout AS DWORD, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES) AS DWORD

DECLARE FUNCTION CreateMailslotW LIB "Kernel32.dll" ALIAS "CreateMailslotW" _
    (lpName AS WSTRINGZ, BYVAL nMaxMessageSize AS DWORD, _
    BYVAL lReadTimeout AS DWORD, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateMailslot LIB "Kernel32.dll" ALIAS "CreateMailslotW" _
    (lpName AS WSTRINGZ, BYVAL nMaxMessageSize AS DWORD, _
    BYVAL lReadTimeout AS DWORD, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES) AS DWORD
#ELSE
DECLARE FUNCTION CreateMailslot LIB "Kernel32.dll" ALIAS "CreateMailslotA" _
    (lpName AS ASCIIZ, BYVAL nMaxMessageSize AS DWORD, _
    BYVAL lReadTimeout AS DWORD, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetMailslotInfo LIB "Kernel32.dll" ALIAS "GetMailslotInfo" _
    (BYVAL hMailSlot AS DWORD, lpMaxMessageSize AS DWORD, _
    lpNextSize AS DWORD, lpMessageCount AS DWORD, lpReadTimeout AS DWORD) _
    AS LONG

DECLARE FUNCTION SetMailslotInfo LIB "Kernel32.dll" ALIAS "SetMailslotInfo" _
    (BYVAL hMailslot AS DWORD, BYVAL lReadTimeout AS DWORD) AS LONG

DECLARE FUNCTION MapViewOfFile LIB "Kernel32.dll" ALIAS "MapViewOfFile" _
    (BYVAL hFileMappingObject AS DWORD, BYVAL dwDesiredAccess AS DWORD, _
    BYVAL dwFileOffsetHigh AS DWORD, BYVAL dwFileOffsetLow AS DWORD, _
    BYVAL dwNumberOfBytesToMap AS DWORD) AS DWORD

DECLARE FUNCTION FlushViewOfFile LIB "Kernel32.dll" ALIAS "FlushViewOfFile" _
    (BYVAL lpBaseAddress AS DWORD, BYVAL dwNumberOfBytesToFlush AS DWORD) _
    AS LONG

DECLARE FUNCTION UnmapViewOfFile LIB "Kernel32.dll" ALIAS "UnmapViewOfFile" _
    (BYVAL lpBaseAddress AS DWORD) AS LONG

'
' File Encryption API
'

DECLARE FUNCTION EncryptFileA LIB "AdvApi32.dll" ALIAS "EncryptFileA" _
    (lpFileName AS ASCIIZ) AS LONG

DECLARE FUNCTION EncryptFileW LIB "AdvApi32.dll" ALIAS "EncryptFileW" _
    (lpFileName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION EncryptFile LIB "AdvApi32.dll" ALIAS "EncryptFileW" _
    (lpFileName AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION EncryptFile LIB "AdvApi32.dll" ALIAS "EncryptFileA" _
    (lpFileName AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DecryptFileA LIB "AdvApi32.dll" ALIAS "DecryptFileA" _
    (lpFileName AS ASCIIZ, BYVAL dwReserved AS DWORD) AS LONG

DECLARE FUNCTION DecryptFileW LIB "AdvApi32.dll" ALIAS "DecryptFileW" _
    (lpFileName AS WSTRINGZ, BYVAL dwReserved AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION DecryptFile LIB "AdvApi32.dll" ALIAS "DecryptFileW" _
    (lpFileName AS WSTRINGZ, BYVAL dwReserved AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION DecryptFile LIB "AdvApi32.dll" ALIAS "DecryptFileA" _
    (lpFileName AS ASCIIZ, BYVAL dwReserved AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

'
'  Encryption Status Value
'

%FILE_ENCRYPTABLE              = 0
%FILE_IS_ENCRYPTED             = 1
%FILE_SYSTEM_ATTR              = 2
%FILE_ROOT_DIR                 = 3
%FILE_SYSTEM_DIR               = 4
%FILE_UNKNOWN                  = 5
%FILE_SYSTEM_NOT_SUPPORT       = 6
%FILE_USER_DISALLOWED          = 7
%FILE_READ_ONLY                = 8
%FILE_DIR_DISALLOWED           = 9

DECLARE FUNCTION FileEncryptionStatusA LIB "Kernel32.dll" _
    ALIAS "FileEncryptionStatusA" (lpFileName AS ASCIIZ, lpStatus AS DWORD) _
    AS LONG

DECLARE FUNCTION FileEncryptionStatusW LIB "Kernel32.dll" _
    ALIAS "FileEncryptionStatusW" (lpFileName AS WSTRINGZ, lpStatus AS DWORD) _
    AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION FileEncryptionStatus LIB "Kernel32.dll" _
    ALIAS "FileEncryptionStatusW" (lpFileName AS WSTRINGZ, lpStatus AS DWORD) _
    AS LONG
#ELSE
DECLARE FUNCTION FileEncryptionStatus LIB "Kernel32.dll" _
    ALIAS "FileEncryptionStatusA" (lpFileName AS ASCIIZ, lpStatus AS DWORD) _
    AS LONG
#ENDIF ' NOT %UNICODE

'
' Currently defined recovery flags
'

%EFS_USE_RECOVERY_KEYS  = 1

DECLARE FUNCTION PFE_EXPORT_FUNC (BYVAL pbData AS BYTE PTR, _
    pvCallbackContext AS ANY, BYVAL ulLength AS DWORD) AS DWORD

DECLARE FUNCTION PFE_IMPORT_FUNC (BYVAL pbData AS BYTE PTR, _
    pvCallbackContext AS ANY, BYVAL ulLength AS DWORD) AS DWORD


'
'  OpenRaw flag values
'

%CREATE_FOR_IMPORT  = 1
%CREATE_FOR_DIR     = 2
%OVERWRITE_HIDDEN   = 4
%EFSRPC_SECURE_ONLY = 8


DECLARE FUNCTION OpenEncryptedFileRawA LIB "AdvApi32.dll" _
    ALIAS "OpenEncryptedFileRawA" (lpFileName AS ASCIIZ, _
    BYVAL ulFlags AS DWORD, pvContext AS DWORD) AS DWORD

DECLARE FUNCTION OpenEncryptedFileRawW LIB "AdvApi32.dll" _
    ALIAS "OpenEncryptedFileRawW" (lpFileName AS WSTRINGZ, _
    BYVAL ulFlags AS DWORD, pvContext AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION OpenEncryptedFileRaw LIB "AdvApi32.dll" _
    ALIAS "OpenEncryptedFileRawW" (lpFileName AS WSTRINGZ, _
    BYVAL ulFlags AS DWORD, pvContext AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION OpenEncryptedFileRaw LIB "AdvApi32.dll" _
    ALIAS "OpenEncryptedFileRawA" (lpFileName AS ASCIIZ, _
    BYVAL ulFlags AS DWORD, pvContext AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION ReadEncryptedFileRaw LIB "AdvApi32.dll" _
    ALIAS "ReadEncryptedFileRaw" (BYVAL pfExportCallback AS DWORD, _
    BYVAL pvCallbackContext AS DWORD, BYVAL pvContext AS DWORD) AS DWORD

DECLARE FUNCTION WriteEncryptedFileRaw LIB "AdvApi32.dll" _
    ALIAS "WriteEncryptedFileRaw" (BYVAL pfExportCallback AS DWORD, _
    BYVAL pvCallbackContext AS DWORD, BYVAL pvContext AS DWORD) AS DWORD

DECLARE SUB CloseEncryptedFileRaw LIB "AdvApi32.dll" _
    ALIAS "CloseEncryptedFileRaw" (BYVAL pvContext AS DWORD)

'
' _l Compat Functions
'

DECLARE FUNCTION lstrcmpA LIB "Kernel32.dll" ALIAS "lstrcmpA" _
    (lpString1 AS ASCIIZ, lpString2 AS ASCIIZ) AS LONG

DECLARE FUNCTION lstrcmpW LIB "Kernel32.dll" ALIAS "lstrcmpW" _
    (lpString1 AS WSTRINGZ, lpString2 AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION lstrcmp LIB "Kernel32.dll" ALIAS "lstrcmpW" _
    (lpString1 AS WSTRINGZ, lpString2 AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION lstrcmp LIB "Kernel32.dll" ALIAS "lstrcmpA" _
    (lpString1 AS ASCIIZ, lpString2 AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION lstrcmpiA LIB "Kernel32.dll" ALIAS "lstrcmpiA" _
    (lpString1 AS ASCIIZ, lpString2 AS ASCIIZ) AS LONG

DECLARE FUNCTION lstrcmpiW LIB "Kernel32.dll" ALIAS "lstrcmpiW" _
    (lpString1 AS WSTRINGZ, lpString2 AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION lstrcmpi LIB "Kernel32.dll" ALIAS "lstrcmpiW" _
    (lpString1 AS WSTRINGZ, lpString2 AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION lstrcmpi LIB "Kernel32.dll" ALIAS "lstrcmpiA" _
    (lpString1 AS ASCIIZ, lpString2 AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION lstrcpynA LIB "Kernel32.dll" ALIAS "lstrcpynA" _
    (lpString1 AS ASCIIZ, lpString2 AS ASCIIZ, BYVAL iMaxLength AS LONG) _
    AS LONG

DECLARE FUNCTION lstrcpynW LIB "Kernel32.dll" ALIAS "lstrcpynW" _
    (lpString1 AS WSTRINGZ, lpString2 AS WSTRINGZ, BYVAL iMaxLength AS LONG) _
    AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION lstrcpyn LIB "Kernel32.dll" ALIAS "lstrcpynW" _
    (lpString1 AS WSTRINGZ, lpString2 AS WSTRINGZ, BYVAL iMaxLength AS LONG) _
    AS LONG
#ELSE
DECLARE FUNCTION lstrcpyn LIB "Kernel32.dll" ALIAS "lstrcpynA" _
    (lpString1 AS ASCIIZ, lpString2 AS ASCIIZ, BYVAL iMaxLength AS LONG) _
    AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION lstrcpyA LIB "Kernel32.dll" ALIAS "lstrcpyA" _
    (lpString1 AS ASCIIZ, lpString2 AS ASCIIZ) AS DWORD

DECLARE FUNCTION lstrcpyW LIB "Kernel32.dll" ALIAS "lstrcpyW" _
    (lpString1 AS WSTRINGZ, lpString2 AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION lstrcpy LIB "Kernel32.dll" ALIAS "lstrcpyW" _
    (lpString1 AS WSTRINGZ, lpString2 AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION lstrcpy LIB "Kernel32.dll" ALIAS "lstrcpyA" _
    (lpString1 AS ASCIIZ, lpString2 AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION lstrcatA LIB "Kernel32.dll" ALIAS "lstrcatA" _
    (lpString1 AS ASCIIZ, lpString2 AS ASCIIZ) AS LONG

DECLARE FUNCTION lstrcatW LIB "Kernel32.dll" ALIAS "lstrcatW" _
    (lpString1 AS WSTRINGZ, lpString2 AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION lstrcat LIB "Kernel32.dll" ALIAS "lstrcatW" _
    (lpString1 AS WSTRINGZ, lpString2 AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION lstrcat LIB "Kernel32.dll" ALIAS "lstrcatA" _
    (lpString1 AS ASCIIZ, lpString2 AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION lstrlenA LIB "Kernel32.dll" ALIAS "lstrlenA" _
    (lpString AS ASCIIZ) AS LONG

DECLARE FUNCTION lstrlenW LIB "Kernel32.dll" ALIAS "lstrlenW" _
    (lpString AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION lstrlen LIB "Kernel32.dll" ALIAS "lstrlenW" _
    (lpString AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION lstrlen LIB "Kernel32.dll" ALIAS "lstrlenA" _
    (lpString AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION OpenFile LIB "Kernel32.dll" ALIAS "OpenFile" _
    (lpFileName AS ASCIIZ, lpReOpenBuff AS OFSTRUCT, _
    BYVAL uStyle AS DWORD) AS DWORD

DECLARE FUNCTION lopen LIB "Kernel32.dll" ALIAS "_lopen" _
    (lpPathName AS ASCIIZ, BYVAL iReadWrite AS LONG) AS DWORD

DECLARE FUNCTION lcreat LIB "Kernel32.dll" ALIAS "_lcreat" _
    (lpPathName AS ASCIIZ, BYVAL iAttribute AS LONG) AS LONG

DECLARE FUNCTION lread LIB "Kernel32.dll" ALIAS "_lread" _
    (BYVAL hFile AS DWORD, BYVAL lpBuffer AS DWORD, BYVAL uBytes AS DWORD) _
    AS DWORD

DECLARE FUNCTION lwrite LIB "Kernel32.dll" ALIAS "_lwrite" _
    (BYVAL hFile AS DWORD, BYVAL lpBuffer AS DWORD, BYVAL uBytes AS DWORD) _
    AS DWORD

DECLARE FUNCTION hread LIB "Kernel32.dll" ALIAS "_hread" _
    (BYVAL hFile AS DWORD, BYVAL lpBuffer AS DWORD, BYVAL lBytes AS LONG) _
    AS LONG

DECLARE FUNCTION hwrite LIB "Kernel32.dll" ALIAS "_hwrite" _
    (BYVAL hFile AS DWORD, BYVAL lpBuffer AS DWORD, BYVAL lBytes AS LONG) _
    AS LONG

DECLARE FUNCTION lclose LIB "Kernel32.dll" ALIAS "_lclose" _
    (BYVAL hFile AS DWORD) AS DWORD

DECLARE FUNCTION llseek LIB "Kernel32.dll" ALIAS "_llseek" _
    (BYVAL hFile AS DWORD, BYVAL lOffset AS LONG, BYVAL iOrigin AS LONG) _
    AS LONG

DECLARE FUNCTION IsTextUnicode LIB "AdvApi32.dll" ALIAS "IsTextUnicode" _
    (BYVAL lpv AS DWORD, BYVAL iSize AS LONG, lpiResult AS LONG) AS LONG

%FLS_OUT_OF_INDEXES = &HFFFFFFFF???

DECLARE FUNCTION FlsAlloc LIB "Kernel32.dll" ALIAS "FlsAlloc" _
    (BYVAL lpCallback AS DWORD) AS DWORD

DECLARE FUNCTION FlsGetValue LIB "Kernel32.dll" ALIAS "FlsGetValue" _
    (BYVAL dwFlsIndex AS DWORD) AS DWORD

DECLARE FUNCTION FlsSetValue LIB "Kernel32.dll" ALIAS "FlsSetValue" _
    (BYVAL dwFlsIndex AS DWORD, lpFlsData AS DWORD) AS LONG

DECLARE FUNCTION FlsFree LIB "Kernel32.dll" ALIAS "FlsFree" _
    (BYVAL dwFlsIndex AS DWORD) AS LONG

%TLS_OUT_OF_INDEXES = &HFFFFFFFF???

DECLARE FUNCTION TlsAlloc LIB "Kernel32.dll" ALIAS "TlsAlloc" () AS DWORD

DECLARE FUNCTION TlsGetValue LIB "Kernel32.dll" ALIAS "TlsGetValue" _
    (BYVAL dwTlsIndex AS DWORD) AS DWORD

DECLARE FUNCTION TlsSetValue LIB "Kernel32.dll" ALIAS "TlsSetValue" _
    (BYVAL dwTlsIndex AS DWORD, lpTlsValue AS DWORD) AS LONG

DECLARE FUNCTION TlsFree LIB "Kernel32.dll" ALIAS "TlsFree" _
    (BYVAL dwTlsIndex AS DWORD) AS LONG

DECLARE SUB LPOVERLAPPED_COMPLETION_ROUTINE _
    (BYVAL dwErrorCode AS DWORD, _
    BYVAL dwNumberOfBytesTransfered AS DWORD, lpOverlapped AS OVERLAPPED)

DECLARE FUNCTION SleepEx LIB "Kernel32.dll" ALIAS "SleepEx" _
    (BYVAL dwMilliseconds AS DWORD, BYVAL bAlertable AS LONG) AS DWORD

DECLARE FUNCTION WaitForSingleObjectEx LIB "Kernel32.dll" _
    ALIAS "WaitForSingleObjectEx" (BYVAL hHandle AS DWORD, _
    BYVAL dwMilliseconds AS DWORD, BYVAL bAlertable AS LONG) AS DWORD

DECLARE FUNCTION WaitForMultipleObjectsEx LIB "Kernel32.dll" _
    ALIAS "WaitForMultipleObjectsEx" (BYVAL nCount AS DWORD, _
    lpHandles AS DWORD, BYVAL bWaitAll AS LONG, _
    BYVAL dwMilliseconds AS DWORD, BYVAL bAlertable AS LONG) AS DWORD

#IF (%WIN32_WINNT >= &H0400)

DECLARE FUNCTION SignalObjectAndWait LIB "Kernel32.dll" _
    ALIAS "SignalObjectAndWait" (BYVAL hObjectToSignal AS DWORD, _
    BYVAL hObjectToWaitOn AS DWORD, BYVAL dwMilliseconds AS DWORD, _
    BYVAL bAlertable AS LONG) AS DWORD

#ENDIF ' %WIN32_WINNT >= &H0400

DECLARE FUNCTION ReadFileEx LIB "Kernel32.dll" ALIAS "ReadFileEx" _
    (BYVAL hFile AS DWORD, BYVAL lpBuffer AS DWORD, _
    BYVAL nNumberOfBytesToRead AS DWORD, lpOverlapped AS OVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD) AS LONG

DECLARE FUNCTION WriteFileEx LIB "Kernel32.dll" ALIAS "WriteFileEx" _
    (BYVAL hFile AS DWORD, BYVAL lpBuffer AS DWORD, _
    BYVAL nNumberOfBytesToWrite AS DWORD, lpOverlapped AS OVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD) AS LONG

DECLARE FUNCTION BackupRead LIB "Kernel32.dll" ALIAS "BackupRead" _
    (BYVAL hFile AS DWORD, BYVAL lpBuffer AS DWORD, _
    BYVAL nNumberOfBytesToRead AS DWORD, lpNumberOfBytesRead AS DWORD, _
    BYVAL bAbort AS LONG, BYVAL bProcessSecurity AS LONG, _
    lpContext AS DWORD) AS LONG

DECLARE FUNCTION BackupSeek LIB "Kernel32.dll" ALIAS "BackupSeek" _
    (BYVAL hFile AS DWORD, BYVAL dwLowBytesToSeek AS DWORD, _
    BYVAL dwHighBytesToSeek AS DWORD, lpdwLowByteSeeked AS DWORD, _
    lpdwHighByteSeeked AS LONG, lpContext AS DWORD) AS LONG

DECLARE FUNCTION BackupWrite LIB "Kernel32.dll" ALIAS "BackupWrite" _
    (BYVAL hFile AS DWORD, BYVAL lpBuffer AS DWORD, _
    BYVAL nNumberOfBytesToWrite AS DWORD, lpNumberOfBytesWritten AS DWORD, _
    BYVAL bAbort AS LONG, BYVAL bProcessSecurity AS LONG, _
    lpContext AS DWORD) AS LONG

'
'  Stream id structure
'
'TYPE WIN32_STREAM_ID
'    dwStreamID         AS DWORD
'    dwStreamAttributes AS DWORD
'    qsize              AS QUAD
'    dwStreamNameSize   AS DWORD
'    cStreamName        AS WSTRINGZ * %ANYSIZE_ARRAY
'END TYPE

'
'  Stream Ids
'

%BACKUP_INVALID         = &H00000000
%BACKUP_DATA            = &H00000001
%BACKUP_EA_DATA         = &H00000002
%BACKUP_SECURITY_DATA   = &H00000003
%BACKUP_ALTERNATE_DATA  = &H00000004
%BACKUP_LINK            = &H00000005
%BACKUP_PROPERTY_DATA   = &H00000006
%BACKUP_OBJECT_ID       = &H00000007
%BACKUP_REPARSE_DATA    = &H00000008
%BACKUP_SPARSE_BLOCK    = &H00000009
%BACKUP_TXFS_DATA       = &H0000000a


'
'  Stream Attributes
'

%STREAM_NORMAL_ATTRIBUTE        = &H00000000
%STREAM_MODIFIED_WHEN_READ      = &H00000001
%STREAM_CONTAINS_SECURITY       = &H00000002
%STREAM_CONTAINS_PROPERTIES     = &H00000004
%STREAM_SPARSE_ATTRIBUTE        = &H00000008

DECLARE FUNCTION ReadFileScatter LIB "Kernel32.dll" ALIAS "ReadFileScatter" _
    (BYVAL hFile AS DWORD, BYVAL aSegmentArray AS FILE_SEGMENT_ELEMENT PTR, _
    BYVAL nNumberOfBytesToRead AS DWORD, BYVAL lpReserved AS DWORD, _
    lpOverlapped AS OVERLAPPED) AS LONG

DECLARE FUNCTION WriteFileGather LIB "Kernel32.dll" ALIAS "WriteFileGather" _
    (BYVAL hFile AS DWORD, BYVAL aSegmentArray AS FILE_SEGMENT_ELEMENT PTR, _
    BYVAL nNumberOfBytesToWrite AS DWORD, BYVAL lpReserved AS DWORD, _
    lpOverlapped AS OVERLAPPED) AS LONG

'
' Dual Mode API below this line. Dual Mode Structures also included.
'

%STARTF_USESHOWWINDOW   = &H00000001
%STARTF_USESIZE         = &H00000002
%STARTF_USEPOSITION     = &H00000004
%STARTF_USECOUNTCHARS   = &H00000008
%STARTF_USEFILLATTRIBUTE= &H00000010
%STARTF_RUNFULLSCREEN   = &H00000020  ' ignored for non-x86 platforms
%STARTF_FORCEONFEEDBACK = &H00000040
%STARTF_FORCEOFFFEEDBACK= &H00000080
%STARTF_USESTDHANDLES   = &H00000100

#IF (%WINVER >= &H0400)

%STARTF_USEHOTKEY       = &H00000200
%STARTF_TITLEISLINKNAME = &H00000800
%STARTF_TITLEISAPPID    = &H00001000
%STARTF_PREVENTPINNING  = &H00002000

#ENDIF ' WINVER >= &H0400


TYPE STARTUPINFOA
    cb              AS DWORD
    lpReserved      AS ASCIIZ PTR
    lpDesktop       AS ASCIIZ PTR
    lpTitle         AS ASCIIZ PTR
    dwX             AS DWORD
    dwY             AS DWORD
    dwXSize         AS DWORD
    dwYSize         AS DWORD
    dwXCountChars   AS DWORD
    dwYCountChars   AS DWORD
    dwFillAttribute AS DWORD
    dwFlags         AS DWORD
    wShowWindow     AS WORD
    cbReserved2     AS WORD
    lpReserved2     AS BYTE PTR
    hStdInput       AS DWORD
    hStdOutput      AS DWORD
    hStdError       AS DWORD
END TYPE

TYPE STARTUPINFOW
    cb              AS DWORD
    lpReserved      AS WSTRINGZ PTR
    lpDesktop       AS WSTRINGZ PTR
    lpTitle         AS WSTRINGZ PTR
    dwX             AS DWORD
    dwY             AS DWORD
    dwXSize         AS DWORD
    dwYSize         AS DWORD
    dwXCountChars   AS DWORD
    dwYCountChars   AS DWORD
    dwFillAttribute AS DWORD
    dwFlags         AS DWORD
    wShowWindow     AS WORD
    cbReserved2     AS WORD
    lpReserved2     AS BYTE PTR
    hStdInput       AS DWORD
    hStdOutput      AS DWORD
    hStdError       AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE STARTUPINFO
    STARTUPINFOW
END TYPE
#ELSE
TYPE STARTUPINFO
    STARTUPINFOA
END TYPE
#ENDIF ' UNICODE

#IF (%WIN32_WINNT >= &H0600)

TYPE STARTUPINFOEXA
    StartupInfoValue AS STARTUPINFOA
    lpAttributeList  AS DWORD  ' PROC_THREAD_ATTRIBUTE_LIST PTR [undefined]
END TYPE

TYPE STARTUPINFOEXW
    StartupInfoValue AS STARTUPINFOW
    lpAttributeList  AS DWORD  ' PROC_THREAD_ATTRIBUTE_LIST PTR [undefined]
END TYPE

#IF %DEF(%UNICODE)
TYPE STARTUPINFOEX
    STARTUPINFOEXW
END TYPE
#ELSE
TYPE STARTUPINFOEX
    STARTUPINFOEXA
END TYPE
#ENDIF ' UNICODE

#ENDIF  ' #IF (%WIN32_WINNT >= &H0600)

%SHUTDOWN_NORETRY               = &H00000001

TYPE WIN32_FIND_DATAA
    dwFileAttributes   AS DWORD
    ftCreationTime     AS FILETIME
    ftLastAccessTime   AS FILETIME
    ftLastWriteTime    AS FILETIME
    nFileSizeHigh      AS DWORD
    nFileSizeLow       AS DWORD
    dwReserved0        AS DWORD
    dwReserved1        AS DWORD
    cFileName          AS ASCIIZ * %MAX_PATH
    cAlternateFileName AS ASCIIZ * 14
END TYPE

TYPE WIN32_FIND_DATAW
    dwFileAttributes   AS DWORD
    ftCreationTime     AS FILETIME
    ftLastAccessTime   AS FILETIME
    ftLastWriteTime    AS FILETIME
    nFileSizeHigh      AS DWORD
    nFileSizeLow       AS DWORD
    dwReserved0        AS DWORD
    dwReserved1        AS DWORD
    cFileName          AS WSTRINGZ * %MAX_PATH
    cAlternateFileName AS WSTRINGZ * 14
END TYPE

#IF %DEF(%UNICODE)
TYPE WIN32_FIND_DATA
    WIN32_FIND_DATAW
END TYPE
#ELSE
TYPE WIN32_FIND_DATA
    WIN32_FIND_DATAA
END TYPE
#ENDIF ' UNICODE

TYPE WIN32_FILE_ATTRIBUTE_DATA
    dwFileAttributes AS DWORD
    ftCreationTime   AS FILETIME
    ftLastAccessTime AS FILETIME
    ftLastWriteTime  AS FILETIME
    nFileSizeHigh    AS DWORD
    nFileSizeLow     AS DWORD
END TYPE

'
' Synchronization APIs
'

DECLARE FUNCTION CreateMutexA LIB "Kernel32.dll" ALIAS "CreateMutexA" _
    (lpMutexAttributes AS SECURITY_ATTRIBUTES, BYVAL bInitialOwner AS LONG, _
    lpName AS ASCIIZ) AS DWORD

DECLARE FUNCTION CreateMutexW LIB "Kernel32.dll" ALIAS "CreateMutexW" _
    (lpMutexAttributes AS SECURITY_ATTRIBUTES, BYVAL bInitialOwner AS LONG, _
    lpName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateMutex LIB "Kernel32.dll" ALIAS "CreateMutexW" _
    (lpMutexAttributes AS SECURITY_ATTRIBUTES, BYVAL bInitialOwner AS LONG, _
    lpName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION CreateMutex LIB "Kernel32.dll" ALIAS "CreateMutexA" _
    (lpMutexAttributes AS SECURITY_ATTRIBUTES, BYVAL bInitialOwner AS LONG, _
    lpName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION OpenMutexA LIB "Kernel32.dll" ALIAS "OpenMutexA" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    lpName AS ASCIIZ) AS DWORD

DECLARE FUNCTION OpenMutexW LIB "Kernel32.dll" ALIAS "OpenMutexW" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    lpName AS STRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION OpenMutex LIB "Kernel32.dll" ALIAS "OpenMutexW" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    lpName AS STRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION OpenMutex LIB "Kernel32.dll" ALIAS "OpenMutexA" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    lpName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CreateEventA LIB "Kernel32.dll" ALIAS "CreateEventA"_
    (lpEventAttributes AS SECURITY_ATTRIBUTES, BYVAL bManualReset AS LONG, _
    BYVAL bInitialState AS LONG, lpName AS ASCIIZ) AS DWORD

DECLARE FUNCTION CreateEventW LIB "Kernel32.dll" ALIAS "CreateEventW"_
    (lpEventAttributes AS SECURITY_ATTRIBUTES, BYVAL bManualReset AS LONG, _
    BYVAL bInitialState AS LONG, lpName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateEvent LIB "Kernel32.dll" ALIAS "CreateEventW"_
    (lpEventAttributes AS SECURITY_ATTRIBUTES, BYVAL bManualReset AS LONG, _
    BYVAL bInitialState AS LONG, lpName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION CreateEvent LIB "Kernel32.dll" ALIAS "CreateEventA"_
    (lpEventAttributes AS SECURITY_ATTRIBUTES, BYVAL bManualReset AS LONG, _
    BYVAL bInitialState AS LONG, lpName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION OpenEventA LIB "Kernel32.dll" ALIAS "OpenEventA" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    lpName AS ASCIIZ) AS DWORD

DECLARE FUNCTION OpenEventW LIB "Kernel32.dll" ALIAS "OpenEventW" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    lpName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION OpenEvent LIB "Kernel32.dll" ALIAS "OpenEventW" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    lpName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION OpenEvent LIB "Kernel32.dll" ALIAS "OpenEventA" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    lpName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CreateSemaphoreA LIB "Kernel32.dll" ALIAS "CreateSemaphoreA" _
    (lpSemaphoreAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL lInitialCount AS LONG, BYVAL lMaximumCount AS LONG, _
    lpName AS ASCIIZ) AS DWORD

DECLARE FUNCTION CreateSemaphoreW LIB "Kernel32.dll" ALIAS "CreateSemaphoreW" _
    (lpSemaphoreAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL lInitialCount AS LONG, BYVAL lMaximumCount AS LONG, _
    lpName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateSemaphore LIB "Kernel32.dll" ALIAS "CreateSemaphoreW" _
    (lpSemaphoreAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL lInitialCount AS LONG, BYVAL lMaximumCount AS LONG, _
    lpName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION CreateSemaphore LIB "Kernel32.dll" ALIAS "CreateSemaphoreA" _
    (lpSemaphoreAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL lInitialCount AS LONG, BYVAL lMaximumCount AS LONG, _
    lpName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION OpenSemaphoreA LIB "Kernel32.dll" ALIAS "OpenSemaphoreA" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    lpName AS ASCIIZ) AS DWORD

DECLARE FUNCTION OpenSemaphoreW LIB "Kernel32.dll" ALIAS "OpenSemaphoreW" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    lpName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION OpenSemaphore LIB "Kernel32.dll" ALIAS "OpenSemaphoreW" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    lpName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION OpenSemaphore LIB "Kernel32.dll" ALIAS "OpenSemaphoreA" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    lpName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

#IF (%WIN32_WINNT >= &H0400) OR (%WIN32_WINDOWS > &H0400)

DECLARE SUB PTIMERAPCROUTINE (lpArgToCompletionRoutine AS ANY, _
    BYVAL dwTimerLowValue AS DWORD, BYVAL dwTimerHighValue AS DWORD)

DECLARE FUNCTION CreateWaitableTimerA LIB "Kernel32.dll" _
    ALIAS "CreateWaitableTimerA" (lpTimerAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL bManualReset AS LONG, lpTimerName AS ASCIIZ) AS DWORD

DECLARE FUNCTION CreateWaitableTimerW LIB "Kernel32.dll" _
    ALIAS "CreateWaitableTimerW" (lpTimerAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL bManualReset AS LONG, lpTimerName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateWaitableTimer LIB "Kernel32.dll" _
    ALIAS "CreateWaitableTimerW" (lpTimerAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL bManualReset AS LONG, lpTimerName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION CreateWaitableTimer LIB "Kernel32.dll" _
    ALIAS "CreateWaitableTimerA" (lpTimerAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL bManualReset AS LONG, lpTimerName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION OpenWaitableTimerA LIB "Kernel32.dll" _
    ALIAS "OpenWaitableTimerA" (BYVAL dwDesiredAccess AS DWORD, _
    BYVAL bInheritHandle AS LONG, lpTimerName AS ASCIIZ) AS DWORD

DECLARE FUNCTION OpenWaitableTimerW LIB "Kernel32.dll" _
    ALIAS "OpenWaitableTimerW" (BYVAL dwDesiredAccess AS DWORD, _
    BYVAL bInheritHandle AS LONG, lpTimerName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION OpenWaitableTimer LIB "Kernel32.dll" _
    ALIAS "OpenWaitableTimerW" (BYVAL dwDesiredAccess AS DWORD, _
    BYVAL bInheritHandle AS LONG, lpTimerName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION OpenWaitableTimer LIB "Kernel32.dll" _
    ALIAS "OpenWaitableTimerA" (BYVAL dwDesiredAccess AS DWORD, _
    BYVAL bInheritHandle AS LONG, lpTimerName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

#IF (%WIN32_WINNT >= %WIN32_WINNT_WIN7)

DECLARE FUNCTION SetWaitableTimerEx LIB "Kernel32.dll" _
    ALIAS "SetWaitableTimerEx" ( _
    BYVAL hTimer               AS DWORD, _  ' HANDLE
    lpDueTime                  AS QUAD, _   ' LARGE_INTEGER
    BYVAL lPeriod              AS LONG, _
    BYVAL pfnCompletionRoutine AS DWORD, _  ' PTIMERAPCROUTINE
    lpArgToCompletionRoutine   AS ANY, _    ' LPVOID
    WakeContext                AS REASON_CONTEXT, _
    BYVAL TolerableDelay       AS DWORD) _
    AS LONG   ' BOOL

#ENDIF  ' #IF (%WIN32_WINNT >= %WIN32_WINNT_WIN7)

DECLARE FUNCTION SetWaitableTimer LIB "Kernel32.dll" ALIAS "SetWaitableTimer" _
    (BYVAL hTimer AS DWORD, lpDueTime AS QUAD, BYVAL lPeriod AS LONG, _
    BYVAL pfnCompletionRoutine AS DWORD, _
    BYVAL lpArgToCompletionRoutine AS DWORD, BYVAL fResume AS LONG) AS LONG

DECLARE FUNCTION CancelWaitableTimer LIB "Kernel32.dll" _
    ALIAS "CancelWaitableTimer" (BYVAL hTimer AS DWORD) AS LONG

#IF (%WIN32_WINNT >= &H0600)

%CREATE_MUTEX_INITIAL_OWNER = &H00000001

DECLARE FUNCTION CreateMutexExA LIB "Kernel32.dll" ALIAS "CreateMutexExA" _
    (lpMutexAttributes AS SECURITY_ATTRIBUTES, lpName AS ASCIIZ, _
    BYVAL dwFlags AS DWORD, BYVAL dwDesiredAccess AS DWORD) AS DWORD

DECLARE FUNCTION CreateMutexExW LIB "Kernel32.dll" ALIAS "CreateMutexExW" _
    (lpMutexAttributes AS SECURITY_ATTRIBUTES, lpName AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD, BYVAL dwDesiredAccess AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateMutexEx LIB "Kernel32.dll" ALIAS "CreateMutexExW" _
    (lpMutexAttributes AS SECURITY_ATTRIBUTES, lpName AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD, BYVAL dwDesiredAccess AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION CreateMutexEx LIB "Kernel32.dll" ALIAS "CreateMutexExA" _
    (lpMutexAttributes AS SECURITY_ATTRIBUTES, lpName AS ASCIIZ, _
    BYVAL dwFlags AS DWORD, BYVAL dwDesiredAccess AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

%CREATE_EVENT_MANUAL_RESET  = &H00000001
%CREATE_EVENT_INITIAL_SET   = &H00000002

DECLARE FUNCTION CreateEventExA LIB "Kernel32.dll" ALIAS "CreateEventExA" _
    (lpEventAttributes AS SECURITY_ATTRIBUTES, lpName AS ASCIIZ, _
    BYVAL dwFlags AS DWORD, BYVAL dwDesiredAccess AS DWORD) AS DWORD

DECLARE FUNCTION CreateEventExW LIB "Kernel32.dll" ALIAS "CreateEventExW" _
    (lpEventAttributes AS SECURITY_ATTRIBUTES, lpName AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD, BYVAL dwDesiredAccess AS DWORD) AS DWORD
#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateEventEx LIB "Kernel32.dll" ALIAS "CreateEventExW" _
    (lpEventAttributes AS SECURITY_ATTRIBUTES, lpName AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD, BYVAL dwDesiredAccess AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION CreateEventEx LIB "Kernel32.dll" ALIAS "CreateEventExA" _
    (lpEventAttributes AS SECURITY_ATTRIBUTES, lpName AS ASCIIZ, _
    BYVAL dwFlags AS DWORD, BYVAL dwDesiredAccess AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CreateSemaphoreExA LIB "Kernel32.dll" _
    ALIAS "CreateSemaphoreExA" (lpSemaphoreAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL lInitialCount AS LONG, BYVAL lMaximumCount AS LONG, _
    lpName AS ASCIIZ, BYVAL dwFlags AS DWORD, _
    BYVAL dwDesiredAccess AS DWORD) AS DWORD

DECLARE FUNCTION CreateSemaphoreExW LIB "Kernel32.dll" _
    ALIAS "CreateSemaphoreExW" (lpSemaphoreAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL lInitialCount AS LONG, BYVAL lMaximumCount AS LONG, _
    lpName AS WSTRINGZ, BYVAL dwFlags AS DWORD, _
    BYVAL dwDesiredAccess AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateSemaphoreEx LIB "Kernel32.dll" _
    ALIAS "CreateSemaphoreExW" (lpSemaphoreAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL lInitialCount AS LONG, BYVAL lMaximumCount AS LONG, _
    lpName AS WSTRINGZ, BYVAL dwFlags AS DWORD, _
    BYVAL dwDesiredAccess AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION CreateSemaphoreEx LIB "Kernel32.dll" _
    ALIAS "CreateSemaphoreExA" (lpSemaphoreAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL lInitialCount AS LONG, BYVAL lMaximumCount AS LONG, _
    lpName AS ASCIIZ, BYVAL dwFlags AS DWORD, _
    BYVAL dwDesiredAccess AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

%CREATE_WAITABLE_TIMER_MANUAL_RESET = &H00000001

DECLARE FUNCTION CreateWaitableTimerExA LIB "Kernel32.dll" _
    ALIAS "CreateWaitableTimerExA" (lpTimerAttributes AS SECURITY_ATTRIBUTES, _
    lpTimerName AS ASCIIZ, BYVAL dwFlags AS DWORD, _
    BYVAL dwDesiredAccess AS DWORD) AS DWORD

DECLARE FUNCTION CreateWaitableTimerExW LIB "Kernel32.dll" _
    ALIAS "CreateWaitableTimerExW" (lpTimerAttributes AS SECURITY_ATTRIBUTES, _
    lpTimerName AS WSTRINGZ, BYVAL dwFlags AS DWORD, _
    BYVAL dwDesiredAccess AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateWaitableTimerEx LIB "Kernel32.dll" _
    ALIAS "CreateWaitableTimerExW" (lpTimerAttributes AS SECURITY_ATTRIBUTES, _
    lpTimerName AS WSTRINGZ, BYVAL dwFlags AS DWORD, _
    BYVAL dwDesiredAccess AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION CreateWaitableTimerEx LIB "Kernel32.dll" _
    ALIAS "CreateWaitableTimerExA" (lpTimerAttributes AS SECURITY_ATTRIBUTES, _
    lpTimerName AS ASCIIZ, BYVAL dwFlags AS DWORD, _
    BYVAL dwDesiredAccess AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

#ENDIF ' (%WIN32_WINNT >= &H0600)

#ENDIF ' (%WIN32_WINNT >= &H0400) OR (%WIN32_WINDOWS > &H0400)

DECLARE FUNCTION CreateFileMappingA LIB "Kernel32.dll" _
    ALIAS "CreateFileMappingA" (BYVAL hFile AS DWORD, _
    lpFileMappigAttributes AS SECURITY_ATTRIBUTES, BYVAL flProtect AS DWORD, _
    BYVAL dwMaximumSizeHigh AS DWORD, BYVAL dwMaximumSizeLow AS DWORD, _
    lpName AS ASCIIZ) AS LONG

DECLARE FUNCTION CreateFileMappingW LIB "Kernel32.dll" _
    ALIAS "CreateFileMappingW" (BYVAL hFile AS DWORD, _
    lpFileMappigAttributes AS SECURITY_ATTRIBUTES, BYVAL flProtect AS DWORD, _
    BYVAL dwMaximumSizeHigh AS DWORD, BYVAL dwMaximumSizeLow AS DWORD, _
    lpName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateFileMapping LIB "Kernel32.dll" _
    ALIAS "CreateFileMappingW" (BYVAL hFile AS DWORD, _
    lpFileMappigAttributes AS SECURITY_ATTRIBUTES, BYVAL flProtect AS DWORD, _
    BYVAL dwMaximumSizeHigh AS DWORD, BYVAL dwMaximumSizeLow AS DWORD, _
    lpName AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION CreateFileMapping LIB "Kernel32.dll" _
    ALIAS "CreateFileMappingA" (BYVAL hFile AS DWORD, _
    lpFileMappigAttributes AS SECURITY_ATTRIBUTES, BYVAL flProtect AS DWORD, _
    BYVAL dwMaximumSizeHigh AS DWORD, BYVAL dwMaximumSizeLow AS DWORD, _
    lpName AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

#IF %WIN32_WINNT >= &H0600

DECLARE FUNCTION CreateFileMappingNumaA LIB "Kernel32.dll" _
    ALIAS "CreateFileMappingNumaA" (BYVAL hFile AS DWORD, _
    lpFileMappingAttributes AS SECURITY_ATTRIBUTES, BYVAL flProtect AS DWORD, _
    BYVAL dwMaximumSizeHigh AS DWORD, BYVAL dwMaximumSizeLow AS DWORD, _
    lpName AS ASCIIZ, BYVAL nndPreferred AS DWORD) AS DWORD

DECLARE FUNCTION CreateFileMappingNumaW LIB "Kernel32.dll" _
    ALIAS "CreateFileMappingNumaW" (BYVAL hFile AS DWORD, _
    lpFileMappingAttributes AS SECURITY_ATTRIBUTES, BYVAL flProtect AS DWORD, _
    BYVAL dwMaximumSizeHigh AS DWORD, BYVAL dwMaximumSizeLow AS DWORD, _
    lpName AS WSTRINGZ, BYVAL nndPreferred AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateFileMappingNuma LIB "Kernel32.dll" _
    ALIAS "CreateFileMappingNumaW" (BYVAL hFile AS DWORD, _
    lpFileMappingAttributes AS SECURITY_ATTRIBUTES, BYVAL flProtect AS DWORD, _
    BYVAL dwMaximumSizeHigh AS DWORD, BYVAL dwMaximumSizeLow AS DWORD, _
    lpName AS WSTRINGZ, BYVAL nndPreferred AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION CreateFileMappingNuma LIB "Kernel32.dll" _
    ALIAS "CreateFileMappingNumaA" (BYVAL hFile AS DWORD, _
    lpFileMappingAttributes AS SECURITY_ATTRIBUTES, BYVAL flProtect AS DWORD, _
    BYVAL dwMaximumSizeHigh AS DWORD, BYVAL dwMaximumSizeLow AS DWORD, _
    lpName AS ASCIIZ, BYVAL nndPreferred AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

#ENDIF ' %WIN32_WINNT >= &H0600

DECLARE FUNCTION OpenFileMappingA LIB "Kernel32.dll" ALIAS "OpenFileMappingA" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    lpName AS ASCIIZ) AS DWORD

DECLARE FUNCTION OpenFileMappingW LIB "Kernel32.dll" ALIAS "OpenFileMappingW" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    lpName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION OpenFileMapping LIB "Kernel32.dll" ALIAS "OpenFileMappingW" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    lpName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION OpenFileMapping LIB "Kernel32.dll" ALIAS "OpenFileMappingA" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    lpName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetLogicalDriveStringsA LIB "Kernel32.dll" _
    ALIAS "GetLogicalDriveStringsA" (BYVAL nBufferLength AS DWORD, _
    BYVAL lpBuffer AS DWORD) AS DWORD

DECLARE FUNCTION GetLogicalDriveStringsW LIB "Kernel32.dll" _
    ALIAS "GetLogicalDriveStringsW" (BYVAL nBufferLength AS DWORD, _
    BYVAL lpBuffer AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetLogicalDriveStrings LIB "Kernel32.dll" _
    ALIAS "GetLogicalDriveStringsW" (BYVAL nBufferLength AS DWORD, _
    BYVAL lpBuffer AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetLogicalDriveStrings LIB "Kernel32.dll" _
    ALIAS "GetLogicalDriveStringsA" (BYVAL nBufferLength AS DWORD, _
    BYVAL lpBuffer AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

#IF %WIN32_WINNT >= &H0501

MACRO MEMORY_RESOURCE_NOTIFICATION_TYPE_enum=LONG
ENUM MEMORY_RESOURCE_NOTIFICATION_TYPE SINGULAR
    LowMemoryResourceNotification
    HighMemoryResourceNotification
END ENUM

DECLARE FUNCTION CreateMemoryResourceNotification LIB "Kernel32.dll" _
    ALIAS "CreateMemoryResourceNotification" (BYVAL NotificationType AS LONG) _
    AS DWORD

DECLARE FUNCTION QueryMemoryResourceNotification LIB "Kernel32.dll" _
    ALIAS "QueryMemoryResourceNotification" _
    (BYVAL ResourceNotificationHandle AS DWORD, ResourceState AS LONG) AS LONG

#ENDIF ' %WIN32_WINNT >= &H0501


DECLARE FUNCTION LoadLibraryA LIB "Kernel32.dll" ALIAS "LoadLibraryA" _
    (lpLibFileName AS ASCIIZ) AS DWORD

DECLARE FUNCTION LoadLibraryW LIB "Kernel32.dll" ALIAS "LoadLibraryW" _
    (lpLibFileName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION LoadLibrary LIB "Kernel32.dll" ALIAS "LoadLibraryW" _
    (lpLibFileName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION LoadLibrary LIB "Kernel32.dll" ALIAS "LoadLibraryA" _
    (lpLibFileName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION LoadLibraryExA LIB "Kernel32.dll" ALIAS "LoadLibraryExA" _
    (lpLibFileName AS ASCIIZ, BYVAL hFile AS DWORD, BYVAL dwFlags AS DWORD) _
    AS DWORD

DECLARE FUNCTION LoadLibraryExW LIB "Kernel32.dll" ALIAS "LoadLibraryExW" _
    (lpLibFileName AS WSTRINGZ, BYVAL hFile AS DWORD, BYVAL dwFlags AS DWORD) _
    AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION LoadLibraryEx LIB "Kernel32.dll" ALIAS "LoadLibraryExW" _
    (lpLibFileName AS WSTRINGZ, BYVAL hFile AS DWORD, BYVAL dwFlags AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION LoadLibraryEx LIB "Kernel32.dll" ALIAS "LoadLibraryExA" _
    (lpLibFileName AS ASCIIZ, BYVAL hFile AS DWORD, BYVAL dwFlags AS DWORD) _
    AS DWORD
#ENDIF ' NOT %UNICODE


%DONT_RESOLVE_DLL_REFERENCES        = &H00000001
%LOAD_LIBRARY_AS_DATAFILE           = &H00000002
%LOAD_WITH_ALTERED_SEARCH_PATH      = &H00000008
%LOAD_IGNORE_CODE_AUTHZ_LEVEL       = &H00000010
%LOAD_LIBRARY_AS_IMAGE_RESOURCE     = &H00000020
%LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE = &H00000040
%LOAD_LIBRARY_REQUIRE_SIGNED_TARGET = &H00000080

DECLARE FUNCTION GetModuleFileNameA LIB "Kernel32.dll" _
    ALIAS "GetModuleFileNameA" (BYVAL hModule AS DWORD, _
    lpFileName AS ASCIIZ, BYVAL nSize AS DWORD) AS DWORD

DECLARE FUNCTION GetModuleFileNameW LIB "Kernel32.dll" _
    ALIAS "GetModuleFileNameW" (BYVAL hModule AS DWORD, _
    lpFileName AS WSTRINGZ, BYVAL nSize AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetModuleFileName LIB "Kernel32.dll" _
    ALIAS "GetModuleFileNameW" (BYVAL hModule AS DWORD, _
    lpFileName AS WSTRINGZ, BYVAL nSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetModuleFileName LIB "Kernel32.dll" _
    ALIAS "GetModuleFileNameA" (BYVAL hModule AS DWORD, _
    lpFileName AS ASCIIZ, BYVAL nSize AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetModuleHandleA LIB "Kernel32.dll" ALIAS "GetModuleHandleA" _
    (lpModuleName AS ASCIIZ) AS DWORD

DECLARE FUNCTION GetModuleHandleW LIB "Kernel32.dll" ALIAS "GetModuleHandleW" _
    (lpModuleName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetModuleHandle LIB "Kernel32.dll" ALIAS "GetModuleHandleW" _
    (lpModuleName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION GetModuleHandle LIB "Kernel32.dll" ALIAS "GetModuleHandleA" _
    (lpModuleName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

#IF NOT %DEF(%RC_INVOKED)
#IF %WIN32_WINNT > &H0500 OR %DEF(%WINBASE_DECLARE_GET_MODULE_HANDLE_EX) OR %ISOLATION_AWARE_ENABLED

%GET_MODULE_HANDLE_EX_FLAG_PIN                = &H00000001
%GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT = &H00000002
%GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS       = &H00000004

'DECLARE FUNCTION PGET_MODULE_HANDLE_EXA (BYVAL dwFlags AS DWORD, _
'    lpModuleName AS ASCIIZ, phModule AS DWORD) AS LONG
'
'DECLARE FUNCTION PGET_MODULE_HANDLE_EXW (BYVAL dwFlags AS DWORD, _
'    lpModuleName AS WSTRINGZ, phModule AS DWORD) AS LONG
'
'#IF %DEF(%UNICODE)
'MACRO PGET_MODULE_HANDLE_EX=PGET_MODULE_HANDLE_EXW
'#ELSE
'MACRO PGET_MODULE_HANDLE_EX=PGET_MODULE_HANDLE_EXA
'#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetModuleHandleExA LIB "Kernel32.dll" _
    ALIAS "GetModuleHandleExA" (BYVAL dwFlags AS DWORD, _
    lpModuleName AS ASCIIZ, _
    phModule     AS DWORD _    ' HMODULE
    ) AS LONG

DECLARE FUNCTION GetModuleHandleExW LIB "Kernel32.dll" _
    ALIAS "GetModuleHandleExW" (BYVAL dwFlags AS DWORD, _
    lpModuleName AS WSTRINGZ, _
    phModule     AS DWORD _    ' HMODULE
    ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetModuleHandleEx LIB "Kernel32.dll" _
    ALIAS "GetModuleHandleExW" (BYVAL dwFlags AS DWORD, _
    lpModuleName AS WSTRINGZ, _
    phModule     AS DWORD _    ' HMODULE
    ) AS LONG
#ELSE
DECLARE FUNCTION GetModuleHandleEx LIB "Kernel32.dll" _
    ALIAS "GetModuleHandleExA" (BYVAL dwFlags AS DWORD, _
    lpModuleName AS ASCIIZ, _
    phModule     AS DWORD _    ' HMODULE
    ) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF
#ENDIF

#IF %WIN32_WINNT >= &H0502

DECLARE FUNCTION NeedCurrentDirectoryForExePathA LIB "Kernel32.dll" _
    ALIAS "NeedCurrentDirectoryForExePathA" (sExeName AS ASCIIZ) AS LONG

DECLARE FUNCTION NeedCurrentDirectoryForExePathW LIB "Kernel32.dll" _
    ALIAS "NeedCurrentDirectoryForExePathW" (sExeName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION NeedCurrentDirectoryForExePath LIB "Kernel32.dll" _
    ALIAS "NeedCurrentDirectoryForExePathW" (sExeName AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION NeedCurrentDirectoryForExePath LIB "Kernel32.dll" _
    ALIAS "NeedCurrentDirectoryForExePathA" (sExeName AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' #IF %WIN32_WINNT >= &H0502

#IF %WIN32_WINNT >= &H0600

%PROCESS_NAME_NATIVE    = &H00000001

DECLARE FUNCTION QueryFullProcessImageNameA LIB "Kernel32.dll" _
    ALIAS "QueryFullProcessImageNameA" (BYVAL hProcess AS DWORD, _
    BYVAL dwFlags AS DWORD, lpExeName AS ASCIIZ, lpdwSize AS DWORD) AS LONG

DECLARE FUNCTION QueryFullProcessImageNameW LIB "Kernel32.dll" _
    ALIAS "QueryFullProcessImageNameW" (BYVAL hProcess AS DWORD, _
    BYVAL dwFlags AS DWORD, lpExeName AS WSTRINGZ, lpdwSize AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION QueryFullProcessImageName LIB "Kernel32.dll" _
    ALIAS "QueryFullProcessImageNameW" (BYVAL hProcess AS DWORD, _
    BYVAL dwFlags AS DWORD, lpExeName AS WSTRINGZ, lpdwSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION QueryFullProcessImageName LIB "Kernel32.dll" _
    ALIAS "QueryFullProcessImageNameA" (BYVAL hProcess AS DWORD, _
    BYVAL dwFlags AS DWORD, lpExeName AS ASCIIZ, lpdwSize AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' #IF %WIN32_WINNT >= &H0600

#IF (%WIN32_WINNT >= &H0600)

'
' Extended process and thread attribute support
'

%PROC_THREAD_ATTRIBUTE_NUMBER   = &H0000FFFF
%PROC_THREAD_ATTRIBUTE_THREAD   = &H00010000  ' Attribute may be used with thread creation
%PROC_THREAD_ATTRIBUTE_INPUT    = &H00020000  ' Attribute is input only
%PROC_THREAD_ATTRIBUTE_ADDITIVE = &H00040000  ' Attribute may be "accumulated," e.g. bitmasks, counters, etc.

MACRO PROC_THREAD_ATTRIBUTE_NUM_enum=LONG
ENUM PROC_THREAD_ATTRIBUTE_NUM SINGULAR
    ProcThreadAttributeParentProcess
    ProcThreadAttributeExtendedFlags
    ProcThreadAttributeHandleList
    ProcThreadAttributeGroupAffinity
    ProcThreadAttributePreferredNode
    ProcThreadAttributeIdealProcessor
    ProcThreadAttributeUmsThread
    ProcThreadAttributeMitigationPolicy
    ProcThreadAttributeMax
END ENUM

MACRO FUNCTION ProcThreadAttributeValue(Number, nThread, nInput, Additive)
    MACROTEMP d
    LOCAL d AS DWORD
    d = (((Number) AND %PROC_THREAD_ATTRIBUTE_NUMBER)    OR _
         IIF&(nThread, %PROC_THREAD_ATTRIBUTE_THREAD, 0) OR _
         IIF&(nInput, %PROC_THREAD_ATTRIBUTE_INPUT, 0)   OR _
         IIF&(Additive, %PROC_THREAD_ATTRIBUTE_ADDITIVE, 0))
END MACRO=d

MACRO PROC_THREAD_ATTRIBUTE_PARENT_PROCESS=ProcThreadAttributeValue(ProcThreadAttributeParentProcess, %FALSE, %TRUE, %FALSE)
MACRO PROC_THREAD_ATTRIBUTE_EXTENDED_FLAGS=ProcThreadAttributeValue(ProcThreadAttributeExtendedFlags, %FALSE, %TRUE, %TRUE)
MACRO PROC_THREAD_ATTRIBUTE_HANDLE_LIST=ProcThreadAttributeValue(ProcThreadAttributeHandleList, %FALSE, %TRUE, %FALSE)
MACRO PROC_THREAD_ATTRIBUTE_GROUP_AFFINITY=ProcThreadAttributeValue(ProcThreadAttributeGroupAffinity, %TRUE, %TRUE, %FALSE)
MACRO PROC_THREAD_ATTRIBUTE_PREFERRED_NODE=ProcThreadAttributeValue(ProcThreadAttributePreferredNode, %FALSE, %TRUE, %FALSE)
MACRO PROC_THREAD_ATTRIBUTE_IDEAL_PROCESSOR=ProcThreadAttributeValue(ProcThreadAttributeIdealProcessor, %TRUE, %TRUE, %FALSE)
MACRO PROC_THREAD_ATTRIBUTE_UMS_THREAD=ProcThreadAttributeValue(ProcThreadAttributeUmsThread, %TRUE, %TRUE, %FALSE)
MACRO PROC_THREAD_ATTRIBUTE_MITIGATION_POLICY=ProcThreadAttributeValue(ProcThreadAttributeMitigationPolicy, %FALSE, %TRUE, %FALSE)

%PROCESS_CREATION_MITIGATION_POLICY_DEP_ENABLE           = &H01
%PROCESS_CREATION_MITIGATION_POLICY_DEP_ATL_THUNK_ENABLE = &H02
%PROCESS_CREATION_MITIGATION_POLICY_SEHOP_ENABLE         = &H04

DECLARE FUNCTION InitializeProcThreadAttributeList LIB "Kernel32.dll" _
    ALIAS "InitializeProcThreadAttributeList" _
    (BYVAL lpAttributeList AS DWORD, BYVAL dwAttributeCount AS DWORD, _
    BYVAL dwFlags AS DWORD, lpSize AS DWORD) AS LONG

DECLARE SUB DeleteProcThreadAttributeList LIB "Kernel32.dll" _
    ALIAS "DeleteProcThreadAttributeList" (lpAttributeList AS DWORD)

%PROC_THREAD_ATTRIBUTE_REPLACE_VALUE    = &H00000001

DECLARE FUNCTION UpdateProcThreadAttribute LIB "Kernel32.dll" _
    ALIAS "UpdateProcThreadAttribute" (BYVAL lpAttributeList AS DWORD, _
    BYVAL dwFlags AS DWORD, BYVAL dAttribute AS DWORD, _
    BYVAL lpValue AS DWORD, BYVAL cbSize AS DWORD, _
    BYVAL lpPreviousValue AS DWORD, BYVAL lpReturnSize AS DWORD) AS LONG

#ENDIF  ' #IF (%WIN32_WINNT >= &H0600)

DECLARE FUNCTION CreateProcessA LIB "Kernel32.dll" ALIAS "CreateProcessA" _
    (lpApplicationName AS ASCIIZ, lpCommandLine AS ASCIIZ, _
    lpProcessAttributes AS SECURITY_ATTRIBUTES, _
    lpThreadAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL bInheritHandles AS LONG, BYVAL dwCreationFlags AS DWORD, _
    BYVAL lpEnvironment AS DWORD, lpCurrentDirectory AS ASCIIZ, _
    lpStartupInfo AS STARTUPINFOA, _
    lpProcessInformation AS PROCESS_INFORMATION) AS LONG

DECLARE FUNCTION CreateProcessW LIB "Kernel32.dll" ALIAS "CreateProcessW" _
    (lpApplicationName AS WSTRINGZ, lpCommandLine AS WSTRINGZ, _
    lpProcessAttributes AS SECURITY_ATTRIBUTES, _
    lpThreadAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL bInheritHandles AS LONG, BYVAL dwCreationFlags AS DWORD, _
    BYVAL lpEnvironment AS DWORD, lpCurrentDirectory AS WSTRINGZ, _
    lpStartupInfo AS STARTUPINFOW, _
    lpProcessInformation AS PROCESS_INFORMATION) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateProcess LIB "Kernel32.dll" ALIAS "CreateProcessW" _
    (lpApplicationName AS WSTRINGZ, lpCommandLine AS WSTRINGZ, _
    lpProcessAttributes AS SECURITY_ATTRIBUTES, _
    lpThreadAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL bInheritHandles AS LONG, BYVAL dwCreationFlags AS DWORD, _
    BYVAL lpEnvironment AS DWORD, lpCurrentDirectory AS WSTRINGZ, _
    lpStartupInfo AS STARTUPINFOW, _
    lpProcessInformation AS PROCESS_INFORMATION) AS LONG
#ELSE
DECLARE FUNCTION CreateProcess LIB "Kernel32.dll" ALIAS "CreateProcessA" _
    (lpApplicationName AS ASCIIZ, lpCommandLine AS ASCIIZ, _
    lpProcessAttributes AS SECURITY_ATTRIBUTES, _
    lpThreadAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL bInheritHandles AS LONG, BYVAL dwCreationFlags AS DWORD, _
    BYVAL lpEnvironment AS DWORD, lpCurrentDirectory AS ASCIIZ, _
    lpStartupInfo AS STARTUPINFOA, _
    lpProcessInformation AS PROCESS_INFORMATION) AS LONG
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION SetProcessShutdownParameters LIB "Kernel32.dll" _
    ALIAS "SetProcessShutdownParameters" (BYVAL dwLevel AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION GetProcessShutdownParameters LIB "Kernel32.dll" _
    ALIAS "GetProcessShutdownParameters" (lpdwLevel AS DWORD, _
    lpdwFlags AS DWORD) AS LONG

DECLARE FUNCTION GetProcessVersion LIB "Kernel32.dll" _
    ALIAS "GetProcessVersion" (BYVAL hProcess AS DWORD) AS DWORD

DECLARE SUB FatalAppExitA LIB "Kernel32.dll" ALIAS "FatalAppExitA" _
    (BYVAL uAction AS DWORD, lpMessageText AS ASCIIZ)

DECLARE SUB FatalAppExitW LIB "Kernel32.dll" ALIAS "FatalAppExitW" _
    (BYVAL uAction AS DWORD, lpMessageText AS WSTRINGZ)

#IF %DEF(%UNICODE)
DECLARE SUB FatalAppExit LIB "Kernel32.dll" ALIAS "FatalAppExitW" _
    (BYVAL uAction AS DWORD, lpMessageText AS WSTRINGZ)
#ELSE
DECLARE SUB FatalAppExit LIB "Kernel32.dll" ALIAS "FatalAppExitA" _
    (BYVAL uAction AS DWORD, lpMessageText AS ASCIIZ)
#ENDIF ' NOT %UNICODE

DECLARE SUB GetStartupInfoA LIB "Kernel32.dll" ALIAS "GetStartupInfoA" _
    (lpStartupInfo AS STARTUPINFOA)

DECLARE SUB GetStartupInfoW LIB "Kernel32.dll" ALIAS "GetStartupInfoW" _
    (lpStartupInfo AS STARTUPINFOW)

#IF %DEF(%UNICODE)
DECLARE SUB GetStartupInfo LIB "Kernel32.dll" ALIAS "GetStartupInfoW" _
    (lpStartupInfo AS STARTUPINFOW)
#ELSE
DECLARE SUB GetStartupInfo LIB "Kernel32.dll" ALIAS "GetStartupInfoA" _
    (lpStartupInfo AS STARTUPINFOA)
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetCommandLineA LIB "Kernel32.dll" ALIAS "GetCommandLineA" _
    () AS DWORD

DECLARE FUNCTION GetCommandLineW LIB "Kernel32.dll" ALIAS "GetCommandLineW" _
    () AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetCommandLine LIB "Kernel32.dll" ALIAS "GetCommandLineW" _
    () AS DWORD
#ELSE
DECLARE FUNCTION GetCommandLine LIB "Kernel32.dll" ALIAS "GetCommandLineA" _
    () AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetEnvironmentVariableA LIB "Kernel32.dll" _
    ALIAS "GetEnvironmentVariableA" (lpName AS ASCIIZ, lpBuffer AS ASCIIZ, _
    BYVAL nSize AS DWORD) AS DWORD

DECLARE FUNCTION GetEnvironmentVariableW LIB "Kernel32.dll" _
    ALIAS "GetEnvironmentVariableW" (lpName AS WSTRINGZ, _
    lpBuffer AS WSTRINGZ, BYVAL nSize AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetEnvironmentVariable LIB "Kernel32.dll" _
    ALIAS "GetEnvironmentVariableW" (lpName AS WSTRINGZ, lpBuffer AS WSTRINGZ, _
    BYVAL nSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetEnvironmentVariable LIB "Kernel32.dll" _
    ALIAS "GetEnvironmentVariableA" (lpName AS ASCIIZ, _
    lpBuffer AS ASCIIZ, BYVAL nSize AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetEnvironmentVariableA LIB "Kernel32.dll" _
    ALIAS "SetEnvironmentVariableA" (lpName AS ASCIIZ, lpValue AS ASCIIZ) _
    AS LONG

DECLARE FUNCTION SetEnvironmentVariableW LIB "Kernel32.dll" _
    ALIAS "SetEnvironmentVariableW" (lpName AS WSTRINGZ, lpValue AS WSTRINGZ) _
    AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetEnvironmentVariable LIB "Kernel32.dll" _
    ALIAS "SetEnvironmentVariableW" (lpName AS WSTRINGZ, lpValue AS WSTRINGZ) _
    AS LONG
#ELSE
DECLARE FUNCTION SetEnvironmentVariable LIB "Kernel32.dll" _
    ALIAS "SetEnvironmentVariableA" (lpName AS ASCIIZ, lpValue AS ASCIIZ) _
    AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION ExpandEnvironmentStringsA LIB "Kernel32.dll" _
    ALIAS "ExpandEnvironmentStringsA" (lpSrc AS ASCIIZ, lpDst AS ASCIIZ, _
    BYVAL nSize AS DWORD) AS DWORD

DECLARE FUNCTION ExpandEnvironmentStringsW LIB "Kernel32.dll" _
    ALIAS "ExpandEnvironmentStringsW" (lpSrc AS WSTRINGZ, lpDst AS WSTRINGZ, _
    BYVAL nSize AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION ExpandEnvironmentStrings LIB "Kernel32.dll" _
    ALIAS "ExpandEnvironmentStringsW" (lpSrc AS WSTRINGZ, lpDst AS WSTRINGZ, _
    BYVAL nSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION ExpandEnvironmentStrings LIB "Kernel32.dll" _
    ALIAS "ExpandEnvironmentStringsA" (lpSrc AS ASCIIZ, lpDst AS ASCIIZ, _
    BYVAL nSize AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetFirmwareEnvironmentVariableA LIB "Kernel32.dll" _
    ALIAS "GetFirmwareEnvironmentVariableA" (lpName AS ASCIIZ, _
    lpGuid AS ASCIIZ, BYVAL pBuffer AS DWORD, BYVAL nSize AS DWORD) AS DWORD

DECLARE FUNCTION GetFirmwareEnvironmentVariableW LIB "Kernel32.dll" _
    ALIAS "GetFirmwareEnvironmentVariableW" (lpName AS WSTRINGZ, _
    lpGuid AS WSTRINGZ, BYVAL pBuffer AS DWORD, BYVAL nSize AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetFirmwareEnvironmentVariable LIB "Kernel32.dll" _
    ALIAS "GetFirmwareEnvironmentVariableW" (lpName AS WSTRINGZ, _
    lpGuid AS WSTRINGZ, BYVAL pBuffer AS DWORD, BYVAL nSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetFirmwareEnvironmentVariable LIB "Kernel32.dll" _
    ALIAS "GetFirmwareEnvironmentVariableA" (lpName AS ASCIIZ, _
    lpGuid AS ASCIIZ, BYVAL pBuffer AS DWORD, BYVAL nSize AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetFirmwareEnvironmentVariableA LIB "Kernel32.dll" _
    ALIAS "SetFirmwareEnvironmentVariableA" (lpName AS ASCIIZ, _
    lpGuid AS ASCIIZ, BYVAL pBuffer AS DWORD, BYVAL nSize AS DWORD) AS LONG

DECLARE FUNCTION SetFirmwareEnvironmentVariableW LIB "Kernel32.dll" _
    ALIAS "SetFirmwareEnvironmentVariableW" (lpName AS WSTRINGZ, _
    lpGuid AS WSTRINGZ, BYVAL pBuffer AS DWORD, BYVAL nSize AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetFirmwareEnvironmentVariable LIB "Kernel32.dll" _
    ALIAS "SetFirmwareEnvironmentVariableW" (lpName AS WSTRINGZ, _
    lpGuid AS WSTRINGZ, BYVAL pBuffer AS DWORD, BYVAL nSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SetFirmwareEnvironmentVariable LIB "Kernel32.dll" _
    ALIAS "SetFirmwareEnvironmentVariableA" (lpName AS ASCIIZ, _
    lpGuid AS ASCIIZ, BYVAL pBuffer AS DWORD, BYVAL nSize AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE SUB OutputDebugStringA LIB "Kernel32.dll" ALIAS "OutputDebugStringA" _
    (lpOutputString AS ASCIIZ)

DECLARE SUB OutputDebugStringW LIB "Kernel32.dll" ALIAS "OutputDebugStringW" _
    (lpOutputString AS WSTRINGZ)

#IF %DEF(%UNICODE)
DECLARE SUB OutputDebugString LIB "Kernel32.dll" ALIAS "OutputDebugStringW" _
    (lpOutputString AS WSTRINGZ)
#ELSE
DECLARE SUB OutputDebugString LIB "Kernel32.dll" ALIAS "OutputDebugStringA" _
    (lpOutputString AS ASCIIZ)
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION FindResourceA LIB "Kernel32.dll" ALIAS "FindResourceA" _
    (BYVAL hInstance AS DWORD, lpName AS ASCIIZ, lpType AS ASCIIZ) AS LONG

DECLARE FUNCTION FindResourceW LIB "Kernel32.dll" ALIAS "FindResourceW" _
    (BYVAL hInstance AS DWORD, lpName AS WSTRINGZ, lpType AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION FindResource LIB "Kernel32.dll" ALIAS "FindResourceW" _
    (BYVAL hInstance AS DWORD, lpName AS WSTRINGZ, lpType AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION FindResource LIB "Kernel32.dll" ALIAS "FindResourceA" _
    (BYVAL hInstance AS DWORD, lpName AS ASCIIZ, lpType AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION FindResourceExA LIB "Kernel32.dll" ALIAS "FindResourceExA" _
    (BYVAL hModule AS DWORD, lpType AS ASCIIZ, lpName AS ASCIIZ, _
    BYVAL wLanguage AS WORD) AS DWORD

DECLARE FUNCTION FindResourceExW LIB "Kernel32.dll" ALIAS "FindResourceExW" _
    (BYVAL hModule AS DWORD, lpType AS WSTRINGZ, lpName AS WSTRINGZ, _
    BYVAL wLanguage AS WORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION FindResourceEx LIB "Kernel32.dll" ALIAS "FindResourceExW" _
    (BYVAL hModule AS DWORD, lpType AS WSTRINGZ, lpName AS WSTRINGZ, _
    BYVAL wLanguage AS WORD) AS DWORD
#ELSE
DECLARE FUNCTION FindResourceEx LIB "Kernel32.dll" ALIAS "FindResourceExA" _
    (BYVAL hModule AS DWORD, lpType AS ASCIIZ, lpName AS ASCIIZ, _
    BYVAL wLanguage AS WORD) AS DWORD
#ENDIF ' NOT %UNICODE

'DECLARE FUNCTION ENUMRESTYPEPROCA (BYVAL hModule AS DWORD, _
'    lpType AS ASCIIZ, lParam AS LONG) AS LONG
'
'DECLARE FUNCTION ENUMRESTYPEPROCW (BYVAL hModule AS DWORD, _
'    lpType AS WSTRINGZ, lParam AS LONG) AS LONG
'
'#IF %DEF(%UNICODE)
'MACRO ENUMRESTYPEPROC=ENUMRESTYPEPROCW
'#ELSE
'MACRO ENUMRESTYPEPROC=ENUMRESTYPEPROCA
'#ENDIF ' NOT %UNICODE
'
'DECLARE FUNCTION ENUMRESNAMEPROCA (BYVAL hModule AS DWORD, _
'    lpType AS ASCIIZ, lpName AS ASCIIZ, BYVAL lparam AS LONG) AS LONG
'
'DECLARE FUNCTION ENUMRESNAMEPROCW (BYVAL hModule AS DWORD, _
'    lpType AS WSTRINGZ, lpName AS WSTRINGZ, BYVAL lparam AS LONG) AS LONG
'
'#IF %DEF(%UNICODE)
'MACRO ENUMRESNAMEPROC=ENUMRESNAMEPROCW
'#ELSE
'MACRO ENUMRESNAMEPROC=ENUMRESNAMEPROCA
'#ENDIF ' NOT %UNICODE
'
'DECLARE FUNCTION ENUMRESLANGPROCA (BYVAL hModule AS DWORD, lpType AS ASCIIZ, _
'    lpName AS ASCIIZ, BYVAL wLanguage AS WORD, BYVAL lparam AS LONG) AS LONG
'
'DECLARE FUNCTION ENUMRESLANGPROCW (BYVAL hModule AS DWORD, _
'    lpType AS WSTRINGZ, _
'    lpName AS WSTRINGZ, BYVAL wLanguage AS WORD, BYVAL lparam AS LONG) AS LONG
'
'#IF %DEF(%UNICODE)
'MACRO ENUMRESLANGPROC=ENUMRESLANGPROCW
'#ELSE
'MACRO ENUMRESLANGPROC=ENUMRESLANGPROCA
'#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumResourceTypesA LIB "Kernel32.dll" _
    ALIAS "EnumResourceTypesA" (BYVAL hModule AS DWORD, _
    BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION EnumResourceTypesW LIB "Kernel32.dll" _
    ALIAS "EnumResourceTypesW" (BYVAL hModule AS DWORD, _
    BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION EnumResourceTypes LIB "Kernel32.dll" _
    ALIAS "EnumResourceTypesW" (BYVAL hModule AS DWORD, _
    BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG) AS LONG
#ELSE
DECLARE FUNCTION EnumResourceTypes LIB "Kernel32.dll" _
    ALIAS "EnumResourceTypesA" (BYVAL hModule AS DWORD, _
    BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumResourceNamesA LIB "Kernel32.dll" _
    ALIAS "EnumResourceNamesA" (BYVAL hModule AS DWORD, lpType AS ASCIIZ, _
    BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION EnumResourceNamesW LIB "Kernel32.dll" _
    ALIAS "EnumResourceNamesW" (BYVAL hModule AS DWORD, lpType AS WSTRINGZ, _
    BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION EnumResourceNames LIB "Kernel32.dll" _
    ALIAS "EnumResourceNamesW" (BYVAL hModule AS DWORD, lpType AS WSTRINGZ, _
    BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG) AS LONG
#ELSE
DECLARE FUNCTION EnumResourceNames LIB "Kernel32.dll" _
    ALIAS "EnumResourceNamesA" (BYVAL hModule AS DWORD, lpType AS ASCIIZ, _
    BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumResourceLanguagesA LIB "Kernel32.dll" _
    ALIAS "EnumResourceLanguagesA" (BYVAL hModule AS DWORD, _
    lpType AS ASCIIZ, lpName AS ASCIIZ, BYVAL lpEnumFunc AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION EnumResourceLanguagesW LIB "Kernel32.dll" _
    ALIAS "EnumResourceLanguagesW" (BYVAL hModule AS DWORD, _
    lpType AS WSTRINGZ, lpName AS WSTRINGZ, BYVAL lpEnumFunc AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION EnumResourceLanguages LIB "Kernel32.dll" _
    ALIAS "EnumResourceLanguagesW" (BYVAL hModule AS DWORD, _
    lpType AS WSTRINGZ, lpName AS WSTRINGZ, BYVAL lpEnumFunc AS DWORD, _
    BYVAL lParam AS LONG) AS LONG
#ELSE
DECLARE FUNCTION EnumResourceLanguages LIB "Kernel32.dll" _
    ALIAS "EnumResourceLanguagesA" (BYVAL hModule AS DWORD, _
    lpType AS ASCIIZ, lpName AS ASCIIZ, BYVAL lpEnumFunc AS DWORD, _
    BYVAL lParam AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

%RESOURCE_ENUM_LN             = &H0001
%RESOURCE_ENUM_MUI            = &H0002
%RESOURCE_ENUM_MUI_SYSTEM     = &H0004
%RESOURCE_ENUM_VALIDATE       = &H0008
%RESOURCE_ENUM_MODULE_EXACT   = &H0010
'%RESOURCE_UPDATE_LN           = &H0010
'%RESOURCE_UPDATE_MUI          = &H0020

DECLARE FUNCTION EnumResourceTypesExA LIB "Kernel32.dll" _
    ALIAS "EnumResourceTypesExA" (BYVAL hModule AS DWORD, _
    BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG, BYVAL dwFlags AS DWORD, _
    BYVAL LangId AS WORD) AS LONG

DECLARE FUNCTION EnumResourceTypesExW LIB "Kernel32.dll" _
    ALIAS "EnumResourceTypesExW" (BYVAL hModule AS DWORD, _
    BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG, BYVAL dwFlags AS DWORD, _
    BYVAL LangId AS WORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION EnumResourceTypesEx LIB "Kernel32.dll" _
    ALIAS "EnumResourceTypesExW" (BYVAL hModule AS DWORD, _
    BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG, BYVAL dwFlags AS DWORD, _
    BYVAL LangId AS WORD) AS LONG
#ELSE
DECLARE FUNCTION EnumResourceTypesEx LIB "Kernel32.dll" _
    ALIAS "EnumResourceTypesExA" (BYVAL hModule AS DWORD, _
    BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG, BYVAL dwFlags AS DWORD, _
    BYVAL LangId AS WORD) AS LONG
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION EnumResourceNamesExA LIB "Kernel32.dll" _
    ALIAS "EnumResourceNamesExA" (BYVAL hModule AS DWORD, lpType AS ASCIIZ, _
    BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG, BYVAL dwFlags AS DWORD, _
    BYVAL LangId AS WORD) AS LONG

DECLARE FUNCTION EnumResourceNamesExW LIB "Kernel32.dll" _
    ALIAS "EnumResourceNamesExW" (BYVAL hModule AS DWORD, lpType AS WSTRINGZ, _
    BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG, BYVAL dwFlags AS DWORD, _
    BYVAL LangId AS WORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION EnumResourceNamesEx LIB "Kernel32.dll" _
    ALIAS "EnumResourceNamesExW" (BYVAL hModule AS DWORD, lpType AS WSTRINGZ, _
    BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG, BYVAL dwFlags AS DWORD, _
    BYVAL LangId AS WORD) AS LONG
#ELSE
DECLARE FUNCTION EnumResourceNamesEx LIB "Kernel32.dll" _
    ALIAS "EnumResourceNamesExA" (BYVAL hModule AS DWORD, lpType AS ASCIIZ, _
    BYVAL lpEnumFunc AS DWORD, BYVAL lParam AS LONG, BYVAL dwFlags AS DWORD, _
    BYVAL LangId AS WORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumResourceLanguagesExA LIB "Kernel32.dll" _
    ALIAS "EnumResourceLanguagesExA" (BYVAL hModule AS DWORD, _
    lpType AS ASCIIZ, lpName AS ASCIIZ, BYVAL lpEnumFunc AS DWORD, _
    BYVAL lParam AS LONG, BYVAL dwFlags AS DWORD, BYVAL LangId AS WORD) AS LONG

DECLARE FUNCTION EnumResourceLanguagesExW LIB "Kernel32.dll" _
    ALIAS "EnumResourceLanguagesExW" (BYVAL hModule AS DWORD, _
    lpType AS WSTRINGZ, lpName AS WSTRINGZ, BYVAL lpEnumFunc AS DWORD, _
    BYVAL lParam AS LONG, BYVAL dwFlags AS DWORD, BYVAL LangId AS WORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION EnumResourceLanguagesEx LIB "Kernel32.dll" _
    ALIAS "EnumResourceLanguagesExW" (BYVAL hModule AS DWORD, _
    lpType AS WSTRINGZ, lpName AS WSTRINGZ, BYVAL lpEnumFunc AS DWORD, _
    BYVAL lParam AS LONG, BYVAL dwFlags AS DWORD, BYVAL LangId AS WORD) AS LONG
#ELSE
DECLARE FUNCTION EnumResourceLanguagesEx LIB "Kernel32.dll" _
    ALIAS "EnumResourceLanguagesExA" (BYVAL hModule AS DWORD, _
    lpType AS ASCIIZ, lpName AS ASCIIZ, BYVAL lpEnumFunc AS DWORD, _
    BYVAL lParam AS LONG, BYVAL dwFlags AS DWORD, BYVAL LangId AS WORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION BeginUpdateResourceA LIB "Kernel32.dll" _
    ALIAS "BeginUpdateResourceA" (pFileName AS ASCIIZ, _
    BYVAL bDeleteExistingResources AS LONG) AS DWORD

DECLARE FUNCTION BeginUpdateResourceW LIB "Kernel32.dll" _
    ALIAS "BeginUpdateResourceW" (pFileName AS WSTRINGZ, _
    BYVAL bDeleteExistingResources AS LONG) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION BeginUpdateResource LIB "Kernel32.dll" _
    ALIAS "BeginUpdateResourceW" (pFileName AS WSTRINGZ, _
    BYVAL bDeleteExistingResources AS LONG) AS DWORD
#ELSE
DECLARE FUNCTION BeginUpdateResource LIB "Kernel32.dll" _
    ALIAS "BeginUpdateResourceA" (pFileName AS ASCIIZ, _
    BYVAL bDeleteExistingResources AS LONG) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION UpdateResourceA LIB "Kernel32.dll" ALIAS "UpdateResourceA" _
    (BYVAL hUpdate AS DWORD, lpType AS ASCIIZ, lpName AS ASCIIZ, _
    BYVAL wLanguage AS WORD, BYVAL lpData AS DWORD, BYVAL cbData AS DWORD) _
    AS LONG

DECLARE FUNCTION UpdateResourceW LIB "Kernel32.dll" ALIAS "UpdateResourceW" _
    (BYVAL hUpdate AS DWORD, lpType AS WSTRINGZ, lpName AS WSTRINGZ, _
    BYVAL wLanguage AS WORD, BYVAL lpData AS DWORD, BYVAL cbData AS DWORD) _
    AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION UpdateResource LIB "Kernel32.dll" ALIAS "UpdateResourceW" _
    (BYVAL hUpdate AS DWORD, lpType AS WSTRINGZ, lpName AS WSTRINGZ, _
    BYVAL wLanguage AS WORD, BYVAL lpData AS DWORD, BYVAL cbData AS DWORD) _
    AS LONG
#ELSE
DECLARE FUNCTION UpdateResource LIB "Kernel32.dll" ALIAS "UpdateResourceA" _
    (BYVAL hUpdate AS DWORD, lpType AS ASCIIZ, lpName AS ASCIIZ, _
    BYVAL wLanguage AS WORD, BYVAL lpData AS DWORD, BYVAL cbData AS DWORD) _
    AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EndUpdateResourceA LIB "Kernel32.dll" _
    ALIAS "EndUpdateResourceA" (BYVAL hUpdate AS DWORD, _
    BYVAL fDiscard AS LONG) AS LONG

DECLARE FUNCTION EndUpdateResourceW LIB "Kernel32.dll" _
    ALIAS "EndUpdateResourceW" (BYVAL hUpdate AS DWORD, _
    BYVAL fDiscard AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION EndUpdateResource LIB "Kernel32.dll" _
    ALIAS "EndUpdateResourceW" (BYVAL hUpdate AS DWORD, _
    BYVAL fDiscard AS LONG) AS LONG
#ELSE
DECLARE FUNCTION EndUpdateResource LIB "Kernel32.dll" _
    ALIAS "EndUpdateResourceA" (BYVAL hUpdate AS DWORD, _
    BYVAL fDiscard AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GlobalAddAtomA LIB "Kernel32.dll" ALIAS "GlobalAddAtomA" _
    (lpString AS ASCIIZ) AS WORD

DECLARE FUNCTION GlobalAddAtomW LIB "Kernel32.dll" ALIAS "GlobalAddAtomW" _
    (lpString AS WSTRINGZ) AS WORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GlobalAddAtom LIB "Kernel32.dll" ALIAS "GlobalAddAtomW" _
    (lpString AS WSTRINGZ) AS WORD
#ELSE
DECLARE FUNCTION GlobalAddAtom LIB "Kernel32.dll" ALIAS "GlobalAddAtomA" _
    (lpString AS ASCIIZ) AS WORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GlobalFindAtomA LIB "Kernel32.dll" ALIAS "GlobalFindAtomA" _
    (lpString AS ASCIIZ) AS WORD

DECLARE FUNCTION GlobalFindAtomW LIB "Kernel32.dll" ALIAS "GlobalFindAtomW" _
    (lpString AS WSTRINGZ) AS WORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GlobalFindAtom LIB "Kernel32.dll" ALIAS "GlobalFindAtomW" _
    (lpString AS WSTRINGZ) AS WORD
#ELSE
DECLARE FUNCTION GlobalFindAtom LIB "Kernel32.dll" ALIAS "GlobalFindAtomA" _
    (lpString AS ASCIIZ) AS WORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GlobalGetAtomNameA LIB "Kernel32.dll" _
    ALIAS "GlobalGetAtomNameA" (BYVAL nAtom AS WORD, lpBuffer AS ASCIIZ, _
    BYVAL nSize AS DWORD) AS DWORD

DECLARE FUNCTION GlobalGetAtomNameW LIB "Kernel32.dll" _
    ALIAS "GlobalGetAtomNameW" (BYVAL nAtom AS WORD, lpBuffer AS WSTRINGZ, _
    BYVAL nSize AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GlobalGetAtomName LIB "Kernel32.dll" _
    ALIAS "GlobalGetAtomNameW" (BYVAL nAtom AS WORD, lpBuffer AS WSTRINGZ, _
    BYVAL nSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GlobalGetAtomName LIB "Kernel32.dll" _
    ALIAS "GlobalGetAtomNameA" (BYVAL nAtom AS WORD, lpBuffer AS ASCIIZ, _
    BYVAL nSize AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION AddAtomA LIB "Kernel32.dll" ALIAS "AddAtomA" _
    (lpString AS ASCIIZ) AS WORD

DECLARE FUNCTION AddAtomW LIB "Kernel32.dll" ALIAS "AddAtomW" _
    (lpString AS WSTRINGZ) AS WORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION AddAtom LIB "Kernel32.dll" ALIAS "AddAtomW" _
    (lpString AS WSTRINGZ) AS WORD
#ELSE
DECLARE FUNCTION AddAtom LIB "Kernel32.dll" ALIAS "AddAtomA" _
    (lpString AS ASCIIZ) AS WORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION FindAtomA LIB "Kernel32.dll" ALIAS "FindAtomA" _
    (lpString AS ASCIIZ) AS WORD

DECLARE FUNCTION FindAtomW LIB "Kernel32.dll" ALIAS "FindAtomW" _
    (lpString AS WSTRINGZ) AS WORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION FindAtom LIB "Kernel32.dll" ALIAS "FindAtomW" _
    (lpString AS WSTRINGZ) AS WORD
#ELSE
DECLARE FUNCTION FindAtom LIB "Kernel32.dll" ALIAS "FindAtomA" _
    (lpString AS ASCIIZ) AS WORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetAtomNameA LIB "Kernel32.dll" ALIAS "GetAtomNameA" _
    (BYVAL nAtom AS WORD, lpBuffer AS ASCIIZ, BYVAL nSize AS DWORD) AS DWORD

DECLARE FUNCTION GetAtomNameW LIB "Kernel32.dll" ALIAS "GetAtomNameW" _
    (BYVAL nAtom AS WORD, lpBuffer AS WSTRINGZ, BYVAL nSize AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetAtomName LIB "Kernel32.dll" ALIAS "GetAtomNameW" _
    (BYVAL nAtom AS WORD, lpBuffer AS WSTRINGZ, BYVAL nSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetAtomName LIB "Kernel32.dll" ALIAS "GetAtomNameA" _
    (BYVAL nAtom AS WORD, lpBuffer AS ASCIIZ, BYVAL nSize AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetProfileIntA LIB "Kernel32.dll" ALIAS "GetProfileIntA" _
    (lpAppName AS ASCIIZ, lpKeyName AS ASCIIZ, BYVAL nDefault AS LONG) _
    AS DWORD

DECLARE FUNCTION GetProfileIntW LIB "Kernel32.dll" ALIAS "GetProfileIntW" _
    (lpAppName AS WSTRINGZ, lpKeyName AS WSTRINGZ, BYVAL nDefault AS LONG) _
    AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetProfileInt LIB "Kernel32.dll" ALIAS "GetProfileIntW" _
    (lpAppName AS WSTRINGZ, lpKeyName AS WSTRINGZ, BYVAL nDefault AS LONG) _
    AS DWORD
#ELSE
DECLARE FUNCTION GetProfileInt LIB "Kernel32.dll" ALIAS "GetProfileIntA" _
    (lpAppName AS ASCIIZ, lpKeyName AS ASCIIZ, BYVAL nDefault AS LONG) _
    AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetProfileStringA LIB "Kernel32.dll" _
    ALIAS "GetProfileStringA" (lpAppName AS ASCIIZ, lpKeyName AS ASCIIZ, _
    lpDefault AS ASCIIZ, lpReturnedString AS ASCIIZ, BYVAL nSize AS DWORD) _
    AS DWORD

DECLARE FUNCTION GetProfileStringW LIB "Kernel32.dll" _
    ALIAS "GetProfileStringW" (lpAppName AS WSTRINGZ, lpKeyName AS WSTRINGZ, _
    lpDefault AS WSTRINGZ, lpReturnedString AS WSTRINGZ, _
    BYVAL nSize AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetProfileString LIB "Kernel32.dll" _
    ALIAS "GetProfileStringW" (lpAppName AS WSTRINGZ, lpKeyName AS WSTRINGZ, _
    lpDefault AS WSTRINGZ, lpReturnedString AS WSTRINGZ, _
    BYVAL nSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetProfileString LIB "Kernel32.dll" _
    ALIAS "GetProfileStringA" (lpAppName AS ASCIIZ, lpKeyName AS ASCIIZ, _
    lpDefault AS ASCIIZ, lpReturnedString AS ASCIIZ, BYVAL nSize AS DWORD) _
    AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION WriteProfileStringA LIB "Kernel32.dll" _
    ALIAS "WriteProfileStringA" (lpszSection AS ASCIIZ, _
    lpszKeyName AS ASCIIZ, lpszString AS ASCIIZ) AS LONG

DECLARE FUNCTION WriteProfileStringW LIB "Kernel32.dll" _
    ALIAS "WriteProfileStringW" (lpszSection AS WSTRINGZ, _
    lpszKeyName AS WSTRINGZ, lpszString AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION WriteProfileString LIB "Kernel32.dll" _
    ALIAS "WriteProfileStringW" (lpszSection AS WSTRINGZ, _
    lpszKeyName AS WSTRINGZ, lpszString AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION WriteProfileString LIB "Kernel32.dll" _
    ALIAS "WriteProfileStringA" (lpszSection AS ASCIIZ, _
    lpszKeyName AS ASCIIZ, lpszString AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetProfileSectionA LIB "Kernel32.dll" _
    ALIAS "GetProfileSectionA" (lpAppName AS ASCIIZ, _
    lpReturnedString AS ASCIIZ, BYVAL nSize AS DWORD) AS DWORD

DECLARE FUNCTION GetProfileSectionW LIB "Kernel32.dll" _
    ALIAS "GetProfileSectionW" (lpAppName AS WSTRINGZ, _
    lpReturnedString AS WSTRINGZ, BYVAL nSize AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetProfileSection LIB "Kernel32.dll" _
    ALIAS "GetProfileSectionW" (lpAppName AS WSTRINGZ, _
    lpReturnedString AS WSTRINGZ, BYVAL nSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetProfileSection LIB "Kernel32.dll" _
    ALIAS "GetProfileSectionA" (lpAppName AS ASCIIZ, _
    lpReturnedString AS ASCIIZ, BYVAL nSize AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION WriteProfileSectionA LIB "Kernel32.dll" _
    ALIAS "WriteProfileSectionA" (lpAppName AS ASCIIZ, lpString AS ASCIIZ) _
    AS LONG

DECLARE FUNCTION WriteProfileSectionW LIB "Kernel32.dll" _
    ALIAS "WriteProfileSectionW" (lpAppName AS WSTRINGZ, _
    lpString AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION WriteProfileSection LIB "Kernel32.dll" _
    ALIAS "WriteProfileSectionW" (lpAppName AS WSTRINGZ, _
    lpString AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION WriteProfileSection LIB "Kernel32.dll" _
    ALIAS "WriteProfileSectionA" (lpAppName AS ASCIIZ, lpString AS ASCIIZ) _
    AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetPrivateProfileIntA LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileIntA" (lpApplicationName AS ASCIIZ, _
    lpKeyName AS ASCIIZ, BYVAL nDefault AS LONG, lpFileName AS ASCIIZ) _
    AS DWORD

DECLARE FUNCTION GetPrivateProfileIntW LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileIntW" (lpApplicationName AS WSTRINGZ, _
    lpKeyName AS WSTRINGZ, BYVAL nDefault AS LONG, lpFileName AS WSTRINGZ) _
    AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetPrivateProfileInt LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileIntW" (lpApplicationName AS WSTRINGZ, _
    lpKeyName AS WSTRINGZ, BYVAL nDefault AS LONG, lpFileName AS WSTRINGZ) _
    AS DWORD
#ELSE
DECLARE FUNCTION GetPrivateProfileInt LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileIntA" (lpApplicationName AS ASCIIZ, _
    lpKeyName AS ASCIIZ, BYVAL nDefault AS LONG, lpFileName AS ASCIIZ) _
    AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetPrivateProfileStringA LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileStringA" (lpApplicationName AS ASCIIZ, _
    lpKeyName AS ASCIIZ, lpDefault AS ASCIIZ, _
    lpReturnedString AS ASCIIZ, BYVAL nSize AS DWORD, _
    lpFileName AS ASCIIZ) AS DWORD

DECLARE FUNCTION GetPrivateProfileStringW LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileStringW" (lpApplicationName AS WSTRINGZ, _
    lpKeyName AS WSTRINGZ, lpDefault AS WSTRINGZ, _
    lpReturnedString AS WSTRINGZ, BYVAL nSize AS DWORD, _
    lpFileName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetPrivateProfileString LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileStringW" (lpApplicationName AS WSTRINGZ, _
    lpKeyName AS WSTRINGZ, lpDefault AS WSTRINGZ, _
    lpReturnedString AS WSTRINGZ, BYVAL nSize AS DWORD, _
    lpFileName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION GetPrivateProfileString LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileStringA" (lpApplicationName AS ASCIIZ, _
    lpKeyName AS ASCIIZ, lpDefault AS ASCIIZ, _
    lpReturnedString AS ASCIIZ, BYVAL nSize AS DWORD, _
    lpFileName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION WritePrivateProfileStringA LIB "Kernel32.dll" _
    ALIAS "WritePrivateProfileStringA" (lpApplicationName AS ASCIIZ, _
    lpKeyName AS ASCIIZ, lpString AS ASCIIZ, lpFileName AS ASCIIZ) AS LONG

DECLARE FUNCTION WritePrivateProfileStringW LIB "Kernel32.dll" _
    ALIAS "WritePrivateProfileStringW" (lpApplicationName AS WSTRINGZ, _
    lpKeyName AS WSTRINGZ, lpString AS WSTRINGZ, lpFileName AS WSTRINGZ) _
    AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION WritePrivateProfileString LIB "Kernel32.dll" _
    ALIAS "WritePrivateProfileStringW" (lpApplicationName AS WSTRINGZ, _
    lpKeyName AS WSTRINGZ, lpString AS WSTRINGZ, lpFileName AS WSTRINGZ) _
    AS LONG
#ELSE
DECLARE FUNCTION WritePrivateProfileString LIB "Kernel32.dll" _
    ALIAS "WritePrivateProfileStringA" (lpApplicationName AS ASCIIZ, _
    lpKeyName AS ASCIIZ, lpString AS ASCIIZ, lpFileName AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetPrivateProfileSectionA LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileSectionA" (lpAppName AS ASCIIZ, _
    lpReturnedString AS ASCIIZ, BYVAL nSize AS DWORD, _
    lpFileName AS ASCIIZ) AS DWORD

DECLARE FUNCTION GetPrivateProfileSectionW LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileSectionW" (lpAppName AS WSTRINGZ, _
    lpReturnedString AS WSTRINGZ, BYVAL nSize AS DWORD, _
    lpFileName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetPrivateProfileSection LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileSectionW" (lpAppName AS WSTRINGZ, _
    lpReturnedString AS WSTRINGZ, BYVAL nSize AS DWORD, _
    lpFileName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION GetPrivateProfileSection LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileSectionA" (lpAppName AS ASCIIZ, _
    lpReturnedString AS ASCIIZ, BYVAL nSize AS DWORD, _
    lpFileName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION WritePrivateProfileSectionA LIB "Kernel32.dll" _
    ALIAS "WritePrivateProfileSectionA" (lpAppName AS ASCIIZ, _
    lpString AS ASCIIZ, lpFileName AS ASCIIZ) AS LONG

DECLARE FUNCTION WritePrivateProfileSectionW LIB "Kernel32.dll" _
    ALIAS "WritePrivateProfileSectionW" (lpAppName AS WSTRINGZ, _
    lpString AS WSTRINGZ, lpFileName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION WritePrivateProfileSection LIB "Kernel32.dll" _
    ALIAS "WritePrivateProfileSectionW" (lpAppName AS WSTRINGZ, _
    lpString AS WSTRINGZ, lpFileName AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION WritePrivateProfileSection LIB "Kernel32.dll" _
    ALIAS "WritePrivateProfileSectionA" (lpAppName AS ASCIIZ, _
    lpString AS ASCIIZ, lpFileName AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION GetPrivateProfileSectionNamesA LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileSectionNamesA" (lpszReturnBuffer AS ASCIIZ, _
    BYVAL nSize AS DWORD, lpFileName AS ASCIIZ) AS DWORD

DECLARE FUNCTION GetPrivateProfileSectionNamesW LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileSectionNamesW" (lpszReturnBuffer AS WSTRINGZ, _
    BYVAL nSize AS DWORD, lpFileName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetPrivateProfileSectionNames LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileSectionNamesW" (lpszReturnBuffer AS WSTRINGZ, _
    BYVAL nSize AS DWORD, lpFileName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION GetPrivateProfileSectionNames LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileSectionNamesA" (lpszReturnBuffer AS ASCIIZ, _
    BYVAL nSize AS DWORD, lpFileName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetPrivateProfileStructA LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileStructA" (lpApplicationName AS ASCIIZ, _
    lpKeyName AS ASCIIZ, BYVAL lpStruct AS DWORD, BYVAL nSize AS DWORD, _
    lpFileName AS ASCIIZ) AS DWORD

DECLARE FUNCTION GetPrivateProfileStructW LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileStructW" (lpApplicationName AS WSTRINGZ, _
    lpKeyName AS WSTRINGZ, BYVAL lpStruct AS DWORD, BYVAL nSize AS DWORD, _
    lpFileName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetPrivateProfileStruct LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileStructW" (lpApplicationName AS WSTRINGZ, _
    lpKeyName AS WSTRINGZ, BYVAL lpStruct AS DWORD, BYVAL nSize AS DWORD, _
    lpFileName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION GetPrivateProfileStruct LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileStructA" (lpApplicationName AS ASCIIZ, _
    lpKeyName AS ASCIIZ, BYVAL lpStruct AS DWORD, BYVAL nSize AS DWORD, _
    lpFileName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION WritePrivateProfileStructA LIB "Kernel32.dll" _
    ALIAS "WritePrivateProfileStructA" (lpApplicationName AS ASCIIZ, _
    lpKeyName AS ASCIIZ, BYVAL lpStruct AS DWORD, _
    BYVAL uSizeStruct AS DWORD, lpFileName AS ASCIIZ) AS LONG

DECLARE FUNCTION WritePrivateProfileStructW LIB "Kernel32.dll" _
    ALIAS "WritePrivateProfileStructW" (lpApplicationName AS WSTRINGZ, _
    lpKeyName AS WSTRINGZ, BYVAL lpStruct AS DWORD, _
    BYVAL uSizeStruct AS DWORD, lpFileName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION WritePrivateProfileStruct LIB "Kernel32.dll" _
    ALIAS "WritePrivateProfileStructW" (lpApplicationName AS WSTRINGZ, _
    lpKeyName AS WSTRINGZ, BYVAL lpStruct AS DWORD, _
    BYVAL uSizeStruct AS DWORD, lpFileName AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION WritePrivateProfileStruct LIB "Kernel32.dll" _
    ALIAS "WritePrivateProfileStructA" (lpApplicationName AS ASCIIZ, _
    lpKeyName AS ASCIIZ, BYVAL lpStruct AS DWORD, _
    BYVAL uSizeStruct AS DWORD, lpFileName AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION GetDriveTypeA LIB "Kernel32.dll" ALIAS "GetDriveTypeA" _
    (nDrive AS ASCIIZ) AS DWORD

DECLARE FUNCTION GetDriveTypeW LIB "Kernel32.dll" ALIAS "GetDriveTypeW" _
    (nDrive AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetDriveType LIB "Kernel32.dll" ALIAS "GetDriveTypeW" _
    (nDrive AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION GetDriveType LIB "Kernel32.dll" ALIAS "GetDriveTypeA" _
    (nDrive AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetSystemDirectoryA LIB "Kernel32.dll" _
    ALIAS "GetSystemDirectoryA" (lpBuffer AS ASCIIZ, BYVAL nSize AS DWORD) _
    AS DWORD

DECLARE FUNCTION GetSystemDirectoryW LIB "Kernel32.dll" _
    ALIAS "GetSystemDirectoryW" (lpBuffer AS WSTRINGZ, BYVAL nSize AS DWORD) _
    AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetSystemDirectory LIB "Kernel32.dll" _
    ALIAS "GetSystemDirectoryW" (lpBuffer AS WSTRINGZ, BYVAL nSize AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION GetSystemDirectory LIB "Kernel32.dll" _
    ALIAS "GetSystemDirectoryA" (lpBuffer AS ASCIIZ, BYVAL nSize AS DWORD) _
    AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetTempPathA LIB "Kernel32.dll" ALIAS "GetTempPathA" _
    (BYVAL nBufferLength AS DWORD, lpBuffer AS ASCIIZ) AS DWORD

DECLARE FUNCTION GetTempPathW LIB "Kernel32.dll" ALIAS "GetTempPathW" _
    (BYVAL nBufferLength AS DWORD, lpBuffer AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetTempPath LIB "Kernel32.dll" ALIAS "GetTempPathW" _
    (BYVAL nBufferLength AS DWORD, lpBuffer AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION GetTempPath LIB "Kernel32.dll" ALIAS "GetTempPathA" _
    (BYVAL nBufferLength AS DWORD, lpBuffer AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetTempFileNameA LIB "Kernel32.dll" _
    ALIAS "GetTempFileNameA" (lpszPath AS ASCIIZ, _
    lpPrefixString AS ASCIIZ, BYVAL dwUnique AS DWORD, _
    lpTempFileName AS ASCIIZ) AS DWORD

DECLARE FUNCTION GetTempFileNameW LIB "Kernel32.dll" _
    ALIAS "GetTempFileNameW" (lpszPath AS WSTRINGZ, _
    lpPrefixString AS WSTRINGZ, BYVAL dwUnique AS DWORD, _
    lpTempFileName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetTempFileName LIB "Kernel32.dll" _
    ALIAS "GetTempFileNameW" (lpszPath AS WSTRINGZ, _
    lpPrefixString AS WSTRINGZ, BYVAL dwUnique AS DWORD, _
    lpTempFileName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION GetTempFileName LIB "Kernel32.dll" _
    ALIAS "GetTempFileNameA" (lpszPath AS ASCIIZ, _
    lpPrefixString AS ASCIIZ, BYVAL dwUnique AS DWORD, _
    lpTempFileName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetWindowsDirectoryA LIB "Kernel32.dll" _
    ALIAS "GetWindowsDirectoryA" (lpBuffer AS ASCIIZ, BYVAL nSize AS DWORD) _
    AS DWORD

DECLARE FUNCTION GetWindowsDirectoryW LIB "Kernel32.dll" _
    ALIAS "GetWindowsDirectoryW" (lpBuffer AS WSTRINGZ, BYVAL nSize AS DWORD) _
    AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetWindowsDirectory LIB "Kernel32.dll" _
    ALIAS "GetWindowsDirectoryW" (lpBuffer AS WSTRINGZ, BYVAL nSize AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION GetWindowsDirectory LIB "Kernel32.dll" _
    ALIAS "GetWindowsDirectoryA" (lpBuffer AS ASCIIZ, BYVAL nSize AS DWORD) _
    AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetSystemWindowsDirectoryA LIB "Kernel32.dll" _
    ALIAS "GetSystemWindowsDirectoryA" (lpBuffer AS ASCIIZ, _
    BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION GetSystemWindowsDirectoryW LIB "Kernel32.dll" _
    ALIAS "GetSystemWindowsDirectoryW" (lpBuffer AS WSTRINGZ, _
    BYVAL uSize AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetSystemWindowsDirectory LIB "Kernel32.dll" _
    ALIAS "GetSystemWindowsDirectoryW" (lpBuffer AS WSTRINGZ, _
    BYVAL uSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetSystemWindowsDirectory LIB "Kernel32.dll" _
    ALIAS "GetSystemWindowsDirectoryA" (lpBuffer AS ASCIIZ, _
    BYVAL uSize AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

#IF NOT %DEF(%RC_INVOKED)
#IF %WIN32_WINNT >= &H0501 OR %DEF(%WINBASE_DECLARE_GET_SYSTEM_WOW64_DIRECTORY)

DECLARE FUNCTION GetSystemWow64DirectoryA LIB "Kernel32.dll" _
    ALIAS "GetSystemWow64DirectoryA" (lpBuffer AS ASCIIZ, _
    BYVAL uSize AS DWORD) AS DWORD

DECLARE FUNCTION GetSystemWow64DirectoryW LIB "Kernel32.dll" _
    ALIAS "GetSystemWow64DirectoryW" (lpBuffer AS WSTRINGZ, _
    BYVAL uSize AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetSystemWow64Directory LIB "Kernel32.dll" _
    ALIAS "GetSystemWow64DirectoryW" (lpBuffer AS WSTRINGZ, _
    BYVAL uSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetSystemWow64Directory LIB "Kernel32.dll" _
    ALIAS "GetSystemWow64DirectoryA" (lpBuffer AS ASCIIZ, _
    BYVAL uSize AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION Wow64EnableWow64FsRedirection LIB "Kernel32.dll" _
    ALIAS "Wow64EnableWow64FsRedirection" _
    (BYVAL Wow64FsEnableRedirection AS BYTE) AS LONG

DECLARE FUNCTION Wow64DisableWow64FsRedirection LIB "Kernel32.dll" _
    ALIAS "Wow64DisableWow64FsRedirection" _
    (pOldValue AS DWORD) AS LONG

DECLARE FUNCTION Wow64RevertWow64FsRedirection LIB "Kernel32.dll" _
    ALIAS "Wow64RevertWow64FsRedirection" _
    (BYVAL pOldValue AS DWORD) AS LONG

'
' for GetProcAddress
'
' [these callbacks are not documented]
'typedef DWORD (WINAPI* PGET_SYSTEM_WOW64_DIRECTORY_A)(__out_ecount_part_opt(uSize, return + 1) LPSTR lpBuffer, DWORD uSize);
'typedef DWORD (WINAPI* PGET_SYSTEM_WOW64_DIRECTORY_W)(__out_ecount_part_opt(uSize, return + 1) LPWSTR lpBuffer, DWORD uSize);

'
' GetProcAddress only accepts GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A,
' GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A, GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A.
' The others are if you want to use the strings in some other way.
'
$GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A    = "GetSystemWow64DirectoryA"$
$$GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W   = "GetSystemWow64DirectoryA"$$
'#define GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T TEXT("GetSystemWow64DirectoryA")
$GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A    = "GetSystemWow64DirectoryW"$
$$GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W   = "GetSystemWow64DirectoryW"$$
'#define GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T TEXT("GetSystemWow64DirectoryW")

'#if %DEF(%UNICODE)
'#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A
'#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W
'#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T
'#else
'#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A
'#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W
'#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T
'#endif

#ENDIF ' %WIN32_WINNT >= &H0501
#ENDIF ' #IF NOT %DEF(%RC_INVOKED)

DECLARE FUNCTION SetCurrentDirectoryA LIB "Kernel32.dll" _
    ALIAS "SetCurrentDirectoryA" (lpPathName AS ASCIIZ) AS LONG

DECLARE FUNCTION SetCurrentDirectoryW LIB "Kernel32.dll" _
    ALIAS "SetCurrentDirectoryW" (lpPathName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetCurrentDirectory LIB "Kernel32.dll" _
    ALIAS "SetCurrentDirectoryW" (lpPathName AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION SetCurrentDirectory LIB "Kernel32.dll" _
    ALIAS "SetCurrentDirectoryA" (lpPathName AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetCurrentDirectoryA LIB "Kernel32.dll" _
    ALIAS "GetCurrentDirectoryA" (BYVAL nBufferLength AS DWORD, _
    lpBuffer AS ASCIIZ) AS DWORD

DECLARE FUNCTION GetCurrentDirectoryW LIB "Kernel32.dll" _
    ALIAS "GetCurrentDirectoryW" (BYVAL nBufferLength AS DWORD, _
    lpBuffer AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetCurrentDirectory LIB "Kernel32.dll" _
    ALIAS "GetCurrentDirectoryW" (BYVAL nBufferLength AS DWORD, _
    lpBuffer AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION GetCurrentDirectory LIB "Kernel32.dll" _
    ALIAS "GetCurrentDirectoryA" (BYVAL nBufferLength AS DWORD, _
    lpBuffer AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

#IF %WIN32_WINNT >= &H0502

DECLARE FUNCTION SetDllDirectoryA LIB "Kernel32.dll" ALIAS "SetDllDirectoryA" _
    (lpPathName AS ASCIIZ) AS LONG

DECLARE FUNCTION SetDllDirectoryW LIB "Kernel32.dll" ALIAS "SetDllDirectoryW" _
    (lpPathName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetDllDirectory LIB "Kernel32.dll" ALIAS "SetDllDirectoryW" _
    (lpPathName AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION SetDllDirectory LIB "Kernel32.dll" ALIAS "SetDllDirectoryA" _
    (lpPathName AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetDllDirectoryA LIB "Kernel32.dll" ALIAS "GetDllDirectoryA" _
    (BYVAL nBufferLength AS DWORD, lpBuffer AS ASCIIZ) AS DWORD

DECLARE FUNCTION GetDllDirectoryW LIB "Kernel32.dll" ALIAS "GetDllDirectoryW" _
    (BYVAL nBufferLength AS DWORD, lpBuffer AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetDllDirectory LIB "Kernel32.dll" ALIAS "GetDllDirectoryW" _
    (BYVAL nBufferLength AS DWORD, lpBuffer AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION GetDllDirectory LIB "Kernel32.dll" ALIAS "GetDllDirectoryA" _
    (BYVAL nBufferLength AS DWORD, lpBuffer AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

#ENDIF ' %WIN32_WINNT >= &H0502

%BASE_SEARCH_PATH_ENABLE_SAFE_SEARCHMODE  = &H00001
%BASE_SEARCH_PATH_DISABLE_SAFE_SEARCHMODE = &H10000
%BASE_SEARCH_PATH_PERMANENT               = &H08000
%BASE_SEARCH_PATH_INVALID_FLAGS           = NOT &H18001

DECLARE FUNCTION SetSearchPathMode LIB "Kernel32.dll" _
    ALIAS "SetSearchPathMode" (BYVAL Flags AS DWORD) AS LONG

DECLARE FUNCTION GetDiskFreeSpaceA LIB "Kernel32.dll" _
    ALIAS "GetDiskFreeSpaceA" (lpRootPathName AS ASCIIZ, _
    lpSectorsPerCluster AS DWORD, lpBytesPerSector AS DWORD, _
    lpNumberOfFreeClusters AS DWORD, lpTotalNumberOfClusters AS DWORD) AS LONG

DECLARE FUNCTION GetDiskFreeSpaceW LIB "Kernel32.dll" _
    ALIAS "GetDiskFreeSpaceW" (lpRootPathName AS WSTRINGZ, _
    lpSectorsPerCluster AS DWORD, lpBytesPerSector AS DWORD, _
    lpNumberOfFreeClusters AS DWORD, lpTotalNumberOfClusters AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetDiskFreeSpace LIB "Kernel32.dll" _
    ALIAS "GetDiskFreeSpaceW" (lpRootPathName AS WSTRINGZ, _
    lpSectorsPerCluster AS DWORD, lpBytesPerSector AS DWORD, _
    lpNumberOfFreeClusters AS DWORD, lpTotalNumberOfClusters AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetDiskFreeSpace LIB "Kernel32.dll" _
    ALIAS "GetDiskFreeSpaceA" (lpRootPathName AS ASCIIZ, _
    lpSectorsPerCluster AS DWORD, lpBytesPerSector AS DWORD, _
    lpNumberOfFreeClusters AS DWORD, lpTotalNumberOfClusters AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetDiskFreeSpaceExA LIB "Kernel32.dll" _
    ALIAS "GetDiskFreeSpaceExA" (lpPathName AS ASCIIZ, _
    lpFreeBytesAvailableToCaller AS QUAD, lpTotalNumberOfBytes AS QUAD, _
    lpTotalNumberOfFreeBytes AS QUAD) AS LONG  ' *** should be unsigned quads

DECLARE FUNCTION GetDiskFreeSpaceExW LIB "Kernel32.dll" _
    ALIAS "GetDiskFreeSpaceExW" (lpPathName AS WSTRINGZ, _
    lpFreeBytesAvailableToCaller AS QUAD, lpTotalNumberOfBytes AS QUAD, _
    lpTotalNumberOfFreeBytes AS QUAD) AS LONG  ' *** should be unsigned quads

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetDiskFreeSpaceEx LIB "Kernel32.dll" _
    ALIAS "GetDiskFreeSpaceExW" (lpPathName AS WSTRINGZ, _
    lpFreeBytesAvailableToCaller AS QUAD, lpTotalNumberOfBytes AS QUAD, _
    lpTotalNumberOfFreeBytes AS QUAD) AS LONG  ' *** should be unsigned quads
#ELSE
DECLARE FUNCTION GetDiskFreeSpaceEx LIB "Kernel32.dll" _
    ALIAS "GetDiskFreeSpaceExA" (lpPathName AS ASCIIZ, _
    lpFreeBytesAvailableToCaller AS QUAD, lpTotalNumberOfBytes AS QUAD, _
    lpTotalNumberOfFreeBytes AS QUAD) AS LONG  ' *** should be unsigned quads
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CreateDirectoryA LIB "Kernel32.dll" _
    ALIAS "CreateDirectoryA" (lpPathName AS ASCIIZ, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES) AS LONG

DECLARE FUNCTION CreateDirectoryW LIB "Kernel32.dll" _
    ALIAS "CreateDirectoryW" (lpPathName AS WSTRINGZ, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateDirectory LIB "Kernel32.dll" _
    ALIAS "CreateDirectoryW" (lpPathName AS WSTRINGZ, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES) AS LONG
#ELSE
DECLARE FUNCTION CreateDirectory LIB "Kernel32.dll" _
    ALIAS "CreateDirectoryA" (lpPathName AS ASCIIZ, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CreateDirectoryExA LIB "Kernel32.dll" _
    ALIAS "CreateDirectoryExA" (lpTemplateDirectory AS ASCIIZ, _
    lpNewDirectory AS ASCIIZ, lpSecurityAttributes AS SECURITY_ATTRIBUTES) _
    AS LONG

DECLARE FUNCTION CreateDirectoryExW LIB "Kernel32.dll" _
    ALIAS "CreateDirectoryExW" (lpTemplateDirectory AS WSTRINGZ, _
    lpNewDirectory AS WSTRINGZ, lpSecurityAttributes AS SECURITY_ATTRIBUTES) _
    AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateDirectoryEx LIB "Kernel32.dll" _
    ALIAS "CreateDirectoryExW" (lpTemplateDirectory AS WSTRINGZ, _
    lpNewDirectory AS WSTRINGZ, lpSecurityAttributes AS SECURITY_ATTRIBUTES) _
    AS LONG
#ELSE
DECLARE FUNCTION CreateDirectoryEx LIB "Kernel32.dll" _
    ALIAS "CreateDirectoryExA" (lpTemplateDirectory AS ASCIIZ, _
    lpNewDirectory AS ASCIIZ, lpSecurityAttributes AS SECURITY_ATTRIBUTES) _
    AS LONG
#ENDIF ' NOT %UNICODE

#IF %WIN32_WINNT >= &H0600

DECLARE FUNCTION CreateDirectoryTransactedA LIB "Kernel32.dll" _
    ALIAS "CreateDirectoryTransactedA" (lpTemplateDirectory AS ASCIIZ, _
    lpNewDirectory AS ASCIIZ, lpSecurityAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL hTransaction AS DWORD) AS LONG

DECLARE FUNCTION CreateDirectoryTransactedW LIB "Kernel32.dll" _
    ALIAS "CreateDirectoryTransactedW" (lpTemplateDirectory AS WSTRINGZ, _
    lpNewDirectory AS WSTRINGZ, lpSecurityAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL hTransaction AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateDirectoryTransacted LIB "Kernel32.dll" _
    ALIAS "CreateDirectoryTransactedW" (lpTemplateDirectory AS WSTRINGZ, _
    lpNewDirectory AS WSTRINGZ, lpSecurityAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL hTransaction AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION CreateDirectoryTransacted LIB "Kernel32.dll" _
    ALIAS "CreateDirectoryTransactedA" (lpTemplateDirectory AS ASCIIZ, _
    lpNewDirectory AS ASCIIZ, lpSecurityAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL hTransaction AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' %WIN32_WINNT >= &H0600

DECLARE FUNCTION RemoveDirectoryA LIB "Kernel32.dll" ALIAS "RemoveDirectoryA" _
    (lpPathName AS ASCIIZ) AS LONG

DECLARE FUNCTION RemoveDirectoryW LIB "Kernel32.dll" ALIAS "RemoveDirectoryW" _
    (lpPathName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION RemoveDirectory LIB "Kernel32.dll" ALIAS "RemoveDirectoryW" _
    (lpPathName AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION RemoveDirectory LIB "Kernel32.dll" ALIAS "RemoveDirectoryA" _
    (lpPathName AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

#IF %WIN32_WINNT >= &H0600

DECLARE FUNCTION RemoveDirectoryTransactedA LIB "Kernel32.dll" _
    ALIAS "RemoveDirectoryTransactedA" (lpPathName AS ASCIIZ, _
    BYVAL hTransaction AS DWORD) AS LONG

DECLARE FUNCTION RemoveDirectoryTransactedW LIB "Kernel32.dll" _
    ALIAS "RemoveDirectoryTransactedW" (lpPathName AS WSTRINGZ, _
    BYVAL hTransaction AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION RemoveDirectoryTransacted LIB "Kernel32.dll" _
    ALIAS "RemoveDirectoryTransactedW" (lpPathName AS WSTRINGZ, _
    BYVAL hTransaction AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION RemoveDirectoryTransacted LIB "Kernel32.dll" _
    ALIAS "RemoveDirectoryTransactedA" (lpPathName AS ASCIIZ, _
    BYVAL hTransaction AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' %WIN32_WINNT >= &H0600

DECLARE FUNCTION GetFullPathNameA LIB "Kernel32.dll" ALIAS "GetFullPathNameA" _
    (lpFileName AS ASCIIZ, BYVAL nBufferLength AS DWORD, _
    lpBuffer AS ASCIIZ, lpFilePart AS DWORD) AS DWORD

DECLARE FUNCTION GetFullPathNameW LIB "Kernel32.dll" ALIAS "GetFullPathNameW" _
    (lpFileName AS WSTRINGZ, BYVAL nBufferLength AS DWORD, _
    lpBuffer AS WSTRINGZ, lpFilePart AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetFullPathName LIB "Kernel32.dll" ALIAS "GetFullPathNameW" _
    (lpFileName AS WSTRINGZ, BYVAL nBufferLength AS DWORD, _
    lpBuffer AS WSTRINGZ, lpFilePart AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetFullPathName LIB "Kernel32.dll" ALIAS "GetFullPathNameA" _
    (lpFileName AS ASCIIZ, BYVAL nBufferLength AS DWORD, _
    lpBuffer AS ASCIIZ, lpFilePart AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

#IF %WIN32_WINNT >= &H0600

DECLARE FUNCTION GetFullPathNameTransactedA LIB "Kernel32.dll" _
    ALIAS "GetFullPathNameTransactedA" (lpFileName AS ASCIIZ, _
    BYVAL nBufferLength AS DWORD, lpBuffer AS ASCIIZ, lpFilePart AS DWORD, _
    BYVAL hTransaction AS DWORD) AS DWORD

DECLARE FUNCTION GetFullPathNameTransactedW LIB "Kernel32.dll" _
    ALIAS "GetFullPathNameTransactedW" (lpFileName AS WSTRINGZ, _
    BYVAL nBufferLength AS DWORD, lpBuffer AS WSTRINGZ, lpFilePart AS DWORD, _
    BYVAL hTransaction AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetFullPathNameTransacted LIB "Kernel32.dll" _
    ALIAS "GetFullPathNameTransactedW" (lpFileName AS WSTRINGZ, _
    BYVAL nBufferLength AS DWORD, lpBuffer AS WSTRINGZ, lpFilePart AS DWORD, _
    BYVAL hTransaction AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetFullPathNameTransacted LIB "Kernel32.dll" _
    ALIAS "GetFullPathNameTransactedA" (lpFileName AS ASCIIZ, _
    BYVAL nBufferLength AS DWORD, lpBuffer AS ASCIIZ, lpFilePart AS DWORD, _
    BYVAL hTransaction AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

#ENDIF ' %WIN32_WINNT >= &H0600

%DDD_RAW_TARGET_PATH        = &H00000001
%DDD_REMOVE_DEFINITION      = &H00000002
%DDD_EXACT_MATCH_ON_REMOVE  = &H00000004
%DDD_NO_BROADCAST_SYSTEM    = &H00000008
%DDD_LUID_BROADCAST_DRIVE   = &H00000010

DECLARE FUNCTION DefineDosDeviceA LIB "Kernel32.dll" ALIAS "DefineDosDeviceA" _
    (BYVAL dwFlags AS DWORD, lpDeviceName AS ASCIIZ, _
    lpTargetPath AS ASCIIZ) AS LONG

DECLARE FUNCTION DefineDosDeviceW LIB "Kernel32.dll" ALIAS "DefineDosDeviceW" _
    (BYVAL dwFlags AS DWORD, lpDeviceName AS WSTRINGZ, _
    lpTargetPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION DefineDosDevice LIB "Kernel32.dll" ALIAS "DefineDosDeviceW" _
    (BYVAL dwFlags AS DWORD, lpDeviceName AS WSTRINGZ, _
    lpTargetPath AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION DefineDosDevice LIB "Kernel32.dll" ALIAS "DefineDosDeviceA" _
    (BYVAL dwFlags AS DWORD, lpDeviceName AS ASCIIZ, _
    lpTargetPath AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION QueryDosDeviceA LIB "Kernel32.dll" ALIAS "QueryDosDeviceA" _
    (lpDeviceName AS ASCIIZ, lpTargetPath AS ASCIIZ, _
    BYVAL ucchMax AS DWORD) AS DWORD

DECLARE FUNCTION QueryDosDeviceW LIB "Kernel32.dll" ALIAS "QueryDosDeviceW" _
    (lpDeviceName AS WSTRINGZ, lpTargetPath AS WSTRINGZ, _
    BYVAL ucchMax AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION QueryDosDevice LIB "Kernel32.dll" ALIAS "QueryDosDeviceW" _
    (lpDeviceName AS WSTRINGZ, lpTargetPath AS WSTRINGZ, _
    BYVAL ucchMax AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION QueryDosDevice LIB "Kernel32.dll" ALIAS "QueryDosDeviceA" _
    (lpDeviceName AS ASCIIZ, lpTargetPath AS ASCIIZ, _
    BYVAL ucchMax AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

%EXPAND_LOCAL_DRIVES = 1

DECLARE FUNCTION CreateFileA LIB "Kernel32.dll" ALIAS "CreateFileA" _
    (lpFileName AS ASCIIZ, BYVAL dwDesiredAccess AS DWORD, _
    BYVAL dwShareMode AS DWORD, lpSecurityAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL dwCreationDisposition AS DWORD, _
    BYVAL dwFlagsAndAttributes AS DWORD, BYVAL hTemplateFile AS DWORD) _
    AS DWORD

DECLARE FUNCTION CreateFileW LIB "Kernel32.dll" ALIAS "CreateFileW" _
    (lpFileName AS WSTRINGZ, BYVAL dwDesiredAccess AS DWORD, _
    BYVAL dwShareMode AS DWORD, lpSecurityAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL dwCreationDisposition AS DWORD, _
    BYVAL dwFlagsAndAttributes AS DWORD, BYVAL hTemplateFile AS DWORD) _
    AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateFile LIB "Kernel32.dll" ALIAS "CreateFileW" _
    (lpFileName AS WSTRINGZ, BYVAL dwDesiredAccess AS DWORD, _
    BYVAL dwShareMode AS DWORD, lpSecurityAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL dwCreationDisposition AS DWORD, _
    BYVAL dwFlagsAndAttributes AS DWORD, BYVAL hTemplateFile AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION CreateFile LIB "Kernel32.dll" ALIAS "CreateFileA" _
    (lpFileName AS ASCIIZ, BYVAL dwDesiredAccess AS DWORD, _
    BYVAL dwShareMode AS DWORD, lpSecurityAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL dwCreationDisposition AS DWORD, _
    BYVAL dwFlagsAndAttributes AS DWORD, BYVAL hTemplateFile AS DWORD) _
    AS DWORD
#ENDIF ' NOT %UNICODE

#IF %WIN32_WINNT >= &H0600

DECLARE FUNCTION CreateFileTransactedA LIB "Kernel32.dll" _
    ALIAS "CreateFileTransactedA" (lpFileName AS ASCIIZ, _
    BYVAL dwDesiredAccess AS DWORD, BYVAL dwShareMode AS DWORD, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL dwCreationDisposition AS DWORD, _
    BYVAL dwFlagsAndAttributes AS DWORD, BYVAL hTemplateFile AS DWORD, _
    BYVAL hTransaction AS DWORD, pusMiniVersion AS WORD, _
    BYVAL lpExtendedParameter AS DWORD) AS DWORD

DECLARE FUNCTION CreateFileTransactedW LIB "Kernel32.dll" _
    ALIAS "CreateFileTransactedW" (lpFileName AS WSTRINGZ, _
    BYVAL dwDesiredAccess AS DWORD, BYVAL dwShareMode AS DWORD, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL dwCreationDisposition AS DWORD, _
    BYVAL dwFlagsAndAttributes AS DWORD, BYVAL hTemplateFile AS DWORD, _
    BYVAL hTransaction AS DWORD, pusMiniVersion AS WORD, _
    BYVAL lpExtendedParameter AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateFileTransacted LIB "Kernel32.dll" _
    ALIAS "CreateFileTransactedW" (lpFileName AS WSTRINGZ, _
    BYVAL dwDesiredAccess AS DWORD, BYVAL dwShareMode AS DWORD, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL dwCreationDisposition AS DWORD, _
    BYVAL dwFlagsAndAttributes AS DWORD, BYVAL hTemplateFile AS DWORD, _
    BYVAL hTransaction AS DWORD, pusMiniVersion AS WORD, _
    BYVAL lpExtendedParameter AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION CreateFileTransacted LIB "Kernel32.dll" _
    ALIAS "CreateFileTransactedA" (lpFileName AS ASCIIZ, _
    BYVAL dwDesiredAccess AS DWORD, BYVAL dwShareMode AS DWORD, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL dwCreationDisposition AS DWORD, _
    BYVAL dwFlagsAndAttributes AS DWORD, BYVAL hTemplateFile AS DWORD, _
    BYVAL hTransaction AS DWORD, pusMiniVersion AS WORD, _
    BYVAL lpExtendedParameter AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

#ENDIF ' %WIN32_WINNT >= &H0600


#IF %WIN32_WINNT >= &H0502

DECLARE FUNCTION ReOpenFile LIB "Kernel32.dll" ALIAS "ReOpenFile" _
    (BYVAL hOriginalFile AS DWORD, BYVAL dwDesiredAccess AS DWORD, _
    BYVAL dwShareMode AS DWORD, BYVAL dwFlagsAndAttributes AS DWORD) AS DWORD

#ENDIF ' %WIN32_WINNT >= &H0502

DECLARE FUNCTION SetFileAttributesA LIB "Kernel32.dll" _
    ALIAS "SetFileAttributesA" (lpFileName AS ASCIIZ, _
    BYVAL dwFileAttributes AS DWORD) AS LONG

DECLARE FUNCTION SetFileAttributesW LIB "Kernel32.dll" _
    ALIAS "SetFileAttributesW" (lpFileName AS WSTRINGZ, _
    BYVAL dwFileAttributes AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetFileAttributes LIB "Kernel32.dll" _
    ALIAS "SetFileAttributesW" (lpFileName AS WSTRINGZ, _
    BYVAL dwFileAttributes AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SetFileAttributes LIB "Kernel32.dll" _
    ALIAS "SetFileAttributesA" (lpFileName AS ASCIIZ, _
    BYVAL dwFileAttributes AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetFileAttributesA LIB "Kernel32.dll" _
    ALIAS "GetFileAttributesA" (lpFileName AS ASCIIZ) AS DWORD

DECLARE FUNCTION GetFileAttributesW LIB "Kernel32.dll" _
    ALIAS "GetFileAttributesW" (lpFileName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetFileAttributes LIB "Kernel32.dll" _
    ALIAS "GetFileAttributesW" (lpFileName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION GetFileAttributes LIB "Kernel32.dll" _
    ALIAS "GetFileAttributesA" (lpFileName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

#IF %WIN32_WINNT >= &H0600

DECLARE FUNCTION SetFileAttributesTransactedA LIB "Kernel32.dll" _
    ALIAS "SetFileAttributesTransactedA" (lpFileName AS ASCIIZ, _
    BYVAL dwFileAttributes AS DWORD, BYVAL hTransaction AS DWORD) AS LONG

DECLARE FUNCTION SetFileAttributesTransactedW LIB "Kernel32.dll" _
    ALIAS "SetFileAttributesTransactedW" (lpFileName AS WSTRINGZ, _
    BYVAL dwFileAttributes AS DWORD, BYVAL hTransaction AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetFileAttributesTransacted LIB "Kernel32.dll" _
    ALIAS "SetFileAttributesTransactedW" (lpFileName AS WSTRINGZ, _
    BYVAL dwFileAttributes AS DWORD, BYVAL hTransaction AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SetFileAttributesTransacted LIB "Kernel32.dll" _
    ALIAS "SetFileAttributesTransactedA" (lpFileName AS ASCIIZ, _
    BYVAL dwFileAttributes AS DWORD, BYVAL hTransaction AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' %WIN32_WINNT >= &H0600

MACRO GET_FILEEX_INFO_LEVELS_enum=LONG
ENUM GET_FILEEX_INFO_LEVELS SINGULAR
    GetFileExInfoStandard
    GetFileExMaxInfoLevel
END ENUM

#IF %WIN32_WINNT >= &H0600

DECLARE FUNCTION GetFileAttributesTransactedA LIB "Kernel32.dll" _
    ALIAS "GetFileAttributesTransactedA" (lpFileName AS ASCIIZ, _
    BYVAL fInfoLevelId AS GET_FILEEX_INFO_LEVELS_enum, _
    BYVAL lpFileInformation AS DWORD, _
    BYVAL hTransaction AS DWORD) AS LONG

DECLARE FUNCTION GetFileAttributesTransactedW LIB "Kernel32.dll" _
    ALIAS "GetFileAttributesTransactedW" (lpFileName AS WSTRINGZ, _
    BYVAL fInfoLevelId AS GET_FILEEX_INFO_LEVELS_enum, _
    BYVAL lpFileInformation AS DWORD, _
    BYVAL hTransaction AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetFileAttributesTransacted LIB "Kernel32.dll" _
    ALIAS "GetFileAttributesTransactedW" (lpFileName AS WSTRINGZ, _
    BYVAL fInfoLevelId AS GET_FILEEX_INFO_LEVELS_enum, _
    BYVAL lpFileInformation AS DWORD, _
    BYVAL hTransaction AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetFileAttributesTransacted LIB "Kernel32.dll" _
    ALIAS "GetFileAttributesTransactedA" (lpFileName AS ASCIIZ, _
    BYVAL fInfoLevelId AS GET_FILEEX_INFO_LEVELS_enum, _
    BYVAL lpFileInformation AS DWORD, _
    BYVAL hTransaction AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' %WIN32_WINNT >= &H0600

DECLARE FUNCTION GetFileAttributesExA LIB "Kernel32.dll" _
    ALIAS "GetFileAttributesExA" (lpFileName AS ASCIIZ, _
    BYVAL fInfoLevelId AS GET_FILEEX_INFO_LEVELS_enum, _
    BYVAL lpFileInformation AS DWORD) AS LONG

DECLARE FUNCTION GetFileAttributesExW LIB "Kernel32.dll" _
    ALIAS "GetFileAttributesExW" (lpFileName AS WSTRINGZ, _
    BYVAL fInfoLevelId AS GET_FILEEX_INFO_LEVELS_enum, _
    BYVAL lpFileInformation AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetFileAttributesEx LIB "Kernel32.dll" _
    ALIAS "GetFileAttributesExW" (lpFileName AS WSTRINGZ, _
    BYVAL fInfoLevelId AS GET_FILEEX_INFO_LEVELS_enum, _
    BYVAL lpFileInformation AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetFileAttributesEx LIB "Kernel32.dll" _
    ALIAS "GetFileAttributesExA" (lpFileName AS ASCIIZ, _
    BYVAL fInfoLevelId AS GET_FILEEX_INFO_LEVELS_enum, _
    BYVAL lpFileInformation AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetCompressedFileSizeA LIB "Kernel32.dll" _
    ALIAS "GetCompressedFileSizeA" (lpFileName AS ASCIIZ, _
    lpFileSizeHigh AS DWORD) AS DWORD

DECLARE FUNCTION GetCompressedFileSizeW LIB "Kernel32.dll" _
    ALIAS "GetCompressedFileSizeW" (lpFileName AS WSTRINGZ, _
    lpFileSizeHigh AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetCompressedFileSize LIB "Kernel32.dll" _
    ALIAS "GetCompressedFileSizeW" (lpFileName AS WSTRINGZ, _
    lpFileSizeHigh AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetCompressedFileSize LIB "Kernel32.dll" _
    ALIAS "GetCompressedFileSizeA" (lpFileName AS ASCIIZ, _
    lpFileSizeHigh AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

#IF %WIN32_WINNT >= &H0600

DECLARE FUNCTION GetCompressedFileSizeTransactedA LIB "Kernel32.dll" _
    ALIAS "GetCompressedFileSizeTransactedA" (lpFileName AS ASCIIZ, _
    lpFileSizeHigh AS DWORD, BYVAL hTransaction AS DWORD) AS DWORD

DECLARE FUNCTION GetCompressedFileSizeTransactedW LIB "Kernel32.dll" _
    ALIAS "GetCompressedFileSizeTransactedW" (lpFileName AS WSTRINGZ, _
    lpFileSizeHigh AS DWORD, BYVAL hTransaction AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetCompressedFileSizeTransacted LIB "Kernel32.dll" _
    ALIAS "GetCompressedFileSizeTransactedW" (lpFileName AS WSTRINGZ, _
    lpFileSizeHigh AS DWORD, BYVAL hTransaction AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetCompressedFileSizeTransacted LIB "Kernel32.dll" _
    ALIAS "GetCompressedFileSizeTransactedA" (lpFileName AS ASCIIZ, _
    lpFileSizeHigh AS DWORD, BYVAL hTransaction AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

#ENDIF ' %WIN32_WINNT >= &H0600

DECLARE FUNCTION DeleteFileA LIB "Kernel32.dll" ALIAS "DeleteFileA" _
    (lpFileName AS ASCIIZ) AS LONG

DECLARE FUNCTION DeleteFileW LIB "Kernel32.dll" ALIAS "DeleteFileW" _
    (lpFileName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION DeleteFile LIB "Kernel32.dll" ALIAS "DeleteFileW" _
    (lpFileName AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION DeleteFile LIB "Kernel32.dll" ALIAS "DeleteFileA" _
    (lpFileName AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

#IF %WIN32_WINNT >= &H0600

DECLARE FUNCTION DeleteFileTransactedA LIB "Kernel32.dll" _
    ALIAS "DeleteFileTransactedA" (lpFileName AS ASCIIZ, _
    BYVAL hTransaction AS DWORD) AS LONG

DECLARE FUNCTION DeleteFileTransactedW LIB "Kernel32.dll" _
    ALIAS "DeleteFileTransactedW" (lpFileName AS WSTRINGZ, _
    BYVAL hTransaction AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION DeleteFileTransacted LIB "Kernel32.dll" _
    ALIAS "DeleteFileTransactedW" (lpFileName AS WSTRINGZ, _
    BYVAL hTransaction AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION DeleteFileTransacted LIB "Kernel32.dll" _
    ALIAS "DeleteFileTransactedA" (lpFileName AS ASCIIZ, _
    BYVAL hTransaction AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' %WIN32_WINNT >= &H0600


#IF %WIN32_WINNT >= &H0501

DECLARE FUNCTION CheckNameLegalDOS8Dot3A LIB "Kernel32.dll" _
    ALIAS "CheckNameLegalDOS8Dot3A" (lpName AS ASCIIZ, lpOemName AS ASCIIZ, _
    BYVAL OemNameSize AS DWORD, pbNameContainsSpaces AS LONG, _
    pbNameLegal AS LONG) AS LONG

DECLARE FUNCTION CheckNameLegalDOS8Dot3W LIB "Kernel32.dll" _
    ALIAS "CheckNameLegalDOS8Dot3W" (lpName AS WSTRINGZ, _
    lpOemName AS WSTRINGZ, BYVAL OemNameSize AS DWORD, _
    pbNameContainsSpaces AS LONG, pbNameLegal AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CheckNameLegalDOS8Dot3 LIB "Kernel32.dll" _
    ALIAS "CheckNameLegalDOS8Dot3W" (lpName AS WSTRINGZ, _
    lpOemName AS WSTRINGZ, BYVAL OemNameSize AS DWORD, _
    pbNameContainsSpaces AS LONG, pbNameLegal AS LONG) AS LONG
#ELSE
DECLARE FUNCTION CheckNameLegalDOS8Dot3 LIB "Kernel32.dll" _
    ALIAS "CheckNameLegalDOS8Dot3A" (lpName AS ASCIIZ, lpOemName AS ASCIIZ, _
    BYVAL OemNameSize AS DWORD, pbNameContainsSpaces AS LONG, _
    pbNameLegal AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' (%WIN32_WINNT >= &H0501)

#IF (%WIN32_WINNT >= &H0400)

MACRO FINDEX_INFO_LEVELS_enum=LONG
ENUM FINDEX_INFO_LEVELS SINGULAR
    FindExInfoStandard
    FindExInfoBasic
    FindExInfoMaxInfoLevel
END ENUM

MACRO FINDEX_SEARCH_OPS_enum=LONG
ENUM FINDEX_SEARCH_OPS SINGULAR
    FindExSearchNameMatch
    FindExSearchLimitToDirectories
    FindExSearchLimitToDevices
    FindExSearchMaxSearchOp
END ENUM

%FIND_FIRST_EX_CASE_SENSITIVE  = &H00000001
%FIND_FIRST_EX_LARGE_FETCH     = &H00000002

DECLARE FUNCTION FindFirstFileExA LIB "Kernel32.dll" ALIAS "FindFirstFileExA" _
    (lpFileName AS ASCIIZ, BYVAL fInfoLevelId AS FINDEX_INFO_LEVELS_enum, _
    BYVAL lpFindFileData AS DWORD, BYVAL fSearchOp AS FINDEX_SEARCH_OPS_enum, _
    BYVAL lpSearchFilter AS DWORD, BYVAL dwAdditionalFlags AS DWORD) AS DWORD

DECLARE FUNCTION FindFirstFileExW LIB "Kernel32.dll" ALIAS "FindFirstFileExW" _
    (lpFileName AS WSTRINGZ, BYVAL fInfoLevelId AS FINDEX_INFO_LEVELS_enum, _
    BYVAL lpFindFileData AS DWORD, BYVAL fSearchOp AS FINDEX_SEARCH_OPS_enum, _
    BYVAL lpSearchFilter AS DWORD, BYVAL dwAdditionalFlags AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION FindFirstFileEx LIB "Kernel32.dll" ALIAS "FindFirstFileExW" _
    (lpFileName AS WSTRINGZ, BYVAL fInfoLevelId AS FINDEX_INFO_LEVELS_enum, _
    BYVAL lpFindFileData AS DWORD, BYVAL fSearchOp AS FINDEX_SEARCH_OPS_enum, _
    BYVAL lpSearchFilter AS DWORD, BYVAL dwAdditionalFlags AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION FindFirstFileEx LIB "Kernel32.dll" ALIAS "FindFirstFileExA" _
    (lpFileName AS ASCIIZ, BYVAL fInfoLevelId AS FINDEX_INFO_LEVELS_enum, _
    BYVAL lpFindFileData AS DWORD, BYVAL fSearchOp AS FINDEX_SEARCH_OPS_enum, _
    BYVAL lpSearchFilter AS DWORD, BYVAL dwAdditionalFlags AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

#IF %WIN32_WINNT >= &H0600

DECLARE FUNCTION FindFirstFileTransactedA LIB "Kernel32.dll" _
    ALIAS "FindFirstFileTransactedA" (lpFileName AS ASCIIZ, _
    BYVAL fInfoLevelId AS FINDEX_INFO_LEVELS_enum, _
    lpFindFileData AS WIN32_FIND_DATA, _
    BYVAL fSearchOp AS FINDEX_SEARCH_OPS_enum, BYVAL lpSearchFilter AS DWORD, _
    BYVAL dwAdditionalFlags AS DWORD, BYVAL hTransaction AS DWORD) AS DWORD

DECLARE FUNCTION FindFirstFileTransactedW LIB "Kernel32.dll" _
    ALIAS "FindFirstFileTransactedW" (lpFileName AS WSTRINGZ, _
    BYVAL fInfoLevelId AS FINDEX_INFO_LEVELS_enum, _
    lpFindFileData AS WIN32_FIND_DATA, _
    BYVAL fSearchOp AS FINDEX_SEARCH_OPS_enum, BYVAL lpSearchFilter AS DWORD, _
    BYVAL dwAdditionalFlags AS DWORD, BYVAL hTransaction AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION FindFirstFileTransacted LIB "Kernel32.dll" _
    ALIAS "FindFirstFileTransactedW" (lpFileName AS WSTRINGZ, _
    BYVAL fInfoLevelId AS FINDEX_INFO_LEVELS_enum, _
    lpFindFileData AS WIN32_FIND_DATA, _
    BYVAL fSearchOp AS FINDEX_SEARCH_OPS_enum, BYVAL lpSearchFilter AS DWORD, _
    BYVAL dwAdditionalFlags AS DWORD, BYVAL hTransaction AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION FindFirstFileTransacted LIB "Kernel32.dll" _
    ALIAS "FindFirstFileTransactedA" (lpFileName AS ASCIIZ, _
    BYVAL fInfoLevelId AS FINDEX_INFO_LEVELS_enum, _
    lpFindFileData AS WIN32_FIND_DATA, _
    BYVAL fSearchOp AS FINDEX_SEARCH_OPS_enum, BYVAL lpSearchFilter AS DWORD, _
    BYVAL dwAdditionalFlags AS DWORD, BYVAL hTransaction AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

#ENDIF ' #IF %WIN32_WINNT >= &H0600

#ENDIF ' %WIN32_WINNT >= &H0400

DECLARE FUNCTION FindFirstFileA LIB "Kernel32.dll" ALIAS "FindFirstFileA" _
    (lpFileName AS ASCIIZ, lpFindFileData AS WIN32_FIND_DATAA) AS DWORD

DECLARE FUNCTION FindFirstFileW LIB "Kernel32.dll" ALIAS "FindFirstFileW" _
    (lpFileName AS WSTRINGZ, lpFindFileData AS WIN32_FIND_DATAW) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION FindFirstFile LIB "Kernel32.dll" ALIAS "FindFirstFileW" _
    (lpFileName AS WSTRINGZ, lpFindFileData AS WIN32_FIND_DATAW) AS DWORD
#ELSE
DECLARE FUNCTION FindFirstFile LIB "Kernel32.dll" ALIAS "FindFirstFileA" _
    (lpFileName AS ASCIIZ, lpFindFileData AS WIN32_FIND_DATAA) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION FindNextFileA LIB "Kernel32.dll" ALIAS "FindNextFileA" _
    (BYVAL hFindFile AS DWORD, lpFindFileData AS WIN32_FIND_DATAA) AS LONG

DECLARE FUNCTION FindNextFileW LIB "Kernel32.dll" ALIAS "FindNextFileW" _
    (BYVAL hFindFile AS DWORD, lpFindFileData AS WIN32_FIND_DATAW) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION FindNextFile LIB "Kernel32.dll" ALIAS "FindNextFileW" _
    (BYVAL hFindFile AS DWORD, lpFindFileData AS WIN32_FIND_DATAW) AS LONG
#ELSE
DECLARE FUNCTION FindNextFile LIB "Kernel32.dll" ALIAS "FindNextFileA" _
    (BYVAL hFindFile AS DWORD, lpFindFileData AS WIN32_FIND_DATAA) AS LONG
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION SearchPathA LIB "Kernel32.dll" ALIAS "SearchPathA" _
    (lpPath AS ASCIIZ, lpFileName AS ASCIIZ, lpExtension AS ASCIIZ, _
    BYVAL nBufferLength AS LONG, lpBuffer AS ASCIIZ, lpFilePart AS ASCIIZ) _
    AS DWORD

DECLARE FUNCTION SearchPathW LIB "Kernel32.dll" ALIAS "SearchPathW" _
    (lpPath AS WSTRINGZ, lpFileName AS WSTRINGZ, lpExtension AS WSTRINGZ, _
    BYVAL nBufferLength AS LONG, lpBuffer AS WSTRINGZ, _
    lpFilePart AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION SearchPath LIB "Kernel32.dll" ALIAS "SearchPathW" _
    (lpPath AS WSTRINGZ, lpFileName AS WSTRINGZ, lpExtension AS WSTRINGZ, _
    BYVAL nBufferLength AS LONG, lpBuffer AS WSTRINGZ, _
    lpFilePart AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION SearchPath LIB "Kernel32.dll" ALIAS "SearchPathA" _
    (lpPath AS ASCIIZ, lpFileName AS ASCIIZ, lpExtension AS ASCIIZ, _
    BYVAL nBufferLength AS LONG, lpBuffer AS ASCIIZ, lpFilePart AS ASCIIZ) _
    AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CopyFileA LIB "Kernel32.dll" ALIAS "CopyFileA" _
    (lpExistingFileName AS ASCIIZ, lpNewFileName AS ASCIIZ, _
    BYVAL bFailIfExists AS LONG) AS LONG

DECLARE FUNCTION CopyFileW LIB "Kernel32.dll" ALIAS "CopyFileW" _
    (lpExistingFileName AS WSTRINGZ, lpNewFileName AS WSTRINGZ, _
    BYVAL bFailIfExists AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CopyFile LIB "Kernel32.dll" ALIAS "CopyFileW" _
    (lpExistingFileName AS WSTRINGZ, lpNewFileName AS WSTRINGZ, _
    BYVAL bFailIfExists AS LONG) AS LONG
#ELSE
DECLARE FUNCTION CopyFile LIB "Kernel32.dll" ALIAS "CopyFileA" _
    (lpExistingFileName AS ASCIIZ, lpNewFileName AS ASCIIZ, _
    BYVAL bFailIfExists AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

#IF (%WIN32_WINNT >= &H0400)

'DECLARE FUNCTION LPPROGRESS_ROUTINE (BYVAL TotalFileSize AS LARGE_INTEGER, _
'    BYVAL TotalBytesTransferred AS LARGE_INTEGER, _
'    BYVAL StreamSize AS LARGE_INTEGER, _
'    BYVAL StreamBytesTransferred AS LARGE_INTEGER, _
'    BYVAL dwStreamNumber AS DWORD, BYVAL dwCallbackReason AS DWORD, _
'    BYVAL hSourceFile AS DWORD, BYVAL hDestinationFile AS DWORD, _
'    BYVAL lpData AS DWORD) AS DWORD

DECLARE FUNCTION CopyFileExA LIB "Kernel32.dll" ALIAS "CopyFileExA" _
    (lpExistingFileName AS ASCIIZ, lpNewFileName AS ASCIIZ, _
    BYVAL lpProgressRoutine AS DWORD, BYVAL lpData AS DWORD, _
    pbCancel AS LONG, BYVAL dwCopyFlags AS DWORD) AS LONG

DECLARE FUNCTION CopyFileExW LIB "Kernel32.dll" ALIAS "CopyFileExW" _
    (lpExistingFileName AS WSTRINGZ, lpNewFileName AS WSTRINGZ, _
    BYVAL lpProgressRoutine AS DWORD, BYVAL lpData AS DWORD, _
    pbCancel AS LONG, BYVAL dwCopyFlags AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CopyFileEx LIB "Kernel32.dll" ALIAS "CopyFileExW" _
    (lpExistingFileName AS WSTRINGZ, lpNewFileName AS WSTRINGZ, _
    BYVAL lpProgressRoutine AS DWORD, BYVAL lpData AS DWORD, _
    pbCancel AS LONG, BYVAL dwCopyFlags AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION CopyFileEx LIB "Kernel32.dll" ALIAS "CopyFileExA" _
    (lpExistingFileName AS ASCIIZ, lpNewFileName AS ASCIIZ, _
    BYVAL lpProgressRoutine AS DWORD, BYVAL lpData AS DWORD, _
    pbCancel AS LONG, BYVAL dwCopyFlags AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

#IF %WIN32_WINNT >= &H0600

DECLARE FUNCTION CopyFileTransactedA LIB "Kernel32.dll" _
    ALIAS "CopyFileTransactedA" (lpExistingFileName AS ASCIIZ, _
    lpNewFileName AS ASCIIZ, BYVAL lpProgressRoutine AS DWORD, _
    BYVAL lpData AS DWORD, pbCancel AS LONG, BYVAL dwCopyFlags AS DWORD, _
    BYVAL hTransaction AS DWORD) AS LONG

DECLARE FUNCTION CopyFileTransactedW LIB "Kernel32.dll" _
    ALIAS "CopyFileTransactedW" (lpExistingFileName AS WSTRINGZ, _
    lpNewFileName AS WSTRINGZ, BYVAL lpProgressRoutine AS DWORD, _
    BYVAL lpData AS DWORD, pbCancel AS LONG, BYVAL dwCopyFlags AS DWORD, _
    BYVAL hTransaction AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CopyFileTransacted LIB "Kernel32.dll" _
    ALIAS "CopyFileTransactedW" (lpExistingFileName AS WSTRINGZ, _
    lpNewFileName AS WSTRINGZ, BYVAL lpProgressRoutine AS DWORD, _
    BYVAL lpData AS DWORD, pbCancel AS LONG, BYVAL dwCopyFlags AS DWORD, _
    BYVAL hTransaction AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION CopyFileTransacted LIB "Kernel32.dll" _
    ALIAS "CopyFileTransactedA" (lpExistingFileName AS ASCIIZ, _
    lpNewFileName AS ASCIIZ, BYVAL lpProgressRoutine AS DWORD, _
    BYVAL lpData AS DWORD, pbCancel AS LONG, BYVAL dwCopyFlags AS DWORD, _
    BYVAL hTransaction AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' %WIN32_WINNT >= &H0600
#ENDIF ' %WIN32_WINNT >= &H0400

DECLARE FUNCTION MoveFileA LIB "Kernel32.dll" ALIAS "MoveFileA" _
    (lpExistingFileName AS ASCIIZ, lpNewFileName AS ASCIIZ) AS LONG

DECLARE FUNCTION MoveFileW LIB "Kernel32.dll" ALIAS "MoveFileW" _
    (lpExistingFileName AS WSTRINGZ, lpNewFileName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION MoveFile LIB "Kernel32.dll" ALIAS "MoveFileW" _
    (lpExistingFileName AS WSTRINGZ, lpNewFileName AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION MoveFile LIB "Kernel32.dll" ALIAS "MoveFileA" _
    (lpExistingFileName AS ASCIIZ, lpNewFileName AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION MoveFileExA LIB "Kernel32.dll" ALIAS "MoveFileExA" _
    (lpExistingFileName AS ASCIIZ, lpNewFileName AS ASCIIZ, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION MoveFileExW LIB "Kernel32.dll" ALIAS "MoveFileExW" _
    (lpExistingFileName AS WSTRINGZ, lpNewFileName AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION MoveFileEx LIB "Kernel32.dll" ALIAS "MoveFileExW" _
    (lpExistingFileName AS WSTRINGZ, lpNewFileName AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION MoveFileEx LIB "Kernel32.dll" ALIAS "MoveFileExA" _
    (lpExistingFileName AS ASCIIZ, lpNewFileName AS ASCIIZ, _
    BYVAL dwFlags AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

#IF (%WIN32_WINNT >= &H0500)

DECLARE FUNCTION MoveFileWithProgressA LIB "Kernel32.dll" _
    ALIAS "MoveFileWithProgressA" (lpExistingFileName AS ASCIIZ, _
    lpNewFileName AS ASCIIZ, BYVAL lpProgressRoutine AS DWORD, _
    BYVAL lpData AS BYTE PTR, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION MoveFileWithProgressW LIB "Kernel32.dll" _
    ALIAS "MoveFileWithProgressW" (lpExistingFileName AS WSTRINGZ, _
    lpNewFileName AS WSTRINGZ, BYVAL lpProgressRoutine AS DWORD, _
    BYVAL lpData AS BYTE PTR, BYVAL dwFlags AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION MoveFileWithProgress LIB "Kernel32.dll" _
    ALIAS "MoveFileWithProgressW" (lpExistingFileName AS WSTRINGZ, _
    lpNewFileName AS WSTRINGZ, BYVAL lpProgressRoutine AS DWORD, _
    BYVAL lpData AS BYTE PTR, BYVAL dwFlags AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION MoveFileWithProgress LIB "Kernel32.dll" _
    ALIAS "MoveFileWithProgressA" (lpExistingFileName AS ASCIIZ, _
    lpNewFileName AS ASCIIZ, BYVAL lpProgressRoutine AS DWORD, _
    BYVAL lpData AS BYTE PTR, BYVAL dwFlags AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE
#ENDIF ' (%WIN32_WINNT >= &H0500)

#IF (%WIN32_WINNT >= &H0600)

DECLARE FUNCTION MoveFileTransactedA LIB "Kernel32.dll" _
    ALIAS "MoveFileTransactedA" (lpExistingFileName AS ASCIIZ, _
    lpNewFileName AS ASCIIZ, BYVAL lpProgressRoutine AS DWORD, _
    BYVAL lpData AS DWORD, BYVAL dwFlags AS DWORD, _
    BYVAL hTransaction AS DWORD) AS LONG

DECLARE FUNCTION MoveFileTransactedW LIB "Kernel32.dll" _
    ALIAS "MoveFileTransactedW" (lpExistingFileName AS WSTRINGZ, _
    lpNewFileName AS WSTRINGZ, BYVAL lpProgressRoutine AS DWORD, _
    BYVAL lpData AS DWORD, BYVAL dwFlags AS DWORD, _
    BYVAL hTransaction AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION MoveFileTransacted LIB "Kernel32.dll" _
    ALIAS "MoveFileTransactedW" (lpExistingFileName AS WSTRINGZ, _
    lpNewFileName AS WSTRINGZ, BYVAL lpProgressRoutine AS DWORD, _
    BYVAL lpData AS DWORD, BYVAL dwFlags AS DWORD, _
    BYVAL hTransaction AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION MoveFileTransacted LIB "Kernel32.dll" _
    ALIAS "MoveFileTransactedA" (lpExistingFileName AS ASCIIZ, _
    lpNewFileName AS ASCIIZ, BYVAL lpProgressRoutine AS DWORD, _
    BYVAL lpData AS DWORD, BYVAL dwFlags AS DWORD, _
    BYVAL hTransaction AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE
#ENDIF ' (%WIN32_WINNT >= &H0600)

%MOVEFILE_REPLACE_EXISTING      = &H00000001
%MOVEFILE_COPY_ALLOWED          = &H00000002
%MOVEFILE_DELAY_UNTIL_REBOOT    = &H00000004
%MOVEFILE_WRITE_THROUGH         = &H00000008
#IF (%WIN32_WINNT >= &H0500)
%MOVEFILE_CREATE_HARDLINK       = &H00000010
%MOVEFILE_FAIL_IF_NOT_TRACKABLE = &H00000020
#ENDIF ' (%WIN32_WINNT >= &H0500)


#IF (%WIN32_WINNT >= &H0500)

DECLARE FUNCTION ReplaceFileA LIB "Kernel32.dll" ALIAS "ReplaceFileA" _
    (lpReplacedFileName AS ASCIIZ, lpReplacementFileName AS ASCIIZ, _
    lpBackupFileName AS ASCIIZ, BYVAL dwReplaceFlags AS DWORD, _
    BYVAL lpExclude AS DWORD, BYVAL lpReserved AS DWORD) AS LONG

DECLARE FUNCTION ReplaceFileW LIB "Kernel32.dll" ALIAS "ReplaceFileW" _
    (lpReplacedFileName AS WSTRINGZ, lpReplacementFileName AS WSTRINGZ, _
    lpBackupFileName AS WSTRINGZ, BYVAL dwReplaceFlags AS DWORD, _
    BYVAL lpExclude AS DWORD, BYVAL lpReserved AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ReplaceFile LIB "Kernel32.dll" ALIAS "ReplaceFileW" _
    (lpReplacedFileName AS WSTRINGZ, lpReplacementFileName AS WSTRINGZ, _
    lpBackupFileName AS WSTRINGZ, BYVAL dwReplaceFlags AS DWORD, _
    BYVAL lpExclude AS DWORD, BYVAL lpReserved AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION ReplaceFile LIB "Kernel32.dll" ALIAS "ReplaceFileA" _
    (lpReplacedFileName AS ASCIIZ, lpReplacementFileName AS ASCIIZ, _
    lpBackupFileName AS ASCIIZ, BYVAL dwReplaceFlags AS DWORD, _
    BYVAL lpExclude AS DWORD, BYVAL lpReserved AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE
#ENDIF ' (%WIN32_WINNT >= &H0500)


#IF (%WIN32_WINNT >= &H0500)
'
' API call to create hard links.
'

DECLARE FUNCTION CreateHardLinkA LIB "Kernel32.dll" ALIAS "CreateHardLinkA" _
    (lpFileName AS ASCIIZ, lpExistingFileName AS ASCIIZ, _
    lpSecurity_Attributes AS SECURITY_ATTRIBUTES) AS LONG

DECLARE FUNCTION CreateHardLinkW LIB "Kernel32.dll" ALIAS "CreateHardLinkW" _
    (lpFileName AS WSTRINGZ, lpExistingFileName AS WSTRINGZ, _
    lpSecurity_Attributes AS SECURITY_ATTRIBUTES) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateHardLink LIB "Kernel32.dll" ALIAS "CreateHardLinkW" _
    (lpFileName AS WSTRINGZ, lpExistingFileName AS WSTRINGZ, _
    lpSecurity_Attributes AS SECURITY_ATTRIBUTES) AS LONG
#ELSE
DECLARE FUNCTION CreateHardLink LIB "Kernel32.dll" ALIAS "CreateHardLinkA" _
    (lpFileName AS ASCIIZ, lpExistingFileName AS ASCIIZ, _
    lpSecurity_Attributes AS SECURITY_ATTRIBUTES) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' (%WIN32_WINNT >= &H0500)

#IF (%WIN32_WINNT >= &H0600)
'
' API call to create hard links.
'

DECLARE FUNCTION CreateHardLinkTransactedA LIB "Kernel32.dll" _
    ALIAS "CreateHardLinkTransactedA" (lpFileName AS ASCIIZ, _
    lpExistingFileName AS ASCIIZ, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL hTransaction AS DWORD) AS LONG

DECLARE FUNCTION CreateHardLinkTransactedW LIB "Kernel32.dll" _
    ALIAS "CreateHardLinkTransactedW" (lpFileName AS WSTRINGZ, _
    lpExistingFileName AS WSTRINGZ, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL hTransaction AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateHardLinkTransacted LIB "Kernel32.dll" _
    ALIAS "CreateHardLinkTransactedW" (lpFileName AS WSTRINGZ, _
    lpExistingFileName AS WSTRINGZ, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL hTransaction AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION CreateHardLinkTransacted LIB "Kernel32.dll" _
    ALIAS "CreateHardLinkTransactedA" (lpFileName AS ASCIIZ, _
    lpExistingFileName AS ASCIIZ, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL hTransaction AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' (%WIN32_WINNT >= &H0600)


#IF (%WIN32_WINNT >= &H0501)

'
' API call to enumerate for streams within a file
'

MACRO STREAM_INFO_LEVELS_enum=LONG
ENUM STREAM_INFO_LEVELS SINGULAR
    FindStreamInfoStandard
    FindStreamInfoMaxInfoLevel
END ENUM

TYPE WIN32_FIND_STREAM_DATA
    StreamSize  AS QUAD
    cStreamName AS WSTRINGZ * (%MAX_PATH + 36)
END TYPE

DECLARE FUNCTION FindFirstStreamW LIB "Kernel32.dll" _
    ALIAS "FindFirstStreamW" (lpFileName AS WSTRINGZ, _
    BYVAL InfoLevel AS STREAM_INFO_LEVELS_enum, _
    lpFindStreamData AS WIN32_FIND_STREAM_DATA, _
    BYVAL dwFlags AS DWORD) AS DWORD

#IF %WIN32_WINNT >= &H0600

DECLARE FUNCTION FindFirstStreamTransactedW LIB "Kernel32.dll" _
    ALIAS "FindFirstStreamTransactedW" (lpFileName AS WSTRINGZ, _
    BYVAL InfoLevel AS STREAM_INFO_LEVELS_enum, _
    lpFindStreamData AS WIN32_FIND_STREAM_DATA, _
    BYVAL dwFlags AS DWORD, BYVAL hTransaction AS DWORD) AS DWORD

#ENDIF ' %WIN32_WINNT >= &H600

DECLARE FUNCTION FindNextStreamW LIB "Kernel32.dll" _
    (BYVAL hFindStream AS DWORD, lpFindStreamData AS WIN32_FIND_STREAM_DATA) _
    AS LONG

#ENDIF ' (%WIN32_WINNT >= &H0501)

#IF %WIN32_WINNT >= &H0600

DECLARE FUNCTION FindFirstFileNameW LIB "Kernel32.dll" _
    ALIAS "FindFirstFileNameW" (lpFileName AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD, dStringLength AS DWORD, LinkName AS WSTRINGZ) _
    AS DWORD

DECLARE FUNCTION FindNextFileNameW LIB "Kernel32.dll" _
    ALIAS "FindNextFileNameW" (BYVAL hFindStream AS DWORD, _
    dStringLength AS DWORD, LinkName AS WSTRINGZ) AS LONG

DECLARE FUNCTION FindFirstFileNameTransactedW LIB "Kernel32.dll" _
    ALIAS "FindFirstFileNameTransactedW" (lpFileName AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD, dStringLength AS DWORD, LinkName AS WSTRINGZ, _
    BYVAL hTransaction AS DWORD) AS DWORD

#ENDIF


DECLARE FUNCTION CreateNamedPipeA LIB "Kernel32.dll" ALIAS "CreateNamedPipeA" _
    (lpName AS ASCIIZ, BYVAL dwOpenMode AS DWORD, BYVAL dwPipeMode AS DWORD, _
    BYVAL nMaxInstances AS DWORD, BYVAL nOutBufferSize AS DWORD, _
    BYVAL nInBufferSize AS DWORD, BYVAL nDefaultTimeOut AS DWORD, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES) AS DWORD

DECLARE FUNCTION CreateNamedPipeW LIB "Kernel32.dll" ALIAS "CreateNamedPipeW" _
    (lpName AS WSTRINGZ, BYVAL dwOpenMode AS DWORD, _
    BYVAL dwPipeMode AS DWORD, BYVAL nMaxInstances AS DWORD, _
    BYVAL nOutBufferSize AS DWORD, BYVAL nInBufferSize AS DWORD, _
    BYVAL nDefaultTimeOut AS DWORD, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateNamedPipe LIB "Kernel32.dll" ALIAS "CreateNamedPipeW" _
    (lpName AS WSTRINGZ, BYVAL dwOpenMode AS DWORD, _
    BYVAL dwPipeMode AS DWORD, BYVAL nMaxInstances AS DWORD, _
    BYVAL nOutBufferSize AS DWORD, BYVAL nInBufferSize AS DWORD, _
    BYVAL nDefaultTimeOut AS DWORD, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES) AS DWORD
#ELSE
DECLARE FUNCTION CreateNamedPipe LIB "Kernel32.dll" ALIAS "CreateNamedPipeA" _
    (lpName AS ASCIIZ, BYVAL dwOpenMode AS DWORD, BYVAL dwPipeMode AS DWORD, _
    BYVAL nMaxInstances AS DWORD, BYVAL nOutBufferSize AS DWORD, _
    BYVAL nInBufferSize AS DWORD, BYVAL nDefaultTimeOut AS DWORD, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetNamedPipeHandleStateA LIB "Kernel32.dll" _
    ALIAS "GetNamedPipeHandleStateA" (BYVAL hNamedPipe AS DWORD, _
    lpState AS DWORD, lpCurInstances AS DWORD, lpMaxCollectionCount AS DWORD, _
    lpCollectDataTimeout AS DWORD, lpUserName AS ASCIIZ, _
    BYVAL nMaxUserNameSize AS DWORD) AS LONG

DECLARE FUNCTION GetNamedPipeHandleStateW LIB "Kernel32.dll" _
    ALIAS "GetNamedPipeHandleStateW" (BYVAL hNamedPipe AS DWORD, _
    lpState AS DWORD, lpCurInstances AS DWORD, lpMaxCollectionCount AS DWORD, _
    lpCollectDataTimeout AS DWORD, lpUserName AS WSTRINGZ, _
    BYVAL nMaxUserNameSize AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetNamedPipeHandleState LIB "Kernel32.dll" _
    ALIAS "GetNamedPipeHandleStateW" (BYVAL hNamedPipe AS DWORD, _
    lpState AS DWORD, lpCurInstances AS DWORD, lpMaxCollectionCount AS DWORD, _
    lpCollectDataTimeout AS DWORD, lpUserName AS WSTRINGZ, _
    BYVAL nMaxUserNameSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetNamedPipeHandleState LIB "Kernel32.dll" _
    ALIAS "GetNamedPipeHandleStateA" (BYVAL hNamedPipe AS DWORD, _
    lpState AS DWORD, lpCurInstances AS DWORD, lpMaxCollectionCount AS DWORD, _
    lpCollectDataTimeout AS DWORD, lpUserName AS ASCIIZ, _
    BYVAL nMaxUserNameSize AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CallNamedPipeA LIB "Kernel32.dll" ALIAS "CallNamedPipeA" _
    (lpNamedPipeName AS ASCIIZ, BYVAL lpInBuffer AS DWORD, _
    BYVAL nInBufferSize AS DWORD, BYVAL lpOutBuffer AS DWORD, _
    BYVAL nOutBufferSize AS DWORD, lpBytesRead AS DWORD, _
    BYVAL nTimeOut AS DWORD) AS LONG

DECLARE FUNCTION CallNamedPipeW LIB "Kernel32.dll" ALIAS "CallNamedPipeW" _
    (lpNamedPipeName AS WSTRINGZ, BYVAL lpInBuffer AS DWORD, _
    BYVAL nInBufferSize AS DWORD, BYVAL lpOutBuffer AS DWORD, _
    BYVAL nOutBufferSize AS DWORD, lpBytesRead AS DWORD, _
    BYVAL nTimeOut AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CallNamedPipe LIB "Kernel32.dll" ALIAS "CallNamedPipeW" _
    (lpNamedPipeName AS WSTRINGZ, BYVAL lpInBuffer AS DWORD, _
    BYVAL nInBufferSize AS DWORD, BYVAL lpOutBuffer AS DWORD, _
    BYVAL nOutBufferSize AS DWORD, lpBytesRead AS DWORD, _
    BYVAL nTimeOut AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION CallNamedPipe LIB "Kernel32.dll" ALIAS "CallNamedPipeA" _
    (lpNamedPipeName AS ASCIIZ, BYVAL lpInBuffer AS DWORD, _
    BYVAL nInBufferSize AS DWORD, BYVAL lpOutBuffer AS DWORD, _
    BYVAL nOutBufferSize AS DWORD, lpBytesRead AS DWORD, _
    BYVAL nTimeOut AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION WaitNamedPipeA LIB "Kernel32.dll" ALIAS "WaitNamedPipeA" _
    (lpNamedPipeName AS ASCIIZ, BYVAL nTimeOut AS DWORD) AS LONG

DECLARE FUNCTION WaitNamedPipeW LIB "Kernel32.dll" ALIAS "WaitNamedPipeW" _
    (lpNamedPipeName AS WSTRINGZ, BYVAL nTimeOut AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION WaitNamedPipe LIB "Kernel32.dll" ALIAS "WaitNamedPipeW" _
    (lpNamedPipeName AS WSTRINGZ, BYVAL nTimeOut AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION WaitNamedPipe LIB "Kernel32.dll" ALIAS "WaitNamedPipeA" _
    (lpNamedPipeName AS ASCIIZ, BYVAL nTimeOut AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

MACRO PIPE_ATTRIBUTE_TYPE_enum=LONG
ENUM PIPE_ATTRIBUTE_TYPE SINGULAR
    PipeAttribute
    PipeConnectionAttribute
    PipeHandleAttribute
END ENUM

' [These functions are undocumented]
' ***
'WINBASEAPI
'BOOL
'WINAPI
'GetNamedPipeAttribute(
'    DWORD Pipe,
'    PIPE_ATTRIBUTE_TYPE AttributeType,
'    PSTR AttributeName,
'    __out_bcount(*AttributeValueLength) PVOID AttributeValue,
'    __inout PSIZE_T AttributeValueLength
'    );
'
'WINBASEAPI
'BOOL
'WINAPI
'SetNamedPipeAttribute(
'    DWORD Pipe,
'    PIPE_ATTRIBUTE_TYPE AttributeType,
'    PSTR AttributeName,
'    PVOID AttributeValue,
'    SIZE_T AttributeValueLength
'    );

DECLARE FUNCTION GetNamedPipeClientComputerNameA LIB "Kernel32.dll" _
    ALIAS "GetNamedPipeClientComputerNameA" (BYVAL hPipe AS DWORD, _
    ClientComputerName AS ASCIIZ, ClientComputerNameLength AS DWORD) AS LONG

DECLARE FUNCTION GetNamedPipeClientComputerNameW LIB "Kernel32.dll" _
    ALIAS "GetNamedPipeClientComputerNameW" (BYVAL hPipe AS DWORD, _
    ClientComputerName AS WSTRING, ClientComputerNameLength AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetNamedPipeClientComputerName LIB "Kernel32.dll" _
    ALIAS "GetNamedPipeClientComputerNameW" (BYVAL hPipe AS DWORD, _
    ClientComputerName AS WSTRING, ClientComputerNameLength AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetNamedPipeClientComputerName LIB "Kernel32.dll" _
    ALIAS "GetNamedPipeClientComputerNameA" (BYVAL hPipe AS DWORD, _
    ClientComputerName AS ASCIIZ, ClientComputerNameLength AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetNamedPipeClientProcessId LIB "Kernel32.dll" _
    ALIAS "GetNamedPipeClientProcessId" (BYVAL hPipe AS DWORD, _
    ClientProcessId AS DWORD) AS LONG

DECLARE FUNCTION GetNamedPipeClientSessionId LIB "Kernel32.dll" _
    ALIAS "GetNamedPipeClientSessionId" (BYVAL hPipe AS DWORD, _
    ClientSessionId AS DWORD) AS LONG

DECLARE FUNCTION GetNamedPipeServerProcessId LIB "Kernel32.dll" _
    ALIAS "GetNamedPipeServerProcessId" (BYVAL hPipe AS DWORD, _
    ServerProcessId AS DWORD) AS LONG

DECLARE FUNCTION GetNamedPipeServerSessionId LIB "Kernel32.dll" _
    ALIAS "GetNamedPipeServerSessionId" (BYVAL hPipe AS DWORD, _
    ServerSessionId AS DWORD) AS LONG

DECLARE FUNCTION SetVolumeLabelA LIB "Kernel32.dll" ALIAS "SetVolumeLabelA" _
    (lpRootPathName AS ASCIIZ, lpVolumeName AS ASCIIZ) AS LONG

DECLARE FUNCTION SetVolumeLabelW LIB "Kernel32.dll" ALIAS "SetVolumeLabelW" _
    (lpRootPathName AS WSTRINGZ, lpVolumeName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetVolumeLabel LIB "Kernel32.dll" ALIAS "SetVolumeLabelW" _
    (lpRootPathName AS WSTRINGZ, lpVolumeName AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION SetVolumeLabel LIB "Kernel32.dll" ALIAS "SetVolumeLabelA" _
    (lpRootPathName AS ASCIIZ, lpVolumeName AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE SUB SetFileApisToOEM LIB "Kernel32.dll" ALIAS "SetFileApisToOEM" ()
DECLARE SUB SetFileApisToANSI LIB "Kernel32.dll" ALIAS "SetFileApisToANSI" ()

DECLARE FUNCTION AreFileApisANSI LIB "Kernel32.dll" ALIAS "AreFileApisANSI" _
    () AS LONG

DECLARE FUNCTION GetVolumeInformationA LIB "Kernel32.dll" _
    ALIAS "GetVolumeInformationA" (lpRootPathName AS ASCIIZ, _
    lpVolumeNameBuffer AS ASCIIZ, BYVAL nVolumeNameSize AS DWORD, _
    lpVolumeSerialNumber AS DWORD, lpMaximumComponentLength AS DWORD, _
    lpFileSystemFlags AS DWORD, lpFileSystemNameBuffer AS ASCIIZ, _
    BYVAL nFileSystemNameSize AS DWORD) AS LONG

DECLARE FUNCTION GetVolumeInformationW LIB "Kernel32.dll" _
    ALIAS "GetVolumeInformationW" (lpRootPathName AS WSTRINGZ, _
    lpVolumeNameBuffer AS WSTRING, BYVAL nVolumeNameSize AS DWORD, _
    lpVolumeSerialNumber AS DWORD, lpMaximumComponentLength AS DWORD, _
    lpFileSystemFlags AS DWORD, lpFileSystemNameBuffer AS WSTRING, _
    BYVAL nFileSystemNameSize AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetVolumeInformation LIB "Kernel32.dll" _
    ALIAS "GetVolumeInformationW" (lpRootPathName AS WSTRINGZ, _
    lpVolumeNameBuffer AS WSTRING, BYVAL nVolumeNameSize AS DWORD, _
    lpVolumeSerialNumber AS DWORD, lpMaximumComponentLength AS DWORD, _
    lpFileSystemFlags AS DWORD, lpFileSystemNameBuffer AS WSTRING, _
    BYVAL nFileSystemNameSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetVolumeInformation LIB "Kernel32.dll" _
    ALIAS "GetVolumeInformationA" (lpRootPathName AS ASCIIZ, _
    lpVolumeNameBuffer AS ASCIIZ, BYVAL nVolumeNameSize AS DWORD, _
    lpVolumeSerialNumber AS DWORD, lpMaximumComponentLength AS DWORD, _
    lpFileSystemFlags AS DWORD, lpFileSystemNameBuffer AS ASCIIZ, _
    BYVAL nFileSystemNameSize AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

#IF (%WIN32_WINNT >= &H0600)

DECLARE FUNCTION GetVolumeInformationByHandleW LIB "Kernel32.dll" _
    ALIAS "GetVolumeInformationByHandleW" (BYVAL hFile AS DWORD, _
    lpVolumeNameBuffer AS WSTRING, BYVAL nVolumeNameSize AS DWORD, _
    lpVolumeSerialNumber AS DWORD, lpMaximumComponentLength AS DWORD, _
    lpFileSystemFlags AS DWORD, lpFileSystemNameBuffer AS WSTRING, _
    BYVAL nFileSystemNameSize AS DWORD) AS LONG

#ENDIF ' %WIN32_WINNT >=  &H0600

DECLARE FUNCTION CancelSynchronousIo LIB "Kernel32.dll" _
    ALIAS "CancelSynchronousIo" (BYVAL hThread AS DWORD) AS LONG

DECLARE FUNCTION CancelIoEx LIB "Kernel32.dll" ALIAS "CancelIoEx" _
    (BYVAL hFile AS DWORD, lpOverlapped AS OVERLAPPED) AS LONG

DECLARE FUNCTION CancelIo LIB "Kernel32.dll" ALIAS "CancelIo" _
    (BYVAL hFile AS DWORD) AS LONG

DECLARE FUNCTION SetFileBandwidthReservation LIB "Kernel32.dll" _
    ALIAS "SetFileBandwidthReservation" (BYVAL hFile AS DWORD, _
    BYVAL nPeriodMilliseconds AS DWORD, BYVAL nBytesPerPeriod AS DWORD, _
    BYVAL bDiscardable AS LONG, lpTransfersize AS DWORD, _
    lpNumOutstandingRequests AS DWORD) AS LONG

DECLARE FUNCTION GetFileBandwidthReservation LIB "Kernel32.dll" _
    ALIAS "GetFileBandwidthReservation" (BYVAL hFile AS DWORD, _
    lpPeriodMilliseconds AS DWORD, lpBytesPerPeriod AS DWORD, _
    pbDiscardable AS LONG, lpTransfersize AS DWORD, _
    lpNumOutstandingRequests AS DWORD) AS LONG

'
' Event logging APIs
'

DECLARE FUNCTION ClearEventLogA LIB "AdvApi32.dll" ALIAS "ClearEventLogA" _
    (BYVAL hEventLog AS DWORD, lpBackupFileName AS ASCIIZ) AS LONG

DECLARE FUNCTION ClearEventLogW LIB "AdvApi32.dll" ALIAS "ClearEventLogW" _
    (BYVAL hEventLog AS DWORD, lpBackupFileName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ClearEventLog LIB "AdvApi32.dll" ALIAS "ClearEventLogW" _
    (BYVAL hEventLog AS DWORD, lpBackupFileName AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION ClearEventLog LIB "AdvApi32.dll" ALIAS "ClearEventLogA" _
    (BYVAL hEventLog AS DWORD, lpBackupFileName AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION BackupEventLogA LIB "AdvApi32.dll" ALIAS "BackupEventLogA" _
    (BYVAL hEventLog AS DWORD, lpBackupFileName AS ASCIIZ) AS LONG

DECLARE FUNCTION BackupEventLogW LIB "AdvApi32.dll" ALIAS "BackupEventLogW" _
    (BYVAL hEventLog AS DWORD, lpBackupFileName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION BackupEventLog LIB "AdvApi32.dll" ALIAS "BackupEventLogW" _
    (BYVAL hEventLog AS DWORD, lpBackupFileName AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION BackupEventLog LIB "AdvApi32.dll" ALIAS "BackupEventLogA" _
    (BYVAL hEventLog AS DWORD, lpBackupFileName AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CloseEventLog LIB "AdvApi32.dll" ALIAS "CloseEventLog" _
    (BYVAL hEventLog AS DWORD) AS LONG

DECLARE FUNCTION DeregisterEventSource LIB "AdvApi32.dll" _
    ALIAS "DeregisterEventSource" (BYVAL hEventLog AS DWORD) AS LONG

DECLARE FUNCTION NotifyChangeEventLog LIB "AdvApi32.dll" _
    ALIAS "NotifyChangeEventLog" (BYVAL hEventLog AS DWORD, _
    BYVAL hEvent AS DWORD) AS LONG

DECLARE FUNCTION GetNumberOfEventLogRecords LIB "AdvApi32.dll" _
    ALIAS "GetNumberOfEventLogRecords" (BYVAL hEventLog AS DWORD, _
    NumberOfRecords AS DWORD) AS LONG

DECLARE FUNCTION GetOldestEventLogRecord LIB "AdvApi32.dll" _
    ALIAS "GetOldestEventLogRecord" (BYVAL hEventLog AS DWORD, _
    OldestRecord AS DWORD) AS LONG

DECLARE FUNCTION OpenEventLogA LIB "AdvApi32.dll" ALIAS "OpenEventLogA" _
    (lpUNCServerName AS ASCIIZ, lpSourceName AS ASCIIZ) AS DWORD

DECLARE FUNCTION OpenEventLogW LIB "AdvApi32.dll" ALIAS "OpenEventLogW" _
    (lpUNCServerName AS WSTRINGZ, lpSourceName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION OpenEventLog LIB "AdvApi32.dll" ALIAS "OpenEventLogW" _
    (lpUNCServerName AS WSTRINGZ, lpSourceName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION OpenEventLog LIB "AdvApi32.dll" ALIAS "OpenEventLogA" _
    (lpUNCServerName AS ASCIIZ, lpSourceName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegisterEventSourceA LIB "AdvApi32.dll" _
    ALIAS "RegisterEventSourceA" (lpUNCServerName AS ASCIIZ, _
    lpSourceName AS ASCIIZ) AS DWORD

DECLARE FUNCTION RegisterEventSourceW LIB "AdvApi32.dll" _
    ALIAS "RegisterEventSourceW" (lpUNCServerName AS WSTRINGZ, _
    lpSourceName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION RegisterEventSource LIB "AdvApi32.dll" _
    ALIAS "RegisterEventSourceW" (lpUNCServerName AS WSTRINGZ, _
    lpSourceName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION RegisterEventSource LIB "AdvApi32.dll" _
    ALIAS "RegisterEventSourceA" (lpUNCServerName AS ASCIIZ, _
    lpSourceName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION OpenBackupEventLogA LIB "AdvApi32.dll" _
    ALIAS "OpenBackupEventLogA" (lpUNCServerName AS ASCIIZ, _
    lpFileName AS ASCIIZ) AS DWORD

DECLARE FUNCTION OpenBackupEventLogW LIB "AdvApi32.dll" _
    ALIAS "OpenBackupEventLogW" (lpUNCServerName AS WSTRINGZ, _
    lpFileName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION OpenBackupEventLog LIB "AdvApi32.dll" _
    ALIAS "OpenBackupEventLogW" (lpUNCServerName AS WSTRINGZ, _
    lpFileName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION OpenBackupEventLog LIB "AdvApi32.dll" _
    ALIAS "OpenBackupEventLogA" (lpUNCServerName AS ASCIIZ, _
    lpFileName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION ReadEventLogA LIB "AdvApi32.dll" ALIAS "ReadEventLogA" _
    (BYVAL hEventLog AS DWORD, BYVAL dwReadFlags AS DWORD, _
    BYVAL dwRecordOffset AS DWORD, lpBuffer AS EVENTLOGRECORD, _
    BYVAL nNumberOfBytesToRead AS DWORD, pnBytesRead AS DWORD, _
    pnMinNumberOfBytesNeeded AS DWORD) AS LONG

DECLARE FUNCTION ReadEventLogW LIB "AdvApi32.dll" ALIAS "ReadEventLogW" _
    (BYVAL hEventLog AS DWORD, BYVAL dwReadFlags AS DWORD, _
    BYVAL dwRecordOffset AS DWORD, lpBuffer AS EVENTLOGRECORD, _
    BYVAL nNumberOfBytesToRead AS DWORD, pnBytesRead AS DWORD, _
    pnMinNumberOfBytesNeeded AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ReadEventLog LIB "AdvApi32.dll" ALIAS "ReadEventLogW" _
    (BYVAL hEventLog AS DWORD, BYVAL dwReadFlags AS DWORD, _
    BYVAL dwRecordOffset AS DWORD, lpBuffer AS EVENTLOGRECORD, _
    BYVAL nNumberOfBytesToRead AS DWORD, pnBytesRead AS DWORD, _
    pnMinNumberOfBytesNeeded AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION ReadEventLog LIB "AdvApi32.dll" ALIAS "ReadEventLogA" _
    (BYVAL hEventLog AS DWORD, BYVAL dwReadFlags AS DWORD, _
    BYVAL dwRecordOffset AS DWORD, lpBuffer AS EVENTLOGRECORD, _
    BYVAL nNumberOfBytesToRead AS DWORD, pnBytesRead AS DWORD, _
    pnMinNumberOfBytesNeeded AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION ReportEventA LIB "AdvApi32.dll" ALIAS "ReportEventA" _
    (BYVAL hEventLog AS DWORD, BYVAL wType AS WORD, BYVAL wCategory AS WORD, _
    BYVAL dwEventId AS DWORD, lpUserSid AS SID, BYVAL wNumStrings AS WORD, _
    BYVAL dwDataSize AS DWORD, BYVAL lpStrings AS DWORD, _
    BYVAL lpRawData AS DWORD) AS LONG

DECLARE FUNCTION ReportEventW LIB "AdvApi32.dll" ALIAS "ReportEventW" _
    (BYVAL hEventLog AS DWORD, BYVAL wType AS WORD, BYVAL wCategory AS WORD, _
    BYVAL dwEventId AS DWORD, lpUserSid AS SID, BYVAL wNumStrings AS WORD, _
    BYVAL dwDataSize AS DWORD, BYVAL lpStrings AS DWORD, _
    BYVAL lpRawData AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ReportEvent LIB "AdvApi32.dll" ALIAS "ReportEventW" _
    (BYVAL hEventLog AS DWORD, BYVAL wType AS WORD, BYVAL wCategory AS WORD, _
    BYVAL dwEventId AS DWORD, lpUserSid AS SID, BYVAL wNumStrings AS WORD, _
    BYVAL dwDataSize AS DWORD, BYVAL lpStrings AS DWORD, _
    BYVAL lpRawData AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION ReportEvent LIB "AdvApi32.dll" ALIAS "ReportEventA" _
    (BYVAL hEventLog AS DWORD, BYVAL wType AS WORD, BYVAL wCategory AS WORD, _
    BYVAL dwEventId AS DWORD, lpUserSid AS SID, BYVAL wNumStrings AS WORD, _
    BYVAL dwDataSize AS DWORD, BYVAL lpStrings AS DWORD, _
    BYVAL lpRawData AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE


%EVENTLOG_FULL_INFO    = 0

TYPE EVENTLOG_FULL_INFORMATION
    dwFull AS DWORD
END TYPE

DECLARE FUNCTION GetEventLogInformation LIB "AdvApi32.dll" _
    ALIAS "GetEventLogInformation" (BYVAL hEventLog AS DWORD, _
    BYVAL dwInfoLevel AS DWORD, lpBuffer AS EVENTLOG_FULL_INFORMATION, _
    BYVAL cbBufSize AS DWORD, pcbBytesNeeded AS DWORD) AS LONG

'
'
' Security APIs
'


DECLARE FUNCTION DuplicateToken LIB "AdvApi32.dll" ALIAS "DuplicateToken" _
    (BYVAL ExistingTokenHandle AS DWORD, ImpersonationLevel AS LONG, _
    DuplicateTokenHandle AS DWORD) AS LONG

DECLARE FUNCTION GetKernelObjectSecurity LIB "AdvApi32.dll" _
    ALIAS "GetKernelObjectSecurity" (BYVAL xHandle AS DWORD, _
    BYVAL RequestedInformation AS DWORD, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL nLength AS DWORD, _
    lpnLengthNeeded AS DWORD) AS LONG

DECLARE FUNCTION ImpersonateNamedPipeClient LIB "AdvApi32.dll" _
    ALIAS "ImpersonateNamedPipeClient" (BYVAL hNamedPipe AS DWORD) AS LONG

DECLARE FUNCTION ImpersonateSelf LIB "AdvApi32.dll" ALIAS "ImpersonateSelf" _
    (BYVAL ImpersonationLevel AS LONG) AS LONG

DECLARE FUNCTION RevertToSelf LIB "AdvApi32.dll" ALIAS "RevertToSelf" () _
    AS LONG

DECLARE FUNCTION SetThreadToken LIB "AdvApi32.dll" ALIAS "SetThreadToken" _
    (hThread AS DWORD, BYVAL Token AS DWORD) AS LONG

DECLARE FUNCTION AccessCheck LIB "AdvApi32.dll" ALIAS "AccessCheck" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL ClientToken AS DWORD, _
    BYVAL DesiredAccess AS DWORD, GenericMapping AS GENERIC_MAPPING, _
    BYVAL PrivilegeSet AS DWORD, PrivilegeSetLength AS DWORD, _
    GrantedAccess AS DWORD, AccessStatus AS LONG) AS LONG

#IF (%WIN32_WINNT >= &H0500)

DECLARE FUNCTION AccessCheckByType LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByType" (pSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    PrincipalSelfSid AS SID, BYVAL ClientToken AS DWORD, _
    BYVAL DesiredAccess AS DWORD, _
    BYVAL ObjectTypeList AS OBJECT_TYPE_LIST PTR, _
    BYVAL ObjectTypeListLength AS DWORD, GenericMapping AS GENERIC_MAPPING, _
    BYVAL PrivilegeSet AS DWORD, PrivilegeSetLength AS DWORD, _
    GrantedAccess AS DWORD, AccessStatus AS LONG) AS LONG

DECLARE FUNCTION AccessCheckByTypeResultList LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByTypeResultList" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    PrincipalSelfSid AS SID, BYVAL ClientToken AS DWORD, _
    BYVAL DesiredAccess AS DWORD, _
    BYVAL ObjectTypeList AS OBJECT_TYPE_LIST PTR, _
    BYVAL ObjectTypeListLength AS DWORD, GenericMapping AS GENERIC_MAPPING, _
    BYVAL PrivilegeSet AS DWORD, PrivilegeSetLength AS DWORD, _
    GrantedAccess AS DWORD, AccessStatusList AS DWORD) AS LONG

#ENDIF ' %WIN32_WINNT >=  &H0500


DECLARE FUNCTION OpenProcessToken LIB "AdvApi32.dll" ALIAS "OpenProcessToken" _
    (BYVAL ProcessHandle AS DWORD, BYVAL DesiredAccess AS DWORD, _
    TokenHandle AS DWORD) AS LONG

DECLARE FUNCTION OpenThreadToken LIB "AdvApi32.dll" ALIAS "OpenThreadToken" _
    (BYVAL ThreadHandle AS DWORD, BYVAL DesiredAccess AS DWORD, _
    BYVAL OpenAsSelf AS LONG, TokenHandle AS DWORD) AS LONG

DECLARE FUNCTION GetTokenInformation LIB "AdvApi32.dll" _
    ALIAS "GetTokenInformation" (BYVAL TokenHandle AS DWORD, _
    BYVAL TokenInformationClass AS LONG, BYVAL TokenInformation AS DWORD, _
    BYVAL TokenInformationLength AS DWORD, ReturnLength AS DWORD) AS LONG

DECLARE FUNCTION SetTokenInformation LIB "AdvApi32.dll" _
    ALIAS "SetTokenInformation" (BYVAL TokenHandle AS DWORD, _
    BYVAL TokenInformationClass AS LONG, BYVAL TokenInformation AS DWORD, _
    BYVAL TokenInformationLength AS DWORD) AS LONG

DECLARE FUNCTION AdjustTokenPrivileges LIB "AdvApi32.dll" _
    ALIAS "AdjustTokenPrivileges" (BYVAL TokenHandle AS DWORD, _
    BYVAL DisableAllPrivileges AS LONG, BYVAL NewState AS DWORD, _
    BYVAL BufferLength AS DWORD, BYVAL PreviousState AS DWORD, _
    ReturnLength AS DWORD) AS LONG

DECLARE FUNCTION AdjustTokenGroups LIB "AdvApi32.dll" _
    ALIAS "AdjustTokenGroups" (BYVAL TokenHandle AS DWORD, _
    BYVAL ResetToDefault AS LONG, BYVAL NewState AS DWORD, _
    BYVAL BufferLength AS DWORD, BYVAL PreviousState AS DWORD, _
    ReturnLength AS DWORD) AS LONG

DECLARE FUNCTION PrivilegeCheck LIB "AdvApi32.dll" ALIAS "PrivilegeCheck" _
    (BYVAL ClientToken AS LONG, BYVAL RequiredPrivileges AS DWORD, _
    pfResult AS LONG) AS LONG

DECLARE FUNCTION AccessCheckAndAuditAlarmA LIB "AdvApi32.dll" _
    ALIAS "AccessCheckAndAuditAlarmA" (SubsystemName AS ASCIIZ, _
    HandleId AS DWORD, ObjectTypeName AS ASCIIZ, ObjectName AS ASCIIZ, _
    SecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL DesiredAccess AS DWORD, _
    GenericMapping AS GENERIC_MAPPING, BYVAL ObjectCreation AS LONG, _
    GrantedAccess AS DWORD, BYVAL AccessStatus AS LONG, _
    BYVAL pfGenerateOnClose AS LONG) AS LONG

DECLARE FUNCTION AccessCheckAndAuditAlarmW LIB "AdvApi32.dll" _
    ALIAS "AccessCheckAndAuditAlarmW" (SubsystemName AS WSTRINGZ, _
    HandleId AS DWORD, ObjectTypeName AS WSTRINGZ, ObjectName AS WSTRINGZ, _
    SecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL DesiredAccess AS DWORD, _
    GenericMapping AS GENERIC_MAPPING, BYVAL ObjectCreation AS LONG, _
    GrantedAccess AS DWORD, BYVAL AccessStatus AS LONG, _
    BYVAL pfGenerateOnClose AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION AccessCheckAndAuditAlarm LIB "AdvApi32.dll" _
    ALIAS "AccessCheckAndAuditAlarmW" (SubsystemName AS WSTRINGZ, _
    HandleId AS DWORD, ObjectTypeName AS WSTRINGZ, ObjectName AS WSTRINGZ, _
    SecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL DesiredAccess AS DWORD, _
    GenericMapping AS GENERIC_MAPPING, BYVAL ObjectCreation AS LONG, _
    GrantedAccess AS DWORD, BYVAL AccessStatus AS LONG, _
    BYVAL pfGenerateOnClose AS LONG) AS LONG
#ELSE
DECLARE FUNCTION AccessCheckAndAuditAlarm LIB "AdvApi32.dll" _
    ALIAS "AccessCheckAndAuditAlarmA" (SubsystemName AS ASCIIZ, _
    HandleId AS DWORD, ObjectTypeName AS ASCIIZ, ObjectName AS ASCIIZ, _
    SecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL DesiredAccess AS DWORD, _
    GenericMapping AS GENERIC_MAPPING, BYVAL ObjectCreation AS LONG, _
    GrantedAccess AS DWORD, BYVAL AccessStatus AS LONG, _
    BYVAL pfGenerateOnClose AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

#IF (%WIN32_WINNT >= &H0500)

DECLARE FUNCTION AccessCheckByTypeAndAuditAlarmA LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByTypeAndAuditAlarmA" (SubsystemName AS ASCIIZ, _
    HandleId AS DWORD, ObjectTypeName AS ASCIIZ, ObjectName AS ASCIIZ, _
    SecurityDescriptor AS SECURITY_DESCRIPTOR, PrincipalSelfSid AS SID, _
    BYVAL DesiredAccess AS DWORD, BYVAL AuditType AS LONG, _
    BYVAL Flags AS DWORD, ObjectTypeList AS OBJECT_TYPE_LIST, _
    BYVAL ObjectTypeListLength AS DWORD, GenericMapping AS GENERIC_MAPPING, _
    BYVAL ObjectCreation AS LONG, GrantedAccess AS DWORD, _
    AccessStatus AS LONG, pfGenerateOnClose AS LONG) AS LONG

DECLARE FUNCTION AccessCheckByTypeAndAuditAlarmW LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByTypeAndAuditAlarmW" (SubsystemName AS WSTRINGZ, _
    HandleId AS DWORD, ObjectTypeName AS WSTRINGZ, ObjectName AS WSTRINGZ, _
    SecurityDescriptor AS SECURITY_DESCRIPTOR, PrincipalSelfSid AS SID, _
    BYVAL DesiredAccess AS DWORD, BYVAL AuditType AS LONG, _
    BYVAL Flags AS DWORD, ObjectTypeList AS OBJECT_TYPE_LIST, _
    BYVAL ObjectTypeListLength AS DWORD, GenericMapping AS GENERIC_MAPPING, _
    BYVAL ObjectCreation AS LONG, GrantedAccess AS DWORD, _
    AccessStatus AS LONG, pfGenerateOnClose AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION AccessCheckByTypeAndAuditAlarm LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByTypeAndAuditAlarmW" (SubsystemName AS WSTRINGZ, _
    HandleId AS DWORD, ObjectTypeName AS WSTRINGZ, ObjectName AS WSTRINGZ, _
    SecurityDescriptor AS SECURITY_DESCRIPTOR, PrincipalSelfSid AS SID, _
    BYVAL DesiredAccess AS DWORD, BYVAL AuditType AS LONG, _
    BYVAL Flags AS DWORD, ObjectTypeList AS OBJECT_TYPE_LIST, _
    BYVAL ObjectTypeListLength AS DWORD, GenericMapping AS GENERIC_MAPPING, _
    BYVAL ObjectCreation AS LONG, GrantedAccess AS DWORD, _
    AccessStatus AS LONG, pfGenerateOnClose AS LONG) AS LONG
#ELSE
DECLARE FUNCTION AccessCheckByTypeAndAuditAlarm LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByTypeAndAuditAlarmA" (SubsystemName AS ASCIIZ, _
    HandleId AS DWORD, ObjectTypeName AS ASCIIZ, ObjectName AS ASCIIZ, _
    SecurityDescriptor AS SECURITY_DESCRIPTOR, PrincipalSelfSid AS SID, _
    BYVAL DesiredAccess AS DWORD, BYVAL AuditType AS LONG, _
    BYVAL Flags AS DWORD, ObjectTypeList AS OBJECT_TYPE_LIST, _
    BYVAL ObjectTypeListLength AS DWORD, GenericMapping AS GENERIC_MAPPING, _
    BYVAL ObjectCreation AS LONG, GrantedAccess AS DWORD, _
    AccessStatus AS LONG, pfGenerateOnClose AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION AccessCheckByTypeResultListAndAuditAlarmA LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByTypeResultListAndAuditAlarmA" _
    (SubsystemName AS ASCIIZ, HandleId AS DWORD, ObjectTypeName AS ASCIIZ, _
    ObjectName AS ASCIIZ, SecurityDescriptor AS SECURITY_DESCRIPTOR, _
    PrincipalSelfSid AS SID, BYVAL DesiredAccess AS DWORD, _
    BYVAL AuditType AS LONG, BYVAL Flags AS DWORD, _
    ObjectTypeList AS OBJECT_TYPE_LIST, GenericMapping AS GENERIC_MAPPING, _
    BYVAL ObjectCreation AS LONG, GrantedAccess AS DWORD, _
    AccessStatusList AS DWORD, pfGenerateOnClose AS LONG) AS LONG

DECLARE FUNCTION AccessCheckByTypeResultListAndAuditAlarmW LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByTypeResultListAndAuditAlarmW" _
    (SubsystemName AS WSTRINGZ, HandleId AS DWORD, _
    ObjectTypeName AS WSTRINGZ, ObjectName AS WSTRINGZ, _
    SecurityDescriptor AS SECURITY_DESCRIPTOR, PrincipalSelfSid AS SID, _
    BYVAL DesiredAccess AS DWORD, BYVAL AuditType AS LONG, _
    BYVAL Flags AS DWORD, ObjectTypeList AS OBJECT_TYPE_LIST, _
    GenericMapping AS GENERIC_MAPPING, BYVAL ObjectCreation AS LONG, _
    GrantedAccess AS DWORD, AccessStatusList AS DWORD, _
    pfGenerateOnClose AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION AccessCheckByTypeResultListAndAuditAlarm LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByTypeResultListAndAuditAlarmW" _
    (SubsystemName AS WSTRINGZ, HandleId AS DWORD, _
    ObjectTypeName AS WSTRINGZ, ObjectName AS WSTRINGZ, _
    SecurityDescriptor AS SECURITY_DESCRIPTOR, PrincipalSelfSid AS SID, _
    BYVAL DesiredAccess AS DWORD, BYVAL AuditType AS LONG, _
    BYVAL Flags AS DWORD, ObjectTypeList AS OBJECT_TYPE_LIST, _
    GenericMapping AS GENERIC_MAPPING, BYVAL ObjectCreation AS LONG, _
    GrantedAccess AS DWORD, AccessStatusList AS DWORD, _
    pfGenerateOnClose AS LONG) AS LONG
#ELSE
DECLARE FUNCTION AccessCheckByTypeResultListAndAuditAlarm LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByTypeResultListAndAuditAlarmA" _
    (SubsystemName AS ASCIIZ, HandleId AS DWORD, ObjectTypeName AS ASCIIZ, _
    ObjectName AS ASCIIZ, SecurityDescriptor AS SECURITY_DESCRIPTOR, _
    PrincipalSelfSid AS SID, BYVAL DesiredAccess AS DWORD, _
    BYVAL AuditType AS LONG, BYVAL Flags AS DWORD, _
    ObjectTypeList AS OBJECT_TYPE_LIST, GenericMapping AS GENERIC_MAPPING, _
    BYVAL ObjectCreation AS LONG, GrantedAccess AS DWORD, _
    AccessStatusList AS DWORD, pfGenerateOnClose AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION AccessCheckByTypeResultListAndAuditAlarmByHandleA _
    LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByTypeResultListAndAuditAlarmByHandleA" _
    (SubsystemName AS ASCIIZ, HandleId AS DWORD, BYVAL ClientToken AS DWORD, _
    ObjectTypeName AS ASCIIZ, ObjectName AS ASCIIZ, _
    SecurityDescriptor AS SECURITY_DESCRIPTOR, _
    PrincipalSelfSid AS SID, BYVAL DesiredAccess AS DWORD, _
    BYVAL AuditType AS LONG, BYVAL Flags AS DWORD, _
    ObjectTypeList AS OBJECT_TYPE_LIST, BYVAL ObjectTypeListLength AS DWORD, _
    BYVAL GenericMapping AS GENERIC_MAPPING, BYVAL ObjectCreation AS LONG, _
    GrantedAccess AS DWORD, AccessStatusList AS DWORD, _
    pfGenerateOnClose AS LONG) AS LONG

DECLARE FUNCTION AccessCheckByTypeResultListAndAuditAlarmByHandleW _
    LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByTypeResultListAndAuditAlarmByHandleW" _
    (SubsystemName AS WSTRINGZ, HandleId AS DWORD, _
    BYVAL ClientToken AS DWORD, ObjectTypeName AS WSTRINGZ, _
    ObjectName AS WSTRINGZ, SecurityDescriptor AS SECURITY_DESCRIPTOR, _
    PrincipalSelfSid AS SID, BYVAL DesiredAccess AS DWORD, _
    BYVAL AuditType AS LONG, BYVAL Flags AS DWORD, _
    ObjectTypeList AS OBJECT_TYPE_LIST, BYVAL ObjectTypeListLength AS DWORD, _
    BYVAL GenericMapping AS GENERIC_MAPPING, BYVAL ObjectCreation AS LONG, _
    GrantedAccess AS DWORD, AccessStatusList AS DWORD, _
    pfGenerateOnClose AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION AccessCheckByTypeResultListAndAuditAlarmByHandle _
    LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByTypeResultListAndAuditAlarmByHandleW" _
    (SubsystemName AS WSTRINGZ, HandleId AS DWORD, _
    BYVAL ClientToken AS DWORD, ObjectTypeName AS WSTRINGZ, _
    ObjectName AS WSTRINGZ, SecurityDescriptor AS SECURITY_DESCRIPTOR, _
    PrincipalSelfSid AS SID, BYVAL DesiredAccess AS DWORD, _
    BYVAL AuditType AS LONG, BYVAL Flags AS DWORD, _
    ObjectTypeList AS OBJECT_TYPE_LIST, BYVAL ObjectTypeListLength AS DWORD, _
    BYVAL GenericMapping AS GENERIC_MAPPING, BYVAL ObjectCreation AS LONG, _
    GrantedAccess AS DWORD, AccessStatusList AS DWORD, _
    pfGenerateOnClose AS LONG) AS LONG
#ELSE
DECLARE FUNCTION AccessCheckByTypeResultListAndAuditAlarmByHandle _
    LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByTypeResultListAndAuditAlarmByHandleA" _
    (SubsystemName AS ASCIIZ, HandleId AS DWORD, BYVAL ClientToken AS DWORD, _
    ObjectTypeName AS ASCIIZ, ObjectName AS ASCIIZ, _
    SecurityDescriptor AS SECURITY_DESCRIPTOR, _
    PrincipalSelfSid AS SID, BYVAL DesiredAccess AS DWORD, _
    BYVAL AuditType AS LONG, BYVAL Flags AS DWORD, _
    ObjectTypeList AS OBJECT_TYPE_LIST, BYVAL ObjectTypeListLength AS DWORD, _
    BYVAL GenericMapping AS GENERIC_MAPPING, BYVAL ObjectCreation AS LONG, _
    GrantedAccess AS DWORD, AccessStatusList AS DWORD, _
    pfGenerateOnClose AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF '(%WIN32_WINNT >= &H0500)

DECLARE FUNCTION ObjectOpenAuditAlarmA LIB "AdvApi32.dll" _
    ALIAS "ObjectOpenAuditAlarmA" (SubsystemName AS ASCIIZ, _
    HandleId AS DWORD, ObjectTypeName AS ASCIIZ, ObjectName AS ASCIIZ, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL ClientToken AS LONG, _
    BYVAL DesiredAccess AS LONG, BYVAL GrantedAccess AS LONG, _
    BYVAL Privileges AS DWORD, BYVAL ObjectCreation AS LONG, _
    BYVAL AccessGranted AS LONG, GenerateOnClose AS LONG) AS LONG

DECLARE FUNCTION ObjectOpenAuditAlarmW LIB "AdvApi32.dll" _
    ALIAS "ObjectOpenAuditAlarmW" (SubsystemName AS WSTRINGZ, _
    HandleId AS DWORD, ObjectTypeName AS WSTRINGZ, ObjectName AS WSTRINGZ, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL ClientToken AS LONG, _
    BYVAL DesiredAccess AS LONG, BYVAL GrantedAccess AS LONG, _
    BYVAL Privileges AS DWORD, BYVAL ObjectCreation AS LONG, _
    BYVAL AccessGranted AS LONG, GenerateOnClose AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ObjectOpenAuditAlarm LIB "AdvApi32.dll" _
    ALIAS "ObjectOpenAuditAlarmW" (SubsystemName AS WSTRINGZ, _
    HandleId AS DWORD, ObjectTypeName AS WSTRINGZ, ObjectName AS WSTRINGZ, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL ClientToken AS LONG, _
    BYVAL DesiredAccess AS LONG, BYVAL GrantedAccess AS LONG, _
    BYVAL Privileges AS DWORD, BYVAL ObjectCreation AS LONG, _
    BYVAL AccessGranted AS LONG, GenerateOnClose AS LONG) AS LONG
#ELSE
DECLARE FUNCTION ObjectOpenAuditAlarm LIB "AdvApi32.dll" _
    ALIAS "ObjectOpenAuditAlarmA" (SubsystemName AS ASCIIZ, _
    HandleId AS DWORD, ObjectTypeName AS ASCIIZ, ObjectName AS ASCIIZ, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL ClientToken AS LONG, _
    BYVAL DesiredAccess AS LONG, BYVAL GrantedAccess AS LONG, _
    BYVAL Privileges AS DWORD, BYVAL ObjectCreation AS LONG, _
    BYVAL AccessGranted AS LONG, GenerateOnClose AS LONG) AS LONG
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION ObjectPrivilegeAuditAlarmA LIB "AdvApi32.dll" _
    ALIAS "ObjectPrivilegeAuditAlarmA" (SubsystemName AS ASCIIZ, _
    HandleId AS DWORD, BYVAL ClientToken AS DWORD, _
    BYVAL DesiredAccess AS DWORD, BYVAL Privileges AS DWORD, _
    BYVAL AccessGranted AS LONG) AS LONG

DECLARE FUNCTION ObjectPrivilegeAuditAlarmW LIB "AdvApi32.dll" _
    ALIAS "ObjectPrivilegeAuditAlarmW" (SubsystemName AS WSTRINGZ, _
    HandleId AS DWORD, BYVAL ClientToken AS DWORD, _
    BYVAL DesiredAccess AS DWORD, BYVAL Privileges AS DWORD, _
    BYVAL AccessGranted AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ObjectPrivilegeAuditAlarm LIB "AdvApi32.dll" _
    ALIAS "ObjectPrivilegeAuditAlarmW" (SubsystemName AS WSTRINGZ, _
    HandleId AS DWORD, BYVAL ClientToken AS DWORD, _
    BYVAL DesiredAccess AS DWORD, BYVAL Privileges AS DWORD, _
    BYVAL AccessGranted AS LONG) AS LONG
#ELSE
DECLARE FUNCTION ObjectPrivilegeAuditAlarm LIB "AdvApi32.dll" _
    ALIAS "ObjectPrivilegeAuditAlarmA" (SubsystemName AS ASCIIZ, _
    HandleId AS DWORD, BYVAL ClientToken AS DWORD, _
    BYVAL DesiredAccess AS DWORD, BYVAL Privileges AS DWORD, _
    BYVAL AccessGranted AS LONG) AS LONG
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION ObjectCloseAuditAlarmA LIB "AdvApi32.dll" _
    ALIAS "ObjectCloseAuditAlarmA" (SubsystemName AS ASCIIZ, _
    HandleId AS DWORD, BYVAL GenerateOnClose AS LONG) AS LONG

DECLARE FUNCTION ObjectCloseAuditAlarmW LIB "AdvApi32.dll" _
    ALIAS "ObjectCloseAuditAlarmW" (SubsystemName AS WSTRINGZ, _
    HandleId AS DWORD, BYVAL GenerateOnClose AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ObjectCloseAuditAlarm LIB "AdvApi32.dll" _
    ALIAS "ObjectCloseAuditAlarmW" (SubsystemName AS WSTRINGZ, _
    HandleId AS DWORD, BYVAL GenerateOnClose AS LONG) AS LONG
#ELSE
DECLARE FUNCTION ObjectCloseAuditAlarm LIB "AdvApi32.dll" _
    ALIAS "ObjectCloseAuditAlarmA" (SubsystemName AS ASCIIZ, _
    HandleId AS DWORD, BYVAL GenerateOnClose AS LONG) AS LONG
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION ObjectDeleteAuditAlarmA LIB "AdvApi32.dll" _
    ALIAS "ObjectDeleteAuditAlarmA" (SubsystemName AS ASCIIZ, _
    HandleId AS DWORD, BYVAL GenerateOnClose AS LONG) AS LONG

DECLARE FUNCTION ObjectDeleteAuditAlarmW LIB "AdvApi32.dll" _
    ALIAS "ObjectDeleteAuditAlarmW" (SubsystemName AS WSTRINGZ, _
    HandleId AS DWORD, BYVAL GenerateOnClose AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ObjectDeleteAuditAlarm LIB "AdvApi32.dll" _
    ALIAS "ObjectDeleteAuditAlarmW" (SubsystemName AS WSTRINGZ, _
    HandleId AS DWORD, BYVAL GenerateOnClose AS LONG) AS LONG
#ELSE
DECLARE FUNCTION ObjectDeleteAuditAlarm LIB "AdvApi32.dll" _
    ALIAS "ObjectDeleteAuditAlarmA" (SubsystemName AS ASCIIZ, _
    HandleId AS DWORD, BYVAL GenerateOnClose AS LONG) AS LONG
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION PrivilegedServiceAuditAlarmA LIB "AdvApi32.dll" _
    ALIAS "PrivilegedServiceAuditAlarmA" (SubsystemName AS ASCIIZ, _
    ServiceName AS ASCIIZ, BYVAL ClientToken AS DWORD, _
    BYVAL Privileges AS DWORD, BYVAL AccessGranted AS LONG) AS LONG

DECLARE FUNCTION PrivilegedServiceAuditAlarmW LIB "AdvApi32.dll" _
    ALIAS "PrivilegedServiceAuditAlarmW" (SubsystemName AS WSTRINGZ, _
    ServiceName AS WSTRINGZ, BYVAL ClientToken AS DWORD, _
    BYVAL Privileges AS DWORD, BYVAL AccessGranted AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION PrivilegedServiceAuditAlarm LIB "AdvApi32.dll" _
    ALIAS "PrivilegedServiceAuditAlarmW" (SubsystemName AS WSTRINGZ, _
    ServiceName AS WSTRINGZ, BYVAL ClientToken AS DWORD, _
    BYVAL Privileges AS DWORD, BYVAL AccessGranted AS LONG) AS LONG
#ELSE
DECLARE FUNCTION PrivilegedServiceAuditAlarm LIB "AdvApi32.dll" _
    ALIAS "PrivilegedServiceAuditAlarmA" (SubsystemName AS ASCIIZ, _
    ServiceName AS ASCIIZ, BYVAL ClientToken AS DWORD, _
    BYVAL Privileges AS DWORD, BYVAL AccessGranted AS LONG) AS LONG
#ENDIF ' NOT %UNICODE



#IF (%WIN32_WINNT >= &H0501)


DECLARE FUNCTION IsWellKnownSid LIB "AdvApi32.dll" ALIAS "IsWellKnownSid" _
    (pSid AS SID, BYVAL WellKnownSidType AS LONG) AS LONG

DECLARE FUNCTION CreateWellKnownSid LIB "AdvApi32.dll" _
    ALIAS "CreateWellKnownSid" (BYVAL WellKnownSidType AS LONG, _
    DomainSid AS SID, pSid AS SID, cbSid AS DWORD) AS LONG

DECLARE FUNCTION EqualDomainSid LIB "AdvApi32.dll" _
    ALIAS "EqualDomainSid" (pSid1 AS SID, pSid2 AS SID, pfEqual AS LONG) _
    AS LONG

DECLARE FUNCTION GetWindowsAccountDomainSid LIB "AdvApi32.dll" _
    ALIAS "GetWindowsAccountDomainSid" (pSid AS SID, pDomainSid AS SID, _
    cbDomainSid AS DWORD) AS LONG

#ENDIF '(%WIN32_WINNT >= &H0501)

DECLARE FUNCTION IsValidSid LIB "AdvApi32.dll" ALIAS "IsValidSid" _
    (pSid AS SID) AS LONG

DECLARE FUNCTION EqualSid LIB "AdvApi32.dll" ALIAS "EqualSid" _
    (pSid1 AS SID, pSid2 AS SID) AS LONG

DECLARE FUNCTION EqualPrefixSid LIB "AdvApi32.dll" ALIAS "EqualPrefixSid" _
    (pSid1 AS SID, pSid2 AS SID) AS LONG

DECLARE FUNCTION GetSidLengthRequired LIB "AdvApi32.dll" _
    ALIAS "GetSidLengthRequired" (BYVAL nSubAuthorityCount AS BYTE) AS DWORD

DECLARE FUNCTION AllocateAndInitializeSid LIB "AdvApi32.dll" _
    ALIAS "AllocateAndInitializeSid" _
    (pIdentifierAuthority AS SID_IDENTIFIER_AUTHORITY, _
    BYVAL nSubAuthorityCount AS BYTE, BYVAL nSubAuthority0 AS DWORD, _
    BYVAL nSubAuthority1 AS DWORD, BYVAL nSubAuthority2 AS DWORD, _
    BYVAL nSubAuthority3 AS DWORD, BYVAL nSubAuthority4 AS DWORD, _
    BYVAL nSubAuthority5 AS DWORD, BYVAL nSubAuthority6 AS DWORD, _
    BYVAL nSubAuthority7 AS DWORD, lpPSid AS DWORD) AS LONG

DECLARE SUB FreeSid LIB "AdvApi32.dll" ALIAS "FreeSid" (pSid AS SID)

DECLARE FUNCTION InitializeSid LIB "AdvApi32.dll" ALIAS "InitializeSid" _
    (pSid AS SID, pIdentifierAuthority AS SID_IDENTIFIER_AUTHORITY, _
    BYVAL nSubAuthorityCount AS BYTE) AS LONG

DECLARE FUNCTION GetSidIdentifierAuthority LIB "AdvApi32.dll" _
    ALIAS "GetSidIdentifierAuthority" (pSid AS SID) AS DWORD

DECLARE FUNCTION GetSidSubAuthority LIB "AdvApi32.dll" _
    ALIAS "GetSidSubAuthority" (dwFlags AS DWORD, _
    BYVAL nSubAuthority AS DWORD) AS DWORD

DECLARE FUNCTION GetSidSubAuthorityCount LIB "AdvApi32.dll" _
    ALIAS "GetSidSubAuthorityCount" (pSid AS SID) AS DWORD

DECLARE FUNCTION GetLengthSid LIB "AdvApi32.dll" ALIAS "GetLengthSid" _
    (pSid AS SID) AS DWORD

DECLARE FUNCTION CopySid LIB "AdvApi32.dll" ALIAS "CopySid" _
    (BYVAL nDestinationSidLength AS DWORD, pDestinationSid AS SID, _
    pSourceSid AS SID) AS LONG

DECLARE FUNCTION AreAllAccessesGranted LIB "AdvApi32.dll" _
    ALIAS "AreAllAccessesGranted" (BYVAL GrantedAccess AS DWORD, _
    BYVAL DesiredAccess AS DWORD) AS LONG

DECLARE FUNCTION AreAnyAccessesGranted LIB "AdvApi32.dll" _
    ALIAS "AreAnyAccessesGranted" (BYVAL GrantedAccess AS DWORD, _
    BYVAL DesiredAccess AS DWORD) AS LONG

DECLARE SUB MapGenericMask LIB "AdvApi32.dll" ALIAS "MapGenericMask" _
    (AccessMask AS DWORD, GenericMapping AS GENERIC_MAPPING)

DECLARE FUNCTION IsValidAcl LIB "AdvApi32.dll" ALIAS "IsValidAcl" _
    (pAcl AS ACL) AS LONG

DECLARE FUNCTION InitializeAcl LIB "AdvApi32.dll" ALIAS "InitializeAcl" _
    (pAcl AS ACL, BYVAL nAclLength AS DWORD, BYVAL dwAclRevision AS DWORD) _
    AS LONG

DECLARE FUNCTION GetAclInformation LIB "AdvApi32.dll" _
    ALIAS "GetAclInformation" (pAcl AS ACL, BYVAL pAclInformation AS DWORD, _
    BYVAL nAclInformationLength AS DWORD, _
    BYVAL dwAclInformationClass AS DWORD) AS LONG

DECLARE FUNCTION SetAclInformation LIB "AdvApi32.dll" _
    ALIAS "SetAclInformation" (pAcl AS ACL, BYVAL pAclInformation AS DWORD, _
    BYVAL nAclInformationLength AS DWORD, _
    BYVAL dwAclInformationClass AS DWORD) AS LONG

DECLARE FUNCTION AddAce LIB "AdvApi32.dll" ALIAS "AddAce" _
    (pAcl AS ACL, BYVAL dwAceRevision AS DWORD, _
    BYVAL dwStartingAceIndex AS DWORD, BYVAL pAceList AS DWORD, _
    BYVAL nAceListLength AS DWORD) AS LONG

DECLARE FUNCTION DeleteAce LIB "AdvApi32.dll" ALIAS "DeleteAce" _
    (pAcl AS ACL, BYVAL dwAceIndex AS DWORD) AS LONG

DECLARE FUNCTION GetAce LIB "AdvApi32.dll" ALIAS "GetAce" _
    (pAcl AS ACL, BYVAL dwAceIndex AS DWORD, BYVAL pAce AS DWORD) AS LONG

DECLARE FUNCTION AddAccessAllowedAce LIB "AdvApi32.dll" _
    ALIAS "AddAccessAllowedAce" (pAcl AS ACL, BYVAL dwAceRevision AS DWORD, _
    BYVAL AccessMask AS DWORD, dwFlags AS DWORD) AS LONG

#IF (%WIN32_WINNT >= &H0500)

DECLARE FUNCTION AddAccessAllowedAceEx LIB "AdvApi32.dll" _
    ALIAS "AddAccessAllowedAceEx" (pAcl AS ACL, BYVAL dwAceRevision AS DWORD, _
    BYVAL AceFlags AS DWORD, BYVAL AccessMask AS DWORD, pSid AS SID) AS LONG

#ENDIF ' %WIN32_WINNT >=  &H0500

#IF (%WIN32_WINNT >= &H0600)

DECLARE FUNCTION AddMandatoryAce LIB "AdvApi32.dll" ALIAS "AddMandatoryAce" ( _
    pAcl AS ACL, BYVAL dwAceRevision AS DWORD, BYVAL AceFlags AS DWORD, _
    BYVAL MandatoryPolicy AS DWORD, pLabelSid AS SID) AS LONG

#ENDIF ' %WIN32_WINNT >=  &H0600

#IF (%WIN32_WINNT >= &H0601)

DECLARE FUNCTION AddConditionalAce LIB "AdvApi32.dll" _
    ALIAS "AddConditionalAce" ( _
    pAcl                AS ACL, _
    BYVAL dwAceRevision AS DWORD, _
    BYVAL AceFlags      AS DWORD, _
    BYVAL AceType       AS BYTE, _
    BYVAL AccessMask    AS DWORD, _
    BYVAL pSid          AS SID, _
    ConditionStr        AS WSTRINGZ, _
    ReturnLength        AS DWORD) _
    AS LONG

#ENDIF ' #IF (%WIN32_WINNT >= &H0601)

DECLARE FUNCTION AddAccessDeniedAce LIB "AdvApi32.dll" _
    ALIAS "AddAccessDeniedAce" (pAcl AS ACL, BYVAL dwAceRevision AS DWORD, _
    BYVAL AccessMask AS DWORD, pSid AS SID) AS LONG

#IF (%WIN32_WINNT >= &H0500)

DECLARE FUNCTION AccessDeniedAceEx LIB "AdvApi32.dll" _
    ALIAS "AccessDeniedAceEx" (pAcl AS ACL, BYVAL dwAceRevision AS DWORD, _
    BYVAL AceFlags AS DWORD, BYVAL AccessMask AS DWORD, pSid AS SID) AS LONG

#ENDIF ' %WIN32_WINNT >=  &H0500

DECLARE FUNCTION AddAuditAccessAce LIB "AdvApi32.dll" _
    ALIAS "AddAuditAccessAce" (pAcl AS ACL, BYVAL dwAceRevision AS DWORD, _
    BYVAL dwAccessMask AS DWORD, pSid AS SID, BYVAL bAuditSuccess AS LONG, _
    BYVAL bAuditFailure AS LONG) AS LONG

#IF (%WIN32_WINNT >= &H0500)

DECLARE FUNCTION AddAuditAccessAceEx LIB "AdvApi32.dll" _
    ALIAS "AddAuditAccessAceEx" (pAcl AS ACL, BYVAL dwAceRevision AS DWORD, _
    BYVAL AceFlags AS DWORD, BYVAL dwAccessMask AS DWORD, pSid AS SID, _
    BYVAL bAuditSuccess AS LONG, BYVAL bAuditFailure AS LONG) AS LONG

DECLARE FUNCTION AddAccessAllowedObjectAce LIB "AdvApi32.dll" _
    ALIAS "AddAccessAllowedObjectAce" (pAcl AS ACL, _
    BYVAL dwAceRevision AS DWORD, BYVAL AceFlags AS DWORD, _
    BYVAL AccessMask AS DWORD, ObjectTypeGuid AS GUID, _
    InheritedObjectTypeGuid AS GUID, psid AS SID) AS LONG

DECLARE FUNCTION AddAccessDeniedObjectAce LIB "AdvApi32.dll" _
    ALIAS "AddAccessDeniedObjectAce" (pAcl AS ACL, _
    BYVAL dwAceRevision AS DWORD, BYVAL AceFlags AS DWORD, _
    BYVAL AccessMask AS DWORD, ObjectTypeGuid AS GUID, _
    InheritedObjectTypeGuid AS GUID, pSid AS SID) AS LONG

DECLARE FUNCTION AddAuditAccessObjectAce LIB "AdvApi32.dll" _
    ALIAS "AddAuditAccessObjectAce" (pAcl AS ACL, _
    BYVAL dwAceRevision AS DWORD, BYVAL AceFlags AS DWORD, _
    BYVAL AccessMask AS DWORD, ObjectTypeGuid AS GUID, _
    InheritedObjectTypeGuid AS GUID, pSid AS SID, _
    BYVAL bAuditSuccess AS LONG, BYVAL bAuditFailure AS LONG) AS LONG

#ENDIF ' %WIN32_WINNT >=  &H0500

DECLARE FUNCTION FindFirstFreeAce LIB "AdvApi32.dll" ALIAS "FindFirstFreeAce" _
    (pAcl AS ACL, pAce AS DWORD) AS LONG

DECLARE FUNCTION InitializeSecurityDescriptor LIB "AdvApi32.dll" _
    ALIAS "InitializeSecurityDescriptor" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL dwRevision AS DWORD) _
    AS LONG

DECLARE FUNCTION IsValidSecurityDescriptor LIB "AdvApi32.dll" _
    ALIAS "IsValidSecurityDescriptor" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR) AS LONG

DECLARE FUNCTION IsValidRelativeSecurityDescriptor LIB "AdvApi32.dll" _
    ALIAS "IsValidRelativeSecurityDescriptor" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    BYVAL SecurityDescriptorLength AS DWORD, _
    BYVAL RequiredInformation AS DWORD) AS LONG

'WINADVAPI
'BOOL
'WINAPI
'IsValidRelativeSecurityDescriptor (
'    PSECURITY_DESCRIPTOR pSecurityDescriptor,
'    DWORD SecurityDescriptorLength,
'    SECURITY_INFORMATION RequiredInformation
'    );

DECLARE FUNCTION GetSecurityDescriptorLength LIB "AdvApi32.dll" _
    ALIAS "GetSecurityDescriptorLength" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR) AS DWORD

DECLARE FUNCTION GetSecurityDescriptorControl LIB "AdvApi32.dll" _
    ALIAS "GetSecurityDescriptorControl" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    pControl AS SECURITY_DESCRIPTOR, lpdwRevision AS DWORD) AS LONG

#IF (%WIN32_WINNT >= &H0500)

DECLARE FUNCTION SetSecurityDescriptorControl LIB "AdvApi32.dll" _
    ALIAS "SetSecurityDescriptorControl" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    BYVAL ControlBitsOfInterest AS WORD, BYVAL ControlBitsToSet AS WORD) _
    AS LONG

#ENDIF ' %WIN32_WINNT >=  &H0500

DECLARE FUNCTION SetSecurityDescriptorDacl LIB "AdvApi32.dll" _
    ALIAS "SetSecurityDescriptorDacl" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    BYVAL bDaclPresent AS LONG, pDacl AS ACL, BYVAL bDaclDefaulted AS LONG) _
    AS LONG

DECLARE FUNCTION GetSecurityDescriptorDacl LIB "AdvApi32.dll" _
    ALIAS "GetSecurityDescriptorDacl" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, lpbDaclPresent AS LONG, _
    pDacl AS DWORD, lpbDaclDefaulted AS LONG) AS LONG

DECLARE FUNCTION SetSecurityDescriptorSacl LIB "AdvApi32.dll" _
    ALIAS "SetSecurityDescriptorSacl" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL bSaclPresent AS LONG, _
    pSacl AS ACL, BYVAL bSaclDefaulted AS LONG) AS LONG

DECLARE FUNCTION GetSecurityDescriptorSacl LIB "AdvApi32.dll" _
    ALIAS "GetSecurityDescriptorSacl" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    BYVAL lpbSaclPresent AS LONG, pSacl AS DWORD, lpbSaclDefaulted AS LONG) _
    AS LONG

DECLARE FUNCTION SetSecurityDescriptorOwner LIB "AdvApi32.dll" _
    ALIAS "SetSecurityDescriptorOwner" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, pOwner AS SID, _
    BYVAL bOwnerDefaulted AS LONG) AS LONG

DECLARE FUNCTION GetSecurityDescriptorOwner LIB "AdvApi32.dll" _
    ALIAS "GetSecurityDescriptorOwner" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, pOwner AS DWORD, _
    BYVAL lpbOwnerDefaulted AS LONG) AS LONG

DECLARE FUNCTION SetSecurityDescriptorGroup LIB "AdvApi32.dll" _
    ALIAS "SetSecurityDescriptorGroup" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, pGroup AS SID, _
    BYVAL bGroupDefaulted AS LONG) AS LONG

DECLARE FUNCTION GetSecurityDescriptorGroup LIB "AdvApi32.dll" _
    ALIAS "GetSecurityDescriptorGroup" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, pGroup AS DWORD, _
    lpbGroupDefaulted AS LONG) AS LONG

DECLARE FUNCTION SetSecurityDescriptorRMControl LIB "AdvApi32.dll" _
    ALIAS "SetSecurityDescriptorRMControl" _
    (SecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL RMControl AS DWORD) _
    AS DWORD

DECLARE FUNCTION GetSecurityDescriptorRMControl LIB "AdvApi32.dll" _
    ALIAS "GetSecurityDescriptorRMControl" _
    (SecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL RMControl AS DWORD) _
    AS DWORD

DECLARE FUNCTION CreatePrivateObjectSecurity LIB "AdvApi32.dll" _
    ALIAS "CreatePrivateObjectSecurity" _
    (ParentDescriptor AS SECURITY_DESCRIPTOR, _
    CreatorDescriptor AS SECURITY_DESCRIPTOR, _
    NewDescriptor AS DWORD, BYVAL IsDirectoryObject AS LONG, _
    BYVAL Token AS DWORD, GenericMapping AS GENERIC_MAPPING) AS LONG

#IF (%WIN32_WINNT >= &H0500)

DECLARE FUNCTION ConvertToAutoInheritPrivateObjectSecurity LIB "AdvApi32.dll" _
    ALIAS "ConvertToAutoInheritPrivateObjectSecurity" _
    (ParentDescriptor AS SECURITY_DESCRIPTOR, _
    CurrentSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    NewSecurityDescriptor AS DWORD, ObjectType AS GUID, _
    BYVAL IsDirectoryObject AS LONG, GenericMapping AS GENERIC_MAPPING) AS LONG

DECLARE FUNCTION CreatePrivateObjectSecurityEx _
    LIB "AdvApi32.dll" ALIAS "CreatePrivateObjectSecurityEx" _
    (ParentDescriptor AS SECURITY_DESCRIPTOR, _
    CurrentSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    NewDescriptor AS DWORD, ObjectType AS GUID, _
    BYVAL IsContainerObject AS LONG, BYVAL AutoInheritFlags AS DWORD, _
    BYVAL Token AS DWORD, GenericMapping AS GENERIC_MAPPING) AS LONG

DECLARE FUNCTION CreatePrivateObjectSecurityWithMultipleInheritance _
    LIB "AdvApi32.dll" _
    ALIAS "CreatePrivateObjectSecurityWithMultipleInheritance" _
    (ParentDescriptor AS SECURITY_DESCRIPTOR, _
    CreatorDescriptor AS SECURITY_DESCRIPTOR, _
    NewDescriptor AS DWORD, BYVAL ObjectTypes AS DWORD, _
    BYVAL GuidCount AS DWORD, BYVAL IsDirectoryObject AS LONG, _
    BYVAL AutoInheritFlags AS DWORD, BYVAL Token AS DWORD, _
    GenericMapping AS GENERIC_MAPPING) AS LONG

#ENDIF ' %WIN32_WINNT >=  &H0500

DECLARE FUNCTION SetPrivateObjectSecurity LIB "AdvApi32.dll" _
    ALIAS "SetPrivateObjectSecurity" (BYVAL SecurityInformation AS LONG, _
    ModificationDescriptor AS SECURITY_DESCRIPTOR, _
    ObjectsSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    GenericMapping AS GENERIC_MAPPING, BYVAL Token AS DWORD) AS LONG

#IF (%WIN32_WINNT >= &H0500)

DECLARE FUNCTION SetPrivateObjectSecurityEx LIB "AdvApi32.dll" _
    ALIAS "SetPrivateObjectSecurityEx" (BYVAL SecurityInformation AS LONG, _
    ModificationDescriptor AS SECURITY_DESCRIPTOR, _
    ObjectsSecurityDescriptor AS DWORD, BYVAL AutoInheritFlags AS DWORD, _
    GenericMapping AS GENERIC_MAPPING, BYVAL Token AS DWORD) AS LONG

#ENDIF ' %WIN32_WINNT >=  &H0500

DECLARE FUNCTION GetPrivateObjectSecurity LIB "AdvApi32.dll" _
    ALIAS "GetPrivateObjectSecurity" _
    (ObjectDescriptor AS SECURITY_DESCRIPTOR, _
    BYVAL SecurityInformation AS LONG, _
    ResultantDescriptor AS SECURITY_DESCRIPTOR, _
    BYVAL DescriptorLength AS DWORD, ReturnLength AS DWORD) AS LONG

DECLARE FUNCTION DestroyPrivateObjectSecurity LIB "AdvApi32.dll" _
    ALIAS "DestroyPrivateObjectSecurity" _
    (ObjectDescriptor AS DWORD) AS LONG

DECLARE FUNCTION MakeSelfRelativeSD LIB "AdvApi32.dll" _
    ALIAS "MakeSelfRelativeSD" _
    (pAbsoluteSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    pSelfRelativeSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    lpdwBufferLength AS DWORD) AS LONG

DECLARE FUNCTION MakeAbsoluteSD LIB "AdvApi32.dll" ALIAS "MakeAbsoluteSD" _
    (pSelfRelativeSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    pAbsoluteSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    lpdwAbsoluteSecurityDescriptorSize AS DWORD, pDacl AS ACL, _
    lpdwDaclSize AS DWORD, pSacl AS ACL, lpdwSaclSize AS DWORD, _
    pOwner AS SID, lpdwOwnerSize AS DWORD, pPrimaryGroup AS SID, _
    lpdwPrimaryGroupSize AS DWORD) AS LONG

DECLARE FUNCTION MakeAbsoluteSD2 LIB "AdvApi32.dll" ALIAS "MakeAbsoluteSD2" ( _
    pSelfRelativeSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    lpdwBufferSize AS DWORD) AS LONG

DECLARE SUB QuerySecurityAccessMask LIB "AdvApi32.dll" _
    ALIAS "QuerySecurityAccessMask" (BYVAL SecurityInformation AS LONG, _
    DesiredAccess AS DWORD)

DECLARE SUB SetSecurityAccessMask LIB "AdvApi32.dll" _
    ALIAS "SetSecurityAccessMask" (BYVAL SecurityInformation AS LONG, _
    DesiredAccess AS DWORD)

DECLARE FUNCTION SetFileSecurityA LIB "AdvApi32.dll" ALIAS "SetFileSecurityA" _
    (lpFileName AS ASCIIZ, BYVAL SecurityInformation AS LONG, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR) AS LONG

DECLARE FUNCTION SetFileSecurityW LIB "AdvApi32.dll" ALIAS "SetFileSecurityW" _
    (lpFileName AS WSTRINGZ, BYVAL SecurityInformation AS LONG, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetFileSecurity LIB "AdvApi32.dll" ALIAS "SetFileSecurityW" _
    (lpFileName AS WSTRINGZ, BYVAL SecurityInformation AS LONG, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR) AS LONG
#ELSE
DECLARE FUNCTION SetFileSecurity LIB "AdvApi32.dll" ALIAS "SetFileSecurityA" _
    (lpFileName AS ASCIIZ, BYVAL SecurityInformation AS LONG, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetFileSecurityA LIB "AdvApi32.dll" ALIAS "GetFileSecurityA" _
    (lpFileName AS ASCIIZ, BYVAL RequestedInformation AS LONG, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL nLength AS DWORD, _
    lpnLengthNeeded AS DWORD) AS LONG

DECLARE FUNCTION GetFileSecurityW LIB "AdvApi32.dll" ALIAS "GetFileSecurityW" _
    (lpFileName AS WSTRINGZ, BYVAL RequestedInformation AS LONG, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL nLength AS DWORD, _
    lpnLengthNeeded AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetFileSecurity LIB "AdvApi32.dll" ALIAS "GetFileSecurityW" _
    (lpFileName AS WSTRINGZ, BYVAL RequestedInformation AS LONG, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL nLength AS DWORD, _
    lpnLengthNeeded AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetFileSecurity LIB "AdvApi32.dll" ALIAS "GetFileSecurityA" _
    (lpFileName AS ASCIIZ, BYVAL RequestedInformation AS LONG, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL nLength AS DWORD, _
    lpnLengthNeeded AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetKernelObjectSecurity LIB "AdvApi32.dll" _
    ALIAS "SetKernelObjectSecurity" (BYVAL xHandle AS DWORD, _
    BYVAL SecurityInformation AS LONG, _
    SecurityDescriptor AS SECURITY_DESCRIPTOR) AS LONG

DECLARE FUNCTION FindFirstChangeNotificationA LIB "Kernel32.dll" _
    ALIAS "FindFirstChangeNotificationA" (lpPathName AS ASCIIZ, _
    BYVAL bWatchSubtree AS LONG, BYVAL dwNotifyFilter AS DWORD) AS DWORD

DECLARE FUNCTION FindFirstChangeNotificationW LIB "Kernel32.dll" _
    ALIAS "FindFirstChangeNotificationW" (lpPathName AS WSTRINGZ, _
    BYVAL bWatchSubtree AS LONG, BYVAL dwNotifyFilter AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION FindFirstChangeNotification LIB "Kernel32.dll" _
    ALIAS "FindFirstChangeNotificationW" (lpPathName AS WSTRINGZ, _
    BYVAL bWatchSubtree AS LONG, BYVAL dwNotifyFilter AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION FindFirstChangeNotification LIB "Kernel32.dll" _
    ALIAS "FindFirstChangeNotificationA" (lpPathName AS ASCIIZ, _
    BYVAL bWatchSubtree AS LONG, BYVAL dwNotifyFilter AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION FindNextChangeNotification LIB "Kernel32.dll" _
    ALIAS "FindNextChangeNotification" (BYVAL hChangeHandle AS DWORD) AS LONG

DECLARE FUNCTION FindCloseChangeNotification LIB "Kernel32.dll" _
    ALIAS "FindCloseChangeNotification" (BYVAL hChangeHandle AS DWORD) AS LONG

#IF (%WIN32_WINNT >= &H0400)

DECLARE FUNCTION ReadDirectoryChangesW LIB "Kernel32.dll" _
    ALIAS "ReadDirectoryChangesW" (BYVAL hDirectory AS DWORD, _
    BYVAL lpBuffer AS DWORD, BYVAL nBufferLength AS DWORD, _
    BYVAL bWatchSubtree AS LONG, BYVAL dwNotifyFilter AS DWORD, _
    lpBytesReturned AS DWORD, lpOverlapped AS OVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD) AS LONG

#ENDIF ' %WIN32_WINNT >= &H0400

DECLARE FUNCTION VirtualLock LIB "Kernel32.dll" ALIAS "VirtualLock" _
    (BYVAL lpAddress AS DWORD, BYVAL dwSize AS DWORD) AS LONG

DECLARE FUNCTION VirtualUnlock LIB "Kernel32.dll" ALIAS "VirtualUnlock" _
    (BYVAL lpAddress AS DWORD, BYVAL dwSize AS DWORD) AS LONG

DECLARE FUNCTION MapViewOfFileEx LIB "Kernel32.dll" ALIAS "MapViewOfFileEx" _
    (BYVAL hFileMappingObject AS DWORD, BYVAL dwDesiredAccess AS DWORD, _
    BYVAL dwFileOffsetHigh AS DWORD, BYVAL dwFileOffsetLow AS DWORD, _
    BYVAL dwNumberOfBytesToMap AS DWORD, lpBaseAddress AS DWORD) AS DWORD

#IF %WIN32_WINNT >= &H0600

DECLARE FUNCTION MapViewOfFileExNuma LIB "Kernel32.dll" _
    ALIAS "MapViewOfFileExNuma" (BYVAL hFileMappingObject AS DWORD, _
    BYVAL dwDesiredAccess AS DWORD, BYVAL dwFileOffsetHigh AS DWORD, _
    BYVAL dwFileOffsetLow AS DWORD, BYVAL dwNumberOfBytesToMap AS DWORD, _
    lpBaseAddress AS DWORD, BYVAL nndPreferred AS DWORD) AS DWORD

#ENDIF ' %WIN32_WINNT >= &H0600

DECLARE FUNCTION SetPriorityClass LIB "Kernel32.dll" _
    ALIAS "SetPriorityClass" (BYVAL hProcess AS DWORD, _
    BYVAL dwPriorityClass AS DWORD) AS LONG

DECLARE FUNCTION GetPriorityClass LIB "Kernel32.dll" ALIAS "GetPriorityClass" _
    (BYVAL hProcess AS DWORD) AS DWORD

DECLARE FUNCTION IsBadReadPtr LIB "Kernel32.dll" ALIAS "IsBadReadPtr" _
    (BYVAL lp AS DWORD, BYVAL ucb AS DWORD) AS LONG

DECLARE FUNCTION IsBadWritePtr LIB "Kernel32.dll" ALIAS "IsBadWritePtr" _
    (BYVAL lp AS DWORD, BYVAL ucb AS DWORD) AS LONG

DECLARE FUNCTION IsBadHugeReadPtr LIB "Kernel32.dll" ALIAS "IsBadHugeReadPtr" _
    (BYVAL lp AS DWORD, BYVAL ucb AS DWORD) AS LONG

DECLARE FUNCTION IsBadHugeWritePtr LIB "Kernel32.dll" _
    ALIAS "IsBadHugeWritePtr" (BYVAL lp AS DWORD, BYVAL ucb AS DWORD) AS LONG

DECLARE FUNCTION IsBadCodePtr LIB "Kernel32.dll" ALIAS "IsBadCodePtr" _
    (BYVAL lpfn AS DWORD) AS LONG

DECLARE FUNCTION IsBadStringPtrA LIB "Kernel32.dll" ALIAS "IsBadStringPtrA" _
    (lpsz AS ASCIIZ, BYVAL ucchMax AS DWORD) AS LONG

DECLARE FUNCTION IsBadStringPtrW LIB "Kernel32.dll" ALIAS "IsBadStringPtrW" _
    (lpsz AS WSTRINGZ, BYVAL ucchMax AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION IsBadStringPtr LIB "Kernel32.dll" ALIAS "IsBadStringPtrW" _
    (lpsz AS WSTRINGZ, BYVAL ucchMax AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION IsBadStringPtr LIB "Kernel32.dll" ALIAS "IsBadStringPtrA" _
    (lpsz AS ASCIIZ, BYVAL ucchMax AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION LookupAccountSidA LIB "AdvApi32.dll" _
    ALIAS "LookupAccountSidA" (lpSystemName AS ASCIIZ, pSid AS SID, _
    xName AS ASCIIZ, cbName AS DWORD, ReferencedDomainName AS ASCIIZ, _
    cbReferencedDomainName AS LONG, peUse AS LONG) AS LONG

DECLARE FUNCTION LookupAccountSidW LIB "AdvApi32.dll" _
    ALIAS "LookupAccountSidW" (lpSystemName AS WSTRINGZ, pSid AS SID, _
    xName AS WSTRINGZ, cbName AS DWORD, ReferencedDomainName AS WSTRINGZ, _
    cbReferencedDomainName AS LONG, peUse AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION LookupAccountSid LIB "AdvApi32.dll" _
    ALIAS "LookupAccountSidW" (lpSystemName AS WSTRINGZ, pSid AS SID, _
    xName AS WSTRINGZ, cbName AS DWORD, ReferencedDomainName AS WSTRINGZ, _
    cbReferencedDomainName AS LONG, peUse AS LONG) AS LONG
#ELSE
DECLARE FUNCTION LookupAccountSid LIB "AdvApi32.dll" _
    ALIAS "LookupAccountSidA" (lpSystemName AS ASCIIZ, pSid AS SID, _
    xName AS ASCIIZ, cbName AS DWORD, ReferencedDomainName AS ASCIIZ, _
    cbReferencedDomainName AS LONG, peUse AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

' [not documented. does not appear to be exported.]
'DECLARE FUNCTION LookupAccountSidLocalA LIB "AdvApi32.dll" _
'    ALIAS "LookupAccountSidLocalA" ( _
'    pSid                    AS SID, _
'    sName                   AS ASCIIZ, _
'    cchName                 AS DWORD, _
'    ReferencedDomainName    AS ASCIIZ, _
'    cchReferencedDomainname AS DWORD, _
'    peUse                   AS SID_NAME_USE_enum) _
'    AS LONG
'
'DECLARE FUNCTION LookupAccountSidLocalW LIB "AdvApi32.dll" _
'    ALIAS "LookupAccountSidLocalW" ( _
'    pSid                    AS SID, _
'    sName                   AS WSTRINGZ, _
'    cchName                 AS DWORD, _
'    ReferencedDomainName    AS WSTRINGZ, _
'    cchReferencedDomainname AS DWORD, _
'    peUse                   AS SID_NAME_USE_enum) _
'    AS LONG
'
'#IF %DEF(%UNICODE)
'MACRO LookupAccountSidLocal=LookUpAccountSidLocalW
'#ELSE
'MACRO LookupAccountSidLocal=LookUpAccountSidLocalA
'#ENDIF

DECLARE FUNCTION LookupAccountNameA LIB "AdvApi32.dll" _
    ALIAS "LookupAccountNameA" (lpSystemName AS ASCIIZ, _
    lpAccountName AS ASCIIZ, pSid AS SID, cbSid AS DWORD, _
    ReferencedDomainName AS ASCIIZ, cbReferencedDomainName AS DWORD, _
    peUse AS LONG) AS LONG

DECLARE FUNCTION LookupAccountNameW LIB "AdvApi32.dll" _
    ALIAS "LookupAccountNameW" (lpSystemName AS WSTRINGZ, _
    lpAccountName AS WSTRINGZ, pSid AS SID, cbSid AS DWORD, _
    ReferencedDomainName AS WSTRINGZ, cbReferencedDomainName AS DWORD, _
    peUse AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION LookupAccountName LIB "AdvApi32.dll" _
    ALIAS "LookupAccountNameW" (lpSystemName AS WSTRINGZ, _
    lpAccountName AS WSTRINGZ, pSid AS SID, cbSid AS DWORD, _
    ReferencedDomainName AS WSTRINGZ, cbReferencedDomainName AS DWORD, _
    peUse AS LONG) AS LONG
#ELSE
DECLARE FUNCTION LookupAccountName LIB "AdvApi32.dll" _
    ALIAS "LookupAccountNameA" (lpSystemName AS ASCIIZ, _
    lpAccountName AS ASCIIZ, pSid AS SID, cbSid AS DWORD, _
    ReferencedDomainName AS ASCIIZ, cbReferencedDomainName AS DWORD, _
    peUse AS LONG) AS LONG
#ENDIF ' NOT %UNICODE

' [not documented. does not appear to be exported]
'DECLARE FUNCTION LookupAccountNameLocalA LIB "AdvApi32.dll" _
'    ALIAS "LookupAccountNameLocalA" ( _
'    lpAccountName           AS ASCIIZ, _
'    pSid                    AS SID, _
'    cbSid                   AS DWORD, _
'    ReferencedDomainName    AS ASCIIZ, _
'    cchReferencedDomainName AS DWORD, _
'    peUse                   AS SID_NAME_USE_enum) _
'    AS LONG
'
'DECLARE FUNCTION LookupAccountNameLocalW LIB "AdvApi32.dll" _
'    ALIAS "LookupAccountNameLocalW" ( _
'    lpAccountName           AS WSTRINGZ, _
'    pSid                    AS SID, _
'    cbSid                   AS DWORD, _
'    ReferencedDomainName    AS WSTRINGZ, _
'    cchReferencedDomainName AS DWORD, _
'    peUse                   AS SID_NAME_USE_enum) _
'    AS LONG
'
'#IF %DEF(%UNICODE)
'MACRO LookupAccountNameLocal=LookupAccountNameLocalW
'#ELSE
'MACRO LookupAccountNameLocal=LookupAccountNameLocalA
'#ENDIF

DECLARE FUNCTION LookupPrivilegeValueA LIB "AdvApi32.dll" _
    ALIAS "LookupPrivilegeValueA" (lpSystemName AS ASCIIZ, _
    lpName AS ASCIIZ, lpLuid AS QUAD) AS LONG

DECLARE FUNCTION LookupPrivilegeValueW LIB "AdvApi32.dll" _
    ALIAS "LookupPrivilegeValueW" (lpSystemName AS WSTRINGZ, _
    lpName AS WSTRINGZ, lpLuid AS QUAD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION LookupPrivilegeValue LIB "AdvApi32.dll" _
    ALIAS "LookupPrivilegeValueW" (lpSystemName AS WSTRINGZ, _
    lpName AS WSTRINGZ, lpLuid AS QUAD) AS LONG
#ELSE
DECLARE FUNCTION LookupPrivilegeValue LIB "AdvApi32.dll" _
    ALIAS "LookupPrivilegeValueA" (lpSystemName AS ASCIIZ, _
    lpName AS ASCIIZ, lpLuid AS QUAD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION LookupPrivilegeNameA LIB "AdvApi32.dll" _
    ALIAS "LookupPrivilegeNameA" (lpSystemName AS ASCIIZ, lpLuid AS QUAD, _
    lpName AS ASCIIZ, cbName AS DWORD) AS LONG

DECLARE FUNCTION LookupPrivilegeNameW LIB "AdvApi32.dll" _
    ALIAS "LookupPrivilegeNameW" (lpSystemName AS WSTRINGZ, lpLuid AS QUAD, _
    lpName AS WSTRINGZ, cbName AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION LookupPrivilegeName LIB "AdvApi32.dll" _
    ALIAS "LookupPrivilegeNameW" (lpSystemName AS WSTRINGZ, lpLuid AS QUAD, _
    lpName AS WSTRINGZ, cbName AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION LookupPrivilegeName LIB "AdvApi32.dll" _
    ALIAS "LookupPrivilegeNameA" (lpSystemName AS ASCIIZ, lpLuid AS QUAD, _
    lpName AS ASCIIZ, cbName AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION LookupPrivilegeDisplayNameA LIB "AdvApi32.dll" _
    ALIAS "LookupPrivilegeDisplayNameA" (lpSystemName AS ASCIIZ, _
    lpName AS ASCIIZ, lpDisplayName AS ASCIIZ, cbDisplayName AS DWORD, _
    lpLanguageID AS DWORD) AS LONG

DECLARE FUNCTION LookupPrivilegeDisplayNameW LIB "AdvApi32.dll" _
    ALIAS "LookupPrivilegeDisplayNameW" (lpSystemName AS WSTRINGZ, _
    lpName AS WSTRINGZ, lpDisplayName AS WSTRINGZ, cbDisplayName AS DWORD, _
    lpLanguageID AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION LookupPrivilegeDisplayName LIB "AdvApi32.dll" _
    ALIAS "LookupPrivilegeDisplayNameW" (lpSystemName AS WSTRINGZ, _
    lpName AS WSTRINGZ, lpDisplayName AS WSTRINGZ, cbDisplayName AS DWORD, _
    lpLanguageID AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION LookupPrivilegeDisplayName LIB "AdvApi32.dll" _
    ALIAS "LookupPrivilegeDisplayNameA" (lpSystemName AS ASCIIZ, _
    lpName AS ASCIIZ, lpDisplayName AS ASCIIZ, cbDisplayName AS DWORD, _
    lpLanguageID AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION AllocateLocallyUniqueId LIB "AdvApi32.dll" _
    ALIAS "AllocateLocallyUniqueId" (Luid AS QUAD) AS LONG

DECLARE FUNCTION BuildCommDCBA LIB "Kernel32.dll" ALIAS "BuildCommDCBA" _
    (lpDef AS ASCIIZ, lpDCB AS DCB) AS LONG

DECLARE FUNCTION BuildCommDCBW LIB "Kernel32.dll" ALIAS "BuildCommDCBW" _
    (lpDef AS WSTRINGZ, lpDCB AS DCB) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION BuildCommDCB LIB "Kernel32.dll" ALIAS "BuildCommDCBW" _
    (lpDef AS WSTRINGZ, lpDCB AS DCB) AS LONG
#ELSE
DECLARE FUNCTION BuildCommDCB LIB "Kernel32.dll" ALIAS "BuildCommDCBA" _
    (lpDef AS ASCIIZ, lpDCB AS DCB) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION BuildCommDCBAndTimeoutsA LIB "Kernel32.dll" _
    ALIAS "BuildCommDCBAndTimeoutsA" (lpDef AS ASCIIZ, lpDCB AS DCB, _
    lpCommTimeouts AS COMMTIMEOUTS) AS LONG

DECLARE FUNCTION BuildCommDCBAndTimeoutsW LIB "Kernel32.dll" _
    ALIAS "BuildCommDCBAndTimeoutsW" (lpDef AS WSTRINGZ, lpDCB AS DCB, _
    lpCommTimeouts AS COMMTIMEOUTS) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION BuildCommDCBAndTimeouts LIB "Kernel32.dll" _
    ALIAS "BuildCommDCBAndTimeoutsW" (lpDef AS WSTRINGZ, lpDCB AS DCB, _
    lpCommTimeouts AS COMMTIMEOUTS) AS LONG
#ELSE
DECLARE FUNCTION BuildCommDCBAndTimeouts LIB "Kernel32.dll" _
    ALIAS "BuildCommDCBAndTimeoutsA" (lpDef AS ASCIIZ, lpDCB AS DCB, _
    lpCommTimeouts AS COMMTIMEOUTS) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CommConfigDialogA LIB "Kernel32.dll" _
    ALIAS "CommConfigDialogA" (lpszName AS ASCIIZ, BYVAL hWnd AS DWORD, _
    lpCC AS COMMCONFIG) AS LONG

DECLARE FUNCTION CommConfigDialogW LIB "Kernel32.dll" _
    ALIAS "CommConfigDialogW" (lpszName AS WSTRINGZ, BYVAL hWnd AS DWORD, _
    lpCC AS COMMCONFIG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CommConfigDialog LIB "Kernel32.dll" _
    ALIAS "CommConfigDialogW" (lpszName AS WSTRINGZ, BYVAL hWnd AS DWORD, _
    lpCC AS COMMCONFIG) AS LONG
#ELSE
DECLARE FUNCTION CommConfigDialog LIB "Kernel32.dll" _
    ALIAS "CommConfigDialogA" (lpszName AS ASCIIZ, BYVAL hWnd AS DWORD, _
    lpCC AS COMMCONFIG) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetDefaultCommConfigA LIB "Kernel32.dll" _
    ALIAS "GetDefaultCommConfigA" (lpszName AS ASCIIZ, lpCC AS COMMCONFIG, _
    lpdwSize AS DWORD) AS LONG

DECLARE FUNCTION GetDefaultCommConfigW LIB "Kernel32.dll" _
    ALIAS "GetDefaultCommConfigW" (lpszName AS WSTRINGZ, lpCC AS COMMCONFIG, _
    lpdwSize AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetDefaultCommConfig LIB "Kernel32.dll" _
    ALIAS "GetDefaultCommConfigW" (lpszName AS WSTRINGZ, lpCC AS COMMCONFIG, _
    lpdwSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetDefaultCommConfig LIB "Kernel32.dll" _
    ALIAS "GetDefaultCommConfigA" (lpszName AS ASCIIZ, lpCC AS COMMCONFIG, _
    lpdwSize AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetDefaultCommConfigA LIB "Kernel32.dll" _
    ALIAS "SetDefaultCommConfigA" (lpszName AS ASCIIZ, lpCC AS COMMCONFIG, _
    BYVAL dwSize AS DWORD) AS LONG

DECLARE FUNCTION SetDefaultCommConfigW LIB "Kernel32.dll" _
    ALIAS "SetDefaultCommConfigW" (lpszName AS WSTRINGZ, lpCC AS COMMCONFIG, _
    BYVAL dwSize AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetDefaultCommConfig LIB "Kernel32.dll" _
    ALIAS "SetDefaultCommConfigW" (lpszName AS WSTRINGZ, lpCC AS COMMCONFIG, _
    BYVAL dwSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SetDefaultCommConfig LIB "Kernel32.dll" _
    ALIAS "SetDefaultCommConfigA" (lpszName AS ASCIIZ, lpCC AS COMMCONFIG, _
    BYVAL dwSize AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

%MAX_COMPUTERNAME_LENGTH = 15

DECLARE FUNCTION GetComputerNameA LIB "Kernel32.dll" ALIAS "GetComputerNameA" _
    (lpBuffer AS ASCIIZ, nSize AS DWORD) AS LONG

DECLARE FUNCTION GetComputerNameW LIB "Kernel32.dll" ALIAS "GetComputerNameW" _
    (lpBuffer AS WSTRING, nSize AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetComputerName LIB "Kernel32.dll" ALIAS "GetComputerNameW" _
    (lpBuffer AS WSTRING, nSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetComputerName LIB "Kernel32.dll" ALIAS "GetComputerNameA" _
    (lpBuffer AS ASCIIZ, nSize AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetComputerNameA LIB "Kernel32.dll" ALIAS "SetComputerNameA" _
    (lpComputerName AS ASCIIZ) AS LONG

DECLARE FUNCTION SetComputerNameW LIB "Kernel32.dll" ALIAS "SetComputerNameW" _
    (lpComputerName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetComputerName LIB "Kernel32.dll" ALIAS "SetComputerNameW" _
    (lpComputerName AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION SetComputerName LIB "Kernel32.dll" ALIAS "SetComputerNameA" _
    (lpComputerName AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE


#IF (%WIN32_WINNT >= &H0500)

MACRO COMPUTER_NAME_FORMAT_enum=LONG
ENUM COMPUTER_NAME_FORMAT SINGULAR
    ComputerNameNetBIOS
    ComputerNameDnsHostname
    ComputerNameDnsDomain
    ComputerNameDnsFullyQualified
    ComputerNamePhysicalNetBIOS
    ComputerNamePhysicalDnsHostname
    ComputerNamePhysicalDnsDomain
    ComputerNamePhysicalDnsFullyQualified
    ComputerNameMax
END ENUM

DECLARE FUNCTION GetComputerNameExA LIB "Kernel32.dll" _
    ALIAS "GetComputerNameExA" (BYVAL NameType AS COMPUTER_NAME_FORMAT_enum, _
    lpBuffer AS ASCIIZ, _
    nSize AS DWORD) AS LONG

DECLARE FUNCTION GetComputerNameExW LIB "Kernel32.dll" _
    ALIAS "GetComputerNameExW" (BYVAL NameType AS COMPUTER_NAME_FORMAT_enum, _
    lpBuffer AS WSTRINGZ, _
    nSize AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetComputerNameEx LIB "Kernel32.dll" _
    ALIAS "GetComputerNameExW" (BYVAL NameType AS COMPUTER_NAME_FORMAT_enum, _
    lpBuffer AS WSTRINGZ, _
    nSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetComputerNameEx LIB "Kernel32.dll" _
    ALIAS "GetComputerNameExA" (BYVAL NameType AS COMPUTER_NAME_FORMAT_enum, _
    lpBuffer AS ASCIIZ, _
    nSize AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetComputerNameExA LIB "Kernel32.dll" _
    ALIAS "SetComputerNameExA" (BYVAL NameType AS COMPUTER_NAME_FORMAT_enum, _
    lpBuffer AS ASCIIZ) AS LONG

DECLARE FUNCTION SetComputerNameExW LIB "Kernel32.dll" _
    ALIAS "SetComputerNameExW" (BYVAL NameType AS COMPUTER_NAME_FORMAT_enum, _
    lpBuffer AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetComputerNameEx LIB "Kernel32.dll" _
    ALIAS "SetComputerNameExW" (BYVAL NameType AS COMPUTER_NAME_FORMAT_enum, _
    lpBuffer AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION SetComputerNameEx LIB "Kernel32.dll" _
    ALIAS "SetComputerNameExA" (BYVAL NameType AS COMPUTER_NAME_FORMAT_enum, _
    lpBuffer AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION DnsHostnameToComputerNameA LIB "Kernel32.dll" _
    ALIAS "DnsHostnameToComputerNameA" (Hostname AS ASCIIZ, _
    ComputerName AS ASCIIZ, nSize AS DWORD) AS LONG

DECLARE FUNCTION DnsHostnameToComputerNameW LIB "Kernel32.dll" _
    ALIAS "DnsHostnameToComputerNameW" (Hostname AS WSTRINGZ, _
    ComputerName AS WSTRINGZ, nSize AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION DnsHostnameToComputerName LIB "Kernel32.dll" _
    ALIAS "DnsHostnameToComputerNameW" (Hostname AS WSTRINGZ, _
    ComputerName AS WSTRINGZ, nSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION DnsHostnameToComputerName LIB "Kernel32.dll" _
    ALIAS "DnsHostnameToComputerNameA" (Hostname AS ASCIIZ, _
    ComputerName AS ASCIIZ, nSize AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' %WIN32_WINNT

DECLARE FUNCTION GetUserNameA LIB "AdvApi32.dll" ALIAS "GetUserNameA" _
    (lpBuffer AS ASCIIZ, nSize AS DWORD) AS LONG

DECLARE FUNCTION GetUserNameW LIB "AdvApi32.dll" ALIAS "GetUserNameW" _
    (lpBuffer AS WSTRINGZ, nSize AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetUserName LIB "AdvApi32.dll" ALIAS "GetUserNameW" _
    (lpBuffer AS WSTRINGZ, nSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetUserName LIB "AdvApi32.dll" ALIAS "GetUserNameA" _
    (lpBuffer AS ASCIIZ, nSize AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

'
' Logon Support APIs
'

%LOGON32_LOGON_INTERACTIVE       = 2
%LOGON32_LOGON_NETWORK           = 3
%LOGON32_LOGON_BATCH             = 4
%LOGON32_LOGON_SERVICE           = 5
%LOGON32_LOGON_UNLOCK            = 7
#IF (%WIN32_WINNT >= &H0500)
%LOGON32_LOGON_NETWORK_CLEARTEXT = 8
%LOGON32_LOGON_NEW_CREDENTIALS   = 9
#ENDIF ' (%WIN32_WINNT >= &H0500)

%LOGON32_PROVIDER_DEFAULT   = 0
%LOGON32_PROVIDER_WINNT35   = 1
#IF (%WIN32_WINNT >= &H0400)
%LOGON32_PROVIDER_WINNT40   = 2
#ENDIF ' %WIN32_WINNT >= &H0400
#IF (%WIN32_WINNT >= &H0500)
%LOGON32_PROVIDER_WINNT50   = 3
#ENDIF ' (%WIN32_WINNT >= &H0500)
#IF (%WIN32_WINNT >= &H0600)
%LOGON32_PROVIDER_VIRTUAL   = 4
#ENDIF ' (%WIN32_WINNT >= &H0600)


DECLARE FUNCTION LogonUserA LIB "AdvApi32.dll" ALIAS "LogonUserA" _
    (lpszUsername AS ASCIIZ, lpszDomain AS ASCIIZ, lpszPassword AS ASCIIZ, _
    BYVAL dwLogonType AS DWORD, BYVAL dwLogonProvider AS DWORD, _
    phToken AS DWORD) AS LONG

DECLARE FUNCTION LogonUserW LIB "AdvApi32.dll" ALIAS "LogonUserW" _
    (lpszUsername AS WSTRINGZ, lpszDomain AS WSTRINGZ, _
    lpszPassword AS WSTRINGZ, BYVAL dwLogonType AS DWORD, _
    BYVAL dwLogonProvider AS DWORD, phToken AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION LogonUser LIB "AdvApi32.dll" ALIAS "LogonUserW" _
    (lpszUsername AS WSTRINGZ, lpszDomain AS WSTRINGZ, _
    lpszPassword AS WSTRINGZ, BYVAL dwLogonType AS DWORD, _
    BYVAL dwLogonProvider AS DWORD, phToken AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION LogonUser LIB "AdvApi32.dll" ALIAS "LogonUserA" _
    (lpszUsername AS ASCIIZ, lpszDomain AS ASCIIZ, lpszPassword AS ASCIIZ, _
    BYVAL dwLogonType AS DWORD, BYVAL dwLogonProvider AS DWORD, _
    phToken AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION LogonUserExA LIB "AdvApi32.dll" ALIAS "LogonUserExA" _
    (lpszUsername AS ASCIIZ, lpszDomain AS ASCIIZ, lpszPassword AS ASCIIZ, _
    BYVAL dwLogonType AS DWORD, BYVAL dwLogonProvider AS DWORD, _
    phToken AS DWORD, ppLogonSid AS DWORD, ppProfileBuffer AS DWORD, _
    pdwProfileLength AS DWORD, pQuotaLimits AS QUOTA_LIMITS) AS LONG

DECLARE FUNCTION LogonUserExW LIB "AdvApi32.dll" ALIAS "LogonUserExW" _
    (lpszUsername AS WSTRINGZ, lpszDomain AS WSTRINGZ, _
    lpszPassword AS WSTRINGZ, BYVAL dwLogonType AS DWORD, _
    BYVAL dwLogonProvider AS DWORD, phToken AS DWORD, ppLogonSid AS DWORD, _
    ppProfileBuffer AS DWORD, pdwProfileLength AS DWORD, _
    pQuotaLimits AS QUOTA_LIMITS) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION LogonUserEx LIB "AdvApi32.dll" ALIAS "LogonUserExW" _
    (lpszUsername AS WSTRINGZ, lpszDomain AS WSTRINGZ, _
    lpszPassword AS WSTRINGZ, BYVAL dwLogonType AS DWORD, _
    BYVAL dwLogonProvider AS DWORD, phToken AS DWORD, ppLogonSid AS DWORD, _
    ppProfileBuffer AS DWORD, pdwProfileLength AS DWORD, _
    pQuotaLimits AS QUOTA_LIMITS) AS LONG
#ELSE
DECLARE FUNCTION LogonUserEx LIB "AdvApi32.dll" ALIAS "LogonUserExA" _
    (lpszUsername AS ASCIIZ, lpszDomain AS ASCIIZ, lpszPassword AS ASCIIZ, _
    BYVAL dwLogonType AS DWORD, BYVAL dwLogonProvider AS DWORD, _
    phToken AS DWORD, ppLogonSid AS DWORD, ppProfileBuffer AS DWORD, _
    pdwProfileLength AS DWORD, pQuotaLimits AS QUOTA_LIMITS) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION ImpersonateLoggedOnUser LIB "AdvApi32.dll" _
    ALIAS "ImpersonateLoggedOnUser" (BYVAL hToken AS DWORD) AS LONG

DECLARE FUNCTION CreateProcessAsUserA LIB "AdvApi32.dll" _
    ALIAS "CreateProcessAsUserA" (BYVAL hToken AS DWORD, _
    lpApplicationName AS ASCIIZ, lpCommandLine AS ASCIIZ, _
    lpProcessAttributes AS SECURITY_ATTRIBUTES, _
    lpThreadAttributes AS SECURITY_ATTRIBUTES, BYVAL bInheritHandles AS LONG, _
    BYVAL dwCreationFlags AS DWORD, BYVAL lpEnvironment AS DWORD, _
    lpCurrentDirectory AS ASCIIZ, lpStartupInfo AS STARTUPINFOA, _
    lpProcessInformation AS PROCESS_INFORMATION) AS LONG

DECLARE FUNCTION CreateProcessAsUserW LIB "AdvApi32.dll" _
    ALIAS "CreateProcessAsUserW" (BYVAL hToken AS DWORD, _
    lpApplicationName AS WSTRINGZ, lpCommandLine AS ASCIIZ, _
    lpProcessAttributes AS SECURITY_ATTRIBUTES, _
    lpThreadAttributes AS SECURITY_ATTRIBUTES, BYVAL bInheritHandles AS LONG, _
    BYVAL dwCreationFlags AS DWORD, BYVAL lpEnvironment AS DWORD, _
    lpCurrentDirectory AS WSTRINGZ, lpStartupInfo AS STARTUPINFOW, _
    lpProcessInformation AS PROCESS_INFORMATION) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateProcessAsUser LIB "AdvApi32.dll" _
    ALIAS "CreateProcessAsUserW" (BYVAL hToken AS DWORD, _
    lpApplicationName AS WSTRINGZ, lpCommandLine AS ASCIIZ, _
    lpProcessAttributes AS SECURITY_ATTRIBUTES, _
    lpThreadAttributes AS SECURITY_ATTRIBUTES, BYVAL bInheritHandles AS LONG, _
    BYVAL dwCreationFlags AS DWORD, BYVAL lpEnvironment AS DWORD, _
    lpCurrentDirectory AS WSTRINGZ, lpStartupInfo AS STARTUPINFOW, _
    lpProcessInformation AS PROCESS_INFORMATION) AS LONG
#ELSE
DECLARE FUNCTION CreateProcessAsUser LIB "AdvApi32.dll" _
    ALIAS "CreateProcessAsUserA" (BYVAL hToken AS DWORD, _
    lpApplicationName AS ASCIIZ, lpCommandLine AS ASCIIZ, _
    lpProcessAttributes AS SECURITY_ATTRIBUTES, _
    lpThreadAttributes AS SECURITY_ATTRIBUTES, BYVAL bInheritHandles AS LONG, _
    BYVAL dwCreationFlags AS DWORD, BYVAL lpEnvironment AS DWORD, _
    lpCurrentDirectory AS ASCIIZ, lpStartupInfo AS STARTUPINFOA, _
    lpProcessInformation AS PROCESS_INFORMATION) AS LONG
#ENDIF ' NOT %UNICODE


#IF (%WIN32_WINNT >= &H0500)

'
' LogonFlags
'
%LOGON_WITH_PROFILE             = &H00000001
%LOGON_NETCREDENTIALS_ONLY      = &H00000002
%LOGON_ZERO_PASSWORD_BUFFER     = &H80000000???

DECLARE FUNCTION CreateProcessWithLogonW LIB "AdvApi32.dll" _
    ALIAS "CreateProcessWithLogonW" (lpUsername AS WSTRINGZ, _
    lpDomain AS WSTRINGZ, lpPassword AS WSTRINGZ, _
    BYVAL dwLogonFlags AS DWORD, lpApplicationName AS WSTRINGZ, _
    lpCommandLine AS WSTRINGZ, BYVAL dwCreationFlags AS DWORD, _
    BYVAL lpEnvironment AS DWORD, lpCurrentDirectory AS WSTRINGZ, _
    lpStartupInfo AS STARTUPINFOW, _
    lpProcessInformation AS PROCESS_INFORMATION) AS LONG

DECLARE FUNCTION CreateProcessWithTokenW LIB "AdvApi32.dll" _
    ALIAS "CreateProcessWithTokenW" (BYVAL hToken AS DWORD, _
    BYVAL dwLogonFlags AS DWORD, lpApplicationName AS WSTRINGZ, _
    lpCommandLine AS WSTRINGZ, BYVAL dwCreationFlags AS DWORD, _
    BYVAL lpEnvironment AS DWORD, lpCurrentDirectory AS WSTRINGZ, _
    lpStartupInfo AS STARTUPINFOW, _
    lpProcessInformation AS PROCESS_INFORMATION) AS LONG

#ENDIF ' (%WIN32_WINNT >= &H0500)

DECLARE FUNCTION ImpersonateAnonymousToken LIB "AdvApi32.dll" _
    ALIAS "ImpersonateAnonymousToken" (BYVAL hToken AS DWORD) AS LONG

DECLARE FUNCTION DuplicateTokenEx LIB "AdvApi32.dll" ALIAS "DuplicateTokenEx" _
    (BYVAL ExistingTokenHandle AS DWORD, BYVAL dwDesiredAccess AS DWORD, _
    lpTokenAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL ImpersonationLevel AS LONG, BYVAL TokenType AS LONG, _
    phNewToken AS DWORD) AS LONG

DECLARE FUNCTION CreateRestrictedToken LIB "AdvApi32.dll" _
    ALIAS "CreateRestrictedToken" (BYVAL ExistingTokenHandle AS DWORD, _
    BYVAL Flags AS DWORD, BYVAL DisableSidCount AS DWORD, _
    BYVAL SidsToDisable AS SID_AND_ATTRIBUTES PTR, _
    BYVAL DeletePrivilegeCount AS DWORD, _
    BYVAL PrivilegesToDelete AS LUID_AND_ATTRIBUTES PTR, _
    BYVAL RestrictedSidCount AS DWORD, _
    BYVAL SidsToRestrict AS SID_AND_ATTRIBUTES PTR, NewTokenHandle AS DWORD) _
    AS LONG

DECLARE FUNCTION IsTokenRestricted LIB "AdvApi32.dll" _
    ALIAS "IsTokenRestricted" (BYVAL hToken AS DWORD) AS LONG

DECLARE FUNCTION IsTokenUntrusted LIB "AdvApi32.dll" ALIAS "IsTokenUntrusted" _
    (BYVAL hToken AS DWORD) AS LONG

DECLARE FUNCTION CheckTokenMembership LIB "AdvApi32.dll" _
    ALIAS "CheckTokenMembership" (BYVAL hToken AS DWORD, SidToCheck AS SID, _
    IsMember AS LONG) AS LONG

'
' Thread pool API's
'

#IF (%WIN32_WINNT >= &H0500)

DECLARE FUNCTION RegisterWaitForSingleObject LIB "Kernel32.dll" _
    ALIAS "RegisterWaitForSingleObject" (phNewWaitObject AS DWORD, _
    BYVAL hObject AS DWORD, BYVAL pfCallback AS DWORD, _
    BYVAL dContext AS DWORD, BYVAL dwMilliseconds AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION RegisterWaitForSingleObjectEx LIB "Kernel32.dll" _
    ALIAS "RegisterWaitForSingleObjectEx" (BYVAL hObject AS DWORD, _
    BYVAL pfCallback AS DWORD, BYVAL dContext AS DWORD, _
    BYVAL dwMilliseconds AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION UnregisterWait LIB "Kernel32.dll" ALIAS "UnregisterWait" _
    (BYVAL WaitHandle AS DWORD) AS LONG

DECLARE FUNCTION UnregisterWaitEx LIB "Kernel32.dll" ALIAS "UnregisterWaitEx" _
    (BYVAL WaitHandle AS DWORD, CompletionEvent AS DWORD) AS LONG

DECLARE FUNCTION QueueUserWorkItem LIB "Kernel32.dll" _
    ALIAS "QueueUserWorkItem" (BYVAL pfThread AS DWORD, _
    BYVAL dContext AS DWORD, BYVAL dFlags AS DWORD) AS LONG

DECLARE FUNCTION BindIoCompletionCallback LIB "Kernel32.dll" _
    ALIAS "BindIoCompletionCallback" (BYVAL FileHandle AS DWORD, _
    BYVAL pFunction AS DWORD, BYVAL dFlags AS DWORD) AS LONG

DECLARE FUNCTION CreateTimerQueue LIB "Kernel32.dll" ALIAS "CreateTimerQueue" _
    () AS DWORD

DECLARE FUNCTION CreateTimerQueueTimer LIB "Kernel32.dll" _
    ALIAS "CreateTimerQueueTimer" (phNewTimer AS DWORD, _
    BYVAL TimerQueue AS DWORD, BYVAL pCallback AS DWORD, _
    BYVAL Parameter AS DWORD, BYVAL DueTime AS DWORD, BYVAL Period AS DWORD, _
    BYVAL dFlags AS DWORD) AS LONG

DECLARE FUNCTION ChangeTimerQueueTimer LIB "Kernel32.dll" _
    ALIAS "ChangeTimerQueueTimer" (BYVAL hTimerQueue AS DWORD, _
    BYVAL hTimer AS DWORD, BYVAL DueTime AS DWORD, BYVAL Period AS DWORD) _
    AS LONG

DECLARE FUNCTION DeleteTimerQueueTimer LIB "Kernel32.dll" _
    ALIAS "DeleteTimerQueueTimer" (BYVAL hTimerQueue AS DWORD, _
    BYVAL hTimer AS DWORD, BYVAL hCompletionEvent AS DWORD) AS LONG

DECLARE FUNCTION DeleteTimerQueueEx LIB "Kernel32.dll" _
    ALIAS "DeleteTimerQueueEx" (BYVAL hTimerQueue AS DWORD, _
    BYVAL hCompletionEvent AS DWORD) AS LONG

DECLARE FUNCTION SetTimerQueueTimer LIB "Kernel32.dll" _
    ALIAS "SetTimerQueueTimer" (BYVAL hTimerQueue AS DWORD, _
    BYVAL pCallback AS DWORD, BYVAL Parameter AS DWORD, _
    BYVAL DueTime AS DWORD, BYVAL Period AS DWORD, BYVAL PreferIo AS LONG) _
    AS DWORD

DECLARE FUNCTION CancelTimerQueueTimer LIB "Kernel32.dll" _
    ALIAS "CancelTimerQueueTimer" (BYVAL hTimerQueue AS DWORD, _
    BYVAL hTimer AS DWORD) AS LONG

DECLARE FUNCTION DeleteTimerQueue LIB "Kernel32.dll" ALIAS "DeleteTimerQueue" _
    (BYVAL hTimerQueue AS DWORD) AS LONG

#IF (%WIN32_WINNT >= &H0600)

DECLARE SUB PTP_WIN32_IO_CALLBACK (BYVAL INSTANCE AS DWORD, _
    BYVAL Context AS DWORD, BYVAL Overlap AS OVERLAPPED PTR, _
    BYVAL IoResult AS DWORD, BYVAL NumberOfBytesTransferred AS DWORD, _
    Io AS ANY)

DECLARE FUNCTION CreateThreadpool LIB "Kernel32.dll" ALIAS "CreateThreadpool" _
    (BYVAL Reserved AS DWORD) AS DWORD

DECLARE SUB SetThreadpoolThreadMaximum LIB "Kernel32.dll" _
    ALIAS "SetThreadpoolThreadMaximum" (BYVAL ptpp AS DWORD, _
    BYVAL cthrdMost AS DWORD)

DECLARE FUNCTION SetThreadpoolThreadMinimum LIB "Kernel32.dll" _
    ALIAS "SetThreadpoolThreadMinimum" (BYVAL ptpp AS DWORD, _
    BYVAL cthrdMic AS DWORD) AS LONG

DECLARE FUNCTION SetThreadpoolStackInformation LIB "Kernel32.dll" _
    ALIAS "SetThreadpoolStackInformation" (BYVAL pptp AS DWORD, _
    ptpsi AS TP_POOL_STACK_INFORMATION) AS LONG

DECLARE FUNCTION QueryThreadpoolStackInformation LIB "Kernel32.dll" _
    ALIAS "QueryThreadpoolStackInformation" (BYVAL pptp AS DWORD, _
    ptpsi AS TP_POOL_STACK_INFORMATION) AS LONG

DECLARE SUB CloseThreadpool LIB "Kernel32.dll" ALIAS "CloseThreadpool" _
    (BYVAL ptpp AS DWORD)

DECLARE FUNCTION CreateThreadpoolCleanupGroup LIB "Kernel32.dll" _
    ALIAS "CreateThreadpoolCleanupGroup" () AS DWORD

DECLARE SUB CloseThreadpoolCleanupGroupMembers LIB "Kernel32.dll" _
    ALIAS "CloseThreadpoolCleanupGroupMembers" ( _
    BYVAL ptpcg AS DWORD, BYVAL fCancelPendingCallbacks AS LONG, _
    BYVAL pvCleanupContext AS DWORD)

DECLARE SUB CloseThreadpoolCleanupGroup LIB "Kernel32.dll" _
    ALIAS "CloseThreadpoolCleanupGroup" (BYVAL ptpcg AS DWORD)

#IF NOT %DEF(%MIDL_PASS)
MACRO InitializeThreadpoolEnvironment(pcbe)=TpInitializeCallbackEnviron(pcbe)
MACRO SetThreadpoolCallbackPool(pcbe,ptpp)=TpSetCallbackThreadpool(pcbe, ptpp)
MACRO SetThreadpoolCallbackCleanupGroup(pcbe,ptpcg,pfng)=TpSetCallbackCleanupGroup(pcbe, ptpcg, pfng);
MACRO SetThreadpoolCallbackRunsLong(pcbe)=TpSetCallbackLongFunction(pcbe)
MACRO SetThreadpoolCallbackLibrary(pcbe,xmod)=TpSetCallbackRaceWithDll(pcbe,xmod)
MACRO DestroyThreadpoolEnvironment(pcbe)=TpDestroyCallbackEnviron(pcbe)
#ENDIF

DECLARE SUB SetEventWhenCallbackReturns LIB "Kernel32.dll" _
    ALIAS "SetEventWhenCallbackReturns" (BYVAL pci AS DWORD, _
    BYVAL evt AS DWORD)

DECLARE SUB ReleaseSemaphoreWhenCallbackReturns LIB "Kernel32.dll" _
    ALIAS "ReleaseSemaphoreWhenCallbackReturns" (BYVAL fpci AS DWORD, _
    BYVAL hsem AS DWORD, BYVAL crel AS DWORD)

DECLARE SUB ReleaseMutexWhenCallbackReturns LIB "Kernel32.dll" _
    ALIAS "ReleaseMutexWhenCallbackReturns" (BYVAL fpci AS DWORD, _
    BYVAL hmut AS DWORD)

DECLARE SUB LeaveCriticalSectionWhenCallbackReturns LIB "Kernel32.dll" _
    ALIAS "LeaveCriticalSectionWhenCallbackReturns" (BYVAL fpci AS DWORD, _
    pcs AS CRITICAL_SECTION)

DECLARE SUB FreeLibraryWhenCallbackReturns LIB "Kernel32.dll" _
    ALIAS "FreeLibraryWhenCallbackReturns" (BYVAL fpci AS DWORD, _
    BYVAL hmod AS DWORD)

DECLARE FUNCTION CallbackMayRunLong LIB "Kernel32.dll" _
    ALIAS "CallbackMayRunLong" (BYVAL fpci AS DWORD) AS LONG

DECLARE SUB DisassociateCurrentThreadFromCallback LIB "Kernel32.dll" _
    ALIAS "DisassociateCurrentThreadFromCallback" (BYVAL fpci AS DWORD)

DECLARE FUNCTION TrySubmitThreadpoolCallback LIB "Kernel32.dll" _
    ALIAS "TrySubmitThreadpoolCallback" (BYVAL pfns AS DWORD, _
    BYVAL pv AS DWORD, BYVAL pcbe AS DWORD) AS LONG

DECLARE FUNCTION CreateThreadpoolWork LIB "Kernel32.dll" _
    ALIAS "CreateThreadpoolWork" (BYVAL pfnwk AS DWORD, BYVAL pv AS DWORD, _
    BYVAL pcbe AS DWORD) AS DWORD

DECLARE SUB SubmitThreadpoolWork LIB "Kernel32.dll" _
    ALIAS "SubmitThreadpoolWork" (BYVAL pwk AS DWORD)

DECLARE SUB WaitForThreadpoolWorkCallbacks LIB "Kernel32.dll" _
    ALIAS "WaitForThreadpoolWorkCallbacks" (BYVAL pwk AS DWORD, _
    BYVAL fCancelPendingCallbacks AS LONG)

DECLARE SUB CloseThreadpoolWork LIB "Kernel32.dll" _
    ALIAS "CloseThreadpoolWork" (BYVAL pwk AS DWORD)

DECLARE FUNCTION CreateThreadpoolTimer LIB "Kernel32.dll" _
    ALIAS "CreateThreadpoolTimer" (BYVAL pfnit AS DWORD, _
    BYVAL pv AS DWORD, BYVAL pcbe AS DWORD) AS DWORD

DECLARE SUB SetThreadpoolTimer LIB "Kernel32.dll" ALIAS "SetThreadpoolTimer" _
    (BYVAL pti AS DWORD, pftDueTime AS FILETIME, BYVAL msPeriod AS DWORD, _
    BYVAL msWindowLength AS DWORD)

DECLARE FUNCTION IsThreadpoolTimerSet LIB "Kernel32.dll" _
    ALIAS "IsThreadpoolTimerSet" (BYVAL pti AS DWORD) AS LONG

DECLARE SUB WaitForThreadpoolTimerCallbacks LIB "Kernel32.dll" _
    ALIAS "WaitForThreadpoolTimerCallbacks" (BYVAL pti AS DWORD, _
    BYVAL fCancelPendingCallbacks AS LONG)

DECLARE SUB CloseThreadpoolTimer LIB "Kernel32.dll" _
    ALIAS "CloseThreadpoolTimer" (BYVAL pti AS DWORD)

DECLARE FUNCTION CreateThreadpoolWait LIB "Kernel32.dll" _
    ALIAS "CreateThreadpoolWait" (BYVAL pfnwa AS DWORD, BYVAL pv AS DWORD, _
    BYVAL pcbe AS DWORD) AS DWORD

DECLARE SUB SetThreadpoolWait LIB "Kernel32.dll" ALIAS "SetThreadpoolWait" _
    (BYVAL pwa AS DWORD, BYVAL h AS DWORD, pftTimeout AS FILETIME)

DECLARE SUB WaitForThreadpoolWaitCallbacks LIB "Kernel32.dll" _
    ALIAS "WaitForThreadpoolWaitCallbacks" (BYVAL pwa AS DWORD, _
    BYVAL fCancelPendingCallbacks AS LONG)

DECLARE SUB CloseThreadpoolWait LIB "Kernel32.dll" _
    ALIAS "CloseThreadpoolWait" (BYVAL pwa AS DWORD)

DECLARE FUNCTION CreateThreadpoolIo LIB "Kernel32.dll" _
    ALIAS "CreateThreadpoolIo" (BYVAL fl AS DWORD, BYVAL pfnio AS DWORD, _
    BYVAL pv AS DWORD, pbce AS TP_CALLBACK_ENVIRON) AS DWORD

DECLARE SUB StartThreadpoolIo LIB "Kernel32.dll" ALIAS "StartThreadpoolIo" _
    (BYVAL pio AS DWORD)

DECLARE SUB CancelThreadpoolIo LIB "Kernel32.dll" ALIAS "CancelThreadpoolIo" _
    (BYVAL pio AS DWORD)

DECLARE SUB WaitForThreadpoolIoCallbacks LIB "Kernel32.dll" _
    ALIAS "WaitForThreadpoolIoCallbacks" (BYVAL pio AS DWORD, _
    BYVAL fCancelPendingCallbacks AS LONG)  ' BOOL

DECLARE SUB CloseThreadpoolIo LIB "Kernel32.dll" ALIAS "CloseThreadpoolIo" _
    (BYVAL pio AS DWORD)

'
'  Private Namespaces support
'

DECLARE FUNCTION CreatePrivateNamespaceA LIB "Kernel32.dll" _
    ALIAS "CreatePrivateNamespaceA" _
    (lpPrivateNamespaceAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL lpBoundaryDescriptor AS DWORD, lpAliasPrefix AS ASCIIZ) AS DWORD

DECLARE FUNCTION CreatePrivateNamespaceW LIB "Kernel32.dll" _
    ALIAS "CreatePrivateNamespaceW" _
    (lpPrivateNamespaceAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL lpBoundaryDescriptor AS DWORD, lpAliasPrefix AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreatePrivateNamespace LIB "Kernel32.dll" _
    ALIAS "CreatePrivateNamespaceW" _
    (lpPrivateNamespaceAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL lpBoundaryDescriptor AS DWORD, lpAliasPrefix AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION CreatePrivateNamespace LIB "Kernel32.dll" _
    ALIAS "CreatePrivateNamespaceA" _
    (lpPrivateNamespaceAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL lpBoundaryDescriptor AS DWORD, lpAliasPrefix AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION OpenPrivateNamespaceA LIB "Kernel32.dll" _
    ALIAS "OpenPrivateNamespaceA" (BYVAL lpBoundaryDescriptor AS DWORD, _
    lpAliasPrefix AS ASCIIZ) AS DWORD

DECLARE FUNCTION OpenPrivateNamespaceW LIB "Kernel32.dll" _
    ALIAS "OpenPrivateNamespaceW" (BYVAL lpBoundaryDescriptor AS DWORD, _
    lpAliasPrefix AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION OpenPrivateNamespace LIB "Kernel32.dll" _
    ALIAS "OpenPrivateNamespaceW" (BYVAL lpBoundaryDescriptor AS DWORD, _
    lpAliasPrefix AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION OpenPrivateNamespace LIB "Kernel32.dll" _
    ALIAS "OpenPrivateNamespaceA" (BYVAL lpBoundaryDescriptor AS DWORD, _
    lpAliasPrefix AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

%PRIVATE_NAMESPACE_FLAG_DESTROY     = &H00000001

DECLARE FUNCTION ClosePrivateNamespace LIB "Kernel32.dll" _
    ALIAS "ClosePrivateNamespace" (BYVAL hHandle AS DWORD, _
    BYVAL dFlags AS DWORD) AS LONG


'
'  Boundary descriptors support
'

DECLARE FUNCTION CreateBoundaryDescriptorA LIB "Kernel32.dll" _
    ALIAS "CreateBoundaryDescriptorA" (lpName AS ASCIIZ, _
    BYVAL dFlags AS DWORD) AS DWORD

DECLARE FUNCTION CreateBoundaryDescriptorW LIB "Kernel32.dll" _
    ALIAS "CreateBoundaryDescriptorW" (lpName AS WSTRINGZ, _
    BYVAL dFlags AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateBoundaryDescriptor LIB "Kernel32.dll" _
    ALIAS "CreateBoundaryDescriptorW" (lpName AS WSTRINGZ, _
    BYVAL dFlags AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION CreateBoundaryDescriptor LIB "Kernel32.dll" _
    ALIAS "CreateBoundaryDescriptorA" (lpName AS ASCIIZ, _
    BYVAL dFlags AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION AddSIDToBoundaryDescriptor LIB "Kernel32.dll" _
    ALIAS "AddSIDToBoundaryDescriptor" (hBoundaryDescriptor AS DWORD, _
    RequiredSid AS SID) AS LONG

DECLARE FUNCTION AddIntegrityLabelToBoundaryDescriptor LIB "Kernel32.dll" _
    ALIAS "AddIntegrityLabelToBoundaryDescriptor" ( _
    BoundaryDescriptor AS DWORD, _  ' HANDLE
    IntegrityLabel     AS SID) _
    AS LONG

DECLARE SUB DeleteBoundaryDescriptor LIB "Kernel32.dll" _
    ALIAS "DeleteBoundaryDescriptor" (BYVAL hBoundaryDescriptor AS DWORD)

#ENDIF ' %WIN32_WINNT >= &H0600

#ENDIF ' %WIN32_WINNT >= &H0500


#IF (%WIN32_WINNT >= &H0400)
'
' Plug-and-Play API's
'

%HW_PROFILE_GUIDLEN       = 39      ' 36-characters plus NULL terminator
%MAX_PROFILE_LEN          = 80

%DOCKINFO_UNDOCKED        = 1
%DOCKINFO_DOCKED          = 2
%DOCKINFO_USER_SUPPLIED   = 4
%DOCKINFO_USER_UNDOCKED   = (%DOCKINFO_USER_SUPPLIED OR %DOCKINFO_UNDOCKED)
%DOCKINFO_USER_DOCKED     = (%DOCKINFO_USER_SUPPLIED OR %DOCKINFO_DOCKED)

TYPE HW_PROFILE_INFOA
    dwDockInfo      AS DWORD
    szHwProfileGuid AS ASCIIZ * %HW_PROFILE_GUIDLEN
    szHwProfileName AS ASCIIZ * %MAX_PROFILE_LEN
END TYPE

TYPE HW_PROFILE_INFOW
    dwDockInfo      AS DWORD
    szHwProfileGuid AS WSTRINGZ * %HW_PROFILE_GUIDLEN
    szHwProfileName AS WSTRINGZ * %MAX_PROFILE_LEN
END TYPE

#IF %DEF(%UNICODE)
TYPE HW_PROFILE_INFO
    HW_PROFILE_INFOW
END TYPE
#ELSE
TYPE HW_PROFILE_INFO
    HW_PROFILE_INFOA
END TYPE
#ENDIF ' UNICODE

DECLARE FUNCTION GetCurrentHwProfileA LIB "AdvApi32.dll" _
    ALIAS "GetCurrentHwProfileA" (lpHwProfileInfo AS HW_PROFILE_INFOA) AS LONG

DECLARE FUNCTION GetCurrentHwProfileW LIB "AdvApi32.dll" _
    ALIAS "GetCurrentHwProfileW" (lpHwProfileInfo AS HW_PROFILE_INFOW) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetCurrentHwProfile LIB "AdvApi32.dll" _
    ALIAS "GetCurrentHwProfileW" (lpHwProfileInfo AS HW_PROFILE_INFOW) AS LONG
#ELSE
DECLARE FUNCTION GetCurrentHwProfile LIB "AdvApi32.dll" _
    ALIAS "GetCurrentHwProfileA" (lpHwProfileInfo AS HW_PROFILE_INFOA) AS LONG
#ENDIF ' NOT %UNICODE
#ENDIF ' %WIN32_WINNT >= &H0400

'
' Performance counter API's
'

DECLARE FUNCTION QueryPerformanceCounter LIB "Kernel32.dll" _
    ALIAS "QueryPerformanceCounter" (lpPerformanceCount AS QUAD) AS LONG

DECLARE FUNCTION QueryPerformanceFrequency LIB "Kernel32.dll" _
    ALIAS "QueryPerformanceFrequency" (lpFrequency AS QUAD) AS LONG

DECLARE FUNCTION GetVersionExA LIB "Kernel32.dll" ALIAS "GetVersionExA" _
    (lpVersionInformation AS OSVERSIONINFOA) AS LONG

DECLARE FUNCTION GetVersionExW LIB "Kernel32.dll" ALIAS "GetVersionExW" _
    (lpVersionInformation AS OSVERSIONINFOW) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetVersionEx LIB "Kernel32.dll" ALIAS "GetVersionExW" _
    (lpVersionInformation AS OSVERSIONINFOW) AS LONG
#ELSE
DECLARE FUNCTION GetVersionEx LIB "Kernel32.dll" ALIAS "GetVersionExA" _
    (lpVersionInformation AS OSVERSIONINFOA) AS LONG
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION VerifyVersionInfoA LIB "Kernel32.dll" _
    ALIAS "VerifyVersionInfoA" (lpVersionInformation AS OSVERSIONINFOEXA, _
    BYVAL dwTypeMask AS DWORD, BYVAL dwlConditionMask AS QUAD) AS LONG

DECLARE FUNCTION VerifyVersionInfoW LIB "Kernel32.dll" _
    ALIAS "VerifyVersionInfoW" (lpVersionInformation AS OSVERSIONINFOEXW, _
    BYVAL dwTypeMask AS DWORD, BYVAL dwlConditionMask AS QUAD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION VerifyVersionInfo LIB "Kernel32.dll" _
    ALIAS "VerifyVersionInfoW" (lpVersionInformation AS OSVERSIONINFOEXW, _
    BYVAL dwTypeMask AS DWORD, BYVAL dwlConditionMask AS QUAD) AS LONG
#ELSE
DECLARE FUNCTION VerifyVersionInfo LIB "Kernel32.dll" _
    ALIAS "VerifyVersionInfoA" (lpVersionInformation AS OSVERSIONINFOEXA, _
    BYVAL dwTypeMask AS DWORD, BYVAL dwlConditionMask AS QUAD) AS LONG
#ENDIF ' NOT %UNICODE

#IF (%WIN32_WINNT >= &H0600)

DECLARE FUNCTION GetProductInfo LIB "Kernel32.dll" ALIAS "GetProductInfo" ( _
    BYVAL dwOSMajorVersion AS DWORD, BYVAL dwOSMinorVersion AS DWORD, _
    BYVAL dwSpMajorVersion AS DWORD, BYVAL dwSpMinorVersion AS DWORD, _
    pdwReturnedProductType AS DWORD) AS LONG

#ENDIF

' DOS and OS/2 Compatible Error Code definitions returned by the Win32 Base
' API functions.
'

#INCLUDE "WinError.inc"

' Abnormal termination codes

%TC_NORMAL     = 0
%TC_HARDERR    = 1
%TC_GP_TRAP    = 2
%TC_SIGNAL     = 3

#IF (%WINVER >= &H0400)
'
' Power Management APIs
'

%AC_LINE_OFFLINE                = &H00?
%AC_LINE_ONLINE                 = &H01?
%AC_LINE_BACKUP_POWER           = &H02?
%AC_LINE_UNKNOWN                = &HFF?

%BATTERY_FLAG_HIGH              = &H01?
%BATTERY_FLAG_LOW               = &H02?
%BATTERY_FLAG_CRITICAL          = &H04?
%BATTERY_FLAG_CHARGING          = &H08?
%BATTERY_FLAG_NO_BATTERY        = &H80?
%BATTERY_FLAG_UNKNOWN           = &HFF?

%BATTERY_PERCENTAGE_UNKNOWN     = &HFF?

%BATTERY_LIFE_UNKNOWN       = &HFFFFFFFF???

TYPE SYSTEM_POWER_STATUS
    ACLineStatus        AS BYTE
    BatteryFlag         AS BYTE
    BatteryLifePercent  AS BYTE
    Reserved1           AS BYTE
    BatteryLifeTime     AS DWORD
    BatteryFullLifeTime AS DWORD
END TYPE

DECLARE FUNCTION GetSystemPowerStatus LIB "Kernel32.dll" _
    ALIAS "GetSystemPowerStatus" (lpSystemPowerStatus AS SYSTEM_POWER_STATUS) _
    AS LONG

DECLARE FUNCTION SetSystemPowerState LIB "Kernel32.dll" _
    ALIAS "SetSystemPowerState" (BYVAL fSuspend AS LONG, _
    BYVAL fForce AS LONG) AS LONG

#ENDIF ' WINVER >= &H0400

#IF (%WIN32_WINNT >= &H0500)
'
' Very Large Memory API Subset
'

DECLARE FUNCTION AllocateUserPhysicalPages LIB "Kernel32.dll" _
    ALIAS "AllocateUserPhysicalPages" (BYVAL hProcess AS DWORD, _
    NumberOfPages AS DWORD, PageArray AS DWORD) AS LONG

#IF %WIN32_WINNT >= &H0600

DECLARE FUNCTION AllocateUserPhysicalPagesNuma LIB "Kernel32.dll" _
    ALIAS "AllocateUserPhysicalPagesNuma" (BYVAL hProcess AS DWORD, _
    NumberOfPages AS DWORD, PageArray AS DWORD, BYVAL nndPreferred AS DWORD) _
    AS LONG

#ENDIF ' %WIN32_WINNT >= &H0600

DECLARE FUNCTION FreeUserPhysicalPages LIB "Kernel32.dll" _
    ALIAS "FreeUserPhysicalPages" (BYVAL hProcess AS DWORD, _
    NumberOfPages AS DWORD, PageArray AS DWORD) AS LONG

DECLARE FUNCTION MapUserPhysicalPages LIB "Kernel32.dll" _
    ALIAS "MapUserPhysicalPages" (BYVAL VirtualAddress AS DWORD, _
    BYVAL NumberOfPages AS DWORD, PageArray AS DWORD) AS LONG

DECLARE FUNCTION MapUserPhysicalPagesScatter LIB "Kernel32.dll" _
    ALIAS "MapUserPhysicalPagesScatter" (BYVAL VirtualAddresses AS DWORD, _
    BYVAL NumberOfPages AS DWORD, PageArray AS DWORD) AS LONG

DECLARE FUNCTION CreateJobObjectA LIB "Kernel32.dll" ALIAS "CreateJobObjectA" _
    (lpJobAttributes AS SECURITY_ATTRIBUTES, lpName AS ASCIIZ) AS DWORD

DECLARE FUNCTION CreateJobObjectW LIB "Kernel32.dll" ALIAS "CreateJobObjectW" _
    (lpJobAttributes AS SECURITY_ATTRIBUTES, lpName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateJobObject LIB "Kernel32.dll" ALIAS "CreateJobObjectW" _
    (lpJobAttributes AS SECURITY_ATTRIBUTES, lpName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION CreateJobObject LIB "Kernel32.dll" ALIAS "CreateJobObjectA" _
    (lpJobAttributes AS SECURITY_ATTRIBUTES, lpName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION OpenJobObjectA LIB "Kernel32.dll" ALIAS "OpenJobObjectA" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    lpName AS ASCIIZ) AS DWORD

DECLARE FUNCTION OpenJobObjectW LIB "Kernel32.dll" ALIAS "OpenJobObjectW" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    lpName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION OpenJobObject LIB "Kernel32.dll" ALIAS "OpenJobObjectW" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    lpName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION OpenJobObject LIB "Kernel32.dll" ALIAS "OpenJobObjectA" _
    (BYVAL dwDesiredAccess AS DWORD, BYVAL bInheritHandle AS LONG, _
    lpName AS ASCIIZ) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION AssignProcessToJobObject LIB "Kernel32.dll" _
    ALIAS "AssignProcessToJobObject" (BYVAL hJob AS DWORD, _
    BYVAL hProcess AS DWORD) AS LONG

DECLARE FUNCTION TerminateJobObject LIB "Kernel32.dll" _
    ALIAS "TerminateJobObject" (BYVAL hJob AS DWORD, _
    BYVAL uExitCode AS DWORD) AS LONG

DECLARE FUNCTION QueryInformationJobObject LIB "Kernel32.dll" _
    ALIAS "QueryInformationJobObject" (BYVAL hJob AS DWORD, _
    BYVAL JobObjectInformationClass AS LONG, _
    BYVAL lpJobObjectInformation AS DWORD, _
    BYVAL cbJobObjectInformationLength AS DWORD, lpReturnlength AS DWORD) _
    AS LONG

DECLARE FUNCTION SetInformationJobObject LIB "Kernel32.dll" _
    ALIAS "SetInformationJobObject" (BYVAL hJob AS DWORD, _
    BYVAL JobObjectInformationClass AS LONG, _
    BYVAL lpJobObjectInformation AS DWORD, _
    BYVAL cbJobObjectInformationLength AS DWORD) AS LONG

#IF (%WIN32_WINNT >= &H0501)

DECLARE FUNCTION IsProcessInJob LIB "Kernel32.dll" ALIAS "IsProcessInJob" _
    (BYVAL hProcess AS DWORD, BYVAL hJob AS DWORD, bResult AS LONG) AS LONG

#ENDIF

DECLARE FUNCTION CreateJobSet LIB "Kernel32.dll" ALIAS "CreateJobSet" _
    (BYVAL NumJob AS DWORD, UserJobSet AS JOB_SET_ARRAY, _
    BYVAL dFlags AS DWORD) AS LONG

DECLARE FUNCTION AddVectoredExceptionHandler LIB "Kernel32.dll" _
    ALIAS "AddVectoredExceptionHandler" (BYVAL dFirst AS DWORD, _
    BYVAL pHandler AS DWORD) AS DWORD

DECLARE FUNCTION RemoveVectoredExceptionHandler LIB "Kernel32.dll" _
    ALIAS "RemoveVectoredExceptionHandler" (BYVAL pHandle AS DWORD) AS DWORD

DECLARE FUNCTION AddVectoredContinueHandler LIB "Kernel32.dll" _
    ALIAS "AddVectoredContinueHandler" (BYVAL dFirst AS DWORD, _
    BYVAL pHandler AS DWORD) AS DWORD

DECLARE FUNCTION RemoveVectoredContinueHandler LIB "Kernel32.dll" _
    ALIAS "RemoveVectoredContinueHandler" (BYVAL pHandle AS DWORD) AS DWORD

'
' New Volume Mount Point API.
'

DECLARE FUNCTION FindFirstVolumeA LIB "Kernel32.dll" ALIAS "FindFirstVolumeA" _
    (lpszVolumeName AS ASCIIZ, BYVAL cchBufferLength AS DWORD) AS DWORD

DECLARE FUNCTION FindFirstVolumeW LIB "Kernel32.dll" ALIAS "FindFirstVolumeW" _
    (lpszVolumeName AS WSTRINGZ, BYVAL cchBufferLength AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION FindFirstVolume LIB "Kernel32.dll" ALIAS "FindFirstVolumeW" _
    (lpszVolumeName AS WSTRINGZ, BYVAL cchBufferLength AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION FindFirstVolume LIB "Kernel32.dll" ALIAS "FindFirstVolumeA" _
    (lpszVolumeName AS ASCIIZ, BYVAL cchBufferLength AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION FindNextVolumeA LIB "Kernel32.dll" ALIAS "FindNextVolumeA" _
    (BYVAL hFindVolume AS DWORD, lpszVolumeName AS ASCIIZ, _
    BYVAL cchBufferLength AS DWORD) AS LONG

DECLARE FUNCTION FindNextVolumeW LIB "Kernel32.dll" ALIAS "FindNextVolumeW" _
    (BYVAL hFindVolume AS DWORD, lpszVolumeName AS WSTRINGZ, _
    BYVAL cchBufferLength AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION FindNextVolume LIB "Kernel32.dll" ALIAS "FindNextVolumeW" _
    (BYVAL hFindVolume AS DWORD, lpszVolumeName AS WSTRINGZ, _
    BYVAL cchBufferLength AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION FindNextVolume LIB "Kernel32.dll" ALIAS "FindNextVolumeA" _
    (BYVAL hFindVolume AS DWORD, lpszVolumeName AS ASCIIZ, _
    BYVAL cchBufferLength AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION FindVolumeClose LIB "Kernel32.dll" ALIAS "FindVolumeClose" _
    (BYVAL hFindVolume AS DWORD) AS LONG

DECLARE FUNCTION FindFirstVolumeMountPointA LIB "Kernel32.dll" _
    ALIAS "FindFirstVolumeMountPointA" (lpszRootPathName AS ASCIIZ, _
    lpszVolumeMountPoint AS ASCIIZ, BYVAL cchBufferLength AS DWORD) AS DWORD

DECLARE FUNCTION FindFirstVolumeMountPointW LIB "Kernel32.dll" _
    ALIAS "FindFirstVolumeMountPointW" (lpszRootPathName AS WSTRINGZ, _
    lpszVolumeMountPoint AS WSTRINGZ, BYVAL cchBufferLength AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION FindFirstVolumeMountPoint LIB "Kernel32.dll" _
    ALIAS "FindFirstVolumeMountPointW" (lpszRootPathName AS WSTRINGZ, _
    lpszVolumeMountPoint AS WSTRINGZ, BYVAL cchBufferLength AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION FindFirstVolumeMountPoint LIB "Kernel32.dll" _
    ALIAS "FindFirstVolumeMountPointA" (lpszRootPathName AS ASCIIZ, _
    lpszVolumeMountPoint AS ASCIIZ, BYVAL cchBufferLength AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION FindNextVolumeMountPointA LIB "Kernel32.dll" _
    ALIAS "FindNextVolumeMountPointA" (BYVAL hFindVolumeMountPoint AS DWORD, _
    lpszVolumeMountPoint AS ASCIIZ, BYVAL cchBufferLength AS DWORD) AS LONG

DECLARE FUNCTION FindNextVolumeMountPointW LIB "Kernel32.dll" _
    ALIAS "FindNextVolumeMountPointW" (BYVAL hFindVolumeMountPoint AS DWORD, _
    lpszVolumeMountPoint AS WSTRINGZ, BYVAL cchBufferLength AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION FindNextVolumeMountPoint LIB "Kernel32.dll" _
    ALIAS "FindNextVolumeMountPointW" (BYVAL hFindVolumeMountPoint AS DWORD, _
    lpszVolumeMountPoint AS WSTRINGZ, BYVAL cchBufferLength AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION FindNextVolumeMountPoint LIB "Kernel32.dll" _
    ALIAS "FindNextVolumeMountPointA" (BYVAL hFindVolumeMountPoint AS DWORD, _
    lpszVolumeMountPoint AS ASCIIZ, BYVAL cchBufferLength AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION FindVolumeMountPointClose LIB "Kernel32.dll" _
    ALIAS "FindVolumeMountPointClose" (BYVAL hFindVolumeMountPoint AS DWORD) _
    AS LONG

DECLARE FUNCTION SetVolumeMountPointA LIB "Kernel32.dll" _
    ALIAS "SetVolumeMountPointA" (lpszVolumeMountPoint AS ASCIIZ, _
    lpszVolumeName AS ASCIIZ) AS LONG

DECLARE FUNCTION SetVolumeMountPointW LIB "Kernel32.dll" _
    ALIAS "SetVolumeMountPointW" (lpszVolumeMountPoint AS WSTRINGZ, _
    lpszVolumeName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetVolumeMountPoint LIB "Kernel32.dll" _
    ALIAS "SetVolumeMountPointW" (lpszVolumeMountPoint AS WSTRINGZ, _
    lpszVolumeName AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION SetVolumeMountPoint LIB "Kernel32.dll" _
    ALIAS "SetVolumeMountPointA" (lpszVolumeMountPoint AS ASCIIZ, _
    lpszVolumeName AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DeleteVolumeMountPointA LIB "Kernel32.dll" _
    ALIAS "DeleteVolumeMountPointA" (lpszVolumeMountPoint AS ASCIIZ) AS LONG

DECLARE FUNCTION DeleteVolumeMountPointW LIB "Kernel32.dll" _
    ALIAS "DeleteVolumeMountPointW" (lpszVolumeMountPoint AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION DeleteVolumeMountPoint LIB "Kernel32.dll" _
    ALIAS "DeleteVolumeMountPointW" (lpszVolumeMountPoint AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION DeleteVolumeMountPoint LIB "Kernel32.dll" _
    ALIAS "DeleteVolumeMountPointA" (lpszVolumeMountPoint AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetVolumeNameForVolumeMountPointA LIB "Kernel32.dll" _
    ALIAS "GetVolumeNameForVolumeMountPointA" _
    (lpszVolumeMountPoint AS ASCIIZ, lpszVolumeName AS ASCIIZ, _
    BYVAL cchBufferLength AS DWORD) AS LONG

DECLARE FUNCTION GetVolumeNameForVolumeMountPointW LIB "Kernel32.dll" _
    ALIAS "GetVolumeNameForVolumeMountPointW" _
    (lpszVolumeMountPoint AS WSTRINGZ, lpszVolumeName AS WSTRINGZ, _
    BYVAL cchBufferLength AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetVolumeNameForVolumeMountPoint LIB "Kernel32.dll" _
    ALIAS "GetVolumeNameForVolumeMountPointW" _
    (lpszVolumeMountPoint AS WSTRINGZ, lpszVolumeName AS WSTRINGZ, _
    BYVAL cchBufferLength AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetVolumeNameForVolumeMountPoint LIB "Kernel32.dll" _
    ALIAS "GetVolumeNameForVolumeMountPointA" _
    (lpszVolumeMountPoint AS ASCIIZ, lpszVolumeName AS ASCIIZ, _
    BYVAL cchBufferLength AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetVolumePathNameA LIB "Kernel32.dll" _
    ALIAS "GetVolumePathNameA" (lpszFileName AS ASCIIZ, _
    lpszVolumePathName AS ASCIIZ, BYVAL cchBufferLength AS DWORD) AS LONG

DECLARE FUNCTION GetVolumePathNameW LIB "Kernel32.dll" _
    ALIAS "GetVolumePathNameW" (lpszFileName AS WSTRINGZ, _
    lpszVolumePathName AS WSTRINGZ, BYVAL cchBufferLength AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetVolumePathName LIB "Kernel32.dll" _
    ALIAS "GetVolumePathNameW" (lpszFileName AS WSTRINGZ, _
    lpszVolumePathName AS WSTRINGZ, BYVAL cchBufferLength AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetVolumePathName LIB "Kernel32.dll" _
    ALIAS "GetVolumePathNameA" (lpszFileName AS ASCIIZ, _
    lpszVolumePathName AS ASCIIZ, BYVAL cchBufferLength AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF

#IF (%WIN32_WINNT >= &H0501)

DECLARE FUNCTION GetVolumePathNamesForVolumeNameA LIB "Kernel32.dll" _
    ALIAS "GetVolumePathNamesForVolumeNameA" (lpszVolumeName AS ASCIIZ, _
    BYVAL lpszVolumePathNames AS DWORD, BYVAL ccBufferLength AS DWORD, _
    lpcchReturnLength AS DWORD) AS LONG

DECLARE FUNCTION GetVolumePathNamesForVolumeNameW LIB "Kernel32.dll" _
    ALIAS "GetVolumePathNamesForVolumeNameW" (lpszVolumeName AS WSTRINGZ, _
    BYVAL lpszVolumePathNames AS DWORD, BYVAL ccBufferLength AS DWORD, _
    lpcchReturnLength AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetVolumePathNamesForVolumeName LIB "Kernel32.dll" _
    ALIAS "GetVolumePathNamesForVolumeNameW" (lpszVolumeName AS WSTRINGZ, _
    BYVAL lpszVolumePathNames AS DWORD, BYVAL ccBufferLength AS DWORD, _
    lpcchReturnLength AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetVolumePathNamesForVolumeName LIB "Kernel32.dll" _
    ALIAS "GetVolumePathNamesForVolumeNameA" (lpszVolumeName AS ASCIIZ, _
    BYVAL lpszVolumePathNames AS DWORD, BYVAL ccBufferLength AS DWORD, _
    lpcchReturnLength AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' #IF (%WIN32_WINNT >= &H0501)

' [Microsoft never defines WIN32_FUSION]
'#IF (%WIN32_WINNT >= &H0500) OR (%WIN32_FUSION >= &H0100) OR %ISOLATION_AWARE_ENABLED
#IF (%WIN32_WINNT >= &H0500) OR %ISOLATION_AWARE_ENABLED

%ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID   = &H00000001
%ACTCTX_FLAG_LANGID_VALID                   = &H00000002
%ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID       = &H00000004
%ACTCTX_FLAG_RESOURCE_NAME_VALID            = &H00000008
%ACTCTX_FLAG_SET_PROCESS_DEFAULT            = &H00000010
%ACTCTX_FLAG_APPLICATION_NAME_VALID         = &H00000020
%ACTCTX_FLAG_SOURCE_IS_ASSEMBLYREF          = &H00000040
%ACTCTX_FLAG_HMODULE_VALID                  = &H00000080

TYPE ACTCTXA
    cbSize                 AS DWORD
    dwFlags                AS DWORD
    lpSource               AS ASCIIZ PTR
    wProcessorArchitecture AS WORD
    wLangId                AS WORD
    lpAssemblyDirectory    AS ASCIIZ PTR
    lpResourceName         AS ASCIIZ PTR
    lpApplicationName      AS ASCIIZ PTR
    hModule                AS DWORD
END TYPE

TYPE ACTCTXW
    cbSize                 AS DWORD
    dwFlags                AS DWORD
    lpSource               AS WSTRINGZ PTR
    wProcessorArchitecture AS WORD
    wLangId                AS WORD
    lpAssemblyDirectory    AS WSTRINGZ PTR
    lpResourceName         AS WSTRINGZ PTR
    lpApplicationName      AS WSTRINGZ PTR
    hModule                AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE ACTCTX
    ACTCTXW
END TYPE
#ELSE
TYPE ACTCTX
    ACTCTXA
END TYPE
#ENDIF ' UNICODE


DECLARE FUNCTION CreateActCtxA LIB "Kernel32.dll" ALIAS "CreateActCtxA" _
    (pActCtx AS ACTCTXA) AS DWORD

DECLARE FUNCTION CreateActCtxW LIB "Kernel32.dll" ALIAS "CreateActCtxW" _
    (pActCtx AS ACTCTXW) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateActCtx LIB "Kernel32.dll" ALIAS "CreateActCtxW" _
    (pActCtx AS ACTCTXW) AS DWORD
#ELSE
DECLARE FUNCTION CreateActCtx LIB "Kernel32.dll" ALIAS "CreateActCtxA" _
    (pActCtx AS ACTCTXA) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE SUB AddRefActCtx LIB "Kernel32.dll" ALIAS "AddRefActCtx" _
    (BYVAL hActCtx AS DWORD)

DECLARE SUB ReleaseActCtx LIB "Kernel32.dll" ALIAS "ReleaseActCtx" _
    (BYVAL hActCtx AS DWORD)

DECLARE FUNCTION ZombifyActCtx LIB "Kernel32.dll" ALIAS "ZombifyActCtx" _
    (BYVAL hActCtx AS DWORD) AS LONG

DECLARE FUNCTION ActivateActCtx LIB "Kernel32.dll" ALIAS "ActivateActCtx" _
    (BYVAL hActCtx AS DWORD, lpCookie AS DWORD) AS LONG

%DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION = &H00000001

DECLARE FUNCTION DeactivateActCtx LIB "Kernel32.dll" ALIAS "DeactivateActCtx" _
    (BYVAL dwFlags AS DWORD, BYVAL ulCookie AS DWORD) AS LONG

DECLARE FUNCTION GetCurrentActCtx LIB "Kernel32.dll" ALIAS "GetCurrentActCtx" _
    (lphActCtx AS DWORD) AS LONG

TYPE ACTCTX_SECTION_KEYED_DATA_2600
    cbSize                    AS DWORD
    ulDataFormatVersion       AS DWORD
    lpData                    AS DWORD
    ulLength                  AS DWORD
    lpSectionGlobalData       AS DWORD
    ulSectionGlobalDataLength AS DWORD
    lpSectionBase             AS DWORD
    ulSectionTotalLength      AS DWORD
    hActCtx                   AS DWORD
    ulAssemblyRosterIndex     AS DWORD
END TYPE

TYPE ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA
    lpInformation             AS DWORD
    lpSectionBase             AS DWORD
    ulSectionLength           AS DWORD
    lpSectionGlobalDataBase   AS DWORD
    ulSectionGlobalDataLength AS DWORD
END TYPE

TYPE ACTCTX_SECTION_KEYED_DATA
    cbSize                    AS DWORD
    ulDataFormatVersion       AS DWORD
    lpData                    AS DWORD
    ulLength                  AS DWORD
    lpSectionGlobalData       AS DWORD
    ulSectionGlobalDataLength AS DWORD
    lpSectionBase             AS DWORD
    ulSectionTotalLength      AS DWORD
    hActCtx                   AS DWORD
    ulAssemblyRosterIndex     AS DWORD
' 2600 stops here
    ulFlags                   AS DWORD
    AssemblyMetadata          AS ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA
END TYPE

%FIND_ACTCTX_SECTION_KEY_RETURN_HACTCTX           = &H00000001
%FIND_ACTCTX_SECTION_KEY_RETURN_FLAGS             = &H00000002
%FIND_ACTCTX_SECTION_KEY_RETURN_ASSEMBLY_METADATA = &H00000004


DECLARE FUNCTION FindActCtxSectionStringA LIB "Kernel32.dll" _
    ALIAS "FindActCtxSectionStringA" (BYVAL dwFlags AS DWORD, _
    lpExtensionGuid AS GUID, BYVAL ulSectionId AS DWORD, _
    lpStringToFind AS ASCIIZ, ReturnedData AS ACTCTX_SECTION_KEYED_DATA) _
    AS LONG

DECLARE FUNCTION FindActCtxSectionStringW LIB "Kernel32.dll" _
    ALIAS "FindActCtxSectionStringW" (BYVAL dwFlags AS DWORD, _
    lpExtensionGuid AS GUID, BYVAL ulSectionId AS DWORD, _
    lpStringToFind AS WSTRINGZ, ReturnedData AS ACTCTX_SECTION_KEYED_DATA) _
    AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION FindActCtxSectionString LIB "Kernel32.dll" _
    ALIAS "FindActCtxSectionStringW" (BYVAL dwFlags AS DWORD, _
    lpExtensionGuid AS GUID, BYVAL ulSectionId AS DWORD, _
    lpStringToFind AS WSTRINGZ, ReturnedData AS ACTCTX_SECTION_KEYED_DATA) _
    AS LONG
#ELSE
DECLARE FUNCTION FindActCtxSectionString LIB "Kernel32.dll" _
    ALIAS "FindActCtxSectionStringA" (BYVAL dwFlags AS DWORD, _
    lpExtensionGuid AS GUID, BYVAL ulSectionId AS DWORD, _
    lpStringToFind AS ASCIIZ, ReturnedData AS ACTCTX_SECTION_KEYED_DATA) _
    AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION FindActCtxSectionGuid LIB "Kernel32.dll" _
    ALIAS "FindActCtxSectionGuid" (BYVAL dwFlags AS DWORD, _
    lpExtensionGuid AS GUID, BYVAL ulSectionId AS DWORD, _
    lpGuidToFind AS GUID, ReturnedData AS ACTCTX_SECTION_KEYED_DATA) AS LONG

#IF NOT %DEF(%ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED)

TYPE ACTIVATION_CONTEXT_BASIC_INFORMATION
    hActCtx AS DWORD
    dwFlags AS DWORD
END TYPE

%ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED = 1

#ENDIF ' NOT %DEF(%ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED)

%QUERY_ACTCTX_FLAG_USE_ACTIVE_ACTCTX = &H00000004
%QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE = &H00000008
%QUERY_ACTCTX_FLAG_ACTCTX_IS_ADDRESS = &H00000010
%QUERY_ACTCTX_FLAG_NO_ADDREF         = &H80000000???


'
' switch (ulInfoClass)
'
'  case ActivationContextBasicInformation:
'    pvSubInstance == NULL
'    pvBuffer is of type PACTIVATION_CONTEXT_BASIC_INFORMATION
'
'  case ActivationContextDetailedInformation:
'    pvSubInstance == NULL
'    pvBuffer is of type PACTIVATION_CONTEXT_DETAILED_INFORMATION
'
'  case AssemblyDetailedInformationInActivationContext:
'    pvSubInstance is of type PULONG
'      *pvSubInstance < ACTIVATION_CONTEXT_DETAILED_INFORMATION::ulAssemblyCount
'    pvBuffer is of type PACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION
'
'  case FileInformationInAssemblyOfAssemblyInActivationContext:
'    pvSubInstance is of type PACTIVATION_CONTEXT_QUERY_INDEX
'      pvSubInstance->ulAssemblyIndex < ACTIVATION_CONTEXT_DETAILED_INFORMATION::ulAssemblyCount
'      pvSubInstance->ulFileIndexInAssembly < ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION::ulFileCount
'    pvBuffer is of type PASSEMBLY_FILE_DETAILED_INFORMATION
'
'  case RunlevelInformationInActivationContext :
'    pvSubInstance == NULL
'    pvBuffer is of type PACTIVATION_CONTEXT_RUN_LEVEL_INFORMATION
'
' String are placed after the structs.
'
DECLARE FUNCTION QueryActCtxW LIB "Kernel32.dll" ALIAS "QueryActCtxW" _
    (BYVAL dwFlags AS DWORD, BYVAL hActCtx AS DWORD, _
    BYVAL pvSubInstance AS DWORD, BYVAL ulInfoClass AS DWORD, _
    BYVAL pvBuffer AS DWORD, BYVAL cbBuffer AS DWORD, _
    pcbWrittenOrRequired AS DWORD) AS LONG

' [undocumented callback function]
'typedef BOOL (WINAPI * PQUERYACTCTXW_FUNC)(
'         DWORD dwFlags,
'         DWORD hActCtx,
'    __in_opt  PVOID pvSubInstance,
'         DWORD ulInfoClass,
'    __out_bcount_part_opt(cbBuffer, *pcbWrittenOrRequired) PVOID pvBuffer,
'         SIZE_T cbBuffer,
'    __out_opt SIZE_T *pcbWrittenOrRequired
'    );

#ENDIF ' (%WIN32_WINNT > &H0500) OR (%WIN32_FUSION >= &H0100) OR %ISOLATION_AWARE_ENABLED


DECLARE FUNCTION ProcessIdToSessionId LIB "Kernel32.dll" _
    ALIAS "ProcessIdToSessionId" (BYVAL dwProcessId AS DWORD, _
    pSessionId AS DWORD) AS LONG

#IF %WIN32_WINNT >= &H0501

DECLARE FUNCTION WTSGetActiveConsoleSessionId LIB "Kernel32.dll" _
    ALIAS "WTSGetActiveConsoleSessionId" () AS DWORD

DECLARE FUNCTION IsWow64Process LIB "Kernel32.dll" ALIAS "IsWow64Process" _
    (BYVAL hProcess AS DWORD, Wow64Process AS LONG) AS LONG

#ENDIF ' (%WIN32_WINNT >= &H0501)

DECLARE FUNCTION GetLogicalProcessorInformation LIB "Kernel32.dll" _
    ALIAS "GetLogicalProcessorInformation" _
    (pBuffer AS SYSTEM_LOGICAL_PROCESSOR_INFORMATION, _
    ReturnedLength AS DWORD) AS LONG

#IF %WIN32_WINNT >= &H0601

DECLARE FUNCTION GetLogicalProcessorInformationEx LIB "Kernel32.dll" _
    ALIAS "GetLogicalProcessorInformationEx" ( _
    BYVAL RelationshipType AS LOGICAL_PROCESSOR_RELATIONSHIP_enum, _
    Buffer AS SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX, _
    ReturnedLength AS DWORD) _
    AS LONG

DECLARE FUNCTION GetActiveProcessorGroupCount LIB "Kernel32.dll" _
    ALIAS "GetActiveProcessorGroupCount" () AS WORD

DECLARE FUNCTION GetMaximumProcessorGroupCount LIB "Kernel32.dll" _
    ALIAS "GetMaximumProcessorGroupCount" () AS WORD

DECLARE FUNCTION GetActiveProcessorCount LIB "Kernel32.dll" _
    ALIAS "GetActiveProcessorCount" (BYVAL GroupNumber AS WORD) AS DWORD

DECLARE FUNCTION GetMaximumProcessorCount LIB "Kernel32.dll" _
    ALIAS "GetMaximumProcessorCount" (BYVAL GroupNumber AS WORD) AS DWORD

#ENDIF ' (%WIN32_WINNT >= &H0601)

'
' NUMA Information routines.
'

DECLARE FUNCTION GetNumaHighestNodeNumber LIB "Kernel32.dll" _
    ALIAS "GetNumaHighestNodeNumber" (pHighestNodeNumber AS DWORD) AS LONG

DECLARE FUNCTION GetNumaProcessorNode LIB "Kernel32.dll" _
    ALIAS "GetNumaProcessorNode" (BYVAL Processor AS BYTE, _
    NodeNumber AS BYTE) AS LONG

#IF %WIN32_WINNT >= &H0601

DECLARE FUNCTION GetNumaNodeNumberFromHandle LIB "Kernel32.dll" _
    ALIAS "GetNumaNodeNumberFromHandle" (BYVAL hFile AS DWORD, _
    NodeNumber AS WORD) AS LONG

#ENDIF  ' #IF %WIN32_WINNT >= &H0601

#IF %WIN32_WINNT >= &H0601

DECLARE FUNCTION GetNumaProcessorNodeEx LIB "Kernel32.dll" _
    ALIAS "GetNumaProcessorNodeEx" (Processor AS PROCESSOR_NUMBER, _
    NodeNumber AS WORD) AS LONG

#ENDIF  ' #IF %WIN32_WINNT >= &H0601

DECLARE FUNCTION GetNumaNodeProcessorMask LIB "Kernel32.dll" _
    ALIAS "GetNumaNodeProcessorMask" (BYVAL Node AS BYTE, _
    ProcessorMask AS QUAD) AS LONG

#IF %WIN32_WINNT >= &H0601

DECLARE FUNCTION GetNumaNodeProcessorMaskEx LIB "Kernel32.dll" _
    ALIAS "GetNumaNodeProcessorMaskEx" (BYVAL Node AS BYTE, _
    ProcessorMask AS GROUP_AFFINITY) AS LONG

#ENDIF  ' #IF %WIN32_WINNT >= &H0601

DECLARE FUNCTION GetNumaAvailableMemoryNode LIB "Kernel32.dll" _
    ALIAS "GetNumaAvailableMemoryNode" (BYVAL Node AS BYTE, _
    BYVAL AvailableBytes AS QUAD) AS LONG

#IF %WIN32_WINNT >= &H0601

DECLARE FUNCTION GetNumaAvailableMemoryNodeEx LIB "Kernel32.dll" _
    ALIAS "GetNumaAvailableMemoryNodeEx" (BYVAL Node AS WORD, _
    BYVAL AvailableBytes AS QUAD) AS LONG

#ENDIF  ' #IF %WIN32_WINNT >= &H0601

#IF (%WIN32_WINNT >= &H0600)

DECLARE FUNCTION GetNumaProximityNode LIB "Kernel32.dll" _
    ALIAS "GetNumaProximityNode" (BYVAL ProximityId AS DWORD, _
    NodeNumber AS BYTE) AS LONG

#ENDIF ' #if (%WIN32_WINNT >= &H0600)

#IF (%WIN32_WINNT >= &H0601)

DECLARE FUNCTION GetNumaProximityNodeEx LIB "Kernel32.dll" _
    ALIAS "GetNumaProximityNodeEx" (BYVAL ProximityId AS DWORD, _
    NodeNumber AS WORD) AS LONG

#ENDIF ' #if (%WIN32_WINNT >= &H0601)

'
' Application restart and data recovery callback
'
DECLARE FUNCTION APPLICATION_RECOVERY_CALLBACK (BYVAL pvParameter AS DWORD) _
    AS DWORD

'
' Max length of commandline in characters (including the NULL character that can be registered for restart)
'
'%RESTART_MAX_CMD_LINE  = 2048
%RESTART_MAX_CMD_LINE  = 1024


'
' Do not restart the process for termination due to application crashes
'
%RESTART_NO_CRASH      = 1

'
' Do not restart the process for termination due to application hangs
'
%RESTART_NO_HANG       = 2

'
' Do not restart the process for termination due to patch installations
'
%RESTART_NO_PATCH      = 4

'
' Do not restart the process when the system is rebooted due to patch installations
'
%RESTART_NO_REBOOT      = 8

DECLARE FUNCTION RegisterApplicationRecoveryCallback LIB "Kernel32.dll" _
    ALIAS "RegisterApplicationRecoveryCallback" ( _
    BYVAL pRecoveryCallback AS DWORD, BYVAL pvParameter AS DWORD, _
    BYVAL dwPingInterval AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION UnregisterApplicationRecoveryCallback LIB "Kernel32.dll" _
    ALIAS "UnregisterApplicationRecoveryCallback" () AS LONG

DECLARE FUNCTION RegisterApplicationRestart LIB "Kernel32.dll" _
    ALIAS "RegisterApplicationRestart" (pwzCommandLine AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION UnregisterApplicationRestart LIB "Kernel32.dll" _
    ALIAS "UnregisterApplicationRestart" () AS LONG

%RECOVERY_DEFAULT_PING_INTERVAL = 5000
%RECOVERY_MAX_PING_INTERVAL     = (5 * 60 * 1000)

DECLARE FUNCTION GetApplicationRecoveryCallback LIB "Kernel32.dll" _
    ALIAS "GetApplicationRecoveryCallback" (BYVAL hProcess AS DWORD, _
    BYVAL pRecoveryCallback AS DWORD, BYVAL ppvParameter AS DWORD, _
    pdwPingInterval AS DWORD, pdwFlags AS DWORD) AS LONG

DECLARE FUNCTION GetApplicationRestartSettings LIB "Kernel32.dll" _
    ALIAS "GetApplicationRestartSettings" (BYVAL hProcess AS DWORD, _
    pwzCommandLine AS WSTRINGZ, pcchSize AS DWORD, pdwFlags AS DWORD) AS LONG

DECLARE FUNCTION ApplicationRecoveryInProgress LIB "Kernel32.dll" _
    ALIAS "ApplicationRecoveryInProgress" (pbCancelled AS LONG) AS LONG

DECLARE SUB ApplicationRecoveryFinished LIB "Kernel32.dll" _
    ALIAS "ApplicationRecoveryFinished" (BYVAL bSuccess AS LONG)

#IF (%WIN32_WINNT >= &H0600)

MACRO FILE_INFO_BY_HANDLE_CLASS_enum=LONG
ENUM FILE_INFO_BY_HANDLE_CLASS SINGULAR
    FileBasicInfo
    FileStandardInfo
    FileNameInfo
    FileRenameInfo
    FileDispositionInfo
    FileAllocationInfo
    FileEndOfFileInfo
    FileStreamInfo
    FileCompressionInfo
    FileAttributeTagInfo
    FileIdBothDirectoryInfo
    FileIdBothDirectoryRestartInfo
    FileIoPriorityHintInfo
    FileRemoteProtocolInfo
    MaximumFileInfoByHandleClass
END ENUM

TYPE FILE_BASIC_INFO
    CreationTime   AS QUAD
    LastAccessTime AS QUAD
    LastWriteTime  AS QUAD
    ChangeTime     AS QUAD
    FileAttributes AS DWORD
END TYPE

TYPE FILE_STANDARD_INFO
    AllocationSize AS QUAD
    EndOfFile      AS QUAD
    NumberOfLinks  AS DWORD
    DeletePending  AS BYTE
    Directory      AS BYTE
END TYPE

TYPE FILE_NAME_INFO
    FileNameLength AS DWORD
    FileName       AS WSTRINGZ * 1
END TYPE

TYPE FILE_RENAME_INFO
     ReplaceIfExists AS BYTE
     RootDirectory   AS DWORD
     FileNameLength  AS DWORD
     FileName        AS WSTRINGZ * 1
END TYPE

TYPE FILE_ALLOCATION_INFO
    AllocationSize AS QUAD
END TYPE

TYPE FILE_END_OF_FILE_INFO
    EndOfFile AS QUAD
END TYPE

TYPE FILE_STREAM_INFO
    NextEntryOffset      AS DWORD
    StreamNameLength     AS DWORD
    StreamSize           AS LARGE_INTEGER
    StreamAllocationSize AS LARGE_INTEGER
    StreamName           AS WSTRINGZ * 1
END TYPE

TYPE FILE_COMPRESSION_INFO
    CompressedFileSize   AS QUAD
    CompressionFormat    AS WORD
    CompressionUnitShift AS BYTE
    ChunkShift           AS BYTE
    ClusterShift         AS BYTE
    Reserved(2)          AS BYTE
END TYPE

TYPE FILE_ATTRIBUTE_TAG_INFO
    FileAttributes AS DWORD
    ReparseTag     AS DWORD
END TYPE

TYPE FILE_DISPOSITION_INFO
    DeleteFile AS BYTE
END TYPE

TYPE FILE_ID_BOTH_DIR_INFO
    NextEntryOffset AS DWORD
    FileIndex       AS DWORD
    CreationTime    AS LARGE_INTEGER
    LastAccessTime  AS LARGE_INTEGER
    LastWriteTime   AS LARGE_INTEGER
    ChangeTime      AS LARGE_INTEGER
    EndOfFile       AS LARGE_INTEGER
    AllocationSize  AS LARGE_INTEGER
    FileAttributes  AS DWORD
    FileNameLength  AS DWORD
    EaSize          AS DWORD
    ShortNameLength AS BYTE  ' CCHAR
    ShortName       AS WSTRINGZ * 12
    FileId          AS LARGE_INTEGER
    FileName        AS WSTRINGZ * 1
END TYPE

MACRO PRIORITY_HINT_enum=LONG
ENUM PRIORITY_HINT SINGULAR
    IoPriorityHintVeryLow
    IoPriorityHintLow
    IoPriorityHintNormal
    MaximumIoPriorityHintType
END ENUM

TYPE FILE_IO_PRIORITY_HINT_INFO
    PriorityHint AS PRIORITY_HINT_enum
END TYPE

' Structure and constants must match those in ntioapi_x.w

%REMOTE_PROTOCOL_INFO_FLAG_LOOPBACK     = &H00000001
%REMOTE_PROTOCOL_INFO_FLAG_OFFLINE      = &H00000002

TYPE FILE_REMOTE_PROTOCOL_INFO
    ' Structure Version
    StructureVersion     AS WORD  ' 1
    StructureSize        AS WORD  ' sizeof(FILE_REMOTE_PROTOCOL_INFO)

    Protocol             AS DWORD ' Protocol (WNNC_NET_*) defined in wnnc.h or ntifs.h.

    ' Protocol Version & Type
    ProtocolMajorVersion AS WORD
    ProtocolMinorVersion AS WORD
    ProtocolRevision     AS WORD

    Reserved             AS WORD

    ' Protocol-Generic Information
    Flags                AS WORD

    GenericReserved(7)   AS DWORD

    ' Protocol specific information
    ProtocolSpecificReserved(15) AS DWORD
END TYPE

DECLARE FUNCTION SetFileInformationByHandle LIB "Kernel32.dll" _
    ALIAS "SetFileInformationByHandle" (BYVAL hFile AS DWORD, _
    BYVAL FileInformationClass AS LONG, BYVAL lpFileInformation AS DWORD, _
    BYVAL dwBufferSize AS DWORD) AS LONG

DECLARE FUNCTION GetFileInformationByHandleEx LIB "Kernel32.dll" _
    ALIAS "GetFileInformationByHandleEx" (BYVAL hFile AS DWORD, _
    BYVAL FileInformationClass AS LONG, BYVAL lpFileInformation AS DWORD, _
    BYVAL dwBufferSize AS DWORD) AS LONG

MACRO FILE_ID_TYPE_enum=LONG
ENUM FILE_ID_TYPE SINGULAR
    FileIdType
    ObjectIdType
    MaximumFileIdType
END ENUM

UNION FILE_ID_DESCRIPTORunion
    FileId   AS QUAD
    ObjectId AS GUID
END UNION

TYPE FILE_ID_DESCRIPTOR
    dwSize         AS DWORD             ' Size of the struct
    fidType        AS FILE_ID_TYPE_enum ' the type of identifier passed in
    FILE_ID_DESCRIPTORunion
END TYPE

DECLARE FUNCTION OpenFileById LIB "Kernel32.dll" ALIAS "OpenFileById" _
    (BYVAL hVolumeHint AS DWORD, lpFileId AS LONG, _
    BYVAL dwDesiredAccess AS DWORD, BYVAL dwShareMode AS DWORD, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL dwFlagsAndAttributes AS DWORD) AS DWORD

#ENDIF ' #if (%WIN32_WINNT >= &H0600)

#IF (%WIN32_WINNT >= &H0600)

'
'  Flags to be passed into CREATE_SYMBOLIC_LINK
'

%SYMBOLIC_LINK_FLAG_DIRECTORY            = 1

%VALID_SYMBOLIC_LINK_FLAGS  = %SYMBOLIC_LINK_FLAG_DIRECTORY ' & whatever other flags we think of!

DECLARE FUNCTION CreateSymbolicLinkA LIB "Kernel32.dll" _
    ALIAS "CreateSymbolicLinkA" (lpSymlinkFileName AS ASCIIZ, _
    lpTargetFileName AS ASCIIZ, BYVAL dwFlags AS DWORD) AS BYTE

DECLARE FUNCTION CreateSymbolicLinkW LIB "Kernel32.dll" _
    ALIAS "CreateSymbolicLinkW" (lpSymlinkFileName AS WSTRINGZ, _
    lpTargetFileName AS WSTRINGZ, BYVAL dwFlags AS DWORD) AS BYTE

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateSymbolicLink LIB "Kernel32.dll" _
    ALIAS "CreateSymbolicLinkW" (lpSymlinkFileName AS WSTRINGZ, _
    lpTargetFileName AS WSTRINGZ, BYVAL dwFlags AS DWORD) AS BYTE
#ELSE
DECLARE FUNCTION CreateSymbolicLink LIB "Kernel32.dll" _
    ALIAS "CreateSymbolicLinkA" (lpSymlinkFileName AS ASCIIZ, _
    lpTargetFileName AS ASCIIZ, BYVAL dwFlags AS DWORD) AS BYTE
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CreateSymbolicLinkTransactedA LIB "Kernel32.dll" _
    ALIAS "CreateSymbolicLinkTransactedA" (lpSymlinkFileName AS ASCIIZ, _
    lpTargetFileName AS ASCIIZ, BYVAL dwFlags AS DWORD, _
    BYVAL hTransaction AS DWORD) AS BYTE

DECLARE FUNCTION CreateSymbolicLinkTransactedW LIB "Kernel32.dll" _
    ALIAS "CreateSymbolicLinkTransactedW" (lpSymlinkFileName AS WSTRINGZ, _
    lpTargetFileName AS WSTRINGZ, BYVAL dwFlags AS DWORD, _
    BYVAL hTransaction AS DWORD) AS BYTE

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateSymbolicLinkTransacted LIB "Kernel32.dll" _
    ALIAS "CreateSymbolicLinkTransactedW" (lpSymlinkFileName AS WSTRINGZ, _
    lpTargetFileName AS WSTRINGZ, BYVAL dwFlags AS DWORD, _
    BYVAL hTransaction AS DWORD) AS BYTE
#ELSE
DECLARE FUNCTION CreateSymbolicLinkTransacted LIB "Kernel32.dll" _
    ALIAS "CreateSymbolicLinkTransactedA" (lpSymlinkFileName AS ASCIIZ, _
    lpTargetFileName AS ASCIIZ, BYVAL dwFlags AS DWORD, _
    BYVAL hTransaction AS DWORD) AS BYTE
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetFinalPathNameByHandleA LIB "Kernel32.dll" _
    ALIAS "GetFinalPathNameByHandleA" (BYVAL hFile AS DWORD, _
    lpszFilePath AS ASCIIZ, BYVAL cchFilePath AS DWORD, _
    BYVAL dwFlags AS DWORD) AS DWORD

DECLARE FUNCTION GetFinalPathNameByHandleW LIB "Kernel32.dll" _
    ALIAS "GetFinalPathNameByHandleW" (BYVAL hFile AS DWORD, _
    lpszFilePath AS WSTRINGZ, BYVAL cchFilePath AS DWORD, _
    BYVAL dwFlags AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetFinalPathNameByHandle LIB "Kernel32.dll" _
    ALIAS "GetFinalPathNameByHandleW" (BYVAL hFile AS DWORD, _
    lpszFilePath AS WSTRINGZ, BYVAL cchFilePath AS DWORD, _
    BYVAL dwFlags AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetFinalPathNameByHandle LIB "Kernel32.dll" _
    ALIAS "GetFinalPathNameByHandleA" (BYVAL hFile AS DWORD, _
    lpszFilePath AS ASCIIZ, BYVAL cchFilePath AS DWORD, _
    BYVAL dwFlags AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

#ENDIF ' (%WIN32_WINNT >= &H0600)


#IF (%WIN32_WINNT >= &H0600)

DECLARE FUNCTION QueryActCtxSettingsW LIB "Kernel32.dll" _
    ALIAS "QueryActCtxSettingsW" (BYVAL dwFlags AS DWORD, _
    BYVAL hActCtx AS DWORD, lpszSettingsNameSpace AS WSTRINGZ, _
    lpszSettingName AS WSTRINGZ, pvBuffer AS WSTRINGZ, _
    BYVAL dwBuffer AS DWORD, pdwWrittenOrRequired AS DWORD) AS LONG

#ENDIF ' #if (%WIN32_WINNT >= &H0600)

#IF (%WIN32_WINNT >= &H0600)

DECLARE FUNCTION ReplacePartitionUnit LIB "Kernel32.dll" _
    ALIAS "ReplacePartitionUnit" (lpszTargetPartition AS WSTRINGZ, _
    lpszSparePartition AS WSTRINGZ, BYVAL dFlags AS DWORD) AS LONG

#ENDIF ' #if (%WIN32_WINNT >= &H0600)

#IF (%WIN32_WINNT >= &H0600)

DECLARE FUNCTION AddSecureMemoryCacheCallback LIB "Kernel32.dll" _
    ALIAS "AddSecureMemoryCacheCallback" (BYVAL pfnCallBack AS DWORD) AS LONG

DECLARE FUNCTION RemoveSecureMemoryCacheCallback LIB "Kernel32.dll" _
    ALIAS "RemoveSecureMemoryCacheCallback" (BYVAL pfnCallBack AS DWORD) _
    AS LONG

#ENDIF ' #if (%WIN32_WINNT >= &H0600)

#IF (%WIN32_WINNT >= &H0601)

' [documented as "not supported". do not appear to be exported.]
'DECLARE FUNCTION CopyExtendedContext LIB "Kernel32.dll" _
'    ALIAS "CopyExtendedContext" (Destination AS CONTEXT_EX, _
'    BYVAL ContextFlags AS DWORD, SOURCE AS CONTEXT_EX) AS LONG
'
'DECLARE FUNCTION InitializeExtendedContext LIB "Kernel32.dll" _
'    ALIAS "InitializeExtendedContext" (Context AS ANY, _
'    BYVAL ContextFlags AS DWORD, ContextEx AS ANY) AS LONG

'DECLARE FUNCTION GetEnabledExtendedFeatures LIB "Kernel32.dll" _
'    ALIAS "GetEnabledExtendedFeatures" (BYVAL FeatureMask AS QUAD) AS QUAD
'
'DECLARE FUNCTION GetExtendedContextLength LIB "Kernel32.dll" _
'    ALIAS "GetExtendedContextLength" (BYVAL ContextFlags AS DWORD, _
'    ContextLength AS DWORD) AS LONG
'
'DECLARE FUNCTION GetExtendedFeaturesMask LIB "Kernel32.dll" _
'    ALIAS "GetExtendedFeaturesMask" (ContextEx AS CONTEXT_EX) AS QUAD
'
'DECLARE FUNCTION LocateExtendedFeature LIB "Kernel32.dll" _
'    ALIAS "LocateExtendedFeature" (ContextEx AS CONTEXT_EX, _
'    BYVAL FeatureId AS DWORD, Length AS DWORD) AS DWORD
'
'DECLARE FUNCTION LocateLegacyContext LIB "Kernel32.dll" _
'    ALIAS "LocateLegacyContext" (ContextEx AS CONTEXT_EX, _
'    Length AS DWORD) AS DWORD
'
'DECLARE SUB SetExtendedFeaturesMask LIB "Kernel32.dll" _
'    ALIAS "SetExtendedFeaturesMask" (ContextEx AS CONTEXT_EX, _
'    BYVAL FeatureMask AS QUAD)

DECLARE FUNCTION EnableThreadProfiling LIB "Kernel32.dll" _
    ALIAS "EnableThreadProfiling" (BYVAL ThreadHandle AS DWORD, _
    BYVAL Flags AS DWORD, BYVAL HardwareCounters AS QUAD, _
    PerformanceDataHandle AS DWORD) AS DWORD

DECLARE FUNCTION DisableThreadProfiling LIB "Kernel32.dll" _
    ALIAS "DisableThreadProfiling" (BYVAL PerformanceDataHandle AS DWORD) _
    AS DWORD

DECLARE FUNCTION QueryThreadProfiling LIB "Kernel32.dll" _
    ALIAS "QueryThreadProfiling" (BYVAL ThreadHandle AS DWORD, _
    Enabled AS BYTE) AS DWORD

DECLARE FUNCTION ReadThreadProfilingData LIB "Kernel32.dll" _
    ALIAS "ReadThreadProfilingData" (BYVAL PerformanceDataHandle AS DWORD, _
    BYVAL Flags AS DWORD, PerformanceData AS PERFORMANCE_DATA) AS DWORD

#ENDIF ' #IF (%WIN32_WINNT >= &H0601)


'#IF %DEF(%ISOLATION_AWARE_ENABLED) AND (%ISOLATION_AWARE_ENABLED)
'#INCLUDE "winbase.inl.inc"
'#ENDIF ' %ISOLATION_AWARE_ENABLED
