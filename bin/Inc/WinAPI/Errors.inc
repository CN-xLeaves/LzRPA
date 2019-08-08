'------------------------------------------------------------------------------
'
'  Errors.inc -- ActiveMovie error defines.
'
'  Copyright (c) 2011 PowerBASIC, Inc.
'  Portions Copyright (c) 1992-2001 Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 24 Feb 2011
'
'------------------------------------------------------------------------------
'  from Errors.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%ERRORS = 1

' codes 0-01ff are reserved for OLE
%VFW_FIRST_CODE     = &H200
%MAX_ERROR_TEXT_LEN = 160

#INCLUDE ONCE "VFWMSGS.inc"                 ' includes all message definitions

'typedef BOOL (WINAPI* AMGETERRORTEXTPROCA)(HRESULT, char *, DWORD);
'typedef BOOL (WINAPI* AMGETERRORTEXTPROCW)(HRESULT, WCHAR *, DWORD);

DECLARE FUNCTION AMGetErrorTextA LIB "Quartz.dll" ALIAS "AMGetErrorTextA" ( _
    BYVAL hr     AS LONG, _  ' HRESULT
    pBuffer      AS ASCIIZ, _
    BYVAL MaxLen AS DWORD _
    ) AS DWORD

DECLARE FUNCTION AMGetErrorTextW LIB "Quartz.dll" ALIAS "AMGetErrorTextW" ( _
    BYVAL hr     AS LONG, _  ' HRESULT
    pBuffer      AS ASCIIZ, _
    BYVAL MaxLen AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION AMGetErrorText LIB "Quartz.dll" ALIAS "AMGetErrorTextW" ( _
    BYVAL hr     AS LONG, _  ' HRESULT
    pBuffer      AS ASCIIZ, _
    BYVAL MaxLen AS DWORD _
    ) AS DWORD
'typedef AMGETERRORTEXTPROCW AMGETERRORTEXTPROC;
#ELSE
DECLARE FUNCTION AMGetErrorText LIB "Quartz.dll" ALIAS "AMGetErrorTextA" ( _
    BYVAL hr     AS LONG, _  ' HRESULT
    pBuffer      AS ASCIIZ, _
    BYVAL MaxLen AS DWORD _
    ) AS DWORD
'typedef AMGETERRORTEXTPROCA AMGETERRORTEXTPROC;
#ENDIF
