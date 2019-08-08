'------------------------------------------------------------------------------
'
'  ACLAPI.inc -- Definitions for the Win32 Access Control APIS
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from aclapi.h build version 0001 of 14 Jul 2009
'------------------------------------------------------------------------------


#INCLUDE THIS ONCE

%ACLAPI_INC = 1

#INCLUDE "WinNT.inc"
#INCLUDE "AccCtrl.inc"


'
' Progress Function:
' Caller of tree operation implements this Progress function, then
' passes its function pointer to tree operation.
' Tree operation invokes Progress function to provide progress and error
' information to the caller during the potentially long execution
' of the tree operation.  Tree operation provides the name of the object
' last processed and the error status of the operation on that object.
' Tree operation also passes the current InvokeSetting value.
' Caller may change the InvokeSetting value, for example, from "Always"
' to "Only On Error."
'

DECLARE SUB FN_PROGRESS ( _
    pObjectName       AS WSTRINGZ, _   ' name of object just processed
    BYVAL Status      AS DWORD,    _   ' status of operation on object
    pInvokeSetting    AS LONG,     _   ' Never, always,
    Args              AS ANY,      _   ' Caller-specific data
    BYVAL SecuritySet AS LONG)         ' Whether security was set


DECLARE FUNCTION SetEntriesInAclA LIB "ADVAPI32.DLL" _
   ALIAS "SetEntriesInAclA" ( _
    BYVAL cCountOfExplicitEntries AS DWORD, _
    BYVAL pListOfExplicitEntries  AS EXPLICIT_ACCESS_A PTR, _
    BYVAL OldAcl                  AS ACL PTR, _
    NewAcl                        AS DWORD _   ' ACL PTR PTR
    ) AS DWORD

