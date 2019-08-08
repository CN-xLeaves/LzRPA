'------------------------------------------------------------------------------
'
'  CdoSysErr.inc -- CDO message file
'
'  Copyright (c) 2011 PowerBASIC, Inc.
'  Portions Copyright (c) 1991-1999 Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 18 Feb 2011
'
'------------------------------------------------------------------------------
'  from CDOSysErr.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

' IMPORTANT:
' if you add a new string do it at the end of the existing strings for the
' given section (cdosys, cdosvr or cdoex)
' see x5:191917 for more details
'
' Message categories
'
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


'
' Define the severity codes
'


'
' MessageId: categoryHeader
'
' MessageText:
'
' Header
'
%categoryHeader                   = &H00000001

'
' MessageId: categoryUnused
'
' MessageText:
'
' None
'
%categoryUnused                   = &H00000002

'
' MessageId: categoryGeneral
'
' MessageText:
'
' General
'
%categoryGeneral                  = &H00000003

'----------------------------------------------------------------------------
' Error code ranges in FACILITY_ITF.
' Different libraries sharing the CDO name
' should not conflict in their error codes. Note that below = &H200 is
' reserved by COM.
'  &H200 through &H5ff    - CDOEX and CDOSYS error codes
' &H600 through &H6ff    - workflow error codes
'  &H1000 through &H1100
'  &H4000 through &H4100
'
'----------------------------------------------------------------------------
' MessageId Ranges used by the localizer
'
' 1: &H200 through &H7ff, &H4000 through &H4fff: Library error messages, not localized.
' 2: &H2000 through &H2fff: Server error messages, localized in server languages.
' 3: &H1000 through &H1fff: Client text, localized in client languages.
'
'----------------------------------------------------------------------------
' Error strings for IErrorInfo
'
' MessageId = &H200 through &H7ff or &H4000 through &H4fff. Not localized.
'
' = &H200 available - was CDO_E_FAIL
'
' MessageId: CDO_E_UNCAUGHT_EXCEPTION
'
' MessageText:
'
' Exception %1 was generated at address %2
'
%CDO_E_UNCAUGHT_EXCEPTION         = &H80040201

' &H202 was CDO_E_NOT_BOUND, was renamed
'
' MessageId: CDO_E_NOT_OPENED
'
' MessageText:
'
' No data source has been opened for the object.
'
%CDO_E_NOT_OPENED                 = &H80040202

'
' MessageId: CDO_E_UNSUPPORTED_DATASOURCE
'
' MessageText:
'
' The object does not support this type of data source.
'
%CDO_E_UNSUPPORTED_DATASOURCE     = &H80040203

'
' MessageId: CDO_E_INVALID_PROPERTYNAME
'
' MessageText:
'
' The object does not support the requested property name or namespace.
'
%CDO_E_INVALID_PROPERTYNAME       = &H80040204

'
' MessageId: CDO_E_PROP_UNSUPPORTED
'
' MessageText:
'
' The object does not support the requested property.
'
%CDO_E_PROP_UNSUPPORTED           = &H80040205

' &H206 - was CDO_E_NOT_INITIALIZED
'
' MessageId: CDO_E_INACTIVE
'
' MessageText:
'
' The object is not active. It may have been deleted or it may not have been opened.
'
%CDO_E_INACTIVE                   = &H80040206

'
' MessageId: CDO_E_NO_SUPPORT_FOR_OBJECTS
'
' MessageText:
'
' The object does not support storing persistent state information for objects.
'
%CDO_E_NO_SUPPORT_FOR_OBJECTS     = &H80040207

'
' MessageId: CDO_E_NOT_AVAILABLE
'
' MessageText:
'
' The requested property or feature, while supported, is not available at this time or in this context.
'
%CDO_E_NOT_AVAILABLE              = &H80040208

'
' MessageId: CDO_E_NO_DEFAULT_DROP_DIR
'
' MessageText:
'
' No default drop directory has been configured for this server.
'
%CDO_E_NO_DEFAULT_DROP_DIR        = &H80040209

'
' MessageId: CDO_E_SMTP_SERVER_REQUIRED
'
' MessageText:
'
' The SMTP server name is required, and was not found in the configuration source.
'
%CDO_E_SMTP_SERVER_REQUIRED       = &H8004020A

'
' MessageId: CDO_E_NNTP_SERVER_REQUIRED
'
' MessageText:
'
' The NNTP server name is required, and was not found in the configuration source.
'
%CDO_E_NNTP_SERVER_REQUIRED       = &H8004020B

'
' MessageId: CDO_E_RECIPIENT_MISSING
'
' MessageText:
'
' At least one recipient is required, but none were found.
'
%CDO_E_RECIPIENT_MISSING          = &H8004020C

'
' MessageId: CDO_E_FROM_MISSING
'
' MessageText:
'
' At least one of the From or Sender fields is required, and neither was found.
'
%CDO_E_FROM_MISSING               = &H8004020D

'
' MessageId: CDO_E_SENDER_REJECTED
'
' MessageText:
'
' The server rejected the sender address. The server response was: %1
'
%CDO_E_SENDER_REJECTED            = &H8004020E

'
' MessageId: CDO_E_RECIPIENTS_REJECTED
'
' MessageText:
'
' The server rejected one or more recipient addresses. The server response was: %1
'
%CDO_E_RECIPIENTS_REJECTED        = &H8004020F

'
' MessageId: CDO_E_NNTP_POST_FAILED
'
' MessageText:
'
' The message could not be posted to the NNTP server. The transport error code was %2. The server response was %1
'
%CDO_E_NNTP_POST_FAILED           = &H80040210

'
' MessageId: CDO_E_SMTP_SEND_FAILED
'
' MessageText:
'
' The message could not be sent to the SMTP server. The transport error code was %2. The server response was %1
'
%CDO_E_SMTP_SEND_FAILED           = &H80040211

'
' MessageId: CDO_E_CONNECTION_DROPPED
'
' MessageText:
'
' The transport lost its connection to the server.
'
%CDO_E_CONNECTION_DROPPED         = &H80040212

'
' MessageId: CDO_E_FAILED_TO_CONNECT
'
' MessageText:
'
' The transport failed to connect to the server.
'
%CDO_E_FAILED_TO_CONNECT          = &H80040213

'
' MessageId: CDO_E_INVALID_POST
'
' MessageText:
'
' The Subject, From, and Newsgroup fields are all required, and one or more was not found.
'
%CDO_E_INVALID_POST               = &H80040214

'&H215 was CDO_E_DELETE_FAILED
'
' MessageId: CDO_E_AUTHENTICATION_FAILURE
'
' MessageText:
'
' The server rejected the logon attempt due to authentication failure. The server response was: %1
'
%CDO_E_AUTHENTICATION_FAILURE     = &H80040215

