'==============================================================================
' TOOLBAR CONTROL

$TOOLBARCLASSNAME      = "ToolbarWindow32"

'%TBN_FIRST               = 0-700      ' toolbar
'%TBN_LAST                = 0-720

'DECLARE FUNCTION CreateToolbarEx LIB "COMCTL32.DLL" ALIAS "CreateToolbarEx" _
'    (BYVAL hWnd AS DWORD, BYVAL ws AS DWORD, BYVAL wID AS WORD, _
'    BYVAL nBitmaps AS LONG, BYVAL hBMInst AS DWORD, BYVAL wBMID AS DWORD, _
'    lpButtons AS TBBUTTON, BYVAL iNumButtons AS LONG, BYVAL dxButton AS LONG, _
'    BYVAL dyButton AS LONG, BYVAL dxBitmap AS LONG, BYVAL dyBitmap AS LONG, _
'    BYVAL uStructSize AS DWORD) AS DWORD
'
'DECLARE FUNCTION CreateMappedBitmap LIB "COMCTL32.DLL" _
'    ALIAS "CreateMappedBitmap" (BYVAL hInstance AS DWORD, _
'    BYVAL idBitmap AS LONG, BYVAL wFlags AS DWORD, lpColorMap AS COLORMAP, _
'    BYVAL iNumMaps AS LONG) AS DWORD

%CMB_MASKED             = &H02

%TBSTATE_CHECKED        = &H0001
%TBSTATE_PRESSED        = &H0002
%TBSTATE_ENABLED        = &H0004
%TBSTATE_HIDDEN         = &H0008
%TBSTATE_INDETERMINATE  = &H0010
%TBSTATE_WRAP           = &H0020
%TBSTATE_ELLIPSES       = &H0040
%TBSTATE_MARKED         = &H0080

%TBSTYLE_BUTTON         = &H0000
%TBSTYLE_SEP            = &H0001
%TBSTYLE_CHECK          = &H0002
%TBSTYLE_GROUP          = &H0004
%TBSTYLE_CHECKGROUP     = %TBSTYLE_GROUP OR %TBSTYLE_CHECK
%TBSTYLE_DROPDOWN       = &H0008
%TBSTYLE_AUTOSIZE       = &H0010 ' automatically calculate the cx of the button
%TBSTYLE_NOPREFIX       = &H0020 ' if this button should not have accel prefix

%TBSTYLE_TOOLTIPS        = &H00000100
%TBSTYLE_WRAPABLE        = &H00000200
%TBSTYLE_ALTDRAG         = &H00000400
%TBSTYLE_FLAT            = &H00000800
%TBSTYLE_LIST            = &H00001000
%TBSTYLE_CUSTOMERASE     = &H00002000
%TBSTYLE_REGISTERDROP    = &H00004000
%TBSTYLE_TRANSPARENT     = &H00008000
%TBSTYLE_EX_DRAWDDARROWS = &H00000001

%BTNS_BUTTON     = %TBSTYLE_BUTTON      ' &H0000
%BTNS_SEP        = %TBSTYLE_SEP         ' &H0001
%BTNS_CHECK      = %TBSTYLE_CHECK       ' &H0002
%BTNS_GROUP      = %TBSTYLE_GROUP       ' &H0004
%BTNS_CHECKGROUP = %TBSTYLE_CHECKGROUP  ' (%TBSTYLE_GROUP OR %TBSTYLE_CHECK)
%BTNS_DROPDOWN   = %TBSTYLE_DROPDOWN    ' &H0008
%BTNS_AUTOSIZE   = %TBSTYLE_AUTOSIZE    ' &H0010; automatically calculate the cx of the button
%BTNS_NOPREFIX   = %TBSTYLE_NOPREFIX    ' &H0020; this button should not have accel prefix
%BTNS_SHOWTEXT   = &H0040              ' ignored unless %TBSTYLE_EX_MIXEDBUTTONS is set
%BTNS_WHOLEDROPDOWN  = &H0080          ' draw drop-down arrow, but without split arrow section

