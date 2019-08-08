'------------------------------------------------------------------------------
'
'  OleAuto.inc  - Defines OLE Automation support function prototypes, constants
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 04 Apr 2011
'
'------------------------------------------------------------------------------
'  from OleAuto.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%OLEAUTO_H = 1

#INCLUDE "SdkDdkVer.inc"


' Set packing to 8 for ISV, and Win95 support

'  Definition of the OLE Automation APIs, and macros.

'EXTERN_C IID IID_StdOle;

%STDOLE_MAJORVERNUM  = &H1
%STDOLE_MINORVERNUM  = &H0
%STDOLE_LCID         = &H0000

' Version # of stdole2.tlb
%STDOLE2_MAJORVERNUM = &H2
%STDOLE2_MINORVERNUM = &H0
%STDOLE2_LCID        = &H0000

' if not already picked up from olenls.h
#IF NOT %DEF(%LCID_DEFINED)
'MACRO LCID=DWORD
%LCID_DEFINED = 1
#ENDIF

#IF NOT %DEF(%BEGIN_INTERFACE)
%BEGIN_INTERFACE = 1
%END_INTERFACE = 1
#ENDIF

' pull in the MIDL generated header
#INCLUDE "oaidl.inc"


'*---------------------------------------------------------------------*
'*                            BSTR API                                 *
'*---------------------------------------------------------------------*

DECLARE FUNCTION SysAllocString LIB "OleAut32.dll" ALIAS "SysAllocString" ( _
    psz AS ANY _
    ) AS DWORD

DECLARE FUNCTION SysReAllocString LIB "OleAut32.dll" _
    ALIAS "SysReAllocString" ( _
    pbstr AS ANY, _  ' BSTR*
    psz   AS ANY _
    ) AS LONG

DECLARE FUNCTION SysAllocStringLen LIB "OleAut32.dll" _
    ALIAS "SysAllocStringLen" ( _
    strIn    AS ANY, _
    BYVAL ui AS DWORD _
    ) AS DWORD

DECLARE FUNCTION SysReAllocStringLen LIB "OleAut32.dll" _
    ALIAS "SysReAllocStringLen" ( _
    pbstr     AS ANY, _  ' BSTR*
    psz       AS ANY, _
    BYVAL len AS DWORD _
    ) AS LONG

DECLARE SUB SysFreeString LIB "OleAut32.dll" ALIAS "SysFreeString" ( _
    bstrString AS ANY _
    )

DECLARE FUNCTION SysStringLen LIB "OleAut32.dll" ALIAS "SysStringLen" ( _
    bstrString AS ANY _
    ) AS DWORD

#IF %DEF(%WIN32) OR %DEF(%WIN64)

DECLARE FUNCTION SysStringByteLen LIB "OleAut32.dll" _
    ALIAS "SysStringByteLen" ( _
    bstr AS ANY _
    ) AS DWORD

DECLARE FUNCTION SysAllocStringByteLen LIB "OleAut32.dll" _
    ALIAS "SysAllocStringByteLen" ( _
    psz       AS ASCIIZ, _
    BYVAL len AS DWORD _
    ) AS DWORD

#ENDIF

'*---------------------------------------------------------------------*
'*                            Time API                                 *
'*---------------------------------------------------------------------*

DECLARE FUNCTION DosDateTimeToVariantTime LIB "OleAut32.dll" _
    ALIAS "DosDateTimeToVariantTime" ( _
    BYVAL wDosDate AS WORD, _
    BYVAL wDosTime AS WORD, _
    pvtime         AS DOUBLE  _
    ) AS LONG

DECLARE FUNCTION VariantTimeToDosDateTime LIB "OleAut32.dll" _
    ALIAS "VariantTimeToDosDateTime" ( _
    BYVAL vtime AS DOUBLE, _
    pwDosDate   AS WORD, _
    pwDosTime   AS WORD _
    ) AS LONG

#IF %DEF(%WIN32) OR %DEF(%WIN64)

DECLARE FUNCTION SystemTimeToVariantTime LIB "OleAut32.dll" _
    ALIAS "SystemTimeToVariantTime" ( _
    lpSystemTime AS SYSTEMTIME, _
    pvtime       AS DOUBLE _
    ) AS LONG

DECLARE FUNCTION VariantTimeToSystemTime LIB "OleAut32.dll" _
    ALIAS "VariantTimeToSystemTime" ( _
    BYVAL vtime  AS DOUBLE, _
    lpSystemTime AS SYSTEMTIME _
    ) AS LONG

#ENDIF


'*---------------------------------------------------------------------*
'*                          SafeArray API                              *
'*---------------------------------------------------------------------*

DECLARE FUNCTION SafeArrayAllocDescriptor LIB "OleAut32.dll" _
    ALIAS "SafeArrayAllocDescriptor" ( _
    BYVAL cDims AS DWORD, _
    ppsaOut     AS ANY _  ' SAFEARRAY **
    ) AS LONG

DECLARE FUNCTION SafeArrayAllocDescriptorEx LIB "OleAut32.dll" _
    ALIAS "SafeArrayAllocDescriptorEx" ( _
    BYVAL vt AS VARTYPE, _
    BYVAL cDims AS DWORD, _
    ppsaOut     AS ANY _  ' SAFEARRAY **
    ) AS LONG

DECLARE FUNCTION SafeArrayAllocData LIB "OleAut32.dll" _
    ALIAS "SafeArrayAllocData" ( _
    ppsaOut AS SAFEARRAY _
    ) AS LONG

DECLARE FUNCTION SafeArrayCreate LIB "OleAut32.dll" ALIAS "SafeArrayCreate" ( _
    BYVAL vt    AS VARTYPE, _
    BYVAL cDims AS DWORD, _
    rgsabound   AS SAFEARRAYBOUND _
    ) AS DWORD  ' SAFEARRAY *

DECLARE FUNCTION SafeArrayCreateEx LIB "OleAut32.dll" _
    ALIAS "SafeArrayCreateEx" ( _
    BYVAL vt    AS VARTYPE, _
    BYVAL cDims AS DWORD, _
    rgsabound   AS SAFEARRAYBOUND, _
    pvExtra     AS ANY _  ' PVOID
    ) AS DWORD  ' SAFEARRAY *

DECLARE FUNCTION SafeArrayCopyData LIB "OleAut32.dll" _
    ALIAS "SafeArrayCopyData" ( _
    psaSource AS SAFEARRAY, _
    psaTarget AS SAFEARRAY _
    ) AS LONG

DECLARE FUNCTION SafeArrayDestroyDescriptor LIB "OleAut32.dll" _
    ALIAS "SafeArrayDestroyDescriptor" ( _
    psa AS SAFEARRAY _
    ) AS LONG

DECLARE FUNCTION SafeArrayDestroyData LIB "OleAut32.dll" _
    ALIAS "SafeArrayDestroyData" ( _
    psa AS SAFEARRAY _
    ) AS LONG

DECLARE FUNCTION SafeArrayDestroy LIB "OleAut32.dll" _
    ALIAS "SafeArrayDestroy" ( _
    psa AS SAFEARRAY _
    ) AS LONG

DECLARE FUNCTION SafeArrayRedim LIB "OleAut32.dll" ALIAS "SafeArrayRedim" ( _
    psa         AS SAFEARRAY, _
    psaboundNew AS SAFEARRAYBOUND _
    ) AS LONG

DECLARE FUNCTION SafeArrayGetDim LIB "OleAut32.dll" ALIAS "SafeArrayGetDim" ( _
    psa AS SAFEARRAY _
    ) AS DWORD

DECLARE FUNCTION SafeArrayGetElemsize LIB "OleAut32.dll" _
    ALIAS "SafeArrayGetElemsize" ( _
    psa AS SAFEARRAY _
    ) AS DWORD

DECLARE FUNCTION SafeArrayGetUBound LIB "OleAut32.dll" _
    ALIAS "SafeArrayGetUBound" ( _
    psa        AS SAFEARRAY, _
    BYVAL nDim AS DWORD, _
    plUbound   AS LONG _
    ) AS LONG

DECLARE FUNCTION SafeArrayGetLBound LIB "OleAut32.dll" _
    ALIAS "SafeArrayGetLBound" ( _
    psa        AS SAFEARRAY, _
    BYVAL nDim AS DWORD, _
    plLbound   AS LONG _
    ) AS LONG

DECLARE FUNCTION SafeArrayLock LIB "OleAut32.dll" ALIAS "SafeArrayLock" ( _
    psa AS SAFEARRAY _
    ) AS LONG

DECLARE FUNCTION SafeArrayUnlock LIB "OleAut32.dll" ALIAS "SafeArrayUnlock" ( _
    psa AS SAFEARRAY _
    ) AS LONG

DECLARE FUNCTION SafeArrayAccessData LIB "OleAut32.dll" _
    ALIAS "SafeArrayAccessData" ( _
    psa     AS SAFEARRAY, _
    ppvData AS ANY _  ' void HUGEP**
    ) AS LONG

DECLARE FUNCTION SafeArrayUnaccessData LIB "OleAut32.dll" _
    ALIAS "SafeArrayUnaccessData" ( _
    psa AS SAFEARRAY _
    ) AS LONG

DECLARE FUNCTION SafeArrayGetElement LIB "OleAut32.dll" _
    ALIAS "SafeArrayGetElement" ( _
    psa             AS SAFEARRAY, _
    BYVAL rgIndices AS LONG PTR, _
    pv              AS ANY _  ' void *
    ) AS LONG

DECLARE FUNCTION SafeArrayPutElement LIB "OleAut32.dll" _
    ALIAS "SafeArrayPutElement" ( _
    psa             AS SAFEARRAY, _
    BYVAL rgIndices AS LONG PTR, _
    pv              AS ANY _  ' void *
    ) AS LONG

DECLARE FUNCTION SafeArrayCopy LIB "OleAut32.dll" ALIAS "SafeArrayCopy" ( _
    psa     AS SAFEARRAY, _
    ppsaOut AS ANY _  ' SAFEARRAY **
    ) AS LONG

DECLARE FUNCTION SafeArrayPtrOfIndex LIB "OleAut32.dll" _
    ALIAS "SafeArrayPtrOfIndex" ( _
    psa             AS SAFEARRAY, _
    BYVAL rgIndices AS LONG PTR, _
    ppvData         AS ANY _  ' void **
    ) AS LONG

DECLARE FUNCTION SafeArraySetRecordInfo LIB "OleAut32.dll" _
    ALIAS "SafeArraySetRecordInfo" ( _
    psa    AS SAFEARRAY, _
    prinfo AS ANY _  ' IRecordInfo *
    ) AS LONG

DECLARE FUNCTION SafeArrayGetRecordInfo LIB "OleAut32.dll" _
    ALIAS "SafeArrayGetRecordInfo" ( _
    psa    AS SAFEARRAY, _
    prinfo AS ANY _  ' IRecordInfo **
    ) AS LONG

DECLARE FUNCTION SafeArraySetIID LIB "OleAut32.dll" ALIAS "SafeArraySetIID" ( _
    psa   AS SAFEARRAY, _
    rguid AS GUID _  ' REFGUID
    ) AS LONG

DECLARE FUNCTION SafeArrayGetIID LIB "OleAut32.dll" ALIAS "SafeArrayGetIID" ( _
    psa   AS SAFEARRAY, _
    pguid AS GUID _
    ) AS LONG

DECLARE FUNCTION SafeArrayGetVartype LIB "OleAut32.dll" _
    ALIAS "SafeArrayGetVartype" ( _
    psa AS SAFEARRAY, _
    pvt AS VARTYPE _
    ) AS LONG

DECLARE FUNCTION SafeArrayCreateVector LIB "OleAut32.dll" _
    ALIAS "SafeArrayCreateVector" ( _
    BYVAL vt        AS VARTYPE, _
    BYVAL lLbound   AS LONG, _
    BYVAL cElements AS DWORD _
    ) AS DWORD  ' SAFEARRAY *

DECLARE FUNCTION SafeArrayCreateVectorEx LIB "OleAut32.dll" _
    ALIAS "SafeArrayCreateVectorEx" ( _
    BYVAL vt        AS VARTYPE, _
    BYVAL lLbound   AS LONG, _
    BYVAL cElements AS DWORD, _
    pvExtra         AS ANY _  ' PVOID
    ) AS DWORD  ' SAFEARRAY *

'*---------------------------------------------------------------------*
'*                           VARIANT API                               *
'*---------------------------------------------------------------------*

DECLARE SUB VariantInit LIB "OleAut32.dll" ALIAS "VariantInit" ( _
    pvarg AS VARIANT _
    )

DECLARE FUNCTION VariantClear LIB "OleAut32.dll" ALIAS "VariantClear" ( _
    pvarg AS VARIANT _
    ) AS LONG

DECLARE FUNCTION VariantCopy LIB "OleAut32.dll" ALIAS "VariantCopy" ( _
    pvargDest AS VARIANT, _
    pvargSrc  AS VARIANT _
    ) AS LONG

DECLARE FUNCTION VariantCopyInd LIB "OleAut32.dll" ALIAS "VariantCopyInd" ( _
    pvarDest AS VARIANT, _
    pvargSrc AS VARIANT _
    ) AS LONG

DECLARE FUNCTION VariantChangeType LIB "OleAut32.dll" _
    ALIAS "VariantChangeType" ( _
    pvargDest    AS VARIANT, _
    pvarSrc      AS VARIANT, _
    BYVAL wFlags AS WORD, _
    BYVAL vt     AS VARTYPE _
    ) AS LONG

DECLARE FUNCTION VariantChangeTypeEx LIB "OleAut32.dll" _
    ALIAS "VariantChangeTypeEx" ( _
    pvargDest    AS VARIANT, _
    pvarSrc      AS VARIANT, _
    BYVAL lcid   AS DWORD, _  ' LCID
    BYVAL wFlags AS WORD, _
    BYVAL vt     AS VARTYPE _
    ) AS LONG

' Flags for VariantChangeType/VariantChangeTypeEx
%VARIANT_NOVALUEPROP     = &H01
%VARIANT_ALPHABOOL       = &H02 ' For %VT_BOOL to %VT_BSTR conversions,
                                ' convert to "True"/"False" instead of
                                ' "-1"/"0"
%VARIANT_NOUSEROVERRIDE  = &H04 ' For conversions to/from %VT_BSTR,
                                ' passes %LOCALE_NOUSEROVERRIDE
                                ' to core coercion routines
