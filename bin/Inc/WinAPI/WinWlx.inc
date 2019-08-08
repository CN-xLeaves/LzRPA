'------------------------------------------------------------------------------
'
'  WinWLX.inc -- WLX = WinLogon eXtension
'
'    This file contains definitions, data types, and routine prototypes
'    necessary to produce a replacement Graphical Identification aNd
'    Authentication (GINA) DLL for Winlogon.
'
'    Author: [of winwlx.h]
'        Richard Ward (RichardW) and Jim Kelly (JimK) May-1994
'
'  Copyright (c) 2002-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated: 23 Mar 2011
'
'------------------------------------------------------------------------------
'  from WinWLX.h build version 0001 dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WINWLX = 1

#INCLUDE "WinNT.inc"



''''''''''''''''''''''''''''''''''''
'
'  #defines
'
''''''''''''''''''''''''''''''''''''


''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''
'
' Revisions of Winlogon API available for use by GINAs
' Version is two parts: Major revision and minor revision.
' Major revision is the upper 16-bits, minor is the lower
' 16-bits.
'

%WLX_VERSION_1_0        = &H00010000
%WLX_VERSION_1_1        = &H00010001
%WLX_VERSION_1_2        = &H00010002
%WLX_VERSION_1_3        = &H00010003
%WLX_VERSION_1_4        = &H00010004
%WLX_CURRENT_VERSION    = %WLX_VERSION_1_4


''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''
'
' Secure attention sequence types
' These values are passed to routines that have a dwSasType
' parameter.
'
'  ALL VALUES FROM 0 TO 127 ARE RESERVED FOR MICROSOFT DEFINITION.
'  VALUES ABOVE 127 ARE RESERVED FOR CUSTOMER DEFINITION.
'
'      CTRL_ALT_DEL - used to indicate that the standard ctrl-alt-del
'          secure attention sequence has been entered.
'
'      SCRNSVR_TIMEOUT - used to indicate that keyboard/mouse inactivity
'          has lead to a screensaver activation.  It is up to the GINA
'          DLL whether this constitutes a workstation locking event.
'
'      SCRNSVR_ACTIVITY - used to indicate that keyboard or mouse
'          activity occured while a secure screensaver was active.
'
'      SC_INSERT - used to indicate that a smart card has been inserted
'          to a compatible device
'
'      SC_REMOVE - used to indicate that a smart card has been removed
'          from a compatible device
'

%WLX_SAS_TYPE_TIMEOUT                  = 0
%WLX_SAS_TYPE_CTRL_ALT_DEL             = 1
%WLX_SAS_TYPE_SCRNSVR_TIMEOUT          = 2
%WLX_SAS_TYPE_SCRNSVR_ACTIVITY         = 3
%WLX_SAS_TYPE_USER_LOGOFF              = 4
%WLX_SAS_TYPE_SC_INSERT                = 5
%WLX_SAS_TYPE_SC_REMOVE                = 6
%WLX_SAS_TYPE_AUTHENTICATED            = 7
%WLX_SAS_TYPE_SC_FIRST_READER_ARRIVED  = 8
%WLX_SAS_TYPE_SC_LAST_READER_REMOVED   = 9
%WLX_SAS_TYPE_SWITCHUSER               = 10
%WLX_SAS_TYPE_MAX_MSFT_VALUE           = 127


'
' This structure is available through WlxGetOption, and is
' passed as the lParam for any S/C SAS notices sent to windows
'
TYPE WLX_SC_NOTIFICATION_INFO
    pszCard           AS WSTRINGZ PTR
    pszReader         AS WSTRINGZ PTR
    pszContainer      AS WSTRINGZ PTR
    pszCryptoProvider AS WSTRINGZ PTR
END TYPE



''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''
'
' Upon successful logon, the GINA DLL may specify any of the following
' options to Winlogon (via the dwOptions parameter of the WlxLoggedOutSas()
' api).  When set, these options specify:
'
'      NO_PROFILE - Winlogon must NOT load a profile for the logged
'                   on user.  Either the GINA DLL will take care of
'                   this activity, or the user does not need a profile.
'

%WLX_LOGON_OPT_NO_PROFILE      = &H00000001



''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''
'
' GINA DLLs are expected to return account information to Winlogon
' following a successful logon.  This information allows Winlogon
' to support profile loading and supplemental network providers.
'
' To allow different sets of profile information to be returned
' by GINAs over time, the first DWORD of each profile structure
' is expected to contain a type-identifier.  The following constants
' are the defined profile type identifiers.
'

'
' Standard profile is V2_0
'

%WLX_PROFILE_TYPE_V1_0         = 1
%WLX_PROFILE_TYPE_V2_0         = 2



