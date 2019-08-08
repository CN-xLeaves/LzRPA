'------------------------------------------------------------------------------
'
'  HtmlHelp.inc
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 10 Mar 2011
'
'------------------------------------------------------------------------------
'  From HtmlHelp.h 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%HTMLHELP_H = 1

#INCLUDE "WinDef.inc"


' Commands to pass to HtmlHelp()

%HH_DISPLAY_TOPIC        = &H0000
%HH_HELP_FINDER          = &H0000  ' WinHelp equivalent
%HH_DISPLAY_TOC          = &H0001
%HH_DISPLAY_INDEX        = &H0002
%HH_DISPLAY_SEARCH       = &H0003
%HH_SET_WIN_TYPE         = &H0004
%HH_GET_WIN_TYPE         = &H0005
%HH_GET_WIN_HANDLE       = &H0006
%HH_ENUM_INFO_TYPE       = &H0007  ' Get Info type name, call repeatedly to enumerate, -1 at end
%HH_SET_INFO_TYPE        = &H0008  ' Add Info type to filter.
%HH_SYNC                 = &H0009
%HH_RESERVED1            = &H000A
%HH_RESERVED2            = &H000B
%HH_RESERVED3            = &H000C
%HH_KEYWORD_LOOKUP       = &H000D
%HH_DISPLAY_TEXT_POPUP   = &H000E  ' display string resource id or text in a popup window
%HH_HELP_CONTEXT         = &H000F  ' display mapped numeric value in dwData
%HH_TP_HELP_CONTEXTMENU  = &H0010  ' text popup help, same as WinHelp HELP_CONTEXTMENU
%HH_TP_HELP_WM_HELP      = &H0011  ' text popup help, same as WinHelp HELP_WM_HELP
%HH_CLOSE_ALL            = &H0012  ' close all windows opened directly or indirectly by the caller
%HH_ALINK_LOOKUP         = &H0013  ' ALink version of HH_KEYWORD_LOOKUP
%HH_GET_LAST_ERROR       = &H0014  ' not currently implemented ' See HHERROR.h
%HH_ENUM_CATEGORY        = &H0015  ' Get category name, call repeatedly to enumerate, -1 at end
%HH_ENUM_CATEGORY_IT     = &H0016  ' Get category info type members, call repeatedly to enumerate, -1 at end
%HH_RESET_IT_FILTER      = &H0017  ' Clear the info type filter of all info types.
%HH_SET_INCLUSIVE_FILTER = &H0018  ' set inclusive filtering method for untyped topics to be included in display
%HH_SET_EXCLUSIVE_FILTER = &H0019  ' set exclusive filtering method for untyped topics to be excluded from display
%HH_INITIALIZE            = &H001C  ' Initializes the help system.
%HH_UNINITIALIZE          = &H001D  ' Uninitializes the help system.
%HH_SET_QUERYSERVICE     = &H001E  ' Set the Host IQueryService interface
%HH_PRETRANSLATEMESSAGE  = &H00fd  ' Pumps messages. (NULL, NULL, MSG*).
%HH_SET_GLOBAL_PROPERTY  = &H00fc  ' Set a global property. (NULL, NULL, HH_GPROP)
%HH_SAFE_DISPLAY_TOPIC   = &H0020  ' private addition to the interface for InternetExplorer.

