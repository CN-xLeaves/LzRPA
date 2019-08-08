'------------------------------------------------------------------------------
'
'  TlHelp32.inc -- WIN32 tool help functions, types, and definitions
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from TLHELP32.H version 1.0 of 14 Jul 2009
'------------------------------------------------------------------------------



#INCLUDE THIS ONCE

%TLHELP32_INC = 1

#INCLUDE "WinDef.inc"

%MAX_MODULE_NAME32 = 255

'----- Snapshot function ---------------------------------------------

DECLARE FUNCTION CreateToolhelp32Snapshot LIB "Kernel32.dll" _
    ALIAS "CreateToolhelp32Snapshot" (BYVAL dwFlags AS DWORD, _
    BYVAL th32ProcessID AS DWORD) AS DWORD


' The th32ProcessID argument is only used if %TH32CS_SNAPHEAPLIST or
' %TH32CS_SNAPMODULE is specified. th32ProcessID = 0 means the current
' process.
'
' NOTE that all of the snapshots are global except for the heap and module
'      lists which are process specific. To enumerate the heap or module
'      state for all WIN32 processes call with TH32CS_SNAPALL and the
'      current process. Then for each process in the TH32CS_SNAPPROCESS
'      list that isn't the current process, do a call with just
'      TH32CS_SNAPHEAPLIST and/or TH32CS_SNAPMODULE.
'
' dwFlags
'
%TH32CS_SNAPHEAPLIST = &H00000001
%TH32CS_SNAPPROCESS  = &H00000002
%TH32CS_SNAPTHREAD   = &H00000004
%TH32CS_SNAPMODULE   = &H00000008
%TH32CS_SNAPMODULE32 = &H00000010
%TH32CS_SNAPALL      = %TH32CS_SNAPHEAPLIST _
                    OR %TH32CS_SNAPPROCESS _
                    OR %TH32CS_SNAPTHREAD _
                    OR %TH32CS_SNAPMODULE
%TH32CS_INHERIT      = &H80000000???
'
' Use CloseHandle to destroy the snapshot
'

'----- heap walking --------------------------------------------------

TYPE HEAPLIST32
    dwSize        AS DWORD
    th32ProcessID AS DWORD   ' owning process
    th32HeapID    AS DWORD   ' heap (in owning process's context!)
    dwFlags       AS DWORD
END TYPE
'
' dwFlags
'
%HF32_DEFAULT = 1  ' process's default heap
%HF32_SHARED  = 2  ' is shared heap

DECLARE FUNCTION Heap32ListFirst LIB "Kernel32.dll" ALIAS "Heap32ListFirst" _
    (BYVAL hSnapshot AS DWORD, lphl AS HEAPLIST32) AS LONG

DECLARE FUNCTION Heap32ListNext LIB "Kernel32.dll" ALIAS "Heap32ListNext" _
    (BYVAL hSnapshot AS DWORD, lphl AS HEAPLIST32) AS LONG

TYPE HEAPENTRY32
    dwSize        AS DWORD
    hHandle       AS DWORD   ' Handle of this heap block
    dwAddress     AS DWORD   ' Linear address of start of block
    dwBlockSize   AS DWORD   ' Size of block in bytes
    dwFlags       AS DWORD
    dwLockCount   AS DWORD
    dwResvd       AS DWORD
    th32ProcessID AS DWORD   ' owning process
    th32HeapID    AS DWORD   ' heap block is in
END TYPE
'
' dwFlags
'
%LF32_FIXED    = &H00000001
%LF32_FREE     = &H00000002
%LF32_MOVEABLE = &H00000004

DECLARE FUNCTION Heap32First LIB "Kernel32.dll" ALIAS "Heap32First" _
    (lphe AS HEAPENTRY32, BYVAL th32ProcessID AS DWORD, _
    BYVAL th32HeapID AS DWORD) AS LONG

DECLARE FUNCTION Heap32Next LIB "Kernel32.dll" ALIAS "Heap32Next" _
    (lphe AS HEAPENTRY32) AS LONG

