'------------------------------------------------------------------------------
'
'  FsrmErr.inc -- common File Server Resource Management service errors.
'
'  Copyright (c) 2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 18 Feb 2011
'
'------------------------------------------------------------------------------
'  from FsrmErr.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

'
' HRESULT Success codes
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
' MessageId: FSRM_S_PARTIAL_BATCH
'
' MessageText:
'
' At least one failure occurred in a batch operation.
'
%FSRM_S_PARTIAL_BATCH             = &H00045304

'
' MessageId: FSRM_S_PARTIAL_CLASSIFICATION
'
' MessageText:
'
' The file may only have partial classification because a failure occurred while loading or classifying the file properties.
'
%FSRM_S_PARTIAL_CLASSIFICATION    = &H00045305


'
' HRESULT Failure codes
'

'
' MessageId: FSRM_E_NOT_FOUND
'
' MessageText:
'
' The requested object was not found.
'
%FSRM_E_NOT_FOUND                 = &H80045301

'
' MessageId: FSRM_E_INVALID_SCHEDULER_ARGUMENT
'
' MessageText:
'
' One or more of the arguments supplied to the task scheduler are not valid.
'
%FSRM_E_INVALID_SCHEDULER_ARGUMENT = &H80045302

'
' MessageId: FSRM_E_ALREADY_EXISTS
'
' MessageText:
'
' The specified object already exists.
'
%FSRM_E_ALREADY_EXISTS            = &H80045303

'
' MessageId: FSRM_E_PATH_NOT_FOUND
'
' MessageText:
'
' The specified path was not found.
'
%FSRM_E_PATH_NOT_FOUND            = &H80045304

'
' MessageId: FSRM_E_INVALID_USER
'
' MessageText:
'
' The specified user is invalid.
'
%FSRM_E_INVALID_USER              = &H80045305

'
' MessageId: FSRM_E_INVALID_PATH
'
' MessageText:
'
' The specified path is invalid.
'
%FSRM_E_INVALID_PATH              = &H80045306

'
' MessageId: FSRM_E_INVALID_LIMIT
'
' MessageText:
'
' The specified limit is invalid.
'
%FSRM_E_INVALID_LIMIT             = &H80045307

'
' MessageId: FSRM_E_INVALID_NAME
'
' MessageText:
'
' The specified name is invalid.
'
%FSRM_E_INVALID_NAME              = &H80045308

'
' MessageId: FSRM_E_FAIL_BATCH
'
' MessageText:
'
' All items in a batch operation failed.
'
%FSRM_E_FAIL_BATCH                = &H80045309

'
' MessageId: FSRM_E_INVALID_TEXT
'
' MessageText:
'
' The specified text is invalid.
'
%FSRM_E_INVALID_TEXT              = &H8004530A

'
' MessageId: FSRM_E_INVALID_IMPORT_VERSION
'
' MessageText:
'
' The version of the configuration file you are trying to import is not supported. You cannot import configuration files with database versions earlier than 2.0.
'
%FSRM_E_INVALID_IMPORT_VERSION    = &H8004530B

'
' MessageId: FSRM_E_OUT_OF_RANGE
'
' MessageText:
'
' The specified property is out of range.
'
%FSRM_E_OUT_OF_RANGE              = &H8004530D

'
' MessageId: FSRM_E_REQD_PARAM_MISSING
'
' MessageText:
'
' The specified required property is missing.
'
%FSRM_E_REQD_PARAM_MISSING        = &H8004530E

'
' MessageId: FSRM_E_INVALID_COMBINATION
'
' MessageText:
'
' The specified property combination is invalid.
'
%FSRM_E_INVALID_COMBINATION       = &H8004530F

'
' MessageId: FSRM_E_DUPLICATE_NAME
'
' MessageText:
'
' Duplicate names were detected for the same object.
'
%FSRM_E_DUPLICATE_NAME            = &H80045310

