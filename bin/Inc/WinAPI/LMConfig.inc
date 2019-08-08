'------------------------------------------------------------------------------
'
'  LMConfig.inc -
'    This module defines the API function prototypes and data structures
'    for the following groups of NT API functions:
'        NetConfig
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from LMConfig.h build version 0003 dated 18 Jan 2008
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%LMCONFIG = 1

#INCLUDE "LmCons.inc"

%REVISED_CONFIG_APIS = 1

'
' Function Prototypes - Config
'

#IF %DEF(%REVISED_CONFIG_APIS)
DECLARE FUNCTION NetConfigGet LIB "NetApi32.dll" ALIAS "NetConfigGet" ( _
    SERVER         AS WSTRINGZ, _
    component      AS WSTRINGZ, _
    parameter      AS WSTRINGZ, _
    bufptr         AS ANY _   ' BYTE PTR PTR
    ) AS NET_API_STATUS
#ELSE
DECLARE FUNCTION NetConfigGet LIB "NetApi32.dll" ALIAS "NetConfigGet" ( _
    SERVER         AS WSTRINGZ, _
    component      AS WSTRINGZ, _
    parameter      AS WSTRINGZ, _
    bufptr         AS ANY, _  ' BYTE PTR PTR
    totalavailable AS DWORD _
    ) AS NET_API_STATUS
#ENDIF

#IF %DEF(%REVISED_CONFIG_APIS)
DECLARE FUNCTION NetConfigGetAll LIB "NetApi32.dll" ALIAS "NetConfigGetAll" ( _
    SERVER         AS WSTRINGZ, _
    component      AS WSTRINGZ, _
    bufptr         AS ANY _   ' BYTE PTR PTR
    ) AS NET_API_STATUS
#ELSE
DECLARE FUNCTION NetConfigGetAll LIB "NetApi32.dll" ALIAS "NetConfigGetAll" ( _
    SERVER         AS WSTRINGZ, _
    component      AS WSTRINGZ, _
    bufptr         AS ANY, _  ' BYTE PTR PTR
    totalavailable AS DWORD _
    ) AS NET_API_STATUS
#ENDIF

DECLARE FUNCTION NetConfigSet LIB "NetApi32.dll" ALIAS "NetConfigSet" ( _
    SERVER          AS WSTRINGZ, _
    reserved1       AS WSTRINGZ, _
    component       AS WSTRINGZ, _
    BYVAL level     AS DWORD, _
    BYVAL reserved2 AS DWORD, _
    BYVAL buf       AS BYTE PTR, _
    BYVAL reserved3 AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetRegisterDomainNameChangeNotification LIB "NetApi32.dll" _
    ALIAS "NetRegisterDomainNameChangeNotification" ( _
    NotificationEventHandle AS DWORD _  ' HANDLE
    ) AS NET_API_STATUS

DECLARE FUNCTION NetUnregisterDomainNameChangeNotification LIB "NetApi32.dll" _
    ALIAS "NetUnregisterDomainNameChangeNotification" ( _
    BYVAL NotificationEventHandle AS DWORD _
    ) AS NET_API_STATUS

'
' Data Structures - Config
'

TYPE CONFIG_INFO_0
     cfgi0_key  AS WSTRINGZ PTR
     cfgi0_data AS WSTRINGZ PTR
END TYPE
