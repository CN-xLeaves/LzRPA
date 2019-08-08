'------------------------------------------------------------------------------
'
'  LMJoin.inc -
'    Definitions and prototypes for the Net setup apis, for joining/unjoinging
'    domains and promoting/demoting servers
'
'  Copyright (c) 2009-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from LMJoin.h dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%LMJOIN_H = 1

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "LmCons.inc"

'
' Types of name that can be validated
'
MACRO NETSETUP_NAME_TYPE_enum=LONG
ENUM NETSETUP_NAME_TYPE SINGULAR
    NetSetupUnknown
    NetSetupMachine
    NetSetupWorkgroup
    NetSetupDomain
    NetSetupNonExistentDomain
#IF (%WIN32_WINNT >= &H0500)
    NetSetupDnsMachine
#ENDIF
END ENUM


'
' Status of a workstation
'
MACRO NETSETUP_JOIN_STATUS_enum=LONG
ENUM NETSETUP_JOIN_STATUS SINGULAR
    NetSetupUnknownStatus
    NetSetupUnjoined
    NetSetupWorkgroupName
    NetSetupDomainName
END ENUM

'
' Flags to determine the behavior of the join/unjoin APIs
'
%NETSETUP_JOIN_DOMAIN   = &H00000001      ' If not present, workgroup is joined
%NETSETUP_ACCT_CREATE   = &H00000002      ' Do the server side account creation/rename
%NETSETUP_ACCT_DELETE   = &H00000004      ' Delete the account when a domain is left
%NETSETUP_WIN9X_UPGRADE = &H00000010      ' Invoked during upgrade of Windows 9x to
                                          ' Windows NT
%NETSETUP_DOMAIN_JOIN_IF_JOINED = &H00000020  ' Allow the client to join a new domain
                                              ' even if it is already joined to a domain
%NETSETUP_JOIN_UNSECURE = &H00000040      ' Performs an unsecure join
%NETSETUP_MACHINE_PWD_PASSED = &H00000080 ' Indicates that the machine (not user) password
                                          '  is passed. Valid only for unsecure joins
%NETSETUP_DEFER_SPN_SET = &H00000100      ' Specifies that writting SPN and DnsHostName
                                          '  attributes on the computer object should be
                                          '  defered until rename that will follow join

%NETSETUP_JOIN_DC_ACCOUNT    = &H00000200 ' Allow join if existing account is a DC
%NETSETUP_JOIN_WITH_NEW_NAME = &H00000400 ' Check for computer name change
%NETSETUP_JOIN_READONLY      = &H00000800 ' Perform join using a pre-created account w/o requiring a writable DC

%NETSETUP_DNS_NAME_CHANGES_ONLY = &H00001000 ' When performing machine rename only update DNS based names

%NETSETUP_INSTALL_INVOCATION = &H00040000 ' The APIs were invoked during install

%NETSETUP_AMBIGUOUS_DC       = &H00001000  ' When joiing the domain don't try to set the
                                           ' preferred DC in the registry.
%NETSETUP_NO_NETLOGON_CACHE  = &H00002000  ' Don't create the netlogon cache
%NETSETUP_DONT_CONTROL_SERVICES = &H00004000 ' Don't force netlogon to start
%NETSETUP_SET_MACHINE_NAME   = &H00008000  ' For offline join only, set target machine hostname and NB name.
%NETSETUP_FORCE_SPN_SET      = &H00010000  ' Override other settings during domain join
                                           ' and attempt to set the SPN.
%NETSETUP_NO_ACCT_REUSE      = &H00020000  ' Do not reuse an existing account

%NETSETUP_IGNORE_UNSUPPORTED_FLAGS = &H10000000 ' If this bit is set, unrecognized flags
                                                '  will be ignored by the NetJoin API and
                                                '  the API will behave as if the flags
                                                '  were not set.

%NETSETUP_VALID_UNJOIN_FLAGS = (%NETSETUP_ACCT_DELETE _
                             OR %NETSETUP_IGNORE_UNSUPPORTED_FLAGS _
                             OR %NETSETUP_JOIN_DC_ACCOUNT)

