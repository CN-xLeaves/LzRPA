'------------------------------------------------------------------------------
'
'  CiError.inc
'
'  Copyright (c) 2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 18 Feb 2011
'
'------------------------------------------------------------------------------
'  from CiError.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%CIERROR_H = 1

#IF NOT %DEF(%FACILITY_WINDOWS)
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
%FACILITY_WINDOWS               = &H8
%FACILITY_NULL                  = &H0
%FACILITY_ITF                   = &H4


'
' Define the severity codes
'
%STATUS_SEVERITY_SUCCESS        = &H0
%STATUS_SEVERITY_COFAIL         = &H3
%STATUS_SEVERITY_COERROR        = &H2


'
' MessageId: NOT_AN_ERROR1
'
' MessageText:
'
'  NOTE:  This dummy error message is necessary to force MC to output
'         the above defines inside the FACILITY_WINDOWS guard instead
'         of leaving it empty.
'
%NOT_AN_ERROR1                    = &H00081600

#ENDIF ' #IF NOT %DEF(%FACILITY_WINDOWS)
'
' Range &H1600-&H1850 is reserved by Content Index.
'
'
' Codes &H1600-&H164f are reserved for QUERY
'
'
' MessageId: QUERY_E_FAILED
'
' MessageText:
'
'  Call failed for unknown reason.
'
%QUERY_E_FAILED                   = &H80041600

'
' MessageId: QUERY_E_INVALIDQUERY
'
' MessageText:
'
'  Invalid parameter.
'
%QUERY_E_INVALIDQUERY             = &H80041601

'
' MessageId: QUERY_E_INVALIDRESTRICTION
'
' MessageText:
'
'  The query restriction could not be parsed.
'
%QUERY_E_INVALIDRESTRICTION       = &H80041602

'
' MessageId: QUERY_E_INVALIDSORT
'
' MessageText:
'
'  An invalid sort order was requested.
'
%QUERY_E_INVALIDSORT              = &H80041603

'
' MessageId: QUERY_E_INVALIDCATEGORIZE
'
' MessageText:
'
'  An invalid categorization order was requested.
'
%QUERY_E_INVALIDCATEGORIZE        = &H80041604

'
' MessageId: QUERY_E_ALLNOISE
'
' MessageText:
'
'  The query contained only ignored words.
'
%QUERY_E_ALLNOISE                 = &H80041605

'
' MessageId: QUERY_E_TOOCOMPLEX
'
' MessageText:
'
'  The query was too complex to be executed.
'
%QUERY_E_TOOCOMPLEX               = &H80041606

'
' MessageId: QUERY_E_TIMEDOUT
'
' MessageText:
'
'  The query exceeded its execution time limit.
'
%QUERY_E_TIMEDOUT                 = &H80041607

'
' MessageId: QUERY_E_DUPLICATE_OUTPUT_COLUMN
'
' MessageText:
'
'  One or more columns in the output column list is a duplicate.
'
%QUERY_E_DUPLICATE_OUTPUT_COLUMN  = &H80041608

'
' MessageId: QUERY_E_INVALID_OUTPUT_COLUMN
'
' MessageText:
'
'  One or more columns in the output column list is not valid.
'
%QUERY_E_INVALID_OUTPUT_COLUMN    = &H80041609

'
' MessageId: QUERY_E_INVALID_DIRECTORY
'
' MessageText:
'
'  Invalid directory name.
'
%QUERY_E_INVALID_DIRECTORY        = &H8004160A

'
' MessageId: QUERY_E_DIR_ON_REMOVABLE_DRIVE
'
' MessageText:
'
'  Specified directory is on a removable medium.
'
%QUERY_E_DIR_ON_REMOVABLE_DRIVE   = &H8004160B

'
' MessageId: QUERY_S_NO_QUERY
'
' MessageText:
'
'  The catalog is in a state where indexing continues, but queries are not allowed.
'
%QUERY_S_NO_QUERY                 = &H8004160C

'
' Codes &H1650-&H167f are reserved for qutil error codes
'
'
' MessageId: QPLIST_E_CANT_OPEN_FILE
'
' MessageText:
'
'  Can not open file.
'
%QPLIST_E_CANT_OPEN_FILE          = &H80041651