'
' MessageId: CDO_E_INVALID_CONTENT_TYPE
'
' MessageText:
'
' The content type was not valid in this context. For example, the root of an MHTML message must be an HTML document.
'
%CDO_E_INVALID_CONTENT_TYPE       = &H80040216

'
' MessageId: CDO_E_LOGON_FAILURE
'
' MessageText:
'
' The transport was unable to log on to the server.
'
%CDO_E_LOGON_FAILURE              = &H80040217

'
' MessageId: CDO_E_HTTP_NOT_FOUND
'
' MessageText:
'
' The requested resource could not be found. The server response was: %1.
'
%CDO_E_HTTP_NOT_FOUND             = &H80040218

'
' MessageId: CDO_E_HTTP_FORBIDDEN
'
' MessageText:
'
' Access to the requested resource is denied. The server response was: %1.
'
%CDO_E_HTTP_FORBIDDEN             = &H80040219

'
' MessageId: CDO_E_HTTP_FAILED
'
' MessageText:
'
' The HTTP request failed.  The server response was: %1.
'
%CDO_E_HTTP_FAILED                = &H8004021A

'
' MessageId: CDO_E_MULTIPART_NO_DATA
'
' MessageText:
'
' This is a multipart body part. It has no content other than the body parts contained within it.
'
%CDO_E_MULTIPART_NO_DATA          = &H8004021B

' renamed, was CDO_E_INVALID_ENCODING_FOR_COMPOSITE
'
' MessageId: CDO_E_INVALID_ENCODING_FOR_MULTIPART
'
' MessageText:
'
' Multipart body parts must be encoded as 7bit, 8bit, or binary.
'
%CDO_E_INVALID_ENCODING_FOR_MULTIPART = &H8004021C

' &H21d was CDO_E_PATHTOOLONG
'
' MessageId: CDO_E_UNSAFE_OPERATION
'
' MessageText:
'
' The requested operation is not allowed in secure mode.
'
%CDO_E_UNSAFE_OPERATION           = &H8004021D

'
' MessageId: CDO_E_PROP_NOT_FOUND
'
' MessageText:
'
' The requested property was not found.
'
%CDO_E_PROP_NOT_FOUND             = &H8004021E

' &H21f available, was CDO_E_UNSUPPORTED_PROTOCOL
'
' MessageId: CDO_E_INVALID_SEND_OPTION
'
' MessageText:
'
' The "SendUsing" configuration value is invalid.
'
%CDO_E_INVALID_SEND_OPTION        = &H80040220

'
' MessageId: CDO_E_INVALID_POST_OPTION
'
' MessageText:
'
' The "PostUsing" configuration value is invalid.
'
%CDO_E_INVALID_POST_OPTION        = &H80040221

'
' MessageId: CDO_E_NO_PICKUP_DIR
'
' MessageText:
'
' The pickup directory path is required and was not specified.
'
%CDO_E_NO_PICKUP_DIR              = &H80040222

'
' MessageId: CDO_E_NOT_ALL_DELETED
'
' MessageText:
'
' One or more messages could not be deleted.
'
%CDO_E_NOT_ALL_DELETED            = &H80040223

'
' MessageId: CDO_E_NO_METHOD
'
' MessageText:
'
' The requested operation is not available on the underlying object.
'
%CDO_E_NO_METHOD                  = &H80040224

'&H225 available, was CDO_E_BYTEARRAY_REQUIRED
' &H226 available, was CDO_E_BSTR_REQUIRED
'
' MessageId: CDO_E_PROP_READONLY
'
' MessageText:
'
' The property is read-only.
'
%CDO_E_PROP_READONLY              = &H80040227

'
' MessageId: CDO_E_PROP_CANNOT_DELETE
'
' MessageText:
'
' The property cannot be deleted.
'
%CDO_E_PROP_CANNOT_DELETE         = &H80040228

'
' MessageId: CDO_E_BAD_DATA
'
' MessageText:
'
' Data written to the object are inconsistent or invalid.
'
%CDO_E_BAD_DATA                   = &H80040229

'
' MessageId: CDO_E_PROP_NONHEADER
'
' MessageText:
'
' The requested property is not in the mail header namespace.
'
%CDO_E_PROP_NONHEADER             = &H8004022A

'
' MessageId: CDO_E_INVALID_CHARSET
'
' MessageText:
'
' The requested character set is not installed on the computer.
'
%CDO_E_INVALID_CHARSET            = &H8004022B

'
' MessageId: CDO_E_ADOSTREAM_NOT_BOUND
'
' MessageText:
'
' The ADO stream has not been opened.
'
%CDO_E_ADOSTREAM_NOT_BOUND        = &H8004022C

'
' MessageId: CDO_E_CONTENTPROPXML_NOT_FOUND
'
' MessageText:
'
' The content properties are missing.
'
%CDO_E_CONTENTPROPXML_NOT_FOUND   = &H8004022D

'
' MessageId: CDO_E_CONTENTPROPXML_WRONG_CHARSET
'
' MessageText:
'
' Content properties XML must be encoded using UTF-8.
'
%CDO_E_CONTENTPROPXML_WRONG_CHARSET = &H8004022E

'
' MessageId: CDO_E_CONTENTPROPXML_PARSE_FAILED
'
' MessageText:
'
' Failed to parse content properties XML.
'
%CDO_E_CONTENTPROPXML_PARSE_FAILED = &H8004022F

'
' MessageId: CDO_E_CONTENTPROPXML_CONVERT_FAILED
'
' MessageText:
'
' Failed to convert a property from XML to a requested type.
'
%CDO_E_CONTENTPROPXML_CONVERT_FAILED = &H80040230

'
' MessageId: CDO_E_NO_DIRECTORIES_SPECIFIED
'
' MessageText:
'
' No directories were specified for resolution.
'
%CDO_E_NO_DIRECTORIES_SPECIFIED   = &H80040231

'
' MessageId: CDO_E_DIRECTORIES_UNREACHABLE
'
' MessageText:
'
' Failed to resolve against one or more of the specified directories.
'
%CDO_E_DIRECTORIES_UNREACHABLE    = &H80040232

'
' MessageId: CDO_E_BAD_SENDER
'
' MessageText:
'
' Could not find the Sender's mailbox.
'
%CDO_E_BAD_SENDER                 = &H80040233

'
' MessageId: CDO_E_SELF_BINDING
'
' MessageText:
'
' Binding to self is not allowed.
'
%CDO_E_SELF_BINDING               = &H80040234

'
' MessageId: CDO_E_BAD_ATTENDEE_DATA
'
' MessageText:
'
' Data of the Attendees in the object are inconsistent or invalid.
'
%CDO_E_BAD_ATTENDEE_DATA          = &H80040235