DECLARE FUNCTION SetEntriesInAclW LIB "ADVAPI32.DLL" _
   ALIAS "SetEntriesInAclW" ( _
    BYVAL cCountOfExplicitEntries AS DWORD, _
    BYVAL pListOfExplicitEntries  AS EXPLICIT_ACCESS_W PTR, _
    BYVAL OldAcl                  AS ACL PTR, _
    NewAcl                        AS DWORD _   ' ACL PTR PTR
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetEntriesInAcl LIB "ADVAPI32.DLL" _
   ALIAS "SetEntriesInAclW" ( _
    BYVAL cCountOfExplicitEntries AS DWORD, _
    BYVAL pListOfExplicitEntries  AS EXPLICIT_ACCESS_W PTR, _
    BYVAL OldAcl                  AS ACL PTR, _
    NewAcl                        AS DWORD _   ' ACL PTR PTR
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetEntriesInAcl LIB "ADVAPI32.DLL" _
   ALIAS "SetEntriesInAclA" ( _
    BYVAL cCountOfExplicitEntries AS DWORD, _
    BYVAL pListOfExplicitEntries  AS EXPLICIT_ACCESS_A PTR, _
    BYVAL OldAcl                  AS ACL PTR, _
    NewAcl                        AS DWORD _   ' ACL PTR PTR
    ) AS DWORD
#ENDIF


DECLARE FUNCTION GetExplicitEntriesFromAclA LIB "ADVAPI32.DLL" _
   ALIAS "GetExplicitEntriesFromAclA" ( _
    BYVAL pacl               AS ACL PTR, _
    pcCountOfExplicitEntries AS DWORD, _
    pListOfExplicitEntries   AS DWORD _   ' EXPLICIT_ACCESS_A PTR PTR
    ) AS DWORD

DECLARE FUNCTION GetExplicitEntriesFromAclW LIB "ADVAPI32.DLL" _
   ALIAS "GetExplicitEntriesFromAclW" ( _
    BYVAL pacl               AS ACL PTR, _
    pcCountOfExplicitEntries AS DWORD, _
    pListOfExplicitEntries   AS DWORD _   ' EXPLICIT_ACCESS_W PTR PTR
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetExplicitEntriesFromAcl LIB "ADVAPI32.DLL" _
   ALIAS "GetExplicitEntriesFromAclW" ( _
    BYVAL pacl               AS ACL PTR, _
    pcCountOfExplicitEntries AS DWORD, _
    pListOfExplicitEntries   AS DWORD _   ' EXPLICIT_ACCESS_W PTR PTR
    ) AS DWORD
#ELSE
DECLARE FUNCTION GetExplicitEntriesFromAcl LIB "ADVAPI32.DLL" _
   ALIAS "GetExplicitEntriesFromAclA" ( _
    BYVAL pacl               AS ACL PTR, _
    pcCountOfExplicitEntries AS DWORD, _
    pListOfExplicitEntries   AS DWORD _   ' EXPLICIT_ACCESS_A PTR PTR
    ) AS DWORD
#ENDIF


DECLARE FUNCTION GetEffectiveRightsFromAclA LIB "ADVAPI32.DLL" _
   ALIAS "GetEffectiveRightsFromAclA" ( _
    pacl          AS ACL, _
    pTrustee      AS TRUSTEE_A, _
    pAccessRights AS DWORD _
    ) AS DWORD

DECLARE FUNCTION GetEffectiveRightsFromAclW LIB "ADVAPI32.DLL" _
   ALIAS "GetEffectiveRightsFromAclW" ( _
    pacl          AS ACL, _
    pTrustee      AS TRUSTEE_W, _
    pAccessRights AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
MACRO GetEffectiveRightsFromAcl=GetEffectiveRightsFromAclW
#ELSE
MACRO GetEffectiveRightsFromAcl=GetEffectiveRightsFromAclA
#ENDIF


DECLARE FUNCTION GetAuditedPermissionsFromAclA LIB "ADVAPI32.DLL" _
   ALIAS "GetAuditedPermissionsFromAclA" ( _
    pacl                     AS ACL, _
    pTrustee                 AS TRUSTEE_A, _
    pSuccessfulAuditedRights AS DWORD, _
    pFailedAuditRights       AS DWORD _
    ) AS DWORD

DECLARE FUNCTION GetAuditedPermissionsFromAclW LIB "ADVAPI32.DLL" _
   ALIAS "GetAuditedPermissionsFromAclW" ( _
    pacl                     AS ACL, _
    pTrustee                 AS TRUSTEE_W, _
    pSuccessfulAuditedRights AS DWORD, _
    pFailedAuditRights       AS DWORD _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetAuditedPermissionsFromAcl LIB "ADVAPI32.DLL" _
   ALIAS "GetAuditedPermissionsFromAclW" ( _
    pacl                     AS ACL, _
    pTrustee                 AS TRUSTEE_W, _
    pSuccessfulAuditedRights AS DWORD, _
    pFailedAuditRights       AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION GetAuditedPermissionsFromAcl LIB "ADVAPI32.DLL" _
   ALIAS "GetAuditedPermissionsFromAclA" ( _
    pacl                     AS ACL, _
    pTrustee                 AS TRUSTEE_A, _
    pSuccessfulAuditedRights AS DWORD, _
    pFailedAuditRights       AS DWORD _
    ) AS DWORD
#ENDIF


DECLARE FUNCTION GetNamedSecurityInfoA LIB "ADVAPI32.DLL" _
   ALIAS "GetNamedSecurityInfoA" ( _
    pObjectName          AS ASCIIZ, _
    BYVAL ObjectType     AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo   AS SECURITY_INFORMATION, _
    ppsidOwner           AS DWORD, _   ' SID PTR PTR
    ppsidGroup           AS DWORD, _   ' SID PTR PTR
    ppDacl               AS DWORD, _   ' ACL PTR PTR
    ppSacl               AS DWORD, _   ' ACL PTR PTR
    ppSecurityDescriptor AS DWORD _    ' SECURITY_DESCRIPTOR PTR PTR
    ) AS DWORD

DECLARE FUNCTION GetNamedSecurityInfoW LIB "ADVAPI32.DLL" _
   ALIAS "GetNamedSecurityInfoW" ( _
    pObjectName          AS WSTRINGZ, _
    BYVAL ObjectType     AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo   AS SECURITY_INFORMATION, _
    ppsidOwner           AS DWORD, _   ' SID PTR PTR
    ppsidGroup           AS DWORD, _   ' SID PTR PTR
    ppDacl               AS DWORD, _   ' ACL PTR PTR
    ppSacl               AS DWORD, _   ' ACL PTR PTR
    ppSecurityDescriptor AS DWORD _    ' SECURITY_DESCRIPTOR PTR PTR
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetNamedSecurityInfo LIB "ADVAPI32.DLL" _
   ALIAS "GetNamedSecurityInfoW" ( _
    pObjectName          AS WSTRINGZ, _
    BYVAL ObjectType     AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo   AS SECURITY_INFORMATION, _
    ppsidOwner           AS DWORD, _   ' SID PTR PTR
    ppsidGroup           AS DWORD, _   ' SID PTR PTR
    ppDacl               AS DWORD, _   ' ACL PTR PTR
    ppSacl               AS DWORD, _   ' ACL PTR PTR
    ppSecurityDescriptor AS DWORD _    ' SECURITY_DESCRIPTOR PTR PTR
    ) AS DWORD

#ELSE
DECLARE FUNCTION GetNamedSecurityInfo LIB "ADVAPI32.DLL" _
   ALIAS "GetNamedSecurityInfoA" ( _
    pObjectName          AS ASCIIZ, _
    BYVAL ObjectType     AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo   AS SECURITY_INFORMATION, _
    ppsidOwner           AS DWORD, _   ' SID PTR PTR
    ppsidGroup           AS DWORD, _   ' SID PTR PTR
    ppDacl               AS DWORD, _   ' ACL PTR PTR
    ppSacl               AS DWORD, _   ' ACL PTR PTR
    ppSecurityDescriptor AS DWORD _    ' SECURITY_DESCRIPTOR PTR PTR
    ) AS DWORD
#ENDIF


DECLARE FUNCTION GetSecurityInfo LIB "ADVAPI32.DLL" _
   ALIAS "GetSecurityInfo" ( _
    BYVAL shandle        AS DWORD, _
    BYVAL ObjectType     AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo   AS SECURITY_INFORMATION, _
    ppsidOwner           AS DWORD, _   ' SID PTR PTR
    ppsidGroup           AS DWORD, _   ' SID PTR PTR
    ppDacl               AS DWORD, _   ' ACL PTR PTR
    ppSacl               AS DWORD, _   ' ACL PTR PTR
    ppSecurityDescriptor AS DWORD _    ' SECURITY_DESCRIPTOR PTR PTR
    ) AS DWORD


DECLARE FUNCTION SetNamedSecurityInfoA LIB "ADVAPI32.DLL" _
   ALIAS "SetNamedSecurityInfoA" ( _
    pObjectName        AS ASCIIZ, _
    BYVAL ObjectType   AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo AS SECURITY_INFORMATION, _
    ppsidOwner         AS DWORD, _   ' SID PTR PTR
    ppsidGroup         AS DWORD, _   ' SID PTR PTR
    ppDacl             AS DWORD, _   ' ACL PTR PTR
    ppSacl             AS DWORD _    ' ACL PTR PTR
    ) AS DWORD

DECLARE FUNCTION SetNamedSecurityInfoW LIB "ADVAPI32.DLL" _
   ALIAS "SetNamedSecurityInfoW" ( _
    pObjectName        AS WSTRINGZ, _
    BYVAL ObjectType   AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo AS SECURITY_INFORMATION, _
    ppsidOwner         AS DWORD, _   ' SID PTR PTR
    ppsidGroup         AS DWORD, _   ' SID PTR PTR
    ppDacl             AS DWORD, _   ' ACL PTR PTR
    ppSacl             AS DWORD _    ' ACL PTR PTR
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION SetNamedSecurityInfo LIB "ADVAPI32.DLL" _
   ALIAS "SetNamedSecurityInfoW" ( _
    pObjectName        AS WSTRINGZ, _
    BYVAL ObjectType   AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo AS SECURITY_INFORMATION, _
    ppsidOwner         AS DWORD, _   ' SID PTR PTR
    ppsidGroup         AS DWORD, _   ' SID PTR PTR
    ppDacl             AS DWORD, _   ' ACL PTR PTR
    ppSacl             AS DWORD _    ' ACL PTR PTR
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetNamedSecurityInfo LIB "ADVAPI32.DLL" _
   ALIAS "SetNamedSecurityInfoA" ( _
    pObjectName        AS ASCIIZ, _
    BYVAL ObjectType   AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo AS SECURITY_INFORMATION, _
    ppsidOwner         AS DWORD, _   ' SID PTR PTR
    ppsidGroup         AS DWORD, _   ' SID PTR PTR
    ppDacl             AS DWORD, _   ' ACL PTR PTR
    ppSacl             AS DWORD _    ' ACL PTR PTR
    ) AS DWORD
#ENDIF


DECLARE FUNCTION SetSecurityInfo LIB "ADVAPI32.DLL" _
   ALIAS "SetSecurityInfo" ( _
    BYVAL shandle      AS DWORD, _
    BYVAL ObjectType   AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo AS SECURITY_INFORMATION, _
    ppsidOwner         AS DWORD, _   ' SID PTR PTR
    ppsidGroup         AS DWORD, _   ' SID PTR PTR
    ppDacl             AS DWORD, _   ' ACL PTR PTR
    ppSacl             AS DWORD _    ' ACL PTR PTR
    ) AS DWORD


DECLARE FUNCTION GetInheritanceSourceA LIB "ADVAPI32.DLL" _
   ALIAS "GetInheritanceSourceA" ( _
    pObjectName          AS ASCIIZ, _
    BYVAL ObjectType     AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo   AS SECURITY_INFORMATION, _
    BYVAL Container      AS LONG, _
    pObjectClassGuids    AS DWORD, _   ' GUID PTR PTR
    BYVAL GuidCount      AS DWORD, _
    pAcl                 AS ACL, _
    pfnArray             AS DWORD, _   ' OBJECT_MGR_FUNCTS PTR
    pGenericMapping      AS GENERIC_MAPPING, _
    pInheritArray        AS DWORD _    ' INHERITED_FROM PTR (to one or more)
    ) AS DWORD

DECLARE FUNCTION GetInheritanceSourceW LIB "ADVAPI32.DLL" _
   ALIAS "GetInheritanceSourceW" ( _
    pObjectName          AS WSTRINGZ, _
    BYVAL ObjectType     AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo   AS SECURITY_INFORMATION, _
    BYVAL Container      AS LONG, _
    pObjectClassGuids    AS DWORD, _   ' GUID PTR PTR
    BYVAL GuidCount      AS DWORD, _
    pAcl                 AS ACL, _
    pfnArray             AS DWORD, _   ' OBJECT_MGR_FUNCTS PTR
    pGenericMapping      AS GENERIC_MAPPING, _
    pInheritArray        AS DWORD _    ' INHERITED_FROM PTR (to one or more)
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetInheritanceSource LIB "ADVAPI32.DLL" _
   ALIAS "GetInheritanceSourceW" ( _
    pObjectName          AS WSTRINGZ, _
    BYVAL ObjectType     AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo   AS SECURITY_INFORMATION, _
    BYVAL Container      AS LONG, _
    pObjectClassGuids    AS DWORD, _   ' GUID PTR PTR
    BYVAL GuidCount      AS DWORD, _
    pAcl                 AS ACL, _
    pfnArray             AS DWORD, _   ' OBJECT_MGR_FUNCTS PTR
    pGenericMapping      AS GENERIC_MAPPING, _
    pInheritArray        AS DWORD _    ' INHERITED_FROM PTR (to one or more)
    ) AS DWORD
#ELSE
DECLARE FUNCTION GetInheritanceSource LIB "ADVAPI32.DLL" _
   ALIAS "GetInheritanceSourceA" ( _
    pObjectName          AS ASCIIZ, _
    BYVAL ObjectType     AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo   AS SECURITY_INFORMATION, _
    BYVAL Container      AS LONG, _
    pObjectClassGuids    AS DWORD, _   ' GUID PTR PTR
    BYVAL GuidCount      AS DWORD, _
    pAcl                 AS ACL, _
    pfnArray             AS DWORD, _   ' OBJECT_MGR_FUNCTS PTR
    pGenericMapping      AS GENERIC_MAPPING, _
    pInheritArray        AS DWORD _    ' INHERITED_FROM PTR (to one or more)
    ) AS DWORD
#ENDIF


DECLARE FUNCTION FreeInheritedFromArray LIB "ADVAPI32.DLL" _
   ALIAS "FreeInheritedFromArray" ( _
    BYVAL pInheritArray AS INHERITED_FROM PTR, _
    BYVAL AceCnt  AS WORD, _
    OPTIONAL BYVAL pfnArray AS DWORD _   ' OBJECT_MGR_FUNCTS PTR
    ) AS DWORD


DECLARE FUNCTION TreeResetNamedSecurityInfoA LIB "ADVAPI32.DLL" _
   ALIAS "TreeResetNamedSecurityInfoA" ( _
    pObjectName        AS ASCIIZ, _
    BYVAL ObjectType   AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo AS SECURITY_INFORMATION, _
    pOwner             AS SID, _
    pGroup             AS SID, _
    pDacl              AS ACL, _
    pSacl              AS ACL, _
    BYVAL KeepExplicit AS LONG, _
    BYVAL fnProgress   AS DWORD, _    ' FN_PROGRESS
    BYVAL ProgressInvokeSetting AS LONG, _   ' PROG_INVOKE_SETTING
    Args               AS ANY _
    ) AS DWORD

DECLARE FUNCTION TreeResetNamedSecurityInfoW LIB "ADVAPI32.DLL" _
   ALIAS "TreeResetNamedSecurityInfoW" ( _
    pObjectName        AS WSTRINGZ, _
    BYVAL ObjectType   AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo AS SECURITY_INFORMATION, _
    pOwner             AS SID, _
    pGroup             AS SID, _
    pDacl              AS ACL, _
    pSacl              AS ACL, _
    BYVAL KeepExplicit AS LONG, _
    BYVAL fnProgress   AS DWORD, _    ' FN_PROGRESS
    BYVAL ProgressInvokeSetting AS LONG, _   ' PROG_INVOKE_SETTING
    Args               AS ANY _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION TreeResetNamedSecurityInfo LIB "ADVAPI32.DLL" _
   ALIAS "TreeResetNamedSecurityInfoW" ( _
    pObjectName        AS WSTRINGZ, _
    BYVAL ObjectType   AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo AS SECURITY_INFORMATION, _
    pOwner             AS SID, _
    pGroup             AS SID, _
    pDacl              AS ACL, _
    pSacl              AS ACL, _
    BYVAL KeepExplicit AS LONG, _
    BYVAL fnProgress   AS DWORD, _    ' FN_PROGRESS
    BYVAL ProgressInvokeSetting AS LONG, _   ' PROG_INVOKE_SETTING
    Args               AS ANY _
    ) AS DWORD
#ELSE
DECLARE FUNCTION TreeResetNamedSecurityInfo LIB "ADVAPI32.DLL" _
   ALIAS "TreeResetNamedSecurityInfoA" ( _
    pObjectName        AS ASCIIZ, _
    BYVAL ObjectType   AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo AS SECURITY_INFORMATION, _
    pOwner             AS SID, _
    pGroup             AS SID, _
    pDacl              AS ACL, _
    pSacl              AS ACL, _
    BYVAL KeepExplicit AS LONG, _
    BYVAL fnProgress   AS DWORD, _    ' FN_PROGRESS
    BYVAL ProgressInvokeSetting AS LONG, _   ' PROG_INVOKE_SETTING
    Args               AS ANY _
    ) AS DWORD
#ENDIF


#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

DECLARE FUNCTION TreeSetNamedSecurityInfoA LIB "ADVAPI32.DLL" _
   ALIAS "TreeSetNamedSecurityInfoA" ( _
    pObjectName           AS ASCIIZ, _
    BYVAL ObjectType      AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo    AS SECURITY_INFORMATION, _
    pOwner                AS SID, _
    pGroup                AS SID, _
    pDacl                 AS ACL, _
    pSacl                 AS ACL, _
    BYVAL dwAction        AS DWORD, _
    BYVAL fnProgress      AS DWORD, _     ' FN_PROGRESS
    ProgressInvokeSetting AS LONG, _      ' PROG_INVOKE_SETTING
    Args                  AS ANY _
    ) AS DWORD

DECLARE FUNCTION TreeSetNamedSecurityInfoW LIB "ADVAPI32.DLL" _
   ALIAS "TreeSetNamedSecurityInfoW" ( _
    pObjectName           AS WSTRINGZ, _
    BYVAL ObjectType      AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo    AS SECURITY_INFORMATION, _
    pOwner                AS SID, _
    pGroup                AS SID, _
    pDacl                 AS ACL, _
    pSacl                 AS ACL, _
    BYVAL dwAction        AS DWORD, _
    BYVAL fnProgress      AS DWORD, _     ' FN_PROGRESS
    ProgressInvokeSetting AS LONG, _      ' PROG_INVOKE_SETTING
    Args                  AS ANY _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION TreeSetNamedSecurityInfo LIB "ADVAPI32.DLL" _
   ALIAS "TreeSetNamedSecurityInfoW" ( _
    pObjectName           AS WSTRINGZ, _
    BYVAL ObjectType      AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo    AS SECURITY_INFORMATION, _
    pOwner                AS SID, _
    pGroup                AS SID, _
    pDacl                 AS ACL, _
    pSacl                 AS ACL, _
    BYVAL dwAction        AS DWORD, _
    BYVAL fnProgress      AS DWORD, _     ' FN_PROGRESS
    ProgressInvokeSetting AS LONG, _      ' PROG_INVOKE_SETTING
    Args                  AS ANY _
    ) AS DWORD
#ELSE
DECLARE FUNCTION TreeSetNamedSecurityInfo LIB "ADVAPI32.DLL" _
   ALIAS "TreeSetNamedSecurityInfoA" ( _
    pObjectName           AS ASCIIZ, _
    BYVAL ObjectType      AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo    AS SECURITY_INFORMATION, _
    pOwner                AS SID, _
    pGroup                AS SID, _
    pDacl                 AS ACL, _
    pSacl                 AS ACL, _
    BYVAL dwAction        AS DWORD, _
    BYVAL fnProgress      AS DWORD, _     ' FN_PROGRESS
    ProgressInvokeSetting AS LONG, _      ' PROG_INVOKE_SETTING
    Args                  AS ANY _
    ) AS DWORD
#ENDIF

#ENDIF  ' #IF (%NTDDI_VERSION >= %NTDDI_VISTA)


'----------------------------------------------------------------------------
' The following API are provided for trusted servers to use to
' implement access control on their own objects.
'----------------------------------------------------------------------------

DECLARE FUNCTION BuildSecurityDescriptorA LIB "ADVAPI32.DLL" _
   ALIAS "BuildSecurityDescriptorA" ( _
    pOwner                      AS TRUSTEE_A, _
    pGroup                      AS TRUSTEE_A, _
    BYVAL cCountOfAccessEntries AS DWORD, _
    BYVAL pListOfAccessEntries  AS EXPLICIT_ACCESS_A PTR, _
    BYVAL cCountOfAuditEntries  AS DWORD, _
    BYVAL pListOfAuditEntries   AS EXPLICIT_ACCESS_A PTR, _
    pOldSD                      AS SECURITY_DESCRIPTOR, _
    pSizeNewSD                  AS DWORD, _
    pNewSD                      AS SECURITY_DESCRIPTOR _
    ) AS DWORD

DECLARE FUNCTION BuildSecurityDescriptorW LIB "ADVAPI32.DLL" _
   ALIAS "BuildSecurityDescriptorW" ( _
    pOwner                      AS TRUSTEE_W, _
    pGroup                      AS TRUSTEE_W, _
    BYVAL cCountOfAccessEntries AS DWORD, _
    BYVAL pListOfAccessEntries  AS EXPLICIT_ACCESS PTR, _
    BYVAL cCountOfAuditEntries  AS DWORD, _
    BYVAL pListOfAuditEntries   AS EXPLICIT_ACCESS PTR, _
    pOldSD                      AS SECURITY_DESCRIPTOR, _
    pSizeNewSD                  AS DWORD, _
    pNewSD                      AS SECURITY_DESCRIPTOR _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION BuildSecurityDescriptor LIB "ADVAPI32.DLL" _
   ALIAS "BuildSecurityDescriptorW" ( _
    pOwner                      AS TRUSTEE_W, _
    pGroup                      AS TRUSTEE_W, _
    BYVAL cCountOfAccessEntries AS DWORD, _
    BYVAL pListOfAccessEntries  AS EXPLICIT_ACCESS PTR, _
    BYVAL cCountOfAuditEntries  AS DWORD, _
    BYVAL pListOfAuditEntries   AS EXPLICIT_ACCESS PTR, _
    pOldSD                      AS SECURITY_DESCRIPTOR, _
    pSizeNewSD                  AS DWORD, _
    pNewSD                      AS SECURITY_DESCRIPTOR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION BuildSecurityDescriptor LIB "ADVAPI32.DLL" _
   ALIAS "BuildSecurityDescriptorA" ( _
    pOwner                      AS TRUSTEE_A, _
    pGroup                      AS TRUSTEE_A, _
    BYVAL cCountOfAccessEntries AS DWORD, _
    BYVAL pListOfAccessEntries  AS EXPLICIT_ACCESS_A PTR, _
    BYVAL cCountOfAuditEntries  AS DWORD, _
    BYVAL pListOfAuditEntries   AS EXPLICIT_ACCESS_A PTR, _
    pOldSD                      AS SECURITY_DESCRIPTOR, _
    pSizeNewSD                  AS DWORD, _
    pNewSD                      AS SECURITY_DESCRIPTOR _
    ) AS DWORD
#ENDIF


DECLARE FUNCTION LookupSecurityDescriptorPartsA LIB "ADVAPI32.DLL" _
   ALIAS "LookupSecurityDescriptorPartsA" ( _
    pOwner                      AS TRUSTEE_A, _
    pGroup                      AS TRUSTEE_A, _
    BYVAL cCountOfAccessEntries AS DWORD, _
    BYVAL pListOfAccessEntries  AS EXPLICIT_ACCESS_A PTR, _
    BYVAL cCountOfAuditEntries  AS DWORD, _
    BYVAL pListOfAuditEntries   AS EXPLICIT_ACCESS_A PTR, _
    pSD                         AS SECURITY_DESCRIPTOR _
    ) AS DWORD

DECLARE FUNCTION LookupSecurityDescriptorPartsW LIB "ADVAPI32.DLL" _
   ALIAS "LookupSecurityDescriptorPartsW" ( _
    pOwner                      AS TRUSTEE_W, _
    pGroup                      AS TRUSTEE_W, _
    BYVAL cCountOfAccessEntries AS DWORD, _
    BYVAL pListOfAccessEntries  AS EXPLICIT_ACCESS_W PTR, _
    BYVAL cCountOfAuditEntries  AS DWORD, _
    BYVAL pListOfAuditEntries   AS EXPLICIT_ACCESS_W PTR, _
    pSD                         AS SECURITY_DESCRIPTOR _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION LookupSecurityDescriptorParts LIB "ADVAPI32.DLL" _
   ALIAS "LookupSecurityDescriptorPartsW" ( _
    pOwner                      AS TRUSTEE_W, _
    pGroup                      AS TRUSTEE_W, _
    BYVAL cCountOfAccessEntries AS DWORD, _
    BYVAL pListOfAccessEntries  AS EXPLICIT_ACCESS_W PTR, _
    BYVAL cCountOfAuditEntries  AS DWORD, _
    BYVAL pListOfAuditEntries   AS EXPLICIT_ACCESS_W PTR, _
    pSD                         AS SECURITY_DESCRIPTOR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION LookupSecurityDescriptorParts LIB "ADVAPI32.DLL" _
   ALIAS "LookupSecurityDescriptorPartsA" ( _
    pOwner                      AS TRUSTEE_A, _
    pGroup                      AS TRUSTEE_A, _
    BYVAL cCountOfAccessEntries AS DWORD, _
    BYVAL pListOfAccessEntries  AS EXPLICIT_ACCESS_A PTR, _
    BYVAL cCountOfAuditEntries  AS DWORD, _
    BYVAL pListOfAuditEntries   AS EXPLICIT_ACCESS_A PTR, _
    pSD                         AS SECURITY_DESCRIPTOR _
    ) AS DWORD
#ENDIF


'----------------------------------------------------------------------------
' The following helper API are provided for building
' access control structures.
'----------------------------------------------------------------------------

DECLARE SUB BuildExplicitAccessWithNameA LIB "ADVAPI32.DLL" _
   ALIAS "BuildExplicitAccessWithNameA" ( _
    BYVAL pExplicitAccess   AS EXPLICIT_ACCESS_A PTR, _
    pTrusteeName            AS ASCIIZ, _
    BYVAL AccessPermissions AS DWORD, _
    BYVAL AccessMode        AS ACCESS_MODE_enum, _
    BYVAL Inheritance       AS DWORD _
    )

DECLARE SUB BuildExplicitAccessWithNameW LIB "ADVAPI32.DLL" _
   ALIAS "BuildExplicitAccessWithNameW" ( _
    BYVAL pExplicitAccess   AS EXPLICIT_ACCESS_W PTR, _
    pTrusteeName            AS WSTRINGZ, _
    BYVAL AccessPermissions AS DWORD, _
    BYVAL AccessMode        AS ACCESS_MODE_enum, _
    BYVAL Inheritance       AS DWORD _
    )

#IF %DEF(%UNICODE)
DECLARE SUB BuildExplicitAccessWithName LIB "ADVAPI32.DLL" _
   ALIAS "BuildExplicitAccessWithNameW" ( _
    BYVAL pExplicitAccess   AS EXPLICIT_ACCESS_W PTR, _
    pTrusteeName            AS WSTRINGZ, _
    BYVAL AccessPermissions AS DWORD, _
    BYVAL AccessMode        AS ACCESS_MODE_enum, _
    BYVAL Inheritance       AS DWORD _
    )
#ELSE
DECLARE SUB BuildExplicitAccessWithName LIB "ADVAPI32.DLL" _
   ALIAS "BuildExplicitAccessWithNameA" ( _
    BYVAL pExplicitAccess   AS EXPLICIT_ACCESS_A PTR, _
    pTrusteeName            AS ASCIIZ, _
    BYVAL AccessPermissions AS DWORD, _
    BYVAL AccessMode        AS ACCESS_MODE_enum, _
    BYVAL Inheritance       AS DWORD _
    )
#ENDIF


DECLARE SUB BuildImpersonateExplicitAccessWithNameA LIB "ADVAPI32.DLL" _
   ALIAS "BuildImpersonateExplicitAccessWithNameA" ( _
    BYVAL pExplicitAccess   AS EXPLICIT_ACCESS_A PTR, _
    pTrusteeName            AS ASCIIZ, _
    pTrustee                AS TRUSTEE_A, _
    BYVAL AccessPermissions AS DWORD, _
    BYVAL AccessMode        AS ACCESS_MODE_enum, _
    BYVAL Inheritance       AS DWORD _
    )

DECLARE SUB BuildImpersonateExplicitAccessWithNameW LIB "ADVAPI32.DLL" _
   ALIAS "BuildImpersonateExplicitAccessWithNameW" ( _
    BYVAL pExplicitAccess   AS EXPLICIT_ACCESS_W PTR, _
    pTrusteeName            AS WSTRINGZ, _
    pTrustee                AS TRUSTEE_A, _
    BYVAL AccessPermissions AS DWORD, _
    BYVAL AccessMode        AS ACCESS_MODE_enum, _
    BYVAL Inheritance       AS DWORD _
    )

#IF %DEF(%UNICODE)
DECLARE SUB BuildImpersonateExplicitAccessWithName LIB "ADVAPI32.DLL" _
   ALIAS "BuildImpersonateExplicitAccessWithNameW" ( _
    BYVAL pExplicitAccess   AS EXPLICIT_ACCESS_W PTR, _
    pTrusteeName            AS WSTRINGZ, _
    pTrustee                AS TRUSTEE_A, _
    BYVAL AccessPermissions AS DWORD, _
    BYVAL AccessMode        AS ACCESS_MODE_enum, _
    BYVAL Inheritance       AS DWORD _
    )
#ELSE
DECLARE SUB BuildImpersonateExplicitAccessWithName LIB "ADVAPI32.DLL" _
   ALIAS "BuildImpersonateExplicitAccessWithNameA" ( _
    BYVAL pExplicitAccess   AS EXPLICIT_ACCESS_A PTR, _
    pTrusteeName            AS ASCIIZ, _
    pTrustee                AS TRUSTEE_A, _
    BYVAL AccessPermissions AS DWORD, _
    BYVAL AccessMode        AS ACCESS_MODE_enum, _
    BYVAL Inheritance       AS DWORD _
    )
#ENDIF


DECLARE SUB BuildTrusteeWithNameA LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithNameA" ( _
    pTrustee AS TRUSTEE_A, _
    pName    AS ASCIIZ _
    )

DECLARE SUB BuildTrusteeWithNameW LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithNameW" ( _
    pTrustee AS TRUSTEE_W, _
    pName    AS WSTRINGZ _
    )

#IF %DEF(%UNICODE)
DECLARE SUB BuildTrusteeWithName LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithNameW" ( _
    pTrustee AS TRUSTEE_W, _
    pName    AS WSTRINGZ _
    )
#ELSE
DECLARE SUB BuildTrusteeWithName LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithNameA" ( _
    pTrustee AS TRUSTEE_A, _
    pName    AS ASCIIZ _
    )
#ENDIF


DECLARE SUB BuildImpersonateTrusteeA LIB "ADVAPI32.DLL" _
   ALIAS "BuildImpersonateTrusteeA" ( _
    pTrustee            AS TRUSTEE_A, _
    pImpersonateTrustee AS TRUSTEE_A _
    )

DECLARE SUB BuildImpersonateTrusteeW LIB "ADVAPI32.DLL" _
   ALIAS "BuildImpersonateTrusteeW" ( _
    pTrustee            AS TRUSTEE_W, _
    pImpersonateTrustee AS TRUSTEE_W _
    )

#IF %DEF(%UNICODE)
DECLARE SUB BuildImpersonateTrustee LIB "ADVAPI32.DLL" _
   ALIAS "BuildImpersonateTrusteeW" ( _
    pTrustee            AS TRUSTEE_W, _
    pImpersonateTrustee AS TRUSTEE_W _
    )
#ELSE
DECLARE SUB BuildImpersonateTrustee LIB "ADVAPI32.DLL" _
   ALIAS "BuildImpersonateTrusteeA" ( _
    pTrustee            AS TRUSTEE_A, _
    pImpersonateTrustee AS TRUSTEE_A _
    )
#ENDIF


DECLARE SUB BuildTrusteeWithSidA LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithSidA" ( _
    pTrustee   AS TRUSTEE_A, _
    BYVAL pSid AS SID PTR _
    )

DECLARE SUB BuildTrusteeWithSidW LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithSidW" ( _
    pTrustee   AS TRUSTEE_W, _
    BYVAL pSid AS SID PTR _
    )

#IF %DEF(%UNICODE)
DECLARE SUB BuildTrusteeWithSid LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithSidW" ( _
    pTrustee   AS TRUSTEE_W, _
    BYVAL pSid AS SID PTR _
    )
#ELSE
DECLARE SUB BuildTrusteeWithSid LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithSidA" ( _
    pTrustee   AS TRUSTEE_A, _
    BYVAL pSid AS SID PTR _
    )
#ENDIF


DECLARE SUB BuildTrusteeWithObjectsAndSidA LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithObjectsAndSidA" ( _
    pTrustee             AS TRUSTEE_A, _
    pObjSid              AS OBJECTS_AND_SID, _
    pObjectGuid          AS GUID, _
    pInheritedObjectGuid AS GUID, _
    BYVAL pSid           AS SID PTR _
    )

DECLARE SUB BuildTrusteeWithObjectsAndSidW LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithObjectsAndSidW" ( _
    pTrustee             AS TRUSTEE_W, _
    pObjSid              AS OBJECTS_AND_SID, _
    pObjectGuid          AS GUID, _
    pInheritedObjectGuid AS GUID, _
    BYVAL pSid           AS SID PTR _
    )

#IF %DEF(%UNICODE)
DECLARE SUB BuildTrusteeWithObjectsAndSid LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithObjectsAndSidW" ( _
    pTrustee             AS TRUSTEE_W, _
    pObjSid              AS OBJECTS_AND_SID, _
    pObjectGuid          AS GUID, _
    pInheritedObjectGuid AS GUID, _
    BYVAL pSid           AS SID PTR _
    )
#ELSE
DECLARE SUB BuildTrusteeWithObjectsAndSid LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithObjectsAndSidA" ( _
    pTrustee             AS TRUSTEE_A, _
    pObjSid              AS OBJECTS_AND_SID, _
    pObjectGuid          AS GUID, _
    pInheritedObjectGuid AS GUID, _
    BYVAL pSid           AS SID PTR _
    )
#ENDIF


DECLARE SUB BuildTrusteeWithObjectsAndNameA LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithObjectsAndNameA" ( _
    pTrustee                AS TRUSTEE_A, _
    pObjName                AS OBJECTS_AND_NAME, _
    ObjectType              AS SE_OBJECT_TYPE_enum, _
    ObjectTypeName          AS ASCIIZ, _
    InheritedObjectTypeName AS ASCIIZ, _
    TrusteeName             AS ASCIIZ _
    )

DECLARE SUB BuildTrusteeWithObjectsAndNameW LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithObjectsAndNameW" ( _
    pTrustee                AS TRUSTEE_W, _
    pObjName                AS OBJECTS_AND_NAME, _
    ObjectType              AS SE_OBJECT_TYPE_enum, _
    ObjectTypeName          AS WSTRINGZ, _
    InheritedObjectTypeName AS WSTRINGZ, _
    TrusteeName             AS WSTRINGZ _
    )

#IF %DEF(%UNICODE)
DECLARE SUB BuildTrusteeWithObjectsAndName LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithObjectsAndNameW" ( _
    pTrustee                AS TRUSTEE_W, _
    pObjName                AS OBJECTS_AND_NAME, _
    ObjectType              AS SE_OBJECT_TYPE_enum, _
    ObjectTypeName          AS WSTRINGZ, _
    InheritedObjectTypeName AS WSTRINGZ, _
    TrusteeName             AS WSTRINGZ _
    )
#ELSE
DECLARE SUB BuildTrusteeWithObjectsAndName LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithObjectsAndNameA" ( _
    pTrustee                AS TRUSTEE_A, _
    pObjName                AS OBJECTS_AND_NAME, _
    ObjectType              AS SE_OBJECT_TYPE_enum, _
    ObjectTypeName          AS ASCIIZ, _
    InheritedObjectTypeName AS ASCIIZ, _
    TrusteeName             AS ASCIIZ _
    )
