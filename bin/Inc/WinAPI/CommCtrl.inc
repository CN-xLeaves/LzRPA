'------------------------------------------------------------------------------
'
'  CommCtrl.inc -- Interface for the Windows Common Controls
'
'  Copyright (c) 1997-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from CommCtrl.h version 1.2 of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%INC_COMMCTRL = 1
%COMMCTRL_INC = 1

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "WinDef.inc"
#INCLUDE "WinUser.inc"

#IF NOT %DEF(%HRESULT_DEFINED)
%HRESULT_DEFINED = 1
'MACRO HRESULT=LONG
#ENDIF

'
' Users of this header may define any number of these constants to avoid
' the definitions of each functional group.
'
'    %NOTOOLBAR    Customizable bitmap-button toolbar control.
'    %NOUPDOWN     Up and Down arrow increment/decrement control.
'    %NOSTATUSBAR  Status bar control.
'    %NOMENUHELP   APIs to help manage menus, especially with a status bar.
'    %NOTRACKBAR   Customizable column-width tracking control.
'    %NODRAGLIST   APIs to make a listbox source and sink drag&drop actions.
'    %NOPROGRESS   Progress gas gauge.
'    %NOHOTKEY     HotKey control
'    %NOHEADER     Header bar control.
'    %NOIMAGEAPIS  ImageList apis.
'    %NOLISTVIEW   ListView control.
'    %NOTREEVIEW   TreeView control.
'    %NOTABCONTROL Tab control.
'    %NOANIMATE    Animate control.
'    %NOBUTTON     Button control.
'    %NOSTATIC     Static control.
'    %NOEDIT       Edit control.
'    %NOLISTBOX    Listbox control.
'    %NOCOMBOBOX   Combobox control.
'    %NOSCROLLBAR  Scrollbar control.
'    %NOTASKDIALOG Task Dialog.
'
'=============================================================================

%LPSTR_TEXTCALLBACKW    = -1
%LPSTR_TEXTCALLBACKA    = -1
%LPSTR_TEXTCALLBACK     = -1

DECLARE SUB InitCommonControls LIB "ComCtl32.dll" ALIAS "InitCommonControls" ()

' WM_NOTIFY codes (NMHDR.code values)

%NM_FIRST                = 0-0         ' generic to all controls
%NM_LAST                 = 0-99

%LVN_FIRST               = 0-100       ' listview
%LVN_LAST                = 0-199

' Property sheet reserved     (0U-200U) - (0U-299U) - see prsht.h

%HDN_FIRST               = 0-300       ' header
%HDN_LAST                = 0-399

%TVN_FIRST               = 0-400       ' treeview
%TVN_LAST                = 0-499

%TTN_FIRST               = 0-520       ' tooltips
%TTN_LAST                = 0-549

%TCN_FIRST               = 0-550       ' tab control
%TCN_LAST                = 0-580

' Shell reserved               0U-580U -  0U-589U

#IF NOT %DEF(%CDN_FIRST)
%CDN_FIRST               = 0-601       ' common dialog new
#ENDIF
#IF NOT %DEF(%CDN_LAST)
%CDN_LAST                = 0-699
#ENDIF

%TBN_FIRST               = 0-700      ' toolbar
%TBN_LAST                = 0-720

%UDN_FIRST               = 0-721       ' updown
%UDN_LAST                = 0-729

#IF (%WIN32_IE >= &H0300)
%DTN_FIRST               = 0-740       ' datetimepick
%DTN_LAST                = 0-745

%MCN_FIRST               = 0-746       ' monthcal
%MCN_LAST                = 0-752

%DTN_FIRST2              = 0-753       ' datetimepick
%DTN_LAST2               = 0-799

%CBEN_FIRST              = 0-800       ' combo box ex
%CBEN_LAST               = 0-830

%RBN_FIRST               = 0-831       ' rebar
%RBN_LAST                = 0-859
#ENDIF  ' #IF (%WIN32_IE >= &H0300)

#IF (%WIN32_IE >= &H0400)
%IPN_FIRST               = 0-860       ' internet address
%IPN_LAST                = 0-879       ' internet address

%SBN_FIRST               = 0-880       ' status bar
%SBN_LAST                = 0-899

%PGN_FIRST               = 0-900       ' Pager Control
%PGN_LAST                = 0-950
#ENDIF  ' #IF (%WIN32_IE >= &H0400)

#IF (%WIN32_IE >= &H0500)
#IF NOT %DEF(%WMN_FIRST)
%WMN_FIRST               = 0-1000
%WMN_LAST                = 0-1200
#ENDIF
#ENDIF

#IF (%WIN32_WINNT >= &H0501)
%BCN_FIRST               = 0-1250
%BCN_LAST                = 0-1350
#ENDIF

#IF (%WIN32_WINNT >= &H0600)
%TRBN_FIRST               = 0-1501    ' trackbar
%TRBN_LAST                = 0-1519
#ENDIF

#IF %WIN32_IE >= &H0300
TYPE INIT_COMMON_CONTROLSEX
    dwSize AS DWORD   ' size of this structure
    dwICC  AS DWORD   ' flags indicating which classes to be initialized
END TYPE

%ICC_LISTVIEW_CLASSES   = &H00000001 ' listview, header
%ICC_TREEVIEW_CLASSES   = &H00000002 ' treeview, tooltips
%ICC_BAR_CLASSES        = &H00000004 ' toolbar, statusbar, trackbar, tooltips
%ICC_TAB_CLASSES        = &H00000008 ' tab, tooltips
%ICC_UPDOWN_CLASS       = &H00000010 ' updown
%ICC_PROGRESS_CLASS     = &H00000020 ' progress
%ICC_HOTKEY_CLASS       = &H00000040 ' hotkey
%ICC_ANIMATE_CLASS      = &H00000080 ' animate
%ICC_WIN95_CLASSES      = &H000000FF
%ICC_DATE_CLASSES       = &H00000100 ' month picker, date picker, time picker, updown
%ICC_USEREX_CLASSES     = &H00000200 ' comboex
%ICC_COOL_CLASSES       = &H00000400 ' rebar (coolbar) control
#IF %WIN32_IE >= &H0400
%ICC_INTERNET_CLASSES   = &H00000800
%ICC_PAGESCROLLER_CLASS = &H00001000 ' page scroller
%ICC_NATIVEFNTCTL_CLASS = &H00002000 ' native font control
#ENDIF  ' #IF %WIN32_IE >= &H0400
#IF %WIN32_WINNT >= &H0501
%ICC_STANDARD_CLASSES   = &H00004000
%ICC_LINK_CLASS         = &H00008000
#ENDIF  ' #IF %WIN32_WINNT >= &H0501

DECLARE FUNCTION InitCommonControlsEx LIB "ComCtl32.dll" ALIAS "InitCommonControlsEx" (icc AS INIT_COMMON_CONTROLSEX) AS LONG

#ENDIF  ' #IF %WIN32_IE >= &H0300

%ODT_HEADER             = 100
%ODT_TAB                = 101
%ODT_LISTVIEW           = 102

' Ranges for control message IDs

%LVM_FIRST              = &H1000      ' ListView messages
%TV_FIRST               = &H1100      ' TreeView messages
%HDM_FIRST              = &H1200      ' Header messages
%TCM_FIRST              = &H1300      ' Tab control messages
#IF (%WIN32_IE >= &H0400)
%PGM_FIRST              = &H1400      ' Pager control messages
#IF (%WIN32_WINNT >= &H0501)
%ECM_FIRST              = &H1500      ' Edit control messages
%BCM_FIRST              = &H1600      ' Button control messages
%CBM_FIRST              = &H1700      ' Combobox control messages
#ENDIF  ' #IF (%WIN32_WINNT >= &H0501)
%CCM_FIRST              = &H2000      ' Common control shared messages
%CCM_LAST               = %CCM_FIRST + &H200

%CCM_SETBKCOLOR         = %CCM_FIRST + 1 ' lParam is bkColor

TYPE COLORSCHEME
    dwSize          AS DWORD
    clrBtnHighlight AS COLORREF  ' highlight color
    clrBtnShadow    AS COLORREF  ' shadow color
END TYPE

%CCM_SETCOLORSCHEME     = %CCM_FIRST + 2 ' lParam is color scheme
%CCM_GETCOLORSCHEME     = %CCM_FIRST + 3 ' fills in COLORSCHEME pointed to by lParam
%CCM_GETDROPTARGET      = %CCM_FIRST + 4
%CCM_SETUNICODEFORMAT   = %CCM_FIRST + 5
%CCM_GETUNICODEFORMAT   = %CCM_FIRST + 6

#IF (%WIN32_IE >= &H0500)
#IF (%WIN32_WINNT >= &H0501)
%COMCTL32_VERSION = 6
#ELSE
%COMCTL32_VERSION = 5
#ENDIF

%CCM_SETVERSION         = %CCM_FIRST + 7
%CCM_GETVERSION         = %CCM_FIRST + 8
%CCM_SETNOTIFYWINDOW    = %CCM_FIRST + 9 ' wParam = hwndParent.
#IF (%WIN32_WINNT >= &H0501)
%CCM_SETWINDOWTHEME     = %CCM_FIRST + &Hb
%CCM_DPISCALE           = %CCM_FIRST + &Hc ' wParam == Awareness
#ENDIF  ' (%WIN32_WINNT >= &H0501)
#ENDIF  ' (%WIN32_IE >= &H0500)

#ENDIF  ' (%WIN32_IE >= &H0400)

#IF (%WIN32_IE >= &H0400)
' for tooltips
%INFOTIPSIZE = 1024
#ENDIF

'====== WM_NOTIFY Macros =====================================================

MACRO HANDLE_WM_NOTIFY(hwnd, wParam, lParam, fn)=fn(hwnd, wParam, lParam)
MACRO FORWARD_WM_NOTIFY(hwnd, idFrom, pnmhdr, fn)=fn(hwnd, %WM_NOTIFY, idFrom, pnmhdr)


' Generic WM_NOTIFY notification codes

%NM_OUTOFMEMORY     = %NM_FIRST - 1
%NM_CLICK           = %NM_FIRST - 2  ' uses NMCLICK type
%NM_DBLCLK          = %NM_FIRST - 3
%NM_RETURN          = %NM_FIRST - 4
%NM_RCLICK          = %NM_FIRST - 5  ' uses NMCLICK type
%NM_RDBLCLK         = %NM_FIRST - 6
%NM_SETFOCUS        = %NM_FIRST - 7
%NM_KILLFOCUS       = %NM_FIRST - 8
#IF (%WIN32_IE >= &H0300)
%NM_CUSTOMDRAW      = %NM_FIRST - 12
%NM_HOVER           = %NM_FIRST - 13
#ENDIF  '(%WIN32_IE >= &H0300)
#IF (%WIN32_IE >= &H0400)
%NM_NCHITTEST       = %NM_FIRST - 14 ' uses NMMOUSE type
%NM_KEYDOWN         = %NM_FIRST - 15 ' uses NMKEY type
%NM_RELEASEDCAPTURE = %NM_FIRST - 16
%NM_SETCURSOR       = %NM_FIRST - 17 ' uses NMMOUSE type
%NM_CHAR            = %NM_FIRST - 18 ' uses NMCHAR type
#ENDIF  ' (%WIN32_IE >= &H0400)
#IF (%WIN32_IE >= &H0401)
%NM_TOOLTIPSCREATED = %NM_FIRST - 19 ' notify of when the tooltips window is create
#ENDIF  ' (%WIN32_IE >= &H0401)
#IF (%WIN32_IE >= &H0500)
%NM_LDOWN           = %NM_FIRST - 20
%NM_RDOWN           = %NM_FIRST - 21
%NM_THEMECHANGED    = %NM_FIRST - 22
#ENDIF  ' (%WIN32_IE >= &H0500)

#IF %WIN32_WINNT >= &H0600
%NM_FONTCHANGED          = %NM_FIRST-23
%NM_CUSTOMTEXT           = %NM_FIRST-24   ' uses NMCUSTOMTEXT struct
%NM_TVSTATEIMAGECHANGING = %NM_FIRST-24   ' uses NMTVSTATEIMAGECHANGING struct, defined after HTREEITEM
#ENDIF  ' %WIN32_WINNT >= &H0600

'====== Generic %WM_NOTIFY notification structures ============================
#IF (%WIN32_IE >= &H0401)
TYPE NMTOOLTIPSCREATED
    hdr          AS NMHDR
    hwndToolTips AS DWORD
END TYPE
#ENDIF  ' (%WIN32_IE >= &H0401)

#IF (%WIN32_IE >= &H0400)
TYPE NMMOUSE
    hdr        AS NMHDR
    dwItemSpec AS DWORD
    dwItemData AS DWORD
    pt         AS POINT
    dwHitInfo  AS DWORD ' any specifics about where on the item or control the mouse is
END TYPE

TYPE NMCLICK
    NMMOUSE
END TYPE

' Generic structure to request an object of a specific type.

TYPE NMOBJECTNOTIFY
    hdr     AS NMHDR
    iItem   AS LONG
    piid    AS GUID PTR
    pObject AS DWORD
    hResult AS LONG
    dwFlags AS DWORD    ' control specific flags (hints as to where in iItem it hit)
END TYPE

' Generic structure for a key

TYPE NMKEY
    hdr    AS NMHDR
    nVKey  AS DWORD
    uFlags AS DWORD
END TYPE

' Generic structure for a character

TYPE NMCHAR
    hdr        AS NMHDR
    ch         AS DWORD
    dwItemPrev AS DWORD  ' item previously selected
    dwItemNext AS DWORD  ' item to be selected
END TYPE

#ENDIF           ' %WIN32_IE >= &H0400

#IF (%WIN32_IE >= &H0600)

TYPE NMCUSTOMTEXT
    hd       AS NMHDR
    hdc      AS DWORD
    lpString AS WSTRINGZ PTR
    nCount   AS LONG
    lpRect   AS RECT
    uFormat  AS DWORD
    fLink    AS LONG
END TYPE

#ENDIF  ' %WIN32_IE >= &H0600

%MSGF_COMMCTRL_BEGINDRAG   = &H4200
%MSGF_COMMCTRL_SIZEHEADER  = &H4201
%MSGF_COMMCTRL_DRAGSELECT  = &H4202
%MSGF_COMMCTRL_TOOLBARCUST = &H4203


#IF (%WIN32_IE >= &H0300)
'==============================================================================
' CUSTOM DRAW APIS

' custom draw return flags
' values under &H00010000 are reserved for global custom draw values.
' above that are for specific controls
%CDRF_DODEFAULT          = &H00000000
%CDRF_NEWFONT            = &H00000002
%CDRF_SKIPDEFAULT        = &H00000004
%CDRF_DOERASE            = &H00000008 ' draw the background
%CDRF_SKIPPOSTPAINT      = &H00000100 ' don't draw the focus rect

%CDRF_NOTIFYPOSTPAINT    = &H00000010
%CDRF_NOTIFYITEMDRAW     = &H00000020
#IF (%WIN32_IE >= &H0400)
%CDRF_NOTIFYSUBITEMDRAW  = &H00000020  ' flags are the same, we can distinguish by context
#ENDIF
%CDRF_NOTIFYPOSTERASE    = &H00000040

' drawstage flags
' values under &H00010000 are reserved for global custom draw values.
' above that are for specific controls
%CDDS_PREPAINT           = &H00000001
%CDDS_POSTPAINT          = &H00000002
%CDDS_PREERASE           = &H00000003
%CDDS_POSTERASE          = &H00000004
' the &H000010000 bit means it's individual item specific
%CDDS_ITEM               = &H00010000
%CDDS_ITEMPREPAINT       = (%CDDS_ITEM OR %CDDS_PREPAINT)
%CDDS_ITEMPOSTPAINT      = (%CDDS_ITEM OR %CDDS_POSTPAINT)
%CDDS_ITEMPREERASE       = (%CDDS_ITEM OR %CDDS_PREERASE)
%CDDS_ITEMPOSTERASE      = (%CDDS_ITEM OR %CDDS_POSTERASE)
#IF (%WIN32_IE >= &H0400)
%CDDS_SUBITEM            = &H00020000
#ENDIF

' itemState flags
%CDIS_SELECTED         = &H0001
%CDIS_GRAYED           = &H0002
%CDIS_DISABLED         = &H0004
%CDIS_CHECKED          = &H0008
%CDIS_FOCUS            = &H0010
%CDIS_DEFAULT          = &H0020
%CDIS_HOT              = &H0040
%CDIS_MARKED           = &H0080
%CDIS_INDETERMINATE    = &H0100
#IF (%WIN32_WINNT >= &H0501)
%CDIS_SHOWKEYBOARDCUES = &H0200
#ENDIF
#IF (%WIN32_WINNT >= &H0600)
%CDIS_NEARHOT          = &H0400
%CDIS_OTHERSIDEHOT     = &H0800
%CDIS_DROPHILITED      = &H1000
#ENDIF

TYPE NMCUSTOMDRAW
    hdr         AS NMHDR
    dwDrawStage AS DWORD
    hdc         AS DWORD
    rc          AS RECT
    dwItemSpec  AS DWORD  ' this is control specific, but it's how to specify an item. valid only with CDDS_ITEM bit set
    uItemState  AS DWORD
    lItemlParam AS LONG
END TYPE

TYPE NMTTCUSTOMDRAW
    nmcd       AS NMCUSTOMDRAW
    uDrawFlags AS DWORD
END TYPE

TYPE NMCUSTOMSPLITRECTINFO
    hdr      AS NMHDR
    rcClient AS RECT
    rcButton AS RECT
    rcSplit  AS RECT
END TYPE

%NM_GETCUSTOMSPLITRECT = (%BCN_FIRST + &H0003)

#ENDIF      ' %WIN32_IE >= &H0300


'==============================================================================
' IMAGE APIS

#IF NOT %DEF(%NOIMAGEAPIS) OR (NOT %DEF(%NOTREEVIEW))

%CLR_NONE    = &HFFFFFFFF???
%CLR_DEFAULT = &HFF000000???

#IF NOT %DEF(%IMAGELISTDRAWPARAMS)
#IF (%WIN32_IE >= &H0300)
%IMAGELISTDRAWPARAMS = 1
TYPE IMAGELISTDRAWPARAMS
    cbSize   AS DWORD
    himl     AS DWORD
    i        AS LONG
    hdcDst   AS DWORD
    x        AS LONG
    y        AS LONG
    cx       AS LONG
    cy       AS LONG
    xBitmap  AS LONG      ' x offest from the upperleft of bitmap
    yBitmap  AS LONG      ' y offest from the upperleft of bitmap
    rgbBk    AS COLORREF
    rgbFg    AS COLORREF
    fStyle   AS DWORD
    dwRop    AS DWORD
#IF (%WIN32_IE >= &H0501)
    fState   AS DWORD
    FRAME    AS DWORD
    crEffect AS COLORREF
#ENDIF  ' #IF (%WIN32_IE >= &H0501)
END TYPE

%IMAGELISTDRAWPARAMS_V3_SIZE = 14*4  ' CCSIZEOF_STRUCT(IMAGELISTDRAWPARAMS, dwRop)

#ENDIF  ' %WIN32_IE >= &H0300
#ENDIF  ' #IF NOT %DEF(%IMAGELISTDRAWPARAMS)

%ILC_MASK             = &H00000001
%ILC_COLOR            = &H00000000
%ILC_COLORDDB         = &H000000FE
%ILC_COLOR4           = &H00000004
%ILC_COLOR8           = &H00000008
%ILC_COLOR16          = &H00000010
%ILC_COLOR24          = &H00000018
%ILC_COLOR32          = &H00000020
%ILC_PALETTE          = &H00000800 ' (not implemented)
#IF (%WIN32_WINNT >= &H0501)
%ILC_MIRROR           = &H00002000 ' Mirror the icons contained, if the process is mirrored
%ILC_PERITEMMIRROR    = &H00008000 ' Causes the mirroring code to mirror each item when inserting a set of images, verses the whole strip
#ENDIF
#IF %WIN32_WINNT >= &H0600
%ILC_ORIGINALSIZE     = &H00010000 ' Imagelist should accept smaller than set images and apply OriginalSize based on image added
%ILC_HIGHQUALITYSCALE = &H00020000 ' Imagelist should enable use of the high quality scaler.
#ENDIF

DECLARE FUNCTION ImageList_Create LIB "ComCtl32.dll" ALIAS "ImageList_Create" _
    (BYVAL cx AS LONG, BYVAL cy AS LONG, BYVAL flags AS DWORD, _
    BYVAL cInitial AS LONG, BYVAL cGrow AS LONG) AS DWORD

DECLARE FUNCTION ImageList_Destroy LIB "ComCtl32.dll" _
    ALIAS "ImageList_Destroy" (OPTIONAL BYVAL himl AS DWORD) AS LONG

DECLARE FUNCTION ImageList_GetImageCount LIB "ComCtl32.dll" _
    ALIAS "ImageList_GetImageCount" (BYVAL himl AS DWORD) AS LONG

#IF (%WIN32_IE >= &H0300)
DECLARE FUNCTION ImageList_SetImageCount LIB "ComCtl32.dll" _
    ALIAS "ImageList_SetImageCount" (BYVAL himl AS DWORD, _
    BYVAL uNewCount AS DWORD) AS LONG
#ENDIF

DECLARE FUNCTION ImageList_Add LIB "ComCtl32.dll" ALIAS "ImageList_Add" _
    (BYVAL himl AS DWORD, BYVAL hbmImage AS DWORD, _
    OPTIONAL BYVAL hbmMask AS DWORD) AS LONG

DECLARE FUNCTION ImageList_ReplaceIcon LIB "ComCtl32.dll" _
    ALIAS "ImageList_ReplaceIcon" (BYVAL himl AS DWORD, BYVAL i AS LONG, _
    BYVAL hIcon AS DWORD) AS LONG

DECLARE FUNCTION ImageList_SetBkColor LIB "ComCtl32.dll" _
    ALIAS "ImageList_SetBkColor" (BYVAL himl AS DWORD, BYVAL clrBk AS DWORD) _
    AS DWORD

DECLARE FUNCTION ImageList_GetBkColor LIB "ComCtl32.dll" _
    ALIAS "ImageList_GetBkColor" (BYVAL himl AS DWORD) AS DWORD

DECLARE FUNCTION ImageList_SetOverlayImage LIB "ComCtl32.dll" _
    ALIAS "ImageList_SetOverlayImage" (BYVAL himl AS DWORD, _
    BYVAL iImage AS LONG, BYVAL iOverlay AS LONG) AS LONG

FUNCTION ImageList_AddIcon (BYVAL hIml AS DWORD, hIcon AS DWORD) AS LONG
    FUNCTION = ImageList_ReplaceIcon(hIml, -1, hIcon)
END FUNCTION

%ILD_NORMAL        = &H00000000
%ILD_TRANSPARENT   = &H00000001
%ILD_MASK          = &H00000010
%ILD_IMAGE         = &H00000020
#IF (%WIN32_IE >= &H0300)
%ILD_ROP           = &H00000040
#ENDIF
%ILD_BLEND25       = &H00000002
%ILD_BLEND50       = &H00000004
%ILD_OVERLAYMASK   = &H00000F00
MACRO IndexToOverlayMask(i)=((i)*256)
%ILD_PRESERVEALPHA = &H00001000  ' This preserves the alpha channel in dest
%ILD_SCALE         = &H00002000  ' Causes the image to be scaled to cx, cy instead of clipped
%ILD_DPISCALE      = &H00004000
#IF %WIN32_WINNT >= &H0600
%ILD_ASYNC         = &H00008000
#ENDIF

%ILD_SELECTED      = %ILD_BLEND50
%ILD_FOCUS         = %ILD_BLEND25
%ILD_BLEND         = %ILD_BLEND50
%CLR_HILIGHT       = %CLR_DEFAULT

%ILS_NORMAL        = &H00000000
%ILS_GLOW          = &H00000001
%ILS_SHADOW        = &H00000002
%ILS_SATURATE      = &H00000004
%ILS_ALPHA         = &H00000008

#IF %WIN32_WINNT >= &H0600
%ILGT_NORMAL       = &H00000000
%ILGT_ASYNC        = &H00000001
#ENDIF

DECLARE FUNCTION ImageList_Draw LIB "ComCtl32.dll" ALIAS "ImageList_Draw" _
    (BYVAL himl AS DWORD, BYVAL i AS LONG, BYVAL hdcDst AS DWORD, _
    BYVAL x AS LONG, BYVAL y AS LONG, BYVAL fStyle AS DWORD) AS LONG

#IF %DEF(%WIN32)

#IF %WIN32_WINNT >= &H0600
%HBITMAP_CALLBACK = &HFFFFFFFF???  '((HBITMAP)-1)       // only for SparseImageList
#ENDIF

DECLARE FUNCTION ImageList_Replace LIB "ComCtl32.dll" _
    ALIAS "ImageList_Replace" (BYVAL himl AS DWORD, BYVAL i AS LONG, _
    BYVAL hbmImage AS DWORD, OPTIONAL BYVAL hbmMask AS DWORD) AS LONG

DECLARE FUNCTION ImageList_AddMasked LIB "ComCtl32.dll" _
    ALIAS "ImageList_AddMasked" (BYVAL himl AS DWORD, _
    BYVAL hbmImage AS DWORD, BYVAL crMask AS DWORD) AS LONG

DECLARE FUNCTION ImageList_DrawEx LIB "ComCtl32.dll" ALIAS "ImageList_DrawEx" _
    (BYVAL himl AS DWORD, BYVAL i AS LONG, BYVAL hdcDst AS DWORD, _
    BYVAL x AS LONG, BYVAL y AS LONG, BYVAL dx AS LONG, BYVAL dy AS LONG, _
    BYVAL rgbBk AS DWORD, BYVAL rgbFg AS DWORD, BYVAL fStyle AS DWORD) AS LONG

#IF (%WIN32_IE >= &H0300)
DECLARE FUNCTION ImageList_DrawIndirect LIB "ComCtl32.dll" _
    ALIAS "ImageList_DrawIndirect" (pimldp AS IMAGELISTDRAWPARAMS) AS LONG
#ENDIF

DECLARE FUNCTION ImageList_Remove LIB "ComCtl32.dll" ALIAS "ImageList_Remove" _
    (BYVAL himl AS DWORD, BYVAL i AS LONG) AS LONG

DECLARE FUNCTION ImageList_GetIcon LIB "ComCtl32.dll" _
    ALIAS "ImageList_GetIcon" (BYVAL himl AS DWORD, BYVAL i AS LONG, _
    BYVAL flags AS DWORD) AS DWORD

DECLARE FUNCTION ImageList_LoadImageA LIB "ComCtl32.dll" _
    ALIAS "ImageList_LoadImageA" (BYVAL dhi AS DWORD, lpBmp AS ASCIIZ, _
    BYVAL cx AS LONG, BYVAL cGrow AS LONG, BYVAL crMask AS DWORD, _
    BYVAL uTypw AS DWORD, BYVAL uFlags AS DWORD) AS DWORD

DECLARE FUNCTION ImageList_LoadImageW LIB "ComCtl32.dll" _
    ALIAS "ImageList_LoadImageW" (BYVAL dhi AS DWORD, lpBmp AS WSTRINGZ, _
    BYVAL cx AS LONG, BYVAL cGrow AS LONG, BYVAL crMask AS DWORD, _
    BYVAL uTypw AS DWORD, BYVAL uFlags AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION ImageList_LoadImage LIB "ComCtl32.dll" _
    ALIAS "ImageList_LoadImageW" (BYVAL dhi AS DWORD, lpBmp AS WSTRINGZ, _
    BYVAL cx AS LONG, BYVAL cGrow AS LONG, BYVAL crMask AS DWORD, _
    BYVAL uTypw AS DWORD, BYVAL uFlags AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION ImageList_LoadImage LIB "ComCtl32.dll" _
    ALIAS "ImageList_LoadImageA" (BYVAL dhi AS DWORD, lpBmp AS ASCIIZ, _
    BYVAL cx AS LONG, BYVAL cGrow AS LONG, BYVAL crMask AS DWORD, _
    BYVAL uTypw AS DWORD, BYVAL uFlags AS DWORD) AS DWORD
#ENDIF

#IF (%WIN32_IE >= &H0300)
%ILCF_MOVE = &H00000000
%ILCF_SWAP = &H00000001
DECLARE FUNCTION ImageList_Copy LIB "ComCtl32.dll" ALIAS "ImageList_Copy" _
    (BYVAL himlDst AS DWORD, BYVAL iDst AS LONG, BYVAL himlSrc AS DWORD, _
    BYVAL iSrc AS LONG, BYVAL uFlags AS DWORD) AS LONG
#ENDIF  ' #IF (%WIN32_IE >= &H0300)

DECLARE FUNCTION ImageList_BeginDrag LIB "ComCtl32.dll" _
    ALIAS "ImageList_BeginDrag" (BYVAL himlTrack AS DWORD, _
    BYVAL iTrack AS LONG, BYVAL dxHotSpot AS LONG, BYVAL dyHotSpot AS LONG) _
    AS LONG

DECLARE SUB ImageList_EndDrag LIB "ComCtl32.dll" ALIAS "ImageList_EndDrag" ()

DECLARE FUNCTION ImageList_DragEnter LIB "ComCtl32.dll" _
    ALIAS "ImageList_DragEnter" (BYVAL hWndLock AS DWORD, BYVAL x AS LONG, _
    BYVAL y AS LONG) AS LONG

DECLARE FUNCTION ImageList_DragLeave LIB "ComCtl32.dll" _
    ALIAS "ImageList_DragLeave" (BYVAL hWndLock AS DWORD) AS LONG

DECLARE FUNCTION ImageList_DragMove LIB "ComCtl32.dll" _
    ALIAS "ImageList_DragMove" (BYVAL x AS LONG, BYVAL y AS LONG) AS LONG

DECLARE FUNCTION ImageList_SetDragCursorImage LIB "ComCtl32.dll" _
    ALIAS "ImageList_SetDragCursorImage" (BYVAL himlDrag AS DWORD, _
    BYVAL iDrag AS LONG, BYVAL dxHotSpot AS LONG, BYVAL dyHotSpot AS LONG) _
    AS LONG

DECLARE FUNCTION ImageList_DragShowNolock LIB "ComCtl32.dll" _
    ALIAS "ImageList_DragShowNolock" (BYVAL fShow AS LONG) AS LONG

DECLARE FUNCTION ImageList_GetDragImage LIB "ComCtl32.dll" _
    ALIAS "ImageList_GetDragImage" (ppt AS POINT, pptHotSpot AS POINT) _
    AS DWORD

FUNCTION ImageList_RemoveAll (BYVAL hIml AS DWORD) AS LONG
    FUNCTION = ImageList_Remove(hIml, -1)
END FUNCTION

FUNCTION ImageList_ExtractIcon (BYVAL dhI AS DWORD, BYVAL hIml AS DWORD, _
    BYVAL i AS LONG) AS LONG
    FUNCTION = ImageList_GetIcon(hIml, i, 0)
END FUNCTION

FUNCTION ImageList_LoadBitmapA (BYVAL dhI AS DWORD, lpBmp AS ASCIIZ, _
    BYVAL cx AS LONG, BYVAL cGrow AS LONG, crMask AS LONG) AS LONG
    FUNCTION = ImageList_LoadImageA(dhi, lpBmp, cx, cGrow, crMask, _
        %IMAGE_BITMAP, 0)
END FUNCTION

FUNCTION ImageList_LoadBitmapW (BYVAL dhI AS DWORD, lpBmp AS WSTRINGZ, _
    BYVAL cx AS LONG, BYVAL cGrow AS LONG, crMask AS LONG) AS LONG
    FUNCTION = ImageList_LoadImageW(dhi, lpBmp, cx, cGrow, crMask, _
        %IMAGE_BITMAP, 0)
END FUNCTION

#IF %DEF(%UNICODE)
FUNCTION ImageList_LoadBitmap (BYVAL dhI AS DWORD, lpBmp AS WSTRINGZ, _
    BYVAL cx AS LONG, BYVAL cGrow AS LONG, crMask AS LONG) AS LONG
    FUNCTION = ImageList_LoadImageW(dhi, lpBmp, cx, cGrow, crMask, _
        %IMAGE_BITMAP, 0)
END FUNCTION
#ELSE
FUNCTION ImageList_LoadBitmap (BYVAL dhI AS DWORD, lpBmp AS ASCIIZ, _
    BYVAL cx AS LONG, BYVAL cGrow AS LONG, crMask AS LONG) AS LONG
    FUNCTION = ImageList_LoadImageA(dhi, lpBmp, cx, cGrow, crMask, _
        %IMAGE_BITMAP, 0)
END FUNCTION
#ENDIF

DECLARE FUNCTION ImageList_Read LIB "ComCtl32.dll" ALIAS "ImageList_Read" _
   (pstm AS ANY) AS DWORD

DECLARE FUNCTION ImageList_Write LIB "ComCtl32.dll" ALIAS "ImageList_Write" _
   (BYVAL himl AS DWORD, pstm AS ANY) AS LONG

#IF (%WIN32_WINNT >= &H0501)
%ILP_NORMAL    = 0 ' Writes or reads the stream using new sematics for this version of comctl32
%ILP_DOWNLEVEL = 1 ' Write or reads the stream using downlevel sematics.

DECLARE FUNCTION ImageList_ReadEx LIB "ComCtl32.dll" ALIAS "ImageList_ReadEx" _
   (BYVAL dwFlags AS DWORD, pstm AS ANY, riid AS GUID, ppv AS ANY) AS LONG

DECLARE FUNCTION ImageList_WriteEx LIB "ComCtl32.dll" _
    ALIAS "ImageList_WriteEx" (BYVAL himl AS DWORD, BYVAL dwFlags AS DWORD, _
    pstm AS ANY) AS LONG
#ENDIF  ' #IF (%WIN32_WINNT >= &H0501)

#ENDIF  ' #IF %DEF(%WIN32)

#IF NOT %DEF(%IMAGEINFO)
%IMAGEINFO = 1
TYPE IMAGEINFO
    hbmImage AS DWORD
    hbmMask  AS DWORD
    Unused1  AS LONG
    Unused2  AS LONG
    rcImage  AS RECT
END TYPE
#ENDIF

DECLARE FUNCTION ImageList_GetIconSize LIB "ComCtl32.dll" _
    ALIAS "ImageList_GetIconSize" (BYVAL himl AS DWORD, cx AS LONG, _
    cy AS LONG) AS LONG

DECLARE FUNCTION ImageList_SetIconSize LIB "ComCtl32.dll" _
    ALIAS "ImageList_SetIconSize" (BYVAL himl AS DWORD, BYVAL cx AS LONG, _
    BYVAL cy AS LONG) AS LONG

DECLARE FUNCTION ImageList_GetImageInfo LIB "ComCtl32.dll" _
    ALIAS "ImageList_GetImageInfo" (BYVAL himl AS DWORD, BYVAL i AS LONG, _
    pImageInfo AS IMAGEINFO) AS LONG

DECLARE FUNCTION ImageList_Merge LIB "ComCtl32.dll" ALIAS "ImageList_Merge" _
   (BYVAL himl1 AS DWORD, BYVAL i1 AS LONG, BYVAL himl2 AS DWORD, _
    BYVAL i2 AS LONG, BYVAL dx AS LONG, BYVAL dy AS LONG) AS DWORD

#IF (%WIN32_IE >= &H0400)
DECLARE FUNCTION ImageList_Duplicate LIB "ComCtl32.dll" _
    ALIAS "ImageList_Duplicate" (BYVAL himl AS DWORD) AS DWORD
#ENDIF

#IF (%WIN32_WINNT >= &H0501)

DECLARE FUNCTION HIMAGELIST_QueryInterface LIB "ComCtl32.dll" _
    ALIAS "HIMAGELIST_QueryInterface" (BYVAL himl AS DWORD, _
    BYVAL riid AS GUID PTR, ppv AS ANY) AS LONG

MACRO IImageListToHIMAGELIST(himl)=(himl)

#ENDIF  ' #IF (%WIN32_WINNT >= &H0501)

#ENDIF  ' #IF NOT %DEF(%NOIMAGEAPIS) OR (NOT %DEF(%NOTREEVIEW))


'==============================================================================
' HEADER CONTROL

#IF NOT %DEF(%NOHEADER)

#IF %DEF(%WIN32)
$WC_HEADERA      = "SysHeader32"
$$WC_HEADERW     = "SysHeader32"$$

#IF %DEF(%UNICODE)
MACRO WC_HEADER = $$WC_HEADERW
#ELSE
MACRO WC_HEADER = $WC_HEADERA
#ENDIF  ' #IF %DEF(%UNICODE)

#ELSE
MACRO WC_HEADER = "SysHeader"
#ENDIF  ' #IF %DEF(%WIN32)

%HDS_HORZ        = &H0000
%HDS_BUTTONS     = &H0002
#IF (%WIN32_IE >= &H0300)
%HDS_HOTTRACK    = &H0004
#ENDIF
%HDS_HIDDEN      = &H0008

#IF (%WIN32_IE >= &H0300)
%HDS_DRAGDROP    = &H0040
%HDS_FULLDRAG    = &H0080
#ENDIF
#IF (%WIN32_IE >= &H0500)
%HDS_FILTERBAR   = &H0100
#ENDIF

#IF (%WIN32_WINNT >= &H0501)
%HDS_FLAT        = &H0200
#ENDIF

#IF %WIN32_WINNT >= &H0600
%HDS_CHECKBOXES  = &H0400
%HDS_NOSIZING    = &H0800
%HDS_OVERFLOW    = &H1000
#ENDIF

#IF (%WIN32_IE >= &H0500)

%HDFT_ISSTRING   = &H0000     ' HD_ITEM.pvFilter points to a HD_TEXTFILTER
%HDFT_ISNUMBER   = &H0001     ' HD_ITEM.pvFilter points to a INT
%HDFT_ISDATE     = &H0002     ' HD_ITEM.pvFilter points to a DWORD(dos date)
%HDFT_HASNOVALUE = &H8000???  ' clear the filter, by setting this bit

TYPE HD_TEXTFILTERA
    pszText    AS ASCIIZ PTR  ' [in] pointer to the buffer containing the filter(ANSI)
    cchTextMax AS LONG        ' [in] max size of buffer/edit control buffer
END TYPE

TYPE HD_TEXTFILTERW
    pszText    AS WSTRINGZ PTR  ' [in] pointer to the buffer containing the filter(Unicode)
    cchTextMax AS LONG          ' [in] max size of buffer/edit control buffer
END TYPE

#IF %DEF(%UNICODE)
TYPE HD_TEXTFILTER
    HD_TEXTFILTERW
END TYPE
TYPE HDTEXTFILTER
    HD_TEXTFILTERW
END TYPE
#ELSE
TYPE HD_TEXTFILTER
    HD_TEXTFILTERA
END TYPE
TYPE HDTEXTFILTER
    HD_TEXTFILTERA
END TYPE
#ENDIF

#ENDIF  ' %WIN32_IE >= &H0500

TYPE HDITEMA
    Mask       AS DWORD
    cxy        AS LONG
    pszText    AS ASCIIZ PTR
    hbm        AS DWORD
    cchTextMax AS LONG
    fmt        AS LONG
    lParam     AS LONG
#IF (%WIN32_IE >= &H0300)
    iImage     AS LONG    ' index of bitmap in ImageList
    iOrder     AS LONG    ' where to draw this item
#ENDIF
#IF (%WIN32_IE >= &H0500)
    dType      AS DWORD   ' [in] filter type(defined what pvFilter is a pointer to)
    pvFilter   AS DWORD   ' [in] filter data see above
#ENDIF
#IF %WIN32_WINNT >= &H0600
    State      AS DWORD
#ENDIF
END TYPE

%HDITEMA_V1_SIZE = 4+4+4+4+4+4+4 ' CCSIZEOF_STRUCT(HDITEMA, lParam)

TYPE HDITEMW
    Mask       AS DWORD
    cxy        AS LONG
    pszText    AS WSTRINGZ PTR
    hbm        AS DWORD
    cchTextMax AS LONG
    fmt        AS LONG
    lParam     AS LONG
#IF (%WIN32_IE >= &H0300)
    iImage     AS LONG    ' index of bitmap in ImageList
    iOrder     AS LONG    ' where to draw this item
#ENDIF
#IF (%WIN32_IE >= &H0500)
    dType      AS DWORD   ' [in] filter type(defined what pvFilter is a pointer to)
    pvFilter   AS DWORD   ' [in] filter data see above
#ENDIF
#IF %WIN32_WINNT >= &H0600
    State      AS DWORD
#ENDIF
END TYPE

%HDITEMW_V1_SIZE = 4+4+4+4+4+4+4 ' CCSIZEOF_STRUCT(HDITEMW, lParam)

#IF %DEF(%UNICODE)
TYPE HDITEM
    HDITEMW
END TYPE
%HDITEM_V1_SIZE=%HDITEMW_V1_SIZE
#ELSE
TYPE HDITEM
    HDITEMA
END TYPE
%HDITEM_V1_SIZE=%HDITEMA_V1_SIZE
#ENDIF

#IF (%WIN32_IE >= &H0300)
TYPE HD_ITEMA
    HDITEMA
END TYPE
TYPE HD_ITEMW
    HDITEMW
END TYPE
#ELSE
TYPE HDITEMW
    HD_ITEMW
END TYPE
TYPE HDITEMA
    HD_ITEMA
END TYPE
#ENDIF
TYPE HD_ITEM
    HDITEM
END TYPE

%HDI_WIDTH           = &H0001
%HDI_HEIGHT          = %HDI_WIDTH
%HDI_TEXT            = &H0002
%HDI_FORMAT          = &H0004
%HDI_LPARAM          = &H0008
%HDI_BITMAP          = &H0010
#IF (%WIN32_IE >= &H0300)
%HDI_IMAGE           = &H0020
%HDI_DI_SETITEM      = &H0040
%HDI_ORDER           = &H0080
#ENDIF
#IF (%WIN32_IE >= &H0500)
%HDI_FILTER          = &H0100
#ENDIF
#IF %WIN32_WINNT >= &H0600
%HDI_STATE           = &H0200
#ENDIF

' HDF_ flags are shared with the listview control(LVCFMT_ flags)

%HDF_LEFT                = &H0000 ' Same as LVCFMT_LEFT
%HDF_RIGHT               = &H0001 ' Same as LVCFMT_RIGHT
%HDF_CENTER              = &H0002 ' Same as LVCFMT_CENTER
%HDF_JUSTIFYMASK         = &H0003 ' Same as LVCFMT_JUSTIFYMASK
%HDF_RTLREADING          = &H0004 ' Same as LVCFMT_LEFT

%HDF_BITMAP              = &H2000
%HDF_STRING              = &H4000
%HDF_OWNERDRAW           = &H8000??? ' Same as LVCFMT_COL_HAS_IMAGES
#IF (%WIN32_IE >= &H0300)
%HDF_IMAGE               = &H0800 ' Same as LVCFMT_IMAGE
%HDF_BITMAP_ON_RIGHT     = &H1000 ' Same as LVCFMT_BITMAP_ON_RIGHT
#ENDIF

#IF (%WIN32_WINNT >= &H0501)
%HDF_SORTUP              = &H0400
%HDF_SORTDOWN            = &H0200
#ENDIF

#IF %WIN32_WINNT >= &H0600
%HDF_CHECKBOX            = &H0040
%HDF_CHECKED             = &H0080
%HDF_FIXEDWIDTH          = &H0100 ' Can't resize the column; same as LVCFMT_FIXED_WIDTH
%HDF_SPLITBUTTON      = &H1000000 ' Column is a split button; same as LVCFMT_SPLITBUTTON
#ENDIF

#IF %WIN32_WINNT >= &H0600
%HDIS_FOCUSED            = &H00000001
#ENDIF

%HDM_GETITEMCOUNT        = (%HDM_FIRST + 0)
FUNCTION Header_GetItemCount (BYVAL hWndHD AS DWORD) AS LONG
    FUNCTION = SendMessage(hWndHD, %HDM_GETITEMCOUNT, 0, 0)
END FUNCTION

%HDM_INSERTITEMA         = (%HDM_FIRST + 1)
%HDM_INSERTITEMW         = (%HDM_FIRST + 10)

#IF %DEF(%UNICODE)
%HDM_INSERTITEM = %HDM_INSERTITEMW
#ELSE
%HDM_INSERTITEM = %HDM_INSERTITEMA
#ENDIF

FUNCTION Header_InsertItem (BYVAL hWndHD AS DWORD, BYVAL i AS DWORD, _
    BYVAL phdi AS DWORD) AS LONG
    FUNCTION = SendMessage(hWndHD, %HDM_INSERTITEM, i, phdi)
END FUNCTION

%HDM_DELETEITEM         = (%HDM_FIRST + 2)

FUNCTION Header_DeleteItem (BYVAL hWndHD AS DWORD, BYVAL i AS DWORD) AS LONG
    FUNCTION = SendMessage(hWndHD, %HDM_DELETEITEM, i, 0)
END FUNCTION

%HDM_GETITEMA            = (%HDM_FIRST + 3)
%HDM_GETITEMW            = (%HDM_FIRST + 11)

#IF %DEF(%UNICODE)
%HDM_GETITEM = %HDM_GETITEMW
#ELSE
%HDM_GETITEM = %HDM_GETITEMA
#ENDIF

FUNCTION Header_GetItem (BYVAL hWndHD AS DWORD, BYVAL i AS DWORD, _
    phdi AS HD_ITEM) AS LONG
    FUNCTION = SendMessage(hWndHD, %HDM_GETITEM, i, VARPTR(phdi))
END FUNCTION

%HDM_SETITEMA            = (%HDM_FIRST + 4)
%HDM_SETITEMW            = (%HDM_FIRST + 12)

#IF %DEF(%UNICODE)
%HDM_SETITEM = %HDM_SETITEMW
#ELSE
%HDM_SETITEM = %HDM_SETITEMA
#ENDIF

FUNCTION Header_SetItem (BYVAL hWndHD AS DWORD, BYVAL i AS DWORD, _
    phdi AS HD_ITEM) AS LONG
    FUNCTION = SendMessage(hWndHD, %HDM_SETITEM, i, VARPTR(phdi))
END FUNCTION

TYPE HDLAYOUT
    prc   AS RECT PTR
    pwpos AS WINDOWPOS PTR
END TYPE

#IF (%WIN32_IE >= &H0300)
TYPE HD_LAYOUT
    HDLAYOUT
END TYPE
#ELSE
TYPE HDLAYOUT
    HD_LAYOUT
END TYPE
#ENDIF

%HDM_LAYOUT              = (%HDM_FIRST + 5)
FUNCTION Header_Layout (BYVAL hWndHD AS DWORD, playout AS HD_LAYOUT) AS LONG
    FUNCTION = SendMessage(hWndHD, %HDM_LAYOUT, 0, VARPTR(playout))
END FUNCTION

%HHT_NOWHERE         = &H0001
%HHT_ONHEADER        = &H0002
%HHT_ONDIVIDER       = &H0004
%HHT_ONDIVOPEN       = &H0008
#IF (%WIN32_IE >= &H0500)
%HHT_ONFILTER        = &H0010
%HHT_ONFILTERBUTTON  = &H0020
#ENDIF
%HHT_ABOVE           = &H0100
%HHT_BELOW           = &H0200
%HHT_TORIGHT         = &H0400
%HHT_TOLEFT          = &H0800
#IF %WIN32_WINNT >= &H0600
%HHT_ONITEMSTATEICON = &H1000
%HHT_ONDROPDOWN      = &H2000
%HHT_ONOVERFLOW      = &H4000
#ENDIF

TYPE HDHITTESTINFO
    pt    AS POINT
    flags AS DWORD
    iItem AS LONG
END TYPE

#IF (%WIN32_IE >= &H0300)
TYPE HD_HITTESTINFO
    HDHITTESTINFO
END TYPE
#ELSE
TYPE HDHITTESTINFO
    HD_HITTESTINFO
END TYPE
#ENDIF

%HDSIL_NORMAL        = 0
%HDSIL_STATE         = 1

%HDM_HITTEST             = (%HDM_FIRST + 6)

#IF (%WIN32_IE >= &H0300)

%HDM_GETITEMRECT         = (%HDM_FIRST + 7)
FUNCTION Header_GetItemRect (BYVAL hwnd AS DWORD, BYVAL iItem AS LONG, _
    BYVAL lprc AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %HDM_GETITEMRECT, iItem, lprc)
END FUNCTION

%HDM_SETIMAGELIST        = (%HDM_FIRST + 8)
FUNCTION Header_SetImageList (BYVAL hwnd AS DWORD, BYVAL himl AS DWORD) _
    AS DWORD
    FUNCTION = SendMessage(hwnd, %HDM_SETIMAGELIST, 0, himl)
END FUNCTION

FUNCTION Header_SetStateImageList (BYVAL hwnd AS DWORD, BYVAL himl AS DWORD) _
    AS DWORD
    FUNCTION = SendMessage(hwnd, %HDM_SETIMAGELIST, %HDSIL_STATE, himl)
END FUNCTION

%HDM_GETIMAGELIST        = (%HDM_FIRST + 9)
FUNCTION Header_GetImageList (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %HDM_GETIMAGELIST, 0, 0)
END FUNCTION

FUNCTION Header_GetStateImageList (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %HDM_GETIMAGELIST, %HDSIL_STATE, 0)
END FUNCTION

%HDM_ORDERTOINDEX        = (%HDM_FIRST + 15)
FUNCTION Header_OrderToIndex (BYVAL hwnd AS DWORD, BYVAL i AS LONG) AS DWORD
    FUNCTION = SendMessage(hwnd, %HDM_ORDERTOINDEX, i, 0)
END FUNCTION

%HDM_CREATEDRAGIMAGE     = (%HDM_FIRST + 16)  ' wparam = which item(by index)
FUNCTION Header_CreateDragImage (BYVAL hwnd AS DWORD, BYVAL i AS DWORD) _
    AS DWORD
    FUNCTION = SendMessage(hwnd, %HDM_CREATEDRAGIMAGE, i, 0)
END FUNCTION

%HDM_GETORDERARRAY       = (%HDM_FIRST + 17)
FUNCTION Header_GetOrderArray (BYVAL hwnd AS DWORD, BYVAL iCount AS DWORD, _
    BYVAL lpi AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %HDM_GETORDERARRAY, iCount, lpi)
END FUNCTION

%HDM_SETORDERARRAY       = (%HDM_FIRST + 18)
FUNCTION Header_SetOrderArray (BYVAL hwnd AS DWORD, BYVAL iCount AS DWORD, _
    BYVAL lpi AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %HDM_SETORDERARRAY, iCount, lpi)
END FUNCTION
' lparam = int array of size %HDM_GETITEMCOUNT
' the array specifies the order that all items should be displayed.
' e.g.  { 2, 0, 1}
' says the index 2 item should be shown in the 0ths position
'      index 0 should be shown in the 1st position
'      index 1 should be shown in the 2nd position

%HDM_SETHOTDIVIDER       = (%HDM_FIRST + 19)
FUNCTION Header_SetHotDivider (BYVAL hwnd AS DWORD, BYVAL fPos AS DWORD, _
    BYVAL dwd AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %HDM_SETHOTDIVIDER, fPos, dwd)
END FUNCTION
' convenience message for external dragdrop
' wParam = BOOL  specifying whether the lParam is a dwPos of the cursor
'              position or the index of which divider to hotlight
' lParam = depends on wParam (-1 and wParm = %FALSE turns off hotlight)
#ENDIF      ' %WIN32_IE >= &H0300

#IF (%WIN32_IE >= &H0500)

%HDM_SETBITMAPMARGIN     = (%HDM_FIRST + 20)
FUNCTION Header_SetBitmapMargin (BYVAL hwnd AS DWORD, BYVAL iWidth AS DWORD) _
    AS LONG
    FUNCTION = SendMessage(hwnd, %HDM_SETBITMAPMARGIN, iWidth, 0)
END FUNCTION

%HDM_GETBITMAPMARGIN     = (%HDM_FIRST + 21)
FUNCTION Header_GetBitmapMargin (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %HDM_GETBITMAPMARGIN, 0, 0)
END FUNCTION
#ENDIF

#IF (%WIN32_IE >= &H0400)
%HDM_SETUNICODEFORMAT    = %CCM_SETUNICODEFORMAT
FUNCTION Header_SetUnicodeFormat (BYVAL hwnd AS DWORD, _
    BYVAL fUnicode AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %HDM_SETUNICODEFORMAT, fUnicode, 0)
END FUNCTION

%HDM_GETUNICODEFORMAT    = %CCM_GETUNICODEFORMAT
FUNCTION Header_GetUnicodeFormat (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %HDM_GETUNICODEFORMAT, 0, 0)
END FUNCTION
#ENDIF

#IF (%WIN32_IE >= &H0500)
%HDM_SETFILTERCHANGETIMEOUT = (%HDM_FIRST + 22)
FUNCTION Header_SetFilterChangeTimeout (BYVAL hwnd AS DWORD, BYVAL i AS LONG) _
    AS LONG
    FUNCTION = SendMessage(hwnd, %HDM_SETFILTERCHANGETIMEOUT, 0, i)
END FUNCTION

%HDM_EDITFILTER             = (%HDM_FIRST + 23)
FUNCTION Header_EditFilter (BYVAL hwnd AS DWORD, BYVAL i AS DWORD, _
    BYVAL fDiscardChanges AS INTEGER) AS LONG
    FUNCTION = SendMessage(hwnd, %HDM_EDITFILTER, i, MAKLNG(fDiscardChanges, 0))
END FUNCTION

' Clear filter takes -1 as a column value to indicate that all
' the filter should be cleared.  When this happens you will
' only receive a single filter changed notification.

%HDM_CLEARFILTER            = (%HDM_FIRST + 24)

FUNCTION Header_ClearFilter (BYVAL hwnd AS DWORD, BYVAL i AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %HDM_CLEARFILTER, i, 0)
END FUNCTION

FUNCTION Header_ClearAllFilters (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %HDM_CLEARFILTER, -1, 0)
END FUNCTION

#ENDIF

'#IF (%WIN32_IE >= &H0600)
' [CCM_TRANSLATEACCELERATOR is never defined]
'%HDM_TRANSLATEACCELERATOR = %CCM_TRANSLATEACCELERATOR
'#ENDIF

#IF (%WIN32_WINNT >= &H600)

%HDM_GETITEMDROPDOWNRECT = (%HDM_FIRST+25)  ' rect of item's drop down button
FUNCTION Header_GetItemDropDownRect (BYVAL hwnd AS DWORD, _
    BYVAL iItem AS LONG, lprc AS RECT) AS LONG
    FUNCTION = SendMessage(hwnd, %HDM_GETITEMDROPDOWNRECT, iItem, VARPTR(lprc))
END FUNCTION

%HDM_GETOVERFLOWRECT = (%HDM_FIRST+26)  ' rect of overflow button
FUNCTION Header_GetOverflowRect (BYVAL hwnd AS DWORD, lprc AS RECT) AS LONG
    FUNCTION = SendMessage(hwnd, %HDM_GETOVERFLOWRECT, 0, VARPTR(lprc))
END FUNCTION

%HDM_GETFOCUSEDITEM = (%HDM_FIRST+27)
FUNCTION Header_GetFocusedItem (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %HDM_GETFOCUSEDITEM, 0, 0)
END FUNCTION

%HDM_SETFOCUSEDITEM = (%HDM_FIRST+28)
FUNCTION Header_SetFocusedItem (BYVAL hwnd AS DWORD, BYVAL iItem AS LONG) _
    AS LONG
    FUNCTION = SendMessage(hwnd, %HDM_SETFOCUSEDITEM, 0, iItem)
END FUNCTION

#ENDIF  ' %WIN32_WINNT >= &H600

%HDN_ITEMCHANGINGA       = (%HDN_FIRST - 0)
%HDN_ITEMCHANGINGW       = (%HDN_FIRST - 20)
%HDN_ITEMCHANGEDA        = (%HDN_FIRST - 1)
%HDN_ITEMCHANGEDW        = (%HDN_FIRST - 21)
%HDN_ITEMCLICKA          = (%HDN_FIRST - 2)
%HDN_ITEMCLICKW          = (%HDN_FIRST - 22)
%HDN_ITEMDBLCLICKA       = (%HDN_FIRST - 3)
%HDN_ITEMDBLCLICKW       = (%HDN_FIRST - 23)
%HDN_DIVIDERDBLCLICKA    = (%HDN_FIRST - 5)
%HDN_DIVIDERDBLCLICKW    = (%HDN_FIRST - 25)
%HDN_BEGINTRACKA         = (%HDN_FIRST - 6)
%HDN_BEGINTRACKW         = (%HDN_FIRST - 26)
%HDN_ENDTRACKA           = (%HDN_FIRST - 7)
%HDN_ENDTRACKW           = (%HDN_FIRST - 27)
%HDN_TRACKA              = (%HDN_FIRST - 8)
%HDN_TRACKW              = (%HDN_FIRST - 28)
#IF (%WIN32_IE >= &H0300)
%HDN_GETDISPINFOA        = (%HDN_FIRST - 9)
%HDN_GETDISPINFOW        = (%HDN_FIRST - 29)
%HDN_BEGINDRAG           = (%HDN_FIRST - 10)
%HDN_ENDDRAG             = (%HDN_FIRST - 11)
#ENDIF
#IF (%WIN32_IE >= &H0500)
%HDN_FILTERCHANGE        = (%HDN_FIRST - 12)
%HDN_FILTERBTNCLICK      = (%HDN_FIRST - 13)
#ENDIF

#IF (%WIN32_IE >= &H0600)
%HDN_BEGINFILTEREDIT   = (%HDN_FIRST-14)
%HDN_ENDFILTEREDIT     = (%HDN_FIRST-15)
#ENDIF

#IF %WIN32_WINNT >= &H0600
%HDN_ITEMSTATEICONCLICK= (%HDN_FIRST-16)
%HDN_ITEMKEYDOWN       = (%HDN_FIRST-17)
%HDN_DROPDOWN          = (%HDN_FIRST-18)
%HDN_OVERFLOWCLICK     = (%HDN_FIRST-19)
#ENDIF

#IF %DEF(%UNICODE)
%HDN_ITEMCHANGING      =  %HDN_ITEMCHANGINGW
%HDN_ITEMCHANGED       =  %HDN_ITEMCHANGEDW
%HDN_ITEMCLICK         =  %HDN_ITEMCLICKW
%HDN_ITEMDBLCLICK      =  %HDN_ITEMDBLCLICKW
%HDN_DIVIDERDBLCLICK   =  %HDN_DIVIDERDBLCLICKW
%HDN_BEGINTRACK        =  %HDN_BEGINTRACKW
%HDN_ENDTRACK          =  %HDN_ENDTRACKW
%HDN_TRACK             =  %HDN_TRACKW
#IF (%WIN32_IE >= &H0300)
%HDN_GETDISPINFO       =  %HDN_GETDISPINFOW
#ENDIF
#ELSE
%HDN_ITEMCHANGING      =  %HDN_ITEMCHANGINGA
%HDN_ITEMCHANGED       =  %HDN_ITEMCHANGEDA
%HDN_ITEMCLICK         =  %HDN_ITEMCLICKA
%HDN_ITEMDBLCLICK      =  %HDN_ITEMDBLCLICKA
%HDN_DIVIDERDBLCLICK   =  %HDN_DIVIDERDBLCLICKA
%HDN_BEGINTRACK        =  %HDN_BEGINTRACKA
%HDN_ENDTRACK          =  %HDN_ENDTRACKA
%HDN_TRACK             =  %HDN_TRACKA
#IF (%WIN32_IE >= &H0300)
%HDN_GETDISPINFO       =  %HDN_GETDISPINFOA
#ENDIF
#ENDIF


TYPE NMHEADERA
    hdr     AS NMHDR
    iItem   AS LONG
    iButton AS LONG
    pitem   AS HDITEMA PTR
END TYPE

TYPE NMHEADERW
    hdr     AS NMHDR
    iItem   AS LONG
    iButton AS LONG
    pitem   AS HDITEMW PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE NMHEADER
    NMHEADERW
END TYPE
#ELSE
TYPE NMHEADER
    NMHEADERA
END TYPE
#ENDIF

#IF (%WIN32_IE >= &H0300)
TYPE HD_NOTIFYA
    NMHEADERA
END TYPE
TYPE HD_NOTIFYW
    NMHEADERW
END TYPE
#ELSE
TYPE NMHEADERA
    HD_NOTIFYA
END TYPE
TYPE NMHEADERW
    HD_NOTIFYW
END TYPE
#ENDIF
TYPE HD_NOTIFY
    NMHEADER
END TYPE

TYPE NMHDDISPINFOW
    hdr        AS NMHDR
    iItem      AS LONG
    mask       AS DWORD
    pszText    AS WSTRINGZ PTR
    cchTextMax AS LONG
    iImage     AS LONG
    lParam     AS LONG
END TYPE

TYPE NMHDDISPINFOA
    hdr        AS NMHDR
    iItem      AS LONG
    mask       AS DWORD
    pszText    AS ASCIIZ PTR
    cchTextMax AS LONG
    iImage     AS LONG
    lParam     AS LONG
END TYPE

#IF %DEF(%UNICODE)
TYPE NMHDDISPINFO
    NMHDDISPINFOW
END TYPE
#ELSE
TYPE NMHDDISPINFO
    NMHDDISPINFOA
END TYPE
#ENDIF

#IF (%WIN32_IE >= &H0500)
TYPE NMHDFILTERBTNCLICK
    hdr   AS NMHDR
    iItem AS LONG
    rc    AS RECT
END TYPE
#ENDIF

#ENDIF  ' %NOHEADER


'==============================================================================
' TOOLBAR CONTROL

#IF NOT %DEF(%NOTOOLBAR)

#IF %DEF(%WIN32)
$$TOOLBARCLASSNAMEW   = "ToolbarWindow32"$$
$TOOLBARCLASSNAMEA    = "ToolbarWindow32"

#IF %DEF(%UNICODE)
MACRO TOOLBARCLASSNAME=$$TOOLBARCLASSNAMEW
#ELSE
MACRO TOOLBARCLASSNAME=$TOOLBARCLASSNAMEA
#ENDIF

#ELSE
MACRO TOOLBARCLASSNAME="ToolbarWindow"
#ENDIF  ' #IF %DEF(%WIN32)

TYPE TBBUTTON
    iBitmap   AS LONG
    idCommand AS LONG
    fsState   AS BYTE
    fsStyle   AS BYTE
#IF %DEF(%WIN64)
    bReserved(5) AS BYTE   ' padding for alignment
#ELSEIF %DEF(%WIN32)
    bReserved(1) AS BYTE   ' padding for alignment
#ENDIF
    dwData    AS DWORD
    iString   AS DWORD
END TYPE

TYPE COLORMAP
    nfrom AS DWORD
    nto   AS DWORD
END TYPE

DECLARE FUNCTION CreateToolbarEx LIB "ComCtl32.dll" ALIAS "CreateToolbarEx" _
   (BYVAL hWnd AS DWORD, BYVAL ws AS DWORD, BYVAL wID AS WORD, _
    BYVAL nBitmaps AS LONG, BYVAL hBMInst AS DWORD, BYVAL wBMID AS DWORD, _
    lpButtons AS TBBUTTON, BYVAL iNumButtons AS LONG, BYVAL dxButton AS LONG, _
    BYVAL dyButton AS LONG, BYVAL dxBitmap AS LONG, BYVAL dyBitmap AS LONG, _
    BYVAL uStructSize AS DWORD) AS DWORD

DECLARE FUNCTION CreateMappedBitmap LIB "ComCtl32.dll" _
    ALIAS "CreateMappedBitmap" (BYVAL hInstance AS DWORD, _
    BYVAL idBitmap AS LONG, BYVAL wFlags AS DWORD, lpColorMap AS COLORMAP, _
    BYVAL iNumMaps AS LONG) AS DWORD

%CMB_MASKED             = &H02
%TBSTATE_CHECKED        = &H0001
%TBSTATE_PRESSED        = &H0002
%TBSTATE_ENABLED        = &H0004
%TBSTATE_HIDDEN         = &H0008
%TBSTATE_INDETERMINATE  = &H0010
%TBSTATE_WRAP           = &H0020
#IF (%WIN32_IE >= &H0300)
%TBSTATE_ELLIPSES       = &H0040
#ENDIF
#IF (%WIN32_IE >= &H0400)
%TBSTATE_MARKED         = &H0080
#ENDIF

%TBSTYLE_BUTTON         = &H0000  ' obsolete; use BTNS_BUTTON instead
%TBSTYLE_SEP            = &H0001  ' obsolete; use BTNS_SEP instead
%TBSTYLE_CHECK          = &H0002  ' obsolete; use BTNS_CHECK instead
%TBSTYLE_GROUP          = &H0004  ' obsolete; use BTNS_GROUP instead
%TBSTYLE_CHECKGROUP     = (%TBSTYLE_GROUP OR %TBSTYLE_CHECK)  ' obsolete; use BTNS_CHECKGROUP instead
#IF (%WIN32_IE >= &H0300)
%TBSTYLE_DROPDOWN       = &H0008  ' obsolete; use BTNS_DROPDOWN instead
#ENDIF
#IF (%WIN32_IE >= &H0400)
%TBSTYLE_AUTOSIZE       = &H0010  ' obsolete; use BTNS_AUTOSIZE instead
%TBSTYLE_NOPREFIX       = &H0020  ' obsolete; use BTNS_NOPREFIX instead
#ENDIF

%TBSTYLE_TOOLTIPS        = &H00000100
%TBSTYLE_WRAPABLE        = &H00000200
%TBSTYLE_ALTDRAG         = &H00000400
#IF (%WIN32_IE >= &H0300)
%TBSTYLE_FLAT            = &H00000800
%TBSTYLE_LIST            = &H00001000
%TBSTYLE_CUSTOMERASE     = &H00002000
#ENDIF
#IF (%WIN32_IE >= &H0400)
%TBSTYLE_REGISTERDROP    = &H00004000
%TBSTYLE_TRANSPARENT     = &H00008000

%TBSTYLE_EX_DRAWDDARROWS = &H00000001
#ENDIF

#IF (%WIN32_IE >= &H0500)
%BTNS_BUTTON     = %TBSTYLE_BUTTON      ' &H0000
%BTNS_SEP        = %TBSTYLE_SEP         ' &H0001
%BTNS_CHECK      = %TBSTYLE_CHECK       ' &H0002
%BTNS_GROUP      = %TBSTYLE_GROUP       ' &H0004
%BTNS_CHECKGROUP = %TBSTYLE_CHECKGROUP  '(%TBSTYLE_GROUP OR %TBSTYLE_CHECK)
%BTNS_DROPDOWN   = %TBSTYLE_DROPDOWN    ' &H0008
%BTNS_AUTOSIZE   = %TBSTYLE_AUTOSIZE    ' &H0010; automatically calculate the cx of the button
%BTNS_NOPREFIX   = %TBSTYLE_NOPREFIX    ' &H0020; this button should not have accel prefix
#IF (%WIN32_IE >= &H0501)
%BTNS_SHOWTEXT   = &H0040              ' ignored unless %TBSTYLE_EX_MIXEDBUTTONS is set
#ENDIF
%BTNS_WHOLEDROPDOWN  = &H0080          ' draw drop-down arrow, but without split arrow section
#ENDIF

#IF (%WIN32_IE >= &H0501)
%TBSTYLE_EX_MIXEDBUTTONS       = &H00000008
%TBSTYLE_EX_HIDECLIPPEDBUTTONS = &H00000010 ' don't show partially obscured buttons
#ENDIF

#IF (%WIN32_WINNT >= &H0501)
%TBSTYLE_EX_DOUBLEBUFFER       = &H00000080 ' Double Buffer the toolbar
#ENDIF

#IF (%WIN32_IE >= &H0400)
' Custom Draw Structure
TYPE NMTBCUSTOMDRAW
    nmcd                 AS NMCUSTOMDRAW
    hbrMonoDither        AS DWORD
    hbrLines             AS DWORD  ' For drawing lines on buttons
    hpenLines            AS DWORD  ' For drawing lines on buttons
    clrText              AS DWORD  ' Color of text
    clrMark              AS DWORD  ' Color of text bk when marked(only if TBSTATE_MARKED)
    clrTextHighlight     AS DWORD  ' Color of text when highlighted
    clrBtnFace           AS DWORD  ' Background of the button
    clrBtnHighlight      AS DWORD  ' 3D highlight
    clrHighlightHotTrack AS DWORD  ' In conjunction with fHighlightHotTrack,
    rcText               AS RECT   ' will cause button to highlight like a menu
    nStringBkMode        AS LONG   ' Rect for text
    nHLStringBkMode      AS LONG
#IF (%WIN32_WINNT >= &H0501)
    iListGap             AS LONG
#ENDIF
END TYPE

' Toolbar custom draw return flags
%TBCDRF_NOEDGES        = &H00010000 ' Don't draw button edges
%TBCDRF_HILITEHOTTRACK = &H00020000 ' Use color of the button bk when hottracked
%TBCDRF_NOOFFSET       = &H00040000 ' Don't offset button if pressed
%TBCDRF_NOMARK         = &H00080000 ' Don't draw default highlight of image/text for TBSTATE_MARKED
%TBCDRF_NOETCHEDEFFECT = &H00100000 ' Don't draw etched effect for disabled items
#ENDIF

#IF (%WIN32_IE >= &H0500)
%TBCDRF_BLENDICON      = &H00200000  ' Use ILD_BLEND50 on the icon image
%TBCDRF_NOBACKGROUND   = &H00400000  ' Use ILD_BLEND50 on the icon image
#ENDIF
#IF %WIN32_WINNT >= &H0600
%TBCDRF_USECDCOLORS    = &H00800000  ' Use CustomDrawColors to RenderText regardless of VisualStyle
#ENDIF

%TB_ENABLEBUTTON             = %WM_USER + 1
%TB_CHECKBUTTON              = %WM_USER + 2
%TB_PRESSBUTTON              = %WM_USER + 3
%TB_HIDEBUTTON               = %WM_USER + 4
%TB_INDETERMINATE            = %WM_USER + 5
#IF (%WIN32_IE >= &H0400)
%TB_MARKBUTTON               = %WM_USER + 6
#ENDIF
%TB_ISBUTTONENABLED          = %WM_USER + 9
%TB_ISBUTTONCHECKED          = %WM_USER + 10
%TB_ISBUTTONPRESSED          = %WM_USER + 11
%TB_ISBUTTONHIDDEN           = %WM_USER + 12
%TB_ISBUTTONINDETERMINATE    = %WM_USER + 13
#IF (%WIN32_IE >= &H0400)
%TB_ISBUTTONHIGHLIGHTED      = %WM_USER + 14
#ENDIF
%TB_SETSTATE                 = %WM_USER + 17
%TB_GETSTATE                 = %WM_USER + 18
%TB_ADDBITMAP                = %WM_USER + 19

#IF %DEF(%WIN32)
TYPE TBADDBITMAP
    hInst AS DWORD
    nID   AS DWORD
END TYPE

%HINST_COMMCTRL          = &HFFFFFFFF??? '((HINSTANCE)-1)
%IDB_STD_SMALL_COLOR     = 0
%IDB_STD_LARGE_COLOR     = 1
%IDB_VIEW_SMALL_COLOR    = 4
%IDB_VIEW_LARGE_COLOR    = 5
#IF (%WIN32_IE >= &H0300)
%IDB_HIST_SMALL_COLOR    = 8
%IDB_HIST_LARGE_COLOR    = 9
#ENDIF
#IF (%WIN32_WINNT >= &H600)
%IDB_HIST_NORMAL         = 12
%IDB_HIST_HOT            = 13
%IDB_HIST_DISABLED       = 14
%IDB_HIST_PRESSED        = 15
#ENDIF  ' %WIN32_WINNT >= &H600

' icon indexes for standard bitmap

%STD_CUT         = 0
%STD_COPY        = 1
%STD_PASTE       = 2
%STD_UNDO        = 3
%STD_REDOW       = 4
%STD_DELETE      = 5
%STD_FILENEW     = 6
%STD_FILEOPEN    = 7
%STD_FILESAVE    = 8
%STD_PRINTPRE    = 9
%STD_PROPERTIES  = 10
%STD_HELP        = 11
%STD_FIND        = 12
%STD_REPLACE     = 13
%STD_PRINT       = 14

' icon indexes for standard view bitmap

%VIEW_LARGEICONS     = 0
%VIEW_SMALLICONS     = 1
%VIEW_LIST           = 2
%VIEW_DETAILS        = 3
%VIEW_SORTNAME       = 4
%VIEW_SORTSIZE       = 5
%VIEW_SORTDATE       = 6
%VIEW_SORTTYPE       = 7
%VIEW_PARENTFOLDER   = 8
%VIEW_NETCONNECT     = 9
%VIEW_NETDISCONNECT  = 10
%VIEW_NEWFOLDER      = 11
#IF (%WIN32_IE >= &H0400)
%VIEW_VIEWMENU       = 12
#ENDIF

#IF (%WIN32_IE >= &H0300)
%HIST_BACK           = 0
%HIST_FORWARD        = 1
%HIST_FAVORITES      = 2
%HIST_ADDTOFAVORITES = 3
%HIST_VIEWTREE       = 4
#ENDIF

#ENDIF  ' #IF %DEF(%WIN32)

#IF (%WIN32_IE >= &H0400)
%TB_ADDBUTTONSA      = %WM_USER + 20
%TB_INSERTBUTTONA    = %WM_USER + 21
#ELSE
%TB_ADDBUTTONS       = %WM_USER + 20
%TB_INSERTBUTTON     = %WM_USER + 21
#ENDIF

%TB_DELETEBUTTON     = %WM_USER + 22
%TB_GETBUTTON        = %WM_USER + 23
%TB_BUTTONCOUNT      = %WM_USER + 24
%TB_COMMANDTOINDEX   = %WM_USER + 25

#IF %DEF(%WIN32)

TYPE TBSAVEPARAMSA
    hkr          AS DWORD
    pszSubKey    AS ASCIIZ PTR
    pszValueName AS ASCIIZ PTR
END TYPE

TYPE TBSAVEPARAMSW
    hkr          AS DWORD
    pszSubKey    AS WSTRINGZ PTR
    pszValueName AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE TBSAVEPARAMS
    TBSAVEPARAMSW
END TYPE
#ELSE
TYPE TBSAVEPARAMS
    TBSAVEPARAMSA
END TYPE
#ENDIF

#ENDIF  ' %WIN32

%TB_SAVERESTOREA          = %WM_USER + 26
%TB_SAVERESTOREW          = %WM_USER + 76
%TB_CUSTOMIZE             = %WM_USER + 27
%TB_ADDSTRINGA            = %WM_USER + 28
%TB_ADDSTRINGW            = %WM_USER + 77
%TB_GETITEMRECT           = %WM_USER + 29
%TB_BUTTONSTRUCTSIZE      = %WM_USER + 30
%TB_SETBUTTONSIZE         = %WM_USER + 31
%TB_SETBITMAPSIZE         = %WM_USER + 32
%TB_AUTOSIZE              = %WM_USER + 33
%TB_GETTOOLTIPS           = %WM_USER + 35
%TB_SETTOOLTIPS           = %WM_USER + 36
%TB_SETPARENT             = %WM_USER + 37
%TB_SETROWS               = %WM_USER + 39
%TB_GETROWS               = %WM_USER + 40
%TB_SETCMDID              = %WM_USER + 42
%TB_CHANGEBITMAP          = %WM_USER + 43
%TB_GETBITMAP             = %WM_USER + 44
%TB_GETBUTTONTEXTA        = %WM_USER + 45
%TB_GETBUTTONTEXTW        = %WM_USER + 75
%TB_REPLACEBITMAP         = %WM_USER + 46
#IF (%WIN32_IE >= &H0300)
%TB_SETINDENT             = %WM_USER + 47
%TB_SETIMAGELIST          = %WM_USER + 48
%TB_GETIMAGELIST          = %WM_USER + 49
%TB_LOADIMAGES            = %WM_USER + 50
%TB_GETRECT               = %WM_USER + 51  ' wParam is the Cmd instead of index
%TB_SETHOTIMAGELIST       = %WM_USER + 52
%TB_GETHOTIMAGELIST       = %WM_USER + 53
%TB_SETDISABLEDIMAGELIST  = %WM_USER + 54
%TB_GETDISABLEDIMAGELIST  = %WM_USER + 55
%TB_SETSTYLE              = %WM_USER + 56
%TB_GETSTYLE              = %WM_USER + 57
%TB_GETBUTTONSIZE         = %WM_USER + 58
%TB_SETBUTTONWIDTH        = %WM_USER + 59
%TB_SETMAXTEXTROWS        = %WM_USER + 60
%TB_GETTEXTROWS           = %WM_USER + 61
#ENDIF  ' %WIN32_IE >= &H0300

#IF %DEF(%UNICODE)
%TB_GETBUTTONTEXT = %TB_GETBUTTONTEXTW
%TB_SAVERESTORE   = %TB_SAVERESTOREW
%TB_ADDSTRING     = %TB_ADDSTRINGW
#ELSE
%TB_GETBUTTONTEXT = %TB_GETBUTTONTEXTA
%TB_SAVERESTORE   = %TB_SAVERESTOREA
%TB_ADDSTRING     = %TB_ADDSTRINGA
#ENDIF
#IF (%WIN32_IE >= &H0400)
%TB_GETOBJECT             = %WM_USER + 62  ' wParam == IID, lParam void **ppv
%TB_GETHOTITEM            = %WM_USER + 71
%TB_SETHOTITEM            = %WM_USER + 72  ' wParam == iHotItem
%TB_SETANCHORHIGHLIGHT    = %WM_USER + 73  ' wParam == TRUE/FALSE
%TB_GETANCHORHIGHLIGHT    = %WM_USER + 74
%TB_MAPACCELERATORA       = %WM_USER + 78  ' wParam == ch, lParam int * pidBtn

TYPE TBINSERTMARK
    iButton AS LONG
    dwFlags AS DWORD
END TYPE

%TBIMHT_AFTER      = &H00000001 ' TRUE = insert After iButton, otherwise before
%TBIMHT_BACKGROUND = &H00000002 ' TRUE iff missed buttons completely

%TB_GETINSERTMARK        = %WM_USER + 79  ' lParam == LPTBINSERTMARK
%TB_SETINSERTMARK        = %WM_USER + 80  ' lParam == LPTBINSERTMARK
%TB_INSERTMARKHITTEST    = %WM_USER + 81  ' wParam == LPPOINT lParam == LPTBINSERTMARK
%TB_MOVEBUTTON           = %WM_USER + 82
%TB_GETMAXSIZE           = %WM_USER + 83  ' lParam == LPSIZE
%TB_SETEXTENDEDSTYLE     = %WM_USER + 84  ' For TBSTYLE_EX_*
%TB_GETEXTENDEDSTYLE     = %WM_USER + 85  ' For TBSTYLE_EX_*
%TB_GETPADDING           = %WM_USER + 86
%TB_SETPADDING           = %WM_USER + 87
%TB_SETINSERTMARKCOLOR   = %WM_USER + 88
%TB_GETINSERTMARKCOLOR   = %WM_USER + 89

%TB_SETCOLORSCHEME       = %CCM_SETCOLORSCHEME  ' lParam is color scheme
%TB_GETCOLORSCHEME       = %CCM_GETCOLORSCHEME  ' fills in COLORSCHEME pointed to by lParam

%TB_SETUNICODEFORMAT     = %CCM_SETUNICODEFORMAT
%TB_GETUNICODEFORMAT     = %CCM_GETUNICODEFORMAT

%TB_MAPACCELERATORW      = %WM_USER + 90  ' wParam == ch, lParam int * pidBtn
#IF %DEF(%UNICODE)
%TB_MAPACCELERATOR  = %TB_MAPACCELERATORW
#ELSE
%TB_MAPACCELERATOR  = %TB_MAPACCELERATORA
#ENDIF

#ENDIF  ' %WIN32_IE >= &H0400

TYPE TBREPLACEBITMAP
    hInstOld AS DWORD
    nIDOld   AS DWORD
    hInstNew AS DWORD
    nIDNew   AS DWORD
    nButtons AS LONG
END TYPE

#IF %DEF(%WIN32)

%TBBF_LARGE              = &H0001

%TB_GETBITMAPFLAGS       = (%WM_USER + 41)

#IF (%WIN32_IE >= &H0400)
%TBIF_IMAGE   = &H00000001
%TBIF_TEXT    = &H00000002
%TBIF_STATE   = &H00000004
%TBIF_STYLE   = &H00000008
%TBIF_LPARAM  = &H00000010
%TBIF_COMMAND = &H00000020
%TBIF_SIZE    = &H00000040

#IF (%WIN32_IE >= &H0500)
%TBIF_BYINDEX = &H80000000??? ' this specifies that the wparam in Get/SetButtonInfo is an index, not id
#ENDIF

TYPE TBBUTTONINFOA
    cbSize    AS DWORD
    dwMask    AS DWORD
    idCommand AS LONG
    iImage    AS LONG
    fsState   AS BYTE
    fsStyle   AS BYTE
    cx        AS WORD
    lParam    AS DWORD
    pszText   AS ASCIIZ PTR
    cchText   AS LONG
END TYPE

TYPE TBBUTTONINFOW
    cbSize    AS DWORD
    dwMask    AS DWORD
    idCommand AS LONG
    iImage    AS LONG
    fsState   AS BYTE
    fsStyle   AS BYTE
    cx        AS WORD
    lParam    AS DWORD
    pszText   AS WSTRINGZ PTR
    cchText   AS LONG
END TYPE

#IF %DEF(%UNICODE)
TYPE TBBUTTONINFO
    TBBUTTONINFOW
END TYPE
#ELSE
TYPE TBBUTTONINFO
    TBBUTTONINFOA
END TYPE
#ENDIF

' BUTTONINFO APIs do NOT support the string pool.
%TB_GETBUTTONINFOW       = %WM_USER + 63
%TB_SETBUTTONINFOW       = %WM_USER + 64
%TB_GETBUTTONINFOA       = %WM_USER + 65
%TB_SETBUTTONINFOA       = %WM_USER + 66
#IF %DEF(%UNICODE)
%TB_GETBUTTONINFO        = %TB_GETBUTTONINFOW
%TB_SETBUTTONINFO        = %TB_SETBUTTONINFOW
#ELSE
%TB_GETBUTTONINFO        = %TB_GETBUTTONINFOA
%TB_SETBUTTONINFO        = %TB_SETBUTTONINFOA
#ENDIF

%TB_INSERTBUTTONW        = %WM_USER + 67
%TB_ADDBUTTONSW          = %WM_USER + 68

%TB_HITTEST              = %WM_USER + 69

' New post Win95/NT4 for InsertButton and AddButton.  if iString member
' is a pointer to a string, it will be handled as a string like listview
'(although LPSTR_TEXTCALLBACK is not supported).
#IF %DEF(%UNICODE)
%TB_INSERTBUTTON         = %TB_INSERTBUTTONW
%TB_ADDBUTTONS           = %TB_ADDBUTTONSW
#ELSE
%TB_INSERTBUTTON         = %TB_INSERTBUTTONA
%TB_ADDBUTTONS           = %TB_ADDBUTTONSA
#ENDIF

%TB_SETDRAWTEXTFLAGS     = %WM_USER + 70  ' wParam == mask lParam == bit values

#ENDIF  ' %WIN32_IE >= &H0400

#IF (%WIN32_IE >= &H0500)

%TB_GETSTRINGW           = %WM_USER + 91
%TB_GETSTRINGA           = %WM_USER + 92
#IF %DEF(%UNICODE)
%TB_GETSTRING            = %TB_GETSTRINGW
#ELSE
%TB_GETSTRING            = %TB_GETSTRINGA
#ENDIF

%TB_SETHOTITEM2          = (%WM_USER + 94)  ' wParam = iHotItem, lParam = dwFlags
%TB_SETLISTGAP           = (%WM_USER + 96)
%TB_GETIMAGELISTCOUNT    = (%WM_USER + 98)
%TB_GETIDEALSIZE         = (%WM_USER + 99)  ' wParam = fHeight, lParam = psize
' before using %WM_USER + 103, recycle old space above(%WM_USER + 97)
' [CCM_TRANSLATEACCELERATOR is never defined]
'%TB_TRANSLATEACCELERATOR = %CCM_TRANSLATEACCELERATOR

#ENDIF  ' %WIN32_IE >= &H0500


#IF (%WIN32_WINNT >= &H0501)
%TBMF_PAD                = &H00000001
%TBMF_BARPAD             = &H00000002
%TBMF_BUTTONSPACING      = &H00000004

TYPE TBMETRICS
    cbSize          AS DWORD
    dwMask          AS DWORD
    cxPad           AS LONG   ' PAD
    cyPad           AS LONG
    cxBarPad        AS LONG   ' BARPAD
    cyBarPad        AS LONG
    cxButtonSpacing AS LONG   ' BUTTONSPACING
    cyButtonSpacing AS LONG
END TYPE

%TB_GETMETRICS           = %WM_USER + 101
%TB_SETMETRICS           = %WM_USER + 102
#ENDIF

#IF (%WIN32_WINNT >= &H600)
%TB_GETITEMDROPDOWNRECT  = %WM_USER + 103  ' Rect of item's drop down button
%TB_SETPRESSEDIMAGELIST  = %WM_USER + 104
%TB_GETPRESSEDIMAGELIST  = %WM_USER + 105
#ENDIF  ' %WIN32_WINNT >= &H600

#IF (%WIN32_WINNT >= &H0501)
%TB_SETWINDOWTHEME       = %CCM_SETWINDOWTHEME
#ENDIF

%TBN_GETBUTTONINFOA      = %TBN_FIRST - 0
%TBN_BEGINDRAG           = %TBN_FIRST - 1
%TBN_ENDDRAG             = %TBN_FIRST - 2
%TBN_BEGINADJUST         = %TBN_FIRST - 3
%TBN_ENDADJUST           = %TBN_FIRST - 4
%TBN_RESET               = %TBN_FIRST - 5
%TBN_QUERYINSERT         = %TBN_FIRST - 6
%TBN_QUERYDELETE         = %TBN_FIRST - 7
%TBN_TOOLBARCHANGE       = %TBN_FIRST - 8
%TBN_CUSTHELP            = %TBN_FIRST - 9
#IF (%WIN32_IE >= &H0300)
%TBN_DROPDOWN            = %TBN_FIRST - 10
#ENDIF
#IF (%WIN32_IE >= &H0400)
%TBN_GETOBJECT           = %TBN_FIRST - 12

' Structure for %TBN_HOTITEMCHANGE notification
'
TYPE NMTBHOTITEM
    hdr AS NMHDR
    idOld AS LONG
    idNew AS LONG
    dwFlags AS DWORD    ' %HICF_*
END TYPE

' Hot item change flags
%HICF_OTHER          = &H00000000
%HICF_MOUSE          = &H00000001    ' Triggered by mouse
%HICF_ARROWKEYS      = &H00000002    ' Triggered by arrow keys
%HICF_ACCELERATOR    = &H00000004    ' Triggered by accelerator
%HICF_DUPACCEL       = &H00000008    ' This accelerator is not unique
%HICF_ENTERING       = &H00000010    ' idOld is invalid
%HICF_LEAVING        = &H00000020    ' idNew is invalid
%HICF_RESELECT       = &H00000040    ' hot item reselected
%HICF_LMOUSE         = &H00000080    ' left mouse button selected
%HICF_TOGGLEDROPDOWN = &H00000100    ' Toggle button's dropdown state

%TBN_HOTITEMCHANGE   = %TBN_FIRST - 13
%TBN_DRAGOUT         = %TBN_FIRST - 14 ' this is sent when the user clicks down on a button then drags off the button
%TBN_DELETINGBUTTON  = %TBN_FIRST - 15 ' uses %TBNOTIFY
%TBN_GETDISPINFOA    = %TBN_FIRST - 16 ' This is sent when the toolbar needs some display information
%TBN_GETDISPINFOW    = %TBN_FIRST - 17 ' This is sent when the toolbar needs some display information
%TBN_GETINFOTIPA     = %TBN_FIRST - 18
%TBN_GETINFOTIPW     = %TBN_FIRST - 19
%TBN_GETBUTTONINFOW  = %TBN_FIRST - 20
#IF (%WIN32_IE >= &H0500)
%TBN_RESTORE         = %TBN_FIRST - 21
%TBN_SAVE            = %TBN_FIRST - 22
%TBN_INITCUSTOMIZE   = %TBN_FIRST - 23
%TBNRF_HIDEHELP      = &H00000001
%TBNRF_ENDCUSTOMIZE  = &H00000002
%TBN_WRAPHOTITEM     = %TBN_FIRST - 24
%TBN_DUPACCELERATOR  = %TBN_FIRST - 25
%TBN_WRAPACCELERATOR = %TBN_FIRST - 26
%TBN_DRAGOVER        = %TBN_FIRST - 27
%TBN_MAPACCELERATOR  = %TBN_FIRST - 28

#ENDIF  '(%WIN32_IE >= &H0500)


#IF (%WIN32_IE >= &H0500)

TYPE NMTBSAVE
    hdr      AS NMHDR
    pData    AS DWORD PTR
    pCurrent AS DWORD PTR
    cbData   AS DWORD
    iItem    AS LONG
    cButtons AS LONG
    tButton  AS TBBUTTON
END TYPE

TYPE NMTBRESTORE
    hdr              AS NMHDR
    pData            AS DWORD PTR
    pCurrent         AS DWORD PTR
    cbData           AS DWORD
    iItem            AS LONG
    cButtons         AS LONG
    cbBytesPerRecord AS LONG
    tButton          AS TBBUTTON
END TYPE
#ENDIF  '(%WIN32_IE >= &H0500)

TYPE NMTBGETINFOTIPA
    hdr        AS NMHDR
    pszText    AS ASCIIZ PTR
    cchTextMax AS LONG
    iItem      AS LONG
    lParam     AS LONG
END TYPE

TYPE NMTBGETINFOTIPW
    hdr        AS NMHDR
    pszText    AS ASCIIZ PTR
    cchTextMax AS LONG
    iItem      AS LONG
    lParam     AS LONG
END TYPE

#IF %DEF(%UNICODE)
%TBN_GETINFOTIP   = %TBN_GETINFOTIPW
TYPE NMTBGETINFOTIP
    NMTBGETINFOTIPW
END TYPE
#ELSE
%TBN_GETINFOTIP   = %TBN_GETINFOTIPA
TYPE NMTBGETINFOTIP
    NMTBGETINFOTIPA
END TYPE
#ENDIF

%TBNF_IMAGE       = &H00000001
%TBNF_TEXT        = &H00000002
%TBNF_DI_SETITEM  = &H10000000

TYPE NMTBDISPINFOA
    hdr       AS NMHDR
    dwMask    AS DWORD      ' [in] Specifies the values requested .[out] Client ask the data to be set for future use
    idCommand AS LONG       ' [in] id of button we're requesting info for
    lParam    AS DWORD      ' [in] lParam of button
    iImage    AS LONG       ' [out] image index
    pszText   AS ASCIIZ PTR ' [out] new text for item
    cchText   AS LONG       ' [in] size of buffer pointed to by pszText
END TYPE

TYPE NMTBDISPINFOW
    hdr       AS NMHDR
    dwMask    AS DWORD      ' [in] Specifies the values requested .[out] Client ask the data to be set for future use
    idCommand AS LONG       ' [in] id of button we're requesting info for
    lParam    AS DWORD      ' [in] lParam of button
    iImage    AS LONG       ' [out] image index
    pszText   AS WSTRINGZ PTR ' [out] new text for item
    cchText   AS LONG       ' [in] size of buffer pointed to by pszText
END TYPE

#IF %DEF(%UNICODE)
%TBN_GETDISPINFO      = %TBN_GETDISPINFOW
TYPE NMTBDISPINFO
    NMTBDISPINFOW
END TYPE
#ELSE
%TBN_GETDISPINFO      = %TBN_GETDISPINFOA
TYPE NMTBDISPINFO
    NMTBDISPINFOA
END TYPE
#ENDIF

' Return codes for TBN_DROPDOWN
%TBDDRET_DEFAULT      = 0
%TBDDRET_NODEFAULT    = 1
%TBDDRET_TREATPRESSED = 2       ' Treat as a standard press button

#ENDIF


#IF %DEF(%UNICODE)
%TBN_GETBUTTONINFO    = %TBN_GETBUTTONINFOW
#ELSE
%TBN_GETBUTTONINFO    = %TBN_GETBUTTONINFOA
#ENDIF

#IF (%WIN32_IE >= &H0300)
TYPE NMTOOLBARA
    hdr      AS NMHDR
    iItem    AS LONG
    tbButton AS TBBUTTON
    cchText  AS LONG
    pszText  AS ASCIIZ PTR
#IF (%WIN32_IE >= &H500)
    rcButton AS RECT
#ENDIF
END TYPE
#ENDIF

#IF (%WIN32_IE >= &H0300)
TYPE NMTOOLBARW
    hdr      AS NMHDR
    iItem    AS LONG
    tbButton AS TBBUTTON
    cchText  AS LONG
    pszText  AS WSTRINGZ PTR
#IF (%WIN32_IE >= &H500)
    rcButton AS RECT
#ENDIF
END TYPE
#ENDIF

#IF %DEF(%UNICODE)
TYPE NMTOOLBAR
    NMTOOLBARW
END TYPE
#ELSE
TYPE NMTOOLBAR
    NMTOOLBARA
END TYPE
#ENDIF

#IF (%WIN32_IE >= &H0300)
TYPE TBNOTIFYA
    NMTOOLBARA
END TYPE
TYPE TBNOTIFYW
    NMTOOLBARW
END TYPE
#ELSE
TYPE NMTOOLBARA
    TBNOTIFYA
END TYPE
TYPE NMTOOLBARW
    TBNOTIFYW
END TYPE
#ENDIF

TYPE TBNOTIFY
    NMTOOLBAR
END TYPE

#ENDIF

#ENDIF      ' NOTOOLBAR


#IF (%WIN32_IE >= &H0300)
'====== REBAR CONTROL ========================================================

#IF NOT %DEF(%NOREBAR)

#IF %DEF(%WIN32)
$$REBARCLASSNAMEW    = "ReBarWindow32"$$
$REBARCLASSNAMEA     = "ReBarWindow32"

#IF %DEF(%UNICODE)
MACRO REBARCLASSNAME=$$REBARCLASSNAMEW
#ELSE
MACRO REBARCLASSNAME=$REBARCLASSNAMEA
#ENDIF

#ELSE
MACRO REBARCLASSNAME="ReBarWindow"
#ENDIF

%RBIM_IMAGELIST  = &H00000001

%RBS_TOOLTIPS        = &H00000100
%RBS_VARHEIGHT       = &H00000200
%RBS_BANDBORDERS     = &H00000400
%RBS_FIXEDORDER      = &H00000800
#IF (%WIN32_IE >= &H0400)
%RBS_REGISTERDROP    = &H00001000
%RBS_AUTOSIZE        = &H00002000
%RBS_VERTICALGRIPPER = &H00004000  ' this always has the vertical gripper(default for horizontal mode)
%RBS_DBLCLKTOGGLE    = &H00008000
#ENDIF

TYPE REBARINFO
    cbSize AS DWORD
    fMask  AS DWORD
    himl   AS DWORD
END TYPE

%RBBS_BREAK          = &H00000001  ' break to new line
%RBBS_FIXEDSIZE      = &H00000002  ' band can't be sized
%RBBS_CHILDEDGE      = &H00000004  ' edge around top & bottom of child window
%RBBS_HIDDEN         = &H00000008  ' don't show
%RBBS_NOVERT         = &H00000010  ' don't show when vertical
%RBBS_FIXEDBMP       = &H00000020  ' bitmap doesn't move during band resize
#IF (%WIN32_IE >= &H0400)          '
%RBBS_VARIABLEHEIGHT = &H00000040  ' allow autosizing of this child vertically
%RBBS_GRIPPERALWAYS  = &H00000080  ' always show the gripper
%RBBS_NOGRIPPER      = &H00000100  ' never show the gripper
#IF (%WIN32_IE >= &H0500)          '
%RBBS_USECHEVRON     = &H00000200  ' display drop-down button for this band if it's sized smaller than ideal width
#IF (%WIN32_IE >= &H0501)          '
%RBBS_HIDETITLE      = &H00000400  ' keep band title hidden
%RBBS_TOPALIGN       = &H00000800  ' keep band title hidden
#ENDIF  ' &H0501                    '
#ENDIF  ' &H0500                    '
#ENDIF  ' &H0400                    '


%RBBIM_STYLE         = &H00000001
%RBBIM_COLORS        = &H00000002
%RBBIM_TEXT          = &H00000004
%RBBIM_IMAGE         = &H00000008
%RBBIM_CHILD         = &H00000010
%RBBIM_CHILDSIZE     = &H00000020
%RBBIM_SIZE          = &H00000040
%RBBIM_BACKGROUND    = &H00000080
%RBBIM_ID            = &H00000100
#IF (%WIN32_IE >= &H0400)
%RBBIM_IDEALSIZE     = &H00000200
%RBBIM_LPARAM        = &H00000400
%RBBIM_HEADERSIZE    = &H00000800  ' control the size of the header
#ENDIF
#IF (%WIN32_WINNT >= &H0600)
%RBBIM_CHEVRONLOCATION = &H00001000
%RBBIM_CHEVRONSTATE    = &H00002000
#ENDIF

TYPE REBARBANDINFOA
    cbSize     AS DWORD
    fMask      AS DWORD
    fStyle     AS DWORD
    clrFore    AS DWORD
    clrBack    AS DWORD
    lpText     AS ASCIIZ PTR
    cch        AS DWORD
    iImage     AS LONG
    hwndChild  AS DWORD
    cxMinChild AS DWORD
    cyMinChild AS DWORD
    cx         AS DWORD
    hbmBack    AS DWORD
    wID        AS DWORD
#IF (%WIN32_IE >= &H0400)
    cyChild    AS DWORD
    cyMaxChild AS DWORD
    cyIntegral AS DWORD
    cxIdeal    AS DWORD
    lParam     AS LONG
    cxHeader   AS DWORD
#ENDIF
#IF (%WIN32_WINNT >= &H0600)
    rcChevronLocation AS RECT  ' the rect is in client co-ord wrt hwndChild
    uChevronState     AS DWORD ' STATE_SYSTEM_*
#ENDIF
END TYPE

TYPE REBARBANDINFOW
    cbSize     AS DWORD
    fMask      AS DWORD
    fStyle     AS DWORD
    clrFore    AS DWORD
    clrBack    AS DWORD
    lpText     AS WSTRINGZ PTR
    cch        AS DWORD
    iImage     AS LONG
    hwndChild  AS DWORD
    cxMinChild AS DWORD
    cyMinChild AS DWORD
    cx         AS DWORD
    hbmBack    AS DWORD
    wID        AS DWORD
#IF (%WIN32_IE >= &H0400)
    cyChild    AS DWORD
    cyMaxChild AS DWORD
    cyIntegral AS DWORD
    cxIdeal    AS DWORD
    lParam     AS LONG
    cxHeader   AS DWORD
#ENDIF
#IF (%WIN32_WINNT >= &H0600)
    rcChevronLocation AS RECT  ' the rect is in client co-ord wrt hwndChild
    uChevronState     AS DWORD ' STATE_SYSTEM_*
#ENDIF
END TYPE

%REBARBANDINFOA_V3_SIZE = 14 * 4 ' CCSIZEOF_STRUCT(REBARBANDINFOA, wID)
%REBARBANDINFOW_V3_SIZE = 14 * 4 ' CCSIZEOF_STRUCT(REBARBANDINFOW, wID)

%REBARBANDINFOA_V6_SIZE = 14 * 4 + 6 * 4 ' CCSIZEOF_STRUCT(REBARBANDINFOA, cxHeader)
%REBARBANDINFOW_V6_SIZE = 14 * 4 + 6 * 4 ' CCSIZEOF_STRUCT(REBARBANDINFOW, cxHeader)

#IF %DEF(%UNICODE)
TYPE REBARBANDINFO
    REBARBANDINFOW
END TYPE
%REBARBANDINFO_V3_SIZE = %REBARBANDINFOW_V3_SIZE
%REBARBANDINFO_V6_SIZE = %REBARBANDINFOW_V6_SIZE
#ELSE
TYPE REBARBANDINFO
    REBARBANDINFOA
END TYPE
%REBARBANDINFO_V3_SIZE = %REBARBANDINFOA_V3_SIZE
%REBARBANDINFO_V6_SIZE = %REBARBANDINFOA_V6_SIZE
#ENDIF

%RB_INSERTBANDA  = (%WM_USER +  1)
%RB_DELETEBAND   = (%WM_USER +  2)
%RB_GETBARINFO   = (%WM_USER +  3)
%RB_SETBARINFO   = (%WM_USER +  4)
#IF (%WIN32_IE < &H0400)
%RB_GETBANDINFO  = (%WM_USER +  5)
#ENDIF
%RB_SETBANDINFOA = (%WM_USER +  6)
%RB_SETPARENT    = (%WM_USER +  7)
#IF (%WIN32_IE >= &H0400)
%RB_HITTEST      = (%WM_USER +  8)
%RB_GETRECT      = (%WM_USER +  9)
#ENDIF
%RB_INSERTBANDW  = (%WM_USER +  10)
%RB_SETBANDINFOW = (%WM_USER +  11)
%RB_GETBANDCOUNT = (%WM_USER +  12)
%RB_GETROWCOUNT  = (%WM_USER +  13)
%RB_GETROWHEIGHT = (%WM_USER +  14)
#IF (%WIN32_IE >= &H0400)
%RB_IDTOINDEX    = (%WM_USER +  16) ' wParam == id
%RB_GETTOOLTIPS  = (%WM_USER +  17)
%RB_SETTOOLTIPS  = (%WM_USER +  18)
%RB_SETBKCOLOR   = (%WM_USER +  19) ' sets the default BK color
%RB_GETBKCOLOR   = (%WM_USER +  20) ' defaults to CLR_NONE
%RB_SETTEXTCOLOR = (%WM_USER +  21)
%RB_GETTEXTCOLOR = (%WM_USER +  22) ' defaults to &H00000000

#IF (%WIN32_WINNT >= &H0501)
%RBSTR_CHANGERECT = &H0001   ' flags for RB_SIZETORECT
#ENDIF

%RB_SIZETORECT   = (%WM_USER + 23) ' resize the rebar/break bands and such to this rect(lparam)
#ENDIF  ' %WIN32_IE >= &H0400

%RB_SETCOLORSCHEME  = %CCM_SETCOLORSCHEME  ' lParam is color scheme
%RB_GETCOLORSCHEME  = %CCM_GETCOLORSCHEME  ' fills in COLORSCHEME pointed to by lParam

#IF %DEF(%UNICODE)
%RB_INSERTBAND  = %RB_INSERTBANDW
%RB_SETBANDINFO = %RB_SETBANDINFOW
#ELSE
%RB_INSERTBAND  = %RB_INSERTBANDA
%RB_SETBANDINFO = %RB_SETBANDINFOA
#ENDIF

#IF (%WIN32_IE >= &H0400)
' for manual drag control
' lparam == cursor pos
        ' -1 means do it yourself.
        ' -2 means use what you had saved before
%RB_BEGINDRAG    = (%WM_USER + 24)
%RB_ENDDRAG      = (%WM_USER + 25)
%RB_DRAGMOVE     = (%WM_USER + 26)
%RB_GETBARHEIGHT = (%WM_USER + 27)
%RB_GETBANDINFOW = (%WM_USER + 28)
%RB_GETBANDINFOA = (%WM_USER + 29)

#IF %DEF(%UNICODE)
%RB_GETBANDINFO  = %RB_GETBANDINFOW
#ELSE
%RB_GETBANDINFO  = %RB_GETBANDINFOA
#ENDIF

%RB_MINIMIZEBAND = (%WM_USER + 30)
%RB_MAXIMIZEBAND = (%WM_USER + 31)

%RB_GETDROPTARGET = (%CCM_GETDROPTARGET)

%RB_GETBANDBORDERS = (%WM_USER + 34)  ' returns in lparam = lprc the amount of edges added to band wparam

%RB_SHOWBAND     = (%WM_USER + 35)      ' show/hide band
%RB_SETPALETTE   = (%WM_USER + 37)
%RB_GETPALETTE   = (%WM_USER + 38)
%RB_MOVEBAND     = (%WM_USER + 39)

%RB_SETUNICODEFORMAT = %CCM_SETUNICODEFORMAT
%RB_GETUNICODEFORMAT = %CCM_GETUNICODEFORMAT

#ENDIF      ' %WIN32_IE >= &H0400

#IF (%WIN32_WINNT >= &H0501)
%RB_GETBANDMARGINS = (%WM_USER + 40)
%RB_SETWINDOWTHEME = %CCM_SETWINDOWTHEME
#ENDIF

#IF (%WIN32_IE >= &H0600)
%RB_SETEXTENDEDSTYLE = (%WM_USER + 41)
%RB_GETEXTENDEDSTYLE = (%WM_USER + 42)
#ENDIF      ' %WIN32_IE >= &H0600

#IF (%WIN32_IE >= &H0500)
%RB_PUSHCHEVRON      = (%WM_USER + 43)
#ENDIF      ' %WIN32_IE >= &H0500

#IF (%WIN32_WINNT >= &H0600)
%RB_SETBANDWIDTH     = (%WM_USER + 44)  ' set width for docked band
#ENDIF      ' %WIN32_WINNT >= &H0600

%RBN_HEIGHTCHANGE    = (%RBN_FIRST - 0)

#IF (%WIN32_IE >= &H0400)
%RBN_GETOBJECT       = (%RBN_FIRST - 1)
%RBN_LAYOUTCHANGED   = (%RBN_FIRST - 2)
%RBN_AUTOSIZE        = (%RBN_FIRST - 3)
%RBN_BEGINDRAG       = (%RBN_FIRST - 4)
%RBN_ENDDRAG         = (%RBN_FIRST - 5)
%RBN_DELETINGBAND    = (%RBN_FIRST - 6)     ' Uses NMREBAR
%RBN_DELETEDBAND     = (%RBN_FIRST - 7)     ' Uses NMREBAR
%RBN_CHILDSIZE       = (%RBN_FIRST - 8)

#IF (%WIN32_IE >= &H0500)
%RBN_CHEVRONPUSHED   = (%RBN_FIRST - 10)
#ENDIF      ' %WIN32_IE >= &H0500

#IF (%WIN32_IE >= &H0600)
%RBN_SPLITTERDRAG    = (%RBN_FIRST - 11)
#ENDIF      ' %WIN32_IE >= &H0600


#IF (%WIN32_IE >= &H0500)
%RBN_MINMAX          = (%RBN_FIRST - 21)
#ENDIF

#IF (%WIN32_WINNT >= &H0501)
%RBN_AUTOBREAK       = (%RBN_FIRST - 22)
#ENDIF


TYPE NMREBARCHILDSIZE
    hdr     AS NMHDR
    uBand   AS DWORD
    wID     AS DWORD
    rcChild AS RECT
    rcBand  AS RECT
END TYPE

TYPE NMREBAR
    hdr    AS NMHDR
    dwMask AS DWORD    ' RBNM_*
    uBand  AS DWORD
    fStyle AS DWORD
    wID    AS DWORD
    lParam AS LONG
END TYPE

' Mask flags for NMREBAR
%RBNM_ID     = &H00000001
%RBNM_STYLE  = &H00000002
%RBNM_LPARAM = &H00000004

TYPE NMRBAUTOSIZE
    hdr      AS NMHDR
    fChanged AS LONG
    rcTarget AS RECT
    rcActual AS RECT
END TYPE

#IF (%WIN32_IE >= &H0500)
TYPE NMREBARCHEVRON
    hdr      AS NMHDR
    uBand    AS DWORD
    wID      AS DWORD
    lParam   AS LONG
    rc       AS RECT
    lParamNM AS LONG
END TYPE
#ENDIF

#IF (%WIN32_IE >= &H0600)
TYPE NMREBARSPLITTER
    hdr      AS NMHDR
    rcSizing AS RECT
END TYPE
#ENDIF

#IF (%WIN32_WINNT >= &H0501)
%RBAB_AUTOSIZE = &H0001 ' These are not flags and are all mutually exclusive
%RBAB_ADDBAND  = &H0002

TYPE NMREBARAUTOBREAK
    hdr           AS NMHDR
    uBand         AS DWORD
    wID           AS DWORD
    lParam        AS LONG
    uMsg          AS DWORD
    fStyleCurrent AS DWORD
    fAutoBreak    AS LONG
END TYPE
#ENDIF

%RBHT_NOWHERE  = &H0001
%RBHT_CAPTION  = &H0002
%RBHT_CLIENT   = &H0003
%RBHT_GRABBER  = &H0004
#IF (%WIN32_IE >= &H0500)
%RBHT_CHEVRON  = &H0008
#ENDIF
#IF (%WIN32_IE >= &H0600)
%RBHT_SPLITTER = &H0010
#ENDIF

TYPE RBHITTESTINFO
    pt    AS POINT
    flags AS DWORD
    iBand AS LONG
END TYPE

#ENDIF      ' %WIN32_IE >= &H0400

#ENDIF      ' %NOREBAR

#ENDIF      ' %WIN32_IE >= &H0300



'==============================================================================
' TOOLTIPS CONTROL

#IF NOT %DEF(%NOTOOLTIPS)

#IF %DEF(%WIN32)

$$TOOLTIPS_CLASSW    = "tooltips_class32"$$
$TOOLTIPS_CLASSA     = "tooltips_class32"

#IF %DEF(%UNICODE)
MACRO TOOLTIPS_CLASS = $$TOOLTIPS_CLASSW
#ELSE
MACRO TOOLTIPS_CLASS = $TOOLTIPS_CLASSA
#ENDIF

#ELSE
MACRO TOOLTIPS_CLASS = "tooltips_class"
#ENDIF

%TTTOOLINFOA_V1_SIZE = 7 * 4 ' CCSIZEOF_STRUCT(TTTOOLINFOA, lpszText)
%TTTOOLINFOW_V1_SIZE = 7 * 4 ' CCSIZEOF_STRUCT(TTTOOLINFOW, lpszText)
%TTTOOLINFOA_V2_SIZE = 7 * 4 + 4 ' CCSIZEOF_STRUCT(TTTOOLINFOA, lParam)
%TTTOOLINFOW_V2_SIZE = 7 * 4 + 4 ' CCSIZEOF_STRUCT(TTTOOLINFOW, lParam)
%TTTOOLINFOA_V3_SIZE = 7 * 4 + 4 + 4 ' CCSIZEOF_STRUCT(TTTOOLINFOA, lpReserved)
%TTTOOLINFOW_V3_SIZE = 7 * 4 + 4 + 4 ' CCSIZEOF_STRUCT(TTTOOLINFOW, lpReserved)

TYPE TTTOOLINFOA
    cbSize     AS DWORD
    uFlags     AS DWORD
    hwnd       AS DWORD
    uId        AS DWORD
    rrect      AS RECT
    hinst      AS DWORD
    lpszText   AS ASCIIZ PTR
#IF (%WIN32_IE >= &H0300)
    lParam     AS LONG
#ENDIF
#IF (%WIN32_WINNT >= &H0501)
    lpReserved AS DWORD
#ENDIF
END TYPE

TYPE TTTOOLINFOW
    cbSize     AS DWORD
    uFlags     AS DWORD
    hwnd       AS DWORD
    uId        AS DWORD
    rrect      AS RECT
    hinst      AS DWORD
    lpszText   AS WSTRINGZ PTR
#IF (%WIN32_IE >= &H0300)
    lParam     AS LONG
#ENDIF
#IF (%WIN32_WINNT >= &H0501)
    lpReserved AS DWORD
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
TYPE TTTOOLINFO
    TTTOOLINFOW
END TYPE
%TTTOOLINFO_V1_SIZE = %TTTOOLINFOW_V1_SIZE
#ELSE
TYPE TTTOOLINFO
    TTTOOLINFOA
END TYPE
%TTTOOLINFO_V1_SIZE = %TTTOOLINFOA_V1_SIZE
#ENDIF

#IF (%WIN32_IE >= &H0300)
TYPE TOOLINFOA
    TTTOOLINFOA
END TYPE
TYPE TOOLINFOW
    TTTOOLINFOW
END TYPE
#ELSE
TYPE TTTOOLINFOA
    TOOLINFOA
END TYPE
TYPE TTTOOLINFOW
    TOOLINFOW
END TYPE
#ENDIF

TYPE TOOLINFO
    TTTOOLINFO
END TYPE

%TTS_ALWAYSTIP = &H0001
%TTS_NOPREFIX  = &H0002
#IF (%WIN32_IE >= &H0500)
%TTS_NOANIMATE = &H0010
%TTS_NOFADE    = &H0020
%TTS_BALLOON   = &H0040
%TTS_CLOSE     = &H0080
#ENDIF
#IF %WIN32_WINNT >= &H0600
%TTS_USEVISUALSTYLE = &H100  ' Use themed hyperlinks
#ENDIF

' end_r_commctrl

%TTF_IDISHWND      = &H00000001

' Use this to center around trackpoint in trackmode
' -OR- to center around tool in normal mode.
' Use TTF_ABSOLUTE to place the tip exactly at the track coords when
' in tracking mode. TTF_ABSOLUTE can be used in conjunction with TTF_CENTERTIP
' to center the tip absolutely about the track point.

%TTF_CENTERTIP     = &H00000002
%TTF_RTLREADING    = &H00000004
%TTF_SUBCLASS      = &H00000010
#IF (%WIN32_IE >= &H0300)
%TTF_TRACK         = &H00000020
%TTF_ABSOLUTE      = &H00000080
%TTF_TRANSPARENT   = &H00000100
#IF (%WIN32_IE >= &H0501)
%TTF_PARSELINKS    = &H00001000
#ENDIF  ' %WIN32_IE >= &H0501
%TTF_DI_SETITEM    = &H8000??     ' valid only on the TTN_NEEDTEXT callback
#ENDIF      ' %WIN32_IE >= &H0300

%TTDT_AUTOMATIC    = 0
%TTDT_RESHOW       = 1
%TTDT_AUTOPOP      = 2
%TTDT_INITIAL      = 3

' ToolTip Icons(Set with TTM_SETTITLE)
%TTI_NONE          = 0
%TTI_INFO          = 1
%TTI_WARNING       = 2
%TTI_ERROR         = 3
#IF (%WIN32_WINNT >= &H0600)
%TTI_INFO_LARGE    = 4
%TTI_WARNING_LARGE = 5
%TTI_ERROR_LARGE   = 6
#ENDIF  '(%WIN32_WINNT >= &H0600)

' Tool Tip Messages
%TTM_ACTIVATE      = %WM_USER +  1
%TTM_SETDELAYTIME  = %WM_USER +  3
%TTM_ADDTOOLA      = %WM_USER +  4
%TTM_ADDTOOLW      = %WM_USER + 50
%TTM_DELTOOLA      = %WM_USER +  5
%TTM_DELTOOLW      = %WM_USER + 51
%TTM_NEWTOOLRECTA  = %WM_USER +  6
%TTM_NEWTOOLRECTW  = %WM_USER + 52
%TTM_RELAYEVENT    = %WM_USER +  7

%TTM_GETTOOLINFOA  = %WM_USER +  8
%TTM_GETTOOLINFOW  = %WM_USER + 53

%TTM_SETTOOLINFOA  = %WM_USER +  9
%TTM_SETTOOLINFOW  = %WM_USER + 54

%TTM_HITTESTA        = %WM_USER + 10
%TTM_HITTESTW        = %WM_USER + 55
%TTM_GETTEXTA        = %WM_USER + 11
%TTM_GETTEXTW        = %WM_USER + 56
%TTM_UPDATETIPTEXTA  = %WM_USER + 12
%TTM_UPDATETIPTEXTW  = %WM_USER + 57
%TTM_GETTOOLCOUNT    = %WM_USER + 13
%TTM_ENUMTOOLSA      = %WM_USER + 14
%TTM_ENUMTOOLSW      = %WM_USER + 58
%TTM_GETCURRENTTOOLA = %WM_USER + 15
%TTM_GETCURRENTTOOLW = %WM_USER + 59
%TTM_WINDOWFROMPOINT = %WM_USER + 16
#IF (%WIN32_IE >= &H0300)
%TTM_TRACKACTIVATE   = %WM_USER + 17  ' wParam = TRUE/FALSE start end  lparam = LPTOOLINFO
%TTM_TRACKPOSITION   = %WM_USER + 18  ' lParam = dwPos
%TTM_SETTIPBKCOLOR   = %WM_USER + 19
%TTM_SETTIPTEXTCOLOR = %WM_USER + 20
%TTM_GETDELAYTIME    = %WM_USER + 21
%TTM_GETTIPBKCOLOR   = %WM_USER + 22
%TTM_GETTIPTEXTCOLOR = %WM_USER + 23
%TTM_SETMAXTIPWIDTH  = %WM_USER + 24
%TTM_GETMAXTIPWIDTH  = %WM_USER + 25
%TTM_SETMARGIN       = %WM_USER + 26  ' lParam = lprc
%TTM_GETMARGIN       = %WM_USER + 27  ' lParam = lprc
%TTM_POP             = %WM_USER + 28
#ENDIF
#IF (%WIN32_IE >= &H0400)
%TTM_UPDATE          = %WM_USER + 29
#ENDIF
#IF (%WIN32_IE >= &H0500)
%TTM_GETBUBBLESIZE   = %WM_USER + 30
%TTM_ADJUSTRECT      = %WM_USER + 31
%TTM_SETTITLEA       = %WM_USER + 32  ' wParam = TTI_*, lParam = char* szTitle
%TTM_SETTITLEW       = %WM_USER + 33  ' wParam = TTI_*, lParam = wchar* szTitle
#ENDIF

#IF (%WIN32_WINNT >= &H0501)
%TTM_POPUP           = %WM_USER + 34
%TTM_GETTITLE        = %WM_USER + 35  ' wParam = 0, lParam = TTGETTITLE*

TYPE TTGETTITLE
    dwSize       AS DWORD
    uTitleBitmap AS DWORD
    cch          AS DWORD
    pszTitle     AS WSTRINGZ PTR
END TYPE
#ENDIF

#IF %DEF(%UNICODE)
%TTM_ADDTOOL          = %TTM_ADDTOOLW
%TTM_DELTOOL          = %TTM_DELTOOLW
%TTM_NEWTOOLRECT      = %TTM_NEWTOOLRECTW
%TTM_GETTOOLINFO      = %TTM_GETTOOLINFOW
%TTM_SETTOOLINFO      = %TTM_SETTOOLINFOW
%TTM_HITTEST          = %TTM_HITTESTW
%TTM_GETTEXT          = %TTM_GETTEXTW
%TTM_UPDATETIPTEXT    = %TTM_UPDATETIPTEXTW
%TTM_ENUMTOOLS        = %TTM_ENUMTOOLSW
%TTM_GETCURRENTTOOL   = %TTM_GETCURRENTTOOLW
#IF (%WIN32_IE >= &H0500)
%TTM_SETTITLE         = %TTM_SETTITLEW
#ENDIF
#ELSE
%TTM_ADDTOOL          = %TTM_ADDTOOLA
%TTM_DELTOOL          = %TTM_DELTOOLA
%TTM_NEWTOOLRECT      = %TTM_NEWTOOLRECTA
%TTM_GETTOOLINFO      = %TTM_GETTOOLINFOA
%TTM_SETTOOLINFO      = %TTM_SETTOOLINFOA
%TTM_HITTEST          = %TTM_HITTESTA
%TTM_GETTEXT          = %TTM_GETTEXTA
%TTM_UPDATETIPTEXT    = %TTM_UPDATETIPTEXTA
%TTM_ENUMTOOLS        = %TTM_ENUMTOOLSA
%TTM_GETCURRENTTOOL   = %TTM_GETCURRENTTOOLA
#IF (%WIN32_IE >= &H0500)
%TTM_SETTITLE         = %TTM_SETTITLEA
#ENDIF
#ENDIF  ' #IF %DEF(%UNICODE)

#IF (%WIN32_WINNT >= &H0501)
%TTM_SETWINDOWTHEME   = %CCM_SETWINDOWTHEME
#ENDIF


TYPE TT_HITTESTINFOA
    hWnd  AS DWORD
    pt    AS POINT
    ti    AS TTTOOLINFOA
END TYPE

TYPE TT_HITTESTINFOW
    hWnd  AS DWORD
    pt    AS POINT
    ti    AS TTTOOLINFOW
END TYPE

#IF %DEF(%UNICODE)
TYPE TTHITTESTINFO
    TT_HITTESTINFOW
END TYPE
TYPE TT_HITTESTINFO
    TT_HITTESTINFOW
END TYPE
#ELSE
TYPE TTHITTESTINFO
    TT_HITTESTINFOA
END TYPE
TYPE TT_HITTESTINFO
    TT_HITTESTINFOA
END TYPE
#ENDIF

%TTN_GETDISPINFOA    = %TTN_FIRST
%TTN_GETDISPINFOW    = %TTN_FIRST - 10
%TTN_SHOW            = %TTN_FIRST - 1
%TTN_POP             = %TTN_FIRST - 2
%TTN_LINKCLICK       = %TTN_FIRST - 3

#IF %DEF(%UNICODE)
%TTN_GETDISPINFO     = %TTN_GETDISPINFOW
#ELSE
%TTN_GETDISPINFO     = %TTN_GETDISPINFOA
#ENDIF

%TTN_NEEDTEXT        = %TTN_GETDISPINFO
%TTN_NEEDTEXTA       = %TTN_GETDISPINFOA
%TTN_NEEDTEXTW       = %TTN_GETDISPINFOW

%NMTTDISPINFOA_V1_SIZE = 3 * 4 + 4 + 80 + 4 + 4 ' CCSIZEOF_STRUCT(NMTTDISPINFOA, uFlags)
%NMTTDISPINFOW_V1_SIZE = 3 * 4 + 4 + 80 + 4 + 4 ' CCSIZEOF_STRUCT(NMTTDISPINFOW, uFlags)

TYPE NMTTDISPINFOA
    hdr       AS NMHDR
    lpszText  AS ASCIIZ PTR
    szText    AS ASCIIZ * 80
    hInst     AS DWORD
    uFlags    AS DWORD
#IF (%WIN32_IE >= &H0300)
    lParam    AS DWORD
#ENDIF
END TYPE

TYPE NMTTDISPINFOW
    hdr       AS NMHDR
    lpszText  AS WSTRINGZ PTR
    szText    AS WSTRINGZ * 80
    hInst     AS DWORD
    uFlags    AS DWORD
#IF (%WIN32_IE >= &H0300)
    lParam    AS DWORD
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
TYPE NMTTDISPINFO
    NMTTDISPINFOW
END TYPE
%NMTTDISPINFO_V1_SIZE = %NMTTDISPINFOW_V1_SIZE
#ELSE
TYPE NMTTDISPINFO
    NMTTDISPINFOA
END TYPE
%NMTTDISPINFO_V1_SIZE = %NMTTDISPINFOA_V1_SIZE
#ENDIF

#IF (%WIN32_IE >= &H0300)
TYPE TOOLTIPTEXTW
    NMTTDISPINFOW
END TYPE
TYPE TOOLTIPTEXTA
    NMTTDISPINFOA
END TYPE
#ELSE
TYPE NMTTDISPINFOA
    TOOLTIPTEXTA
END TYPE
TYPE NMTTDISPINFOW
    TOOLTIPTEXTW
END TYPE
#ENDIF

TYPE TOOLTIPTEXT
    NMTTDISPINFO
END TYPE

#ENDIF      ' NOTOOLTIPS



'==============================================================================
' STATUS BAR CONTROL

#IF NOT %DEF(%NOSTATUSBAR)

%SBARS_SIZEGRIP = &H0100
#IF (%WIN32_IE >= &H0500)
%SBARS_TOOLTIPS = &H0800
#ENDIF

#IF (%WIN32_IE >= &H0400)
' this is a status bar flag, preference to SBARS_TOOLTIPS
%SBT_TOOLTIPS   = &H0800
#ENDIF

DECLARE SUB DrawStatusTextA LIB "ComCtl32.dll" ALIAS "DrawStatusTextA" _
   (BYVAL hDc AS DWORD, lprec AS RECT, sztext AS ASCIIZ, _
    BYVAL uFlags AS DWORD)

DECLARE SUB DrawStatusTextW LIB "ComCtl32.dll" ALIAS "DrawStatusTextW" _
   (BYVAL hDc AS DWORD, lprec AS RECT, sztext AS WSTRINGZ, _
    BYVAL uFlags AS DWORD)

DECLARE FUNCTION CreateStatusWindowA LIB "ComCtl32.dll" _
    ALIAS "CreateStatusWindowA" (BYVAL STYLE AS LONG, lpszText AS ASCIIZ, _
    BYVAL hWndParent AS DWORD, BYVAL wId AS DWORD) AS DWORD

DECLARE FUNCTION CreateStatusWindowW LIB "ComCtl32.dll" _
    ALIAS "CreateStatusWindowW" (BYVAL STYLE AS LONG, lpszText AS WSTRINGZ, _
    BYVAL hWndParent AS DWORD, BYVAL wId AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION CreateStatusWindow LIB "ComCtl32.dll" _
    ALIAS "CreateStatusWindowW" (BYVAL STYLE AS LONG, lpszText AS WSTRINGZ, _
    BYVAL hWndParent AS DWORD, BYVAL wId AS DWORD) AS DWORD
DECLARE SUB DrawStatusText LIB "ComCtl32.dll" ALIAS "DrawStatusTextW" _
   (BYVAL hDc AS DWORD, lprec AS RECT, sztext AS WSTRINGZ, _
    BYVAL uFlags AS DWORD)
#ELSE
DECLARE FUNCTION CreateStatusWindow LIB "ComCtl32.dll" _
    ALIAS "CreateStatusWindowA" (BYVAL STYLE AS LONG, lpszText AS ASCIIZ, _
    BYVAL hWndParent AS DWORD, BYVAL wId AS DWORD) AS DWORD
DECLARE SUB DrawStatusText LIB "ComCtl32.dll" ALIAS "DrawStatusTextA" _
   (BYVAL hDc AS DWORD, lprec AS RECT, sztext AS ASCIIZ, _
    BYVAL uFlags AS DWORD)
#ENDIF

#IF %DEF(%WIN32)
$$STATUSCLASSNAMEW    = "msctls_statusbar32"$$
$STATUSCLASSNAMEA     = "msctls_statusbar32"

#IF %DEF(%UNICODE)
MACRO STATUSCLASSNAME = $$STATUSCLASSNAMEW
#ELSE
MACRO STATUSCLASSNAME = $STATUSCLASSNAMEA
#ENDIF

#ELSE
MACRO STATUSCLASSNAME = "msctls_statusbar"
#ENDIF

%SB_SETTEXTA          = %WM_USER + 1
%SB_SETTEXTW          = %WM_USER + 11
%SB_GETTEXTA          = %WM_USER + 2
%SB_GETTEXTW          = %WM_USER + 13
%SB_GETTEXTLENGTHA    = %WM_USER + 3
%SB_GETTEXTLENGTHW    = %WM_USER + 12

%SB_SETPARTS          = %WM_USER + 4
%SB_GETPARTS          = %WM_USER + 6
%SB_GETBORDERS        = %WM_USER + 7
%SB_SETMINHEIGHT      = %WM_USER + 8
%SB_SIMPLE            = %WM_USER + 9
%SB_GETRECT           = %WM_USER + 10

#IF (%WIN32_IE >= &H0300)
%SB_ISSIMPLE          = %WM_USER+14
#ENDIF
#IF (%WIN32_IE >= &H0400)
%SB_SETICON           = %WM_USER+15
%SB_SETTIPTEXTA       = %WM_USER+16
%SB_SETTIPTEXTW       = %WM_USER+17
%SB_GETTIPTEXTA       = %WM_USER+18
%SB_GETTIPTEXTW       = %WM_USER+19
%SB_GETICON           = %WM_USER+20
%SB_SETUNICODEFORMAT  = %CCM_SETUNICODEFORMAT
%SB_GETUNICODEFORMAT  = %CCM_GETUNICODEFORMAT
#ENDIF

%SBT_OWNERDRAW        = &H1000
%SBT_NOBORDERS        = &H0100
%SBT_POPOUT           = &H0200
%SBT_RTLREADING       = &H0400
%SBT_TOOLTIPS         = &H0800
#IF (%WIN32_IE >= &H0500)
%SBT_NOTABPARSING     = &H0800
#ENDIF

#IF %DEF(%UNICODE)
%SB_GETTEXT            = %SB_GETTEXTW
%SB_SETTEXT            = %SB_SETTEXTW
%SB_GETTEXTLENGTH      = %SB_GETTEXTLENGTHW
#IF (%WIN32_IE >= &H0400)
%SB_SETTIPTEXT         = %SB_SETTIPTEXTW
%SB_GETTIPTEXT         = %SB_GETTIPTEXTW
#ENDIF
#ELSE
%SB_GETTEXT            = %SB_GETTEXTA
%SB_SETTEXT            = %SB_SETTEXTA
%SB_GETTEXTLENGTH      = %SB_GETTEXTLENGTHA
#IF (%WIN32_IE >= &H0400)
%SB_SETTIPTEXT         = %SB_SETTIPTEXTA
%SB_GETTIPTEXT         = %SB_GETTIPTEXTA
#ENDIF
#ENDIF

%SB_SETBKCOLOR         = %CCM_SETBKCOLOR  ' lParam = bkColor

' status bar notifications
#IF (%WIN32_IE >= &H0400)
%SBN_SIMPLEMODECHANGE  = %SBN_FIRST - 0
#ENDIF

#IF (%WIN32_IE >= &H0500)
' refers to the data saved for simple mode
%SB_SIMPLEID = &H00ff
#ENDIF

#ENDIF      ' %NOSTATUSBAR



'==============================================================================
' MENU HELP

#IF NOT %DEF(%NOMENUHELP)

DECLARE SUB MenuHelp LIB "ComCtl32.dll" ALIAS "MenuHelp" _
   (BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG, _
    BYVAL hMainMenu AS DWORD, BYVAL hInst AS DWORD, _
    BYVAL hWndStatus AS DWORD, lpwIds AS DWORD)

DECLARE FUNCTION ShowHideMenuCtl LIB "ComCtl32.dll" ALIAS "ShowHideMenuCtl" _
   (BYVAL hWnd AS DWORD, BYVAL uFlags AS DWORD, lpInfo AS LONG) AS LONG

DECLARE SUB GetEffectiveClientRect LIB "ComCtl32.dll" _
    ALIAS "GetEffectiveClientRect" (BYVAL hWnd AS DWORD, lprc AS RECT, _
    lpInfo AS LONG)

%MINSYSCOMMAND  = %SC_SIZE

#ENDIF



'==============================================================================
' TRACKBAR CONTROL

#IF NOT %DEF(%NOTRACKBAR)

#IF %DEF(%WIN32)

$TRACKBAR_CLASSA     = "msctls_trackbar32"
$$TRACKBAR_CLASSW    = "msctls_trackbar32"$$

#IF %DEF(%UNICODE)
MACRO TRACKBAR_CLASS = $$TRACKBAR_CLASSW
#ELSE
MACRO TRACKBAR_CLASS = $TRACKBAR_CLASSA
#ENDIF

#ELSE
$TRACKBAR_CLASS      = "msctls_trackbar"
#ENDIF

%TBS_AUTOTICKS      = &H0001
%TBS_VERT           = &H0002
%TBS_HORZ           = &H0000
%TBS_TOP            = &H0004
%TBS_BOTTOM         = &H0000
%TBS_LEFT           = &H0004
%TBS_RIGHT          = &H0000
%TBS_BOTH           = &H0008
%TBS_NOTICKS        = &H0010
%TBS_ENABLESELRANGE = &H0020
%TBS_FIXEDLENGTH    = &H0040
%TBS_NOTHUMB        = &H0080
#IF (%WIN32_IE >= &H0300)
%TBS_TOOLTIPS       = &H0100
#ENDIF
#IF (%WIN32_IE >= &H0500)
%TBS_REVERSED       = &H0200  ' Accessibility hint: the smaller number(usually the min value) means "high" and the larger number(usually the max value) means "low"
#ENDIF

#IF (%WIN32_IE >= &H0501)
%TBS_DOWNISLEFT     = &H0400  ' Down=Left and Up=Right(default is Down=Right and Up=Left)
#ENDIF

#IF (%WIN32_IE >= &H0600)
%TBS_NOTIFYBEFOREMOVE = &H0800  ' Trackbar should notify parent before repositioning the slider due to user action(enables snapping)
#ENDIF

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%TBS_TRANSPARENTBKGND = &H1000  ' Background is painted by the parent via WM_PRINTCLIENT
#ENDIF

%TBM_GETPOS             = %WM_USER
%TBM_GETRANGEMIN        = %WM_USER + 1
%TBM_GETRANGEMAX        = %WM_USER + 2
%TBM_GETTIC             = %WM_USER + 3
%TBM_SETTIC             = %WM_USER + 4
%TBM_SETPOS             = %WM_USER + 5
%TBM_SETRANGE           = %WM_USER + 6
%TBM_SETRANGEMIN        = %WM_USER + 7
%TBM_SETRANGEMAX        = %WM_USER + 8
%TBM_CLEARTICS          = %WM_USER + 9
%TBM_SETSEL             = %WM_USER + 10
%TBM_SETSELSTART        = %WM_USER + 11
%TBM_SETSELEND          = %WM_USER + 12
%TBM_GETPTICS           = %WM_USER + 14
%TBM_GETTICPOS          = %WM_USER + 15
%TBM_GETNUMTICS         = %WM_USER + 16
%TBM_GETSELSTART        = %WM_USER + 17
%TBM_GETSELEND          = %WM_USER + 18
%TBM_CLEARSEL           = %WM_USER + 19
%TBM_SETTICFREQ         = %WM_USER + 20
%TBM_SETPAGESIZE        = %WM_USER + 21
%TBM_GETPAGESIZE        = %WM_USER + 22
%TBM_SETLINESIZE        = %WM_USER + 23
%TBM_GETLINESIZE        = %WM_USER + 24
%TBM_GETTHUMBRECT       = %WM_USER + 25
%TBM_GETCHANNELRECT     = %WM_USER + 26
%TBM_SETTHUMBLENGTH     = %WM_USER + 27
%TBM_GETTHUMBLENGTH     = %WM_USER + 28
#IF (%WIN32_IE >= &H0300)
%TBM_SETTOOLTIPS        = %WM_USER + 29
%TBM_GETTOOLTIPS        = %WM_USER + 30
%TBM_SETTIPSIDE         = %WM_USER + 31

' TrackBar Tip Side flags
%TBTS_TOP               = 0
%TBTS_LEFT              = 1
%TBTS_BOTTOM            = 2
%TBTS_RIGHT             = 3

%TBM_SETBUDDY           = %WM_USER + 32 ' wparam = BOOL fLeft;(or right)
%TBM_GETBUDDY           = %WM_USER + 33 ' wparam = BOOL fLeft;(or right)
%TBM_SETPOSNOTIFY       = %WM_USER + 34
#ENDIF

#IF (%WIN32_IE >= &H0400)
%TBM_SETUNICODEFORMAT   = %CCM_SETUNICODEFORMAT
%TBM_GETUNICODEFORMAT   = %CCM_GETUNICODEFORMAT
#ENDIF

%TB_LINEUP              = 0
%TB_LINEDOWN            = 1
%TB_PAGEUP              = 2
%TB_PAGEDOWN            = 3
%TB_THUMBPOSITION       = 4
%TB_THUMBTRACK          = 5
%TB_TOP                 = 6
%TB_BOTTOM              = 7
%TB_ENDTRACK            = 8

#IF (%WIN32_IE >= &H0300)
' custom draw item specs
%TBCD_TICS    = &H0001
%TBCD_THUMB   = &H0002
%TBCD_CHANNEL = &H0003
#ENDIF

#IF (%WIN32_WINNT >= &H0600)
%TRBN_THUMBPOSCHANGING  = %TRBN_FIRST-1

' Structure for Trackbar's TRBN_THUMBPOSCHANGING notification
TYPE TRBTHUMBPOSCHANGING
    hdr     AS NMHDR
    dwPos   AS DWORD
    nReason AS LONG
END TYPE
#ENDIF

#ENDIF  ' trackbar


'==============================================================================
' DRAG LIST CONTROL

#IF NOT %DEF(%NODRAGLIST)

TYPE DRAGLISTINFO
    uNotification AS DWORD
    hWnd          AS DWORD
    ptCursor      AS POINT
END TYPE

%DL_BEGINDRAG  = %WM_USER + 133
%DL_DRAGGING   = %WM_USER + 134
%DL_DROPPED    = %WM_USER + 135
%DL_CANCELDRAG = %WM_USER + 136

%DL_CURSORSET  = 0
%DL_STOPCURSOR = 1
%DL_COPYCURSOR = 2
%DL_MOVECURSOR = 3

$DRAGLISTMSGSTRING = "commctrl_DragListMsg"
$$DRAGLISTMSGSTRING = "commctrl_DragListMsg"$$
#IF %DEF(%UNICODE)
MACRO DRAGLISTMSGSTRING = $$DRAGLISTMSGSTRING
#ELSE
MACRO DRAGLISTMSGSTRING = $DRAGLISTMSGSTRING
#ENDIF

DECLARE FUNCTION MakeDragList LIB "ComCtl32.dll" ALIAS "MakeDragList" _
   (BYVAL hLB AS DWORD) AS LONG

DECLARE SUB DrawInsert LIB "ComCtl32.dll" ALIAS "DrawInsert" _
   (BYVAL handParent AS DWORD, BYVAL hLB AS DWORD, BYVAL nItem AS LONG)

DECLARE FUNCTION LBItemFromPt LIB "ComCtl32.dll" ALIAS "LBItemFromPt" _
   (BYVAL hLB AS DWORD, BYVAL pt AS POINT, BYVAL bAutoScroll AS LONG) _
    AS LONG

#ENDIF  ' #IF NOT %DEF(%NODRAGLIST)



'==============================================================================
' UPDOWN CONTROL

#IF NOT %DEF(%NOUPDOWN)

#IF %DEF(%WIN32)

$UPDOWN_CLASSA     = "msctls_updown32"
$$UPDOWN_CLASSW    = "msctls_updown32"$$

#IF %DEF(%UNICODE)
MACRO UPDOWN_CLASS = $$UPDOWN_CLASSW
#ELSE
MACRO UPDOWN_CLASS = $UPDOWN_CLASSA
#ENDIF

#ELSE
MACRO UPDOWN_CLASS = "msctls_updown"
#ENDIF

TYPE UDACCEL
    nSec AS DWORD
    nInc AS DWORD
END TYPE

%UD_MAXVAL            = &H7FFF
%UD_MINVAL            = - %UD_MAXVAL

%UDS_WRAP             = &H0001
%UDS_SETBUDDYINT      = &H0002
%UDS_ALIGNRIGHT       = &H0004
%UDS_ALIGNLEFT        = &H0008
%UDS_AUTOBUDDY        = &H0010
%UDS_ARROWKEYS        = &H0020
%UDS_HORZ             = &H0040
%UDS_NOTHOUSANDS      = &H0080
#IF (%WIN32_IE >= &H0300)
%UDS_HOTTRACK         = &H0100
#ENDIF

%UDM_SETRANGE         = %WM_USER + 101
%UDM_GETRANGE         = %WM_USER + 102
%UDM_SETPOS           = %WM_USER + 103
%UDM_GETPOS           = %WM_USER + 104
%UDM_SETBUDDY         = %WM_USER + 105
%UDM_GETBUDDY         = %WM_USER + 106
%UDM_SETACCEL         = %WM_USER + 107
%UDM_GETACCEL         = %WM_USER + 108
%UDM_SETBASE          = %WM_USER + 109
%UDM_GETBASE          = %WM_USER + 110
#IF (%WIN32_IE >= &H0400)
%UDM_SETRANGE32       = %WM_USER + 111
%UDM_GETRANGE32       = %WM_USER + 112 ' wParam & lParam are LPINT
%UDM_SETUNICODEFORMAT = %CCM_SETUNICODEFORMAT
%UDM_GETUNICODEFORMAT = %CCM_GETUNICODEFORMAT
#ENDIF
#IF (%WIN32_IE >= &H0500)
%UDM_SETPOS32         = %WM_USER + 113
%UDM_GETPOS32         = %WM_USER + 114
#ENDIF

DECLARE FUNCTION CreateUpDownControl LIB "ComCtl32.dll" _
    ALIAS "CreateUpDownControl" (BYVAL dwStyle AS DWORD, BYVAL x AS LONG, _
    BYVAL y AS LONG, BYVAL cx AS LONG, BYVAL cy AS LONG, _
    BYVAL hParent AS DWORD, BYVAL nID AS LONG, BYVAL hInst AS DWORD, _
    BYVAL hBuddy AS DWORD, BYVAL nUpper AS LONG, BYVAL nLower AS LONG, _
    BYVAL nPos AS LONG) AS DWORD

TYPE NMUPDOWN
    hdr    AS NMHDR
    iPos   AS LONG
    iDelta AS LONG
END TYPE

#IF (%WIN32_IE >= &H0300)
TYPE NM_UPDOWN
    NMUPDOWN
END TYPE
#ELSE
TYPE NMUPDOWN
    NM_UPDOWN
END TYPE
#ENDIF

%UDN_DELTAPOS = %UDN_FIRST - 1


#ENDIF  ' %NOUPDOWN



'==============================================================================
' PROGRESS CONTROL

#IF NOT %DEF(%NOPROGRESS)

#IF %DEF(%WIN32)

$PROGRESS_CLASSA     = "msctls_progress32"
$$PROGRESS_CLASSW    = "msctls_progress32"$$


#IF %DEF(%UNICODE)
MACRO PROGRESS_CLASS = $$PROGRESS_CLASSW
#ELSE
MACRO PROGRESS_CLASS = $PROGRESS_CLASSA
#ENDIF

#ELSE
MACRO PROGRESS_CLASS = "msctls_progress"
#ENDIF  ' #IF %DEF(%WIN32)

#IF (%WIN32_IE >= &H0300)
%PBS_SMOOTH     = &H01
%PBS_VERTICAL   = &H04
#ENDIF

%PBM_SETRANGE    = %WM_USER + 1
%PBM_SETPOS      = %WM_USER + 2
%PBM_DELTAPOS    = %WM_USER + 3
%PBM_SETSTEP     = %WM_USER + 4
%PBM_STEPIT      = %WM_USER + 5
#IF (%WIN32_IE >= &H0300)
%PBM_SETRANGE32  = %WM_USER + 6  ' lParam = high, wParam = low

TYPE PBRANGE
    iLow  AS LONG
    iHigh AS LONG
END TYPE

%PBM_GETRANGE    = %WM_USER + 7     ' wParam = return(TRUE ? low : high). lParam = PPBRANGE or NULL
%PBM_GETPOS      = %WM_USER + 8
#IF (%WIN32_IE >= &H0400)
%PBM_SETBARCOLOR = %WM_USER + 9     ' lParam = bar color
#ENDIF  ' #IF (%WIN32_IE >= &H0400)
%PBM_SETBKCOLOR  = %CCM_SETBKCOLOR  ' lParam = bkColor
#ENDIF  ' #IF (%WIN32_IE >= &H0300)

#IF (%WIN32_WINNT >= &H0501)
%PBM_SETMARQUEE  = (%WM_USER+10)
#ENDIF      ' %WIN32_WINNT >= &H0501

#IF %WIN32_WINNT >= &H0600
%PBS_SMOOTHREVERSE = &H10
#ENDIF       ' %WIN32_WINNT >= &H0600

#IF %WIN32_WINNT >= &H0600

%PBM_GETSTEP     = (%WM_USER+13)
%PBM_GETBKCOLOR  = (%WM_USER+14)
%PBM_GETBARCOLOR = (%WM_USER+15)
%PBM_SETSTATE    = (%WM_USER+16) ' wParam = PBST_[STATE](NORMAL, ERROR, PAUSED)
%PBM_GETSTATE    = (%WM_USER+17)

%PBST_NORMAL     = &H0001
%PBST_ERROR      = &H0002
%PBST_PAUSED     = &H0003
#ENDIF      ' %WIN32_WINNT >= &H0600

#ENDIF  ' %NOPROGRESS



'==============================================================================
' HOTKEY CONTROL

#IF NOT %DEF(%NOHOTKEY)

%HOTKEYF_SHIFT   = &H01
%HOTKEYF_CONTROL = &H02
%HOTKEYF_ALT     = &H04
#IF %DEF(%MAC)
%HOTKEYF_EXT     = &H80?
#ELSE
%HOTKEYF_EXT     = &H08
#ENDIF

%HKCOMB_NONE     = &H0001
%HKCOMB_S        = &H0002
%HKCOMB_C        = &H0004
%HKCOMB_A        = &H0008
%HKCOMB_SC       = &H0010
%HKCOMB_SA       = &H0020
%HKCOMB_CA       = &H0040
%HKCOMB_SCA      = &H0080

%HKM_SETHOTKEY   = %WM_USER + 1
%HKM_GETHOTKEY   = %WM_USER + 2
%HKM_SETRULES    = %WM_USER + 3

#IF %DEF(%WIN32)

$HOTKEY_CLASSA     = "msctls_hotkey32"
$$HOTKEY_CLASSW    = "msctls_hotkey32"$$

#IF %DEF(%UNICODE)
MACRO HOTKEY_CLASS = $$HOTKEY_CLASSW
#ELSE
MACRO HOTKEY_CLASS = $HOTKEY_CLASSA
#ENDIF

#ELSE
MACRO HOTKEY_CLASS = "msctls_hotkey"
#ENDIF

#ENDIF  ' %NOHOTKEY



'==============================================================================
' COMMON CONTROL STYLES

%CCS_TOP           = &H00000001&
%CCS_NOMOVEY       = &H00000002&
%CCS_BOTTOM        = &H00000003&
%CCS_NORESIZE      = &H00000004&
%CCS_NOPARENTALIGN = &H00000008&
%CCS_ADJUSTABLE    = &H00000020&
%CCS_NODIVIDER     = &H00000040&
#IF (%WIN32_IE >= &H0300)
%CCS_VERT          = &H00000080&
%CCS_LEFT          = %CCS_VERT OR %CCS_TOP
%CCS_RIGHT         = %CCS_VERT OR %CCS_BOTTOM
%CCS_NOMOVEX       = %CCS_VERT OR %CCS_NOMOVEY
#ENDIF



' ====== SysLink control =============================================

#IF %DEF(%WIN32)
#IF NOT %DEF(%NOSYSLINK) OR (NOT %DEF(%NOLISTVIEW))

%INVALID_LINK_INDEX = -1
%MAX_LINKID_TEXT    = 48
%L_MAX_URL_LENGTH   = 2048 + 32 + 2

$$WC_LINK = "SysLink"$$

%LWS_TRANSPARENT    = &H0001
%LWS_IGNORERETURN   = &H0002
#IF %WIN32_WINNT >= &H0600
%LWS_NOPREFIX       = &H0004
%LWS_USEVISUALSTYLE = &H0008
%LWS_USECUSTOMTEXT  = &H0010
%LWS_RIGHT          = &H0020
#ENDIF  ' %WIN32_WINNT >= &H600

%LIF_ITEMINDEX     = &H00000001
%LIF_STATE         = &H00000002
%LIF_ITEMID        = &H00000004
%LIF_URL           = &H00000008

%LIS_FOCUSED       = &H00000001
%LIS_ENABLED       = &H00000002
%LIS_VISITED       = &H00000004
#IF %WIN32_WINNT >= &H0600
%LIS_HOTTRACK      = &H00000008
%LIS_DEFAULTCOLORS = &H00000010 ' Don't use any custom text colors
#ENDIF

TYPE LITEM
    mask      AS DWORD
    iLink     AS LONG
    STATE     AS DWORD
    stateMask AS DWORD
    szID      AS WSTRINGZ * %MAX_LINKID_TEXT
    szUrl     AS WSTRINGZ * %L_MAX_URL_LENGTH
END TYPE

TYPE LHITTESTINFO
    pt   AS POINT
    ITEM AS LITEM
END TYPE

TYPE NMLINK
    hdr  AS NMHDR
    ITEM AS LITEM
END TYPE

' SysLink notifications
' NM_CLICK   ' wParam: control ID, lParam: PNMLINK, ret: ignored.

' LinkWindow messages
%LM_HITTEST        = %WM_USER + &H300  ' wParam: n/a, lparam: PLHITTESTINFO, ret: BOOL
%LM_GETIDEALHEIGHT = %WM_USER + &H301  ' wParam: n/a, lparam: n/a, ret: cy
%LM_SETITEM        = %WM_USER + &H302  ' wParam: n/a, lparam: LITEM*, ret: BOOL
%LM_GETITEM        = %WM_USER + &H303  ' wParam: n/a, lparam: LITEM*, ret: BOOL
%LM_GETIDEALSIZE   = %LM_GETIDEALHEIGHT  ' wParam: cxMaxWidth, lparam: SIZEL ptr, ret: cy

#ENDIF  ' #IF NOT %DEF(%NOSYSLINK) OR (NOT %DEF(%NOLISTVIEW))

#ENDIF  ' %WIN32


'==============================================================================
' LISTVIEW CONTROL

#IF NOT %DEF(%NOLISTVIEW)

#IF %DEF(%WIN32)

$WC_LISTVIEWA  = "SysListView32"
$$WC_LISTVIEWW = "SysListView32"$$

#IF %DEF(%UNICODE)
MACRO WC_LISTVIEW = $$WC_LISTVIEWW
#ELSE
MACRO WC_LISTVIEW = $WC_LISTVIEWA
#ENDIF

#ELSE
MACRO WC_LISTVIEW = "SysListView"
#ENDIF  ' #IF %DEF(%WIN32)

%LVS_ICON            = &H00000000
%LVS_REPORT          = &H00000001
%LVS_SMALLICON       = &H00000002
%LVS_LIST            = &H00000003
%LVS_TYPEMASK        = &H00000003
%LVS_SINGLESEL       = &H00000004
%LVS_SHOWSELALWAYS   = &H00000008
%LVS_SORTASCENDING   = &H00000010
%LVS_SORTDESCENDING  = &H00000020
%LVS_SHAREIMAGELISTS = &H00000040
%LVS_NOLABELWRAP     = &H00000080
%LVS_AUTOARRANGE     = &H00000100
%LVS_EDITLABELS      = &H00000200
#IF (%WIN32_IE >= &H0300)
%LVS_OWNERDATA       = &H00001000
#ENDIF
%LVS_NOSCROLL        = &H00002000

%LVS_TYPESTYLEMASK   = &H0000FC00

%LVS_ALIGNTOP        = &H00000000
%LVS_ALIGNLEFT       = &H00000800
%LVS_ALIGNMASK       = &H00000C00

%LVS_OWNERDRAWFIXED  = &H00000400
%LVS_NOCOLUMNHEADER  = &H00004000
%LVS_NOSORTHEADER    = &H00008000

#IF (%WIN32_IE >= &H0400)
%LVM_SETUNICODEFORMAT   = %CCM_SETUNICODEFORMAT
FUNCTION ListView_SetUnicodeFormat (BYVAL hwnd AS DWORD, _
    BYVAL fUnicode AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_SETUNICODEFORMAT, fUnicode, 0)
END FUNCTION

%LVM_GETUNICODEFORMAT   = %CCM_GETUNICODEFORMAT
FUNCTION ListView_GetUnicodeFormat (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_GETUNICODEFORMAT, 0, 0)
END FUNCTION
#ENDIF

%LVM_GETBKCOLOR         = %LVM_FIRST + 0
FUNCTION ListView_GetBkColor (BYVAL hWnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hWnd, %LVM_GETBKCOLOR, 0, 0)
END FUNCTION

%LVM_SETBKCOLOR         = %LVM_FIRST + 1
FUNCTION ListView_SetBkColor (BYVAL hWnd AS DWORD, BYVAL clrBk AS DWORD) AS LONG
    FUNCTION = SendMessage(hWnd, %LVM_SETBKCOLOR, 0, clrBk)
END FUNCTION

%LVM_GETIMAGELIST       = %LVM_FIRST + 2
FUNCTION ListView_GetImageList (BYVAL hWnd AS DWORD, _
    BYVAL iImageList AS LONG) AS DWORD
    FUNCTION = SendMessage(hWnd, %LVM_GETIMAGELIST, iImageList, 0)
END FUNCTION

%LVSIL_NORMAL           = 0
%LVSIL_SMALL            = 1
%LVSIL_STATE            = 2
%LVSIL_GROUPHEADER      = 3

%LVM_SETIMAGELIST       = %LVM_FIRST + 3
FUNCTION ListView_SetImageList (BYVAL hWnd AS DWORD, BYVAL himl AS DWORD, _
    BYVAL iImageList AS LONG) AS DWORD
    FUNCTION = SendMessage(hWnd, %LVM_SETIMAGELIST, iImageList, himl)
END FUNCTION

%LVM_GETITEMCOUNT       = %LVM_FIRST + 4
FUNCTION ListView_GetItemCount (BYVAL hWnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hWnd, %LVM_GETITEMCOUNT, 0, 0)
END FUNCTION

%LVIF_TEXT              = &H0001
%LVIF_IMAGE             = &H0002
%LVIF_PARAM             = &H0004
%LVIF_STATE             = &H0008
#IF (%WIN32_IE >= &H0300)
%LVIF_INDENT            = &H0010
%LVIF_NORECOMPUTE       = &H0800
#ENDIF
#IF (%WIN32_WINNT >= &H0501)
%LVIF_GROUPID           = &H0100
%LVIF_COLUMNS           = &H0200
#ENDIF

#IF %WIN32_WINNT >= &H0600
%LVIF_COLFMT            = &H00010000 ' The piColFmt member is valid in addition to puColumns
#ENDIF

%LVIS_FOCUSED           = &H0001
%LVIS_SELECTED          = &H0002
%LVIS_CUT               = &H0004
%LVIS_DROPHILITED       = &H0008
%LVIS_GLOW              = &H0010
%LVIS_ACTIVATING        = &H0020

%LVIS_OVERLAYMASK       = &H00F00
%LVIS_STATEIMAGEMASK    = &H0F000

#IF NOT %DEF(%ITSIM)
%ITSIM = 1
MACRO IndexToStateImageMask(i)=((i)*4096)
#ENDIF

#IF (%WIN32_WINNT >= &H0501)
%I_GROUPIDCALLBACK  = (-1)
%I_GROUPIDNONE      = (-2)
#ENDIF

%LVITEMA_V1_SIZE = 9 * 4 ' CCSIZEOF_STRUCT(LVITEMA, lParam)
%LVITEMW_V1_SIZE = 9 * 4 ' CCSIZEOF_STRUCT(LVITEMW, lParam)

#IF %WIN32_WINNT >= &H0600 ' Will be unused downlevel, but sizeof(LVITEMA) must be equal to sizeof(LVITEMW)
%LVITEMA_V5_SIZE = 9 * 4 + 4 * 4 ' CCSIZEOF_STRUCT(LVITEMA, puColumns)
%LVITEMW_V5_SIZE = 9 * 4 + 4 * 4 ' CCSIZEOF_STRUCT(LVITEMW, puColumns)

#IF %DEF(%UNICODE)
%LVITEM_V5_SIZE = %LVITEMW_V5_SIZE
#ELSE
%LVITEM_V5_SIZE = %LVITEMA_V5_SIZE
#ENDIF
#ENDIF  ' #IF %WIN32_WINNT >= &H0600

TYPE LVITEMA
    mask       AS DWORD
    iItem      AS LONG
    iSubItem   AS LONG
    STATE      AS DWORD
    stateMask  AS DWORD
    pszText    AS ASCIIZ PTR
    cchTextMax AS LONG
    iImage     AS LONG
    lParam     AS LONG
#IF (%WIN32_IE >= &H0300)
    iIndent    AS LONG
#ENDIF
#IF (%WIN32_WINNT >= &H0501)
    iGroupId   AS LONG
    cColumns   AS DWORD        ' tile view columns
    puColumns  AS DWORD PTR
#ENDIF
#IF %WIN32_WINNT >= &H0600 ' Will be unused downlevel, but sizeof(LVITEMA) must be equal to sizeof(LVITEMW)
    piColFmt   AS LONG PTR
    iGroup     AS LONG ' readonly. only valid for owner data.
#ENDIF
END TYPE

TYPE LVITEMW
    mask       AS DWORD
    iItem      AS LONG
    iSubItem   AS LONG
    STATE      AS DWORD
    stateMask  AS DWORD
    pszText    AS WSTRINGZ PTR
    cchTextMax AS LONG
    iImage     AS LONG
    lParam     AS LONG
#IF (%WIN32_IE >= &H0300)
    iIndent    AS LONG
#ENDIF
#IF (%WIN32_WINNT >= &H0501)
    iGroupId   AS LONG
    cColumns   AS DWORD        ' tile view columns
    puColumns  AS DWORD PTR
#ENDIF
#IF %WIN32_WINNT >= &H0600 ' Will be unused downlevel, but sizeof(LVITEMA) must be equal to sizeof(LVITEMW)
    piColFmt   AS LONG PTR
    iGroup     AS LONG ' readonly. only valid for owner data.
#ENDIF
END TYPE

#IF (%WIN32_IE >= &H0300)
%I_INDENTCALLBACK = (-1)
TYPE LV_ITEMA
    LVITEMA
END TYPE
TYPE LV_ITEMW
    LVITEMW
END TYPE
#ELSE
TYPE LVITEMA
    LV_ITEMA
END TYPE
TYPE LVITEMW
    LV_ITEMW
END TYPE
#ENDIF

#IF %DEF(%UNICODE)
TYPE LVITEM
    LVITEMW
END TYPE
%LVITEM_V1_SIZE = %LVITEMW_V1_SIZE
#ELSE
TYPE LVITEM
    LVITEMA
END TYPE
%LVITEM_V1_SIZE = %LVITEMA_V1_SIZE
#ENDIF

TYPE LV_ITEM
    LVITEM
END TYPE

%LPSTR_TEXTCALLBACKW = -1  '((LPWSTR)-1L)
%LPSTR_TEXTCALLBACKA = -1  '((LPSTR)-1L)
#IF %DEF(%UNICODE)
%LPSTR_TEXTCALLBACK = %LPSTR_TEXTCALLBACKW
#ELSE
%LPSTR_TEXTCALLBACK = %LPSTR_TEXTCALLBACKA
#ENDIF

%I_IMAGECALLBACK       = (-1)
#IF (%WIN32_IE >= &H0501)
%I_IMAGENONE           = (-2)
#ENDIF  ' &H0501

#IF (%WIN32_WINNT >= &H0501)
' For tileview
%I_COLUMNSCALLBACK     = &HFFFFFFFF???  '((UINT)-1)
#ENDIF

%LVM_GETITEMA           = %LVM_FIRST + 5
%LVM_GETITEMW           = %LVM_FIRST + 75
#IF %DEF(%UNICODE)
%LVM_GETITEM = %LVM_GETITEMW
#ELSE
%LVM_GETITEM = %LVM_GETITEMA
#ENDIF

FUNCTION ListView_GetItem (BYVAL hWnd AS DWORD, pitem AS LV_ITEM) AS LONG
    FUNCTION = SendMessage(hWnd, %LVM_GETITEM, 0, VARPTR(pitem))
END FUNCTION

%LVM_SETITEMA           = %LVM_FIRST + 6
%LVM_SETITEMW           = %LVM_FIRST + 76
#IF %DEF(%UNICODE)
%LVM_SETITEM = %LVM_SETITEMW
#ELSE
%LVM_SETITEM = %LVM_SETITEMA
#ENDIF

FUNCTION ListView_SetItem (BYVAL hWnd AS DWORD, pitem AS LV_ITEM) AS LONG
    FUNCTION = SendMessage(hWnd, %LVM_SETITEM, 0, VARPTR(pitem))
END FUNCTION

%LVM_INSERTITEMA        = %LVM_FIRST + 7
%LVM_INSERTITEMW        = %LVM_FIRST + 77
#IF %DEF(%UNICODE)
%LVM_INSERTITEM = %LVM_INSERTITEMW
#ELSE
%LVM_INSERTITEM = %LVM_INSERTITEMA
#ENDIF

FUNCTION ListView_InsertItem (BYVAL hWnd AS DWORD, pitem AS LV_ITEM) AS LONG
    FUNCTION = SendMessage(hWnd, %LVM_INSERTITEM, 0, VARPTR(pitem))
END FUNCTION

%LVM_DELETEITEM         = %LVM_FIRST + 8
FUNCTION ListView_DeleteItem (BYVAL hWnd AS DWORD, BYVAL i AS LONG) AS LONG
    FUNCTION = SendMessage(hWnd, %LVM_DELETEITEM, i, 0)
END FUNCTION

%LVM_DELETEALLITEMS     = %LVM_FIRST + 9
FUNCTION ListView_DeleteAllItems (BYVAL hWnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hWnd, %LVM_DELETEALLITEMS, 0, 0)
END FUNCTION

%LVM_GETCALLBACKMASK    = %LVM_FIRST + 10
FUNCTION ListView_GetCallbackMask (BYVAL hWnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hWnd, %LVM_GETCALLBACKMASK, 0, 0)
END FUNCTION

%LVM_SETCALLBACKMASK    = %LVM_FIRST + 11
FUNCTION ListView_SetCallbackMask (BYVAL hWnd AS DWORD, BYVAL mask AS DWORD) _
    AS LONG
    FUNCTION = SendMessage(hWnd, %LVM_SETCALLBACKMASK, mask, 0)
END FUNCTION

%LVNI_ALL               = &H0000
%LVNI_FOCUSED           = &H0001
%LVNI_SELECTED          = &H0002
%LVNI_CUT               = &H0004
%LVNI_DROPHILITED       = &H0008

%LVNI_ABOVE             = &H0100
%LVNI_BELOW             = &H0200
%LVNI_TOLEFT            = &H0400
%LVNI_TORIGHT           = &H0800

%LVM_GETNEXTITEM        = %LVM_FIRST + 12
FUNCTION ListView_GetNextItem (BYVAL hWnd AS DWORD, BYVAL i AS LONG, _
    BYVAL flags AS LONG) AS LONG
    FUNCTION = SendMessage(hWnd, %LVM_GETNEXTITEM, i, MAKLNG(flags, 0))
END FUNCTION

%LVFI_PARAM             = &H0001
%LVFI_STRING            = &H0002
%LVFI_SUBSTRING         = &H0004  ' Same as LVFI_PARTIAL
%LVFI_PARTIAL           = &H0008
%LVFI_WRAP              = &H0020
%LVFI_NEARESTXY         = &H0040

TYPE LVFINDINFOA
    flags       AS DWORD
    psz         AS ASCIIZ PTR
    lParam      AS LONG
    pt          AS POINT
    vkDirection AS DWORD
END TYPE

TYPE LVFINDINFOW
    flags       AS DWORD
    psz         AS WSTRINGZ PTR
    lParam      AS LONG
    pt          AS POINT
    vkDirection AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE LVFINDINFO
    LVFINDINFOW
END TYPE
#ELSE
TYPE LVFINDINFO
    LVFINDINFOA
END TYPE
#ENDIF

#IF (%WIN32_IE >= &H0300)
TYPE LV_FINDINFOA
    LVFINDINFOA
END TYPE
TYPE LV_FINDINFOW
    LVFINDINFOW
END TYPE
#ELSE
TYPE LVFINDINFOA
    LV_FINDINFOA
END TYPE
TYPE LVFINDINFOW
    LV_FINDINFOW
END TYPE
#ENDIF

TYPE LV_FINDINFO
    LVFINDINFO
END TYPE

%LVM_FINDITEMA          = %LVM_FIRST + 13
%LVM_FINDITEMW          = %LVM_FIRST + 83
#IF %DEF(%UNICODE)
%LVM_FINDITEM = %LVM_FINDITEMW
#ELSE
%LVM_FINDITEM = %LVM_FINDITEMA
#ENDIF

FUNCTION ListView_FindItem (BYVAL hWnd AS DWORD, BYVAL iStart AS LONG, _
    plvfi AS LV_FINDINFO) AS LONG
    FUNCTION = SendMessage(hWnd, %LVM_FINDITEM, iStart, VARPTR(plvfi))
END FUNCTION

%LVIR_BOUNDS            = 0
%LVIR_ICON              = 1
%LVIR_LABEL             = 2
%LVIR_SELECTBOUNDS      = 3

%LVM_GETITEMRECT        = %LVM_FIRST + 14

FUNCTION ListView_GetItemRect (BYVAL hWnd AS DWORD, BYVAL i AS LONG, _
    prc AS RECT, BYVAL nCode AS LONG) AS LONG
    prc.nLeft = nCode
    FUNCTION = SendMessage(hWnd, %LVM_GETITEMRECT, i, VARPTR(prc))
END FUNCTION

%LVM_SETITEMPOSITION    = %LVM_FIRST + 15

FUNCTION ListView_SetItemPosition (BYVAL hWndLV AS DWORD, BYVAL i AS LONG, _
    BYVAL x AS INTEGER, BYVAL y AS INTEGER) AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_SETITEMPOSITION, i, MAKLNG(x, y))
END FUNCTION

%LVM_GETITEMPOSITION    = %LVM_FIRST + 16

FUNCTION ListView_GetItemPosition (BYVAL hWndLV AS DWORD, BYVAL i AS LONG, _
    pt AS POINT) AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_GETITEMPOSITION, i, VARPTR(pt))
END FUNCTION

%LVM_GETSTRINGWIDTHA    = %LVM_FIRST + 17
%LVM_GETSTRINGWIDTHW    = %LVM_FIRST + 87
#IF %DEF(%UNICODE)
%LVM_GETSTRINGWIDTH = %LVM_GETSTRINGWIDTHW
#ELSE
%LVM_GETSTRINGWIDTH = %LVM_GETSTRINGWIDTHA
#ENDIF

FUNCTION ListView_GetStringWidthA (BYVAL hWndLV AS DWORD, psz AS ASCIIZ) AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_GETSTRINGWIDTHA, 0, VARPTR(psz))
END FUNCTION

FUNCTION ListView_GetStringWidthW (BYVAL hWndLV AS DWORD, psz AS WSTRINGZ) AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_GETSTRINGWIDTHA, 0, VARPTR(psz))
END FUNCTION

#IF %DEF(%UNICODE)
FUNCTION ListView_GetStringWidth (BYVAL hWndLV AS DWORD, psz AS WSTRINGZ) AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_GETSTRINGWIDTHA, 0, VARPTR(psz))
END FUNCTION
#ELSE
FUNCTION ListView_GetStringWidth (BYVAL hWndLV AS DWORD, psz AS ASCIIZ) AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_GETSTRINGWIDTHA, 0, VARPTR(psz))
END FUNCTION
#ENDIF

%LVHT_NOWHERE           = &H00000001
%LVHT_ONITEMICON        = &H00000002
%LVHT_ONITEMLABEL       = &H00000004
%LVHT_ONITEMSTATEICON   = &H00000008
%LVHT_ONITEM            = (%LVHT_ONITEMICON OR %LVHT_ONITEMLABEL OR %LVHT_ONITEMSTATEICON)

%LVHT_ABOVE             = &H00000008
%LVHT_BELOW             = &H00000010
%LVHT_TORIGHT           = &H00000020
%LVHT_TOLEFT            = &H00000040

%LVHT_EX_GROUP_HEADER     = &H10000000
%LVHT_EX_GROUP_FOOTER     = &H20000000
%LVHT_EX_GROUP_COLLAPSE   = &H40000000
%LVHT_EX_GROUP_BACKGROUND = &H80000000???
%LVHT_EX_GROUP_STATEICON  = &H01000000
%LVHT_EX_GROUP_SUBSETLINK = &H02000000
%LVHT_EX_GROUP            = (%LVHT_EX_GROUP_BACKGROUND OR %LVHT_EX_GROUP_COLLAPSE _
                          OR %LVHT_EX_GROUP_FOOTER OR %LVHT_EX_GROUP_HEADER _
                          OR %LVHT_EX_GROUP_STATEICON OR %LVHT_EX_GROUP_SUBSETLINK)
%LVHT_EX_ONCONTENTS       = &H04000000 ' On item AND not on the background
%LVHT_EX_FOOTER           = &H08000000

%LVHITTESTINFO_V1_SIZE = 4 + 2 * 4 ' CCSIZEOF_STRUCT(LVHITTESTINFO, iItem)

TYPE LVHITTESTINFO
    pt       AS POINT
    flags    AS DWORD
    iItem    AS LONG
#IF (%WIN32_IE >= &H0300)
    iSubItem AS LONG    ' this is was NOT in win95.  valid only for LVM_SUBITEMHITTEST
#ENDIF
#IF %WIN32_WINNT >= &H0600
    iGroup   AS LONG ' readonly. index of group. only valid for owner data.
                     ' supports single item in multiple groups.
#ENDIF
END TYPE

#IF (%WIN32_IE >= &H0300)
TYPE LV_HITTESTINFO
    LVHITTESTINFO
END TYPE
#ELSE
TYPE LVHITTESTINFO
    LV_HITTESTINFO
END TYPE
#ENDIF

%LVM_HITTEST            = %LVM_FIRST + 18
FUNCTION ListView_HitTest (BYVAL hWndLV AS DWORD, pinfo AS LV_HITTESTINFO) _
    AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_HITTEST, 0, VARPTR(pinfo))
END FUNCTION

FUNCTION ListView_HitTestEx (BYVAL hWndLV AS DWORD, pinfo AS LV_HITTESTINFO) _
    AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_HITTEST, -1, VARPTR(pinfo))
END FUNCTION

%LVM_ENSUREVISIBLE      = %LVM_FIRST + 19
FUNCTION ListView_EnsureVisible (BYVAL hWndLV AS DWORD, BYVAL i AS LONG, _
    BYVAL fPartialOK AS INTEGER) AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_ENSUREVISIBLE, i, MAKLNG(fPartialOK, 0))
END FUNCTION

%LVM_SCROLL             = %LVM_FIRST + 20
FUNCTION ListView_Scroll (BYVAL hWndLV AS DWORD, dx AS LONG, _
    BYVAL dy AS LONG) AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_SCROLL, dx, dy)
END FUNCTION

%LVM_REDRAWITEMS        = %LVM_FIRST + 21
FUNCTION ListView_RedrawItems (BYVAL hWndLV AS DWORD, BYVAL iFirst AS LONG, _
    BYVAL iLast AS LONG) AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_REDRAWITEMS, iFirst, iLast)
END FUNCTION

%LVA_DEFAULT            = &H0000
%LVA_ALIGNLEFT          = &H0001
%LVA_ALIGNTOP           = &H0002
%LVA_SNAPTOGRID         = &H0005

%LVM_ARRANGE            = %LVM_FIRST + 22
FUNCTION ListView_Arrange (BYVAL hWndLV AS DWORD, BYVAL CODE AS LONG) AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_ARRANGE, CODE, 0)
END FUNCTION

%LVM_EDITLABELA         = %LVM_FIRST + 23
%LVM_EDITLABELW         = %LVM_FIRST + 118
#IF %DEF(%UNICODE)
%LVM_EDITLABEL = %LVM_EDITLABELW
#ELSE
%LVM_EDITLABEL = %LVM_EDITLABELA
#ENDIF

FUNCTION ListView_EditLabel (BYVAL hWndLV AS DWORD, BYVAL i AS LONG) AS DWORD
    FUNCTION = SendMessage(hWndLV, %LVM_EDITLABEL, i, 0)
END FUNCTION

%LVM_GETEDITCONTROL     = %LVM_FIRST + 24
MACRO ListView_GetEditControl(hWndLV)=SendMessage(hWndLV, %LVM_GETEDITCONTROL, 0, 0)

%LVCOLUMNA_V1_SIZE = 6 * 4 ' CCSIZEOF_STRUCT(LVCOLUMNA, iSubItem)
%LVCOLUMNW_V1_SIZE = 6 * 4 ' CCSIZEOF_STRUCT(LVCOLUMNW, iSubItem)

TYPE LVCOLUMNA
    mask       AS DWORD
    fmt        AS LONG
    cx         AS LONG
    pszText    AS ASCIIZ PTR
    cchTextMax AS LONG
    iSubItem   AS LONG
#IF (%WIN32_IE >= &H0300)
    iImage     AS LONG
    iOrder     AS LONG
#ENDIF
#IF %WIN32_WINNT >= &H0600
    cxMin      AS LONG   ' min snap point
    cxDefault  AS LONG   ' default snap point
    cxIdeal    AS LONG   ' read only. ideal may not equal current width if auto sized
                         '(%LVS_EX_AUTOSIZECOLUMNS) to a lesser width.
#ENDIF
END TYPE

TYPE LVCOLUMNW
    mask       AS DWORD
    fmt        AS LONG
    cx         AS LONG
    pszText    AS WSTRINGZ PTR
    cchTextMax AS LONG
    iSubItem   AS LONG
#IF (%WIN32_IE >= &H0300)
    iImage     AS LONG
    iOrder     AS LONG
#ENDIF
#IF %WIN32_WINNT >= &H0600
    cxMin      AS LONG   ' min snap point
    cxDefault  AS LONG   ' default snap point
    cxIdeal    AS LONG   ' read only. ideal may not equal current width if auto sized
                         '(%LVS_EX_AUTOSIZECOLUMNS) to a lesser width.
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
TYPE LVCOLUMN
    LVCOLUMNW
END TYPE
%LVCOLUMN_V1_SIZE = %LVCOLUMNW_V1_SIZE
#ELSE
TYPE LVCOLUMN
    LVCOLUMNA
END TYPE
%LVCOLUMN_V1_SIZE = %LVCOLUMNA_V1_SIZE
#ENDIF

#IF (%WIN32_IE >= &H0300)
TYPE LV_COLUMNA
    LVCOLUMNA
END TYPE
TYPE LV_COLUMNW
    LVCOLUMNW
END TYPE
#ELSE
TYPE LVCOLUMNA
    LV_COLUMNA
END TYPE
TYPE LVCOLUMNW
    LV_COLUMNW
END TYPE
#ENDIF

TYPE LV_COLUMN
    LVCOLUMN
END TYPE

%LVCF_FMT               = &H0001
%LVCF_WIDTH             = &H0002
%LVCF_TEXT              = &H0004
%LVCF_SUBITEM           = &H0008
#IF (%WIN32_IE >= &H0300)
%LVCF_IMAGE             = &H0010
%LVCF_ORDER             = &H0020
#ENDIF
#IF %WIN32_WINNT >= &H0600
%LVCF_MINWIDTH          = &H0040
%LVCF_DEFAULTWIDTH      = &H0080
%LVCF_IDEALWIDTH        = &H0100
#ENDIF

' LVCFMT_ flags up to FFFF are shared with the header control(HDF_ flags).
' Flags above FFFF are listview-specific.

%LVCFMT_LEFT               = &H0000 ' Same as HDF_LEFT
%LVCFMT_RIGHT              = &H0001 ' Same as HDF_RIGHT
%LVCFMT_CENTER             = &H0002 ' Same as HDF_CENTER
%LVCFMT_JUSTIFYMASK        = &H0003 ' Same as HDF_JUSTIFYMASK

#IF (%WIN32_IE >= &H0300)
%LVCFMT_IMAGE              = &H0800 ' Same as HDF_IMAGE
%LVCFMT_BITMAP_ON_RIGHT    = &H1000 ' Same as HDF_BITMAP_ON_RIGHT
%LVCFMT_COL_HAS_IMAGES     = &H8000?? ' Same as HDF_OWNERDRAW
#ENDIF

#IF %WIN32_WINNT >= &H0600
%LVCFMT_FIXED_WIDTH        = &H00100  ' Can't resize the column; same as HDF_FIXEDWIDTH
%LVCFMT_NO_DPI_SCALE       = &H40000  ' If not set, CCM_DPISCALE will govern scaling up fixed width
%LVCFMT_FIXED_RATIO        = &H80000  ' Width will augment with the row height

' The following flags
%LVCFMT_LINE_BREAK         = &H100000 ' Move to the top of the next list of columns
%LVCFMT_FILL               = &H200000 ' Fill the remainder of the tile area. Might have a title.
%LVCFMT_WRAP               = &H400000 ' This sub-item can be wrapped.
%LVCFMT_NO_TITLE           = &H800000 ' This sub-item doesn't have an title.
%LVCFMT_TILE_PLACEMENTMASK = (%LVCFMT_LINE_BREAK OR %LVCFMT_FILL)

%LVCFMT_SPLITBUTTON        = &H1000000 ' Column is a split button; same as HDF_SPLITBUTTON
#ENDIF

%LVM_GETCOLUMNA         = %LVM_FIRST + 25
%LVM_GETCOLUMNW         = %LVM_FIRST + 95
#IF %DEF(%UNICODE)
%LVM_GETCOLUMN = %LVM_GETCOLUMNW
#ELSE
%LVM_GETCOLUMN = %LVM_GETCOLUMNA
#ENDIF

FUNCTION ListView_GetColumn (BYVAL hWnd AS DWORD, BYVAL iCol AS LONG, _
    pcol AS LV_COLUMN) AS LONG
    FUNCTION = SendMessage(hWnd, %LVM_GETCOLUMN, iCol, VARPTR(pcol))
END FUNCTION

%LVM_SETCOLUMNA         = %LVM_FIRST + 26
%LVM_SETCOLUMNW         = %LVM_FIRST + 96
#IF %DEF(%UNICODE)
%LVM_SETCOLUMN = %LVM_SETCOLUMNW
#ELSE
%LVM_SETCOLUMN = %LVM_SETCOLUMNA
#ENDIF

FUNCTION ListView_SetColumn (BYVAL hWnd AS DWORD, BYVAL iCol AS LONG, _
    pcol AS LV_COLUMN) AS LONG
    FUNCTION = SendMessage(hWnd, %LVM_SETCOLUMN, iCol, VARPTR(pcol))
END FUNCTION

%LVM_INSERTCOLUMNA      = %LVM_FIRST + 27
%LVM_INSERTCOLUMNW      = %LVM_FIRST + 97
#IF %DEF(%UNICODE)
%LVM_INSERTCOLUMN = %LVM_INSERTCOLUMNW
#ELSE
%LVM_INSERTCOLUMN = %LVM_INSERTCOLUMNA
#ENDIF

FUNCTION ListView_InsertColumn (BYVAL hWnd AS DWORD, BYVAL iCol AS LONG, _
    pcol AS LV_COLUMN) AS LONG
    FUNCTION = SendMessage(hWnd, %LVM_INSERTCOLUMN, iCol, VARPTR(pcol))
END FUNCTION

%LVM_DELETECOLUMN       = %LVM_FIRST + 28
FUNCTION ListView_DeleteColumn (BYVAL hWnd AS DWORD, BYVAL iCol AS LONG) AS LONG
    FUNCTION = SendMessage(hWnd, %LVM_DELETECOLUMN, iCol, 0)
END FUNCTION

%LVM_GETCOLUMNWIDTH     = %LVM_FIRST + 29
FUNCTION ListView_GetColumnWidth (BYVAL hWnd AS DWORD, iCol AS LONG) AS LONG
    FUNCTION = SendMessage(hWnd, %LVM_GETCOLUMNWIDTH, iCol, 0)
END FUNCTION

%LVSCW_AUTOSIZE             = -1
%LVSCW_AUTOSIZE_USEHEADER   = -2
%LVM_SETCOLUMNWIDTH         = %LVM_FIRST + 30

FUNCTION ListView_SetColumnWidth (BYVAL hWnd AS DWORD, BYVAL iCol AS LONG, _
    BYVAL cx AS INTEGER) AS LONG
    FUNCTION = SendMessage(hWnd, %LVM_SETCOLUMNWIDTH, iCol, MAKLNG(cx, 0))
END FUNCTION

#IF (%WIN32_IE >= &H0300)
%LVM_GETHEADER          = %LVM_FIRST + 31
FUNCTION ListView_GetHeader (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %LVM_GETHEADER, 0, 0)
END FUNCTION
#ENDIF

%LVM_CREATEDRAGIMAGE    = %LVM_FIRST + 33
FUNCTION ListView_CreateDragImage (BYVAL hWnd AS DWORD, BYVAL i AS LONG, _
    lpptUpLeft AS POINT) AS LONG
     FUNCTION = SendMessage(hWnd, %LVM_CREATEDRAGIMAGE, i, VARPTR(lpptUpLeft))
END FUNCTION

%LVM_GETVIEWRECT        = %LVM_FIRST + 34
FUNCTION ListView_GetViewRect (BYVAL hWnd AS DWORD, prc AS RECT) AS LONG
    FUNCTION = SendMessage(hWnd, %LVM_GETVIEWRECT, 0, VARPTR(prc))
END FUNCTION

%LVM_GETTEXTCOLOR       = %LVM_FIRST + 35
FUNCTION ListView_GetTextColor (BYVAL hWnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hWnd, %LVM_GETTEXTCOLOR, 0, 0)
END FUNCTION

%LVM_SETTEXTCOLOR       = %LVM_FIRST + 36
FUNCTION ListView_SetTextColor (BYVAL hWnd AS DWORD, BYVAL clrText AS LONG) _
    AS LONG
    FUNCTION = SendMessage(hWnd, %LVM_SETTEXTCOLOR, 0, clrText)
END FUNCTION

%LVM_GETTEXTBKCOLOR     = %LVM_FIRST + 37
FUNCTION ListView_GetTextBkColor (BYVAL hWnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hWnd, %LVM_GETTEXTBKCOLOR, 0, 0)
END FUNCTION

%LVM_SETTEXTBKCOLOR     = %LVM_FIRST + 38
FUNCTION ListView_SetTextBkColor (BYVAL hWnd AS DWORD, _
    BYVAL clrTextBk AS LONG) AS LONG
    FUNCTION = SendMessage(hWnd, %LVM_SETTEXTBKCOLOR, 0, clrTextBk)
END FUNCTION

%LVM_GETTOPINDEX        = %LVM_FIRST + 39
FUNCTION ListView_GetTopIndex (BYVAL hWndLV AS DWORD) AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_GETTOPINDEX, 0, 0)
END FUNCTION

%LVM_GETCOUNTPERPAGE    = %LVM_FIRST + 40
FUNCTION ListView_GetCountPerPage (BYVAL hWndLV AS DWORD) AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_GETCOUNTPERPAGE, 0, 0)
END FUNCTION

%LVM_GETORIGIN          = %LVM_FIRST + 41
FUNCTION ListView_GetOrigin (BYVAL hWndLV AS DWORD, pt AS POINT) AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_GETORIGIN, 0, VARPTR(pt))
END FUNCTION

%LVM_UPDATE             = %LVM_FIRST + 42
FUNCTION ListView_Update (BYVAL hWndLV AS DWORD, BYVAL i AS LONG) AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_UPDATE, i, 0)
END FUNCTION

%LVM_SETITEMSTATE       = %LVM_FIRST + 43

SUB ListView_SetItemState (BYVAL hWndLV AS DWORD, BYVAL i AS LONG, _
    BYVAL nData AS DWORD, BYVAL mask AS DWORD)
    LOCAL ms_lvi AS LV_ITEM
    ms_lvi.stateMask = mask
    ms_lvi.state = nData
    SendMessage hWndLV, %LVM_SETITEMSTATE, i, VARPTR(ms_lvi)
END SUB

#IF (%WIN32_IE >= &H0300)
SUB ListView_SetCheckState (BYVAL hWndLV AS DWORD, BYVAL i AS LONG, _
    BYVAL fCheck AS LONG)
    ListView_SetItemState hWndLV, i, _
        INDEXTOSTATEIMAGEMASK(1 - (ISTRUE fCheck)), %LVIS_STATEIMAGEMASK
END SUB
#ENDIF

%LVM_GETITEMSTATE       = %LVM_FIRST + 44

FUNCTION ListView_GetItemState (BYVAL hWndLV AS DWORD, BYVAL i AS LONG, _
    BYVAL mask AS LONG) AS DWORD
    FUNCTION = SendMessage(hWndLV, %LVM_GETITEMSTATE, i, mask)
END FUNCTION

#IF (%WIN32_IE >= &H0300)
FUNCTION ListView_GetCheckState (BYVAL hwndLV AS DWORD, BYVAL i AS LONG) AS DWORD
    LOCAL nCheck AS LONG
    nCheck = SendMessage(hwndLV, %LVM_GETITEMSTATE, i, %LVIS_STATEIMAGEMASK)
    FUNCTION = BIT(nCheck, 12) - 1
END FUNCTION
#ENDIF

%LVM_GETITEMTEXTA       = (%LVM_FIRST + 45)
%LVM_GETITEMTEXTW       = (%LVM_FIRST + 115)

#IF %DEF(%UNICODE)
%LVM_GETITEMTEXT = %LVM_GETITEMTEXTW
#ELSE
%LVM_GETITEMTEXT = %LVM_GETITEMTEXTA
#ENDIF

SUB ListView_GetItemText(BYVAL hWndLV AS DWORD, BYVAL i AS LONG, _
    BYVAL iSubItem AS LONG, pszText AS ASCIIZ, BYVAL cchTextMax AS LONG)
    LOCAL ms_lvi AS LV_ITEM
    ms_lvi.iSubItem = iSubItem
    ms_lvi.cchTextMax = cchTextMax
    ms_lvi.pszText = VARPTR(pszText)
    SendMessage hWndLV, %LVM_GETITEMTEXT, i, VARPTR(ms_lvi)
END SUB

%LVM_SETITEMTEXTA       = %LVM_FIRST + 46
%LVM_SETITEMTEXTW       = %LVM_FIRST + 116

#IF %DEF(%UNICODE)
%LVM_SETITEMTEXT = %LVM_SETITEMTEXTW
#ELSE
%LVM_SETITEMTEXT = %LVM_SETITEMTEXTA
#ENDIF

SUB ListView_SetItemText(BYVAL hWndLV AS DWORD, BYVAL i AS LONG, _
    BYVAL iSubItem AS LONG, pszText AS ASCIIZ)
    LOCAL ms_lvi AS LV_ITEM
    ms_lvi.iSubItem = iSubItem
    ms_lvi.pszText = VARPTR(pszText)
    SendMessage hWndLV, %LVM_SETITEMTEXT, i, VARPTR(ms_lvi)
END SUB

#IF (%WIN32_IE >= &H0300)
' these flags only apply to LVS_OWNERDATA listviews in report or list mode
%LVSICF_NOINVALIDATEALL  = &H00000001
%LVSICF_NOSCROLL         = &H00000002
#ENDIF

%LVM_SETITEMCOUNT       = %LVM_FIRST + 47
SUB ListView_SetItemCount (BYVAL hwndLV AS DWORD, BYVAL cItems AS DWORD)
    SendMessage hwndLV, %LVM_SETITEMCOUNT, cItems, 0
END SUB

#IF (%WIN32_IE >= &H0300)
SUB ListView_SetItemCountEx (BYVAL hwndLV AS DWORD, BYVAL cItems AS DWORD, _
    BYVAL dwFlags AS LONG)
    SendMessage hwndLV, %LVM_SETITEMCOUNT, cItems, dwFlags
END SUB
#ENDIF

DECLARE FUNCTION PFNLVCOMPARE (BYVAL l1 AS LONG, BYVAL l2 AS LONG, _
    BYVAL l3 AS LONG) AS LONG

%LVM_SORTITEMS          = %LVM_FIRST + 48
FUNCTION ListView_SortItems (BYVAL hWndLV AS DWORD, _
    BYVAL pfnCompare AS DWORD, BYVAL lPrm AS LONG) AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_SORTITEMS, lPrm, pfnCompare)
END FUNCTION

%LVM_SETITEMPOSITION32  = %LVM_FIRST + 49

SUB ListView_SetItemPosition32 (BYVAL hWndLV AS DWORD, BYVAL i AS LONG, _
    BYVAL x AS LONG, BYVAL y AS LONG)
    LOCAL ptNewPos AS POINT
    ptNewPos.x = x
    ptNewPos.y = y
    SendMessage hWndLV, %LVM_SETITEMPOSITION32, i, VARPTR(ptNewPos)
END SUB

%LVM_GETSELECTEDCOUNT   = %LVM_FIRST + 50

FUNCTION ListView_GetSelectedCount (BYVAL hWndLV AS DWORD) AS DWORD
    FUNCTION = SendMessage(hWndLV, %LVM_GETSELECTEDCOUNT, 0, 0)
END FUNCTION

%LVM_GETITEMSPACING     = %LVM_FIRST + 51

FUNCTION ListView_GetItemSpacing (BYVAL hWndLV AS DWORD, _
    BYVAL fSmall AS LONG) AS DWORD
    FUNCTION = SendMessage(hWndLV, %LVM_GETITEMSPACING, fSmall, 0)
END FUNCTION

%LVM_GETISEARCHSTRINGA  = %LVM_FIRST + 52
%LVM_GETISEARCHSTRINGW  = %LVM_FIRST + 117

#IF %DEF(%UNICODE)
%LVM_GETISEARCHSTRING = %LVM_GETISEARCHSTRINGW
#ELSE
%LVM_GETISEARCHSTRING = %LVM_GETISEARCHSTRINGA
#ENDIF

FUNCTION ListView_GetISearchString (BYVAL hWndLV AS DWORD, lpsz AS ASCIIZ) _
    AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_GETISEARCHSTRING, 0, VARPTR(lpsz))
END FUNCTION

#IF (%WIN32_IE >= &H0300)
%LVM_SETICONSPACING     = %LVM_FIRST + 53

' -1 for cx and cy means we'll use the default(system settings)
' 0 for cx or cy means use the current setting(allows you to change just one param)

MACRO ListView_SetIconSpacing(hwndLV, cx, cy)=SendMessage(hwndLV, %LVM_SETICONSPACING, 0, MAK(LONG,cx,cy))

%LVM_SETEXTENDEDLISTVIEWSTYLE = %LVM_FIRST + 54  ' optional wParam == mask
FUNCTION ListView_SetExtendedListViewStyle (BYVAL hwndLV AS DWORD, _
    BYVAL dwd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwndLV, %LVM_SETEXTENDEDLISTVIEWSTYLE, 0, dwd)
END FUNCTION
#IF (%WIN32_IE >= &H0400)
FUNCTION ListView_SetExtendedListViewStyleEx (BYVAL hwndLV AS DWORD, _
    BYVAL dwMask AS DWORD, BYVAL dwd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwndLV, %LVM_SETEXTENDEDLISTVIEWSTYLE, dwMask, dwd)
END FUNCTION
#ENDIF

%LVM_GETEXTENDEDLISTVIEWSTYLE = %LVM_FIRST + 55

FUNCTION ListView_GetExtendedListViewStyle(BYVAL hwndLV AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwndLV, %LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0)
END FUNCTION

%LVS_EX_GRIDLINES        = &H00000001
%LVS_EX_SUBITEMIMAGES    = &H00000002
%LVS_EX_CHECKBOXES       = &H00000004
%LVS_EX_TRACKSELECT      = &H00000008
%LVS_EX_HEADERDRAGDROP   = &H00000010
%LVS_EX_FULLROWSELECT    = &H00000020 ' applies to report mode only
%LVS_EX_ONECLICKACTIVATE = &H00000040
%LVS_EX_TWOCLICKACTIVATE = &H00000080
#IF (%WIN32_IE >= &H0400)
%LVS_EX_FLATSB           = &H00000100
%LVS_EX_REGIONAL         = &H00000200
%LVS_EX_INFOTIP          = &H00000400 ' listview does InfoTips for you
%LVS_EX_UNDERLINEHOT     = &H00000800
%LVS_EX_UNDERLINECOLD    = &H00001000
%LVS_EX_MULTIWORKAREAS   = &H00002000
#ENDIF
#IF (%WIN32_IE >= &H0500)
%LVS_EX_LABELTIP         = &H00004000 ' listview unfolds partly hidden labels if it does not have infotip text
%LVS_EX_BORDERSELECT     = &H00008000 ' border selection style instead of highlight
#ENDIF  '(%WIN32_IE >= &H0500)
#IF (%WIN32_WINNT >= &H0501)
%LVS_EX_DOUBLEBUFFER     = &H00010000
%LVS_EX_HIDELABELS       = &H00020000
%LVS_EX_SINGLEROW        = &H00040000
%LVS_EX_SNAPTOGRID       = &H00080000 ' Icons automatically snap to grid.
%LVS_EX_SIMPLESELECT     = &H00100000 ' Also changes overlay rendering to top right for icon mode.
#ENDIF
#IF %WIN32_WINNT >= &H0600
%LVS_EX_JUSTIFYCOLUMNS   = &H00200000  ' Icons are lined up in columns that use up the whole view area.
%LVS_EX_TRANSPARENTBKGND = &H00400000  ' Background is painted by the parent via WM_PRINTCLIENT
%LVS_EX_TRANSPARENTSHADOWTEXT = &H00800000  ' Enable shadow text on transparent backgrounds only(useful with bitmaps)
%LVS_EX_AUTOAUTOARRANGE  = &H01000000  ' Icons automatically arrange if no icon positions have been set
%LVS_EX_HEADERINALLVIEWS = &H02000000  ' Display column header in all view modes
%LVS_EX_AUTOCHECKSELECT  = &H08000000
%LVS_EX_AUTOSIZECOLUMNS  = &H10000000
%LVS_EX_COLUMNSNAPPOINTS = &H40000000
%LVS_EX_COLUMNOVERFLOW   = &H80000000???
#ENDIF

%LVM_GETSUBITEMRECT      = %LVM_FIRST + 56

FUNCTION ListView_GetSubItemRect (BYVAL hwnd AS DWORD, BYVAL iItem AS LONG, _
    BYVAL iSubItem AS LONG, BYVAL nCode AS LONG, BYVAL prc AS RECT PTR) AS LONG
    IF prc THEN
        @prc.nTop = iSubItem
        @prc.nLeft = nCode
    END IF
    FUNCTION = SendMessage(hwnd, %LVM_GETSUBITEMRECT, iItem, prc)
END FUNCTION

%LVM_SUBITEMHITTEST      = %LVM_FIRST + 57
FUNCTION ListView_SubItemHitTest (BYVAL hwnd AS DWORD, _
    plvhti AS LVHITTESTINFO) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_SUBITEMHITTEST, 0, VARPTR(plvhti))
END FUNCTION

%LVM_SETCOLUMNORDERARRAY = %LVM_FIRST + 58
FUNCTION ListView_SetColumnOrderArray (BYVAL hwnd AS DWORD, _
    BYVAL iCount AS LONG, BYVAL pii AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_SETCOLUMNORDERARRAY, iCount, pii)
END FUNCTION

%LVM_GETCOLUMNORDERARRAY = %LVM_FIRST + 59
FUNCTION ListView_GetColumnOrderArray (BYVAL hwnd AS DWORD, _
    BYVAL iCount AS LONG, BYVAL pii AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_GETCOLUMNORDERARRAY, iCount, pii)
END FUNCTION

%LVM_SETHOTITEM  = %LVM_FIRST + 60
FUNCTION ListView_SetHotItem (BYVAL hwnd AS DWORD, i AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_SETHOTITEM, i, 0)
END FUNCTION

%LVM_GETHOTITEM  = %LVM_FIRST + 61
FUNCTION ListView_GetHotItem (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_GETHOTITEM, 0, 0)
END FUNCTION

%LVM_SETHOTCURSOR  = %LVM_FIRST + 62
FUNCTION ListView_SetHotCursor (BYVAL hwnd AS DWORD, BYVAL hcur AS DWORD) _
    AS DWORD
    FUNCTION = SendMessage(hwnd, %LVM_SETHOTCURSOR, 0, hcur)
END FUNCTION

%LVM_GETHOTCURSOR  = %LVM_FIRST + 63
FUNCTION ListView_GetHotCursor (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %LVM_GETHOTCURSOR, 0, 0)
END FUNCTION

%LVM_APPROXIMATEVIEWRECT = %LVM_FIRST + 64
FUNCTION ListView_ApproximateViewRect (BYVAL hwnd AS DWORD, _
    BYVAL iWidth AS INTEGER, BYVAL iHeight AS INTEGER, BYVAL iCount AS LONG) _
    AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_APPROXIMATEVIEWRECT, iCount, _
        MAK(LONG, iWidth, iHeight))
END FUNCTION
#ENDIF      ' %WIN32_IE >= &H0300

#IF (%WIN32_IE >= &H0400)

%LV_MAX_WORKAREAS         = 16
%LVM_SETWORKAREAS         = %LVM_FIRST + 65

FUNCTION ListView_SetWorkAreas (BYVAL hwnd AS DWORD, _
    BYVAL nWorkAreas AS LONG, prc AS RECT) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_SETWORKAREAS, nWorkAreas, VARPTR(prc))
END FUNCTION

%LVM_GETWORKAREAS        = %LVM_FIRST + 70
FUNCTION ListView_GetWorkAreas (BYVAL hwnd AS DWORD, _
    BYVAL nWorkAreas AS LONG, prc AS RECT) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_GETWORKAREAS, nWorkAreas, VARPTR(prc))
END FUNCTION

%LVM_GETNUMBEROFWORKAREAS  = %LVM_FIRST + 73
FUNCTION ListView_GetNumberOfWorkAreas (BYVAL hwnd AS DWORD, _
    pnWorkAreas AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_GETNUMBEROFWORKAREAS, 0, _
        VARPTR(pnWorkAreas))
END FUNCTION

%LVM_GETSELECTIONMARK    = %LVM_FIRST + 66
FUNCTION ListView_GetSelectionMark (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_GETSELECTIONMARK, 0, 0)
END FUNCTION

%LVM_SETSELECTIONMARK    = %LVM_FIRST + 67
FUNCTION ListView_SetSelectionMark (BYVAL hwnd AS DWORD, i AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_SETSELECTIONMARK, 0, i)
END FUNCTION

%LVM_SETHOVERTIME        = %LVM_FIRST + 71
FUNCTION ListView_SetHoverTime (BYVAL hwndLV AS DWORD, _
    BYVAL dwHoverTimeMs AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwndLV, %LVM_SETHOVERTIME, 0, dwHoverTimeMs)
END FUNCTION

%LVM_GETHOVERTIME        = %LVM_FIRST + 72
FUNCTION ListView_GetHoverTime (BYVAL hwndLV AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwndLV, %LVM_GETHOVERTIME, 0, 0)
END FUNCTION

%LVM_SETTOOLTIPS       = %LVM_FIRST + 74
FUNCTION ListView_SetToolTips (BYVAL hwndLV AS DWORD, _
    BYVAL hwndNewHwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwndLV, %LVM_SETTOOLTIPS, hwndNewHwnd, 0)
END FUNCTION

%LVM_GETTOOLTIPS       = %LVM_FIRST + 78
FUNCTION ListView_GetToolTips (BYVAL hwndLV AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwndLV, %LVM_GETTOOLTIPS, 0, 0)
END FUNCTION

%LVM_SORTITEMSEX       = %LVM_FIRST + 81
FUNCTION ListView_SortItemsEx (BYVAL hwndLV AS DWORD, _
    BYVAL pfnCompare AS DWORD, BYVAL lParamSort AS LONG) AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_SORTITEMSEX, lParamSort, pfnCompare)
END FUNCTION

TYPE LVBKIMAGEA
    ulFlags        AS DWORD    ' LVBKIF_*
    hbm            AS DWORD
    pszImage       AS ASCIIZ PTR
    cchImageMax    AS DWORD
    xOffsetPercent AS LONG
    yOffsetPercent AS LONG
END TYPE

TYPE LVBKIMAGEW
    ulFlags        AS DWORD    ' LVBKIF_*
    hbm            AS DWORD
    pszImage       AS WSTRINGZ PTR
    cchImageMax    AS DWORD
    xOffsetPercent AS LONG
    yOffsetPercent AS LONG
END TYPE

%LVBKIF_SOURCE_NONE      = &H00000000
%LVBKIF_SOURCE_HBITMAP   = &H00000001
%LVBKIF_SOURCE_URL       = &H00000002
%LVBKIF_SOURCE_MASK      = &H00000003
%LVBKIF_STYLE_NORMAL     = &H00000000
%LVBKIF_STYLE_TILE       = &H00000010
%LVBKIF_STYLE_MASK       = &H00000010
#IF (%WIN32_WINNT >= &H0501)
%LVBKIF_FLAG_TILEOFFSET  = &H00000100
%LVBKIF_TYPE_WATERMARK   = &H10000000
%LVBKIF_FLAG_ALPHABLEND  = &H20000000
#ENDIF

%LVM_SETBKIMAGEA         = %LVM_FIRST + 68
%LVM_SETBKIMAGEW         = %LVM_FIRST + 138
%LVM_GETBKIMAGEA         = %LVM_FIRST + 69
%LVM_GETBKIMAGEW         = %LVM_FIRST + 139

#IF (%WIN32_WINNT >= &H0501)
%LVM_SETSELECTEDCOLUMN         = (%LVM_FIRST + 140)
SUB ListView_SetSelectedColumn (BYVAL hwnd AS DWORD, BYVAL iCol AS LONG)
    SendMessage hwnd, %LVM_SETSELECTEDCOLUMN, iCol, 0
END SUB

%LVM_SETTILEWIDTH         = (%LVM_FIRST + 141)
FUNCTION ListView_SetTileWidth (BYVAL hwnd AS DWORD, BYVAL cpWidth AS DWORD) _
    AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_SETTILEWIDTH, cpWidth, 0)
END FUNCTION

%LV_VIEW_ICON      = &H0000
%LV_VIEW_DETAILS   = &H0001
%LV_VIEW_SMALLICON = &H0002
%LV_VIEW_LIST      = &H0003
%LV_VIEW_TILE      = &H0004
%LV_VIEW_MAX       = &H0004

%LVM_SETVIEW         = (%LVM_FIRST + 142)
FUNCTION ListView_SetView (BYVAL hwnd AS DWORD, BYVAL dView AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_SETVIEW, dView, 0)
END FUNCTION

%LVM_GETVIEW         = (%LVM_FIRST + 143)
FUNCTION ListView_GetView (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %LVM_GETVIEW, 0, 0)
END FUNCTION

%LVGF_NONE          = &H00000000
%LVGF_HEADER        = &H00000001
%LVGF_FOOTER        = &H00000002
%LVGF_STATE         = &H00000004
%LVGF_ALIGN         = &H00000008
%LVGF_GROUPID       = &H00000010
#IF %WIN32_WINNT >= &H0600
%LVGF_SUBTITLE          = &H00000100  ' pszSubtitle is valid
%LVGF_TASK              = &H00000200  ' pszTask is valid
%LVGF_DESCRIPTIONTOP    = &H00000400  ' pszDescriptionTop is valid
%LVGF_DESCRIPTIONBOTTOM = &H00000800  ' pszDescriptionBottom is valid
%LVGF_TITLEIMAGE        = &H00001000  ' iTitleImage is valid
%LVGF_EXTENDEDIMAGE     = &H00002000  ' iExtendedImage is valid
%LVGF_ITEMS             = &H00004000  ' iFirstItem and cItems are valid
%LVGF_SUBSET            = &H00008000  ' pszSubsetTitle is valid
%LVGF_SUBSETITEMS       = &H00010000  ' readonly, cItems holds count of items in visible subset, iFirstItem is valid
#ENDIF  ' #IF %WIN32_WINNT >= &H0600

%LVGS_NORMAL            = &H00000000
%LVGS_COLLAPSED         = &H00000001
%LVGS_HIDDEN            = &H00000002
%LVGS_NOHEADER          = &H00000004
%LVGS_COLLAPSIBLE       = &H00000008
%LVGS_FOCUSED           = &H00000010
%LVGS_SELECTED          = &H00000020
%LVGS_SUBSETED          = &H00000040
%LVGS_SUBSETLINKFOCUSED = &H00000080

%LVGA_HEADER_LEFT   = &H00000001
%LVGA_HEADER_CENTER = &H00000002
%LVGA_HEADER_RIGHT  = &H00000004  ' Don't forget to validate exclusivity
%LVGA_FOOTER_LEFT   = &H00000008
%LVGA_FOOTER_CENTER = &H00000010
%LVGA_FOOTER_RIGHT  = &H00000020  ' Don't forget to validate exclusivity

' [MSDN incorrectly documents this type as LV_GROUP]
TYPE LVGROUP
    cbSize               AS DWORD
    mask                 AS DWORD
    pszHeader            AS WSTRINGZ PTR
    cchHeader            AS LONG
    pszFooter            AS WSTRINGZ PTR
    cchFooter            AS LONG
    iGroupId             AS LONG
    stateMask            AS DWORD
    nState               AS DWORD
    uAlign               AS DWORD
#IF %WIN32_WINNT >= &H0600
    pszSubtitle          AS WSTRINGZ PTR
    cchSubtitle          AS DWORD
    pszTask              AS WSTRINGZ PTR
    cchTask              AS DWORD
    pszDescriptionTop    AS WSTRINGZ PTR
    cchDescriptionTop    AS DWORD
    pszDescriptionBottom AS WSTRINGZ PTR
    cchDescriptionBottom AS DWORD
    iTitleImage          AS LONG
    iExtendedImage       AS LONG
    iFirstItem           AS LONG         ' Read only
    cItems               AS DWORD        ' Read only
    pszSubsetTitle       AS WSTRINGZ PTR ' %NULL if group is not subset
    cchSubsetTitle       AS DWORD
#ENDIF  ' #IF %WIN32_WINNT >= &H0600
END TYPE

#IF %WIN32_WINNT >= &H0600
%LVGROUP_V5_SIZE = 10 * 4     ' CCSIZEOF_STRUCT(LVGROUP, uAlign)
#ENDIF

%LVM_INSERTGROUP         = (%LVM_FIRST + 145)

FUNCTION ListView_InsertGroup (BYVAL hwnd AS DWORD, BYVAL index AS LONG, _
    pgrp AS LVGROUP) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_INSERTGROUP, index, VARPTR(pgrp))
END FUNCTION

%LVM_SETGROUPINFO         = (%LVM_FIRST + 147)

FUNCTION ListView_SetGroupInfo (BYVAL hwnd AS DWORD, BYVAL iGroupId AS LONG, _
    pgrp AS LVGROUP) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_SETGROUPINFO, iGroupId, VARPTR(pgrp))
END FUNCTION

%LVM_GETGROUPINFO         = (%LVM_FIRST + 149)

FUNCTION ListView_GetGroupInfo (BYVAL hwnd AS DWORD, BYVAL iGroupId AS LONG, _
    pgrp AS LVGROUP) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_GETGROUPINFO, iGroupId, VARPTR(pgrp))
END FUNCTION

%LVM_REMOVEGROUP         = (%LVM_FIRST + 150)

FUNCTION ListView_RemoveGroup (BYVAL hwnd AS DWORD, BYVAL iGroupId AS LONG) _
    AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_REMOVEGROUP, iGroupId, 0)
END FUNCTION

%LVM_MOVEGROUP         = (%LVM_FIRST + 151)

SUB ListView_MoveGroup (BYVAL hwnd AS DWORD, BYVAL iGroupId AS LONG, _
    BYVAL toIndex AS LONG)
    SendMessage hwnd, %LVM_MOVEGROUP, iGroupId, toIndex
END SUB

%LVM_MOVEITEMTOGROUP            = (%LVM_FIRST + 154)

SUB ListView_MoveItemToGroup (BYVAL hwnd AS DWORD, BYVAL idItemFrom AS LONG, _
    BYVAL idGroupTo AS LONG)
    SendMessage hwnd, %LVM_MOVEITEMTOGROUP, idItemFrom, idGroupTo
END SUB

%LVGMF_NONE        = &H00000000
%LVGMF_BORDERSIZE  = &H00000001
%LVGMF_BORDERCOLOR = &H00000002
%LVGMF_TEXTCOLOR   = &H00000004

TYPE LVGROUPMETRICS
    cbSize   AS DWORD
    mask     AS DWORD
    nLeft    AS DWORD
    nTop     AS DWORD
    nRight   AS DWORD
    nBottom  AS DWORD
    crLeft   AS DWORD
    crTop    AS DWORD
    crRight  AS DWORD
    crBottom AS DWORD
    crHeader AS DWORD
    crFooter AS DWORD
END TYPE

%LVM_SETGROUPMETRICS         = (%LVM_FIRST + 155)

SUB ListView_SetGroupMetrics (BYVAL hwnd AS DWORD, _
    pGroupMetrics AS LVGROUPMETRICS)
    SendMessage hwnd, %LVM_SETGROUPMETRICS, 0, VARPTR(pGroupMetrics)
END SUB

%LVM_GETGROUPMETRICS         = (%LVM_FIRST + 156)

SUB ListView_GetGroupMetrics (BYVAL hwnd AS DWORD, _
    pGroupMetrics AS LVGROUPMETRICS)
    SendMessage hwnd, %LVM_GETGROUPMETRICS, 0, VARPTR(pGroupMetrics)
END SUB

%LVM_ENABLEGROUPVIEW         = (%LVM_FIRST + 157)

FUNCTION ListView_EnableGroupView (BYVAL hwnd AS DWORD, _
    BYVAL fEnable AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_ENABLEGROUPVIEW, fEnable, 0)
END FUNCTION

%LVM_SORTGROUPS         = (%LVM_FIRST + 158)

FUNCTION ListView_SortGroups (BYVAL hwnd AS DWORD, _
    BYVAL pfnGroupCompate AS DWORD, BYVAL plv AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_SORTGROUPS, pfnGroupCompate, plv)
END FUNCTION

TYPE LVINSERTGROUPSORTED
    pfnGroupCompare AS DWORD
    pvData          AS DWORD
    lvGrp           AS LVGROUP
END TYPE

%LVM_INSERTGROUPSORTED           = (%LVM_FIRST + 159)

' MSDN documents a third index parameter, apparently incorrectly.
SUB ListView_InsertGroupSorted (BYVAL hwnd AS DWORD, _
    structInsert AS LVINSERTGROUPSORTED)
    SendMessage hwnd, %LVM_INSERTGROUPSORTED, VARPTR(structInsert), 0
END SUB

%LVM_REMOVEALLGROUPS             = (%LVM_FIRST + 160)

SUB ListView_RemoveAllGroups (BYVAL hwnd AS DWORD)
    SendMessage hwnd, %LVM_REMOVEALLGROUPS, 0, 0
END SUB

%LVM_HASGROUP                    = (%LVM_FIRST + 161)

FUNCTION ListView_HasGroup (BYVAL hwnd AS DWORD, BYVAL iGroupId AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_HASGROUP, iGroupId, 0)
END FUNCTION

%LVTVIF_AUTOSIZE    = &H00000000
%LVTVIF_FIXEDWIDTH  = &H00000001
%LVTVIF_FIXEDHEIGHT = &H00000002
%LVTVIF_FIXEDSIZE   = &H00000003
#IF %WIN32_WINNT >= &H0600
%LVTVIF_EXTENDED    = &H00000004
#ENDIF

%LVTVIM_TILESIZE    = &H00000001
%LVTVIM_COLUMNS     = &H00000002
%LVTVIM_LABELMARGIN = &H00000004

TYPE LVTILEVIEWINFO
    cbSize        AS DWORD
    dwMask        AS DWORD   ' LVTVIM_*
    dwFlags       AS DWORD   ' LVTVIF_*
    sizeTile      AS SIZEL
    cLines        AS LONG
    rcLabelMargin AS RECT
END TYPE

TYPE LVTILEINFO
    cbSize    AS DWORD
    iItem     AS LONG
    cColumns  AS DWORD
    puColumns AS DWORD PTR
END TYPE

%LVM_SETTILEVIEWINFO                 = (%LVM_FIRST + 162)

FUNCTION ListView_SetTileViewInfo (BYVAL hwnd AS DWORD, _
    ptvi AS LVTILEVIEWINFO) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_SETTILEVIEWINFO, 0, VARPTR(ptvi))
END FUNCTION

%LVM_GETTILEVIEWINFO                 = (%LVM_FIRST + 163)

SUB ListView_GetTileViewInfo (BYVAL hwnd AS DWORD, ptvi AS LVTILEVIEWINFO)
    SendMessage hwnd, %LVM_GETTILEVIEWINFO, 0, VARPTR(ptvi)
END SUB

%LVM_SETTILEINFO                     = (%LVM_FIRST + 164)

FUNCTION ListView_SetTileInfo (BYVAL hwnd AS DWORD, pti AS LVTILEINFO) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_SETTILEINFO, 0, VARPTR(pti))
END FUNCTION

%LVM_GETTILEINFO                     = (%LVM_FIRST + 165)

SUB ListView_GetTileInfo (BYVAL hwnd AS DWORD, pti AS LVTILEINFO)
    SendMessage hwnd, %LVM_GETTILEINFO, 0, VARPTR(pti)
END SUB

TYPE LVINSERTMARK
    cbSize     AS DWORD
    dwFlags    AS DWORD
    iItem      AS LONG
    dwReserved AS DWORD
END TYPE

%LVIM_AFTER = &H00000001 ' %TRUE = insert After iItem, otherwise before

%LVM_SETINSERTMARK                   = (%LVM_FIRST + 166)

FUNCTION ListView_SetInsertMark (BYVAL hwnd AS DWORD, lvim AS LVINSERTMARK) _
    AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_SETINSERTMARK, 0, VARPTR(lvim))
END FUNCTION

%LVM_GETINSERTMARK                   = (%LVM_FIRST + 167)

FUNCTION ListView_GetInsertMark (BYVAL hwnd AS DWORD, lvim AS LVINSERTMARK) _
    AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_GETINSERTMARK, 0, VARPTR(lvim))
END FUNCTION

%LVM_INSERTMARKHITTEST               = (%LVM_FIRST + 168)

FUNCTION ListView_InsertMarkHitTest (BYVAL hwnd AS DWORD, _
    ppoint AS POINT, lvim AS LVINSERTMARK) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_INSERTMARKHITTEST, VARPTR(ppoint), _
        VARPTR(lvim))
END FUNCTION

%LVM_GETINSERTMARKRECT               = (%LVM_FIRST + 169)

FUNCTION ListView_GetInsertMarkRect (BYVAL hwnd AS DWORD, rc AS RECT) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_GETINSERTMARKRECT, 0, VARPTR(rc))
END FUNCTION

%LVM_SETINSERTMARKCOLOR                 = (%LVM_FIRST + 170)

FUNCTION ListView_SetInsertMarkColor (BYVAL hwnd AS DWORD, _
    BYVAL colr AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %LVM_SETINSERTMARKCOLOR, 0, colr)
END FUNCTION

%LVM_GETINSERTMARKCOLOR                 = (%LVM_FIRST + 171)

FUNCTION ListView_GetInsertMarkColor (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %LVM_GETINSERTMARKCOLOR, 0, 0)
END FUNCTION

TYPE LVSETINFOTIP
    cbSize   AS DWORD
    dwFlags  AS DWORD
    pszText  AS DWORD ' UnicodeZ string ptr
    iItem    AS LONG
    iSubItem AS LONG
END TYPE

%LVM_SETINFOTIP         = (%LVM_FIRST + 173)

FUNCTION ListView_SetInfoTip (BYVAL hwndLV AS DWORD, _
    plvInfoTip AS LVSETINFOTIP) AS LONG
    FUNCTION = SendMessage(hwndLV, %LVM_SETINFOTIP, 0, VARPTR(plvInfoTip))
END FUNCTION

%LVM_GETSELECTEDCOLUMN   = (%LVM_FIRST + 174)

FUNCTION ListView_GetSelectedColumn (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %LVM_GETSELECTEDCOLUMN, 0, 0)
END FUNCTION

%LVM_ISGROUPVIEWENABLED  = (%LVM_FIRST + 175)

FUNCTION ListView_IsGroupViewEnabled (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_ISGROUPVIEWENABLED, 0, 0)
END FUNCTION

%LVM_GETOUTLINECOLOR     = (%LVM_FIRST + 176)

FUNCTION ListView_GetOutlineColor (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %LVM_GETOUTLINECOLOR, 0, 0)
END FUNCTION

%LVM_SETOUTLINECOLOR     = (%LVM_FIRST + 177)

FUNCTION ListView_SetOutlineColor (BYVAL hwnd AS DWORD, BYVAL colr AS DWORD) _
    AS DWORD
    FUNCTION = SendMessage(hwnd, %LVM_SETOUTLINECOLOR, 0, colr)
END FUNCTION

%LVM_CANCELEDITLABEL     = (%LVM_FIRST + 179)

SUB ListView_CancelEditLabel (BYVAL hwnd AS DWORD)
    SendMessage hwnd, %LVM_CANCELEDITLABEL, 0, 0
END SUB

' These next to methods make it easy to identify an item that can be repositioned
' within listview. For example: Many developers use the lParam to store an identifier that is
' unique. Unfortunately, in order to find this item, they have to iterate through all of the items
' in the listview. Listview will maintain a unique identifier.  The upper bound is the size of a DWORD.
%LVM_MAPINDEXTOID     = (%LVM_FIRST + 180)

FUNCTION ListView_MapIndexToID (BYVAL hwnd AS DWORD, BYVAL index AS DWORD) _
    AS DWORD
    FUNCTION = SendMessage(hwnd, %LVM_MAPINDEXTOID, index, 0)
END FUNCTION

%LVM_MAPIDTOINDEX     = (%LVM_FIRST + 181)

FUNCTION ListView_MapIDToIndex (BYVAL hwnd AS DWORD, BYVAL ID AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %LVM_MAPIDTOINDEX, ID, 0)
END FUNCTION

%LVM_ISITEMVISIBLE    = (%LVM_FIRST + 182)
FUNCTION ListView_IsItemVisible (BYVAL hWnd AS DWORD, BYVAL index AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %LVM_ISITEMVISIBLE, index, 0)
END FUNCTION


#IF %WIN32_WINNT >= &H0600
FUNCTION ListView_SetGroupHeaderImageList (BYVAL hWnd AS DWORD, _
    BYVAL himl AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %LVM_SETIMAGELIST, %LVSIL_GROUPHEADER, himl)
END FUNCTION

FUNCTION ListView_GetGroupHeaderImageList (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %LVM_GETIMAGELIST, %LVSIL_GROUPHEADER, 0)
END FUNCTION

%LVM_GETEMPTYTEXT = (%LVM_FIRST + 204)
FUNCTION ListView_GetEmptyText (BYVAL hwnd AS DWORD, pszText AS WSTRINGZ, _
    BYVAL cchText AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_GETEMPTYTEXT, cchText, VARPTR(pszText))
END FUNCTION

%LVM_GETFOOTERRECT = (%LVM_FIRST + 205)
FUNCTION ListView_GetFooterRect (BYVAL hwnd AS DWORD, prc AS RECT) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_GETFOOTERRECT, 0, VARPTR(prc))
END FUNCTION

' footer flags
%LVFF_ITEMCOUNT        = &H00000001

TYPE LVFOOTERINFO
    mask       AS DWORD          ' LVFF_*
    pszText    AS WSTRINGZ PTR
    cchTextMax AS LONG
    cItems     AS DWORD
END TYPE

%LVM_GETFOOTERINFO = (%LVM_FIRST + 206)
FUNCTION ListView_GetFooterInfo (BYVAL hwnd AS DWORD, plvfi AS LVFOOTERINFO) _
    AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_GETFOOTERINFO, 0, VARPTR(plvfi))
END FUNCTION

%LVM_GETFOOTERITEMRECT = (%LVM_FIRST + 207)
FUNCTION ListView_GetFooterItemRect (BYVAL hwnd AS DWORD, _
    BYVAL iItem AS DWORD, prc AS RECT) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_GETFOOTERITEMRECT, iItem, VARPTR(prc))
END FUNCTION

' footer item flags
%LVFIF_TEXT             = &H00000001
%LVFIF_STATE            = &H00000002

' footer item state
%LVFIS_FOCUSED          = &H0001

TYPE LVFOOTERITEM
    mask       AS DWORD         ' LVFIF_*
    iItem      AS LONG
    pszText    AS WSTRINGZ PTR
    cchTextMax AS LONG
    nstate     AS DWORD         ' LVFIS_*
    stateMask  AS DWORD         ' LVFIS_*
END TYPE

%LVM_GETFOOTERITEM = (%LVM_FIRST + 208)
FUNCTION ListView_GetFooterItem (BYVAL hwnd AS DWORD, BYVAL iItem AS DWORD, _
    pfi AS LVFOOTERITEM) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_GETFOOTERITEM, iItem, VARPTR(pfi))
END FUNCTION

' supports a single item in multiple groups.
TYPE LVITEMINDEX
    iItem  AS LONG         ' listview item index
    iGroup AS LONG         ' group index(must be -1 if group view is not enabled)
END TYPE

%LVM_GETITEMINDEXRECT  = (%LVM_FIRST + 209)
FUNCTION ListView_GetItemIndexRect (BYVAL hwnd AS DWORD, _
    plvii AS LVITEMINDEX, BYVAL iSubItem AS LONG, BYVAL code AS LONG, _
    prc AS RECT) AS LONG
    prc.top  = iSubItem
    prc.left = CODE
    FUNCTION = SendMessage(hwnd, %LVM_GETITEMINDEXRECT, VARPTR(plvii), VARPTR(prc))
END FUNCTION

%LVM_SETITEMINDEXSTATE = (%LVM_FIRST + 210)
FUNCTION ListView_SetItemIndexState (BYVAL hwndLV AS DWORD, _
    plvii AS LVITEMINDEX, BYVAL ddata AS DWORD, BYVAL mask AS DWORD) AS LONG
    LOCAL macro_lvi AS LV_ITEM
    macro_lvi.stateMask = mask
    macro_lvi.state = ddata
    FUNCTION = SendMessage(hwndLV, %LVM_SETITEMINDEXSTATE, VARPTR(plvii), VARPTR(macro_lvi))
END FUNCTION

%LVM_GETNEXTITEMINDEX  = (%LVM_FIRST + 211)
FUNCTION ListView_GetNextItemIndex (BYVAL hwnd AS DWORD, _
    plvii AS LVITEMINDEX, BYVAL flags AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_GETNEXTITEMINDEX, VARPTR(plvii), MAKELPARAM(flags, 0))
END FUNCTION

#ENDIF

#ENDIF

#IF %DEF(%UNICODE)
TYPE LVBKIMAGE
    LVBKIMAGEW
END TYPE
%LVM_SETBKIMAGE = %LVM_SETBKIMAGEW
%LVM_GETBKIMAGE = %LVM_GETBKIMAGEW
#ELSE
TYPE LVBKIMAGE
    LVBKIMAGEA
END TYPE
%LVM_SETBKIMAGE = %LVM_SETBKIMAGEA
%LVM_GETBKIMAGE = %LVM_GETBKIMAGEA
#ENDIF

FUNCTION ListView_SetBkImage (BYVAL hwnd AS DWORD, plvbki AS LVBKIMAGE) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_SETBKIMAGE, 0, VARPTR(plvbki))
END FUNCTION

FUNCTION ListView_GetBkImage (BYVAL hwnd AS DWORD, plvbki AS LVBKIMAGE) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_GETBKIMAGE, 0, VARPTR(plvbki))
END FUNCTION

#ENDIF  ' %WIN32_IE >= &H0400

TYPE NMLISTVIEW
    hdr       AS NMHDR
    iItem     AS LONG
    iSubItem  AS LONG
    uNewState AS DWORD
    uOldState AS DWORD
    uChanged  AS DWORD
    ptAction  AS POINT
    lParam    AS LONG
END TYPE

#IF (%WIN32_IE >= &H0300)
TYPE NM_LISTVIEW
    NMLISTVIEW
END TYPE
#ELSE
TYPE NMLISTVIEW
    NM_LISTVIEW
END TYPE
#ENDIF

#IF (%WIN32_IE >= &H400)
' NMITEMACTIVATE is used instead of NMLISTVIEW in IE >= 0x400
' therefore all the fields are the same except for extra uKeyFlags
' they are used to store key flags at the time of the single click with
' delayed activation - because by the time the timer goes off a user may
' not hold the keys(shift, ctrl) any more

TYPE NMITEMACTIVATE
    hdr       AS NMHDR
    iItem     AS LONG
    iSubItem  AS LONG
    uNewState AS DWORD
    uOldState AS DWORD
    uChanged  AS DWORD
    ptAction  AS POINT
    lParam    AS LONG
    uKeyFlags AS DWORD
END TYPE

' key flags stored in uKeyFlags
%LVKF_ALT       = &H0001
%LVKF_CONTROL   = &H0002
%LVKF_SHIFT     = &H0004
#ENDIF  ' #IF (%WIN32_IE >= &H400)

#IF (%WIN32_IE >= &H0300)
TYPE NMLVCUSTOMDRAW
    nmcd        AS NMCUSTOMDRAW
    clrText     AS DWORD
    clrTextBk   AS DWORD
#IF (%WIN32_IE >= &H0400)
    iSubItem    AS LONG
#ENDIF
#IF (%WIN32_WINNT >= &H0501)
    dwItemType  AS DWORD
    ' Item custom draw
    clrFace     AS DWORD
    iIconEffect AS LONG
    iIconPhase  AS LONG
    iPartId     AS LONG
    iStateId    AS LONG
    ' Group Custom Draw
    rcText      AS RECT
    uAlign      AS DWORD ' Alignment. Use LVGA_HEADER_CENTER, LVGA_HEADER_RIGHT, LVGA_HEADER_LEFT
#ENDIF
END TYPE

' dwItemType
%LVCDI_ITEM      = &H00000000
%LVCDI_GROUP     = &H00000001
%LVCDI_ITEMSLIST = &H00000002

' ListView custom draw return values
%LVCDRF_NOSELECT     = &H00010000
%LVCDRF_NOGROUPFRAME = &H00020000

TYPE NMLVCACHEHINT
    hdr   AS NMHDR
    iFrom AS LONG
    iTo   AS LONG
END TYPE

TYPE NM_CACHEHINT
    NMLVCACHEHINT
END TYPE

TYPE NMLVFINDITEMA
    hdr    AS NMHDR
    iStart AS LONG
    lvfi   AS LVFINDINFOA
END TYPE

TYPE NMLVFINDITEMW
    hdr    AS NMHDR
    iStart AS LONG
    lvfi   AS LVFINDINFOW
END TYPE

TYPE NM_FINDITEMA
    NMLVFINDITEMA
END TYPE
TYPE NM_FINDITEMW
    NMLVFINDITEMW
END TYPE

#IF %DEF(%UNICODE)
TYPE NM_FINDITEM
    NM_FINDITEMW
END TYPE
TYPE NMLVFINDITEM
    NMLVFINDITEMW
END TYPE
#ELSE
TYPE NM_FINDITEM
    NM_FINDITEMA
END TYPE
TYPE NMLVFINDITEM
    NMLVFINDITEMA
END TYPE
#ENDIF

TYPE NMLVODSTATECHANGE
    hdr       AS NMHDR
    iFrom     AS LONG
    iTo       AS LONG
    uNewState AS DWORD
    uOldState AS DWORD
END TYPE

TYPE NM_ODSTATECHANGE
    NMLVODSTATECHANGE
END TYPE

#ENDIF  ' %WIN32_IE >= &H0300

%LVN_ITEMCHANGING    = %LVN_FIRST
%LVN_ITEMCHANGED     = %LVN_FIRST - 1
%LVN_INSERTITEM      = %LVN_FIRST - 2
%LVN_DELETEITEM      = %LVN_FIRST - 3
%LVN_DELETEALLITEMS  = %LVN_FIRST - 4
%LVN_BEGINLABELEDITA = %LVN_FIRST - 5
%LVN_BEGINLABELEDITW = %LVN_FIRST - 75
%LVN_ENDLABELEDITA   = %LVN_FIRST - 6
%LVN_ENDLABELEDITW   = %LVN_FIRST - 76
%LVN_COLUMNCLICK     = %LVN_FIRST - 8
%LVN_BEGINDRAG       = %LVN_FIRST - 9
%LVN_BEGINRDRAG      = %LVN_FIRST - 11

#IF (%WIN32_IE >= &H0300)
%LVN_ODCACHEHINT     = %LVN_FIRST - 13
%LVN_ODFINDITEMA     = %LVN_FIRST - 52
%LVN_ODFINDITEMW     = %LVN_FIRST - 79

%LVN_ITEMACTIVATE    = %LVN_FIRST - 14
%LVN_ODSTATECHANGED  = %LVN_FIRST - 15
#IF %DEF(%UNICODE)
%LVN_ODFINDITEM = %LVN_ODFINDITEMW
#ELSE
%LVN_ODFINDITEM = %LVN_ODFINDITEMA
#ENDIF
#ENDIF  ' #IF (%WIN32_IE >= &H0300)

#IF (%WIN32_IE >= &H0400)
%LVN_HOTTRACK        = %LVN_FIRST - 21
#ENDIF

%LVN_GETDISPINFOA    = %LVN_FIRST - 50
%LVN_GETDISPINFOW    = %LVN_FIRST - 77
%LVN_SETDISPINFOA    = %LVN_FIRST - 51
%LVN_SETDISPINFOW    = %LVN_FIRST - 78

#IF %DEF(%UNICODE)
%LVN_BEGINLABELEDIT  = %LVN_BEGINLABELEDITW
%LVN_ENDLABELEDIT    = %LVN_ENDLABELEDITW
%LVN_GETDISPINFO     = %LVN_GETDISPINFOW
%LVN_SETDISPINFO     = %LVN_SETDISPINFOW
#ELSE
%LVN_BEGINLABELEDIT  = %LVN_BEGINLABELEDITA
%LVN_ENDLABELEDIT    = %LVN_ENDLABELEDITA
%LVN_GETDISPINFO     = %LVN_GETDISPINFOA
%LVN_SETDISPINFO     = %LVN_SETDISPINFOA
#ENDIF

%LVIF_DI_SETITEM     = &H1000

TYPE NMLVDISPINFOA
    hdr  AS NMHDR
    item AS LVITEMA
END TYPE

TYPE NMLVDISPINFOW
    hdr  AS NMHDR
    item AS LVITEMW
END TYPE

#IF %DEF(%UNICODE)
TYPE NMLVDISPINFO
    NMLVDISPINFOW
END TYPE
#ELSE
TYPE NMLVDISPINFO
    NMLVDISPINFOA
END TYPE
#ENDIF

%LVN_KEYDOWN          = %LVN_FIRST - 55

TYPE NMLVKEYDOWN BYTE
    hdr   AS NMHDR
    wVKey AS WORD
    flags AS DWORD
END TYPE

#IF (%WIN32_IE >= &H0300)
TYPE LV_KEYDOWN
    NMLVKEYDOWN
END TYPE
#ELSE
TYPE NMLVKEYDOWN
    LV_KEYDOWN
END TYPE
#ENDIF

#IF (%WIN32_IE >= &H0300)
TYPE LV_DISPINFOA
    NMLVDISPINFOA
END TYPE
TYPE LV_DISPINFOW
    NMLVDISPINFOW
END TYPE
#ELSE
TYPE NMLVDISPINFOA
    LV_DISPINFOA
END TYPE
TYPE NMLVDISPINFOW
    LV_DISPINFOW
END TYPE
#ENDIF

TYPE LV_DISPINFO
    NMLVDISPINFO
END TYPE

#IF (%WIN32_IE >= &H0300)
%LVN_MARQUEEBEGIN     = %LVN_FIRST - 56
#ENDIF

#IF %WIN32_WINNT >= &H0600
TYPE NMLVLINK
    hdr      AS NMHDR
    link     AS LITEM
    iItem    AS INTEGER
    iSubItem AS INTEGER
END TYPE
#ENDIF

#IF (%WIN32_IE >= &H0400)
TYPE NMLVGETINFOTIPA
    hdr        AS NMHDR
    dwFlags    AS DWORD
    pszText    AS ASCIIZ PTR
    cchTextMax AS LONG
    iItem      AS LONG
    iSubItem   AS LONG
    lParam     AS LONG
END TYPE

TYPE NMLVGETINFOTIPW
    hdr        AS NMHDR
    dwFlags    AS DWORD
    pszText    AS WSTRINGZ PTR
    cchTextMax AS LONG
    iItem      AS LONG
    iSubItem   AS LONG
    lParam     AS LONG
END TYPE

' NMLVGETINFOTIPA.dwFlag values

%LVGIT_UNFOLDED  = &H0001

%LVN_GETINFOTIPA       = %LVN_FIRST - 57
%LVN_GETINFOTIPW       = %LVN_FIRST - 58

#IF %DEF(%UNICODE)
TYPE NMLVGETINFOTIP
    NMLVGETINFOTIPW
END TYPE
%LVN_GETINFOTIP=%LVN_GETINFOTIPW
#ELSE
TYPE NMLVGETINFOTIP
    NMLVGETINFOTIPA
END TYPE
%LVN_GETINFOTIP=%LVN_GETINFOTIPA
#ENDIF

#ENDIF  ' %WIN32_IE >= &H0400

#IF (%WIN32_IE >= &H0500)

'
'  LVN_INCREMENTALSEARCH gives the app the opportunity to customize
'  incremental search.  For example, if the items are numeric,
'  the app can do numerical search instead of string search.
'
'  ListView notifies the app with NMLVFINDITEM.
'  The app sets pnmfi->lvfi.lParam to the result of the incremental search,
'  or to LVNSCH_DEFAULT if ListView should do the default search,
'  or to LVNSCH_ERROR to fail the search and just beep,
'  or to LVNSCH_IGNORE to stop all ListView processing.
'
'  The return value is not used.

%LVNSCH_DEFAULT = -1
%LVNSCH_ERROR   = -2
%LVNSCH_IGNORE  = -3

%LVN_INCREMENTALSEARCHA = %LVN_FIRST - 62
%LVN_INCREMENTALSEARCHW = %LVN_FIRST - 63

#IF %DEF(%UNICODE)
%LVN_INCREMENTALSEARCH=%LVN_INCREMENTALSEARCHW
#ELSE
%LVN_INCREMENTALSEARCH=%LVN_INCREMENTALSEARCHA
#ENDIF

#ENDIF      ' %WIN32_IE >= &H0500

#IF %WIN32_WINNT >= &H0600
%LVN_COLUMNDROPDOWN      = %LVN_FIRST - 64


%LVN_COLUMNOVERFLOWCLICK = %LVN_FIRST - 66

#ENDIF  ' %WIN32_WINNT >= &H0600

#IF %WIN32_WINNT >= &H0501
TYPE NMLVSCROLL
    hdr AS NMHDR
    dx  AS LONG
    dy  AS LONG
END TYPE

%LVN_BEGINSCROLL       = %LVN_FIRST - 80
%LVN_ENDSCROLL         = %LVN_FIRST - 81
#ENDIF

#IF %WIN32_WINNT >= &H0600
%LVN_LINKCLICK         = %LVN_FIRST - 84


%EMF_CENTERED          = &H00000001  ' render markup centered in the listview area

TYPE NMLVEMPTYMARKUP
    hdr      AS NMHDR
    ' out params from client back to listview
    dwFlags  AS DWORD                         ' EMF_*
    szMarkup AS WSTRINGZ * %L_MAX_URL_LENGTH  ' markup displayed
END TYPE

%LVN_GETEMPTYMARKUP    = %LVN_FIRST - 87
#ENDIF

#ENDIF  ' NOLISTVIEW

#INCLUDE "PrSht.inc"


'==============================================================================
' TREEVIEW CONTROL

#IF NOT %DEF(%NOTREEVIEW)

$WC_TREEVIEW        = "SysTreeView32"
$$WC_TREEVIEW       = "SysTreeView32"$$

#IF %DEF(%WIN32)
#IF %DEF(%UNICODE)
MACRO WC_TREEVIEW=$$WC_TREEVIEW
#ELSE
MACRO WC_TREEVIEW=$WC_TREEVIEW
#ENDIF
#ELSE
MACRO WC_TREEVIEW = "SysTreeView"
#ENDIF

' begin_r_commctrl

%TVS_HASBUTTONS      = &H00000001
%TVS_HASLINES        = &H00000002
%TVS_LINESATROOT     = &H00000004
%TVS_EDITLABELS      = &H00000008
%TVS_DISABLEDRAGDROP = &H00000010
%TVS_SHOWSELALWAYS   = &H00000020
%TVS_RTLREADING      = &H00000040
%TVS_NOTOOLTIPS      = &H00000080
%TVS_CHECKBOXES      = &H00000100
%TVS_TRACKSELECT     = &H00000200
%TVS_SINGLEEXPAND    = &H00000400
%TVS_INFOTIP         = &H00000800
%TVS_FULLROWSELECT   = &H00001000
%TVS_NOSCROLL        = &H00002000
%TVS_NONEVENHEIGHT   = &H00004000
%TVS_NOHSCROLL       = &H00008000  ' %TVS_NOSCROLL overrides this

' end_r_commctrl

%TVIF_TEXT           = &H0001
%TVIF_IMAGE          = &H0002
%TVIF_PARAM          = &H0004
%TVIF_STATE          = &H0008
%TVIF_HANDLE         = &H0010
%TVIF_SELECTEDIMAGE  = &H0020
%TVIF_CHILDREN       = &H0040
%TVIF_INTEGRAL       = &H0080

%TVIS_SELECTED       = &H0002
%TVIS_CUT            = &H0004
%TVIS_DROPHILITED    = &H0008
%TVIS_BOLD           = &H0010
%TVIS_EXPANDED       = &H0020
%TVIS_EXPANDEDONCE   = &H0040
%TVIS_EXPANDPARTIAL  = &H0080

%TVIS_OVERLAYMASK    = &H00F00
%TVIS_STATEIMAGEMASK = &H0F000
%TVIS_USERMASK       = &H0F000

#IF (%WIN32_IE >= &H0600)
%TVIS_EX_FLAT        = &H0001
#IF (%WIN32_WINNT >= &H0600)
%TVIS_EX_DISABLED    = &H0002
#ENDIF
%TVIS_EX_ALL         = &H0002

' Structure for TreeView's NM_TVSTATEIMAGECHANGING notification
TYPE NMTVSTATEIMAGECHANGING
    hdr                 AS NMHDR
    hti                 AS DWORD  ' HTREEITEM
    iOldStateImageIndex AS LONG
    iNewStateImageIndex AS LONG
END TYPE
#ENDIF  ' #IF (%WIN32_IE >= &H0600)

%I_CHILDRENCALLBACK  = -1

TYPE TVITEMA
    mask           AS DWORD
    hItem          AS DWORD   ' HTREEITEM
    STATE          AS DWORD
    stateMask      AS DWORD
    pszText        AS ASCIIZ PTR
    cchTextMax     AS LONG
    iImage         AS LONG
    iSelectedImage AS LONG
    cChildren      AS LONG
    lParam         AS LONG
END TYPE

TYPE TVITEMW
    mask           AS DWORD
    hItem          AS DWORD   ' HTREEITEM
    STATE          AS DWORD
    stateMask      AS DWORD
    pszText        AS WSTRINGZ PTR
    cchTextMax     AS LONG
    iImage         AS LONG
    iSelectedImage AS LONG
    cChildren      AS LONG
    lParam         AS LONG
END TYPE

#IF (%WIN32_IE >= &H0300)
TYPE TV_ITEMW
    TVITEMW
END TYPE
TYPE TV_ITEMA
    TVITEMA
END TYPE
#ELSE
TYPE TVITEMA
    TV_ITEMA
END TYPE
TYPE TVITEMW
    TV_ITEMW
END TYPE
#ENDIF

#IF (%WIN32_IE >= &H0400)

' only used for Get and Set messages.  no notifies

TYPE TVITEMEXA
    mask           AS DWORD
    hItem          AS DWORD
    STATE          AS DWORD
    stateMask      AS DWORD
    pszText        AS ASCIIZ PTR
    cchTextMax     AS LONG
    iImage         AS LONG
    iSelectedImage AS LONG
    cChildren      AS LONG
    lParam         AS LONG
    iIntegral      AS LONG
#IF (%WIN32_IE >= &H0600)
    uStateEx       AS DWORD
    hwnd           AS DWORD
    iExpandedImage AS LONG
#ENDIF
#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
    iReserved      AS LONG
#ENDIF
END TYPE

TYPE TVITEMEXW
    mask           AS DWORD
    hItem          AS DWORD
    STATE          AS DWORD
    stateMask      AS DWORD
    pszText        AS WSTRINGZ PTR
    cchTextMax     AS LONG
    iImage         AS LONG
    iSelectedImage AS LONG
    cChildren      AS LONG
    lParam         AS LONG
    iIntegral      AS LONG
#IF (%WIN32_IE >= &H0600)
    uStateEx       AS DWORD
    hwnd           AS DWORD
    iExpandedImage AS LONG
#ENDIF
#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
    iReserved      AS LONG
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
TYPE TVITEMEX
    TVITEMEXW
END TYPE
#ELSE
TYPE TVITEMEX
    TVITEMEXA
END TYPE
#ENDIF

#ENDIF  ' #IF (%WIN32_IE >= &H0400)

#IF %DEF(%UNICODE)
TYPE TVITEM
    TVITEMW
END TYPE
#ELSE
TYPE TVITEM
    TVITEMA
END TYPE
#ENDIF

TYPE TV_ITEM
    TVITEM
END TYPE

%TVI_ROOT               = &HFFFF0000???   '((HTREEITEM)(ULONG_PTR)-0x10000)
%TVI_FIRST              = &HFFFF0001???   '((HTREEITEM)(ULONG_PTR)-0x0FFFF)
%TVI_LAST               = &HFFFF0002???   '((HTREEITEM)(ULONG_PTR)-0x0FFFE)
%TVI_SORT               = &HFFFF0003???   '((HTREEITEM)(ULONG_PTR)-0x0FFFD)

%TVINSERTSTRUCTA_V1_SIZE = 48 ' CCSIZEOF_STRUCT(TVINSERTSTRUCTA, item)
%TVINSERTSTRUCTW_V1_SIZE = 48 ' CCSIZEOF_STRUCT(TVINSERTSTRUCTW, item)

UNION TVINSERTSTRUCTA_union
    itemex AS TVITEMEXA
    Item   AS TV_ITEMA
END UNION

TYPE TVINSERTSTRUCTA
    hParent      AS DWORD
    hInsertAfter AS DWORD
#IF (%WIN32_IE >= &H0400)
    TVINSERTSTRUCTA_union
#ELSE
    Item         AS TV_ITEMA
#ENDIF
END TYPE

UNION TVINSERTSTRUCTW_union
    itemex AS TVITEMEXW
    Item   AS TV_ITEMW
END UNION

TYPE TVINSERTSTRUCTW
    hParent      AS DWORD
    hInsertAfter AS DWORD
#IF (%WIN32_IE >= &H0400)
    TVINSERTSTRUCTW_union
#ELSE
    Item         AS TV_ITEMW
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
TYPE TVINSERTSTRUCT
    TVINSERTSTRUCTW
END TYPE
%TVINSERTSTRUCT_V1_SIZE = %TVINSERTSTRUCTW_V1_SIZE
#ELSE
TYPE TVINSERTSTRUCT
    TVINSERTSTRUCTA
END TYPE
%TVINSERTSTRUCT_V1_SIZE = %TVINSERTSTRUCTA_V1_SIZE
#ENDIF

#IF (%WIN32_IE >= &H0300)
TYPE TV_INSERTSTRUCTA
    TVINSERTSTRUCTA
END TYPE
TYPE TV_INSERTSTRUCTW
    TVINSERTSTRUCTW
END TYPE
#ELSE
TYPE TVINSERTSTRUCTA
    TV_INSERTSTRUCTA
END TYPE
TYPE TVINSERTSTRUCTW
    TV_INSERTSTRUCTW
END TYPE
#ENDIF

TYPE TV_INSERTSTRUCT
    TVINSERTSTRUCT
END TYPE

%TVM_INSERTITEMA        = %TV_FIRST
%TVM_INSERTITEMW        = %TV_FIRST + 50
#IF %DEF(%UNICODE)
%TVM_INSERTITEM = %TVM_INSERTITEMW
#ELSE
%TVM_INSERTITEM = %TVM_INSERTITEMA
#ENDIF

FUNCTION TreeView_InsertItem (BYVAL hWnd AS DWORD, lpis AS TV_INSERTSTRUCT) _
    AS DWORD
    FUNCTION = SendMessage(hWnd, %TVM_INSERTITEM, 0, VARPTR(lpis))
END FUNCTION

%TVM_DELETEITEM         = %TV_FIRST + 1

FUNCTION TreeView_DeleteItem (BYVAL hWnd AS DWORD, BYVAL hitem AS DWORD) AS LONG
    FUNCTION = SendMessage(hWnd, %TVM_DELETEITEM, 0, hitem)
END FUNCTION

FUNCTION TreeView_DeleteAllItems (BYVAL hWnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hWnd, %TVM_DELETEITEM, 0, %TVI_ROOT)
END FUNCTION

%TVM_EXPAND             = %TV_FIRST + 2

FUNCTION TreeView_Expand (BYVAL hWnd AS DWORD, BYVAL hitem AS DWORD, _
    BYVAL dFlag AS DWORD) AS LONG
    FUNCTION = SendMessage(hWnd, %TVM_EXPAND, dFlag, hitem)
END FUNCTION

%TVE_COLLAPSE           = &H00000001
%TVE_EXPAND             = &H00000002
%TVE_TOGGLE             = &H00000003
#IF (%WIN32_IE >= &H0300)
%TVE_EXPANDPARTIAL      = &H00004000
#ENDIF
%TVE_COLLAPSERESET      = &H00008000

%TVM_GETITEMRECT        = %TV_FIRST + 4

FUNCTION TreeView_GetItemRect (BYVAL hWnd AS DWORD, BYVAL hItem AS DWORD, _
    prc AS RECT, BYVAL CODE AS LONG) AS LONG
    prc.nLeft = hItem
    FUNCTION = SendMessage(hWnd, %TVM_GETITEMRECT, CODE, VARPTR(prc))
END FUNCTION

%TVM_GETCOUNT           = %TV_FIRST + 5

FUNCTION TreeView_GetCount (BYVAL hWnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hWnd, %TVM_GETCOUNT, 0, 0)
END FUNCTION

%TVM_GETINDENT          = %TV_FIRST + 6

FUNCTION TreeView_GetIndent (BYVAL hWnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hWnd, %TVM_GETINDENT, 0, 0)
END FUNCTION

%TVM_SETINDENT          = %TV_FIRST + 7

FUNCTION TreeView_SetIndent (BYVAL hWnd AS DWORD, BYVAL indent AS DWORD) AS LONG
    FUNCTION = SendMessage(hWnd, %TVM_SETINDENT, indent, 0)
END FUNCTION

%TVM_GETIMAGELIST       = %TV_FIRST + 8

FUNCTION TreeView_GetImageList (BYVAL hWnd AS DWORD, BYVAL iImage AS LONG) AS DWORD
    FUNCTION = SendMessage(hWnd, %TVM_GETIMAGELIST, iImage, 0)
END FUNCTION

%TVSIL_NORMAL           = 0
%TVSIL_STATE            = 2

%TVM_SETIMAGELIST       = %TV_FIRST + 9

FUNCTION TreeView_SetImageList (BYVAL hWnd AS DWORD, BYVAL himl AS DWORD, _
    BYVAL iImage AS LONG) AS DWORD
    FUNCTION = SendMessage(hWnd, %TVM_SETIMAGELIST, iImage, himl)
END FUNCTION

%TVM_GETNEXTITEM        = %TV_FIRST + 10

FUNCTION TreeView_GetNextItem (BYVAL hWnd AS DWORD, BYVAL hitem AS DWORD, _
    BYVAL CODE AS DWORD) AS DWORD
    FUNCTION = SendMessage(hWnd, %TVM_GETNEXTITEM, CODE, hitem)
END FUNCTION

%TVGN_ROOT              = &H0000
%TVGN_NEXT              = &H0001
%TVGN_PREVIOUS          = &H0002
%TVGN_PARENT            = &H0003
%TVGN_CHILD             = &H0004
%TVGN_FIRSTVISIBLE      = &H0005
%TVGN_NEXTVISIBLE       = &H0006
%TVGN_PREVIOUSVISIBLE   = &H0007
%TVGN_DROPHILITE        = &H0008
%TVGN_CARET             = &H0009
#IF (%WIN32_IE >= &H0400)
%TVGN_LASTVISIBLE       = &H000A
#ENDIF
#IF (%WIN32_IE >= &H0600)
%TVGN_NEXTSELECTED      = &H000B
#ENDIF

#IF (%WIN32_WINNT >= &H0501)
%TVSI_NOSINGLEEXPAND    = &H8000?? ' Should not conflict with TVGN flags.
#ENDIF

FUNCTION TreeView_GetChild (BYVAL hwnd AS DWORD, BYVAL hitem AS DWORD) AS DWORD
    FUNCTION = TreeView_GetNextItem(hwnd, hitem, %TVGN_CHILD)
END FUNCTION

FUNCTION TreeView_GetNextSibling (BYVAL hwnd AS DWORD, BYVAL hitem AS DWORD) _
    AS DWORD
    FUNCTION = TreeView_GetNextItem(hwnd, hitem, %TVGN_NEXT)
END FUNCTION

FUNCTION TreeView_GetPrevSibling (BYVAL hwnd AS DWORD, BYVAL hitem AS DWORD) _
    AS DWORD
    FUNCTION = TreeView_GetNextItem(hwnd, hitem, %TVGN_PREVIOUS)
END FUNCTION

FUNCTION TreeView_GetParent (BYVAL hwnd AS DWORD, BYVAL hitem AS DWORD) _
    AS DWORD
    FUNCTION = TreeView_GetNextItem(hwnd, hitem, %TVGN_PARENT)
END FUNCTION

FUNCTION TreeView_GetFirstVisible (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = TreeView_GetNextItem(hwnd, %NULL, %TVGN_FIRSTVISIBLE)
END FUNCTION

FUNCTION TreeView_GetNextVisible (BYVAL hwnd AS DWORD, BYVAL hitem AS DWORD) _
    AS DWORD
    FUNCTION = TreeView_GetNextItem(hwnd, hitem, %TVGN_NEXTVISIBLE)
END FUNCTION

FUNCTION TreeView_GetPrevVisible (BYVAL hwnd AS DWORD, BYVAL hitem AS DWORD) _
    AS DWORD
    FUNCTION = TreeView_GetNextItem(hwnd, hitem, %TVGN_PREVIOUSVISIBLE)
END FUNCTION

FUNCTION TreeView_GetSelection (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = TreeView_GetNextItem(hwnd, %NULL, %TVGN_CARET)
END FUNCTION

FUNCTION TreeView_GetDropHilight (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = TreeView_GetNextItem(hwnd, %NULL, %TVGN_DROPHILITE)
END FUNCTION

FUNCTION TreeView_GetRoot (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = TreeView_GetNextItem(hwnd, %NULL, %TVGN_ROOT)
END FUNCTION
#IF (%WIN32_IE >= &H0400)
FUNCTION TreeView_GetLastVisible (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = TreeView_GetNextItem(hwnd, %NULL, %TVGN_LASTVISIBLE)
END FUNCTION
#ENDIF
#IF (%WIN32_IE >= &H0600)
FUNCTION TreeView_GetNextSelected (BYVAL hwnd AS DWORD, hitem AS DWORD) AS DWORD
    FUNCTION = TreeView_GetNextItem(hwnd, hitem, %TVGN_NEXTSELECTED)
END FUNCTION
#ENDIF

%TVM_SELECTITEM         = %TV_FIRST + 11

FUNCTION TreeView_Select (BYVAL hwnd AS DWORD, BYVAL hitem AS DWORD, _
    BYVAL nCode AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %TVM_SELECTITEM, nCode, hitem)
END FUNCTION

FUNCTION TreeView_SelectItem (BYVAL hwnd AS DWORD, BYVAL hitem AS DWORD) AS LONG
    FUNCTION = TreeView_Select(hwnd, hitem, %TVGN_CARET)
END FUNCTION

FUNCTION TreeView_SelectDropTarget (BYVAL hwnd AS DWORD, _
    BYVAL hitem AS DWORD) AS LONG
    FUNCTION = TreeView_Select(hwnd, hitem, %TVGN_DROPHILITE)
END FUNCTION

FUNCTION TreeView_SelectSetFirstVisible (BYVAL hwnd AS DWORD, _
    BYVAL hitem AS DWORD) AS LONG
    FUNCTION = TreeView_Select(hwnd, hitem, %TVGN_FIRSTVISIBLE)
END FUNCTION

%TVM_GETITEMA           = %TV_FIRST + 12
%TVM_GETITEMW           = %TV_FIRST + 62

#IF %DEF(%UNICODE)
%TVM_GETITEM = %TVM_GETITEMW
#ELSE
%TVM_GETITEM = %TVM_GETITEMA
#ENDIF

FUNCTION TreeView_GetItem (BYVAL hwnd AS DWORD, pitem AS TV_ITEM) AS LONG
    FUNCTION = SendMessage(hwnd, %TVM_GETITEM, 0, VARPTR(pitem))
END FUNCTION

%TVM_SETITEMA           = %TV_FIRST + 13
%TVM_SETITEMW           = %TV_FIRST + 63

#IF %DEF(%UNICODE)
%TVM_SETITEM = %TVM_SETITEMW
#ELSE
%TVM_SETITEM = %TVM_SETITEMA
#ENDIF

FUNCTION TreeView_SetItem (BYVAL hwnd AS DWORD, pitem AS TV_ITEM) AS LONG
    FUNCTION = SendMessage(hwnd, %TVM_SETITEM, 0, VARPTR(pitem))
END FUNCTION

%TVM_EDITLABELA         = %TV_FIRST + 14
%TVM_EDITLABELW         = %TV_FIRST + 65

#IF %DEF(%UNICODE)
%TVM_EDITLABEL = %TVM_EDITLABELW
#ELSE
%TVM_EDITLABEL = %TVM_EDITLABELA
#ENDIF

FUNCTION TreeView_EditLabel (BYVAL hwnd AS DWORD, BYVAL hitem AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %TVM_EDITLABEL, 0, hitem)
END FUNCTION

%TVM_GETEDITCONTROL     = %TV_FIRST + 15

FUNCTION TreeView_GetEditControl (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %TVM_GETEDITCONTROL, 0, 0)
END FUNCTION

%TVM_GETVISIBLECOUNT    = %TV_FIRST + 16

FUNCTION TreeView_GetVisibleCount (BYVAL hWnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hWnd, %TVM_GETVISIBLECOUNT, 0, 0)
END FUNCTION

%TVM_HITTEST            = %TV_FIRST + 17

TYPE TVHITTESTINFO
    pt    AS POINT
    flags AS DWORD
    hItem AS DWORD  ' HTREEITEM
END TYPE

#IF (%WIN32_IE >= &H0300)
TYPE TV_HITTESTINFO
    TVHITTESTINFO
END TYPE
#ELSE
TYPE TVHITTESTINFO
    TV_HITTESTINFO
END TYPE
#ENDIF

FUNCTION TreeView_HitTest (BYVAL hwnd AS DWORD, lpht AS TV_HITTESTINFO) AS DWORD
    FUNCTION = SendMessage(hwnd, %TVM_HITTEST, 0, VARPTR(lpht))
END FUNCTION


%TVHT_NOWHERE           = &H0001
%TVHT_ONITEMICON        = &H0002
%TVHT_ONITEMLABEL       = &H0004
%TVHT_ONITEMINDENT      = &H0008
%TVHT_ONITEMBUTTON      = &H0010
%TVHT_ONITEMRIGHT       = &H0020
%TVHT_ONITEMSTATEICON   = &H0040

%TVHT_ABOVE             = &H0100
%TVHT_BELOW             = &H0200
%TVHT_TORIGHT           = &H0400
%TVHT_TOLEFT            = &H0800

%TVHT_ONITEM            = %TVHT_ONITEMICON OR %TVHT_ONITEMLABEL OR %TVHT_ONITEMSTATEICON

%TVM_CREATEDRAGIMAGE    = %TV_FIRST + 18

FUNCTION TreeView_CreateDragImage (BYVAL hwnd AS DWORD, BYVAL hitem AS DWORD) _
    AS DWORD
    FUNCTION = SendMessage(hwnd, %TVM_CREATEDRAGIMAGE, 0, hitem)
END FUNCTION

%TVM_SORTCHILDREN       = %TV_FIRST + 19

FUNCTION TreeView_SortChildren (BYVAL hwnd AS DWORD, BYVAL hitem AS DWORD, _
    BYVAL recurse AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %TVM_SORTCHILDREN, recurse, hitem)
END FUNCTION

%TVM_ENSUREVISIBLE      = %TV_FIRST + 20

FUNCTION TreeView_EnsureVisible (BYVAL hwnd AS DWORD, BYVAL hitem AS DWORD) _
    AS LONG
    FUNCTION = SendMessage(hwnd, %TVM_ENSUREVISIBLE, 0, hitem)
END FUNCTION

TYPE TVSORTCB
    hParent     AS DWORD  ' HTREEITEM
    lpfnCompare AS DWORD  ' PBNTVCOMPARE
    lParam      AS LONG   ' LPARAM
END TYPE

#IF (%WIN32_IE >= &H0300)
TYPE TV_SORTCB
    TVSORTCB
END TYPE
#ELSE
TYPE TVSORTCB
    TV_SORTCB
END TYPE
#ENDIF

%TVM_SORTCHILDRENCB     = %TV_FIRST + 21

FUNCTION TreeView_SortChildrenCB (BYVAL hwnd AS DWORD, psort AS TV_SORTCB, _
    recurse AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %TVM_SORTCHILDRENCB, recurse, VARPTR(psort))
END FUNCTION

%TVM_ENDEDITLABELNOW    = %TV_FIRST + 22

FUNCTION TreeView_EndEditLabelNow (BYVAL hwnd AS DWORD, _
    BYVAL fCancel AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %TVM_ENDEDITLABELNOW, fCancel, 0)
END FUNCTION

%TVM_GETISEARCHSTRINGA  = %TV_FIRST + 23
%TVM_GETISEARCHSTRINGW  = %TV_FIRST + 64

#IF %DEF(%UNICODE)
%TVM_GETISEARCHSTRING = %TVM_GETISEARCHSTRINGW
#ELSE
%TVM_GETISEARCHSTRING = %TVM_GETISEARCHSTRINGA
#ENDIF

FUNCTION TreeView_GetISearchStringA (BYVAL hwndTV AS DWORD, lpsz AS ASCIIZ) AS LONG
    FUNCTION = SendMessage(hwndTV, %TVM_GETISEARCHSTRINGA, 0, VARPTR(lpsz))
END FUNCTION

FUNCTION TreeView_GetISearchStringW (BYVAL hwndTV AS DWORD, lpsz AS WSTRINGZ) AS LONG
    FUNCTION = SendMessage(hwndTV, %TVM_GETISEARCHSTRINGW, 0, VARPTR(lpsz))
END FUNCTION

#IF %DEF(%UNICODE)
FUNCTION TreeView_GetISearchString (BYVAL hwndTV AS DWORD, lpsz AS WSTRINGZ) AS LONG
    FUNCTION = SendMessage(hwndTV, %TVM_GETISEARCHSTRINGW, 0, VARPTR(lpsz))
END FUNCTION
#ELSE
FUNCTION TreeView_GetISearchString (BYVAL hwndTV AS DWORD, lpsz AS ASCIIZ) AS LONG
    FUNCTION = SendMessage(hwndTV, %TVM_GETISEARCHSTRINGA, 0, VARPTR(lpsz))
END FUNCTION
#ENDIF

#IF (%WIN32_IE >= &H0300)
%TVM_SETTOOLTIPS        = %TV_FIRST + 24

FUNCTION TreeView_SetToolTips (BYVAL hwnd AS DWORD, BYVAL hwndTT AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %TVM_SETTOOLTIPS, hwndTT, 0)
END FUNCTION

%TVM_GETTOOLTIPS        = %TV_FIRST + 25

FUNCTION TreeView_GetToolTips (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %TVM_GETTOOLTIPS, 0, 0)
END FUNCTION

#ENDIF  ' #IF (%WIN32_IE >= &H0300)


#IF (%WIN32_IE >= &H0400)
%TVM_SETINSERTMARK      = %TV_FIRST + 26

FUNCTION TreeView_SetInsertMark (BYVAL hwnd AS DWORD, BYVAL hItem AS DWORD, _
    BYVAL fAfter AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %TVM_SETINSERTMARK, fAfter, hItem)
END FUNCTION

%TVM_SETUNICODEFORMAT   = %CCM_SETUNICODEFORMAT

FUNCTION TreeView_SetUnicodeFormat (BYVAL hwnd AS DWORD, _
    BYVAL fUnicode AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %TVM_SETUNICODEFORMAT, fUnicode, 0)
END FUNCTION

%TVM_GETUNICODEFORMAT   = %CCM_GETUNICODEFORMAT

FUNCTION TreeView_GetUnicodeFormat (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %TVM_GETUNICODEFORMAT, 0, 0)
END FUNCTION

%TVM_SETITEMHEIGHT      = %TV_FIRST + 27

FUNCTION TreeView_SetItemHeight (BYVAL hwnd AS DWORD, iHeight AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %TVM_SETITEMHEIGHT, iHeight, 0)
END FUNCTION

%TVM_GETITEMHEIGHT      = %TV_FIRST + 28

FUNCTION TreeView_GetItemHeight (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %TVM_GETITEMHEIGHT, 0, 0)
END FUNCTION

%TVM_SETBKCOLOR         = %TV_FIRST + 29

FUNCTION TreeView_SetBkColor (BYVAL hwnd AS DWORD, BYVAL clr AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %TVM_SETBKCOLOR, 0, clr)
END FUNCTION

%TVM_SETTEXTCOLOR       = %TV_FIRST + 30

FUNCTION TreeView_SetTextColor (BYVAL hwnd AS DWORD, BYVAL clr AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %TVM_SETTEXTCOLOR, 0, clr)
END FUNCTION

%TVM_GETBKCOLOR         = %TV_FIRST + 31

FUNCTION TreeView_GetBkColor (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %TVM_GETBKCOLOR, 0, 0)
END FUNCTION

%TVM_GETTEXTCOLOR       = %TV_FIRST + 32

FUNCTION TreeView_GetTextColor (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %TVM_GETTEXTCOLOR, 0, 0)
END FUNCTION

%TVM_SETSCROLLTIME      = %TV_FIRST + 33

FUNCTION TreeView_SetScrollTime (BYVAL hwnd AS DWORD, BYVAL uTime AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %TVM_SETSCROLLTIME, uTime, 0)
END FUNCTION

%TVM_GETSCROLLTIME      = %TV_FIRST + 34

FUNCTION TreeView_GetScrollTime (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %TVM_GETSCROLLTIME, 0, 0)
END FUNCTION

%TVM_SETINSERTMARKCOLOR = %TV_FIRST + 37

FUNCTION TreeView_SetInsertMarkColor (BYVAL hwnd AS DWORD, _
    BYVAL clr AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %TVM_SETINSERTMARKCOLOR, 0, clr)
END FUNCTION

%TVM_GETINSERTMARKCOLOR = %TV_FIRST + 38

FUNCTION TreeView_GetInsertMarkColor (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %TVM_GETINSERTMARKCOLOR, 0, 0)
END FUNCTION

#ENDIF  ' #IF (%WIN32_IE >= &H0400)

#IF (%WIN32_IE >= &H0500)
' tvm_?etitemstate only uses mask, state and stateMask.
' so unicode or ansi is irrelevant.
FUNCTION TreeView_SetItemState (BYVAL hwndTV AS DWORD, BYVAL hti AS DWORD, _
    BYVAL nSTATE AS DWORD, BYVAL nstatemask AS DWORD) AS DWORD
    LOCAL ms_TVi AS TVITEM
    ms_TVi.mask  = %TVIF_STATE
    ms_TVi.hItem = hti
    ms_TVi.stateMask = nstatemask
    ms_TVi.state = nSTATE
    SendMessage hwndTV, %TVM_SETITEM, 0, VARPTR(ms_TVi)
    ' the return value is not used
END FUNCTION

#IF NOT %DEF(%ITSIM)
    %ITSIM = 1
    MACRO IndexToStateImageMask(i)=((i)*4096)
#ENDIF

FUNCTION TreeView_SetCheckState (BYVAL hwndTV AS DWORD, BYVAL hti AS DWORD, _
    BYVAL fCheck AS LONG) AS DWORD
    FUNCTION = TreeView_SetItemState(hwndTV, hti, _
        IndexToStateImageMask(IIF&(fCheck, 2, 1)), %TVIS_STATEIMAGEMASK)
END FUNCTION

%TVM_GETITEMSTATE = %TV_FIRST + 39

FUNCTION TreeView_GetItemState (BYVAL hwndTV AS DWORD, BYVAL hti AS DWORD, _
    BYVAL mask AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwndTV, %TVM_GETITEMSTATE, hti, mask)
END FUNCTION

' [Despite this returning a DWORD, Microsoft documents one of the return
'  values as being -1. What they mean is &HFFFFFFFF???, not &HFFFFFFFF&.]
FUNCTION TreeView_GetCheckState (BYVAL hwndTV AS DWORD, BYVAL hti AS DWORD) _
    AS DWORD
    LOCAL dTmp AS LONG
    dTmp = %TVIS_STATEIMAGEMASK
    SHIFT RIGHT dTmp, 12
    DECR dTmp
    FUNCTION = SendMessage(hwndTV, %TVM_GETITEMSTATE, hti, dTmp)
END FUNCTION

%TVM_SETLINECOLOR = %TV_FIRST + 40

FUNCTION TreeView_SetLineColor (BYVAL hwnd AS DWORD, BYVAL clr AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %TVM_SETLINECOLOR, 0, clr)
END FUNCTION

%TVM_GETLINECOLOR = %TV_FIRST + 41

FUNCTION TreeView_GetLineColor (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %TVM_GETLINECOLOR, 0, 0)
END FUNCTION

#ENDIF  ' #IF (%WIN32_IE >= &H0500)

#IF (%WIN32_WINNT >= &H0501)
%TVM_MAPACCIDTOHTREEITEM   = (%TV_FIRST + 42)
FUNCTION TreeView_MapAccIDToHTREEITEM (BYVAL hwnd AS DWORD, BYVAL nid AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %TVM_MAPACCIDTOHTREEITEM, nid, 0)
END FUNCTION

%TVM_MAPHTREEITEMTOACCID   = (%TV_FIRST + 43)
FUNCTION TreeView_MapHTREEITEMToAccID (BYVAL hwnd AS DWORD, _
    BYVAL htreeitem AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %TVM_MAPHTREEITEMTOACCID, htreeitem, 0)
END FUNCTION

%TVM_SETEXTENDEDSTYLE    = (%TV_FIRST + 44)
FUNCTION TreeView_SetExtendedStyle (BYVAL hwnd AS DWORD, BYVAL dwd AS DWORD, _
    BYVAL mask AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %TVM_SETEXTENDEDSTYLE, mask, dwd)
END FUNCTION

%TVM_GETEXTENDEDSTYLE    = (%TV_FIRST + 45)
FUNCTION TreeView_GetExtendedStyle (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %TVM_GETEXTENDEDSTYLE, 0, 0)
END FUNCTION


%TVM_SETAUTOSCROLLINFO  = (%TV_FIRST + 59)
FUNCTION TreeView_SetAutoScrollInfo (BYVAL hwnd AS DWORD, _
    BYVAL uPixPerSec AS DWORD, BYVAL uUpdateTime AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %TVM_SETAUTOSCROLLINFO, uPixPerSec, uUpdateTime)
END FUNCTION
#ENDIF  ' #IF (%WIN32_WINNT >= &H0501)


#IF (%WIN32_WINNT >= &H0600)
%TVM_GETSELECTEDCOUNT     = (%TV_FIRST + 70)
FUNCTION TreeView_GetSelectedCount (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %TVM_GETSELECTEDCOUNT, 0, 0)
END FUNCTION

%TVM_SHOWINFOTIP          = (%TV_FIRST + 71)
FUNCTION TreeView_ShowInfoTip (BYVAL hwnd AS DWORD, BYVAL hitem AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %TVM_SHOWINFOTIP, 0, hitem)
END FUNCTION

MACRO TVITEMPART_enum=LONG
ENUM TVITEMPART SINGULAR
    TVGIPR_BUTTON  = &H0001
END ENUM

TYPE TVGETITEMPARTRECTINFO
    hti    AS DWORD  ' HTREEITEM
    prc    AS RECT PTR
    partID AS TVITEMPART_enum
END TYPE

%TVM_GETITEMPARTRECT       = (%TV_FIRST + 72)
FUNCTION TreeView_GetItemPartRect (BYVAL hwnd AS DWORD, BYVAL hitem AS DWORD, _
    prc AS RECT, BYVAL partid AS TVITEMPART_enum) AS LONG
    LOCAL info AS TVGETITEMPARTRECTINFO
    info.hti    = hitem
    info.prc    = VARPTR(prc)
    info.partID = partid
    FUNCTION = SendMessage(hwnd, %TVM_GETITEMPARTRECT, 0, VARPTR(info))
END FUNCTION

#ENDIF  ' #IF (%WIN32_WINNT >= &H0600)

DECLARE FUNCTION PFNTVCOMPARE(BYVAL lParam1 AS LONG, BYVAL lparam2 AS LONG, _
    BYVAL lParamSort AS LONG) AS LONG

TYPE NMTREEVIEWA
    hdr     AS NMHDR
    action  AS DWORD
    itemOld AS TVITEMA
    itemNew AS TVITEMA
    ptDrag  AS POINT
END TYPE

TYPE NMTREEVIEWW
    hdr     AS NMHDR
    action  AS DWORD
    itemOld AS TVITEMW
    itemNew AS TVITEMW
    ptDrag  AS POINT
END TYPE

#IF %DEF(%UNICODE)
TYPE NMTREEVIEW
    NMTREEVIEWW
END TYPE
#ELSE
TYPE NMTREEVIEW
    NMTREEVIEWW
END TYPE
#ENDIF

#IF (%WIN32_IE >= &H0300)
TYPE NM_TREEVIEWW
    NMTREEVIEWW
END TYPE
TYPE NM_TREEVIEWA
    NMTREEVIEWA
END TYPE
#ELSE
TYPE NMTREEVIEWW
    NM_TREEVIEWW
END TYPE
TYPE NMTREEVIEWA
    NM_TREEVIEWA
END TYPE
#ENDIF

TYPE NM_TREEVIEW
    NMTREEVIEW
END TYPE

%TVN_SELCHANGINGA       = %TVN_FIRST - 1
%TVN_SELCHANGINGW       = %TVN_FIRST - 50
%TVN_SELCHANGEDA        = %TVN_FIRST - 2
%TVN_SELCHANGEDW        = %TVN_FIRST - 51

%TVC_UNKNOWN            = &H0000
%TVC_BYMOUSE            = &H0001
%TVC_BYKEYBOARD         = &H0002

%TVN_GETDISPINFOA       = %TVN_FIRST - 3
%TVN_GETDISPINFOW       = %TVN_FIRST - 52
%TVN_SETDISPINFOA       = %TVN_FIRST - 4
%TVN_SETDISPINFOW       = %TVN_FIRST - 53

%TVIF_DI_SETITEM        = &H1000

TYPE NMTVDISPINFOA
    hdr  AS NMHDR
    ITEM AS TVITEMA
END TYPE

TYPE NMTVDISPINFOW
    hdr  AS NMHDR
    ITEM AS TVITEMW
END TYPE

#IF %DEF(%UNICODE)
TYPE NMTVDISPINFO
    NMTVDISPINFOW
END TYPE
#ELSE
TYPE NMTVDISPINFO
    NMTVDISPINFOA
END TYPE
#ENDIF

#IF (%WIN32_IE >= &H0300)
TYPE TV_DISPINFOA
    NMTVDISPINFOA
END TYPE
TYPE TV_DISPINFOW
    NMTVDISPINFOW
END TYPE
#ELSE
TYPE NMTVDISPINFOA
    TV_DISPINFOA
END TYPE
TYPE NMTVDISPINFOW
    TV_DISPINFOW
END TYPE
#ENDIF

TYPE TV_DISPINFO
    NMTVDISPINFO
END TYPE

#IF (%WIN32_IE >= &H0600)

TYPE NMTVDISPINFOEXA
    hdr  AS NMHDR
    ITEM AS TVITEMEXA
END TYPE

TYPE NMTVDISPINFOEXW
    hdr  AS NMHDR
    ITEM AS TVITEMEXW
END TYPE

#IF %DEF(%UNICODE)
TYPE NMTVDISPINFOEX
    NMTVDISPINFOEXW
END TYPE
#ELSE
TYPE NMTVDISPINFOEX
    NMTVDISPINFOEXA
END TYPE
#ENDIF

TYPE TV_DISPINFOEXA
    NMTVDISPINFOEXA
END TYPE
TYPE TV_DISPINFOEXW
    NMTVDISPINFOEXW
END TYPE
TYPE TV_DISPINFOEX
    NMTVDISPINFOEX
END TYPE

#ENDIF  ' #IF (%WIN32_IE >= &H0600)

%TVN_ITEMEXPANDINGA     = %TVN_FIRST - 5
%TVN_ITEMEXPANDINGW     = %TVN_FIRST - 54
%TVN_ITEMEXPANDEDA      = %TVN_FIRST - 6
%TVN_ITEMEXPANDEDW      = %TVN_FIRST - 55
%TVN_BEGINDRAGA         = %TVN_FIRST - 7
%TVN_BEGINDRAGW         = %TVN_FIRST - 56
%TVN_BEGINRDRAGA        = %TVN_FIRST - 8
%TVN_BEGINRDRAGW        = %TVN_FIRST - 57
%TVN_DELETEITEMA        = %TVN_FIRST - 9
%TVN_DELETEITEMW        = %TVN_FIRST - 58
%TVN_BEGINLABELEDITA    = %TVN_FIRST - 10
%TVN_BEGINLABELEDITW    = %TVN_FIRST - 59
%TVN_ENDLABELEDITA      = %TVN_FIRST - 11
%TVN_ENDLABELEDITW      = %TVN_FIRST - 60
%TVN_KEYDOWN            = %TVN_FIRST - 12

#IF (%WIN32_IE >= &H0400)
%TVN_GETINFOTIPA        = %TVN_FIRST - 13
%TVN_GETINFOTIPW        = %TVN_FIRST - 14
%TVN_SINGLEEXPAND       = %TVN_FIRST - 15

%TVNRET_DEFAULT = 0
%TVNRET_SKIPOLD = 1
%TVNRET_SKIPNEW = 2
#ENDIF  ' #IF (%WIN32_IE >= &H0400)

#IF (%WIN32_IE >= &H0600)
%TVN_ITEMCHANGINGA      = (%TVN_FIRST-16)
%TVN_ITEMCHANGINGW      = (%TVN_FIRST-17)
%TVN_ITEMCHANGEDA       = (%TVN_FIRST-18)
%TVN_ITEMCHANGEDW       = (%TVN_FIRST-19)
%TVN_ASYNCDRAW          = (%TVN_FIRST-20)
#ENDIF

TYPE NMTVKEYDOWN BYTE
    hdr   AS NMHDR
    wVKey AS WORD
    flags AS DWORD
END TYPE

#IF (%WIN32_IE >= &H0300)
TYPE TV_KEYDOWN
    NMTVKEYDOWN
END TYPE
#ELSE
TYPE NMTVKEYDOWN
    TV_KEYDOWN
END TYPE
#ENDIF

#IF %DEF(%UNICODE)
%TVN_SELCHANGING       = %TVN_SELCHANGINGW
%TVN_SELCHANGED        = %TVN_SELCHANGEDW
%TVN_GETDISPINFO       = %TVN_GETDISPINFOW
%TVN_SETDISPINFO       = %TVN_SETDISPINFOW
%TVN_ITEMEXPANDING     = %TVN_ITEMEXPANDINGW
%TVN_ITEMEXPANDED      = %TVN_ITEMEXPANDEDW
%TVN_BEGINDRAG         = %TVN_BEGINDRAGW
%TVN_BEGINRDRAG        = %TVN_BEGINRDRAGW
%TVN_DELETEITEM        = %TVN_DELETEITEMW
%TVN_BEGINLABELEDIT    = %TVN_BEGINLABELEDITW
%TVN_ENDLABELEDIT      = %TVN_ENDLABELEDITW
#ELSE
%TVN_SELCHANGING       = %TVN_SELCHANGINGA
%TVN_SELCHANGED        = %TVN_SELCHANGEDA
%TVN_GETDISPINFO       = %TVN_GETDISPINFOA
%TVN_SETDISPINFO       = %TVN_SETDISPINFOA
%TVN_ITEMEXPANDING     = %TVN_ITEMEXPANDINGA
%TVN_ITEMEXPANDED      = %TVN_ITEMEXPANDEDA
%TVN_BEGINDRAG         = %TVN_BEGINDRAGA
%TVN_BEGINRDRAG        = %TVN_BEGINRDRAGA
%TVN_DELETEITEM        = %TVN_DELETEITEMA
%TVN_BEGINLABELEDIT    = %TVN_BEGINLABELEDITA
%TVN_ENDLABELEDIT      = %TVN_ENDLABELEDITA
#ENDIF

#IF (%WIN32_IE >= &H0300)
%NMTVCUSTOMDRAW_V3_SIZE = 48 + 2 * 4 ' CCSIZEOF_STRUCT(NMTVCUSTOMDRAW, clrTextBk)

TYPE NMTVCUSTOMDRAW
    nmcd      AS NMCUSTOMDRAW
    clrText   AS COLORREF
    clrTextBk AS COLORREF
#IF (%WIN32_IE >= &H0400)
    iLevel    AS LONG
#ENDIF
END TYPE
#ENDIF  ' #IF (%WIN32_IE >= &H0300)

#IF (%WIN32_IE >= &H0400)

' for tooltips

TYPE NMTVGETINFOTIPA
    hdr        AS NMHDR
    pszText    AS ASCIIZ PTR
    cchTextMax AS LONG
    hItem      AS DWORD   ' HTREEITEM
    lParam     AS LONG    ' LPARAM
END TYPE

TYPE NMTVGETINFOTIPW
    hdr        AS NMHDR
    pszText    AS WSTRINGZ PTR
    cchTextMax AS LONG
    hItem      AS DWORD   ' HTREEITEM
    lParam     AS LONG    ' LPARAM
END TYPE

#IF %DEF(%UNICODE)
%TVN_GETINFOTIP = %TVN_GETINFOTIPW
TYPE NMTVGETINFOTIP
    NMTVGETINFOTIPW
END TYPE
#ELSE
%TVN_GETINFOTIP = %TVN_GETINFOTIPA
TYPE NMTVGETINFOTIP
    NMTVGETINFOTIPA
END TYPE
#ENDIF

' treeview's customdraw return meaning don't draw images.
' valid on CDRF_NOTIFYITEMPREPAINT
%TVCDRF_NOIMAGES        = &H00010000

#ENDIF      ' %WIN32_IE >= &H0400

#IF (%WIN32_IE > &H0600)

TYPE NMTVITEMCHANGE
    hdr       AS NMHDR
    uChanged  AS DWORD
    hItem     AS DWORD   ' HTREEITEM
    uStateNew AS DWORD
    uStateOld AS DWORD
    lParam    AS LONG    ' LPARAM
END TYPE

TYPE NMTVASYNCDRAW
    hdr       AS NMHDR
    pimldp    AS IMAGELISTDRAWPARAMS PTR  ' the draw that failed
    hr        AS LONG     ' HRESULT         why it failed
    hItem     AS DWORD    ' HTREEITEM       item that failed to draw icon
    lParam    AS LONG                     ' its data
    ' Out Params
    dwRetFlags AS DWORD           ' What listview should do on return
    iRetImageIndex AS LONG        ' used if ADRF_DRAWIMAGE is returned
END TYPE

#IF %DEF(%UNICODE)
%TVN_ITEMCHANGING     = %TVN_ITEMCHANGINGW
%TVN_ITEMCHANGED      = %TVN_ITEMCHANGEDW
#ELSE
%TVN_ITEMCHANGING     = %TVN_ITEMCHANGINGA
%TVN_ITEMCHANGED      = %TVN_ITEMCHANGEDA
#ENDIF

#ENDIF      ' %WIN32_IE >= &H0600

#ENDIF  ' NOTREEVIEW



'==============================================================================
' COMBOBOXEX Control

#IF (%WIN32_IE >= &H0300)
#IF NOT %DEF(%NOUSEREXCONTROLS)

$WC_COMBOBOXEX       = "ComboBoxEx32"
$$WC_COMBOBOXEX      = "ComboBoxEx32"$$

#IF %DEF(%UNICODE)
MACRO WC_COMBOBOXEX  = $$WC_COMBOBOXEX
#ELSE
MACRO WC_COMBOBOXEX  = $WC_COMBOBOXEX
#ENDIF

%CBEIF_TEXT          = &H00000001
%CBEIF_IMAGE         = &H00000002
%CBEIF_SELECTEDIMAGE = &H00000004
%CBEIF_OVERLAY       = &H00000008
%CBEIF_INDENT        = &H00000010
%CBEIF_LPARAM        = &H00000020

%CBEIF_DI_SETITEM    = &H10000000

TYPE COMBOBOXEXITEMA
    mask           AS DWORD
    iItem          AS LONG
    pszText        AS ASCIIZ PTR
    cchTextMax     AS LONG
    iImage         AS LONG
    iSelectedImage AS LONG
    iOverlay       AS LONG
    iIndent        AS LONG
    lParam         AS LONG
END TYPE

TYPE COMBOBOXEXITEMW
    mask           AS DWORD
    iItem          AS LONG
    pszText        AS WSTRINGZ PTR
    cchTextMax     AS LONG
    iImage         AS LONG
    iSelectedImage AS LONG
    iOverlay       AS LONG
    iIndent        AS LONG
    lParam         AS LONG
END TYPE

#IF %DEF(%UNICODE)
TYPE COMBOBOXEXITEM
    COMBOBOXEXITEMW
END TYPE
#ELSE
TYPE COMBOBOXEXITEM
    COMBOBOXEXITEMA
END TYPE
#ENDIF

%CBEM_INSERTITEMA       = %WM_USER + 1
%CBEM_SETIMAGELIST      = %WM_USER + 2
%CBEM_GETIMAGELIST      = %WM_USER + 3
%CBEM_GETITEMA          = %WM_USER + 4
%CBEM_SETITEMA          = %WM_USER + 5
%CBEM_DELETEITEM        = %CB_DELETESTRING
%CBEM_GETCOMBOCONTROL   = %WM_USER + 6
%CBEM_GETEDITCONTROL    = %WM_USER + 7
%CBEM_SETEXSTYLE        = %WM_USER + 8     ' use  SETEXTENDEDSTYLE instead
%CBEM_SETEXTENDEDSTYLE  = %WM_USER + 14    ' lparam == new style, wParam(optional) == mask
%CBEM_GETEXSTYLE        = %WM_USER + 9     ' use GETEXTENDEDSTYLE instead
%CBEM_GETEXTENDEDSTYLE  = %WM_USER + 9
%CBEM_SETUNICODEFORMAT  = %CCM_SETUNICODEFORMAT
%CBEM_GETUNICODEFORMAT  = %CCM_GETUNICODEFORMAT
%CBEM_HASEDITCHANGED    = %WM_USER + 10
%CBEM_INSERTITEMW       = %WM_USER + 11
%CBEM_SETITEMW          = %WM_USER + 12
%CBEM_GETITEMW          = %WM_USER + 13

#IF %DEF(%unicode)
%CBEM_INSERTITEM        = %CBEM_INSERTITEMW
%CBEM_SETITEM           = %CBEM_SETITEMW
%CBEM_GETITEM           = %CBEM_GETITEMW
#ELSE
%CBEM_INSERTITEM        = %CBEM_INSERTITEMA
%CBEM_SETITEM           = %CBEM_SETITEMA
%CBEM_GETITEM           = %CBEM_GETITEMA
#ENDIF

#IF (%WIN32_WINNT >= &H0501)
%CBEM_SETWINDOWTHEME    = %CCM_SETWINDOWTHEME
#ENDIF

%CBES_EX_NOEDITIMAGE         = &H00000001
%CBES_EX_NOEDITIMAGEINDENT   = &H00000002
%CBES_EX_PATHWORDBREAKPROC   = &H00000004
#IF (%WIN32_IE >= &H0400)
%CBES_EX_NOSIZELIMIT         = &H00000008
%CBES_EX_CASESENSITIVE       = &H00000010
#IF (%WIN32_WINNT >= &H0600)
%CBES_EX_TEXTENDELLIPSIS     = &H00000020
#ENDIF

TYPE NMCOMBOBOXEXA
    hdr    AS NMHDR
    ceItem AS COMBOBOXEXITEMA
END TYPE

TYPE NMCOMBOBOXEXW
    hdr    AS NMHDR
    ceItem AS COMBOBOXEXITEMW
END TYPE

%CBEN_GETDISPINFOA = %CBEN_FIRST - 0
%CBEN_GETDISPINFOW = %CBEN_FIRST - 7

#IF %DEF(%UNICODE)
TYPE NMCOMBOBOXEX
    NMCOMBOBOXEXW
END TYPE
%CBEN_GETDISPINFO = %CBEN_GETDISPINFOW
#ELSE
TYPE NMCOMBOBOXEX
    NMCOMBOBOXEXA
END TYPE
%CBEN_GETDISPINFO = %CBEN_GETDISPINFOA
#ENDIF

#ELSE

TYPE NMCOMBOBOXEX
    hdr    AS NMHDR
    ceItem AS COMBOBOXEXITEM
END IF

#ENDIF
%CBEN_INSERTITEM   = %CBEN_FIRST - 1
%CBEN_DELETEITEM   = %CBEN_FIRST - 2
%CBEN_BEGINEDIT    = %CBEN_FIRST - 4
%CBEN_ENDEDITA     = %CBEN_FIRST - 5
%CBEN_ENDEDITW     = %CBEN_FIRST - 6

#IF (%WIN32_IE >= &H0400)
%CBEN_DRAGBEGINA   = %CBEN_FIRST - 8
%CBEN_DRAGBEGINW   = %CBEN_FIRST - 9

#IF %DEF(%UNICODE)
%CBEN_DRAGBEGIN = %CBEN_DRAGBEGINW
#ELSE
%CBEN_DRAGBEGIN = %CBEN_DRAGBEGINA
#ENDIF

#ENDIF  ' #IF (%WIN32_IE >= &H0400)

#IF %DEF(%UNICODE)
%CBEN_ENDEDIT = %CBEN_ENDEDITW
#ELSE
%CBEN_ENDEDIT = %CBEN_ENDEDITA
#ENDIF

%CBENF_KILLFOCUS   = 1
%CBENF_RETURN      = 2
%CBENF_ESCAPE      = 3
%CBENF_DROPDOWN    = 4

%CBEMAXSTRLEN = 260

#IF (%WIN32_IE >= &H0400)
' CBEN_DRAGBEGIN sends this information ...

TYPE NMCBEDRAGBEGINW
    hdr     AS NMHDR
    iItemid AS LONG
    szText  AS WSTRINGZ * %CBEMAXSTRLEN
END TYPE

TYPE NMCBEDRAGBEGINA
    hdr     AS NMHDR
    iItemid AS LONG
    szText  AS ASCIIZ * %CBEMAXSTRLEN
END TYPE

#IF %DEF(%UNICODE)
TYPE NMCBEDGRAGBEGIN
    NMCBEDRAGBEGINW
END TYPE
#ELSE
TYPE NMCBEDGRAGBEGIN
    NMCBEDRAGBEGINA
END TYPE
#ENDIF

#ENDIF  ' #IF (%WIN32_IE >= &H0400)

' CBEN_ENDEDIT sends this information...
' fChanged if the user actually did anything
' iNewSelection gives what would be the new selection unless the notify failed
'                      iNewSelection may be CB_ERR if there's no match
TYPE NMCBEENDEDITW
    hdr           AS NMHDR
    fChanged      AS LONG
    iNewSelection AS LONG
    szText        AS WSTRINGZ * %CBEMAXSTRLEN
    iWhy          AS LONG
END TYPE

TYPE NMCBEENDEDITA
    hdr           AS NMHDR
    fChanged      AS LONG
    iNewSelection AS LONG
    szText        AS ASCIIZ * %CBEMAXSTRLEN
    iWhy          AS LONG
END TYPE

#IF %DEF(%UNICODE)
TYPE NMCBEENDEDIT
    NMCBEENDEDITW
END TYPE
#ELSE
TYPE NMCBEENDEDIT
    NMCBEENDEDITA
END TYPE
#ENDIF

#ENDIF  ' #IF NOT %DEF(%NOUSEREXCONTROLS)
#ENDIF  ' #IF (%WIN32_IE >= &H0300)



'==============================================================================
' TAB CONTROL

#IF NOT %DEF(%NOTABCONTROL)

#IF %DEF(%WIN32)

$WC_TABCONTROLA          = "SysTabControl32"
$$WC_TABCONTROLW         = "SysTabControl32"$$

#IF %DEF(%UNICODE)
MACRO WC_TABCONTROL      = $$WC_TABCONTROLW
#ELSE
MACRO WC_TABCONTROL      = $WC_TABCONTROLA
#ENDIF

#ELSE
MACRO WC_TABCONTROL      = "SysTabControl"
#ENDIF

' begin_r_commctrl

#IF (%WIN32_IE >= &H0300)
%TCS_SCROLLOPPOSITE      = &H00000001  ' assumes multiline tab
%TCS_BOTTOM              = &H00000002
%TCS_RIGHT               = &H00000002
%TCS_MULTISELECT         = &H00000004  ' allow multi-select in button mode
#ENDIF
#IF (%WIN32_IE >= &H0400)
%TCS_FLATBUTTONS         = &H00000008
#ENDIF
%TCS_FORCEICONLEFT       = &H00000010
%TCS_FORCELABELLEFT      = &H00000020
#IF (%WIN32_IE >= &H0300)
%TCS_HOTTRACK            = &H00000040
%TCS_VERTICAL            = &H00000080
#ENDIF
%TCS_TABS                = &H00000000
%TCS_BUTTONS             = &H00000100
%TCS_SINGLELINE          = &H00000000
%TCS_MULTILINE           = &H00000200
%TCS_RIGHTJUSTIFY        = &H00000000
%TCS_FIXEDWIDTH          = &H00000400
%TCS_RAGGEDRIGHT         = &H00000800
%TCS_FOCUSONBUTTONDOWN   = &H00001000
%TCS_OWNERDRAWFIXED      = &H00002000
%TCS_TOOLTIPS            = &H00004000
%TCS_FOCUSNEVER          = &H00008000

' end_r_commctrl

#IF (%WIN32_IE >= &H0400)
' EX styles for use with TCM_SETEXTENDEDSTYLE
%TCS_EX_FLATSEPARATORS   = &H00000001
%TCS_EX_REGISTERDROP     = &H00000002
#ENDIF

%TCM_GETIMAGELIST        = %TCM_FIRST + 2

MACRO TabCtrl_GetImageList(hWnd)=SendMessage(hWnd, %TCM_GETIMAGELIST, 0, 0)

%TCM_SETIMAGELIST        = %TCM_FIRST + 3

FUNCTION TabCtrl_SetImageList (BYVAL hWnd AS DWORD, BYVAL himl AS DWORD) AS DWORD
    FUNCTION = SendMessage(hWnd, %TCM_SETIMAGELIST, 0, himl)
END FUNCTION

%TCM_GETITEMCOUNT        = %TCM_FIRST + 4

FUNCTION TabCtrl_GetItemCount (BYVAL hWnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hWnd, %TCM_GETITEMCOUNT, 0, 0)
END FUNCTION

%TCIF_TEXT               = &H0001
%TCIF_IMAGE              = &H0002
%TCIF_RTLREADING         = &H0004
%TCIF_PARAM              = &H0008
#IF (%WIN32_IE >= &H0300)
%TCIF_STATE              = &H0010

%TCIS_BUTTONPRESSED      = &H0001
#ENDIF
#IF (%WIN32_IE >= &H0400)
%TCIS_HIGHLIGHTED        = &H0002
#ENDIF

TYPE TCITEMHEADERA
    Mask          AS DWORD
    lpReserved1   AS DWORD
    lpReserved2   AS DWORD
    pszText       AS ASCIIZ PTR
    cchTextMax    AS LONG
    iImage        AS LONG
END TYPE

TYPE TCITEMHEADERW
    Mask          AS DWORD
    lpReserved1   AS DWORD
    lpReserved2   AS DWORD
    pszText       AS WSTRINGZ PTR
    cchTextMax    AS LONG
    iImage        AS LONG
END TYPE

#IF %DEF(%UNICODE)
TYPE TCITEMHEADER
    TCITEMHEADERW
END TYPE
#ELSE
TYPE TCITEMHEADER
    TCITEMHEADERA
END TYPE
#ENDIF

#IF (%WIN32_IE >= &H0300)
TYPE TC_ITEMHEADERA
    TCITEMHEADERA
END TYPE
TYPE TC_ITEMHEADERW
    TCITEMHEADERW
END TYPE
#ELSE
TYPE TCITEMHEADERA
    TC_ITEMHEADERA
END TYPE
TYPE TCITEMHEADERW
    TC_ITEMHEADERW
END TYPE
#ENDIF
TYPE TC_ITEMHEADER
    TCITEMHEADER
END TYPE

TYPE TCITEMA
    Mask          AS DWORD
#IF (%WIN32_IE >= &H0300)
    dwState       AS DWORD
    dwStateMask   AS DWORD
#ELSE
    lpReserved1   AS DWORD
    lpReserved2   AS DWORD
#ENDIF
    pszText       AS ASCIIZ PTR
    cchTextMax    AS LONG
    iImage        AS LONG
    lParam        AS LONG
END TYPE

TYPE TCITEMW
    Mask          AS DWORD
#IF (%WIN32_IE >= &H0300)
    dwState       AS DWORD
    dwStateMask   AS DWORD
#ELSE
    lpReserved1   AS DWORD
    lpReserved2   AS DWORD
#ENDIF
    pszText       AS WSTRINGZ PTR
    cchTextMax    AS LONG
    iImage        AS LONG
    lParam        AS LONG
END TYPE

#IF %DEF(%UNICODE)
TYPE TCITEM
    TCITEMW
END TYPE
#ELSE
TYPE TCITEM
    TCITEMA
END TYPE
#ENDIF

#IF (%WIN32_IE >= &H0300)
TYPE TC_ITEMA
    TCITEMA
END TYPE
TYPE TC_ITEMW
    TCITEMW
END TYPE
#ELSE
TYPE TCITEMA
    TC_ITEMA
END TYPE
TYPE TCITEMW
    TC_ITEMW
END TYPE
#ENDIF
TYPE TC_ITEM
    TCITEM
END TYPE

%TCM_GETITEMA            = %TCM_FIRST + 5
%TCM_GETITEMW            = %TCM_FIRST + 60

#IF %DEF(%UNICODE)
%TCM_GETITEM = %TCM_GETITEMW
#ELSE
%TCM_GETITEM = %TCM_GETITEMA
#ENDIF

FUNCTION TabCtrl_GetItem (BYVAL hwnd AS DWORD, BYVAL iItem AS DWORD, _
    pItem AS TC_ITEM) AS LONG
    FUNCTION = SendMessage(hwnd, %TCM_GETITEM, iItem, VARPTR(pItem))
END FUNCTION

%TCM_SETITEMA           = %TCM_FIRST + 6
%TCM_SETITEMW           = %TCM_FIRST + 61

#IF %DEF(%UNICODE)
%TCM_SETITEM = %TCM_SETITEMW
#ELSE
%TCM_SETITEM = %TCM_SETITEMA
#ENDIF

FUNCTION TabCtrl_SetItem (BYVAL hwnd AS DWORD, BYVAL iItem AS DWORD, _
    pItem AS TC_ITEM) AS LONG
    FUNCTION = SendMessage(hwnd, %TCM_SETITEM, iItem, VARPTR(pItem))
END FUNCTION

%TCM_INSERTITEMA        = %TCM_FIRST + 7
%TCM_INSERTITEMW        = %TCM_FIRST + 62

#IF %DEF(%UNICODE)
%TCM_INSERTITEM = %TCM_INSERTITEMW
#ELSE
%TCM_INSERTITEM = %TCM_INSERTITEMA
#ENDIF

FUNCTION TabCtrl_InsertItem (BYVAL hwnd AS DWORD, BYVAL iItem AS DWORD, _
    pItem AS TC_ITEM) AS LONG
    FUNCTION = SendMessage(hwnd, %TCM_INSERTITEM, iItem, VARPTR(pItem))
END FUNCTION

%TCM_DELETEITEM         = %TCM_FIRST + 8

FUNCTION TabCtrl_DeleteItem (BYVAL hwnd AS DWORD, BYVAL iItem AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %TCM_DELETEITEM, iItem, 0)
END FUNCTION

%TCM_DELETEALLITEMS      = %TCM_FIRST + 9

FUNCTION TabCtrl_DeleteAllItems (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %TCM_DELETEALLITEMS, 0, 0)
END FUNCTION

%TCM_GETITEMRECT         = %TCM_FIRST + 10

FUNCTION TabCtrl_GetItemRect (BYVAL hwnd AS DWORD, BYVAL i AS DWORD, _
    prc AS RECT) AS LONG
    FUNCTION = SendMessage(hwnd, %TCM_GETITEMRECT, i, VARPTR(prc))
END FUNCTION

%TCM_GETCURSEL           = %TCM_FIRST + 11

FUNCTION TabCtrl_GetCurSel (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %TCM_GETCURSEL, 0, 0)
END FUNCTION

%TCM_SETCURSEL           = %TCM_FIRST + 12

FUNCTION TabCtrl_SetCurSel (BYVAL hwnd AS DWORD, BYVAL i AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %TCM_SETCURSEL, i, 0)
END FUNCTION

%TCHT_NOWHERE      = &H0001
%TCHT_ONITEMICON   = &H0002
%TCHT_ONITEMLABEL  = &H0004
%TCHT_ONITEM       = %TCHT_ONITEMICON OR %TCHT_ONITEMLABEL

TYPE TCHITTESTINFO
    pt    AS POINT
    flags AS DWORD
END TYPE

#IF (%WIN32_IE >= &H0300)
TYPE TC_HITTESTINFO
    TCHITTESTINFO
END TYPE
#ELSE
TYPE TCHITTESTINFO
    TC_HITTESTINFO
END TYPE
#ENDIF

%TCM_HITTEST             = %TCM_FIRST + 13

FUNCTION TabCtrl_HitTest (BYVAL hwndTC AS DWORD, pinfo AS TC_HITTESTINFO) AS LONG
    FUNCTION = SendMessage(hwndTC, %TCM_HITTEST, 0, VARPTR(pinfo))
END FUNCTION

%TCM_SETITEMEXTRA        = %TCM_FIRST + 14

FUNCTION TabCtrl_SetItemExtra (BYVAL hwndTC AS DWORD, BYVAL cb AS DWORD) AS LONG
    FUNCTION = SendMessage(hwndTC, %TCM_SETITEMEXTRA, cb, 0)
END FUNCTION

%TCM_ADJUSTRECT          = %TCM_FIRST + 40

FUNCTION TabCtrl_AdjustRect (BYVAL hwnd AS DWORD, BYVAL bLarger AS DWORD, _
    prc AS RECT) AS LONG
    FUNCTION = SendMessage(hwnd, %TCM_ADJUSTRECT, bLarger, VARPTR(prc))
END FUNCTION

%TCM_SETITEMSIZE         = %TCM_FIRST + 41

FUNCTION TabCtrl_SetItemSize (BYVAL hwnd AS DWORD, BYVAL x AS INTEGER, _
    BYVAL y AS INTEGER) AS DWORD
    FUNCTION = SendMessage(hwnd, %TCM_SETITEMSIZE, 0, MAKLNG(x,y))
END FUNCTION

%TCM_REMOVEIMAGE         = %TCM_FIRST + 42

SUB TabCtrl_RemoveImage (BYVAL hwnd AS DWORD, BYVAL i AS DWORD)
    SendMessage hwnd, %TCM_REMOVEIMAGE, i, 0
END SUB

%TCM_SETPADDING          = %TCM_FIRST + 43

SUB TabCtrl_SetPadding (BYVAL hwnd AS DWORD, BYVAL cx AS INTEGER, BYVAL cy AS INTEGER)
    SendMessage hwnd, %TCM_SETPADDING, 0, MAKLNG(cx,cy)
END SUB

%TCM_GETROWCOUNT         = %TCM_FIRST + 44

FUNCTION TabCtrl_GetRowCount (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %TCM_GETROWCOUNT, 0, 0)
END FUNCTION

%TCM_GETTOOLTIPS         = %TCM_FIRST + 45

FUNCTION TabCtrl_GetToolTips (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %TCM_GETTOOLTIPS, 0, 0)
END FUNCTION

%TCM_SETTOOLTIPS         = %TCM_FIRST + 46

SUB TabCtrl_SetToolTips (BYVAL hwnd AS DWORD, BYVAL hwndTT AS DWORD)
    SendMessage hwnd, %TCM_SETTOOLTIPS, hwndTT, 0
END SUB

%TCM_GETCURFOCUS         = %TCM_FIRST + 47

FUNCTION TabCtrl_GetCurFocus (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %TCM_GETCURFOCUS, 0, 0)
END FUNCTION

%TCM_SETCURFOCUS         = %TCM_FIRST + 48

SUB TabCtrl_SetCurFocus (BYVAL hwnd AS DWORD, BYVAL i AS DWORD)
    SendMessage hwnd, %TCM_SETCURFOCUS, i, 0
END SUB

#IF (%WIN32_IE >= &H0300)
%TCM_SETMINTABWIDTH      = %TCM_FIRST + 49

FUNCTION TabCtrl_SetMinTabWidth (BYVAL hwnd AS DWORD, BYVAL x AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %TCM_SETMINTABWIDTH, 0, x)
END FUNCTION

%TCM_DESELECTALL         = %TCM_FIRST + 50

SUB TabCtrl_DeselectAll (BYVAL hwnd AS DWORD, BYVAL fExcludeFocus AS DWORD)
    SendMessage hwnd, %TCM_DESELECTALL, fExcludeFocus, 0
END SUB
#ENDIF  ' #IF (%WIN32_IE >= &H0300)

#IF (%WIN32_IE >= &H0400)

%TCM_HIGHLIGHTITEM       = %TCM_FIRST + 51

FUNCTION TabCtrl_HighlightItem (BYVAL hwnd AS DWORD, BYVAL i AS DWORD, _
    BYVAL fHighlight AS INTEGER) AS LONG
    FUNCTION = SendMessage(hwnd, %TCM_HIGHLIGHTITEM, i, MAKLNG(fHighlight, 0))
END FUNCTION

%TCM_SETEXTENDEDSTYLE    = %TCM_FIRST + 52  ' optional wParam == mask

FUNCTION TabCtrl_SetExtendedStyle (BYVAL hwnd AS DWORD, BYVAL dwd AS LONG) AS DWORD
    FUNCTION = SendMessage(hwnd, %TCM_SETEXTENDEDSTYLE, 0, dwd)
END FUNCTION

%TCM_GETEXTENDEDSTYLE    = %TCM_FIRST + 53

FUNCTION TabCtrl_GetExtendedStyle (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %TCM_GETEXTENDEDSTYLE, 0, 0)
END FUNCTION

%TCM_SETUNICODEFORMAT    = %CCM_SETUNICODEFORMAT

FUNCTION TabCtrl_SetUnicodeFormat (BYVAL hwnd AS DWORD, _
    BYVAL fUnicode AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %TCM_SETUNICODEFORMAT, fUnicode, 0)
END FUNCTION

%TCM_GETUNICODEFORMAT    = %CCM_GETUNICODEFORMAT

FUNCTION TabCtrl_GetUnicodeFormat (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %TCM_GETUNICODEFORMAT, 0, 0)
END FUNCTION

#ENDIF  ' #IF (%WIN32_IE >= &H0400)

%TCN_KEYDOWN             = %TCN_FIRST - 0

TYPE NMTCKEYDOWN BYTE
    hdr    AS NMHDR
    wVKey  AS WORD
    flags  AS DWORD
END TYPE

#IF (%WIN32_IE >= &H0300)
TYPE TC_KEYDOWN
    NMTCKEYDOWN
END TYPE
#ELSE
TYPE NMTCKEYDOWN
    TC_KEYDOWN
END TYPE
#ENDIF

%TCN_SELCHANGE   = %TCN_FIRST - 1
%TCN_SELCHANGING = %TCN_FIRST - 2
#IF (%WIN32_IE >= &H0400)
%TCN_GETOBJECT   = %TCN_FIRST - 3
#ENDIF
#IF (%WIN32_IE >= &H0500)
%TCN_FOCUSCHANGE = %TCN_FIRST - 4
#ENDIF

#ENDIF  ' NOTABCONTROL



'==============================================================================
' ANIMATE CONTROL

#IF NOT %DEF(%NOANIMATE)

#IF %DEF(%WIN32)

$ANIMATE_CLASSA         = "SysAnimate32"
$$ANIMATE_CLASSW        = "SysAnimate32"$$

#IF %DEF(%UNICODE)
MACRO ANIMATE_CLASS    = $$ANIMATE_CLASSW
#ELSE
MACRO ANIMATE_CLASS    = $ANIMATE_CLASSA
#ENDIF

' begin_r_commctrl

%ACS_CENTER             = &H0001
%ACS_TRANSPARENT        = &H0002
%ACS_AUTOPLAY           = &H0004
#IF (%WIN32_IE >= &H0300)
%ACS_TIMER              = &H0008  ' don't use threads... use timers
#ENDIF

' end_r_commctrl

%ACM_OPENA              = %WM_USER + 100
%ACM_OPENW              = %WM_USER + 103

#IF %DEF(%UNICODE)
%ACM_OPEN               = %ACM_OPENW
#ELSE
%ACM_OPEN               = %ACM_OPENA
#ENDIF

%ACM_PLAY               = %WM_USER + 101
%ACM_STOP               = %WM_USER + 102
%ACM_ISPLAYING          = %WM_USER + 104

%ACN_START              = 1
%ACN_STOP               = 2

SUB Animate_Create (BYVAL hWndP AS DWORD, BYVAL ID AS DWORD, _
    BYVAL dwStyle AS DWORD, BYVAL hInstance AS DWORD)
    CreateWindow "SysAnimate32", BYVAL %NULL, dwStyle, 0, 0, 0, 0, hWndP, _
       ID, hInstance, BYVAL %NULL
END SUB

FUNCTION Animate_Open(BYVAL hwnd AS DWORD, szName AS ASCIIZ) AS LONG
    FUNCTION = SendMessage(hwnd, %ACM_OPEN, 0, VARPTR(szName))
END FUNCTION

FUNCTION Animate_OpenEx(BYVAL hwnd AS DWORD, BYVAL hInst AS DWORD, szName AS ASCIIZ) AS LONG
    FUNCTION = SendMessage(hwnd, %ACM_OPEN, hInst, VARPTR(szName))
END FUNCTION

FUNCTION Animate_Play (BYVAL hwnd AS DWORD, BYVAL nFrom AS INTEGER, _
   BYVAL nTo AS INTEGER, BYVAL rep AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %ACM_PLAY, rep, MAKLNG(nFrom, nTo))
END FUNCTION

FUNCTION Animate_Stop (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %ACM_STOP, 0, 0)
END FUNCTION

FUNCTION Animate_IsPlaying (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %ACM_ISPLAYING, 0, 0)
END FUNCTION

FUNCTION Animate_Close (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = Animate_Open(hwnd, BYVAL %NULL)
END FUNCTION

FUNCTION Animate_Seek (BYVAL hwnd AS DWORD, BYVAL FRAME AS LONG) AS LONG
    FUNCTION = Animate_Play(hwnd, FRAME, FRAME, 1)
END FUNCTION

#ENDIF  ' #IF %DEF(%WIN32)

#ENDIF  ' #IF NOT %DEF(%NOANIMATE)



'====== MONTHCAL CONTROL ======================================================

#IF (%WIN32_IE >= &H0300)

#IF NOT %DEF(%NOMONTHCAL)
#IF %DEF(%WIN32)

$$MONTHCAL_CLASSW = "SysMonthCal32"$$
$MONTHCAL_CLASSA = "SysMonthCal32"

#IF %DEF(%UNICODE)
MACRO MONTHCAL_CLASS = $$MONTHCAL_CLASSW
#ELSE
MACRO MONTHCAL_CLASS = $MONTHCAL_CLASSA
#ENDIF

' bit-packed array of "bold" info for a month
' if a bit is on, that day is drawn bold
MACRO MONTHDAYSTATE=DWORD


%MCM_FIRST = &H1000

' BOOL MonthCal_GetCurSel(HWND hmc, LPSYSTEMTIME pst)
'   returns FALSE if MCS_MULTISELECT
'   returns TRUE and sets *pst to the currently selected date otherwise
%MCM_GETCURSEL       = %MCM_FIRST + 1

FUNCTION MonthCal_GetCurSel (BYVAL hmc AS DWORD, pst AS SYSTEMTIME) AS LONG
    FUNCTION = SendMessage(hmc, %MCM_GETCURSEL, 0, VARPTR(pst))
END FUNCTION

' BOOL MonthCal_SetCurSel(HWND hmc, LPSYSTEMTIME pst)
'   returns FALSE if MCS_MULTISELECT
'   returns TRUE and sets the currently selected date to *pst otherwise
%MCM_SETCURSEL       = %MCM_FIRST + 2

FUNCTION MonthCal_SetCurSel (BYVAL hmc AS DWORD, pst AS SYSTEMTIME) AS LONG
    FUNCTION = SendMessage(hmc, %MCM_SETCURSEL, 0, VARPTR(pst))
END FUNCTION

' DWORD MonthCal_GetMaxSelCount(HWND hmc)
'   returns the maximum number of selectable days allowed
%MCM_GETMAXSELCOUNT  = %MCM_FIRST + 3

FUNCTION MonthCal_GetMaxSelCount (BYVAL hmc AS DWORD) AS DWORD
    FUNCTION = SendMessage(hmc, %MCM_GETMAXSELCOUNT, 0, 0)
END FUNCTION

' BOOL MonthCal_SetMaxSelCount(HWND hmc, UINT n)
'   sets the max number days that can be selected iff MCS_MULTISELECT
%MCM_SETMAXSELCOUNT  = %MCM_FIRST + 4

FUNCTION MonthCal_SetMaxSelCount (BYVAL hmc AS DWORD, BYVAL n AS DWORD) AS LONG
    FUNCTION = SendMessage(hmc, %MCM_SETMAXSELCOUNT, n, 0)
END FUNCTION

' BOOL MonthCal_GetSelRange(HWND hmc, LPSYSTEMTIME rgst)
'   sets rgst[0] to the first day of the selection range
'   sets rgst[1] to the last day of the selection range
%MCM_GETSELRANGE     = %MCM_FIRST + 5

FUNCTION MonthCal_GetSelRange (BYVAL hmc AS DWORD, rgst AS SYSTEMTIME) AS LONG
    FUNCTION = SendMessage(hmc, %MCM_GETSELRANGE, 0, VARPTR(rgst))
END FUNCTION

' BOOL MonthCal_SetSelRange(HWND hmc, LPSYSTEMTIME rgst)
'   selects the range of days from rgst[0] to rgst[1]
%MCM_SETSELRANGE     = %MCM_FIRST + 6

FUNCTION MonthCal_SetSelRange (BYVAL hmc AS DWORD, rgst AS SYSTEMTIME) AS LONG
    FUNCTION = SendMessage(hmc, %MCM_SETSELRANGE, 0, VARPTR(rgst))
END FUNCTION

' DWORD MonthCal_GetMonthRange(HWND hmc, DWORD gmr, LPSYSTEMTIME rgst)
'   if rgst specified, sets rgst[0] to the starting date and
'      and rgst[1] to the ending date of the the selectable(non-grayed)
'      days if GMR_VISIBLE or all the displayed days(including grayed)
'      if GMR_DAYSTATE.
'   returns the number of months spanned by the above range.
%MCM_GETMONTHRANGE   = %MCM_FIRST + 7

FUNCTION MonthCal_GetMonthRange (BYVAL hmc AS DWORD, BYVAL gmr AS DWORD, _
    rgst AS SYSTEMTIME) AS DWORD
    FUNCTION = SendMessage(hmc, %MCM_GETMONTHRANGE, gmr, VARPTR(rgst))
END FUNCTION

' BOOL MonthCal_SetDayState(HWND hmc, int cbds, DAYSTATE *rgds)
'   cbds is the count of DAYSTATE items in rgds and it must be equal
'   to the value returned from MonthCal_GetMonthRange(hmc, GMR_DAYSTATE, NULL)
'   This sets the DAYSTATE bits for each month(grayed and non-grayed
'   days) displayed in the calendar. The first bit in a month's DAYSTATE
'   corresponts to bolding day 1, the second bit affects day 2, etc.
' [note: Microsoft's docs, above, are incorrect:
' DAYSTATE should actually be MONTHDAYSTATE, which is a DWORD.]
%MCM_SETDAYSTATE     = %MCM_FIRST + 8

FUNCTION MonthCal_SetDayState (BYVAL hmc AS DWORD, BYVAL cbds AS LONG, _
    rgds AS DWORD) AS LONG
    FUNCTION = SendMessage(hmc, %MCM_SETDAYSTATE, cbds, VARPTR(rgds))
END FUNCTION

' BOOL MonthCal_GetMinReqRect(HWND hmc, LPRECT prc)
'   sets *prc the minimal size needed to display one month
'   To display two months, undo the AdjustWindowRect calculation already done to
'   this rect, double the width, and redo the AdjustWindowRect calculation --
'   the monthcal control will display two calendars in this window(if you also
'   double the vertical size, you will get 4 calendars)
'   NOTE: if you want to gurantee that the "Today" string is not clipped,
'   get the MCM_GETMAXTODAYWIDTH and use the max of that width and this width
%MCM_GETMINREQRECT   = %MCM_FIRST + 9

FUNCTION MonthCal_GetMinReqRect (BYVAL hmc AS DWORD, prc AS RECT) AS LONG
    FUNCTION = SendMessage(hmc, %MCM_GETMINREQRECT, 0, VARPTR(prc))
END FUNCTION

' set colors to draw control with -- see MCSC_ bits below
%MCM_SETCOLOR            = %MCM_FIRST + 10
FUNCTION MonthCal_SetColor (BYVAL hmc AS DWORD, BYVAL iColor AS DWORD, _
    BYVAL clr AS DWORD) AS DWORD
    FUNCTION = SendMessage(hmc, %MCM_SETCOLOR, iColor, clr)
END FUNCTION

%MCM_GETCOLOR            = %MCM_FIRST + 11
FUNCTION MonthCal_GetColor (BYVAL hmc AS DWORD, BYVAL iColor AS DWORD) AS DWORD
    FUNCTION = SendMessage(hmc, %MCM_GETCOLOR, iColor, 0)
END FUNCTION

%MCSC_BACKGROUND   = 0   ' the background color(between months)
%MCSC_TEXT         = 1   ' the dates
%MCSC_TITLEBK      = 2   ' background of the title
%MCSC_TITLETEXT    = 3
%MCSC_MONTHBK      = 4   ' background within the month cal
%MCSC_TRAILINGTEXT = 5   ' the text color of header & trailing days

' set what day is "today"   send NULL to revert back to real date
%MCM_SETTODAY    = %MCM_FIRST + 12
FUNCTION MonthCal_SetToday (BYVAL hmc AS DWORD, pst AS SYSTEMTIME) AS LONG
    FUNCTION = SendMessage(hmc, %MCM_SETTODAY, 0, VARPTR(pst))
END FUNCTION

' get what day is "today"
' returns BOOL for success/failure
%MCM_GETTODAY    = %MCM_FIRST + 13
FUNCTION MonthCal_GetToday (BYVAL hmc AS DWORD, pst AS SYSTEMTIME) AS LONG
    FUNCTION = SendMessage(hmc, %MCM_GETTODAY, 0, VARPTR(pst))
END FUNCTION

TYPE MCHITTESTINFO
    cbSize  AS DWORD
    pt      AS POINT
    uHit    AS DWORD   ' out param
    st      AS SYSTEMTIME
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
    rc      AS RECT
    iOffset AS LONG
    iRow    AS LONG
    iCol    AS LONG
#ENDIF
END TYPE

' determine what pinfo->pt is over
%MCM_HITTEST          = %MCM_FIRST + 14
FUNCTION MonthCal_HitTest (BYVAL hmc AS DWORD, pinfo AS MCHITTESTINFO) AS DWORD
    FUNCTION = SendMessage(hmc, %MCM_HITTEST, 0, VARPTR(pinfo))
END FUNCTION

%MCHITTESTINFO_V1_SIZE = 32 ' CCSIZEOF_STRUCT(MCHITTESTINFO, st)

%MCHT_TITLE            = &H00010000
%MCHT_CALENDAR         = &H00020000
%MCHT_TODAYLINK        = &H00030000

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%MCHT_CALENDARCONTROL  = &H00100000
#ENDIF

%MCHT_NEXT             = &H01000000  ' these indicate that hitting
%MCHT_PREV             = &H02000000  ' here will go to the next/prev month
%MCHT_NOWHERE          = &H00000000

%MCHT_TITLEBK          = %MCHT_TITLE
%MCHT_TITLEMONTH       = %MCHT_TITLE OR &H0001
%MCHT_TITLEYEAR        = %MCHT_TITLE OR &H0002
%MCHT_TITLEBTNNEXT     = %MCHT_TITLE OR %MCHT_NEXT OR &H0003
%MCHT_TITLEBTNPREV     = %MCHT_TITLE OR %MCHT_PREV OR &H0003

%MCHT_CALENDARBK       = %MCHT_CALENDAR
%MCHT_CALENDARDATE     = %MCHT_CALENDAR OR &H0001
%MCHT_CALENDARDATENEXT = %MCHT_CALENDARDATE OR %MCHT_NEXT
%MCHT_CALENDARDATEPREV = %MCHT_CALENDARDATE OR %MCHT_PREV
%MCHT_CALENDARDAY      = %MCHT_CALENDAR OR &H0002
%MCHT_CALENDARWEEKNUM  = %MCHT_CALENDAR OR &H0003
%MCHT_CALENDARDATEMIN  = %MCHT_CALENDAR OR &H0004
%MCHT_CALENDARDATEMAX  = %MCHT_CALENDAR OR &H0005

' set first day of week to iDay:
' 0 for Monday, 1 for Tuesday, ..., 6 for Sunday
' -1 for means use locale info
%MCM_SETFIRSTDAYOFWEEK = %MCM_FIRST + 15
FUNCTION MonthCal_SetFirstDayOfWeek (BYVAL hmc AS DWORD, BYVAL iDay AS LONG) AS DWORD
    FUNCTION = SendMessage(hmc, %MCM_SETFIRSTDAYOFWEEK, 0, iDay)
END FUNCTION

' DWORD result...  low word has the day.  high word is bool if this is app set
' or not(FALSE == using locale info)
%MCM_GETFIRSTDAYOFWEEK = %MCM_FIRST + 16
FUNCTION MonthCal_GetFirstDayOfWeek (BYVAL hmc AS DWORD) AS DWORD
    FUNCTION = SendMessage(hmc, %MCM_GETFIRSTDAYOFWEEK, 0, 0)
END FUNCTION

' DWORD MonthCal_GetRange(HWND hmc, LPSYSTEMTIME rgst)
'   modifies rgst[0] to be the minimum ALLOWABLE systemtime(0 if no minimum)
'   modifies rgst[1] to be the maximum ALLOWABLE systemtime(0 if no maximum)
'   returns GDTR_MIN or GDTR_MAX if there is a minimum or maximum limit
%MCM_GETRANGE = %MCM_FIRST + 17
FUNCTION MonthCal_GetRange (BYVAL hmc AS DWORD, rgst AS SYSTEMTIME) AS DWORD
    FUNCTION = SendMessage(hmc, %MCM_GETRANGE, 0, VARPTR(rgst))
END FUNCTION

' BOOL MonthCal_SetRange(HWND hmc, DWORD gdtr, LPSYSTEMTIME rgst)
'   if GDTR_MIN, sets the minimum ALLOWABLE systemtime to rgst[0], otherwise removes minimum
'   if GDTR_MAX, sets the maximum ALLOWABLE systemtime to rgst[1], otherwise removes maximum
'   returns TRUE on success, FALSE on error(such as invalid parameters)
%MCM_SETRANGE = %MCM_FIRST + 18
FUNCTION MonthCal_SetRange (BYVAL hmc AS DWORD, BYVAL gd AS DWORD, _
    rgst AS SYSTEMTIME) AS LONG
    FUNCTION = SendMessage(hmc, %MCM_SETRANGE, gd, VARPTR(rgst))
END FUNCTION

' int MonthCal_GetMonthDelta(HWND hmc)
'   returns the number of months one click on a next/prev button moves by
%MCM_GETMONTHDELTA = %MCM_FIRST + 19
FUNCTION MonthCal_GetMonthDelta (BYVAL hmc AS DWORD) AS LONG
    FUNCTION = SendMessage(hmc, %MCM_GETMONTHDELTA, 0, 0)
END FUNCTION

' int MonthCal_SetMonthDelta(HWND hmc, int n)
'   sets the month delta to n. n==0 reverts to moving by a page of months
'   returns the previous value of n.
%MCM_SETMONTHDELTA = %MCM_FIRST + 20
FUNCTION MonthCal_SetMonthDelta (BYVAL hmc AS DWORD, BYVAL n AS LONG) AS LONG
    FUNCTION = SendMessage(hmc, %MCM_SETMONTHDELTA, n, 0)
END FUNCTION

' DWORD MonthCal_GetMaxTodayWidth(HWND hmc, LPSIZE psz)
'   sets *psz to the maximum width/height of the "Today" string displayed
'   at the bottom of the calendar(as long as MCS_NOTODAY is not specified)
'   --(the above bit of Microsoft documentation is flagrantly confused) --
%MCM_GETMAXTODAYWIDTH = %MCM_FIRST + 21
FUNCTION MonthCal_GetMaxTodayWidth (BYVAL hmc AS DWORD) AS DWORD
    FUNCTION = SendMessage(hmc, %MCM_GETMAXTODAYWIDTH, 0, 0)
END FUNCTION

#IF (%WIN32_IE >= &H0400)
%MCM_SETUNICODEFORMAT = %CCM_SETUNICODEFORMAT
FUNCTION MonthCal_SetUnicodeFormat (BYVAL hwnd AS DWORD, _
    BYVAL fUnicode AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %MCM_SETUNICODEFORMAT, fUnicode, 0)
END FUNCTION

%MCM_GETUNICODEFORMAT = %CCM_GETUNICODEFORMAT
FUNCTION MonthCal_GetUnicodeFormat (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %MCM_GETUNICODEFORMAT, 0, 0)
END FUNCTION
#ENDIF

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
' View
%MCMV_MONTH    = 0
%MCMV_YEAR     = 1
%MCMV_DECADE   = 2
%MCMV_CENTURY  = 3
%MCMV_MAX      = %MCMV_CENTURY

%MCM_GETCURRENTVIEW = (%MCM_FIRST + 22)
FUNCTION MonthCal_GetCurrentView (BYVAL hmc AS DWORD) AS DWORD
    FUNCTION = SendMessage(hmc, %MCM_GETCURRENTVIEW, 0, 0)
END FUNCTION

%MCM_GETCALENDARCOUNT = (%MCM_FIRST + 23)
FUNCTION MonthCal_GetCalendarCount (BYVAL hmc AS DWORD) AS DWORD
    FUNCTION = SendMessage(hmc, %MCM_GETCALENDARCOUNT, 0, 0)
END FUNCTION

' Part
%MCGIP_CALENDARCONTROL    = 0
%MCGIP_NEXT               = 1
%MCGIP_PREV               = 2
%MCGIP_FOOTER             = 3
%MCGIP_CALENDAR           = 4
%MCGIP_CALENDARHEADER     = 5
%MCGIP_CALENDARBODY       = 6
%MCGIP_CALENDARROW        = 7
%MCGIP_CALENDARCELL       = 8

%MCGIF_DATE               = &H00000001
%MCGIF_RECT               = &H00000002
%MCGIF_NAME               = &H00000004

' Note: iRow of -1 refers to the row header and iCol of -1 refers to the col header.
TYPE MCGRIDINFO
    cbSize     AS DWORD
    dwPart     AS DWORD
    dwFlags    AS DWORD
    iCalendar  AS LONG
    iRow       AS LONG
    iCol       AS LONG
    bSelected  AS LONG  ' BOOL
    stStart    AS SYSTEMTIME
    stEnd      AS SYSTEMTIME
    rc         AS RECT
    pszName    AS WSTRINGZ PTR
    cchName    AS size_t
END TYPE

%MCM_GETCALENDARGRIDINFO = (%MCM_FIRST + 24)
FUNCTION MonthCal_GetCalendarGridInfo (BYVAL hmc AS DWORD, _
    pmcGridInfo AS MCGRIDINFO) AS LONG
    FUNCTION = SendMessage(hmc, %MCM_GETCALENDARGRIDINFO, 0, VARPTR(pmcGridInfo))
END FUNCTION

%MCM_GETCALID = (%MCM_FIRST + 27)
FUNCTION MonthCal_GetCALID (BYVAL hmc AS DWORD) AS DWORD
    FUNCTION = SendMessage(hmc, %MCM_GETCALID, 0, 0)
END FUNCTION

%MCM_SETCALID = (%MCM_FIRST + 28)
FUNCTION MonthCal_SetCALID (BYVAL hmc AS DWORD, BYVAL calid AS DWORD) AS LONG
    FUNCTION = SendMessage(hmc, %MCM_SETCALID, calid, 0)
END FUNCTION

' Returns the min rect that will fit the max number of calendars for the passed in rect.
%MCM_SIZERECTTOMIN = (%MCM_FIRST + 29)
FUNCTION MonthCal_SizeRectToMin (BYVAL hmc AS DWORD, prc AS RECT) AS LONG
    FUNCTION = SendMessage(hmc, %MCM_SIZERECTTOMIN, 0, VARPTR(prc))
END FUNCTION

%MCM_SETCALENDARBORDER = (%MCM_FIRST + 30)
FUNCTION MonthCal_SetCalendarBorder (BYVAL hmc AS DWORD, BYVAL fset AS LONG, _
    BYVAL xyborder AS LONG) AS LONG
    FUNCTION = SendMessage(hmc, %MCM_SETCALENDARBORDER, fset, xyborder)
END FUNCTION

%MCM_GETCALENDARBORDER = (%MCM_FIRST + 31)
FUNCTION MonthCal_GetCalendarBorder (BYVAL hmc AS DWORD) AS DWORD
    FUNCTION = SendMessage(hmc, %MCM_GETCALENDARBORDER, 0, 0)
END FUNCTION

%MCM_SETCURRENTVIEW = (%MCM_FIRST + 32)
FUNCTION MonthCal_SetCurrentView (BYVAL hmc AS DWORD, _
    BYVAL dwNewView AS DWORD) AS LONG
    FUNCTION = SendMessage(hmc, %MCM_SETCURRENTVIEW, 0, dwNewView)
END FUNCTION

#ENDIF  ' #IF (%NTDDI_VERSION >= %NTDDI_VISTA)

' MCN_SELCHANGE is sent whenever the currently displayed date changes
' via month change, year change, keyboard navigation, prev/next button
'
TYPE NMSELCHANGE
    hdr        AS NMHDR       ' this must be first, so we don't break WM_NOTIFY
    stSelStart AS SYSTEMTIME
    stSelEnd   AS SYSTEMTIME
END TYPE

TYPE NMSELECT
    hdr        AS NMHDR       ' this must be first, so we don't break WM_NOTIFY
    stSelStart AS SYSTEMTIME
    stSelEnd   AS SYSTEMTIME
END TYPE

%MCN_SELCHANGE       = %MCN_FIRST - 3

' MCN_GETDAYSTATE is sent for MCS_DAYSTATE controls whenever new daystate
' information is needed(month or year scroll) to draw bolding information.
' The app must fill in cDayState months worth of information starting from
' stStart date. The app may fill in the array at prgDayState or change
' prgDayState to point to a different array out of which the information
' will be copied.(similar to tooltips)
'
TYPE NMDAYSTATE
    hdr         AS NMHDR      ' this must be first, so we don't break WM_NOTIFY
    stStart     AS SYSTEMTIME
    cDayState   AS LONG
    prgDayState AS DWORD PTR  ' points to cDayState MONTHDAYSTATEs
END TYPE

%MCN_GETDAYSTATE     = %MCN_FIRST - 1

' MCN_SELECT is sent whenever a selection has occured(via mouse or keyboard)
'
%MCN_SELECT          = %MCN_FIRST

TYPE NMVIEWCHANGE
    hdr       AS NMHDR  ' this must be first, so we don't break WM_NOTIFY
    dwOldView AS DWORD
    dwNewView AS DWORD
END TYPE

%MCN_VIEWCHANGE    = (%MCN_FIRST - 4) ' -750


' begin_r_commctrl

%MCS_DAYSTATE         = &H0001
%MCS_MULTISELECT      = &H0002
%MCS_WEEKNUMBERS      = &H0004
#IF (%WIN32_IE >= &H0400)
%MCS_NOTODAYCIRCLE    = &H0008
%MCS_NOTODAY          = &H0010
#ELSE
%MCS_NOTODAY          = &H0008
#ENDIF
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%MCS_NOTRAILINGDATES  = &H0040
%MCS_SHORTDAYSOFWEEK  = &H0080
%MCS_NOSELCHANGEONNAV = &H0100
#ENDIF

' end_r_commctrl

%GMR_VISIBLE     = 0       ' visible portion of display
%GMR_DAYSTATE    = 1       ' above plus the grayed out parts of
                           ' partially displayed months

#ENDIF  ' %WIN32
#ENDIF  ' NOMONTHCAL


'====== DATETIMEPICK CONTROL ==================================================

#IF NOT %DEF(%NODATETIMEPICK)
#IF %DEF(%WIN32)

$DATETIMEPICK_CLASSA = "SysDateTimePick32"
$$DATETIMEPICK_CLASSW = "SysDateTimePick32"$$

#IF %DEF(%UNICODE)
MACRO DATETIMEPICK_CLASS = $$DATETIMEPICK_CLASSW
#ELSE
MACRO DATETIMEPICK_CLASS = $DATETIMEPICK_CLASSW
#ENDIF

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

TYPE DATETIMEPICKERINFO
    cbSize       AS DWORD

    rcCheck      AS RECT
    stateCheck   AS DWORD

    rcButton     AS RECT
    stateButton  AS DWORD

    hwndEdit     AS DWORD  ' HWND
    hwndUD       AS DWORD  ' HWND
    hwndDropDown AS DWORD  ' HWND
END TYPE

#ENDIF  '(%NTDDI_VERSION >= %NTDDI_VISTA)

%DTM_FIRST        = &H1000

' DWORD DateTimePick_GetSystemtime(HWND hdp, LPSYSTEMTIME pst)
'   returns GDT_NONE if "none" is selected(DTS_SHOWNONE only)
'   returns GDT_VALID and modifies *pst to be the currently selected value
%DTM_GETSYSTEMTIME   = %DTM_FIRST + 1

FUNCTION DateTime_GetSystemtime (BYVAL hdp AS DWORD, pst AS SYSTEMTIME) AS DWORD
    FUNCTION = SendMessage(hdp, %DTM_GETSYSTEMTIME, 0, VARPTR(pst))
END FUNCTION

' BOOL DateTime_SetSystemtime(HWND hdp, DWORD gd, LPSYSTEMTIME pst)
'   if gd==GDT_NONE, sets datetimepick to None(DTS_SHOWNONE only)
'   if gd==GDT_VALID, sets datetimepick to *pst
'   returns TRUE on success, FALSE on error(such as bad params)
%DTM_SETSYSTEMTIME   = %DTM_FIRST + 2

FUNCTION DateTime_SetSystemtime (BYVAL hdp AS DWORD, BYVAL gd AS DWORD, _
    pst AS SYSTEMTIME) AS LONG
    FUNCTION = SendMessage(hdp, %DTM_SETSYSTEMTIME, gd, VARPTR(pst))
END FUNCTION

' DWORD DateTime_GetRange(HWND hdp, LPSYSTEMTIME rgst)
'   modifies rgst[0] to be the minimum ALLOWABLE systemtime(or 0 if no minimum)
'   modifies rgst[1] to be the maximum ALLOWABLE systemtime(or 0 if no maximum)
'   returns GDTR_MIN or GDTR_MAX if there is a minimum or maximum limit
%DTM_GETRANGE = %DTM_FIRST + 3

FUNCTION DateTime_GetRange (BYVAL hdp AS DWORD, rgst AS SYSTEMTIME) AS DWORD
    FUNCTION = SendMessage(hdp, %DTM_GETRANGE, 0, VARPTR(rgst))
END FUNCTION

' BOOL DateTime_SetRange(HWND hdp, DWORD gdtr, LPSYSTEMTIME rgst)
'   if GDTR_MIN, sets the minimum ALLOWABLE systemtime to rgst[0],
'       otherwise removes minimum
'   if GDTR_MAX, sets the maximum ALLOWABLE systemtime to rgst[1],
'       otherwise removes maximum
'   returns TRUE on success, FALSE on error(such as invalid parameters)
%DTM_SETRANGE = %DTM_FIRST + 4

FUNCTION DateTime_SetRange (BYVAL hdp AS DWORD, BYVAL gd AS DWORD, _
    rgst AS SYSTEMTIME) AS LONG
    FUNCTION = SendMessage(hdp, %DTM_SETRANGE, gd, VARPTR(rgst))
END FUNCTION

' BOOL DateTime_SetFormat(HWND hdp, LPCTSTR sz)
'   sets the display formatting string to sz(see GetDateFormat and GetTimeFormat for valid formatting chars)
'   NOTE: 'X' is a valid formatting character which indicates that the application
'   will determine how to display information. Such apps must support DTN_WMKEYDOWN,
'   DTN_FORMAT, and DTN_FORMATQUERY.
%DTM_SETFORMATA = %DTM_FIRST + 5
%DTM_SETFORMATW = %DTM_FIRST + 50

#IF %DEF(%UNICODE)
%DTM_SETFORMAT = %DTM_SETFORMATW
#ELSE
%DTM_SETFORMAT = %DTM_SETFORMATA
#ENDIF

FUNCTION DateTime_SetFormat(BYVAL hdp AS DWORD, sz AS ASCIIZ) AS LONG
    FUNCTION = SendMessage(hdp, %DTM_SETFORMAT, 0, VARPTR(sz))
END FUNCTION


%DTM_SETMCCOLOR    = %DTM_FIRST + 6

FUNCTION DateTime_SetMonthCalColor (BYVAL hdp AS DWORD, _
    BYVAL iColor AS DWORD, BYVAL clr AS DWORD) AS DWORD
    FUNCTION = SendMessage(hdp, %DTM_SETMCCOLOR, iColor, clr)
END FUNCTION

%DTM_GETMCCOLOR    = %DTM_FIRST + 7

' HWND DateTime_GetMonthCal(HWND hdp)
'   returns the HWND of the MonthCal popup window. Only valid
' between DTN_DROPDOWN and DTN_CLOSEUP notifications.
%DTM_GETMONTHCAL   = %DTM_FIRST + 8
FUNCTION DateTime_GetMonthCalColor (BYVAL hdp AS DWORD, iColor AS DWORD) AS DWORD
    FUNCTION = SendMessage(hdp, %DTM_GETMCCOLOR, iColor, 0)
END FUNCTION

#IF (%WIN32_IE >= &H0400)

%DTM_SETMCFONT     = %DTM_FIRST + 9
SUB DateTime_SetMonthCalFont (BYVAL hdp AS DWORD, BYVAL hfont AS DWORD, _
    BYVAL fRedraw AS LONG)
    SendMessage hdp, %DTM_SETMCFONT, hfont, fRedraw
END SUB

%DTM_GETMCFONT     = %DTM_FIRST + 10
FUNCTION DateTime_GetMonthCalFont (BYVAL hdp AS DWORD) AS DWORD
    FUNCTION = SendMessage(hdp, %DTM_GETMCFONT, 0, 0)
END FUNCTION

#ENDIF  ' #IF (%WIN32_IE >= &H0400)

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

%DTM_SETMCSTYLE  = (%DTM_FIRST + 11)
FUNCTION DateTime_SetMonthCalStyle (BYVAL hdp AS DWORD, _
    BYVAL dwStyle AS DWORD) AS LONG
    FUNCTION = SendMessage(hdp, %DTM_SETMCSTYLE, 0, dwStyle)
END FUNCTION

%DTM_GETMCSTYLE  = (%DTM_FIRST + 12)
FUNCTION DateTime_GetMonthCalStyle (BYVAL hdp AS DWORD) AS LONG
    FUNCTION = SendMessage(hdp, %DTM_GETMCSTYLE, 0, 0)
END FUNCTION

%DTM_CLOSEMONTHCAL = (%DTM_FIRST + 13)
FUNCTION DateTime_CloseMonthCal (BYVAL hdp AS DWORD) AS LONG
    FUNCTION = SendMessage(hdp, %DTM_CLOSEMONTHCAL, 0, 0)
END FUNCTION

' DateTime_GetDateTimePickerInfo(HWND hdp, DATETIMEPICKERINFO* pdtpi)
' Retrieves information about the selected date time picker.
%DTM_GETDATETIMEPICKERINFO = (%DTM_FIRST + 14)
FUNCTION DateTime_GetDateTimePickerInfo (BYVAL hdp AS DWORD, _
    pdtpi AS DATETIMEPICKERINFO) AS LONG
    FUNCTION = SendMessage(hdp, %DTM_GETDATETIMEPICKERINFO, 0, VARPTR(pdtpi))
END FUNCTION

%DTM_GETIDEALSIZE = (%DTM_FIRST + 15)
FUNCTION DateTime_GetIdealSize (BYVAL hdp AS DWORD, psize AS SIZE) AS LONG
    FUNCTION = SendMessage(hdp, %DTM_GETIDEALSIZE, 0, VARPTR(psize))
END FUNCTION

#ENDIF  '(%NTDDI_VERSION >= %NTDDI_VISTA)


' begin_r_commctrl

%DTS_UPDOWN          = &H0001 ' use UPDOWN instead of MONTHCAL
%DTS_SHOWNONE        = &H0002 ' allow a NONE selection
%DTS_SHORTDATEFORMAT = &H0000 ' use the short date format(app must forward WM_WININICHANGE messages)
%DTS_LONGDATEFORMAT  = &H0004 ' use the long date format(app must forward WM_WININICHANGE messages)
#IF (%WIN32_IE >= &H500)
%DTS_SHORTDATECENTURYFORMAT = &H000C ' short date format with century(app must forward WM_WININICHANGE messages)
#ENDIF
%DTS_TIMEFORMAT      = &H0009 ' use the time format(app must forward WM_WININICHANGE messages)
%DTS_APPCANPARSE     = &H0010 ' allow user entered strings(app MUST respond to DTN_USERSTRING)
%DTS_RIGHTALIGN      = &H0020 ' right-align popup instead of left-align it

' end_r_commctrl

%DTN_DATETIMECHANGE  = %DTN_FIRST2 - 6 ' the systemtime has changed

TYPE NMDATETIMECHANGE
    hdr     AS NMHDR
    dwFlags AS DWORD        ' GDT_VALID or GDT_NONE
    st      AS SYSTEMTIME   ' valid iff dwFlags==GDT_VALID
END TYPE

%DTN_USERSTRINGA  = %DTN_FIRST2 - 5 ' the user has entered a string
%DTN_USERSTRINGW  = %DTN_FIRST - 5

TYPE NMDATETIMESTRINGA
    hdr           AS NMHDR
    pszUserString AS ASCIIZ PTR  ' string user entered
    st            AS SYSTEMTIME  ' app fills this in
    dwFlags       AS DWORD       ' GDT_VALID or GDT_NONE
END TYPE

TYPE NMDATETIMESTRINGW
    hdr           AS NMHDR
    pszUserString AS WSTRINGZ PTR  ' string user entered
    st            AS SYSTEMTIME    ' app fills this in
    dwFlags       AS DWORD         ' GDT_VALID or GDT_NONE
END TYPE

#IF %DEF(%UNICODE)
%DTN_USERSTRING   = %DTN_USERSTRINGW
TYPE NMDATETIMESTRING
    NMDATETIMESTRINGW
END TYPE
#ELSE
%DTN_USERSTRING   = %DTN_USERSTRINGA
TYPE NMDATETIMESTRING
    NMDATETIMESTRINGA
END TYPE
#ENDIF

%DTN_WMKEYDOWNA  = %DTN_FIRST2 - 4 ' modify keydown on app format field(X)
%DTN_WMKEYDOWNW  = %DTN_FIRST - 4

TYPE NMDATETIMEWMKEYDOWNA
    hdr       AS NMHDR
    nVirtKey  AS LONG       ' virtual key code of WM_KEYDOWN which MODIFIES an X field
    pszFormat AS ASCIIZ PTR ' format substring
    st        AS SYSTEMTIME ' current systemtime, app should modify based on key
END TYPE

TYPE NMDATETIMEWMKEYDOWNW
    hdr       AS NMHDR
    nVirtKey  AS LONG         ' virtual key code of WM_KEYDOWN which MODIFIES an X field
    pszFormat AS WSTRINGZ PTR ' format substring
    st        AS SYSTEMTIME   ' current systemtime, app should modify based on key
END TYPE

#IF %DEF(%UNICODE)
%DTN_WMKEYDOWN         = %DTN_WMKEYDOWNW
TYPE NMDATETIMEWMKEYDOWN
    NMDATETIMEWMKEYDOWNW
END TYPE
#ELSE
%DTN_WMKEYDOWN         = %DTN_WMKEYDOWNA
TYPE NMDATETIMEWMKEYDOWN
    NMDATETIMEWMKEYDOWNA
END TYPE
#ENDIF


%DTN_FORMATA  = %DTN_FIRST2 - 3 ' query display for app format field(X)
%DTN_FORMATW  = %DTN_FIRST - 3

TYPE NMDATETIMEFORMATA
    hdr        AS NMHDR
    pszFormat  AS ASCIIZ PTR  ' format substring
    st         AS SYSTEMTIME  ' current systemtime
    pszDisplay AS ASCIIZ PTR  ' string to display
    szDisplay  AS ASCIIZ * 64 ' buffer pszDisplay originally points at
END TYPE

TYPE NMDATETIMEFORMATW
    hdr        AS NMHDR
    pszFormat  AS WSTRINGZ PTR  ' format substring
    st         AS SYSTEMTIME    ' current systemtime
    pszDisplay AS WSTRINGZ PTR  ' string to display
    szDisplay  AS WSTRINGZ * 64 ' buffer pszDisplay originally points at
END TYPE

#IF %DEF(%UNICODE)
%DTN_FORMAT          = %DTN_FORMATW
TYPE NMDATETIMEFORMAT
    NMDATETIMEFORMATW
END TYPE
#ELSE
%DTN_FORMAT          = %DTN_FORMATA
TYPE NMDATETIMEFORMAT
    NMDATETIMEFORMATA
END TYPE
#ENDIF


%DTN_FORMATQUERYA = %DTN_FIRST2 - 2 ' query formatting info for app format field(X)
%DTN_FORMATQUERYW = %DTN_FIRST - 2

TYPE NMDATETIMEFORMATQUERYA
    hdr       AS NMHDR
    pszFormat AS ASCIIZ PTR ' format substring
    szMax     AS SIZE       ' max bounding rectangle app will use for this format string
END TYPE

TYPE NMDATETIMEFORMATQUERYW
    hdr       AS NMHDR
    pszFormat AS WSTRINGZ PTR ' format substring
    szMax     AS SIZE         ' max bounding rectangle app will use for this format string
END TYPE

#IF %DEF(%UNICODE)
%DTN_FORMATQUERY      = %DTN_FORMATQUERYW
TYPE NMDATETIMEFORMATQUERY
    NMDATETIMEFORMATQUERYW
END TYPE
#ELSE
%DTN_FORMATQUERY      = %DTN_FORMATQUERYA
TYPE NMDATETIMEFORMATQUERY
    NMDATETIMEFORMATQUERYA
END TYPE
#ENDIF


%DTN_DROPDOWN   = %DTN_FIRST2 - 1 ' MonthCal has dropped down
%DTN_CLOSEUP    = %DTN_FIRST2     ' MonthCal is popping up

%GDTR_MIN       = &H0001
%GDTR_MAX       = &H0002

%GDT_ERROR      = -1
%GDT_VALID      = 0
%GDT_NONE       = 1

#ENDIF  ' %WIN32
#ENDIF  ' IF NOT %DEF(%NODATETIMEPICK)



'======= IP Address edit control ==============================================

#IF (%WIN32_IE >= &H0400)

#IF NOT %DEF(%NOIPADDRESS)


' Messages sent to IPAddress controls

%IPM_CLEARADDRESS  = %WM_USER + 100 ' no parameters
%IPM_SETADDRESS    = %WM_USER + 101 ' lparam = TCP/IP address
%IPM_GETADDRESS    = %WM_USER + 102 ' lresult = # of non black fields. lparam = LPDWORD for TCP/IP address
%IPM_SETRANGE      = %WM_USER + 103 ' wparam = field, lparam = range
%IPM_SETFOCUS      = %WM_USER + 104 ' wparam = field
%IPM_ISBLANK       = %WM_USER + 105 ' no parameters

$$WC_IPADDRESSW = "SysIPAddress32"$$
$WC_IPADDRESSA = "SysIPAddress32"

#IF %DEF(%UNICODE)
MACRO WC_IPADDRESS = $$WC_IPADDRESSW
#ELSE
MACRO WC_IPADDRESS = $WC_IPADDRESSA
#ENDIF

%IPN_FIELDCHANGED  = %IPN_FIRST

TYPE NMIPADDRESS
    hdr    AS NMHDR
    iField AS LONG
    iValue AS LONG
END TYPE

' The following is a useful macro for passing the range values in the
' IPM_SETRANGE message.

MACRO MAKEIPRANGE(low,high)=MAK(WORD,low,high)

' And this is a useful macro for making the IP Address to be passed
' as a LPARAM.

MACRO MAKEIPADDRESS(b1,b2,b3,b4)=MAK(DWORD,MAK(WORD,b4,b3),MAK(WORD,b2,b1))

' Get individual number

MACRO FUNCTION FIRST_IPADDRESS(x) =HI(BYTE,HI(WORD,x))
MACRO FUNCTION SECOND_IPADDRESS(x)=LO(BYTE,HI(WORD,x))
MACRO FUNCTION THIRD_IPADDRESS(x) =HI(BYTE,LO(WORD,x))
MACRO FOURTH_IPADDRESS(x)         =LO(BYTE,x)

#ENDIF  ' NOIPADDRESS



' ====================== Pager Control =============================

#IF NOT %DEF(%NOPAGESCROLLER)

'Pager Class Name

$$WC_PAGESCROLLERW = "SysPager"$$
$WC_PAGESCROLLERA  = "SysPager"

#IF %DEF(%UNICODE)
MACRO WC_PAGESCROLLER = $$WC_PAGESCROLLERW
#ELSE
MACRO WC_PAGESCROLLER = $WC_PAGESCROLLERA
#ENDIF


'------------------------------------------------------------------------------
' Pager Control Styles
'------------------------------------------------------------------------------
' begin_r_commctrl
%PGS_VERT                = &H00000000
%PGS_HORZ                = &H00000001
%PGS_AUTOSCROLL          = &H00000002
%PGS_DRAGNDROP           = &H00000004
' end_r_commctrl


'------------------------------------------------------------------------------
' Pager Button State
'------------------------------------------------------------------------------
'The scroll can be in one of the following control State
%PGF_INVISIBLE       = 0      ' Scroll button is not visible
%PGF_NORMAL          = 1      ' Scroll button is in normal state
%PGF_GRAYED          = 2      ' Scroll button is in grayed state
%PGF_DEPRESSED       = 4      ' Scroll button is in depressed state
%PGF_HOT             = 8      ' Scroll button is in hot state


' The following identifiers specifies the button control
%PGB_TOPORLEFT       = 0
%PGB_BOTTOMORRIGHT   = 1

'------------------------------------------------------------------------------
' Pager Control  Messages
'------------------------------------------------------------------------------
%PGM_SETCHILD            = %PGM_FIRST + 1  ' lParam == hwnd
SUB Pager_SetChild (BYVAL hwnd AS DWORD, BYVAL hwndChild AS DWORD)
    SendMessage hwnd, %PGM_SETCHILD, 0, hwndChild
END SUB

%PGM_RECALCSIZE          = %PGM_FIRST + 2
SUB Pager_RecalcSize (BYVAL hwnd AS DWORD)
    SendMessage  hwnd, %PGM_RECALCSIZE, 0, 0
END SUB

%PGM_FORWARDMOUSE        = %PGM_FIRST + 3
SUB Pager_ForwardMouse (BYVAL hwnd AS DWORD, BYVAL bForward AS BYTE)
    SendMessage hwnd, %PGM_FORWARDMOUSE, bForward, 0
END SUB

%PGM_SETBKCOLOR          = %PGM_FIRST + 4
FUNCTION Pager_SetBkColor (BYVAL hwnd AS DWORD, BYVAL clr AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %PGM_SETBKCOLOR, 0, clr)
END FUNCTION

%PGM_GETBKCOLOR          = %PGM_FIRST + 5
FUNCTION Pager_GetBkColor (BYVAL hwnd AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwnd, %PGM_GETBKCOLOR, 0, 0)
END FUNCTION

%PGM_SETBORDER          = %PGM_FIRST + 6
FUNCTION Pager_SetBorder (BYVAL hwnd AS DWORD, BYVAL iBorder AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %PGM_SETBORDER, 0, iBorder)
END FUNCTION

%PGM_GETBORDER          = %PGM_FIRST + 7
FUNCTION Pager_GetBorder (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %PGM_GETBORDER, 0, 0)
END FUNCTION

%PGM_SETPOS              = %PGM_FIRST + 8
FUNCTION Pager_SetPos (BYVAL hwnd AS DWORD, BYVAL iPos AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %PGM_SETPOS, 0, iPos)
END FUNCTION

%PGM_GETPOS              = %PGM_FIRST + 9
FUNCTION Pager_GetPos (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %PGM_GETPOS, 0, 0)
END FUNCTION

%PGM_SETBUTTONSIZE       = %PGM_FIRST + 10
FUNCTION Pager_SetButtonSize (BYVAL hwnd AS DWORD, BYVAL iSize AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %PGM_SETBUTTONSIZE, 0, iSize)
END FUNCTION

%PGM_GETBUTTONSIZE       = %PGM_FIRST + 11
FUNCTION Pager_GetButtonSize (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %PGM_GETBUTTONSIZE, 0, 0)
END FUNCTION

%PGM_GETBUTTONSTATE      = %PGM_FIRST + 12
FUNCTION Pager_GetButtonState (BYVAL hwnd AS DWORD, BYVAL iButton AS LONG) AS DWORD
    FUNCTION = SendMessage(hwnd, %PGM_GETBUTTONSTATE, 0, iButton)
END FUNCTION

%PGM_GETDROPTARGET       = %CCM_GETDROPTARGET
SUB Pager_GetDropTarget (BYVAL hwnd AS DWORD, ppdt AS DWORD)
    SendMessage hwnd, %PGM_GETDROPTARGET, 0, VARPTR(ppdt)
END SUB

'---------------------------------------------------------------------------------------
'Pager Control Notification Messages
'---------------------------------------------------------------------------------------


' PGN_SCROLL Notification Message

%PGN_SCROLL      = %PGN_FIRST - 1

%PGF_SCROLLUP    = 1
%PGF_SCROLLDOWN  = 2
%PGF_SCROLLLEFT  = 4
%PGF_SCROLLRIGHT = 8


'Keys down
%PGK_SHIFT       = 1
%PGK_CONTROL     = 2
%PGK_MENU        = 4


' This structure is sent along with PGN_SCROLL notifications

TYPE NMPGSCROLL BYTE
    hdr      AS NMHDR
    fwKeys   AS WORD  ' Specifies which keys are down when this notification is sent
    rcParent AS RECT  ' Contains Parent Window Rect
    iDir     AS LONG  ' Scrolling Direction
    iXpos    AS LONG  ' Horizontal scroll position
    iYpos    AS LONG  ' Vertical scroll position
    iScroll  AS LONG  ' [in/out] Amount to scroll
END TYPE


' PGN_CALCSIZE Notification Message

%PGN_CALCSIZE    = %PGN_FIRST - 2

%PGF_CALCWIDTH   = 1
%PGF_CALCHEIGHT  = 2

TYPE NMPGCALCSIZE
    hdr     AS NMHDR
    dwFlag  AS DWORD
    iWidth  AS LONG
    iHeight AS LONG
END TYPE

' PGN_HOTITEMCHANGE Notification Message

%PGN_HOTITEMCHANGE = %PGN_FIRST - 3

'
'The PGN_HOTITEMCHANGE notification uses these notification
'flags defined in TOOLBAR:
'
'#define HICF_ENTERING       0x00000010          ' idOld is invalid
'#define HICF_LEAVING        0x00000020          ' idNew is invalid
'

' Structure for PGN_HOTITEMCHANGE notification
'
TYPE NMPGHOTITEM
    hdr     AS NMHDR
    idOld   AS LONG
    idNew   AS LONG
    dwFlags AS DWORD   ' HICF_*
END TYPE


#ENDIF  ' NOPAGESCROLLER

'==============================================================================

'
' === Native Font Control ===
'

#IF NOT %DEF(%NONATIVEFONTCTL)

'NativeFont Class Name
$$WC_NATIVEFONTCTLW = "NativeFontCtl"$$
$WC_NATIVEFONTCTLA  = "NativeFontCtl"

#IF %DEF(%UNICODE)
MACRO WC_NATIVEFONTCTL = $$WC_NATIVEFONTCTLW
#ELSE
MACRO WC_NATIVEFONTCTL = $WC_NATIVEFONTCTLA
#ENDIF

' begin_r_commctrl

' style definition
%NFS_EDIT         = &H0001
%NFS_STATIC       = &H0002
%NFS_LISTCOMBO    = &H0004
%NFS_BUTTON       = &H0008
%NFS_ALL          = &H0010
%NFS_USEFONTASSOC = &H0020

' end_r_commctrl

#ENDIF  ' NONATIVEFONTCTL



'==============================================================================
' BUTTON CONTROL

#IF NOT %DEF(%NOBUTTON)

#IF %DEF(%WIN32)

' Button Class Name
$WC_BUTTONA  = "Button"
$$WC_BUTTONW = "Button"$$

#IF %DEF(%UNICODE)
MACRO WC_BUTTON = $$WC_BUTTONW
#ELSE
MACRO WC_BUTTON = $WC_BUTTONA
#ENDIF

#ELSE
MACRO WC_BUTTON = "Button"
#ENDIF

#IF (%WIN32_WINNT >= &H0501)
%BUTTON_IMAGELIST_ALIGN_LEFT   = 0
%BUTTON_IMAGELIST_ALIGN_RIGHT  = 1
%BUTTON_IMAGELIST_ALIGN_TOP    = 2
%BUTTON_IMAGELIST_ALIGN_BOTTOM = 3
%BUTTON_IMAGELIST_ALIGN_CENTER = 4       ' Doesn't draw text

TYPE BUTTON_IMAGELIST
    himl   AS DWORD   ' HIMAGELIST ' Images: Normal, Hot, Pushed, Disabled. If count is less than 4, we use index 1
    MARGIN AS RECT    ' Margin around icon.
    uAlign AS DWORD
END TYPE

%BCM_GETIDEALSIZE      = (%BCM_FIRST + &H0001)
FUNCTION Button_GetIdealSize (BYVAL hwnd AS DWORD, psize AS SIZE) AS LONG
    FUNCTION = SendMessage(hwnd, %BCM_GETIDEALSIZE, 0, VARPTR(psize))
END FUNCTION

%BCM_SETIMAGELIST      = (%BCM_FIRST + &H0002)
FUNCTION Button_SetImageList (BYVAL hwnd AS DWORD, _
    pbuttonImagelist AS BUTTON_IMAGELIST) AS LONG
    FUNCTION = SendMessage(hwnd, %BCM_SETIMAGELIST, 0, VARPTR(pbuttonImagelist))
END FUNCTION

%BCM_GETIMAGELIST      = (%BCM_FIRST + &H0003)
FUNCTION Button_GetImageList (BYVAL hwnd AS DWORD, _
    pbuttonImagelist AS BUTTON_IMAGELIST) AS LONG
    FUNCTION = SendMessage(hwnd, %BCM_GETIMAGELIST, 0, VARPTR(pbuttonImagelist))
END FUNCTION

%BCM_SETTEXTMARGIN     = (%BCM_FIRST + &H0004)
FUNCTION Button_SetTextMargin (BYVAL hwnd AS DWORD, pmargin AS RECT) AS LONG
    FUNCTION = SendMessage(hwnd, %BCM_SETTEXTMARGIN, 0, VARPTR(pmargin))
END FUNCTION

%BCM_GETTEXTMARGIN     = (%BCM_FIRST + &H0005)
FUNCTION Button_GetTextMargin (BYVAL hwnd AS DWORD, pmargin AS RECT) AS LONG
    FUNCTION = SendMessage(hwnd, %BCM_GETTEXTMARGIN, 0, VARPTR(pmargin))
END FUNCTION

TYPE NMBCHOTITEM
    hdr     AS NMHDR
    dwFlags AS DWORD           ' %HICF_*
END TYPE

%BCN_HOTITEMCHANGE     = (%BCN_FIRST + &H0001)

%BST_HOT          = &H0200

#ENDIF  ' %WIN32_WINNT >= &H0501

#IF %WIN32_WINNT >= &H0600

' BUTTON STATE FLAGS
%BST_DROPDOWNPUSHED    = &H0400

' begin_r_commctrl

' BUTTON STYLES
%BS_SPLITBUTTON        = &H0000000C
%BS_DEFSPLITBUTTON     = &H0000000D
%BS_COMMANDLINK        = &H0000000E
%BS_DEFCOMMANDLINK     = &H0000000F

' SPLIT BUTTON INFO mask flags
%BCSIF_GLYPH           = &H0001
%BCSIF_IMAGE           = &H0002
%BCSIF_STYLE           = &H0004
%BCSIF_SIZE            = &H0008

' SPLIT BUTTON STYLE flags
%BCSS_NOSPLIT          = &H0001
%BCSS_STRETCH          = &H0002
%BCSS_ALIGNLEFT        = &H0004
%BCSS_IMAGE            = &H0008

' end_r_commctrl

' BUTTON STRUCTURES
TYPE BUTTON_SPLITINFO
    mask        AS DWORD
    himlGlyph   AS DWORD  ' HIMAGELIST  ' interpreted as WCHAR if BCSIF_GLYPH is set
    uSplitStyle AS DWORD
    SIZE        AS SIZEL
END TYPE

' BUTTON MESSAGES
%BCM_SETDROPDOWNSTATE   = (%BCM_FIRST + &H0006)
FUNCTION Button_SetDropDownState (BYVAL hwnd AS DWORD, _
    BYVAL fDropDown AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %BCM_SETDROPDOWNSTATE, fDropDown, 0)
END FUNCTION

%BCM_SETSPLITINFO       = (%BCM_FIRST + &H0007)
FUNCTION Button_SetSplitInfo (BYVAL hwnd AS DWORD, pInfo AS BUTTON_SPLITINFO) _
    AS LONG
    FUNCTION = SendMessage(hwnd, %BCM_SETSPLITINFO, 0, VARPTR(pInfo))
END FUNCTION

%BCM_GETSPLITINFO       = (%BCM_FIRST + &H0008)
FUNCTION Button_GetSplitInfo (BYVAL hwnd AS DWORD, pInfo AS BUTTON_SPLITINFO) _
    AS LONG
    FUNCTION = SendMessage(hwnd, %BCM_GETSPLITINFO, 0, VARPTR(pInfo))
END FUNCTION

%BCM_SETNOTE            = (%BCM_FIRST + &H0009)
FUNCTION Button_SetNote (BYVAL hwnd AS DWORD, psz AS WSTRINGZ) AS LONG
    FUNCTION = SendMessage(hwnd, %BCM_SETNOTE, 0, VARPTR(psz))
END FUNCTION

%BCM_GETNOTE            = (%BCM_FIRST + &H000A)
FUNCTION Button_GetNote (BYVAL hwnd AS DWORD, psz AS WSTRINGZ, _
    BYVAL pcc AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %BCM_GETNOTE, pcc, VARPTR(psz))
END FUNCTION

%BCM_GETNOTELENGTH      = (%BCM_FIRST + &H000B)
FUNCTION Button_GetNoteLength (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %BCM_GETNOTELENGTH, 0, 0)
END FUNCTION

#IF %WIN32_WINNT >= &H0600
' Macro to use on a button or command link to display an elevated icon
%BCM_SETSHIELD          = (%BCM_FIRST + &H000C)
FUNCTION Button_SetElevationRequiredState (BYVAL hwnd AS DWORD, _
    BYVAL fRequired AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %BCM_SETSHIELD, 0, fRequired)
END FUNCTION
#ENDIF

' Value to pass to BCM_SETIMAGELIST to indicate that no glyph should be
' displayed
%BCCL_NOGLYPH  = &HFFFFFFFF???  '(HIMAGELIST)(-1)

' NOTIFICATION MESSAGES
TYPE NMBCDROPDOWN
    hdr      AS NMHDR
    rcButton AS RECT
END TYPE

%BCN_DROPDOWN          = (%BCN_FIRST + &H0002)

#ENDIF  ' %WIN32_WINNT >= &H0600


#ENDIF  ' IF NOT %DEF(%NOBUTTON)

' =====================  End Button Control =========================

' ====================== Static Control =============================

#IF NOT %DEF(%NOSTATIC)

#IF %DEF(%WIN32)

' Static Class Name
$WC_STATICA  = "Static"
$$WC_STATICW = "Static"$$

#IF %DEF(%UNICODE)
MACRO WC_STATIC = $$WC_STATICW
#ELSE
MACRO WC_STATIC = $WC_STATICA
#ENDIF

#ELSE
MACRO WC_STATIC = "Static"
#ENDIF

#ENDIF  ' NOSTATIC

' =====================  End Static Control =========================

'==============================================================================
' EDIT CONTROL

#IF NOT %DEF(%NOEDIT)

#IF %DEF(%WIN32)

' Edit Class Name
$WC_EDITA  = "Edit"
$$WC_EDITW = "Edit"$$

#IF %DEF(%UNICODE)
MACRO WC_EDIT = $$WC_EDITW
#ELSE
MACRO WC_EDIT = $WC_EDITA
#ENDIF

#ELSE
MACRO WC_EDIT = "Edit"
#ENDIF


#IF (%WIN32_WINNT >= &H0501)
%EM_SETCUEBANNER = %ECM_FIRST + 1
FUNCTION Edit_SetCueBannerText (BYVAL hwnd AS DWORD, lpcwText AS WSTRINGZ) AS LONG
    FUNCTION = SendMessage(hwnd, %EM_SETCUEBANNER, 0, VARPTR(lpcwText))
END FUNCTION

FUNCTION Edit_SetCueBannerTextFocused (BYVAL hwnd AS DWORD, _
    lpcwText AS WSTRINGZ, BYVAL fDrawFocused AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %EM_SETCUEBANNER, fDrawFocused, VARPTR(lpcwText))
END FUNCTION

%EM_GETCUEBANNER = %ECM_FIRST + 2
FUNCTION Edit_GetCueBannerText (BYVAL hwnd AS DWORD, lpwText AS WSTRINGZ, _
    BYVAL cchText AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %EM_GETCUEBANNER, VARPTR(lpwText), cchText)
END FUNCTION

TYPE EDITBALLOONTIP
    cbStruct AS DWORD
    pszTitle AS WSTRINGZ PTR
    pszText  AS WSTRINGZ PTR
    ttiIcon  AS LONG
END TYPE

%EM_SHOWBALLOONTIP = %ECM_FIRST + 3 ' Show a balloon tip associated to the edit control
FUNCTION Edit_ShowBalloonTip (BYVAL hwnd AS DWORD, _
    peditballoontip AS EDITBALLOONTIP) AS LONG
    FUNCTION = SendMessage(hwnd, %EM_SHOWBALLOONTIP, 0, VARPTR(peditballoontip))
END FUNCTION

%EM_HIDEBALLOONTIP = %ECM_FIRST + 4 ' Hide any balloon tip associated with the edit control
FUNCTION Edit_HideBalloonTip (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %EM_HIDEBALLOONTIP, 0, 0)
END FUNCTION

#ENDIF   ' (%WIN32_WINNT >= &H0501)

#IF %WIN32_WINNT >= &H0600
%EM_SETHILITE      = %ECM_FIRST + 5
SUB Edit_SetHilite (BYVAL hwndCtl AS DWORD, BYVAL ichStart AS LONG, _
    BYVAL ichEnd AS LONG)
    SendMessage hwndCtl, %EM_SETHILITE, ichStart, ichEnd
END SUB
%EM_GETHILITE      = %ECM_FIRST + 6
FUNCTION Edit_GetHilite (BYVAL hwndCtl AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwndCtl, %EM_GETHILITE, 0, 0)
END FUNCTION
#ENDIF  ' #IF %WIN32_WINNT >= &H0600

#ENDIF  ' %NOEDIT


' =====================  End Edit Control =========================


'==============================================================================
' LISTBOX CONTROL

#IF NOT %DEF(%NOLISTBOX)

#IF %DEF(%WIN32)

' Listbox Class Name
$WC_LISTBOXA  = "ListBox"
$$WC_LISTBOXW = "ListBox"$$

#IF %DEF(%UNICODE)
MACRO WC_LISTBOX = $$WC_LISTBOXW
#ELSE
MACRO WC_LISTBOX = $WC_LISTBOXA
#ENDIF

#ELSE
MACRO WC_LISTBOX = "ListBox"
#ENDIF

#ENDIF  ' NOLISTBOX

' =====================  End Listbox Control =========================

'==============================================================================
' COMBOBOX CONTROL

#IF NOT %DEF(%NOCOMBOBOX)

#IF %DEF(%WIN32)

' Combobox Class Name
$WC_COMBOBOXA  = "ComboBox"
$$WC_COMBOBOXW = "ComboBox"$$

#IF %DEF(%UNICODE)
MACRO WC_COMBOBOX = $$WC_COMBOBOXW
#ELSE
MACRO WC_COMBOBOX = $WC_COMBOBOXA
#ENDIF

#ELSE
MACRO WC_COMBOBOX = "ComboBox"
#ENDIF

#ENDIF  ' NOCOMBOBOX


#IF (%WIN32_WINNT >= &H0501)

' custom combobox control messages
%CB_SETMINVISIBLE      = (%CBM_FIRST + 1)
%CB_GETMINVISIBLE      = (%CBM_FIRST + 2)
%CB_SETCUEBANNER       = (%CBM_FIRST + 3)
%CB_GETCUEBANNER       = (%CBM_FIRST + 4)

FUNCTION ComboBox_SetMinVisible (BYVAL hwnd AS DWORD, _
    BYVAL iMinVisible AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %CB_SETMINVISIBLE, iMinVisible, 0)
END FUNCTION

FUNCTION ComboBox_GetMinVisible (BYVAL hwnd AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %CB_GETMINVISIBLE, 0, 0)
END FUNCTION

FUNCTION ComboBox_SetCueBannerText (BYVAL hwnd AS DWORD, _
    lpcwText AS WSTRINGZ) AS LONG
    FUNCTION = SendMessage(hwnd, %CB_SETCUEBANNER, 0, VARPTR(lpcwText))
END FUNCTION

FUNCTION ComboBox_GetCueBannerText (BYVAL hwnd AS DWORD, lpwText AS WSTRINGZ, _
    BYVAL cchText AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %CB_GETCUEBANNER, VARPTR(lpwText), cchText)
END FUNCTION

#ENDIF  ' #IF (%WIN32_WINNT >= &H0501)

' =====================  End Combobox Control =========================

' ====================== Scrollbar Control ============================

#IF NOT %DEF(%NOSCROLLBAR)

#IF %DEF(%WIN32)

' Scrollbar Class Name
$WC_SCROLLBARA  = "ScrollBar"
$$WC_SCROLLBARW = "ScrollBar"$$

#IF %DEF(%UNICODE)
MACRO WC_SCROLLBAR = $$WC_SCROLLBARW
#ELSE
MACRO WC_SCROLLBAR = $WC_SCROLLBARA
#ENDIF

#ELSE
MACRO WC_SCROLLBAR = "ScrollBar"
#ENDIF

#ENDIF  ' NOSCROLLBAR


' ===================== End Scrollbar Control =========================

' ===================== Task Dialog =========================
#IF NOT %DEF(%NOTASKDIALOG)
' Task Dialog is only available starting Windows Vista
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)


DECLARE FUNCTION PFTASKDIALOGCALLBACK(BYVAL hwnd AS DWORD, _
    BYVAL msg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG, _
    BYVAL lpRefData AS DWORD) AS LONG  ' HRESULT

MACRO TASKDIALOG_FLAGS_enum=LONG
ENUM TASKDIALOG_FLAGS SINGULAR BITS
    TDF_ENABLE_HYPERLINKS               = &H0001
    TDF_USE_HICON_MAIN
    TDF_USE_HICON_FOOTER
    TDF_ALLOW_DIALOG_CANCELLATION
    TDF_USE_COMMAND_LINKS
    TDF_USE_COMMAND_LINKS_NO_ICON
    TDF_EXPAND_FOOTER_AREA
    TDF_EXPANDED_BY_DEFAULT
    TDF_VERIFICATION_FLAG_CHECKED
    TDF_SHOW_PROGRESS_BAR
    TDF_SHOW_MARQUEE_PROGRESS_BAR
    TDF_CALLBACK_TIMER
    TDF_POSITION_RELATIVE_TO_WINDOW
    TDF_RTL_LAYOUT
    TDF_NO_DEFAULT_RADIO_BUTTON
    TDF_CAN_BE_MINIMIZED
END ENUM

MACRO TASKDIALOG_MESSAGES_enum=LONG
ENUM TASKDIALOG_MESSAGES SINGULAR
    TDM_NAVIGATE_PAGE      = %WM_USER+101
    TDM_CLICK_BUTTON                        ' wParam = Button ID
    TDM_SET_MARQUEE_PROGRESS_BAR            ' wParam = 0(nonMarque) wParam != 0(Marquee)
    TDM_SET_PROGRESS_BAR_STATE              ' wParam = new progress state
    TDM_SET_PROGRESS_BAR_RANGE              ' lParam = MAKELPARAM(nMinRange, nMaxRange)
    TDM_SET_PROGRESS_BAR_POS                ' wParam = new position
    TDM_SET_PROGRESS_BAR_MARQUEE            ' wParam = 0(stop marquee), wParam != 0(start marquee), lparam = speed(milliseconds between repaints)
    TDM_SET_ELEMENT_TEXT                    ' wParam = element(TASKDIALOG_ELEMENTS), lParam = new element text(LPCWSTR)
    TDM_CLICK_RADIO_BUTTON = %WM_USER+110   ' wParam = Radio Button ID
    TDM_ENABLE_BUTTON                       ' lParam = 0(disable), lParam != 0(enable), wParam = Button ID
    TDM_ENABLE_RADIO_BUTTON                 ' lParam = 0(disable), lParam != 0(enable), wParam = Radio Button ID
    TDM_CLICK_VERIFICATION                  ' wParam = 0(unchecked), 1(checked), lParam = 1(set key focus)
    TDM_UPDATE_ELEMENT_TEXT                 ' wParam = element(TASKDIALOG_ELEMENTS), lParam = new element text(LPCWSTR)
    TDM_SET_BUTTON_ELEVATION_REQUIRED_STATE ' wParam = Button ID, lParam = 0(elevation not required), lParam != 0(elevation required)
    TDM_UPDATE_ICON                         ' wParam = icon element(TASKDIALOG_ICON_ELEMENTS), lParam = new icon(hIcon if TDF_USE_HICON_* was set, PCWSTR otherwise)
END ENUM

MACRO TASKDIALOG_NOTIFICATIONS_enum=LONG
ENUM TASKDIALOG_NOTIFICATIONS SINGULAR
    TDN_CREATED
    TDN_NAVIGATED
    TDN_BUTTON_CLICKED                      ' wParam = Button ID
    TDN_HYPERLINK_CLICKED                   ' lParam = (LPCWSTR)pszHREF
    TDN_TIMER                               ' wParam = Milliseconds since dialog created or timer reset
    TDN_DESTROYED
    TDN_RADIO_BUTTON_CLICKED                ' wParam = Radio Button ID
    TDN_DIALOG_CONSTRUCTED
    TDN_VERIFICATION_CLICKED                ' wParam = 1 if checkbox checked, 0 if not, lParam is unused and always 0
    TDN_HELP
    TDN_EXPANDO_BUTTON_CLICKED              ' wParam = 0(dialog is now collapsed), wParam != 0(dialog is now expanded)
END ENUM

TYPE TASKDIALOG_BUTTON
    nButtonID     AS LONG
    pszButtonText AS WSTRINGZ PTR
END TYPE

MACRO TASKDIALOG_ELEMENTS_enum=LONG
ENUM TASKDIALOG_ELEMENTS SINGULAR
    TDE_CONTENT
    TDE_EXPANDED_INFORMATION
    TDE_FOOTER
    TDE_MAIN_INSTRUCTION
END ENUM

MACRO TASKDIALOG_ICON_ELEMENTS_enum=LONG
ENUM TASKDIALOG_ICON_ELEMENTS SINGULAR
    TDIE_ICON_MAIN
    TDIE_ICON_FOOTER
END ENUM

%TD_WARNING_ICON     = -1   ' MAKEINTRESOURCEW(-1)
%TD_ERROR_ICON       = -2   ' MAKEINTRESOURCEW(-2)
%TD_INFORMATION_ICON = -3   ' MAKEINTRESOURCEW(-3)
%TD_SHIELD_ICON      = -4   ' MAKEINTRESOURCEW(-4)

#ENDIF  '(%NTDDI_VERSION >= %NTDDI_VISTA)


#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

MACRO TASKDIALOG_COMMON_BUTTON_FLAGS_enum=LONG
ENUM TASKDIALOG_COMMON_BUTTON_FLAGS SINGULAR BITS
    TDCBF_OK_BUTTON     = &H0001  ' selected control return value IDOK
    TDCBF_YES_BUTTON              ' selected control return value IDYES
    TDCBF_NO_BUTTON               ' selected control return value IDNO
    TDCBF_CANCEL_BUTTON           ' selected control return value IDCANCEL
    TDCBF_RETRY_BUTTON            ' selected control return value IDRETRY
    TDCBF_CLOSE_BUTTON            ' selected control return value IDCLOSE
END ENUM

UNION TASKDIALOGCONFIG_union1
    hMainIcon   AS DWORD    ' HICON
    pszMainIcon AS WSTRINGZ PTR
END UNION

UNION TASKDIALOGCONFIG_union2
    hFooterIcon   AS DWORD    ' HICON
    pszFooterIcon AS WSTRINGZ PTR
END UNION

TYPE TASKDIALOGCONFIG
    cbSize                  AS DWORD
    hwndParent              AS DWORD    ' HWND
    hInstance               AS DWORD    ' HINSTANCE                ' used for MAKEINTRESOURCE() strings
    dwFlags                 AS TASKDIALOG_FLAGS_enum               ' TASKDIALOG_FLAGS(TDF_XXX) flags
    dwCommonButtons         AS TASKDIALOG_COMMON_BUTTON_FLAGS_enum ' TASKDIALOG_COMMON_BUTTON(TDCBF_XXX) flags
    pszWindowTitle          AS WSTRINGZ PTR                        ' string or MAKEINTRESOURCE()
    TASKDIALOGCONFIG_union1
    pszMainInstruction      AS WSTRINGZ PTR
    pszContent              AS WSTRINGZ PTR
    cButtons                AS DWORD
    pButtons                AS TASKDIALOG_BUTTON PTR
    nDefaultButton          AS LONG
    cRadioButtons           AS DWORD
    pRadioButtons           AS TASKDIALOG_BUTTON PTR
    nDefaultRadioButton     AS LONG
    pszVerificationText     AS WSTRINGZ PTR
    pszExpandedInformation  AS WSTRINGZ PTR
    pszExpandedControlText  AS WSTRINGZ PTR
    pszCollapsedControlText AS WSTRINGZ PTR
    TASKDIALOGCONFIG_union2
    pszFooter               AS WSTRINGZ PTR
    pfCallback              AS DWORD   ' PFTASKDIALOGCALLBACK
    lpCallbackData          AS DWORD
    cxWidth                 AS DWORD                               ' width of the Task Dialog's client area in DLU's. If 0, Task Dialog will calculate the ideal width.
END TYPE


' [ComCtl32.dll version 6 - need to load it explicitly for these functions]

DECLARE FUNCTION TaskDialogIndirect ALIAS "TaskDialogIndirect" ( _
    pTaskConfig AS TASKDIALOGCONFIG, pnButton AS LONG, pnRadioButton AS LONG, _
    pfVerificationFlagChecked AS LONG) AS LONG  ' HRESULT

DECLARE FUNCTION TaskDialog ALIAS "TaskDialog" (BYVAL hwndParent AS DWORD, _
    BYVAL hInstance AS DWORD, pszWindowTitle AS WSTRINGZ, _
    pszMainInstruction AS WSTRINGZ, pszContent AS WSTRINGZ, _
    BYVAL dwCommonButtons AS TASKDIALOG_COMMON_BUTTON_FLAGS_enum, _
    pszIcon AS WSTRINGZ, pnButton AS LONG) AS LONG  ' HRESULT

#ENDIF  '(%NTDDI_VERSION >= %NTDDI_VISTA)
#ENDIF  ' %NOTASKDIALOG


' ==================== End TaskDialog =======================


'====== MUI APIs =============================================================

#IF NOT %DEF(%NOMUI)

DECLARE SUB InitMUILanguage LIB "ComCtl32.dll" ALIAS "InitMUILanguage" _
   (BYVAL uiLang AS DWORD)

DECLARE FUNCTION GetMUILanguage LIB "ComCtl32.dll" ALIAS "GetMUILanguage" () _
    AS DWORD

#ENDIF  ' NOMUI

#ENDIF  ' %WIN32_IE >= &H0400


#IF NOT %DEF(%NO_COMMCTRL_DA)
%COMMCTRL_DA_DEFINED = 1
'
'====== Dynamic Array routines ==========================================
'
' Note that the STL and other libraries have similar functionality.
' The routines here are specific to Windows and may not be as convenient
' or fully functional as those in other libraries.
'

%DA_LAST       = (&H7FFFFFFF)
%DA_ERR        = (-1)

DECLARE FUNCTION PFNDAENUMCALLBACK(p AS ANY, pData AS ANY) AS LONG

DECLARE FUNCTION PFNDAENUMCALLBACKCONST(p AS ANY, pData AS ANY) AS LONG

DECLARE FUNCTION PFNDACOMPARE(p1 AS ANY, p2 AS ANY, BYVAL lParam AS LONG) _
    AS LONG

DECLARE FUNCTION PFNDACOMPARECONST(p1 AS ANY, p2 AS ANY, _
    BYVAL lParam AS LONG) AS LONG


' Dynamic structure array
'struct _DSA;
'typedef struct _DSA *HDSA;

DECLARE FUNCTION DSA_Create LIB "ComCtl32.dll" ALIAS "DSA_Create" ( _
    BYVAL cbItem AS LONG, BYVAL cItemGrow AS LONG) AS DWORD

DECLARE FUNCTION DSA_Destroy LIB "ComCtl32.dll" ALIAS "DSA_Destroy" ( _
    BYVAL hdsa AS DWORD) AS LONG

DECLARE SUB DSA_DestroyCallback LIB "ComCtl32.dll" _
    ALIAS "DSA_DestroyCallback" (BYVAL hdsa AS DWORD, BYVAL pfnCB AS DWORD, _
    pData AS ANY)

DECLARE FUNCTION DSA_DeleteItem LIB "ComCtl32.dll" ALIAS "DSA_DeleteItem" ( _
    BYVAL hdsa AS DWORD, BYVAL i AS LONG) AS LONG

DECLARE FUNCTION DSA_DeleteAllItems LIB "ComCtl32.dll" _
    ALIAS "DSA_DeleteAllItems" (BYVAL hdsa AS DWORD) AS LONG

DECLARE SUB DSA_EnumCallback LIB "ComCtl32.dll" ALIAS "DSA_EnumCallback" ( _
    BYVAL hdsa AS DWORD, BYVAL pfnCB AS DWORD, pData AS ANY)

DECLARE FUNCTION DSA_InsertItem LIB "ComCtl32.dll" ALIAS "DSA_InsertItem" ( _
    BYVAL hdsa AS DWORD, BYVAL i AS LONG, pItem AS ANY) AS LONG

DECLARE FUNCTION DSA_GetItemPtr LIB "ComCtl32.dll" ALIAS "DSA_GetItemPtr" ( _
    BYVAL hdsa AS DWORD, BYVAL i AS LONG) AS DWORD

DECLARE FUNCTION DSA_GetItem LIB "ComCtl32.dll" ALIAS "DSA_GetItem" ( _
    BYVAL hdsa AS DWORD, BYVAL i AS LONG, pItem AS ANY) AS LONG

DECLARE FUNCTION DSA_SetItem LIB "ComCtl32.dll" ALIAS "DSA_SetItem" ( _
    BYVAL hdsa AS DWORD, BYVAL i AS LONG, pItem AS ANY) AS LONG

MACRO DSA_GetItemCount(hdsa)=PEEK(LONG,hdsa)

MACRO DSA_AppendItem(hdsa,pitem)=DSA_InsertItem(hdsa,%DA_LAST,pitem)

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

DECLARE FUNCTION DSA_Clone LIB "ComCtl32.dll" ALIAS "DSA_Clone" ( _
    BYVAL hdsa AS DWORD) AS DWORD

DECLARE FUNCTION DSA_GetSize LIB "ComCtl32.dll" ALIAS "DSA_GetSize" ( _
    OPTIONAL BYVAL hdsa AS DWORD) AS QUAD

DECLARE FUNCTION DSA_Sort LIB "ComCtl32.dll" ALIAS "DSA_Sort" ( _
    BYVAL hdsa AS DWORD, BYVAL pfnCompare AS DWORD, BYVAL lParam AS LONG) _
    AS LONG

#ENDIF  ' NTDDI_VISTA

%DSA_APPEND   = %DA_LAST
%DSA_ERR      = %DA_ERR

'#define PFNDSAENUMCALLBACK          PFNDAENUMCALLBACK
'#define PFNDSAENUMCALLBACKCONST     PFNDAENUMCALLBACKCONST
'#define PFNDSACOMPARE               PFNDACOMPARE
'#define PFNDSACOMPARECONST          PFNDACOMPARECONST

' Dynamic pointer array
'struct _DPA;
'typedef struct _DPA *HDPA;

DECLARE FUNCTION DPA_Create LIB "ComCtl32.dll" ALIAS "DPA_Create" ( _
    BYVAL cItemGrow AS LONG) AS DWORD

DECLARE FUNCTION DPA_CreateEx LIB "ComCtl32.dll" ALIAS "DPA_CreateEx" ( _
    BYVAL cpGrow AS LONG, OPTIONAL BYVAL hheap AS DWORD) AS DWORD

DECLARE FUNCTION DPA_Clone LIB "ComCtl32.dll" ALIAS "DPA_Clone" ( _
    BYVAL hdpa AS DWORD, OPTIONAL BYVAL hdpaNew AS DWORD) AS DWORD

DECLARE FUNCTION DPA_Destroy LIB "ComCtl32.dll" ALIAS "DPA_Destroy" ( _
    BYVAL hdpa AS DWORD) AS LONG

DECLARE SUB DPA_DestroyCallback LIB "ComCtl32.dll" _
    ALIAS "DPA_DestroyCallback" (BYVAL hdpa AS DWORD, BYVAL pfnCB AS DWORD, _
    pData AS ANY)

DECLARE FUNCTION DPA_DeletePtr LIB "ComCtl32.dll" ALIAS "DPA_DeletePtr" ( _
    BYVAL hdpa AS DWORD, BYVAL i AS LONG) AS DWORD

DECLARE FUNCTION DPA_DeleteAllPtrs LIB "ComCtl32.dll" _
    ALIAS "DPA_DeleteAllPtrs" (BYVAL hdpa AS DWORD) AS LONG

DECLARE SUB DPA_EnumCallback LIB "ComCtl32.dll" ALIAS "DPA_EnumCallback" _
   (BYVAL hdpa AS DWORD, BYVAL pfnCB AS DWORD, pData AS ANY)

DECLARE FUNCTION DPA_Grow LIB "ComCtl32.dll" ALIAS "DPA_Grow" ( _
    BYVAL hdpa AS DWORD, BYVAL cp AS LONG) AS LONG

DECLARE FUNCTION DPA_InsertPtr LIB "ComCtl32.dll" ALIAS "DPA_InsertPtr" ( _
    BYVAL hdpa AS DWORD, BYVAL i AS LONG, p AS ANY) AS LONG

DECLARE FUNCTION DPA_SetPtr LIB "ComCtl32.dll" ALIAS "DPA_SetPtr" ( _
    BYVAL hdpa AS DWORD, BYVAL i AS LONG, p AS ANY) AS LONG

DECLARE FUNCTION DPA_GetPtr LIB "ComCtl32.dll" ALIAS "DPA_GetPtr" ( _
    BYVAL hdpa AS DWORD, BYVAL i AS DWORD) AS DWORD

DECLARE FUNCTION DPA_GetPtrIndex LIB "ComCtl32.dll" ALIAS "DPA_GetPtrIndex" ( _
    BYVAL hdpa AS DWORD, p AS ANY) AS LONG

MACRO DPA_GetPtrCount(hdpa)=PEEK(LONG,hdpa)

FUNCTION DPA_SetPtrCount (BYVAL hdpa AS DWORD, BYVAL cItems AS LONG) AS LONG
    POKE LONG, hdpa, cItems
    FUNCTION = cItems
END FUNCTION

SUB DPA_FastDeleteLastPtr (BYVAL hdpa AS LONG PTR)
    DECR @hdpa
END SUB

'#define DPA_GetPtrPtr(hdpa) (*((void * **)((BYTE *)(hdpa) + sizeof(void *))))
'#define DPA_FastGetPtr(hdpa, i)    (DPA_GetPtrPtr(hdpa)[i])

MACRO DPA_AppendPtr(hdpa, pitem)=DPA_InsertPtr(hdpa, %DA_LAST, pitem)

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

DECLARE FUNCTION DPA_GetSize LIB "ComCtl32.dll" ALIAS "DPA_GetSize" ( _
    OPTIONAL BYVAL hdpa AS DWORD) AS QUAD

#ENDIF  ' NTDDI_VISTA

DECLARE FUNCTION DPA_Sort LIB "ComCtl32.dll" ALIAS "DPA_Sort" ( _
    BYVAL hdpa AS DWORD, BYVAL pfnCompare AS DWORD, BYVAL lParam AS LONG) _
    AS LONG

'
' Save to and load from a stream.  The stream callback gets a pointer to
' a DPASTREAMINFO structure.
'
' For DPA_SaveStream, the callback is responsible for writing the pvItem
' info to the stream. (It's not necessary to write the iPos to the
' stream.)  Return S_OK if the element was saved, S_FALSE if it wasn't
' but continue anyway, or some failure.
'
' For DPA_LoadStream, the callback is responsible for allocating an
' item and setting the pvItem field to the new pointer.  Return S_OK
' if the element was loaded, S_FALSE it it wasn't but continue anyway,
' or some failure.
'

TYPE DPASTREAMINFO
    iPos   AS LONG   ' Index of item
    pvItem AS DWORD  ' generic ptr
END TYPE

'struct IStream;

DECLARE FUNCTION PFNDPASTREAM(pInfo AS DPASTREAMINFO, pstream AS ANY, _
    pvInstData AS ANY) AS LONG  ' HRESULT

DECLARE FUNCTION DPA_LoadStream LIB "ComCtl32.dll" ALIAS "DPA_LoadStream" ( _
    phdpa AS DWORD, BYVAL pfn AS DWORD, pstream AS ANY, pvInstData AS ANY) _
    AS LONG  ' HRESULT

DECLARE FUNCTION DPA_SaveStream LIB "ComCtl32.dll" ALIAS "DPA_SaveStream" ( _
    BYVAL hdpa AS DWORD, BYVAL pfn AS DWORD, pstream AS ANY, _
    pvInstData AS ANY) AS LONG  ' HRESULT

' Merge two DPAs.  This takes two(optionally) presorted arrays and merges
' the source array into the dest.  DPA_Merge uses the provided callbacks
' to perform comparison and merge operations.  The merge callback is
' called when two elements(one in each list) match according to the
' compare function.  This allows portions of an element in one list to
' be merged with the respective element in the second list.
'
' The first DPA(hdpaDest) is the output array.
'
' Merge options:
'
'    DPAM_SORTED       The arrays are already sorted; don't sort
'    DPAM_UNION        The resulting array is the union of all elements
'                      in both arrays(DPAMM_INSERT may be sent for
'                      this merge option.)
'    DPAM_INTERSECT    Only elements in the source array that intersect
'                      with the dest array are merged. (DPAMM_DELETE
'                      may be sent for this merge option.)
'    DPAM_NORMAL       Like DPAM_INTERSECT except the dest array
'                      also maintains its original, additional elements.
'
%DPAM_SORTED           = &H00000001
%DPAM_NORMAL           = &H00000002
%DPAM_UNION            = &H00000004
%DPAM_INTERSECT        = &H00000008

' The merge callback should merge contents of the two items and return
' the pointer of the merged item.  It's okay to simply use pvDest
' as the returned pointer.
'

DECLARE FUNCTION PFNDPAMERGE(BYVAL uMsg AS DWORD, pvDest AS ANY, _
    pvSrc AS ANY, BYVAL lParam AS LONG) AS DWORD

DECLARE FUNCTION PFNDPAMERGECONST(BYVAL uMsg AS DWORD, pvDest AS ANY, _
    pvSrc AS ANY, BYVAL lParam AS LONG) AS DWORD

' Messages for merge callback
%DPAMM_MERGE   = 1
%DPAMM_DELETE  = 2
%DPAMM_INSERT  = 3

DECLARE FUNCTION DPA_Merge LIB "ComCtl32.dll" ALIAS "DPA_Merge" ( _
    BYVAL hdpaDest AS DWORD, BYVAL hdpaSrc AS DWORD, BYVAL dwFlags AS DWORD, _
    BYVAL pfnCompare AS DWORD, BYVAL pfnMerge AS DWORD, BYVAL lParam AS LONG) _
    AS LONG

'
' Search array.  If DPAS_SORTED, then array is assumed to be sorted
' according to pfnCompare, and binary search algorithm is used.
' Otherwise, linear search is used.
'
' Searching starts at iStart(0 to start search at beginning).
'
' DPAS_INSERTBEFORE/AFTER govern what happens if an exact match is not
' found.  If neither are specified, this function returns -1 if no exact
' match is found.  Otherwise, the index of the item before or after the
' closest(including exact) match is returned.
'
' Search option flags
'
%DPAS_SORTED           = &H0001
%DPAS_INSERTBEFORE     = &H0002
%DPAS_INSERTAFTER      = &H0004

DECLARE FUNCTION DPA_Search LIB "ComCtl32.dll" ALIAS "DPA_Search" ( _
    BYVAL hdpa AS DWORD, pFind AS DWORD, BYVAL iStart AS LONG, _
    BYVAL pfnCompare AS DWORD, BYVAL lParam AS LONG, BYVAL options AS DWORD) _
    AS LONG

MACRO DPA_SortedInsertPtr(hdpa,pFind,iStart,pfnCompare,lParam,options,pitem)=DPA_InsertPtr(hdpa,DPA_Search(hdpa,pFind,iStart,pfnCompare,lParam,%DPAS_SORTED OR(options)),pitem)

%DPA_APPEND   = %DA_LAST
%DPA_ERR      = %DA_ERR

'#define PFNDPAENUMCALLBACK          PFNDAENUMCALLBACK
'#define PFNDPAENUMCALLBACKCONST     PFNDAENUMCALLBACKCONST
'#define PFNDPACOMPARE               PFNDACOMPARE
'#define PFNDPACOMPARECONST          PFNDACOMPARECONST

#ENDIF  ' NO_COMMCTRL_DA


DECLARE FUNCTION Str_SetPtrW LIB "ComCtl32.dll" ALIAS "Str_SetPtrW" ( _
    ppsz AS ANY, psz AS WSTRINGZ) AS LONG


'====== TrackMouseEvent  =====================================================

#IF %DEF(%WIN32)

#IF NOT %DEF(%NOTRACKMOUSEEVENT)

' If the messages for TrackMouseEvent were not defined, define them.
'
#IF NOT %DEF(%WM_MOUSEHOVER)
%WM_MOUSEHOVER                 = &H02A1
%WM_MOUSELEAVE                 = &H02A3
#ENDIF  ' %WM_MOUSEHOVER

'
' If the TRACKMOUSEEVENT structure and associated flags were not declared,
' declare them.
'
#IF NOT %DEF(%TME_HOVER)
%TME_HOVER      = &H00000001
%TME_LEAVE      = &H00000002
#IF (%WINVER >= &H0500)
%TME_NONCLIENT  = &H00000010
#ENDIF
%TME_QUERY      = &H40000000
%TME_CANCEL     = &H80000000???


%HOVER_DEFAULT  = &HFFFFFFFF???

TYPE TRACKMOUSEEVENT_type
    cbSize      AS DWORD
    dwFlags     AS DWORD
    hwndTrack   AS DWORD   ' HWND
    dwHoverTime AS DWORD
END TYPE

' [legacy]
TYPE EVENTTRACK
    TRACKMOUSEEVENT_type
END TYPE

' [legacy]
TYPE TRACKMOUSEEVENTAPI
    TRACKMOUSEEVENT_type
END TYPE

#ENDIF  ' NOT %TME_HOVER

'
' Declare _TrackMouseEvent.  This API tries to use the window manager's
' implementation of TrackMouseEvent if it is present, otherwise it emulates.
'
DECLARE FUNCTION TrackMouseEvent LIB "USER32.DLL" ALIAS "TrackMouseEvent" _
  (lpEventTrack AS TRACKMOUSEEVENT_type) AS LONG

#ENDIF  ' %NOTRACKMOUSEEVENT


' ====== Flat Scrollbar APIs =========================================

#IF (%WIN32_IE >= &H0400)

#IF NOT %DEF(%NOFLATSBAPIS)

%WSB_PROP_CYVSCROLL = &H00000001
%WSB_PROP_CXHSCROLL = &H00000002
%WSB_PROP_CYHSCROLL = &H00000004
%WSB_PROP_CXVSCROLL = &H00000008
%WSB_PROP_CXHTHUMB  = &H00000010
%WSB_PROP_CYVTHUMB  = &H00000020
%WSB_PROP_VBKGCOLOR = &H00000040
%WSB_PROP_HBKGCOLOR = &H00000080
%WSB_PROP_VSTYLE    = &H00000100
%WSB_PROP_HSTYLE    = &H00000200
%WSB_PROP_WINSTYLE  = &H00000400
%WSB_PROP_PALETTE   = &H00000800
%WSB_PROP_MASK      = &H00000FFF

%FSB_FLAT_MODE    = 2
%FSB_ENCARTA_MODE = 1
%FSB_REGULAR_MODE = 0

DECLARE FUNCTION FlatSB_EnableScrollBar LIB "ComCtl32.dll" _
          ALIAS "FlatSB_EnableScrollBar" (BYVAL hWnd AS DWORD, _
          BYVAL wSBflags AS LONG, BYVAL dArrows AS DWORD) AS LONG

DECLARE FUNCTION FlatSB_ShowScrollBar LIB "ComCtl32.dll" _
          ALIAS "FlatSB_ShowScrollBar" (BYVAL hWnd AS DWORD, _
          BYVAL typecode AS LONG, BYVAL fShow AS LONG) AS LONG

DECLARE FUNCTION FlatSB_GetScrollRange LIB "ComCtl32.dll" _
          ALIAS "FlatSB_GetScrollRange" (BYVAL hWnd AS DWORD, _
          BYVAL typecode AS LONG, MinPos AS LONG, MaxPos AS LONG) AS LONG

DECLARE FUNCTION FlatSB_GetScrollInfo LIB "ComCtl32.dll" _
          ALIAS "FlatSB_GetScrollInfo" (BYVAL hWnd AS DWORD, _
          BYVAL typecode AS LONG, si AS SCROLLINFO) AS LONG

DECLARE FUNCTION FlatSB_GetScrollPos LIB "ComCtl32.dll" _
          ALIAS "FlatSB_GetScrollPos" (BYVAL hWnd AS DWORD, _
          BYVAL typecode AS LONG) AS LONG

DECLARE FUNCTION FlatSB_GetScrollProp LIB "ComCtl32.dll" _
          ALIAS "FlatSB_GetScrollProp" (BYVAL hWnd AS DWORD, _
          BYVAL propIndex AS DWORD, nValue AS LONG) AS LONG

#IF %DEF(%WIN64)
'WINCOMMCTRLAPI BOOL WINAPI FlatSB_GetScrollPropPtr(HWND, int propIndex, PINT_PTR);
#ELSE
DECLARE FUNCTION FlatSB_GetScrollPropPtr LIB "ComCtl32.dll" _
          ALIAS "FlatSB_GetScrollProp" (BYVAL hWnd AS DWORD, _
          BYVAL propIndex AS DWORD, nValue AS LONG) AS LONG
#ENDIF

DECLARE FUNCTION FlatSB_SetScrollPos LIB "ComCtl32.dll" _
          ALIAS "FlatSB_SetScrollPos" (BYVAL hWnd AS DWORD, _
          BYVAL typecode AS LONG, BYVAL nPos AS LONG, BYVAL fRedraw AS LONG) _
          AS LONG

DECLARE FUNCTION FlatSB_SetScrollInfo LIB "ComCtl32.dll" _
          ALIAS "FlatSB_SetScrollInfo" (BYVAL hWnd AS DWORD, _
          BYVAL typecode AS LONG, si AS SCROLLINFO, BYVAL fRedraw AS LONG) _
          AS LONG

DECLARE FUNCTION FlatSB_SetScrollRange LIB "ComCtl32.dll" _
          ALIAS "FlatSB_SetScrollRange" (BYVAL hWnd AS DWORD, _
          BYVAL typecode AS LONG, BYVAL nMinPos AS LONG, _
          BYVAL nMaxPos AS LONG, BYVAL fRedraw AS LONG) AS LONG

DECLARE FUNCTION FlatSB_SetScrollProp LIB "ComCtl32.dll" _
          ALIAS "FlatSB_SetScrollProp" (BYVAL hWnd AS DWORD, _
          BYVAL propIndex AS DWORD, BYVAL newValue AS DWORD, _
          BYVAL fRedraw AS LONG) AS LONG

DECLARE FUNCTION FlatSB_SetScrollPropPtr LIB "ComCtl32.dll" _
          ALIAS "FlatSB_SetScrollProp" (BYVAL hWnd AS DWORD, _
          BYVAL propIndex AS DWORD, BYVAL newValue AS DWORD, _
          BYVAL fRedraw AS LONG) AS LONG

DECLARE FUNCTION InitializeFlatSB LIB "ComCtl32.dll" _
          ALIAS "InitializeFlatSB" (BYVAL hWnd AS DWORD) AS LONG

DECLARE FUNCTION UninitializeFlatSB LIB "ComCtl32.dll" _
          ALIAS "UninitializeFlatSB" (BYVAL hWnd AS DWORD) AS LONG

#ENDIF  ' %NOFLATSBAPIS

#ENDIF  ' %WIN32_IE >= &H0400

#ENDIF  ' %WIN32

#ENDIF  ' %WIN32_IE >= &H0300


#IF (%WIN32_WINNT >= &H0501)
'
' subclassing stuff
'
'DECLARE FUNCTION SUBCLASSPROC (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, _
'    BYVAL wParam AS DWORD, BYVAL lParam AS LONG, BYVAL uIdSubclass AS DWORD, _
'    BYVAL dwRefData AS DWORD) AS LONG

DECLARE FUNCTION SetWindowSubclass LIB "ComCtl32.dll" _
    ALIAS "SetWindowSubclass" (BYVAL hWnd AS DWORD, _
    BYVAL pfnSubclass AS DWORD, BYVAL uIdSubclass AS DWORD, _
    BYVAL dwRefData AS DWORD) AS LONG

DECLARE FUNCTION GetWindowSubclass LIB "ComCtl32.dll" _
    ALIAS "GetWindowSubclass" (BYVAL hWnd AS DWORD, _
    BYVAL pfnSubclass AS DWORD, BYVAL uIdSubclass AS DWORD, _
    pdwRefData AS DWORD) AS LONG

DECLARE FUNCTION RemoveWindowSubclass LIB "ComCtl32.dll" _
    ALIAS "RemoveWindowSubclass" (BYVAL hWnd AS DWORD, _
    BYVAL pfnSubclass AS DWORD, BYVAL uIdSubclass AS DWORD) AS LONG

DECLARE FUNCTION DefSubclassProc LIB "ComCtl32.dll" ALIAS "DefSubclassProc" _
    (BYVAL hWnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS DWORD) AS LONG

#ENDIF  ' #IF (%WIN32_WINNT >= &H0501)

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

MACRO LI_METRIC_enum=LONG
ENUM LI_METRIC SINGULAR
    LIM_SMALL  ' corresponds to SM_CXSMICON/SM_CYSMICON
    LIM_LARGE  ' corresponds to SM_CXICON/SM_CYICON
END ENUM

DECLARE FUNCTION LoadIconMetric LIB "ComCtl32.dll" ALIAS "LoadIconMetric" _
    (BYVAL hinst AS DWORD, pszName AS WSTRINGZ, BYVAL lims AS LONG, phico AS DWORD) _
    AS LONG

DECLARE FUNCTION LoadIconWithScaleDown LIB "ComCtl32.dll" ALIAS "LoadIconWithScaleDown" _
    (BYVAL hInst AS DWORD, pszName AS WSTRINGZ, BYVAL cx AS LONG, BYVAL cy AS LONG, _
    phico AS DWORD) AS LONG

#ENDIF  ' %NTDDI_VISTA

#IF (%WIN32_WINNT >= &H0501)

DECLARE FUNCTION DrawShadowText LIB "ComCtl32.dll" ALIAS "DrawShadowText" _
    (BYVAL hdc AS DWORD, pszText AS WSTRINGZ, BYVAL cch AS DWORD, _
    prc AS RECT, BYVAL dwFlags AS DWORD, BYVAL crText AS COLORREF, _
    BYVAL crShadow AS COLORREF, BYVAL ixOffset AS LONG, BYVAL iyOffset AS LONG) _
    AS LONG

#ENDIF



'#IF %DEF(%ISOLATION_AWARE_ENABLED) AND(%ISOLATION_AWARE_ENABLED)
'#INCLUDE "commctrl.inl.inc"
'#ENDIF  ' ISOLATION_AWARE_ENABLED
