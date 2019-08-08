
'------------------------------------------------------------------------------
' Filename    : MENU.INC
'
' Description : Custom draw for Menus based on Borje's DrawMenu Source Code.
'               NOTE: I have modified Borje's DRAWMENU Code to use ImageLists.
'                     So please look at the code to see what has changed.
'
'               Compiler Version - PB/WIN 7.02
'               Win32Api Version - Last Update: 27 August 2003.
'               Creation Date    - 
'               Creation Time    - 
'               Window Platforms - Windows 95, 98, ME And XP.
'
' A Special Thank you to Borje for his DrawMenu Source Code.
'------------------------------------------------------------------------------

'------------------------------------------------------------------------------
' Constants and Equates.
'------------------------------------------------------------------------------
' ImageList Draw Style Constants.
%IMG_DIS = 0      '= Disabled
%IMG_NOR = 1      '= Normal
%IMG_HOT = 2      '= Selected

'------------------------------------------------------------------------------
' NOTE: These Constants will change depending on your Applications Menu's and
'       ToolBars. If you use 24x24 Toolbar bitmaps then you will need a 16x16
'       bitmap strip for the Menu's...
'------------------------------------------------------------------------------
' Menu And ToolBar ID Constants.
' FILE
%IDM_FILE             = %WM_USER       + 2048   ' File Menu
%IDM_NEW              = %IDM_FILE      + 1       ' New File
%IDM_OPEN             = %IDM_NEW       + 1      ' Open File
%IDM_SAVE             = %IDM_OPEN      + 1      ' Save
%IDM_SAVEAS           = %IDM_SAVE      + 1      ' Save As
%IDM_EXIT             = %IDM_SAVEAS    + 1      ' Exit

' EDIT
%IDM_EDIT             = %IDM_EXIT      + 1      ' Edit Menu
%IDM_UNDO             = %IDM_EDIT      + 1      ' Undo
%IDM_CUT              = %IDM_UNDO      + 1      ' Cut
%IDM_COPY             = %IDM_CUT       + 1      ' Copy
%IDM_PASTE            = %IDM_COPY      + 1      ' Paste
%IDM_SELALL           = %IDM_PASTE     + 1      ' Select All

' EMAIL
%IDM_EMAIL            = %IDM_SELALL    + 1      ' Email Us

' HELP
%IDM_HELP             = %IDM_EMAIL     + 1      ' Display Html Help
%IDM_HELPCONT         = %IDM_HELP      + 1      ' Help Contents.

%IDM_ABOUT            = %IDM_HELPCONT  + 1      ' About box      

'------------------------------------------------------------------------------
' Global Variables.
'------------------------------------------------------------------------------
GLOBAL hIml AS DWORD
GLOBAL IsCode AS LONG

'------------------------------------------------------------------------------
' Application Functions and Sub-Routine Procedures.
'------------------------------------------------------------------------------

