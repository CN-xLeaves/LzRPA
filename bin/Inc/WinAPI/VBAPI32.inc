'==============================================================================
'
'  VBAPI32.INC -- Visual Basic 32-bit API for PowerBASIC Windows compilers
'
'  Copyright (C) 1997-2011 PowerBASIC, Inc.
'  Some portions Copyright (C) Microsoft Corporation
'  All Rights Reserved.
'
'  Last Update: 17 Mar 2011
'
'==============================================================================


#INCLUDE THIS ONCE

#INCLUDE "OleAuto.inc"


'------------------------------------------------------------------------------
' vbArrayRedim - Redimension the upper bound of a single dimension VB array.
'                The array will retain any existing data.
'
FUNCTION vbArrayRedim (BYVAL psa AS DWORD, BYVAL Elems AS LONG) AS LONG

    LOCAL Result AS LONG
    LOCAL b      AS SAFEARRAYBOUND

    ' Must be a single dimension array.
    IF SafeArrayGetDim(BYVAL psa) <> 1 THEN
        EXIT FUNCTION
    END IF

    ' Get the LBOUND of the array.
    IF SafeArrayGetlBound(BYVAL psa, 1, b.lLbound) <> %S_OK THEN
        EXIT FUNCTION
    END IF

    ' Resize it.
    b.cElements = Elems

    ' Redimension the array to the new size.
    Result = SafeArrayRedim(BYVAL psa, b)

    ' Return TRUE for success, or FALSE for failure.
    FUNCTION = (Result = %S_OK)

END FUNCTION



'------------------------------------------------------------------------------
' vbArrayLBound - Return the LBOUND of a Visual Basic array
'
FUNCTION vbArrayLBound (BYVAL psa AS DWORD, BYVAL nDim AS INTEGER) AS LONG

    LOCAL bound AS LONG

    IF SafeArrayGetLBound(BYVAL psa, nDim, bound) = %S_OK THEN
        FUNCTION = bound
    END IF

END FUNCTION



'------------------------------------------------------------------------------
' vbArrayUBound - Return the UBOUND of a Visual Basic array
'
FUNCTION vbArrayUBound (BYVAL psa AS DWORD, BYVAL nDim AS INTEGER) AS LONG

    LOCAL bound AS LONG

    IF SafeArrayGetUBound(BYVAL psa, nDim, bound) = %S_OK THEN
        FUNCTION = bound
    END IF

END FUNCTION



'------------------------------------------------------------------------------
' vbArrayFirstElem - Return the address of the first element in a VB array.
'
FUNCTION vbArrayFirstElem (BYVAL psa AS DWORD) AS DWORD

    LOCAL sa AS SAFEARRAY PTR

    sa = psa

    FUNCTION = @sa.pvData

END FUNCTION



'------------------------------------------------------------------------------
' Convert a dynamic string from ASCII/ANSI to Unicode
'
' Note:  When VB passes a dynamic string to a DLL, it automatically converts
'        the string from Unicode to ANSI.  However, strings inside of
'        user-defined types are not converted by VB.
'
MACRO StrToUnicode(x)=UCODE$(x)+$$NUL



'------------------------------------------------------------------------------
' Convert a unicode buffer to an ANSI string
'
MACRO UnicodeToStr(pBuff,ncBuff)=RTRIM$(ACODE$(PEEK$(pBuff,ncBuff)),$NUL)



'------------------------------------------------------------------------------
' vb2DArrayRedim - Redimension the upper bound of a dual-dimension VB array.
'                The array will retain any existing data.
'
FUNCTION vb2DArrayRedim (BYVAL psa AS DWORD, BYVAL Elems AS LONG) AS LONG

    LOCAL Result AS LONG
    LOCAL b      AS SAFEARRAYBOUND

    ' Must be a dual-dimension array.
    IF SafeArrayGetDim(BYVAL psa) <> 2 THEN
        EXIT FUNCTION
    END IF

    ' Get the LBOUND of the array.
    Result = SafeArrayGetLBound(BYVAL psa, 2, b.lLbound)
    IF Result <> %S_OK THEN
        EXIT FUNCTION
    END IF

    ' Resize it.
    b.cElements = Elems

    ' Redimension the array to the new size.
    Result = SafeArrayRedim(BYVAL psa, b)

    ' Return TRUE for success, or FALSE for failure.
    FUNCTION = (Result = %S_OK)

END FUNCTION