%HHWIN_PROP_TAB_AUTOHIDESHOW = &H00000001???   ' Automatically hide/show tri-pane window
%HHWIN_PROP_ONTOP            = &H00000002???   ' Top-most window
%HHWIN_PROP_NOTITLEBAR       = &H00000004???   ' no title bar
%HHWIN_PROP_NODEF_STYLES     = &H00000008???   ' no default window styles (only HH_WINTYPE.dwStyles)
%HHWIN_PROP_NODEF_EXSTYLES   = &H00000010???   ' no default extended window styles (only HH_WINTYPE.dwExStyles)
%HHWIN_PROP_TRI_PANE         = &H00000020???   ' use a tri-pane window
%HHWIN_PROP_NOTB_TEXT        = &H00000040???   ' no text on toolbar buttons
%HHWIN_PROP_POST_QUIT        = &H00000080???   ' post WM_QUIT message when window closes
%HHWIN_PROP_AUTO_SYNC        = &H00000100???   ' automatically ssync contents and index
%HHWIN_PROP_TRACKING         = &H00000200???   ' send tracking notification messages
%HHWIN_PROP_TAB_SEARCH       = &H00000400???   ' include search tab in navigation pane
%HHWIN_PROP_TAB_HISTORY      = &H00000800???   ' include history tab in navigation pane
%HHWIN_PROP_TAB_FAVORITES    = &H00001000???   ' include favorites tab in navigation pane
%HHWIN_PROP_CHANGE_TITLE     = &H00002000???   ' Put current HTML title in title bar
%HHWIN_PROP_NAV_ONLY_WIN     = &H00004000???   ' Only display the navigation window
%HHWIN_PROP_NO_TOOLBAR       = &H00008000???   ' Don't display a toolbar
%HHWIN_PROP_MENU             = &H00010000???   ' Menu
%HHWIN_PROP_TAB_ADVSEARCH    = &H00020000???   ' Advanced FTS UI.
%HHWIN_PROP_USER_POS         = &H00040000???   ' After initial creation, user controls window size/position
%HHWIN_PROP_TAB_CUSTOM1      = &H00080000???   ' Use custom tab #1
%HHWIN_PROP_TAB_CUSTOM2      = &H00100000???   ' Use custom tab #2
%HHWIN_PROP_TAB_CUSTOM3      = &H00200000???   ' Use custom tab #3
%HHWIN_PROP_TAB_CUSTOM4      = &H00400000???   ' Use custom tab #4
%HHWIN_PROP_TAB_CUSTOM5      = &H00800000???   ' Use custom tab #5
%HHWIN_PROP_TAB_CUSTOM6      = &H01000000???   ' Use custom tab #6
%HHWIN_PROP_TAB_CUSTOM7      = &H02000000???   ' Use custom tab #7
%HHWIN_PROP_TAB_CUSTOM8      = &H03000000???   ' Use custom tab #8
%HHWIN_PROP_TAB_CUSTOM9      = &H04000000???   ' Use custom tab #9
%HHWIN_TB_MARGIN             = &H10000000???   ' the window type has a margin

%HHWIN_PARAM_PROPERTIES      = &H00000002???   ' valid fsWinProperties
%HHWIN_PARAM_STYLES          = &H00000004???   ' valid dwStyles
%HHWIN_PARAM_EXSTYLES        = &H00000008???   ' valid dwExStyles
%HHWIN_PARAM_RECT            = &H00000010???   ' valid rcWindowPos
%HHWIN_PARAM_NAV_WIDTH       = &H00000020???   ' valid iNavWidth
%HHWIN_PARAM_SHOWSTATE       = &H00000040???   ' valid nShowState
%HHWIN_PARAM_INFOTYPES       = &H00000080???   ' valid apInfoTypes
%HHWIN_PARAM_TB_FLAGS        = &H00000100???   ' valid fsToolBarFlags
%HHWIN_PARAM_EXPANSION       = &H00000200???   ' valid fNotExpanded
%HHWIN_PARAM_TABPOS          = &H00000400???   ' valid tabpos
%HHWIN_PARAM_TABORDER        = &H00000800???   ' valid taborder
%HHWIN_PARAM_HISTORY_COUNT   = &H00001000???   ' valid cHistory
%HHWIN_PARAM_CUR_TAB         = &H00002000???   ' valid curNavType

