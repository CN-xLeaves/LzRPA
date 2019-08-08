'------------------------------------------------------------------------------
'
'  WpWizMsg.inc
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 18 Feb 2011
'
'------------------------------------------------------------------------------
'  from WpWizMsg.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WpWizMsg_inc = 1

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
' MessageId: WPWIZ_ERROR_FIRST
'
' MessageText:
'
'  Web Publishing Wizard first error message.
'
%WPWIZ_ERROR_FIRST                = &H40042000

'
' MessageId: WPWIZ_ERROR_UNKNOWN
'
' MessageText:
'
'  An unknown error occurred in the Web Publishing Wizard.
'
%WPWIZ_ERROR_UNKNOWN              = &HC0042001

'
' MessageId: WPWIZ_ERROR_PROV_QI
'
' MessageText:
'
'  The Web Publishing Wizard was unable to determine the version number of your service provider.
'
%WPWIZ_ERROR_PROV_QI              = &HC0042002

'
' MessageId: WPWIZ_ERROR_INIT_FAILED
'
' MessageText:
'
'  An error occurred while attempting to start the Web Publishing Wizard.
'
%WPWIZ_ERROR_INIT_FAILED          = &HC0042003

'
' MessageId: WPWIZ_ERROR_COCREATE_WEBPOST
'
' MessageText:
'
'  The Web Publishing Wizard is not installed correctly. Please uninstall and then reinstall the wizard.
'
%WPWIZ_ERROR_COCREATE_WEBPOST     = &HC0042004

'
' MessageId: WPWIZ_ERROR_NO_PROVIDERS
'
' MessageText:
'
'  The Web Publishing Wizard could not run because there are no service providers installed.
'
%WPWIZ_ERROR_NO_PROVIDERS         = &HC0042005

'
' MessageId: WPWIZ_ERROR_STATE_PTR
'
' MessageText:
'
'  An internal error (= &H2006) occurred in the Web Publishing Wizard.
'
%WPWIZ_ERROR_STATE_PTR            = &HC0042006

'
' MessageId: WPWIZ_ERROR_WEBPOST_PTR
'
' MessageText:
'
'  An internal error (= &H2007) occurred in the Web Publishing Wizard.
'
%WPWIZ_ERROR_WEBPOST_PTR          = &HC0042007

'
' MessageId: WPWIZ_ERROR_FILE_NOT_FOUND
'
' MessageText:
'
'  The file(s) you selected to publish could not be found.
'
%WPWIZ_ERROR_FILE_NOT_FOUND       = &HC0042008

'
' MessageId: WPWIZ_ERROR_PROPSHEET_ERROR
'
' MessageText:
'
'  An error occurred in the user interface of the Web Publishing Wizard.
'
%WPWIZ_ERROR_PROPSHEET_ERROR      = &HC0042009

'
' MessageId: WPWIZ_ERROR_OUTOFMEMORY
'
' MessageText:
'
'  The Web Publishing Wizard has run out of memory. Please close other running applications before continuing.
'
%WPWIZ_ERROR_OUTOFMEMORY          = &HC004200A

'
' MessageId: WPWIZ_ERROR_LAST
'
' MessageText:
'
'  Web Publishing Wizard last error message.
'
%WPWIZ_ERROR_LAST                 = &H400420FF
