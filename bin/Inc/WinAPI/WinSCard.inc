'------------------------------------------------------------------------------
'
'  WinSCard.inc
'
'   This header file provides the definitions and symbols necessary for an
'   Application or Smart Card Service Provider to access the Smartcard
'   Subsystem.
'
'  Copyright (c) 1997-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from WinSCard.h dated 18 Jan 2008
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WINSCARD_H = 1

#INCLUDE "wtypes.inc"
#INCLUDE "winioctl.inc"
#INCLUDE "winsmcrd.inc"
#IF NOT %DEF(%SCARD_S_SUCCESS)
#INCLUDE "SCardErr.inc"
#ENDIF

#IF NOT %DEF(%WINSCARDAPI)
%WINSCARDAPI = 1
#ENDIF

' In clr:pure we cannot mark data export with dllimport.
' We should add small functions which returns the value of
' the global.
'
'#if NOT %DEF(%M_CEE_PURE)
'WINSCARDDATA extern const SCARD_IO_REQUEST
'    g_rgSCardT0Pci,
'    g_rgSCardT1Pci,
'    g_rgSCardRawPci;
'#define SCARD_PCI_T0  (&g_rgSCardT0Pci)
'#define SCARD_PCI_T1  (&g_rgSCardT1Pci)
'#define SCARD_PCI_RAW (&g_rgSCardRawPci)
'#endif

'
''''''''''''''''''''''''''''''''''''''''
'
'  Service Manager Access Services
'
'      The following services are used to manage user and terminal contexts for
'      Smart Cards.
'

'typedef ULONG_PTR SCARDCONTEXT;
'typedef SCARDCONTEXT *PSCARDCONTEXT, *LPSCARDCONTEXT;

'typedef ULONG_PTR SCARDHANDLE;
'typedef SCARDHANDLE *PSCARDHANDLE, *LPSCARDHANDLE;

%SCARD_AUTOALLOCATE = &HFFFFFFFF???  ' (DWORD)(-1)

%SCARD_SCOPE_USER     = 0  ' The context is a user context, and any
                           ' database operations are performed within the
                           ' domain of the user.
%SCARD_SCOPE_TERMINAL = 1  ' The context is that of the current terminal,
                           ' and any database operations are performed
                           ' within the domain of that terminal.  (The
                           ' calling application must have appropriate
                           ' access permissions for any database actions.)
%SCARD_SCOPE_SYSTEM   = 2  ' The context is the system context, and any
                           ' database operations are performed within the
                           ' domain of the system.  (The calling
                           ' application must have appropriate access
                           ' permissions for any database actions.)

DECLARE FUNCTION SCardEstablishContext LIB "WinSCard.dll" _
    ALIAS "SCardEstablishContext" (BYVAL dwScope AS DWORD, _
    pvReserved1 AS DWORD, pvReserved2 AS DWORD, phContext AS DWORD) AS LONG

DECLARE FUNCTION SCardReleaseContext LIB "WinSCard.dll" _
    ALIAS "SCardReleaseContext" (BYVAL hContext AS DWORD) AS LONG

DECLARE FUNCTION SCardIsValidContext LIB "WinSCard.dll" _
    ALIAS "SCardIsValidContext" (BYVAL hContext AS DWORD) AS LONG


'
''''''''''''''''''''''''''''''''''''''''
'
'  Smart Card Database Management Services
'
'      The following services provide for managing the Smart Card Database.
'

MACRO SCARD_ALL_READERS      = "SCard$AllReaders" + $NUL
MACRO SCARD_DEFAULT_READERS  = "SCard$DefaultReaders" + $NUL
MACRO SCARD_LOCAL_READERS    = "SCard$LocalReaders" + $NUL
MACRO SCARD_SYSTEM_READERS   = "SCardMACRO SystemReaders" + $NUL

%SCARD_PROVIDER_PRIMARY = 1   ' Primary Provider Id
%SCARD_PROVIDER_CSP     = 2   ' Crypto Service Provider Id
%SCARD_PROVIDER_KSP     = 3   ' Key Storage Provider Id


'
' Database Reader routines
'

DECLARE FUNCTION SCardListReaderGroupsA LIB "WinSCard.dll" _
    ALIAS "SCardListReaderGroupsA" (BYVAL hContext AS DWORD, _
    mszGroups AS ASCIIZ, pcchGroups AS DWORD) AS LONG

