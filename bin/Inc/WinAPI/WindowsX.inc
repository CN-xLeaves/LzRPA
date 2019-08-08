'------------------------------------------------------------------------------
'
'  WindowsX.inc -- Macro APIs, window message crackers, and control APIs
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 03 May 2011
'
'------------------------------------------------------------------------------
'  from WindowsX.h of 14 Jul 2009
'------------------------------------------------------------------------------

%INC_WINDOWSX = 1

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "WinUser.inc"

'***** KERNEL Macro APIs *****************************************************

MACRO GetInstanceModule(hInstance)=hInstance

MACRO GlobalPtrHandle(lp)=GlobalHandle(lp)

MACRO GlobalLockPtr(lp)=GlobalLock(GlobalPtrHandle(lp))

MACRO GlobalUnlockPtr(lp)=GlobalUnlock(GlobalPtrHandle(lp))

#IF NOT %DEF(%MAC)
MACRO GlobalAllocPtr(flags, cb)=GlobalLock(GlobalAlloc(flags, cb))
#ELSE
MACRO GlobalAllocPtr(flags, cb)=GlobalLock(GlobalAlloc((flags) OR %GMEM_PMODELOCKSTRATEGY, cb))
#ENDIF

MACRO FUNCTION GlobalReAllocPtr(lp, cbNew, flags)
    GlobalUnlockPtr lp
END MACRO=GlobalLock(GlobalReAlloc(GlobalPtrHandle(lp), cbNew, flags)))

MACRO FUNCTION GlobalFreePtr(lp)
    GlobalUnlockPtr lp
END MACRO=GlobalFree(GlobalPtrHandle(lp))

'***** GDI Macro APIs ********************************************************

MACRO DeletePen(hpen)=DeleteObject(hpen)
MACRO SelectPen(hdc, hpen)=SelectObject(hdc, hpen)
MACRO GetStockPen(i)=GetStockObject(i)

MACRO DeleteBrush(hbr)=DeleteObject(hbr)
MACRO SelectBrush(hdc, hbr)=SelectObject(hdc, hbr)
MACRO GetStockBrush(i)=GetStockObject(i)

MACRO DeleteRgn(hrgn)=DeleteObject(hrgn)

#IF NOT %DEF(%MAC)
MACRO CopyRgn(hrgnDst, hrgnSrc)              = CombineRgn(hrgnDst, hrgnSrc, 0, %RGN_COPY)
#ELSE
MACRO AfxCopyRgn(hrgnDst, hrgnSrc)           = CombineRgn(hrgnDst, hrgnSrc, 0, %RGN_COPY)
#ENDIF
MACRO IntersectRgn(hrgnResult, hrgnA, hrgnB) = CombineRgn(hrgnResult, hrgnA, hrgnB, %RGN_AND)
MACRO SubtractRgn(hrgnResult, hrgnA, hrgnB)  = CombineRgn(hrgnResult, hrgnA, hrgnB, %RGN_DIFF)
#IF NOT %DEF(%MAC)
MACRO UnionRgn(hrgnResult, hrgnA, hrgnB)     = CombineRgn(hrgnResult, hrgnA, hrgnB, %RGN_OR)
MACRO XorRgn(hrgnResult, hrgnA, hrgnB)       = CombineRgn(hrgnResult, hrgnA, hrgnB, %RGN_XOR)
#ELSE
MACRO AfxUnionRgn(hrgnResult, hrgnA, hrgnB)  = CombineRgn(hrgnResult, hrgnA, hrgnB, %RGN_OR)
MACRO AfxXorRgn(hrgnResult, hrgnA, hrgnB)    = CombineRgn(hrgnResult, hrgnA, hrgnB, %RGN_XOR)
#ENDIF

MACRO DeletePalette(hpal)=DeleteObject(hpal)

MACRO DeleteFont(hfont)=DeleteObject(hfont)
MACRO SelectFont(hdc, hfont)=SelectObject(hdc, hfont)
MACRO GetStockFont(i)=GetStockObject(i)

MACRO DeleteBitmap(hbm)=DeleteObject(hbm)
MACRO SelectBitmap(hdc, hbm)=SelectObject(hdc, hbm)

#IF NOT %DEF(%MAC)
MACRO InsetRect(lprc, dx, dy)=InflateRect(lprc, -dx, -dy)
#ELSE
MACRO AfxInsetRect(lprc, dx, dy)=InflateRect(lprc, -dx, -dy)
#ENDIF

'***** USER Macro APIs *******************************************************

MACRO GetWindowInstance(hwnd)=GetWindowLongPtr(hwnd, %GWLP_HINSTANCE)

MACRO GetWindowStyle(hwnd)   =GetWindowLong(hwnd, %GWL_STYLE)
MACRO GetWindowExStyle(hwnd) =GetWindowLong(hwnd, %GWL_EXSTYLE)

MACRO GetWindowOwner(hwnd)   =GetWindow(hwnd, %GW_OWNER)

MACRO GetFirstChild(hwnd)    =GetTopWindow(hwnd)
MACRO GetFirstSibling(hwnd)  =GetWindow(hwnd, %GW_HWNDFIRST)
MACRO GetLastSibling(hwnd)   =GetWindow(hwnd, %GW_HWNDLAST)
MACRO GetNextSibling(hwnd)   =GetWindow(hwnd, %GW_HWNDNEXT)
MACRO GetPrevSibling(hwnd)   =GetWindow(hwnd, %GW_HWNDPREV)

MACRO GetWindowID(hwnd)      =GetDlgCtrlID(hwnd)

MACRO SetWindowRedraw(hwnd, fRedraw)
    SendMessage hwnd, %WM_SETREDRAW, fRedraw, 0
END MACRO

MACRO SubclassWindow(hwnd, lpfn)=SetWindowLongPtr(hwnd, %GWLP_WNDPROC, lpfn)

MACRO IsMinimized(hwnd)=IsIconic(hwnd)
MACRO IsMaximized(hwnd)=IsZoomed(hwnd)
MACRO IsRestored(hwnd)=ABS((GetWindowStyle(hwnd) AND (%WS_MINIMIZE OR %WS_MAXIMIZE)) = 0)

MACRO SetWindowFont(hwnd, hfont, fRedraw)=FORWARD_WM_SETFONT(hwnd, hfont, fRedraw, SendMessage)

MACRO GetWindowFont(hwnd)=FORWARD_WM_GETFONT(hwnd, SendMessage)

#IF (%WINVER >= &H030a)

#IF %DEF(%UNIX)
MACRO MapWindowRect=MwMapWindowRect
'LONG MwMapWindowRect(HWND, HWND, RECT *);
#ELSE
MACRO MapWindowRect(hwndFrom, hwndTo, lprc)=MapWindowPoints(hwndFrom, hwndTo, lprc, 2)
#ENDIF ' NOT %UNIX
#ENDIF


MACRO IsLButtonDown=ABS(GetKeyState(%VK_LBUTTON) < 0)
MACRO IsRButtonDown=ABS(GetKeyState(%VK_RBUTTON) < 0)
MACRO IsMButtonDown=ABS(GetKeyState(%VK_MBUTTON) < 0)

MACRO SubclassDialog(hwndDlg, lpfn)=SetWindowLongPtr(hwndDlg, %DWLP_DLGPROC, lpfn)

MACRO FUNCTION SetDlgMsgResult(hwnd, msg, result)
    MACROTEMP retval
    LOCAL retval AS LONG

    IF msg = %WM_CTLCOLORMSGBOX OR msg = %WM_CTLCOLOREDIT _
    OR msg = %WM_CTLCOLORLISTBOX OR msg = %WM_CTLCOLORBTN _
    OR msg = %WM_CTLCOLORDLG OR msg = %WM_CTLCOLORSCROLLBAR _
    OR msg = %WM_CTLCOLORSTATIC OR msg = %WM_COMPAREITEM _
    OR msg = %WM_VKEYTOITEM OR msg = %WM_CHARTOITEM _
    OR msg = %WM_QUERYDRAGICON OR msg = %WM_INITDIALOG THEN
        retval = result
    ELSE
        SetWindowLongPtr hwnd, %DWLP_MSGRESULT, result
        retval = %TRUE
    END IF
END MACRO=retval

MACRO FUNCTION DefDlgProcEx(hwnd, msg, wParam, lParam, pfRecursion)
    *pfRecursion = %TRUE
END MACRO=DefDlgProc(hwnd, msg, wParam, lParam)

MACRO CheckDefDlgRecursion(pfRecursion)
    IF *pfRecursion THEN
        *pfRecursion = %FALSE
        FUNCTION = %FALSE
        EXIT FUNCTION
    END IF
END MACRO

'***** Message crackers *****************************************************

'#define HANDLE_MSG(hwnd, message, fn)
'    case (message): return HANDLE_##message((hwnd), (wParam), (lParam), (fn))

' void Cls_OnCompacting(HWND hwnd, UINT compactRatio)
MACRO FUNCTION HANDLE_WM_COMPACTING(hwnd, wParam, lParam, fn)
    fn hwnd, wParam
END MACRO=0
MACRO FORWARD_WM_COMPACTING(hwnd, compactRatio, fn)
    fn hwnd, %WM_COMPACTING, compactRatio, 0
END MACRO

' void Cls_OnWinIniChange(HWND hwnd, LPCTSTR lpszSectionName)
MACRO FUNCTION HANDLE_WM_WININICHANGE(hwnd, wParam, lParam, fn)
    fn hwnd, lParam
END MACRO=0
MACRO FORWARD_WM_WININICHANGE(hwnd, lpszSectionName, fn)
    fn hwnd, %WM_WININICHANGE, 0, lpszSectionName
END MACRO

' void Cls_OnSysColorChange(HWND hwnd)
MACRO FUNCTION HANDLE_WM_SYSCOLORCHANGE(hwnd, wParam, lParam, fn)
    fn hwnd
END MACRO=0
MACRO FORWARD_WM_SYSCOLORCHANGE(hwnd, fn)
    fn hwnd, %WM_SYSCOLORCHANGE, 0, 0
END MACRO

' BOOL Cls_OnQueryNewPalette(HWND hwnd)
MACRO HANDLE_WM_QUERYNEWPALETTE(hwnd, wParam, lParam, fn)=MAKELRESULT(fn(hwnd), 0)
MACRO FORWARD_WM_QUERYNEWPALETTE(hwnd, fn)=fn (hwnd, %WM_QUERYNEWPALETTE, 0, 0)

' void Cls_OnPaletteIsChanging(HWND hwnd, HWND hwndPaletteChange)
MACRO HANDLE_WM_PALETTEISCHANGING(hwnd, wParam, lParam, fn)=fn (hwnd, wParam, 0)
MACRO FORWARD_WM_PALETTEISCHANGING(hwnd, hwndPaletteChange, fn)
    fn hwnd, %WM_PALETTEISCHANGING, hwndPaletteChange, 0
END MACRO

' void Cls_OnPaletteChanged(HWND hwnd, HWND hwndPaletteChange)
MACRO FUNCTION HANDLE_WM_PALETTECHANGED(hwnd, wParam, lParam, fn)
    fn hwnd, wParam
END MACRO=0
MACRO FORWARD_WM_PALETTECHANGED(hwnd, hwndPaletteChange, fn)
    fn hwnd, %WM_PALETTECHANGED, hwndPaletteChange, 0
END MACRO

' void Cls_OnFontChange(HWND hwnd)
MACRO FUNCTION HANDLE_WM_FONTCHANGE(hwnd, wParam, lParam, fn)
    fn hwnd
END MACRO=0
MACRO FORWARD_WM_FONTCHANGE(hwnd, fn)
    fn hwnd, %WM_FONTCHANGE, 0, 0
END MACRO

