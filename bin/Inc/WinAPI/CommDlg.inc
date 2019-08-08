'------------------------------------------------------------------------------
'
'  CommDlg.inc -- This module defines the 32-Bit Common Dialog APIs
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from CommDlg.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

#INCLUDE "WinGDI.inc"

#IF (%WINVER >= &H0500)

#IF %DEF(%DEFINE_GUID)

'
'  IPrintDialogCallback interface id used by PrintDlgEx.
'
MACRO IID_IPrintDialogCallback=GUID$("{5852A2C3-6530-11D1-B6A3-0000F8757BF9}")

'
'  IPrintDialogServices interface id used by PrintDlgEx.
'
MACRO IID_IPrintDialogServices=GUID$("{509AAEDA-5639-11D1-B6A1-0000F8757BF9}")

#ENDIF  ' %DEFINE_GUID

#ENDIF  ' %WINVER >= &H0500



#IF NOT %DEF(%GUID_DEFS_ONLY)
#INCLUDE "PrSht.inc"
#ENDIF  ' NOT %DEF(%GUID_DEFS_ONLY)

#IF %DEF(%MAC)
TYPE EDITMENU
    hmenu   AS DWORD
    idEdit  AS WORD
    idCut   AS WORD
    idCopy  AS WORD
    idPaste AS WORD
    idClear AS WORD
    idUndo  AS WORD
END TYPE
#ENDIF

DECLARE FUNCTION LPOFNHOOKPROC (BYVAL h AS DWORD, BYVAL u AS DWORD, _
    BYVAL w AS DWORD, BYVAL l AS LONG) AS DWORD


'#ifndef CDSIZEOF_STRUCT
'#define CDSIZEOF_STRUCT(structname, member)  (((int)((LPBYTE)(&((structname*)0)->member) - ((LPBYTE)((structname*)0)))) + sizeof(((structname*)0)->member))
'#endif

TYPE OPENFILENAME_NT4A
    lStructSize       AS DWORD
    hwndOwner         AS DWORD
    hInstance         AS DWORD
    lpstrFilter       AS ASCIIZ PTR
    lpstrCustomFilter AS ASCIIZ PTR
    nMaxCustFilter    AS DWORD
    nFilterIndex      AS DWORD
    lpstrFile         AS ASCIIZ PTR
    nMaxFile          AS DWORD
    lpstrFileTitle    AS ASCIIZ PTR
    nMaxFileTitle     AS DWORD
    lpstrInitialDir   AS ASCIIZ PTR
    lpstrTitle        AS ASCIIZ PTR
    Flags             AS DWORD
    nFileOffset       AS WORD
    nFileExtension    AS WORD
    lpstrDefExt       AS ASCIIZ PTR
    lCustData         AS LONG
    lpfnHook          AS DWORD
    lpTemplateName    AS ASCIIZ PTR
END TYPE

TYPE OPENFILENAME_NT4W
    lStructSize       AS DWORD
    hwndOwner         AS DWORD
    hInstance         AS DWORD
    lpstrFilter       AS WSTRINGZ PTR
    lpstrCustomFilter AS WSTRINGZ PTR
    nMaxCustFilter    AS DWORD
    nFilterIndex      AS DWORD
    lpstrFile         AS WSTRINGZ PTR
    nMaxFile          AS DWORD
    lpstrFileTitle    AS WSTRINGZ PTR
    nMaxFileTitle     AS DWORD
    lpstrInitialDir   AS WSTRINGZ PTR
    lpstrTitle        AS WSTRINGZ PTR
    Flags             AS DWORD
    nFileOffset       AS WORD
    nFileExtension    AS WORD
    lpstrDefExt       AS WSTRINGZ PTR
    lCustData         AS LONG
    lpfnHook          AS DWORD
    lpTemplateName    AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE OPENFILENAME_NT4
    OPENFILENAME_NT4W
END TYPE
#ELSE
TYPE OPENFILENAME_NT4
    OPENFILENAME_NT4A
END TYPE
#ENDIF

TYPE OPENFILENAMEA
    lStructSize       AS DWORD
    hWndOwner         AS DWORD
    hInstance         AS DWORD
    lpstrFilter       AS ASCIIZ PTR
    lpstrCustomFilter AS ASCIIZ PTR
    nMaxCustFilter    AS DWORD
    nFilterIndex      AS DWORD
    lpstrFile         AS ASCIIZ PTR
    nMaxFile          AS DWORD
    lpstrFileTitle    AS ASCIIZ PTR
    nMaxFileTitle     AS DWORD
    lpstrInitialDir   AS ASCIIZ PTR
    lpstrTitle        AS ASCIIZ PTR
    Flags             AS DWORD
    nFileOffset       AS WORD
    nFileExtension    AS WORD
    lpstrDefExt       AS ASCIIZ PTR
    lCustData         AS LONG
    lpfnHook          AS DWORD
    lpTemplateName    AS ASCIIZ PTR
#IF %DEF(%MAC)
    lpEditInfo        AS EDITMENU PTR
    lpstrPrompt       AS ASCIIZ PTR
#ENDIF
#IF (%WIN32_WINNT >= &H0500)
    pvReserved        AS DWORD
    dwReserved        AS DWORD
    FlagsEx           AS DWORD
#ENDIF
END TYPE

TYPE OPENFILENAMEW
    lStructSize       AS DWORD
    hWndOwner         AS DWORD
    hInstance         AS DWORD
    lpstrFilter       AS WSTRINGZ PTR
    lpstrCustomFilter AS WSTRINGZ PTR
    nMaxCustFilter    AS DWORD
    nFilterIndex      AS DWORD
    lpstrFile         AS WSTRINGZ PTR
    nMaxFile          AS DWORD
    lpstrFileTitle    AS WSTRINGZ PTR
    nMaxFileTitle     AS DWORD
    lpstrInitialDir   AS WSTRINGZ PTR
    lpstrTitle        AS WSTRINGZ PTR
    Flags             AS DWORD
    nFileOffset       AS WORD
    nFileExtension    AS WORD
    lpstrDefExt       AS WSTRINGZ PTR
    lCustData         AS LONG
    lpfnHook          AS DWORD
    lpTemplateName    AS WSTRINGZ PTR
#IF %DEF(%MAC)
    lpEditInfo        AS EDITMENU PTR
    lpstrPrompt       AS WSTRINGZ PTR
#ENDIF
#IF (%WIN32_WINNT >= &H0500)
    pvReserved        AS DWORD
    dwReserved        AS DWORD
    FlagsEx           AS DWORD
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
TYPE OPENFILENAME
    OPENFILENAMEW
END TYPE
#ELSE
TYPE OPENFILENAME
    OPENFILENAMEA
END TYPE
#ENDIF

#IF (%WIN32_WINNT >= &H0500)
%OPENFILENAME_SIZE_VERSION_400A = 76 ' CDSIZEOF_STRUCT(OPENFILENAMEA,lpTemplateName)
%OPENFILENAME_SIZE_VERSION_400W = 76 ' CDSIZEOF_STRUCT(OPENFILENAMEW,lpTemplateName)
#IF %DEF(%UNICODE)
%OPENFILENAME_SIZE_VERSION_400 = %OPENFILENAME_SIZE_VERSION_400W
#ELSE
%OPENFILENAME_SIZE_VERSION_400 = %OPENFILENAME_SIZE_VERSION_400A
#ENDIF ' NOT %UNICODE
#ENDIF ' (%WIN32_WINNT >= &H0500)