'
' MessageId: CDO_E_ROLE_NOMORE_AVAILABLE
'
' MessageText:
'
' No more roles of the desired type are available - maxed out.
'
%CDO_E_ROLE_NOMORE_AVAILABLE      = &H80040236

#IF %DEF(%CDOTASKS)
'
' MessageId: CDO_E_BAD_TASKTYPE_ONASSIGN
'
' MessageText:
'
' The task with its current task type does not permit a call on Assign. Please call CreateUnassignedCopy instead.
'
%CDO_E_BAD_TASKTYPE_ONASSIGN      = &H80040237

'
' MessageId: CDO_E_NOT_ASSIGNEDTO_USER
'
' MessageText:
'
' The task is not assigned to the current user.
'
%CDO_E_NOT_ASSIGNEDTO_USER        = &H80040238

#ENDIF
'
' MessageId: CDO_E_OUTOFDATE
'
' MessageText:
'
' The item being accessed or manipulated is out of date.
'
%CDO_E_OUTOFDATE                  = &H80040239


'----------------------------------------------------------------------------
' parameter validation error messages
'
' MessageId: CDO_E_ARGUMENT1
'
' MessageText:
'
' The first argument is invalid
'
%CDO_E_ARGUMENT1                  = &H80044000

'
' MessageId: CDO_E_ARGUMENT2
'
' MessageText:
'
' The second argument is invalid
'
%CDO_E_ARGUMENT2                  = &H80044001

'
' MessageId: CDO_E_ARGUMENT3
'
' MessageText:
'
' The third argument is invalid
'
%CDO_E_ARGUMENT3                  = &H80044002

'
' MessageId: CDO_E_ARGUMENT4
'
' MessageText:
'
' The fourth argument is invalid
'
%CDO_E_ARGUMENT4                  = &H80044003

'
' MessageId: CDO_E_ARGUMENT5
'
' MessageText:
'
' The fifth argument is invalid
'
%CDO_E_ARGUMENT5                  = &H80044004


'----------------------------------------------------------------------------
' Errors returned by MimeOle
'
' These are defined here to provide extended error info text descriptions.
' CDO should never explicitly return any of these errors; they may be passed
' through from MimeOle
' I expect there are numerous places where these errors could still slip through:
' MIME_E_NOT_FOUND
'
' MessageId: CDO_E_NOT_FOUND
'
' MessageText:
'
' The requested body part was not found in this message.
'
%CDO_E_NOT_FOUND                  = &H800CCE05

' MIME_E_INVALID_ENCODINGTYPE
' Returned when MimeOLE tries to BinHex encode.  Can also be returned if an invalid encoding
' is specified, but CDO should protect from these cases.
'
' Also CDO returns this error when a client sets an invalid encoding
'
' MessageId: CDO_E_INVALID_ENCODING_TYPE
'
' MessageText:
'
' The content encoding type is invalid.
'
%CDO_E_INVALID_ENCODING_TYPE      = &H800CCE1D

'--------------------------------------
' Headers and folder names
'
' MessageId = &H1000 through &H1fff, localized in client languages.
'--------------------------------------
'
' MessageId: IDS_ORIGINAL_MESSAGE
'
' MessageText:
'
' -----Original Message-----%0
'
%IDS_ORIGINAL_MESSAGE             = &H00011000

'
' MessageId: IDS_FROM
'
' MessageText:
'
' From:%0
'
%IDS_FROM                         = &H00011001

'
' MessageId: IDS_SENT
'
' MessageText:
'
' Sent:%0
'
%IDS_SENT                         = &H00011002

'
' MessageId: IDS_POSTED_AT
'
' MessageText:
'
' Posted At:%0
'
%IDS_POSTED_AT                    = &H00011003

'
' MessageId: IDS_TO
'
' MessageText:
'
' To:%0
'
%IDS_TO                           = &H00011004

'
' MessageId: IDS_CC
'
' MessageText:
'
' Cc:%0
'
%IDS_CC                           = &H00011005

'
' MessageId: IDS_POSTED_TO
'
' MessageText:
'
' Posted To:%0
'
%IDS_POSTED_TO                    = &H00011006

'
' MessageId: IDS_CONVERSATION
'
' MessageText:
'
' Conversation:%0
'
%IDS_CONVERSATION                 = &H00011007

'
' MessageId: IDS_SUBJECT
'
' MessageText:
'
' Subject:%0
'
%IDS_SUBJECT                      = &H00011008

'
' MessageId: IDS_IMPORTANCE
'
' MessageText:
'
' Importance:%0
'
%IDS_IMPORTANCE                   = &H00011009

'
' MessageId: IDS_ON_BEHALF_OF
'
' MessageText:
'
' on behalf of%0
'
%IDS_ON_BEHALF_OF                 = &H0001100A

'
' MessageId: IDS_FW
'
' MessageText:
'
' FW:%0
'
%IDS_FW                           = &H0001100B

'
' MessageId: IDS_RE
'
' MessageText:
'
' RE:%0
'
%IDS_RE                           = &H0001100C

'
' MessageId: IDS_CODEPAGE
'
' MessageText:
'
' 1252%0
'
%IDS_CODEPAGE                     = &H0001100D

#IF %DEF(%CDOSVR)
'
' MessageId: IDS_CalendarFolder
'
' MessageText:
'
' Calendar%0
'
%IDS_CalendarFolder               = &H0001100E

'
' MessageId: IDS_ContactsFolder
'
' MessageText:
'
' Contacts%0
'
%IDS_ContactsFolder               = &H0001100F

'
' MessageId: IDS_DraftsFolder
'
' MessageText:
'
' Drafts%0
'
%IDS_DraftsFolder                 = &H00011010

'
' MessageId: IDS_JournalFolder
'
' MessageText:
'
' Journal%0
'
%IDS_JournalFolder                = &H00011011

'
' MessageId: IDS_NotesFolder
'
' MessageText:
'
' Notes%0
'
%IDS_NotesFolder                  = &H00011012

'
' MessageId: IDS_TasksFolder
'
' MessageText:
'
' Tasks%0
'
%IDS_TasksFolder                  = &H00011013

#ENDIF
'
' MessageId: IDS_NewFolder
'
' MessageText:
'
' New Folder%0
'
%IDS_NewFolder                    = &H00011014

'
' MessageId: IDS_Location
'
' MessageText:
'
' Location:%0
'
%IDS_Location                     = &H00011015

'
' MessageId: IDS_StartTime
'
' MessageText:
'
' Start Time:%0
'
%IDS_StartTime                    = &H00011016

'
' MessageId: IDS_EndTime
'
' MessageText:
'
' End Time:%0
'
%IDS_EndTime                      = &H00011017

'
' MessageId: IDS_TimeZone
'
' MessageText:
'
' Time Zone:%0
'
%IDS_TimeZone                     = &H00011018

'
' MessageId: IDS_LocalTime
'
' MessageText:
'
' Local time%0
'
%IDS_LocalTime                    = &H00011019