%HHWIN_BUTTON_EXPAND         = &H00000002???   ' Expand/contract button
%HHWIN_BUTTON_BACK           = &H00000004???   ' Back button
%HHWIN_BUTTON_FORWARD        = &H00000008???   ' Forward button
%HHWIN_BUTTON_STOP           = &H00000010???   ' Stop button
%HHWIN_BUTTON_REFRESH        = &H00000020???   ' Refresh button
%HHWIN_BUTTON_HOME           = &H00000040???   ' Home button
%HHWIN_BUTTON_BROWSE_FWD     = &H00000080???   ' not implemented
%HHWIN_BUTTON_BROWSE_BCK     = &H00000100???   ' not implemented
%HHWIN_BUTTON_NOTES          = &H00000200???   ' not implemented
%HHWIN_BUTTON_CONTENTS       = &H00000400???   ' not implemented
%HHWIN_BUTTON_SYNC           = &H00000800???   ' Sync button
%HHWIN_BUTTON_OPTIONS        = &H00001000???   ' Options button
%HHWIN_BUTTON_PRINT          = &H00002000???   ' Print button
%HHWIN_BUTTON_INDEX          = &H00004000???   ' not implemented
%HHWIN_BUTTON_SEARCH         = &H00008000???   ' not implemented
%HHWIN_BUTTON_HISTORY        = &H00010000???   ' not implemented
%HHWIN_BUTTON_FAVORITES      = &H00020000???   ' not implemented
%HHWIN_BUTTON_JUMP1          = &H00040000???
%HHWIN_BUTTON_JUMP2          = &H00080000???
%HHWIN_BUTTON_ZOOM           = &H00100000???
%HHWIN_BUTTON_TOC_NEXT       = &H00200000???
%HHWIN_BUTTON_TOC_PREV       = &H00400000???

%HHWIN_DEF_BUTTONS = %HHWIN_BUTTON_EXPAND  _
                  OR %HHWIN_BUTTON_BACK    _
                  OR %HHWIN_BUTTON_OPTIONS _
                  OR %HHWIN_BUTTON_PRINT

' Button IDs

%IDTB_EXPAND      =      200
%IDTB_CONTRACT    =      201
%IDTB_STOP        =      202
%IDTB_REFRESH     =      203
%IDTB_BACK        =      204
%IDTB_HOME        =      205
%IDTB_SYNC        =      206
%IDTB_PRINT       =      207
%IDTB_OPTIONS     =      208
%IDTB_FORWARD     =      209
%IDTB_NOTES       =      210 ' not implemented
%IDTB_BROWSE_FWD  =      211
%IDTB_BROWSE_BACK =      212
%IDTB_CONTENTS    =      213 ' not implemented
%IDTB_INDEX       =      214 ' not implemented
%IDTB_SEARCH      =      215 ' not implemented
%IDTB_HISTORY     =      216 ' not implemented
%IDTB_FAVORITES   =      217 ' not implemented
%IDTB_JUMP1       =      218
%IDTB_JUMP2       =      219
%IDTB_CUSTOMIZE   =      221
%IDTB_ZOOM        =      222
%IDTB_TOC_NEXT    =      223
%IDTB_TOC_PREV    =      224

' Notification codes

%HHN_FIRST = -860
%HHN_LAST  = -879

%HHN_NAVCOMPLETE   = %HHN_FIRST
%HHN_TRACK         = %HHN_FIRST - 1
%HHN_WINDOW_CREATE = %HHN_FIRST - 2

TYPE HHN_NOTIFY
    hdr    AS NMHDR
    pszUrl AS ASCIIZ PTR   ' Multi-byte, null-terminated string
END TYPE

TYPE HH_POPUP
    cbStruct      AS LONG       ' sizeof this structure
    hinst         AS DWORD      ' instance handle for string resource
    idString      AS DWORD      ' string resource id, or text id if pszFile is specified in HtmlHelp call
    pszText       AS ASCIIZ PTR ' used if idString is zero
    pt            AS POINT      ' top center of popup window
    clrForeground AS DWORD      ' use BITS???(-1) for default
    clrBackground AS DWORD      ' use BITS???(-1) for default
    rcMargins     AS RECT       ' amount of space between edges of window and text, -1 for each member to ignore
    pszFont       AS ASCIIZ PTR ' facename, point size, char set, BOLD ITALIC UNDERLINE