%VARIANT_CALENDAR_HIJRI  = &H08
%VARIANT_LOCALBOOL       = &H10 ' For %VT_BOOL to %VT_BSTR and back,
                                ' convert to local language rather than
                                ' English
%VARIANT_CALENDAR_THAI      = &H20  ' SOUTHASIA calendar support
%VARIANT_CALENDAR_GREGORIAN = &H40  ' SOUTHASIA calendar support
%VARIANT_USE_NLS            = &H80? ' NLS function call support
'*---------------------------------------------------------------------*
'*                Vector <-> Bstr conversion APIs                      *
'*---------------------------------------------------------------------*

DECLARE FUNCTION VectorFromBstr LIB "OleAut32.dll" ALIAS "VectorFromBstr" ( _
    bstr AS WSTRING, _
    ppsa AS ANY _  ' SAFEARRAY **
    ) AS LONG

DECLARE FUNCTION BstrFromVector LIB "OleAut32.dll" ALIAS "BstrFromVector" ( _
    psa   AS SAFEARRAY, _
    pbstr AS ANY _  ' BSTR *
    ) AS LONG

'*---------------------------------------------------------------------*
'*                     Variant API Flags                               *
'*---------------------------------------------------------------------*

' Any of the coersion functions that converts either from or to a string
' takes an additional lcid and dwFlags arguments. The lcid argument allows
' locale specific parsing to occur.  The dwFlags allow additional function
' specific condition to occur.  All function that accept the dwFlags argument
' can include either 0 or LOCALE_NOUSEROVERRIDE flag.
'

' The VarDateFromStr and VarBstrFromDate functions also accept the
' VAR_TIMEVALUEONLY and VAR_DATEVALUEONLY flags
'
%VAR_TIMEVALUEONLY       = &H00000001    ' return time value
%VAR_DATEVALUEONLY       = &H00000002    ' return date value

' VarDateFromUdate() only
%VAR_VALIDDATE           = &H00000004

' Accepted by all date & format APIs
%VAR_CALENDAR_HIJRI      = &H00000008    ' use Hijri calender

' Booleans can optionally be accepted in localized form. Pass VAR_LOCALBOOL
' into VarBoolFromStr and VarBstrFromBool to use localized boolean names
'
%VAR_LOCALBOOL           = &H00000010

' When passed into VarFormat and VarFormatFromTokens, prevents substitution
' of formats in the case where a string is passed in that can not be
' coverted into the desired type. (for ex, 'Format("Hello", "General Number")')
'
%VAR_FORMAT_NOSUBSTITUTE = &H00000020

'
' For VarBstrFromDate only - forces years to be 4 digits rather than shortening
' to 2-digits when the years is in the date window.
'
%VAR_FOURDIGITYEARS  = &H00000040

'
' Use NLS functions to format date, currency, time, and number.
'
#IF NOT %DEF(%LOCALE_USE_NLS)
%LOCALE_USE_NLS = &H10000000
#ENDIF

' SOUTHASIA START
' SOUTHASIA
' For VarBstrFromDate only - forces years to be 4 digits rather than shortening
' to 2-digits when the years is in the date window.
'
%VAR_CALENDAR_THAI      = &H00000080
%VAR_CALENDAR_GREGORIAN = &H00000100
'SOUTHASIA END

%VTDATEGRE_MAX = 2958465   ' Dec 31, 9999, 0:0:0 in Gregorian Calendar
%VTDATEGRE_MIN = -657434   ' Jan  1,  100, 0:0:0 in Gregorian Calendar
'*---------------------------------------------------------------------*
'*                     VARTYPE Coercion API                            *
'*---------------------------------------------------------------------*

' Note: The routines that convert *from* a string are defined
' to take a OLECHAR* rather than a BSTR because no allocation is
' required, and this makes the routines a bit more generic.
' They may of course still be passed a BSTR as the strIn param.
'