''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''
'
' WlxLoggedOnSas() and WlxWkstaLockedSas() return an action
' value to Winlogon directing Winlogon to either remain unchanged
' or to perform some action (such as force-log the user off).
' These are the values that may be returned.  Note, however, that
' not all of the values may be returned by both of these api.  See
' the description of each api to see which values are expected from
' each.
'
'  LOGON              - User has logged on
'  NONE               - Don't change the state of the window station.
'  LOCK_WKSTA         - Lock the workstation, wait for next SAS.
'  LOGOFF             - Log the user off of the workstation.
'  SHUTDOWN           - Log the user off and shutdown the machine.
'  PWD_CHANGED        - Indicates that the user changed their password.  Notify network providers.
'  TASKLIST           - Invoke the task list.
'  UNLOCK_WKSTA       - Unlock the workstation.
'  FORCE_LOGOFF       - Forcibly log the user off.
'  SHUTDOWN_POWER_OFF - Turn off machine after shutting down.
'  SHUTDOWN_REBOOT    - Reboot machine after shutting down.
'  SHUTDOWN_SLEEP     - Put the machine to sleep
'  SHUTDOWN_SLEEP2    - Put the machine to sleep and disable wakeup events
'  SHUTDOWN_HIBERNATE - Hibernate the machine
'  RECONNECTED        - Session was reconnected to an earlier session
'

%WLX_SAS_ACTION_LOGON                    = 1
%WLX_SAS_ACTION_NONE                     = 2
%WLX_SAS_ACTION_LOCK_WKSTA               = 3
%WLX_SAS_ACTION_LOGOFF                   = 4
%WLX_SAS_ACTION_SHUTDOWN                 = 5
%WLX_SAS_ACTION_PWD_CHANGED              = 6
%WLX_SAS_ACTION_TASKLIST                 = 7
%WLX_SAS_ACTION_UNLOCK_WKSTA             = 8
%WLX_SAS_ACTION_FORCE_LOGOFF             = 9
%WLX_SAS_ACTION_SHUTDOWN_POWER_OFF       = 10
%WLX_SAS_ACTION_SHUTDOWN_REBOOT          = 11
%WLX_SAS_ACTION_SHUTDOWN_SLEEP           = 12
%WLX_SAS_ACTION_SHUTDOWN_SLEEP2          = 13
%WLX_SAS_ACTION_SHUTDOWN_HIBERNATE       = 14
%WLX_SAS_ACTION_RECONNECTED              = 15
%WLX_SAS_ACTION_DELAYED_FORCE_LOGOFF     = 16
%WLX_SAS_ACTION_SWITCH_CONSOLE           = 17


''''''''''''''''''''''''''''''''''''
'
'  Window Messages
'
''''''''''''''''''''''''''''''''''''

'
' The WM_SAS is defined as follows
'
'  The wParam parameter has the SAS Type (above)

%WLX_WM_SAS              = %WM_USER + 601


'
' Dialog return values
'
' These may be returned by dialogs started by a GINA dll.
'
%WLX_DLG_SAS                   = 101
%WLX_DLG_INPUT_TIMEOUT         = 102     ' Input (keys, etc) timed out
%WLX_DLG_SCREEN_SAVER_TIMEOUT  = 103     ' Screen Saver activated
%WLX_DLG_USER_LOGOFF           = 104     ' User logged off




''''''''''''''''''''''''''''''''''''
'
'  #data types
'
''''''''''''''''''''''''''''''''''''


''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''
'
' The WLX_PROFILE_* structure is returned from a GINA DLL
' following authentication.  This information is used by Winlogon
' to support supplemental Network Providers and to load the
' newly logged-on user's profile.
'
' Winlogon is responsible for freeing both the profile structure
' and the fields within the structure that are marked as separately
' deallocatable.
'

TYPE WLX_PROFILE_V1_0

    ' This field identifies the type of profile being returned by a
    ' GINA DLL.  Profile types are defined with the prefix
    ' WLX_PROFILE_TYPE_xxx.  It allows Winlogon to typecast the
    ' structure so the remainder of the structure may be referenced.

    dwType AS DWORD

    ' pathname of profile to load for user.
    '
    ' The buffer pointed to by this field must be separately allocated.
    ' Winlogon will free the buffer when it is no longer needed.

    pszProfile AS WSTRINGZ PTR

END TYPE


