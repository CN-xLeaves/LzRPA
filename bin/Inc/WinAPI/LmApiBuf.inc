'------------------------------------------------------------------------------
'
'  LmApiBuf.inc -- This file contains information about NetApiBuffer APIs.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from LmApiBuf.h build version 0001 of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%LMAPIBUF = 1

#INCLUDE "LmCons.inc"

'
' Function Prototypes
'

DECLARE FUNCTION NetApiBufferAllocate LIB "NetApi32.dll" _
    ALIAS "NetApiBufferAllocate" ( _
    BYVAL ByteCount AS DWORD, _
    pBuffer         AS ANY _  ' LPVOID *
    ) AS NET_API_STATUS

DECLARE FUNCTION NetApiBufferFree LIB "NetApi32.dll" _
    ALIAS "NetApiBufferFree" ( _
    pBuffer AS ANY _  ' LPVOID
    ) AS NET_API_STATUS

DECLARE FUNCTION NetApiBufferReallocate LIB "NetApi32.dll" _
    ALIAS "NetApiBufferReallocate" ( _
    pOldBuffer         AS ANY, _  ' LPVOID
    BYVAL NewByteCount AS DWORD, _
    pNewBuffer         AS ANY _   ' LPVOID *
    ) AS NET_API_STATUS

DECLARE FUNCTION NetApiBufferSize LIB "NetApi32.dll" _
    ALIAS "NetApiBufferSize" ( _
    pBuffer   AS ANY, _  ' LPVOID
    ByteCount AS DWORD _
    ) AS NET_API_STATUS


'
' The following private function will go away eventually.
' Call NetApiBufferAllocate instead.
'
DECLARE FUNCTION NetapipBufferAllocate LIB "NetApi32.dll" _
    ALIAS "NetapipBufferAllocate" ( _
    BYVAL ByteCount AS DWORD, _
    Buffer          AS ANY _   ' LPVOID *
    ) AS NET_API_STATUS
