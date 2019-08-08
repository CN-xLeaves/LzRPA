'------------------------------------------------------------------------------
'
'  RichEdit.inc -- RichEdit v2.0/3.0/4.0 public definitions
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from RichEdit.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%RICHEDIT = 1
%RICHEDIT_INC = 1

'
' Pull in Windows includes if necessary
'
#INCLUDE "SdkDdkVer.inc"
#INCLUDE "WinGDI.inc"


' To mimic older RichEdit behavior, set %RICHEDIT_VER to appropriate value
'    Version 1.0   &H0100
'    Version 2.0   &H0200
'    Version 2.1   &H0210
#IF NOT %DEF(%RICHEDIT_VER)
%RICHEDIT_VER = &H0300
#ENDIF

%cchTextLimitDefault = 32767

$$MSFTEDIT_CLASS = "RICHEDIT50W"$$
' NOTE:  MSFTEDIT.DLL only registers MSFTEDIT_CLASS.  If an application wants
' to use the following Richedit classes, it needs to load the riched20.dll.
' Otherwise, CreateWindow with RICHEDIT_CLASS would fail.
' This also applies to any dialog that uses RICHEDIT_CLASS,

' RichEdit 2.0 Window Class
' On Windows CE, avoid possible conflicts on Win95
$CERICHEDIT_CLASSA  = "RichEditCEA"
$$CERICHEDIT_CLASSW = "RichEditCEW"$$

$RICHEDIT_CLASSA = "RichEdit20A"
$RICHEDIT_CLASS10A = "RICHEDIT" ' Richedit 1.0

#IF NOT %DEF(%MACPORT)
$$RICHEDIT_CLASSW = "RichEdit20W"$$
#ELSE   '----------------------MACPORT
$RICHEDIT_CLASSW = "RichEdit20W"
$$RICHEDIT_CLASSW = "RichEdit20W"$$  ' MACPORT change
#ENDIF ' MACPORT

#IF (%RICHEDIT_VER >= &H0200 )
#IF %DEF(%UNICODE)
MACRO RICHEDIT_CLASS = $$RICHEDIT_CLASSW
#ELSE
MACRO RICHEDIT_CLASS = $RICHEDIT_CLASSA
#ENDIF ' %UNICODE
#ELSE
$RICHEDIT_CLASS = $RICHEDIT_CLASS10A
#ENDIF ' %RICHEDIT_VER >= &H0200

' RichEdit messages

#IF NOT %DEF(%WM_CONTEXTMENU)
%WM_CONTEXTMENU  = &H007B
#ENDIF

#IF NOT %DEF(%WM_UNICHAR)
%WM_UNICHAR      = &H0109
#ENDIF

#IF NOT %DEF(%WM_PRINTCLIENT)
%WM_PRINTCLIENT  = &H0318
#ENDIF

#IF NOT %DEF(%EM_GETLIMITTEXT)
%EM_GETLIMITTEXT = %WM_USER + 37
#ENDIF

#IF NOT %DEF(%EM_POSFROMCHAR)
%EM_POSFROMCHAR  = %WM_USER + 38
%EM_CHARFROMPOS  = %WM_USER + 39
#ENDIF

#IF NOT %DEF(%EM_SCROLLCARET)
%EM_SCROLLCARET  = %WM_USER + 49
#ENDIF

%EM_CANPASTE           = %WM_USER + 50
%EM_DISPLAYBAND        = %WM_USER + 51
%EM_EXGETSEL           = %WM_USER + 52
%EM_EXLIMITTEXT        = %WM_USER + 53
%EM_EXLINEFROMCHAR     = %WM_USER + 54
%EM_EXSETSEL           = %WM_USER + 55
%EM_FINDTEXT           = %WM_USER + 56
%EM_FORMATRANGE        = %WM_USER + 57
%EM_GETCHARFORMAT      = %WM_USER + 58
%EM_GETEVENTMASK       = %WM_USER + 59
%EM_GETOLEINTERFACE    = %WM_USER + 60
%EM_GETPARAFORMAT      = %WM_USER + 61
%EM_GETSELTEXT         = %WM_USER + 62
%EM_HIDESELECTION      = %WM_USER + 63
%EM_PASTESPECIAL       = %WM_USER + 64
%EM_REQUESTRESIZE      = %WM_USER + 65
%EM_SELECTIONTYPE      = %WM_USER + 66
%EM_SETBKGNDCOLOR      = %WM_USER + 67
%EM_SETCHARFORMAT      = %WM_USER + 68
%EM_SETEVENTMASK       = %WM_USER + 69
%EM_SETOLECALLBACK     = %WM_USER + 70
%EM_SETPARAFORMAT      = %WM_USER + 71
%EM_SETTARGETDEVICE    = %WM_USER + 72
%EM_STREAMIN           = %WM_USER + 73
%EM_STREAMOUT          = %WM_USER + 74
%EM_GETTEXTRANGE       = %WM_USER + 75
%EM_FINDWORDBREAK      = %WM_USER + 76
%EM_SETOPTIONS         = %WM_USER + 77
%EM_GETOPTIONS         = %WM_USER + 78
%EM_FINDTEXTEX         = %WM_USER + 79
#IF %DEF(%WIN32)
%EM_GETWORDBREAKPROCEX = %WM_USER + 80
%EM_SETWORDBREAKPROCEX = %WM_USER + 81
#ENDIF

' RichEdit 2.0 messages
%EM_SETUNDOLIMIT       = %WM_USER + 82
%EM_REDO               = %WM_USER + 84
%EM_CANREDO            = %WM_USER + 85
%EM_GETUNDONAME        = %WM_USER + 86
%EM_GETREDONAME        = %WM_USER + 87
%EM_STOPGROUPTYPING    = %WM_USER + 88

%EM_SETTEXTMODE        = %WM_USER + 89
%EM_GETTEXTMODE        = %WM_USER + 90

' enum for use with EM_GET/SETTEXTMODE
MACRO TEXTMODE_enum=LONG
ENUM TEXTMODE SINGULAR BITS
    TM_PLAINTEXT       = 1
    TM_RICHTEXT                ' default behavior
    TM_SINGLELEVELUNDO
    TM_MULTILEVELUNDO          ' default behavior
    TM_SINGLECODEPAGE
    TM_MULTICODEPAGE           ' default behavior
END ENUM

%EM_AUTOURLDETECT      = %WM_USER + 91
%EM_GETAUTOURLDETECT   = %WM_USER + 92
%EM_SETPALETTE         = %WM_USER + 93
%EM_GETTEXTEX          = %WM_USER + 94
%EM_GETTEXTLENGTHEX    = %WM_USER + 95
%EM_SHOWSCROLLBAR      = %WM_USER + 96
%EM_SETTEXTEX          = %WM_USER + 97