END TYPE

TYPE HH_AKLINK
    cbStruct     AS LONG       ' sizeof this structure
    fReserved    AS LONG       ' must be FALSE (really!)
    pszKeywords  AS ASCIIZ PTR ' semi-colon separated keywords
    pszUrl       AS ASCIIZ PTR ' URL to jump to if no keywords found (may be NULL)
    pszMsgText   AS ASCIIZ PTR ' Message text to display in MessageBox if pszUrl is NULL and no keyword match
    pszMsgTitle  AS ASCIIZ PTR ' Message text to display in MessageBox if pszUrl is NULL and no keyword match
    pszWindow    AS ASCIIZ PTR ' Window to display URL in
    fIndexOnFail AS LONG       ' Displays index if keyword lookup fails.
END TYPE

%HHWIN_NAVTYPE_TOC          = 0
%HHWIN_NAVTYPE_INDEX        = 1
%HHWIN_NAVTYPE_SEARCH       = 2
%HHWIN_NAVTYPE_FAVORITES    = 3
%HHWIN_NAVTYPE_HISTORY      = 4   ' not implemented
%HHWIN_NAVTYPE_AUTHOR       = 5
%HHWIN_NAVTYPE_CUSTOM_FIRST = 11

%IT_INCLUSIVE = 0
%IT_EXCLUSIVE = 1
%IT_HIDDEN    = 2

TYPE HH_ENUM_IT
    cbStruct         AS LONG       ' size of this structure
    iType            AS LONG       ' the type of the information type ie. Inclusive, Exclusive, or Hidden
    pszCatName       AS ASCIIZ PTR ' Set to the name of the Category to enumerate the info types in a category; else NULL
    pszITName        AS ASCIIZ PTR ' volatile pointer to the name of the infotype. Allocated by call. Caller responsible for freeing
    pszITDescription AS ASCIIZ PTR ' volatile pointer to the description of the infotype.
END TYPE

TYPE HH_ENUM_CAT
    cbStruct          AS LONG       ' size of this structure
    pszCatName        AS ASCIIZ PTR ' volatile pointer to the category name
    pszCatDescription AS ASCIIZ PTR ' volatile pointer to the category description
END TYPE

TYPE HH_SET_INFOTYPE
    cbStruct        AS LONG       ' the size of this structure
    pszCatName      AS ASCIIZ PTR ' the name of the category, if any, the InfoType is a member of.
    pszInfoTypeName AS ASCIIZ PTR ' the name of the info type to add to the filter
END TYPE

'typedef DWORD HH_INFOTYPE;
'typedef HH_INFOTYPE* PHH_INFOTYPE;

%HHWIN_NAVTAB_TOP    = 0
%HHWIN_NAVTAB_LEFT   = 1
%HHWIN_NAVTAB_BOTTOM = 2

%HH_MAX_TABS = 19  ' maximum number of tabs

%HH_TAB_CONTENTS     = 0
%HH_TAB_INDEX        = 1
%HH_TAB_SEARCH       = 2
%HH_TAB_FAVORITES    = 3
%HH_TAB_HISTORY      = 4
%HH_TAB_AUTHOR       = 5
%HH_TAB_CUSTOM_FIRST = 11
%HH_TAB_CUSTOM_LAST  = %HH_MAX_TABS

%HH_MAX_TABS_CUSTOM = (%HH_TAB_CUSTOM_LAST - %HH_TAB_CUSTOM_FIRST) + 1

' HH_DISPLAY_SEARCH Command Related Structures and Constants

%HH_FTS_DEFAULT_PROXIMITY  = -1&

