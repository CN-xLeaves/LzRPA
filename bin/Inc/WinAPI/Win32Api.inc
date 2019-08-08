'------------------------------------------------------------------------------
'
'  Win32Api.inc -- Master file for Windows API declarations for PowerBASIC
'
'  Copyright (C) 1997-2011 PowerBASIC, Inc.
'  Portions Copyright (C) Microsoft Corporation
'  All Rights Reserved.
'
'  Last Update: 03 May 2011
'
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WINAPI = 1



MACRO FUNCTION DWORDSHL(a,b)
    MACROTEMP c
    LOCAL c AS DWORD
    c = a
    SHIFT LEFT c,b
END MACRO=c

MACRO FUNCTION DWORDSHR(a,b)
    MACROTEMP c
    LOCAL c AS DWORD
    c = a
    SHIFT RIGHT c,b
END MACRO=c

#INCLUDE "SdkDdkVer.inc"

#IF NOT %DEF(%NTSTATUS)
#INCLUDE "NTStatus.inc"
%WIN32_NO_STATUS = 1
#ENDIF

#INCLUDE "WinDef.inc"
#INCLUDE "WTypes.inc"

' [These are defined in WinResrc.inc, but we need to put them here first
'  to resolve a circular reference problem]
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

#INCLUDE "WinGDI.inc"
#INCLUDE "WinUser.inc"
#INCLUDE "Excpt.inc"
#INCLUDE "WinResrc.inc"
#INCLUDE "WinBase.inc"
#INCLUDE "WinReg.inc"
#INCLUDE "WinNLS.inc"
#INCLUDE "CommDlg.inc"
#INCLUDE "CommCtrl.inc"
#INCLUDE "ShlObj.inc"
#INCLUDE "ShellApi.inc"
#INCLUDE "Mcx.inc"
#INCLUDE "MMSystem.inc"
#INCLUDE "UrlMon.inc"
#INCLUDE "WindowsX.inc"

' [legacy / backwards compatibility definitions]

%VK_LINEFEED = &H0A
%VK_PGUP = %VK_PRIOR
%VK_PGDN = %VK_NEXT

' File attributes
%ReadOnly = &B000001
%Archive  = &B100000

MACRO GUIDAPI=GUID

TYPE DIOC_REGISTERS
    regEBX   AS DWORD
    regEDX   AS DWORD
    regECX   AS DWORD
    regEAX   AS DWORD
    regEDI   AS DWORD
    regESI   AS DWORD
    regFlags AS DWORD
END TYPE
