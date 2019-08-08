'------------------------------------------------------------------------------
'
' UxTheme.inc -- Theming API header file.
'
' Copyright (c) 2010-2011 PowerBASIC, Inc.
' Portions Copyright (c) Microsoft Corporation
' All Rights Reserved.
'
' Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
' from Uxtheme.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%UXTHEME_H = 1

#INCLUDE "CommCtrl.inc"
#INCLUDE "WinGDI.inc"

'MACRO HTHEME=HANDLE

#IF (%WIN32_WINNT >= &H0600)
%MAX_THEMECOLOR = 64
%MAX_THEMESIZE  = 64
#ENDIF

#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
'---------------------------------------------------------------------------
' BeginPanningFeedback - Visual feedback init function related to pan gesture
' - internally called by DefaultGestureHandler
' - called by application
'
' HWND hwnd - The handle to the Target window that will receive feedback
'
'---------------------------------------------------------------------------

DECLARE FUNCTION BeginPanningFeedback LIB "UxTheme.dll" _
    ALIAS "BeginPanningFeedback" ( _
    BYVAL hwnd AS DWORD _  ' HWND
    ) AS LONG              ' BOOL

'---------------------------------------------------------------------------
' UpdatePanningFeedback : Visual feedback function related to pan gesture
' Can Be called only after a BeginPanningFeedback call
' - internally called by DefaultGestureHandler
' - called by application
'
' HWND hwnd                 - The handle to the Target window that will receive feedback
'                          For the method to succeed this must be the same hwnd as provided in
'                          BeginPanningFeedback
'
' LONG lTotalOverpanOffsetX - The Total displacement that the window has moved in the horizontal direction
'                          since the end of scrollable region was reached. The API would move the window by the distance specified
'                          A maximum displacement of 30 pixels is allowed
'
' LONG lTotalOverpanOffsetY - The Total displacement that the window has moved in the horizontal direction
'                          since the end of scrollable
'                          region was reached. The API would move the window by the distance specified
'                          A maximum displacement of 30 pixels is allowed
'
' BOOL fInInertia           - Flag dictating whether the Application is handling a WM_GESTURE message with the
'                          GF_INERTIA FLAG set
'
' Incremental calls to UpdatePanningFeedback should make sure they always pass
' the sum of the increments and not just the increment themselves
' Eg : If the initial displacement is 10 pixels and the next displacement 10 pixels
'     the second call would be with the parameter as 20 pixels as opposed to 10
' Eg : UpdatePanningFeedback(hwnd, 10, 10, %TRUE)
'

DECLARE FUNCTION UpdatePanningFeedback LIB "UxTheme.dll" _
    ALIAS "UpdatePanningFeedback" ( _
    BYVAL hwnd                 AS DWORD, _  ' HWND
    BYVAL lTotalOverpanOffsetX AS LONG, _
    BYVAL lTotalOverpanOffsetY AS LONG, _
    BYVAL fInInertia           AS LONG _  ' BOOL
    ) AS LONG  ' BOOL

'---------------------------------------------------------------------------
'
' EndPanningFeedback :Visual feedback reset function related to pan gesture
' - internally called by DefaultGestureHandler
' - called by application
' Terminates any existing animation that was in process or set up by BeginPanningFeedback and UpdatePanningFeedback
' The EndPanningFeedBack needs to be called Prior to calling any BeginPanningFeedBack if we have already
' called a BeginPanningFeedBack followed by one/ more UpdatePanningFeedback calls
'
' HWND hwnd         - The handle to the Target window that will receive feedback
'
' BOOL fAnimateBack - Flag to indicate whether you wish the displaced window to move back
'                   to the original position via animation or a direct jump.
'                   Either ways the method will try to restore the moved window.
'                   The latter case exists for compatibility with legacy apps.
'

DECLARE FUNCTION EndPanningFeedback LIB "UxTheme.dll" _
    ALIAS "EndPanningFeedback" ( _
    BYVAL hwnd         AS DWORD, _  ' HWND
    BYVAL fAnimateBack AS LONG _  ' BOOL
    ) AS LONG  ' BOOL

#ENDIF

'---------------------------------------------------------------------------
' NOTE: PartIds and StateIds used in the theme API are defined in the
'    hdr file <vssym32.h> using the TM_PART and TM_STATE macros.  For
'    example, "TM_PART(BP, PUSHBUTTON)" defines the PartId "BP_PUSHBUTTON".

'---------------------------------------------------------------------------
' OpenThemeData()     - Open the theme data for the specified HWND and
'                     semi-colon separated list of class names.
'
'                     OpenThemeData() will try each class name, one at
'                     a time, and use the first matching theme info
'                     found.  If a match is found, a theme handle
'                     to the data is returned.  If no match is found,
'                     a "NULL" handle is returned.
'
'                     When the window is destroyed or a WM_THEMECHANGED
'                     msg is received, "CloseThemeData()" should be
'                     called to close the theme handle.
'
' hwnd                - window handle of the control/window to be themed
'
' pszClassList        - class name (or list of names) to match to theme data
'                     section.  if the list contains more than one name,
'                     the names are tested one at a time for a match.
'                     If a match is found, OpenThemeData() returns a
'                     theme handle associated with the matching class.
'                     This param is a list (instead of just a single
'                     class name) to provide the class an opportunity
'                     to get the "best" match between the class and
'                     the current theme.  For example, a button might
'                     pass "OkButton, Button"$$ if its ID=%ID_OK.  If
'                     the current theme has an entry for OkButton,
'                     that will be used.  Otherwise, we fall back on
'                     the normal Button entry.
'---------------------------------------------------------------------------

DECLARE FUNCTION OpenThemeData LIB "UxTheme.dll" _
    ALIAS "OpenThemeData" ( _
    BYVAL hwnd   AS DWORD, _  ' HWND
    pszClassList AS WSTRINGZ _
    ) AS DWORD  ' HTHEME

%OTD_FORCE_RECT_SIZING   = &H00000001         ' make all parts size to rect
%OTD_NONCLIENT           = &H00000002         ' set if hTheme to be used for nonclient area
%OTD_VALIDBITS           = (%OTD_FORCE_RECT_SIZING OR %OTD_NONCLIENT)

'---------------------------------------------------------------------------
' OpenThemeDataEx     - Open the theme data for the specified HWND and
'                     semi-colon separated list of class names.
'
'                     OpenThemeData() will try each class name, one at _
'                     a time, and use the first matching theme info
'                     found.  If a match is found, a theme handle
'                     to the data is returned.  If no match is found,
'                     a %NULL handle is returned.
'
'                     When the window is destroyed or a %WM_THEMECHANGED
'                     msg is received, "CloseThemeData()" should be
'                     called to close the theme handle.
'
' hwnd                - window handle of the control/window to be themed
'
' pszClassList        - class name (or list of names) to match to theme data
'                     section.  if the list contains more than one name,
'                     the names are tested one at a time for a match.
'                     If a match is found, OpenThemeData() returns a
'                     theme handle associated with the matching class.
'                     This param is a list (instead of just a single
'                     class name) to provide the class an opportunity
'                     to get the "best" match between the class and
'                     the current theme.  For example, a button might
'                     pass "OkButton, Button"$$ if its ID=%ID_OK.  If
'                     the current theme has an entry for OkButton,
'                     that will be used.  Otherwise, we fall back on
'                     the normal Button entry.
'
' dwFlags              - allows certain overrides of std features
'                      (see %OTD_XXX defines above)
'---------------------------------------------------------------------------

DECLARE FUNCTION OpenThemeDataEx LIB "UxTheme.dll" _
    ALIAS "OpenThemeDataEx" ( _
    BYVAL hwnd    AS DWORD, _  ' HWND
    pszClassList  AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD _
    ) AS DWORD  ' HTHEME

'---------------------------------------------------------------------------
' CloseThemeData()    - closes the theme data handle.  This should be done
'                     when the window being themed is destroyed or
'                     whenever a %WM_THEMECHANGED msg is received
'                     (followed by an attempt to create a new Theme data
'                     handle).
'
' hTheme              - open theme data handle (returned from prior call
'                     to OpenThemeData() API).
'---------------------------------------------------------------------------

DECLARE FUNCTION CloseThemeData LIB "UxTheme.dll" _
    ALIAS "CloseThemeData" ( _
    BYVAL hTheme AS DWORD _  ' HTHEME
    ) AS LONG  ' HRESULT

'---------------------------------------------------------------------------
' functions for basic drawing support
'---------------------------------------------------------------------------
' The following methods are the theme-aware drawing services.
' Controls/Windows are defined in drawable "parts" by their author: a
' parent part and 0 or more child parts.  Each of the parts can be
' described in "states" (ex: disabled, hot, pressed).
'---------------------------------------------------------------------------
' For the list of all themed classes and the definition of all
' parts and states, see the file "tmschmea.h".
'---------------------------------------------------------------------------
' Each of the below methods takes a "iPartId" param to specify the
' part and a "iStateId" to specify the state of the part.
' "iStateId=0" refers to the root part.  "iPartId" = "0" refers to
' the root class.
'-----------------------------------------------------------------------
' Note: draw operations are always scaled to fit (and not to exceed)
' the specified "Rect".
'-----------------------------------------------------------------------

