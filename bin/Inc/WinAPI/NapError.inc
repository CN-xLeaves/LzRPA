'------------------------------------------------------------------------------
'
'  NapError.inc -- Declares the NAP-specific HRESULTs.
'
'  Copyright (c) 2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 18 Feb 2011
'
'------------------------------------------------------------------------------
'  from NapError.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%NAPERROR_H = 1

%FACILITY_NAP = &H27


'
' MessageId: NAP_E_INVALID_PACKET
'
' MessageText:
'
'  The NAP SoH packet is invalid.
'
%NAP_E_INVALID_PACKET  = &H80270001


'
' MessageId: NAP_E_MISSING_SOH
'
' MessageText:
'
' An SoH was missing from the NAP packet.
'
%NAP_E_MISSING_SOH     = &H80270002


'
' MessageId: NAP_E_CONFLICTING_ID
'
' MessageText:
'
'  The entity ID conflicts with an already registered id.
'
%NAP_E_CONFLICTING_ID  = &H80270003


'
' MessageId: NAP_E_NO_CACHED_SOH
'
' MessageText:
'
'  No cached SoH is present.
'
%NAP_E_NO_CACHED_SOH    = &H80270004


'
' MessageId: NAP_E_STILL_BOUND
'
' MessageText:
'
'  The entity is still bound to the NAP system.
'
%NAP_E_STILL_BOUND      = &H80270005


'
' MessageId: NAP_E_NOT_REGISTERED
'
' MessageText:
'
'  The entity is not registered with the NAP system.
'
%NAP_E_NOT_REGISTERED   = &H80270006


'
' MessageId: NAP_E_NOT_INITIALIZED
'
' MessageText:
'
'  The entity is not initialized with the NAP system.
'
%NAP_E_NOT_INITIALIZED   = &H80270007


'
' MessageId: NAP_E_MISMATCHED_ID
'
' MessageText:
'
'  The correlation id in the SoH-Request and SoH-Response do not match up.
'
%NAP_E_MISMATCHED_ID   = &H80270008


'
' MessageId: NAP_E_NOT_PENDING
'
' MessageText:
'
'  Completion was indicated on a request that is not currently pending.
'
%NAP_E_NOT_PENDING    = &H80270009


'
' MessageId: NAP_E_ID_NOT_FOUND
'
' MessageText:
'
'  The NAP component's id was not found.
'
%NAP_E_ID_NOT_FOUND    = &H8027000A


'
' MessageId: NAP_E_MAXSIZE_TOO_SMALL
'
' MessageText:
'
'  The maximum size of the connection is too small for an SoH packet.
'
%NAP_E_MAXSIZE_TOO_SMALL    = &H8027000B


'
' MessageId: NAP_E_SERVICE_NOT_RUNNING
'
' MessageText:
'
'  The NapAgent service is not running.
'
%NAP_E_SERVICE_NOT_RUNNING    = &H8027000C


'
' MessageId: NAP_S_CERT_ALREADY_PRESENT
'
' MessageText:
'
'  A certificate is already present in the cert store
'
%NAP_S_CERT_ALREADY_PRESENT    = &H0027000D

'
' MessageId: NAP_E_ENTITY_DISABLED
'
' MessageText:
'
'  The entity is disabled with the NapAgent service.
'
%NAP_E_ENTITY_DISABLED    = &H8027000E

'
' MessageId: NAP_E_NETSH_GROUPPOLICY_ERROR
'
' MessageText:
'
'  Group Policy is not configured
'
%NAP_E_NETSH_GROUPPOLICY_ERROR    = &H8027000F

'
' MessageId: NAP_E_TOO_MANY_CALLS
'
' MessageText:
'
'  Too many simultaneous calls
'
%NAP_E_TOO_MANY_CALLS    = &H80270010

'
' MessageId: NAP_E_SHV_CONFIG_EXISTED
'
' MessageText:
'
' SHV configuration already existed
'
%NAP_E_SHV_CONFIG_EXISTED = &H80270011

'
' MessageId: NAP_E_SHV_CONFIG_NOT_FOUND
'
' MessageText:
'
' SHV configuration is not found
'
%NAP_E_SHV_CONFIG_NOT_FOUND = &H80270012

'
' MessageId: NAP_E_SHV_TIMEOUT
'
' MessageText:
'
' SHV timed out on the request
'
%NAP_E_SHV_TIMEOUT = &H80270013
