'------------------------------------------------------------------------------
'
'  EapTypes.inc  - IDL source for interaction with EAPHost supplicants.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from EapTypes.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%EAPTYPES_H = 1

'#include <guiddef.h>  ' Used by EAP_ERROR structure.


' Properties that EAP Methods support
%eapPropCipherSuiteNegotiation     = &H00000001
%eapPropMutualAuth                 = &H00000002
%eapPropIntegrity                  = &H00000004
%eapPropReplayProtection           = &H00000008
%eapPropConfidentiality            = &H00000010
%eapPropKeyDerivation              = &H00000020
%eapPropKeyStrength64              = &H00000040
%eapPropKeyStrength128             = &H00000080
%eapPropKeyStrength256             = &H00000100
%eapPropKeyStrength512             = &H00000200
%eapPropKeyStrength1024            = &H00000400
%eapPropDictionaryAttackResistance = &H00000800
%eapPropFastReconnect              = &H00001000
%eapPropCryptoBinding              = &H00002000
%eapPropSessionIndependence        = &H00004000
%eapPropFragmentation              = &H00008000
%eapPropChannelBinding             = &H00010000
%eapPropNap                        = &H00020000
%eapPropStandalone                 = &H00040000
%eapPropMppeEncryption             = &H00080000
%eapPropTunnelMethod               = &H00100000
%eapPropSupportsConfig             = &H00200000
%eapPropCertifiedMethod            = &H00400000
%eapPropHiddenMethod               = &H00800000
%eapPropMachineAuth                = &H01000000
%eapPropUserAuth                   = &H02000000
%eapPropIdentityPrivacy            = &H04000000
%eapPropMethodChaining             = &H08000000
%eapPropSharedStateEquivalence     = &H10000000
%eapPropReserved                   = &H80000000???

' Registry NameValue that stores Properties supported by EAP Method
$$EAP_VALUENAME_PROPERTIES = "Properties"$$

MACRO EAP_SESSIONID=DWORD


TYPE EAP_TYPE
    type         AS BYTE
    dwVendorId   AS DWORD
    dwVendorType AS DWORD
END TYPE


' definition of EAP_METHOD_TYPE used for describing an EAP method
TYPE EAP_METHOD_TYPE
    eapType    AS EAP_TYPE
    dwAuthorId AS DWORD
END TYPE


' Information pertaining to each EAP method is populated in this structure format
TYPE EAP_METHOD_INFO
    eaptype          AS EAP_METHOD_TYPE
    pwszAuthorName   AS WSTRINGZ PTR
    pwszFriendlyName AS WSTRINGZ PTR
    eapProperties    AS DWORD
    pInnerMethodInfo AS EAP_METHOD_INFO PTR
END TYPE


' EAPHost populates this array with the information for all the eap-methods installed
' on machine and passes it to a supplicant
'struct _EAP_METHOD_INFO_ARRAY_EX;


TYPE EAP_METHOD_INFO_EX
    eaptype               AS EAP_METHOD_TYPE
    pwszAuthorName        AS WSTRINGZ PTR
    pwszFriendlyName      AS WSTRINGZ PTR
    eapProperties         AS DWORD
    pInnerMethodInfoArray AS DWORD  ' EAP_METHOD_INFO_ARRAY_EX PTR
END TYPE


TYPE EAP_METHOD_INFO_ARRAY
    dwNumberOfMethods AS DWORD
    pEapMethods       AS EAP_METHOD_INFO PTR
END TYPE

' EAPHost populates this error structs with appropriate information and passes it to
' supplicant, which can use this information for error reporting and troubleshooting
TYPE EAP_METHOD_INFO_ARRAY_EX
    dwNumberOfMethods AS DWORD
    pEapMethods       AS EAP_METHOD_INFO_EX PTR
END TYPE

TYPE EAP_ERROR
    dwWinError       AS DWORD
    type             AS EAP_METHOD_TYPE
    dwReasonCode     AS DWORD

    rootCauseGuid    AS GUID
    repairGuid       AS GUID
    helpLinkGuid     AS GUID

    pRootCauseString AS WSTRINGZ PTR
    pRepairString    AS WSTRINGZ PTR