TYPE WLX_PROFILE_V2_0

    ' This field identifies the type of profile being returned by a
    ' GINA DLL.  Profile types are defined with the prefix
    ' WLX_PROFILE_TYPE_xxx.  It allows Winlogon to typecast the
    ' structure so the remainder of the structure may be referenced.

    dwType AS DWORD

    ' pathname of profile to load for user.
    '
    ' This parameter can be NULL.  If so, the user has a local
    ' profile only.
    '
    ' The buffer pointed to by this field must be separately allocated.
    ' Winlogon will free the buffer when it is no longer needed.

    pszProfile AS WSTRINGZ PTR

    ' pathname of policy to load for user.
    '
    ' This parameter can be NULL which prevents network wide policy
    ' from being applied.
    '
    ' The buffer pointed to by this field must be separately allocated.
    ' Winlogon will free the buffer when it is no longer needed.

    pszPolicy AS WSTRINGZ PTR

    ' pathname of network default user profile
    '
    ' This parameter can be NULL, which causes the Default User
    ' profile on the local machine to be used.
    '
    ' The buffer pointed to by this field must be separately allocated.
    ' Winlogon will free the buffer when it is no longer needed.

    pszNetworkDefaultUserProfile AS WSTRINGZ PTR

    ' name of the server which validated the user account
    '
    ' This is used to enumerate globals groups the user belongs
    ' to for policy support.  This parameter can be NULL.
    '
    ' The buffer pointed to by this field must be separately allocated.
    ' Winlogon will free the buffer when it is no longer needed.

    pszServerName AS WSTRINGZ PTR

    ' pointer to a series of null terminated environment variables
    '
    ' envname=environment variable value
    '   - or -
    ' envname=%OtherVar%\more text
    '
    ' Each environment variable is NULL terminated with the last
    ' environment variable double NULL terminated.  These variables
    ' are set into the user's initial environment.  The environment
    ' variable value can contain other environment variables wrapped
    ' in "%" signs. This parameter can be NULL.
    '
    ' The buffer pointed to by this field must be separately allocated.
    ' Winlogon will free the buffer when it is no longer needed.

    pszEnvironment AS WSTRINGZ PTR

END TYPE



''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''
'
' The WLX_NPR_NOTIFICATION_INFO structure is returned
' from a GINA DLL following successful authentication.
' This information is used by Winlogon to provide
' identification and authentication information already
' collected to network providers.  Winlogon is
' responsible for freeing both the main structure and all
' string and other buffers pointed to from within the
' structure.
'

TYPE WLX_MPR_NOTIFY_INFO

    ' The name of the account logged onto (e.g. REDMOND\Joe).
    ' The string pointed to by this field must be separately
    ' allocated and will be separately deallocated by Winlogon.

    pszUserName AS WSTRINGZ PTR

    ' The string pointed to by this field must be separately
    ' allocated and will be separately deallocated by Winlogon.

    pszDomain AS WSTRINGZ PTR

    ' Cleartext password of the user account.  If the OldPassword
    ' field is non-null, then this field contains the new password
    ' in a password change operation.  The string pointed to by
    ' this field must be separately allocated and will be seperately
    ' deallocated by Winlogon.

    pszPassword AS WSTRINGZ PTR

    ' Cleartext old password of the user account whose password
    ' has just been changed.  The Password field contains the new
    ' password.  The string pointed to by this field must be
    ' separately allocated and will be separately deallocated by
    ' Winlogon.

    pszOldPassword AS WSTRINGZ PTR

END TYPE



''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''
'
' WLX_TERMINAL_SERVICES_DATA is used by the GINA during a
' WlxQueryTerminalServicesData() callback into WinLogon from the
' WlxLoggedOutSAS() context, after the user name and domain are known.
' This structure relates to TS user configuration information which is
' retrieved from the Domain Controller and SAM database. Having WinLogon
' pass this information means the GINA does not need to do the same
' off-machines lookups again.
'

%WLX_DIRECTORY_LENGTH = 256

TYPE WLX_TERMINAL_SERVICES_DATA

    ' TS profile path, overrides the standard profile path.

    ProfilePath AS WSTRINGZ * %WLX_DIRECTORY_LENGTH + 1

    ' TS home directory, overrides standard home directory.

    HomeDir AS WSTRINGZ * %WLX_DIRECTORY_LENGTH + 1

    ' TS home directory drive, overrides standard drive.

    HomeDirDrive AS WSTRINGZ * 4

END TYPE



''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''
'
' The WLX_CLIENT_CREDENTIALS_INFO structure is returned
' from winlogon from the WlxQueryClientCredentials() call.
'
' This allows a network client WinStation to pass client
' credentials for automatic logon.
'
' The MSGINA DLL is responsible for freeing the memory
' and substrings with LocalFree().
'

%WLX_CREDENTIAL_TYPE_V1_0 = 1
%WLX_CREDENTIAL_TYPE_V2_0 = 2

TYPE WLX_CLIENT_CREDENTIALS_INFO_V1_0

    ' This field identifies the type of credentials structure being allocated
    ' by GINA DLL.  Credential types are defined with the prefix
    ' WLX_CREDENTIAL_TYPE_xxx.  It allows Winlogon to typecast the
    ' structure so the remainder of the structure may be referenced.

    dwType      AS DWORD

    pszUserName AS WSTRINGZ PTR
    pszDomain   AS WSTRINGZ PTR
    pszPassword AS WSTRINGZ PTR

    ' This field forces a prompt for the password. This
    ' is due to an administrator override.
    '
    ' This allows the distinguishing of autologon with no password.

    fPromptForPassword AS LONG