'
' MessageId: IDS_Organizer
'
' MessageText:
'
' Organizer:%0
'
%IDS_Organizer                    = &H0001101A

'
' MessageId: IDS_ApptType
'
' MessageText:
'
' Type:%0
'
%IDS_ApptType                     = &H0001101B

'
' MessageId: IDS_SingleAppt
'
' MessageText:
'
' Single Appointment%0
'
%IDS_SingleAppt                   = &H0001101C

'
' MessageId: IDS_SingleMtg
'
' MessageText:
'
' Single Meeting%0
'
%IDS_SingleMtg                    = &H0001101D

'
' MessageId: IDS_RecurAppt
'
' MessageText:
'
' Recurring Appointment%0
'
%IDS_RecurAppt                    = &H0001101E

'
' MessageId: IDS_RecurMtg
'
' MessageText:
'
' Recurring Meeting%0
'
%IDS_RecurMtg                     = &H0001101F

'--------------------------------------
' time zones
'
' MessageId = &H1100 through &H11ff
'--------------------------------------
'
' MessageId: IDS_Universal
'
' MessageText:
'
' Universal Coordinated Time%0
'
%IDS_Universal                    = &H00011100

'
' MessageId: IDS_Greenwich
'
' MessageText:
'
' (GMT) Greenwich Mean Time : Dublin, Edinburgh, Lisbon, London%0
'
%IDS_Greenwich                    = &H00011101

'
' MessageId: IDS_Sarajevo
'
' MessageText:
'
' (GMT+01:00) Sarajevo, Skopje, Sofija, Vilnius, Warsaw, Zagreb%0
'
%IDS_Sarajevo                     = &H00011102

'
' MessageId: IDS_Paris
'
' MessageText:
'
' (GMT+01:00) Brussels, Copenhagen, Madrid, Paris%0
'
%IDS_Paris                        = &H00011103

'
' MessageId: IDS_Berlin
'
' MessageText:
'
' (GMT+01:00) Amsterdam, Berlin, Bern, Rome, Stockholm, Vienna%0
'
%IDS_Berlin                       = &H00011104

'
' MessageId: IDS_EasternEurope
'
' MessageText:
'
' (GMT+02:00) Bucharest%0
'
%IDS_EasternEurope                = &H00011105

'
' MessageId: IDS_Prague
'
' MessageText:
'
' (GMT+01:00) Belgrade, Bratislava, Budapest, Ljubljana, Prague%0
'
%IDS_Prague                       = &H00011106

'
' MessageId: IDS_Athens
'
' MessageText:
'
' (GMT+02:00) Athens, Istanbul, Minsk%0
'
%IDS_Athens                       = &H00011107

'
' MessageId: IDS_Brasilia
'
' MessageText:
'
' (GMT-03:00) Brasilia%0
'
%IDS_Brasilia                     = &H00011108

'
' MessageId: IDS_Atlantic
'
' MessageText:
'
' (GMT-04:00) Atlantic Time (Canada)%0
'
%IDS_Atlantic                     = &H00011109

'
' MessageId: IDS_Eastern
'
' MessageText:
'
' (GMT-05:00) Eastern Time (US & Canada)%0
'
%IDS_Eastern                      = &H0001110A

'
' MessageId: IDS_Central
'
' MessageText:
'
' (GMT-06:00) Central Time (US & Canada)%0
'
%IDS_Central                      = &H0001110B

'
' MessageId: IDS_Mountain
'
' MessageText:
'
' (GMT-07:00) Mountain Time (US & Canada)%0
'
%IDS_Mountain                     = &H0001110C

'
' MessageId: IDS_Pacific
'
' MessageText:
'
' (GMT-08:00) Pacific Time (US & Canada)%0
'
%IDS_Pacific                      = &H0001110D

'
' MessageId: IDS_Alaska
'
' MessageText:
'
' (GMT-09:00) Alaska%0
'
%IDS_Alaska                       = &H0001110E

'
' MessageId: IDS_Hawaii
'
' MessageText:
'
' (GMT-10:00) Hawaii%0
'
%IDS_Hawaii                       = &H0001110F

'
' MessageId: IDS_Midway
'
' MessageText:
'
' (GMT-11:00) Midway Island, Samoa%0
'
%IDS_Midway                       = &H00011110

'
' MessageId: IDS_Wellington
'
' MessageText:
'
' (GMT+12:00) Auckland, Wellington%0
'
%IDS_Wellington                   = &H00011111

'
' MessageId: IDS_Brisbane
'
' MessageText:
'
' (GMT+10:00) Brisbane%0
'
%IDS_Brisbane                     = &H00011112

'
' MessageId: IDS_Adelaide
'
' MessageText:
'
' (GMT+09:30) Adelaide%0
'
%IDS_Adelaide                     = &H00011113

'
' MessageId: IDS_Tokyo
'
' MessageText:
'
' (GMT+09:00) Osaka, Sapporo, Tokyo%0
'
%IDS_Tokyo                        = &H00011114

'
' MessageId: IDS_Singapore
'
' MessageText:
'
' (GMT+08:00) Kuala Lumpur, Singapore%0
'
%IDS_Singapore                    = &H00011115

'
' MessageId: IDS_Bangkok
'
' MessageText:
'
' (GMT+07:00) Bangkok, Hanoi, Jakarta%0
'
%IDS_Bangkok                      = &H00011116

'
' MessageId: IDS_Bombay
'
' MessageText:
'
' (GMT+05:30) Kolkata, Chennai, Mumbai, New Delhi%0
'
%IDS_Bombay                       = &H00011117

'
' MessageId: IDS_AbuDhabi
'
' MessageText:
'
' (GMT+04:00) Abu Dhabi, Muscat%0
'
%IDS_AbuDhabi                     = &H00011118

'
' MessageId: IDS_Tehran
'
' MessageText:
'
' (GMT+03:30) Tehran%0
'
%IDS_Tehran                       = &H00011119

'
' MessageId: IDS_Baghdad
'
' MessageText:
'
' (GMT+03:00) Baghdad%0
'
%IDS_Baghdad                      = &H0001111A

'
' MessageId: IDS_Israel
'
' MessageText:
'
' (GMT+02:00) Jerusalem%0
'
%IDS_Israel                       = &H0001111B

'
' MessageId: IDS_Newfoundland
'
' MessageText:
'
' (GMT-03:30) Newfoundland%0
'
%IDS_Newfoundland                 = &H0001111C

'
' MessageId: IDS_Azores
'
' MessageText:
'
' (GMT-01:00) Azores%0
'
%IDS_Azores                       = &H0001111D

'
' MessageId: IDS_MidAtlantic
'
' MessageText:
'
' (GMT-02:00) Mid-Atlantic%0
'
%IDS_MidAtlantic                  = &H0001111E

