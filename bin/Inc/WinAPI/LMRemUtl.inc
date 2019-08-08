'------------------------------------------------------------------------------
'
'  LmRemUtl.inc -- definitions for the NetRemote API.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from LmRemUtl.h build version 0001 of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%LMREMUTL = 1

#INCLUDE "LmCons.inc"

'
' Type Definitions
'

#IF NOT %DEF(%DESC_CHAR_UNICODE)

'typedef CHAR DESC_CHAR;
MACRO LPDESC=ASCIIZ

#ELSE ' %DESC_CHAR_UNICODE is defined

'typedef WCHAR DESC_CHAR;
MACRO LPDESC=WSTRINGZ

#ENDIF ' %DESC_CHAR_UNICODE is defined



'
' Function Prototypes
'

DECLARE FUNCTION NetRemoteTOD LIB "NetApi32.dll" ALIAS "NetRemoteTOD" ( _
    UncServerName AS WSTRINGZ, _
    pBuffer       AS ANY _  ' BYTE PTR PTR
    ) AS NET_API_STATUS

DECLARE FUNCTION NetRemoteComputerSupports LIB "NetApi32.dll" _
    ALIAS "NetRemoteComputerSupports" ( _
    UncServerName       AS WSTRINGZ, _  ' Must start with "\\".
    BYVAL OptionsWanted AS DWORD, _     ' Set SUPPORTS_ bits wanted.
    OptionsSupported    AS DWORD _      ' Supported features, masked.
    ) AS NET_API_STATUS

' [not documented]
'declare function RxRemoteApi CDECL lib "NetApi32.dll" alias "RxRemoteApi" ( _
'    DWORD ApiNumber,
'    LPCWSTR UncServerName,                    ' Required, with \\name.
'    LPDESC ParmDescString,
'    LPDESC DataDesc16,
'    LPDESC DataDesc32,
'    LPDESC DataDescSmb,
'    LPDESC AuxDesc16,
'    LPDESC AuxDesc32,
'    LPDESC AuxDescSmb,
'    DWORD  Flags,
'    ...                                         ' rest of API's arguments
'    ) AS NET_API_STATUS



'
'  Data Structures
'

TYPE TIME_OF_DAY_INFO
    tod_elapsedt  AS DWORD
    tod_msecs     AS DWORD
    tod_hours     AS DWORD
    tod_mins      AS DWORD
    tod_secs      AS DWORD
    tod_hunds     AS DWORD
    tod_timezone  AS LONG
    tod_tinterval AS DWORD
    tod_day       AS DWORD
    tod_month     AS DWORD
    tod_year      AS DWORD
    tod_weekday   AS DWORD
END TYPE

'
' Special Values and Constants
'

'
' Mask bits for use with NetRemoteComputerSupports:
'

%SUPPORTS_REMOTE_ADMIN_PROTOCOL = &H00000002
%SUPPORTS_RPC                   = &H00000004
%SUPPORTS_SAM_PROTOCOL          = &H00000008
%SUPPORTS_UNICODE               = &H00000010
%SUPPORTS_LOCAL                 = &H00000020
%SUPPORTS_ANY                   = &HFFFFFFFF???

'
' Flag bits for RxRemoteApi:
'

%NO_PERMISSION_REQUIRED = &H00000001  ' set if use NULL session
%ALLOCATE_RESPONSE      = &H00000002  ' set if RxRemoteApi allocates response buffer
%USE_SPECIFIC_TRANSPORT = &H80000000???
