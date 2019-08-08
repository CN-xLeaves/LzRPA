
'THE 3X3 KEYPAD


'------------
sub Pad3x3()
'============

  'CREATE KEYPAD BUTTONS

  CONTROL ADD BUTTON, hDlg, %ctrl01         , "Lines"              , 005, 033, 033, 33,,, call cbPadKey1
  CONTROL ADD BUTTON, hDlg, %ctrl02         , "Panels"             , 038, 033, 033, 33,,, call cbPadKey2
  CONTROL ADD BUTTON, hDlg, %ctrl03         , "Tubes"              , 071, 033, 033, 33,,, call cbPadKey3

  CONTROL ADD BUTTON, hDlg, %ctrl04         , "Sticks"             , 005, 066, 033, 33,,, call cbPadKey4

  CONTROL ADD BUTTON, hDlg, %ctrl05         , ""             , 038, 066, 033, 33,,, call cbPadKey5
  CONTROL ADD BUTTON, hDlg, %ctrl06         , ""             , 071, 066, 033, 33,,, call cbPadKey6

  CONTROL ADD BUTTON, hDlg, %ctrl07         , ""             , 005, 099, 033, 33,,, call cbPadKey7
  CONTROL ADD BUTTON, hDlg, %ctrl08         , ""             , 038, 099, 033, 33,,, call cbPadKey8
  CONTROL ADD BUTTON, hDlg, %ctrl09         , "Spin"         , 071, 099, 033, 33,,, call cbPadKey9

  'SET ANCHORS

  CONTROL Set RESIZE hDlg, %ctrl01        , 1, 0, 1, 0
  CONTROL Set RESIZE hDlg, %ctrl02        , 1, 0, 1, 0
  CONTROL Set RESIZE hDlg, %ctrl03        , 1, 0, 1, 0
  CONTROL Set RESIZE hDlg, %ctrl04        , 1, 0, 1, 0
  CONTROL Set RESIZE hDlg, %ctrl05        , 1, 0, 1, 0
  CONTROL Set RESIZE hDlg, %ctrl06        , 1, 0, 1, 0
  CONTROL Set RESIZE hDlg, %ctrl07        , 1, 0, 1, 0
  CONTROL Set RESIZE hDlg, %ctrl08        , 1, 0, 1, 0
  CONTROL Set RESIZE hDlg, %ctrl09        , 1, 0, 1, 0
 
end sub

'------------------------------------
callback function cbP3x3new() as long
'====================================

  if CBMSG = %WM_COMMAND then
    if (cbctlmsg = %BN_CLICKED)and(p3x3Flag=0) then
      Pad3x3()
      p3x3Flag=1
    end if
  end if
end function



'------------------------------------
callback function cbP3x3zap() as long
'====================================

  if CBMSG = %WM_COMMAND then
    if cbctlmsg = %BN_CLICKED then
      
      control kill hDlg,   %ctrl01
      control kill hDlg,   %ctrl02
      control kill hDlg,   %ctrl03
      control kill hDlg,   %ctrl04
      control kill hDlg,   %ctrl05
      control kill hDlg,   %ctrl06
      control kill hDlg,   %ctrl07
      control kill hDlg,   %ctrl08
      control kill hDlg,   %ctrl09
      p3x3Flag=0
    end if
  end if
end function



'------------------------------------
callback function cbPadKey1() as long
'====================================
  if CBMSG = %WM_COMMAND then
    if cbctlmsg = %BN_CLICKED then     
      lines=1-lines : updatem=2
    end if
  end if
end function

'------------------------------------
callback function cbPadKey2() as long
'====================================
  if CBMSG = %WM_COMMAND then
    if cbctlmsg = %BN_CLICKED then
      panels=1-panels : updatem=2
    end if
  end if
end function

'------------------------------------
callback function cbPadKey3() as long
'====================================
  if CBMSG = %WM_COMMAND then
    if cbctlmsg = %BN_CLICKED then
      tubes=1-tubes : updatem=2
    end if
  end if
end function

'------------------------------------
callback function cbPadKey4() as long
'====================================
  if CBMSG = %WM_COMMAND then
    if cbctlmsg = %BN_CLICKED then
      sticks=1-sticks : updatem=2
    end if
  end if
end function

'------------------------------------
callback function cbPadKey5() as long
'====================================
  if CBMSG = %WM_COMMAND then
    if cbctlmsg = %BN_CLICKED then
      
    end if
  end if
end function

'------------------------------------
callback function cbPadKey6() as long
'====================================
  if CBMSG = %WM_COMMAND then
    if cbctlmsg = %BN_CLICKED then
      
    end if
  end if
end function

'------------------------------------
callback function cbPadKey7() as long
'====================================
  if CBMSG = %WM_COMMAND then
    if cbctlmsg = %BN_CLICKED then
      
    end if
  end if
end function

'------------------------------------
callback function cbPadKey8() as long
'====================================
  if CBMSG = %WM_COMMAND then
    if cbctlmsg = %BN_CLICKED then
      
    end if
  end if
end function

'------------------------------------
callback function cbPadKey9() as long
'====================================
  if CBMSG = %WM_COMMAND then
    if cbctlmsg = %BN_CLICKED then
      yspinf=1-yspinf 
    end if
  end if
end function








