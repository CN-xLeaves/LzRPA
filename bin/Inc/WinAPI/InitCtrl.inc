'==============================================================================
'
' InitCtrl.inc - Initialize ComCtl32.dll and return its version number.
'
' Copyright (c) 2001-2011 PowerBASIC, Inc.
' All Rights Reserved.
'
' Here we use LoadLibrary and GetProcAddress to avoid crash on failure when
' older Win95 systems are running without the later IE3+ ComCtl32 versions.
'
' Example use:  ComCtlVersion = InitComCtl32(%ICC_BAR_CLASSES)
' If the InitComCtl32() parameter is zero, it defaults to initialization
' with %ICC_WIN95_CLASSES only.
'
' Last updated 31 Jan 2011
'
'==============================================================================

#INCLUDE THIS ONCE

%INITCTRL_INC = 1

#INCLUDE "WinDef.inc"
#INCLUDE "VerRsrc.inc"
#INCLUDE "WinBase.inc"
#INCLUDE "WinVer.inc"
#INCLUDE "CommCtrl.inc"

DECLARE FUNCTION zInitCommonControlsEx (iccex AS INIT_COMMON_CONTROLSEX) _
    AS LONG



'------------------------------------------------------------------------------
' Retrieve the version number of an OS component file, e.g., COMCTL32.DLL
'------------------------------------------------------------------------------
FUNCTION GetSysFileVerA ALIAS "GetSysFileVerA" (BYVAL sFileName AS STRING) _
    AS CURRENCYX

    LOCAL ncbVersionInfo AS LONG
    LOCAL dHandle        AS DWORD
    LOCAL pFI            AS VS_FIXEDFILEINFO PTR
    LOCAL sVersionInfo   AS STRING
    LOCAL szFileSpec     AS ASCIIZ * %MAX_PATH

    ' Get System directory/folder path
    IF ISFALSE GetSystemDirectoryA(szFileSpec, %MAX_PATH) THEN
        EXIT FUNCTION
    END IF

    IF RIGHT$(szFileSpec, 1) = "\" THEN
        szFileSpec += sFileName
    ELSE
        szFileSpec += "\" + sFileName
    END IF

    ncbVersionInfo = GetFileVersionInfoSizeA(szFileSpec, dHandle)
    IF ncbVersionInfo = 0 THEN
        EXIT FUNCTION
    END IF

    sVersionInfo = SPACE$(ncbVersionInfo)
    IF ISFALSE GetFileVersionInfoA(szFileSpec, 0, ncbVersionInfo, _
       BYVAL STRPTR(sVersionInfo)) THEN
        EXIT FUNCTION
    END IF

    IF ISFALSE VerQueryValueA(BYVAL STRPTR(sVersionInfo), "\", pFI, _
       ncbVersionInfo) THEN
        EXIT FUNCTION
    END IF

    FUNCTION = HI(WORD, @pFI.dwFileVersionMS) _
             + LO(WORD, @pFI.dwFileVersionMS) / 100

END FUNCTION

'------------------------------------------------------------------------------
' Retrieve the version number of an OS component file, e.g., COMCTL32.DLL
'------------------------------------------------------------------------------
FUNCTION GetSysFileVerW ALIAS "GetSysFileVerW" (BYVAL sFileName AS STRING) _
    AS CURRENCYX

    LOCAL ncbVersionInfo AS LONG
    LOCAL dHandle        AS DWORD
    LOCAL pFI            AS VS_FIXEDFILEINFO PTR
    LOCAL sVersionInfo   AS STRING
    LOCAL szFileSpec     AS WSTRINGZ * %MAX_PATH

    ' Get System directory/folder path
    IF ISFALSE GetSystemDirectoryW(szFileSpec, %MAX_PATH) THEN
        EXIT FUNCTION
    END IF

    IF RIGHT$(szFileSpec, 1) = "\"$$ THEN
        szFileSpec += sFileName
    ELSE
        szFileSpec += "\"$$ + sFileName
    END IF

    ncbVersionInfo = GetFileVersionInfoSizeW(szFileSpec, dHandle)
    IF ncbVersionInfo = 0 THEN
        EXIT FUNCTION
    END IF

    sVersionInfo = SPACE$(ncbVersionInfo)
    IF ISFALSE GetFileVersionInfoW(szFileSpec, 0, ncbVersionInfo, _
       BYVAL STRPTR(sVersionInfo)) THEN
        EXIT FUNCTION
    END IF

    IF ISFALSE VerQueryValueW(BYVAL STRPTR(sVersionInfo), "\"$$, pFI, _
       ncbVersionInfo) THEN
        EXIT FUNCTION
    END IF

    FUNCTION = HI(WORD, @pFI.dwFileVersionMS) _
             + LO(WORD, @pFI.dwFileVersionMS) / 100