DECLARE FUNCTION GetOpenFileNameA LIB "ComDlg32.dll" ALIAS "GetOpenFileNameA" _
    (lpofn AS OPENFILENAMEA) AS LONG

DECLARE FUNCTION GetOpenFileNameW LIB "ComDlg32.dll" ALIAS "GetOpenFileNameW" _
    (lpofn AS OPENFILENAMEW) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetOpenFileName LIB "ComDlg32.dll" ALIAS "GetOpenFileNameW" _
    (lpofn AS OPENFILENAMEW) AS LONG
#ELSE
DECLARE FUNCTION GetOpenFileName LIB "ComDlg32.dll" ALIAS "GetOpenFileNameA" _
    (lpofn AS OPENFILENAMEA) AS LONG
#ENDIF

DECLARE FUNCTION GetSaveFileNameA LIB "COMDLG32.DLL" ALIAS "GetSaveFileNameA" _
    (lpofn AS OPENFILENAMEA) AS LONG

DECLARE FUNCTION GetSaveFileNameW LIB "COMDLG32.DLL" ALIAS "GetSaveFileNameW" _
    (lpofn AS OPENFILENAMEW) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetSaveFileName LIB "COMDLG32.DLL" ALIAS "GetSaveFileNameW" _
    (lpofn AS OPENFILENAMEW) AS LONG
#ELSE
DECLARE FUNCTION GetSaveFileName LIB "COMDLG32.DLL" ALIAS "GetSaveFileNameA" _
    (lpofn AS OPENFILENAMEA) AS LONG
#ENDIF

DECLARE FUNCTION GetFileTitleA LIB "COMDLG32.DLL" ALIAS "GetFileTitleA" _
    (lpszFile AS ASCIIZ, lpszTitle AS ASCIIZ, BYVAL cbBuf AS WORD) AS INTEGER

DECLARE FUNCTION GetFileTitleW LIB "COMDLG32.DLL" ALIAS "GetFileTitleW" _
    (lpszFile AS WSTRINGZ, lpszTitle AS WSTRINGZ, BYVAL cbBuf AS WORD) _
    AS INTEGER

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetFileTitle LIB "COMDLG32.DLL" ALIAS "GetFileTitleW" _
    (lpszFile AS WSTRINGZ, lpszTitle AS WSTRINGZ, BYVAL cbBuf AS WORD) _
    AS INTEGER
#ELSE
DECLARE FUNCTION GetFileTitle LIB "COMDLG32.DLL" ALIAS "GetFileTitleA" _
    (lpszFile AS ASCIIZ, lpszTitle AS ASCIIZ, BYVAL cbBuf AS WORD) AS INTEGER
#ENDIF

%OFN_READONLY             = &H00000001
%OFN_OVERWRITEPROMPT      = &H00000002
%OFN_HIDEREADONLY         = &H00000004
%OFN_NOCHANGEDIR          = &H00000008
%OFN_SHOWHELP             = &H00000010
%OFN_ENABLEHOOK           = &H00000020
%OFN_ENABLETEMPLATE       = &H00000040
%OFN_ENABLETEMPLATEHANDLE = &H00000080
%OFN_NOVALIDATE           = &H00000100
%OFN_ALLOWMULTISELECT     = &H00000200
%OFN_EXTENSIONDIFFERENT   = &H00000400
%OFN_PATHMUSTEXIST        = &H00000800
%OFN_FILEMUSTEXIST        = &H00001000
%OFN_CREATEPROMPT         = &H00002000
%OFN_SHAREAWARE           = &H00004000
%OFN_NOREADONLYRETURN     = &H00008000
%OFN_NOTESTFILECREATE     = &H00010000
%OFN_NONETWORKBUTTON      = &H00020000
%OFN_NOLONGNAMES          = &H00040000 ' force no long names for 4.x modules
#IF (%WINVER >= &H0400)
%OFN_EXPLORER             = &H00080000 ' new look commdlg
%OFN_NODEREFERENCELINKS   = &H00100000
%OFN_LONGNAMES            = &H00200000 ' force long names for 3.x modules
' OFN_ENABLEINCLUDENOTIFY and OFN_ENABLESIZING require
' Windows 2000 or higher to have any effect.
%OFN_ENABLEINCLUDENOTIFY  = &H00400000 ' send include message to callback
%OFN_ENABLESIZING         = &H00800000
#ENDIF  ' %WINVER >= &H0400
#IF %WIN32_WINNT >= &H0500
%OFN_DONTADDTORECENT      = &H02000000
%OFN_FORCESHOWHIDDEN      = &H10000000 ' Show All files including System and hidden files
#ENDIF  ' %WIN32_WINNT >= &H0500

' FlagsEx Values
#IF (%WIN32_WINNT >= &H0500)
%OFN_EX_NOPLACESBAR       = &H00000001
#ENDIF  ' (%WIN32_WINNT >= &H0500)

' Return values for the registered message sent to the hook function
' when a sharing violation occurs.  %OFN_SHAREFALLTHROUGH allows the
' filename to be accepted, %OFN_SHARENOWARN rejects the name but puts
' up no warning (returned when the app has already put up a warning
' message), and %OFN_SHAREWARN puts up the default warning message
' for sharing violations.
'
' Note:  Undefined return values map to OFN_SHAREWARN, but are
'        reserved for future use.

%OFN_SHAREFALLTHROUGH     = 2
%OFN_SHARENOWARN          = 1
%OFN_SHAREWARN            = 0

DECLARE FUNCTION LPCCHOOKPROC (BYVAL h AS DWORD, BYVAL u AS DWORD, _
    BYVAL w AS DWORD, BYVAL l AS LONG) AS DWORD

#IF (%WINVER >= &H0400)

' Structure used for all file based OpenFileName notifications
TYPE OFNOTIFYA
    hdr     AS NMHDR
    lpOFN   AS OPENFILENAMEA PTR
    pszFile AS ASCIIZ PTR                ' May be %NULL
END TYPE

' Structure used for all file based OpenFileName notifications
TYPE OFNOTIFYW
    hdr     AS NMHDR
    lpOFN   AS OPENFILENAMEW PTR
    pszFile AS WSTRINGZ PTR              ' May be %NULL
END TYPE

#IF %DEF(%UNICODE)
TYPE OFNOTIFY
    OFNOTIFYW
END TYPE
#ELSE
TYPE OFNOTIFY
    OFNOTIFYA
END TYPE
#ENDIF

' Structure used for all object based OpenFileName notifications
TYPE OFNOTIFYEXA
    hdr     AS NMHDR
    lpOFN   AS OPENFILENAMEA PTR
    psf     AS DWORD
    pidl    AS DWORD          ' May be %NULL
END TYPE

' Structure used for all object based OpenFileName notifications
TYPE OFNOTIFYEXW
    hdr     AS NMHDR
    lpOFN   AS OPENFILENAMEW PTR
    psf     AS DWORD
    pidl    AS DWORD          ' May be %NULL
END TYPE

#IF %DEF(%UNICODE)
TYPE OFNOTIFYEX
    OFNOTIFYEXW
END TYPE
#ELSE
TYPE OFNOTIFYEX
    OFNOTIFYEXA
END TYPE
#ENDIF

%CDN_FIRST = 0-601
%CDN_LAST  = 0-699

