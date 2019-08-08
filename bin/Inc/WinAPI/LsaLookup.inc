'------------------------------------------------------------------------------
'
'  LsaLookup.inc -- LSA Policy Lookup API
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 17 Mar 2011
'
'------------------------------------------------------------------------------
'  from LsaLookup.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%LSALOOKUP = 1

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "WinNT.inc"

TYPE UNICODE_STRING
    Length        AS WORD
    MaximumLength AS WORD
    Buffer        AS WSTRINGZ PTR
END TYPE

TYPE LSA_UNICODE_STRING
    UNICODE_STRING
END TYPE

TYPE LSA_STRING
    Length        AS WORD
    MaximumLength AS WORD
    Buffer        AS ASCIIZ PTR
END TYPE

TYPE LSA_OBJECT_ATTRIBUTES
    Length                   AS DWORD
    RootDirectory            AS DWORD  ' HANDLE
    ObjectName               AS LSA_UNICODE_STRING PTR
    Attributes               AS DWORD
    SecurityDescriptor       AS DWORD  ' Points to type SECURITY_DESCRIPTOR
    SecurityQualityOfService AS DWORD  ' Points to type SECURITY_QUALITY_OF_SERVICE
END TYPE

'
' The following data type is used to identify a domain
'

TYPE LSA_TRUST_INFORMATION

    NAME AS LSA_UNICODE_STRING
    pSid  AS SID PTR

END TYPE

' where members have the following usage:
'
'     Name - The name of the domain.
'
'     Sid - A pointer to the Sid of the Domain
'

'
' The following data type is used in name and SID lookup services to
' describe the domains referenced in the lookup operation.
'

TYPE LSA_REFERENCED_DOMAIN_LIST

    Entries AS DWORD
    Domains AS LSA_TRUST_INFORMATION PTR

END TYPE

' where members have the following usage:
'
'     Entries - Is a count of the number of domains described in the
'         Domains array.
'
'     Domains - Is a pointer to an array of Entries LSA_TRUST_INFORMATION data
'         structures.
'

'
' The following data type is used in name to SID lookup services to describe
' the domains referenced in the lookup operation.
'

#IF (%WIN32_WINNT >= &H0501)
TYPE LSA_TRANSLATED_SID2

    Use         AS SID_NAME_USE_enum
    pSid        AS SID PTR
    DomainIndex AS LONG
    Flags       AS DWORD

END TYPE

' where members have the following usage:
'
'     Use - identifies the use of the SID.  If this value is SidUnknown or
'         SidInvalid, then the remainder of the record is not set and
'         should be ignored.
'
'     Sid - Contains the complete Sid of the tranlated SID
'
'     DomainIndex - Is the index of an entry in a related
'         LSA_REFERENCED_DOMAIN_LIST data structure describing the
'         domain in which the account was found.
'
'         If there is no corresponding reference domain for an entry, then
'         this field will contain a negative value.
'
#ENDIF

'
' The following data type is used in SID to name lookup services to
' describe the domains referenced in the lookup operation.
'

TYPE LSA_TRANSLATED_NAME

    Use         AS SID_NAME_USE_enum
    NAME        AS LSA_UNICODE_STRING
    DomainIndex AS LONG

END TYPE

' where the members have the following usage:
'
'     Use - Identifies the use of the name.  If this value is SidUnknown
'         or SidInvalid, then the remainder of the record is not set and
'         should be ignored.  If this value is SidWellKnownGroup then the
'         Name field is invalid, but the DomainIndex field is not.
'
'     Name - Contains the isolated name of the translated SID.
'
'     DomainIndex - Is the index of an entry in a related
'         LSA_REFERENCED_DOMAIN_LIST data structure describing the domain
'         in which the account was found.
'
'         If there is no corresponding reference domain for an entry, then
'         this field will contain a negative value.
'

'
' The following structure specifies the account domain info
' (corresponds to the PolicyAccountDomainInformation information class).
'

TYPE POLICY_ACCOUNT_DOMAIN_INFO

    DomainName AS LSA_UNICODE_STRING
    DomainSid  AS SID PTR

END TYPE

' where the members have the following usage:
'
'     DomainName - Is the name of the domain
'
'     DomainSid - Is the Sid of the domain
'

'
' The following structure corresponds to the PolicyDnsDomainInformation
' information class
'

TYPE POLICY_DNS_DOMAIN_INFO
    NAME          AS LSA_UNICODE_STRING
    DnsDomainName AS LSA_UNICODE_STRING
    DnsForestName AS LSA_UNICODE_STRING
    DomainGuid    AS GUID
    pSid          AS SID PTR
END TYPE

' where the members have the following usage:
'
'      Name - Is the name of the Domain
'
'      DnsDomainName - Is the DNS name of the domain
'
'      DnsForestName - Is the DNS forest name of the domain
'
'      DomainGuid - Is the GUID of the domain
'
'      Sid - Is the Sid of the domain


'
' Access types for the Lookup Policy object
'
' Choose values to correspond to the POLICY_* access types
'

%LOOKUP_VIEW_LOCAL_INFORMATION    = &H00000001
%LOOKUP_TRANSLATE_NAMES           = &H00000800

'
' The following data type defines the classes of Lookup Policy
' Domain Information that may be queried. The values are chosen
' to match corresponding POLICY_INFORMATION_CLASS values.
'

MACRO LSA_LOOKUP_DOMAIN_INFO_CLASS_enum=LONG
ENUM LSA_LOOKUP_DOMAIN_INFO_CLASS SINGULAR
    AccountDomainInformation = 5
    DnsDomainInformation     = 12
END ENUM

'
' Lookup handle
'

'typedef PVOID LSA_LOOKUP_HANDLE, *PLSA_LOOKUP_HANDLE;

' [undocumented functions]

'NTSTATUS
'LsaLookupOpenLocalPolicy(
'    __in     PLSA_OBJECT_ATTRIBUTES ObjectAttributes,
'    __in     ACCESS_MASK AccessMask,
'    __inout  PLSA_LOOKUP_HANDLE PolicyHandle
'    );
'
'NTSTATUS
'LsaLookupClose(
'    __in LSA_LOOKUP_HANDLE ObjectHandle
'    );
'
'NTSTATUS
'LsaLookupTranslateSids(
'    __in  LSA_LOOKUP_HANDLE PolicyHandle,
'    __in  ULONG Count,
'    __in  PSID *Sids,
'    __out PLSA_REFERENCED_DOMAIN_LIST *ReferencedDomains,
'    __out PLSA_TRANSLATED_NAME *Names
'    );
'
'#if (%WIN32_WINNT >= &H0501)
'NTSTATUS
'LsaLookupTranslateNames(
'    __in  LSA_LOOKUP_HANDLE PolicyHandle,
'    __in  ULONG Flags,
'    __in  ULONG Count,
'    __in  PLSA_UNICODE_STRING Names,
'    __out PLSA_REFERENCED_DOMAIN_LIST *ReferencedDomains,
'    __out PLSA_TRANSLATED_SID2 *Sids
'    );
'#endif
'
'NTSTATUS
'LsaLookupGetDomainInfo(
'    __in  LSA_LOOKUP_HANDLE PolicyHandle,
'    __in  LSA_LOOKUP_DOMAIN_INFO_CLASS DomainInfoClass,
'    __out PVOID *DomainInfo
'    );
'
'NTSTATUS
'LsaLookupFreeMemory(
'    __in PVOID Buffer
'    );
