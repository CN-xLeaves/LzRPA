'------------------------------------------------------------------------------
'
'  SensApi.inc -- Public header file for the SENS Connectivity APIs.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from SensApi.h build version 0001 of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%SENSAPI_H = 1


%NETWORK_ALIVE_LAN      = &H00000001
%NETWORK_ALIVE_WAN      = &H00000002
%NETWORK_ALIVE_AOL      = &H00000004
%NETWORK_ALIVE_INTERNET = &H00000008


TYPE QOCINFO
    dwSize     AS DWORD
    dwFlags    AS DWORD
    dwInSpeed  AS DWORD
    dwOutSpeed AS DWORD
END TYPE



DECLARE FUNCTION IsDestinationReachableA LIB "SensApi.dll" _
    ALIAS "IsDestinationReachableA" ( _
    lpszDestination AS ASCIIZ, _
    lpQOCInfo       AS QOCINFO _
    ) AS LONG  ' BOOL

DECLARE FUNCTION IsDestinationReachableW LIB "SensApi.dll" _
    ALIAS "IsDestinationReachableW" ( _
    lpszDestination AS WSTRINGZ, _
    lpQOCInfo       AS QOCINFO _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
DECLARE FUNCTION IsDestinationReachable LIB "SensApi.dll" _
    ALIAS "IsDestinationReachableW" ( _
    lpszDestination AS WSTRINGZ, _
    lpQOCInfo       AS QOCINFO _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION IsDestinationReachable LIB "SensApi.dll" _
    ALIAS "IsDestinationReachableA" ( _
    lpszDestination AS ASCIIZ, _
    lpQOCInfo       AS QOCINFO _
    ) AS LONG  ' BOOL
#ENDIF ' %UNICODE


DECLARE FUNCTION IsNetworkAlive LIB "SensApi.dll" ALIAS "IsNetworkAlive" ( _
    lpdwFlags AS DWORD _
    ) AS LONG  ' BOOL