TYPE HH_FTS_QUERY
    cbStruct        AS LONG       ' Sizeof structure in bytes.
    fUniCodeStrings AS LONG       ' TRUE if all strings are unicode.
    pszSearchQuery  AS ASCIIZ PTR ' String containing the search query.
    iProximity      AS LONG       ' Word proximity.
    fStemmedSearch  AS LONG       ' TRUE for StemmedSearch only.
    fTitleOnly      AS LONG       ' TRUE for Title search only.
    fExecute        AS LONG       ' TRUE to initiate the search.
    pszWindow       AS ASCIIZ PTR ' Window to display in
END TYPE

' HH_WINTYPE Structure

TYPE HH_WINTYPE
    cbStruct        AS LONG       ' IN: size of this structure including all Information Types
    fUniCodeStrings AS LONG       ' IN/OUT: TRUE if all strings are in UNICODE
    pszType         AS ASCIIZ PTR ' IN/OUT: Name of a type of window
    fsValidMembers  AS DWORD      ' IN: Bit flag of valid members (HHWIN_PARAM_)
    fsWinProperties AS DWORD      ' IN/OUT: Properties/attributes of the window (HHWIN_)

    pszCaption      AS ASCIIZ PTR ' IN/OUT: Window title
    dwStyles        AS DWORD      ' IN/OUT: Window styles
    dwExStyles      AS DWORD      ' IN/OUT: Extended Window styles
    rcWindowPos     AS RECT       ' IN: Starting position, OUT: current position
    nShowState      AS LONG       ' IN: show state (e.g., SW_SHOW)

    hwndHelp        AS DWORD      ' OUT: window handle
    hwndCaller      AS DWORD      ' OUT: who called this window

    paInfoTypes     AS DWORD PTR  ' IN: Pointer to an array of Information Types

    ' The following members are only valid if HHWIN_PROP_TRI_PANE is set

    hwndToolBar     AS DWORD      ' OUT: toolbar window in tri-pane window
    hwndNavigation  AS DWORD      ' OUT: navigation window in tri-pane window
    hwndHTML        AS DWORD      ' OUT: window displaying HTML in tri-pane window
    iNavWidth       AS LONG       ' IN/OUT: width of navigation window
    rcHTML          AS RECT       ' OUT: HTML window coordinates

    pszToc          AS ASCIIZ PTR ' IN: Location of the table of contents file
    pszIndex        AS ASCIIZ PTR ' IN: Location of the index file
    pszFile         AS ASCIIZ PTR ' IN: Default location of the html file
    pszHome         AS ASCIIZ PTR ' IN/OUT: html file to display when Home button is clicked
    fsToolBarFlags  AS DWORD      ' IN: flags controling the appearance of the toolbar
    fNotExpanded    AS LONG       ' IN: TRUE/FALSE to contract or expand, OUT: current state
    curNavType      AS LONG       ' IN/OUT: UI to display in the navigational pane
    tabpos          AS LONG       ' IN/OUT: HHWIN_NAVTAB_TOP, HHWIN_NAVTAB_LEFT, or HHWIN_NAVTAB_BOTTOM
    idNotify        AS LONG       ' IN: ID to use for WM_NOTIFY messages
    tabOrder(%HH_MAX_TABS) AS BYTE ' IN/OUT: tab order: Contents, Index, Search, History, Favorites, Reserved 1-5, Custom tabs
    cHistory        AS LONG       ' IN/OUT: number of history items to keep (default is 30)
    pszJump1        AS ASCIIZ PTR ' Text for HHWIN_BUTTON_JUMP1
    pszJump2        AS ASCIIZ PTR ' Text for HHWIN_BUTTON_JUMP2
    pszUrlJump1     AS ASCIIZ PTR ' URL for HHWIN_BUTTON_JUMP1
    pszUrlJump2     AS ASCIIZ PTR ' URL for HHWIN_BUTTON_JUMP2
    rcMinSize       AS RECT       ' Minimum size for window (ignored in version 1)
    cbInfoTypes     AS LONG       ' size of paInfoTypes;
    pszCustomTabs   AS ASCIIZ PTR ' multiple zero-terminated strings