' Far East specific messages
%EM_SETPUNCTUATION     = %WM_USER + 100
%EM_GETPUNCTUATION     = %WM_USER + 101
%EM_SETWORDWRAPMODE    = %WM_USER + 102
%EM_GETWORDWRAPMODE    = %WM_USER + 103
%EM_SETIMECOLOR        = %WM_USER + 104
%EM_GETIMECOLOR        = %WM_USER + 105
%EM_SETIMEOPTIONS      = %WM_USER + 106
%EM_GETIMEOPTIONS      = %WM_USER + 107
%EM_CONVPOSITION       = %WM_USER + 108

%EM_SETLANGOPTIONS     = %WM_USER + 120
%EM_GETLANGOPTIONS     = %WM_USER + 121
%EM_GETIMECOMPMODE     = %WM_USER + 122

%EM_FINDTEXTW          = %WM_USER + 123
%EM_FINDTEXTEXW        = %WM_USER + 124

' RE3.0 FE messages
%EM_RECONVERSION       = %WM_USER + 125
%EM_SETIMEMODEBIAS     = %WM_USER + 126
%EM_GETIMEMODEBIAS     = %WM_USER + 127

' BiDi specific messages
%EM_SETBIDIOPTIONS     = %WM_USER + 200
%EM_GETBIDIOPTIONS     = %WM_USER + 201

%EM_SETTYPOGRAPHYOPTIONS = %WM_USER + 202
%EM_GETTYPOGRAPHYOPTIONS = %WM_USER + 203

' Extended edit style specific messages
%EM_SETEDITSTYLE       = %WM_USER + 204
%EM_GETEDITSTYLE       = %WM_USER + 205

' Extended edit style masks
%SES_EMULATESYSEDIT     = 1
%SES_BEEPONMAXTEXT      = 2
%SES_EXTENDBACKCOLOR    = 4
%SES_MAPCPS             = 8      ' (obsolete)
%SES_EMULATE10          = 16     ' (obsolete)
%SES_USECRLF            = 32     ' (obsolete)
%SES_NOXLTSYMBOLRANGE   = 32
%SES_USEAIMM            = 64
%SES_NOIME              = 128

%SES_ALLOWBEEPS         = 256
%SES_UPPERCASE          = 512
%SES_LOWERCASE          = 1024
%SES_NOINPUTSEQUENCECHK = 2048
%SES_BIDI               = 4096
%SES_SCROLLONKILLFOCUS  = 8192
%SES_XLTCRCRLFTOCR      = 16384
%SES_DRAFTMODE          = 32768

%SES_USECTF             = &H0010000
%SES_HIDEGRIDLINES      = &H0020000
%SES_USEATFONT          = &H0040000
%SES_CUSTOMLOOK         = &H0080000
%SES_LBSCROLLNOTIFY     = &H0100000
%SES_CTFALLOWEMBED      = &H0200000
%SES_CTFALLOWSMARTTAG   = &H0400000
%SES_CTFALLOWPROOFING   = &H0800000

' Options for EM_SETLANGOPTIONS and EM_GETLANGOPTIONS
%IMF_AUTOKEYBOARD        = &H0001
%IMF_AUTOFONT            = &H0002
%IMF_IMECANCELCOMPLETE   = &H0004  ' High completes comp string when aborting, low cancels.
%IMF_IMEALWAYSSENDNOTIFY = &H0008
%IMF_AUTOFONTSIZEADJUST  = &H0010
%IMF_UIFONTS             = &H0020
%IMF_DUALFONT            = &H0080
%IMF_NORTFFONTSUBSTITUTE = &H0400


' Values for EM_GETIMECOMPMODE
%ICM_NOTOPEN    = &H0000
%ICM_LEVEL3     = &H0001
%ICM_LEVEL2     = &H0002
%ICM_LEVEL2_5   = &H0003
%ICM_LEVEL2_SUI = &H0004
%ICM_CTF        = &H0005

' Options for EM_SETTYPOGRAPHYOPTIONS
%TO_ADVANCEDTYPOGRAPHY   = 1
%TO_SIMPLELINEBREAK      = 2
%TO_DISABLECUSTOMTEXTOUT = 4
%TO_ADVANCEDLAYOUT       = 8

' Pegasus outline mode messages (RE 3.0)

' Outline mode message
%EM_OUTLINE          = %WM_USER + 220
' Message for getting and restoring scroll pos
%EM_GETSCROLLPOS     = %WM_USER + 221
%EM_SETSCROLLPOS     = %WM_USER + 222
' Change fontsize in current selection by wParam
%EM_SETFONTSIZE      = %WM_USER + 223
%EM_GETZOOM          = %WM_USER + 224
%EM_SETZOOM          = %WM_USER + 225
%EM_GETVIEWKIND      = %WM_USER + 226
%EM_SETVIEWKIND      = %WM_USER + 227

' RichEdit 4.0 messages
%EM_GETPAGE          = %WM_USER + 228
%EM_SETPAGE          = %WM_USER + 229
%EM_GETHYPHENATEINFO = %WM_USER + 230
%EM_SETHYPHENATEINFO = %WM_USER + 231
%EM_GETPAGEROTATE    = %WM_USER + 235
%EM_SETPAGEROTATE    = %WM_USER + 236
%EM_GETCTFMODEBIAS   = %WM_USER + 237
%EM_SETCTFMODEBIAS   = %WM_USER + 238
%EM_GETCTFOPENSTATUS = %WM_USER + 240
%EM_SETCTFOPENSTATUS = %WM_USER + 241
%EM_GETIMECOMPTEXT   = %WM_USER + 242
%EM_ISIME            = %WM_USER + 243
%EM_GETIMEPROPERTY   = %WM_USER + 244

' These messages control what rich edit does when it comes across
' OLE objects during RTF stream in.  Normally rich edit queries the client
' application only after OleLoad has been called.  With these messages it is possible to
' set the rich edit control to a mode where it will query the client application before
' OleLoad is called
%EM_GETQUERYRTFOBJ   = %WM_USER + 269
%EM_SETQUERYRTFOBJ   = %WM_USER + 270

' EM_SETPAGEROTATE wparam values
%EPR_0                  = 0  ' Text flows left to right and top to bottom
%EPR_270                = 1  ' Text flows top to bottom and right to left
%EPR_180                = 2  ' Text flows right to left and bottom to top
%EPR_90                 = 3  ' Text flows bottom to top and left to right

' EM_SETCTFMODEBIAS wparam values
%CTFMODEBIAS_DEFAULT               = &H0000
%CTFMODEBIAS_FILENAME              = &H0001
%CTFMODEBIAS_NAME                  = &H0002
%CTFMODEBIAS_READING               = &H0003
%CTFMODEBIAS_DATETIME              = &H0004
%CTFMODEBIAS_CONVERSATION          = &H0005
%CTFMODEBIAS_NUMERIC               = &H0006
%CTFMODEBIAS_HIRAGANA              = &H0007
%CTFMODEBIAS_KATAKANA              = &H0008
%CTFMODEBIAS_HANGUL                = &H0009
%CTFMODEBIAS_HALFWIDTHKATAKANA     = &H000A
%CTFMODEBIAS_FULLWIDTHALPHANUMERIC = &H000B
%CTFMODEBIAS_HALFWIDTHALPHANUMERIC = &H000C

