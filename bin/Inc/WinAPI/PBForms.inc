'---------------------------------------------------------------------------------
'
'   ** PBForms.inc ** Macros for PowerBASIC Forms
'
'   Copyright (c) 2002, 2003, 2011 PowerBASIC, Inc.
'   All Rights Reserved.
'
'   Last Update: 31 Jan 2011
'
'   Note: PowerBASIC Forms expects the macros to be in the original form.
'         Any modification to the macros could cause the generated PBForms
'         files to not compile or function as expected.
'
'---------------------------------------------------------------------------------

#INCLUDE THIS ONCE

'---------------------------------------------------------------------------------
'   ** Constants **
'---------------------------------------------------------------------------------
%PBFORMS_INC = 1

'---------------------------------------------------------------------------------
'   ** Structures **
'---------------------------------------------------------------------------------
#IF NOT %DEF(%COMMCTRL_INC)
TYPE INIT_COMMON_CONTROLSEX
    dwSize AS DWORD   ' size of this structure
    dwICC  AS DWORD   ' flags indicating which classes to be initialized
END TYPE
#ENDIF

'---------------------------------------------------------------------------------
'   ** Declarations **
'---------------------------------------------------------------------------------
DECLARE FUNCTION PBFormsInitCommonControlsEx(iccex AS INIT_COMMON_CONTROLSEX) AS LONG

'---------------------------------------------------------------------------------
'   ** Macros **
'---------------------------------------------------------------------------------
MACRO FUNCTION PBFormsMakeFont(sFntName, fFntSize, lWeight, lUnderlined, lItalic, lStrike, lCharSet)
'
' Examples of Use:
'
'    hFont = PBFormsMakeFont("MS Sans Serif", 8, %FW_NORMAL, %FALSE, %FALSE, %FALSE, %DEFAULT_CHARSET)
'    hFont = PBFormsMakeFont("Courier New", 10, %FW_BOLD, %FALSE, %FALSE, %FALSE, %DEFAULT_CHARSET)
'    hFont = PBFormsMakeFont("Marlett", 8, %FW_NORMAL, %FALSE, %FALSE, %FALSE, %SYMBOL_CHARSET)
'
' Note: Any font created with PBFormsMakeFont should also be destroyed with DeleteObject
'       when no longer needed to prevent memory leaks.  For example:
'
'        Case %WM_DESTROY
'            DeleteObject hFont

    MACROTEMP       lf
    MACROTEMP       hDC
    MACROTEMP       lCyPixels

    DIM lf          AS LOGFONT
    DIM hDC         AS DWORD
    DIM lCyPixels   AS LONG

    hDC         = GetDC(%HWND_DESKTOP)
    lCyPixels   = GetDeviceCaps(hDC, %LOGPIXELSY)
    ReleaseDC %HWND_DESKTOP, hDC

    lf.lfHeight         = -(fFntSize * lCyPixels) \ 72
    lf.lfFaceName       = sFntName
    lf.lfPitchAndFamily = %FF_DONTCARE
    IF lWeight = %FW_DONTCARE THEN
        lf.lfWeight = %FW_NORMAL
    ELSE
        lf.lfWeight = lWeight
    END IF
    lf.lfUnderline  = lUnderlined
    lf.lfItalic     = lItalic
    lf.lfStrikeOut  = lStrike
    lf.lfCharSet    = lCharSet

END MACRO = CreateFontIndirect(lf)
'---------------------------------------------------------------------------------

'---------------------------------------------------------------------------------
MACRO PBFormsInitComCtls(icc)
    MACROTEMP   iccex
    MACROTEMP   hLib
    MACROTEMP   pProc

    DIM iccex   AS INIT_COMMON_CONTROLSEX
    DIM hLib    AS DWORD
    DIM pProc   AS DWORD

    hLib = LoadLibrary("COMCTL32.DLL")
    IF hLib THEN
        pProc = GetProcAddress(hLib, "InitCommonControlsEx")
        IF pProc THEN
            iccex.dwSize    = SIZEOF(iccex)
            iccex.dwICC     = icc
            CALL DWORD pProc USING PBFormsInitCommonControlsEx(iccex)
        ELSE
            InitCommonControls
        END IF
        FreeLibrary hLib
    END IF
END MACRO
'---------------------------------------------------------------------------------

'---------------------------------------------------------------------------------
'   ** Functions **
'---------------------------------------------------------------------------------
#IF %DEF(%RICHEDIT_INC) ' Include only if RICHEDIT.INC is included in the code

FUNCTION PBFormsRichEdit(OPTIONAL BYVAL fUnLoad AS LONG) AS STRING
    ' * PBFormsRichEdit() without a parameter will load and return the
    '   class name of the best possible version of RichEdit installed.
    ' * Subsequent calls simply return the class name (eg, for use in
    '   CONTROL ADD statements, etc).
    ' * PBFormsRichEdit(%TRUE) will force the library to be unloaded.

    STATIC hLibRichEdit    AS DWORD
    STATIC szRichEditClass AS STRING

    IF ISFALSE fUnload THEN
        ' Load and/or return class name
        IF ISFALSE hLibRichEdit THEN
            ' First try RichEdit 4.1 (Windows XP/SP1)
            hLibRichEdit = LoadLibrary("MSFTEDIT.DLL")

            IF ISTRUE hLibRichEdit THEN
                szRichEditClass = "RichEdit50W"

            ELSE
                ' Next try RichEdit 2.0 or 3.0
                hLibRichEdit = LoadLibrary("RICHED20.DLL")

                IF ISTRUE hLibRichEdit THEN
                    szRichEditClass = "RichEdit20A"

                ELSE
                    ' Else try RichEdit 1.0
                    hLibRichEdit = LoadLibrary("RICHED32.DLL")

                    IF ISTRUE hLibRichEdit THEN
                        szRichEditClass = "RichEdit"

                    ELSE
                        ' No RichEdit control available, use Edit.
                        szRichEditClass = "Edit"
                    END IF
                END IF
            END IF
        END IF
        ' Return the class name
        FUNCTION = szRichEditClass
    ELSE
        ' Unload the RichEdit library
        IF hLibRichEdit THEN
            CALL FreeLibrary(hLibRichEdit)
            hLibRichEdit = 0
        END IF
        FUNCTION = ""
    END IF
END FUNCTION

'---------------------------------------------------------------------------------
#ENDIF ' #IF %DEF(%RICHEDIT_INC)
