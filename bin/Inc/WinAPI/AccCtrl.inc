'------------------------------------------------------------------------------
'
'  AccCtrl.inc -- Common includes for new-style Win32 Access Control APIS
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from accctrl.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%ACCESS_CONTROL = 1

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "WTypes.inc"



DECLARE FUNCTION AccFree LIB "Kernel32.dll" ALIAS "LocalFree" _
    (BYVAL hMem AS DWORD) AS DWORD

'
' Definition:
' This enumerated type defines the objects supported by the get/set API within
' this document. See section 3.1, Object Types for a detailed definition of the
' supported object types, and their name formats.
'
MACRO SE_OBJECT_TYPE_enum=LONG
ENUM SE_OBJECT_TYPE SINGULAR
    SE_UNKNOWN_OBJECT_TYPE
    SE_FILE_OBJECT
    SE_SERVICE
    SE_PRINTER
    SE_REGISTRY_KEY
    SE_LMSHARE
    SE_KERNEL_OBJECT
    SE_WINDOW_OBJECT
    SE_DS_OBJECT
    SE_DS_OBJECT_ALL
    SE_PROVIDER_DEFINED_OBJECT
    SE_WMIGUID_OBJECT
    SE_REGISTRY_WOW64_32KEY
END ENUM

'
' Definition: TRUSTEE_TYPE
' This enumerated type specifies the type of trustee account for the trustee
' returned by the API described in this document.
' TRUSTEE_IS_UNKNOWN - The trustee is an unknown, but not necessarily invalid
'                      type.  This field is not validated on input to the APIs
'                      that take Trustees.
' TRUSTEE_IS_USER      The trustee account is a user account.
' TRUSTEE_IS_GROUP     The trustee account is a group account.
'

MACRO TRUSTEE_TYPE_enum=LONG
ENUM TRUSTEE_TYPE SINGULAR
    TRUSTEE_IS_UNKNOWN
    TRUSTEE_IS_USER
    TRUSTEE_IS_GROUP
    TRUSTEE_IS_DOMAIN
    TRUSTEE_IS_ALIAS
    TRUSTEE_IS_WELL_KNOWN_GROUP
    TRUSTEE_IS_DELETED
    TRUSTEE_IS_INVALID
    TRUSTEE_IS_COMPUTER
END ENUM

'
' Definition: TRUSTEE_FORM
' This enumerated type specifies the form the trustee identifier is in for a
' particular trustee.
' TRUSTEE_IS_SID       The trustee is identified with a SID rather than with a name.
' TRUSTEE_IS_NAME      The trustee is identified with a name.
'
MACRO TRUSTEE_FORM_enum=LONG
ENUM TRUSTEE_FORM SINGULAR
    TRUSTEE_IS_SID
    TRUSTEE_IS_NAME
    TRUSTEE_BAD_FORM
    TRUSTEE_IS_OBJECTS_AND_SID
    TRUSTEE_IS_OBJECTS_AND_NAME
END ENUM


'
' Definition: MULTIPLE_TRUSTEE_OPERATION
' If the trustee is a multiple trustee, this enumerated type specifies the type.
' TRUSTEE_IS_IMPERSONATE       The trustee is an impersonate trustee and the multiple
'                          trustee field in the trustee points to another trustee
'                          that is a trustee for the server that will be doing the
'                          impersonation.
'
MACRO MULTIPLE_TRUSTEE_OPERATION_enum=LONG
ENUM MULTIPLE_TRUSTEE_OPERATION SINGULAR
    NO_MULTIPLE_TRUSTEE
    TRUSTEE_IS_IMPERSONATE
END ENUM


TYPE OBJECTS_AND_SID
    ObjectsPresent          AS DWORD
    ObjectTypeGuid          AS GUID
    InheritedObjectTypeGuid AS GUID
    pSid                    AS SID PTR
END TYPE