'------------------------------------------------------------------------------
' Function    : GetMenuBmpHandle ()
'
' Description : Get desired Menu Item's bitmap handle.
'
' NOTE        : You will need to modify the bitmap names in the LoadImage
'               to load your own bitmap strips, if you use 24x24 Toolbar
'               bitmap strips. ie: TBDIS, TBNOR and TBHOT. Use a new name...
'------------------------------------------------------------------------------
FUNCTION GetMenuBmpHandle (BYVAL BmpNum AS LONG, _
                           BYVAL nState AS LONG) AS LONG

  LOCAL hBmp1  AS DWORD
  LOCAL hBmp2  AS DWORD
  LOCAL hDC    AS DWORD
  LOCAL memDC1 AS DWORD
  LOCAL memDC2 AS DWORD
  
  '----------------------------------------------------------------------------
  ' Load the Bitmap Strips and create the ImageLists.
  '----------------------------------------------------------------------------
  ' Disabled bitmap strip.
  IF nState = %IMG_DIS THEN
    hBmp1 = LoadImage(GetModuleHandle(""), "TBDIS", %IMAGE_BITMAP, 0, 0, _
                      %LR_LOADTRANSPARENT OR %LR_LOADMAP3DCOLORS OR %LR_DEFAULTSIZE)
  END IF
  
  ' Normal bitmap strip.
  IF nState = %IMG_NOR THEN
    hBmp1 = LoadImage(GetModuleHandle(""), "TBNOR", %IMAGE_BITMAP, 0, 0, _
                      %LR_LOADTRANSPARENT OR %LR_LOADMAP3DCOLORS OR %LR_DEFAULTSIZE)
  END IF
  
  ' Hot Selected bitmap strip.
  IF nState = %IMG_HOT THEN  
    hBmp1 = LoadImage(GetModuleHandle(""), "TBHOT", %IMAGE_BITMAP, 0, 0, _
                      %LR_LOADTRANSPARENT OR %LR_LOADMAP3DCOLORS OR %LR_DEFAULTSIZE)
  END IF
  
  '----------------------------------------------------------------------------
  ' Create memory DC's and draw the bitmaps.
  '----------------------------------------------------------------------------    
  hdc = GetDc(0)                               ' GET device context FOR screen
  memDC1 = CreateCompatibleDC (hDC)            ' Create two memory device contexts
  memDC2 = CreateCompatibleDC (hDC)
  hBmp2  = CreateCompatibleBitmap(hDC, 16, 16) ' Create compatible 16x16 pixel bmp
  ReleaseDC 0, hdc                             ' Release the DC - don't need it anymore.
  
  SelectObject memDC1, hBmp1                   ' Select the bitmaps into the mem dc's
  SelectObject memDC2, hBmp2
  
  BitBlt memDC2, 0, 0, 16, 16, _               ' copy bNum part of hBmp1 strip to hBmp2
         memDC1, BmpNum * 16, 0, %SRCCOPY
  
  
  DeleteDC memDC1          ' Cleanup memDC's and delete main bmp strip object
  DeleteDC memDC2    
  DeleteObject hBmp1       ' (note: 16x16 pixel hBmp2 is deleted in DrawMenu routine)
  
  FUNCTION = hBmp2         ' return handle to 16x16 pixel bitmap
  
END FUNCTION

'------------------------------------------------------------------------------
' Function    : GetMenuTxtAndBmp ()
'
' Description : Return menu item string and zero-based bitmap number 
'               (-1 = no bitmap).
'               Bitmap ImageList Strip starts at Zero, so BmpNum starts at Zero.
'------------------------------------------------------------------------------
FUNCTION GetMenuTxtAndBmp (BYVAL ItemId AS LONG, _
                           byref BmpNum AS LONG) AS STRING

  SELECT CASE ItemId
    ' FILE MENU.
    CASE %IDM_FILE    : BmpNum = -1 : FUNCTION = "&File"
    CASE %IDM_NEW     : BmpNum =  0 : FUNCTION = "&New"        & $TAB & "Ctrl+N"
    CASE %IDM_OPEN    : BmpNum =  1 : FUNCTION = "&Open..."    & $TAB & "Ctrl+O"
    CASE %IDM_SAVE    : BmpNum =  2 : FUNCTION = "&Save"       & $TAB & "Ctrl+S"
    CASE %IDM_SAVEAS  : BmpNum = -1 : FUNCTION = "&Save as..."
    CASE %IDM_EXIT    : BmpNum = -1 : FUNCTION = "E&xit"       & $TAB & "Alt+F4"
     
    ' EDIT MENU.
    CASE %IDM_EDIT    : BmpNum = -1 : FUNCTION = "&Edit"
    CASE %IDM_UNDO    : BmpNum = -1 : FUNCTION = "&Undo"       & $TAB & "Ctrl+Z"
    CASE %IDM_CUT     : BmpNum =  5 : FUNCTION = "Cu&t"        & $TAB & "Ctrl+X"
    CASE %IDM_COPY    : BmpNum =  6 : FUNCTION = "&Copy"       & $TAB & "Ctrl+C"
    CASE %IDM_PASTE   : BmpNum =  7 : FUNCTION = "&Paste"      & $TAB & "Ctrl+V"
    CASE %IDM_SELALL  : BmpNum = -1 : FUNCTION = "Select &All" & $TAB & "Ctrl+A"
    
    ' HELP MENU.
    CASE %IDM_HELP     : BmpNum = -1 : FUNCTION = "&Help"
    CASE %IDM_HELPCONT : BmpNum = -1 : FUNCTION = "Help &Contents" & $TAB & "F1"
    CASE %IDM_ABOUT    : BmpNum = -1 : FUNCTION = "About"
  END SELECT