%TBSTYLE_EX_MIXEDBUTTONS       = &H00000008
%TBSTYLE_EX_HIDECLIPPEDBUTTONS = &H00000010 ' don't show partially obscured buttons

%TBSTYLE_EX_DOUBLEBUFFER       = &H00000080 ' Double Buffer the toolbar

'TYPE NMTBCUSTOMDRAW
'    nmcd                 AS NMCUSTOMDRAW
'    hbrMonoDither        AS DWORD
'    hbrLines             AS DWORD  ' For drawing lines on buttons
'    hpenLines            AS DWORD  ' For drawing lines on buttons
'    clrText              AS DWORD  ' Color of text
'    clrMark              AS DWORD  ' Color of text bk when marked (only if TBSTATE_MARKED)
'    clrTextHighlight     AS DWORD  ' Color of text when highlighted
'    clrBtnFace           AS DWORD  ' Background of the button
'    clrBtnHighlight      AS DWORD  ' 3D highlight
'    clrHighlightHotTrack AS DWORD  ' In conjunction with fHighlightHotTrack,
'    rcText               AS RECT   ' will cause button to highlight like a menu
'    nStringBkMode        AS LONG   ' Rect for text
'    nHLStringBkMode      AS LONG
'    iListGap             AS LONG
'END TYPE

' Toolbar custom draw return flags
%TBCDRF_NOEDGES        = &H00010000 ' Don't draw button edges
%TBCDRF_HILITEHOTTRACK = &H00020000 ' Use color of the button bk when hottracked
%TBCDRF_NOOFFSET       = &H00040000 ' Don't offset button if pressed
%TBCDRF_NOMARK         = &H00080000 ' Don't draw default highlight of image/text for TBSTATE_MARKED
%TBCDRF_NOETCHEDEFFECT = &H00100000 ' Don't draw etched effect for disabled items
%TBCDRF_BLENDICON      = &H00200000 ' Use ILD_BLEND50 on the icon image
%TBCDRF_NOBACKGROUND   = &H00400000 ' Use ILD_BLEND50 on the icon image

%TB_ENABLEBUTTON             = %WM_USER + 1
%TB_CHECKBUTTON              = %WM_USER + 2
%TB_PRESSBUTTON              = %WM_USER + 3
%TB_HIDEBUTTON               = %WM_USER + 4
%TB_INDETERMINATE            = %WM_USER + 5
%TB_MARKBUTTON               = %WM_USER + 6
%TB_ISBUTTONENABLED          = %WM_USER + 9
%TB_ISBUTTONCHECKED          = %WM_USER + 10
%TB_ISBUTTONPRESSED          = %WM_USER + 11
%TB_ISBUTTONHIDDEN           = %WM_USER + 12
%TB_ISBUTTONINDETERMINATE    = %WM_USER + 13
%TB_ISBUTTONHIGHLIGHTED      = %WM_USER + 14
%TB_SETSTATE                 = %WM_USER + 17
%TB_GETSTATE                 = %WM_USER + 18
%TB_ADDBITMAP                = %WM_USER + 19

%HINST_COMMCTRL          = &HFFFFFFFF ' -1
%IDB_STD_SMALL_COLOR     = 0
%IDB_STD_LARGE_COLOR     = 1
%IDB_VIEW_SMALL_COLOR    = 4
%IDB_VIEW_LARGE_COLOR    = 5
%IDB_HIST_SMALL_COLOR    = 8
%IDB_HIST_LARGE_COLOR    = 9

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
%VIEW_VIEWMENU       = 12

%HIST_BACK           = 0
%HIST_FORWARD        = 1
%HIST_FAVORITES      = 2
%HIST_ADDTOFAVORITES = 3
%HIST_VIEWTREE       = 4

