'------------------------------------------------------------------------------
'
' DDT.INC -- Win32 API Constants for PowerBASIC
'
' Copyright (c) 1997-2003,2009,2011 PowerBASIC, Inc.
' Portions Copyright (c) Microsoft Corporation
' All Rights Reserved.
'
' Last updated 02 May 2011
'
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%DDT_INC = 1

%TRUE  = 1
%FALSE = 0
%NULL  = 0

%HEAP_NO_SERIALIZE             = &H00000001
%HEAP_GROWABLE                 = &H00000002
%HEAP_GENERATE_EXCEPTIONS      = &H00000004
%HEAP_ZERO_MEMORY              = &H00000008
%HEAP_REALLOC_IN_PLACE_ONLY    = &H00000010
%HEAP_TAIL_CHECKING_ENABLED    = &H00000020
%HEAP_FREE_CHECKING_ENABLED    = &H00000040
%HEAP_DISABLE_COALESCE_ON_FREE = &H00000080
%HEAP_CREATE_ALIGN_16          = &H00010000
%HEAP_CREATE_ENABLE_TRACING    = &H00020000
%HEAP_MAXIMUM_TAG              = &H00000FFF
%HEAP_PSEUDO_TAG_FLAG          = &H00008000
%HEAP_TAG_SHIFT                = 18

%IS_TEXT_UNICODE_ASCII16            = &H00000001
%IS_TEXT_UNICODE_REVERSE_ASCII16    = &H00000010
%IS_TEXT_UNICODE_STATISTICS         = &H00000002
%IS_TEXT_UNICODE_REVERSE_STATISTICS = &H00000020
%IS_TEXT_UNICODE_CONTROLS           = &H00000004
%IS_TEXT_UNICODE_REVERSE_CONTROLS   = &H00000040
%IS_TEXT_UNICODE_SIGNATURE          = &H00000008
%IS_TEXT_UNICODE_REVERSE_SIGNATURE  = &H00000080
%IS_TEXT_UNICODE_ILLEGAL_CHARS      = &H00000100
%IS_TEXT_UNICODE_ODD_LENGTH         = &H00000200
%IS_TEXT_UNICODE_DBCS_LEADBYTE      = &H00000400
%IS_TEXT_UNICODE_NULL_BYTES         = &H00001000
%IS_TEXT_UNICODE_UNICODE_MASK       = &H0000000F
%IS_TEXT_UNICODE_REVERSE_MASK       = &H000000F0
%IS_TEXT_UNICODE_NOT_UNICODE_MASK   = &H00000F00
%IS_TEXT_UNICODE_NOT_ASCII_MASK     = &H0000F000

%COMPRESSION_FORMAT_NONE     = &H0000
%COMPRESSION_FORMAT_DEFAULT  = &H0001
%COMPRESSION_FORMAT_LZNT1    = &H0002
%COMPRESSION_ENGINE_STANDARD = &H0000
%COMPRESSION_ENGINE_MAXIMUM  = &H0100
%COMPRESSION_ENGINE_HIBER    = &H0200

' return codes for %WM_MENUCHAR
%MNC_IGNORE  = 0
%MNC_CLOSE   = 1
%MNC_EXECUTE = 2
%MNC_SELECT  = 3

%MNS_NOCHECK      = &H80000000???
%MNS_MODELESS     = &H40000000
%MNS_DRAGDROP     = &H20000000
%MNS_AUTODISMISS  = &H10000000
%MNS_NOTIFYBYPOS  = &H08000000
%MNS_CHECKORBMP   = &H04000000

%MIM_MAXHEIGHT       = &H00000001
%MIM_BACKGROUND      = &H00000002
%MIM_HELPID          = &H00000004
%MIM_MENUDATA        = &H00000008
%MIM_STYLE           = &H00000010
%MIM_APPLYTOSUBMENUS = &H80000000???

' %WM_MENUDRAG return values
%MND_CONTINUE = 0
%MND_ENDMENU  = 1

' MENUGETOBJECTINFO dwFlags values
%MNGOF_TOPGAP     = &H00000001
%MNGOF_BOTTOMGAP  = &H00000002

' WM_MENUGETOBJECT return values
%MNGO_NOINTERFACE = &H00000000
%MNGO_NOERROR     = &H00000001

%HBMMENU_CALLBACK        = &HFFFFFFFF??? ' BITS???(-1)
%HBMMENU_SYSTEM          =  1
%HBMMENU_MBAR_RESTORE    =  2
%HBMMENU_MBAR_MINIMIZE   =  3
%HBMMENU_MBAR_CLOSE      =  5
%HBMMENU_MBAR_CLOSE_D    =  6
%HBMMENU_MBAR_MINIMIZE_D =  7
%HBMMENU_POPUP_CLOSE     =  8
%HBMMENU_POPUP_RESTORE   =  9
%HBMMENU_POPUP_MAXIMIZE  = 10
%HBMMENU_POPUP_MINIMIZE  = 11

%TPM_RECURSE         = &H00001
%TPM_HORPOSANIMATION = &H00400
%TPM_HORNEGANIMATION = &H00800
%TPM_VERPOSANIMATION = &H01000
%TPM_VERNEGANIMATION = &H02000
%TPM_NOANIMATION     = &H04000
%TPM_LAYOUTRTL       = &H08000
%TPM_WORKAREA        = &H10000

%DOF_EXECUTABLE = &H00008001      ' wFmt flags
%DOF_DOCUMENT   = &H00008002
%DOF_DIRECTORY  = &H00008003
%DOF_MULTIPLE   = &H00008004
%DOF_PROGMAN    = &H00000001
%DOF_SHELLDATA  = &H00000002

%DO_DROPFILE    = &H454C4946
%DO_PRINTFILE   = &H544E5250

#IF NOT %DEF(%NORESOURCE) '---------------------------

%RT_CURSOR       = 1
%RT_BITMAP       = 2
%RT_ICON         = 3
%RT_MENU         = 4
%RT_DIALOG       = 5
%RT_STRING       = 6
%RT_FONTDIR      = 7
%RT_FONT         = 8
%RT_ACCELERATOR  = 9
%RT_RCDATA       = 10
%RT_MESSAGETABLE = 11
%RT_GROUP_CURSOR = 12
%RT_GROUP_ICON   = 14
%RT_VERSION      = 16
%RT_DLGINCLUDE   = 17
%RT_PLUGPLAY     = 19
%RT_VXD          = 20
%RT_ANICURSOR    = 21
%RT_ANIICON      = 22
%RT_HTML         = 23
%RT_MANIFEST     = 24
%CREATEPROCESS_MANIFEST_RESOURCE_ID =  1
%ISOLATIONAWARE_MANIFEST_RESOURCE_ID = 2
%ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID = 3
%MINIMUM_RESERVED_MANIFEST_RESOURCE_ID =  1 ' inclusive
%MAXIMUM_RESERVED_MANIFEST_RESOURCE_ID = 16 ' inclusive

#ENDIF ' #IF NOT %DEF(%NORESOURCE) -------------------

%DFC_CAPTION     = 1
%DFC_MENU        = 2
%DFC_SCROLL      = 3
%DFC_BUTTON      = 4
%DFC_POPUPMENU   = 5

%DFCS_CAPTIONCLOSE   = &H0000
%DFCS_CAPTIONMIN     = &H0001
%DFCS_CAPTIONMAX     = &H0002
%DFCS_CAPTIONRESTORE = &H0003
%DFCS_CAPTIONHELP    = &H0004

%DFCS_MENUARROW      = &H0000
%DFCS_MENUCHECK      = &H0001
%DFCS_MENUBULLET     = &H0002
%DFCS_MENUARROWRIGHT = &H0004

%DFCS_SCROLLUP            = &H0000
%DFCS_SCROLLDOWN          = &H0001
%DFCS_SCROLLLEFT          = &H0002
%DFCS_SCROLLRIGHT         = &H0003
%DFCS_SCROLLCOMBOBOX      = &H0005
%DFCS_SCROLLSIZEGRIP      = &H0008
%DFCS_SCROLLSIZEGRIPRIGHT = &H0010

%DFCS_BUTTONCHECK      = &H0000
%DFCS_BUTTONRADIOIMAGE = &H0001
%DFCS_BUTTONRADIOMASK  = &H0002
%DFCS_BUTTONRADIO      = &H0004
%DFCS_BUTTON3STATE     = &H0008
%DFCS_BUTTONPUSH       = &H0010

%DFCS_INACTIVE    = &H00000100
%DFCS_PUSHED      = &H00000200
%DFCS_CHECKED     = &H00000400
%DFCS_TRANSPARENT = &H00000800
%DFCS_HOT         = &H00001000
%DFCS_ADJUSTRECT  = &H00002000
%DFCS_FLAT        = &H00004000
%DFCS_MONO        = &H00008000

' flags for DrawCaption
%DC_ACTIVE   = &H0001
%DC_SMALLCAP = &H0002
%DC_ICON     = &H0004
%DC_TEXT     = &H0008
%DC_INBUTTON = &H0010
%DC_GRADIENT = &H0020
%DC_BUTTONS  = &H1000

%IDANI_OPEN    = 1
%IDANI_CAPTION = 3

%DDD_RAW_TARGET_PATH        = &H00000001
%DDD_REMOVE_DEFINITION      = &H00000002
%DDD_EXACT_MATCH_ON_REMOVE  = &H00000004
%DDD_NO_BROADCAST_SYSTEM    = &H00000008
%DDD_LUID_BROADCAST_DRIVE   = &H00000010

%MAX_DRIVE = 3    ' max. length of drive component
%MAX_DIR   = 256  ' max. length of path component
%MAX_EXT   = 256  ' max. length of extension component

%FOREGROUND_BLUE      = &H0001 ' text color contains blue.
%FOREGROUND_GREEN     = &H0002 ' text color contains green.
%FOREGROUND_RED       = &H0004 ' text color contains red.
%FOREGROUND_INTENSITY = &H0008 ' text color is intensified.
%BACKGROUND_BLUE      = &H0010 ' background color contains blue.
%BACKGROUND_GREEN     = &H0020 ' background color contains green.
%BACKGROUND_RED       = &H0040 ' background color contains red.
%BACKGROUND_INTENSITY = &H0080 ' background color is intensified.
%COMMON_LVB_LEADING_BYTE    = &H0100 ' Leading Byte of DBCS
%COMMON_LVB_TRAILING_BYTE   = &H0200 ' Trailing Byte of DBCS
%COMMON_LVB_GRID_HORIZONTAL = &H0400 ' DBCS: Grid attribute: top horizontal.
%COMMON_LVB_GRID_LVERTICAL  = &H0800 ' DBCS: Grid attribute: left vertical.
%COMMON_LVB_GRID_RVERTICAL  = &H1000 ' DBCS: Grid attribute: right vertical.
%COMMON_LVB_REVERSE_VIDEO   = &H4000 ' DBCS: Reverse fore/back ground attribute.
%COMMON_LVB_UNDERSCORE      = &H8000?? ' DBCS: Underscore.

%COMMON_LVB_SBCSDBCS        = &H0300 ' SBCS or DBCS flag.

%R2_BLACK       = 1   ' 0
%R2_NOTMERGEPEN = 2   ' DPon
%R2_MASKNOTPEN  = 3   ' DPna
%R2_NOTCOPYPEN  = 4   ' PN
%R2_MASKPENNOT  = 5   ' PDna
%R2_NOT         = 6   ' Dn
%R2_XORPEN      = 7   ' DPx
%R2_NOTMASKPEN  = 8   ' DPan
%R2_MASKPEN     = 9   ' DPa
%R2_NOTXORPEN   = 10  ' DPxn
%R2_NOP         = 11  ' D
%R2_MERGENOTPEN = 12  ' DPno
%R2_COPYPEN     = 13  ' P
%R2_MERGEPENNOT = 14  ' PDno
%R2_MERGEPEN    = 15  ' DPo
%R2_WHITE       = 16  ' 1
%R2_LAST        = 16

' Ternary raster operations
%SRCCOPY     = &H00CC0020 ' (DWORD) dest = source
%SRCPAINT    = &H00EE0086 ' (DWORD) dest = source OR dest
%SRCAND      = &H008800C6 ' (DWORD) dest = source AND dest
%SRCINVERT   = &H00660046 ' (DWORD) dest = source XOR dest
%SRCERASE    = &H00440328 ' (DWORD) dest = source AND (NOT dest )
%NOTSRCCOPY  = &H00330008 ' (DWORD) dest = (NOT source)
%NOTSRCERASE = &H001100A6 ' (DWORD) dest = (NOT src) AND (NOT dest)
%MERGECOPY   = &H00C000CA ' (DWORD) dest = (source AND pattern)
%MERGEPAINT  = &H00BB0226 ' (DWORD) dest = (NOT source) OR dest
%PATCOPY     = &H00F00021 ' (DWORD) dest = pattern
%PATPAINT    = &H00FB0A09 ' (DWORD) dest = DPSnoo
%PATINVERT   = &H005A0049 ' (DWORD) dest = pattern XOR dest
%DSTINVERT   = &H00550009 ' (DWORD) dest = (NOT dest)
%BLACKNESS   = &H00000042 ' (DWORD) dest = BLACK
%WHITENESS   = &H00FF0062 ' (DWORD) dest = WHITE

%NOMIRRORBITMAP = &H80000000??? ' Do not Mirror the bitmap in this call
%CAPTUREBLT     = &H40000000    ' Include layered windows

%GDI_ERROR  = &HFFFFFFFF???
%HGDI_ERROR = &HFFFFFFFF???

' Region Flags
%ERROR         = 0
%ERRORAPI      = %ERROR  ' [legacy]
%NULLREGION    = 1
%SIMPLEREGION  = 2
%COMPLEXREGION = 3
%RGN_ERROR = %ERROR

' CombineRgn() Styles
%RGN_AND  = 1
%RGN_OR   = 2
%RGN_XOR  = 3
%RGN_DIFF = 4
%RGN_COPY = 5
%RGN_MIN  = %RGN_AND
%RGN_MAX  = %RGN_COPY

' StretchBlt() Modes
%MAXSTRETCHBLTMODE = 4

' New StretchBlt() Modes
%STRETCH_ANDSCANS    = %BLACKONWHITE
%STRETCH_ORSCANS     = %WHITEONBLACK
%STRETCH_DELETESCANS = %COLORONCOLOR
%STRETCH_HALFTONE    = %HALFTONE

' Layout Orientation Options
%LAYOUT_RTL                        = &H00000001 ' Right to left
%LAYOUT_BTT                        = &H00000002 ' Bottom to top
%LAYOUT_VBH                        = &H00000004 ' Vertical before horizontal
%LAYOUT_ORIENTATIONMASK            = (%LAYOUT_RTL OR %LAYOUT_BTT OR %LAYOUT_VBH)
%LAYOUT_BITMAPORIENTATIONPRESERVED = &H00000008

' PolyFill() Modes
%ALTERNATE     = 1
%WINDING       = 2
%POLYFILL_LAST = 2

' Text Alignment Options
%TA_NOUPDATECP = 0
%TA_UPDATECP   = 1

%TA_LEFT       = 0
%TA_RIGHT      = 2
%TA_CENTER     = 6

%TA_TOP        = 0
%TA_BOTTOM     = 8
%TA_BASELINE   = 24
%TA_RTLREADING = 256
%TA_MASK       = %TA_BASELINE + %TA_CENTER + %TA_UPDATECP + %TA_RTLREADING

%VTA_BASELINE  = %TA_BASELINE
%VTA_LEFT      = %TA_BOTTOM
%VTA_RIGHT     = %TA_TOP
%VTA_CENTER    = %TA_CENTER
%VTA_BOTTOM    = %TA_RIGHT
%VTA_TOP       = %TA_LEFT

%ETO_OPAQUE            = 2
%ETO_CLIPPED           = 4
%ETO_GLYPH_INDEX       = &H0010
%ETO_RTLREADING        = &H0080
%ETO_NUMERICSLOCAL     = &H0400
%ETO_NUMERICSLATIN     = &H0800
%ETO_IGNORELANGUAGE    = &H1000
%ETO_PDY               = &H2000
%ETO_REVERSE_INDEX_MAP = &H10000

%ASPECT_FILTERING = &H1

' Bounds Accumulation APIs

%DCB_RESET       = &H0001
%DCB_ACCUMULATE  = &H0002
%DCB_DIRTY       = %DCB_ACCUMULATE
%DCB_SET         = (%DCB_RESET OR %DCB_ACCUMULATE)
%DCB_ENABLE      = &H0004
%DCB_DISABLE     = &H0008

' Metafile Functions
%META_SAVEDC                = &H01E
%META_REALIZEPALETTE        = &H035
%META_SETPALENTRIES         = &H037
%META_CREATEPALETTE         = &H0F7
%META_SETBKMODE             = &H102
%META_SETMAPMODE            = &H103
%META_SETROP2               = &H104
%META_SETRELABS             = &H105
%META_SETPOLYFILLMODE       = &H106
%META_SETSTRETCHBLTMODE     = &H107
%META_SETTEXTCHAREXTRA      = &H108
%META_RESTOREDC             = &H127
%META_INVERTREGION          = &H12A
%META_PAINTREGION           = &H12B
%META_SELECTCLIPREGION      = &H12C
%META_SELECTOBJECT          = &H12D
%META_SETTEXTALIGN          = &H12E
%META_RESIZEPALETTE         = &H139
%META_DIBCREATEPATTERNBRUSH = &H142
%META_DELETEOBJECT          = &H1F0
%META_CREATEPATTERNBRUSH    = &H1F9
%META_SETBKCOLOR            = &H201
%META_SETTEXTCOLOR          = &H209
%META_SETTEXTJUSTIFICATION  = &H20A
%META_SETWINDOWORG          = &H20B
%META_SETWINDOWEXT          = &H20C
%META_SETVIEWPORTORG        = &H20D
%META_SETVIEWPORTEXT        = &H20E
%META_OFFSETWINDOWORG       = &H20F
%META_OFFSETVIEWPORTORG     = &H211
%META_LINETO                = &H213
%META_MOVETO                = &H214
%META_OFFSETCLIPRGN         = &H220
%META_FILLREGION            = &H228
%META_SETMAPPERFLAGS        = &H231
%META_SELECTPALETTE         = &H234
%META_CREATEPENINDIRECT     = &H2FA
%META_CREATEFONTINDIRECT    = &H2FB
%META_CREATEBRUSHINDIRECT   = &H2FC
%META_POLYGON               = &H324
%META_POLYLINE              = &H325
%META_SCALEWINDOWEXT        = &H410
%META_SCALEVIEWPORTEXT      = &H412
%META_EXCLUDECLIPRECT       = &H415
%META_INTERSECTCLIPRECT     = &H416
%META_ELLIPSE               = &H418
%META_FLOODFILL             = &H419
%META_RECTANGLE             = &H41B
%META_SETPIXEL              = &H41F
%META_FRAMEREGION           = &H429
%META_ANIMATEPALETTE        = &H436
%META_TEXTOUT               = &H521
%META_POLYPOLYGON           = &H538
%META_EXTFLOODFILL          = &H548
%META_ROUNDRECT             = &H61C
%META_PATBLT                = &H61D
%META_ESCAPE                = &H626
%META_CREATEREGION          = &H6FF
%META_ARC                   = &H817
%META_PIE                   = &H81A
%META_CHORD                 = &H830
%META_BITBLT                = &H922
%META_DIBBITBLT             = &H940
%META_EXTTEXTOUT            = &HA32
%META_STRETCHBLT            = &HB23
%META_DIBSTRETCHBLT         = &HB41
%META_SETDIBTODEV           = &HD33
%META_STRETCHDIB            = &HF43
%META_EXTFLOODFILL          = &H0548
%META_SETLAYOUT             = &H0149
%META_DELETEOBJECT          = &H01f0
%META_CREATEPALETTE         = &H00f7
%META_CREATEPATTERNBRUSH    = &H01F9
%META_CREATEPENINDIRECT     = &H02FA
%META_CREATEFONTINDIRECT    = &H02FB
%META_CREATEBRUSHINDIRECT   = &H02FC
%META_CREATEREGION          = &H06FF

' GDI Escapes
%NEWFRAME           = 1
%AbortDocC          = 2
%NEXTBAND           = 3
%SETCOLORTABLE      = 4
%GETCOLORTABLE      = 5
%FLUSHOUTPUT        = 6
%DRAFTMODE          = 7
%QUERYESCSUPPORT    = 8
%SETABORTPROC       = 9
%StartDocC          = 10
%EndDocC            = 11
%GETPHYSPAGESIZE    = 12
%GETPRINTINGOFFSET  = 13
%GETSCALINGFACTOR   = 14
%MFCOMMENT          = 15
%GETPENWIDTH        = 16
%SETCOPYCOUNT       = 17
%SELECTPAPERSOURCE  = 18
%DEVICEDATA         = 19
%PASSTHROUGH        = 19
%GETTECHNOLGY       = 20
%GETTECHNOLOGY      = 20
%SETLINECAP         = 21
%SETLINEJOIN        = 22
%SetMiterLimitC     = 23
%BANDINFO           = 24
%DRAWPATTERNRECT    = 25
%GETVECTORPENSIZE   = 26
%GETVECTORBRUSHSIZE = 27
%ENABLEDUPLEX       = 28
%GETSETPAPERBINS    = 29
%GETSETPRINTORIENT  = 30
%ENUMPAPERBINS      = 31
%SETDIBSCALING      = 32
%EPSPRINTING        = 33
%ENUMPAPERMETRICS   = 34
%GETSETPAPERMETRICS = 35
%POSTSCRIPT_DATA    = 37
%POSTSCRIPT_IGNORE  = 38
%MOUSETRAILS        = 39
%GETDEVICEUNITS     = 42

%GETEXTENDEDTEXTMETRICS = 256
%GETEXTENTTABLE         = 257
%GETPAIRKERNTABLE       = 258
%GETTRACKKERNTABLE      = 259
%ExtTextOutC            = 512
%GETFACENAME            = 513
%DOWNLOADFACE           = 514
%ENABLERELATIVEWIDTHS   = 768
%ENABLEPAIRKERNING      = 769
%SETKERNTRACK           = 770
%SETALLJUSTVALUES       = 771
%SETCHARSET             = 772

%STRETCHBLTC            = 2048
%METAFILE_DRIVER        = 2049
%GETSETSCREENPARAMS     = 3072
%QUERYDIBSUPPORT        = 3073
%BEGIN_PATH             = 4096
%CLIP_TO_PATH           = 4097
%END_PATH               = 4098
%EXT_DEVICE_CAPS        = 4099
%RESTORE_CTM            = 4100
%SAVE_CTM               = 4101
%SET_ARC_DIRECTION      = 4102
%SET_BACKGROUND_COLOR   = 4103
%SET_POLY_MODE          = 4104
%SET_SCREEN_ANGLE       = 4105
%SET_SPREAD             = 4106
%TRANSFORM_CTM          = 4107
%SET_CLIP_BOX           = 4108
%SET_BOUNDS             = 4109
%SET_MIRROR_MODE        = 4110
%OPENCHANNEL            = 4110
%DOWNLOADHEADER         = 4111
%CLOSECHANNEL           = 4112
%POSTSCRIPT_PASSTHROUGH = 4115
%ENCAPSULATED_POSTSCRIPT = 4116
%POSTSCRIPT_IDENTIFY    = 4117   ' new escape for NT5 pscript driver
%POSTSCRIPT_INJECTION   = 4118   ' new escape for NT5 pscript driver
%CHECKJPEGFORMAT        = 4119
%CHECKPNGFORMAT         = 4120

%GET_PS_FEATURESETTING  = 4121   ' new escape for NT5 pscript driver

%GDIPLUS_TS_QUERYVER    = 4122   ' private escape
%GDIPLUS_TS_RECORD      = 4123   ' private escape

%MILCORE_TS_QUERYVER_RESULT_FALSE = &H0
%MILCORE_TS_QUERYVER_RESULT_TRUE  = &H7FFFFFFF

%SPCLPASSTHROUGH2           = 4568   ' new escape for NT5 pscript driver

%PSIDENT_GDICENTRIC  = 0
%PSIDENT_PSCENTRIC   = 1

' Spooler Error Codes
%SP_NOTREPORTED = &H4000
%SP_ERROR       = -1
%SP_APPABORT    = -2
%SP_USERABORT   = -3
%SP_OUTOFDISK   = -4
%SP_OUTOFMEMORY = -5

%PR_JOBSTATUS = &H0

%PSINJECT_BEGINSTREAM                = 1
%PSINJECT_PSADOBE                    = 2
%PSINJECT_PAGESATEND                 = 3
%PSINJECT_PAGES                      = 4

%PSINJECT_DOCNEEDEDRES               = 5
%PSINJECT_DOCSUPPLIEDRES             = 6
%PSINJECT_PAGEORDER                  = 7
%PSINJECT_ORIENTATION                = 8
%PSINJECT_BOUNDINGBOX                = 9
%PSINJECT_DOCUMENTPROCESSCOLORS      = 10

%PSINJECT_COMMENTS                   = 11
%PSINJECT_BEGINDEFAULTS              = 12
%PSINJECT_ENDDEFAULTS                = 13
%PSINJECT_BEGINPROLOG                = 14
%PSINJECT_ENDPROLOG                  = 15
%PSINJECT_BEGINSETUP                 = 16
%PSINJECT_ENDSETUP                   = 17
%PSINJECT_TRAILER                    = 18
%PSINJECT_EOF                        = 19
%PSINJECT_ENDSTREAM                  = 20
%PSINJECT_DOCUMENTPROCESSCOLORSATEND = 21

%PSINJECT_PAGENUMBER                 = 100
%PSINJECT_BEGINPAGESETUP             = 101
%PSINJECT_ENDPAGESETUP               = 102
%PSINJECT_PAGETRAILER                = 103
%PSINJECT_PLATECOLOR                 = 104

%PSINJECT_SHOWPAGE                   = 105
%PSINJECT_PAGEBBOX                   = 106
%PSINJECT_ENDPAGECOMMENTS            = 107

%PSINJECT_VMSAVE                     = 200
%PSINJECT_VMRESTORE                  = 201

%PSINJECT_DLFONT                     = &Hdddddddd???

%FEATURESETTING_NUP                = 0
%FEATURESETTING_OUTPUT             = 1
%FEATURESETTING_PSLEVEL            = 2
%FEATURESETTING_CUSTPAPER          = 3
%FEATURESETTING_MIRROR             = 4
%FEATURESETTING_NEGATIVE           = 5
%FEATURESETTING_PROTOCOL           = 6

%FEATURESETTING_PRIVATE_BEGIN = &H1000
%FEATURESETTING_PRIVATE_END   = &H1FFF

' Value returned for FEATURESETTING_PROTOCOL
%PSPROTOCOL_ASCII           = 0
%PSPROTOCOL_BCP             = 1
%PSPROTOCOL_TBCP            = 2
%PSPROTOCOL_BINARY          = 3

' Flag returned from QUERYDIBSUPPORT
%QDI_SETDIBITS              = 1
%QDI_GETDIBITS              = 2
%QDI_DIBTOSCREEN            = 4
%QDI_STRETCHDIB             = 8

' Spooler Error Codes
%SP_NOTREPORTED             = &H4000
%SP_ERROR                   = -1
%SP_APPABORT                = -2
%SP_USERABORT               = -3
%SP_OUTOFDISK               = -4
%SP_OUTOFMEMORY             = -5

%PR_JOBSTATUS               = &H0000

' Object Definitions for EnumObjects()
%OBJ_PEN         = 1
%OBJ_BRUSH       = 2
%OBJ_DC          = 3
%OBJ_METADC      = 4
%OBJ_PAL         = 5
%OBJ_FONT        = 6
%OBJ_BITMAP      = 7
%OBJ_REGION      = 8
%OBJ_METAFILE    = 9
%OBJ_MEMDC       = 10
%OBJ_EXTPEN      = 11
%OBJ_ENHMETADC   = 12
%OBJ_ENHMETAFILE = 13
%OBJ_COLORSPACE  = 14

' xform stuff
%MWT_IDENTITY      = 1
%MWT_LEFTMULTIPLY  = 2
%MWT_RIGHTMULTIPLY = 3

%MWT_MIN           = %MWT_IDENTITY
%MWT_MAX           = %MWT_RIGHTMULTIPLY

%BI_RGB       = 0
%BI_RLE8      = 1
%BI_RLE4      = 2
%BI_BITFIELDS = 3
%BI_JPEG      = 4
%BI_PNG       = 5

%NTM_REGULAR        = &H00000040
%NTM_BOLD           = &H00000020
%NTM_ITALIC         = &H00000001
%NTM_NONNEGATIVE_AC = &H00010000
%NTM_OPENTYPE       = &H00020000
%NTM_MULTIPLEMASTER = &H00040000
%NTM_MM_INSTANCE    = &H00080000
%NTM_TYPE1          = &H00100000
%NTM_DSIG           = &H00200000

%TMPF_FIXED_PITCH = &H1
%TMPF_VECTOR      = &H2
%TMPF_DEVICE      = &H8
%TMPF_TRUETYPE    = &H4

#IF NOT %DEF(%LF_FACESIZE)
  %LF_FACESIZE     = 32
  %LF_FULLFACESIZE = 64
#ENDIF

%OUT_DEFAULT_PRECIS   = 0
%OUT_STRING_PRECIS    = 1
%OUT_CHARACTER_PRECIS = 2
%OUT_STROKE_PRECIS    = 3
%OUT_TT_PRECIS        = 4
%OUT_DEVICE_PRECIS    = 5
%OUT_RASTER_PRECIS    = 6
%OUT_TT_ONLY_PRECIS   = 7
%OUT_OUTLINE_PRECIS   = 8
%OUT_SCREEN_OUTLINE_PRECIS = 9
%OUT_PS_ONLY_PRECIS        = 10

%CLIP_DEFAULT_PRECIS   = 0
%CLIP_CHARACTER_PRECIS = 1
%CLIP_STROKE_PRECIS    = 2
%CLIP_MASK             = &HF
%CLIP_LH_ANGLES        = 16
%CLIP_TT_ALWAYS        = 32
%CLIP_EMBEDDED         = 128

%DEFAULT_QUALITY = 0
%DRAFT_QUALITY   = 1
%PROOF_QUALITY   = 2
%NONANTIALIASED_QUALITY = 3
%ANTIALIASED_QUALITY    = 4
%CLEARTYPE_QUALITY     = 5
%CLEARTYPE_NATURAL_QUALITY = 6

%DEFAULT_PITCH  = 0
%FIXED_PITCH    = 1
%VARIABLE_PITCH = 2
%MONO_FONT      = 8

%ANSI_CHARSET        = 0
%DEFAULT_CHARSET     = 1
%SYMBOL_CHARSET      = 2
%SHIFTJIS_CHARSET    = 128
%HANGEUL_CHARSET     = 129
%HANGUL_CHARSET      = 129
%CHINESEBIG5_CHARSET = 136
%OEM_CHARSET         = 255
%JOHAB_CHARSET       = 130
%HEBREW_CHARSET      = 177
%ARABIC_CHARSET      = 178
%GREEK_CHARSET       = 161
%TURKISH_CHARSET     = 162
%THAI_CHARSET        = 222
%EASTEUROPE_CHARSET  = 238
%RUSSIAN_CHARSET     = 204
%MAC_CHARSET         = 77
%BALTIC_CHARSET      = 186

' Font Families
%FF_DONTCARE = 0    ' Don't care or don't know.
%FF_ROMAN    = 16   ' Variable stroke width, serifed.
%FF_SWISS    = 32   ' Variable stroke width, sans-serifed.
%FF_MODERN   = 48   ' Constant stroke width, serifed or sans-serifed.
%FF_SCRIPT     = 64 ' Cursive, etc.
%FF_DECORATIVE = 80 ' Old English, etc.

' Font Families
%FF_DONTCARE   = 0    ' Don't care or don't know.
%FF_ROMAN      = 16   ' Variable stroke width, serifed.
                      ' Times Roman, Century Schoolbook, etc.
%FF_SWISS      = 32   ' Variable stroke width, sans-serifed.
                      ' Helvetica, Swiss, etc.
%FF_MODERN     = 48   ' Constant stroke width, serifed or sans-serifed.
                      ' Pica, Elite, Courier, etc.
%FF_SCRIPT     = 64   ' Cursive, etc.
%FF_DECORATIVE = 80   ' Old English, etc.

' Font Weights
%FW_DONTCARE    = 0
%FW_THIN        = 100
%FW_EXTRALIGHT  = 200
%FW_LIGHT       = 300
%FW_NORMAL      = 400
%FW_MEDIUM      = 500
%FW_SEMIBOLD    = 600
%FW_BOLD        = 700
%FW_EXTRABOLD   = 800
%FW_HEAVY       = 900

%FW_ULTRALIGHT  = %FW_EXTRALIGHT
%FW_REGULAR     = %FW_NORMAL
%FW_DEMIBOLD    = %FW_SEMIBOLD
%FW_ULTRABOLD   = %FW_EXTRABOLD
%FW_BLACK       = %FW_HEAVY

%PANOSE_COUNT              = 10
%PAN_FAMILYTYPE_INDEX      = 0
%PAN_SERIFSTYLE_INDEX      = 1
%PAN_WEIGHT_INDEX          = 2
%PAN_PROPORTION_INDEX      = 3
%PAN_CONTRAST_INDEX        = 4
%PAN_STROKEVARIATION_INDEX = 5
%PAN_ARMSTYLE_INDEX        = 6
%PAN_LETTERFORM_INDEX      = 7
%PAN_MIDLINE_INDEX         = 8
%PAN_XHEIGHT_INDEX         = 9

%PAN_CULTURE_LATIN         = 0

%PAN_ANY                   = 0  ' Any
%PAN_NO_FIT                = 1  ' No Fit

%PAN_FAMILY_TEXT_DISPLAY   = 2  ' Text and Display
%PAN_FAMILY_SCRIPT         = 3  ' Script
%PAN_FAMILY_DECORATIVE     = 4  ' Decorative
%PAN_FAMILY_PICTORIAL      = 5  ' Pictorial

%PAN_SERIF_COVE               = 2  ' Cove
%PAN_SERIF_OBTUSE_COVE        = 3  ' Obtuse Cove
%PAN_SERIF_SQUARE_COVE        = 4  ' Square Cove
%PAN_SERIF_OBTUSE_SQUARE_COVE = 5  ' Obtuse Square Cove
%PAN_SERIF_SQUARE             = 6  ' Square
%PAN_SERIF_THIN               = 7  ' Thin
%PAN_SERIF_BONE               = 8  ' Bone
%PAN_SERIF_EXAGGERATED        = 9  ' Exaggerated
%PAN_SERIF_TRIANGLE           = 10 ' Triangle
%PAN_SERIF_NORMAL_SANS        = 11 ' Normal Sans
%PAN_SERIF_OBTUSE_SANS        = 12 ' Obtuse Sans
%PAN_SERIF_PERP_SANS          = 13 ' Prep Sans
%PAN_SERIF_FLARED             = 14 ' Flared
%PAN_SERIF_ROUNDED            = 15 ' Rounded

%PAN_WEIGHT_VERY_LIGHT        = 2  ' Very Light
%PAN_WEIGHT_LIGHT             = 3  ' Light
%PAN_WEIGHT_THIN              = 4  ' Thin
%PAN_WEIGHT_BOOK              = 5  ' Book
%PAN_WEIGHT_MEDIUM            = 6  ' Medium
%PAN_WEIGHT_DEMI              = 7  ' Demi
%PAN_WEIGHT_BOLD              = 8  ' Bold
%PAN_WEIGHT_HEAVY             = 9  ' Heavy
%PAN_WEIGHT_BLACK             = 10 ' Black
%PAN_WEIGHT_NORD              = 11 ' Nord

%PAN_PROP_OLD_STYLE           = 2  ' Old Style
%PAN_PROP_MODERN              = 3  ' Modern
%PAN_PROP_EVEN_WIDTH          = 4  ' Even Width
%PAN_PROP_EXPANDED            = 5  ' Expanded
%PAN_PROP_CONDENSED           = 6  ' Condensed
%PAN_PROP_VERY_EXPANDED       = 7  ' Very Expanded
%PAN_PROP_VERY_CONDENSED      = 8  ' Very Condensed
%PAN_PROP_MONOSPACED          = 9  ' Monospaced

%PAN_CONTRAST_NONE            = 2  ' None
%PAN_CONTRAST_VERY_LOW        = 3  ' Very Low
%PAN_CONTRAST_LOW             = 4  ' Low
%PAN_CONTRAST_MEDIUM_LOW      = 5  ' Medium Low
%PAN_CONTRAST_MEDIUM          = 6  ' Medium
%PAN_CONTRAST_MEDIUM_HIGH     = 7  ' Mediim High
%PAN_CONTRAST_HIGH            = 8  ' High
%PAN_CONTRAST_VERY_HIGH       = 9  ' Very High

%PAN_STROKE_GRADUAL_DIAG      = 2  ' Gradual/Diagonal
%PAN_STROKE_GRADUAL_TRAN      = 3  ' Gradual/Transitional
%PAN_STROKE_GRADUAL_VERT      = 4  ' Gradual/Vertical
%PAN_STROKE_GRADUAL_HORZ      = 5  ' Gradual/Horizontal
%PAN_STROKE_RAPID_VERT        = 6  ' Rapid/Vertical
%PAN_STROKE_RAPID_HORZ        = 7  ' Rapid/Horizontal
%PAN_STROKE_INSTANT_VERT      = 8  ' Instant/Vertical

%PAN_STRAIGHT_ARMS_HORZ         = 2  ' Straight Arms/Horizontal
%PAN_STRAIGHT_ARMS_WEDGE        = 3  ' Straight Arms/Wedge
%PAN_STRAIGHT_ARMS_VERT         = 4  ' Straight Arms/Vertical
%PAN_STRAIGHT_ARMS_SINGLE_SERIF = 5  ' Straight Arms/Single-Serif
%PAN_STRAIGHT_ARMS_DOUBLE_SERIF = 6  ' Straight Arms/Double-Serif
%PAN_BENT_ARMS_HORZ             = 7  ' Non-Straight Arms/Horizontal
%PAN_BENT_ARMS_WEDGE            = 8  ' Non-Straight Arms/Wedge
%PAN_BENT_ARMS_VERT             = 9  ' Non-Straight Arms/Vertical
%PAN_BENT_ARMS_SINGLE_SERIF     = 10 ' Non-Straight Arms/Single-Serif
%PAN_BENT_ARMS_DOUBLE_SERIF     = 11 ' Non-Straight Arms/Double-Serif

%PAN_LETT_NORMAL_CONTACT     = 2  ' Normal/Contact
%PAN_LETT_NORMAL_WEIGHTED    = 3  ' Normal/Weighted
%PAN_LETT_NORMAL_BOXED       = 4  ' Normal/Boxed
%PAN_LETT_NORMAL_FLATTENED   = 5  ' Normal/Flattened
%PAN_LETT_NORMAL_ROUNDED     = 6  ' Normal/Rounded
%PAN_LETT_NORMAL_OFF_CENTER  = 7  ' Normal/Off Center
%PAN_LETT_NORMAL_SQUARE      = 8  ' Normal/Square
%PAN_LETT_OBLIQUE_CONTACT    = 9  ' Oblique/Contact
%PAN_LETT_OBLIQUE_WEIGHTED   = 10 ' Oblique/Weighted
%PAN_LETT_OBLIQUE_BOXED      = 11 ' Oblique/Boxed
%PAN_LETT_OBLIQUE_FLATTENED  = 12 ' Oblique/Flattened
%PAN_LETT_OBLIQUE_ROUNDED    = 13 ' Oblique/Rounded
%PAN_LETT_OBLIQUE_OFF_CENTER = 14 ' Oblique/Off Center
%PAN_LETT_OBLIQUE_SQUARE     = 15 ' Oblique/Square

%PAN_MIDLINE_STANDARD_TRIMMED = 2  ' Standard/Trimmed
%PAN_MIDLINE_STANDARD_POINTED = 3  ' Standard/Pointed
%PAN_MIDLINE_STANDARD_SERIFED = 4  ' Standard/Serifed
%PAN_MIDLINE_HIGH_TRIMMED     = 5  ' High/Trimmed
%PAN_MIDLINE_HIGH_POINTED     = 6  ' High/Pointed
%PAN_MIDLINE_HIGH_SERIFED     = 7  ' High/Serifed
%PAN_MIDLINE_CONSTANT_TRIMMED = 8  ' Constant/Trimmed
%PAN_MIDLINE_CONSTANT_POINTED = 9  ' Constant/Pointed
%PAN_MIDLINE_CONSTANT_SERIFED = 10 ' Constant/Serifed
%PAN_MIDLINE_LOW_TRIMMED      = 11 ' Low/Trimmed
%PAN_MIDLINE_LOW_POINTED      = 12 ' Low/Pointed
%PAN_MIDLINE_LOW_SERIFED      = 13 ' Low/Serifed

%PAN_XHEIGHT_CONSTANT_SMALL   = 2  ' Constant/Small
%PAN_XHEIGHT_CONSTANT_STD     = 3  ' Constant/Standard
%PAN_XHEIGHT_CONSTANT_LARGE   = 4  ' Constant/Large
%PAN_XHEIGHT_DUCKING_SMALL    = 5  ' Ducking/Small
%PAN_XHEIGHT_DUCKING_STD      = 6  ' Ducking/Standard
%PAN_XHEIGHT_DUCKING_LARGE    = 7  ' Ducking/Large

' EnumFonts Masks
%RASTER_FONTTYPE   = &H1
%DEVICE_FONTTYPE   = &H2
%TRUETYPE_FONTTYPE = &H4

' palette entry flags
%PC_RESERVED   = &H1  ' palette index used for animation
%PC_EXPLICIT   = &H2  ' palette index is explicit to device
%PC_NOCOLLAPSE = &H4  ' do not match color to system palette

' Background Modes
%TRANSPARENT = 1
%OPAQUE      = 2
%BKMODE_LAST = 2

' Graphics Modes
%GM_COMPATIBLE = 1
%GM_ADVANCED   = 2
%GM_LAST       = 2

' PolyDraw and GetPath point types
%PT_CLOSEFIGURE = &H1
%PT_LINETO      = &H2
%PT_BEZIERTO    = &H4
%PT_MOVETO      = &H6

' Mapping Modes
%MM_TEXT         = 1
%MM_LOMETRIC     = 2
%MM_HIMETRIC     = 3
%MM_LOENGLISH    = 4
%MM_HIENGLISH    = 5
%MM_TWIPS        = 6
%MM_ISOTROPIC    = 7
%MM_ANISOTROPIC  = 8

' Min and Max Mapping Mode values
%MM_MIN            = %MM_TEXT
%MM_MAX            = %MM_ANISOTROPIC
%MM_MAX_FIXEDSCALE = %MM_TWIPS

' Coordinate Modes
%ABSOLUTE = 1
%RELATIVE = 2

' Stock Logical Objects
%WHITE_BRUSH         = 0
%LTGRAY_BRUSH        = 1
%GRAY_BRUSH          = 2
%DKGRAY_BRUSH        = 3
%BLACK_BRUSH         = 4
%NULL_BRUSH          = 5
%HOLLOW_BRUSH        = %NULL_BRUSH
%WHITE_PEN           = 6
%BLACK_PEN           = 7
%NULL_PEN            = 8
%OEM_FIXED_FONT      = 10
%ANSI_FIXED_FONT     = 11
%ANSI_VAR_FONT       = 12
%SYSTEM_FONT         = 13
%DEVICE_DEFAULT_FONT = 14
%DEFAULT_PALETTE     = 15
%SYSTEM_FIXED_FONT   = 16
%DEFAULT_GUI_FONT    = 17
%DC_BRUSH            = 18
%DC_PEN              = 19
%STOCK_LAST          = 19  ' depending on Windows version, may be 16, 17 or 19

%CLR_INVALID         = &HFFFFFFFF???  ' some Microsoft docs claim this is &HFFFF, but it's not

' Brush Styles
%BS_SOLID         = 0
%BS_NULL          = 1
%BS_HOLLOW        = %BS_NULL
%BS_HATCHED       = 2
%BS_PATTERN       = 3
%BS_INDEXED       = 4
%BS_DIBPATTERN    = 5
%BS_DIBPATTERNPT  = 6
%BS_PATTERN8X8    = 7
%BS_DIBPATTERN8X8 = 8
%BS_MONOPATTERN   = 9

' Hatch Styles
%HS_HORIZONTAL      = 0     ' -----
%HS_VERTICAL        = 1     ' |||||
%HS_FDIAGONAL       = 2     ' \\\\\
%HS_BDIAGONAL       = 3     ' -----
%HS_CROSS           = 4     ' +++++
%HS_DIAGCROSS       = 5     ' xxxxx
%HS_API_MAX         = 12

' Pen Styles
%PS_SOLID           = 0
%PS_DASH            = 1     ' -------
%PS_DOT             = 2     ' .......
%PS_DASHDOT         = 3     ' _._._._
%PS_DASHDOTDOT      = 4     ' _.._.._
%PS_NULL            = 5
%PS_INSIDEFRAME     = 6
%PS_USERSTYLE       = 7
%PS_ALTERNATE       = 8
%PS_STYLE_MASK      = &H0000000F
%PS_ENDCAP_ROUND    = &H00000000
%PS_ENDCAP_SQUARE   = &H00000100
%PS_ENDCAP_FLAT     = &H00000200
%PS_ENDCAP_MASK     = &H00000F00
%PS_JOIN_ROUND      = &H00000000
%PS_JOIN_BEVEL      = &H00001000
%PS_JOIN_MITER      = &H00002000
%PS_JOIN_MASK       = &H0000F000
%PS_COSMETIC        = &H00000000
%PS_GEOMETRIC       = &H00010000
%PS_TYPE_MASK       = &H000F0000

%AD_COUNTERCLOCKWISE = 1
%AD_CLOCKWISE        = 2

' WM_PRINT flags
%PRF_CHECKVISIBLE   = &H00000001
%PRF_NONCLIENT      = &H00000002
%PRF_CLIENT         = &H00000004
%PRF_ERASEBKGND     = &H00000008
%PRF_CHILDREN       = &H00000010
%PRF_OWNED          = &H00000020

' 3D border styles
%BDR_RAISEDOUTER = &H0001
%BDR_SUNKENOUTER = &H0002
%BDR_RAISEDINNER = &H0004
%BDR_SUNKENINNER = &H0008
%BDR_OUTER       = %BDR_RAISEDOUTER OR %BDR_SUNKENOUTER
%BDR_INNER       = %BDR_RAISEDINNER OR %BDR_SUNKENINNER
%BDR_RAISED      = %BDR_RAISEDOUTER OR %BDR_RAISEDINNER
%BDR_SUNKEN      = %BDR_SUNKENOUTER OR %BDR_SUNKENINNER

%EDGE_RAISED  = %BDR_RAISEDOUTER OR %BDR_RAISEDINNER
%EDGE_SUNKEN  = %BDR_SUNKENOUTER OR %BDR_SUNKENINNER
%EDGE_ETCHED  = %BDR_SUNKENOUTER OR %BDR_RAISEDINNER
%EDGE_BUMP    = %BDR_RAISEDOUTER OR %BDR_SUNKENINNER

' Border flags
%BF_LEFT        = &H0001
%BF_TOP         = &H0002
%BF_RIGHT       = &H0004
%BF_BOTTOM      = &H0008

%BF_TOPLEFT     = %BF_TOP OR %BF_LEFT
%BF_TOPRIGHT    = %BF_TOP OR %BF_RIGHT
%BF_BOTTOMLEFT  = %BF_BOTTOM OR %BF_LEFT
%BF_BOTTOMRIGHT = %BF_BOTTOM OR %BF_RIGHT
%BF_RECT        = %BF_LEFT OR %BF_TOP OR %BF_RIGHT OR %BF_BOTTOM

%BF_DIAGONAL    = &H0010

' For diagonal lines, the BF_RECT flags specify the end point of the
' vector bounded by the rectangle parameter.
%BF_DIAGONAL_ENDTOPRIGHT    = %BF_DIAGONAL OR %BF_TOP OR %BF_RIGHT
%BF_DIAGONAL_ENDTOPLEFT     = %BF_DIAGONAL OR %BF_TOP OR %BF_LEFT
%BF_DIAGONAL_ENDBOTTOMLEFT  = %BF_DIAGONAL OR %BF_BOTTOM OR %BF_LEFT
%BF_DIAGONAL_ENDBOTTOMRIGHT = %BF_DIAGONAL OR %BF_BOTTOM OR %BF_RIGHT

%BF_MIDDLE                  = &H00000800 ' Fill in the middle
%BF_SOFT                    = &H00001000 ' For softer buttons
%BF_ADJUST                  = &H00002000 ' Calculate the space left over
%BF_FLAT                    = &H00004000 ' For flat rather than 3D borders
%BF_MONO                    = &H00008000 ' For monochrome borders

' Device Parameters for GetDeviceCaps()
%DRIVERVERSION   = 0     ' Device driver version
%TECHNOLOGY      = 2     ' Device classification
%HORZSIZE        = 4     ' Horizontal size in millimeters
%VERTSIZE        = 6     ' Vertical size in millimeters
%HORZRES         = 8     ' Horizontal width in pixels
%VERTRES         = 10    ' Vertical width in pixels
%BITSPIXEL       = 12    ' Number of bits per pixel
%PLANES          = 14    ' Number of planes
%NUMBRUSHES      = 16    ' Number of brushes the device has
%NUMPENS         = 18    ' Number of pens the device has
%NUMMARKERS      = 20    ' Number of markers the device has
%NUMFONTS        = 22    ' Number of fonts the device has
%NUMCOLORS       = 24    ' Number of colors the device supports
%PDEVICESIZE     = 26    ' Size required for device descriptor
%CURVECAPS       = 28    ' Curve capabilities
%LINECAPS        = 30    ' Line capabilities
%POLYGONALCAPS   = 32    ' Polygonal capabilities
%TEXTCAPS        = 34    ' Text capabilities
%CLIPCAPS        = 36    ' Clipping capabilities
%RASTERCAPS      = 38    ' Bitblt capabilities
%ASPECTX         = 40    ' Length of the X leg
%ASPECTY         = 42    ' Length of the Y leg
%ASPECTXY        = 44    ' Length of the hypotenuse

%LOGPIXELSX      = 88    ' Logical pixels/inch in X
%LOGPIXELSY      = 90    ' Logical pixels/inch in Y

%SIZEPALETTE     = 104   ' Number of entries in physical palette
%NUMRESERVED     = 106   ' Number of reserved entries in palette
%COLORRES        = 108   ' Actual color resolution

' Printing related DeviceCaps. These replace the appropriate Escapes
%PHYSICALWIDTH   = 110   ' Physical Width in device units
%PHYSICALHEIGHT  = 111   ' Physical Height in device units
%PHYSICALOFFSETX = 112   ' Physical Printable Area x margin
%PHYSICALOFFSETY = 113   ' Physical Printable Area y margin
%SCALINGFACTORX  = 114   ' Scaling factor x
%SCALINGFACTORY  = 115   ' Scaling factor y
%VREFRESH        = 116   ' Current vertical refresh rate of the
%DESKTOPVERTRES  = 117   ' Horizontal width of entire desktop in pixels
%DESKTOPHORZRES  = 118   ' Vertical height of entire desktop in pixels
%BLTALIGNMENT    = 119   ' Preferred blt alignment
%SHADEBLENDCAPS  = 120   ' Shading and blending caps
%COLORMGMTCAPS   = 121   ' Color Management caps

' Device Capability Masks:

' Device Technologies
%DT_PLOTTER      = 0     ' Vector plotter
%DT_RASDISPLAY   = 1     ' Raster display
%DT_RASPRINTER   = 2     ' Raster printer
%DT_RASCAMERA    = 3     ' Raster camera
%DT_CHARSTREAM   = 4     ' Character-stream, PLP
%DT_METAFILE     = 5     ' Metafile, VDM
%DT_DISPFILE     = 6     ' Display-file

' Curve Capabilities
%CC_NONE         = 0     ' Curves not supported
%CC_CIRCLES      = 1     ' Can do circles
%CC_PIE          = 2     ' Can do pie wedges
%CC_CHORD        = 4     ' Can do chord arcs
%CC_ELLIPSES     = 8     ' Can do ellipese
%CC_WIDE         = 16    ' Can do wide lines
%CC_STYLED       = 32    ' Can do styled lines
%CC_WIDESTYLED   = 64    ' Can do wide styled lines
%CC_INTERIORS    = 128   ' Can do interiors
%CC_ROUNDRECT    = 256   '

' Line Capabilities
%LC_NONE         = 0     ' Lines not supported
%LC_POLYLINE     = 2     ' Can do polylines
%LC_MARKER       = 4     ' Can do markers
%LC_POLYMARKER   = 8     ' Can do polymarkers
%LC_WIDE         = 16    ' Can do wide lines
%LC_STYLED       = 32    ' Can do styled lines
%LC_WIDESTYLED   = 64    ' Can do wide styled lines
%LC_INTERIORS    = 128   ' Can do interiors

' Polygonal Capabilities
%PC_NONE         = 0     ' Polygonals not supported
%PC_POLYGON      = 1     ' Can do polygons
%PC_RECTANGLE    = 2     ' Can do rectangles
%PC_WINDPOLYGON  = 4     ' Can do winding polygons
%PC_TRAPEZOID    = 4     ' Can do trapezoids
%PC_SCANLINE     = 8     ' Can do scanlines
%PC_WIDE         = 16    ' Can do wide borders
%PC_STYLED       = 32    ' Can do styled borders
%PC_WIDESTYLED   = 64    ' Can do wide styled borders
%PC_INTERIORS    = 128   ' Can do interiors
%PC_POLYPOLYGON  = 256   ' Can do polypolygons
%PC_PATHS        = 512   ' Can do paths

' Polygonal Capabilities
%CP_NONE         = 0     ' No clipping of output
%CP_RECTANGLE    = 1     ' Output clipped to rects
%CP_REGION       = 2     ' obsolete

' Text Capabilities
%TC_OP_CHARACTER = &H00000001  ' Can do OutputPrecision   CHARACTER
%TC_OP_STROKE    = &H00000002  ' Can do OutputPrecision   STROKE
%TC_CP_STROKE    = &H00000004  ' Can do ClipPrecision     STROKE
%TC_CR_90        = &H00000008  ' Can do CharRotAbility    90
%TC_CR_ANY       = &H00000010  ' Can do CharRotAbility    ANY
%TC_SF_X_YINDEP  = &H00000020  ' Can do ScaleFreedom      X_YINDEPENDENT
%TC_SA_DOUBLE    = &H00000040  ' Can do ScaleAbility      DOUBLE
%TC_SA_INTEGER   = &H00000080  ' Can do ScaleAbility      INTEGER
%TC_SA_CONTIN    = &H00000100  ' Can do ScaleAbility      CONTINUOUS
%TC_EA_DOUBLE    = &H00000200  ' Can do EmboldenAbility   DOUBLE
%TC_IA_ABLE      = &H00000400  ' Can do ItalisizeAbility  ABLE
%TC_UA_ABLE      = &H00000800  ' Can do UnderlineAbility  ABLE
%TC_SO_ABLE      = &H00001000  ' Can do StrikeOutAbility  ABLE
%TC_RA_ABLE      = &H00002000  ' Can do RasterFontAble    ABLE
%TC_VA_ABLE      = &H00004000  ' Can do VectorFontAble    ABLE
%TC_RESERVED     = &H00008000
%TC_SCROLLBLT    = &H00010000  ' do text scroll with blt

' Raster Capabilities
%RC_NONE          = &H00000000
%RC_BITBLT        = &H00000001  ' Can do standard BLT.
%RC_BANDING       = &H00000002  ' Device requires banding support
%RC_SCALING       = &H00000004  ' Device requires scaling support
%RC_BITMAP64      = &H00000008  ' Device can support >64K bitmap
%RC_GDI20_OUTPUT  = &H00000010  ' has 2.0 output calls
%RC_GDI20_STATE   = &H00000020
%RC_SAVEBITMAP    = &H00000040
%RC_DI_BITMAP     = &H00000080  ' supports DIB to memory
%RC_PALETTE       = &H00000100  ' supports a palette
%RC_DIBTODEV      = &H00000200  ' supports DIBitsToDevice
%RC_BIGFONT       = &H00000400  ' supports >64K fonts
%RC_STRETCHBLT    = &H00000800  ' supports StretchBlt
%RC_FLOODFILL     = &H00001000  ' supports FloodFill
%RC_STRETCHDIB    = &H00002000  ' supports StretchDIBits
%RC_OP_DX_OUTPUT  = &H00004000
%RC_DEVBITS       = &H00008000

%SB_NONE           = &H00000000
%SB_CONST_ALPHA    = &H00000001
%SB_PIXEL_ALPHA    = &H00000002
%SB_PREMULT_ALPHA  = &H00000004

%SB_GRAD_RECT      = &H00000010
%SB_GRAD_TRI       = &H00000020

' Color Management caps
%CM_NONE           = &H00000000
%CM_DEVICE_ICM     = &H00000001
%CM_GAMMA_RAMP     = &H00000002
%CM_CMYK_COLOR     = &H00000004

' DIB color table identifiers
%DIB_RGB_COLORS       = 0 ' color table in RGBs
%DIB_PAL_COLORS       = 1 ' color table in palette indices
%DIB_PAL_INDICES      = 2 ' No color table indices into surf palette
%DIB_PAL_PHYSINDICES  = 2 ' No color table indices into surf palette
%DIB_PAL_LOGINDICES   = 4 ' No color table indices into DC palette

' constants for Get/SetSystemPaletteUse()
%SYSPAL_ERROR       = 0
%SYSPAL_STATIC      = 1
%SYSPAL_NOSTATIC    = 2
%SYSPAL_NOSTATIC256 = 3

' constants for CreateDIBitmap
%CBM_CREATEDIB  = &H2     ' create DIB bitmap
%CBM_INIT       = &H4     ' initialize bitmap

' ExtFloodFill style flags
%FLOODFILLBORDER  = 0
%FLOODFILLSURFACE = 1

' size of a device name string
%CCHDEVICENAME = 32

' size of a form name string
%CCHFORMNAME = 32

' current version of specification
%DM_SPECVERSION = &H0401

' field selection bits
%DM_ORIENTATION      = &H00000001
%DM_PAPERSIZE        = &H00000002
%DM_PAPERLENGTH      = &H00000004
%DM_PAPERWIDTH       = &H00000008
%DM_SCALE            = &H00000010
%DM_POSITION         = &H00000020
%DM_COPIES           = &H00000100
%DM_DEFAULTSOURCE    = &H00000200
%DM_PRINTQUALITY     = &H00000400
%DM_COLOR            = &H00000800
%DM_DUPLEX           = &H00001000
%DM_YRESOLUTION      = &H00002000
%DM_TTOPTION         = &H00004000
%DM_COLLATE          = &H00008000
%DM_FORMNAME         = &H00010000
%DM_LOGPIXELS        = &H00020000
%DM_BITSPERPEL       = &H00040000
%DM_PELSWIDTH        = &H00080000
%DM_PELSHEIGHT       = &H00100000
%DM_DISPLAYFLAGS     = &H00200000
%DM_DISPLAYFREQUENCY = &H00400000
%DM_ICMMETHOD        = &H00800000
%DM_ICMINTENT        = &H01000000
%DM_MEDIATYPE        = &H02000000
%DM_DITHERTYPE       = &H04000000
%DM_PANNINGWIDTH     = &H08000000
%DM_PANNINGHEIGHT    = &H10000000
%DM_DISPLAYFIXEDOUTPUT = &H20000000

' orientation selections
%DMORIENT_PORTRAIT  = 1
%DMORIENT_LANDSCAPE = 2

' paper selections
%DMPAPER_LETTER            = 1
%DMPAPER_FIRST             = %DMPAPER_LETTER
' Letter 8 1/2 x 11 in
%DMPAPER_LETTERSMALL         = 2    ' Letter Small 8 1/2 x 11 in
%DMPAPER_TABLOID             = 3    ' Tabloid 11 x 17 in
%DMPAPER_LEDGER              = 4    ' Ledger 17 x 11 in
%DMPAPER_LEGAL               = 5    ' Legal 8 1/2 x 14 in
%DMPAPER_STATEMENT           = 6    ' Statement 5 1/2 x 8 1/2 in
%DMPAPER_EXECUTIVE           = 7    ' Executive 7 1/4 x 10 1/2 in
%DMPAPER_A3                  = 8    ' A3 297 x 420 mm
%DMPAPER_A4                  = 9    ' A4 210 x 297 mm
%DMPAPER_A4SMALL             = 10   ' A4 Small 210 x 297 mm
%DMPAPER_A5                  = 11   ' A5 148 x 210 mm
%DMPAPER_B4                  = 12   ' B4 250 x 354
%DMPAPER_B5                  = 13   ' B5 182 x 257 mm
%DMPAPER_FOLIO               = 14   ' Folio 8 1/2 x 13 in
%DMPAPER_QUARTO              = 15   ' Quarto 215 x 275 mm
%DMPAPER_10X14               = 16   ' 1&H14 in
%DMPAPER_11X17               = 17   ' 11x17 in
%DMPAPER_NOTE                = 18   ' Note 8 1/2 x 11 in
%DMPAPER_ENV_9               = 19   ' Envelope #9 3 7/8 x 8 7/8
%DMPAPER_ENV_10              = 20   ' Envelope #10 4 1/8 x 9 1/2
%DMPAPER_ENV_11              = 21   ' Envelope #11 4 1/2 x 10 3/8
%DMPAPER_ENV_12              = 22   ' Envelope #12 4 \276 x 11
%DMPAPER_ENV_14              = 23   ' Envelope #14 5 x 11 1/2
%DMPAPER_CSHEET              = 24   ' C size sheet
%DMPAPER_DSHEET              = 25   ' D size sheet
%DMPAPER_ESHEET              = 26   ' E size sheet
%DMPAPER_ENV_DL              = 27   ' Envelope DL 110 x 220mm
%DMPAPER_ENV_C5              = 28   ' Envelope C5 162 x 229 mm
%DMPAPER_ENV_C3              = 29   ' Envelope C3  324 x 458 mm
%DMPAPER_ENV_C4              = 30   ' Envelope C4  229 x 324 mm
%DMPAPER_ENV_C6              = 31   ' Envelope C6  114 x 162 mm
%DMPAPER_ENV_C65             = 32   ' Envelope C65 114 x 229 mm
%DMPAPER_ENV_B4              = 33   ' Envelope B4  250 x 353 mm
%DMPAPER_ENV_B5              = 34   ' Envelope B5  176 x 250 mm
%DMPAPER_ENV_B6              = 35   ' Envelope B6  176 x 125 mm
%DMPAPER_ENV_ITALY           = 36   ' Envelope 110 x 230 mm
%DMPAPER_ENV_MONARCH         = 37   ' Envelope Monarch 3.875 x 7.5 in
%DMPAPER_ENV_PERSONAL        = 38   ' 6 3/4 Envelope 3 5/8 x 6 1/2 in
%DMPAPER_FANFOLD_US          = 39   ' US Std Fanfold 14 7/8 x 11 in
%DMPAPER_FANFOLD_STD_GERMAN  = 40   ' German Std Fanfold 8 1/2 x 12 in
%DMPAPER_FANFOLD_LGL_GERMAN  = 41   ' German Legal Fanfold 8 1/2 x 13 in
%DMPAPER_ISO_B4              = 42   ' B4 (ISO) 250 x 353 mm
%DMPAPER_JAPANESE_POSTCARD   = 43   ' Japanese Postcard 100 x 148 mm
%DMPAPER_9X11                = 44   ' 9 x 11 in
%DMPAPER_10X11               = 45   ' 10 x 11 in
%DMPAPER_15X11               = 46   ' 15 x 11 in
%DMPAPER_ENV_INVITE          = 47   ' Envelope Invite 220 x 220 mm
%DMPAPER_RESERVED_48         = 48   ' RESERVED--DO NOT USE
%DMPAPER_RESERVED_49         = 49   ' RESERVED--DO NOT USE
%DMPAPER_LETTER_EXTRA        = 50   ' Letter Extra 9 \275 x 12 in
%DMPAPER_LEGAL_EXTRA         = 51   ' Legal Extra 9 \275 x 15 in
%DMPAPER_TABLOID_EXTRA       = 52   ' Tabloid Extra 11.69 x 18 in
%DMPAPER_A4_EXTRA            = 53   ' A4 Extra 9.27 x 12.69 in
%DMPAPER_LETTER_TRANSVERSE   = 54   ' Letter Transverse 8 \275 x 11 in
%DMPAPER_A4_TRANSVERSE       = 55   ' A4 Transverse 210 x 297 mm
%DMPAPER_LETTER_EXTRA_TRANSVERSE = 56 ' Letter Extra Transverse 9\275 x 12 in
%DMPAPER_A_PLUS              = 57   ' SuperA/SuperA/A4 227 x 356 mm
%DMPAPER_B_PLUS              = 58   ' SuperB/SuperB/A3 305 x 487 mm
%DMPAPER_LETTER_PLUS         = 59   ' Letter Plus 8.5 x 12.69 in
%DMPAPER_A4_PLUS             = 60   ' A4 Plus 210 x 330 mm
%DMPAPER_A5_TRANSVERSE       = 61   ' A5 Transverse 148 x 210 mm
%DMPAPER_B5_TRANSVERSE       = 62   ' B5 (JIS) Transverse 182 x 257 mm
%DMPAPER_A3_EXTRA            = 63   ' A3 Extra 322 x 445 mm
%DMPAPER_A5_EXTRA            = 64   ' A5 Extra 174 x 235 mm
%DMPAPER_B5_EXTRA            = 65   ' B5 (ISO) Extra 201 x 276 mm
%DMPAPER_A2                  = 66   ' A2 420 x 594 mm
%DMPAPER_A3_TRANSVERSE       = 67   ' A3 Transverse 297 x 420 mm
%DMPAPER_A3_EXTRA_TRANSVERSE = 68   ' A3 Extra Transverse 322 x 445 mm
%DMPAPER_DBL_JAPANESE_POSTCARD = 69 ' Japanese Double Postcard 200 x 148 mm
%DMPAPER_A6                  = 70  ' A6 105 x 148 mm
%DMPAPER_JENV_KAKU2          = 71  ' Japanese Envelope Kaku #2
%DMPAPER_JENV_KAKU3          = 72  ' Japanese Envelope Kaku #3
%DMPAPER_JENV_CHOU3          = 73  ' Japanese Envelope Chou #3
%DMPAPER_JENV_CHOU4          = 74  ' Japanese Envelope Chou #4
%DMPAPER_LETTER_ROTATED      = 75  ' Letter Rotated 11 x 8 1/2 11 in
%DMPAPER_A3_ROTATED          = 76  ' A3 Rotated 420 x 297 mm
%DMPAPER_A4_ROTATED          = 77  ' A4 Rotated 297 x 210 mm
%DMPAPER_A5_ROTATED          = 78  ' A5 Rotated 210 x 148 mm
%DMPAPER_B4_JIS_ROTATED      = 79  ' B4 (JIS) Rotated 364 x 257 mm
%DMPAPER_B5_JIS_ROTATED      = 80  ' B5 (JIS) Rotated 257 x 182 mm
%DMPAPER_JAPANESE_POSTCARD_ROTATED = 81 ' Japanese Postcard Rotated 148 x 100 mm
%DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED = 82 ' Double Japanese Postcard Rotated 148 x 200 mm
%DMPAPER_A6_ROTATED          = 83  ' A6 Rotated 148 x 105 mm
%DMPAPER_JENV_KAKU2_ROTATED  = 84  ' Japanese Envelope Kaku #2 Rotated
%DMPAPER_JENV_KAKU3_ROTATED  = 85  ' Japanese Envelope Kaku #3 Rotated
%DMPAPER_JENV_CHOU3_ROTATED  = 86  ' Japanese Envelope Chou #3 Rotated
%DMPAPER_JENV_CHOU4_ROTATED  = 87  ' Japanese Envelope Chou #4 Rotated
%DMPAPER_B6_JIS              = 88  ' B6 (JIS) 128 x 182 mm
%DMPAPER_B6_JIS_ROTATED      = 89  ' B6 (JIS) Rotated 182 x 128 mm
%DMPAPER_12X11               = 90  ' 12 x 11 in
%DMPAPER_JENV_YOU4           = 91  ' Japanese Envelope You #4
%DMPAPER_JENV_YOU4_ROTATED   = 92  ' Japanese Envelope You #4 Rotated
%DMPAPER_P16K                = 93  ' PRC 16K 146 x 215 mm
%DMPAPER_P32K                = 94  ' PRC 32K 97 x 151 mm
%DMPAPER_P32KBIG             = 95  ' PRC 32K(Big) 97 x 151 mm
%DMPAPER_PENV_1              = 96  ' PRC Envelope #1 102 x 165 mm
%DMPAPER_PENV_2              = 97  ' PRC Envelope #2 102 x 176 mm
%DMPAPER_PENV_3              = 98  ' PRC Envelope #3 125 x 176 mm
%DMPAPER_PENV_4              = 99  ' PRC Envelope #4 110 x 208 mm
%DMPAPER_PENV_5              = 100 ' PRC Envelope #5 110 x 220 mm
%DMPAPER_PENV_6              = 101 ' PRC Envelope #6 120 x 230 mm
%DMPAPER_PENV_7              = 102 ' PRC Envelope #7 160 x 230 mm
%DMPAPER_PENV_8              = 103 ' PRC Envelope #8 120 x 309 mm
%DMPAPER_PENV_9              = 104 ' PRC Envelope #9 229 x 324 mm
%DMPAPER_PENV_10             = 105 ' PRC Envelope #10 324 x 458 mm
%DMPAPER_P16K_ROTATED        = 106 ' PRC 16K Rotated
%DMPAPER_P32K_ROTATED        = 107 ' PRC 32K Rotated
%DMPAPER_P32KBIG_ROTATED     = 108 ' PRC 32K(Big) Rotated
%DMPAPER_PENV_1_ROTATED      = 109 ' PRC Envelope #1 Rotated 165 x 102 mm
%DMPAPER_PENV_2_ROTATED      = 110 ' PRC Envelope #2 Rotated 176 x 102 mm
%DMPAPER_PENV_3_ROTATED      = 111 ' PRC Envelope #3 Rotated 176 x 125 mm
%DMPAPER_PENV_4_ROTATED      = 112 ' PRC Envelope #4 Rotated 208 x 110 mm
%DMPAPER_PENV_5_ROTATED      = 113 ' PRC Envelope #5 Rotated 220 x 110 mm
%DMPAPER_PENV_6_ROTATED      = 114 ' PRC Envelope #6 Rotated 230 x 120 mm
%DMPAPER_PENV_7_ROTATED      = 115 ' PRC Envelope #7 Rotated 230 x 160 mm
%DMPAPER_PENV_8_ROTATED      = 116 ' PRC Envelope #8 Rotated 309 x 120 mm
%DMPAPER_PENV_9_ROTATED      = 117 ' PRC Envelope #9 Rotated 324 x 229 mm
%DMPAPER_PENV_10_ROTATED     = 118 ' PRC Envelope #10 Rotated 458 x 324 mm
%DMPAPER_LAST = %DMPAPER_PENV_10_ROTATED
%DMPAPER_USER                = 256

' bin selections
%DMBIN_FIRST         = %DMBIN_UPPER
%DMBIN_ONLYONE       = 1
%DMBIN_LAST          = %DMBIN_FORMSOURCE

%DMBIN_USER                  = 256  ' device specific bins start here

' print qualities
%DMRES_DRAFT                 = -1
%DMRES_LOW                   = -2
%DMRES_MEDIUM                = -3
%DMRES_HIGH                  = -4

' TrueType options
%DMTT_BITMAP           = 1  ' print TT fonts as graphics
%DMTT_DOWNLOAD         = 2  ' download TT fonts as soft fonts
%DMTT_SUBDEV           = 3  ' substitute device fonts for TT fonts
%DMTT_DOWNLOAD_OUTLINE = 4  ' download TT fonts as outline soft fonts

' DEVMODE dmDisplayFlags flags

'%DM_GRAYSCALE           = &H1   ' no longer valid
%DM_INTERLACED           = &H2
%DMDISPLAYFLAGS_TEXTMODE = &H4

' GetRegionData/ExtCreateRegion

%RDH_RECTANGLES              = 1

' GetGlyphOutline constants
%GGO_METRICS      = 0
%GGO_BITMAP       = 1
%GGO_NATIVE       = 2
%GGO_BEZIER       = 3
%GGO_GRAY2_BITMAP = 4
%GGO_GRAY4_BITMAP = 5
%GGO_GRAY8_BITMAP = 6
%GGO_GLYPH_INDEX  = &H0080
%GGO_UNHINTED     = &H0100

%TT_POLYGON_TYPE = 24

%TT_PRIM_LINE    = 1
%TT_PRIM_QSPLINE = 2
%TT_PRIM_CSPLINE = 3

' bits defined in wFlags of RASTERIZER_STATUS
%TT_AVAILABLE = &H1
%TT_ENABLED   = &H2

' mode selections for the device mode function
%DM_UPDATE       = 1
%DM_COPY         = 2
%DM_PROMPT       = 4
%DM_MODIFY       = 8

%DM_IN_BUFFER    = %DM_MODIFY
%DM_IN_PROMPT    = %DM_PROMPT
%DM_OUT_BUFFER   = %DM_COPY
%DM_OUT_DEFAULT  = %DM_UPDATE

' device capabilities indices
%DC_FIELDS           = 1
%DC_PAPERS           = 2
%DC_PAPERSIZE        = 3
%DC_MINEXTENT        = 4
%DC_MAXEXTENT        = 5
%DC_BINS             = 6
%DC_DUPLEX           = 7
%DC_SIZE             = 8
%DC_EXTRA            = 9
%DC_VERSION          = 10
%DC_DRIVER           = 11
%DC_BINNAMES         = 12
%DC_ENUMRESOLUTIONS  = 13
%DC_FILEDEPENDENCIES = 14
%DC_TRUETYPE         = 15
%DC_PAPERNAMES       = 16
%DC_ORIENTATION      = 17
%DC_COPIES           = 18
%DC_BINADJUST         = 19
%DC_EMF_COMPLIANT     = 20
%DC_DATATYPE_PRODUCED = 21
%DC_COLLATE           = 22
%DC_MANUFACTURER      = 23
%DC_MODEL             = 24
%DC_PERSONALITY       = 25
%DC_PRINTRATE         = 26
%DC_PRINTRATEUNIT     = 27
%DC_PRINTERMEM        = 28
%DC_MEDIAREADY        = 29
%DC_STAPLE            = 30
%DC_PRINTRATEPPM      = 31
%DC_COLORDEVICE       = 32
%DC_NUP               = 33
%DC_MEDIATYPENAMES    = 34
%DC_MEDIATYPES        = 35

' bit fields of the return value (DWORD) for DC_TRUETYPE
%DCTT_BITMAP           = &H00000001
%DCTT_DOWNLOAD         = &H00000002
%DCTT_SUBDEV           = &H00000004
%DCTT_DOWNLOAD_OUTLINE = &H00000008

' return values for DC_BINADJUST
%DCBA_FACEUPNONE     = &H0000
%DCBA_FACEUPCENTER   = &H0001
%DCBA_FACEUPLEFT     = &H0002
%DCBA_FACEUPRIGHT    = &H0003
%DCBA_FACEDOWNNONE   = &H0100
%DCBA_FACEDOWNCENTER = &H0101
%DCBA_FACEDOWNLEFT   = &H0102
%DCBA_FACEDOWNRIGHT  = &H0103

' Flags value for COLORADJUSTMENT
%CA_NEGATIVE   = &H1
%CA_LOG_FILTER = &H2

' IlluminantIndex values
%ILLUMINANT_DEVICE_DEFAULT = 0
%ILLUMINANT_A              = 1
%ILLUMINANT_B              = 2
%ILLUMINANT_C              = 3
%ILLUMINANT_D50            = 4
%ILLUMINANT_D55            = 5
%ILLUMINANT_D65            = 6
%ILLUMINANT_D75            = 7
%ILLUMINANT_F2             = 8
%ILLUMINANT_MAX_INDEX      = %ILLUMINANT_F2

%ILLUMINANT_TUNGSTEN       = %ILLUMINANT_A
%ILLUMINANT_DAYLIGHT       = %ILLUMINANT_C
%ILLUMINANT_FLUORESCENT    = %ILLUMINANT_F2
%ILLUMINANT_NTSC           = %ILLUMINANT_C

' Min and max for RedGamma, GreenGamma, BlueGamma
%RGB_GAMMA_MIN = 2500
%RGB_GAMMA_MAX = 65000

' Min and max for ReferenceBlack and ReferenceWhite
%REFERENCE_WHITE_MIN = 6000
%REFERENCE_WHITE_MAX = 10000
%REFERENCE_BLACK_MIN = 0
%REFERENCE_BLACK_MAX = 4000

' Min and max for Contrast, Brightness, Colorfulness, RedGreenTint
%COLOR_ADJ_MIN = -100
%COLOR_ADJ_MAX = 100

%FONTMAPPER_MAX = 10

%ENHMETA_SIGNATURE     = &H464D4520

' Stock object flag used in the object handle
' index in the enhanced metafile records.
' E.g. The object xHandle index (%META_STOCK_OBJECT OR %BLACK_BRUSH)
' represents the stock object BLACK_BRUSH.

%ENHMETA_STOCK_OBJECT  = &H80000000???

' Enhanced metafile record types.

%EMR_HEADER               = 1
%EMR_POLYBEZIER           = 2
%EMR_POLYGON              = 3
%EMR_POLYLINE             = 4
%EMR_POLYBEZIERTO         = 5
%EMR_POLYLINETO           = 6
%EMR_POLYPOLYLINE         = 7
%EMR_POLYPOLYGON          = 8
%EMR_SETWINDOWEXTEX       = 9
%EMR_SETWINDOWORGEX       = 10
%EMR_SETVIEWPORTEXTEX     = 11
%EMR_SETVIEWPORTORGEX     = 12
%EMR_SETBRUSHORGEX        = 13
%EMR_EOF                  = 14
%EMR_SETPIXELV            = 15
%EMR_SETMAPPERFLAGS       = 16
%EMR_SETMAPMODE           = 17
%EMR_SETBKMODE            = 18
%EMR_SETPOLYFILLMODE      = 19
%EMR_SETROP2              = 20
%EMR_SETSTRETCHBLTMODE    = 21
%EMR_SETTEXTALIGN         = 22
%EMR_SETCOLORADJUSTMENT   = 23
%EMR_SETTEXTCOLOR         = 24
%EMR_SETBKCOLOR           = 25
%EMR_OFFSETCLIPRGN        = 26
%EMR_MOVETOEX             = 27
%EMR_SETMETARGN           = 28
%EMR_EXCLUDECLIPRECT      = 29
%EMR_INTERSECTCLIPRECT    = 30
%EMR_SCALEVIEWPORTEXTEX   = 31
%EMR_SCALEWINDOWEXTEX     = 32
%EMR_SAVEDC               = 33
%EMR_RESTOREDC            = 34
%EMR_SETWORLDTRANSFORM    = 35
%EMR_MODIFYWORLDTRANSFORM = 36
%EMR_SELECTOBJECT         = 37
%EMR_CREATEPEN            = 38
%EMR_CREATEBRUSHINDIRECT  = 39
%EMR_DELETEOBJECT         = 40
%EMR_ANGLEARC             = 41
%EMR_ELLIPSE              = 42
%EMR_RECTANGLE            = 43
%EMR_ROUNDRECT            = 44
%EMR_ARC                  = 45
%EMR_CHORD                = 46
%EMR_PIE                  = 47
%EMR_SELECTPALETTE        = 48
%EMR_CREATEPALETTE        = 49
%EMR_SETPALETTEENTRIES    = 50
%EMR_RESIZEPALETTE        = 51
%EMR_REALIZEPALETTE       = 52
%EMR_EXTFLOODFILL         = 53
%EMR_LINETO               = 54
%EMR_ARCTO                = 55
%EMR_POLYDRAW             = 56
%EMR_SETARCDIRECTION      = 57
%EMR_SETMITERLIMIT        = 58
%EMR_BEGINPATH            = 59
%EMR_ENDPATH              = 60
%EMR_CLOSEFIGURE          = 61
%EMR_FILLPATH             = 62
%EMR_STROKEANDFILLPATH    = 63
%EMR_STROKEPATH           = 64
%EMR_FLATTENPATH          = 65
%EMR_WIDENPATH            = 66
%EMR_SELECTCLIPPATH       = 67
%EMR_ABORTPATH            = 68

%EMR_GDICOMMENT           = 70
%EMR_FILLRGN              = 71
%EMR_FRAMERGN             = 72
%EMR_INVERTRGN            = 73
%EMR_PAINTRGN             = 74
%EMR_EXTSELECTCLIPRGN     = 75
%EMR_BITBLT               = 76
%EMR_STRETCHBLT           = 77
%EMR_MASKBLT              = 78
%EMR_PLGBLT               = 79
%EMR_SETDIBITSTODEVICE    = 80
%EMR_STRETCHDIBITS        = 81
%EMR_EXTCREATEFONTINDIRECTW = 82
%EMR_EXTTEXTOUTA          = 83
%EMR_EXTTEXTOUTW          = 84
%EMR_POLYBEZIER16         = 85
%EMR_POLYGON16            = 86
%EMR_POLYLINE16           = 87
%EMR_POLYBEZIERTO16       = 88
%EMR_POLYLINETO16         = 89
%EMR_POLYPOLYLINE16       = 90
%EMR_POLYPOLYGON16        = 91
%EMR_POLYDRAW16           = 92
%EMR_CREATEMONOBRUSH      = 93
%EMR_CREATEDIBPATTERNBRUSHPT = 94
%EMR_EXTCREATEPEN         = 95
%EMR_POLYTEXTOUTA         = 96
%EMR_POLYTEXTOUTW         = 97
%EMR_SETICMMODE              = 98
%EMR_CREATECOLORSPACE        = 99
%EMR_SETCOLORSPACE           = 100
%EMR_DELETECOLORSPACE        = 101
%EMR_GLSRECORD               = 102
%EMR_GLSBOUNDEDRECORD        = 103
%EMR_PIXELFORMAT             = 104
%EMR_DRAWESCAPE              = 105
%EMR_EXTESCAPE               = 106
%EMR_STARTDOC                = 107
%EMR_SMALLTEXTOUT            = 108
%EMR_FORCEUFIMAPPING         = 109
%EMR_NAMEDESCAPE             = 110
%EMR_COLORCORRECTPALETTE     = 111
%EMR_SETICMPROFILEA          = 112
%EMR_SETICMPROFILEW          = 113
%EMR_ALPHABLEND              = 114
%EMR_ALPHADIBBLEND           = 115
%EMR_TRANSPARENTBLT          = 116
%EMR_TRANSPARENTDIB          = 117
%EMR_GRADIENTFILL            = 118
%EMR_SETLINKEDUFIS           = 119
%EMR_SETTEXTJUSTIFICATION    = 120
%EMR_COLORMATCHTOTARGETW     = 121
%EMR_CREATECOLORSPACEW       = 122
%EMR_MIN                     = 1
%EMR_MAX                     = 122 ' varies by Windows version

' StretchBlt() Modes
%STRETCH_ANDSCANS    = 1
%STRETCH_ORSCANS     = 2
%STRETCH_DELETESCANS = 3
%STRETCH_HALFTONE    = 4

%TCI_SRCCHARSET  = 1
%TCI_SRCCODEPAGE = 2
%TCI_SRCFONTSIG  = 3

%FS_LATIN1      = &H00000001
%FS_LATIN2      = &H00000002
%FS_CYRILLIC    = &H00000004
%FS_GREEK       = &H00000008
%FS_TURKISH     = &H00000010
%FS_HEBREW      = &H00000020
%FS_ARABIC      = &H00000040
%FS_BALTIC      = &H00000080
%FS_THAI        = &H00010000
%FS_JISJAPAN    = &H00020000
%FS_CHINESESIMP = &H00040000
%FS_WANSUNG     = &H00080000
%FS_CHINESETRAD = &H00100000
%FS_JOHAB       = &H00200000
%FS_SYMBOL      = &H80000000???

' ICM methods
%DMICMMETHOD_NONE   = 1      ' ICM disabled
%DMICMMETHOD_SYSTEM = 2      ' ICM handled by system
%DMICMMETHOD_DRIVER = 3      ' ICM handled by driver
%DMICMMETHOD_DEVICE = 4      ' ICM handled by device
%DMICMMETHOD_USER   = 256    ' Device-specific methods start here

' ICM Intents
%DMICM_SATURATE     = 1      ' Maximize color saturation
%DMICM_CONTRAST     = 2      ' Maximize color contrast
%DMICM_COLORMETRIC  = 3      ' Use specific color metric
%DMICM_ABS_COLORIMETRIC = 4  ' Use specific color metric
%DMICM_USER         = 256    ' Device-specific intents start here

' Media types
%DMMEDIA_STANDARD     = 1      ' Standard paper
%DMMEDIA_TRANSPARENCY = 2      ' Transparency
%DMMEDIA_GLOSSY       = 3      ' Glossy paper

%DMMEDIA_USER         = 256    ' Device-specific media start here

' Dither types
%DMDITHER_NONE      = 1      ' No dithering
%DMDITHER_COARSE    = 2      ' Dither with a coarse brush
%DMDITHER_FINE      = 3      ' Dither with a fine brush
%DMDITHER_LINEART   = 4      ' LineArt dithering
%DMDITHER_ERRORDIFFUSION = 5   ' LineArt dithering
%DMDITHER_RESERVED6      = 6   ' LineArt dithering
%DMDITHER_RESERVED7      = 7   ' LineArt dithering
%DMDITHER_RESERVED8      = 8   ' LineArt dithering
%DMDITHER_RESERVED9      = 9   ' LineArt dithering
%DMDITHER_GRAYSCALE      = 10  ' Device does grayscaling
%DMDITHER_USER      = 256    ' Device-specific dithers start here

%GCP_DBCS            = &H00000001
%GCP_REORDER         = &H00000002
%GCP_USEKERNING      = &H00000008
%GCP_GLYPHSHAPE      = &H00000010
%GCP_LIGATE          = &H00000020
%GCP_DIACRITIC       = &H00000100
%GCP_KASHIDA         = &H00000400
%GCP_ERROR           = &H00008000
%FLI_MASK            = &H0000103B
%GCP_JUSTIFY         = &H00010000
%GCP_NODIACRITICS    = &H00020000
%FLI_GLYPHS          = &H00040000
%GCP_CLASSIN         = &H00080000
%GCP_MAXEXTENT       = &H00100000
%GCP_JUSTIFYIN       = &H00200000
%GCP_DISPLAYZWG      = &H00400000
%GCP_SYMSWAPOFF      = &H00800000
%GCP_NUMERICOVERRIDE = &H01000000
%GCP_NEUTRALOVERRIDE = &H02000000
%GCP_NUMERICSLATIN   = &H04000000
%GCP_NUMERICSLOCAL   = &H08000000
%GCPCLASS_LATIN                   = 1
%GCPCLASS_HEBREW                  = 2
%GCPCLASS_ARABIC                  = 2
%GCPCLASS_NEUTRAL                 = 3
%GCPCLASS_LOCALNUMBER             = 4
%GCPCLASS_LATINNUMBER             = 5
%GCPCLASS_LATINNUMERICTERMINATOR  = 6
%GCPCLASS_LATINNUMERICSEPARATOR   = 7
%GCPCLASS_NUMERICSEPARATOR        = 8
%GCPCLASS_PREBOUNDLTR         = &H80?
%GCPCLASS_PREBOUNDRTL         = &H40
%GCPCLASS_POSTBOUNDLTR        = &H20
%GCPCLASS_POSTBOUNDRTL        = &H10

%GCPGLYPH_LINKBEFORE          = &H8000??
%GCPGLYPH_LINKAFTER           = &H4000

' return values for DC_BINADJUST
%DCBA_FACEUPNONE     = &H0
%DCBA_FACEUPCENTER   = &H1
%DCBA_FACEUPLEFT     = &H2
%DCBA_FACEUPRIGHT    = &H3
%DCBA_FACEDOWNNONE   = &H100
%DCBA_FACEDOWNCENTER = &H101
%DCBA_FACEDOWNLEFT   = &H102
%DCBA_FACEDOWNRIGHT  = &H103

%ICM_OFF   = 1
%ICM_ON    = 2
%ICM_QUERY = 3
%ICM_DONE_OUTSIDEDC = 4

%ASFW_ANY = &HFFFFFFFF??? ' BITS???(-1)
%LSFW_LOCK   = 1
%LSFW_UNLOCK = 2

#IF NOT %DEF(%NOSHOWWINDOW) '--------------------------------------------------

' Old ShowWindow() Commands
%HIDE_WINDOW         = 0
%SHOW_OPENWINDOW     = 1
%SHOW_ICONWINDOW     = 2
%SHOW_FULLSCREEN     = 3
%SHOW_OPENNOACTIVATE = 4

' Identifiers for the WM_SHOWWINDOW message
%SW_PARENTCLOSING  = 1
%SW_OTHERZOOM      = 2
%SW_PARENTOPENING  = 3
%SW_OTHERUNZOOM    = 4

#ENDIF ' #IF NOT %DEF(%NOSHOWWINDOW) ------------------------------------------

' AnimateWindow() Commands
%AW_HOR_POSITIVE = &H00000001
%AW_HOR_NEGATIVE = &H00000002
%AW_VER_POSITIVE = &H00000004
%AW_VER_NEGATIVE = &H00000008
%AW_CENTER       = &H00000010
%AW_HIDE         = &H00010000
%AW_ACTIVATE     = &H00020000
%AW_SLIDE        = &H00040000
%AW_BLEND        = &H00080000

' WM_KEYUP/DOWN/CHAR HIWORD(lParam) flags
%KF_EXTENDED = &H00000100
%KF_DLGMODE  = &H00000800
%KF_MENUMODE = &H00001000
%KF_ALTDOWN  = &H00002000
%KF_REPEAT   = &H00004000
%KF_UP       = &H00008000

#IF NOT %DEF(%NOVIRTUALKEYCODES) '---------------------------------------------

' Virtual Keys, Standard Set
%VK_LBUTTON  = &H01
%VK_RBUTTON  = &H02
%VK_CANCEL   = &H03
%VK_MBUTTON  = &H04    ' NOT contiguous with L RBUTTON
%VK_XBUTTON1 = &H05    ' NOT contiguous with L & RBUTTON
%VK_XBUTTON2 = &H06    ' NOT contiguous with L & RBUTTON
%VK_BACK     = &H08
%VK_TAB      = &H09
%VK_LINEFEED = &H0A
%VK_CLEAR    = &H0C
%VK_RETURN   = &H0D
%VK_SHIFT    = &H10
%VK_CONTROL  = &H11
%VK_MENU     = &H12
%VK_PAUSE    = &H13
%VK_CAPITAL  = &H14
%VK_KANA     = &H15
%VK_HANGEUL  = &H15  ' old name - should be here for compatibility
%VK_HANGUL   = &H15
%VK_JUNJA    = &H17
%VK_FINAL    = &H18
%VK_HANJA    = &H19
%VK_KANJI    = &H19
%VK_ESCAPE   = &H1B
%VK_CONVERT    = &H1C
%VK_NONCONVERT = &H1D
%VK_ACCEPT     = &H1E
%VK_MODECHANGE = &H1F
%VK_SPACE    = &H20
%VK_PGUP     = &H21
%VK_PRIOR    = &H21
%VK_NEXT     = &H22
%VK_PGDN     = &H22
%VK_END      = &H23
%VK_HOME     = &H24
%VK_LEFT     = &H25
%VK_UP       = &H26
%VK_RIGHT    = &H27
%VK_DOWN     = &H28
%VK_SELECT   = &H29
%VK_PRINT    = &H2A
%VK_EXECUTE  = &H2B
%VK_SNAPSHOT = &H2C
%VK_INSERT   = &H2D
%VK_DELETE   = &H2E
%VK_HELP     = &H2F
%VK_0        = &H30
%VK_1        = &H31
%VK_2        = &H32
%VK_3        = &H33
%VK_4        = &H34
%VK_5        = &H35
%VK_6        = &H36
%VK_7        = &H37
%VK_8        = &H38
%VK_9        = &H39
%VK_A        = &H41
%VK_B        = &H42
%VK_C        = &H43
%VK_D        = &H44
%VK_E        = &H45
%VK_F        = &H46
%VK_G        = &H47
%VK_H        = &H48
%VK_I        = &H49
%VK_J        = &H4A
%VK_K        = &H4B
%VK_L        = &H4C
%VK_M        = &H4D
%VK_N        = &H4E
%VK_O        = &H4F
%VK_P        = &H50
%VK_Q        = &H51
%VK_R        = &H52
%VK_S        = &H53
%VK_T        = &H54
%VK_U        = &H55
%VK_V        = &H56
%VK_W        = &H57
%VK_X        = &H58
%VK_Y        = &H59
%VK_Z        = &H5A
%VK_LWIN     = &H5B
%VK_RWIN     = &H5C
%VK_APPS     = &H5D
%VK_SLEEP    = &H5F
%VK_NUMPAD0  = &H60
%VK_NUMPAD1  = &H61
%VK_NUMPAD2  = &H62
%VK_NUMPAD3  = &H63
%VK_NUMPAD4  = &H64
%VK_NUMPAD5  = &H65
%VK_NUMPAD6  = &H66
%VK_NUMPAD7  = &H67
%VK_NUMPAD8  = &H68
%VK_NUMPAD9  = &H69
%VK_MULTIPLY = &H6A
%VK_ADD      = &H6B
%VK_SEPARATOR= &H6C
%VK_SUBTRACT = &H6D
%VK_DECIMAL  = &H6E
%VK_DIVIDE   = &H6F
%VK_F1       = &H70
%VK_F2       = &H71
%VK_F3       = &H72
%VK_F4       = &H73
%VK_F5       = &H74
%VK_F6       = &H75
%VK_F7       = &H76
%VK_F8       = &H77
%VK_F9       = &H78
%VK_F10      = &H79
%VK_F11      = &H7A
%VK_F12      = &H7B
%VK_F13      = &H7C
%VK_F14      = &H7D
%VK_F15      = &H7E
%VK_F16      = &H7F
%VK_F17      = &H80?
%VK_F18      = &H81?
%VK_F19      = &H82?
%VK_F20      = &H83?
%VK_F21      = &H84?
%VK_F22      = &H85?
%VK_F23      = &H86?
%VK_F24      = &H87?
%VK_NUMLOCK  = &H90?
%VK_SCROLL   = &H91?

' NEC PC-9800 kbd definitions

%VK_OEM_NEC_EQUAL  = &H92?   ' "=" key on numpad

' Fujitsu/OASYS kbd definitions

%VK_OEM_FJ_JISHO   = &H92?   ' "Dictionary" key
%VK_OEM_FJ_MASSHOU = &H93?   ' "Unregister word" key
%VK_OEM_FJ_TOUROKU = &H94?   ' "Register word" key
%VK_OEM_FJ_LOYA    = &H95?   ' "Left OYAYUBI" key
%VK_OEM_FJ_ROYA    = &H96?   ' "Right OYAYUBI" key

' VK_L* & VK_R* - left and right Alt, Ctrl and Shift virtual keys.
' Used only as parameters to GetAsyncKeyState() and GetKeyState().
' No other API or message will distinguish left and right keys in this way.

%VK_LSHIFT   = &HA0?
%VK_RSHIFT   = &HA1?
%VK_LCONTROL = &HA2?
%VK_RCONTROL = &HA3?
%VK_LMENU    = &HA4?
%VK_RMENU    = &HA5?
%VK_BROWSER_BACK        = &HA6?
%VK_BROWSER_FORWARD     = &HA7?
%VK_BROWSER_REFRESH     = &HA8?
%VK_BROWSER_STOP        = &HA9?
%VK_BROWSER_SEARCH      = &HAA?
%VK_BROWSER_FAVORITES   = &HAB?
%VK_BROWSER_HOME        = &HAC?
%VK_VOLUME_MUTE         = &HAD?
%VK_VOLUME_DOWN         = &HAE?
%VK_VOLUME_UP           = &HAF?
%VK_MEDIA_NEXT_TRACK    = &HB0?
%VK_MEDIA_PREV_TRACK    = &HB1?
%VK_MEDIA_STOP          = &HB2?
%VK_MEDIA_PLAY_PAUSE    = &HB3?
%VK_LAUNCH_MAIL         = &HB4?
%VK_LAUNCH_MEDIA_SELECT = &HB5?
%VK_LAUNCH_APP1         = &HB6?
%VK_LAUNCH_APP2         = &HB7?
%VK_OEM_1        = &HBA?   ' ";:" for US
%VK_OEM_PLUS     = &HBB?   ' "+" any country
%VK_OEM_COMMA    = &HBC?   ' "," any country
%VK_OEM_MINUS    = &HBD?   ' "-" any country
%VK_OEM_PERIOD   = &HBE?   ' "." any country
%VK_OEM_2        = &HBF?   ' "/?" for US
%VK_OEM_3        = &HC0?   ' "`~" for US
%VK_OEM_4        = &HDB?  ' "[{" for US
%VK_OEM_5        = &HDC?  ' "\|" for US
%VK_OEM_6        = &HDD?  ' "]}" for US
%VK_OEM_7        = &HDE?  ' """" for US
%VK_OEM_8        = &HDF?
%VK_OEM_AX       = &HE1?  ' "AX" key on Japanese AX kbd
%VK_OEM_102      = &HE2?  ' "<>" or "\|" on RT 102-key kbd.
%VK_ICO_HELP     = &HE3?  ' Help key on ICO
%VK_ICO_00       = &HE4?  ' 00 key on ICO
%VK_PROCESSKEY   = &HE5?
%VK_ICO_CLEAR    = &HE6?
%VK_PACKET       = &HE7?

' Nokia/Ericsson definitions

%VK_OEM_RESET    = &HE9?
%VK_OEM_JUMP     = &HEA?
%VK_OEM_PA1      = &HEB?
%VK_OEM_PA2      = &HEC?
%VK_OEM_PA3      = &HED?
%VK_OEM_WSCTRL   = &HEE?
%VK_OEM_CUSEL    = &HEF?
%VK_OEM_ATTN     = &HF0?
%VK_OEM_FINISH   = &HF1?
%VK_OEM_COPY     = &HF2?
%VK_OEM_AUTO     = &HF3?
%VK_OEM_ENLW     = &HF4?
%VK_OEM_BACKTAB  = &HF5?

%VK_ATTN         = &HF6?
%VK_CRSEL        = &HF7?
%VK_EXSEL        = &HF8?
%VK_EREOF        = &HF9?
%VK_PLAY         = &HFA?
%VK_ZOOM         = &HFB?
%VK_NONAME       = &HFC?
%VK_PA1          = &HFD?
%VK_OEM_CLEAR    = &HFE?
%VK_NONAME       = &HFC?
%VK_PA1          = &HFD?
%VK_OEM_CLEAR    = &HFE?

#ENDIF '#IF NOT %DEF(%NOVIRTUALKEYCODES) '-------------------------------------

' SetWindowsHook() codes
%WH_MIN             = -1
%WH_MSGFILTER       = -1
%WH_JOURNALRECORD   = 0
%WH_JOURNALPLAYBACK = 1
%WH_KEYBOARD        = 2
%WH_GETMESSAGE      = 3
%WH_CALLWNDPROC     = 4
%WH_CBT             = 5
%WH_SYSMSGFILTER    = 6
%WH_MOUSE           = 7
%WH_HARDWARE        = 8
%WH_DEBUG           = 9
%WH_SHELL           = 10
%WH_FOREGROUNDIDLE  = 11
%WH_CALLWNDPROCRET  = 12
%WH_KEYBOARD_LL     = 13
%WH_MOUSE_LL        = 14
%WH_MAX             = 14   ' depending on Windows version
%WH_MINHOOK         = %WH_MIN
%WH_MAXHOOK         = %WH_MAX

' codes passed in WPARAM for WM_WTSSESSION_CHANGE

%WTS_CONSOLE_CONNECT    = &H1
%WTS_CONSOLE_DISCONNECT = &H2
%WTS_REMOTE_CONNECT     = &H3
%WTS_REMOTE_DISCONNECT  = &H4
%WTS_SESSION_LOGON      = &H5
%WTS_SESSION_LOGOFF     = &H6
%WTS_SESSION_LOCK       = &H7
%WTS_SESSION_UNLOCK     = &H8
%WTS_SESSION_REMOTE_CONTROL    = &H9

' Hook Codes
%HC_ACTION       = 0
%HC_GETNEXT      = 1
%HC_SKIP         = 2
%HC_NOREMOVE     = 3
%HC_NOREM        = %HC_NOREMOVE
%HC_SYSMODALON   = 4
%HC_SYSMODALOFF  = 5

' CBT Hook Codes
%HCBT_MOVESIZE      = 0
%HCBT_MINMAX        = 1
%HCBT_QS            = 2
%HCBT_CREATEWND     = 3
%HCBT_DESTROYWND    = 4
%HCBT_ACTIVATE      = 5
%HCBT_CLICKSKIPPED  = 6
%HCBT_KEYSKIPPED    = 7
%HCBT_SYSCOMMAND    = 8
%HCBT_SETFOCUS      = 9

%HSHELL_WINDOWCREATED       = 1
%HSHELL_WINDOWDESTROYED     = 2
%HSHELL_ACTIVATESHELLWINDOW = 3
%HSHELL_WINDOWACTIVATED     = 4
%HSHELL_GETMINRECT          = 5
%HSHELL_REDRAW              = 6
%HSHELL_TASKMAN             = 7
%HSHELL_LANGUAGE            = 8
%HSHELL_ACCESSIBILITYSTATE  = 11
%HSHELL_APPCOMMAND          = 12
%HSHELL_WINDOWREPLACED      = 13
%HSHELL_WINDOWREPLACING     = 14

%HSHELL_HIGHBIT          = &H8000??
%HSHELL_FLASH            = (%HSHELL_REDRAW OR %HSHELL_HIGHBIT)
%HSHELL_RUDEAPPACTIVATED = (%HSHELL_WINDOWACTIVATED OR %HSHELL_HIGHBIT)

' wparam for HSHELL_ACCESSIBILITYSTATE
%ACCESS_STICKYKEYS = &H0001
%ACCESS_FILTERKEYS = &H0002
%ACCESS_MOUSEKEYS  = &H0003

' cmd for HSHELL_APPCOMMAND and WM_APPCOMMAND
%APPCOMMAND_BROWSER_BACKWARD     = 1
%APPCOMMAND_BROWSER_FORWARD      = 2
%APPCOMMAND_BROWSER_REFRESH      = 3
%APPCOMMAND_BROWSER_STOP         = 4
%APPCOMMAND_BROWSER_SEARCH       = 5
%APPCOMMAND_BROWSER_FAVORITES    = 6
%APPCOMMAND_BROWSER_HOME         = 7
%APPCOMMAND_VOLUME_MUTE          = 8
%APPCOMMAND_VOLUME_DOWN          = 9
%APPCOMMAND_VOLUME_UP            = 10
%APPCOMMAND_MEDIA_NEXTTRACK      = 11
%APPCOMMAND_MEDIA_PREVIOUSTRACK  = 12
%APPCOMMAND_MEDIA_STOP           = 13
%APPCOMMAND_MEDIA_PLAY_PAUSE     = 14
%APPCOMMAND_LAUNCH_MAIL          = 15
%APPCOMMAND_LAUNCH_MEDIA_SELECT  = 16
%APPCOMMAND_LAUNCH_APP1          = 17
%APPCOMMAND_LAUNCH_APP2          = 18
%APPCOMMAND_BASS_DOWN            = 19
%APPCOMMAND_BASS_BOOST           = 20
%APPCOMMAND_BASS_UP              = 21
%APPCOMMAND_TREBLE_DOWN          = 22
%APPCOMMAND_TREBLE_UP            = 23
%APPCOMMAND_MICROPHONE_VOLUME_MUTE = 24
%APPCOMMAND_MICROPHONE_VOLUME_DOWN = 25
%APPCOMMAND_MICROPHONE_VOLUME_UP   = 26
%APPCOMMAND_HELP                   = 27
%APPCOMMAND_FIND                   = 28
%APPCOMMAND_NEW                    = 29
%APPCOMMAND_OPEN                   = 30
%APPCOMMAND_CLOSE                  = 31
%APPCOMMAND_SAVE                   = 32
%APPCOMMAND_PRINT                  = 33
%APPCOMMAND_UNDO                   = 34
%APPCOMMAND_REDO                   = 35
%APPCOMMAND_COPY                   = 36
%APPCOMMAND_CUT                    = 37
%APPCOMMAND_PASTE                  = 38
%APPCOMMAND_REPLY_TO_MAIL          = 39
%APPCOMMAND_FORWARD_MAIL           = 40
%APPCOMMAND_SEND_MAIL              = 41
%APPCOMMAND_SPELL_CHECK            = 42
%APPCOMMAND_DICTATE_OR_COMMAND_CONTROL_TOGGLE = 43
%APPCOMMAND_MIC_ON_OFF_TOGGLE      = 44
%APPCOMMAND_CORRECTION_LIST        = 45
%APPCOMMAND_MEDIA_PLAY             = 46
%APPCOMMAND_MEDIA_PAUSE            = 47
%APPCOMMAND_MEDIA_RECORD           = 48
%APPCOMMAND_MEDIA_FAST_FORWARD     = 49
%APPCOMMAND_MEDIA_REWIND           = 50
%APPCOMMAND_MEDIA_CHANNEL_UP       = 51
%APPCOMMAND_MEDIA_CHANNEL_DOWN     = 52
%APPCOMMAND_DELETE               = 53
%APPCOMMAND_DWM_FLIP3D           = 54

%FAPPCOMMAND_MOUSE = &H08000
%FAPPCOMMAND_KEY   = 0
%FAPPCOMMAND_OEM   = &H01000
%FAPPCOMMAND_MASK  = &H0F000

' Low level hook flags

%LLKHF_EXTENDED = %KF_EXTENDED \ 256
%LLKHF_INJECTED = &H00000010
%LLKHF_ALTDOWN  = %KF_ALTDOWN \ 256
%LLKHF_UP       = %KF_UP \ 256
%LLMHF_INJECTED = &H00000001

' Keyboard Layout API
%HKL_PREV = 0
%HKL_NEXT = 1

%KLF_ACTIVATE       = &H00000001
%KLF_SUBSTITUTE_OK  = &H00000002
%KLF_UNLOADPREVIOUS = &H00000004
%KLF_REORDER        = &H00000008
%KLF_REPLACELANG    = &H00000010
%KLF_NOTELLSHELL    = &H00000080
%KLF_SETFORPROCESS  = &H00000100
%KLF_SHIFTLOCK      = &H00010000
%KLF_RESET          = &H40000000

' Size of KeyboardLayoutName (number of characters), including nul terminator
%KL_NAMELENGTH = 9

' Values for resolution parameter of GetMouseMovePointsEx
%GMMP_USE_DISPLAY_POINTS         = 1
%GMMP_USE_HIGH_RESOLUTION_POINTS = 2

#IF NOT %DEF(%NODESKTOP) '----------------------------

' Desktop-specific access flags
%DESKTOP_READOBJECTS      = &H0001
%DESKTOP_CREATEWINDOW     = &H0002
%DESKTOP_CREATEMENU       = &H0004
%DESKTOP_HOOKCONTROL      = &H0008
%DESKTOP_JOURNALRECORD    = &H0010
%DESKTOP_JOURNALPLAYBACK  = &H0020
%DESKTOP_ENUMERATE        = &H0040
%DESKTOP_WRITEOBJECTS     = &H0080
%DESKTOP_SWITCHDESKTOP    = &H0100

' Desktop-specific control flags
%DF_ALLOWOTHERACCOUNTHOOK = &H0001

#ENDIF ' #IF NOT %DEF(%NODESKTOP) '-------------------


#IF NOT %DEF(%NOWINDOWSTATION) '----------------------

' Windowstation-specific access flags
%WINSTA_ENUMDESKTOPS      = &H0001
%WINSTA_READATTRIBUTES    = &H0002
%WINSTA_ACCESSCLIPBOARD   = &H0004
%WINSTA_CREATEDESKTOP     = &H0008
%WINSTA_WRITEATTRIBUTES   = &H0010
%WINSTA_ACCESSGLOBALATOMS = &H0020
%WINSTA_EXITWINDOWS       = &H0040
%WINSTA_ENUMERATE         = &H0100
%WINSTA_READSCREEN        = &H0200

' Windowstation-specific attribute flags
%WSF_VISIBLE              = &H0001

#ENDIF ' #IF NOT %DEF(%NOWINDOWSTATION) '-------------

#IF NOT %DEF(%NOWINOFFSETS) '-------------------------
' Window field offsets for GetWindowLong() and GetWindowWord()
%GWL_WNDPROC    = -4
%GWL_HINSTANCE  = -6
%GWL_HWNDPARENT = -8
%GWL_STYLE      = -16
%GWL_EXSTYLE    = -20
%GWL_USERDATA   = -21
%GWL_ID         = -12

%GWLP_WNDPROC    = -4
%GWLP_HINSTANCE  = -6
%GWLP_HWNDPARENT = -8
%GWLP_USERDATA   = -21
%GWLP_ID         = -12

' Class field offsets for GetClassLong() and GetClassWord()
%GCL_MENUNAME      = -8
%GCL_HBRBACKGROUND = -10
%GCL_HCURSOR       = -12
%GCL_HICON         = -14
%GCL_HMODULE       = -16
%GCL_CBWNDEXTRA    = -18
%GCL_CBCLSEXTRA    = -20
%GCL_WNDPROC       = -24
%GCL_STYLE         = -26
%GCW_ATOM          = -32
%GCL_HICONSM       = -34

%GCLP_MENUNAME      = -8
%GCLP_HBRBACKGROUND = -10
%GCLP_HCURSOR       = -12
%GCLP_HICON         = -14
%GCLP_HMODULE       = -16
%GCLP_WNDPROC       = -24
%GCLP_HICONSM       = -34
#ENDIF ' #IF NOT %DEF(%NOWINOFFSETS) '----------------

' WH_MSGFILTER Filter Proc Codes
%MSGF_DIALOGBOX  = 0
%MSGF_MESSAGEBOX = 1
%MSGF_MENU       = 2
%MSGF_MOVE       = 3
%MSGF_SIZE       = 4
%MSGF_SCROLLBAR  = 5
%MSGF_NEXTWINDOW = 6
%MSGF_MAX        = 8
%MSGF_USER       = 4096

'
' WM_ACTIVATE state values

%WA_INACTIVE     = 0
%WA_ACTIVE       = 1
%WA_CLICKACTIVE  = 2

%WM_ENABLE               = &HA
%WM_SETREDRAW            = &HB
%WM_SETTEXT              = &HC
%WM_GETTEXT              = &HD
%WM_GETTEXTLENGTH        = &HE
%WM_QUERYENDSESSION      = &H11
%WM_QUERYOPEN            = &H13
%WM_ERASEBKGND           = &H14
%WM_SYSCOLORCHANGE       = &H15
%WM_ENDSESSION           = &H16
%WM_SHOWWINDOW           = &H18
%WM_WININICHANGE         = &H1A
%WM_SETTINGCHANGE        = %WM_WININICHANGE
%WM_DEVMODECHANGE        = &H1B
%WM_FONTCHANGE           = &H1D
%WM_TIMECHANGE           = &H1E
%WM_SETCURSOR            = &H20
%WM_CHILDACTIVATE        = &H22
%WM_QUEUESYNC            = &H23
%WM_GETMINMAXINFO        = &H24
%WM_PAINTICON            = &H26
%WM_ICONERASEBKGND       = &H27
%WM_NEXTDLGCTL           = &H28
%WM_SPOOLERSTATUS        = &H2A
%WM_MEASUREITEM          = &H2C
%WM_DELETEITEM           = &H2D
%WM_VKEYTOITEM           = &H2E
%WM_CHARTOITEM           = &H2F
%WM_SETFONT              = &H30
%WM_GETFONT              = &H31
%WM_SETHOTKEY            = &H32
%WM_GETHOTKEY            = &H33
%WM_QUERYDRAGICON        = &H37
%WM_COMPAREITEM          = &H39
%WM_GETOBJECT            = &H3D
%WM_COMPACTING           = &H41
%WM_OTHERWINDOWCREATED   = &H42  ' no longer supported
%WM_OTHERWINDOWDESTROYED = &H43  ' no longer supported
%WM_COMMNOTIFY           = &H44  ' no longer supported

' notifications passed in low word of lParam on WM_COMMNOTIFY messages
%CN_RECEIVE              = &H1
%CN_TRANSMIT             = &H2
%CN_EVENT                = &H4

%WM_WINDOWPOSCHANGING    = &H46
%WM_WINDOWPOSCHANGED     = &H47
%WM_POWER                = &H48

' wParam for WM_POWER window message and DRV_POWER driver notification
%PWR_OK             = 1
%PWR_FAIL           = -1
%PWR_SUSPENDREQUEST = 1
%PWR_SUSPENDRESUME  = 2
%PWR_CRITICALRESUME = 3

%WM_COPYDATA                   = &H4A
%WM_CANCELJOURNAL              = &H4B
%WM_INPUTLANGUAGECHANGEREQUEST = &H50
%WM_INPUTLANGCHANGEREQUEST     = &H50
%WM_INPUTLANGUAGECHANGE        = &H51
%WM_INPUTLANGCHANGE            = &H51
%WM_TCARD                      = &H52
%WM_USERCHANGED                = &H54
%WM_NOTIFYFORMAT               = &H55

%WM_CONTEXTMENU      = &H7B
%WM_STYLECHANGING    = &H7C
%WM_STYLECHANGED     = &H7D
%WM_DISPLAYCHANGE    = &H7E

%WM_GETICON          = &H7F
%WM_SETICON          = &H80
%WM_GETDLGCODE       = &H87
%WM_SYNCPAINT        = &H88
%WM_INPUT_DEVICE_CHANGE = &H00FE
%WM_INPUT            = &HFF

%WM_KEYFIRST         = &H100
%WM_DEADCHAR         = &H103
%WM_SYSCHAR          = &H106
%WM_SYSDEADCHAR      = &H107
%WM_IME_STARTCOMPOSITION = &H010D
%WM_IME_ENDCOMPOSITION   = &H010E
%WM_IME_COMPOSITION      = &H010F
%WM_IME_KEYLAST          = &H010F
%WM_UNICHAR          = &H0109
%WM_KEYLAST          = &H0109
%UNICODE_NOCHAR      = &H0FFFF
%WM_SYSCOMMAND       = &H112
%WM_INITMENU         = &H116
%WM_INITMENUPOPUP    = &H117
%WM_MENUSELECT       = &H11F
%WM_MENUCHAR         = &H120
%WM_ENTERIDLE        = &H121
%WM_MENURBUTTONUP    = &H0122
%WM_MENUDRAG         = &H0123
%WM_MENUGETOBJECT    = &H0124
%WM_UNINITMENUPOPUP  = &H0125
%WM_MENUCOMMAND      = &H0126
%WM_CHANGEUISTATE    = &H0127
%WM_UPDATEUISTATE    = &H0128
%WM_QUERYUISTATE     = &H0129
%WM_CTLCOLORMSGBOX   = &H132
%WM_CTLCOLOREDIT     = &H133
%WM_CTLCOLORLISTBOX  = &H134
%WM_CTLCOLORBTN      = &H135
%WM_CTLCOLORDLG      = &H136
%WM_CTLCOLORSCROLLBAR = &H137
%WM_CTLCOLORSTATIC   = &H138
%WM_XBUTTONDOWN      = &H20B
%WM_XBUTTONUP        = &H20C
%WM_XBUTTONDBLCLK    = &H20D

%WM_PARENTNOTIFY     = &H210
%WM_ENTERMENULOOP    = &H211
%WM_EXITMENULOOP     = &H212

%WM_SIZING           = &H214
%WM_MOVING           = &H216

%WM_POWERBROADCAST   = &H218
%WM_DEVICECHANGE     = &H219
%WM_MDICREATE        = &H220
%WM_MDIDESTROY       = &H221
%WM_MDIACTIVATE      = &H222
%WM_MDIRESTORE       = &H223
%WM_MDINEXT          = &H224
%WM_MDIMAXIMIZE      = &H225
%WM_MDITILE          = &H226
%WM_MDICASCADE       = &H227
%WM_MDIICONARRANGE   = &H228
%WM_MDIGETACTIVE     = &H229
%WM_MDISETMENU       = &H230
%WM_DROPFILES        = &H233
%WM_MDIREFRESHMENU   = &H234

%WM_WTSSESSION_CHANGE = &H02B1
%WM_TABLET_FIRST      = &H02c0
%WM_TABLET_LAST       = &H02df

%WM_CUT               = &H300
%WM_COPY              = &H301
%WM_PASTE             = &H302
%WM_CLEAR             = &H303
%WM_UNDO              = &H304
%WM_RENDERFORMAT      = &H305
%WM_RENDERALLFORMATS  = &H306
%WM_DESTROYCLIPBOARD  = &H307
%WM_DRAWCLIPBOARD     = &H308
%WM_PAINTCLIPBOARD    = &H309
%WM_VSCROLLCLIPBOARD  = &H30A
%WM_SIZECLIPBOARD     = &H30B
%WM_ASKCBFORMATNAME   = &H30C
%WM_CHANGECBCHAIN     = &H30D
%WM_HSCROLLCLIPBOARD  = &H30E
%WM_QUERYNEWPALETTE   = &H30F
%WM_PALETTEISCHANGING = &H310
%WM_PALETTECHANGED    = &H311
%WM_HOTKEY            = &H312
%WM_PRINT             = &H317
%WM_PRINTCLIENT       = &H318
%WM_APPCOMMAND        = &H319
%WM_THEMECHANGED      = &H31A
%WM_HANDHELDFIRST     = &H0358
%WM_HANDHELDLAST      = &H035F
%WM_AFXFIRST          = &H0360
%WM_AFXLAST           = &H037F
%WM_PENWINFIRST       = &H380
%WM_PENWINLAST        = &H38F
%WM_APP               = &H08000

%WMSZ_LEFT         = 1
%WMSZ_RIGHT        = 2
%WMSZ_TOP          = 3
%WMSZ_TOPLEFT      = 4
%WMSZ_TOPRIGHT     = 5
%WMSZ_BOTTOM       = 6
%WMSZ_BOTTOMLEFT   = 7
%WMSZ_BOTTOMRIGHT  = 8

' Broadcast Special Message Recipient list
%BSM_ALLCOMPONENTS       = &H00000000
%BSM_VXDS                = &H00000001
%BSM_NETDRIVER           = &H00000002
%BSM_INSTALLABLEDRIVERS  = &H00000004
%BSM_APPLICATIONS        = &H00000008
%BSM_ALLDESKTOPS         = &H00000010

' Broadcast Special Message Flags
%BSF_QUERY               = &H00000001
%BSF_IGNORECURRENTTASK   = &H00000002
%BSF_FLUSHDISK           = &H00000004
%BSF_NOHANG              = &H00000008
%BSF_POSTMESSAGE         = &H00000010
%BSF_FORCEIFHUNG         = &H00000020
%BSF_NOTIMEOUTIFNOTHUNG  = &H00000040
%BSF_ALLOWSFW            = &H00000080
%BSF_SENDNOTIFYMESSAGE   = &H00000100
%BSF_RETURNHDESK         = &H00000200
%BSF_LUID                = &H00000400

%BROADCAST_QUERY_DENY    = &H424D5144  ' Return this value to deny a query.

%DEVICE_NOTIFY_WINDOW_HANDLE         = &H00000000
%DEVICE_NOTIFY_SERVICE_HANDLE        = &H00000001
%DEVICE_NOTIFY_ALL_INTERFACE_CLASSES = &H00000004

' WM_SETICON / WM_GETICON Type Codes
%ICON_SMALL  = 0
%ICON_BIG    = 1
%ICON_SMALL2 = 2

' WM_NCHITTEST and MOUSEHOOKSTRUCT Mouse Position Codes
%HTERROR        = -2
%HTTRANSPARENT  = -1
%HTNOWHERE      = 0
%HTCLIENT       = 1
%HTCAPTION      = 2
%HTSYSMENU      = 3
%HTGROWBOX      = 4
%HTSIZE         = %HTGROWBOX
%HTMENU         = 5
%HTHSCROLL      = 6
%HTVSCROLL      = 7
%HTMINBUTTON    = 8
%HTMAXBUTTON    = 9
%HTLEFT         = 10
%HTRIGHT        = 11
%HTTOP          = 12
%HTTOPLEFT      = 13
%HTTOPRIGHT     = 14
%HTBOTTOM       = 15
%HTBOTTOMLEFT   = 16
%HTBOTTOMRIGHT  = 17
%HTBORDER       = 18
%HTREDUCE       = %HTMINBUTTON
%HTZOOM         = %HTMAXBUTTON
%HTSIZEFIRST    = %HTLEFT
%HTSIZELAST     = %HTBOTTOMRIGHT
%HTOBJECT       = 19
%HTCLOSE        = 20
%HTHELP         = 21

' SendMessageTimeout values
%SMTO_NORMAL             = &H0000
%SMTO_BLOCK              = &H0001
%SMTO_ABORTIFHUNG        = &H0002
%SMTO_NOTIMEOUTIFNOTHUNG = &H0008
%SMTO_ERRORONEXIT        = &H0020

' WM_MOUSEACTIVATE Return Codes
%MA_ACTIVATE         = 1
%MA_ACTIVATEANDEAT   = 2
%MA_NOACTIVATE       = 3
%MA_NOACTIVATEANDEAT = 4

' WM_SIZE message wParam values
%SIZE_RESTORED   = 0
%SIZE_MINIMIZED  = 1
%SIZE_MAXIMIZED  = 2
%SIZE_MAXSHOW    = 3
%SIZE_MAXHIDE    = 4

' Obsolete constant names
%SIZENORMAL     = %SIZE_RESTORED
%SIZEICONIC     = %SIZE_MINIMIZED
%SIZEFULLSCREEN = %SIZE_MAXIMIZED
%SIZEZOOMSHOW   = %SIZE_MAXSHOW
%SIZEZOOMHIDE   = %SIZE_MAXHIDE

' WM_NCCALCSIZE return flags
%WVR_ALIGNTOP     = &H10
%WVR_ALIGNLEFT    = &H20
%WVR_ALIGNBOTTOM  = &H40
%WVR_ALIGNRIGHT   = &H80
%WVR_HREDRAW      = &H100
%WVR_VREDRAW      = &H200
%WVR_REDRAW       = %WVR_HREDRAW OR %WVR_VREDRAW
%WVR_VALIDRECTS   = &H400

' Key State Masks for Mouse Messages
%MK_LBUTTON  = &H0001
%MK_RBUTTON  = &H0002
%MK_SHIFT    = &H0004
%MK_CONTROL  = &H0008
%MK_MBUTTON  = &H0010
%MK_XBUTTON1 = &H0020
%MK_XBUTTON2 = &H0040

%TME_HOVER     = &H00000001
%TME_LEAVE     = &H00000002
%TME_NONCLIENT = &H00000010
%TME_QUERY     = &H40000000
%TME_CANCEL    = &H80000000???
%HOVER_DEFAULT = &HFFFFFFFF???

%CS_VREDRAW          = &H00000001
%CS_HREDRAW          = &H00000002
%CS_KEYCVTWINDOW     = &H00000004
%CS_DBLCLKS          = &H00000008
%CS_OWNDC            = &H00000020
%CS_CLASSDC          = &H00000040
%CS_PARENTDC         = &H00000080
%CS_NOKEYCVT         = &H00000100
%CS_NOCLOSE          = &H00000200
%CS_SAVEBITS         = &H00000800
%CS_BYTEALIGNCLIENT  = &H00001000
%CS_BYTEALIGNWINDOW  = &H00002000
%CS_PUBLICCLASS      = &H00004000
%CS_GLOBALCLASS      = %CS_PUBLICCLASS
%CS_IME              = &H00010000
%CS_DROPSHADOW       = &H00020000

%CF_DIBV5         = 17
%CF_MAX           = 18   ' varies by Windows version

%CF_OWNERDISPLAY    = &H0080
%CF_DSPTEXT         = &H0081
%CF_DSPBITMAP       = &H0082
%CF_DSPMETAFILEPICT = &H0083
%CF_DSPENHMETAFILE  = &H008E

%CF_PRIVATEFIRST    = &H200
%CF_PRIVATELAST     = &H2FF

%CF_GDIOBJFIRST     = &H300
%CF_GDIOBJLAST      = &H3FF

%FVIRTKEY  = &H1        ' Assumed to be equal to %TRUE
%FNOINVERT = &H2
%FSHIFT    = &H4
%FCONTROL  = &H8
%FALT      = &H10

%WPF_SETMINPOSITION       = &H0001
%WPF_RESTORETOMAXIMIZED   = &H0002
%WPF_ASYNCWINDOWPLACEMENT = &H0004

' Owner draw control types
%ODT_MENU      = 1
%ODT_LISTBOX   = 2
%ODT_COMBOBOX  = 3
%ODT_BUTTON    = 4
%ODT_STATIC    = 5

' Owner draw actions
%ODA_DRAWENTIRE = &H1
%ODA_SELECT     = &H2
%ODA_FOCUS      = &H4

' Owner draw state
%ODS_SELECTED   = &H1
%ODS_GRAYED     = &H2
%ODS_DISABLED   = &H4
%ODS_CHECKED    = &H8
%ODS_FOCUS      = &H10
%ODS_DEFAULT      = &H0020
%ODS_COMBOBOXEDIT = &H1000
%ODS_HOTLIGHT     = &H0040
%ODS_INACTIVE     = &H0080
%ODS_NOACCEL      = &H0100
%ODS_NOFOCUSRECT  = &H0200

%MOD_ALT                 = &H00000001
%MOD_CONTROL             = &H00000002
%MOD_SHIFT               = &H00000004
%MOD_WIN                 = &H00000008
%MOD_NOREPEAT  = &H4000
%MOD_LEFT                = &H00008000
%MOD_RIGHT               = &H00004000
%MOD_ON_KEYUP            = &H00000800
%MOD_IGNORE_ALL_MODIFIER = &H00000400

%IDHOT_SNAPWINDOW  = -1    ' SHIFT-PRINTSCRN
%IDHOT_SNAPDESKTOP = -2    ' PRINTSCRN

%EWX_LOGOFF      = &H0000
%EWX_SHUTDOWN    = &H0001
%EWX_REBOOT      = &H0002
%EWX_FORCE       = &H0004
%EWX_POWEROFF    = &H0008
%EWX_FORCEIFHUNG = &H0010
%EWX_QUICKRESOLVE   = &H00000020
%EWX_RESTARTAPPS    = &H00000040

%READAPI           = 0     ' Flags for _lopen
%WRITEAPI          = 1
%READ_WRITE        = 2

' Special HWND value for use with PostMessage and SendMessage
%HWND_BROADCAST = &HFFFFFFFF???

%CW_USEDEFAULT       = &H80000000& ' long

%CWP_ALL             = &H0000
%CWP_SKIPINVISIBLE   = &H0001
%CWP_SKIPDISABLED    = &H0002
%CWP_SKIPTRANSPARENT = &H0004

%HWND_TOP       = 0
%HWND_BOTTOM    = 1
%HWND_TOPMOST   = &HFFFFFFFF???
%HWND_NOTOPMOST = &HFFFFFFFE???
%HWND_MESSAGE   = &HFFFFFFFD???

' InSendMessageEx return value
%ISMEX_NOSEND   = &H00000000
%ISMEX_SEND     = &H00000001
%ISMEX_NOTIFY   = &H00000002
%ISMEX_CALLBACK = &H00000004
%ISMEX_REPLIED  = &H00000008

%PW_CLIENTONLY = &H00000001

%LWA_COLORKEY  = &H00000001
%LWA_ALPHA     = &H00000002

%ULW_COLORKEY  = &H00000001
%ULW_ALPHA     = &H00000002
%ULW_OPAQUE    = &H00000004

%ULW_EX_NORESIZE  = &H00000008

%FLASHW_STOP      = 0
%FLASHW_CAPTION   = &H00000001
%FLASHW_TRAY      = &H00000002
%FLASHW_ALL       = %FLASHW_CAPTION OR %FLASHW_TRAY
%FLASHW_TIMER     = &H00000004
%FLASHW_TIMERNOFG = &H0000000C

' SetWindowPos Flags
%SWP_NOSIZE         = &H0001
%SWP_NOMOVE         = &H0002
%SWP_NOZORDER       = &H0004
%SWP_NOREDRAW       = &H0008
%SWP_NOACTIVATE     = &H0010
%SWP_FRAMECHANGED   = &H0020  ' The frame changed: send WM_NCCALCSIZE
%SWP_SHOWWINDOW     = &H0040
%SWP_HIDEWINDOW     = &H0080
%SWP_NOCOPYBITS     = &H0100
%SWP_NOOWNERZORDER  = &H0200  ' Don't do owner Z ordering
%SWP_NOSENDCHANGING = &H0400  ' Don't send WM_WINDOWPOSCHANGING
%SWP_DRAWFRAME      = %SWP_FRAMECHANGED
%SWP_NOREPOSITION   = %SWP_NOOWNERZORDER
%SWP_DEFERERASE     = &H2000
%SWP_ASYNCWINDOWPOS = &H4000

%DLGWINDOWEXTRA     = 30        ' Window extra bytes needed for private dialog classes

%KEYEVENTF_EXTENDEDKEY  = &H1
%KEYEVENTF_KEYUP        = &H2
%KEYEVENTF_UNICODE     = &H0004
%KEYEVENTF_SCANCODE    = &H0008

%MOUSEEVENTF_MOVE       = &H00000001 ' mouse move
%MOUSEEVENTF_LEFTDOWN   = &H00000002 ' left button down
%MOUSEEVENTF_LEFTUP     = &H00000004 ' left button up
%MOUSEEVENTF_RIGHTDOWN  = &H00000008 ' right button down
%MOUSEEVENTF_RIGHTUP    = &H00000010 ' right button up
%MOUSEEVENTF_MIDDLEDOWN = &H00000020 ' middle button down
%MOUSEEVENTF_MIDDLEUP   = &H00000040 ' middle button up
%MOUSEEVENTF_WHEEL      = &H00000800 ' wheel button rolled
%MOUSEEVENTF_HWHEEL     = &H00001000 ' hwheel button rolled
%MOUSEEVENTF_MOVE_NOCOALESCE = &H2000 ' do not coalesce mouse moves
%MOUSEEVENTF_VIRTUALDESK = &H4000 ' map to entire virtual desktop
%MOUSEEVENTF_ABSOLUTE   = &H00008000 ' absolute move

%INPUT_MOUSE    = 0
%INPUT_KEYBOARD = 1
%INPUT_HARDWARE = 2

' GetQueueStatus flags
%QS_KEY          = &H0001
%QS_MOUSEMOVE    = &H0002
%QS_MOUSEBUTTON  = &H0004
%QS_POSTMESSAGE  = &H0008
%QS_TIMER        = &H0010
%QS_PAINT        = &H0020
%QS_SENDMESSAGE  = &H0040
%QS_HOTKEY       = &H0080
%QS_MOUSE        = %QS_MOUSEMOVE OR %QS_MOUSEBUTTON
%QS_RAWINPUT       = &H0400
%QS_INPUT        = %QS_MOUSE OR %QS_KEY OR %QS_RAWINPUT
%QS_ALLPOSTMESSAGE = &H0100
%QS_INPUTXP        = %QS_MOUSE OR %QS_KEY OR %QS_RAWINPUT ' Windows XP and later
%QS_ALLEVENTS      = %QS_INPUT OR %QS_POSTMESSAGE OR %QS_TIMER OR %QS_PAINT OR %QS_HOTKEY
%QS_ALLINPUT       = %QS_INPUT OR %QS_POSTMESSAGE OR %QS_TIMER OR %QS_PAINT OR %QS_HOTKEY OR %QS_SENDMESSAGE

' PeekMessage() Options
%PM_NOREMOVE    = &H0
%PM_REMOVE      = &H1
%PM_NOYIELD     = &H2
%PM_QS_INPUT       = %QS_INPUT * 256
%PM_QS_POSTMESSAGE = (%QS_POSTMESSAGE OR %QS_HOTKEY OR %QS_TIMER) * 256
%PM_QS_PAINT       = %QS_PAINT * 256
%PM_QS_SENDMESSAGE = %QS_SENDMESSAGE * 256

' GetSystemMetrics() codes
%SM_CXSCREEN            = 0
%SM_CYSCREEN            = 1
%SM_CXVSCROLL           = 2
%SM_CYHSCROLL           = 3
%SM_CYCAPTION           = 4
%SM_CXBORDER            = 5
%SM_CYBORDER            = 6
%SM_CXDLGFRAME          = 7
%SM_CYDLGFRAME          = 8
%SM_CYVTHUMB            = 9
%SM_CXHTHUMB            = 10
%SM_CXICON              = 11
%SM_CYICON              = 12
%SM_CXCURSOR            = 13
%SM_CYCURSOR            = 14
%SM_CYMENU              = 15
%SM_CXFULLSCREEN        = 16
%SM_CYFULLSCREEN        = 17
%SM_CYKANJIWINDOW       = 18
%SM_MOUSEPRESENT        = 19
%SM_CYVSCROLL           = 20
%SM_CXHSCROLL           = 21
%SM_DEBUG               = 22
%SM_SWAPBUTTON          = 23
%SM_RESERVED1           = 24
%SM_RESERVED2           = 25
%SM_RESERVED3           = 26
%SM_RESERVED4           = 27
%SM_CXMIN               = 28
%SM_CYMIN               = 29
%SM_CXSIZE              = 30
%SM_CYSIZE              = 31
%SM_CXFRAME             = 32
%SM_CYFRAME             = 33
%SM_CXMINTRACK          = 34
%SM_CYMINTRACK          = 35
%SM_CXDOUBLECLK         = 36
%SM_CYDOUBLECLK         = 37
%SM_CXICONSPACING       = 38
%SM_CYICONSPACING       = 39
%SM_MENUDROPALIGNMENT   = 40
%SM_PENWINDOWS          = 41
%SM_DBCSENABLED         = 42
%SM_CMOUSEBUTTONS       = 43

%SM_CXFIXEDFRAME        = %SM_CXDLGFRAME  ' win40 name change
%SM_CYFIXEDFRAME        = %SM_CYDLGFRAME  ' win40 name change
%SM_CXSIZEFRAME         = %SM_CXFRAME     ' win40 name change
%SM_CYSIZEFRAME         = %SM_CYFRAME     ' win40 name change

%SM_SECURE              = 44
%SM_CXEDGE              = 45
%SM_CYEDGE              = 46
%SM_CXMINSPACING        = 47
%SM_CYMINSPACING        = 48
%SM_CXSMICON            = 49
%SM_CYSMICON            = 50
%SM_CYSMCAPTION         = 51
%SM_CXSMSIZE            = 52
%SM_CYSMSIZE            = 53
%SM_CXMENUSIZE          = 54
%SM_CYMENUSIZE          = 55
%SM_ARRANGE             = 56
%SM_CXMINIMIZED         = 57
%SM_CYMINIMIZED         = 58
%SM_CXMAXTRACK          = 59
%SM_CYMAXTRACK          = 60
%SM_CXMAXIMIZED         = 61
%SM_CYMAXIMIZED         = 62
%SM_NETWORK             = 63
%SM_CLEANBOOT           = 67
%SM_CXDRAG              = 68
%SM_CYDRAG              = 69
%SM_SHOWSOUNDS          = 70
%SM_CXMENUCHECK         = 71   ' Use instead of GetMenuCheckMarkDimensions()
%SM_CYMENUCHECK         = 72
%SM_SLOWMACHINE         = 73
%SM_MIDEASTENABLED      = 74
%SM_MOUSEWHEELPRESENT   = 75
%SM_XVIRTUALSCREEN      = 76
%SM_YVIRTUALSCREEN      = 77
%SM_CXVIRTUALSCREEN     = 78
%SM_CYVIRTUALSCREEN     = 79
%SM_CMONITORS           = 80
%SM_SAMEDISPLAYFORMAT   = 81
%SM_IMMENABLED          = 82
%SM_CXFOCUSBORDER       = 83
%SM_CYFOCUSBORDER       = 84
%SM_TABLETPC            = 86
%SM_MEDIACENTER         = 87
%SM_STARTER             = 88
%SM_SERVERR2            = 89
%SM_MOUSEHORIZONTALWHEELPRESENT  = 91
%SM_CXPADDEDBORDER       = 92
%SM_DIGITIZER            = 94
%SM_MAXIMUMTOUCHES       = 95
%SM_CMETRICS             = 97   ' depends on Windows version
%SM_REMOTESESSION        = &H1000
%SM_SHUTTINGDOWN         = &H2000
%SM_REMOTECONTROL        = &H2001
%SM_CARETBLINKINGENABLED = &H2002

' Flags for TrackPopupMenu
%TPM_LEFTBUTTON   = &H0000
%TPM_RIGHTBUTTON  = &H0002
%TPM_LEFTALIGN    = &H0000
%TPM_CENTERALIGN  = &H0004
%TPM_RIGHTALIGN   = &H0008
%TPM_TOPALIGN     = &H0000
%TPM_VCENTERALIGN = &H0010
%TPM_BOTTOMALIGN  = &H0020
%TPM_HORIZONTAL   = &H0000    ' Horz alignment matters more
%TPM_VERTICAL     = &H0040   ' Vert alignment matters more
%TPM_NONOTIFY     = &H0080   ' Don't send any notification msgs
%TPM_RETURNCMD    = &H0100
%TPM_RECURSE           = &H0001
%TPM_HORPOSANIMATION   = &H0400
%TPM_HORNEGANIMATION   = &H0800
%TPM_VERPOSANIMATION   = &H1000
%TPM_VERNEGANIMATION   = &H2000
%TPM_NOANIMATION       = &H4000
%TPM_LAYOUTRTL         = &H8000??
%TPM_WORKAREA          = &H10000

' DrawText() Format Flags
%DT_TOP                 = &H0
%DT_LEFT                = &H0
%DT_CENTER              = &H00000001
%DT_RIGHT               = &H00000002
%DT_VCENTER             = &H00000004
%DT_BOTTOM              = &H00000008
%DT_WORDBREAK           = &H00000010
%DT_SINGLELINE          = &H00000020
%DT_EXPANDTABS          = &H00000040
%DT_TABSTOP             = &H00000080
%DT_NOCLIP              = &H00000100
%DT_EXTERNALLEADING     = &H00000200
%DT_CALCRECT            = &H00000400
%DT_NOPREFIX            = &H00000800
%DT_INTERNAL            = &H00001000
%DT_EDITCONTROL         = &H00002000
%DT_PATH_ELLIPSIS       = &H00004000
%DT_END_ELLIPSIS        = &H00008000
%DT_MODIFYSTRING        = &H00010000
%DT_RTLREADING          = &H00020000
%DT_WORD_ELLIPSIS       = &H00040000
%DT_NOFULLWIDTHCHARBREAK = &H00080000
%DT_HIDEPREFIX           = &H00100000
%DT_PREFIXONLY           = &H00200000

%DCX_WINDOW           = &H00000001
%DCX_CACHE            = &H00000002
%DCX_NORESETATTRS     = &H00000004
%DCX_CLIPCHILDREN     = &H00000008
%DCX_CLIPSIBLINGS     = &H00000010
%DCX_PARENTCLIP       = &H00000020
%DCX_EXCLUDERGN       = &H00000040
%DCX_INTERSECTRGN     = &H00000080
%DCX_EXCLUDEUPDATE    = &H00000100
%DCX_INTERSECTUPDATE  = &H00000200
%DCX_LOCKWINDOWUPDATE = &H00000400

%DCX_VALIDATE         = &H00200000

%RDW_INVALIDATE       = &H0001
%RDW_INTERNALPAINT    = &H0002
%RDW_ERASE            = &H0004

%RDW_VALIDATE         = &H0008
%RDW_NOINTERNALPAINT  = &H0010
%RDW_NOERASE          = &H0020

%RDW_NOCHILDREN       = &H0040
%RDW_ALLCHILDREN      = &H0080

%RDW_UPDATENOW        = &H0100
%RDW_ERASENOW         = &H0200

%RDW_FRAME            = &H0400
%RDW_NOFRAME          = &H0800

%SW_SCROLLCHILDREN = &H1
%SW_INVALIDATE     = &H2
%SW_ERASE          = &H4
%SW_SMOOTHSCROLL   = &H0010

' EnableScrollBar() flags
%ESB_ENABLE_BOTH        = &H0
%ESB_DISABLE_BOTH       = &H3

%ESB_DISABLE_LEFT       = &H1
%ESB_DISABLE_RIGHT      = &H2

%ESB_DISABLE_UP         = &H1
%ESB_DISABLE_DOWN       = &H2

%ESB_DISABLE_LTUP       = %ESB_DISABLE_LEFT
%ESB_DISABLE_RTDN       = %ESB_DISABLE_RIGHT

%MB_PRECOMPOSED       = &H00000001  ' use precomposed chars
%MB_COMPOSITE         = &H00000002  ' use composite chars
%MB_USEGLYPHCHARS     = &H00000004  ' use glyph chars, not ctrl chars
%MB_ERR_INVALID_CHARS = &H00000008  ' error for invalid chars

' Color Types
%CTLCOLOR_MSGBOX            = 0
%CTLCOLOR_EDIT              = 1
%CTLCOLOR_LISTBOX           = 2
%CTLCOLOR_BTN               = 3
%CTLCOLOR_DLG               = 4
%CTLCOLOR_SCROLLBAR         = 5
%CTLCOLOR_STATIC            = 6
%CTLCOLOR_MAX               = 7

%COLOR_SCROLLBAR            = 0
%COLOR_BACKGROUND           = 1
%COLOR_ACTIVECAPTION        = 2
%COLOR_INACTIVECAPTION      = 3
%COLOR_MENU                 = 4
%COLOR_MSGBOX               = 4
%COLOR_WINDOW               = 5
%COLOR_WINDOWFRAME          = 6
%COLOR_MENUTEXT             = 7
%COLOR_MSGBOXTEXT           = 7
%COLOR_WINDOWTEXT           = 8
%COLOR_CAPTIONTEXT          = 9
%COLOR_ACTIVEBORDER         = 10
%COLOR_INACTIVEBORDER       = 11
%COLOR_APPWORKSPACE         = 12
%COLOR_HIGHLIGHT            = 13
%COLOR_HIGHLIGHTTEXT        = 14
%COLOR_BTNFACE              = 15
%COLOR_BTNSHADOW            = 16
%COLOR_GRAYTEXT             = 17
%COLOR_BTNTEXT              = 18
%COLOR_INACTIVECAPTIONTEXT  = 19
%COLOR_BTNHIGHLIGHT         = 20

%COLOR_3DDKSHADOW           = 21
%COLOR_3DLIGHT              = 22
%COLOR_INFOTEXT             = 23
%COLOR_INFOBK               = 24

%COLOR_HOTLIGHT                = 26
%COLOR_GRADIENTACTIVECAPTION   = 27
%COLOR_GRADIENTINACTIVECAPTION = 28
%COLOR_MENUHILIGHT             = 29
%COLOR_MENUBAR                 = 30

%COLOR_DESKTOP              = %COLOR_BACKGROUND
%COLOR_3DFACE               = %COLOR_BTNFACE
%COLOR_3DSHADOW             = %COLOR_BTNSHADOW
%COLOR_3DHIGHLIGHT          = %COLOR_BTNHIGHLIGHT
%COLOR_3DHILIGHT            = %COLOR_BTNHIGHLIGHT
%COLOR_BTNHILIGHT           = %COLOR_BTNHIGHLIGHT

%RES_ICON   = 1
%RES_CURSOR = 2

' GetWindow() Constants
%GW_HWNDFIRST    = 0
%GW_HWNDLAST     = 1
%GW_HWNDNEXT     = 2
%GW_HWNDPREV     = 3
%GW_OWNER        = 4
%GW_CHILD        = 5
%GW_ENABLEDPOPUP = 6
%GW_MAX          = 6

' Menu flags for Add/Check/EnableMenuItem()
%MF_INSERT           = &H00000000
%MF_CHANGE           = &H00000080
%MF_APPEND           = &H00000100
%MF_DELETE           = &H00000200
%MF_REMOVE           = &H00001000

%MF_BYCOMMAND        = &H00000000
%MF_BYPOSITION       = &H00000400

%MF_SEPARATOR        = &H00000800

%MF_USECHECKBITMAPS  = &H00000200

%MF_STRING           = &H00000000
%MF_BITMAP           = &H00000004
%MF_OWNERDRAW        = &H00000100

%MF_POPUP            = &H00000010
%MF_MENUBARBREAK     = &H00000020
%MF_MENUBREAK        = &H00000040

%MF_DEFAULT          = &H00001000
%MF_SYSMENU          = &H00002000
%MF_HELP             = &H00004000
%MF_RIGHTJUSTIFY     = &H00004000
%MF_MOUSESELECT      = &H00008000

%MF_END              = &H00000080

%MFT_STRING        = %MF_STRING
%MFT_BITMAP        = %MF_BITMAP
%MFT_MENUBARBREAK  = %MF_MENUBARBREAK
%MFT_MENUBREAK     = %MF_MENUBREAK
%MFT_OWNERDRAW     = %MF_OWNERDRAW
%MFT_RADIOCHECK    = &H00000200&
%MFT_SEPARATOR     = %MF_SEPARATOR
%MFT_RIGHTORDER    = &H00002000&
%MFT_RIGHTJUSTIFY  = %MF_RIGHTJUSTIFY

' Menu flags for Add/Check/EnableMenuItem
%MFS_GRAYED        = &H00000003&
%MFS_DISABLED      = %MFS_GRAYED
%MFS_CHECKED       = %MF_CHECKED
%MFS_HILITE        = %MF_HILITE
%MFS_ENABLED       = %MF_ENABLED
%MFS_UNCHECKED     = %MF_UNCHECKED
%MFS_UNHILITE      = %MF_UNHILITE
%MFS_DEFAULT       = %MF_DEFAULT

' System Menu Command Values
%SC_SEPARATOR      = &HF00F??

' Obsolete names
%SC_ICON           = %SC_MINIMIZE
%SC_ZOOM           = %SC_MAXIMIZE

' Standard Cursor IDs
%IDC_ARROW         = 32512&
%IDC_IBEAM         = 32513&
%IDC_WAIT          = 32514&
%IDC_CROSS         = 32515&
%IDC_UPARROW       = 32516&
%IDC_SIZE          = 32640&
%IDC_ICON          = 32641&
%IDC_SIZENWSE      = 32642&
%IDC_SIZENESW      = 32643&
%IDC_SIZEWE        = 32644&
%IDC_SIZENS        = 32645&
%IDC_SIZEALL       = 32646&
%IDC_NO            = 32648&
%IDC_HAND          = 32649&
%IDC_APPSTARTING   = 32650&
%IDC_HELP          = 32651&

' OEM Resource Ordinal Numbers
%OBM_CLOSE         = 32754
%OBM_UPARROW       = 32753
%OBM_DNARROW       = 32752
%OBM_RGARROW       = 32751
%OBM_LFARROW       = 32750
%OBM_REDUCE        = 32749
%OBM_ZOOM          = 32748
%OBM_RESTORE       = 32747
%OBM_REDUCED       = 32746
%OBM_ZOOMD         = 32745
%OBM_RESTORED      = 32744
%OBM_UPARROWD      = 32743
%OBM_DNARROWD      = 32742
%OBM_RGARROWD      = 32741
%OBM_LFARROWD      = 32740
%OBM_MNARROW       = 32739
%OBM_COMBO         = 32738
%OBM_UPARROWI      = 32737
%OBM_DNARROWI      = 32736
%OBM_RGARROWI      = 32735
%OBM_LFARROWI      = 32734

%OBM_OLD_CLOSE     = 32767
%OBM_SIZE          = 32766
%OBM_OLD_UPARROW   = 32765
%OBM_OLD_DNARROW   = 32764
%OBM_OLD_RGARROW   = 32763
%OBM_OLD_LFARROW   = 32762
%OBM_BTSIZE        = 32761
%OBM_CHECK         = 32760
%OBM_CHECKBOXES    = 32759
%OBM_BTNCORNERS    = 32758
%OBM_OLD_REDUCE    = 32757
%OBM_OLD_ZOOM      = 32756
%OBM_OLD_RESTORE   = 32755

%OCR_NORMAL        = 32512
%OCR_IBEAM         = 32513
%OCR_WAIT          = 32514
%OCR_CROSS         = 32515
%OCR_UP            = 32516
%OCR_SIZE        = 32640   ' OBSOLETE: use %OCR_SIZEALL
%OCR_ICON        = 32641   ' OBSOLETE: use %OCR_NORMAL
%OCR_SIZENWSE    = 32642
%OCR_SIZENESW    = 32643
%OCR_SIZEWE      = 32644
%OCR_SIZENS      = 32645
%OCR_SIZEALL     = 32646
%OCR_ICOCUR      = 32647   ' OBSOLETE: use %OIC_WINLOGO
%OCR_NO          = 32648
%OCR_HAND        = 32649
%OCR_APPSTARTING = 32650

%OIC_SAMPLE      = 32512
%OIC_HAND        = 32513
%OIC_QUES        = 32514
%OIC_BANG        = 32515
%OIC_NOTE        = 32516
%OIC_WINLOGO     = 32517
%OIC_WARNING     = %OIC_BANG
%OIC_ERROR       = %OIC_HAND
%OIC_INFORMATION = %OIC_NOTE
%OIC_SHIELD      = 32518

%ORD_LANGDRIVER    = 1 ' The ordinal number for the entry point of
' language drivers.

' Standard Icon IDs
%IDI_APPLICATION   = 32512&
%IDI_HAND          = 32513&
%IDI_ERROR         = 32513&
%IDI_QUESTION      = 32514&
%IDI_EXCLAMATION   = 32515&
%IDI_WARNING       = 32515&
%IDI_ASTERISK      = 32516&
%IDI_INFORMATION   = 32516&
%IDI_WINLOGO       = 32517&
%IDI_SHIELD        = 32518
%IDI_WARNING     = %IDI_EXCLAMATION
%IDI_ERROR       = %IDI_HAND
%IDI_INFORMATION = %IDI_ASTERISK

#IF NOT %DEF(%IDTIMEOUT)
%IDTIMEOUT  = 32000
#ENDIF

' Control Manager Structures and Definitions

' Edit Control Notification Codes
%EN_ALIGN_LTR_EC   = &H0700
%EN_ALIGN_RTL_EC   = &H0701

' Edit Control Messages
%EM_GETSEL              = &HB0
%EM_SETSEL              = &HB1
%EM_GETRECT             = &HB2
%EM_SETRECT             = &HB3
%EM_SETRECTNP           = &HB4
%EM_SCROLL              = &HB5
%EM_LINESCROLL          = &HB6
%EM_SCROLLCARET         = &HB7
%EM_GETMODIFY           = &HB8
%EM_SETMODIFY           = &HB9
%EM_GETLINECOUNT        = &HBA
%EM_LINEINDEX           = &HBB
%EM_SETHANDLE           = &HBC
%EM_GETHANDLE           = &HBD
%EM_GETTHUMB            = &HBE
%EM_LINELENGTH          = &HC1
%EM_REPLACESEL          = &HC2
%EM_GETLINE             = &HC4
%EM_LIMITTEXT           = &HC5
%EM_CANUNDO             = &HC6
%EM_UNDO                = &HC7
%EM_FMTLINES            = &HC8
%EM_LINEFROMCHAR        = &HC9
%EM_SETTABSTOPS         = &HCB
%EM_SETPASSWORDCHAR     = &HCC
%EM_EMPTYUNDOBUFFER     = &HCD
%EM_GETFIRSTVISIBLELINE = &HCE
%EM_SETREADONLY         = &HCF
%EM_SETWORDBREAKPROC    = &HD0
%EM_GETWORDBREAKPROC    = &HD1
%EM_GETPASSWORDCHAR     = &HD2
%EM_SETMARGINS          = &HD3
%EM_GETMARGINS          = &HD4
%EM_SETLIMITTEXT        = %EM_LIMITTEXT
%EM_GETLIMITTEXT        = &HD5
%EM_POSFROMCHAR         = &HD6
%EM_CHARFROMPOS         = &HD7
%EM_SETIMESTATUS        = &HD8
%EM_GETIMESTATUS        = &HD9

' EDITWORDBREAKPROC code values
%WB_LEFT         = 0
%WB_RIGHT        = 1
%WB_ISDELIMITER  = 2

' Button Control Messages
%BST_UNCHECKED      = &H00
%BST_CHECKED        = &H01
%BST_INDETERMINATE  = &H02
%BST_PUSHED         = &H04

%BM_GETCHECK  = &H00F0
%BM_SETCHECK  = &H00F1
%BM_GETSTATE  = &H00F2
%BM_SETSTATE  = &H00F3
%BM_SETSTYLE  = &H00F4
%BM_CLICK     = &H00F5
%BM_GETIMAGE  = &H00F6
%BM_SETIMAGE  = &H00F7

' Static Control Messages
%STM_SETICON    = &H170
%STM_GETICON    = &H171
%STM_SETIMAGE   = &H172
%STM_GETIMAGE   = &H173
%STM_MSGMAX     = &H174

%STN_CLICKED    = 0
%STN_DBLCLK     = 1
%STN_ENABLE     = 2
%STN_DISABLE    = 3

%WC_DIALOG      = &H8002??

' Get/SetWindowWord/Long offsets for use with WC_DIALOG windows
%DWL_MSGRESULT  = 0
%DWL_DLGPROC    = 4
%DWL_USER       = 8

' DlgDirList, DlgDirListComboBox flags values
%DDL_READWRITE     = &H0000
%DDL_READONLY      = &H0001
%DDL_HIDDEN        = &H0002
%DDL_SYSTEM        = &H0004
%DDL_DIRECTORY     = &H0010
%DDL_ARCHIVE       = &H0020

%DDL_POSTMSGS      = &H2000
%DDL_DRIVES        = &H4000
%DDL_EXCLUSIVE     = &H8000??

%DS_SHELLFONT        = (%DS_SETFONT OR %DS_FIXEDSYS)

%DM_GETDEFID      = %WM_USER + 0
%DM_SETDEFID      = %WM_USER + 1
%DM_REPOSITION    = %WM_USER + 2
%DC_HASDEFID      = &H534B

' Listbox Return Values
%LB_CTLCODE  = 0
%LB_OKAY     = 0
%LB_ERR      = -1
%LB_ERRSPACE = -2

' Listbox messages
%LB_ADDSTRING          = &H180
%LB_INSERTSTRING       = &H181
%LB_DELETESTRING       = &H182
%LB_SELITEMRANGEEX     = &H183
%LB_RESETCONTENT       = &H184
%LB_SETSEL             = &H185
%LB_SETCURSEL          = &H186
%LB_GETSEL             = &H187
%LB_GETCURSEL          = &H188
%LB_GETTEXT            = &H189
%LB_GETTEXTLEN         = &H18A
%LB_GETCOUNT           = &H18B
%LB_SELECTSTRING       = &H18C
%LB_DIR                = &H18D
%LB_GETTOPINDEX        = &H18E
%LB_FINDSTRING         = &H18F
%LB_GETSELCOUNT        = &H190
%LB_GETSELITEMS        = &H191
%LB_SETTABSTOPS        = &H192
%LB_GETHORIZONTALEXTENT= &H193
%LB_SETHORIZONTALEXTENT= &H194
%LB_SETCOLUMNWIDTH     = &H195
%LB_ADDFILE            = &H196
%LB_SETTOPINDEX        = &H197
%LB_GETITEMRECT        = &H198
%LB_GETITEMDATA        = &H199
%LB_SETITEMDATA        = &H19A
%LB_SELITEMRANGE       = &H19B
%LB_SETANCHORINDEX     = &H19C
%LB_GETANCHORINDEX     = &H19D
%LB_SETCARETINDEX      = &H19E
%LB_GETCARETINDEX      = &H19F
%LB_SETITEMHEIGHT      = &H1A0
%LB_GETITEMHEIGHT      = &H1A1
%LB_FINDSTRINGEXACT    = &H1A2
%LB_SETLOCALE          = &H1A5
%LB_GETLOCALE          = &H1A6
%LB_SETCOUNT           = &H1A7
%LB_INITSTORAGE        = &H1A8
%LB_ITEMFROMPOINT      = &H1A9
%LB_MULTIPLEADDSTRING  = &H1B1
%LB_GETLISTBOXINFO     = &H1B2
%LB_MSGMAX             = &H1B3  ' depends on Windows version

%LBS_COMBOBOX          = &H8000??

' Combo Box return Values
%CB_OKAY       = 0
%CB_ERR        = -1
%CB_ERRSPACE   = -2

' Combo Box Notification Codes
%CBN_SELENDCANCEL  = 10

' Combo Box messages
%CB_GETEDITSEL              = &H140
%CB_LIMITTEXT               = &H141
%CB_SETEDITSEL              = &H142
%CB_ADDSTRING               = &H143
%CB_DELETESTRING            = &H144
%CB_DIR                     = &H145
%CB_GETCOUNT                = &H146
%CB_GETCURSEL               = &H147
%CB_GETLBTEXT               = &H148
%CB_GETLBTEXTLEN            = &H149
%CB_INSERTSTRING            = &H14A
%CB_RESETCONTENT            = &H14B
%CB_FINDSTRING              = &H14C
%CB_SELECTSTRING            = &H14D
%CB_SETCURSEL               = &H14E
%CB_SHOWDROPDOWN            = &H14F
%CB_GETITEMDATA             = &H150
%CB_SETITEMDATA             = &H151
%CB_GETDROPPEDCONTROLRECT   = &H152
%CB_SETITEMHEIGHT           = &H153
%CB_GETITEMHEIGHT           = &H154
%CB_SETEXTENDEDUI           = &H155
%CB_GETEXTENDEDUI           = &H156
%CB_GETDROPPEDSTATE         = &H157
%CB_FINDSTRINGEXACT         = &H158
%CB_SETLOCALE               = &H159
%CB_GETLOCALE               = &H15A
%CB_GETTOPINDEX             = &H15B
%CB_SETTOPINDEX             = &H15C
%CB_GETHORIZONTALEXTENT     = &H15D
%CB_SETHORIZONTALEXTENT     = &H15E
%CB_GETDROPPEDWIDTH         = &H15F
%CB_SETDROPPEDWIDTH         = &H160
%CB_INITSTORAGE             = &H161
%CB_MULTIPLEADDSTRING     = &H163
%CB_GETCOMBOBOXINFO       = &H164
%CB_MSGMAX                = &H165  ' depends on Windows version

' Scroll bar messages
%SBM_SETPOS           = &H00E0 ' not in win3.1
%SBM_GETPOS           = &H00E1 ' not in win3.1
%SBM_SETRANGE         = &H00E2 ' not in win3.1
%SBM_SETRANGEREDRAW   = &H00E6 ' not in win3.1
%SBM_GETRANGE         = &H00E3 ' not in win3.1
%SBM_ENABLE_ARROWS    = &H00E4 ' not in win3.1
%SBM_SETSCROLLINFO    = &H00E9
%SBM_GETSCROLLINFO    = &H00EA
%SBM_GETSCROLLBARINFO = &H00EB

%GR_GDIOBJECTS  = 0  ' Count of GDI objects
%GR_USEROBJECTS = 1  ' Count of USER objects
%GR_GDIOBJECTS_PEAK  = 2       ' Peak count of GDI objects
%GR_USEROBJECTS_PEAK = 4       ' Peak count of USER objects
%GR_GLOBAL           = &HFFFFFFFE???   ' ((HANDLE)-2)

%MDIS_ALLCHILDSTYLES = &H1

' wParam values for WM_MDITILE and WM_MDICASCADE messages.
%MDITILE_VERTICAL     = &H0
%MDITILE_HORIZONTAL   = &H1
%MDITILE_SKIPDISABLED = &H2
%MDITILE_ZORDER       = &H4

' Commands to pass WinHelp()
%HELP_CONTEXT       = &H00000001   ' Display topic in ulTopic
%HELP_QUIT          = &H00000002   ' Terminate help
%HELP_INDEX         = &H00000003   ' Display index
%HELP_CONTENTS      = &H00000003
%HELP_HELPONHELP    = &H00000004   ' Display help on using help
%HELP_SETINDEX      = &H00000005   ' Set current Index for multi index help
%HELP_SETCONTENTS   = &H00000005
%HELP_CONTEXTPOPUP  = &H00000008
%HELP_FORCEFILE     = &H00000009
%HELP_KEY           = &H00000101   ' Display topic for keyword in offabData
%HELP_COMMAND       = &H00000102
%HELP_PARTIALKEY    = &H00000105
%HELP_MULTIKEY      = &H00000201
%HELP_SETWINPOS     = &H00000203
%HELP_CONTEXTMENU   = &H0000000a
%HELP_FINDER        = &H0000000b
%HELP_WM_HELP       = &H0000000c
%HELP_SETPOPUP_POS  = &H0000000d

%HELP_TCARD              = &H00008000
%HELP_TCARD_DATA         = &H00000010
%HELP_TCARD_OTHER_CALLER = &H00000011

' These are in winhelp.h in Win95.
%IDH_NO_HELP             = 28440
%IDH_MISSING_CONTEXT     = 28441 ' Control doesn't have matching help context
%IDH_GENERIC_HELP_BUTTON = 28442 ' Property sheet help button
%IDH_OK                  = 28443
%IDH_CANCEL              = 28444
%IDH_HELP                = 28445

' Parameter for SystemParametersInfo()
%SPI_GETBEEP                 = &H0001
%SPI_SETBEEP                 = &H0002
%SPI_GETMOUSE                = &H0003
%SPI_SETMOUSE                = &H0004
%SPI_GETBORDER               = &H0005
%SPI_SETBORDER               = &H0006
%SPI_GETKEYBOARDSPEED        = &H000A
%SPI_SETKEYBOARDSPEED        = &H000B
%SPI_LANGDRIVER              = &H000C
%SPI_ICONHORIZONTALSPACING   = &H000D
%SPI_GETSCREENSAVETIMEOUT    = &H000E
%SPI_SETSCREENSAVETIMEOUT    = &H000F
%SPI_GETSCREENSAVEACTIVE     = &H0010
%SPI_SETSCREENSAVEACTIVE     = &H0011
%SPI_GETGRIDGRANULARITY      = &H0012
%SPI_SETGRIDGRANULARITY      = &H0013
%SPI_SETDESKWALLPAPER        = &H0014
%SPI_SETDESKPATTERN          = &H0015
%SPI_GETKEYBOARDDELAY        = &H0016
%SPI_SETKEYBOARDDELAY        = &H0017
%SPI_ICONVERTICALSPACING     = &H0018
%SPI_GETICONTITLEWRAP        = &H0019
%SPI_SETICONTITLEWRAP        = &H001A
%SPI_GETMENUDROPALIGNMENT    = &H001B
%SPI_SETMENUDROPALIGNMENT    = &H001C
%SPI_SETDOUBLECLKWIDTH       = &H001D
%SPI_SETDOUBLECLKHEIGHT      = &H001E
%SPI_GETICONTITLELOGFONT     = &H001F
%SPI_SETDOUBLECLICKTIME      = &H0020
%SPI_SETMOUSEBUTTONSWAP      = &H0021
%SPI_SETICONTITLELOGFONT     = &H0022
%SPI_GETFASTTASKSWITCH       = &H0023
%SPI_SETFASTTASKSWITCH       = &H0024
%SPI_SETDRAGFULLWINDOWS      = &H0025
%SPI_GETDRAGFULLWINDOWS      = &H0026
%SPI_GETNONCLIENTMETRICS     = &H0029
%SPI_SETNONCLIENTMETRICS     = &H002A
%SPI_GETMINIMIZEDMETRICS     = &H002B
%SPI_SETMINIMIZEDMETRICS     = &H002C
%SPI_GETICONMETRICS          = &H002D
%SPI_SETICONMETRICS          = &H002E
%SPI_SETWORKAREA             = &H002F
%SPI_GETWORKAREA             = &H0030
%SPI_SETPENWINDOWS           = &H0031

%SPI_GETHIGHCONTRAST         = &H0042
%SPI_SETHIGHCONTRAST         = &H0043
%SPI_GETKEYBOARDPREF         = &H0044
%SPI_SETKEYBOARDPREF         = &H0045
%SPI_GETSCREENREADER         = &H0046
%SPI_SETSCREENREADER         = &H0047
%SPI_GETANIMATION            = &H0048
%SPI_SETANIMATION            = &H0049
%SPI_GETFONTSMOOTHING        = &H004A
%SPI_SETFONTSMOOTHING        = &H004B
%SPI_SETDRAGWIDTH            = &H004C
%SPI_SETDRAGHEIGHT           = &H004D
%SPI_SETHANDHELD             = &H004E
%SPI_GETLOWPOWERTIMEOUT      = &H004F
%SPI_GETPOWEROFFTIMEOUT      = &H0050
%SPI_SETLOWPOWERTIMEOUT      = &H0051
%SPI_SETPOWEROFFTIMEOUT      = &H0052
%SPI_GETLOWPOWERACTIVE       = &H0053
%SPI_GETPOWEROFFACTIVE       = &H0054
%SPI_SETLOWPOWERACTIVE       = &H0055
%SPI_SETPOWEROFFACTIVE       = &H0056
%SPI_SETCURSORS              = &H0057
%SPI_SETICONS                = &H0058
%SPI_GETDEFAULTINPUTLANG     = &H0059
%SPI_SETDEFAULTINPUTLANG     = &H005A
%SPI_SETLANGTOGGLE           = &H005B
%SPI_GETWINDOWSEXTENSION     = &H005C
%SPI_SETMOUSETRAILS          = &H005D
%SPI_GETMOUSETRAILS          = &H005E
%SPI_SETSCREENSAVERRUNNING   = &H0061
%SPI_SCREENSAVERRUNNING     = %SPI_SETSCREENSAVERRUNNING
%SPI_GETFILTERKEYS          = &H0032
%SPI_SETFILTERKEYS          = &H0033
%SPI_GETTOGGLEKEYS          = &H0034
%SPI_SETTOGGLEKEYS          = &H0035
%SPI_GETMOUSEKEYS           = &H0036
%SPI_SETMOUSEKEYS           = &H0037
%SPI_GETSHOWSOUNDS          = &H0038
%SPI_SETSHOWSOUNDS          = &H0039
%SPI_GETSTICKYKEYS          = &H003A
%SPI_SETSTICKYKEYS          = &H003B
%SPI_GETACCESSTIMEOUT       = &H003C
%SPI_SETACCESSTIMEOUT       = &H003D
%SPI_GETSERIALKEYS          = &H003E
%SPI_SETSERIALKEYS          = &H003F
%SPI_GETSOUNDSENTRY         = &H0040
%SPI_SETSOUNDSENTRY         = &H0041
%SPI_GETSNAPTODEFBUTTON     = &H005F
%SPI_SETSNAPTODEFBUTTON     = &H0060
%SPI_GETMOUSEHOVERWIDTH     = &H0062
%SPI_SETMOUSEHOVERWIDTH     = &H0063
%SPI_GETMOUSEHOVERHEIGHT    = &H0064
%SPI_SETMOUSEHOVERHEIGHT    = &H0065
%SPI_GETMOUSEHOVERTIME      = &H0066
%SPI_SETMOUSEHOVERTIME      = &H0067
%SPI_GETWHEELSCROLLLINES    = &H0068
%SPI_SETWHEELSCROLLLINES    = &H0069
%SPI_GETMENUSHOWDELAY       = &H006A
%SPI_SETMENUSHOWDELAY       = &H006B

%SPI_GETWHEELSCROLLCHARS   = &H006C
%SPI_SETWHEELSCROLLCHARS   = &H006D

%SPI_GETSHOWIMEUI          = &H006E
%SPI_SETSHOWIMEUI          = &H006F

%SPI_GETMOUSESPEED         = &H0070
%SPI_SETMOUSESPEED         = &H0071
%SPI_GETSCREENSAVERRUNNING = &H0072
%SPI_GETDESKWALLPAPER      = &H0073

%SPI_GETAUDIODESCRIPTION   = &H0074
%SPI_SETAUDIODESCRIPTION   = &H0075

%SPI_GETSCREENSAVESECURE   = &H0076
%SPI_SETSCREENSAVESECURE   = &H0077

%SPI_GETHUNGAPPTIMEOUT           = &H0078
%SPI_SETHUNGAPPTIMEOUT           = &H0079
%SPI_GETWAITTOKILLTIMEOUT        = &H007A
%SPI_SETWAITTOKILLTIMEOUT        = &H007B
%SPI_GETWAITTOKILLSERVICETIMEOUT = &H007C
%SPI_SETWAITTOKILLSERVICETIMEOUT = &H007D
%SPI_GETMOUSEDOCKTHRESHOLD       = &H007E
%SPI_SETMOUSEDOCKTHRESHOLD       = &H007F
%SPI_GETPENDOCKTHRESHOLD         = &H0080
%SPI_SETPENDOCKTHRESHOLD         = &H0081
%SPI_GETWINARRANGING             = &H0082
%SPI_SETWINARRANGING             = &H0083
%SPI_GETMOUSEDRAGOUTTHRESHOLD    = &H0084
%SPI_SETMOUSEDRAGOUTTHRESHOLD    = &H0085
%SPI_GETPENDRAGOUTTHRESHOLD      = &H0086
%SPI_SETPENDRAGOUTTHRESHOLD      = &H0087
%SPI_GETMOUSESIDEMOVETHRESHOLD   = &H0088
%SPI_SETMOUSESIDEMOVETHRESHOLD   = &H0089
%SPI_GETPENSIDEMOVETHRESHOLD     = &H008A
%SPI_SETPENSIDEMOVETHRESHOLD     = &H008B
%SPI_GETDRAGFROMMAXIMIZE         = &H008C
%SPI_SETDRAGFROMMAXIMIZE         = &H008D
%SPI_GETSNAPSIZING               = &H008E
%SPI_SETSNAPSIZING               = &H008F
%SPI_GETDOCKMOVING               = &H0090
%SPI_SETDOCKMOVING               = &H0091

%SPI_GETACTIVEWINDOWTRACKING         = &H1000
%SPI_SETACTIVEWINDOWTRACKING         = &H1001
%SPI_GETMENUANIMATION                = &H1002
%SPI_SETMENUANIMATION                = &H1003
%SPI_GETCOMBOBOXANIMATION            = &H1004
%SPI_SETCOMBOBOXANIMATION            = &H1005
%SPI_GETLISTBOXSMOOTHSCROLLING       = &H1006
%SPI_SETLISTBOXSMOOTHSCROLLING       = &H1007
%SPI_GETGRADIENTCAPTIONS             = &H1008
%SPI_SETGRADIENTCAPTIONS             = &H1009
%SPI_GETKEYBOARDCUES                 = &H100A
%SPI_SETKEYBOARDCUES                 = &H100B
%SPI_GETMENUUNDERLINES               = %SPI_GETKEYBOARDCUES
%SPI_SETMENUUNDERLINES               = %SPI_SETKEYBOARDCUES
%SPI_GETACTIVEWNDTRKZORDER           = &H100C
%SPI_SETACTIVEWNDTRKZORDER           = &H100D
%SPI_GETHOTTRACKING                  = &H100E
%SPI_SETHOTTRACKING                  = &H100F
%SPI_GETMENUFADE                     = &H1012
%SPI_SETMENUFADE                     = &H1013
%SPI_GETSELECTIONFADE                = &H1014
%SPI_SETSELECTIONFADE                = &H1015
%SPI_GETTOOLTIPANIMATION             = &H1016
%SPI_SETTOOLTIPANIMATION             = &H1017
%SPI_GETTOOLTIPFADE                  = &H1018
%SPI_SETTOOLTIPFADE                  = &H1019
%SPI_GETCURSORSHADOW                 = &H101A
%SPI_SETCURSORSHADOW                 = &H101B
%SPI_GETMOUSESONAR                   = &H101C
%SPI_SETMOUSESONAR                   = &H101D
%SPI_GETMOUSECLICKLOCK               = &H101E
%SPI_SETMOUSECLICKLOCK               = &H101F
%SPI_GETMOUSEVANISH                  = &H1020
%SPI_SETMOUSEVANISH                  = &H1021
%SPI_GETFLATMENU                     = &H1022
%SPI_SETFLATMENU                     = &H1023
%SPI_GETDROPSHADOW                   = &H1024
%SPI_SETDROPSHADOW                   = &H1025
%SPI_GETBLOCKSENDINPUTRESETS         = &H1026
%SPI_SETBLOCKSENDINPUTRESETS         = &H1027

%SPI_GETUIEFFECTS                    = &H103E
%SPI_SETUIEFFECTS                    = &H103F

%SPI_GETDISABLEOVERLAPPEDCONTENT     = &H1040
%SPI_SETDISABLEOVERLAPPEDCONTENT     = &H1041
%SPI_GETCLIENTAREAANIMATION          = &H1042
%SPI_SETCLIENTAREAANIMATION          = &H1043
%SPI_GETCLEARTYPE                    = &H1048
%SPI_SETCLEARTYPE                    = &H1049
%SPI_GETSPEECHRECOGNITION            = &H104A
%SPI_SETSPEECHRECOGNITION            = &H104B

%SPI_GETFOREGROUNDLOCKTIMEOUT        = &H2000
%SPI_SETFOREGROUNDLOCKTIMEOUT        = &H2001
%SPI_GETACTIVEWNDTRKTIMEOUT          = &H2002
%SPI_SETACTIVEWNDTRKTIMEOUT          = &H2003
%SPI_GETFOREGROUNDFLASHCOUNT         = &H2004
%SPI_SETFOREGROUNDFLASHCOUNT         = &H2005
%SPI_GETCARETWIDTH                   = &H2006
%SPI_SETCARETWIDTH                   = &H2007

%SPI_GETMOUSECLICKLOCKTIME           = &H2008
%SPI_SETMOUSECLICKLOCKTIME           = &H2009
%SPI_GETFONTSMOOTHINGTYPE            = &H200A
%SPI_SETFONTSMOOTHINGTYPE            = &H200B

' constants for SPI_GETFONTSMOOTHINGTYPE and SPI_SETFONTSMOOTHINGTYPE:
%FE_FONTSMOOTHINGSTANDARD            = &H0001
%FE_FONTSMOOTHINGCLEARTYPE           = &H0002
%FE_FONTSMOOTHINGDOCKING             = &H8000??

%SPI_GETFONTSMOOTHINGCONTRAST        = &H200C
%SPI_SETFONTSMOOTHINGCONTRAST        = &H200D

%SPI_GETFOCUSBORDERWIDTH             = &H200E
%SPI_SETFOCUSBORDERWIDTH             = &H200F
%SPI_GETFOCUSBORDERHEIGHT            = &H2010
%SPI_SETFOCUSBORDERHEIGHT            = &H2011

%SPI_GETFONTSMOOTHINGORIENTATION     = &H2012
%SPI_SETFONTSMOOTHINGORIENTATION     = &H2013

' constants for SPI_GETFONTSMOOTHINGORIENTATION and SPI_SETFONTSMOOTHINGORIENTATION:
%FE_FONTSMOOTHINGORIENTATIONBGR   = &H0000
%FE_FONTSMOOTHINGORIENTATIONRGB   = &H0001

%SPI_GETMINIMUMHITRADIUS             = &H2014
%SPI_SETMINIMUMHITRADIUS             = &H2015
%SPI_GETMESSAGEDURATION              = &H2016
%SPI_SETMESSAGEDURATION              = &H2017

' Return values for ChangeDisplaySettings
%DISP_CHANGE_SUCCESSFUL    =  0
%DISP_CHANGE_RESTART       =  1
%DISP_CHANGE_FAILED        = -1
%DISP_CHANGE_BADMODE       = -2
%DISP_CHANGE_NOTUPDATED    = -3
%DISP_CHANGE_BADFLAGS      = -4
%DISP_CHANGE_BADPARAM      = -5
%DISP_CHANGE_BADDUALVIEW   = -6

' dwFlags for SetWinEventHook
%WINEVENT_OUTOFCONTEXT   = &H0000  ' Events are ASYNC
%WINEVENT_SKIPOWNTHREAD  = &H0001  ' Don't call back for events on installer's thread
%WINEVENT_SKIPOWNPROCESS = &H0002  ' Don't call back for events on installer's process
%WINEVENT_INCONTEXT      = &H0004  ' Events are SYNC, this causes your dll to be injected into every process

' idObject values for WinEventProc and NotifyWinEvent
'
' hwnd + idObject can be used with OLEACC.DLL's OleGetObjectFromWindow()
' to get an interface pointer to the container.  indexChild is the item
' within the container in question.  Setup a VARIANT with vt VT_I4 and
' lVal the indexChild and pass that in to all methods.  Then you
' are raring to go.
'
' Common object IDs (cookies, only for sending WM_GETOBJECT to get at the
' thing in question).  Positive IDs are reserved for apps (app specific),
' negative IDs are system things and are global, 0 means "just little old
' me".
'
%CHILDID_SELF      = 0
%INDEXID_OBJECT    = 0
%INDEXID_CONTAINER = 0

' Reserved IDs for system objects
%OBJID_WINDOW            = &H00000000
%OBJID_SYSMENU           = &HFFFFFFFF???
%OBJID_TITLEBAR          = &HFFFFFFFE???
%OBJID_MENU              = &HFFFFFFFD???
%OBJID_CLIENT            = &HFFFFFFFC???
%OBJID_VSCROLL           = &HFFFFFFFB???
%OBJID_HSCROLL           = &HFFFFFFFA???
%OBJID_SIZEGRIP          = &HFFFFFFF9???
%OBJID_CARET             = &HFFFFFFF8???
%OBJID_CURSOR            = &HFFFFFFF7???
%OBJID_ALERT             = &HFFFFFFF6???
%OBJID_SOUND             = &HFFFFFFF5???
%OBJID_QUERYCLASSNAMEIDX = &HFFFFFFF4???
%OBJID_NATIVEOM          = &HFFFFFFF0???

' EVENT DEFINITION
%EVENT_MIN           = &H00000001
%EVENT_MAX           = &H7FFFFFFF

%EVENT_SYSTEM_SOUND              = &H0001
%EVENT_SYSTEM_ALERT              = &H0002
%EVENT_SYSTEM_FOREGROUND         = &H0003
%EVENT_SYSTEM_MENUSTART          = &H0004
%EVENT_SYSTEM_MENUEND            = &H0005
%EVENT_SYSTEM_MENUPOPUPSTART     = &H0006
%EVENT_SYSTEM_MENUPOPUPEND       = &H0007
%EVENT_SYSTEM_CAPTURESTART       = &H0008
%EVENT_SYSTEM_CAPTUREEND         = &H0009
%EVENT_SYSTEM_MOVESIZESTART      = &H000A
%EVENT_SYSTEM_MOVESIZEEND        = &H000B
%EVENT_SYSTEM_CONTEXTHELPSTART   = &H000C
%EVENT_SYSTEM_CONTEXTHELPEND     = &H000D
%EVENT_SYSTEM_DRAGDROPSTART      = &H000E
%EVENT_SYSTEM_DRAGDROPEND        = &H000F
%EVENT_SYSTEM_DIALOGSTART        = &H0010
%EVENT_SYSTEM_DIALOGEND          = &H0011
%EVENT_SYSTEM_SCROLLINGSTART     = &H0012
%EVENT_SYSTEM_SCROLLINGEND       = &H0013
%EVENT_SYSTEM_SWITCHSTART        = &H0014
%EVENT_SYSTEM_SWITCHEND          = &H0015
%EVENT_SYSTEM_MINIMIZESTART      = &H0016
%EVENT_SYSTEM_MINIMIZEEND        = &H0017

%EVENT_CONSOLE_CARET             = &H4001
%EVENT_CONSOLE_UPDATE_REGION     = &H4002
%EVENT_CONSOLE_UPDATE_SIMPLE     = &H4003
%EVENT_CONSOLE_UPDATE_SCROLL     = &H4004
%EVENT_CONSOLE_LAYOUT            = &H4005
%EVENT_CONSOLE_START_APPLICATION = &H4006
%EVENT_CONSOLE_END_APPLICATION   = &H4007

' Flags for EVENT_CONSOLE_START/END_APPLICATION.
%CONSOLE_APPLICATION_16BIT       = &H0001

' Flags for EVENT_CONSOLE_CARET
%CONSOLE_CARET_SELECTION         = &H0001
%CONSOLE_CARET_VISIBLE           = &H0002

' Object events
%EVENT_OBJECT_CREATE                 = &H08000  ' hwnd + ID + idChild is created item
%EVENT_OBJECT_DESTROY                = &H08001  ' hwnd + ID + idChild is destroyed item
%EVENT_OBJECT_SHOW                   = &H08002  ' hwnd + ID + idChild is shown item
%EVENT_OBJECT_HIDE                   = &H08003  ' hwnd + ID + idChild is hidden item
%EVENT_OBJECT_REORDER                = &H08004  ' hwnd + ID + idChild is parent of zordering children

%EVENT_OBJECT_FOCUS                  = &H08005  ' hwnd + ID + idChild is focused item
%EVENT_OBJECT_SELECTION              = &H08006  ' hwnd + ID + idChild is selected item (if only one), or idChild is OBJID_WINDOW if complex
%EVENT_OBJECT_SELECTIONADD           = &H08007  ' hwnd + ID + idChild is item added
%EVENT_OBJECT_SELECTIONREMOVE        = &H08008  ' hwnd + ID + idChild is item removed
%EVENT_OBJECT_SELECTIONWITHIN        = &H08009  ' hwnd + ID + idChild is parent of changed selected items

%EVENT_OBJECT_STATECHANGE            = &H0800A  ' hwnd + ID + idChild is item w/ state change

%EVENT_OBJECT_LOCATIONCHANGE         = &H0800B  ' hwnd + ID + idChild is moved/sized item

%EVENT_OBJECT_NAMECHANGE             = &H0800C  ' hwnd + ID + idChild is item w/ name change
%EVENT_OBJECT_DESCRIPTIONCHANGE      = &H0800D  ' hwnd + ID + idChild is item w/ desc change
%EVENT_OBJECT_VALUECHANGE            = &H0800E  ' hwnd + ID + idChild is item w/ value change
%EVENT_OBJECT_PARENTCHANGE           = &H0800F  ' hwnd + ID + idChild is item w/ new parent
%EVENT_OBJECT_HELPCHANGE             = &H08010  ' hwnd + ID + idChild is item w/ help change
%EVENT_OBJECT_DEFACTIONCHANGE        = &H08011  ' hwnd + ID + idChild is item w/ def action change
%EVENT_OBJECT_ACCELERATORCHANGE      = &H08012  ' hwnd + ID + idChild is item w/ keybd accel change

%EVENT_OBJECT_INVOKED                = &H8013?? ' hwnd + ID + idChild is item invoked
%EVENT_OBJECT_TEXTSELECTIONCHANGED   = &H8014?? ' hwnd + ID + idChild is item w? test selection change
%EVENT_OBJECT_CONTENTSCROLLED        = &H8015??
%EVENT_SYSTEM_ARRANGMENTPREVIEW      = &H8016??
%EVENT_OBJECT_END                    = &H80FF??

%EVENT_AIA_START                     = &HA000??
%EVENT_AIA_END                       = &HAFFF??

' Child IDs

' System Sounds (idChild of system SOUND notification)
%SOUND_SYSTEM_STARTUP          = 1
%SOUND_SYSTEM_SHUTDOWN         = 2
%SOUND_SYSTEM_BEEP             = 3
%SOUND_SYSTEM_ERROR            = 4
%SOUND_SYSTEM_QUESTION         = 5
%SOUND_SYSTEM_WARNING          = 6
%SOUND_SYSTEM_INFORMATION      = 7
%SOUND_SYSTEM_MAXIMIZE         = 8
%SOUND_SYSTEM_MINIMIZE         = 9
%SOUND_SYSTEM_RESTOREUP        = 10
%SOUND_SYSTEM_RESTOREDOWN      = 11
%SOUND_SYSTEM_APPSTART         = 12
%SOUND_SYSTEM_FAULT            = 13
%SOUND_SYSTEM_APPEND           = 14
%SOUND_SYSTEM_MENUCOMMAND      = 15
%SOUND_SYSTEM_MENUPOPUP        = 16
%CSOUND_SYSTEM                 = 16

' System Alerts (indexChild of system ALERT notification)
%ALERT_SYSTEM_INFORMATIONAL    = 1       ' MB_INFORMATION
%ALERT_SYSTEM_WARNING          = 2       ' MB_WARNING
%ALERT_SYSTEM_ERROR            = 3       ' MB_ERROR
%ALERT_SYSTEM_QUERY            = 4       ' MB_QUESTION
%ALERT_SYSTEM_CRITICAL         = 5       ' HardSysErrBox
%CALERT_SYSTEM                 = 6

%GUI_CARETBLINKING   = &H00000001
%GUI_INMOVESIZE      = &H00000002
%GUI_INMENUMODE      = &H00000004
%GUI_SYSTEMMENUMODE  = &H00000008
%GUI_POPUPMENUMODE   = &H00000010
%GUI_16BITTASK       = &H00000020

#IF NOT %DEF(%NO_STATE_FLAGS)
%STATE_SYSTEM_UNAVAILABLE     = &H00000001  ' Disabled
%STATE_SYSTEM_SELECTED        = &H00000002
%STATE_SYSTEM_FOCUSED         = &H00000004
%STATE_SYSTEM_PRESSED         = &H00000008
%STATE_SYSTEM_CHECKED         = &H00000010
%STATE_SYSTEM_MIXED           = &H00000020  ' 3-state checkbox or toolbar button
%STATE_SYSTEM_INDETERMINATE   = %STATE_SYSTEM_MIXED
%STATE_SYSTEM_READONLY        = &H00000040
%STATE_SYSTEM_HOTTRACKED      = &H00000080
%STATE_SYSTEM_DEFAULT         = &H00000100
%STATE_SYSTEM_EXPANDED        = &H00000200
%STATE_SYSTEM_COLLAPSED       = &H00000400
%STATE_SYSTEM_BUSY            = &H00000800
%STATE_SYSTEM_FLOATING        = &H00001000  ' Children "owned" not "contained" by parent
%STATE_SYSTEM_MARQUEED        = &H00002000
%STATE_SYSTEM_ANIMATED        = &H00004000
%STATE_SYSTEM_INVISIBLE       = &H00008000
%STATE_SYSTEM_OFFSCREEN       = &H00010000
%STATE_SYSTEM_SIZEABLE        = &H00020000
%STATE_SYSTEM_MOVEABLE        = &H00040000
%STATE_SYSTEM_SELFVOICING     = &H00080000
%STATE_SYSTEM_FOCUSABLE       = &H00100000
%STATE_SYSTEM_SELECTABLE      = &H00200000
%STATE_SYSTEM_LINKED          = &H00400000
%STATE_SYSTEM_TRAVERSED       = &H00800000
%STATE_SYSTEM_MULTISELECTABLE = &H01000000  ' Supports multiple selection
%STATE_SYSTEM_EXTSELECTABLE   = &H02000000  ' Supports extended selection
%STATE_SYSTEM_ALERT_LOW       = &H04000000  ' This information is of low priority
%STATE_SYSTEM_ALERT_MEDIUM    = &H08000000  ' This information is of medium priority
%STATE_SYSTEM_ALERT_HIGH      = &H10000000  ' This information is of high priority
%STATE_SYSTEM_PROTECTED       = &H20000000  ' access to this is restricted
%STATE_SYSTEM_VALID           = &H3FFFFFFF
#ENDIF

%CCHILDREN_TITLEBAR   = 5
%CCHILDREN_SCROLLBAR  = 5

%CURSOR_SHOWING    = &H00000001

%WS_ACTIVECAPTION  = &H0001
' The input is in the regular message flow, the app is required to call
' DefWindowProc so that the system can perform clean ups.
%RIM_INPUT     = 0

' The input is sink only. The app is expected
' to behave nicely, honoring RIM_FOREGROUND etc.
%RIM_INPUTSINK = 1

' Type of the raw input
%RIM_TYPEMOUSE    = 0
%RIM_TYPEKEYBOARD = 1
%RIM_TYPEHID      = 2
' Define the mouse button state indicators.

%RI_MOUSE_LEFT_BUTTON_DOWN   = &H0001  ' Left Button changed to down.
%RI_MOUSE_LEFT_BUTTON_UP     = &H0002  ' Left Button changed to up.
%RI_MOUSE_RIGHT_BUTTON_DOWN  = &H0004  ' Right Button changed to down.
%RI_MOUSE_RIGHT_BUTTON_UP    = &H0008  ' Right Button changed to up.
%RI_MOUSE_MIDDLE_BUTTON_DOWN = &H0010  ' Middle Button changed to down.
%RI_MOUSE_MIDDLE_BUTTON_UP   = &H0020  ' Middle Button changed to up.

%RI_MOUSE_BUTTON_1_DOWN      = %RI_MOUSE_LEFT_BUTTON_DOWN
%RI_MOUSE_BUTTON_1_UP        = %RI_MOUSE_LEFT_BUTTON_UP
%RI_MOUSE_BUTTON_2_DOWN      = %RI_MOUSE_RIGHT_BUTTON_DOWN
%RI_MOUSE_BUTTON_2_UP        = %RI_MOUSE_RIGHT_BUTTON_UP
%RI_MOUSE_BUTTON_3_DOWN      = %RI_MOUSE_MIDDLE_BUTTON_DOWN
%RI_MOUSE_BUTTON_3_UP        = %RI_MOUSE_MIDDLE_BUTTON_UP

%RI_MOUSE_BUTTON_4_DOWN      = &H0040
%RI_MOUSE_BUTTON_4_UP        = &H0080
%RI_MOUSE_BUTTON_5_DOWN      = &H0100
%RI_MOUSE_BUTTON_5_UP        = &H0200

' If usButtonFlags has RI_MOUSE_WHEEL, the wheel delta is stored
' in usButtonData. Take it as a signed value.
%RI_MOUSE_WHEEL              = &H0400

' Define the mouse indicator flags.
%MOUSE_MOVE_RELATIVE      = 0
%MOUSE_MOVE_ABSOLUTE      = 1
%MOUSE_VIRTUAL_DESKTOP    = 2  ' the coordinates are mapped to the virtual desktop
%MOUSE_ATTRIBUTES_CHANGED = 4  ' requery for mouse attributes
%MOUSE_MOVE_NOCOALESCE    = &H08  ' do not coalesce mouse moves

%KEYBOARD_OVERRUN_MAKE_CODE  = &H00FF

' Define the keyboard input data Flags.
%RI_KEY_MAKE             = &H0000
%RI_KEY_BREAK            = &H0001
%RI_KEY_E0               = &H0002
%RI_KEY_E1               = &H0004
%RI_KEY_TERMSRV_SET_LED  = &H0008
%RI_KEY_TERMSRV_SHADOW   = &H0010
' Flags for GetRawInputData
%RID_INPUT  = &H10000003
%RID_HEADER = &H10000005

' Raw Input Device Information
%RIDI_PREPARSEDDATA = &H20000005
%RIDI_DEVICENAME    = &H20000007 ' the return value is the character length, not the byte size
%RIDI_DEVICEINFO    = &H2000000b
%RIDEV_REMOVE       = &H00000001
%RIDEV_EXCLUDE      = &H00000010
%RIDEV_PAGEONLY     = &H00000020
%RIDEV_NOLEGACY     = &H00000030
%RIDEV_CAPTUREMOUSE = &H00000200  ' effective when mouse nolegacy is specified, otherwise it would be an error
%RIDEV_NOHOTKEYS    = &H00000200  ' effective for keyboard.
%RIDEV_EXMODEMASK   = &H000000F0

%WHEEL_DELTA       = 120
%WHEEL_PAGESCROLL  = &HFFFFFFFF??? ' (UINT_MAX)
' XButton values are WORD flags
%XBUTTON1 = &H0001
%XBUTTON2 = &H0002
' Were there to be an XBUTTON3, its value would be &H0004

' LOWORD(wParam) values in WM_*UISTATE*
%UIS_SET        = 1
%UIS_CLEAR      = 2
%UIS_INITIALIZE = 3

' HIWORD(wParam) values in WM_*UISTATE*
%UISF_HIDEFOCUS = &H1
%UISF_HIDEACCEL = &H2
%UISF_ACTIVE    = &H4

' SystemParametersInfo flags
%SPIF_UPDATEINIFILE    = &H1
%SPIF_SENDWININICHANGE = &H2
%SPIF_SENDCHANGE       = %SPIF_SENDWININICHANGE

%ARW_BOTTOMLEFT  = &H0000
%ARW_BOTTOMRIGHT = &H0001
%ARW_TOPLEFT     = &H0002
%ARW_TOPRIGHT    = &H0003
%ARW_STARTMASK   = &H0003
%ARW_STARTRIGHT  = &H0001
%ARW_STARTTOP    = &H0002

%ARW_LEFT        = &H0000
%ARW_RIGHT       = &H0000
%ARW_UP          = &H0004
%ARW_DOWN        = &H0004
%ARW_HIDE        = &H0008

' DDE window messages
%WM_DDE_FIRST       = &H3E0
%WM_DDE_INITIATE    = %WM_DDE_FIRST
%WM_DDE_TERMINATE   = %WM_DDE_FIRST + 1
%WM_DDE_ADVISE      = %WM_DDE_FIRST + 2
%WM_DDE_UNADVISE    = %WM_DDE_FIRST + 3
%WM_DDE_ACK         = %WM_DDE_FIRST + 4
%WM_DDE_DATA        = %WM_DDE_FIRST + 5
%WM_DDE_REQUEST     = %WM_DDE_FIRST + 6
%WM_DDE_POKE        = %WM_DDE_FIRST + 7
%WM_DDE_EXECUTE     = %WM_DDE_FIRST + 8
%WM_DDE_LAST        = %WM_DDE_FIRST + 8

' conversation states (usState)
%XST_NULL            = 0  ' quiescent states
%XST_INCOMPLETE      = 1
%XST_CONNECTED       = 2
%XST_INIT1           = 3  ' mid-initiation states
%XST_INIT2           = 4
%XST_REQSENT         = 5  ' active conversation states
%XST_DATARCVD        = 6
%XST_POKESENT        = 7
%XST_POKEACKRCVD     = 8
%XST_EXECSENT        = 9
%XST_EXECACKRCVD     = 10
%XST_ADVSENT         = 11
%XST_UNADVSENT       = 12
%XST_ADVACKRCVD      = 13
%XST_UNADVACKRCVD    = 14
%XST_ADVDATASENT     = 15
%XST_ADVDATAACKRCVD  = 16

' used in LOWORD(dwData1) of XTYP_ADVREQ callbacks...
%CADV_LATEACK        = &HFFFF??

' conversation status bits (fsStatus)
%ST_CONNECTED   = &H1
%ST_ADVISE      = &H2
%ST_ISLOCAL     = &H4
%ST_BLOCKED     = &H8
%ST_CLIENT      = &H10
%ST_TERMINATED  = &H20
%ST_INLIST      = &H40
%ST_BLOCKNEXT   = &H80
%ST_ISSELF      = &H100

' DDE constants for wStatus field
%DDE_FACK            = &H00008000
%DDE_FBUSY           = &H00004000
%DDE_FDEFERUPD       = &H00004000
%DDE_FACKREQ         = &H00008000
%DDE_FRELEASE        = &H00002000
%DDE_FREQUESTED      = &H00001000
%DDE_FAPPSTATUS      = &H000000FF
%DDE_FNOTPROCESSED   = &H00000000

%DDE_FACKRESERVED    = NOT (%DDE_FACK OR %DDE_FBUSY OR %DDE_FAPPSTATUS)
%DDE_FADVRESERVED    = NOT (%DDE_FACKREQ OR %DDE_FDEFERUPD)
%DDE_FDATRESERVED    = NOT (%DDE_FACKREQ OR %DDE_FRELEASE OR %DDE_FREQUESTED)
%DDE_FPOKRESERVED    = NOT (%DDE_FRELEASE)

' codepage constants
%CP_WINANSI          = 1004  ' default codepage for windows old DDE convs.
%CP_WINUNICODE       = 1200

' transaction types
%XTYPF_NOBLOCK    = &H2     ' CBR_BLOCK will not work
%XTYPF_NODATA     = &H4     ' DDE_FDEFERUPD
%XTYPF_ACKREQ     = &H8     ' DDE_FACKREQ

%XCLASS_MASK         = &H0000FC00
%XCLASS_BOOL         = &H00001000
%XCLASS_DATA         = &H00002000
%XCLASS_FLAGS        = &H00004000
%XCLASS_NOTIFICATION = &H00008000

%XTYP_ERROR            = &H0 OR %XCLASS_NOTIFICATION OR %XTYPF_NOBLOCK
%XTYP_ADVDATA          = &H10 OR %XCLASS_FLAGS
%XTYP_ADVREQ           = &H20 OR %XCLASS_DATA OR %XTYPF_NOBLOCK
%XTYP_ADVSTART         = &H30 OR %XCLASS_BOOL
%XTYP_ADVSTOP          = &H40 OR %XCLASS_NOTIFICATION
%XTYP_EXECUTE          = &H50 OR %XCLASS_FLAGS
%XTYP_CONNECT          = &H60 OR %XCLASS_BOOL OR %XTYPF_NOBLOCK
%XTYP_CONNECT_CONFIRM  = &H70 OR %XCLASS_NOTIFICATION OR %XTYPF_NOBLOCK
%XTYP_XACT_COMPLETE    = &H80 OR %XCLASS_NOTIFICATION
%XTYP_POKE             = &H90 OR %XCLASS_FLAGS
%XTYP_REGISTER         = &HA0 OR %XCLASS_NOTIFICATION OR %XTYPF_NOBLOCK
%XTYP_REQUEST          = &HB0 OR %XCLASS_DATA
%XTYP_DISCONNECT       = &HC0 OR %XCLASS_NOTIFICATION OR %XTYPF_NOBLOCK
%XTYP_UNREGISTER       = &HD0 OR %XCLASS_NOTIFICATION OR %XTYPF_NOBLOCK
%XTYP_WILDCONNECT      = &HE0 OR %XCLASS_DATA OR %XTYPF_NOBLOCK

%XTYP_MASK             = &HF0
%XTYP_SHIFT            = 4  ' shift to turn XTYP_ into an index

' Timeout constants
%TIMEOUT_ASYNC         = &HFFFFFFFF???

' Transaction ID constants
%QID_SYNC              = &HFFFFFFFF???

%CBR_BLOCK             = &HFFFFFFFF???

' Callback filter flags for use with standard apps.
%CBF_FAIL_SELFCONNECTIONS  = &H00001000
%CBF_FAIL_CONNECTIONS      = &H00002000
%CBF_FAIL_ADVISES          = &H00004000
%CBF_FAIL_EXECUTES         = &H00008000
%CBF_FAIL_POKES            = &H00010000
%CBF_FAIL_REQUESTS         = &H00020000
%CBF_FAIL_ALLSVRXACTIONS   = &H0003F000

%CBF_SKIP_CONNECT_CONFIRMS = &H00040000
%CBF_SKIP_REGISTRATIONS    = &H00080000
%CBF_SKIP_UNREGISTRATIONS  = &H00100000
%CBF_SKIP_DISCONNECTS      = &H00200000
%CBF_SKIP_ALLNOTIFICATIONS = &H003C0000

' Application command flags
%APPCMD_CLIENTONLY         = &H00000010&
%APPCMD_FILTERINITS        = &H00000020&
%APPCMD_MASK               = &H00000FF0&

' Application classification flags
%APPCLASS_STANDARD  = &H0&
%APPCLASS_MASK      = &HF&

%EC_ENABLEALL     = 0
%EC_ENABLEONE     = %ST_BLOCKNEXT
%EC_DISABLE       = %ST_BLOCKED
%EC_QUERYWAITING  = 2

%DNS_REGISTER    = &H1
%DNS_UNREGISTER  = &H2
%DNS_FILTERON    = &H4
%DNS_FILTEROFF   = &H8

%HDATA_APPOWNED  = &H1

%DMLERR_NO_ERROR = 0      ' must be 0

%DMLERR_FIRST                = &H4000

%DMLERR_ADVACKTIMEOUT        = &H4000
%DMLERR_BUSY                 = &H4001
%DMLERR_DATAACKTIMEOUT       = &H4002
%DMLERR_DLL_NOT_INITIALIZED  = &H4003
%DMLERR_DLL_USAGE            = &H4004
%DMLERR_EXECACKTIMEOUT       = &H4005
%DMLERR_INVALIDPARAMETER     = &H4006
%DMLERR_LOW_MEMORY           = &H4007
%DMLERR_MEMORY_ERROR         = &H4008
%DMLERR_NOTPROCESSED         = &H4009
%DMLERR_NO_CONV_ESTABLISHED  = &H400A
%DMLERR_POKEACKTIMEOUT       = &H400B
%DMLERR_POSTMSG_FAILED       = &H400C
%DMLERR_REENTRANCY           = &H400D
%DMLERR_SERVER_DIED          = &H400E
%DMLERR_SYS_ERROR            = &H400F
%DMLERR_UNADVACKTIMEOUT      = &H4010
%DMLERR_UNFOUND_QUEUE_ID     = &H4011

%DMLERR_LAST                 = &H4011

%MH_CREATE  = 1
%MH_KEEP    = 2
%MH_DELETE  = 3
%MH_CLEANUP = 4

%MAX_MONITORS      = 4
%APPCLASS_MONITOR  = &H1&
%XTYP_MONITOR      = &HF0 OR %XCLASS_NOTIFICATION OR %XTYPF_NOBLOCK

' Callback filter flags for use with MONITOR apps - 0 implies no monitor callbacks
%MF_HSZ_INFO     = &H1000000
%MF_SENDMSGS     = &H2000000
%MF_POSTMSGS     = &H4000000
%MF_CALLBACKS    = &H8000000
%MF_ERRORS       = &H10000000
%MF_LINKS        = &H20000000
%MF_CONV         = &H40000000

%MF_MASK         = &HFF000000???

%NO_ERROR        = 0 ' dderror

' The configuration registry database operation completed successfully.
%ERROR_SUCCESS                    = 0&

%ERROR_INVALID_FUNCTION           = 1&     ' dderror
%ERROR_FILE_NOT_FOUND             = 2&
%ERROR_PATH_NOT_FOUND             = 3&
%ERROR_TOO_MANY_OPEN_FILES        = 4&
%ERROR_ACCESS_DENIED              = 5&
%ERROR_INVALID_HANDLE             = 6&
%ERROR_ARENA_TRASHED              = 7&
%ERROR_NOT_ENOUGH_MEMORY          = 8&     ' dderror
%ERROR_INVALID_BLOCK              = 9&
%ERROR_BAD_ENVIRONMENT            = 10&
%ERROR_BAD_FORMAT                 = 11&
%ERROR_INVALID_ACCESS             = 12&
%ERROR_INVALID_DATA               = 13&
%ERROR_OUTOFMEMORY                = 14&
%ERROR_INVALID_DRIVE              = 15&
%ERROR_CURRENT_DIRECTORY          = 16&
%ERROR_NOT_SAME_DEVICE            = 17&
%ERROR_NO_MORE_FILES              = 18&
%ERROR_WRITE_PROTECT              = 19&
%ERROR_BAD_UNIT                   = 20&
%ERROR_NOT_READY                  = 21&
%ERROR_BAD_COMMAND                = 22&
%ERROR_CRC                        = 23&
%ERROR_BAD_LENGTH                 = 24&
%ERROR_SEEK                       = 25&
%ERROR_NOT_DOS_DISK               = 26&
%ERROR_SECTOR_NOT_FOUND           = 27&
%ERROR_OUT_OF_PAPER               = 28&
%ERROR_WRITE_FAULT                = 29&
%ERROR_READ_FAULT                 = 30&
%ERROR_GEN_FAILURE                = 31&
%ERROR_SHARING_VIOLATION          = 32&
%ERROR_LOCK_VIOLATION             = 33&
%ERROR_WRONG_DISK                 = 34&
%ERROR_SHARING_BUFFER_EXCEEDED    = 36&
%ERROR_HANDLE_EOF                 = 38&
%ERROR_HANDLE_DISK_FULL           = 39&
%ERROR_NOT_SUPPORTED              = 50&
%ERROR_REM_NOT_LIST               = 51&
%ERROR_DUP_NAME                   = 52&
%ERROR_BAD_NETPATH                = 53&
%ERROR_NETWORK_BUSY               = 54&
%ERROR_DEV_NOT_EXIST              = 55&     ' dderror
%ERROR_TOO_MANY_CMDS              = 56&
%ERROR_ADAP_HDW_ERR               = 57&
%ERROR_BAD_NET_RESP               = 58&
%ERROR_UNEXP_NET_ERR              = 59&
%ERROR_BAD_REM_ADAP               = 60&
%ERROR_PRINTQ_FULL                = 61&
%ERROR_NO_SPOOL_SPACE             = 62&
%ERROR_PRINT_CANCELLED            = 63&
%ERROR_NETNAME_DELETED            = 64&
%ERROR_NETWORK_ACCESS_DENIED      = 65&
%ERROR_BAD_DEV_TYPE               = 66&
%ERROR_BAD_NET_NAME               = 67&
%ERROR_TOO_MANY_NAMES             = 68&
%ERROR_TOO_MANY_SESS              = 69&
%ERROR_SHARING_PAUSED             = 70&
%ERROR_REQ_NOT_ACCEP              = 71&
%ERROR_REDIR_PAUSED               = 72&
%ERROR_FILE_EXISTS                = 80&
%ERROR_CANNOT_MAKE                = 82&
%ERROR_FAIL_I24                   = 83&
%ERROR_OUT_OF_STRUCTURES          = 84&
%ERROR_ALREADY_ASSIGNED           = 85&
%ERROR_INVALID_PASSWORD           = 86&
%ERROR_INVALID_PARAMETER          = 87&     ' dderror
%ERROR_NET_WRITE_FAULT            = 88&
%ERROR_NO_PROC_SLOTS              = 89&
%ERROR_TOO_MANY_SEMAPHORES        = 100&
%ERROR_EXCL_SEM_ALREADY_OWNED     = 101&
%ERROR_SEM_IS_SET                 = 102&
%ERROR_TOO_MANY_SEM_REQUESTS      = 103&
%ERROR_INVALID_AT_INTERRUPT_TIME  = 104&
%ERROR_SEM_OWNER_DIED             = 105&
%ERROR_SEM_USER_LIMIT             = 106&
%ERROR_DISK_CHANGE                = 107&
%ERROR_DRIVE_LOCKED               = 108&
%ERROR_BROKEN_PIPE                = 109&
%ERROR_OPEN_FAILED                = 110&
%ERROR_BUFFER_OVERFLOW            = 111&
%ERROR_DISK_FULL                  = 112&
%ERROR_NO_MORE_SEARCH_HANDLES     = 113&
%ERROR_INVALID_TARGET_HANDLE      = 114&
%ERROR_INVALID_CATEGORY           = 117&
%ERROR_INVALID_VERIFY_SWITCH      = 118&
%ERROR_BAD_DRIVER_LEVEL           = 119&
%ERROR_CALL_NOT_IMPLEMENTED       = 120&
%ERROR_SEM_TIMEOUT                = 121&
%ERROR_INSUFFICIENT_BUFFER        = 122&     ' dderror
%ERROR_INVALID_NAME               = 123&     ' dderror
%ERROR_INVALID_LEVEL              = 124&
%ERROR_NO_VOLUME_LABEL            = 125&
%ERROR_MOD_NOT_FOUND              = 126&
%ERROR_PROC_NOT_FOUND             = 127&
%ERROR_WAIT_NO_CHILDREN           = 128&
%ERROR_CHILD_NOT_COMPLETE         = 129&
%ERROR_DIRECT_ACCESS_HANDLE       = 130&
%ERROR_NEGATIVE_SEEK              = 131&
%ERROR_SEEK_ON_DEVICE             = 132&
%ERROR_IS_JOIN_TARGET             = 133&
%ERROR_IS_JOINED                  = 134&
%ERROR_IS_SUBSTED                 = 135&
%ERROR_NOT_JOINED                 = 136&
%ERROR_NOT_SUBSTED                = 137&
%ERROR_JOIN_TO_JOIN               = 138&
%ERROR_SUBST_TO_SUBST             = 139&
%ERROR_JOIN_TO_SUBST              = 140&
%ERROR_SUBST_TO_JOIN              = 141&
%ERROR_BUSY_DRIVE                 = 142&
%ERROR_SAME_DRIVE                 = 143&
%ERROR_DIR_NOT_ROOT               = 144&
%ERROR_DIR_NOT_EMPTY              = 145&
%ERROR_IS_SUBST_PATH              = 146&
%ERROR_IS_JOIN_PATH               = 147&
%ERROR_PATH_BUSY                  = 148&
%ERROR_IS_SUBST_TARGET            = 149&
%ERROR_SYSTEM_TRACE               = 150&
%ERROR_INVALID_EVENT_COUNT        = 151&
%ERROR_TOO_MANY_MUXWAITERS        = 152&
%ERROR_INVALID_LIST_FORMAT        = 153&
%ERROR_LABEL_TOO_LONG             = 154&
%ERROR_TOO_MANY_TCBS              = 155&
%ERROR_SIGNAL_REFUSED             = 156&
%ERROR_DISCARDED                  = 157&
%ERROR_NOT_LOCKED                 = 158&
%ERROR_BAD_THREADID_ADDR          = 159&
%ERROR_BAD_ARGUMENTS              = 160&
%ERROR_BAD_PATHNAME               = 161&
%ERROR_SIGNAL_PENDING             = 162&
%ERROR_MAX_THRDS_REACHED          = 164&
%ERROR_LOCK_FAILED                = 167&
%ERROR_BUSY                       = 170&
%ERROR_CANCEL_VIOLATION           = 173&
%ERROR_ATOMIC_LOCKS_NOT_SUPPORTED = 174&
%ERROR_INVALID_SEGMENT_NUMBER     = 180&
%ERROR_INVALID_ORDINAL            = 182&
%ERROR_ALREADY_EXISTS             = 183&
%ERROR_INVALID_FLAG_NUMBER        = 186&
%ERROR_SEM_NOT_FOUND              = 187&
%ERROR_INVALID_STARTING_CODESEG   = 188&
%ERROR_INVALID_STACKSEG           = 189&
%ERROR_INVALID_MODULETYPE         = 190&
%ERROR_INVALID_EXE_SIGNATURE      = 191&
%ERROR_EXE_MARKED_INVALID         = 192&
%ERROR_BAD_EXE_FORMAT             = 193&
%ERROR_ITERATED_DATA_EXCEEDS_64k  = 194&
%ERROR_INVALID_MINALLOCSIZE       = 195&
%ERROR_DYNLINK_FROM_INVALID_RING  = 196&
%ERROR_IOPL_NOT_ENABLED           = 197&
%ERROR_INVALID_SEGDPL             = 198&
%ERROR_AUTODATASEG_EXCEEDS_64k    = 199&
%ERROR_RING2SEG_MUST_BE_MOVABLE   = 200&
%ERROR_RELOC_CHAIN_XEEDS_SEGLIM   = 201&
%ERROR_INFLOOP_IN_RELOC_CHAIN     = 202&
%ERROR_ENVVAR_NOT_FOUND           = 203&
%ERROR_NO_SIGNAL_SENT             = 205&
%ERROR_FILENAME_EXCED_RANGE       = 206&
%ERROR_RING2_STACK_IN_USE         = 207&
%ERROR_META_EXPANSION_TOO_LONG    = 208&
%ERROR_INVALID_SIGNAL_NUMBER      = 209&
%ERROR_THREAD_1_INACTIVE          = 210&
%ERROR_LOCKED                     = 212&
%ERROR_TOO_MANY_MODULES           = 214&
%ERROR_NESTING_NOT_ALLOWED        = 215&
%ERROR_EXE_MACHINE_TYPE_MISMATCH  = 216&
%ERROR_BAD_PIPE                   = 230&
%ERROR_PIPE_BUSY                  = 231&
%ERROR_NO_DATA                    = 232&
%ERROR_PIPE_NOT_CONNECTED         = 233&
%ERROR_MORE_DATA                  = 234&     ' dderror
%ERROR_VC_DISCONNECTED            = 240&
%ERROR_INVALID_EA_NAME            = 254&
%ERROR_EA_LIST_INCONSISTENT       = 255&
%WAIT_TIMEOUT                     = 258&
%ERROR_NO_MORE_ITEMS              = 259&
%ERROR_CANNOT_COPY                = 266&
%ERROR_DIRECTORY                  = 267&
%ERROR_EAS_DIDNT_FIT              = 275&
%ERROR_EA_FILE_CORRUPT            = 276&
%ERROR_EA_TABLE_FULL              = 277&
%ERROR_INVALID_EA_HANDLE          = 278&
%ERROR_EAS_NOT_SUPPORTED          = 282&
%ERROR_NOT_OWNER                  = 288&
%ERROR_TOO_MANY_POSTS             = 298&
%ERROR_PARTIAL_COPY               = 299&
%ERROR_OPLOCK_NOT_GRANTED         = 300&
%ERROR_INVALID_OPLOCK_PROTOCOL    = 301&
%ERROR_MR_MID_NOT_FOUND           = 317&
%ERROR_INVALID_ADDRESS            = 487&
%ERROR_ARITHMETIC_OVERFLOW        = 534&
%ERROR_PIPE_CONNECTED             = 535&
%ERROR_PIPE_LISTENING             = 536&
%ERROR_EA_ACCESS_DENIED           = 994&
%ERROR_OPERATION_ABORTED          = 995&
%ERROR_IO_INCOMPLETE              = 996&
%ERROR_IO_PENDING                 = 997&     ' dderror
%ERROR_NOACCESS                   = 998&
%ERROR_SWAPERROR                  = 999&
%ERROR_STACK_OVERFLOW             = 1001&
%ERROR_INVALID_MESSAGE            = 1002&
%ERROR_CAN_NOT_COMPLETE           = 1003&
%ERROR_INVALID_FLAGS              = 1004&
%ERROR_UNRECOGNIZED_VOLUME        = 1005&
%ERROR_FILE_INVALID               = 1006&
%ERROR_FULLSCREEN_MODE            = 1007&
%ERROR_NO_TOKEN                   = 1008&
%ERROR_BADDB                      = 1009&
%ERROR_BADKEY                     = 1010&
%ERROR_CANTOPEN                   = 1011&
%ERROR_CANTREAD                   = 1012&
%ERROR_CANTWRITE                  = 1013&
%ERROR_REGISTRY_RECOVERED         = 1014&
%ERROR_REGISTRY_CORRUPT           = 1015&
%ERROR_REGISTRY_IO_FAILED         = 1016&
%ERROR_NOT_REGISTRY_FILE          = 1017&
%ERROR_KEY_DELETED                = 1018&
%ERROR_NO_LOG_SPACE               = 1019&
%ERROR_KEY_HAS_CHILDREN           = 1020&
%ERROR_CHILD_MUST_BE_VOLATILE     = 1021&
%ERROR_NOTIFY_ENUM_DIR            = 1022&
%ERROR_DEPENDENT_SERVICES_RUNNING = 1051&
%ERROR_INVALID_SERVICE_CONTROL    = 1052&
%ERROR_SERVICE_REQUEST_TIMEOUT    = 1053&
%ERROR_SERVICE_NO_THREAD          = 1054&
%ERROR_SERVICE_DATABASE_LOCKED    = 1055&
%ERROR_SERVICE_ALREADY_RUNNING    = 1056&
%ERROR_INVALID_SERVICE_ACCOUNT    = 1057&
%ERROR_SERVICE_DISABLED           = 1058&
%ERROR_CIRCULAR_DEPENDENCY        = 1059&
%ERROR_SERVICE_DOES_NOT_EXIST     = 1060&
%ERROR_SERVICE_CANNOT_ACCEPT_CTRL = 1061&
%ERROR_SERVICE_NOT_ACTIVE         = 1062&
%ERROR_FAILED_SERVICE_CONTROLLER_CONNECT = 1063&
%ERROR_EXCEPTION_IN_SERVICE       = 1064&
%ERROR_DATABASE_DOES_NOT_EXIST    = 1065&
%ERROR_SERVICE_SPECIFIC_ERROR     = 1066&
%ERROR_PROCESS_ABORTED            = 1067&
%ERROR_SERVICE_DEPENDENCY_FAIL    = 1068&
%ERROR_SERVICE_LOGON_FAILED       = 1069&
%ERROR_SERVICE_START_HANG         = 1070&
%ERROR_INVALID_SERVICE_LOCK       = 1071&
%ERROR_SERVICE_MARKED_FOR_DELETE  = 1072&
%ERROR_SERVICE_EXISTS             = 1073&
%ERROR_ALREADY_RUNNING_LKG        = 1074&
%ERROR_SERVICE_DEPENDENCY_DELETED = 1075&
%ERROR_BOOT_ALREADY_ACCEPTED      = 1076&
%ERROR_SERVICE_NEVER_STARTED      = 1077&
%ERROR_DUPLICATE_SERVICE_NAME     = 1078&
%ERROR_DIFFERENT_SERVICE_ACCOUNT  = 1079&
%ERROR_CANNOT_DETECT_DRIVER_FAILURE = 1080&
%ERROR_CANNOT_DETECT_PROCESS_ABORT = 1081&
%ERROR_NO_RECOVERY_PROGRAM        = 1082&
%ERROR_SERVICE_NOT_IN_EXE         = 1083&
%ERROR_END_OF_MEDIA               = 1100&
%ERROR_FILEMARK_DETECTED          = 1101&
%ERROR_BEGINNING_OF_MEDIA         = 1102&
%ERROR_SETMARK_DETECTED           = 1103&
%ERROR_NO_DATA_DETECTED           = 1104&
%ERROR_PARTITION_FAILURE          = 1105&
%ERROR_INVALID_BLOCK_LENGTH       = 1106&
%ERROR_DEVICE_NOT_PARTITIONED     = 1107&
%ERROR_UNABLE_TO_LOCK_MEDIA       = 1108&
%ERROR_UNABLE_TO_UNLOAD_MEDIA     = 1109&
%ERROR_MEDIA_CHANGED              = 1110&
%ERROR_BUS_RESET                  = 1111&
%ERROR_NO_MEDIA_IN_DRIVE          = 1112&
%ERROR_NO_UNICODE_TRANSLATION     = 1113&
%ERROR_DLL_INIT_FAILED            = 1114&
%ERROR_SHUTDOWN_IN_PROGRESS       = 1115&
%ERROR_NO_SHUTDOWN_IN_PROGRESS    = 1116&
%ERROR_IO_DEVICE                  = 1117&
%ERROR_SERIAL_NO_DEVICE           = 1118&
%ERROR_IRQ_BUSY                   = 1119&
%ERROR_MORE_WRITES                = 1120&
%ERROR_COUNTER_TIMEOUT            = 1121&
%ERROR_FLOPPY_ID_MARK_NOT_FOUND   = 1122&
%ERROR_FLOPPY_WRONG_CYLINDER      = 1123&
%ERROR_FLOPPY_UNKNOWN_ERROR       = 1124&
%ERROR_FLOPPY_BAD_REGISTERS       = 1125&
%ERROR_DISK_RECALIBRATE_FAILED    = 1126&
%ERROR_DISK_OPERATION_FAILED      = 1127&
%ERROR_DISK_RESET_FAILED          = 1128&
%ERROR_EOM_OVERFLOW               = 1129&
%ERROR_NOT_ENOUGH_SERVER_MEMORY   = 1130&
%ERROR_POSSIBLE_DEADLOCK          = 1131&
%ERROR_MAPPED_ALIGNMENT           = 1132&
%ERROR_SET_POWER_STATE_VETOED     = 1140&
%ERROR_SET_POWER_STATE_FAILED     = 1141&
%ERROR_TOO_MANY_LINKS             = 1142&
%ERROR_OLD_WIN_VERSION            = 1150&
%ERROR_APP_WRONG_OS               = 1151&
%ERROR_SINGLE_INSTANCE_APP        = 1152&
%ERROR_RMODE_APP                  = 1153&
%ERROR_INVALID_DLL                = 1154&
%ERROR_NO_ASSOCIATION             = 1155&
%ERROR_DDE_FAIL                   = 1156&
%ERROR_DLL_NOT_FOUND              = 1157&
%ERROR_NO_MORE_USER_HANDLES       = 1158&
%ERROR_MESSAGE_SYNC_ONLY          = 1159&
%ERROR_SOURCE_ELEMENT_EMPTY       = 1160&
%ERROR_DESTINATION_ELEMENT_FULL   = 1161&
%ERROR_ILLEGAL_ELEMENT_ADDRESS    = 1162&
%ERROR_MAGAZINE_NOT_PRESENT       = 1163&
%ERROR_DEVICE_REINITIALIZATION_NEEDED = 1164&     ' dderror
%ERROR_DEVICE_REQUIRES_CLEANING   = 1165&
%ERROR_DEVICE_DOOR_OPEN           = 1166&
%ERROR_DEVICE_NOT_CONNECTED       = 1167&
%ERROR_NOT_FOUND                  = 1168&
%ERROR_NO_MATCH                   = 1169&
%ERROR_SET_NOT_FOUND              = 1170&
%ERROR_POINT_NOT_FOUND            = 1171&
%ERROR_NO_TRACKING_SERVICE        = 1172&
%ERROR_NO_VOLUME_ID               = 1173&
%ERROR_INVALID_VLM_OPERATION      = 1174&
%ERROR_UNABLE_TO_REMOVE_REPLACED  = 1175&
%ERROR_UNABLE_TO_MOVE_REPLACEMENT = 1176&
%ERROR_UNABLE_TO_MOVE_REPLACEMENT_2 = 1177&
%ERROR_JOURNAL_DELETE_IN_PROGRESS = 1178&
%ERROR_JOURNAL_NOT_ACTIVE         = 1179&
%ERROR_POTENTIAL_FILE_FOUND       = 1180&
%ERROR_JOURNAL_ENTRY_DELETED      = 1181&
%ERROR_CANCELLED                  = 1223&
%ERROR_USER_MAPPED_FILE           = 1224&
%ERROR_CONNECTION_REFUSED         = 1225&
%ERROR_GRACEFUL_DISCONNECT        = 1226&
%ERROR_ADDRESS_ALREADY_ASSOCIATED = 1227&
%ERROR_ADDRESS_NOT_ASSOCIATED     = 1228&
%ERROR_CONNECTION_INVALID         = 1229&
%ERROR_CONNECTION_ACTIVE          = 1230&
%ERROR_NETWORK_UNREACHABLE        = 1231&
%ERROR_HOST_UNREACHABLE           = 1232&
%ERROR_PROTOCOL_UNREACHABLE       = 1233&
%ERROR_PORT_UNREACHABLE           = 1234&
%ERROR_REQUEST_ABORTED            = 1235&
%ERROR_CONNECTION_ABORTED         = 1236&
%ERROR_RETRY                      = 1237&
%ERROR_CONNECTION_COUNT_LIMIT     = 1238&
%ERROR_LOGIN_TIME_RESTRICTION     = 1239&
%ERROR_LOGIN_WKSTA_RESTRICTION    = 1240&
%ERROR_INCORRECT_ADDRESS          = 1241&
%ERROR_ALREADY_REGISTERED         = 1242&
%ERROR_SERVICE_NOT_FOUND          = 1243&
%ERROR_NOT_AUTHENTICATED          = 1244&
%ERROR_NOT_LOGGED_ON              = 1245&
%ERROR_CONTINUE                   = 1246&     ' dderror
%ERROR_ALREADY_INITIALIZED        = 1247&
%ERROR_NO_MORE_DEVICES            = 1248&     ' dderror
%ERROR_NO_SUCH_SITE               = 1249&
%ERROR_DOMAIN_CONTROLLER_EXISTS   = 1250&
%ERROR_ONLY_IF_CONNECTED          = 1251&
%ERROR_OVERRIDE_NOCHANGES         = 1252&
%ERROR_BAD_USER_PROFILE           = 1253&
%ERROR_NOT_SUPPORTED_ON_SBS       = 1254&
%ERROR_LICENSE_QUOTA_EXCEEDED     = 1395&
%ERROR_WRONG_TARGET_NAME          = 1396&
%ERROR_MUTUAL_AUTH_FAILED         = 1397&
%ERROR_TIME_SKEW                  = 1398&
%ERROR_GLOBAL_ONLY_HOOK           = 1429&
%ERROR_NO_SYSTEM_RESOURCES        = 1450&
%ERROR_NONPAGED_SYSTEM_RESOURCES  = 1451&
%ERROR_PAGED_SYSTEM_RESOURCES     = 1452&
%ERROR_WORKING_SET_QUOTA          = 1453&
%ERROR_PAGEFILE_QUOTA             = 1454&
%ERROR_COMMITMENT_LIMIT           = 1455&
%ERROR_MENU_ITEM_NOT_FOUND        = 1456&
%ERROR_INVALID_KEYBOARD_HANDLE    = 1457&
%ERROR_HOOK_TYPE_NOT_ALLOWED      = 1458&
%ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION = 1459&
%ERROR_TIMEOUT                    = 1460&
%ERROR_INVALID_MONITOR_HANDLE     = 1461&
%ERROR_INSTALL_SERVICE_FAILURE    = 1601&
%ERROR_INSTALL_USEREXIT           = 1602&
%ERROR_INSTALL_FAILURE            = 1603&
%ERROR_INSTALL_SUSPEND            = 1604&
%ERROR_UNKNOWN_PRODUCT            = 1605&
%ERROR_UNKNOWN_FEATURE            = 1606&
%ERROR_UNKNOWN_COMPONENT          = 1607&
%ERROR_UNKNOWN_PROPERTY           = 1608&
%ERROR_INVALID_HANDLE_STATE       = 1609&
%ERROR_BAD_CONFIGURATION          = 1610&
%ERROR_INDEX_ABSENT               = 1611&
%ERROR_INSTALL_SOURCE_ABSENT      = 1612&
%ERROR_INSTALL_PACKAGE_VERSION    = 1613&
%ERROR_PRODUCT_UNINSTALLED        = 1614&
%ERROR_BAD_QUERY_SYNTAX           = 1615&
%ERROR_INVALID_FIELD              = 1616&
%ERROR_DEVICE_REMOVED             = 1617&
%ERROR_INSTALL_ALREADY_RUNNING    = 1618&
%ERROR_INSTALL_PACKAGE_OPEN_FAILED = 1619&
%ERROR_INSTALL_PACKAGE_INVALID    = 1620&
%ERROR_INSTALL_UI_FAILURE         = 1621&
%ERROR_INSTALL_LOG_FAILURE        = 1622&
%ERROR_INSTALL_LANGUAGE_UNSUPPORTED = 1623&
%ERROR_INSTALL_TRANSFORM_FAILURE  = 1624&
%ERROR_INSTALL_PACKAGE_REJECTED   = 1625&
%ERROR_FUNCTION_NOT_CALLED        = 1626&
%ERROR_FUNCTION_FAILED            = 1627&
%ERROR_INVALID_TABLE              = 1628&
%ERROR_DATATYPE_MISMATCH          = 1629&
%ERROR_UNSUPPORTED_TYPE           = 1630&
%ERROR_CREATE_FAILED              = 1631&
%ERROR_INSTALL_TEMP_UNWRITABLE    = 1632&
%ERROR_INSTALL_PLATFORM_UNSUPPORTED = 1633&
%ERROR_INSTALL_NOTUSED            = 1634&
%ERROR_PATCH_PACKAGE_OPEN_FAILED  = 1635&
%ERROR_PATCH_PACKAGE_INVALID      = 1636&
%ERROR_PATCH_PACKAGE_UNSUPPORTED  = 1637&
%ERROR_PRODUCT_VERSION            = 1638&
%ERROR_INVALID_COMMAND_LINE       = 1639&
%ERROR_INSTALL_REMOTE_DISALLOWED  = 1640&
%ERROR_SUCCESS_REBOOT_INITIATED   = 1641&
%ERROR_PATCH_TARGET_NOT_FOUND     = 1642&

%SEVERITY_SUCCESS = 0
%SEVERITY_ERROR   = 1
%FACILITY_NT_BIT  = &H10000000
%NOERROR          = 0

' Error codes need to be LONG due to quirky HRESULT definition
%E_PENDING                        = &H8000000A&
%CO_E_INIT_TLS                    = &H80004006&
%CO_E_INIT_SHARED_ALLOCATOR       = &H80004007&
%CO_E_INIT_MEMORY_ALLOCATOR       = &H80004008&
%CO_E_INIT_CLASS_CACHE            = &H80004009&
%CO_E_INIT_RPC_CHANNEL            = &H8000400A&
%CO_E_INIT_TLS_SET_CHANNEL_CONTROL   = &H8000400B&
%CO_E_INIT_TLS_CHANNEL_CONTROL       = &H8000400C&
%CO_E_INIT_UNACCEPTED_USER_ALLOCATOR = &H8000400D&
%CO_E_INIT_SCM_MUTEX_EXISTS          = &H8000400E&
%CO_E_INIT_SCM_FILE_MAPPING_EXISTS   = &H8000400F&
%CO_E_INIT_SCM_MAP_VIEW_OF_FILE      = &H80004010&
%CO_E_INIT_SCM_EXEC_FAILURE          = &H80004011&
%CO_E_INIT_ONLY_SINGLE_THREADED      = &H80004012&

%OLE_E_FIRST                      = &H80040000&
%OLE_E_LAST                       = &H800400FF&
%OLE_S_FIRST                      = &H40000
%OLE_S_LAST                       = &H400FF
%OLE_E_OLEVERB                    = &H80040000&
%OLE_E_ADVF                       = &H80040001&
%OLE_E_ENUM_NOMORE                = &H80040002&
%OLE_E_ADVISENOTSUPPORTED         = &H80040003&
%OLE_E_NOCONNECTION               = &H80040004&
%OLE_E_NOTRUNNING                 = &H80040005&
%OLE_E_NOCACHE                    = &H80040006&
%OLE_E_BLANK                      = &H80040007&
%OLE_E_CLASSDIFF                  = &H80040008&
%OLE_E_CANT_GETMONIKER            = &H80040009&
%OLE_E_CANT_BINDTOSOURCE          = &H8004000A&
%OLE_E_STATIC                     = &H8004000B&
%OLE_E_PROMPTSAVECANCELLED        = &H8004000C&
%OLE_E_INVALIDRECT                = &H8004000D&
%OLE_E_WRONGCOMPOBJ               = &H8004000E&
%OLE_E_INVALIDHWND                = &H8004000F&
%OLE_E_NOT_INPLACEACTIVE          = &H80040010&
%OLE_E_CANTCONVERT                = &H80040011&
%OLE_E_NOSTORAGE                  = &H80040012&
%DV_E_FORMATETC                   = &H80040064&
%DV_E_DVTARGETDEVICE              = &H80040065&
%DV_E_STGMEDIUM                   = &H80040066&
%DV_E_STATDATA                    = &H80040067&
%DV_E_LINDEX                      = &H80040068&
%DV_E_TYMED                       = &H80040069&
%DV_E_CLIPFORMAT                  = &H8004006A&
%DV_E_DVASPECT                    = &H8004006B&
%DV_E_DVTARGETDEVICE_SIZE         = &H8004006C&
%DV_E_NOIVIEWOBJECT               = &H8004006D&
%DRAGDROP_E_FIRST                 = &H80040100&
%DRAGDROP_E_LAST                  = &H8004010F&
%DRAGDROP_S_FIRST                 = &H40100
%DRAGDROP_S_LAST                  = &H4010F
%DRAGDROP_E_NOTREGISTERED         = &H80040100&
%DRAGDROP_E_ALREADYREGISTERED     = &H80040101&
%DRAGDROP_E_INVALIDHWND           = &H80040102&
%CLASSFACTORY_E_FIRST             = &H80040110&
%CLASSFACTORY_E_LAST              = &H8004011F&
%CLASSFACTORY_S_FIRST             = &H40110
%CLASSFACTORY_S_LAST              = &H4011F
%CLASS_E_NOAGGREGATION            = &H80040110&
%CLASS_E_CLASSNOTAVAILABLE        = &H80040111&
%MARSHAL_E_FIRST                  = &H80040120&
%MARSHAL_E_LAST                   = &H8004012F&
%MARSHAL_S_FIRST                  = &H40120
%MARSHAL_S_LAST                   = &H4012F
%DATA_E_FIRST                     = &H80040130&
%DATA_E_LAST                      = &H8004013F&
%DATA_S_FIRST                     = &H40130
%DATA_S_LAST                      = &H4013F
%VIEW_E_FIRST                     = &H80040140&
%VIEW_E_LAST                      = &H8004014F&
%VIEW_S_FIRST                     = &H40140
%VIEW_S_LAST                      = &H4014F
%VIEW_E_DRAW                      = &H80040140&
%REGDB_E_FIRST                    = &H80040150&
%REGDB_E_LAST                     = &H8004015F&
%REGDB_S_FIRST                    = &H40150
%REGDB_S_LAST                     = &H4015F
%REGDB_E_READREGDB                = &H80040150&
%REGDB_E_WRITEREGDB               = &H80040151&
%REGDB_E_KEYMISSING               = &H80040152&
%REGDB_E_INVALIDVALUE             = &H80040153&
%REGDB_E_CLASSNOTREG              = &H80040154&
%REGDB_E_IIDNOTREG                = &H80040155&
%CACHE_E_FIRST                    = &H80040170&
%CACHE_E_LAST                     = &H8004017F&
%CACHE_S_FIRST                    = &H40170
%CACHE_S_LAST                     = &H4017F
%CACHE_E_NOCACHE_UPDATED          = &H80040170&
%OLEOBJ_E_FIRST                   = &H80040180&
%OLEOBJ_E_LAST                    = &H8004018F&
%OLEOBJ_S_FIRST                   = &H40180
%OLEOBJ_S_LAST                    = &H4018F
%OLEOBJ_E_NOVERBS                 = &H80040180&
%OLEOBJ_E_INVALIDVERB             = &H80040181&
%CLIENTSITE_E_FIRST               = &H80040190&
%CLIENTSITE_E_LAST                = &H8004019F&
%CLIENTSITE_S_FIRST               = &H40190
%CLIENTSITE_S_LAST                = &H4019F
%INPLACE_E_NOTUNDOABLE            = &H800401A0&
%INPLACE_E_NOTOOLSPACE            = &H800401A1&
%INPLACE_E_FIRST                  = &H800401A0&
%INPLACE_E_LAST                   = &H800401AF&
%INPLACE_S_FIRST                  = &H401A0
%INPLACE_S_LAST                   = &H401AF
%ENUM_E_FIRST                     = &H800401B0&
%ENUM_E_LAST                      = &H800401BF&
%ENUM_S_FIRST                     = &H401B0
%ENUM_S_LAST                      = &H401BF
%CONVERT10_E_FIRST                = &H800401C0&
%CONVERT10_E_LAST                 = &H800401CF&
%CONVERT10_S_FIRST                = &H401C0
%CONVERT10_S_LAST                 = &H401CF
%CONVERT10_E_OLESTREAM_GET        = &H800401C0&
%CONVERT10_E_OLESTREAM_PUT        = &H800401C1&
%CONVERT10_E_OLESTREAM_FMT        = &H800401C2&
%CONVERT10_E_OLESTREAM_BITMAP_TO_DIB = &H800401C3&
%CONVERT10_E_STG_FMT              = &H800401C4&
%CONVERT10_E_STG_NO_STD_STREAM    = &H800401C5&
%CONVERT10_E_STG_DIB_TO_BITMAP    = &H800401C6&
%CLIPBRD_E_FIRST                  = &H800401D0&
%CLIPBRD_E_LAST                   = &H800401DF&
%CLIPBRD_S_FIRST                  = &H401D0
%CLIPBRD_S_LAST                   = &H401DF
%CLIPBRD_E_CANT_OPEN              = &H800401D0&
%CLIPBRD_E_CANT_EMPTY             = &H800401D1&
%CLIPBRD_E_CANT_SET               = &H800401D2&
%CLIPBRD_E_BAD_DATA               = &H800401D3&
%CLIPBRD_E_CANT_CLOSE             = &H800401D4&
%MK_E_FIRST                       = &H800401E0&
%MK_E_LAST                        = &H800401EF&
%MK_S_FIRST                       = &H401E0
%MK_S_LAST                        = &H401EF
%MK_E_CONNECTMANUALLY             = &H800401E0&
%MK_E_EXCEEDEDDEADLINE            = &H800401E1&
%MK_E_NEEDGENERIC                 = &H800401E2&
%MK_E_UNAVAILABLE                 = &H800401E3&
%MK_E_SYNTAX                      = &H800401E4&
%MK_E_NOOBJECT                    = &H800401E5&
%MK_E_INVALIDEXTENSION            = &H800401E6&
%MK_E_INTERMEDIATEINTERFACENOTSUPPORTED = &H800401E7&
%MK_E_NOTBINDABLE                 = &H800401E8&
%MK_E_NOTBOUND                    = &H800401E9&
%MK_E_CANTOPENFILE                = &H800401EA&
%MK_E_MUSTBOTHERUSER              = &H800401EB&
%MK_E_NOINVERSE                   = &H800401EC&
%MK_E_NOSTORAGE                   = &H800401ED&
%MK_E_NOPREFIX                    = &H800401EE&
%MK_E_ENUMERATION_FAILED          = &H800401EF&
%CO_E_FIRST                       = &H800401F0&
%CO_E_LAST                        = &H800401FF&
%CO_S_FIRST                       = &H401F0
%CO_S_LAST                        = &H401FF
%CO_E_NOTINITIALIZED              = &H800401F0&
%CO_E_ALREADYINITIALIZED          = &H800401F1&
%CO_E_CANTDETERMINECLASS          = &H800401F2&
%CO_E_CLASSSTRING                 = &H800401F3&
%CO_E_IIDSTRING                   = &H800401F4&
%CO_E_APPNOTFOUND                 = &H800401F5&
%CO_E_APPSINGLEUSE                = &H800401F6&
%CO_E_ERRORINAPP                  = &H800401F7&
%CO_E_DLLNOTFOUND                 = &H800401F8&
%CO_E_ERRORINDLL                  = &H800401F9&
%CO_E_WRONGOSFORAPP               = &H800401FA&
%CO_E_OBJNOTREG                   = &H800401FB&
%CO_E_OBJISREG                    = &H800401FC&
%CO_E_OBJNOTCONNECTED             = &H800401FD&
%CO_E_APPDIDNTREG                 = &H800401FE&
%CO_E_RELEASED                    = &H800401FF&
%OLE_S_USEREG                     = &H40000
%OLE_S_STATIC                     = &H40001
%OLE_S_MAC_CLIPFORMAT             = &H40002
%DRAGDROP_S_DROP                  = &H40100
%DRAGDROP_S_CANCEL                = &H40101
%DRAGDROP_S_USEDEFAULTCURSORS     = &H40102
%DATA_S_SAMEFORMATETC             = &H40130
%VIEW_S_ALREADY_FROZEN            = &H40140
%CACHE_S_FORMATETC_NOTSUPPORTED   = &H40170
%CACHE_S_SAMECACHE                = &H40171
%CACHE_S_SOMECACHES_NOTUPDATED    = &H40172
%OLEOBJ_S_INVALIDVERB             = &H40180
%OLEOBJ_S_CANNOT_DOVERB_NOW       = &H40181
%OLEOBJ_S_INVALIDHWND             = &H40182
%INPLACE_S_TRUNCATED              = &H401A0
%CONVERT10_S_NO_PRESENTATION      = &H401C0
%MK_S_REDUCED_TO_SELF             = &H401E2
%MK_S_ME                          = &H401E4
%MK_S_HIM                         = &H401E5
%MK_S_US                          = &H401E6
%MK_S_MONIKERALREADYREGISTERED    = &H401E7
%CO_E_CLASS_CREATE_FAILED         = &H80080001&
%CO_E_SCM_ERROR                   = &H80080002&
%CO_E_SCM_RPC_FAILURE             = &H80080003&
%CO_E_BAD_PATH                    = &H80080004&
%CO_E_SERVER_EXEC_FAILURE         = &H80080005&
%CO_E_OBJSRV_RPC_FAILURE          = &H80080006&
%MK_E_NO_NORMALIZED               = &H80080007&
%CO_E_SERVER_STOPPING             = &H80080008&
%MEM_E_INVALID_ROOT               = &H80080009&
%MEM_E_INVALID_LINK               = &H80080010&
%MEM_E_INVALID_SIZE               = &H80080011&

%DISP_E_BADCALLEE                 = &H80020010&
%DISP_E_NOTACOLLECTION            = &H80020011&
%TYPE_E_BUFFERTOOSMALL            = &H80028016&
%TYPE_E_INVDATAREAD               = &H80028018&
%TYPE_E_UNSUPFORMAT               = &H80028019&
%TYPE_E_REGISTRYACCESS            = &H8002801C&
%TYPE_E_LIBNOTREGISTERED          = &H8002801D&
%TYPE_E_UNDEFINEDTYPE             = &H80028027&
%TYPE_E_QUALIFIEDNAMEDISALLOWED   = &H80028028&
%TYPE_E_INVALIDSTATE              = &H80028029&
%TYPE_E_WRONGTYPEKIND             = &H8002802A&
%TYPE_E_ELEMENTNOTFOUND           = &H8002802B&
%TYPE_E_AMBIGUOUSNAME             = &H8002802C&
%TYPE_E_NAMECONFLICT              = &H8002802D&
%TYPE_E_UNKNOWNLCID               = &H8002802E&
%TYPE_E_DLLFUNCTIONNOTFOUND       = &H8002802F&
%TYPE_E_BADMODULEKIND             = &H800288BD&
%TYPE_E_SIZETOOBIG                = &H800288C5&
%TYPE_E_DUPLICATEID               = &H800288C6&
%TYPE_E_INVALIDID                 = &H800288CF&
%TYPE_E_TYPEMISMATCH              = &H80028CA0&
%TYPE_E_OUTOFBOUNDS               = &H80028CA1&
%TYPE_E_IOERROR                   = &H80028CA2&
%TYPE_E_CANTCREATETMPFILE         = &H80028CA3&
%TYPE_E_CANTLOADLIBRARY           = &H80029C4A&
%TYPE_E_INCONSISTENTPROPFUNCS     = &H80029C83&
%TYPE_E_CIRCULARTYPE              = &H80029C84&
%STG_E_INVALIDFUNCTION            = &H80030001&
%STG_E_FILENOTFOUND               = &H80030002&
%STG_E_PATHNOTFOUND               = &H80030003&
%STG_E_TOOMANYOPENFILES           = &H80030004&
%STG_E_ACCESSDENIED               = &H80030005&
%STG_E_INVALIDHANDLE              = &H80030006&
%STG_E_INSUFFICIENTMEMORY         = &H80030008&
%STG_E_INVALIDPOINTER             = &H80030009&
%STG_E_NOMOREFILES                = &H80030012&
%STG_E_DISKISWRITEPROTECTED       = &H80030013&
%STG_E_SEEKERROR                  = &H80030019&
%STG_E_WRITEFAULT                 = &H8003001D&
%STG_E_READFAULT                  = &H8003001E&
%STG_E_SHAREVIOLATION             = &H80030020&
%STG_E_LOCKVIOLATION              = &H80030021&
%STG_E_FILEALREADYEXISTS          = &H80030050&
%STG_E_INVALIDPARAMETER           = &H80030057&
%STG_E_MEDIUMFULL                 = &H80030070&
%STG_E_ABNORMALAPIEXIT            = &H800300FA&
%STG_E_INVALIDHEADER              = &H800300FB&
%STG_E_INVALIDNAME                = &H800300FC&
%STG_E_UNKNOWN                    = &H800300FD&
%STG_E_UNIMPLEMENTEDFUNCTION      = &H800300FE&
%STG_E_INVALIDFLAG                = &H800300FF&
%STG_E_INUSE                      = &H80030100&
%STG_E_NOTCURRENT                 = &H80030101&
%STG_E_REVERTED                   = &H80030102&
%STG_E_CANTSAVE                   = &H80030103&
%STG_E_OLDFORMAT                  = &H80030104&
%STG_E_OLDDLL                     = &H80030105&
%STG_E_SHAREREQUIRED              = &H80030106&
%STG_E_NOTFILEBASEDSTORAGE        = &H80030107&
%STG_E_EXTANTMARSHALLINGS         = &H80030108&
%STG_S_CONVERTED                  = &H30200
%RPC_E_CALL_REJECTED              = &H80010001&
%RPC_E_CALL_CANCELED              = &H80010002&
%RPC_E_CANTPOST_INSENDCALL        = &H80010003&
%RPC_E_CANTCALLOUT_INASYNCCALL    = &H80010004&
%RPC_E_CANTCALLOUT_INEXTERNALCALL = &H80010005&
%RPC_E_CONNECTION_TERMINATED      = &H80010006&
%RPC_E_SERVER_DIED                = &H80010007&
%RPC_E_CLIENT_DIED                = &H80010008&
%RPC_E_INVALID_DATAPACKET         = &H80010009&
%RPC_E_CANTTRANSMIT_CALL          = &H8001000A&
%RPC_E_CLIENT_CANTMARSHAL_DATA    = &H8001000B&
%RPC_E_CLIENT_CANTUNMARSHAL_DATA  = &H8001000C&
%RPC_E_SERVER_CANTMARSHAL_DATA    = &H8001000D&
%RPC_E_SERVER_CANTUNMARSHAL_DATA  = &H8001000E&
%RPC_E_INVALID_DATA               = &H8001000F&
%RPC_E_INVALID_PARAMETER          = &H80010010&
%RPC_E_CANTCALLOUT_AGAIN          = &H80010011&
%RPC_E_SERVER_DIED_DNE            = &H80010012&
%RPC_E_SYS_CALL_FAILED            = &H80010100&
%RPC_E_OUT_OF_RESOURCES           = &H80010101&
%RPC_E_ATTEMPTED_MULTITHREAD      = &H80010102&
%RPC_E_NOT_REGISTERED             = &H80010103&
%RPC_E_FAULT                      = &H80010104&
%RPC_E_SERVERFAULT                = &H80010105&
%RPC_E_CHANGED_MODE               = &H80010106&
%RPC_E_INVALIDMETHOD              = &H80010107&
%RPC_E_DISCONNECTED               = &H80010108&
%RPC_E_RETRY                      = &H80010109&
%RPC_E_SERVERCALL_RETRYLATER      = &H8001010A&
%RPC_E_SERVERCALL_REJECTED        = &H8001010B&
%RPC_E_INVALID_CALLDATA           = &H8001010C&
%RPC_E_CANTCALLOUT_ININPUTSYNCCALL= &H8001010D&
%RPC_E_WRONG_THREAD               = &H8001010E&
%RPC_E_THREAD_NOT_INIT            = &H8001010F&
%RPC_E_VERSION_MISMATCH           = &H80010110&
%RPC_E_INVALID_HEADER             = &H80010111&
%RPC_E_INVALID_EXTENSION          = &H80010112&
%RPC_E_INVALID_IPID               = &H80010113&
%RPC_E_INVALID_OBJECT             = &H80010114&
%RPC_S_CALLPENDING                = &H80010115&
%RPC_S_WAITONTIMER                = &H80010116&
%RPC_E_CALL_COMPLETE              = &H80010117&
%RPC_E_UNSECURE_CALL              = &H80010118&
%RPC_E_TOO_LATE                   = &H80010119&
%RPC_E_NO_GOOD_SECURITY_PACKAGES  = &H8001011A&
%RPC_E_ACCESS_DENIED              = &H8001011B&
%RPC_E_REMOTE_DISABLED            = &H8001011C&
%RPC_E_INVALID_OBJREF             = &H8001011D&
%RPC_E_NO_CONTEXT                 = &H8001011E&
%RPC_E_TIMEOUT                    = &H8001011F&
%RPC_E_NO_SYNC                    = &H80010120&
%RPC_E_FULLSIC_REQUIRED           = &H80010121&
%RPC_E_INVALID_STD_NAME           = &H80010122&
%RPC_E_UNEXPECTED                 = &H8001FFFF&


' -------------------------
'
' Winnet32 Status Codes
'
' -------------------------

'  The specified username is invalid.
%ERROR_BAD_USERNAME               = 2202&

'  This network connection does not exist.
%ERROR_NOT_CONNECTED              = 2250&

'  This network connection has files open or requests pending.
%ERROR_OPEN_FILES                 = 2401&

'  The device is in use by an active process and cannot be disconnected.
%ERROR_DEVICE_IN_USE              = 2404&

'  The specified device name is invalid.
%ERROR_BAD_DEVICE                 = 1200&

'  The device is not currently connected but it is a remembered connection.
%ERROR_CONNECTION_UNAVAIL         = 1201&

'  An attempt was made to remember a device that had previously been remembered.
%ERROR_DEVICE_ALREADY_REMEMBERED  = 1202&

'  No network provider accepted the given network path.
%ERROR_NO_NET_OR_BAD_PATH         = 1203&

'  The specified network provider name is invalid.
%ERROR_BAD_PROVIDER               = 1204&

'  Unable to open the network connection profile.
%ERROR_CANNOT_OPEN_PROFILE        = 1205&

'  The network connection profile is corrupt.
%ERROR_BAD_PROFILE                = 1206&

'  Cannot enumerate a non-container.
%ERROR_NOT_CONTAINER              = 1207&

'  An extended error has occurred.
%ERROR_EXTENDED_ERROR             = 1208&

'  The format of the specified group name is invalid.
%ERROR_INVALID_GROUPNAME          = 1209&

'  The format of the specified computer name is invalid.
%ERROR_INVALID_COMPUTERNAME       = 1210&

'  The format of the specified event name is invalid.
%ERROR_INVALID_EVENTNAME          = 1211&

'  The format of the specified domain name is invalid.
%ERROR_INVALID_DOMAINNAME         = 1212&

'  The format of the specified service name is invalid.
%ERROR_INVALID_SERVICENAME        = 1213&

'  The format of the specified network name is invalid.
%ERROR_INVALID_NETNAME            = 1214&

'  The format of the specified share name is invalid.
%ERROR_INVALID_SHARENAME          = 1215&

'  The format of the specified password is invalid.
%ERROR_INVALID_PASSWORDNAME       = 1216&

'  The format of the specified message name is invalid.
%ERROR_INVALID_MESSAGENAME        = 1217&

'  The format of the specified message destination is invalid.
%ERROR_INVALID_MESSAGEDEST        = 1218&

'  The credentials supplied conflict with an existing set of credentials.
%ERROR_SESSION_CREDENTIAL_CONFLICT           = 1219&

'  An attempt was made to establish a session to a Lan Manager server, but there
'  are already too many sessions established to that server.
%ERROR_REMOTE_SESSION_LIMIT_EXCEEDED         = 1220&

'  The workgroup or domain name is already in use by another computer on the
'  network.
%ERROR_DUP_DOMAINNAME             = 1221&

'  The network is not present or not started.
%ERROR_NO_NETWORK                 = 1222&


' -------------------------
'
' Security Status Codes
'
' -------------------------

'  Not all privileges referenced are assigned to the caller.
%ERROR_NOT_ALL_ASSIGNED           = 1300&

'  Some mapping between account names and security IDs was not done.
%ERROR_SOME_NOT_MAPPED            = 1301&

'  No system quota limits are specifically set for this account.
%ERROR_NO_QUOTAS_FOR_ACCOUNT      = 1302&

'  No encryption key is available.  A well-known encryption key was returned.
%ERROR_LOCAL_USER_SESSION_KEY     = 1303&

'  The NT password is too complex to be converted to a LAN Manager
'  password.  The LAN Manager password returned is a NULL string.
%ERROR_NULL_LM_PASSWORD           = 1304&

'  The revision level is unknown.
%ERROR_UNKNOWN_REVISION           = 1305&

'  Indicates two revision levels are incompatible.
%ERROR_REVISION_MISMATCH          = 1306&

'  This security ID may not be assigned as the owner of this object.
%ERROR_INVALID_OWNER              = 1307&

'  This security ID may not be assigned as the primary group of an object.
%ERROR_INVALID_PRIMARY_GROUP      = 1308&

'  An attempt has been made to operate on an impersonation token
'  by a thread that is not currently impersonating a client.
%ERROR_NO_IMPERSONATION_TOKEN     = 1309&

'  The group may not be disabled.
%ERROR_CANT_DISABLE_MANDATORY     = 1310&

'  There are currently no logon servers available to service the logon
'  request.
%ERROR_NO_LOGON_SERVERS           = 1311&

'   A specified logon session does not exist.  It may already have
'   been terminated.
%ERROR_NO_SUCH_LOGON_SESSION      = 1312&

'   A specified privilege does not exist.
%ERROR_NO_SUCH_PRIVILEGE          = 1313&

'   A required privilege is not held by the client.
%ERROR_PRIVILEGE_NOT_HELD         = 1314&

'  The name provided is not a properly formed account name.
%ERROR_INVALID_ACCOUNT_NAME       = 1315&

'  The specified user already exists.
%ERROR_USER_EXISTS                = 1316&

'  The specified user does not exist.
%ERROR_NO_SUCH_USER               = 1317&

'  The specified group already exists.
%ERROR_GROUP_EXISTS               = 1318&

'  The specified group does not exist.
%ERROR_NO_SUCH_GROUP              = 1319&

'  Either the specified user account is already a member of the specified
'  group, or the specified group cannot be deleted because it contains
'  a member.
%ERROR_MEMBER_IN_GROUP            = 1320&

'  The specified user account is not a member of the specified group account.
%ERROR_MEMBER_NOT_IN_GROUP        = 1321&

'  The last remaining administration account cannot be disabled
'  or deleted.
%ERROR_LAST_ADMIN                 = 1322&

'  Unable to update the password.  The value provided as the current
'  password is incorrect.
%ERROR_WRONG_PASSWORD             = 1323&

'  Unable to update the password.  The value provided for the new password
'  contains values that are not allowed in passwords.
%ERROR_ILL_FORMED_PASSWORD        = 1324&

'  Unable to update the password because a password update rule has been
'  violated.
%ERROR_PASSWORD_RESTRICTION       = 1325&

'  Logon failure: unknown user name or bad password.
%ERROR_LOGON_FAILURE              = 1326&

'  Logon failure: user account restriction.
%ERROR_ACCOUNT_RESTRICTION        = 1327&

'  Logon failure: account logon time restriction violation.
%ERROR_INVALID_LOGON_HOURS        = 1328&

'  Logon failure: user not allowed to log on to this computer.
%ERROR_INVALID_WORKSTATION        = 1329&

'  Logon failure: the specified account password has expired.
%ERROR_PASSWORD_EXPIRED           = 1330&

'  Logon failure: account currently disabled.
%ERROR_ACCOUNT_DISABLED           = 1331&

'  No mapping between account names and security IDs was done.
%ERROR_NONE_MAPPED                = 1332&

'  Too many local user identifiers (LUIDs) were requested at one time.
%ERROR_TOO_MANY_LUIDS_REQUESTED   = 1333&

'  No more local user identifiers (LUIDs) are available.
%ERROR_LUIDS_EXHAUSTED            = 1334&

'  The subauthority part of a security ID is invalid for this particular use.
%ERROR_INVALID_SUB_AUTHORITY      = 1335&

'  The access control list (ACL) structure is invalid.
%ERROR_INVALID_ACL                = 1336&

'  The security ID structure is invalid.
%ERROR_INVALID_SID                = 1337&

'  The security descriptor structure is invalid.
%ERROR_INVALID_SECURITY_DESCR     = 1338&

'  The inherited access control list (ACL) or access control entry (ACE)
'  could not be built.
%ERROR_BAD_INHERITANCE_ACL        = 1340&

'  The server is currently disabled.
%ERROR_SERVER_DISABLED            = 1341&

'  The server is currently enabled.
%ERROR_SERVER_NOT_DISABLED        = 1342&

'  The value provided was an invalid value for an identifier authority.
%ERROR_INVALID_ID_AUTHORITY       = 1343&

'  No more memory is available for security information updates.
%ERROR_ALLOTTED_SPACE_EXCEEDED    = 1344&

'  The specified attributes are invalid, or incompatible with the
'  attributes for the group as a whole.
%ERROR_INVALID_GROUP_ATTRIBUTES   = 1345&

'  Either a required impersonation level was not provided, or the
'  provided impersonation level is invalid.
%ERROR_BAD_IMPERSONATION_LEVEL    = 1346&

'  Cannot open an anonymous level security token.
%ERROR_CANT_OPEN_ANONYMOUS        = 1347&

'  The validation information class requested was invalid.
%ERROR_BAD_VALIDATION_CLASS       = 1348&

'  The type of the token is inappropriate for its attempted use.
%ERROR_BAD_TOKEN_TYPE             = 1349&

'  Unable to perform a security operation on an object
'  which has no associated security.
%ERROR_NO_SECURITY_ON_OBJECT      = 1350&

'  Indicates a Windows NT Advanced Server could not be contacted or that
'  objects within the domain are protected such that necessary
'  information could not be retrieved.
%ERROR_CANT_ACCESS_DOMAIN_INFO    = 1351&

'  The security account manager (SAM) or local security
'  authority (LSA) server was in the wrong state to perform
'  the security operation.
%ERROR_INVALID_SERVER_STATE       = 1352&

'  The domain was in the wrong state to perform the security operation.
%ERROR_INVALID_DOMAIN_STATE       = 1353&

'  This operation is only allowed for the Primary Domain Controller of the domain.
%ERROR_INVALID_DOMAIN_ROLE        = 1354&

'  The specified domain did not exist.
%ERROR_NO_SUCH_DOMAIN             = 1355&

'  The specified domain already exists.
%ERROR_DOMAIN_EXISTS              = 1356&

'  An attempt was made to exceed the limit on the number of domains per server.
%ERROR_DOMAIN_LIMIT_EXCEEDED      = 1357&

'  Unable to complete the requested operation because of either a
'  catastrophic media failure or a data structure corruption on the disk.
%ERROR_INTERNAL_DB_CORRUPTION     = 1358&

'  The security account database contains an internal inconsistency.
%ERROR_INTERNAL_ERROR             = 1359&

'  Generic access types were contained in an access mask which should
'  already be mapped to non-generic types.
%ERROR_GENERIC_NOT_MAPPED         = 1360&

'  A security descriptor is not in the right format (absolute or self-relative).
%ERROR_BAD_DESCRIPTOR_FORMAT      = 1361&

'  The requested action is restricted for use by logon processes
'  only.  The calling process has not registered as a logon process.
%ERROR_NOT_LOGON_PROCESS          = 1362&

'  Cannot start a new logon session with an ID that is already in use.
%ERROR_LOGON_SESSION_EXISTS       = 1363&

'  A specified authentication package is unknown.
%ERROR_NO_SUCH_PACKAGE            = 1364&

'  The logon session is not in a state that is consistent with the
'  requested operation.
%ERROR_BAD_LOGON_SESSION_STATE    = 1365&

'  The logon session ID is already in use.
%ERROR_LOGON_SESSION_COLLISION    = 1366&

'  A logon request contained an invalid logon type value.
%ERROR_INVALID_LOGON_TYPE         = 1367&

'  Unable to impersonate via a named pipe until data has been read
'  from that pipe.
%ERROR_CANNOT_IMPERSONATE         = 1368&

'  The transaction state of a Registry subtree is incompatible with the
'  requested operation.
%ERROR_RXACT_INVALID_STATE        = 1369&

'  An internal security database corruption has been encountered.
%ERROR_RXACT_COMMIT_FAILURE       = 1370&

'  Cannot perform this operation on built-in accounts.
%ERROR_SPECIAL_ACCOUNT            = 1371&

'  Cannot perform this operation on this built-in special group.
%ERROR_SPECIAL_GROUP              = 1372&

'  Cannot perform this operation on this built-in special user.
%ERROR_SPECIAL_USER               = 1373&

'  The user cannot be removed from a group because the group
'  is currently the user's primary group.
%ERROR_MEMBERS_PRIMARY_GROUP      = 1374&

'  The token is already in use as a primary token.
%ERROR_TOKEN_ALREADY_IN_USE       = 1375&

'  The specified local group does not exist.
%ERROR_NO_SUCH_ALIAS              = 1376&

'  The specified account name is not a member of the local group.
%ERROR_MEMBER_NOT_IN_ALIAS        = 1377&

'  The specified account name is already a member of the local group.
%ERROR_MEMBER_IN_ALIAS            = 1378&

'  The specified local group already exists.
%ERROR_ALIAS_EXISTS               = 1379&

'  Logon failure: the user has not been granted the requested
'  logon type at this computer.
%ERROR_LOGON_NOT_GRANTED          = 1380&

'  The maximum number of secrets that may be stored in a single system has been
'  exceeded.
%ERROR_TOO_MANY_SECRETS           = 1381&

'  The length of a secret exceeds the maximum length allowed.
%ERROR_SECRET_TOO_LONG            = 1382&

'  The local security authority database contains an internal inconsistency.
%ERROR_INTERNAL_DB_ERROR          = 1383&

'  During a logon attempt, the user's security context accumulated too many
'  security IDs.
%ERROR_TOO_MANY_CONTEXT_IDS       = 1384&

'  Logon failure: the user has not been granted the requested logon type
'  at this computer.
%ERROR_LOGON_TYPE_NOT_GRANTED     = 1385&

'  A cross-encrypted password is necessary to change a user password.
%ERROR_NT_CROSS_ENCRYPTION_REQUIRED          = 1386&

'  A new member could not be added to a local group because the member does
'  not exist.
%ERROR_NO_SUCH_MEMBER             = 1387&

'  A new member could not be added to a local group because the member has the
'  wrong account type.
%ERROR_INVALID_MEMBER             = 1388&

'  Too many security IDs have been specified.
%ERROR_TOO_MANY_SIDS                         = 1389&

'  A cross-encrypted password is necessary to change this user password.
%ERROR_LM_CROSS_ENCRYPTION_REQUIRED          = 1390&

'  Indicates an ACL contains no inheritable components
%ERROR_NO_INHERITANCE             = 1391&

'  The file or directory is corrupt and non-readable.
%ERROR_FILE_CORRUPT               = 1392&

'  The disk structure is corrupt and non-readable.
%ERROR_DISK_CORRUPT               = 1393&

'  There is no user session key for the specified logon session.
%ERROR_NO_USER_SESSION_KEY        = 1394&

' End of security error codes


' -------------------------
'
' WinUser Error Codes
'
' -------------------------

'  Invalid window handle.
%ERROR_INVALID_WINDOW_HANDLE      = 1400&

'  Invalid menu handle.
%ERROR_INVALID_MENU_HANDLE        = 1401&

'  Invalid cursor handle.
%ERROR_INVALID_CURSOR_HANDLE      = 1402&

'  Invalid accelerator table handle.
%ERROR_INVALID_ACCEL_HANDLE       = 1403&

'  Invalid hook handle.
%ERROR_INVALID_HOOK_HANDLE        = 1404&

'  Invalid xHandle to a multiple-window position structure.
%ERROR_INVALID_DWP_HANDLE         = 1405&

'  Cannot create a top-level child window.
%ERROR_TLW_WITH_WSCHILD           = 1406&

'  Cannot find window class.
%ERROR_CANNOT_FIND_WND_CLASS      = 1407&

'  Invalid window, belongs to other thread.
%ERROR_WINDOW_OF_OTHER_THREAD     = 1408&

'  Hot key is already registered.
%ERROR_HOTKEY_ALREADY_REGISTERED  = 1409&

'  Class already exists.
%ERROR_CLASS_ALREADY_EXISTS       = 1410&

'  Class does not exist.
%ERROR_CLASS_DOES_NOT_EXIST       = 1411&

'  Class still has open windows.
%ERROR_CLASS_HAS_WINDOWS          = 1412&

'  Invalid index.
%ERROR_INVALID_INDEX              = 1413&

'  Invalid icon handle.
%ERROR_INVALID_ICON_HANDLE        = 1414&

'  Using private DIALOG window words.
%ERROR_PRIVATE_DIALOG_INDEX       = 1415&

'  The listbox identifier was not found.
%ERROR_LISTBOX_ID_NOT_FOUND       = 1416&

'  No wildcards were found.
%ERROR_NO_WILDCARD_CHARACTERS     = 1417&

'  Thread does not have a clipboard open.
%ERROR_CLIPBOARD_NOT_OPEN         = 1418&

'  Hot key is not registered.
%ERROR_HOTKEY_NOT_REGISTERED      = 1419&

'  The window is not a valid dialog window.
%ERROR_WINDOW_NOT_DIALOG          = 1420&

'  Control ID not found.
%ERROR_CONTROL_ID_NOT_FOUND       = 1421&

'  Invalid message for a combo box because it does not have an edit control.
%ERROR_INVALID_COMBOBOX_MESSAGE   = 1422&

'  The window is not a combo box.
%ERROR_WINDOW_NOT_COMBOBOX        = 1423&

'  Height must be less than 256.
%ERROR_INVALID_EDIT_HEIGHT        = 1424&

'  Invalid device context (DC) handle.
%ERROR_DC_NOT_FOUND               = 1425&

'  Invalid hook procedure type.
%ERROR_INVALID_HOOK_FILTER        = 1426&

'  Invalid hook procedure.
%ERROR_INVALID_FILTER_PROC        = 1427&

'  Cannot set non-local hook without a module handle.
%ERROR_HOOK_NEEDS_HMOD            = 1428&

'  This hook procedure can only be set Globally.
'
%ERROR_PUBLIC_ONLY_HOOK           = 1429&

'  The journal hook procedure is already installed.
%ERROR_JOURNAL_HOOK_SET           = 1430&

'  The hook procedure is not installed.
%ERROR_HOOK_NOT_INSTALLED         = 1431&

'  Invalid message for single-selection listbox.
%ERROR_INVALID_LB_MESSAGE         = 1432&

'  LB_SETCOUNT sent to non-lazy listbox.
%ERROR_SETCOUNT_ON_BAD_LB         = 1433&

'  This list box does not support tab stops.
%ERROR_LB_WITHOUT_TABSTOPS        = 1434&

'  Cannot destroy object created by another thread.
%ERROR_DESTROY_OBJECT_OF_OTHER_THREAD        = 1435&

'  Child windows cannot have menus.
%ERROR_CHILD_WINDOW_MENU          = 1436&

'  The window does not have a system menu.
%ERROR_NO_SYSTEM_MENU             = 1437&

'  Invalid message box style.
%ERROR_INVALID_MSGBOX_STYLE       = 1438&

'  Invalid system-wide (SPI_) parameter.
%ERROR_INVALID_SPI_VALUE          = 1439&

'  Screen already locked.
%ERROR_SCREEN_ALREADY_LOCKED      = 1440&

'  All handles to windows in a multiple-window position structure must
'  have the same parent.
%ERROR_HWNDS_HAVE_DIFF_PARENT     = 1441&

'  The window is not a child window.
%ERROR_NOT_CHILD_WINDOW           = 1442&

'  Invalid GW_ command.
%ERROR_INVALID_GW_COMMAND         = 1443&

'  Invalid thread identifier.
%ERROR_INVALID_THREAD_ID          = 1444&

'  Cannot process a message from a window that is not a multiple document
'  interface (MDI) window.
%ERROR_NON_MDICHILD_WINDOW        = 1445&

'  Popup menu already active.
%ERROR_POPUP_ALREADY_ACTIVE       = 1446&

'  The window does not have scroll bars.
%ERROR_NO_SCROLLBARS              = 1447&

'  Scroll bar range cannot be greater than &H7FFF.
%ERROR_INVALID_SCROLLBAR_RANGE    = 1448&

'  Cannot show or remove the window in the way specified.
%ERROR_INVALID_SHOWWIN_COMMAND    = 1449&

' End of WinUser error codes


' -------------------------
'
' Eventlog Status Codes
'
' -------------------------

'  The event log file is corrupt.
%ERROR_EVENTLOG_FILE_CORRUPT      = 1500&

'  No event log file could be opened, so the event logging service did not start.
%ERROR_EVENTLOG_CANT_START        = 1501&

'  The event log file is full.
%ERROR_LOG_FILE_FULL              = 1502&

'  The event log file has changed between reads.
%ERROR_EVENTLOG_FILE_CHANGED      = 1503&

' End of eventlog error codes


' -------------------------
'
'   RPC Status Codes
'
' -------------------------

'  The string binding is invalid.
%RPC_S_INVALID_STRING_BINDING     = 1700&

'  The binding xHandle is not the correct type.
%RPC_S_WRONG_KIND_OF_BINDING      = 1701&

'  The binding xHandle is invalid.
%RPC_S_INVALID_BINDING            = 1702&

'  The RPC protocol sequence is not supported.
%RPC_S_PROTSEQ_NOT_SUPPORTED      = 1703&

'  The RPC protocol sequence is invalid.
%RPC_S_INVALID_RPC_PROTSEQ        = 1704&

'  The string universal unique identifier (UUID) is invalid.
%RPC_S_INVALID_STRING_UUID        = 1705&

'  The endpoint format is invalid.
%RPC_S_INVALID_ENDPOINT_FORMAT    = 1706&

'  The network address is invalid.
%RPC_S_INVALID_NET_ADDR           = 1707&

'  No endpoint was found.
%RPC_S_NO_ENDPOINT_FOUND          = 1708&

'  The timeout value is invalid.
%RPC_S_INVALID_TIMEOUT            = 1709&

'  The object universal unique identifier (UUID) was not found.
%RPC_S_OBJECT_NOT_FOUND           = 1710&

'  The object universal unique identifier (UUID) has already been registered.
%RPC_S_ALREADY_REGISTERED         = 1711&

'  The type universal unique identifier (UUID) has already been registered.
%RPC_S_TYPE_ALREADY_REGISTERED    = 1712&

'  The RPC server is already listening.
%RPC_S_ALREADY_LISTENING          = 1713&

'  No protocol sequences have been registered.
%RPC_S_NO_PROTSEQS_REGISTERED     = 1714&

'  The RPC server is not listening.
%RPC_S_NOT_LISTENING              = 1715&

'  The manager type is unknown.
%RPC_S_UNKNOWN_MGR_TYPE           = 1716&

'  The interface is unknown.
%RPC_S_UNKNOWN_IF                 = 1717&

'  There are no bindings.
%RPC_S_NO_BINDINGS                = 1718&

'  There are no protocol sequences.
%RPC_S_NO_PROTSEQS                = 1719&

'  The endpoint cannot be created.
%RPC_S_CANT_CREATE_ENDPOINT       = 1720&

'  Not enough resources are available to complete this operation.
%RPC_S_OUT_OF_RESOURCES           = 1721&

'  The RPC server is unavailable.
%RPC_S_SERVER_UNAVAILABLE         = 1722&

'  The RPC server is too busy to complete this operation.
%RPC_S_SERVER_TOO_BUSY            = 1723&

'  The network options are invalid.
%RPC_S_INVALID_NETWORK_OPTIONS    = 1724&

'  There is not a remote procedure call active in this thread.
%RPC_S_NO_CALL_ACTIVE             = 1725&

'  The remote procedure call failed.
%RPC_S_CALL_FAILED                = 1726&

'  The remote procedure call failed and did not execute.
%RPC_S_CALL_FAILED_DNE            = 1727&

'  A remote procedure call (RPC) protocol error occurred.
%RPC_S_PROTOCOL_ERROR             = 1728&

'  The transfer syntax is not supported by the RPC server.
%RPC_S_UNSUPPORTED_TRANS_SYN      = 1730&

'  The universal unique identifier (UUID) type is not supported.
%RPC_S_UNSUPPORTED_TYPE           = 1732&

'  The tag is invalid.
%RPC_S_INVALID_TAG                = 1733&

'  The array bounds are invalid.
%RPC_S_INVALID_BOUND              = 1734&

'  The binding does not contain an entry name.
%RPC_S_NO_ENTRY_NAME              = 1735&

'  The name syntax is invalid.
%RPC_S_INVALID_NAME_SYNTAX        = 1736&

'  The name syntax is not supported.
%RPC_S_UNSUPPORTED_NAME_SYNTAX    = 1737&

'  No network address is available to use to construct a universal
'  unique identifier (UUID).
%RPC_S_UUID_NO_ADDRESS            = 1739&

'  The endpoint is a duplicate.
%RPC_S_DUPLICATE_ENDPOINT         = 1740&

'  The authentication type is unknown.
%RPC_S_UNKNOWN_AUTHN_TYPE         = 1741&

'  The maximum number of calls is too small.
%RPC_S_MAX_CALLS_TOO_SMALL        = 1742&

'  The string is too long.
%RPC_S_STRING_TOO_LONG            = 1743&

'  The RPC protocol sequence was not found.
%RPC_S_PROTSEQ_NOT_FOUND          = 1744&

'  The procedure number is out of range.
%RPC_S_PROCNUM_OUT_OF_RANGE       = 1745&

'  The binding does not contain any authentication information.
%RPC_S_BINDING_HAS_NO_AUTH        = 1746&

'  The authentication service is unknown.
%RPC_S_UNKNOWN_AUTHN_SERVICE      = 1747&

'  The authentication level is unknown.
%RPC_S_UNKNOWN_AUTHN_LEVEL        = 1748&

'  The security context is invalid.
%RPC_S_INVALID_AUTH_IDENTITY      = 1749&

'  The authorization service is unknown.
%RPC_S_UNKNOWN_AUTHZ_SERVICE      = 1750&

'  The entry is invalid.
%EPT_S_INVALID_ENTRY              = 1751&

'  The server endpoint cannot perform the operation.
%EPT_S_CANT_PERFORM_OP            = 1752&

'  There are no more endpoints available from the endpoint mapper.
%EPT_S_NOT_REGISTERED             = 1753&

'  No interfaces have been exported.
%RPC_S_NOTHING_TO_EXPORT          = 1754&

'  The entry name is incomplete.
%RPC_S_INCOMPLETE_NAME            = 1755&

'  The version option is invalid.
%RPC_S_INVALID_VERS_OPTION        = 1756&

'  There are no more members.
%RPC_S_NO_MORE_MEMBERS            = 1757&

'  There is nothing to unexport.
%RPC_S_NOT_ALL_OBJS_UNEXPORTED    = 1758&

'  The interface was not found.
%RPC_S_INTERFACE_NOT_FOUND        = 1759&

'  The entry already exists.
%RPC_S_ENTRY_ALREADY_EXISTS       = 1760&

'  The entry is not found.
%RPC_S_ENTRY_NOT_FOUND            = 1761&

'  The name service is unavailable.
%RPC_S_NAME_SERVICE_UNAVAILABLE   = 1762&

'  The network address family is invalid.
%RPC_S_INVALID_NAF_ID             = 1763&

'  The requested operation is not supported.
%RPC_S_CANNOT_SUPPORT             = 1764&

'  No security context is available to allow impersonation.
%RPC_S_NO_CONTEXT_AVAILABLE       = 1765&

'  An internal error occurred in a remote procedure call (RPC).
%RPC_S_INTERNAL_ERROR             = 1766&

'  The RPC server attempted an integer division by zero.'
%RPC_S_ZERO_DIVIDE                = 1767&

'  An addressing error occurred in the RPC server.
%RPC_S_ADDRESS_ERROR              = 1768&

'  A floating-point operation at the RPC server caused a division by zero.
%RPC_S_FP_DIV_ZERO                = 1769&

'  A floating-point underflow occurred at the RPC server.
%RPC_S_FP_UNDERFLOW               = 1770&

'  A floating-point overflow occurred at the RPC server.
%RPC_S_FP_OVERFLOW                = 1771&

'  The list of RPC servers available for the binding of auto handles
'  has been exhausted.
%RPC_X_NO_MORE_ENTRIES            = 1772&

'  Unable to open the character translation table file.
%RPC_X_SS_CHAR_TRANS_OPEN_FAIL    = 1773&

'  The file containing the character translation table has fewer than
'  512 bytes.
%RPC_X_SS_CHAR_TRANS_SHORT_FILE   = 1774&

'  A null context xHandle was passed from the client to the host during
'  a remote procedure call.
%RPC_X_SS_IN_NULL_CONTEXT         = 1775&

'  The context xHandle changed during a remote procedure call.
%RPC_X_SS_CONTEXT_DAMAGED         = 1777&

'  The binding handles passed to a remote procedure call do not match.
%RPC_X_SS_HANDLES_MISMATCH        = 1778&

'  The stub is unable to get the remote procedure call handle.
%RPC_X_SS_CANNOT_GET_CALL_HANDLE  = 1779&

'  A null reference pointer was passed to the stub.
%RPC_X_NULL_REF_POINTER           = 1780&

'  The enumeration value is out of range.
%RPC_X_ENUM_VALUE_OUT_OF_RANGE    = 1781&

'  The byte count is too small.
%RPC_X_BYTE_COUNT_TOO_SMALL       = 1782&

'  The stub received bad data.
%RPC_X_BAD_STUB_DATA              = 1783&

'  The supplied user buffer is not valid for the requested operation.
%ERROR_INVALID_USER_BUFFER        = 1784&

'  The disk media is not recognized.  It may not be formatted.
%ERROR_UNRECOGNIZED_MEDIA         = 1785&

'  The workstation does not have a trust secret.
%ERROR_NO_TRUST_LSA_SECRET        = 1786&

'  The SAM database on the Windows NT Advanced Server does not have a computer
'  account for this workstation trust relationship.
%ERROR_NO_TRUST_SAM_ACCOUNT       = 1787&

'  The trust relationship between the primary domain and the trusted
'  domain failed.
%ERROR_TRUSTED_DOMAIN_FAILURE     = 1788&

'  The trust relationship between this workstation and the primary
'  domain failed.
%ERROR_TRUSTED_RELATIONSHIP_FAILURE          = 1789&

'  The network logon failed.
%ERROR_TRUST_FAILURE              = 1790&

'  A remote procedure call is already in progress for this thread.
%RPC_S_CALL_IN_PROGRESS           = 1791&

'  An attempt was made to logon, but the network logon service was not started.
%ERROR_NETLOGON_NOT_STARTED       = 1792&

'  The user's account has expired.
%ERROR_ACCOUNT_EXPIRED            = 1793&

'  The redirector is in use and cannot be unloaded.
%ERROR_REDIRECTOR_HAS_OPEN_HANDLES           = 1794&

'  The specified printer driver is already installed.
%ERROR_PRINTER_DRIVER_ALREADY_INSTALLED      = 1795&

'  The specified port is unknown.
%ERROR_UNKNOWN_PORT               = 1796&

'  The printer driver is unknown.
%ERROR_UNKNOWN_PRINTER_DRIVER     = 1797&

'  The print processor is unknown.
'
%ERROR_UNKNOWN_PRINTPROCESSOR     = 1798&

'  The specified separator file is invalid.
%ERROR_INVALID_SEPARATOR_FILE     = 1799&

'  The specified priority is invalid.
%ERROR_INVALID_PRIORITY           = 1800&

'  The printer name is invalid.
%ERROR_INVALID_PRINTER_NAME       = 1801&

'  The printer already exists.
%ERROR_PRINTER_ALREADY_EXISTS     = 1802&

'  The printer command is invalid.
%ERROR_INVALID_PRINTER_COMMAND    = 1803&

'  The specified datatype is invalid.
%ERROR_INVALID_DATATYPE           = 1804&

'  The Environment specified is invalid.
%ERROR_INVALID_ENVIRONMENT        = 1805&

'  There are no more bindings.
%RPC_S_NO_MORE_BINDINGS           = 1806&

'  The account used is an interdomain trust account.  Use your Global user account or local user account to access this server.
%ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT     = 1807&

'  The account used is a Computer Account.  Use your Global user account or local user account to access this server.
%ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT     = 1808&

'  The account used is an server trust account.  Use your Global user account or local user account to access this server.
%ERROR_NOLOGON_SERVER_TRUST_ACCOUNT          = 1809&

'  The name or security ID (SID) of the domain specified is inconsistent
'  with the trust information for that domain.
%ERROR_DOMAIN_TRUST_INCONSISTENT  = 1810&

'  The server is in use and cannot be unloaded.
%ERROR_SERVER_HAS_OPEN_HANDLES    = 1811&

'  The specified image file did not contain a resource section.
%ERROR_RESOURCE_DATA_NOT_FOUND    = 1812&

'  The specified resource type can not be found in the image file.
%ERROR_RESOURCE_TYPE_NOT_FOUND    = 1813&

'  The specified resource name can not be found in the image file.
%ERROR_RESOURCE_NAME_NOT_FOUND    = 1814&

'  The specified resource language ID cannot be found in the image file.
%ERROR_RESOURCE_LANG_NOT_FOUND    = 1815&

'  Not enough quota is available to process this command.
%ERROR_NOT_ENOUGH_QUOTA           = 1816&

'  The group member was not found.
%RPC_S_GROUP_MEMBER_NOT_FOUND     = 1898&

'  The endpoint mapper database could not be created.
%EPT_S_CANT_CREATE                = 1899&

'  The object universal unique identifier (UUID) is the nil UUID.
%RPC_S_INVALID_OBJECT             = 1900&

'  The specified time is invalid.
%ERROR_INVALID_TIME               = 1901&

'  The specified Form name is invalid.
%ERROR_INVALID_FORM_NAME          = 1902&

'  The specified Form size is invalid
%ERROR_INVALID_FORM_SIZE          = 1903&

'  The specified Printer xHandle is already being waited on
%ERROR_ALREADY_WAITING            = 1904&

'  The specified Printer has been deleted
%ERROR_PRINTER_DELETED            = 1905&

'  The state of the Printer is invalid
%ERROR_INVALID_PRINTER_STATE      = 1906&

'  The list of servers for this workgroup is not currently available
%ERROR_NO_BROWSER_SERVERS_FOUND   = 6118&


' -------------------------
' MMSystem Section
' -------------------------

' This section defines all the support for Multimedia applications

' general constants
%MAXPNAMELEN      = 32  ' max product name length (including NULL)
%MAXERRORLENGTH   = 256 ' max error text length (including final NULL)

' values for wType field in MMTIME struct
%TIME_MS       = &H1     ' time in Milliseconds
%TIME_SAMPLES  = &H2     ' number of wave samples
%TIME_BYTES    = &H4     ' current byte offset
%TIME_SMPTE    = &H8     ' SMPTE time
%TIME_MIDI     = &H10    ' MIDI time
%TIME_TICKS    = &H20    ' Ticks within MIDI stream

%MAX_JOYSTICKOEMVXDNAME = 260

' Multimedia Window Messages
%MM_JOY1MOVE            = &H3A0  ' joystick
%MM_JOY2MOVE            = &H3A1
%MM_JOY1ZMOVE           = &H3A2
%MM_JOY2ZMOVE           = &H3A3
%MM_JOY1BUTTONDOWN      = &H3B5
%MM_JOY2BUTTONDOWN      = &H3B6
%MM_JOY1BUTTONUP        = &H3B7
%MM_JOY2BUTTONUP        = &H3B8

%MM_MCINOTIFY           = &H3B9  ' MCI
%MM_MCISYSTEM_STRING    = &H3CA

%MM_WOM_OPEN            = &H3BB  ' waveform output
%MM_WOM_CLOSE           = &H3BC
%MM_WOM_DONE            = &H3BD

%MM_WIM_OPEN            = &H3BE  ' waveform input
%MM_WIM_CLOSE           = &H3BF
%MM_WIM_DATA            = &H3C0

%MM_MIM_OPEN            = &H3C1  ' MIDI input
%MM_MIM_CLOSE           = &H3C2
%MM_MIM_DATA            = &H3C3
%MM_MIM_LONGDATA        = &H3C4
%MM_MIM_ERROR           = &H3C5
%MM_MIM_LONGERROR       = &H3C6

%MM_MOM_OPEN            = &H3C7  ' MIDI output
%MM_MOM_CLOSE           = &H3C8
%MM_MOM_DONE            = &H3C9

' String resource number bases (internal use)

%MMSYSERR_BASE          = 0
%WAVERR_BASE            = 32
%MIDIERR_BASE           = 64
%TIMERR_BASE            = 96   ' was 128, changed to match Win 31 Sonic
%JOYERR_BASE            = 160
%MCIERR_BASE            = 256

%MCI_STRING_OFFSET      = 512  ' if this number is changed you MUST
' alter the MCI_DEVTYPE_... list below
%MCI_VD_OFFSET          = 1024
%MCI_CD_OFFSET          = 1088
%MCI_WAVE_OFFSET        = 1152
%MCI_SEQ_OFFSET         = 1216

' General error return values
%MMSYSERR_NOERROR       = 0  ' no error
%MMSYSERR_ERROR         = %MMSYSERR_BASE + 1  ' unspecified error
%MMSYSERR_BADDEVICEID   = %MMSYSERR_BASE + 2  ' device ID out of range
%MMSYSERR_NOTENABLED    = %MMSYSERR_BASE + 3  ' driver failed enable
%MMSYSERR_ALLOCATED     = %MMSYSERR_BASE + 4  ' device already allocated
%MMSYSERR_INVALHANDLE   = %MMSYSERR_BASE + 5  ' device xHandle is invalid
%MMSYSERR_NODRIVER      = %MMSYSERR_BASE + 6  ' no device driver present
%MMSYSERR_NOMEM         = %MMSYSERR_BASE + 7  ' memory allocation error
%MMSYSERR_NOTSUPPORTED  = %MMSYSERR_BASE + 8  ' function isn't supported
%MMSYSERR_BADERRNUM     = %MMSYSERR_BASE + 9  ' error value out of range
%MMSYSERR_INVALFLAG     = %MMSYSERR_BASE + 10 ' invalid flag passed
%MMSYSERR_INVALPARAM    = %MMSYSERR_BASE + 11 ' invalid parameter passed
%MMSYSERR_HANDLEBUSY    = %MMSYSERR_BASE + 12 ' xHandle being used
' simultaneously on another
' thread (eg callback)
%MMSYSERR_INVALIDALIAS  = %MMSYSERR_BASE + 13 ' "Specified alias not found in WIN.INI
%MMSYSERR_BADDB         = %MMSYSERR_BASE + 14 ' bad registry database
%MMSYSERR_KEYNOTFOUND   = %MMSYSERR_BASE + 15 ' registry key not found
%MMSYSERR_READERROR     = %MMSYSERR_BASE + 16 ' registry read error
%MMSYSERR_WRITEERROR    = %MMSYSERR_BASE + 17 ' registry write error
%MMSYSERR_DELETEERROR   = %MMSYSERR_BASE + 18 ' registry delete error
%MMSYSERR_VALNOTFOUND   = %MMSYSERR_BASE + 19 ' registry value not found
%MMSYSERR_NODRIVERCB    = %MMSYSERR_BASE + 20 ' driver does not call DriverCallback
%MMSYSERR_MOREDATA      = %MMSYSERR_BASE + 21 ' more data to be returned
'%MMSYSERR_LASTERROR     = %MMSYSERR_BASE + 21 ' last error in range (varies by version)
%MM_MOM_POSITIONCB      = &H3CA              ' Callback for MEVT_POSITIONCB
%MM_MCISIGNAL           = &H3CB
%MM_MIM_MOREDATA        = &H3CC                ' MIM_DONE w/ pending events
%MIDICAPS_STREAM        = &H8               ' driver supports midiStreamOut directly

%MM_MIXM_LINE_CHANGE    = &H3D0    ' mixer line change notify
%MM_MIXM_CONTROL_CHANGE = &H3D1    ' mixer control change notify

%MEVT_F_SHORT           = &H0&
%MEVT_F_LONG            = &H80000000???
%MEVT_F_CALLBACK        = &H40000000
%MIDISTRM_ERROR         = -2

'
' Structures and defines for midiStreamProperty
'
%MIDIPROP_SET           = &H80000000???
%MIDIPROP_GET           = &H40000000

' These are intentionally both non-zero so the app cannot accidentally
' leave the operation off and happen to appear to work due to default
' action.

%MIDIPROP_TIMEDIV       = &H1&
%MIDIPROP_TEMPO         = &H2&

%MIXER_SHORT_NAME_CHARS = 16
%MIXER_LONG_NAME_CHARS  = 64

'
'  MMRESULT error return values specific to the mixer API
'
'
%MIXERR_BASE          = 1024
%MIXERR_INVALLINE     = %MIXERR_BASE + 0
%MIXERR_INVALCONTROL  = %MIXERR_BASE + 1
%MIXERR_INVALVALUE    = %MIXERR_BASE + 2
%MIXERR_LASTERROR     = %MIXERR_BASE + 2


%MIXER_OBJECTF_HANDLE   = &H80000000???
%MIXER_OBJECTF_MIXER    = &H0&
%MIXER_OBJECTF_HMIXER   = %MIXER_OBJECTF_HANDLE OR %MIXER_OBJECTF_MIXER
%MIXER_OBJECTF_WAVEOUT  = &H10000000
%MIXER_OBJECTF_HWAVEOUT = %MIXER_OBJECTF_HANDLE OR %MIXER_OBJECTF_WAVEOUT
%MIXER_OBJECTF_WAVEIN   = &H20000000
%MIXER_OBJECTF_HWAVEIN  = %MIXER_OBJECTF_HANDLE OR %MIXER_OBJECTF_WAVEIN
%MIXER_OBJECTF_MIDIOUT  = &H30000000
%MIXER_OBJECTF_HMIDIOUT = %MIXER_OBJECTF_HANDLE OR %MIXER_OBJECTF_MIDIOUT
%MIXER_OBJECTF_MIDIIN   = &H40000000
%MIXER_OBJECTF_HMIDIIN  = %MIXER_OBJECTF_HANDLE OR %MIXER_OBJECTF_MIDIIN
%MIXER_OBJECTF_AUX      = &H50000000

%MIXERLINE_LINEF_ACTIVE       = &H1
%MIXERLINE_LINEF_DISCONNECTED = &H00008000
%MIXERLINE_LINEF_SOURCE       = &H80000000???

'  MIXERLINE.dwComponentType

'  component types for destinations and sources

%MIXERLINE_COMPONENTTYPE_DST_FIRST      = &H0&
%MIXERLINE_COMPONENTTYPE_DST_UNDEFINED  = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 0
%MIXERLINE_COMPONENTTYPE_DST_DIGITAL    = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 1
%MIXERLINE_COMPONENTTYPE_DST_LINE       = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 2
%MIXERLINE_COMPONENTTYPE_DST_MONITOR    = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 3
%MIXERLINE_COMPONENTTYPE_DST_SPEAKERS   = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 4
%MIXERLINE_COMPONENTTYPE_DST_HEADPHONES = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 5
%MIXERLINE_COMPONENTTYPE_DST_TELEPHONE  = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 6
%MIXERLINE_COMPONENTTYPE_DST_WAVEIN     = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 7
%MIXERLINE_COMPONENTTYPE_DST_VOICEIN    = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 8
%MIXERLINE_COMPONENTTYPE_DST_LAST       = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 8

%MIXERLINE_COMPONENTTYPE_SRC_FIRST       = &H1000&
%MIXERLINE_COMPONENTTYPE_SRC_UNDEFINED   = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 0
%MIXERLINE_COMPONENTTYPE_SRC_DIGITAL     = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 1
%MIXERLINE_COMPONENTTYPE_SRC_LINE        = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 2
%MIXERLINE_COMPONENTTYPE_SRC_MICROPHONE  = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 3
%MIXERLINE_COMPONENTTYPE_SRC_SYNTHESIZER = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 4
%MIXERLINE_COMPONENTTYPE_SRC_COMPACTDISC = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 5
%MIXERLINE_COMPONENTTYPE_SRC_TELEPHONE   = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 6
%MIXERLINE_COMPONENTTYPE_SRC_PCSPEAKER   = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 7
%MIXERLINE_COMPONENTTYPE_SRC_WAVEOUT     = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 8
%MIXERLINE_COMPONENTTYPE_SRC_AUXILIARY   = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 9
%MIXERLINE_COMPONENTTYPE_SRC_ANALOG      = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 10
%MIXERLINE_COMPONENTTYPE_SRC_LAST        = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 10


'
'  MIXERLINE.Target.dwType
'
'
%MIXERLINE_TARGETTYPE_UNDEFINED   = 0
%MIXERLINE_TARGETTYPE_WAVEOUT     = 1
%MIXERLINE_TARGETTYPE_WAVEIN      = 2
%MIXERLINE_TARGETTYPE_MIDIOUT     = 3
%MIXERLINE_TARGETTYPE_MIDIIN      = 4
%MIXERLINE_TARGETTYPE_AUX         = 5

%MIXER_GETLINEINFOF_DESTINATION   = &H00
%MIXER_GETLINEINFOF_SOURCE        = &H01
%MIXER_GETLINEINFOF_LINEID        = &H02
%MIXER_GETLINEINFOF_COMPONENTTYPE = &H03
%MIXER_GETLINEINFOF_TARGETTYPE    = &H04
%MIXER_GETLINEINFOF_QUERYMASK     = &H0F

%MIXERCONTROL_CONTROLF_UNIFORM    = &H1
%MIXERCONTROL_CONTROLF_MULTIPLE   = &H2
%MIXERCONTROL_CONTROLF_DISABLED   = &H80000000???

'  MIXERCONTROL_CONTROLTYPE_xxx building block defines

%MIXERCONTROL_CT_CLASS_MASK        = &HF0000000???
%MIXERCONTROL_CT_CLASS_CUSTOM      = &H0&
%MIXERCONTROL_CT_CLASS_METER       = &H10000000
%MIXERCONTROL_CT_CLASS_SWITCH      = &H20000000
%MIXERCONTROL_CT_CLASS_NUMBER      = &H30000000
%MIXERCONTROL_CT_CLASS_SLIDER      = &H40000000
%MIXERCONTROL_CT_CLASS_FADER       = &H50000000
%MIXERCONTROL_CT_CLASS_TIME        = &H60000000
%MIXERCONTROL_CT_CLASS_LIST        = &H70000000
%MIXERCONTROL_CT_SUBCLASS_MASK     = &H0F000000
%MIXERCONTROL_CT_SC_SWITCH_BOOLEAN = &H0
%MIXERCONTROL_CT_SC_SWITCH_BUTTON  = &H01000000
%MIXERCONTROL_CT_SC_METER_POLLED   = &H0
%MIXERCONTROL_CT_SC_TIME_MICROSECS = &H0
%MIXERCONTROL_CT_SC_TIME_MILLISECS = &H01000000
%MIXERCONTROL_CT_SC_LIST_SINGLE    = &H0
%MIXERCONTROL_CT_SC_LIST_MULTIPLE  = &H01000000
%MIXERCONTROL_CT_UNITS_MASK        = &H00FF0000
%MIXERCONTROL_CT_UNITS_CUSTOM      = &H0
%MIXERCONTROL_CT_UNITS_BOOLEAN     = &H10000
%MIXERCONTROL_CT_UNITS_SIGNED      = &H20000
%MIXERCONTROL_CT_UNITS_UNSIGNED    = &H30000
%MIXERCONTROL_CT_UNITS_DECIBELS    = &H40000 ' in 10ths
%MIXERCONTROL_CT_UNITS_PERCENT     = &H50000 ' in 10ths
'
'  Commonly used control types for specifying MIXERCONTROL.dwControlType
'
%MIXERCONTROL_CONTROLTYPE_CUSTOM         = %MIXERCONTROL_CT_CLASS_CUSTOM OR %MIXERCONTROL_CT_UNITS_CUSTOM
%MIXERCONTROL_CONTROLTYPE_BOOLEANMETER   = %MIXERCONTROL_CT_CLASS_METER OR %MIXERCONTROL_CT_SC_METER_POLLED OR %MIXERCONTROL_CT_UNITS_BOOLEAN
%MIXERCONTROL_CONTROLTYPE_SIGNEDMETER    = %MIXERCONTROL_CT_CLASS_METER OR %MIXERCONTROL_CT_SC_METER_POLLED OR %MIXERCONTROL_CT_UNITS_SIGNED
%MIXERCONTROL_CONTROLTYPE_PEAKMETER      = %MIXERCONTROL_CONTROLTYPE_SIGNEDMETER + 1
%MIXERCONTROL_CONTROLTYPE_UNSIGNEDMETER  = %MIXERCONTROL_CT_CLASS_METER OR %MIXERCONTROL_CT_SC_METER_POLLED OR %MIXERCONTROL_CT_UNITS_UNSIGNED
%MIXERCONTROL_CONTROLTYPE_BOOLEAN        = %MIXERCONTROL_CT_CLASS_SWITCH OR %MIXERCONTROL_CT_SC_SWITCH_BOOLEAN OR %MIXERCONTROL_CT_UNITS_BOOLEAN
%MIXERCONTROL_CONTROLTYPE_ONOFF          = %MIXERCONTROL_CONTROLTYPE_BOOLEAN + 1
%MIXERCONTROL_CONTROLTYPE_MUTE           = %MIXERCONTROL_CONTROLTYPE_BOOLEAN + 2
%MIXERCONTROL_CONTROLTYPE_MONO           = %MIXERCONTROL_CONTROLTYPE_BOOLEAN + 3
%MIXERCONTROL_CONTROLTYPE_LOUDNESS       = %MIXERCONTROL_CONTROLTYPE_BOOLEAN + 4
%MIXERCONTROL_CONTROLTYPE_STEREOENH      = %MIXERCONTROL_CONTROLTYPE_BOOLEAN + 5
%MIXERCONTROL_CONTROLTYPE_BUTTON         = %MIXERCONTROL_CT_CLASS_SWITCH OR %MIXERCONTROL_CT_SC_SWITCH_BUTTON OR %MIXERCONTROL_CT_UNITS_BOOLEAN
%MIXERCONTROL_CONTROLTYPE_DECIBELS       = %MIXERCONTROL_CT_CLASS_NUMBER OR %MIXERCONTROL_CT_UNITS_DECIBELS
%MIXERCONTROL_CONTROLTYPE_SIGNED         = %MIXERCONTROL_CT_CLASS_NUMBER OR %MIXERCONTROL_CT_UNITS_SIGNED
%MIXERCONTROL_CONTROLTYPE_UNSIGNED       = %MIXERCONTROL_CT_CLASS_NUMBER OR %MIXERCONTROL_CT_UNITS_UNSIGNED
%MIXERCONTROL_CONTROLTYPE_PERCENT        = %MIXERCONTROL_CT_CLASS_NUMBER OR %MIXERCONTROL_CT_UNITS_PERCENT
%MIXERCONTROL_CONTROLTYPE_SLIDER         = %MIXERCONTROL_CT_CLASS_SLIDER OR %MIXERCONTROL_CT_UNITS_SIGNED
%MIXERCONTROL_CONTROLTYPE_PAN            = %MIXERCONTROL_CONTROLTYPE_SLIDER + 1
%MIXERCONTROL_CONTROLTYPE_QSOUNDPAN      = %MIXERCONTROL_CONTROLTYPE_SLIDER + 2
%MIXERCONTROL_CONTROLTYPE_FADER          = %MIXERCONTROL_CT_CLASS_FADER OR %MIXERCONTROL_CT_UNITS_UNSIGNED
%MIXERCONTROL_CONTROLTYPE_VOLUME         = %MIXERCONTROL_CONTROLTYPE_FADER + 1
%MIXERCONTROL_CONTROLTYPE_BASS           = %MIXERCONTROL_CONTROLTYPE_FADER + 2
%MIXERCONTROL_CONTROLTYPE_TREBLE         = %MIXERCONTROL_CONTROLTYPE_FADER + 3
%MIXERCONTROL_CONTROLTYPE_EQUALIZER      = %MIXERCONTROL_CONTROLTYPE_FADER + 4
%MIXERCONTROL_CONTROLTYPE_SINGLESELECT   = %MIXERCONTROL_CT_CLASS_LIST OR %MIXERCONTROL_CT_SC_LIST_SINGLE OR %MIXERCONTROL_CT_UNITS_BOOLEAN
%MIXERCONTROL_CONTROLTYPE_MUX            = %MIXERCONTROL_CONTROLTYPE_SINGLESELECT + 1
%MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT = %MIXERCONTROL_CT_CLASS_LIST OR %MIXERCONTROL_CT_SC_LIST_MULTIPLE OR %MIXERCONTROL_CT_UNITS_BOOLEAN
%MIXERCONTROL_CONTROLTYPE_MIXER          = %MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT + 1
%MIXERCONTROL_CONTROLTYPE_MICROTIME      = %MIXERCONTROL_CT_CLASS_TIME OR %MIXERCONTROL_CT_SC_TIME_MICROSECS OR %MIXERCONTROL_CT_UNITS_UNSIGNED
%MIXERCONTROL_CONTROLTYPE_MILLITIME      = %MIXERCONTROL_CT_CLASS_TIME OR %MIXERCONTROL_CT_SC_TIME_MILLISECS OR %MIXERCONTROL_CT_UNITS_UNSIGNED
'
%MIXER_GETLINECONTROLSF_ALL            = &H0&
%MIXER_GETLINECONTROLSF_ONEBYID        = &H1&
%MIXER_GETLINECONTROLSF_ONEBYTYPE      = &H2&
%MIXER_GETLINECONTROLSF_QUERYMASK      = &HF&

%MIXER_GETCONTROLDETAILSF_VALUE        = &H0&
%MIXER_GETCONTROLDETAILSF_LISTTEXT     = &H1&
%MIXER_GETCONTROLDETAILSF_QUERYMASK    = &HF&

%MIXER_SETCONTROLDETAILSF_VALUE        = &H0&
%MIXER_SETCONTROLDETAILSF_CUSTOM       = &H1&
%MIXER_SETCONTROLDETAILSF_QUERYMASK    = &HF&

' constants used with JOYINFOEX
%JOY_BUTTON5    = &H00000010
%JOY_BUTTON6    = &H00000020
%JOY_BUTTON7    = &H00000040
%JOY_BUTTON8    = &H00000080
%JOY_BUTTON9    = &H00000100
%JOY_BUTTON10   = &H00000200
%JOY_BUTTON11   = &H00000400
%JOY_BUTTON12   = &H00000800
%JOY_BUTTON13   = &H00001000
%JOY_BUTTON14   = &H00002000
%JOY_BUTTON15   = &H00004000
%JOY_BUTTON16   = &H00008000
%JOY_BUTTON17   = &H00010000
%JOY_BUTTON18   = &H00020000
%JOY_BUTTON19   = &H00040000
%JOY_BUTTON20   = &H00080000
%JOY_BUTTON21   = &H00100000
%JOY_BUTTON22   = &H00200000
%JOY_BUTTON23   = &H00400000
%JOY_BUTTON24   = &H00800000
%JOY_BUTTON25   = &H01000000
%JOY_BUTTON26   = &H02000000
%JOY_BUTTON27   = &H04000000
%JOY_BUTTON28   = &H08000000
%JOY_BUTTON29   = &H10000000
%JOY_BUTTON30   = &H20000000
%JOY_BUTTON31   = &H40000000
%JOY_BUTTON32   = &H80000000??

' constants used with JOYINFOEX structure
%JOY_POVCENTERED      = &HFFFF??  ' (WORD)-1
%JOY_POVFORWARD       = 0
%JOY_POVRIGHT         = 9000
%JOY_POVBACKWARD      = 18000
%JOY_POVLEFT          = 27000
%JOY_RETURNX          = &H1&
%JOY_RETURNY          = &H2&
%JOY_RETURNZ          = &H4&
%JOY_RETURNR          = &H8&
%JOY_RETURNU          = &H10    ' axis 5
%JOY_RETURNV          = &H20    ' axis 6
%JOY_RETURNPOV        = &H40&
%JOY_RETURNBUTTONS    = &H80&
%JOY_RETURNRAWDATA    = &H100&
%JOY_RETURNPOVCTS     = &H200&
%JOY_RETURNCENTERED   = &H400&
%JOY_USEDEADZONE      = &H800&
%JOY_RETURNALL        = %JOY_RETURNX OR %JOY_RETURNY OR %JOY_RETURNZ OR %JOY_RETURNR OR %JOY_RETURNU OR %JOY_RETURNV OR %JOY_RETURNPOV OR %JOY_RETURNBUTTONS
%JOY_CAL_READALWAYS   = &H10000
%JOY_CAL_READXYONLY   = &H20000
%JOY_CAL_READ3        = &H40000
%JOY_CAL_READ4        = &H80000
%JOY_CAL_READXONLY    = &H100000
%JOY_CAL_READYONLY    = &H200000
%JOY_CAL_READ5        = &H400000
%JOY_CAL_READ6        = &H800000
%JOY_CAL_READZONLY    = &H1000000
%JOY_CAL_READRONLY    = &H2000000
%JOY_CAL_READUONLY    = &H4000000
%JOY_CAL_READVONLY    = &H8000000

%WAVE_FORMAT_QUERY         = &H1
%SND_PURGE                 = &H40  ' purge non-static events for task
%SND_APPLICATION           = &H80? ' look for application specific association
%WAVE_MAPPED               = &H4
%WAVE_FORMAT_DIRECT        = &H8
%WAVE_FORMAT_DIRECT_QUERY  = %WAVE_FORMAT_QUERY OR %WAVE_FORMAT_DIRECT
%MIM_MOREDATA              = %MM_MIM_MOREDATA
%MOM_POSITIONCB            = %MM_MOM_POSITIONCB

' flags for dwFlags parm of midiInOpen()
%MIDI_IO_STATUS                        = &H20&

' Driver messages
%DRV_LOAD           = &H01
%DRV_ENABLE         = &H02
%DRV_OPEN           = &H03
%DRV_CLOSE          = &H04
%DRV_DISABLE        = &H05
%DRV_FREE           = &H06
%DRV_CONFIGURE      = &H07
%DRV_QUERYCONFIGURE = &H08
%DRV_INSTALL        = &H09
%DRV_REMOVE         = &H0A
%DRV_EXITSESSION    = &H0B
%DRV_POWER          = &H0F
%DRV_RESERVED       = &H0800
%DRV_USER           = &H4000

' Supported return values for DRV_CONFIGURE message
%DRVCNF_CANCEL  = &H0
%DRVCNF_OK      = &H1
%DRVCNF_RESTART = &H2

' return values from DriverProc() function
%DRV_CANCEL     = %DRVCNF_CANCEL
%DRV_OK         = %DRVCNF_OK
%DRV_RESTART    = %DRVCNF_RESTART

%DRV_MCI_FIRST  = %DRV_RESERVED
%DRV_MCI_LAST   = %DRV_RESERVED + &H0FFF

' Driver callback support

' flags used with waveOutOpen(), waveInOpen(), midiInOpen(), and
' midiOutOpen() to specify the type of the dwCallback parameter.
%CALLBACK_TYPEMASK    = &H70000      ' callback type mask
%CALLBACK_NULL        = &H0        ' no callback
%CALLBACK_WINDOW      = &H10000      ' dwCallback is a HWND
%CALLBACK_TASK        = &H20000      ' dwCallback is a HTASK
%CALLBACK_FUNCTION    = &H30000      ' dwCallback is a FARPROC

' manufacturer IDs
%MM_MICROSOFT         = 1  ' Microsoft Corp.

' product IDs
%MM_MIDI_MAPPER       = 1  ' MIDI Mapper
%MM_WAVE_MAPPER       = 2  ' Wave Mapper

%MM_SNDBLST_MIDIOUT   = 3  ' Sound Blaster MIDI output port
%MM_SNDBLST_MIDIIN    = 4  ' Sound Blaster MIDI input port
%MM_SNDBLST_SYNTH     = 5  ' Sound Blaster internal synthesizer
%MM_SNDBLST_WAVEOUT   = 6  ' Sound Blaster waveform output
%MM_SNDBLST_WAVEIN    = 7  ' Sound Blaster waveform input

%MM_ADLIB             = 9  ' Ad Lib-compatible synthesizer

%MM_MPU401_MIDIOUT    = 10  ' MPU401-compatible MIDI output port
%MM_MPU401_MIDIIN     = 11  ' MPU401-compatible MIDI input port

%MM_PC_JOYSTICK       = 12  ' Joystick adapter

' flag values for uFlags parameter
%SND_SYNC             = &H0         ' play synchronously (default)
%SND_ASYNC            = &H1         ' play asynchronously

%SND_NODEFAULT        = &H2         ' silence not default, if sound not found

%SND_MEMORY           = &H4         ' lpszSoundName points to a memory file
%SND_ALIAS            = &H10000     ' name is a WIN.INI [sounds] entry
%SND_FILENAME         = &H20000     ' name is a file name
%SND_RESOURCE         = &H40004     ' name is a resource name or atom
%SND_ALIAS_ID         = &H110000    ' name is a WIN.INI [sounds] entry identifier

%SND_ALIAS_START      = 0  ' must be > 4096 to keep strings in same section of resource file

%SND_LOOP             = &H8         ' loop the sound until next sndPlaySound
%SND_NOSTOP           = &H10        ' don't stop any currently playing sound
%SND_VALID            = &H1F        ' valid flags          / ;Internal /

%SND_NOWAIT           = &H2000      ' don't wait if the driver is busy

%SND_VALIDFLAGS       = &H17201F    ' Set of valid flag bits.  Anything outside
' this range will raise an error
%SND_RESERVED         = &HFF000000  ' In particular these flags are reserved

%SND_TYPE_MASK        = &H170007

' waveform audio error return values
%WAVERR_BADFORMAT     = %WAVERR_BASE + 0    ' unsupported wave format
%WAVERR_STILLPLAYING  = %WAVERR_BASE + 1    ' still something playing
%WAVERR_UNPREPARED    = %WAVERR_BASE + 2    ' header not prepared
%WAVERR_SYNC          = %WAVERR_BASE + 3    ' device is synchronous
%WAVERR_LASTERROR     = %WAVERR_BASE + 3    ' last error in range

' wave callback messages
%WOM_OPEN             = %MM_WOM_OPEN
%WOM_CLOSE            = %MM_WOM_CLOSE
%WOM_DONE             = %MM_WOM_DONE
%WIM_OPEN             = %MM_WIM_OPEN
%WIM_CLOSE            = %MM_WIM_CLOSE
%WIM_DATA             = %MM_WIM_DATA

' device ID for wave device mapper
%WAVE_MAPPER          = &HFFFFFFFF??? ' (DWORD)-1

' flags for dwFlags parameter in waveOutOpen() and waveInOpen()

%WAVE_ALLOWSYNC       = &H2
%WAVE_VALID           = &H3         ' ;Internal

' flags for dwFlags field of WAVEHDR
%WHDR_DONE            = &H1         ' done bit
%WHDR_PREPARED        = &H2         ' set if this header has been prepared
%WHDR_BEGINLOOP       = &H4         ' loop start block
%WHDR_ENDLOOP         = &H8         ' loop end block
%WHDR_INQUEUE         = &H10        ' reserved for driver
%WHDR_VALID           = &H1F        ' valid flags      / ;Internal /

' flags for dwSupport field of WAVEOUTCAPS
%WAVECAPS_PITCH        = &H1         ' supports pitch control
%WAVECAPS_PLAYBACKRATE = &H2         ' supports playback rate control
%WAVECAPS_VOLUME       = &H4         ' supports volume control
%WAVECAPS_LRVOLUME     = &H8         ' separate left-right volume control
%WAVECAPS_SYNC         = &H10

' defines for dwFormat field of WAVEINCAPS and WAVEOUTCAPS
%WAVE_INVALIDFORMAT   = &H0000            ' invalid format
%WAVE_FORMAT_1M08     = &H0001            ' 11.025 kHz, Mono,   8-bit
%WAVE_FORMAT_1S08     = &H0002            ' 11.025 kHz, Stereo, 8-bit
%WAVE_FORMAT_1M16     = &H0004            ' 11.025 kHz, Mono,   16-bit
%WAVE_FORMAT_1S16     = &H0008            ' 11.025 kHz, Stereo, 16-bit
%WAVE_FORMAT_2M08     = &H0010            ' 22.05  kHz, Mono,   8-bit
%WAVE_FORMAT_2S08     = &H0020            ' 22.05  kHz, Stereo, 8-bit
%WAVE_FORMAT_2M16     = &H0040            ' 22.05  kHz, Mono,   16-bit
%WAVE_FORMAT_2S16     = &H0080            ' 22.05  kHz, Stereo, 16-bit
%WAVE_FORMAT_4M08     = &H0100            ' 44.1   kHz, Mono,   8-bit
%WAVE_FORMAT_4S08     = &H0200            ' 44.1   kHz, Stereo, 8-bit
%WAVE_FORMAT_4M16     = &H0400            ' 44.1   kHz, Mono,   16-bit
%WAVE_FORMAT_4S16     = &H0800            ' 44.1   kHz, Stereo, 16-bit

' flags for wFormatTag field of WAVEFORMAT
%WAVE_FORMAT_PCM      = 1  ' Needed in resource files so outside #ifndef RC_INVOKED

' MIDI error return values
%MIDIERR_UNPREPARED    = %MIDIERR_BASE + 0   ' header not prepared
%MIDIERR_STILLPLAYING  = %MIDIERR_BASE + 1   ' still something playing
%MIDIERR_NOMAP         = %MIDIERR_BASE + 2   ' no current map
%MIDIERR_NOTREADY      = %MIDIERR_BASE + 3   ' hardware is still busy
%MIDIERR_NODEVICE      = %MIDIERR_BASE + 4   ' port no longer connected
%MIDIERR_INVALIDSETUP  = %MIDIERR_BASE + 5   ' invalid setup
%MIDIERR_BADOPENMODE   = %MIDIERR_BASE + 6   ' operation unsupported w/ open mode
%MIDIERR_DONT_CONTINUE = %MIDIERR_BASE + 7   ' thru device 'eating' a message
%MIDIERR_LASTERROR     = %MIDIERR_BASE + 7   ' last error in range

' MIDI callback messages
%MIM_OPEN             = %MM_MIM_OPEN
%MIM_CLOSE            = %MM_MIM_CLOSE
%MIM_DATA             = %MM_MIM_DATA
%MIM_LONGDATA         = %MM_MIM_LONGDATA
%MIM_ERROR            = %MM_MIM_ERROR
%MIM_LONGERROR        = %MM_MIM_LONGERROR
%MOM_OPEN             = %MM_MOM_OPEN
%MOM_CLOSE            = %MM_MOM_CLOSE
%MOM_DONE             = %MM_MOM_DONE

#IF NOT %DEF(%MM_DRVM_OPEN)
  %MM_DRVM_OPEN         = &H3D0             ' installable drivers
  %MM_DRVM_CLOSE        = &H3D1
  %MM_DRVM_DATA         = &H3D2
  %MM_DRVM_ERROR        = &H3D3
#ENDIF

%MM_STREAM_OPEN       = &H3D4
%MM_STREAM_CLOSE      = &H3D5
%MM_STREAM_DONE       = &H3D6
%MM_STREAM_ERROR      = &H3D7

' device ID for MIDI mapper
%MIDIMAPPER           = &HFFFFFFFF???
%MIDI_MAPPER          = &HFFFFFFFF???

' flags for wFlags parm of midiOutCachePatches(), midiOutCacheDrumPatches()
%MIDI_CACHE_ALL       = 1
%MIDI_CACHE_BESTFIT   = 2
%MIDI_CACHE_QUERY     = 3
%MIDI_UNCACHE         = 4
%MIDI_CACHE_VALID     = %MIDI_CACHE_ALL OR %MIDI_CACHE_BESTFIT OR %MIDI_CACHE_QUERY OR %MIDI_UNCACHE  ' ;Internal

' flags for wTechnology field of MIDIOUTCAPS structure
%MOD_MIDIPORT         = 1  ' output port
%MOD_SYNTH            = 2  ' generic internal synth
%MOD_SQSYNTH          = 3  ' square wave internal synth
%MOD_FMSYNTH          = 4  ' FM internal synth
%MOD_MAPPER           = 5  ' MIDI mapper

' flags for dwSupport field of MIDIOUTCAPS
%MIDICAPS_VOLUME      = &H1         ' supports volume control
%MIDICAPS_LRVOLUME    = &H2         ' separate left-right volume control
%MIDICAPS_CACHE       = &H4

' flags for dwFlags field of MIDIHDR structure
%MHDR_DONE            = &H1         ' done bit
%MHDR_PREPARED        = &H2         ' set if header prepared
%MHDR_INQUEUE         = &H4         ' reserved for driver
%MHDR_VALID           = &H7         ' valid flags / ;Internal /

' device ID for aux device mapper
%AUX_MAPPER           = &HFFFFFFFF???

' flags for wTechnology field in AUXCAPS structure
%AUXCAPS_CDAUDIO      = 1  ' audio from internal CD-ROM drive
%AUXCAPS_AUXIN        = 2  ' audio from auxiliary input jacks

' flags for dwSupport field in AUXCAPS structure
%AUXCAPS_VOLUME       = &H1         ' supports volume control
%AUXCAPS_LRVOLUME     = &H2         ' separate left-right volume control

' timer error return values
%TIMERR_NOERROR       = 0  ' no error
%TIMERR_NOCANDO       = %TIMERR_BASE + 1 ' request not completed
%TIMERR_STRUCT        = %TIMERR_BASE + 33 ' time struct size

' flags for wFlags parameter of timeSetEvent() function
%TIME_ONESHOT         = 0  ' program timer for single event
%TIME_PERIODIC        = 1  ' program for continuous periodic event

' joystick error return values
%JOYERR_NOERROR       = 0  ' no error
%JOYERR_PARMS         = %JOYERR_BASE + 5 ' bad parameters
%JOYERR_NOCANDO       = %JOYERR_BASE + 6 ' request not completed
%JOYERR_UNPLUGGED     = %JOYERR_BASE + 7 ' joystick is unplugged

' constants used with JOYINFO structure and MM_JOY messages
%JOY_BUTTON1          = &H0001
%JOY_BUTTON2          = &H0002
%JOY_BUTTON3          = &H0004
%JOY_BUTTON4          = &H0008
%JOY_BUTTON1CHG       = &H0100
%JOY_BUTTON2CHG       = &H0200
%JOY_BUTTON3CHG       = &H0400
%JOY_BUTTON4CHG       = &H0800

' joystick ID constants
%JOYSTICKID1          = 0
%JOYSTICKID2          = 1

' MMIO error return values
%MMIOERR_BASE             = 256
%MMIOERR_FILENOTFOUND     = %MMIOERR_BASE + 1  ' file not found
%MMIOERR_OUTOFMEMORY      = %MMIOERR_BASE + 2  ' out of memory
%MMIOERR_CANNOTOPEN       = %MMIOERR_BASE + 3  ' cannot open
%MMIOERR_CANNOTCLOSE      = %MMIOERR_BASE + 4  ' cannot close
%MMIOERR_CANNOTREAD       = %MMIOERR_BASE + 5  ' cannot read
%MMIOERR_CANNOTWRITE      = %MMIOERR_BASE + 6  ' cannot write
%MMIOERR_CANNOTSEEK       = %MMIOERR_BASE + 7  ' cannot seek
%MMIOERR_CANNOTEXPAND     = %MMIOERR_BASE + 8  ' cannot expand file
%MMIOERR_CHUNKNOTFOUND    = %MMIOERR_BASE + 9  ' chunk not found
%MMIOERR_UNBUFFERED       = %MMIOERR_BASE + 10 ' file is unbuffered
%MMIOERR_PATHNOTFOUND     = %MMIOERR_BASE + 11 ' path incorrect
%MMIOERR_ACCESSDENIED     = %MMIOERR_BASE + 12 ' file was protected
%MMIOERR_SHARINGVIOLATION = %MMIOERR_BASE + 13 ' file in use
%MMIOERR_NETWORKERROR     = %MMIOERR_BASE + 14 ' network not responding
%MMIOERR_TOOMANYOPENFILES = %MMIOERR_BASE + 15 ' no more file handles
%MMIOERR_INVALIDFILE      = %MMIOERR_BASE + 16 ' default error file error

%MMIO_RWMODE          = &H3         ' open file for reading/writing/both
%MMIO_SHAREMODE       = &H70        ' file sharing mode number

' constants for dwFlags field of MMIOINFO
%MMIO_CREATE          = &H1000      ' create new file (or truncate file)
%MMIO_PARSE           = &H100       ' parse new file returning path
%MMIO_DELETE          = &H200       ' create new file (or truncate file)
%MMIO_EXIST           = &H4000      ' checks for existence of file
%MMIO_ALLOCBUF        = &H10000     ' mmioOpen() should allocate a buffer
%MMIO_GETTEMP         = &H20000     ' mmioOpen() should retrieve temp name

%MMIO_DIRTY           = &H10000000  ' I/O buffer is dirty
' MMIO_DIRTY is also used in the <dwFlags> field of MMCKINFO structure

%MMIO_OPEN_VALID      = &H3FFFF     ' valid flags for mmioOpen / ;Internal /

' read/write mode numbers (bit field MMIO_RWMODE)
%MMIO_READ            = &H0         ' open file for reading only
%MMIO_WRITE           = &H1         ' open file for writing only
%MMIO_READWRITE       = &H2         ' open file for reading and writing

' share mode numbers (bit field MMIO_SHAREMODE)
%MMIO_COMPAT          = &H0         ' compatibility mode
%MMIO_EXCLUSIVE       = &H10        ' exclusive-access mode
%MMIO_DENYWRITE       = &H20        ' deny writing to other processes
%MMIO_DENYREAD        = &H30        ' deny reading to other processes
%MMIO_DENYNONE        = &H40        ' deny nothing to other processes

' flags for other functions
%MMIO_FHOPEN          = &H10    ' mmioClose(): keep file xHandle open
%MMIO_EMPTYBUF        = &H10    ' mmioFlush(): empty the I/O buffer
%MMIO_TOUPPER         = &H10    ' mmioStringToFOURCC(): cvt. to u-case
%MMIO_INSTALLPROC     = &H10000     ' mmioInstallIOProc(): install MMIOProc
%MMIO_PUBLICPROC      = &H10000000  ' mmioInstallIOProc: install Globally
%MMIO_UNICODEPROC     = &H1000000   ' mmioInstallIOProc(): Unicode MMIOProc
%MMIO_REMOVEPROC      = &H20000     ' mmioInstallIOProc(): remove MMIOProc
%MMIO_FINDPROC        = &H40000     ' mmioInstallIOProc(): find an MMIOProc
%MMIO_FINDCHUNK       = &H10    ' mmioDescend(): find a chunk by ID
%MMIO_FINDRIFF        = &H20    ' mmioDescend(): find a LIST chunk
%MMIO_FINDLIST        = &H40    ' mmioDescend(): find a RIFF chunk
%MMIO_CREATERIFF      = &H20    ' mmioCreateChunk(): make a LIST chunk
%MMIO_CREATELIST      = &H40    ' mmioCreateChunk(): make a RIFF chunk

%MMIO_VALIDPROC       = &H11070000  ' valid for mmioInstallIOProc / ;Internal /

' message numbers for MMIOPROC I/O procedure functions
%MMIOM_READ           = %MMIO_READ  ' read (must equal MMIO_READ!)
%MMIOM_WRITE          = %MMIO_WRITE  ' write (must equal MMIO_WRITE!)
%MMIOM_SEEK           = 2  ' seek to a new position in file
%MMIOM_OPEN           = 3  ' open file
%MMIOM_CLOSE          = 4  ' close file
%MMIOM_WRITEFLUSH     = 5  ' write and flush
%MMIOM_RENAME         = 6  ' rename specified file
%MMIOM_USER           = &H00008000  ' beginning of user-defined messages

' flags for mmioSeek()
%SEEK_SET             = 0  ' seek to an absolute position
%SEEK_CUR             = 1  ' seek relative to current position
%SEEK_END             = 2  ' seek relative to end of file

' other constants
%MMIO_DEFAULTBUFFER   = 8192  ' default buffer size

'  MCI error return values
%MCIERR_INVALID_DEVICE_ID       = %MCIERR_BASE + 1
%MCIERR_UNRECOGNIZED_KEYWORD    = %MCIERR_BASE + 3
%MCIERR_UNRECOGNIZED_COMMAND    = %MCIERR_BASE + 5
%MCIERR_HARDWARE                = %MCIERR_BASE + 6
%MCIERR_INVALID_DEVICE_NAME     = %MCIERR_BASE + 7
%MCIERR_OUT_OF_MEMORY           = %MCIERR_BASE + 8
%MCIERR_DEVICE_OPEN             = %MCIERR_BASE + 9
%MCIERR_CANNOT_LOAD_DRIVER      = %MCIERR_BASE + 10
%MCIERR_MISSING_COMMAND_STRING  = %MCIERR_BASE + 11
%MCIERR_PARAM_OVERFLOW          = %MCIERR_BASE + 12
%MCIERR_MISSING_STRING_ARGUMENT = %MCIERR_BASE + 13
%MCIERR_BAD_INTEGER             = %MCIERR_BASE + 14
%MCIERR_PARSER_INTERNAL         = %MCIERR_BASE + 15
%MCIERR_DRIVER_INTERNAL         = %MCIERR_BASE + 16
%MCIERR_MISSING_PARAMETER       = %MCIERR_BASE + 17
%MCIERR_UNSUPPORTED_FUNCTION    = %MCIERR_BASE + 18
%MCIERR_FILE_NOT_FOUND          = %MCIERR_BASE + 19
%MCIERR_DEVICE_NOT_READY        = %MCIERR_BASE + 20
%MCIERR_INTERNAL                = %MCIERR_BASE + 21
%MCIERR_DRIVER                  = %MCIERR_BASE + 22
%MCIERR_CANNOT_USE_ALL          = %MCIERR_BASE + 23
%MCIERR_MULTIPLE                = %MCIERR_BASE + 24
%MCIERR_EXTENSION_NOT_FOUND     = %MCIERR_BASE + 25
%MCIERR_OUTOFRANGE              = %MCIERR_BASE + 26
%MCIERR_FLAGS_NOT_COMPATIBLE    = %MCIERR_BASE + 28
%MCIERR_FILE_NOT_SAVED          = %MCIERR_BASE + 30
%MCIERR_DEVICE_TYPE_REQUIRED    = %MCIERR_BASE + 31
%MCIERR_DEVICE_LOCKED           = %MCIERR_BASE + 32
%MCIERR_DUPLICATE_ALIAS         = %MCIERR_BASE + 33
%MCIERR_BAD_CONSTANT            = %MCIERR_BASE + 34
%MCIERR_MUST_USE_SHAREABLE      = %MCIERR_BASE + 35
%MCIERR_MISSING_DEVICE_NAME     = %MCIERR_BASE + 36
%MCIERR_BAD_TIME_FORMAT         = %MCIERR_BASE + 37
%MCIERR_NO_CLOSING_QUOTE        = %MCIERR_BASE + 38
%MCIERR_DUPLICATE_FLAGS         = %MCIERR_BASE + 39
%MCIERR_INVALID_FILE            = %MCIERR_BASE + 40
%MCIERR_NULL_PARAMETER_BLOCK    = %MCIERR_BASE + 41
%MCIERR_UNNAMED_RESOURCE        = %MCIERR_BASE + 42
%MCIERR_NEW_REQUIRES_ALIAS      = %MCIERR_BASE + 43
%MCIERR_NOTIFY_ON_AUTO_OPEN     = %MCIERR_BASE + 44
%MCIERR_NO_ELEMENT_ALLOWED      = %MCIERR_BASE + 45
%MCIERR_NONAPPLICABLE_FUNCTION  = %MCIERR_BASE + 46
%MCIERR_ILLEGAL_FOR_AUTO_OPEN   = %MCIERR_BASE + 47
%MCIERR_FILENAME_REQUIRED       = %MCIERR_BASE + 48
%MCIERR_EXTRA_CHARACTERS        = %MCIERR_BASE + 49
%MCIERR_DEVICE_NOT_INSTALLED    = %MCIERR_BASE + 50
%MCIERR_GET_CD                  = %MCIERR_BASE + 51
%MCIERR_SET_CD                  = %MCIERR_BASE + 52
%MCIERR_SET_DRIVE               = %MCIERR_BASE + 53
%MCIERR_DEVICE_LENGTH           = %MCIERR_BASE + 54
%MCIERR_DEVICE_ORD_LENGTH       = %MCIERR_BASE + 55
%MCIERR_NO_INTEGER              = %MCIERR_BASE + 56

%MCIERR_WAVE_OUTPUTSINUSE        = %MCIERR_BASE + 64
%MCIERR_WAVE_SETOUTPUTINUSE      = %MCIERR_BASE + 65
%MCIERR_WAVE_INPUTSINUSE         = %MCIERR_BASE + 66
%MCIERR_WAVE_SETINPUTINUSE       = %MCIERR_BASE + 67
%MCIERR_WAVE_OUTPUTUNSPECIFIED   = %MCIERR_BASE + 68
%MCIERR_WAVE_INPUTUNSPECIFIED    = %MCIERR_BASE + 69
%MCIERR_WAVE_OUTPUTSUNSUITABLE   = %MCIERR_BASE + 70
%MCIERR_WAVE_SETOUTPUTUNSUITABLE = %MCIERR_BASE + 71
%MCIERR_WAVE_INPUTSUNSUITABLE    = %MCIERR_BASE + 72
%MCIERR_WAVE_SETINPUTUNSUITABLE  = %MCIERR_BASE + 73

%MCIERR_SEQ_DIV_INCOMPATIBLE    = %MCIERR_BASE + 80
%MCIERR_SEQ_PORT_INUSE          = %MCIERR_BASE + 81
%MCIERR_SEQ_PORT_NONEXISTENT    = %MCIERR_BASE + 82
%MCIERR_SEQ_PORT_MAPNODEVICE    = %MCIERR_BASE + 83
%MCIERR_SEQ_PORT_MISCERROR      = %MCIERR_BASE + 84
%MCIERR_SEQ_TIMER               = %MCIERR_BASE + 85
%MCIERR_SEQ_PORTUNSPECIFIED     = %MCIERR_BASE + 86
%MCIERR_SEQ_NOMIDIPRESENT       = %MCIERR_BASE + 87

%MCIERR_NO_WINDOW               = %MCIERR_BASE + 90
%MCIERR_CREATEWINDOW            = %MCIERR_BASE + 91
%MCIERR_FILE_READ               = %MCIERR_BASE + 92
%MCIERR_FILE_WRITE              = %MCIERR_BASE + 93

%MCIERR_NO_IDENTITY             = %MCIERR_BASE + 94

' All custom device driver errors must be >= this value
%MCIERR_CUSTOM_DRIVER_BASE      = %MCIERR_BASE + 256

' Message numbers must be in the range between MCI_FIRST and MCI_LAST

%MCI_FIRST         = %DRV_MCI_FIRST   ' &H0800
' Messages &H801 and &H802 are reserved
%MCI_OPEN          = &H0803
%MCI_CLOSE         = &H0804
%MCI_ESCAPE        = &H0805
%MCI_PLAY          = &H0806
%MCI_SEEK          = &H0807
%MCI_STOP          = &H0808
%MCI_PAUSE         = &H0809
%MCI_INFO          = &H080A
%MCI_GETDEVCAPS    = &H080B
%MCI_SPIN          = &H080C
%MCI_SET           = &H080D
%MCI_STEP          = &H080E
%MCI_RECORD        = &H080F
%MCI_SYSINFO       = &H0810
%MCI_BREAK         = &H0811
%MCI_SOUND         = &H0812
%MCI_SAVE          = &H0813
%MCI_STATUS        = &H0814

%MCI_CUE           = &H0830

%MCI_REALIZE       = &H0840
%MCI_WINDOW        = &H0841
%MCI_PUT           = &H0842
%MCI_WHERE         = &H0843
%MCI_FREEZE        = &H0844
%MCI_UNFREEZE      = &H0845

%MCI_LOAD          = &H0850
%MCI_CUT           = &H0851
%MCI_COPY          = &H0852
%MCI_PASTE         = &H0853
%MCI_UPDATE        = &H0854
%MCI_RESUME        = &H0855
%MCI_DELETE        = &H0856

%MCI_LAST          = &H0FFF

' the next &H400 message ID's are reserved for custom drivers
' all custom MCI command messages must be >= than this value
%MCI_USER_MESSAGES           = &H400 + %MCI_FIRST
%MCI_ALL_DEVICE_ID           = &HFFFFFFFF??? ' Matches all MCI devices

' constants for predefined MCI device types
%MCI_DEVTYPE_VCR             = 513
%MCI_DEVTYPE_VIDEODISC       = 514
%MCI_DEVTYPE_OVERLAY         = 515
%MCI_DEVTYPE_CD_AUDIO        = 516
%MCI_DEVTYPE_DAT             = 517
%MCI_DEVTYPE_SCANNER         = 518
%MCI_DEVTYPE_ANIMATION       = 519
%MCI_DEVTYPE_DIGITAL_VIDEO   = 520
%MCI_DEVTYPE_OTHER           = 521
%MCI_DEVTYPE_WAVEFORM_AUDIO  = 522
%MCI_DEVTYPE_SEQUENCER       = 523

%MCI_DEVTYPE_FIRST           = %MCI_DEVTYPE_VCR
%MCI_DEVTYPE_LAST            = %MCI_DEVTYPE_SEQUENCER

%MCI_DEVTYPE_FIRST_USER      = &H1000

' return values for 'status mode' command
%MCI_MODE_NOT_READY          = %MCI_STRING_OFFSET + 12
%MCI_MODE_STOP               = %MCI_STRING_OFFSET + 13
%MCI_MODE_PLAY               = %MCI_STRING_OFFSET + 14
%MCI_MODE_RECORD             = %MCI_STRING_OFFSET + 15
%MCI_MODE_SEEK               = %MCI_STRING_OFFSET + 16
%MCI_MODE_PAUSE              = %MCI_STRING_OFFSET + 17
%MCI_MODE_OPEN               = %MCI_STRING_OFFSET + 18

' constants used in 'set time format' and 'status time format' commands
%MCI_FORMAT_MILLISECONDS     = 0
%MCI_FORMAT_HMS              = 1
%MCI_FORMAT_MSF              = 2
%MCI_FORMAT_FRAMES           = 3
%MCI_FORMAT_SMPTE_24         = 4
%MCI_FORMAT_SMPTE_25         = 5
%MCI_FORMAT_SMPTE_30         = 6
%MCI_FORMAT_SMPTE_30DROP     = 7
%MCI_FORMAT_BYTES            = 8
%MCI_FORMAT_SAMPLES          = 9
%MCI_FORMAT_TMSF             = 10

' Flags for wParam of the MM_MCINOTIFY message
%MCI_NOTIFY_SUCCESSFUL       = &H1
%MCI_NOTIFY_SUPERSEDED       = &H2
%MCI_NOTIFY_ABORTED          = &H4
%MCI_NOTIFY_FAILURE          = &H8

' common flags for dwFlags parameter of MCI command messages
%MCI_NOTIFY                  = &H1&
%MCI_WAIT                    = &H2&
%MCI_FROM                    = &H4&
%MCI_TO                      = &H8&
%MCI_TRACK                   = &H10&

' flags for dwFlags parameter of MCI_OPEN command message
%MCI_OPEN_SHAREABLE          = &H100&
%MCI_OPEN_ELEMENT            = &H200&
%MCI_OPEN_ALIAS              = &H400&
%MCI_OPEN_ELEMENT_ID         = &H800&
%MCI_OPEN_TYPE_ID            = &H1000&
%MCI_OPEN_TYPE               = &H2000&

' flags for dwFlags parameter of MCI_SEEK command message
%MCI_SEEK_TO_START           = &H100&
%MCI_SEEK_TO_END             = &H200&

' flags for dwFlags parameter of MCI_STATUS command message
%MCI_STATUS_ITEM             = &H100&
%MCI_STATUS_START            = &H200&

' flags for dwItem field of the MCI_STATUS_PARMS parameter block
%MCI_STATUS_LENGTH           = &H1&
%MCI_STATUS_POSITION         = &H2&
%MCI_STATUS_NUMBER_OF_TRACKS = &H3&
%MCI_STATUS_MODE             = &H4&
%MCI_STATUS_MEDIA_PRESENT    = &H5&
%MCI_STATUS_TIME_FORMAT      = &H6&
%MCI_STATUS_READY            = &H7&
%MCI_STATUS_CURRENT_TRACK    = &H8&

' flags for dwFlags parameter of MCI_INFO command message
%MCI_INFO_PRODUCT            = &H100&
%MCI_INFO_FILE               = &H200&

' flags for dwFlags parameter of MCI_GETDEVCAPS command message
%MCI_GETDEVCAPS_ITEM            = &H100&

' flags for dwItem field of the MCI_GETDEVCAPS_PARMS parameter block
%MCI_GETDEVCAPS_CAN_RECORD      = &H1&
%MCI_GETDEVCAPS_HAS_AUDIO       = &H2&
%MCI_GETDEVCAPS_HAS_VIDEO       = &H3&
%MCI_GETDEVCAPS_DEVICE_TYPE     = &H4&
%MCI_GETDEVCAPS_USES_FILES      = &H5&
%MCI_GETDEVCAPS_COMPOUND_DEVICE = &H6&
%MCI_GETDEVCAPS_CAN_EJECT       = &H7&
%MCI_GETDEVCAPS_CAN_PLAY        = &H8&
%MCI_GETDEVCAPS_CAN_SAVE        = &H9&

' flags for dwFlags parameter of MCI_SYSINFO command message
%MCI_SYSINFO_QUANTITY           = &H100&
%MCI_SYSINFO_OPEN               = &H200&
%MCI_SYSINFO_NAME               = &H400&
%MCI_SYSINFO_INSTALLNAME        = &H800&

' flags for dwFlags parameter of MCI_SET command message
%MCI_SET_DOOR_OPEN              = &H100&
%MCI_SET_DOOR_CLOSED            = &H200&
%MCI_SET_TIME_FORMAT            = &H400&
%MCI_SET_AUDIO                  = &H800&
%MCI_SET_VIDEO                  = &H1000&
%MCI_SET_ON                     = &H2000&
%MCI_SET_OFF                    = &H4000&

' flags for dwAudio field of MCI_SET_PARMS or MCI_SEQ_SET_PARMS
%MCI_SET_AUDIO_ALL              = &H0000
%MCI_SET_AUDIO_LEFT             = &H0001
%MCI_SET_AUDIO_RIGHT            = &H0002

' flags for dwFlags parameter of MCI_BREAK command message
%MCI_BREAK_KEY                  = &H100&
%MCI_BREAK_HWND                 = &H200&
%MCI_BREAK_OFF                  = &H400&

' flags for dwFlags parameter of MCI_RECORD command message
%MCI_RECORD_INSERT              = &H100&
%MCI_RECORD_OVERWRITE           = &H200&

' flags for dwFlags parameter of MCI_SOUND command message
%MCI_SOUND_NAME                 = &H100&

' flags for dwFlags parameter of MCI_SAVE command message
%MCI_SAVE_FILE                  = &H100&

' flags for dwFlags parameter of MCI_LOAD command message
%MCI_LOAD_FILE                  = &H100&

%MCI_VD_MODE_PARK               = %MCI_VD_OFFSET + 1

' return ID's for videodisc MCI_GETDEVCAPS command

' flag for dwReturn field of MCI_STATUS_PARMS
' MCI_STATUS command, (dwItem == MCI_VD_STATUS_MEDIA_TYPE)
%MCI_VD_MEDIA_CLV               = %MCI_VD_OFFSET + 2
%MCI_VD_MEDIA_CAV               = %MCI_VD_OFFSET + 3
%MCI_VD_MEDIA_OTHER             = %MCI_VD_OFFSET + 4

%MCI_VD_FORMAT_TRACK            = &H4001

' flags for dwFlags parameter of MCI_PLAY command message
%MCI_VD_PLAY_REVERSE            = &H10000
%MCI_VD_PLAY_FAST               = &H20000
%MCI_VD_PLAY_SPEED              = &H40000
%MCI_VD_PLAY_SCAN               = &H80000
%MCI_VD_PLAY_SLOW               = &H100000

' flag for dwFlags parameter of MCI_SEEK command message
%MCI_VD_SEEK_REVERSE            = &H10000

' flags for dwItem field of MCI_STATUS_PARMS parameter block
%MCI_VD_STATUS_SPEED            = &H4002&
%MCI_VD_STATUS_FORWARD          = &H4003&
%MCI_VD_STATUS_MEDIA_TYPE       = &H4004&
%MCI_VD_STATUS_SIDE             = &H4005&
%MCI_VD_STATUS_DISC_SIZE        = &H4006&

' flags for dwFlags parameter of MCI_GETDEVCAPS command message
%MCI_VD_GETDEVCAPS_CLV          = &H10000
%MCI_VD_GETDEVCAPS_CAV          = &H20000

%MCI_VD_SPIN_UP                 = &H10000
%MCI_VD_SPIN_DOWN               = &H20000

' flags for dwItem field of MCI_GETDEVCAPS_PARMS parameter block
%MCI_VD_GETDEVCAPS_CAN_REVERSE  = &H4002&
%MCI_VD_GETDEVCAPS_FAST_RATE    = &H4003&
%MCI_VD_GETDEVCAPS_SLOW_RATE    = &H4004&
%MCI_VD_GETDEVCAPS_NORMAL_RATE  = &H4005&

' flags for the dwFlags parameter of MCI_STEP command message
%MCI_VD_STEP_FRAMES             = &H10000
%MCI_VD_STEP_REVERSE            = &H20000

' flag for the MCI_ESCAPE command message
%MCI_VD_ESCAPE_STRING           = &H100&

%MCI_WAVE_PCM                   = %MCI_WAVE_OFFSET + 0
%MCI_WAVE_MAPPER                = %MCI_WAVE_OFFSET + 1

' flags for the dwFlags parameter of MCI_OPEN command message
%MCI_WAVE_OPEN_BUFFER           = &H10000

' flags for the dwFlags parameter of MCI_SET command message
%MCI_WAVE_SET_FORMATTAG         = &H10000
%MCI_WAVE_SET_CHANNELS          = &H20000
%MCI_WAVE_SET_SAMPLESPERSEC     = &H40000
%MCI_WAVE_SET_AVGBYTESPERSEC    = &H80000
%MCI_WAVE_SET_BLOCKALIGN        = &H100000
%MCI_WAVE_SET_BITSPERSAMPLE     = &H200000

' flags for the dwFlags parameter of MCI_STATUS, MCI_SET command messages
%MCI_WAVE_INPUT                 = &H400000
%MCI_WAVE_OUTPUT                = &H800000

' flags for the dwItem field of MCI_STATUS_PARMS parameter block
%MCI_WAVE_STATUS_FORMATTAG      = &H4001&
%MCI_WAVE_STATUS_CHANNELS       = &H4002&
%MCI_WAVE_STATUS_SAMPLESPERSEC  = &H4003&
%MCI_WAVE_STATUS_AVGBYTESPERSEC = &H4004&
%MCI_WAVE_STATUS_BLOCKALIGN     = &H4005&
%MCI_WAVE_STATUS_BITSPERSAMPLE  = &H4006&
%MCI_WAVE_STATUS_LEVEL          = &H4007&

' flags for the dwFlags parameter of MCI_SET command message
%MCI_WAVE_SET_ANYINPUT          = &H4000000
%MCI_WAVE_SET_ANYOUTPUT         = &H8000000

' flags for the dwFlags parameter of MCI_GETDEVCAPS command message
%MCI_WAVE_GETDEVCAPS_INPUTS     = &H4001&
%MCI_WAVE_GETDEVCAPS_OUTPUTS    = &H4002&

' flags for the dwReturn field of MCI_STATUS_PARMS parameter block
' MCI_STATUS command, (dwItem == MCI_SEQ_STATUS_DIVTYPE)
%MCI_SEQ_DIV_PPQN               = 0 + %MCI_SEQ_OFFSET
%MCI_SEQ_DIV_SMPTE_24           = 1 + %MCI_SEQ_OFFSET
%MCI_SEQ_DIV_SMPTE_25           = 2 + %MCI_SEQ_OFFSET
%MCI_SEQ_DIV_SMPTE_30DROP       = 3 + %MCI_SEQ_OFFSET
%MCI_SEQ_DIV_SMPTE_30           = 4 + %MCI_SEQ_OFFSET

' flags for the dwMaster field of MCI_SEQ_SET_PARMS parameter block
' MCI_SET command, (dwFlags == MCI_SEQ_SET_MASTER)
%MCI_SEQ_FORMAT_SONGPTR         = &H4001
%MCI_SEQ_FILE                   = &H4002
%MCI_SEQ_MIDI                   = &H4003
%MCI_SEQ_SMPTE                  = &H4004
%MCI_SEQ_NONE                   = 65533

%MCI_SEQ_MAPPER                 = 65535

' flags for the dwItem field of MCI_STATUS_PARMS parameter block
%MCI_SEQ_STATUS_TEMPO           = &H4002&
%MCI_SEQ_STATUS_PORT            = &H4003&
%MCI_SEQ_STATUS_SLAVE           = &H4007&
%MCI_SEQ_STATUS_MASTER          = &H4008&
%MCI_SEQ_STATUS_OFFSET          = &H4009&
%MCI_SEQ_STATUS_DIVTYPE         = &H400A&

' flags for the dwFlags parameter of MCI_SET command message
%MCI_SEQ_SET_TEMPO              = &H10000
%MCI_SEQ_SET_PORT               = &H20000
%MCI_SEQ_SET_SLAVE              = &H40000
%MCI_SEQ_SET_MASTER             = &H80000
%MCI_SEQ_SET_OFFSET             = &H1000000

' flags for dwFlags parameter of MCI_OPEN command message
%MCI_ANIM_OPEN_WS               = &H10000
%MCI_ANIM_OPEN_PARENT           = &H20000
%MCI_ANIM_OPEN_NOSTATIC         = &H40000

' flags for dwFlags parameter of MCI_PLAY command message
%MCI_ANIM_PLAY_SPEED            = &H10000
%MCI_ANIM_PLAY_REVERSE          = &H20000
%MCI_ANIM_PLAY_FAST             = &H40000
%MCI_ANIM_PLAY_SLOW             = &H80000
%MCI_ANIM_PLAY_SCAN             = &H100000

' flags for dwFlags parameter of MCI_STEP command message
%MCI_ANIM_STEP_REVERSE          = &H10000
%MCI_ANIM_STEP_FRAMES           = &H20000

' flags for dwItem field of MCI_STATUS_PARMS parameter block
%MCI_ANIM_STATUS_SPEED          = &H4001&
%MCI_ANIM_STATUS_FORWARD        = &H4002&
%MCI_ANIM_STATUS_HWND           = &H4003&
%MCI_ANIM_STATUS_HPAL           = &H4004&
%MCI_ANIM_STATUS_STRETCH        = &H4005&

' flags for the dwFlags parameter of MCI_INFO command message
%MCI_ANIM_INFO_TEXT              = &H10000

' flags for dwItem field of MCI_GETDEVCAPS_PARMS parameter block
%MCI_ANIM_GETDEVCAPS_CAN_REVERSE = &H4001&
%MCI_ANIM_GETDEVCAPS_FAST_RATE   = &H4002&
%MCI_ANIM_GETDEVCAPS_SLOW_RATE   = &H4003&
%MCI_ANIM_GETDEVCAPS_NORMAL_RATE = &H4004&
%MCI_ANIM_GETDEVCAPS_PALETTES    = &H4006&
%MCI_ANIM_GETDEVCAPS_CAN_STRETCH = &H4007&
%MCI_ANIM_GETDEVCAPS_MAX_WINDOWS = &H4008&

' flags for the MCI_REALIZE command message
%MCI_ANIM_REALIZE_NORM           = &H10000
%MCI_ANIM_REALIZE_BKGD           = &H20000

' flags for dwFlags parameter of MCI_WINDOW command message
%MCI_ANIM_WINDOW_HWND            = &H10000
%MCI_ANIM_WINDOW_STATE           = &H40000
%MCI_ANIM_WINDOW_TEXT            = &H80000
%MCI_ANIM_WINDOW_ENABLE_STRETCH  = &H100000
%MCI_ANIM_WINDOW_DISABLE_STRETCH = &H200000

' flags for hWnd field of MCI_ANIM_WINDOW_PARMS parameter block
' MCI_WINDOW command message, (dwFlags == MCI_ANIM_WINDOW_HWND)
%MCI_ANIM_WINDOW_DEFAULT         = &H0&

' flags for dwFlags parameter of MCI_PUT command message
%MCI_ANIM_RECT                   = &H10000
%MCI_ANIM_PUT_SOURCE             = &H20000      ' also  MCI_WHERE
%MCI_ANIM_PUT_DESTINATION        = &H40000      ' also  MCI_WHERE

' flags for dwFlags parameter of MCI_WHERE command message
%MCI_ANIM_WHERE_SOURCE           = &H20000
%MCI_ANIM_WHERE_DESTINATION      = &H40000

' flags for dwFlags parameter of MCI_UPDATE command message
%MCI_ANIM_UPDATE_HDC             = &H20000

' flags for dwFlags parameter of MCI_OPEN command message
%MCI_OVLY_OPEN_WS                = &H10000
%MCI_OVLY_OPEN_PARENT            = &H20000

' flags for dwFlags parameter of MCI_STATUS command message
%MCI_OVLY_STATUS_HWND            = &H4001&
%MCI_OVLY_STATUS_STRETCH         = &H4002&

' flags for dwFlags parameter of MCI_INFO command message
%MCI_OVLY_INFO_TEXT              = &H10000

' flags for dwItem field of MCI_GETDEVCAPS_PARMS parameter block
%MCI_OVLY_GETDEVCAPS_CAN_STRETCH = &H4001&
%MCI_OVLY_GETDEVCAPS_CAN_FREEZE  = &H4002&
%MCI_OVLY_GETDEVCAPS_MAX_WINDOWS = &H4003&

' flags for dwFlags parameter of MCI_WINDOW command message
%MCI_OVLY_WINDOW_HWND            = &H10000
%MCI_OVLY_WINDOW_STATE           = &H40000
%MCI_OVLY_WINDOW_TEXT            = &H80000
%MCI_OVLY_WINDOW_ENABLE_STRETCH  = &H100000
%MCI_OVLY_WINDOW_DISABLE_STRETCH = &H200000

' flags for hWnd parameter of MCI_OVLY_WINDOW_PARMS parameter block
%MCI_OVLY_WINDOW_DEFAULT         = &H0&

' flags for dwFlags parameter of MCI_PUT command message
%MCI_OVLY_RECT                   = &H10000
%MCI_OVLY_PUT_SOURCE             = &H20000
%MCI_OVLY_PUT_DESTINATION        = &H40000
%MCI_OVLY_PUT_FRAME              = &H80000
%MCI_OVLY_PUT_VIDEO              = &H100000

' flags for dwFlags parameter of MCI_WHERE command message
%MCI_OVLY_WHERE_SOURCE           = &H20000
%MCI_OVLY_WHERE_DESTINATION      = &H40000
%MCI_OVLY_WHERE_FRAME            = &H80000
%MCI_OVLY_WHERE_VIDEO            = &H100000

%CAPS1                           = 94  ' other caps
%C1_TRANSPARENT                  = &H1 ' new raster cap
%NEWTRANSPARENT                  = 3   ' use with SetBkMode()

%QUERYROPSUPPORT                 = 40  ' use to determine ROP support

%SELECTDIB                       = 41  ' DIB.DRV select dib escape

' ----------------
' shell association database management functions
' -----------------

' error values for ShellExecute() beyond the regular WinExec() codes
%SE_ERR_SHARE                    = 26
%SE_ERR_ASSOCINCOMPLETE          = 27
%SE_ERR_DDETIMEOUT               = 28
%SE_ERR_DDEFAIL                  = 29
%SE_ERR_DDEBUSY                  = 30
%SE_ERR_NOASSOC                  = 31

%PRINTER_CONTROL_PAUSE           = 1
%PRINTER_CONTROL_RESUME          = 2
%PRINTER_CONTROL_PURGE           = 3

%PRINTER_STATUS_PAUSED           = &H1
%PRINTER_STATUS_ERROR            = &H2
%PRINTER_STATUS_PENDING_DELETION = &H4
%PRINTER_STATUS_PAPER_JAM        = &H8
%PRINTER_STATUS_PAPER_OUT        = &H10
%PRINTER_STATUS_MANUAL_FEED      = &H20
%PRINTER_STATUS_PAPER_PROBLEM    = &H40
%PRINTER_STATUS_OFFLINE          = &H80
%PRINTER_STATUS_IO_ACTIVE        = &H100
%PRINTER_STATUS_BUSY             = &H200
%PRINTER_STATUS_PRINTING         = &H400
%PRINTER_STATUS_OUTPUT_BIN_FULL  = &H800
%PRINTER_STATUS_NOT_AVAILABLE    = &H00001000
%PRINTER_STATUS_WAITING          = &H00002000
%PRINTER_STATUS_PROCESSING       = &H00004000
%PRINTER_STATUS_INITIALIZING     = &H00008000
%PRINTER_STATUS_WARMING_UP       = &H10000
%PRINTER_STATUS_TONER_LOW        = &H20000
%PRINTER_STATUS_NO_TONER         = &H40000
%PRINTER_STATUS_PAGE_PUNT        = &H80000
%PRINTER_STATUS_USER_INTERVENTION= &H100000
%PRINTER_STATUS_OUT_OF_MEMORY    = &H200000
%PRINTER_STATUS_DOOR_OPEN        = &H400000

%PRINTER_ATTRIBUTE_QUEUED        = &H1
%PRINTER_ATTRIBUTE_DIRECT        = &H2
%PRINTER_ATTRIBUTE_DEFAULT       = &H4
%PRINTER_ATTRIBUTE_SHARED        = &H8
%PRINTER_ATTRIBUTE_NETWORK       = &H10
%PRINTER_ATTRIBUTE_HIDDEN        = &H20
%PRINTER_ATTRIBUTE_LOCAL         = &H40

%NO_PRIORITY                     = 0
%MAX_PRIORITY                    = 99
%MIN_PRIORITY                    = 1
%DEF_PRIORITY                    = 1

%JOB_CONTROL_PAUSE               = 1
%JOB_CONTROL_RESUME              = 2
%JOB_CONTROL_CANCEL              = 3
%JOB_CONTROL_RESTART             = 4

%JOB_STATUS_PAUSED               = &H1
%JOB_STATUS_ERROR                = &H2
%JOB_STATUS_DELETING             = &H4
%JOB_STATUS_SPOOLING             = &H8
%JOB_STATUS_PRINTING             = &H10
%JOB_STATUS_OFFLINE              = &H20
%JOB_STATUS_PAPEROUT             = &H40
%JOB_STATUS_PRINTED              = &H80

%JOB_POSITION_UNSPECIFIED        = 0

%FORM_BUILTIN                    = &H1

%PRINTER_CONTROL_SET_STATUS      = 4
%PRINTER_ATTRIBUTE_WORK_OFFLINE  = &H400
%PRINTER_ATTRIBUTE_ENABLE_BIDI   = &H800
%JOB_CONTROL_DELETE              = 5
%JOB_STATUS_USER_INTERVENTION    = &H00000400

%DI_CHANNEL                      = 1  ' start direct read/write channel,
%DI_READ_SPOOL_JOB               = 3

%DI_MASK                         = &H0001
%DI_IMAGE                        = &H0002
%DI_NORMAL                       = &H0003
%DI_COMPAT                       = &H0004
%DI_DEFAULTSIZE                  = &H0008
%DI_NOMIRROR       = &H0010

%PORT_TYPE_WRITE                 = &H1
%PORT_TYPE_READ                  = &H2
%PORT_TYPE_REDIRECTED            = &H4
%PORT_TYPE_NET_ATTACHED          = &H8

%PRINTER_ENUM_DEFAULT            = &H1
%PRINTER_ENUM_LOCAL              = &H2
%PRINTER_ENUM_CONNECTIONS        = &H4
%PRINTER_ENUM_FAVORITE           = &H4
%PRINTER_ENUM_NAME               = &H8
%PRINTER_ENUM_REMOTE             = &H10
%PRINTER_ENUM_SHARED             = &H20
%PRINTER_ENUM_NETWORK            = &H40

%PRINTER_ENUM_EXPAND             = &H00004000
%PRINTER_ENUM_CONTAINER          = &H00008000

%PRINTER_ENUM_ICONMASK           = &H00FF0000
%PRINTER_ENUM_ICON1              = &H00010000
%PRINTER_ENUM_ICON2              = &H00020000
%PRINTER_ENUM_ICON3              = &H00040000
%PRINTER_ENUM_ICON4              = &H00080000
%PRINTER_ENUM_ICON5              = &H00100000
%PRINTER_ENUM_ICON6              = &H00200000
%PRINTER_ENUM_ICON7              = &H00400000
%PRINTER_ENUM_ICON8              = &H00800000

%PRINTER_CHANGE_ADD_PRINTER            = &H00000001
%PRINTER_CHANGE_SET_PRINTER            = &H00000002
%PRINTER_CHANGE_DELETE_PRINTER         = &H00000004
%PRINTER_CHANGE_PRINTER                = &H000000FF
%PRINTER_CHANGE_ADD_JOB                = &H00000100
%PRINTER_CHANGE_SET_JOB                = &H00000200
%PRINTER_CHANGE_DELETE_JOB             = &H00000400
%PRINTER_CHANGE_WRITE_JOB              = &H00000800
%PRINTER_CHANGE_JOB                    = &H0000FF00
%PRINTER_CHANGE_ADD_FORM               = &H00010000
%PRINTER_CHANGE_SET_FORM               = &H00020000
%PRINTER_CHANGE_DELETE_FORM            = &H00040000
%PRINTER_CHANGE_FORM                   = &H00070000
%PRINTER_CHANGE_ADD_PORT               = &H00100000
%PRINTER_CHANGE_CONFIGURE_PORT         = &H00200000
%PRINTER_CHANGE_DELETE_PORT            = &H00400000
%PRINTER_CHANGE_PORT                   = &H00700000
%PRINTER_CHANGE_ADD_PRINT_PROCESSOR    = &H01000000
%PRINTER_CHANGE_DELETE_PRINT_PROCESSOR = &H04000000
%PRINTER_CHANGE_PRINT_PROCESSOR        = &H07000000
%PRINTER_CHANGE_ADD_PRINTER_DRIVER     = &H10000000
%PRINTER_CHANGE_DELETE_PRINTER_DRIVER  = &H40000000
%PRINTER_CHANGE_PRINTER_DRIVER         = &H70000000
%PRINTER_CHANGE_TIMEOUT                = &H80000000???
%PRINTER_CHANGE_ALL                    = &H7777FFFF

%PRINTER_ERROR_INFORMATION       = &H80000000???
%PRINTER_ERROR_WARNING           = &H40000000
%PRINTER_ERROR_SEVERE            = &H20000000

%PRINTER_ERROR_OUTOFPAPER        = &H1
%PRINTER_ERROR_JAM               = &H2
%PRINTER_ERROR_OUTOFTONER        = &H4

%SERVER_ACCESS_ADMINISTER        = &H1
%SERVER_ACCESS_ENUMERATE         = &H2

%PRINTER_ACCESS_ADMINISTER       = &H4
%PRINTER_ACCESS_USE              = &H8

%JOB_ACCESS_ADMINISTER           = &H10

' Windows Network support

' RESOURCE ENUMERATION

%RESOURCE_CONNECTED              = &H1
%RESOURCE_PUBLICNET              = &H2
%RESOURCE_GLOBALNET              = &H2
%RESOURCE_REMEMBERED             = &H3
%RESOURCE_RECENT                 = &H4
%RESOURCE_CONTEXT                = &H5

%RESOURCETYPE_ANY                = &H0
%RESOURCETYPE_DISK               = &H1
%RESOURCETYPE_PRINT              = &H2
%RESOURCETYPE_UNKNOWN            = &HFFFFFFFF???

%RESOURCEUSAGE_CONNECTABLE       = &H1
%RESOURCEUSAGE_CONTAINER         = &H2
%RESOURCEUSAGE_RESERVED          = &H80000000???

%RESOURCEDISPLAYTYPE_GENERIC     = &H0
%RESOURCEDISPLAYTYPE_DOMAIN      = &H1
%RESOURCEDISPLAYTYPE_SERVER      = &H2
%RESOURCEDISPLAYTYPE_SHARE       = &H3
%RESOURCEDISPLAYTYPE_FILE        = &H4
%RESOURCEDISPLAYTYPE_GROUP       = &H5

%CONNECT_UPDATE_PROFILE          = &H1

%WN_SUCCESS              = %NO_ERROR
%WN_NOT_SUPPORTED        = %ERROR_NOT_SUPPORTED
%WN_NET_ERROR            = %ERROR_UNEXP_NET_ERR
%WN_MORE_DATA            = %ERROR_MORE_DATA
%WN_BAD_POINTER          = %ERROR_INVALID_ADDRESS
%WN_BAD_VALUE            = %ERROR_INVALID_PARAMETER
%WN_BAD_PASSWORD         = %ERROR_INVALID_PASSWORD
%WN_ACCESS_DENIED        = %ERROR_ACCESS_DENIED
%WN_FUNCTION_BUSY        = %ERROR_BUSY
%WN_WINDOWS_ERROR        = %ERROR_UNEXP_NET_ERR
%WN_BAD_USER             = %ERROR_BAD_USERNAME
%WN_OUT_OF_MEMORY        = %ERROR_NOT_ENOUGH_MEMORY
%WN_NO_NETWORK           = %ERROR_NO_NETWORK
%WN_EXTENDED_ERROR       = %ERROR_EXTENDED_ERROR

' Connection

%WN_NOT_CONNECTED        = %ERROR_NOT_CONNECTED
%WN_OPEN_FILES           = %ERROR_OPEN_FILES
%WN_DEVICE_IN_USE        = %ERROR_DEVICE_IN_USE
%WN_BAD_NETNAME          = %ERROR_BAD_NET_NAME
%WN_BAD_LOCALNAME        = %ERROR_BAD_DEVICE
%WN_ALREADY_CONNECTED    = %ERROR_ALREADY_ASSIGNED
%WN_DEVICE_ERROR         = %ERROR_GEN_FAILURE
%WN_CONNECTION_CLOSED    = %ERROR_CONNECTION_UNAVAIL
%WN_NO_NET_OR_BAD_PATH   = %ERROR_NO_NET_OR_BAD_PATH
%WN_BAD_PROVIDER         = %ERROR_BAD_PROVIDER
%WN_CANNOT_OPEN_PROFILE  = %ERROR_CANNOT_OPEN_PROFILE
%WN_BAD_PROFILE          = %ERROR_BAD_PROFILE

' Enumeration

%WN_BAD_HANDLE           = %ERROR_INVALID_HANDLE
%WN_NO_MORE_ENTRIES      = %ERROR_NO_MORE_ITEMS
%WN_NOT_CONTAINER        = %ERROR_NOT_CONTAINER

%WN_NO_ERROR             = %NO_ERROR

' This section contains the definitions
' for portable NetBIOS 3.0 support.

%NCBNAMSZ                = 16  ' absolute length of a net name
%MAX_LANA                = 254  ' lana's in range 0 to MAX_LANA

%NAME_FLAGS_MASK         = &H87

%GROUP_NAME              = &H80
%UNIQUE_NAME             = &H0

%REGISTERING             = &H0
%REGISTERED              = &H4
%DEREGISTERED            = &H5
%DUPLICATE               = &H6
%DUPLICATE_DEREG         = &H7

' Values for state
%LISTEN_OUTSTANDING      = &H1
%CALL_PENDING            = &H2
%SESSION_ESTABLISHED     = &H3
%HANGUP_PENDING          = &H4
%HANGUP_COMPLETE         = &H5
%SESSION_ABORTED         = &H6

' NCB Command codes
%NCBCALL                 = &H10  ' NCB CALL
%NCBLISTEN               = &H11  ' NCB LISTEN
%NCBHANGUP               = &H12  ' NCB HANG UP
%NCBSEND                 = &H14  ' NCB SEND
%NCBRECV                 = &H15  ' NCB RECEIVE
%NCBRECVANY              = &H16  ' NCB RECEIVE ANY
%NCBCHAINSEND            = &H17  ' NCB CHAIN SEND
%NCBDGSEND               = &H20  ' NCB SEND DATAGRAM
%NCBDGRECV               = &H21  ' NCB RECEIVE DATAGRAM
%NCBDGSENDBC             = &H22  ' NCB SEND BROADCAST DATAGRAM
%NCBDGRECVBC             = &H23  ' NCB RECEIVE BROADCAST DATAGRAM
%NCBADDNAME              = &H30  ' NCB ADD NAME
%NCBDELNAME              = &H31  ' NCB DELETE NAME
%NCBRESET                = &H32  ' NCB RESET
%NCBASTAT                = &H33  ' NCB ADAPTER STATUS
%NCBSSTAT                = &H34  ' NCB SESSION STATUS
%NCBCANCEL               = &H35  ' NCB CANCEL
%NCBADDGRNAME            = &H36  ' NCB ADD GROUP NAME
%NCBENUM                 = &H37  ' NCB ENUMERATE LANA NUMBERS
%NCBUNLINK               = &H70  ' NCB UNLINK
%NCBSENDNA               = &H71  ' NCB SEND NO ACK
%NCBCHAINSENDNA          = &H72  ' NCB CHAIN SEND NO ACK
%NCBLANSTALERT           = &H73  ' NCB LAN STATUS ALERT
%NCBACTION               = &H77  ' NCB ACTION
%NCBFINDNAME             = &H78  ' NCB FIND NAME
%NCBTRACE                = &H79  ' NCB TRACE

%ASYNCH                  = &H80  ' high bit set == asynchronous

' NCB Return codes
%NRC_GOODRET             = &H0   ' good return
' also returned when ASYNCH request accepted
%NRC_BUFLEN              = &H1   ' illegal buffer length
%NRC_ILLCMD              = &H3   ' illegal command
%NRC_CMDTMO              = &H5   ' command timed out
%NRC_INCOMP              = &H6   ' message incomplete, issue another command
%NRC_BADDR               = &H7   ' illegal buffer address
%NRC_SNUMOUT             = &H8   ' session number out of range
%NRC_NORES               = &H9   ' no resource available
%NRC_SCLOSED             = &HA   ' session closed
%NRC_CMDCAN              = &HB   ' command cancelled
%NRC_DUPNAME             = &HD   ' duplicate name
%NRC_NAMTFUL             = &HE   ' name table full
%NRC_ACTSES              = &HF   ' no deletions, name has active sessions
%NRC_LOCTFUL             = &H11  ' local session table full
%NRC_REMTFUL             = &H12  ' remote session table full
%NRC_ILLNN               = &H13  ' illegal name number
%NRC_NOCALL              = &H14  ' no callname
%NRC_NOWILD              = &H15  ' cannot put  in NCB_NAME
%NRC_INUSE               = &H16  ' name in use on remote adapter
%NRC_NAMERR              = &H17  ' name deleted
%NRC_SABORT              = &H18  ' session ended abnormally
%NRC_NAMCONF             = &H19  ' name conflict detected
%NRC_IFBUSY              = &H21  ' interface busy, IRET before retrying
%NRC_TOOMANY             = &H22  ' too many commands outstanding, retry later
%NRC_BRIDGE              = &H23  ' ncb_lana_num field invalid
%NRC_CANOCCR             = &H24  ' command completed while cancel occurring
%NRC_CANCEL              = &H26  ' command not valid to cancel
%NRC_DUPENV              = &H30  ' name defined by anther local process
%NRC_ENVNOTDEF           = &H34  ' environment undefined. RESET required
%NRC_OSRESNOTAV          = &H35  ' required OS resources exhausted
%NRC_MAXAPPS             = &H36  ' max number of applications exceeded
%NRC_NOSAPS              = &H37  ' no saps available for netbios
%NRC_NORESOURCES         = &H38  ' requested resources are not available
%NRC_INVADDRESS          = &H39  ' invalid ncb address or length > segment
%NRC_INVDDID             = &H3B  ' invalid NCB DDID
%NRC_LOCKFAIL            = &H3C  ' lock of user area failed
%NRC_OPENERR             = &H3F  ' NETBIOS not loaded
%NRC_SYSTEM              = &H40  ' system error

%NRC_PENDING             = &HFF  ' asynchronous command is not yet finished

' Legal values for expression in except().
%EXCEPTION_EXECUTE_HANDLER       = 1
%EXCEPTION_CONTINUE_SEARCH       = 0
%EXCEPTION_CONTINUE_EXECUTION    = -1

' UI dialog constants and types

' ----Constants--------------------------------------------------------------
%ctlFirst          = &H400
%ctlLast           = &H4FF
' Push buttons
%psh1              = &H400
%psh2              = &H401
%psh3              = &H402
%psh4              = &H403
%psh5              = &H404
%psh6              = &H405
%psh7              = &H406
%psh8              = &H407
%psh9              = &H408
%psh10             = &H409
%psh11             = &H40A
%psh12             = &H40B
%psh13             = &H40C
%psh14             = &H40D
%psh15             = &H40E
%pshHelp           = %psh15
%psh16             = &H40F
' Checkboxes
%chx1              = &H410
%chx2              = &H411
%chx3              = &H412
%chx4              = &H413
%chx5              = &H414
%chx6              = &H415
%chx7              = &H416
%chx8              = &H417
%chx9              = &H418
%chx10             = &H419
%chx11             = &H41A
%chx12             = &H41B
%chx13             = &H41C
%chx14             = &H41D
%chx15             = &H41E
%chx16             = &H41F
' Radio buttons
%rad1              = &H420
%rad2              = &H421
%rad3              = &H422
%rad4              = &H423
%rad5              = &H424
%rad6              = &H425
%rad7              = &H426
%rad8              = &H427
%rad9              = &H428
%rad10             = &H429
%rad11             = &H42A
%rad12             = &H42B
%rad13             = &H42C
%rad14             = &H42D
%rad15             = &H42E
%rad16             = &H42F
' Groups, frames, rectangles, and icons
%grp1              = &H430
%grp2              = &H431
%grp3              = &H432
%grp4              = &H433
%frm1              = &H434
%frm2              = &H435
%frm3              = &H436
%frm4              = &H437
%rct1              = &H438
%rct2              = &H439
%rct3              = &H43A
%rct4              = &H43B
%ico1              = &H43C
%ico2              = &H43D
%ico3              = &H43E
%ico4              = &H43F
' Static text
%stc1              = &H440
%stc2              = &H441
%stc3              = &H442
%stc4              = &H443
%stc5              = &H444
%stc6              = &H445
%stc7              = &H446
%stc8              = &H447
%stc9              = &H448
%stc10             = &H449
%stc11             = &H44A
%stc12             = &H44B
%stc13             = &H44C
%stc14             = &H44D
%stc15             = &H44E
%stc16             = &H44F
%stc17             = &H450
%stc18             = &H451
%stc19             = &H452
%stc20             = &H453
%stc21             = &H454
%stc22             = &H455
%stc23             = &H456
%stc24             = &H457
%stc25             = &H458
%stc26             = &H459
%stc27             = &H45A
%stc28             = &H45B
%stc29             = &H45C
%stc30             = &H45D
%stc31             = &H45E
%stc32             = &H45F
' Listboxes
%lst1              = &H460
%lst2              = &H461
%lst3              = &H462
%lst4              = &H463
%lst5              = &H464
%lst6              = &H465
%lst7              = &H466
%lst8              = &H467
%lst9              = &H468
%lst10             = &H469
%lst11             = &H46A
%lst12             = &H46B
%lst13             = &H46C
%lst14             = &H46D
%lst15             = &H46E
%lst16             = &H46F
' Combo boxes
%cmb1              = &H470
%cmb2              = &H471
%cmb3              = &H472
%cmb4              = &H473
%cmb5              = &H474
%cmb6              = &H475
%cmb7              = &H476
%cmb8              = &H477
%cmb9              = &H478
%cmb10             = &H479
%cmb11             = &H47A
%cmb12             = &H47B
%cmb13             = &H47C
%cmb14             = &H47D
%cmb15             = &H47E
%cmb16             = &H47F
' Edit controls
%edt1              = &H480
%edt2              = &H481
%edt3              = &H482
%edt4              = &H483
%edt5              = &H484
%edt6              = &H485
%edt7              = &H486
%edt8              = &H487
%edt9              = &H488
%edt10             = &H489
%edt11             = &H48A
%edt12             = &H48B
%edt13             = &H48C
%edt14             = &H48D
%edt15             = &H48E
%edt16             = &H48F
' Scroll bars
%scr1              = &H490
%scr2              = &H491
%scr3              = &H492
%scr4              = &H493
%scr5              = &H494
%scr6              = &H495
%scr7              = &H496
%scr8              = &H497

%FILEOPENORD       = 1536
%MULTIFILEOPENORD  = 1537
%PRINTDLGORD       = 1538
%PRNSETUPDLGORD    = 1539
%FINDDLGORD        = 1540
%REPLACEDLGORD     = 1541
%FONTDLGORD        = 1542
%FORMATDLGORD31    = 1543
%FORMATDLGORD30    = 1544

%HKEY_CLASSES_ROOT      = &H80000000???
%HKEY_CURRENT_USER      = &H80000001???
%HKEY_LOCAL_MACHINE     = &H80000002???
%HKEY_USERS             = &H80000003???
%HKEY_PERFORMANCE_DATA  = &H80000004???
%HKEY_CURRENT_CONFIG    = &H80000005???
%HKEY_DYN_DATA          = &H80000006???
%HKEY_DYNAMIC_DATA      = %HKEY_DYN_DATA

%HKCR              = %HKEY_CLASSES_ROOT
%HKCU              = %HKEY_CURRENT_USER
%HKLM              = %HKEY_LOCAL_MACHINE
%HKU               = %HKEY_USERS
%HKPD              = %HKEY_PERFORMANCE_DATA
%HKCC              = %HKEY_CURRENT_CONFIG
%HKDD              = %HKEY_DYN_DATA

%PERF_DATA_VERSION      = 1
%PERF_DATA_REVISION     = 1

%PERF_NO_INSTANCES      = -1  ' no instances

' The counter type is the "or" of the following values as described below
'
' select one of the following to indicate the counter's data size
%PERF_SIZE_DWORD        = &H0
%PERF_SIZE_LARGE        = &H100
%PERF_SIZE_ZERO         = &H200       ' for Zero Length fields
%PERF_SIZE_VARIABLE_LEN = &H300       ' length is in CounterLength field of Counter Definition struct

' select one of the following values to indicate the counter field usage
%PERF_TYPE_NUMBER       = &H0         ' a number (not a counter)
%PERF_TYPE_COUNTER      = &H400       ' an increasing numeric value
%PERF_TYPE_TEXT         = &H800       ' a text field
%PERF_TYPE_ZERO         = &HC00       ' displays a zero

' If the PERF_TYPE_NUMBER field was selected, then select one of the
' following to describe the Number
%PERF_NUMBER_HEX        = &H0         ' display as HEX value
%PERF_NUMBER_DECIMAL    = &H10000     ' display as a decimal integer
%PERF_NUMBER_DEC_1000   = &H20000     ' display as a decimal/1000
'
' If the PERF_TYPE_COUNTER value was selected then select one of the
' following to indicate the type of counter
%PERF_COUNTER_VALUE     = &H0         ' display counter value
%PERF_COUNTER_RATE      = &H10000     ' divide ctr / delta time
%PERF_COUNTER_FRACTION  = &H20000     ' divide ctr / base
%PERF_COUNTER_BASE      = &H30000     ' base value used in fractions
%PERF_COUNTER_ELAPSED   = &H40000     ' subtract counter from current time
%PERF_COUNTER_QUEUELEN  = &H50000     ' Use Queuelen processing func.
%PERF_COUNTER_HISTOGRAM = &H60000     ' Counter begins or ends a histogram

' If the PERF_TYPE_TEXT value was selected, then select one of the
' following to indicate the type of TEXT data.
%PERF_TEXT_UNICODE      = &H0         ' type of text in text field
%PERF_TEXT_ASCII        = &H10000     ' ASCII using the CodePage field

' Timer SubTypes
%PERF_TIMER_TICK        = &H0         ' use system perf. freq for base
%PERF_TIMER_100NS       = &H100000    ' use 100 NS timer time base units
%PERF_OBJECT_TIMER      = &H200000    ' use the object timer freq

' Any types that have calculations performed can use one or more of
' the following calculation modification flags listed here
%PERF_DELTA_COUNTER     = &H400000    ' compute difference first
%PERF_DELTA_BASE        = &H800000    ' compute base diff as well
%PERF_INVERSE_COUNTER   = &H1000000   ' show as 1.00-value (assumes:
%PERF_MULTI_COUNTER     = &H2000000   ' sum of multiple instances

' Select one of the following values to indicate the display suffix (if any)
%PERF_DISPLAY_NO_SUFFIX = &H0         ' no suffix
%PERF_DISPLAY_PER_SEC   = &H10000000  ' "/sec"
%PERF_DISPLAY_PERCENT   = &H20000000  ' "%"
%PERF_DISPLAY_SECONDS   = &H30000000  ' "secs"
%PERF_DISPLAY_NOSHOW    = &H40000000  ' value is not displayed

' Predefined counter types

' 32-bit Counter.  Divide delta by delta time.  Display suffix: "/sec"
%PERF_COUNTER_COUNTER   = %PERF_SIZE_DWORD OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_RATE OR %PERF_TIMER_TICK OR %PERF_DELTA_COUNTER OR %PERF_DISPLAY_PER_SEC

' 64-bit Timer.  Divide delta by delta time.  Display suffix: "%"
%PERF_COUNTER_TIMER     = %PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_RATE OR %PERF_TIMER_TICK OR %PERF_DELTA_COUNTER OR %PERF_DISPLAY_PERCENT

' Queue Length Space-Time Product. Divide delta by delta time. No Display Suffix.
%PERF_COUNTER_QUEUELEN_TYPE = %PERF_SIZE_DWORD OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_QUEUELEN OR %PERF_TIMER_TICK OR %PERF_DELTA_COUNTER OR %PERF_DISPLAY_NO_SUFFIX

' 64-bit Counter.  Divide delta by delta time. Display Suffix: "/sec"
%PERF_COUNTER_BULK_COUNT = %PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_RATE OR %PERF_TIMER_TICK OR %PERF_DELTA_COUNTER OR %PERF_DISPLAY_PER_SEC

' Indicates the counter is not a  counter but rather Unicode text Display as text.
%PERF_COUNTER_TEXT      = %PERF_SIZE_VARIABLE_LEN OR %PERF_TYPE_TEXT OR %PERF_TEXT_UNICODE OR %PERF_DISPLAY_NO_SUFFIX

' Indicates the data is a counter  which should not be
' time averaged on display (such as an error counter on a serial line)
' Display as is.  No Display Suffix.
%PERF_COUNTER_RAWCOUNT  = %PERF_SIZE_DWORD OR %PERF_TYPE_NUMBER OR %PERF_NUMBER_DECIMAL OR %PERF_DISPLAY_NO_SUFFIX

' A count which is either 1 or 0 on each sampling interrupt (% busy)
' Divide delta by delta base. Display Suffix: "%"
%PERF_SAMPLE_FRACTION   = %PERF_SIZE_DWORD OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_FRACTION OR %PERF_DELTA_COUNTER OR %PERF_DELTA_BASE OR %PERF_DISPLAY_PERCENT

' A count which is sampled on each sampling interrupt (queue length)
' Divide delta by delta time. No Display Suffix.
%PERF_SAMPLE_COUNTER    = %PERF_SIZE_DWORD OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_RATE OR %PERF_TIMER_TICK OR %PERF_DELTA_COUNTER OR %PERF_DISPLAY_NO_SUFFIX

' A label: no data is associated with this counter (it has 0 length)
' Do not display.
%PERF_COUNTER_NODATA    = %PERF_SIZE_ZERO OR %PERF_DISPLAY_NOSHOW

' 64-bit Timer inverse (e.g., idle is measured, but display busy as Integer)
' Display 100 - delta divided by delta time.  Display suffix: "%"
%PERF_COUNTER_TIMER_INV = %PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_RATE OR %PERF_TIMER_TICK OR %PERF_DELTA_COUNTER OR %PERF_INVERSE_COUNTER OR %PERF_DISPLAY_PERCENT

' The divisor for a sample, used with the previous counter to form a
' sampled %.  You must check for >0 before dividing by this!  This
' counter will directly follow the  numerator counter.  It should not
' be displayed to the user.
%PERF_SAMPLE_BASE       = %PERF_SIZE_DWORD OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_BASE OR %PERF_DISPLAY_NOSHOW OR &H1         ' for compatibility with pre-beta versions

' A timer which, when divided by an average base, produces a time
' in seconds which is the average time of some operation.  This
' timer times total operations, and  the base is the number of opera-
' tions.  Display Suffix: "sec"
%PERF_AVERAGE_TIMER     = %PERF_SIZE_DWORD OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_FRACTION OR %PERF_DISPLAY_SECONDS

' Used as the denominator in the computation of time or count
' averages.  Must directly follow the numerator counter.  Not dis-
' played to the user.
%PERF_AVERAGE_BASE      = %PERF_SIZE_DWORD OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_BASE OR %PERF_DISPLAY_NOSHOW OR &H2         ' for compatibility with pre-beta versions

' A bulk count which, when divided (typically) by the number of
' operations, gives (typically) the number of bytes per operation.
' No Display Suffix.
%PERF_AVERAGE_BULK      = %PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_FRACTION OR %PERF_DISPLAY_NOSHOW

' 64-bit Timer in 100 nsec units. Display delta divided by
' delta time.  Display suffix: "%"
%PERF_100NSEC_TIMER     = %PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_RATE OR %PERF_TIMER_100NS OR %PERF_DELTA_COUNTER OR %PERF_DISPLAY_PERCENT

' 64-bit Timer inverse (e.g., idle is measured, but display busy  AS Integer)
' Display 100 - delta divided by delta time.  Display suffix: "%"
%PERF_100NSEC_TIMER_INV = %PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_RATE OR %PERF_TIMER_100NS OR %PERF_DELTA_COUNTER OR %PERF_INVERSE_COUNTER OR %PERF_DISPLAY_PERCENT

' 64-bit Timer.  Divide delta by delta time.  Display suffix: "%"
' Timer for multiple instances, so result can exceed 100%.
%PERF_COUNTER_MULTI_TIMER = %PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_RATE OR %PERF_DELTA_COUNTER OR %PERF_TIMER_TICK OR %PERF_MULTI_COUNTER OR %PERF_DISPLAY_PERCENT

' 64-bit Timer inverse (e.g., idle is measured, but display busy  AS Integer)
' Display 100  _MULTI_BASE - delta divided by delta time.
' Display suffix: "%" Timer for multiple instances, so result
' can exceed 100%.  Followed by a counter of type _MULTI_BASE.
%PERF_COUNTER_MULTI_TIMER_INV = %PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_RATE OR %PERF_DELTA_COUNTER OR %PERF_MULTI_COUNTER OR %PERF_TIMER_TICK OR %PERF_INVERSE_COUNTER OR %PERF_DISPLAY_PERCENT

' Number of instances to which the preceding _MULTI_..._INV counter
' applies.  Used as a factor to get the percentage.
%PERF_COUNTER_MULTI_BASE = %PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_BASE OR %PERF_MULTI_COUNTER OR %PERF_DISPLAY_NOSHOW

' 64-bit Timer in 100 nsec units. Display delta divided by delta time.
' Display suffix: "%" Timer for multiple instances, so result can exceed 100%.
%PERF_100NSEC_MULTI_TIMER = %PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_DELTA_COUNTER OR %PERF_COUNTER_RATE OR %PERF_TIMER_100NS OR %PERF_MULTI_COUNTER OR %PERF_DISPLAY_PERCENT

' 64-bit Timer inverse (e.g., idle is measured, but display busy  AS Integer)
' Display 100  _MULTI_BASE - delta divided by delta time.
' Display suffix: "%" Timer for multiple instances, so result
' can exceed 100%.  Followed by a counter of type _MULTI_BASE.
%PERF_100NSEC_MULTI_TIMER_INV = %PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_DELTA_COUNTER OR %PERF_COUNTER_RATE OR %PERF_TIMER_100NS OR %PERF_MULTI_COUNTER OR %PERF_INVERSE_COUNTER OR %PERF_DISPLAY_PERCENT

' Indicates the data is a fraction of the following counter  which
' should not be time averaged on display (such as free space over
' total space.) Display as is.  Display the quotient as "%".
%PERF_RAW_FRACTION = %PERF_SIZE_DWORD OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_FRACTION OR %PERF_DISPLAY_PERCENT

' Indicates the data is a base for the preceding counter which should
' not be time averaged on display (such as free space over total space.)
%PERF_RAW_BASE = %PERF_SIZE_DWORD OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_BASE OR %PERF_DISPLAY_NOSHOW OR &H3         ' for compatibility with pre-beta versions

' The data collected in this counter is actually the start time of the
' item being measured. For display, this data is subtracted from the
' sample time to yield the elapsed time as the difference between the two.
' In the definition below, the PerfTime field of the Object contains
' the sample time as indicated by the PERF_OBJECT_TIMER bit and the
' difference is scaled by the PerfFreq of the Object to convert the time
' units into seconds.
%PERF_ELAPSED_TIME = %PERF_SIZE_LARGE OR %PERF_TYPE_COUNTER OR %PERF_COUNTER_ELAPSED OR %PERF_OBJECT_TIMER OR %PERF_DISPLAY_SECONDS

' The following counter type can be used with the preceding types to
' define a range of values to be displayed in a histogram.
%PERF_COUNTER_HISTOGRAM_TYPE = &H80000000???  ' Counter begins or ends a histogram

' The following are used to determine the level of detail associated
' with the counter.  The user will be setting the level of detail
' that should be displayed at any given time.
%PERF_DETAIL_NOVICE          = 100 ' The uninformed can understand it
%PERF_DETAIL_ADVANCED        = 200 ' For the advanced user
%PERF_DETAIL_EXPERT          = 300 ' For the expert user
%PERF_DETAIL_WIZARD          = 400 ' For the system designer

%PERF_NO_UNIQUE_ID           = -1

' LZEXPAND error return codes
%LZERROR_BADINHANDLE         = -1  ' invalid input handle
%LZERROR_BADOUTHANDLE        = -2  ' invalid output handle
%LZERROR_READ                = -3  ' corrupt compressed file format
%LZERROR_WRITE               = -4  ' out of space for output file
%LZERROR_PUBLICLOC           = -5  ' insufficient memory for LZFile struct
%LZERROR_GLOBLOCK            = -6  ' bad Global handle
%LZERROR_BADVALUE            = -7  ' input parameter out of range
%LZERROR_UNKNOWNALG          = -8  ' compression algorithm not recognized

%STYLE_DESCRIPTION_SIZE      = 32

%WM_IME_STARTCOMPOSITION = &H10D
%WM_IME_ENDCOMPOSITION   = &H10E
%WM_IME_COMPOSITION      = &H10F
%WM_IME_KEYLAST          = &H10F

%WM_IME_SETCONTEXT       = &H281
%WM_IME_NOTIFY           = &H282
%WM_IME_CONTROL          = &H283
%WM_IME_COMPOSITIONFULL  = &H284
%WM_IME_SELECT           = &H285
%WM_IME_CHAR             = &H286
%WM_IME_REQUEST          = &H0288
%WM_IME_KEYDOWN          = &H290
%WM_IME_KEYUP            = &H291

%ABM_NEW              = &H0
%ABM_REMOVE           = &H1
%ABM_QUERYPOS         = &H2
%ABM_SETPOS           = &H3
%ABM_GETSTATE         = &H4
%ABM_GETTASKBARPOS    = &H5
%ABM_ACTIVATE         = &H6 ' lParam == TRUE/FALSE means activate/deactivate
%ABM_GETAUTOHIDEBAR   = &H7
%ABM_SETAUTOHIDEBAR   = &H8 ' this can fail at any time.  MUST check the result
' lParam = TRUE/FALSE  Set/Unset
' uEdge = what edge
%ABM_WINDOWPOSCHANGED = &H9


' these are put in the wparam of callback messages
%ABN_STATECHANGE   = &H0
%ABN_POSCHANGED    = &H1
%ABN_FULLSCREENAPP = &H2
%ABN_WINDOWARRANGE = &H3 ' lParam == TRUE means hide

' flags for get state

%ABS_AUTOHIDE     = &H1
%ABS_ALWAYSONTOP  = &H2
%ABE_LEFT         = 0
%ABE_TOP          = 1
%ABE_RIGHT        = 2
%ABE_BOTTOM       = 3

%EIRESID                        = -1

%FO_MOVE                        = &H1
%FO_COPY                        = &H2
%FO_DELETE                      = &H3
%FO_RENAME                      = &H4
%FOF_MULTIDESTFILES             = &H1
%FOF_CONFIRMMOUSE               = &H2
%FOF_SILENT                     = &H4    ' don't create progress/report
%FOF_RENAMEONCOLLISION          = &H8
%FOF_NOCONFIRMATION             = &H10   ' Don't prompt the user.
%FOF_WANTMAPPINGHANDLE          = &H20   ' Fill in SHFILEOPSTRUCT.hNameMappings
' Must be freed using SHFreeNameMappings
%FOF_ALLOWUNDO                  = &H40
%FOF_FILESONLY                  = &H80   ' on *.*, do only files
%FOF_SIMPLEPROGRESS             = &H100  ' means don't show names of files
%FOF_NOCONFIRMMKDIR             = &H200  ' don't confirm making any needed dirs
%FOF_NOERRORUI             = &H00400  ' don't put up error UI
%FOF_NOCOPYSECURITYATTRIBS = &H00800  ' don't copy NT file Security Attributes
%FOF_NORECURSION           = &H01000  ' don't recurse into directories.
%FOF_NO_CONNECTED_ELEMENTS = &H02000  ' don't operate on connected file elements.
%FOF_WANTNUKEWARNING       = &H04000  ' during delete operation, warn if nuking instead of recycling (partially overrides FOF_NOCONFIRMATION)
%FOF_NORECURSEREPARSE      = &H08000  ' treat reparse points as objects, not containers

%PO_DELETE                      = &H13   ' printer is being deleted
%PO_RENAME                      = &H14   ' printer is being renamed
%PO_PORTCHANGE                  = &H20   ' port this printer connected to is being changed
' if this id is set, the strings received by
' the copyhook are a doubly-null terminated
' list of strings.  The first is the printer
' name and the second is the printer port.
%PO_REN_PORT                    = &H34   ' PO_RENAME and PO_PORTCHANGE at same time.

' no POF_ flags currently defined
' regular WinExec() codes
%SE_ERR_FNF          = 2      ' file not found
%SE_ERR_PNF          = 3      ' path not found
%SE_ERR_ACCESSDENIED = 5      ' access denied
%SE_ERR_OOM          = 8      ' out of memory
%SE_ERR_DLLNOTFOUND  = 32

' Note CLASSKEY overrides CLASSNAME
%SEE_MASK_CLASSNAME      = &H00000001
%SEE_MASK_CLASSKEY       = &H00000003

' Note INVOKEIDLIST overrides IDLIST
%SEE_MASK_IDLIST            = &H00000004
%SEE_MASK_INVOKEIDLIST      = &H0000000C
%SEE_MASK_ICON              = &H00000010
%SEE_MASK_HOTKEY            = &H00000020
%SEE_MASK_NOCLOSEPROCESS    = &H00000040
%SEE_MASK_CONNECTNETDRV     = &H00000080
%SEE_MASK_FLAG_DDEWAIT      = &H00000100
%SEE_MASK_DOENVSUBST        = &H00000200
%SEE_MASK_FLAG_NO_UI        = &H00000400
%SEE_MASK_UNICODE           = &H00004000
%SEE_MASK_NO_CONSOLE        = &H00008000
%SEE_MASK_ASYNCOK           = &H00100000
%SEE_MASK_HMONITOR          = &H00200000
%SEE_MASK_NOQUERYCLASSSTORE = &H01000000
%SEE_MASK_WAITFORINPUTIDLE  = &H02000000
%SEE_MASK_FLAG_LOG_USAGE    = &H04000000
%SEE_MASK_NOZONECHECKS      = &H00800000

' flags for SHEmptyRecycleBin
%SHERB_NOCONFIRMATION = &H00000001
%SHERB_NOPROGRESSUI   = &H00000002
%SHERB_NOSOUND        = &H00000004

%NIN_SELECT           = %WM_USER
%NINF_KEY             = 1
%NIN_KEYSELECT        = %NIN_SELECT OR %NINF_KEY
%NIN_BALLOONSHOW      = %WM_USER + 2
%NIN_BALLOONHIDE      = %WM_USER + 3
%NIN_BALLOONTIMEOUT   = %WM_USER + 4
%NIN_BALLOONUSERCLICK = %WM_USER + 5

%NIM_ADD        = &H00000000
%NIM_MODIFY     = &H00000001
%NIM_DELETE     = &H00000002
%NIM_SETFOCUS   = &H00000003
%NIM_SETVERSION = &H00000004

%NIF_MESSAGE = &H00000001
%NIF_ICON    = &H00000002
%NIF_TIP     = &H00000004
%NIF_STATE   = &H00000008
%NIF_INFO    = &H00000010
%NIF_GUID    = &H00000020

%NIS_HIDDEN     = &H00000001
%NIS_SHAREDICON = &H00000002

' Notify Icon Infotip flags
%NIIF_NONE      = &H00000000
' icon flags are mutually exclusive
' and take only the lowest 2 bits
%NIIF_INFO      = &H00000001
%NIIF_WARNING   = &H00000002
%NIIF_ERROR     = &H00000003
%NIIF_ICON_MASK = &H0000000F
%NIIF_NOSOUND   = &H00000010

%SHGFI_ICON              = &H00000100  ' get icon
%SHGFI_DISPLAYNAME       = &H00000200  ' get display name
%SHGFI_TYPENAME          = &H00000400  ' get type name
%SHGFI_ATTRIBUTES        = &H00000800  ' get attributes
%SHGFI_ICONLOCATION      = &H00001000  ' get icon location
%SHGFI_EXETYPE           = &H00002000  ' return exe type
%SHGFI_SYSICONINDEX      = &H00004000  ' get system icon index
%SHGFI_LINKOVERLAY       = &H00008000  ' put a link overlay on icon
%SHGFI_SELECTED          = &H00010000  ' show icon in selected state
%SHGFI_ATTR_SPECIFIED    = &H00020000  ' get only specified attributes

%SHGFI_LARGEICON         = &H00000000  ' get large icon
%SHGFI_SMALLICON         = &H00000001  ' get small icon
%SHGFI_OPENICON          = &H00000002  ' get open icon
%SHGFI_SHELLICONSIZE     = &H00000004  ' get shell size icon
%SHGFI_PIDL              = &H00000008  ' pszPath is a pidl
%SHGFI_USEFILEATTRIBUTES = &H00000010  ' use passed dwFileAttribute

%SHGFI_ADDOVERLAYS       = &H00000020  ' apply the appropriate overlays
%SHGFI_OVERLAYINDEX      = &H00000040  ' Get the index of the overlay
                                       ' in the upper 8 bits of the iIcon

%SHGNLI_PIDL             = &H00000001  ' pszLinkTo is a pidl
%SHGNLI_PREFIXNAME       = &H00000002  ' Make name "Shortcut to xxx"
%SHGNLI_NOUNIQUE         = &H00000004  ' don't do the unique name generation
%SHGNLI_NOLNK            = &H00000008  ' don't add ".lnk" extension

' Printer stuff
'
%PRINTACTION_OPEN             = 0
%PRINTACTION_PROPERTIES       = 1
%PRINTACTION_NETINSTALL       = 2
%PRINTACTION_NETINSTALLLINK   = 3
%PRINTACTION_TESTPAGE         = 4
%PRINTACTION_OPENNETPRN       = 5
%PRINTACTION_DOCUMENTDEFAULTS = 6
%PRINTACTION_SERVERPROPERTIES = 7

%OFFLINE_STATUS_LOCAL      = &H0001  ' If open, it's open locally
%OFFLINE_STATUS_REMOTE     = &H0002  ' If open, it's open remotely
%OFFLINE_STATUS_INCOMPLETE = &H0004  ' The local copy is currently imcomplete.
                                     ' The file will not be available offline
                                     ' until it has been synchronized.

%SHIL_LARGE      = 0  ' normally 32x32
%SHIL_SMALL      = 1  ' normally 16x16
%SHIL_EXTRALARGE = 2
%SHIL_SYSSMALL   = 3  ' like %SHIL_SMALL, but tracks system small icon metric correctly
%SHIL_JUMBO        = 4   ' normally 256x256
%SHIL_LAST         = %SHIL_JUMBO

' QueryContextMenu uFlags
%CMF_NORMAL              = &H00000000
%CMF_DEFAULTONLY         = &H00000001
%CMF_VERBSONLY           = &H00000002
%CMF_EXPLORE             = &H00000004
%CMF_NOVERBS             = &H00000008
%CMF_CANRENAME           = &H00000010
%CMF_NODEFAULT           = &H00000020
%CMF_INCLUDESTATIC       = &H00000040
%CMF_EXTENDEDVERBS       = &H00000100      ' rarely used verbs
%CMF_RESERVED            = &Hffff0000???   ' View specific


' GetCommandString uFlags
%GCS_VERBA        = &H00000000     ' canonical verb
%GCS_HELPTEXTA    = &H00000001     ' help text (for status bar)
%GCS_VALIDATEA    = &H00000002     ' validate command exists
%GCS_VERBW        = &H00000004     ' canonical verb (unicode)
%GCS_HELPTEXTW    = &H00000005     ' help text (unicode version)
%GCS_VALIDATEW    = &H00000006     ' validate command exists (unicode)
%GCS_UNICODE      = &H00000004     ' for bit testing - Unicode string

%GCS_VERB      = %GCS_VERBA
%GCS_HELPTEXT  = %GCS_HELPTEXTA
%GCS_VALIDATE  = %GCS_VALIDATEA

$CMDSTR_NEWFOLDER   = "NewFolder"
$CMDSTR_VIEWLIST    = "ViewList"
$CMDSTR_VIEWDETAILS = "ViewDetails"

' GetIconLocation() input flags

%GIL_OPENICON    = &H0001  ' allows containers to specify an "open" look
%GIL_FORSHELL    = &H0002  ' icon is to be displayed in a ShellFolder
%GIL_ASYNC       = &H0020  ' this is an async extract, return E_PENDING
%GIL_DEFAULTICON = &H0040  ' get the default icon location if the final one takes too long to get
%GIL_FORSHORTCUT = &H0080  ' the icon is for a shortcut to the object

' GetIconLocation() return flags

%GIL_SIMULATEDOC = &H0001  ' simulate this document icon for this
%GIL_PERINSTANCE = &H0002  ' icons from this class are per instance (each file has its own)
%GIL_PERCLASS    = &H0004  ' icons from this class per class (shared for all files of this type)
%GIL_NOTFILENAME = &H0008  ' location is not a filename, must call ::ExtractIcon
%GIL_DONTCACHE   = &H0010  ' this icon should not be cached

%ISIOI_ICONFILE  = &H00000001  ' path is returned through pwszIconFile
%ISIOI_ICONINDEX = &H00000002  ' icon index in pwszIconFile is returned through pIndex

%OI_ASYNC = &HFFFFEEEE???

%IDO_SHGIOI_SHARE    =  &H0FFFFFFF
%IDO_SHGIOI_LINK     =  &H0FFFFFFE
%IDO_SHGIOI_SLOWFILE = &H0FFFFFFFD
%IDO_SHGIOI_DEFAULT  = &H0FFFFFFFC

' IShellLinkDataList::GetFlags()/SetFlags()
' SHELL_LINK_DATA_FLAGS enumerated type
%SLDF_HAS_ID_LIST        = &H00000001    ' Shell link saved with ID list
%SLDF_HAS_LINK_INFO      = &H00000002    ' Shell link saved with LinkInfo
%SLDF_HAS_NAME           = &H00000004
%SLDF_HAS_RELPATH        = &H00000008
%SLDF_HAS_WORKINGDIR     = &H00000010
%SLDF_HAS_ARGS           = &H00000020
%SLDF_HAS_ICONLOCATION   = &H00000040
%SLDF_UNICODE            = &H00000080    ' the strings are unicode
%SLDF_FORCE_NO_LINKINFO  = &H00000100    ' don't create a LINKINFO (make a dumb link)
%SLDF_HAS_EXP_SZ         = &H00000200    ' the link contains expandable env strings
%SLDF_RUN_IN_SEPARATE    = &H00000400    ' Run the 16-bit target exe in a separate VDM/WOW
%SLDF_HAS_LOGO3ID        = &H00000800    ' this link is a special Logo3/MSICD link
%SLDF_HAS_DARWINID       = &H00001000    ' this link is a special Darwin link
%SLDF_RUNAS_USER         = &H00002000    ' Run this link as a different user
%SLDF_HAS_EXP_ICON_SZ    = &H00004000    ' contains expandable env string for icon path
%SLDF_NO_PIDL_ALIAS      = &H00008000    ' don't ever resolve to a logical location
%SLDF_FORCE_UNCNAME      = &H00010000    ' make GetPath() prefer the UNC name to the local name
%SLDF_RUN_WITH_SHIMLAYER = &H00020000    ' Launch the target of this link w/ shim layer active
%SLDF_RESERVED           = &H80000000??? ' Reserved-- so we can use the low word as an index value in the future

%NT_CONSOLE_PROPS_SIG    = &HA0000002???
%NT_FE_CONSOLE_PROPS_SIG = &HA0000004???
%EXP_DARWIN_ID_SIG       = &HA0000006???
' BUGBUG (reinerf) - this has the same value as EXP_SZ_ICON_SIG?!?!?!
%EXP_LOGO3_ID_SIG        = &HA0000007???

%EXP_SPECIAL_FOLDER_SIG  = &HA0000005??? ' LPEXP_SPECIAL_FOLDER
%EXP_SZ_LINK_SIG         = &HA0000001??? ' LPEXP_SZ_LINK (target)
%EXP_SZ_ICON_SIG         = &HA0000007??? ' LPEXP_SZ_LINK (icon)

' Define File View Show Info Flags.
%FVSIF_RECT      = &H00000001   ' The rect variable has valid data.
%FVSIF_PINNED    = &H00000002   ' We should Initialize pinned

%FVSIF_NEWFAILED = &H08000000   ' The new file passed back failed
                                ' to be viewed.

%FVSIF_NEWFILE   = &H80000000??? ' A new file to view has been returned
%FVSIF_CANVIEWIT = &H40000000    ' The viewer can view it.

%FCIDM_SHVIEWFIRST  = &H00000
%FCIDM_SHVIEWLAST   = &H07fff
%FCIDM_BROWSERFIRST = &H0a000
%FCIDM_BROWSERLAST  = &H0bf00
%FCIDM_GLOBALFIRST  = &H08000
%FCIDM_GLOBALLAST   = &H09fff

'
' Global submenu IDs and separator IDs
'
%FCIDM_MENU_FILE             = %FCIDM_GLOBALFIRST + &H0000
%FCIDM_MENU_EDIT             = %FCIDM_GLOBALFIRST + &H0040
%FCIDM_MENU_VIEW             = %FCIDM_GLOBALFIRST + &H0080
%FCIDM_MENU_VIEW_SEP_OPTIONS = %FCIDM_GLOBALFIRST + &H0081
%FCIDM_MENU_TOOLS            = %FCIDM_GLOBALFIRST + &H00c0 ' for Win9x compat
%FCIDM_MENU_TOOLS_SEP_GOTO   = %FCIDM_GLOBALFIRST + &H00c1 ' for Win9x compat
%FCIDM_MENU_HELP             = %FCIDM_GLOBALFIRST + &H0100
%FCIDM_MENU_FIND             = %FCIDM_GLOBALFIRST + &H0140
%FCIDM_MENU_EXPLORE          = %FCIDM_GLOBALFIRST + &H0150
%FCIDM_MENU_FAVORITES        = %FCIDM_GLOBALFIRST + &H0170

' control IDs known to the view

%FCIDM_TOOLBAR      = %FCIDM_BROWSERFIRST
%FCIDM_STATUS       = %FCIDM_BROWSERFIRST + 1

' The resource id of the offline cursor
' This cursor is avaialble in shdocvw.dll
%IDC_OFFLINE_HAND = 103

%CDBOSC_SETFOCUS    = &H00000000
%CDBOSC_KILLFOCUS   = &H00000001
%CDBOSC_SELCHANGE   = &H00000002
%CDBOSC_RENAME      = &H00000003
%CDBOSC_STATECHANGE = &H00000004

%CDB2N_CONTEXTMENU_DONE  = &H00000001
%CDB2N_CONTEXTMENU_START = &H00000002

' GetViewFlags
%CDB2GVF_SHOWALLFILES = &H00000001

' Browsing for directory.
%BIF_STATUSTEXT         = &H0004  ' Top of the dialog has 2 lines of text for BROWSEINFO.lpszTitle and one line if
                                  ' this flag is set.  Passing the message BFFM_SETSTATUSTEXTA to the hwnd can set the
                                  ' rest of the text.  This is not used with BIF_USENEWUI and BROWSEINFO.lpszTitle gets
                                  ' all three lines of text.
%BIF_BROWSEFORCOMPUTER  = &H00001000  ' Browsing for Computers.
%BIF_BROWSEFORPRINTER   = &H00002000  ' Browsing for Printers

' message from browser
%BFFM_INITIALIZED      = 1
%BFFM_SELCHANGED       = 2
%BFFM_VALIDATEFAILEDA  = 3   ' lParam:szPath ret:1(cont),0(EndDialog)
%BFFM_VALIDATEFAILEDW  = 4   ' lParam:wzPath ret:1(cont),0(EndDialog)

' messages to browser
%BFFM_SETSTATUSTEXTA   = %WM_USER + 100
%BFFM_ENABLEOK         = %WM_USER + 101
%BFFM_SETSELECTIONA    = %WM_USER + 102
%BFFM_SETSELECTIONW    = %WM_USER + 103
%BFFM_SETSTATUSTEXTW   = %WM_USER + 104
%BFFM_SETOKTEXT        = %WM_USER + 105  ' Unicode only
%BFFM_SETEXPANDED      = %WM_USER + 106  ' Unicode only

#IF %DEF(%UNICODE)
%BFFM_SETSTATUSTEXT  = %BFFM_SETSTATUSTEXTW
%BFFM_SETSELECTION   = %BFFM_SETSELECTIONW
%BFFM_VALIDATEFAILED = %BFFM_VALIDATEFAILEDW
#ELSE
%BFFM_SETSTATUSTEXT  = %BFFM_SETSTATUSTEXTA
%BFFM_SETSELECTION   = %BFFM_SETSELECTIONA
%BFFM_VALIDATEFAILED = %BFFM_VALIDATEFAILEDA
#ENDIF

' SHAddToRecentDocs
%SHARD_PIDL    = &H00000001
%SHARD_PATHA   = &H00000002
%SHARD_PATHW   = &H00000003

%SHARD_PATH  = %SHARD_PATHA

%ISHCUTCMDID_DOWNLOADICON      = 0
%ISHCUTCMDID_INTSHORTCUTCREATE = 1
%CMDID_INTSHORTCUTCREATE       = %ISHCUTCMDID_INTSHORTCUTCREATE

' Flags for IProgressDialog::StartProgressDialog() (dwFlags)
%PROGDLG_NORMAL        = &H00000000 ' default normal progress dlg behavior
%PROGDLG_MODAL         = &H00000001 ' the dialog is modal to its hwndParent (default is modeless)
%PROGDLG_AUTOTIME      = &H00000002 ' automatically updates the "Line3" text with the "time remaining" (you can't call SetLine3 if you pass this!)
%PROGDLG_NOTIME        = &H00000004 ' we don't show the "time remaining" if this is set. We need this if dwTotal < dwCompleted for sparse files
%PROGDLG_NOMINIMIZE    = &H00000008 ' Do not have a minimize button in the caption bar.
%PROGDLG_NOPROGRESSBAR = &H00000010 ' Don't display the progress bar

' Time Actions (dwTimerAction)
%PDTIMER_RESET     = &H00000001       ' Reset the timer so the progress will be calculated from now until the first ::SetProgress() is called so

' flags for RemoveToolbar
%DWFRF_NORMAL           = &H0000
%DWFRF_DELETECONFIGDATA = &H0001

' flags for AddToolbar
%DWFAF_HIDDEN = &H0001   ' add hidden

' Convenient state values
%IRTIR_TASK_NOT_RUNNING = 0
%IRTIR_TASK_RUNNING     = 1
%IRTIR_TASK_SUSPENDED   = 2
%IRTIR_TASK_PENDING     = 3
%IRTIR_TASK_FINISHED    = 4

%COMPONENT_TOP = &H3fffffff  ' izOrder value meaning component is at the top

' iCompType values
%COMP_TYPE_HTMLDOC = 0
%COMP_TYPE_PICTURE = 1
%COMP_TYPE_WEBSITE = 2
%COMP_TYPE_CONTROL = 3
%COMP_TYPE_CFHTML  = 4
%COMP_TYPE_MAX     = 4

' Defines for dwCurItemState
%IS_NORMAL             = &H00000001
%IS_FULLSCREEN         = &H00000002
%IS_SPLIT              = &H00000004
%IS_VALIDSIZESTATEBITS = %IS_NORMAL OR %IS_SPLIT OR %IS_FULLSCREEN  ' The set of IS_* state bits which define the "size" of the component - these bits are mutually exclusive.
%IS_VALIDSTATEBITS     = %IS_NORMAL OR %IS_SPLIT OR %IS_FULLSCREEN OR &H80000000 OR &H40000000  ' All of the currently defined %IS_* bits.

' Flags for IActiveDesktop::ApplyChanges()
%AD_APPLY_SAVE             = &H00000001
%AD_APPLY_HTMLGEN          = &H00000002
%AD_APPLY_REFRESH          = &H00000004
%AD_APPLY_ALL              = %AD_APPLY_SAVE OR %AD_APPLY_HTMLGEN OR %AD_APPLY_REFRESH
%AD_APPLY_FORCE            = &H00000008
%AD_APPLY_BUFFERED_REFRESH = &H00000010
%AD_APPLY_DYNAMICREFRESH   = &H00000020

' Flags for IActiveDesktop::GetWallpaperOptions()
'           IActiveDesktop::SetWallpaperOptions()
%WPSTYLE_CENTER  = 0
%WPSTYLE_TILE    = 1
%WPSTYLE_STRETCH = 2
%WPSTYLE_MAX     = 3

%SETWALLPAPER_DEFAULT = &HFFFFFFFF???

' Flags for IActiveDesktop::ModifyComponent()
%COMP_ELEM_TYPE          = &H00000001
%COMP_ELEM_CHECKED       = &H00000002
%COMP_ELEM_DIRTY         = &H00000004
%COMP_ELEM_NOSCROLL      = &H00000008
%COMP_ELEM_POS_LEFT      = &H00000010
%COMP_ELEM_POS_TOP       = &H00000020
%COMP_ELEM_SIZE_WIDTH    = &H00000040
%COMP_ELEM_SIZE_HEIGHT   = &H00000080
%COMP_ELEM_POS_ZINDEX    = &H00000100
%COMP_ELEM_SOURCE        = &H00000200
%COMP_ELEM_FRIENDLYNAME  = &H00000400
%COMP_ELEM_SUBSCRIBEDURL = &H00000800
%COMP_ELEM_ORIGINAL_CSI  = &H00001000
%COMP_ELEM_RESTORED_CSI  = &H00002000
%COMP_ELEM_CURITEMSTATE  = &H00004000

%COMP_ELEM_ALL = %COMP_ELEM_TYPE OR %COMP_ELEM_CHECKED OR %COMP_ELEM_DIRTY _
    OR %COMP_ELEM_NOSCROLL OR %COMP_ELEM_POS_LEFT OR %COMP_ELEM_SIZE_WIDTH _
    OR %COMP_ELEM_SIZE_HEIGHT OR %COMP_ELEM_POS_ZINDEX OR %COMP_ELEM_SOURCE _
    OR %COMP_ELEM_FRIENDLYNAME OR %COMP_ELEM_POS_TOP OR %COMP_ELEM_SUBSCRIBEDURL _
    OR %COMP_ELEM_ORIGINAL_CSI OR %COMP_ELEM_RESTORED_CSI OR %COMP_ELEM_CURITEMSTATE

' Flags for IActiveDesktop::AddDesktopItemWithUI()
' enum tagDTI_ADTIWUI
%DTI_ADDUI_DEFAULT       = &H00000000
%DTI_ADDUI_DISPSUBWIZARD = &H00000001
%DTI_ADDUI_POSITIONITEM  = &H00000002

' Flags for IActiveDesktop::AddUrl()
%ADDURL_SILENT = &H0001

' Default positions for ADI
%COMPONENT_DEFAULT_LEFT    = &H0FFFF
%COMPONENT_DEFAULT_TOP     = &H0FFFF

%MAX_COLUMN_NAME_LEN = 80
%MAX_COLUMN_DESC_LEN = 128

%SHCDF_UPDATEITEM = &H00000001   ' this flag is a hint that the file has changed since the last call to GetItemData

' FILEDESCRIPTOR.dwFlags field indicate which fields are to be used
' (enumerated type FD_FLAGS)
'
%FD_CLSID      = &H00001
%FD_SIZEPOINT  = &H00002
%FD_ATTRIBUTES = &H00004
%FD_CREATETIME = &H00008
%FD_ACCESSTIME = &H00010
%FD_WRITESTIME = &H00020
%FD_FILESIZE   = &H00040
%FD_PROGRESSUI = &H04000  ' Show Progress UI w/Drag and Drop
%FD_LINKUI     = &H08000  ' 'link' UI is prefered

' File System Notification flags

%SHCNE_RENAMEITEM       = &H00000001
%SHCNE_CREATE           = &H00000002
%SHCNE_DELETE           = &H00000004
%SHCNE_MKDIR            = &H00000008
%SHCNE_RMDIR            = &H00000010
%SHCNE_MEDIAINSERTED    = &H00000020
%SHCNE_MEDIAREMOVED     = &H00000040
%SHCNE_DRIVEREMOVED     = &H00000080
%SHCNE_DRIVEADD         = &H00000100
%SHCNE_NETSHARE         = &H00000200
%SHCNE_NETUNSHARE       = &H00000400
%SHCNE_ATTRIBUTES       = &H00000800
%SHCNE_UPDATEDIR        = &H00001000
%SHCNE_UPDATEITEM       = &H00002000
%SHCNE_SERVERDISCONNECT = &H00004000
%SHCNE_UPDATEIMAGE      = &H00008000
%SHCNE_DRIVEADDGUI      = &H00010000
%SHCNE_RENAMEFOLDER     = &H00020000
%SHCNE_FREESPACE        = &H00040000

' %SHCNE_EXTENDED_EVENT: the extended event is identified in dwItem1,
' packed in LPITEMIDLIST format (same as SHCNF_DWORD packing).
' Additional information can be passed in the dwItem2 parameter
' of SHChangeNotify (called "pidl2" below), which if present, must also
' be in LPITEMIDLIST format.
'
' Unlike the standard events, the extended events are ORDINALs, so we
' don't run out of bits.  Extended events follow the SHCNEE_* naming
' convention.
'
' The dwItem2 parameter varies according to the extended event.

%SHCNE_EXTENDED_EVENT   = &H04000000

%SHCNE_ASSOCCHANGED     = &H08000000

%SHCNE_DISKEVENTS       = &H0002381F
%SHCNE_GLOBALEVENTS     = &H0C0581E0 ' Events that dont match pidls first
%SHCNE_ALLEVENTS        = &H7FFFFFFF
%SHCNE_INTERRUPT        = &H80000000??? ' The presence of this flag indicates
                                        ' that the event was generated by an
                                        ' interrupt.  It is stripped out before
                                        ' the clients of SHCNNotify_ see it.

' SHCNE_EXTENDED_EVENT extended events.  These events are ordinals.
' This is not a bitfield.

%SHCNEE_ORDERCHANGED  = 2 ' pidl2 is the changed folder
%SHCNEE_MSI_CHANGE    = 4 ' pidl2 is a SHChangeProductKeyAsIDList
%SHCNEE_MSI_UNINSTALL = 5 ' pidl2 is a SHChangeProductKeyAsIDList


' Flags
' uFlags & SHCNF_TYPE is an ID which indicates what dwItem1 and dwItem2 mean
%SHCNF_IDLIST      = &H0000     ' LPITEMIDLIST
%SHCNF_PATHA       = &H0001     ' path name
%SHCNF_PRINTERA    = &H0002     ' printer friendly name
%SHCNF_DWORD       = &H0003     ' DWORD
%SHCNF_PATHW       = &H0005     ' path name
%SHCNF_PRINTERW    = &H0006     ' printer friendly name
%SHCNF_TYPE        = &H00FF
%SHCNF_FLUSH       = &H1000
%SHCNF_FLUSHNOWAIT = &H2000

%QITIPF_DEFAULT       = &H00000000
%QITIPF_USENAME       = &H00000001
%QITIPF_LINKNOTARGET  = &H00000002
%QITIPF_LINKUSETARGET = &H00000004
%QITIPF_USESLOWTIP    = &H00000008  ' Flag says it's OK to take a long time generating tip

%QIF_CACHED           = &H00000001
%QIF_DONTEXPANDFOLDER = &H00000002

%SHGDFIL_FINDDATA      = 1
%SHGDFIL_NETRESOURCE   = 2
%SHGDFIL_DESCRIPTIONID = 3

%SHDID_ROOT_REGITEM        = 1
%SHDID_FS_FILE             = 2
%SHDID_FS_DIRECTORY        = 3
%SHDID_FS_OTHER            = 4
%SHDID_COMPUTER_DRIVE35    = 5
%SHDID_COMPUTER_DRIVE525   = 6
%SHDID_COMPUTER_REMOVABLE  = 7
%SHDID_COMPUTER_FIXED      = 8
%SHDID_COMPUTER_NETDRIVE   = 9
%SHDID_COMPUTER_CDROM      = 10
%SHDID_COMPUTER_RAMDISK    = 11
%SHDID_COMPUTER_OTHER      = 12
%SHDID_NET_DOMAIN          = 13
%SHDID_NET_SERVER          = 14
%SHDID_NET_SHARE           = 15
%SHDID_NET_RESTOFNET       = 16
%SHDID_NET_OTHER           = 17
%SHDID_COMPUTER_IMAGING    = 18
%SHDID_COMPUTER_AUDIO      = 19
%SHDID_COMPUTER_SHAREDDOCS = 20

%PID_IS_URL         = 2
%PID_IS_NAME        = 4
%PID_IS_WORKINGDIR  = 5
%PID_IS_HOTKEY      = 6
%PID_IS_SHOWCMD     = 7
%PID_IS_ICONINDEX   = 8
%PID_IS_ICONFILE    = 9
%PID_IS_WHATSNEW    = 10
%PID_IS_AUTHOR      = 11
%PID_IS_DESCRIPTION = 12
%PID_IS_COMMENT     = 13

' PROPIDs for Internet Sites (FMTID_InternetSite) to be used with
' IPropertySetStorage/IPropertyStorage

%PID_INTSITE_WHATSNEW     = 2
%PID_INTSITE_AUTHOR       = 3
%PID_INTSITE_LASTVISIT    = 4
%PID_INTSITE_LASTMOD      = 5
%PID_INTSITE_VISITCOUNT   = 6
%PID_INTSITE_DESCRIPTION  = 7
%PID_INTSITE_COMMENT      = 8
%PID_INTSITE_FLAGS        = 9
%PID_INTSITE_CONTENTLEN   = 10
%PID_INTSITE_CONTENTCODE  = 11
%PID_INTSITE_RECURSE      = 12
%PID_INTSITE_WATCH        = 13
%PID_INTSITE_SUBSCRIPTION = 14
%PID_INTSITE_URL          = 15
%PID_INTSITE_TITLE        = 16
%PID_INTSITE_CODEPAGE     = 18
%PID_INTSITE_TRACKING     = 19
%PID_INTSITE_ICONINDEX    = 20
%PID_INTSITE_ICONFILE     = 21

' Flags for PID_IS_FLAGS
%PIDISF_RECENTLYCHANGED  = &H00000001
%PIDISF_CACHEDSTICKY     = &H00000002
%PIDISF_CACHEIMAGES      = &H00000010
%PIDISF_FOLLOWALLLINKS   = &H00000020

' Values for PID_INTSITE_WATCH
%PIDISM_GLOBAL    = 0       ' Monitor based on global setting
%PIDISM_WATCH     = 1       ' User says watch
%PIDISM_DONTWATCH = 2       ' User says don't watch

%SSF_SHOWALLOBJECTS       = &H00000001
%SSF_SHOWEXTENSIONS       = &H00000002
%SSF_SHOWCOMPCOLOR        = &H00000008
%SSF_SHOWSYSFILES         = &H00000020
%SSF_DOUBLECLICKINWEBVIEW = &H00000080
%SSF_SHOWATTRIBCOL        = &H00000100
%SSF_DESKTOPHTML          = &H00000200
%SSF_WIN95CLASSIC         = &H00000400
%SSF_DONTPRETTYPATH       = &H00000800
%SSF_SHOWINFOTIP          = &H00002000
%SSF_MAPNETDRVBUTTON      = &H00001000
%SSF_NOCONFIRMRECYCLE     = &H00008000
%SSF_HIDEICONS            = &H00004000

%SHPPFW_NONE           = &H00000000
%SHPPFW_DIRCREATE      = &H00000001        ' Create the directory if it doesn't exist without asking the user.
%SHPPFW_DEFAULT        = %SHPPFW_DIRCREATE ' May change
%SHPPFW_ASKDIRCREATE   = &H00000002        ' Create the directory if it doesn't exist after asking the user.
%SHPPFW_IGNOREFILENAME = &H00000004        ' Ignore the last item in pszPath because it's a file.  Example: pszPath="C:\DirA\DirB", only use "C:\DirA".
%SHPPFW_NOWRITECHECK   = &H00000008        ' Caller only needs to read from the drive, so don't check if it's READ ONLY.
%SHPPFW_MEDIACHECKONLY = &H00000010        ' do the retrys on the media (or net path), return errors if the file can't be found
%SIMULATED_FONTTYPE    = &H00008000
%PRINTER_FONTTYPE      = &H00004000
%SCREEN_FONTTYPE       = &H00002000
%BOLD_FONTTYPE         = &H100
%ITALIC_FONTTYPE       = &H200
%REGULAR_FONTTYPE      = &H400

%WM_PSD_PAGESETUPDLG   = %WM_USER
%WM_PSD_FULLPAGERECT   = %WM_USER + 1
%WM_PSD_MINMARGINRECT  = %WM_USER + 2
%WM_PSD_MARGINRECT     = %WM_USER + 3
%WM_PSD_GREEKTEXTRECT  = %WM_USER + 4
%WM_PSD_ENVSTAMPRECT   = %WM_USER + 5
%WM_PSD_YAFULLPAGERECT = %WM_USER + 6

%IMAGE_BITMAP       = 0
%IMAGE_ICON         = 1
%IMAGE_CURSOR       = 2
%IMAGE_ENHMETAFILE  = 3

' ----- Symbols -----
%VS_VERSION_INFO = 1
%VS_USER_DEFINED = 100

' ----- VS_VERSION.dwFileFlags -----
%VS_FFI_SIGNATURE     = &HFEEF04BD???
%VS_FFI_STRUCVERSION  = &H10000
%VS_FFI_FILEFLAGSMASK = &H3F&

' ----- VS_VERSION.dwFileFlags -----
%VS_FF_INFOINFERRED = &H10&

' ----- VS_VERSION.dwFileOS -----
%VOS_UNKNOWN = &H00000000
%VOS_DOS     = &H00010000
%VOS_OS216   = &H00020000
%VOS_OS232   = &H00030000
%VOS_NT      = &H00040000
%VOS_WINCE   = &H00050000

%VOS__BASE         = &H0
%VOS__WINDOWS16    = &H1
%VOS__PM16         = &H2
%VOS__PM32         = &H3
%VOS__WINDOWS32    = &H4

%VOS_DOS_WINDOWS16 = &H10001
%VOS_DOS_WINDOWS32 = &H10004
%VOS_OS216_PM16    = &H20002
%VOS_OS232_PM32    = &H30003
%VOS_NT_WINDOWS32  = &H40004

' ----- VS_VERSION.dwFileType -----
%VFT_UNKNOWN    = &H0&
%VFT_APP        = &H1&
%VFT_DLL        = &H2&
%VFT_DRV        = &H3&
%VFT_FONT       = &H4&
%VFT_VXD        = &H5&
%VFT_STATIC_LIB = &H7&

' ----- VS_VERSION.dwFileSubtype for VFT_WINDOWS_DRV -----
%VFT2_UNKNOWN         = &H00
%VFT2_DRV_PRINTER     = &H01
%VFT2_DRV_KEYBOARD    = &H02
%VFT2_DRV_LANGUAGE    = &H03
%VFT2_DRV_DISPLAY     = &H04
%VFT2_DRV_MOUSE       = &H05
%VFT2_DRV_NETWORK     = &H06
%VFT2_DRV_SYSTEM      = &H07
%VFT2_DRV_INSTALLABLE = &H08
%VFT2_DRV_SOUND       = &H09
%VFT2_DRV_COMM        = &H0A
%VFT2_DRV_INPUTMETHOD = &H0B
%VFT2_DRV_VERSIONED_PRINTER = &H0C

' ----- VS_VERSION.dwFileSubtype for VFT_WINDOWS_FONT -----
%VFT2_FONT_RASTER     = &H1
%VFT2_FONT_VECTOR     = &H2
%VFT2_FONT_TRUETYPE   = &H3

' ----- VerFindFile() flags -----
%VFFF_ISSHAREDFILE = &H1

%VFF_CURNEDEST    = &H1
%VFF_FILEINUSE    = &H2
%VFF_BUFFTOOSMALL = &H4

' ----- VerInstallFile() flags -----
%VIFF_FORCEINSTALL  = &H1
%VIFF_DONTDELETEOLD = &H2

%VIF_TEMPFILE          = &H00000001
%VIF_MISMATCH          = &H00000002
%VIF_SRCOLD            = &H00000004

%VIF_DIFFLANG          = &H00000008
%VIF_DIFFCODEPG        = &H00000010
%VIF_DIFFTYPE          = &H00000020

%VIF_WRITEPROT         = &H00000040
%VIF_FILEINUSE         = &H00000080
%VIF_OUTOFSPACE        = &H00000100
%VIF_ACCESSVIOLATION   = &H00000200
%VIF_SHARINGVIOLATION  = &H00000400
%VIF_CANNOTCREATE      = &H00000800
%VIF_CANNOTDELETE      = &H00001000
%VIF_CANNOTRENAME      = &H00002000
%VIF_CANNOTDELETECUR   = &H00004000
%VIF_OUTOFMEMORY       = &H00008000

%VIF_CANNOTREADSRC     = &H00010000
%VIF_CANNOTREADDST     = &H00020000
%VIF_BUFFTOOSMALL      = &H00040000
%VIF_CANNOTLOADLZ32    = &H00080000
%VIF_CANNOTLOADCABINET = &H00100000