'
' MessageId: FSRM_E_NOT_SUPPORTED
'
' MessageText:
'
' The operation or the specified combination of parameters is not supported.
'
%FSRM_E_NOT_SUPPORTED             = &H80045311

'
' MessageId: FSRM_E_DRIVER_NOT_READY
'
' MessageText:
'
' A required filter driver is not installed, loaded or ready for service.
'
%FSRM_E_DRIVER_NOT_READY          = &H80045313

'
' MessageId: FSRM_E_INSUFFICIENT_DISK
'
' MessageText:
'
' There is insufficient disk space to perform the requested operation.
'
%FSRM_E_INSUFFICIENT_DISK         = &H80045314

'
' MessageId: FSRM_E_VOLUME_UNSUPPORTED
'
' MessageText:
'
' The specified volume is unsupported.
'
%FSRM_E_VOLUME_UNSUPPORTED        = &H80045315

'
' MessageId: FSRM_E_UNEXPECTED
'
' MessageText:
'
' The File Server Resource Manager service encountered an unexpected error.
' Check the application event log for more information.
'
%FSRM_E_UNEXPECTED                = &H80045316

'
' MessageId: FSRM_E_INSECURE_PATH
'
' MessageText:
'
' The specified path is insecure.
'
%FSRM_E_INSECURE_PATH             = &H80045317

'
' MessageId: FSRM_E_INVALID_SMTP_SERVER
'
' MessageText:
'
' The SMTP server is invalid.
'
%FSRM_E_INVALID_SMTP_SERVER       = &H80045318

'
' MessageId: FSRM_E_AUTO_QUOTA
'
' MessageText:
'
' Auto apply quota configuration for one or more folders failed.  Check the application event log for more information.
'
%FSRM_E_AUTO_QUOTA                = &H0004531B

'
' MessageId: FSRM_E_EMAIL_NOT_SENT
'
' MessageText:
'
' The File Server Resource Manager service could not send email due to an error.
' Check the application event log for more information.
'
%FSRM_E_EMAIL_NOT_SENT            = &H8004531C

'
' MessageId: FSRM_E_INVALID_EMAIL_ADDRESS
'
' MessageText:
'
' The specified email address is invalid.
'
%FSRM_E_INVALID_EMAIL_ADDRESS     = &H8004531E

'
' MessageId: FSRM_E_FILE_SYSTEM_CORRUPT
'
' MessageText:
'
' The file system might be corrupted.  Please run the CHKDSK utility.
'
%FSRM_E_FILE_SYSTEM_CORRUPT       = &H8004531F

'
' MessageId: FSRM_E_LONG_CMDLINE
'
' MessageText:
'
' The specified command-line executable path is longer than MAX_PATH.
'
%FSRM_E_LONG_CMDLINE              = &H80045320

'
' MessageId: FSRM_E_INVALID_FILEGROUP_DEFINITION
'
' MessageText:
'
' The specified file group definition is invalid.
'
%FSRM_E_INVALID_FILEGROUP_DEFINITION = &H80045321

'
' MessageId: FSRM_E_INVALID_DATASCREEN_DEFINITION
'
' MessageText:
'
' The specified file screen is invalid.
'
%FSRM_E_INVALID_DATASCREEN_DEFINITION = &H80045324

'
' MessageId: FSRM_E_INVALID_REPORT_FORMAT
'
' MessageText:
'
' The specified report format is invalid.
'
%FSRM_E_INVALID_REPORT_FORMAT     = &H80045328

'
' MessageId: FSRM_E_INVALID_REPORT_DESC
'
' MessageText:
'
' The specified report description is invalid.
'
%FSRM_E_INVALID_REPORT_DESC       = &H80045329

'
' MessageId: FSRM_E_INVALID_FILENAME
'
' MessageText:
'
' The specified file name is invalid.
'
%FSRM_E_INVALID_FILENAME          = &H8004532A

