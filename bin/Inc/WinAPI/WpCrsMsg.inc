'------------------------------------------------------------------------------
'
'  WpCrsMsg.inc
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 18 Feb 2011
'
'------------------------------------------------------------------------------
'  from WpCrsMsg.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WpCrsMsg_inc = 1

'
'  Values are 32 bit values layed out as follows:
'
'   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
'   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'  +---+-+-+-----------------------+-------------------------------+
'  |Sev|C|R|     Facility          |               Code            |
'  +---+-+-+-----------------------+-------------------------------+
'
'  where
'
'      Sev - is the severity code
'
'          00 - Success
'          01 - Informational
'          10 - Warning
'          11 - Error
'
'      C - is the Customer code flag
'
'      R - is a reserved bit
'
'      Facility - is the facility code
'
'      Code - is the facility's status code
'
'
' Define the facility codes
'


'
' Define the severity codes
'


'
' MessageId: CRSWPP_ERROR_FIRST
'
' MessageText:
'
'  CRS WebPost provider's first error message.
'
%CRSWPP_ERROR_FIRST               = &H40042200

'
' MessageId: CRSWPP_INVALID_POSTINFO_FILE
'
' MessageText:
'
'  The PostInfo file is invalid on the server you selected.
'
%CRSWPP_INVALID_POSTINFO_FILE     = &HC0042201

'
' MessageId: CRSWPP_NO_MATCHING_MAPURL
'
' MessageText:
'
'  The CRS project you selected has no MAPURL.
'
%CRSWPP_NO_MATCHING_MAPURL        = &HC0042202

'
' MessageId: CRSWPP_SECURITY_PACKAGE
'
' MessageText:
'
'  The initialization of the security package failed.
'
%CRSWPP_SECURITY_PACKAGE          = &HC0042203

'
' MessageId: CRSWPP_SECURITY_PACKAGE_NOT_FOUND
'
' MessageText:
'
'  The security package(s) required by the server could not be found on your computer.
'
%CRSWPP_SECURITY_PACKAGE_NOT_FOUND = &HC0042204

'
' MessageId: CRSWPP_PROJECT_BINDING_INCOMPLETE
'
' MessageText:
'
'  The CRS provider has not determined which CRS project on the server corresponds to the URL you selected.
'
%CRSWPP_PROJECT_BINDING_INCOMPLETE = &HC0042205

'
' MessageId: CRSWPP_SERVER_BINDING_INCOMPLETE
'
' MessageText:
'
'  The CRS provider has not determined the name of the server that corresponds to the URL you selected.
'
%CRSWPP_SERVER_BINDING_INCOMPLETE = &HC0042206

'
' MessageId: CRSWPP_SERVER_NOT_RESPONDING
'
' MessageText:
'
'  The CRS server is not responding.
'
%CRSWPP_SERVER_NOT_RESPONDING     = &HC0042207

'
' MessageId: CRSWPP_FAILED_AUTH
'
' MessageText:
'
'  You do not have the necessary access privileges to publish to this CRS server.
'
%CRSWPP_FAILED_AUTH               = &HC0042208

'
' MessageId: CRSWPP_POSTINFO_NEEDED
'
' MessageText:
'
'  The CRS provider could not retrieve all of the required information from the PostInfo file on the server.
'
%CRSWPP_POSTINFO_NEEDED           = &H40042209

'
' MessageId: CRSWPP_BIND_FAILED
'
' MessageText:
'
'  The CRS provider could not connect to the CRS server.
'
%CRSWPP_BIND_FAILED               = &HC004220A