'
' MessageId: QPLIST_E_READ_ERROR
'
' MessageText:
'
'  Read error in file.
'
%QPLIST_E_READ_ERROR              = &H80041652

'
' MessageId: QPLIST_E_EXPECTING_NAME
'
' MessageText:
'
'  Expecting property name.
'
%QPLIST_E_EXPECTING_NAME          = &H80041653

'
' MessageId: QPLIST_E_EXPECTING_TYPE
'
' MessageText:
'
'  Expecting type specifier.
'
%QPLIST_E_EXPECTING_TYPE          = &H80041654

'
' MessageId: QPLIST_E_UNRECOGNIZED_TYPE
'
' MessageText:
'
'  Unrecognized type.
'
%QPLIST_E_UNRECOGNIZED_TYPE       = &H80041655

'
' MessageId: QPLIST_E_EXPECTING_INTEGER
'
' MessageText:
'
'  Expecting integer.
'
%QPLIST_E_EXPECTING_INTEGER       = &H80041656

'
' MessageId: QPLIST_E_EXPECTING_CLOSE_PAREN
'
' MessageText:
'
'  Expecting closing parenthesis.
'
%QPLIST_E_EXPECTING_CLOSE_PAREN   = &H80041657

'
' MessageId: QPLIST_E_EXPECTING_GUID
'
' MessageText:
'
'  Expecting GUID.
'
%QPLIST_E_EXPECTING_GUID          = &H80041658

'
' MessageId: QPLIST_E_BAD_GUID
'
' MessageText:
'
'  Invalid guid.
'
%QPLIST_E_BAD_GUID                = &H80041659

'
' MessageId: QPLIST_E_EXPECTING_PROP_SPEC
'
' MessageText:
'
'  Expecting property specifier.
'
%QPLIST_E_EXPECTING_PROP_SPEC     = &H8004165A

'
' MessageId: QPLIST_E_CANT_SET_PROPERTY
'
' MessageText:
'
'  Failed to set property name.
'
%QPLIST_E_CANT_SET_PROPERTY       = &H8004165B

'
' MessageId: QPLIST_E_DUPLICATE
'
' MessageText:
'
'  Duplicate property name.
'
%QPLIST_E_DUPLICATE               = &H8004165C

'
' MessageId: QPLIST_E_VECTORBYREF_USED_ALONE
'
' MessageText:
'
'  DBTYPE_VECTOR or DBTYPE_BYREF used alone.
'
%QPLIST_E_VECTORBYREF_USED_ALONE  = &H8004165D

'
' MessageId: QPLIST_E_BYREF_USED_WITHOUT_PTRTYPE
'
' MessageText:
'
'  DBTYPE_BYREF must be used with DBTYPE_STR, DBTYPE_WSTR, DBTYPE_GUID
'   or DBTYPE_UI1 types.
'
%QPLIST_E_BYREF_USED_WITHOUT_PTRTYPE = &H8004165E

'
' MessageId: QPARSE_E_UNEXPECTED_NOT
'
' MessageText:
'
'  Unexpected NOT operator.
'
%QPARSE_E_UNEXPECTED_NOT          = &H80041660

'
' MessageId: QPARSE_E_EXPECTING_INTEGER
'
' MessageText:
'
'  Expecting integer.
'
%QPARSE_E_EXPECTING_INTEGER       = &H80041661

'
' MessageId: QPARSE_E_EXPECTING_REAL
'
' MessageText:
'
'  Expecting real number.
'
%QPARSE_E_EXPECTING_REAL          = &H80041662

'
' MessageId: QPARSE_E_EXPECTING_DATE
'
' MessageText:
'
'  Expecting date.
'
%QPARSE_E_EXPECTING_DATE          = &H80041663

'
' MessageId: QPARSE_E_EXPECTING_CURRENCY
'
' MessageText:
'
'  Expecting currency.
'
%QPARSE_E_EXPECTING_CURRENCY      = &H80041664

'
' MessageId: QPARSE_E_EXPECTING_GUID
'
' MessageText:
'
'  Expecting GUID.
'
%QPARSE_E_EXPECTING_GUID          = &H80041665

'
' MessageId: QPARSE_E_EXPECTING_BRACE
'
' MessageText:
'
'  Expecting closing square bracket ']'.
'
%QPARSE_E_EXPECTING_BRACE         = &H80041666