'
' MessageId: FSRM_E_SHADOW_COPY
'
' MessageText:
'
' A volume shadow copy could not be created or was unexpectedly deleted.
'
%FSRM_E_SHADOW_COPY               = &H8004532C

'
' MessageId: FSRM_E_XML_CORRUPTED
'
' MessageText:
'
' A File Server Resource Manager XML configuration file or import-export file is corrupted.
'
%FSRM_E_XML_CORRUPTED             = &H8004532D

'
' MessageId: FSRM_E_CLUSTER_NOT_RUNNING
'
' MessageText:
'
' File Server Resource Manager global configuration cannot be accessed since the cluster service is not running.
'
%FSRM_E_CLUSTER_NOT_RUNNING       = &H8004532E

'
' MessageId: FSRM_E_STORE_NOT_INSTALLED
'
' MessageText:
'
' File Server Resource Manager global configuration cannot be accessed since it is not installed yet.
'
%FSRM_E_STORE_NOT_INSTALLED       = &H8004532F

'
' MessageId: FSRM_E_NOT_CLUSTER_VOLUME
'
' MessageText:
'
' The volume does not reside on a cluster shared disk with an associated cluster resource.
'
%FSRM_E_NOT_CLUSTER_VOLUME        = &H80045330

'
' MessageId: FSRM_E_DIFFERENT_CLUSTER_GROUP
'
' MessageText:
'
' There are at least two paths which reside on different cluster shared disks which are not in the same cluster resource group.
'
%FSRM_E_DIFFERENT_CLUSTER_GROUP   = &H80045331

'
' MessageId: FSRM_E_REPORT_TYPE_ALREADY_EXISTS
'
' MessageText:
'
' A report of the specified type already exists in the report job.
'
%FSRM_E_REPORT_TYPE_ALREADY_EXISTS = &H80045332

'
' MessageId: FSRM_E_REPORT_JOB_ALREADY_RUNNING
'
' MessageText:
'
' The report job is already running or queued for running.
'
%FSRM_E_REPORT_JOB_ALREADY_RUNNING = &H80045333

'
' MessageId: FSRM_E_REPORT_GENERATION_ERR
'
' MessageText:
'
' An error occurred during report generation.
'
%FSRM_E_REPORT_GENERATION_ERR     = &H80045334

'
' MessageId: FSRM_E_REPORT_TASK_TRIGGER
'
' MessageText:
'
' The task contains zero or unsupported triggers.
'
%FSRM_E_REPORT_TASK_TRIGGER       = &H80045335

'
' MessageId: FSRM_E_LOADING_DISABLED_MODULE
'
' MessageText:
'
' A rule or policy attempted to load/use a disabled module.
'
%FSRM_E_LOADING_DISABLED_MODULE   = &H80045336

'
' MessageId: FSRM_E_CANNOT_AGGREGATE
'
' MessageText:
'
' File Server Resource Manager cannot aggregate the value for the specified file property.
'
%FSRM_E_CANNOT_AGGREGATE          = &H80045337

'
' MessageId: FSRM_E_MESSAGE_LIMIT_EXCEEDED
'
' MessageText:
'
' The limit of the number of messages that the current pipeline context can add to the property bag has been reached.
'
%FSRM_E_MESSAGE_LIMIT_EXCEEDED    = &H80045338

'
' MessageId: FSRM_E_OBJECT_IN_USE
'
' MessageText:
'
' The object is in use and cannot be deleted.
'
%FSRM_E_OBJECT_IN_USE             = &H80045339

'
' MessageId: FSRM_E_CANNOT_RENAME_PROPERTY
'
' MessageText:
'
' Cannot change the name of a property definition once it is set.
'
%FSRM_E_CANNOT_RENAME_PROPERTY    = &H8004533A

'
' MessageId: FSRM_E_CANNOT_CHANGE_PROPERTY_TYPE
'
' MessageText:
'
' Cannot change the type of a property definition once it is set.
'
%FSRM_E_CANNOT_CHANGE_PROPERTY_TYPE = &H8004533B

