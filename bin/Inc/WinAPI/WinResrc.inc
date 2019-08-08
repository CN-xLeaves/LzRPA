'------------------------------------------------------------------------------
'
'  WinResrc.inc - This module defines the 32-Bit Windows resource codes.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from WinResrc.h dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WINRESRC = 1

#INCLUDE "SdkDdkVer.inc"

#IF NOT %DEF(%WINVER)
%WINVER = &H0500
#ENDIF

#IF NOT %DEF(%WIN32_IE)
%WIN32_IE = &H0501
#ENDIF

#IF NOT %DEF(%WIN32_WINDOWS)
%WIN32_WINDOWS = &H0410
#ENDIF

#IF NOT %DEF(%WIN32_WINNT)
%WIN32_WINNT = &H0500
#ENDIF

'#INCLUDE "winuser.rh.inc"
'#INCLUDE "commctrl.rh.inc"
'#INCLUDE "dde.rh.inc"
'#INCLUDE "winnt.rh.inc"

#INCLUDE "dlgs.inc"
#INCLUDE "winver.inc"