' The following flags are used when the system is processing information left from a prior offline
' join.  We want to force DC discovery and we don't want to create the netlogon cache.  We also
' don't want to immediately force netlogon to start, let it start on its own.
%NETSETUP_PROCESS_OFFLINE_FLAGS = (%NETSETUP_JOIN_DOMAIN OR            _
                                   %NETSETUP_DOMAIN_JOIN_IF_JOINED OR  _
                                   %NETSETUP_JOIN_WITH_NEW_NAME OR     _
                                   %NETSETUP_DONT_CONTROL_SERVICES OR  _
                                   %NETSETUP_MACHINE_PWD_PASSED)

'
' &H80000000 is reserved for internal use only
'

'
' Joins a machine to the domain.
'
DECLARE FUNCTION NetJoinDomain LIB "NetApi32.dll" ALIAS "NetJoinDomain" ( _
    lpServer           AS WSTRINGZ, _
    lpDomain           AS WSTRINGZ, _
    lpAccountOU        AS WSTRINGZ, _
    lpAccount          AS WSTRINGZ, _
    lpPassword         AS WSTRINGZ, _
    BYVAL fJoinOptions AS DWORD _
    ) AS NET_API_STATUS

#IF (%WIN32_WINNT >= &H0601)

'
' Flags to determine the behavior of NetProvisionComputerAccount
'

' The caller requires account creation by privilege, this option will cause a retry
' on failure using down level account creation APIs.
'
%NETSETUP_PROVISION_DOWNLEVEL_PRIV_SUPPORT = &H00000001

' If the named account already exists an attempt will be made to reuse. Requires
' sufficient credentials i.e. Domain Administrator or the object owner.
'
%NETSETUP_PROVISION_REUSE_ACCOUNT          = &H00000002

' Use the default machine account password which is the machine name in lowercase.
'
%NETSETUP_PROVISION_USE_DEFAULT_PASSWORD   = &H00000004

' Do not try to find the account on any DC in the domain. This is faster but
' should only be used when the caller is certain that an account by the same
' name hasn't recently been created. Only valid when specifying the target DC.
' When the pre-requisites are met, this option allows for must faster provisioning
' useful for scenarios such as batch processing.
'
%NETSETUP_PROVISION_SKIP_ACCOUNT_SEARCH    = &H00000008

'
' The following are reserved for internal use.
'

' The operation is online.
' This is an internal option not available through the API.
'
%NETSETUP_PROVISION_ONLINE_CALLER          = &H40000000

' Validate the machine password only. This is an internal option not available
' through the API.
'
%NETSETUP_PROVISION_CHECK_PWD_ONLY         = &H80000000???


DECLARE FUNCTION NetProvisionComputerAccount LIB "NetApi32.dll" _
    ALIAS "NetProvisionComputerAccount" ( _
    lpDomain                AS WSTRINGZ, _
    lpMachineName           AS WSTRINGZ, _
    lpMachineAccountOU      AS WSTRINGZ, _
    lpDcName                AS WSTRINGZ, _
    BYVAL dwOptions         AS DWORD, _
    pProvisionBinData       AS ANY, _  ' BYTE PTR PTR
    pdwProvisionBinDataSize AS DWORD, _
    pProvisionTextData      AS ANY _  ' LPWSTR *
    ) AS NET_API_STATUS

DECLARE FUNCTION NetRequestOfflineDomainJoin LIB "NetApi32.dll" _
    ALIAS "NetRequestOfflineDomainJoin" ( _
    BYVAL pProvisionBinData      AS BYTE PTR, _
    BYVAL cbProvisionBinDataSize AS DWORD, _
    BYVAL dwOptions              AS DWORD, _
    lpWindowsPath                AS WSTRINGZ _
    ) AS NET_API_STATUS

#ENDIF ' (%WIN32_WINNT >= &H0601)

