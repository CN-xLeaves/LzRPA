'------------------------------------------------------------------------------
'
'  WinGDI.inc -- GDI procedure declarations, constant definitions and macros
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from WinGDI.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WINGDI = 1

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "WinDef.inc"


#IF %DEF(%MAC)
#INCLUDE "MacWin32.inc"
#ENDIF

#IF NOT %DEF(%WINVER)
%WINVER = &H0500   ' version 5.0
#ENDIF  ' WINVER

#IF NOT %DEF(%NOGDI)

#IF NOT %DEF(%NORASTEROPS)

' Binary raster ops
%R2_BLACK          =  1   '  0
%R2_NOTMERGEPEN    =  2   ' DPon
%R2_MASKNOTPEN     =  3   ' DPna
%R2_NOTCOPYPEN     =  4   ' PN
%R2_MASKPENNOT     =  5   ' PDna
%R2_NOT            =  6   ' Dn
%R2_XORPEN         =  7   ' DPx
%R2_NOTMASKPEN     =  8   ' DPan
%R2_MASKPEN        =  9   ' DPa
%R2_NOTXORPEN      =  10  ' DPxn
%R2_NOP            =  11  ' D
%R2_MERGENOTPEN    =  12  ' DPno
%R2_COPYPEN        =  13  ' P
%R2_MERGEPENNOT    =  14  ' PDno
%R2_MERGEPEN       =  15  ' DPo
%R2_WHITE          =  16  '  1
%R2_LAST           =  16

' Ternary raster operations
%SRCCOPY             = &H00CC0020 ' dest = source
%SRCPAINT            = &H00EE0086 ' dest = source OR dest
%SRCAND              = &H008800C6 ' dest = source AND dest
%SRCINVERT           = &H00660046 ' dest = source XOR dest
%SRCERASE            = &H00440328 ' dest = source AND (NOT dest )
%NOTSRCCOPY          = &H00330008 ' dest = (NOT source)
%NOTSRCERASE         = &H001100A6 ' dest = (NOT src) AND (NOT dest)
%MERGECOPY           = &H00C000CA ' dest = (source AND pattern)
%MERGEPAINT          = &H00BB0226 ' dest = (NOT source) OR dest
%PATCOPY             = &H00F00021 ' dest = pattern
%PATPAINT            = &H00FB0A09 ' dest = DPSnoo
%PATINVERT           = &H005A0049 ' dest = pattern XOR dest
%DSTINVERT           = &H00550009 ' dest = (NOT dest)
%BLACKNESS           = &H00000042 ' dest = BLACK
%WHITENESS           = &H00FF0062 ' dest = WHITE

#IF (%WINVER >= &H0500)
%NOMIRRORBITMAP      = &H80000000??? ' Do not Mirror the bitmap in this call
%CAPTUREBLT          = &H40000000    ' Include layered windows
#ENDIF ' WINVER >= &H0500

' Quaternary raster codes
MACRO MAKEROP4(fore,back)=LO(DWORD,((back)*256 AND &HFF000000???) OR (fore))

#ENDIF ' NORASTEROPS

%GDI_ERROR  = &HFFFFFFFF???
%HGDI_ERROR = &HFFFFFFFF???

' Region Flags
%ERROR             = 0
%ERRORAPI          = %ERROR  ' [legacy]
%NULLREGION        = 1
%SIMPLEREGION      = 2
%COMPLEXREGION     = 3
%RGN_ERROR         = %ERROR

' CombineRgn() Styles
%RGN_AND           = 1
%RGN_OR            = 2
%RGN_XOR           = 3
%RGN_DIFF          = 4
%RGN_COPY          = 5
%RGN_MIN           = %RGN_AND
%RGN_MAX           = %RGN_COPY

' StretchBlt() Modes
%BLACKONWHITE               = 1
%WHITEONBLACK               = 2
%COLORONCOLOR               = 3
%HALFTONE                   = 4
%MAXSTRETCHBLTMODE          = 4

#IF (%WINVER >= &H0400)
' New StretchBlt() Modes
%STRETCH_ANDSCANS    = %BLACKONWHITE
%STRETCH_ORSCANS     = %WHITEONBLACK
%STRETCH_DELETESCANS = %COLORONCOLOR
%STRETCH_HALFTONE    = %HALFTONE
#ENDIF ' WINVER >= &H0400

' PolyFill() Modes
%ALTERNATE                  = 1
%WINDING                    = 2
%POLYFILL_LAST              = 2

' Layout Orientation Options
#IF (%WINVER >= &H0500)
%LAYOUT_RTL                        = &H00000001 ' Right to left
%LAYOUT_BTT                        = &H00000002 ' Bottom to top
%LAYOUT_VBH                        = &H00000004 ' Vertical before horizontal
%LAYOUT_ORIENTATIONMASK            = (%LAYOUT_RTL OR %LAYOUT_BTT OR %LAYOUT_VBH)
%LAYOUT_BITMAPORIENTATIONPRESERVED = &H00000008
#ENDIF ' WINVER >= &H0500

' Text Alignment Options
%TA_NOUPDATECP              = 0
%TA_UPDATECP                = 1

%TA_LEFT                    = 0
%TA_RIGHT                   = 2
%TA_CENTER                  = 6

%TA_TOP                     = 0
%TA_BOTTOM                  = 8
%TA_BASELINE                = 24
#IF (%WINVER >= &H0400)
%TA_RTLREADING              = 256
%TA_MASK     = (%TA_BASELINE OR %TA_CENTER OR %TA_UPDATECP OR %TA_RTLREADING)
#ELSE
%TA_MASK     = (%TA_BASELINE OR %TA_CENTER OR %TA_UPDATECP)
#ENDIF

%VTA_BASELINE = %TA_BASELINE
%VTA_LEFT     = %TA_BOTTOM
%VTA_RIGHT    = %TA_TOP
%VTA_CENTER   = %TA_CENTER
%VTA_BOTTOM   = %TA_RIGHT
%VTA_TOP      = %TA_LEFT

%ETO_OPAQUE                 = &H0002
%ETO_CLIPPED                = &H0004
#IF (%WINVER >= &H0400)
%ETO_GLYPH_INDEX            = &H0010
%ETO_RTLREADING             = &H0080
%ETO_NUMERICSLOCAL          = &H0400
%ETO_NUMERICSLATIN          = &H0800
%ETO_IGNORELANGUAGE         = &H1000
#ENDIF ' WINVER >= &H0400
#IF (%WIN32_WINNT >= %WIN32_WINNT_WIN2K)
%ETO_PDY                    = &H2000
#ENDIF ' (%WIN32_WINNT >= %WIN32_WINNT_WIN2K)
#IF (%WIN32_WINNT >= %WIN32_WINNT_LONGHORN)
%ETO_REVERSE_INDEX_MAP      = &H10000
#ENDIF ' #IF (%WIN32_WINNT >= %WIN32_WINNT_LONGHORN)

%ASPECT_FILTERING           = &H0001

' Bounds Accumulation APIs

%DCB_RESET       = &H0001
%DCB_ACCUMULATE  = &H0002
%DCB_DIRTY       = %DCB_ACCUMULATE
%DCB_SET         = (%DCB_RESET OR %DCB_ACCUMULATE)
%DCB_ENABLE      = &H0004
%DCB_DISABLE     = &H0008

#IF NOT %DEF(%NOMETAFILE)

' Metafile Functions
%META_SETBKCOLOR            = &H0201
%META_SETBKMODE             = &H0102
%META_SETMAPMODE            = &H0103
%META_SETROP2               = &H0104
%META_SETRELABS             = &H0105
%META_SETPOLYFILLMODE       = &H0106
%META_SETSTRETCHBLTMODE     = &H0107
%META_SETTEXTCHAREXTRA      = &H0108
%META_SETTEXTCOLOR          = &H0209
%META_SETTEXTJUSTIFICATION  = &H020A
%META_SETWINDOWORG          = &H020B
%META_SETWINDOWEXT          = &H020C
%META_SETVIEWPORTORG        = &H020D
%META_SETVIEWPORTEXT        = &H020E
%META_OFFSETWINDOWORG       = &H020F
%META_SCALEWINDOWEXT        = &H0410
%META_OFFSETVIEWPORTORG     = &H0211
%META_SCALEVIEWPORTEXT      = &H0412
%META_LINETO                = &H0213
%META_MOVETO                = &H0214
%META_EXCLUDECLIPRECT       = &H0415
%META_INTERSECTCLIPRECT     = &H0416
%META_ARC                   = &H0817
%META_ELLIPSE               = &H0418
%META_FLOODFILL             = &H0419
%META_PIE                   = &H081A
%META_RECTANGLE             = &H041B
%META_ROUNDRECT             = &H061C
%META_PATBLT                = &H061D
%META_SAVEDC                = &H001E
%META_SETPIXEL              = &H041F
%META_OFFSETCLIPRGN         = &H0220
%META_TEXTOUT               = &H0521
%META_BITBLT                = &H0922
%META_STRETCHBLT            = &H0B23
%META_POLYGON               = &H0324
%META_POLYLINE              = &H0325
%META_ESCAPE                = &H0626
%META_RESTOREDC             = &H0127
%META_FILLREGION            = &H0228
%META_FRAMEREGION           = &H0429
%META_INVERTREGION          = &H012A
%META_PAINTREGION           = &H012B
%META_SELECTCLIPREGION      = &H012C
%META_SELECTOBJECT          = &H012D
%META_SETTEXTALIGN          = &H012E
%META_CHORD                 = &H0830
%META_SETMAPPERFLAGS        = &H0231
%META_EXTTEXTOUT            = &H0a32
%META_SETDIBTODEV           = &H0d33
%META_SELECTPALETTE         = &H0234
%META_REALIZEPALETTE        = &H0035
%META_ANIMATEPALETTE        = &H0436
%META_SETPALENTRIES         = &H0037
%META_POLYPOLYGON           = &H0538
%META_RESIZEPALETTE         = &H0139
%META_DIBBITBLT             = &H0940
%META_DIBSTRETCHBLT         = &H0b41
%META_DIBCREATEPATTERNBRUSH = &H0142
%META_STRETCHDIB            = &H0f43
%META_EXTFLOODFILL          = &H0548
#IF (%WINVER >= &H0500)
%META_SETLAYOUT             = &H0149
#ENDIF ' WINVER >= &H0500
%META_DELETEOBJECT          = &H01f0
%META_CREATEPALETTE         = &H00f7
%META_CREATEPATTERNBRUSH    = &H01F9
%META_CREATEPENINDIRECT     = &H02FA
%META_CREATEFONTINDIRECT    = &H02FB
%META_CREATEBRUSHINDIRECT   = &H02FC
%META_CREATEREGION          = &H06FF

#IF (%WINVER >= &H0400)
TYPE DRAWPATRECT
    ptPosition AS POINT
    ptSize     AS POINT
    wStyle     AS WORD
    wPattern   AS WORD
END TYPE
#ENDIF ' WINVER >= &H0400

#ENDIF ' NOMETAFILE

' GDI Escapes
%NEWFRAME                   = 1
%ABORTDOC                   = 2
%NEXTBAND                   = 3
%SETCOLORTABLE              = 4
%GETCOLORTABLE              = 5
%FLUSHOUTPUT                = 6
%DRAFTMODE                  = 7
%QUERYESCSUPPORT            = 8
%SETABORTPROC               = 9
%STARTDOC                   = 10
%ENDDOC                     = 11
%GETPHYSPAGESIZE            = 12
%GETPRINTINGOFFSET          = 13
%GETSCALINGFACTOR           = 14
%MFCOMMENT                  = 15
%GETPENWIDTH                = 16
%SETCOPYCOUNT               = 17
%SELECTPAPERSOURCE          = 18
%DEVICEDATA                 = 19
%PASSTHROUGH                = 19
%GETTECHNOLGY               = 20
%GETTECHNOLOGY              = 20
%SETLINECAP                 = 21
%SETLINEJOIN                = 22
%SETMITERLIMIT              = 23
%BANDINFO                   = 24
%DRAWPATTERNRECT            = 25
%GETVECTORPENSIZE           = 26
%GETVECTORBRUSHSIZE         = 27
%ENABLEDUPLEX               = 28
%GETSETPAPERBINS            = 29
%GETSETPRINTORIENT          = 30
%ENUMPAPERBINS              = 31
%SETDIBSCALING              = 32
%EPSPRINTING                = 33
%ENUMPAPERMETRICS           = 34
%GETSETPAPERMETRICS         = 35
%POSTSCRIPT_DATA            = 37
%POSTSCRIPT_IGNORE          = 38
%MOUSETRAILS                = 39
%GETDEVICEUNITS             = 42

%GETEXTENDEDTEXTMETRICS     = 256
%GETEXTENTTABLE             = 257
%GETPAIRKERNTABLE           = 258
%GETTRACKKERNTABLE          = 259
%EXTTEXTOUT                 = 512
%GETFACENAME                = 513
%DOWNLOADFACE               = 514
%ENABLERELATIVEWIDTHS       = 768
%ENABLEPAIRKERNING          = 769
%SETKERNTRACK               = 770
%SETALLJUSTVALUES           = 771
%SETCHARSET                 = 772

%STRETCHBLT                 = 2048
%METAFILE_DRIVER            = 2049
%GETSETSCREENPARAMS         = 3072
%QUERYDIBSUPPORT            = 3073
%BEGIN_PATH                 = 4096
%CLIP_TO_PATH               = 4097
%END_PATH                   = 4098
%EXT_DEVICE_CAPS            = 4099
%RESTORE_CTM                = 4100
%SAVE_CTM                   = 4101
%SET_ARC_DIRECTION          = 4102
%SET_BACKGROUND_COLOR       = 4103
%SET_POLY_MODE              = 4104
%SET_SCREEN_ANGLE           = 4105
%SET_SPREAD                 = 4106
%TRANSFORM_CTM              = 4107
%SET_CLIP_BOX               = 4108
%SET_BOUNDS                 = 4109
%SET_MIRROR_MODE            = 4110
%OPENCHANNEL                = 4110
%DOWNLOADHEADER             = 4111
%CLOSECHANNEL               = 4112
%POSTSCRIPT_PASSTHROUGH     = 4115
%ENCAPSULATED_POSTSCRIPT    = 4116

%POSTSCRIPT_IDENTIFY        = 4117   ' new escape for NT5 pscript driver
%POSTSCRIPT_INJECTION       = 4118   ' new escape for NT5 pscript driver

%CHECKJPEGFORMAT            = 4119
%CHECKPNGFORMAT             = 4120

%GET_PS_FEATURESETTING      = 4121   ' new escape for NT5 pscript driver

%GDIPLUS_TS_QUERYVER        = 4122   ' private escape
%GDIPLUS_TS_RECORD          = 4123   ' private escape

'
' Return Values for MILCORE_TS_QUERYVER
'

#IF (%WIN32_WINNT >= %WIN32_WINNT_LONGHORN)
%MILCORE_TS_QUERYVER_RESULT_FALSE = &H0
%MILCORE_TS_QUERYVER_RESULT_TRUE  = &H7FFFFFFF
#ENDIF ' (%WIN32_WINNT >= %WIN32_WINNT_LONGHORN)


%SPCLPASSTHROUGH2           = 4568   ' new escape for NT5 pscript driver

'
' Parameters for POSTSCRIPT_IDENTIFY escape
'

%PSIDENT_GDICENTRIC  = 0
%PSIDENT_PSCENTRIC   = 1

'
' Header structure for the input buffer to POSTSCRIPT_INJECTION escape
'

TYPE PSINJECTDATA
    DataBytes      AS DWORD ' number of raw data bytes (NOT including this header)
    InjectionPoint AS WORD  ' injection point
    PageNumber     AS WORD  ' page number to apply the injection

    ' Followed by raw data to be injected
END TYPE

'
' Constants for PSINJECTDATA.InjectionPoint field
'

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

'
' InjectionPoint for publisher mode PScript5 OEM plugin to
' generate DSC comment for included font resource
'
%PSINJECT_DLFONT                     = &Hdddddddd???

'
' Parameter for GET_PS_FEATURESETTING escape
'

%FEATURESETTING_NUP                = 0
%FEATURESETTING_OUTPUT             = 1
%FEATURESETTING_PSLEVEL            = 2
%FEATURESETTING_CUSTPAPER          = 3
%FEATURESETTING_MIRROR             = 4
%FEATURESETTING_NEGATIVE           = 5
%FEATURESETTING_PROTOCOL           = 6

#IF (%WIN32_WINNT >= %WIN32_WINNT_WINXP)
'
' The range of selectors between FEATURESETTING_PRIVATE_BEGIN and
' FEATURESETTING_PRIVATE_END is reserved by Microsoft for private use
'
%FEATURESETTING_PRIVATE_BEGIN = &H1000
%FEATURESETTING_PRIVATE_END   = &H1FFF
#ENDIF ' (%WIN32_WINNT >= %WIN32_WINNT_WINXP)

'
' Information about output options
'

TYPE PSFEATURE_OUTPUT
    bPageIndependent AS LONG
    bSetPageDevice   AS LONG
END TYPE

'
' Information about custom paper size
'

TYPE PSFEATURE_CUSTPAPER
    lOrientation  AS LONG
    lWidth        AS LONG
    lHeight       AS LONG
    lWidthOffset  AS LONG
    lHeightOffset AS LONG
END TYPE

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
%OBJ_PEN             = 1
%OBJ_BRUSH           = 2
%OBJ_DC              = 3
%OBJ_METADC          = 4
%OBJ_PAL             = 5
%OBJ_FONT            = 6
%OBJ_BITMAP          = 7
%OBJ_REGION          = 8
%OBJ_METAFILE        = 9
%OBJ_MEMDC           = 10
%OBJ_EXTPEN          = 11
%OBJ_ENHMETADC       = 12
%OBJ_ENHMETAFILE     = 13
%OBJ_COLORSPACE      = 14

%GDI_OBJ_LAST        = %OBJ_COLORSPACE

' xform stuff
%MWT_IDENTITY      = 1
%MWT_LEFTMULTIPLY  = 2
%MWT_RIGHTMULTIPLY = 3

%MWT_MIN           = %MWT_IDENTITY
%MWT_MAX           = %MWT_RIGHTMULTIPLY

%XFORM = 1

TYPE XFORM
    eM11 AS SINGLE
    eM12 AS SINGLE
    eM21 AS SINGLE
    eM22 AS SINGLE
    eDx  AS SINGLE
    eDy  AS SINGLE
END TYPE


' Bitmap Header Definition
TYPE BITMAP
    bmType       AS LONG
    bmWidth      AS LONG
    bmHeight     AS LONG
    bmWidthBytes AS LONG
    bmPlanes     AS WORD
    bmBitsPixel  AS WORD
    bmBits       AS DWORD  ' LPVOID
END TYPE

TYPE RGBTRIPLE BYTE
    rgbtBlue  AS BYTE
    rgbtGreen AS BYTE
    rgbtRed   AS BYTE
END TYPE

TYPE RGBQUAD
    rgbBlue     AS BYTE
    rgbGreen    AS BYTE
    rgbRed      AS BYTE
    rgbReserved AS BYTE
END TYPE


#IF (%WINVER >= &H0400)

' Image Color Matching color definitions

%CS_ENABLE                       = &H00000001
%CS_DISABLE                      = &H00000002
%CS_DELETE_TRANSFORM             = &H00000003

' Logcolorspace signature

%LCS_SIGNATURE = &H50534f43     ' "PSOC"
$LCS_SIGNATURE = "PSOC"

' Logcolorspace lcsType values

$LCS_sRGB                = "sRGB"
%LCS_sRGB                = &H73524742  ' "sRGB"

$LCS_WINDOWS_COLOR_SPACE = "Win "  ' Windows default color space
%LCS_WINDOWS_COLOR_SPACE = &H57696e20  ' "Win "  ' Windows default color space

%LCS_CALIBRATED_RGB              = &H00000000

%LCS_GM_BUSINESS                 = &H00000001
%LCS_GM_GRAPHICS                 = &H00000002
%LCS_GM_IMAGES                   = &H00000004
%LCS_GM_ABS_COLORIMETRIC         = &H00000008

' ICM Defines for results from CheckColorInGamut()
%CM_OUT_OF_GAMUT               = 255
%CM_IN_GAMUT                   = 0

' UpdateICMRegKey Constants
%ICM_ADDPROFILE                = 1
%ICM_DELETEPROFILE             = 2
%ICM_QUERYPROFILE              = 3
%ICM_SETDEFAULTPROFILE         = 4
%ICM_REGISTERICMATCHER         = 5
%ICM_UNREGISTERICMATCHER       = 6
%ICM_QUERYMATCH                = 7

' Macros to retrieve CMYK values from a COLORREF

MACRO GetKValue(dwCMYK)=LO(BYTE,dwCMYK)
MACRO GetYValue(dwCMYK)=HI(BYTE,LO(WORD,dwCMYK))
MACRO GetMValue(dwCMYK)=LO(BYTE,HI(WORD,dwCMYK))
MACRO GetCValue(dwCMYK)=HI(BYTE,HI(WORD,dwCMYK))
MACRO CMYK(c,m,y,k)=(LO(BYTE,k) OR LO(BYTE,y)*256 OR LO(BYTE,m)*65536 OR LO(BYTE,c)*65536*256)

MACRO FXPT16DOT16=LONG
MACRO FXPT2DOT30=LONG

' ICM Color Definitions
' The following two structures are used for defining RGB's in terms of CIEXYZ.

TYPE CIEXYZ
    ciexyzX AS FXPT2DOT30
    ciexyzY AS FXPT2DOT30
    ciexyzZ AS FXPT2DOT30
END TYPE

TYPE CIEXYZTRIPLE
    ciexyzRed   AS CIEXYZ
    ciexyzGreen AS CIEXYZ
    ciexyBlue   AS CIEXYZ
END TYPE

' The next structures the logical color space. Unlike pens and brushes,
' but like palettes, there is only one way to create a LogColorSpace.
' A pointer to it must be passed, its elements can't be pushed as
' arguments.

TYPE LOGCOLORSPACEA
    lcsSignature  AS DWORD
    lcsVersion    AS DWORD
    lcsSize       AS DWORD
    lcsCSType     AS LONG
    lcsIntent     AS LONG
    lcsEndPoints  AS CIEXYZTRIPLE
    lcsGammaRed   AS DWORD
    lcsGammaGreen AS DWORD
    lcsGammaBlue  AS DWORD
    lcsFileName   AS ASCIIZ * %MAX_PATH
END TYPE

TYPE LOGCOLORSPACEW
    lcsSignature  AS DWORD
    lcsVersion    AS DWORD
    lcsSize       AS DWORD
    lcsCSType     AS LONG
    lcsIntent     AS LONG
    lcsEndPoints  AS CIEXYZTRIPLE
    lcsGammaRed   AS DWORD
    lcsGammaGreen AS DWORD
    lcsGammaBlue  AS DWORD
    lcsFileName   AS WSTRINGZ * %MAX_PATH
END TYPE

#IF %DEF(%UNICODE)
TYPE LOGCOLORSPACE
    LOGCOLORSPACEW
END TYPE
#ELSE
TYPE LOGCOLORSPACE
    LOGCOLORSPACEA
END TYPE
#ENDIF ' UNICODE

#ENDIF ' WINVER >= &H0400

' structures for defining DIBs

TYPE BITMAPCOREHEADER
    bcSize     AS DWORD            ' used to get to color table
    bcWidth    AS WORD
    bcHeight   AS WORD
    bcPlanes   AS WORD
    bcBitCount AS WORD
END TYPE

TYPE BITMAPINFOHEADER
    biSize          AS DWORD
    biWidth         AS LONG
    biHeight        AS LONG
    biPlanes        AS WORD
    biBitCount      AS WORD
    biCompression   AS DWORD
    biSizeImage     AS DWORD
    biXPelsPerMeter AS LONG
    biYPelsPerMeter AS LONG
    biClrUsed       AS DWORD
    biClrImportant  AS DWORD
END TYPE

#IF (%WINVER >= &H0400)

TYPE BITMAPV4HEADER
    bV4Size          AS DWORD
    bV4Width         AS LONG
    bV4Height        AS LONG
    bV4Planes        AS WORD
    bV4BitCount      AS WORD
    bV4Compression   AS DWORD
    bV4SizeImage     AS DWORD
    bV4XPelsPerMeter AS LONG
    bV4YPelsPerMeter AS LONG
    bV4ClrUsed       AS DWORD
    bV4ClrImportant  AS DWORD
    bV4RedMask       AS DWORD
    bV4GreenMask     AS DWORD
    bV4BlueMask      AS DWORD
    bV4AlphaMask     AS DWORD
    bV4CSType        AS DWORD
    bV4Endpoints     AS CIEXYZTRIPLE
    bV4GammaRed      AS DWORD
    bV4GammaGreen    AS DWORD
    bV4GammaBlue     AS DWORD
END TYPE  ' BITMAPV4HEADER

#ENDIF ' WINVER >= &H0400

#IF (%WINVER >= &H0500)

TYPE BITMAPV5HEADER
    bV5Size          AS DWORD
    bV5Width         AS LONG
    bV5Height        AS LONG
    bV5Planes        AS WORD
    bV5BitCount      AS WORD
    bV5Compression   AS DWORD
    bV5SizeImage     AS DWORD
    bV5XPelsPerMeter AS LONG
    bV5YPelsPerMeter AS LONG
    bV5ClrUsed       AS DWORD
    bV5ClrImportant  AS DWORD
    bV5RedMask       AS DWORD
    bV5GreenMask     AS DWORD
    bV5BlueMask      AS DWORD
    bV5AlphaMask     AS DWORD
    bV5CSType        AS DWORD
    bV5Endpoints     AS CIEXYZTRIPLE
    bV5GammaRed      AS DWORD
    bV5GammaGreen    AS DWORD
    bV5GammaBlue     AS DWORD
    bV5Intent        AS DWORD
    bV5ProfileData   AS DWORD
    bV5ProfileSize   AS DWORD
    bV5Reserved      AS DWORD
END TYPE  ' BITMAPV5HEADER

' Values for bV5CSType

$PROFILE_LINKED   = "LINK"
%PROFILE_LINKED   = &H4c494e4b  ' "LINK"

$PROFILE_EMBEDDED = "MBED"
%PROFILE_EMBEDDED = &H4d424544  ' "MBED"

#ENDIF ' #IF (%WINVER >= &H0500)

' constants for the biCompression field
%BI_RGB       = 0
%BI_RLE8      = 1
%BI_RLE4      = 2
%BI_BITFIELDS = 3
%BI_JPEG      = 4
%BI_PNG       = 5

TYPE BITMAPINFO
    bmiHeader AS BITMAPINFOHEADER
    bmiColors(0) AS RGBQUAD
END TYPE

TYPE BITMAPCOREINFO
    bmciHeader AS BITMAPCOREHEADER
    bmciColors(0) AS RGBTRIPLE
END TYPE

TYPE BITMAPFILEHEADER WORD FILL
    bfType      AS WORD
    bfSize      AS DWORD
    bfReserved1 AS WORD
    bfReserved2 AS WORD
    bfOffBits   AS DWORD
END TYPE

#IF (%WINVER >= &H0400)
#IF NOT %DEF(%NOFONTSIG)

TYPE FONTSIGNATURE
    fsUsb(3) AS DWORD
    fsCsb(1) AS DWORD
END TYPE

TYPE CHARSETINFO
    ciCharset AS DWORD
    ciACP     AS DWORD
    fs        AS FONTSIGNATURE
END TYPE

%TCI_SRCCHARSET  = 1
%TCI_SRCCODEPAGE = 2
%TCI_SRCFONTSIG  = 3

#IF (%WIN32_WINNT >= %WIN32_WINNT_WINXP)
%TCI_SRCLOCALE  = &H1000
#ENDIF ' (%WIN32_WINNT >= %WIN32_WINNT_WINXP)

TYPE LOCALESIGNATURE
    lsUsb(3)          AS DWORD
    lsCsbDefault(1)   AS DWORD
    lsCsbSupported(1) AS DWORD
END TYPE

#ENDIF ' #IF NOT %DEF(%NOFONTSIG)
#ENDIF ' %WINVER >= &H0400

#IF NOT %DEF(%NOMETAFILE)

' Clipboard Metafile Picture Structure
TYPE HANDLETABLE
    objectHandle(0) AS LONG
END TYPE

TYPE METARECORD
    rdSize     AS DWORD
    rdFunction AS WORD
    rdParm(0)  AS WORD
END TYPE

TYPE METAFILEPICT
    mm   AS LONG
    xExt AS LONG
    yExt AS LONG
    hMF  AS DWORD
END TYPE

TYPE METAHEADER WORD FILL
    mtType         AS WORD
    mtHeaderSize   AS WORD
    mtVersion      AS WORD
    mtSize         AS DWORD
    mtNoObjects    AS WORD
    mtMaxRecord    AS DWORD
    mtNoParameters AS WORD
END TYPE

' Enhanced Metafile structures
TYPE ENHMETARECORD
    iType    AS DWORD   ' Record type EMR_XXX
    nSize    AS DWORD   ' Record size in bytes
    dParm(0) AS DWORD   ' Parameters (variable-size array)
END TYPE

TYPE ENHMETAHEADER
    iType          AS DWORD  ' Record type EMR_HEADER
    nSize          AS DWORD  ' Record size in bytes. This may be greater
                             ' than the sizeof(ENHMETAHEADER).
    rclBounds      AS RECTL  ' Inclusive-inclusive bounds in device units
    rclFrame       AS RECTL  ' Inclusive-inclusive Picture Frame of metafile in .01 mm units
    dSignature     AS DWORD  ' Signature. Must be ENHMETA_SIGNATURE.
    nVersion       AS DWORD  ' Version number
    nBytes         AS DWORD  ' Size of the metafile in bytes
    nRecords       AS DWORD  ' Number of records in the metafile
    nHandles       AS WORD   ' Number of handles in the handle table
                             ' Handle index zero is reserved.
    sReserved      AS WORD   ' Reserved. Must be zero.
    nDescription   AS DWORD  ' Number of chars in the unicode description string
                             ' This is 0 if there is no description string
    offDescription AS DWORD  ' Offset to the metafile description record.
                             ' This is 0 if there is no description string
    nPalEntries    AS DWORD  ' Number of entries in the metafile palette.
    szlDevice      AS SIZEL  ' Size of the reference device in pels
    szlMillimeters AS SIZEL  ' Size of the reference device in millimeters
#IF (%WINVER >= &H0400)
    cbPixelFormat  AS DWORD  ' Size of PIXELFORMATDESCRIPTOR information
                             ' This is 0 if no pixel format is set
    offPixelFormat AS DWORD  ' Offset to PIXELFORMATDESCRIPTOR
                             ' This is 0 if no pixel format is set
    bOpenGL        AS DWORD  ' TRUE if OpenGL commands are present in
                             ' the metafile, otherwise FALSE
#ENDIF ' WINVER >= &H0400
#IF (%WINVER >= &H0500)
    szlMicrometers AS SIZEL   ' Size of the reference device in micrometers
#ENDIF ' WINVER >= &H0500
END TYPE  ' ENHMETAHEADER

#ENDIF ' NOMETAFILE

#IF NOT %DEF(%NOTEXTMETRIC)

' tmPitchAndFamily flags
%TMPF_FIXED_PITCH  = &H01
%TMPF_VECTOR       = &H02
%TMPF_DEVICE       = &H08
%TMPF_TRUETYPE     = &H04

#IF NOT %DEF(%TEXTMETRIC_DEFINED)
%TEXTMETRIC_DEFINED = 1

TYPE TEXTMETRICA DWORD FILL
    tmHeight           AS LONG
    tmAscent           AS LONG
    tmDescent          AS LONG
    tmInternalLeading  AS LONG
    tmExternalLeading  AS LONG
    tmAveCharWidth     AS LONG
    tmMaxCharWidth     AS LONG
    tmWeight           AS LONG
    tmOverhang         AS LONG
    tmDigitizedAspectX AS LONG
    tmDigitizedAspectY AS LONG
    tmFirstChar        AS STRING * 1
    tmLastChar         AS STRING * 1
    tmDefaultChar      AS STRING * 1
    tmBreakChar        AS STRING * 1
    tmItalic           AS BYTE
    tmUnderlined       AS BYTE
    tmStruckOut        AS BYTE
    tmPitchAndFamily   AS BYTE
    tmCharSet          AS BYTE
END TYPE

TYPE TEXTMETRICW DWORD FILL
    tmHeight           AS LONG
    tmAscent           AS LONG
    tmDescent          AS LONG
    tmInternalLeading  AS LONG
    tmExternalLeading  AS LONG
    tmAveCharWidth     AS LONG
    tmMaxCharWidth     AS LONG
    tmWeight           AS LONG
    tmOverhang         AS LONG
    tmDigitizedAspectX AS LONG
    tmDigitizedAspectY AS LONG
    tmFirstChar        AS WSTRING * 1
    tmLastChar         AS WSTRING * 1
    tmDefaultChar      AS WSTRING * 1
    tmBreakChar        AS WSTRING * 1
    tmItalic           AS BYTE
    tmUnderlined       AS BYTE
    tmStruckOut        AS BYTE
    tmPitchAndFamily   AS BYTE
    tmCharSet          AS BYTE
END TYPE

#IF %DEF(%UNICODE)
TYPE TEXTMETRIC
    TEXTMETRICW
END TYPE
#ELSE
TYPE TEXTMETRIC
    TEXTMETRICA
END TYPE
#ENDIF ' UNICODE

#ENDIF ' NOT %TEXTMETRIC_DEFINED

' ntmFlags field flags
%NTM_REGULAR        = &H00000040&
%NTM_BOLD           = &H00000020&
%NTM_ITALIC         = &H00000001&

' new in NT 5.0

%NTM_NONNEGATIVE_AC = &H00010000
%NTM_OPENTYPE       = &H00020000
%NTM_MULTIPLEMASTER = &H00040000
%NTM_MM_INSTANCE    = &H00080000
%NTM_TYPE1          = &H00100000
%NTM_DSIG           = &H00200000


TYPE NEWTEXTMETRICA DWORD FILL
    tmHeight           AS LONG
    tmAscent           AS LONG
    tmDescent          AS LONG
    tmInternalLeading  AS LONG
    tmExternalLeading  AS LONG
    tmAveCharWidth     AS LONG
    tmMaxCharWidth     AS LONG
    tmWeight           AS LONG
    tmOverhang         AS LONG
    tmDigitizedAspectX AS LONG
    tmDigitizedAspectY AS LONG
    tmFirstChar        AS STRING * 1
    tmLastChar         AS STRING * 1
    tmDefaultChar      AS STRING * 1
    tmBreakChar        AS STRING * 1
    tmItalic           AS BYTE
    tmUnderlined       AS BYTE
    tmStruckOut        AS BYTE
    tmPitchAndFamily   AS BYTE
    tmCharSet          AS BYTE
    ntmFlags           AS DWORD
    ntmSizeEM          AS DWORD
    ntmCellHeight      AS DWORD
    ntmAveWidth        AS DWORD
END TYPE

TYPE NEWTEXTMETRICW DWORD FILL
    tmHeight           AS LONG
    tmAscent           AS LONG
    tmDescent          AS LONG
    tmInternalLeading  AS LONG
    tmExternalLeading  AS LONG
    tmAveCharWidth     AS LONG
    tmMaxCharWidth     AS LONG
    tmWeight           AS LONG
    tmOverhang         AS LONG
    tmDigitizedAspectX AS LONG
    tmDigitizedAspectY AS LONG
    tmFirstChar        AS WSTRING * 1
    tmLastChar         AS WSTRING * 1
    tmDefaultChar      AS WSTRING * 1
    tmBreakChar        AS WSTRING * 1
    tmItalic           AS BYTE
    tmUnderlined       AS BYTE
    tmStruckOut        AS BYTE
    tmPitchAndFamily   AS BYTE
    tmCharSet          AS BYTE
    ntmFlags           AS DWORD
    ntmSizeEM          AS DWORD
    ntmCellHeight      AS DWORD
    ntmAveWidth        AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE NEWTEXTMETRIC
    NEWTEXTMETRICW