TYPE OBJECTS_AND_NAME_A
    ObjectsPresent          AS DWORD
    ObjectType              AS SE_OBJECT_TYPE_enum
    ObjectTypeName          AS ASCIIZ PTR
    InheritedObjectTypeName AS ASCIIZ PTR
    ptstrName               AS ASCIIZ PTR
END TYPE

TYPE OBJECTS_AND_NAME_W
    ObjectsPresent          AS DWORD
    ObjectType              AS SE_OBJECT_TYPE_enum
    ObjectTypeName          AS WSTRINGZ PTR
    InheritedObjectTypeName AS WSTRINGZ PTR
    ptstrName               AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE OBJECTS_AND_NAME
    OBJECTS_AND_NAME_W
END TYPE
#ELSE
TYPE OBJECTS_AND_NAME
    OBJECTS_AND_NAME_A
END TYPE
#ENDIF

'
' Definition: TRUSTEE (changed to TRUSTEE_A to avoid conflicts elsewhere)
' This structure is used to pass account information into and out of the system
' using the API defined in this document.
' PMultipleTrustee     - if NON-NULL, points to another trustee structure, as
'                    defined by the multiple trustee operation field.
' MultipleTrusteeOperation - Defines the multiple trustee operation/type.
' TrusteeForm - defines if the trustee is defined by name or SID.
' TrusteeType - defines if the trustee type is unknown, a user or a group.
' PwcsName     - points to the trustee name or the trustee SID.
'

TYPE TRUSTEE_A
    pMultipleTrustee         AS TRUSTEE_A PTR
    MultipleTrusteeOperation AS MULTIPLE_TRUSTEE_OPERATION_enum
    TrusteeForm              AS TRUSTEE_FORM_enum
    TrusteeType              AS TRUSTEE_TYPE_enum
    ptstrName                AS ASCIIZ PTR
END TYPE

TYPE TRUSTEE_W
    pMultipleTrustee         AS TRUSTEE_W PTR
    MultipleTrusteeOperation AS MULTIPLE_TRUSTEE_OPERATION_enum
    TrusteeForm              AS TRUSTEE_FORM_enum
    TrusteeType              AS TRUSTEE_TYPE_enum
    ptstrName                AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE TRUSTEE
    TRUSTEE_W
END TYPE
#ELSE
TYPE TRUSTEE
    TRUSTEE_A
END TYPE
#ENDIF

'
' Definition: ACCESS_MODE
' This enumerated type specifies how permissions are (requested)/to be applied
'  for the trustee by the access control entry.  On input this field can by any
'  of the values, although it is not meaningful to mix access control and audit
'  control entries.  On output this field will be either SET_ACCESS, DENY_ACCESS,
' SET_AUDIT_SUCCESS, SET_AUDIT_FAILURE.
' The following descriptions define how this type effects an explicit access
' request to apply access permissions to an object.
' GRANT_ACCESS - The trustee will have at least the requested permissions upon
'                successful completion of the command. (If the trustee has
'                additional permissions they will not be removed).
' SET_ACCESS - The trustee will have exactly the requested permissions upon
'              successful completion of the command.
' DENY_ACCESS - The trustee will be denied the specified permissions.
' REVOKE_ACCESS - Any explicit access rights the trustee has will be revoked.
' SET_AUDIT_SUCCESS - The trustee will be audited for successful opens of the
'                     object using the requested permissions.
' SET_AUDIT_FAILURE - The trustee will be audited for failed opens of the object
'                     using the requested permissions.
'

MACRO ACCESS_MODE_enum=LONG
ENUM ACCESS_MODE SINGULAR
    NOT_USED_ACCESS
    GRANT_ACCESS
    SET_ACCESS
    DENY_ACCESS
    REVOKE_ACCESS
    SET_AUDIT_SUCCESS
    SET_AUDIT_FAILURE
END ENUM