'------------------------------------------------------------------------
' DrawThemeBackground()
'                   - draws the theme-specified border and fill for
'                     the "iPartId" and "iStateId".  This could be
'                     based on a bitmap file, a border and fill, or
'                     other image description.
'
' hTheme              - theme data handle
' hdc                 - HDC to draw into
' iPartId             - part number to draw
' iStateId            - state number (of the part) to draw
' pRect               - defines the size/location of the part
' pClipRect           - optional clipping rect (don't draw outside it)
'------------------------------------------------------------------------

DECLARE FUNCTION DrawThemeBackground LIB "UxTheme.dll" _
    ALIAS "DrawThemeBackground" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL hdc      AS DWORD, _   ' HDC
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    pRect          AS RECT, _
    pClipRect      AS RECT _
    ) AS LONG  ' HRESULT

'------------------------------------------------------------------------
'---- bits used in dwFlags of DTBGOPTS ----
%DTBG_CLIPRECT           = &H00000001  ' rcClip has been specified
%DTBG_DRAWSOLID          = &H00000002  ' DEPRECATED: draw transparent/alpha images as solid
%DTBG_OMITBORDER         = &H00000004  ' don't draw border of part
%DTBG_OMITCONTENT        = &H00000008  ' don't draw content area of part
%DTBG_COMPUTINGREGION    = &H00000010  ' TRUE if calling to compute region
%DTBG_MIRRORDC           = &H00000020  ' assume the hdc is mirrorred and
                                       ' flip images as appropriate (currently
                                       ' only supported for bgtype=imagefile)
%DTBG_NOMIRROR           = &H00000040  ' don't mirror the output, overrides everything else
%DTBG_VALIDBITS          = %DTBG_CLIPRECT _
                        OR %DTBG_DRAWSOLID _
                        OR %DTBG_OMITBORDER _
                        OR %DTBG_OMITCONTENT _
                        OR %DTBG_COMPUTINGREGION _
                        OR %DTBG_MIRRORDC _
                        OR %DTBG_NOMIRROR

TYPE DTBGOPTS
    dwSize  AS DWORD          ' size of the struct
    dwFlags AS DWORD          ' which options have been specified
    rcClip  AS RECT           ' clipping rectangle
END TYPE

'------------------------------------------------------------------------
' DrawThemeBackgroundEx()
'                   - draws the theme-specified border and fill for
'                     the "iPartId" and "iStateId".  This could be
'                     based on a bitmap file, a border and fill, or
'                     other image description.  NOTE: This will be
'                     merged back into DrawThemeBackground() after
'                     BETA 2.
'
' hTheme              - theme data handle
' hdc                 - HDC to draw into
' iPartId             - part number to draw
' iStateId            - state number (of the part) to draw
' pRect               - defines the size/location of the part
' pOptions            - ptr to optional params
'------------------------------------------------------------------------

DECLARE FUNCTION DrawThemeBackgroundEx LIB "UxTheme.dll" _
    ALIAS "DrawThemeBackgroundEx" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL hdc      AS DWORD, _  ' HDC
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    pRect          AS RECT, _
    BYVAL pOptions AS DTBGOPTS PTR _
    ) AS LONG  ' HRESULT

'---------------------------------------------------------------------------
'----- DrawThemeText() flags ----
%DTT_GRAYED              = &H00000001   ' draw a grayed-out string (this is deprecated)
%DTT_FLAGS2VALIDBITS     = %DTT_GRAYED

'-------------------------------------------------------------------------
' DrawThemeText()     - draws the text using the theme-specified
'                     color and font for the "iPartId" and
'                     "iStateId".
'
' hTheme              - theme data handle
' hdc                 - HDC to draw into
' iPartId             - part number to draw
' iStateId            - state number (of the part) to draw
' pszText             - actual text to draw
' dwCharCount         - number of chars to draw (-1 for all)
' dwTextFlags         - same as DrawText() "uFormat" param
' dwTextFlags2        - additional drawing options
' pRect               - defines the size/location of the part
'-------------------------------------------------------------------------

DECLARE FUNCTION DrawThemeText LIB "UxTheme.dll" _
    ALIAS "DrawThemeText" ( _
    BYVAL hTheme       AS DWORD, _  ' HTHEME
    BYVAL hdc          AS DWORD, _  ' HDC
    BYVAL iPartId      AS LONG, _
    BYVAL iStateId     AS LONG, _
    pszText            AS WSTRINGZ, _
    BYVAL cchText      AS LONG, _
    BYVAL dwTextFlags  AS DWORD, _
    BYVAL dwTextFlags2 AS DWORD, _
    pRect              AS RECT _
    ) AS LONG  ' HRESULT

'-------------------------------------------------------------------------
' GetThemeBackgroundContentRect()
'                   - gets the size of the content for the theme-defined
'                     background.  This is usually the area inside
'                     the borders or Margins.
'
'   hTheme          - theme data handle
'   hdc             - (optional) device content to be used for drawing
'   iPartId         - part number to draw
'   iStateId        - state number (of the part) to draw
'   pBoundingRect   - the outer RECT of the part being drawn
'   pContentRect    - RECT to receive the content area
'-------------------------------------------------------------------------

DECLARE FUNCTION GetThemeBackgroundContentRect LIB "UxTheme.dll" _
    ALIAS "GetThemeBackgroundContentRect" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL hdc      AS DWORD, _  ' HDC
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    pBoundingRect  AS RECT, _
    pContentRect   AS RECT _
    ) AS LONG  ' HRESULT

'-------------------------------------------------------------------------
' GetThemeBackgroundExtent() - calculates the size/location of the theme-
'                            specified background based on the
'                            "pContentRect".
'
'   hTheme          - theme data handle
'   hdc             - (optional) device content to be used for drawing
'   iPartId         - part number to draw
'   iStateId        - state number (of the part) to draw
'   pContentRect    - RECT that defines the content area
'   pBoundingRect   - RECT to receive the overall size/location of part
'-------------------------------------------------------------------------

DECLARE FUNCTION GetThemeBackgroundExtent LIB "UxTheme.dll" _
    ALIAS "GetThemeBackgroundExtent" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL hdc      AS DWORD, _  ' HDC
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    pContentRect   AS RECT, _
    pExtentRect    AS RECT _
    ) AS LONG  ' HRESULT

'-------------------------------------------------------------------------
' GetThemeBackgroundRegion()
'                   - computes the region for a regular or partially
'                     transparent theme-specified background that is
'                     bound by the specified "pRect".
'                     If the rectangle is empty, sets the HRGN to NULL
'                     and return S_FALSE.
'
' hTheme              - theme data handle
' hdc                 - optional HDC to draw into (DPI scaling)
' iPartId             - part number to draw
' iStateId            - state number (of the part)
' pRect               - the RECT used to draw the part
' pRegion             - receives handle to calculated region
'-------------------------------------------------------------------------

DECLARE FUNCTION GetThemeBackgroundRegion LIB "UxTheme.dll" _
    ALIAS "GetThemeBackgroundRegion" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL hdc      AS DWORD, _  ' HDC
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    pRect          AS RECT, _
    pRegion        AS DWORD _  ' HRGN
    ) AS LONG  ' HRESULT

ENUM THEMESIZE SINGULAR
    TS_MIN             ' minimum size
    TS_TRUE            ' size without stretching
    TS_DRAW            ' size that theme mgr will use to draw part
END ENUM

'-------------------------------------------------------------------------
' GetThemePartSize() - returns the specified size of the theme part
'
' hTheme              - theme data handle
' hdc                 - HDC to select font into and measure against
' iPartId             - part number to retrieve size for
' iStateId            - state number (of the part)
' prc                 - (optional) rect for part drawing destination
' eSize               - the type of size to be retreived
' psz                 - receives the specified size of the part
'-------------------------------------------------------------------------

DECLARE FUNCTION GetThemePartSize LIB "UxTheme.dll" _
    ALIAS "GetThemePartSize" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL hdc      AS DWORD, _  ' HDC
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    prc            AS RECT, _
    BYVAL eSize    AS LONG, _  ' THEMESIZE enum
    psz            AS SIZE _
    ) AS LONG  ' HRESULT

'-------------------------------------------------------------------------
' GetThemeTextExtent() - calculates the size/location of the specified
'                      text when rendered in the Theme Font.
'
' hTheme              - theme data handle
' hdc                 - HDC to select font and measure into
' iPartId             - part number to draw
' iStateId            - state number (of the part)
' pszText             - the text to be measured
' dwCharCount         - number of chars to draw (-1 for all)
' dwTextFlags         - same as DrawText() "uFormat" param
' pszBoundingRect     - optional: to control layout of text
' pszExtentRect       - receives the RECT for text size/location
'-------------------------------------------------------------------------

DECLARE FUNCTION GetThemeTextExtent LIB "UxTheme.dll" _
    ALIAS "GetThemeTextExtent" ( _
    BYVAL hTheme       AS DWORD, _  ' HTHEME
    BYVAL hdc          AS DWORD, _  ' HDC
    BYVAL iPartId      AS LONG, _
    BYVAL iStateId     AS LONG, _
    pszText            AS WSTRINGZ, _
    BYVAL cchCharCount AS LONG, _
    BYVAL dwTextFlags  AS DWORD, _
    pBoundingRect      AS RECT, _
    pExtentRect        AS RECT _
    ) AS LONG  ' HRESULT