END TYPE

%HHACT_TAB_CONTENTS  = 0
%HHACT_TAB_INDEX     = 1
%HHACT_TAB_SEARCH    = 2
%HHACT_TAB_HISTORY   = 3
%HHACT_TAB_FAVORITES = 4

%HHACT_EXPAND        = 5
%HHACT_CONTRACT      = 6
%HHACT_BACK          = 7
%HHACT_FORWARD       = 8
%HHACT_STOP          = 9
%HHACT_REFRESH       = 10
%HHACT_HOME          = 11
%HHACT_SYNC          = 12
%HHACT_OPTIONS       = 13
%HHACT_PRINT         = 14
%HHACT_HIGHLIGHT     = 15
%HHACT_CUSTOMIZE     = 16
%HHACT_JUMP1         = 17
%HHACT_JUMP2         = 18
%HHACT_ZOOM          = 19
%HHACT_TOC_NEXT      = 20
%HHACT_TOC_PREV      = 21
%HHACT_NOTES         = 22

%HHACT_LAST_ENUM     = 23

TYPE HHNTRACK
    hdr        AS NMHDR
    pszCurUrl  AS ASCIIZ PTR     ' Multi-byte, null-terminated string
    idAction   AS LONG           ' HHACT_ value
    phhWinType AS HH_WINTYPE PTR ' Current window type structure
END TYPE


DECLARE FUNCTION HtmlHelpA LIB "hhctrl.ocx" ALIAS "HtmlHelpA" _
    (BYVAL hwndCaller AS DWORD, pszFile AS ASCIIZ, BYVAL uCommand AS DWORD, _
    BYVAL dwData AS DWORD) AS DWORD

DECLARE FUNCTION HtmlHelpW LIB "hhctrl.ocx" ALIAS "HtmlHelpW" _
    (BYVAL hwndCaller AS DWORD, pszFile AS WSTRINGZ, BYVAL uCommand AS DWORD, _
    BYVAL dwData AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION HtmlHelp LIB "hhctrl.ocx" ALIAS "HtmlHelpW" _
    (BYVAL hwndCaller AS DWORD, pszFile AS WSTRINGZ, BYVAL uCommand AS DWORD, _
    BYVAL dwData AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION HtmlHelp LIB "hhctrl.ocx" ALIAS "HtmlHelpA" _
    (BYVAL hwndCaller AS DWORD, pszFile AS ASCIIZ, BYVAL uCommand AS DWORD, _
    BYVAL dwData AS DWORD) AS DWORD
#ENDIF ' NOT %UNICODE

' Use the following for GetProcAddress to load from hhctrl.ocx

%ATOM_HTMLHELP_API_ANSI    = 14
%ATOM_HTMLHELP_API_UNICODE = 15

'------------------------------------------------------------------------------
'
' Global Control Properties.
'
MACRO HH_GPROPID_enum=LONG
ENUM HHGPROPID SINGULAR
    HH_GPROPID_SINGLETHREAD   = 1  ' VARIANT_BOOL: True for single thread
    HH_GPROPID_TOOLBAR_MARGIN      ' long: Provides a left/right margin around the toolbar.
    HH_GPROPID_UI_LANGUAGE         ' long: LangId of the UI.
    HH_GPROPID_CURRENT_SUBSET      ' BSTR: Current subset.
    HH_GPROPID_CONTENT_LANGUAGE    ' long: LandId for desired content.
END ENUM

'------------------------------------------------------------------------------
'
' Global Property structure
'
#IF %DEF(%oaidl_h)

TYPE gHH_GLOBAL_PROPERTY
    id  AS HH_GPROPID_enum
    var AS VARIANT_type
END TYPE

#ENDIF