'
' MessageId: FSRM_E_MAX_PROPERTY_DEFINITIONS
'
' MessageText:
'
' A new property definition cannot be created.  The maximum number of property definitions, {0}, has been reached.
'
%FSRM_E_MAX_PROPERTY_DEFINITIONS  = &H8004533C

'
' MessageId: FSRM_E_CLASSIFICATION_ALREADY_RUNNING
'
' MessageText:
'
' A classification job is currently running.  Only one classification job can be running at a time.
'
%FSRM_E_CLASSIFICATION_ALREADY_RUNNING = &H8004533D

'
' MessageId: FSRM_E_CLASSIFICATION_NOT_RUNNING
'
' MessageText:
'
' Classification is not currently running.
'
%FSRM_E_CLASSIFICATION_NOT_RUNNING = &H8004533E

'
' MessageId: FSRM_E_FILE_MANAGEMENT_JOB_ALREADY_RUNNING
'
' MessageText:
'
' The file management task is already running or queued for running.
'
%FSRM_E_FILE_MANAGEMENT_JOB_ALREADY_RUNNING = &H8004533F

'
' MessageId: FSRM_E_FILE_MANAGEMENT_JOB_EXPIRATION
'
' MessageText:
'
' Cannot expire a file while running a file management task.
'
%FSRM_E_FILE_MANAGEMENT_JOB_EXPIRATION = &H80045340

'
' MessageId: FSRM_E_FILE_MANAGEMENT_JOB_CUSTOM
'
' MessageText:
'
' Cannot execute a custom action on a file while executing a file management task.
'
%FSRM_E_FILE_MANAGEMENT_JOB_CUSTOM = &H80045341

'
' MessageId: FSRM_E_FILE_MANAGEMENT_JOB_NOTIFICATION
'
' MessageText:
'
' Cannot send a notification for a file management task.
'
%FSRM_E_FILE_MANAGEMENT_JOB_NOTIFICATION = &H80045342

'
' MessageId: FSRM_E_FILE_OPEN_ERROR
'
' MessageText:
'
' File Server Resource Manager cannot open the file.
'
%FSRM_E_FILE_OPEN_ERROR           = &H80045343

'
' MessageId: FSRM_E_UNSECURE_LINK_TO_HOSTED_MODULE
'
' MessageText:
'
' File Server Resource Manager failed to perform a secure link with a hosted module process.
'
%FSRM_E_UNSECURE_LINK_TO_HOSTED_MODULE = &H80045344

'
' MessageId: FSRM_E_CACHE_INVALID
'
' MessageText:
'
' The property cache for the file is invalid and could not be read.
'
%FSRM_E_CACHE_INVALID             = &H80045345

'
' MessageId: FSRM_E_CACHE_MODULE_ALREADY_EXISTS
'
' MessageText:
'
' A cache storage module already exists.
'
%FSRM_E_CACHE_MODULE_ALREADY_EXISTS = &H80045346

'
' MessageId: FSRM_E_FILE_MANAGEMENT_EXPIRATION_DIR_IN_SCOPE
'
' MessageText:
'
' The expiration directory cannot be within the file management scope.
'
%FSRM_E_FILE_MANAGEMENT_EXPIRATION_DIR_IN_SCOPE = &H80045347

'
' MessageId: FSRM_E_FILE_MANAGEMENT_JOB_ALREADY_EXISTS
'
' MessageText:
'
' A file management task of the specified name already exists.
'
%FSRM_E_FILE_MANAGEMENT_JOB_ALREADY_EXISTS = &H80045348

'
' MessageId: FSRM_E_PROPERTY_DELETED
'
' MessageText:
'
' The specified file property has been deleted.
'
%FSRM_E_PROPERTY_DELETED          = &H80045349

'
' MessageId: FSRM_E_LAST_ACCESS_UPDATE_DISABLED
'
' MessageText:
'
' The updating of last access times is disabled on this server.  To create a report or file management task that uses the last access time the updating of last access time must be enabled.
'
%FSRM_E_LAST_ACCESS_UPDATE_DISABLED = &H80045350