'
' MessageId: IDS_Monrovia
'
' MessageText:
'
' (GMT) Casablanca, Monrovia%0
'
%IDS_Monrovia                     = &H0001111F

'
' MessageId: IDS_BuenosAires
'
' MessageText:
'
' (GMT-03:00) Buenos Aires, Georgetown%0
'
%IDS_BuenosAires                  = &H00011120

'
' MessageId: IDS_Caracas
'
' MessageText:
'
' (GMT-04:00) Caracas, La Paz%0
'
%IDS_Caracas                      = &H00011121

'
' MessageId: IDS_Indiana
'
' MessageText:
'
' (GMT-05:00) Indiana (East)%0
'
%IDS_Indiana                      = &H00011122

'
' MessageId: IDS_Bogota
'
' MessageText:
'
' (GMT-05:00) Bogota, Lima, Quito%0
'
%IDS_Bogota                       = &H00011123

'
' MessageId: IDS_Saskatchewan
'
' MessageText:
'
' (GMT-06:00) Saskatchewan%0
'
%IDS_Saskatchewan                 = &H00011124

'
' MessageId: IDS_Mexico
'
' MessageText:
'
' (GMT-06:00) Mexico City%0
'
%IDS_Mexico                       = &H00011125

'
' MessageId: IDS_Arizona
'
' MessageText:
'
' (GMT-07:00) Arizona%0
'
%IDS_Arizona                      = &H00011126

'
' MessageId: IDS_Eniwetok
'
' MessageText:
'
' (GMT-12:00) Eniwetok, Kwajalein%0
'
%IDS_Eniwetok                     = &H00011127

'
' MessageId: IDS_Fiji
'
' MessageText:
'
' (GMT+12:00) Fiji Is., Kamchatka, Marshall Is.%0
'
%IDS_Fiji                         = &H00011128

'
' MessageId: IDS_Magadan
'
' MessageText:
'
' (GMT+11:00) Magadan, Solomon Is., New Caledonia%0
'
%IDS_Magadan                      = &H00011129

'
' MessageId: IDS_Hobart
'
' MessageText:
'
' (GMT+10:00) Hobart%0
'
%IDS_Hobart                       = &H0001112A

'
' MessageId: IDS_Guam
'
' MessageText:
'
' (GMT+10:00) Guam, Port Moresby%0
'
%IDS_Guam                         = &H0001112B

'
' MessageId: IDS_Darwin
'
' MessageText:
'
' (GMT+09:30) Darwin%0
'
%IDS_Darwin                       = &H0001112C

'
' MessageId: IDS_Beijing
'
' MessageText:
'
' (GMT+08:00) Beijing, Chongqing, Hong Kong SAR, Urumqi%0
'
%IDS_Beijing                      = &H0001112D

'
' MessageId: IDS_Almaty
'
' MessageText:
'
' (GMT+06:00) Almaty, Novosibirsk%0
'
%IDS_Almaty                       = &H0001112E

'
' MessageId: IDS_Islamabad
'
' MessageText:
'
' (GMT+05:00) Islamabad, Karachi, Tashkent%0
'
%IDS_Islamabad                    = &H0001112F

'
' MessageId: IDS_Kabul
'
' MessageText:
'
' (GMT+04:30) Kabul%0
'
%IDS_Kabul                        = &H00011130

'
' MessageId: IDS_Cairo
'
' MessageText:
'
' (GMT+02:00) Cairo%0
'
%IDS_Cairo                        = &H00011131

'
' MessageId: IDS_Harare
'
' MessageText:
'
' (GMT+02:00) Harare, Pretoria%0
'
%IDS_Harare                       = &H00011132

'
' MessageId: IDS_Moscow
'
' MessageText:
'
' (GMT+03:00) Moscow, St. Petersburg, Volgograd%0
'
%IDS_Moscow                       = &H00011133

'
' MessageId: IDS_CapeVerde
'
' MessageText:
'
' (GMT-01:00) Cape Verde Is.%0
'
%IDS_CapeVerde                    = &H00011134

'
' MessageId: IDS_Caucasus
'
' MessageText:
'
' (GMT+04:00) Baku, Tbilisi, Yerevan%0
'
%IDS_Caucasus                     = &H00011135

'
' MessageId: IDS_CentralAmerica
'
' MessageText:
'
' (GMT-06:00) Central America%0
'
%IDS_CentralAmerica               = &H00011136

'
' MessageId: IDS_EastAfrica
'
' MessageText:
'
' (GMT+03:00) Nairobi%0
'
%IDS_EastAfrica                   = &H00011137

'
' MessageId: IDS_Melbourne
'
' MessageText:
'
' (GMT+10:00) Canberra, Melbourne, Sydney%0
'
%IDS_Melbourne                    = &H00011138

'
' MessageId: IDS_Ekaterinburg
'
' MessageText:
'
' (GMT+05:00) Ekaterinburg%0
'
%IDS_Ekaterinburg                 = &H00011139

'
' MessageId: IDS_Helsinki
'
' MessageText:
'
' (GMT+02:00) Helsinki, Riga, Tallinn%0
'
%IDS_Helsinki                     = &H0001113A

'
' MessageId: IDS_Greenland
'
' MessageText:
'
' (GMT-03:00) Greenland%0
'
%IDS_Greenland                    = &H0001113B

'
' MessageId: IDS_Rangoon
'
' MessageText:
'
' (GMT+06:30) Yangon (Rangun)%0
'
%IDS_Rangoon                      = &H0001113C

'
' MessageId: IDS_Nepal
'
' MessageText:
'
' (GMT+05:45) Kathmandu%0
'
%IDS_Nepal                        = &H0001113D

'
' MessageId: IDS_Irkutsk
'
' MessageText:
'
' (GMT+08:00) Irkutsk, Ulaan Bataar%0
'
%IDS_Irkutsk                      = &H0001113E

'
' MessageId: IDS_Krasnoyarsk
'
' MessageText:
'
' (GMT+07:00) Krasnoyarsk%0
'
%IDS_Krasnoyarsk                  = &H0001113F

'
' MessageId: IDS_Santiago
'
' MessageText:
'
' (GMT-04:00) Santiago%0
'
%IDS_Santiago                     = &H00011140

'
' MessageId: IDS_SriLanka
'
' MessageText:
'
' (GMT+06:00) Sri Jayawardenepura%0
'
%IDS_SriLanka                     = &H00011141

'
' MessageId: IDS_Tonga
'
' MessageText:
'
' (GMT+13:00) Nuku'alofa%0
'
%IDS_Tonga                        = &H00011142

'
' MessageId: IDS_Vladivostok
'
' MessageText:
'
' (GMT+10:00) Vladivostok%0
'
%IDS_Vladivostok                  = &H00011143