' EM_SETIMEMODEBIAS lparam values
%IMF_SMODE_PLAURALCLAUSE  = &H0001
%IMF_SMODE_NONE           = &H0002

' EM_GETIMECOMPTEXT wparam structure
TYPE IMECOMPTEXT
    cb    AS LONG    ' count of bytes in the output buffer.
    flags AS DWORD   ' value specifying the composition string type.
                     '  Currently only support ICT_RESULTREADSTR
END TYPE
%ICT_RESULTREADSTR = 1


' Outline mode wparam values
%EMO_EXIT            = 0       ' enter normal mode,  lparam ignored
%EMO_ENTER           = 1       ' enter outline mode, lparam ignored
%EMO_PROMOTE         = 2       ' LOWORD(lparam) = 0 ==>
                               ' promote  to body-text
                               ' LOWORD(lparam) <> 0 ==>
                               ' promote/demote current selection
                               ' by indicated number of levels
%EMO_EXPAND          = 3       ' HIWORD(lparam) = %EMO_EXPANDSELECTION
                               ' -> expands selection to level
                               ' indicated in LOWORD(lparam)
                               ' LOWORD(lparam) = -1/+1 corresponds
                               ' to collapse/expand button presses
                               ' in winword (other values are
                               ' equivalent to having pressed these
                               ' buttons more than once)
                               ' HIWORD(lparam) = %EMO_EXPANDDOCUMENT
                               ' -> expands whole document to
                               ' indicated level
%EMO_MOVESELECTION   = 4       ' LOWORD(lparam) <> 0 -> move current
                               ' selection up/down by indicated
                               ' amount
%EMO_GETVIEWMODE     = 5       ' Returns %VM_NORMAL or %VM_OUTLINE

' EMO_EXPAND options
%EMO_EXPANDSELECTION = 0
%EMO_EXPANDDOCUMENT  = 1

%VM_NORMAL           = 4       ' Agrees with RTF \viewkindN
%VM_OUTLINE          = 2
%VM_PAGE             = 9       ' Screen page view (not print layout)


' new notifications
%EN_MSGFILTER         = &H0700
%EN_REQUESTRESIZE     = &H0701
%EN_SELCHANGE         = &H0702
%EN_DROPFILES         = &H0703
%EN_PROTECTED         = &H0704
%EN_CORRECTTEXT       = &H0705     ' PenWin specific
%EN_STOPNOUNDO        = &H0706
%EN_IMECHANGE         = &H0707     ' Far East specific
%EN_SAVECLIPBOARD     = &H0708
%EN_OLEOPFAILED       = &H0709
%EN_OBJECTPOSITIONS   = &H070a
%EN_LINK              = &H070b
%EN_DRAGDROPDONE      = &H070c
%EN_PARAGRAPHEXPANDED = &H070d
%EN_PAGECHANGE        = &H070e
%EN_LOWFIRTF          = &H070f
%EN_ALIGNLTR          = &H0710     ' BiDi specific notifications
%EN_ALIGNRTL          = &H0711     ' BiDi specific notifications

' event notification masks
%ENM_NONE              = &H00000000
%ENM_CHANGE            = &H00000001
%ENM_UPDATE            = &H00000002
%ENM_SCROLL            = &H00000004
%ENM_SCROLLEVENTS      = &H00000008
%ENM_DRAGDROPDONE      = &H00000010
%ENM_PARAGRAPHEXPANDED = &H00000020
%ENM_PAGECHANGE        = &H00000040
%ENM_KEYEVENTS         = &H00010000
%ENM_MOUSEEVENTS       = &H00020000
%ENM_REQUESTRESIZE     = &H00040000
%ENM_SELCHANGE         = &H00080000
%ENM_DROPFILES         = &H00100000
%ENM_PROTECTED         = &H00200000
%ENM_CORRECTTEXT       = &H00400000    ' PenWin specific
%ENM_IMECHANGE         = &H00800000    ' Used by RE1.0 compatibility
%ENM_LANGCHANGE        = &H01000000
%ENM_OBJECTPOSITIONS   = &H02000000
%ENM_LINK              = &H04000000
%ENM_LOWFIRTF          = &H08000000

' new edit control styles
%ES_SAVESEL         = &H00008000
%ES_SUNKEN          = &H00004000
%ES_DISABLENOSCROLL = &H00002000
' same as WS_MAXIMIZE, but that doesn't make sense so we re-use the value
%ES_SELECTIONBAR    = &H01000000
' same as ES_UPPERCASE, but re-used to completely disable OLE drag'n'drop
%ES_NOOLEDRAGDROP   = &H00000008

' Edit control extended style
#IF (%WIN32_WINNT > &H0400) OR (%WINVER > &H0400)
%ES_EX_NOCALLOLEINIT   = &H00000000    ' Not supported in RE 2.0/3.0
#ELSE
#IF %DEF(%WIN32)
%ES_EX_NOCALLOLEINIT   = &H01000000
#ENDIF
#ENDIF

' These flag are used in FE Windows
%ES_VERTICAL           = &H00400000
%ES_NOIME              = &H00080000    ' Not supported in RE 2.0/3.0
%ES_SELFIME            = &H00040000

' Edit control options
%ECO_AUTOWORDSELECTION = &H00000001
%ECO_AUTOVSCROLL       = &H00000040
%ECO_AUTOHSCROLL       = &H00000080
%ECO_NOHIDESEL         = &H00000100
%ECO_READONLY          = &H00000800
%ECO_WANTRETURN        = &H00001000
%ECO_SAVESEL           = &H00008000
%ECO_SELECTIONBAR      = &H01000000
%ECO_VERTICAL          = &H00400000    ' FE specific

' ECO operations
%ECOOP_SET = &H0001
%ECOOP_OR  = &H0002
%ECOOP_AND = &H0003
%ECOOP_XOR = &H0004

' new word break function actions
%WB_CLASSIFY      = 3
%WB_MOVEWORDLEFT  = 4
%WB_MOVEWORDRIGHT = 5
%WB_LEFTBREAK     = 6
%WB_RIGHTBREAK    = 7

' Far East specific flags
%WB_MOVEWORDPREV  = 4
%WB_MOVEWORDNEXT  = 5
%WB_PREVBREAK     = 6
%WB_NEXTBREAK     = 7

%PC_FOLLOWING  = 1
%PC_LEADING    = 2
%PC_OVERFLOW   = 3
%PC_DELIMITER  = 4
%WBF_WORDWRAP  = &H010
%WBF_WORDBREAK = &H020
%WBF_OVERFLOW  = &H040
%WBF_LEVEL1    = &H080
%WBF_LEVEL2    = &H100
%WBF_CUSTOM    = &H200

' Far East specific flags
%IMF_FORCENONE         = &H0001
%IMF_FORCEENABLE       = &H0002
%IMF_FORCEDISABLE      = &H0004
%IMF_CLOSESTATUSWINDOW = &H0008
%IMF_VERTICAL          = &H0020
%IMF_FORCEACTIVE       = &H0040
%IMF_FORCEINACTIVE     = &H0080
%IMF_FORCEREMEMBER     = &H0100
%IMF_MULTIPLEEDIT      = &H0400