END TYPE
#ELSE
TYPE NEWTEXTMETRIC
    NEWTEXTMETRICA
END TYPE
#ENDIF ' UNICODE

#IF (%WINVER >= &H0400)

TYPE NEWTEXTMETRICEXA
    ntmTm      AS NEWTEXTMETRICA
    ntmFontSig AS FONTSIGNATURE
END TYPE

TYPE NEWTEXTMETRICEXW
    ntmTm      AS NEWTEXTMETRICW
    ntmFontSig AS FONTSIGNATURE
END TYPE

#IF %DEF(%UNICODE)
TYPE NEWTEXTMETRICEX
    NEWTEXTMETRICEXW
END TYPE
#ELSE
TYPE NEWTEXTMETRICEX
    NEWTEXTMETRICEXA
END TYPE
#ENDIF ' %UNICODE

#ENDIF ' %WINVER >= &H0400

#ENDIF ' %NOTEXTMETRIC
' GDI Logical Objects:

' Pel Array
TYPE PELARRAY
    paXCount AS LONG
    paYCount AS LONG
    paXExt   AS LONG
    paYExt   AS LONG
    paRGBs   AS BYTE
END TYPE

' Logical Brush (or Pattern)
TYPE LOGBRUSH
    lbStyle AS DWORD
    lbColor AS COLORREF
    lbHatch AS DWORD    ' ULONG_PTR
END TYPE

TYPE LOGBRUSH32
    lbStyle AS DWORD
    lbColor AS COLORREF
    lbHatch AS DWORD
END TYPE

TYPE PATTERN
    LOGBRUSH
END TYPE

' Logical Pen
TYPE LOGPEN
    lopnStyle AS DWORD
    lopnWidth AS POINT
    lopnColor AS COLORREF
END TYPE

TYPE EXTLOGPEN
    elpPenStyle   AS DWORD
    elpWidth      AS DWORD
    elpBrushStyle AS DWORD
    elpColor      AS COLORREF
    elpHatch      AS DWORD    ' ULONG_PTR
    elpNumEntries AS DWORD
    elpStyleEntry(0) AS DWORD
END TYPE

TYPE EXTLOGPEN32
    elpPenStyle      AS DWORD
    elpWidth         AS DWORD
    elpBrushStyle    AS DWORD
    elpColor         AS COLORREF
    elpHatch         AS DWORD
    elpNumEntries    AS DWORD
    elpStyleEntry(0) AS DWORD
END TYPE

#IF NOT %DEF(%PALETTEENTRY_DEFINED)

%PALETTEENTRY_DEFINED = 1

TYPE PALETTEENTRY
    peRed   AS BYTE
    peGreen AS BYTE
    peBlue  AS BYTE
    peFlags AS BYTE
END TYPE

#ENDIF ' NOT %PALETTEENTRY_DEFINED

#IF NOT %DEF(%LOGPALETTE_DEFINED)

%LOGPALETTE_DEFINED = 1

' Logical Palette
TYPE LOGPALETTE
    palVersion    AS WORD
    palNumEntries AS WORD
    palPalEntry(0) AS PALETTEENTRY
END TYPE

#ENDIF ' NOT %LOGPALETTE_DEFINED


' Logical Font
%LF_FACESIZE = 32

TYPE LOGFONTA
    lfHeight         AS LONG
    lfWidth          AS LONG
    lfEscapement     AS LONG
    lfOrientation    AS LONG
    lfWeight         AS LONG
    lfItalic         AS BYTE
    lfUnderline      AS BYTE
    lfStrikeOut      AS BYTE
    lfCharSet        AS BYTE
    lfOutPrecision   AS BYTE
    lfClipPrecision  AS BYTE
    lfQuality        AS BYTE
    lfPitchAndFamily AS BYTE
    lfFaceName       AS ASCIIZ * %LF_FACESIZE
END TYPE

TYPE LOGFONTW
    lfHeight         AS LONG
    lfWidth          AS LONG
    lfEscapement     AS LONG
    lfOrientation    AS LONG
    lfWeight         AS LONG
    lfItalic         AS BYTE
    lfUnderline      AS BYTE
    lfStrikeOut      AS BYTE
    lfCharSet        AS BYTE
    lfOutPrecision   AS BYTE
    lfClipPrecision  AS BYTE
    lfQuality        AS BYTE
    lfPitchAndFamily AS BYTE
    lfFaceName       AS WSTRINGZ * %LF_FACESIZE
END TYPE

#IF %DEF(%UNICODE)
TYPE LOGFONT
    LOGFONTW
END TYPE
#ELSE
TYPE LOGFONT
    LOGFONTA
END TYPE
#ENDIF ' UNICODE

%LF_FULLFACESIZE = 64

' Structure passed to FONTENUMPROC
TYPE ENUMLOGFONTA
    elfLogFont  AS LOGFONTA
    elfFullName AS ASCIIZ * %LF_FULLFACESIZE
    elfStyle    AS ASCIIZ * %LF_FACESIZE
END TYPE

TYPE ENUMLOGFONTW
    elfLogFont  AS LOGFONTW
    elfFullName AS WSTRINGZ * %LF_FULLFACESIZE
    elfStyle    AS WSTRINGZ * %LF_FACESIZE
END TYPE

#IF %DEF(%UNICODE)
TYPE ENUMLOGFONT
    ENUMLOGFONTW
END TYPE
#ELSE
TYPE ENUMLOGFONT
    ENUMLOGFONTA
END TYPE
#ENDIF ' UNICODE

#IF (%WINVER >= &H0400)

TYPE ENUMLOGFONTEXA
    elfLogFont  AS LOGFONTA
    elfFullName AS ASCIIZ * %LF_FULLFACESIZE
    elfStyle    AS ASCIIZ * %LF_FACESIZE
    elfScript   AS ASCIIZ * %LF_FACESIZE
END TYPE

TYPE ENUMLOGFONTEXW
    elfLogFont  AS LOGFONTW
    elfFullName AS WSTRINGZ * %LF_FULLFACESIZE
    elfStyle    AS WSTRINGZ * %LF_FACESIZE
    elfScript   AS WSTRINGZ * %LF_FACESIZE
END TYPE

#IF %DEF(%UNICODE)
TYPE ENUMLOGFONTEX
    ENUMLOGFONTEXW
END TYPE
#ELSE
TYPE ENUMLOGFONTEX
    ENUMLOGFONTEXA
END TYPE
#ENDIF ' UNICODE

#ENDIF ' WINVER >= &H0400

%OUT_DEFAULT_PRECIS        = 0
%OUT_STRING_PRECIS         = 1
%OUT_CHARACTER_PRECIS      = 2
%OUT_STROKE_PRECIS         = 3
%OUT_TT_PRECIS             = 4
%OUT_DEVICE_PRECIS         = 5
%OUT_RASTER_PRECIS         = 6
%OUT_TT_ONLY_PRECIS        = 7
%OUT_OUTLINE_PRECIS        = 8
%OUT_SCREEN_OUTLINE_PRECIS = 9
%OUT_PS_ONLY_PRECIS        = 10

%CLIP_DEFAULT_PRECIS   = 0
%CLIP_CHARACTER_PRECIS = 1
%CLIP_STROKE_PRECIS    = 2
%CLIP_MASK             = &Hf
%CLIP_LH_ANGLES        = 1 * &B10000
%CLIP_TT_ALWAYS        = 2 * &B10000
#IF (%WIN32_WINNT >= %WIN32_WINNT_LONGHORN)
%CLIP_DFA_DISABLE      = 4 * &B10000
#ENDIF ' (%WIN32_WINNT >= %WIN32_WINNT_LONGHORN)
%CLIP_EMBEDDED         = 8 * &B10000

%DEFAULT_QUALITY       = 0
%DRAFT_QUALITY         = 1
%PROOF_QUALITY         = 2
#IF (%WINVER >= &H0400)
%NONANTIALIASED_QUALITY= 3
%ANTIALIASED_QUALITY   = 4
#ENDIF ' %WINVER >= &H0400

#IF (%WIN32_WINNT >= %WIN32_WINNT_WINXP)
%CLEARTYPE_QUALITY     = 5
%CLEARTYPE_NATURAL_QUALITY = 6
#ENDIF

%DEFAULT_PITCH         = 0
%FIXED_PITCH           = 1
%VARIABLE_PITCH        = 2
#IF (%WINVER >= &H0400)
%MONO_FONT             = 8
#ENDIF ' %WINVER >= &H0400

%ANSI_CHARSET          = 0
%DEFAULT_CHARSET       = 1
%SYMBOL_CHARSET        = 2
%SHIFTJIS_CHARSET      = 128
%HANGEUL_CHARSET       = 129
%HANGUL_CHARSET        = 129
%GB2312_CHARSET        = 134
%CHINESEBIG5_CHARSET   = 136
%OEM_CHARSET           = 255
#IF (%WINVER >= &H0400)
%JOHAB_CHARSET         = 130
%HEBREW_CHARSET        = 177
%ARABIC_CHARSET        = 178
%GREEK_CHARSET         = 161
%TURKISH_CHARSET       = 162
%VIETNAMESE_CHARSET    = 163
%THAI_CHARSET          = 222
%EASTEUROPE_CHARSET    = 238
%RUSSIAN_CHARSET       = 204

%MAC_CHARSET           = 77
%BALTIC_CHARSET        = 186

%FS_LATIN1             = &H00000001
%FS_LATIN2             = &H00000002
%FS_CYRILLIC           = &H00000004
%FS_GREEK              = &H00000008
%FS_TURKISH            = &H00000010
%FS_HEBREW             = &H00000020
%FS_ARABIC             = &H00000040
%FS_BALTIC             = &H00000080
%FS_VIETNAMESE         = &H00000100
%FS_THAI               = &H00010000
%FS_JISJAPAN           = &H00020000
%FS_CHINESESIMP        = &H00040000
%FS_WANSUNG            = &H00080000
%FS_CHINESETRAD        = &H00100000
%FS_JOHAB              = &H00200000
%FS_SYMBOL             = &H80000000???
#ENDIF ' WINVER >= &H0400

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
%FW_DONTCARE       = 0
%FW_THIN           = 100
%FW_EXTRALIGHT     = 200
%FW_LIGHT          = 300
%FW_NORMAL         = 400
%FW_MEDIUM         = 500
%FW_SEMIBOLD       = 600
%FW_BOLD           = 700
%FW_EXTRABOLD      = 800
%FW_HEAVY          = 900

%FW_ULTRALIGHT     = %FW_EXTRALIGHT
%FW_REGULAR        = %FW_NORMAL
%FW_DEMIBOLD       = %FW_SEMIBOLD
%FW_ULTRABOLD      = %FW_EXTRABOLD
%FW_BLACK          = %FW_HEAVY

%PANOSE_COUNT              =10
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

TYPE PANOSE
    bFamilyType      AS BYTE
    bSerifStyle      AS BYTE
    bWeight          AS BYTE
    bProportion      AS BYTE
    bContrast        AS BYTE
    bStrokeVariation AS BYTE
    bArmStyle        AS BYTE
    bLetterform      AS BYTE
    bMidline         AS BYTE
    bXHeight         AS BYTE
END TYPE

%PAN_ANY                      =   0 ' Any
%PAN_NO_FIT                   =   1 ' No Fit

%PAN_FAMILY_TEXT_DISPLAY      =   2 ' Text and Display
%PAN_FAMILY_SCRIPT            =   3 ' Script
%PAN_FAMILY_DECORATIVE        =   4 ' Decorative
%PAN_FAMILY_PICTORIAL         =   5 ' Pictorial

%PAN_SERIF_COVE               =   2 ' Cove
%PAN_SERIF_OBTUSE_COVE        =   3 ' Obtuse Cove
%PAN_SERIF_SQUARE_COVE        =   4 ' Square Cove
%PAN_SERIF_OBTUSE_SQUARE_COVE =   5 ' Obtuse Square Cove
%PAN_SERIF_SQUARE             =   6 ' Square
%PAN_SERIF_THIN               =   7 ' Thin
%PAN_SERIF_BONE               =   8 ' Bone
%PAN_SERIF_EXAGGERATED        =   9 ' Exaggerated
%PAN_SERIF_TRIANGLE           =  10 ' Triangle
%PAN_SERIF_NORMAL_SANS        =  11 ' Normal Sans
%PAN_SERIF_OBTUSE_SANS        =  12 ' Obtuse Sans
%PAN_SERIF_PERP_SANS          =  13 ' Prep Sans
%PAN_SERIF_FLARED             =  14 ' Flared
%PAN_SERIF_ROUNDED            =  15 ' Rounded

%PAN_WEIGHT_VERY_LIGHT        =   2 ' Very Light
%PAN_WEIGHT_LIGHT             =   3 ' Light
%PAN_WEIGHT_THIN              =   4 ' Thin
%PAN_WEIGHT_BOOK              =   5 ' Book
%PAN_WEIGHT_MEDIUM            =   6 ' Medium
%PAN_WEIGHT_DEMI              =   7 ' Demi
%PAN_WEIGHT_BOLD              =   8 ' Bold
%PAN_WEIGHT_HEAVY             =   9 ' Heavy
%PAN_WEIGHT_BLACK             =  10 ' Black
%PAN_WEIGHT_NORD              =  11 ' Nord

%PAN_PROP_OLD_STYLE           =   2 ' Old Style
%PAN_PROP_MODERN              =   3 ' Modern
%PAN_PROP_EVEN_WIDTH          =   4 ' Even Width
%PAN_PROP_EXPANDED            =   5 ' Expanded
%PAN_PROP_CONDENSED           =   6 ' Condensed
%PAN_PROP_VERY_EXPANDED       =   7 ' Very Expanded
%PAN_PROP_VERY_CONDENSED      =   8 ' Very Condensed
%PAN_PROP_MONOSPACED          =   9 ' Monospaced

%PAN_CONTRAST_NONE            =   2 ' None
%PAN_CONTRAST_VERY_LOW        =   3 ' Very Low
%PAN_CONTRAST_LOW             =   4 ' Low
%PAN_CONTRAST_MEDIUM_LOW      =   5 ' Medium Low
%PAN_CONTRAST_MEDIUM          =   6 ' Medium
%PAN_CONTRAST_MEDIUM_HIGH     =   7 ' Mediim High
%PAN_CONTRAST_HIGH            =   8 ' High
%PAN_CONTRAST_VERY_HIGH       =   9 ' Very High

%PAN_STROKE_GRADUAL_DIAG      =   2 ' Gradual/Diagonal
%PAN_STROKE_GRADUAL_TRAN      =   3 ' Gradual/Transitional
%PAN_STROKE_GRADUAL_VERT      =   4 ' Gradual/Vertical
%PAN_STROKE_GRADUAL_HORZ      =   5 ' Gradual/Horizontal
%PAN_STROKE_RAPID_VERT        =   6 ' Rapid/Vertical
%PAN_STROKE_RAPID_HORZ        =   7 ' Rapid/Horizontal
%PAN_STROKE_INSTANT_VERT      =   8 ' Instant/Vertical

%PAN_STRAIGHT_ARMS_HORZ        =  2 ' Straight Arms/Horizontal
%PAN_STRAIGHT_ARMS_WEDGE       =  3 ' Straight Arms/Wedge
%PAN_STRAIGHT_ARMS_VERT        =  4 ' Straight Arms/Vertical
%PAN_STRAIGHT_ARMS_SINGLE_SERIF=  5 ' Straight Arms/Single-Serif
%PAN_STRAIGHT_ARMS_DOUBLE_SERIF=  6 ' Straight Arms/Double-Serif
%PAN_BENT_ARMS_HORZ            =  7 ' Non-Straight Arms/Horizontal
%PAN_BENT_ARMS_WEDGE           =  8 ' Non-Straight Arms/Wedge
%PAN_BENT_ARMS_VERT            =  9 ' Non-Straight Arms/Vertical
%PAN_BENT_ARMS_SINGLE_SERIF    = 10 ' Non-Straight Arms/Single-Serif
%PAN_BENT_ARMS_DOUBLE_SERIF    = 11 ' Non-Straight Arms/Double-Serif

%PAN_LETT_NORMAL_CONTACT      =   2 ' Normal/Contact
%PAN_LETT_NORMAL_WEIGHTED     =   3 ' Normal/Weighted
%PAN_LETT_NORMAL_BOXED        =   4 ' Normal/Boxed
%PAN_LETT_NORMAL_FLATTENED    =   5 ' Normal/Flattened
%PAN_LETT_NORMAL_ROUNDED      =   6 ' Normal/Rounded
%PAN_LETT_NORMAL_OFF_CENTER   =   7 ' Normal/Off Center
%PAN_LETT_NORMAL_SQUARE       =   8 ' Normal/Square
%PAN_LETT_OBLIQUE_CONTACT     =   9 ' Oblique/Contact
%PAN_LETT_OBLIQUE_WEIGHTED    =  10 ' Oblique/Weighted
%PAN_LETT_OBLIQUE_BOXED       =  11 ' Oblique/Boxed
%PAN_LETT_OBLIQUE_FLATTENED   =  12 ' Oblique/Flattened
%PAN_LETT_OBLIQUE_ROUNDED     =  13 ' Oblique/Rounded
%PAN_LETT_OBLIQUE_OFF_CENTER  =  14 ' Oblique/Off Center
%PAN_LETT_OBLIQUE_SQUARE      =  15 ' Oblique/Square

%PAN_MIDLINE_STANDARD_TRIMMED  =  2 ' Standard/Trimmed
%PAN_MIDLINE_STANDARD_POINTED  =  3 ' Standard/Pointed
%PAN_MIDLINE_STANDARD_SERIFED  =  4 ' Standard/Serifed
%PAN_MIDLINE_HIGH_TRIMMED      =  5 ' High/Trimmed
%PAN_MIDLINE_HIGH_POINTED      =  6 ' High/Pointed
%PAN_MIDLINE_HIGH_SERIFED      =  7 ' High/Serifed
%PAN_MIDLINE_CONSTANT_TRIMMED  =  8 ' Constant/Trimmed
%PAN_MIDLINE_CONSTANT_POINTED  =  9 ' Constant/Pointed
%PAN_MIDLINE_CONSTANT_SERIFED  = 10 ' Constant/Serifed
%PAN_MIDLINE_LOW_TRIMMED       = 11 ' Low/Trimmed
%PAN_MIDLINE_LOW_POINTED       = 12 ' Low/Pointed
%PAN_MIDLINE_LOW_SERIFED       = 13 ' Low/Serifed

%PAN_XHEIGHT_CONSTANT_SMALL    =  2 ' Constant/Small
%PAN_XHEIGHT_CONSTANT_STD      =  3 ' Constant/Standard
%PAN_XHEIGHT_CONSTANT_LARGE    =  4 ' Constant/Large
%PAN_XHEIGHT_DUCKING_SMALL     =  5 ' Ducking/Small
%PAN_XHEIGHT_DUCKING_STD       =  6 ' Ducking/Standard
%PAN_XHEIGHT_DUCKING_LARGE     =  7 ' Ducking/Large


%ELF_VENDOR_SIZE    = 4

' The extended logical font
' An extension of the ENUMLOGFONT

TYPE EXTLOGFONTA
    elfLogFont   AS LOGFONTA
    elfFullName  AS ASCIIZ * %LF_FULLFACESIZE
    elfStyle     AS ASCIIZ * %LF_FACESIZE
    elfVersion   AS DWORD      ' 0 for the first release of NT
    elfStyleSize AS DWORD
    elfMatch     AS DWORD
    elfReserved  AS DWORD
    elfVendorId  AS ASCIIZ * %ELF_VENDOR_SIZE
    elfCulture   AS DWORD
    elfPanose    AS PANOSE
END TYPE

TYPE EXTLOGFONTW
    elfLogFont   AS LOGFONTW
    elfFullName  AS WSTRINGZ * %LF_FULLFACESIZE
    elfStyle     AS WSTRINGZ * %LF_FACESIZE
    elfVersion   AS DWORD      ' 0 for the first release of NT
    elfStyleSize AS DWORD
    elfMatch     AS DWORD
    elfReserved  AS DWORD
    elfVendorId  AS WSTRINGZ * %ELF_VENDOR_SIZE
    elfCulture   AS DWORD
    elfPanose    AS PANOSE
END TYPE

#IF %DEF(%UNICODE)
TYPE EXTLOGFONT
    EXTLOGFONTW
END TYPE
#ELSE
TYPE EXTLOGFONT
    EXTLOGFONTW
END TYPE
#ENDIF ' UNICODE

%ELF_VERSION       = 0
%ELF_CULTURE_LATIN = 0

' EnumFonts Masks
%RASTER_FONTTYPE     = &H0001
%DEVICE_FONTTYPE     = &H0002
%TRUETYPE_FONTTYPE   = &H0004

MACRO PALETTERGB(r,g,b)=(&H02000000 OR RGB(r,g,b))
MACRO PALETTEINDEX(i)=(&H01000000 OR CDWD(i))

' palette entry flags

%PC_RESERVED     = &H01    ' palette index used for animation
%PC_EXPLICIT     = &H02    ' palette index is explicit to device
%PC_NOCOLLAPSE   = &H04    ' do not match color to system palette

MACRO GetRValue(nRGB)=LO(BYTE,nRGB)
MACRO GetGValue(nRGB)=LO(BYTE,(nRGB)\256)
MACRO GetBValue(nRGB)=LO(BYTE,(nRGB)\65536)

' Background Modes
%TRANSPARENT        = 1
%OPAQUE             = 2
%BKMODE_LAST        = 2

' Graphics Modes

%GM_COMPATIBLE      = 1
%GM_ADVANCED        = 2
%GM_LAST            = 2

' PolyDraw and GetPath point types
%PT_CLOSEFIGURE     = &H01
%PT_LINETO          = &H02
%PT_BEZIERTO        = &H04
%PT_MOVETO          = &H06

' Mapping Modes
%MM_TEXT            = 1
%MM_LOMETRIC        = 2
%MM_HIMETRIC        = 3
%MM_LOENGLISH       = 4
%MM_HIENGLISH       = 5
%MM_TWIPS           = 6
%MM_ISOTROPIC       = 7
%MM_ANISOTROPIC     = 8

' Min and Max Mapping Mode values
%MM_MIN             = %MM_TEXT
%MM_MAX             = %MM_ANISOTROPIC
%MM_MAX_FIXEDSCALE  = %MM_TWIPS

' Coordinate Modes
%ABSOLUTE           = 1
%RELATIVE           = 2

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

#IF (%WINVER >= &H0400)
%DEFAULT_GUI_FONT    = 17
#ENDIF ' WINVER >= &H0400

#IF (%WIN32_WINNT >= %WIN32_WINNT_WIN2K)
%DC_BRUSH            = 18
%DC_PEN              = 19
#ENDIF

#IF (%WIN32_WINNT >= %WIN32_WINNT_WIN2K)
%STOCK_LAST          = 19
#ELSEIF (%WINVER >= &H0400)
%STOCK_LAST          = 17
#ELSE
%STOCK_LAST          = 16
#ENDIF

%CLR_INVALID = &HFFFFFFFF???  ' some Microsoft docs claim this is &HFFFF, but it's not

' Brush Styles
%BS_SOLID          = 0
%BS_NULL           = 1
%BS_HOLLOW         = %BS_NULL
%BS_HATCHED        = 2
%BS_PATTERN        = 3
%BS_INDEXED        = 4
%BS_DIBPATTERN     = 5
%BS_DIBPATTERNPT   = 6
%BS_PATTERN8X8     = 7
%BS_DIBPATTERN8X8  = 8
%BS_MONOPATTERN    = 9

' Hatch Styles
%HS_HORIZONTAL     = 0       ' -----
%HS_VERTICAL       = 1       '  OR  OR |
%HS_FDIAGONAL      = 2       ' \\\\ _
%HS_BDIAGONAL      = 3       ' ''/
%HS_CROSS          = 4       ' +++++
%HS_DIAGCROSS      = 5       ' xxxxx
%HS_API_MAX        = 12

' Pen Styles
%PS_SOLID          = 0
%PS_DASH           = 1       ' -------
%PS_DOT            = 2       ' .......
%PS_DASHDOT        = 3       ' _._._._
%PS_DASHDOTDOT     = 4       ' _.._.._
%PS_NULL           = 5
%PS_INSIDEFRAME    = 6
%PS_USERSTYLE      = 7
%PS_ALTERNATE      = 8
%PS_STYLE_MASK     = &H0000000F

%PS_ENDCAP_ROUND   = &H00000000
%PS_ENDCAP_SQUARE  = &H00000100
%PS_ENDCAP_FLAT    = &H00000200
%PS_ENDCAP_MASK    = &H00000F00

%PS_JOIN_ROUND     = &H00000000
%PS_JOIN_BEVEL     = &H00001000
%PS_JOIN_MITER     = &H00002000
%PS_JOIN_MASK      = &H0000F000

%PS_COSMETIC       = &H00000000
%PS_GEOMETRIC      = &H00010000
%PS_TYPE_MASK      = &H000F0000

%AD_COUNTERCLOCKWISE = 1
%AD_CLOCKWISE        = 2

' Device Parameters for GetDeviceCaps()
%DRIVERVERSION = 0     ' Device driver version
%TECHNOLOGY    = 2     ' Device classification
%HORZSIZE      = 4     ' Horizontal size in millimeters
%VERTSIZE      = 6     ' Vertical size in millimeters
%HORZRES       = 8     ' Horizontal width in pixels
%VERTRES       = 10    ' Vertical height in pixels
%BITSPIXEL     = 12    ' Number of bits per pixel
%PLANES        = 14    ' Number of planes
%NUMBRUSHES    = 16    ' Number of brushes the device has
%NUMPENS       = 18    ' Number of pens the device has
%NUMMARKERS    = 20    ' Number of markers the device has
%NUMFONTS      = 22    ' Number of fonts the device has
%NUMCOLORS     = 24    ' Number of colors the device supports
%PDEVICESIZE   = 26    ' Size required for device descriptor
%CURVECAPS     = 28    ' Curve capabilities
%LINECAPS      = 30    ' Line capabilities
%POLYGONALCAPS = 32    ' Polygonal capabilities
%TEXTCAPS      = 34    ' Text capabilities
%CLIPCAPS      = 36    ' Clipping capabilities
%RASTERCAPS    = 38    ' Bitblt capabilities
%ASPECTX       = 40    ' Length of the X leg
%ASPECTY       = 42    ' Length of the Y leg
%ASPECTXY      = 44    ' Length of the hypotenuse

%LOGPIXELSX    = 88    ' Logical pixels/inch in X
%LOGPIXELSY    = 90    ' Logical pixels/inch in Y

%SIZEPALETTE  = 104    ' Number of entries in physical palette
%NUMRESERVED  = 106    ' Number of reserved entries in palette
%COLORRES     = 108    ' Actual color resolution

' Printing related DeviceCaps. These replace the appropriate Escapes

%PHYSICALWIDTH   = 110 ' Physical Width in device units
%PHYSICALHEIGHT  = 111 ' Physical Height in device units
%PHYSICALOFFSETX = 112 ' Physical Printable Area x margin
%PHYSICALOFFSETY = 113 ' Physical Printable Area y margin
%SCALINGFACTORX  = 114 ' Scaling factor x
%SCALINGFACTORY  = 115 ' Scaling factor y

' Display driver specific

%VREFRESH        = 116  ' Current vertical refresh rate of the
                        ' display device (for displays only) in Hz
%DESKTOPVERTRES  = 117  ' Horizontal width of entire desktop in
                        ' pixels
%DESKTOPHORZRES  = 118  ' Vertical height of entire desktop in
                        ' pixels
%BLTALIGNMENT    = 119  ' Preferred blt alignment

#IF (%WINVER >= &H0500)
%SHADEBLENDCAPS  = 120  ' Shading and blending caps
%COLORMGMTCAPS   = 121  ' Color Management caps
#ENDIF ' WINVER >= &H0500

#IF NOT %DEF(%NOGDICAPMASKS)

' Device Capability Masks:

' Device Technologies
%DT_PLOTTER        = 0   ' Vector plotter
%DT_RASDISPLAY     = 1   ' Raster display
%DT_RASPRINTER     = 2   ' Raster printer
%DT_RASCAMERA      = 3   ' Raster camera
%DT_CHARSTREAM     = 4   ' Character-stream, PLP
%DT_METAFILE       = 5   ' Metafile, VDM
%DT_DISPFILE       = 6   ' Display-file

' Curve Capabilities
%CC_NONE           = 0   ' Curves not supported
%CC_CIRCLES        = 1   ' Can do circles
%CC_PIE            = 2   ' Can do pie wedges
%CC_CHORD          = 4   ' Can do chord arcs
%CC_ELLIPSES       = 8   ' Can do ellipese
%CC_WIDE           = 16  ' Can do wide lines
%CC_STYLED         = 32  ' Can do styled lines
%CC_WIDESTYLED     = 64  ' Can do wide styled lines
%CC_INTERIORS      = 128 ' Can do interiors
%CC_ROUNDRECT      = 256 '

' Line Capabilities
%LC_NONE           = 0   ' Lines not supported
%LC_POLYLINE       = 2   ' Can do polylines
%LC_MARKER         = 4   ' Can do markers
%LC_POLYMARKER     = 8   ' Can do polymarkers
%LC_WIDE           = 16  ' Can do wide lines
%LC_STYLED         = 32  ' Can do styled lines
%LC_WIDESTYLED     = 64  ' Can do wide styled lines
%LC_INTERIORS      = 128 ' Can do interiors

' Polygonal Capabilities
%PC_NONE           = 0   ' Polygonals not supported
%PC_POLYGON        = 1   ' Can do polygons
%PC_RECTANGLE      = 2   ' Can do rectangles
%PC_WINDPOLYGON    = 4   ' Can do winding polygons
%PC_TRAPEZOID      = 4   ' Can do trapezoids
%PC_SCANLINE       = 8   ' Can do scanlines
%PC_WIDE           = 16  ' Can do wide borders
%PC_STYLED         = 32  ' Can do styled borders
%PC_WIDESTYLED     = 64  ' Can do wide styled borders
%PC_INTERIORS      = 128 ' Can do interiors
%PC_POLYPOLYGON    = 256 ' Can do polypolygons
%PC_PATHS          = 512 ' Can do paths

' Clipping Capabilities
%CP_NONE           = 0   ' No clipping of output
%CP_RECTANGLE      = 1   ' Output clipped to rects
%CP_REGION         = 2   ' obsolete

' Text Capabilities
%TC_OP_CHARACTER   = &H00000001  ' Can do OutputPrecision   CHARACTER
%TC_OP_STROKE      = &H00000002  ' Can do OutputPrecision   STROKE
%TC_CP_STROKE      = &H00000004  ' Can do ClipPrecision     STROKE
%TC_CR_90          = &H00000008  ' Can do CharRotAbility    90
%TC_CR_ANY         = &H00000010  ' Can do CharRotAbility    ANY
%TC_SF_X_YINDEP    = &H00000020  ' Can do ScaleFreedom      X_YINDEPENDENT
%TC_SA_DOUBLE      = &H00000040  ' Can do ScaleAbility      DOUBLE
%TC_SA_INTEGER     = &H00000080  ' Can do ScaleAbility      INTEGER
%TC_SA_CONTIN      = &H00000100  ' Can do ScaleAbility      CONTINUOUS
%TC_EA_DOUBLE      = &H00000200  ' Can do EmboldenAbility   DOUBLE
%TC_IA_ABLE        = &H00000400  ' Can do ItalisizeAbility  ABLE
%TC_UA_ABLE        = &H00000800  ' Can do UnderlineAbility  ABLE
%TC_SO_ABLE        = &H00001000  ' Can do StrikeOutAbility  ABLE
%TC_RA_ABLE        = &H00002000  ' Can do RasterFontAble    ABLE
%TC_VA_ABLE        = &H00004000  ' Can do VectorFontAble    ABLE
%TC_RESERVED       = &H00008000
%TC_SCROLLBLT      = &H00010000  ' Don't do text scroll with blt

#ENDIF ' NOGDICAPMASKS

' Raster Capabilities
%RC_NONE           = 0
%RC_BITBLT         = 1       ' Can do standard BLT.
%RC_BANDING        = 2       ' Device requires banding support
%RC_SCALING        = 4       ' Device requires scaling support
%RC_BITMAP64       = 8       ' Device can support >64K bitmap
%RC_GDI20_OUTPUT   = &H0010      ' has 2.0 output calls
%RC_GDI20_STATE    = &H0020
%RC_SAVEBITMAP     = &H0040
%RC_DI_BITMAP      = &H0080      ' supports DIB to memory
%RC_PALETTE        = &H0100      ' supports a palette
%RC_DIBTODEV       = &H0200      ' supports DIBitsToDevice
%RC_BIGFONT        = &H0400      ' supports >64K fonts
%RC_STRETCHBLT     = &H0800      ' supports StretchBlt
%RC_FLOODFILL      = &H1000      ' supports FloodFill
%RC_STRETCHDIB     = &H2000      ' supports StretchDIBits
%RC_OP_DX_OUTPUT   = &H4000
%RC_DEVBITS        = &H8000??

#IF (%WINVER >= &H0500)

' Shading and blending caps
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

#ENDIF ' WINVER >= &H0500


' DIB color table identifiers

%DIB_RGB_COLORS    = 0 ' color table in RGBs
%DIB_PAL_COLORS    = 1 ' color table in palette indices

' constants for Get/SetSystemPaletteUse()

%SYSPAL_ERROR       = 0
%SYSPAL_STATIC      = 1
%SYSPAL_NOSTATIC    = 2
%SYSPAL_NOSTATIC256 = 3

' constants for CreateDIBitmap
%CBM_INIT      = &H04    ' initialize bitmap

' ExtFloodFill style flags
%FLOODFILLBORDER  = 0
%FLOODFILLSURFACE = 1

' size of a device name string
%CCHDEVICENAME = 32

' size of a form name string
%CCHFORMNAME = 32

'#IF %WIN32_WINNT >= OSVER(%NTDDI_WINXPSP2) \ 65536
#IF %WIN32_WINNT >= (%NTDDI_WINXPSP2 AND &HFFFF0000???) \ 65536

' printer only fields
TYPE DEVMODE_type1
    dmOrientation   AS INTEGER
    dmPaperSize     AS INTEGER
    dmPaperLength   AS INTEGER
    dmPaperWidth    AS INTEGER
    dmScale         AS INTEGER
    dmCopies        AS INTEGER
    dmDefaultSource AS INTEGER
    dmPrintQuality  AS INTEGER
END TYPE

' display only fields
TYPE DEVMODE_type2
    dmPosition           AS POINTL
    dmDisplayOrientation AS DWORD
    dmDisplayFixedOutput AS DWORD
END TYPE

UNION DEVMODE_union1
    DEVMODE_type1
    DEVMODE_type2
END UNION

UNION DEVMODE_union2
    dmDisplayFlags AS DWORD
    dmNup          AS DWORD
END UNION

TYPE DEVMODEA
    dmDeviceName       AS ASCIIZ * %CCHDEVICENAME
    dmSpecVersion      AS WORD
    dmDriverVersion    AS WORD
    dmSize             AS WORD
    dmDriverExtra      AS WORD
    dmFields           AS DWORD
    DEVMODE_union1
    dmColor            AS INTEGER
    dmDuplex           AS INTEGER
    dmYResolution      AS INTEGER
    dmTTOption         AS INTEGER
    dmCollate          AS INTEGER
    dmFormName         AS ASCIIZ * %CCHFORMNAME
    dmLogPixels        AS WORD
    dmBitsPerPel       AS DWORD
    dmPelsWidth        AS DWORD
    dmPelsHeight       AS DWORD
    DEVMODE_union2
    dmDisplayFrequency AS DWORD
#IF (%WINVER >= &H0400)
    dmICMMethod        AS DWORD
    dmICMIntent        AS DWORD
    dmMediaType        AS DWORD
    dmDitherType       AS DWORD
    dmReserved1        AS DWORD
    dmReserved2        AS DWORD