'
' Definition: Inheritance flags
' These bit masks are provided to allow simple application of inheritance in
' explicit access requests on containers.
' NO_INHERITANCE       The specific access permissions will only be applied to
'                  the container, and will not be inherited by objects created
'                  within the container.
' SUB_CONTAINERS_ONLY_INHERIT  The specific access permissions will be inherited
'                              and applied to sub containers created within the
'                              container, and will be applied to the container
'                              itself.
' SUB_OBJECTS_ONLY_INHERIT     The specific access permissions will only be inherited
'                              by objects created within the specific container.
'                              The access permissions will not be applied to the
'                              container itself.
' SUB_CONTAINERS_AND_OBJECTS_INHERIT   The specific access permissions will be
'                                      inherited by containers created within the
'                                      specific container, will be applied to
'                                      objects created within the container, but
'                                      will not be applied to the container itself.
'
%NO_INHERITANCE                     = &H00
%SUB_OBJECTS_ONLY_INHERIT           = &H01
%SUB_CONTAINERS_ONLY_INHERIT        = &H02
%SUB_CONTAINERS_AND_OBJECTS_INHERIT = &H03
%INHERIT_NO_PROPAGATE               = &H04
%INHERIT_ONLY                       = &H08

'
' Informational bit that is returned
'
%INHERITED_ACCESS_ENTRY             = &H10

'
' Informational bit that tells where a node was inherited from.  Valid only
' for NT 5 APIs (Windows 2000 and later)
'
%INHERITED_PARENT                   = &H10000000
%INHERITED_GRANDPARENT              = &H20000000


'
' Definition: EXPLICIT_ACCESS
' This structure is used to pass access control entry information into and out
' of the system using the API defined in this document.
' grfAccessPermissions - This contains the access permissions to assign for the
'                     trustee.  It is in the form of an NT access mask.
' grfAccessMode - This field defines how the permissions are to be applied for
'                 the trustee.
' grfInheritance - For containers, this field defines how the access control
'                  entry is/(is requested) to be inherited on
'                  objects/sub-containers created within the container.
' Trustee - This field contains the definition of the trustee account the
'           explicit access applies to.
'

TYPE EXPLICIT_ACCESS_A
    grfAccessPermissions AS DWORD
    grfAccessMode        AS ACCESS_MODE_enum
    grfInheritance       AS DWORD
    Trustee              AS TRUSTEE_A
END TYPE

TYPE EXPLICIT_ACCESS_W
    grfAccessPermissions AS DWORD
    grfAccessMode        AS ACCESS_MODE_enum
    grfInheritance       AS DWORD
    Trustee              AS TRUSTEE_W
END TYPE

#IF %DEF(%UNICODE)
TYPE EXPLICIT_ACCESS
    EXPLICIT_ACCESS_W
END TYPE
#ELSE
TYPE EXPLICIT_ACCESS
    EXPLICIT_ACCESS_A
END TYPE
#ENDIF

'----------------------------------------------------------------------------
'
'                                  NT5 APIs
'
'----------------------------------------------------------------------------

'
' Default provider
'
$ACCCTRL_DEFAULT_PROVIDERA = "Windows NT Access Provider"
$$ACCCTRL_DEFAULT_PROVIDERW = "Windows NT Access Provider"$$

#IF %DEF(%UNICODE)
MACRO ACCCTRL_DEFAULT_PROVIDER=$$ACCCTRL_DEFAULT_PROVIDERW
#ELSE
MACRO ACCCTRL_DEFAULT_PROVIDER=$ACCCTRL_DEFAULT_PROVIDERA
#ENDIF



'
' Access rights
'
'typedef     ULONG   ACCESS_RIGHTS, *PACCESS_RIGHTS;
'MACRO ACCESS_RIGHTS=DWORD

'
' Inheritance flags
'
'typedef ULONG INHERIT_FLAGS, *PINHERIT_FLAGS;
'MACRO INHERIT_FLAGS=DWORD