' Notifications from Open or Save dialog
%CDN_INITDONE         = %CDN_FIRST - &H0000
%CDN_SELCHANGE        = %CDN_FIRST - &H0001
%CDN_FOLDERCHANGE     = %CDN_FIRST - &H0002
%CDN_SHAREVIOLATION   = %CDN_FIRST - &H0003
%CDN_HELP             = %CDN_FIRST - &H0004
%CDN_FILEOK           = %CDN_FIRST - &H0005
%CDN_TYPECHANGE       = %CDN_FIRST - &H0006
#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)
%CDN_INCLUDEITEM      = %CDN_FIRST - &H0007
#ENDIF

%CDM_FIRST           = %WM_USER + 100
%CDM_LAST            = %WM_USER + 200

' Messages to query information from the Open or Save dialogs

' lParam = pointer to text buffer that gets filled in
' wParam = max number of characters of the text buffer (including %NULL)
' return = < 0 if error; number of characters needed (including %NULL)

%CDM_GETSPEC         = %CDM_FIRST + &H0

FUNCTION CommDlg_OpenSave_GetSpecA (BYVAL hdlg AS DWORD, psz AS ASCIIZ, _
   BYVAL cbmax AS DWORD) AS LONG

    FUNCTION = SendMessage(hdlg, %CDM_GETSPEC, cbmax, BYVAL VARPTR(psz))

END FUNCTION

FUNCTION CommDlg_OpenSave_GetSpecW (BYVAL hdlg AS DWORD, psz AS WSTRINGZ, _
   BYVAL cbmax AS DWORD) AS LONG

    FUNCTION = SendMessage(hdlg, %CDM_GETSPEC, cbmax, BYVAL VARPTR(psz))

END FUNCTION

#IF %DEF(%UNICODE)
FUNCTION CommDlg_OpenSave_GetSpec (BYVAL hdlg AS DWORD, psz AS WSTRINGZ, _
   BYVAL cbmax AS DWORD) AS LONG

    FUNCTION = SendMessage(hdlg, %CDM_GETSPEC, cbmax, BYVAL VARPTR(psz))

END FUNCTION
#ELSE
FUNCTION CommDlg_OpenSave_GetSpec (BYVAL hdlg AS DWORD, psz AS ASCIIZ, _
   BYVAL cbmax AS DWORD) AS LONG

    FUNCTION = SendMessage(hdlg, %CDM_GETSPEC, cbmax, BYVAL VARPTR(psz))

END FUNCTION
#ENDIF

' lParam = pointer to text buffer that gets filled in
' wParam = max number of characters of the text buffer (including NULL)
' return = < 0 if error; number of characters needed (including NULL)

%CDM_GETFILEPATH     = %CDM_FIRST + &H1

FUNCTION CommDlg_OpenSave_GetFilePathA (BYVAL hdlg AS DWORD, psz AS ASCIIZ, _
   BYVAL cbmax AS DWORD) AS LONG

    FUNCTION = SendMessage(hdlg, %CDM_GETFILEPATH, cbmax, BYVAL VARPTR(psz))

END FUNCTION

FUNCTION CommDlg_OpenSave_GetFilePathW (BYVAL hdlg AS DWORD, psz AS WSTRINGZ, _
   BYVAL cbmax AS DWORD) AS LONG

    FUNCTION = SendMessage(hdlg, %CDM_GETFILEPATH, cbmax, BYVAL VARPTR(psz))

END FUNCTION

#IF %DEF(%UNICODE)
FUNCTION CommDlg_OpenSave_GetFilePath (BYVAL hdlg AS DWORD, psz AS WSTRINGZ, _
   BYVAL cbmax AS DWORD) AS LONG

    FUNCTION = SendMessage(hdlg, %CDM_GETFILEPATH, cbmax, BYVAL VARPTR(psz))

END FUNCTION
#ELSE
FUNCTION CommDlg_OpenSave_GetFilePath (BYVAL hdlg AS DWORD, psz AS ASCIIZ, _
   BYVAL cbmax AS DWORD) AS LONG

    FUNCTION = SendMessage(hdlg, %CDM_GETFILEPATH, cbmax, BYVAL VARPTR(psz))

END FUNCTION
#ENDIF


' lParam = pointer to text buffer that gets filled in
' wParam = max number of characters of the text buffer (including %NULL)
' return = < 0 if error; number of characters needed (including %NULL)

%CDM_GETFOLDERPATH   = %CDM_FIRST + &H2

FUNCTION CommDlg_OpenSave_GetFolderPathA (BYVAL hdlg AS DWORD, _
   psz AS ASCIIZ, BYVAL cbmax AS DWORD) AS LONG

    FUNCTION = SendMessage(hdlg, %CDM_GETFOLDERPATH, cbmax, BYVAL VARPTR(psz))

END FUNCTION

FUNCTION CommDlg_OpenSave_GetFolderPathW (BYVAL hdlg AS DWORD, _
   psz AS WSTRINGZ, BYVAL cbmax AS DWORD) AS LONG

    FUNCTION = SendMessage(hdlg, %CDM_GETFOLDERPATH, cbmax, BYVAL VARPTR(psz))

END FUNCTION

#IF %DEF(%UNICODE)
FUNCTION CommDlg_OpenSave_GetFolderPath (BYVAL hdlg AS DWORD, _
   psz AS WSTRINGZ, BYVAL cbmax AS DWORD) AS LONG

    FUNCTION = SendMessage(hdlg, %CDM_GETFOLDERPATH, cbmax, BYVAL VARPTR(psz))

END FUNCTION
#ELSE
FUNCTION CommDlg_OpenSave_GetFolderPath (BYVAL hdlg AS DWORD, _
   psz AS ASCIIZ, BYVAL cbmax AS DWORD) AS LONG

    FUNCTION = SendMessage(hdlg, %CDM_GETFOLDERPATH, cbmax, BYVAL VARPTR(psz))

END FUNCTION
#ENDIF


' lParam = pointer to ITEMIDLIST buffer that gets filled in
' wParam = size of the ITEMIDLIST buffer
' return = < 0 if error; length of buffer needed

%CDM_GETFOLDERIDLIST = %CDM_FIRST + &H3

MACRO CommDlg_OpenSave_GetFolderIDList(hdlg, pidl, cbmax)=SendMessage(hdlg, %CDM_GETFOLDERIDLIST, cbmax, pidl)


' lParam = pointer to a string
' wParam = ID of control to change
' return = not used

%CDM_SETCONTROLTEXT  = %CDM_FIRST + &H4

SUB CommDlg_OpenSave_SetControlText (BYVAL hdlg AS DWORD, BYVAL ID AS DWORD, _
   pszTEXT AS ASCIIZ)

    SendMessage hdlg, %CDM_SETCONTROLTEXT, ID, BYVAL VARPTR(pszTEXT)

END SUB


' lParam = not used
' wParam = ID of control to change
' return = not used

%CDM_HIDECONTROL     = %CDM_FIRST + &H5

MACRO CommDlg_OpenSave_HideControl(hdlg, ID)=SendMessage(hdlg, %CDM_HIDECONTROL, ID, 0)


' lParam = pointer to default extension (no dot)
' wParam = not used
' return = not used

%CDM_SETDEFEXT       = %CDM_FIRST + &H6

SUB CommDlg_OpenSave_SetDefExt (BYVAL hdlg AS DWORD, pszext AS ASCIIZ)

    SendMessage hdlg, %CDM_SETDEFEXT, 0, BYVAL VARPTR(pszext)

END SUB