END TYPE

TYPE WLX_CLIENT_CREDENTIALS_INFO_V2_0

    dwType             AS DWORD
    pszUserName        AS WSTRINGZ PTR
    pszDomain          AS WSTRINGZ PTR
    pszPassword        AS WSTRINGZ PTR
    fPromptForPassword AS LONG

    ' This field tells winlogon to disconnect/abort the logon attempt if the
    ' provided password is incorrect, or if it should reprompt (current
    ' behavior)

    fDisconnectOnLogonFailure AS LONG

END TYPE


''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''
'
' The WLX_CONSOLESWITCH_CREDENTIALS_INFO structure is returned
' from gina in response to WlxGetConsoleSwitchCredentials calls.

' This structure is also returned from winlogon in response to
' to WlxQueryConsoleSwitchCredentials call
'
' This is used to implement single session Terminal Server. A remote
' session winlogon calls WlxGetConsoleSwitchCredentials to get the token
' and other info of the logged on user from msgina. This info is then passed to
' the console session winlogon to autologon the user on the console session.
' The gina on console session calls WlxQueryConsoleSwitchCredentials to get
' this info from winlogon and logs on the user.
'
' The caller is responsible for freeing the memory
' and substrings with LocalFree().
'


%WLX_CONSOLESWITCHCREDENTIAL_TYPE_V1_0 = 1

TYPE WLX_CONSOLESWITCH_CREDENTIALS_INFO_V1_0

    ' This field identifies the type of credentials structure being allocated
    ' Credential types are defined with the prefix
    ' WLX_CONSOLESWITCHCREDENTIAL_TYPE_xxx.  It allows Winlogon to typecast the
    ' structure so the remainder of the structure may be referenced.

    dwType         AS DWORD

    UserToken      AS DWORD
    LogonId        AS QUAD  ' LUID
    Quotas         AS QUOTA_LIMITS
    UserName       AS WSTRINGZ PTR
    Domain         AS WSTRINGZ PTR
    LogonTime      AS QUAD
    SmartCardLogon AS LONG
    ProfileLength  AS DWORD

    ' From MSV1_0_INTERACTIVE_PROFILE

    MessageType        AS DWORD
    LogonCount         AS WORD
    BadPasswordCount   AS WORD
    ProfileLogonTime   AS QUAD
    LogoffTime         AS QUAD
    KickOffTime        AS QUAD
    PasswordLastSet    AS QUAD
    PasswordCanChange  AS QUAD
    PasswordMustChange AS QUAD
    LogonScript        AS WSTRINGZ PTR
    HomeDirectory      AS WSTRINGZ PTR
    FullName           AS WSTRINGZ PTR
    ProfilePath        AS WSTRINGZ PTR
    HomeDirectoryDrive AS WSTRINGZ PTR
    LogonServer        AS WSTRINGZ PTR
    UserFlags          AS DWORD
    PrivateDataLen     AS DWORD
    PrivateData        AS BYTE PTR

END TYPE


''''''''''''''''''''''''''''''''''''
'
'  Services that replacement GINAs   ** MUST ** provide
'
''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION WlxNegotiate ALIAS "WlxNegotiate" ( _
    BYVAL dwWinlogonVersion AS DWORD, _
    pdwDllVersion AS DWORD) AS LONG

DECLARE FUNCTION WlxInitialize ALIAS "WlxInitialize" ( _
    lpWinsta AS WSTRINGZ, _
    BYVAL hWlx AS DWORD, _
    BYVAL pvReserved AS DWORD, _
    BYVAL pWinlogonFunctions AS DWORD, _
    pWlxContext AS DWORD) AS LONG

DECLARE SUB WlxDisplaySASNotice ALIAS "WlxDisplaySASNotice" ( _
    BYVAL pWlxContext AS DWORD)

DECLARE FUNCTION WlxLoggedOutSAS ALIAS "WlxLoggedOutSAS" ( _
    BYVAL pWlxContext AS DWORD,_
    BYVAL dwSasType AS DWORD, _
    pAuthenticationId AS QUAD, _  ' LUID, _
    pLogonSid AS SID, _
    pdwOptions AS DWORD, _
    phToken AS DWORD, _
    pNprNotifyInfo AS WLX_MPR_NOTIFY_INFO, _
    pProfile AS DWORD) AS LONG

DECLARE FUNCTION WlxActivateUserShell ALIAS "WlxActivateUserShell" ( _
    BYVAL pWlxContext AS DWORD, _
    pszDesktopName AS WSTRINGZ, _
    pszMprLogonScript AS WSTRINGZ, _
    BYVAL pEnvironment AS DWORD) AS LONG