END FUNCTION

'------------------------------------------------------------------------------
' Sub Routine : DrawMenu ()
'
' Description : Draw Owner Drawn Menu Items - called from OnDrawItem ().
'------------------------------------------------------------------------------ 
SUB DrawMenu (BYREF lp AS LONG)

  REGISTER c             AS LONG        ' for/next counter
  
  LOCAL ShortCutWidth    AS LONG        ' for ShortCut text width (if any)
  LOCAL id               AS LONG        ' tmp item id
  LOCAL BmpNum           AS LONG        ' bitmap number
  LOCAL hBmp             AS LONG        ' icon to draw
  LOCAL hBrush           AS LONG        ' brush used for selection draw
  LOCAL bHighlight       AS LONG        ' higlighted flag
  LOCAL drawTxtFlags     AS DWORD       ' how we draw the text
  LOCAL drawBmpFlags     AS DWORD       ' how we draw the icon
  LOCAL menuBtnW         AS LONG        ' Width of the menubutton, in pixels
  LOCAL sCaption         AS STRING      ' string for the menu item text
  LOCAL sShortCut        AS STRING      ' string for eventual shortcut text
  LOCAL rc               AS RECT        ' RECT used for drawing areas
  LOCAL szl              AS SIZEL       ' used to calculate text extent
  LOCAL lpDis AS DRAWITEMSTRUCT PTR     ' we fill this from received pointer
  
  LOCAL nState           AS LONG        ' For ImageList Bitmap Strip ID.
  
  lpDis    = lp                               ' Get structure from given pointer
  menuBtnW = GetSystemMetrics(%SM_CYMENU) - 1 ' for "button" size

  '----------------------------------------------------------------------------
  ' Calculate pos for eventual shortcut. We need to look at all items
  ' in dropped menu and calculate largest width, which then is used
  ' as base to calculate all shortcuts' pos.
  '----------------------------------------------------------------------------
  FOR c = 0 TO GetMenuItemCount(@lpDis.hwndItem) - 1 ' hwndItem is dropped menu's handle
     id = GetMenuItemID(@lpDis.hwndItem, c)

     IF id THEN
        sCaption = GetMenuTxtAndBmp(id, 0)
        IF INSTR(sCaption, $TAB) THEN        ' if it has shortcut (Ctrl+X, etc.)
           sShortCut = TRIM$(PARSE$(sCaption, $TAB, 2))
        ELSE
           sShortCut = ""
        END IF

        IF LEN(sShortCut) THEN
           GetTextExtentPoint32 @lpDis.hDC, BYVAL STRPTR(sShortCut), _
                                LEN(sShortCut), BYVAL VARPTR(szl)
           ShortCutWidth = MAX&(ShortCutWidth, szl.cx)
        END IF
     END IF
  NEXT
  
  '----------------------------------------------------------------------------
  ' Get menu item string and split up into ev. text and shortcut part.
  '----------------------------------------------------------------------------
  sCaption = GetMenuTxtAndBmp(@lpDis.itemID, BmpNum)
  
  IF INSTR(sCaption, $TAB) THEN             ' if it has shortcut (Ctrl+X, etc.)
     sShortCut = TRIM$(PARSE$(sCaption, $TAB, 2))
     sCaption  = TRIM$(PARSE$(sCaption, $TAB, 1))
  ELSE
     sCaption = TRIM$(sCaption)
     sShortCut = ""
  END IF
 
  '----------------------------------------------------------------------------
  ' Calculate menu item string's height.
  '----------------------------------------------------------------------------
  GetTextExtentPoint32 @lpDis.hDC, BYVAL STRPTR(sCaption), LEN(sCaption), szl
 
  '----------------------------------------------------------------------------
  ' Sep up colors depending on what drawing actions we need to take.
  '----------------------------------------------------------------------------
  IF (@lpDis.itemState AND %ODS_SELECTED) THEN         ' menu item is selected 
     nState = %IMG_HOT
     hBrush =     GetSysColorBrush(%COLOR_HIGHLIGHT)
     SetBkColor   @lpDis.hDC, GetSysColor(%COLOR_HIGHLIGHT)
     SetTextColor @lpDis.hDC, GetSysColor(%COLOR_HIGHLIGHTTEXT)
     bHighlight = %TRUE  ' flag, so later we can add or remove the 3D edge around the icon
  ELSEIF (@lpDis.itemState AND %ODS_GRAYED) THEN       ' menu item is disabled
     nState = %IMG_DIS
     hBrush =     GetSysColorBrush(%COLOR_MENU)
     SetBkColor   @lpDis.hDC, GetSysColor(%COLOR_MENU)
     SetTextColor @lpDis.hDC, GetSysColor(%COLOR_MENUTEXT)
  ELSE                                                 ' not selected or disabled
     nState = %IMG_NOR
     hBrush =     GetSysColorBrush(%COLOR_MENU)
     SetBkColor   @lpDis.hDC, GetSysColor(%COLOR_MENU)
     SetTextColor @lpDis.hDC, GetSysColor(%COLOR_MENUTEXT)
  END IF

  drawTxtFlags = %DST_PREFIXTEXT
  drawBmpFlags = %DST_BITMAP
 
  IF (@lpDis.itemState AND %ODS_GRAYED) THEN           ' if disabled item
     IF (@lpDis.itemState AND %ODS_SELECTED) THEN      ' if it's selected
        SetTextColor @lpDis.hDC, GetSysColor(%COLOR_GRAYTEXT)
     ELSE
        drawTxtFlags = drawTxtFlags OR %DSS_DISABLED
     END IF
  END IF
 
  '----------------------------------------------------------------------------
  ' Calculate rect for highlight area (selected item) and fill rect with proper
  ' color, either COLOR_MENU or COLOR_HIGHLIGHT, depending on selection state.
  '----------------------------------------------------------------------------
  rc = @lpDis.rcItem
  IF (@lpDis.itemState AND %ODS_GRAYED) OR BmpNum = -1 THEN ' grayed or no bitmap
     rc.nLeft = 0
  ELSE
     rc.nLeft = menuBtnW + 4                                ' enabled, with bitmap
  END IF
  
  ' For GRAYED With Bitmap.
  IF (@lpDis.itemState AND %ODS_GRAYED) THEN
     IF BmpNum => 0 THEN
        rc.nLeft     = menuBtnW + 4
        hBrush       = GetSysColorBrush(%COLOR_MENU)
        drawTxtFlags = drawTxtFlags OR %DSS_DISABLED
     END IF
  END IF
  
  FillRect @lpDis.hDC, rc, hBrush
  
  '----------------------------------------------------------------------------
  ' Draw the disabled bitmap.
  '----------------------------------------------------------------------------
  IF (@lpDis.itemState AND %ODS_GRAYED) THEN
     ' Draw Disabled Bitmap.
     IF BmpNum => 0 THEN hBmp = GetMenuBmpHandle(BmpNum, nState)
     IF nState = %IMG_DIS THEN
        ImageList_DrawEx(ghImlDis, BmpNum, @lpDis.hDC, ((menuBtnW + 3) \ 2) - 8, _
                        ((@lpDis.rcItem.nTop + @lpDis.rcItem.nBottom) \ 2) - 8, _
                        16, 16, %CLR_NONE, %CLR_NONE, %ILD_TRANSPARENT)
     END IF
  END IF
  
  '----------------------------------------------------------------------------
  ' Draw the bitmap "button", if item is not grayed out (disabled).
  '----------------------------------------------------------------------------
  ' ImageList Draw Style Constants.
  ' %IMG_DIS = 0 : %IMG_NOR = 1 : %IMG_HOT = 2

  IF (@lpDis.itemState AND %ODS_GRAYED) = 0 THEN

     IF BmpNum => 0 THEN hBmp = GetMenuBmpHandle(BmpNum, nState)
 
     IF hBmp <> 0 THEN     ' Draw bitmap, centered in "button"
        ' Draw Normal Bitmap.
        IF nState = %IMG_NOR THEN
           ImageList_DrawEx(ghImlNor, BmpNum, @lpDis.hDC, ((menuBtnW + 3) \ 2) - 8, _
                           ((@lpDis.rcItem.nTop + @lpDis.rcItem.nBottom) \ 2) - 8, _
                           16, 16, %CLR_NONE, %CLR_NONE, %ILD_TRANSPARENT)
        END IF
        
        ' Draw Hot Selected Bitmap.
        IF nState = %IMG_HOT THEN
           ImageList_DrawEx(ghImlHot, BmpNum, @lpDis.hDC, ((menuBtnW + 3) \ 2) - 8, _
                           ((@lpDis.rcItem.nTop + @lpDis.rcItem.nBottom) \ 2) - 8, _
                           16, 16, %CLR_NONE, %CLR_NONE, %ILD_TRANSPARENT)
        END IF
        
        '----------------------------------------------------------------------
        ' Calculate the RECT we need for the 3D edge.
        '----------------------------------------------------------------------
        rc = @lpDis.rcItem
        rc.nLeft   = 0                           ' Size and pos for "button"..
        rc.nRight  = menuBtnW + 3
        rc.nBottom = rc.nTop  + GetSystemMetrics(%SM_CYMENU) + 1
        
        '----------------------------------------------------------------------
        ' Draw "button" if the item is highlighted, or flat if it's not.
        '----------------------------------------------------------------------
        IF bHighlight = %TRUE THEN
           DrawEdge @lpDis.hDC, rc, %BDR_RAISEDINNER, %BF_RECT
        ELSE
           DrawEdge @lpDis.hDC, rc, %BDR_RAISEDINNER, %BF_FLAT OR %BF_RECT
        END IF
     END IF
 
  END IF
  
  DeleteObject hBmp       ' Delete the bitmap when done, to avoid memory leaks!
    
  '----------------------------------------------------------------------------
  ' Draw the menu text next to bitmap button, with centered y-pos.
  '----------------------------------------------------------------------------
  IF LEN(sCaption) THEN
       rc.nLeft = menuBtnW + 6 : rc.nRight = @lpDis.rcItem.nRight
       rc.nTop = rc.nTop + ((rc.nBottom - rc.nTop) - szl.cy) \ 2
       DrawState @lpDis.hDC, 0&, 0&, BYVAL STRPTR(sCaption), LEN(sCaption), _
                 rc.nLeft, rc.nTop, rc.nRight, szl.cy, drawTxtFlags

     IF ShortCutWidth THEN             ' if there's shortcut text (Ctrl+N, etc)
        DrawState @lpDis.hDC, 0&, 0&, BYVAL STRPTR(sShortCut), LEN(sShortCut), _
                  @lpDis.rcItem.nRight - ShortCutWidth - 8, rc.nTop, _
                  rc.nRight, szl.cy, drawTxtFlags
     END IF
  END IF
 