#IF (%WINVER >= &H0500) OR (%WIN32_WINNT >= %WIN32_WINNT_NT4)
    dmPanningWidth     AS DWORD
    dmPanningHeight    AS DWORD
#ENDIF
#ENDIF ' WINVER >= &H0400
END TYPE

TYPE DEVMODEW
    dmDeviceName       AS WSTRINGZ * %CCHDEVICENAME
    dmSpecVersion      AS WORD
    dmDriverVersion    AS WORD
    dmSize             AS WORD
    dmDriverExtra      AS WORD
    dmFields           AS DWORD
    DEVMODE_union1
    dmColor            AS INTEGER
    dmDuplex           AS INTEGER
    dmYResolution      AS INTEGER
    dmTTOption         AS INTEGER
    dmCollate          AS INTEGER
    dmFormName         AS WSTRINGZ * %CCHFORMNAME
    dmLogPixels        AS WORD
    dmBitsPerPel       AS DWORD
    dmPelsWidth        AS DWORD
    dmPelsHeight       AS DWORD
    DEVMODE_union2
    dmDisplayFrequency AS DWORD
#IF (%WINVER >= &H0400)
    dmICMMethod        AS DWORD
    dmICMIntent        AS DWORD
    dmMediaType        AS DWORD
    dmDitherType       AS DWORD
    dmReserved1        AS DWORD
    dmReserved2        AS DWORD
#IF (%WINVER >= &H0500) OR (%WIN32_WINNT >= %WIN32_WINNT_NT4)
    dmPanningWidth     AS DWORD
    dmPanningHeight    AS DWORD
#ENDIF
#ENDIF ' WINVER >= &H0400
END TYPE

#IF %DEF(%UNICODE)
TYPE DEVMODE
    DEVMODEW
END TYPE
#ELSE
TYPE DEVMODE
    DEVMODEA
END TYPE
#ENDIF ' UNICODE

#ELSE

TYPE DEVMODE_type1
    dmOrientation AS INTEGER
    dmPaperSize   AS INTEGER
    dmPaperLength AS INTEGER
    dmPaperWidth  AS INTEGER
END TYPE

UNION DEVMODE_union1
    DEVMODE_type1
    dmPosition    AS POINTL
END UNION

UNION DEVMODE_union2
    dmDisplayFlags AS DWORD
    dmNup          AS DWORD
END UNION

TYPE DEVMODEA
    dmDeviceName       AS ASCIIZ * %CCHDEVICENAME
    dmSpecVersion      AS WORD
    dmDriverVersion    AS WORD
    dmSize             AS WORD
    dmDriverExtra      AS WORD
    dmFields           AS DWORD
    DEVMODE_union1
    dmScale            AS INTEGER
    dmCopies           AS INTEGER
    dmDefaultSource    AS INTEGER
    dmPrintQuality     AS INTEGER
    dmColor            AS INTEGER
    dmDuplex           AS INTEGER
    dmYResolution      AS INTEGER
    dmTTOption         AS INTEGER
    dmCollate          AS INTEGER
    dmFormName         AS ASCIIZ * %CCHFORMNAME
    dmLogPixels        AS WORD
    dmBitsPerPel       AS DWORD
    dmPelsWidth        AS DWORD
    dmPelsHeight       AS DWORD
    DEVMODE_union2
    dmDisplayFrequency AS DWORD
#IF (%WINVER >= &H0400)
    dmICMMethod        AS DWORD
    dmICMIntent        AS DWORD
    dmMediaType        AS DWORD
    dmDitherType       AS DWORD
    dmReserved1        AS DWORD
    dmReserved2        AS DWORD
#IF (%WINVER >= &H0500) OR (%WIN32_WINNT >= %WIN32_WINNT_NT4)
    dmPanningWidth     AS DWORD
    dmPanningHeight    AS DWORD
#ENDIF
#ENDIF ' WINVER >= &H0400
END TYPE

TYPE DEVMODEW
    dmDeviceName       AS WSTRINGZ * %CCHDEVICENAME
    dmSpecVersion      AS WORD
    dmDriverVersion    AS WORD
    dmSize             AS WORD
    dmDriverExtra      AS WORD
    dmFields           AS DWORD
    DEVMODE_union1
    dmScale            AS INTEGER
    dmCopies           AS INTEGER
    dmDefaultSource    AS INTEGER
    dmPrintQuality     AS INTEGER
    dmColor            AS INTEGER
    dmDuplex           AS INTEGER
    dmYResolution      AS INTEGER
    dmTTOption         AS INTEGER
    dmCollate          AS INTEGER
    dmFormName         AS WSTRINGZ * %CCHFORMNAME
    dmLogPixels        AS WORD
    dmBitsPerPel       AS DWORD
    dmPelsWidth        AS DWORD
    dmPelsHeight       AS DWORD
    DEVMODE_union2
    dmDisplayFrequency AS DWORD
#IF (%WINVER >= &H0400)
    dmICMMethod        AS DWORD
    dmICMIntent        AS DWORD
    dmMediaType        AS DWORD
    dmDitherType       AS DWORD
    dmReserved1        AS DWORD
    dmReserved2        AS DWORD
#IF (%WINVER >= &H0500) OR (%WIN32_WINNT >= %WIN32_WINNT_NT4)
    dmPanningWidth     AS DWORD
    dmPanningHeight    AS DWORD
#ENDIF
#ENDIF ' %WINVER >= &H0400
END TYPE

#IF %DEF(%UNICODE)
TYPE DEVMODE
    DEVMODEW
END TYPE
#ELSE
TYPE DEVMODE
    DEVMODEA
END TYPE
#ENDIF ' %UNICODE

#ENDIF ' (%WIN32_WINNT >= %WIN32_WINNT_WINXP)

' current version of specification
#IF (%WINVER >= &H0500) OR (%WIN32_WINNT >= %WIN32_WINNT_NT4)
%DM_SPECVERSION = &H0401
#ELSEIF (%WINVER >= &H0400)
%DM_SPECVERSION = &H0400
#ELSE
%DM_SPECVERSION = &H0320
#ENDIF ' %WINVER

' field selection bits
%DM_ORIENTATION        = &H00000001
%DM_PAPERSIZE          = &H00000002
%DM_PAPERLENGTH        = &H00000004
%DM_PAPERWIDTH         = &H00000008
%DM_SCALE              = &H00000010
#IF (%WINVER >= &H0500)
%DM_POSITION           = &H00000020
%DM_NUP                = &H00000040
#ENDIF ' WINVER >= &H0500
#IF (%WINVER >= &H0501)
%DM_DISPLAYORIENTATION = &H00000080
#ENDIF ' WINVER >= &H0501
%DM_COPIES             = &H00000100
%DM_DEFAULTSOURCE      = &H00000200
%DM_PRINTQUALITY       = &H00000400
%DM_COLOR              = &H00000800
%DM_DUPLEX             = &H00001000
%DM_YRESOLUTION        = &H00002000
%DM_TTOPTION           = &H00004000
%DM_COLLATE            = &H00008000
%DM_FORMNAME           = &H00010000
%DM_LOGPIXELS          = &H00020000
%DM_BITSPERPEL         = &H00040000
%DM_PELSWIDTH          = &H00080000
%DM_PELSHEIGHT         = &H00100000
%DM_DISPLAYFLAGS       = &H00200000
%DM_DISPLAYFREQUENCY   = &H00400000
#IF (%WINVER >= &H0400)
%DM_ICMMETHOD          = &H00800000
%DM_ICMINTENT          = &H01000000
%DM_MEDIATYPE          = &H02000000
%DM_DITHERTYPE         = &H04000000
%DM_PANNINGWIDTH       = &H08000000
%DM_PANNINGHEIGHT      = &H10000000
#ENDIF ' WINVER >= &H0400
#IF (%WINVER >= &H0501)
%DM_DISPLAYFIXEDOUTPUT = &H20000000
#ENDIF ' WINVER >= &H0501

' orientation selections
%DMORIENT_PORTRAIT  = 1
%DMORIENT_LANDSCAPE = 2

' paper selections
%DMPAPER_FIRST              =  %DMPAPER_LETTER
%DMPAPER_LETTER             =  1  ' Letter 8 1/2 x 11 in
%DMPAPER_LETTERSMALL        =  2  ' Letter Small 8 1/2 x 11 in
%DMPAPER_TABLOID            =  3  ' Tabloid 11 x 17 in
%DMPAPER_LEDGER             =  4  ' Ledger 17 x 11 in
%DMPAPER_LEGAL              =  5  ' Legal 8 1/2 x 14 in
%DMPAPER_STATEMENT          =  6  ' Statement 5 1/2 x 8 1/2 in
%DMPAPER_EXECUTIVE          =  7  ' Executive 7 1/4 x 10 1/2 in
%DMPAPER_A3                 =  8  ' A3 297 x 420 mm
%DMPAPER_A4                 =  9  ' A4 210 x 297 mm
%DMPAPER_A4SMALL            = 10  ' A4 Small 210 x 297 mm
%DMPAPER_A5                 = 11  ' A5 148 x 210 mm
%DMPAPER_B4                 = 12  ' B4 (JIS) 250 x 354
%DMPAPER_B5                 = 13  ' B5 (JIS) 182 x 257 mm
%DMPAPER_FOLIO              = 14  ' Folio 8 1/2 x 13 in
%DMPAPER_QUARTO             = 15  ' Quarto 215 x 275 mm
%DMPAPER_10X14              = 16  ' 10X14 in
%DMPAPER_11X17              = 17  ' 11x17 in
%DMPAPER_NOTE               = 18  ' Note 8 1/2 x 11 in
%DMPAPER_ENV_9              = 19  ' Envelope #9 3 7/8 x 8 7/8
%DMPAPER_ENV_10             = 20  ' Envelope #10 4 1/8 x 9 1/2
%DMPAPER_ENV_11             = 21  ' Envelope #11 4 1/2 x 10 3/8
%DMPAPER_ENV_12             = 22  ' Envelope #12 4 \276 x 11
%DMPAPER_ENV_14             = 23  ' Envelope #14 5 x 11 1/2
%DMPAPER_CSHEET             = 24  ' C size sheet
%DMPAPER_DSHEET             = 25  ' D size sheet
%DMPAPER_ESHEET             = 26  ' E size sheet
%DMPAPER_ENV_DL             = 27  ' Envelope DL 110 x 220mm
%DMPAPER_ENV_C5             = 28  ' Envelope C5 162 x 229 mm
%DMPAPER_ENV_C3             = 29  ' Envelope C3  324 x 458 mm
%DMPAPER_ENV_C4             = 30  ' Envelope C4  229 x 324 mm
%DMPAPER_ENV_C6             = 31  ' Envelope C6  114 x 162 mm
%DMPAPER_ENV_C65            = 32  ' Envelope C65 114 x 229 mm
%DMPAPER_ENV_B4             = 33  ' Envelope B4  250 x 353 mm
%DMPAPER_ENV_B5             = 34  ' Envelope B5  176 x 250 mm
%DMPAPER_ENV_B6             = 35  ' Envelope B6  176 x 125 mm
%DMPAPER_ENV_ITALY          = 36  ' Envelope 110 x 230 mm
%DMPAPER_ENV_MONARCH        = 37  ' Envelope Monarch 3.875 x 7.5 in
%DMPAPER_ENV_PERSONAL       = 38  ' 6 3/4 Envelope 3 5/8 x 6 1/2 in
%DMPAPER_FANFOLD_US         = 39  ' US Std Fanfold 14 7/8 x 11 in
%DMPAPER_FANFOLD_STD_GERMAN = 40  ' German Std Fanfold 8 1/2 x 12 in
%DMPAPER_FANFOLD_LGL_GERMAN = 41  ' German Legal Fanfold 8 1/2 x 13 in
#IF (%WINVER >= &H0400)
%DMPAPER_ISO_B4             = 42  ' B4 (ISO) 250 x 353 mm
%DMPAPER_JAPANESE_POSTCARD  = 43  ' Japanese Postcard 100 x 148 mm
%DMPAPER_9X11               = 44  ' 9 x 11 in
%DMPAPER_10X11              = 45  ' 10 x 11 in
%DMPAPER_15X11              = 46  ' 15 x 11 in
%DMPAPER_ENV_INVITE         = 47  ' Envelope Invite 220 x 220 mm
%DMPAPER_RESERVED_48        = 48  ' RESERVED--DO NOT USE
%DMPAPER_RESERVED_49        = 49  ' RESERVED--DO NOT USE
%DMPAPER_LETTER_EXTRA       = 50  ' Letter Extra 9 \275 x 12 in
%DMPAPER_LEGAL_EXTRA        = 51  ' Legal Extra 9 \275 x 15 in
%DMPAPER_TABLOID_EXTRA      = 52  ' Tabloid Extra 11.69 x 18 in
%DMPAPER_A4_EXTRA           = 53  ' A4 Extra 9.27 x 12.69 in
%DMPAPER_LETTER_TRANSVERSE  = 54  ' Letter Transverse 8 \275 x 11 in
%DMPAPER_A4_TRANSVERSE      = 55  ' A4 Transverse 210 x 297 mm
%DMPAPER_LETTER_EXTRA_TRANSVERSE = 56 ' Letter Extra Transverse 9\275 x 12 in
%DMPAPER_A_PLUS             = 57  ' SuperA/SuperA/A4 227 x 356 mm
%DMPAPER_B_PLUS             = 58  ' SuperB/SuperB/A3 305 x 487 mm
%DMPAPER_LETTER_PLUS        = 59  ' Letter Plus 8.5 x 12.69 in
%DMPAPER_A4_PLUS            = 60  ' A4 Plus 210 x 330 mm
%DMPAPER_A5_TRANSVERSE      = 61  ' A5 Transverse 148 x 210 mm
%DMPAPER_B5_TRANSVERSE      = 62  ' B5 (JIS) Transverse 182 x 257 mm
%DMPAPER_A3_EXTRA           = 63  ' A3 Extra 322 x 445 mm
%DMPAPER_A5_EXTRA           = 64  ' A5 Extra 174 x 235 mm
%DMPAPER_B5_EXTRA           = 65  ' B5 (ISO) Extra 201 x 276 mm
%DMPAPER_A2                 = 66  ' A2 420 x 594 mm
%DMPAPER_A3_TRANSVERSE      = 67  ' A3 Transverse 297 x 420 mm
%DMPAPER_A3_EXTRA_TRANSVERSE= 68  ' A3 Extra Transverse 322 x 445 mm
#ENDIF ' WINVER >= &H0400

#IF (%WINVER >= &H0500)
%DMPAPER_DBL_JAPANESE_POSTCARD = 69 ' Japanese Double Postcard 200 x 148 mm
%DMPAPER_A6                 = 70  ' A6 105 x 148 mm
%DMPAPER_JENV_KAKU2         = 71  ' Japanese Envelope Kaku #2
%DMPAPER_JENV_KAKU3         = 72  ' Japanese Envelope Kaku #3
%DMPAPER_JENV_CHOU3         = 73  ' Japanese Envelope Chou #3
%DMPAPER_JENV_CHOU4         = 74  ' Japanese Envelope Chou #4
%DMPAPER_LETTER_ROTATED     = 75  ' Letter Rotated 11 x 8 1/2 11 in
%DMPAPER_A3_ROTATED         = 76  ' A3 Rotated 420 x 297 mm
%DMPAPER_A4_ROTATED         = 77  ' A4 Rotated 297 x 210 mm
%DMPAPER_A5_ROTATED         = 78  ' A5 Rotated 210 x 148 mm
%DMPAPER_B4_JIS_ROTATED     = 79  ' B4 (JIS) Rotated 364 x 257 mm
%DMPAPER_B5_JIS_ROTATED     = 80  ' B5 (JIS) Rotated 257 x 182 mm
%DMPAPER_JAPANESE_POSTCARD_ROTATED = 81 ' Japanese Postcard Rotated 148 x 100 mm
%DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED = 82 ' Double Japanese Postcard Rotated 148 x 200 mm
%DMPAPER_A6_ROTATED         = 83  ' A6 Rotated 148 x 105 mm
%DMPAPER_JENV_KAKU2_ROTATED = 84  ' Japanese Envelope Kaku #2 Rotated
%DMPAPER_JENV_KAKU3_ROTATED = 85  ' Japanese Envelope Kaku #3 Rotated
%DMPAPER_JENV_CHOU3_ROTATED = 86  ' Japanese Envelope Chou #3 Rotated
%DMPAPER_JENV_CHOU4_ROTATED = 87  ' Japanese Envelope Chou #4 Rotated
%DMPAPER_B6_JIS             = 88  ' B6 (JIS) 128 x 182 mm
%DMPAPER_B6_JIS_ROTATED     = 89  ' B6 (JIS) Rotated 182 x 128 mm
%DMPAPER_12X11              = 90  ' 12 x 11 in
%DMPAPER_JENV_YOU4          = 91  ' Japanese Envelope You #4
%DMPAPER_JENV_YOU4_ROTATED  = 92  ' Japanese Envelope You #4 Rotated
%DMPAPER_P16K               = 93  ' PRC 16K 146 x 215 mm
%DMPAPER_P32K               = 94  ' PRC 32K 97 x 151 mm
%DMPAPER_P32KBIG            = 95  ' PRC 32K(Big) 97 x 151 mm
%DMPAPER_PENV_1             = 96  ' PRC Envelope #1 102 x 165 mm
%DMPAPER_PENV_2             = 97  ' PRC Envelope #2 102 x 176 mm
%DMPAPER_PENV_3             = 98  ' PRC Envelope #3 125 x 176 mm
%DMPAPER_PENV_4             = 99  ' PRC Envelope #4 110 x 208 mm
%DMPAPER_PENV_5             = 100 ' PRC Envelope #5 110 x 220 mm
%DMPAPER_PENV_6             = 101 ' PRC Envelope #6 120 x 230 mm
%DMPAPER_PENV_7             = 102 ' PRC Envelope #7 160 x 230 mm
%DMPAPER_PENV_8             = 103 ' PRC Envelope #8 120 x 309 mm
%DMPAPER_PENV_9             = 104 ' PRC Envelope #9 229 x 324 mm
%DMPAPER_PENV_10            = 105 ' PRC Envelope #10 324 x 458 mm
%DMPAPER_P16K_ROTATED       = 106 ' PRC 16K Rotated
%DMPAPER_P32K_ROTATED       = 107 ' PRC 32K Rotated
%DMPAPER_P32KBIG_ROTATED    = 108 ' PRC 32K(Big) Rotated
%DMPAPER_PENV_1_ROTATED     = 109 ' PRC Envelope #1 Rotated 165 x 102 mm
%DMPAPER_PENV_2_ROTATED     = 110 ' PRC Envelope #2 Rotated 176 x 102 mm
%DMPAPER_PENV_3_ROTATED     = 111 ' PRC Envelope #3 Rotated 176 x 125 mm
%DMPAPER_PENV_4_ROTATED     = 112 ' PRC Envelope #4 Rotated 208 x 110 mm
%DMPAPER_PENV_5_ROTATED     = 113 ' PRC Envelope #5 Rotated 220 x 110 mm
%DMPAPER_PENV_6_ROTATED     = 114 ' PRC Envelope #6 Rotated 230 x 120 mm
%DMPAPER_PENV_7_ROTATED     = 115 ' PRC Envelope #7 Rotated 230 x 160 mm
%DMPAPER_PENV_8_ROTATED     = 116 ' PRC Envelope #8 Rotated 309 x 120 mm
%DMPAPER_PENV_9_ROTATED     = 117 ' PRC Envelope #9 Rotated 324 x 229 mm
%DMPAPER_PENV_10_ROTATED    = 118 ' PRC Envelope #10 Rotated 458 x 324 mm
#ENDIF ' WINVER >= &H0500

#IF (%WINVER >= &H0500)
%DMPAPER_LAST               = %DMPAPER_PENV_10_ROTATED
#ELSEIF (%WINVER >= &H0400)
%DMPAPER_LAST               = %DMPAPER_A3_EXTRA_TRANSVERSE
#ELSE
%DMPAPER_LAST               = %DMPAPER_FANFOLD_LGL_GERMAN
#ENDIF

%DMPAPER_USER               = 256

' bin selections
%DMBIN_FIRST         = %DMBIN_UPPER
%DMBIN_UPPER         = 1
%DMBIN_ONLYONE       = 1
%DMBIN_LOWER         = 2
%DMBIN_MIDDLE        = 3
%DMBIN_MANUAL        = 4
%DMBIN_ENVELOPE      = 5
%DMBIN_ENVMANUAL     = 6
%DMBIN_AUTO          = 7
%DMBIN_TRACTOR       = 8
%DMBIN_SMALLFMT      = 9
%DMBIN_LARGEFMT      = 10
%DMBIN_LARGECAPACITY = 11
%DMBIN_CASSETTE      = 14
%DMBIN_FORMSOURCE    = 15
%DMBIN_LAST          = %DMBIN_FORMSOURCE

%DMBIN_USER          = 256     ' device specific bins start here

' print qualities
%DMRES_DRAFT         = -1
%DMRES_LOW           = -2
%DMRES_MEDIUM        = -3
%DMRES_HIGH          = -4

' color enable/disable for color printers
%DMCOLOR_MONOCHROME  = 1
%DMCOLOR_COLOR       = 2

' duplex enable
%DMDUP_SIMPLEX    = 1
%DMDUP_VERTICAL   = 2
%DMDUP_HORIZONTAL = 3

' TrueType options
%DMTT_BITMAP     = 1       ' print TT fonts as graphics
%DMTT_DOWNLOAD   = 2       ' download TT fonts as soft fonts
%DMTT_SUBDEV     = 3       ' substitute device fonts for TT fonts
#IF (%WINVER >= &H0400)
%DMTT_DOWNLOAD_OUTLINE = 4 ' download TT fonts as outline soft fonts
#ENDIF ' WINVER >= &H0400

' Collation selections
%DMCOLLATE_FALSE  = 0
%DMCOLLATE_TRUE   = 1

#IF (%WINVER >= &H0501)
' DEVMODE dmDisplayOrientation specifiations
%DMDO_DEFAULT  = 0
%DMDO_90       = 1
%DMDO_180      = 2
%DMDO_270      = 3

' DEVMODE dmDisplayFixedOutput specifiations
%DMDFO_DEFAULT = 0
%DMDFO_STRETCH = 1
%DMDFO_CENTER  = 2
#ENDIF ' WINVER >= &H0501

' DEVMODE dmDisplayFlags flags

' %DM_GRAYSCALE            = &H00000001 ' This flag is no longer valid
%DM_INTERLACED           = &H00000002
%DMDISPLAYFLAGS_TEXTMODE = &H00000004

' dmNup , multiple logical page per physical page options
%DMNUP_SYSTEM       = 1
%DMNUP_ONEUP        = 2

#IF (%WINVER >= &H0400)
' ICM methods
%DMICMMETHOD_NONE   = 1   ' ICM disabled
%DMICMMETHOD_SYSTEM = 2   ' ICM handled by system
%DMICMMETHOD_DRIVER = 3   ' ICM handled by driver
%DMICMMETHOD_DEVICE = 4   ' ICM handled by device

%DMICMMETHOD_USER = 256   ' Device-specific methods start here

' ICM Intents
%DMICM_SATURATE         = 1   ' Maximize color saturation
%DMICM_CONTRAST         = 2   ' Maximize color contrast
%DMICM_COLORIMETRIC     = 3   ' Use specific color metric
%DMICM_ABS_COLORIMETRIC = 4   ' Use specific color metric

%DMICM_USER       = 256   ' Device-specific intents start here

' Media types

%DMMEDIA_STANDARD     = 1   ' Standard paper
%DMMEDIA_TRANSPARENCY = 2   ' Transparency
%DMMEDIA_GLOSSY       = 3   ' Glossy paper

%DMMEDIA_USER      =  256   ' Device-specific media start here

' Dither types
%DMDITHER_NONE           = 1   ' No dithering
%DMDITHER_COARSE         = 2   ' Dither with a coarse brush
%DMDITHER_FINE           = 3   ' Dither with a fine brush
%DMDITHER_LINEART        = 4   ' LineArt dithering
%DMDITHER_ERRORDIFFUSION = 5   ' LineArt dithering
%DMDITHER_RESERVED6      = 6   ' LineArt dithering
%DMDITHER_RESERVED7      = 7   ' LineArt dithering
%DMDITHER_RESERVED8      = 8   ' LineArt dithering
%DMDITHER_RESERVED9      = 9   ' LineArt dithering
%DMDITHER_GRAYSCALE      = 10  ' Device does grayscaling

%DMDITHER_USER   = 256   ' Device-specific dithers start here
#ENDIF ' WINVER >= &H0400

TYPE DISPLAY_DEVICEA
    cb           AS DWORD
    DeviceName   AS ASCIIZ * 32
    DeviceString AS ASCIIZ * 128
    StateFlags   AS DWORD
    DeviceID     AS ASCIIZ * 128
    DeviceKey    AS ASCIIZ * 128
END TYPE

TYPE DISPLAY_DEVICEW
    cb           AS DWORD
    DeviceName   AS WSTRINGZ * 32
    DeviceString AS WSTRINGZ * 128
    StateFlags   AS DWORD
    DeviceID     AS WSTRINGZ * 128
    DeviceKey    AS WSTRINGZ * 128
END TYPE

#IF %DEF(%UNICODE)
TYPE DISPLAY_DEVICE
    DISPLAY_DEVICEW
END TYPE
#ELSE
TYPE DISPLAY_DEVICE
    DISPLAY_DEVICEA
END TYPE
#ENDIF ' UNICODE

%DISPLAY_DEVICE_ATTACHED_TO_DESKTOP = &H00000001
%DISPLAY_DEVICE_MULTI_DRIVER        = &H00000002
%DISPLAY_DEVICE_PRIMARY_DEVICE      = &H00000004
%DISPLAY_DEVICE_MIRRORING_DRIVER    = &H00000008
%DISPLAY_DEVICE_VGA_COMPATIBLE      = &H00000010
#IF (%WIN32_WINNT >= %WIN32_WINNT_WIN2K)
%DISPLAY_DEVICE_REMOVABLE           = &H00000020
#ENDIF
%DISPLAY_DEVICE_MODESPRUNED         = &H08000000
#IF (%WIN32_WINNT >= %WIN32_WINNT_WIN2K)
%DISPLAY_DEVICE_REMOTE              = &H04000000
%DISPLAY_DEVICE_DISCONNECT          = &H02000000
#ENDIF
%DISPLAY_DEVICE_TS_COMPATIBLE       = &H00200000
#IF (%WIN32_WINNT >= %WIN32_WINNT_LONGHORN)
%DISPLAY_DEVICE_UNSAFE_MODES_ON     = &H00080000
#ENDIF

' Child device state
#IF (%WIN32_WINNT >= %WIN32_WINNT_WIN2K)
%DISPLAY_DEVICE_ACTIVE              = &H00000001
%DISPLAY_DEVICE_ATTACHED            = &H00000002
#ENDIF ' (%WIN32_WINNT >= %WIN32_WINNT_WIN2K)

#IF (%WINVER >= &H0601)

%DISPLAYCONFIG_MAXPATH = 1024        ' Maximum display path in system.
                                     ' Max adapter (16) * Max source (16) *
                                     ' Max clone pre source (4)

TYPE DISPLAYCONFIG_RATIONAL
    Numerator   AS DWORD
    Denominator AS DWORD
END TYPE

MACRO DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY_enum=LONG
ENUM DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY SINGULAR
    DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY_OTHER                   = -1
    DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY_HD15
    DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY_SVIDEO
    DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY_COMPOSITE_VIDEO
    DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY_COMPONENT_VIDEO
    DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY_DVI
    DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY_HDMI
    DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY_LVDS
    displayconfig_video_output_technology_reserved
    DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY_D_JPN
    DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY_SDI
    DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY_DISPLAYPORT_EXTERNAL
    DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY_DISPLAYPORT_EMBEDDED
    DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY_UDI_EXTERNAL
    DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY_UDI_EMBEDDED
    DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY_SDTVDONGLE
    DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY_INTERNAL      = &H80000000???
    DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY_FORCE_UINT32  = &HFFFFFFFF???
END ENUM

MACRO DISPLAYCONFIG_SCANLINE_ORDERING_enum=LONG
ENUM DISPLAYCONFIG_SCANLINE_ORDERING SINGULAR
    DISPLAYCONFIG_SCANLINE_ORDERING_UNSPECIFIED
    DISPLAYCONFIG_SCANLINE_ORDERING_PROGRESSIVE
    DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED
    DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_UPPERFIELDFIRST = %DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED
    DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_LOWERFIELDFIRST
    DISPLAYCONFIG_SCANLINE_ORDERING_FORCE_UINT32               = &HFFFFFFFF???
END ENUM

TYPE DISPLAYCONFIG_2DREGION
    cx AS DWORD
    cy AS DWORD
END TYPE

TYPE DISPLAYCONFIG_VIDEO_SIGNAL_INFO
    pixelRate        AS QUAD   ' [unsigned]
    hSyncFreq        AS DISPLAYCONFIG_RATIONAL
    vSyncFreq        AS DISPLAYCONFIG_RATIONAL
    activeSize       AS DISPLAYCONFIG_2DREGION
    totalSize        AS DISPLAYCONFIG_2DREGION
    videoStandard    AS DWORD
    scanLineOrdering AS LONG ' DISPLAYCONFIG_SCANLINE_ORDERING
END TYPE

MACRO DISPLAYCONFIG_SCALING_enum=LONG
ENUM DISPLAYCONFIG_SCALING SINGULAR
    DISPLAYCONFIG_SCALING_IDENTITY      = 1
    DISPLAYCONFIG_SCALING_CENTERED
    DISPLAYCONFIG_SCALING_STRETCHED
    DISPLAYCONFIG_SCALING_ASPECTRATIOCENTEREDMAX
    DISPLAYCONFIG_SCALING_CUSTOM
    DISPLAYCONFIG_SCALING_PREFERRED     = 128
    DISPLAYCONFIG_SCALING_FORCE_UINT32  = &HFFFFFFFF???
END ENUM

MACRO DISPLAYCONFIG_ROTATION_enum=LONG
ENUM DISPLAYCONFIG_ROTATION SINGULAR
    DISPLAYCONFIG_ROTATION_IDENTITY     = 1
    DISPLAYCONFIG_ROTATION_ROTATE90
    DISPLAYCONFIG_ROTATION_ROTATE180
    DISPLAYCONFIG_ROTATION_ROTATE270
    DISPLAYCONFIG_ROTATION_FORCE_UINT32 = &HFFFFFFFF???
END ENUM

MACRO DISPLAYCONFIG_MODE_INFO_TYPE_enum=LONG
ENUM DISPLAYCONFIG_MODE_INFO_TYPE SINGULAR
    DISPLAYCONFIG_MODE_INFO_TYPE_SOURCE       = 1
    DISPLAYCONFIG_MODE_INFO_TYPE_TARGET
    DISPLAYCONFIG_MODE_INFO_TYPE_FORCE_UINT32 = &HFFFFFFFF???
END ENUM

MACRO DISPLAYCONFIG_PIXELFORMAT_enum=LONG
ENUM DISPLAYCONFIG_PIXELFORMAT SINGULAR
    DISPLAYCONFIG_PIXELFORMAT_8BPP         = 1
    DISPLAYCONFIG_PIXELFORMAT_16BPP
    DISPLAYCONFIG_PIXELFORMAT_24BPP
    DISPLAYCONFIG_PIXELFORMAT_32BPP
    DISPLAYCONFIG_PIXELFORMAT_NONGDI
    DISPLAYCONFIG_PIXELFORMAT_FORCE_UINT32 = &Hffffffff???
END ENUM

TYPE DISPLAYCONFIG_SOURCE_MODE
    WIDTH       AS DWORD
    height      AS DWORD
    pixelFormat AS LONG ' DISPLAYCONFIG_PIXELFORMAT
    position    AS POINTL
END TYPE

TYPE DISPLAYCONFIG_TARGET_MODE
    targetVideoSignalInfo AS DISPLAYCONFIG_VIDEO_SIGNAL_INFO
END TYPE

UNION DISPLAYCONFIG_MODE_INFO_union
    targetMode AS DISPLAYCONFIG_TARGET_MODE
    sourceMode AS DISPLAYCONFIG_SOURCE_MODE
END UNION

TYPE DISPLAYCONFIG_MODE_INFO
    infoType  AS LONG  ' DISPLAYCONFIG_MODE_INFO_TYPE
    ID        AS DWORD
    adapterId AS QUAD  ' LUID
    DISPLAYCONFIG_MODE_INFO_union
END TYPE

%DISPLAYCONFIG_PATH_MODE_IDX_INVALID   = &Hffffffff???

TYPE DISPLAYCONFIG_PATH_SOURCE_INFO
    adapterId   AS QUAD  ' LUID
    ID          AS DWORD
    modeInfoIdx AS DWORD
    statusFlags AS DWORD
END TYPE

'
' Flags for source info structure (from OS to application through QDC)
'

%DISPLAYCONFIG_SOURCE_IN_USE   = &H00000001

TYPE DISPLAYCONFIG_PATH_TARGET_INFO
    adapterId        AS QUAD  ' LUID
    ID               AS DWORD
    modeInfoIdx      AS DWORD
    outputTechnology AS DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY_enum
    rotation         AS DISPLAYCONFIG_ROTATION_enum
    scaling          AS DISPLAYCONFIG_SCALING_enum
    refreshRate      AS DISPLAYCONFIG_RATIONAL
    scanLineOrdering AS DISPLAYCONFIG_SCANLINE_ORDERING_enum
    targetAvailable  AS LONG  ' BOOL
    statusFlags      AS DWORD
END TYPE

'
' Status flags for target info structure (from OS to application through QDC)
'
%DISPLAYCONFIG_TARGET_IN_USE                       = &H00000001
%DISPLAYCONFIG_TARGET_FORCIBLE                     = &H00000002
%DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_BOOT     = &H00000004
%DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_PATH     = &H00000008
%DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_SYSTEM   = &H00000010

TYPE DISPLAYCONFIG_PATH_INFO
    sourceInfo AS DISPLAYCONFIG_PATH_SOURCE_INFO
    targetInfo AS DISPLAYCONFIG_PATH_TARGET_INFO
    flags      AS DWORD
END TYPE

'
' Flags for path info structure (from OS to application through QDC)
'

%DISPLAYCONFIG_PATH_ACTIVE     = &H00000001

MACRO DISPLAYCONFIG_TOPOLOGY_ID_enum=LONG
ENUM DISPLAYCONFIG_TOPOLOGY_ID BITS SINGULAR
    DISPLAYCONFIG_TOPOLOGY_ID_INTERNAL     = 1
    DISPLAYCONFIG_TOPOLOGY_ID_CLONE
    DISPLAYCONFIG_TOPOLOGY_ID_EXTEND
    DISPLAYCONFIG_TOPOLOGY_ID_EXTERNAL
    DISPLAYCONFIG_TOPOLOGY_ID_FORCE_UINT32 = &HFFFFFFFF???
END ENUM

MACRO DISPLAYCONFIG_DEVICE_INFO_TYPE_enum=LONG
ENUM DISPLAYCONFIG_DEVICE_INFO_TYPE SINGULAR
    DISPLAYCONFIG_DEVICE_INFO_TYPE_GET_SOURCE_NAME           = 1
    DISPLAYCONFIG_DEVICE_INFO_TYPE_GET_TARGET_NAME
    DISPLAYCONFIG_DEVICE_INFO_TYPE_GET_TARGET_PREFERRED_MODE
    DISPLAYCONFIG_DEVICE_INFO_TYPE_GET_ADAPTER_NAME
    DISPLAYCONFIG_DEVICE_INFO_TYPE_SET_TARGET_PERSISTENCE
    DISPLAYCONFIG_DEVICE_INFO_TYPE_FORCE_UINT32              = &HFFFFFFFF???
END ENUM

TYPE DISPLAYCONFIG_DEVICE_INFO_HEADER
    dtype      AS DISPLAYCONFIG_DEVICE_INFO_TYPE_enum
    dsize      AS DWORD
    adapterId  AS QUAD  ' LUID
    ID         AS DWORD