END TYPE


'EXTERN_C const CLSID GUID_EapHost_Default;
'
'EXTERN_C const CLSID GUID_EapHost_Cause_MethodDLLNotFound;
'EXTERN_C const CLSID GUID_EapHost_Cause_EapNegotiationFailed;    '*!*
'EXTERN_C const CLSID GUID_EapHost_Cause_ThirdPartyMethod_Host_Reset;
'EXTERN_C const CLSID GUID_EapHost_Cause_XmlMalformed;
'EXTERN_C const CLSID GUID_EapHost_Cause_MethodDoesNotSupportOperation;
'EXTERN_C const CLSID GUID_EapHost_Cause_EapQecInaccessible;      '*!*
'
'EXTERN_C const CLSID GUID_EapHost_Cause_Generic_AuthFailure;
'EXTERN_C const CLSID GUID_EapHost_Cause_IdentityUnknown;
'
'EXTERN_C const CLSID GUID_EapHost_Cause_CertStoreInaccessible;
'
'EXTERN_C const CLSID GUID_EapHost_Cause_User_CertExpired;
'EXTERN_C const CLSID GUID_EapHost_Cause_User_CertInvalid;
'EXTERN_C const CLSID GUID_EapHost_Cause_User_CertNotFound;
'EXTERN_C const CLSID GUID_EapHost_Cause_User_CertOtherError;
'EXTERN_C const CLSID GUID_EapHost_Cause_User_CertRejected;
'EXTERN_C const CLSID GUID_EapHost_Cause_User_CertRevoked;
'EXTERN_C const CLSID GUID_EapHost_Cause_User_Account_OtherProblem;
'EXTERN_C const CLSID GUID_EapHost_Cause_User_CredsRejected;
'
'EXTERN_C const CLSID GUID_EapHost_Cause_Server_CertExpired;
'EXTERN_C const CLSID GUID_EapHost_Cause_Server_CertInvalid;
'EXTERN_C const CLSID GUID_EapHost_Cause_Server_CertNotFound;
'EXTERN_C const CLSID GUID_EapHost_Cause_Server_CertOtherError;
'EXTERN_C const CLSID GUID_EapHost_Cause_Server_CertRevoked;
'
'EXTERN_C const CLSID GUID_EapHost_Cause_User_Root_CertExpired;
'EXTERN_C const CLSID GUID_EapHost_Cause_User_Root_CertInvalid;
'EXTERN_C const CLSID GUID_EapHost_Cause_User_Root_CertNotFound;
'
'EXTERN_C const CLSID GUID_EapHost_Cause_Server_Root_CertNotFound;
'EXTERN_C const CLSID GUID_EapHost_Cause_Server_Root_CertNameRequired;
'EXTERN_C const CLSID GUID_EapHost_Cause_No_SmartCardReader_Found;
'
'EXTERN_C const CLSID GUID_EapHost_Repair_ContactSysadmin;
'EXTERN_C const CLSID GUID_EapHost_Repair_Retry_Authentication;
'
'EXTERN_C const CLSID GUID_EapHost_Repair_User_AuthFailure;
'EXTERN_C const CLSID GUID_EapHost_Repair_User_GetNewCert;
'EXTERN_C const CLSID GUID_EapHost_Repair_User_SelectValidCert;
'
'EXTERN_C const CLSID GUID_EapHost_Repair_Server_ClientSelectServerCert;
'
'EXTERN_C const CLSID GUID_EapHost_Repair_ContactAdmin_AuthFailure;
'EXTERN_C const CLSID GUID_EapHost_Repair_ContactAdmin_IdentityUnknown;
'EXTERN_C const CLSID GUID_EapHost_Repair_ContactAdmin_NegotiationFailed;
'EXTERN_C const CLSID GUID_EapHost_Repair_ContactAdmin_MethodNotFound;
'EXTERN_C const CLSID GUID_EapHost_Repair_RestartNap;
'EXTERN_C const CLSID GUID_EapHost_Repair_ContactAdmin_CertStoreInaccessible;
'EXTERN_C const CLSID GUID_EapHost_Repair_ContactAdmin_InvalidUserAccount;
'EXTERN_C const CLSID GUID_EapHost_Repair_ContactAdmin_InvalidUserCert;
'EXTERN_C const CLSID GUID_EapHost_Repair_ContactAdmin_RootCertInvalid;
'EXTERN_C const CLSID GUID_EapHost_Repair_ContactAdmin_RootCertNotFound;
'EXTERN_C const CLSID GUID_EapHost_Repair_ContactAdmin_RootExpired;
'EXTERN_C const CLSID GUID_EapHost_Repair_ContactAdmin_CertNameAbsent;
'EXTERN_C const CLSID GUID_EapHost_Repair_ContactAdmin_NoSmartCardReader;
'EXTERN_C const CLSID GUID_EapHost_Repair_Method_Not_Support_Sso;
'
'EXTERN_C const CLSID GUID_EapHost_Help_ObtainingCerts;
'EXTERN_C const CLSID GUID_EapHost_Help_Troubleshooting;
'EXTERN_C const CLSID GUID_EapHost_Cause_Method_Config_Does_Not_Support_Sso;