DECLARE FUNCTION NetUnjoinDomain LIB "NetApi32.dll" ALIAS "NetUnjoinDomain" ( _
    lpServer             AS WSTRINGZ, _
    lpAccount            AS WSTRINGZ, _
    lpPassword           AS WSTRINGZ, _
    BYVAL fUnjoinOptions AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetRenameMachineInDomain LIB "NetApi32.dll" _
    ALIAS "NetRenameMachineInDomain" ( _
    lpServer             AS WSTRINGZ, _
    lpNewMachineName     AS WSTRINGZ, _
    lpAccount            AS WSTRINGZ, _
    lpPassword           AS WSTRINGZ, _
    BYVAL fRenameOptions AS DWORD _
    ) AS NET_API_STATUS


'
' Determine the validity of a name
'
DECLARE FUNCTION NetValidateName LIB "NetApi32.dll" ALIAS "NetValidateName" ( _
    lpServer       AS WSTRINGZ, _
    lpName         AS WSTRINGZ, _
    lpAccount      AS WSTRINGZ, _
    lpPassword     AS WSTRINGZ, _
    BYVAL NameType AS NETSETUP_NAME_TYPE_enum _
    ) AS NET_API_STATUS

'
' Determines whether a workstation is joined to a domain or not
'
DECLARE FUNCTION NetGetJoinInformation LIB "NetApi32.dll" _
    ALIAS "NetGetJoinInformation" ( _
    lpServer     AS WSTRINGZ, _
    lpNameBuffer AS ANY, _  ' LPWSTR *
    BufferType   AS NETSETUP_JOIN_STATUS_enum _
    ) AS NET_API_STATUS


'
' Determines the list of OUs that the client can create a machine account in
'
DECLARE FUNCTION NetGetJoinableOUs LIB "NetApi32.dll" _
    ALIAS "NetGetJoinableOUs" ( _
    lpServer   AS WSTRINGZ, _
    lpDomain   AS WSTRINGZ, _
    lpAccount  AS WSTRINGZ, _
    lpPassword AS WSTRINGZ, _
    OUCount    AS DWORD, _
    OUs        AS ANY _  ' LPWSTR **
    ) AS NET_API_STATUS

#IF (%WIN32_WINNT >= &H0501)

'
' Computer rename preparation APIs
'

%NET_IGNORE_UNSUPPORTED_FLAGS = &H01

DECLARE FUNCTION NetAddAlternateComputerName LIB "NetApi32.dll" _
    ALIAS "NetAddAlternateComputerName" ( _
    Server                AS WSTRINGZ, _
    AlternateName         AS WSTRINGZ, _
    DomainAccount         AS WSTRINGZ, _
    DomainAccountPassword AS WSTRINGZ, _
    BYVAL Reserved        AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetRemoveAlternateComputerName LIB "NetApi32.dll" _
    ALIAS "NetRemoveAlternateComputerName" ( _
    Server                AS WSTRINGZ, _
    AlternateName         AS WSTRINGZ, _
    DomainAccount         AS WSTRINGZ, _
    DomainAccountPassword AS WSTRINGZ, _
    BYVAL Reserved        AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetSetPrimaryComputerName LIB "NetApi32.dll" _
    ALIAS "NetSetPrimaryComputerName" ( _
    Server                AS WSTRINGZ, _
    PrimaryName           AS WSTRINGZ, _
    DomainAccount         AS WSTRINGZ, _
    DomainAccountPassword AS WSTRINGZ, _
    BYVAL Reserved        AS DWORD _
    ) AS NET_API_STATUS

'
' The following enumeration must be kept
' in sync with COMPUTER_NAME_TYPE defined
' in winbase.h
'

MACRO NET_COMPUTER_NAME_TYPE_enum=LONG
ENUM NET_COMPUTER_NAME_TYPE SINGULAR
    NetPrimaryComputerName
    NetAlternateComputerNames
    NetAllComputerNames
    NetComputerNameTypeMax
END ENUM

DECLARE FUNCTION NetEnumerateComputerNames LIB "NetApi32.dll" _
    ALIAS "NetEnumerateComputerNames" ( _
    Server         AS WSTRINGZ, _
    BYVAL NameType AS NET_COMPUTER_NAME_TYPE_enum, _
    BYVAL Reserved AS DWORD, _
    EntryCount     AS DWORD, _
    ComputerNames  AS ANY _  ' LPWSTR **
    ) AS NET_API_STATUS

#ENDIF  ' (%WIN32_WINNT >= &H0501)
