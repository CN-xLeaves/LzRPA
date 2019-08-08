'------------------------------------------------------------------------------
'
'  ShlWApi.inc -- Interface for the Windows light-weight utility APIs
'
'  Copyright (c) 2002-2011 PowerBASIC, Inc.
'  Portions Copyright (c) 1991-1998 Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from shlwapi.h version 1.0 of 14 Jul 2009
'------------------------------------------------------------------------------


#INCLUDE THIS ONCE

%INC_SHLWAPI = 1

#IF NOT %DEF(%NOSHLWAPI)

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "ObjBase.inc"
#INCLUDE "ShTypes.inc"

'
' Users of this header may define any number of these constants to avoid
' the definitions of each functional group.
'
'    %NO_SHLWAPI_STRFCNS    String functions
'    %NO_SHLWAPI_PATH       Path functions
'    %NO_SHLWAPI_REG        Registry functions
'    %NO_SHLWAPI_STREAM     Stream functions
'    %NO_SHLWAPI_GDI        GDI helper functions

#IF NOT %DEF(%NO_SHLWAPI_STRFCNS)

'=============== String Routines ===================================

DECLARE FUNCTION StrChrA LIB "ShlWApi.dll" ALIAS "StrChrA" _
    (lpStart AS ASCIIZ, BYVAL wMatch AS WORD) AS DWORD

DECLARE FUNCTION StrChrW LIB "ShlWApi.dll" ALIAS "StrChrW" _
    (lpStart AS WSTRINGZ, BYVAL wMatch AS WORD) AS DWORD

DECLARE FUNCTION StrChrIA LIB "ShlWApi.dll" ALIAS "StrChrIA" _
    (lpStart AS ASCIIZ, BYVAL wMatch AS WORD) AS DWORD

DECLARE FUNCTION StrChrIW LIB "ShlWApi.dll" ALIAS "StrChrIW" _
    (lpStart AS WSTRINGZ, BYVAL wMatch AS WORD) AS DWORD

#IF (%WIN32_IE >= %WIN32_IE_IE60)

DECLARE FUNCTION StrChrNW LIB "ShlWApi.dll" ALIAS "StrChrNW" _
    (lpStart AS WSTRINGZ, BYVAL wMatch AS WORD, BYVAL cchMax AS DWORD) AS DWORD

DECLARE FUNCTION StrChrNIW LIB "ShlWApi.dll" ALIAS "StrChrNIW" _
    (lpStart AS WSTRINGZ, BYVAL wMatch AS WORD, BYVAL cchMax AS DWORD) AS DWORD

#ENDIF ' %WIN32_IE_IE60

DECLARE FUNCTION StrCmpNA LIB "ShlWApi.dll" ALIAS "StrCmpNA" _
    (lpStr1 AS ASCIIZ, lpStr2 AS ASCIIZ, BYVAL nChar AS LONG) AS LONG

DECLARE FUNCTION StrCmpNW LIB "ShlWApi.dll" ALIAS "StrCmpNW" _
    (lpStr1 AS WSTRINGZ, lpStr2 AS WSTRINGZ, BYVAL nChar AS LONG) AS LONG

DECLARE FUNCTION StrCmpNIA LIB "ShlWApi.dll" ALIAS "StrCmpNIA" _
    (lpStr1 AS ASCIIZ, lpStr2 AS ASCIIZ, BYVAL nChar AS LONG) AS LONG

DECLARE FUNCTION StrCmpNIW LIB "ShlWApi.dll" ALIAS "StrCmpNIW" _
    (lpStr1 AS WSTRINGZ, lpStr2 AS WSTRINGZ, BYVAL nChar AS LONG) AS LONG

DECLARE FUNCTION StrCSpnA LIB "ShlWApi.dll" ALIAS "StrCSpnA" _
    (lpsz AS ASCIIZ, lpSet AS ASCIIZ) AS LONG

DECLARE FUNCTION StrCSpnW LIB "ShlWApi.dll" ALIAS "StrCSpnW" _
    (lpsz AS WSTRINGZ, lpSet AS WSTRINGZ) AS LONG

DECLARE FUNCTION StrCSpnIA LIB "ShlWApi.dll" ALIAS "StrCSpnIA" _
    (lpsz AS ASCIIZ, lpSet AS ASCIIZ) AS LONG

DECLARE FUNCTION StrCSpnIW LIB "ShlWApi.dll" ALIAS "StrCSpnIW" _
    (lpsz AS WSTRINGZ, lpSet AS WSTRINGZ) AS LONG

DECLARE FUNCTION StrDupA LIB "ShlWApi.dll" ALIAS "StrDupA" _
    (lpSrch AS ASCIIZ) AS DWORD

DECLARE FUNCTION StrDupW LIB "ShlWApi.dll" ALIAS "StrDupW" _
    (lpSrch AS WSTRINGZ) AS DWORD

' StrFormatByteSizeEx takes a ULONGLONG as a byte count and formats a string
' representing that number of bytes in an appropriately concise manner, where
' "appropriate manner" is determine by several factors:
'
' 1) order - is this most appropriately expressed as KB? MB? GB?
'    for example: 1039 -> "1.01 KB", 5454608466 -> "5.08 GB", etc
'
' 2) number of whole number places shown - if there are more than a few whole
'    number places to display, decimal places are omitted.
'    for example: 1024 -> "1.00 KB", 12288 -> "12.0 KB", 125952 -> "123 KB"
'
' 3) the caller can specify whether the result should involve rounding to the
'    nearest displayed digit, or truncation of undisplayed digits. the caller
'    must specify either rounding or truncation when calling the API.
'    for example: with rounding,   2147483647 -> "2.00 GB"
'                 with truncation, 2147483647 -> "1.99 GB"

MACRO SFBS_FLAGS_enum=LONG
ENUM SFBS_FLAGS BITS SINGULAR
    SFBS_FLAGS_ROUND_TO_NEAREST_DISPLAYED_DIGIT = 1  ' round to the nearest displayed digit
    SFBS_FLAGS_TRUNCATE_UNDISPLAYED_DECIMAL_DIGITS   ' discard undisplayed digits
END ENUM


DECLARE FUNCTION StrFormatByteSizeEx LIB "ShlWApi.dll" _
    ALIAS "StrFormatByteSizeEx" (BYVAL flags AS SFBS_FLAGS_enum, _
    pszBuf AS WSTRINGZ, BYVAL cchBuf AS DWORD) AS LONG

DECLARE FUNCTION StrFormatByteSizeA LIB "ShlWApi.dll" _
    ALIAS "StrFormatByteSizeA" (BYVAL dwd AS DWORD, szBuf AS ASCIIZ, _
    BYVAL uiBufSize AS DWORD) AS DWORD

DECLARE FUNCTION StrFormatByteSize64A LIB "ShlWApi.dll" _
    ALIAS "StrFormatByteSize64A" (BYVAL qdw AS QUAD, szBuf AS ASCIIZ, _
    BYVAL uiBufSize AS DWORD) AS DWORD

DECLARE FUNCTION StrFormatByteSizeW LIB "ShlWApi.dll" _
    ALIAS "StrFormatByteSizeW" (BYVAL dwd AS DWORD, szBuf AS WSTRINGZ, _
    BYVAL uiBufSize AS DWORD) AS DWORD

DECLARE FUNCTION StrFormatKBSizeW LIB "ShlWApi.dll" ALIAS "StrFormatKBSizeW" _
    (BYVAL qdw AS QUAD, pszBuf AS WSTRINGZ, BYVAL cchBuf AS DWORD) AS DWORD

DECLARE FUNCTION StrFormatKBSizeA LIB "ShlWApi.dll" ALIAS "StrFormatKBSizeA" _
    (BYVAL qdw AS QUAD, pszBuf AS ASCIIZ, BYVAL cchBuf AS DWORD) AS DWORD

DECLARE FUNCTION StrFromTimeIntervalA LIB "ShlWApi.dll" _
    ALIAS "StrFromTimeIntervalA" (pszOut AS ASCIIZ, BYVAL cchMax AS DWORD, _
    BYVAL dwTimeMS AS DWORD, BYVAL digits AS LONG) AS LONG

DECLARE FUNCTION StrFromTimeIntervalW LIB "ShlWApi.dll" _
    ALIAS "StrFromTimeIntervalW" (pszOut AS WSTRINGZ, BYVAL cchMax AS DWORD, _
    BYVAL dwTimeMS AS DWORD, BYVAL digits AS LONG) AS LONG

DECLARE FUNCTION StrIsIntlEqualA LIB "ShlWApi.dll" ALIAS "StrIsIntlEqualA" _
    (BYVAL fCaseSense AS LONG, lpString1 AS ASCIIZ, lpString2 AS ASCIIZ, _
    BYVAL nChar AS LONG) AS LONG

DECLARE FUNCTION StrIsIntlEqualW LIB "ShlWApi.dll" ALIAS "StrIsIntlEqualW" _
    (BYVAL fCaseSense AS LONG, lpString1 AS WSTRINGZ, lpString2 AS WSTRINGZ, _
    BYVAL nChar AS LONG) AS LONG

DECLARE FUNCTION StrNCatA LIB "ShlWApi.dll" ALIAS "StrNCatA" _
    (psz1 AS ASCIIZ, psz2 AS ASCIIZ, BYVAL cchMax AS LONG) AS DWORD

DECLARE FUNCTION StrNCatW LIB "ShlWApi.dll" ALIAS "StrNCatW" _
    (psz1 AS WSTRINGZ, psz2 AS WSTRINGZ, BYVAL cchMax AS LONG) AS DWORD

DECLARE FUNCTION StrPBrkA LIB "ShlWApi.dll" ALIAS "StrPBrkA" _
    (psz AS ASCIIZ, pszSet AS ASCIIZ) AS DWORD

DECLARE FUNCTION StrPBrkW LIB "ShlWApi.dll" ALIAS "StrPBrkW" _
    (psz AS WSTRINGZ, pszSet AS WSTRINGZ) AS DWORD

DECLARE FUNCTION StrRChrA LIB "ShlWApi.dll" ALIAS "StrRChrA" _
    (lpStart AS ASCIIZ, lpEnd AS ASCIIZ, BYVAL wMatch AS WORD) AS DWORD

DECLARE FUNCTION StrRChrW LIB "ShlWApi.dll" ALIAS "StrRChrW" _
    (lpStart AS WSTRINGZ, lpEnd AS WSTRINGZ, BYVAL wMatch AS WORD) AS DWORD

DECLARE FUNCTION StrRChrIA LIB "ShlWApi.dll" ALIAS "StrRChrIA" _
    (lpStart AS ASCIIZ, lpEnd AS ASCIIZ, BYVAL wMatch AS WORD) AS DWORD

DECLARE FUNCTION StrRChrIW LIB "ShlWApi.dll" ALIAS "StrRChrIW" _
    (lpStart AS WSTRINGZ, lpEnd AS WSTRINGZ, BYVAL wMatch AS WORD) AS DWORD

DECLARE FUNCTION StrRStrIA LIB "ShlWApi.dll" ALIAS "StrRStrIA" _
    (lpSource AS ASCIIZ, lpLast AS ASCIIZ, lpSrch AS ASCIIZ) AS DWORD

DECLARE FUNCTION StrRStrIW LIB "ShlWApi.dll" ALIAS "StrRStrIW" _
    (lpSource AS WSTRINGZ, lpLast AS WSTRINGZ, lpSrch AS WSTRINGZ) AS DWORD

DECLARE FUNCTION StrSpnA LIB "ShlWApi.dll" ALIAS "StrSpnA" _
    (psz AS ASCIIZ, pszSet AS ASCIIZ) AS LONG

DECLARE FUNCTION StrSpnW LIB "ShlWApi.dll" ALIAS "StrSpnW" _
    (psz AS WSTRINGZ, pszSet AS WSTRINGZ) AS LONG

DECLARE FUNCTION StrStrA LIB "ShlWApi.dll" ALIAS "StrStrA" _
    (lpFirst AS ASCIIZ, lpSrch AS ASCIIZ) AS DWORD

DECLARE FUNCTION StrStrW LIB "ShlWApi.dll" ALIAS "StrStrW" _
    (lpFirst AS WSTRINGZ, lpSrch AS WSTRINGZ) AS DWORD

DECLARE FUNCTION StrStrIA LIB "ShlWApi.dll" ALIAS "StrStrIA" _
    (lpFirst AS ASCIIZ, lpSrch AS ASCIIZ) AS DWORD

DECLARE FUNCTION StrStrIW LIB "ShlWApi.dll" ALIAS "StrStrIW" _
    (lpFirst AS WSTRINGZ, lpSrch AS WSTRINGZ) AS DWORD

#IF (%WIN32_IE >= %WIN32_IE_IE60)

DECLARE FUNCTION StrStrNW LIB "ShlWApi.dll" ALIAS "StrStrNW" _
    (lpFirst AS WSTRINGZ, lpSrch AS WSTRINGZ, BYVAL cchMax AS DWORD) AS DWORD

DECLARE FUNCTION StrStrNIW LIB "ShlWApi.dll" ALIAS "StrStrNIW" _
    (lpFirst AS WSTRINGZ, lpSrch AS WSTRINGZ, BYVAL cchMax AS DWORD) AS DWORD

#ENDIF ' %WIN32_IE_IE60

MACRO STIF_FLAGS_enum=LONG
ENUM STIF_FLAGS SINGULAR
    STIF_DEFAULT
    STIF_SUPPORT_HEX
END ENUM

DECLARE FUNCTION StrToIntA LIB "ShlWApi.dll" ALIAS "StrToIntA" _
    (lpSrc AS ASCIIZ) AS LONG

DECLARE FUNCTION StrToIntW LIB "ShlWApi.dll" ALIAS "StrToIntW" _
    (lpSrc AS WSTRINGZ) AS LONG

DECLARE FUNCTION StrToIntExA LIB "ShlWApi.dll" ALIAS "StrToIntExA" _
    (pszString AS ASCIIZ, BYVAL nFlags AS STIF_FLAGS_enum, piRet AS LONG) _
    AS LONG

DECLARE FUNCTION StrToIntExW LIB "ShlWApi.dll" ALIAS "StrToIntExW" _
    (pszString AS WSTRINGZ, BYVAL nFlags AS STIF_FLAGS_enum, piRet AS LONG) _
    AS LONG

#IF (%WIN32_IE >= %WIN32_IE_IE60)

DECLARE FUNCTION StrToInt64ExA LIB "ShlWApi.dll" ALIAS "StrToInt64ExA" _
    (pszString AS ASCIIZ, BYVAL nFlags AS STIF_FLAGS_enum, pllRet AS QUAD) _
    AS LONG

DECLARE FUNCTION StrToInt64ExW LIB "ShlWApi.dll" ALIAS "StrToInt64ExW" _
    (pszString AS WSTRINGZ, BYVAL nFlags AS STIF_FLAGS_enum, pllRet AS QUAD) _
    AS LONG

#ENDIF ' %WIN32_IE_IE60

DECLARE FUNCTION StrTrimA LIB "ShlWApi.dll" ALIAS "StrTrimA" _
    (psz AS ASCIIZ, pszTrimChars AS ASCIIZ) AS LONG

DECLARE FUNCTION StrTrimW LIB "ShlWApi.dll" ALIAS "StrTrimW" _
    (psz AS WSTRINGZ, pszTrimChars AS WSTRINGZ) AS LONG

DECLARE FUNCTION StrCatW LIB "ShlWApi.dll" ALIAS "StrCatW" _
    (psz1 AS WSTRINGZ, psz2 AS WSTRINGZ) AS DWORD

DECLARE FUNCTION StrCmpW LIB "ShlWApi.dll" ALIAS "StrCmpW" _
    (psz1 AS WSTRINGZ, psz2 AS WSTRINGZ) AS LONG

DECLARE FUNCTION StrCmpIW LIB "ShlWApi.dll" ALIAS "StrCmpIW" _
    (psz1 AS WSTRINGZ, psz2 AS WSTRINGZ) AS LONG

DECLARE FUNCTION StrCpyW LIB "ShlWApi.dll" ALIAS "StrCpyW" _
    (psz1 AS WSTRINGZ, psz2 AS WSTRINGZ) AS DWORD

DECLARE FUNCTION StrCpyNW LIB "ShlWApi.dll" ALIAS "StrCpyNW" _
    (psz1 AS WSTRINGZ, psz2 AS WSTRINGZ, BYVAL cchMax AS LONG) AS DWORD

DECLARE FUNCTION StrCatBuffW LIB "ShlWApi.dll" ALIAS "StrCatBuffW" _
    (pszDest AS WSTRINGZ, pszSrc AS WSTRINGZ, BYVAL cchDestBuffSize AS LONG) _
    AS DWORD

DECLARE FUNCTION StrCatBuffA LIB "ShlWApi.dll" ALIAS "StrCatBuffA" _
    (pszDest AS ASCIIZ, pszSrc AS ASCIIZ, BYVAL cchDestBuffSize AS LONG) _
    AS DWORD

DECLARE FUNCTION ChrCmpIA LIB "ShlWApi.dll" ALIAS "ChrCmpIA" _
    (BYVAL w1 AS WORD, BYVAL w2 AS WORD) AS LONG

DECLARE FUNCTION ChrCmpIW LIB "ShlWApi.dll" ALIAS "ChrCmpIW" _
    (BYVAL w1 AS WORD, BYVAL w2 AS WORD) AS LONG

'LWSTDAPI_(int)      wvnsprintfA(__out_ecount(cchLimitIn) LPSTR lpOut, int cchLimitIn, LPCSTR lpFmt, va_list arglist);
'LWSTDAPI_(int)      wvnsprintfW(__out_ecount(cchLimitIn) LPWSTR lpOut, int cchLimitIn, LPCWSTR lpFmt, va_list arglist);
'LWSTDAPIV_(int)     wnsprintfA(__out_ecount(cchLimitIn) LPSTR lpOut, int cchLimitIn, LPCSTR lpFmt, ...);
'LWSTDAPIV_(int)     wnsprintfW(__out_ecount(cchLimitIn) LPWSTR lpOut, int cchLimitIn, LPCWSTR lpFmt, ...);

MACRO StrIntlEqNA( s1, s2, nChar)=StrIsIntlEqualA( %TRUE, s1, s2, nChar)
MACRO StrIntlEqNW( s1, s2, nChar)=StrIsIntlEqualW( %TRUE, s1, s2, nChar)
MACRO StrIntlEqNIA(s1, s2, nChar)=StrIsIntlEqualA(%FALSE, s1, s2, nChar)
MACRO StrIntlEqNIW(s1, s2, nChar)=StrIsIntlEqualW(%FALSE, s1, s2, nChar)

DECLARE FUNCTION StrRetToStrA LIB "ShlWApi.dll" ALIAS "StrRetToStrA" _
    (BYVAL pstr AS STRRET PTR, pidl AS ITEMID_CHILD, ppsz AS ANY) AS LONG

DECLARE FUNCTION StrRetToStrW LIB "ShlWApi.dll" ALIAS "StrRetToStrW" _
    (BYVAL pstr AS STRRET PTR, pidl AS ITEMID_CHILD, ppsz AS ANY) AS LONG

#IF %DEF(%UNICODE)
MACRO StrRetToStr=StrRetToStrW
#ELSE
MACRO StrRetToStr=StrRetToStrA
#ENDIF ' NOT %UNICODE

' helper to duplicate a string using the task allocator

DECLARE FUNCTION SHStrDupA LIB "ShlWApi.dll" ALIAS "SHStrDupA" _
    (psz AS ASCIIZ, ppwsz AS ANY) AS LONG

DECLARE FUNCTION SHStrDupW LIB "ShlWApi.dll" ALIAS "SHStrDupW" _
    (psz AS WSTRINGZ, ppwsz AS ANY) AS LONG

#IF %DEF(%UNICODE)
MACRO SHStrDup=SHStrDupW
#ELSE
MACRO SHStrDup=SHStrDupA
#ENDIF ' NOT %UNICODE

#IF (%WIN32_IE >= %WIN32_IE_IE55)

DECLARE FUNCTION StrCmpLogicalW LIB "ShlWApi.dll" ALIAS "StrCmpLogicalW" _
    (psz1 AS WSTRINGZ, psz2 AS WSTRINGZ) AS LONG

DECLARE FUNCTION StrCatChainW LIB "ShlWApi.dll" ALIAS "StrCatChainW" _
    (pszDst AS WSTRINGZ, BYVAL ccDst AS DWORD, BYVAL ichAt AS DWORD, _
    pszSrc AS WSTRINGZ) AS DWORD

DECLARE FUNCTION StrRetToBSTR LIB "ShlWApi.dll" ALIAS "StrRetToBSTR" _
    (BYVAL pstr AS STRRET PTR, pidl AS ITEMID_CHILD, pbstr AS ANY) AS LONG

DECLARE FUNCTION SHLoadIndirectString LIB "ShlWApi.dll" _
    ALIAS "SHLoadIndirectString" (pszSource AS WSTRINGZ, _
    pszOutBuf AS WSTRINGZ, BYVAL cchOutBuf AS DWORD, ppvReserved AS ANY) _
    AS LONG