#ENDIF  ' %WINVER >= &H0400


#IF NOT %DEF(%MAC)

TYPE CHOOSECOLORA_type
    lStructSize    AS DWORD
    hwndOwner      AS DWORD
    hInstance      AS DWORD
    rgbResult      AS DWORD
    lpCustColors   AS DWORD PTR
    Flags          AS DWORD
    lCustData      AS LONG
    lpfnHook       AS DWORD
    lpTemplateName AS ASCIIZ PTR
END TYPE

' [legacy]
TYPE CHOOSECOLORAPI
    CHOOSECOLORA_type
END TYPE

TYPE CHOOSECOLORW_type
    lStructSize    AS DWORD
    hwndOwner      AS DWORD
    hInstance      AS DWORD
    rgbResult      AS DWORD
    lpCustColors   AS DWORD PTR
    Flags          AS DWORD
    lCustData      AS LONG
    lpfnHook       AS DWORD
    lpTemplateName AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE CHOOSECOLOR_type
    CHOOSECOLORW_type
END TYPE
#ELSE
TYPE CHOOSECOLOR_type
    CHOOSECOLORA_type
END TYPE
#ENDIF

#ELSE

TYPE CHOOSECOLORA_type
    lStructSize    AS DWORD
    hwndOwner      AS DWORD
    hInstance      AS DWORD
    rgbResult      AS DWORD
    lpCustColors   AS DWORD PTR
    Flags          AS DWORD
    lCustData      AS LONG
    lpfnHook       AS DWORD
    lpTemplateName AS ASCIIZ PTR
    lpEditInfo     AS EDITMENU PTR
END TYPE

TYPE CHOOSECOLORW_type
    lStructSize    AS DWORD
    hwndOwner      AS DWORD
    hInstance      AS DWORD
    rgbResult      AS DWORD
    lpCustColors   AS DWORD PTR
    Flags          AS DWORD
    lCustData      AS LONG
    lpfnHook       AS DWORD
    lpTemplateName AS WSTRINGZ PTR
    lpEditInfo     AS EDITMENU PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE CHOOSECOLOR_type
    CHOOSECOLORW_type
END TYPE
#ELSE
TYPE CHOOSECOLOR_type
    CHOOSECOLORA_type
END TYPE
#ENDIF

#ENDIF  ' %MAC

DECLARE FUNCTION ChooseColorA LIB "COMDLG32.DLL" ALIAS "ChooseColorA" _
    (lpcc AS CHOOSECOLORA_type) AS LONG

DECLARE FUNCTION ChooseColorW LIB "COMDLG32.DLL" ALIAS "ChooseColorW" _
    (lpcc AS CHOOSECOLORW_type) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ChooseColor LIB "COMDLG32.DLL" ALIAS "ChooseColorW" _
    (lpcc AS CHOOSECOLORW_type) AS LONG
#ELSE
DECLARE FUNCTION ChooseColor LIB "COMDLG32.DLL" ALIAS "ChooseColorA" _
    (lpcc AS CHOOSECOLORA_type) AS LONG
#ENDIF

%CC_RGBINIT               = &H00000001
%CC_FULLOPEN              = &H00000002
%CC_PREVENTFULLOPEN       = &H00000004
%CC_SHOWHELP              = &H00000008
%CC_ENABLEHOOK            = &H00000010
%CC_ENABLETEMPLATE        = &H00000020
%CC_ENABLETEMPLATEHANDLE  = &H00000040
#IF %WINVER >= &H0400
%CC_SOLIDCOLOR            = &H00000080
%CC_ANYCOLOR              = &H00000100
#ENDIF

DECLARE FUNCTION LPFRHOOKPROC (BYVAL h AS DWORD, BYVAL u AS DWORD, _
    BYVAL w AS DWORD, BYVAL l AS LONG) AS DWORD

TYPE FINDREPLACEA
    lStructSize      AS DWORD        ' size of this struct 0x20
    hWndOwner        AS DWORD        ' handle to owner's window
    hInstance        AS DWORD        ' instance handle of.EXE that
                                     '   contains cust. dlg. template
    Flags            AS DWORD        ' one or more of the FR_??
    lpstrFindWhat    AS ASCIIZ PTR   ' ptr. to search string
    lpstrReplaceWith AS ASCIIZ PTR   ' ptr. to replace string
    wFindWhatLen     AS WORD         ' size of find buffer
    wReplaceWithLen  AS WORD         ' size of replace buffer
    lCustData        AS LONG         ' data passed to hook fn.
    lpfnHook         AS DWORD        ' ptr. to hook fn. or NULL
    lpTemplateName   AS ASCIIZ PTR   ' custom template name
END TYPE

TYPE FINDREPLACEW
    lStructSize      AS DWORD        ' size of this struct 0x20
    hWndOwner        AS DWORD        ' handle to owner's window
    hInstance        AS DWORD        ' instance handle of.EXE that
                                     '   contains cust. dlg. template
    Flags            AS DWORD        ' one or more of the FR_??
    lpstrFindWhat    AS WSTRINGZ PTR ' ptr. to search string
    lpstrReplaceWith AS WSTRINGZ PTR ' ptr. to replace string
    wFindWhatLen     AS WORD         ' size of find buffer
    wReplaceWithLen  AS WORD         ' size of replace buffer
    lCustData        AS LONG         ' data passed to hook fn.
    lpfnHook         AS DWORD        ' ptr. to hook fn. or NULL
    lpTemplateName   AS WSTRINGZ PTR ' custom template name
END TYPE

#IF %DEF(%UNICODE)
TYPE FINDREPLACE
    FINDREPLACEW
END TYPE
#ELSE
TYPE FINDREPLACE
    FINDREPLACEA
END TYPE
#ENDIF

%FR_DOWN                 = &H00000001&
%FR_WHOLEWORD            = &H00000002&
%FR_MATCHCASE            = &H00000004&
%FR_FINDNEXT             = &H00000008&
%FR_REPLACE              = &H00000010&
%FR_REPLACEALL           = &H00000020&
%FR_DIALOGTERM           = &H00000040&
%FR_SHOWHELP             = &H00000080&
%FR_ENABLEHOOK           = &H00000100&
%FR_ENABLETEMPLATE       = &H00000200&
%FR_NOUPDOWN             = &H00000400&
%FR_NOMATCHCASE          = &H00000800&
%FR_NOWHOLEWORD          = &H00001000&
%FR_ENABLETEMPLATEHANDLE = &H00002000&
%FR_HIDEUPDOWN           = &H00004000&
%FR_HIDEMATCHCASE        = &H00008000&
%FR_HIDEWHOLEWORD        = &H00010000&
#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)
%FR_RAW                  = &H00020000
%FR_MATCHDIAC            = &H20000000
%FR_MATCHKASHIDA         = &H40000000
%FR_MATCHALEFHAMZA       = &H80000000???
#ENDIF  ' (%NTDDI_VERSION >= %NTDDI_WIN2K)

DECLARE FUNCTION FindTextA LIB "COMDLG32.DLL" ALIAS "FindTextA" _
    (lpfr AS FINDREPLACEA) AS DWORD

DECLARE FUNCTION FindTextW LIB "COMDLG32.DLL" ALIAS "FindTextW" _
    (lpfr AS FINDREPLACEW) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION FindText LIB "COMDLG32.DLL" ALIAS "FindTextW" _
    (lpfr AS FINDREPLACEW) AS DWORD