'
' Access / Audit structures
'
TYPE ACTRL_ACCESS_ENTRYA
    Trustee            AS TRUSTEE_A
    fAccessFlags       AS DWORD
    dAccess            AS DWORD
    ProvSpecificAccess AS DWORD
    Inheritance        AS DWORD
    lpInheritProperty  AS ASCIIZ PTR
END TYPE

TYPE ACTRL_ACCESS_ENTRYW
    Trustee            AS TRUSTEE_W
    fAccessFlags       AS DWORD
    dAccess            AS DWORD
    ProvSpecificAccess AS DWORD
    Inheritance        AS DWORD
    lpInheritProperty  AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE ACTRL_ACCESS_ENTRY
    ACTRL_ACCESS_ENTRYW
END TYPE
#ELSE
TYPE ACTRL_ACCESS_ENTRY
    ACTRL_ACCESS_ENTRYA
END TYPE
#ENDIF


TYPE ACTRL_ACCESS_ENTRY_LISTA
    cEntries    AS DWORD
    pAccessList AS ACTRL_ACCESS_ENTRYA PTR
END TYPE

TYPE ACTRL_ACCESS_ENTRY_LISTW
    cEntries    AS DWORD
    pAccessList AS ACTRL_ACCESS_ENTRYW PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE ACTRL_ACCESS_ENTRY_LIST
    ACTRL_ACCESS_ENTRY_LISTW
END TYPE
#ELSE
TYPE ACTRL_ACCESS_ENTRY_LIST
    ACTRL_ACCESS_ENTRY_LISTA
END TYPE
#ENDIF


TYPE ACTRL_PROPERTY_ENTRYA
    lpProperty       AS ASCIIZ PTR
    pAccessEntryList AS ACTRL_ACCESS_ENTRY_LISTA PTR
    fListFlags       AS DWORD
END TYPE

TYPE ACTRL_PROPERTY_ENTRYW
    lpProperty       AS WSTRINGZ PTR
    pAccessEntryList AS ACTRL_ACCESS_ENTRY_LISTW PTR
    fListFlags       AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE ACTRL_PROPERTY_ENTRY
    ACTRL_PROPERTY_ENTRYW
END TYPE
#ELSE
TYPE ACTRL_PROPERTY_ENTRY
    ACTRL_PROPERTY_ENTRYA
END TYPE
#ENDIF


TYPE ACTRL_ALISTA
    cEntries            AS DWORD
    pPropertyAccessList AS ACTRL_PROPERTY_ENTRYA PTR
END TYPE

TYPE ACTRL_ALISTW
    cEntries            AS DWORD
    pPropertyAccessList AS ACTRL_PROPERTY_ENTRYW PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE ACTRL_ALIST
    ACTRL_ALISTW
END TYPE
#ELSE
TYPE ACTRL_ALIST
    ACTRL_ALISTA
END TYPE
#ENDIF


'
' TRUSTEE_ACCESS flags
'
%TRUSTEE_ACCESS_ALLOWED    = &H00000001
%TRUSTEE_ACCESS_READ       = &H00000002
%TRUSTEE_ACCESS_WRITE      = &H00000004

%TRUSTEE_ACCESS_EXPLICIT   = &H00000001
%TRUSTEE_ACCESS_READ_WRITE = %TRUSTEE_ACCESS_READ OR %TRUSTEE_ACCESS_WRITE


%TRUSTEE_ACCESS_ALL        = &HFFFFFFFF???

TYPE TRUSTEE_ACCESSA
    lpProperty      AS ASCIIZ PTR
    dAccess         AS DWORD
    fAccessFlags    AS DWORD
    fReturnedAccess AS DWORD
END TYPE

TYPE TRUSTEE_ACCESSW
    lpProperty      AS WSTRINGZ PTR
    dAccess         AS DWORD
    fAccessFlags    AS DWORD
    fReturnedAccess AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE TRUSTEE_ACCESS
    TRUSTEE_ACCESSW