#ENDIF ' %WIN32_IE_IE55


#IF (%WIN32_IE >= %WIN32_IE_IE60SP2)

DECLARE FUNCTION IsCharSpaceA LIB "ShlWApi.dll" ALIAS "IsCharSpaceA" _
    (BYVAL wch AS BYTE) AS LONG

DECLARE FUNCTION IsCharSpaceW LIB "ShlWApi.dll" ALIAS "IsCharSpaceW" _
    (BYVAL wch AS WORD) AS LONG

#IF %DEF(%UNICODE)
MACRO IsCharSpace=IsCharSpaceW
#ELSE
MACRO IsCharSpace=IsCharSpaceA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION StrCmpCA LIB "ShlWApi.dll" ALIAS "StrCmpCA" _
    (pszStr1 AS ASCIIZ, pszStr2 AS ASCIIZ) AS LONG

DECLARE FUNCTION StrCmpCW LIB "ShlWApi.dll" ALIAS "StrCmpCW" _
    (pszStr1 AS WSTRINGZ, pszStr2 AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO StrCmpC=StrCmpCW
#ELSE
MACRO StrCmpC=StrCmpCA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION StrCmpICA LIB "ShlWApi.dll" ALIAS "StrCmpICA" _
    (pszStr1 AS ASCIIZ, pszStr2 AS ASCIIZ) AS LONG

DECLARE FUNCTION StrCmpICW LIB "ShlWApi.dll" ALIAS "StrCmpICW" _
    (pszStr1 AS WSTRINGZ, pszStr2 AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO StrCmpIC=StrCmpICW
#ELSE
MACRO StrCmpIC=StrCmpICA
#ENDIF ' NOT %UNICODE

#ENDIF ' %WIN32_IE_IE60SP2

#IF %DEF(%UNICODE)
MACRO StrChr              = StrChrW
MACRO StrRChr             = StrRChrW
MACRO StrChrI             = StrChrIW
MACRO StrRChrI            = StrRChrIW
MACRO StrCmpN             = StrCmpNW
MACRO StrCmpNI            = StrCmpNIW
MACRO StrStr              = StrStrW
MACRO StrStrI             = StrStrIW
MACRO StrDup              = StrDupW
MACRO StrRStrI            = StrRStrIW
MACRO StrCSpn             = StrCSpnW
MACRO StrCSpnI            = StrCSpnIW
MACRO StrSpn              = StrSpnW
MACRO StrToInt            = StrToIntW
MACRO StrPBrk             = StrPBrkW
MACRO StrToIntEx          = StrToIntExW
#IF (%WIN32_IE >= &H0600)
MACRO StrToInt64Ex        = StrToInt64ExW
#ENDIF
MACRO StrFromTimeInterval = StrFromTimeIntervalW
MACRO StrIntlEqN          = StrIntlEqNW
MACRO StrIntlEqNI         = StrIntlEqNIW
MACRO StrFormatByteSize   = StrFormatByteSizeW
MACRO StrFormatByteSize64 = StrFormatByteSizeW
MACRO StrFormatKBSize     = StrFormatKBSizeW
MACRO StrNCat             = StrNCatW
MACRO StrTrim             = StrTrimW
MACRO StrCatBuff          = StrCatBuffW
MACRO ChrCmpI             = ChrCmpIW
MACRO wvnsprintf          = wvnsprintfW
MACRO wnsprintf           = wnsprintfW
MACRO StrIsIntlEqual      = StrIsIntlEqualW

#ELSE

MACRO StrChr              = StrChrA
MACRO StrRChr             = StrRChrA
MACRO StrChrI             = StrChrIA
MACRO StrRChrI            = StrRChrIA
MACRO StrCmpN             = StrCmpNA
MACRO StrCmpNI            = StrCmpNIA
MACRO StrStr              = StrStrA
MACRO StrStrI             = StrStrIA
MACRO StrDup              = StrDupA
MACRO StrRStrI            = StrRStrIA
MACRO StrCSpn             = StrCSpnA
MACRO StrCSpnI            = StrCSpnIA
MACRO StrSpn              = StrSpnA
MACRO StrToInt            = StrToIntA
MACRO StrPBrk             = StrPBrkA
MACRO StrToIntEx          = StrToIntExA
#IF (%WIN32_IE >= &H0600)
MACRO StrToInt64Ex        = StrToInt64ExA
#ENDIF
MACRO StrFromTimeInterval = StrFromTimeIntervalA
MACRO StrIntlEqN          = StrIntlEqNA
MACRO StrIntlEqNI         = StrIntlEqNIA
MACRO StrFormatByteSize   = StrFormatByteSizeA
MACRO StrFormatByteSize64 = StrFormatByteSize64A
MACRO StrFormatKBSize     = StrFormatKBSizeA
MACRO StrNCat             = StrNCatA
MACRO StrTrim             = StrTrimA
MACRO StrCatBuff          = StrCatBuffA
MACRO ChrCmpI             = ChrCmpIA
MACRO wvnsprintf          = wvnsprintfA
MACRO wnsprintf           = wnsprintfA
MACRO StrIsIntlEqual      = StrIsIntlEqualA
#ENDIF

#IF (%WIN32_IE >= %WIN32_IE_IE50)

' StrCmp*C* - Compare strings using C runtime collation rules.
DECLARE FUNCTION StrCmpNCA LIB "ShlWApi.dll" ALIAS "StrCmpNCA" _
    (lpStr1 AS ASCIIZ, lpStr2 AS ASCIIZ, BYVAL nChar AS LONG) AS LONG

' StrCmp*C* - Compare strings using C runtime collation rules.
DECLARE FUNCTION StrCmpNCW LIB "ShlWApi.dll" ALIAS "StrCmpNCW" _
    (lpStr1 AS WSTRINGZ, lpStr2 AS WSTRINGZ, BYVAL nChar AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO StrCmpNC=StrCmpNCW
#ELSE
MACRO StrCmpNC=StrCmpNCA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION StrCmpNICA LIB "ShlWApi.dll" ALIAS "StrCmpNICA" _
    (lpStr1 AS ASCIIZ, lpStr2 AS ASCIIZ, BYVAL nChar AS LONG, _
    BYVAL nChar AS LONG) AS LONG

DECLARE FUNCTION StrCmpNICW LIB "ShlWApi.dll" ALIAS "StrCmpNICW" _
    (lpStr1 AS WSTRINGZ, lpStr2 AS WSTRINGZ, BYVAL nChar AS LONG, _
    BYVAL nChar AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO StrCmpNIC=StrCmpNICW
#ELSE
MACRO StrCmpNIC=StrCmpNICA
#ENDIF ' NOT %UNICODE

#ENDIF  ' %WIN32_IE_IE50


' Backward compatible to NT's non-standard naming (strictly
' for comctl32)
'
DECLARE FUNCTION IntlStrEqWorkerA LIB "ShlWApi.dll" ALIAS "IntlStrEqWorkerA" _
    (BYVAL fCaseSens AS LONG, lpString1 AS ASCIIZ, lpString2 AS ASCIIZ, _
    BYVAL nChar AS LONG) AS LONG

DECLARE FUNCTION IntlStrEqWorkerW LIB "ShlWApi.dll" ALIAS "IntlStrEqWorkerW" _
    (BYVAL fCaseSens AS LONG, lpString1 AS WSTRINGZ, lpString2 AS WSTRINGZ, _
    BYVAL nChar AS LONG) AS LONG

MACRO IntlStrEqNA( s1, s2, nChar)=IntlStrEqWorkerA( %TRUE, s1, s2, nChar)
MACRO IntlStrEqNW( s1, s2, nChar)=IntlStrEqWorkerW( %TRUE, s1, s2, nChar)
MACRO IntlStrEqNIA(s1, s2, nChar)=IntlStrEqWorkerA(%FALSE, s1, s2, nChar)
MACRO IntlStrEqNIW(s1, s2, nChar)=IntlStrEqWorkerW(%FALSE, s1, s2, nChar)

#IF %DEF(%UNICODE)
MACRO IntlStrEqN  = IntlStrEqNW
MACRO IntlStrEqNI = IntlStrEqNIW
#ELSE
MACRO IntlStrEqN  = IntlStrEqNA
MACRO IntlStrEqNI = IntlStrEqNIA
#ENDIF

$SZ_CONTENTTYPE_HTMLA     = "text/html"
$$SZ_CONTENTTYPE_HTMLW    =  "text/html"$$
$SZ_CONTENTTYPE_CDFA      = "application/x-cdf"
$$SZ_CONTENTTYPE_CDFW     =  "application/x-cdf"$$

#IF %DEF(%UNICODE)
MACRO SZ_CONTENTTYPE_HTML = $$SZ_CONTENTTYPE_HTMLW
MACRO SZ_CONTENTTYPE_CDF  = $$SZ_CONTENTTYPE_CDFW
#ELSE
MACRO SZ_CONTENTTYPE_HTML = $SZ_CONTENTTYPE_HTMLA
MACRO SZ_CONTENTTYPE_CDF  = $SZ_CONTENTTYPE_CDFA
#ENDIF

MACRO PathIsHTMLFileA(pszPath)=PathIsContentTypeA(pszPath,%SZ_CONTENTTYPE_HTMLA)
MACRO PathIsHTMLFileW(pszPath)=PathIsContentTypeW(pszPath,%SZ_CONTENTTYPE_HTMLW)


MACRO StrCatA    = lstrcatA
MACRO StrCmpA    = lstrcmpA
MACRO StrCmpIA   = lstrcmpiA
MACRO StrCpyA    = lstrcpyA
MACRO StrCpyNA   = lstrcpynA


MACRO StrToLong  = StrToInt
MACRO StrNCmp    = StrCmpN
MACRO StrNCmpI   = StrCmpNI
MACRO StrNCpy    = StrCpyN
MACRO StrCatN    = StrNCat

#IF %DEF(%UNICODE)
MACRO StrCat     = StrCatW
MACRO StrCmp     = StrCmpW
MACRO StrCmpI    = StrCmpIW
MACRO StrCpy     = StrCpyW
MACRO StrCpyN    = StrCpyNW
#ELSE
MACRO StrCat     = lstrcatA
MACRO StrCmp     = lstrcmpA
MACRO StrCmpI    = lstrcmpiA
MACRO StrCpy     = lstrcpyA
MACRO StrCpyN    = lstrcpynA
#ENDIF


#ENDIF ' #IF NOT %DEF(%NO_SHLWAPI_STRFCNS)



#IF NOT %DEF(%NO_SHLWAPI_PATH)

'=============== Path Routines ===================================

DECLARE FUNCTION PathAddBackslashA LIB "ShlWApi.dll" _
    ALIAS "PathAddBackslashA" (pszPath AS ASCIIZ) AS DWORD

DECLARE FUNCTION PathAddBackslashW LIB "ShlWApi.dll" _
    ALIAS "PathAddBackslashW" (pszPath AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
MACRO PathAddBackslash=PathAddBackslashW
#ELSE
MACRO PathAddBackslash=PathAddBackslashA
#ENDIF

DECLARE FUNCTION PathAddExtensionA LIB "ShlWApi.dll" _
    ALIAS "PathAddExtensionA" (pszPath AS ASCIIZ, pszExt AS ASCIIZ) AS LONG

DECLARE FUNCTION PathAddExtensionW LIB "ShlWApi.dll" _
    ALIAS "PathAddExtensionW" (pszPath AS WSTRINGZ, pszExt AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO PathAddExtension=PathAddExtensionW
#ELSE
MACRO PathAddExtension=PathAddExtensionA
#ENDIF

DECLARE FUNCTION PathAppendA LIB "ShlWApi.dll" ALIAS "PathAppendA" _
    (pszPath AS ASCIIZ, pMore AS ASCIIZ) AS LONG

DECLARE FUNCTION PathAppendW LIB "ShlWApi.dll" ALIAS "PathAppendW" _
    (pszPath AS WSTRINGZ, pMore AS WSTRINGZ) AS LONG

DECLARE FUNCTION PathBuildRootA LIB "ShlWApi.dll" ALIAS "PathBuildRootA" _
    (szRoot AS ASCIIZ, BYVAL iDrive AS LONG) AS DWORD

DECLARE FUNCTION PathBuildRootW LIB "ShlWApi.dll" ALIAS "PathBuildRootW" _
    (szRoot AS WSTRINGZ, BYVAL iDrive AS LONG) AS DWORD

#IF %DEF(%UNICODE)
MACRO PathBuildRoot=PathBuildRootW
#ELSE
MACRO PathBuildRoot=PathBuildRootA
#ENDIF

DECLARE FUNCTION PathCanonicalizeA LIB "ShlWApi.dll" _
    ALIAS "PathCanonicalizeA" (pszBuf AS ASCIIZ, pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION PathCanonicalizeW LIB "ShlWApi.dll" _
    ALIAS "PathCanonicalizeW" (pszBuf AS WSTRINGZ, pszPath AS WSTRINGZ) AS LONG

DECLARE FUNCTION PathCombineA LIB "ShlWApi.dll" ALIAS "PathCombineA" _
    (szDest AS ASCIIZ, lpszDir AS ASCIIZ, lpszFile AS ASCIIZ) AS DWORD

DECLARE FUNCTION PathCombineW LIB "ShlWApi.dll" ALIAS "PathCombineW" _
    (szDest AS WSTRINGZ, lpszDir AS WSTRINGZ, lpszFile AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
MACRO PathCombine=PathCombineW
#ELSE
MACRO PathCombine=PathCombineA
#ENDIF

DECLARE FUNCTION PathCompactPathA LIB "ShlWApi.dll" ALIAS "PathCompactPathA" _
    (BYVAL hDC AS DWORD, pszPath AS ASCIIZ, BYVAL dx AS DWORD) AS LONG

DECLARE FUNCTION PathCompactPathW LIB "ShlWApi.dll" ALIAS "PathCompactPathW" _
    (BYVAL hDC AS DWORD, pszPath AS WSTRINGZ, BYVAL dx AS DWORD) AS LONG

DECLARE FUNCTION PathCompactPathExA LIB "ShlWApi.dll" _
    ALIAS "PathCompactPathExA" (pszOut AS ASCIIZ, pszSrc AS ASCIIZ, _
    BYVAL cchMax AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION PathCompactPathExW LIB "ShlWApi.dll" _
    ALIAS "PathCompactPathExW" (pszOut AS WSTRINGZ, pszSrc AS WSTRINGZ, _
    BYVAL cchMax AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION PathCommonPrefixA LIB "ShlWApi.dll" _
    ALIAS "PathCommonPrefixA" (pszFile1 AS ASCIIZ, pszFile2 AS ASCIIZ, _
    achPath AS ASCIIZ) AS LONG

DECLARE FUNCTION PathCommonPrefixW LIB "ShlWApi.dll" _
    ALIAS "PathCommonPrefixW" (pszFile1 AS WSTRINGZ, pszFile2 AS WSTRINGZ, _
    achPath AS WSTRINGZ) AS LONG

DECLARE FUNCTION PathFileExistsA LIB "ShlWApi.dll" ALIAS "PathFileExistsA" _
    (pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION PathFileExistsW LIB "ShlWApi.dll" ALIAS "PathFileExistsW" _
    (pszPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO PathFileExists=PathFileExistsW
#ELSE
MACRO PathFileExists=PathFileExistsA
#ENDIF

DECLARE FUNCTION PathFindExtensionA LIB "ShlWApi.dll" _
    ALIAS "PathFindExtensionA" (pszPath AS ASCIIZ) AS DWORD

DECLARE FUNCTION PathFindExtensionW LIB "ShlWApi.dll" _
    ALIAS "PathFindExtensionW" (pszPath AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
MACRO PathFindExtension=PathFindExtensionW
#ELSE
MACRO PathFindExtension=PathFindExtensionA
#ENDIF

DECLARE FUNCTION PathFindFileNameA LIB "ShlWApi.dll" _
    ALIAS "PathFindFileNameA" (pszPath AS ASCIIZ) AS DWORD

DECLARE FUNCTION PathFindFileNameW LIB "ShlWApi.dll" _
    ALIAS "PathFindFileNameW" (pszPath AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
MACRO PathFindFileName=PathFindFileNameW
#ELSE
MACRO PathFindFileName=PathFindFileNameA
#ENDIF

DECLARE FUNCTION PathFindNextComponentA LIB "ShlWApi.dll" _
    ALIAS "PathFindNextComponentA" (pszPath AS ASCIIZ) AS DWORD

DECLARE FUNCTION PathFindNextComponentW LIB "ShlWApi.dll" _
    ALIAS "PathFindNextComponentW" (pszPath AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
MACRO PathFindNextComponent=PathFindNextComponentW
#ELSE
MACRO PathFindNextComponent=PathFindNextComponentA
#ENDIF

DECLARE FUNCTION PathFindOnPathA LIB "ShlWApi.dll" ALIAS "PathFindOnPathA" _
    (pszPath AS ASCIIZ, ppszOtherDirs AS DWORD) AS LONG

DECLARE FUNCTION PathFindOnPathW LIB "ShlWApi.dll" ALIAS "PathFindOnPathW" _
    (pszPath AS WSTRINGZ, ppszOtherDirs AS DWORD) AS LONG

DECLARE FUNCTION PathFindSuffixArrayA LIB "ShlWApi.dll" _
    ALIAS "PathFindSuffixArrayA" (pszPath AS ASCIIZ, apszSuffix AS ANY, _
    BYVAL iArraySize AS LONG) AS DWORD

DECLARE FUNCTION PathFindSuffixArrayW LIB "ShlWApi.dll" _
    ALIAS "PathFindSuffixArrayW" (pszPath AS WSTRINGZ, apszSuffix AS ANY, _
    BYVAL iArraySize AS LONG) AS DWORD

#IF %DEF(%UNICODE)
MACRO PathFindSuffixArray=PathFindSuffixArrayW
#ELSE
MACRO PathFindSuffixArray=PathFindSuffixArrayA
#ENDIF

DECLARE FUNCTION PathGetArgsA LIB "ShlWApi.dll" ALIAS "PathGetArgsA" _
    (pszPath AS ASCIIZ) AS DWORD

DECLARE FUNCTION PathGetArgsW LIB "ShlWApi.dll" ALIAS "PathGetArgsW" _
    (pszPath AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
MACRO PathGetArgs=PathGetArgsW
#ELSE
MACRO PathGetArgs=PathGetArgsA
#ENDIF

DECLARE FUNCTION PathIsLFNFileSpecA LIB "ShlWApi.dll" _
    ALIAS "PathIsLFNFileSpecA" (lpName AS ASCIIZ) AS LONG

DECLARE FUNCTION PathIsLFNFileSpecW LIB "ShlWApi.dll" _
    ALIAS "PathIsLFNFileSpecW" (lpName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO PathIsLFNFileSpec=PathIsLFNFileSpecW
#ELSE
MACRO PathIsLFNFileSpec=PathIsLFNFileSpecA
#ENDIF

DECLARE FUNCTION PathGetCharTypeA LIB "ShlWApi.dll" ALIAS "PathGetCharTypeA" _
    (BYVAL ch AS BYTE) AS DWORD

DECLARE FUNCTION PathGetCharTypeW LIB "ShlWApi.dll" ALIAS "PathGetCharTypeW" _
    (BYVAL ch AS WORD) AS DWORD

' Return flags for PathGetCharType
%GCT_INVALID   = &H0000
%GCT_LFNCHAR   = &H0001
%GCT_SHORTCHAR = &H0002
%GCT_WILD      = &H0004
%GCT_SEPARATOR = &H0008

DECLARE FUNCTION PathGetDriveNumberA LIB "ShlWApi.dll" _
    ALIAS "PathGetDriveNumberA" (pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION PathGetDriveNumberW LIB "ShlWApi.dll" _
    ALIAS "PathGetDriveNumberW" (pszPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO PathGetDriveNumber=PathGetDriveNumberW
#ELSE
MACRO PathGetDriveNumber=PathGetDriveNumberA
#ENDIF

DECLARE FUNCTION PathIsDirectoryA LIB "ShlWApi.dll" ALIAS "PathIsDirectoryA" _
    (pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION PathIsDirectoryW LIB "ShlWApi.dll" ALIAS "PathIsDirectoryW" _
    (pszPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO PathIsDirectory=PathIsDirectoryW
#ELSE
MACRO PathIsDirectory=PathIsDirectoryA
#ENDIF

DECLARE FUNCTION PathIsDirectoryEmptyA LIB "ShlWApi.dll" _
    ALIAS "PathIsDirectoryEmptyA" (pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION PathIsDirectoryEmptyW LIB "ShlWApi.dll" _
    ALIAS "PathIsDirectoryEmptyW" (pszPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO PathIsDirectoryEmpty=PathIsDirectoryEmptyW
#ELSE
MACRO PathIsDirectoryEmpty=PathIsDirectoryEmptyA
#ENDIF

DECLARE FUNCTION PathIsFileSpecA LIB "ShlWApi.dll" ALIAS "PathIsFileSpecA" _
    (pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION PathIsFileSpecW LIB "ShlWApi.dll" ALIAS "PathIsFileSpecW" _
    (pszPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO PathIsFileSpec=PathIsFileSpecW
#ELSE
MACRO PathIsFileSpec=PathIsFileSpecA
#ENDIF

DECLARE FUNCTION PathIsPrefixA LIB "ShlWApi.dll" ALIAS "PathIsPrefixA" _
    (pszPrefix AS ASCIIZ, pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION PathIsPrefixW LIB "ShlWApi.dll" ALIAS "PathIsPrefixW" _
    (pszPrefix AS WSTRINGZ, pszPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO PathIsPrefix=PathIsPrefixW
#ELSE
MACRO PathIsPrefix=PathIsPrefixA
#ENDIF

DECLARE FUNCTION PathIsRelativeA LIB "ShlWApi.dll" ALIAS "PathIsRelativeA" _
    (pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION PathIsRelativeW LIB "ShlWApi.dll" ALIAS "PathIsRelativeW" _
    (pszPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO PathIsRelative=PathIsRelativeW
#ELSE
MACRO PathIsRelative=PathIsRelativeA
#ENDIF

DECLARE FUNCTION PathIsRootA LIB "ShlWApi.dll" ALIAS "PathIsRootA" _
    (pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION PathIsRootW LIB "ShlWApi.dll" ALIAS "PathIsRootW" _
    (pszPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO PathIsRoot=PathIsRootW
#ELSE
MACRO PathIsRoot=PathIsRootA
#ENDIF

DECLARE FUNCTION PathIsSameRootA LIB "ShlWApi.dll" ALIAS "PathIsSameRootA" _
    (pszPath1 AS ASCIIZ, pszPath2 AS ASCIIZ) AS LONG

DECLARE FUNCTION PathIsSameRootW LIB "ShlWApi.dll" ALIAS "PathIsSameRootW" _
    (pszPath1 AS WSTRINGZ, pszPath2 AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO PathIsSameRoot=PathIsSameRootW
#ELSE
MACRO PathIsSameRoot=PathIsSameRootA
#ENDIF

DECLARE FUNCTION PathIsUNCA LIB "ShlWApi.dll" ALIAS "PathIsUNCA" _
    (pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION PathIsUNCW LIB "ShlWApi.dll" ALIAS "PathIsUNCW" _
    (pszPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO PathIsUNC=PathIsUNCW
#ELSE
MACRO PathIsUNC=PathIsUNCA
#ENDIF

DECLARE FUNCTION PathIsNetworkPathA LIB "ShlWApi.dll" _
    ALIAS "PathIsNetworkPathA" (pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION PathIsNetworkPathW LIB "ShlWApi.dll" _
    ALIAS "PathIsNetworkPathW" (pszPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO PathIsNetworkPath=PathIsNetworkPathW
#ELSE
MACRO PathIsNetworkPath=PathIsNetworkPathA
#ENDIF

DECLARE FUNCTION PathIsUNCServerA LIB "ShlWApi.dll" ALIAS "PathIsUNCServerA" _
    (pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION PathIsUNCServerW LIB "ShlWApi.dll" ALIAS "PathIsUNCServerW" _
    (pszPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO PathIsUNCServer=PathIsUNCServerW
#ELSE
MACRO PathIsUNCServer=PathIsUNCServerA
#ENDIF

DECLARE FUNCTION PathIsUNCServerShareA LIB "ShlWApi.dll" _
    ALIAS "PathIsUNCServerShareA" (pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION PathIsUNCServerShareW LIB "ShlWApi.dll" _
    ALIAS "PathIsUNCServerShareW" (pszPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO PathIsUNCServerShare=PathIsUNCServerShareW
#ELSE
MACRO PathIsUNCServerShare=PathIsUNCServerShareA
#ENDIF

DECLARE FUNCTION PathIsContentTypeA LIB "ShlWApi.dll" _
    ALIAS "PathIsContentTypeA" (pszPath AS ASCIIZ, pszContentType AS ASCIIZ) _
    AS LONG

DECLARE FUNCTION PathIsContentTypeW LIB "ShlWApi.dll" _
    ALIAS "PathIsContentTypeW" (pszPath AS WSTRINGZ, _
    pszContentType AS WSTRINGZ) AS LONG

DECLARE FUNCTION PathIsURLA LIB "ShlWApi.dll" ALIAS "PathIsURLA" _
    (pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION PathIsURLW LIB "ShlWApi.dll" ALIAS "PathIsURLW" _
    (pszPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO PathIsURL=PathIsURLW
#ELSE
MACRO PathIsURL=PathIsURLA
#ENDIF

DECLARE FUNCTION PathMakePrettyA LIB "ShlWApi.dll" ALIAS "PathMakePrettyA" _
    (pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION PathMakePrettyW LIB "ShlWApi.dll" ALIAS "PathMakePrettyW" _
    (pszPath AS WSTRINGZ) AS LONG

DECLARE FUNCTION PathMatchSpecA LIB "ShlWApi.dll" ALIAS "PathMatchSpecA" _
    (pszFile AS ASCIIZ, pszSpec AS ASCIIZ) AS LONG

DECLARE FUNCTION PathMatchSpecW LIB "ShlWApi.dll" ALIAS "PathMatchSpecW" _
    (pszFile AS WSTRINGZ, pszSpec AS WSTRINGZ) AS LONG

#IF (%WIN32_IE >= %WIN32_IE_IE70)
' Flags for PathMatchSpecEx
%PMSF_NORMAL            = &H00000000
%PMSF_MULTIPLE          = &H00000001
%PMSF_DONT_STRIP_SPACES = &H00010000  ' modifies either of the above

DECLARE FUNCTION PathMatchSpecExA LIB "ShlWApi.dll" ALIAS "PathMatchSpecExA" _
    (pszFile AS ASCIIZ, pszSpec AS ASCIIZ, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION PathMatchSpecExW LIB "ShlWApi.dll" ALIAS "PathMatchSpecExW" _
    (pszFile AS WSTRINGZ, pszSpec AS WSTRINGZ, BYVAL dwFlags AS DWORD) AS LONG

#ENDIF ' %WIN32_IE_IE70

DECLARE FUNCTION PathParseIconLocationA LIB "ShlWApi.dll" _
    ALIAS "PathParseIconLocationA" (pszIconFile AS ASCIIZ) AS LONG

DECLARE FUNCTION PathParseIconLocationW LIB "ShlWApi.dll" _
    ALIAS "PathParseIconLocationW" (pszIconFile AS WSTRINGZ) AS LONG

DECLARE SUB PathQuoteSpacesA LIB "ShlWApi.dll" ALIAS "PathQuoteSpacesA" _
    (lpsz AS ASCIIZ)

DECLARE SUB PathQuoteSpacesW LIB "ShlWApi.dll" ALIAS "PathQuoteSpacesW" _
    (lpsz AS WSTRINGZ)

#IF %DEF(%UNICODE)
MACRO PathQuoteSpaces=PathQuoteSpacesW
#ELSE
MACRO PathQuoteSpaces=PathQuoteSpacesA
#ENDIF

DECLARE FUNCTION PathRelativePathToA LIB "ShlWApi.dll" _
    ALIAS "PathRelativePathToA" (pszPath AS ASCIIZ, pszFrom AS ASCIIZ, _
    BYVAL dwAttrFrom AS DWORD, pszTo AS ASCIIZ, BYVAL dwAttrTo AS DWORD) _
    AS LONG

DECLARE FUNCTION PathRelativePathToW LIB "ShlWApi.dll" _
    ALIAS "PathRelativePathToW" (pszPath AS WSTRINGZ, pszFrom AS WSTRINGZ, _
    BYVAL dwAttrFrom AS DWORD, pszTo AS WSTRINGZ, BYVAL dwAttrTo AS DWORD) _
    AS LONG

DECLARE SUB PathRemoveArgsA LIB "ShlWApi.dll" ALIAS "PathRemoveArgsA" _
    (pszPath AS ASCIIZ)

DECLARE SUB PathRemoveArgsW LIB "ShlWApi.dll" ALIAS "PathRemoveArgsW" _
    (pszPath AS WSTRINGZ)

DECLARE FUNCTION PathRemoveBackslashA LIB "ShlWApi.dll" _
    ALIAS "PathRemoveBackslashA" (pszPath AS ASCIIZ) AS DWORD

DECLARE FUNCTION PathRemoveBackslashW LIB "ShlWApi.dll" _
    ALIAS "PathRemoveBackslashW" (pszPath AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
MACRO PathRemoveBackslash=PathRemoveBackslashW
#ELSE
MACRO PathRemoveBackslash=PathRemoveBackslashA
#ENDIF

DECLARE SUB PathRemoveBlanksA LIB "ShlWApi.dll" ALIAS "PathRemoveBlanksA" _
    (pszPath AS ASCIIZ)

DECLARE SUB PathRemoveBlanksW LIB "ShlWApi.dll" ALIAS "PathRemoveBlanksW" _
    (pszPath AS WSTRINGZ)

DECLARE SUB PathRemoveExtensionA LIB "ShlWApi.dll" _
    ALIAS "PathRemoveExtensionA" (pszPath AS ASCIIZ)

DECLARE SUB PathRemoveExtensionW LIB "ShlWApi.dll" _
    ALIAS "PathRemoveExtensionW" (pszPath AS WSTRINGZ)

DECLARE FUNCTION PathRemoveFileSpecA LIB "ShlWApi.dll" _
    ALIAS "PathRemoveFileSpecA" (pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION PathRemoveFileSpecW LIB "ShlWApi.dll" _
    ALIAS "PathRemoveFileSpecW" (pszPath AS WSTRINGZ) AS LONG

DECLARE FUNCTION PathRenameExtensionA LIB "ShlWApi.dll" _
    ALIAS "PathRenameExtensionA" (pszPath AS ASCIIZ, pszExt AS ASCIIZ) AS LONG

DECLARE FUNCTION PathRenameExtensionW LIB "ShlWApi.dll" _
    ALIAS "PathRenameExtensionW" (pszPath AS WSTRINGZ, pszExt AS WSTRINGZ) _
    AS LONG

DECLARE FUNCTION PathSearchAndQualifyA LIB "ShlWApi.dll" _
    ALIAS "PathSearchAndQualifyA" (pszPath AS ASCIIZ, pszBuf AS ASCIIZ, _
    BYVAL cchBuf AS DWORD) AS LONG

DECLARE FUNCTION PathSearchAndQualifyW LIB "ShlWApi.dll" _
    ALIAS "PathSearchAndQualifyW" (pszPath AS WSTRINGZ, pszBuf AS WSTRINGZ, _
    BYVAL cchBuf AS DWORD) AS LONG

DECLARE SUB PathSetDlgItemPathA LIB "ShlWApi.dll" ALIAS "PathSetDlgItemPathA" _
    (BYVAL hDlg AS DWORD, BYVAL ID AS LONG, pszPath AS ASCIIZ)

DECLARE SUB PathSetDlgItemPathW LIB "ShlWApi.dll" ALIAS "PathSetDlgItemPathW" _
    (BYVAL hDlg AS DWORD, BYVAL ID AS LONG, pszPath AS WSTRINGZ)

DECLARE FUNCTION PathSkipRootA LIB "ShlWApi.dll" ALIAS "PathSkipRootA" _
    (pszPath AS ASCIIZ) AS DWORD

DECLARE FUNCTION PathSkipRootW LIB "ShlWApi.dll" ALIAS "PathSkipRootW" _
    (pszPath AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
MACRO PathSkipRoot=PathSkipRootW
#ELSE
MACRO PathSkipRoot=PathSkipRootA
#ENDIF

DECLARE SUB PathStripPathA LIB "ShlWApi.dll" ALIAS "PathStripPathA" _
    (pszPath AS ASCIIZ)

DECLARE SUB PathStripPathW LIB "ShlWApi.dll" ALIAS "PathStripPathW" _
    (pszPath AS WSTRINGZ)

#IF %DEF(%UNICODE)
MACRO PathStripPath=PathStripPathW
#ELSE
MACRO PathStripPath=PathStripPathA
#ENDIF

DECLARE FUNCTION PathStripToRootA LIB "ShlWApi.dll" ALIAS "PathStripToRootA" _
    (pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION PathStripToRootW LIB "ShlWApi.dll" ALIAS "PathStripToRootW" _
    (pszPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO PathStripToRoot=PathStripToRootW
#ELSE
MACRO PathStripToRoot=PathStripToRootA
#ENDIF

DECLARE SUB PathUnquoteSpacesA LIB "ShlWApi.dll" ALIAS "PathUnquoteSpacesA" _
    (lpsz AS ASCIIZ)

DECLARE SUB PathUnquoteSpacesW LIB "ShlWApi.dll" ALIAS "PathUnquoteSpacesW" _
    (lpsz AS WSTRINGZ)

DECLARE FUNCTION PathMakeSystemFolderA LIB "ShlWApi.dll" _
    ALIAS "PathMakeSystemFolderA" (pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION PathMakeSystemFolderW LIB "ShlWApi.dll" _
    ALIAS "PathMakeSystemFolderW" (pszPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO PathMakeSystemFolder=PathMakeSystemFolderW
#ELSE
MACRO PathMakeSystemFolder=PathMakeSystemFolderA
#ENDIF

DECLARE FUNCTION PathUnmakeSystemFolderA LIB "ShlWApi.dll" _
    ALIAS "PathUnmakeSystemFolderA" (pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION PathUnmakeSystemFolderW LIB "ShlWApi.dll" _
    ALIAS "PathUnmakeSystemFolderW" (pszPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO PathUnmakeSystemFolder=PathUnmakeSystemFolderW
#ELSE
MACRO PathUnmakeSystemFolder=PathUnmakeSystemFolderA
#ENDIF

DECLARE FUNCTION PathIsSystemFolderA LIB "ShlWApi.dll" _
    ALIAS "PathIsSystemFolderA" (pszPath AS ASCIIZ, BYVAL dwAttrb AS DWORD) _
    AS LONG

DECLARE FUNCTION PathIsSystemFolderW LIB "ShlWApi.dll" _
    ALIAS "PathIsSystemFolderW" (pszPath AS WSTRINGZ, _
    BYVAL dwAttrb AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO PathIsSystemFolder=PathIsSystemFolderW
#ELSE
MACRO PathIsSystemFolder=PathIsSystemFolderA
#ENDIF

DECLARE SUB PathUndecorateA LIB "ShlWApi.dll" ALIAS "PathUndecorateA" _
    (pszPath AS ASCIIZ)

DECLARE SUB PathUndecorateW LIB "ShlWApi.dll" ALIAS "PathUndecorateW" _
    (pszPath AS WSTRINGZ)

#IF %DEF(%UNICODE)
MACRO PathUndecorate=PathUndecorateW
#ELSE
MACRO PathUndecorate=PathUndecorateA
#ENDIF

DECLARE FUNCTION PathUnExpandEnvStringsA LIB "ShlWApi.dll" _
    ALIAS "PathUnExpandEnvStringsA" (pszPath AS ASCIIZ, pszBuf AS ASCIIZ, _
    BYVAL cchBuf AS DWORD) AS LONG

DECLARE FUNCTION PathUnExpandEnvStringsW LIB "ShlWApi.dll" _
    ALIAS "PathUnExpandEnvStringsW" (pszPath AS WSTRINGZ, pszBuf AS WSTRINGZ, _
    BYVAL cchBuf AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO PathUnExpandEnvStrings=PathUnExpandEnvStringsW
#ELSE
MACRO PathUnExpandEnvStrings=PathUnExpandEnvStringsA
#ENDIF

#IF %DEF(%UNICODE)
MACRO PathAppend            = PathAppendW
MACRO PathCanonicalize      = PathCanonicalizeW
MACRO PathCompactPath       = PathCompactPathW
MACRO PathCompactPathEx     = PathCompactPathExW
MACRO PathCommonPrefix      = PathCommonPrefixW
MACRO PathFindOnPath        = PathFindOnPathW
MACRO PathGetCharType       = PathGetCharTypeW
MACRO PathIsContentType     = PathIsContentTypeW
MACRO PathIsHTMLFile        = PathIsHTMLFileW
MACRO PathMakePretty        = PathMakePrettyW
MACRO PathMatchSpec         = PathMatchSpecW
#IF (%WIN32_IE >= %WIN32_IE_IE70)
MACRO PathMatchSpecEx       = PathMatchSpecExW
#ENDIF ' %WIN32_IE_IE70
MACRO PathParseIconLocation = PathParseIconLocationW
MACRO PathRelativePathTo    = PathRelativePathToW
MACRO PathRemoveArgs        = PathRemoveArgsW
MACRO PathRemoveBlanks      = PathRemoveBlanksW
MACRO PathRemoveExtension   = PathRemoveExtensionW
MACRO PathRemoveFileSpec    = PathRemoveFileSpecW
MACRO PathRenameExtension   = PathRenameExtensionW
MACRO PathSearchAndQualify  = PathSearchAndQualifyW
MACRO PathSetDlgItemPath    = PathSetDlgItemPathW
MACRO PathUnquoteSpaces     = PathUnquoteSpacesW
#ELSE
MACRO PathAppend            = PathAppendA
MACRO PathCanonicalize      = PathCanonicalizeA
MACRO PathCompactPath       = PathCompactPathA
MACRO PathCompactPathEx     = PathCompactPathExA
MACRO PathCommonPrefix      = PathCommonPrefixA
MACRO PathFindOnPath        = PathFindOnPathA
MACRO PathGetCharType       = PathGetCharTypeA
MACRO PathIsContentType     = PathIsContentTypeA
MACRO PathIsHTMLFile        = PathIsHTMLFileA
MACRO PathMakePretty        = PathMakePrettyA
MACRO PathMatchSpec         = PathMatchSpecA
#IF (%WIN32_IE >= %WIN32_IE_IE70)
MACRO PathMatchSpecEx       = PathMatchSpecExA
#ENDIF ' %WIN32_IE_IE70
MACRO PathParseIconLocation = PathParseIconLocationA
MACRO PathRelativePathTo    = PathRelativePathToA
MACRO PathRemoveArgs        = PathRemoveArgsA
MACRO PathRemoveBlanks      = PathRemoveBlanksA
MACRO PathRemoveExtension   = PathRemoveExtensionA
MACRO PathRemoveFileSpec    = PathRemoveFileSpecA
MACRO PathRenameExtension   = PathRenameExtensionA
MACRO PathSearchAndQualify  = PathSearchAndQualifyA
MACRO PathSetDlgItemPath    = PathSetDlgItemPathA
MACRO PathUnquoteSpaces     = PathUnquoteSpacesA
#ENDIF

MACRO URL_SCHEME_enum=LONG
ENUM URL_SCHEME SINGULAR
    URL_SCHEME_INVALID = -1
    URL_SCHEME_UNKNOWN
    URL_SCHEME_FTP
    URL_SCHEME_HTTP
    URL_SCHEME_GOPHER
    URL_SCHEME_MAILTO
    URL_SCHEME_NEWS
    URL_SCHEME_NNTP
    URL_SCHEME_TELNET
    URL_SCHEME_WAIS
    URL_SCHEME_FILE
    URL_SCHEME_MK
    URL_SCHEME_HTTPS
    URL_SCHEME_SHELL
    URL_SCHEME_SNEWS
    URL_SCHEME_LOCAL
    URL_SCHEME_JAVASCRIPT
    URL_SCHEME_VBSCRIPT
    URL_SCHEME_ABOUT
    URL_SCHEME_RES
#IF (%WIN32_IE >= %WIN32_IE_IE60)
    URL_SCHEME_MSSHELLROOTED
    URL_SCHEME_MSSHELLIDLIST
    URL_SCHEME_MSHELP
#ENDIF ' %WIN32_IE_IE60
#IF (%WIN32_IE >= %WIN32_IE_IE70)
    URL_SCHEME_MSSHELLDEVICE
    URL_SCHEME_WILDCARD
#ENDIF ' %WIN32_IE_IE70
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
    URL_SCHEME_SEARCH_MS
#ENDIF
#IF (%NTDDI_VERSION >= %NTDDI_VISTASP1)
    URL_SCHEME_SEARCH
#ENDIF
#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
    URL_SCHEME_KNOWNFOLDER
#ENDIF
    URL_SCHEME_MAXVALUE
END ENUM

MACRO URL_PART_enum=LONG
ENUM URL_PART SINGULAR
    URL_PART_NONE
    URL_PART_SCHEME
    URL_PART_HOSTNAME
    URL_PART_USERNAME
    URL_PART_PASSWORD
    URL_PART_PORT
    URL_PART_QUERY
END ENUM

MACRO URLIS_enum=LONG
ENUM URLIS_x SINGULAR
    URLIS_URL
    URLIS_OPAQUE
    URLIS_NOHISTORY
    URLIS_FILEURL
    URLIS_APPLIABLE
    URLIS_DIRECTORY
    URLIS_HASQUERY
END ENUM

%URL_UNESCAPE                    = &H10000000
%URL_ESCAPE_UNSAFE               = &H20000000
%URL_PLUGGABLE_PROTOCOL          = &H40000000
%URL_WININET_COMPATIBILITY       = &H80000000???
%URL_DONT_ESCAPE_EXTRA_INFO      = &H02000000
%URL_DONT_UNESCAPE_EXTRA_INFO    = %URL_DONT_ESCAPE_EXTRA_INFO
%URL_BROWSER_MODE                = %URL_DONT_ESCAPE_EXTRA_INFO
%URL_ESCAPE_SPACES_ONLY          = &H04000000
%URL_DONT_SIMPLIFY               = &H08000000
%URL_NO_META                     = %URL_DONT_SIMPLIFY
%URL_UNESCAPE_INPLACE            = &H00100000
%URL_CONVERT_IF_DOSPATH          = &H00200000
%URL_UNESCAPE_HIGH_ANSI_ONLY     = &H00400000
%URL_INTERNAL_PATH               = &H00800000  ' Will escape #'s in paths
%URL_FILE_USE_PATHURL            = &H00010000
#IF (%WIN32_IE >= %WIN32_IE_IE60SP2)
%URL_DONT_UNESCAPE               = &H00020000  ' Do not unescape the path/url at all
#ENDIF  ' %WIN32_IE_IE60SP2
#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
%URL_ESCAPE_AS_UTF8              = &H00040000  ' Percent-encode all non-ASCII characters as their UTF-8 equivalents.
#ENDIF  ' (%NTDDI_VERSION >= %NTDDI_WIN7)
%URL_ESCAPE_PERCENT              = &H00001000
%URL_ESCAPE_SEGMENT_ONLY         = &H00002000  ' Treat the entire URL param as one URL segment.

%URL_PARTFLAG_KEEPSCHEME         = &H00000001

%URL_APPLY_DEFAULT               = &H00000001
%URL_APPLY_GUESSSCHEME           = &H00000002
%URL_APPLY_GUESSFILE             = &H00000004
%URL_APPLY_FORCEAPPLY            = &H00000008

DECLARE FUNCTION UrlCompareA LIB "ShlWApi.dll" ALIAS "UrlCompareA" _
    (psz1 AS ASCIIZ, psz2 AS ASCIIZ, BYVAL fIgnoreSlash AS LONG) AS LONG


DECLARE FUNCTION UrlCompareW LIB "ShlWApi.dll" ALIAS "UrlCompareW" _
    (psz1 AS WSTRINGZ, psz2 AS WSTRINGZ, BYVAL fIgnoreSlash AS LONG) AS LONG

DECLARE FUNCTION UrlCombineA LIB "ShlWApi.dll" ALIAS "UrlCombineA" _
    (pszBase AS ASCIIZ, pszRelative AS ASCIIZ, pszCombined AS ASCIIZ, _
    pcchCombined AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION UrlCombineW LIB "ShlWApi.dll" ALIAS "UrlCombineW" _
    (pszBase AS WSTRINGZ, pszRelative AS WSTRINGZ, pszCombined AS WSTRINGZ, _
    pcchCombined AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION UrlCanonicalizeA LIB "ShlWApi.dll" ALIAS "UrlCanonicalizeA" _
    (pszUrl AS ASCIIZ, pszCanonicalized AS ASCIIZ, _
    pcchCanonicalized AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION UrlCanonicalizeW LIB "ShlWApi.dll" ALIAS "UrlCanonicalizeW" _
    (pszUrl AS WSTRINGZ, pszCanonicalized AS WSTRINGZ, _
    pcchCanonicalized AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION UrlIsOpaqueA LIB "ShlWApi.dll" ALIAS "UrlIsOpaqueA" _
    (pszURL AS ASCIIZ) AS LONG

DECLARE FUNCTION UrlIsOpaqueW LIB "ShlWApi.dll" ALIAS "UrlIsOpaqueW" _
    (pszURL AS WSTRINGZ) AS LONG

DECLARE FUNCTION UrlIsNoHistoryA LIB "ShlWApi.dll" ALIAS "UrlIsNoHistoryA" _
    (pszURL AS ASCIIZ) AS LONG

DECLARE FUNCTION UrlIsNoHistoryW LIB "ShlWApi.dll" ALIAS "UrlIsNoHistoryW" _
    (pszURL AS WSTRINGZ) AS LONG

MACRO UrlIsFileUrlA(pszURL)=UrlIsA(pszURL,%URLIS_FILEURL)
MACRO UrlIsFileUrlW(pszURL)=UrlIsW(pszURL,%URLIS_FILEURL)

DECLARE FUNCTION UrlIsA LIB "ShlWApi.dll" ALIAS "UrlIsA" (pszUrl AS ASCIIZ, _
    BYVAL UrlIs AS LONG) AS LONG

DECLARE FUNCTION UrlIsW LIB "ShlWApi.dll" ALIAS "UrlIsW" (pszUrl AS WSTRINGZ, _
    BYVAL UrlIs AS LONG) AS LONG

DECLARE FUNCTION UrlGetLocationA LIB "ShlWApi.dll" ALIAS "UrlGetLocationA" _
    (psz1 AS ASCIIZ) AS DWORD

DECLARE FUNCTION UrlGetLocationW LIB "ShlWApi.dll" ALIAS "UrlGetLocationW" _
    (psz1 AS WSTRINGZ) AS DWORD

DECLARE FUNCTION UrlUnescapeA LIB "ShlWApi.dll" ALIAS "UrlUnescapeA" _
    (pszUrl AS ASCIIZ, pszUnescaped AS ASCIIZ, pcchUnescaped AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION UrlUnescapeW LIB "ShlWApi.dll" ALIAS "UrlUnescapeW" _
    (pszUrl AS WSTRINGZ, pszUnescaped AS WSTRINGZ, pcchUnescaped AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION UrlEscapeA LIB "ShlWApi.dll" ALIAS "UrlEscapeA" _
    (pszUrl AS ASCIIZ, pszEscaped AS ASCIIZ, pcchUnescaped AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION UrlEscapeW LIB "ShlWApi.dll" ALIAS "UrlEscapeW" _
    (pszUrl AS WSTRINGZ, pszEscaped AS WSTRINGZ, pcchUnescaped AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION UrlCreateFromPathA LIB "ShlWApi.dll" _
    ALIAS "UrlCreateFromPathA" (pszPath AS ASCIIZ, pszUrl AS ASCIIZ, _
    pcchUrl AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION UrlCreateFromPathW LIB "ShlWApi.dll" _
    ALIAS "UrlCreateFromPathW" (pszPath AS WSTRINGZ, pszUrl AS WSTRINGZ, _
    pcchUrl AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION PathCreateFromUrlA LIB "ShlWApi.dll" _
    ALIAS "PathCreateFromUrlA" (pszUrl AS ASCIIZ, pszPath AS ASCIIZ, _
    pcchPath AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION PathCreateFromUrlW LIB "ShlWApi.dll" _
    ALIAS "PathCreateFromUrlW" (pszUrl AS WSTRINGZ, pszPath AS WSTRINGZ, _
    pcchPath AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

#IF (%WIN32_IE >= %WIN32_IE_IE70)
DECLARE FUNCTION PathCreateFromUrlAlloc LIB "ShlWApi.dll" _
    ALIAS "PathCreateFromUrlAlloc" (pszIn AS WSTRINGZ, ppszOut AS ANY, _
    BYVAL dwFlags AS DWORD) AS LONG
#ENDIF ' %WIN32_IE_IE70

DECLARE FUNCTION UrlHashA LIB "ShlWApi.dll" ALIAS "UrlHashA" _
    (pszUrl AS ASCIIZ, BYVAL pbHash AS BYTE PTR, BYVAL cbHash AS DWORD) AS LONG

DECLARE FUNCTION UrlHashW LIB "ShlWApi.dll" ALIAS "UrlHashW" _
    (pszUrl AS WSTRINGZ, BYVAL pbHash AS BYTE PTR, BYVAL cbHash AS DWORD) _
    AS LONG

DECLARE FUNCTION UrlGetPartA LIB "ShlWApi.dll" ALIAS "UrlGetPartA" _
    (pszIn AS ASCIIZ, pszOut AS ASCIIZ, pcchOut AS DWORD, _
    BYVAL dwPath AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION UrlGetPartW LIB "ShlWApi.dll" ALIAS "UrlGetPartW" _
    (pszIn AS WSTRINGZ, pszOut AS WSTRINGZ, pcchOut AS DWORD, _
    BYVAL dwPath AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION UrlApplySchemeA LIB "ShlWApi.dll" ALIAS "UrlApplySchemeA" _
    (pszIn AS ASCIIZ, pszOut AS ASCIIZ, pcchOut AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION UrlApplySchemeW LIB "ShlWApi.dll" ALIAS "UrlApplySchemeW" _
    (pszIn AS WSTRINGZ, pszOut AS WSTRINGZ, pcchOut AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION HashData LIB "ShlWApi.dll" ALIAS "HashData" _
    (BYVAL pbData AS BYTE PTR, BYVAL cbData AS DWORD, _
    BYVAL pbHash AS BYTE PTR, BYVAL cbHash AS DWORD) AS LONG

DECLARE FUNCTION UrlFixupW LIB "ShlWApi.dll" ALIAS "UrlFixupW" _
    (pszIn AS WSTRINGZ, pszOut AS WSTRINGZ, BYVAL cchOut AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO UrlCompare        = UrlCompareW
MACRO UrlCombine        = UrlCombineW
MACRO UrlCanonicalize   = UrlCanonicalizeW
MACRO UrlIsOpaque       = UrlIsOpaqueW
MACRO UrlIsFileUrl      = UrlIsFileUrlW
MACRO UrlGetLocation    = UrlGetLocationW
MACRO UrlUnescape       = UrlUnescapeW
MACRO UrlEscape         = UrlEscapeW
MACRO UrlCreateFromPath = UrlCreateFromPathW
MACRO PathCreateFromUrl = PathCreateFromUrlW
MACRO UrlHash           = UrlHashW
MACRO UrlGetPart        = UrlGetPartW
MACRO UrlApplyScheme    = UrlApplySchemeW
MACRO UrlIs             = UrlIsW
MACRO UrlFixup          = UrlFixupW
#ELSE ' NOT %UNICODE
MACRO UrlCompare        = UrlCompareA
MACRO UrlCombine        = UrlCombineA
MACRO UrlCanonicalize   = UrlCanonicalizeA
MACRO UrlIsOpaque       = UrlIsOpaqueA
MACRO UrlIsFileUrl      = UrlIsFileUrlA
MACRO UrlGetLocation    = UrlGetLocationA
MACRO UrlUnescape       = UrlUnescapeA
MACRO UrlEscape         = UrlEscapeA
MACRO UrlCreateFromPath = UrlCreateFromPathA
MACRO PathCreateFromUrl = PathCreateFromUrlA
MACRO UrlHash           = UrlHashA
MACRO UrlGetPart        = UrlGetPartA
MACRO UrlApplyScheme    = UrlApplySchemeA
MACRO UrlIs             = UrlIsA
' no UrlFixupA
#ENDIF ' %UNICODE

MACRO UrlEscapeSpaces(pszUrl, pszEscaped, pcchEscaped)
    UrlCanonicalize pszUrl, pszEscaped, pcchEscaped, _
        %URL_ESCAPE_SPACES_ONLY OR %URL_DONT_ESCAPE_EXTRA_INFO
END MACRO

MACRO UrlUnescapeInPlace(pszUrl, dwFlags)
    UrlUnescape pszUrl, BYVAL %NULL, BYVAL %NULL, _
        dwFlags OR %URL_UNESCAPE_INPLACE
END MACRO

#IF (%WIN32_IE >= %WIN32_IE_IE50)

TYPE PARSEDURLA
    cbSize      AS DWORD
    ' Pointers into the buffer that was provided to ParseURL
    pszProtocol AS ASCIIZ PTR
    cchProtocol AS DWORD
    pszSuffix   AS ASCIIZ PTR
    cchSuffix   AS DWORD
    nScheme     AS DWORD            ' One of URL_SCHEME_*
END TYPE

TYPE PARSEDURLW
    cbSize      AS DWORD
    ' Pointers into the buffer that was provided to ParseURL
    pszProtocol AS WSTRINGZ PTR
    cchProtocol AS DWORD
    pszSuffix   AS WSTRINGZ PTR
    cchSuffix   AS DWORD
    nScheme     AS DWORD            ' One of URL_SCHEME_*
END TYPE

#IF %DEF(%UNICODE)
TYPE PARSEDURL
    PARSEDURLW
END TYPE
#ELSE
TYPE PARSEDURL
    PARSEDURLA
END TYPE
#ENDIF ' %UNICODE

DECLARE FUNCTION ParseURLA LIB "ShlWApi.dll" ALIAS "ParseURLA" _
    (pcszURL AS ASCIIZ, ppu AS PARSEDURLA) AS LONG

DECLARE FUNCTION ParseURLW LIB "ShlWApi.dll" ALIAS "ParseURLW" _
    (pcszURL AS WSTRINGZ, ppu AS PARSEDURLA) AS LONG

#IF %DEF(%UNICODE)
MACRO ParseURL=ParseURLW
#ELSE
MACRO ParseURL=ParseURLA
#ENDIF ' NOT %UNICODE

#ENDIF  ' %WIN32_IE_IE50

#ENDIF  ' #IF NOT %DEF(%NO_SHLWAPI_PATH)



#IF NOT %DEF(%NO_SHLWAPI_REG)

'=============== Registry Routines ===================================

' SHDeleteEmptyKey mimics RegDeleteKey as it behaves on NT.
' SHDeleteKey mimics RegDeleteKey as it behaves on Win95.

DECLARE FUNCTION SHDeleteEmptyKeyA LIB "ShlWApi.dll" _
    ALIAS "SHDeleteEmptyKeyA" (BYVAL hkey AS DWORD, pszSubKey AS ASCIIZ) _
    AS DWORD

DECLARE FUNCTION SHDeleteEmptyKeyW LIB "ShlWApi.dll" _
    ALIAS "SHDeleteEmptyKeyW" (BYVAL hkey AS DWORD, pszSubKey AS WSTRINGZ) _
    AS DWORD

#IF %DEF(%UNICODE)
MACRO SHDeleteEmptyKey=SHDeleteEmptyKeyW
#ELSE
MACRO SHDeleteEmptyKey=SHDeleteEmptyKeyA
#ENDIF

DECLARE FUNCTION SHDeleteKeyA LIB "ShlWApi.dll" ALIAS "SHDeleteKeyA" _
    (BYVAL hkey AS DWORD, pszSubKey AS ASCIIZ) AS DWORD

DECLARE FUNCTION SHDeleteKeyW LIB "ShlWApi.dll" ALIAS "SHDeleteKeyW" _
    (BYVAL hkey AS DWORD, pszSubKey AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
MACRO SHDeleteKey=SHDeleteKeyW
#ELSE
MACRO SHDeleteKey=SHDeleteKeyA
#ENDIF

DECLARE FUNCTION SHRegDuplicateHKey LIB "ShlWApi.dll" _
    ALIAS "SHRegDuplicateHKey" (BYVAL hKey AS DWORD) AS DWORD


' These functions open the key, get/set/delete the value, then close
' the key.

DECLARE FUNCTION SHDeleteValueA LIB "ShlWApi.dll" ALIAS "SHDeleteValueA" _
    (BYVAL hkey AS DWORD, pszSubKey AS ASCIIZ, pszValue AS ASCIIZ) AS DWORD

DECLARE FUNCTION SHDeleteValueW LIB "ShlWApi.dll" ALIAS "SHDeleteValueW" _
    (BYVAL hkey AS DWORD, pszSubKey AS WSTRINGZ, pszValue AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
MACRO SHDeleteValue=SHDeleteValueW
#ELSE
MACRO SHDeleteValue=SHDeleteValueA
#ENDIF

DECLARE FUNCTION SHGetValueA LIB "ShlWApi.dll" ALIAS "SHGetValueA" _
    (BYVAL hkey AS DWORD, pszSubKey AS ASCIIZ, pszValue AS ASCIIZ, _
    pdwType AS DWORD, pvData AS ANY, pcbData AS DWORD) AS DWORD

DECLARE FUNCTION SHGetValueW LIB "ShlWApi.dll" ALIAS "SHGetValueW" _
    (BYVAL hkey AS DWORD, pszSubKey AS WSTRINGZ, pszValue AS WSTRINGZ, _
    pdwType AS DWORD, pvData AS ANY, pcbData AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
MACRO SHGetValue=SHGetValueW
#ELSE
MACRO SHGetValue=SHGetValueA
#ENDIF

DECLARE FUNCTION SHSetValueA LIB "ShlWApi.dll" ALIAS "SHSetValueA" _
    (BYVAL hkey AS DWORD, pszSubKey AS ASCIIZ, pszValue AS ASCIIZ, _
    BYVAL dwType AS DWORD, pvData AS ANY, BYVAL cbData AS DWORD) AS DWORD

DECLARE FUNCTION SHSetValueW LIB "ShlWApi.dll" ALIAS "SHSetValueW" _
    (BYVAL hkey AS DWORD, pszSubKey AS WSTRINGZ, pszValue AS WSTRINGZ, _
    BYVAL dwType AS DWORD, pvData AS ANY, BYVAL cbData AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
MACRO SHSetValue=SHSetValueW
#ELSE
MACRO SHSetValue=SHSetValueA
#ENDIF

#IF (%WIN32_IE >= &H0602)
'
' SRRF - Shell Registry Routine Flags (for SHRegGetValue)
'

'typedef int SRRF;

%SRRF_RT_REG_NONE       = &H00000001  ' restrict type to REG_NONE      (other data types will not return ERROR_SUCCESS)
%SRRF_RT_REG_SZ         = &H00000002  ' restrict type to REG_SZ        (other data types will not return ERROR_SUCCESS) (automatically converts REG_EXPAND_SZ to REG_SZ unless SRRF_NOEXPAND is specified)
%SRRF_RT_REG_EXPAND_SZ  = &H00000004  ' restrict type to REG_EXPAND_SZ (other data types will not return ERROR_SUCCESS) (must specify SRRF_NOEXPAND or SHRegGetValue will fail with ERROR_INVALID_PARAMETER)
%SRRF_RT_REG_BINARY     = &H00000008  ' restrict type to REG_BINARY    (other data types will not return ERROR_SUCCESS)
%SRRF_RT_REG_DWORD      = &H00000010  ' restrict type to REG_DWORD     (other data types will not return ERROR_SUCCESS)
%SRRF_RT_REG_MULTI_SZ   = &H00000020  ' restrict type to REG_MULTI_SZ  (other data types will not return ERROR_SUCCESS)
%SRRF_RT_REG_QWORD      = &H00000040  ' restrict type to REG_QWORD     (other data types will not return ERROR_SUCCESS)

%SRRF_RT_DWORD          = (%SRRF_RT_REG_BINARY OR %SRRF_RT_REG_DWORD) ' restrict type to *32-bit* SRRF_RT_REG_BINARY or SRRF_RT_REG_DWORD (other data types will not return ERROR_SUCCESS)
%SRRF_RT_QWORD          = (%SRRF_RT_REG_BINARY OR %SRRF_RT_REG_QWORD) ' restrict type to *64-bit* SRRF_RT_REG_BINARY or SRRF_RT_REG_DWORD (other data types will not return ERROR_SUCCESS)
%SRRF_RT_ANY            = &H0000ffff                               ' no type restriction

%SRRF_RM_ANY            = &H00000000  ' no mode restriction (default is to allow any mode)
%SRRF_RM_NORMAL         = &H00010000  ' restrict system startup mode to "normal boot"               (other startup modes will not return ERROR_SUCCESS)
%SRRF_RM_SAFE           = &H00020000  ' restrict system startup mode to "safe mode"                 (other startup modes will not return ERROR_SUCCESS)
%SRRF_RM_SAFENETWORK    = &H00040000  ' restrict system startup mode to "safe mode with networking" (other startup modes will not return ERROR_SUCCESS)

%SRRF_NOEXPAND          = &H10000000  ' do not automatically expand environment strings if value is of type REG_EXPAND_SZ
%SRRF_ZEROONFAILURE     = &H20000000  ' if pvData is not NULL, set content to all zeros on failure
%SRRF_NOVIRT            = &H40000000  ' if the requested key is virtualized, then fail with ERROR_FILE_NOT_FOUND


' Function:
'
'  SHRegGetValue()
'
' Purpose:
'
'  Gets a registry value.  SHRegGetValue() provides the following benefits:
'
'  - data type checking
'  - boot mode checking
'  - auto-expansion of REG_EXPAND_SZ data
'  - guaranteed NULL termination of REG_SZ, REG_EXPAND_SZ, REG_MULTI_SZ data
'
' Parameters:
'
'  hkey        - handle to a currently open key.
'
'  pszSubKey   - pointer to a null-terminated string specifying the relative
'                path from hkey to one of its subkeys from which the data is
'                to be retrieved.  this will be opened with KEY_READ sam.
'
'                Note1: pszSubKey can be NULL or "".  In either of these two
'                       cases, the data is retrieved from the hkey itself.
'                Note2: *** PERF ***
'                       If pszSubKey is not NULL or "", the subkey will be
'                       automatically be opened and closed by this routine
'                       in order to obtain the data.  If you are retrieving
'                       multiple values from the same subkey, it is better
'                       for perf to open the subkey via RegOpenKeyEx() prior
'                       to calling this method, and using this opened key as
'                       hkey with pszSubKey set to NULL.
'
'  pszValue    - pointer to a null-terminated string specifying the name of
'                the value to query for data
'
'                Note1: pszValue can be NULL or "".  In either of these two
'                       cases, the data is retrieved from the unnamed or
'                       default value.
'
'  srrfFlags   - bitwise or of SRRF_ flags, which cannot be 0:  at least one
'                type restriction must be specified (SRRF_RT_...), or if any
'                type is desired then SRRF_RT_ANY can be specified
'
'                Note1: SRRF_RT_ANY will allow any data type to be returned.
'                Note2: The following two type restrictions have special
'                       handling semantics:
'
'                         SRRF_RT_DWORD == SRRF_RT_REG_BINARY | SRRF_RT_REG_DWORD
'                         SRRF_RT_QWORD == SRRF_RT_REG_BINARY | SRRF_RT_REG_QWORD
'
'                       If either of these are specified, with no other type
'                       restrictions, then in the prior case the restriction
'                       will limit "valid" returned data to either REG_DWORD
'                       or 32-bit REG_BINARY data, and in the latter case
'                       the restriction will limit "valid" returned data to
'                       either REG_QWORD or 64-bit REG_BINARY.
'
'  pdwType     - pointer to a dword which receives a code indicating the
'                type of data stored in the specified value
'
'                Note1: pdwType can be NULL if no type information is wanted
'                Note2: If pdwType is not NULL, and the SRRF_NOEXPAND flag
'                       has not been set, data types of REG_EXPAND_SZ will
'                       be returned as REG_SZ since they are automatically
'                       expanded in this method.
'
'  pvData      - pointer to a buffer that receives the value's data
'
'                Note1: pvData can be NULL if the data is not required.
'                       pvData is usually NULL if doing either a simple
'                       existence test, or if interested in the size only.
'                Note2: *** PERF ***
'                       Reference 'perf' note for pcbData.
'
'  pcbData     - when pvData is NULL:
'                  optional pointer to a dword that receives a size in bytes
'                  which would be sufficient to hold the registry data (note
'                  this size is not guaranteed to be exact, merely sufficient)
'                when pvData is not NULL:
'                  required pointer to a dword that specifies the size in
'                  bytes of the buffer pointed to by the pvData parameter
'                  and receives a size in bytes of:
'                  a) the number of bytes read into pvData on ERROR_SUCCESS
'                     (note this size is guaranteed to be exact)
'                  b) the number of bytes which would be sufficient to hold
'                     the registry data on ERROR_MORE_DATA -- pvData was of
'                     insufficient size (note this size is not guaranteed to
'                     be exact, merely sufficient)
'
'                Note1: pcbData can be NULL only if pvData is NULL.
'                Note2: *** PERF ***
'                       The potential for an 'extra' call to the registry to
'                       read (or re-read) in the data exists when the data
'                       type is REG_EXPAND_SZ and the SRRF_NOEXPAND flag has
'                       not been set.  The following conditions will result
'                       in this 'extra' read operation:
'                       i)  when pvData is NULL and pcbData is not NULL
'                           we must read in the data from the registry
'                           anyway in order to obtain the string and perform
'                           an expand on it to obtain and return the total
'                           required size in pcbData
'                       ii) when pvData is not NULL but is of insufficient
'                           size we must re-read in the data from the
'                           registry in order to obtain the entire string
'                           and perform an expand on it to obtain and return
'                           the total required size in pcbData
'
' Remarks:
'
'  The key identified by hkey must have been opened with KEY_QUERY_VALUE
'  access.  If pszSubKey is not NULL or "", it must be able to be opened
'  with KEY_QUERY_VALUE access in the current calling context.
'
'  If the data type is REG_SZ, REG_EXPAND_SZ or REG_MULTI_SZ then any
'  returned data is guaranteed to take into account proper null termination.
'  For example:  if pcbData is not NULL, its returned size will include the
'  bytes for a null terminator  if pvData is not NULL, its returned data
'  will be properly null terminated.
'
'  If the data type is REG_EXPAND_SZ, then unless the SRRF_NOEXPAND flag
'  is set the data will be automatically expanded prior to being returned.
'  For example:  if pdwType is not NULL, its returned type will be changed
'  to REG_SZ,  if pcbData is not NULL, its returned size will include the
'  bytes for a properly expanded string.  if pvData is not NULL, its
'  returned data will be the expanded version of the string.
'
'  Reference MSDN documentation for RegQueryValueEx() for more information
'  of the behaviour when pdwType, pvData, and/or pcbData are equal to NULL.
'
' Return Values:
'
'  If the function succeeds, the return value is ERROR_SUCCESS and all out
'  parameters requested (pdwType, pvData, pcbData) are valid.
'
'  If the function fails due to insufficient space in a provided non-NULL
'  pvData, the return value is ERROR_MORE_DATA and only pdwType and pcbData
'  can contain valid data.  The content of pvData in this case is undefined.
'
' Examples:
'
'  1) read REG_SZ (or REG_EXPAND_SZ as REG_SZ) "string" data from the (default) value of an open hkey
'
'      TCHAR szData[128]
'      DWORD cbData = sizeof(pszData)
'      if (ERROR_SUCCESS == SHRegGetValue(hkey, NULL, NULL, SRRF_RT_REG_SZ, NULL, szData, &cbData))
'      {
'          ' use sz (successful read)
'      }
'
'  2) read REG_SZ (or REG_EXPAND_SZ as REG_SZ) "string" data of unknown size from the "MyValue" value of an open hkey
'
'      DWORD cbData
'      if (ERROR_SUCCESS == SHRegGetValue(hkey, NULL, TEXT("MyValue"), SRRF_RT_REG_SZ, NULL, NULL, &cbData))
'      {
'          TCHAR *pszData = new TCHAR[cbData/sizeof(TCHAR)]
'          if (pszData)
'          {
'              if (ERROR_SUCCESS == SHRegGetValue(hkey, NULL, TEXT("MyValue"), SRRF_RT_REG_SZ, NULL, pszData, &cbData))
'              {
'                  ' use pszData (successful read)
'              }
'              delete[] pszData
'          }
'      }
'
'  3) read "dword" data from the "MyValue" value of the "MySubKey" subkey of an open hkey
'
'      DWORD dwData
'      DWORD cbData = sizeof(dwData)
'      if (ERROR_SUCCESS == SHRegGetValue(hkey, TEXT("MySubKey"), TEXT("MyValue"), SRRF_RT_REG_DWORD, NULL, &dwData, &cbData))
'      {
'          ' use dwData (successful read)
'      }
'
'  4) read "dword" data from the "MyValue" value of the "MySubKey" subkey of an open hkey (32-bit binary data also ok)
'
'      DWORD dwData
'      DWORD cbData = sizeof(dwData)
'      if (ERROR_SUCCESS == SHRegGetValue(hkey, TEXT("MySubKey"), TEXT("MyValue"), SRRF_RT_DWORD, NULL, &dwData, &cbData))
'      {
'          ' use dwData (successful read)
'      }
'
'  5) determine existence of "MyValue" value of an open hkey
'
'      BOOL bExists = ERROR_SUCCESS == SHRegGetValue(hkey, NULL, TEXT("MyValue"), SRRF_RT_ANY, NULL, NULL, NULL)


DECLARE FUNCTION SHRegGetValueA LIB "ShlWApi.dll" ALIAS "SHRegGetValueA" _
    (BYVAL hKey AS DWORD, pszSubKey AS ASCIIZ, pszValue AS ASCIIZ, _
    BYVAL srrfFlags AS LONG, pdwType AS DWORD, pvData AS ANY, _
    pcbData AS DWORD) AS LONG

DECLARE FUNCTION SHRegGetValueW LIB "ShlWApi.dll" ALIAS "SHRegGetValueW" _
    (BYVAL hKey AS DWORD, pszSubKey AS WSTRINGZ, pszValue AS WSTRINGZ, _
    BYVAL srrfFlags AS LONG, pdwType AS DWORD, pvData AS ANY, _
    pcbData AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO SHRegGetValue=SHRegGetValueW
#ELSE
MACRO SHRegGetValue=SHRegGetValueA
#ENDIF

' [officially "not supported" as well as not exported. so why are they here?]
'DECLARE FUNCTION SHRegSetValue LIB "ShlWApi.dll" ALIAS "SHRegSetValue" _
'    (BYVAL hKey AS DWORD, pszSubKey AS ASCIIZ, pszValue AS ASCIIZ, _
'    BYVAL srrfFlags AS LONG, BYVAL dwType AS DWORD, pvData AS ANY, _
'    BYVAL cbData AS DWORD) AS LONG
'
'DECLARE FUNCTION SHRegGetValueFromHKCUHKLM LIB "ShlWApi.dll" _
'    ALIAS "SHRegGetValueFromHKCUHKLM" (pswzKey AS WSTRINGZ, _
'    pwszValue AS WSTRINGZ, BYVAL srrfFlags AS LONG, pvData AS ANY, _
'    pcbData AS DWORD) AS LONG
'
'DECLARE FUNCTION SHRegGetBoolValueFromHKCUHKLM LIB "ShlWApi.dll" _
'    ALIAS "SHRegGetBoolValueFromHKCUHKLM" (pszKey AS WSTRINGZ, _
'    pszValue AS WSTRINGZ, BYVAL fDefault AS LONG) AS LONG

#ENDIF  ' (%WIN32_IE >= &H0602)


' These functions behave just like RegQueryValueEx(), except if the data
' type is REG_SZ, REG_EXPAND_SZ or REG_MULTI_SZ then the string is
' guaranteed to be properly null terminated.
'
' Additionally, if the data type is REG_EXPAND_SZ these functions will
' go ahead and expand out the string, and "massage" the returned *pdwType
' to be REG_SZ.

DECLARE FUNCTION SHQueryValueExA LIB "ShlWApi.dll" ALIAS "SHQueryValueExA" _
    (BYVAL hkey AS DWORD, pszValue AS ASCIIZ, pdwReserved AS DWORD, _
    pdwType AS DWORD, pvData AS ANY, pcbData AS DWORD) AS LONG

DECLARE FUNCTION SHQueryValueExW LIB "ShlWApi.dll" ALIAS "SHQueryValueExW" _
    (BYVAL hkey AS DWORD, pszValue AS WSTRINGZ, pdwReserved AS DWORD, _
    pdwType AS DWORD, pvData AS ANY, pcbData AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO SHQueryValueEx=SHQueryValueExW
#ELSE
MACRO SHQueryValueEx=SHQueryValueExA
#ENDIF

' Enumeration functions support.

DECLARE FUNCTION SHEnumKeyExA LIB "ShlWApi.dll" ALIAS "SHEnumKeyExA" _
    (BYVAL hkey AS DWORD, BYVAL dwIndex AS DWORD, pszName AS ASCIIZ, _
    pcchName AS DWORD) AS LONG

DECLARE FUNCTION SHEnumKeyExW LIB "ShlWApi.dll" ALIAS "SHEnumKeyExW" _
    (BYVAL hkey AS DWORD, BYVAL dwIndex AS DWORD, pszName AS WSTRINGZ, _
    pcchName AS DWORD) AS LONG

DECLARE FUNCTION SHEnumValueA LIB "ShlWApi.dll" ALIAS "SHEnumValueA" _
    (BYVAL hkey AS DWORD, BYVAL dwIndex AS DWORD, pszValueName AS ASCIIZ, _
    pcchValueName AS DWORD, pdwType AS DWORD, pvData AS ANY, _
    pcbData AS DWORD) AS LONG

DECLARE FUNCTION SHEnumValueW LIB "ShlWApi.dll" ALIAS "SHEnumValueW" _
    (BYVAL hkey AS DWORD, BYVAL dwIndex AS DWORD, pszValueName AS WSTRINGZ, _
    pcchValueName AS DWORD, pdwType AS DWORD, pvData AS ANY, _
    pcbData AS DWORD) AS LONG

DECLARE FUNCTION SHQueryInfoKeyA LIB "ShlWApi.dll" ALIAS "SHQueryInfoKeyA" _
    (BYVAL hkey AS DWORD, pcSubKeys AS DWORD, pcchMaxSubKeyLen AS DWORD, _
    pcValues AS DWORD, pcchMaxValueNameLen AS DWORD) AS LONG

DECLARE FUNCTION SHQueryInfoKeyW LIB "ShlWApi.dll" ALIAS "SHQueryInfoKeyW" _
    (BYVAL hkey AS DWORD, pcSubKeys AS DWORD, pcchMaxSubKeyLen AS DWORD, _
    pcValues AS DWORD, pcchMaxValueNameLen AS DWORD) AS LONG

' recursive key copy
DECLARE FUNCTION SHCopyKeyA LIB "ShlWApi.dll" ALIAS "SHCopyKeyA" _
    (BYVAL hkeySrc AS DWORD, szSrcSubKey AS ASCIIZ, BYVAL hKeyDest AS DWORD, _
    BYVAL fReserved AS DWORD) AS LONG

' recursive key copy
DECLARE FUNCTION SHCopyKeyW LIB "ShlWApi.dll" ALIAS "SHCopyKeyW" _
    (BYVAL hkeySrc AS DWORD, szSrcSubKey AS WSTRINGZ, _
    BYVAL hKeyDest AS DWORD, BYVAL fReserved AS DWORD) AS LONG

' Getting and setting file system paths with environment variables

DECLARE FUNCTION SHRegGetPathA LIB "ShlWApi.dll" ALIAS "SHRegGetPathA" _
    (BYVAL hKey AS DWORD, pcszSubKey AS ASCIIZ, pcszValue AS ASCIIZ, _
    pszPath AS ASCIIZ, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION SHRegGetPathW LIB "ShlWApi.dll" ALIAS "SHRegGetPathW" _
    (BYVAL hKey AS DWORD, pcszSubKey AS WSTRINGZ, pcszValue AS WSTRINGZ, _
    pszPath AS WSTRINGZ, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION SHRegSetPathA LIB "ShlWApi.dll" ALIAS "SHRegSetPathA" _
    (BYVAL hKey AS DWORD, pcszSubKey AS ASCIIZ, pcszValue AS ASCIIZ, _
    pszPath AS ASCIIZ, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION SHRegSetPathW LIB "ShlWApi.dll" ALIAS "SHRegSetPathW" _
    (BYVAL hKey AS DWORD, pcszSubKey AS WSTRINGZ, pcszValue AS WSTRINGZ, _
    pszPath AS WSTRINGZ, BYVAL dwFlags AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO SHEnumKeyEx    = SHEnumKeyExW
MACRO SHEnumValue    = SHEnumValueW
MACRO SHQueryInfoKey = SHQueryInfoKeyW
MACRO SHCopyKey      = SHCopyKeyW
MACRO SHRegGetPath   = SHRegGetPathW
MACRO SHRegSetPath   = SHRegSetPathW
#ELSE
MACRO SHEnumKeyEx    = SHEnumKeyExA
MACRO SHEnumValue    = SHEnumValueA
MACRO SHQueryInfoKey = SHQueryInfoKeyA
MACRO SHCopyKey      = SHCopyKeyA
MACRO SHRegGetPath   = SHRegGetPathA
MACRO SHRegSetPath   = SHRegSetPathA
#ENDIF


'--------------------------------------------
' User Specific Registry Access Functions
'--------------------------------------------

' Type definitions.


' enumerated type SHREGDEL_FLAGS
%SHREGDEL_DEFAULT = &H00000000   ' Deletes HKCU, or HKLM if HKCU is not found.
%SHREGDEL_HKCU    = &H00000001   ' Delete HKCU only
%SHREGDEL_HKLM    = &H00000010   ' Delete HKLM only.
%SHREGDEL_BOTH    = &H00000011   ' Delete both HKCU and HKLM.

' enumerated type SHREGENUM_FLAGS
%SHREGENUM_DEFAULT = &H00000000   ' Enumerates HKCU or HKLM if not found.
%SHREGENUM_HKCU    = &H00000001   ' Enumerates HKCU only
%SHREGENUM_HKLM    = &H00000010   ' Enumerates HKLM only.
%SHREGENUM_BOTH    = &H00000011   ' Enumerates both HKCU and HKLM without duplicates.

%SHREGSET_HKCU       = &H00000001   ' Write to HKCU if empty.
%SHREGSET_FORCE_HKCU = &H00000002   ' Write to HKCU.
%SHREGSET_HKLM       = &H00000004   ' Write to HKLM if empty.
%SHREGSET_FORCE_HKLM = &H00000008   ' Write to HKLM.
%SHREGSET_DEFAULT    = (%SHREGSET_FORCE_HKCU OR %SHREGSET_HKLM) ' Default

'typedef DWORD HUSKEY;  ' HUSKEY is a Handle to a User Specific KEY.
'typedef HUSKEY *PHUSKEY;

DECLARE FUNCTION SHRegCreateUSKeyA LIB "ShlWApi.dll" _
    ALIAS "SHRegCreateUSKeyA" (pszPath AS ASCIIZ, _
    BYVAL samDesired AS DWORD, BYVAL hRelativeUSKey AS DWORD, _
    phNewUSKey AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION SHRegCreateUSKeyW LIB "ShlWApi.dll" _
    ALIAS "SHRegCreateUSKeyW" (pszPath AS WSTRINGZ, _
    BYVAL samDesired AS DWORD, BYVAL hRelativeUSKey AS DWORD, _
    phNewUSKey AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION SHRegOpenUSKeyA LIB "ShlWApi.dll" ALIAS "SHRegOpenUSKeyA" _
    (pszPath AS ASCIIZ, BYVAL samDesired AS DWORD, _
    BYVAL hRelativeUSKey AS DWORD, phNewUSKey AS DWORD, _
    BYVAL fIgnoreHKCU AS LONG) AS LONG

DECLARE FUNCTION SHRegOpenUSKeyW LIB "ShlWApi.dll" ALIAS "SHRegOpenUSKeyW" _
    (pszPath AS WSTRINGZ, BYVAL samDesired AS DWORD, _
    BYVAL hRelativeUSKey AS DWORD, phNewUSKey AS DWORD, _
    BYVAL fIgnoreHKCU AS LONG) AS LONG

DECLARE FUNCTION SHRegQueryUSValueA LIB "ShlWApi.dll" _
    ALIAS "SHRegQueryUSValueA" (BYVAL hUSKey AS DWORD, pszValue AS ASCIIZ, _
    pdwType AS DWORD, pvData AS ANY, pcbData AS DWORD, _
    BYVAL fIgnoreHKCU AS LONG, pvDefaultData AS ANY, _
    BYVAL dwDefaultDataSize AS DWORD) AS LONG

DECLARE FUNCTION SHRegQueryUSValueW LIB "ShlWApi.dll" _
    ALIAS "SHRegQueryUSValueW" (BYVAL hUSKey AS DWORD, pszValue AS WSTRINGZ, _
    pdwType AS DWORD, pvData AS ANY, pcbData AS DWORD, _
    BYVAL fIgnoreHKCU AS LONG, pvDefaultData AS ANY, _
    BYVAL dwDefaultDataSize AS DWORD) AS LONG

DECLARE FUNCTION SHRegWriteUSValueA LIB "ShlWApi.dll" _
    ALIAS "SHRegWriteUSValueA" (BYVAL hUSKey AS DWORD, pszValue AS ASCIIZ, _
    BYVAL dwType AS DWORD, pvData AS ANY, BYVAL cbData AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION SHRegWriteUSValueW LIB "ShlWApi.dll" _
    ALIAS "SHRegWriteUSValueW" (BYVAL hUSKey AS DWORD, pszValue AS WSTRINGZ, _
    BYVAL dwType AS DWORD, pvData AS ANY, BYVAL cbData AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION SHRegDeleteUSValueA LIB "ShlWApi.dll" _
    ALIAS "SHRegDeleteUSValueA" (BYVAL hUSKey AS DWORD, pszValue AS ASCIIZ, _
    BYVAL delRegFlags AS LONG) AS LONG

DECLARE FUNCTION SHRegDeleteUSValueW LIB "ShlWApi.dll" _
    ALIAS "SHRegDeleteUSValueW" (BYVAL hUSKey AS DWORD, pszValue AS WSTRINGZ, _
    BYVAL delRegFlags AS LONG) AS LONG

DECLARE FUNCTION SHRegDeleteEmptyUSKeyA LIB "ShlWApi.dll" _
    ALIAS "SHRegDeleteEmptyUSKeyA" (BYVAL hUSKey AS DWORD, _
    pszSubKey AS ASCIIZ, BYVAL delRegFlags AS LONG) AS LONG

DECLARE FUNCTION SHRegDeleteEmptyUSKeyW LIB "ShlWApi.dll" _
    ALIAS "SHRegDeleteEmptyUSKeyW" (BYVAL hUSKey AS DWORD, _
    pszSubKey AS WSTRINGZ, BYVAL delRegFlags AS LONG) AS LONG

DECLARE FUNCTION SHRegEnumUSKeyA LIB "ShlWApi.dll" ALIAS "SHRegEnumUSKeyA" _
    (BYVAL hUSKey AS DWORD, BYVAL dwIndex AS DWORD, pszName AS ASCIIZ, _
    pcchName AS DWORD, BYVAL enumRegFlags AS LONG) AS LONG

DECLARE FUNCTION SHRegEnumUSKeyW LIB "ShlWApi.dll" ALIAS "SHRegEnumUSKeyW" _
    (BYVAL hUSKey AS DWORD, BYVAL dwIndex AS DWORD, pszName AS WSTRINGZ, _
    pcchName AS DWORD, BYVAL enumRegFlags AS LONG) AS LONG

DECLARE FUNCTION SHRegEnumUSValueA LIB "ShlWApi.dll" _
    ALIAS "SHRegEnumUSValueA" (BYVAL hUSkey AS DWORD, BYVAL dwIndex AS DWORD, _
    pszValueName AS ASCIIZ, pcchValueName AS DWORD, pdwType AS DWORD, _
    pvData AS ANY, pcbData AS DWORD, BYVAL enumRegFlags AS LONG) AS LONG

DECLARE FUNCTION SHRegEnumUSValueW LIB "ShlWApi.dll" _
    ALIAS "SHRegEnumUSValueW" (BYVAL hUSkey AS DWORD, BYVAL dwIndex AS DWORD, _
    pszValueName AS ASCIIZ, pcchValueName AS DWORD, pdwType AS DWORD, _
    pvData AS ANY, pcbData AS DWORD, BYVAL enumRegFlags AS LONG) AS LONG

DECLARE FUNCTION SHRegQueryInfoUSKeyA LIB "ShlWApi.dll" _
    ALIAS "SHRegQueryInfoUSKeyA" (BYVAL hUSKey AS DWORD, pcSubKeys AS DWORD, _
    pcchMaxSubKeyLen AS DWORD, pcValues AS DWORD, _
    pcchMaxValueNameLen AS DWORD, BYVAL enumRegFlags AS LONG) AS LONG

DECLARE FUNCTION SHRegQueryInfoUSKeyW LIB "ShlWApi.dll" _
    ALIAS "SHRegQueryInfoUSKeyW" (BYVAL hUSKey AS DWORD, pcSubKeys AS DWORD, _
    pcchMaxSubKeyLen AS DWORD, pcValues AS DWORD, _
    pcchMaxValueNameLen AS DWORD, BYVAL enumRegFlags AS LONG) AS LONG

DECLARE FUNCTION SHRegCloseUSKey LIB "ShlWApi.dll" ALIAS "SHRegCloseUSKey" _
    (BYVAL hUSKey AS DWORD) AS LONG


' These calls are equal to an SHRegOpenUSKey, SHRegQueryUSValue, and then a SHRegCloseUSKey.

DECLARE FUNCTION SHRegGetUSValueA LIB "ShlWApi.dll" ALIAS "SHRegGetUSValueA" _
    (pszSubKey AS ASCIIZ, pszValue AS ASCIIZ, pdwType AS DWORD, _
    pvData AS ANY, pcbData AS DWORD, BYVAL fIgnoreHKCU AS LONG, _
    pvDefaultData AS ANY, BYVAL dwDefaultDataSize AS DWORD) AS LONG

DECLARE FUNCTION SHRegGetUSValueW LIB "ShlWApi.dll" ALIAS "SHRegGetUSValueW" _
    (pszSubKey AS WSTRINGZ, pszValue AS WSTRINGZ, pdwType AS DWORD, _
    pvData AS ANY, pcbData AS DWORD, BYVAL fIgnoreHKCU AS LONG, _
    pvDefaultData AS ANY, BYVAL dwDefaultDataSize AS DWORD) AS LONG

DECLARE FUNCTION SHRegSetUSValueA LIB "ShlWApi.dll" ALIAS "SHRegSetUSValueA" _
    (pszSubKey AS ASCIIZ, pszValue AS ASCIIZ, BYVAL dwType AS DWORD, _
    pvData AS ANY, BYVAL cbData AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION SHRegSetUSValueW LIB "ShlWApi.dll" ALIAS "SHRegSetUSValueW" _
    (pszSubKey AS WSTRINGZ, pszValue AS WSTRINGZ, BYVAL dwType AS DWORD, _
    pvData AS ANY, BYVAL cbData AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION SHRegGetIntW LIB "ShlWApi.dll" ALIAS "SHRegGetIntW" _
    (BYVAL hk AS DWORD, pwzKey AS WSTRINGZ, BYVAL iDefault AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO SHRegCreateUSKey      = SHRegCreateUSKeyW
MACRO SHRegOpenUSKey        = SHRegOpenUSKeyW
MACRO SHRegQueryUSValue     = SHRegQueryUSValueW
MACRO SHRegWriteUSValue     = SHRegWriteUSValueW
MACRO SHRegDeleteUSValue    = SHRegDeleteUSValueW
MACRO SHRegDeleteEmptyUSKey = SHRegDeleteEmptyUSKeyW
MACRO SHRegEnumUSKey        = SHRegEnumUSKeyW
MACRO SHRegEnumUSValue      = SHRegEnumUSValueW
MACRO SHRegQueryInfoUSKey   = SHRegQueryInfoUSKeyW
MACRO SHRegGetUSValue       = SHRegGetUSValueW
MACRO SHRegSetUSValue       = SHRegSetUSValueW
MACRO SHRegGetInt           = SHRegGetIntW
#ELSE
MACRO SHRegCreateUSKey      = SHRegCreateUSKeyA
MACRO SHRegOpenUSKey        = SHRegOpenUSKeyA
MACRO SHRegQueryUSValue     = SHRegQueryUSValueA
MACRO SHRegWriteUSValue     = SHRegWriteUSValueA
MACRO SHRegDeleteUSValue    = SHRegDeleteUSValueA
MACRO SHRegDeleteEmptyUSKey = SHRegDeleteEmptyUSKeyA
MACRO SHRegEnumUSKey        = SHRegEnumUSKeyA
MACRO SHRegEnumUSValue      = SHRegEnumUSValueA
MACRO SHRegQueryInfoUSKey   = SHRegQueryInfoUSKeyA
MACRO SHRegGetUSValue       = SHRegGetUSValueA
MACRO SHRegSetUSValue       = SHRegSetUSValueA
#ENDIF


DECLARE FUNCTION SHRegGetBoolUSValueA LIB "ShlWApi.dll" _
    ALIAS "SHRegGetBoolUSValueA" (pszSubKey AS ASCIIZ, _
    pszValue AS ASCIIZ, BYVAL fIgnoreHKCU AS LONG, BYVAL fDefault AS LONG) _
    AS LONG

DECLARE FUNCTION SHRegGetBoolUSValueW LIB "ShlWApi.dll" _
    ALIAS "SHRegGetBoolUSValueW" (pszSubKey AS WSTRINGZ, _
    pszValue AS WSTRINGZ, BYVAL fIgnoreHKCU AS LONG, BYVAL fDefault AS LONG) _
    AS LONG

#IF %DEF(%UNICODE)
MACRO SHRegGetBoolUSValue=SHRegGetBoolUSValueW
#ELSE
MACRO SHRegGetBoolUSValue=SHRegGetBoolUSValueA
#ENDIF


'  Association APIs
'
'  these APIs are to assist in accessing the data in HKCR
'  getting the Command strings and exe paths
'  for different verbs and extensions are simplified this way

%ASSOCF_INIT_NOREMAPCLSID    = &H00000001  ' do not remap clsids to progids
%ASSOCF_INIT_BYEXENAME       = &H00000002  ' executable is being passed in
%ASSOCF_OPEN_BYEXENAME       = &H00000002  ' executable is being passed in
%ASSOCF_INIT_DEFAULTTOSTAR   = &H00000004  ' treat "*" as the BaseClass
%ASSOCF_INIT_DEFAULTTOFOLDER = &H00000008  ' treat "Folder" as the BaseClass
%ASSOCF_NOUSERSETTINGS       = &H00000010  ' don't use HKCU
%ASSOCF_NOTRUNCATE           = &H00000020  ' don't truncate the return string
%ASSOCF_VERIFY               = &H00000040  ' verify data is accurate (DISK HITS)
%ASSOCF_REMAPRUNDLL          = &H00000080  ' actually gets info about rundlls target if applicable
%ASSOCF_NOFIXUPS             = &H00000100  ' attempt to fix errors if found
%ASSOCF_IGNOREBASECLASS      = &H00000200  ' don't recurse into the baseclass
%ASSOCF_INIT_IGNOREUNKNOWN   = &H00000400  ' don't use the "Unknown" progid, instead fail

'typedef DWORD ASSOCF;


' enumerated type ASSOCSTR
%ASSOCSTR_COMMAND         = 1   ' shell\verb\command string
%ASSOCSTR_EXECUTABLE      = 2   ' the executable part of command string
%ASSOCSTR_FRIENDLYDOCNAME = 3   ' friendly name of the document type
%ASSOCSTR_FRIENDLYAPPNAME = 4   ' friendly name of executable
%ASSOCSTR_NOOPEN          = 5   ' noopen value
%ASSOCSTR_SHELLNEWVALUE   = 6   ' query values under the shellnew key
%ASSOCSTR_DDECOMMAND      = 7   ' template for DDE commands
%ASSOCSTR_DDEIFEXEC       = 8   ' DDECOMMAND to use if just create a process
%ASSOCSTR_DDEAPPLICATION  = 9   ' Application name in DDE broadcast
%ASSOCSTR_DDETOPIC        = 10  ' Topic Name in DDE broadcast
%ASSOCSTR_INFOTIP         = 11  ' info tip for an item, or list of properties to create info tip from
#IF (%WIN32_IE >= %WIN32_IE_IE60)
%ASSOCSTR_QUICKTIP        = 12  ' same as ASSOCSTR_INFOTIP, except, this list contains only quickly retrievable properties
%ASSOCSTR_TILEINFO        = 13  ' similar to ASSOCSTR_INFOTIP - lists important properties for tileview
%ASSOCSTR_CONTENTTYPE     = 14  ' MIME Content type
%ASSOCSTR_DEFAULTICON     = 15  ' Default icon source
%ASSOCSTR_SHELLEXTENSION  = 16  ' Guid string pointing to the Shellex\Shellextensionhandler value.
#ENDIF ' %WIN32_IE_IE60
#IF (%WIN32_IE >= %WIN32_IE_IE80)
%ASSOCSTR_DROPTARGET      = 17  ' The CLSID of DropTarget
%ASSOCSTR_DELEGATEEXECUTE = 18  ' The CLSID of DelegateExecute
#ENDIF ' %WIN32_IE_IE80
'%ASSOCSTR_MAX             = varies  ' last item in enum...

' enumerated type ASSOCKEY
%ASSOCKEY_SHELLEXECCLASS = 1    ' the key that should be passed to ShellExec(hkeyClass)
%ASSOCKEY_APP            = 2    ' the "Application" key for the association
%ASSOCKEY_CLASS          = 3    ' the progid or class key
%ASSOCKEY_BASECLASS      = 4    ' the BaseClass key
%ASSOCKEY_MAX            = 5    ' last item in enum...

' enumerated type ASSOCDATA
%ASSOCDATA_MSIDESCRIPTOR     = 1  ' Component Descriptor to pass to MSI APIs
%ASSOCDATA_NOACTIVATEHANDLER = 2  ' restrict attempts to activate window
%ASSOCDATA_QUERYCLASSSTORE   = 3  ' should check with the NT Class Store
%ASSOCDATA_HASPERUSERASSOC   = 4  ' defaults to user specified association
#IF (%WIN32_IE >= %WIN32_IE_IE60)
%ASSOCDATA_EDITFLAGS         = 5  ' Edit flags.
%ASSOCDATA_VALUE             = 6  ' use pszExtra as the Value name
%ASSOCDATA_MAX               = 7
#ELSE
%ASSOCDATA_MAX               = 5
#ENDIF ' %WIN32_IE_IE60

' enumerated type ASSOCENUM
%ASSOCENUM_NONE = 0

'DECLARE_INTERFACE_IID_( IQueryAssociations, IUnknown, "c46ca590-3c3f-11d2-bee6-0000f805ca57" )
'{
'    ' IUnknown methods
'    STDMETHOD (QueryInterface)(THIS_ REFIID riid, void **ppv) PURE;
'    STDMETHOD_(ULONG, AddRef) ( THIS ) PURE;
'    STDMETHOD_(ULONG, Release) ( THIS ) PURE;
'
'    ' IQueryAssociations methods
'    STDMETHOD (Init)(THIS_ ASSOCF flags, LPCWSTR pszAssoc, HKEY hkProgid, DWORD hwnd) PURE;
'    STDMETHOD (GetString)(THIS_ ASSOCF flags, ASSOCSTR str, LPCWSTR pszExtra, __out_ecount_opt(*pcchOut) LPWSTR pszOut, __inout DWORD *pcchOut) PURE;
'    STDMETHOD (GetKey)(THIS_ ASSOCF flags, ASSOCKEY key, LPCWSTR pszExtra, HKEY *phkeyOut) PURE;
'    STDMETHOD (GetData)(THIS_ ASSOCF flags, ASSOCDATA data, LPCWSTR pszExtra, __out_bcount_opt(*pcbOut) void * pvOut, __inout_opt DWORD *pcbOut) PURE;
'    STDMETHOD (GetEnum)(THIS_ ASSOCF flags, ASSOCENUM assocenum, LPCWSTR pszExtra, REFIID riid, void **ppvOut) PURE;
'};

' use CLSID_QueryAssociations for clsid, object implements IQueryAssociations
' AssocCreateForClasses() is the more functional version of this API
DECLARE FUNCTION AssocCreate LIB "ShlWApi.dll" ALIAS "AssocCreate" _
    (xclsid AS ANY, xriid AS ANY, BYVAL ppv AS DWORD) AS LONG

'  wrappers for the interface
DECLARE FUNCTION AssocQueryStringA LIB "ShlWApi.dll" _
    ALIAS "AssocQueryStringA" (BYVAL dFlags AS DWORD, BYVAL dStrType AS LONG, _
    pszAssoc AS ASCIIZ, pszExtra AS ASCIIZ, pszOut AS ASCIIZ, _
    pcchOut AS DWORD) AS LONG

DECLARE FUNCTION AssocQueryStringW LIB "ShlWApi.dll" _
    ALIAS "AssocQueryStringW" (BYVAL dFlags AS DWORD, BYVAL dStrType AS LONG, _
    pszAssoc AS WSTRINGZ, pszExtra AS WSTRINGZ, pszOut AS WSTRINGZ, _
    pcchOut AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO AssocQueryString=AssocQueryStringW
#ELSE
MACRO AssocQueryString=AssocQueryStringA
#ENDIF

DECLARE FUNCTION AssocQueryStringByKeyA LIB "ShlWApi.dll" _
    ALIAS "AssocQueryStringByKeyA" (BYVAL dFlags AS DWORD, _
    BYVAL dStrType AS LONG, BYVAL hkAssoc AS DWORD, pszExtra AS ASCIIZ, _
    pszOut AS ASCIIZ, pcchOut AS DWORD) AS LONG

DECLARE FUNCTION AssocQueryStringByKeyW LIB "ShlWApi.dll" _
    ALIAS "AssocQueryStringByKeyW" (BYVAL dFlags AS DWORD, _
    BYVAL dStrType AS LONG, BYVAL hkAssoc AS DWORD, pszExtra AS WSTRINGZ, _
    pszOut AS WSTRINGZ, pcchOut AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO AssocQueryStringByKey=AssocQueryStringByKeyW
#ELSE
MACRO AssocQueryStringByKey=AssocQueryStringByKeyA
#ENDIF

DECLARE FUNCTION AssocQueryKeyA LIB "ShlWApi.dll" ALIAS "AssocQueryKeyA" _
    (BYVAL dFlags AS DWORD, BYVAL dKey AS DWORD, pszAssoc AS ASCIIZ, _
    pszExtra AS ASCIIZ, phkeyOut AS DWORD) AS LONG

DECLARE FUNCTION AssocQueryKeyW LIB "ShlWApi.dll" ALIAS "AssocQueryKeyW" _
    (BYVAL dFlags AS DWORD, BYVAL dKey AS DWORD, pszAssoc AS WSTRINGZ, _
    pszExtra AS WSTRINGZ, phkeyOut AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO AssocQueryKey=AssocQueryKeyW
#ELSE
MACRO AssocQueryKey=AssocQueryKeyA
#ENDIF

#IF (%WIN32_IE >= &H0601)
'  AssocIsDangerous() checks a file type to determine whether it is "Dangerous"
'      this maps to the IE download dialog's forcing a prompt to open or save.
'      dangerous file types should be handled more carefully than other file types.
'
'  Parameter:  pszAssoc - type to check.  may be an extension or progid.  (".exe" or "exefile" would both be valid)
'
'  Returns: TRUE if the file type is dangerous.
'
'  NOTES:
'
'      this API first checks a hardcoded list of known dangerous types.
'      then it checks the editflags for the file type looking for the FTA_AlwaysUnsafe bit.
'      then it checks Safer policies.
'
DECLARE FUNCTION AssocIsDangerous LIB "ShlWApi.dll" ALIAS "AssocIsDangerous" _
    (pszAssoc AS WSTRINGZ) AS LONG

#ENDIF  ' %WIN32_IE >= &H0601

#IF (%WIN32_IE >= %WIN32_IE_IE60SP2)
DECLARE FUNCTION AssocGetPerceivedType LIB "ShlWApi.dll" _
    ALIAS "AssocGetPerceivedType" (pszExt AS WSTRINGZ, _
    ptype AS PERCEIVED_enum, pFlags AS PERCEIVEDFLAG_enum, ppszType AS ANY) _
    AS LONG
#ENDIF


#ENDIF  ' #IF NOT %DEF(%NO_SHLWAPI_REG)



#IF NOT %DEF(%NO_SHLWAPI_STREAM)

'
'=============== Stream Routines ===================================
'

DECLARE FUNCTION SHOpenRegStreamA LIB "ShlWApi.dll" ALIAS "SHOpenRegStreamA" _
    (BYVAL hKey AS DWORD, pszSubkey AS ASCIIZ, pszValue AS ASCIIZ, _
    BYVAL grfMode AS DWORD) AS DWORD

DECLARE FUNCTION SHOpenRegStreamW LIB "ShlWApi.dll" ALIAS "SHOpenRegStreamW" _
    (BYVAL hKey AS DWORD, pszSubkey AS WSTRINGZ, pszValue AS WSTRINGZ, _
    BYVAL grfMode AS DWORD) AS DWORD

'#IF %DEF(%UNICODE)
'MACRO SHOpenRegStream=SHOpenRegStreamW
'#ELSE
'MACRO SHOpenRegStream=SHOpenRegStreamA
'#ENDIF

DECLARE FUNCTION SHOpenRegStream2A LIB "ShlWApi.dll" _
    ALIAS "SHOpenRegStream2A" (BYVAL hKey AS DWORD, pszSubkey AS ASCIIZ, _
    pszValue AS ASCIIZ, BYVAL grfMode AS DWORD) AS DWORD

DECLARE FUNCTION SHOpenRegStream2W LIB "ShlWApi.dll" _
    ALIAS "SHOpenRegStream2W" (BYVAL hKey AS DWORD, pszSubkey AS WSTRINGZ, _
    pszValue AS WSTRINGZ, BYVAL grfMode AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
MACRO SHOpenRegStream2=SHOpenRegStream2W
#ELSE
MACRO SHOpenRegStream2=SHOpenRegStream2A
#ENDIF

' New code always wants new implementation...
MACRO SHOpenRegStream=SHOpenRegStream2

DECLARE FUNCTION SHCreateStreamOnFileA LIB "ShlWApi.dll" _
    ALIAS "SHCreateStreamOnFileA" (pszFile AS ASCIIZ, _
    BYVAL grfMode AS DWORD, ppstm AS ANY) AS LONG

DECLARE FUNCTION SHCreateStreamOnFileW LIB "ShlWApi.dll" _
    ALIAS "SHCreateStreamOnFileW" (pszFile AS WSTRINGZ, _
    BYVAL grfMode AS DWORD, ppstm AS ANY) AS LONG

#IF %DEF(%UNICODE)
MACRO SHCreateStreamOnFile=SHCreateStreamOnFileW
#ELSE
MACRO SHCreateStreamOnFile=SHCreateStreamOnFileA
#ENDIF

#IF (%WIN32_IE >= &H0600)

DECLARE FUNCTION SHCreateStreamOnFileEx LIB "ShlWApi.dll" _
    ALIAS "SHCreateStreamOnFileEx" (pszFile AS WSTRINGZ, _
    BYVAL grfMode AS DWORD, BYVAL dwAttributes AS DWORD, _
    BYVAL fCreate AS LONG, pstmTemplate AS ANY, ppstm AS ANY) AS LONG

#ENDIF ' (%WIN32_IE >= &H0600)

#IF (%WIN32_IE >= %WIN32_IE_IE501)

DECLARE FUNCTION SHCreateMemStream LIB "ShlWApi.dll" _
    ALIAS "SHCreateMemStream" (BYVAL pInit AS BYTE PTR, _
    BYVAL cbInit AS DWORD) AS DWORD

#ENDIF ' (%WIN32_IE >= %WIN32_IE_IE501)



#ENDIF ' %NO_SHLWAPI_STREAM



#IF NOT %DEF(%NO_SHLWAPI_MLUI)
'
'=============== Multi Language UI Routines ===================================
'

#IF (%WIN32_IE >= %WIN32_IE_IE501)

DECLARE FUNCTION MLLoadLibraryA LIB "ShlWApi.dll" ALIAS "MLLoadLibraryA" _
    (lpLibFileName AS ASCIIZ, BYVAL hModule AS DWORD, _
    BYVAL dwCrossCodePage AS DWORD) AS DWORD

DECLARE FUNCTION MLLoadLibraryW LIB "ShlWApi.dll" ALIAS "MLLoadLibraryW" _
    (lpLibFileName AS WSTRINGZ, BYVAL hModule AS DWORD, _
    BYVAL dwCrossCodePage AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
MACRO MLLoadLibrary=MLLoadLibraryW
#ELSE
MACRO MLLoadLibrary=MLLoadLibraryA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION MLFreeLibrary LIB "ShlWApi.dll" ALIAS "MLFreeLibrary" _
    (BYVAL hModule AS DWORD) AS LONG

%ML_NO_CROSSCODEPAGE   = 0
%ML_CROSSCODEPAGE_NT   = 1
%ML_CROSSCODEPAGE      = 2
%ML_SHELL_LANGUAGE     = 4
%ML_CROSSCODEPAGE_MASK = 7

#ENDIF ' (%WIN32_IE >= %WIN32_IE_IE501)

#ENDIF ' NO_SHLWAPI_MLUI



#IF NOT %DEF(%NO_SHLWAPI_HTTP)
'
'=============== HTTP helper Routines ===================================
'

#IF (%WIN32_IE >= &H0603)

DECLARE FUNCTION GetAcceptLanguagesA LIB "ShlWApi.dll" _
    ALIAS "GetAcceptLanguagesA" (psz AS ASCIIZ, pcch AS DWORD) AS LONG

DECLARE FUNCTION GetAcceptLanguagesW LIB "ShlWApi.dll" _
    ALIAS "GetAcceptLanguagesW" (psz AS WSTRINGZ, pcch AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO GetAcceptLanguages=GetAcceptLanguagesW
#ELSE
MACRO GetAcceptLanguages=GetAcceptLanguagesA
#ENDIF ' NOT %UNICODE

#ENDIF ' (%WIN32_IE >= &H0603)

#ENDIF ' NO_SHLWAPI_HTTP


#IF (%WIN32_IE < %WIN32_IE_IE70) AND NOT %DEF(%NO_SHLWAPI_STOPWATCH)

%SPMODE_SHELL      = &H00000001
%SPMODE_DEBUGOUT   = &H00000002
%SPMODE_TEST       = &H00000004
%SPMODE_BROWSER    = &H00000008
%SPMODE_FLUSH      = &H00000010
%SPMODE_EVENT      = &H00000020
%SPMODE_MSVM       = &H00000040
%SPMODE_FORMATTEXT = &H00000080
%SPMODE_PROFILE    = &H00000100
%SPMODE_DEBUGBREAK = &H00000200
%SPMODE_MSGTRACE   = &H00000400
%SPMODE_PERFTAGS   = &H00000800
%SPMODE_MEMWATCH   = &H00001000
%SPMODE_DBMON      = &H00002000
%SPMODE_MULTISTOP  = &H00004000
#IF NOT %DEF(%NO_ETW_TRACING)
%SPMODE_EVENTTRACE = &H00008000 ' Event Tracing for Windows Enabled
#ENDIF

DECLARE FUNCTION StopWatchMode LIB "ShlWApi.dll" ALIAS "StopWatchMode" _
    () AS DWORD

DECLARE FUNCTION StopWatchFlush LIB "ShlWApi.dll" ALIAS "StopWatchFlush" _
    () AS DWORD

#ENDIF ' (%WIN32_IE < %WIN32_IE_IE70) AND NOT %DEF(%NO_SHLWAPI_STOPWATCH)


#IF (%WIN32_IE >= %WIN32_IE_IE501)

DECLARE SUB IUnknown_Set LIB "ShlWApi.dll" ALIAS "IUnknown_Set" (ppunk AS ANY, punk AS ANY)
DECLARE SUB IUnknown_AtomicRelease LIB "ShlWApi.dll" ALIAS "IUnknown_AtomicRelease" _
     (ppunk AS ANY)
DECLARE FUNCTION IUnknown_GetWindow LIB "ShlWApi.dll" ALIAS "IUnknown_GetWindow" _
    (punk AS ANY, phwnd AS DWORD) AS LONG
DECLARE FUNCTION IUnknown_SetSite LIB "ShlWApi.dll" ALIAS "IUnknown_SetSite" _
    (punk AS ANY, punkSite AS ANY) AS LONG
DECLARE FUNCTION IUnknown_GetSite LIB "ShlWApi.dll" ALIAS "IUnknown_GetSite" _
    (punk AS ANY, riid AS GUID, punkSite AS ANY) AS LONG
DECLARE FUNCTION IUnknown_QueryService LIB "ShlWApi.dll" ALIAS "IUnknown_QueryService" _
    (punk AS ANY, guidService AS GUID, riid AS GUID, ppvOut AS ANY) AS LONG

#ENDIF ' (%WIN32_IE >= %WIN32_IE_IE501)


#IF (%WIN32_IE >= %WIN32_IE_IE501)

DECLARE FUNCTION IStream_Read LIB "ShlWApi.dll" ALIAS "IStream_Read" _
    (pstm AS ANY, pv AS ANY, BYVAL cb AS DWORD) AS LONG
DECLARE FUNCTION IStream_Write LIB "ShlWApi.dll" ALIAS "IStream_Write" _
    (pstm AS ANY, pv AS ANY, BYVAL cb AS DWORD) AS LONG
DECLARE FUNCTION IStream_Reset LIB "ShlWApi.dll" ALIAS "IStream_Reset" _
    (pstm AS ANY) AS LONG
DECLARE FUNCTION IStream_Size LIB "ShlWApi.dll" ALIAS "IStream_Size" _
    (pstm AS ANY, pui AS QUAD) AS LONG
DECLARE FUNCTION ConnectToConnectionPoint LIB "ShlWApi.dll" _
    ALIAS "ConnectToConnectionPoint" (punk AS ANY, riidEvent AS GUID, _
    BYVAL fConnect AS LONG, punkTarget AS ANY, pdwCookie AS DWORD, _
    ppcpOut AS ANY) AS LONG

#ENDIF ' (%WIN32_IE >= %WIN32_IE_IE501)

#IF (%WIN32_IE >= %WIN32_IE_IE60)

DECLARE FUNCTION IStream_ReadPidl LIB "ShlWApi.dll" ALIAS "IStream_ReadPidl" _
    (pstm AS ANY, ppidlOut AS ANY) AS LONG
DECLARE FUNCTION IStream_WritePidl LIB "ShlWApi.dll" _
    ALIAS "IStream_WritePidl" (pstm AS ANY, BYVAL ppidlWrite AS DWORD) _
    AS LONG

#ENDIF ' (%WIN32_IE >= %WIN32_IE_IE60)

#IF (%WIN32_IE >= %WIN32_IE_IE70)

DECLARE FUNCTION IStream_ReadStr LIB "ShlWApi.dll" ALIAS "IStream_ReadStr" _
    (pstm AS ANY, ppsz AS ANY) AS LONG
DECLARE FUNCTION IStream_WriteStr LIB "ShlWApi.dll" ALIAS "IStream_WriteStr" _
    (pstm AS ANY, psz AS WSTRINGZ) AS LONG
DECLARE FUNCTION IStream_Copy LIB "ShlWApi.dll" ALIAS "IStream_Copy" _
    (pstmFrom AS ANY, pstmTo AS ANY, BYVAL cb AS DWORD) AS LONG

#ENDIF ' (%WIN32_IE >= %WIN32_IE_IE70)


#IF (%WIN32_IE >= &H0600)
%SHGVSPB_PERUSER        = &H00000001 ' must have one of PERUSER or ALLUSERS
%SHGVSPB_ALLUSERS       = &H00000002
%SHGVSPB_PERFOLDER      = &H00000004 ' must have one of PERFOLDER ALLFOLDERS or INHERIT
%SHGVSPB_ALLFOLDERS     = &H00000008
%SHGVSPB_INHERIT        = &H00000010
%SHGVSPB_ROAM           = &H00000020 ' modifies the above
%SHGVSPB_NOAUTODEFAULTS = &H80000000??? ' turns off read delegation to more general property bags

%SHGVSPB_FOLDER           = (%SHGVSPB_PERUSER OR %SHGVSPB_PERFOLDER)
%SHGVSPB_FOLDERNODEFAULTS = (%SHGVSPB_PERUSER OR %SHGVSPB_PERFOLDER OR %SHGVSPB_NOAUTODEFAULTS)
%SHGVSPB_USERDEFAULTS     = (%SHGVSPB_PERUSER OR %SHGVSPB_ALLFOLDERS)
%SHGVSPB_GLOBALDEAFAULTS  = (%SHGVSPB_ALLUSERS OR %SHGVSPB_ALLFOLDERS)

DECLARE FUNCTION SHGetViewStatePropertyBag LIB "ShlWApi.dll" _
    ALIAS "SHGetViewStatePropertyBag" (BYVAL pidl AS DWORD, _
    pszBagName AS WSTRINGZ, BYVAL dwFlags AS DWORD, riid AS GUID, _
    ppv AS ANY) AS LONG

#ENDIF  ' (%WIN32_IE >= &H0600)

' SHFormatDateTime flags
'  (FDTF_SHORTDATE and FDTF_LONGDATE are mutually exclusive, as is
'   FDTF_SHORTIME and FDTF_LONGTIME.)
'
%FDTF_SHORTTIME          = &H00000001      ' eg, "7:48 PM"
%FDTF_SHORTDATE          = &H00000002      ' eg, "3/29/98"
%FDTF_DEFAULT            = (%FDTF_SHORTDATE OR %FDTF_SHORTTIME) ' eg, "3/29/98 7:48 PM"
%FDTF_LONGDATE           = &H00000004      ' eg, "Monday, March 29, 1998"
%FDTF_LONGTIME           = &H00000008      ' eg. "7:48:33 PM"
%FDTF_RELATIVE           = &H00000010      ' uses "Yesterday", etc. if possible
%FDTF_LTRDATE            = &H00000100      ' Left To Right reading order
%FDTF_RTLDATE            = &H00000200      ' Right To Left reading order
%FDTF_NOAUTOREADINGORDER = &H00000400      ' Don't detect reading order automatically. Useful if you will be converting to Ansi and don't want Unicode reading order characters

DECLARE FUNCTION SHFormatDateTimeA LIB "ShlWApi.dll" _
    ALIAS "SHFormatDateTimeA" (pft AS FILETIME, pdwFlags AS DWORD, _
    pszBuf AS ASCIIZ, BYVAL cchBuf AS DWORD) AS LONG

DECLARE FUNCTION SHFormatDateTimeW LIB "ShlWApi.dll" _
    ALIAS "SHFormatDateTimeW" (pft AS FILETIME, pdwFlags AS DWORD, _
    pszBuf AS WSTRINGZ, BYVAL cchBuf AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO SHFormatDateTime=SHFormatDateTimeW
#ELSE
MACRO SHFormatDateTime=SHFormatDateTimeA
#ENDIF ' NOT %UNICODE

#IF (%WIN32_IE >= %WIN32_IE_IE501)

DECLARE FUNCTION SHAnsiToUnicode LIB "ShlWApi.dll" ALIAS "SHAnsiToUnicode" _
    (pszSrc AS ASCIIZ, pwszDst AS WSTRINGZ, BYVAL cwchBuf AS LONG) AS LONG
DECLARE FUNCTION SHAnsiToAnsi LIB "ShlWApi.dll" ALIAS "SHAnsiToAnsi" _
    (pszSrc AS ASCIIZ, pszDst AS ASCIIZ, BYVAL cchBuf AS LONG) AS LONG
DECLARE FUNCTION SHUnicodeToAnsi LIB "ShlWApi.dll" ALIAS "SHUnicodeToAnsi" _
    (pwszSrc AS WSTRINGZ, pszDst AS ASCIIZ, BYVAL cchBuf AS LONG) AS LONG
DECLARE FUNCTION SHUnicodeToUnicode LIB "ShlWApi.dll" ALIAS "SHUnicodeToUnicode" _
    (pwszSrc AS WSTRINGZ, pwszDst AS WSTRINGZ, BYVAL cwchBuf AS LONG) AS LONG

' The return value from all SH<Type>To<Type> is the size of szDest including the terminater.
#IF %DEF(%UNICODE)
MACRO SHTCharToUnicode(wzSrc, wzDest, cchSize) = SHUnicodeToUnicode(wzSrc, wzDest, cchSize)
MACRO SHTCharToAnsi(wzSrc, szDest, cchSize)    = SHUnicodeToAnsi(wzSrc, szDest, cchSize)
MACRO SHUnicodeToTChar(wzSrc, wzDest, cchSize) = SHUnicodeToUnicode(wzSrc, wzDest, cchSize)
MACRO SHAnsiToTChar(szSrc, wzDest, cchSize)    = SHAnsiToUnicode(szSrc, wzDest, cchSize)
#ELSE ' UNICODE
MACRO SHTCharToUnicode(szSrc, wzDest, cchSize) = SHAnsiToUnicode(szSrc, wzDest, cchSize)
MACRO SHTCharToAnsi(szSrc, szDest, cchSize)    = SHAnsiToAnsi(szSrc, szDest, cchSize)
MACRO SHUnicodeToTChar(wzSrc, szDest, cchSize) = SHUnicodeToAnsi(wzSrc, szDest, cchSize)
MACRO SHAnsiToTChar(szSrc, szDest, cchSize)    = SHAnsiToAnsi(szSrc, szDest, cchSize)
#ENDIF ' UNICODE

#ENDIF ' (%WIN32_IE >= %WIN32_IE_IE501)


#IF (%WIN32_IE >= %WIN32_IE_IE501)

DECLARE FUNCTION SHMessageBoxCheckA LIB "ShlWApi.dll" _
    ALIAS "SHMessageBoxCheckA" (BYVAL hwnd AS DWORD, pszText AS ASCIIZ, _
    pszCaption AS ASCIIZ, BYVAL uType AS DWORD, BYVAL iDefault AS LONG, _
    pszRegVal AS ASCIIZ) AS LONG

DECLARE FUNCTION SHMessageBoxCheckW LIB "ShlWApi.dll" _
    ALIAS "SHMessageBoxCheckW" (BYVAL hwnd AS DWORD, pszText AS WSTRINGZ, _
    pszCaption AS WSTRINGZ, BYVAL uType AS DWORD, BYVAL iDefault AS LONG, _
    pszRegVal AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO SHMessageBoxCheck=SHMessageBoxCheckW
#ELSE
MACRO SHMessageBoxCheck=SHMessageBoxCheckA
#ENDIF ' NOT %UNICODE

#ENDIF ' (%WIN32_IE >= %WIN32_IE_IE501)


#IF (%WIN32_IE >= %WIN32_IE_IE501)

' Prevents hang do [sic] to hung window on broadcast
DECLARE FUNCTION SHSendMessageBroadcastA LIB "ShlWApi.dll" _
    ALIAS "SHSendMessageBroadcastA" (BYVAL uMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG
' Prevents hang do [sic] to hung window on broadcast
DECLARE FUNCTION SHSendMessageBroadcastW LIB "ShlWApi.dll" _
    ALIAS "SHSendMessageBroadcastW" (BYVAL uMsg AS DWORD, _
    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO SHSendMessageBroadcast=SHSendMessageBroadcastW
#ELSE
MACRO SHSendMessageBroadcast=SHSendMessageBroadcastA
#ENDIF ' NOT %UNICODE

' [yes, these routines really are spelled this way]
DECLARE FUNCTION SHStripMneumonicA LIB "ShlWApi.dll" _
    ALIAS "SHStripMneumonicA" (pszMenu AS ASCIIZ) AS BYTE
DECLARE FUNCTION SHStripMneumonicW LIB "ShlWApi.dll" _
    ALIAS "SHStripMneumonicW" (pszMenu AS WSTRINGZ) AS WORD

#IF %DEF(%UNICODE)
MACRO SHStripMneumonic=SHStripMneumonicW
#ELSE
MACRO SHStripMneumonic=SHStripMneumonicA
#ENDIF ' NOT %UNICODE

#IF NOT %DEF(%NO_SHLWAPI_ISOS)

' Returns TRUE/FALSE depending on question
%OS_WINDOWS                = 0    ' Windows 9x vs. NT
%OS_NT                     = 1    ' Windows 9x vs. NT
%OS_WIN95ORGREATER         = 2    ' Win95 or greater
%OS_NT4ORGREATER           = 3    ' NT4 or greater
%OS_WIN98ORGREATER         = 5    ' Win98 or greater
%OS_WIN98_GOLD             = 6    ' Win98 Gold (Version 4.10 build 1998)
%OS_WIN2000ORGREATER       = 7    ' Some derivative of Win2000

' NOTE: these flags check explicitly for (dwMajorVersion == 5)
%OS_WIN2000PRO             = 8    ' Windows 2000 Professional (Workstation)
%OS_WIN2000SERVER          = 9    ' Windows 2000 Server
%OS_WIN2000ADVSERVER       = 10   ' Windows 2000 Advanced Server
%OS_WIN2000DATACENTER      = 11   ' Windows 2000 Data Center Server
%OS_WIN2000TERMINAL        = 12   ' Windows 2000 Terminal Server in "Application Server" mode (now simply called "Terminal Server")

%OS_EMBEDDED               = 13   ' Embedded Windows Edition
%OS_TERMINALCLIENT         = 14   ' Windows Terminal Client (eg user is comming in via tsclient)
%OS_TERMINALREMOTEADMIN    = 15   ' Terminal Server in "Remote Administration" mode
%OS_WIN95_GOLD             = 16   ' Windows 95 Gold (Version 4.0 Build 1995)
%OS_MEORGREATER            = 17   ' Windows Millennium (Version 5.0)
%OS_XPORGREATER            = 18   ' Windows XP or greater
%OS_HOME                   = 19   ' Home Edition (eg NOT Professional, Server, Advanced Server, or Datacenter)
%OS_PROFESSIONAL           = 20   ' Professional     (aka Workstation; eg NOT Server, Advanced Server, or Datacenter)
%OS_DATACENTER             = 21   ' Datacenter       (eg NOT Server, Advanced Server, Professional, or Personal)
%OS_ADVSERVER              = 22   ' Advanced Server  (eg NOT Datacenter, Server, Professional, or Personal)
%OS_SERVER                 = 23   ' Server           (eg NOT Datacenter, Advanced Server, Professional, or Personal)
%OS_TERMINALSERVER         = 24   ' Terminal Server - server running in what used to be called "Application Server" mode (now simply called "Terminal Server")
%OS_PERSONALTERMINALSERVER = 25   ' Personal Terminal Server - per/pro machine running in single user TS mode
%OS_FASTUSERSWITCHING      = 26   ' Fast User Switching
%OS_WELCOMELOGONUI         = 27   ' New friendly logon UI
%OS_DOMAINMEMBER           = 28   ' Is this machine a member of a domain (eg NOT a workgroup)
%OS_ANYSERVER              = 29   ' is this machine any type of server? (eg datacenter or advanced server or server)?
%OS_WOW6432                = 30   ' Is this process a 32-bit process running on an 64-bit platform?
%OS_WEBSERVER              = 31   ' Web Edition Server
%OS_SMALLBUSINESSSERVER    = 32   ' SBS Server
%OS_TABLETPC               = 33   ' Are we running on a TabletPC?
%OS_SERVERADMINUI          = 34   ' Should defaults lean towards those preferred by server administrators?
%OS_MEDIACENTER            = 35   ' eHome Freestyle Project
%OS_APPLIANCE              = 36   ' Windows .NET Appliance Server

' [only exported by name as of Vista]
DECLARE FUNCTION IsOS LIB "ShlWApi.dll" ALIAS "IsOS" (BYVAL dwOS AS DWORD) _
    AS LONG

#ENDIF ' #IF NOT %DEF(%NO_SHLWAPI_ISOS)

#ENDIF ' (%WIN32_IE >= %WIN32_IE_IE501)

MACRO SHGLOBALCOUNTER_enum=LONG
ENUM SHGLOBALCOUNTER SINGULAR
    GLOBALCOUNTER_SEARCHMANAGER
    GLOBALCOUNTER_SEARCHOPTIONS
    GLOBALCOUNTER_FOLDERSETTINGSCHANGE
    GLOBALCOUNTER_RATINGS
    GLOBALCOUNTER_APPROVEDSITES
    GLOBALCOUNTER_RESTRICTIONS
    GLOBALCOUNTER_SHELLSETTINGSCHANGED
    GLOBALCOUNTER_SYSTEMPIDLCHANGE
    GLOBALCOUNTER_OVERLAYMANAGER
    GLOBALCOUNTER_QUERYASSOCIATIONS
    GLOBALCOUNTER_IESESSIONS
    GLOBALCOUNTER_IEONLY_SESSIONS
    GLOBALCOUNTER_APPLICATION_DESTINATIONS
    UNUSED_RECYCLE_WAS_GLOBALCOUNTER_CSCSYNCINPROGRESS
    GLOBALCOUNTER_BITBUCKETNUMDELETERS
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_SHARES
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_A
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_B
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_C
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_D
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_E
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_F
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_G
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_H
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_I
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_J
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_K
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_L
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_M
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_N
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_O
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_P
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Q
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_R
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_S
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_T
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_U
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_V
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_W
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_X
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Y
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Z
    UNUSED_RECYCLE_WAS_GLOBALCOUNTER_RECYCLEDIRTYCOUNT_SERVERDRIVE
    UNUSED_RECYCLE_WAS_GLOBALCOUNTER_RECYCLEGLOBALDIRTYCOUNT
    GLOBALCOUNTER_RECYCLEBINENUM
    GLOBALCOUNTER_RECYCLEBINCORRUPTED
    GLOBALCOUNTER_RATINGS_STATECOUNTER
    GLOBALCOUNTER_PRIVATE_PROFILE_CACHE
    GLOBALCOUNTER_INTERNETTOOLBAR_LAYOUT
    GLOBALCOUNTER_FOLDERDEFINITION_CACHE
    GLOBALCOUNTER_COMMONPLACES_LIST_CACHE
    GLOBALCOUNTER_PRIVATE_PROFILE_CACHE_MACHINEWIDE
    GLOBALCOUNTER_ASSOCCHANGED
    GLOBALCOUNTER_MAXIMUMVALUE
END ENUM

DECLARE FUNCTION SHGlobalCounterGetValue LIB "ShlWApi.dll" _
    ALIAS "SHGlobalCounterGetValue" ( _
    BYVAL gcid AS SHGLOBALCOUNTER_enum) _
    AS LONG

DECLARE FUNCTION SHGlobalCounterIncrement LIB "ShlWApi.dll" _
    ALIAS "SHGlobalCounterIncrement" ( _
    BYVAL gcid AS SHGLOBALCOUNTER_enum) _
    AS LONG

DECLARE FUNCTION SHGlobalCounterDecrement LIB "ShlWApi.dll" _
    ALIAS "SHGlobalCounterDecrement" ( _
    BYVAL gcid AS SHGLOBALCOUNTER_enum) _
    AS LONG


' Shared memory apis


#IF (%WIN32_IE >= &H0603)
DECLARE FUNCTION SHAllocShared LIB "ShlWApi.dll" ALIAS "SHAllocShared" _
    (pvData AS ANY, BYVAL dwSize AS DWORD, BYVAL dwProcessId AS DWORD) AS DWORD
DECLARE FUNCTION SHFreeShared LIB "ShlWApi.dll" ALIAS "SHFreeShared" _
    (BYVAL hData AS DWORD, BYVAL dwProcessId AS DWORD) AS LONG
DECLARE FUNCTION SHLockShared LIB "ShlWApi.dll" ALIAS "SHLockShared" _
    (BYVAL hData AS DWORD, BYVAL dwProcessId AS DWORD) AS DWORD
DECLARE FUNCTION SHUnlockShared LIB "ShlWApi.dll" ALIAS "SHUnlockShared" _
    (pvData AS ANY) AS LONG
#ENDIF ' %WIN32_IE >= &H0603


#IF (%WIN32_IE >= %WIN32_IE_IE501)

DECLARE FUNCTION WhichPlatform LIB "ShlWApi.dll" ALIAS "WhichPlatform" _
    () AS DWORD

' Return values of WhichPlatform
%PLATFORM_UNKNOWN     = 0
%PLATFORM_IE3         = 1      ' obsolete: use %PLATFORM_BROWSERONLY
%PLATFORM_BROWSERONLY = 1      ' browser-only (no new shell)
%PLATFORM_INTEGRATED  = 2      ' integrated shell

'***   QueryInterface helpers
' NOTES
'  ATL has a fancier version of this.  if we need to extend ours, we
'  should probably just switch to ATL's rather than reinvent.
' EXAMPLE
'  Cfoo::QI(REFIID riid, void **ppv)
'  {
'      ' (the IID_xxx comments make grep'ing work!)
'      static const QITAB qit = {
'          QITABENT(Cfoo, Iiface1),    ' IID_Iiface1
'          ...
'          QITABENT(Cfoo, IifaceN),    ' IID_IifaceN
'          { 0 },                      ' n.b. don't forget the 0
'      };
'
'      ' n.b. make sure you don't cast 'this'
'      hr = QISearch(this, qit, riid, ppv);
'      if (FAILED(hr))
'          hr = SUPER::QI(riid, ppv);
'      ' custom code could be added here for FAILED() case
'      return hr;
'  }
'
'  If you have an interface that is implemented multiple times,
'  the compiler will claim an ambiguous cast, so you need to give
'  some help.  For example, if your class is defined as
'
'  class CClass : public IPersistStream, public IPersistFile
'
'  then you need to say
'
'      QITABENTMULTI(CClass, IPersist, IPersistStream)
'      QITABENT(CClass, IPersistStream)
'      QITABENT(CClass, IPersistFile)
'
'  The MULTI is needed for IPersist because the compiler doesn't
'  know whether you wanted the IPersist from IPersistStream
'  or the IPersist from IPersistFile.  Unless you have played weird
'  compiler tricks, they are the same implementation, so you can
'  just pick either one, doesn't matter.
'
'  Common mistake: You do not need to use MULTI if the base interface
'  can be unambiguously determined.  E.g.,
'
'  class CSimple : public IContextMenu3
'
'      QITABENT(CClass, IContextMenu)      ' do not need MULTI
'      QITABENT(CClass, IContextMenu2)     ' do not need MULTI
'      QITABENT(CClass, IContextMenu3)
'
'  Do not create an entry for IUnknown; the first entry in the
'  table will be used for IUnknown.
'

TYPE QITAB
    piid     AS GUID PTR
    dwOffset AS LONG
END TYPE

'#define QITABENTMULTI(Cthis, Ifoo, Iimpl)  _
'    { (IID*) &IID_##Ifoo, OFFSETOFCLASS(Iimpl, Cthis) }

'#define QITABENTMULTI2(Cthis, Ifoo, Iimpl)  _
'    { (IID*) &Ifoo, OFFSETOFCLASS(Iimpl, Cthis) }

MACRO QITABENT(Cthis, Ifoo)=QITABENTMULTI(Cthis, Ifoo, Ifoo)

DECLARE FUNCTION QISearch LIB "ShlWApi.dll" ALIAS "QISearch" (that AS ANY, _
    pqit AS QITAB, riid AS GUID, ppv AS ANY) AS LONG

#ENDIF ' (%WIN32_IE >= %WIN32_IE_IE501)

#IF NOT %DEF(%STATIC_CAST)
'***   STATIC_CAST -- 'portable' static_cast<>
' NOTES
'  do *not* use SAFE_CAST (see comment in OFFSETOFCLASS)
'#define STATIC_CAST(typ)   static_cast<typ>
#IF NOT %DEF(%X86)
    ' assume only intel compiler (>=vc5) supports static_cast for now
    ' we could key off of _MSC_VER >= 1100 but i'm not sure that will work
    '
    ' a straight cast will give the correct result but no error checking,
    ' so we'll have to catch errors on intel.
'    #undef  STATIC_CAST
'    #define STATIC_CAST(typ)   (typ)
#ENDIF
#ENDIF

#IF NOT %DEF(%OFFSETOFCLASS)
'***   OFFSETOFCLASS -- (stolen from ATL)
' we use STATIC_CAST not SAFE_CAST because the compiler gets confused
' (it doesn't constant-fold the ,-op in SAFE_CAST so we end up generating
' code for the table!)

'#define OFFSETOFCLASS(BASE, derived)  _
'    ((DWORD)(DWORD_PTR)(STATIC_CAST(BASE*)((derived*)8))-8)
#ENDIF


' Types for SHIsLowMemoryMachine

%ILMM_IE4  = 0       ' 1997-era machine

DECLARE FUNCTION SHIsLowMemoryMachine LIB "ShlWApi.dll" _
    ALIAS "SHIsLowMemoryMachine" (BYVAL dwType AS DWORD) AS LONG

' Menu Helpers
DECLARE FUNCTION GetMenuPosFromID LIB "ShlWApi.dll" ALIAS "GetMenuPosFromID" _
    (BYVAL hmenu AS DWORD, BYVAL ID AS DWORD) AS LONG

DECLARE FUNCTION SHGetInverseCMAP LIB "ShlWApi.dll" ALIAS "SHGetInverseCMAP" _
    (BYVAL pbMap AS BYTE PTR, BYVAL cbMap AS DWORD) AS LONG

#IF (%WIN32_IE >= &H0500)

' SHAutoComplete
'      hwndEdit - DWORD of editbox, ComboBox or ComboBoxEx.
'      dwFlags - Flags to indicate what to AutoAppend or AutoSuggest for the editbox.
'
' WARNING:
'    Caller needs to have called CoInitialize() or OleInitialize()
'    and cannot call CoUninit/OleUninit until after
'    WM_DESTROY on hwndEdit.
'
'  dwFlags values:
%SHACF_DEFAULT                 = &H00000000  ' Currently (%SHACF_FILESYSTEM OR %SHACF_URLALL)
%SHACF_FILESYSTEM              = &H00000001  ' This includes the File System as well as the rest of the shell (Desktop\My Computer\Control Panel\)
%SHACF_URLHISTORY              = &H00000002  ' URLs in the User's History
%SHACF_URLMRU                  = &H00000004  ' URLs in the User's Recently Used list.
%SHACF_URLALL                  = (%SHACF_URLHISTORY OR %SHACF_URLMRU)
%SHACF_USETAB                  = &H00000008  ' Use the tab to move thru the autocomplete possibilities instead of to the next dialog/window control.
%SHACF_FILESYS_ONLY            = &H00000010  ' This includes the File System
#IF (%WIN32_IE >= &H0600)
%SHACF_FILESYS_DIRS            = &H00000020  ' Same as %SHACF_FILESYS_ONLY except it only includes directories, UNC servers, and UNC server shares.
#ENDIF ' (%WIN32_IE >= &H0600)
#IF (%WIN32_IE >= %WIN32_IE_IE70)
%SHACF_VIRTUAL_NAMESPACE       = &H00000040  ' Also include the virtual namespace
#ENDIF ' %WIN32_IE_IE70
%SHACF_AUTOSUGGEST_FORCE_ON    = &H10000000  ' Ignore the registry default and force the feature on.
%SHACF_AUTOSUGGEST_FORCE_OFF   = &H20000000  ' Ignore the registry default and force the feature off.
%SHACF_AUTOAPPEND_FORCE_ON     = &H40000000  ' Ignore the registry default and force the feature on. (Also know as AutoComplete)
%SHACF_AUTOAPPEND_FORCE_OFF    = &H80000000???  ' Ignore the registry default and force the feature off. (Also know as AutoComplete)

DECLARE FUNCTION SHAutoComplete LIB "ShlWApi.dll" ALIAS "SHAutoComplete" _
    (BYVAL hwndEdit AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

#IF (%WIN32_IE >= %WIN32_IE_IE60SP2)
DECLARE FUNCTION SHCreateThreadRef LIB "ShlWApi.dll" _
    ALIAS "SHCreateThreadRef" (pcRef AS LONG, ppunk AS GUID) AS LONG
#ENDIF ' %WIN32_IE_IE60SP2
DECLARE FUNCTION SHSetThreadRef LIB "ShlWApi.dll" ALIAS "SHSetThreadRef" _
    (punk AS ANY) AS LONG
DECLARE FUNCTION SHGetThreadRef LIB "ShlWApi.dll" ALIAS "SHGetThreadRef" _
    (ppunk AS ANY) AS LONG

DECLARE FUNCTION SHSkipJunction LIB "ShlWApi.dll" ALIAS "SHSkipJunction" _
    (pbc AS ANY, pclsid AS GUID) AS LONG
#ENDIF ' (%WIN32_IE >= &H0500)

%CTF_INSIST                   = &H00000001      ' SHCreateThread() dwFlags - call pfnThreadProc synchronously if CreateThread() fails
%CTF_THREAD_REF               = &H00000002      ' hold a reference to the creating thread
%CTF_PROCESS_REF              = &H00000004      ' hold a reference to the creating process
%CTF_COINIT_STA               = &H00000008      ' init COM as STA for the created thread
%CTF_COINIT                   = %CTF_COINIT_STA ' init COM as STA for the created thread
#IF (%WIN32_IE >= %WIN32_IE_IE60)
%CTF_FREELIBANDEXIT           = &H00000010      ' hold a ref to the DLL and call FreeLibraryAndExitThread() when done
%CTF_REF_COUNTED              = &H00000020      ' thread supports ref counting via SHGetThreadRef() or CTF_THREAD_REF so that child threads can keep this thread alive
%CTF_WAIT_ALLOWCOM            = &H00000040      ' while waiting for pfnCallback, allow COM marshaling to the blocked calling thread
#ENDIF ' %WIN32_IE_IE60
#IF (%WIN32_IE >= %WIN32_IE_IE70)
%CTF_UNUSED                   = &H00000080
%CTF_INHERITWOW64             = &H00000100      ' new thread should inherit the wow64 disable state for the file system redirector
#ENDIF ' %WIN32_IE_IE70
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%CTF_WAIT_NO_REENTRANCY       = &H00000200      ' don't allow re-entrancy when waiting for the sync proc, this won't work with marshalled objects or SendMessages() from the sync proc
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)
#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
%CTF_KEYBOARD_LOCALE     = &H00000400   ' carry the keyboard locale from creating to created thread
%CTF_OLEINITIALIZE       = &H00000800   ' init OLE on the created thread (this will also init COM as STA)
%CTF_COINIT_MTA          = &H00001000   ' init COM as MTA for the created thread
%CTF_NOADDREFLIB         = &H00002000   ' this flag is the opposite of CTF_FREELIBANDEXIT that is now implicit as of Vista
                                        ' this avoids the LoadLibrary/FreeLibraryAndExitThread calls that result in contention for the loader lock
                                        ' only use this when the thread being created has some other means to ensure that the code
                                        ' of the thread proc will remain loaded. This should not be used in the context of COM objects as those
                                        ' need to ensure that the DLL stays loaded as COM will unload DLLs

#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WIN7)

MACRO SHCT_FLAGS=DWORD  ' SHCreateThread flags values

'%CTF_COINIT_MTA   = &H00000800      ' init COM as STA for the created thread

DECLARE FUNCTION SHCreateThread LIB "ShlWApi.dll" ALIAS "SHCreateThread" _
    (BYVAL pfnThreadProc AS DWORD, pData AS ANY, BYVAL dwFlags AS DWORD, _
    BYVAL pfnCallback AS DWORD) AS LONG

DECLARE FUNCTION SHCreateThreadWithHandle LIB "ShlWApi.dll" _
    ALIAS "SHCreateThreadWithHandle" ( _
    BYVAL pfnThreadProc AS DWORD, _    ' LPTHREAD_START_ROUTINE
    pData AS ANY, _
    BYVAL flags AS DWORD, _            ' SHCT_FLAGS
    BYVAL pfnCallback AS DWORD, _      ' LPTHREAD_START_ROUTINE
    pHandle AS DWORD) _                ' HANDLE
    AS LONG

#IF (%WIN32_IE >= %WIN32_IE_IE60)
' release a CTF_THREAD_REF reference earlier than the return of pfnThreadProc
DECLARE FUNCTION SHReleaseThreadRef LIB "ShlWApi.dll" _
    ALIAS "SHReleaseThreadRef" () AS LONG  ' HRESULT
#ENDIF ' %WIN32_IE_IE60

#IF NOT %DEF(%NO_SHLWAPI_GDI)
'
'====== GDI helper functions  ================================================
'

DECLARE FUNCTION SHCreateShellPalette LIB "ShlWApi.dll" _
    ALIAS "SHCreateShellPalette" (BYVAL hdc AS DWORD) AS DWORD

#IF (%WIN32_IE >= &H0500)

DECLARE SUB ColorRGBToHLS LIB "ShlWApi.dll" ALIAS "ColorRGBToHLS" _
    (BYVAL clrRGB AS DWORD, pwHue AS WORD, pwLuminance AS WORD, _
    psSaturation AS WORD)

DECLARE FUNCTION ColorHLSToRGB LIB "ShlWApi.dll" ALIAS "ColorHLSToRGB" _
    (BYVAL wHue AS WORD, BYVAL wLuminance AS WORD, BYVAL wSaturation AS WORD) _
    AS DWORD

DECLARE FUNCTION ColorAdjustLuma LIB "ShlWApi.dll" ALIAS "ColorAdjustLuma" _
    (BYVAL clrRGB AS DWORD, BYVAL n AS LONG, BYVAL fScale AS LONG) AS DWORD

#ENDIF  ' %WIN32_IE >= &H0500

#ENDIF  ' #IF NOT %DEF(%NO_SHLWAPI_GDI)


'====== DllGetVersion  =======================================================

TYPE DLLVERSIONINFO
    cbSize         AS DWORD
    dwMajorVersion AS DWORD   ' Major version
    dwMinorVersion AS DWORD   ' Minor version
    dwBuildNumber  AS DWORD   ' Build number
    dwPlatformID   AS DWORD   ' %DLLVER_PLATFORM_*
END TYPE

' Platform IDs for DLLVERSIONINFO
%DLLVER_PLATFORM_WINDOWS = &H00000001   ' Windows 95
%DLLVER_PLATFORM_NT      = &H00000002   ' Windows NT

' The caller should always GetProcAddress("DllGetVersion"), not
' implicitly link to it.

#IF (%WIN32_IE >= &H0501)

TYPE DLLVERSIONINFO2
    info1      AS DLLVERSIONINFO
    dwFlags    AS DWORD                     ' No flags currently defined
    ullVersion AS QUAD                      ' Encoded as:
                                            ' Major &HFFFF 0000 0000 0000
                                            ' Minor &H0000 FFFF 0000 0000
                                            ' Build &H0000 0000 FFFF 0000
                                            ' QFE   &H0000 0000 0000 FFFF
END TYPE

%DLLVER_MAJOR_MASK = &HFFFF000000000000
%DLLVER_MINOR_MASK = &H0000FFFF00000000
%DLLVER_BUILD_MASK = &H00000000FFFF0000
%DLLVER_QFE_MASK   = &H000000000000FFFF

#ENDIF

MACRO FUNCTION MAKEDLLVERULL(major, minor, build, qfe)
    MACROTEMP q, qResult
    LOCAL q, qResult AS QUAD
    qResult = (major)
    SHIFT LEFT qResult, 48
    q = (minor)
    SHIFT LEFT q, 32
    qResult OR= q
    q = (build)
    SHIFT LEFT q, 16
END MACRO=(qResult OR q OR (qfe))

'
' The caller should always GetProcAddress("DllGetVersion"), not
' implicitly link to it.
'

DECLARE FUNCTION DLLGETVERSIONPROC (dvi AS DLLVERSIONINFO) AS LONG

' DllInstall (to be implemented by self-installing DLLs)
DECLARE FUNCTION DllInstall (BYVAL bInstall AS LONG, pszCmdLine AS WSTRINGZ) _
    AS LONG


#IF (%WIN32_IE >= &H0602)
' Function to see if Internet Explorer Enhanced Security Configuration
' is active for the current user
DECLARE FUNCTION IsInternetESCEnabled LIB "ShlWApi.dll" _
    ALIAS "IsInternetESCEnabled" () AS LONG
#ENDIF ' (%WIN32_IE >= &H0602)



#ENDIF  ' #IF NOT %DEF(%NOSHLWAPI)