#ELSE
DECLARE FUNCTION FindText LIB "COMDLG32.DLL" ALIAS "FindTextA" _
    (lpfr AS FINDREPLACEA) AS DWORD
#ENDIF

DECLARE FUNCTION ReplaceTextA LIB "COMDLG32.DLL" ALIAS "ReplaceTextA" _
    (lpfr AS FINDREPLACEA) AS DWORD

DECLARE FUNCTION ReplaceTextW LIB "COMDLG32.DLL" ALIAS "ReplaceTextW" _
    (lpfr AS FINDREPLACEW) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION ReplaceText LIB "COMDLG32.DLL" ALIAS "ReplaceTextW" _
    (lpfr AS FINDREPLACEW) AS DWORD
#ELSE
DECLARE FUNCTION ReplaceText LIB "COMDLG32.DLL" ALIAS "ReplaceTextA" _
    (lpfr AS FINDREPLACEA) AS DWORD
#ENDIF

' [these functions are not documented and don't seem to be exported]
'DECLARE FUNCTION AfxReplaceTextA LIB "COMDLG32.DLL" ALIAS "AfxReplaceTextA" _
'    (lpfr AS FINDREPLACEA) AS DWORD
'
'DECLARE FUNCTION AfxReplaceTextW LIB "COMDLG32.DLL" ALIAS "AfxReplaceTextW" _
'    (lpfr AS FINDREPLACEW) AS DWORD
'
'#IF %DEF(%UNICODE)
'MACRO AfxReplaceText=AfxReplaceTextW
'#ELSE
'MACRO AfxReplaceText=AfxReplaceTextA
'#ENDIF


DECLARE FUNCTION LPCFHOOKPROC (BYVAL h AS DWORD, BYVAL u AS DWORD, _
    BYVAL w AS DWORD, BYVAL l AS LONG) AS DWORD


TYPE CHOOSEFONTA_type DWORD
    lStructSize    AS DWORD
    hwndOwner      AS DWORD          ' caller's window handle
    hDC            AS DWORD          ' printer DC/IC or NULL
    lpLogFont      AS LOGFONTA PTR   ' ptr. to a LOGFONT struct
    iPointSize     AS LONG           ' 10 * size in points of selected font
    Flags          AS DWORD          ' enum. type flags
    rgbColors      AS DWORD          ' returned text color
    lCustData      AS LONG           ' data passed to hook fn.
    lpfnHook       AS DWORD          ' ptr. to hook function
    lpTemplateName AS ASCIIZ PTR     ' custom template name
    hInstance      AS DWORD          ' instance handle of.EXE that
                                     '   contains cust. dlg. template
    lpszStyle      AS ASCIIZ PTR     ' return the style field here
                                     ' must be LF_FACESIZE or bigger
    nFontType      AS WORD           ' same value reported to the EnumFonts
                                     '   call back with the extra FONTTYPE_
                                     '   bits added
    nSizeMin       AS LONG           ' minimum pt size allowed &
    nSizeMax       AS LONG           ' max pt size allowed if
                                     '   CF_LIMITSIZE is used
END TYPE

' [legacy]
TYPE CHOOSEFONTAPI
    CHOOSEFONTA_type
END TYPE

TYPE CHOOSEFONTW_type DWORD
    lStructSize    AS DWORD
    hwndOwner      AS DWORD          ' caller's window handle
    hDC            AS DWORD          ' printer DC/IC or NULL
    lpLogFont      AS LOGFONTW PTR   ' ptr. to a LOGFONT struct
    iPointSize     AS LONG           ' 10 * size in points of selected font
    Flags          AS DWORD          ' enum. type flags
    rgbColors      AS DWORD          ' returned text color
    lCustData      AS LONG           ' data passed to hook fn.
    lpfnHook       AS DWORD          ' ptr. to hook function
    lpTemplateName AS WSTRINGZ PTR   ' custom template name
    hInstance      AS DWORD          ' instance handle of.EXE that
                                     '   contains cust. dlg. template
    lpszStyle      AS WSTRINGZ PTR   ' return the style field here
                                     ' must be LF_FACESIZE or bigger
    nFontType      AS WORD           ' same value reported to the EnumFonts
                                     '   call back with the extra FONTTYPE_
                                     '   bits added
    nSizeMin       AS LONG           ' minimum pt size allowed &
    nSizeMax       AS LONG           ' max pt size allowed if
                                     '   CF_LIMITSIZE is used
END TYPE

#IF %DEF(%UNICODE)
TYPE ChooseFont_type
    ChooseFontW_type
END TYPE
#ELSE
TYPE ChooseFont_type
    ChooseFontA_type
END TYPE
#ENDIF

DECLARE FUNCTION ChooseFontA LIB "COMDLG32.DLL" ALIAS "ChooseFontA" _
    (lpcf AS CHOOSEFONTA_type) AS LONG

DECLARE FUNCTION ChooseFontW LIB "COMDLG32.DLL" ALIAS "ChooseFontW" _
    (lpcf AS CHOOSEFONTW_type) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION ChooseFont LIB "COMDLG32.DLL" ALIAS "ChooseFontW" _
    (lpcf AS CHOOSEFONTW_type) AS LONG
#ELSE
DECLARE FUNCTION ChooseFont LIB "COMDLG32.DLL" ALIAS "ChooseFontA" _
    (lpcf AS CHOOSEFONTA_type) AS LONG
#ENDIF

%CF_SCREENFONTS            = &H00000001&
%CF_PRINTERFONTS           = &H00000002&
%CF_BOTH                   = %CF_SCREENFONTS OR %CF_PRINTERFONTS
%CF_SHOWHELP               = &H00000004&
%CF_ENABLEHOOK             = &H00000008&
%CF_ENABLETEMPLATE         = &H00000010&
%CF_ENABLETEMPLATEHANDLE   = &H00000020&
%CF_INITTOLOGFONTSTRUCT    = &H00000040&
%CF_USESTYLE               = &H00000080&
%CF_EFFECTS                = &H00000100&
%CF_APPLY                  = &H00000200&
#IF %WINVER >= &H0400
%CF_ANSIONLY               = &H00000400&
#ENDIF
%CF_SCRIPTSONLY            = %CF_ANSIONLY
%CF_NOVECTORFONTS          = &H00000800&
%CF_NOOEMFONTS             = %CF_NOVECTORFONTS
%CF_NOSIMULATIONS          = &H00001000&
%CF_LIMITSIZE              = &H00002000&
%CF_FIXEDPITCHONLY         = &H00004000&
%CF_WYSIWYG                = &H00008000& ' must also have CF_SCREENFONTS & CF_PRINTERFONTS
%CF_FORCEFONTEXIST         = &H00010000&
%CF_SCALABLEONLY           = &H00020000&
%CF_TTONLY                 = &H00040000&
%CF_NOFACESEL              = &H00080000&
%CF_NOSTYLESEL             = &H00100000&
%CF_NOSIZESEL              = &H00200000&
#IF %WINVER > &H0400
%CF_SELECTSCRIPT           = &H00400000&
%CF_NOSCRIPTSEL            = &H00800000&
%CF_NOVERTFONTS            = &H01000000&
#ENDIF  ' %WINVER >= &H0400
#IF (%WINVER >= &H0601)
%CF_INACTIVEFONTS          = &H02000000&
#ENDIF  ' %WINVER >= &H0601

' these are extra nFontType bits that are added to what is returned to the
' EnumFonts callback routine

