
'--------------
' Main function
'==============

function TBMAIN() as long
  
  dim hctrl01 as long
  dim t as string
  

  '------------------
  'MAIN DIALOG WINDOW
  '==================


  DIALOG New  0, "UI TBGL OXYGEN", 100, 100, 625, 390, _
         %WS_POPUP Or %WS_VISIBLE Or _
         %WS_CLIPCHILDREN Or %ws_clipsiblings or %WS_CAPTION OR _
         %WS_SYSMENU Or %WS_MINIMIZEBOX or %WS_THICKFRAME, 0 To hDlg    

  'hCtrl1 = CONTROL ADD CANVAS, hDlg, %gCanvas, "", 110,  5, 510, 380
  hCtrl1 = CONTROL ADD LABEL, hDlg, %gCanvas, "", 110,  5, 510, 380

  'control set color hDlg, %gCanvas, %YELLOW, %BLACK     
  'CONTROL ADD BUTTON, hDlg, %btnCanvasOn    , "On"           , 005,   5, 050, 20,,, call CanvasButton
  'CONTROL ADD BUTTON, hDlg, %btnCanvasOff   , "Off"          , 055,   5, 050, 20,,, call CanvasButton


  '---------------
  'STATUS MESSAGES
  '===============
  
  dim sst as long=%ES_MULTILINE
  CONTROL ADD LABEL, hDlg, %sts_label        , "X,Y"           , 005,  005, 50, 10
  'CONTROL ADD LABEL, hDlg, %sts_label2      , ""              , 005,  015, 50, 10
  CONTROL ADD TEXTBOX, hDlg, %sts_box        , ""              , 050, 005, 50, 10,%ES_READONLY,', 0
  'CONTROL ADD TEXTBOX, hDlg, %sts_box2      , ""              , 050, 015, 50, 10,%ES_READONLY,', 0





  '-------------------
  'CONTROL BUTTON AREA
  '===================

  Pad3x3()

  'NAVIGATION FOCUS TRAP

  CONTROL ADD BUTTON, hDlg, %Navigate        , "Navigate With Keys" , 005, 135, 100, 15,,         , call cbNavigate
  hnav=_
  CONTROL ADD TEXTBOX, hDlg, %NavTrap        , ""                   , 090, 135,   1, 5 ,%ES_READONLY,, call cbNavigate


  CONTROL ADD BUTTON, hDlg, %btn_test01     , "Construction 1"     , 005, 150, 100, 15,,, call cbChangeTest
  CONTROL ADD BUTTON, hDlg, %btn_test02     , "Construction 2"     , 005, 165, 100, 15,,, call cbChangeTest
  CONTROL ADD BUTTON, hDlg, %btn_test03     , "Construction 3"     , 005, 180, 100, 15,,, call cbChangeTest
 
  CONTROL ADD BUTTON,  hDlg, %btn_colorpik  , "Forgnd color  "     , 005, 195, 050, 15,,, call cbColorpik
  CONTROL ADD BUTTON,  hDlg, %btn_colorpikB , "Backgn color  "     , 055, 195, 050, 15,,, call cbColorpikB

  CONTROL ADD BUTTON,  hDlg, %btn_p3x3zap  , "del keypad  "        , 005, 210, 050, 15,,, call cbP3x3zap
  CONTROL ADD BUTTON,  hDlg, %btn_p3x3new  , "new keypad  "        , 055, 210, 050, 15,,, call cbP3x3new

  'CONTROL ADD BUTTON,  hDlg, %btn_dlg2new  , "new dialog2"         , 005, 225, 050, 15,,, call cbDlg2new
  'CONTROL ADD BUTTON,  hDlg, %btn_dlg2zap  , "del dialog2"         , 055, 225, 050, 15,,, call cbDlg2zap


  '------------
  'PROG CONTROL
  '============

  CONTROL ADD BUTTON,  hDlg, %btn_read      , "Load Metrics"       , 005, 240, 050, 15,,, call cbReado
  CONTROL ADD BUTTON,  hDlg, %btn_exec      , "Exec"               , 055, 240, 050, 15,,, call cbExeco



  dim est as long=%ES_MULTILINE or %ES_WANTRETURN or %WS_HSCROLL or %WS_VSCROLL
  'dim est as long=%WS_CHILD Or %WS_VISIBLE Or %ES_MULTILINE Or %ES_WANTRETURN Or %ES_LEFT Or %WS_TABSTOP, %WS_EX_CLIENTEDGE


  '-----------------
  'OXYGEN SCRIPT BOX 
  '=================

  tbox=_
  CONTROL ADD TEXTBOX, hDlg, %txt_box       , ""                    , 005, 260, 100,140,est,,call cbTBox

  '--------
  'SHUTDOWN
  '========

  'CONTROL ADD BUTTON, hDlg, %btnClose     , "Click to close"       , 005, 370, 100, 15,,, call CloseButton
  
  


  
'  '----------------
'  'SET MAIN ANCHORS
'  '================
'
'  controls that are located in the upper left do not need anchor control here.
'
'  CONTROL Set RESIZE hDlg, %btnClose       , 1, 0, 1, 0
'  'CONTROL Set RESIZE hDlg, %btnCanvasOn   , 1, 0, 1, 0
'  'CONTROL Set RESIZE hDlg, %btnCanvasOff  , 1, 0, 1, 0 
'
   CONTROL Set RESIZE hDlg, %gCanvas       , 1, 1, 1, 1
'
'
'  CONTROL Set RESIZE hDlg, %sts_box       , 1, 0, 1, 0 
'  CONTROL Set RESIZE hDlg, %sts_box2      , 1, 0, 1, 0 
'
'   
'  CONTROL Set RESIZE hDlg, %btn_test01    , 1, 0, 1, 0 
'  CONTROL Set RESIZE hDlg, %btn_test02    , 1, 0, 1, 0 
'  CONTROL Set RESIZE hDlg, %btn_test03    , 1, 0, 1, 0
'  
'  CONTROL Set RESIZE hDlg, %btn_colorpik  , 1, 0, 1, 0 
'  CONTROL Set RESIZE hDlg, %btn_colorpikB , 1, 0, 1, 0
'
'  CONTROL Set RESIZE hDlg, %btn_read      , 1, 0, 1, 0 
'  CONTROL Set RESIZE hDlg, %btn_exec      , 1, 0, 1, 0 
   CONTROL Set RESIZE hDlg, %txt_box       , 1, 0, 1, 0
'
'  CONTROL SET RESIZE hDlg, %btn_p3x3new   , 1, 0, 1, 0 
'  CONTROL SET RESIZE hDlg, %btn_p3x3zap   , 1, 0, 1, 0
'   
'  CONTROL SET RESIZE hDlg, %btn_dlg2new   , 1, 0, 1, 0 
'  CONTROL SET RESIZE hDlg, %btn_dlg2zap   , 1, 0, 1, 0 
  



  updatem=2 'FULL UPDATE INCLUDING MODEL BUILDING

  CONTROL disable hDlg, %btn_test01 'SELECTED TEST

  dialog set minsize hDlg, 400, 300

  cid=1     '1st construction
  TBGL_TestFunction = "Render_01" : mtrack=1
  TBGL_BindCanvas(hCtrl1)
  hCtrl=hCtrl1
  DIALOG SHOW MODAL hDlg, call DlgProc

  '
End Function