END TYPE

TYPE DISPLAYCONFIG_SOURCE_DEVICE_NAME
    HEADER            AS DISPLAYCONFIG_DEVICE_INFO_HEADER
    viewGdiDeviceName AS WSTRINGZ * %CCHDEVICENAME
END TYPE

TYPE DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS_type
    friendlyNameFromEdid AS BIT * 1 IN DWORD
    friendlyNameForced   AS BIT * 1
    edidIdsValid         AS BIT * 1
    reserved             AS BIT * 29
END TYPE

UNION DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS
    DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS_type
    value AS DWORD
END UNION

TYPE DISPLAYCONFIG_TARGET_DEVICE_NAME
    HEADER                    AS DISPLAYCONFIG_DEVICE_INFO_HEADER
    flags                     AS DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS
    outputTechnology          AS DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY_enum
    edidManufactureId         AS WORD
    edidProductCodeId         AS WORD
    connectorInstance         AS DWORD
    monitorFriendlyDeviceName AS WSTRINGZ * 64
    monitorDevicePath         AS WSTRINGZ * 128
END TYPE

TYPE DISPLAYCONFIG_TARGET_PREFERRED_MODE
    HEADER     AS DISPLAYCONFIG_DEVICE_INFO_HEADER
    WIDTH      AS DWORD
    height     AS DWORD
    targetMode AS DISPLAYCONFIG_TARGET_MODE
END TYPE

TYPE DISPLAYCONFIG_ADAPTER_NAME
    HEADER            AS DISPLAYCONFIG_DEVICE_INFO_HEADER
    adapterDevicePath AS WSTRINGZ * 128
END TYPE

TYPE DISPLAYCONFIG_SET_TARGET_PERSISTENCE_type
    bootPersistenceOn  AS BIT * 1 IN DWORD
    reserved           AS BIT * 31
END TYPE

UNION DISPLAYCONFIG_SET_TARGET_PERSISTENCE_union
    DISPLAYCONFIG_SET_TARGET_PERSISTENCE_type
    value AS DWORD
END UNION

TYPE DISPLAYCONFIG_SET_TARGET_PERSISTENCE
    HEADER AS DISPLAYCONFIG_DEVICE_INFO_HEADER
    DISPLAYCONFIG_SET_TARGET_PERSISTENCE_union
END TYPE

'
' Definitions to be used by GetDisplayConfigBufferSizes and QueryDisplayConfig.
'

%QDC_ALL_PATHS                   = &H00000001
%QDC_ONLY_ACTIVE_PATHS           = &H00000002
%QDC_DATABASE_CURRENT            = &H00000004

'
' Definitions used by SetDisplayConfig.
'

%SDC_TOPOLOGY_INTERNAL           = &H00000001
%SDC_TOPOLOGY_CLONE              = &H00000002
%SDC_TOPOLOGY_EXTEND             = &H00000004
%SDC_TOPOLOGY_EXTERNAL           = &H00000008
%SDC_TOPOLOGY_SUPPLIED           = &H00000010
%SDC_USE_DATABASE_CURRENT        = (%SDC_TOPOLOGY_INTERNAL OR %SDC_TOPOLOGY_CLONE _
                                 OR %SDC_TOPOLOGY_EXTEND OR %SDC_TOPOLOGY_EXTERNAL)

%SDC_USE_SUPPLIED_DISPLAY_CONFIG = &H00000020
%SDC_VALIDATE                    = &H00000040
%SDC_APPLY                       = &H00000080
%SDC_NO_OPTIMIZATION             = &H00000100
%SDC_SAVE_TO_DATABASE            = &H00000200
%SDC_ALLOW_CHANGES               = &H00000400
%SDC_PATH_PERSIST_IF_REQUIRED    = &H00000800
%SDC_FORCE_MODE_ENUMERATION      = &H00001000
%SDC_ALLOW_PATH_ORDER_CHANGES    = &H00002000

#ENDIF ' %WINVER >= &H0601

' GetRegionData/ExtCreateRegion

%RDH_RECTANGLES = 1

TYPE RGNDATAHEADER
    dwSize   AS DWORD
    iType    AS DWORD
    nCount   AS DWORD
    nRgnSize AS DWORD
    rcBound  AS RECT
END TYPE

TYPE RGNDATA
    rdh       AS RGNDATAHEADER
    BUFFER(0) AS BYTE
END TYPE


' for GetRandomRgn
%SYSRGN = 4

TYPE ABC
    abcA AS LONG
    abcB AS DWORD
    abcC AS LONG
END TYPE

TYPE ABCFLOAT
    abcfA AS SINGLE
    abcfB AS SINGLE
    abcfC AS SINGLE
END TYPE

#IF NOT %DEF(%NOTEXTMETRIC)

TYPE OUTLINETEXTMETRICA
    otmSize                AS DWORD
    otmTextMetrics         AS TEXTMETRICA
    otmFiller              AS BYTE
    otmPanoseNumber        AS PANOSE
    otmfsSelection         AS DWORD
    otmfsType              AS DWORD
    otmsCharSlopeRise      AS LONG
    otmsCharSlopeRun       AS LONG
    otmItalicAngle         AS LONG
    otmEMSquare            AS DWORD
    otmAscent              AS LONG
    otmDescent             AS LONG
    otmLineGap             AS DWORD
    otmsCapEmHeight        AS DWORD
    otmsXHeight            AS DWORD
    otmrcFontBox           AS RECT
    otmMacAscent           AS LONG
    otmMacDescent          AS LONG
    otmMacLineGap          AS DWORD
    otmusMinimumPPEM       AS DWORD
    otmptSubscriptSize     AS POINT
    otmptSubscriptOffset   AS POINT
    otmptSuperscriptSize   AS POINT
    otmptSuperscriptOffset AS POINT
    otmsStrikeoutSize      AS DWORD
    otmsStrikeoutPosition  AS LONG
    otmsUnderscoreSize     AS LONG
    otmsUnderscorePosition AS LONG
    otmpFamilyName         AS DWORD ' ASCIIZ PTR
    otmpFaceName           AS DWORD ' ASCIIZ PTR
    otmpStyleName          AS DWORD ' ASCIIZ PTR
    otmpFullName           AS DWORD ' ASCIIZ PTR
END TYPE

TYPE OUTLINETEXTMETRICW
    otmSize                AS DWORD
    otmTextMetrics         AS TEXTMETRICW
    otmFiller              AS BYTE
    otmPanoseNumber        AS PANOSE
    otmfsSelection         AS DWORD
    otmfsType              AS DWORD
    otmsCharSlopeRise      AS LONG
    otmsCharSlopeRun       AS LONG
    otmItalicAngle         AS LONG
    otmEMSquare            AS DWORD
    otmAscent              AS LONG
    otmDescent             AS LONG
    otmLineGap             AS DWORD
    otmsCapEmHeight        AS DWORD
    otmsXHeight            AS DWORD
    otmrcFontBox           AS RECT
    otmMacAscent           AS LONG
    otmMacDescent          AS LONG
    otmMacLineGap          AS DWORD
    otmusMinimumPPEM       AS DWORD
    otmptSubscriptSize     AS POINT
    otmptSubscriptOffset   AS POINT
    otmptSuperscriptSize   AS POINT
    otmptSuperscriptOffset AS POINT
    otmsStrikeoutSize      AS DWORD
    otmsStrikeoutPosition  AS LONG
    otmsUnderscoreSize     AS LONG
    otmsUnderscorePosition AS LONG
    otmpFamilyName         AS DWORD ' WSTRINGZ PTR
    otmpFaceName           AS DWORD ' WSTRINGZ PTR
    otmpStyleName          AS DWORD ' WSTRINGZ PTR
    otmpFullName           AS DWORD ' WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE OUTLINETEXTMETRIC
    OUTLINETEXTMETRICW
END TYPE
#ELSE
TYPE OUTLINETEXTMETRIC
    OUTLINETEXTMETRICA
END TYPE
#ENDIF ' %UNICODE

#ENDIF ' %NOTEXTMETRIC

TYPE POLYTEXTA
    x       AS LONG
    y       AS LONG
    n       AS DWORD
    lpstr   AS ASCIIZ PTR
    uiFlags AS DWORD
    rcl     AS RECT
    pdx     AS LONG PTR
END TYPE

TYPE POLYTEXTW
    x       AS LONG
    y       AS LONG
    n       AS DWORD
    lpstr   AS WSTRINGZ PTR
    uiFlags AS DWORD
    rcl     AS RECT
    pdx     AS LONG PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE POLYTEXT
    POLYTEXTW
END TYPE
#ELSE
TYPE POLYTEXT
    POLYTEXTA
END TYPE
#ENDIF ' UNICODE

#IF NOT %DEF(%MAC)
TYPE FIXED
    fract AS WORD
    value AS INTEGER
END TYPE
#ELSE
TYPE FIXED
    value AS INTEGER
    fract AS WORD
END TYPE
#ENDIF


TYPE MAT2
    eM11 AS FIXED
    eM12 AS FIXED
    eM21 AS FIXED
    eM22 AS FIXED
END TYPE


TYPE GLYPHMETRICS
    gmBlackBoxX     AS DWORD
    gmBlackBoxY     AS DWORD
    gmptGlyphOrigin AS POINT
    gmCellIncX      AS INTEGER
    gmCellIncY      AS INTEGER
END TYPE

'  GetGlyphOutline constants

%GGO_METRICS       = 0
%GGO_BITMAP        = 1
%GGO_NATIVE        = 2
%GGO_BEZIER        = 3

#IF (%WINVER >= &H0400)
%GGO_GRAY2_BITMAP = 4
%GGO_GRAY4_BITMAP = 5
%GGO_GRAY8_BITMAP = 6
%GGO_GLYPH_INDEX  = &H0080
#ENDIF ' WINVER >= &H0400

#IF (%WIN32_WINNT >= %WIN32_WINNT_WIN2K)
%GGO_UNHINTED     = &H0100
#ENDIF ' (%WIN32_WINNT >= %WIN32_WINNT_WIN2K)

%TT_POLYGON_TYPE   = 24

%TT_PRIM_LINE      = 1
%TT_PRIM_QSPLINE   = 2
%TT_PRIM_CSPLINE   = 3

TYPE POINTFX
    x AS FIXED
    y AS FIXED
END TYPE

TYPE TTPOLYCURVE
    wType   AS WORD
    cpfx    AS WORD
    apfx(0) AS POINTFX
END TYPE

TYPE TTPOLYGONHEADER
    cb       AS DWORD
    dwType   AS DWORD
    pfxStart AS POINTFX
END TYPE

#IF (%WINVER >= &H0400)
%GCP_DBCS           = &H0001
%GCP_REORDER        = &H0002
%GCP_USEKERNING     = &H0008
%GCP_GLYPHSHAPE     = &H0010
%GCP_LIGATE         = &H0020
'%GCP_GLYPHINDEXING  = &H0080
%GCP_DIACRITIC      = &H0100
%GCP_KASHIDA        = &H0400
%GCP_ERROR          = &H8000??
%FLI_MASK           = &H103B

%GCP_JUSTIFY         = &H00010000
'%GCP_NODIACRITICS    = &H00020000
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

%GCPCLASS_LATIN                  = 1
%GCPCLASS_HEBREW                 = 2
%GCPCLASS_ARABIC                 = 2
%GCPCLASS_NEUTRAL                = 3
%GCPCLASS_LOCALNUMBER            = 4
%GCPCLASS_LATINNUMBER            = 5
%GCPCLASS_LATINNUMERICTERMINATOR = 6
%GCPCLASS_LATINNUMERICSEPARATOR  = 7
%GCPCLASS_NUMERICSEPARATOR       = 8
%GCPCLASS_PREBOUNDLTR         = &H80?
%GCPCLASS_PREBOUNDRTL         = &H40
%GCPCLASS_POSTBOUNDLTR        = &H20
%GCPCLASS_POSTBOUNDRTL        = &H10

%GCPGLYPH_LINKBEFORE          = &H8000??
%GCPGLYPH_LINKAFTER           = &H4000

TYPE GCP_RESULTSA
    lStructSize AS DWORD
    lpOutString AS ASCIIZ PTR
    lpOrder     AS DWORD PTR
    lpDx        AS LONG PTR
    lpCaretPos  AS LONG PTR
    lpClass     AS ASCIIZ PTR
    lpGlyphs    AS WSTRINGZ PTR
    nGlyphs     AS DWORD
    nMaxFit     AS LONG
END TYPE

TYPE GCP_RESULTSW
    lStructSize AS DWORD
    lpOutString AS WSTRINGZ PTR
    lpOrder     AS DWORD PTR
    lpDx        AS LONG PTR
    lpCaretPos  AS LONG PTR
    lpClass     AS ASCIIZ PTR
    lpGlyphs    AS WSTRINGZ PTR
    nGlyphs     AS DWORD
    nMaxFit     AS LONG
END TYPE

#IF %DEF(%UNICODE)
TYPE GCP_RESULTS
    GCP_RESULTSW
END TYPE
#ELSE
TYPE GCP_RESULTS
    GCP_RESULTSA
END TYPE
#ENDIF ' UNICODE

#ENDIF ' WINVER >= &H0400

TYPE RASTERIZER_STATUS
    nSize       AS INTEGER
    wFlags      AS INTEGER   ' yes, this is supposed to be a signed integer
    nLanguageID AS INTEGER
END TYPE

' bits defined in wFlags of RASTERIZER_STATUS
%TT_AVAILABLE   = &H0001
%TT_ENABLED     = &H0002

' Pixel format descriptor
TYPE PIXELFORMATDESCRIPTOR
    nSize           AS WORD
    nVersion        AS WORD
    dwFlags         AS DWORD
    iPixelType      AS BYTE
    cColorBits      AS BYTE
    cRedBits        AS BYTE
    cRedShift       AS BYTE
    cGreenBits      AS BYTE
    cGreenShift     AS BYTE
    cBlueBits       AS BYTE
    cBlueShift      AS BYTE
    cAlphaBits      AS BYTE
    cAlphaShift     AS BYTE
    cAccumBits      AS BYTE
    cAccumRedBits   AS BYTE
    cAccumGreenBits AS BYTE
    cAccumBlueBits  AS BYTE
    cAccumAlphaBits AS BYTE
    cDepthBits      AS BYTE
    cStencilBits    AS BYTE
    cAuxBuffers     AS BYTE
    iLayerType      AS BYTE
    bReserved       AS BYTE
    dwLayerMask     AS DWORD
    dwVisibleMask   AS DWORD
    dwDamageMask    AS DWORD
END TYPE

' pixel types
%PFD_TYPE_RGBA       = 0
%PFD_TYPE_COLORINDEX = 1

' layer types
%PFD_MAIN_PLANE      = 0
%PFD_OVERLAY_PLANE   = 1
%PFD_UNDERLAY_PLANE  = -1

' PIXELFORMATDESCRIPTOR flags
%PFD_DOUBLEBUFFER           = &H00000001
%PFD_STEREO                 = &H00000002
%PFD_DRAW_TO_WINDOW         = &H00000004
%PFD_DRAW_TO_BITMAP         = &H00000008
%PFD_SUPPORT_GDI            = &H00000010
%PFD_SUPPORT_OPENGL         = &H00000020
%PFD_GENERIC_FORMAT         = &H00000040
%PFD_NEED_PALETTE           = &H00000080
%PFD_NEED_SYSTEM_PALETTE    = &H00000100
%PFD_SWAP_EXCHANGE          = &H00000200
%PFD_SWAP_COPY              = &H00000400
%PFD_SWAP_LAYER_BUFFERS     = &H00000800
%PFD_GENERIC_ACCELERATED    = &H00001000
%PFD_SUPPORT_DIRECTDRAW     = &H00002000
%PFD_DIRECT3D_ACCELERATED   = &H00004000
%PFD_SUPPORT_COMPOSITION    = &H00008000

' PIXELFORMATDESCRIPTOR flags for use in ChoosePixelFormat only
%PFD_DEPTH_DONTCARE         = &H20000000
%PFD_DOUBLEBUFFER_DONTCARE  = &H40000000
%PFD_STEREO_DONTCARE        = &H80000000???

#IF NOT %DEF(%NOTEXTMETRIC)