DECLARE FUNCTION SCardListReaderGroupsW LIB "WinSCard.dll" _
    ALIAS "SCardListReaderGroupsW" (BYVAL hContext AS DWORD, _
    mszGroups AS WSTRINGZ, pcchGroups AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO SCardListReaderGroups=SCardListReaderGroupsW
#ELSE
MACRO SCardListReaderGroups=SCardListReaderGroupsA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SCardListReadersA LIB "WinSCard.dll" _
    ALIAS "SCardListReadersA" (BYVAL hContext AS DWORD, mszGroups AS ASCIIZ, _
    mszReaders AS ASCIIZ, pcchReaders AS DWORD) AS LONG

DECLARE FUNCTION SCardListReadersW LIB "WinSCard.dll" _
    ALIAS "SCardListReadersW" (BYVAL hContext AS DWORD, _
    mszGroups AS WSTRINGZ, mszReaders AS WSTRINGZ, pcchReaders AS DWORD) _
    AS LONG

#IF %DEF(%UNICODE)
MACRO SCardListReaders=SCardListReadersW
#ELSE
MACRO SCardListReaders=SCardListReadersA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SCardListCardsA LIB "WinSCard.dll" ALIAS "SCardListCardsA" _
    (BYVAL hContext AS DWORD, BYVAL pbAtr AS BYTE PTR, _
    BYVAL rgquidInterfaces AS GUID PTR, BYVAL cguidInterfaceCount AS DWORD, _
    mszCards AS ASCIIZ, pcchCards AS DWORD) AS LONG

DECLARE FUNCTION SCardListCardsW LIB "WinSCard.dll" ALIAS "SCardListCardsW" _
    (BYVAL hContext AS DWORD, BYVAL pbAtr AS BYTE PTR, _
    BYVAL rgquidInterfaces AS GUID PTR, BYVAL cguidInterfaceCount AS DWORD, _
    mszCards AS WSTRINGZ, pcchCards AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO SCardListCards=SCardListCardsW
#ELSE
MACRO SCardListCards=SCardListCardsA
#ENDIF ' NOT %UNICODE

'
' NOTE:    The routine SCardListCards name differs from the PC/SC definition.
'          It should be:
'
'              extern WINSCARDAPI LONG WINAPI
'              SCardListCardTypes(
'                  IN      SCARDCONTEXT hContext,
'                  IN      LPCBYTE pbAtr,
'                  IN      LPCGUID rgquidInterfaces,
'                  IN      DWORD cguidInterfaceCount,
'                  OUT     LPTSTR mszCards,
'                  IN OUT  LPDWORD pcchCards);
'
'          Here's a work-around MACRO:
MACRO SCardListCardTypes=SCardListCards

DECLARE FUNCTION SCardListInterfacesA LIB "WinSCard.dll" _
    ALIAS "SCardListInterfacesA" (BYVAL hContext AS DWORD, szCard AS ASCIIZ, _
    BYVAL pguidInterfaces AS GUID PTR, pcguidInterfaces AS DWORD) AS LONG

DECLARE FUNCTION SCardListInterfacesW LIB "WinSCard.dll" _
    ALIAS "SCardListInterfacesW" (BYVAL hContext AS DWORD, _
    szCard AS WSTRINGZ, BYVAL pguidInterfaces AS GUID PTR, _
    pcguidInterfaces AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO SCardListInterfaces=SCardListInterfacesW
#ELSE
MACRO SCardListInterfaces=SCardListInterfacesA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SCardGetProviderIdA LIB "WinSCard.dll" _
    ALIAS "SCardGetProviderIdA" (BYVAL hContext AS DWORD, szCard AS ASCIIZ, _
    pguidProviderId AS GUID) AS LONG

DECLARE FUNCTION SCardGetProviderIdW LIB "WinSCard.dll" _
    ALIAS "SCardGetProviderIdW" (BYVAL hContext AS DWORD, szCard AS WSTRINGZ, _
    pguidProviderId AS GUID) AS LONG

#IF %DEF(%UNICODE)
MACRO SCardGetProviderId=SCardGetProviderIdW
#ELSE
MACRO SCardGetProviderId=SCardGetProviderIdA
#ENDIF ' NOT %UNICODE
'
' NOTE:    The routine SCardGetProviderId in this implementation uses GUIDs.
'          The PC/SC definition uses BYTEs.
'

DECLARE FUNCTION SCardGetCardTypeProviderNameA LIB "WinSCard.dll" _
    ALIAS "SCardGetCardTypeProviderNameA" (BYVAL hContext AS DWORD, _
    szCardName AS ASCIIZ, BYVAL dwProviderId AS DWORD, szProvider AS ASCIIZ, _
    pcchProviders AS DWORD) AS LONG

DECLARE FUNCTION SCardGetCardTypeProviderNameW LIB "WinSCard.dll" _
    ALIAS "SCardGetCardTypeProviderNameW" (BYVAL hContext AS DWORD, _
    szCardName AS WSTRINGZ, BYVAL dwProviderId AS DWORD, _
    szProvider AS WSTRINGZ, pcchProviders AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO SCardGetCardTypeProviderName=SCardGetCardTypeProviderNameW
#ELSE
MACRO SCardGetCardTypeProviderName=SCardGetCardTypeProviderNameA
#ENDIF ' NOT %UNICODE
'
' NOTE:    This routine is an extension to the PC/SC definitions.
'


'
' Database Writer routines
'

DECLARE FUNCTION SCardIntroduceReaderGroupA LIB "WinSCard.dll" _
    ALIAS "SCardIntroduceReaderGroupA" (BYVAL hContext AS DWORD, _
    szGroupName AS ASCIIZ) AS LONG

DECLARE FUNCTION SCardIntroduceReaderGroupW LIB "WinSCard.dll" _
    ALIAS "SCardIntroduceReaderGroupW" (BYVAL hContext AS DWORD, _
    szGroupName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO SCardIntroduceReaderGroup=SCardIntroduceReaderGroupW
#ELSE
MACRO SCardIntroduceReaderGroup=SCardIntroduceReaderGroupA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SCardForgetReaderGroupA LIB "WinSCard.dll" _
    ALIAS "SCardForgetReaderGroupA" (BYVAL hContext AS DWORD, _
    szGroupName AS ASCIIZ) AS LONG

DECLARE FUNCTION SCardForgetReaderGroupW LIB "WinSCard.dll" _
    ALIAS "SCardForgetReaderGroupW" (BYVAL hContext AS DWORD, _
    szGroupName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO SCardForgetReaderGroup=SCardForgetReaderGroupW
#ELSE
MACRO SCardForgetReaderGroup=SCardForgetReaderGroupA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SCardIntroduceReaderA LIB "WinSCard.dll" _
    ALIAS "SCardIntroduceReaderA" (BYVAL hContext AS DWORD, _
    szReaderName AS ASCIIZ, szDeviceName AS ASCIIZ) AS LONG

DECLARE FUNCTION SCardIntroduceReaderW LIB "WinSCard.dll" _
    ALIAS "SCardIntroduceReaderW" (BYVAL hContext AS DWORD, _
    szReaderName AS WSTRINGZ, szDeviceName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO SCardIntroduceReader=SCardIntroduceReaderW
#ELSE
MACRO SCardIntroduceReader=SCardIntroduceReaderA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SCardForgetReaderA LIB "WinSCard.dll" _
    ALIAS "SCardForgetReaderA" (BYVAL hContext AS DWORD, _
    szReaderName AS ASCIIZ) AS LONG

DECLARE FUNCTION SCardForgetReaderW LIB "WinSCard.dll" _
    ALIAS "SCardForgetReaderW" (BYVAL hContext AS DWORD, _
    szReaderName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO SCardForgetReader=SCardForgetReaderW
#ELSE
MACRO SCardForgetReader=SCardForgetReaderA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SCardAddReaderToGroupA LIB "WinSCard.dll" _
    ALIAS "SCardAddReaderToGroupA" (BYVAL hContext AS DWORD, _
    szReaderName AS ASCIIZ, szGroupName AS ASCIIZ) AS LONG

DECLARE FUNCTION SCardAddReaderToGroupW LIB "WinSCard.dll" _
    ALIAS "SCardAddReaderToGroupW" (BYVAL hContext AS DWORD, _
    szReaderName AS WSTRINGZ, szGroupName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO SCardAddReaderToGroup=SCardAddReaderToGroupW
#ELSE
MACRO SCardAddReaderToGroup=SCardAddReaderToGroupA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SCardRemoveReaderFromGroupA LIB "WinSCard.dll" _
    ALIAS "SCardRemoveReaderFromGroupA" (BYVAL hContext AS DWORD, _
    szReaderName AS ASCIIZ, szGroupName AS ASCIIZ) AS LONG

DECLARE FUNCTION SCardRemoveReaderFromGroupW LIB "WinSCard.dll" _
    ALIAS "SCardRemoveReaderFromGroupW" (BYVAL hContext AS DWORD, _
    szReaderName AS WSTRINGZ, szGroupName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO SCardRemoveReaderFromGroup=SCardRemoveReaderFromGroupW
#ELSE
MACRO SCardRemoveReaderFromGroup=SCardRemoveReaderFromGroupA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SCardIntroduceCardTypeA LIB "WinSCard.dll" _
    ALIAS "SCardIntroduceCardTypeA" (BYVAL hContext AS DWORD, _
    szCardName AS ASCIIZ, pguidPrimaryProvider AS GUID, _
    BYVAL rgGuidInterfaces AS GUID PTR, BYVAL dwInterfaceCount AS DWORD, _
    BYVAL pbAtr AS BYTE PTR, BYVAL pbAtrMask AS BYTE PTR, _
    BYVAL cbAtrLen AS DWORD) AS LONG

DECLARE FUNCTION SCardIntroduceCardTypeW LIB "WinSCard.dll" _
    ALIAS "SCardIntroduceCardTypeW" (BYVAL hContext AS DWORD, _
    szCardName AS WSTRINGZ, pguidPrimaryProvider AS GUID, _
    BYVAL rgGuidInterfaces AS GUID PTR, BYVAL dwInterfaceCount AS DWORD, _
    BYVAL pbAtr AS BYTE PTR, BYVAL pbAtrMask AS BYTE PTR, _
    BYVAL cbAtrLen AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO SCardIntroduceCardType=SCardIntroduceCardTypeW
#ELSE
MACRO SCardIntroduceCardType=SCardIntroduceCardTypeA
#ENDIF ' NOT %UNICODE

'
' NOTE:    The routine SCardIntroduceCardType's parameters' order differs from
'          the PC/SC definition.  It should be:
'
'              extern WINSCARDAPI LONG WINAPI
'              SCardIntroduceCardType(
'                  IN SCARDCONTEXT hContext,
'                  IN LPCTSTR szCardName,
'                  IN LPCBYTE pbAtr,
'                  IN LPCBYTE pbAtrMask,
'                  IN DWORD cbAtrLen,
'                  IN LPCGUID pguidPrimaryProvider,
'                  IN LPCGUID rgguidInterfaces,
'                  IN DWORD dwInterfaceCount);
'
'          Here's a work-around MACRO:
MACRO PCSCardIntroduceCardType(hContext, szCardName, pbAtr, pbAtrMask, cbAtrLen, pguidPrimaryProvider, rgguidInterfaces, dwInterfaceCount)
    SCardIntroduceCardType(hContext, szCardName, pguidPrimaryProvider, rgguidInterfaces, dwInterfaceCount, pbAtr, pbAtrMask, cbAtrLen)
END MACRO

DECLARE FUNCTION SCardSetCardTypeProviderNameA LIB "WinSCard.dll" _
    ALIAS "SCardSetCardTypeProviderNameA" (BYVAL hContext AS DWORD, _
    szCardName AS ASCIIZ, dwProviderId AS DWORD, szProvider AS ASCIIZ) AS LONG

DECLARE FUNCTION SCardSetCardTypeProviderNameW LIB "WinSCard.dll" _
    ALIAS "SCardSetCardTypeProviderNameW" (BYVAL hContext AS DWORD, _
    szCardName AS WSTRINGZ, dwProviderId AS DWORD, szProvider AS WSTRINGZ) _
    AS LONG

#IF %DEF(%UNICODE)
MACRO SCardSetCardTypeProviderName=SCardSetCardTypeProviderNameW
#ELSE
MACRO SCardSetCardTypeProviderName=SCardSetCardTypeProviderNameA
#ENDIF ' NOT %UNICODE
'
' NOTE:    This routine is an extention to the PC/SC specifications.
'

DECLARE FUNCTION SCardForgetCardTypeA LIB "WinSCard.dll" _
    ALIAS "SCardForgetCardTypeA" (BYVAL hContext AS DWORD, _
    szCardName AS ASCIIZ) AS LONG

DECLARE FUNCTION SCardForgetCardTypeW LIB "WinSCard.dll" _
    ALIAS "SCardForgetCardTypeW" (BYVAL hContext AS DWORD, _
    szCardName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO SCardForgetCardType=SCardForgetCardTypeW
#ELSE
MACRO SCardForgetCardType=SCardForgetCardTypeA
#ENDIF ' NOT %UNICODE


'
''''''''''''''''''''''''''''''''''''''''
'
'  Service Manager Support Routines
'
'      The following services are supplied to simplify the use of the Service
'      Manager API.
'

DECLARE FUNCTION SCardFreeMemory LIB "WinSCard.dll" ALIAS "SCardFreeMemory" _
    (BYVAL hContext AS DWORD, pvMem AS DWORD) AS LONG

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)

DECLARE FUNCTION SCardAccessStartedEvent LIB "WinSCard.dll" _
    ALIAS "SCardAccessStartedEvent" () AS DWORD

DECLARE SUB SCardReleaseStartedEvent LIB "WinSCard.dll" _
    ALIAS "SCardReleaseStartedEvent" ()

#ENDIF ' (NTDDI_VERSION >= NTDDI_WINXP)

'
''''''''''''''''''''''''''''''''''''''''
'
'  Reader Services
'
'      The following services supply means for tracking cards within readers.
'

TYPE SCARD_READERSTATEA
    szReader       AS ASCIIZ PTR   ' reader name
    pvUserData     AS DWORD        ' user defined data
    dwCurrentState AS DWORD        ' current state of reader at time of call
    dwEventState   AS DWORD        ' state of reader after state change
    cbAtr          AS DWORD        ' Number of bytes in the returned ATR.
    rgbAtr(35)     AS BYTE         ' Atr of inserted card, (extra alignment bytes)
END TYPE

TYPE SCARD_READERSTATEW
    szReader       AS WSTRINGZ PTR ' reader name
    pvUserData     AS DWORD        ' user defined data
    dwCurrentState AS DWORD        ' current state of reader at time of call
    dwEventState   AS DWORD        ' state of reader after state change
    cbAtr          AS DWORD        ' Number of bytes in the returned ATR.
    rgbAtr(35)     AS BYTE         ' Atr of inserted card, (extra alignment bytes)
END TYPE

#IF %DEF(%UNICODE)
TYPE SCARD_READERSTATE
    SCARD_READERSTATEW
END TYPE
#ELSE
TYPE SCARD_READERSTATE
    SCARD_READERSTATEA
END TYPE
#ENDIF ' UNICODE

' Backwards compatibility macros
MACRO SCARD_READERSTATE_A=SCARD_READERSTATEA
MACRO SCARD_READERSTATE_W=SCARD_READERSTATEW
MACRO PSCARD_READERSTATE_A=PSCARD_READERSTATEA
MACRO PSCARD_READERSTATE_W=PSCARD_READERSTATEW
MACRO LPSCARD_READERSTATE_A=LPSCARD_READERSTATEA
MACRO LPSCARD_READERSTATE_W=LPSCARD_READERSTATEW

%SCARD_STATE_UNAWARE     = &H00000000  ' The application is unaware of the
                                       ' current state, and would like to
                                       ' know.  The use of this value
                                       ' results in an immediate return
                                       ' from state transition monitoring
                                       ' services.  This is represented by
                                       ' all bits set to zero.
%SCARD_STATE_IGNORE      = &H00000001  ' The application requested that
                                       ' this reader be ignored.  No other
                                       ' bits will be set.
%SCARD_STATE_CHANGED     = &H00000002  ' This implies that there is a
                                       ' difference between the state
                                       ' believed by the application, and
                                       ' the state known by the Service
                                       ' Manager.  When this bit is set,
                                       ' the application may assume a
                                       ' significant state change has
                                       ' occurred on this reader.
%SCARD_STATE_UNKNOWN     = &H00000004  ' This implies that the given
                                       ' reader name is not recognized by
                                       ' the Service Manager.  If this bit
                                       ' is set, then SCARD_STATE_CHANGED
                                       ' and SCARD_STATE_IGNORE will also
                                       ' be set.
%SCARD_STATE_UNAVAILABLE = &H00000008  ' This implies that the actual
                                       ' state of this reader is not
                                       ' available.  If this bit is set,
                                       ' then all the following bits are
                                       ' clear.
%SCARD_STATE_EMPTY       = &H00000010  ' This implies that there is not
                                       ' card in the reader.  If this bit
                                       ' is set, all the following bits
                                       ' will be clear.
%SCARD_STATE_PRESENT     = &H00000020  ' This implies that there is a card
                                       ' in the reader.
%SCARD_STATE_ATRMATCH    = &H00000040  ' This implies that there is a card
                                       ' in the reader with an ATR
                                       ' matching one of the target cards.
                                       ' If this bit is set,
                                       ' SCARD_STATE_PRESENT will also be
                                       ' set.  This bit is only returned
                                       ' on the SCardLocateCard() service.
%SCARD_STATE_EXCLUSIVE   = &H00000080  ' This implies that the card in the
                                       ' reader is allocated for exclusive
                                       ' use by another application.  If
                                       ' this bit is set,
                                       ' SCARD_STATE_PRESENT will also be
                                       ' set.
%SCARD_STATE_INUSE       = &H00000100  ' This implies that the card in the
                                       ' reader is in use by one or more
                                       ' other applications, but may be
                                       ' connected to in shared mode.  If
                                       ' this bit is set,
                                       ' SCARD_STATE_PRESENT will also be
                                       ' set.
%SCARD_STATE_MUTE        = &H00000200  ' This implies that the card in the
                                       ' reader is unresponsive or not
                                       ' supported by the reader or
                                       ' software.
%SCARD_STATE_UNPOWERED   = &H00000400  ' This implies that the card in the
                                       ' reader has not been powered up.

DECLARE FUNCTION SCardLocateCardsA LIB "WinSCard.dll" _
    ALIAS "SCardLocateCardsA" (BYVAL hContext AS DWORD, mszCards AS ASCIIZ, _
    BYVAL rgReaderStates AS SCARD_READERSTATEA PTR, BYVAL cReaders AS DWORD) _
    AS LONG

DECLARE FUNCTION SCardLocateCardsW LIB "WinSCard.dll" _
    ALIAS "SCardLocateCardsW" (BYVAL hContext AS DWORD, mszCards AS WSTRINGZ, _
    BYVAL rgReaderStates AS SCARD_READERSTATEW PTR, BYVAL cReaders AS DWORD) _
    AS LONG

#IF %DEF(%UNICODE)
MACRO SCardLocateCards=SCardLocateCardsW
#ELSE
MACRO SCardLocateCards=SCardLocateCardsA
#ENDIF ' NOT %UNICODE

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)

TYPE SCARD_ATRMASK
    cbAtr       AS DWORD   ' Number of bytes in the ATR and the mask.
    rgbAtr(35)  AS BYTE    ' Atr of card (extra alignment bytes)
    rgbMask(35) AS BYTE    ' Mask for the Atr (extra alignment bytes)
END TYPE


DECLARE FUNCTION SCardLocateCardsByATRA LIB "WinSCard.dll" _
    ALIAS "SCardLocateCardsByATRA" (BYVAL hContext AS DWORD, _
    BYVAL rgAtrMasks AS SCARD_ATRMASK PTR, BYVAL cAtrs AS DWORD, _
    BYVAL rgReaderStates AS SCARD_READERSTATEA PTR, BYVAL cReaders AS DWORD) _
    AS LONG

DECLARE FUNCTION SCardLocateCardsByATRW LIB "WinSCard.dll" _
    ALIAS "SCardLocateCardsByATRW" (BYVAL hContext AS DWORD, _
    BYVAL rgAtrMasks AS SCARD_ATRMASK PTR, BYVAL cAtrs AS DWORD, _
    BYVAL rgReaderStates AS SCARD_READERSTATEW PTR, BYVAL cReaders AS DWORD) _
    AS LONG

#IF %DEF(%UNICODE)
MACRO SCardLocateCardsByATR=SCardLocateCardsByATRW
#ELSE
MACRO SCardLocateCardsByATR=SCardLocateCardsByATRA
#ENDIF ' NOT %UNICODE
#ENDIF ' (NTDDI_VERSION >= NTDDI_WINXP)

DECLARE FUNCTION SCardGetStatusChangeA LIB "WinSCard.dll" _
    ALIAS "SCardGetStatusChangeA" (BYVAL hContext AS DWORD, _
    BYVAL dwTimeout AS DWORD, BYVAL rgReaderStates AS SCARD_READERSTATEA PTR, _
    BYVAL cReaders AS DWORD) AS LONG

DECLARE FUNCTION SCardGetStatusChangeW LIB "WinSCard.dll" _
    ALIAS "SCardGetStatusChangeW" (BYVAL hContext AS DWORD, _
    BYVAL dwTimeout AS DWORD, BYVAL rgReaderStates AS SCARD_READERSTATEW PTR, _
    BYVAL cReaders AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO SCardGetStatusChange=SCardGetStatusChangeW
#ELSE
MACRO SCardGetStatusChange=SCardGetStatusChangeA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SCardCancel LIB "WinSCard.dll" ALIAS "SCardCancel" _
    (BYVAL hContext AS DWORD) AS LONG


'
''''''''''''''''''''''''''''''''''''''''
'
'  Card/Reader Communication Services
'
'      The following services provide means for communication with the card.
'

%SCARD_SHARE_EXCLUSIVE = 1 ' This application is not willing to share this
                           ' card with other applications.
%SCARD_SHARE_SHARED    = 2 ' This application is willing to share this
                           ' card with other applications.
%SCARD_SHARE_DIRECT    = 3 ' This application demands direct control of
                           ' the reader, so it is not available to other
                           ' applications.

%SCARD_LEAVE_CARD      = 0 ' Don't do anything special on close
%SCARD_RESET_CARD      = 1 ' Reset the card on close
%SCARD_UNPOWER_CARD    = 2 ' Power down the card on close
%SCARD_EJECT_CARD      = 3 ' Eject the card on close

DECLARE FUNCTION SCardConnectA LIB "WinSCard.dll" ALIAS "SCardConnectA" _
    (BYVAL hContext AS DWORD, szReader AS ASCIIZ, BYVAL dwShareMode AS DWORD, _
    BYVAL dwPreferredProtocols AS DWORD, phCard AS DWORD, _
    pdwActiveProtocol AS DWORD) AS LONG

DECLARE FUNCTION SCardConnectW LIB "WinSCard.dll" ALIAS "SCardConnectW" _
    (BYVAL hContext AS DWORD, szReader AS WSTRINGZ, _
    BYVAL dwShareMode AS DWORD, BYVAL dwPreferredProtocols AS DWORD, _
    phCard AS DWORD, pdwActiveProtocol AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO SCardConnect=SCardConnectW
#ELSE
MACRO SCardConnect=SCardConnectA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SCardReconnect LIB "WinSCard.dll" ALIAS "SCardReconnect" _
    (BYVAL hCard AS DWORD, BYVAL dwShareMode AS DWORD, _
    BYVAL dwPreferredProtocols AS DWORD, BYVAL dwInitialization AS DWORD, _
    pdwActiveProtocol AS DWORD) AS LONG

DECLARE FUNCTION SCardDisconnect LIB "WinSCard.dll" ALIAS "SCardDisconnect" _
    (BYVAL hCard AS DWORD, BYVAL dwDisposition AS DWORD) AS LONG

DECLARE FUNCTION SCardBeginTransaction LIB "WinSCard.dll" _
    ALIAS "SCardBeginTransaction" (BYVAL hCard AS DWORD) AS LONG

DECLARE FUNCTION SCardEndTransaction LIB "WinSCard.dll" _
    ALIAS "SCardEndTransaction" (BYVAL hCard AS DWORD, _
    BYVAL dwDisposition AS DWORD) AS LONG

' [not documented. does not appear to be exported.]
'DECLARE FUNCTION SCardCancelTransaction LIB "WinSCard.dll" _
'    ALIAS "SCardCancelTransaction" (BYVAL hCard AS DWORD) AS LONG

'
' NOTE:    This call corresponds to the PC/SC SCARDCOMM::Cancel routine,
'          terminating a blocked SCardBeginTransaction service.
'


DECLARE FUNCTION SCardState LIB "WinSCard.dll" ALIAS "SCardState" _
    (BYVAL hCard AS DWORD, pdwState AS DWORD, pdwProtocol AS DWORD, _
    BYVAL pbAtr AS BYTE PTR, pcbAtrLen AS DWORD) AS LONG
'
' NOTE:    SCardState is an obsolete routine.  PC/SC has replaced it with
'          SCardStatus.
'

DECLARE FUNCTION SCardStatusA LIB "WinSCard.dll" ALIAS "SCardStatusA" _
    (BYVAL hCard AS DWORD, szReaderName AS ASCIIZ, pcchReaderLen AS DWORD, _
    pdwState AS DWORD, pdwProtocol AS DWORD, BYVAL pbAtr AS BYTE PTR, _
    pcbAtrLen AS DWORD) AS LONG

DECLARE FUNCTION SCardStatusW LIB "WinSCard.dll" ALIAS "SCardStatusW" _
    (BYVAL hCard AS DWORD, szReaderName AS WSTRINGZ, pcchReaderLen AS DWORD, _
    pdwState AS DWORD, pdwProtocol AS DWORD, BYVAL pbAtr AS BYTE PTR, _
    pcbAtrLen AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO SCardStatus=SCardStatusW
#ELSE
MACRO SCardStatus=SCardStatusA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SCardTransmit LIB "WinSCard.dll" ALIAS "SCardTransmit" _
    (BYVAL hCard AS DWORD, pioSendPci AS DWORD, _
    BYVAL pbSendBuffer AS BYTE PTR, BYVAL cbSendLength AS DWORD, _
    pioRecvPci AS DWORD, BYVAL pbRecvBuffer AS BYTE PTR, _
    pcbRecvLength AS DWORD) AS LONG

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

DECLARE FUNCTION SCardGetTransmitCount LIB "WinSCard.dll" _
    ALIAS "SCardGetTransmitCount" (BYVAL hCard AS DWORD, _
    pcTransmitCount AS DWORD) AS LONG

#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)

'
''''''''''''''''''''''''''''''''''''''''
'
'  Reader Control Routines
'
'      The following services provide for direct, low-level manipulation of the
'      reader by the calling application allowing it control over the
'      attributes of the communications with the card.
'

DECLARE FUNCTION SCardControl LIB "WinSCard.dll" ALIAS "SCardControl" _
    (BYVAL hCard AS DWORD, BYVAL dwControlCode AS DWORD, _
    lpInBuffer AS ANY, BYVAL nInBufferSize AS DWORD, lpOutBuffer AS ANY, _
    BYVAL nOutBufferSize AS DWORD, lpBytesReturned AS DWORD) AS LONG

DECLARE FUNCTION SCardGetAttrib LIB "WinSCard.dll" _
    ALIAS "SCardGetAttrib" (BYVAL hCard AS DWORD, BYVAL dwAttrId AS DWORD, _
    BYVAL pbAttr AS BYTE PTR, pcbAttrLen AS DWORD) AS LONG
'
' NOTE:    The routine SCardGetAttrib's name differs from the PC/SC definition.
'          It should be:
'
'              extern WINSCARDAPI LONG WINAPI
'              SCardGetReaderCapabilities(
'                  IN SCARDHANDLE hCard,
'                  IN DWORD dwTag,
'                  OUT LPBYTE pbAttr,
'                  IN OUT LPDWORD pcbAttrLen);
'
'          Here's a work-around MACRO:
MACRO SCardGetReaderCapabilities=SCardGetAttrib

DECLARE FUNCTION SCardSetAttrib LIB "WinSCard.dll" ALIAS "SCardSetAttrib" _
    (BYVAL hCard AS DWORD, BYVAL dwAttrId AS DWORD, BYVAL pbAttr AS BYTE PTR, _
    BYVAL cbAttrLen AS DWORD) AS LONG
'
' NOTE:    The routine SCardSetAttrib's name differs from the PC/SC definition.
'          It should be:
'
'              extern WINSCARDAPI LONG WINAPI
'              SCardSetReaderCapabilities(
'                  IN SCARDHANDLE hCard,
'                  IN DWORD dwTag,
'                  OUT LPBYTE pbAttr,
'                  IN OUT LPDWORD pcbAttrLen);
'
'          Here's a work-around MACRO:
MACRO SCardSetReaderCapabilities=SCardSetAttrib


'
''''''''''''''''''''''''''''''''''''''''
'
'  Smart Card Dialog definitions
'
'      The following section contains structures and  exported function
'      declarations for the Smart Card Common Dialog dialog.
'

' Defined constants
' Flags
%SC_DLG_MINIMAL_UI   = &H01
%SC_DLG_NO_UI        = &H02
%SC_DLG_FORCE_UI     = &H04

%SCERR_NOCARDNAME    = &H4000
%SCERR_NOGUIDS       = &H8000??

'typedef SCARDHANDLE (WINAPI *LPOCNCONNPROCA) (IN SCARDCONTEXT, IN LPSTR, IN LPSTR, IN PVOID);
'typedef SCARDHANDLE (WINAPI *LPOCNCONNPROCW) (IN SCARDCONTEXT, IN LPWSTR, IN LPWSTR, IN PVOID);
#IF %DEF(%UNICODE)
MACRO LPOCNCONNPROC=LPOCNCONNPROCW
#ELSE
MACRO LPOCNCONNPROC=LPOCNCONNPROCA
#ENDIF ' NOT %UNICODE
'typedef BOOL (WINAPI *LPOCNCHKPROC) (IN SCARDCONTEXT, IN SCARDHANDLE, IN PVOID);
'typedef void (WINAPI *LPOCNDSCPROC) (IN SCARDCONTEXT, IN SCARDHANDLE, IN PVOID);


'
' OPENCARD_SEARCH_CRITERIA: In order to specify a user-extended search,
' lpfnCheck must not be NULL.  Moreover, the connection to be made to the
' card before performing the callback must be indicated by either providing
' lpfnConnect and lpfnDisconnect OR by setting dwShareMode.
' If both the connection callbacks and dwShareMode are non-NULL, the callbacks
' will be used.
'

TYPE OPENCARD_SEARCH_CRITERIAA
    dwStructSize         AS DWORD
    lpstrGroupNames      AS ASCIIZ PTR    ' OPTIONAL reader groups to include in
    nMaxGroupNames       AS DWORD         '          search.  NULL defaults to
                                          '          SCard$DefaultReaders
    rgguidInterfaces     AS GUID PTR      ' OPTIONAL requested interfaces
    cguidInterfaces      AS DWORD         '          supported by card's SSP
    lpstrCardNames       AS ASCIIZ PTR    ' OPTIONAL requested card names; all cards w/
    nMaxCardNames        AS DWORD         '          matching ATRs will be accepted
    lpfnCheck            AS DWORD         ' OPTIONAL if NULL no user check will be performed.
    lpfnConnect          AS DWORD         ' OPTIONAL if lpfnConnect is provided,
    lpfnDisconnect       AS DWORD         '          lpfnDisconnect must also be set.
    pvUserData           AS DWORD         ' OPTIONAL parameter to callbacks
    dwShareMode          AS DWORD         ' OPTIONAL must be set if lpfnCheck is not null
    dwPreferredProtocols AS DWORD         ' OPTIONAL
END TYPE

TYPE OPENCARD_SEARCH_CRITERIAW
    dwStructSize         AS DWORD
    lpstrGroupNames      AS WSTRINGZ PTR  ' OPTIONAL reader groups to include in
    nMaxGroupNames       AS DWORD         '          search.  NULL defaults to
                                          '          SCard$DefaultReaders
    rgguidInterfaces     AS GUID PTR      ' OPTIONAL requested interfaces
    cguidInterfaces      AS DWORD         '          supported by card's SSP
    lpstrCardNames       AS WSTRINGZ PTR  ' OPTIONAL requested card names; all cards w/
    nMaxCardNames        AS DWORD         '          matching ATRs will be accepted
    lpfnCheck            AS DWORD         ' OPTIONAL if NULL no user check will be performed.
    lpfnConnect          AS DWORD         ' OPTIONAL if lpfnConnect is provided,
    lpfnDisconnect       AS DWORD         '          lpfnDisconnect must also be set.
    pvUserData           AS DWORD         ' OPTIONAL parameter to callbacks
    dwShareMode          AS DWORD         ' OPTIONAL must be set if lpfnCheck is not null
    dwPreferredProtocols AS DWORD         ' OPTIONAL
END TYPE

#IF %DEF(%UNICODE)
TYPE OPENCARD_SEARCH_CRITERIA
    OPENCARD_SEARCH_CRITERIAW
END TYPE
#ELSE
TYPE OPENCARD_SEARCH_CRITERIA
    OPENCARD_SEARCH_CRITERIAA
END TYPE
#ENDIF ' UNICODE


'
' OPENCARDNAME_EX: used by SCardUIDlgSelectCard; replaces obsolete OPENCARDNAME
'

TYPE OPENCARDNAME_EXA
    dwStructSize            AS DWORD                      ' REQUIRED
    hSCardContext           AS DWORD     ' SCARDCONTEXT   ' REQUIRED
    hwndOwner               AS DWORD                      ' OPTIONAL
    dwFlags                 AS DWORD                      ' OPTIONAL -- default is SC_DLG_MINIMAL_UI
    lpstrTitle              AS ASCIIZ PTR                 ' OPTIONAL
    lpstrSearchDesc         AS ASCIIZ PTR                 ' OPTIONAL (eg. "Please insert your <brandname> smart card.")
    hIcon                   AS DWORD                      ' OPTIONAL 32x32 icon for your brand insignia
    pOpenCardSearchCriteria AS OPENCARD_SEARCH_CRITERIAA PTR ' OPTIONAL
    lpfnConnect             AS DWORD                      ' OPTIONAL - performed on successful selection
    pvUserData              AS DWORD                      ' OPTIONAL parameter to lpfnConnect
    dwShareMode             AS DWORD                      ' OPTIONAL - if lpfnConnect is NULL, dwShareMode and
    dwPreferredProtocols    AS DWORD                      ' OPTIONAL dwPreferredProtocols will be used to
                                                          '    connect to the selected card
    lpstrRdr                AS ASCIIZ PTR                 ' REQUIRED [IN|OUT] Name of selected reader
    nMaxRdr                 AS DWORD                      ' REQUIRED [IN|OUT]
    lpstrCard               AS ASCIIZ PTR                 ' REQUIRED [IN|OUT] Name of selected card
    nMaxCard                AS DWORD                      ' REQUIRED [IN|OUT]
    dwActiveProtocol        AS DWORD                      ' [OUT] set only if dwShareMode not NULL
    hCardHandle             AS DWORD     ' SCARDHANDLE    ' [OUT] set if a card connection was indicated
END TYPE

TYPE OPENCARDNAME_EXW
    dwStructSize            AS DWORD                      ' REQUIRED
    hSCardContext           AS DWORD     ' SCARDCONTEXT   ' REQUIRED
    hwndOwner               AS DWORD                      ' OPTIONAL
    dwFlags                 AS DWORD                      ' OPTIONAL -- default is SC_DLG_MINIMAL_UI
    lpstrTitle              AS WSTRINGZ PTR               ' OPTIONAL
    lpstrSearchDesc         AS WSTRINGZ PTR               ' OPTIONAL (eg. "Please insert your <brandname> smart card.")
    hIcon                   AS DWORD                      ' OPTIONAL 32x32 icon for your brand insignia
    pOpenCardSearchCriteria AS OPENCARD_SEARCH_CRITERIAA PTR ' OPTIONAL
    lpfnConnect             AS DWORD                      ' OPTIONAL - performed on successful selection
    pvUserData              AS DWORD                      ' OPTIONAL parameter to lpfnConnect
    dwShareMode             AS DWORD                      ' OPTIONAL - if lpfnConnect is NULL, dwShareMode and
    dwPreferredProtocols    AS DWORD                      ' OPTIONAL dwPreferredProtocols will be used to
                                                          '    connect to the selected card
    lpstrRdr                AS WSTRINGZ PTR               ' REQUIRED [IN|OUT] Name of selected reader
    nMaxRdr                 AS DWORD                      ' REQUIRED [IN|OUT]
    lpstrCard               AS WSTRINGZ PTR               ' REQUIRED [IN|OUT] Name of selected card
    nMaxCard                AS DWORD                      ' REQUIRED [IN|OUT]
    dwActiveProtocol        AS DWORD                      ' [OUT] set only if dwShareMode not NULL
    hCardHandle             AS DWORD     ' SCARDHANDLE    ' [OUT] set if a card connection was indicated
END TYPE

#IF %DEF(%UNICODE)
TYPE OPENCARDNAME_EX
    OPENCARDNAME_EXW
END TYPE
#ELSE
TYPE OPENCARDNAME_EX
    OPENCARDNAME_EXA
END TYPE
#ENDIF ' UNICODE

TYPE OPENCARDNAMEA_EX
    OPENCARDNAME_EXA
END TYPE
TYPE OPENCARDNAMEW_EX
    OPENCARDNAME_EXW
END TYPE


'
' SCardUIDlgSelectCard replaces GetOpenCardName
'

DECLARE FUNCTION SCardUIDlgSelectCardA LIB "SCardDlg.dll" _
    ALIAS "SCardUIDlgSelectCardA" (lpocn AS OPENCARDNAMEA_EX) AS LONG

DECLARE FUNCTION SCardUIDlgSelectCardW LIB "SCardDlg.dll" _
    ALIAS "SCardUIDlgSelectCardW" (lpocn AS OPENCARDNAMEA_EX) AS LONG

#IF %DEF(%UNICODE)
MACRO SCardUIDlgSelectCard=SCardUIDlgSelectCardW
#ELSE
MACRO SCardUIDlgSelectCard=SCardUIDlgSelectCardA
#ENDIF ' NOT %UNICODE


'
' "Smart Card Common Dialog" definitions for backwards compatibility
'  with the Smart Card Base Services SDK version 1.0
'

TYPE OPENCARDNAMEA
    dwStructSize         AS DWORD
    hwndOwner            AS DWORD
    hSCardContext        AS DWORD  ' SCARDCONTEXT
    lpstrGroupNames      AS ASCIIZ PTR
    nMaxGroupNames       AS DWORD
    lpstrCardNames       AS ASCIIZ PTR
    nMaxCardNames        AS DWORD
    rgguidInterfaces     AS GUID PTR
    cguidInterfaces      AS DWORD
    lpstrRdr             AS ASCIIZ PTR
    nMaxRdr              AS DWORD
    lpstrCard            AS ASCIIZ PTR
    nMaxCard             AS DWORD
    lpstrTitle           AS ASCIIZ PTR
    dwFlags              AS DWORD
    pvUserData           AS DWORD
    dwShareMode          AS DWORD
    dwPreferredProtocols AS DWORD
    dwActiveProtocol     AS DWORD
    lpfnConnect          AS DWORD  ' OCNCONNPROCA PTR
    lpfnCheck            AS DWORD  ' OCNCHKPROC PTR
    lpfnDisconnect       AS DWORD  ' OCNDSCPROC PTR
    hCardHandle          AS DWORD  ' SCARDHANDLE
END TYPE

TYPE OPENCARDNAMEW
    dwStructSize         AS DWORD
    hwndOwner            AS DWORD
    hSCardContext        AS DWORD  ' SCARDCONTEXT
    lpstrGroupNames      AS WSTRINGZ PTR
    nMaxGroupNames       AS DWORD
    lpstrCardNames       AS WSTRINGZ PTR
    nMaxCardNames        AS DWORD
    rgguidInterfaces     AS GUID PTR
    cguidInterfaces      AS DWORD
    lpstrRdr             AS WSTRINGZ PTR
    nMaxRdr              AS DWORD
    lpstrCard            AS WSTRINGZ PTR
    nMaxCard             AS DWORD
    lpstrTitle           AS WSTRINGZ PTR
    dwFlags              AS DWORD
    pvUserData           AS DWORD
    dwShareMode          AS DWORD
    dwPreferredProtocols AS DWORD
    dwActiveProtocol     AS DWORD
    lpfnConnect          AS DWORD  ' OCNCONNPROCW PTR
    lpfnCheck            AS DWORD  ' OCNCHKPROC PTR
    lpfnDisconnect       AS DWORD  ' OCNDSCPROC PTR
    hCardHandle          AS DWORD  ' SCARDHANDLE
END TYPE

#IF %DEF(%UNICODE)
TYPE OPENCARDNAME
    OPENCARDNAMEW
END TYPE
#ELSE
TYPE OPENCARDNAME
    OPENCARDNAMEA
END TYPE
#ENDIF ' UNICODE

' Backwards compatibility macros
MACRO OPENCARDNAME_A=OPENCARDNAMEA
MACRO OPENCARDNAME_W=OPENCARDNAMEW
MACRO POPENCARDNAME_A=POPENCARDNAMEA
MACRO POPENCARDNAME_W=POPENCARDNAMEW
MACRO LPOPENCARDNAME_A=LPOPENCARDNAMEA
MACRO LPOPENCARDNAME_W=LPOPENCARDNAMEW

DECLARE FUNCTION GetOpenCardNameA LIB "SCardDlg.dll" ALIAS "GetOpenCardNameA" _
    (lpocn AS OPENCARDNAMEA) AS LONG

DECLARE FUNCTION GetOpenCardNameW LIB "SCardDlg.dll" ALIAS "GetOpenCardNameW" _
    (lpocn AS OPENCARDNAMEW) AS LONG

#IF %DEF(%UNICODE)
MACRO GetOpenCardName=GetOpenCardNameW
#ELSE
MACRO GetOpenCardName=GetOpenCardNameA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SCardDlgExtendedError LIB "SCardDlg.dll" _
    ALIAS "SCardDlgExtendedError" () AS LONG

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

'
' Smartcard Caching API
'

DECLARE FUNCTION SCardReadCacheA LIB "WinSCard.dll" ALIAS "SCardReadCacheA" _
    (BYVAL hContext AS DWORD, CardIdentifier AS GUID, _
    BYVAL FreshnessCounter AS DWORD, LookupName AS ASCIIZ, _
    BYVAL pData AS BYTE PTR, DataLen AS DWORD) AS LONG

DECLARE FUNCTION SCardReadCacheW LIB "WinSCard.dll" ALIAS "SCardReadCacheW" _
    (BYVAL hContext AS DWORD, CardIdentifier AS GUID, _
    BYVAL FreshnessCounter AS DWORD, LookupName AS WSTRINGZ, _
    BYVAL pData AS BYTE PTR, DataLen AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO SCardReadCache=SCardReadCacheW
#ELSE
MACRO SCardReadCache=SCardReadCacheA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SCardWriteCacheA LIB "WinSCard.dll" _
    ALIAS "SCardWriteCacheA" (BYVAL hContext AS DWORD, _
    CardIdentifier AS GUID, BYVAL FreshnessCounter AS DWORD, _
    LookupName AS ASCIIZ, BYVAL pData AS BYTE PTR, BYVAL DataLen AS DWORD) _
    AS LONG

DECLARE FUNCTION SCardWriteCacheW LIB "WinSCard.dll" _
    ALIAS "SCardWriteCacheW" (BYVAL hContext AS DWORD, _
    CardIdentifier AS GUID, BYVAL FreshnessCounter AS DWORD, _
    LookupName AS WSTRINGZ, BYVAL pData AS BYTE PTR, BYVAL DataLen AS DWORD) _
    AS LONG

#IF %DEF(%UNICODE)
MACRO SCardWriteCache=SCardWriteCacheW
#ELSE
MACRO SCardWriteCache=SCardWriteCacheA
#ENDIF ' NOT %UNICODE

#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)