DECLARE FUNCTION Toolhelp32ReadProcessMemory LIB "Kernel32.dll" _
    ALIAS "Toolhelp32ReadProcessMemory" (BYVAL th32ProcessID AS DWORD, _
    BYVAL lpBaseAddress AS DWORD, BYVAL lpBuffer AS DWORD, _
    BYVAL cbRead AS DWORD, lpNumberOfBytesRead AS DWORD) AS LONG

'---- Process walking ------------------------------------------------

TYPE PROCESSENTRY32W
    dwSize              AS DWORD
    cntUsage            AS DWORD
    th32ProcessID       AS DWORD    ' this process
    th32DefaultHeapID   AS DWORD
    th32ModuleID        AS DWORD    ' associated exe
    cntThreads          AS DWORD
    th32ParentProcessID AS DWORD    ' this process's parent process
    pcPriClassBase      AS LONG     ' Base priority of process's threads
    dwFlags             AS DWORD
    szExeFile           AS WSTRINGZ * %MAX_PATH
END TYPE

DECLARE FUNCTION Process32FirstW LIB "Kernel32.dll" ALIAS "Process32FirstW" _
    (BYVAL hSnapshot AS DWORD, lppe AS PROCESSENTRY32W) AS LONG

DECLARE FUNCTION Process32NextW LIB "Kernel32.dll" ALIAS "Process32NextW" _
    (BYVAL hSnapshot AS DWORD, lppe AS PROCESSENTRY32W) AS LONG


TYPE PROCESSENTRY32A
    dwSize              AS DWORD
    cntUsage            AS DWORD
    th32ProcessID       AS DWORD    ' this process
    th32DefaultHeapID   AS DWORD
    th32ModuleID        AS DWORD    ' associated exe
    cntThreads          AS DWORD
    th32ParentProcessID AS DWORD    ' this process's parent process
    pcPriClassBase      AS LONG     ' Base priority of process's threads
    dwFlags             AS DWORD
    szExeFile           AS ASCIIZ * %MAX_PATH
END TYPE

' [note, no A suffix on the alias names of the ASCIIZ versions]

DECLARE FUNCTION Process32FirstA LIB "Kernel32.dll" ALIAS "Process32First" _
    (BYVAL hSnapshot AS DWORD, lppe AS PROCESSENTRY32A) AS LONG

DECLARE FUNCTION Process32NextA LIB "Kernel32.dll" ALIAS "Process32Next" _
    (BYVAL hSnapshot AS DWORD, lppe AS PROCESSENTRY32A) AS LONG

#IF %DEF(%UNICODE)
TYPE PROCESSENTRY32
    PROCESSENTRY32W
END TYPE
DECLARE FUNCTION Process32First LIB "Kernel32.dll" ALIAS "Process32FirstW" _
    (BYVAL hSnapshot AS DWORD, lppe AS PROCESSENTRY32) AS LONG
DECLARE FUNCTION Process32Next LIB "Kernel32.dll" ALIAS "Process32NextW" _
    (BYVAL hSnapshot AS DWORD, lppe AS PROCESSENTRY32) AS LONG
#ELSE
TYPE PROCESSENTRY32
    PROCESSENTRY32A
END TYPE
DECLARE FUNCTION Process32First LIB "Kernel32.dll" ALIAS "Process32First" _
    (BYVAL hSnapshot AS DWORD, lppe AS PROCESSENTRY32) AS LONG
DECLARE FUNCTION Process32Next LIB "Kernel32.dll" ALIAS "Process32Next" _
    (BYVAL hSnapshot AS DWORD, lppe AS PROCESSENTRY32) AS LONG
#ENDIF

'---- Thread walking -------------------------------------------------

TYPE THREADENTRY32
    dwSize             AS DWORD
    cntUsage           AS DWORD
    th32ThreadID       AS DWORD   ' this thread
    th32OwnerProcessID AS DWORD   ' Process this thread is associated with
    tpBasePri          AS LONG
    tpDeltaPri         AS LONG
    dwFlags            AS DWORD
END TYPE

