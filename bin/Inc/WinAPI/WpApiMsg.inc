'------------------------------------------------------------------------------
'
'  WpApiMsg.inc
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 18 Feb 2011
'
'------------------------------------------------------------------------------
'  from WpApiMsg.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WpApiMsg_inc = 1

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
' MessageId: WEBPOST_ERROR_FIRST
'
' MessageText:
'
'  Web Publishing Wizard first error message.
'
%WEBPOST_ERROR_FIRST              = &H40042100

'
' MessageId: WEBPOST_ERROR_UNKNOWN
'
' MessageText:
'
'  An unknown error occurred in the Web Publishing Wizard.
'
%WEBPOST_ERROR_UNKNOWN            = &HC0042101

'
' MessageId: WEBPOST_ERROR_PROVCLSID_UNKNOWN
'
' MessageText:
'
'  The Web Publishing Wizard could not locate the service provider used to transfer files to your Web server.
'
%WEBPOST_ERROR_PROVCLSID_UNKNOWN  = &HC0042102

'
' MessageId: WEBPOST_ERROR_SITE_CORRUPT
'
' MessageText:
'
'  The Web Publishing Wizard could not retrieve all of the required information about your Web server.
'
%WEBPOST_ERROR_SITE_CORRUPT       = &HC0042103

'
' MessageId: WEBPOST_ERROR_PROV_CORRUPT
'
' MessageText:
'
'  The Web Publishing Wizard could not retrieve all of the required information about this service provider.
'
%WEBPOST_ERROR_PROV_CORRUPT       = &HC0042104

'
' MessageId: WEBPOST_ERROR_PROV_DLL
'
' MessageText:
'
'  The Web Publishing Wizard could not locate the file(s) for the requested service provider.
'
%WEBPOST_ERROR_PROV_DLL           = &HC0042105

'
' MessageId: WEBPOST_ERROR_PROV_EP
'
' MessageText:
'
'  The file(s) for the requested service provider are either corrupt or outdated.
'
%WEBPOST_ERROR_PROV_EP            = &HC0042106

'
' MessageId: WEBPOST_ERROR_INIT_FAILED
'
' MessageText:
'
'  An error occurred while attempting to start the Web Publishing Wizard.
'
%WEBPOST_ERROR_INIT_FAILED        = &HC0042107

'
' MessageId: WEBPOST_ERROR_LIST_SITES
'
' MessageText:
'
'  An error occurred while the Web Publishing Wizard was enumerating the Web servers to which you have previously published.
'
%WEBPOST_ERROR_LIST_SITES         = &HC0042108

'
' MessageId: WEBPOST_ERROR_SITE_EXISTS
'
' MessageText:
'
'  The Web Publishing Wizard could not use the requested descriptive name for your Web server because another Web server already uses the name.
'
%WEBPOST_ERROR_SITE_EXISTS        = &HC0042109

'
' MessageId: WEBPOST_ERROR_CREATE_SITE
'
' MessageText:
'
'  An error occurred while the Web Publishing Wizard was saving information about your Web server.
'
%WEBPOST_ERROR_CREATE_SITE        = &HC004210A

'
' MessageId: WEBPOST_ERROR_SITE_DOESNOTEXIST
'
' MessageText:
'
'  Your computer does not contain any information about the Web server you have selected.
'
%WEBPOST_ERROR_SITE_DOESNOTEXIST  = &HC004210B

'
' MessageId: WEBPOST_ERROR_DELETE_SITE
'
' MessageText:
'
'  An error occurred while the Web Publishing Wizard was deleting information about your Web server.
'
%WEBPOST_ERROR_DELETE_SITE        = &HC004210C

'
' MessageId: WEBPOST_ERROR_ENUM_PROVS
'
' MessageText:
'
'  An error occurred while the Web Publishing Wizard was enumerating the service providers on this system.
'
%WEBPOST_ERROR_ENUM_PROVS         = &HC004210D

'
' MessageId: WEBPOST_ERROR_PROV_QI
'
' MessageText:
'
'  The Web Publishing Wizard was unable to determine the version number of your service provider.
'
%WEBPOST_ERROR_PROV_QI            = &HC004210E

'
' MessageId: WEBPOST_ERROR_POST_FILES
'
' MessageText:
'
'  An error occurred while the Web Publishing Wizard was attempting to publish your files.
'
%WEBPOST_ERROR_POST_FILES         = &HC004210F

'
' MessageId: WEBPOST_ERROR_COCREATE_WIZARD
'
' MessageText:
'
'  The Web Publishing Wizard is not installed correctly. Please uninstall and then reinstall the wizard.
'
%WEBPOST_ERROR_COCREATE_WIZARD    = &HC0042110

'
' MessageId: WEBPOST_ERROR_POSTINFO_REQUIRED
'
' MessageText:
'
'  Your service provider requires that a PostInfo file be located on the server. No PostInfo file could be located.
'
%WEBPOST_ERROR_POSTINFO_REQUIRED  = &HC0042111

'
' MessageId: WEBPOST_ERROR_AUTOBIND_FAILED
'
' MessageText:
'
'  The service provider could not be automatically selected for your Web server.
'
%WEBPOST_ERROR_AUTOBIND_FAILED    = &HC0042112

'
' MessageId: WEBPOST_ERROR_BAD_PROV_PTR
'
' MessageText:
'
'  The Web Publishing Wizard was not able to obtain a valid pointer to the requested service provider.
'
%WEBPOST_ERROR_BAD_PROV_PTR       = &HC0042113

'
' MessageId: WEBPOST_ERROR_PROV_NOT_IN_POSTINFO
'
' MessageText:
'
'  The Web server you selected does not indicate support for the service provider you selected.
'
%WEBPOST_ERROR_PROV_NOT_IN_POSTINFO = &H80042114

'
' MessageId: WEBPOST_ERROR_EXTENDED_ERROR
'
' MessageText:
'
'  Web Publishing Wizard extended error.
'
%WEBPOST_ERROR_EXTENDED_ERROR     = &HC0042116

'
' MessageId: WEBPOST_ERROR_NO_EXT_ERR_INFO
'
' MessageText:
'
'  An extended error occurred in the Web Publishing Wizard, but the error message could not be retrieved.
'
%WEBPOST_ERROR_NO_EXT_ERR_INFO    = &HC0042117

'
' MessageId: WEBPOST_ERROR_INVALID_POSTINFO
'
' MessageText:
'
'  The PostInfo file on the server is invalid.
'
%WEBPOST_ERROR_INVALID_POSTINFO   = &H40042118

'
' MessageId: WEBPOST_ERROR_NO_POSTINFO
'
' MessageText:
'
'  There is no PostInfo file on the server.
'
%WEBPOST_ERROR_NO_POSTINFO        = &H40042119

'
' MessageId: WEBPOST_ERROR_HTTP_GET_FAILED
'
' MessageText:
'
'  The Web Publishing Wizard was not able to retrieve the first file published using an HTTP connection.
'
%WEBPOST_ERROR_HTTP_GET_FAILED    = &H4004211A

'
' MessageId: WEBPOST_ERROR_LAST
'
' MessageText:
'
'  Web Publishing Wizard last error message.
'
%WEBPOST_ERROR_LAST               = &H400421FF