'--------------------------


' Attributes that EAP Methods support
MACRO EAP_ATTRIBUTE_TYPE_enum=LONG
ENUM EAP_ATTRIBUTE_TYPE SINGULAR
    eatMinimum = 0                 ' Undefined
    eatUserName                    ' Value field is a Pointer
    eatUserPassword                ' Value field is a Pointer
    eatMD5CHAPPassword             ' Value field is a Pointer
    eatNASIPAddress                ' Value field is a 32 bit integral value
    eatNASPort                     ' Value field is a 32 bit integral value
    eatServiceType                 ' Value field is a 32 bit integral value
    eatFramedProtocol              ' Value field is a 32 bit integral value
    eatFramedIPAddress             ' Value field is a 32 bit integral value
    eatFramedIPNetmask             ' Value field is a 32 bit integral value
    eatFramedRouting = 10          ' Value field is a 32 bit integral value
    eatFilterId                    ' Value field is a Pointer
    eatFramedMTU                   ' Value field is a 32 bit integral value
    eatFramedCompression           ' Value field is a 32 bit integral value
    eatLoginIPHost                 ' Value field is a 32 bit integral value
    eatLoginService                ' Value field is a 32 bit integral value
    eatLoginTCPPort                ' Value field is a 32 bit integral value
    eatUnassigned17                ' Undefined
    eatReplyMessage                ' Value field is a Pointer
    eatCallbackNumber              ' Value field is a Pointer
    eatCallbackId =20              ' Value field is a Pointer
    eatUnassigned21                ' Undefined
    eatFramedRoute                 ' Value field is a Pointer
    eatFramedIPXNetwork            ' Value field is a 32 bit integral value
    eatState                       ' Value field is a Pointer
    eatClass                       ' Value field is a Pointer
    eatVendorSpecific              ' Value field is a Pointer
    eatSessionTimeout              ' Value field is a 32 bit integral value
    eatIdleTimeout                 ' Value field is a 32 bit integral value
    eatTerminationAction           ' Value field is a 32 bit integral value
    eatCalledStationId = 30        ' Value field is a Pointer
    eatCallingStationId            ' Value field is a Pointer
    eatNASIdentifier               ' Value field is a Pointer
    eatProxyState                  ' Value field is a Pointer
    eatLoginLATService             ' Value field is a Pointer
    eatLoginLATNode                ' Value field is a Pointer
    eatLoginLATGroup               ' Value field is a Pointer
    eatFramedAppleTalkLink         ' Value field is a 32 bit integral value
    eatFramedAppleTalkNetwork      ' Value field is a 32 bit integral value
    eatFramedAppleTalkZone         ' Value field is a Pointer
    eatAcctStatusType = 40         ' Value field is a 32 bit integral value
    eatAcctDelayTime               ' Value field is a 32 bit integral value
    eatAcctInputOctets             ' Value field is a 32 bit integral value
    eatAcctOutputOctets            ' Value field is a 32 bit integral value
    eatAcctSessionId               ' Value field is a Pointer
    eatAcctAuthentic               ' Value field is a 32 bit integral value
    eatAcctSessionTime             ' Value field is a 32 bit integral value
    eatAcctInputPackets            ' Value field is a 32 bit integral value
    eatAcctOutputPackets           ' Value field is a 32 bit integral value
    eatAcctTerminateCause          ' Value field is a 32 bit integral value
    eatAcctMultiSessionId = 50     ' Value field is a Pointer
    eatAcctLinkCount               ' Value field is a 32 bit integral value
    eatAcctEventTimeStamp = 55     ' Value field is a 32 bit integral value
    eatMD5CHAPChallenge = 60       ' Value field is a Pointer
    eatNASPortType                 ' Value field is a 32 bit integral value
    eatPortLimit                   ' Value field is a 32 bit integral value
    eatLoginLATPort                ' Value field is a Pointer
    eatTunnelType                  ' Value field is a 32 bit integral value
    eatTunnelMediumType            ' Value field is a 32 bit integral value
    eatTunnelClientEndpoint        ' Value field is a Pointer
    eatTunnelServerEndpoint        ' Value field is a Pointer
    eatARAPPassword = 70           ' Value field is a Pointer
    eatARAPFeatures                ' Value field is a Pointer
    eatARAPZoneAccess              ' Value field is a 32 bit integral value
    eatARAPSecurity                ' Value field is a 32 bit integral value
    eatARAPSecurityData            ' Value field is a Pointer
    eatPasswordRetry               ' Value field is a 32 bit integral value
    eatPrompt                      ' Value field is a 32 bit integral value
    eatConnectInfo                 ' Value field is a Pointer
    eatConfigurationToken          ' Value field is a Pointer
    eatEAPMessage                  ' Value field is a Pointer
    eatSignature = 80              ' Value field is a Pointer
    eatARAPChallengeResponse = 84  ' Value field is a Pointer
    eatAcctInterimInterval = 85    ' Value field is a 32 bit integral value
    eatNASIPv6Address = 95         ' Value field is a Pointer
    eatFramedInterfaceId           ' Value field is a Pointer
    eatFramedIPv6Prefix            ' Value field is a Pointer
    eatLoginIPv6Host               ' Value field is a Pointer
    eatFramedIPv6Route             ' Value field is a Pointer
    eatFramedIPv6Pool              ' Value field is a Pointer
    eatARAPGuestLogon = 8096       ' Value field is a 32 bit integral value
    eatCertificateOID              ' Value field is a Pointer
    eatEAPConfiguration            ' Value field is a Pointer
    eatPEAPEmbeddedEAPTypeId       ' Value field is a 32 bit integral value
    eatPEAPFastRoamedSession       ' Value field is a 32 bit integral value
    eatEAPTLV = 8102               ' Value field is a Pointer
    eatCredentialsChanged          ' Value field is a Integer with boolean
                                   ' semantics
    eatInnerEapMethodType          ' Value field is a pointer
                                   ' EapMethodType of the inner method in
                                   ' case of Tunnelled method
    eatClearTextPassword = 8107    ' Value field is a pointer
                                   ' Clear text password that can be used
                                   ' by certain password based eap methods
                                   ' to authenticate a user.
    eatQuarantineSoH     = 8150    ' Value field is a pointer
    eatPeerId            = 9000    ' Value field is a pointer
    eatServerId                    ' Value field is a pointer
    eatMethodId                    ' Value field is a pointer
    eatEMSK                        ' Value field is a pointer
    eatSessionId                   ' Value field is a pointer
    eatReserved = &HFFFFFFFF       ' Undefined