#ENDIF


DECLARE FUNCTION GetTrusteeNameA LIB "ADVAPI32.DLL" _
   ALIAS "GetTrusteeNameA" ( _
    pTrustee AS TRUSTEE_A _
    ) AS DWORD

DECLARE FUNCTION GetTrusteeNameW LIB "ADVAPI32.DLL" _
   ALIAS "GetTrusteeNameW" ( _
    pTrustee AS TRUSTEE_W _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetTrusteeName LIB "ADVAPI32.DLL" _
   ALIAS "GetTrusteeNameW" ( _
    pTrustee AS TRUSTEE_W _
    ) AS DWORD
#ELSE
DECLARE FUNCTION GetTrusteeName LIB "ADVAPI32.DLL" _
   ALIAS "GetTrusteeNameA" ( _
    pTrustee AS TRUSTEE_A _
    ) AS DWORD
#ENDIF


DECLARE FUNCTION GetTrusteeTypeA LIB "ADVAPI32.DLL" _
   ALIAS "GetTrusteeTypeA" ( _
    pTrustee AS TRUSTEE_A _
    ) AS TRUSTEE_TYPE_enum

DECLARE FUNCTION GetTrusteeTypeW LIB "ADVAPI32.DLL" _
   ALIAS "GetTrusteeTypeW" ( _
    pTrustee AS TRUSTEE_W _
    ) AS TRUSTEE_TYPE_enum

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetTrusteeType LIB "ADVAPI32.DLL" _
   ALIAS "GetTrusteeTypeW" ( _
    pTrustee AS TRUSTEE_W _
    ) AS TRUSTEE_TYPE_enum
#ELSE
DECLARE FUNCTION GetTrusteeType LIB "ADVAPI32.DLL" _
   ALIAS "GetTrusteeTypeA" ( _
    pTrustee AS TRUSTEE_A _
    ) AS TRUSTEE_TYPE_enum
#ENDIF


DECLARE FUNCTION GetTrusteeFormA LIB "ADVAPI32.DLL" _
   ALIAS "GetTrusteeFormA" ( _
    pTrustee AS TRUSTEE_A _
    ) AS TRUSTEE_FORM_enum

DECLARE FUNCTION GetTrusteeFormW LIB "ADVAPI32.DLL" _
   ALIAS "GetTrusteeFormW" ( _
    pTrustee AS TRUSTEE_W _
    ) AS TRUSTEE_FORM_enum

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetTrusteeForm LIB "ADVAPI32.DLL" _
   ALIAS "GetTrusteeFormW" ( _
    pTrustee AS TRUSTEE_W _
    ) AS TRUSTEE_FORM_enum
#ELSE
DECLARE FUNCTION GetTrusteeForm LIB "ADVAPI32.DLL" _
   ALIAS "GetTrusteeFormA" ( _
    pTrustee AS TRUSTEE_A _
    ) AS TRUSTEE_FORM_enum
#ENDIF


DECLARE FUNCTION GetMultipleTrusteeOperationA LIB "ADVAPI32.DLL" _
   ALIAS "GetMultipleTrusteeOperationA" ( _
    pTrustee AS TRUSTEE_A _
    ) AS MULTIPLE_TRUSTEE_OPERATION_enum

DECLARE FUNCTION GetMultipleTrusteeOperationW LIB "ADVAPI32.DLL" _
   ALIAS "GetMultipleTrusteeOperationW" ( _
    pTrustee AS TRUSTEE_W _
    ) AS MULTIPLE_TRUSTEE_OPERATION_enum

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetMultipleTrusteeOperation LIB "ADVAPI32.DLL" _
   ALIAS "GetMultipleTrusteeOperationW" ( _
    pTrustee AS TRUSTEE_W _
    ) AS MULTIPLE_TRUSTEE_OPERATION_enum
#ELSE
DECLARE FUNCTION GetMultipleTrusteeOperation LIB "ADVAPI32.DLL" _
   ALIAS "GetMultipleTrusteeOperationA" ( _
    pTrustee AS TRUSTEE_A _
    ) AS MULTIPLE_TRUSTEE_OPERATION_enum
#ENDIF


DECLARE FUNCTION GetMultipleTrusteeA LIB "ADVAPI32.DLL" _
   ALIAS "GetMultipleTrusteeA" ( _
    pTrustee AS TRUSTEE_A _
    ) AS DWORD

DECLARE FUNCTION GetMultipleTrusteeW LIB "ADVAPI32.DLL" _
   ALIAS "GetMultipleTrusteeW" ( _
    pTrustee AS TRUSTEE_W _
    ) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetMultipleTrusteeW LIB "ADVAPI32.DLL" _
   ALIAS "GetMultipleTrusteeW" ( _
    pTrustee AS TRUSTEE_W _
    ) AS DWORD
#ELSE
DECLARE FUNCTION GetMultipleTrustee LIB "ADVAPI32.DLL" _
   ALIAS "GetMultipleTrusteeA" ( _
    pTrustee AS TRUSTEE_A _
    ) AS DWORD
#ENDIF