DECLARE FUNCTION WlxLoggedOnSAS ALIAS "WlxLoggedOnSAS" ( _
    BYVAL pWlxContext AS DWORD, _
    BYVAL dwSasType AS DWORD, _
    BYVAL pReserved AS DWORD) AS LONG

DECLARE SUB WlxDisplayLockedNotice ALIAS "WlxDisplayLockedNotice" ( _
    BYVAL pWlxContext AS DWORD)

DECLARE FUNCTION WlxWkstaLockedSAS ALIAS "WlxWkstaLockedSAS" ( _
    BYVAL pWlxContext AS DWORD, _
    BYVAL dwSasType AS DWORD) AS LONG

DECLARE FUNCTION WlxIsLockOk ALIAS "WlxIsLockOk" ( _
    BYVAL pWlxContext AS DWORD) AS LONG

DECLARE FUNCTION WlxIsLogoffOk ALIAS "WlxIsLogoffOk" ( _
    BYVAL pWlxContext AS DWORD) AS LONG

DECLARE SUB WlxLogoff ALIAS "WlxLogoff" ( _
    BYVAL pWlxContext AS DWORD)

DECLARE SUB WlxShutdown ALIAS "WlxShutdown" ( _
    BYVAL pWlxContext AS DWORD, _
    BYVAL ShutdownType AS DWORD)


'
' NEW for version 1.1
'
DECLARE FUNCTION WlxScreenSaverNotify ALIAS "WlxScreenSaverNotify" ( _
    BYVAL pWlxContext AS DWORD, _
    pSecure AS LONG) AS LONG

DECLARE FUNCTION WlxStartApplication ALIAS "WlxStartApplication" ( _
    BYVAL pWlxContext AS DWORD, _
    pszDesktopName AS WSTRINGZ, _
    BYVAL pEnvironment AS DWORD, _
    pszCmdLine AS WSTRINGZ _
    ) AS LONG

'
' New for 1.3
'

DECLARE FUNCTION WlxNetworkProviderLoad ALIAS "WlxNetworkProviderLoad" ( _
    BYVAL pWlxContext AS DWORD, _
    pNprNotifyInfo AS WLX_MPR_NOTIFY_INFO) AS LONG

%STATUSMSG_OPTION_NOANIMATION   = &H00000001
%STATUSMSG_OPTION_SETFOREGROUND = &H00000002

DECLARE FUNCTION WlxDisplayStatusMessage ALIAS "WlxDisplayStatusMessage" ( _
    BYVAL pWlxContext AS DWORD, _
    BYVAL hDesktop AS DWORD, _
    BYVAL dwOptions AS DWORD, _
    pTitle AS WSTRINGZ, _
    pMessage AS WSTRINGZ _
    ) AS LONG

DECLARE FUNCTION WlxGetStatusMessage ALIAS "WlxGetStatusMessage" ( _
    BYVAL pWlxContext AS DWORD, _
    pdwOptions AS DWORD, _
    pMessage AS WSTRINGZ, _
    BYVAL dwBufferSize AS DWORD) AS LONG

DECLARE FUNCTION WlxRemoveStatusMessage ALIAS "WlxRemoveStatusMessage" ( _
    BYVAL pWlxContext AS DWORD) AS LONG

'
' New for 1.4
'
DECLARE FUNCTION WlxGetConsoleSwitchCredentials _
    ALIAS "WlxGetConsoleSwitchCredentials" ( _
    BYVAL pWlxContext AS DWORD, _
    BYVAL pCredInfo AS DWORD) AS LONG

DECLARE SUB WlxReconnectNotify ALIAS "WlxReconnectNotify" ( _
    BYVAL pWlxContext AS DWORD)

DECLARE SUB WlxDisconnectNotify ALIAS "WlxDisconnectNotify" ( _
    BYVAL pWlxContext AS DWORD)


''''''''''''''''''''''''''''''''''''
'
'  Services that Winlogon provides
'
''''''''''''''''''''''''''''''''''''

TYPE WLX_DESKTOP
    Size           AS DWORD
    Flags          AS DWORD
    hDesktop       AS DWORD
    pszDesktopName AS WSTRINGZ PTR
END TYPE

%WLX_DESKTOP_NAME   = &H00000001    ' Name present
%WLX_DESKTOP_HANDLE = &H00000002    ' Handle present

DECLARE SUB PWLX_USE_CTRL_ALT_DEL (BYVAL hWlx AS DWORD)

DECLARE SUB PWLX_SET_CONTEXT_POINTER (BYVAL hWlx AS DWORD, pWlxContent AS ANY)

DECLARE SUB PWLX_SAS_NOTIFY (BYVAL hWlx AS DWORD, BYVAL dwSasType AS DWORD)

DECLARE SUB PWLX_SET_TIMEOUT (BYVAL hWlx AS DWORD, BYVAL TIMEOUT AS DWORD)

