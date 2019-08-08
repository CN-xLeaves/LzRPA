'------------------------------------------------------------------------------
'
'  MswSockDef.inc -- helper for MsWSock.inc socket definitions
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from MswSockDef.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%MSWSOCKDEF = 1

#INCLUDE "SdkDdkVer.inc"

#IF (%WIN32_WINNT >= &H0600)

'#if %def(%WS2DEF)
'
'extern CONST UCHAR sockaddr_size[AF_MAX];
'
'MSWSOCKDEF_INLINE
'UCHAR
'SOCKADDR_SIZE(__in ADDRESS_FAMILY af)
'{
'    return (UCHAR)((af < AF_MAX) ? sockaddr_size[af]
'                                 : sockaddr_size[AF_UNSPEC]);
'}
'
'MSWSOCKDEF_INLINE
'SCOPE_LEVEL
'ScopeLevel(
'    __in SCOPE_ID ScopeId
'    )
'{
'    '
'    ' We can't declare the Level field of type SCOPE_LEVEL directly,
'    ' since it gets sign extended to be negative.  We can, however,
'    ' safely cast.
'    '
'    return (SCOPE_LEVEL)ScopeId.Level;
'}
'
'#endif ' %WS2DEF

%SIO_SET_COMPATIBILITY_MODE = &H9800012C???  ' _WSAIOW(IOC_VENDOR,300)

MACRO WSA_COMPATIBILITY_BEHAVIOR_ID_enum=LONG
ENUM WSA_COMPATIBILITY_BEHAVIOR_ID SINGULAR
    WsaBehaviorAll
    WsaBehaviorReceiveBuffering
    WsaBehaviorAutoTuning
END ENUM

TYPE WSA_COMPATIBILITY_MODE
    BehaviorId      AS WSA_COMPATIBILITY_BEHAVIOR_ID_enum
    TargetOsVersion AS DWORD
END TYPE

#ENDIF ' (%WIN32_WINNT>=&H0600)