DECLARE FUNCTION Thread32First LIB "Kernel32.dll" ALIAS "Thread32First" _
    (BYVAL hSnapshot AS DWORD, lpte AS THREADENTRY32) AS LONG

DECLARE FUNCTION Thread32Next LIB "Kernel32.dll" ALIAS "Thread32Next" _
    (BYVAL hSnapshot AS DWORD, lpte AS THREADENTRY32) AS LONG

'---- Module walking ------------------------------------------------

TYPE MODULEENTRY32W
    dwSize        AS DWORD
    th32ModuleID  AS DWORD    ' This module
    th32ProcessID AS DWORD    ' owning process
    GlblcntUsage  AS DWORD    ' Global usage count on the module
    ProccntUsage  AS DWORD    ' Module usage count in th32ProcessID's context
    modBaseAddr   AS BYTE PTR ' Base address of module in th32ProcessID's context
    modBaseSize   AS DWORD    ' Size in bytes of module starting at modBaseAddr
    hModule       AS DWORD    ' The hModule of this module in th32ProcessID's context
    szModule      AS WSTRINGZ * %MAX_MODULE_NAME32 + 1
    szExePath     AS WSTRINGZ * %MAX_PATH
END TYPE

DECLARE FUNCTION Module32FirstW LIB "Kernel32.dll" ALIAS "Module32FirstW" _
    (BYVAL hSnapshot AS DWORD, lpme AS MODULEENTRY32W) AS LONG

DECLARE FUNCTION Module32NextW LIB "Kernel32.dll" ALIAS "Module32NextW" _
    (BYVAL hSnapshot AS DWORD, lpme AS MODULEENTRY32W) AS LONG

TYPE MODULEENTRY32A
    dwSize        AS DWORD
    th32ModuleID  AS DWORD    ' This module
    th32ProcessID AS DWORD    ' owning process
    GlblcntUsage  AS DWORD    ' Global usage count on the module
    ProccntUsage  AS DWORD    ' Module usage count in th32ProcessID's context
    modBaseAddr   AS BYTE PTR ' Base address of module in th32ProcessID's context
    modBaseSize   AS DWORD    ' Size in bytes of module starting at modBaseAddr
    hModule       AS DWORD    ' The hModule of this module in th32ProcessID's context
    szModule      AS ASCIIZ * %MAX_MODULE_NAME32 + 1
    szExePath     AS ASCIIZ * %MAX_PATH
END TYPE

'
' NOTE CAREFULLY that the modBaseAddr and hModule fields are valid ONLY
' in th32ProcessID's process context.
'

' [note, no A suffix on the alias names of the ASCIIZ versions]

DECLARE FUNCTION Module32FirstA LIB "Kernel32.dll" ALIAS "Module32First" _
    (BYVAL hSnapshot AS DWORD, lpme AS MODULEENTRY32A) AS LONG

DECLARE FUNCTION Module32NextA LIB "Kernel32.dll" ALIAS "Module32Next" _
    (BYVAL hSnapshot AS DWORD, lpme AS MODULEENTRY32A) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION Module32First LIB "Kernel32.dll" ALIAS "Module32FirstW" _
    (BYVAL hSnapshot AS DWORD, lpme AS MODULEENTRY32W) AS LONG
DECLARE FUNCTION Module32Next LIB "Kernel32.dll" ALIAS "Module32NextW" _
    (BYVAL hSnapshot AS DWORD, lpme AS MODULEENTRY32W) AS LONG
TYPE MODULEENTRY32
    MODULEENTRY32W
END TYPE
#ELSE
DECLARE FUNCTION Module32First LIB "Kernel32.dll" ALIAS "Module32First" _
    (BYVAL hSnapshot AS DWORD, lpme AS MODULEENTRY32A) AS LONG
DECLARE FUNCTION Module32Next LIB "Kernel32.dll" ALIAS "Module32Next" _
    (BYVAL hSnapshot AS DWORD, lpme AS MODULEENTRY32A) AS LONG
TYPE MODULEENTRY32
    MODULEENTRY32A
END TYPE
#ENDIF