'
' MessageId: QPARSE_E_EXPECTING_PAREN
'
' MessageText:
'
'  Expecting closing parenthesis ')'.
'
%QPARSE_E_EXPECTING_PAREN         = &H80041667

'
' MessageId: QPARSE_E_EXPECTING_PROPERTY
'
' MessageText:
'
'  Expecting property name.
'
%QPARSE_E_EXPECTING_PROPERTY      = &H80041668

'
' MessageId: QPARSE_E_NOT_YET_IMPLEMENTED
'
' MessageText:
'
'  Not yet implemented.
'
%QPARSE_E_NOT_YET_IMPLEMENTED     = &H80041669

'
' MessageId: QPARSE_E_EXPECTING_PHRASE
'
' MessageText:
'
'  Expecting phrase.
'
%QPARSE_E_EXPECTING_PHRASE        = &H8004166A

'
' MessageId: QPARSE_E_UNSUPPORTED_PROPERTY_TYPE
'
' MessageText:
'
'  Unsupported property type.
'
%QPARSE_E_UNSUPPORTED_PROPERTY_TYPE = &H8004166B

'
' MessageId: QPARSE_E_EXPECTING_REGEX
'
' MessageText:
'
'  Expecting regular expression.
'
%QPARSE_E_EXPECTING_REGEX         = &H8004166C

'
' MessageId: QPARSE_E_EXPECTING_REGEX_PROPERTY
'
' MessageText:
'
'  Regular expressions require a property of type string.
'
%QPARSE_E_EXPECTING_REGEX_PROPERTY = &H8004166D

'
' MessageId: QPARSE_E_INVALID_LITERAL
'
' MessageText:
'
'  Invalid literal.
'
%QPARSE_E_INVALID_LITERAL         = &H8004166E

'
' MessageId: QPARSE_E_NO_SUCH_PROPERTY
'
' MessageText:
'
'  No such property.
'
%QPARSE_E_NO_SUCH_PROPERTY        = &H8004166F

'
' MessageId: QPARSE_E_EXPECTING_EOS
'
' MessageText:
'
'  Expecting end of string.
'
%QPARSE_E_EXPECTING_EOS           = &H80041670

'
' MessageId: QPARSE_E_EXPECTING_COMMA
'
' MessageText:
'
'  Expecting comma.
'
%QPARSE_E_EXPECTING_COMMA         = &H80041671

'
' MessageId: QPARSE_E_UNEXPECTED_EOS
'
' MessageText:
'
'  Unexpected end of string.
'
%QPARSE_E_UNEXPECTED_EOS          = &H80041672

'
' MessageId: QPARSE_E_WEIGHT_OUT_OF_RANGE
'
' MessageText:
'
'  Weight must be between 0 and 1000 in short form queries and between 0.0 and 1.0 in long form queries.
'
%QPARSE_E_WEIGHT_OUT_OF_RANGE     = &H80041673

'
' MessageId: QPARSE_E_NO_SUCH_SORT_PROPERTY
'
' MessageText:
'
'  An invalid property was found in the sort specification.
'
%QPARSE_E_NO_SUCH_SORT_PROPERTY   = &H80041674

'
' MessageId: QPARSE_E_INVALID_SORT_ORDER
'
' MessageText:
'
'  An invalid sort order was specified.  Only [a] and [d] are supported.
'
%QPARSE_E_INVALID_SORT_ORDER      = &H80041675

'
' MessageId: QUTIL_E_CANT_CONVERT_VROOT
'
' MessageText:
'
'  Couldn't convert a virtual path to a physical path.
'
%QUTIL_E_CANT_CONVERT_VROOT       = &H80041676

'
' MessageId: QPARSE_E_INVALID_GROUPING
'
' MessageText:
'
'  An unsupported grouping type was specified.
'
%QPARSE_E_INVALID_GROUPING        = &H80041677

'
' MessageId: QUTIL_E_INVALID_CODEPAGE
'
' MessageText:
'
'  Invalid CiCodepage was specified.
'
%QUTIL_E_INVALID_CODEPAGE         = &HC0041678

'
' MessageId: QPLIST_S_DUPLICATE
'
' MessageText:
'
'  Exact duplicate property defined.
'
%QPLIST_S_DUPLICATE               = &H00041679

