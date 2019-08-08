'-----------------------------------------
sub CanvasKeys(byval hndl as long) as long
'=========================================
       '
 if pt.x+pt.y>0 then
   navf=1
   win_setFocus hnav 'hctrl1 'hdlg
   GetAsyncKeyState (-1)
   ke(%VK_CONTROL)=GetAsyncKeyState (%VK_CONTROL)
   ke(%VK_SHIFT)=GetAsyncKeyState (%VK_SHIFT)
   ke(%VK_ESCAPE)=GetAsyncKeyState (%VK_ESCAPE)
   ke(%VK_LEFT)=GetAsyncKeyState (%VK_LEFT)
   ke(%VK_RIGHT)=GetAsyncKeyState (%VK_RIGHT)
   ke(%VK_UP)=GetAsyncKeyState (%VK_UP)
   ke(%VK_DOWN)=GetAsyncKeyState (%VK_DOWN)
   ke(%VK_HOME)=GetAsyncKeyState (%VK_HOME)
   ke(%VK_END)=GetAsyncKeyState (%VK_END)
   ke(%VK_PGUP)=GetAsyncKeyState (%VK_PGUP)
   ke(%VK_PGDN)=GetAsyncKeyState (%VK_PGDN)
   '
   'if ke(%VK_ESCAPE) then
   '  DIALOG End hndl
   'end if
 else
  navf=0
 end if

end sub

'---------------------
sub KeyboardControls()
'=====================

  if navf then
  'if pt.x+pt.y>0 then

    '
    if ke(%VK_SHIFT) then
      if ke(%VK_LEFT)  then pdx-=1 : ppdx=pdx : updatem=1
      if ke(%VK_RIGHT) then pdx+=1 : ppdx=pdx : updatem=1
      if ke(%VK_UP)    then pdy+=1 : ppdy=pdy : updatem=1
      if ke(%VK_DOWN)  then pdy-=1 : ppdy=pdy : updatem=1
      if ke(%VK_HOME)  then
        pdx=0 : ppdx=pdx
        pdy=0 : ppdy=pdy
        updatem=1
      end if
    elseif ke(%VK_CONTROL) then
      if ke(%VK_LEFT)  then pdx-=1 : ppdx=pdx : updatem=1
      if ke(%VK_RIGHT) then pdx+=1 : ppdx=pdx : updatem=1
      if ke(%VK_UP)    then pdz+=1 : ppdz=pdz : updatem=1
      if ke(%VK_DOWN)  then pdz-=1 : ppdz=pdz : updatem=1
      if ke(%VK_HOME)  then
        pdx=0 : ppdx=pdx
        pdz=0 : ppdz=pdz
        updatem=1
      end if
    else 
      if ke(%VK_LEFT)  then pax-=1 : ppax=pax : updatem=1
      if ke(%VK_RIGHT) then pax+=1 : ppax=pax : updatem=1
      if ke(%VK_UP)    then pay-=1 : ppay=pay : updatem=1
      if ke(%VK_DOWN)  then pay+=1 : ppay=pay : updatem=1
      if ke(%VK_HOME)  then
        yspinv=0
        pax=0 : ppax=pax
        pay=0 : ppay=pay
        paz=0 : ppaz=paz
        updatem=1
    end if
    end if

  end if
end sub



'------------------------------------
callback function cbNavigate() as long
'====================================
  if CBMSG = %WM_COMMAND then
    if cbctlmsg = %BN_CLICKED then
      navf=1
      updatem=2
    end if
  end if
end function


'------------------
sub MouseCoords()
'==================

  'win_getcursorpos pt 'pt.x pt.y screen pos
  pt.x=TBGL_MouseGetPosX : pt.y=TBGL_MouseGetPosY
  if pf then Control_Settext(hDlg, %sts_box,str$(pt.x)+$tab+str$(pt.y))
end sub

%EM_GETSEL = &h000000b0


'---------------------
sub displayCharIndex()
'=====================

  static chindex,lindex as long
  SendMessage tbox,%EM_GETSEL,varptr(chindex),varptr(lindex)
  Control_Settext(hDlg, %sts_box2,str$(chindex)+$tab+str$(lindex) )
end sub


'----------------------------------
' Callback function for main window
'==================================

