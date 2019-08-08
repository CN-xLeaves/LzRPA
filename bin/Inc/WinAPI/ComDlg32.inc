'------------------------------------------------------------------------------
'
'  COMDLG32.INC -- Windows API Common Dialog declarations for PowerBASIC
'
'  Copyright (C) 1997-2011 PowerBASIC, Inc.
'  Portions Copyright (C) Microsoft Corporation
'  All Rights Reserved.
'
'  Last Update: 28 Mar 2011
'
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%COMDLG32_INC = 1

'
' Pull in Windows includes if necessary
'

#INCLUDE "CommDlg.inc"


#IF NOT %DEF(%NOPRINTDLG)

FUNCTION PrinterDialog (BYVAL hWnd AS DWORD, _      ' parent window
                        Flags AS DWORD, _           ' dialog flags
                        hDC AS DWORD, _             ' hDC of printer
                        nCopies AS WORD, _          ' Number of Copies
                        nFromPage AS WORD, _        ' From page number
                        nToPage AS WORD, _          ' To page number
                        BYVAL nMinPage AS WORD, _   ' Minimum page number
                        BYVAL nMaxPage AS WORD _    ' Maximum page number
                       ) AS LONG

    LOCAL pd AS PRINTDLG_type

    STATIC save_hDevMode  AS DWORD ' retain printer selection info
    STATIC save_hDevNames AS DWORD '  during the entire process

    pd.lStructSize = SIZEOF(pd)
    pd.hDevMode    = save_hDevMode
    pd.hDevNames   = save_hDevNames
    pd.hWndOwner   = hWnd
    pd.Flags       = Flags OR %PD_SHOWHELP
    pd.nCopies     = nCopies
    pd.nFromPage   = MAX(nFromPage, nMinPage)
    pd.nToPage     = MAX(MIN(nToPage, nMaxPage), nMaxPage)
    pd.nMinPage    = nMinPage
    pd.nMaxPage    = nMaxPage

    IF PrintDlg(pd) THEN
        hDC            = pd.hDC
        nCopies        = pd.nCopies
        nFromPage      = pd.nFromPage
        nToPage        = pd.nToPage
        Flags          = pd.Flags
        save_hDevMode  = pd.hDevMode
        save_hDevNames = pd.hDevNames
        FUNCTION = %TRUE
    END IF

END FUNCTION


MACRO FUNCTION PrinterSetup(hwnd)
    MACROTEMP d, w
    LOCAL d AS DWORD, w AS WORD
END MACRO=PrinterDialog(hwnd, %PD_PRINTSETUP, d, w, w, w, w, w)


#ENDIF ' #IF NOT %DEF(%NOPRINTDLG)



#IF NOT %DEF(%NOFILEDLG)

#IF NOT %DEF(%OFN_FILEBUFFERSIZE)
    ' Max bytes to allow for returning the selected file or list of files.
    ' This must be at least equal to %MAX_PATH for safety.
    %OFN_FILEBUFFERSIZE = 16384
#ENDIF

FUNCTION OpenFileDialog (BYVAL hWnd AS DWORD, _            ' parent window
                         BYVAL sCaption AS STRING, _       ' caption
                         sFileSpec AS STRING, _            ' filename
                         BYVAL sInitialDir AS STRING, _    ' start directory
                         BYVAL sFilter AS STRING, _        ' filename filter
                         BYVAL sDefExtension AS STRING, _  ' default extension
                         dFlags AS DWORD _                 ' flags
                        ) AS LONG

    LOCAL ix          AS LONG
    LOCAL ofn         AS OPENFILENAME_NT4A
    LOCAL szFileTitle AS ASCIIZ * %MAX_PATH

    ' Filter is a sequence of ASCIIZ strings with a final (extra) $NUL terminator
    REPLACE "|" WITH $NUL IN sFilter
    sFilter += $NUL

    IF LEN(sInitialDir) = 0 THEN
        sInitialDir = CURDIR$
    END IF

    sFileSpec = LSET$(sFileSpec, %OFN_FILEBUFFERSIZE USING $NUL)

    ofn.lStructSize      = SIZEOF(ofn)
    ofn.hWndOwner        = hWnd
    IF LEN(sFilter) THEN
        ofn.lpstrFilter  = STRPTR(sFilter)
    END IF
    ofn.nFilterIndex     = 1
    ofn.lpstrFile        = STRPTR(sFileSpec)
    ofn.nMaxFile         = LEN(sFileSpec)
    ofn.lpstrFileTitle   = VARPTR(szFileTitle)
    ofn.nMaxFileTitle    = SIZEOF(szFileTitle)
    IF LEN(sInitialDir) THEN
        ofn.lpstrInitialDir  = STRPTR(sInitialDir)
    END IF
    IF LEN(sCaption) THEN
        ofn.lpstrTitle   = STRPTR(sCaption)
    END IF
    ofn.Flags            = dFlags
    IF LEN(sDefExtension) THEN
        ofn.lpstrDefExt  = STRPTR(sDefExtension)
    END IF

    FUNCTION = GetOpenFilenameA(BYVAL VARPTR(ofn))

    ix = INSTR(sFileSpec, $NUL + $NUL)
    IF ix THEN
        sFileSpec = LEFT$(sFileSpec, ix - 1)
    ELSE
        ix = INSTR(sFileSpec, $NUL)
        sFileSpec = IIF$(ix, LEFT$(sFileSpec, ix - 1), "")
    END IF

    dFlags = ofn.Flags

END FUNCTION