'
' MessageId: IDS_WestCentralAfrica
'
' MessageText:
'
' (GMT+01:00) West Central Africa%0
'
%IDS_WestCentralAfrica            = &H00011144

'
' MessageId: IDS_Yakutsk
'
' MessageText:
'
' (GMT+09:00) Yakutsk%0
'
%IDS_Yakutsk                      = &H00011145

'
' MessageId: IDS_Dhaka
'
' MessageText:
'
' (GMT+06:00) Astana, Dhaka%0
'
%IDS_Dhaka                        = &H00011146

'
' MessageId: IDS_Seoul
'
' MessageText:
'
' (GMT+09:00) Seoul%0
'
%IDS_Seoul                        = &H00011147

'
' MessageId: IDS_Perth
'
' MessageText:
'
' (GMT+08:00) Perth%0
'
%IDS_Perth                        = &H00011148

'
' MessageId: IDS_Arab
'
' MessageText:
'
' (GMT+03:00) Kuwait, Riyadh%0
'
%IDS_Arab                         = &H00011149

'
' MessageId: IDS_Taipei
'
' MessageText:
'
' (GMT+08:00) Taipei%0
'
%IDS_Taipei                       = &H0001114A

'
' MessageId: IDS_Sydney2000
'
' MessageText:
'
' (GMT+10:00) Canberra, Melbourne, Sydney (Year 2000 only)%0
'
%IDS_Sydney2000                   = &H0001114B

'
' MessageId: IDS_Chihuahua
'
' MessageText:
'
' (GMT-07:00) Chihuahua, La Paz, Mazatlan%0
'
%IDS_Chihuahua                    = &H0001114C

'
' MessageId: IDS_CanberraCommonwealthGames2006
'
' MessageText:
'
' (GMT+10:00) Canberra, Melbourne, Sydney (Commonwealth Games)%0
'
%IDS_CanberraCommonwealthGames2006 = &H0001114D

'
' MessageId: IDS_AdelaideCommonwealthGames2006
'
' MessageText:
'
' (GMT+09:30) Adelaide (Commonwealth Games)%0
'
%IDS_AdelaideCommonwealthGames2006 = &H0001114E

'
' MessageId: IDS_HobartCommonwealthGames2006
'
' MessageText:
'
' (GMT+10:00) Hobart (Commonwealth Games)%0
'
%IDS_HobartCommonwealthGames2006  = &H0001114F

'
' MessageId: IDS_Tijuana
'
' MessageText:
'
' (GMT-08:00) Tijuana, Baja California%0
'
%IDS_Tijuana                      = &H00011150

'--------------------------------------
' EXCDO messages
'
' MessageId = &H2000 through &H2fff, localized in server languages.
'--------------------------------------
#IF %DEF(%CDOSVR)
'
' MessageId: evtMethodCalled
'
' MessageText:
'
' %1 Event on %2 called with Flags %3
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtMethodCalled                  = &H00032000

'
' MessageId: evtMethodReturning
'
' MessageText:
'
' %1 Event Method is returning with HRESULT %2
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtMethodReturning               = &H00032001

'
' MessageId: evtIsAborting
'
' MessageText:
'
' %1 Event Method is halting, HRESULT %2
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtIsAborting                    = &HC0032002

'
' MessageId: evtExpansionInitialized
'
' MessageText:
'
' Calendaring agent is initialized successfully.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtExpansionInitialized          = &H00032003

'
' MessageId: evtExpansionUnInitialized
'
' MessageText:
'
' Calendaring agent is stopping successfully.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtExpansionUnInitialized        = &H00032004

'
' MessageId: evtExpansionInitializeFailed
'
' MessageText:
'
' Calendaring agent failed to initialize with error %1.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtExpansionInitializeFailed     = &HC0032005

'
' MessageId: evtExpansionRegisterFailed
'
' MessageText:
'
' Calendaring recurring item expansion failed to register for notifications for
' MDB %1.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtExpansionRegisterFailed       = &HC0032006

'
' MessageId: evtExpansionMessageSaveChangesFailed
'
' MessageText:
'
' Calendaring agent failed in message save notification with error %1 on %2: %3.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtExpansionMessageSaveChangesFailed = &HC0032007

'
' MessageId: evtExpansionMessageDeleteFailed
'
' MessageText:
'
' Calendaring agent failed in message delete notification with error %1 on %2: %3.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtExpansionMessageDeleteFailed  = &HC0032008

'
' MessageId: evtExpansionFolderSaveChangesFailed
'
' MessageText:
'
' Calendaring agent failed in folder save notification with error %1 on %2: %3.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtExpansionFolderSaveChangesFailed = &HC0032009

'
' MessageId: evtExpansionTooManyInstancesPerDay
'
' MessageText:
'
' Calendaring agent truncated expansion after %1 instances per day.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtExpansionTooManyInstancesPerDay = &H8003200A

'
' MessageId: evtMailboxCreateTotalFailure
'
' MessageText:
'
' The mailbox creation callback failed to create any folders in mailbox %1.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtMailboxCreateTotalFailure     = &HC003200B

'
' MessageId: evtMailboxCreatePartialFailure
'
' MessageText:
'
' The mailbox creation callback failed to create one or more folders in mailbox
' %1.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtMailboxCreatePartialFailure   = &HC003200C

'
' MessageId: evtUninitImplRestFailed
'
' MessageText:
'
' Calendaring agent failed to uninitialize implied restriction with error %1
' on %2: %3.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtUninitImplRestFailed          = &HC003200D

'
' MessageId: evtExpandSavingAppt
'
' MessageText:
'
' Calendaring agent failed with error code %1 while saving appointment.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtExpandSavingAppt              = &HC003200E

'
' MessageId: evtExpandDeletingAppt
'
' MessageText:
'
' Calendaring agent failed with error code %1 while deleting appointment.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtExpandDeletingAppt            = &HC003200F

'
' MessageId: evtExpandQuery
'
' MessageText:
'
' Calendaring agent failed with error code %1 while expanding recurring
' appointments.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtExpandQuery                   = &HC0032010

'
' MessageId: evtExpandFolderSetProps
'
' MessageText:
'
' Calendaring agent failed with error code %1 while cleaning up the calendar.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtExpandFolderSetProps          = &HC0032011

'
' MessageId: evtRegistryFailure
'
' MessageText:
'
' Calendaring agent failed to open registry with error code %1.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtRegistryFailure               = &HC0032012

'
' MessageId: evtExpStat
'
' MessageText:
'
' Calendaring agent failed in the following function with error code: %1.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtExpStat                       = &HC0032013

'
' MessageId: evtDumpFcn
'
' MessageText:
'
' Calendaring agent failed in the following function with error code %1.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtDumpFcn                       = &HC0032014

'
' MessageId: evtSaveDeleteFailFBUpdate
'
' MessageText:
'
' Calendaring agent failed to update the free/busy cache during an appointment
' save or delete operation.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtSaveDeleteFailFBUpdate        = &HC0032015

