



'------------------------------------------------------------
' Second Dialog Main function
'------------------------------------------------------------
function Main2() as long
  
  dim hctrl01 as long
  dim t as string
  
  DIALOG New  hdlg, "dialog2", 200, 0, 400, 200, _
    %WS_POPUP Or %WS_VISIBLE Or _
    %WS_CLIPCHILDREN Or %ws_clipsiblings or %WS_CAPTION OR _
    %WS_SYSMENU Or %WS_MINIMIZEBOX or %WS_THICKFRAME, 0 To hDlg2    

   t="label2"
   hCtrl2 = CONTROL ADD label, hDlg2, %gCanvas2, t, 100,  5, 200, 100
  control set color hDlg2, %gCanvas2, %YELLOW, %BLACK    

  
  ' -- Set anchors 
  '...
  

  updatem=2

  'dialog set minsize hDlg2, 400, 300

       DIALOG SHOW MODELESS hDlg2 , call DlgProc2 ' MODAL / MODELESS possible

End Function




'------------------------------------------------------------
' Callback function for dialog2 window
'------------------------------------------------------------
callback function DlgProc2() as long

  dlg2f=1

  select case cbmsg

    case %WM_LBUTTONDOWN


    case %WM_MOVE

      updatem=1

    case %WM_SIZE

      updatem=1

    case %WM_DESTROY

      dialog kill Timer cbhndl, %IDC_TIMER
      updatem=1 : mtrack=otrack : hdlg2=0
    

    case %WM_TIMER

    case 0

       TBGL_ReleaseCanvas(hctrl1)
       TBGL_ReleaseCanvas(hctrl2)
       TBGL_BindCanvas(hctrl2)
       call render_02
       TBGL_BindCanvas(hCtrl1)

    case %WM_INITDIALOG

       dialog Set Timer cbhndl, %IDC_TIMER, %TIMER_DELAY


                                  
  end select

  dlg2f=0
      
end function