'-------------------------------------------------------------------------
' GetThemeTextMetrics()
'                   - returns info about the theme-specified font
'                     for the part/state passed in.
'
' hTheme              - theme data handle
' hdc                 - optional: HDC for screen context
' iPartId             - part number to draw
' iStateId            - state number (of the part)
' ptm                 - receives the font info
'-------------------------------------------------------------------------

DECLARE FUNCTION GetThemeTextMetrics LIB "UxTheme.dll" _
    ALIAS "GetThemeTextMetrics" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL hdc      AS DWORD, _  ' HDC
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    ptm            AS TEXTMETRICW _
    ) AS LONG  ' HRESULT

'-------------------------------------------------------------------------
'----- HitTestThemeBackground, HitTestThemeBackgroundRegion flags ----

' Theme background segment hit test flag (default). possible return values are:
' HTCLIENT: hit test succeeded in the middle background segment
' HTTOP, HTLEFT, HTTOPLEFT, etc:  ' hit test succeeded in the the respective theme background segment.
%HTTB_BACKGROUNDSEG          = &H00000000
' Fixed border hit test option.  possible return values are:
' HTCLIENT: hit test succeeded in the middle background segment
' HTBORDER: hit test succeeded in any other background segment
%HTTB_FIXEDBORDER            = &H00000002     ' Return code may be either HTCLIENT or HTBORDER.
' Caption hit test option.  Possible return values are:
' HTCAPTION: hit test succeeded in the top, top left, or top right background segments
' HTNOWHERE or another return code, depending on absence or presence of accompanying flags, resp.
%HTTB_CAPTION                = &H00000004
' Resizing border hit test flags.  Possible return values are:
' HTCLIENT: hit test succeeded in middle background segment
' HTTOP, HTTOPLEFT, HTLEFT, HTRIGHT, etc:    hit test succeeded in the respective system resizing zone
' HTBORDER: hit test failed in middle segment and resizing zones, but succeeded in a background border segment
%HTTB_RESIZINGBORDER_LEFT    = &H00000010     ' Hit test left resizing border,
%HTTB_RESIZINGBORDER_TOP     = &H00000020     ' Hit test top resizing border
%HTTB_RESIZINGBORDER_RIGHT   = &H00000040     ' Hit test right resizing border
%HTTB_RESIZINGBORDER_BOTTOM  = &H00000080     ' Hit test bottom resizing border
%HTTB_RESIZINGBORDER         = %HTTB_RESIZINGBORDER_LEFT _
                            OR %HTTB_RESIZINGBORDER_TOP _
                            OR %HTTB_RESIZINGBORDER_RIGHT _
                            OR %HTTB_RESIZINGBORDER_BOTTOM
' Resizing border is specified as a template, not just window edges.
' This option is mutually exclusive with HTTB_SYSTEMSIZINGWIDTH; HTTB_SIZINGTEMPLATE takes precedence
%HTTB_SIZINGTEMPLATE         = &H00000100
' Use system resizing border width rather than theme content margins.
' This option is mutually exclusive with HTTB_SIZINGTEMPLATE, which takes precedence.
%HTTB_SYSTEMSIZINGMARGINS    = &H00000200

'-------------------------------------------------------------------------
' HitTestThemeBackground()
'                   - returns a HitTestCode (a subset of the values
'                     returned by WM_NCHITTEST) for the point "ptTest"
'                     within the theme-specified background
'                     (bound by pRect).  "pRect" and "ptTest" should
'                     both be in the same coordinate system
'                     (client, screen, etc).
'
'   hTheme          - theme data handle
'   hdc             - HDC to draw into
'   iPartId         - part number to test against
'   iStateId        - state number (of the part)
'   pRect           - the RECT used to draw the part
'   hrgn            - optional region to use; must be in same coordinates as
'                   -    pRect and pTest.
'   ptTest          - the hit point to be tested
'   dwOptions       - %HTTB_xxx constants
'   pwHitTestCode   - receives the returned hit test code - one of:
'
'                     %HTNOWHERE, %HTLEFT, %HTTOPLEFT, %HTBOTTOMLEFT,
'                     %HTRIGHT, %HTTOPRIGHT, %HTBOTTOMRIGHT,
'                     %HTTOP, %HTBOTTOM, %HTCLIENT
'-------------------------------------------------------------------------

DECLARE FUNCTION HitTestThemeBackground LIB "UxTheme.dll" _
    ALIAS "HitTestThemeBackground" ( _
    BYVAL hTheme    AS DWORD, _  ' HTHEME
    BYVAL hdc       AS DWORD, _  ' HDC
    BYVAL iPartId   AS LONG, _
    BYVAL iStateId  AS LONG, _
    BYVAL dwOptions AS DWORD, _
    pRect           AS RECT, _
    BYVAL hrgn      AS DWORD, _  ' HRGN
    BYVAL ptTest    AS POINT, _
    pwHitTestCode   AS WORD _
    ) AS LONG  ' HRESULT

'------------------------------------------------------------------------
' DrawThemeEdge()     - Similar to the DrawEdge() API, but uses part colors
'                     and is high-DPI aware
' hTheme              - theme data handle
' hdc                 - HDC to draw into
' iPartId             - part number to draw
' iStateId            - state number of part
' pDestRect           - the RECT used to draw the line(s)
' uEdge               - Same as DrawEdge() API
' uFlags              - Same as DrawEdge() API
' pContentRect        - Receives the interior rect if (uFlags AND %BF_ADJUST)
'------------------------------------------------------------------------

DECLARE FUNCTION DrawThemeEdge LIB "UxTheme.dll" _
    ALIAS "DrawThemeEdge" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL hdc      AS DWORD, _  ' HDC
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    pDestRect      AS RECT, _
    BYVAL uEdge    AS DWORD, _
    BYVAL uFlags   AS DWORD, _
    pContentRect   AS RECT _
    ) AS LONG  ' HRESULT

'------------------------------------------------------------------------
' DrawThemeIcon()     - draws an image within an imagelist based on
'                     a (possible) theme-defined effect.
'
' hTheme              - theme data handle
' hdc                 - HDC to draw into
' iPartId             - part number to draw
' iStateId            - state number of part
' pRect               - the RECT to draw the image within
' himl                - handle to IMAGELIST
' iImageIndex         - index into IMAGELIST (which icon to draw)
'------------------------------------------------------------------------

DECLARE FUNCTION DrawThemeIcon LIB "UxTheme.dll" _
    ALIAS "DrawThemeIcon" ( _
    BYVAL hTheme      AS DWORD, _  ' HTHEME
    BYVAL hdc         AS DWORD, _  ' HDC
    BYVAL iPartId     AS LONG, _
    BYVAL iStateId    AS LONG, _
    pRect             AS RECT, _
    BYVAL himl        AS DWORD, _  ' HIMAGELIST
    BYVAL iImageIndex AS LONG _
    ) AS LONG  ' HRESULT

'---------------------------------------------------------------------------
' IsThemePartDefined() - returns TRUE if the theme has defined parameters
'                      for the specified "iPartId" and "iStateId".
'
' hTheme              - theme data handle
' iPartId             - part number to find definition for
' iStateId            - state number of part
'---------------------------------------------------------------------------

DECLARE FUNCTION IsThemePartDefined LIB "UxTheme.dll" _
    ALIAS "IsThemePartDefined" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG _
    ) AS LONG  ' BOOL

'---------------------------------------------------------------------------
' IsThemeBackgroundPartiallyTransparent()
'                   - returns TRUE if the theme specified background for
'                     the part/state has transparent pieces or
'                     alpha-blended pieces.
'
' hTheme              - theme data handle
' iPartId             - part number
' iStateId            - state number of part
'---------------------------------------------------------------------------

DECLARE FUNCTION IsThemeBackgroundPartiallyTransparent LIB "UxTheme.dll" _
    ALIAS "IsThemeBackgroundPartiallyTransparent" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG _
    ) AS LONG  ' BOOL

'---------------------------------------------------------------------------
' lower-level theme information services
'---------------------------------------------------------------------------
' The following methods are getter routines for each of the Theme Data types.
' Controls/Windows are defined in drawable "parts" by their author: a
' parent part and 0 or more child parts.  Each of the parts can be
' described in "states" (ex: disabled, hot, pressed).
'---------------------------------------------------------------------------
' Each of the below methods takes a "iPartId" param to specify the
' part and a "iStateId" to specify the state of the part.
' "iStateId=0" refers to the root part.  "iPartId" = "0" refers to
' the root class.
'-----------------------------------------------------------------------
' Each method also take a "iPropId" param because multiple instances of
' the same primitive type can be defined in the theme schema.
'-----------------------------------------------------------------------

'-----------------------------------------------------------------------
' GetThemeColor()     - Get the value for the specified COLOR property
'
' hTheme              - theme data handle
' iPartId             - part number
' iStateId            - state number of part
' iPropId             - the property number to get the value for
' pColor              - receives the value of the property
'-----------------------------------------------------------------------

DECLARE FUNCTION GetThemeColor LIB "UxTheme.dll" _
    ALIAS "GetThemeColor" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    BYVAL iPropId  AS LONG, _
    pColor         AS COLORREF _
    ) AS LONG  ' HRESULT