'
' MessageId: QPARSE_E_INVALID_QUERY
'
' MessageText:
'
'  Invalid query.
'
%QPARSE_E_INVALID_QUERY           = &H8004167A

'
' MessageId: QPARSE_E_INVALID_RANKMETHOD
'
' MessageText:
'
'  Invalid rank method.
'
%QPARSE_E_INVALID_RANKMETHOD      = &H8004167B

'
' &H1680 - &H169F are Filter daemon error codes
'
'
' MessageId: FDAEMON_W_WORDLISTFULL
'
' MessageText:
'
'  Wordlist has reached maximum size.  Additional documents should not be filtered.
'
%FDAEMON_W_WORDLISTFULL           = &H00041680

'
' MessageId: FDAEMON_E_LOWRESOURCE
'
' MessageText:
'
'  The system is running out of one of more resources needed for filtering, usually memory.
'
%FDAEMON_E_LOWRESOURCE            = &H80041681

'
' MessageId: FDAEMON_E_FATALERROR
'
' MessageText:
'
'  A critical error occurred during document filtering.  Consult system administrator.
'
%FDAEMON_E_FATALERROR             = &H80041682

'
' MessageId: FDAEMON_E_PARTITIONDELETED
'
' MessageText:
'
'  Documents not stored in content index because partition has been deleted.
'
%FDAEMON_E_PARTITIONDELETED       = &H80041683

'
' MessageId: FDAEMON_E_CHANGEUPDATEFAILED
'
' MessageText:
'
'  Documents not stored in content index because update of changelist failed.
'
%FDAEMON_E_CHANGEUPDATEFAILED     = &H80041684

'
' MessageId: FDAEMON_W_EMPTYWORDLIST
'
' MessageText:
'
'  Final wordlist was empty.
'
%FDAEMON_W_EMPTYWORDLIST          = &H00041685

'
' MessageId: FDAEMON_E_WORDLISTCOMMITFAILED
'
' MessageText:
'
'  Commit of wordlist failed.  Data not available for query.
'
%FDAEMON_E_WORDLISTCOMMITFAILED   = &H80041686

'
' MessageId: FDAEMON_E_NOWORDLIST
'
' MessageText:
'
'  No wordlist is being constructed.  May happen after fatal filter error.
'
%FDAEMON_E_NOWORDLIST             = &H80041687

'
' MessageId: FDAEMON_E_TOOMANYFILTEREDBLOCKS
'
' MessageText:
'
'  During document filtering the limit on buffers has been exceeded.
'
%FDAEMON_E_TOOMANYFILTEREDBLOCKS  = &H80041688

'
' ISearch error codes
'
'
' MessageId: SEARCH_S_NOMOREHITS
'
' MessageText:
'
'  End of hits has been reached.
'
%SEARCH_S_NOMOREHITS              = &H000416A0

'
' MessageId: SEARCH_E_NOMONIKER
'
' MessageText:
'
'  Retrival of hits as monikers is not supported (by filter passed into Init).
'
%SEARCH_E_NOMONIKER               = &H800416A1

'
' MessageId: SEARCH_E_NOREGION
'
' MessageText:
'
'  Retrival of hits as filter regions is not supported (by filter passed into Init).
'
%SEARCH_E_NOREGION                = &H800416A2

'
' Filter error codes
'
'
' MessageId: FILTER_E_TOO_BIG
'
' MessageText:
'
'  File is too large to filter.
'
%FILTER_E_TOO_BIG                 = &H80041730

'
' MessageId: FILTER_S_PARTIAL_CONTENTSCAN_IMMEDIATE
'
' MessageText:
'
'  A partial content scan of the disk needs to be scheduled for immediate execution.
'
%FILTER_S_PARTIAL_CONTENTSCAN_IMMEDIATE = &H00041731

'
' MessageId: FILTER_S_FULL_CONTENTSCAN_IMMEDIATE
'
' MessageText:
'
'  A full content scan of the disk needs to be scheduled for immediate execution.
'
%FILTER_S_FULL_CONTENTSCAN_IMMEDIATE = &H00041732

'
' MessageId: FILTER_S_CONTENTSCAN_DELAYED
'
' MessageText:
'
'  A content scan of the disk needs to be scheduled for execution later.
'
%FILTER_S_CONTENTSCAN_DELAYED     = &H00041733