%SIMULATED_FONTTYPE   = &H8000??
%PRINTER_FONTTYPE     = &H4000
%SCREEN_FONTTYPE      = &H2000
%BOLD_FONTTYPE        = &H0100
%ITALIC_FONTTYPE      = &H0200
%REGULAR_FONTTYPE     = &H0400

' EnumFonts callback routine only uses these bits, so we can use the rest

' %RASTER_FONTTYPE    = &H001
' %DEVICE_FONTTYPE    = &H002
' %TRUETYPE_FONTTYPE  = &H004

#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)
%PS_OPENTYPE_FONTTYPE = &H00010000
%TT_OPENTYPE_FONTTYPE = &H00020000
%TYPE1_FONTTYPE       = &H00040000
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WIN2K)

#IF (%WINVER >= &H0601)
%SYMBOL_FONTTYPE      = &H00080000
#ENDIF  ' %WINVER >= &H0601

%WM_CHOOSEFONT_GETLOGFONT = %WM_USER + 1
#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)
%WM_CHOOSEFONT_SETLOGFONT = %WM_USER + 101
%WM_CHOOSEFONT_SETFLAGS   = %WM_USER + 102
#ENDIF

' strings used to obtain unique window message for communication
' between dialog and caller

$LBSELCHSTRING = "commdlg_LBSelChangedNotify"
$SHAREVISTRING = "commdlg_ShareViolation"
$FILEOKSTRING  = "commdlg_FileNameOK"
$COLOROKSTRING = "commdlg_ColorOK"
$SETRGBSTRING  = "commdlg_SetRGBColor"
$HELPMSGSTRING = "commdlg_help"
$FINDMSGSTRING = "commdlg_FindReplace"

$$LBSELCHSTRING = "commdlg_LBSelChangedNotify"$$
$$SHAREVISTRING = "commdlg_ShareViolation"$$
$$FILEOKSTRING  = "commdlg_FileNameOK"$$
$$COLOROKSTRING = "commdlg_ColorOK"$$
$$SETRGBSTRING  = "commdlg_SetRGBColor"$$
$$HELPMSGSTRING = "commdlg_help"$$
$$FINDMSGSTRING = "commdlg_FindReplace"$$

#IF %DEF(%UNICODE)
MACRO LBSELCHSTRING = $$LBSELCHSTRING
MACRO SHAREVISTRING = $$SHAREVISTRING
MACRO FILEOKSTRING  = $$FILEOKSTRING
MACRO COLOROKSTRING = $$COLOROKSTRING
MACRO SETRGBSTRING  = $$SETRGBSTRING
MACRO HELPMSGSTRING = $$HELPMSGSTRING
MACRO FINDMSGSTRING = $$FINDMSGSTRING
#ELSE
MACRO LBSELCHSTRING = $LBSELCHSTRING
MACRO SHAREVISTRING = $SHAREVISTRING
MACRO FILEOKSTRING  = $FILEOKSTRING
MACRO COLOROKSTRING = $COLOROKSTRING
MACRO SETRGBSTRING  = $SETRGBSTRING
MACRO HELPMSGSTRING = $HELPMSGSTRING
MACRO FINDMSGSTRING = $FINDMSGSTRING
#ENDIF

' HIWORD values for lParam of commdlg_LBSelChangeNotify message
%CD_LBSELNOITEMS = &HFFFF??  ' (WORD)-1
%CD_LBSELCHANGE  = 0
%CD_LBSELSUB     = 1
%CD_LBSELADD     = 2

DECLARE FUNCTION LPPRINTHOOKPROC (BYVAL h AS DWORD, BYVAL u AS DWORD, _
    BYVAL w AS DWORD, BYVAL l AS LONG) AS DWORD

DECLARE FUNCTION LPSETUPHOOKPROC (BYVAL h AS DWORD, BYVAL u AS DWORD, _
    BYVAL w AS DWORD, BYVAL l AS LONG) AS DWORD

TYPE PRINTDLGA_type
    lStructSize              AS DWORD
    hWndOwner                AS DWORD
    hDevMode                 AS DWORD
    hDevNames                AS DWORD
    hDC                      AS DWORD
    Flags                    AS DWORD
    nFromPage                AS WORD
    nToPage                  AS WORD
    nMinPage                 AS WORD
    nMaxPage                 AS WORD
    nCopies                  AS WORD
    hInstance                AS DWORD
    lCustData                AS LONG
    lpfnPrintHook            AS DWORD
    lpfnSetupHook            AS DWORD
    lpPrintTemplateName      AS ASCIIZ PTR
    lpPrintSetupTemplateName AS ASCIIZ PTR
    hPrintTemplate           AS DWORD
    hSetupTemplate           AS DWORD
END TYPE

' [legacy]
TYPE PRINTDLGAPI
    PRINTDLGA_type
END TYPE

TYPE PRINTDLGW_type
    lStructSize              AS DWORD
    hWndOwner                AS DWORD
    hDevMode                 AS DWORD
    hDevNames                AS DWORD
    hDC                      AS DWORD
    Flags                    AS DWORD
    nFromPage                AS WORD
    nToPage                  AS WORD
    nMinPage                 AS WORD
    nMaxPage                 AS WORD
    nCopies                  AS WORD
    hInstance                AS DWORD
    lCustData                AS LONG
    lpfnPrintHook            AS DWORD
    lpfnSetupHook            AS DWORD
    lpPrintTemplateName      AS WSTRINGZ PTR
    lpPrintSetupTemplateName AS WSTRINGZ PTR
    hPrintTemplate           AS DWORD
    hSetupTemplate           AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE PRINTDLG_type
    PRINTDLGW_type
END TYPE
#ELSE
TYPE PRINTDLG_type
    PRINTDLGA_type
END TYPE
#ENDIF


DECLARE FUNCTION PrintDlgA LIB "COMDLG32.DLL" ALIAS "PrintDlgA" _
    (lpPd AS PRINTDLGA_type) AS LONG

DECLARE FUNCTION PrintDlgW LIB "COMDLG32.DLL" ALIAS "PrintDlgW" _
    (lpPd AS PRINTDLGW_type) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION PrintDlg LIB "COMDLG32.DLL" ALIAS "PrintDlgW" _
    (lpPd AS PRINTDLGW_type) AS LONG
#ELSE
DECLARE FUNCTION PrintDlg LIB "COMDLG32.DLL" ALIAS "PrintDlgA" _
    (lpPd AS PRINTDLGA_type) AS LONG
#ENDIF


#IF %WINVER >= &H0500

#IF %DEF(%STDMETHOD)

'-------------------------------------------------------------------------
'
'  IPrintDialogCallback Interface
'
'  IPrintDialogCallback::InitDone()
'    This function is called by PrintDlgEx when the system has finished
'    initializing the main page of the print dialog.  This function
'    should return S_OK if it has processed the action or S_FALSE to let
'    PrintDlgEx perform the default action.
'
'  IPrintDialogCallback::SelectionChange()
'    This function is called by PrintDlgEx when a selection change occurs
'    in the list view that displays the currently installed printers.
'    This function should return S_OK if it has processed the action or
'    S_FALSE to let PrintDlgEx perform the default action.
'
'  IPrintDialogCallback::HandleMessage(hDlg, uMsg, wParam, lParam, pResult)
'    This function is called by PrintDlgEx when a message is sent to the
'    child window of the main page of the print dialog.  This function
'    should return S_OK if it has processed the action or S_FALSE to let
'    PrintDlgEx perform the default action.
'
'  IObjectWithSite::SetSite(punkSite)
'    IPrintDialogCallback usually paired with IObjectWithSite.
'    Provides the IUnknown pointer of the site to QI for the
'    IPrintDialogServices interface.
'
'-------------------------------------------------------------------------