DECLARE FUNCTION PWLX_ASSIGN_SHELL_PROTECTION (BYVAL hWlx AS DWORD, _
    BYVAL hToken AS DWORD, BYVAL hProcess AS DWORD, BYVAL hThread AS DWORD) _
    AS LONG

DECLARE FUNCTION PWLX_MESSAGE_BOX (BYVAL hWlx AS DWORD, _
    BYVAL hwndOwner AS DWORD, lpszText AS WSTRINGZ, lpszTitle AS WSTRINGZ, _
    BYVAL fuStyle AS DWORD) AS LONG

DECLARE FUNCTION PWLX_DIALOG_BOX (BYVAL hWlx AS DWORD, _
    BYVAL hInst AS DWORD, lpszTemplate AS WSTRINGZ, BYVAL hwndOwner AS DWORD, _
    BYVAL dlgprc AS DWORD) AS LONG

DECLARE FUNCTION PWLX_DIALOG_BOX_INDIRECT (BYVAL hWlx AS DWORD, _
    BYVAL hInst AS DWORD, BYVAL hDialogTemplate AS DWORD, _
    BYVAL hwndOwner AS DWORD, BYVAL dlgprc AS DWORD) AS LONG

DECLARE FUNCTION PWLX_DIALOG_BOX_PARAM (BYVAL hWlx AS DWORD, _
    BYVAL hInst AS DWORD, lpszTemplate AS WSTRINGZ, BYVAL hwndOwner AS DWORD, _
    BYVAL dlgprc AS DWORD, BYVAL dwInitParam AS LONG) AS LONG

DECLARE FUNCTION PWLX_DIALOG_BOX_INDIRECT_PARAM (BYVAL hWlx AS DWORD, _
    BYVAL hInst AS DWORD, BYVAL hDialogTemplate AS DWORD, _
    BYVAL hwndOwner AS DWORD, BYVAL dlgprc AS DWORD, _
    BYVAL dwInitParam AS LONG) AS LONG

DECLARE FUNCTION PWLX_SWITCH_DESKTOP_TO_USER (BYVAL hWlx AS DWORD) AS LONG

DECLARE FUNCTION PWLX_SWITCH_DESKTOP_TO_WINLOGON (BYVAL hWlx AS DWORD) AS LONG

DECLARE FUNCTION PWLX_CHANGE_PASSWORD_NOTIFY (BYVAL hWlx AS DWORD, _
    pMprInfo AS WLX_MPR_NOTIFY_INFO, BYVAL dwChangeInfo AS DWORD) AS LONG

DECLARE FUNCTION PWLX_GET_SOURCE_DESKTOP (BYVAL hWlx AS DWORD, _
    ppDeskTop AS ANY) AS LONG

DECLARE FUNCTION PWLX_SET_RETURN_DESKTOP (BYVAL hWlx AS DWORD, _
    pDesktop AS WLX_DESKTOP) AS LONG

DECLARE FUNCTION PWLX_CREATE_USER_DESKTOP (BYVAL hWlx AS DWORD, _
    BYVAL hToken AS DWORD, BYVAL Flags AS DWORD, pszDesktopName AS WSTRINGZ, _
    ppDesktop AS ANY) AS LONG

%WLX_CREATE_INSTANCE_ONLY = &H00000001
%WLX_CREATE_USER          = &H00000002

DECLARE FUNCTION PWLX_CHANGE_PASSWORD_NOTIFY_EX (BYVAL hWlx AS DWORD, _
    pMprInfo AS WLX_MPR_NOTIFY_INFO, BYVAL dwChangeInfo AS DWORD, _
    ProviderName AS WSTRINGZ, Reserved AS ANY) AS LONG

DECLARE FUNCTION PWLX_CLOSE_USER_DESKTOP (BYVAL hWlx AS DWORD, _
    pDesktop AS WLX_DESKTOP, BYVAL hToken AS DWORD) AS LONG

DECLARE FUNCTION PWLX_SET_OPTION (BYVAL hWlx AS DWORD, _
    BYVAL dOption AS DWORD, BYVAL Value AS DWORD, OldValue AS DWORD) AS LONG

DECLARE FUNCTION PWLX_GET_OPTION (BYVAL hWlx AS DWORD, _
    BYVAL dOption AS DWORD, Value AS DWORD) AS LONG

DECLARE SUB PWLX_WIN31_MIGRATE (BYVAL hWlx AS DWORD)

DECLARE FUNCTION PWLX_QUERY_CLIENT_CREDENTIALS _
    (pCred AS WLX_CLIENT_CREDENTIALS_INFO_V1_0) AS LONG

DECLARE FUNCTION PWLX_QUERY_IC_CREDENTIALS _
    (pCred AS WLX_CLIENT_CREDENTIALS_INFO_V1_0) AS LONG

DECLARE FUNCTION PWLX_QUERY_TS_LOGON_CREDENTIALS _
    (pCred AS WLX_CLIENT_CREDENTIALS_INFO_V2_0) AS LONG