END ENUM  ' EAP_ATTRIBUTE_TYPE  EapAttributeType;


' format for carrying EAP attribute TLV (type, length and value)
TYPE EAP_ATTRIBUTE
    eaType   AS EAP_ATTRIBUTE_TYPE_enum
    dwLength AS DWORD
    pValue   AS BYTE PTR
END TYPE


' List of EAP-attributes
TYPE EAP_ATTRIBUTES
    dwNumberOfAttributes AS DWORD
    pAttribs             AS EAP_ATTRIBUTE PTR
END TYPE


' No UI should be displayed
%EAP_FLAG_Reserved1            = &H00000001
%EAP_FLAG_NON_INTERACTIVE      = &H00000002

' The user data was obtained from Winlogon
%EAP_FLAG_LOGON                = &H00000004

' Show the Credentails UI before authenticating even if cached creds are present
%EAP_FLAG_PREVIEW              = &H00000008

%EAP_FLAG_Reserved2            = &H00000010

' Authentication is for machine, i.e. not for user. Not setting this flag means
' it is user authentication.
%EAP_FLAG_MACHINE_AUTH         = &H00000020

' Request to provide guest access
%EAP_FLAG_GUEST_ACCESS         = &H00000040

%EAP_FLAG_Reserved3            = &H00000080

