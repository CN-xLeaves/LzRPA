'------------------------------------------------------------------------------
'
'  UrlMon.inc -- Common includes for new-style Win32 Access Control APIS
'
'  Copyright (c) 2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 21 Mar 2011
'
'------------------------------------------------------------------------------
'  from UrlMon.h of 14 Jul 2009
'------------------------------------------------------------------------------

' [stub file for backwards compatibility]

#INCLUDE THIS ONCE

DECLARE FUNCTION URLDownloadToFileA LIB "UrlMon.dll" _
    ALIAS "URLDownloadToFileA" ( _
    pCaller          AS ANY, _
    szURL            AS ASCIIZ, _
    szFileName       AS ASCIIZ, _
    BYVAL dwReserved AS DWORD, _
    BYVAL lpfnCB     AS DWORD) AS LONG

DECLARE FUNCTION URLDownloadToFileW LIB "UrlMon.dll" _
    ALIAS "URLDownloadToFileW" ( _
    pCaller          AS ANY, _
    szURL            AS WSTRINGZ, _
    szFileName       AS WSTRINGZ, _
    BYVAL dwReserved AS DWORD, _
    BYVAL lpfnCB     AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION URLDownloadToFile LIB "UrlMon.dll" _
    ALIAS "URLDownloadToFileW" ( _
    pCaller          AS ANY, _
    szURL            AS WSTRINGZ, _
    szFileName       AS WSTRINGZ, _
    BYVAL dwReserved AS DWORD, _
    BYVAL lpfnCB     AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION URLDownloadToFile LIB "UrlMon.dll" _
    ALIAS "URLDownloadToFileA" ( _
    pCaller          AS ANY, _
    szURL            AS ASCIIZ, _
    szFileName       AS ASCIIZ, _
    BYVAL dwReserved AS DWORD, _
    BYVAL lpfnCB     AS DWORD) AS LONG
#ENDIF