END TYPE
#ELSE
TYPE TRUSTEE_ACCESS
    TRUSTEE_ACCESSA
END TYPE
#ENDIF


'
' Generic permission values
'
%ACTRL_RESERVED          = &H00000000
%ACTRL_PERM_1            = &H00000001
%ACTRL_PERM_2            = &H00000002
%ACTRL_PERM_3            = &H00000004
%ACTRL_PERM_4            = &H00000008
%ACTRL_PERM_5            = &H00000010
%ACTRL_PERM_6            = &H00000020
%ACTRL_PERM_7            = &H00000040
%ACTRL_PERM_8            = &H00000080
%ACTRL_PERM_9            = &H00000100
%ACTRL_PERM_10           = &H00000200
%ACTRL_PERM_11           = &H00000400
%ACTRL_PERM_12           = &H00000800
%ACTRL_PERM_13           = &H00001000
%ACTRL_PERM_14           = &H00002000
%ACTRL_PERM_15           = &H00004000
%ACTRL_PERM_16           = &H00008000
%ACTRL_PERM_17           = &H00010000
%ACTRL_PERM_18           = &H00020000
%ACTRL_PERM_19           = &H00040000
%ACTRL_PERM_20           = &H00080000

'
' Access permissions
'
%ACTRL_ACCESS_ALLOWED        = &H00000001
%ACTRL_ACCESS_DENIED         = &H00000002
%ACTRL_AUDIT_SUCCESS         = &H00000004
%ACTRL_AUDIT_FAILURE         = &H00000008

'
' Property list flags
'
%ACTRL_ACCESS_PROTECTED      = &H00000001

'
' Standard and object rights
'
%ACTRL_SYSTEM_ACCESS         = &H04000000
%ACTRL_DELETE                = &H08000000
%ACTRL_READ_CONTROL          = &H10000000
%ACTRL_CHANGE_ACCESS         = &H20000000
%ACTRL_CHANGE_OWNER          = &H40000000
%ACTRL_SYNCHRONIZE           = &H80000000???
%ACTRL_STD_RIGHTS_ALL        = &HF8000000???
%ACTRL_STD_RIGHT_REQUIRED    = %ACTRL_STD_RIGHTS_ALL AND (%ACTRL_SYNCHRONIZE XOR &HFFFFFFFF???)

#IF NOT %DEF(%DS_CONTROL_BITS_DEFINED)
    %DS_CONTROL_BITS_DEFINED = 1
    %ACTRL_DS_OPEN                          = %ACTRL_RESERVED
    %ACTRL_DS_CREATE_CHILD                  = %ACTRL_PERM_1
    %ACTRL_DS_DELETE_CHILD                  = %ACTRL_PERM_2
    %ACTRL_DS_LIST                          = %ACTRL_PERM_3
    %ACTRL_DS_SELF                          = %ACTRL_PERM_4
    %ACTRL_DS_READ_PROP                     = %ACTRL_PERM_5
    %ACTRL_DS_WRITE_PROP                    = %ACTRL_PERM_6
    %ACTRL_DS_DELETE_TREE                   = %ACTRL_PERM_7
    %ACTRL_DS_LIST_OBJECT                   = %ACTRL_PERM_8
    %ACTRL_DS_CONTROL_ACCESS                = %ACTRL_PERM_9
#ENDIF