'
' MessageId: evtProcessingQueryCallback
'
' MessageText:
'
' Calendaring agent failed to update the free/busy cache and internal data
' while processing a query.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtProcessingQueryCallback       = &HC0032016

'
' MessageId: evtMailboxLocalizeTotalFailure
'
' MessageText:
'
' The mailbox creation callback failed to rename any folders in mailbox %1.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtMailboxLocalizeTotalFailure   = &HC0032017

'
' MessageId: evtMailboxLocalizePartialFailure
'
' MessageText:
'
' The mailbox creation callback failed to rename one or more folders in mailbox %1.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtMailboxLocalizePartialFailure = &HC0032018

'
' MessageId: evtExpandMaster
'
' MessageText:
'
' The processing of the recurring appointment with the subject "%1" in mailbox:
' %2 failed with error code %3.  This appointment will not be visible in the
' web client or other non-MAPI client.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtExpandMaster                  = &HC0032019

'
' MessageId: evtExpansionInit
'
' MessageText:
'
' A transaction failed during initialization.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtExpansionInit                 = &HC003201A

'
' MessageId: evtFBGenerateMsg
'
' MessageText:
'
' The calendaring agent could not publish the free/busy information for "%1"
' because it failed reading the registry with error: %2.
' The save/delete calendar operation for "%3" will not be completed.
' Please ensure that MSExchangeFBPublish agent is started.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtFBGenerateMsg                 = &HC003201B

'
' MessageId: evtExpansionInstExpiryInPublicMDB
'
' MessageText:
'
' Expiry of an instance for the recurring appointment with the subject "%1" in
' the folder "%2" was detected.  The master for that should be expired before
' this instance.
' This instance will no longer appear in the web clients until the master is
' updated manually or through replication.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtExpansionInstExpiryInPublicMDB = &H8003201C

'
' MessageId: evtUnhandledExceptionInitialization
'
' MessageText:
'
' Unhandled exception %1 caught during initialization of server agents.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtUnhandledExceptionInitialization = &HC003201D

'
' MessageId: evtUnhandledExceptionShutdown
'
' MessageText:
'
' Unhandled exception %1 caught trying to stop server agents.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtUnhandledExceptionShutdown    = &HC003201E

'
' MessageId: evtUnhandledExceptionInitializationMDB
'
' MessageText:
'
' Unhandled exception %1 caught during initialization of server agents while
' an MDB is mounted.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtUnhandledExceptionInitializationMDB = &HC003201F

'
' MessageId: evtUnhandledExceptionShutdownMDB
'
' MessageText:
'
' Unhandled exception %1 caught trying to stop server agents while an MDB is
' unmounted.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtUnhandledExceptionShutdownMDB = &HC0032020

'
' MessageId: evtUnhandledExceptionMsgSaveChanges
'
' MessageText:
'
' Unhandled exception %1 caught during message save changes notification.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtUnhandledExceptionMsgSaveChanges = &HC0032021

'
' MessageId: evtUnhandledExceptionDelete
'
' MessageText:
'
' Unhandled exception %1 caught during deletion notification.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtUnhandledExceptionDelete      = &HC0032022

'
' MessageId: evtUnhandledExceptionQuery
'
' MessageText:
'
' Unhandled exception %1 caught during query processing.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtUnhandledExceptionQuery       = &HC0032023

'
' MessageId: evtUnhandledExceptionFolderSaveChanges
'
' MessageText:
'
' Unhandled exception %1 caught during folder save changes notification.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtUnhandledExceptionFolderSaveChanges = &HC0032024

'
' MessageId: evtCorruptedCalendar
'
' MessageText:
'
' The calendar for the mailbox %1 is corrupted.  This calendar needs to be
' recreated.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtCorruptedCalendar             = &HC0032025

'
' MessageId: evtRebuildCalendar
'
' MessageText:
'
' An inconsistency was detected in %2: %3.  The calendar is being repaired.
' If other errors occur with this calendar, please view the calendar using
' Microsoft Outlook Web Access.  If a problem persists, please recreate the
' calendar or the containing mailbox.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtRebuildCalendar               = &H80032026

'
' MessageId: evtCheckPrimaryCalendar
'
' MessageText:
'
' Calendar agent failed to determine the primary calendar for mailbox: %1.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtCheckPrimaryCalendar          = &H80032027

'
' MessageId: evtExpandMasterPF
'
' MessageText:
'
' The processing of the recurring appointment with the subject "%1" in public
' folder: %2 failed with error code %3.  This appointment will not be visible
' in the web client or other non-MAPI client.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtExpandMasterPF                = &HC0032028

'
' MessageId: evtCorruptedPFCalendar
'
' MessageText:
'
' The public folder %1 is corrupted.  This calendar needs to be recreated.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtCorruptedPFCalendar           = &HC0032029

'
' MessageId: evtRebuildPFCalendar
'
' MessageText:
'
' An inconsistency was detected in %1.  The calendar is being repaired.  If
' other errors occur with this calendar, please view the calendar using
' Microsoft Outlook Web Access.  If a problem persists, please recreate the
' public folder calendar.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtRebuildPFCalendar             = &H8003202A

'
' MessageId: evtMovingMailboxCallbackFailed
'
' MessageText:
'
' Clearing the calendar instances before a move failed for mailbox %1 with
' error %2.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtMovingMailboxCallbackFailed   = &H8003202B

'
' MessageId: evtGetMsgClassFromMaster
'
' MessageText:
'
' Calendaring agent failed with error %1 while attempting to retrieve the
' message class for a recurring appointment.  The message class for the
' instance when viewed with the Web Client will not be the same as the one in
' the series if it is not IPM.Appointment.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtGetMsgClassFromMaster         = &H8003202C

'
' MessageId: evtOpenURL
'
' MessageText:
'
' Calendaring agent failed with error %1 while attempting to open the status
' message. If the user is a delegate, the access rights to the mailbox might
' not be set up correctly.  Otherwise, the calendar for this mailbox could be
' corrupted. This could be fixed by moving the mailbox to another Exchange
' server, or exporting the calendar to a Personal Folder File (.PST), and
' re-importing this into a new calendar.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtOpenURL                       = &H8003202D

'
' MessageId: evtStatusMsgSent
'
' MessageText:
'
' The calendaring data message for %1: %2 has been sent to %3.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtStatusMsgSent                 = &H4003202E

'
' MessageId: evtSaveInvalidStartAppt
'
' MessageText:
'
' An appointment with the subject "%1" was saved to mailbox %2. The start time
' is missing, so the calendaring agent cannot publish the free/busy information
' for this appointment. To correct this, please delete the appointment and
' recreate it.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtSaveInvalidStartAppt          = &HC003202F