'-----------------------------------------------------------------------
' GetThemeMetric()    - Get the value for the specified metric/size
'                     property
'
' hTheme              - theme data handle
' hdc                 - (optional) hdc to be drawn into (DPI scaling)
' iPartId             - part number
' iStateId            - state number of part
' iPropId             - the property number to get the value for
' piVal               - receives the value of the property
'-----------------------------------------------------------------------

DECLARE FUNCTION GetThemeMetric LIB "UxTheme.dll" _
    ALIAS "GetThemeMetric" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL hdc      AS DWORD, _  ' HDC
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    BYVAL iPropId  AS LONG, _
    piVal          AS LONG _
    ) AS LONG  ' HRESULT

'-----------------------------------------------------------------------
' GetThemeString()    - Get the value for the specified string property
'
' hTheme              - theme data handle
' iPartId             - part number
' iStateId            - state number of part
' iPropId             - the property number to get the value for
' pszBuff             - receives the string property value
' cchMaxBuffChars     - max. number of chars allowed in pszBuff
'-----------------------------------------------------------------------

DECLARE FUNCTION GetThemeString LIB "UxTheme.dll" _
    ALIAS "GetThemeString" ( _
    BYVAL hTheme          AS DWORD, _  ' HTHEME
    BYVAL iPartId         AS LONG, _
    BYVAL iStateId        AS LONG, _
    BYVAL iPropId         AS LONG, _
    pszBuff               AS WSTRINGZ, _
    BYVAL cchMaxBuffChars AS LONG _
    ) AS LONG  ' HRESULT

'-----------------------------------------------------------------------
' GetThemeBool()      - Get the value for the specified BOOL property
'
' hTheme              - theme data handle
' iPartId             - part number
' iStateId            - state number of part
' iPropId             - the property number to get the value for
' pfVal               - receives the value of the property
'-----------------------------------------------------------------------

DECLARE FUNCTION GetThemeBool LIB "UxTheme.dll" _
    ALIAS "GetThemeBool" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    BYVAL iPropId  AS LONG, _
    pfVal          AS LONG _  ' BOOL
    ) AS LONG  ' HRESULT

'-----------------------------------------------------------------------
' GetThemeInt()       - Get the value for the specified LONG property
'
' hTheme              - theme data handle
' iPartId             - part number
' iStateId            - state number of part
' iPropId             - the property number to get the value for
' piVal               - receives the value of the property
'-----------------------------------------------------------------------

DECLARE FUNCTION GetThemeInt LIB "UxTheme.dll" _
    ALIAS "GetThemeInt" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    BYVAL iPropId  AS LONG, _
    piVal          AS LONG _
    ) AS LONG  ' HRESULT

'-----------------------------------------------------------------------
' GetThemeEnumValue() - Get the value for the specified ENUM property
'
' hTheme              - theme data handle
' iPartId             - part number
' iStateId            - state number of part
' iPropId             - the property number to get the value for
' piVal               - receives the value of the enum (cast to LONG PTR)
'-----------------------------------------------------------------------

DECLARE FUNCTION GetThemeEnumValue LIB "UxTheme.dll" _
    ALIAS "GetThemeEnumValue" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    BYVAL iPropId  AS LONG, _
    piVal          AS LONG _
    ) AS LONG  ' HRESULT

'-----------------------------------------------------------------------
' GetThemePosition()  - Get the value for the specified position
'                     property
'
' hTheme              - theme data handle
' iPartId             - part number
' iStateId            - state number of part
' iPropId             - the property number to get the value for
' pPoint              - receives the value of the position property
'-----------------------------------------------------------------------

DECLARE FUNCTION GetThemePosition LIB "UxTheme.dll" _
    ALIAS "GetThemePosition" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    BYVAL iPropId  AS LONG, _
    pPoint         AS POINT _
    ) AS LONG  ' HRESULT

'-----------------------------------------------------------------------
' GetThemeFont()      - Get the value for the specified font property
'
' hTheme              - theme data handle
' hdc                 - (optional) hdc to be drawn to (DPI scaling)
' iPartId             - part number
' iStateId            - state number of part
' iPropId             - the property number to get the value for
' pFont               - receives the value of the LOGFONT property
'                     (scaled for the current logical screen dpi)
'-----------------------------------------------------------------------

DECLARE FUNCTION GetThemeFont LIB "UxTheme.dll" _
    ALIAS "GetThemeFont" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL hdc      AS DWORD, _  ' HDC
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    BYVAL iPropId  AS LONG, _
    pFont          AS LOGFONTW _
    ) AS LONG  ' HRESULT

'-----------------------------------------------------------------------
' GetThemeRect()      - Get the value for the specified RECT property
'
' hTheme              - theme data handle
' iPartId             - part number
' iStateId            - state number of part
' iPropId             - the property number to get the value for
' pRect               - receives the value of the RECT property
'-----------------------------------------------------------------------

DECLARE FUNCTION GetThemeRect LIB "UxTheme.dll" _
    ALIAS "GetThemeRect" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    BYVAL iPropId  AS LONG, _
    pRect          AS RECT _
    ) AS LONG  ' HRESULT

TYPE MARGINS
    cxLeftWidth    AS LONG  ' width of left border that retains its size
    cxRightWidth   AS LONG  ' width of right border that retains its size
    cyTopHeight    AS LONG  ' height of top border that retains its size
    cyBottomHeight AS LONG  ' height of bottom border that retains its size
END TYPE

'-----------------------------------------------------------------------
' GetThemeMargins()   - Get the value for the specified MARGINS property
'
'   hTheme          - theme data handle
'   hdc             - (optional) hdc to be used for drawing
'   iPartId         - part number
'   iStateId        - state number of part
'   iPropId         - the property number to get the value for
'   prc             - RECT for area to be drawn into
'   pMargins        - receives the value of the MARGINS property
'-----------------------------------------------------------------------

DECLARE FUNCTION GetThemeMargins LIB "UxTheme.dll" _
    ALIAS "GetThemeMargins" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL hdc      AS DWORD, _  ' HDC
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    BYVAL iPropId  AS LONG, _
    prc            AS RECT, _
    pMargins       AS MARGINS _
    ) AS LONG  ' HRESULT

#IF (%WIN32_WINNT >= &H0600)
%MAX_INTLIST_COUNT = 402
#ELSE
%MAX_INTLIST_COUNT = 10
#ENDIF

TYPE INTLIST
    iValueCount AS LONG     ' number of values in iValues
    iValues(%MAX_INTLIST_COUNT - 1) AS LONG
END TYPE

'-----------------------------------------------------------------------
' GetThemeIntList()   - Get the value for the specified INTLIST struct
'
'   hTheme          - theme data handle
'   iPartId         - part number
'   iStateId        - state number of part
'   iPropId         - the property number to get the value for
'   pIntList        - receives the value of the INTLIST property
'-----------------------------------------------------------------------

DECLARE FUNCTION GetThemeIntList LIB "UxTheme.dll" _
    ALIAS "GetThemeIntList" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    BYVAL iPropId  AS LONG, _
    pIntList       AS INTLIST _
    ) AS LONG  ' HRESULT

ENUM PROPERTYORIGIN SINGULAR
    PO_STATE           ' property was found in the state section
    PO_PART            ' property was found in the part section
    PO_CLASS           ' property was found in the class section
    PO_GLOBAL          ' property was found in [globals] section
    PO_NOTFOUND        ' property was not found
END ENUM

'-----------------------------------------------------------------------
' GetThemePropertyOrigin()
'                   - searches for the specified theme property
'                     and sets "pOrigin" to indicate where it was
'                     found (or not found)
'
' hTheme              - theme data handle
' iPartId             - part number
' iStateId            - state number of part
' iPropId             - the property number to search for
' pOrigin             - receives the value of the property origin
'-----------------------------------------------------------------------

DECLARE FUNCTION GetThemePropertyOrigin LIB "UxTheme.dll" _
    ALIAS "GetThemePropertyOrigin" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    BYVAL iPropId  AS LONG, _
    pOrigin        AS LONG _  ' PROPERTYORIGIN enum
    ) AS LONG  ' HRESULT

'---------------------------------------------------------------------------
' SetWindowTheme()
'                   - redirects an existing Window to use a different
'                     section of the current theme information than its
'                     class normally asks for.
'
' hwnd                - the handle of the window (cannot be NULL)
'
' pszSubAppName       - app (group) name to use in place of the calling
'                     app's name.  If NULL, the actual calling app
'                     name will be used.
'
' pszSubIdList        - semicolon separated list of class Id names to
'                     use in place of actual list passed by the
'                     window's class.  if NULL, the id list from the
'                     calling class is used.
'---------------------------------------------------------------------------
' The Theme Manager will remember the "pszSubAppName" and the
' "pszSubIdList" associations thru the lifetime of the window (even
' if themes are subsequently changed).  The window is sent a
' "WM_THEMECHANGED" msg at the end of this call, so that the new
' theme can be found and applied.
'---------------------------------------------------------------------------
' When "pszSubAppName" or "pszSubIdList" are NULL, the Theme Manager
' removes the previously remember association.  To turn off theme-ing for
' the specified window, you can pass an empty string (L"") so it
' won't match any section entries.
'---------------------------------------------------------------------------

DECLARE FUNCTION SetWindowTheme LIB "UxTheme.dll" _
    ALIAS "SetWindowTheme" ( _
    BYVAL hwnd AS DWORD, _  ' HWND
    pszSubAppName AS WSTRINGZ, _
    pszSubIdList AS WSTRINGZ _
    ) AS LONG  ' HRESULT