%TB_ADDBUTTONS       = %WM_USER + 20
%TB_INSERTBUTTON     = %WM_USER + 21
%TB_DELETEBUTTON     = %WM_USER + 22
%TB_GETBUTTON        = %WM_USER + 23
%TB_BUTTONCOUNT      = %WM_USER + 24
%TB_COMMANDTOINDEX   = %WM_USER + 25

TYPE TBSAVEPARAMS
    hkr AS DWORD
    pszSubKey AS ASCIIZ PTR
    pszValueName AS ASCIIZ PTR
END TYPE

%TB_SAVERESTORE           = %WM_USER + 26
%TB_SAVERESTOREW          = %WM_USER + 76
%TB_CUSTOMIZE             = %WM_USER + 27
%TB_ADDSTRING             = %WM_USER + 28
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
%TB_GETBUTTONTEXT         = %WM_USER + 45
%TB_GETBUTTONTEXTW        = %WM_USER + 75
%TB_REPLACEBITMAP         = %WM_USER + 46
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

%TB_GETOBJECT             = %WM_USER + 62  ' wParam == IID, lParam void **ppv
%TB_GETHOTITEM            = %WM_USER + 71
%TB_SETHOTITEM            = %WM_USER + 72  ' wParam == iHotItem
%TB_SETANCHORHIGHLIGHT    = %WM_USER + 73  ' wParam == TRUE/FALSE
%TB_GETANCHORHIGHLIGHT    = %WM_USER + 74
%TB_MAPACCELERATOR        = %WM_USER + 78  ' wParam == ch, lParam int * pidBtn

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

'%TB_SETCOLORSCHEME       = %CCM_SETCOLORSCHEME  ' lParam is color scheme
'%TB_GETCOLORSCHEME       = %CCM_GETCOLORSCHEME  ' fills in COLORSCHEME pointed to by lParam

'%TB_SETUNICODEFORMAT     = %CCM_SETUNICODEFORMAT
'%TB_GETUNICODEFORMAT     = %CCM_GETUNICODEFORMAT

%TB_MAPACCELERATORW      = %WM_USER + 90  ' wParam == ch, lParam int * pidBtn

%TBBF_LARGE              = &H0001

%TB_GETBITMAPFLAGS       = (%WM_USER + 41)

%TBIF_IMAGE   = &H00000001
%TBIF_TEXT    = &H00000002
%TBIF_STATE   = &H00000004
%TBIF_STYLE   = &H00000008
%TBIF_LPARAM  = &H00000010
%TBIF_COMMAND = &H00000020
%TBIF_SIZE    = &H00000040
%TBIF_BYINDEX = &H80000000 ' this specifies that the wparam in Get/SetButtonInfo is an index, not id

TYPE TBBUTTONINFO
    cbSize AS DWORD
    dwMask AS DWORD
    idCommand AS LONG
    iImage AS LONG
    fsState AS BYTE
    fsStyle AS BYTE
    cx AS WORD
    lParam AS DWORD
    pszText AS ASCIIZ PTR
    cchText AS LONG
END TYPE

' BUTTONINFO APIs do NOT support the string pool.
%TB_GETBUTTONINFOW        = %WM_USER + 63
%TB_SETBUTTONINFOW        = %WM_USER + 64
%TB_GETBUTTONINFO         = %WM_USER + 65
%TB_SETBUTTONINFO         = %WM_USER + 66

' New post Win95/NT4 for InsertButton and AddButton.  if iString member
' is a pointer to a string, it will be handled as a string like listview
' (although LPSTR_TEXTCALLBACK is not supported).

%TB_INSERTBUTTONW        = %WM_USER + 67
%TB_ADDBUTTONSW          = %WM_USER + 68

%TB_HITTEST              = %WM_USER + 69

%TB_SETDRAWTEXTFLAGS     = %WM_USER + 70  ' wParam == mask lParam == bit values