' Word break flags (used with %WB_CLASSIFY)
%WBF_CLASS      = &H0F
%WBF_ISWHITE    = &H10
%WBF_BREAKLINE  = &H20
%WBF_BREAKAFTER = &H40

' Data types

#IF %DEF(%WIN32)
DECLARE FUNCTION EDITWORDBREAKPROCEX (pchText AS ASCIIZ, _
    BYVAL cchText AS LONG, BYVAL bCharSet AS BYTE, BYVAL action AS LONG) _
    AS LONG
#ENDIF

' All character format measurements are in twips
TYPE CHARFORMATA BYTE
    cbSize          AS DWORD
    dwMask          AS DWORD
    dwEffects       AS DWORD
    yHeight         AS LONG
    yOffset         AS LONG
    crTextColor     AS COLORREF
    bCharSet        AS BYTE
    bPitchAndFamily AS BYTE
    szFaceName      AS ASCIIZ * %LF_FACESIZE
    wFiller         AS WORD
END TYPE

TYPE CHARFORMATW BYTE
    cbSize          AS DWORD
    dwMask          AS DWORD
    dwEffects       AS DWORD
    yHeight         AS LONG
    yOffset         AS LONG
    crTextColor     AS COLORREF
    bCharSet        AS BYTE
    bPitchAndFamily AS BYTE
    szFaceName      AS ASCIIZ * %LF_FACESIZE
    wFiller         AS WORD
END TYPE

#IF (%RICHEDIT_VER >= &H0200)
#IF %DEF(%UNICODE)
TYPE CHARFORMAT
    CHARFORMATW
END TYPE
#ELSE
TYPE CHARFORMAT
    CHARFORMATA
END TYPE
#ENDIF ' %UNICODE
#ELSE
TYPE CHARFORMAT
    CHARFORMATA
END TYPE
#ENDIF ' %RICHEDIT_VER >= &H0200

' CHARFORMAT2 structure

TYPE CHARFORMAT2W
    cbSize          AS DWORD
    dwMask          AS DWORD
    dwEffects       AS DWORD
    yHeight         AS LONG
    yOffset         AS LONG      ' > 0 for superscript, < 0 for subscript
    crTextColor     AS COLORREF
    bCharSet        AS BYTE
    bPitchAndFamily AS BYTE
    szFaceName      AS WSTRINGZ * %LF_FACESIZE
    wWeight         AS WORD      ' Font weight (LOGFONT value)
    sSpacing        AS INTEGER   ' Amount to space between letters
    crBackColor     AS COLORREF  ' Background color
    lcid            AS DWORD     ' LCID ' Locale ID
    dwReserved      AS DWORD     ' Reserved. Must be 0
    sStyle          AS INTEGER   ' Style handle
    wKerning        AS WORD      ' Twip size above which to kern char pair
    bUnderlineType  AS BYTE      ' Underline type
    bAnimation      AS BYTE      ' Animated text like marching ants
    bRevAuthor      AS BYTE      ' Revision author index
    bReserved1      AS BYTE
END TYPE

TYPE CHARFORMAT2A
    cbSize          AS DWORD
    dwMask          AS DWORD
    dwEffects       AS DWORD
    yHeight         AS LONG
    yOffset         AS LONG      ' > 0 for superscript, < 0 for subscript
    crTextColor     AS COLORREF
    bCharSet        AS BYTE
    bPitchAndFamily AS BYTE
    szFaceName      AS ASCIIZ * %LF_FACESIZE
    wWeight         AS WORD      ' Font weight (LOGFONT value)
    sSpacing        AS INTEGER   ' Amount to space between letters
    crBackColor     AS COLORREF  ' Background color
    lcid            AS DWORD     ' LCID ' Locale ID
    dwReserved      AS DWORD     ' Reserved. Must be 0
    sStyle          AS INTEGER   ' Style handle
    wKerning        AS WORD      ' Twip size above which to kern char pair
    bUnderlineType  AS BYTE      ' Underline type
    bAnimation      AS BYTE      ' Animated text like marching ants
    bRevAuthor      AS BYTE      ' Revision author index
    bReserved1      AS BYTE
END TYPE

#IF %DEF(%UNICODE)
TYPE CHARFORMAT2
    CHARFORMAT2W
END TYPE
#ELSE
TYPE CHARFORMAT2
    CHARFORMAT2A
END TYPE
#ENDIF

MACRO CHARFORMATDELTA = (SIZEOF(CHARFORMAT2) - SIZEOF(CHARFORMAT))


' CFM_COLOR mirrors CFE_AUTOCOLOR, a little hack to easily deal with autocolor

' CHARFORMAT masks
%CFM_BOLD      = &H00000001
%CFM_ITALIC    = &H00000002
%CFM_UNDERLINE = &H00000004
%CFM_STRIKEOUT = &H00000008
%CFM_PROTECTED = &H00000010
%CFM_LINK      = &H00000020    ' Exchange hyperlink extension
%CFM_SIZE      = &H80000000???
%CFM_COLOR     = &H40000000
%CFM_FACE      = &H20000000
%CFM_OFFSET    = &H10000000
%CFM_CHARSET   = &H08000000

' CHARFORMAT effects
%CFE_BOLD      = &H0001
%CFE_ITALIC    = &H0002
%CFE_UNDERLINE = &H0004
%CFE_STRIKEOUT = &H0008
%CFE_PROTECTED = &H0010
%CFE_LINK      = &H0020

%CFE_AUTOCOLOR = &H40000000 ' NOTE: this corresponds to CFM_COLOR, which controls it

' Masks and effects defined for CHARFORMAT2 -- an (*) indicates
' the data is stored by RichEdit 2.0/3.0, but not displayed

%CFM_SMALLCAPS     = &H0040        ' (*)
%CFM_ALLCAPS       = &H0080        ' Displayed by 3.0
%CFM_HIDDEN        = &H0100        ' Hidden by 3.0
%CFM_OUTLINE       = &H0200        ' (*)
%CFM_SHADOW        = &H0400        ' (*)
%CFM_EMBOSS        = &H0800        ' (*)
%CFM_IMPRINT       = &H1000        ' (*)
%CFM_DISABLED      = &H2000
%CFM_REVISED       = &H4000

%CFM_BACKCOLOR     = &H04000000
%CFM_LCID          = &H02000000
%CFM_UNDERLINETYPE = &H00800000    ' Many displayed by 3.0
%CFM_WEIGHT        = &H00400000
%CFM_SPACING       = &H00200000    ' Displayed by 3.0
%CFM_KERNING       = &H00100000    ' (*)
%CFM_STYLE         = &H00080000    ' (*)
%CFM_ANIMATION     = &H00040000    ' (*)
%CFM_REVAUTHOR     = &H00008000

%CFE_SUBSCRIPT     = &H00010000    ' Superscript and subscript are
%CFE_SUPERSCRIPT   = &H00020000    '  mutually exclusive