'---------------------------------------------------------------------------
' GetThemeFilename()  - Get the value for the specified FILENAME property.
'
' hTheme              - theme data handle
' iPartId             - part number
' iStateId            - state number of part
' iPropId             - the property number to search for
' pszThemeFileName    - output buffer to receive the filename
' cchMaxBuffChars     - the size of the return buffer, in chars
'---------------------------------------------------------------------------

DECLARE FUNCTION GetThemeFilename LIB "UxTheme.dll" _
    ALIAS "GetThemeFilename" ( _
    BYVAL hTheme          AS DWORD, _  ' HTHEME
    BYVAL iPartId         AS LONG, _
    BYVAL iStateId        AS LONG, _
    BYVAL iPropId         AS LONG, _
    pszThemeFileName      AS WSTRINGZ, _
    BYVAL cchMaxBuffChars AS LONG _
    ) AS LONG  ' HRESULT

'---------------------------------------------------------------------------
' GetThemeSysColor()  - Get the value of the specified System color.
'
' hTheme              - the theme data handle.  if non-NULL, will return
'                     color from [SysMetrics] section of theme.
'                     if NULL, will return the global system color.
'
' iColorId            - the system color index defined in winuser.h
'---------------------------------------------------------------------------

DECLARE FUNCTION GetThemeSysColor LIB "UxTheme.dll" _
    ALIAS "GetThemeSysColor" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL iColorId AS LONG _
    ) AS COLORREF

'---------------------------------------------------------------------------
' GetThemeSysColorBrush()
'                   - Get the brush for the specified System color.
'
' hTheme              - the theme data handle.  if non-NULL, will return
'                     brush matching color from [SysMetrics] section of
'                     theme.  if NULL, will return the brush matching
'                     global system color.
'
' iColorId            - the system color index defined in winuser.h
'---------------------------------------------------------------------------

DECLARE FUNCTION GetThemeSysColorBrush LIB "UxTheme.dll" _
    ALIAS "GetThemeSysColorBrush" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL iColorId AS LONG _
    ) AS DWORD  ' HBRUSH

'---------------------------------------------------------------------------
' GetThemeSysBool()   - Get the boolean value of specified System metric.
'
' hTheme              - the theme data handle.  if non-NULL, will return
'                     BOOL from [SysMetrics] section of theme.
'                     if NULL, will return the specified system boolean.
'
' iBoolId             - the TMT_XXX BOOL number (first BOOL
'                     is TMT_FLATMENUS)
'---------------------------------------------------------------------------

DECLARE FUNCTION GetThemeSysBool LIB "UxTheme.dll" _
    ALIAS "GetThemeSysBool" ( _
    BYVAL hTheme  AS DWORD, _
    BYVAL iBoolId AS LONG _
    ) AS LONG  ' BOOL

'---------------------------------------------------------------------------
' GetThemeSysSize()   - Get the value of the specified System size metric.
'                     (scaled for the current logical screen dpi)
'
' hTheme              - the theme data handle.  if non-NULL, will return
'                     size from [SysMetrics] section of theme.
'                     if NULL, will return the global system metric.
'
' iSizeId             - the following values are supported when
'                     hTheme is non-NULL:
'
'                       SM_CXBORDER       (border width)
'                       SM_CXVSCROLL      (scrollbar width)
'                       SM_CYHSCROLL      (scrollbar height)
'                       SM_CXSIZE         (caption width)
'                       SM_CYSIZE         (caption height)
'                       SM_CXSMSIZE       (small caption width)
'                       SM_CYSMSIZE       (small caption height)
'                       SM_CXMENUSIZE     (menubar width)
'                       SM_CYMENUSIZE     (menubar height)
'                       SM_CXPADDEDBORDER (padded border width)
'
'                     when hTheme is NULL, iSizeId is passed directly
'                     to the GetSystemMetrics() function
'---------------------------------------------------------------------------

DECLARE FUNCTION GetThemeSysSize LIB "UxTheme.dll" _
    ALIAS "GetThemeSysSize" ( _
    BYVAL hTheme AS DWORD, _  ' HTHEME
    BYVAL iSizeId AS LONG _
    ) AS LONG

'---------------------------------------------------------------------------
' GetThemeSysFont()   - Get the LOGFONT for the specified System font.
'
' hTheme              - the theme data handle.  if non-NULL, will return
'                     font from [SysMetrics] section of theme.
'                     if NULL, will return the specified system font.
'
' iFontId             - the TMT_XXX font number (first font
'                     is TMT_CAPTIONFONT)
'
' plf                 - ptr to LOGFONT to receive the font value.
'                     (scaled for the current logical screen dpi)
'---------------------------------------------------------------------------

DECLARE FUNCTION GetThemeSysFont LIB "UxTheme.dll" _
    ALIAS "GetThemeSysFont" ( _
    BYVAL hTheme  AS DWORD, _  ' HTHEME
    BYVAL iFontId AS LONG, _
    plf           AS LOGFONTW _
    ) AS LONG  ' HRESULT

'---------------------------------------------------------------------------
' GetThemeSysString() - Get the value of specified System string metric.
'
' hTheme              - the theme data handle (required)
'
' iStringId           - must be one of the following values:
'
'                       TMT_CSSNAME
'                       TMT_XMLNAME
'
' pszStringBuff       - the buffer to receive the string value
'
' cchMaxStringChars   - max. number of chars that pszStringBuff can hold
'---------------------------------------------------------------------------

DECLARE FUNCTION GetThemeSysString LIB "UxTheme.dll" _
    ALIAS "GetThemeSysString" ( _
    BYVAL hTheme            AS DWORD, _  ' HTHEME
    BYVAL iStringId         AS LONG, _
    pszStringBuff           AS WSTRINGZ, _
    BYVAL cchMaxStringChars AS LONG _
    ) AS LONG  ' HRESULT

'---------------------------------------------------------------------------
' GetThemeSysInt() - Get the value of specified System LONG.
'
' hTheme              - the theme data handle (required)
'
' iIntId              - must be one of the following values:
'
'                       TMT_DPIX
'                       TMT_DPIY
'                       TMT_MINCOLORDEPTH
'
' piValue             - ptr to LONG to receive value
'---------------------------------------------------------------------------

DECLARE FUNCTION GetThemeSysInt LIB "UxTheme.dll" _
    ALIAS "GetThemeSysInt" ( _
    BYVAL hTheme AS DWORD, _  ' HTHEME
    BYVAL iIntId AS LONG, _
    piValue      AS LONG _
    ) AS LONG  ' HRESULT

'---------------------------------------------------------------------------
' IsThemeActive()     - can be used to test if a system theme is active
'                     for the current user session.
'
'                     use the API "IsAppThemed()" to test if a theme is
'                     active for the calling process.
'---------------------------------------------------------------------------

DECLARE FUNCTION IsThemeActive LIB "UxTheme.dll" _
    ALIAS "IsThemeActive" () AS LONG  ' BOOL

'---------------------------------------------------------------------------
' IsAppThemed()       - returns TRUE if a theme is active and available to
'                     the current process
'---------------------------------------------------------------------------

DECLARE FUNCTION IsAppThemed LIB "UxTheme.dll" _
    ALIAS "IsAppThemed" () AS LONG  ' BOOL

'---------------------------------------------------------------------------
' GetWindowTheme()    - if window is themed, returns its most recent
'                     HTHEME from OpenThemeData() - otherwise, returns
'                     NULL.
'
'   hwnd            - the window to get the HTHEME of
'---------------------------------------------------------------------------

DECLARE FUNCTION GetWindowTheme LIB "UxTheme.dll" _
    ALIAS "GetWindowTheme" ( _
    BYVAL hwnd AS DWORD _  ' HWND
    ) AS DWORD  ' HTHEME

%ETDT_DISABLE                = &H00000001
%ETDT_ENABLE                 = &H00000002
%ETDT_USETABTEXTURE          = &H00000004

%ETDT_ENABLETAB              = %ETDT_ENABLE OR %ETDT_USETABTEXTURE

#IF (%WIN32_WINNT >= &H0600)
%ETDT_USEAEROWIZARDTABTEXTURE    = &H00000008

%ETDT_ENABLEAEROWIZARDTAB    = %ETDT_ENABLE OR %ETDT_USEAEROWIZARDTABTEXTURE

%ETDT_VALIDBITS              = %ETDT_DISABLE _
                            OR %ETDT_ENABLE _
                            OR %ETDT_USETABTEXTURE _
                            OR %ETDT_USEAEROWIZARDTABTEXTURE
#ENDIF

'---------------------------------------------------------------------------
' EnableThemeDialogTexture()
'
' - Enables/disables dialog background theme.  This method can be used to
' tailor dialog compatibility with child windows and controls that
' may or may not coordinate the rendering of their client area backgrounds
' with that of their parent dialog in a manner that supports seamless
' background texturing.
'
'   hdlg         - the window handle of the target dialog
'   dwFlags      - ETDT_ENABLE to enable the theme-defined dialog background texturing,
'                  ETDT_DISABLE to disable background texturing,
'                  ETDT_ENABLETAB to enable the theme-defined background
'                       texturing using the Tab texture
'---------------------------------------------------------------------------