DECLARE FUNCTION OLDFONTENUMPROCA (xlf AS LOGFONTA, xtm AS TEXTMETRICA, _
    BYVAL dwd AS DWORD, BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION OLDFONTENUMPROCW (xlf AS LOGFONTW, xtm AS TEXTMETRICW, _
    BYVAL dwd AS DWORD, BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO OLDFONTENUMPROC=OLDFONTENUMPROCW
#ELSE
MACRO OLDFONTENUMPROC=OLDFONTENUMPROCA
#ENDIF ' NOT UNICODE

#ELSE

DECLARE FUNCTION OLDFONTENUMPROCA (xlf AS LOGFONTA, pv AS ANY, _
    BYVAL dwd AS DWORD, BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION OLDFONTENUMPROCW (xlf AS LOGFONTW, pv AS ANY, _
    BYVAL dwd AS DWORD, BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO OLDFONTENUMPROC=OLDFONTENUMPROCW
#ELSE
MACRO OLDFONTENUMPROC=OLDFONTENUMPROCA
#ENDIF ' NOT UNICODE

#ENDIF

MACRO FONTENUMPROCA=OLDFONTENUMPROCA
MACRO FONTENUMPROCW=OLDFONTENUMPROCW
#IF %DEF(%UNICODE)
MACRO FONTENUMPROC=FONTENUMPROCW
#ELSE
MACRO FONTENUMPROC=FONTENUMPROCA
#ENDIF ' UNICODE

DECLARE FUNCTION GOBJENUMPROC (lpv AS ANY, BYVAL lParam AS LONG) AS LONG

DECLARE SUB LINEDDAPROC (BYVAL i1 AS LONG, BYVAL i2 AS LONG, _
    BYVAL lParam AS LONG)


DECLARE FUNCTION AddFontResourceA LIB "GDI32.DLL" ALIAS "AddFontResourceA" _
    (lpFileName AS ASCIIZ) AS LONG

DECLARE FUNCTION AddFontResourceW LIB "GDI32.DLL" ALIAS "AddFontResourceW" _
    (lpFileName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO AddFontResource=AddFontResourceW
#ELSE
MACRO AddFontResource=AddFontResourceA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION AnimatePalette LIB "GDI32.DLL" ALIAS "AnimatePalette" _
    (BYVAL hPalette AS DWORD, BYVAL wStartIndex AS DWORD, _
    BYVAL wNumEntries AS DWORD, lpPaletteColors AS PALETTEENTRY) AS LONG

DECLARE FUNCTION ARC LIB "GDI32.DLL" ALIAS "Arc" (BYVAL hdc AS DWORD, _
    BYVAL X1 AS LONG, BYVAL Y1 AS LONG, BYVAL X2 AS LONG, BYVAL Y2 AS LONG, _
    BYVAL X3 AS LONG, BYVAL Y3 AS LONG, BYVAL X4 AS LONG, BYVAL Y4 AS LONG) _
    AS LONG

DECLARE FUNCTION BitBlt LIB "GDI32.DLL" ALIAS "BitBlt" _
    (BYVAL hDestDC AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL hSrcDC AS DWORD, _
    BYVAL xSrc AS LONG, BYVAL ySrc AS LONG, BYVAL dwRop AS DWORD) AS LONG

DECLARE FUNCTION CancelDC LIB "GDI32.DLL" ALIAS "CancelDC" _
    (BYVAL hdc AS DWORD) AS LONG

DECLARE FUNCTION Chord LIB "GDI32.DLL" ALIAS "Chord" (BYVAL hdc AS DWORD, _
    BYVAL X1 AS LONG, BYVAL Y1 AS LONG, BYVAL X2 AS LONG, BYVAL Y2 AS LONG, _
    BYVAL X3 AS LONG, BYVAL Y3 AS LONG, BYVAL X4 AS LONG, BYVAL Y4 AS LONG) _
    AS LONG

DECLARE FUNCTION ChoosePixelFormat LIB "GDI32.DLL" ALIAS "ChoosePixelFormat" _
    (BYVAL hDC AS DWORD, pPixelFormatDescriptor AS PIXELFORMATDESCRIPTOR) _
    AS LONG

DECLARE FUNCTION CloseMetaFile LIB "GDI32.DLL" ALIAS "CloseMetaFile" _
    (BYVAL hMF AS DWORD) AS DWORD

DECLARE FUNCTION CombineRgn LIB "GDI32.DLL" ALIAS "CombineRgn" _
    (BYVAL hDestRgn AS DWORD, BYVAL hSrcRgn1 AS DWORD, _
    BYVAL hSrcRgn2 AS DWORD, BYVAL nCombineMode AS LONG) AS LONG

DECLARE FUNCTION CopyMetaFileA LIB "GDI32.DLL" ALIAS "CopyMetaFileA" _
    (BYVAL hMF AS DWORD, lpFileName AS ASCIIZ) AS DWORD

DECLARE FUNCTION CopyMetaFileW LIB "GDI32.DLL" ALIAS "CopyMetaFileW" _
    (BYVAL hMF AS DWORD, lpFileName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
MACRO CopyMetaFile=CopyMetaFileW
#ELSE
MACRO CopyMetaFile=CopyMetaFileA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CreateBitmap LIB "GDI32.DLL" ALIAS "CreateBitmap" _
    (BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL nPlanes AS DWORD, _
    BYVAL nBitCount AS DWORD, lpBits AS DWORD) AS DWORD

DECLARE FUNCTION CreateBitmapIndirect LIB "GDI32.DLL" _
    ALIAS "CreateBitmapIndirect" (lpBitmap AS BITMAP) AS DWORD

DECLARE FUNCTION CreateBrushIndirect LIB "GDI32.DLL" _
    ALIAS "CreateBrushIndirect" (lpLogBrush AS LOGBRUSH) AS DWORD

DECLARE FUNCTION CreateCompatibleBitmap LIB "GDI32.DLL" _
    ALIAS "CreateCompatibleBitmap" (BYVAL hdc AS DWORD, BYVAL nWidth AS LONG, _
    BYVAL nHeight AS LONG) AS DWORD

DECLARE FUNCTION CreateDiscardableBitmap LIB "GDI32.DLL" _
    ALIAS "CreateDiscardableBitmap" (BYVAL hdc AS DWORD, _
    BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS DWORD

DECLARE FUNCTION CreateCompatibleDC LIB "GDI32.DLL" _
    ALIAS "CreateCompatibleDC" (BYVAL hdc AS DWORD) AS DWORD

DECLARE FUNCTION CreateDCA LIB "GDI32.DLL" ALIAS "CreateDCA" _
    (lpDriverName AS ASCIIZ, lpDeviceName AS ASCIIZ, lpOutput AS ASCIIZ, _
    lpInitData AS DEVMODEA) AS DWORD

DECLARE FUNCTION CreateDCW LIB "GDI32.DLL" ALIAS "CreateDCW" _
    (lpDriverName AS WSTRINGZ, lpDeviceName AS WSTRINGZ, _
    lpOutput AS WSTRINGZ, lpInitData AS DEVMODEW) AS DWORD

#IF %DEF(%UNICODE)
MACRO CreateDC=CreateDCW
#ELSE
MACRO CreateDC=CreateDCA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CreateDIBitmap LIB "GDI32.DLL" ALIAS "CreateDIBitmap" _
    (BYVAL hdc AS DWORD, lpInfoHeader AS BITMAPINFOHEADER, _
    BYVAL dwUsage AS DWORD, lpInitBits AS ANY, lpInitInfo AS BITMAPINFO, _
    BYVAL wUsage AS DWORD) AS DWORD

DECLARE FUNCTION CreateDIBPatternBrush LIB "GDI32.DLL" _
    ALIAS "CreateDIBPatternBrush" (BYVAL hPackedDIB AS DWORD, _
    BYVAL wUsage AS DWORD) AS DWORD

DECLARE FUNCTION CreateDIBPatternBrushPt LIB "GDI32.DLL" _
    ALIAS "CreateDIBPatternBrushPt" (lpPackedDIB AS ANY, _
    BYVAL iUsage AS DWORD) AS DWORD

DECLARE FUNCTION CreateEllipticRgn LIB "GDI32.DLL" ALIAS "CreateEllipticRgn" _
    (BYVAL X1 AS LONG, BYVAL Y1 AS LONG, BYVAL X2 AS LONG, BYVAL Y2 AS LONG) _
    AS DWORD

DECLARE FUNCTION CreateEllipticRgnIndirect LIB "GDI32.DLL" _
    ALIAS "CreateEllipticRgnIndirect" (lpRect AS RECT) AS DWORD

DECLARE FUNCTION CreateFontIndirectA LIB "GDI32.DLL" _
    ALIAS "CreateFontIndirectA" (lpLogFont AS LOGFONTA) AS DWORD

DECLARE FUNCTION CreateFontIndirectW LIB "GDI32.DLL" _
    ALIAS "CreateFontIndirectW" (lpLogFont AS LOGFONTW) AS DWORD

#IF %DEF(%UNICODE)
MACRO CreateFontIndirect=CreateFontIndirectW
#ELSE
MACRO CreateFontIndirect=CreateFontIndirectA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CreateFontA LIB "GDI32.DLL" ALIAS "CreateFontA" _
    (BYVAL nHeight AS LONG, BYVAL nWidth AS LONG, BYVAL nEscapement AS LONG, _
    BYVAL nOrientation AS LONG, BYVAL fnWeight AS LONG, _
    BYVAL fdwItalic AS DWORD, BYVAL fdwUnderline AS DWORD, _
    BYVAL fdwStrikeOut AS DWORD, BYVAL fdwCharSet AS DWORD, _
    BYVAL fdwOutputPrecision AS DWORD, BYVAL fdwClipPrecision AS DWORD, _
    BYVAL fdwQuality AS DWORD, BYVAL fdwPitchAndFamily AS DWORD, _
    lpszFace AS ASCIIZ) AS DWORD

DECLARE FUNCTION CreateFontW LIB "GDI32.DLL" ALIAS "CreateFontW" _
    (BYVAL nHeight AS LONG, BYVAL nWidth AS LONG, BYVAL nEscapement AS LONG, _
    BYVAL nOrientation AS LONG, BYVAL fnWeight AS LONG, _
    BYVAL fdwItalic AS DWORD, BYVAL fdwUnderline AS DWORD, _
    BYVAL fdwStrikeOut AS DWORD, BYVAL fdwCharSet AS DWORD, _
    BYVAL fdwOutputPrecision AS DWORD, BYVAL fdwClipPrecision AS DWORD, _
    BYVAL fdwQuality AS DWORD, BYVAL fdwPitchAndFamily AS DWORD, _
    lpszFace AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
MACRO CreateFont=CreateFontW
#ELSE
MACRO CreateFont=CreateFontA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CreateHatchBrush LIB "GDI32.DLL" ALIAS "CreateHatchBrush" _
    (BYVAL nIndex AS LONG, BYVAL crColor AS DWORD) AS DWORD

DECLARE FUNCTION CreateICA LIB "GDI32.DLL" ALIAS "CreateICA" _
    (lpDriverName AS ASCIIZ, lpDeviceName AS ASCIIZ, lpOutput AS ASCIIZ, _
    lpInitData AS DEVMODEA) AS DWORD

DECLARE FUNCTION CreateICW LIB "GDI32.DLL" ALIAS "CreateICW" _
    (lpDriverName AS WSTRINGZ, lpDeviceName AS WSTRINGZ, _
    lpOutput AS WSTRINGZ, lpInitData AS DEVMODEW) AS DWORD

#IF %DEF(%UNICODE)
MACRO CreateIC=CreateICW
#ELSE
MACRO CreateIC=CreateICA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CreateMetaFileA LIB "GDI32.DLL" ALIAS "CreateMetaFileA" _
    (lpString AS ASCIIZ) AS DWORD

DECLARE FUNCTION CreateMetaFileW LIB "GDI32.DLL" ALIAS "CreateMetaFileW" _
    (lpString AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
MACRO CreateMetaFile=CreateMetaFileW
#ELSE
MACRO CreateMetaFile=CreateMetaFileA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CreatePalette LIB "GDI32.DLL" ALIAS "CreatePalette" _
    (BYVAL lpLogPalette AS DWORD) AS DWORD

DECLARE FUNCTION CreatePen LIB "GDI32.DLL" ALIAS "CreatePen" _
    (BYVAL nPenStyle AS LONG, BYVAL nWidth AS LONG, BYVAL crColor AS DWORD) _
    AS DWORD

DECLARE FUNCTION CreatePenIndirect LIB "GDI32.DLL" ALIAS "CreatePenIndirect" _
    (lpLogPen AS LOGPEN) AS DWORD

DECLARE FUNCTION CreatePolyPolygonRgn LIB "GDI32.DLL" _
    ALIAS "CreatePolyPolygonRgn" (lpPoint AS POINT, lpPolyCounts AS LONG, _
    BYVAL nCount AS LONG, BYVAL nPolyFillMode AS LONG) AS DWORD

DECLARE FUNCTION CreatePatternBrush LIB "GDI32.DLL" _
    ALIAS "CreatePatternBrush" (BYVAL hBitmap AS DWORD) AS DWORD

DECLARE FUNCTION CreateRectRgn LIB "GDI32.DLL" ALIAS "CreateRectRgn" _
    (BYVAL X1 AS LONG, BYVAL Y1 AS LONG, BYVAL X2 AS LONG, BYVAL Y2 AS LONG) _
    AS DWORD

DECLARE FUNCTION CreateRectRgnIndirect LIB "GDI32.DLL" _
    ALIAS "CreateRectRgnIndirect" (lpRect AS RECT) AS DWORD

DECLARE FUNCTION CreateRoundRectRgn LIB "GDI32.DLL" _
    ALIAS "CreateRoundRectRgn" (BYVAL X1 AS LONG, BYVAL Y1 AS LONG, _
    BYVAL X2 AS LONG, BYVAL Y2 AS LONG, BYVAL X3 AS LONG, BYVAL Y3 AS LONG) _
    AS DWORD

DECLARE FUNCTION CreateScalableFontResourceA LIB "GDI32.DLL" _
    ALIAS "CreateScalableFontResourceA" (BYVAL fHidden AS DWORD, _
    lpszResourceFile AS ASCIIZ, lpszFontFile AS ASCIIZ, _
    lpszCurrentPath AS ASCIIZ) AS LONG

DECLARE FUNCTION CreateScalableFontResourceW LIB "GDI32.DLL" _
    ALIAS "CreateScalableFontResourceW" (BYVAL fHidden AS DWORD, _
    lpszResourceFile AS WSTRINGZ, lpszFontFile AS WSTRINGZ, _
    lpszCurrentPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO CreateScalableFontResource=CreateScalableFontResourceW
#ELSE
MACRO CreateScalableFontResource=CreateScalableFontResourceA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CreateSolidBrush LIB "GDI32.DLL" ALIAS "CreateSolidBrush" _
    (BYVAL crColor AS DWORD) AS DWORD

DECLARE FUNCTION DeleteDC LIB "GDI32.DLL" ALIAS "DeleteDC" _
    (BYVAL hdc AS DWORD) AS LONG

DECLARE FUNCTION DeleteMetaFile LIB "GDI32.DLL" ALIAS "DeleteMetaFile" _
    (BYVAL hMF AS DWORD) AS LONG

DECLARE FUNCTION DeleteObject LIB "GDI32.DLL" ALIAS "DeleteObject" _
    (BYVAL hObject AS DWORD) AS LONG

DECLARE FUNCTION DescribePixelFormat LIB "GDI32.DLL" _
    ALIAS "DescribePixelFormat" (BYVAL hDC AS DWORD, _
    BYVAL iPixelFormat AS LONG, BYVAL nBytes AS DWORD, _
    ppfd AS PIXELFORMATDESCRIPTOR) AS LONG

' define types of pointers to ExtDeviceMode() and DeviceCapabilities()
' functions for Win 3.1 compatibility
'
DECLARE FUNCTION LPFNDEVMODE (BYVAL hwnd AS DWORD, BYVAL hModule AS DWORD, _
    lpsz1 AS ASCIIZ, lpsz2 AS ASCIIZ, BYVAL lpdm AS DWORD, lpsz2 AS ASCIIZ, _
    BYVAL lpdw AS DWORD) AS DWORD

DECLARE FUNCTION LPFNDEVCAPS (lpsz1 AS ASCIIZ, lpsz2 AS ASCIIZ, _
    BYVAL dwd AS DWORD, lpsz3 AS ASCIIZ, BYVAL lpdm AS DWORD) AS DWORD

' mode selections for the device mode function
%DM_UPDATE           = 1
%DM_COPY             = 2
%DM_PROMPT           = 4
%DM_MODIFY           = 8

%DM_IN_BUFFER        = %DM_MODIFY
%DM_IN_PROMPT        = %DM_PROMPT
%DM_OUT_BUFFER       = %DM_COPY
%DM_OUT_DEFAULT      = %DM_UPDATE

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
#IF (%WINVER >= &H0400)
%DC_BINADJUST         = 19
%DC_EMF_COMPLIANT     = 20
%DC_DATATYPE_PRODUCED = 21
%DC_COLLATE           = 22
%DC_MANUFACTURER      = 23
%DC_MODEL             = 24
#ENDIF ' WINVER >= &H0400

#IF (%WINVER >= &H0500)
%DC_PERSONALITY       = 25
%DC_PRINTRATE         = 26
%DC_PRINTRATEUNIT     = 27
%PRINTRATEUNIT_PPM  = 1
%PRINTRATEUNIT_CPS  = 2
%PRINTRATEUNIT_LPM  = 3
%PRINTRATEUNIT_IPM  = 4
%DC_PRINTERMEM        = 28
%DC_MEDIAREADY        = 29
%DC_STAPLE            = 30
%DC_PRINTRATEPPM      = 31
%DC_COLORDEVICE       = 32
%DC_NUP               = 33
#IF (%WIN32_WINNT >= %WIN32_WINNT_WIN2K)
%DC_MEDIATYPENAMES    = 34
%DC_MEDIATYPES        = 35
#ENDIF ' (%WIN32_WINNT >= %WIN32_WINNT_WIN2K)
#ENDIF ' WINVER >= &H0500

' bit fields of the return value (DWORD) for DC_TRUETYPE
%DCTT_BITMAP           = &H0000001
%DCTT_DOWNLOAD         = &H0000002
%DCTT_SUBDEV           = &H0000004
#IF (%WINVER >= &H0400)
%DCTT_DOWNLOAD_OUTLINE = &H0000008

' return values for DC_BINADJUST
%DCBA_FACEUPNONE     = &H0000
%DCBA_FACEUPCENTER   = &H0001
%DCBA_FACEUPLEFT     = &H0002
%DCBA_FACEUPRIGHT    = &H0003
%DCBA_FACEDOWNNONE   = &H0100
%DCBA_FACEDOWNCENTER = &H0101
%DCBA_FACEDOWNLEFT   = &H0102
%DCBA_FACEDOWNRIGHT  = &H0103
#ENDIF ' WINVER >= &H0400

DECLARE FUNCTION DeviceCapabilitiesA LIB "WINSPOOL.DRV" _
    ALIAS "DeviceCapabilitiesA" (lpDeviceName AS ASCIIZ, lpPort AS ASCIIZ, _
    BYVAL iIndex AS WORD, lpOutput AS ASCIIZ, lpDevMode AS DEVMODE) AS LONG

DECLARE FUNCTION DeviceCapabilitiesW LIB "WINSPOOL.DRV" _
    ALIAS "DeviceCapabilitiesW" (lpDeviceName AS WSTRINGZ, _
    lpPort AS WSTRINGZ, BYVAL iIndex AS WORD, lpOutput AS WSTRINGZ, _
    lpDevMode AS DEVMODE) AS LONG

#IF %DEF(%UNICODE)
MACRO DeviceCapabilities=DeviceCapabilitiesW
#ELSE
MACRO DeviceCapabilities=DeviceCapabilitiesA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DrawEscape LIB "GDI32.DLL" ALIAS "DrawEscape" _
    (BYVAL hdc AS DWORD, BYVAL nEscape AS LONG, BYVAL cbInput AS LONG, _
    BYVAL lpszInData AS BYTE PTR) AS LONG

DECLARE FUNCTION ELLIPSE LIB "GDI32.DLL" ALIAS "Ellipse" (BYVAL hdc AS DWORD, _
    BYVAL X1 AS LONG, BYVAL Y1 AS LONG, BYVAL X2 AS LONG, BYVAL Y2 AS LONG) _
    AS LONG

#IF (%WINVER >= &H0400)

DECLARE FUNCTION EnumFontFamiliesExA LIB "GDI32.DLL" _
    ALIAS "EnumFontFamiliesExA" (BYVAL hdc AS DWORD, lpLogFont AS LOGFONTA, _
    BYVAL lpEnumFontProcA AS DWORD, BYVAL lParam AS LONG, BYVAL DW AS DWORD) _
    AS LONG

DECLARE FUNCTION EnumFontFamiliesExW LIB "GDI32.DLL" _
    ALIAS "EnumFontFamiliesExW" (BYVAL hdc AS DWORD, lpLogFont AS LOGFONTW, _
    BYVAL lpEnumFontProcW AS DWORD, BYVAL lParam AS LONG, BYVAL DW AS DWORD) _
    AS LONG

#IF %DEF(%UNICODE)
MACRO EnumFontFamiliesEx=EnumFontFamiliesExW
#ELSE
MACRO EnumFontFamiliesEx=EnumFontFamiliesExA
#ENDIF ' NOT %UNICODE

#ENDIF ' %WINVER >= &H0400

DECLARE FUNCTION EnumFontFamiliesA LIB "GDI32.DLL" ALIAS "EnumFontFamiliesA" _
    (BYVAL hdc AS DWORD, lpszFamily AS ASCIIZ, _
    BYVAL lpEnumFontFamProcA AS DWORD, BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION EnumFontFamiliesW LIB "GDI32.DLL" ALIAS "EnumFontFamiliesW" _
    (BYVAL hdc AS DWORD, lpszFamily AS WSTRINGZ, _
    BYVAL lpEnumFontFamProcW AS DWORD, BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO EnumFontFamilies=EnumFontFamiliesW
#ELSE
MACRO EnumFontFamilies=EnumFontFamiliesA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumFontsA LIB "GDI32.DLL" ALIAS "EnumFontsA" _
    (BYVAL hDC AS DWORD, lpsz AS ASCIIZ, BYVAL lpFontEnumProcA AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION EnumFontsW LIB "GDI32.DLL" ALIAS "EnumFontsW" _
    (BYVAL hDC AS DWORD, lpsz AS WSTRINGZ, BYVAL lpFontEnumProcW AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO EnumFonts=EnumFontsW
#ELSE
MACRO EnumFonts=EnumFontsA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumObjects LIB "GDI32.DLL" ALIAS "EnumObjects" _
    (BYVAL hDC AS DWORD, BYVAL n AS LONG, BYVAL lpGOBJEnumProc AS DWORD, _
    BYVAL lpVoid AS DWORD) AS LONG

DECLARE FUNCTION EqualRgn LIB "GDI32.DLL" ALIAS "EqualRgn" _
    (BYVAL hSrcRgn1 AS DWORD, BYVAL hSrcRgn2 AS DWORD) AS LONG

DECLARE FUNCTION Escape LIB "GDI32.DLL" ALIAS "Escape" (BYVAL hdc AS DWORD, _
    BYVAL nEscape AS LONG, BYVAL nCount AS LONG, lpInData AS ASCIIZ, _
    lpOutData AS ANY) AS LONG

DECLARE FUNCTION ExtEscape LIB "GDI32.DLL" ALIAS "ExtEscape" _
    (BYVAL hdc AS DWORD, BYVAL nEscape AS LONG, BYVAL cbInput AS LONG, _
    lpszInData AS ASCIIZ, BYVAL cbOutput AS LONG, lpszOutData AS ASCIIZ) _
    AS LONG

DECLARE FUNCTION ExcludeClipRect LIB "GDI32.DLL" ALIAS "ExcludeClipRect" _
    (BYVAL hdc AS DWORD, BYVAL X1 AS LONG, BYVAL Y1 AS LONG, _
    BYVAL X2 AS LONG, BYVAL Y2 AS LONG) AS LONG

DECLARE FUNCTION ExtCreateRegion LIB "GDI32.DLL" ALIAS "ExtCreateRegion" _
    (lpXform AS xform, BYVAL nCount AS DWORD, lpRgnData AS ANY) AS DWORD

DECLARE FUNCTION ExtFloodFill LIB "GDI32.DLL" ALIAS "ExtFloodFill" _
    (BYVAL hdc AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    BYVAL crColor AS DWORD, BYVAL wFillType AS DWORD) AS LONG

DECLARE FUNCTION FillRgn LIB "GDI32.DLL" ALIAS "FillRgn" _
    (BYVAL hdc AS DWORD, BYVAL hRgn AS DWORD, BYVAL hBrush AS DWORD) AS LONG

DECLARE FUNCTION FloodFill LIB "GDI32.DLL" ALIAS "FloodFill" _
    (BYVAL hdc AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    BYVAL crColor AS DWORD) AS LONG

DECLARE FUNCTION FrameRgn LIB "GDI32.DLL" ALIAS "FrameRgn" _
    (BYVAL hdc AS DWORD, BYVAL hRgn AS DWORD, BYVAL hBrush AS DWORD, _
    BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS LONG

DECLARE FUNCTION GetROP2 LIB "GDI32.DLL" ALIAS "GetROP2" (BYVAL hdc AS DWORD) _
    AS LONG

DECLARE FUNCTION GetAspectRatioFilterEx LIB "GDI32.DLL" _
    ALIAS "GetAspectRatioFilterEx" (BYVAL hdc AS DWORD, _
    lpAspectRatio AS SIZEL) AS LONG

DECLARE FUNCTION GetBkColor LIB "GDI32.DLL" ALIAS "GetBkColor" _
    (BYVAL hdc AS DWORD) AS COLORREF

#IF (%WIN32_WINNT >= %WIN32_WINNT_WIN2K)

DECLARE FUNCTION GetDCBrushColor LIB "GDI32.DLL" ALIAS "GetDCBrushColor" _
    (BYVAL hdc AS DWORD) AS COLORREF

DECLARE FUNCTION GetDCPenColor LIB "GDI32.DLL" ALIAS "GetDCPenColor" _
    (BYVAL hdc AS DWORD) AS COLORREF

#ENDIF

DECLARE FUNCTION GetBkMode LIB "GDI32.DLL" ALIAS "GetBkMode" _
    (BYVAL hdc AS DWORD) AS LONG

DECLARE FUNCTION GetBitmapBits LIB "GDI32.DLL" ALIAS "GetBitmapBits" _
    (BYVAL hBitmap AS DWORD, BYVAL cbBuffer AS LONG, lpBits AS ANY) AS LONG

DECLARE FUNCTION GetBitmapDimensionEx LIB "GDI32.DLL" _
    ALIAS "GetBitmapDimensionEx" (BYVAL hBitmap AS DWORD, _
    lpDimension AS SIZEL) AS LONG

DECLARE FUNCTION GetBoundsRect LIB "GDI32.DLL" ALIAS "GetBoundsRect" _
    (BYVAL hdc AS DWORD, lprcBounds AS RECT, BYVAL flags AS DWORD) AS DWORD

DECLARE FUNCTION GetBrushOrgEx LIB "GDI32.DLL" ALIAS "GetBrushOrgEx" _
    (BYVAL hDC AS DWORD, lpPoint AS POINT) AS LONG

DECLARE FUNCTION GetCharWidthA LIB "GDI32.DLL" ALIAS "GetCharWidthA" _
    (BYVAL hdc AS DWORD, BYVAL dFirstChar AS DWORD, BYVAL dLastChar AS DWORD, _
    lpBuffer AS LONG) AS LONG

DECLARE FUNCTION GetCharWidthW LIB "GDI32.DLL" ALIAS "GetCharWidthW" _
    (BYVAL hdc AS DWORD, BYVAL dFirstChar AS DWORD, BYVAL dLastChar AS DWORD, _
    lpBuffer AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO GetCharWidth=GetCharWidthW
#ELSE
MACRO GetCharWidth=GetCharWidthA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetCharWidth32A LIB "GDI32.DLL" ALIAS "GetCharWidth32A" _
    (BYVAL hdc AS DWORD, BYVAL dFirstChar AS DWORD, BYVAL dLastChar AS DWORD, _
    lpBuffer AS LONG) AS LONG

DECLARE FUNCTION GetCharWidth32W LIB "GDI32.DLL" ALIAS "GetCharWidth32W" _
    (BYVAL hdc AS DWORD, BYVAL dFirstChar AS DWORD, BYVAL dLastChar AS DWORD, _
    lpBuffer AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO GetCharWidth32=GetCharWidth32W
#ELSE
MACRO GetCharWidth32=GetCharWidth32A
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetCharWidthFloatA LIB "GDI32.DLL" _
    ALIAS "GetCharWidthFloatA" (BYVAL hdc AS DWORD, _
    BYVAL dFirstChar AS DWORD, BYVAL dLastChar AS DWORD, _
    BYVAL pxBuffer AS SINGLE PTR) AS LONG

DECLARE FUNCTION GetCharWidthFloatW LIB "GDI32.DLL" _
    ALIAS "GetCharWidthFloatW" (BYVAL hdc AS DWORD, _
    BYVAL dFirstChar AS DWORD, BYVAL dLastChar AS DWORD, _
    BYVAL pxBuffer AS SINGLE PTR) AS LONG

#IF %DEF(%UNICODE)
MACRO GetCharWidthFloat=GetCharWidthFloatW
#ELSE
MACRO GetCharWidthFloat=GetCharWidthFloatA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetCharABCWidthsA LIB "GDI32.DLL" ALIAS "GetCharABCWidthsA" _
    (BYVAL hdc AS DWORD, BYVAL dFirstChar AS DWORD, BYVAL dLastChar AS DWORD, _
    lpabc AS ABC) AS LONG

DECLARE FUNCTION GetCharABCWidthsW LIB "GDI32.DLL" ALIAS "GetCharABCWidthsW" _
    (BYVAL hdc AS DWORD, BYVAL dFirstChar AS DWORD, BYVAL dLastChar AS DWORD, _
    lpabc AS ABC) AS LONG

#IF %DEF(%UNICODE)
MACRO GetCharABCWidths=GetCharABCWidthsW
#ELSE
MACRO GetCharABCWidths=GetCharABCWidthsA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetCharABCWidthsFloatA LIB "GDI32.DLL" _
    ALIAS "GetCharABCWidthsFloatA" (BYVAL hdc AS DWORD, _
    BYVAL dFirstChar AS DWORD, BYVAL dLastChar AS DWORD, _
    lpABCF AS ABCFLOAT) AS LONG

DECLARE FUNCTION GetCharABCWidthsFloatW LIB "GDI32.DLL" _
    ALIAS "GetCharABCWidthsFloatW" (BYVAL hdc AS DWORD, _
    BYVAL dFirstChar AS DWORD, BYVAL dLastChar AS DWORD, _
    lpABCF AS ABCFLOAT) AS LONG

#IF %DEF(%UNICODE)
MACRO GetCharABCWidthsFloat=GetCharABCWidthsFloatW
#ELSE
MACRO GetCharABCWidthsFloat=GetCharABCWidthsFloatA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetClipBox LIB "GDI32.DLL" ALIAS "GetClipBox" _
    (BYVAL hdc AS DWORD, lpRect AS RECT) AS LONG

DECLARE FUNCTION GetClipRgn LIB "GDI32.DLL" ALIAS "GetClipRgn" _
    (BYVAL hdc AS DWORD, BYVAL hRgn AS DWORD) AS LONG

DECLARE FUNCTION GetMetaRgn LIB "GDI32.DLL" ALIAS "GetMetaRgn" _
    (BYVAL hdc AS DWORD, BYVAL hRgn AS DWORD) AS LONG

DECLARE FUNCTION GetCurrentObject LIB "GDI32.DLL" ALIAS "GetCurrentObject" _
    (BYVAL hdc AS DWORD, BYVAL uObjectType AS DWORD) AS DWORD

DECLARE FUNCTION GetCurrentPositionEx LIB "GDI32.DLL" _
    ALIAS "GetCurrentPositionEx" (BYVAL hdc AS DWORD, lpPoint AS POINT) AS LONG

DECLARE FUNCTION GetDeviceCaps LIB "GDI32.DLL" ALIAS "GetDeviceCaps" _
    (BYVAL hdc AS DWORD, BYVAL nIndex AS LONG) AS LONG

DECLARE FUNCTION GetDIBits LIB "GDI32.DLL" ALIAS "GetDIBits" _
    (BYVAL hdc AS DWORD, BYVAL hBitmap AS DWORD, BYVAL nStartScan AS DWORD, _
    BYVAL nNumScans AS DWORD, lpBits AS ANY, lpBI AS BITMAPINFO, _
    BYVAL wUsage AS DWORD) AS LONG

DECLARE FUNCTION GetFontData LIB "GDI32.DLL" ALIAS "GetFontData" _
    (BYVAL hdc AS DWORD, BYVAL dwTable AS DWORD, BYVAL dwOffset AS DWORD, _
    lpvBuffer AS ANY, BYVAL cbData AS DWORD) AS DWORD

DECLARE FUNCTION GetGlyphOutlineA LIB "GDI32.DLL" ALIAS "GetGlyphOutlineA" _
    (BYVAL hdc AS DWORD, BYVAL uChar AS DWORD, BYVAL ufFormat AS DWORD, _
    lpgm AS GLYPHMETRICS, BYVAL cbBuffer AS DWORD, lpBuffer AS ANY, _
    lpmat2 AS MAT2) AS DWORD

DECLARE FUNCTION GetGlyphOutlineW LIB "GDI32.DLL" ALIAS "GetGlyphOutlineW" _
    (BYVAL hdc AS DWORD, BYVAL uChar AS DWORD, BYVAL ufFormat AS DWORD, _
    lpgm AS GLYPHMETRICS, BYVAL cbBuffer AS DWORD, lpBuffer AS ANY, _
    lpmat2 AS MAT2) AS DWORD

#IF %DEF(%UNICODE)
MACRO GetGlyphOutline=GetGlyphOutlineW
#ELSE
MACRO GetGlyphOutline=GetGlyphOutlineA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetGraphicsMode LIB "GDI32.DLL" ALIAS "GetGraphicsMode" _
    (BYVAL hdc AS DWORD) AS LONG

DECLARE FUNCTION GetMapMode LIB "GDI32.DLL" ALIAS "GetMapMode" _
    (BYVAL hdc AS DWORD) AS LONG

DECLARE FUNCTION GetMetaFileBitsEx LIB "GDI32.DLL" ALIAS "GetMetaFileBitsEx" _
    (BYVAL hMF AS DWORD, BYVAL nSize AS DWORD, lpvData AS ANY) AS DWORD

DECLARE FUNCTION GetMetaFileA LIB "GDI32.DLL" ALIAS "GetMetaFileA" _
    (lpFileName AS ASCIIZ) AS DWORD

DECLARE FUNCTION GetMetaFileW LIB "GDI32.DLL" ALIAS "GetMetaFileW" _
    (lpFileName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
MACRO GetMetaFile=GetMetaFileW
#ELSE
MACRO GetMetaFile=GetMetaFileA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetNearestColor LIB "GDI32.DLL" ALIAS "GetNearestColor" _
    (BYVAL hdc AS DWORD, BYVAL crColor AS DWORD) AS DWORD

DECLARE FUNCTION GetNearestPaletteIndex LIB "GDI32.DLL" _
    ALIAS "GetNearestPaletteIndex" (BYVAL hPalette AS DWORD, _
    BYVAL crColor AS DWORD) AS DWORD

DECLARE FUNCTION GetObjectType LIB "GDI32.DLL" ALIAS "GetObjectType" _
    (BYVAL hgdiobj AS DWORD) AS DWORD


#IF NOT %DEF(%NOTEXTMETRIC)

DECLARE FUNCTION GetOutlineTextMetricsA LIB "GDI32.DLL" _
    ALIAS "GetOutlineTextMetricsA" (BYVAL hdc AS DWORD, _
    BYVAL cbData AS DWORD, lpotm AS OUTLINETEXTMETRICA) AS DWORD

DECLARE FUNCTION GetOutlineTextMetricsW LIB "GDI32.DLL" _
    ALIAS "GetOutlineTextMetricsW" (BYVAL hdc AS DWORD, _
    BYVAL cbData AS DWORD, lpotm AS OUTLINETEXTMETRICW) AS DWORD

#IF %DEF(%UNICODE)
MACRO GetOutlineTextMetrics=GetOutlineTextMetricsW
#ELSE
MACRO GetOutlineTextMetrics=GetOutlineTextMetricsA
#ENDIF ' NOT %UNICODE

#ENDIF ' %NOTEXTMETRIC


DECLARE FUNCTION GetPaletteEntries LIB "GDI32.DLL" ALIAS "GetPaletteEntries" _
    (BYVAL hPalette AS DWORD, BYVAL wStartIndex AS DWORD, _
    BYVAL wNumEntries AS DWORD, lpPaletteEntries AS PALETTEENTRY) AS DWORD

DECLARE FUNCTION GetPixel LIB "GDI32.DLL" ALIAS "GetPixel" _
    (BYVAL hdc AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG) AS DWORD

DECLARE FUNCTION GetPixelFormat LIB "GDI32.DLL" ALIAS "GetPixelFormat" _
    (BYVAL hDC AS DWORD) AS LONG

DECLARE FUNCTION GetPolyFillMode LIB "GDI32.DLL" ALIAS "GetPolyFillMode" _
    (BYVAL hdc AS DWORD) AS LONG

DECLARE FUNCTION GetRasterizerCaps LIB "GDI32.DLL" ALIAS "GetRasterizerCaps" _
    (lpraststat AS RASTERIZER_STATUS, BYVAL cb AS DWORD) AS LONG

DECLARE FUNCTION GetRandomRgn LIB "GDI32.DLL" ALIAS "GetRandomRgn" _
    (BYVAL hdc AS DWORD, BYVAL hrgn AS DWORD, BYVAL i AS LONG) AS LONG

DECLARE FUNCTION GetRegionData LIB "GDI32.DLL" ALIAS "GetRegionData" _
    (BYVAL hRgn AS DWORD, BYVAL dwCount AS DWORD, lpRgnData AS RgnData) AS DWORD

DECLARE FUNCTION GetRgnBox LIB "GDI32.DLL" ALIAS "GetRgnBox" _
    (BYVAL hRgn AS DWORD, lpRect AS RECT) AS LONG

DECLARE FUNCTION GetStockObject LIB "GDI32.DLL" ALIAS "GetStockObject" _
    (BYVAL nIndex AS LONG) AS DWORD

DECLARE FUNCTION GetStretchBltMode LIB "GDI32.DLL" ALIAS "GetStretchBltMode" _
    (BYVAL hdc AS DWORD) AS LONG

DECLARE FUNCTION GetSystemPaletteEntries LIB "GDI32.DLL" _
    ALIAS "GetSystemPaletteEntries" (BYVAL hdc AS DWORD, _
    BYVAL wStartIndex AS DWORD, BYVAL wNumEntries AS DWORD, _
    lpPaletteEntries AS PALETTEENTRY) AS DWORD

DECLARE FUNCTION GetSystemPaletteUse LIB "GDI32.DLL" _
    ALIAS "GetSystemPaletteUse" (BYVAL hdc AS DWORD) AS DWORD

DECLARE FUNCTION GetTextCharacterExtra LIB "GDI32.DLL" _
    ALIAS "GetTextCharacterExtra" (BYVAL hdc AS DWORD) AS LONG

DECLARE FUNCTION GetTextAlign LIB "GDI32.DLL" ALIAS "GetTextAlign" _
    (BYVAL hdc AS DWORD) AS DWORD

DECLARE FUNCTION GetTextColor LIB "GDI32.DLL" ALIAS "GetTextColor" _
    (BYVAL hdc AS DWORD) AS DWORD

DECLARE FUNCTION GetTextExtentPointA LIB "GDI32.DLL" _
    ALIAS "GetTextExtentPointA" (BYVAL hdc AS DWORD, lpszString AS ASCIIZ, _
    BYVAL cbString AS LONG, lpSize AS SIZEL) AS LONG

DECLARE FUNCTION GetTextExtentPointW LIB "GDI32.DLL" _
    ALIAS "GetTextExtentPointW" (BYVAL hdc AS DWORD, lpszString AS WSTRINGZ, _
    BYVAL cbString AS LONG, lpSize AS SIZEL) AS LONG

#IF %DEF(%UNICODE)
MACRO GetTextExtentPoint=GetTextExtentPointW
#ELSE
MACRO GetTextExtentPoint=GetTextExtentPointA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetTextExtentPoint32A LIB "GDI32.DLL" _
    ALIAS "GetTextExtentPoint32A" (BYVAL hdc AS DWORD, lpsz AS ASCIIZ, _
    BYVAL cbString AS LONG, lpSize AS SIZEL) AS LONG

DECLARE FUNCTION GetTextExtentPoint32W LIB "GDI32.DLL" _
    ALIAS "GetTextExtentPoint32W" (BYVAL hdc AS DWORD, lpsz AS WSTRINGZ, _
    BYVAL cbString AS LONG, lpSize AS SIZEL) AS LONG

#IF %DEF(%UNICODE)
MACRO GetTextExtentPoint32=GetTextExtentPoint32W
#ELSE
MACRO GetTextExtentPoint32=GetTextExtentPoint32A
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetTextExtentExPointA LIB "GDI32.DLL" _
    ALIAS "GetTextExtentExPointA" (BYVAL hdc AS DWORD, lpszStr AS ASCIIZ, _
    BYVAL cchString AS LONG, BYVAL nMaxExtent AS LONG, lpnFit AS LONG, _
    alpDx AS LONG, lpSize AS SIZEL) AS LONG

DECLARE FUNCTION GetTextExtentExPointW LIB "GDI32.DLL" _
    ALIAS "GetTextExtentExPointW" (BYVAL hdc AS DWORD, lpszStr AS WSTRINGZ, _
    BYVAL cchString AS LONG, BYVAL nMaxExtent AS LONG, lpnFit AS LONG, _
    alpDx AS LONG, lpSize AS SIZEL) AS LONG

#IF %DEF(%UNICODE)
MACRO GetTextExtentExPoint=GetTextExtentExPointW
#ELSE
MACRO GetTextExtentExPoint=GetTextExtentExPointA
#ENDIF ' NOT %UNICODE

#IF (%WINVER >= &H0400)

DECLARE FUNCTION GetTextCharset LIB "GDI32.DLL" ALIAS "GetTextCharset" _
    (BYVAL hdc AS DWORD) AS LONG

DECLARE FUNCTION GetTextCharsetInfo LIB "GDI32.DLL" _
    ALIAS "GetTextCharsetInfo" (BYVAL hdc AS DWORD, lpSig AS FONTSIGNATURE, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION TranslateCharsetInfo LIB "GDI32.DLL" _
    ALIAS "TranslateCharsetInfo" (lpSrc AS DWORD, lpcs AS CHARSETINFO, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION GetFontLanguageInfo LIB "GDI32.DLL" _
    ALIAS "GetFontLanguageInfo" (BYVAL hdc AS DWORD) AS DWORD

DECLARE FUNCTION GetCharacterPlacementA LIB "GDI32.DLL" _
    ALIAS "GetCharacterPlacementA" (BYVAL hdc AS DWORD, lpsz AS ASCIIZ, _
    BYVAL n1 AS LONG, BYVAL n2 AS LONG, lpGcpResults AS GCP_RESULTSA, _
    BYVAL DW AS DWORD) AS DWORD

DECLARE FUNCTION GetCharacterPlacementW LIB "GDI32.DLL" _
    ALIAS "GetCharacterPlacementW" (BYVAL hdc AS DWORD, lpsz AS WSTRINGZ, _
    BYVAL n1 AS LONG, BYVAL n2 AS LONG, lpGcpResults AS GCP_RESULTSW, _
    BYVAL DW AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
MACRO GetCharacterPlacement=GetCharacterPlacementW
#ELSE
MACRO GetCharacterPlacement=GetCharacterPlacementA
#ENDIF ' NOT %UNICODE

#ENDIF ' WINVER >= &H0400

#IF (%WIN32_WINNT >= %WIN32_WINNT_WIN2K)

TYPE WCRANGE
    wcLow   AS WSTRING * 1
    cGlyphs AS WORD
END TYPE


TYPE GLYPHSET
    cbThis           AS DWORD
    flAccel          AS DWORD
    cGlyphsSupported AS DWORD
    cRanges          AS DWORD
    ranges(0)        AS WCRANGE
END TYPE

' flAccel flags for the GLYPHSET structure above

%GS_8BIT_INDICES   = &H00000001

' flags for GetGlyphIndices

%GGI_MARK_NONEXISTING_GLYPHS = &H0001

DECLARE FUNCTION GetFontUnicodeRanges LIB "GDI32.dll" _
    ALIAS "GetFontUnicodeRanges" (BYVAL hdc AS DWORD, BYVAL lpgs AS DWORD) _
    AS DWORD

DECLARE FUNCTION GetGlyphIndicesA LIB "GDI32.DLL" ALIAS "GetGlyphIndicesA" _
    (BYVAL hdc AS DWORD, lpstr AS ASCIIZ, BYVAL c AS LONG, pgi AS WORD, _
    BYVAL fl AS DWORD) AS DWORD

DECLARE FUNCTION GetGlyphIndicesW LIB "GDI32.DLL" ALIAS "GetGlyphIndicesW" _
    (BYVAL hdc AS DWORD, lpstr AS WSTRINGZ, BYVAL c AS LONG, pgi AS WORD, _
    BYVAL fl AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
MACRO GetGlyphIndices=GetGlyphIndicesW
#ELSE
MACRO GetGlyphIndices=GetGlyphIndicesA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetTextExtentPointI LIB "GDI32.DLL" _
    ALIAS "GetTextExtentPointI" (BYVAL hdc AS DWORD, pgiIn AS WORD, _
    BYVAL cgi AS LONG, lpSize AS SIZEL) AS LONG

DECLARE FUNCTION GetTextExtentExPointI LIB "GDI32.DLL" _
    ALIAS "GetTextExtentExPointI" (BYVAL hdc AS DWORD, pgiIn AS WORD, _
    BYVAL cgi AS LONG, BYVAL nMaxExtent AS LONG, lpnFit AS LONG, _
    alpDx AS LONG, lpSize AS SIZEL) AS LONG

DECLARE FUNCTION GetCharWidthI LIB "GDI32.DLL" ALIAS "GetCharWidthI" _
    (BYVAL hdc AS DWORD, BYVAL giFirst AS DWORD, BYVAL cgi AS DWORD, _
    pgi AS ANY, lpBuffer AS ANY) AS LONG

DECLARE FUNCTION GetCharABCWidthsI LIB "GDI32.DLL" ALIAS "GetCharABCWidthsI" _
    (BYVAL hdc AS DWORD, BYVAL giFirst AS DWORD, BYVAL cgi AS DWORD, _
    pgi AS ANY, lpabc AS ANY) AS LONG

%STAMP_DESIGNVECTOR = &H08007664  ' (&H8000000 + 'd' + ('v' << 8))
%STAMP_AXESLIST     = &H08006C61  ' (&H8000000 + 'a' + ('l' << 8))
%MM_MAX_NUMAXES     = 16

TYPE DESIGNVECTOR
    dvReserved AS DWORD
    dvNumAxes  AS DWORD
    dvValues(%MM_MAX_NUMAXES - 1) AS LONG
END TYPE

DECLARE FUNCTION AddFontResourceExA LIB "GDI32.DLL" _
    ALIAS "AddFontResourceExA" (lpszFileName AS ASCIIZ, BYVAL fl AS DWORD, _
    BYVAL pdv AS DWORD) AS LONG

DECLARE FUNCTION AddFontResourceExW LIB "GDI32.DLL" _
    ALIAS "AddFontResourceExW" (lpszFileName AS WSTRINGZ, BYVAL fl AS DWORD, _
    BYVAL pdv AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO AddFontResourceEx=AddFontResourceExW
#ELSE
MACRO AddFontResourceEx=AddFontResourceExA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RemoveFontResourceExA LIB "GDI32.DLL" _
    ALIAS "RemoveFontResourceExA" (lpFileName AS ASCIIZ, BYVAL fl AS DWORD, _
    BYVAL pdv AS DWORD) AS LONG

DECLARE FUNCTION RemoveFontResourceExW LIB "GDI32.DLL" _
    ALIAS "RemoveFontResourceExW" (lpFileName AS WSTRINGZ, BYVAL fl AS DWORD, _
    BYVAL pdv AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO RemoveFontResourceEx=RemoveFontResourceExW
#ELSE
MACRO RemoveFontResourceEx=RemoveFontResourceExA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION AddFontMemResourceEx LIB "GDI32.DLL" _
    ALIAS "AddFontMemResourceEx" (BYVAL pbFont AS DWORD, _
    BYVAL cbFont AS DWORD, BYVAL pdv AS DWORD, pcFonts AS DWORD) AS DWORD

DECLARE FUNCTION RemoveFontMemResourceEx LIB "GDI32.DLL" _
    ALIAS "RemoveFontMemResourceEx" (BYVAL fh AS DWORD) AS LONG

%FR_PRIVATE     = &H10
%FR_NOT_ENUM    = &H20

' The actual size of the DESIGNVECTOR and ENUMLOGFONTEXDV structures
' is determined by dvNumAxes,
' MM_MAX_NUMAXES only detemines the maximal size allowed

%MM_MAX_AXES_NAMELEN = 16

TYPE AXISINFOA
    axMinValue AS LONG
    axMaxValue AS LONG
    axAxisName AS ASCIIZ * %MM_MAX_AXES_NAMELEN - 1
END TYPE

TYPE AXISINFOW
    axMinValue AS LONG
    axMaxValue AS LONG
    axAxisName AS WSTRINGZ * %MM_MAX_AXES_NAMELEN - 1
END TYPE

#IF %DEF(%UNICODE)
TYPE AXISINFO
    AXISINFOW
END TYPE
#ELSE
TYPE AXISINFO
    AXISINFOA
END TYPE
#ENDIF ' UNICODE

TYPE AXESLISTA
    axlReserved AS DWORD
    axlNumAxes  AS DWORD
    axlAxisInfo(%MM_MAX_NUMAXES - 1) AS AXISINFOA
END TYPE

TYPE AXESLISTW
    axlReserved AS DWORD
    axlNumAxes  AS DWORD
    axlAxisInfo(%MM_MAX_NUMAXES - 1) AS AXISINFOW
END TYPE

#IF %DEF(%UNICODE)
TYPE AXESLIST
    AXESLISTW
END TYPE
#ELSE
TYPE AXESLIST
    AXESLISTA
END TYPE
#ENDIF ' UNICODE

' The actual size of the AXESLIST and ENUMTEXTMETRIC structure is
' determined by axlNumAxes,
' MM_MAX_NUMAXES only detemines the maximal size allowed

TYPE ENUMLOGFONTEXDVA
    elfEnumLogfontEx AS ENUMLOGFONTEXA
    elfDesignVector  AS DESIGNVECTOR
END TYPE

TYPE ENUMLOGFONTEXDVW
    elfEnumLogfontEx AS ENUMLOGFONTEXW
    elfDesignVector  AS DESIGNVECTOR
END TYPE

#IF %DEF(%UNICODE)
TYPE ENUMLOGFONTEXDV
    ENUMLOGFONTEXDVW
END TYPE
#ELSE
TYPE ENUMLOGFONTEXDV
    ENUMLOGFONTEXDVA
END TYPE
#ENDIF ' UNICODE

DECLARE FUNCTION CreateFontIndirectExA LIB "GDI32.DLL" _
    ALIAS "CreateFontIndirectExA" (penumlfex AS ENUMLOGFONTEXDVA) AS DWORD

DECLARE FUNCTION CreateFontIndirectExW LIB "GDI32.DLL" _
    ALIAS "CreateFontIndirectExW" (penumlfex AS ENUMLOGFONTEXDVW) AS DWORD

#IF %DEF(%UNICODE)
MACRO CreateFontIndirectEx=CreateFontIndirectExW
#ELSE
MACRO CreateFontIndirectEx=CreateFontIndirectExA
#ENDIF ' NOT %UNICODE

#IF NOT %DEF(%NOTEXTMETRIC)

TYPE ENUMTEXTMETRICA
    etmNewTextMetricEx AS NEWTEXTMETRICEXA
    etmAxesList        AS AXESLISTA
END TYPE

TYPE ENUMTEXTMETRICW
    etmNewTextMetricEx AS NEWTEXTMETRICEXW
    etmAxesList        AS AXESLISTW
END TYPE

#IF %DEF(%UNICODE)
TYPE ENUMTEXTMETRIC
    ENUMTEXTMETRICW
END TYPE
#ELSE
TYPE ENUMTEXTMETRIC
    ENUMTEXTMETRICA
END TYPE
#ENDIF ' UNICODE

#ENDIF ' NOTEXTMETRIC

#ENDIF ' (%WIN32_WINNT >= %WIN32_WINNT_WIN2K)

DECLARE FUNCTION GetViewportExtEx LIB "GDI32.DLL" ALIAS "GetViewportExtEx" _
    (BYVAL hdc AS DWORD, lpSize AS SIZEL) AS LONG

DECLARE FUNCTION GetViewportOrgEx LIB "GDI32.DLL" ALIAS "GetViewportOrgEx" _
    (BYVAL hdc AS DWORD, lpPoint AS POINT) AS LONG

DECLARE FUNCTION GetWindowExtEx LIB "GDI32.DLL" ALIAS "GetWindowExtEx" _
    (BYVAL hdc AS DWORD, lpSize AS SIZEL) AS LONG

DECLARE FUNCTION GetWindowOrgEx LIB "GDI32.DLL" ALIAS "GetWindowOrgEx" _
    (BYVAL hdc AS DWORD, lpPoint AS POINT) AS LONG

DECLARE FUNCTION IntersectClipRect LIB "GDI32.DLL" ALIAS "IntersectClipRect" _
    (BYVAL hdc AS DWORD, BYVAL X1 AS LONG, BYVAL Y1 AS LONG, _
    BYVAL X2 AS LONG, BYVAL Y2 AS LONG) AS LONG

DECLARE FUNCTION InvertRgn LIB "GDI32.DLL" ALIAS "InvertRgn" _
    (BYVAL hdc AS DWORD, BYVAL hRgn AS DWORD) AS LONG

DECLARE FUNCTION LineDDA LIB "GDI32.DLL" ALIAS "LineDDA" (BYVAL n1 AS LONG, _
    BYVAL n2 AS LONG, BYVAL n3 AS LONG, BYVAL n4 AS LONG, _
    BYVAL lpLineDDAProc AS DWORD, BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION LineTo LIB "GDI32.DLL" ALIAS "LineTo" (BYVAL hdc AS DWORD, _
    BYVAL x AS LONG, BYVAL y AS LONG) AS LONG

DECLARE FUNCTION MaskBlt LIB "GDI32.DLL" ALIAS "MaskBlt" _
    (BYVAL hdcDest AS DWORD, BYVAL nXDest AS LONG, BYVAL nYDest AS LONG, _
    BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL hdcSrc AS DWORD, _
    BYVAL nXSrc AS LONG, BYVAL nYSrc AS LONG, BYVAL hbmMask AS DWORD, _
    BYVAL xMask AS LONG, BYVAL yMask AS LONG, BYVAL dwRop AS DWORD) AS LONG

DECLARE FUNCTION PlgBlt LIB "GDI32.DLL" ALIAS "PlgBlt" _
    (BYVAL hdcDest AS DWORD, lpPoint AS POINT, BYVAL hdcSrc AS DWORD, _
    BYVAL nXSrc AS LONG, BYVAL nYSrc AS LONG, BYVAL nWidth AS LONG, _
    BYVAL nHeight AS LONG, BYVAL hbmMask AS DWORD, BYVAL xMask AS LONG, _
    BYVAL yMask AS LONG) AS LONG

DECLARE FUNCTION OffsetClipRgn LIB "GDI32.DLL" ALIAS "OffsetClipRgn" _
    (BYVAL hdc AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG

DECLARE FUNCTION OffsetRgn LIB "GDI32.DLL" ALIAS "OffsetRgn" _
    (BYVAL hRgn AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG

DECLARE FUNCTION PatBlt LIB "GDI32.DLL" ALIAS "PatBlt" (BYVAL hdc AS DWORD, _
    BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, _
    BYVAL nHeight AS LONG, BYVAL dwRop AS DWORD) AS LONG

DECLARE FUNCTION PIE LIB "GDI32.DLL" ALIAS "Pie" (BYVAL hdc AS DWORD, _
    BYVAL X1 AS LONG, BYVAL Y1 AS LONG, BYVAL X2 AS LONG, BYVAL Y2 AS LONG, _
    BYVAL X3 AS LONG, BYVAL Y3 AS LONG, BYVAL X4 AS LONG, BYVAL Y4 AS LONG) _
    AS LONG

DECLARE FUNCTION PlayMetaFile LIB "GDI32.DLL" ALIAS "PlayMetaFile" _
    (BYVAL hdc AS DWORD, BYVAL hMF AS DWORD) AS LONG

DECLARE FUNCTION PaintRgn LIB "GDI32.DLL" ALIAS "PaintRgn" _
    (BYVAL hdc AS DWORD, BYVAL hRgn AS DWORD) AS LONG

DECLARE FUNCTION PolyPolygon LIB "GDI32.DLL" ALIAS "PolyPolygon" _
    (BYVAL hdc AS DWORD, lpPoint AS POINT, lpPolyCounts AS LONG, _
    BYVAL nCount AS LONG) AS LONG

DECLARE FUNCTION PtInRegion LIB "GDI32.DLL" ALIAS "PtInRegion" _
    (BYVAL hRgn AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG

DECLARE FUNCTION PtVisible LIB "GDI32.DLL" ALIAS "PtVisible" _
    (BYVAL hdc AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG

DECLARE FUNCTION RectInRegion LIB "GDI32.DLL" ALIAS "RectInRegion" _
    (BYVAL hRgn AS DWORD, lpRect AS RECT) AS LONG

DECLARE FUNCTION RectVisible LIB "GDI32.DLL" ALIAS "RectVisible" _
    (BYVAL hdc AS DWORD, lpRect AS RECT) AS LONG

DECLARE FUNCTION Rectangle LIB "GDI32.DLL" ALIAS "Rectangle" _
    (BYVAL hdc AS DWORD, BYVAL X1 AS LONG, BYVAL Y1 AS LONG, _
    BYVAL X2 AS LONG, BYVAL Y2 AS LONG) AS LONG

DECLARE FUNCTION RestoreDC LIB "GDI32.DLL" ALIAS "RestoreDC" _
    (BYVAL hdc AS DWORD, BYVAL nSavedDC AS LONG) AS LONG

DECLARE FUNCTION ResetDCA LIB "GDI32.DLL" ALIAS "ResetDCA" _
    (BYVAL hdc AS DWORD, lpInitData AS DEVMODEA) AS DWORD

DECLARE FUNCTION ResetDCW LIB "GDI32.DLL" ALIAS "ResetDCW" _
    (BYVAL hdc AS DWORD, lpInitData AS DEVMODEW) AS DWORD

#IF %DEF(%UNICODE)
MACRO ResetDC=ResetDCW
#ELSE
MACRO ResetDC=ResetDCA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RealizePalette LIB "GDI32.DLL" ALIAS "RealizePalette" _
    (BYVAL hdc AS DWORD) AS DWORD

DECLARE FUNCTION RemoveFontResourceA LIB "GDI32.DLL" _
    ALIAS "RemoveFontResourceA" (lpFileName AS ASCIIZ) AS LONG

DECLARE FUNCTION RemoveFontResourceW LIB "GDI32.DLL" _
    ALIAS "RemoveFontResourceW" (lpFileName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO RemoveFontResource=RemoveFontResourceW
#ELSE
MACRO RemoveFontResource=RemoveFontResourceA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RoundRect LIB "GDI32.DLL" ALIAS "RoundRect" _
    (BYVAL hdc AS DWORD, BYVAL X1 AS LONG, BYVAL Y1 AS LONG, _
    BYVAL X2 AS LONG, BYVAL Y2 AS LONG, BYVAL X3 AS LONG, BYVAL Y3 AS LONG) _
    AS LONG

DECLARE FUNCTION ResizePalette LIB "GDI32.DLL" ALIAS "ResizePalette" _
    (BYVAL hPalette AS DWORD, BYVAL nNumEntries AS DWORD) AS LONG

DECLARE FUNCTION SaveDC LIB "GDI32.DLL" ALIAS "SaveDC" (BYVAL hdc AS DWORD) _
    AS LONG

DECLARE FUNCTION SelectClipRgn LIB "GDI32.DLL" ALIAS "SelectClipRgn" _
    (BYVAL hdc AS DWORD, BYVAL hRgn AS DWORD) AS LONG

DECLARE FUNCTION ExtSelectClipRgn LIB "GDI32.DLL" ALIAS "ExtSelectClipRgn" _
    (BYVAL hdc AS DWORD, BYVAL hRgn AS DWORD, BYVAL fnMode AS LONG) AS LONG

DECLARE FUNCTION SetMetaRgn LIB "GDI32.DLL" ALIAS "SetMetaRgn" _
    (BYVAL hdc AS DWORD) AS LONG

DECLARE FUNCTION SelectObject LIB "GDI32.DLL" ALIAS "SelectObject" _
    (BYVAL hdc AS DWORD, BYVAL hObject AS DWORD) AS DWORD

DECLARE FUNCTION SelectPalette LIB "GDI32.DLL" ALIAS "SelectPalette" _
    (BYVAL hdc AS DWORD, BYVAL hPalette AS DWORD, _
    BYVAL bForceBackground AS LONG) AS DWORD

DECLARE FUNCTION SetBkColor LIB "GDI32.DLL" ALIAS "SetBkColor" _
    (BYVAL hdc AS DWORD, BYVAL crColor AS COLORREF) AS COLORREF

#IF (%WIN32_WINNT >= %WIN32_WINNT_WIN2K)

DECLARE FUNCTION SetDCBrushColor LIB "GDI32.DLL" ALIAS "SetDCBrushColor" _
    (BYVAL hdc AS DWORD, BYVAL crColor AS DWORD) AS COLORREF

DECLARE FUNCTION SetDCPenColor LIB "GDI32.DLL" ALIAS "SetDCPenColor" _
    (BYVAL hdc AS DWORD, BYVAL crColor AS DWORD) AS COLORREF

#ENDIF

DECLARE FUNCTION SetBkMode LIB "GDI32.DLL" ALIAS "SetBkMode" _
    (BYVAL hdc AS DWORD, BYVAL nBkMode AS LONG) AS LONG

DECLARE FUNCTION SetBitmapBits LIB "GDI32.DLL" ALIAS "SetBitmapBits" _
    (BYVAL hBitmap AS DWORD, BYVAL dwCount AS DWORD, lpBits AS ANY) AS LONG

DECLARE FUNCTION SetBoundsRect LIB "GDI32.DLL" ALIAS "SetBoundsRect" _
    (BYVAL hdc AS DWORD, lprcBounds AS RECT, BYVAL flags AS DWORD) AS DWORD

DECLARE FUNCTION SetDIBits LIB "GDI32.DLL" ALIAS "SetDIBits" _
    (BYVAL hdc AS DWORD, BYVAL hBitmap AS DWORD, BYVAL nStartScan AS DWORD, _
    BYVAL nNumScans AS DWORD, lpBits AS ANY, lpBI AS BITMAPINFO, _
    BYVAL wUsage AS DWORD) AS LONG

DECLARE FUNCTION SetDIBitsToDevice LIB "GDI32.DLL" ALIAS "SetDIBitsToDevice" _
    (BYVAL hdc AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    BYVAL dx AS DWORD, BYVAL dy AS DWORD, BYVAL SrcX AS LONG, _
    BYVAL SrcY AS LONG, BYVAL xScan AS DWORD, BYVAL NumScans AS DWORD, _
    xBits AS ANY, BitsInfo AS BITMAPINFO, BYVAL wUsage AS DWORD) AS LONG

DECLARE FUNCTION SetMapperFlags LIB "GDI32.DLL" ALIAS "SetMapperFlags" _
    (BYVAL hdc AS DWORD, BYVAL dwFlag AS DWORD) AS DWORD

DECLARE FUNCTION SetGraphicsMode LIB "GDI32.DLL" ALIAS "SetGraphicsMode" _
    (BYVAL hdc AS DWORD, BYVAL iMode AS LONG) AS LONG

DECLARE FUNCTION SetMapMode LIB "GDI32.DLL" ALIAS "SetMapMode" _
    (BYVAL hdc AS DWORD, BYVAL nMapMode AS LONG) AS LONG

#IF (%WINVER >= &H0500)

DECLARE FUNCTION SetLayout LIB "GDI32.DLL" ALIAS "SetLayout" _
    (BYVAL hdc AS DWORD, BYVAL l AS DWORD) AS DWORD

DECLARE FUNCTION GetLayout LIB "GDI32.DLL" ALIAS "GetLayout" _
    (BYVAL hdc AS DWORD) AS DWORD

#ENDIF ' WINVER >= &H0500

DECLARE FUNCTION SetMetaFileBitsEx LIB "GDI32.DLL" ALIAS "SetMetaFileBitsEx" _
    (BYVAL nSize AS DWORD, lpData AS BYTE) AS DWORD

DECLARE FUNCTION SetPaletteEntries LIB "GDI32.DLL" ALIAS "SetPaletteEntries" _
    (BYVAL hPalette AS DWORD, BYVAL wStartIndex AS DWORD, _
    BYVAL wNumEntries AS DWORD, lpPaletteEntries AS PALETTEENTRY) AS DWORD

DECLARE FUNCTION SetPixel LIB "GDI32.DLL" ALIAS "SetPixel" _
    (BYVAL hdc AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    BYVAL crColor AS DWORD) AS DWORD

DECLARE FUNCTION SetPixelV LIB "GDI32.DLL" ALIAS "SetPixelV" _
    (BYVAL hdc AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    BYVAL crColor AS DWORD) AS LONG

DECLARE FUNCTION SetPixelFormat LIB "GDI32.DLL" ALIAS "SetPixelFormat" _
    (BYVAL hDC AS DWORD, BYVAL n AS LONG, _
    pcPixelFormatDescriptor AS PIXELFORMATDESCRIPTOR) AS LONG

DECLARE FUNCTION SetPolyFillMode LIB "GDI32.DLL" ALIAS "SetPolyFillMode" _
    (BYVAL hdc AS DWORD, BYVAL nPolyFillMode AS LONG) AS LONG

DECLARE FUNCTION StretchBlt LIB "GDI32.DLL" ALIAS "StretchBlt" _
    (BYVAL hdc AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL hSrcDC AS DWORD, _
    BYVAL xSrc AS LONG, BYVAL ySrc AS LONG, BYVAL nSrcWidth AS LONG, _
    BYVAL nSrcHeight AS LONG, BYVAL dwRop AS DWORD) AS LONG

DECLARE FUNCTION SetRectRgn LIB "GDI32.DLL" ALIAS "SetRectRgn" _
    (BYVAL hRgn AS DWORD, BYVAL X1 AS LONG, BYVAL Y1 AS LONG, _
    BYVAL X2 AS LONG, BYVAL Y2 AS LONG) AS LONG

DECLARE FUNCTION StretchDIBits LIB "GDI32.DLL" ALIAS "StretchDIBits" _
    (BYVAL hdc AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL dx AS LONG, _
    BYVAL dy AS LONG, BYVAL SrcX AS LONG, BYVAL SrcY AS LONG, _
    BYVAL nSrcWidth AS LONG, BYVAL nSrcHeight AS LONG, lpBits AS ANY, _
    lpBitsInfo AS BITMAPINFO, BYVAL uUsage AS DWORD, BYVAL dwRop AS DWORD) _
    AS LONG

DECLARE FUNCTION SetROP2 LIB "GDI32.DLL" ALIAS "SetROP2" (BYVAL hdc AS DWORD, _
    BYVAL nDrawMode AS LONG) AS LONG

DECLARE FUNCTION SetStretchBltMode LIB "GDI32.DLL" ALIAS "SetStretchBltMode" _
    (BYVAL hdc AS DWORD, BYVAL nStretchMode AS LONG) AS LONG

DECLARE FUNCTION SetSystemPaletteUse LIB "GDI32.DLL" _
    ALIAS "SetSystemPaletteUse" (BYVAL hdc AS DWORD, BYVAL uUsage AS DWORD) _
    AS DWORD

DECLARE FUNCTION SetTextCharacterExtra LIB "GDI32.DLL" _
    ALIAS "SetTextCharacterExtra" (BYVAL hdc AS DWORD, _
    BYVAL nCharExtra AS LONG) AS LONG

DECLARE FUNCTION SetTextColor LIB "GDI32.DLL" ALIAS "SetTextColor" _
    (BYVAL hdc AS DWORD, BYVAL crColor AS DWORD) AS DWORD

DECLARE FUNCTION SetTextAlign LIB "GDI32.DLL" ALIAS "SetTextAlign" _
    (BYVAL hdc AS DWORD, BYVAL dwFlags AS DWORD) AS DWORD

DECLARE FUNCTION SetTextJustification LIB "GDI32.DLL" _
    ALIAS "SetTextJustification" (BYVAL hdc AS DWORD, _
    BYVAL nBreakExtra AS LONG, BYVAL nBreakCount AS LONG) AS LONG

DECLARE FUNCTION UpdateColors LIB "GDI32.DLL" ALIAS "UpdateColors" _
    (BYVAL hdc AS DWORD) AS LONG

#IF %DEF(%COMBOX_SANDBOX)

#IF (%WIN32_WINNT >= &H0600)

' [these callbacks are not documented]
'typedef PVOID   (WINAPI *GDIMARSHALLOC)(DWORD dwSize, LPVOID pGdiRef);
'
'typedef LONG (WINAPI *DDRAWMARSHCALLBACKMARSHAL)(__in HGDIOBJ hGdiObj, LPVOID pGdiRef, LPVOID *ppDDrawRef);
'typedef LONG (WINAPI *DDRAWMARSHCALLBACKUNMARSHAL)(__in LPVOID pData, HDC *phdc, LPVOID *ppDDrawRef);
'typedef LONG (WINAPI *DDRAWMARSHCALLBACKRELEASE)(__in LPVOID pDDrawRef);

%GDIREGISTERDDRAWPACKETVERSION = &H1

TYPE GDIREGISTERDDRAWPACKET
    dwSize         AS DWORD
    dwVersion      AS DWORD
    pfnDdMarshal   AS DWORD  ' DDRAWMARSHCALLBACKMARSHAL
    pfnDdUnmarshal AS DWORD  ' DDRAWMARSHCALLBACKUNMARSHAL
    pfnDdRelease   AS DWORD  ' DDRAWMARSHCALLBACKRELEASE
END TYPE

' [not documented. does not appear to be exported.]
'DECLARE FUNCTION GdiRegisterDdraw LIB "GDI32.DLL" ALIAS "GdiRegisterDdraw" _
'    pPacket AS GDIREGISTERDRAWPACKET, ppfnGdiAlloc AS DWORD) AS LONG
'
'DECLARE FUNCTION GdiMarshalSize LIB "GDI32.DLL" ALIAS "GdiMarshalSize" () _
'    AS DWORD
'
'DECLARE SUB GdiMarshal LIB "GDI32.DLL" ALIAS "GdiMarshal" _
'    (BYVAL dwProcessIdTo AS DWORD, BYVAL hGdiObj AS DWORD, _
'    BYVAL pData AS DWORD PTR, BYVAL ulFlags AS DWORD)
'
'DECLARE FUNCTION GdiUnmarshal LIB "GDI32.DLL" ALIAS "GdiUnmarshal" _
'    (BYVAL pData AS DWORD, BYVAL ulFlags AS DWORD) AS DWORD

#ENDIF ' (%WIN32_WINNT >= &H0600)

#ENDIF  ' %COMBOX_SANDBOX

#IF (%WINVER >= &H0400)

'
' image blt
'

TYPE TRIVERTEX
    x     AS LONG
    y     AS LONG
    Red   AS WORD
    Green AS WORD
    Blue  AS WORD
    Alpha AS WORD
END TYPE

TYPE GRADIENT_TRIANGLE
    Vertex1 AS DWORD
    Vertex2 AS DWORD
    Vertex3 AS DWORD
END TYPE

TYPE GRADIENT_RECT
    UpperLeft  AS DWORD
    LowerRight AS DWORD
END TYPE

TYPE BLENDFUNCTION
    BlendOp     AS BYTE
    BlendFlags  AS BYTE
    SourceConstantAlpha AS BYTE
    AlphaFormat AS BYTE
END TYPE


'
' currently defined blend function
'

%AC_SRC_OVER             = &H00

'
' alpha format flags
'

%AC_SRC_ALPHA            = &H01

DECLARE FUNCTION AlphaBlend LIB "MSIMG32.DLL" ALIAS "AlphaBlend" ( _
    BYVAL hdcDest      AS DWORD, _
    BYVAL nXOriginDest AS LONG, _
    BYVAL nYOriginDest AS LONG, _
    BYVAL nWidthDest   AS LONG, _
    BYVAL nHeightDest  AS LONG, _
    BYVAL hdcSrc       AS DWORD, _
    BYVAL nXOriginSrc  AS LONG, _
    BYVAL nYOriginSrc  AS LONG, _
    BYVAL nWidthSrc    AS LONG, _
    BYVAL nHeightSrc   AS LONG, _
    BYVAL bf           AS BLENDFUNCTION) _
    AS LONG

DECLARE FUNCTION TransparentBlt LIB "MSIMG32.DLL" ALIAS "TransparentBlt" ( _
    BYVAL hdcDest       AS DWORD, _
    BYVAL nXOriginDest  AS LONG, _
    BYVAL nYOriginDest  AS LONG, _
    BYVAL nWidthDest    AS LONG, _
    BYVAL hHeightDest   AS DWORD, _
    BYVAL hdcSrc        AS DWORD, _
    BYVAL nXOriginSrc   AS LONG, _
    BYVAL nYOriginSrc   AS LONG, _
    BYVAL nWidthSrc     AS LONG, _
    BYVAL nHeightSrc    AS LONG, _
    BYVAL crTransparent AS DWORD) _
    AS LONG


'
' gradient drawing modes
'

%GRADIENT_FILL_RECT_H    = &H00000000
%GRADIENT_FILL_RECT_V    = &H00000001
%GRADIENT_FILL_TRIANGLE  = &H00000002
%GRADIENT_FILL_OP_FLAG   = &H000000ff

DECLARE FUNCTION GradientFill LIB "MSIMG32.DLL" ALIAS "GradientFill" _
    (BYVAL hdc AS DWORD, pVertex AS TRIVERTEX, BYVAL dwNumVertex AS DWORD, _
    pMesh AS ANY, BYVAL dwNumMesh AS DWORD, BYVAL dwMode AS DWORD) AS LONG

#ENDIF


#IF (%WIN32_WINNT >= %WIN32_WINNT_WIN2K)

DECLARE FUNCTION GdiAlphaBlend LIB "GDI32.DLL" ALIAS "GdiAlphaBlend" _
    (BYVAL hdcDest AS DWORD, BYVAL nXOriginDest AS LONG, _
    BYVAL nYOriginDest AS LONG, BYVAL nWidthDest AS LONG, _
    BYVAL nHeightDest AS LONG, BYVAL hdcSrc AS DWORD, _
    BYVAL nXOriginSrc AS LONG, BYVAL nYOriginSrc AS LONG, _
    BYVAL nWidthSrc AS LONG, BYVAL nHeightSrc AS LONG, _
    BYVAL bf AS BLENDFUNCTION) AS LONG

DECLARE FUNCTION GdiTransparentBlt LIB "GDI32.DLL" ALIAS "GdiTransparentBlt" _
    (BYVAL hdcDest AS DWORD, BYVAL nXOriginDest AS LONG, _
    BYVAL nYOriginDest AS LONG, BYVAL nWidthDest AS LONG, _
    BYVAL hHeightDest AS DWORD, BYVAL hdcSrc AS DWORD, _
    BYVAL nXOriginSrc AS LONG, BYVAL nYOriginSrc AS LONG, _
    BYVAL nWidthSrc AS LONG, BYVAL nHeightSrc AS LONG, _
    BYVAL crTransparent AS DWORD) AS LONG

DECLARE FUNCTION GdiGradientFill LIB "GDI32.DLL" ALIAS "GdiGradientFill" _
    (BYVAL hdc AS DWORD, pVertex AS TRIVERTEX, BYVAL dwNumVertex AS DWORD, _
    pMesh AS ANY, BYVAL dwNumMesh AS DWORD, BYVAL dwMode AS DWORD) AS LONG

#ENDIF


#IF NOT %DEF(%NOMETAFILE)

DECLARE FUNCTION PlayMetaFileRecord LIB "GDI32.DLL" _
    ALIAS "PlayMetaFileRecord" (BYVAL hdc AS DWORD, _
    lpHandletable AS HANDLETABLE, lpMetaRecord AS METARECORD, _
    BYVAL nHandles AS DWORD) AS LONG

DECLARE FUNCTION MFENUMPROC (BYVAL hdc AS DWORD, _
    BYVAL lpht AS HANDLETABLE PTR, BYVAL lpMR AS METARECORD PTR, _
    BYVAL nObj AS LONG, lparam AS LONG) AS LONG

DECLARE FUNCTION EnumMetaFile LIB "GDI32.DLL" ALIAS "EnumMetaFile" _
    (BYVAL hDC AS DWORD, BYVAL hMetafile AS DWORD, _
    BYVAL lpMFEnumProc AS DWORD, BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION ENHMFENUMPROC (BYVAL hdc AS DWORD, _
    BYVAL lpht AS HANDLETABLE PTR, BYVAL lpmr AS ENHMETARECORD PTR, _
    BYVAL hHandles AS LONG, BYVAL lparam AS LONG) AS LONG

' Enhanced Metafile Function Declarations

DECLARE FUNCTION CloseEnhMetaFile LIB "GDI32.DLL" ALIAS "CloseEnhMetaFile" _
    (BYVAL hdc AS DWORD) AS DWORD

DECLARE FUNCTION CopyEnhMetaFileA LIB "GDI32.DLL" ALIAS "CopyEnhMetaFileA" _
    (BYVAL hemfSrc AS DWORD, lpszFile AS ASCIIZ) AS DWORD

DECLARE FUNCTION CopyEnhMetaFileW LIB "GDI32.DLL" ALIAS "CopyEnhMetaFileW" _
    (BYVAL hemfSrc AS DWORD, lpszFile AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
MACRO CopyEnhMetaFile=CopyEnhMetaFileW
#ELSE
MACRO CopyEnhMetaFile=CopyEnhMetaFileA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CreateEnhMetaFileA LIB "GDI32.DLL" _
    ALIAS "CreateEnhMetaFileA" (BYVAL hdcRef AS DWORD, lpFileName AS ASCIIZ, _
    lpRect AS RECT, lpDescription AS ASCIIZ) AS DWORD

DECLARE FUNCTION CreateEnhMetaFileW LIB "GDI32.DLL" _
    ALIAS "CreateEnhMetaFileW" (BYVAL hdcRef AS DWORD, _
    lpFileName AS WSTRINGZ, lpRect AS RECT, lpDescription AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
MACRO CreateEnhMetaFile=CreateEnhMetaFileW
#ELSE
MACRO CreateEnhMetaFile=CreateEnhMetaFileA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION DeleteEnhMetaFile LIB "GDI32.DLL" ALIAS "DeleteEnhMetaFile" _
    (BYVAL hemf AS DWORD) AS LONG

DECLARE FUNCTION EnumEnhMetaFile LIB "GDI32.DLL" ALIAS "EnumEnhMetaFile" _
    (BYVAL hdc AS DWORD, BYVAL hemf AS DWORD, BYVAL lpEnhMetaFunc AS DWORD, _
    lpData AS ANY, lpRect AS RECT) AS LONG

DECLARE FUNCTION GetEnhMetaFileA LIB "GDI32.DLL" ALIAS "GetEnhMetaFileA" _
    (lpszMetaFile AS ASCIIZ) AS DWORD

DECLARE FUNCTION GetEnhMetaFileW LIB "GDI32.DLL" ALIAS "GetEnhMetaFileW" _
    (lpszMetaFile AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
MACRO GetEnhMetaFile=GetEnhMetaFileW
#ELSE
MACRO GetEnhMetaFile=GetEnhMetaFileA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetEnhMetaFileBits LIB "GDI32.DLL" _
    ALIAS "GetEnhMetaFileBits" (BYVAL hemf AS DWORD, BYVAL cbBuffer AS DWORD, _
    lpbBuffer AS BYTE) AS DWORD

DECLARE FUNCTION GetEnhMetaFileDescriptionA LIB "GDI32.DLL" _
    ALIAS "GetEnhMetaFileDescriptionA" (BYVAL hemf AS DWORD, _
    BYVAL cchBuffer AS DWORD, lpszDescription AS ASCIIZ) AS DWORD

DECLARE FUNCTION GetEnhMetaFileDescriptionW LIB "GDI32.DLL" _
    ALIAS "GetEnhMetaFileDescriptionW" (BYVAL hemf AS DWORD, _
    BYVAL cchBuffer AS DWORD, lpszDescription AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
MACRO GetEnhMetaFileDescription=GetEnhMetaFileDescriptionW
#ELSE
MACRO GetEnhMetaFileDescription=GetEnhMetaFileDescriptionA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetEnhMetaFileHeader LIB "GDI32.DLL" _
    ALIAS "GetEnhMetaFileHeader" (BYVAL hemf AS DWORD, _
    BYVAL cbBuffer AS DWORD, lpemh AS ENHMETAHEADER) AS DWORD

DECLARE FUNCTION GetEnhMetaFilePaletteEntries LIB "GDI32.DLL" _
    ALIAS "GetEnhMetaFilePaletteEntries" (BYVAL hemf AS DWORD, _
    BYVAL cEntries AS DWORD, lppe AS PALETTEENTRY) AS DWORD

DECLARE FUNCTION GetEnhMetaFilePixelFormat LIB "GDI32.DLL" _
    ALIAS "GetEnhMetaFilePixelFormat" (BYVAL hemf AS DWORD, _
    BYVAL cbBuffer AS DWORD, ppfd AS PIXELFORMATDESCRIPTOR) AS DWORD

DECLARE FUNCTION GetWinMetaFileBits LIB "GDI32.DLL" _
    ALIAS "GetWinMetaFileBits" (BYVAL hemf AS DWORD, BYVAL cbBuffer AS DWORD, _
    lpbBuffer AS BYTE, BYVAL fnMapMode AS LONG, BYVAL hdcRef AS DWORD) AS DWORD

DECLARE FUNCTION PlayEnhMetaFile LIB "GDI32.DLL" ALIAS "PlayEnhMetaFile" _
    (BYVAL hdc AS DWORD, BYVAL hemf AS DWORD, lpRect AS RECT) AS LONG

DECLARE FUNCTION PlayEnhMetaFileRecord LIB "GDI32.DLL" _
    ALIAS "PlayEnhMetaFileRecord" (BYVAL hdc AS DWORD, _
    lpHandletable AS HANDLETABLE, lpEnhMetaRecord AS ENHMETARECORD, _
    BYVAL nHandles AS DWORD) AS LONG

DECLARE FUNCTION SetEnhMetaFileBits LIB "GDI32.DLL" _
    ALIAS "SetEnhMetaFileBits" (BYVAL cbBuffer AS DWORD, lpData AS BYTE) _
    AS DWORD

DECLARE FUNCTION SetWinMetaFileBits LIB "GDI32.DLL" _
    ALIAS "SetWinMetaFileBits" (BYVAL cbBuffer AS DWORD, lpbBuffer AS BYTE, _
    BYVAL hdcRef AS DWORD, lpmfp AS METAFILEPICT) AS DWORD

DECLARE FUNCTION GdiComment LIB "GDI32.DLL" ALIAS "GdiComment" _
    (BYVAL hdc AS DWORD, BYVAL cbSize AS DWORD, lpData AS BYTE) AS LONG

#ENDIF  ' NOMETAFILE

#IF NOT %DEF(%NOTEXTMETRIC)

DECLARE FUNCTION GetTextMetricsA LIB "GDI32.DLL" ALIAS "GetTextMetricsA" _
    (BYVAL hdc AS DWORD, lpMetrics AS TEXTMETRICA) AS LONG

DECLARE FUNCTION GetTextMetricsW LIB "GDI32.DLL" ALIAS "GetTextMetricsW" _
    (BYVAL hdc AS DWORD, lpMetrics AS TEXTMETRICW) AS LONG

#IF %DEF(%UNICODE)
MACRO GetTextMetrics=GetTextMetricsW
#ELSE
MACRO GetTextMetrics=GetTextMetricsA
#ENDIF ' NOT %UNICODE

#ENDIF

' new GDI

TYPE DIBSECTION
    dsBm           AS BITMAP
    dsBmih         AS BITMAPINFOHEADER
    dsBitfields(2) AS DWORD
    dshSection     AS DWORD  ' HANDLE
    dsOffset       AS DWORD
END TYPE


DECLARE FUNCTION AngleArc LIB "GDI32.DLL" ALIAS "AngleArc" _
    (BYVAL hdc AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    BYVAL dwRadius AS DWORD, BYVAL eStartAngle AS SINGLE, _
    BYVAL eSweepAngle AS SINGLE) AS LONG

DECLARE FUNCTION PolyPolyline LIB "GDI32.DLL" ALIAS "PolyPolyline" _
    (BYVAL hdc AS DWORD, lppt AS POINT, lpdwPolyPoints AS DWORD, _
    BYVAL cCount AS DWORD) AS LONG

DECLARE FUNCTION GetWorldTransform LIB "GDI32.DLL" ALIAS "GetWorldTransform" _
    (BYVAL hdc AS DWORD, lpXform AS XFORM) AS LONG

DECLARE FUNCTION SetWorldTransform LIB "GDI32.DLL" ALIAS "SetWorldTransform" _
    (BYVAL hdc AS DWORD, lpXform AS XFORM) AS LONG

DECLARE FUNCTION ModifyWorldTransform LIB "GDI32.DLL" _
    ALIAS "ModifyWorldTransform" (BYVAL hdc AS DWORD, lpXform AS xform, _
    BYVAL dwMode AS DWORD) AS LONG

DECLARE FUNCTION CombineTransform LIB "GDI32.DLL" ALIAS "CombineTransform" _
    (lpXFORMResult AS XFORM, lpXFORM1 AS XFORM, lpXFORM2 AS XFORM) AS LONG

DECLARE FUNCTION CreateDIBSection LIB "GDI32.DLL" ALIAS "CreateDIBSection" _
    (BYVAL hdc AS DWORD, pbmi AS BITMAPINFO, BYVAL dwUsage AS DWORD, _
    BYVAL ppvBits AS DWORD, BYVAL hSection AS DWORD, BYVAL dwOffset AS DWORD) _
    AS DWORD

DECLARE FUNCTION GetDIBColorTable LIB "GDI32.DLL" ALIAS "GetDIBColorTable" _
    (BYVAL hDC AS DWORD, BYVAL uStartIndex AS DWORD, BYVAL cEntries AS DWORD, _
    pRGBQuad AS RGBQUAD) AS DWORD

DECLARE FUNCTION SetDIBColorTable LIB "GDI32.DLL" ALIAS "SetDIBColorTable" _
    (BYVAL hDC AS DWORD, BYVAL uStartIndex AS DWORD, BYVAL cEntries AS DWORD, _
    pcRGBQuad AS RGBQUAD) AS DWORD


' Flags value for COLORADJUSTMENT
%CA_NEGATIVE                 = &H0001
%CA_LOG_FILTER               = &H0002

' IlluminantIndex values
%ILLUMINANT_DEVICE_DEFAULT   = 0
%ILLUMINANT_A                = 1
%ILLUMINANT_B                = 2
%ILLUMINANT_C                = 3
%ILLUMINANT_D50              = 4
%ILLUMINANT_D55              = 5
%ILLUMINANT_D65              = 6
%ILLUMINANT_D75              = 7
%ILLUMINANT_F2               = 8
%ILLUMINANT_MAX_INDEX        = %ILLUMINANT_F2

%ILLUMINANT_TUNGSTEN         = %ILLUMINANT_A
%ILLUMINANT_DAYLIGHT         = %ILLUMINANT_C
%ILLUMINANT_FLUORESCENT      = %ILLUMINANT_F2
%ILLUMINANT_NTSC             = %ILLUMINANT_C

' Min and max for RedGamma, GreenGamma, BlueGamma
%RGB_GAMMA_MIN               = 02500
%RGB_GAMMA_MAX               = 65000

' Min and max for ReferenceBlack and ReferenceWhite
%REFERENCE_WHITE_MIN         = 6000
%REFERENCE_WHITE_MAX         = 10000
%REFERENCE_BLACK_MIN         = 0
%REFERENCE_BLACK_MAX         = 4000

' Min and max for Contrast, Brightness, Colorfulness, RedGreenTint
%COLOR_ADJ_MIN               = -100
%COLOR_ADJ_MAX               = 100

TYPE COLORADJUSTMENT
    caSize            AS WORD
    caFlags           AS WORD
    caIlluminantIndex AS WORD
    caRedGamma        AS WORD
    caGreenGamma      AS WORD
    caBlueGamma       AS WORD
    caReferenceBlack  AS WORD
    caReferenceWhite  AS WORD
    caContrast        AS INTEGER
    caBrightness      AS INTEGER
    caColorfulness    AS INTEGER
    caRedGreenTint    AS INTEGER
END TYPE

DECLARE FUNCTION SetColorAdjustment LIB "GDI32.DLL" _
    ALIAS "SetColorAdjustment" (BYVAL hdc AS DWORD, lpca AS COLORADJUSTMENT) _
    AS LONG

DECLARE FUNCTION GetColorAdjustment LIB "GDI32.DLL" _
    ALIAS "GetColorAdjustment" (BYVAL hdc AS DWORD, lpca AS COLORADJUSTMENT) _
    AS LONG

DECLARE FUNCTION CreateHalftonePalette LIB "GDI32.DLL" _
    ALIAS "CreateHalftonePalette" (BYVAL hdc AS DWORD) AS DWORD

TYPE DOCINFOA
    cbSize       AS LONG
    lpszDocName  AS ASCIIZ PTR
    lpszOutput   AS ASCIIZ PTR
#IF (%WINVER >= &H0400)
    lpszDataType AS ASCIIZ PTR
    fwType       AS DWORD
#ENDIF ' WINVER
END TYPE

TYPE DOCINFOW
    cbSize       AS LONG
    lpszDocName  AS WSTRINGZ PTR
    lpszOutput   AS WSTRINGZ PTR
#IF (%WINVER >= &H0400)
    lpszDataType AS WSTRINGZ PTR
    fwType       AS DWORD
#ENDIF ' WINVER
END TYPE

#IF %DEF(%UNICODE)
TYPE DOCINFO
    DOCINFOW
END TYPE
#ELSE
TYPE DOCINFO
    DOCINFOA
END TYPE
#ENDIF ' UNICODE

#IF (%WINVER >= &H0400)
%DI_APPBANDING              = &H00000001
%DI_ROPS_READ_DESTINATION   = &H00000002
#ENDIF ' WINVER >= &H0400

DECLARE FUNCTION StartDocA LIB "GDI32.DLL" ALIAS "StartDocA" _
    (BYVAL hdc AS DWORD, lpdi AS DOCINFOA) AS LONG

DECLARE FUNCTION StartDocW LIB "GDI32.DLL" ALIAS "StartDocW" _
    (BYVAL hdc AS DWORD, lpdi AS DOCINFOW) AS LONG

#IF %DEF(%UNICODE)
MACRO StartDoc=StartDocW
#ELSE
MACRO StartDoc=StartDocA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EndDoc LIB "GDI32.DLL" ALIAS "EndDoc" (BYVAL hdc AS DWORD) _
    AS LONG

DECLARE FUNCTION StartPage LIB "GDI32.DLL" ALIAS "StartPage" _
    (BYVAL hdc AS DWORD) AS LONG

DECLARE FUNCTION EndPage LIB "GDI32.DLL" ALIAS "EndPage" (BYVAL hdc AS DWORD) _
    AS LONG

DECLARE FUNCTION AbortDoc LIB "GDI32.DLL" ALIAS "AbortDoc" _
    (BYVAL hdc AS DWORD) AS LONG

DECLARE FUNCTION SetAbortProc LIB "GDI32.DLL" ALIAS "SetAbortProc" _
    (BYVAL hDC AS DWORD, BYVAL lpAbortProc AS DWORD) AS LONG

DECLARE FUNCTION AbortPath LIB "GDI32.DLL" ALIAS "AbortPath" _
    (BYVAL hdc AS DWORD) AS LONG

DECLARE FUNCTION ArcTo LIB "GDI32.DLL" ALIAS "ArcTo" (BYVAL hdc AS DWORD, _
    BYVAL X1 AS LONG, BYVAL Y1 AS LONG, BYVAL X2 AS LONG, BYVAL Y2 AS LONG, _
    BYVAL X3 AS LONG, BYVAL Y3 AS LONG, BYVAL X4 AS LONG, BYVAL Y4 AS LONG) _
    AS LONG

DECLARE FUNCTION BeginPath LIB "GDI32.DLL" ALIAS "BeginPath" _
    (BYVAL hdc AS DWORD) AS LONG

DECLARE FUNCTION CloseFigure LIB "GDI32.DLL" ALIAS "CloseFigure" _
    (BYVAL hdc AS DWORD) AS LONG

DECLARE FUNCTION EndPath LIB "GDI32.DLL" ALIAS "EndPath" (BYVAL hdc AS DWORD) _
    AS LONG

DECLARE FUNCTION FillPath LIB "GDI32.DLL" ALIAS "FillPath" _
    (BYVAL hdc AS DWORD) AS LONG

DECLARE FUNCTION FlattenPath LIB "GDI32.DLL" ALIAS "FlattenPath" _
    (BYVAL hdc AS DWORD) AS LONG

DECLARE FUNCTION GetPath LIB "GDI32.DLL" ALIAS "GetPath" (BYVAL hdc AS DWORD, _
    lpPoint AS POINT, lpTypes AS BYTE, BYVAL nSize AS DWORD) AS LONG

DECLARE FUNCTION PathToRegion LIB "GDI32.DLL" ALIAS "PathToRegion" _
    (BYVAL hdc AS DWORD) AS DWORD

DECLARE FUNCTION PolyDraw LIB "GDI32.DLL" ALIAS "PolyDraw" _
    (BYVAL hdc AS DWORD, lppt AS POINT, lpbTypes AS BYTE, _
    BYVAL cCount AS LONG) AS LONG

DECLARE FUNCTION SelectClipPath LIB "GDI32.DLL" ALIAS "SelectClipPath" _
    (BYVAL hdc AS DWORD, BYVAL iMode AS LONG) AS LONG

DECLARE FUNCTION SetArcDirection LIB "GDI32.DLL" ALIAS "SetArcDirection" _
    (BYVAL hdc AS DWORD, BYVAL ArcDirection AS LONG) AS LONG

DECLARE FUNCTION SetMiterLimit LIB "GDI32.DLL" ALIAS "SetMiterLimit" _
    (BYVAL hdc AS DWORD, BYVAL eNewLimit AS SINGLE, peOldLimit AS SINGLE) _
    AS LONG

DECLARE FUNCTION StrokeAndFillPath LIB "GDI32.DLL" ALIAS "StrokeAndFillPath" _
    (BYVAL hdc AS DWORD) AS LONG

DECLARE FUNCTION StrokePath LIB "GDI32.DLL" ALIAS "StrokePath" _
    (BYVAL hdc AS DWORD) AS LONG

DECLARE FUNCTION WidenPath LIB "GDI32.DLL" ALIAS "WidenPath" _
    (BYVAL hdc AS DWORD) AS LONG

DECLARE FUNCTION ExtCreatePen LIB "GDI32.DLL" ALIAS "ExtCreatePen" _
    (BYVAL dwPenStyle AS DWORD, BYVAL dwWidth AS DWORD, lplb AS LOGBRUSH, _
    BYVAL dwStyleCount AS DWORD, lpStyle AS DWORD) AS DWORD

DECLARE FUNCTION GetMiterLimit LIB "GDI32.DLL" ALIAS "GetMiterLimit" _
    (BYVAL hdc AS DWORD, peLimit AS SINGLE) AS LONG

DECLARE FUNCTION GetArcDirection LIB "GDI32.DLL" ALIAS "GetArcDirection" _
    (BYVAL hdc AS DWORD) AS LONG

DECLARE FUNCTION GetObjectA LIB "GDI32.DLL" ALIAS "GetObjectA" _
    (BYVAL hObject AS DWORD, BYVAL nCount AS LONG, lpObject AS ANY) AS LONG

DECLARE FUNCTION GetObjectW LIB "GDI32.DLL" ALIAS "GetObjectW" _
    (BYVAL hObject AS DWORD, BYVAL nCount AS LONG, lpObject AS ANY) AS LONG

#IF %DEF(%UNICODE)
MACRO GetObject=GetObjectW
#ELSE
MACRO GetObject=GetObjectA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION MoveToEx LIB "GDI32.DLL" ALIAS "MoveToEx" _
    (BYVAL hdc AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    lpPoint AS POINT) AS LONG

MACRO MoveTo(hDC,x,y)=MoveToEx(hDC,x,y,BYVAL %NULL)

DECLARE FUNCTION TextOutA LIB "GDI32.DLL" ALIAS "TextOutA" _
    (BYVAL hdc AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    lpString AS ASCIIZ, BYVAL nCount AS LONG) AS LONG

DECLARE FUNCTION TextOutW LIB "GDI32.DLL" ALIAS "TextOutW" _
    (BYVAL hdc AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    lpString AS WSTRINGZ, BYVAL nCount AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO TextOut=TextOutW
#ELSE
MACRO TextOut=TextOutA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION ExtTextOutA LIB "GDI32.DLL" ALIAS "ExtTextOutA" _
    (BYVAL hdc AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    BYVAL dwOptions AS DWORD, lpRect AS RECT, lpString AS ASCIIZ, _
    BYVAL nCount AS DWORD, lpDx AS LONG) AS LONG

DECLARE FUNCTION ExtTextOutW LIB "GDI32.DLL" ALIAS "ExtTextOutW" _
    (BYVAL hdc AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, _
    BYVAL dwOptions AS DWORD, lpRect AS RECT, lpString AS WSTRINGZ, _
    BYVAL nCount AS DWORD, lpDx AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO ExtTextOut=ExtTextOutW
#ELSE
MACRO ExtTextOut=ExtTextOutA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION PolyTextOutA LIB "GDI32.DLL" ALIAS "PolyTextOutA" _
    (BYVAL hdc AS DWORD, pptxt AS POLYTEXTA, cStrings AS LONG) AS LONG

DECLARE FUNCTION PolyTextOutW LIB "GDI32.DLL" ALIAS "PolyTextOutW" _
    (BYVAL hdc AS DWORD, pptxt AS POLYTEXTW, cStrings AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO PolyTextOut=PolyTextOutW
#ELSE
MACRO PolyTextOut=PolyTextOutA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CreatePolygonRgn LIB "GDI32.DLL" ALIAS "CreatePolygonRgn" _
    (lpPoint AS POINT, BYVAL nCount AS LONG, BYVAL nPolyFillMode AS LONG) _
    AS DWORD

DECLARE FUNCTION DPtoLP LIB "GDI32.DLL" ALIAS "DPtoLP" (BYVAL hdc AS DWORD, _
    lpPoint AS POINT, BYVAL nCount AS LONG) AS LONG

DECLARE FUNCTION LPtoDP LIB "GDI32.DLL" ALIAS "LPtoDP" (BYVAL hdc AS DWORD, _
    lpPoint AS POINT, BYVAL nCount AS LONG) AS LONG

DECLARE FUNCTION POLYGON LIB "GDI32.DLL" ALIAS "Polygon" (BYVAL hdc AS DWORD, _
    lpPoint AS POINT, BYVAL nCount AS LONG) AS LONG

DECLARE FUNCTION POLYLINE LIB "GDI32.DLL" ALIAS "Polyline" _
    (BYVAL hdc AS DWORD, lpPoint AS POINT, BYVAL nCount AS LONG) AS LONG

DECLARE FUNCTION PolyBezier LIB "GDI32.DLL" ALIAS "PolyBezier" _
    (BYVAL hdc AS DWORD, lppt AS POINT, BYVAL cPoints AS DWORD) AS LONG

DECLARE FUNCTION PolyBezierTo LIB "GDI32.DLL" ALIAS "PolyBezierTo" _
    (BYVAL hdc AS DWORD, lppt AS POINT, BYVAL cCount AS DWORD) AS LONG

DECLARE FUNCTION PolylineTo LIB "GDI32.DLL" ALIAS "PolylineTo" _
    (BYVAL hdc AS DWORD, lppt AS POINT, BYVAL cCount AS DWORD) AS LONG

DECLARE FUNCTION SetViewportExtEx LIB "GDI32.DLL" ALIAS "SetViewportExtEx" _
    (BYVAL hdc AS DWORD, BYVAL nX AS LONG, BYVAL nY AS LONG, _
    lpSize AS SIZEL) AS LONG

DECLARE FUNCTION SetViewportOrgEx LIB "GDI32.DLL" ALIAS "SetViewportOrgEx" _
    (BYVAL hdc AS DWORD, BYVAL nX AS LONG, BYVAL nY AS LONG, _
    lpPoint AS POINT) AS LONG

DECLARE FUNCTION SetWindowExtEx LIB "GDI32.DLL" ALIAS "SetWindowExtEx" _
    (BYVAL hdc AS DWORD, BYVAL nX AS LONG, BYVAL nY AS LONG, lpSize AS SIZEL) _
    AS LONG

DECLARE FUNCTION SetWindowOrgEx LIB "GDI32.DLL" ALIAS "SetWindowOrgEx" _
    (BYVAL hdc AS DWORD, BYVAL nX AS LONG, BYVAL nY AS LONG, _
    lpPoint AS POINT) AS LONG

DECLARE FUNCTION OffsetViewportOrgEx LIB "GDI32.DLL" _
    ALIAS "OffsetViewportOrgEx" (BYVAL hdc AS DWORD, BYVAL nX AS LONG, _
    BYVAL nY AS LONG, lpPoint AS POINT) AS LONG

DECLARE FUNCTION OffsetWindowOrgEx LIB "GDI32.DLL" ALIAS "OffsetWindowOrgEx" _
    (BYVAL hdc AS DWORD, BYVAL nX AS LONG, BYVAL nY AS LONG, _
    lpPoint AS POINT) AS LONG

DECLARE FUNCTION ScaleViewportExtEx LIB "GDI32.DLL" _
    ALIAS "ScaleViewportExtEx" (BYVAL hdc AS DWORD, BYVAL nXnum AS LONG, _
    BYVAL nXdenom AS LONG, BYVAL nYnum AS LONG, BYVAL nYdenom AS LONG, _
    lpSize AS SIZEL) AS LONG

DECLARE FUNCTION ScaleWindowExtEx LIB "GDI32.DLL" ALIAS "ScaleWindowExtEx" _
    (BYVAL hdc AS DWORD, BYVAL nXnum AS LONG, BYVAL nXdenom AS LONG, _
    BYVAL nYnum AS LONG, BYVAL nYdenom AS LONG, lpSize AS SIZEL) AS LONG

DECLARE FUNCTION SetBitmapDimensionEx LIB "GDI32.DLL" _
    ALIAS "SetBitmapDimensionEx" (BYVAL hbm AS DWORD, BYVAL nX AS LONG, _
    BYVAL nY AS LONG, lpSize AS SIZEL) AS LONG

DECLARE FUNCTION SetBrushOrgEx LIB "GDI32.DLL" ALIAS "SetBrushOrgEx" _
    (BYVAL hdc AS DWORD, BYVAL nXOrg AS LONG, BYVAL nYOrg AS LONG, _
    lppt AS POINT) AS LONG

DECLARE FUNCTION GetTextFaceA LIB "GDI32.DLL" ALIAS "GetTextFaceA" _
    (BYVAL hdc AS DWORD, BYVAL nCount AS LONG, lpFacename AS ASCIIZ) AS LONG

DECLARE FUNCTION GetTextFaceW LIB "GDI32.DLL" ALIAS "GetTextFaceW" _
    (BYVAL hdc AS DWORD, BYVAL nCount AS LONG, lpFacename AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO GetTextFace=GetTextFaceW
#ELSE
MACRO GetTextFace=GetTextFaceA
#ENDIF ' NOT %UNICODE

%FONTMAPPER_MAX = 10

TYPE KERNINGPAIR
    wFirst      AS WORD
    wSecond     AS WORD
    iKernAmount AS LONG
END TYPE

DECLARE FUNCTION GetKerningPairsA LIB "GDI32.DLL" ALIAS "GetKerningPairsA" _
    (BYVAL hdc AS DWORD, BYVAL cPairs AS DWORD, lpkrnpair AS KERNINGPAIR) _
    AS DWORD

DECLARE FUNCTION GetKerningPairsW LIB "GDI32.DLL" ALIAS "GetKerningPairsW" _
    (BYVAL hdc AS DWORD, BYVAL cPairs AS DWORD, lpkrnpair AS KERNINGPAIR) _
    AS DWORD

#IF %DEF(%UNICODE)
MACRO GetKerningPairs=GetKerningPairsW
#ELSE
MACRO GetKerningPairs=GetKerningPairsA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetDCOrgEx LIB "GDI32.DLL" ALIAS "GetDCOrgEx" _
    (BYVAL hdc AS DWORD, lpPoint AS POINT) AS LONG

DECLARE FUNCTION FixBrushOrgEx LIB "GDI32.DLL" ALIAS "FixBrushOrgEx" _
    (BYVAL hDC AS DWORD, BYVAL n1 AS LONG, BYVAL n2 AS LONG, _
    lpPoint AS POINT) AS LONG

DECLARE FUNCTION UnrealizeObject LIB "GDI32.DLL" ALIAS "UnrealizeObject" _
    (BYVAL hObject AS DWORD) AS LONG

DECLARE FUNCTION GdiFlush LIB "GDI32.DLL" ALIAS "GdiFlush" () AS LONG

DECLARE FUNCTION GdiSetBatchLimit LIB "GDI32.DLL" ALIAS "GdiSetBatchLimit" _
    (BYVAL dwLimit AS DWORD) AS DWORD

DECLARE FUNCTION GdiGetBatchLimit LIB "GDI32.DLL" ALIAS "GdiGetBatchLimit" _
    () AS DWORD

#IF (%WINVER >= &H0400)

%ICM_OFF             = 1
%ICM_ON              = 2
%ICM_QUERY           = 3
%ICM_DONE_OUTSIDEDC  = 4

DECLARE FUNCTION ICMENUMPROCA (lpszFilename AS ASCIIZ, _
    BYVAL lparam AS LONG) AS LONG

DECLARE FUNCTION ICMENUMPROCW (lpszFilename AS WSTRINGZ, _
    BYVAL lparam AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO ICMENUMPROC=ICMENUMPROCW
#ELSE
MACRO ICMENUMPROC=ICMENUMPROCA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetICMMode LIB "GDI32.DLL" ALIAS "SetICMMode" _
    (BYVAL hdc AS DWORD, BYVAL n AS LONG) AS LONG

DECLARE FUNCTION CheckColorsInGamut LIB "GDI32.DLL" _
    ALIAS "CheckColorsInGamut" (BYVAL hDC AS DWORD, lpRGBTriples AS ANY, _
    lpBuffer AS ANY, BYVAL nCount AS DWORD) AS LONG

DECLARE FUNCTION GetColorSpace LIB "GDI32.DLL" ALIAS "GetColorSpace" _
    (BYVAL hdc AS DWORD) AS DWORD

DECLARE FUNCTION GetLogColorSpaceA LIB "GDI32.DLL" ALIAS "GetLogColorSpaceA" _
    (BYVAL hColorSpace AS DWORD, lpBuffer AS LOGCOLORSPACEA, _
    BYVAL nSize AS DWORD) AS LONG

DECLARE FUNCTION GetLogColorSpaceW LIB "GDI32.DLL" ALIAS "GetLogColorSpaceW" _
    (BYVAL hColorSpace AS DWORD, lpBuffer AS LOGCOLORSPACEW, _
    BYVAL nSize AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO GetLogColorSpace=GetLogColorSpaceW
#ELSE
MACRO GetLogColorSpace=GetLogColorSpaceA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION CreateColorSpaceA LIB "GDI32.DLL" ALIAS "CreateColorSpaceA" _
    (lpLogColorSpace AS LOGCOLORSPACEA) AS DWORD

DECLARE FUNCTION CreateColorSpaceW LIB "GDI32.DLL" ALIAS "CreateColorSpaceW" _
    (lpLogColorSpace AS LOGCOLORSPACEW) AS DWORD

#IF %DEF(%UNICODE)
MACRO CreateColorSpace=CreateColorSpaceW
#ELSE
MACRO CreateColorSpace=CreateColorSpaceA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetColorSpace LIB "GDI32.DLL" ALIAS "SetColorSpace" _
    (BYVAL hdc AS DWORD, BYVAL hColorSpace AS DWORD) AS DWORD

DECLARE FUNCTION DeleteColorSpace LIB "GDI32.DLL" ALIAS "DeleteColorSpace" _
    (BYVAL hColorSpace AS DWORD) AS LONG

DECLARE FUNCTION GetICMProfileA LIB "GDI32.DLL" ALIAS "GetICMProfileA" _
    (BYVAL hDC AS DWORD, BYVAL lpcbName AS DWORD, lpszFilename AS ASCIIZ) _
    AS LONG

DECLARE FUNCTION GetICMProfileW LIB "GDI32.DLL" ALIAS "GetICMProfileW" _
    (BYVAL hDC AS DWORD, BYVAL lpcbName AS DWORD, lpszFilename AS WSTRINGZ) _
    AS LONG

#IF %DEF(%UNICODE)
MACRO GetICMProfile=GetICMProfileW
#ELSE
MACRO GetICMProfile=GetICMProfileA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetICMProfileA LIB "GDI32.DLL" ALIAS "SetICMProfileA" _
    (BYVAL hDC AS DWORD, lpFileName AS ASCIIZ) AS LONG

DECLARE FUNCTION SetICMProfileW LIB "GDI32.DLL" ALIAS "SetICMProfileW" _
    (BYVAL hDC AS DWORD, lpFileName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO SetICMProfile=SetICMProfileW
#ELSE
MACRO SetICMProfile=SetICMProfileA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetDeviceGammaRamp LIB "GDI32.DLL" _
    ALIAS "GetDeviceGammaRamp" (BYVAL hDC AS DWORD, lpRamp AS ANY) AS LONG

DECLARE FUNCTION SetDeviceGammaRamp LIB "GDI32.DLL" _
    ALIAS "SetDeviceGammaRamp" (BYVAL hDC AS DWORD, lpRamp AS ANY) AS LONG

DECLARE FUNCTION ColorMatchToTarget LIB "GDI32.DLL" _
    ALIAS "ColorMatchToTarget" (BYVAL hDC AS DWORD, BYVAL hdcTarget AS DWORD, _
    BYVAL uiAction AS DWORD) AS LONG

DECLARE FUNCTION EnumICMProfilesA LIB "GDI32.DLL" ALIAS "EnumICMProfilesA" _
    (BYVAL hdc AS DWORD, BYVAL icmEnumProc AS DWORD, BYVAL lParam AS LONG) _
    AS LONG

DECLARE FUNCTION EnumICMProfilesW LIB "GDI32.DLL" ALIAS "EnumICMProfilesW" _
    (BYVAL hdc AS DWORD, BYVAL icmEnumProc AS DWORD, BYVAL lParam AS LONG) _
    AS LONG

#IF %DEF(%UNICODE)
MACRO EnumICMProfiles=EnumICMProfilesW
#ELSE
MACRO EnumICMProfiles=EnumICMProfilesA
#ENDIF ' NOT %UNICODE

' The Win95 update API UpdateICMRegKeyA is deprecated to set last error to ERROR_NOT_SUPPORTED and return FALSE
DECLARE FUNCTION UpdateICMRegKeyA LIB "GDI32.DLL" ALIAS "UpdateICMRegKeyA" _
    (BYVAL dwReserved AS DWORD, lpszCMID AS ASCIIZ, lpszFileName AS ASCIIZ, _
    BYVAL nCommand AS DWORD) AS LONG

' The Win95 update API UpdateICMRegKeyW is deprecated to set last error to ERROR_NOT_SUPPORTED and return FALSE
DECLARE FUNCTION UpdateICMRegKeyW LIB "GDI32.DLL" ALIAS "UpdateICMRegKeyW" _
    (BYVAL dwReserved AS DWORD, lpszCMID AS WSTRINGZ, _
    lpszFileName AS WSTRINGZ, BYVAL nCommand AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO UpdateICMRegKey=UpdateICMRegKeyW
#ELSE
MACRO UpdateICMRegKey=UpdateICMRegKeyA
#ENDIF ' NOT %UNICODE

#ENDIF ' WINVER >= &H0400

#IF (%WINVER >= &H0500)

DECLARE FUNCTION ColorCorrectPalette LIB "GDI32.DLL" _
    ALIAS "ColorCorrectPalette" (BYVAL hDC AS DWORD, BYVAL hPalette AS DWORD, _
    BYVAL dwFirstEntry AS DWORD, BYVAL dwNumOfEntries AS DWORD) AS LONG

#ENDIF

#IF NOT %DEF(%NOMETAFILE)

' Enhanced metafile constants.

%ENHMETA_SIGNATURE       = &H464D4520

' Stock object flag used in the object handle index in the enhanced
' metafile records.
' E.g. The object handle index (META_STOCK_OBJECT | BLACK_BRUSH)
' represents the stock object BLACK_BRUSH.

%ENHMETA_STOCK_OBJECT    = &H80000000???

' Enhanced metafile record types.

%EMR_HEADER                    = 1
%EMR_POLYBEZIER                = 2
%EMR_POLYGON                   = 3
%EMR_POLYLINE                  = 4
%EMR_POLYBEZIERTO              = 5
%EMR_POLYLINETO                = 6
%EMR_POLYPOLYLINE              = 7
%EMR_POLYPOLYGON               = 8
%EMR_SETWINDOWEXTEX            = 9
%EMR_SETWINDOWORGEX            = 10
%EMR_SETVIEWPORTEXTEX          = 11
%EMR_SETVIEWPORTORGEX          = 12
%EMR_SETBRUSHORGEX             = 13
%EMR_EOF                       = 14
%EMR_SETPIXELV                 = 15
%EMR_SETMAPPERFLAGS            = 16
%EMR_SETMAPMODE                = 17
%EMR_SETBKMODE                 = 18
%EMR_SETPOLYFILLMODE           = 19
%EMR_SETROP2                   = 20
%EMR_SETSTRETCHBLTMODE         = 21
%EMR_SETTEXTALIGN              = 22
%EMR_SETCOLORADJUSTMENT        = 23
%EMR_SETTEXTCOLOR              = 24
%EMR_SETBKCOLOR                = 25
%EMR_OFFSETCLIPRGN             = 26
%EMR_MOVETOEX                  = 27
%EMR_SETMETARGN                = 28
%EMR_EXCLUDECLIPRECT           = 29
%EMR_INTERSECTCLIPRECT         = 30
%EMR_SCALEVIEWPORTEXTEX        = 31
%EMR_SCALEWINDOWEXTEX          = 32
%EMR_SAVEDC                    = 33
%EMR_RESTOREDC                 = 34
%EMR_SETWORLDTRANSFORM         = 35
%EMR_MODIFYWORLDTRANSFORM      = 36
%EMR_SELECTOBJECT              = 37
%EMR_CREATEPEN                 = 38
%EMR_CREATEBRUSHINDIRECT       = 39
%EMR_DELETEOBJECT              = 40
%EMR_ANGLEARC                  = 41
%EMR_ELLIPSE                   = 42
%EMR_RECTANGLE                 = 43
%EMR_ROUNDRECT                 = 44
%EMR_ARC                       = 45
%EMR_CHORD                     = 46
%EMR_PIE                       = 47
%EMR_SELECTPALETTE             = 48
%EMR_CREATEPALETTE             = 49
%EMR_SETPALETTEENTRIES         = 50
%EMR_RESIZEPALETTE             = 51
%EMR_REALIZEPALETTE            = 52
%EMR_EXTFLOODFILL              = 53
%EMR_LINETO                    = 54
%EMR_ARCTO                     = 55
%EMR_POLYDRAW                  = 56
%EMR_SETARCDIRECTION           = 57
%EMR_SETMITERLIMIT             = 58
%EMR_BEGINPATH                 = 59
%EMR_ENDPATH                   = 60
%EMR_CLOSEFIGURE               = 61
%EMR_FILLPATH                  = 62
%EMR_STROKEANDFILLPATH         = 63
%EMR_STROKEPATH                = 64
%EMR_FLATTENPATH               = 65
%EMR_WIDENPATH                 = 66
%EMR_SELECTCLIPPATH            = 67
%EMR_ABORTPATH                 = 68

%EMR_GDICOMMENT                = 70
%EMR_FILLRGN                   = 71
%EMR_FRAMERGN                  = 72
%EMR_INVERTRGN                 = 73
%EMR_PAINTRGN                  = 74
%EMR_EXTSELECTCLIPRGN          = 75
%EMR_BITBLT                    = 76
%EMR_STRETCHBLT                = 77
%EMR_MASKBLT                   = 78
%EMR_PLGBLT                    = 79
%EMR_SETDIBITSTODEVICE         = 80
%EMR_STRETCHDIBITS             = 81
%EMR_EXTCREATEFONTINDIRECTW    = 82
%EMR_EXTTEXTOUTA               = 83
%EMR_EXTTEXTOUTW               = 84
%EMR_POLYBEZIER16              = 85
%EMR_POLYGON16                 = 86
%EMR_POLYLINE16                = 87
%EMR_POLYBEZIERTO16            = 88
%EMR_POLYLINETO16              = 89
%EMR_POLYPOLYLINE16            = 90
%EMR_POLYPOLYGON16             = 91
%EMR_POLYDRAW16                = 92
%EMR_CREATEMONOBRUSH           = 93
%EMR_CREATEDIBPATTERNBRUSHPT   = 94
%EMR_EXTCREATEPEN              = 95
%EMR_POLYTEXTOUTA              = 96
%EMR_POLYTEXTOUTW              = 97

#IF (%WINVER >= &H0400)
%EMR_SETICMMODE                = 98
%EMR_CREATECOLORSPACE          = 99
%EMR_SETCOLORSPACE             =100
%EMR_DELETECOLORSPACE          =101
%EMR_GLSRECORD                 =102
%EMR_GLSBOUNDEDRECORD          =103
%EMR_PIXELFORMAT               =104
#ENDIF ' WINVER >= &H0400

#IF (%WINVER >= &H0500)
%EMR_RESERVED_105              =105
%EMR_RESERVED_106              =106
%EMR_RESERVED_107              =107
%EMR_RESERVED_108              =108
%EMR_RESERVED_109              =109
%EMR_RESERVED_110              =110
%EMR_COLORCORRECTPALETTE       =111
%EMR_SETICMPROFILEA            =112
%EMR_SETICMPROFILEW            =113
%EMR_ALPHABLEND                =114
%EMR_SETLAYOUT                 =115
%EMR_TRANSPARENTBLT            =116
#IF (%WIN32_WINNT >= %WIN32_WINNT_WIN2K)
%EMR_RESERVED_117              =117
#ENDIF
%EMR_GRADIENTFILL              =118
%EMR_RESERVED_119              =119
%EMR_RESERVED_120              =120
%EMR_COLORMATCHTOTARGETW       =121
%EMR_CREATECOLORSPACEW         =122
#ENDIF ' WINVER >= &H0500

%EMR_MIN                       =  1

#IF (%WINVER >= &H0500)
%EMR_MAX                       =122
#ELSEIF (%WINVER >= &H0400)
%EMR_MAX                       =104
#ELSE
%EMR_MAX                       = 97
#ENDIF

' Base record type for the enhanced metafile.

TYPE EMR
    iType AS DWORD   ' Enhanced metafile record type
    nSize AS DWORD   ' Length of the record in bytes. Must be a multiple of 4.
END TYPE

' Base text record type for the enhanced metafile.

TYPE EMRTEXT
    ptlReference AS POINTL
    nChars       AS DWORD
    offString    AS DWORD   ' Offset to the string
    fOptions     AS DWORD
    rcl          AS RECTL
    offDx        AS DWORD   ' Offset to the inter-character spacing array.
                            ' This is always given.
END TYPE

' Record structures for the enhanced metafile.

TYPE EMRABORTPATH
    emr AS EMR
END TYPE

TYPE EMRBEGINPATH
    emr AS EMR
END TYPE

TYPE EMRENDPATH
    emr AS EMR
END TYPE

TYPE EMRCLOSEFIGURE
    emr AS EMR
END TYPE

TYPE EMRFLATTENPATH
    emr AS EMR
END TYPE

TYPE EMRWIDENPATH
    emr AS EMR
END TYPE

TYPE EMRSETMETARGN
    emr AS EMR
END TYPE

TYPE EMREMRSAVEDC
    emr AS EMR
END TYPE

TYPE EMRREALIZEPALETTE
    emr AS EMR
END TYPE

TYPE EMRSELECTCLIPPATH
    emr   AS EMR
    iMode AS DWORD
END TYPE

TYPE EMRSETBKMODE
    emr   AS EMR
    iMode AS DWORD
END TYPE

TYPE EMRSETMAPMODE
    emr   AS EMR
    iMode AS DWORD
END TYPE

#IF (%WINVER >= &H0500)
TYPE EMRSETLAYOUT
    emr   AS EMR
    iMode AS DWORD
END TYPE
#ENDIF ' WINVER >= &H0500

TYPE EMRSETPOLYFILLMODE
    emr   AS EMR
    iMode AS DWORD
END TYPE

TYPE EMRSETROP2
    emr   AS EMR
    iMode AS DWORD
END TYPE

TYPE EMRSETSTRETCHBLTMODE
    emr   AS EMR
    iMode AS DWORD
END TYPE

TYPE EMRSETICMMODE
    emr   AS EMR
    iMode AS DWORD
END TYPE

TYPE EMRSETTEXTALIGN
    emr   AS EMR
    iMode AS DWORD
END TYPE

TYPE EMRSETMITERLIMIT
    emr         AS EMR
    eMiterLimit AS SINGLE
END TYPE

TYPE EMRRESTOREDC
    emr       AS EMR
    iRelative AS LONG   ' Specifies a relative instance
END TYPE

TYPE EMRSETARCDIRECTION
    emr           AS EMR
    iArcDirection AS DWORD ' Specifies the arc direction in the advanced graphics mode
END TYPE

TYPE EMRSETMAPPERFLAGS
    emr     AS EMR
    dwFlags AS DWORD
END TYPE

TYPE EMRSETTEXTCOLOR
    emr     AS EMR
    crColor AS DWORD
END TYPE

TYPE EMRSETBKCOLOR
    emr     AS EMR
    crColor AS DWORD
END TYPE

TYPE EMRSELECTOBJECT
    emr      AS EMR
    ihObject AS DWORD  ' Object handle index
END TYPE

TYPE EMRDELETEOBJECT
    emr      AS EMR
    ihObject AS DWORD  ' Object handle index
END TYPE

TYPE EMRSELECTPALETTE
    emr      AS EMR
    ihPal    AS DWORD  ' Palette handle index, background mode only
END TYPE

TYPE EMRRESIZEPALETTE
    emr      AS EMR
    ihPal    AS DWORD  ' Palette handle index
    cEntries AS DWORD
END TYPE

TYPE EMRSELECTCOLORSPACE
    emr  AS EMR
    ihCS AS DWORD    ' ColorSpace handle index
END TYPE

TYPE EMRDELETECOLORSPACE
    emr  AS EMR
    ihCS AS DWORD    ' ColorSpace handle index
END TYPE

TYPE EMRSELECTPALETTE
    emr   AS EMR
    ihPal AS DWORD    ' Palette handle index, background mode only
END TYPE

TYPE EMRRESIZEPALETTE
    emr      AS EMR
    ihPal    AS DWORD    ' Palette handle index
    cEntries AS DWORD
END TYPE

TYPE EMRSETPALETTEENTRIES
    emr            AS EMR
    ihPal          AS DWORD    ' Palette handle index
    iStart         AS DWORD
    cEntries       AS DWORD
    aPalEntries(0) AS PALETTEENTRY  ' The peFlags fields do not contain any flags
END TYPE

TYPE EMRSETCOLORADJUSTMENT
    emr             AS EMR
    ColorAdjustment AS ColorAdjustment
END TYPE

TYPE EMRGDICOMMENT
    emr      AS EMR
    cbData   AS DWORD       ' Size of data in bytes
    xData(0) AS BYTE
END TYPE

TYPE EMREOF
    emr AS EMR
    nPalEntries AS DWORD    ' Number of palette entries
    offPalEntries AS DWORD  ' Offset to the palette entries
    nSizeLast AS DWORD      ' Same as nSize and must be the last DWORD
                            ' of the record. The palette entries, if they
                            ' exist, precede this field.
END TYPE

TYPE EMRLINETO
    emr AS EMR
    ptl AS POINTL
END TYPE

TYPE EMRMOVETOEX
    emr AS EMR
    ptl AS POINTL
END TYPE

TYPE EMROFFSETCLIPRGN
    Emr       AS EMR
    ptlOffset AS POINTL
END TYPE

TYPE EMRFILLPATH
    Emr       AS EMR
    rclBounds AS RECTL    ' inclusive-inclusive bounds in device units
END TYPE

TYPE EMRSTROKEANDFILLPATH
    Emr       AS EMR
    rclBounds AS RECTL    ' inclusive-inclusive bounds in device units
END TYPE

TYPE EMRSTROKEPATH
    Emr       AS EMR
    rclBounds AS RECTL    ' inclusive-inclusive bounds in device units
END TYPE

TYPE EMREXCLUDECLIPRECT
    Emr     AS EMR
    rclClip AS RECTL
END TYPE

TYPE EMRINTERSECTCLIPRECT
    Emr     AS EMR
    rclClip AS RECTL
END TYPE

TYPE EMRSETVIEWPORTORGEX
    Emr       AS EMR
    ptlOrigin AS POINTL
END TYPE

TYPE EMRSETWINDOWORGEX
    Emr       AS EMR
    ptlOrigin AS POINTL
END TYPE

TYPE EMRSETBRUSHORGEX
    Emr       AS EMR
    ptlOrigin AS POINTL
END TYPE

TYPE EMRSETVIEWPORTEXTEX
    Emr       AS EMR
    szlExtent AS SIZEL
END TYPE

TYPE EMRSETWINDOWEXTEX
    Emr       AS EMR
    szlExtent AS SIZEL
END TYPE

TYPE EMRSCALEVIEWPORTEXTEX
    Emr    AS EMR
    xNum   AS LONG
    xDenom AS LONG
    yNum   AS LONG
    yDemon AS LONG
END TYPE

TYPE EMRSCALEWINDOWEXTEX
    Emr    AS EMR
    xNum   AS LONG
    xDenom AS LONG
    yNum   AS LONG
    yDemon AS LONG
END TYPE

TYPE EMRSETWORLDTRANSFORM
    Emr   AS EMR
    xform AS XFORM
END TYPE

TYPE EMRMODIFYWORLDTRANSFORM
    Emr   AS EMR
    xform AS XFORM
    iMode AS DWORD
END TYPE

TYPE EMRSETPIXELV
    Emr      AS EMR
    ptlPixel AS POINTL
    crColor  AS DWORD
END TYPE

TYPE EMREXTFLOODFILL
    Emr      AS EMR
    ptlStart AS POINTL
    crColor  AS DWORD
    iMode    AS DWORD
END TYPE

TYPE EMRELLIPSE
    Emr    AS EMR
    rclBox AS RECTL    ' Inclusive-inclusive bounding rectangle
END TYPE

TYPE EMRRECTANGLE
    Emr    AS EMR
    rclBox AS RECTL    ' Inclusive-inclusive bounding rectangle
END TYPE

TYPE EMRROUNDRECT
    Emr       AS EMR
    rclBox    AS RECTL    ' Inclusive-inclusive bounding rectangle
    szlCorner AS SIZEL
END TYPE

TYPE EMRARC
    Emr      AS EMR
    rclBox   AS RECTL    ' Inclusive-inclusive bounding rectangle
    ptlStart AS POINTL
    ptlEnd   AS POINTL
END TYPE

TYPE EMRARCTO
    Emr      AS EMR
    rclBox   AS RECTL    ' Inclusive-inclusive bounding rectangle
    ptlStart AS POINTL
    ptlEnd   AS POINTL
END TYPE

TYPE EMRCHORD
    Emr      AS EMR
    rclBox   AS RECTL    ' Inclusive-inclusive bounding rectangle
    ptlStart AS POINTL
    ptlEnd   AS POINTL
END TYPE

TYPE EMRPIE
    Emr      AS EMR
    rclBox   AS RECTL    ' Inclusive-inclusive bounding rectangle
    ptlStart AS POINTL
    ptlEnd   AS POINTL
END TYPE

TYPE EMRANGLEARC
    Emr         AS EMR
    ptlCenter   AS POINTL
    nRadius     AS LONG
    eStartAngle AS SINGLE
    eSweepAngle AS SINGLE
END TYPE

TYPE EMRPOLYLINE
    Emr       AS EMR
    rclBounds AS RECTL      ' Inclusive-inclusive bounds in device units
    cptl      AS DWORD
    aptl(0)   AS POINTL  ' array size may vary (fake type)
END TYPE

TYPE EMRPOLYBEZIER
    Emr       AS EMR
    rclBounds AS RECTL      ' Inclusive-inclusive bounds in device units
    cptl      AS DWORD
    aptl(0)   AS POINTL  ' array size may vary (fake type)
END TYPE

TYPE EMRPOLYGON
    Emr       AS EMR
    rclBounds AS RECTL      ' Inclusive-inclusive bounds in device units
    cptl      AS DWORD
    aptl(0)   AS POINTL  ' array size may vary (fake type)
END TYPE

TYPE EMRPOLYBEZIERTO
    Emr       AS EMR
    rclBounds AS RECTL      ' Inclusive-inclusive bounds in device units
    cptl      AS DWORD
    aptl(0)   AS POINTL  ' array size may vary (fake type)
END TYPE

TYPE EMRPOLYLINETO
    Emr       AS EMR
    rclBounds AS RECTL      ' Inclusive-inclusive bounds in device units
    cptl      AS DWORD
    aptl(0)   AS POINTL  ' array size may vary (fake type)
END TYPE

TYPE EMRPOLYLINE16
    Emr       AS EMR
    rclBounds AS RECTL      ' Inclusive-inclusive bounds in device units
    cpts      AS DWORD
    aptl(0)   AS POINTL  ' array size may vary (fake type)
END TYPE

TYPE EMRPOLYBEZIER16
    Emr       AS EMR
    rclBounds AS RECTL      ' Inclusive-inclusive bounds in device units
    cpts      AS DWORD
    aptl(0)   AS POINTL  ' array size may vary (fake type)
END TYPE

TYPE EMRPOLYGON16
    Emr       AS EMR
    rclBounds AS RECTL        ' Inclusive-inclusive bounds in device units
    cpts      AS DWORD
    aptl(0)   AS POINTL    ' array size may vary (fake type)
END TYPE

TYPE EMRPOLYBEZIERTO16
    Emr       AS EMR
    rclBounds AS RECTL        ' Inclusive-inclusive bounds in device units
    cpts      AS DWORD
    aptl(0)   AS POINTL    ' array size may vary (fake type)
END TYPE

TYPE EMRPOLYLINETO16
    Emr       AS EMR
    rclBounds AS RECTL        ' Inclusive-inclusive bounds in device units
    cpts      AS DWORD
    aptl(0)   AS POINTL    ' array size may vary (fake type)
END TYPE

TYPE EMRPOLYDRAW
    Emr        AS EMR
    rclBounds  AS RECTL     ' Inclusive-inclusive bounds in device units
    cptl       AS DWORD     ' Number of points
    aptl(0)    AS POINTL    ' Array of points - array size may vary (fake type)
    abTypes(0) AS BYTE      ' Array of point types - array size may vary (fake type)
END TYPE

TYPE EMRPOLYDRAW16
    Emr        AS EMR
    rclBounds  AS RECTL     ' Inclusive-inclusive bounds in device units
    cpts       AS DWORD     ' Number of points
    apts(0)    AS POINTS    ' Array of points - array size may vary (fake type)
    abTypes(0) AS BYTE      ' Array of point types - array size may vary (fake type)
END TYPE

TYPE EMRPOLYPOLYLINE
    Emr            AS EMR
    rclBounds      AS RECTL   ' Inclusive-inclusive bounds in device units
    nPolys         AS DWORD   ' Number of polys
    cptl           AS DWORD   ' Total number of points in all polys
    aPolyCounts(0) AS DWORD   ' Array of point counts for each poly - array size may vary (fake type)
    aptl(0)        AS POINTL  ' Array of points - array size may vary (fake type)
END TYPE

TYPE EMRPOLYPOLYGON
    Emr            AS EMR
    rclBounds      AS RECTL   ' Inclusive-inclusive bounds in device units
    nPolys         AS DWORD   ' Number of polys
    cptl           AS DWORD   ' Total number of points in all polys
    aPolyCounts(0) AS DWORD   ' Array of point counts for each poly - array size may vary (fake type)
    aptl(0)        AS POINTL  ' Array of points - array size may vary (fake type)
END TYPE

TYPE EMRPOLYPOLYLINE16
    Emr            AS EMR
    rclBounds      AS RECTL   ' Inclusive-inclusive bounds in device units
    nPolys         AS DWORD   ' Number of polys
    cpts           AS DWORD   ' Total number of points in all polys
    aPolyCounts(0) AS DWORD   ' Array of point counts for each poly - array size may vary
    apts(0)        AS POINTS  ' Array of points - array size may vary
END TYPE

TYPE EMRINVERTRGN
    Emr        AS EMR
    rclBounds  AS RECTL       ' Inclusive-inclusive bounds in device units
    cbRgnData  AS DWORD       ' Size of region data in bytes
    RgnData(0) AS BYTE        ' array size may vary (fake type)
END TYPE

TYPE EMRPAINTRGN
    Emr        AS EMR
    rclBounds  AS RECTL       ' Inclusive-inclusive bounds in device units
    cbRgnData  AS DWORD       ' Size of region data in bytes
    RgnData(0) AS BYTE        ' array size may vary (fake type)
END TYPE

TYPE EMRFILLRGN
    Emr        AS EMR
    rclBounds  AS RECTL       ' Inclusive-inclusive bounds in device units
    cbRgnData  AS DWORD       ' Size of region data in bytes
    ihBrush    AS DWORD       ' Brush handle index
    RgnData(0) AS BYTE        ' array size may vary (fake type)
END TYPE

TYPE EMRFRAMERGN
    Emr        AS EMR
    rclBounds  AS RECTL       ' Inclusive-inclusive bounds in device units
    cbRgnData  AS DWORD       ' Size of region data in bytes
    ihBrush    AS DWORD       ' Brush handle index
    szlStroke  AS SIZEL
    RgnData(0) AS BYTE        ' array size may vary (fake type)
END TYPE

TYPE EMREXTSELECTCLIPRGN
    Emr        AS EMR
    cbRgnData  AS DWORD       ' Size of region data in bytes
    iMode      AS DWORD
    RgnData(0) AS BYTE        ' array size may vary (fake type)
END TYPE

TYPE EMREXTTEXTOUTA
    Emr           AS EMR
    rclBounds     AS RECTL    ' Inclusive-inclusive bounds in device units
    iGraphicsMode AS DWORD    ' Current graphics mode
    exScale       AS SINGLE   ' X and Y scales from Page units to .01mm units
    eyScale       AS SINGLE   '  if graphics mode is %GM_COMPATIBLE.
    pemrtext      AS EMRTEXT  ' This is followed by the string and spacing array
END TYPE

TYPE EMREXTTEXTOUTW
    Emr           AS EMR
    rclBounds     AS RECTL    ' Inclusive-inclusive bounds in device units
    iGraphicsMode AS DWORD    ' Current graphics mode
    exScale       AS SINGLE   ' X and Y scales from Page units to .01mm units
    eyScale       AS SINGLE   '  if graphics mode is %GM_COMPATIBLE.
    pemrtext      AS EMRTEXT  ' This is followed by the string and spacing array
END TYPE

TYPE EMRPOLYTEXTOUT
    Emr           AS EMR
    rclBounds     AS RECTL    ' Inclusive-inclusive bounds in device units
    iGraphicsMode AS DWORD    ' Current graphics mode
    exScale       AS SINGLE   ' X and Y scales from Page units to .01mm units
    eyScale       AS SINGLE   '  if graphics mode is %GM_COMPATIBLE.
    cStrings      AS LONG     '
    aemrtext(0)   AS EMRTEXT  ' Array of EMRTEXT structures. This is followed
                              ' by the strings and spacing arrays.
END TYPE

TYPE EMRBITBLT
    Emr          AS EMR
    rclBounds    AS RECTL     ' Inclusive-inclusive bounds in device units
    xDest        AS LONG
    yDest        AS LONG
    cxDest       AS LONG
    cyDest       AS LONG
    dwRop        AS DWORD
    xSrc         AS LONG
    ySrc         AS LONG
    xformSrc     AS XFORM   ' Source DC transform
    crBkColorSrc AS DWORD   ' Source DC BkColor in RGB
    iUsageSrc    AS DWORD   ' Source bitmap info color table usage (%DIB_RGB_COLORS)
    offBmiSrc    AS DWORD   ' Offset to the source BITMAPINFO structure
    cbBmiSrc     AS DWORD   ' Size of the source BITMAPINFO structure
    offBitsSrc   AS DWORD   ' Offset to the source bitmap bits
    cbBitsSrc    AS DWORD   ' Size of the source bitmap bits
END TYPE

TYPE EMRSTRETCHBLT
    Emr          AS EMR
    rclBounds    AS RECTL     ' Inclusive-inclusive bounds in device units
    xDest        AS LONG
    yDest        AS LONG
    cxDest       AS LONG
    cyDest       AS LONG
    dwRop        AS DWORD
    xSrc         AS LONG
    ySrc         AS LONG
    xformSrc     AS XFORM  ' Source DC transform
    crBkColorSrc AS DWORD  ' Source DC BkColor in RGB
    iUsageSrc    AS DWORD  ' Source bitmap info color table usage (%DIB_RGB_COLORS)
    offBmiSrc    AS DWORD  ' Offset to the source BITMAPINFO structure
    cbBmiSrc     AS DWORD  ' Size of the source BITMAPINFO structure
    offBitsSrc   AS DWORD  ' Offset to the source bitmap bits
    cbBitsSrc    AS DWORD  ' Size of the source bitmap bits
    cxSrc        AS LONG
    cySrc        AS LONG
END TYPE

TYPE EMRMASKBLT
    Emr          AS EMR
    rclBounds    AS RECTL   ' Inclusive-inclusive bounds in device units
    xDest        AS LONG
    yDest        AS LONG
    cxDest       AS LONG
    cyDest       AS LONG
    dwRop        AS DWORD
    xSrc2        AS LONG
    cyDest2      AS LONG
    dwRop2       AS LONG
    xSrc         AS LONG
    ySrc         AS LONG
    xformSrc     AS XFORM   ' Source DC transform
    crBkColorSrc AS DWORD   ' Source DC BkColor in RGB
    iUsageSrc    AS DWORD   ' Source bitmap info color table usage (%DIB_RGB_COLORS)
    offBmiSrc    AS DWORD   ' Offset to the source BITMAPINFO structure
    cbBmiSrc     AS DWORD   ' Size of the source BITMAPINFO structure
    offBitsSrc   AS DWORD   ' Offset to the source bitmap bits
    cbBitsSrc    AS DWORD   ' Size of the source bitmap bits
    xMask        AS LONG
    yMask        AS LONG
    iUsageMask   AS DWORD   ' Mask bitmap info color table usage
    offBmiMask   AS DWORD   ' Offset to the mask BITMAPINFO structure if any
    cbBmiMask    AS DWORD   ' Size of the mask BITMAPINFO structure if any
    offBitsMask  AS DWORD   ' Offset to the mask bitmap bits if any
    cbBitsMask   AS DWORD   ' Size of the mask bitmap bits if any
END TYPE

TYPE EMRPLGBLT
    Emr          AS EMR
    rclBounds    AS RECTL    ' Inclusive-inclusive bounds in device units
    aptlDest(2)  AS POINTL
    xSrc         AS LONG
    ySrc         AS LONG
    cxSrc        AS LONG
    cySrc        AS LONG
    xformSrc     AS XFORM    ' Source DC transform
    crBkColorSrc AS DWORD    ' Source DC BkColor in RGB
    iUsageSrc    AS DWORD    ' Source bitmap info color table usage (%DIB_RGB_COLORS)
    offBmiSrc    AS DWORD    ' Offset to the source BITMAPINFO structure
    cbBmiSrc     AS DWORD    ' Size of the source BITMAPINFO structure
    offBitsSrc   AS DWORD    ' Offset to the source bitmap bits
    cbBitsSrc    AS DWORD    ' Size of the source bitmap bits
    xMask        AS LONG
    yMask        AS LONG
    iUsageMask   AS DWORD    ' Mask bitmap info color table usage
    offBmiMask   AS DWORD    ' Offset to the mask BITMAPINFO structure if any
    cbBmiMask    AS DWORD    ' Size of the mask BITMAPINFO structure if any
    offBitsMask  AS DWORD    ' Offset to the mask bitmap bits if any
    cbBitsMask   AS DWORD    ' Size of the mask bitmap bits if any
END TYPE

TYPE EMRSETDIBITSTODEVICE
    Emr        AS EMR
    rclBounds  AS RECTL   ' Inclusive-inclusive bounds in device units
    xDest      AS LONG
    yDest      AS LONG
    xSrc       AS LONG
    ySrc       AS LONG
    cxSrc      AS LONG
    cySrc      AS LONG
    offBmiSrc  AS DWORD   ' Offset to the source BITMAPINFO structure
    cbBmiSrc   AS DWORD   ' Size of the source BITMAPINFO structure
    offBitsSrc AS DWORD   ' Offset to the source bitmap bits
    cbBitsSrc  AS DWORD   ' Size of the source bitmap bits
    iUsageSrc  AS DWORD   ' Source bitmap info color table usage
    iStartScan AS DWORD
    cScans     AS DWORD
END TYPE

TYPE EMRSTRETCHDIBITS
    Emr        AS EMR
    rclBounds  AS RECTL    ' Inclusive-inclusive bounds in device units
    xDest      AS LONG
    yDest      AS LONG
    xSrc       AS LONG
    ySrc       AS LONG
    cxSrc      AS LONG
    cySrc      AS LONG
    offBmiSrc  AS DWORD    ' Offset to the source BITMAPINFO structure
    cbBmiSrc   AS DWORD    ' Size of the source BITMAPINFO structure
    offBitsSrc AS DWORD    ' Offset to the source bitmap bits
    cbBitsSrc  AS DWORD    ' Size of the source bitmap bits
    iUsageSrc  AS DWORD    ' Source bitmap info color table usage
    dwRop      AS DWORD
    cxDest     AS LONG
    cyDest     AS LONG
END TYPE

TYPE EMREXTCREATEFONTINDIRECTW
    Emr    AS emr
    ihFont AS DWORD
    elfw   AS EXTLOGFONT
END TYPE


TYPE EMRCREATEPALETTE
    Emr   AS EMR
    ihPal AS DWORD       ' Palette handle index
    lgpl  AS LOGPALETTE  ' The peFlags fields in the palette entries
                         ' do not contain any flags
END TYPE

TYPE EMRCREATEPEN
    Emr   AS EMR
    ihPen AS DWORD    ' Pen handle index
    lopn  AS LOGPEN
END TYPE

TYPE EMREXTCREATEPEN
    Emr     AS EMR
    ihPen   AS DWORD     ' Pen handle index
    offBmi  AS DWORD     ' Offset to the BITMAPINFO structure if any
    cbBmi   AS DWORD     ' Size of the BITMAPINFO structure if any
                         ' The bitmap info is followed by the bitmap bits
                         ' to form a packed DIB.
    offBits AS DWORD     ' Offset to the brush bitmap bits if any
    cbBits  AS DWORD     ' Size of the brush bitmap bits if any
    elp     AS EXTLOGPEN ' The extended pen with the style array
END TYPE

TYPE EMRCREATEBRUSHINDIRECT
    Emr     AS EMR
    ihBrush AS DWORD     ' Brush handle index
    lb      AS LOGBRUSH  ' The style must be %BS_SOLID, %BS_HOLLOW, %BS_NULL or
                         ' %BS_HATCHED.
END TYPE

TYPE EMRCREATEMONOBRUSH
    Emr     AS EMR
    ihBrush AS DWORD   ' Brush handle index
    iUsage  AS DWORD   ' Bitmap info color table usage
    offBmi  AS DWORD   ' Offset to the BITMAPINFO structure
    cbBmi   AS DWORD   ' Size of the BITMAPINFO structure
    offBits AS DWORD   ' Offset to the bitmap bits
    cbBits  AS DWORD   ' Size of the bitmap bits
END TYPE

TYPE EMRCREATEDIBPATTERNBRUSHPT
    Emr     AS EMR
    ihBursh AS DWORD   ' Brush handle index
    iUsage  AS DWORD   ' Bitmap info color table usage
    offBmi  AS DWORD   ' Offset to the BITMAPINFO structure
    cbBmi   AS DWORD   ' Size of the BITMAPINFO structure
                       ' The bitmap info is followed by the bitmap bits
                       ' to form a packed DIB.
    offBits AS DWORD   ' Offset to the bitmap bits
    cbBits  AS DWORD   ' Size of the bitmap bits
END TYPE

TYPE EMRFORMAT
    dSignature AS DWORD   ' Format signature, e.g. %ENHMETA_SIGNATURE.
    nVersion   AS DWORD   ' Format version number.
    cbData     AS DWORD   ' Size of data in bytes.
    offData    AS DWORD   ' Offset to data from %GDICOMMENT_IDENTIFIER.
                          ' It must begin at a DWORD offset.
END TYPE

#IF (%WINVER >= &H0400)

TYPE EMRGLSRECORD
    emr      AS EMR
    cbData   AS DWORD        ' Size of data in bytes
    bData(0) AS BYTE
END TYPE

TYPE EMRGLSBOUNDEDRECORD
    emr       AS EMR
    rclBounds AS RECTL       ' Bounds in recording coordinates
    cbData    AS DWORD       ' Size of data in bytes
    bData(0)  AS BYTE
END TYPE

TYPE EMRPIXELFORMAT
    emr AS EMR
    pfd AS PIXELFORMATDESCRIPTOR
END TYPE

TYPE EMRCREATECOLORSPACE
    emr  AS EMR
    ihCS AS DWORD            ' ColorSpace handle index
    lcs  AS LOGCOLORSPACEA   ' Ansi version of LOGCOLORSPACE
END TYPE

TYPE EMRSETCOLORSPACE
    emr  AS EMR
    ihCS AS DWORD            ' ColorSpace handle index
END TYPE

TYPE EMRSELECTCOLORSPACE
    EMRSETCOLORSPACE
END TYPE

TYPE EMRDELETECOLORSPACE
    EMRSETCOLORSPACE
END TYPE

#ENDIF ' WINVER >= &H0400

#IF (%WINVER >= &H0500)

TYPE EMREXTESCAPE
    emr        AS EMR
    iEscape    AS LONG      ' Escape code
    cbEscData  AS LONG      ' Size of escape data
    EscData(0) AS BYTE      ' Escape data
END TYPE

TYPE EMRDRAWESCAPE
    EMREXTESCAPE
END TYPE

TYPE EMRNAMEDESCAPE
    emr       AS EMR
    iEscape   AS LONG       ' Escape code
    cbDriver  AS LONG       ' Size of driver name
    cbEscData AS LONG       ' Size of escape data
    EscData(0) AS BYTE      ' Driver name and Escape data
END TYPE

%SETICMPROFILE_EMBEDED = &H00000001

TYPE EMRSETICMPROFILE
    Emr      AS EMR
    dwFlags  AS DWORD     ' flags
    cbName   AS DWORD     ' Size of desired profile name
    cbData   AS DWORD     ' Size of raw profile data if attached
    bData(0) AS BYTE      ' Array size is cbName and cbData
END TYPE

TYPE EMRSETICMPROFILEA
    EMRSETICMPROFILE
END TYPE

TYPE EMRSETICMPROFILEW
    EMRSETICMPROFILE
END TYPE


%CREATECOLORSPACE_EMBEDED = &H00000001

TYPE EMRCREATECOLORSPACEW
    emr      AS EMR
    ihCS     AS DWORD           ' ColorSpace handle index
    lcs      AS LOGCOLORSPACEW  ' Unicode version of logical color space structure
    dwFlags  AS DWORD           ' flags
    cbData   AS DWORD           ' size of raw source profile data if attached
    bData(0) AS BYTE            ' Array size is cbData
END TYPE

%COLORMATCHTOTARGET_EMBEDED = &H00000001

TYPE COLORMATCHTOTARGET_type
    emr      AS EMR
    dwAction AS DWORD     ' CS_ENABLE, CS_DISABLE or CS_DELETE_TRANSFORM
    dwFlags  AS DWORD     ' flags
    cbName   AS DWORD     ' Size of desired target profile name
    cbData   AS DWORD     ' Size of raw target profile data if attached
    bData(0) AS BYTE      ' Array size is cbName + cbData
END TYPE

TYPE COLORCORRECTPALETTE_type
    emr         AS EMR
    ihPalette   AS DWORD  ' Palette handle index
    nFirstEntry AS DWORD  ' Index of first entry to correct
    nPalEntries AS DWORD  ' Number of palette entries to correct
    nReserved   AS DWORD  ' Reserved
END TYPE

TYPE EMRALPHABLEND
    emr          AS EMR
    rclBounds    AS RECTL    ' Inclusive-inclusive bounds in device units
    xDest        AS LONG
    yDest        AS LONG
    cxDest       AS LONG
    cyDest       AS LONG
    dwRop        AS DWORD
    xSrc         AS LONG
    ySrc         AS LONG
    xformSrc     AS XFORM    ' Source DC transform
    crBkColorSrc AS DWORD    ' Source DC BkColor in RGB
    iUsageSrc    AS DWORD    ' Source bitmap info color table usage
                             ' (DIB_RGB_COLORS)
    offBmiSrc    AS DWORD    ' Offset to the source BITMAPINFO structure
    cbBmiSrc     AS DWORD    ' Size of the source BITMAPINFO structure
    offBitsSrc   AS DWORD    ' Offset to the source bitmap bits
    cbBitsSrc    AS DWORD    ' Size of the source bitmap bits
    cxSrc        AS LONG
    cySrc        AS LONG
END TYPE

TYPE EMRGRADIENTFILL
    emr       AS EMR
    rclBounds AS RECTL       ' Inclusive-inclusive bounds in device units
    nVer      AS DWORD
    nTri      AS DWORD
    ulMode    AS DWORD
    Ver(0)    AS TRIVERTEX
END TYPE

TYPE EMRTRANSPARENTBLT
    emr       AS EMR
    rclBounds AS RECTL          ' Inclusive-inclusive bounds in device units
    xDest     AS LONG
    yDest     AS LONG
    cxDest    AS LONG
    cyDest    AS LONG
    dwRop     AS DWORD
    xSrc      AS LONG
    ySrc      AS LONG
    xformSrc  AS XFORM          ' Source DC transform
    crBkColorSrc AS COLORREF    ' Source DC BkColor in RGB
    iUsageSrc AS DWORD          ' Source bitmap info color table usage
                                ' (DIB_RGB_COLORS)
    offBmiSrc AS DWORD          ' Offset to the source BITMAPINFO structure
    cbBmiSrc  AS DWORD          ' Size of the source BITMAPINFO structure
    offBitsSrc AS DWORD         ' Offset to the source bitmap bits
    cbBitsSrc AS DWORD          ' Size of the source bitmap bits
    cxSrc     AS LONG
    cySrc     AS LONG
END TYPE


#ENDIF ' WINVER >= &H0500

%GDICOMMENT_IDENTIFIER         = &H43494447
%GDICOMMENT_WINDOWS_METAFILE   = &H80000001???
%GDICOMMENT_BEGINGROUP         = &H00000002
%GDICOMMENT_ENDGROUP           = &H00000003
%GDICOMMENT_MULTIFORMATS       = &H40000004
%EPS_SIGNATURE                 = &H46535045
%GDICOMMENT_UNICODE_STRING     = &H00000040
%GDICOMMENT_UNICODE_END        = &H00000080

#ENDIF  ' NOMETAFILE


' OpenGL wgl prototypes

DECLARE FUNCTION wglCopyContext LIB "OPENGL32.DLL" ALIAS "wglCopyContext" _
    (BYVAL hglrcSrc AS DWORD, BYVAL hlglrcDst AS DWORD, BYVAL dMask AS DWORD) _
    AS LONG

DECLARE FUNCTION wglCreateContext LIB "OPENGL32.DLL" ALIAS "wglCreateContext" _
    (BYVAL hdc AS DWORD) AS DWORD

DECLARE FUNCTION wglCreateLayerContext LIB "OPENGL32.DLL" _
    ALIAS "wglCreateLayerContext" (BYVAL hdc AS DWORD, _
    BYVAL iLayerPlane AS LONG) AS DWORD

DECLARE FUNCTION wglDeleteContext LIB "OPENGL32.DLL" ALIAS "wglDeleteContext" _
    (BYVAL hglrc AS DWORD) AS LONG

DECLARE FUNCTION wglGetCurrentContext LIB "OPENGL32.DLL" _
    ALIAS "wglGetCurrentContext" () AS DWORD

DECLARE FUNCTION wglGetCurrentDC LIB "OPENGL32.DLL" ALIAS "wglGetCurrentDC" _
    () AS DWORD

DECLARE FUNCTION wglGetProcAddress LIB "OPENGL32.DLL" _
    ALIAS "wglGetProcAddress" (lpszProc AS ASCIIZ) AS DWORD

DECLARE FUNCTION wglMakeCurrent LIB "OPENGL32.DLL" ALIAS "wglMakeCurrent" _
    (BYVAL hdc AS DWORD, BYVAL hglrc AS DWORD) AS LONG

DECLARE FUNCTION wglShareLists LIB "OPENGL32.DLL" ALIAS "wglShareLists" _
    (BYVAL hglrc1 AS DWORD, BYVAL hglrc2 AS DWORD) AS LONG

DECLARE FUNCTION wglUseFontBitmapsA LIB "OPENGL32.DLL" _
    ALIAS "wglUseFontBitmapsA" (BYVAL hdc AS DWORD, BYVAL dFirst AS DWORD, _
    BYVAL dCount AS DWORD, BYVAL dListBase AS DWORD) AS LONG

DECLARE FUNCTION wglUseFontBitmapsW LIB "OPENGL32.DLL" _
    ALIAS "wglUseFontBitmapsW" (BYVAL hdc AS DWORD, BYVAL dFirst AS DWORD, _
    BYVAL dCount AS DWORD, BYVAL dListBase AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO wglUseFontBitmaps=wglUseFontBitmapsW
#ELSE
MACRO wglUseFontBitmaps=wglUseFontBitmapsA
#ENDIF ' NOT %UNICODE

' NOTE ** Microsoft incorrectly documents SwapBuffers as being in OPENGL32.DLL
DECLARE FUNCTION SwapBuffers LIB "GDI32.DLL" ALIAS "SwapBuffers" _
    (BYVAL hDC AS DWORD) AS LONG

TYPE POINTFLOAT
    x AS SINGLE
    y AS SINGLE
END TYPE

TYPE GLYPHMETRICSFLOAT
    gmfBlackBoxX     AS SINGLE
    gmfBlackBoxY     AS SINGLE
    gmfptGlyphOrigin AS POINTFLOAT
    gmfCellIncX      AS SINGLE
    gmfCellIncY      AS SINGLE
END TYPE

%WGL_FONT_LINES    = 0
%WGL_FONT_POLYGONS = 1

DECLARE FUNCTION wglUseFontOutlinesA LIB "OPENGL32.DLL" _
    ALIAS "wglUseFontOutlinesA" (BYVAL hdc AS DWORD, BYVAL dFirst AS DWORD, _
    BYVAL dCount AS DWORD, BYVAL dListBase AS DWORD, _
    BYVAL deviation AS SINGLE, BYVAL extrusion AS SINGLE, _
    BYVAL iFormat AS LONG, BYVAL lpgmf AS DWORD) AS LONG

DECLARE FUNCTION wglUseFontOutlinesW LIB "OPENGL32.DLL" _
    ALIAS "wglUseFontOutlinesW" (BYVAL hdc AS DWORD, BYVAL dFirst AS DWORD, _
    BYVAL dCount AS DWORD, BYVAL dListBase AS DWORD, _
    BYVAL deviation AS SINGLE, BYVAL extrusion AS SINGLE, _
    BYVAL iFormat AS LONG, BYVAL lpgmf AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO wglUseFontOutlines=wglUseFontOutlinesW
#ELSE
MACRO wglUseFontOutlines=wglUseFontOutlinesA
#ENDIF ' NOT %UNICODE

' Layer plane descriptor
TYPE LAYERPLANEDESCRIPTOR  ' lpd
    nSize           AS WORD
    nVersion        AS WORD
    dwFlags         AS DWORD
    iPixelType      AS BYTE
    cColorBits      AS BYTE
    cRedBits        AS BYTE
    cRedShift       AS BYTE
    cGreenBits      AS BYTE
    cGreenShift     AS BYTE
    cBlueBits       AS BYTE
    cBlueShift      AS BYTE
    cAlphaBits      AS BYTE
    cAlphaShift     AS BYTE
    cAccumBits      AS BYTE
    cAccumRedBits   AS BYTE
    cAccumGreenBits AS BYTE
    cAccumBlueBits  AS BYTE
    cAccumAlphaBits AS BYTE
    cDepthBits      AS BYTE
    cStencilBits    AS BYTE
    cAuxBuffers     AS BYTE
    iLayerPlane     AS BYTE
    bReserved       AS BYTE
    crTransparent   AS DWORD
END TYPE

' LAYERPLANEDESCRIPTOR flags
%LPD_DOUBLEBUFFER       = &H00000001
%LPD_STEREO             = &H00000002
%LPD_SUPPORT_GDI        = &H00000010
%LPD_SUPPORT_OPENGL     = &H00000020
%LPD_SHARE_DEPTH        = &H00000040
%LPD_SHARE_STENCIL      = &H00000080
%LPD_SHARE_ACCUM        = &H00000100
%LPD_SWAP_EXCHANGE      = &H00000200
%LPD_SWAP_COPY          = &H00000400
%LPD_TRANSPARENT        = &H00001000

%LPD_TYPE_RGBA       = 0
%LPD_TYPE_COLORINDEX = 1

' wglSwapLayerBuffers flags
%WGL_SWAP_MAIN_PLANE    = &H00000001
%WGL_SWAP_OVERLAY1      = &H00000002
%WGL_SWAP_OVERLAY2      = &H00000004
%WGL_SWAP_OVERLAY3      = &H00000008
%WGL_SWAP_OVERLAY4      = &H00000010
%WGL_SWAP_OVERLAY5      = &H00000020
%WGL_SWAP_OVERLAY6      = &H00000040
%WGL_SWAP_OVERLAY7      = &H00000080
%WGL_SWAP_OVERLAY8      = &H00000100
%WGL_SWAP_OVERLAY9      = &H00000200
%WGL_SWAP_OVERLAY10     = &H00000400
%WGL_SWAP_OVERLAY11     = &H00000800
%WGL_SWAP_OVERLAY12     = &H00001000
%WGL_SWAP_OVERLAY13     = &H00002000
%WGL_SWAP_OVERLAY14     = &H00004000
%WGL_SWAP_OVERLAY15     = &H00008000
%WGL_SWAP_UNDERLAY1     = &H00010000
%WGL_SWAP_UNDERLAY2     = &H00020000
%WGL_SWAP_UNDERLAY3     = &H00040000
%WGL_SWAP_UNDERLAY4     = &H00080000
%WGL_SWAP_UNDERLAY5     = &H00100000
%WGL_SWAP_UNDERLAY6     = &H00200000
%WGL_SWAP_UNDERLAY7     = &H00400000
%WGL_SWAP_UNDERLAY8     = &H00800000
%WGL_SWAP_UNDERLAY9     = &H01000000
%WGL_SWAP_UNDERLAY10    = &H02000000
%WGL_SWAP_UNDERLAY11    = &H04000000
%WGL_SWAP_UNDERLAY12    = &H08000000
%WGL_SWAP_UNDERLAY13    = &H10000000
%WGL_SWAP_UNDERLAY14    = &H20000000
%WGL_SWAP_UNDERLAY15    = &H40000000

DECLARE FUNCTION wglDescribeLayerPlane LIB "OPENGL32.DLL" _
    ALIAS "wglDescribeLayerPlane" (BYVAL hdc AS DWORD, _
    BYVAL iPixelFormat AS LONG, BYVAL iLayerPlane AS LONG, _
    BYVAL nBytes AS DWORD, plpd AS LAYERPLANEDESCRIPTOR) AS LONG

DECLARE FUNCTION wglSetLayerPaletteEntries LIB "OPENGL32.DLL" _
    ALIAS "wglSetLayerPaletteEntries" (BYVAL hdc AS DWORD, _
    BYVAL iLayerPlane AS LONG, BYVAL iStart AS LONG, BYVAL cEntries AS LONG, _
    pcr AS DWORD) AS LONG

DECLARE FUNCTION wglGetLayerPaletteEntries LIB "OPENGL32.DLL" _
    ALIAS "wglGetLayerPaletteEntries" (BYVAL hdc AS DWORD, _
    BYVAL iLayerPlane AS LONG, BYVAL iStart AS LONG, BYVAL cEntries AS LONG, _
    pcr AS DWORD) AS LONG

DECLARE FUNCTION wglRealizeLayerPalette LIB "OPENGL32.DLL" _
    ALIAS "wglRealizeLayerPalette" (BYVAL hdc AS DWORD, _
    BYVAL iLayerPlane AS LONG, BYVAL fRealize AS LONG) AS LONG

DECLARE FUNCTION wglSwapLayerBuffers LIB "OPENGL32.DLL" _
    ALIAS "wglSwapLayerBuffers" (BYVAL hdc AS DWORD, BYVAL dfPlanes AS DWORD) _
    AS LONG

#IF (%WINVER >= &H0500)

TYPE WGLSWAP
    hdc     AS DWORD
    uiFlags AS DWORD
END TYPE

%WGL_SWAPMULTIPLE_MAX = 16

' [undocumented function]
DECLARE FUNCTION wglSwapMultipleBuffers LIB "OPENGL32.DLL" _
    ALIAS "wglSwapMultipleBuffers" (BYVAL u AS DWORD, _
    BYVAL wglswapptr AS DWORD) AS DWORD

#ENDIF ' (%WINVER >= &H0500)

#ENDIF ' %NOGDI