'
' MessageId: FILTER_E_CONTENTINDEXCORRUPT
'
' MessageText:
'
'  The content index is corrupt. A content scan will to be scheduled after chkdsk or autochk is run.
'
%FILTER_E_CONTENTINDEXCORRUPT     = &HC0041734

'
' MessageId: FILTER_S_DISK_FULL
'
' MessageText:
'
'  The disk is getting full.
'
%FILTER_S_DISK_FULL               = &H00041735

'
' MessageId: FILTER_E_ALREADY_OPEN
'
' MessageText:
'
'  A file is already open. Cannot open another one while a file is open.
'
%FILTER_E_ALREADY_OPEN            = &H80041736

'
' MessageId: FILTER_E_UNREACHABLE
'
' MessageText:
'
'  The file is not reachable.
'
%FILTER_E_UNREACHABLE             = &H80041737

'
' MessageId: FILTER_E_IN_USE
'
' MessageText:
'
'  The document is in use by another process.
'
%FILTER_E_IN_USE                  = &H80041738

'
' MessageId: FILTER_E_NOT_OPEN
'
' MessageText:
'
'  The document is not opened.
'
%FILTER_E_NOT_OPEN                = &H80041739

'
' MessageId: FILTER_S_NO_PROPSETS
'
' MessageText:
'
'  The document has no property sets.
'
%FILTER_S_NO_PROPSETS             = &H0004173A

'
' MessageId: FILTER_E_NO_SUCH_PROPERTY
'
' MessageText:
'
'  There is no property with the given GUID.
'
%FILTER_E_NO_SUCH_PROPERTY        = &H8004173B

'
' MessageId: FILTER_S_NO_SECURITY_DESCRIPTOR
'
' MessageText:
'
'  The document has no security descriptor.
'
%FILTER_S_NO_SECURITY_DESCRIPTOR  = &H0004173C

'
' MessageId: FILTER_E_OFFLINE
'
' MessageText:
'
'  The document is offline.
'
%FILTER_E_OFFLINE                 = &H8004173D

'
' MessageId: FILTER_E_PARTIALLY_FILTERED
'
' MessageText:
'
'  The document was too large to filter in its entirety.  Portions of the document were not emitted.
'
%FILTER_E_PARTIALLY_FILTERED      = &H8004173E

'
' Word breaker error codes
'
'
' MessageId: WBREAK_E_END_OF_TEXT
'
' MessageText:
'
'  End of text reached in text source.
'
%WBREAK_E_END_OF_TEXT             = &H80041780

'
' MessageId: LANGUAGE_S_LARGE_WORD
'
' MessageText:
'
'  Word larger than maximum length.  May be truncated by word sink.
'
%LANGUAGE_S_LARGE_WORD            = &H00041781

'
' MessageId: WBREAK_E_QUERY_ONLY
'
' MessageText:
'
'  Feature only available in query mode.
'
%WBREAK_E_QUERY_ONLY              = &H80041782

'
' MessageId: WBREAK_E_BUFFER_TOO_SMALL
'
' MessageText:
'
'  Buffer too small to hold composed phrase.
'
%WBREAK_E_BUFFER_TOO_SMALL        = &H80041783

'
' MessageId: LANGUAGE_E_DATABASE_NOT_FOUND
'
' MessageText:
'
'  Langauge database/cache file could not be found.
'
%LANGUAGE_E_DATABASE_NOT_FOUND    = &H80041784

'
' MessageId: WBREAK_E_INIT_FAILED
'
' MessageText:
'
'  Initialization of word breaker failed.
'
%WBREAK_E_INIT_FAILED             = &H80041785

'
' MessageId: PSINK_E_QUERY_ONLY
'
' MessageText:
'
'  Feature only available in query mode.
'
%PSINK_E_QUERY_ONLY               = &H80041790

'
' MessageId: PSINK_E_INDEX_ONLY
'
' MessageText:
'
'  Feature only available in index mode.
'
%PSINK_E_INDEX_ONLY               = &H80041791

'
' MessageId: PSINK_E_LARGE_ATTACHMENT
'
' MessageText:
'
'  Attachment type beyond valid range.
'
%PSINK_E_LARGE_ATTACHMENT         = &H80041792