END SUB

'------------------------------------------------------------------------------
' Sub Routine : MeasureMenu ()
'
' Description : Called form the OnMeasureMenu () handler.
'------------------------------------------------------------------------------ 
SUB MeasureMenu (BYVAL hWnd   AS DWORD, _
                 BYVAL lParam AS DWORD)

 LOCAL hDC   AS DWORD
 LOCAL hf    AS DWORD
 LOCAL txt   AS STRING
 LOCAL sl    AS SIZEL
 LOCAL lpMis AS MEASUREITEMSTRUCT PTR
 LOCAL ncm   AS NONCLIENTMETRICS

  lpMis = lParam                           ' lParam points to MEASUREITEMSTRUCT
  txt   = GetMenuTxtAndBmp(@lpMis.itemID, 0) ' get menu item's text

  hDC = GetDC(hWnd)                        ' grab dialog's DC
    ncm.cbSize = SIZEOF(ncm)               ' grab menu font
    SystemParametersInfo %SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), BYVAL VARPTR(ncm), 0

    IF LEN(ncm.lfMenuFont) THEN
       hf = CreateFontIndirect(ncm.lfMenuFont) ' create font from menu LogFont data
       IF hf THEN hf = SelectObject(hDC, hf)   ' select it in DC
    END IF

    GetTextExtentPoint32 hDC, BYVAL STRPTR(txt), LEN(txt), sl ' get text size

    @lpMis.itemWidth  = sl.cx                                 ' set width
    @lpMis.ItemHeight = GetSystemMetrics(%SM_CYMENU) + 1      ' set height

    IF hf THEN DeleteObject SelectObject(hDC, hf)  ' delete our tmp menu font object

  ReleaseDC hWnd, hDC                              ' release DC to avoid memory leak