%CFM_SUBSCRIPT     = %CFE_SUBSCRIPT OR %CFE_SUPERSCRIPT
%CFM_SUPERSCRIPT   = %CFM_SUBSCRIPT

' CHARFORMAT "ALL" masks
%CFM_EFFECTS = (%CFM_BOLD OR %CFM_ITALIC OR %CFM_UNDERLINE OR %CFM_COLOR OR _
                %CFM_STRIKEOUT OR %CFE_PROTECTED OR %CFM_LINK)

%CFM_ALL = (%CFM_EFFECTS OR %CFM_SIZE OR %CFM_FACE OR %CFM_OFFSET OR _
           %CFM_CHARSET)

%CFM_EFFECTS2 = (%CFM_EFFECTS OR %CFM_DISABLED OR %CFM_SMALLCAPS OR _
                %CFM_ALLCAPS OR %CFM_HIDDEN  OR %CFM_OUTLINE OR %CFM_SHADOW _
                OR %CFM_EMBOSS OR %CFM_IMPRINT OR %CFM_DISABLED _
                OR %CFM_REVISED OR %CFM_SUBSCRIPT OR %CFM_SUPERSCRIPT _
                OR %CFM_BACKCOLOR)

%CFM_ALL2 = (%CFM_ALL OR %CFM_EFFECTS2 OR %CFM_BACKCOLOR OR %CFM_LCID _
             OR %CFM_UNDERLINETYPE OR %CFM_WEIGHT OR %CFM_REVAUTHOR _
             OR %CFM_SPACING OR %CFM_KERNING OR %CFM_STYLE OR %CFM_ANIMATION)

%CFE_SMALLCAPS     = %CFM_SMALLCAPS
%CFE_ALLCAPS       = %CFM_ALLCAPS
%CFE_HIDDEN        = %CFM_HIDDEN
%CFE_OUTLINE       = %CFM_OUTLINE
%CFE_SHADOW        = %CFM_SHADOW
%CFE_EMBOSS        = %CFM_EMBOSS
%CFE_IMPRINT       = %CFM_IMPRINT
%CFE_DISABLED      = %CFM_DISABLED
%CFE_REVISED       = %CFM_REVISED

' NOTE: %CFE_AUTOCOLOR and %CFE_AUTOBACKCOLOR correspond to %CFM_COLOR and
' %CFM_BACKCOLOR, respectively, which control them

%CFE_AUTOBACKCOLOR = %CFM_BACKCOLOR

' Underline types. RE 1.0 displays only CFU_UNDERLINE
%CFU_CF1UNDERLINE             = &HFF  ' map charformat's bit underline to CF2.
%CFU_INVERT                   = &HFE  ' For IME composition fake a selection.
%CFU_UNDERLINETHICKLONGDASH   = 18    ' (*) display as dash
%CFU_UNDERLINETHICKDOTTED     = 17    ' (*) display as dot
%CFU_UNDERLINETHICKDASHDOTDOT = 16    ' (*) display as dash dot dot
%CFU_UNDERLINETHICKDASHDOT    = 15    ' (*) display as dash dot
%CFU_UNDERLINETHICKDASH       = 14    ' (*) display as dash
%CFU_UNDERLINELONGDASH        = 13    ' (*) display as dash
%CFU_UNDERLINEHEAVYWAVE       = 12    ' (*) display as wave
%CFU_UNDERLINEDOUBLEWAVE      = 11    ' (*) display as wave
%CFU_UNDERLINEHAIRLINE        = 10    ' (*) display as single
%CFU_UNDERLINETHICK           = 9
%CFU_UNDERLINEWAVE            = 8
%CFU_UNDERLINEDASHDOTDOT      = 7
%CFU_UNDERLINEDASHDOT         = 6
%CFU_UNDERLINEDASH            = 5
%CFU_UNDERLINEDOTTED          = 4
%CFU_UNDERLINEDOUBLE          = 3     ' (*) display as single
%CFU_UNDERLINEWORD            = 2     ' (*) display as single
%CFU_UNDERLINE                = 1
%CFU_UNDERLINENONE            = 0

%yHeightCharPtsMost = 1638

' %EM_SETCHARFORMAT wParam masks
%SCF_SELECTION      = &H0001
%SCF_WORD           = &H0002
%SCF_DEFAULT        = &H0000    ' Set default charformat or paraformat
%SCF_ALL            = &H0004    ' Not valid with SCF_SELECTION or SCF_WORD
%SCF_USEUIRULES     = &H0008    ' Modifier for SCF_SELECTION; says that
                                '  format came from a toolbar, etc., and
                                '  hence UI formatting rules should be
                                '  used instead of literal formatting
%SCF_ASSOCIATEFONT  = &H0010    ' Associate fontname with bCharSet (one
                                '  possible for each of Western, ME, FE, Thai)
%SCF_NOKBUPDATE     = &H0020    ' Do not update the KB layput for this change
                                ' even if autokeyboard is on.
%SCF_ASSOCIATEFONT2 = &H0040    ' Associate plane-2 (surrogate) font

TYPE CHARRANGE
    cpMin AS LONG
    cpMax AS LONG
END TYPE

TYPE TEXTRANGEA
    chrg      AS CHARRANGE
    lpstrText AS ASCIIZ PTR    ' allocated by caller, zero terminated by RichEdit
END TYPE

TYPE TEXTRANGEW
    chrg      AS CHARRANGE
    lpstrText AS WSTRINGZ PTR  ' allocated by caller, zero terminated by RichEdit
END TYPE

#IF (%RICHEDIT_VER >= &H0200)
#IF %DEF(%UNICODE)
TYPE TEXTRANGE
    TEXTRANGEW
END TYPE
#ELSE
TYPE TEXTRANGE
    TEXTRANGEA
END TYPE
#ENDIF ' %UNICODE
#ELSE
TYPE TEXTRANGE
    TEXTRANGEA
END TYPE
#ENDIF ' %RICHEDIT_VER >= &H0200

DECLARE FUNCTION EDITSTREAMCALLBACK (BYVAL dwCookie AS DWORD, _
    BYVAL pbBuff AS BYTE PTR, BYVAL cb AS LONG, pcb AS LONG) AS DWORD


TYPE EDITSTREAM DWORD
    dwCookie    AS DWORD    ' user value passed to callback as first parameter
    dwError     AS DWORD    ' last error
    pfnCallback AS DWORD
END TYPE

' Stream formats. Flags are all in low word, since high word gives
' possible codepage choice.

%SF_TEXT         = &H0001
%SF_RTF          = &H0002
%SF_RTFNOOBJS    = &H0003    ' Write only
%SF_TEXTIZED     = &H0004    ' Write only

%SF_UNICODE      = &H0010    ' Unicode file (UCS2 little endian)
%SF_USECODEPAGE  = &H0020    ' CodePage given by high word
%SF_NCRFORNONASCII = &H40    ' Output /uN for nonASCII
%SFF_WRITEEXTRAPAR = &H80?   ' Output \par at end

' Flag telling stream operations to operate on the selection only
' EM_STREAMIN will replace the current selection
' EM_STREAMOUT will stream out the current selection
%SFF_SELECTION = &H08000