DECLARE FUNCTION EnableThemeDialogTexture LIB "UxTheme.dll" _
    ALIAS "EnableThemeDialogTexture" ( _
    BYVAL hwnd    AS DWORD, _  ' HWND
    BYVAL dwFlags AS DWORD _
    ) AS LONG  ' HRESULT

'---------------------------------------------------------------------------
' IsThemeDialogTextureEnabled()
'
' - Reports whether the dialog supports background texturing.
'
'   hdlg         - the window handle of the target dialog
'---------------------------------------------------------------------------

DECLARE FUNCTION IsThemeDialogTextureEnabled LIB "UxTheme.dll" _
    ALIAS "IsThemeDialogTextureEnabled" ( _
    BYVAL hwnd AS DWORD _  ' HWND
    ) AS LONG  ' BOOL

'---------------------------------------------------------------------------
'---- flags to control theming within an app ----

%STAP_ALLOW_NONCLIENT  = 1
%STAP_ALLOW_CONTROLS   = 2
%STAP_ALLOW_WEBCONTENT = 4
%STAP_VALIDBITS        = %STAP_ALLOW_NONCLIENT _
                      OR %STAP_ALLOW_CONTROLS _
                      OR %STAP_ALLOW_WEBCONTENT

'---------------------------------------------------------------------------
' GetThemeAppProperties()
'                   - returns the app property flags that control theming
'---------------------------------------------------------------------------

DECLARE FUNCTION GetThemeAppProperties LIB "UxTheme.dll" _
    ALIAS "GetThemeAppProperties" () AS DWORD

'---------------------------------------------------------------------------
' SetThemeAppProperties()
'                   - sets the flags that control theming within the app
'
'   dwFlags         - the flag values to be set
'---------------------------------------------------------------------------

DECLARE SUB SetThemeAppProperties LIB "UxTheme.dll" _
    ALIAS "SetThemeAppProperties" (BYVAL dwFlags AS DWORD)

'---------------------------------------------------------------------------
' GetCurrentThemeName()
'                   - Get the name of the current theme in-use.
'                     Optionally, return the ColorScheme name and the
'                     Size name of the theme.
'
' pszThemeFileName    - receives the theme path and filename
' cchMaxNameChars     - max chars allowed in pszNameBuff
'
' pszColorBuff        - (optional) receives the canonical color scheme name
'                     (not the display name)
' cchMaxColorChars    - max chars allowed in pszColorBuff
'
' pszSizeBuff         - (optional) receives the canonical size name
'                     (not the display name)
' cchMaxSizeChars     - max chars allowed in pszSizeBuff
'---------------------------------------------------------------------------

DECLARE FUNCTION GetCurrentThemeName LIB "UxTheme.dll" _
    ALIAS "GetCurrentThemeName" ( _
    pszThemeFileName       AS WSTRINGZ, _
    BYVAL cchMaxNameChars  AS LONG, _
    pszColorBuff           AS WSTRINGZ, _
    BYVAL cchMaxColorChars AS LONG, _
    pszSizeBuff            AS WSTRINGZ, _
    BYVAL cchMaxSizeChars  AS LONG _
    ) AS LONG  ' HRESULT

$$SZ_THDOCPROP_DISPLAYNAME   = "DisplayName"$$
$$SZ_THDOCPROP_CANONICALNAME = "ThemeName"$$
$$SZ_THDOCPROP_TOOLTIP       = "ToolTip"$$
$$SZ_THDOCPROP_AUTHOR        = "author"$$

DECLARE FUNCTION GetThemeDocumentationProperty LIB "UxTheme.dll" _
    ALIAS "GetThemeDocumentationProperty" ( _
    pszThemeName         AS WSTRINGZ, _
    pszPropertyName      AS WSTRINGZ, _
    pszValueBuff         AS WSTRINGZ, _
    BYVAL cchMaxValChars AS LONG _
    ) AS LONG  ' HRESULT

'---------------------------------------------------------------------------
' Theme API Error Handling
'
'   All functions in the Theme API not returning an HRESULT (THEMEAPI_)
'   use the WIN32 function "SetLastError()" to record any call failures.
'
'   To retreive the error code of the last failure on the
'   current thread for these type of APIs, use the WIN32 function
'   "GetLastError()".
'
'   All Theme API error codes (HRESULTs and GetLastError() values)
'   should be normal win32 errors which can be formatted into
'   strings using the Win32 API FormatMessage().
'---------------------------------------------------------------------------

'---------------------------------------------------------------------------
' DrawThemeParentBackground()
'                   - used by partially-transparent or alpha-blended
'                     child controls to draw the part of their parent
'                     that they appear in front of.
'
' hwnd                - handle of the child control
'
' hdc                 - hdc of the child control
'
' prc                 - (optional) rect that defines the area to be
'                     drawn (CHILD coordinates)
'---------------------------------------------------------------------------

DECLARE FUNCTION DrawThemeParentBackground LIB "UxTheme.dll" _
    ALIAS "DrawThemeParentBackground" ( _
    BYVAL hwnd AS DWORD, _  ' HWND
    BYVAL hdc  AS DWORD, _  ' HDC
    prc        AS RECT _
    ) AS LONG  ' HRESULT


'---------------------------------------------------------------------------
' EnableTheming()     - enables or disables themeing for the current user
'                     in the current and future sessions.
'
' fEnable             - if FALSE, disable theming and turn themes off.
'                   - if TRUE, enable themeing and, if user previously
'                     had a theme active, make it active now.
'---------------------------------------------------------------------------

DECLARE FUNCTION EnableTheming LIB "UxTheme.dll" _
    ALIAS "EnableTheming" ( _
    BYVAL fEnable AS LONG _  ' BOOL
    ) AS LONG

%GBF_DIRECT      = &H00000001     ' direct dereferencing.
%GBF_COPY        = &H00000002     ' create a copy of the bitmap
%GBF_VALIDBITS   = %GBF_DIRECT OR %GBF_COPY

#IF (%WIN32_WINNT >= &H0600)

%DTPB_WINDOWDC           = &H00000001
%DTPB_USECTLCOLORSTATIC  = &H00000002
%DTPB_USEERASEBKGND      = &H00000004

'---------------------------------------------------------------------------
' DrawThemeParentBackgroundEx()
'                   - used by partially-transparent or alpha-blended
'                     child controls to draw the part of their parent
'                     that they appear in front of.
'                     Sends a WM_ERASEBKGND message followed by a WM_PRINTCLIENT.
'
' hwnd                - handle of the child control
'
' hdc                 - hdc of the child control
'
' dwFlags             - if 0, only returns S_OK if the parent handled
'                     WM_PRINTCLIENT.
'                   - if DTPB_WINDOWDC is set, hdc is assumed to be a window DC,
'                     not a client DC.
'                   - if DTPB_USEERASEBKGND is set, the function will return S_OK
'                     without sending a WM_CTLCOLORSTATIC message if the parent
'                     actually painted on WM_ERASEBKGND.
'                   - if DTPB_CTLCOLORSTATIC is set, the function will send
'                     a WM_CTLCOLORSTATIC message to the parent and use the
'                     brush if one is provided, else COLOR_BTNFACE.
'
' prc                 - (optional) rect that defines the area to be
'                     drawn (CHILD coordinates)
'
' Return value        - S_OK if something was painted, S_FALSE if not.
'---------------------------------------------------------------------------

DECLARE FUNCTION DrawThemeParentBackgroundEx LIB "UxTheme.dll" _
    ALIAS "DrawThemeParentBackgroundEx" ( _
    BYVAL hwnd    AS DWORD, _  ' HWND
    BYVAL hdc     AS DWORD, _  ' HDC
    BYVAL dwFlags AS DWORD, _
    prc           AS RECT _
    ) AS LONG  ' HRESULT


ENUM WINDOWTHEMEATTRIBUTETYPE SINGULAR
    WTA_NONCLIENT = 1
END ENUM

TYPE WTA_OPTIONS
    dwFlags AS DWORD    ' values for each style option specified in the bitmask
    dwMask  AS DWORD    ' bitmask for flags that are changing
                        ' valid options are: %WTNCA_NODRAWCAPTION, %WTNCA_NODRAWICON, %WTNCA_NOSYSMENU
END TYPE

%WTNCA_NODRAWCAPTION       = &H00000001   ' don't draw the window caption
%WTNCA_NODRAWICON          = &H00000002   ' don't draw the system icon
%WTNCA_NOSYSMENU           = &H00000004   ' don't expose the system menu icon functionality
%WTNCA_NOMIRRORHELP        = &H00000008   ' don't mirror the question mark, even in RTL layout
%WTNCA_VALIDBITS           = %WTNCA_NODRAWCAPTION _
                          OR %WTNCA_NODRAWICON _
                          OR %WTNCA_NOSYSMENU _
                          OR %WTNCA_NOMIRRORHELP

DECLARE FUNCTION SetWindowThemeAttribute LIB "UxTheme.dll" _
    ALIAS "SetWindowThemeAttribute" ( _
    BYVAL hwnd        AS DWORD, _  ' HWND
    BYVAL eAttribute  AS LONG, _  ' WINDOWTHEMEATTRIBUTETYPE enum
    BYVAL pvAttribute AS DWORD, _  ' PVOID
    BYVAL cbAttribute AS DWORD _
    ) AS LONG  ' HRESULT