DECLARE FUNCTION PWLX_DISCONNECT () AS LONG

DECLARE FUNCTION PWLX_QUERY_TERMINAL_SERVICES_DATA (BYVAL hWlx AS DWORD, _
    pTSData AS WLX_TERMINAL_SERVICES_DATA, UserName AS WSTRINGZ, _
    Domain AS WSTRINGZ) AS DWORD

DECLARE FUNCTION PWLX_QUERY_CONSOLESWITCH_CREDENTIALS _
    (pCred AS WLX_CONSOLESWITCH_CREDENTIALS_INFO_V1_0) AS DWORD


'
' Options that can be get or set:
'

%WLX_OPTION_USE_CTRL_ALT_DEL     = &H00000001
%WLX_OPTION_CONTEXT_POINTER      = &H00000002
%WLX_OPTION_USE_SMART_CARD       = &H00000003
%WLX_OPTION_FORCE_LOGOFF_TIME    = &H00000004
%WLX_OPTION_IGNORE_AUTO_LOGON    = &H00000008
%WLX_OPTION_NO_SWITCH_ON_SAS     = &H00000009

'
' Options that can be queried only:
'

%WLX_OPTION_SMART_CARD_PRESENT   = &H00010001
%WLX_OPTION_SMART_CARD_INFO      = &H00010002
%WLX_OPTION_DISPATCH_TABLE_SIZE  = &H00010003



''''''''''''''''''''''''''''''''''''
'
'  Function dispatch tables.
'  One of the following tables will be passed to the GINA DLL
'  in the WlxInitialize() call during initialization.
'
''''''''''''''''''''''''''''''''''''

TYPE WLX_DISPATCH_VERSION_1_0
    WlxUseCtrlAltDel           AS DWORD  ' codeptr
    WlxSetContextPointer       AS DWORD  ' codeptr
    WlxSasNotify               AS DWORD  ' codeptr
    WlxSetTimeout              AS DWORD  ' codeptr
    WlxAssignShellProtection   AS DWORD  ' codeptr
    WlxMessageBox              AS DWORD  ' codeptr
    WlxDialogBox               AS DWORD  ' codeptr
    WlxDialogBoxParam          AS DWORD  ' codeptr
    WlxDialogBoxIndirect       AS DWORD  ' codeptr
    WlxDialogBoxIndirectParam  AS DWORD  ' codeptr
    WlxSwitchDesktopToUser     AS DWORD  ' codeptr
    WlxSwitchDesktopToWinlogon AS DWORD  ' codeptr
    WlxChangePasswordNotify    AS DWORD  ' codeptr
END TYPE

TYPE WLX_DISPATCH_VERSION_1_1
    WlxUseCtrlAltDel           AS DWORD  ' codeptr
    WlxSetContextPointer       AS DWORD  ' codeptr
    WlxSasNotify               AS DWORD  ' codeptr
    WlxSetTimeout              AS DWORD  ' codeptr
    WlxAssignShellProtection   AS DWORD  ' codeptr
    WlxMessageBox              AS DWORD  ' codeptr
    WlxDialogBox               AS DWORD  ' codeptr
    WlxDialogBoxParam          AS DWORD  ' codeptr
    WlxDialogBoxIndirect       AS DWORD  ' codeptr
    WlxDialogBoxIndirectParam  AS DWORD  ' codeptr
    WlxSwitchDesktopToUser     AS DWORD  ' codeptr
    WlxSwitchDesktopToWinlogon AS DWORD  ' codeptr
    WlxChangePasswordNotify    AS DWORD  ' codeptr
    WlxGetSourceDesktop        AS DWORD  ' codeptr
    WlxSetReturnDesktop        AS DWORD  ' codeptr
    WlxCreateUserDesktop       AS DWORD  ' codeptr
    WlxChangePasswordNotifyEx  AS DWORD  ' codeptr
END TYPE

TYPE WLX_DISPATCH_VERSION_1_2
    WlxUseCtrlAltDel           AS DWORD  ' codeptr
    WlxSetContextPointer       AS DWORD  ' codeptr
    WlxSasNotify               AS DWORD  ' codeptr
    WlxSetTimeout              AS DWORD  ' codeptr
    WlxAssignShellProtection   AS DWORD  ' codeptr
    WlxMessageBox              AS DWORD  ' codeptr
    WlxDialogBox               AS DWORD  ' codeptr
    WlxDialogBoxParam          AS DWORD  ' codeptr
    WlxDialogBoxIndirect       AS DWORD  ' codeptr
    WlxDialogBoxIndirectParam  AS DWORD  ' codeptr
    WlxSwitchDesktopToUser     AS DWORD  ' codeptr
    WlxSwitchDesktopToWinlogon AS DWORD  ' codeptr
    WlxChangePasswordNotify    AS DWORD  ' codeptr
    WlxGetSourceDesktop        AS DWORD  ' codeptr
    WlxSetReturnDesktop        AS DWORD  ' codeptr
    WlxCreateUserDesktop       AS DWORD  ' codeptr
    WlxChangePasswordNotifyEx  AS DWORD  ' codeptr
    WlxCloseUserDesktop        AS DWORD  ' codeptr
