'------------------------------------------------------------------------------
'
'  LmMsg.inc  - definitions for the NetMessage API.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from LmMsg.h build version 0001 of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%LMMSG = 1

#INCLUDE "LmCons.inc"

'
' Function Prototypes
'

DECLARE FUNCTION NetMessageNameAdd LIB "NetApi32.dll" _
    ALIAS "NetMessageNameAdd" ( _
    servername AS WSTRINGZ, _
    msgname    AS WSTRINGZ _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetMessageNameEnum LIB "NetApi32.dll" _
    ALIAS "NetMessageNameEnum" ( _
    servername       AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    bufptr           AS ANY, _  ' BYTE PTR PTR
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resume_handle    AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetMessageNameGetInfo LIB "NetApi32.dll" _
    ALIAS "NetMessageNameGetInfo" ( _
    servername  AS WSTRINGZ, _
    msgname     AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    bufptr      AS ANY _  ' BYTE PTR PTR
    ) AS NET_API_STATUS

DECLARE FUNCTION NetMessageNameDel LIB "NetApi32.dll" _
    ALIAS "NetMessageNameDel" ( _
    servername AS WSTRINGZ, _
    msgname    AS WSTRINGZ _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetMessageBufferSend LIB "NetApi32.dll" _
    ALIAS "NetMessageBufferSend" ( _
    servername   AS WSTRINGZ, _
    msgname      AS WSTRINGZ, _
    fromname     AS WSTRINGZ, _
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS DWORD _
    ) AS NET_API_STATUS

'
'  Data Structures
'

TYPE MSG_INFO_0
    msgi0_name AS WSTRINGZ PTR
END TYPE

TYPE MSG_INFO_1
    msgi1_name         AS WSTRINGZ PTR
    msgi1_forward_flag AS DWORD
    msgi1_forward      AS WSTRINGZ PTR
END TYPE

'
' Special Values and Constants
'

'
' Values for msgi1_forward_flag.
'

%MSGNAME_NOT_FORWARDED  = 0       ' Name not forwarded
%MSGNAME_FORWARDED_TO   = &H04    ' Name forward to remote station
%MSGNAME_FORWARDED_FROM = &H10    ' Name forwarded from remote station
