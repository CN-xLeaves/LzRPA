'------------------------------------------------------------------------------
'
'  WpFtpMsg.inc
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 18 Feb 2011
'
'------------------------------------------------------------------------------
'  from WpFtpMsg.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WpFtpMsg_inc = 1

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
' MessageId: FTPWPP_ERROR_FIRST
'
' MessageText:
'
'  CFtpWpp's first error message.
'
%FTPWPP_ERROR_FIRST               = &H40042300

'
' MessageId: FTPWPP_ERROR_INETOPEN_FAILED
'
' MessageText:
'
'  The FTP provider could not connect to the internet.
'
%FTPWPP_ERROR_INETOPEN_FAILED     = &HC0042301

'
' MessageId: FTPWPP_ERROR_AUTHENTICATION_FAILED
'
' MessageText:
'
'  The FTP provider could not log in to the FTP server.
'
%FTPWPP_ERROR_AUTHENTICATION_FAILED = &HC0042302

'
' MessageId: FTPWPP_ERROR_LAST
'
' MessageText:
'
'  CFtpWpp's last error message.
'
%FTPWPP_ERROR_LAST                = &H400423FF