'
' MessageId: PSINK_S_LARGE_WORD
'
' MessageText:
'
'  Word larger than maximum length.  May be truncated by phrase sink.
'
%PSINK_S_LARGE_WORD               = &H00041793

'
' Content Index Framework Error Codes
'
'
' MessageId: CI_CORRUPT_DATABASE
'
' MessageText:
'
'  The content index is corrupt.
'
%CI_CORRUPT_DATABASE              = &HC0041800

'
' MessageId: CI_CORRUPT_CATALOG
'
' MessageText:
'
'  The content index meta data is corrupt.
'
%CI_CORRUPT_CATALOG               = &HC0041801

'
' MessageId: CI_INVALID_PARTITION
'
' MessageText:
'
'  The content index partition is invalid.
'
%CI_INVALID_PARTITION             = &HC0041802

'
' MessageId: CI_INVALID_PRIORITY
'
' MessageText:
'
'  The priority is invalid.
'
%CI_INVALID_PRIORITY              = &HC0041803

'
' MessageId: CI_NO_STARTING_KEY
'
' MessageText:
'
'  There is no starting key.
'
%CI_NO_STARTING_KEY               = &HC0041804

'
' MessageId: CI_OUT_OF_INDEX_IDS
'
' MessageText:
'
'  The content index is out of index ids.
'
%CI_OUT_OF_INDEX_IDS              = &HC0041805

'
' MessageId: CI_NO_CATALOG
'
' MessageText:
'
'  There is no catalog.
'
%CI_NO_CATALOG                    = &HC0041806

'
' MessageId: CI_CORRUPT_FILTER_BUFFER
'
' MessageText:
'
'  The filter buffer is corrupt.
'
%CI_CORRUPT_FILTER_BUFFER         = &HC0041807

'
' MessageId: CI_INVALID_INDEX
'
' MessageText:
'
'  The index is invalid.
'
%CI_INVALID_INDEX                 = &HC0041808

'
' MessageId: CI_PROPSTORE_INCONSISTENCY
'
' MessageText:
'
'  Inconsistency in property store detected.
'
%CI_PROPSTORE_INCONSISTENCY       = &HC0041809

'
' MessageId: CI_E_ALREADY_INITIALIZED
'
' MessageText:
'
'  The object is already initialzed.
'
%CI_E_ALREADY_INITIALIZED         = &H8004180A

'
' MessageId: CI_E_NOT_INITIALIZED
'
' MessageText:
'
'  The object is not initialzed.
'
%CI_E_NOT_INITIALIZED             = &H8004180B

'
' MessageId: CI_E_BUFFERTOOSMALL
'
' MessageText:
'
'  The buffer is too small.
'
%CI_E_BUFFERTOOSMALL              = &H8004180C

'
' MessageId: CI_E_PROPERTY_NOT_CACHED
'
' MessageText:
'
'  The given property is not cached.
'
%CI_E_PROPERTY_NOT_CACHED         = &H8004180D

'
' MessageId: CI_S_WORKID_DELETED
'
' MessageText:
'
'  The workid is deleted.
'
%CI_S_WORKID_DELETED              = &H0004180E

'
' MessageId: CI_E_INVALID_STATE
'
' MessageText:
'
'  The object is not in a valid state.
'
%CI_E_INVALID_STATE               = &H8004180F

'
' MessageId: CI_E_FILTERING_DISABLED
'
' MessageText:
'
'  Filtering is disabled in this content index.
'
%CI_E_FILTERING_DISABLED          = &H80041810

'
' MessageId: CI_E_DISK_FULL
'
' MessageText:
'
'  The disk is full and the specified operation cannot be done.
'
%CI_E_DISK_FULL                   = &H80041811

'
' MessageId: CI_E_SHUTDOWN
'
' MessageText:
'
'  Content Index has been shutdown.
'
%CI_E_SHUTDOWN                    = &H80041812

'
' MessageId: CI_E_WORKID_NOTVALID
'
' MessageText:
'
'  The workid is not valid.
'
%CI_E_WORKID_NOTVALID             = &H80041813

'
' MessageId: CI_S_END_OF_ENUMERATION
'
' MessageText:
'
'  There are no more documents to enumerate.
'
%CI_S_END_OF_ENUMERATION          = &H00041814