'#undef  INTERFACE
'#define INTERFACE   IPrintDialogCallback
'
'DECLARE_INTERFACE_IID_(IPrintDialogCallback, IUNKNOWN, "5852A2C3-6530-11D1-B6A3-0000F8757BF9")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
'    STDMETHOD_(ULONG, AddRef) (THIS) PURE;
'    STDMETHOD_(ULONG, Release) (THIS) PURE;
'
'    ' *** IPrintDialogCallback methods ***
'    STDMETHOD(InitDone) (THIS) PURE;
'    STDMETHOD(SelectionChange) (THIS) PURE;
'    STDMETHOD(HandleMessage) (THIS_ HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT *pResult) PURE;
'};


'-------------------------------------------------------------------------
'
'  IPrintDialogServices Interface
'
'  IPrintDialogServices::GetCurrentDevMode(pDevMode, pcbSize)
'    Returns the DEVMODE structure for the currently selected printer.
'
'  IPrintDialogServices::GetCurrentPrinterName(pPrinterName, pcchSize)
'    Returns the printer name for the currently selected printer.
'
'  IPrintDialogServices::GetCurrentPortName(pPortName, pcchSize)
'    Returns the port name for the currently selected printer.
'
'-------------------------------------------------------------------------

'#undef  INTERFACE
'#define INTERFACE   IPrintDialogServices
'
'DECLARE_INTERFACE_IID_(IPrintDialogServices, IUNKNOWN, "509AAEDA-5639-11D1-B6A1-0000F8757BF9")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
'    STDMETHOD_(ULONG, AddRef) (THIS) PURE;
'    STDMETHOD_(ULONG, Release) (THIS) PURE;
'
'    ' *** IPrintDialogServices methods ***
'    STDMETHOD(GetCurrentDevMode) (THIS_ __inout LPDEVMODE pDevMode, __inout UINT *pcbSize) PURE;
'    STDMETHOD(GetCurrentPrinterName) (THIS_ __out_ecount_opt(*pcchSize) LPWSTR pPrinterName, __inout UINT *pcchSize) PURE;
'    STDMETHOD(GetCurrentPortName) (THIS_ __out_ecount_opt(*pcchSize) LPWSTR pPortName, __inout UINT *pcchSize) PURE;
'};


#ENDIF ' %STDMETHOD [closing tag is incorectly placed later in the .h file]


'
'  Page Range structure for PrintDlgEx.
'
TYPE PRINTPAGERANGE
    nFromPage AS DWORD
    nToPage   AS DWORD
END TYPE


'
'  PrintDlgEx structure.
'
TYPE PRINTDLGEXA_type
    lStructSize         AS DWORD              ' size of structure in bytes
    hwndOwner           AS DWORD              ' caller's window handle
    hDevMode            AS DWORD              ' handle to DevMode
    hDevNames           AS DWORD              ' handle to DevNames
    hDC                 AS DWORD              ' printer DC/IC or %NULL
    Flags               AS DWORD              ' PD_ flags
    Flags2              AS DWORD              ' reserved
    ExclusionFlags      AS DWORD              ' items to exclude from driver pages
    nPageRanges         AS DWORD              ' number of page ranges
    nMaxPageRanges      AS DWORD              ' max number of page ranges
    lpPageRanges        AS PRINTPAGERANGE PTR ' array of page ranges
    nMinPage            AS DWORD              ' min page number
    nMaxPage            AS DWORD              ' max page number
    nCopies             AS DWORD              ' number of copies
    hInstance           AS DWORD              ' instance handle
    lpPrintTemplateName AS ASCIIZ PTR         ' template name for app specific area
    lpCallback          AS DWORD              ' app callback interface
    nPropertyPages      AS DWORD              ' number of app property pages in lphPropertyPages
    lphPropertyPages    AS DWORD PTR          ' array of app property page handles
    nStartPage          AS DWORD              ' start page id
    dwResultAction      AS DWORD              ' result action if S_OK is returned
END TYPE

' [legacy]
TYPE PRINTDLGEXAPI
    PRINTDLGEXA_type
END TYPE

'
'  PrintDlgEx structure.
'
TYPE PRINTDLGEXW_type
    lStructSize         AS DWORD              ' size of structure in bytes
    hwndOwner           AS DWORD              ' caller's window handle
    hDevMode            AS DWORD              ' handle to DevMode
    hDevNames           AS DWORD              ' handle to DevNames
    hDC                 AS DWORD              ' printer DC/IC or %NULL
    Flags               AS DWORD              ' PD_ flags
    Flags2              AS DWORD              ' reserved
    ExclusionFlags      AS DWORD              ' items to exclude from driver pages
    nPageRanges         AS DWORD              ' number of page ranges
    nMaxPageRanges      AS DWORD              ' max number of page ranges
    lpPageRanges        AS PRINTPAGERANGE PTR ' array of page ranges
    nMinPage            AS DWORD              ' min page number
    nMaxPage            AS DWORD              ' max page number
    nCopies             AS DWORD              ' number of copies
    hInstance           AS DWORD              ' instance handle
    lpPrintTemplateName AS WSTRINGZ PTR        ' template name for app specific area
    lpCallback          AS DWORD              ' app callback interface
    nPropertyPages      AS DWORD              ' number of app property pages in lphPropertyPages
    lphPropertyPages    AS DWORD PTR          ' array of app property page handles
    nStartPage          AS DWORD              ' start page id
    dwResultAction      AS DWORD              ' result action if S_OK is returned
END TYPE

#IF %DEF(%UNICODE)
TYPE PRINTDLGEX_type
    PRINTDLGEXW_type
END TYPE
#ELSE
TYPE PRINTDLGEX_type
    PRINTDLGEXA_type
END TYPE
#ENDIF


DECLARE FUNCTION PrintDlgExA LIB "COMDLG32.DLL" ALIAS "PrintDlgExA" _
    (lpPde AS PRINTDLGEXA_type) AS LONG

DECLARE FUNCTION PrintDlgExW LIB "COMDLG32.DLL" ALIAS "PrintDlgExW" _
    (lpPde AS PRINTDLGEXW_type) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION PrintDlgEx LIB "COMDLG32.DLL" ALIAS "PrintDlgExW" _
    (lpPde AS PRINTDLGEXW_type) AS LONG
#ELSE
DECLARE FUNCTION PrintDlgEx LIB "COMDLG32.DLL" ALIAS "PrintDlgExA" _
    (lpPde AS PRINTDLGEXA_type) AS LONG
#ENDIF

