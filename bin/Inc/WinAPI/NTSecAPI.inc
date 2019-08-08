'------------------------------------------------------------------------------
'
'  NTSecAPI.inc -- This module defines the Local Security Authority APIs.
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from ntsecapi.h build version 0000 of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

'
' All the subcategories are named as <Audit_CategoryName_SubCategoryName>
'

#IF %DEF(%DEFINE_GUID)

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_System_SecurityStateChange_defined)
    $Audit_System_SecurityStateChange = GUID$("{0cce9210-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_System_SecurityStateChange_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_System_SecuritySubsystemExtension_defined)
    $Audit_System_SecuritySubsystemExtension = GUID$("{0cce9211-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_System_SecuritySubsystemExtension_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_System_Integrity_defined)
    $Audit_System_Integrity = GUID$("{0cce9212-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_System_Integrity_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_System_IPSecDriverEvents_defined)
    $Audit_System_IPSecDriverEvents = GUID$("{0cce9213-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_System_IPSecDriverEvents_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_System_Others_defined)
    $Audit_System_Others = GUID$("{0cce9214-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_System_Others_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_Logon_Logon_defined)
    $Audit_Logon_Logon = GUID$("{0cce9215-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_Logon_Logon_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_Logon_Logoff_defined)
    $Audit_Logon_Logoff = GUID$("{0cce9216-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_Logon_Logoff_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_Logon_AccountLockout_defined)
    $Audit_Logon_AccountLockout = GUID$("{0cce9217-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_Logon_AccountLockout_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_Logon_IPSecMainMode_defined)
    $Audit_Logon_IPSecMainMode = GUID$("{0cce9218-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_Logon_IPSecMainMode_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_Logon_IPSecQuickMode_defined)
    $Audit_Logon_IPSecQuickMode = GUID$("{0cce9219-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_Logon_IPSecQuickMode_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_Logon_IPSecUserMode_defined)
    $Audit_Logon_IPSecUserMode = GUID$("{0cce921a-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_Logon_IPSecUserMode_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_Logon_SpecialLogon_defined)
    $Audit_Logon_SpecialLogon = GUID$("{0cce921b-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_Logon_SpecialLogon_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_Logon_Others_defined)
    $Audit_Logon_Others = GUID$("{0cce921c-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_Logon_Others_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_ObjectAccess_FileSystem_defined)
    $Audit_ObjectAccess_FileSystem = GUID$("{0cce921d-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_ObjectAccess_FileSystem_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_ObjectAccess_Registry_defined)
    $Audit_ObjectAccess_Registry = GUID$("{0cce921e-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_ObjectAccess_Registry_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_ObjectAccess_Kernel_defined)
    $Audit_ObjectAccess_Kernel = GUID$("{0cce921f-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_ObjectAccess_Kernel_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_ObjectAccess_Sam_defined)
    $Audit_ObjectAccess_Sam = GUID$("{0cce9220-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_ObjectAccess_Sam_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_ObjectAccess_CertificationServices_defined)
    $Audit_ObjectAccess_CertificationServices = GUID$("{0cce9221-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_ObjectAccess_CertificationServices_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_ObjectAccess_ApplicationGenerated_defined)
    $Audit_ObjectAccess_ApplicationGenerated = GUID$("{0cce9222-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_ObjectAccess_ApplicationGenerated_defined = 1
    #ENDIF
#ENDIF

'
' The Audit_ObjectAccess_Handle sub-category behaves different from the other sub-categories.
' For handle based audits to be generated (Open handle AuditId: &H1230, Close handle AuditId:
' &H1232), the corresponding object sub-category AND Audit_ObjectAccess_Handle must be
' enabled. For eg, to generate handle based audits for Reg keys, both
' Audit_ObjectAccess_Registry and Audit_ObjectAccess_Handle must be enabled
'

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_ObjectAccess_Handle_defined)
    $Audit_ObjectAccess_Handle = GUID$("{0cce9223-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_ObjectAccess_Handle_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_ObjectAccess_Share_defined)
    $Audit_ObjectAccess_Share = GUID$("{0cce9224-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_ObjectAccess_Share_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_ObjectAccess_FirewallPacketDrops_defined)
    $Audit_ObjectAccess_FirewallPacketDrops = GUID$("{0cce9225-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_ObjectAccess_FirewallPacketDrops_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_ObjectAccess_FirewallConnection_defined)
    $Audit_ObjectAccess_FirewallConnection = GUID$("{0cce9226-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_ObjectAccess_FirewallConnection_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_ObjectAccess_Other_defined)
    $Audit_ObjectAccess_Other = GUID$("{0cce9227-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_ObjectAccess_Other_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_PrivilegeUse_Sensitive_defined)
    $Audit_PrivilegeUse_Sensitive = GUID$("{0cce9228-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_PrivilegeUse_Sensitive_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_PrivilegeUse_NonSensitive_defined)
    $Audit_PrivilegeUse_NonSensitive = GUID$("{0cce9229-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_PrivilegeUse_NonSensitive_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_PrivilegeUse_Others_defined)
    $Audit_PrivilegeUse_Others = GUID$("{0cce922a-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_PrivilegeUse_Others_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_DetailedTracking_ProcessCreation_defined)
    $Audit_DetailedTracking_ProcessCreation = GUID$("{0cce922b-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_DetailedTracking_ProcessCreation_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_DetailedTracking_ProcessTermination_defined)
    $Audit_DetailedTracking_ProcessTermination = GUID$("{0cce922c-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_DetailedTracking_ProcessTermination_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_DetailedTracking_DpapiActivity_defined)
    $Audit_DetailedTracking_DpapiActivity = GUID$("{0cce922d-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_DetailedTracking_DpapiActivity_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_DetailedTracking_RpcCall_defined)
    $Audit_DetailedTracking_RpcCall = GUID$("{0cce922e-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_DetailedTracking_RpcCall_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_PolicyChange_AuditPolicy_defined)
    $Audit_PolicyChange_AuditPolicy = GUID$("{0cce922f-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_PolicyChange_AuditPolicy_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_PolicyChange_AuthenticationPolicy_defined)
    $Audit_PolicyChange_AuthenticationPolicy = GUID$("{0cce9230-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_PolicyChange_AuthenticationPolicy_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_PolicyChange_AuthorizationPolicy_defined)
    $Audit_PolicyChange_AuthorizationPolicy = GUID$("{0cce9231-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_PolicyChange_AuthorizationPolicy_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_PolicyChange_MpsscvRulePolicy_defined)
    $Audit_PolicyChange_MpsscvRulePolicy = GUID$("{0cce9232-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_PolicyChange_MpsscvRulePolicy_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_PolicyChange_WfpIPSecPolicy_defined)
    $Audit_PolicyChange_WfpIPSecPolicy = GUID$("{0cce9233-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_PolicyChange_WfpIPSecPolicy_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_PolicyChange_Others_defined)
    $Audit_PolicyChange_Others = GUID$("{0cce9234-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_PolicyChange_Others_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_AccountManagement_UserAccount_defined)
    $Audit_AccountManagement_UserAccount = GUID$("{0cce9235-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_AccountManagement_UserAccount_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_AccountManagement_ComputerAccount_defined)
    $Audit_AccountManagement_ComputerAccount = GUID$("{0cce9236-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_AccountManagement_ComputerAccount_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_AccountManagement_SecurityGroup_defined)
    $Audit_AccountManagement_SecurityGroup = GUID$("{0cce9237-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_AccountManagement_SecurityGroup_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_AccountManagement_DistributionGroup_defined)
    $Audit_AccountManagement_DistributionGroup = GUID$("{0cce9238-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_AccountManagement_DistributionGroup_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_AccountManagement_ApplicationGroup_defined)
    $Audit_AccountManagement_ApplicationGroup = GUID$("{0cce9239-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_AccountManagement_ApplicationGroup_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_AccountManagement_Others_defined)
    $Audit_AccountManagement_Others = GUID$("{0cce923a-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_AccountManagement_Others_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_DSAccess_DSAccess_defined)
    $Audit_DSAccess_DSAccess = GUID$("{0cce923b-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_DSAccess_DSAccess_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_DsAccess_AdAuditChanges_defined)
    $Audit_DsAccess_AdAuditChanges = GUID$("{0cce923c-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_DsAccess_AdAuditChanges_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_Ds_Replication_defined)
    $Audit_Ds_Replication = GUID$("{0cce923d-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_Ds_Replication_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_Ds_DetailedReplication_defined)
    $Audit_Ds_DetailedReplication = GUID$("{0cce923e-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_Ds_DetailedReplication_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_AccountLogon_CredentialValidation_defined)
    $Audit_AccountLogon_CredentialValidation = GUID$("{0cce923f-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_AccountLogon_CredentialValidation_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_AccountLogon_Kerberos_defined)
    $Audit_AccountLogon_Kerberos = GUID$("{0cce9240-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_AccountLogon_Kerberos_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_AccountLogon_Others_defined)
    $Audit_AccountLogon_Others = GUID$("{0cce9241-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_AccountLogon_Others_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_AccountLogon_KerbCredentialValidation_defined)
    $Audit_AccountLogon_KerbCredentialValidation = GUID$("{0cce9242-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_AccountLogon_KerbCredentialValidation_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_Logon_NPS_defined)
    $Audit_Logon_NPS = GUID$("{0cce9243-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_Logon_NPS_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_ObjectAccess_DetailedFileShare_defined)
    $Audit_ObjectAccess_DetailedFileShare = GUID$("{0cce9244-69ae-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_ObjectAccess_DetailedFileShare_defined = 1
    #ENDIF
#ENDIF

#ENDIF ' DEFINE_GUID


'
' All categories are named as <Audit_CategoryName>
'

#IF %DEF(%DEFINE_GUID)

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_System_defined)
    $Audit_System = GUID$("{69979848-797a-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_System_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_Logon_defined)
    $Audit_Logon = GUID$("{69979849-797a-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_Logon_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_ObjectAccess_defined)
    $Audit_ObjectAccess = GUID$("{6997984a-797a-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_ObjectAccess_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_PrivilegeUse_defined)
    $Audit_PrivilegeUse = GUID$("{6997984b-797a-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_PrivilegeUse_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_DetailedTracking_defined)
    $Audit_DetailedTracking = GUID$("{6997984c-797a-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_DetailedTracking_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_PolicyChange_defined)
    $Audit_PolicyChange = GUID$("{6997984d-797a-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_PolicyChange_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_AccountManagement_defined)
    $Audit_AccountManagement = GUID$("{6997984e-797a-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_AccountManagement_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_DirectoryServiceAccess_defined)
    $Audit_DirectoryServiceAccess = GUID$("{6997984f-797a-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_DirectoryServiceAccess_defined = 1
    #ENDIF
#ENDIF

#IF NOT %DEF(%INITGUID) OR NOT %DEF(%Audit_AccountLogon_defined)
    $Audit_AccountLogon = GUID$("{69979850-797a-11d9-bed3-505054503030}")
    #IF %DEF(%INITGUID)
        %Audit_AccountLogon_defined = 1
    #ENDIF
#ENDIF

#ENDIF  ' %DEFINE_GUID


#IF NOT %DEF(%NTSECAPI)

%NTSECAPI = 1

#IF NOT %DEF(%NTDEF)
%NTDEF = 1
MACRO NTSTATUS=LONG
#ENDIF

#INCLUDE "lsalookup.inc"

#IF NOT %DEF(%NTLSA_IFS)
' begin_ntifs


'
' Security operation mode of the system is held in a control
' longword.
'

MACRO LSA_OPERATIONAL_MODE=DWORD

' end_ntifs
#ENDIF ' %NTLSA_IFS

'
' The flags in the security operational mode are defined
' as:
'
'    PasswordProtected - Some level of authentication (such as
'        a password) must be provided by users before they are
'        allowed to use the system.  Once set, this value will
'        not be cleared without re-booting the system.
'
'    IndividualAccounts - Each user must identify an account to
'        logon to.  This flag is only meaningful if the
'        PasswordProtected flag is also set.  If this flag is
'        not set and the PasswordProtected flag is set, then all
'        users may logon to the same account.  Once set, this value
'        will not be cleared without re-booting the system.
'
'    MandatoryAccess - Indicates the system is running in a mandatory
'        access control mode (e.g., B-level as defined by the U.S.A's
'        Department of Defense's "Orange Book").  This is not utilized
'        in the current release of NT.  This flag is only meaningful
'        if both the PasswordProtected and IndividualAccounts flags are
'        set.  Once set, this value will not be cleared without
'        re-booting the system. [PB note: this comment may be outdated]
'
'    LogFull - Indicates the system has been brought up in a mode in
'        which if must perform security auditing, but its audit log
'        is full.  This may (should) restrict the operations that
'        can occur until the audit log is made not-full again.  THIS
'        VALUE MAY BE CLEARED WHILE THE SYSTEM IS RUNNING (I.E., WITHOUT
'        REBOOTING).
'
' If the PasswordProtected flag is not set, then the system is running
' without security, and user interface should be adjusted appropriately.
'

%LSA_MODE_PASSWORD_PROTECTED   = &H00000001
%LSA_MODE_INDIVIDUAL_ACCOUNTS  = &H00000002
%LSA_MODE_MANDATORY_ACCESS     = &H00000004
%LSA_MODE_LOG_FULL             = &H00000008

#IF NOT %DEF(%NTLSA_IFS)
' begin_ntifs
'
' Used by a logon process to indicate what type of logon is being
' requested.
'

MACRO SECURITY_LOGON_TYPE_enum=LONG
ENUM SECURITY_LOGON_TYPE SINGULAR
    UndefinedLogonType      = 0  ' This is used to specify an undefied logon type
    Interactive             = 2  ' Interactively logged on (locally or remotely)
    Network                      ' Accessing system via network
    Batch                        ' Started via a batch queue
    Service                      ' Service started by service controller
    Proxy                        ' Proxy logon
    UNLOCK                       ' Unlock workstation
    NetworkCleartext             ' Network logon with cleartext credentials
    NewCredentials               ' Clone caller, new default credentials
    'The types below only exist in Windows XP and greater
#IF (%WIN32_WINNT >= &H0501)
    RemoteInteractive            ' Remote, yet interactive. Terminal server
    CachedInteractive            ' Try cached credentials without hitting the net.
#ENDIF
    ' The types below only exist in Windows Server 2003 and greater
#IF (%WIN32_WINNT >= &H0502)
    CachedRemoteInteractive      ' Same as RemoteInteractive                      = x this is used internally for auditing purpose
    CachedUnlock                 ' Cached Unlock workstation
#ENDIF
END ENUM

' end_ntifs
#ENDIF ' %NTLSA_IFS


#IF NOT %DEF(%NTLSA_IFS)
' begin_ntifs

'
' All of this stuff (between the Ifndef _NTLSA_AUDIT_ and its endif) were not
' present in NTIFS prior to Windows Server 2003 SP1. All of the definitions however
' exist down to windows 2000 (except for the few exceptions noted in the code).
'

#IF NOT %DEF(%NTLSA_AUDIT)
%NTLSA_AUDIT = 1

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''                                                                     ''
'' Data types related to Auditing                                      ''
''                                                                     ''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''


'
' The following enumerated type is used between the reference monitor and
' LSA in the generation of audit messages.  It is used to indicate the
' type of data being passed as a parameter from the reference monitor
' to LSA.  LSA is responsible for transforming the specified data type
' into a set of unicode strings that are added to the event record in
' the audit log.
'

MACRO SE_ADT_PARAMETER_TYPE_enum=LONG
ENUM SE_ADT_PARAMETER_TYPE SINGULAR

    SeAdtParmTypeNone               'Produces 1 parameter
                                    'Received value:
                                    '
                                    '  None.
                                    '
                                    'Results in:
                                    '
                                    '  a unicode string containing "-".
                                    '
                                    'Note:  This is typically used to
                                    '       indicate that a parameter value
                                    '       was not available.
                                    '

    SeAdtParmTypeString             'Produces 1 parameter.
                                    'Received Value:
                                    '
                                    '  Unicode String (variable length)
                                    '
                                    'Results in:
                                    '
                                    '  No transformation.  The string
                                    '  entered into the event record as
                                    '  received.
                                    '
                                    ' The Address value of the audit info
                                    ' should be a pointer to a UNICODE_STRING
                                    ' structure.



    SeAdtParmTypeFileSpec           'Produces 1 parameter.
                                    'Received value:
                                    '
                                    '  Unicode string containing a file or
                                    '  directory name.
                                    '
                                    'Results in:
                                    '
                                    '  Unicode string with the prefix of the
                                    '  file's path replaced by a drive letter
                                    '  if possible.
                                    '


    SeAdtParmTypeUlong              'Produces 1 parameter
                                    'Received value:
                                    '
                                    '  Ulong
                                    '
                                    'Results in:
                                    '
                                    '  Unicode string representation of
                                    '  unsigned integer value.


    SeAdtParmTypeSid                'Produces 1 parameter.
                                    'Received value:
                                    '
                                    '  SID (variable length)
                                    '
                                    'Results in:
                                    '
                                    '  String representation of SID
                                    '


    SeAdtParmTypeLogonId            'Produces 4 parameters.
                                    'Received Value:
                                    '
                                    '  LUID (fixed length)
                                    '
                                    'Results in:
                                    '
                                    '  param 1: Sid string
                                    '  param 2: Username string
                                    '  param 3: domain name string
                                    '  param 4: Logon ID (Luid) string


    SeAdtParmTypeNoLogonId          'Produces 3 parameters.
                                    'Received value:
                                    '
                                    '  None.
                                    '
                                    'Results in:
                                    '
                                    '  param 1: "-"
                                    '  param 2: "-"
                                    '  param 3: "-"
                                    '  param 4: "-"
                                    '
                                    'Note:
                                    '
                                    '  This type is used when a logon ID
                                    '  is needed, but one is not available
                                    '  to pass.  For example, if an
                                    '  impersonation logon ID is expected
                                    '  but the subject is not impersonating
                                    '  anyone.
                                    '

    SeAdtParmTypeAccessMask         'Produces 1 parameter with formatting.
                                    'Received value:
                                    '
                                    '  ACCESS_MASK followed by
                                    '  a Unicode string.  The unicode
                                    '  string contains the name of the
                                    '  type of object the access mask
                                    '  applies to.  The event's source
                                    '  further qualifies the object type.
                                    '
                                    'Results in:
                                    '
                                    '  formatted unicode string built to
                                    '  take advantage of the specified
                                    '  source's parameter message file.
                                    '
                                    'Note:
                                    '
                                    '  An access mask containing three
                                    '  access types for a Widget object
                                    '  type (defined by the Foozle source)
                                    '  might end up looking like:
                                    '
                                    '      %%1062\n\t\t%1066\n\t\t%%601
                                    '
                                    '  The %%numbers are signals to the
                                    '  event viewer to perform parameter
                                    '  substitution before display.
                                    '



    SeAdtParmTypePrivs              'Produces 1 parameter with formatting.
                                    'Received value:
                                    '
                                    'Results in:
                                    '
                                    '  formatted unicode string similar to
                                    '  that for access types.  Each priv
                                    '  will be formatted to be displayed
                                    '  on its own line.  E.g.,
                                    '
                                    '      %%642\n\t\t%%651\n\t\t%%655
                                    '

    SeAdtParmTypeObjectTypes        'Produces 10 parameters with formatting.
                                    'Received value:
                                    '
                                    ' Produces a list a stringized GUIDS along
                                    ' with information similar to that for
                                    ' an access mask.

    SeAdtParmTypeHexUlong           'Produces 1 parameter
                                    'Received value:
                                    '
                                    '  Ulong
                                    '
                                    'Results in:
                                    '
                                    '  Unicode string representation of
                                    '  unsigned integer value in hexadecimal.

' In W2k this value did not exist, it was ParmTypeLUID

    SeAdtParmTypePtr                'Produces 1 parameter
                                    'Received value:
                                    '
                                    '  pointer
                                    '
                                    'Results in:
                                    '
                                    '  Unicode string representation of
                                    '  unsigned integer value in hexadecimal.

'
' Everything below exists only in Windows XP and greater
'

    SeAdtParmTypeTime               'Produces 2 parameters
                                    'Received value:
                                    '
                                    '  LARGE_INTEGER
                                    '
                                    'Results in:
                                    '
                                    ' Unicode string representation of
                                    ' date and time.

                                    '
    SeAdtParmTypeGuid               'Produces 1 parameter
                                    'Received value:
                                    '
                                    '  GUID pointer
                                    '
                                    'Results in:
                                    '
                                    ' Unicode string representation of GUID
                                    ' {xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}
                                    '

'
' Everything below exists only in Windows Server 2003 and Greater
'

    SeAdtParmTypeLuid               '
                                    'Produces 1 parameter
                                    'Received value:
                                    '
                                    ' LUID
                                    '
                                    'Results in:
                                    '
                                    ' Hex LUID
                                    '

    SeAdtParmTypeHexInt64           'Produces 1 parameter
                                    'Received value:
                                    '
                                    '  64 bit integer
                                    '
                                    'Results in:
                                    '
                                    '  Unicode string representation of
                                    '  unsigned integer value in hexadecimal.

    SeAdtParmTypeStringList         'Produces 1 parameter
                                    'Received value:
                                    '
                                    ' ptr to LSAP_ADT_STRING_LIST
                                    '
                                    'Results in:
                                    '
                                    ' Unicode string representation of
                                    ' concatenation of the strings in the list

    SeAdtParmTypeSidList            'Produces 1 parameter
                                    'Received value:
                                    '
                                    ' ptr to LSAP_ADT_SID_LIST
                                    '
                                    'Results in:
                                    '
                                    ' Unicode string representation of
                                    ' concatenation of the SIDs in the list

    SeAdtParmTypeDuration           'Produces 1 parameters
                                    'Received value:
                                    '
                                    '  LARGE_INTEGER
                                    '
                                    'Results in:
                                    '
                                    ' Unicode string representation of
                                    ' a duration.

    SeAdtParmTypeUserAccountControl 'Produces 3 parameters
                                    'Received value:
                                    '
                                    ' old and new UserAccountControl values
                                    '
                                    'Results in:
                                    '
                                    ' Unicode string representations of
                                    ' the flags in UserAccountControl.
                                    ' 1 - old value in hex
                                    ' 2 - new value in hex
                                    ' 3 - difference as strings

    SeAdtParmTypeNoUac              'Produces 3 parameters
                                    'Received value:
                                    '
                                    ' none
                                    '
                                    'Results in:
                                    '
                                    ' Three dashes ('-') as unicode strings.

    SeAdtParmTypeMessage            'Produces 1 Parameter
                                    'Received value:
                                    '
                                    '  DWORD (MessageNo from msobjs.mc)
                                    '
                                    'Results in:
                                    '
                                    ' Unicode string representation of
                                    ' %%MessageNo which the event viewer
                                    ' will replace with the message string
                                    ' from msobjs.mc

    SeAdtParmTypeDateTime           'Produces 1 Parameter
                                    'Received value:
                                    '
                                    '  LARGE_INTEGER
                                    '
                                    'Results in:
                                    '
                                    ' Unicode string representation of
                                    ' date and time (in _one_ string).

    SeAdtParmTypeSockAddr           ' Produces 2 parameters
                                    '
                                    ' Received value:
                                    '
                                    ' pointer to SOCKADDR_IN/SOCKADDR_IN6
                                    ' structure
                                    '
                                    ' Results in:
                                    '
                                    ' param 1: IP address string
                                    ' param 2: Port number string
                                    '

'
' Everything below this exists only in Windows Server 2008 and greater
'

    SeAdtParmTypeSD                 ' Produces 1 parameters
                                    '
                                    ' Received value:
                                    '
                                    ' pointer to SECURITY_DESCRIPTOR
                                    ' structure
                                    '
                                    ' Results in:
                                    '
                                    ' SDDL string representation of SD
                                    '

    SeAdtParmTypeLogonHours         ' Produces 1 parameters
                                    '
                                    ' Received value:
                                    '
                                    ' pointer to LOGON_HOURS
                                    ' structure
                                    '
                                    ' Results in:
                                    '
                                    ' String representation of allowed logon hours
                                    '

    SeAdtParmTypeLogonIdNoSid       'Produces 3 parameters.
                                    'Received Value:
                                    '
                                    '  LUID (fixed length)
                                    '
                                    'Results in:
                                    '
                                    '  param 1: Username string
                                    '  param 2: domain name string
                                    '  param 3: Logon ID (Luid) string

    SeAdtParmTypeUlongNoConv        ' Produces 1 parameter.
                                    ' Received Value:
                                    ' Ulong
                                    '
                                    'Results in:
                                    ' Not converted to string
                                    '

    SeAdtParmTypeSockAddrNoPort     ' Produces 1 parameter
                                    '
                                    ' Received value:
                                    '
                                    ' pointer to SOCKADDR_IN/SOCKADDR_IN6
                                    ' structure
                                    '
                                    ' Results in:
                                    '
                                    ' param 1: IPv4/IPv6 address string
                                    '
'
' Everything below this exists only in Windows Server 2008 and greater
'

    SeAdtParmTypeAccessReason       ' Produces 1 parameters
                                    '
                                    ' Received value:
                                    '
                                    ' pointer to SECURITY_DESCRIPTOR
                                    ' structure followed by the reason code.
                                    ' The reason code could be the index
                                    ' of the ACE in the SD or privilege ID or
                                    ' other reason codes.
                                    '
                                    ' Results in:
                                    '
                                    ' String representation of the access reason.
                                    '
END ENUM  ' SE_ADT_PARAMETER_TYPE

'#include "guiddef.inc"

%SE_ADT_OBJECT_ONLY = &H1
TYPE SE_ADT_OBJECT_TYPE
    ObjectType AS GUID
    Flags      AS WORD
    Level      AS WORD
    AccessMask AS DWORD ' ACCESS_MASK
END TYPE

TYPE SE_ADT_PARAMETER_ARRAY_ENTRY
    nType    AS SE_ADT_PARAMETER_TYPE_enum
    Length   AS DWORD
    DATA(1)  AS DWORD  ' ULONG_PTR
    Address  AS DWORD  ' PVOID
END TYPE


TYPE SE_ADT_ACCESS_REASON
    AccessMask         AS DWORD  ' ACCESS_MASK
    AccessReasons(31)  AS DWORD
    ObjectTypeIndex    AS DWORD
    AccessGranted      AS DWORD
    ' multiple SDs may be stored here in self-relative way.
    SecurityDescriptor AS SECURITY_DESCRIPTOR PTR
END TYPE



'
' Structure that will be passed between the Reference Monitor and LSA
' to transmit auditing information.
'

%SE_MAX_AUDIT_PARAMETERS = 32
%SE_MAX_GENERIC_AUDIT_PARAMETERS = 28

TYPE SE_ADT_PARAMETER_ARRAY
    CategoryId        AS DWORD
    AuditId           AS DWORD
    ParameterCount    AS DWORD
    Length            AS DWORD
    FlatSubCategoryId AS WORD
    nType             AS WORD
    Flags             AS DWORD
    Parameters(%SE_MAX_AUDIT_PARAMETERS-1) AS SE_ADT_PARAMETER_ARRAY_ENTRY
END TYPE


%SE_ADT_PARAMETERS_SELF_RELATIVE    = &H00000001
%SE_ADT_PARAMETERS_SEND_TO_LSA      = &H00000002
%SE_ADT_PARAMETER_EXTENSIBLE_AUDIT  = &H00000004
%SE_ADT_PARAMETER_GENERIC_AUDIT     = &H00000008
%SE_ADT_PARAMETER_WRITE_SYNCHRONOUS = &H00000010


'
' This macro only existed in Windows Server 2008 and after
'

'#define LSAP_SE_ADT_PARAMETER_ARRAY_TRUE_SIZE(AuditParameters)    \
'     ( sizeof(SE_ADT_PARAMETER_ARRAY) -                           \
'       sizeof(SE_ADT_PARAMETER_ARRAY_ENTRY) *                     \
'       (SE_MAX_AUDIT_PARAMETERS - AuditParameters->ParameterCount) )

#ENDIF ' %NTLSA_AUDIT

' end_ntifs
#ENDIF ' %NTLSA_IFS


'
' Audit Event Categories
'
' The following are the built-in types or Categories of audit event.
' WARNING!  This structure is subject to expansion.  The user should not
' compute the number of elements of this type directly, but instead
' should obtain the count of elements by calling LsaQueryInformationPolicy()
' for the PolicyAuditEventsInformation class and extracting the count from
' the MaximumAuditEventCount field of the returned structure.
'
MACRO POLICY_AUDIT_EVENT_TYPE_enum=LONG
ENUM POLICY_AUDIT_EVENT_TYPE SINGULAR
    AuditCategorySystem
    AuditCategoryLogon
    AuditCategoryObjectAccess
    AuditCategoryPrivilegeUse
    AuditCategoryDetailedTracking
    AuditCategoryPolicyChange
    AuditCategoryAccountManagement
    AuditCategoryDirectoryServiceAccess
    AuditCategoryAccountLogon
END ENUM

'
' The following defines describe the auditing options for each
' event type
'

' Leave options specified for this event unchanged

%POLICY_AUDIT_EVENT_UNCHANGED   = &H00000000

' Audit successful occurrences of events of this type

%POLICY_AUDIT_EVENT_SUCCESS     = &H00000001

' Audit failed attempts to cause an event of this type to occur

%POLICY_AUDIT_EVENT_FAILURE     = &H00000002

%POLICY_AUDIT_EVENT_NONE        = &H00000004

' Mask of valid event auditing options

%POLICY_AUDIT_EVENT_MASK = _
    %POLICY_AUDIT_EVENT_SUCCESS OR _
    %POLICY_AUDIT_EVENT_FAILURE OR _
    %POLICY_AUDIT_EVENT_UNCHANGED OR _
    %POLICY_AUDIT_EVENT_NONE


'
' Macro for determining whether an API succeeded.
'

MACRO LSA_SUCCESS(nError) = ABS(BITS(LONG, nError) >= 0)

#IF NOT %DEF(%NTLSA_IFS)
' begin_ntifs

DECLARE FUNCTION LsaRegisterLogonProcess LIB "SECUR32.DLL" _
   ALIAS "LsaRegisterLogonProcess" ( _
    LogonProcessName AS LSA_STRING, _
    LsaHandle        AS DWORD, _
    SecurityMode     AS DWORD _
    ) AS LONG

'
' The function below did not exist in NTIFS before windows XP
' However, the function has always been there, so it is okay to use
' even on w2k
'
DECLARE FUNCTION LsaLogonUser LIB "SECUR32.DLL" _
   ALIAS "LsaLogonUser" ( _
    BYVAL LsaHandle                       AS DWORD, _
    OriginName                            AS LSA_STRING, _
    BYVAL LogonType                       AS LONG, _
    BYVAL AuthenticationPackage           AS DWORD , _
    BYVAL AuthenticationInformation       AS DWORD, _
    BYVAL AuthenticationInformationLength AS DWORD , _
    BYVAL LocalGroups                     AS TOKEN_GROUPS PTR, _
    SourceContext                         AS TOKEN_SOURCE, _
    ProfileBuffer                         AS DWORD, _
    ProfileBufferLength                   AS DWORD, _
    LogonId                               AS QUAD, _
    Token                                 AS DWORD, _
    Quotas                                AS QUOTA_LIMITS, _
    SubStatus                             AS LONG _
    ) AS LONG

' end_ntifs

DECLARE FUNCTION LsaLookupAuthenticationPackage LIB "SECUR32.DLL" _
   ALIAS "LsaLookupAuthenticationPackage" ( _
    LsaHandle             AS DWORD, _
    PackageName           AS LSA_STRING, _
    AuthenticationPackage AS DWORD _
    ) AS LONG

' begin_ntifs

DECLARE FUNCTION LsaFreeReturnBuffer LIB "SECUR32.DLL" _
   ALIAS "LsaFreeReturnBuffer" ( _
    BYVAL Buffer AS DWORD _
    ) AS LONG

' end_ntifs

DECLARE FUNCTION LsaCallAuthenticationPackage LIB "SECUR32.DLL" _
   ALIAS "LsaCallAuthenticationPackage" ( _
    BYVAL LsaHandle             AS DWORD, _
    BYVAL AuthenticationPackage AS DWORD, _
    BYVAL ProtocolSubmitBuffer  AS DWORD, _
    BYVAL SubmitBufferLength    AS DWORD, _
    ProtocolReturnBuffer        AS DWORD, _
    ReturnBufferLength          AS DWORD, _
    ProtocolStatus              AS LONG _
    ) AS LONG

DECLARE FUNCTION LsaDeregisterLogonProcess LIB "SECUR32.DLL" _
   ALIAS "LsaDeregisterLogonProcess" ( _
    BYVAL LsaHandle AS DWORD _
    ) AS LONG

DECLARE FUNCTION LsaConnectUntrusted LIB "SECUR32.DLL" _
   ALIAS "LsaConnectUntrusted" ( _
    LsaHandle AS DWORD _
    ) AS LONG

#ENDIF  ' %NTLSA_IFS


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''                                                                        ''
'' Local Security Policy Administration API datatypes and defines         ''
''                                                                        ''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

'
' Access types for the Policy object
'

%POLICY_VIEW_LOCAL_INFORMATION   = &H00000001
%POLICY_VIEW_AUDIT_INFORMATION   = &H00000002
%POLICY_GET_PRIVATE_INFORMATION  = &H00000004
%POLICY_TRUST_ADMIN              = &H00000008
%POLICY_CREATE_ACCOUNT           = &H00000010
%POLICY_CREATE_SECRET            = &H00000020
%POLICY_CREATE_PRIVILEGE         = &H00000040
%POLICY_SET_DEFAULT_QUOTA_LIMITS = &H00000080
%POLICY_SET_AUDIT_REQUIREMENTS   = &H00000100
%POLICY_AUDIT_LOG_ADMIN          = &H00000200
%POLICY_SERVER_ADMIN             = &H00000400
%POLICY_LOOKUP_NAMES             = &H00000800
%POLICY_NOTIFICATION             = &H00001000

%POLICY_ALL_ACCESS =   %STANDARD_RIGHTS_REQUIRED         OR _
                       %POLICY_VIEW_LOCAL_INFORMATION    OR _
                       %POLICY_VIEW_AUDIT_INFORMATION    OR _
                       %POLICY_GET_PRIVATE_INFORMATION   OR _
                       %POLICY_TRUST_ADMIN               OR _
                       %POLICY_CREATE_ACCOUNT            OR _
                       %POLICY_CREATE_SECRET             OR _
                       %POLICY_CREATE_PRIVILEGE          OR _
                       %POLICY_SET_DEFAULT_QUOTA_LIMITS  OR _
                       %POLICY_SET_AUDIT_REQUIREMENTS    OR _
                       %POLICY_AUDIT_LOG_ADMIN           OR _
                       %POLICY_SERVER_ADMIN              OR _
                       %POLICY_LOOKUP_NAMES

%POLICY_READ       =   %STANDARD_RIGHTS_READ             OR _
                       %POLICY_VIEW_AUDIT_INFORMATION    OR _
                       %POLICY_GET_PRIVATE_INFORMATION

%POLICY_WRITE      =   %STANDARD_RIGHTS_WRITE            OR _
                       %POLICY_TRUST_ADMIN               OR _
                       %POLICY_CREATE_ACCOUNT            OR _
                       %POLICY_CREATE_SECRET             OR _
                       %POLICY_CREATE_PRIVILEGE          OR _
                       %POLICY_SET_DEFAULT_QUOTA_LIMITS  OR _
                       %POLICY_SET_AUDIT_REQUIREMENTS    OR _
                       %POLICY_AUDIT_LOG_ADMIN           OR _
                       %POLICY_SERVER_ADMIN

%POLICY_EXECUTE    =   %STANDARD_RIGHTS_EXECUTE          OR _
                       %POLICY_VIEW_LOCAL_INFORMATION    OR _
                       %POLICY_LOOKUP_NAMES


'
' Legacy policy object specific data types.
'
'
' The following data type is used in name to SID lookup services to describe
' the domains referenced in the lookup operation.
'

TYPE LSA_TRANSLATED_SID
    Use         AS SID_NAME_USE_enum
    RelativeId  AS DWORD
    DomainIndex AS LONG
END TYPE

' where members have the following usage:
'
'     Use - identifies the use of the SID.  If this value is SidUnknown or
'         SidInvalid, then the remainder of the record is not set and
'         should be ignored.
'
'     RelativeId - Contains the relative ID of the translated SID.  The
'         remainder of the SID (the prefix) is obtained using the
'         DomainIndex field.
'
'     DomainIndex - Is the index of an entry in a related
'         LSA_REFERENCED_DOMAIN_LIST data structure describing the
'         domain in which the account was found.
'
'         If there is no corresponding reference domain for an entry, then
'         this field will contain a negative value.
'


'
' The following data type is used to represent the role of the LSA
' server (primary or backup).
'

MACRO POLICY_LSA_SERVER_ROLE_enum=LONG
ENUM POLICY_LSA_SERVER_ROLE SINGULAR
    PolicyServerRoleBackup  = 2
    PolicyServerRolePrimary = 3
END ENUM

#IF (%WIN32_WINNT < &H0502)
'
' The following data type is used to represent the state of the LSA
' server (enabled or disabled).  Some operations may only be performed on
' an enabled LSA server.
'

MACRO POLICY_SERVER_ENABLE_STATE_enum=LONG
ENUM POLICY_SERVER_ENABLE_STATE SINGULAR
    PolicyServerEnabled  = 2
    PolicyServerDisabled = 3
END ENUM

#ENDIF ' #IF (%WIN32_WINNT < &H0502)

'
' The following data type is used to specify the auditing options for
' an Audit Event Type.
'

MACRO POLICY_AUDIT_EVENT_OPTIONS=DWORD

' where the following flags can be set:
'
'     %POLICY_AUDIT_EVENT_UNCHANGED - Leave existing auditing options
'         unchanged for events of this type.  This flag is only used for
'         set operations.  If this flag is set, then all other flags
'         are ignored.
'
'     %POLICY_AUDIT_EVENT_NONE - Cancel all auditing options for events
'         of this type.  If this flag is set, the success/failure flags
'         are ignored.
'
'     %POLICY_AUDIT_EVENT_SUCCESS - When auditing is enabled, audit all
'         successful occurrences of events of the given type.
'
'     %POLICY_AUDIT_EVENT_FAILURE - When auditing is enabled, audit all
'         unsuccessful occurrences of events of the given type.
'




'
' The following data type defines the classes of Policy Information
' that may be queried/set.
'

MACRO POLICY_INFORMATION_CLASS_enum=LONG
ENUM POLICY_INFORMATION_CLASS SINGULAR
    PolicyAuditLogInformation           = 1
    PolicyAuditEventsInformation
    PolicyPrimaryDomainInformation
    PolicyPdAccountInformation
    PolicyAccountDomainInformation
    PolicyLsaServerRoleInformation
    PolicyReplicaSourceInformation
    PolicyDefaultQuotaInformation
    PolicyModificationInformation
    PolicyAuditFullSetInformation
    PolicyAuditFullQueryInformation
    PolicyDnsDomainInformation
    PolicyDnsDomainInformationInt
    PolicyLocalAccountDomainInformation
    PolicyLastEntry
END ENUM


'
' The following data type corresponds to the PolicyAuditLogInformation
' information class.  It is used to represent information relating to
' the Audit Log.
'
' This structure may be used in both query and set operations.  However,
' when used in set operations, some fields are ignored.
'

TYPE POLICY_AUDIT_LOG_INFO DWORD FILL
    AuditLogPercentFull            AS DWORD
    MaximumLogSize                 AS DWORD
    AuditRetentionPeriod           AS QUAD
    AuditLogFullShutdownInProgress AS BYTE
    TimeToShutdown                 AS QUAD
    NextAuditRecordId              AS DWORD
END TYPE

' where the members have the following usage:
'
'     AuditLogPercentFull - Indicates the percentage of the Audit Log
'         currently being used.
'
'     MaximumLogSize - Specifies the maximum size of the Audit Log in
'         kilobytes.
'
'     AuditRetentionPeriod - Indicates the length of time that Audit
'         Records are to be retained.  Audit Records are discardable
'         if their timestamp predates the current time minus the
'         retention period.
'
'     AuditLogFullShutdownInProgress - Indicates whether or not a system
'         shutdown is being initiated due to the security Audit Log becoming
'         full.  This condition will only occur if the system is configured
'         to shutdown when the log becomes full.
'
'         TRUE indicates that a shutdown is in progress
'         FALSE indicates that a shutdown is not in progress.
'
'         Once a shutdown has been initiated, this flag will be set to
'         TRUE.  If an administrator is able to currect the situation
'         before the shutdown becomes irreversible, then this flag will
'         be reset to false.
'
'         This field is ignored for set operations.
'
'     TimeToShutdown - If the AuditLogFullShutdownInProgress flag is set,
'         then this field contains the time left before the shutdown
'         becomes irreversible.
'
'         This field is ignored for set operations.
'


'
' The following data type corresponds to the PolicyAuditEventsInformation
' information class.  It is used to represent information relating to
' the audit requirements.
'

TYPE POLICY_AUDIT_EVENTS_INFO DWORD FILL
    AuditingMode           AS BYTE
    EventAuditingOptions   AS DWORD PTR
    MaximumAuditEventCount AS DWORD
END TYPE

' where the members have the following usage:
'
'     AuditingMode - A Boolean variable specifying the Auditing Mode value.
'         This value is interpreted as follows:
'
'         TRUE - Auditing is to be enabled (set operations) or is enabled
'             (query operations).  Audit Records will be generated according
'             to the Event Auditing Options in effect (see the
'             EventAuditingOptions field.
'
'         FALSE - Auditing is to be disabled (set operations) or is
'             disabled (query operations).  No Audit Records will be
'             generated.  Note that for set operations the Event Auditing
'             Options in effect will still be updated as specified by the
'             EventAuditingOptions field whether Auditing is enabled or
'             disabled.
'
'    EventAuditingOptions - Pointer to an array of Auditing Options
'        indexed by Audit Event Type.
'
'    MaximumAuditEventCount - Specifiesa count of the number of Audit
'        Event Types specified by the EventAuditingOptions parameter.  If
'        this count is less than the number of Audit Event Types supported
'        by the system, the Auditing Options for Event Types with IDs
'        higher than (MaximumAuditEventCount + 1) are left unchanged.
'

'
' The following data type is used to represent information relating to
' the audit requirements.
'

TYPE POLICY_AUDIT_SUBCATEGORIES_INFO
    MaximumSubCategoryCount AS DWORD
    EventAuditingOptions    AS POLICY_AUDIT_EVENT_OPTIONS PTR
END TYPE

TYPE POLICY_AUDIT_CATEGORIES_INFO
    MaximumCategoryCount AS DWORD
    SubCategoriesInfo    AS POLICY_AUDIT_SUBCATEGORIES_INFO PTR
END TYPE

'
' Valid bits for Per user policy mask.
'

%PER_USER_POLICY_UNCHANGED          = &H00
%PER_USER_AUDIT_SUCCESS_INCLUDE     = &H01
%PER_USER_AUDIT_SUCCESS_EXCLUDE     = &H02
%PER_USER_AUDIT_FAILURE_INCLUDE     = &H04
%PER_USER_AUDIT_FAILURE_EXCLUDE     = &H08
%PER_USER_AUDIT_NONE                = &H10


%VALID_PER_USER_AUDIT_POLICY_FLAG   = (%PER_USER_AUDIT_SUCCESS_INCLUDE OR _
                                       %PER_USER_AUDIT_SUCCESS_EXCLUDE OR _
                                       %PER_USER_AUDIT_FAILURE_INCLUDE OR _
                                       %PER_USER_AUDIT_FAILURE_EXCLUDE OR _
                                       %PER_USER_AUDIT_NONE)


'
' The following structure corresponds to the PolicyPrimaryDomainInformation
' information class.
'

TYPE POLICY_PRIMARY_DOMAIN_INFO
    uName AS LSA_UNICODE_STRING
    pSid AS SID PTR
END TYPE

' where the members have the following usage:
'
'     Name - Is the name of the domain
'
'     Sid - Is the Sid of the domain
'

'
' The following structure corresponds to the PolicyPdAccountInformation
' information class.  This structure may be used in Query operations
' only.
'

TYPE POLICY_PD_ACCOUNT_INFO
    uName AS LSA_UNICODE_STRING
END TYPE

' where the members have the following usage:
'
'     Name - Is the name of an account in the domain that should be used
'         for authentication and name/ID lookup requests.
'


'
' The following structure corresponds to the PolicyLsaServerRoleInformation
' information class.
'

TYPE POLICY_LSA_SERVER_ROLE_INFO
    LsaServerRole AS LONG
END TYPE

' where the fields have the following usage:
'
' TBS
'


'
' The following structure corresponds to the PolicyReplicaSourceInformation
' information class.
'

TYPE POLICY_REPLICA_SOURCE_INFO
    ReplicaSource      AS LSA_UNICODE_STRING
    ReplicaAccountName AS LSA_UNICODE_STRING
END TYPE


'
' The following structure corresponds to the PolicyDefaultQuotaInformation
' information class.
'

TYPE POLICY_DEFAULT_QUOTA_INFO
    QuotaLimits AS QUOTA_LIMITS
END TYPE


'
' The following structure corresponds to the PolicyModificationInformation
' information class.
'

TYPE POLICY_MODIFICATION_INFO
    ModifiedId           AS QUAD
    DatabaseCreationTime AS QUAD
END TYPE

' where the members have the following usage:
'
'     ModifiedId - Is a 64-bit unsigned integer that is incremented each
'         time anything in the LSA database is modified.  This value is
'         only modified on Primary Domain Controllers.
'
'     DatabaseCreationTime - Is the date/time that the LSA Database was
'         created.  On Backup Domain Controllers, this value is replicated
'         from the Primary Domain Controller.
'

'
' The following structure type corresponds to the PolicyAuditFullSetInformation
' Information Class.
'

TYPE POLICY_AUDIT_FULL_SET_INFO
    ShutDownOnFull AS BYTE
END TYPE

'
' The following structure type corresponds to the PolicyAuditFullQueryInformation
' Information Class.
'

TYPE POLICY_AUDIT_FULL_QUERY_INFO
    ShutDownOnFull AS BYTE
    LogIsFull AS BYTE
END TYPE

'
' The following data type defines the classes of Policy Information
' that may be queried/set that has domain wide effect.
'

MACRO POLICY_DOMAIN_INFORMATION_CLASS_enum=LONG
ENUM POLICY_DOMAIN_INFORMATION_CLASS SINGULAR

#IF (%WIN32_WINNT <= &H0500)
    'PolicyDomainQualityOfServiceInformation = 0
    PolicyDomainQualityOfServiceInformation = 1
#ENDIF
    PolicyDomainEfsInformation              = 2
    PolicyDomainKerberosTicketInformation

END ENUM

#IF (%WIN32_WINNT < &H0502)
'
' QualityOfService information. Corresponds to PolicyDomainQualityOfServiceInformation
'

%POLICY_QOS_SCHANNEL_REQUIRED            = &H00000001
%POLICY_QOS_OUTBOUND_INTEGRITY           = &H00000002
%POLICY_QOS_OUTBOUND_CONFIDENTIALITY     = &H00000004
%POLICY_QOS_INBOUND_INTEGRITY            = &H00000008
%POLICY_QOS_INBOUND_CONFIDENTIALITY      = &H00000010
%POLICY_QOS_ALLOW_LOCAL_ROOT_CERT_STORE  = &H00000020
%POLICY_QOS_RAS_SERVER_ALLOWED           = &H00000040
%POLICY_QOS_DHCP_SERVER_ALLOWED          = &H00000080

'
' Bits &H00000100 through &HFFFFFFFF are reserved for future use.
'
#ENDIF ' #IF (%WIN32_WINNT < &H0502)

#IF (%WIN32_WINNT = &H0500)

TYPE POLICY_DOMAIN_QUALITY_OF_SERVICE_INFO
    QualityOfService AS DWORD
END TYPE
'
' where the members have the following usage:
'
'  QualityOfService - Determines what specific QOS actions a machine should take
'
#ENDIF ' #IF (%WIN32_WINNT = &H0500)

'
' The following structure corresponds to the PolicyEfsInformation
' information class
'

TYPE POLICY_DOMAIN_EFS_INFO
    InfoLength AS DWORD
    EfsBlob    AS DWORD
END TYPE

'
' where the members have the following usage:
'
'      InfoLength - Length of the EFS Information blob
'
'      EfsBlob - Efs blob data
'


'
' The following structure corresponds to the PolicyDomainKerberosTicketInformation
' information class
'

%POLICY_KERBEROS_VALIDATE_CLIENT = &H00000080


TYPE POLICY_DOMAIN_KERBEROS_TICKET_INFO
    AuthenticationOptions AS DWORD
    MaxServiceTicketAge   AS LARGE_INTEGER
    MaxTicketAge          AS LARGE_INTEGER
    MaxRenewAge           AS LARGE_INTEGER
    MaxClockSkew          AS LARGE_INTEGER
    Reserved              AS LARGE_INTEGER
END TYPE

'
' where the members have the following usage
'
'      AuthenticationOptions -- allowed ticket options (POLICY_KERBEROS_* flags )
'
'      MaxServiceTicketAge   -- Maximum lifetime for a service ticket
'
'      MaxTicketAge -- Maximum lifetime for the initial ticket
'
'      MaxRenewAge -- Maximum cumulative age a renewable ticket can be with
'                     requring authentication
'
'      MaxClockSkew -- Maximum tolerance for synchronization of computer clocks
'
'      Reserved   --  Reserved


'
' The following data type defines the classes of Policy Information / Policy Domain Information
' that may be used to request notification
'

MACRO POLICY_NOTIFICATION_INFORMATION_CLASS_enum=LONG
ENUM POLICY_NOTIFICATION_INFORMATION_CLASS SINGULAR
    PolicyNotifyAuditEventsInformation            = 1
    PolicyNotifyAccountDomainInformation
    PolicyNotifyServerRoleInformation
    PolicyNotifyDnsDomainInformation
    PolicyNotifyDomainEfsInformation
    PolicyNotifyDomainKerberosTicketInformation
    PolicyNotifyMachineAccountPasswordInformation
    PolicyNotifyGlobalSaclInformation
    PolicyNotifyMax                            ' must always be the last entry
END ENUM


'
' LSA RPC Context Handle (Opaque form).  Note that a Context Handle is
' always a pointer type unlike regular handles.
'

'typedef PVOID LSA_HANDLE, *PLSA_HANDLE;


'
' Trusted Domain Object specific data types
'

'
' This data type defines the following information classes that may be
' queried or set.
'

MACRO TRUSTED_INFORMATION_CLASS_enum=LONG
ENUM TRUSTED_INFORMATION_CLASS SINGULAR
    TrustedDomainNameInformation          = 1
    TrustedControllersInformation
    TrustedPosixOffsetInformation
    TrustedPasswordInformation
    TrustedDomainInformationBasic
    TrustedDomainInformationEx
    TrustedDomainAuthInformation
    TrustedDomainFullInformation
    TrustedDomainAuthInformationInternal
    TrustedDomainFullInformationInternal
    TrustedDomainInformationEx2Internal
    TrustedDomainFullInformation2Internal
    TrustedDomainSupportedEncryptionTypes
END ENUM


'
' The following data type corresponds to the TrustedDomainNameInformation
' information class.
'

TYPE TRUSTED_DOMAIN_NAME_INFO
    uName AS LSA_UNICODE_STRING
END TYPE

' where members have the following meaning:
'
' Name - The name of the Trusted Domain.
'

'
' The following data type corresponds to the TrustedControllersInformation
' information class.
'

TYPE TRUSTED_CONTROLLERS_INFO
    Entries AS DWORD
    Names   AS LSA_UNICODE_STRING PTR
END TYPE

' where members have the following meaning:
'
' Entries - Indicate how mamy entries there are in the Names array.
'
' Names - Pointer to an array of LSA_UNICODE_STRING structures containing the
'     names of domain controllers of the domain.  This information may not
'     be accurate and should be used only as a hint.  The order of this
'     list is considered significant and will be maintained.
'
'     By convention, the first name in this list is assumed to be the
'     Primary Domain Controller of the domain.  If the Primary Domain
'     Controller is not known, the first name should be set to the NULL
'     string.
'


'
' The following data type corresponds to the TrustedPosixOffsetInformation
' information class.
'

TYPE TRUSTED_POSIX_OFFSET_INFO
    Offset AS DWORD
END TYPE

' where members have the following meaning:
'
' Offset - Is an offset to use for the generation of Posix user and group
'     IDs from SIDs.  The Posix ID corresponding to any particular SID is
'     generated by adding the RID of that SID to the Offset of the SID's
'     corresponding TrustedDomain object.
'

'
' The following data type corresponds to the TrustedPasswordInformation
' information class.
'

TYPE TRUSTED_PASSWORD_INFO
    Password    AS LSA_UNICODE_STRING
    OldPassword AS LSA_UNICODE_STRING
END TYPE

TYPE TRUSTED_DOMAIN_INFORMATION_BASIC  ' same as LSA_TRUST_INFORMATION
    uName AS LSA_UNICODE_STRING
    pSid  AS SID PTR
END TYPE

'
' Direction of the trust
'
%TRUST_DIRECTION_DISABLED        = &H00000000
%TRUST_DIRECTION_INBOUND         = &H00000001
%TRUST_DIRECTION_OUTBOUND        = &H00000002
%TRUST_DIRECTION_BIDIRECTIONAL   = %TRUST_DIRECTION_INBOUND _
                                OR %TRUST_DIRECTION_OUTBOUND

%TRUST_TYPE_DOWNLEVEL            = &H00000001  ' NT4 and before
%TRUST_TYPE_UPLEVEL              = &H00000002  ' NT5
%TRUST_TYPE_MIT                  = &H00000003  ' Trust with a MIT Kerberos realm

#IF (%WIN32_WINNT < &H0502)
%TRUST_TYPE_DCE                  = &H00000004  ' Trust with a DCE realm
#ENDIF

' Levels &H5 - &H000FFFFF reserved for future use
' Provider specific trust levels are from &H00100000 to &HFFF00000

%TRUST_ATTRIBUTE_NON_TRANSITIVE     = &H00000001  ' Disallow transitivity
%TRUST_ATTRIBUTE_UPLEVEL_ONLY       = &H00000002  ' Trust link only valid for uplevel client

#IF (%WIN32_WINNT = &H0500)
%TRUST_ATTRIBUTE_TREE_PARENT   = &H00400000  ' Denotes that we are setting the trust
                                                    ' to our parent in the org tree...
%TRUST_ATTRIBUTE_TREE_ROOT     = &H00800000  ' Denotes that we are setting the trust
                                                    ' to another tree root in a forest...
' Trust attributes &H00000004 through &H004FFFFF reserved for future use
' Trust attributes &H00F00000 through &H00400000 are reserved for internal use
' Trust attributes &H01000000 through &HFF000000 are reserved for user
' defined values
%TRUST_ATTRIBUTES_VALID  &HFF02FFFF
#ENDIF ' #IF (%WIN32_WINNT = &H0500)

#IF (%WIN32_WINNT < &H0502)
%TRUST_ATTRIBUTE_FILTER_SIDS      = &H00000004  ' Used to quarantine domains
#ELSE
%TRUST_ATTRIBUTE_QUARANTINED_DOMAIN          = &H00000004  ' Used to quarantine domains
#ENDIF

#IF (%WIN32_WINNT >= &H0501)
%TRUST_ATTRIBUTE_FOREST_TRANSITIVE           = &H00000008  ' This link may contain forest trust information
#IF (%WIN32_WINNT >= &H0502)
%TRUST_ATTRIBUTE_CROSS_ORGANIZATION          = &H00000010  ' This trust is to a domain/forest which is not part of this enterprise
%TRUST_ATTRIBUTE_WITHIN_FOREST               = &H00000020  ' Trust is internal to this forest
%TRUST_ATTRIBUTE_TREAT_AS_EXTERNAL           = &H00000040  ' Trust is to be treated as external for trust boundary purposes
#IF (%WIN32_WINNT >= &H0600)
%TRUST_ATTRIBUTE_TRUST_USES_RC4_ENCRYPTION   = &H00000080  ' MIT trust with RC4
%TRUST_ATTRIBUTE_TRUST_USES_AES_KEYS         = &H00000100  ' Use AES keys to encrypte KRB TGTs
#ENDIF ' #IF (%WIN32_WINNT >= &H0600)
' Trust attributes &H00000040 through &H00200000 are reserved for future use
#ELSE
' Trust attributes &H00000010 through &H00200000 are reserved for future use
#ENDIF ' #IF (%WIN32_WINNT >= &H0502)
' Trust attributes &H00400000 through &H00800000 were used previously (up to W2K) and should not be re-used
' Trust attributes &H01000000 through &H80000000 are reserved for user
%TRUST_ATTRIBUTES_VALID        = &HFF03FFFF???
#ENDIF ' #IF (%WIN32_WINNT >= &H0501)
%TRUST_ATTRIBUTES_USER         = &HFF000000???

TYPE TRUSTED_DOMAIN_INFORMATION_EX
    uName           AS LSA_UNICODE_STRING
    FlatName        AS LSA_UNICODE_STRING
    pSid            AS SID PTR
    TrustDirection  AS DWORD
    TrustType       AS DWORD
    TrustAttributes AS DWORD
END TYPE

TYPE TRUSTED_DOMAIN_INFORMATION_EX2
    uName             AS LSA_UNICODE_STRING
    FlatName          AS LSA_UNICODE_STRING
    pSid              AS SID PTR
    TrustDirection    AS DWORD
    TrustType         AS DWORD
    TrustAttributes   AS DWORD
    ForestTrustLength AS DWORD
    ForestTrustInfo   AS WORD PTR
END TYPE

'
' Type of authentication information
'
%TRUST_AUTH_TYPE_NONE    = 0   ' Ignore this entry
%TRUST_AUTH_TYPE_NT4OWF  = 1   ' NT4 OWF password
%TRUST_AUTH_TYPE_CLEAR   = 2   ' Cleartext password
%TRUST_AUTH_TYPE_VERSION = 3   ' Cleartext password version number

TYPE LSA_AUTH_INFORMATION
    LastUpdateTime AS QUAD
    AuthType       AS DWORD
    AuthInfoLength AS DWORD
    AuthInfo       AS WORD PTR
END TYPE

TYPE TRUSTED_DOMAIN_AUTH_INFORMATION
    IncomingAuthInfos                         AS DWORD
    IncomingAuthenticationInformation         AS LSA_AUTH_INFORMATION PTR
    IncomingPreviousAuthenticationInformation AS LSA_AUTH_INFORMATION PTR
    OutgoingAuthInfos                         AS DWORD
    OutgoingAuthenticationInformation         AS LSA_AUTH_INFORMATION PTR
    OutgoingPreviousAuthenticationInformation AS LSA_AUTH_INFORMATION PTR
END TYPE

TYPE TRUSTED_DOMAIN_FULL_INFORMATION
    Information     AS TRUSTED_DOMAIN_INFORMATION_EX
    PosixOffset     AS TRUSTED_POSIX_OFFSET_INFO
    AuthInformation AS TRUSTED_DOMAIN_AUTH_INFORMATION
END TYPE

TYPE TRUSTED_DOMAIN_FULL_INFORMATION2
    Information     AS TRUSTED_DOMAIN_INFORMATION_EX2
    PosixOffset     AS TRUSTED_POSIX_OFFSET_INFO
    AuthInformation AS TRUSTED_DOMAIN_AUTH_INFORMATION
END TYPE

TYPE TRUSTED_DOMAIN_SUPPORTED_ENCRYPTION_TYPES
    SupportedEncryptionTypes AS DWORD
END TYPE

MACRO LSA_FOREST_TRUST_RECORD_TYPE_enum=LONG
ENUM LSA_FOREST_TRUST_RECORD_TYPE SINGULAR
    ForestTrustTopLevelName
    ForestTrustTopLevelNameEx
    ForestTrustDomainInfo     = 2
    ForestTrustRecordTypeLast = 2
END ENUM

#IF (%WIN32_WINNT < &H0502)
%LSA_FOREST_TRUST_RECORD_TYPE_UNRECOGNIZED = &H80000000???
#ENDIF

'
' Bottom 16 bits of the flags are reserved for disablement reasons
'

%LSA_FTRECORD_DISABLED_REASONS = &H0000FFFF

'
' Reasons for a top-level name forest trust record to be disabled
'

%LSA_TLN_DISABLED_NEW      = &H00000001
%LSA_TLN_DISABLED_ADMIN    = &H00000002
%LSA_TLN_DISABLED_CONFLICT = &H00000004

'
' Reasons for a domain information forest trust record to be disabled
'

%LSA_SID_DISABLED_ADMIN    = &H00000001
%LSA_SID_DISABLED_CONFLICT = &H00000002
%LSA_NB_DISABLED_ADMIN     = &H00000004
%LSA_NB_DISABLED_CONFLICT  = &H00000008

TYPE LSA_FOREST_TRUST_DOMAIN_INFO
    pSid        AS SID PTR
    DnsName     AS LSA_UNICODE_STRING
    NetbiosName AS LSA_UNICODE_STRING
END TYPE


#IF (%WIN32_WINNT >= &H0502)
'
' To prevent huge data to be passed in, we should put a limit on LSA_FOREST_TRUST_BINARY_DATA.
'   128K is large enough that can't be reached in the near future, and small enough not to
'   cause memory problems.

%MAX_FOREST_TRUST_BINARY_DATA_SIZE = 128 * 1024
#ENDIF ' #IF (%WIN32_WINNT >= &H0502)

TYPE LSA_FOREST_TRUST_BINARY_DATA
    Length AS DWORD
    Buffer AS WORD PTR
END TYPE

UNION LSA_FOREST_TRUST_RECORD_union
    TopLevelName AS LSA_UNICODE_STRING
    DomainInfo   AS LSA_FOREST_TRUST_DOMAIN_INFO
    nData        AS LSA_FOREST_TRUST_BINARY_DATA  ' used for unrecognized types
END UNION

TYPE LSA_FOREST_TRUST_RECORD
    Flags           AS DWORD
    ForestTrustType AS LSA_FOREST_TRUST_RECORD_TYPE_enum  ' type of record
    Time            AS LARGE_INTEGER
    ForestTrustData AS LSA_FOREST_TRUST_RECORD_union      ' actual data
END TYPE

#IF (%WIN32_WINNT >= &H0502)
'
' To prevent forest trust blobs of large size, number of records must be
' smaller than MAX_RECORDS_IN_FOREST_TRUST_INFO
'

%MAX_RECORDS_IN_FOREST_TRUST_INFO = 4000
#ENDIF ' #IF (%WIN32_WINNT >= &H0502)

TYPE LSA_FOREST_TRUST_INFORMATION
    RecordCount AS DWORD
    Entries     AS DWORD  ' LSA_FOREST_TRUST_RECORD PTR PTR
END TYPE

MACRO LSA_FOREST_TRUST_COLLISION_RECORD_TYPE_enum=LONG
ENUM LSA_FOREST_TRUST_COLLISION_RECORD_TYPE SINGULAR
    CollisionTdo
    CollisionXref
    CollisionOther
END ENUM


TYPE LSA_FOREST_TRUST_COLLISION_RECORD
    Index AS DWORD
    tType AS LSA_FOREST_TRUST_COLLISION_RECORD_TYPE_enum
    Flags AS DWORD
    uName AS LSA_UNICODE_STRING
END TYPE

TYPE LSA_FOREST_TRUST_COLLISION_INFORMATION
    RecordCount AS DWORD
    Entries     AS DWORD  ' LSA_FOREST_TRUST_COLLISION_RECORD PTR PTR
END TYPE


'
' LSA Enumeration Context
'

MACRO LSA_ENUMERATION_HANDLE=DWORD

'
' LSA Enumeration Information
'

TYPE LSA_ENUMERATION_INFORMATION
    pSid AS SID PTR
END TYPE



'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''                                                                       ''
'' Local Security Policy - Miscellaneous API function prototypes         ''
''                                                                       ''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''


DECLARE FUNCTION LsaFreeMemory LIB "ADVAPI32.DLL" _
   ALIAS "LsaFreeMemory" ( _
    BYVAL Buffer AS DWORD _
    ) AS LONG

DECLARE FUNCTION LsaClose LIB "ADVAPI32.DLL" _
   ALIAS "LsaClose" ( _
    BYVAL ObjectHandle AS DWORD _
    ) AS LONG

#IF (%WIN32_WINNT >= &H0600)

TYPE LSA_LAST_INTER_LOGON_INFO
    LastSuccessfulLogon AS LARGE_INTEGER
    LastFailedLogon     AS LARGE_INTEGER
    FailedAttemptCountSinceLastSuccessfulLogon AS DWORD
END TYPE

#ENDIF ' #IF (%WIN32_WINNT >= &H0600)

#IF (%WIN32_WINNT >= &H0501)
TYPE SECURITY_LOGON_SESSION_DATA
    SIZE                  AS DWORD
    LogonId               AS QUAD  ' LUID
    UserName              AS LSA_UNICODE_STRING
    LogonDomain           AS LSA_UNICODE_STRING
    AuthenticationPackage AS LSA_UNICODE_STRING
    LogonType             AS DWORD
    Session               AS DWORD
    pSid                  AS SID PTR
    LogonTime             AS LARGE_INTEGER

    '
    ' new for whistler:
    '

    LogonServer           AS LSA_UNICODE_STRING
    DnsDomainName         AS LSA_UNICODE_STRING
    Upn                   AS LSA_UNICODE_STRING

#IF (%WIN32_WINNT >= &H0600)

    '
    ' new for LH
    '

    UserFlags             AS DWORD

    LastLogonInfo         AS LSA_LAST_INTER_LOGON_INFO
    LogonScript           AS LSA_UNICODE_STRING
    ProfilePath           AS LSA_UNICODE_STRING
    HomeDirectory         AS LSA_UNICODE_STRING
    HomeDirectoryDrive    AS LSA_UNICODE_STRING

    LogoffTime            AS LARGE_INTEGER
    KickOffTime           AS LARGE_INTEGER
    PasswordLastSet       AS LARGE_INTEGER
    PasswordCanChange     AS LARGE_INTEGER
    PasswordMustChange    AS LARGE_INTEGER

#ENDIF ' #IF (%WIN32_WINNT >= &H0600)
END TYPE

DECLARE FUNCTION LsaEnumerateLogonSessions LIB "SECUR32.DLL" _
   ALIAS "LsaEnumerateLogonSessions" ( _
    LogonSessionCount AS DWORD, _
    LogonSessionList  AS DWORD _   ' LUID PTR PTR
    ) AS LONG

DECLARE FUNCTION LsaGetLogonSessionData LIB "SECUR32.DLL" _
   ALIAS "LsaGetLogonSessionData" ( _
    LogonId            AS QUAD, _  ' LUID
    ppLogonSessionData AS DWORD _  ' SECURITY_LOGON_SESSION_DATA PTR PTR
    ) AS LONG
#ENDIF ' #IF (%WIN32_WINNT >= &H0501)

DECLARE FUNCTION LsaOpenPolicy LIB "ADVAPI32.DLL" _
   ALIAS "LsaOpenPolicy" ( _
    SystemName          AS LSA_UNICODE_STRING, _
    ObjectAttributes    AS LSA_OBJECT_ATTRIBUTES, _
    BYVAL DesiredAccess AS DWORD, _  ' ACCESS_MASK
    PolicyHandle        AS DWORD _   ' LSA_HANDLE
    ) AS LONG

DECLARE FUNCTION LsaQueryInformationPolicy LIB "ADVAPI32.DLL" _
   ALIAS "LsaQueryInformationPolicy" ( _
    BYVAL PolicyHandle     AS DWORD, _
    BYVAL InformationClass AS LONG, _
    Buffer                 AS DWORD _
    ) AS LONG

DECLARE FUNCTION LsaSetInformationPolicy LIB "ADVAPI32.DLL" _
   ALIAS "LsaSetInformationPolicy" ( _
    BYVAL PolicyHandle     AS DWORD, _
    BYVAL InformationClass AS LONG, _
    BYVAL Buffer           AS DWORD _
    ) AS LONG

DECLARE FUNCTION LsaQueryDomainInformationPolicy LIB "ADVAPI32.DLL" _
   ALIAS "LsaQueryDomainInformationPolicy" ( _
    BYVAL PolicyHandle     AS DWORD, _
    BYVAL InformationClass AS LONG, _  ' POLICY_DOMAIN_INFORMATION_CLASS
    Buffer                 AS DWORD _
    ) AS LONG

DECLARE FUNCTION LsaSetDomainInformationPolicy LIB "ADVAPI32.DLL" _
   ALIAS "LsaSetDomainInformationPolicy" ( _
    BYVAL PolicyHandle     AS DWORD, _
    BYVAL InformationClass AS LONG, _  ' POLICY_DOMAIN_INFORMATION_CLASS
    BYVAL Buffer           AS DWORD _
    ) AS LONG

DECLARE FUNCTION LsaRegisterPolicyChangeNotification LIB "SECUR32.DLL" _
   ALIAS "LsaRegisterPolicyChangeNotification" ( _
    BYVAL InformationClass AS LONG, _  ' POLICY_NOTIFICATION_INFORMATION_CLASS
    BYVAL NotificationEventHandle AS DWORD _
    ) AS LONG

DECLARE FUNCTION LsaUnregisterPolicyChangeNotification LIB "SECUR32.DLL" _
   ALIAS "LsaUnregisterPolicyChangeNotification" ( _
    BYVAL InformationClass AS LONG, _  ' POLICY_NOTIFICATION_INFORMATION_CLASS
    BYVAL NotificationEventHandle AS DWORD _
    ) AS LONG

DECLARE FUNCTION LsaEnumerateTrustedDomains LIB "ADVAPI32.DLL" _
   ALIAS "LsaEnumerateTrustedDomains" ( _
    BYVAL PolicyHandle AS DWORD, _
    EnumerationContext AS DWORD, _
    Buffer AS DWORD, _
    BYVAL PreferedMaximumLength AS DWORD, _
    CountReturned AS DWORD _
    ) AS LONG

DECLARE FUNCTION LsaLookupNames LIB "ADVAPI32.DLL" _
   ALIAS "LsaLookupNames" ( _
    BYVAL PolicyHandle AS DWORD, _
    BYVAL COUNT AS DWORD, _
    BYVAL Names AS LSA_UNICODE_STRING PTR, _
    ReferencedDomains AS DWORD, _
    Sids AS DWORD _
    ) AS LONG

#IF (%WIN32_WINNT >= &H0501)

DECLARE FUNCTION LsaLookupNames2 LIB "ADVAPI32.DLL" _
   ALIAS "LsaLookupNames2" ( _
    BYVAL PolicyHandle AS DWORD, _
    BYVAL Flags AS DWORD, _  ' Reserved
    BYVAL COUNT AS DWORD, _
    BYVAL Names AS LSA_UNICODE_STRING PTR, _
    ReferencedDomains AS DWORD, _
    Sids AS DWORD _
    ) AS LONG

#ENDIF

DECLARE FUNCTION LsaLookupSids LIB "ADVAPI32.DLL" _
   ALIAS "LsaLookupSids" ( _
    BYVAL PolicyHandle AS DWORD, _
    BYVAL COUNT AS DWORD, _
    BYVAL Sids AS SID PTR, _
    ReferencedDomains AS DWORD, _
    Names AS DWORD _
    ) AS LONG


$$SE_INTERACTIVE_LOGON_NAME             = "SeInteractiveLogonRight"$$
$$SE_NETWORK_LOGON_NAME                 = "SeNetworkLogonRight"$$
$$SE_BATCH_LOGON_NAME                   = "SeBatchLogonRight"$$
$$SE_SERVICE_LOGON_NAME                 = "SeServiceLogonRight"$$
$$SE_DENY_INTERACTIVE_LOGON_NAME        = "SeDenyInteractiveLogonRight"$$
$$SE_DENY_NETWORK_LOGON_NAME            = "SeDenyNetworkLogonRight"$$
$$SE_DENY_BATCH_LOGON_NAME              = "SeDenyBatchLogonRight"$$
$$SE_DENY_SERVICE_LOGON_NAME            = "SeDenyServiceLogonRight"$$
#IF (%WIN32_WINNT >= &H0501)
$$SE_REMOTE_INTERACTIVE_LOGON_NAME      = "SeRemoteInteractiveLogonRight"$$
$$SE_DENY_REMOTE_INTERACTIVE_LOGON_NAME = "SeDenyRemoteInteractiveLogonRight"$$
#ENDIF

'
' This new API returns all the accounts with a certain privilege
'

DECLARE FUNCTION LsaEnumerateAccountsWithUserRight LIB "ADVAPI32.DLL" _
   ALIAS "LsaEnumerateAccountsWithUserRight" ( _
    BYVAL PolicyHandle AS DWORD, _
    UserRights         AS LSA_UNICODE_STRING, _
    EnumerationBuffer  AS DWORD, _
    CountReturned      AS DWORD _
    ) AS LONG

'
' These new APIs differ by taking a SID instead of requiring the caller
' to open the account first and passing in an account handle
'

DECLARE FUNCTION LsaEnumerateAccountRights LIB "ADVAPI32.DLL" _
   ALIAS "LsaEnumerateAccountRights" ( _
    BYVAL PolicyHandle AS DWORD, _
    AccountSid         AS SID, _
    UserRights         AS DWORD, _
    CountOfRights      AS DWORD _
    ) AS LONG

DECLARE FUNCTION LsaAddAccountRights LIB "ADVAPI32.DLL" _
   ALIAS "LsaAddAccountRights" ( _
    BYVAL PolicyHandle  AS DWORD, _
    AccountSid          AS SID, _
    UserRights          AS LSA_UNICODE_STRING, _
    BYVAL CountOfRights AS DWORD _
    ) AS LONG

DECLARE FUNCTION LsaRemoveAccountRights LIB "ADVAPI32.DLL" _
   ALIAS "LsaRemoveAccountRights" ( _
    BYVAL PolicyHandle  AS DWORD, _
    AccountSid          AS SID, _
    BYVAL AllRights     AS BYTE, _
    UserRights          AS LSA_UNICODE_STRING, _
    BYVAL CountOfRights AS DWORD _
    ) AS LONG


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''                                                                          ''
'' Local Security Policy - Trusted Domain Object API function prototypes    ''
''                                                                          ''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION LsaOpenTrustedDomainByName LIB "ADVAPI32.DLL" _
   ALIAS "LsaOpenTrustedDomainByName" ( _
    BYVAL PolicyHandle  AS DWORD, _
    TrustedDomainName   AS LSA_UNICODE_STRING, _
    BYVAL DesiredAccess AS DWORD, _  ' ACCESS_MASK
    TrustedDomainHandle AS DWORD _  ' LSA_HANDLE
    ) AS LONG

DECLARE FUNCTION LsaQueryTrustedDomainInfo LIB "ADVAPI32.DLL" _
   ALIAS "LsaQueryTrustedDomainInfo" ( _
    BYVAL PolicyHandle     AS DWORD, _
    TrustedDomainSid       AS SID, _
    BYVAL InformationClass AS TRUSTED_INFORMATION_CLASS_enum, _
    Buffer AS DWORD _
    ) AS LONG

DECLARE FUNCTION LsaSetTrustedDomainInformation LIB "ADVAPI32.DLL" _
   ALIAS "LsaSetTrustedDomainInformation" ( _
    BYVAL PolicyHandle     AS DWORD, _
    TrustedDomainSid       AS SID, _
    BYVAL InformationClass AS TRUSTED_INFORMATION_CLASS_enum, _
    BYVAL Buffer           AS DWORD _
    ) AS LONG

DECLARE FUNCTION LsaDeleteTrustedDomain LIB "ADVAPI32.DLL" _
   ALIAS "LsaDeleteTrustedDomain" ( _
    BYVAL PolicyHandle AS DWORD, _
    TrustedDomainSid   AS SID _
    ) AS LONG

DECLARE FUNCTION LsaQueryTrustedDomainInfoByName LIB "ADVAPI32.DLL" _
   ALIAS "LsaQueryTrustedDomainInfoByName" ( _
    BYVAL PolicyHandle     AS DWORD, _
    TrustedDomainName      AS LSA_UNICODE_STRING, _
    BYVAL InformationClass AS TRUSTED_INFORMATION_CLASS_enum, _
    Buffer                 AS DWORD _
    ) AS LONG

DECLARE FUNCTION LsaSetTrustedDomainInfoByName LIB "ADVAPI32.DLL" _
   ALIAS "LsaSetTrustedDomainInfoByName" ( _
    BYVAL PolicyHandle     AS DWORD, _
    TrustedDomainName      AS LSA_UNICODE_STRING, _
    BYVAL InformationClass AS TRUSTED_INFORMATION_CLASS_enum, _
    BYVAL Buffer           AS DWORD _
    ) AS LONG

DECLARE FUNCTION LsaEnumerateTrustedDomainsEx LIB "ADVAPI32.DLL" _
   ALIAS "LsaEnumerateTrustedDomainsEx" ( _
    BYVAL PolicyHandle          AS DWORD, _
    EnumerationContext          AS DWORD, _
    Buffer                      AS DWORD, _
    BYVAL PreferedMaximumLength AS DWORD, _
    CountReturned               AS DWORD _
    ) AS LONG

DECLARE FUNCTION LsaCreateTrustedDomainEx LIB "ADVAPI32.DLL" _
   ALIAS "LsaCreateTrustedDomainEx" ( _
    BYVAL PolicyHandle        AS DWORD, _
    TrustedDomainInformation  AS TRUSTED_DOMAIN_INFORMATION_EX, _
    AuthenticationInformation AS TRUSTED_DOMAIN_AUTH_INFORMATION, _
    BYVAL DesiredAccess       AS DWORD, _  ' ACCESS_MASK
    TrustedDomainHandle       AS DWORD _  ' LSA_HANDLE
    ) AS LONG

DECLARE FUNCTION LsaQueryForestTrustInformation LIB "ADVAPI32.DLL" _
   ALIAS "LsaQueryForestTrustInformation" ( _
    BYVAL PolicyHandle AS DWORD, _
    TrustedDomainName  AS LSA_UNICODE_STRING, _
    ForestTrustInfo    AS DWORD _
    ) AS LONG

DECLARE FUNCTION LsaSetForestTrustInformation LIB "ADVAPI32.DLL" _
   ALIAS "LsaSetForestTrustInformation" ( _
    BYVAL PolicyHandle AS DWORD, _
    TrustedDomainName  AS LSA_UNICODE_STRING, _
    ForestTrustInfo    AS LSA_FOREST_TRUST_INFORMATION, _
    BYVAL CheckOnly    AS BYTE, _
    CollisionInfo      AS DWORD _
    ) AS LONG

' %TESTING_MATCHING_ROUTINE = 1

' [not documented. doesn't appear to be exported.]
'#IF %DEF(%TESTING_MATCHING_ROUTINE)
'
'DECLARE FUNCTION LsaForestTrustFindMatch LIB "ADVAPI32.DLL" _
'   ALIAS "LsaForestTrustFindMatch" ( _
'    BYVAL PolicyHandle AS DWORD, _
'    BYVAL dType        AS DWORD, _
'    uName              AS LSA_UNICODE_STRING, _
'    Match              AS DWORD _
'    ) AS LONG
'
'#ENDIF

#ENDIF

'
' This API sets the workstation password (equivalent of setting/getting
' the SSI_SECRET_NAME secret)
'

DECLARE FUNCTION LsaStorePrivateData LIB "ADVAPI32.DLL" _
   ALIAS "LsaStorePrivateData" ( _
    BYVAL PolicyHandle AS DWORD, _
    KeyName AS LSA_UNICODE_STRING, _
    PrivateData AS LSA_UNICODE_STRING _
    ) AS LONG

DECLARE FUNCTION LsaRetrievePrivateData LIB "ADVAPI32.DLL" _
   ALIAS "LsaRetrievePrivateData" ( _
    BYVAL PolicyHandle AS DWORD, _
    KeyName AS LSA_UNICODE_STRING, _
    PrivateData AS DWORD _
    ) AS LONG


DECLARE FUNCTION LsaNtStatusToWinError LIB "ADVAPI32.DLL" _
   ALIAS "LsaNtStatusToWinError" ( _
    BYVAL STATUS AS LONG _
    ) AS DWORD


'
' Define a symbol so we can tell if ntifs.h has been included.
'

' begin_ntifs
#IF NOT %DEF(%NTLSA_IFS)
%NTLSA_IFS = 1
#ENDIF
' end_ntifs

'
' SPNEGO package stuff
'

MACRO NEGOTIATE_MESSAGES_enum=LONG
ENUM NEGOTIATE_MESSAGES SINGULAR
    NegEnumPackagePrefixes
    NegGetCallerName
    NegCallPackageMax
END ENUM

%NEGOTIATE_MAX_PREFIX   = 32

TYPE NEGOTIATE_PACKAGE_PREFIX
    PackageId    AS DWORD
    PackageDataA AS DWORD
    PackageDataW AS DWORD
    PrefixLen    AS DWORD
    Prefix       AS STRING * %NEGOTIATE_MAX_PREFIX
END TYPE

TYPE NEGOTIATE_PACKAGE_PREFIXES
    MessageType AS DWORD
    PrefixCount AS DWORD
    Offset      AS DWORD        ' Offset to array of _PREFIX above
#IF (%WIN32_WINNT >= &H0502)
    Pad         AS DWORD        ' Align structure for 64-bit
#ENDIF
END TYPE

TYPE NEGOTIATE_CALLER_NAME_REQUEST
    MessageType AS DWORD
    LogonId     AS QUAD  ' LUID
END TYPE

TYPE NEGOTIATE_CALLER_NAME_RESPONSE
    MessageType AS DWORD
    CallerName  AS WORD PTR
END TYPE

#IF NOT %DEF(%NTDEF)
MACRO UNICODE_STRING=LSA_UNICODE_STRING
#ENDIF

#IF NOT %DEF(%DOMAIN_PASSWORD_INFORMATION_DEFINED)
    %DOMAIN_PASSWORD_INFORMATION_DEFINED = 1

    TYPE DOMAIN_PASSWORD_INFORMATION
        MinPasswordLength     AS WORD
        PasswordHistoryLength AS WORD
        PasswordProperties    AS DWORD
        MaxPasswordAge        AS LARGE_INTEGER
        MinPasswordAge        AS LARGE_INTEGER
    END TYPE
#ENDIF  ' #IF NOT %DEF(%DOMAIN_PASSWORD_INFORMATION_DEFINED)

#IF (%WIN32_WINNT >= &H0501)
'
' PasswordProperties flags
'

%DOMAIN_PASSWORD_COMPLEX         = &H00000001
%DOMAIN_PASSWORD_NO_ANON_CHANGE  = &H00000002
%DOMAIN_PASSWORD_NO_CLEAR_CHANGE = &H00000004
%DOMAIN_LOCKOUT_ADMINS           = &H00000008
%DOMAIN_PASSWORD_STORE_CLEARTEXT = &H00000010
%DOMAIN_REFUSE_PASSWORD_CHANGE   = &H00000020
#IF (%WIN32_WINNT >= &H0502)
%DOMAIN_NO_LM_OWF_CHANGE         = &H00000040
#ENDIF
#ENDIF ' #IF (%WIN32_WINNT >= &H0501)



#IF NOT %DEF(%PASSWORD_NOTIFICATION_DEFINED)
    %PASSWORD_NOTIFICATION_DEFINED = 1

'DECLARE FUNCTION PSAM_PASSWORD_NOTIFICATION_ROUTINE ( _
'    UserName         AS UNICODE_STRING, _
'    BYVAL RelativeId AS DWORD, _
'    NewPassword      AS UNICODE_STRING _
'    ) AS LONG

$$SAM_PASSWORD_CHANGE_NOTIFY_ROUTINE = "PasswordChangeNotify"$$

'DECLARE FUNCTION PSAM_INIT_NOTIFICATION_ROUTINE () AS BYTE

$$SAM_INIT_NOTIFICATION_ROUTINE = "InitializeChangeNotify"$$

$$SAM_PASSWORD_FILTER_ROUTINE = "PasswordFilter"$$

'DECLARE FUNCTION PSAM_PASSWORD_FILTER_ROUTINE ( _
'    AccountName        AS UNICODE_STRING, _
'    FullName           AS UNICODE_STRING, _
'    Password           AS UNICODE_STRING, _
'    BYVAL SetOperation AS BYTE _
'    ) AS BYTE

#ENDIF  ' #IF NOT %DEF(%PASSWORD_NOTIFICATION_DEFINED)


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''                                                                    ''
'' Name of the MSV1_0 authentication package                          ''
''                                                                    ''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

$MSV1_0_PACKAGE_NAME   = "MICROSOFT_AUTHENTICATION_PACKAGE_V1_0"
$$MSV1_0_PACKAGE_NAMEW  = "MICROSOFT_AUTHENTICATION_PACKAGE_V1_0"$$
%MSV1_0_PACKAGE_NAMEW_LENGTH = 74  ' LEN($$MSV1_0_PACKAGE_NAMEW) - SIZEOF(WORD)

'
' Location of MSV authentication package data
'
$MSV1_0_SUBAUTHENTICATION_KEY = "SYSTEM\CurrentControlSet\Control\Lsa\MSV1_0"
$MSV1_0_SUBAUTHENTICATION_VALUE = "Auth"


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''                                                                    ''
'' Widely used MSV1_0 data types                                      ''
''                                                                    ''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''




''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''                                                                          ''
''       LOGON      Related Data Structures                                 ''
''                                                                          ''
''                                                                          ''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

'
' When a LsaLogonUser() call is dispatched to the MsV1_0 authentication
' package, the beginning of the AuthenticationInformation buffer is
' cast to a MSV1_0_LOGON_SUBMIT_TYPE to determine the type of logon
' being requested.  Similarly, upon return, the type of profile buffer
' can be determined by typecasting it to a MSV_1_0_PROFILE_BUFFER_TYPE.
'

'
'  MSV1.0 LsaLogonUser() submission message types.
'

MACRO MSV1_0_LOGON_SUBMIT_TYPE_enum=LONG
ENUM MSV1_0_LOGON_SUBMIT_TYPE SINGULAR
    MsV1_0InteractiveLogon       = 2
    MsV1_0Lm20Logon
    MsV1_0NetworkLogon
    MsV1_0SubAuthLogon
    MsV1_0WorkstationUnlockLogon = 7
    ' defined in Windows Server 2008 and up
    MsV1_0S4ULogon               = 12
    MsV1_0VirtualLogon           = 82
END ENUM


'
'  MSV1.0 LsaLogonUser() profile buffer types.
'

MACRO MSV1_0_PROFILE_BUFFER_TYPE_enum=LONG
ENUM MSV1_0_PROFILE_BUFFER_TYPE SINGULAR
    MsV1_0InteractiveProfile = 2
    MsV1_0Lm20LogonProfile
    MsV1_0SmartCardProfile
END ENUM

'
' MsV1_0InteractiveLogon
'
' The AuthenticationInformation buffer of an LsaLogonUser() call to
' perform an interactive logon contains the following data structure:
'

TYPE MSV1_0_INTERACTIVE_LOGON
    MessageType     AS MSV1_0_LOGON_SUBMIT_TYPE_enum
    LogonDomainName AS UNICODE_STRING
    UserName        AS UNICODE_STRING
    Password        AS UNICODE_STRING
END TYPE

'
' Where:
'
'     MessageType - Contains the type of logon being requested.  This
'         field must be set to MsV1_0InteractiveLogon.
'
'     UserName - Is a string representing the user's account name.  The
'         name may be up to 255 characters long.  The name is treated case
'         insensitive.
'
'     Password - Is a string containing the user's cleartext password.
'         The password may be up to 255 characters long and contain any
'         UNICODE value.
'
'


'
' The ProfileBuffer returned upon a successful logon of this type
' contains the following data structure:
'

TYPE MSV1_0_INTERACTIVE_PROFILE
    MessageType        AS MSV1_0_PROFILE_BUFFER_TYPE_enum
    LogonCount         AS WORD
    BadPasswordCount   AS WORD
    LogonTime          AS QUAD
    LogoffTime         AS QUAD
    KickOffTime        AS QUAD
    PasswordLastSet    AS QUAD
    PasswordCanChange  AS QUAD
    PasswordMustChange AS QUAD
    LogonScript        AS UNICODE_STRING
    HomeDirectory      AS UNICODE_STRING
    FullName           AS UNICODE_STRING
    ProfilePath        AS UNICODE_STRING
    HomeDirectoryDrive AS UNICODE_STRING
    LogonServer        AS UNICODE_STRING
    UserFlags          AS DWORD
END TYPE

'
' where:
'
'     MessageType - Identifies the type of profile data being returned.
'         Contains the type of logon being requested.  This field must
'         be set to MsV1_0InteractiveProfile.
'
'     LogonCount - Number of times the user is currently logged on.
'
'     BadPasswordCount - Number of times a bad password was applied to
'         the account since last successful logon.
'
'     LogonTime - Time when user last logged on.  This is an absolute
'         format NT standard time value.
'
'     LogoffTime - Time when user should log off.  This is an absolute
'         format NT standard time value.
'
'     KickOffTime - Time when system should force user logoff.  This is
'         an absolute format NT standard time value.
'
'     PasswordLastChanged - Time and date the password was last
'         changed.  This is an absolute format NT standard time
'         value.
'
'     PasswordCanChange - Time and date when the user can change the
'         password.  This is an absolute format NT time value.  To
'         prevent a password from ever changing, set this field to a
'         date very far into the future.
'
'     PasswordMustChange - Time and date when the user must change the
'         password.  If the user can never change the password, this
'         field is undefined.  This is an absolute format NT time
'         value.
'
'     LogonScript - The (relative) path to the account's logon
'         script.
'
'     HomeDirectory - The home directory for the user.
'


'
' MsV1_0Lm20Logon and MsV1_0NetworkLogon
'
' The AuthenticationInformation buffer of an LsaLogonUser() call to
' perform an network logon contains the following data structure:
'
' MsV1_0NetworkLogon logon differs from MsV1_0Lm20Logon in that the
' ParameterControl field exists.
'

%MSV1_0_CHALLENGE_LENGTH          = 8
%MSV1_0_USER_SESSION_KEY_LENGTH   = 16
%MSV1_0_LANMAN_SESSION_KEY_LENGTH = 8



'
' Values for ParameterControl.
'

%MSV1_0_CLEARTEXT_PASSWORD_ALLOWED      = &H00000002
%MSV1_0_UPDATE_LOGON_STATISTICS         = &H00000004
%MSV1_0_RETURN_USER_PARAMETERS          = &H00000008
%MSV1_0_DONT_TRY_GUEST_ACCOUNT          = &H00000010
%MSV1_0_ALLOW_SERVER_TRUST_ACCOUNT      = &H00000020
%MSV1_0_RETURN_PASSWORD_EXPIRY          = &H00000040
' this next flag says that CaseInsensitiveChallengeResponse
'  (aka LmResponse) contains a client challenge in the first 8 bytes
%MSV1_0_USE_CLIENT_CHALLENGE            = &H00000080
%MSV1_0_TRY_GUEST_ACCOUNT_ONLY          = &H00000100
%MSV1_0_RETURN_PROFILE_PATH             = &H00000200
%MSV1_0_TRY_SPECIFIED_DOMAIN_ONLY       = &H00000400
%MSV1_0_ALLOW_WORKSTATION_TRUST_ACCOUNT = &H00000800
'#if (%WIN32_WINNT >= &H0501) -- Disabled until IIS fixes their target version.
%MSV1_0_DISABLE_PERSONAL_FALLBACK       = &H00001000
%MSV1_0_ALLOW_FORCE_GUEST               = &H00002000
'#endif
#IF (%WIN32_WINNT >= &H0502)
%MSV1_0_CLEARTEXT_PASSWORD_SUPPLIED = &H00004000
' Start
' Doesn't exist in Windows XP but does exist in Windows 2000 Security Rollup and up
%MSV1_0_USE_DOMAIN_FOR_ROUTING_ONLY     = &H00008000
#ENDIF
%MSV1_0_SUBAUTHENTICATION_DLL_EX        = &H00100000
' Defined in Windows Server 2003 SP1 and above
%MSV1_0_ALLOW_MSVCHAPV2                 = &H00010000

#IF (%WIN32_WINNT >= &H0600)

'Defined in Windows Server 2008 and up
%MSV1_0_S4U2SELF                        = &H00020000 ' no password is needed
%MSV1_0_CHECK_LOGONHOURS_FOR_S4U        = &H00040000 ' check logon hours for S4U logon

#ENDIF

'
' The high order byte is a value indicating the SubAuthentication DLL.
'  Zero indicates no SubAuthentication DLL.
'
%MSV1_0_SUBAUTHENTICATION_DLL         = &HFF000000???
%MSV1_0_SUBAUTHENTICATION_DLL_SHIFT   = 24
%MSV1_0_MNS_LOGON                     = &H01000000

'
' This is the list of subauthentication dlls used in MS
'

%MSV1_0_SUBAUTHENTICATION_DLL_RAS     = 2
%MSV1_0_SUBAUTHENTICATION_DLL_IIS     = 132

TYPE MSV1_0_LM20_LOGON
    MessageType       AS MSV1_0_LOGON_SUBMIT_TYPE_enum
    LogonDomainName   AS UNICODE_STRING
    UserName          AS UNICODE_STRING
    Workstation       AS UNICODE_STRING
    ChallengeToClient AS STRING * %MSV1_0_CHALLENGE_LENGTH
    CaseSensitiveChallengeResponse   AS LSA_STRING
    CaseInsensitiveChallengeResponse AS LSA_STRING
    ParameterControl  AS DWORD
END TYPE

'
' NT 5.0 SubAuth dlls can use this struct
'

TYPE MSV1_0_SUBAUTH_LOGON
    MessageType         AS MSV1_0_LOGON_SUBMIT_TYPE_enum
    LogonDomainName     AS UNICODE_STRING
    UserName            AS UNICODE_STRING
    Workstation         AS UNICODE_STRING
    ChallengeToClient   AS STRING * %MSV1_0_CHALLENGE_LENGTH
    AuthenticationInfo1 AS LSA_STRING
    AuthenticationInfo2 AS LSA_STRING
    ParameterControl    AS DWORD
    SubAuthPackageId    AS DWORD
END TYPE

#IF (%WIN32_WINNT >= &H0600)

'
' s4u2self logon
'
' Defined in Windows Server 2008 and above

'
' request to enforce logon hours policy
'

%MSV1_0_S4U_LOGON_FLAG_CHECK_LOGONHOURS = &H2

TYPE MSV1_0_S4U_LOGON
    MessageType       AS MSV1_0_LOGON_SUBMIT_TYPE_enum
    Flags             AS DWORD
    UserPrincipalName AS UNICODE_STRING  ' username or username@domain
    DomainName        AS UNICODE_STRING  ' Optional: if missing, using the local machine
END TYPE

#ENDIF

'
' Values for UserFlags.
'

%LOGON_GUEST                 = &H0001
%LOGON_NOENCRYPTION          = &H0002
%LOGON_CACHED_ACCOUNT        = &H0004
%LOGON_USED_LM_PASSWORD      = &H0008
%LOGON_EXTRA_SIDS            = &H0020
%LOGON_SUBAUTH_SESSION_KEY   = &H0040
%LOGON_SERVER_TRUST_ACCOUNT  = &H0080
%LOGON_NTLMV2_ENABLED        = &H0100  ' says DC understands NTLMv2
%LOGON_RESOURCE_GROUPS       = &H0200
%LOGON_PROFILE_PATH_RETURNED = &H0400
' Defined in Windows Server 2008 and above
%LOGON_NT_V2                 = &H0800  ' NT response was used for validation
%LOGON_LM_V2                 = &H1000  ' LM response was used for validation
%LOGON_NTLM_V2               = &H2000  ' LM response was used to authenticate but NT response was used to derive the session key

#IF (%WIN32_WINNT >= &H0600)

%LOGON_OPTIMIZED             = &H4000   ' this is an optimized logon
%LOGON_WINLOGON              = &H8000?? ' the logon session was created for winlogon
%LOGON_PKINIT                = &H10000  ' Kerberos PKINIT extension was used to authenticate the user
%LOGON_NO_OPTIMIZED          = &H20000  ' optimized logon has been disabled for this account

#ENDIF


'
' The high order byte is reserved for return by SubAuthentication DLLs.
'

%MSV1_0_SUBAUTHENTICATION_FLAGS = &HFF000000???

' Values returned by the MSV1_0_MNS_LOGON SubAuthentication DLL
%LOGON_GRACE_LOGON              = &H01000000

TYPE MSV1_0_LM20_LOGON_PROFILE
    MessageType      AS MSV1_0_PROFILE_BUFFER_TYPE_enum
    KickOffTime      AS QUAD
    LogoffTime       AS QUAD
    UserFlags        AS DWORD
    UserSessionKey   AS STRING * %MSV1_0_USER_SESSION_KEY_LENGTH
    LogonDomainName  AS UNICODE_STRING
    LanmanSessionKey AS STRING * %MSV1_0_LANMAN_SESSION_KEY_LENGTH
    LogonServer      AS UNICODE_STRING
    UserParameters   AS UNICODE_STRING
END TYPE


'
' Supplemental credentials structure used for passing credentials into
' MSV1_0 from other packages
'

%MSV1_0_OWF_PASSWORD_LENGTH = 16
%MSV1_0_CRED_LM_PRESENT = &H1
%MSV1_0_CRED_NT_PRESENT = &H2
%MSV1_0_CRED_VERSION    = 0

TYPE MSV1_0_SUPPLEMENTAL_CREDENTIAL
    Version    AS DWORD
    Flags      AS DWORD
    LmPassword AS STRING * %MSV1_0_OWF_PASSWORD_LENGTH
    NtPassword AS STRING * %MSV1_0_OWF_PASSWORD_LENGTH
END TYPE


'
' NTLM3 definitions.
'

%MSV1_0_NTLM3_RESPONSE_LENGTH = 16
%MSV1_0_NTLM3_OWF_LENGTH      = 16

'
' this is the longest amount of time we'll allow challenge response
' pairs to be used. Note that this also has to allow for worst case clock skew
'
#IF (%WIN32_WINNT = &H0500)
%MSV1_0_MAX_NTLM3_LIFE = 1800     ' 30 minutes (in seconds)
#ELSE
%MSV1_0_MAX_NTLM3_LIFE = 129600   ' 36 hours (in seconds)
#ENDIF
%MSV1_0_MAX_AVL_SIZE   = 64000

#IF (%WIN32_WINNT >= &H0501)
'
' MsvAvFlags bit values
'
' Exists only after Windows 2000
'

%MSV1_0_AV_FLAG_FORCE_GUEST            = &H00000001
#IF (%WIN32_WINNT >= &H0600)
' the client supports hand-shake messages integrity
%MSV1_0_AV_FLAG_MIC_HANDSHAKE_MESSAGES = &H00000002
#ENDIF
#ENDIF


' this is an MSV1_0 private data structure, defining the layout of an NTLM3 response, as sent by a
'  client in the NtChallengeResponse field of the NETLOGON_NETWORK_INFO structure. If can be differentiated
'  from an old style NT response by its length. This is crude, but it needs to pass through servers and
'  the servers' DCs that do not understand NTLM3 but that are willing to pass longer responses.
TYPE MSV1_0_NTLM3_RESPONSE
    Response   AS STRING * %MSV1_0_NTLM3_RESPONSE_LENGTH ' hash of OWF of password with all the following fields
    RespType   AS BYTE   ' id number of response AS BYTE current is 1
    HiRespType AS BYTE   ' highest id number understood by client
    Flags      AS WORD   ' reserved; must be sent as zero at this version
    MsgWord    AS DWORD  ' 32 bit message from client to server (for use by auth protocol)
    TimeStamp  AS QUAD   ' time stamp when client generated response -- NT system time, quad part
    ChallengeFromClient AS STRING * %MSV1_0_CHALLENGE_LENGTH
    AvPairsOff AS DWORD  ' offset to start of AvPairs (to allow future expansion)
    Buffer     AS STRING * 2  ' start of buffer with AV pairs (or future stuff -- so use the offset)
END TYPE

%MSV1_0_NTLM3_INPUT_LENGTH = _
    %MSV1_0_NTLM3_RESPONSE_LENGTH+1+1+2+4+8+%MSV1_0_CHALLENGE_LENGTH+4+2 _
    - %MSV1_0_NTLM3_RESPONSE_LENGTH
' SIZEOF(MSV1_0_NTLM3_RESPONSE) - %MSV1_0_NTLM3_RESPONSE_LENGTH

'#if (%WIN32_WINNT >= &H0502)
'macro  MSV1_0_NTLM3_MIN_NT_RESPONSE_LENGTH=RTL_SIZEOF_THROUGH_FIELD(MSV1_0_NTLM3_RESPONSE, AvPairsOff)
'#endif

MACRO MSV1_0_AVID_enum=LONG
ENUM MSV1_0_AVID SINGULAR
    MsvAvEOL                   ' end of list
    MsvAvNbComputerName        ' server's computer name -- NetBIOS
    MsvAvNbDomainName          ' server's domain name -- NetBIOS
    MsvAvDnsComputerName       ' server's computer name -- DNS
    MsvAvDnsDomainName         ' server's domain name -- DNS
#IF (%WIN32_WINNT >= &H0501)
    MsvAvDnsTreeName           ' server's tree name -- DNS
    MsvAvFlags                 ' server's extended flags -- DWORD mask
#IF (%WIN32_WINNT >= &H0600)
    MsvAvTimestamp             ' contains the server's local time in FILETIME,
                               ' (64 bit 100 ns ticks since 1602
                               ' (UTC)) in little endian byte order
    MsvAvRestrictions          ' token restrictions
    MsvAvTargetName
    MsvAvChannelBindings
#ENDIF
#ENDIF
END ENUM

TYPE MSV1_0_AV_PAIR
    AvId  AS WORD
    AvLen AS WORD
    ' Data is treated as byte array following structure
END TYPE




''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''                                                                          ''
''       CALL PACKAGE Related Data Structures                               ''
''                                                                          ''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''


'
'  MSV1.0 LsaCallAuthenticationPackage() submission and response
'  message types.
'

MACRO MSV1_0_PROTOCOL_MESSAGE_TYPE_enum=LONG
ENUM MSV1_0_PROTOCOL_MESSAGE_TYPE SINGULAR
    MsV1_0Lm20ChallengeRequest        ' Both submission and response
    MsV1_0Lm20GetChallengeResponse    ' Both submission and response
    MsV1_0EnumerateUsers              ' Both submission and response
    MsV1_0GetUserInfo                 ' Both submission and response
    MsV1_0ReLogonUsers                ' Submission only
    MsV1_0ChangePassword              ' Both submission and response
    MsV1_0ChangeCachedPassword        ' Both submission and response
    MsV1_0GenericPassthrough          ' Both submission and response
    MsV1_0CacheLogon                  ' Submission only, no response
    MsV1_0SubAuth                     ' Both submission and response
    MsV1_0DeriveCredential            ' Both submission and response
    MsV1_0CacheLookup                 ' Both submission and response
#IF (%WIN32_WINNT >= &H0501)
    MsV1_0SetProcessOption            ' Submission only, no response
#ENDIF
#IF (%WIN32_WINNT >= &H0600)
    MsV1_0ConfigLocalAliases
    MsV1_0ClearCachedCredentials
#ENDIF
END ENUM


TYPE MSV1_0_CHANGEPASSWORD_REQUEST
    MessageType   AS MSV1_0_PROTOCOL_MESSAGE_TYPE_enum
    DomainName    AS UNICODE_STRING
    AccountName   AS UNICODE_STRING
    OldPassword   AS UNICODE_STRING
    NewPassword   AS UNICODE_STRING
    Impersonating AS BYTE
END TYPE

TYPE MSV1_0_CHANGEPASSWORD_RESPONSE DWORD FILL
    MessageType        AS MSV1_0_PROTOCOL_MESSAGE_TYPE_enum
    PasswordInfoValid  AS BYTE
    DomainPasswordInfo AS DOMAIN_PASSWORD_INFORMATION
END TYPE


#IF (%WIN32_WINNT >= &H0502)
'
' MsV1_0GenericPassthrough - for remoting a CallPackage to
' a domain controller on the specified domain
'

TYPE MSV1_0_PASSTHROUGH_REQUEST
    MessageType AS MSV1_0_PROTOCOL_MESSAGE_TYPE_enum
    DomainName  AS UNICODE_STRING
    PackageName AS UNICODE_STRING
    DataLength  AS DWORD
    LogonData   AS WORD PTR
    Pad         AS DWORD
END TYPE

TYPE MSV1_0_PASSTHROUGH_RESPONSE
    MessageType    AS MSV1_0_PROTOCOL_MESSAGE_TYPE_enum
    Pad            AS DWORD
    DataLength     AS DWORD
    ValidationData AS WORD PTR
END TYPE
#ENDIF ' #IF (%WIN32_WINNT >= &H0502)


'
' MsV1_0SubAuthInfo submit buffer and response - for submitting a buffer to a
' specified Subauthentication Package during an LsaCallAuthenticationPackage().
' If this Subauthentication is to be done locally, then package this message
' in LsaCallAuthenticationPackage(). If this SubAuthentication needs to be done
' on the domain controller, then call LsaCallauthenticationPackage with the
' message type being MsV1_0GenericPassThrough and the LogonData in this struct
' should be a PMSV1_0_SUBAUTH_REQUEST
'

TYPE MSV1_0_SUBAUTH_REQUEST
    MessageType         AS MSV1_0_PROTOCOL_MESSAGE_TYPE_enum
    SubAuthPackageId    AS DWORD
    SubAuthInfoLength   AS DWORD
    SubAuthSubmitBuffer AS WORD PTR
END TYPE

TYPE MSV1_0_SUBAUTH_RESPONSE
    MessageType         AS MSV1_0_PROTOCOL_MESSAGE_TYPE_enum
    SubAuthInfoLength   AS DWORD
    SubAuthReturnBuffer AS WORD PTR
END TYPE

#IF (%WIN32_WINNT >= &H0501)

DECLARE FUNCTION RtlGenRandom LIB "AdvApi32.dll" ALIAS "SystemFunction036" ( _
    RandomBuffer AS ANY, _
    BYVAL RandomBufferLength AS DWORD _
    ) AS BYTE

#ENDIF

'
' #IF (%WIN32_WINNT >= &H0500) -- Disabled until WinHTTP fixes their target version.
'

'
' The buffer passed into RtlEncryptMemory and RtlDecryptMemory
' must be a multiple of this length.
'

%RTL_ENCRYPT_MEMORY_SIZE           = 8

'
' Allow Encrypt/Decrypt across process boundaries.
' eg: encrypted buffer passed across LPC to another process which calls RtlDecryptMemory.
'

%RTL_ENCRYPT_OPTION_CROSS_PROCESS  = &H01

'
' Allow Encrypt/Decrypt across callers with same LogonId.
' eg: encrypted buffer passed across LPC to another process which calls RtlDecryptMemory whilst impersonating.
'

%RTL_ENCRYPT_OPTION_SAME_LOGON     = &H02

DECLARE FUNCTION RtlEncryptMemory LIB "AdvApi32.dll" _
    ALIAS "SystemFunction040" (_
    Memory            AS ANY, _
    BYVAL MemorySize  AS DWORD, _
    BYVAL OptionFlags AS DWORD _
    ) AS LONG

DECLARE FUNCTION RtlDecryptMemory LIB "AdvApi32.dll" _
    ALIAS "SystemFunction041" (_
    Memory            AS ANY, _
    BYVAL MemorySize  AS DWORD, _
    BYVAL OptionFlags AS DWORD _
    ) AS LONG

' #endif  ' #IF (%WIN32_WINNT >= &H0500)


' Revision of the Kerberos Protocol.  MS uses Version 5, Revision 6

%KERBEROS_VERSION  = 5
%KERBEROS_REVISION = 6



' Encryption Types:
' These encryption types are supported by the default MS KERBSUPP DLL
' as crypto systems.  Values over 127 are local values, and may be changed
' without notice.

%KERB_ETYPE_NULL        = 0
%KERB_ETYPE_DES_CBC_CRC = 1
%KERB_ETYPE_DES_CBC_MD4 = 2
%KERB_ETYPE_DES_CBC_MD5 = 3


%KERB_ETYPE_RC4_MD4           = -128    ' &HFFFFFF80&
%KERB_ETYPE_RC4_PLAIN2        = -129
%KERB_ETYPE_RC4_LM            = -130
%KERB_ETYPE_RC4_SHA           = -131
%KERB_ETYPE_DES_PLAIN         = -132
%KERB_ETYPE_RC4_HMAC_OLD      = -133    ' &HFFFFFF7B&
%KERB_ETYPE_RC4_PLAIN_OLD     = -134
%KERB_ETYPE_RC4_HMAC_OLD_EXP  = -135
%KERB_ETYPE_RC4_PLAIN_OLD_EXP = -136
%KERB_ETYPE_RC4_PLAIN         = -140
%KERB_ETYPE_RC4_PLAIN_EXP     = -141

'
' used internally by userapi.cxx
'

%KERB_ETYPE_AES128_CTS_HMAC_SHA1_96_PLAIN  = -148
%KERB_ETYPE_AES256_CTS_HMAC_SHA1_96_PLAIN  = -149


'
' Pkinit encryption types
'


%KERB_ETYPE_DSA_SHA1_CMS     = 9
%KERB_ETYPE_RSA_MD5_CMS      = 10
%KERB_ETYPE_RSA_SHA1_CMS     = 11
%KERB_ETYPE_RC2_CBC_ENV      = 12
%KERB_ETYPE_RSA_ENV          = 13
%KERB_ETYPE_RSA_ES_OEAP_ENV  = 14
%KERB_ETYPE_DES_EDE3_CBC_ENV = 15


'
' Deprecated
'

%KERB_ETYPE_DSA_SIGN     = 8
%KERB_ETYPE_RSA_PRIV     = 9
%KERB_ETYPE_RSA_PUB      = 10
%KERB_ETYPE_RSA_PUB_MD5  = 11
%KERB_ETYPE_RSA_PUB_SHA1 = 12
%KERB_ETYPE_PKCS7_PUB    = 13

#IF (%WIN32_WINNT >= &H0502)
'
' Unsupported but defined types
'

%KERB_ETYPE_DES3_CBC_MD5     = 5
%KERB_ETYPE_DES3_CBC_SHA1    = 7
%KERB_ETYPE_DES3_CBC_SHA1_KD = 16
#ENDIF

'
' In use types
'

%KERB_ETYPE_DES_CBC_MD5_NT  = 20
%KERB_ETYPE_RC4_HMAC_NT     = 23
%KERB_ETYPE_RC4_HMAC_NT_EXP = 24

' Checksum algorithms.
' These algorithms are keyed internally for our use. ["our" = Microsoft's]

%KERB_CHECKSUM_NONE          = 0
%KERB_CHECKSUM_CRC32         = 1
%KERB_CHECKSUM_MD4           = 2
%KERB_CHECKSUM_KRB_DES_MAC   = 4
#IF (%WIN32_WINNT >= &H0501)
%KERB_CHECKSUM_KRB_DES_MAC_K = 5
#ENDIF
%KERB_CHECKSUM_MD5           = 7
%KERB_CHECKSUM_MD5_DES       = 8

%KERB_CHECKSUM_SHA1_NEW      = 14           '/ defined in RFC3961
%KERB_CHECKSUM_HMAC_SHA1_96_AES128 = 15
%KERB_CHECKSUM_HMAC_SHA1_96_AES256 = 16

%KERB_CHECKSUM_LM          = -130
%KERB_CHECKSUM_SHA1        = -131
%KERB_CHECKSUM_REAL_CRC32  = -132
%KERB_CHECKSUM_DES_MAC     = -133
%KERB_CHECKSUM_DES_MAC_MD5 = -134
%KERB_CHECKSUM_MD25        = -135
%KERB_CHECKSUM_RC4_MD5     = -136
%KERB_CHECKSUM_MD5_HMAC    = -137    ' used by netlogon
%KERB_CHECKSUM_HMAC_MD5    = -138    ' used by Kerberos

'
' used internally by userapi.cxx
'

%KERB_CHECKSUM_HMAC_SHA1_96_AES128_Ki = -150
%KERB_CHECKSUM_HMAC_SHA1_96_AES256_Ki = -151


%AUTH_REQ_ALLOW_FORWARDABLE      = &H00000001
%AUTH_REQ_ALLOW_PROXIABLE        = &H00000002
%AUTH_REQ_ALLOW_POSTDATE         = &H00000004
%AUTH_REQ_ALLOW_RENEWABLE        = &H00000008
%AUTH_REQ_ALLOW_NOADDRESS        = &H00000010
%AUTH_REQ_ALLOW_ENC_TKT_IN_SKEY  = &H00000020
%AUTH_REQ_ALLOW_VALIDATE         = &H00000040
%AUTH_REQ_VALIDATE_CLIENT        = &H00000080
%AUTH_REQ_OK_AS_DELEGATE         = &H00000100
%AUTH_REQ_PREAUTH_REQUIRED       = &H00000200
%AUTH_REQ_TRANSITIVE_TRUST       = &H00000400
#IF (%WIN32_WINNT >= &H0502)
%AUTH_REQ_ALLOW_S4U_DELEGATE     = &H00000800
#ENDIF


%AUTH_REQ_PER_USER_FLAGS = %AUTH_REQ_ALLOW_FORWARDABLE OR _
                           %AUTH_REQ_ALLOW_PROXIABLE OR _
                           %AUTH_REQ_ALLOW_POSTDATE OR _
                           %AUTH_REQ_ALLOW_RENEWABLE OR _
                           %AUTH_REQ_ALLOW_VALIDATE
'
' Ticket Flags:
'

%KERB_TICKET_FLAGS_reserved          = &H80000000???
%KERB_TICKET_FLAGS_forwardable       = &H40000000
%KERB_TICKET_FLAGS_forwarded         = &H20000000
%KERB_TICKET_FLAGS_proxiable         = &H10000000
%KERB_TICKET_FLAGS_proxy             = &H08000000
%KERB_TICKET_FLAGS_may_postdate      = &H04000000
%KERB_TICKET_FLAGS_postdated         = &H02000000
%KERB_TICKET_FLAGS_invalid           = &H01000000
%KERB_TICKET_FLAGS_renewable         = &H00800000
%KERB_TICKET_FLAGS_initial           = &H00400000
%KERB_TICKET_FLAGS_pre_authent       = &H00200000
%KERB_TICKET_FLAGS_hw_authent        = &H00100000
%KERB_TICKET_FLAGS_ok_as_delegate    = &H00040000
%KERB_TICKET_FLAGS_name_canonicalize = &H00010000
#IF (%WIN32_WINNT = &H0501)
%KERB_TICKET_FLAGS_cname_in_pa_data  = &H00040000
#ENDIF
%KERB_TICKET_FLAGS_reserved1         = &H00000001



#IF (%WIN32_WINNT >= &H0501)
'
' Name types
'

%KRB_NT_UNKNOWN              = 0     ' Name type not known
%KRB_NT_PRINCIPAL            = 1     ' Just the name of the principal as in DCE, or for users
%KRB_NT_PRINCIPAL_AND_ID     = -131  ' Name of the principal and its SID.
%KRB_NT_SRV_INST             = 2     ' Service and other unique instance (krbtgt)
%KRB_NT_SRV_INST_AND_ID      = -132  ' SPN and SID
%KRB_NT_SRV_HST              = 3     ' Service with host name as instance (telnet, rcommands)
%KRB_NT_SRV_XHST             = 4     ' Service with host as remaining components
%KRB_NT_UID                  = 5     ' Unique ID
%KRB_NT_ENTERPRISE_PRINCIPAL = 10    ' UPN or SPN
%KRB_NT_ENT_PRINCIPAL_AND_ID = -130  ' UPN and SID

'
' MS extensions, negative according to the RFC
'

%KRB_NT_MS_PRINCIPAL        = -128   ' NT4 style name

%KRB_NT_MS_PRINCIPAL_AND_ID = -129   ' nt4 style name with sid

MACRO KERB_IS_MS_PRINCIPAL (x) = ABS(((x) <= %KRB_NT_MS_PRINCIPAL) OR ((x) >= %KRB_NT_ENTERPRISE_PRINCIPAL))

#IF (%WIN32_WINNT >= &H0600)
%KRB_NT_X500_PRINCIPAL = 6           ' Encoded X.500 Distingished name [RFC 2253]
#ENDIF

#IF NOT %DEF($MICROSOFT_KERBEROS_NAME_A)
    $MICROSOFT_KERBEROS_NAME_A = "Kerberos"
    $$MICROSOFT_KERBEROS_NAME_W = "Kerberos"$$

#IF %DEF(%WIN32_CHICAGO)
MACRO MICROSOFT_KERBEROS_NAME = $MICROSOFT_KERBEROS_NAME_A
#ELSE
MACRO MICROSOFT_KERBEROS_NAME = $$MICROSOFT_KERBEROS_NAME_W
#ENDIF  ' #IF %DEF(%WIN32_CHICAGO)
#ENDIF  ' #IF NOT %DEF($MICROSOFT_KERBEROS_NAME_A)


'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''
'' Quality of protection parameters for MakeSignature / EncryptMessage
''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

'
' This flag indicates to EncryptMessage that the message is not to actually
' be encrypted, but a header/trailer are to be produced.
'

%KERB_WRAP_NO_ENCRYPT = &H80000001???

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''
'' LsaLogonUser parameters
''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

MACRO KERB_LOGON_SUBMIT_TYPE_enum=LONG
ENUM KERB_LOGON_SUBMIT_TYPE SINGULAR
    KerbInteractiveLogon       = 2
    KerbSmartCardLogon         = 6
    KerbWorkstationUnlockLogon
    KerbSmartCardUnlockLogon
    KerbProxyLogon
    KerbTicketLogon
    KerbTicketUnlockLogon
'#IF (%WIN32_WINNT >= &H0501) -- Disabled until IIS fixes their target version.
    KerbS4ULogon
'#ENDIF
#IF (%WIN32_WINNT >= &H0600)
    KerbCertificateLogon
    KerbCertificateS4ULogon
    KerbCertificateUnlockLogon
#ENDIF
END ENUM


TYPE KERB_INTERACTIVE_LOGON
    MessageType     AS KERB_LOGON_SUBMIT_TYPE_enum
    LogonDomainName AS UNICODE_STRING
    UserName        AS UNICODE_STRING
    Password        AS UNICODE_STRING
END TYPE


TYPE KERB_INTERACTIVE_UNLOCK_LOGON
    Logon   AS KERB_INTERACTIVE_LOGON
    LogonId AS QUAD
END TYPE

TYPE KERB_SMART_CARD_LOGON
    MessageType   AS KERB_LOGON_SUBMIT_TYPE_enum
    Pin           AS UNICODE_STRING
    CspDataLength AS DWORD
    CspData       AS WORD PTR
END TYPE

TYPE KERB_SMART_CARD_UNLOCK_LOGON
    Logon   AS KERB_SMART_CARD_LOGON
    LogonId AS QUAD
END TYPE


#IF (%WIN32_WINNT >= &H0600)

'
' let the KDC detect account mapping conflicts for the same certificate.
'

%KERB_CERTIFICATE_LOGON_FLAG_CHECK_DUPLICATES = &H1

TYPE KERB_CERTIFICATE_LOGON
    MessageType   AS KERB_LOGON_SUBMIT_TYPE_enum  ' KerbCertificateLogon
    DomainName    AS UNICODE_STRING  ' OPTIONAL, if supplied, used to locate the account forest
    UserName      AS UNICODE_STRING  ' OPTIONAL, if supplied, used to locate the account
    Pin           AS UNICODE_STRING
    Flags         AS DWORD           ' additional flags
    CspDataLength AS DWORD
    CspData       AS WORD PTR        ' contains the smartcard CSP data
END TYPE

TYPE KERB_CERTIFICATE_UNLOCK_LOGON
    Logon   AS KERB_CERTIFICATE_LOGON
    LogonId AS QUAD  ' LUID
END TYPE

'
' let the KDC detect account mapping conflicts for the same certificate.
'

%KERB_CERTIFICATE_S4U_LOGON_FLAG_CHECK_DUPLICATES = &H1
%KERB_CERTIFICATE_S4U_LOGON_FLAG_CHECK_LOGONHOURS = &H2
%KERB_CERTIFICATE_S4U_LOGON_FLAG_FAIL_IF_NT_AUTH_POLICY_REQUIRED = &H4

TYPE KERB_CERTIFICATE_S4U_LOGON
    MessageType       AS KERB_LOGON_SUBMIT_TYPE_enum
    Flags             AS DWORD
    UserPrincipalName AS UNICODE_STRING
    ' OPTIONAL, certificate mapping hints: username or username@domain
    DomainName        AS UNICODE_STRING  ' used to locate the forest
     ' OPTIONAL, certificate mapping hints: if missing, using the local machine's domain
    CertificateLength AS DWORD    ' for the client certificate
    Certificate       AS WORD PTR ' for the client certificate, BER encoded
END TYPE

#ENDIF


'
' Structure used for a ticket-only logon
'

TYPE KERB_TICKET_LOGON
    MessageType                AS KERB_LOGON_SUBMIT_TYPE_enum
    Flags                      AS DWORD
    ServiceTicketLength        AS DWORD
    TicketGrantingTicketLength AS DWORD
    ServiceTicket              AS WORD PTR ' REQUIRED: Service ticket "host"
    TicketGrantingTicket       AS WORD PTR ' OPTIONAL: User's encdoded in a KERB_CRED message, encrypted with session key from service ticket
END TYPE

'
' Flags for the ticket logon flags field
'

%KERB_LOGON_FLAG_ALLOW_EXPIRED_TICKET = &H1

TYPE KERB_TICKET_UNLOCK_LOGON
    Logon   AS KERB_TICKET_LOGON
    LogonId AS QUAD  ' LUID
END TYPE

'#if (%WIN32_WINNT >= &H0501) -- Disabled until IIS fixes their target version.
'
'  Used for S4U Client requests
'
'

#IF (%WIN32_WINNT >= &H0600)

'
' request to enforce logon hours policy
'

%KERB_S4U_LOGON_FLAG_CHECK_LOGONHOURS = &H2

#ENDIF

TYPE KERB_S4U_LOGON
    MessageType AS KERB_LOGON_SUBMIT_TYPE_enum
    Flags       AS DWORD
    ClientUpn   AS UNICODE_STRING  ' REQUIRED: UPN for client
    ClientRealm AS UNICODE_STRING  ' Optional: Client Realm, if known
END TYPE
'#endif ' #if (%WIN32_WINNT >= &H0501)


'
' Use the same profile structure as MSV1_0
'

MACRO KERB_PROFILE_BUFFER_TYPE_enum=LONG
ENUM KERB_PROFILE_BUFFER_TYPE SINGULAR
    KerbInteractiveProfile = 2
    KerbSmartCardProfile   = 4
    KerbTicketProfile      = 6
END ENUM


TYPE KERB_INTERACTIVE_PROFILE
    MessageType        AS KERB_PROFILE_BUFFER_TYPE_enum
    LogonCount         AS WORD
    BadPasswordCount   AS WORD
    LogonTime          AS LARGE_INTEGER
    LogoffTime         AS LARGE_INTEGER
    KickOffTime        AS LARGE_INTEGER
    PasswordLastSet    AS LARGE_INTEGER
    PasswordCanChange  AS LARGE_INTEGER
    PasswordMustChange AS LARGE_INTEGER
    LogonScript        AS UNICODE_STRING
    HomeDirectory      AS UNICODE_STRING
    FullName           AS UNICODE_STRING
    ProfilePath        AS UNICODE_STRING
    HomeDirectoryDrive AS UNICODE_STRING
    LogonServer        AS UNICODE_STRING
    UserFlags          AS DWORD
END TYPE


'
' For smart card, we return a smart card profile, which is an interactive
' profile plus a certificate
'

TYPE KERB_SMART_CARD_PROFILE
    kProfile        AS KERB_INTERACTIVE_PROFILE
    CertificateSize AS DWORD
    CertificateData AS WORD PTR
END TYPE


'
' For a ticket logon profile, we return the session key from the ticket
'


TYPE KERB_CRYPTO_KEY
    KeyType AS LONG
    Length  AS DWORD
    Value   AS WORD PTR
END TYPE

TYPE KERB_CRYPTO_KEY32
    KeyType AS LONG
    Length  AS DWORD
    Offset  AS DWORD
END TYPE

TYPE KERB_TICKET_PROFILE
    kProfile   AS KERB_INTERACTIVE_PROFILE
    SessionKey AS KERB_CRYPTO_KEY
END TYPE


MACRO KERB_PROTOCOL_MESSAGE_TYPE_enum=LONG
ENUM KERB_PROTOCOL_MESSAGE_TYPE SINGULAR
    KerbDebugRequestMessage          = 0
    KerbQueryTicketCacheMessage
    KerbChangeMachinePasswordMessage
    KerbVerifyPacMessage
    KerbRetrieveTicketMessage
    KerbUpdateAddressesMessage
    KerbPurgeTicketCacheMessage
    KerbChangePasswordMessage
    KerbRetrieveEncodedTicketMessage
    KerbDecryptDataMessage
    KerbAddBindingCacheEntryMessage
    KerbSetPasswordMessage
    KerbSetPasswordExMessage
#IF (%WIN32_WINNT = &H0500)
    KerbAddExtraCredentialsMessage   = 17
#ENDIF
#IF (%WIN32_WINNT >= &H0501)
    KerbVerifyCredentialsMessage
    KerbQueryTicketCacheExMessage
    KerbPurgeTicketCacheExMessage
#ENDIF
#IF (%WIN32_WINNT >= &H0502)
    KerbRefreshSmartcardCredentialsMessage
    KerbAddExtraCredentialsMessage
    KerbQuerySupplementalCredentialsMessage
#ENDIF
#IF (%WIN32_WINNT >= &H0600)
    KerbTransferCredentialsMessage
    KerbQueryTicketCacheEx2Message
    KerbSubmitTicketMessage
    KerbAddExtraCredentialsExMessage
#ENDIF
END ENUM


'
' Used both for retrieving tickets and for querying ticket cache
'

TYPE KERB_QUERY_TKT_CACHE_REQUEST
    MessageType AS KERB_PROTOCOL_MESSAGE_TYPE_enum
    LogonId     AS QUAD  ' LUID
END TYPE


TYPE KERB_TICKET_CACHE_INFO
    ServerName     AS UNICODE_STRING
    RealmName      AS UNICODE_STRING
    StartTime      AS LARGE_INTEGER
    EndTime        AS LARGE_INTEGER
    RenewTime      AS LARGE_INTEGER
    EncryptionType AS LONG
    TicketFlags    AS DWORD
END TYPE


#IF (%WIN32_WINNT >= &H0501)
TYPE KERB_TICKET_CACHE_INFO_EX
    ClientName     AS UNICODE_STRING
    ClientRealm    AS UNICODE_STRING
    ServerName     AS UNICODE_STRING
    ServerRealm    AS UNICODE_STRING
    StartTime      AS LARGE_INTEGER
    EndTime        AS LARGE_INTEGER
    RenewTime      AS LARGE_INTEGER
    EncryptionType AS LONG
    TicketFlags    AS DWORD
END TYPE
#ENDIF ' #IF (%WIN32_WINNT >= &H0501)


TYPE KERB_TICKET_CACHE_INFO_EX2
    ClientName     AS UNICODE_STRING
    ClientRealm    AS UNICODE_STRING
    ServerName     AS UNICODE_STRING
    ServerRealm    AS UNICODE_STRING
    StartTime      AS LARGE_INTEGER
    EndTime        AS LARGE_INTEGER
    RenewTime      AS LARGE_INTEGER
    EncryptionType AS LONG
    TicketFlags    AS DWORD

    '
    ' the following are new in KERB_TICKET_CACHE_INFO_EX2
    '
    SessionKeyType AS DWORD
    BranchId       AS DWORD
END TYPE


TYPE KERB_QUERY_TKT_CACHE_RESPONSE
    MessageType    AS KERB_PROTOCOL_MESSAGE_TYPE_enum
    CountOfTickets AS DWORD
    Tickets(%ANYSIZE_ARRAY-1) AS KERB_TICKET_CACHE_INFO
END TYPE


#IF (%WIN32_WINNT >= &H0502)
TYPE KERB_QUERY_TKT_CACHE_EX_RESPONSE
    MessageType    AS KERB_PROTOCOL_MESSAGE_TYPE_enum
    CountOfTickets AS DWORD
    Tickets(%ANYSIZE_ARRAY-1) AS KERB_TICKET_CACHE_INFO_EX
END TYPE
#ENDIF


'
' Types for retrieving encoded ticket from the cache
'

#IF NOT %DEF(%SECHANDLE_DEFINED)
%SECHANDLE_DEFINED = 1

TYPE SecHandle
    dwLower AS DWORD
    dwUpper AS DWORD
END TYPE
#ENDIF  ' #IF NOT %DEF(%SECHANDLE_DEFINED)

#IF (%WIN32_WINNT >= &H0501)
' Ticket Flags
%KERB_USE_DEFAULT_TICKET_FLAGS       = &H0

' CacheOptions
%KERB_RETRIEVE_TICKET_DEFAULT        = &H00
#ENDIF
%KERB_RETRIEVE_TICKET_DONT_USE_CACHE = &H01
%KERB_RETRIEVE_TICKET_USE_CACHE_ONLY = &H02
%KERB_RETRIEVE_TICKET_USE_CREDHANDLE = &H04
#IF (%WIN32_WINNT >= &H0501)
%KERB_RETRIEVE_TICKET_AS_KERB_CRED   = &H08
%KERB_RETRIEVE_TICKET_WITH_SEC_CRED  = &H10
#ENDIF
#IF (%WIN32_WINNT >= &H0600)
%KERB_RETRIEVE_TICKET_CACHE_TICKET   = &H20
#ENDIF

#IF (%WIN32_WINNT >= &H0601)
%KERB_RETRIEVE_TICKET_MAX_LIFETIME   = &H40
#ENDIF

#IF (%WIN32_WINNT >= &H0501)
' Encryption Type options
%KERB_ETYPE_DEFAULT = &H0 ' don't specify etype in tkt req.

TYPE KERB_AUTH_DATA
    dType  AS DWORD
    Length AS DWORD
    uData  AS WORD PTR
END TYPE


TYPE KERB_NET_ADDRESS
    Family  AS DWORD
    Length  AS DWORD
    Address AS DWORD  ' ANSI ptr
END TYPE


TYPE KERB_NET_ADDRESSES
    Number  AS DWORD
    Addresses(%ANYSIZE_ARRAY-1) AS KERB_NET_ADDRESS
END TYPE
#ENDIF  ' #IF (%WIN32_WINNT >= &H0501)

'
' Types for the information about a ticket
'

TYPE KERB_EXTERNAL_NAME
    NameType  AS INTEGER
    NameCount AS WORD
    Names(%ANYSIZE_ARRAY-1) AS UNICODE_STRING
END TYPE


TYPE KERB_EXTERNAL_TICKET
    ServiceName         AS KERB_EXTERNAL_NAME PTR
    TargetName          AS KERB_EXTERNAL_NAME PTR
    ClientName          AS KERB_EXTERNAL_NAME PTR
    DomainName          AS UNICODE_STRING
    TargetDomainName    AS UNICODE_STRING
    AltTargetDomainName AS UNICODE_STRING   ' contains ClientDomainName
    SessionKey          AS KERB_CRYPTO_KEY
    TicketFlags         AS DWORD
    Flags               AS DWORD
    KeyExpirationTime   AS QUAD
    StartTime           AS LARGE_INTEGER
    EndTime             AS LARGE_INTEGER
    RenewUntil          AS LARGE_INTEGER
    TimeSkew            AS LARGE_INTEGER
    EncodedTicketSize   AS DWORD
    EncodedTicket       AS WORD PTR
END TYPE

TYPE KERB_RETRIEVE_TKT_REQUEST
    MessageType       AS KERB_PROTOCOL_MESSAGE_TYPE_enum
    LogonId           AS QUAD  ' LUID
    TargetName        AS UNICODE_STRING
    TicketFlags       AS DWORD
    CacheOptions      AS DWORD
    EncryptionType    AS LONG
    CredentialsHandle AS SecHandle
END TYPE

TYPE KERB_RETRIEVE_TKT_RESPONSE
    Ticket AS KERB_EXTERNAL_TICKET
END TYPE

'
' Used to purge entries from the ticket cache
'

TYPE KERB_PURGE_TKT_CACHE_REQUEST
    MessageType AS KERB_PROTOCOL_MESSAGE_TYPE_enum
    LogonId     AS QUAD  ' LUID
    ServerName  AS UNICODE_STRING
    RealmName   AS UNICODE_STRING
END TYPE

#IF (%WIN32_WINNT >= &H0501)
'
' Flags for purge requests
'

%KERB_PURGE_ALL_TICKETS = 1

TYPE KERB_PURGE_TKT_CACHE_EX_REQUEST
    MessageType    AS KERB_PROTOCOL_MESSAGE_TYPE_enum
    LogonId        AS QUAD  ' LUID
    Flags          AS DWORD
    TicketTemplate AS KERB_TICKET_CACHE_INFO_EX
END TYPE
#ENDIF

TYPE KERB_SUBMIT_TKT_REQUEST
    MessageType    AS KERB_PROTOCOL_MESSAGE_TYPE_enum
    LogonId        AS QUAD  ' LUID
    Flags          AS DWORD
    KEY            AS KERB_CRYPTO_KEY32   ' key to decrypt KERB_CRED
    KerbCredSize   AS DWORD
    KerbCredOffset AS DWORD
END TYPE



'
' KerbChangePassword
'
' KerbChangePassword changes the password on the KDC account plus
'  the password cache and logon credentials if applicable.
'
'

TYPE KERB_CHANGEPASSWORD_REQUEST
    MessageType   AS KERB_PROTOCOL_MESSAGE_TYPE_enum
    DomainName    AS UNICODE_STRING
    AccountName   AS UNICODE_STRING
    OldPassword   AS UNICODE_STRING
    NewPassword   AS UNICODE_STRING
    Impersonating AS BYTE  ' BOOLEAN
END TYPE



'
' KerbSetPassword
'
' KerbSetPassword changes the password on the KDC account plus
'  the password cache and logon credentials if applicable.
'
'

TYPE KERB_SETPASSWORD_REQUEST
    MessageType       AS KERB_PROTOCOL_MESSAGE_TYPE_enum
    LogonId           AS QUAD  ' LUID
    CredentialsHandle AS SecHandle
    Flags             AS DWORD
    DomainName        AS UNICODE_STRING
    AccountName       AS UNICODE_STRING
    Password          AS UNICODE_STRING
END TYPE


TYPE KERB_SETPASSWORD_EX_REQUEST DWORD
    MessageType       AS KERB_PROTOCOL_MESSAGE_TYPE_enum
    LogonId           AS QUAD  ' LUID
    CredentialsHandle AS SecHandle
    Flags             AS DWORD
    AccountRealm      AS UNICODE_STRING
    AccountName       AS UNICODE_STRING
    Password          AS UNICODE_STRING
    ClientRealm       AS UNICODE_STRING
    ClientName        AS UNICODE_STRING
    Impersonating     AS BYTE  ' BOOLEAN
    KdcAddress        AS UNICODE_STRING
    KdcAddressType    AS DWORD
END TYPE


%DS_UNKNOWN_ADDRESS_TYPE     = 0  ' anything *but* IP
%KERB_SETPASS_USE_LOGONID    = 1
%KERB_SETPASS_USE_CREDHANDLE = 2


TYPE KERB_DECRYPT_REQUEST
    MessageType       AS KERB_PROTOCOL_MESSAGE_TYPE_enum
    LogonId           AS QUAD  ' LUID
    Flags             AS DWORD
    CryptoType        AS LONG
    KeyUsage          AS LONG
    KEY               AS KERB_CRYPTO_KEY         ' optional
    EncryptedDataSize AS DWORD
    InitialVectorSize AS DWORD
    InitialVector     AS WORD PTR
    EncryptedData     AS WORD PTR
END TYPE

'
' If set, use the primary key from the current logon session of the one provided in the LogonId field.
' Otherwise, use the Key in the KERB_DECRYPT_MESSAGE.

%KERB_DECRYPT_FLAG_DEFAULT_KEY = &H00000001


TYPE KERB_DECRYPT_RESPONSE
    DecryptedData(%ANYSIZE_ARRAY-1) AS BYTE
END TYPE


'
' Request structure for adding a binding cache entry. TCB privilege
' is required for this operation.
'

TYPE KERB_ADD_BINDING_CACHE_ENTRY_REQUEST
    MessageType AS KERB_PROTOCOL_MESSAGE_TYPE_enum
    RealmName   AS UNICODE_STRING
    KdcAddress  AS UNICODE_STRING
    AddressType AS DWORD  'dsgetdc.h %DS_NETBIOS_ADDRESS OR %DS_INET_ADDRESS
END TYPE


#IF (%WIN32_WINNT >= &H0502)
'
' Request structure for reacquiring smartcard credentials for a
' given LUID.
' Requires TCB.
'
TYPE KERB_REFRESH_SCCRED_REQUEST
    MessageType    AS KERB_PROTOCOL_MESSAGE_TYPE_enum
    CredentialBlob AS UNICODE_STRING            ' optional
    LogonId        AS QUAD  ' LUID
    Flags          AS DWORD
END TYPE

'
' Flags for KERB_REFRESH_SCCRED_REQUEST
'
'  KERB_REFRESH_SCCRED_RELEASE
'  Release the smartcard handle for LUID
'
'      KERB_REFRESH_SCCRED_GETTGT
'  Use the certificate hash in the blob to get a TGT for the logon
'  session.
'
%KERB_REFRESH_SCCRED_RELEASE  = &H0
%KERB_REFRESH_SCCRED_GETTGT   = &H1
#ENDIF

' [this is a dubious check on the face of it]
#IF (%WIN32_WINNT <> &H0501)
'
' Request structure for adding extra Server credentials to a given
' logon session.  Only applicable during AcceptSecurityContext, and
' requires TCB to alter "other" creds
'

TYPE KERB_ADD_CREDENTIALS_REQUEST
    MessageType AS KERB_PROTOCOL_MESSAGE_TYPE_enum
    UserName    AS UNICODE_STRING
    DomainName  AS UNICODE_STRING
    Password    AS UNICODE_STRING
    LogonId     AS QUAD  ' LUID  ' optional
    Flags       AS DWORD
END TYPE


%KERB_REQUEST_ADD_CREDENTIAL     = 1
%KERB_REQUEST_REPLACE_CREDENTIAL = 2
%KERB_REQUEST_REMOVE_CREDENTIAL  = 4

#ENDIF ' #IF (%WIN32_WINNT <> &H0501)


#IF (%WIN32_WINNT >= &H0600)

TYPE KERB_ADD_CREDENTIALS_REQUEST_EX
    Credentials        AS KERB_ADD_CREDENTIALS_REQUEST
    '
    ' new for Ex
    '
    PrincipalNameCount AS DWORD
    PrincipalNames(%ANYSIZE_ARRAY-1) AS UNICODE_STRING
END TYPE


#ENDIF

'
' Request structure for transferring credentials between 2 luids.
' Requires TCB.
'

TYPE KERB_TRANSFER_CRED_REQUEST
    MessageType        AS KERB_PROTOCOL_MESSAGE_TYPE_enum
    OriginLogonId      AS QUAD  ' LUID
    DestinationLogonId AS QUAD  ' LUID
    Flags              AS DWORD
END TYPE

%KERB_TRANSFER_CRED_WITH_TICKETS = &H1



TYPE POLICY_AUDIT_SID_ARRAY

    UsersCount   AS DWORD
    UserSidArray AS DWORD  ' SID PTR PTR

END TYPE

TYPE AUDIT_POLICY_INFORMATION

    AuditSubCategoryGuid AS GUID
    AuditingInformation  AS DWORD
    AuditCategoryGuid    AS GUID

END TYPE

%AUDIT_SET_SYSTEM_POLICY    = (&H0001)
%AUDIT_QUERY_SYSTEM_POLICY  = (&H0002)
%AUDIT_SET_USER_POLICY      = (&H0004)
%AUDIT_QUERY_USER_POLICY    = (&H0008)
%AUDIT_ENUMERATE_USERS      = (&H0010)
%AUDIT_SET_MISC_POLICY      = (&H0020)
%AUDIT_QUERY_MISC_POLICY    = (&H0040)

%AUDIT_GENERIC_ALL          = (%STANDARD_RIGHTS_REQUIRED  OR _
                               %AUDIT_SET_SYSTEM_POLICY   OR _
                               %AUDIT_QUERY_SYSTEM_POLICY OR _
                               %AUDIT_SET_USER_POLICY     OR _
                               %AUDIT_QUERY_USER_POLICY   OR _
                               %AUDIT_ENUMERATE_USERS     OR _
                               %AUDIT_SET_MISC_POLICY     OR _
                               %AUDIT_QUERY_MISC_POLICY)

%AUDIT_GENERIC_READ         = (%STANDARD_RIGHTS_READ      OR _
                               %AUDIT_QUERY_SYSTEM_POLICY OR _
                               %AUDIT_QUERY_USER_POLICY   OR _
                               %AUDIT_ENUMERATE_USERS     OR _
                               %AUDIT_QUERY_MISC_POLICY)

%AUDIT_GENERIC_WRITE        = (%STANDARD_RIGHTS_WRITE     OR _
                               %AUDIT_SET_USER_POLICY     OR _
                               %AUDIT_SET_MISC_POLICY     OR _
                               %AUDIT_SET_SYSTEM_POLICY)

%AUDIT_GENERIC_EXECUTE      = (%STANDARD_RIGHTS_EXECUTE)


DECLARE FUNCTION AuditSetSystemPolicy LIB "AdvApi32.dll" _
    ALIAS "AuditSetSystemPolicy" ( _
    BYVAL pAuditPolicy  AS AUDIT_POLICY_INFORMATION PTR, _
    BYVAL dwPolicyCount AS DWORD _
    ) AS BYTE  ' BOOLEAN

DECLARE FUNCTION AuditSetPerUserPolicy LIB "AdvApi32.dll" _
    ALIAS "AuditSetPerUserPolicy" ( _
    pSid                AS SID, _
    BYVAL pAuditPolicy  AS AUDIT_POLICY_INFORMATION PTR, _
    BYVAL dwPolicyCount AS DWORD _
    ) AS BYTE  ' BOOLEAN

DECLARE FUNCTION AuditQuerySystemPolicy LIB "AdvApi32.dll" _
    ALIAS "AuditQuerySystemPolicy" ( _
    BYVAL pSubCategoryGuids AS GUID PTR, _
    BYVAL dwPolicyCount     AS DWORD, _
    ppAuditPolicy           AS ANY _   ' AUDIT_POLICY_INFORMATION PTR PTR
    ) AS BYTE  ' BOOLEAN

DECLARE FUNCTION AuditQueryPerUserPolicy LIB "AdvApi32.dll" _
    ALIAS "AuditQueryPerUserPolicy" ( _
    pSid                    AS SID, _
    BYVAL pSubCategoryGuids AS GUID PTR, _
    BYVAL dwPolicyCount     AS DWORD, _
    ppAuditPolicy           AS ANY _   ' AUDIT_POLICY_INFORMATION PTR PTR
    ) AS BYTE  ' BOOLEAN

DECLARE FUNCTION AuditEnumeratePerUserPolicy LIB "AdvApi32.dll" _
    ALIAS "AuditEnumeratePerUserPolicy" ( _
    ppAuditSidArray AS ANY _   ' POLICY_AUDIT_SID_ARRAY PTR PTR
    ) AS BYTE  ' BOOLEAN

DECLARE FUNCTION AuditComputeEffectivePolicyBySid LIB "AdvApi32.dll" _
    ALIAS "AuditComputeEffectivePolicyBySid" ( _
    pSid                    AS SID, _
    BYVAL pSubCategoryGuids AS GUID PTR, _
    BYVAL dwPolicyCount     AS DWORD, _
    ppAuditPolicy           AS ANY _   ' AUDIT_POLICY_INFORMATION PTR PTR
    ) AS BYTE  ' BOOLEAN

DECLARE FUNCTION AuditComputeEffectivePolicyByToken LIB "AdvApi32.dll" _
    ALIAS "AuditComputeEffectivePolicyByToken" ( _
    BYVAL hTokenHandle      AS DWORD, _   ' HANDLE
    BYVAL pSubCategoryGuids AS GUID PTR, _
    BYVAL dwPolicyCount     AS DWORD, _
    ppAuditPolicy           AS ANY _   ' AUDIT_POLICY_INFORMATION PTR PTR
    ) AS BYTE  ' BOOLEAN

DECLARE FUNCTION AuditEnumerateCategories LIB "AdvApi32.dll" _
    ALIAS "AuditEnumerateCategories" ( _
    ppAuditCategoriesArray AS ANY, _    ' GUID PTR PTR,
    pdwCountReturned       AS DWORD _
    ) AS BYTE  ' BOOLEAN

DECLARE FUNCTION AuditEnumerateSubCategories LIB "AdvApi32.dll" _
    ALIAS "AuditEnumerateSubCategories" ( _
    pAuditCategoryGuid              AS GUID, _
    BYVAL bRetrieveAllSubCategories AS BYTE, _  ' BOOLEAN
    ppAuditSubCategoriesArray       AS ANY, _   ' GUID PTR PTR,
    pdwCountReturned                AS DWORD _
    ) AS BYTE  ' BOOLEAN

DECLARE FUNCTION AuditLookupCategoryNameW LIB "AdvApi32.dll" _
    ALIAS "AuditLookupCategoryNameW" ( _
    pAuditCategoryGuid AS GUID, _
    ppszCategoryName   AS ANY _   ' PWSTR*
    ) AS BYTE  ' BOOLEAN

DECLARE FUNCTION AuditLookupCategoryNameA LIB "AdvApi32.dll" _
    ALIAS "AuditLookupCategoryNameA" ( _
    pAuditCategoryGuid AS GUID, _
    ppszCategoryName   AS ANY _    ' PSTR*
    ) AS BYTE  ' BOOLEAN

#IF %DEF(%UNICODE)
MACRO AuditLookupCategoryName =AuditLookupCategoryNameW
#ELSE
MACRO AuditLookupCategoryName =AuditLookupCategoryNameA
#ENDIF

DECLARE FUNCTION AuditLookupSubCategoryNameW LIB "AdvApi32.dll" _
    ALIAS "AuditLookupSubCategoryNameW" ( _
    pAuditSubCategoryGuid AS GUID, _
    ppszSubCategoryName   AS ANY _    ' PWSTR*
    ) AS BYTE  ' BOOLEAN

DECLARE FUNCTION AuditLookupSubCategoryNameA LIB "AdvApi32.dll" _
    ALIAS "AuditLookupSubCategoryNameA" ( _
    pAuditSubCategoryGuid AS GUID, _
    ppszSubCategoryName   AS ANY _    ' PSTR*
    ) AS BYTE  ' BOOLEAN

#IF %DEF(%UNICODE)
MACRO AuditLookupSubCategoryName =AuditLookupSubCategoryNameW
#ELSE
MACRO AuditLookupSubCategoryName =AuditLookupSubCategoryNameA
#ENDIF

DECLARE FUNCTION AuditLookupCategoryIdFromCategoryGuid LIB "AdvApi32.dll" _
    ALIAS "AuditLookupCategoryIdFromCategoryGuid" ( _
    pAuditCategoryGuid AS GUID, _
    pAuditCategoryId   AS POLICY_AUDIT_EVENT_TYPE_enum _
    ) AS BYTE  ' BOOLEAN

DECLARE FUNCTION AuditLookupCategoryGuidFromCategoryId LIB "AdvApi32.dll" _
    ALIAS "AuditLookupCategoryGuidFromCategoryId" ( _
    BYVAL AuditCategoryId AS POLICY_AUDIT_EVENT_TYPE_enum, _
    pAuditCategoryGuid    AS GUID _
    ) AS BYTE  ' BOOLEAN

DECLARE FUNCTION AuditSetSecurity LIB "AdvApi32.dll" _
    ALIAS "AuditSetSecurity" ( _
    BYVAL SecurityInformation AS SECURITY_INFORMATION, _
    pSecurityDescriptor       AS SECURITY_DESCRIPTOR _
    ) AS BYTE  ' BOOLEAN

DECLARE FUNCTION AuditQuerySecurity LIB "AdvApi32.dll" _
    ALIAS "AuditQuerySecurity" ( _
    BYVAL SecurityInformation AS SECURITY_INFORMATION, _
    ppSecurityDescriptor      AS ANY  _  ' SECURITY_DESCRIPTOR PTR PTR
    ) AS BYTE  ' BOOLEAN

DECLARE FUNCTION AuditSetGlobalSaclW LIB "AdvApi32.dll" _
    ALIAS "AuditSetGlobalSaclW" ( _
    ObjectTypeName AS WSTRINGZ, _
    pAcl           AS ACL _
    ) AS BYTE  ' BOOLEAN

DECLARE FUNCTION AuditSetGlobalSaclA LIB "AdvApi32.dll" _
    ALIAS "AuditSetGlobalSaclA" ( _
    ObjectTypeName AS ASCIIZ, _
    pAcl           AS ACL _
    ) AS BYTE  ' BOOLEAN

#IF %DEF(%UNICODE)
MACRO AuditSetGlobalSacl=AuditSetGlobalSaclW
#ELSE
MACRO AuditSetGlobalSacl=AuditSetGlobalSaclA
#ENDIF

DECLARE FUNCTION AuditQueryGlobalSaclW LIB "AdvApi32.dll" _
    ALIAS "AuditQueryGlobalSaclW" ( _
    ObjectTypeName AS WSTRINGZ, _
    ppAcl          AS ANY _           ' ACL PTR PTR
    ) AS BYTE  ' BOOLEAN

DECLARE FUNCTION AuditQueryGlobalSaclA LIB "AdvApi32.dll" _
    ALIAS "AuditQueryGlobalSaclA" ( _
    ObjectTypeName AS ASCIIZ, _
    ppAcl          AS ANY _           ' ACL PTR PTR
    ) AS BYTE  ' BOOLEAN

#IF %DEF(%UNICODE)
MACRO AuditQueryGlobalSacl=AuditQueryGlobalSaclW
#ELSE
MACRO AuditQueryGlobalSacl=AuditQueryGlobalSaclA
#ENDIF

DECLARE SUB AuditFree LIB "AdvApi32.dll" ALIAS "AuditFree" (Buffer AS ANY)


#IF (%WIN32_WINNT >= &H0601)

'
' Pku2u package name
'

$PKU2U_PACKAGE_NAME_A    = "pku2u"
$$PKU2U_PACKAGE_NAME_W   = "pku2u"$$
MACRO PKU2U_PACKAGE_NAME = $$PKU2U_PACKAGE_NAME_W

#ENDIF ' %WIN32_WINNT


#IF (%WIN32_WINNT >= &H0601)

' the following structure contains the ASN.1 encoded X.509 certificate
TYPE PKU2U_CERT_BLOB
    CertOffset AS DWORD  ' each element is a byte
    CertLength AS WORD   '
END TYPE

%PKU2U_CREDUI_CONTEXT_VERSION = &H4154414454524543  ' "CERTDATA"

TYPE PKU2U_CREDUI_CONTEXT
    Version           AS QUAD   ' ULONG64
    cbHeaderLength    AS WORD
    cbStructureLength AS DWORD
    CertArrayCount    AS WORD   ' followed by an array of PKU2U_CERT_BLOB
    CertArrayOffset   AS DWORD  ' offset to the array
END TYPE


'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''
'' LsaLogonUser parameters
''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

MACRO PKU2U_LOGON_SUBMIT_TYPE_enum=LONG
ENUM PKU2U_LOGON_SUBMIT_TYPE SINGULAR
    Pku2uCertificateS4ULogon = 14
END ENUM

TYPE PKU2U_CERTIFICATE_S4U_LOGON
    MessageType       AS PKU2U_LOGON_SUBMIT_TYPE_enum
    Flags             AS DWORD
    UserPrincipalName AS UNICODE_STRING
    DomainName        AS UNICODE_STRING
    CertificateLength AS DWORD    ' for the client certificate
    Certificate       AS WORD PTR ' for the client certificate, BER encoded
END TYPE

#ENDIF ' %WIN32_WINNT



#ENDIF  ' #IF NOT %DEF(%NTSECAPI)
