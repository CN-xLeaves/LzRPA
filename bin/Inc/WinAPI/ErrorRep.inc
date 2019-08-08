'------------------------------------------------------------------------------
'
'  ErrorRep.inc -- functions used to report errors to Microsoft
'
'  Copyright (c) 2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 21 Feb 2011
'
'------------------------------------------------------------------------------
'  from ErrorRep.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

#INCLUDE "WinNT.inc"

%ERRORREP_H = 1

MACRO EFaultRepRetVal_enum=LONG
ENUM EFaultRepRetVal SINGULAR
    frrvOk = 0
    frrvOkManifest
    frrvOkQueued
    frrvErr
    frrvErrNoDW
    frrvErrTimeout
    frrvLaunchDebugger
    frrvOkHeadless
    frrvErrAnotherInstance
END ENUM

DECLARE FUNCTION ReportFault LIB "FaultRep.dll" ALIAS "ReportFault" ( _
    BYVAL pep  AS EXCEPTION_POINTERS PTR, _
    BYVAL dwOpt AS DWORD _
    ) AS EFaultRepRetVal_enum

DECLARE FUNCTION AddERExcludedApplicationA LIB "FaultRep.dll" _
    ALIAS "AddERExcludedApplicationA" (szApplication AS ASCIIZ) _
    AS LONG  ' BOOL

DECLARE FUNCTION AddERExcludedApplicationW LIB "FaultRep.dll" _
    ALIAS "AddERExcludedApplicationW" (szApplication AS WSTRINGZ) _
    AS LONG  ' BOOL

'typedef EFaultRepRetVal (APIENTRY *pfn_REPORTFAULT)(__in LPEXCEPTION_POINTERS, __in DWORD);
'typedef EFaultRepRetVal (APIENTRY *pfn_ADDEREXCLUDEDAPPLICATIONA)(__in LPCSTR);
'typedef EFaultRepRetVal (APIENTRY *pfn_ADDEREXCLUDEDAPPLICATIONW)(__in LPCWSTR);

#IF %DEF(%UNICODE)
DECLARE FUNCTION AddERExcludedApplication LIB "FaultRep.dll" _
    ALIAS "AddERExcludedApplicationW" (szApplication AS WSTRINGZ) _
    AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION AddERExcludedApplication LIB "FaultRep.dll" _
    ALIAS "AddERExcludedApplicationA" (szApplication AS ASCIIZ) _
    AS LONG  ' BOOL
#ENDIF

'
'+++++++++++++++++++++ Hang reporting api ++++++++++++++++++++++++++++++++
'
DECLARE FUNCTION WerReportHang LIB "FaultRep.dll" ALIAS "WerReportHang" _
    (BYVAL hwndHungApp AS DWORD, _  ' HWND
    pwzHungApplicationName AS WSTRINGZ _
    ) AS LONG  ' HRESULT