%ACTRL_FILE_READ                        = %ACTRL_PERM_1
%ACTRL_FILE_WRITE                       = %ACTRL_PERM_2
%ACTRL_FILE_APPEND                      = %ACTRL_PERM_3
%ACTRL_FILE_READ_PROP                   = %ACTRL_PERM_4
%ACTRL_FILE_WRITE_PROP                  = %ACTRL_PERM_5
%ACTRL_FILE_EXECUTE                     = %ACTRL_PERM_6
%ACTRL_FILE_READ_ATTRIB                 = %ACTRL_PERM_8
%ACTRL_FILE_WRITE_ATTRIB                = %ACTRL_PERM_9
%ACTRL_FILE_CREATE_PIPE                 = %ACTRL_PERM_10
%ACTRL_DIR_LIST                         = %ACTRL_PERM_1
%ACTRL_DIR_CREATE_OBJECT                = %ACTRL_PERM_2
%ACTRL_DIR_CREATE_CHILD                 = %ACTRL_PERM_3
%ACTRL_DIR_DELETE_CHILD                 = %ACTRL_PERM_7
%ACTRL_DIR_TRAVERSE                     = %ACTRL_PERM_6
%ACTRL_KERNEL_TERMINATE                 = %ACTRL_PERM_1
%ACTRL_KERNEL_THREAD                    = %ACTRL_PERM_2
%ACTRL_KERNEL_VM                        = %ACTRL_PERM_3
%ACTRL_KERNEL_VM_READ                   = %ACTRL_PERM_4
%ACTRL_KERNEL_VM_WRITE                  = %ACTRL_PERM_5
%ACTRL_KERNEL_DUP_HANDLE                = %ACTRL_PERM_6
%ACTRL_KERNEL_PROCESS                   = %ACTRL_PERM_7
%ACTRL_KERNEL_SET_INFO                  = %ACTRL_PERM_8
%ACTRL_KERNEL_GET_INFO                  = %ACTRL_PERM_9
%ACTRL_KERNEL_CONTROL                   = %ACTRL_PERM_10
%ACTRL_KERNEL_ALERT                     = %ACTRL_PERM_11
%ACTRL_KERNEL_GET_CONTEXT               = %ACTRL_PERM_12
%ACTRL_KERNEL_SET_CONTEXT               = %ACTRL_PERM_13
%ACTRL_KERNEL_TOKEN                     = %ACTRL_PERM_14
%ACTRL_KERNEL_IMPERSONATE               = %ACTRL_PERM_15
%ACTRL_KERNEL_DIMPERSONATE              = %ACTRL_PERM_16
%ACTRL_PRINT_SADMIN                     = %ACTRL_PERM_1
%ACTRL_PRINT_SLIST                      = %ACTRL_PERM_2
%ACTRL_PRINT_PADMIN                     = %ACTRL_PERM_3
%ACTRL_PRINT_PUSE                       = %ACTRL_PERM_4
%ACTRL_PRINT_JADMIN                     = %ACTRL_PERM_5
%ACTRL_SVC_GET_INFO                     = %ACTRL_PERM_1
%ACTRL_SVC_SET_INFO                     = %ACTRL_PERM_2
%ACTRL_SVC_STATUS                       = %ACTRL_PERM_3
%ACTRL_SVC_LIST                         = %ACTRL_PERM_4
%ACTRL_SVC_START                        = %ACTRL_PERM_5
%ACTRL_SVC_STOP                         = %ACTRL_PERM_6
%ACTRL_SVC_PAUSE                        = %ACTRL_PERM_7
%ACTRL_SVC_INTERROGATE                  = %ACTRL_PERM_8
%ACTRL_SVC_UCONTROL                     = %ACTRL_PERM_9
%ACTRL_REG_QUERY                        = %ACTRL_PERM_1
%ACTRL_REG_SET                          = %ACTRL_PERM_2
%ACTRL_REG_CREATE_CHILD                 = %ACTRL_PERM_3
%ACTRL_REG_LIST                         = %ACTRL_PERM_4
%ACTRL_REG_NOTIFY                       = %ACTRL_PERM_5
%ACTRL_REG_LINK                         = %ACTRL_PERM_6
%ACTRL_WIN_CLIPBRD                      = %ACTRL_PERM_1
%ACTRL_WIN_GLOBAL_ATOMS                 = %ACTRL_PERM_2
%ACTRL_WIN_CREATE                       = %ACTRL_PERM_3
%ACTRL_WIN_LIST_DESK                    = %ACTRL_PERM_4
%ACTRL_WIN_LIST                         = %ACTRL_PERM_5
%ACTRL_WIN_READ_ATTRIBS                 = %ACTRL_PERM_6
%ACTRL_WIN_WRITE_ATTRIBS                = %ACTRL_PERM_7
%ACTRL_WIN_SCREEN                       = %ACTRL_PERM_8
%ACTRL_WIN_EXIT                         = %ACTRL_PERM_9