callback function DlgProc() as long

   dim s as long


   select case cbmsg
     
     case %WM_CREATE

       
     case %WM_DESTROY

       if TBGL_CanvasBound(hCtrl) then TBGL_ReleaseCanvas(hCtrl)
       dialog Kill Timer cbhndl, %IDC_TIMER
       
            

     case %WM_TIMER

       '---Dynamically call a function whose name is composed at run-time
       '---In this case function name to be executed is inside TBGL_TestFunction string variable

       hctrl=hctrl1
       if updatem=0 then updatem=yspinf
       CanvasKeys(cbHndl)
       call TBGL_TestFunction
       'displayCharIndex

     case %WM_INITDIALOG

       dialog Set Timer cbhndl, %IDC_TIMER, %TIMER_DELAY
       
     case %WM_SIZE

       'updatem=1
       TBGL_UpdateCanvasProportions(hCtrl)
       call TBGL_TestFunction 
       
     case %WM_SIZING    
   
       hctrl=hctrl1
       TBGL_UpdateCanvasProportions(hCtrl )
       TBGL_UpdateCanvasProportions(hCtrl2)
       updatem=1
       call TBGL_TestFunction
       'displayCharIndex

     case %WM_LBUTTONUP
 
       pf=0
       if mtrack then
         ppax=pax : ppay=pay : ppaz=paz
         ppdx=pdx : ppdy=pdy : ppdz=pdz
       end if
       
     case %WM_LBUTTONDOWN

       pf=1 : pr=pt : MouseCoords ': displayCharIndex
       
     case %WM_MOUSEMOVE

       if mtrack then
         if pf=1 then
            pax=ppax+pt.x-pr.x
            pay=ppay+pt.y-pr.y
         elseif pf=2 then
            pdz=ppdz+pr.y-pt.y
            pdx=ppdx+pt.x-pr.x
          end if
        end if

        MouseCoords
       
     case %WM_RBUTTONDOWN

       pf=2 : pr=pt : MouseCoords
         
     case %WM_RBUTTONUP

       pf=0
       if mtrack then
         ppax=pax : ppay=pay : ppaz=paz
         ppdx=pdx : ppdy=pdy : ppdz=pdz
       end if
               
              
  END SELECT
      
end function



'------------------------------------
callback function cbDlg2new() as long
'====================================

  if CBMSG = %WM_COMMAND then
    if (cbctlmsg = %BN_CLICKED) then
      if hdlg2=0 then main2 : otrack=mtrack : mtrack=0
    end if
  end if
end function



'------------------------------------
callback function cbDlg2zap() as long
'====================================

  if CBMSG = %WM_COMMAND then
    if (cbctlmsg = %BN_CLICKED) then
      if hdlg2 then
        dialog kill Timer hdlg2, %IDC_TIMER
        dialog end hdlg2 : hdlg2=0 : updatem=1 : mtrack=otrack
      end if
    end if
  end if
end function


'---------------------------------
callback function cbTbox() as long
'=================================
  if CBMSG = %WM_COMMAND then
    if cbctlmsg = %WM_CHAR then
      'function=%true
    end if
  end if
end function


'--------------------------------------
callback function CloseButton() as long
'======================================

  if CBMSG = %WM_COMMAND then
    if cbctlmsg = %BN_CLICKED then DIALOG End cbhndl
  end if  

end function



'---------------------------------------
callback function CanvasButton() as long
'=======================================
  
  if CBMSG = %WM_COMMAND then
    if cbctlmsg = %BN_CLICKED then 
      select case cbctl
        case %btnCanvasOn
          TBGL_TestFunction = "Render_01"
          CONTROL disable cbhndl, %btnCanvasOn
          TBGL_BindCanvas(hCtrl)           

          CONTROL enable cbhndl, %btnCanvasOff, %btn_test02, %btn_test03 
          
        case %btnCanvasOff  
          CONTROL disable cbhndl, %btnCanvasOff

          TBGL_ReleaseCanvas(hCtrl)        

          CONTROL disable cbhndl, %btn_test01, %btn_test02, %btn_test03 

          CONTROL enable cbhndl, %btnCanvasOn          
          
      end select
    end if
  end if
  
end function