' Flag telling stream operations to ignore some FE control words
' having to do with FE word breaking and horiz vs vertical text.
' Not used in RichEdit 2.0 and later
%SFF_PLAINRTF  = &H4000

' Flag telling file stream output (%SFF_SELECTION flag not set) to persist
' \viewscaleN control word.
%SFF_PERSISTVIEWSCALE = &H2000

' Flag telling file stream input with %SFF_SELECTION flag not set not to
' close the document
%SFF_KEEPDOCINFO = &H1000

' Flag telling stream operations to output in Pocket Word format
%SFF_PWD         = &H0800

' 3-bit field specifying the value of N - 1 to use for \rtfN or \pwdN
%SF_RTFVAL       = &H0700

TYPE FINDTEXTA_type
    chrg      AS CHARRANGE
    lpstrText AS ASCIIZ PTR
END TYPE

' [legacy]
TYPE FINDTEXTAPI
    FINDTEXTA_type
END TYPE

TYPE FINDTEXTW_type
    chrg      AS CHARRANGE
    lpstrText AS WSTRINGZ PTR
END TYPE

#IF (%RICHEDIT_VER >= &H0200)
#IF %DEF(%UNICODE)
TYPE FINDTEXT_type
    FINDTEXTW_type
END TYPE
#ELSE
TYPE FINDTEXT_type
    FINDTEXTA_type
END TYPE
#ENDIF ' %UNICODE
#ELSE
TYPE FINDTEXT_type
    FINDTEXTA_type
END TYPE
#ENDIF ' %RICHEDIT_VER >= &H0200

TYPE FINDTEXTEXA
    chrg      AS CHARRANGE
    lpstrText AS ASCIIZ PTR
    chrgText  AS CHARRANGE
END TYPE

TYPE FINDTEXTEXW
    chrg      AS CHARRANGE
    lpstrText AS WSTRINGZ PTR
    chrgText  AS CHARRANGE
END TYPE

#IF (%RICHEDIT_VER >= &H0200)
#IF %DEF(%UNICODE)
TYPE FINDTEXTEX
    FINDTEXTEXW
END TYPE
#ELSE
TYPE FINDTEXTEX
    FINDTEXTEXA
END TYPE
#ENDIF ' %UNICODE
#ELSE
TYPE FINDTEXTEX
    FINDTEXTEXA
END TYPE
#ENDIF ' %RICHEDIT_VER >= &H0200

TYPE FORMATRANGE
    hdc       AS DWORD
    hdcTarget AS DWORD
    rc        AS RECT
    rcPage    AS RECT
    chrg      AS CHARRANGE
END TYPE

' All paragraph measurements are in twips

%MAX_TAB_STOPS   = 32
%lDefaultTab     = 720
%MAX_TABLE_CELLS = 63

TYPE PARAFORMAT BYTE
    cbSize        AS DWORD
    dwMask        AS DWORD
    wNumbering    AS WORD
    wEffects      AS WORD
    dxStartIndent AS LONG
    dxRightIndent AS LONG
    dxOffset      AS LONG
    wAlignment    AS WORD
    cTabCount     AS INTEGER
    rgxTabs(%MAX_TAB_STOPS - 1) AS LONG
END TYPE

TYPE PARAFORMAT2 BYTE
    cbSize           AS DWORD
    dwMask           AS DWORD
    wNumbering       AS WORD
    wReserved        AS WORD
    dxStartIndent    AS LONG
    dxRightIndent    AS LONG
    dxOffset         AS LONG
    wAlignment       AS WORD
    cTabCount        AS INTEGER
    rgxTabs(%MAX_TAB_STOPS - 1) AS LONG
    dySpaceBefore    AS LONG       ' Vertical spacing before para
    dySpaceAfter     AS LONG       ' Vertical spacing after para
    dyLineSpacing    AS LONG       ' Line spacing depending on Rule
    sStyle           AS INTEGER    ' Style handle
    bLineSpacingRule AS BYTE       ' Rule for line spacing (see tom.doc)
    bOutlineLevel    AS BYTE       ' Outline Level
    wShadingWeight   AS WORD       ' Shading in hundredths of a per cent
    wShadingStyle    AS WORD       ' Byte 0: style, nib 2: cfpat, 3: cbpat
    wNumberingStart  AS WORD       ' Starting value for numbering
    wNumberingStyle  AS WORD       ' Alignment, Roman/Arabic, (), ), ., etc.
    wNumberingTab    AS WORD       ' Space bet 1st indent and 1st-line text
    wBorderSpace     AS WORD       ' Border-text spaces (nbl/bdr in pts)
    wBorderWidth     AS WORD       ' Pen widths (nbl/bdr in half twips)
    wBorders         AS WORD       ' Border styles (nibble/border)
END TYPE


' PARAFORMAT mask values
%PFM_STARTINDENT       = &H00000001
%PFM_RIGHTINDENT       = &H00000002
%PFM_OFFSET            = &H00000004
%PFM_ALIGNMENT         = &H00000008
%PFM_TABSTOPS          = &H00000010
%PFM_NUMBERING         = &H00000020
%PFM_OFFSETINDENT      = &H80000000???

' PARAFORMAT 2.0 masks and effects
%PFM_SPACEBEFORE       = &H00000040
%PFM_SPACEAFTER        = &H00000080
%PFM_LINESPACING       = &H00000100
%PFM_STYLE             = &H00000400
%PFM_BORDER            = &H00000800  ' (*)
%PFM_SHADING           = &H00001000  ' (*)
%PFM_NUMBERINGSTYLE    = &H00002000  ' RE 3.0
%PFM_NUMBERINGTAB      = &H00004000  ' RE 3.0
%PFM_NUMBERINGSTART    = &H00008000  ' RE 3.0

%PFM_RTLPARA           = &H00010000
%PFM_KEEP              = &H00020000  ' (*)
%PFM_KEEPNEXT          = &H00040000  ' (*)
%PFM_PAGEBREAKBEFORE   = &H00080000  ' (*)
%PFM_NOLINENUMBER      = &H00100000  ' (*)
%PFM_NOWIDOWCONTROL    = &H00200000  ' (*)
%PFM_DONOTHYPHEN       = &H00400000  ' (*)
%PFM_SIDEBYSIDE        = &H00800000  ' (*)
%PFM_TABLE             = &H40000000  ' RE 3.0
%PFM_TEXTWRAPPINGBREAK = &H20000000  ' RE 3.0
%PFM_TABLEROWDELIMITER = &H10000000  ' RE 4.0

' The following three properties are read only
%PFM_COLLAPSED         = &H01000000  ' RE 3.0
%PFM_OUTLINELEVEL      = &H02000000  ' RE 3.0
%PFM_BOX               = &H04000000  ' RE 3.0
%PFM_RESERVED2         = &H08000000  ' RE 4.0