%EAP_FLAG_Reserved4            = &H00000100

' Indicates this is the first call after m/c resumed from hibernation.
%EAP_FLAG_RESUME_FROM_HIBERNATE= &H00000200

%EAP_FLAG_Reserved5            = &H00000400

%EAP_FLAG_Reserved6            = &H00000800

' Should have this or make it reserved?
%EAP_FLAG_FULL_AUTH            = &H00001000

'/   New EapHost Flags

' Prefer Credentails passed in BeginSession instead of other form of
' credentials, even if config says use certain way of cred retrieval. If this fails, fallback to
' Method specific credentail retrieval
%EAP_FLAG_PREFER_ALT_CREDENTIALS   = &H00002000

%EAP_FLAG_Reserved7                = &H00004000

' To inform the cause of reauth is a NAP callback
%EAP_PEER_FLAG_HEALTH_STATE_CHANGE = &H00008000

' Continue authentication with information available. If can not proceed, fail
' the authentication
%EAP_FLAG_SUPRESS_UI               = &H00010000

' Pre logon scenario like PLAP
%EAP_FLAG_PRE_LOGON                = &H00020000

' User Authentication. For legacy Methods not setting EAP_FLAG_MACHINE_AUTH
' also means user authentication.
%EAP_FLAG_USER_AUTH                = &H00040000

' Config can be viewed but not updated
%EAP_FLAG_CONFG_READONLY           = &H00080000

%EAP_FLAG_Reserved8                = &H00100000

' the various states of the input fields
%EAP_CONFIG_INPUT_FIELD_PROPS_DEFAULT              = &H00000000
%EAP_CONFIG_INPUT_FIELD_PROPS_NON_DISPLAYABLE      = &H00000001

' This specifies that supplicant should cache this field data
%EAP_CONFIG_INPUT_FIELD_PROPS_NON_PERSIST          = &H00000002


' default property value for entries field to be shown in UI
%EAP_UI_INPUT_FIELD_PROPS_DEFAULT         = %EAP_CONFIG_INPUT_FIELD_PROPS_DEFAULT
' To qualify certain entry data on UI is non-displayable (e.g. password)
%EAP_UI_INPUT_FIELD_PROPS_NON_DISPLAYABLE = %EAP_CONFIG_INPUT_FIELD_PROPS_NON_DISPLAYABLE
' This specifies that supplicant should cache this field data
%EAP_UI_INPUT_FIELD_PROPS_NON_PERSIST          = &H00000002
' This specifies that following field is read only (non-editable)
%EAP_UI_INPUT_FIELD_PROPS_READ_ONLY            = &H00000004


' the types of fields that eap can request to show
MACRO EAP_CONFIG_INPUT_FIELD_TYPE_enum=LONG
ENUM EAP_CONFIG_INPUT_FIELD_TYPE SINGULAR
    EapConfigInputUsername
    EapConfigInputPassword
    EapConfigInputNetworkUsername
    EapConfigInputNetworkPassword
    EapConfigInputPin
    EapConfigInputPSK
    EapConfigInputEdit
    EapConfigSmartCardUsername
    EapConfigSmartCardError
