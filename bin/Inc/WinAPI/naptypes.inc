'------------------------------------------------------------------------------
'
'  naptypes.inc
'
'  Copyright (c) 2009-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from naptypes.h of 14 Jul 2009
'------------------------------------------------------------------------------

' verify that the <rpcndr.h> version is high enough to compile this file
#IF NOT %DEF(%REQUIRED_RPCNDR_H_VERSION)
%REQUIRED_RPCNDR_H_VERSION = 500
#ENDIF

' verify that the <rpcsal.h> version is high enough to compile this file
#IF NOT %DEF(%REQUIRED_RPCSAL_H_VERSION)
%REQUIRED_RPCSAL_H_VERSION = 100
#ENDIF

#INCLUDE THIS ONCE

'#include "rpc.inc"
'#include "rpcndr.inc"

%naptypes_h = 1

#INCLUDE "WTypes.inc"

' Forward Declarations

' header files for imported files
'#include "oaidl.inc"
'#include "ocidl.inc"


' interface __MIDL_itf_naptypes_0000_0000
' [local]


'extern RPC_IF_HANDLE __MIDL_itf_naptypes_0000_0000_v0_0_c_ifspec;
'extern RPC_IF_HANDLE __MIDL_itf_naptypes_0000_0000_v0_0_s_ifspec;

#IF NOT %DEF(%INapTypes_INTERFACE_DEFINED)
%INapTypes_INTERFACE_DEFINED = 1

' interface INapTypes
' [unique]

%maxSoHAttributeCount    = (100)

%maxSoHAttributeSize = (4000)

%minNetworkSoHSize   = (12)

%maxNetworkSoHSize   = (4000)

%maxDwordCountPerSoHAttribute = (%maxSoHAttributeSize / 4)

%maxIpv4CountPerSoHAttribute = (%maxSoHAttributeSize / 4)

%maxIpv6CountPerSoHAttribute = (%maxSoHAttributeSize / 16)

%maxStringLength = (1024)

%maxStringLengthInBytes  = ((%maxStringLength + 1) * 2)

%maxSystemHealthEntityCount  = (20)

%maxEnforcerCount    = (20)

%maxPrivateDataSize  = (200)

%maxConnectionCountPerEnforcer   = (20)

%maxCachedSoHCount   = ((%maxSystemHealthEntityCount * %maxEnforcerCount) * %maxConnectionCountPerEnforcer)

%freshSoHRequest = (&H1)

%shaFixup    = (&H1)

MACRO IsolationState_enum=LONG
ENUM IsolationState SINGULAR
    isolationStateNotRestricted = 1
    isolationStateInProbation
    isolationStateRestrictedAccess
END ENUM

MACRO ExtendedIsolationState_enum=LONG
ENUM ExtendedIsolationState SINGULAR
    extendedIsolationStateNoData
    extendedIsolationStateTransition
    extendedIsolationStateInfected
    extendedIsolationStateUnknown
END ENUM

MACRO NapTracingLevel_enum=LONG
ENUM NapTracingLevel SINGULAR
    tracingLevelUndefined
    tracingLevelBasic
    tracingLevelAdvanced
    tracingLevelDebug
END ENUM

MACRO ProbationTime=FILETIME

TYPE CountedString
    length  AS WORD
    cstring AS WSTRINGZ PTR
END TYPE

TYPE IsolationInfo
    isolationState AS IsolationState_enum
    probEndTime    AS ProbationTime
    failureUrl     AS CountedString
END TYPE

TYPE IsolationInfoEx
    isolationState         AS IsolationState_enum
    extendedIsolationState AS ExtendedIsolationState_enum
    probEndTime            AS ProbationTime
    failureUrl             AS CountedString
END TYPE

%failureCategoryCount  = ( 5 )

MACRO FailureCategory_enum=LONG
ENUM FailureCategory SINGULAR
    failureCategoryNone
    failureCategoryOther
    failureCategoryClientComponent
    failureCategoryClientCommunication
    failureCategoryServerComponent
    failureCategoryServerCommunication
END ENUM


TYPE FailureCategoryMapping
    mappingCompliance(4) AS LONG
END TYPE

MACRO NapComponentId=DWORD
MACRO SystemHealthEntityId=NapComponentId
MACRO EnforcementEntityId=NapComponentId

%ComponentTypeEnforcementClientSoH   = ( &H1 )

%ComponentTypeEnforcementClientRp    = ( &H2 )

MACRO SystemHealthEntityCount=WORD
MACRO EnforcementEntityCount=WORD

TYPE CorrelationId
    connId    AS GUID
    timeStamp AS FILETIME
END TYPE

MACRO StringCorrelationId=CountedString
MACRO ConnectionId=GUID

%percentageNotSupported  = ( 101 )

MACRO Percentage=BYTE
MACRO MessageId=DWORD

TYPE ResultCodes
    count   AS WORD
    results AS LONG PTR
END TYPE

TYPE Ipv4Address
    ADDR(3) AS BYTE
END TYPE

TYPE Ipv6Address
    ADDR(15) AS BYTE
END TYPE

MACRO FixupState_enum=LONG
ENUM FixupState SINGULAR
    fixupStateSuccess
    fixupStateInProgress
    fixupStateCouldNotUpdate
END ENUM

TYPE FixupInfo_type
    state       AS FixupState_enum
    percentage  AS BYTE
    resultCodes AS ResultCodes
    fixupMsgId  AS DWORD
END TYPE

MACRO NapNotifyType_enum=LONG
ENUM NapNotifyType SINGULAR
    napNotifyTypeUnknown
    napNotifyTypeServiceState
    napNotifyTypeQuarState
END ENUM

TYPE SystemHealthAgentState
    id              AS DWORD
    shaResultCodes  AS ResultCodes
    failureCategory AS FailureCategory_enum
    fixupInfo       AS FixupInfo_type
END TYPE

TYPE SoHAttribute
    ntype  AS WORD
    nsize  AS WORD
    nvalue AS BYTE PTR
END TYPE

TYPE SoH
    count      AS WORD
    attributes AS SoHAttribute PTR
END TYPE

MACRO SoHRequest=SoH

MACRO SoHResponse=SoH

TYPE NetworkSoH
    nsize AS WORD
    ndata AS BYTE PTR
END TYPE

MACRO NetworkSoHRequest=NetworkSoH

MACRO NetworkSoHResponse=NetworkSoH

TYPE PrivateData
    nsize AS WORD
    ndata AS BYTE PTR
END TYPE

TYPE NapComponentRegistrationInfo
    id               AS DWORD
    friendlyName     AS CountedString
    description      AS CountedString
    version          AS CountedString
    vendorName       AS CountedString
    infoClsid        AS GUID
    configClsid      AS GUID
    registrationDate AS FILETIME
    componentType    AS DWORD
END TYPE

MACRO RemoteConfigurationType_enum=LONG
ENUM RemoteConfigurationType SINGULAR
    remoteConfigTypeMachine = 1
    remoteConfigTypeConfigBlob
END ENUM


'extern RPC_IF_HANDLE INapTypes_v0_0_c_ifspec;
'extern RPC_IF_HANDLE INapTypes_v0_0_s_ifspec;
#ENDIF ' %INapTypes_INTERFACE_DEFINED

' Additional Prototypes for ALL interfaces

' end of Additional Prototypes
