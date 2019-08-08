
'---------------
'CURSOR POSITION
'===============

type pointxy
  x as long
  y as long
end type


global ke(256)            as long

'-------------
'LOCATION AND CONTROL
'=============

global cid,yspinf(3),yspinf   as long
global yspinvv(3),yspinv      as double

global pt,pr,pd           as pointxy
global pf                 as long

global pax,pay,paz        as long
global ppax,ppay,ppaz     as long

global pdx,pdy,pdz        as long
global ppdx,ppdy,ppdz     as long

ppdz=0

global hCtrl,hCtrl1,hCtrl2  as dword
global ExitProgram          as long 
global TBGL_TestFunction    as string

'----------------
'MODEL PARAMETERS
'================

global navf,hnav as long
global lcolor,fr,fg,fb,br,bg,bb as long
global nsym,lines,panels,tubes,sticks as long
global pfr,pfg,pfb,pbr,pbg,pbb  as long
global tp,swi,sth,sle,diam as double

'INITIAL VALUES

fr=140 : fg=140 : fb=160 'FORGROUND COLOR
br=012 : bg=052 : bb=025 'BACKGROUND COLOR

nsym=6   'SIDES OR SYMMETRIES
tp=0.15  'TOP RADIUS
lines=1  'DRAW OUTLINES
panels=0 'DRAW PANELS
tubes=0  'DRAW TUBES
sticks=0 'DRAW STICKS

swi=.1   'STICK WIDTH
sth=.022 'STICK THICKNESS
sle=1    'STICK LENGTH
diam=.04 'TUBE DIAMETER

'------
'DIALOG
'======

global hDlg      AS LONG
global Msg       AS LONG
global wParam    AS LONG
global lParam    AS LONG


'----------------------
'ID numbers of controls
'======================

Begin Const
  %btnClose     = 1000
  %btnCanvasOn  
  %btnCanvasOff

  %ctrl01
  %ctrl02
  %ctrl03
  %ctrl04
  %ctrl05
  %ctrl06
  %ctrl07
  %ctrl08
  %ctrl09

  %btn_test01
  %btn_test02
  %btn_test03
  %btn_ColorPik
  %btn_colorPikB
  %btn_p3x3zap
  %btn_p3x3new
  %btn_dlg2new
  %btn_dlg2zap
  %btn_read
  %btn_exec
  %sts_label
  %sts_label2
  %sts_box
  %sts_box2
  %txt_box
    
  %gCanvas  
  %gCanvas2

  %navigate 
  %navtrap 

  %IDC_TIMER      = 100
  %TIMER_DELAY    = 1     ' Timer delay (in milliseconds, not very accurate below about 100)
End Const

dim p3x3Flag as long=1
dim hdlg2 as long
dim tbox as long
dim updatem,dlg2f,mtrack,otrack as long

