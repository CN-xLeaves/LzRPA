'------------------------------------------------------------------------------
'
'  LZExpand.inc
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from LZExpand.h dated 18 Jan 2008
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%LZEXPAND = 1

#INCLUDE "WTypes.inc"
#INCLUDE "WinBase.inc"


'
' Error Return Codes
'

%LZERROR_BADINHANDLE  = (-1)  ' invalid input handle
%LZERROR_BADOUTHANDLE = (-2)  ' invalid output handle
%LZERROR_READ         = (-3)  ' corrupt compressed file format
%LZERROR_WRITE        = (-4)  ' out of space for output file
%LZERROR_GLOBALLOC    = (-5)  ' insufficient memory for LZFile struct
%LZERROR_GLOBLOCK     = (-6)  ' bad global handle
%LZERROR_BADVALUE     = (-7)  ' input parameter out of acceptable range
%LZERROR_UNKNOWNALG   = (-8)  ' compression algorithm not recognized


'
' Prototypes
'

DECLARE FUNCTION LZStart LIB "LZ32.DLL" ALIAS "LZStart" () AS LONG
DECLARE SUB LZDone LIB "LZ32.DLL" ALIAS "LZDone" ()
DECLARE FUNCTION CopyLZFile LIB "LZ32.DLL" ALIAS "CopyLZFile" (BYVAL n1 AS LONG, BYVAL n2 AS LONG) AS LONG
DECLARE FUNCTION LZCopy LIB "LZ32.DLL" ALIAS "LZCopy" (BYVAL hfSource AS DWORD, BYVAL hfDest AS DWORD) AS LONG
DECLARE FUNCTION LZInit LIB "LZ32.DLL" ALIAS "LZInit" (BYVAL hfSrc AS DWORD) AS LONG
DECLARE FUNCTION GetExpandedNameA LIB "LZ32.DLL" ALIAS "GetExpandedNameA" (lpszSource AS ASCIIZ, lpszBuffer AS ASCIIZ) AS LONG
DECLARE FUNCTION GetExpandedNameW LIB "LZ32.DLL" ALIAS "GetExpandedNameW" (lpszSource AS WSTRINGZ, lpszBuffer AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetExpandedName LIB "LZ32.DLL" ALIAS "GetExpandedNameW" (lpszSource AS WSTRINGZ, lpszBuffer AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION GetExpandedName LIB "LZ32.DLL" ALIAS "GetExpandedNameA" (lpszSource AS ASCIIZ, lpszBuffer AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION LZOpenFileA LIB "LZ32.DLL" ALIAS "LZOpenFileA" (lpszFile AS ASCIIZ, lpOf AS OFSTRUCT, BYVAL STYLE AS WORD) AS LONG
DECLARE FUNCTION LZOpenFileW LIB "LZ32.DLL" ALIAS "LZOpenFileW" (lpszFile AS WSTRINGZ, lpOf AS OFSTRUCT, BYVAL STYLE AS WORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION LZOpenFile LIB "LZ32.DLL" ALIAS "LZOpenFileW" (lpszFile AS WSTRINGZ, lpOf AS OFSTRUCT, BYVAL STYLE AS WORD) AS LONG
#ELSE
DECLARE FUNCTION LZOpenFile LIB "LZ32.DLL" ALIAS "LZOpenFileA" (lpszFile AS ASCIIZ, lpOf AS OFSTRUCT, BYVAL STYLE AS WORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION LZSeek LIB "LZ32.DLL" ALIAS "LZSeek" (BYVAL hfFile AS DWORD, BYVAL lOffset AS LONG, BYVAL nOrigin AS LONG) AS LONG
DECLARE FUNCTION LZRead LIB "LZ32.DLL" ALIAS "LZRead" (BYVAL hfFile AS DWORD, lpvBuf AS ASCIIZ, BYVAL cbread AS LONG) AS LONG
DECLARE SUB LZClose LIB "LZ32.DLL" ALIAS "LZClose" (BYVAL hfFile AS DWORD)