'
' MessageId: evtSaveInvalidEndAppt
'
' MessageText:
'
' An appointment with the subject "%1" was saved to mailbox %2. The end time
' and duration are missing. For the purposes of publishing free/busy
' information, this appointment has a duration of zero minutes. To correct
' this, please delete the appointment and recreate it.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtSaveInvalidEndAppt            = &H80032030

'
' MessageId: evtModifyInvalidAppt
'
' MessageText:
'
' An existing appointment with the subject "%1" in mailbox %2 was modified.
' The start time, or both the duration and end time of the existing appointment
' were missing.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtModifyInvalidAppt             = &H80032031

'
' MessageId: evtDeleteInvalidAppt
'
' MessageText:
'
' The existing appointment with the subject "%1" in mailbox %2 was deleted.
' The start time, or both the duration and end time were missing.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtDeleteInvalidAppt             = &H80032032

'
' MessageId: evtBindToInvalidStartAppt
'
' MessageText:
'
' The calendaring agent cannot bind to the appointment with the subject "%1"
' in mailbox %2 because the appointment is missing a start time. The
' calendaring agent will not publish free/busy information for this
' appointment. To correct this, please delete the appointment and recreate it.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtBindToInvalidStartAppt        = &HC0032033

'
' MessageId: evtBindToInvalidEndAppt
'
' MessageText:
'
' The calendaring agent did bind to the appointment with the subject "%1" in
' mailbox %2, but the appointment is missing an end time and duration. For the
' purposes of publishing free/busy information, this appointment has a duration
' of zero minutes. To correct this, please delete the appointment and recreate
' it.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtBindToInvalidEndAppt          = &H80032034

'
' MessageId: evtReloadLogType
'
' MessageText:
'
' The EXCDO logging level has been reloaded from the registry and is now set
' to &H%1.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtReloadLogType                 = &H40032035

'
' MessageId: evtBackgroundStarted
'
' MessageText:
'
' Calendaring agent has successfully started the background thread.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtBackgroundStarted             = &H40032036

'
' MessageId: evtBackgroundStartFailed
'
' MessageText:
'
' Calendaring agent has failed to start the background thread due to %1.
' Rendering of large calendars with the Web client will be slower.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtBackgroundStartFailed         = &H80032037

'
' MessageId: evtBackgroundProcessing
'
' MessageText:
'
' Background calendaring agent is processing the calendar (%1) in the mailbox
' (%2) in the MDB (%3).
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtBackgroundProcessing          = &H40032038

'
' MessageId: evtBackgroundProcessingNoCals
'
' MessageText:
'
' Background calendaring agent did not find any more calendars to process.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtBackgroundProcessingNoCals    = &H40032039

'
' MessageId: evtBackgroundProcessingFinished
'
' MessageText:
'
' Background calendaring agent has finished processing the calendar (%1) in the
' mailbox (%2) in the MDB (%3).  The return code is %4.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtBackgroundProcessingFinished  = &H4003203A

'
' MessageId: evtBackgroundAwakeDueToShutdown
'
' MessageText:
'
' Background calendaring agent is awakened due to shutdown.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtBackgroundAwakeDueToShutdown  = &H4003203B

'
' MessageId: evtBackgroundAwake
'
' MessageText:
'
' Background calendaring agent is awakened due to calendars needing expansion.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtBackgroundAwake               = &H4003203C

'
' MessageId: evtBackgroundTerminating
'
' MessageText:
'
' Background calendaring agent is terminating with return code %1.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtBackgroundTerminating         = &H4003203D

'
' MessageId: evtBackgroundRegisterTaskFailed
'
' MessageText:
'
' The background calendaring agent failed with error code %1 while registering
' task.
' The rendering of large calendars with the web client or Microsoft Internet
' Explorer will be slower.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtBackgroundRegisterTaskFailed  = &HC003203E

'
' MessageId: evtBackgroundLogonFailed
'
' MessageText:
'
' The background calendaring agent failed to logon to the MDB, or create a
' session object on the MDB:%1.
' The error code is %2.
' The rendering of large calendars with the web client or Microsoft Internet
' Explorer for the mailbox %3 with GUID:%4 will be slower.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtBackgroundLogonFailed         = &HC003203F

'
' MessageId: evtBackgroundGetMachineToken
'
' MessageText:
'
' The background calendaring agent failed to retrieve the token required for
' logon on the MDB:%1.
' The error code is %2.
' The rendering of large calendars with the web client or Microsoft Internet
' Explorer on this MDB will be slower.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtBackgroundGetMachineToken     = &HC0032040

'
' MessageId: evtBackgroundSleepUntilNewCal
'
' MessageText:
'
' Background calendaring agent is sleeping until shutdown or a calendar is
' queued.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtBackgroundSleepUntilNewCal    = &H40032041

'
' MessageId: evtBackgroundQueued
'
' MessageText:
'
' The calendar (%1) in mailbox (%2) in the MDB (%3) has been queued for
' background expansion.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtBackgroundQueued              = &H40032042

'
' MessageId: evtBkExpDumpFcn
'
' MessageText:
'
' The background calendaring agent failed in the following function with error
' code %1.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtBkExpDumpFcn                  = &HC0032043

'
' MessageId: evtSaveDurationTooLong
'
' MessageText:
'
' An attempt was made to save an appointment with the subject "%1" to
' mailbox %2. The duration of the appointment was too large, so it was not
' saved.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtSaveDurationTooLong           = &H80032044

'
' MessageId: evtModifyDurationTooLong
'
' MessageText:
'
' An existing appointment with the subject "%1" in mailbox %2 was modified.
' The duration of the existing appointment was too large. Free/busy publishing
' may not be accurate.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtModifyDurationTooLong         = &H80032045

'
' MessageId: evtDeleteDurationTooLong
'
' MessageText:
'
' The existing appointment with the subject "%1" in mailbox %2 was deleted. The
' duration of the existing appointment was too large. Free/busy publishing may
' not be accurate.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtDeleteDurationTooLong         = &H80032046

'
' MessageId: evtTooManyIterationsForQuery
'
' MessageText:
'
' The recurring appointment expansion in mailbox %1 has taken too long. Some
' recurring appointment instances may not be visible at this time. To ensure
' that the calendar view is correct, please refresh the calendar view in
' Microsoft Outlook Web Access.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtTooManyIterationsForQuery     = &H80032047

'
' MessageId: evtTooManyIterationsForFreebusy
'
' MessageText:
'
' The recurring appointment expansion in mailbox %1 has taken too long. The
' free/busy information for this calendar may be inaccurate. This may be the
' result of many very old recurring appointments. To correct this, please
' remove them or change their start date to a more recent date.
' %n%nFor more information, click http://www.microsoft.com/contentredirect.asp.
'
%evtTooManyIterationsForFreebusy  = &H80032048

#ENDIF