'
'  Flags for PrintDlg and PrintDlgEx.
'
%PD_ALLPAGES                    = &H00000000
%PD_SELECTION                   = &H00000001
%PD_PAGENUMS                    = &H00000002
%PD_NOSELECTION                 = &H00000004
%PD_NOPAGENUMS                  = &H00000008
%PD_COLLATE                     = &H00000010
%PD_PRINTTOFILE                 = &H00000020
%PD_PRINTSETUP                  = &H00000040
%PD_NOWARNING                   = &H00000080
%PD_RETURNDC                    = &H00000100
%PD_RETURNIC                    = &H00000200
%PD_RETURNDEFAULT               = &H00000400
%PD_SHOWHELP                    = &H00000800
%PD_ENABLEPRINTHOOK             = &H00001000
%PD_ENABLESETUPHOOK             = &H00002000
%PD_ENABLEPRINTTEMPLATE         = &H00004000
%PD_ENABLESETUPTEMPLATE         = &H00008000
%PD_ENABLEPRINTTEMPLATEHANDLE   = &H00010000
%PD_ENABLESETUPTEMPLATEHANDLE   = &H00020000
%PD_USEDEVMODECOPIES            = &H00040000
%PD_USEDEVMODECOPIESANDCOLLATE  = &H00040000
%PD_DISABLEPRINTTOFILE          = &H00080000
%PD_HIDEPRINTTOFILE             = &H00100000
%PD_NONETWORKBUTTON             = &H00200000
#IF %WINVER >= &H0500
%PD_CURRENTPAGE                 = &H00400000
%PD_NOCURRENTPAGE               = &H00800000
%PD_EXCLUSIONFLAGS              = &H01000000
%PD_USELARGETEMPLATE            = &H10000000
#ENDIF

#IF %WINVER >= &H0500

'
'  Exclusion flags for PrintDlgEx.
'
%PD_EXCL_COPIESANDCOLLATE = %DM_COPIES OR %DM_COLLATE


'
'  Define the start page for the print dialog when using PrintDlgEx.
'
%START_PAGE_GENERAL           = &HFFFFFFFF???


'
'  Result action ids for PrintDlgEx.
'
%PD_RESULT_CANCEL   = 0
%PD_RESULT_PRINT    = 1
%PD_RESULT_APPLY    = 2

#ENDIF ' %WINVER >= &H0500


'
'  Device Names structure for PrintDlg and PrintDlgEx.
'
TYPE DEVNAMES
    wDriverOffset AS WORD
    wDeviceOffset AS WORD
    wOutputOffset AS WORD
    wDefault      AS WORD
END TYPE

%DN_DEFAULTPRN = &H0001

DECLARE FUNCTION CommDlgExtendedError LIB "COMDLG32.DLL" _
    ALIAS "CommDlgExtendedError" () AS DWORD

%WM_PSD_PAGESETUPDLG   = %WM_USER
%WM_PSD_FULLPAGERECT   = %WM_USER + 1
%WM_PSD_MINMARGINRECT  = %WM_USER + 2
%WM_PSD_MARGINRECT     = %WM_USER + 3
%WM_PSD_GREEKTEXTRECT  = %WM_USER + 4
%WM_PSD_ENVSTAMPRECT   = %WM_USER + 5
%WM_PSD_YAFULLPAGERECT = %WM_USER + 6

DECLARE FUNCTION LPPAGEPAINTHOOKPROC (BYVAL h AS DWORD, BYVAL u AS DWORD, _
    BYVAL w AS DWORD, BYVAL l AS LONG) AS DWORD

DECLARE FUNCTION LPPAGESETUPHOOKPROC (BYVAL h AS DWORD, BYVAL u AS DWORD, _
    BYVAL w AS DWORD, BYVAL l AS LONG) AS DWORD

TYPE PAGESETUPDLGA_type
    lStructSize             AS DWORD
    hwndOwner               AS DWORD
    hDevMode                AS DWORD
    hDevNames               AS DWORD
    Flags                   AS DWORD
    ptPaperSize             AS POINT
    rtMinMargin             AS RECT
    rtMargin                AS RECT
    hInstance               AS DWORD
    lCustData               AS LONG
    lpfnPageSetupHook       AS DWORD
    lpfnPagePaintHook       AS DWORD
    lpPageSetupTemplateName AS ASCIIZ PTR
    hPageSetupTemplate      AS DWORD
END TYPE

TYPE PAGESETUPDLGW_type
    lStructSize             AS DWORD
    hwndOwner               AS DWORD
    hDevMode                AS DWORD
    hDevNames               AS DWORD
    Flags                   AS DWORD
    ptPaperSize             AS POINT
    rtMinMargin             AS RECT
    rtMargin                AS RECT
    hInstance               AS DWORD
    lCustData               AS LONG
    lpfnPageSetupHook       AS DWORD
    lpfnPagePaintHook       AS DWORD
    lpPageSetupTemplateName AS WSTRINGZ PTR
    hPageSetupTemplate      AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE PAGESETUPDLG_type
    PAGESETUPDLGW_type
END TYPE
#ELSE
TYPE PAGESETUPDLG_type
    PAGESETUPDLGA_type
END TYPE
#ENDIF


DECLARE FUNCTION PageSetupDlgA LIB "COMDLG32.DLL" ALIAS "PageSetupDlgA" _
    (lpPageSetupDlg AS PAGESETUPDLGA_type) AS LONG

DECLARE FUNCTION PageSetupDlgW LIB "COMDLG32.DLL" ALIAS "PageSetupDlgW" _
    (lpPageSetupDlg AS PAGESETUPDLGW_type) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION PageSetupDlg LIB "COMDLG32.DLL" ALIAS "PageSetupDlgW" _
    (lpPageSetupDlg AS PAGESETUPDLGW_type) AS LONG
#ELSE
DECLARE FUNCTION PageSetupDlg LIB "COMDLG32.DLL" ALIAS "PageSetupDlgA" _
    (lpPageSetupDlg AS PAGESETUPDLGA_type) AS LONG
#ENDIF

%PSD_DEFAULTMINMARGINS             = &H00000000 ' default (printer's)
%PSD_INWININIINTLMEASURE           = &H00000000 ' 1st of 4 possible

%PSD_MINMARGINS                    = &H00000001 ' use caller's
%PSD_MARGINS                       = &H00000002 ' use caller's
%PSD_INTHOUSANDTHSOFINCHES         = &H00000004 ' 2nd of 4 possible
%PSD_INHUNDREDTHSOFMILLIMETERS     = &H00000008 ' 3rd of 4 possible
%PSD_DISABLEMARGINS                = &H00000010
%PSD_DISABLEPRINTER                = &H00000020
%PSD_NOWARNING                     = &H00000080 ' must be same as PD_*
%PSD_DISABLEORIENTATION            = &H00000100
%PSD_RETURNDEFAULT                 = &H00000400 ' must be same as PD_*
%PSD_DISABLEPAPER                  = &H00000200
%PSD_SHOWHELP                      = &H00000800 ' must be same as PD_*
%PSD_ENABLEPAGESETUPHOOK           = &H00002000 ' must be same as PD_*
%PSD_ENABLEPAGESETUPTEMPLATE       = &H00008000 ' must be same as PD_*
%PSD_ENABLEPAGESETUPTEMPLATEHANDLE = &H00020000 ' must be same as PD_*
%PSD_ENABLEPAGEPAINTHOOK           = &H00040000
%PSD_DISABLEPAGEPAINTING           = &H00080000
%PSD_NONETWORKBUTTON               = &H00200000 ' must be same as PD_*

#ENDIF  ' %WINVER >= &H0400



'#IF NOT %DEF(%RC_INVOKED) ' RC complains about long symbols in #ifs
'#IF %DEF(%ISOLATION_AWARE_ENABLED) AND (%ISOLATION_AWARE_ENABLED <> 0)
'#INCLUDE "CommDlg.inl.inc"
'#ENDIF ' ISOLATION_AWARE_ENABLED
'#ENDIF ' RC
