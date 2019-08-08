'------------------------------------------------------------------------------
'
'  WinVer.inc
'      Include file for VER.DLL.  This library is
'      designed to allow version stamping of Windows executable files
'      and of special .VER files for DOS executable files.
'
'  Copyright (c) 1997-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 25 Feb 2011
'
'------------------------------------------------------------------------------
'  from WinVer.h dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%VER_H = 1

#INCLUDE "verrsrc.inc"


' ----- Function prototypes -----

DECLARE FUNCTION VerFindFileA LIB "VERSION.DLL" ALIAS "VerFindFileA" _
    (BYVAL uFlags AS DWORD, szFileName AS ASCIIZ, szWinDir AS ASCIIZ, _
    szAppDir AS ASCIIZ, szCurDir AS ASCIIZ, lpuCurDirLen AS DWORD, _
    szDestDir AS ASCIIZ, lpuDestDirLen AS DWORD) AS DWORD

DECLARE FUNCTION VerFindFileW LIB "VERSION.DLL" ALIAS "VerFindFileW" _
    (BYVAL uFlags AS DWORD, szFileName AS WSTRINGZ, szWinDir AS WSTRINGZ, _
    szAppDir AS WSTRINGZ, szCurDir AS WSTRINGZ, lpuCurDirLen AS DWORD, _
    szDestDir AS WSTRINGZ, lpuDestDirLen AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION VerFindFile LIB "VERSION.DLL" ALIAS "VerFindFileW" _
    (BYVAL uFlags AS DWORD, szFileName AS WSTRINGZ, szWinDir AS WSTRINGZ, _
    szAppDir AS WSTRINGZ, szCurDir AS WSTRINGZ, lpuCurDirLen AS DWORD, _
    szDestDir AS WSTRINGZ, lpuDestDirLen AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION VerFindFile LIB "VERSION.DLL" ALIAS "VerFindFileA" _
    (BYVAL uFlags AS DWORD, szFileName AS ASCIIZ, szWinDir AS ASCIIZ, _
    szAppDir AS ASCIIZ, szCurDir AS ASCIIZ, lpuCurDirLen AS DWORD, _
    szDestDir AS ASCIIZ, lpuDestDirLen AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION VerInstallFileA LIB "VERSION.DLL" ALIAS "VerInstallFileA" _
    (BYVAL uFlags AS DWORD, szSrcFileName AS ASCIIZ, _
    szDestFileName AS ASCIIZ, szSrcDir AS ASCIIZ, szDestDir AS ASCIIZ, _
    szCurDir AS ASCIIZ, szTmpFile AS ASCIIZ, lpuTmpFileLen AS DWORD) AS DWORD

DECLARE FUNCTION VerInstallFileW LIB "VERSION.DLL" ALIAS "VerInstallFileW" _
    (BYVAL uFlags AS DWORD, szSrcFileName AS WSTRINGZ, _
    szDestFileName AS WSTRINGZ, szSrcDir AS WSTRINGZ, szDestDir AS WSTRINGZ, _
    szCurDir AS WSTRINGZ, szTmpFile AS WSTRINGZ, lpuTmpFileLen AS DWORD) _
    AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION VerInstallFile LIB "VERSION.DLL" ALIAS "VerInstallFileW" _
    (BYVAL uFlags AS DWORD, szSrcFileName AS WSTRINGZ, _
    szDestFileName AS WSTRINGZ, szSrcDir AS WSTRINGZ, szDestDir AS WSTRINGZ, _
    szCurDir AS WSTRINGZ, szTmpFile AS WSTRINGZ, lpuTmpFileLen AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION VerInstallFile LIB "VERSION.DLL" ALIAS "VerInstallFileA" _
    (BYVAL uFlags AS DWORD, szSrcFileName AS ASCIIZ, _
    szDestFileName AS ASCIIZ, szSrcDir AS ASCIIZ, szDestDir AS ASCIIZ, _
    szCurDir AS ASCIIZ, szTmpFile AS ASCIIZ, lpuTmpFileLen AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

' Returns size of version info in bytes
DECLARE FUNCTION GetFileVersionInfoSizeA LIB "VERSION.DLL" _
    ALIAS "GetFileVersionInfoSizeA" _
    (lptstrFilename AS ASCIIZ, _    ' Filename of version stamped file
    lpdwHandle AS DWORD) _          ' Information for use by GetFileVersionInfo
    AS DWORD

' Returns size of version info in bytes
DECLARE FUNCTION GetFileVersionInfoSizeW LIB "VERSION.DLL" _
    ALIAS "GetFileVersionInfoSizeW" _
    (lptstrFilename AS WSTRINGZ, _  ' Filename of version stamped file
    lpdwHandle AS DWORD) _          ' Information for use by GetFileVersionInfo
    AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetFileVersionInfoSize LIB "VERSION.DLL" _
    ALIAS "GetFileVersionInfoSizeW" _
    (lptstrFilename AS WSTRINGZ, _  ' Filename of version stamped file
    lpdwHandle AS DWORD) _          ' Information for use by GetFileVersionInfo
    AS DWORD
#ELSE
DECLARE FUNCTION GetFileVersionInfoSize LIB "VERSION.DLL" _
    ALIAS "GetFileVersionInfoSizeA" _
    (lptstrFilename AS ASCIIZ, _    ' Filename of version stamped file
    lpdwHandle AS DWORD) _          ' Information for use by GetFileVersionInfo
    AS DWORD
#ENDIF ' NOT %UNICODE

' Read version info into buffer
DECLARE FUNCTION GetFileVersionInfoA LIB "VERSION.DLL"  _
    ALIAS "GetFileVersionInfoA" _
    (lptstrFilename AS ASCIIZ, _    ' Filename of version stamped file
    BYVAL dwHandle AS DWORD, _      ' Information from GetFileVersionSize
    BYVAL dwLen AS DWORD, _         ' Length of buffer for info
    lpData AS ANY) _                ' Buffer to place the data structure
    AS LONG

' Read version info into buffer
DECLARE FUNCTION GetFileVersionInfoW LIB "VERSION.DLL"  _
    ALIAS "GetFileVersionInfoW" _
    (lptstrFilename AS WSTRINGZ, _  ' Filename of version stamped file
    BYVAL dwHandle AS DWORD, _      ' Information from GetFileVersionSize
    BYVAL dwLen AS DWORD, _         ' Length of buffer for info
    lpData AS ANY) _                ' Buffer to place the data structure
    AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetFileVersionInfo LIB "VERSION.DLL"  _
    ALIAS "GetFileVersionInfoW" _
    (lptstrFilename AS WSTRINGZ, _  ' Filename of version stamped file
    BYVAL dwHandle AS DWORD, _      ' Information from GetFileVersionSize
    BYVAL dwLen AS DWORD, _         ' Length of buffer for info
    lpData AS ANY) _                ' Buffer to place the data structure
    AS LONG
#ELSE
DECLARE FUNCTION GetFileVersionInfo LIB "VERSION.DLL"  _
    ALIAS "GetFileVersionInfoA" _
    (lptstrFilename AS ASCIIZ, _    ' Filename of version stamped file
    BYVAL dwHandle AS DWORD, _      ' Information from GetFileVersionSize
    BYVAL dwLen AS DWORD, _         ' Length of buffer for info
    lpData AS ANY) _                ' Buffer to place the data structure
    AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetFileVersionInfoSizeExA LIB "VERSION.DLL"  _
    ALIAS "GetFileVersionInfoSizeExA" (BYVAL dwFlags AS DWORD, _
    lptstrFilename AS ASCIIZ, lpdwHandle AS DWORD) AS DWORD

DECLARE FUNCTION GetFileVersionInfoSizeExW LIB "VERSION.DLL"  _
    ALIAS "GetFileVersionInfoSizeExW" (BYVAL dwFlags AS DWORD, _
    lptstrFilename AS WSTRINGZ, lpdwHandle AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetFileVersionInfoSizeEx LIB "VERSION.DLL"  _
    ALIAS "GetFileVersionInfoSizeExW" (BYVAL dwFlags AS DWORD, _
    lptstrFilename AS WSTRINGZ, lpdwHandle AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetFileVersionInfoSizeEx LIB "VERSION.DLL"  _
    ALIAS "GetFileVersionInfoSizeExA" (BYVAL dwFlags AS DWORD, _
    lptstrFilename AS ASCIIZ, lpdwHandle AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetFileVersionInfoExA LIB "VERSION.DLL"  _
    ALIAS "GetFileVersionInfoExA" (BYVAL dwFlags AS DWORD, _
    lptstrFilename AS ASCIIZ, BYVAL dwHandle AS DWORD, _
    BYVAL dwLen AS DWORD, lpData AS ANY) AS LONG

DECLARE FUNCTION GetFileVersionInfoExW LIB "VERSION.DLL"  _
    ALIAS "GetFileVersionInfoExW" (BYVAL dwFlags AS DWORD, _
    lptstrFilename AS WSTRINGZ, BYVAL dwHandle AS DWORD, _
    BYVAL dwLen AS DWORD, lpData AS ANY) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetFileVersionInfoEx LIB "VERSION.DLL"  _
    ALIAS "GetFileVersionInfoExW" (BYVAL dwFlags AS DWORD, _
    lptstrFilename AS WSTRINGZ, BYVAL dwHandle AS DWORD, _
    BYVAL dwLen AS DWORD, lpData AS ANY) AS LONG
#ELSE
DECLARE FUNCTION GetFileVersionInfoEx LIB "VERSION.DLL"  _
    ALIAS "GetFileVersionInfoExA" (BYVAL dwFlags AS DWORD, _
    lptstrFilename AS ASCIIZ, BYVAL dwHandle AS DWORD, _
    BYVAL dwLen AS DWORD, lpData AS ANY) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION VerLanguageNameA LIB "Version.dll" _
    ALIAS "VerLanguageNameA" (BYVAL wLang AS DWORD, szLang AS ASCIIZ, _
    BYVAL cchLang AS DWORD) AS DWORD

DECLARE FUNCTION VerLanguageNameW LIB "Version.dll" _
    ALIAS "VerLanguageNameW" (BYVAL wLang AS DWORD, szLang AS WSTRINGZ, _
    BYVAL cchLang AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION VerLanguageName LIB "Version.dll" _
    ALIAS "VerLanguageNameW" (BYVAL wLang AS DWORD, szLang AS WSTRINGZ, _
    BYVAL cchLang AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION VerLanguageName LIB "Version.dll" _
    ALIAS "VerLanguageNameA" (BYVAL wLang AS DWORD, szLang AS ASCIIZ, _
    BYVAL cchLang AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION VerQueryValueA LIB "VERSION.DLL" ALIAS "VerQueryValueA" _
    (BYVAL pBlock AS DWORD, lpSubBlock AS ASCIIZ, lplpBuffer AS DWORD, _
    puLen AS DWORD) AS LONG

DECLARE FUNCTION VerQueryValueW LIB "VERSION.DLL" ALIAS "VerQueryValueW" _
    (BYVAL pBlock AS DWORD, lpSubBlock AS WSTRINGZ, lplpBuffer AS DWORD, _
    puLen AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION VerQueryValue LIB "VERSION.DLL" ALIAS "VerQueryValueW" _
    (BYVAL pBlock AS DWORD, lpSubBlock AS WSTRINGZ, lplpBuffer AS DWORD, _
    puLen AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION VerQueryValue LIB "VERSION.DLL" ALIAS "VerQueryValueA" _
    (BYVAL pBlock AS DWORD, lpSubBlock AS ASCIIZ, lplpBuffer AS DWORD, _
    puLen AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE
