'------------------------------------------------------------------------------
'
'  CPL.inc -- Interface for the Control Panel extension DLL
'
'  Copyright (c) 2002-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from cpl.h of 14 Jul 2009
'------------------------------------------------------------------------------

'  General rules for being installed in the Control Panel:
'
'      1) The DLL must export a function named CPlApplet which will handle
'         the messages discussed below.
'      2) If the applet needs to save information in CONTROL.INI minimize
'         clutter by using the application name [MMCPL.appletname].
'      2) If the applet is refrenced in CONTROL.INI under [MMCPL] use
'         the following form:
'              ...
'              [MMCPL]
'              uniqueName=c:\mydir\myapplet.dll
'              ...
'
'
'  The order in which applet DLLs are loaded by CONTROL.EXE is not guaranteed.
'  Control panels may be sorted for display, etc.


#INCLUDE THIS ONCE

%CPL_INC = 1
%INC_CPL = 1

#INCLUDE "SdkDdkVer.inc"



' Deprecated; control.exe no longer uses these messages
%WM_CPL_LAUNCH      = %WM_USER + 1000
%WM_CPL_LAUNCHED    = %WM_USER + 1001

' A function prototype for CPlApplet()

DECLARE FUNCTION APPLET_PROC (BYVAL hwndCpl AS DWORD, BYVAL msg AS DWORD, _
    BYVAL lParam1 AS DWORD, BYVAL lparam2 AS DWORD) AS LONG

' The data structure CPlApplet() must fill in.

TYPE CPLINFO BYTE
    idIcon AS LONG     ' icon resource id, provided by CPlApplet()
    idName AS LONG     ' name string res. id, provided by CPlApplet()
    idInfo AS LONG     ' info string res. id, provided by CPlApplet()
    lData  AS DWORD    ' user defined data
END TYPE

TYPE NEWCPLINFOA BYTE
    dwsize        AS DWORD          ' similar to the commdlg
    dwflags       AS DWORD
    dwHelpContext AS DWORD          ' help context to use
    lData         AS DWORD          ' user defined data
    hIcon         AS DWORD          ' icon to use, this is owned by CONTROL.EXE (may be deleted)
    szName        AS ASCIIZ * 32    ' short name
    szInfo        AS ASCIIZ * 64    ' long name (status line)
    szHelpFile    AS ASCIIZ * 128   ' path to help file to use
END TYPE

TYPE NEWCPLINFOW BYTE
    dwsize        AS DWORD          ' similar to the commdlg
    dwflags       AS DWORD
    dwHelpContext AS DWORD          ' help context to use
    lData         AS DWORD          ' user defined data
    hIcon         AS DWORD          ' icon to use, this is owned by CONTROL.EXE (may be deleted)
    szName        AS WSTRINGZ * 32  ' short name
    szInfo        AS WSTRINGZ * 64  ' long name (status line)
    szHelpFile    AS WSTRINGZ * 128 ' path to help file to use
END TYPE

#IF %DEF(%UNICODE)
TYPE NEWCPLINFO
    NEWCPLINFOW
END TYPE
#ELSE
TYPE NEWCPLINFO
    NEWCPLINFOA
END TYPE
#ENDIF


#IF %WINVER >= &H0400
%CPL_DYNAMIC_RES = 0
' This constant may be used in place of real resource IDs for the idIcon,
' idName or idInfo members of the CPLINFO structure.  Normally, the system
' uses these values to extract copies of the resources and store them in a
' cache.  Once the resource information is in the cache, the system does not
' need to load a CPL unless the user actually tries to use it.
' %CPL_DYNAMIC_RES tells the system not to cache the resource, but instead to
' load the CPL every time it needs to display information about an item.  This
' allows a CPL to dynamically decide what information will be displayed, but
' is SIGNIFICANTLY SLOWER than displaying information from a cache.
' Typically, %CPL_DYNAMIC_RES is used when a control panel must inspect the
' runtime status of some device in order to provide text or icons to display.
' It should be avoided if possible because of the performance hit to Control
' Panel.

#ENDIF  ' #IF %WINVER >= &H0400


' The messages CPlApplet() must handle:

%CPL_INIT               = 1
' This message is sent to indicate CPlApplet() was found.
' lParam1 and lParam2 are not defined.
' Return TRUE or FALSE indicating whether the control panel should proceed.

%CPL_GETCOUNT           = 2
' This message is sent to determine the number of applets to be displayed.
' lParam1 and lParam2 are not defined.
' Return the number of applets you wish to display in the control
' panel window.


%CPL_INQUIRE            = 3
' This message is sent for information about each applet.
' The return value is ignored.
' lParam1 is the applet number to register, a value from 0 to
' (CPL_GETCOUNT - 1).  lParam2 is a pointer to a CPLINFO structure.
' Fill in CPLINFO's idIcon, idName, idInfo and lData fields with
' the resource id for an icon to display, name and description string ids,
' and a long data item associated with applet #lParam1.  This information
' may be cached by the caller at runtime and/or across sessions.
' To prevent caching, see CPL_DYNAMIC_RES, above.  If the icon, name, and
' description are not dynamic then CPL_DYNAMIC_RES should not be used and the
' CPL_NEWINQURE [sic] message should be ignored


%CPL_SELECT             = 4
' The %CPL_SELECT message is not used.


%CPL_DBLCLK             = 5
' This message is sent when the applet's icon has been double-clicked.
' lParam1 is the applet number which was selected.
' lParam2 is the applet's lData value.
' This message should initiate the applet's dialog box.


%CPL_STOP               = 6
' This message is sent for each applet when the control panel is exiting.
' lParam1 is the applet number.  lParam2 is the applet's lData value.
' Do applet specific cleaning up here.


%CPL_EXIT               = 7
' This message is sent just before the control panel calls FreeLibrary.
' lParam1 and lParam2 are not defined.
' Do non-applet specific cleaning up here.


%CPL_NEWINQUIRE         = 8
' Same as CPL_INQUIRE execpt lParam2 is a pointer to a NEWCPLINFO struct.
' The return value is ignored.
' A CPL should NOT respond to the CPL_NEWINQURE [sic] message unless
' CPL_DYNAMIC_RES is used in CPL_INQUIRE. CPLs which respond to CPL_NEWINQUIRE
' cannot be cached and slow the loading of the Control Panel window.

#IF (%WINVER >= &H0400)
%CPL_STARTWPARMSA       = 9
%CPL_STARTWPARMSW       = 10
#IF %DEF(%UNICODE)
%CPL_STARTWPARMS = %CPL_STARTWPARMSA
#ELSE
%CPL_STARTWPARMS = %CPL_STARTWPARMSA
#ENDIF

' This message parallels %CPL_DBLCLK in that the applet should initiate
' its dialog box.  Where it differs is that this invocation is coming
' out of RUNDLL, and there may be some extra directions for execution.
' lParam1: the applet number.
' lParam2: an LPSTR to any extra directions that might exist.
' returns: %TRUE if the message was handled; %FALSE if not.
'
#ENDIF  ' #IF WINVER >= &H0400


' This message is internal to the Control Panel and MAIN applets.
' It is only sent when an applet is invoked from the Command line
' during system installation.
%CPL_SETUP              = 200