END SUB

'------------------------------------------------------------------------------
' Sub Routine : AddMenu ()
'
' Description : Add a menu to given Window or Dialog.
'------------------------------------------------------------------------------ 
SUB AddMenu (BYVAL hWnd AS DWORD)

  local BmpNum AS LONG
  
  '----------------------------------------------------------------------------
  ' Create The Main New Application Menu Bar.
  '----------------------------------------------------------------------------
  MENU NEW BAR TO ghMnu
  
  '----------------------------------------------------------------------------
  ' Add A File Menu And Popup Menu.
  '----------------------------------------------------------------------------
  MENU NEW POPUP TO ghMnuFile
    MENU ADD POPUP, ghMnu, GetMenuTxtAndBmp(%IDM_FILE, BmpNum), ghMnuFile, %MF_ENABLED
    MENU ADD STRING, ghMnuFile, GetMenuTxtAndBmp(%IDM_NEW, BmpNum),    %IDM_NEW,    %MF_ENABLED
    MENU ADD STRING, ghMnuFile, GetMenuTxtAndBmp(%IDM_OPEN, BmpNum),   %IDM_OPEN,   %MF_ENABLED
    MENU ADD STRING, ghMnuFile, "-", 0, 0
    MENU ADD STRING, ghMnuFile, GetMenuTxtAndBmp(%IDM_SAVE, BmpNum),   %IDM_SAVE,   %MF_ENABLED
    MENU ADD STRING, ghMnuFile, GetMenuTxtAndBmp(%IDM_SAVEAS, BmpNum), %IDM_SAVEAS, %MF_ENABLED
    MENU ADD STRING, ghMnuFile, "-", 0, 0
    MENU ADD STRING, ghMnuFile, GetMenuTxtAndBmp(%IDM_EXIT, BmpNum),   %IDM_EXIT,   %MF_ENABLED
  
  '----------------------------------------------------------------------------
  ' Add An Edit Menu And Popup Menu.
  '----------------------------------------------------------------------------
  MENU NEW POPUP TO ghMnuEdit
    MENU ADD POPUP, ghMnu, GetMenuTxtAndBmp(%IDM_EDIT, BmpNum), ghMnuEdit, %MF_ENABLED
    MENU ADD STRING, ghMnuEdit, GetMenuTxtAndBmp(%IDM_UNDO, BmpNum),   %IDM_UNDO,   %MF_ENABLED
    MENU ADD STRING, ghMnuEdit, "-", 0, 0
    MENU ADD STRING, ghMnuEdit, GetMenuTxtAndBmp(%IDM_CUT, BmpNum),    %IDM_CUT,    %MF_ENABLED
    MENU ADD STRING, ghMnuEdit, GetMenuTxtAndBmp(%IDM_COPY, BmpNum),   %IDM_COPY,   %MF_ENABLED
    MENU ADD STRING, ghMnuEdit, GetMenuTxtAndBmp(%IDM_PASTE, BmpNum),  %IDM_PASTE,  %MF_ENABLED
    MENU ADD STRING, ghMnuEdit, "-", 0, 0
    MENU ADD STRING, ghMnuEdit, GetMenuTxtAndBmp(%IDM_SELALL, BmpNum), %IDM_SELALL, %MF_ENABLED
  
  '----------------------------------------------------------------------------
  ' Add An Help Menu And Popup Menu.
  '----------------------------------------------------------------------------
  MENU NEW POPUP TO ghMnuHelp
    MENU ADD POPUP, ghMnu, GetMenuTxtAndBmp(%IDM_HELP, BmpNum), ghMnuHelp, %MF_ENABLED
    MENU ADD STRING, ghMnuHelp, GetMenuTxtAndBmp(%IDM_HELPCONT, BmpNum),   %IDM_HELP,   %MF_ENABLED
    MENU ADD STRING, ghMnuHelp, "-", 0, 0
    MENU ADD STRING, ghMnuHelp, GetMenuTxtAndBmp(%IDM_ABOUT, BmpNum),   %IDM_ABOUT,   %MF_ENABLED
    
  MENU ATTACH ghMnu, hWnd
 
  '----------------------------------------------------------------------------
  ' Make all menu items ownerdrawn.
  '----------------------------------------------------------------------------
  ' FILE MENU.