'---------------------------------------
callback function cbChangeTest() as long
'=======================================
  '
  'CHANGE OBJECT ON DISPLAY
  '
  if CBMSG = %WM_COMMAND then
    if cbctlmsg = %BN_CLICKED then
      yspinvv(cid)=yspinv
      select case cbctl
        case %btn_test01
          cid=1         
          CONTROL disable cbhndl, %btn_test01 
          CONTROL enable cbhndl, %btn_test02, %btn_test03

          TBGL_TestFunction = "Render_01"
          TBGL_ReleaseCanvas(hCtrl)
          TBGL_BindCanvas(hCtrl)
          mtrack=1           
        case %btn_test02
          cid=2
          CONTROL disable cbhndl, %btn_test02 
          CONTROL enable cbhndl, %btn_test01, %btn_test03

          TBGL_TestFunction = "Render_02"
          TBGL_ReleaseCanvas(hCtrl)
          TBGL_BindCanvas(hCtrl)           
          mtrack=0
        case %btn_test03
          cid=3
          CONTROL disable cbhndl, %btn_test03
          CONTROL enable cbhndl, %btn_test01, %btn_test02

          TBGL_TestFunction = "Render_03"
          TBGL_ReleaseCanvas(hCtrl)
          TBGL_BindCanvas(hCtrl)
          mtrack=0          
      end select
      updatem=2
      yspinv=yspinvv(cid)    
    end if
  end if
  
end function



'-------------------------------------
callback function cbColorpik() as long
'=====================================
    '
    'FORGROUND COLOR PICKER
    '
    dim c as long
    if CBMSG = %WM_COMMAND then
      if cbctlmsg = %BN_CLICKED then 
       c = Dialog_ChooseColor(hDlg, rgb(fr,fg,fb), %CC_RGBINIT OR %CC_FULLOPEN )
       if c<>-1 then
         lcolor=c
         fr =lcolor and 255 : fg=lcolor : fb=lcolor
         shift right fg, 8 : fg = fg and 255
         shift right fb, 16 : fb = fb and 255
         updatem=2
       end if
      end if
    end if

end function



'--------------------------------------
callback function cbColorpikB() as long
'======================================
    '
    'BACKGROUND COLOR PICKER
    '
    dim c as long
    if CBMSG = %WM_COMMAND then
      if cbctlmsg = %BN_CLICKED then 
       c = Dialog_ChooseColor(hDlg, rgb(br,bg,bb), %CC_RGBINIT OR %CC_FULLOPEN )
       if c<>-1 then
         lcolor=c
         br =lcolor and 255 : bg=lcolor : bb=lcolor
         shift right bg, 8 : bg = bg and 255
         shift right bb, 16 : bb = bb and 255
         updatem=2
       end if
      end if
    end if
end function


'-------------------------------------------------
' Callback function to read in script from textbox
'=================================================

callback function cbReado() as long
    dim s as string
    if CBMSG = %WM_COMMAND then
      if cbctlmsg = %BN_CLICKED then 
        s="' Enter new values literally"+$crlf+_
          "' or as Expressions"+$crlf+_
          "' then click EXEC"+$crlf+_
          "' COLORS"+$crlf+_
          "    fr ="+$tab+str$(fr)+$crlf+_
          "    fg ="+$tab+str$(fg)+$crlf+_
          "    fb ="+$tab+str$(fb)+$crlf+_
          "    br ="+$tab+str$(br)+$crlf+_
          "    bg ="+$tab+str$(bg)+$crlf+_
          "    bb ="+$tab+str$(bb)+$crlf+_
          "' GEOMETRY:"+$crlf+_
          "    nsym = "+$tab+str$(nsym)+$crlf+_
          "    top = "+$tab+str$(tp)+$crlf+_
          "' FRAME MEMBERS:"+$crlf+_
          "    width = "+$tab+str$(swi)+$crlf+_
          "    thickness = "+$tab+str$(sth)+$crlf+_
          "' TUBING:"+$crlf+_
          "    diameter = "+$tab+str$(diam)+$crlf+_
          $crlf
          Control_Settext(hDlg, %txt_box,s)
       
      end if
    end if
end function


'---------------------------------------------------
' Callback function to compile and execute o2 script
'===================================================

callback function cbExeco() as long
    dim src as string
    if CBMSG = %WM_COMMAND then
      if cbctlmsg = %BN_CLICKED then 
        '
        src="
         basic

         dim as long
         fr at #fr,
         fg at #fg,
         fb at #fb,
         br at #br,
         bg at #bg,
         bb at #bb,
         nsym  at #nsym

         dim as double
         top at #tp,
         width at #swi,
         thickness at #sth,
         diameter at #diam
        "
        src+=Control_Gettext(hDlg, %txt_box)
        o2_basic src
        o2_exec
        updatem=2
      end if
    end if
end function

