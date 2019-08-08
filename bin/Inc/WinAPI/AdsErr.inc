'------------------------------------------------------------------------------
'
'  AdsErr.inc -- Error codes for ADs
'
'  Copyright (c) 2011 PowerBASIC, Inc.
'  Portions Copyright (c) 1991-1999 Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 18 Feb 2011
'
'------------------------------------------------------------------------------
'  from AdsErr.h build version 0001 of 14 Jul 2009
'  "module name oledserr.mc"
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

'
'  Values are 32 bit values laid out as follows:
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
%FACILITY_WINDOWS   = 8
%FACILITY_STORAGE   = 3
%FACILITY_RPC       = 1
%FACILITY_SSPI      = 9
%FACILITY_WIN32     = 7
%FACILITY_CONTROL   = 10
%FACILITY_NULL      = 0
%FACILITY_ITF       = 4
%FACILITY_DISPATCH  = 2


'
' Define the severity codes
'


'
' MessageId: E_ADS_BAD_PATHNAME
'
' MessageText:
'
'  An invalid directory pathname was passed
'
%E_ADS_BAD_PATHNAME               = &H80005000&

'
' MessageId: E_ADS_INVALID_DOMAIN_OBJECT
'
' MessageText:
'
'  An unknown directory domain object was requested
'
%E_ADS_INVALID_DOMAIN_OBJECT      = &H80005001&

'
' MessageId: E_ADS_INVALID_USER_OBJECT
'
' MessageText:
'
'  An unknown directory user object was requested
'
%E_ADS_INVALID_USER_OBJECT        = &H80005002&

'
' MessageId: E_ADS_INVALID_COMPUTER_OBJECT
'
' MessageText:
'
'  An unknown directory computer object was requested
'
%E_ADS_INVALID_COMPUTER_OBJECT    = &H80005003&

'
' MessageId: E_ADS_UNKNOWN_OBJECT
'
' MessageText:
'
'  An unknown directory object was requested
'
%E_ADS_UNKNOWN_OBJECT             = &H80005004&

'
' MessageId: E_ADS_PROPERTY_NOT_SET
'
' MessageText:
'
'  The specified directory property was not set
'
%E_ADS_PROPERTY_NOT_SET           = &H80005005&

'
' MessageId: E_ADS_PROPERTY_NOT_SUPPORTED
'
' MessageText:
'
'  The specified directory property is not supported
'
%E_ADS_PROPERTY_NOT_SUPPORTED     = &H80005006&

'
' MessageId: E_ADS_PROPERTY_INVALID
'
' MessageText:
'
'  The specified directory property is invalid
'
%E_ADS_PROPERTY_INVALID           = &H80005007&

'
' MessageId: E_ADS_BAD_PARAMETER
'
' MessageText:
'
'  One or more input parameters are invalid
'
%E_ADS_BAD_PARAMETER              = &H80005008&

'
' MessageId: E_ADS_OBJECT_UNBOUND
'
' MessageText:
'
'  The specified directory object is not bound to a remote resource
'
%E_ADS_OBJECT_UNBOUND             = &H80005009&

'
' MessageId: E_ADS_PROPERTY_NOT_MODIFIED
'
' MessageText:
'
'  The specified directory object has not been modified
'
%E_ADS_PROPERTY_NOT_MODIFIED      = &H8000500A&

'
' MessageId: E_ADS_PROPERTY_MODIFIED
'
' MessageText:
'
'  The specified directory object has been modified
'
%E_ADS_PROPERTY_MODIFIED          = &H8000500B&

'
' MessageId: E_ADS_CANT_CONVERT_DATATYPE
'
' MessageText:
'
'  The directory datatype cannot be converted to/from a native DS datatype
'
%E_ADS_CANT_CONVERT_DATATYPE      = &H8000500C&

'
' MessageId: E_ADS_PROPERTY_NOT_FOUND
'
' MessageText:
'
'  The directory property cannot be found in the cache.
'
%E_ADS_PROPERTY_NOT_FOUND         = &H8000500D&

'
' MessageId: E_ADS_OBJECT_EXISTS
'
' MessageText:
'
'  The directory object exists.
'
%E_ADS_OBJECT_EXISTS              = &H8000500E&

'
' MessageId: E_ADS_SCHEMA_VIOLATION
'
' MessageText:
'
'  The attempted action violates the DS schema rules.
'
%E_ADS_SCHEMA_VIOLATION           = &H8000500F&

'
' MessageId: E_ADS_COLUMN_NOT_SET
'
' MessageText:
'
'  The specified column in the directory was not set.
'
%E_ADS_COLUMN_NOT_SET             = &H80005010&

'
' MessageId: S_ADS_ERRORSOCCURRED
'
' MessageText:
'
'  One or more errors occurred
'
%S_ADS_ERRORSOCCURRED             = &H00005011&

'
' MessageId: S_ADS_NOMORE_ROWS
'
' MessageText:
'
'  No more rows to be obatained by the search result.
'
%S_ADS_NOMORE_ROWS                = &H00005012&

'
' MessageId: S_ADS_NOMORE_COLUMNS
'
' MessageText:
'
'  No more columns to be obatained for the current row.
'
%S_ADS_NOMORE_COLUMNS             = &H00005013&

'
' MessageId: E_ADS_INVALID_FILTER
'
' MessageText:
'
'  The search filter specified is invalid
'
%E_ADS_INVALID_FILTER             = &H80005014&