' Note: PARAFORMAT has no effects
%PFM_EFFECTS = %PFM_RTLPARA OR %PFM_KEEP OR %PFM_KEEPNEXT OR %PFM_TABLE _
               OR %PFM_PAGEBREAKBEFORE OR %PFM_NOLINENUMBER  _
               OR %PFM_NOWIDOWCONTROL OR %PFM_DONOTHYPHEN OR %PFM_SIDEBYSIDE _
               OR %PFM_TABLE

' CHARFORMAT and PARAFORMAT "ALL" masks
' %CFM_COLOR mirrors %CFE_AUTOCOLOR, a little hack to easily deal with autocolor

%PFM_ALL = %PFM_STARTINDENT OR %PFM_RIGHTINDENT OR %PFM_OFFSET OR _
           %PFM_ALIGNMENT OR %PFM_TABSTOPS OR %PFM_NUMBERING OR _
           %PFM_OFFSETINDENT OR %PFM_RTLPARA

%PFM_ALL2 = %PFM_ALL OR %PFM_EFFECTS OR %PFM_SPACEBEFORE OR %PFM_SPACEAFTER _
            OR %PFM_LINESPACING OR %PFM_STYLE OR %PFM_SHADING OR %PFM_BORDER _
            OR %PFM_NUMBERINGTAB OR %PFM_NUMBERINGSTART OR %PFM_NUMBERINGSTYLE

%PFE_RTLPARA           = %PFM_RTLPARA           / 65536
%PFE_KEEP              = %PFM_KEEP              / 65536  ' (*)
%PFE_KEEPNEXT          = %PFM_KEEPNEXT          / 65536  ' (*)
%PFE_PAGEBREAKBEFORE   = %PFM_PAGEBREAKBEFORE   / 65536  ' (*)
%PFE_NOLINENUMBER      = %PFM_NOLINENUMBER      / 65536  ' (*)
%PFE_NOWIDOWCONTROL    = %PFM_NOWIDOWCONTROL    / 65536  ' (*)
%PFE_DONOTHYPHEN       = %PFM_DONOTHYPHEN       / 65536  ' (*)
%PFE_SIDEBYSIDE        = %PFM_SIDEBYSIDE        / 65536  ' (*)
%PFE_TEXTWRAPPINGBREAK = %PFM_TEXTWRAPPINGBREAK / 65536  ' (*)

' The following four effects are read only
%PFE_COLLAPSED         = %PFM_COLLAPSED    / 65536  ' (+)
%PFE_BOX               = %PFM_BOX          / 65536  ' (+)
%PFE_TABLE             = %PFM_TABLE        / 65536  ' Inside table row. RE 3.0
%PFE_TABLEROWDELIMITER = %PFM_TABLEROWDELIMITER / 65536 ' Table row start. RE 4.0

' PARAFORMAT numbering options
%PFN_BULLET   = 1    ' tomListBullet

' PARAFORMAT2 wNumbering options (see also PFN_BULLET)
%PFN_ARABIC   = 2    ' tomListNumberAsArabic:   0, 1, 2,    ...
%PFN_LCLETTER = 3    ' tomListNumberAsLCLetter: a, b, c,    ...
%PFN_UCLETTER = 4    ' tomListNumberAsUCLetter: A, B, C,    ...
%PFN_LCROMAN  = 5    ' tomListNumberAsLCRoman:  i, ii, iii, ...
%PFN_UCROMAN  = 6    ' tomListNumberAsUCRoman:  I, II, III, ...

' PARAFORMAT2 wNumberingStyle options
%PFNS_PAREN     = &H000    ' default, e.g.,                 1)
%PFNS_PARENS    = &H100    ' tomListParentheses/256, e.g., (1)
%PFNS_PERIOD    = &H200    ' tomListPeriod/256, e.g.,       1.
%PFNS_PLAIN     = &H300    ' tomListPlain/256, e.g.,        1
%PFNS_NONUMBER  = &H400    ' Used for continuation w/o number
%PFNS_NEWNUMBER = &H8000?? ' Start new number with wNumberingStart
                           ' (can be combined with other PFNS_xxx)

' PARAFORMAT alignment options
%PFA_LEFT             = 1
%PFA_RIGHT            = 2
%PFA_CENTER           = 3

' PARAFORMAT2 alignment options
%PFA_JUSTIFY          = 4  ' New paragraph-alignment option 2.0 (*)
%PFA_FULL_INTERWORD   = 4  ' These are supported in 3.0 with advanced
%PFA_FULL_INTERLETTER = 5  '   typography enabled
%PFA_FULL_SCALED      = 6
%PFA_FULL_GLYPHS      = 7
%PFA_SNAP_GRID        = 8


' Notification structures
#IF NOT %DEF(%WM_NOTIFY)
%WM_NOTIFY = &H004E

TYPE NMHDR
    hwndFrom AS DWORD
    idFrom   AS DWORD
    CODE     AS DWORD
END TYPE
#ENDIF  ' #IF NOT %DEF(%WM_NOTIFY)

' notification structures
TYPE MSGFILTER
    hdr    AS NMHDR
    msg    AS DWORD
    wParam AS LONG
    lParam AS LONG
END TYPE

TYPE REQRESIZE DWORD
    hdr AS NMHDR
    rc  AS RECT
END TYPE

TYPE SELCHANGE
    hdr    AS NMHDR
    chrg   AS CHARRANGE
    seltyp AS WORD
END TYPE

%SEL_EMPTY       = &H0000
%SEL_TEXT        = &H0001
%SEL_OBJECT      = &H0002
%SEL_MULTICHAR   = &H0004
%SEL_MULTIOBJECT = &H0008

' Used with IRichEditOleCallback::GetContextMenu, this flag will be
' passed as a "selection type".  It indicates that a context menu for
' a right-mouse drag drop should be generated.  The IOleObject parameter
' will really be the IDataObject for the drop
'
%GCM_RIGHTMOUSEDROP = &H8000??

TYPE ENDROPFILES DWORD
    hdr        AS NMHDR
    hDrop      AS DWORD   ' HANDLE
    cp         AS LONG
    fProtected AS LONG    ' BOOL
END TYPE

TYPE ENPROTECTED DWORD
    hdr    AS NMHDR
    msg    AS DWORD
    wParam AS LONG        ' WPARAM
    lParam AS LONG        ' LPARAM
    chrg   AS CHARRANGE
END TYPE

TYPE ENSAVECLIPBOARD
    hdr          AS NMHDR
    cObjectCount AS LONG
    cch          AS LONG
END TYPE

#IF NOT %DEF(%MACPORT)
TYPE ENOLEOPFAILED
    hdr   AS NMHDR
    iob   AS LONG
    lOper AS LONG
    hr    AS DWORD
END TYPE
#ENDIF

%OLEOP_DOVERB  = 1

TYPE OBJECTPOSITIONS
    NMHDR        AS NMHDR
    cObjectCount AS LONG
    pcpPositions AS LONG PTR
END TYPE

TYPE ENLINK
    NMHDR  AS NMHDR
    msg    AS DWORD
    wParam AS LONG      ' WPARAM
    lParam AS LONG      ' LPARAM
    chrg   AS CHARRANGE
END TYPE