UNION ACTRL_OVERLAPPED_union
    Provider  AS DWORD
    Reserved1 AS DWORD
END UNION

TYPE ACTRL_OVERLAPPED
    ACTRL_OVERLAPPED_union
    Reserved2 AS DWORD
    hEvent    AS DWORD
END TYPE


TYPE ACTRL_ACCESS_INFOA
    fAccessPermission      AS DWORD
    lpAccessPermissionName AS ASCIIZ PTR
END TYPE

TYPE ACTRL_ACCESS_INFOW
    fAccessPermission      AS DWORD
    lpAccessPermissionName AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE ACTRL_ACCESS_INFO
    ACTRL_ACCESS_INFOW
END TYPE
#ELSE
TYPE ACTRL_ACCESS_INFO
    ACTRL_ACCESS_INFOA
END TYPE
#ENDIF


TYPE ACTRL_CONTROL_INFOA
    lpControlId   AS ASCIIZ PTR
    lpControlName AS ASCIIZ PTR
END TYPE

TYPE ACTRL_CONTROL_INFOW
    lpControlId   AS WSTRINGZ PTR
    lpControlName AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE ACTRL_CONTROL_INFO
    ACTRL_CONTROL_INFOW
END TYPE
#ELSE
TYPE ACTRL_CONTROL_INFO
    ACTRL_CONTROL_INFOA
END TYPE
#ENDIF

%ACTRL_ACCESS_NO_OPTIONS              = &H00000000
%ACTRL_ACCESS_SUPPORTS_OBJECT_ENTRIES = &H00000001

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%TREE_SEC_INFO_SET                   = &H00000001
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)

MACRO PROGRESS_INVOKE_SETTING_enum=LONG
ENUM PROGRESS_INVOKE_SETTING SINGULAR
    ProgressInvokeNever        = 1  ' Never invoke the progress function
    ProgressInvokeEveryObject       ' Invoke for each object
    ProgressInvokeOnError           ' Invoke only for each error case
    ProgressCancelOperation         ' Stop propagation and return
    ProgressRetryOperation          ' Retry operation on subtree
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
    ProgressInvokePrePostError      ' Invoke Pre, Post, Error
#ENDIF ' #IF (%NTDDI_VERSION >= %NTDDI_VISTA)
END ENUM

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

'
' New Object Type function pointers.  TBD.
' To support additional object resource managers generically, the
' resource manager must provide it's own functions for operations
' like:
' GetAncestorAcl(IN ObjName, IN GenerationGap, IN DaclOrSacl?, ...)
' GetAncestorName(...)
' FreeNameStructure(...)
'

TYPE FN_OBJECT_MGR_FUNCTIONS
    Placeholder AS DWORD
END TYPE

'
' Name of ancestor and number of generations between
' ancestor and inheriting object.
'
' GenerationGap:
'     Name of ancestor from which ACE was inherited.
'     NULL for explicit ACE.
'
' AncestorName:
'     Number of levels (or generations) between the object and the ancestor.
'     Parent, gap=1.
'     Grandparent, gap=2.
'     Set to 0 for explicit ACE on object.
'

TYPE INHERITED_FROMA
    GenerationGap AS LONG
    AncestorName  AS ASCIIZ PTR
END TYPE

TYPE INHERITED_FROMW
    GenerationGap AS LONG
    AncestorName  AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)
TYPE INHERITED_FROM
    INHERITED_FROMW
END TYPE
#ELSE
TYPE INHERITED_FROM
    INHERITED_FROMA
END TYPE
#ENDIF