END ENUM

%EAP_CREDENTIAL_VERSION                   = 1
%EAP_INTERACTIVE_UI_DATA_VERSION          = 1
%EAPHOST_PEER_API_VERSION                 = 1
%EAPHOST_METHOD_API_VERSION               = 1
%MAX_EAP_CONFIG_INPUT_FIELD_LENGTH        = 256
%MAX_EAP_CONFIG_INPUT_FIELD_VALUE_LENGTH  = 1024


' structure for carrying EAP input field
TYPE EAP_CONFIG_INPUT_FIELD_DATA
    dwSize          AS DWORD
    Type            AS EAP_CONFIG_INPUT_FIELD_TYPE_enum
    dwFlagProps     AS DWORD
    pwszLabel       AS WSTRINGZ PTR
    pwszData        AS WSTRINGZ PTR
    dwMinDataLength AS DWORD
    dwMaxDataLength AS DWORD
END TYPE


' List of EAP input fields
TYPE EAP_CONFIG_INPUT_FIELD_ARRAY
    dwVersion        AS DWORD  ' used for versioning
    dwNumberOfFields AS DWORD
    pFields          AS EAP_CONFIG_INPUT_FIELD_DATA PTR
END TYPE


' provides type of data, EAP_INTERACTIVE_UI_DATA can carry
MACRO EAP_INTERACTIVE_UI_DATA_TYPE_enum=LONG
ENUM EAP_INTERACTIVE_UI_DATA_TYPE SINGULAR
    EapCredReq              ' Credential request during retry
    EapCredResp             ' Credential response during retry
    EapCredExpiryReq        ' Credential request during cred expiry
    EapCredExpiryResp       ' Credential response during cred expiry
    EapCredLogonReq         ' Initial credential request during auth
    EapCredLogonResp        ' Initial credential response during auth
END ENUM


' following determine type of data blob that can be pointed by
' pbUiData member of EAP_INTERACTIVE_UI_DATA
TYPE EAP_CRED_REQ
    EAP_CONFIG_INPUT_FIELD_ARRAY
END TYPE

TYPE EAP_CRED_RESP
    EAP_CONFIG_INPUT_FIELD_ARRAY
END TYPE

TYPE EAP_CRED_LOGON_REQ
    EAP_CONFIG_INPUT_FIELD_ARRAY
END TYPE

TYPE EAP_CRED_LOGON_RESP
    EAP_CONFIG_INPUT_FIELD_ARRAY
END TYPE


' pNewCreds can be NULL in case of EAP_CRED_EXPIRY_REQ
' in case of REQ, pNewCreds can be empty (will not be looked at)
TYPE EAP_CRED_EXPIRY_REQ
    curCreds AS EAP_CONFIG_INPUT_FIELD_ARRAY
    newCreds AS EAP_CONFIG_INPUT_FIELD_ARRAY
END TYPE

UNION EAP_UI_DATA_FORMAT
    credData       AS EAP_CRED_REQ PTR
    credExpiryData AS EAP_CRED_EXPIRY_REQ PTR
    credLogonData  AS EAP_CRED_LOGON_REQ PTR
END UNION


' Data carried from EAP-method to supplicant for interactive UI to raised
TYPE EAP_INTERACTIVE_UI_DATA
    dwVersion  AS DWORD    'specifies version of data structure. It must be 0.
    dwSize     AS DWORD    'specifies size of the entire structure.
    ' this determines what kind of interactive data is passed.
    dwDataType AS EAP_INTERACTIVE_UI_DATA_TYPE_enum
    cbUiData   AS DWORD    ' specifies size of the data pointed by pbUiByte.
    ' pointer to a data blob of a type determined by dwDataType above.
    ' This can be of type EAP_CRED_REQ/EAP_CRED_RESP or
    ' EAP_CRED_EXPIRY_REQ/EAP_CRED_EXPIRY_RESP or
    ' EAP_CRED_LOGON_REQ/EAP_CRED_LOGON_RESP depending on uiDataType above
    pbUiData   AS EAP_UI_DATA_FORMAT