FUNCTION FindExtInFilter (BYVAL sExt AS STRING, sDesc AS STRING, _
                          sExtList AS STRING) AS LONG

    LOCAL ix, iy  AS LONG
    LOCAL nc      AS LONG
    LOCAL sHeader AS STRING

    nc = PARSECOUNT(sExtList, ";")
    REDIM asExtList(1 TO nc) AS STRING
    PARSE sExtList, asExtList(), ";"

    FOR ix = 1 TO nc
        IF UCASE$(asExtList(ix)) = "*" + sExt THEN
            ' Got a match for our extension.
            IF ix > 1 THEN
                ' Rearrange extension list so our extension comes first.
                SWAP asExtList(1), asExtList(ix)
                sExtList = JOIN$(asExtList(), ";")
                REDIM asDesc(1 TO nc) AS STRING
                iy = INSTR(sDesc, "(")
                sHeader = LEFT$(sDesc, iy)
                sDesc = MID$(sDesc, iy + 1)
                sDesc = LEFT$(sDesc, -1)   ' trim off closing ")"
                PARSE sDesc, asDesc(), ","
                SWAP asDesc(1), asDesc(ix)
                sDesc = sHeader + JOIN$(asDesc(), ",") + ")"
            END IF
            FUNCTION = -1
            EXIT FUNCTION
        END IF
    NEXT

    FUNCTION = 0

END FUNCTION


FUNCTION FindFilterIndex (sFilter AS STRING, BYVAL sFileSpec AS STRING) AS LONG

    LOCAL ix, iy  AS LONG    ' indices
    LOCAL nc      AS LONG    ' item count
    LOCAL ixLevel AS LONG    ' filter index level
    LOCAL sExt    AS STRING  ' current file extension (if any)

    ' Get the default file extension in sExt.
    sFileSpec = RTRIM$(sFileSpec)
    ix = INSTR(-1, sFileSpec, ANY "\/:.")
    IF ix THEN
        IF MID$(sFileSpec, ix, 1) = "." THEN
            sExt = UCASE$(MID$(sFileSpec, ix))
        ELSE
            sExt = ".*"
        END IF
    END IF

    ' Parse the filter string out into an array, the better to work with it.
    sFilter = RTRIM$(sFilter, $NUL)
    nc = PARSECOUNT(sFilter, $NUL)
    IF (nc < 2) OR ((nc AND 1) = 1) THEN
        EXIT FUNCTION
    END IF
    REDIM asList(1 TO nc) AS STRING
    PARSE sFilter, asList(), $NUL
    ' ix = 1, e.g., "Source files (*.bas,*.inc)"
    ' ix = 2, e.g., "*.bas;*.inc"
    ' rinse, repeat.

    ' See which set of filters contains the default file extension.
    ' (If none, use the last one, assumed to be "*.*"). The filter set is
    ' rearranged as needed to make sure the default extension is the first
    ' one in the filter set, so Windows will apply the proper default if the
    ' user doesn't explicitly type in the extension.
    FOR ix = 1 TO nc - 1 STEP 2
        INCR ixLevel
        IF FindExtInFilter(sExt, asList(ix), asList(ix + 1)) THEN
            EXIT FOR
        END IF
    NEXT

    ' Rebuild the filter string, in case it was changed.
    sFilter = JOIN$(asList(), $NUL) + $NUL

    FUNCTION = ixLevel

END FUNCTION


FUNCTION SaveFileDialog (BYVAL hWnd AS DWORD, _           ' parent window
                         BYVAL sCaption AS STRING, _      ' caption
                         sFileSpec AS STRING, _           ' filename
                         BYVAL sInitialDir AS STRING, _   ' start directory
                         BYVAL sFilter AS STRING, _       ' filename filter
                         BYVAL sDefExtension AS STRING, _ ' default extension
                         dFlags AS DWORD _                ' flags
                        ) AS LONG

    LOCAL ix          AS LONG
    LOCAL fOk         AS LONG
    LOCAL ofn         AS OPENFILENAME_NT4A
    LOCAL szFileTitle AS ASCIIZ * %MAX_PATH

    ' Filter is a sequence of ASCIIZ strings with a final (extra) $NUL terminator
    REPLACE "|" WITH $NUL IN sFilter
    sFilter += $NUL

    IF LEN(sInitialDir) = 0 THEN
        sInitialDir = CURDIR$
    END IF

    sDefExtension = LTRIM$(sDefExtension, ".")

    ofn.lStructSize      = SIZEOF(ofn)
    ofn.hWndOwner        = hWnd
    ofn.nFilterIndex     = FindFilterIndex(sFilter, _
                               IIF$(LEN(sFileSpec), _
                                   sFileSpec, _
                                   "." + sDefExtension))
    ofn.lpstrFilter      = STRPTR(sFilter)
    sFileSpec            = LSET$(sFileSpec, %MAX_PATH USING $NUL)
    ofn.lpstrFile        = STRPTR(sFileSpec)
    ofn.nMaxFile         = LEN(sFileSpec)
    ofn.lpstrFileTitle   = VARPTR(szFileTitle)
    ofn.nMaxFileTitle    = SIZEOF(szFileTitle)
    ofn.lpstrInitialDir  = STRPTR(sInitialDir)
    IF LEN(sCaption) THEN
        ofn.lpstrTitle   = STRPTR(sCaption)
    END IF
    ofn.Flags            = dFlags
    IF LEN(sDefExtension) THEN
        ofn.lpstrDefExt  = STRPTR(sDefExtension)
    END IF

    fOk = GetSaveFilenameA(BYVAL VARPTR(ofn))
    IF fOk THEN
        ix = INSTR(sFileSpec, $NUL)
        sFileSpec = IIF$(ix, LEFT$(sFileSpec, ix - 1), "")
        dFlags = ofn.Flags
    ELSE
        sFileSpec = ""
        dFlags = 0
    END IF

    FUNCTION = fOk

END FUNCTION



#ENDIF ' IF NOT %DEF(%NOFILEDLG)