'
' MessageId: FSRM_E_NO_PROPERTY_VALUE
'
' MessageText:
'
' The specified file property should not be assigned a value.
'
%FSRM_E_NO_PROPERTY_VALUE         = &H80045351

'
' MessageId: FSRM_E_INPROC_MODULE_BLOCKED
'
' MessageText:
'
' An unknown module cannot be run inside the service process.
'
%FSRM_E_INPROC_MODULE_BLOCKED     = &H80045352

'
' MessageId: FSRM_E_ENUM_PROPERTIES_FAILED
'
' MessageText:
'
' File Server Resource Manager failed to enumerate file properties because a failure occurred while loading or classifying the file properties.
'
%FSRM_E_ENUM_PROPERTIES_FAILED    = &H80045353

'
' MessageId: FSRM_E_SET_PROPERTY_FAILED
'
' MessageText:
'
' File Server Resource Manager failed to set a file property to the file because a failure occurred while saving the file properties.
'
%FSRM_E_SET_PROPERTY_FAILED       = &H80045354

'
' MessageId: FSRM_E_CANNOT_STORE_PROPERTIES
'
' MessageText:
'
' Classification properties will not be stored because a failure occurred while loading or classifying the file properties.
'
%FSRM_E_CANNOT_STORE_PROPERTIES   = &H80045355

'
' MessageId: FSRM_E_CANNOT_ALLOW_REPARSE_POINT_TAG
'
' MessageText:
'
' Classification properties will not be stored because the reparse point tag on the file cannot be classified.
'
%FSRM_E_CANNOT_ALLOW_REPARSE_POINT_TAG = &H80045356

'
' MessageId: FSRM_E_PARTIAL_CLASSIFICATION_PROPERTY_NOT_FOUND
'
' MessageText:
'
' The requested property was not found. The file may only have partial classification because a failure occurred while loading or classifying the file properties.
'
%FSRM_E_PARTIAL_CLASSIFICATION_PROPERTY_NOT_FOUND = &H80045357

'
' MessageId: FSRM_E_TEXTREADER_NOT_INITIALIZED
'
' MessageText:
'
' The File Server Resource Manager text reader was not initialized.
'
%FSRM_E_TEXTREADER_NOT_INITIALIZED = &H80045358

'
' MessageId: FSRM_E_TEXTREADER_IFILTER_NOT_FOUND
'
' MessageText:
'
' There is no IFilter registered for this extension.
'
%FSRM_E_TEXTREADER_IFILTER_NOT_FOUND = &H80045359

'
' MessageId: FSRM_E_TEXTREADER_IFILTER_CLSID_MALFORMED
'
' MessageText:
'
' The IFilter for this extension is not registered correctly.
'
%FSRM_E_TEXTREADER_IFILTER_CLSID_MALFORMED = &H80045360

'
' MessageId: FSRM_E_TEXTREADER_STREAM_ERROR
'
' MessageText:
'
' There was an error obtaining the file's streaming interface.
'
%FSRM_E_TEXTREADER_STREAM_ERROR   = &H80045361

'
' MessageId: FSRM_E_TEXTREADER_FILENAME_TOO_LONG
'
' MessageText:
'
' The file name's extension is too long.
'
%FSRM_E_TEXTREADER_FILENAME_TOO_LONG = &H80045362

'
' MessageId: FSRM_E_INCOMPATIBLE_FORMAT
'
' MessageText:
'
' The module will not process the specified file because it is unable to determine a compatible file format.
'
%FSRM_E_INCOMPATIBLE_FORMAT       = &H80045363

'
' MessageId: FSRM_E_FILE_ENCRYPTED
'
' MessageText:
'
' File Server Resource Manager could not access the file because it is encrypted.
'
%FSRM_E_FILE_ENCRYPTED            = &H80045364