END FUNCTION

#IF %DEF(%UNICODE)
MACRO GetSysFileVer=GetSysFileVerW
#ELSE
MACRO GetSysFileVer=GetSysFileVerA
#ENDIF



'------------------------------------------------------------------------------
' Safely initialize the Common Control Library, and return the version number
' of the DLL as a CURRENCYX/CUX data type, e.g., 4.71.
'------------------------------------------------------------------------------
FUNCTION InitComCtl32A ALIAS "InitComCtl32A" _
    (OPTIONAL BYVAL iccClasses AS DWORD) AS CURRENCYX

    LOCAL hLib   AS DWORD
    LOCAL dwProc AS DWORD
    LOCAL iccex  AS INIT_COMMON_CONTROLSEX

    ' Use dynamic (run-time) linking to initialize the common control library
    ' unless only a very old version is installed. Implicit (load-time) linking
    ' should be avoided, since this will stop the application from starting up
    ' if the "InitCommonControlsEx" API is not available in ComCtl32.dll
    ' (as might be true of early Windows 95 releases).

    hLib = LoadLibraryA("ComCtl32.dll")
    IF hLib THEN
        dwProc = GetProcAddress(hLib, "InitCommonControlsEx")
        IF dwProc THEN
            iccex.dwSize = SIZEOF(iccex)
            iccex.dwICC = IIF&(iccClasses, iccClasses, %ICC_WIN95_CLASSES)
            CALL DWORD dwProc USING zInitCommonControlsEx(iccex)
        ELSE
            InitCommonControls
        END IF

        FreeLibrary hLib

        FUNCTION = GetSysFileVerA("ComCtl32.dll")
    END IF

END FUNCTION

'------------------------------------------------------------------------------
' Safely initialize the Common Control Library, and return the version number
' of the DLL as a CURRENCYX/CUX data type, e.g., 4.71.
'------------------------------------------------------------------------------
FUNCTION InitComCtl32W ALIAS "InitComCtl32W" _
    (OPTIONAL BYVAL iccClasses AS DWORD) AS CURRENCYX

    LOCAL hLib   AS DWORD
    LOCAL dwProc AS DWORD
    LOCAL iccex  AS INIT_COMMON_CONTROLSEX

    ' Use dynamic (run-time) linking to initialize the common control library
    ' unless only a very old version is installed. Implicit (load-time) linking
    ' should be avoided, since this will stop the application from starting up
    ' if the "InitCommonControlsEx" API is not available in ComCtl32.dll
    ' (as might be true of early Windows 95 releases).

    hLib = LoadLibraryW("ComCtl32.dll"$$)
    IF hLib THEN
        ' note: GetProcAddress always uses ANSI strings
        dwProc = GetProcAddress(hLib, "InitCommonControlsEx")
        IF dwProc THEN
            iccex.dwSize = SIZEOF(iccex)
            iccex.dwICC = IIF&(iccClasses, iccClasses, %ICC_WIN95_CLASSES)
            CALL DWORD dwProc USING zInitCommonControlsEx(iccex)
        ELSE
            InitCommonControls
        END IF

        FreeLibrary hLib

        FUNCTION = GetSysFileVerW("ComCtl32.dll"$$)
    END IF

END FUNCTION

#IF %DEF(%UNICODE)
MACRO InitComCtl32=InitComCtl32W
#ELSE
MACRO InitComCtl32=InitComCtl32A
#ENDIF