DECLARE FUNCTION VarUI1FromI2 LIB "OleAut32.dll" ALIAS "VarUI1FromI2" ( _
    BYVAL iIn AS INTEGER, _
    pbOut     AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarUI1FromI4 LIB "OleAut32.dll" ALIAS "VarUI1FromI4" ( _
    BYVAL lIn AS LONG, _
    pbOut     AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarUI1FromI8 LIB "OleAut32.dll" ALIAS "VarUI1FromI8" ( _
    BYVAL i64In AS QUAD, _
    pbOut       AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarUI1FromR4 LIB "OleAut32.dll" ALIAS "VarUI1FromR4" ( _
    BYVAL fltIn AS SINGLE, _
    pbOut       AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarUI1FromR8 LIB "OleAut32.dll" ALIAS "VarUI1FromR8" ( _
    BYVAL dblIn AS DOUBLE, _
    pbOut       AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarUI1FromCy LIB "OleAut32.dll" ALIAS "VarUI1FromCy" ( _
    BYVAL cyIn AS CURRENCY, _
    pbOut      AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarUI1FromDate LIB "OleAut32.dll" ALIAS "VarUI1FromDate" ( _
    BYVAL dateIn AS DOUBLE, _  ' DATE
    pbOut        AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarUI1FromStr LIB "OleAut32.dll" ALIAS "VarUI1FromStr" ( _
    strIn         AS WSTRING, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pbOut         AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarUI1FromDisp LIB "OleAut32.dll" ALIAS "VarUI1FromDisp" ( _
    pdispIn    AS ANY, _  ' IDispatch PTR
    BYVAL lcid AS DWORD, _  ' LCID
    pbOut      AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarUI1FromBool LIB "OleAut32.dll" ALIAS "VarUI1FromBool" ( _
    BYVAL boolIn AS VARIANT_BOOL, _
    pbOut        AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarUI1FromI1 LIB "OleAut32.dll" ALIAS "VarUI1FromI1" ( _
    BYVAL cIn AS BYTE, _
    pbOut     AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarUI1FromUI2 LIB "OleAut32.dll" ALIAS "VarUI1FromUI2" ( _
    BYVAL uiIn AS WORD, _
    pbOut      AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarUI1FromUI4 LIB "OleAut32.dll" ALIAS "VarUI1FromUI4" ( _
    BYVAL ulIn AS DWORD, _
    pbOut      AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarUI1FromUI8 LIB "OleAut32.dll" ALIAS "VarUI1FromUI8" ( _
    BYVAL ui64In AS QUAD, _  ' ULONG64
    pbOut        AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarUI1FromDec LIB "OleAut32.dll" ALIAS "VarUI1FromDec" ( _
    BYVAL pdecIn AS DECIMAL, _
    pbOut        AS BYTE _
    ) AS LONG


DECLARE FUNCTION VarI2FromUI1 LIB "OleAut32.dll" ALIAS "VarI2FromUI1" ( _
    BYVAL bIn AS BYTE, _
    psOut     AS INTEGER _
    ) AS LONG

DECLARE FUNCTION VarI2FromI4 LIB "OleAut32.dll" ALIAS "VarI2FromI4" ( _
    BYVAL lIn AS LONG, _
    psOut     AS INTEGER _
    ) AS LONG

DECLARE FUNCTION VarI2FromI8 LIB "OleAut32.dll" ALIAS "VarI2FromI8" ( _
    BYVAL i64In AS QUAD, _
    psOut       AS INTEGER _
    ) AS LONG

DECLARE FUNCTION VarI2FromR4 LIB "OleAut32.dll" ALIAS "VarI2FromR4" ( _
    BYVAL fltIn AS SINGLE, _
    psOut       AS INTEGER _
    ) AS LONG

DECLARE FUNCTION VarI2FromR8 LIB "OleAut32.dll" ALIAS "VarI2FromR8" ( _
    BYVAL dblIn AS DOUBLE, _
    psOut       AS INTEGER _
    ) AS LONG

DECLARE FUNCTION VarI2FromCy LIB "OleAut32.dll" ALIAS "VarI2FromCy" ( _
    BYVAL cyIn AS CURRENCY, _
    psOut      AS INTEGER _
    ) AS LONG

DECLARE FUNCTION VarI2FromDate LIB "OleAut32.dll" ALIAS "VarI2FromDate" ( _
    BYVAL dateIn AS DOUBLE, _  ' DATE
    psOut        AS INTEGER _
    ) AS LONG

DECLARE FUNCTION VarI2FromStr LIB "OleAut32.dll" ALIAS "VarI2FromStr" ( _
    strIn         AS WSTRING, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    psOut         AS INTEGER _
    ) AS LONG

DECLARE FUNCTION VarI2FromDisp LIB "OleAut32.dll" ALIAS "VarI2FromDisp" ( _
    pdispIn    AS ANY, _  ' IDispatch PTR
    BYVAL lcid AS DWORD, _  ' LCID
    psOut      AS INTEGER _
    ) AS LONG

DECLARE FUNCTION VarI2FromBool LIB "OleAut32.dll" ALIAS "VarI2FromBool" ( _
    BYVAL boolIn AS VARIANT_BOOL, _
    psOut        AS INTEGER _
    ) AS LONG

DECLARE FUNCTION VarI2FromI1 LIB "OleAut32.dll" ALIAS "VarI2FromI1" ( _
    BYVAL cIn AS BYTE, _
    psOut     AS INTEGER _
    ) AS LONG

DECLARE FUNCTION VarI2FromUI2 LIB "OleAut32.dll" ALIAS "VarI2FromUI2" ( _
    BYVAL uiIn AS WORD, _
    psOut      AS INTEGER _
    ) AS LONG

DECLARE FUNCTION VarI2FromUI4 LIB "OleAut32.dll" ALIAS "VarI2FromUI4" ( _
    BYVAL ulIn AS DWORD, _
    psOut      AS INTEGER _
    ) AS LONG

DECLARE FUNCTION VarI2FromUI8 LIB "OleAut32.dll" ALIAS "VarI2FromUI8" ( _
    BYVAL ui64In AS QUAD, _  ' ULONG64
    psOut        AS INTEGER _
    ) AS LONG

DECLARE FUNCTION VarI2FromDec LIB "OleAut32.dll" ALIAS "VarI2FromDec" ( _
    BYVAL pdecIn AS DECIMAL, _
    psOut        AS INTEGER _
    ) AS LONG


DECLARE FUNCTION VarI4FromUI1 LIB "OleAut32.dll" ALIAS "VarI4FromUI1" ( _
    BYVAL bIn AS BYTE, _
    plOut     AS LONG _
    ) AS LONG

DECLARE FUNCTION VarI4FromI2 LIB "OleAut32.dll" ALIAS "VarI4FromI2" ( _
    BYVAL iIn AS INTEGER, _
    plOut     AS LONG _
    ) AS LONG

DECLARE FUNCTION VarI4FromI8 LIB "OleAut32.dll" ALIAS "VarI4FromI8" ( _
    BYVAL i64In AS QUAD, _
    plOut       AS LONG _
    ) AS LONG

DECLARE FUNCTION VarI4FromR4 LIB "OleAut32.dll" ALIAS "VarI4FromR4" ( _
    BYVAL fltIn AS SINGLE, _
    plOut       AS LONG _
    ) AS LONG

DECLARE FUNCTION VarI4FromR8 LIB "OleAut32.dll" ALIAS "VarI4FromR8" ( _
    BYVAL dblIn AS DOUBLE, _
    plOut       AS LONG _
    ) AS LONG

DECLARE FUNCTION VarI4FromCy LIB "OleAut32.dll" ALIAS "VarI4FromCy" ( _
    BYVAL cyIn AS CURRENCY, _
    plOut      AS LONG _
    ) AS LONG

DECLARE FUNCTION VarI4FromDate LIB "OleAut32.dll" ALIAS "VarI4FromDate" ( _
    BYVAL dateIn AS DOUBLE, _  ' DATE
    plOut        AS LONG _
    ) AS LONG

DECLARE FUNCTION VarI4FromStr LIB "OleAut32.dll" ALIAS "VarI4FromStr" ( _
    strIn         AS WSTRING, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    plOut         AS LONG _
    ) AS LONG

DECLARE FUNCTION VarI4FromDisp LIB "OleAut32.dll" ALIAS "VarI4FromDisp" ( _
    pdispIn    AS ANY, _    ' IDispatch PTR
    BYVAL lcid AS DWORD, _  ' LCID
    plOut      AS LONG _
    ) AS LONG

DECLARE FUNCTION VarI4FromBool LIB "OleAut32.dll" ALIAS "VarI4FromBool" ( _
    BYVAL boolIn AS VARIANT_BOOL, _
    plOut        AS LONG _
    ) AS LONG

DECLARE FUNCTION VarI4FromI1 LIB "OleAut32.dll" ALIAS "VarI4FromI1" ( _
    BYVAL cIn AS BYTE, _
    plOut     AS LONG _
    ) AS LONG

DECLARE FUNCTION VarI4FromUI2 LIB "OleAut32.dll" ALIAS "VarI4FromUI2" ( _
    BYVAL uiIn AS WORD, _
    plOut      AS LONG _
    ) AS LONG

DECLARE FUNCTION VarI4FromUI4 LIB "OleAut32.dll" ALIAS "VarI4FromUI4" ( _
    BYVAL ulIn AS DWORD, _
    plOut      AS LONG _
    ) AS LONG

DECLARE FUNCTION VarI4FromUI8 LIB "OleAut32.dll" ALIAS "VarI4FromUI8" ( _
    BYVAL ui64In AS QUAD, _  ' ULONG64
    plOut        AS LONG _
    ) AS LONG

DECLARE FUNCTION VarI4FromDec LIB "OleAut32.dll" ALIAS "VarI4FromDec" ( _
    BYVAL pdecIn AS DECIMAL, _
    plOut        AS LONG _
    ) AS LONG

DECLARE FUNCTION VarI4FromInt LIB "OleAut32.dll" ALIAS "VarI4FromInt" ( _
    BYVAL intIn AS LONG, _
    plOut       AS LONG _
    ) AS LONG


'*******************************************

DECLARE FUNCTION VarI8FromUI1 LIB "OleAut32.dll" ALIAS "VarI8FromUI1" ( _
    BYVAL bIn AS BYTE, _
    pi64Out   AS QUAD _
    ) AS LONG

DECLARE FUNCTION VarI8FromI2 LIB "OleAut32.dll" ALIAS "VarI8FromI2" ( _
    BYVAL iIn AS INTEGER, _
    pi64Out   AS QUAD _
    ) AS LONG

DECLARE FUNCTION VarI8FromI4 LIB "OleAut32.dll" ALIAS "VarI8FromI4" ( _
    BYVAL lIn AS LONG, _
    pi64Out   AS QUAD _
    ) AS LONG

DECLARE FUNCTION VarI8FromR4 LIB "OleAut32.dll" ALIAS "VarI8FromR4" ( _
    BYVAL fltIn AS SINGLE, _
    pi64Out     AS QUAD _
    ) AS LONG

DECLARE FUNCTION VarI8FromR8 LIB "OleAut32.dll" ALIAS "VarI8FromR8" ( _
    BYVAL dblIn AS DOUBLE, _
    pi64Out     AS QUAD _
    ) AS LONG

DECLARE FUNCTION VarI8FromCy LIB "OleAut32.dll" ALIAS "VarI8FromCy" ( _
    BYVAL cyIn AS CURRENCY, _
    pi64Out    AS QUAD _
    ) AS LONG

DECLARE FUNCTION VarI8FromDate LIB "OleAut32.dll" ALIAS "VarI8FromDate" ( _
    BYVAL dateIn AS DOUBLE, _  ' DATA
    pi64Out      AS QUAD _
    ) AS LONG

DECLARE FUNCTION VarI8FromStr LIB "OleAut32.dll" ALIAS "VarI8FromStr" ( _
    strIn         AS WSTRING, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pi64Out       AS QUAD _
    ) AS LONG

DECLARE FUNCTION VarI8FromDisp LIB "OleAut32.dll" ALIAS "VarI8FromDisp" ( _
    pdispIn    AS ANY, _  ' IDispatch PTR
    BYVAL lcid AS DWORD, _  ' LCID
    pi64Out    AS QUAD _
    ) AS LONG

DECLARE FUNCTION VarI8FromBool LIB "OleAut32.dll" ALIAS "VarI8FromBool" ( _
    BYVAL boolIn AS VARIANT_BOOL, _
    pi64Out      AS QUAD _
    ) AS LONG

DECLARE FUNCTION VarI8FromI1 LIB "OleAut32.dll" ALIAS "VarI8FromI1" ( _
    BYVAL cIn AS BYTE, _
    pi64Out   AS QUAD _
    ) AS LONG

DECLARE FUNCTION VarI8FromUI2 LIB "OleAut32.dll" ALIAS "VarI8FromUI2" ( _
    BYVAL uiIn AS WORD, _
    pi64Out    AS QUAD _
    ) AS LONG

DECLARE FUNCTION VarI8FromUI4 LIB "OleAut32.dll" ALIAS "VarI8FromUI4" ( _
    BYVAL ulIn AS DWORD, _
    pi64Out    AS QUAD _
    ) AS LONG

DECLARE FUNCTION VarI8FromUI8 LIB "OleAut32.dll" ALIAS "VarI8FromUI8" ( _
    BYVAL ui64In AS QUAD, _  ' ULONG64
    pi64Out      AS QUAD _
    ) AS LONG

DECLARE FUNCTION VarI8FromDec LIB "OleAut32.dll" ALIAS "VarI8FromDec" ( _
    BYVAL pdecIn AS DECIMAL, _
    pi64Out      AS QUAD _
    ) AS LONG

DECLARE FUNCTION VarI8FromInt LIB "OleAut32.dll" ALIAS "VarI8FromInt" ( _
    BYVAL intIn AS LONG, _
    pi64Out     AS QUAD _
    ) AS LONG


'**********************



DECLARE FUNCTION VarR4FromUI1 LIB "OleAut32.dll" ALIAS "VarR4FromUI1" ( _
    BYVAL bIn AS BYTE, _
    pfltOut   AS SINGLE _
    ) AS LONG

DECLARE FUNCTION VarR4FromI2 LIB "OleAut32.dll" ALIAS "VarR4FromI2" ( _
    BYVAL iIn AS INTEGER, _
    pfltOut   AS SINGLE _
    ) AS LONG

DECLARE FUNCTION VarR4FromI4 LIB "OleAut32.dll" ALIAS "VarR4FromI4" ( _
    BYVAL lIn AS LONG, _
    pfltOut   AS SINGLE _
    ) AS LONG

DECLARE FUNCTION VarR4FromI8 LIB "OleAut32.dll" ALIAS "VarR4FromI8" ( _
    BYVAL i64In AS QUAD, _
    pfltOut     AS SINGLE _
    ) AS LONG

DECLARE FUNCTION VarR4FromR8 LIB "OleAut32.dll" ALIAS "VarR4FromR8" ( _
    BYVAL dblIn AS DOUBLE, _
    pfltOut     AS SINGLE _
    ) AS LONG

DECLARE FUNCTION VarR4FromCy LIB "OleAut32.dll" ALIAS "VarR4FromCy" ( _
    BYVAL cyIn AS CURRENCY, _
    pfltOut    AS SINGLE _
    ) AS LONG

DECLARE FUNCTION VarR4FromDate LIB "OleAut32.dll" ALIAS "VarR4FromDate" ( _
    BYVAL dateIn AS DOUBLE, _  ' DATE
    pfltOut      AS SINGLE _
    ) AS LONG

DECLARE FUNCTION VarR4FromStr LIB "OleAut32.dll" ALIAS "VarR4FromStr" ( _
    strIn         AS WSTRING, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pfltOut       AS SINGLE _
    ) AS LONG

DECLARE FUNCTION VarR4FromDisp LIB "OleAut32.dll" ALIAS "VarR4FromDisp" ( _
    pdispIn    AS ANY, _  ' IDispatch PTR
    BYVAL lcid AS DWORD, _  ' LCID
    pfltOut    AS SINGLE _
    ) AS LONG

DECLARE FUNCTION VarR4FromBool LIB "OleAut32.dll" ALIAS "VarR4FromBool" ( _
    BYVAL boolIn AS VARIANT_BOOL, _
    pfltOut      AS SINGLE _
    ) AS LONG

DECLARE FUNCTION VarR4FromI1 LIB "OleAut32.dll" ALIAS "VarR4FromI1" ( _
    BYVAL cIn AS BYTE, _
    pfltOut   AS SINGLE _
    ) AS LONG

DECLARE FUNCTION VarR4FromUI2 LIB "OleAut32.dll" ALIAS "VarR4FromUI2" ( _
    BYVAL uiIn AS WORD, _
    pfltOut    AS SINGLE _
    ) AS LONG

DECLARE FUNCTION VarR4FromUI4 LIB "OleAut32.dll" ALIAS "VarR4FromUI4" ( _
    BYVAL ulIn AS DWORD, _
    pfltOut    AS SINGLE _
    ) AS LONG

DECLARE FUNCTION VarR4FromUI8 LIB "OleAut32.dll" ALIAS "VarR4FromUI8" ( _
    BYVAL ui64In AS QUAD, _  ' ULONG64
    pfltOut      AS SINGLE _
    ) AS LONG

DECLARE FUNCTION VarR4FromDec LIB "OleAut32.dll" ALIAS "VarR4FromDec" ( _
    BYVAL pdecIn AS DECIMAL, _
    pfltOut      AS SINGLE _
    ) AS LONG


DECLARE FUNCTION VarR8FromUI1 LIB "OleAut32.dll" ALIAS "VarR8FromUI1" ( _
    BYVAL bIn AS BYTE, _
    pdblOut   AS DOUBLE _
    ) AS LONG

DECLARE FUNCTION VarR8FromI2 LIB "OleAut32.dll" ALIAS "VarR8FromI2" ( _
    BYVAL iIn AS INTEGER, _
    pdblOut   AS DOUBLE _
    ) AS LONG

DECLARE FUNCTION VarR8FromI4 LIB "OleAut32.dll" ALIAS "VarR8FromI4" ( _
    BYVAL lIn AS LONG, _
    pdblOut   AS DOUBLE _
    ) AS LONG

DECLARE FUNCTION VarR8FromI8 LIB "OleAut32.dll" ALIAS "VarR8FromI8" ( _
    BYVAL i64In AS QUAD, _
    pdblOut     AS DOUBLE _
    ) AS LONG

DECLARE FUNCTION VarR8FromR4 LIB "OleAut32.dll" ALIAS "VarR8FromR4" ( _
    BYVAL fltIn AS SINGLE, _
    pdblOut     AS DOUBLE _
    ) AS LONG

DECLARE FUNCTION VarR8FromCy LIB "OleAut32.dll" ALIAS "VarR8FromCy" ( _
    BYVAL cyIn AS CURRENCY, _
    pdblOut    AS DOUBLE _
    ) AS LONG

DECLARE FUNCTION VarR8FromDate LIB "OleAut32.dll" ALIAS "VarR8FromDate" ( _
    BYVAL dateIn AS DOUBLE, _  ' DATE
    pdblOut      AS DOUBLE _
    ) AS LONG

DECLARE FUNCTION VarR8FromStr LIB "OleAut32.dll" ALIAS "VarR8FromStr" ( _
    strIn         AS WSTRING, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pdblOut       AS DOUBLE _
    ) AS LONG

DECLARE FUNCTION VarR8FromDisp LIB "OleAut32.dll" ALIAS "VarR8FromDisp" ( _
    pdispIn    AS ANY, _  ' IDispatch PTR
    BYVAL lcid AS DWORD, _  ' LCID
    pdblOut    AS DOUBLE _
    ) AS LONG

DECLARE FUNCTION VarR8FromBool LIB "OleAut32.dll" ALIAS "VarR8FromBool" ( _
    BYVAL boolIn AS VARIANT_BOOL, _
    pdblOut      AS DOUBLE _
    ) AS LONG

DECLARE FUNCTION VarR8FromI1 LIB "OleAut32.dll" ALIAS "VarR8FromI1" ( _
    BYVAL cIn AS BYTE, _
    pdblOut   AS DOUBLE _
    ) AS LONG

DECLARE FUNCTION VarR8FromUI2 LIB "OleAut32.dll" ALIAS "VarR8FromUI2" ( _
    BYVAL uiIn AS WORD, _
    pdblOut    AS DOUBLE _
    ) AS LONG

DECLARE FUNCTION VarR8FromUI4 LIB "OleAut32.dll" ALIAS "VarR8FromUI4" ( _
    BYVAL ulIn AS DWORD, _
    pdblOut    AS DOUBLE _
    ) AS LONG

DECLARE FUNCTION VarR8FromUI8 LIB "OleAut32.dll" ALIAS "VarR8FromUI8" ( _
    BYVAL ui64In AS QUAD, _  ' ULONG64
    pdblOut      AS DOUBLE _
    ) AS LONG

DECLARE FUNCTION VarR8FromDec LIB "OleAut32.dll" ALIAS "VarR8FromDec" ( _
    BYVAL pdecIn AS DECIMAL, _
    pdblOut      AS DOUBLE _
    ) AS LONG


DECLARE FUNCTION VarDateFromUI1 LIB "OleAut32.dll" ALIAS "VarDateFromUI1" ( _
    BYVAL bIn AS BYTE, _
    pdateOut  AS DOUBLE _  ' DATE
    ) AS LONG

DECLARE FUNCTION VarDateFromI2 LIB "OleAut32.dll" ALIAS "VarDateFromI2" ( _
    BYVAL iIn AS INTEGER, _
    pdateOut  AS DOUBLE _  ' DATE
    ) AS LONG

DECLARE FUNCTION VarDateFromI4 LIB "OleAut32.dll" ALIAS "VarDateFromI4" ( _
    BYVAL lIn AS LONG, _
    pdateOut  AS DOUBLE _  ' DATE
    ) AS LONG

DECLARE FUNCTION VarDateFromI8 LIB "OleAut32.dll" ALIAS "VarDateFromI8" ( _
    BYVAL i64In AS QUAD, _
    pdateOut    AS DOUBLE _  ' DATE
    ) AS LONG

DECLARE FUNCTION VarDateFromR4 LIB "OleAut32.dll" ALIAS "VarDateFromR4" ( _
    BYVAL fltIn AS SINGLE, _
    pdateOut    AS DOUBLE _  ' DATE
    ) AS LONG

DECLARE FUNCTION VarDateFromR8 LIB "OleAut32.dll" ALIAS "VarDateFromR8" ( _
    BYVAL dblIn AS DOUBLE, _
    pdateOut    AS DOUBLE _  ' DATE
    ) AS LONG

DECLARE FUNCTION VarDateFromCy LIB "OleAut32.dll" ALIAS "VarDateFromCy" ( _
    BYVAL cyIn AS CURRENCY, _
    pdateOut   AS DOUBLE _  ' DATE
    ) AS LONG

DECLARE FUNCTION VarDateFromStr LIB "OleAut32.dll" ALIAS "VarDateFromStr" ( _
    strIn         AS WSTRING, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pdateOut      AS DOUBLE _  ' DATE
    ) AS LONG

DECLARE FUNCTION VarDateFromDisp LIB "OleAut32.dll" ALIAS "VarDateFromDisp" ( _
    pdispIn    AS ANY, _    ' IDispatch PTR
    BYVAL lcid AS DWORD, _  ' LCID
    pdateOut   AS DOUBLE _  ' DATE
    ) AS LONG

DECLARE FUNCTION VarDateFromBool LIB "OleAut32.dll" ALIAS "VarDateFromBool" ( _
    BYVAL boolIn AS VARIANT_BOOL, _
    pdateOut     AS DOUBLE _  ' DATE
    ) AS LONG

DECLARE FUNCTION VarDateFromI1 LIB "OleAut32.dll" ALIAS "VarDateFromI1" ( _
    BYVAL cIn AS BYTE, _
    pdateOut  AS DOUBLE _  ' DATE
    ) AS LONG

DECLARE FUNCTION VarDateFromUI2 LIB "OleAut32.dll" ALIAS "VarDateFromUI2" ( _
    BYVAL uiIn AS WORD, _
    pdateOut   AS DOUBLE _  ' DATE
    ) AS LONG

DECLARE FUNCTION VarDateFromUI4 LIB "OleAut32.dll" ALIAS "VarDateFromUI4" ( _
    BYVAL ulIn AS DWORD, _
    pdateOut   AS DOUBLE _  ' DATE
    ) AS LONG

DECLARE FUNCTION VarDateFromUI8 LIB "OleAut32.dll" ALIAS "VarDateFromUI8" ( _
    BYVAL ui64In AS QUAD, _   ' ULONG64
    pdateOut     AS DOUBLE _  ' DATE
    ) AS LONG

DECLARE FUNCTION VarDateFromDec LIB "OleAut32.dll" ALIAS "VarDateFromDec" ( _
    BYVAL pdecIn AS DECIMAL, _
    pdateOut     AS DOUBLE _  ' DATE
    ) AS LONG


DECLARE FUNCTION VarCyFromUI1 LIB "OleAut32.dll" ALIAS "VarCyFromUI1" ( _
    BYVAL bIn AS BYTE, _
    pcyOut    AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCyFromI2 LIB "OleAut32.dll" ALIAS "VarCyFromI2" ( _
    BYVAL iIn AS INTEGER, _
    pcyOut    AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCyFromI4 LIB "OleAut32.dll" ALIAS "VarCyFromI4" ( _
    BYVAL lIn AS LONG, _
    pcyOut    AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCyFromI8 LIB "OleAut32.dll" ALIAS "VarCyFromI8" ( _
    BYVAL i64In AS QUAD, _
    pcyOut      AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCyFromR4 LIB "OleAut32.dll" ALIAS "VarCyFromR4" ( _
    BYVAL fltIn AS SINGLE, _
    pcyOut      AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCyFromR8 LIB "OleAut32.dll" ALIAS "VarCyFromR8" ( _
    BYVAL dblIn AS DOUBLE, _
    pcyOut      AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCyFromDate LIB "OleAut32.dll" ALIAS "VarCyFromDate" ( _
    BYVAL dateIn AS DOUBLE, _  ' DATE
    pcyOut       AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCyFromStr LIB "OleAut32.dll" ALIAS "VarCyFromStr" ( _
    strIn         AS WSTRING, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pcyOut        AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCyFromDisp LIB "OleAut32.dll" ALIAS "VarCyFromDisp" ( _
    pdispIn    AS ANY, _  ' IDispatch PTR
    BYVAL lcid AS DWORD, _  ' LCID
    pcyOut     AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCyFromBool LIB "OleAut32.dll" ALIAS "VarCyFromBool" ( _
    BYVAL boolIn AS VARIANT_BOOL, _
    pcyOut       AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCyFromI1 LIB "OleAut32.dll" ALIAS "VarCyFromI1" ( _
    BYVAL cIn AS BYTE, _
    pcyOut    AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCyFromUI2 LIB "OleAut32.dll" ALIAS "VarCyFromUI2" ( _
    BYVAL uiIn AS WORD, _
    pcyOut     AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCyFromUI4 LIB "OleAut32.dll" ALIAS "VarCyFromUI4" ( _
    BYVAL ulIn AS DWORD, _
    pcyOut     AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCyFromUI8 LIB "OleAut32.dll" ALIAS "VarCyFromUI8" ( _
    BYVAL ui64In AS QUAD, _  ' ULONG64
    pcyOut       AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCyFromDec LIB "OleAut32.dll" ALIAS "VarCyFromDec" ( _
    BYVAL pdecIn AS DECIMAL, _
    pcyOut       AS CURRENCY _
    ) AS LONG


DECLARE FUNCTION VarBstrFromUI1 LIB "OleAut32.dll" ALIAS "VarBstrFromUI1" ( _
    BYVAL bVal    AS BYTE, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pbstrOut      AS ANY _     ' BSTR *
    ) AS LONG

DECLARE FUNCTION VarBstrFromI2 LIB "OleAut32.dll" ALIAS "VarBstrFromI2" ( _
    BYVAL iVal    AS INTEGER, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pbstrOut      AS ANY _     ' BSTR *
    ) AS LONG

DECLARE FUNCTION VarBstrFromI4 LIB "OleAut32.dll" ALIAS "VarBstrFromI4" ( _
    BYVAL lIn     AS LONG, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pbstrOut      AS ANY _     ' BSTR *
    ) AS LONG

DECLARE FUNCTION VarBstrFromI8 LIB "OleAut32.dll" ALIAS "VarBstrFromI8" ( _
    BYVAL i64In   AS QUAD, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pbstrOut      AS ANY _     ' BSTR *
    ) AS LONG

DECLARE FUNCTION VarBstrFromR4 LIB "OleAut32.dll" ALIAS "VarBstrFromR4" ( _
    BYVAL fltIn   AS SINGLE, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pbstrOut      AS ANY _     ' BSTR *
    ) AS LONG

DECLARE FUNCTION VarBstrFromR8 LIB "OleAut32.dll" ALIAS "VarBstrFromR8" ( _
    BYVAL dblIn   AS DOUBLE, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pbstrOut      AS ANY _     ' BSTR *
    ) AS LONG

DECLARE FUNCTION VarBstrFromCy LIB "OleAut32.dll" ALIAS "VarBstrFromCy" ( _
    BYVAL cyIn    AS CURRENCY, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pbstrOut      AS ANY _     ' BSTR *
    ) AS LONG

DECLARE FUNCTION VarBstrFromDate LIB "OleAut32.dll" ALIAS "VarBstrFromDate" ( _
    BYVAL dateIn  AS DOUBLE, _ ' DATE
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pbstrOut      AS ANY _     ' BSTR *
    ) AS LONG

DECLARE FUNCTION VarBstrFromDisp LIB "OleAut32.dll" ALIAS "VarBstrFromDisp" ( _
    pdispIn       AS ANY, _    ' IDispatch PTR
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pbstrOut      AS ANY _     ' BSTR *
    ) AS LONG

DECLARE FUNCTION VarBstrFromBool LIB "OleAut32.dll" ALIAS "VarBstrFromBool" ( _
    BYVAL boolIn  AS VARIANT_BOOL, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pbstrOut      AS ANY _     ' BSTR *
    ) AS LONG

DECLARE FUNCTION VarBstrFromI1 LIB "OleAut32.dll" ALIAS "VarBstrFromI1" ( _
    BYVAL cIn     AS BYTE, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pbstrOut      AS ANY _     ' BSTR *
    ) AS LONG

DECLARE FUNCTION VarBstrFromUI2 LIB "OleAut32.dll" ALIAS "VarBstrFromUI2" ( _
    BYVAL uiIn    AS WORD, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pbstrOut      AS ANY _     ' BSTR *
    ) AS LONG

DECLARE FUNCTION VarBstrFromUI4 LIB "OleAut32.dll" ALIAS "VarBstrFromUI4" ( _
    BYVAL ulIn    AS DWORD, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pbstrOut      AS ANY _     ' BSTR *
    ) AS LONG

DECLARE FUNCTION VarBstrFromUI8 LIB "OleAut32.dll" ALIAS "VarBstrFromUI8" ( _
    BYVAL ui64In  AS QUAD, _   ' ULONG64
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pbstrOut      AS ANY _     ' BSTR *
    ) AS LONG

DECLARE FUNCTION VarBstrFromDec LIB "OleAut32.dll" ALIAS "VarBstrFromDec" ( _
    BYVAL pdecIn  AS DECIMAL, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pbstrOut      AS ANY _     ' BSTR *
    ) AS LONG


DECLARE FUNCTION VarBoolFromUI1 LIB "OleAut32.dll" ALIAS "VarBoolFromUI1" ( _
    BYVAL bIn AS BYTE, _
    pboolOut  AS VARIANT_BOOL _
    ) AS LONG

DECLARE FUNCTION VarBoolFromI2 LIB "OleAut32.dll" ALIAS "VarBoolFromI2" ( _
    BYVAL iIn AS INTEGER, _
    pboolOut  AS VARIANT_BOOL _
    ) AS LONG

DECLARE FUNCTION VarBoolFromI4 LIB "OleAut32.dll" ALIAS "VarBoolFromI4" ( _
    BYVAL lIn AS LONG, _
    pboolOut  AS VARIANT_BOOL _
    ) AS LONG

DECLARE FUNCTION VarBoolFromI8 LIB "OleAut32.dll" ALIAS "VarBoolFromI8" ( _
    BYVAL i64In AS QUAD, _
    pboolOut    AS VARIANT_BOOL _
    ) AS LONG

DECLARE FUNCTION VarBoolFromR4 LIB "OleAut32.dll" ALIAS "VarBoolFromR4" ( _
    BYVAL fltIn AS SINGLE, _
    pboolOut    AS VARIANT_BOOL _
    ) AS LONG

DECLARE FUNCTION VarBoolFromR8 LIB "OleAut32.dll" ALIAS "VarBoolFromR8" ( _
    BYVAL dblIn AS DOUBLE, _
    pboolOut    AS VARIANT_BOOL _
    ) AS LONG

DECLARE FUNCTION VarBoolFromDate LIB "OleAut32.dll" ALIAS "VarBoolFromDate" ( _
    BYVAL dateIn AS DOUBLE, _  ' DATE
    pboolOut     AS VARIANT_BOOL _
    ) AS LONG

DECLARE FUNCTION VarBoolFromCy LIB "OleAut32.dll" ALIAS "VarBoolFromCy" ( _
    BYVAL cyIn AS CURRENCY, _
    pboolOut   AS VARIANT_BOOL _
    ) AS LONG

DECLARE FUNCTION VarBoolFromStr LIB "OleAut32.dll" ALIAS "VarBoolFromStr" ( _
    strIn         AS WSTRING, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pboolOut      AS VARIANT_BOOL _
    ) AS LONG

DECLARE FUNCTION VarBoolFromDisp LIB "OleAut32.dll" ALIAS "VarBoolFromDisp" ( _
    pdispIn    AS ANY, _  ' IDispatch PTR
    BYVAL lcid AS DWORD, _  ' LCID
    pboolOut   AS VARIANT_BOOL _
    ) AS LONG

DECLARE FUNCTION VarBoolFromI1 LIB "OleAut32.dll" ALIAS "VarBoolFromI1" ( _
    BYVAL cIn AS BYTE, _
    pboolOut  AS VARIANT_BOOL _
    ) AS LONG

DECLARE FUNCTION VarBoolFromUI2 LIB "OleAut32.dll" ALIAS "VarBoolFromUI2" ( _
    BYVAL uiIn AS WORD, _
    pboolOut   AS VARIANT_BOOL _
    ) AS LONG

DECLARE FUNCTION VarBoolFromUI4 LIB "OleAut32.dll" ALIAS "VarBoolFromUI4" ( _
    BYVAL ulIn AS DWORD, _
    pboolOut   AS VARIANT_BOOL _
    ) AS LONG

DECLARE FUNCTION VarBoolFromUI8 LIB "OleAut32.dll" ALIAS "VarBoolFromUI8" ( _
    BYVAL i64In AS QUAD, _  ' ULONG64
    pboolOut    AS VARIANT_BOOL _
    ) AS LONG

DECLARE FUNCTION VarBoolFromDec LIB "OleAut32.dll" ALIAS "VarBoolFromDec" ( _
    BYVAL pdecIn AS DECIMAL, _
    pboolOut     AS VARIANT_BOOL _
    ) AS LONG


DECLARE FUNCTION VarI1FromUI1 LIB "OleAut32.dll" ALIAS "VarI1FromUI1" ( _
    BYVAL bIn AS BYTE, _
    pcOut     AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarI1FromI2 LIB "OleAut32.dll" ALIAS "VarI1FromI2" ( _
    BYVAL uiIn AS INTEGER, _
    pcOut      AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarI1FromI4 LIB "OleAut32.dll" ALIAS "VarI1FromI4" ( _
    BYVAL lIn AS LONG, _
    pcOut     AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarI1FromI8 LIB "OleAut32.dll" ALIAS "VarI1FromI8" ( _
    BYVAL i64In AS QUAD, _
    pcOut       AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarI1FromR4 LIB "OleAut32.dll" ALIAS "VarI1FromR4" ( _
    BYVAL fltIn AS SINGLE, _
    pcOut       AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarI1FromR8 LIB "OleAut32.dll" ALIAS "VarI1FromR8" ( _
    BYVAL dblIn AS DOUBLE, _
    pcOut       AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarI1FromDate LIB "OleAut32.dll" ALIAS "VarI1FromDate" ( _
    BYVAL dateIn AS DOUBLE, _  ' DATE
    pcOut        AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarI1FromCy LIB "OleAut32.dll" ALIAS "VarI1FromCy" ( _
    BYVAL cyIn AS CURRENCY, _
    pcOut      AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarI1FromStr LIB "OleAut32.dll" ALIAS "VarI1FromStr" ( _
    strIn         AS WSTRING, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pcOut         AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarI1FromDisp LIB "OleAut32.dll" ALIAS "VarI1FromDisp" ( _
    pdispIn    AS ANY, _  ' IDispatch PTR
    BYVAL lcid AS DWORD, _  ' LCID
    pcOut      AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarI1FromBool LIB "OleAut32.dll" ALIAS "VarI1FromBool" ( _
    BYVAL boolIn AS VARIANT_BOOL, _
    pcOut        AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarI1FromUI2 LIB "OleAut32.dll" ALIAS "VarI1FromUI2" ( _
    BYVAL uiIn AS WORD, _
    pcOut      AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarI1FromUI4 LIB "OleAut32.dll" ALIAS "VarI1FromUI4" ( _
    BYVAL ulIn AS DWORD, _
    pcOut      AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarI1FromUI8 LIB "OleAut32.dll" ALIAS "VarI1FromUI8" ( _
    BYVAL i64In AS QUAD, _  ' ULONG64
    pcOut       AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarI1FromDec LIB "OleAut32.dll" ALIAS "VarI1FromDec" ( _
    BYVAL pdecIn AS DECIMAL, _
    pcOut        AS BYTE _
    ) AS LONG

DECLARE FUNCTION VarUI2FromUI1 LIB "OleAut32.dll" ALIAS "VarUI2FromUI1" ( _
    BYVAL bIn AS BYTE, _
    puiOut    AS WORD _
    ) AS LONG

DECLARE FUNCTION VarUI2FromI2 LIB "OleAut32.dll" ALIAS "VarUI2FromI2" ( _
    BYVAL uiIn AS INTEGER, _
    puiOut     AS WORD _
    ) AS LONG

DECLARE FUNCTION VarUI2FromI4 LIB "OleAut32.dll" ALIAS "VarUI2FromI4" ( _
    BYVAL lIn AS LONG, _
    puiOut    AS WORD _
    ) AS LONG

DECLARE FUNCTION VarUI2FromI8 LIB "OleAut32.dll" ALIAS "VarUI2FromI8" ( _
    BYVAL i64In AS QUAD, _
    puiOut      AS WORD _
    ) AS LONG

DECLARE FUNCTION VarUI2FromR4 LIB "OleAut32.dll" ALIAS "VarUI2FromR4" ( _
    BYVAL fltIn AS SINGLE, _
    puiOut      AS WORD _
    ) AS LONG

DECLARE FUNCTION VarUI2FromR8 LIB "OleAut32.dll" ALIAS "VarUI2FromR8" ( _
    BYVAL dblIn AS DOUBLE, _
    puiOut      AS WORD _
    ) AS LONG

DECLARE FUNCTION VarUI2FromDate LIB "OleAut32.dll" ALIAS "VarUI2FromDate" ( _
    BYVAL dateIn AS DOUBLE, _  ' DATE
    puiOut       AS WORD _
    ) AS LONG

DECLARE FUNCTION VarUI2FromCy LIB "OleAut32.dll" ALIAS "VarUI2FromCy" ( _
    BYVAL cyIn AS CURRENCY, _
    puiOut     AS WORD _
    ) AS LONG

DECLARE FUNCTION VarUI2FromStr LIB "OleAut32.dll" ALIAS "VarUI2FromStr" ( _
    strIn         AS WSTRING, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    puiOut        AS WORD _
    ) AS LONG

DECLARE FUNCTION VarUI2FromDisp LIB "OleAut32.dll" ALIAS "VarUI2FromDisp" ( _
    pdispIn AS ANY, _  ' IDispatch PTR
    BYVAL lcid AS DWORD, _  ' LCID
    puiOut     AS WORD _
    ) AS LONG

DECLARE FUNCTION VarUI2FromBool LIB "OleAut32.dll" ALIAS "VarUI2FromBool" ( _
    BYVAL boolIn AS VARIANT_BOOL, _
    puiOut       AS WORD _
    ) AS LONG

DECLARE FUNCTION VarUI2FromI1 LIB "OleAut32.dll" ALIAS "VarUI2FromI1" ( _
    BYVAL cIn AS BYTE, _
    puiOut    AS WORD _
    ) AS LONG

DECLARE FUNCTION VarUI2FromUI4 LIB "OleAut32.dll" ALIAS "VarUI2FromUI4" ( _
    BYVAL ulIn AS DWORD, _
    puiOut     AS WORD _
    ) AS LONG

DECLARE FUNCTION VarUI2FromUI8 LIB "OleAut32.dll" ALIAS "VarUI2FromUI8" ( _
    BYVAL i64In AS QUAD, _  ' ULONG64
    puiOut      AS WORD _
    ) AS LONG

DECLARE FUNCTION VarUI2FromDec LIB "OleAut32.dll" ALIAS "VarUI2FromDec" ( _
    BYVAL pdecIn AS DECIMAL, _
    puiOut       AS WORD _
    ) AS LONG


DECLARE FUNCTION VarUI4FromUI1 LIB "OleAut32.dll" ALIAS "VarUI4FromUI1" ( _
    BYVAL bIn AS BYTE, _
    pulOut    AS DWORD _
    ) AS LONG

DECLARE FUNCTION VarUI4FromI2 LIB "OleAut32.dll" ALIAS "VarUI4FromI2" ( _
    BYVAL uiIn AS INTEGER, _
    pulOut     AS DWORD _
    ) AS LONG

DECLARE FUNCTION VarUI4FromI4 LIB "OleAut32.dll" ALIAS "VarUI4FromI4" ( _
    BYVAL lIn AS LONG, _
    pulOut    AS DWORD _
    ) AS LONG

DECLARE FUNCTION VarUI4FromI8 LIB "OleAut32.dll" ALIAS "VarUI4FromI8" ( _
    BYVAL i64In AS QUAD, _
    plOut       AS DWORD _
    ) AS LONG

DECLARE FUNCTION VarUI4FromR4 LIB "OleAut32.dll" ALIAS "VarUI4FromR4" ( _
    BYVAL fltIn AS SINGLE, _
    pulOut      AS DWORD _
    ) AS LONG

DECLARE FUNCTION VarUI4FromR8 LIB "OleAut32.dll" ALIAS "VarUI4FromR8" ( _
    BYVAL dblIn AS DOUBLE, _
    pulOut      AS DWORD _
    ) AS LONG

DECLARE FUNCTION VarUI4FromDate LIB "OleAut32.dll" ALIAS "VarUI4FromDate" ( _
    BYVAL dateIn AS DOUBLE, _  ' DATE
    pulOut       AS DWORD _
    ) AS LONG

DECLARE FUNCTION VarUI4FromCy LIB "OleAut32.dll" ALIAS "VarUI4FromCy" ( _
    BYVAL cyIn AS CURRENCY, _
    pulOut     AS DWORD _
    ) AS LONG

DECLARE FUNCTION VarUI4FromStr LIB "OleAut32.dll" ALIAS "VarUI4FromStr" ( _
    strIn         AS WSTRING, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pulOut        AS DWORD _
    ) AS LONG

DECLARE FUNCTION VarUI4FromDisp LIB "OleAut32.dll" ALIAS "VarUI4FromDisp" ( _
    pdispIn    AS ANY, _  ' IDispatch PTR
    BYVAL lcid AS DWORD, _  ' LCID
    pulOut     AS DWORD _
    ) AS LONG

DECLARE FUNCTION VarUI4FromBool LIB "OleAut32.dll" ALIAS "VarUI4FromBool" ( _
    BYVAL boolIn AS VARIANT_BOOL, _
    pulOut       AS DWORD _
    ) AS LONG

DECLARE FUNCTION VarUI4FromI1 LIB "OleAut32.dll" ALIAS "VarUI4FromI1" ( _
    BYVAL cIn AS BYTE, _
    pulOut    AS DWORD _
    ) AS LONG

DECLARE FUNCTION VarUI4FromUI2 LIB "OleAut32.dll" ALIAS "VarUI4FromUI2" ( _
    BYVAL uiIn AS WORD, _
    pulOut     AS DWORD _
    ) AS LONG

DECLARE FUNCTION VarUI4FromUI8 LIB "OleAut32.dll" ALIAS "VarUI4FromUI8" ( _
    BYVAL ui64In AS QUAD, _  ' ULONG64
    plOut        AS DWORD _
    ) AS LONG

DECLARE FUNCTION VarUI4FromDec LIB "OleAut32.dll" ALIAS "VarUI4FromDec" ( _
    BYVAL pdecIn AS DECIMAL, _
    pulOut       AS DWORD _
    ) AS LONG


'*******************************************

DECLARE FUNCTION VarUI8FromUI1 LIB "OleAut32.dll" ALIAS "VarUI8FromUI1" ( _
    BYVAL bIn AS BYTE, _
    pi64Out   AS QUAD _  ' ULONG64
    ) AS LONG

DECLARE FUNCTION VarUI8FromI2 LIB "OleAut32.dll" ALIAS "VarUI8FromI2" ( _
    BYVAL iIn AS INTEGER, _
    pi64Out   AS QUAD _  ' ULONG64
    ) AS LONG

DECLARE FUNCTION VarUI8FromI4 LIB "OleAut32.dll" ALIAS "VarUI8FromI4" ( _
    BYVAL lIn AS LONG, _
    pi64Out   AS QUAD _  ' ULONG64
    ) AS LONG

DECLARE FUNCTION VarUI8FromI8 LIB "OleAut32.dll" ALIAS "VarUI8FromI8" ( _
    BYVAL ui64In AS QUAD, _
    pi64Out      AS QUAD _  ' ULONG64
    ) AS LONG

DECLARE FUNCTION VarUI8FromR4 LIB "OleAut32.dll" ALIAS "VarUI8FromR4" ( _
    BYVAL fltIn AS SINGLE, _
    pi64Out     AS QUAD _  ' ULONG64
    ) AS LONG

DECLARE FUNCTION VarUI8FromR8 LIB "OleAut32.dll" ALIAS "VarUI8FromR8" ( _
    BYVAL dblIn AS DOUBLE, _
    pi64Out     AS QUAD _  ' ULONG64
    ) AS LONG

DECLARE FUNCTION VarUI8FromCy LIB "OleAut32.dll" ALIAS "VarUI8FromCy" ( _
    BYVAL cyIn AS CURRENCY, _
    pi64Out    AS QUAD _  ' ULONG64
    ) AS LONG

DECLARE FUNCTION VarUI8FromDate LIB "OleAut32.dll" ALIAS "VarUI8FromDate" ( _
    BYVAL dateIn AS DOUBLE, _  ' DATE
    pi64Out      AS QUAD _     ' ULONG64
    ) AS LONG

DECLARE FUNCTION VarUI8FromStr LIB "OleAut32.dll" ALIAS "VarUI8FromStr" ( _
    strIn AS WSTRING, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pi64Out       AS QUAD _  ' ULONG64
    ) AS LONG

DECLARE FUNCTION VarUI8FromDisp LIB "OleAut32.dll" ALIAS "VarUI8FromDisp" ( _
    pdispIn    AS ANY, _  ' IDispatch PTR
    BYVAL lcid AS DWORD, _  ' LCID
    pi64Out    AS QUAD _  ' ULONG64
    ) AS LONG

DECLARE FUNCTION VarUI8FromBool LIB "OleAut32.dll" ALIAS "VarUI8FromBool" ( _
    BYVAL boolIn AS VARIANT_BOOL, _
    pi64Out      AS QUAD _  ' ULONG64
    ) AS LONG

DECLARE FUNCTION VarUI8FromI1 LIB "OleAut32.dll" ALIAS "VarUI8FromI1" ( _
    BYVAL cIn AS BYTE, _
    pi64Out   AS QUAD _  ' ULONG64
    ) AS LONG

DECLARE FUNCTION VarUI8FromUI2 LIB "OleAut32.dll" ALIAS "VarUI8FromUI2" ( _
    BYVAL uiIn AS WORD, _
    pi64Out    AS QUAD _  ' ULONG64
    ) AS LONG

DECLARE FUNCTION VarUI8FromUI4 LIB "OleAut32.dll" ALIAS "VarUI8FromUI4" ( _
    BYVAL ulIn AS DWORD, _
    pi64Out    AS QUAD _  ' ULONG64
    ) AS LONG

DECLARE FUNCTION VarUI8FromDec LIB "OleAut32.dll" ALIAS "VarUI8FromDec" ( _
    BYVAL pdecIn AS DECIMAL, _
    pi64Out      AS QUAD _  ' ULONG64
    ) AS LONG

DECLARE FUNCTION VarUI8FromInt LIB "OleAut32.dll" ALIAS "VarUI8FromInt" ( _
    BYVAL intIn AS LONG, _
    pi64Out     AS QUAD _  ' ULONG64
    ) AS LONG


'**********************



DECLARE FUNCTION VarDecFromUI1 LIB "OleAut32.dll" ALIAS "VarDecFromUI1" ( _
    BYVAL bIn AS BYTE, _
    pdecOut   AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecFromI2 LIB "OleAut32.dll" ALIAS "VarDecFromI2" ( _
    BYVAL uiIn AS INTEGER, _
    pdecOut    AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecFromI4 LIB "OleAut32.dll" ALIAS "VarDecFromI4" ( _
    BYVAL lIn AS LONG, _
    pdecOut   AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecFromI8 LIB "OleAut32.dll" ALIAS "VarDecFromI8" ( _
    BYVAL i64In AS QUAD, _
    pdecOut     AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecFromR4 LIB "OleAut32.dll" ALIAS "VarDecFromR4" ( _
    BYVAL fltIn AS SINGLE, _
    pdecOut     AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecFromR8 LIB "OleAut32.dll" ALIAS "VarDecFromR8" ( _
    BYVAL dblIn AS DOUBLE, _
    pdecOut     AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecFromDate LIB "OleAut32.dll" ALIAS "VarDecFromDate" ( _
    BYVAL dateIn AS DOUBLE, _  ' DATE
    pdecOut      AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecFromCy LIB "OleAut32.dll" ALIAS "VarDecFromCy" ( _
    BYVAL cyIn AS CURRENCY, _
    pdecOut    AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecFromStr LIB "OleAut32.dll" ALIAS "VarDecFromStr" ( _
    strIn         AS WSTRING, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pdecOut       AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecFromDisp LIB "OleAut32.dll" ALIAS "VarDecFromDisp" ( _
    pdispIn    AS ANY, _  ' IDispatch PTR
    BYVAL lcid AS DWORD, _  ' LCID
    pdecOut    AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecFromBool LIB "OleAut32.dll" ALIAS "VarDecFromBool" ( _
    BYVAL boolIn AS VARIANT_BOOL, _
    pdecOut      AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecFromI1 LIB "OleAut32.dll" ALIAS "VarDecFromI1" ( _
    BYVAL cIn AS BYTE, _
    pdecOut   AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecFromUI2 LIB "OleAut32.dll" ALIAS "VarDecFromUI2" ( _
    BYVAL uiIn AS WORD, _
    pdecOut    AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecFromUI4 LIB "OleAut32.dll" ALIAS "VarDecFromUI4" ( _
    BYVAL ulIn AS DWORD, _
    pdecOut    AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecFromUI8 LIB "OleAut32.dll" ALIAS "VarDecFromUI8" ( _
    BYVAL ui64In AS QUAD, _  ' ULONG64
    pdecOut      AS DECIMAL _
    ) AS LONG


'#define VarUI4FromUI4(in, pOut) (*(pOut) = (in))
'#define VarI4FromI4(in, pOut)   (*(pOut) = (in))

DECLARE FUNCTION VarI4FromI8 LIB "OleAut32.dll" ALIAS "VarI4FromI8" ( _
    BYVAL i64In AS QUAD, _
    plOut       AS LONG _
    ) AS LONG

DECLARE FUNCTION VarI4FromUI8 LIB "OleAut32.dll" ALIAS "VarI4FromUI8" ( _
    BYVAL ui64In AS QUAD, _  ' ULONG64
    plOut        AS LONG _
    ) AS LONG


'#define VarUI8FromUI8(in, pOut) (*(pOut) = (in))
'#define VarI8FromI8(in, pOut)   (*(pOut) = (in))


'#define VarUI1FromInt       VarUI1FromI4
'#define VarUI1FromUint      VarUI1FromUI4
'#define VarI2FromInt        VarI2FromI4
'#define VarI2FromUint       VarI2FromUI4
'#define VarI4FromInt        VarI4FromI4
'#define VarI4FromUint       VarI4FromUI4
'#define VarI8FromInt        VarI8FromI4
'#define VarI8FromUint       VarI8FromUI4
'#define VarR4FromInt        VarR4FromI4
'#define VarR4FromUint       VarR4FromUI4
'#define VarR8FromInt        VarR8FromI4
'#define VarR8FromUint       VarR8FromUI4
'#define VarDateFromInt      VarDateFromI4
'#define VarDateFromUint     VarDateFromUI4
'#define VarCyFromInt        VarCyFromI4
'#define VarCyFromUint       VarCyFromUI4
'#define VarBstrFromInt      VarBstrFromI4
'#define VarBstrFromUint     VarBstrFromUI4
'#define VarBoolFromInt      VarBoolFromI4
'#define VarBoolFromUint     VarBoolFromUI4
'#define VarI1FromInt        VarI1FromI4
'#define VarI1FromUint       VarI1FromUI4
'#define VarUI2FromInt       VarUI2FromI4
'#define VarUI2FromUint      VarUI2FromUI4
'#define VarUI4FromInt       VarUI4FromI4
'#define VarUI4FromUint      VarUI4FromUI4
'#define VarDecFromInt       VarDecFromI4
'#define VarDecFromUint      VarDecFromUI4
'#define VarIntFromUI1       VarI4FromUI1
'#define VarIntFromI2        VarI4FromI2
'#define VarIntFromI4        VarI4FromI4
'#define VarIntFromI8        VarI4FromI8
'#define VarIntFromR4        VarI4FromR4
'#define VarIntFromR8        VarI4FromR8
'#define VarIntFromDate      VarI4FromDate
'#define VarIntFromCy        VarI4FromCy
'#define VarIntFromStr       VarI4FromStr
'#define VarIntFromDisp      VarI4FromDisp
'#define VarIntFromBool      VarI4FromBool
'#define VarIntFromI1        VarI4FromI1
'#define VarIntFromUI2       VarI4FromUI2
'#define VarIntFromUI4       VarI4FromUI4
'#define VarIntFromUI8       VarI4FromUI8
'#define VarIntFromDec       VarI4FromDec
'#define VarIntFromUint      VarI4FromUI4
'#define VarUintFromUI1      VarUI4FromUI1
'#define VarUintFromI2       VarUI4FromI2
'#define VarUintFromI4       VarUI4FromI4
'#define VarUintFromI8       VarUI4FromI8
'#define VarUintFromR4       VarUI4FromR4
'#define VarUintFromR8       VarUI4FromR8
'#define VarUintFromDate     VarUI4FromDate
'#define VarUintFromCy       VarUI4FromCy
'#define VarUintFromStr      VarUI4FromStr
'#define VarUintFromDisp     VarUI4FromDisp
'#define VarUintFromBool     VarUI4FromBool
'#define VarUintFromI1       VarUI4FromI1
'#define VarUintFromUI2      VarUI4FromUI2
'#define VarUintFromUI4      VarUI4FromUI4
'#define VarUintFromUI8      VarUI4FromUI8
'#define VarUintFromDec      VarUI4FromDec
'#define VarUintFromInt      VarUI4FromI4

' Mac Note: On the Mac, the coersion functions support the
' Symantec C++ calling convention for float/double. To support
' float/double arguments compiled with the MPW C compiler,
' use the following APIs to move MPW float/double values into
' a VARIANT.
'

'*---------------------------------------------------------------------*
'*            New VARIANT <-> string parsing functions                 *
'*---------------------------------------------------------------------*

TYPE NUMPARSE
    cDig       AS LONG
    dwInFlags  AS DWORD
    dwOutFlags AS DWORD
    cchUsed    AS LONG
    nBaseShift AS LONG
    nPwr10     AS LONG
END TYPE

' flags used by both dwInFlags and dwOutFlags:
'
%NUMPRS_LEADING_WHITE  = &H0001
%NUMPRS_TRAILING_WHITE = &H0002
%NUMPRS_LEADING_PLUS   = &H0004
%NUMPRS_TRAILING_PLUS  = &H0008
%NUMPRS_LEADING_MINUS  = &H0010
%NUMPRS_TRAILING_MINUS = &H0020
%NUMPRS_HEX_OCT        = &H0040
%NUMPRS_PARENS         = &H0080
%NUMPRS_DECIMAL        = &H0100
%NUMPRS_THOUSANDS      = &H0200
%NUMPRS_CURRENCY       = &H0400
%NUMPRS_EXPONENT       = &H0800
%NUMPRS_USE_ALL        = &H1000
%NUMPRS_STD            = &H1FFF

' flags used by dwOutFlags only:
'
%NUMPRS_NEG            = &H10000
%NUMPRS_INEXACT        = &H20000

' flags used by VarNumFromParseNum to indicate acceptable result types:
'
%VTBIT_I1      = &B10000000000000000      ' (1 << %VT_I1)
%VTBIT_UI1     = &B100000000000000000     ' (1 << %VT_UI1)
%VTBIT_I2      = &B100                    ' (1 << %VT_I2)
%VTBIT_UI2     = &B1000000000000000000    ' (1 << %VT_UI2)
%VTBIT_I4      = &B1000                   ' (1 << %VT_I4)
%VTBIT_UI4     = &B10000000000000000000   ' (1 << %VT_UI4)
%VTBIT_I8      = &B100000000000000000000  ' (1 << %VT_I8)
%VTBIT_UI8     = &B1000000000000000000000 ' (1 << %VT_UI8)
%VTBIT_R4      = &B10000                  ' (1 << %VT_R4)
%VTBIT_R8      = &B100000                 ' (1 << %VT_R8)
%VTBIT_CY      = &B1000000                ' (1 << %VT_CY)
%VTBIT_DECIMAL = &B100000000000000        ' (1 << %VT_DECIMAL)


DECLARE FUNCTION VarParseNumFromStr LIB "OleAut32.dll" _
    ALIAS "VarParseNumFromStr" ( _
    strIn         AS WSTRING, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD, _
    pnumprs       AS NUMPARSE, _
    BYVAL rgbDig  AS BYTE PTR _
    ) AS LONG

DECLARE FUNCTION VarNumFromParseNum LIB "OleAut32.dll" _
    ALIAS "VarNumFromParseNum" ( _
    pnumprs        AS NUMPARSE, _
    BYVAL rgbDig   AS BYTE PTR, _
    BYVAL dwVtBits AS DWORD, _
    pvar           AS VARIANT _
    ) AS LONG

'*---------------------------------------------------------------------*
'*                     VARTYPE Math API                                *
'*---------------------------------------------------------------------*

DECLARE FUNCTION VarAdd LIB "OleAut32.dll" ALIAS "VarAdd" ( _
    pvarLeft   AS VARIANT, _
    pvarRight  AS VARIANT, _
    pvarResult AS VARIANT _
    ) AS LONG

DECLARE FUNCTION VarAnd LIB "OleAut32.dll" ALIAS "VarAnd" ( _
    pvarLeft   AS VARIANT, _
    pvarRight  AS VARIANT, _
    pvarResult AS VARIANT _
    ) AS LONG

DECLARE FUNCTION VarCat LIB "OleAut32.dll" ALIAS "VarCat" ( _
    pvarLeft   AS VARIANT, _
    pvarRight  AS VARIANT, _
    pvarResult AS VARIANT _
    ) AS LONG

DECLARE FUNCTION VarDiv LIB "OleAut32.dll" ALIAS "VarDiv" ( _
    pvarLeft   AS VARIANT, _
    pvarRight  AS VARIANT, _
    pvarResult AS VARIANT _
    ) AS LONG

DECLARE FUNCTION VarEqv LIB "OleAut32.dll" ALIAS "VarEqv" ( _
    pvarLeft   AS VARIANT, _
    pvarRight  AS VARIANT, _
    pvarResult AS VARIANT _
    ) AS LONG

DECLARE FUNCTION VarIdiv LIB "OleAut32.dll" ALIAS "VarIdiv" ( _
    pvarLeft   AS VARIANT, _
    pvarRight  AS VARIANT, _
    pvarResult AS VARIANT _
    ) AS LONG

DECLARE FUNCTION VarImp LIB "OleAut32.dll" ALIAS "VarImp" ( _
    pvarLeft   AS VARIANT, _
    pvarRight  AS VARIANT, _
    pvarResult AS VARIANT _
    ) AS LONG

DECLARE FUNCTION VarMod LIB "OleAut32.dll" ALIAS "VarMod" ( _
    pvarLeft   AS VARIANT, _
    pvarRight  AS VARIANT, _
    pvarResult AS VARIANT _
    ) AS LONG

DECLARE FUNCTION VarMul LIB "OleAut32.dll" ALIAS "VarMul" ( _
    pvarLeft   AS VARIANT, _
    pvarRight  AS VARIANT, _
    pvarResult AS VARIANT _
    ) AS LONG

DECLARE FUNCTION VarOr LIB "OleAut32.dll" ALIAS "VarOr" ( _
    pvarLeft   AS VARIANT, _
    pvarRight  AS VARIANT, _
    pvarResult AS VARIANT _
    ) AS LONG

DECLARE FUNCTION VarPow LIB "OleAut32.dll" ALIAS "VarPow" ( _
    pvarLeft   AS VARIANT, _
    pvarRight  AS VARIANT, _
    pvarResult AS VARIANT _
    ) AS LONG

DECLARE FUNCTION VarSub LIB "OleAut32.dll" ALIAS "VarSub" ( _
    pvarLeft   AS VARIANT, _
    pvarRight  AS VARIANT, _
    pvarResult AS VARIANT _
    ) AS LONG

DECLARE FUNCTION VarXor LIB "OleAut32.dll" ALIAS "VarXor" ( _
    pvarLeft   AS VARIANT, _
    pvarRight  AS VARIANT, _
    pvarResult AS VARIANT _
    ) AS LONG


DECLARE FUNCTION VarAbs LIB "OleAut32.dll" ALIAS "VarAbs" ( _
    pvarIn     AS VARIANT, _
    pvarResult AS VARIANT _
    ) AS LONG

DECLARE FUNCTION VarFix LIB "OleAut32.dll" ALIAS "VarFix" ( _
    pvarIn     AS VARIANT, _
    pvarResult AS VARIANT _
    ) AS LONG

DECLARE FUNCTION VarInt LIB "OleAut32.dll" ALIAS "VarInt" ( _
    pvarIn     AS VARIANT, _
    pvarResult AS VARIANT _
    ) AS LONG

DECLARE FUNCTION VarNeg LIB "OleAut32.dll" ALIAS "VarNeg" ( _
    pvarIn     AS VARIANT, _
    pvarResult AS VARIANT _
    ) AS LONG

DECLARE FUNCTION VarNot LIB "OleAut32.dll" ALIAS "VarNot" ( _
    pvarIn     AS VARIANT, _
    pvarResult AS VARIANT _
    ) AS LONG

DECLARE FUNCTION VarRound LIB "OleAut32.dll" ALIAS "VarRound" ( _
    pvarIn          AS VARIANT, _
    BYVAL cDecimals AS LONG, _
    pvarResult      AS VARIANT _
    ) AS LONG

' dwFlags passed to CompareString if a string compare
DECLARE FUNCTION VarCmp LIB "OleAut32.dll" ALIAS "VarCmp" ( _
    pvarLeft      AS VARIANT, _
    pvarRight     AS VARIANT, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD _
    ) AS LONG

' Add wrapper for old ATL headers to call
'HRESULT
'VarCmp(LPVARIANT pvarLeft, LPVARIANT pvarRight, LCID lcid) {
'    return VarCmp(pvarLeft, pvarRight, lcid, 0);
'}


' Decimal math
'
DECLARE FUNCTION VarDecAdd LIB "OleAut32.dll" ALIAS "VarDecAdd" ( _
    pdecLeft   AS DECIMAL, _
    pdecRight  AS DECIMAL, _
    pdecResult AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecDiv LIB "OleAut32.dll" ALIAS "VarDecDiv" ( _
    pdecLeft   AS DECIMAL, _
    pdecRight  AS DECIMAL, _
    pdecResult AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecMul LIB "OleAut32.dll" ALIAS "VarDecMul" ( _
    pdecLeft   AS DECIMAL, _
    pdecRight  AS DECIMAL, _
    pdecResult AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecSub LIB "OleAut32.dll" ALIAS "VarDecSub" ( _
    pdecLeft   AS DECIMAL, _
    pdecRight  AS DECIMAL, _
    pdecResult AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecAbs LIB "OleAut32.dll" ALIAS "VarDecAbs" ( _
    pdecIn     AS DECIMAL, _
    pdecResult AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecFix LIB "OleAut32.dll" ALIAS "VarDecFix" ( _
    pdecIn     AS DECIMAL, _
    pdecResult AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecInt LIB "OleAut32.dll" ALIAS "VarDecInt" ( _
    pdecIn     AS DECIMAL, _
    pdecResult AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecNeg LIB "OleAut32.dll" ALIAS "VarDecNeg" ( _
    pdecIn     AS DECIMAL, _
    pdecResult AS DECIMAL _
    ) AS LONG


DECLARE FUNCTION VarDecRound LIB "OleAut32.dll" ALIAS "VarDecRound" ( _
    pdecIn          AS DECIMAL, _
    BYVAL cDecimals AS LONG, _
    pdecResult      AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecCmp LIB "OleAut32.dll" ALIAS "VarDecCmp" ( _
    pdecLeft  AS DECIMAL, _
    pdecRight AS DECIMAL _
    ) AS LONG

DECLARE FUNCTION VarDecCmpR8 LIB "OleAut32.dll" ALIAS "VarDecCmpR8" ( _
    pdecLeft AS DECIMAL, _
    BYVAL dblRight AS DOUBLE _
    ) AS LONG


' Currency math
'
DECLARE FUNCTION VarCyAdd LIB "OleAut32.dll" ALIAS "VarCyAdd" ( _
    BYVAL cyLeft  AS CURRENCY, _
    BYVAL cyRight AS CURRENCY, _
    pcyResult     AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCyMul LIB "OleAut32.dll" ALIAS "VarCyMul" ( _
    BYVAL cyLeft  AS CURRENCY, _
    BYVAL cyRight AS CURRENCY, _
    pcyResult     AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCyMulI4 LIB "OleAut32.dll" ALIAS "VarCyMulI4" ( _
    BYVAL cyLeft AS CURRENCY, _
    BYVAL lRight AS LONG, _
    pcyResult    AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCyMulI8 LIB "OleAut32.dll" ALIAS "VarCyMulI8" ( _
    BYVAL cyLeft AS CURRENCY, _
    BYVAL lRight AS QUAD, _
    pcyResult    AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCySub LIB "OleAut32.dll" ALIAS "VarCySub" ( _
    BYVAL cyLeft  AS CURRENCY, _
    BYVAL cyRight AS CURRENCY, _
    pcyResult     AS CURRENCY _
    ) AS LONG


DECLARE FUNCTION VarCyAbs LIB "OleAut32.dll" ALIAS "VarCyAbs" ( _
    BYVAL cyIn AS CURRENCY, _
    pcyResult  AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCyFix LIB "OleAut32.dll" ALIAS "VarCyFix" ( _
    BYVAL cyIn AS CURRENCY, _
    pcyResult  AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCyInt LIB "OleAut32.dll" ALIAS "VarCyInt" ( _
    BYVAL cyIn AS CURRENCY, _
    pcyResult  AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCyNeg LIB "OleAut32.dll" ALIAS "VarCyNeg" ( _
    BYVAL cyIn AS CURRENCY, _
    pcyResult  AS CURRENCY _
    ) AS LONG


DECLARE FUNCTION VarCyRound LIB "OleAut32.dll" ALIAS "VarCyRound" ( _
    BYVAL cyIn      AS CURRENCY, _
    BYVAL cDecimals AS LONG, _
    pcyResult       AS CURRENCY _
    ) AS LONG


DECLARE FUNCTION VarCyCmp LIB "OleAut32.dll" ALIAS "VarCyCmp" ( _
    BYVAL cyLeft  AS CURRENCY, _
    BYVAL cyRight AS CURRENCY _
    ) AS LONG

DECLARE FUNCTION VarCyCmpR8 LIB "OleAut32.dll" ALIAS "VarCyCmpR8" ( _
    BYVAL cyLeft   AS CURRENCY, _
    BYVAL dblRight AS DOUBLE _
    ) AS LONG


' Misc support functions
'
DECLARE FUNCTION VarBstrCat LIB "OleAut32.dll" ALIAS "VarBstrCat" ( _
    bstrLeft    AS STRING, _
    bstrRight   AS STRING, _
    pbstrResult AS STRING _
    ) AS LONG

DECLARE FUNCTION VarBstrCmp LIB "OleAut32.dll" ALIAS "VarBstrCmp" ( _
    bstrLeft      AS STRING, _
    bstrRight     AS STRING, _
    BYVAL lcid    AS DWORD, _  ' LCID
    BYVAL dwFlags AS DWORD _   ' dwFlags passed to CompareString
    ) AS LONG

DECLARE FUNCTION VarR8Pow LIB "OleAut32.dll" ALIAS "VarR8Pow" ( _
    BYVAL dblLeft  AS DOUBLE, _
    BYVAL dblRight AS DOUBLE, _
    pdblResult     AS DOUBLE _
    ) AS LONG

DECLARE FUNCTION VarR4CmpR8 LIB "OleAut32.dll" ALIAS "VarR4CmpR8" ( _
    BYVAL fltLeft  AS SINGLE, _
    BYVAL dblRight AS DOUBLE _
    ) AS LONG

DECLARE FUNCTION VarR8Round LIB "OleAut32.dll" ALIAS "VarR8Round" ( _
    BYVAL dblIn     AS DOUBLE, _
    BYVAL cDecimals AS LONG, _
    pdblResult      AS DOUBLE _
    ) AS LONG


' Compare results.  These are returned as a SUCCESS HResult.  Subtracting
' one gives the usual values of -1 for Less Than, 0 for Equal To, +1 for
' Greater Than.
'
%VARCMP_LT   = 0
%VARCMP_EQ   = 1
%VARCMP_GT   = 2
%VARCMP_NULL = 3

' VT_HARDTYPE tells the compare routine that the argument is a literal or
' otherwise declared of that specific type.  It causes comparison rules to
' change. For example, if a hard-type string is compared to a variant (not hard
' -type) number, the number is converted to string.  If a hard-type number is
' compared to a variant string, the string is converted to number.  If they're
' both variant, then number < string.
%VT_HARDTYPE = %VT_RESERVED

'*---------------------------------------------------------------------*
'*                   New date functions                                *
'*---------------------------------------------------------------------*

' The UDATE structure is used with VarDateFromUdate() and VarUdateFromDate().
' It represents an "unpacked date".
'
TYPE UDATE
    st         AS SYSTEMTIME
    wDayOfYear AS WORD
END TYPE

' APIs to "pack" and "unpack" dates.
' NOTE: Ex version of VarDateFromUdate obeys 2 digit year setting in
' control panel.
'
DECLARE FUNCTION VarDateFromUdate LIB "OleAut32.dll" _
    ALIAS "VarDateFromUdate" ( _
    pudateIn      AS UDATE, _
    BYVAL dwFlags AS DWORD, _
    pdateOut      AS DOUBLE _  ' DATE
    ) AS LONG

DECLARE FUNCTION VarDateFromUdateEx LIB "OleAut32.dll" _
    ALIAS "VarDateFromUdateEx" ( _
    pudateIn       AS UDATE, _
    BYVAL lcid     AS DWORD, _  ' LCID
    BYVAL dwFlags  AS DWORD, _
    pdateOut       AS DOUBLE _  ' DATE
    ) AS LONG

DECLARE FUNCTION VarUdateFromDate LIB "OleAut32.dll" _
    ALIAS "VarUdateFromDate" ( _
    BYVAL dateIn  AS DOUBLE, _  ' DATE
    BYVAL dwFlags AS DWORD, _
    pudateOut     AS UDATE _
    ) AS LONG

' API to retrieve the secondary(altername) month names
' Useful for Hijri, Polish and Russian alternate month names
'
DECLARE FUNCTION GetAltMonthNames LIB "OleAut32.dll" _
    ALIAS "GetAltMonthNames" ( _
    BYVAL lcid AS DWORD, _  ' LCID
    prgp       AS ANY _     ' LPOLESTR * *
    ) AS LONG

'*---------------------------------------------------------------------*
'*                 Format                                              *
'*---------------------------------------------------------------------*

DECLARE FUNCTION VarFormat LIB "OleAut32.dll" ALIAS "VarFormat" ( _
    pvarIn           AS VARIANT, _
    pstrFormat       AS STRING, _
    BYVAL iFirstDay  AS LONG, _
    BYVAL iFirstWeek AS LONG, _
    BYVAL dwFlags    AS DWORD, _
    pbstrOut         AS STRING _
    ) AS LONG

DECLARE FUNCTION VarFormatDateTime LIB "OleAut32.dll" _
    ALIAS "VarFormatDateTime" ( _
    pvarIn             AS VARIANT, _
    BYVAL iNamedFormat AS LONG, _
    dwFlags            AS DWORD, _
    pbstrOut           AS STRING _
    ) AS LONG

DECLARE FUNCTION VarFormatNumber LIB "OleAut32.dll" ALIAS "VarFormatNumber" ( _
    pvarIn           AS VARIANT, _
    BYVAL iNumDig    AS LONG, _
    BYVAL iIncLead   AS LONG, _
    BYVAL iUseParens AS LONG, _
    BYVAL iGroup     AS LONG, _
    BYVAL dwFlags    AS DWORD, _
    pbstrOut         AS STRING _
    ) AS LONG

DECLARE FUNCTION VarFormatPercent LIB "OleAut32.dll" _
    ALIAS "VarFormatPercent" ( _
    pvarIn           AS VARIANT, _
    BYVAL iNumDig    AS LONG, _
    BYVAL iIncLead   AS LONG, _
    BYVAL iUseParens AS LONG, _
    BYVAL iGroup     AS LONG, _
    BYVAL dwFlags    AS DWORD, _
    pbstrOut         AS STRING _
    ) AS LONG

DECLARE FUNCTION VarFormatCurrency LIB "OleAut32.dll" _
    ALIAS "VarFormatCurrency" ( _
    pvarIn           AS VARIANT, _
    BYVAL iNumDig    AS LONG, _
    BYVAL iIncLead   AS LONG, _
    BYVAL iUseParens AS LONG, _
    BYVAL iGroup     AS LONG, _
    BYVAL dwFlags    AS DWORD, _
    pbstrOut         AS STRING _
    ) AS LONG

DECLARE FUNCTION VarWeekdayName LIB "OleAut32.dll" ALIAS "VarWeekdayName" ( _
    BYVAL iWeekday  AS LONG, _
    BYVAL fAbbrev   AS LONG, _
    BYVAL iFirstDay AS LONG, _
    BYVAL dwFlags   AS DWORD, _
    pbstrOut        AS STRING _
    ) AS LONG

DECLARE FUNCTION VarMonthName LIB "OleAut32.dll" ALIAS "VarMonthName" ( _
    BYVAL iMonth  AS LONG, _
    BYVAL fAbbrev AS LONG, _
    BYVAL dwFlags AS DWORD, _
    pbstrOut      AS STRING _
    ) AS LONG

DECLARE FUNCTION VarFormatFromTokens LIB "OleAut32.dll" _
    ALIAS "VarFormatFromTokens" ( _
    pvarIn         AS VARIANT, _
    pstrFormat     AS STRING, _
    BYVAL pbTokCur AS BYTE PTR, _
    BYVAL dwFlags  AS DWORD, _
    pbstrOut       AS STRING, _
    lcid           AS DWORD _  ' LCID
    ) AS LONG

DECLARE FUNCTION VarTokenizeFormatString LIB "OleAut32.dll" _
    ALIAS "VarTokenizeFormatString" ( _
    pstrFormat       AS STRING, _
    BYVAL rgbTok     AS BYTE PTR, _
    BYVAL cbTok      AS LONG, _
    BYVAL iFirstDay  AS LONG, _
    BYVAL iFirstWeek AS LONG, _
    BYVAL lcid       AS DWORD, _  ' LCID
    pcbActual        AS LONG _
    ) AS LONG

'*---------------------------------------------------------------------*
'*                 ITypeLib                                            *
'*---------------------------------------------------------------------*

'typedef /* [unique] */  __RPC_unique_pointer ITypeLib *LPTYPELIB;


'*---------------------------------------------------------------------*
'*                ITypeInfo                                            *
'*---------------------------------------------------------------------*


'MACRO DISPID=LONG
'MACRO MEMBERID=DISPID

%MEMBERID_NIL = %DISPID_UNKNOWN
%ID_DEFAULTINST = -2


' Flags for IDispatch::Invoke
%DISPATCH_METHOD         = &H1
%DISPATCH_PROPERTYGET    = &H2
%DISPATCH_PROPERTYPUT    = &H4
%DISPATCH_PROPERTYPUTREF = &H8

'typedef /* [unique] */  __RPC_unique_pointer ITypeInfo *LPTYPEINFO;


'*---------------------------------------------------------------------*
'*                ITypeComp                                            *
'*---------------------------------------------------------------------*

'typedef /* [unique] */  __RPC_unique_pointer ITypeComp *LPTYPECOMP;


'*---------------------------------------------------------------------*
'*             ICreateTypeLib                                          *
'*---------------------------------------------------------------------*

'typedef ICreateTypeLib * LPCREATETYPELIB;

'typedef ICreateTypeInfo * LPCREATETYPEINFO;

'*---------------------------------------------------------------------*
'*             TypeInfo API                                            *
'*---------------------------------------------------------------------*

' compute a 16bit hash value for the given name
'
#IF %DEF(%WIN32) OR %DEF(%WIN64)
DECLARE FUNCTION LHashValOfNameSysA LIB "OleAut32.dll" _
    ALIAS "LHashValOfNameSysA" ( _
    BYVAL syskind AS SYSKIND_enum, _
    BYVAL lcid    AS DWORD, _  ' LCID
    szName        AS ASCIIZ _
    ) AS DWORD
#ENDIF

DECLARE FUNCTION LHashValOfNameSys LIB "OleAut32.dll" _
    ALIAS "LHashValOfNameSys" ( _
    BYVAL syskind AS SYSKIND_enum, _
    BYVAL lcid    AS DWORD, _  ' LCID
    szName        AS WSTRINGZ _
    ) AS DWORD

MACRO LHashValOfName(lcid, szName)=LHashValOfNameSys(%SYS_WIN32, lcid, szName)

MACRO WHashValOfLHashVal(lhashval)=LO(WORD,lhashval)

MACRO IsHashValCompatible(lhashval1, lhashval2)=(-(&H00ff0000 AND (lhashval1))=(&H00ff0000 AND (lhashval2)))

' load the typelib from the file with the given filename
'
DECLARE FUNCTION LoadTypeLib LIB "OleAut32.dll" ALIAS "LoadTypeLib" ( _
    szFile AS WSTRING, _
    pptlib AS ANY _  ' ITypeLib **
    ) AS LONG

' Control how a type library is registered
'
MACRO REGKIND_enum=LONG
ENUM REGKIND SINGULAR
    REGKIND_DEFAULT
    REGKIND_REGISTER
    REGKIND_NONE
END ENUM


' Constants for specifying format in which TLB should be loaded
' (the default format is 32-bit on WIN32 and 64-bit on WIN64)
%LOAD_TLB_AS_32BIT = &H20
%LOAD_TLB_AS_64BIT = &H40
%MASK_TO_RESET_TLB_BITS = NOT (%LOAD_TLB_AS_32BIT OR %LOAD_TLB_AS_64BIT)

DECLARE FUNCTION LoadTypeLibEx LIB "OleAut32.dll" ALIAS "LoadTypeLibEx" ( _
    szFile        AS STRING, _
    BYVAL regkind AS REGKIND_enum, _
    pptlib        AS ANY _  ' ITypeLib **
    ) AS LONG

' load registered typelib
'
DECLARE FUNCTION LoadRegTypeLib LIB "OleAut32.dll" ALIAS "LoadRegTypeLib" ( _
    rguid           AS GUID, _   ' REFGUID
    BYVAL wVerMajor AS WORD, _
    BYVAL wVerMinor AS WORD, _
    BYVAL lcid      AS DWORD, _  ' LCID
    pptlib          AS ANY _  ' ITypeLib **
    ) AS LONG

' get path to registered typelib
'
DECLARE FUNCTION QueryPathOfRegTypeLib LIB "OleAut32.dll" _
    ALIAS "QueryPathOfRegTypeLib" ( _
    rguid          AS GUID, _   ' REFGUID
    BYVAL wMaj     AS WORD, _
    BYVAL wMin     AS WORD, _
    BYVAL lcid     AS DWORD, _  ' LCID
    lpbstrPathName AS STRING _
    ) AS LONG

' add typelib to registry
'
DECLARE FUNCTION RegisterTypeLib LIB "OleAut32.dll" _
    ALIAS "RegisterTypeLib" ( _
    ptlib      AS ANY, _  ' ITypeLib *
    szFullPath AS STRING, _
    szHelpDir  AS STRING _
    ) AS LONG

' remove typelib from registry
'

DECLARE FUNCTION UnRegisterTypeLib LIB "OleAut32.dll" _
    ALIAS "UnRegisterTypeLib" ( _
    libID           AS GUID, _   ' REFGUID
    BYVAL wVerMajor AS WORD, _
    BYVAL wVerMinor AS WORD, _
    BYVAL lcid      AS DWORD, _  ' LCID
    BYVAL syskind   AS SYSKIND_enum _
    ) AS LONG

' Registers a type library for use by the calling user.
'
DECLARE FUNCTION RegisterTypeLibForUser LIB "OleAut32.dll" _
    ALIAS "RegisterTypeLibForUser" ( _
    ptlib      AS ANY, _  ' ITypeLib *
    szFullPath AS STRING, _
    szHelpDir  AS STRING _
    ) AS LONG

' Removes type library information that was registered by using RegisterTypeLibForUser.
'
DECLARE FUNCTION UnRegisterTypeLibForUser LIB "OleAut32.dll" _
    ALIAS "UnRegisterTypeLibForUser" ( _
    libID              AS GUID, _   ' REFGUID
    BYVAL wMajorVerNum AS WORD, _
    BYVAL wMinorVerNum AS WORD, _
    BYVAL lcid         AS DWORD, _  ' LCID
    BYVAL syskind      AS SYSKIND_enum _
    ) AS LONG

DECLARE FUNCTION CreateTypeLib LIB "OleAut32.dll" ALIAS "CreateTypeLib" ( _
    BYVAL syskind AS SYSKIND_enum, _
    szFile        AS STRING, _
    ppctlib       AS ANY _  ' ICreateTypeLib **
    ) AS LONG

DECLARE FUNCTION CreateTypeLib2 LIB "OleAut32.dll" ALIAS "CreateTypeLib2" ( _
    BYVAL syskind AS SYSKIND_enum, _
    szFile        AS STRING, _
    ppctlib       AS DWORD _  ' ICreateTypeLib2 **
    ) AS LONG


'*---------------------------------------------------------------------*
'*           IDispatch implementation support                          *
'*---------------------------------------------------------------------*

'typedef /* [unique] */  __RPC_unique_pointer IDispatch *LPDISPATCH;

TYPE PARAMDATA
    szName AS STRING PTR   ' parameter name
    vt     AS VARTYPE      ' parameter type
END TYPE

TYPE METHODDATA
    szName   AS STRING PTR    ' method name
    ppdata   AS PARAMDATA PTR ' pointer to an array of PARAMDATAs
    dispid   AS LONG          ' DISPID  ' method ID
    iMeth    AS DWORD         ' method index
    cc       AS CALLCONV_enum ' calling convention
    cArgs    AS DWORD         ' count of arguments
    wFlags   AS WORD          ' same wFlags as on IDispatch::Invoke()
    vtReturn AS VARTYPE
END TYPE

TYPE INTERFACEDATA
    pmethdata AS METHODDATA PTR ' pointer to an array of METHODDATAs
    cMembers  AS DWORD          ' count of members
END TYPE



' Locate the parameter indicated by the given position, and
' return it coerced to the given target VARTYPE (vtTarg).
'
DECLARE FUNCTION DispGetParam LIB "OleAut32.dll" ALIAS "DispGetParam" ( _
    pdispparams    AS DISPPARAMS, _
    BYVAL position AS DWORD, _
    BYVAL vtTarg   AS VARTYPE, _
    pvarResult     AS VARIANT, _
    puArgErr       AS DWORD _
    ) AS LONG

' Automatic TypeInfo driven implementation of IDispatch::GetIDsOfNames()
'
DECLARE FUNCTION DispGetIDsOfNames LIB "OleAut32.dll" _
    ALIAS "DispGetIDsOfNames" ( _
    ptinfo       AS ANY, _   ' ITypeInfo *
    rgszNames    AS ANY, _   ' OLECHAR **
    BYVAL cNames AS DWORD, _
    rgdispid     AS LONG _   ' DISPID *
    ) AS LONG

' Automatic TypeInfo driven implementation of IDispatch::Invoke()
'
DECLARE FUNCTION DispInvoke LIB "OleAut32.dll" ALIAS "DispInvoke" ( _
    vthis              AS ANY, _  ' void *
    ptinfo             AS ANY, _  ' ITypeInfo *
    BYVAL dispidMember AS LONG, _  ' DISPID
    BYVAL wFlags       AS WORD, _
    pparams            AS DISPPARAMS, _
    pvarResult         AS VARIANT, _
    pexcepinfo         AS EXCEPINFO, _
    puArgErr           AS DWORD _
    ) AS LONG

' Construct a TypeInfo from an interface data description
'
DECLARE FUNCTION CreateDispTypeInfo LIB "OleAut32.dll" _
    ALIAS "CreateDispTypeInfo" ( _
    pidata     AS ANY, _    ' INTERFACEDATA *
    BYVAL lcid AS DWORD, _  ' LCID
    pptinfo    AS ANY _     ' ITypeInfo **
    ) AS LONG

' Create an instance of the standard TypeInfo driven IDispatch
' implementation.
'
DECLARE FUNCTION CreateStdDispatch ( _
    punkOuter    AS ANY, _  ' IUnknown *
    pvThis       AS ANY, _  ' void *
    ptinfo       AS ANY, _  ' ITypeInfo *
    ppunkStdDisp AS ANY _   ' IUnknown **
    ) AS LONG

' Low-level helper for IDispatch::Invoke() provides machine independence
' for customized Invoke().
'
DECLARE FUNCTION DispCallFunc LIB "OleAut32.dll" ALIAS "DispCallFunc" ( _
    pvInstance     AS ANY, _  ' void *
    BYVAL oVft     AS DWORD, _
    BYVAL cc       AS CALLCONV_enum, _
    BYVAL vtReturn AS VARTYPE, _
    BYVAL cActuals AS DWORD, _
    prgvt          AS VARTYPE, _
    prgpvarg       AS ANY, _  ' VARIANT **
    pvargResult    AS VARIANT _
    ) AS LONG


'*---------------------------------------------------------------------*
'*            Active Object Registration API                           *
'*---------------------------------------------------------------------*

' flags for RegisterActiveObject
%ACTIVEOBJECT_STRONG = &H0
%ACTIVEOBJECT_WEAK = &H1

DECLARE FUNCTION RegisterActiveObject LIB "OleAut32.dll" _
    ALIAS "RegisterActiveObject" ( _
    punk          AS ANY, _   ' IUnknown *
    rclsid        AS GUID, _  ' REFCLSID
    BYVAL dwFlags AS DWORD, _
    pdwRegister   AS DWORD _
    ) AS LONG

DECLARE FUNCTION RevokeActiveObject LIB "OleAut32.dll" _
    ALIAS "RevokeActiveObject" ( _
    BYVAL dwRegister AS DWORD, _
    pvReserved       AS ANY _  ' void *
    ) AS LONG

DECLARE FUNCTION GetActiveObject LIB "OleAut32.dll" ALIAS "GetActiveObject" ( _
    rclsid     AS GUID, _  ' REFCLSID
    pvReserved AS ANY, _   ' void *
    ppunk      AS ANY _    ' IUnknown **
    ) AS LONG

'*---------------------------------------------------------------------*
'*                           ErrorInfo API                             *
'*---------------------------------------------------------------------*

DECLARE FUNCTION SetErrorInfo LIB "OleAut32.dll" ALIAS "SetErrorInfo" ( _
    BYVAL dwReserved AS DWORD, _
    perrinfo         AS ANY _  ' IErrorInfo *
    ) AS LONG

DECLARE FUNCTION GetErrorInfo LIB "OleAut32.dll" ALIAS "GetErrorInfo" ( _
    BYVAL dwReserved AS DWORD, _
    pperrinfo        AS ANY _  ' IErrorInfo **
    ) AS LONG

DECLARE FUNCTION CreateErrorInfo LIB "OleAut32.dll" ALIAS "CreateErrorInfo" ( _
    pperrinfo AS ANY _  ' ICreateErrorInfo **
    ) AS LONG

'*---------------------------------------------------------------------*
'*           User Defined Data types support                           *
'*---------------------------------------------------------------------*

DECLARE FUNCTION GetRecordInfoFromTypeInfo LIB "OleAut32.dll" _
    ALIAS "GetRecordInfoFromTypeInfo" ( _
    pTypeInfo AS ANY, _  ' ITypeInfo *
    ppRecInfo AS ANY _   ' IRecordInfo **
    ) AS LONG

DECLARE FUNCTION GetRecordInfoFromGuids LIB "OleAut32.dll" _
    ALIAS "GetRecordInfoFromGuids"  ( _
    rGuidTypeLib    AS GUID, _   ' REFGUID
    BYVAL uVerMajor AS DWORD, _
    BYVAL uVerMinor AS DWORD, _
    BYVAL lcid      AS DWORD, _  ' LCID
    rGuidTypeInfo   AS GUID, _   ' REFGUID
    ppRecInfo       AS ANY _     ' IRecordInfo **
    ) AS LONG

'*---------------------------------------------------------------------*
'*                           MISC API                                  *
'*---------------------------------------------------------------------*

DECLARE FUNCTION OaBuildVersion LIB "OleAut32.dll" ALIAS "OaBuildVersion" ( _
    ) AS DWORD

DECLARE SUB ClearCustData LIB "OleAut32.dll" ALIAS "ClearCustData" ( _
    pCustData AS CUSTDATA)

#IF %NTDDI_VERSION >= %NTDDI_VISTASP1
DECLARE SUB OaEnablePerUserTLibRegistration LIB "OleAut32.dll" _
    ALIAS "OaEnablePerUserTLibRegistration" ()
#ENDIF


' Declare variant access functions.

'#if %STDC OR %def(%NONAMELESSUNION)
'#define V_UNION(X, Y)   ((X)->n1.n2.n3.Y)
'#define V_VT(X)         ((X)->n1.n2.vt)
'#define V_RECORDINFO(X) ((X)->n1.n2.n3.brecVal.pRecInfo)
'#define V_RECORD(X)     ((X)->n1.n2.n3.brecVal.pvRecord)
'#else
'#define V_UNION(X, Y)   ((X)->Y)
'#define V_VT(X)         ((X)->vt)
'#define V_RECORDINFO(X) ((X)->pRecInfo)
'#define V_RECORD(X)     ((X)->pvRecord)
'#endif

' Variant access macros
'
'#define V_ISBYREF(X)     (V_VT(X)&VT_BYREF)
'#define V_ISARRAY(X)     (V_VT(X)&VT_ARRAY)
'#define V_ISVECTOR(X)    (V_VT(X)&VT_VECTOR)
'#define V_NONE(X)        V_I2(X)

'#define V_UI1(X)         V_UNION(X, bVal)
'#define V_UI1REF(X)      V_UNION(X, pbVal)
'#define V_I2(X)          V_UNION(X, iVal)
'#define V_I2REF(X)       V_UNION(X, piVal)
'#define V_I4(X)          V_UNION(X, lVal)
'#define V_I4REF(X)       V_UNION(X, plVal)
'#define V_I8(X)          V_UNION(X, llVal)
'#define V_I8REF(X)       V_UNION(X, pllVal)
'#define V_R4(X)          V_UNION(X, fltVal)
'#define V_R4REF(X)       V_UNION(X, pfltVal)
'#define V_R8(X)          V_UNION(X, dblVal)
'#define V_R8REF(X)       V_UNION(X, pdblVal)
'#define V_I1(X)          V_UNION(X, cVal)
'#define V_I1REF(X)       V_UNION(X, pcVal)
'#define V_UI2(X)         V_UNION(X, uiVal)
'#define V_UI2REF(X)      V_UNION(X, puiVal)
'#define V_UI4(X)         V_UNION(X, ulVal)
'#define V_UI4REF(X)      V_UNION(X, pulVal)
'#define V_UI8(X)         V_UNION(X, ullVal)
'#define V_UI8REF(X)      V_UNION(X, pullVal)
'#define V_INT(X)         V_UNION(X, intVal)
'#define V_INTREF(X)      V_UNION(X, pintVal)
'#define V_UINT(X)        V_UNION(X, uintVal)
'#define V_UINTREF(X)     V_UNION(X, puintVal)

'#if %def(%WIN64)
'#define V_INT_PTR(X)        V_UNION(X, llVal)
'#define V_UINT_PTR(X)       V_UNION(X, ullVal)
'#define V_INT_PTRREF(X)     V_UNION(X, pllVal)
'#define V_UINT_PTRREF(X)    V_UNION(X, pullVal)
'#else
'#define V_INT_PTR(X)        V_UNION(X, lVal)
'#define V_UINT_PTR(X)       V_UNION(X, ulVal)
'#define V_INT_PTRREF(X)     V_UNION(X, plVal)
'#define V_UINT_PTRREF(X)    V_UNION(X, pulVal)
'#endif

'#define V_CY(X)          V_UNION(X, cyVal)
'#define V_CYREF(X)       V_UNION(X, pcyVal)
'#define V_DATE(X)        V_UNION(X, date)
'#define V_DATEREF(X)     V_UNION(X, pdate)
'#define V_BSTR(X)        V_UNION(X, bstrVal)
'#define V_BSTRREF(X)     V_UNION(X, pbstrVal)
'#define V_DISPATCH(X)    V_UNION(X, pdispVal)
'#define V_DISPATCHREF(X) V_UNION(X, ppdispVal)
'#define V_ERROR(X)       V_UNION(X, scode)
'#define V_ERRORREF(X)    V_UNION(X, pscode)
'#define V_BOOL(X)        V_UNION(X, boolVal)
'#define V_BOOLREF(X)     V_UNION(X, pboolVal)
'#define V_UNKNOWN(X)     V_UNION(X, punkVal)
'#define V_UNKNOWNREF(X)  V_UNION(X, ppunkVal)
'#define V_VARIANTREF(X)  V_UNION(X, pvarVal)
'#define V_ARRAY(X)       V_UNION(X, parray)
'#define V_ARRAYREF(X)    V_UNION(X, pparray)
'#define V_BYREF(X)       V_UNION(X, byref)

'#define V_DECIMAL(X)     V_UNION(X, decVal)
'#define V_DECIMALREF(X)  V_UNION(X, pdecVal)
