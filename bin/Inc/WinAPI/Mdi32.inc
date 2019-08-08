'------------------------------------------------------------------------------
'
'  MDI32.INC -- Multiple Document Interface (MDI) Encapsulation for PowerBASIC
'
'  Copyright (c) 1997-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corp.
'  All Rights Reserved.
'
'  Last Update: 17 Mar 2011
'
'------------------------------------------------------------------------------



#INCLUDE THIS ONCE

%MDI32_INC = 1


#INCLUDE "WinUser.inc"
#INCLUDE "WinBase.inc"


FUNCTION MdiGetActive (BYVAL hClient AS DWORD) AS DWORD

    FUNCTION = SendMessage(hClient, %WM_MDIGETACTIVE, 0, 0)

END FUNCTION



FUNCTION MdiGetActiveMax (BYVAL hClient AS DWORD, BYVAL lpMaximized AS LONG) AS DWORD

    FUNCTION = SendMessage(hClient, %WM_MDIGETACTIVE, 0, lpMaximized)

END FUNCTION



FUNCTION MdiCascade (BYVAL hClient AS DWORD) AS LONG

    FUNCTION = SendMessage(hClient, %WM_MDICASCADE, 0, 0)

END FUNCTION



FUNCTION MdiTile (BYVAL hClient AS DWORD, BYVAL How AS LONG) AS LONG

    IF How = 0 THEN
        How = %MDITILE_VERTICAL
    END IF

    FUNCTION = SendMessage(hClient, %WM_MDITILE, How, 0)

END FUNCTION



SUB MdiIconArrange (BYVAL hClient AS DWORD)

    SendMessage hClient, %WM_MDIICONARRANGE, 0, 0

END SUB



FUNCTION MdiActivate (BYVAL hClient AS DWORD, BYVAL hWnd AS DWORD) AS LONG

    FUNCTION = SendMessage(hClient, %WM_MDIACTIVATE, hWnd, 0)

END FUNCTION



FUNCTION MdiDestroy (BYVAL hClient AS DWORD, BYVAL hWnd AS DWORD) AS LONG

    ' The return value should always be zero.
    FUNCTION = SendMessage(hClient, %WM_MDIDESTROY, hWnd, 0)

END FUNCTION



FUNCTION MdiMaximize (BYVAL hClient AS DWORD, BYVAL hWnd AS DWORD) AS LONG

    ' The return value should always be zero.
    FUNCTION = SendMessage(hClient, %WM_MDIMAXIMIZE, hWnd, 0)

END FUNCTION



FUNCTION MdiNext (BYVAL hClient AS DWORD, BYVAL hWnd AS DWORD, _
    BYVAL fNext AS LONG) AS LONG

    ' The return value should always be zero.
    FUNCTION = SendMessage(hClient, %WM_MDINEXT, hWnd, fNext)

END FUNCTION



FUNCTION MdiRestore (BYVAL hClient AS DWORD, BYVAL hWnd AS DWORD) AS LONG

    ' The return value should always be zero.
    FUNCTION = SendMessage(hClient, %WM_MDIRESTORE, hWnd, 0)

END FUNCTION



FUNCTION CreateMdiChild (BYVAL sWndClass AS STRING, BYVAL hClient AS DWORD, _
    BYVAL sTitle AS STRING, BYVAL dStyle AS DWORD) AS DWORD

    LOCAL lResult AS LONG
    LOCAL mdi     AS MDICREATESTRUCT

    IF IsZoomed(MdiGetActive(hClient)) THEN
        dStyle OR= %WS_MAXIMIZE
    END IF

    IF LOBYT(GetVersion) < 4 THEN
        mdi.szClass = STRPTR(sWndClass)
        mdi.szTitle = STRPTR(sTitle)
        mdi.hOwner  = GetWindowLong(hClient, %GWL_HINSTANCE)
        mdi.x       = %CW_USEDEFAULT
        mdi.y       = %CW_USEDEFAULT
        mdi.cx      = %CW_USEDEFAULT
        mdi.cy      = %CW_USEDEFAULT
        mdi.Style   = dStyle
        lResult     = SendMessage(hClient, %WM_MDICREATE, 0, VARPTR(mdi))
    ELSE
        lResult = CreateWindowEx(%WS_EX_MDICHILD OR %WS_EX_CLIENTEDGE, _
                                  BYCOPY sWndClass, _
                                  BYCOPY sTitle, _
                                  dStyle, _
                                  %CW_USEDEFAULT, _
                                  %CW_USEDEFAULT, _
                                  %CW_USEDEFAULT, _
                                  %CW_USEDEFAULT, _
                                  hClient, _
                                  %NULL, _
                                  GetWindowLong(hClient, %GWL_HINSTANCE), _
                                  BYVAL %NULL)
    END IF

    mdi.szClass = STRPTR(sWndClass)
    mdi.szTitle = STRPTR(sTitle)
    mdi.hOwner  = GetWindowLong(hClient, %GWL_HINSTANCE)
    mdi.x       = %CW_USEDEFAULT
    mdi.y       = %CW_USEDEFAULT
    mdi.cx      = %CW_USEDEFAULT
    mdi.cy      = %CW_USEDEFAULT
    mdi.Style   = dStyle

    FUNCTION = CDWD(lResult)

END FUNCTION