END TYPE

TYPE WLX_DISPATCH_VERSION_1_3
    WlxUseCtrlAltDel                 AS DWORD  ' codeptr
    WlxSetContextPointer             AS DWORD  ' codeptr
    WlxSasNotify                     AS DWORD  ' codeptr
    WlxSetTimeout                    AS DWORD  ' codeptr
    WlxAssignShellProtection         AS DWORD  ' codeptr
    WlxMessageBox                    AS DWORD  ' codeptr
    WlxDialogBox                     AS DWORD  ' codeptr
    WlxDialogBoxParam                AS DWORD  ' codeptr
    WlxDialogBoxIndirect             AS DWORD  ' codeptr
    WlxDialogBoxIndirectParam        AS DWORD  ' codeptr
    WlxSwitchDesktopToUser           AS DWORD  ' codeptr
    WlxSwitchDesktopToWinlogon       AS DWORD  ' codeptr
    WlxChangePasswordNotify          AS DWORD  ' codeptr
    WlxGetSourceDesktop              AS DWORD  ' codeptr
    WlxSetReturnDesktop              AS DWORD  ' codeptr
    WlxCreateUserDesktop             AS DWORD  ' codeptr
    WlxChangePasswordNotifyEx        AS DWORD  ' codeptr
    WlxCloseUserDesktop              AS DWORD  ' codeptr
    WlxSetOption                     AS DWORD  ' codeptr
    WlxGetOption                     AS DWORD  ' codeptr
    WlxWin31Migrate                  AS DWORD  ' codeptr
    WlxQueryClientCredentials        AS DWORD  ' codeptr
    WlxQueryInetConnectorCredentials AS DWORD  ' codeptr
    WlxDisconnect                    AS DWORD  ' codeptr
    WlxQueryTerminalServicesData     AS DWORD  ' codeptr
END TYPE

TYPE WLX_DISPATCH_VERSION_1_4
    WlxUseCtrlAltDel                 AS DWORD  ' codeptr
    WlxSetContextPointer             AS DWORD  ' codeptr
    WlxSasNotify                     AS DWORD  ' codeptr
    WlxSetTimeout                    AS DWORD  ' codeptr
    WlxAssignShellProtection         AS DWORD  ' codeptr
    WlxMessageBox                    AS DWORD  ' codeptr
    WlxDialogBox                     AS DWORD  ' codeptr
    WlxDialogBoxParam                AS DWORD  ' codeptr
    WlxDialogBoxIndirect             AS DWORD  ' codeptr
    WlxDialogBoxIndirectParam        AS DWORD  ' codeptr
    WlxSwitchDesktopToUser           AS DWORD  ' codeptr
    WlxSwitchDesktopToWinlogon       AS DWORD  ' codeptr
    WlxChangePasswordNotify          AS DWORD  ' codeptr
    WlxGetSourceDesktop              AS DWORD  ' codeptr
    WlxSetReturnDesktop              AS DWORD  ' codeptr
    WlxCreateUserDesktop             AS DWORD  ' codeptr
    WlxChangePasswordNotifyEx        AS DWORD  ' codeptr
    WlxCloseUserDesktop              AS DWORD  ' codeptr
    WlxSetOption                     AS DWORD  ' codeptr
    WlxGetOption                     AS DWORD  ' codeptr
    WlxWin31Migrate                  AS DWORD  ' codeptr
    WlxQueryClientCredentials        AS DWORD  ' codeptr
    WlxQueryInetConnectorCredentials AS DWORD  ' codeptr
    WlxDisconnect                    AS DWORD  ' codeptr
    WlxQueryTerminalServicesData     AS DWORD  ' codeptr
    WlxQueryConsoleSwitchCredentials AS DWORD  ' codeptr
    WlxQueryTsLogonCredentials       AS DWORD  ' codeptr
END TYPE


'
' Non-GINA notification DLLs
'
DECLARE FUNCTION PFNMSGCALLBACK (BYVAL bVervose AS LONG, _
    lpMessage AS WSTRINGZ) AS DWORD

TYPE WLX_NOTIFICATION_INFO
    Size            AS DWORD
    Flags           AS DWORD
    UserName        AS WSTRINGZ PTR
    Domain          AS WSTRINGZ PTR
    WindowStation   AS WSTRINGZ PTR
    hToken          AS DWORD
    hDesktop        AS DWORD
    pStatusCallback AS DWORD  ' codeptr
END TYPE
