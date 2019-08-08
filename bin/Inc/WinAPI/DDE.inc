'------------------------------------------------------------------------------
'
'  DDE.inc - Dynamic Data Exchange structures and definitions
'
'  Copyright (c) 2009-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from DDE.h dated 14 Jun 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%DDEHEADER_INCLUDED = 1

#INCLUDE "WinNT.inc"


' begin_r_dde

' DDE window messages

%WM_DDE_FIRST     = &H03E0
%WM_DDE_INITIATE  = (%WM_DDE_FIRST)
%WM_DDE_TERMINATE = (%WM_DDE_FIRST+1)
%WM_DDE_ADVISE    = (%WM_DDE_FIRST+2)
%WM_DDE_UNADVISE  = (%WM_DDE_FIRST+3)
%WM_DDE_ACK       = (%WM_DDE_FIRST+4)
%WM_DDE_DATA      = (%WM_DDE_FIRST+5)
%WM_DDE_REQUEST   = (%WM_DDE_FIRST+6)
%WM_DDE_POKE      = (%WM_DDE_FIRST+7)
%WM_DDE_EXECUTE   = (%WM_DDE_FIRST+8)
%WM_DDE_LAST      = (%WM_DDE_FIRST+8)

' end_r_dde

'-----------------------------------------------------------------------------
'       DDEACK structure
'
'   Structure of wStatus (LOWORD(lParam)) in WM_DDE_ACK message
'       sent in response to a WM_DDE_DATA, WM_DDE_REQUEST, WM_DDE_POKE,
'       WM_DDE_ADVISE, or WM_DDE_UNADVISE message.
'
'-----------------------------------------------------------------------------

#IF NOT %DEF(%MAC)
TYPE DDEACK
    bAppReturnCode AS BIT * 8 IN WORD
    reserved       AS BIT * 6
    fBusy          AS BIT * 1
    fAck           AS BIT * 1
END TYPE
#ELSE
TYPE DDEACK
    usFlags        AS WORD
END TYPE
#ENDIF


'-----------------------------------------------------------------------------
'       DDEADVISE structure
'
'   WM_DDE_ADVISE parameter structure for hOptions (LOWORD(lParam))
'
'-----------------------------------------------------------------------------

#IF NOT %DEF(%MAC)
TYPE DDEADVISE
    reserved  AS BIT * 14 IN WORD
    fDeferUpd AS BIT * 1
    fAckReq   AS BIT * 1
    cfFormat  AS INTEGER
END TYPE
#ELSE
TYPE DDEADVISE
    usFlags   AS WORD
    cfFormat  AS INTEGER
END TYPE
#ENDIF


'-----------------------------------------------------------------------------
'       DDEDATA structure
'
'       WM_DDE_DATA parameter structure for hData (LOWORD(lParam)).
'       The actual size of this structure depends on the size of
'       the Value array.
'
'-----------------------------------------------------------------------------

#IF NOT %DEF(%MAC)
TYPE DDEDATA
    unused    AS BIT * 12 IN WORD
    fResponse AS BIT * 1
    fRelease  AS BIT * 1
    reserved  AS BIT * 1
    fAckReq   AS BIT * 1
    cfFormat  AS INTEGER
    Value(0)  AS BYTE
END TYPE
#ELSE
TYPE DDEDATA
    usFlags   AS WORD
    cfFormat  AS INTEGER
    Value(0)  AS BYTE
END TYPE
#ENDIF


'-----------------------------------------------------------------------------
'   DDEPOKE structure
'
'   WM_DDE_POKE parameter structure for hData (LOWORD(lParam)).
'       The actual size of this structure depends on the size of
'       the Value array.
'
'-----------------------------------------------------------------------------

#IF NOT %DEF(%MAC)
TYPE DDEPOKE
    unused    AS BIT * 13 IN WORD  ' Earlier versions of DDE.H incorrectly
                                    ' 12 unused bits.
    fRelease  AS BIT * 1
    fReserved AS BIT * 2
    cfFormat  AS INTEGER
    Value(0)  AS BYTE               ' This member was named rgb[1] in previous
                                    ' versions of DDE.H
END TYPE
#ELSE
TYPE DDEPOKE
    usFlags   AS WORD
    cfFormat  AS INTEGER
    Value(0)  AS BYTE               ' This member was named rgb[1] in previous
                                    ' versions of DDE.H
END TYPE
#ENDIF

'-----------------------------------------------------------------------------
' The following typedefs were used in previous versions of the Windows SDK.
' They are still valid.  The above typedefs define exactly the same structures
' as those below.  The above typedef names are recommended, however, as they
' are more meaningful.
'
' Note that the DDEPOKE structure typedef'd in earlier versions of DDE.H did
' not correctly define the bit positions.
'-----------------------------------------------------------------------------

#IF NOT %DEF(%MAC)
TYPE DDELN
    unused    AS BIT * 13 IN WORD
    fRelease  AS BIT * 1
    fDeferUpd AS BIT * 1
    fAckReq   AS BIT * 1
    cfFormat  AS INTEGER
END TYPE
#ELSE
TYPE DDELN
    usFlags   AS WORD
    cfFormat  AS INTEGER
END TYPE
#ENDIF

#IF NOT %DEF(%MAC)
TYPE DDEUP
    unused    AS BIT * 12 IN WORD
    fAck      AS BIT * 1
    fRelease  AS BIT * 1
    fReserved AS BIT * 1
    fAckReq   AS BIT * 1
    cfFormat  AS INTEGER
    RGB(0)    AS BYTE
END TYPE
#ELSE
TYPE DDEUP
    usFlags   AS WORD
    cfFormat  AS INTEGER
    RGB(0)    AS BYTE
END TYPE
#ENDIF

'
' DDE SECURITY
'

DECLARE FUNCTION DdeSetQualityOfService LIB "User32.dll" _
    ALIAS "DdeSetQualityOfService" _
    (BYVAL hwndClient AS DWORD, _
    pqosNew  AS SECURITY_QUALITY_OF_SERVICE, _
    pqosPrev AS SECURITY_QUALITY_OF_SERVICE) AS LONG


DECLARE FUNCTION ImpersonateDdeClientWindow LIB "User32.dll" _
    ALIAS "ImpersonateDdeClientWindow" _
    (BYVAL hWndClient AS DWORD, _
    BYVAL hWndServer AS DWORD) AS LONG

'
' DDE message packing APIs
'
DECLARE FUNCTION PackDDElParam LIB "User32.dll" _
    ALIAS "PackDDElParam" (BYVAL msg AS DWORD, BYVAL uiLo AS DWORD, _
    BYVAL uiHi AS DWORD) AS LONG

DECLARE FUNCTION UnpackDDElParam LIB "User32.dll" _
    ALIAS "UnpackDDElParam" (BYVAL msg AS DWORD, BYVAL lParam AS LONG, _
    puiLo AS DWORD, puiHi AS DWORD) AS LONG

DECLARE FUNCTION FreeDDElParam LIB "User32.dll" _
    ALIAS "FreeDDElParam" (BYVAL msg AS DWORD, BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION ReuseDDElParam LIB "User32.dll" _
    ALIAS "ReuseDDElParam" (BYVAL lParam AS LONG, BYVAL msgIn AS DWORD, _
    BYVAL msgOut AS DWORD, BYVAL uiLo AS DWORD, BYVAL uiHi AS DWORD) AS LONG