END TYPE

' Property types that EAP methods support
MACRO EAP_METHOD_PROPERTY_TYPE_enum=LONG
ENUM EAP_METHOD_PROPERTY_TYPE SINGULAR
    emptPropCipherSuiteNegotiation = 0      ' value field is boolean
    emptPropMutualAuth                      ' value field is boolean
    emptPropIntegrity                       ' value field is boolean
    emptPropReplayProtection                ' value field is boolean
    emptPropConfidentiality                 ' value field is boolean
    emptPropKeyDerivation                   ' value field is boolean
    emptPropKeyStrength64                   ' value field is boolean
    emptPropKeyStrength128                  ' value field is boolean
    emptPropKeyStrength256                  ' value field is boolean
    emptPropKeyStrength512                  ' value field is boolean
    emptPropKeyStrength1024                 ' value field is boolean
    emptPropDictionaryAttackResistance      ' value field is boolean
    emptPropFastReconnect                   ' value field is boolean
    emptPropCryptoBinding                   ' value field is boolean
    emptPropSessionIndependence             ' value field is boolean
    emptPropFragmentation                   ' value field is boolean
    emptPropChannelBinding                  ' value field is boolean
    emptPropNap                             ' value field is boolean
    emptPropStandalone                      ' value field is boolean
    emptPropMppeEncryption                  ' value field is boolean
    emptPropTunnelMethod                    ' value field is boolean
    emptPropSupportsConfig                  ' value field is boolean
    emptPropCertifiedMethod                 ' value field is boolean
    emptPropHiddenMethod                    ' value field is boolean
    emptPropMachineAuth                     ' value field is boolean
    emptPropUserAuth                        ' value field is boolean
    emptPropIdentityPrivacy                 ' value field is boolean
    emptPropMethodChaining                  ' value field is boolean
    emptPropSharedStateEquivalence          ' value field is boolean
    emptLegacyMethodPropertyFlag = 31       ' value field is dword
    emptPropVendorSpecific = 255            ' value field is string
END ENUM  ' EAP_METHOD_PROPERTY_TYPE

' Method property value types that EAP methods support
MACRO EAP_METHOD_PROPERTY_VALUE_TYPE_enum=LONG
ENUM EAP_METHOD_PROPERTY_VALUE_TYPE SINGULAR
    empvtBool           ' value type is boolean
    empvtDword          ' value type is dword
    empvtString         ' value type is string
END ENUM

TYPE EAP_METHOD_PROPERTY_VALUE_BOOL
    length AS DWORD
    value  AS LONG  ' BOOL
END TYPE

TYPE EAP_METHOD_PROPERTY_VALUE_DWORD
    length AS DWORD
    value  AS DWORD
END TYPE

TYPE EAP_METHOD_PROPERTY_VALUE_STRING
    length AS DWORD
    value  AS BYTE PTR
END TYPE

UNION EAP_METHOD_PROPERTY_VALUE
    empvBool   AS EAP_METHOD_PROPERTY_VALUE_BOOL      ' value is boolean type
    empvDword  AS EAP_METHOD_PROPERTY_VALUE_DWORD     ' value is dword type
    empvString AS EAP_METHOD_PROPERTY_VALUE_STRING    ' value is string type
END UNION

' Structure to represent a method property
TYPE EAP_METHOD_PROPERTY
    ' specifies the method property type
    eapMethodPropertyType      AS EAP_METHOD_PROPERTY_TYPE_enum

    ' specifies the data type of value
    eapMethodPropertyValueType AS EAP_METHOD_PROPERTY_VALUE_TYPE_enum
    ' specifies the value of the method property
    eapMethodPropertyValue     AS EAP_METHOD_PROPERTY_VALUE
END TYPE

' Structure to represent an array of method properties
TYPE EAP_METHOD_PROPERTY_ARRAY
    ' specifies the number of method properties in array
    dwNumberOfProperties AS DWORD

    ' specifies the array of method property
    pMethodProperty      AS EAP_METHOD_PROPERTY PTR
END TYPE