' void Cls_OnSpoolerStatus(HWND hwnd, UINT status, int cJobInQueue)
MACRO FUNCTION HANDLE_WM_SPOOLERSTATUS(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, LO(WORD, lParam)
END MACRO=0
MACRO FORWARD_WM_SPOOLERSTATUS(hwnd, STATUS, cJobInQueue, fn)
    fn hwnd, %WM_SPOOLERSTATUS, STATUS, MAKELPARAM(cJobInQueue, 0)
END MACRO

' void Cls_OnDevModeChange(HWND hwnd, LPCTSTR lpszDeviceName)
MACRO FUNCTION HANDLE_WM_DEVMODECHANGE(hwnd, wParam, lParam, fn)
    fn hwnd, lParam
END MACRO=0
MACRO FORWARD_WM_DEVMODECHANGE(hwnd, lpszDeviceName, fn)
    fn hwnd, %WM_DEVMODECHANGE, 0, lpszDeviceName
END MACRO

' void Cls_OnTimeChange(HWND hwnd)
MACRO FUNCTION HANDLE_WM_TIMECHANGE(hwnd, wParam, lParam, fn)
    fn hwnd
END MACRO=0
MACRO FORWARD_WM_TIMECHANGE(hwnd, fn)
    fn hwnd, %WM_TIMECHANGE, 0, 0
END MACRO

' void Cls_OnPower(HWND hwnd, int code)
MACRO FUNCTION HANDLE_WM_POWER(hwnd, wParam, lParam, fn)
    fn hwnd, wParam
END MACRO=0
MACRO FORWARD_WM_POWER(hwnd, CODE, fn)
    fn hwnd, %WM_POWER, CODE, 0
END MACRO

' BOOL Cls_OnQueryEndSession(HWND hwnd)
MACRO HANDLE_WM_QUERYENDSESSION(hwnd, wParam, lParam, fn)=MAKELRESULT(fn(hwnd), 0)
MACRO FORWARD_WM_QUERYENDSESSION(hwnd, fn)=fn(hwnd, %WM_QUERYENDSESSION, 0, 0)

' void Cls_OnEndSession(HWND hwnd, BOOL fEnding)
MACRO FUNCTION HANDLE_WM_ENDSESSION(hwnd, wParam, lParam, fn)
    fn hwnd, wParam
END MACRO=0
MACRO FORWARD_WM_ENDSESSION(hwnd, fEnding, fn)
    fn hwnd, %WM_ENDSESSION, fEnding, 0
END MACRO

' void Cls_OnQuit(HWND hwnd, int exitCode)
MACRO FUNCTION HANDLE_WM_QUIT(hwnd, wParam, lParam, fn)
    fn hwnd, wParam
END MACRO=0
MACRO FORWARD_WM_QUIT(hwnd, exitCode, fn)
    fn hwnd, %WM_QUIT, exitCode, 0
END MACRO

' This message is in Windows 3.1 only
' void Cls_OnSystemError(HWND hwnd, int errCode)
MACRO HANDLE_WM_SYSTEMERROR(hwnd, wParam, lParam, fn)=0
MACRO FORWARD_WM_SYSTEMERROR(hwnd, errCode, fn)=0

' BOOL Cls_OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct)
MACRO HANDLE_WM_CREATE(hwnd, wParam, lParam, fn)=IIF&(fn(hwnd, lParam), 0, -1)
MACRO FORWARD_WM_CREATE(hwnd, lpCreateStruct, fn)=fn(hwnd, %WM_CREATE, 0, lpCreateStruct)

' BOOL Cls_OnNCCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct)
MACRO HANDLE_WM_NCCREATE(hwnd, wParam, lParam, fn)=fn(hwnd, lParam)
MACRO FORWARD_WM_NCCREATE(hwnd, lpCreateStruct, fn)=fn(hwnd, %WM_NCCREATE, 0, lpCreateStruct)

' void Cls_OnDestroy(HWND hwnd)
MACRO FUNCTION HANDLE_WM_DESTROY(hwnd, wParam, lParam, fn)
    fn hwnd
END MACRO=0
MACRO FORWARD_WM_DESTROY(hwnd, fn)
    fn hwnd, %WM_DESTROY, 0, 0
END MACRO

' void Cls_OnNCDestroy(HWND hwnd)
MACRO FUNCTION HANDLE_WM_NCDESTROY(hwnd, wParam, lParam, fn)
    fn hwnd
END MACRO=0
MACRO FORWARD_WM_NCDESTROY(hwnd, fn)
    fn hwnd, %WM_NCDESTROY, 0, 0
END MACRO

' void Cls_OnShowWindow(HWND hwnd, BOOL fShow, UINT status)
MACRO FUNCTION HANDLE_WM_SHOWWINDOW(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, lParam
END MACRO=0
MACRO FORWARD_WM_SHOWWINDOW(hwnd, fShow, STATUS, fn)
    fn hwnd, WM_SHOWWINDOW, fShow, STATUS
END MACRO

' void Cls_OnSetRedraw(HWND hwnd, BOOL fRedraw)
MACRO FUNCTION HANDLE_WM_SETREDRAW(hwnd, wParam, lParam, fn)
    fn(hwnd, wParam)
END MACRO=0
MACRO FORWARD_WM_SETREDRAW(hwnd, fRedraw, fn)
    fn hwnd, %WM_SETREDRAW, fRedraw, 0
END MACRO

' void Cls_OnEnable(HWND hwnd, BOOL fEnable)
MACRO FUNCTION HANDLE_WM_ENABLE(hwnd, wParam, lParam, fn)
    fn hwnd, wParam
END MACRO=0
MACRO FORWARD_WM_ENABLE(hwnd, fEnable, fn)
    fn hwnd, %WM_ENABLE, fEnable, 0
END MACRO

' void Cls_OnSetText(HWND hwnd, LPCTSTR lpszText)
MACRO FUNCTION HANDLE_WM_SETTEXT(hwnd, wParam, lParam, fn)
    fn hwnd, lParam
END MACRO=0
MACRO FORWARD_WM_SETTEXT(hwnd, lpszText, fn)
    fn hwnd, %WM_SETTEXT, 0, lpszText
END MACRO

' INT Cls_OnGetText(HWND hwnd, int cchTextMax, LPTSTR lpszText)
MACRO HANDLE_WM_GETTEXT(hwnd, wParam, lParam, fn)=fn(hwnd, wParam, lParam)
MACRO FORWARD_WM_GETTEXT(hwnd, cchTextMax, lpszText, fn)=fn(hwnd, %WM_GETTEXT, cchTextMax, lpszText)

' INT Cls_OnGetTextLength(HWND hwnd)
MACRO HANDLE_WM_GETTEXTLENGTH(hwnd, wParam, lParam, fn)=fn(hwnd)
MACRO FORWARD_WM_GETTEXTLENGTH(hwnd, fn)=fn(hwnd, %WM_GETTEXTLENGTH, 0, 0)

' BOOL Cls_OnWindowPosChanging(HWND hwnd, LPWINDOWPOS lpwpos)
MACRO HANDLE_WM_WINDOWPOSCHANGING(hwnd, wParam, lParam, fn)=fn(hwnd, lParam)
MACRO FORWARD_WM_WINDOWPOSCHANGING(hwnd, lpwpos, fn)=fn(hwnd, %WM_WINDOWPOSCHANGING, 0, lpwpos)

' void Cls_OnWindowPosChanged(HWND hwnd, const LPWINDOWPOS lpwpos)
MACRO FUNCTION HANDLE_WM_WINDOWPOSCHANGED(hwnd, wParam, lParam, fn)
    fn hwnd, lParam
END MACRO=0
MACRO FORWARD_WM_WINDOWPOSCHANGED(hwnd, lpwpos, fn)
    fn hwnd, %WM_WINDOWPOSCHANGED, 0, lpwpos
END MACRO

' void Cls_OnMove(HWND hwnd, int x, int y)
MACRO FUNCTION HANDLE_WM_MOVE(hwnd, wParam, lParam, fn)
    fn hwnd, LO(WORD, lParam), HI(WORD, lParam)
END MACRO=0
MACRO FORWARD_WM_MOVE(hwnd, x, y, fn)
    fn hwnd, %WM_MOVE, 0, MAKELPARAM((x), (y))
END MACRO

' void Cls_OnSize(HWND hwnd, UINT state, int cx, int cy)
MACRO FUNCTION HANDLE_WM_SIZE(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, LO(WORD, lParam), HI(WORD, lParam)
END MACRO=0
MACRO FORWARD_WM_SIZE(hwnd, STATE, cx, cy, fn)
    fn hwnd, %WM_SIZE, STATE, MAKELPARAM((cx), (cy))
END MACRO

' void Cls_OnClose(HWND hwnd)
MACRO FUNCTION HANDLE_WM_CLOSE(hwnd, wParam, lParam, fn)
    fn(hwnd)
END MACRO=0
MACRO FORWARD_WM_CLOSE(hwnd, fn)
    fn hwnd, %WM_CLOSE, 0, 0
END MACRO

' BOOL Cls_OnQueryOpen(HWND hwnd)
MACRO HANDLE_WM_QUERYOPEN(hwnd, wParam, lParam, fn)=MAKELRESULT(fn(hwnd), 0)
MACRO FORWARD_WM_QUERYOPEN(hwnd, fn)=fn(hwnd, %WM_QUERYOPEN, 0, 0)

' void Cls_OnGetMinMaxInfo(HWND hwnd, LPMINMAXINFO lpMinMaxInfo)
MACRO FUNCTION HANDLE_WM_GETMINMAXINFO(hwnd, wParam, lParam, fn)
    fn hwnd, lParam
END MACRO=0
MACRO FORWARD_WM_GETMINMAXINFO(hwnd, lpMinMaxInfo, fn)
    fn hwnd, %WM_GETMINMAXINFO, 0, lpMinMaxInfo
END MACRO

' void Cls_OnPaint(HWND hwnd)
MACRO FUNCTION HANDLE_WM_PAINT(hwnd, wParam, lParam, fn)
    fn hwnd
END MACRO=0
MACRO FORWARD_WM_PAINT(hwnd, fn)
    fn hwnd, %WM_PAINT, 0, 0
END MACRO

' BOOL Cls_OnEraseBkgnd(HWND hwnd, HDC hdc)
MACRO HANDLE_WM_ERASEBKGND(hwnd, wParam, lParam, fn)=fn(hwnd, wParam)
MACRO FORWARD_WM_ERASEBKGND(hwnd, hdc, fn)=fn(hwnd, %WM_ERASEBKGND, hdc, 0)

' BOOL Cls_OnIconEraseBkgnd(HWND hwnd, HDC hdc)
MACRO HANDLE_WM_ICONERASEBKGND(hwnd, wParam, lParam, fn)=fn(hwnd, wParam)
MACRO FORWARD_WM_ICONERASEBKGND(hwnd, hdc, fn)=fn(hwnd, %WM_ICONERASEBKGND, hdc, 0)

' void Cls_OnNCPaint(HWND hwnd, HRGN hrgn)
MACRO FUNCTION HANDLE_WM_NCPAINT(hwnd, wParam, lParam, fn)
    fn hwnd, wParam
END MACRO=0
MACRO FORWARD_WM_NCPAINT(hwnd, hrgn, fn)
    fn hwnd, WM_NCPAINT, hrgn, 0
END MACRO

' UINT Cls_OnNCCalcSize(HWND hwnd, BOOL fCalcValidRects, NCCALCSIZE_PARAMS * lpcsp)
MACRO HANDLE_WM_NCCALCSIZE(hwnd, wParam, lParam, fn)=fn(hwnd, wParam, lParam)
MACRO FORWARD_WM_NCCALCSIZE(hwnd, fCalcValidRects, lpcsp, fn)=fn(hwnd, %WM_NCCALCSIZE, fCalcValidRects, lpcsp)

' UINT Cls_OnNCHitTest(HWND hwnd, int x, int y)
MACRO HANDLE_WM_NCHITTEST(hwnd, wParam, lParam, fn)=fn(hwnd, LO(WORD, lParam), HI(WORD, lParam))
MACRO FORWARD_WM_NCHITTEST(hwnd, x, y, fn)=fn(hwnd, %WM_NCHITTEST, 0, MAKELPARAM((x), (y)))

' HICON Cls_OnQueryDragIcon(HWND hwnd)
MACRO HANDLE_WM_QUERYDRAGICON(hwnd, wParam, lParam, fn)=fn(hwnd)
MACRO FORWARD_WM_QUERYDRAGICON(hwnd, fn)=fn(hwnd, %WM_QUERYDRAGICON, 0, 0)

#IF %DEF(%INC_SHELLAPI)
' void Cls_OnDropFiles(HWND hwnd, HDROP hdrop)
MACRO FUNCTION HANDLE_WM_DROPFILES(hwnd, wParam, lParam, fn)
    fn hwnd, wParam
END MACRO=0
MACRO FORWARD_WM_DROPFILES(hwnd, hdrop, fn)
    fn hwnd, %WM_DROPFILES, hdrop, 0
END MACRO
#ENDIF  ' %INC_SHELLAPI

' void Cls_OnActivate(HWND hwnd, UINT state, HWND hwndActDeact, BOOL fMinimized)
MACRO FUNCTION HANDLE_WM_ACTIVATE(hwnd, wParam, lParam, fn)
    fn hwnd, LO(WORD, wParam), lParam, HI(WORD, wParam)
END MACRO=0
MACRO FORWARD_WM_ACTIVATE(hwnd, STATE, hwndActDeact, fMinimized, fn)
    fn hwnd, %WM_ACTIVATE, MAKEWPARAM((STATE), (fMinimized)), hwndActDeact
END MACRO

' void Cls_OnActivateApp(HWND hwnd, BOOL fActivate, DWORD dwThreadId)
MACRO FUNCTION HANDLE_WM_ACTIVATEAPP(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, lParam
END MACRO=0
MACRO FORWARD_WM_ACTIVATEAPP(hwnd, fActivate, dwThreadId, fn)
    fn hwnd, %WM_ACTIVATEAPP, fActivate, dwThreadId
END MACRO

' BOOL Cls_OnNCActivate(HWND hwnd, BOOL fActive, HWND hwndActDeact, BOOL fMinimized)
MACRO HANDLE_WM_NCACTIVATE(hwnd, wParam, lParam, fn)=fn(hwnd, wParam, 0, 0)
MACRO FORWARD_WM_NCACTIVATE(hwnd, fActive, hwndActDeact, fMinimized, fn)=fn(hwnd, %WM_NCACTIVATE, fActive, 0)

' void Cls_OnSetFocus(HWND hwnd, HWND hwndOldFocus)
MACRO FUNCTION HANDLE_WM_SETFOCUS(hwnd, wParam, lParam, fn)
    fn hwnd, wParam
END MACRO=0
MACRO FORWARD_WM_SETFOCUS(hwnd, hwndOldFocus, fn)
    fn hwnd, %WM_SETFOCUS, hwndOldFocus, 0
END MACRO

' void Cls_OnKillFocus(HWND hwnd, HWND hwndNewFocus)
MACRO FUNCTION HANDLE_WM_KILLFOCUS(hwnd, wParam, lParam, fn)
    fn hwnd, wParam
END MACRO=0
MACRO FORWARD_WM_KILLFOCUS(hwnd, hwndNewFocus, fn)
    fn hwnd, %WM_KILLFOCUS, hwndNewFocus, 0
END MACRO

' void Cls_OnKey(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags)
MACRO FUNCTION HANDLE_WM_KEYDOWN(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, %TRUE, LO(WORD, lParam), HI(WORD, lParam)
END MACRO=0
MACRO FORWARD_WM_KEYDOWN(hwnd, vk, cRepeat, flags, fn)
    fn hwnd, %WM_KEYDOWN, vk, MAKELPARAM((cRepeat), (flags))
END MACRO

' void Cls_OnKey(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags)
MACRO FUNCTION HANDLE_WM_KEYUP(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, %FALSE, LO(WORD, lParam), HI(WORD, lParam)
END MACRO=0
MACRO FORWARD_WM_KEYUP(hwnd, vk, cRepeat, flags, fn)
    fn hwnd, %WM_KEYUP, vk, MAKELPARAM((cRepeat), (flags))
END MACRO

' void Cls_OnChar(HWND hwnd, TCHAR ch, int cRepeat)
MACRO FUNCTION HANDLE_WM_CHAR(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, LO(INTEGER, lParam)
END MACRO=0
MACRO FORWARD_WM_CHAR(hwnd, ch, cRepeat, fn)
    fn hwnd, %WM_CHAR, ch, MAKELPARAM((cRepeat),0)
END MACRO

' void Cls_OnDeadChar(HWND hwnd, TCHAR ch, int cRepeat)
MACRO FUNCTION HANDLE_WM_DEADCHAR(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, LO(INTEGER, lParam)
END MACRO=0
MACRO FORWARD_WM_DEADCHAR(hwnd, ch, cRepeat, fn)
    fn hwnd, %WM_DEADCHAR, ch, MAKELPARAM((cRepeat),0)
END MACRO

' void Cls_OnSysKey(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags)
MACRO FUNCTION HANDLE_WM_SYSKEYDOWN(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, %TRUE, LO(INTEGER, lParam), HI(WORD, lParam)
END MACRO=0
MACRO FORWARD_WM_SYSKEYDOWN(hwnd, vk, cRepeat, flags, fn)
    fn hwnd, %WM_SYSKEYDOWN, vk, MAKELPARAM((cRepeat), (flags))
END MACRO

' void Cls_OnSysKey(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags)
MACRO FUNCTION HANDLE_WM_SYSKEYUP(hwnd, wParam, lParam, fn)
    fn (hwnd, wParam, %FALSE, LO(INTEGER, lParam), HI(WORD, lParam))
END MACRO=0
MACRO FORWARD_WM_SYSKEYUP(hwnd, vk, cRepeat, flags, fn)
    fn hwnd, %WM_SYSKEYUP, vk, MAKELPARAM((cRepeat), (flags))
END MACRO

' void Cls_OnSysChar(HWND hwnd, TCHAR ch, int cRepeat)
MACRO FUNCTION HANDLE_WM_SYSCHAR(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, LO(INTEGER, lParam)
END MACRO=0
MACRO FORWARD_WM_SYSCHAR(hwnd, ch, cRepeat, fn)
    fn hwnd, %WM_SYSCHAR, ch, MAKELPARAM((cRepeat), 0)
END MACRO

' void Cls_OnSysDeadChar(HWND hwnd, TCHAR ch, int cRepeat)
MACRO FUNCTION HANDLE_WM_SYSDEADCHAR(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, LO(INTEGER, lParam)
END MACRO=0
MACRO FORWARD_WM_SYSDEADCHAR(hwnd, ch, cRepeat, fn)
    fn hwnd, %WM_SYSDEADCHAR, ch, MAKELPARAM((cRepeat), 0)
END MACRO

' void Cls_OnMouseMove(HWND hwnd, int x, int y, UINT keyFlags)
MACRO FUNCTION HANDLE_WM_MOUSEMOVE(hwnd, wParam, lParam, fn)
    fn hwnd, LO(INTEGER, lParam), HI(INTEGER, lParam), wParam
END MACRO=0
MACRO FORWARD_WM_MOUSEMOVE(hwnd, x, y, keyFlags, fn)
    fn hwnd, %WM_MOUSEMOVE, keyFlags, MAKELPARAM((x), (y))
END MACRO

' void Cls_OnLButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
MACRO FUNCTION HANDLE_WM_LBUTTONDOWN(hwnd, wParam, lParam, fn)
    fn hwnd, %FALSE, LO(INTEGER, lParam), HI(INTEGER, lParam), wParam
END MACRO=0
MACRO FORWARD_WM_LBUTTONDOWN(hwnd, fDoubleClick, x, y, keyFlags, fn)
    fn hwnd, IIF&(fDoubleClick, %WM_LBUTTONDBLCLK, %WM_LBUTTONDOWN), keyFlags, MAKELPARAM((x), (y))
END MACRO

' void Cls_OnLButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
MACRO FUNCTION HANDLE_WM_LBUTTONDBLCLK(hwnd, wParam, lParam, fn)
    fn hwnd, %TRUE, LO(INTEGER, lParam), HI(INTEGER, lParam), wParam
END MACRO=0

' void Cls_OnLButtonUp(HWND hwnd, int x, int y, UINT keyFlags)
MACRO FUNCTION HANDLE_WM_LBUTTONUP(hwnd, wParam, lParam, fn)
    fn hwnd, LO(INTEGER, lParam), HI(INTEGER, lParam), wParam
END MACRO=0
MACRO FORWARD_WM_LBUTTONUP(hwnd, x, y, keyFlags, fn)
    fn hwnd, WM_LBUTTONUP, keyFlags, MAKELPARAM((x), (y))
END MACRO

' void Cls_OnRButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
MACRO FUNCTION HANDLE_WM_RBUTTONDOWN(hwnd, wParam, lParam, fn)
    fn hwnd, %FALSE, LO(INTEGER, lParam), HI(INTEGER, lParam), wParam
END MACRO=0
MACRO FORWARD_WM_RBUTTONDOWN(hwnd, fDoubleClick, x, y, keyFlags, fn)
    fn hwnd, IIF&(fDoubleClick, %WM_RBUTTONDBLCLK, %WM_RBUTTONDOWN), keyFlags, MAKELPARAM((x), (y))
END MACRO

' void Cls_OnRButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
MACRO FUNCTION HANDLE_WM_RBUTTONDBLCLK(hwnd, wParam, lParam, fn)
    fn hwnd, %TRUE, LO(INTEGER, lParam), HI(INTEGER, lParam), wParam
END MACRO=0

' void Cls_OnRButtonUp(HWND hwnd, int x, int y, UINT flags)
MACRO FUNCTION HANDLE_WM_RBUTTONUP(hwnd, wParam, lParam, fn)
    fn hwnd, LO(INTEGER, lParam), HI(INTEGER, lParam), wParam
END MACRO=0
MACRO FORWARD_WM_RBUTTONUP(hwnd, x, y, keyFlags, fn)
    fn hwnd, %WM_RBUTTONUP, keyFlags, MAKELPARAM((x), (y))
END MACRO

' void Cls_OnMButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
MACRO FUNCTION HANDLE_WM_MBUTTONDOWN(hwnd, wParam, lParam, fn)
    fn hwnd, %FALSE, LO(INTEGER, lParam), HI(INTEGER, lParam), wParam
END MACRO=0
MACRO FORWARD_WM_MBUTTONDOWN(hwnd, fDoubleClick, x, y, keyFlags, fn)
    fn hwnd, IIF&(fDoubleClick, %WM_MBUTTONDBLCLK, %WM_MBUTTONDOWN), keyFlags, MAKELPARAM(x, y)
END MACRO

' void Cls_OnMButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
MACRO FUNCTION HANDLE_WM_MBUTTONDBLCLK(hwnd, wParam, lParam, fn)
    fn hwnd, %TRUE, LO(INTEGER, lParam), HI(INTEGER, lParam), wParam
END MACRO=0

' void Cls_OnMButtonUp(HWND hwnd, int x, int y, UINT flags)
MACRO FUNCTION HANDLE_WM_MBUTTONUP(hwnd, wParam, lParam, fn)
    fn hwnd, LO(INTEGER, lParam), HI(INTEGER, lParam), wParam
END MACRO=0
MACRO FORWARD_WM_MBUTTONUP(hwnd, x, y, keyFlags, fn)
    fn hwnd, %WM_MBUTTONUP, keyFlags, MAKELPARAM((x), (y))
END MACRO

' void Cls_OnMouseWheel(HWND hwnd, int xPos, int yPos, int zDelta, UINT fwKeys)
MACRO FUNCTION HANDLE_WM_MOUSEWHEEL(hwnd, wParam, lParam, fn)
    fn hwnd, LO(INTEGER, lParam), HI(INTEGER, lParam), HI(INTEGER, wParam), LO(WORD, wParam)
END MACRO=0
MACRO FORWARD_WM_MOUSEWHEEL(hwnd, xPos, yPos, zDelta, fwKeys, fn)
    fn hwnd, %WM_MOUSEWHEEL, MAKEWPARAM((fwKeys),(zDelta)), MAKELPARAM((xPos),(yPos))
END MACRO

' void Cls_OnNCMouseMove(HWND hwnd, int x, int y, UINT codeHitTest)
MACRO FUNCTION HANDLE_WM_NCMOUSEMOVE(hwnd, wParam, lParam, fn)
    fn hwnd, LO(INTEGER, lParam), HI(INTEGER, lParam), wParam
END MACRO=0
MACRO FORWARD_WM_NCMOUSEMOVE(hwnd, x, y, codeHitTest, fn)
    fn hwnd, %WM_NCMOUSEMOVE, codeHitTest, MAKELPARAM((x), (y))
END MACRO

' void Cls_OnNCLButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT codeHitTest)
MACRO FUNCTION HANDLE_WM_NCLBUTTONDOWN(hwnd, wParam, lParam, fn)
    fn hwnd, %FALSE, LO(INTEGER, lParam), HI(INTEGER, lParam), wParam
END MACRO=0
MACRO FORWARD_WM_NCLBUTTONDOWN(hwnd, fDoubleClick, x, y, codeHitTest, fn)
    fn hwnd, IIF&(fDoubleClick, %WM_NCLBUTTONDBLCLK, %WM_NCLBUTTONDOWN), codeHitTest, MAKELPARAM((x), (y))
END MACRO

' void Cls_OnNCLButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT codeHitTest)
MACRO FUNCTION HANDLE_WM_NCLBUTTONDBLCLK(hwnd, wParam, lParam, fn)
    fn hwnd, %TRUE, LO(INTEGER, lParam), HI(INTEGER, lParam), wParam
END MACRO=0

' void Cls_OnNCLButtonUp(HWND hwnd, int x, int y, UINT codeHitTest)
MACRO FUNCTION HANDLE_WM_NCLBUTTONUP(hwnd, wParam, lParam, fn)
    fn hwnd, LO(INTEGER, lParam), HI(INTEGER, lParam), wParam
END MACRO=0
MACRO FORWARD_WM_NCLBUTTONUP(hwnd, x, y, codeHitTest, fn)
    fn hwnd, %WM_NCLBUTTONUP, codeHitTest, MAKELPARAM((x), (y))
END MACRO

' void Cls_OnNCRButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT codeHitTest)
MACRO FUNCTION HANDLE_WM_NCRBUTTONDOWN(hwnd, wParam, lParam, fn)
    fn hwnd, %FALSE, LO(INTEGER, lParam), HI(INTEGER, lParam), wParam
END MACRO=0
MACRO FORWARD_WM_NCRBUTTONDOWN(hwnd, fDoubleClick, x, y, codeHitTest, fn)
    fn hwnd, IIF&(fDoubleClick, %WM_NCRBUTTONDBLCLK, %WM_NCRBUTTONDOWN), codeHitTest, MAKELPARAM((x), (y))
END MACRO

' void Cls_OnNCRButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT codeHitTest)
MACRO FUNCTION HANDLE_WM_NCRBUTTONDBLCLK(hwnd, wParam, lParam, fn)
    fn hwnd, %TRUE, LO(INTEGER, lParam), HI(INTEGER, lParam), wParam
END MACRO=0

' void Cls_OnNCRButtonUp(HWND hwnd, int x, int y, UINT codeHitTest)
MACRO FUNCTION HANDLE_WM_NCRBUTTONUP(hwnd, wParam, lParam, fn)
    fn hwnd, LO(INTEGER, lParam), HI(INTEGER, lParam), wParam
END MACRO=0
MACRO FORWARD_WM_NCRBUTTONUP(hwnd, x, y, codeHitTest, fn)
    fn hwnd, %WM_NCRBUTTONUP, codeHitTest, MAKELPARAM((x), (y))
END MACRO

' void Cls_OnNCMButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT codeHitTest)
MACRO FUNCTION HANDLE_WM_NCMBUTTONDOWN(hwnd, wParam, lParam, fn)
    fn hwnd, %FALSE, LO(INTEGER, lParam), HI(INTEGER, lParam), wParam
END MACRO=0
MACRO FORWARD_WM_NCMBUTTONDOWN(hwnd, fDoubleClick, x, y, codeHitTest, fn)
    fn hwnd, IIF&(fDoubleClick, %WM_NCMBUTTONDBLCLK, %WM_NCMBUTTONDOWN), codeHitTest, MAKELPARAM((x), (y))
END MACRO

' void Cls_OnNCMButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT codeHitTest)
MACRO FUNCTION HANDLE_WM_NCMBUTTONDBLCLK(hwnd, wParam, lParam, fn)
    fn hwnd, %TRUE, LO(INTEGER, lParam), HI(INTEGER, lParam), wParam
END MACRO=0

' void Cls_OnNCMButtonUp(HWND hwnd, int x, int y, UINT codeHitTest)
MACRO FUNCTION HANDLE_WM_NCMBUTTONUP(hwnd, wParam, lParam, fn)
    fn hwnd, LO(INTEGER, lParam), HI(INTEGER, lParam), wParam
END MACRO=0
MACRO FORWARD_WM_NCMBUTTONUP(hwnd, x, y, codeHitTest, fn)
    fn hwnd, %WM_NCMBUTTONUP, codeHitTest, MAKELPARAM((x), (y))
END MACRO

' int Cls_OnMouseActivate(HWND hwnd, HWND hwndTopLevel, UINT codeHitTest, UINT msg)
MACRO HANDLE_WM_MOUSEACTIVATE(hwnd, wParam, lParam, fn)=fn(hwnd, wParam, LO(WORD, lParam), HI(WORD, lParam))
MACRO FORWARD_WM_MOUSEACTIVATE(hwnd, hwndTopLevel, codeHitTest, msg, fn)=fn(hwnd, %WM_MOUSEACTIVATE, hwndTopLevel, MAKELPARAM((codeHitTest), (msg)))

' void Cls_OnCancelMode(HWND hwnd)
MACRO FUNCTION HANDLE_WM_CANCELMODE(hwnd, wParam, lParam, fn)
    fn hwnd
END MACRO=0
MACRO FORWARD_WM_CANCELMODE(hwnd, fn)
    fn hwnd, %WM_CANCELMODE, 0, 0
END MACRO

' void Cls_OnTimer(HWND hwnd, UINT id)
MACRO FUNCTION HANDLE_WM_TIMER(hwnd, wParam, lParam, fn)
    fn hwnd, wParam
END MACRO=0
MACRO FORWARD_WM_TIMER(hwnd, ID, fn)
    fn hwnd, %WM_TIMER, ID
END MACRO

' void Cls_OnInitMenu(HWND hwnd, HMENU hMenu)
MACRO FUNCTION HANDLE_WM_INITMENU(hwnd, wParam, lParam, fn)
    fn hwnd, wParam
END MACRO=0
MACRO FORWARD_WM_INITMENU(hwnd, hMenu, fn)
    fn hwnd, %WM_INITMENU, hMenu, 0
END MACRO

' void Cls_OnInitMenuPopup(HWND hwnd, HMENU hMenu, UINT item, BOOL fSystemMenu)
MACRO FUNCTION HANDLE_WM_INITMENUPOPUP(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, LO(WORD, lParam), HI(WORD, lParam)
END MACRO=0
MACRO FORWARD_WM_INITMENUPOPUP(hwnd, hMenu, ITEM, fSystemMenu, fn)
    fn hwnd, %WM_INITMENUPOPUP, hMenu, MAKELPARAM((ITEM),(fSystemMenu))
END MACRO

' void Cls_OnMenuSelect(HWND hwnd, HMENU hmenu, int item, HMENU hmenuPopup, UINT flags)
MACRO FUNCTION HANDLE_WM_MENUSELECT(hwnd, wParam, lParam, fn)
    fn hwnd, lParam, IIF&((HI(WORD, wParam) AND %MF_POPUP), 0, LO(WORD, wParam), IIF&(HI(WORD, wParam) AND %MF_POPUP), GetSubMenu(lParam, LO(WORD, wParam)), 0, HI(WORD, wParam) = -1), &HFFFFFFFF???, HI(WORD, wParam))
END MACRO=0
MACRO FORWARD_WM_MENUSELECT(hwnd, hmenu, ITEM, hmenuPopup, flags, fn)
    fn hwnd, WM_MENUSELECT, MAKEWPARAM((ITEM), (flags)), IIF&(hmenu, hmenu, hmenuPopup))
END MACRO

' DWORD Cls_OnMenuChar(HWND hwnd, UINT ch, UINT flags, HMENU hmenu)
MACRO HANDLE_WM_MENUCHAR(hwnd, wParam, lParam, fn)=fn (hwnd, LO(WORD, wParam), HI(WORD, wParam), lParam)
MACRO FORWARD_WM_MENUCHAR(hwnd, ch, flags, hmenu, fn)=fn(hwnd, %WM_MENUCHAR, MAKEWPARAM(flags, LO(WORD, ch)), hmenu)

' void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
MACRO FUNCTION HANDLE_WM_COMMAND(hwnd, wParam, lParam, fn)
    fn hwnd, LO(INTEGER, wParam), lParam, HI(WORD, wParam)
END MACRO=0
MACRO FORWARD_WM_COMMAND(hwnd, ID, hwndCtl, codeNotify, fn)
    fn hwnd, %WM_COMMAND, MAKEWPARAM(ID,codeNotify), hwndCtl
END MACRO

' void Cls_OnHScroll(HWND hwnd, HWND hwndCtl, UINT code, int posn)
MACRO FUNCTION HANDLE_WM_HSCROLL(hwnd, wParam, lParam, fn)
    ((fn)((hwnd), (HWND)(lParam), (UINT)(LO(WORD, wParam)), (INT)(short)HI(WORD, wParam))
END MACRO=0
MACRO FORWARD_WM_HSCROLL(hwnd, hwndCtl, CODE, posn, fn)
    fn hwnd, %WM_HSCROLL, MAKEWPARAM(CODE,posn), hwndCtl
END MACRO

' void Cls_OnVScroll(HWND hwnd, HWND hwndCtl, UINT code, int posn)
MACRO FUNCTION HANDLE_WM_VSCROLL(hwnd, wParam, lParam, fn)
    fn hwnd, lParam, LO(WORD, wParam), HI(INTEGER, wParam)
END MACRO=0
MACRO FORWARD_WM_VSCROLL(hwnd, hwndCtl, CODE, posn, fn)
    fn hwnd, %WM_VSCROLL, MAKEWPARAM(CODE, posn), hwndCtl
END MACRO

' void Cls_OnCut(HWND hwnd)
MACRO FUNCTION HANDLE_WM_CUT(hwnd, wParam, lParam, fn)
    fn hwnd
END MACRO=0
MACRO FORWARD_WM_CUT(hwnd, fn)
    fn hwnd, %WM_CUT, 0, 0
END MACRO

' void Cls_OnCopy(HWND hwnd)
MACRO FUNCTION HANDLE_WM_COPY(hwnd, wParam, lParam, fn)
    fn hwnd
END MACRO=0
MACRO FORWARD_WM_COPY(hwnd, fn)
    fn hwnd, %WM_COPY, 0, 0
END MACRO

' void Cls_OnPaste(HWND hwnd)
MACRO FUNCTION HANDLE_WM_PASTE(hwnd, wParam, lParam, fn)
    fn hwnd
END MACRO=0
MACRO FORWARD_WM_PASTE(hwnd, fn)
    fn hwnd, %WM_PASTE, 0, 0
END MACRO

' void Cls_OnClear(HWND hwnd)
MACRO FUNCTION HANDLE_WM_CLEAR(hwnd, wParam, lParam, fn)
    fn hwnd, 0
END MACRO=0
MACRO FORWARD_WM_CLEAR(hwnd, fn)
    fn hwnd, %WM_CLEAR, 0, 0
END MACRO

' void Cls_OnUndo(HWND hwnd)
MACRO FUNCTION HANDLE_WM_UNDO(hwnd, wParam, lParam, fn)
    fn hwnd
END MACRO=0
MACRO FORWARD_WM_UNDO(hwnd, fn)
    fn hwnd, %WM_UNDO, 0, 0
END MACRO

' HANDLE Cls_OnRenderFormat(HWND hwnd, UINT fmt)
MACRO HANDLE_WM_RENDERFORMAT(hwnd, wParam, lParam, fn)=fn(hwnd, wParam)
MACRO FORWARD_WM_RENDERFORMAT(hwnd, fmt, fn)=fn(hwnd, %WM_RENDERFORMAT, fmt, 0)

' void Cls_OnRenderAllFormats(HWND hwnd)
MACRO FUNCTION HANDLE_WM_RENDERALLFORMATS(hwnd, wParam, lParam, fn)
    fn hwnd
END MACRO=0
MACRO FORWARD_WM_RENDERALLFORMATS(hwnd, fn)
    fn hwnd, WM_RENDERALLFORMATS, 0, 0
END MACRO

' void Cls_OnDestroyClipboard(HWND hwnd)
MACRO FUNCTION HANDLE_WM_DESTROYCLIPBOARD(hwnd, wParam, lParam, fn)
    fn hwnd
END MACRO=0
MACRO FORWARD_WM_DESTROYCLIPBOARD(hwnd, fn)
    fn hwnd), %WM_DESTROYCLIPBOARD, 0, 0
END MACRO

' void Cls_OnDrawClipboard(HWND hwnd)
MACRO FUNCTION HANDLE_WM_DRAWCLIPBOARD(hwnd, wParam, lParam, fn)
    fn hwnd
END MACRO=0
MACRO FORWARD_WM_DRAWCLIPBOARD(hwnd, fn)
    fn hwnd, %WM_DRAWCLIPBOARD, 0, 0
END MACRO

' void Cls_OnPaintClipboard(HWND hwnd, HWND hwndCBViewer, const LPPAINTSTRUCT lpPaintStruct)
MACRO FUNCTION HANDLE_WM_PAINTCLIPBOARD(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, GlobalLock(lParam)
    GlobalUnlock lParam
END MACRO=0
MACRO FORWARD_WM_PAINTCLIPBOARD(hwnd, hwndCBViewer, lpPaintStruct, fn)
    fn hwnd, %WM_PAINTCLIPBOARD, hwndCBViewer, lpPaintStruct)
END MACRO

' void Cls_OnSizeClipboard(HWND hwnd, HWND hwndCBViewer, const LPRECT lprc)
MACRO FUNCTION HANDLE_WM_SIZECLIPBOARD(hwnd, wParam, lParam, fn)
    fn(hwnd, wParam, GlobalLock(lParam)
    GlobalUnlock(lParam)
END MACRO=0
MACRO FORWARD_WM_SIZECLIPBOARD(hwnd, hwndCBViewer, lprc, fn)
    fn hwnd, %WM_SIZECLIPBOARD, hwndCBViewer, lprc
END MACRO

' void Cls_OnVScrollClipboard(HWND hwnd, HWND hwndCBViewer, UINT code, int posn)
MACRO FUNCTION HANDLE_WM_VSCROLLCLIPBOARD(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, LO(WORD, lParam), HI(INTEGER, lParam)
END MACRO=0
MACRO FORWARD_WM_VSCROLLCLIPBOARD(hwnd, hwndCBViewer, CODE, posn, fn)
    fn hwnd, %WM_VSCROLLCLIPBOARD, hwndCBViewer, MAKELPARAM((CODE), (posn))
END MACRO

' void Cls_OnHScrollClipboard(HWND hwnd, HWND hwndCBViewer, UINT code, int posn)
MACRO FUNCTION HANDLE_WM_HSCROLLCLIPBOARD(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, LO(WORD, lParam), HI(INTEGER, lParam)
END MACRO=0
MACRO FORWARD_WM_HSCROLLCLIPBOARD(hwnd, hwndCBViewer, CODE, posn, fn)
    fn hwnd, %WM_HSCROLLCLIPBOARD, hwndCBViewer, MAKELPARAM((CODE), (posn))
END MACRO

' void Cls_OnAskCBFormatName(HWND hwnd, int cchMax, LPTSTR rgchName)
MACRO FUNCTION HANDLE_WM_ASKCBFORMATNAME(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, lParam)
END MACRO=0
MACRO FORWARD_WM_ASKCBFORMATNAME(hwnd, cchMax, rgchName, fn)
    fn hwnd, %WM_ASKCBFORMATNAME, cchMax, rgchName
END MACRO

' void Cls_OnChangeCBChain(HWND hwnd, HWND hwndRemove, HWND hwndNext)
MACRO FUNCTION HANDLE_WM_CHANGECBCHAIN(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, lParam
END MACRO=0
MACRO FORWARD_WM_CHANGECBCHAIN(hwnd, hwndRemove, hwndNext, fn)
    fn hwnd, %WM_CHANGECBCHAIN, hwndRemove, hwndNext
END MACRO

' BOOL Cls_OnSetCursor(HWND hwnd, HWND hwndCursor, UINT codeHitTest, UINT msg)
MACRO HANDLE_WM_SETCURSOR(hwnd, wParam, lParam, fn)=fn(hwnd, wParam, LO(WORD, lParam), HI(WORD, lParam))
MACRO FORWARD_WM_SETCURSOR(hwnd, hwndCursor, codeHitTest, msg, fn)=fn(hwnd, %WM_SETCURSOR, hwndCursor, MAKELPARAM((codeHitTest), (msg)))

' void Cls_OnSysCommand(HWND hwnd, UINT cmd, int x, int y)
MACRO FUNCTION HANDLE_WM_SYSCOMMAND(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, LO(WORD, lParam), HI(WORD, lParam)
END MACRO=0
MACRO FORWARD_WM_SYSCOMMAND(hwnd, cmd, x, y, fn)
    fn hwnd, WM_SYSCOMMAND, cmd, MAKELPARAM(x, y)
END MACRO

' HWND Cls_MDICreate(HWND hwnd, const LPMDICREATESTRUCT lpmcs)
MACRO HANDLE_WM_MDICREATE(hwnd, wParam, lParam, fn)=fn(hwnd, lParam)
MACRO FORWARD_WM_MDICREATE(hwnd, lpmcs, fn)=fn(hwnd, %WM_MDICREATE, 0, lpmcs)

' void Cls_MDIDestroy(HWND hwnd, HWND hwndDestroy)
MACRO FUNCTION HANDLE_WM_MDIDESTROY(hwnd, wParam, lParam, fn)
    fn hwnd, wParam
END MACRO=0
MACRO FORWARD_WM_MDIDESTROY(hwnd, hwndDestroy, fn)
    fn hwnd, %WM_MDIDESTROY, hwndDestroy, 0
END MACRO

' NOTE: Usable only by MDI client windows
' void Cls_MDIActivate(HWND hwnd, BOOL fActive, HWND hwndActivate, HWND hwndDeactivate)
MACRO FUNCTION HANDLE_WM_MDIACTIVATE(hwnd, wParam, lParam, fn)
    fn hwnd, ABS(BITSE(lParam, hwnd, 16)), lParam, wParam
END MACRO=0
MACRO FORWARD_WM_MDIACTIVATE(hwnd, fActive, hwndActivate, hwndDeactivate, fn)
    fn hwnd, %WM_MDIACTIVATE, hwndDeactivate, hwndActivate
END MACRO

' void Cls_MDIRestore(HWND hwnd, HWND hwndRestore)
MACRO FUNCTION HANDLE_WM_MDIRESTORE(hwnd, wParam, lParam, fn)
    fn hwnd, wParam
END MACRO=0
MACRO FORWARD_WM_MDIRESTORE(hwnd, hwndRestore, fn)
    fn hwnd, %WM_MDIRESTORE, hwndRestore, 0
END MACRO

' HWND Cls_MDINext(HWND hwnd, HWND hwndCur, BOOL fPrev)
MACRO HANDLE_WM_MDINEXT(hwnd, wParam, lParam, fn)=fn(hwnd, wParam, lParam)
MACRO FORWARD_WM_MDINEXT(hwnd, hwndCur, fPrev, fn)=fn(hwnd, %WM_MDINEXT, hwndCur, fPrev)

' void Cls_MDIMaximize(HWND hwnd, HWND hwndMaximize)
MACRO HANDLE_WM_MDIMAXIMIZE(hwnd, wParam, lParam, fn)
    fn hwnd, wParam
END MACRO
MACRO FORWARD_WM_MDIMAXIMIZE(hwnd, hwndMaximize, fn)
    fn hwnd, WM_MDIMAXIMIZE, hwndMaximize, 0
END MACRO

' BOOL Cls_MDITile(HWND hwnd, UINT cmd)
MACRO HANDLE_WM_MDITILE(hwnd, wParam, lParam, fn)=fn(hwnd, wParam)
MACRO FORWARD_WM_MDITILE(hwnd, cmd, fn)=fn(hwnd, %WM_MDITILE, cmd, 0)

' BOOL Cls_MDICascade(HWND hwnd, UINT cmd)
MACRO HANDLE_WM_MDICASCADE(hwnd, wParam, lParam, fn)=fn(hwnd, wParam)
MACRO FORWARD_WM_MDICASCADE(hwnd, cmd, fn)=fn(hwnd, %WM_MDICASCADE, cmd, 0)

' void Cls_MDIIconArrange(HWND hwnd)
MACRO FUNCTION HANDLE_WM_MDIICONARRANGE(hwnd, wParam, lParam, fn)
    fn hwnd
END MACRO=0
MACRO FORWARD_WM_MDIICONARRANGE(hwnd, fn)
    fn hwnd, %WM_MDIICONARRANGE, 0, 0
END MACRO

' HWND Cls_MDIGetActive(HWND hwnd)
MACRO HANDLE_WM_MDIGETACTIVE(hwnd, wParam, lParam, fn)=fn(hwnd)
MACRO FORWARD_WM_MDIGETACTIVE(hwnd, fn)=fn(hwnd, %WM_MDIGETACTIVE, 0, 0)

' HMENU Cls_MDISetMenu(HWND hwnd, BOOL fRefresh, HMENU hmenuFrame, HMENU hmenuWindow)
MACRO HANDLE_WM_MDISETMENU(hwnd, wParam, lParam, fn)=fn(hwnd, wParam, wParam, lParam)
MACRO FORWARD_WM_MDISETMENU(hwnd, fRefresh, hmenuFrame, hmenuWindow, fn)=(fn(hwnd, %WM_MDISETMENU, IIF&(fRefresh, hmenuFrame, 0), hmenuWindow)

' void Cls_OnChildActivate(HWND hwnd)
MACRO FUNCTION HANDLE_WM_CHILDACTIVATE(hwnd, wParam, lParam, fn)
    fn hwnd
END MACRO=0
MACRO FORWARD_WM_CHILDACTIVATE(hwnd, fn)
    fn hwnd, %WM_CHILDACTIVATE, 0, 0
END MACRO

' BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
MACRO HANDLE_WM_INITDIALOG(hwnd, wParam, lParam, fn)=fn(hwnd, wParam, lParam)
MACRO FORWARD_WM_INITDIALOG(hwnd, hwndFocus, lParam, fn)=fn(hwnd, %WM_INITDIALOG, hwndFocus, lParam)

' HWND Cls_OnNextDlgCtl(HWND hwnd, HWND hwndSetFocus, BOOL fNext)
MACRO HANDLE_WM_NEXTDLGCTL(hwnd, wParam, lParam, fn)=fn(hwnd), wParam, lParam)
MACRO FORWARD_WM_NEXTDLGCTL(hwnd, hwndSetFocus, fNext, fn)=fn(hwnd, %WM_NEXTDLGCTL, hwndSetFocus, fNext)

' void Cls_OnParentNotify(HWND hwnd, UINT msg, HWND hwndChild, int idChild)
MACRO FUNCTION HANDLE_WM_PARENTNOTIFY(hwnd, wParam, lParam, fn)
    fn hwnd, LO(WORD, wParam), lParam, HI(WORD, wParam)
END MACRO=0
MACRO FORWARD_WM_PARENTNOTIFY(hwnd, msg, hwndChild, idChild, fn)
    fn hwnd, %WM_PARENTNOTIFY, MAKEWPARAM(msg, idChild), hwndChild
END MACRO

' void Cls_OnEnterIdle(HWND hwnd, UINT source, HWND hwndSource)
MACRO FUNCTION HANDLE_WM_ENTERIDLE(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, lParam
END MACRO=0
MACRO FORWARD_WM_ENTERIDLE(hwnd, SOURCE, hwndSource, fn)
    (void)(fn)((hwnd), WM_ENTERIDLE, (WPARAM)(UINT)(SOURCE), (LPARAM)(HWND)(hwndSource))
END MACRO

' UINT Cls_OnGetDlgCode(HWND hwnd, LPMSG lpmsg)
MACRO HANDLE_WM_GETDLGCODE(hwnd, wParam, lParam, fn)=fn(hwnd, lParam)
MACRO FORWARD_WM_GETDLGCODE(hwnd, lpmsg, fn)=fn(hwnd, %WM_GETDLGCODE, IF&(lpmsg, lpmsg->wParam, 0), lpmsg)

' HBRUSH Cls_OnCtlColor(HWND hwnd, HDC hdc, HWND hwndChild, int type)
MACRO HANDLE_WM_CTLCOLORMSGBOX(hwnd, wParam, lParam, fn)=fn(hwnd, wParam, lParam, %CTLCOLOR_MSGBOX)
MACRO FORWARD_WM_CTLCOLORMSGBOX(hwnd, hdc, hwndChild, fn)=fn(hwnd, %WM_CTLCOLORMSGBOX, hdc, hwndChild)

MACRO HANDLE_WM_CTLCOLOREDIT(hwnd, wParam, lParam, fn)=fn(hwnd, wParam, lParam, %CTLCOLOR_EDIT)
MACRO FORWARD_WM_CTLCOLOREDIT(hwnd, hdc, hwndChild, fn)=fn(hwnd, %WM_CTLCOLOREDIT, hdc, hwndChild)

MACRO HANDLE_WM_CTLCOLORLISTBOX(hwnd, wParam, lParam, fn)=fn(hwnd, wParam, lParam, %CTLCOLOR_LISTBOX)
MACRO FORWARD_WM_CTLCOLORLISTBOX(hwnd, hdc, hwndChild, fn)=fn(hwnd, %WM_CTLCOLORLISTBOX, hdc, hwndChild)

MACRO HANDLE_WM_CTLCOLORBTN(hwnd, wParam, lParam, fn)=fn(hwnd, wParam, lParam, %CTLCOLOR_BTN)
MACRO FORWARD_WM_CTLCOLORBTN(hwnd, hdc, hwndChild, fn)=fn(hwnd, %WM_CTLCOLORBTN, hdc, hwndChild)

MACRO HANDLE_WM_CTLCOLORDLG(hwnd, wParam, lParam, fn)=fn(hwnd, wParam, lParam, %CTLCOLOR_DLG)
MACRO FORWARD_WM_CTLCOLORDLG(hwnd, hdc, hwndChild, fn)=fn(hwnd, %WM_CTLCOLORDLG, hdc, hwndChild)

MACRO HANDLE_WM_CTLCOLORSCROLLBAR(hwnd, wParam, lParam, fn)=fn(hwnd, wParam, lParam, %CTLCOLOR_SCROLLBAR)
MACRO FORWARD_WM_CTLCOLORSCROLLBAR(hwnd, hdc, hwndChild, fn)=fn(hwnd, %WM_CTLCOLORSCROLLBAR, hdc, hwndChild)

MACRO HANDLE_WM_CTLCOLORSTATIC(hwnd, wParam, lParam, fn)=fn(hwnd, wParam, lParam, %CTLCOLOR_STATIC)
MACRO FORWARD_WM_CTLCOLORSTATIC(hwnd, hdc, hwndChild, fn)=fn(hwnd, %WM_CTLCOLORSTATIC, hdc, hwndChild)

' void Cls_OnSetFont(HWND hwndCtl, HFONT hfont, BOOL fRedraw)
MACRO FUNCTION HANDLE_WM_SETFONT(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, lParam
END MACRO=0
MACRO FORWARD_WM_SETFONT(hwnd, hfont, fRedraw, fn)
    fn hwnd, %WM_SETFONT, hfont, fRedraw
END MACRO

' HFONT Cls_OnGetFont(HWND hwnd)
MACRO HANDLE_WM_GETFONT(hwnd, wParam, lParam, fn)=fn(hwnd)
MACRO FORWARD_WM_GETFONT(hwnd, fn)=fn(hwnd, %WM_GETFONT, 0, 0)

' void Cls_OnDrawItem(HWND hwnd, const DRAWITEMSTRUCT * lpDrawItem)
MACRO FUNCTION HANDLE_WM_DRAWITEM(hwnd, wParam, lParam, fn)
    fn hwnd, lParam
END MACRO=0
MACRO FORWARD_WM_DRAWITEM(hwnd, lpDrawItem, fn)
    fn hwnd, %WM_DRAWITEM, lpDrawItem.CtlID, lpDrawItem
END MACRO

' void Cls_OnMeasureItem(HWND hwnd, MEASUREITEMSTRUCT * lpMeasureItem)
MACRO FUNCTION HANDLE_WM_MEASUREITEM(hwnd, wParam, lParam, fn)
    fn hwnd, lParam
END MACRO=0
MACRO FORWARD_WM_MEASUREITEM(hwnd, lpMeasureItem, fn)
    fn hwnd, %WM_MEASUREITEM, lpMeasureItem.CtlID, lpMeasureItem
END MACRO

' void Cls_OnDeleteItem(HWND hwnd, const DELETEITEMSTRUCT * lpDeleteItem)
MACRO FUNCTION HANDLE_WM_DELETEITEM(hwnd, wParam, lParam, fn)
    fn hwnd, lParam
END MACRO=0
MACRO FORWARD_WM_DELETEITEM(hwnd, lpDeleteItem, fn)
    fn hwnd, %WM_DELETEITEM, lpDeleteItem).CtlID, lpDeleteItem
END MACRO

' int Cls_OnCompareItem(HWND hwnd, const COMPAREITEMSTRUCT * lpCompareItem)
MACRO HANDLE_WM_COMPAREITEM(hwnd, wParam, lParam, fn)=fn(hwnd, lParam)
MACRO FORWARD_WM_COMPAREITEM(hwnd, lpCompareItem, fn)=fn(hwnd, %WM_COMPAREITEM, lpCompareItem.CtlID, lpCompareItem)

' int Cls_OnVkeyToItem(HWND hwnd, UINT vk, HWND hwndListbox, int iCaret)
MACRO HANDLE_WM_VKEYTOITEM(hwnd, wParam, lParam, fn)=fn(hwnd, LO(WORD, wParam), lParam, HI(INTEGER, wParam))
MACRO FORWARD_WM_VKEYTOITEM(hwnd, vk, hwndListBox, iCaret, fn)=fn(hwnd, %WM_VKEYTOITEM, MAKEWPARAM(vk, iCaret), hwndListBox)

' int Cls_OnCharToItem(HWND hwnd, UINT ch, HWND hwndListbox, int iCaret)
MACRO HANDLE_WM_CHARTOITEM(hwnd, wParam, lParam, fn)=fn(hwnd, LO(WORD, wParam), lParam, HI(INTEGER, wParam))
MACRO FORWARD_WM_CHARTOITEM(hwnd, ch, hwndListBox, iCaret, fn)=fn(hwnd, %WM_CHARTOITEM, MAKEWPARAM(ch, iCaret), hwndListBox)

' void Cls_OnQueueSync(HWND hwnd)
MACRO FUNCTION HANDLE_WM_QUEUESYNC(hwnd, wParam, lParam, fn)
    fn hwnd
END MACRO=0
MACRO FORWARD_WM_QUEUESYNC(hwnd, fn)
    fn hwnd, WM_QUEUESYNC, 0, 0
END MACRO

#IF (%WINVER >= &H030a)
' void Cls_OnCommNotify(HWND hwnd, int cid, UINT flags)
MACRO FUNCTION HANDLE_WM_COMMNOTIFY(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, LO(WORD, lParam)
END MACRO=0
MACRO FORWARD_WM_COMMNOTIFY(hwnd, cid, flags, fn)
    fn hwnd, %WM_COMMNOTIFY, cid, MAKELPARAM(flags, 0
END MACRO
#ENDIF

' void Cls_OnDisplayChange(HWND hwnd, UINT bitsPerPixel, UINT cxScreen, UINT cyScreen)
MACRO FUNCTION HANDLE_WM_DISPLAYCHANGE(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, LO(WORD, lParam), HI(WORD, lParam)
END MACRO=0
MACRO FORWARD_WM_DISPLAYCHANGE(hwnd, bitsPerPixel, cxScreen, cyScreen, fn)
    fn hwnd, %WM_DISPLAYCHANGE, bitsPerPixel, MAKELPARAM(cxScreen, cyScreen)
END MACRO

' BOOL Cls_OnDeviceChange(HWND hwnd, UINT uEvent, DWORD dwEventData)
MACRO HANDLE_WM_DEVICECHANGE(hwnd, wParam, lParam, fn)=fn(hwnd, wParam, wParam)
MACRO FORWARD_WM_DEVICECHANGE(hwnd, uEvent, dwEventData, fn)=fn(hwnd, %WM_DEVICECHANGE, uEvent, dwEventData)

' void Cls_OnContextMenu(HWND hwnd, HWND hwndContext, UINT xPos, UINT yPos)
MACRO FUNCTION HANDLE_WM_CONTEXTMENU(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, LO(WORD, lParam), HI(WORD, lParam)
END MACRO=0
MACRO FORWARD_WM_CONTEXTMENU(hwnd, hwndContext, xPos, yPos, fn)
    fn hwnd, %WM_CONTEXTMENU, hwndContext, MAKELPARAM(xPos, yPos)
END MACRO

MACRO FUNCTION HANDLE_WM_COPYDATA(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, lParam
END MACRO=0
MACRO FORWARD_WM_COPYDATA(hwnd, hwndFrom, pcds, fn)=fn(hwnd, %WM_COPYDATA, hwndFrom, pcds)

' void Cls_OnHotKey(HWND hwnd, int idHotKey, UINT fuModifiers, UINT vk)
MACRO FUNCTION HANDLE_WM_HOTKEY(hwnd, wParam, lParam, fn)
    fn hwnd, wParam, LO(WORD, lParam), HI(WORD, lParam)
END MACRO=0
MACRO FORWARD_WM_HOTKEY(hwnd, idHotKey, fuModifiers, vk, fn)
    fn hwnd, %WM_HOTKEY, idHotKey, MAKELPARAM(fuModifiers, vk)
END MACRO

'***** Static control message APIs *******************************************

MACRO Static_Enable(hwndCtl, fEnable)=EnableWindow(hwndCtl, fEnable)

MACRO Static_GetText(hwndCtl, lpch, cchMax)=GetWindowText(hwndCtl, lpch, cchMax)
MACRO Static_GetTextLength(hwndCtl)=GetWindowTextLength(hwndCtl)
MACRO Static_SetText(hwndCtl, lpsz)=SetWindowText(hwndCtl, lpsz)

MACRO Static_SetIcon(hwndCtl, hIcon)=SendMessage(hwndCtl, %STM_SETICON, hIcon, 0)
MACRO Static_GetIcon(hwndCtl, hIcon)=SendMessage(hwndCtl, %STM_GETICON, 0, 0)

'***** Button control message APIs *******************************************

MACRO Button_Enable(hwndCtl, fEnable)=EnableWindow(hwndCtl, fEnable)

MACRO Button_GetText(hwndCtl, lpch, cchMax)=GetWindowText(hwndCtl, lpch, cchMax)
MACRO Button_GetTextLength(hwndCtl)=GetWindowTextLength(hwndCtl)
MACRO Button_SetText(hwndCtl, lpsz)=SetWindowText(hwndCtl, lpsz)

MACRO Button_GetCheck(hwndCtl)=SendMessage(hwndCtl, %BM_GETCHECK, 0, 0)
MACRO Button_SetCheck(hwndCtl, CHECK)
    SendMessage hwndCtl, %BM_SETCHECK, CHECK, 0
END MACRO

MACRO Button_GetState(hwndCtl)=SendMessage(hwndCtl, %BM_GETSTATE, 0, 0
MACRO Button_SetState(hwndCtl, STATE)=SendMessage(hwndCtl, %BM_SETSTATE, STATE, 0)

MACRO Button_SetStyle(hwndCtl, STYLE, fRedraw)
    SendMessage hwndCtl, %BM_SETSTYLE, LO(WORD, STYLE), MAKELPARAM(IIF&((fRedraw), %TRUE, %FALSE), 0)
END MACRO

'***** Edit control message APIs *********************************************

MACRO Edit_Enable(hwndCtl, fEnable)=EnableWindow(hwndCtl, fEnable)

MACRO Edit_GetText(hwndCtl, lpch, cchMax)=GetWindowText(hwndCtl, lpch, cchMax)
MACRO Edit_GetTextLength(hwndCtl)=GetWindowTextLength(hwndCtl)
MACRO Edit_SetText(hwndCtl, lpsz)=SetWindowText(hwndCtl, lpsz)

MACRO Edit_LimitText(hwndCtl, cchMax)
    SendMessage hwndCtl, %EM_LIMITTEXT, cchMax, 0
END MACRO

MACRO Edit_GetLineCount(hwndCtl)=SendMessage(hwndCtl, %EM_GETLINECOUNT, 0, 0)
#IF NOT %DEF(%MAC)
MACRO FUNCTION Edit_GetLine(hwndCtl, nline, lpch, cchMax)
    POKE LONG, lpch, cchMax
END MACRO=SendMessage(hwndCtl, %EM_GETLINE, nline, lpch)
#ELSE
MACRO FUNCTION Edit_GetLine(hwndCtl, nline, lpch, cchMax)
    POKE WORD, lpch, cchMax
END MACRO=SendMessage(hwndCtl, %EM_GETLINE, nline, lpch)
#ENDIF

MACRO Edit_GetRect(hwndCtl, lprc)
    SendMessage hwndCtl, %EM_GETRECT, 0, lprc
END MACRO
MACRO Edit_SetRect(hwndCtl, lprc)
    SendMessage hwndCtl, %EM_SETRECT, 0, lprc
END MACRO
MACRO Edit_SetRectNoPaint(hwndCtl, lprc)
    SendMessage hwndCtl, %EM_SETRECTNP, 0, lprc
END MACRO

MACRO Edit_GetSel(hwndCtl)=SendMessage(hwndCtl, %EM_GETSEL, 0, 0)
MACRO Edit_SetSel(hwndCtl, ichStart, ichEnd)
    SendMessage hwndCtl, %EM_SETSEL, ichStart, ichEnd
END MACRO
MACRO Edit_ReplaceSel(hwndCtl, lpszReplace)
    SendMessage hwndCtl, %EM_REPLACESEL, 0, lpszReplace
END MACRO

MACRO Edit_GetModify(hwndCtl)=SendMessage(hwndCtl, %EM_GETMODIFY, 0, 0)
MACRO Edit_SetModify(hwndCtl, fModified)
    SendMessage hwndCtl, %EM_SETMODIFY, fModified, 0
END MACRO

MACRO Edit_ScrollCaret(hwndCtl)=SendMessage(hwndCtl, %EM_SCROLLCARET, 0, 0)

MACRO Edit_LineFromChar(hwndCtl, ich)=SendMessage(hwndCtl, %EM_LINEFROMCHAR, ich, 0)
MACRO Edit_LineIndex(hwndCtl, nline)=SendMessage(hwndCtl, %EM_LINEINDEX, nline, 0)
MACRO Edit_LineLength(hwndCtl, nline)=SendMessage(hwndCtl, %EM_LINELENGTH, nline, 0)

MACRO Edit_Scroll(hwndCtl, dv, dh)
    SendMessage hwndCtl, %EM_LINESCROLL, dh, dv
END MACRO

' [legacy]
FUNCTION Edit_LineScroll (BYVAL hEdit AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG
    FUNCTION = SendMessage(hEdit, %EM_LINESCROLL, x, y)
END FUNCTION

MACRO Edit_CanUndo(hwndCtl)=SendMessage(hwndCtl, %EM_CANUNDO, 0, 0)
MACRO Edit_Undo(hwndCtl)=SendMessage(hwndCtl, %EM_UNDO, 0, 0)
MACRO Edit_EmptyUndoBuffer(hwndCtl)
    SendMessage hwndCtl, %EM_EMPTYUNDOBUFFER, 0, 0
END MACRO

MACRO Edit_SetPasswordChar(hwndCtl, ch)
    SendMessage hwndCtl, %EM_SETPASSWORDCHAR, ch, 0
END MACRO

MACRO Edit_SetTabStops(hwndCtl, cTabs, lpTabs)
    SendMessage hwndCtl, %EM_SETTABSTOPS, cTabs, lpTabs
END MACRO

MACRO Edit_FmtLines(hwndCtl, fAddEOL)=SendMessage(hwndCtl, %EM_FMTLINES, fAddEOL, 0)

MACRO Edit_GetHandle(hwndCtl)=SendMessage(hwndCtl, %EM_GETHANDLE, 0, 0)
MACRO Edit_SetHandle(hwndCtl, h)
    SendMessage hwndCtl, %EM_SETHANDLE, h, 0
END MACRO

#IF (%WINVER >= &H030a)
MACRO Edit_GetFirstVisibleLine(hwndCtl)=SendMessage(hwndCtl, %EM_GETFIRSTVISIBLELINE, 0, 0)

MACRO Edit_SetReadOnly(hwndCtl, fReadOnly)=SendMessage(hwndCtl, %EM_SETREADONLY, fReadOnly, 0)

MACRO Edit_GetPasswordChar(hwndCtl)=SendMessage(hwndCtl, %EM_GETPASSWORDCHAR, 0, 0)

MACRO Edit_SetWordBreakProc(hwndCtl, lpfnWordBreak)
    SendMessage hwndCtl, %EM_SETWORDBREAKPROC, 0, lpfnWordBreak
END MACRO
MACRO Edit_GetWordBreakProc(hwndCtl)=SendMessage(hwndCtl, %EM_GETWORDBREAKPROC, 0, 0)
#ENDIF ' %WINVER >= &H030a

'***** ScrollBar control message APIs ****************************************

' NOTE: flags parameter is a collection of ESB_* values, NOT a boolean!
MACRO ScrollBar_Enable(hwndCtl, flags)=EnableScrollBar(hwndCtl, %SB_CTL, flags)

MACRO ScrollBar_Show(hwndCtl, fShow)=ShowWindow(hwndCtl, IFF&(fShow, %SW_SHOWNORMAL, %SW_HIDE)

MACRO ScrollBar_SetPos(hwndCtl, posn, fRedraw)=SetScrollPos(hwndCtl, %SB_CTL, posn, fRedraw)
MACRO ScrollBar_GetPos(hwndCtl)=GetScrollPos(hwndCtl, %SB_CTL)

MACRO ScrollBar_SetRange(hwndCtl, posMin, posMax, fRedraw)=SetScrollRange(hwndCtl, %SB_CTL, posMin, posMax, fRedraw)
MACRO ScrollBar_GetRange(hwndCtl, lpposMin, lpposMax)=GetScrollRange(hwndCtl, %SB_CTL, lpposMin, lpposMax)

'***** ListBox control message APIs ******************************************

MACRO ListBox_Enable(hwndCtl, fEnable)=EnableWindow(hwndCtl, fEnable)

MACRO ListBox_GetCount(hwndCtl)=SendMessage(hwndCtl, %LB_GETCOUNT, 0, 0)
MACRO ListBox_ResetContent(hwndCtl)=SendMessage(hwndCtl, %LB_RESETCONTENT, 0, 0)

FUNCTION Listbox_AddString (BYVAL hwndCtl AS DWORD, BYVAL sText AS STRING) AS LONG
    FUNCTION = SendMessage(hwndCtl, %LB_ADDSTRING, 0, STRPTR(sText))
END FUNCTION

FUNCTION Listbox_InsertString (BYVAL hListBox AS DWORD, BYVAL Index AS DWORD, BYVAL sText AS STRING) AS LONG
    FUNCTION = SendMessage(hListBox, %LB_INSERTSTRING, Index, STRPTR(sText))
END FUNCTION

MACRO ListBox_AddItemData(hwndCtl, pdata)=SendMessage(hwndCtl, %LB_ADDSTRING, 0, pdata)
MACRO ListBox_InsertItemData(hwndCtl, index, pdata)=SendMessage(hwndCtl, %LB_INSERTSTRING, index, pdata)

MACRO ListBox_DeleteString(hwndCtl, index)=SendMessage(hwndCtl, %LB_DELETESTRING, index, 0)

MACRO ListBox_GetTextLen(hwndCtl, index)=SendMessage(hwndCtl, %LB_GETTEXTLEN, index, 0)

FUNCTION Listbox_GetText (BYVAL hListBox AS DWORD, BYVAL Index AS DWORD) AS STRING

    LOCAL sBuffer AS STRING

    IF Index < 0 THEN Index = Listbox_GetCurSel(hListBox)

    sBuffer = NUL$(4096)
    SendMessage hListBox, %LB_GETTEXT, Index, STRPTR(sBuffer)

    Index = INSTR(sBuffer, $NUL)
    IF Index THEN
        FUNCTION = LEFT$(sBuffer, Index - 1)
    ELSE
        FUNCTION = sBuffer
    END IF

END FUNCTION

MACRO ListBox_GetItemData(hwndCtl, index)=SendMessage(hwndCtl, %LB_GETITEMDATA, index, 0)
MACRO ListBox_SetItemData(hwndCtl, index, pdata)=SendMessage(hwndCtl, %LB_SETITEMDATA, index, pdata)

#IF (%WINVER >= &H030a)
FUNCTION Listbox_FindString (BYVAL hwndCtl AS DWORD, BYVAL indexStart AS DWORD, BYVAL szCtStr AS STRING) AS LONG
    FUNCTION = SendMessage(hwndCtl, %LB_FINDSTRING, indexStart, STRPTR(szCtStr))
END FUNCTION

MACRO ListBox_FindItemData(hwndCtl, indexStart, pdata)=SendMessage(hwndCtl, %LB_FINDSTRING, indexStart, pdata)

MACRO ListBox_SetSel(hwndCtl, fSelect, index)=SendMessage(hwndCtl, %LB_SETSEL, fSelect, index)
MACRO ListBox_SelItemRange(hwndCtl, fSelect, first, last)=SendMessage(hwndCtl, %LB_SELITEMRANGE, fSelect, MAKELPARAM((first), (last)))

MACRO ListBox_GetCurSel(hwndCtl)=SendMessage(hwndCtl, %LB_GETCURSEL, 0, 0)
MACRO ListBox_SetCurSel(hwndCtl, index)=SendMessage(hwndCtl, %LB_SETCURSEL, index, 0)

MACRO ListBox_SelectString(hwndCtl, indexStart, lpszFind)=SendMessage(hwndCtl, %LB_SELECTSTRING, indexStart, lpszFind)

MACRO ListBox_SelectItemData(hwndCtl, indexStart, pdata)=SendMessage(hwndCtl, %LB_SELECTSTRING, indexStart, pdata)

MACRO ListBox_GetSel(hwndCtl, index)=SendMessage(hwndCtl, %LB_GETSEL, index, 0)
MACRO ListBox_GetSelCount(hwndCtl)=SendMessage(hwndCtl, %LB_GETSELCOUNT, 0, 0)
MACRO ListBox_GetTopIndex(hwndCtl)=SendMessage(hwndCtl, %LB_GETTOPINDEX, 0, 0)
MACRO ListBox_GetSelItems(hwndCtl, cItems, lpItems)=SendMessage(hwndCtl, %LB_GETSELITEMS, cItems, lpItems)

MACRO ListBox_SetTopIndex(hwndCtl, indexTop)=SendMessage(hwndCtl, %LB_SETTOPINDEX, indexTop, 0)

MACRO ListBox_SetColumnWidth(hwndCtl, cxColumn)
    SendMessage hwndCtl, %LB_SETCOLUMNWIDTH, cxColumn, 0
END MACRO
MACRO ListBox_GetHorizontalExtent(hwndCtl)=SendMessage(hwndCtl, %LB_GETHORIZONTALEXTENT, 0, 0)
MACRO ListBox_SetHorizontalExtent(hwndCtl, cxExtent)
    SendMessage hwndCtl, %LB_SETHORIZONTALEXTENT, cxExtent, 0
END MACRO

MACRO ListBox_SetTabStops(hwndCtl, cTabs, lpTabs)=SendMessage(hwndCtl, %LB_SETTABSTOPS, cTabs, lpTabs)

MACRO ListBox_GetItemRect(hwndCtl, index, lprc)=SendMessage(hwndCtl, %LB_GETITEMRECT, index, lprc)

MACRO ListBox_SetCaretIndex(hwndCtl, index)=SendMessage(hwndCtl, %LB_SETCARETINDEX, index, 0)
MACRO ListBox_GetCaretIndex(hwndCtl)=SendMessage(hwndCtl, %LB_GETCARETINDEX, 0, 0)

FUNCTION Listbox_FindStringExact (BYVAL hListBox AS DWORD, BYVAL indexStart AS DWORD, BYVAL szCtStr AS STRING) AS LONG
    FUNCTION = SendMessage(hListBox, %LB_FINDSTRINGEXACT, indexStart, STRPTR(szCtStr))
END FUNCTION

MACRO ListBox_SetItemHeight(hwndCtl, index, cy)=SendMessage(hwndCtl, %LB_SETITEMHEIGHT, index, MAKELPARAM((cy), 0))
MACRO ListBox_GetItemHeight(hwndCtl, index)=SendMessage(hwndCtl, %LB_GETITEMHEIGHT, index, 0)
#ENDIF  ' %WINVER >= &H030a

FUNCTION Listbox_Dir (BYVAL hwndCtl AS DWORD, BYVAL Attrs AS DWORD, BYVAL FileSpec AS STRING) AS LONG
    FUNCTION = SendMessage(hwndCtl, %LB_DIR, Attrs, STRPTR(FileSpec))
END FUNCTION

'***** ComboBox control message APIs *****************************************

MACRO ComboBox_Enable(hwndCtl, fEnable)=EnableWindow(hwndCtl, fEnable)

MACRO ComboBox_GetText(hwndCtl, lpch, cchMax)=GetWindowText(hwndCtl, lpch, cchMax)
MACRO ComboBox_GetTextLength(hwndCtl)=GetWindowTextLength(hwndCtl)
MACRO ComboBox_SetText(hwndCtl, lpsz)=SetWindowText(hwndCtl, lpsz)

MACRO ComboBox_LimitText(hwndCtl, cchLimit)=SendMessage(hwndCtl, %CB_LIMITTEXT, cchLimit, 0)

MACRO ComboBox_GetEditSel(hwndCtl)=SendMessage(hwndCtl, %CB_GETEDITSEL, 0, 0)
MACRO ComboBox_SetEditSel(hwndCtl, ichStart, ichEnd)=SendMessage(hwndCtl, %CB_SETEDITSEL, 0, MAKELPARAM(ichStart, ichEnd))

MACRO ComboBox_GetCount(hwndCtl)=SendMessage(hwndCtl, %CB_GETCOUNT, 0, 0)
MACRO ComboBox_ResetContent(hwndCtl)=SendMessage(hwndCtl, %CB_RESETCONTENT, 0, 0)

FUNCTION Combo_AddString (BYVAL hComboBox AS DWORD, BYVAL sText AS STRING) AS LONG
    FUNCTION = SendMessage(hComboBox, %CB_ADDSTRING, 0, STRPTR(sText))
END FUNCTION

FUNCTION ComboBox_InsertString (BYVAL hComboBox AS DWORD, BYVAL sText AS STRING) AS LONG
     FUNCTION = SendMessage(hComboBox, %CB_INSERTSTRING, 0, STRPTR(sText))
END FUNCTION

MACRO ComboBox_AddItemData(hwndCtl, pdata)=SendMessage(hwndCtl, %CB_ADDSTRING, 0, pdata)
MACRO ComboBox_InsertItemData(hwndCtl, index, pdata)=SendMessage(hwndCtl, %CB_INSERTSTRING, index, pdata)

MACRO ComboBox_DeleteString(hwndCtl, index)=SendMessage(hwndCtl, %CB_DELETESTRING, index, 0)

MACRO ComboBox_GetLBTextLen(hwndCtl, index)=SendMessage(hwndCtl, %CB_GETLBTEXTLEN, index, 0)

FUNCTION Combo_GetLbText (BYVAL hComboBox AS DWORD, BYVAL Index AS LONG) AS STRING

    LOCAL sText AS STRING

    sText = NUL$(4096)
    SendMessage hComboBox, %CB_GETLBTEXT, Index, STRPTR(sText)

    Index = INSTR(sText, $NUL)
    IF Index THEN
        FUNCTION = LEFT$(sText, Index - 1)
    ELSE
        FUNCTION = sText
    END IF

END FUNCTION

MACRO ComboBox_GetItemData(hwndCtl, index)=SendMessage(hwndCtl, %CB_GETITEMDATA, index, 0)
MACRO ComboBox_SetItemData(hwndCtl, index, pdata)=SendMessage(hwndCtl, %CB_SETITEMDATA, index, pdata)

FUNCTION Combo_FindString (BYVAL hComboBox AS DWORD, BYVAL Start AS LONG, BYVAL sText AS STRING) AS LONG
    FUNCTION = SendMessage(hComboBox, %CB_FINDSTRING, Start, STRPTR(sText))
END FUNCTION

MACRO ComboBox_FindItemData(hwndCtl, indexStart, pdata)=SendMessage(hwndCtl, %CB_FINDSTRING, indexStart, pdata)

MACRO ComboBox_GetCurSel(hwndCtl)=SendMessage(hwndCtl, %CB_GETCURSEL, 0, 0)
MACRO ComboBox_SetCurSel(hwndCtl, index)=SendMessage(hwndCtl, %CB_SETCURSEL, index, 0)

FUNCTION Combo_SelectString (BYVAL hComboBox AS DWORD, BYVAL Index AS DWORD, BYVAL sText AS STRING) AS LONG
    FUNCTION = SendMessage(hComboBox, %CB_SELECTSTRING, Index, STRPTR(sText))
END FUNCTION

MACRO ComboBox_SelectItemData(hwndCtl, indexStart, pdata)=SendMessage(hwndCtl, %CB_SELECTSTRING, indexStart, pdata)

FUNCTION ComboBox_Dir (BYVAL hwndCtl AS DWORD, BYVAL Attrs AS DWORD, BYVAL FileSpec AS STRING) AS LONG
    FUNCTION = SendMessage(hwndCtl, %CB_DIR, Attrs, STRPTR(FileSpec))
END FUNCTION

MACRO ComboBox_ShowDropdown(hwndCtl, fShow)=SendMessage(hwndCtl, %CB_SHOWDROPDOWN, fShow, 0)

#IF (%WINVER >= &H030a)
FUNCTION ComboBox_FindStringExact (BYVAL hComboBox AS DWORD, BYVAL Start AS LONG, BYVAL sText AS STRING) AS LONG
    FUNCTION = SendMessage(hComboBox, %CB_FINDSTRINGEXACT, Start, STRPTR(sText))
END FUNCTION

MACRO ComboBox_GetDroppedState(hwndCtl)=SendMessage(hwndCtl, %CB_GETDROPPEDSTATE, 0, 0)
MACRO ComboBox_GetDroppedControlRect(hwndCtl, lprc)=SendMessage(hwndCtl, %CB_GETDROPPEDCONTROLRECT, 0, lprc)

MACRO ComboBox_GetItemHeight(hwndCtl)=SendMessage(hwndCtl, %CB_GETITEMHEIGHT, 0, 0)
MACRO ComboBox_SetItemHeight(hwndCtl, index, cyItem)=SendMessage(hwndCtl, %CB_SETITEMHEIGHT, index, cyItem)

MACRO ComboBox_GetExtendedUI(hwndCtl)=SendMessage(hwndCtl, %CB_GETEXTENDEDUI, 0, 0)
MACRO ComboBox_SetExtendedUI(hwndCtl, flags)=SendMessage(hwndCtl, %CB_SETEXTENDEDUI, flags, 0)
#ENDIF  ' %WINVER >= &H030a

'***** Alternate porting layer macros *****************************************

' USER MESSAGES:

MACRO GET_WPARAM(wp, lp)=wp
MACRO GET_LPARAM(wp, lp)=lp

MACRO GET_X_LPARAM(lp)=LO(INTEGER, lp)
MACRO GET_Y_LPARAM(lp)=HI(INTEGER, lp)

MACRO GET_WM_ACTIVATE_STATE(wp, lp)=LO(WORD, wp)
MACRO GET_WM_ACTIVATE_FMINIMIZED(wp, lp)=HI(WORD, wp)
MACRO GET_WM_ACTIVATE_HWND(wp, lp)=lp
'macro GET_WM_ACTIVATE_MPS(s, fmin, hwnd)=MAKELONG(s, fmin), hwnd

MACRO FUNCTION GET_WM_CHARTOITEM_CHAR(wp, lp)=LO(WORD, wp)
MACRO GET_WM_CHARTOITEM_POS(wp, lp)=HI(WORD, wp)
MACRO GET_WM_CHARTOITEM_HWND(wp, lp)=lp
'macro GET_WM_CHARTOITEM_MPS(ch, posn, hwnd)=MAKELONG(posn, ch), hwnd

MACRO GET_WM_COMMAND_ID(wp, lp)=LO(WORD, wp)
MACRO GET_WM_COMMAND_HWND(wp, lp)=lp
MACRO GET_WM_COMMAND_CMD(wp, lp)=HI(WORD, wp)
'macro GET_WM_COMMAND_MPS(id, hwnd, cmd)=MAKELONG(id, cmd), hwnd

%WM_CTLCOLOR = &H0019

MACRO GET_WM_CTLCOLOR_HDC(wp, lp, msg)=wp
MACRO GET_WM_CTLCOLOR_HWND(wp, lp, msg)=lp
MACRO GET_WM_CTLCOLOR_TYPE(wp, lp, msg)=(WORD)(msg - %WM_CTLCOLORMSGBOX)
MACRO GET_WM_CTLCOLOR_MSG(ntype)=(%WM_CTLCOLORMSGBOX+(ntype))
'macro GET_WM_CTLCOLOR_MPS(hdc, hwnd, type)=hdc, hwnd


MACRO GET_WM_MENUSELECT_CMD(wp, lp)=LO(WORD, wp)
MACRO GET_WM_MENUSELECT_FLAGS(wp, lp)=HI(WORD, wp)
MACRO GET_WM_MENUSELECT_HMENU(wp, lp)=lp
'macro GET_WM_MENUSELECT_MPS(cmd, f, hmenu)=MAKELONG(cmd, f), hmenu

' Note: the following are for interpreting MDIclient to MDI child messages.
MACRO GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)=ABS(BITSE(lp, hwnd, 16))
MACRO GET_WM_MDIACTIVATE_HWNDDEACT(wp, lp)=wp
MACRO GET_WM_MDIACTIVATE_HWNDACTIVATE(wp, lp)=lp
' Note: the following is for sending to the MDI client window.
'macro GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA)=hwndA, 0

'macro GET_WM_MDISETMENU_MPS(hmenuF, hmenuW)=hmenuF, hmenuW

MACRO GET_WM_MENUCHAR_CHAR(wp, lp)=LO(WORD, wp)
MACRO GET_WM_MENUCHAR_HMENU(wp, lp)=lp
MACRO GET_WM_MENUCHAR_FMENU(wp, lp)=HI(WORD, wp)
'macro GET_WM_MENUCHAR_MPS(ch, hmenu, f)=MAKELONG(ch, f), hmenu

MACRO GET_WM_PARENTNOTIFY_MSG(wp, lp)=LO(WORD, wp)
MACRO GET_WM_PARENTNOTIFY_ID(wp, lp)=HI(WORD, wp)
MACRO GET_WM_PARENTNOTIFY_HWNDCHILD(wp, lp)=lp
MACRO GET_WM_PARENTNOTIFY_X(wp, lp)=LO(INTEGER, lp)
MACRO GET_WM_PARENTNOTIFY_Y(wp, lp)=HI(INTEGER, lp)

'macro GET_WM_PARENTNOTIFY_MPS(msg, id, hwnd)=MAKELONG(id, msg), hwnd
'macro GET_WM_PARENTNOTIFY2_MPS(msg, x, y)=MAKELONG(0, msg), MAKELONG(x, y)

MACRO GET_WM_VKEYTOITEM_CODE(wp, lp)=LO(INTEGER, wp)
MACRO GET_WM_VKEYTOITEM_ITEM(wp, lp)=HI(WORD, wp)
MACRO GET_WM_VKEYTOITEM_HWND(wp, lp)=lp
'macro GET_WM_VKEYTOITEM_MPS(code, item, hwnd)=MAKELONG(item, code), hwnd

MACRO GET_EM_SETSEL_START(wp, lp)=wp
MACRO GET_EM_SETSEL_END(wp, lp)=lp
'macro GET_EM_SETSEL_MPS(iStart, iEnd)=iStart, iEnd

'macro GET_EM_LINESCROLL_MPS(vert, horz)=horz, vert

MACRO GET_WM_CHANGECBCHAIN_HWNDNEXT(wp, lp)=lp

MACRO GET_WM_HSCROLL_CODE(wp, lp)=LO(WORD, wp)
MACRO GET_WM_HSCROLL_POS(wp, lp)=HI(WORD, wp)
MACRO GET_WM_HSCROLL_HWND(wp, lp)=lp
'macro GET_WM_HSCROLL_MPS(code, posn, hwnd)=MAKELONG(code, posn), hwnd

MACRO GET_WM_VSCROLL_CODE(wp, lp)=LO(WORD, wp)
MACRO GET_WM_VSCROLL_POS(wp, lp)=HI(WORD, wp)
MACRO GET_WM_VSCROLL_HWND(wp, lp)=lp
'macro GET_WM_VSCROLL_MPS(code, posn, hwnd)=MAKELONG(code, posn), hwnd

#IF NOT %DEF(%DECLARE_HANDLE32)
%DECLARE_HANDLE32 = 1
MACRO DECLARE_HANDLE32=DECLARE_HANDLE
#ENDIF