%TB_GETSTRINGW           = %WM_USER + 91
%TB_GETSTRING            = %WM_USER + 92

%TBMF_PAD                = &H00000001
%TBMF_BARPAD             = &H00000002
%TBMF_BUTTONSPACING      = &H00000004

TYPE TBMETRICS
    cbSize AS DWORD
    dwMask AS DWORD
    cxPad AS LONG        ' PAD
    cyPad AS LONG
    cxBarPad AS LONG     ' BARPAD
    cyBarPad AS LONG
    cxButtonSpacing AS LONG   ' BUTTONSPACING
    cyButtonSpacing AS LONG
END TYPE

%TB_GETMETRICS      = %WM_USER + 101
%TB_SETMETRICS      = %WM_USER + 102
'%TB_SETWINDOWTHEME  = %CCM_SETWINDOWTHEME

%TBN_GETBUTTONINFO  = %TBN_FIRST - 0
%TBN_BEGINDRAG      = %TBN_FIRST - 1
%TBN_ENDDRAG        = %TBN_FIRST - 2
%TBN_BEGINADJUST    = %TBN_FIRST - 3
%TBN_ENDADJUST      = %TBN_FIRST - 4
%TBN_RESET          = %TBN_FIRST - 5
%TBN_QUERYINSERT    = %TBN_FIRST - 6
%TBN_QUERYDELETE    = %TBN_FIRST - 7
%TBN_TOOLBARCHANGE  = %TBN_FIRST - 8
%TBN_CUSTHELP       = %TBN_FIRST - 9
%TBN_DROPDOWN       = %TBN_FIRST - 10
%TBN_GETOBJECT      = %TBN_FIRST - 12

' Structure for %TBN_HOTITEMCHANGE notification
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
%TBN_GETDISPINFO     = %TBN_FIRST - 16 ' This is sent when the toolbar needs some display information
%TBN_GETDISPINFOW    = %TBN_FIRST - 17 ' This is sent when the toolbar needs some display information
%TBN_GETINFOTIP      = %TBN_FIRST - 18
%TBN_GETINFOTIPW     = %TBN_FIRST - 19
%TBN_GETBUTTONINFOW  = %TBN_FIRST - 20
%TBN_RESTORE         = %TBN_FIRST - 21
%TBN_SAVE            = %TBN_FIRST - 22
%TBN_INITCUSTOMIZE   = %TBN_FIRST - 23

%TBNRF_HIDEHELP      = &H00000001
%TBNRF_ENDCUSTOMIZE  = &H00000002

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

TYPE NMTBGETINFOTIP
    hdr        AS NMHDR
    pszText    AS ASCIIZ PTR
    cchTextMax AS LONG
    iItem      AS LONG
    lParam     AS LONG
END TYPE

%TBNF_IMAGE       = &H00000001
%TBNF_TEXT        = &H00000002
%TBNF_DI_SETITEM  = &H10000000

TYPE NMTBDISPINFO
    hdr       AS NMHDR
    dwMask    AS DWORD      ' [in] Specifies the values requested .[out] Client ask the data to be set for future use
    idCommand AS LONG       ' [in] id of button we're requesting info for
    lParam    AS DWORD      ' [in] lParam of button
    iImage    AS LONG       ' [out] image index
    pszText   AS ASCIIZ PTR ' [out] new text for item
    cchText   AS LONG       ' [in] size of buffer pointed to by pszText
END TYPE

' Return codes for TBN_DROPDOWN
%TBDDRET_DEFAULT      = 0
%TBDDRET_NODEFAULT    = 1
%TBDDRET_TREATPRESSED = 2       ' Treat as a standard press button

TYPE NMTOOLBAR
    hdr      AS NMHDR
    iItem    AS LONG
    tbButton AS TBBUTTON
    cchText  AS LONG
    pszText  AS ASCIIZ PTR
    rcButton AS RECT
END TYPE