TYPE ENLOWFIRTF
    NMHDR     AS NMHDR
    szControl AS ASCIIZ PTR
END TYPE

' PenWin specific
TYPE ENCORRECTTEXT
    hdr    AS NMHDR
    chrg   AS CHARRANGE
    seltyp AS WORD
END TYPE

' Far East specific
TYPE PUNCTUATION
    iSize         AS DWORD
    szPunctuation AS ASCIIZ PTR
END TYPE

' Far East specific
TYPE COMPCOLOR
    crText       AS COLORREF
    crBackground AS COLORREF
    dwEffects    AS DWORD
END TYPE


' Clipboard formats - use as parameter to RegisterClipboardFormat()
$CF_RTF       = "Rich Text Format"
$CF_RTFNOOBJS = "Rich Text Format Without Objects"
$CF_RETEXTOBJ = "RichEdit Text and Objects"
$$CF_RTF       = "Rich Text Format"$$
$$CF_RTFNOOBJS = "Rich Text Format Without Objects"$$
$$CF_RETEXTOBJ = "RichEdit Text and Objects"$$

' Paste Special
TYPE REPASTESPECIAL
    dwAspect AS DWORD
    dwParam  AS DWORD
END TYPE

' UndoName info
MACRO UNDONAMEID_enum=LONG
ENUM UNDONAMEID SINGULAR
    UID_UNKNOWN
    UID_TYPING
    UID_DELETE
    UID_DRAGDROP
    UID_CUT
    UID_PASTE
    UID_AUTOCORRECT
END ENUM

' Flags for the SETEXTEX data structure
%ST_DEFAULT   = 0
%ST_KEEPUNDO  = 1
%ST_SELECTION = 2
%ST_NEWCHARS  = 4

' EM_SETTEXTEX info; this struct is passed in the wparam of the message
TYPE SETTEXTEX
    flags   AS DWORD    ' flags (see the ST_XXX defines
    codepage AS DWORD   ' code page for translation (CP_ACP for sys default;
                        ' 1200 for Unicode, -1 for control default
END TYPE

' Flags for the GETEXTEX data structure
%GT_DEFAULT     = 0
%GT_USECRLF     = 1
%GT_SELECTION   = 2
%GT_RAWTEXT     = 4
%G_NOHIDDENTEXT = 8

' EM_GETTEXTEX info; this struct is passed in the wparam of the message
TYPE GETTEXTEX
    cb            AS DWORD       ' count of bytes in the string
    flags         AS DWORD       ' flags (see the GT_XXX defines
    codepage      AS DWORD       ' code page for translation (CP_ACP for sys default,
                                 ' 1200 for Unicode, -1 for control default
    lpDefaultChar AS ASCIIZ PTR  ' replacement for unmappable chars
    lpUsedDefChar AS LONG PTR    ' pointer to flag set when def char used
END TYPE

' Flags for the GETTEXTLENGTHEX data structure
%GTL_DEFAULT  = 0    ' do the default (return # of chars)
%GTL_USECRLF  = 1    ' compute answer using CRLFs for paragraphs
%GTL_PRECISE  = 2    ' compute a precise answer
%GTL_CLOSE    = 4    ' fast computation of a "close" answer
%GTL_NUMCHARS = 8    ' return the number of characters
%GTL_NUMBYTES = 16   ' return the number of _bytes_

' EM_GETTEXTLENGTHEX info; this struct is passed in the wparam of the msg
TYPE GETTEXTLENGTHEX
    flags AS DWORD       ' flags (see GTL_XXX defines)
    codepage AS DWORD    ' code page for translation (CP_ACP for default,
                         ' 1200 for Unicode
END TYPE

' BiDi specific features
TYPE BIDIOPTIONS BYTE
    cbSize   AS DWORD
    wMask    AS WORD
    wEffects AS WORD
END TYPE

' BIDIOPTIONS masks
#IF (%RICHEDIT_VER = &H0100)
%BOM_DEFPARADIR       = &H0001  ' Default paragraph direction (implies alignment) (obsolete)
%BOM_PLAINTEXT        = &H0002  ' Use plain text layout (obsolete)
#ENDIF
%BOM_NEUTRALOVERRIDE  = &H0004  ' Override neutral layout (obsolete)
%BOM_CONTEXTREADING   = &H0008  ' Context reading order
%BOM_CONTEXTALIGNMENT = &H0010  ' Context alignment
%BOM_LEGACYBIDICLASS  = &H0040  ' Legacy Bidi classification

' BIDIOPTIONS effects
#IF (%RICHEDIT_VER = &H0100)
%BOE_RTLDIR           = &H0001  ' Default paragraph direction (implies alignment) (obsolete)
%BOE_PLAINTEXT        = &H0002  ' Use plain text layout (obsolete)
#ENDIF
%BOE_NEUTRALOVERRIDE  = &H0004  ' Override neutral layout (obsolete)
%BOE_CONTEXTREADING   = &H0008  ' Context reading order
%BOE_CONTEXTALIGNMENT = &H0010  ' Context alignment
%BOE_LEGACYBIDICLASS  = &H0040  ' Legacy Bidi classification

' Additional EM_FINDTEXT[EX] flags
%FR_MATCHDIAC      = &H20000000
%FR_MATCHKASHIDA   = &H40000000
%FR_MATCHALEFHAMZA = &H80000000???


' UNICODE embedding character
#IF NOT %DEF(%WCH_EMBEDDING)
%WCH_EMBEDDING = &HFFFC??
$$WCH_EMBEDDING = CHR$$(%WCH_EMBEDDING)
#ENDIF ' %WCH_EMBEDDING

' khyph - Kind of hyphenation
MACRO KHYPH_enum=LONG
ENUM KHYPH SINGULAR
    khyphNil            ' No Hyphenation
    khyphNormal         ' Normal Hyphenation
    khyphAddBefore      ' Add letter before hyphen
    khyphChangeBefore   ' Change letter before hyphen
    khyphDeleteBefore   ' Delete letter before hyphen
    khyphChangeAfter    ' Change letter after hyphen
    khyphDelAndChange   ' Delete letter before hyphen and change
                        '  letter preceding hyphen
END ENUM

TYPE HYPHRESULT
    khyph   AS KHYPH_enum   ' Kind of hyphenation
    ichHyph AS LONG         ' Character which was hyphenated
    chHyph  AS WSTRING * 1  ' Depending on hyphenation type, character added, changed, etc.
END TYPE

DECLARE SUB HyphenateProc (pszWord AS WSTRINGZ, BYVAL langid AS DWORD, _
    BYVAL ichExceed AS LONG, phyphresult AS HYPHRESULT)

TYPE HYPHENATEINFO
    cbSize          AS INTEGER  ' Size of HYPHENATEINFO structure
    dxHyphenateZone AS INTEGER  ' If a space character is closer to the margin
                                '  than this value, don't hyphenate (in TWIPs)
END TYPE

DECLARE SUB pfnHyphenate (pszWord AS WSTRINGZ, BYVAL langid AS DWORD, _
    BYVAL ichExceed AS LONG, phyphresult AS HYPHRESULT)