'  ModifyMenuA ghMnuFile, %IDM_NEW,    %MF_OWNERDRAW, %IDM_NEW,    BYVAL %NULL
'  ModifyMenu ghMnuFile, %IDM_OPEN,   %MF_OWNERDRAW, %IDM_OPEN,   BYVAL %NULL
'  ModifyMenu ghMnuFile, %IDM_SAVE,   %MF_OWNERDRAW, %IDM_SAVE,   BYVAL %NULL
'  ModifyMenu ghMnuFile, %IDM_SAVEAS, %MF_OWNERDRAW, %IDM_SAVEAS, BYVAL %NULL
'  ModifyMenu ghMnuFile, %IDM_EXIT,   %MF_OWNERDRAW, %IDM_EXIT,   BYVAL %NULL
'  
'  ' EDIT MENU.
'  ModifyMenu ghMnuEdit, %IDM_UNDO,   %MF_OWNERDRAW, %IDM_UNDO,   BYVAL %NULL
'  ModifyMenu ghMnuEdit, %IDM_CUT,    %MF_OWNERDRAW, %IDM_CUT,    BYVAL %NULL
'  ModifyMenu ghMnuEdit, %IDM_COPY,   %MF_OWNERDRAW, %IDM_COPY,   BYVAL %NULL
'  ModifyMenu ghMnuEdit, %IDM_PASTE,  %MF_OWNERDRAW, %IDM_PASTE,  BYVAL %NULL
'  ModifyMenu ghMnuEdit, %IDM_SELALL, %MF_OWNERDRAW, %IDM_SELALL, BYVAL %NULL
'  
'  ' HELP MENU.
'  ModifyMenu ghMnuHelp, %IDM_HELPCONT, %MF_OWNERDRAW, %IDM_HELP, BYVAL %NULL
'  
END SUB

'------------------------------------------------------------------------------
' End Of MENU.INC
'------------------------------------------------------------------------------
 