FUNCTION SetWindowThemeNonClientAttributes ( _
    BYVAL hwnd         AS DWORD, _  ' HWND
    BYVAL dwMask       AS DWORD, _
    BYVAL dwAttributes AS DWORD _
    ) AS LONG  ' HRESULT

    LOCAL wta AS WTA_OPTIONS

    wta.dwFlags = dwAttributes
    wta.dwMask = dwMask

    FUNCTION = SetWindowThemeAttribute(hwnd, %WTA_NONCLIENT, VARPTR(wta), SIZEOF(wta))

END FUNCTION

#ENDIF ' #if (%WIN32_WINNT >= &H0600)

'---------------------------------------------------------------------------
'
' DrawThemeTextEx
'
' Note: DrawThemeTextEx only exists on Windows Vista and higher, but the
' following declarations are provided to enable declaring its prototype when
' compiling for all platforms.

' Callback function used by DrawThemeTextEx, instead of DrawText

DECLARE FUNCTION DTT_CALLBACK_PROC ( _
    BYVAL hdc     AS DWORD, _  ' HDC
    pszText       AS WSTRINGZ, _
    BYVAL cchText AS LONG, _
    prc           AS RECT, _
    BYVAL dwFlags AS DWORD, _
    BYVAL lParam  AS LONG _  ' LPARAM
    ) AS LONG

'---- bits used in dwFlags of DTTOPTS ----
%DTT_TEXTCOLOR     = &H00001     ' crText has been specified
%DTT_BORDERCOLOR   = &H00002     ' crBorder has been specified
%DTT_SHADOWCOLOR   = &H00004     ' crShadow has been specified
%DTT_SHADOWTYPE    = &H00008     ' iTextShadowType has been specified
%DTT_SHADOWOFFSET  = &H00010     ' ptShadowOffset has been specified
%DTT_BORDERSIZE    = &H00020     ' iBorderSize has been specified
%DTT_FONTPROP      = &H00040     ' iFontPropId has been specified
%DTT_COLORPROP     = &H00080     ' iColorPropId has been specified
%DTT_STATEID       = &H00100     ' IStateId has been specified
%DTT_CALCRECT      = &H00200     ' Use pRect as and in/out parameter
%DTT_APPLYOVERLAY  = &H00400     ' fApplyOverlay has been specified
%DTT_GLOWSIZE      = &H00800     ' iGlowSize has been specified
%DTT_CALLBACK      = &H01000     ' pfnDrawTextCallback has been specified
%DTT_COMPOSITED    = &H02000     ' Draws text with antialiased alpha (needs a DIB section)
%DTT_VALIDBITS     = %DTT_TEXTCOLOR _
                  OR %DTT_BORDERCOLOR _
                  OR %DTT_SHADOWCOLOR _
                  OR %DTT_SHADOWTYPE _
                  OR %DTT_SHADOWOFFSET _
                  OR %DTT_BORDERSIZE _
                  OR %DTT_FONTPROP _
                  OR %DTT_COLORPROP _
                  OR %DTT_STATEID _
                  OR %DTT_CALCRECT _
                  OR %DTT_APPLYOVERLAY _
                  OR %DTT_GLOWSIZE _
                  OR %DTT_COMPOSITED

TYPE DTTOPTS
    dwSize              AS DWORD        ' size of the struct
    dwFlags             AS DWORD        ' which options have been specified
    crText              AS COLORREF     ' color to use for text fill
    crBorder            AS COLORREF     ' color to use for text outline
    crShadow            AS COLORREF     ' color to use for text shadow
    iTextShadowType     AS LONG         ' TST_SINGLE or TST_CONTINUOUS
    ptShadowOffset      AS POINT        ' where shadow is drawn (relative to text)
    iBorderSize         AS LONG         ' Border radius around text
    iFontPropId         AS LONG         ' Font property to use for the text instead of TMT_FONT
    iColorPropId        AS LONG         ' Color property to use for the text instead of TMT_TEXTCOLOR
    iStateId            AS LONG         ' Alternate state id
    fApplyOverlay       AS LONG  ' BOOL ' Overlay text on top of any text effect?
    iGlowSize           AS LONG         ' Glow radious around text
    pfnDrawTextCallback AS DWORD  ' DTT_CALLBACK_PROC  ' Callback for DrawText
    lParam AS LONG  ' LPARAM            ' Parameter for callback
END TYPE

#IF (%WIN32_WINNT >= &H0600)

DECLARE FUNCTION DrawThemeTextEx LIB "UxTheme.dll" _
    ALIAS "DrawThemeTextEx" ( _
    BYVAL hTheme      AS DWORD, _  ' HTHEME
    BYVAL hdc         AS DWORD, _  ' HDC
    BYVAL iPartId     AS LONG, _
    BYVAL iStateId    AS LONG, _
    pszText           AS WSTRINGZ, _
    BYVAL cchText     AS LONG, _
    BYVAL dwTextFlags AS DWORD, _
    pRect             AS RECT, _
    pOptions          AS DTTOPTS _
    ) AS LONG  ' HRESULT


'-----------------------------------------------------------------------
' GetThemeStream() - Get the value for the specified STREAM property
'
'   hTheme      - theme data handle
'   iPartId     - part number
'   iStateId    - state number of part
'   iPropId     - the property number to get the value for
'   ppvStream   - if non-null receives the value of the STREAM property (not to be freed)
'   pcbStream   - if non-null receives the size of the STREAM property
'   hInst       - NULL when iPropId==TMT_STREAM, HINSTANCE of a loaded msstyles
'                 file when iPropId==TMT_DISKSTREAM (use GetCurrentThemeName
'                 and LoadLibraryEx(LOAD_LIBRARY_AS_DATAFILE)
'-----------------------------------------------------------------------

DECLARE FUNCTION GetThemeBitmap LIB "UxTheme.dll" _
    ALIAS "GetThemeBitmap" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    BYVAL iPropId  AS LONG, _
    BYVAL dwFlags  AS DWORD, _
    phBitmap       AS DWORD _  ' HBITMAP
    ) AS LONG  ' HRESULT

'-----------------------------------------------------------------------
' GetThemeStream() - Get the value for the specified STREAM property
'
'   hTheme      - theme data handle
'   iPartId     - part number
'   iStateId    - state number of part
'   iPropId     - the property number to get the value for
'   ppvStream   - if non-null receives the value of the STREAM property (not to be freed)
'   pcbStream   - if non-null receives the size of the STREAM property
'   hInst       - NULL when iPropId==TMT_STREAM, HINSTANCE of a loaded msstyles
'                 file when iPropId==TMT_DISKSTREAM (use GetCurrentThemeName
'                 and LoadLibraryEx(LOAD_LIBRARY_AS_DATAFILE)
'-----------------------------------------------------------------------

DECLARE FUNCTION GetThemeStream LIB "UxTheme.dll" _
    ALIAS "GetThemeStream" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    BYVAL iPropId  AS LONG, _
    ppvStream      AS DWORD, _  ' VOID PTR PTR
    pcbStream      AS DWORD, _
    BYVAL hInst    AS DWORD _  ' HINSTANCE
    ) AS LONG  ' HRESULT


'------------------------------------------------------------------------
' BufferedPaintInit() - Initialize the Buffered Paint API.
'                     Should be called prior to BeginBufferedPaint,
'                     and should have a matching BufferedPaintUnInit.
'------------------------------------------------------------------------

DECLARE FUNCTION BufferedPaintInit LIB "UxTheme.dll" _
    ALIAS "BufferedPaintInit" () AS LONG  ' HRESULT

'------------------------------------------------------------------------
' BufferedPaintUnInit() - Uninitialize the Buffered Paint API.
'                       Should be called once for each call to BufferedPaintInit,
'                       when calls to BeginBufferedPaint are no longer needed.
'------------------------------------------------------------------------

DECLARE FUNCTION BufferedPaintUnInit LIB "UxTheme.dll" _
    ALIAS "BufferedPaintUnInit" () AS LONG  ' HRESULT

'------------------------------------------------------------------------
' BeginBufferedPaint() - Begins a buffered paint operation.
'
' hdcTarget          - Target DC on which the buffer will be painted
' rcTarget           - Rectangle specifying the area of the target DC to paint to
' dwFormat           - Format of the buffer (see BP_BUFFERFORMAT)
' pPaintParams       - Paint operation parameters (see BP_PAINTPARAMS)
' phBufferedPaint    - Pointer to receive handle to new buffered paint context
'------------------------------------------------------------------------

' HPAINTBUFFER
MACRO HPAINTBUFFER=DWORD   ' HANDLE: handle to a buffered paint context


' BP_BUFFERFORMAT
ENUM BP_BUFFERFORMAT SINGULAR
    BPBF_COMPATIBLEBITMAP    ' Compatible bitmap
    BPBF_DIB                 ' Device-independent bitmap
    BPBF_TOPDOWNDIB          ' Top-down device-independent bitmap
    BPBF_TOPDOWNMONODIB      ' Top-down monochrome device-independent bitmap
END ENUM

%BPBF_COMPOSITED = %BPBF_TOPDOWNDIB


' BP_ANIMATIONSTYLE
ENUM BP_ANIMATIONSTYLE SINGULAR
    BPAS_NONE                ' No animation
    BPAS_LINEAR              ' Linear fade animation
    BPAS_CUBIC               ' Cubic fade animation
    BPAS_SINE                ' Sinusoid fade animation