'
' MessageId: CI_E_NOT_FOUND
'
' MessageText:
'
'  The object was not found.
'
%CI_E_NOT_FOUND                   = &H80041815

'
' MessageId: CI_E_USE_DEFAULT_PID
'
' MessageText:
'
'  The passed-in property id is not supported.
'
%CI_E_USE_DEFAULT_PID             = &H80041816

'
' MessageId: CI_E_DUPLICATE_NOTIFICATION
'
' MessageText:
'
'  There were two notifications for the same workid.
'
%CI_E_DUPLICATE_NOTIFICATION      = &H80041817

'
' MessageId: CI_E_UPDATES_DISABLED
'
' MessageText:
'
'  A document update was rejected because updates were disabled.
'
%CI_E_UPDATES_DISABLED            = &H80041818

'
' MessageId: CI_E_INVALID_FLAGS_COMBINATION
'
' MessageText:
'
'  The combination of flags specified is invalid.
'
%CI_E_INVALID_FLAGS_COMBINATION   = &H80041819

'
' MessageId: CI_E_OUTOFSEQ_INCREMENT_DATA
'
' MessageText:
'
'  The incremental data given to Load is not valid. It may be out of sequence.
'
%CI_E_OUTOFSEQ_INCREMENT_DATA     = &H8004181A

'
' MessageId: CI_E_SHARING_VIOLATION
'
' MessageText:
'
'  A sharing or locking violation caused a failure.
'
%CI_E_SHARING_VIOLATION           = &H8004181B

'
' MessageId: CI_E_LOGON_FAILURE
'
' MessageText:
'
'  A logon permission violation caused a failure.
'
%CI_E_LOGON_FAILURE               = &H8004181C

'
' MessageId: CI_E_NO_CATALOG
'
' MessageText:
'
'  There is no catalog.
'
%CI_E_NO_CATALOG                  = &H8004181D

'
' MessageId: CI_E_STRANGE_PAGEORSECTOR_SIZE
'
' MessageText:
'
'  Page size is not an integral multiple of the sector size of the volume where index is located.
'
%CI_E_STRANGE_PAGEORSECTOR_SIZE   = &H8004181E

'
' MessageId: CI_E_TIMEOUT
'
' MessageText:
'
'  Service is too busy.
'
%CI_E_TIMEOUT                     = &H8004181F

'
' MessageId: CI_E_NOT_RUNNING
'
' MessageText:
'
'  Service is not running.
'
%CI_E_NOT_RUNNING                 = &H80041820

'
' MessageId: CI_INCORRECT_VERSION
'
' MessageText:
'
'  The content index data on disk is for the wrong version.
'
%CI_INCORRECT_VERSION             = &HC0041821

'
' MessageId: CI_E_ENUMERATION_STARTED
'
' MessageText:
'
'  Enumeration has already been started for this query.
'
%CI_E_ENUMERATION_STARTED         = &HC0041822

'
' MessageId: CI_E_PROPERTY_TOOLARGE
'
' MessageText:
'
'  The specified variable length property is too large for the property cache.
'
%CI_E_PROPERTY_TOOLARGE           = &HC0041823

'
' MessageId: CI_E_CLIENT_FILTER_ABORT
'
' MessageText:
'
'  Filtering of object was aborted by client.
'
%CI_E_CLIENT_FILTER_ABORT         = &HC0041824

'
' MessageId: CI_S_NO_DOCSTORE
'
' MessageText:
'
'  For administrative connections from client without association to a docstore.
'
%CI_S_NO_DOCSTORE                 = &H00041825

'
' MessageId: CI_S_CAT_STOPPED
'
' MessageText:
'
'  The catalog has been stopped.
'
%CI_S_CAT_STOPPED                 = &H00041826

'
' MessageId: CI_E_CARDINALITY_MISMATCH
'
' MessageText:
'
'  Mismatch in cardinality of machine(s)/catalog(s)/scope(s).
'
%CI_E_CARDINALITY_MISMATCH        = &H80041827

'
' MessageId: CI_E_CONFIG_DISK_FULL
'
' MessageText:
'
'  The disk has reached its configured space limit.
'
%CI_E_CONFIG_DISK_FULL            = &H80041828