END ENUM


' BP_ANIMATIONPARAMS
TYPE BP_ANIMATIONPARAMS
    cbSize     AS DWORD
    dwFlags    AS DWORD                ' %BPAF_ flags
    style      AS LONG  ' BP_ANIMATIONSTYLE enum
    dwDuration AS DWORD
END TYPE

%BPPF_ERASE     = &H0001 ' Empty the buffer during BeginBufferedPaint()
%BPPF_NOCLIP    = &H0002 ' Don't apply the target DC's clip region to the double buffer
%BPPF_NONCLIENT = &H0004 ' Using a non-client DC


' BP_PAINTPARAMS
TYPE BP_PAINTPARAMS
    cbSize         AS DWORD
    dwFlags        AS DWORD                        ' BPPF_ flags
    prcExclude     AS RECT PTR
    pBlendFunction AS BLENDFUNCTION PTR
END TYPE

DECLARE FUNCTION BeginBufferedPaint LIB "UxTheme.dll" _
    ALIAS "BeginBufferedPaint" ( _
    BYVAL hdcTarget AS DWORD, _  ' HDC
    prcTarget       AS RECT, _
    BYVAL dwFormat  AS LONG, _  ' BP_BUFFERFORMAT enum
    pPaintParams    AS LONG, _  ' BP_PAINTPARAMS enum
    phdc            AS DWORD _  ' HDC
    ) AS DWORD  ' HPAINTBUFFER


'------------------------------------------------------------------------
' EndBufferedPaint() - Ends a buffered paint operation.
'
' hBufferedPaint   - handle to buffered paint context
' fUpdateTarget    - update target DC
'------------------------------------------------------------------------

DECLARE FUNCTION EndBufferedPaint LIB "UxTheme.dll" _
    ALIAS "EndBufferedPaint" ( _
    BYVAL hBufferedPaint AS DWORD, _  ' HPAINTBUFFER
    BYVAL fUpdateTarget  AS LONG _  ' BOOL
    ) AS LONG  ' HRESULT

'------------------------------------------------------------------------
' GetBufferedPaintTargetRect() - Returns the target rectangle specified during BeginBufferedPaint
'
' hBufferedPaint             - handle to buffered paint context
' prc                        - pointer to receive target rectangle
'------------------------------------------------------------------------

DECLARE FUNCTION GetBufferedPaintTargetRect LIB "UxTheme.dll" _
    ALIAS "GetBufferedPaintTargetRect" ( _
    BYVAL hBufferedPaint AS DWORD, _  ' HPAINTBUFFER
    prc                  AS RECT _
    ) AS LONG  ' HRESULT

'------------------------------------------------------------------------
' GetBufferedPaintTargetDC() - Returns the target DC specified during BeginBufferedPaint
'
' hBufferedPaint           - handle to buffered paint context
'------------------------------------------------------------------------

DECLARE FUNCTION GetBufferedPaintTargetDC LIB "UxTheme.dll" _
    ALIAS "GetBufferedPaintTargetDC" ( _
    BYVAL hBufferedPaint AS DWORD _  ' HPAINTBUFFER
    ) AS DWORD  ' HDC

'------------------------------------------------------------------------
' GetBufferedPaintDC() - Returns the same paint DC returned by BeginBufferedPaint
'
' hBufferedPaint     - handle to buffered paint context
'------------------------------------------------------------------------

DECLARE FUNCTION GetBufferedPaintDC LIB "UxTheme.dll" _
    ALIAS "GetBufferedPaintDC" ( _
    BYVAL hBufferedPaint AS DWORD _  ' HPAINTBUFFER
    ) AS DWORD  ' HDC

'------------------------------------------------------------------------
' GetBufferedPaintBits() - Obtains a pointer to the buffer bitmap, if the buffer is a DIB
'
' hBufferedPaint       - handle to buffered paint context
' ppbBuffer            - pointer to receive pointer to buffer bitmap pixels
' pcxRow               - pointer to receive width of buffer bitmap, in pixels;
'                        this value may not necessarily be equal to the buffer width
'------------------------------------------------------------------------

DECLARE FUNCTION GetBufferedPaintBits LIB "UxTheme.dll" _
    ALIAS "GetBufferedPaintBits" ( _
    BYVAL hBufferedPaint AS DWORD, _  ' HPAINTBUFFER
    ppbBuffer            AS DWORD, _  ' RGBQUAD PTR PTR
    pcxRow               AS LONG _
    ) AS LONG  ' HRESULT

'------------------------------------------------------------------------
' BufferedPaintClear() - Clears given rectangle to ARGB = {0, 0, 0, 0}
'
' hBufferedPaint     - handle to buffered paint context
' prc                - rectangle to clear; NULL specifies entire buffer
'------------------------------------------------------------------------

DECLARE FUNCTION BufferedPaintClear LIB "UxTheme.dll" _
    ALIAS "BufferedPaintClear" ( _
    BYVAL hBufferedPaint AS DWORD, _  ' HPAINTBUFFER
    prc                  AS RECT _
    ) AS LONG  ' HRESULT

'------------------------------------------------------------------------
' BufferedPaintSetAlpha() - Set alpha to given value in given rectangle
'
' hBufferedPaint        - handle to buffered paint context
' prc                   - rectangle to set alpha in; NULL specifies entire buffer
' alpha                 - alpha value to set in the given rectangle
'------------------------------------------------------------------------

DECLARE FUNCTION BufferedPaintSetAlpha LIB "UxTheme.dll" _
    ALIAS "BufferedPaintSetAlpha" ( _
    BYVAL hBufferedPaint AS DWORD, _  ' HPAINTBUFFER
    prc                  AS RECT, _
    BYVAL alpha          AS BYTE _
    ) AS LONG  ' HRESULT

' Macro for setting the buffer to opaque (alpha = 255)
MACRO BufferedPaintMakeOpaque(hBufferedPaint,prc)=BufferedPaintSetAlpha(hBufferedPaint,prc,255)

'------------------------------------------------------------------------
' BufferedPaintStopAllAnimations() - Stop all buffer animations for the given window
'
' hwnd                           - window on which to stop all animations
'------------------------------------------------------------------------

DECLARE FUNCTION BufferedPaintStopAllAnimations LIB "UxTheme.dll" _
    ALIAS "BufferedPaintStopAllAnimations" ( _
    BYVAL hwnd AS DWORD _  ' HWND
    ) AS LONG  ' HRESULT

MACRO HANIMATIONBUFFER=DWORD  ' HANDLE: handle to a buffered paint animation

DECLARE FUNCTION BeginBufferedAnimation LIB "UxTheme.dll" _
    ALIAS "BeginBufferedAnimation" ( _
    BYVAL hwnd       AS DWORD, _  ' HWND
    BYVAL hdcTarget  AS DWORD, _  ' HDC
    prcTarget        AS RECT, _
    BYVAL dwFormat   AS LONG, _  ' BP_BUFFERFORMAT enum
    pPaintParams     AS LONG, _  ' BP_PAINTPARAMS enum
    pAnimationParams AS LONG, _  ' BP_ANIMATIONPARAMS enum
    phdcFrom         AS DWORD, _  ' HDC
    phdcTo           AS DWORD _  ' HDC
    ) AS HANIMATIONBUFFER

DECLARE FUNCTION EndBufferedAnimation LIB "UxTheme.dll" _
    ALIAS "EndBufferedAnimation" ( _
    BYVAL hbpAnimation  AS HANIMATIONBUFFER, _
    BYVAL fUpdateTarget AS LONG _  ' BOOL
    ) AS LONG  ' HRESULT

DECLARE FUNCTION BufferedPaintRenderAnimation LIB "UxTheme.dll" _
    ALIAS "BufferedPaintRenderAnimation" ( _
    BYVAL hwnd      AS DWORD, _  ' HWND
    BYVAL hdcTarget AS DWORD _  ' HDC
    ) AS LONG  ' BOOL

'----------------------------------------------------------------------------
' Tells if the DWM is running, and composition effects are possible for this
' process (themes are active).
' Roughly equivalent to "DwmIsCompositionEnabled() AND IsAppthemed()"
'----------------------------------------------------------------------------

DECLARE FUNCTION IsCompositionActive LIB "UxTheme.dll" _
    ALIAS "IsCompositionActive" () AS LONG  ' BOOL

'------------------------------------------------------------------------
' GetThemeTransitionDuration()
'                   - Gets the duration for the specified transition
'
' hTheme              - theme data handle
' iPartId             - part number
' iStateIdFrom        - starting state number of part
' iStateIdTo          - ending state number of part
' iPropId             - property id
' pdwDuration         - receives the transition duration
'------------------------------------------------------------------------

DECLARE FUNCTION GetThemeTransitionDuration LIB "UxTheme.dll" _
    ALIAS "GetThemeTransitionDuration" ( _
    BYVAL hTheme       AS DWORD, _  ' HTHEME
    BYVAL iPartId      AS LONG, _
    BYVAL iStateIdFrom AS LONG, _
    BYVAL iStateIdTo   AS LONG, _
    BYVAL iPropId      AS LONG, _
    pdwDuration        AS DWORD _
    ) AS LONG  ' HRESULT

#ENDIF ' #if (%WIN32_WINNT >= &H0600)
