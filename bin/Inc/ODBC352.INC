' ########################################################################################
' ODBC352.INC - Constants, types and declares of the ODC API.
' ########################################################################################

'#IF NOT %DEF(%ODBC352_INC)
    %ODBC352_INC = 1

   '#IF NOT %DEF(%WINAPI)
   '    #INCLUDE "WIN32API.INC"
   '#ENDIF

'//-----------------------------------------------------------------------------
'// File:      sqltypes.h
'//
'// Copyright:    Copyright (c) Microsoft Corporation
'//
'// Contents:     This file defines the types used in ODBC
'//
'//-----------------------------------------------------------------------------

%ODBCVER = &H0352

TYPE DATE_STRUCT
   year  AS INTEGER
   month AS WORD
   day   AS WORD
END TYPE

TYPE TIME_STRUCT
   hour   AS WORD
   minute AS WORD
   second AS WORD
END TYPE

Type TIMESTAMP_STRUCT
   year     As Integer 
   month    As Word 
   day      As Word 
   hour     As Word 
   minute   As Word 
   second   As Word 
   fraction As DWord 
End Type 

'/*
' * enumerations for DATETIME_INTERVAL_SUBCODE values for interval data types
' * these values are from SQL-92
' */

%SQL_IS_YEAR             = 1
%SQL_IS_MONTH            = 2
%SQL_IS_DAY              = 3
%SQL_IS_HOUR             = 4
%SQL_IS_MINUTE           = 5
%SQL_IS_SECOND           = 6
%SQL_IS_YEAR_TO_MONTH    = 7
%SQL_IS_DAY_TO_HOUR      = 8
%SQL_IS_DAY_TO_MINUTE    = 9
%SQL_IS_DAY_TO_SECOND    = 10
%SQL_IS_HOUR_TO_MINUTE   = 11
%SQL_IS_HOUR_TO_SECOND   = 12
%SQL_IS_MINUTE_TO_SECOND = 13

TYPE SQL_YEAR_MONTH
   year  AS DWORD
   month AS DWORD
END TYPE

TYPE SQL_DAY_SECOND
   day      AS DWORD
   hour     AS DWORD
   minute   AS DWORD
   second   AS DWORD
   fraction AS DWORD
END TYPE

UNION SQL_INTERVAL_UNION
   year_month AS SQL_YEAR_MONTH
   day_second AS SQL_DAY_SECOND
END UNION

TYPE SQL_INTERVAL_STRUCT
   Interval_type AS LONG
   interval_sign AS INTEGER
   intval        AS string * 20 'SQL_INTERVAL_UNION
END TYPE

'/* internal representation of numeric data type */
%SQL_MAX_NUMERIC_LEN     = 16

TYPE SQL_NUMERIC_STRUCT
   precision                    AS BYTE
   scale                        AS BYTE
   sign                         AS BYTE
'   value (%SQL_MAX_NUMERIC_LEN) AS BYTE
   value AS STRING * %SQL_MAX_NUMERIC_LEN
END TYPE

TYPE SQLGUID
  Data1 AS DWORD
  Data2 AS WORD
  Data3 AS WORD
  Data4 AS STRING * 8
END TYPE

'//-----------------------------------------------------------------------------
'// File:      sql.h
'//
'// Copyright:    Copyright (c) Microsoft Corporation
'//
'// Contents:     This is the the main include for ODBC Core functions.
'//
'// Comments:     preconditions: #include "windows.h"
'//
'//-----------------------------------------------------------------------------

'/* special length/indicator values */
%SQL_NULL_DATA    = -1
%SQL_DATA_AT_EXEC = -2

'/* return values from functions */
%SQL_SUCCESS           = 0
%SQL_SUCCESS_WITH_INFO = 1
%SQL_NO_DATA           = 100
%SQL_ERROR             = -1
%SQL_INVALID_HANDLE    = -2
%SQL_STILL_EXECUTING   = 2
%SQL_NEED_DATA         = 99

'/* test for SQL_SUCCESS or SQL_SUCCESS_WITH_INFO */
'#define SQL_SUCCEEDED(rc) (((rc)&(~1))==0)
'MACRO SQL_SUCCEEDED (rc) = -BITS&((rc = 0) OR (rc = 1))
Function SQL_SUCCEEDED(ByVal rc As Integer) As Long
  Function = (rc = 0) Or (rc = 1)
End Function

'/* flags for null-terminated string */
%SQL_NTS  = -3
%SQL_NTSL = -3&

'/* maximum message length */
%SQL_MAX_MESSAGE_LENGTH = 512

'/* date/time length constants */
%SQL_DATE_LEN      = 10
%SQL_TIME_LEN      = 8  '/* add P+1 if precision is nonzero */
%SQL_TIMESTAMP_LEN = 19  '/* add P+1 if precision is nonzero */

'/* handle type identifiers */
%SQL_HANDLE_ENV  = 1
%SQL_HANDLE_DBC  = 2
%SQL_HANDLE_STMT = 3
%SQL_HANDLE_DESC = 4

'/* environment attribute */
%SQL_ATTR_OUTPUT_NTS = 10001

'/* connection attributes */
%SQL_ATTR_AUTO_IPD    = 10001
%SQL_ATTR_METADATA_ID = 10014

'/* statement attributes */
%SQL_ATTR_APP_ROW_DESC       = 10010
%SQL_ATTR_APP_PARAM_DESC     = 10011
%SQL_ATTR_IMP_ROW_DESC       = 10012
%SQL_ATTR_IMP_PARAM_DESC     = 10013
%SQL_ATTR_CURSOR_SCROLLABLE  = -1
%SQL_ATTR_CURSOR_SENSITIVITY = -2

'/* SQL_ATTR_CURSOR_SCROLLABLE values */
%SQL_NONSCROLLABLE = 0
%SQL_SCROLLABLE    = 1

'/* identifiers of fields in the SQL descriptor */
%SQL_DESC_COUNT                  = 1001
%SQL_DESC_TYPE                   = 1002
%SQL_DESC_LENGTH                 = 1003
%SQL_DESC_OCTET_LENGTH_PTR       = 1004
%SQL_DESC_PRECISION              = 1005
%SQL_DESC_SCALE                  = 1006
%SQL_DESC_DATETIME_INTERVAL_CODE = 1007
%SQL_DESC_NULLABLE               = 1008
%SQL_DESC_INDICATOR_PTR          = 1009
%SQL_DESC_DATA_PTR               = 1010
%SQL_DESC_NAME                   = 1011
%SQL_DESC_UNNAMED                = 1012
%SQL_DESC_OCTET_LENGTH           = 1013
%SQL_DESC_ALLOC_TYPE             = 1099

'/* identifiers of fields in the diagnostics area */
%SQL_DIAG_RETURNCODE            = 1
%SQL_DIAG_NUMBER                = 2
%SQL_DIAG_ROW_COUNT             = 3
%SQL_DIAG_SQLSTATE              = 4
%SQL_DIAG_NATIVE                = 5
%SQL_DIAG_MESSAGE_TEXT          = 6
%SQL_DIAG_DYNAMIC_FUNCTION      = 7
%SQL_DIAG_CLASS_ORIGIN          = 8
%SQL_DIAG_SUBCLASS_ORIGIN       = 9
%SQL_DIAG_CONNECTION_NAME       = 10
%SQL_DIAG_SERVER_NAME           = 11
%SQL_DIAG_DYNAMIC_FUNCTION_CODE = 12

'/* dynamic function codes */
%SQL_DIAG_ALTER_TABLE           = 4
%SQL_DIAG_CREATE_INDEX          = -1
%SQL_DIAG_CREATE_TABLE          = 77
%SQL_DIAG_CREATE_VIEW           = 84
%SQL_DIAG_DELETE_WHERE          = 19
%SQL_DIAG_DROP_INDEX            = -2
%SQL_DIAG_DROP_TABLE            = 32
%SQL_DIAG_DROP_VIEW             = 36
%SQL_DIAG_DYNAMIC_DELETE_CURSOR = 38
%SQL_DIAG_DYNAMIC_UPDATE_CURSOR = 81
%SQL_DIAG_GRANT                 = 48
%SQL_DIAG_INSERT                = 50
%SQL_DIAG_REVOKE                = 59
%SQL_DIAG_SELECT_CURSOR         = 85
%SQL_DIAG_UNKNOWN_STATEMENT     = 0
%SQL_DIAG_UPDATE_WHERE          = 82

'/* SQL data type codes */
%SQL_UNKNOWN_TYPE = 0
%SQL_CHAR         = 1
%SQL_NUMERIC      = 2
%SQL_DECIMAL      = 3
%SQL_INTEGER      = 4
%SQL_SMALLINT     = 5
%SQL_FLOAT        = 6
%SQL_REAL         = 7
%SQL_DOUBLE       = 8
%SQL_DATETIME     = 9
%SQL_VARCHAR      = 12

'/* One-parameter shortcuts for date/time data types */
%SQL_TYPE_DATE      = 91
%SQL_TYPE_TIME      = 92
%SQL_TYPE_TIMESTAMP = 93

'/* Statement attribute values for cursor sensitivity */
%SQL_UNSPECIFIED = 0
%SQL_INSENSITIVE = 1
%SQL_SENSITIVE   = 2

'/* GetTypeInfo() request for all data types */
%SQL_ALL_TYPES = 0

'/* Default conversion code for SQLBindCol(), SQLBindParam() and SQLGetData() */
%SQL_DEFAULT = 99

'/* SQLGetData() code indicating that the application row descriptor
' * specifies the data type
' */
%SQL_ARD_TYPE = -99

'/* SQL date/time type subcodes */
%SQL_CODE_DATE      = 1
%SQL_CODE_TIME      = 2
%SQL_CODE_TIMESTAMP = 3

'/* CLI option values */
%SQL_FALSE = 0
%SQL_TRUE  = 1

'/* values of NULLABLE field in descriptor */
%SQL_NO_NULLS = 0
%SQL_NULLABLE = 1

'/* Value returned by SQLGetTypeInfo() to denote that it is
' * not known whether or not a data type supports null values.
' */
%SQL_NULLABLE_UNKNOWN = 2

'/* Values returned by SQLGetTypeInfo() to show WHERE clause
' * supported
' */
%SQL_PRED_NONE  = 0
%SQL_PRED_CHAR  = 1
%SQL_PRED_BASIC = 2

'/* values of UNNAMED field in descriptor */
%SQL_NAMED   = 0
%SQL_UNNAMED = 1

'/* values of ALLOC_TYPE field in descriptor */
%SQL_DESC_ALLOC_AUTO = 1
%SQL_DESC_ALLOC_USER = 2

'/* FreeStmt() options */
%SQL_CLOSE        = 0
%SQL_DROP         = 1
%SQL_UNBIND       = 2
%SQL_RESET_PARAMS = 3

'/* Codes used for FetchOrientation in SQLFetchScroll(),
'   and in SQLDataSources()
'*/
%SQL_FETCH_NEXT  = 1
%SQL_FETCH_FIRST = 2

'/* Other codes used for FetchOrientation in SQLFetchScroll() */
%SQL_FETCH_LAST     = 3
%SQL_FETCH_PRIOR    = 4
%SQL_FETCH_ABSOLUTE = 5
%SQL_FETCH_RELATIVE = 6

'/* SQLEndTran() options */
%SQL_COMMIT   = 0
%SQL_ROLLBACK = 1

'/* null handles returned by SQLAllocHandle() */
%SQL_NULL_HENV  = 0
%SQL_NULL_HDBC  = 0
%SQL_NULL_HSTMT = 0
%SQL_NULL_HDESC = 0

'/* null handle used in place of parent handle when allocating HENV */
%SQL_NULL_HANDLE = 0&

'/* Values that may appear in the result set of SQLSpecialColumns() */
%SQL_SCOPE_CURROW      = 0
%SQL_SCOPE_TRANSACTION = 1
%SQL_SCOPE_SESSION     = 2

%SQL_PC_UNKNOWN        = 0
%SQL_PC_NON_PSEUDO     = 1
%SQL_PC_PSEUDO         = 2

'/* Reserved value for the IdentifierType argument of SQLSpecialColumns() */
%SQL_ROW_IDENTIFIER = 1

'/* Reserved values for UNIQUE argument of SQLStatistics() */
%SQL_INDEX_UNIQUE = 0
%SQL_INDEX_ALL    = 1

'/* Values that may appear in the result set of SQLStatistics() */
%SQL_INDEX_CLUSTERED = 1
%SQL_INDEX_HASHED    = 2
%SQL_INDEX_OTHER     = 3

'/* SQLGetFunctions() values to identify ODBC APIs */
%SQL_API_SQLALLOCCONNECT     = 1
%SQL_API_SQLALLOCENV         = 2
%SQL_API_SQLALLOCHANDLE      = 1001
%SQL_API_SQLALLOCSTMT        = 3
%SQL_API_SQLBINDCOL          = 4
%SQL_API_SQLBINDPARAM        = 1002
%SQL_API_SQLCANCEL           = 5
%SQL_API_SQLCLOSECURSOR      = 1003
%SQL_API_SQLCOLATTRIBUTE     = 6
%SQL_API_SQLCOLUMNS          = 40
%SQL_API_SQLCONNECT          = 7
%SQL_API_SQLCOPYDESC         = 1004
%SQL_API_SQLDATASOURCES      = 57
%SQL_API_SQLDESCRIBECOL      = 8
%SQL_API_SQLDISCONNECT       = 9
%SQL_API_SQLENDTRAN          = 1005
%SQL_API_SQLERROR            = 10
%SQL_API_SQLEXECDIRECT       = 11
%SQL_API_SQLEXECUTE          = 12
%SQL_API_SQLFETCH            = 13
%SQL_API_SQLFETCHSCROLL      = 1021
%SQL_API_SQLFREECONNECT      = 14
%SQL_API_SQLFREEENV          = 15
%SQL_API_SQLFREEHANDLE       = 1006
%SQL_API_SQLFREESTMT         = 16
%SQL_API_SQLGETCONNECTATTR   = 1007
%SQL_API_SQLGETCONNECTOPTION = 42
%SQL_API_SQLGETCURSORNAME    = 17
%SQL_API_SQLGETDATA          = 43
%SQL_API_SQLGETDESCFIELD     = 1008
%SQL_API_SQLGETDESCREC       = 1009
%SQL_API_SQLGETDIAGFIELD     = 1010
%SQL_API_SQLGETDIAGREC       = 1011
%SQL_API_SQLGETENVATTR       = 1012
%SQL_API_SQLGETFUNCTIONS     = 44
%SQL_API_SQLGETINFO          = 45
%SQL_API_SQLGETSTMTATTR      = 1014
%SQL_API_SQLGETSTMTOPTION    = 46
%SQL_API_SQLGETTYPEINFO      = 47
%SQL_API_SQLNUMRESULTCOLS    = 18
%SQL_API_SQLPARAMDATA        = 48
%SQL_API_SQLPREPARE          = 19
%SQL_API_SQLPUTDATA          = 49
%SQL_API_SQLROWCOUNT         = 20
%SQL_API_SQLSETCONNECTATTR   = 1016
%SQL_API_SQLSETCONNECTOPTION = 50
%SQL_API_SQLSETCURSORNAME    = 21
%SQL_API_SQLSETDESCFIELD     = 1017
%SQL_API_SQLSETDESCREC       = 1018
%SQL_API_SQLSETENVATTR       = 1019
%SQL_API_SQLSETPARAM         = 22
%SQL_API_SQLSETSTMTATTR      = 1020
%SQL_API_SQLSETSTMTOPTION    = 51
%SQL_API_SQLSPECIALCOLUMNS   = 52
%SQL_API_SQLSTATISTICS       = 53
%SQL_API_SQLTABLES           = 54
%SQL_API_SQLTRANSACT         = 23

'/* Information requested by SQLGetInfo() */
%SQL_MAX_DRIVER_CONNECTIONS        = 0
%SQL_MAXIMUM_DRIVER_CONNECTIONS    = %SQL_MAX_DRIVER_CONNECTIONS
%SQL_MAX_CONCURRENT_ACTIVITIES     = 1
%SQL_MAXIMUM_CONCURRENT_ACTIVITIES = %SQL_MAX_CONCURRENT_ACTIVITIES
%SQL_DATA_SOURCE_NAME              = 2
%SQL_FETCH_DIRECTION               = 8
%SQL_SERVER_NAME                   = 13
%SQL_SEARCH_PATTERN_ESCAPE         = 14
%SQL_DBMS_NAME                     = 17
%SQL_DBMS_VER                      = 18
%SQL_ACCESSIBLE_TABLES             = 19
%SQL_ACCESSIBLE_PROCEDURES         = 20
%SQL_CURSOR_COMMIT_BEHAVIOR        = 23
%SQL_DATA_SOURCE_READ_ONLY         = 25
%SQL_DEFAULT_TXN_ISOLATION         = 26
%SQL_IDENTIFIER_CASE               = 28
%SQL_IDENTIFIER_QUOTE_CHAR         = 29
%SQL_MAX_COLUMN_NAME_LEN           = 30
%SQL_MAXIMUM_COLUMN_NAME_LENGTH    = %SQL_MAX_COLUMN_NAME_LEN
%SQL_MAX_CURSOR_NAME_LEN           = 31
%SQL_MAXIMUM_CURSOR_NAME_LENGTH    = %SQL_MAX_CURSOR_NAME_LEN
%SQL_MAX_SCHEMA_NAME_LEN           = 32
%SQL_MAXIMUM_SCHEMA_NAME_LENGTH    = %SQL_MAX_SCHEMA_NAME_LEN
%SQL_MAX_CATALOG_NAME_LEN          = 34
%SQL_MAXIMUM_CATALOG_NAME_LENGTH   = %SQL_MAX_CATALOG_NAME_LEN
%SQL_MAX_TABLE_NAME_LEN            = 35
%SQL_SCROLL_CONCURRENCY            = 43
%SQL_TXN_CAPABLE                   = 46
%SQL_TRANSACTION_CAPABLE           = %SQL_TXN_CAPABLE
%SQL_USER_NAME                     = 47
%SQL_TXN_ISOLATION_OPTION          = 72
%SQL_TRANSACTION_ISOLATION_OPTION  = %SQL_TXN_ISOLATION_OPTION
%SQL_INTEGRITY                     = 73
%SQL_GETDATA_EXTENSIONS            = 81
%SQL_NULL_COLLATION                = 85
%SQL_ALTER_TABLE                   = 86
%SQL_ORDER_BY_COLUMNS_IN_SELECT    = 90
%SQL_SPECIAL_CHARACTERS            = 94
%SQL_MAX_COLUMNS_IN_GROUP_BY       = 97
%SQL_MAXIMUM_COLUMNS_IN_GROUP_BY   = %SQL_MAX_COLUMNS_IN_GROUP_BY
%SQL_MAX_COLUMNS_IN_INDEX          = 98
%SQL_MAXIMUM_COLUMNS_IN_INDEX      = %SQL_MAX_COLUMNS_IN_INDEX
%SQL_MAX_COLUMNS_IN_ORDER_BY       = 99
%SQL_MAXIMUM_COLUMNS_IN_ORDER_BY   = %SQL_MAX_COLUMNS_IN_ORDER_BY
%SQL_MAX_COLUMNS_IN_SELECT         = 100
%SQL_MAXIMUM_COLUMNS_IN_SELECT     = %SQL_MAX_COLUMNS_IN_SELECT
%SQL_MAX_COLUMNS_IN_TABLE          = 101
%SQL_MAX_INDEX_SIZE                = 102
%SQL_MAXIMUM_INDEX_SIZE            = %SQL_MAX_INDEX_SIZE
%SQL_MAX_ROW_SIZE                  = 104
%SQL_MAXIMUM_ROW_SIZE              = %SQL_MAX_ROW_SIZE
%SQL_MAX_STATEMENT_LEN             = 105
%SQL_MAXIMUM_STATEMENT_LENGTH      = %SQL_MAX_STATEMENT_LEN
%SQL_MAX_TABLES_IN_SELECT          = 106
%SQL_MAXIMUM_TABLES_IN_SELECT      = %SQL_MAX_TABLES_IN_SELECT
%SQL_MAX_USER_NAME_LEN             = 107
%SQL_MAXIMUM_USER_NAME_LENGTH      = %SQL_MAX_USER_NAME_LEN
%SQL_OJ_CAPABILITIES               = 115
%SQL_OUTER_JOIN_CAPABILITIES       = %SQL_OJ_CAPABILITIES

%SQL_XOPEN_CLI_YEAR                = 10000
%SQL_CURSOR_SENSITIVITY            = 10001
%SQL_DESCRIBE_PARAMETER            = 10002
%SQL_CATALOG_NAME                  = 10003
%SQL_COLLATION_SEQ                 = 10004
%SQL_MAX_IDENTIFIER_LEN            = 10005
%SQL_MAXIMUM_IDENTIFIER_LENGTH     = %SQL_MAX_IDENTIFIER_LEN

'/* SQL_ALTER_TABLE bitmasks */
%SQL_AT_ADD_COLUMN     = &H00000001&
%SQL_AT_DROP_COLUMN    = &H00000002&
%SQL_AT_ADD_CONSTRAINT = &H00000008&

'/* SQL_ASYNC_MODE values */
%SQL_AM_NONE       = 0
%SQL_AM_CONNECTION = 1
%SQL_AM_STATEMENT  = 2

'/* SQL_CURSOR_COMMIT_BEHAVIOR values */
%SQL_CB_DELETE   = 0
%SQL_CB_CLOSE    = 1
%SQL_CB_PRESERVE = 2

'/* SQL_FETCH_DIRECTION bitmasks */
%SQL_FD_FETCH_NEXT     = &H00000001&
%SQL_FD_FETCH_FIRST    = &H00000002&
%SQL_FD_FETCH_LAST     = &H00000004&
%SQL_FD_FETCH_PRIOR    = &H00000008&
%SQL_FD_FETCH_ABSOLUTE = &H00000010&
%SQL_FD_FETCH_RELATIVE = &H00000020&

'/* SQL_GETDATA_EXTENSIONS bitmasks */
%SQL_GD_ANY_COLUMN = &H00000001&
%SQL_GD_ANY_ORDER  = &H00000002&

'/* SQL_IDENTIFIER_CASE values */
%SQL_IC_UPPER     = 1
%SQL_IC_LOWER     = 2
%SQL_IC_SENSITIVE = 3
%SQL_IC_MIXED     = 4

'/* SQL_OJ_CAPABILITIES bitmasks */
'/* NB: this means 'outer join', not what  you may be thinking */

%SQL_OJ_LEFT               = &H00000001&
%SQL_OJ_RIGHT              = &H00000002&
%SQL_OJ_FULL               = &H00000004&
%SQL_OJ_NESTED             = &H00000008&
%SQL_OJ_NOT_ORDERED        = &H00000010&
%SQL_OJ_INNER              = &H00000020&
%SQL_OJ_ALL_COMPARISON_OPS = &H00000040&

'/* SQL_SCROLL_CONCURRENCY bitmasks */
%SQL_SCCO_READ_ONLY  = &H00000001&
%SQL_SCCO_LOCK       = &H00000002&
%SQL_SCCO_OPT_ROWVER = &H00000004&
%SQL_SCCO_OPT_VALUES = &H00000008&

'/* SQL_TXN_CAPABLE values */
%SQL_TC_NONE       = 0
%SQL_TC_DML        = 1
%SQL_TC_ALL        = 2
%SQL_TC_DDL_COMMIT = 3
%SQL_TC_DDL_IGNORE = 4

'/* SQL_TXN_ISOLATION_OPTION bitmasks */
%SQL_TXN_READ_UNCOMMITTED         = &H00000001&
%SQL_TRANSACTION_READ_UNCOMMITTED = %SQL_TXN_READ_UNCOMMITTED
%SQL_TXN_READ_COMMITTED           = &H00000002&
%SQL_TRANSACTION_READ_COMMITTED   = %SQL_TXN_READ_COMMITTED
%SQL_TXN_REPEATABLE_READ          = &H00000004&
%SQL_TRANSACTION_REPEATABLE_READ  = %SQL_TXN_REPEATABLE_READ
%SQL_TXN_SERIALIZABLE             = &H00000008&
%SQL_TRANSACTION_SERIALIZABLE     = %SQL_TXN_SERIALIZABLE

'/* SQL_NULL_COLLATION values */
%SQL_NC_HIGH = 0
%SQL_NC_LOW  = 1


' ========================================================================================
' In ODBC 3.x, the ODBC 2.x function SQLAllocConnect has been replaced by SQLAllocHandle.
' ========================================================================================
' SQLRETURN  SQL_API SQLAllocConnect(SQLHENV EnvironmentHandle,
'            SQLHDBC *ConnectionHandle);
' ========================================================================================
DECLARE FUNCTION SQLAllocConnect LIB "ODBC32.DLL" ALIAS "SQLAllocConnect" ( _
        BYVAL EnvironmentHandle AS DWORD, _
        BYREF ConnectionHandle AS DWORD _
        ) AS INTEGER

' ========================================================================================
' In ODBC 3.x, the ODBC 2.x function SQLAllocEnv has been replaced by SQLAllocHandle.
' ========================================================================================
' SQLRETURN  SQL_API SQLAllocEnv(SQLHENV *EnvironmentHandle);
' ========================================================================================
DECLARE FUNCTION SQLAllocEnv LIB "ODBC32.DLL" ALIAS "SQLAllocEnv" ( _
        BYREF EnvironmentHandle AS DWORD _
        ) AS INTEGER

' ========================================================================================
' Allocates an environment, connection, statement, or descriptor handle.
' ========================================================================================
' SQLRETURN  SQL_API SQLAllocHandle(SQLSMALLINT HandleType,
'            SQLHANDLE InputHandle, SQLHANDLE *OutputHandle);
' ========================================================================================
DECLARE FUNCTION SQLAllocHandle LIB "ODBC32.DLL" ALIAS "SQLAllocHandle" ( _
        BYVAL HandleType   AS INTEGER, _
        BYVAL InputHandle  AS DWORD, _
        BYREF OutPutHandle AS DWORD _
        ) AS INTEGER

' ========================================================================================
' In ODBC 3.x, the ODBC 2.x function SQLAllocStmt has been replaced by SQLAllocHandle.
' ========================================================================================
' SQLRETURN  SQL_API SQLAllocStmt(SQLHDBC ConnectionHandle,
'            SQLHSTMT *StatementHandle);
' ========================================================================================
DECLARE FUNCTION SQLAllocStmt LIB "ODBC32.DLL" ALIAS "SQLAllocStmt" ( _
        BYVAL ConnectionHandle AS DWORD, _
        BYREF StatementHandle  AS DWORD _
        ) AS INTEGER

' ========================================================================================
' Binds application data buffers to columns in the result set.
' ========================================================================================
' SQLRETURN  SQL_API SQLBindCol(SQLHSTMT StatementHandle,
'            SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
'            SQLPOINTER TargetValue, SQLLEN BufferLength,
'            SQLLEN *StrLen_or_Ind);
' ========================================================================================
DECLARE FUNCTION SQLBindCol LIB "ODBC32.DLL" ALIAS "SQLBindCol" ( _
        BYVAL StatementHandle  AS DWORD, _
        BYVAL ColumnNumber     AS INTEGER, _
        BYVAL TargetType       AS INTEGER, _
        BYREF TargetValue      AS ANY, _
        BYVAL BufferLength     AS LONG, _
        BYREF StrLen_or_Ind    AS LONG _
        ) AS INTEGER

' ========================================================================================
' When the underlying driver is an ODBC 3.x driver, SQLBindParam will be mapped on top of
' SQLBindParameter.
' ========================================================================================
' SQLRETURN  SQL_API SQLBindParam(SQLHSTMT StatementHandle,
'            SQLUSMALLINT ParameterNumber, SQLSMALLINT ValueType,
'            SQLSMALLINT ParameterType, SQLULEN LengthPrecision,
'            SQLSMALLINT ParameterScale, SQLPOINTER ParameterValue,
'            SQLLEN *StrLen_or_Ind);
' ========================================================================================
DECLARE FUNCTION SQLBindParam LIB "ODBC32.DLL" ALIAS "SQLBindParam" ( _
        BYVAL StatementHandle AS DWORD, _
        BYVAL ParameterNumber AS INTEGER, _
        BYVAL ValueType       AS INTEGER, _
        BYVAL ParameterType   AS INTEGER, _
        BYVAL LengthPrecision AS DWORD, _
        BYVAL ParameterScale  AS INTEGER, _
        BYREF ParameterValue  AS ANY, _
        BYREF StrLen_or_Ind   AS LONG _
        ) AS INTEGER

' ========================================================================================
' Cancels the processing on a statement.
' ========================================================================================
' SQLRETURN  SQL_API SQLCancel(SQLHSTMT StatementHandle);
' ========================================================================================
DECLARE FUNCTION SQLCancel LIB "ODBC32.DLL" ALIAS "SQLCancel" ( _
        BYVAL StatementHandle AS DWORD _
        ) AS INTEGER

' ========================================================================================
' Closes a cursor that has been opened on a statement and discards pending results.
' ========================================================================================
' SQLRETURN  SQL_API SQLCloseCursor(SQLHSTMT StatementHandle);
' ========================================================================================
DECLARE FUNCTION SQLCloseCursor LIB "ODBC32.DLL" ALIAS "SQLCloseCursor" ( _
        BYVAL StaementHandle AS DWORD _
        ) AS INTEGER

' ========================================================================================
' Returns descriptor information for a column in a result set. Descriptor information is
' returned as a character string, a 32-bit descriptor-dependent value, or an integer value.
' ========================================================================================
' SQLRETURN  SQL_API SQLColAttribute (SQLHSTMT StatementHandle,
'            SQLUSMALLINT ColumnNumber, SQLUSMALLINT FieldIdentifier,
'            SQLPOINTER CharacterAttribute, SQLSMALLINT BufferLength,
'            SQLSMALLINT *StringLength, SQLPOINTER NumericAttribute);
' ========================================================================================
DECLARE FUNCTION SQLColAttribute LIB "ODBC32.DLL" ALIAS "SQLColAttribute" ( _
        BYVAL StatementHandle     AS DWORD, _
        BYVAL ColumnNumber        AS WORD, _
        BYVAL FieldIdentifier     AS WORD, _
        BYREF CharacterAttribute  AS ANY, _
        BYVAL BufferLength        AS INTEGER, _
        BYREF StringLength        AS INTEGER, _
        BYREF NumericAttribute    AS ANY _
        ) AS INTEGER

' ========================================================================================
' Returns the list of column names in specified tables. The driver returns this
' information as a result set on the specified StatementHandle.
' ========================================================================================
' SQLRETURN  SQL_API SQLColumns(SQLHSTMT StatementHandle,
'            SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
'            SQLCHAR *SchemaName, SQLSMALLINT NameLength2,
'            SQLCHAR *TableName, SQLSMALLINT NameLength3,
'            SQLCHAR *ColumnName, SQLSMALLINT NameLength4);
' ========================================================================================
DECLARE FUNCTION SQLColumns LIB "ODBC32.DLL" ALIAS "SQLColumns" ( _
        BYVAL StatementHandle AS DWORD, _
        BYREF CatalogName     AS ASCIIZ, _
        BYVAL NameLength1     AS INTEGER, _
        BYREF SchemaName      AS ASCIIZ, _
        BYVAL NameLength2     AS INTEGER, _
        BYREF TableName       AS ASCIIZ, _
        BYVAL NameLength3     AS INTEGER, _
        BYREF ColumnName      AS ASCIIZ, _
        BYVAL NameLength4     AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' Establishes connections to a driver and a data source. The connection handle references
' storage of all information about the connection to the data source, including status,
' transaction state, and error information.
' ========================================================================================
' SQLRETURN  SQL_API SQLConnect(SQLHDBC ConnectionHandle,
'            SQLCHAR *ServerName, SQLSMALLINT NameLength1,
'            SQLCHAR *UserName, SQLSMALLINT NameLength2,
'            SQLCHAR *Authentication, SQLSMALLINT NameLength3);
' ========================================================================================
DECLARE FUNCTION SQLConnect LIB "ODBC32.DLL" ALIAS "SQLConnect" ( _
        BYVAL ConnectionHandle AS DWORD, _
        BYREF ServerName       AS ASCIIZ, _
        BYVAL NameLength1      AS INTEGER, _
        BYREF UserName         AS ASCIIZ, _
        BYVAL NameLength2      AS INTEGER, _
        BYREF Authentication   AS ASCIIZ, _
        BYVAL NameLength3      AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' Copies descriptor information from one descriptor handle to another.
' ========================================================================================
' SQLRETURN  SQL_API SQLCopyDesc(SQLHDESC SourceDescHandle,
'            SQLHDESC TargetDescHandle);
'' ========================================================================================
DECLARE FUNCTION SQLCopyDesc LIB "ODBC32.DLL" ALIAS "SQLCopyDesc" ( _
        BYVAL SourceDescHandle AS DWORD, _
        BYVAL TargetDescHandle AS DWORD _
        ) AS INTEGER

' ========================================================================================
' Returns information about a data source. This function is implemented solely by the
' Driver Manager.
' ========================================================================================
' SQLRETURN  SQL_API SQLDataSources(SQLHENV EnvironmentHandle,
'            SQLUSMALLINT Direction, SQLCHAR *ServerName,
'            SQLSMALLINT BufferLength1, SQLSMALLINT *NameLength1,
'            SQLCHAR *Description, SQLSMALLINT BufferLength2,
'            SQLSMALLINT *NameLength2);
' ========================================================================================
DECLARE FUNCTION SQLDataSources LIB "ODBC32.DLL" ALIAS "SQLDataSources" ( _
        BYVAL EnvironmentHandle AS DWORD, _
        BYVAL Direction         AS WORD, _
        BYREF ServerName        AS ASCIIZ, _
        BYVAL BufferLength1     AS INTEGER, _
        BYREF NameLength1       AS INTEGER, _
        BYREF Description       AS ASCIIZ, _
        BYVAL BufferLength2     AS INTEGER, _
        BYREF NameLength2       AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' Returns the result descriptor -- column name, type, column size, decimal digits, and
' nullability -- for one column in the result set. This information also is available in
' the fields of the IRD.
' ========================================================================================
' SQLRETURN  SQL_API SQLDescribeCol(SQLHSTMT StatementHandle,
'            SQLUSMALLINT ColumnNumber, SQLCHAR *ColumnName,
'            SQLSMALLINT BufferLength, SQLSMALLINT *NameLength,
'            SQLSMALLINT *DataType, SQLULEN *ColumnSize,
'            SQLSMALLINT *DecimalDigits, SQLSMALLINT *Nullable);
' ========================================================================================
DECLARE FUNCTION SQLDescribeCol LIB "ODBC32.DLL" ALIAS "SQLDescribeCol" ( _
        BYVAL StatementHandle AS DWORD, _
        BYVAL ColumnNumber    AS WORD, _
        BYREF ColumnName      AS ASCIIZ, _
        BYVAL BufferLength    AS INTEGER, _
        BYREF NameLength      AS INTEGER, _
        BYREF DataType        AS INTEGER, _
        BYREF ColumnSize      AS DWORD, _
        BYREF DecimalDigits   AS INTEGER, _
        BYREF Nullable        AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' Closes the connection associated with a specific connection handle.
' ========================================================================================
' SQLRETURN  SQL_API SQLDisconnect(SQLHDBC ConnectionHandle);
' ========================================================================================
DECLARE FUNCTION SQLDisconnect LIB "ODBC32.DLL" ALIAS "SQLDisconnect" ( _
        BYVAL ConnectionHandle AS DWORD _
        ) AS INTEGER

' ========================================================================================
' Requests a commit or rollback operation for all active operations on all statements
' associated with a connection. SQLEndTran can also request that a commit or rollback
' operation be performed for all connections associated with an environment.
' ========================================================================================
' SQLRETURN  SQL_API SQLEndTran(SQLSMALLINT HandleType, SQLHANDLE Handle,
'            SQLSMALLINT CompletionType);
' ========================================================================================
DECLARE FUNCTION SQLEndTran LIB "ODBC32.DLL" ALIAS "SQLEndTran" ( _
        BYVAL HandleType     AS INTEGER, _
        BYVAL dwHandle       AS DWORD, _
        BYVAL CompletionType AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' Deprecated. Returns error or status information.
' ========================================================================================
' SQLRETURN  SQL_API SQLError(SQLHENV EnvironmentHandle,
'            SQLHDBC ConnectionHandle, SQLHSTMT StatementHandle,
'            SQLCHAR *Sqlstate, SQLINTEGER *NativeError,
'            SQLCHAR *MessageText, SQLSMALLINT BufferLength,
'            SQLSMALLINT *TextLength);
' ========================================================================================
DECLARE FUNCTION SQLError LIB "ODBC32.DLL" ALIAS "SQLError" ( _
        BYVAL EnvironmentHandle AS DWORD, _
        BYVAL ConnectionHandle  AS DWORD, _
        BYVAL StatementHandle   AS DWORD, _
        BYREF Sqlstate          AS ASCIIZ, _
        BYREF NativeError       AS LONG, _
        BYREF MessageText       AS ASCIIZ, _
        BYVAL BufferLength      AS INTEGER, _
        BYREF TextLength        AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' Executes a preparable statement, using the current values of the parameter marker
' variables if any parameters exist in the statement. SQLExecDirect is the fastest way to
' submit an SQL statement for one-time execution.
' ========================================================================================
' SQLRETURN  SQL_API SQLExecDirect(SQLHSTMT StatementHandle,
'            SQLCHAR *StatementText, SQLINTEGER TextLength);
' ========================================================================================
DECLARE FUNCTION SQLExecDirect LIB "ODBC32.DLL" ALIAS "SQLExecDirect" ( _
        BYVAL StatementHandle AS DWORD, _
        BYREF StatementText   AS ASCIIZ, _
        BYVAL TextLength      AS LONG _
        ) AS INTEGER

' ========================================================================================
' Executes a prepared statement, using the current values of the parameter marker
' variables if any parameter markers exist in the statement.
' ========================================================================================
' SQLRETURN  SQL_API SQLExecute(SQLHSTMT StatementHandle);
' ========================================================================================
DECLARE FUNCTION SQLExecute LIB "ODBC32.DLL" ALIAS "SQLExecute" ( _
        BYVAL StatementHandle AS DWORD _
        ) AS INTEGER

' ========================================================================================
' Fetches the next rowset of data from the result set and returns data for all bound
' columns.
' ========================================================================================
' SQLRETURN  SQL_API SQLFetch(SQLHSTMT StatementHandle);
' ========================================================================================
DECLARE FUNCTION SQLFetch LIB "ODBC32.DLL" ALIAS "SQLFetch" ( _
        BYVAL StatementHandle AS DWORD _
        ) AS INTEGER

' ========================================================================================
' Fetches the specified rowset of data from the result set and returns data for all bound
' columns. Rowsets can be specified at an absolute or relative position or by bookmark.
' ========================================================================================
' SQLRETURN  SQL_API SQLFetchScroll(SQLHSTMT StatementHandle,
'            SQLSMALLINT FetchOrientation, SQLLEN FetchOffset);
' ========================================================================================
DECLARE FUNCTION SQLFetchScroll LIB "ODBC32.DLL" ALIAS "SQLFetchScroll" ( _
        BYVAL StatementHandle  AS DWORD, _
        BYVAL FetchOrientation AS INTEGER, _
        BYVAL FetchOffset      AS LONG _
        ) AS INTEGER

' ========================================================================================
' Deprecated. In ODBC 3.x, the ODBC 2.0 function SQLFreeConnect has been replaced by
' SQLFreeHandle.
' ========================================================================================
' SQLRETURN  SQL_API SQLFreeConnect(SQLHDBC ConnectionHandle);
' ========================================================================================
DECLARE FUNCTION SQLFreeConnect LIB "ODBC32.DLL" ALIAS "SQLFreeConnect" ( _
        BYVAL ConnectionHandle AS DWORD _
        ) AS INTEGER

' ========================================================================================
' Deprecated. In ODBC 3.x, the ODBC 2.0 function SQLFreeEnv has been replaced by
' SQLFreeHandle.
' ========================================================================================
' SQLRETURN  SQL_API SQLFreeEnv(SQLHENV EnvironmentHandle);
' ========================================================================================
DECLARE FUNCTION SQLFreeEnv LIB "ODBC32.DLL" ALIAS "SQLFreeEnv" ( _
        BYVAL EnvironmentHandle AS DWORD _
        ) AS INTEGER

' ========================================================================================
' Frees resources associated with a specific environment, connection, statement, or
' descriptor handle.
' ========================================================================================
' SQLRETURN  SQL_API SQLFreeHandle(SQLSMALLINT HandleType, SQLHANDLE Handle);
' ========================================================================================
DECLARE FUNCTION SQLFreeHandle LIB "ODBC32.DLL" ALIAS "SQLFreeHandle" ( _
        BYVAL HandleType AS INTEGER, _
        BYVAL dwHandle   AS DWORD _
        ) AS INTEGER

' ========================================================================================
' Stops processing associated with a specific statement, closes any open cursors
' associated with the statement, discards pending results, or, optionally, frees all
' resources associated with the statement handle.
' ========================================================================================
' SQLRETURN  SQL_API SQLFreeStmt(SQLHSTMT StatementHandle,
'            SQLUSMALLINT Option);
' ========================================================================================
DECLARE FUNCTION SQLFreeStmt LIB "ODBC32.DLL" ALIAS "SQLFreeStmt" ( _
        BYVAL StatementHandle AS DWORD, _
        BYVAL wOption         AS WORD _
        ) AS INTEGER

' ========================================================================================
' Returns the current setting of a connection attribute.
' ========================================================================================
' SQLRETURN  SQL_API SQLGetConnectAttr(SQLHDBC ConnectionHandle,
'            SQLINTEGER Attribute, SQLPOINTER Value,
'            SQLINTEGER BufferLength, SQLINTEGER *StringLength);
' ========================================================================================
DECLARE FUNCTION SQLGetConnectAttr LIB "ODBC32.DLL" ALIAS "SQLGetConnectAttr" ( _
        BYVAL ConnectionHandle AS DWORD, _
        BYVAL Attribute        AS LONG, _
        BYREF Value            AS ANY, _
        BYVAL BufferLength     AS LONG, _
        BYREF StringLength     AS LONG _
        ) AS INTEGER

' ========================================================================================
' Deprecated. In ODBC 3.x, the ODBC 2.x function SQLGetConnectOption has been replaced by
' SQLGetConnectAttr.
' ========================================================================================
' SQLRETURN  SQL_API SQLGetConnectOption(SQLHDBC ConnectionHandle,
'            SQLUSMALLINT Option, SQLPOINTER Value);
' ========================================================================================
DECLARE FUNCTION SQLGetConnectOption LIB "ODBC32.DLL" ALIAS "SQLGetConnectOption" ( _
        BYVAL ConnectionHandle AS DWORD, _
        BYVAL wOption          AS WORD, _
        BYREF Value            AS ANY _
        ) AS INTEGER

' ========================================================================================
' Returns the cursor name associated with a specified statement.
' ========================================================================================
' SQLRETURN  SQL_API SQLGetCursorName(SQLHSTMT StatementHandle,
'            SQLCHAR *CursorName, SQLSMALLINT BufferLength,
'            SQLSMALLINT *NameLength);
' ========================================================================================
DECLARE FUNCTION SQLGetCursorName LIB "ODBC32.DLL" ALIAS "SQLGetCursorName" ( _
        BYVAL StatementHandle AS DWORD, _
        BYREF CursorName      AS ASCIIZ, _
        BYVAL BufferLength    AS INTEGER, _
        BYREF NameLength      AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' Retrieves data for a single column in the result set. It can be called multiple times to
' retrieve variable-length data in parts.
' ========================================================================================
' SQLRETURN  SQL_API SQLGetData(SQLHSTMT StatementHandle,
'            SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
'            SQLPOINTER TargetValue, SQLLEN BufferLength,
'            SQLLEN *StrLen_or_Ind);
' ========================================================================================
DECLARE FUNCTION SQLGetData LIB "ODBC32.DLL" ALIAS "SQLGetData" ( _
        BYVAL StatementHandle AS DWORD, _
        BYVAL ColumnNumber    AS WORD, _
        BYVAL TargetType      AS INTEGER, _
        BYREF TargetValue     AS ANY, _
        BYVAL BufferLength    AS LONG, _
        BYREF StrLen_or_Ind   AS LONG _
        ) AS INTEGER

' ========================================================================================
' Returns the current value of a field of a record of the diagnostic data structure
' (associated with a specified handle) that contains error, warning, and status
' information.
' ========================================================================================
' SQLRETURN  SQL_API SQLGetDescField(SQLHDESC DescriptorHandle,
'            SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,
'            SQLPOINTER Value, SQLINTEGER BufferLength,
'            SQLINTEGER *StringLength);
' ========================================================================================
DECLARE FUNCTION SQLGetDescField LIB "ODBC32.DLL" ALIAS "SQLGetDescField" ( _
        BYVAL DescriptorHandle AS DWORD, _
        BYVAL RecNumber        AS INTEGER, _
        BYVAL FieldIdentifier  AS INTEGER, _
        BYREF Value            AS ANY, _
        BYVAL BufferLength     AS LONG, _
        BYREF StringLength     AS LONG _
        ) AS INTEGER

' ========================================================================================
' Returns the current settings or values of multiple fields of a descriptor record. The
' fields returned describe the name, data type, and storage of column or parameter data.
' ========================================================================================
' SQLRETURN  SQL_API SQLGetDescRec(SQLHDESC DescriptorHandle,
'            SQLSMALLINT RecNumber, SQLCHAR *Name,
'            SQLSMALLINT BufferLength, SQLSMALLINT *StringLength,
'            SQLSMALLINT *Type, SQLSMALLINT *SubType,
'            SQLLEN     *Length, SQLSMALLINT *Precision,
'            SQLSMALLINT *Scale, SQLSMALLINT *Nullable);
' ========================================================================================
DECLARE FUNCTION SQLGetDescRec LIB "ODBC32.DLL" ALIAS "SQLGetDescRec" ( _
        BYVAL DescriptorHandle AS DWORD, _
        BYVAL RecNumber        AS INTEGER, _
        BYREF szName           AS ASCIIZ, _
        BYVAL BufferLength     AS INTEGER, _
        BYREF StringLength     AS INTEGER, _
        BYREF iType            AS INTEGER, _
        BYREF SubType          AS INTEGER, _
        BYREF Length           AS LONG, _
        BYREF Precision        AS INTEGER, _
        BYREF iScale           AS INTEGER, _
        BYREF Nullable         AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' Returns the current value of a field of a record of the diagnostic data structure
' (associated with a specified handle) that contains error, warning, and status
' information.
' ========================================================================================
' SQLRETURN  SQL_API SQLGetDiagField(SQLSMALLINT HandleType, SQLHANDLE Handle,
'            SQLSMALLINT RecNumber, SQLSMALLINT DiagIdentifier,
'            SQLPOINTER DiagInfo, SQLSMALLINT BufferLength,
'            SQLSMALLINT *StringLength);
' ========================================================================================
DECLARE FUNCTION SQLGetDiagField LIB "ODBC32.DLL" ALIAS "SQLGetDiagField" ( _
        BYVAL HandleType     AS INTEGER, _
        BYVAL dwHandle       AS DWORD, _
        BYVAL RecNumber      AS INTEGER, _
        BYVAL DiagIdentifier AS INTEGER, _
        BYREF DiagInfo       AS ANY, _
        BYVAL BufferLength   AS INTEGER, _
        BYREF StringLength   AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' Returns the current values of multiple fields of a diagnostic record that contains
' error, warning, and status information. Unlike SQLGetDiagField, which returns one
' diagnostic field per call, SQLGetDiagRec returns several commonly used fields of a
' diagnostic record, including the SQLSTATE, the native error code, and the diagnostic
' message text.
' ========================================================================================
' SQLRETURN  SQL_API SQLGetDiagRec(SQLSMALLINT HandleType, SQLHANDLE Handle,
'            SQLSMALLINT RecNumber, SQLCHAR *Sqlstate,
'            SQLINTEGER *NativeError, SQLCHAR *MessageText,
'            SQLSMALLINT BufferLength, SQLSMALLINT *TextLength);
' ========================================================================================
DECLARE FUNCTION SQLGetDiagRec LIB "ODBC32.DLL" ALIAS "SQLGetDiagRec" ( _
        BYVAL HandleType   AS INTEGER, _
        BYVAL dwHandle     AS DWORD, _
        BYVAL RecNumber    AS INTEGER, _
        BYREF Sqlstate     AS ASCIIZ, _
        BYREF NativeError  AS LONG, _
        BYREF MessageText  AS ASCIIZ, _
        BYVAL BufferLength AS INTEGER, _
        BYREF TextLength   AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' Returns the current setting of an environment attribute.
' ========================================================================================
' SQLRETURN  SQL_API SQLGetEnvAttr(SQLHENV EnvironmentHandle,
'            SQLINTEGER Attribute, SQLPOINTER Value,
'            SQLINTEGER BufferLength, SQLINTEGER *StringLength);
' ========================================================================================
DECLARE FUNCTION SQLGetEnvAttr LIB "ODBC32.DLL" ALIAS "SQLGetEnvAttr" ( _
        BYVAL EnvironmentHandle AS DWORD, _
        BYVAL Attribute         AS LONG, _
        BYREF Value             AS ANY, _
        BYVAL BufferLength      AS LONG, _
        BYREF StringLength      AS LONG _
        ) AS INTEGER

' ========================================================================================
' Returns information about whether a driver supports a specific ODBC function. This
' function is implemented in the Driver Manager; it can also be implemented in drivers.
' If a driver implements SQLGetFunctions, the Driver Manager calls the function in the
' driver. Otherwise, it executes the function itself.
' ========================================================================================
' SQLRETURN  SQL_API SQLGetFunctions(SQLHDBC ConnectionHandle,
'            SQLUSMALLINT FunctionId, SQLUSMALLINT *Supported);
' ========================================================================================
DECLARE FUNCTION SQLGetFunctions LIB "ODBC32.DLL" ALIAS "SQLGetFunctions" ( _
        BYVAL ConnectionHandle AS DWORD, _
        BYVAL FunctionId       AS WORD, _
        BYREF Supported        AS WORD _
        ) AS INTEGER

' ========================================================================================
' Returns general information about the driver and data source associated with a
' connection.
' ========================================================================================
' SQLRETURN  SQL_API SQLGetInfo(SQLHDBC ConnectionHandle,
'            SQLUSMALLINT InfoType, SQLPOINTER InfoValue,
'            SQLSMALLINT BufferLength, SQLSMALLINT *StringLength);
' ========================================================================================
DECLARE FUNCTION SQLGetInfo LIB "ODBC32.DLL" ALIAS "SQLGetInfo" ( _
        BYVAL ConnectionHandle AS DWORD, _
        BYVAL InfoType         AS WORD, _
        BYREF InfoValue        AS ANY, _
        BYVAL BufferLength     AS INTEGER, _
        BYREF StringLength     AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' Returns the current setting of a statement attribute.
' ========================================================================================
' SQLRETURN  SQL_API SQLGetStmtAttr(SQLHSTMT StatementHandle,
'            SQLINTEGER Attribute, SQLPOINTER Value,
'            SQLINTEGER BufferLength, SQLINTEGER *StringLength);
' ========================================================================================
DECLARE FUNCTION SQLGetStmtAttr LIB "ODBC32.DLL" ALIAS "SQLGetStmtAttr" ( _
        BYVAL StatementHandle AS DWORD, _
        BYVAL Attribute       AS LONG, _
        BYREF Value           AS ANY, _
        BYVAL BufferLength    AS LONG, _
        BYREF StringLength    AS LONG _
        ) AS INTEGER

' ========================================================================================
' Deprecated. In ODBC 3.x, the ODBC 2.0 function SQLGetStmtOption has been replaced by
' SQLGetStmtAttr.
' ========================================================================================
' SQLRETURN  SQL_API SQLGetStmtOption(SQLHSTMT StatementHandle,
'            SQLUSMALLINT Option, SQLPOINTER Value);
' ========================================================================================
DECLARE FUNCTION SQLGetStmtOption LIB "ODBC32.DLL" ALIAS "SQLGetStmtOption" ( _
        BYVAL StatementHandle AS DWORD, _
        BYVAL wOption         AS WORD, _
        BYREF Value           AS ANY _
        ) AS INTEGER

' ========================================================================================
' Returns information about data types supported by the data source. The driver returns
' the information in the form of an SQL result set. The data types are intended for use in
' Data Definition Language (DDL) statements.
' ========================================================================================
' SQLRETURN  SQL_API SQLGetTypeInfo(SQLHSTMT StatementHandle,
'            SQLSMALLINT DataType);
' ========================================================================================
DECLARE FUNCTION SQLGetTypeInfo LIB "ODBC32.DLL" ALIAS "SQLGetTypeInfo" ( _
        BYVAL StatementHandle AS DWORD, _
        BYVAL DataType        AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' Returns the number of columns in a result set.
' ========================================================================================
' SQLRETURN  SQL_API SQLNumResultCols(SQLHSTMT StatementHandle,
'            SQLSMALLINT *ColumnCount);
' ========================================================================================
DECLARE FUNCTION SQLNumResultCols LIB "ODBC32.DLL" ALIAS "SQLNumResultCols" ( _
        BYVAL StatementHandle AS DWORD, _
        BYREF ColumnCount     AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' Used in conjunction with SQLPutData to supply parameter data at statement execution time.
' ========================================================================================
' SQLRETURN  SQL_API SQLParamData(SQLHSTMT StatementHandle,
'            SQLPOINTER *Value);
' ========================================================================================
DECLARE FUNCTION SQLParamData LIB "ODBC32.DLL" ALIAS "SQLParamData" ( _
        BYVAL StatementHandle AS DWORD, _
        BYREF  Value           AS ANY _
        ) AS INTEGER

' ========================================================================================
' Prepares an SQL string for execution.
' ========================================================================================
' SQLRETURN  SQL_API SQLPrepare(SQLHSTMT StatementHandle,
'            SQLCHAR *StatementText, SQLINTEGER TextLength);
' ========================================================================================
DECLARE FUNCTION SQLPrepare LIB "ODBC32.DLL" ALIAS "SQLPrepare" ( _
        BYVAL StatementHandle AS DWORD, _
        BYREF StatementText   AS ASCIIZ, _
        BYVAL TextLength      AS LONG _
        ) AS INTEGER

' ========================================================================================
' Allows an application to send data for a parameter or column to the driver at statement
' execution time. This function can be used to send character or binary data values in
' parts to a column with a character, binary, or data source--specific data type (for
' example, parameters of the SQL_LONGVARBINARY or SQL_LONGVARCHAR types). SQLPutData
' supports binding to a Unicode C data type, even if the underlying driver does not
' support Unicode data.
' ========================================================================================
' SQLRETURN  SQL_API SQLPutData(SQLHSTMT StatementHandle,
'            SQLPOINTER Data, SQLLEN StrLen_or_Ind);
' ========================================================================================
DECLARE FUNCTION SQLPutData LIB "ODBC32.DLL" ALIAS "SQLPutData" ( _
        BYVAL StatementHandle AS DWORD, _
        BYREF pData           AS ANY, _
        BYVAL StrLen_or_Ind   AS LONG _
        ) AS INTEGER

' ========================================================================================
' Returns the number of rows affected by an UPDATE, INSERT, or DELETE statement; an
' SQL_ADD, SQL_UPDATE_BY_BOOKMARK, or SQL_DELETE_BY_BOOKMARK operation in
' SQLBulkOperations; or an SQL_UPDATE or SQL_DELETE operation in SQLSetPos.
' ========================================================================================
' SQLRETURN  SQL_API SQLRowCount(SQLHSTMT StatementHandle,
'            SQLLEN* RowCount);
' ========================================================================================
DECLARE FUNCTION SQLRowCount LIB "ODBC32.DLL" ALIAS "SQLRowCount" ( _
        BYVAL StatementHandle AS DWORD, _
        BYREF RowCount        AS LONG _
        ) AS INTEGER

' ========================================================================================
' Sets attributes that govern aspects of connections.
' ========================================================================================
' SQLRETURN  SQL_API SQLSetConnectAttr(SQLHDBC ConnectionHandle,
'            SQLINTEGER Attribute, SQLPOINTER Value,
'            SQLINTEGER StringLength);
' ========================================================================================
DECLARE FUNCTION SQLSetConnectAttr LIB "ODBC32.DLL" ALIAS "SQLSetConnectAttr" ( _
        BYVAL ConnectionHandle AS DWORD, _
        BYVAL Attribute        AS LONG, _
        BYREF Value            AS ANY, _
        BYVAL StringLength     AS LONG _
        ) AS INTEGER

' ========================================================================================
' Deprecated. In ODBC 3.x, the ODBC 2.0 function SQLSetConnectOption has been replaced by
' SQLSetConnectAttr.
' ========================================================================================
' SQLRETURN  SQL_API SQLSetConnectOption(SQLHDBC ConnectionHandle,
'            SQLUSMALLINT Option, SQLULEN Value);
' ========================================================================================
DECLARE FUNCTION SQLSetConnectOption LIB "ODBC32.DLL" ALIAS "SQLSetConnectOption" ( _
        BYVAL ConnectionHandle AS DWORD, _
        BYVAL wOption          AS WORD, _
        BYVAL Value            AS DWORD) AS INTEGER

' ========================================================================================
' Associates a cursor name with an active statement. If an application does not call
' SQLSetCursorName, the driver generates cursor names as needed for SQL statement
' processing.
' ========================================================================================
' SQLRETURN  SQL_API SQLSetCursorName(SQLHSTMT StatementHandle,
'            SQLCHAR *CursorName, SQLSMALLINT NameLength);
' ========================================================================================
DECLARE FUNCTION SQLSetCursorName LIB "ODBC32.DLL" ALIAS "SQLSetCursorName" ( _
        BYVAL StatementHandle AS DWORD, _
        BYREF CursorName      AS ASCIIZ, _
        BYVAL NameLength      AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' Sets the value of a single field of a descriptor record.
' ========================================================================================
' SQLRETURN  SQL_API SQLSetDescField(SQLHDESC DescriptorHandle,
'            SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,
'            SQLPOINTER Value, SQLINTEGER BufferLength);
' ========================================================================================
DECLARE FUNCTION SQLSetDescField LIB "ODBC32.DLL" ALIAS "SQLSetDescField" ( _
        BYVAL DescriptorHandle AS DWORD, _
        BYVAL RecNumber        AS INTEGER, _
        BYVAL FieldIdentifier  AS INTEGER, _
        BYREF Value            AS ANY, _
        BYVAL BufferLength     AS LONG _
        ) AS INTEGER

' ========================================================================================
' Sets multiple descriptor fields that affect the data type and buffer bound to a column
' or parameter data.
' ========================================================================================
' SQLRETURN  SQL_API SQLSetDescRec(SQLHDESC DescriptorHandle,
'            SQLSMALLINT RecNumber, SQLSMALLINT Type,
'            SQLSMALLINT SubType, SQLLEN Length,
'            SQLSMALLINT Precision, SQLSMALLINT Scale,
'            SQLPOINTER Data, SQLLEN *StringLength,
'            SQLLEN *Indicator);
' ========================================================================================
DECLARE FUNCTION SQLSetDescRec LIB "ODBC32.DLL" ALIAS "SQLSetDescRec" ( _
        BYVAL DescriptorHandle AS DWORD, _
        BYVAL RecNumber        AS INTEGER, _
        BYVAL iType            AS INTEGER, _
        BYVAL SubType          AS INTEGER, _
        BYVAL Length           AS LONG, _
        BYVAL Precision        AS INTEGER, _
        BYVAL iScale           AS INTEGER, _
        BYREF pData            AS ANY, _
        BYREF StringLength     AS LONG, _
        BYREF Indicator        AS LONG _
        ) AS INTEGER

' ========================================================================================
' Sets attributes that govern aspects of environments.
' ========================================================================================
' SQLRETURN  SQL_API SQLSetEnvAttr(SQLHENV EnvironmentHandle,
'            SQLINTEGER Attribute, SQLPOINTER Value,
'            SQLINTEGER StringLength);
' ========================================================================================
DECLARE FUNCTION SQLSetEnvAttr LIB "ODBC32.DLL" ALIAS "SQLSetEnvAttr" ( _
        BYVAL EnvironmentHandle AS DWORD, _
        BYVAL Attribute         AS LONG, _
        BYREF Value             AS ANY, _
        BYVAL StringLength      AS LONG _
        ) AS INTEGER

' ========================================================================================
' Deprecated. In ODBC 2.0, the ODBC 1.0 function SQLSetParam has been replaced by
' SQLBindParameter.
' ========================================================================================
' SQLRETURN  SQL_API SQLSetParam(SQLHSTMT StatementHandle,
'            SQLUSMALLINT ParameterNumber, SQLSMALLINT ValueType,
'            SQLSMALLINT ParameterType, SQLULEN LengthPrecision,
'            SQLSMALLINT ParameterScale, SQLPOINTER ParameterValue,
'            SQLLEN *StrLen_or_Ind);
' ========================================================================================
DECLARE FUNCTION SQLSetParam LIB "ODBC32.DLL" ALIAS "SQLSetParam" ( _
        BYVAL StatementHandle AS DWORD, _
        BYVAL ParameterNumber AS WORD, _
        BYVAL ValueType       AS INTEGER, _
        BYVAL ParameterType   AS INTEGER, _
        BYVAL LengthPrecision AS DWORD, _
        BYVAL ParameterScale  AS INTEGER, _
        BYREF ParameterValue  AS ANY, _
        BYREF StrLen_or_Ind   AS LONG _
        ) AS INTEGER

' ========================================================================================
' Sets attributes related to a statement.
' ========================================================================================
' SQLRETURN  SQL_API SQLSetStmtAttr(SQLHSTMT StatementHandle,
'            SQLINTEGER Attribute, SQLPOINTER Value,
'            SQLINTEGER StringLength);
' ========================================================================================
DECLARE FUNCTION SQLSetStmtAttr LIB "ODBC32.DLL" ALIAS "SQLSetStmtAttr" ( _
        BYVAL StatementHandle AS DWORD, _
        BYVAL Attribute       AS LONG, _
        BYREF Value           AS ANY, _
        BYVAL StringLength    AS LONG _
        ) AS INTEGER

' ========================================================================================
' Deprecated. In ODBC 3.x, the ODBC 2.0 function SQLSetStmtOption has been replaced by
' SQLSetStmtAttr.
' ========================================================================================
' SQLRETURN  SQL_API SQLSetStmtOption(SQLHSTMT StatementHandle,
'            SQLUSMALLINT Option, SQLULEN Value);
' ========================================================================================
DECLARE FUNCTION SQLSetStmtOption LIB "ODBC32.DLL" ALIAS "SQLSetStmtOption" ( _
        BYVAL StatementHandle AS DWORD, _
        BYVAL wOption         AS WORD, _
        BYVAL Value           AS DWORD _
        ) AS INTEGER

' ========================================================================================
' Retrieves the following information about columns within a specified table:
'    * The optimal set of columns that uniquely identifies a row in the table.
'    * Columns that are automatically updated when any value in the row is updated by a
'      transaction.
' ========================================================================================
' SQLRETURN  SQL_API SQLSpecialColumns(SQLHSTMT StatementHandle,
'            SQLUSMALLINT IdentifierType, SQLCHAR *CatalogName,
'            SQLSMALLINT NameLength1, SQLCHAR *SchemaName,
'            SQLSMALLINT NameLength2, SQLCHAR *TableName,
'            SQLSMALLINT NameLength3, SQLUSMALLINT Scope,
'            SQLUSMALLINT Nullable);
' ========================================================================================
DECLARE FUNCTION SQLSpecialColumns LIB "ODBC32.DLL" ALIAS "SQLSpecialColumns" ( _
        BYVAL StatementHandle AS DWORD, _
        BYVAL IdentifierType  AS WORD, _
        BYREF CatalogName     AS ASCIIZ, _
        BYVAL NameLength1     AS INTEGER, _
        BYREF SchemaName      AS ASCIIZ, _
        BYVAL Namelength2     AS INTEGER, _
        BYREF TableName       AS ASCIIZ, _
        BYVAL NameLength3     AS INTEGER, _
        BYVAL Scope           AS WORD, _
        BYVAL Nullable        AS WORD _
        ) AS INTEGER

' ========================================================================================
' Retrieves a list of statistics about a single table and the indexes associated with the
' table. The driver returns the information as a result set.
' ========================================================================================
' SQLRETURN  SQL_API SQLStatistics(SQLHSTMT StatementHandle,
'            SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
'            SQLCHAR *SchemaName, SQLSMALLINT NameLength2,
'            SQLCHAR *TableName, SQLSMALLINT NameLength3,
'            SQLUSMALLINT Unique, SQLUSMALLINT Reserved);
' ========================================================================================
DECLARE FUNCTION SQLStatistics LIB "ODBC32.DLL" ALIAS "SQLStatistics" ( _
        BYVAL StatementHandle AS DWORD, _
        BYREF CatalogName     AS ASCIIZ, _
        BYVAL NameLength1     AS INTEGER, _
        BYREF SchemaName      AS ASCIIZ, _
        BYVAL NameLength2     AS INTEGER, _
        BYREF TableName       AS ASCIIZ, _
        BYVAL Namelength3     AS INTEGER, _
        BYVAL Unique          AS WORD, _
        BYVAL Reserved        AS WORD _
        ) AS INTEGER

' ========================================================================================
' Returns the list of table, catalog, or schema names, and table types, stored in a
' specific data source. The driver returns the information as a result set.
' ========================================================================================
' SQLRETURN  SQL_API SQLTables(SQLHSTMT StatementHandle,
'            SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
'            SQLCHAR *SchemaName, SQLSMALLINT NameLength2,
'            SQLCHAR *TableName, SQLSMALLINT NameLength3,
'            SQLCHAR *TableType, SQLSMALLINT NameLength4);
' ========================================================================================
DECLARE FUNCTION SQLTables LIB "ODBC32.DLL" ALIAS "SQLTables" ( _
        BYVAL StatementHandle AS DWORD, _
        BYREF CatalogName     AS ASCIIZ, _
        BYVAL Namelength1     AS INTEGER, _
        BYREF SchemaName      AS ASCIIZ, _
        BYVAL NameLength2     AS INTEGER, _
        BYREF TableName       AS ASCIIZ, _
        BYVAL NameLength3     AS INTEGER, _
        BYREF TableType       AS ASCIIZ, _
        BYVAL NameLength4     AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' Deprecated. In ODBC 3.x, the ODBC 2.x function SQLTransact has been replaced by SQLEndTran.
' ========================================================================================
' SQLRETURN  SQL_API SQLTransact(SQLHENV EnvironmentHandle,
'            SQLHDBC ConnectionHandle, SQLUSMALLINT CompletionType);
' ========================================================================================
DECLARE FUNCTION SQLTransact LIB "ODBC32.DLL" ALIAS "SQLTransact" ( _
        BYVAL EnvironmentHandle AS DWORD, _
        BYVAL ConnectionHandle  AS DWORD, _
        BYVAL CompletionType    AS WORD _
        ) AS INTEGER
' ========================================================================================


'//-----------------------------------------------------------------------------
'// File:      sqlext.h
'//
'// Copyright:    Copyright (c) Microsoft Corporation
'//
'// Contents:     This is the include for applications using the Microsoft SQL Extensions
'//
'//-----------------------------------------------------------------------------

%SQL_LIKE_ONLY       = 1
%SQL_ALL_EXCEPT_LIKE = 2

'/* generally useful constants */
%SQL_SPEC_MAJOR = 3         '/* Major version of specification  */
%SQL_SPEC_MINOR = 52        '/* Minor version of specification  */
$SQL_SPEC_STRING = "03.52"  '/* String constant for version */

%SQL_SQLSTATE_SIZE  = 5   '/* size of SQLSTATE */
%SQL_MAX_DSN_LENGTH = 32  '/* maximum data source name size */

%SQL_MAX_OPTION_STRING_LENGTH = 256

'/* return code SQL_NO_DATA_FOUND is the same as SQL_NO_DATA */
%SQL_NO_DATA_FOUND = %SQL_NO_DATA

'/* an end handle type */
%SQL_HANDLE_SENV = 5

'/* env attribute */
%SQL_ATTR_ODBC_VERSION       = 200
%SQL_ATTR_CONNECTION_POOLING = 201
%SQL_ATTR_CP_MATCH           = 202

'/* values for SQL_ATTR_CONNECTION_POOLING */
%SQL_CP_OFF            = 0???
%SQL_CP_ONE_PER_DRIVER = 1???
%SQL_CP_ONE_PER_HENV   = 2???
%SQL_CP_DEFAULT        = %SQL_CP_OFF

'/* values for SQL_ATTR_CP_MATCH */
%SQL_CP_STRICT_MATCH  = 0???
%SQL_CP_RELAXED_MATCH = 1???
%SQL_CP_MATCH_DEFAULT = %SQL_CP_STRICT_MATCH

'/* values for SQL_ATTR_ODBC_VERSION */
%SQL_OV_ODBC2 = 2???
%SQL_OV_ODBC3 = 3???

'/* connection attributes */
%SQL_ACCESS_MODE       = 101
%SQL_AUTOCOMMIT        = 102
%SQL_LOGIN_TIMEOUT     = 103
%SQL_OPT_TRACE         = 104
%SQL_OPT_TRACEFILE     = 105
%SQL_TRANSLATE_DLL     = 106
%SQL_TRANSLATE_OPTION  = 107
%SQL_TXN_ISOLATION     = 108
%SQL_CURRENT_QUALIFIER = 109
%SQL_ODBC_CURSORS      = 110
%SQL_QUIET_MODE        = 111
%SQL_PACKET_SIZE       = 112

'/* connection attributes with new names */
%SQL_ATTR_ACCESS_MODE         = %SQL_ACCESS_MODE
%SQL_ATTR_AUTOCOMMIT          = %SQL_AUTOCOMMIT
%SQL_ATTR_CONNECTION_TIMEOUT  = 113
%SQL_ATTR_CURRENT_CATALOG     = %SQL_CURRENT_QUALIFIER
%SQL_ATTR_DISCONNECT_BEHAVIOR = 114
%SQL_ATTR_ENLIST_IN_DTC       = 1207
%SQL_ATTR_ENLIST_IN_XA        = 1208
%SQL_ATTR_LOGIN_TIMEOUT       = %SQL_LOGIN_TIMEOUT
%SQL_ATTR_ODBC_CURSORS        = %SQL_ODBC_CURSORS
%SQL_ATTR_PACKET_SIZE         = %SQL_PACKET_SIZE
%SQL_ATTR_QUIET_MODE          = %SQL_QUIET_MODE
%SQL_ATTR_TRACE               = %SQL_OPT_TRACE
%SQL_ATTR_TRACEFILE           = %SQL_OPT_TRACEFILE
%SQL_ATTR_TRANSLATE_LIB       = %SQL_TRANSLATE_DLL
%SQL_ATTR_TRANSLATE_OPTION    = %SQL_TRANSLATE_OPTION
%SQL_ATTR_TXN_ISOLATION       = %SQL_TXN_ISOLATION

%SQL_ATTR_CONNECTION_DEAD     = 1209  'ODBC 3.5 /* GetConnectAttr only */

'#if (ODBCVER >= 0x0351)
'/*   ODBC Driver Manager sets this connection attribute to a unicode driver
'   (which supports SQLConnectW) when the application is an ANSI application
'   (which calls SQLConnect, SQLDriverConnect, or SQLBrowseConnect).
'   This is SetConnectAttr only and application does not set this attribute
'   This attribute was introduced because some unicode driver's some APIs may
'   need to behave differently on ANSI or Unicode applications. A unicode
'   driver, which  has same behavior for both ANSI or Unicode applications,
'   should return SQL_ERROR when the driver manager sets this connection
'   attribute. When a unicode driver returns SQL_SUCCESS on this attribute,
'   the driver manager treates ANSI and Unicode connections differently in
'   connection pooling.
'*/
'#define SQL_ATTR_ANSI_APP         115
'#endif
%SQL_ATTR_ANSI_APP = 115

'/* SQL_CONNECT_OPT_DRVR_START is not meaningful for 3.0 driver */
'#if (ODBCVER < 0x0300)
'#define SQL_CONNECT_OPT_DRVR_START      1000
'#endif  /* ODBCVER < 0x0300 */

'#if (ODBCVER < 0x0300)
'%SQL_CONN_OPT_MAX                SQL_PACKET_SIZE
'%SQL_CONN_OPT_MIN                SQL_ACCESS_MODE
'#endif /* ODBCVER < 0x0300 */

'/* SQL_ACCESS_MODE options */
%SQL_MODE_READ_WRITE = 0???
%SQL_MODE_READ_ONLY  = 1???
%SQL_MODE_DEFAULT    = %SQL_MODE_READ_WRITE

'/* SQL_AUTOCOMMIT options */
%SQL_AUTOCOMMIT_OFF     = 0???
%SQL_AUTOCOMMIT_ON      = 1???
%SQL_AUTOCOMMIT_DEFAULT = %SQL_AUTOCOMMIT_ON

'/* SQL_LOGIN_TIMEOUT options */
%SQL_LOGIN_TIMEOUT_DEFAULT = 15???

'/* SQL_OPT_TRACE options */
%SQL_OPT_TRACE_OFF     = 0???
%SQL_OPT_TRACE_ON      = 1???
%SQL_OPT_TRACE_DEFAULT = %SQL_OPT_TRACE_OFF
$SQL_OPT_TRACE_FILE_DEFAULT = "\SQL.LOG"

'/* SQL_ODBC_CURSORS options */
%SQL_CUR_USE_IF_NEEDED = 0???
%SQL_CUR_USE_ODBC      = 1???
%SQL_CUR_USE_DRIVER    = 2???
%SQL_CUR_DEFAULT       = %SQL_CUR_USE_DRIVER

'/* values for SQL_ATTR_DISCONNECT_BEHAVIOR */
%SQL_DB_RETURN_TO_POOL = 0???
%SQL_DB_DISCONNECT     = 1???
%SQL_DB_DEFAULT        = %SQL_DB_RETURN_TO_POOL

'/* values for SQL_ATTR_ENLIST_IN_DTC */
%SQL_DTC_DONE = 0&

'/* values for SQL_ATTR_CONNECTION_DEAD */
%SQL_CD_FALSE                 = 0???  'ODBC 3.5 /* GetConnectAttr only */
%SQL_CD_TRUE                  = 1???  'ODBC 3.5 /* GetConnectAttr only */

'/* values for SQL_ATTR_ANSI_APP */
'#if (ODBCVER >= 0x0351)
'#define SQL_AA_TRUE               1L   /* the application is an ANSI app */
'#define SQL_AA_FALSE               0L   /* the application is a Unicode app */
'#endif
%SQL_AA_TRUE  = 1???   '/* the application is an ANSI app */
%SQL_AA_FALSE = 0???   '/* the application is a Unicode app */

'/* statement attributes */
%SQL_QUERY_TIMEOUT   = 0
%SQL_MAX_ROWS        = 1
%SQL_NOSCAN          = 2
%SQL_MAX_LENGTH      = 3
%SQL_ASYNC_ENABLE    = 4   '/* same as SQL_ATTR_ASYNC_ENABLE */
%SQL_BIND_TYPE       = 5
%SQL_CURSOR_TYPE     = 6
%SQL_CONCURRENCY     = 7
%SQL_KEYSET_SIZE     = 8
%SQL_ROWSET_SIZE     = 9
%SQL_SIMULATE_CURSOR = 10
%SQL_RETRIEVE_DATA   = 11
%SQL_USE_BOOKMARKS   = 12
%SQL_GET_BOOKMARK    = 13      '/*      GetStmtOption Only */
%SQL_ROW_NUMBER      = 14      '/*      GetStmtOption Only */

' statement attributes for ODBC 3.0 */
%SQL_ATTR_ASYNC_ENABLE          = 4
%SQL_ATTR_CONCURRENCY           = %SQL_CONCURRENCY
%SQL_ATTR_CURSOR_TYPE           = %SQL_CURSOR_TYPE
%SQL_ATTR_ENABLE_AUTO_IPD       = 15
%SQL_ATTR_FETCH_BOOKMARK_PTR    = 16
%SQL_ATTR_KEYSET_SIZE           = %SQL_KEYSET_SIZE
%SQL_ATTR_MAX_LENGTH            = %SQL_MAX_LENGTH
%SQL_ATTR_MAX_ROWS              = %SQL_MAX_ROWS
%SQL_ATTR_NOSCAN                = %SQL_NOSCAN
%SQL_ATTR_PARAM_BIND_OFFSET_PTR = 17
%SQL_ATTR_PARAM_BIND_TYPE       = 18
%SQL_ATTR_PARAM_OPERATION_PTR   = 19
%SQL_ATTR_PARAM_STATUS_PTR      = 20
%SQL_ATTR_PARAMS_PROCESSED_PTR  = 21
%SQL_ATTR_PARAMSET_SIZE         = 22
%SQL_ATTR_QUERY_TIMEOUT         = %SQL_QUERY_TIMEOUT
%SQL_ATTR_RETRIEVE_DATA         = %SQL_RETRIEVE_DATA
%SQL_ATTR_ROW_BIND_OFFSET_PTR   = 23
%SQL_ATTR_ROW_BIND_TYPE         = %SQL_BIND_TYPE
%SQL_ATTR_ROW_NUMBER            = %SQL_ROW_NUMBER        'GetStmtAttr*/
%SQL_ATTR_ROW_OPERATION_PTR     = 24
%SQL_ATTR_ROW_STATUS_PTR        = 25
%SQL_ATTR_ROWS_FETCHED_PTR      = 26
%SQL_ATTR_ROW_ARRAY_SIZE        = 27
%SQL_ATTR_SIMULATE_CURSOR       = %SQL_SIMULATE_CURSOR
%SQL_ATTR_USE_BOOKMARKS         = %SQL_USE_BOOKMARKS


'#if (ODBCVER < 0x0300)
'%SQL_STMT_OPT_MAX                SQL_ROW_NUMBER
'%SQL_STMT_OPT_MIN    SQL_QUERY_TIMEOUT
'#endif      ' ODBCVER < 0x0300 */

' New defines for SEARCHABLE column in SQLGetTypeInfo */

%SQL_COL_PRED_CHAR  = %SQL_LIKE_ONLY
%SQL_COL_PRED_BASIC = %SQL_ALL_EXCEPT_LIKE

' whether an attribute is a pointer or not */
%SQL_IS_POINTER   = (-4)
%SQL_IS_UINTEGER  = (-5)
%SQL_IS_INTEGER   = (-6)
%SQL_IS_USMALLINT = (-7)
%SQL_IS_SMALLINT  = (-8)

' the value of SQL_ATTR_PARAM_BIND_TYPE */
%SQL_PARAM_BIND_BY_COLUMN    = 0???
%SQL_PARAM_BIND_TYPE_DEFAULT = %SQL_PARAM_BIND_BY_COLUMN

' SQL_QUERY_TIMEOUT options */
%SQL_QUERY_TIMEOUT_DEFAULT = 0???

' SQL_MAX_ROWS options */
%SQL_MAX_ROWS_DEFAULT = 0???

' SQL_NOSCAN options */
%SQL_NOSCAN_OFF     = 0???              '      1.0 FALSE */
%SQL_NOSCAN_ON      = 1???              '      1.0 TRUE */
%SQL_NOSCAN_DEFAULT = %SQL_NOSCAN_OFF

' SQL_MAX_LENGTH options */
%SQL_MAX_LENGTH_DEFAULT = 0???

' values for SQL_ATTR_ASYNC_ENABLE */
%SQL_ASYNC_ENABLE_OFF     = 0???
%SQL_ASYNC_ENABLE_ON      = 1???
%SQL_ASYNC_ENABLE_DEFAULT = %SQL_ASYNC_ENABLE_OFF

' SQL_BIND_TYPE options */
%SQL_BIND_BY_COLUMN    = 0???
%SQL_BIND_TYPE_DEFAULT = %SQL_BIND_BY_COLUMN   ' Default value */

' SQL_CONCURRENCY options */
%SQL_CONCUR_READ_ONLY = 1
%SQL_CONCUR_LOCK      = 2
%SQL_CONCUR_ROWVER    = 3
%SQL_CONCUR_VALUES    = 4
%SQL_CONCUR_DEFAULT   = %SQL_CONCUR_READ_ONLY   ' Default value */

' SQL_CURSOR_TYPE options */
%SQL_CURSOR_FORWARD_ONLY  = 0???
%SQL_CURSOR_KEYSET_DRIVEN = 1???
%SQL_CURSOR_DYNAMIC       = 2???
%SQL_CURSOR_STATIC        = 3???
%SQL_CURSOR_TYPE_DEFAULT  = %SQL_CURSOR_FORWARD_ONLY   ' Default value */

' SQL_ROWSET_SIZE options */
%SQL_ROWSET_SIZE_DEFAULT = 1???

' SQL_KEYSET_SIZE options */
%SQL_KEYSET_SIZE_DEFAULT = 0???

' SQL_SIMULATE_CURSOR options */
%SQL_SC_NON_UNIQUE = 0???
%SQL_SC_TRY_UNIQUE = 1???
%SQL_SC_UNIQUE     = 2???

' SQL_RETRIEVE_DATA options */
%SQL_RD_OFF     = 0???
%SQL_RD_ON      = 1???
%SQL_RD_DEFAULT = %SQL_RD_ON

' SQL_USE_BOOKMARKS options */
%SQL_UB_OFF     = 0???
%SQL_UB_ON      = 01???
%SQL_UB_DEFAULT = %SQL_UB_OFF

' New values for SQL_USE_BOOKMARKS attribute */
%SQL_UB_FIXED    = %SQL_UB_ON
%SQL_UB_VARIABLE = 2???

' defines for diagnostics fields */
%SQL_DIAG_CURSOR_ROW_COUNT = (-1249)
%SQL_DIAG_ROW_NUMBER       = (-1248)
%SQL_DIAG_COLUMN_NUMBER    = (-1247)

' dynamic function codes */
%SQL_DIAG_CALL = 7

' SQL extended datatypes */
%SQL_DATE          = 9
%SQL_INTERVAL      = 10
%SQL_TIME          = 10
%SQL_TIMESTAMP     = 11
%SQL_LONGVARCHAR   = (-1)
%SQL_BINARY        = (-2)
%SQL_VARBINARY     = (-3)
%SQL_LONGVARBINARY = (-4)
%SQL_BIGINT        = (-5)
%SQL_TINYINT       = (-6)
%SQL_BIT           = (-7)
'#if (ODBCVER >= 0x0350)
'#define SQL_GUID            (-11)
'#endif  /* ODBCVER >= 0x0350 */
%SQL_GUID          = (-11)

' interval code */
%SQL_CODE_YEAR                 = 1
%SQL_CODE_MONTH                = 2
%SQL_CODE_DAY                  = 3
%SQL_CODE_HOUR                 = 4
%SQL_CODE_MINUTE               = 5
%SQL_CODE_SECOND               = 6
%SQL_CODE_YEAR_TO_MONTH        = 7
%SQL_CODE_DAY_TO_HOUR          = 8
%SQL_CODE_DAY_TO_MINUTE        = 9
%SQL_CODE_DAY_TO_SECOND        = 10
%SQL_CODE_HOUR_TO_MINUTE       = 11
%SQL_CODE_HOUR_TO_SECOND       = 12
%SQL_CODE_MINUTE_TO_SECOND     = 13

%SQL_INTERVAL_YEAR             = (100 + %SQL_CODE_YEAR)
%SQL_INTERVAL_MONTH            = (100 + %SQL_CODE_MONTH)
%SQL_INTERVAL_DAY              = (100 + %SQL_CODE_DAY)
%SQL_INTERVAL_HOUR             = (100 + %SQL_CODE_HOUR)
%SQL_INTERVAL_MINUTE           = (100 + %SQL_CODE_MINUTE)
%SQL_INTERVAL_SECOND           = (100 + %SQL_CODE_SECOND)
%SQL_INTERVAL_YEAR_TO_MONTH    = (100 + %SQL_CODE_YEAR_TO_MONTH)
%SQL_INTERVAL_DAY_TO_HOUR      = (100 + %SQL_CODE_DAY_TO_HOUR)
%SQL_INTERVAL_DAY_TO_MINUTE    = (100 + %SQL_CODE_DAY_TO_MINUTE)
%SQL_INTERVAL_DAY_TO_SECOND    = (100 + %SQL_CODE_DAY_TO_SECOND)
%SQL_INTERVAL_HOUR_TO_MINUTE   = (100 + %SQL_CODE_HOUR_TO_MINUTE)
%SQL_INTERVAL_HOUR_TO_SECOND   = (100 + %SQL_CODE_HOUR_TO_SECOND)
%SQL_INTERVAL_MINUTE_TO_SECOND = (100 + %SQL_CODE_MINUTE_TO_SECOND)

%SQL_UNICODE                   = (-95)
%SQL_UNICODE_VARCHAR           = (-96)
%SQL_UNICODE_LONGVARCHAR       = (-97)
%SQL_UNICODE_CHAR              = %SQL_UNICODE

'#if (ODBCVER < 0x0300)
'%SQL_TYPE_DRIVER_START                   SQL_INTERVAL_YEAR
'%SQL_TYPE_DRIVER_END                     SQL_UNICODE_LONGVARCHAR
'#endif  ' ODBCVER < 0x0300 */

' C datatype to SQL datatype mapping      SQL types

%SQL_C_CHAR    = %SQL_CHAR             ' CHAR, VARCHAR, DECIMAL, NUMERIC */
%SQL_C_LONG    = %SQL_INTEGER          ' INTEGER                      */
%SQL_C_SHORT   = %SQL_SMALLINT         ' SMALLINT                     */
%SQL_C_FLOAT   = %SQL_REAL             ' REAL                         */
%SQL_C_DOUBLE  = %SQL_DOUBLE           ' FLOAT, DOUBLE                */
%SQL_C_NUMERIC = %SQL_NUMERIC
%SQL_C_DEFAULT = 99

%SQL_SIGNED_OFFSET   = (-20)
%SQL_UNSIGNED_OFFSET = (-22)

' C datatype to SQL datatype mapping */
%SQL_C_DATE                      = %SQL_DATE
%SQL_C_TIME                      = %SQL_TIME
%SQL_C_TIMESTAMP                 = %SQL_TIMESTAMP
%SQL_C_TYPE_DATE                 = %SQL_TYPE_DATE
%SQL_C_TYPE_TIME                 = %SQL_TYPE_TIME
%SQL_C_TYPE_TIMESTAMP            = %SQL_TYPE_TIMESTAMP
%SQL_C_INTERVAL_YEAR             = %SQL_INTERVAL_YEAR
%SQL_C_INTERVAL_MONTH            = %SQL_INTERVAL_MONTH
%SQL_C_INTERVAL_DAY              = %SQL_INTERVAL_DAY
%SQL_C_INTERVAL_HOUR             = %SQL_INTERVAL_HOUR
%SQL_C_INTERVAL_MINUTE           = %SQL_INTERVAL_MINUTE
%SQL_C_INTERVAL_SECOND           = %SQL_INTERVAL_SECOND
%SQL_C_INTERVAL_YEAR_TO_MONTH    = %SQL_INTERVAL_YEAR_TO_MONTH
%SQL_C_INTERVAL_DAY_TO_HOUR      = %SQL_INTERVAL_DAY_TO_HOUR
%SQL_C_INTERVAL_DAY_TO_MINUTE    = %SQL_INTERVAL_DAY_TO_MINUTE
%SQL_C_INTERVAL_DAY_TO_SECOND    = %SQL_INTERVAL_DAY_TO_SECOND
%SQL_C_INTERVAL_HOUR_TO_MINUTE   = %SQL_INTERVAL_HOUR_TO_MINUTE
%SQL_C_INTERVAL_HOUR_TO_SECOND   = %SQL_INTERVAL_HOUR_TO_SECOND
%SQL_C_INTERVAL_MINUTE_TO_SECOND = %SQL_INTERVAL_MINUTE_TO_SECOND
%SQL_C_BINARY                    = %SQL_BINARY
%SQL_C_BIT                       = %SQL_BIT
%SQL_C_SBIGINT                   = (%SQL_BIGINT+%SQL_SIGNED_OFFSET)     ' SIGNED BIGINT */
%SQL_C_UBIGINT                   = (%SQL_BIGINT+%SQL_UNSIGNED_OFFSET)   ' UNSIGNED BIGINT */
%SQL_C_TINYINT                   = %SQL_TINYINT
%SQL_C_SLONG                     = (%SQL_C_LONG+%SQL_SIGNED_OFFSET)     ' SIGNED INTEGER  */
%SQL_C_SSHORT                    = (%SQL_C_SHORT+%SQL_SIGNED_OFFSET)    ' SIGNED SMALLINT */
%SQL_C_STINYINT                  = (%SQL_TINYINT+%SQL_SIGNED_OFFSET)    ' SIGNED TINYINT  */
%SQL_C_ULONG                     = (%SQL_C_LONG+%SQL_UNSIGNED_OFFSET)   ' UNSIGNED INTEGER*/
%SQL_C_USHORT                    = (%SQL_C_SHORT+%SQL_UNSIGNED_OFFSET)  ' UNSIGNED SMALLINT*/
%SQL_C_UTINYINT                  = (%SQL_TINYINT+%SQL_UNSIGNED_OFFSET)  ' UNSIGNED TINYINT*/
%SQL_C_BOOKMARK                  = %SQL_C_ULONG                         ' BOOKMARK        */

'#if (ODBCVER >= 0x0350)
'#define SQL_C_GUID   SQL_GUID
'#endif  /* ODBCVER >= 0x0350 */
%SQL_C_GUID = %SQL_GUID

%SQL_TYPE_NULL                   = 0
'#if (ODBCVER < 0x0300)
'%SQL_TYPE_MIN                    SQL_BIT
'%SQL_TYPE_MAX                    SQL_VARCHAR
'#endif

%SQL_C_VARBOOKMARK               = %SQL_C_BINARY

' define for SQL_DIAG_ROW_NUMBER and SQL_DIAG_COLUMN_NUMBER */
%SQL_NO_ROW_NUMBER         = (-1)
%SQL_NO_COLUMN_NUMBER      = (-1)
%SQL_ROW_NUMBER_UNKNOWN    = (-2)
%SQL_COLUMN_NUMBER_UNKNOWN = (-2)

' Defines for SQLBindParameter and
'  SQLProcedureColumns (returned in the result set) */
%SQL_PARAM_TYPE_UNKNOWN = 0
%SQL_PARAM_INPUT        = 1
%SQL_PARAM_INPUT_OUTPUT = 2
%SQL_RESULT_COL         = 3
%SQL_PARAM_OUTPUT       = 4
%SQL_RETURN_VALUE       = 5

' SQLBindParameter extensions */
%SQL_DEFAULT_PARAM           = (-5)
%SQL_IGNORE                  = (-6)
%SQL_COLUMN_IGNORE           = %SQL_IGNORE
%SQL_LEN_DATA_AT_EXEC_OFFSET = (-100)

'SQL_LEN_DATA_AT_EXEC(length) (-(length)+SQL_LEN_DATA_AT_EXEC_OFFSET)
'MACRO SQL_LEN_DATA_AT_EXEC(length) = (-(length)+%SQL_LEN_DATA_AT_EXEC_OFFSET)

' binary length for driver specific attributes */
%SQL_LEN_BINARY_ATTR_OFFSET = (-100)
'SQL_LEN_BINARY_ATTR(length)  (-(length)+SQL_LEN_BINARY_ATTR_OFFSET)
'MACRO SQL_LEN_BINARY_ATTR(length) = (-(length)+%SQL_LEN_BINARY_ATTR_OFFSET)

' Defines used by Driver Manager when mapping SQLSetParam to SQLBindParameter

%SQL_PARAM_TYPE_DEFAULT = %SQL_PARAM_INPUT_OUTPUT
%SQL_SETPARAM_VALUE_MAX = (-1&)

' SQLColAttributes defines */
%SQL_COLUMN_COUNT          = 0
%SQL_COLUMN_NAME           = 1
%SQL_COLUMN_TYPE           = 2
%SQL_COLUMN_LENGTH         = 3
%SQL_COLUMN_PRECISION      = 4
%SQL_COLUMN_SCALE          = 5
%SQL_COLUMN_DISPLAY_SIZE   = 6
%SQL_COLUMN_NULLABLE       = 7
%SQL_COLUMN_UNSIGNED       = 8
%SQL_COLUMN_MONEY          = 9
%SQL_COLUMN_UPDATABLE      = 10
%SQL_COLUMN_AUTO_INCREMENT = 11
%SQL_COLUMN_CASE_SENSITIVE = 12
%SQL_COLUMN_SEARCHABLE     = 13
%SQL_COLUMN_TYPE_NAME      = 14
%SQL_COLUMN_TABLE_NAME     = 15
%SQL_COLUMN_OWNER_NAME     = 16
%SQL_COLUMN_QUALIFIER_NAME = 17
%SQL_COLUMN_LABEL          = 18
%SQL_COLATT_OPT_MAX        = %SQL_COLUMN_LABEL
'#if (ODBCVER < 0x0300)
'%SQL_COLUMN_DRIVER_START         1000
'#endif  ' ODBCVER < 0x0300 */

%SQL_COLATT_OPT_MIN = %SQL_COLUMN_COUNT

' SQLColAttributes subdefines for SQL_COLUMN_UPDATABLE */
%SQL_ATTR_READONLY          = 0
%SQL_ATTR_WRITE             = 1
%SQL_ATTR_READWRITE_UNKNOWN = 2

' SQLColAttributes subdefines for SQL_COLUMN_SEARCHABLE */
' These are also used by SQLGetInfo                     */
%SQL_UNSEARCHABLE    = 0
'%SQL_LIKE_ONLY       = 1
'%SQL_ALL_EXCEPT_LIKE = 2
%SQL_SEARCHABLE      = 3
%SQL_PRED_SEARCHABLE = %SQL_SEARCHABLE

' Special return values for SQLGetData */
%SQL_NO_TOTAL = (-4)

' extended descriptor field */
%SQL_DESC_ARRAY_SIZE                  = 20
%SQL_DESC_ARRAY_STATUS_PTR            = 21
%SQL_DESC_AUTO_UNIQUE_VALUE           = %SQL_COLUMN_AUTO_INCREMENT
%SQL_DESC_BASE_COLUMN_NAME            = 22
%SQL_DESC_BASE_TABLE_NAME             = 23
%SQL_DESC_BIND_OFFSET_PTR             = 24
%SQL_DESC_BIND_TYPE                   = 25
%SQL_DESC_CASE_SENSITIVE              = %SQL_COLUMN_CASE_SENSITIVE
%SQL_DESC_CATALOG_NAME                = %SQL_COLUMN_QUALIFIER_NAME
%SQL_DESC_CONCISE_TYPE                = %SQL_COLUMN_TYPE
%SQL_DESC_DATETIME_INTERVAL_PRECISION = 26
%SQL_DESC_DISPLAY_SIZE                = %SQL_COLUMN_DISPLAY_SIZE
%SQL_DESC_FIXED_PREC_SCALE            = %SQL_COLUMN_MONEY
%SQL_DESC_LABEL                       = %SQL_COLUMN_LABEL
%SQL_DESC_LITERAL_PREFIX              = 27
%SQL_DESC_LITERAL_SUFFIX              = 28
%SQL_DESC_LOCAL_TYPE_NAME             = 29
%SQL_DESC_MAXIMUM_SCALE               = 30
%SQL_DESC_MINIMUM_SCALE               = 31
%SQL_DESC_NUM_PREC_RADIX              = 32
%SQL_DESC_PARAMETER_TYPE              = 33
%SQL_DESC_ROWS_PROCESSED_PTR          = 34
%SQL_DESC_SCHEMA_NAME                 = %SQL_COLUMN_OWNER_NAME
%SQL_DESC_SEARCHABLE                  = %SQL_COLUMN_SEARCHABLE
%SQL_DESC_TYPE_NAME                   = %SQL_COLUMN_TYPE_NAME
%SQL_DESC_TABLE_NAME                  = %SQL_COLUMN_TABLE_NAME
%SQL_DESC_UNSIGNED                    = %SQL_COLUMN_UNSIGNED
%SQL_DESC_UPDATABLE                   = %SQL_COLUMN_UPDATABLE

'*******************************************/
' SQLGetFunctions: additional values for   */
' fFunction to represent functions that    */
' are not in the X/Open spec.              */
'*******************************************/

%SQL_API_SQLALLOCHANDLESTD   = 73
%SQL_API_SQLBULKOPERATIONS   = 24
%SQL_API_SQLBINDPARAMETER    = 72
%SQL_API_SQLBROWSECONNECT    = 55
%SQL_API_SQLCOLATTRIBUTES    = 6
%SQL_API_SQLCOLUMNPRIVILEGES = 56
%SQL_API_SQLDESCRIBEPARAM    = 58
%SQL_API_SQLDRIVERCONNECT    = 41
%SQL_API_SQLDRIVERS          = 71
%SQL_API_SQLEXTENDEDFETCH    = 59
%SQL_API_SQLFOREIGNKEYS      = 60
%SQL_API_SQLMORERESULTS      = 61
%SQL_API_SQLNATIVESQL        = 62
%SQL_API_SQLNUMPARAMS        = 63
%SQL_API_SQLPARAMOPTIONS     = 64
%SQL_API_SQLPRIMARYKEYS      = 65
%SQL_API_SQLPROCEDURECOLUMNS = 66
%SQL_API_SQLPROCEDURES       = 67
%SQL_API_SQLSETPOS           = 68
%SQL_API_SQLSETSCROLLOPTIONS = 69
%SQL_API_SQLTABLEPRIVILEGES  = 70

'-------------------------------------------*/
' SQL_EXT_API_LAST is not useful with ODBC  */
' version 3.0 because some of the values    */
' from X/Open are in the 10000 range.       */
'-------------------------------------------*/

'#if (ODBCVER < 0x0300)
'%SQL_EXT_API_LAST            SQL_API_SQLBINDPARAMETER
'%SQL_NUM_FUNCTIONS           23
'%SQL_EXT_API_START           40
'%SQL_NUM_EXTENSIONS (SQL_EXT_API_LAST-SQL_EXT_API_START+1)
'#endif

'--------------------------------------------*/
' SQL_API_ALL_FUNCTIONS returns an array     */
' of 'booleans' representing whether a       */
' function is implemented by the driver.     */
'                                            */
' CAUTION: Only functions defined in ODBC    */
' version 2.0 and earlier are returned, the  */
' new high-range function numbers defined by */
' X/Open break this scheme.   See the new    */
' method -- SQL_API_ODBC3_ALL_FUNCTIONS      */
'--------------------------------------------*/

%SQL_API_ALL_FUNCTIONS = 0       ' See CAUTION above */

'----------------------------------------------*/
' 2.X drivers export a dummy function with     */
' ordinal number SQL_API_LOADBYORDINAL to speed*/
' loading under the windows operating system.  */
'                      */
' CAUTION: Loading by ordinal is not supported */
' for 3.0 and above drivers.           */
'----------------------------------------------*/

%SQL_API_LOADBYORDINAL = 199     ' See CAUTION above */

'----------------------------------------------*/
' SQL_API_ODBC3_ALL_FUNCTIONS                  */
' This returns a bitmap, which allows us to    */
' handle the higher-valued function numbers.   */
' Use  SQL_FUNC_EXISTS(bitmap,function_number) */
' to determine if the function exists.         */
'----------------------------------------------*/


%SQL_API_ODBC3_ALL_FUNCTIONS      = 999
%SQL_API_ODBC3_ALL_FUNCTIONS_SIZE = 250     ' array of 250 words */

'***** Need to make Function
'%SQL_FUNC_EXISTS(pfExists, uwAPI) \
'                ((*(((UWORD*) (pfExists)) + ((uwAPI) >> 4)) \
'                    & (1 << ((uwAPI) & 0x000F)) \
'                 ) ? SQL_TRUE : SQL_FALSE \
'                )
'*****


'***********************************************/
' Extended definitions for SQLGetInfo          */
'***********************************************/

'---------------------------------*/
' Values in ODBC 2.0 that are not */
' in the X/Open spec              */
'---------------------------------*/

%SQL_INFO_FIRST                 = 0
%SQL_ACTIVE_CONNECTIONS         = 0     ' MAX_DRIVER_CONNECTIONS */
%SQL_ACTIVE_STATEMENTS          = 1     ' MAX_CONCURRENT_ACTIVITIES */
%SQL_DRIVER_HDBC                = 3
%SQL_DRIVER_HENV                = 4
%SQL_DRIVER_HSTMT               = 5
%SQL_DRIVER_NAME                = 6
%SQL_DRIVER_VER                 = 7
%SQL_ODBC_API_CONFORMANCE       = 9
%SQL_ODBC_VER                   = 10
%SQL_ROW_UPDATES                = 11
%SQL_ODBC_SAG_CLI_CONFORMANCE   = 12
%SQL_ODBC_SQL_CONFORMANCE       = 15
%SQL_PROCEDURES                 = 21
%SQL_CONCAT_NULL_BEHAVIOR       = 22
%SQL_CURSOR_ROLLBACK_BEHAVIOR   = 24
%SQL_EXPRESSIONS_IN_ORDERBY     = 27
%SQL_MAX_OWNER_NAME_LEN         = 32    ' MAX_SCHEMA_NAME_LEN */
%SQL_MAX_PROCEDURE_NAME_LEN     = 33
%SQL_MAX_QUALIFIER_NAME_LEN     = 34    ' MAX_CATALOG_NAME_LEN */
%SQL_MULT_RESULT_SETS           = 36
%SQL_MULTIPLE_ACTIVE_TXN        = 37
%SQL_OUTER_JOINS                = 38
%SQL_OWNER_TERM                 = 39
%SQL_PROCEDURE_TERM             = 40
%SQL_QUALIFIER_NAME_SEPARATOR   = 41
%SQL_QUALIFIER_TERM             = 42
%SQL_SCROLL_OPTIONS             = 44
%SQL_TABLE_TERM                 = 45
%SQL_CONVERT_FUNCTIONS          = 48
%SQL_NUMERIC_FUNCTIONS          = 49
%SQL_STRING_FUNCTIONS           = 50
%SQL_SYSTEM_FUNCTIONS           = 51
%SQL_TIMEDATE_FUNCTIONS         = 52
%SQL_CONVERT_BIGINT             = 53
%SQL_CONVERT_BINARY             = 54
%SQL_CONVERT_BIT                = 55
%SQL_CONVERT_CHAR               = 56
%SQL_CONVERT_DATE               = 57
%SQL_CONVERT_DECIMAL            = 58
%SQL_CONVERT_DOUBLE             = 59
%SQL_CONVERT_FLOAT              = 60
%SQL_CONVERT_INTEGER            = 61
%SQL_CONVERT_LONGVARCHAR        = 62
%SQL_CONVERT_NUMERIC            = 63
%SQL_CONVERT_REAL               = 64
%SQL_CONVERT_SMALLINT           = 65
%SQL_CONVERT_TIME               = 66
%SQL_CONVERT_TIMESTAMP          = 67
%SQL_CONVERT_TINYINT            = 68
%SQL_CONVERT_VARBINARY          = 69
%SQL_CONVERT_VARCHAR            = 70
%SQL_CONVERT_LONGVARBINARY      = 71
%SQL_ODBC_SQL_OPT_IEF           = 73    ' SQL_INTEGRITY */
%SQL_CORRELATION_NAME           = 74
%SQL_NON_NULLABLE_COLUMNS       = 75
%SQL_DRIVER_HLIB                = 76
%SQL_DRIVER_ODBC_VER            = 77
%SQL_LOCK_TYPES                 = 78
%SQL_POS_OPERATIONS             = 79
%SQL_POSITIONED_STATEMENTS      = 80
%SQL_BOOKMARK_PERSISTENCE       = 82
%SQL_STATIC_SENSITIVITY         = 83
%SQL_FILE_USAGE                 = 84
%SQL_COLUMN_ALIAS               = 87
%SQL_GROUP_BY                   = 88
%SQL_KEYWORDS                   = 89
%SQL_OWNER_USAGE                = 91
%SQL_QUALIFIER_USAGE            = 92
%SQL_QUOTED_IDENTIFIER_CASE     = 93
%SQL_SUBQUERIES                 = 95
%SQL_UNION                      = 96
%SQL_MAX_ROW_SIZE_INCLUDES_LONG = 103
%SQL_MAX_CHAR_LITERAL_LEN       = 108
%SQL_TIMEDATE_ADD_INTERVALS     = 109
%SQL_TIMEDATE_DIFF_INTERVALS    = 110
%SQL_NEED_LONG_DATA_LEN         = 111
%SQL_MAX_BINARY_LITERAL_LEN     = 112
%SQL_LIKE_ESCAPE_CLAUSE         = 113
%SQL_QUALIFIER_LOCATION         = 114

'#if (ODBCVER >= 0x0201 && ODBCVER < 0x0300)
'%SQL_OJ_CAPABILITIES         65003  ' Temp value until ODBC 3.0 */
'#endif  ' ODBCVER >= 0x0201 && ODBCVER < 0x0300 */

'----------------------------------------------*/
' SQL_INFO_LAST and SQL_INFO_DRIVER_START are  */
' not useful anymore, because  X/Open has      */
' values in the 10000 range.   You             */
' must contact X/Open directly to get a range  */
' of numbers for driver-specific values.       */
'----------------------------------------------*/

'#if (ODBCVER < 0x0300)
'%SQL_INFO_LAST                       SQL_QUALIFIER_LOCATION
'%SQL_INFO_DRIVER_START               1000
'#endif ' ODBCVER < 0x0300 */

'-----------------------------------------------*/
' ODBC 3.0 SQLGetInfo values that are not part  */
' of the X/Open standard at this time.   X/Open */
' standard values are in sql.h.                 */
'-----------------------------------------------*/

%SQL_ACTIVE_ENVIRONMENTS               = 116
%SQL_ALTER_DOMAIN                      = 117

%SQL_SQL_CONFORMANCE                   = 118
%SQL_DATETIME_LITERALS                 = 119

%SQL_ASYNC_MODE                        = 10021    ' new X/Open spec */
%SQL_BATCH_ROW_COUNT                   = 120
%SQL_BATCH_SUPPORT                     = 121
%SQL_CATALOG_LOCATION                  = %SQL_QUALIFIER_LOCATION
%SQL_CATALOG_NAME_SEPARATOR            = %SQL_QUALIFIER_NAME_SEPARATOR
%SQL_CATALOG_TERM                      = %SQL_QUALIFIER_TERM
%SQL_CATALOG_USAGE                     = %SQL_QUALIFIER_USAGE
%SQL_CONVERT_WCHAR                     = 122
%SQL_CONVERT_INTERVAL_DAY_TIME         = 123
%SQL_CONVERT_INTERVAL_YEAR_MONTH       = 124
%SQL_CONVERT_WLONGVARCHAR              = 125
%SQL_CONVERT_WVARCHAR                  = 126
%SQL_CREATE_ASSERTION                  = 127
%SQL_CREATE_CHARACTER_SET              = 128
%SQL_CREATE_COLLATION                  = 129
%SQL_CREATE_DOMAIN                     = 130
%SQL_CREATE_SCHEMA                     = 131
%SQL_CREATE_TABLE                      = 132
%SQL_CREATE_TRANSLATION                = 133
%SQL_CREATE_VIEW                       = 134
%SQL_DRIVER_HDESC                      = 135
%SQL_DROP_ASSERTION                    = 136
%SQL_DROP_CHARACTER_SET                = 137
%SQL_DROP_COLLATION                    = 138
%SQL_DROP_DOMAIN                       = 139
%SQL_DROP_SCHEMA                       = 140
%SQL_DROP_TABLE                        = 141
%SQL_DROP_TRANSLATION                  = 142
%SQL_DROP_VIEW                         = 143
%SQL_DYNAMIC_CURSOR_ATTRIBUTES1        = 144
%SQL_DYNAMIC_CURSOR_ATTRIBUTES2        = 145
%SQL_FORWARD_ONLY_CURSOR_ATTRIBUTES1   = 146
%SQL_FORWARD_ONLY_CURSOR_ATTRIBUTES2   = 147
%SQL_INDEX_KEYWORDS                    = 148
%SQL_INFO_SCHEMA_VIEWS                 = 149
%SQL_KEYSET_CURSOR_ATTRIBUTES1         = 150
%SQL_KEYSET_CURSOR_ATTRIBUTES2         = 151
%SQL_MAX_ASYNC_CONCURRENT_STATEMENTS   = 10022  ' new X/Open spec */
%SQL_ODBC_INTERFACE_CONFORMANCE        = 152
%SQL_PARAM_ARRAY_ROW_COUNTS            = 153
%SQL_PARAM_ARRAY_SELECTS               = 154
%SQL_SCHEMA_TERM                       = %SQL_OWNER_TERM
%SQL_SCHEMA_USAGE                      = %SQL_OWNER_USAGE
%SQL_SQL92_DATETIME_FUNCTIONS          = 155
%SQL_SQL92_FOREIGN_KEY_DELETE_RULE     = 156
%SQL_SQL92_FOREIGN_KEY_UPDATE_RULE     = 157
%SQL_SQL92_GRANT                       = 158
%SQL_SQL92_NUMERIC_VALUE_FUNCTIONS     = 159
%SQL_SQL92_PREDICATES                  = 160
%SQL_SQL92_RELATIONAL_JOIN_OPERATORS   = 161
%SQL_SQL92_REVOKE                      = 162
%SQL_SQL92_ROW_VALUE_CONSTRUCTOR       = 163
%SQL_SQL92_STRING_FUNCTIONS            = 164
%SQL_SQL92_VALUE_EXPRESSIONS           = 165
%SQL_STANDARD_CLI_CONFORMANCE          = 166
%SQL_STATIC_CURSOR_ATTRIBUTES1         = 167
%SQL_STATIC_CURSOR_ATTRIBUTES2         = 168

%SQL_AGGREGATE_FUNCTIONS               = 169
%SQL_DDL_INDEX                         = 170
%SQL_DM_VER                            = 171
%SQL_INSERT_STATEMENT                  = 172
%SQL_CONVERT_GUID                      = 173
%SQL_UNION_STATEMENT                   = %SQL_UNION

%SQL_DTC_TRANSITION_COST               = 1750

' SQL_ALTER_TABLE bitmasks */
%SQL_AT_ADD_COLUMN_SINGLE              = &H00000020&
%SQL_AT_ADD_COLUMN_DEFAULT             = &H00000040&
%SQL_AT_ADD_COLUMN_COLLATION           = &H00000080&
%SQL_AT_SET_COLUMN_DEFAULT             = &H00000100&
%SQL_AT_DROP_COLUMN_DEFAULT            = &H00000200&
%SQL_AT_DROP_COLUMN_CASCADE            = &H00000400&
%SQL_AT_DROP_COLUMN_RESTRICT           = &H00000800&
%SQL_AT_ADD_TABLE_CONSTRAINT           = &H00001000&
%SQL_AT_DROP_TABLE_CONSTRAINT_CASCADE  = &H00002000&
%SQL_AT_DROP_TABLE_CONSTRAINT_RESTRICT = &H00004000&
%SQL_AT_CONSTRAINT_NAME_DEFINITION     = &H00008000&
%SQL_AT_CONSTRAINT_INITIALLY_DEFERRED  = &H00010000&
%SQL_AT_CONSTRAINT_INITIALLY_IMMEDIATE = &H00020000&
%SQL_AT_CONSTRAINT_DEFERRABLE          = &H00040000&
%SQL_AT_CONSTRAINT_NON_DEFERRABLE      = &H00080000&

' SQL_CONVERT_*  return value bitmasks */
%SQL_CVT_CHAR                = &H00000001&
%SQL_CVT_NUMERIC             = &H00000002&
%SQL_CVT_DECIMAL             = &H00000004&
%SQL_CVT_INTEGER             = &H00000008&
%SQL_CVT_SMALLINT            = &H00000010&
%SQL_CVT_FLOAT               = &H00000020&
%SQL_CVT_REAL                = &H00000040&
%SQL_CVT_DOUBLE              = &H00000080&
%SQL_CVT_VARCHAR             = &H00000100&
%SQL_CVT_LONGVARCHAR         = &H00000200&
%SQL_CVT_BINARY              = &H00000400&
%SQL_CVT_VARBINARY           = &H00000800&
%SQL_CVT_BIT                 = &H00001000&
%SQL_CVT_TINYINT             = &H00002000&
%SQL_CVT_BIGINT              = &H00004000&
%SQL_CVT_DATE                = &H00008000&
%SQL_CVT_TIME                = &H00010000&
%SQL_CVT_TIMESTAMP           = &H00020000&
%SQL_CVT_LONGVARBINARY       = &H00040000&
%SQL_CVT_INTERVAL_YEAR_MONTH = &H00080000&
%SQL_CVT_INTERVAL_DAY_TIME   = &H00100000&
%SQL_CVT_WCHAR               = &H00200000&
%SQL_CVT_WLONGVARCHAR        = &H00400000&
%SQL_CVT_WVARCHAR            = &H00800000&
%SQL_CVT_GUID                = &H01000000&

' SQL_CONVERT_FUNCTIONS functions */
%SQL_FN_CVT_CONVERT = &H00000001&
%SQL_FN_CVT_CAST    = &H00000002&

' SQL_STRING_FUNCTIONS functions */

%SQL_FN_STR_CONCAT           = &H00000001&
%SQL_FN_STR_INSERT           = &H00000002&
%SQL_FN_STR_LEFT             = &H00000004&
%SQL_FN_STR_LTRIM            = &H00000008&
%SQL_FN_STR_LENGTH           = &H00000010&
%SQL_FN_STR_LOCATE           = &H00000020&
%SQL_FN_STR_LCASE            = &H00000040&
%SQL_FN_STR_REPEAT           = &H00000080&
%SQL_FN_STR_REPLACE          = &H00000100&
%SQL_FN_STR_RIGHT            = &H00000200&
%SQL_FN_STR_RTRIM            = &H00000400&
%SQL_FN_STR_SUBSTRING        = &H00000800&
%SQL_FN_STR_UCASE            = &H00001000&
%SQL_FN_STR_ASCII            = &H00002000&
%SQL_FN_STR_CHAR             = &H00004000&
%SQL_FN_STR_DIFFERENCE       = &H00008000&
%SQL_FN_STR_LOCATE_2         = &H00010000&
%SQL_FN_STR_SOUNDEX          = &H00020000&
%SQL_FN_STR_SPACE            = &H00040000&
%SQL_FN_STR_BIT_LENGTH       = &H00080000&
%SQL_FN_STR_CHAR_LENGTH      = &H00100000&
%SQL_FN_STR_CHARACTER_LENGTH = &H00200000&
%SQL_FN_STR_OCTET_LENGTH     = &H00400000&
%SQL_FN_STR_POSITION         = &H00800000&

' SQL_SQL92_STRING_FUNCTIONS */

%SQL_SSF_CONVERT       = &H00000001&
%SQL_SSF_LOWER         = &H00000002&
%SQL_SSF_UPPER         = &H00000004&
%SQL_SSF_SUBSTRING     = &H00000008&
%SQL_SSF_TRANSLATE     = &H00000010&
%SQL_SSF_TRIM_BOTH     = &H00000020&
%SQL_SSF_TRIM_LEADING  = &H00000040&
%SQL_SSF_TRIM_TRAILING = &H00000080&

' SQL_NUMERIC_FUNCTIONS functions */

%SQL_FN_NUM_ABS      = &H00000001&
%SQL_FN_NUM_ACOS     = &H00000002&
%SQL_FN_NUM_ASIN     = &H00000004&
%SQL_FN_NUM_ATAN     = &H00000008&
%SQL_FN_NUM_ATAN2    = &H00000010&
%SQL_FN_NUM_CEILING  = &H00000020&
%SQL_FN_NUM_COS      = &H00000040&
%SQL_FN_NUM_COT      = &H00000080&
%SQL_FN_NUM_EXP      = &H00000100&
%SQL_FN_NUM_FLOOR    = &H00000200&
%SQL_FN_NUM_LOG      = &H00000400&
%SQL_FN_NUM_MOD      = &H00000800&
%SQL_FN_NUM_SIGN     = &H00001000&
%SQL_FN_NUM_SIN      = &H00002000&
%SQL_FN_NUM_SQRT     = &H00004000&
%SQL_FN_NUM_TAN      = &H00008000&
%SQL_FN_NUM_PI       = &H00010000&
%SQL_FN_NUM_RAND     = &H00020000&
%SQL_FN_NUM_DEGREES  = &H00040000&
%SQL_FN_NUM_LOG10    = &H00080000&
%SQL_FN_NUM_POWER    = &H00100000&
%SQL_FN_NUM_RADIANS  = &H00200000&
%SQL_FN_NUM_ROUND    = &H00400000&
%SQL_FN_NUM_TRUNCATE = &H00800000&

' SQL_SQL92_NUMERIC_VALUE_FUNCTIONS */
%SQL_SNVF_BIT_LENGTH       = &H00000001&
%SQL_SNVF_CHAR_LENGTH      = &H00000002&
%SQL_SNVF_CHARACTER_LENGTH = &H00000004&
%SQL_SNVF_EXTRACT          = &H00000008&
%SQL_SNVF_OCTET_LENGTH     = &H00000010&
%SQL_SNVF_POSITION         = &H00000020&

' SQL_TIMEDATE_FUNCTIONS functions */

%SQL_FN_TD_NOW               = &H00000001&
%SQL_FN_TD_CURDATE           = &H00000002&
%SQL_FN_TD_DAYOFMONTH        = &H00000004&
%SQL_FN_TD_DAYOFWEEK         = &H00000008&
%SQL_FN_TD_DAYOFYEAR         = &H00000010&
%SQL_FN_TD_MONTH             = &H00000020&
%SQL_FN_TD_QUARTER           = &H00000040&
%SQL_FN_TD_WEEK              = &H00000080&
%SQL_FN_TD_YEAR              = &H00000100&
%SQL_FN_TD_CURTIME           = &H00000200&
%SQL_FN_TD_HOUR              = &H00000400&
%SQL_FN_TD_MINUTE            = &H00000800&
%SQL_FN_TD_SECOND            = &H00001000&
%SQL_FN_TD_TIMESTAMPADD      = &H00002000&
%SQL_FN_TD_TIMESTAMPDIFF     = &H00004000&
%SQL_FN_TD_DAYNAME           = &H00008000&
%SQL_FN_TD_MONTHNAME         = &H00010000&
%SQL_FN_TD_CURRENT_DATE      = &H00020000&
%SQL_FN_TD_CURRENT_TIME      = &H00040000&
%SQL_FN_TD_CURRENT_TIMESTAMP = &H00080000&
%SQL_FN_TD_EXTRACT           = &H00100000&

' SQL_SQL92_DATETIME_FUNCTIONS */

%SQL_SDF_CURRENT_DATE      = &H00000001&
%SQL_SDF_CURRENT_TIME      = &H00000002&
%SQL_SDF_CURRENT_TIMESTAMP = &H00000004&

' SQL_SYSTEM_FUNCTIONS functions */

%SQL_FN_SYS_USERNAME = &H00000001&
%SQL_FN_SYS_DBNAME   = &H00000002&
%SQL_FN_SYS_IFNULL   = &H00000004&

' SQL_TIMEDATE_ADD_INTERVALS and SQL_TIMEDATE_DIFF_INTERVALS functions */

%SQL_FN_TSI_FRAC_SECOND = &H00000001&
%SQL_FN_TSI_SECOND      = &H00000002&
%SQL_FN_TSI_MINUTE      = &H00000004&
%SQL_FN_TSI_HOUR        = &H00000008&
%SQL_FN_TSI_DAY         = &H00000010&
%SQL_FN_TSI_WEEK        = &H00000020&
%SQL_FN_TSI_MONTH       = &H00000040&
%SQL_FN_TSI_QUARTER     = &H00000080&
%SQL_FN_TSI_YEAR        = &H00000100&

' bitmasks for SQL_DYNAMIC_CURSOR_ATTRIBUTES1,
 ' SQL_FORWARD_ONLY_CURSOR_ATTRIBUTES1,
 ' SQL_KEYSET_CURSOR_ATTRIBUTES1, and SQL_STATIC_CURSOR_ATTRIBUTES1
 '*/
' supported SQLFetchScroll FetchOrientation's */
%SQL_CA1_NEXT     = &H00000001&
%SQL_CA1_ABSOLUTE = &H00000002&
%SQL_CA1_RELATIVE = &H00000004&
%SQL_CA1_BOOKMARK = &H00000008&

' supported SQLSetPos LockType's */
%SQL_CA1_LOCK_NO_CHANGE = &H00000040&
%SQL_CA1_LOCK_EXCLUSIVE = &H00000080&
%SQL_CA1_LOCK_UNLOCK    = &H00000100&

' supported SQLSetPos Operations */
%SQL_CA1_POS_POSITION = &H00000200&
%SQL_CA1_POS_UPDATE   = &H00000400&
%SQL_CA1_POS_DELETE   = &H00000800&
%SQL_CA1_POS_REFRESH  = &H00001000&

' positioned updates and deletes */
%SQL_CA1_POSITIONED_UPDATE = &H00002000&
%SQL_CA1_POSITIONED_DELETE = &H00004000&
%SQL_CA1_SELECT_FOR_UPDATE = &H00008000&

' supported SQLBulkOperations operations */
%SQL_CA1_BULK_ADD = &H00010000&
%SQL_CA1_BULK_UPDATE_BY_BOOKMARK = &H00020000&
%SQL_CA1_BULK_DELETE_BY_BOOKMARK = &H00040000&
%SQL_CA1_BULK_FETCH_BY_BOOKMARK = &H00080000&

' bitmasks for SQL_DYNAMIC_CURSOR_ATTRIBUTES2,
 '* SQL_FORWARD_ONLY_CURSOR_ATTRIBUTES2,
 '* SQL_KEYSET_CURSOR_ATTRIBUTES2, and SQL_STATIC_CURSOR_ATTRIBUTES2
 '*/
' supported values for SQL_ATTR_SCROLL_CONCURRENCY */
%SQL_CA2_READ_ONLY_CONCURRENCY  = &H00000001&
%SQL_CA2_LOCK_CONCURRENCY       = &H00000002&
%SQL_CA2_OPT_ROWVER_CONCURRENCY = &H00000004&
%SQL_CA2_OPT_VALUES_CONCURRENCY = &H00000008&

' sensitivity of the cursor to its own inserts, deletes, and updates */
%SQL_CA2_SENSITIVITY_ADDITIONS = &H00000010&
%SQL_CA2_SENSITIVITY_DELETIONS = &H00000020&
%SQL_CA2_SENSITIVITY_UPDATES   = &H00000040&

' semantics of SQL_ATTR_MAX_ROWS */
%SQL_CA2_MAX_ROWS_SELECT      = &H00000080&
%SQL_CA2_MAX_ROWS_INSERT      = &H00000100&
%SQL_CA2_MAX_ROWS_DELETE      = &H00000200&
%SQL_CA2_MAX_ROWS_UPDATE      = &H00000400&
%SQL_CA2_MAX_ROWS_CATALOG     = &H00000800&
%SQL_CA2_MAX_ROWS_AFFECTS_ALL = %SQL_CA2_MAX_ROWS_SELECT OR _
                                %SQL_CA2_MAX_ROWS_INSERT OR _
                                %SQL_CA2_MAX_ROWS_DELETE OR _
                                %SQL_CA2_MAX_ROWS_UPDATE OR _
                                %SQL_CA2_MAX_ROWS_CATALOG

' semantics of SQL_DIAG_CURSOR_ROW_COUNT */
%SQL_CA2_CRC_EXACT       = &H00001000&
%SQL_CA2_CRC_APPROXIMATE = &H00002000&

' the kinds of positioned statements that can be simulated */
%SQL_CA2_SIMULATE_NON_UNIQUE = &H00004000&
%SQL_CA2_SIMULATE_TRY_UNIQUE = &H00008000&
%SQL_CA2_SIMULATE_UNIQUE     = &H00010000&

' SQL_ODBC_API_CONFORMANCE values */

%SQL_OAC_NONE   = &H0000
%SQL_OAC_LEVEL1 = &H0001
%SQL_OAC_LEVEL2 = &H0002

' SQL_ODBC_SAG_CLI_CONFORMANCE values */

%SQL_OSCC_NOT_COMPLIANT = &H0000
%SQL_OSCC_COMPLIANT     = &H0001

' SQL_ODBC_SQL_CONFORMANCE values */

%SQL_OSC_MINIMUM  = &H0000
%SQL_OSC_CORE     = &H0001
%SQL_OSC_EXTENDED = &H0002

' SQL_CONCAT_NULL_BEHAVIOR values */

%SQL_CB_NULL     = &H0000
%SQL_CB_NON_NULL = &H0001

' SQL_SCROLL_OPTIONS masks */

%SQL_SO_FORWARD_ONLY  = &H00000001&
%SQL_SO_KEYSET_DRIVEN = &H00000002&
%SQL_SO_DYNAMIC       = &H00000004&
%SQL_SO_MIXED         = &H00000008&
%SQL_SO_STATIC        = &H00000010&

' SQL_FETCH_DIRECTION masks */

' SQL_FETCH_RESUME is no longer supported
'%SQL_FD_FETCH_RESUME   = &H00000040&
'*/
%SQL_FD_FETCH_BOOKMARK = &H00000080&

' SQL_TXN_ISOLATION_OPTION masks */
' SQL_TXN_VERSIONING is no longer supported
'%SQL_TXN_VERSIONING    = &H00000010&
'*/

' SQL_CORRELATION_NAME values */

%SQL_CN_NONE      = &H0000
%SQL_CN_DIFFERENT = &H0001
%SQL_CN_ANY       = &H0002

' SQL_NON_NULLABLE_COLUMNS values */

%SQL_NNC_NULL     = &H0000
%SQL_NNC_NON_NULL = &H0001

' SQL_NULL_COLLATION values */

%SQL_NC_START = &H0002
%SQL_NC_END   = &H0004

' SQL_FILE_USAGE values */

%SQL_FILE_NOT_SUPPORTED = &H0000
%SQL_FILE_TABLE         = &H0001
%SQL_FILE_QUALIFIER     = &H0002
%SQL_FILE_CATALOG       = %SQL_FILE_QUALIFIER   ' ODBC 3.0


' SQL_GETDATA_EXTENSIONS values */

%SQL_GD_BLOCK = &H00000004&
%SQL_GD_BOUND = &H00000008&

' SQL_POSITIONED_STATEMENTS masks */

%SQL_PS_POSITIONED_DELETE = &H00000001&
%SQL_PS_POSITIONED_UPDATE = &H00000002&
%SQL_PS_SELECT_FOR_UPDATE = &H00000004&

' SQL_GROUP_BY values */

%SQL_GB_NOT_SUPPORTED            = &H0000
%SQL_GB_GROUP_BY_EQUALS_SELECT   = &H0001
%SQL_GB_GROUP_BY_CONTAINS_SELECT = &H0002
%SQL_GB_NO_RELATION              = &H0003
%SQL_GB_COLLATE                  = &H0004

' SQL_OWNER_USAGE masks */

%SQL_OU_DML_STATEMENTS       = &H00000001&
%SQL_OU_PROCEDURE_INVOCATION = &H00000002&
%SQL_OU_TABLE_DEFINITION     = &H00000004&
%SQL_OU_INDEX_DEFINITION     = &H00000008&
%SQL_OU_PRIVILEGE_DEFINITION = &H00000010&

' SQL_SCHEMA_USAGE masks */
%SQL_SU_DML_STATEMENTS       = %SQL_OU_DML_STATEMENTS
%SQL_SU_PROCEDURE_INVOCATION = %SQL_OU_PROCEDURE_INVOCATION
%SQL_SU_TABLE_DEFINITION     = %SQL_OU_TABLE_DEFINITION
%SQL_SU_INDEX_DEFINITION     = %SQL_OU_INDEX_DEFINITION
%SQL_SU_PRIVILEGE_DEFINITION = %SQL_OU_PRIVILEGE_DEFINITION

' SQL_QUALIFIER_USAGE masks */

%SQL_QU_DML_STATEMENTS       = &H00000001&
%SQL_QU_PROCEDURE_INVOCATION = &H00000002&
%SQL_QU_TABLE_DEFINITION     = &H00000004&
%SQL_QU_INDEX_DEFINITION     = &H00000008&
%SQL_QU_PRIVILEGE_DEFINITION = &H00000010&

' SQL_CATALOG_USAGE masks */
%SQL_CU_DML_STATEMENTS       = %SQL_QU_DML_STATEMENTS
%SQL_CU_PROCEDURE_INVOCATION = %SQL_QU_PROCEDURE_INVOCATION
%SQL_CU_TABLE_DEFINITION     = %SQL_QU_TABLE_DEFINITION
%SQL_CU_INDEX_DEFINITION     = %SQL_QU_INDEX_DEFINITION
%SQL_CU_PRIVILEGE_DEFINITION = %SQL_QU_PRIVILEGE_DEFINITION

' SQL_SUBQUERIES masks */

%SQL_SQ_COMPARISON            = &H00000001&
%SQL_SQ_EXISTS                = &H00000002&
%SQL_SQ_IN                    = &H00000004&
%SQL_SQ_QUANTIFIED            = &H00000008&
%SQL_SQ_CORRELATED_SUBQUERIES = &H00000010&

' SQL_UNION masks */

%SQL_U_UNION     = &H00000001&
%SQL_U_UNION_ALL = &H00000002&

' SQL_BOOKMARK_PERSISTENCE values */

%SQL_BP_CLOSE       = &H00000001&
%SQL_BP_DELETE      = &H00000002&
%SQL_BP_DROP        = &H00000004&
%SQL_BP_TRANSACTION = &H00000008&
%SQL_BP_UPDATE      = &H00000010&
%SQL_BP_OTHER_HSTMT = &H00000020&
%SQL_BP_SCROLL      = &H00000040&

' SQL_STATIC_SENSITIVITY values */

%SQL_SS_ADDITIONS = &H00000001&
%SQL_SS_DELETIONS = &H00000002&
%SQL_SS_UPDATES   = &H00000004&

' SQL_VIEW values */
%SQL_CV_CREATE_VIEW  = &H00000001&
%SQL_CV_CHECK_OPTION = &H00000002&
%SQL_CV_CASCADED     = &H00000004&
%SQL_CV_LOCAL        = &H00000008&

' SQL_LOCK_TYPES masks */

%SQL_LCK_NO_CHANGE = &H00000001&
%SQL_LCK_EXCLUSIVE = &H00000002&
%SQL_LCK_UNLOCK    = &H00000004&

' SQL_POS_OPERATIONS masks */

%SQL_POS_POSITION = &H00000001&
%SQL_POS_REFRESH  = &H00000002&
%SQL_POS_UPDATE   = &H00000004&
%SQL_POS_DELETE   = &H00000008&
%SQL_POS_ADD      = &H00000010&

' SQL_QUALIFIER_LOCATION values */

%SQL_QL_START = &H0001
%SQL_QL_END   = &H0002

' Here start return values for ODBC 3.0 SQLGetInfo */

' SQL_AGGREGATE_FUNCTIONS bitmasks */
%SQL_AF_AVG      = &H00000001&
%SQL_AF_COUNT    = &H00000002&
%SQL_AF_MAX      = &H00000004&
%SQL_AF_MIN      = &H00000008&
%SQL_AF_SUM      = &H00000010&
%SQL_AF_DISTINCT = &H00000020&
%SQL_AF_ALL      = %SQL_AF_AVG OR _
                   %SQL_AF_COUNT OR _
                   %SQL_AF_MAX OR _
                   %SQL_AF_MIN OR _
                   %SQL_AF_SUM OR _
                   %SQL_AF_DISTINCT

' SQL_SQL_CONFORMANCE bit masks */
%SQL_SC_SQL92_ENTRY            = &H00000001&
%SQL_SC_FIPS127_2_TRANSITIONAL = &H00000002&
%SQL_SC_SQL92_INTERMEDIATE     = &H00000004&
%SQL_SC_SQL92_FULL             = &H00000008&

' SQL_DATETIME_LITERALS masks */
%SQL_DL_SQL92_DATE                      = &H00000001&
%SQL_DL_SQL92_TIME                      = &H00000002&
%SQL_DL_SQL92_TIMESTAMP                 = &H00000004&
%SQL_DL_SQL92_INTERVAL_YEAR             = &H00000008&
%SQL_DL_SQL92_INTERVAL_MONTH            = &H00000010&
%SQL_DL_SQL92_INTERVAL_DAY              = &H00000020&
%SQL_DL_SQL92_INTERVAL_HOUR             = &H00000040&
%SQL_DL_SQL92_INTERVAL_MINUTE           = &H00000080&
%SQL_DL_SQL92_INTERVAL_SECOND           = &H00000100&
%SQL_DL_SQL92_INTERVAL_YEAR_TO_MONTH    = &H00000200&
%SQL_DL_SQL92_INTERVAL_DAY_TO_HOUR      = &H00000400&
%SQL_DL_SQL92_INTERVAL_DAY_TO_MINUTE    = &H00000800&
%SQL_DL_SQL92_INTERVAL_DAY_TO_SECOND    = &H00001000&
%SQL_DL_SQL92_INTERVAL_HOUR_TO_MINUTE   = &H00002000&
%SQL_DL_SQL92_INTERVAL_HOUR_TO_SECOND   = &H00004000&
%SQL_DL_SQL92_INTERVAL_MINUTE_TO_SECOND = &H00008000&

' SQL_CATALOG_LOCATION values */
%SQL_CL_START = %SQL_QL_START
%SQL_CL_END   = %SQL_QL_END

' values for SQL_BATCH_ROW_COUNT */
%SQL_BRC_PROCEDURES = &H0000001
%SQL_BRC_EXPLICIT   = &H0000002
%SQL_BRC_ROLLED_UP  = &H0000004

' bitmasks for SQL_BATCH_SUPPORT */
%SQL_BS_SELECT_EXPLICIT    = &H00000001&
%SQL_BS_ROW_COUNT_EXPLICIT = &H00000002&
%SQL_BS_SELECT_PROC        = &H00000004&
%SQL_BS_ROW_COUNT_PROC     = &H00000008&

' Values for SQL_PARAM_ARRAY_ROW_COUNTS getinfo */
%SQL_PARC_BATCH    = 1
%SQL_PARC_NO_BATCH = 2

' values for SQL_PARAM_ARRAY_SELECT_BATCH*/
%SQL_PAS_BATCH     = 1
%SQL_PAS_NO_BATCH  = 2
%SQL_PAS_NO_SELECT = 3

' Bitmasks for SQL_INDEX_KEYWORDS */
%SQL_IK_NONE = &H00000000&
%SQL_IK_ASC  = &H00000001&
%SQL_IK_DESC = &H00000002&
%SQL_IK_ALL  = %SQL_IK_ASC OR %SQL_IK_DESC

' Bitmasks for SQL_INFO_SCHEMA_VIEWS */

%SQL_ISV_ASSERTIONS              = &H00000001&
%SQL_ISV_CHARACTER_SETS          = &H00000002&
%SQL_ISV_CHECK_CONSTRAINTS       = &H00000004&
%SQL_ISV_COLLATIONS              = &H00000008&
%SQL_ISV_COLUMN_DOMAIN_USAGE     = &H00000010&
%SQL_ISV_COLUMN_PRIVILEGES       = &H00000020&
%SQL_ISV_COLUMNS                 = &H00000040&
%SQL_ISV_CONSTRAINT_COLUMN_USAGE = &H00000080&
%SQL_ISV_CONSTRAINT_TABLE_USAGE  = &H00000100&
%SQL_ISV_DOMAIN_CONSTRAINTS      = &H00000200&
%SQL_ISV_DOMAINS                 = &H00000400&
%SQL_ISV_KEY_COLUMN_USAGE        = &H00000800&
%SQL_ISV_REFERENTIAL_CONSTRAINTS = &H00001000&
%SQL_ISV_SCHEMATA                = &H00002000&
%SQL_ISV_SQL_LANGUAGES           = &H00004000&
%SQL_ISV_TABLE_CONSTRAINTS       = &H00008000&
%SQL_ISV_TABLE_PRIVILEGES        = &H00010000&
%SQL_ISV_TABLES                  = &H00020000&
%SQL_ISV_TRANSLATIONS            = &H00040000&
%SQL_ISV_USAGE_PRIVILEGES        = &H00080000&
%SQL_ISV_VIEW_COLUMN_USAGE       = &H00100000&
%SQL_ISV_VIEW_TABLE_USAGE        = &H00200000&
%SQL_ISV_VIEWS                   = &H00400000&

' Bitmasks for SQL_ASYNC_MODE */

'%SQL_AM_NONE         = 0
'%SQL_AM_CONNECTION   = 1
'%SQL_AM_STATEMENT    = 2

' Bitmasks for SQL_ALTER_DOMAIN */
%SQL_AD_CONSTRAINT_NAME_DEFINITION         = &H00000001&
%SQL_AD_ADD_DOMAIN_CONSTRAINT              = &H00000002&
%SQL_AD_DROP_DOMAIN_CONSTRAINT             = &H00000004&
%SQL_AD_ADD_DOMAIN_DEFAULT                 = &H00000008&
%SQL_AD_DROP_DOMAIN_DEFAULT                = &H00000010&
%SQL_AD_ADD_CONSTRAINT_INITIALLY_DEFERRED  = &H00000020&
%SQL_AD_ADD_CONSTRAINT_INITIALLY_IMMEDIATE = &H00000040&
%SQL_AD_ADD_CONSTRAINT_DEFERRABLE          = &H00000080&
%SQL_AD_ADD_CONSTRAINT_NON_DEFERRABLE      = &H00000100&


' SQL_CREATE_SCHEMA bitmasks */
%SQL_CS_CREATE_SCHEMA         = &H00000001&
%SQL_CS_AUTHORIZATION         = &H00000002&
%SQL_CS_DEFAULT_CHARACTER_SET = &H00000004&

' SQL_CREATE_TRANSLATION bitmasks */
%SQL_CTR_CREATE_TRANSLATION = &H00000001&

' SQL_CREATE_ASSERTION bitmasks */
%SQL_CA_CREATE_ASSERTION               = &H00000001&
%SQL_CA_CONSTRAINT_INITIALLY_DEFERRED  = &H00000010&
%SQL_CA_CONSTRAINT_INITIALLY_IMMEDIATE = &H00000020&
%SQL_CA_CONSTRAINT_DEFERRABLE          = &H00000040&
%SQL_CA_CONSTRAINT_NON_DEFERRABLE      = &H00000080&

' SQL_CREATE_CHARACTER_SET bitmasks */
%SQL_CCS_CREATE_CHARACTER_SET = &H00000001&
%SQL_CCS_COLLATE_CLAUSE       = &H00000002&
%SQL_CCS_LIMITED_COLLATION    = &H00000004&

' SQL_CREATE_COLLATION bitmasks */
%SQL_CCOL_CREATE_COLLATION = &H00000001&

' SQL_CREATE_DOMAIN bitmasks */
%SQL_CDO_CREATE_DOMAIN                  = &H00000001&
%SQL_CDO_DEFAULT                        = &H00000002&
%SQL_CDO_CONSTRAINT                     = &H00000004&
%SQL_CDO_COLLATION                      = &H00000008&
%SQL_CDO_CONSTRAINT_NAME_DEFINITION     = &H00000010&
%SQL_CDO_CONSTRAINT_INITIALLY_DEFERRED  = &H00000020&
%SQL_CDO_CONSTRAINT_INITIALLY_IMMEDIATE = &H00000040&
%SQL_CDO_CONSTRAINT_DEFERRABLE          = &H00000080&
%SQL_CDO_CONSTRAINT_NON_DEFERRABLE      = &H00000100&

' SQL_CREATE_TABLE bitmasks */
%SQL_CT_CREATE_TABLE                   = &H00000001&
%SQL_CT_COMMIT_PRESERVE                = &H00000002&
%SQL_CT_COMMIT_DELETE                  = &H00000004&
%SQL_CT_GLOBAL_TEMPORARY               = &H00000008&
%SQL_CT_LOCAL_TEMPORARY                = &H00000010&
%SQL_CT_CONSTRAINT_INITIALLY_DEFERRED  = &H00000020&
%SQL_CT_CONSTRAINT_INITIALLY_IMMEDIATE = &H00000040&
%SQL_CT_CONSTRAINT_DEFERRABLE          = &H00000080&
%SQL_CT_CONSTRAINT_NON_DEFERRABLE      = &H00000100&
%SQL_CT_COLUMN_CONSTRAINT              = &H00000200&
%SQL_CT_COLUMN_DEFAULT                 = &H00000400&
%SQL_CT_COLUMN_COLLATION               = &H00000800&
%SQL_CT_TABLE_CONSTRAINT               = &H00001000&
%SQL_CT_CONSTRAINT_NAME_DEFINITION     = &H00002000&

' SQL_DDL_INDEX bitmasks */
%SQL_DI_CREATE_INDEX = &H00000001&
%SQL_DI_DROP_INDEX   = &H00000002&

' SQL_DROP_COLLATION bitmasks */
%SQL_DC_DROP_COLLATION = &H00000001&

' SQL_DROP_DOMAIN bitmasks */
%SQL_DD_DROP_DOMAIN = &H00000001&
%SQL_DD_RESTRICT    = &H00000002&
%SQL_DD_CASCADE     = &H00000004&

' SQL_DROP_SCHEMA bitmasks */
%SQL_DS_DROP_SCHEMA = &H00000001&
%SQL_DS_RESTRICT    = &H00000002&
%SQL_DS_CASCADE     = &H00000004&

' SQL_DROP_CHARACTER_SET bitmasks */
%SQL_DCS_DROP_CHARACTER_SET = &H00000001&

' SQL_DROP_ASSERTION bitmasks */
%SQL_DA_DROP_ASSERTION = &H00000001&

' SQL_DROP_TABLE bitmasks */
%SQL_DT_DROP_TABLE = &H00000001&
%SQL_DT_RESTRICT   = &H00000002&
%SQL_DT_CASCADE    = &H00000004&

' SQL_DROP_TRANSLATION bitmasks */
%SQL_DTR_DROP_TRANSLATION = &H00000001&

' SQL_DROP_VIEW bitmasks */
%SQL_DV_DROP_VIEW = &H00000001&
%SQL_DV_RESTRICT  = &H00000002&
%SQL_DV_CASCADE   = &H00000004&

' SQL_INSERT_STATEMENT bitmasks */
%SQL_IS_INSERT_LITERALS = &H00000001&
%SQL_IS_INSERT_SEARCHED = &H00000002&
%SQL_IS_SELECT_INTO     = &H00000004&

' SQL_ODBC_INTERFACE_CONFORMANCE values */
%SQL_OIC_CORE   = 1???
%SQL_OIC_LEVEL1 = 2???
%SQL_OIC_LEVEL2 = 3???

' SQL_SQL92_FOREIGN_KEY_DELETE_RULE bitmasks */
%SQL_SFKD_CASCADE     = &H00000001&
%SQL_SFKD_NO_ACTION   = &H00000002&
%SQL_SFKD_SET_DEFAULT = &H00000004&
%SQL_SFKD_SET_NULL    = &H00000008&

' SQL_SQL92_FOREIGN_KEY_UPDATE_RULE bitmasks */
%SQL_SFKU_CASCADE     = &H00000001&
%SQL_SFKU_NO_ACTION   = &H00000002&
%SQL_SFKU_SET_DEFAULT = &H00000004&
%SQL_SFKU_SET_NULL    = &H00000008&

' SQL_SQL92_GRANT  bitmasks */
%SQL_SG_USAGE_ON_DOMAIN        = &H00000001&
%SQL_SG_USAGE_ON_CHARACTER_SET = &H00000002&
%SQL_SG_USAGE_ON_COLLATION     = &H00000004&
%SQL_SG_USAGE_ON_TRANSLATION   = &H00000008&
%SQL_SG_WITH_GRANT_OPTION      = &H00000010&
%SQL_SG_DELETE_TABLE           = &H00000020&
%SQL_SG_INSERT_TABLE           = &H00000040&
%SQL_SG_INSERT_COLUMN          = &H00000080&
%SQL_SG_REFERENCES_TABLE       = &H00000100&
%SQL_SG_REFERENCES_COLUMN      = &H00000200&
%SQL_SG_SELECT_TABLE           = &H00000400&
%SQL_SG_UPDATE_TABLE           = &H00000800&
%SQL_SG_UPDATE_COLUMN          = &H00001000&

' SQL_SQL92_PREDICATES bitmasks */
%SQL_SP_EXISTS                = &H00000001&
%SQL_SP_ISNOTNULL             = &H00000002&
%SQL_SP_ISNULL                = &H00000004&
%SQL_SP_MATCH_FULL            = &H00000008&
%SQL_SP_MATCH_PARTIAL         = &H00000010&
%SQL_SP_MATCH_UNIQUE_FULL     = &H00000020&
%SQL_SP_MATCH_UNIQUE_PARTIAL  = &H00000040&
%SQL_SP_OVERLAPS              = &H00000080&
%SQL_SP_UNIQUE                = &H00000100&
%SQL_SP_LIKE                  = &H00000200&
%SQL_SP_IN                    = &H00000400&
%SQL_SP_BETWEEN               = &H00000800&
%SQL_SP_COMPARISON            = &H00001000&
%SQL_SP_QUANTIFIED_COMPARISON = &H00002000&

' SQL_SQL92_RELATIONAL_JOIN_OPERATORS bitmasks */
%SQL_SRJO_CORRESPONDING_CLAUSE = &H00000001&
%SQL_SRJO_CROSS_JOIN           = &H00000002&
%SQL_SRJO_EXCEPT_JOIN          = &H00000004&
%SQL_SRJO_FULL_OUTER_JOIN      = &H00000008&
%SQL_SRJO_INNER_JOIN           = &H00000010&
%SQL_SRJO_INTERSECT_JOIN       = &H00000020&
%SQL_SRJO_LEFT_OUTER_JOIN      = &H00000040&
%SQL_SRJO_NATURAL_JOIN         = &H00000080&
%SQL_SRJO_RIGHT_OUTER_JOIN     = &H00000100&
%SQL_SRJO_UNION_JOIN           = &H00000200&

' SQL_SQL92_REVOKE bitmasks */
%SQL_SR_USAGE_ON_DOMAIN        = &H00000001&
%SQL_SR_USAGE_ON_CHARACTER_SET = &H00000002&
%SQL_SR_USAGE_ON_COLLATION     = &H00000004&
%SQL_SR_USAGE_ON_TRANSLATION   = &H00000008&
%SQL_SR_GRANT_OPTION_FOR       = &H00000010&
%SQL_SR_CASCADE                = &H00000020&
%SQL_SR_RESTRICT               = &H00000040&
%SQL_SR_DELETE_TABLE           = &H00000080&
%SQL_SR_INSERT_TABLE           = &H00000100&
%SQL_SR_INSERT_COLUMN          = &H00000200&
%SQL_SR_REFERENCES_TABLE       = &H00000400&
%SQL_SR_REFERENCES_COLUMN      = &H00000800&
%SQL_SR_SELECT_TABLE           = &H00001000&
%SQL_SR_UPDATE_TABLE           = &H00002000&
%SQL_SR_UPDATE_COLUMN          = &H00004000&

' SQL_SQL92_ROW_VALUE_CONSTRUCTOR bitmasks */
%SQL_SRVC_VALUE_EXPRESSION = &H00000001&
%SQL_SRVC_NULL             = &H00000002&
%SQL_SRVC_DEFAULT          = &H00000004&
%SQL_SRVC_ROW_SUBQUERY     = &H00000008&

' SQL_SQL92_VALUE_EXPRESSIONS bitmasks */
%SQL_SVE_CASE     = &H00000001&
%SQL_SVE_CAST     = &H00000002&
%SQL_SVE_COALESCE = &H00000004&
%SQL_SVE_NULLIF   = &H00000008&

' SQL_STANDARD_CLI_CONFORMANCE bitmasks */
%SQL_SCC_XOPEN_CLI_VERSION1 = &H00000001&
%SQL_SCC_ISO92_CLI          = &H00000002&

' SQL_UNION_STATEMENT bitmasks */
%SQL_US_UNION     = %SQL_U_UNION
%SQL_US_UNION_ALL = %SQL_U_UNION_ALL

'/* SQL_DTC_TRANSITION_COST bitmasks */
%SQL_DTC_ENLIST_EXPENSIVE   = &H00000001&
%SQL_DTC_UNENLIST_EXPENSIVE = &H00000002&

' additional SQLDataSources fetch directions */
%SQL_FETCH_FIRST_USER   = 31
%SQL_FETCH_FIRST_SYSTEM = 32

' Defines for SQLSetPos */
%SQL_ENTIRE_ROWSET = 0

' Operations in SQLSetPos */
%SQL_POSITION = 0   '      1.0 FALSE */
%SQL_REFRESH  = 1   '      1.0 TRUE */
%SQL_UPDATE   = 2
%SQL_DELETE   = 3

' Operations in SQLBulkOperations */
%SQL_ADD                     = 4
%SQL_SETPOS_MAX_OPTION_VALUE = %SQL_ADD
%SQL_UPDATE_BY_BOOKMARK      = 5
%SQL_DELETE_BY_BOOKMARK      = 6
%SQL_FETCH_BY_BOOKMARK       = 7

' Lock options in SQLSetPos */
%SQL_LOCK_NO_CHANGE = 0   '      1.0 FALSE */
%SQL_LOCK_EXCLUSIVE = 1   '      1.0 TRUE */
%SQL_LOCK_UNLOCK    = 2

%SQL_SETPOS_MAX_LOCK_VALUE = %SQL_LOCK_UNLOCK

' Column types and scopes in SQLSpecialColumns.  */
%SQL_BEST_ROWID = 1
%SQL_ROWVER     = 2

' Defines for SQLSpecialColumns (returned in the result set)
'   SQL_PC_UNKNOWN and SQL_PC_PSEUDO are defined in sql.h */
%SQL_PC_NOT_PSEUDO = 1

' Defines for SQLStatistics */
%SQL_QUICK  = 0
%SQL_ENSURE = 1

' Defines for SQLStatistics (returned in the result set)
'   SQL_INDEX_CLUSTERED, SQL_INDEX_HASHED, and SQL_INDEX_OTHER are
'   defined in sql.h */
%SQL_TABLE_STAT = 0


' Defines for SQLTables */
'#if (ODBCVER >= 0x0300)
'$SQL_ALL_CATALOGS                "%"
'$SQL_ALL_SCHEMAS                 "%"
'$SQL_ALL_TABLE_TYPES             "%"
'#endif  ' ODBCVER >= 0x0300 */

' Options for SQLDriverConnect */
%SQL_DRIVER_NOPROMPT          = 0
%SQL_DRIVER_COMPLETE          = 1
%SQL_DRIVER_PROMPT            = 2
%SQL_DRIVER_COMPLETE_REQUIRED = 3


' ========================================================================================
' SQLDriverConnect is an alternative to SQLConnect. It supports data sources that require
' more connection information than the three arguments in SQLConnect, dialog boxes to
' prompt the user for all connection information, and data sources that are not defined in
' the system information.
' ========================================================================================
' SQLRETURN SQL_API SQLDriverConnect(
'           SQLHDBC            hdbc,
'           SQLHWND            hwnd,
'           SQLCHAR           *szConnStrIn,
'           SQLSMALLINT        cbConnStrIn,
'           SQLCHAR           *szConnStrOut,
'           SQLSMALLINT        cbConnStrOutMax,
'           SQLSMALLINT       *pcbConnStrOut,
'           SQLUSMALLINT       fDriverCompletion);
' ========================================================================================
DECLARE FUNCTION SQLDriverConnect LIB "ODBC32.DLL" ALIAS "SQLDriverConnect" ( _
        BYVAL hDbc              AS DWORD, _
        BYVAL hWnd              AS DWORD, _
        BYREF szConnStrIn       AS ASCIIZ, _
        BYVAL cbConnStrIn       AS INTEGER, _
        BYREF szConnStrOut      AS ASCIIZ, _
        BYVAL cbConnStrOutMax   AS INTEGER, _
        BYREF pcbConnStrOut     AS INTEGER, _
        BYVAL fDriverCompletion AS WORD _
        ) AS INTEGER
' ========================================================================================


' Level 2 Functions                             */

' SQLExtendedFetch "fFetchType" values */
%SQL_FETCH_BOOKMARK = 8

' SQLExtendedFetch "rgfRowStatus" element values */
%SQL_ROW_SUCCESS           = 0
%SQL_ROW_DELETED           = 1
%SQL_ROW_UPDATED           = 2
%SQL_ROW_NOROW             = 3
%SQL_ROW_ADDED             = 4
%SQL_ROW_ERROR             = 5
%SQL_ROW_SUCCESS_WITH_INFO = 6
%SQL_ROW_PROCEED           = 0
%SQL_ROW_IGNORE            = 1

' value for SQL_DESC_ARRAY_STATUS_PTR */
%SQL_PARAM_SUCCESS           = 0
%SQL_PARAM_SUCCESS_WITH_INFO = 6
%SQL_PARAM_ERROR             = 5
%SQL_PARAM_UNUSED            = 7
%SQL_PARAM_DIAG_UNAVAILABLE  = 1

%SQL_PARAM_PROCEED           = 0
%SQL_PARAM_IGNORE            = 1

' Defines for SQLForeignKeys (returned in result set) */
%SQL_CASCADE             = 0
%SQL_RESTRICT            = 1
%SQL_SET_NULL            = 2
%SQL_NO_ACTION           = 3
%SQL_SET_DEFAULT         = 4

'/* Note that the following are in a different column of SQLForeignKeys than */
'/* the previous #defines.   These are for DEFERRABILITY.                    */

%SQL_INITIALLY_DEFERRED  = 5
%SQL_INITIALLY_IMMEDIATE = 6
%SQL_NOT_DEFERRABLE      = 7

' Defines for SQLProcedures (returned in the result set) */
%SQL_PT_UNKNOWN   = 0
%SQL_PT_PROCEDURE = 1
%SQL_PT_FUNCTION  = 2

'#ifndef RC_INVOKED

'      This define is too large for RC */
#IF 0
/*
%SQL_ODBC_KEYWORDS \
"ABSOLUTE,ACTION,ADA,ADD,ALL,ALLOCATE,ALTER,AND,ANY,ARE,AS,"\
"ASC,ASSERTION,AT,AUTHORIZATION,AVG,"\
"BEGIN,BETWEEN,BIT,BIT_LENGTH,BOTH,BY,CASCADE,CASCADED,CASE,CAST,CATALOG,"\
"CHAR,CHAR_LENGTH,CHARACTER,CHARACTER_LENGTH,CHECK,CLOSE,COALESCE,"\
"COLLATE,COLLATION,COLUMN,COMMIT,CONNECT,CONNECTION,CONSTRAINT,"\
"CONSTRAINTS,CONTINUE,CONVERT,CORRESPONDING,COUNT,CREATE,CROSS,CURRENT,"\
"CURRENT_DATE,CURRENT_TIME,CURRENT_TIMESTAMP,CURRENT_USER,CURSOR,"\
"DATE,DAY,DEALLOCATE,DEC,DECIMAL,DECLARE,DEFAULT,DEFERRABLE,"\
"DEFERRED,DELETE,DESC,DESCRIBE,DESCRIPTOR,DIAGNOSTICS,DISCONNECT,"\
"DISTINCT,DOMAIN,DOUBLE,DROP,"\
"ELSE,END,END-EXEC,ESCAPE,EXCEPT,EXCEPTION,EXEC,EXECUTE,"\
"EXISTS,EXTERNAL,EXTRACT,"\
"FALSE,FETCH,FIRST,FLOAT,FOR,FOREIGN,FORTRAN,FOUND,FROM,FULL,"\
"GET,GLOBAL,GO,GOTO,GRANT,GROUP,HAVING,HOUR,"\
"IDENTITY,IMMEDIATE,IN,INCLUDE,INDEX,INDICATOR,INITIALLY,INNER,"\
"INPUT,INSENSITIVE,INSERT,INT,INTEGER,INTERSECT,INTERVAL,INTO,IS,ISOLATION,"\
"JOIN,KEY,LANGUAGE,LAST,LEADING,LEFT,LEVEL,LIKE,LOCAL,LOWER,"\
"MATCH,MAX,MIN,MINUTE,MODULE,MONTH,"\
"NAMES,NATIONAL,NATURAL,NCHAR,NEXT,NO,NONE,NOT,NULL,NULLIF,NUMERIC,"\
"OCTET_LENGTH,OF,ON,ONLY,OPEN,OPTION,OR,ORDER,OUTER,OUTPUT,OVERLAPS,"\
"PAD,PARTIAL,PASCAL,PLI,POSITION,PRECISION,PREPARE,PRESERVE,"\
"PRIMARY,PRIOR,PRIVILEGES,PROCEDURE,PUBLIC,"\
"READ,REAL,REFERENCES,RELATIVE,RESTRICT,REVOKE,RIGHT,ROLLBACK,ROWS"\
"SCHEMA,SCROLL,SECOND,SECTION,SELECT,SESSION,SESSION_USER,SET,SIZE,"\
"SMALLINT,SOME,SPACE,SQL,SQLCA,SQLCODE,SQLERROR,SQLSTATE,SQLWARNING,"\
"SUBSTRING,SUM,SYSTEM_USER,"\
"TABLE,TEMPORARY,THEN,TIME,TIMESTAMP,TIMEZONE_HOUR,TIMEZONE_MINUTE,"\
"TO,TRAILING,TRANSACTION,TRANSLATE,TRANSLATION,TRIM,TRUE,"\
"UNION,UNIQUE,UNKNOWN,UPDATE,UPPER,USAGE,USER,USING,"\
"VALUE,VALUES,VARCHAR,VARYING,VIEW,WHEN,WHENEVER,WHERE,WITH,WORK,WRITE,"\
"YEAR,ZONE"
*/
#ENDIF

' ========================================================================================
' SQLBrowseConnect supports an iterative method of discovering and enumerating the
' attributes and attribute values required to connect to a data source. Each call to
' SQLBrowseConnect returns successive levels of attributes and attribute values. When all
' levels have been enumerated, a connection to the data source is completed and a complete
' connection string is returned by SQLBrowseConnect. A return code of SQL_SUCCESS or
' SQL_SUCCESS_WITH_INFO indicates that all connection information has been specified and
' the application is now connected to the data source.
' ========================================================================================
' SQLRETURN SQL_API SQLBrowseConnect(
'           SQLHDBC            hdbc,
'           SQLCHAR           *szConnStrIn,
'           SQLSMALLINT        cbConnStrIn,
'           SQLCHAR           *szConnStrOut,
'           SQLSMALLINT        cbConnStrOutMax,
'           SQLSMALLINT       *pcbConnStrOut);
' ========================================================================================
DECLARE FUNCTION SQLBrowseConnect LIB "ODBC32.DLL" ALIAS "SQLBrowseConnect" ( _
        BYVAL hDbc            AS DWORD, _
        BYREF szConnStrIn     AS ASCIIZ, _
        BYVAL cbConnStrIn     AS INTEGER, _
        BYREF szConnStrOut    AS ASCIIZ, _
        BYVAL cbConnStrOutMax AS INTEGER, _
        BYREF pcbConnStrOut   AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' SQLBulkOperations performs bulk insertions and bulk bookmark operations, including
' update, delete, and fetch by bookmark.
' ========================================================================================
' SQLRETURN SQL_API SQLBulkOperations(
'           SQLHSTMT            StatementHandle,
'           SQLSMALLINT         Operation);
' ========================================================================================
DECLARE FUNCTION SQLBulkOperations LIB "ODBC32.DLL" ALIAS "SQLBulkOperations" ( _
        BYVAL StatementHandle AS DWORD, _
        BYVAL Operation       AS LONG _
        ) AS INTEGER

' ========================================================================================
' Deprecated. In ODBC 3.x, the ODBC 2.0 function SQLColAttributes has been replaced by
' SQLColAttribute.
' ========================================================================================
' SQLRETURN SQL_API SQLColAttributes(
'           SQLHSTMT           hstmt,
'           SQLUSMALLINT       icol,
'           SQLUSMALLINT       fDescType,
'           SQLPOINTER         rgbDesc,
'           SQLSMALLINT        cbDescMax,
'           SQLSMALLINT       *pcbDesc,
'           SQLINTEGER        *pfDesc);
' ========================================================================================
DECLARE FUNCTION SQLColAttributes LIB "ODBC32.DLL" ALIAS "SQLColAttributes" ( _
        BYVAL hstmt     AS DWORD, _
        BYVAL icol      AS WORD, _
        BYVAL fDescType AS WORD, _
        BYREF rgbDesc   AS ANY, _
        BYVAL cbDescMax AS INTEGER, _
        BYREF pcbDesc   AS INTEGER, _
        BYREF pfDesc    AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' SQLColumnPrivileges returns a list of columns and associated privileges for the
' specified table. The driver returns the information as a result set on the specified
' StatementHandle.
' ========================================================================================
' SQLRETURN SQL_API SQLColumnPrivileges(
'           SQLHSTMT           hstmt,
'           SQLCHAR           *szCatalogName,
'           SQLSMALLINT        cbCatalogName,
'           SQLCHAR           *szSchemaName,
'           SQLSMALLINT        cbSchemaName,
'           SQLCHAR           *szTableName,
'           SQLSMALLINT        cbTableName,
'           SQLCHAR           *szColumnName,
'           SQLSMALLINT        cbColumnName);
' ========================================================================================
DECLARE FUNCTION SQLColumnPrivileges LIB "ODBC32.DLL" ALIAS "SQLColumnPrivileges" ( _
        BYVAL hstmt         AS DWORD, _
        BYREF szCatalogName AS ASCIIZ, _
        BYVAL cbCatalogName AS INTEGER, _
        BYREF szSchemaName  AS ASCIIZ, _
        BYVAL cbSchemaName  AS INTEGER, _
        BYREF szTableName   AS ASCIIZ, _
        BYVAL cbTableName   AS INTEGER, _
        BYREF szColumnName  AS ASCIIZ, _
        BYVAL cbColumnName  AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' SQLDescribeParam returns the description of a parameter marker associated with a
' prepared SQL statement. This information is also available in the fields of the IPD.
' ========================================================================================
' SQLRETURN SQL_API SQLDescribeParam(
'           SQLHSTMT           hstmt,
'           SQLUSMALLINT       ipar,
'           SQLSMALLINT       *pfSqlType,
'           SQLUINTEGER       *pcbParamDef,
'           SQLSMALLINT       *pibScale,
'           SQLSMALLINT       *pfNullable);
' ========================================================================================
DECLARE FUNCTION SQLDescribeParam LIB "ODBC32.DLL" ALIAS "SQLDescribeParam" ( _
        BYVAL hstmt        AS DWORD, _
        BYVAL ipar         AS WORD, _
        BYREF pfSqlType    AS INTEGER, _
        BYREF pfcbParamDef AS DWORD, _
        BYREF pibScale     AS INTEGER, _
        BYREF pfNullable   AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' SQLExtendedFetch fetches the specified rowset of data from the result set and returns
' data for all bound columns. Rowsets can be specified at an absolute or relative position
' or by bookmark.
' Note In ODBC 3.x, SQLExtendedFetch has been replaced by SQLFetchScroll. ODBC 3.x
' applications should not call SQLExtendedFetch; instead they should call SQLFetchScroll.
' The Driver Manager maps SQLFetchScroll to SQLExtendedFetch when working with an ODBC 2.x
' driver. ODBC 3.x drivers should support SQLExtendedFetch if they want to work with
' ODBC 2.x applications that call it.
' ========================================================================================
' SQLRETURN SQL_API SQLExtendedFetch(
'           SQLHSTMT           hstmt,
'           SQLUSMALLINT       fFetchType,
'           SQLINTEGER         irow,
'           SQLUINTEGER       *pcrow,
'           SQLUSMALLINT      *rgfRowStatus);
' ========================================================================================
DECLARE FUNCTION SQLExtendedFetch LIB "ODBC32.DLL" ALIAS "SQLExtendedFetch" ( _
        BYVAL hstmt        AS DWORD, _
        BYVAL fFetchType   AS WORD, _
        BYVAL irow         AS LONG, _
        BYREF pcrow        AS DWORD, _
        BYVAL rgfRowStatus AS DWORD _
        ) AS INTEGER

' ========================================================================================
' SQLForeignKeys can return:
'    * A list of foreign keys in the specified table (columns in the specified table that
'      refer to primary keys in other tables).
'    * A list of foreign keys in other tables that refer to the primary key in the
'      specified table.
' The driver returns each list as a result set on the specified statement.
' ========================================================================================
' SQLRETURN SQL_API SQLForeignKeys(
'           SQLHSTMT           hstmt,
'           SQLCHAR           *szPkCatalogName,
'           SQLSMALLINT        cbPkCatalogName,
'           SQLCHAR           *szPkSchemaName,
'           SQLSMALLINT        cbPkSchemaName,
'           SQLCHAR           *szPkTableName,
'           SQLSMALLINT        cbPkTableName,
'           SQLCHAR           *szFkCatalogName,
'           SQLSMALLINT        cbFkCatalogName,
'           SQLCHAR           *szFkSchemaName,
'           SQLSMALLINT        cbFkSchemaName,
'           SQLCHAR           *szFkTableName,
'           SQLSMALLINT        cbFkTableName);
' ========================================================================================
DECLARE FUNCTION SQLForeignKeys LIB "ODBC32.DLL" ALIAS "SQLForeignKeys" ( _
        BYVAL hstmt           AS DWORD, _
        BYREF szPkCatalogName AS ASCIIZ, _
        BYVAL cbPkCatalogName AS INTEGER, _
        BYREF szPkSchemaName  AS ASCIIZ, _
        BYVAL cbPkSchemaName  AS INTEGER, _
        BYREF szPkTableName   AS ASCIIZ, _
        BYVAL cbPkTableName   AS INTEGER, _
        BYREF szFkCatalogName AS ASCIIZ, _
        BYVAL cbFkCatalogName AS INTEGER, _
        BYREF szFkSchemaName  AS ASCIIZ, _
        BYVAL cbFkSchemaName  AS INTEGER, _
        BYREF szFkTableName   AS ASCIIZ, _
        BYVAL cbFkTableName   AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' SQLMoreResults determines whether more results are available on a statement containing
' SELECT, UPDATE, INSERT, or DELETE statements and, if so, initializes processing for
' those results.
' ========================================================================================
' SQLRETURN SQL_API SQLMoreResults(
'           SQLHSTMT           hstmt);
' ========================================================================================
DECLARE FUNCTION SQLMoreResults LIB "ODBC32.DLL" ALIAS "SQLMoreResults" ( _
        BYVAL hstmt AS DWORD _
        ) AS INTEGER

' ========================================================================================
' Returns the SQL string as modified by the driver. SQLNativeSql does not execute the
' SQL statement.
' ========================================================================================
' SQLRETURN SQL_API SQLNativeSql(
'           SQLHDBC            hdbc,
'           SQLCHAR           *szSqlStrIn,
'           SQLINTEGER         cbSqlStrIn,
'           SQLCHAR           *szSqlStr,
'           SQLINTEGER         cbSqlStrMax,
'           SQLINTEGER        *pcbSqlStr);
' ========================================================================================
DECLARE FUNCTION SQLNativeSql LIB "ODBC32.DLL" ALIAS "SQLNativeSql" ( _
        BYVAL hdbc        AS DWORD, _
        BYREF szSqlStrIn  AS ASCIIZ, _
        BYVAL cbSqlStrIn  AS LONG, _
        BYREF szSqlStr    AS ASCIIZ, _
        BYVAL cbSqlStrMax AS LONG, _
        BYREF pcbSqlStr   AS LONG _
        ) AS INTEGER

' ========================================================================================
' Returns the number of parameters in an SQL statement.
' ========================================================================================
' SQLRETURN SQL_API SQLNumParams(
'           SQLHSTMT    hstmt,
'           SQLSMALLINT *pcpar);
' ========================================================================================
DECLARE FUNCTION SQLNumParams LIB "ODBC32.DLL" ALIAS "SQLNumParams" ( _
        BYVAL hstmt AS DWORD, _
        BYREF pcpar AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' The ODBC 2.0 function SQLParamOptions has been replaced in ODBC 3.x by calls to
' SQLSetStmtAttr.
' ========================================================================================
' SQLRETURN SQL_API SQLParamOptions(
'           SQLHSTMT     hstmt,
'           SQLUINTEGER  crow,
'           SQLUINTEGER *pirow);
' ========================================================================================
DECLARE FUNCTION SQLParamOptions LIB "ODBC32.DLL" ALIAS "SQLParamOptions" ( _
        BYVAL hstmt AS DWORD, _
        BYVAL crow  AS DWORD, _
        BYREF pirow AS DWORD _
        ) AS INTEGER

' ========================================================================================
' Returns the column names that make up the primary key for a table. The driver returns
' the information as a result set. This function does not support returning primary keys
' from multiple tables in a single call.
' ========================================================================================
' SQLRETURN SQL_API SQLPrimaryKeys(
'           SQLHSTMT           hstmt,
'           SQLCHAR           *szCatalogName,
'           SQLSMALLINT        cbCatalogName,
'           SQLCHAR           *szSchemaName,
'           SQLSMALLINT        cbSchemaName,
'           SQLCHAR           *szTableName,
'           SQLSMALLINT        cbTableName);
' ========================================================================================
DECLARE FUNCTION SQLPrimaryKeys LIB "ODBC32.DLL" ALIAS "SQLPrimaryKeys" ( _
        BYVAL hstmt         AS DWORD, _
        BYREF szCatalogName AS ASCIIZ, _
        BYVAL cbCatalogName AS INTEGER, _
        BYREF szSchemaName  AS ASCIIZ, _
        BYVAL cbSchemaName  AS INTEGER, _
        BYREF szTableName   AS ASCIIZ, _
        BYVAL cbTableName   AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' Returns the list of input and output parameters, as well as the columns that make up the
' result set for the specified procedures. The driver returns the information as a result
' set on the specified statement.
' ========================================================================================
' SQLRETURN SQL_API SQLProcedureColumns(
'           SQLHSTMT           hstmt,
'           SQLCHAR           *szCatalogName,
'           SQLSMALLINT        cbCatalogName,
'           SQLCHAR           *szSchemaName,
'           SQLSMALLINT        cbSchemaName,
'           SQLCHAR           *szProcName,
'           SQLSMALLINT        cbProcName,
'           SQLCHAR           *szColumnName,
'           SQLSMALLINT        cbColumnName);
' ========================================================================================
DECLARE FUNCTION SQLProcedureColumns LIB "ODBC32.DLL" ALIAS "SQLProcedureColumns" ( _
        BYVAL hstmt         AS DWORD, _
        BYREF szCatalogName AS ASCIIZ, _
        BYVAL cbCatalogName AS INTEGER, _
        BYREF szSchemaName  AS ASCIIZ, _
        BYVAL cbSchemaName  AS INTEGER, _
        BYREF szProcName    AS ASCIIZ, _
        BYVAL cbProcName    AS INTEGER, _
        BYREF szColumnName  AS ASCIIZ, _
        BYVAL cbColumnName  AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' eturns the list of procedure names stored in a specific data source. Procedure is a
' generic term used to describe an executable object, or a named entity that can be
' invoked using input and output parameters. For more information on procedures, see the
' Procedures.
' ========================================================================================
' SQLRETURN SQL_API SQLProcedures(
'           SQLHSTMT           hstmt,
'           SQLCHAR           *szCatalogName,
'           SQLSMALLINT        cbCatalogName,
'           SQLCHAR           *szSchemaName,
'           SQLSMALLINT        cbSchemaName,
'           SQLCHAR           *szProcName,
'           SQLSMALLINT        cbProcName);
' ========================================================================================
DECLARE FUNCTION SQLProcedures LIB "ODBC32.DLL" ALIAS "SQLProcedures" ( _
        BYVAL hstmt         AS DWORD, _
        BYREF szCatalogName AS ASCIIZ, _
        BYVAL cbCatalogName AS INTEGER, _
        BYREF szSchemaName  AS ASCIIZ, _
        BYVAL cbSchemaName  AS INTEGER, _
        BYREF szProcName    AS ASCIIZ, _
        BYVAL cbProcName    AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' Sets the cursor position in a rowset and allows an application to refresh data in the
' rowset or to update or delete data in the result set.
' ========================================================================================
' SQLRETURN SQL_API SQLSetPos(
'           SQLHSTMT           hstmt,
'           SQLUSMALLINT       irow,
'           SQLUSMALLINT       fOption,
'           SQLUSMALLINT       fLock);
' ========================================================================================
DECLARE FUNCTION SQLSetPos LIB "ODBC32.DLL" ALIAS "SQLSetPos" ( _
        BYVAL hstmt   AS DWORD, _
        BYVAL irow    AS WORD, _
        BYVAL fOption AS WORD, _
        BYVAL fLock   AS WORD _
        ) AS INTEGER

' ========================================================================================
' Macros for SQLSetPos */
' ========================================================================================
'MACRO SQL_POSITION_TO(hstmt,irow) = SQLSetPos(hstmt,irow,%SQL_POSITION,%SQL_LOCK_NO_CHANGE)
'MACRO SQL_LOCK_RECORD(hstmt,irow,fLock) = SQLSetPos(hstmt,irow,%SQL_POSITION,fLock)
'MACRO SQL_REFRESH_RECORD(hstmt,irow,fLock) = SQLSetPos(hstmt,irow,%SQL_REFRESH,fLock)
'MACRO SQL_UPDATE_RECORD(hstmt,irow) = SQLSetPos(hstmt,irow,%SQL_UPDATE,%SQL_LOCK_NO_CHANGE)
'MACRO SQL_DELETE_RECORD(hstmt,irow) = SQLSetPos(hstmt,irow,%SQL_DELETE,%SQL_LOCK_NO_CHANGE)
'MACRO SQL_ADD_RECORD(hstmt,irow) = SQLSetPos(hstmt,irow,%SQL_ADD,%SQL_LOCK_NO_CHANGE)
' ========================================================================================

' ========================================================================================
' Returns a list of tables and the privileges associated with each table. The driver
' returns the information as a result set on the specified statement.
' ========================================================================================
' SQLRETURN SQL_API SQLTablePrivileges(
'           SQLHSTMT           hstmt,
'           SQLCHAR           *szCatalogName,
'           SQLSMALLINT        cbCatalogName,
'           SQLCHAR           *szSchemaName,
'           SQLSMALLINT        cbSchemaName,
'           SQLCHAR           *szTableName,
'           SQLSMALLINT        cbTableName);
' ========================================================================================
DECLARE FUNCTION SQLTablePrivileges LIB "ODBC32.DLL" ALIAS "SQLTablePrivileges" ( _
        BYVAL hstmt         AS DWORD, _
        BYREF szCatalogName AS ASCIIZ, _
        BYVAL cbCatalogName AS INTEGER, _
        BYREF szSchemaName  AS ASCIIZ, _
        BYVAL cbSchemaName  AS INTEGER, _
        BYREF szTableName   AS ASCIIZ, _
        BYVAL cbTableName   AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' Lists driver descriptions and driver attribute keywords. This function is implemented
' solely by the Driver Manager.
' ========================================================================================
' SQLRETURN SQL_API SQLDrivers(
'           SQLHENV            henv,
'           SQLUSMALLINT       fDirection,
'           SQLCHAR           *szDriverDesc,
'           SQLSMALLINT        cbDriverDescMax,
'           SQLSMALLINT       *pcbDriverDesc,
'           SQLCHAR           *szDriverAttributes,
'           SQLSMALLINT        cbDrvrAttrMax,
'           SQLSMALLINT       *pcbDrvrAttr);
' ========================================================================================
DECLARE FUNCTION SQLDrivers LIB "ODBC32.DLL" ALIAS "SQLDrivers" ( _
        BYVAL henv               AS DWORD, _
        BYVAL fDirection         AS WORD, _
        BYREF szDriverDesc       AS ASCIIZ, _
        BYVAL cbDriverDescMax    AS INTEGER, _
        BYREF pcbDriverDesc      AS INTEGER, _
        BYREF szDriverAttributes AS ASCIIZ, _
        BYVAL cbDrvrAttrMax      AS INTEGER, _
        BYREF pcbDrvrAttr        AS INTEGER _
        ) AS INTEGER

' ========================================================================================
' Binds a buffer to a parameter marker in an SQL statement. SQLBindParameter supports
' binding to a Unicode C data type, even if the underlying driver does not support Unicode
' data.
' Note  This function replaces the ODBC 1.0 function SQLSetParam.
' ========================================================================================
' SQLRETURN SQL_API SQLBindParameter(
'           SQLHSTMT           hstmt,
'           SQLUSMALLINT       ipar,
'           SQLSMALLINT        fParamType,
'           SQLSMALLINT        fCType,
'           SQLSMALLINT        fSqlType,
'           SQLUINTEGER        cbColDef,
'           SQLSMALLINT        ibScale,
'           SQLPOINTER         rgbValue,
'           SQLINTEGER         cbValueMax,
'           SQLINTEGER        *pcbValue);
' ========================================================================================
DECLARE FUNCTION SQLBindParameter LIB "ODBC32.DLL" ALIAS "SQLBindParameter" ( _
        BYVAL hstmt      AS DWORD, _
        BYVAL ipar       AS WORD, _
        BYVAL fParamType AS INTEGER, _
        BYVAL fCType     AS INTEGER, _
        BYVAL fSqlType   AS INTEGER, _
        BYVAL cbColDef   AS DWORD, _
        BYVAL ibScale    AS INTEGER, _
        BYREF rgbValue   AS ANY, _
        BYVAL cbValueMax AS LONG, _
        BYREF pcbValue   AS LONG _
        ) AS INTEGER

' ========================================================================================

'---------------------------------------------------------*/
' SQLAllocHandleStd is implemented to make SQLAllocHandle */
' compatible with X/Open standard.  an application should */
' not call SQLAllocHandleStd directly                     */
'---------------------------------------------------------*/

'#ifdef ODBC_STD
'#define SQLAllocHandle  SQLAllocHandleStd
'#define SQLAllocEnv(phenv)  SQLAllocHandleStd(SQL_HANDLE_ENV, SQL_NULL_HANDLE, phenv)

' Use SQLAllocHandle instead of SQLAllocHandleStd
'MACRO SQLAllocEnv(phenv) = SQLAllocHandle(%SQL_HANDLE_ENV, %SQL_NULL_HANDLE, phenv)

'/* Internal type subcodes */
'#define SQL_YEAR                  SQL_CODE_YEAR
'#define SQL_MONTH                  SQL_CODE_MONTH
'#define SQL_DAY                     SQL_CODE_DAY
'#define SQL_HOUR                  SQL_CODE_HOUR
'#define SQL_MINUTE                  SQL_CODE_MINUTE
'#define SQL_SECOND                  SQL_CODE_SECOND
'#define SQL_YEAR_TO_MONTH            SQL_CODE_YEAR_TO_MONTH
'#define SQL_DAY_TO_HOUR               SQL_CODE_DAY_TO_HOUR
'#define SQL_DAY_TO_MINUTE            SQL_CODE_DAY_TO_MINUTE
'#define SQL_DAY_TO_SECOND            SQL_CODE_DAY_TO_SECOND
'#define SQL_HOUR_TO_MINUTE            SQL_CODE_HOUR_TO_MINUTE
'#define SQL_HOUR_TO_SECOND            SQL_CODE_HOUR_TO_SECOND
'#define SQL_MINUTE_TO_SECOND         SQL_CODE_MINUTE_TO_SECOND
'#endif /* ODBC_STD */

' Internal type subcodes */
%SQL_YEAR             = %SQL_CODE_YEAR
%SQL_MONTH            = %SQL_CODE_MONTH
%SQL_DAY              = %SQL_CODE_DAY
%SQL_HOUR             = %SQL_CODE_HOUR
%SQL_MINUTE           = %SQL_CODE_MINUTE
%SQL_SECOND           = %SQL_CODE_SECOND
%SQL_YEAR_TO_MONTH    = %SQL_CODE_YEAR_TO_MONTH
%SQL_DAY_TO_HOUR      = %SQL_CODE_DAY_TO_HOUR
%SQL_DAY_TO_MINUTE    = %SQL_CODE_DAY_TO_MINUTE
%SQL_DAY_TO_SECOND    = %SQL_CODE_DAY_TO_SECOND
%SQL_HOUR_TO_MINUTE   = %SQL_CODE_HOUR_TO_MINUTE
%SQL_HOUR_TO_SECOND   = %SQL_CODE_HOUR_TO_SECOND
%SQL_MINUTE_TO_SECOND = %SQL_CODE_MINUTE_TO_SECOND

' ========================================================================================
' SQLRETURN SQL_API SQLAllocHandleStd(
'           SQLSMALLINT     fHandleType,
'           SQLHANDLE       hInput,
'           SQLHANDLE      *phOutput);
' ========================================================================================
'DECLARE FUNCTION SQLAllocHandleStd LIB "ODBC32.DLL" ALIAS "SQLAllocHandleStd" ( _
'        BYVAL fHandleType AS INTEGER, _
'        BYVAL hInput      AS DWORD, _
'        BYREF phOutPut    AS DWORD _
'        ) AS INTEGER
' ========================================================================================

'      Deprecated defines from prior versions of ODBC 
%SQL_DATABASE_NAME      = 16   ' Use SQLGetConnectOption/SQL_CURRENT_QUALIFIER 
%SQL_FD_FETCH_PREV      = %SQL_FD_FETCH_PRIOR
%SQL_FETCH_PREV         = %SQL_FETCH_PRIOR
%SQL_CONCUR_TIMESTAMP   = %SQL_CONCUR_ROWVER
%SQL_SCCO_OPT_TIMESTAMP = %SQL_SCCO_OPT_ROWVER
%SQL_CC_DELETE          = %SQL_CB_DELETE
%SQL_CR_DELETE          = %SQL_CB_DELETE
%SQL_CC_CLOSE           = %SQL_CB_CLOSE
%SQL_CR_CLOSE           = %SQL_CB_CLOSE
%SQL_CC_PRESERVE        = %SQL_CB_PRESERVE
%SQL_CR_PRESERVE        = %SQL_CB_PRESERVE
' SQL_FETCH_RESUME is not supported by 2.0+ drivers
'%SQL_FETCH_RESUME                =7
'
%SQL_SCROLL_FORWARD_ONLY  = 0    As Long '-SQL_CURSOR_FORWARD_ONLY 
%SQL_SCROLL_KEYSET_DRIVEN = (-1) As Long '-SQL_CURSOR_KEYSET_DRIVEN 
%SQL_SCROLL_DYNAMIC       = (-2) As Long '-SQL_CURSOR_DYNAMIC 
%SQL_SCROLL_STATIC        = (-3) as long '-SQL_CURSOR_STATIC 

'      Deprecated functions from prior versions of ODBC 

' ========================================================================================
' Deprecated. In ODBC 3.x, the ODBC 2.0 function SQLSetScrollOptions has been replaced by
' calls to SQLGetInfo and SQLSetStmtAttr.
' SQLRETURN SQL_API SQLSetScrollOptions(    '      Use SQLSetStmtOptions */
'           SQLHSTMT           hstmt,
'           SQLUSMALLINT       fConcurrency,
'           SQLINTEGER         crowKeyset,
'           SQLUSMALLINT       crowRowset);
' ========================================================================================
DECLARE FUNCTION SQLSetScrollOptions LIB "ODBC32.DLL" ALIAS "SQLSetScrollOptions" ( _
        BYVAL hstmt        AS DWORD, _
        BYVAL fConcurrency AS WORD, _
        BYVAL crowKeyset   AS LONG, _
        BYVAL crowRowset   AS WORD _
        ) AS INTEGER

' ========================================================================================

'// Tracing section
'
'%    TRACE_VERSION   1000        // Version of trace API
'
'RETCODE SQL_API TraceOpenLogFile(LPWSTR,LPWSTR,DWORD);// open a trace log file
'RETCODE SQL_API TraceCloseLogFile();            // Request to close a trace log
'VOID    SQL_API TraceReturn(RETCODE,RETCODE);   // Processes trace after FN is called
'DWORD   SQL_API TraceVersion();                 // Returns trace API version

'/* Functions for Visual Studio Analyzer*/
'/* to turn on/off tracing or VS events, call TraceVSControl by setting or clearing the following bits  */
'#define TRACE_ON         0x00000001L
'#define TRACE_VS_EVENT_ON   0x00000002L

'RETCODE   SQL_API   TraceVSControl(DWORD);

'/* Functions for setting the connection pooling failure detection code */
'/* The "TryWait" value is the time (in seconds) that the DM will wait  */
'/* between detecting that a connection is dead (using                  */
'/* SQL_ATTR_CONNECTION_DEAD) and retrying the connection.  During that */
'/* interval, connection requests will get "The server appears to be    */
'/* dead" error returns.                                                */

'BOOL SQL_API    ODBCSetTryWaitValue(DWORD dwValue);   /* In seconds */
'DWORD SQL_API   ODBCGetTryWaitValue();         /* In Milliseconds(!) */

'/* the flags in ODBC_VS_ARGS */
'#define ODBC_VS_FLAG_UNICODE_ARG   0x00000001L   /* the argument is unicode */
'#define   ODBC_VS_FLAG_UNICODE_COR   0x00000002L   /* the correlation is unicode */
'#define ODBC_VS_FLAG_RETCODE      0x00000004L   /* RetCode field is set */
'#define ODBC_VS_FLAG_STOP      0x00000008L   /* Stop firing visual studio analyzer events */

'typedef struct tagODBC_VS_ARGS {
'   const GUID   *pguidEvent;   /* the GUID for event */
'   DWORD   dwFlags;      /* flags for the call */
'   union {
'      WCHAR   *wszArg;
'      CHAR   *szArg;
'   };
'   union {
'      WCHAR   *wszCorrelation;
'      CHAR   *szCorrelation;
'   };
'   RETCODE   RetCode;
'} ODBC_VS_ARGS, *PODBC_VS_ARGS;
'VOID   SQL_API   FireVSDebugEvent(PODBC_VS_ARGS);


'//-----------------------------------------------------------------------------
'// File:      odbcinst.h
'//
'// Copyright:    Copyright (c) Microsoft Corporation
'//
'// Contents:     Prototypes for ODBCCP32.DLL
'//
'// Comments:
'//
'//<owner current="true" primary="true">afield</owner>
'//<owner current="true" primary="false">mugunm</owner>
'//-----------------------------------------------------------------------------

'// Constants -------------------------------------------------------------
'// SQLConfigDataSource request flags
%ODBC_ADD_DSN    = 1               '// Add data source
%ODBC_CONFIG_DSN = 2               '// Configure (edit) data source
%ODBC_REMOVE_DSN = 3               '// Remove data source

%ODBC_ADD_SYS_DSN        = 4       '// add a system DSN
%ODBC_CONFIG_SYS_DSN     = 5       '// Configure a system DSN
%ODBC_REMOVE_SYS_DSN     = 6       '// remove a system DSN
%ODBC_REMOVE_DEFAULT_DSN = 7       '// remove the default DSN

'// install request flags
%ODBC_INSTALL_INQUIRY  = 1
%ODBC_INSTALL_COMPLETE = 2

'// config driver flags
%ODBC_INSTALL_DRIVER    = 1
%ODBC_REMOVE_DRIVER     = 2
%ODBC_CONFIG_DRIVER     = 3
%ODBC_CONFIG_DRIVER_MAX = 100

'// SQLGetConfigMode and SQLSetConfigMode flags
%ODBC_BOTH_DSN   = 0
%ODBC_USER_DSN   = 1
%ODBC_SYSTEM_DSN = 2

'// SQLInstallerError code
%ODBC_ERROR_GENERAL_ERR             = 1
%ODBC_ERROR_INVALID_BUFF_LEN        = 2
%ODBC_ERROR_INVALID_HWND            = 3
%ODBC_ERROR_INVALID_STR             = 4
%ODBC_ERROR_INVALID_REQUEST_TYPE    = 5
%ODBC_ERROR_COMPONENT_NOT_FOUND     = 6
%ODBC_ERROR_INVALID_NAME            = 7
%ODBC_ERROR_INVALID_KEYWORD_VALUE   = 8
%ODBC_ERROR_INVALID_DSN             = 9
%ODBC_ERROR_INVALID_INF             = 10
%ODBC_ERROR_REQUEST_FAILED          = 11
%ODBC_ERROR_INVALID_PATH            = 12
%ODBC_ERROR_LOAD_LIB_FAILED         = 13
%ODBC_ERROR_INVALID_PARAM_SEQUENCE  = 14
%ODBC_ERROR_INVALID_LOG_FILE        = 15
%ODBC_ERROR_USER_CANCELED           = 16
%ODBC_ERROR_USAGE_UPDATE_FAILED     = 17
%ODBC_ERROR_CREATE_DSN_FAILED       = 18
%ODBC_ERROR_WRITING_SYSINFO_FAILED  = 19
%ODBC_ERROR_REMOVE_DSN_FAILED       = 20
%ODBC_ERROR_OUT_OF_MEM              = 21
%ODBC_ERROR_OUTPUT_STRING_TRUNCATED = 22


'// Prototypes --------------------------------------------------------------
'#define INSTAPI __stdcall

' ========================================================================================
'// High level APIs
' ========================================================================================
' Removed in ODBC 3.0+
' ========================================================================================
' BOOL INSTAPI SQLInstallODBC (
'              HWND       hwndParent,
'              LPCSTR     lpszInfFile,
'              LPCSTR     lpszSrcPath,
'              LPCSTR     lpszDrivers);
' ========================================================================================
' DECLARE FUNCTION SQLInstallODBC LIB "ODBCCP32.DLL" ALIAS "SQLInstallODBC" ( _
'         BYVAL hwndParent  AS DWORD, _
'         BYREF lpszInfFile AS ASCIIZ, _
'         BYREF lpszSrcPath AS ASCIIZ, _
'         BYREF lpszDrivers AS ASCIIZ _
'         ) AS INTEGER

' ========================================================================================
' Displays a dialog box with which users can set up, add, and delete data sources in the
' system information.
' ========================================================================================
' BOOL INSTAPI SQLManageDataSources (HWND hwndParent);
' ========================================================================================
DECLARE FUNCTION SQLManageDataSources LIB "ODBCCP32.DLL" ALIAS "SQLManageDataSources" ( _
        BYVAL hwndParent AS DWORD _
        ) AS INTEGER

' ========================================================================================
' Displays a dialog box with which the user can add a data source.
' ========================================================================================
' BOOL INSTAPI SQLCreateDataSource (
'              HWND       hwndParent,
'              LPCSTR     lpszDSN);
' ========================================================================================
DECLARE FUNCTION SQLCreateDataSource LIB "ODBCCP32.DLL" ALIAS "SQLCreateDataSource" ( _
        BYVAL hwndParent AS DWORD, _
        BYREF lpszDSN    AS ASCIIZ _
        ) AS INTEGER

' ========================================================================================
' Displays a dialog box from which a user can select a translator.
' ========================================================================================
' BOOL INSTAPI SQLGetTranslator (
'              HWND       hwnd,
'              LPSTR      lpszName,
'              WORD       cbNameMax,
'              WORD      *pcbNameOut,
'              LPSTR      lpszPath,
'              WORD       cbPathMax,
'              WORD      *pcbPathOut,
'              DWORD     *pvOption);
' ========================================================================================
DECLARE FUNCTION SQLGetTranslator LIB "ODBCCP32.DLL" ALIAS "SQLGetTranslator" ( _
        BYVAL hwnd       AS DWORD, _
        BYREF lpszName   AS ASCIIZ, _
        BYVAL cbNameMax  AS WORD, _
        BYREF pcbNameOut AS WORD, _
        BYREF lpszPath   AS ASCIIZ, _
        BYVAL cbPathMax  AS WORD, _
        BYREF pcbPathOut AS WORD, _
        BYREF pvOption   AS DWORD _
        ) AS INTEGER

' ========================================================================================
'// Low level APIs
'// NOTE: The high-level APIs should always be used. These APIs
'//       have been left for compatibility.
' ========================================================================================
' BOOL INSTAPI SQLInstallDriver (
'              LPCSTR     lpszInfFile,
'              LPCSTR     lpszDriver,
'              LPSTR      lpszPath,
'              WORD       cbPathMax,
'              WORD      *pcbPathOut);
' ========================================================================================
' DECLARE FUNCTION SQLInstallDriver LIB "ODBCCP32.DLL" ALIAS "SQLInstallDriver" ( _
'         BYREF lpszInFile AS ASCIIZ, _
'         BYREF lpszDriver AS ASCIIZ, _
'         BYREF lpszPath   AS ASCIIZ, _
'         BYVAL cbPathMax  AS WORD, _
'         BYREF pcbPathOut AS WORD _
'         ) AS INTEGER

' ========================================================================================
' Adds information about the driver to the Odbcinst.ini entry in the system information
' and increments the driver's UsageCount by 1. However, if a version of the driver already
' exists but the UsageCount value for the driver does not exist, the new UsageCount value
' is set to 2.
' This function does not actually copy any files. It is the responsibility of the calling
' program to copy the driver's files to the target directory properly.
' ========================================================================================
' BOOL SQLInstallDriverEx(
'      LPCSTR      lpszDriver,
'      LPCSTR      lpszPathIn,
'      LPSTR       lpszPathOut,
'      WORD        cbPathOutMax,
'      WORD       *pcbPathOut,
'      WORD        fRequest,
'      LPDWORD     lpdwUsageCount);
' ========================================================================================
DECLARE FUNCTION SQLInstallDriverEx LIB "ODBCCP32.DLL" ALIAS "SQLInstallDriverEx" ( _
        BYREF lpszDriver     AS ASCIIZ, _
        BYREF lpszPathIn     AS ASCIIZ, _
        BYREF lpszPathOut    AS ASCIIZ, _
        BYVAL cbPathOutMax   AS WORD, _
        BYREF pcbPathOut     AS WORD, _
        BYVAL fRequest       AS WORD, _
        BYREF lpdwUsageCount AS DWORD _
        ) AS INTEGER

' ========================================================================================
' Returns the path of the target directory for the installation of the ODBC
' core components. The calling program must actually copy the Driver Manager's
' files to the target directory.
' ========================================================================================
' BOOL INSTAPI SQLInstallDriverManager (
'              LPSTR      lpszPath,
'              WORD       cbPathMax,
'              WORD      *pcbPathOut);
' ========================================================================================
DECLARE FUNCTION SQLInstallDriverManager LIB "ODBCCP32.DLL" ALIAS "SQLInstallDriverManager" ( _
        BYREF lpszPath   AS ASCIIZ, _
        BYVAL cbPathMax  AS WORD, _
        BYREF pcbPathOut AS WORD _
        ) AS INTEGER

' ========================================================================================
' Reads the [ODBC Drivers] section of the system information and returns a list of
' descriptions of the installed drivers.
' ========================================================================================
' BOOL INSTAPI SQLGetInstalledDrivers (
'              LPSTR      lpszBuf,
'              WORD       cbBufMax,
'              WORD      *pcbBufOut);
' ========================================================================================
DECLARE FUNCTION SQLGetInstalledDrivers LIB "ODBCCP32.DLL" ALIAS "SQLGetInstalledDrivers" ( _
        BYREF lpszBuf   AS ASCIIZ, _
        BYVAL cbBufMax  AS WORD, _
        BYREF pcbBufOut AS WORD _
        ) AS INTEGER

' ========================================================================================
' BOOL INSTAPI SQLGetAvailableDrivers (
'              LPCSTR     lpszInfFile,
'              LPSTR      lpszBuf,
'              WORD       cbBufMax,
'              WORD      *pcbBufOut);
' ========================================================================================
' DECLARE FUNCTION SQLGetAvailableDrivers LIB "ODBCCP32.DLL" ALIAS "SQLGetAvailableDrivers" ( _
'         BYREF lpszInfile AS ASCIIZ, _
'         BYREF lpszBuf    AS ASCIIZ, _
'         BYVAL cbBufMax   AS WORD, _
'         BYREF pcbBufOut  AS WORD _
'         ) AS INTEGER

' ========================================================================================
' Adds, modifies, or deletes data sources.
' Example:
'   DIM r as INTEGER
'   r = SQLConfigDataSource(0, %ODBC_ADD_DSN, "Microsoft Access Driver (*.mdb)", _
'       "CREATE_DB=new.mdb")
' ========================================================================================
' BOOL INSTAPI SQLConfigDataSource (
'              HWND       hwndParent,
'              WORD       fRequest,
'              LPCSTR     lpszDriver,
'              LPCSTR     lpszAttributes);
' ========================================================================================
DECLARE FUNCTION SQLConfigDataSource LIB "ODBCCP32.DLL" ALIAS "SQLConfigDataSource" ( _
        BYVAL hwndParent      AS DWORD, _
        BYVAL fRequest        AS WORD, _
        BYREF lpszDriver      AS ASCIIZ, _
        BYREF lpszAttributes  AS ASCIIZ _
        ) AS INTEGER

' ========================================================================================
' BOOL INSTAPI SQLRemoveDefaultDataSource(void);
' In ODBC 3.0, the SQLRemoveDefaultDataSource function has been replaced by
' a call to SQLConfigDataSource with an fRequest argument of
' ODBC_REMOVE_DEFAULT_DSN.
' ========================================================================================
' DECLARE FUNCTION SQLRemoveDefaultDataSource LIB "ODBCCP32.DLL" ALIAS "SQLRemoveDefaultDataSource" () AS INTEGER

' ========================================================================================
' Adds a data source to the system information.
' ========================================================================================
' BOOL INSTAPI SQLWriteDSNToIni (
'              LPCSTR     lpszDSN,
'              LPCSTR     lpszDriver);
' ========================================================================================
DECLARE FUNCTION SQLWriteDSNToIni LIB "ODBCCP32.DLL" ALIAS "SQLWriteDSNToIni" ( _
        BYREF lpszDSN    AS ASCIIZ, _
        BYREF lpszDriver AS ASCIIZ _
        ) AS INTEGER

' ========================================================================================
' Removes a data source from the system information.
' ========================================================================================
' BOOL INSTAPI SQLRemoveDSNFromIni (LPCSTR lpszDSN);
' ========================================================================================
DECLARE FUNCTION SQLRemoveDSNFromIni LIB "ODBCCP32.DLL" ALIAS "SQLRemoveDSNFromIni" ( _
        BYREF lpszDSN AS ASCIIZ) AS INTEGER

' ========================================================================================
' Checks the length and validity of the data source name before the name is added to the
' system information.
' ========================================================================================
' BOOL INSTAPI SQLValidDSN (LPCSTR lpszDSN);
' ========================================================================================
DECLARE FUNCTION SQLValidDSN LIB "ODBCCP32.DLL" ALIAS "SQLValidDSN" ( _
        BYREF lpszDSN AS ASCIIZ _
        ) AS INTEGER

' ========================================================================================
' Writes a value name and data to the Odbc.ini subkey of the system information.
' ========================================================================================
' BOOL INSTAPI SQLWritePrivateProfileString(
'              LPCSTR lpszSection,
'              LPCSTR lpszEntry,
'              LPCSTR lpszString,
'              LPCSTR lpszFilename);
' ========================================================================================
DECLARE FUNCTION SQLWritePrivateProfileString LIB "ODBCCP32.DLL" ALIAS "SQLWritePrivateProfileString" ( _
        BYREF lpszSection  AS ASCIIZ, _
        BYREF lpszEntry    AS ASCIIZ, _
        BYREF lpszString   AS ASCIIZ, _
        BYREF lpszFileName AS ASCIIZ _
        ) AS INTEGER

' ========================================================================================
' Gets a list of names of values or data corresponding to a value of the system information.
' ========================================================================================
' int  INSTAPI SQLGetPrivateProfileString(
'              LPCSTR lpszSection,
'              LPCSTR lpszEntry,
'              LPCSTR lpszDefault,
'              LPSTR  lpszRetBuffer,
'              int    cbRetBuffer,
'              LPCSTR lpszFilename);
' ========================================================================================
DECLARE FUNCTION SQLGetPrivateProfileString LIB "ODBCCP32.DLL" ALIAS "SQLGetPrivateProfileString" ( _
        BYREF lpszSection   AS ASCIIZ, _
        BYREF lpszEntry     AS ASCIIZ, _
        BYREF lpszDefault   AS ASCIIZ, _
        BYREF lpszRetBuffer AS ASCIIZ, _
        BYVAL cbRetBuffer   AS INTEGER, _
        BYREF lpszFileName  AS ASCIIZ _
        ) AS INTEGER

' ========================================================================================
' Changes or removes information about the ODBC core components from the
' Odbcinst.ini entry in the system information.
' ========================================================================================
' BOOL INSTAPI SQLRemoveDriverManager(LPDWORD lpdwUsageCount);
' ========================================================================================
DECLARE FUNCTION SQLRemoveDriverManager LIB "ODBCCP32.DLL" ALIAS "SQLRemoveDriverManager" ( _
        lpdwUsageCount AS DWORD) AS INTEGER

' ========================================================================================
' BOOL INSTAPI SQLInstallTranslator(
'              LPCSTR    lpszInfFile,
'              LPCSTR    lpszTranslator,
'              LPCSTR    lpszPathIn,
'              LPSTR     lpszPathOut,
'              WORD      cbPathOutMax,
'              WORD     *pcbPathOut,
'              WORD      fRequest,
'              LPDWORD   lpdwUsageCount);
' ========================================================================================
' DECLARE FUNCTION SQLInstallTranslator LIB "ODBCCP32.DLL" ALIAS "SQLInstallTranslator" ( _
'         BYREF lpszInfFile    AS ASCIIZ, _
'         BYREF lpszTranslator AS ASCIIZ, _
'         BYREF lpszPathIn     S ASCIIZ, _
'         BYREF lpszPathOut    AS ASCIIZ, _
'         BYVAL cbPathOutMax   AS WORD, _
'         BYREF pcbPathOut     AS WORD, _
'         BYVAL fRqquest       AS WORD, _
'         BYREF lpdwUsageCount AS DWORD) AS INTEGER

' ========================================================================================
' Adds information about a translator to the Odbcinst.ini section of the system information.
' ========================================================================================
' BOOL SQLInstallTranslatorEx(
'      LPCSTR     lpszTranslator,
'      LPCSTR     lpszPathIn,
'      LPSTR      lpszPathOut,
'      WORD       cbPathOutMax,
'      WORD      *pcbPathOut,
'      WORD       fRequest,
'      LPDWORD    lpdwUsageCount);
' ========================================================================================
DECLARE FUNCTION SQLInstallTranslatorEx LIB "ODBCCP32.DLL" ALIAS "SQLInstallTranslatorEx" ( _
        BYREF lpszTranslator AS ASCIIZ, _
        BYREF lpszPathIn     AS ASCIIZ, _
        BYREF lpszPathOut    AS ASCIIZ, _
        BYVAL cbPathOutMax   AS WORD, _
        BYREF pcbPathOut     AS WORD, _
        BYVAL fRqquest       AS WORD, _
        BYREF lpdwUsageCount AS DWORD _
        ) AS INTEGER

' ========================================================================================
' Removes information about a translator from the Odbcinst.ini section of
' the system information and decrements the translator's component usage
' count by 1.
' ========================================================================================
' BOOL INSTAPI SQLRemoveTranslator(
'              LPCSTR  lpszTranslator,
'              LPDWORD lpdwUsageCount);
' ========================================================================================

DECLARE FUNCTION SQLRemoveTranslator LIB "ODBCCP32.DLL" ALIAS "SQLRemoveTranslator" ( _
        BYREF lpszTranslator AS ASCIIZ, _
        BYREF lpdwUsageCount AS DWORD _
        ) AS INTEGER

' ========================================================================================
' Changes or removes information about the driver from the Odbcinst.ini entry in the
' system information.
' ========================================================================================
' BOOL INSTAPI SQLRemoveDriver(
'              LPCSTR  lpszDriver,
'              BOOL    fRemoveDSN,
'              LPDWORD lpdwUsageCount);
' ========================================================================================
DECLARE FUNCTION SQLRemoveDriver LIB "ODBCCP32.DLL" ALIAS "SQLRemoveDriver" ( _
        BYREF lpszDriver     AS ASCIIZ, _
        BYVAL fRemoveDSN     AS INTEGER, _
        BYREF lpdwUsageCount AS DWORD _
        ) AS INTEGER

' ========================================================================================
' Returns error or status information for the ODBC installer functions.
' ========================================================================================
' SQLRETURN INSTAPI SQLInstallerError(
'                   WORD   iError,
'                   DWORD *pfErrorCode,
'                   LPSTR  lpszErrorMsg,
'                   WORD   cbErrorMsgMax,
'                   WORD  *pcbErrorMsg);
' ========================================================================================
DECLARE FUNCTION SQLInstallerError LIB "ODBCCP32.DLL" ALIAS "SQLInstallerError" ( _
        BYVAL iError        AS WORD, _
        BYREF pfErrorCode   AS DWORD, _
        BYREF lpszErrorMsg  AS ASCIIZ, _
        BYVAL cbErrorMsgMax AS WORD, _
        BYREF pcbErrorMsg   AS WORD _
        ) AS INTEGER

' ========================================================================================
' Provides a mechanism for a driver or translator setup library to report
' errors for the ConfigDriver, ConfigDSN, and ConfigTranslator functions to
' the installer error queue. Applications do not use this API; they use
' SQLInstallerError to retrieve the error.
' ========================================================================================
' SQLRETURN INSTAPI SQLPostInstallerError(
'                   DWORD  dwErrorCode,
'                   LPCSTR lpszErrMsg);
' ========================================================================================
DECLARE FUNCTION SQLPostInstallerError LIB "ODBCCP32.DLL" ALIAS "SQLPostInstallerError" ( _
        BYVAL dwErrorCode AS DWORD, _
        BYREF lpszErrMsg  AS ASCIIZ _
        ) AS INTEGER

' ========================================================================================
' Writes information to a File DSN.
' ========================================================================================
' BOOL INSTAPI SQLWriteFileDSN (
'              LPCSTR  lpszFileName,
'              LPCSTR  lpszAppName,
'              LPCSTR  lpszKeyName,
'              LPCSTR  lpszString);
' ========================================================================================
DECLARE FUNCTION SQLWriteFileDSN LIB "ODBCCP32.DLL" ALIAS "SQLWriteFileDSN" ( _
        BYREF lpszFileName AS ASCIIZ, _
        BYREF lpszAppName  AS ASCIIZ, _
        BYREF lpszKeyName  AS ASCIIZ, _
        BYREF lpszString   AS ASCIIZ _
        ) AS INTEGER

' ========================================================================================
' Reads information from a File DSN.
' ========================================================================================
' BOOL INSTAPI  SQLReadFileDSN (
'               LPCSTR  lpszFileName,
'               LPCSTR  lpszAppName,
'               LPCSTR  lpszKeyName,
'               LPSTR   lpszString,
'               WORD    cbString,
'               WORD   *pcbString);
' ========================================================================================
DECLARE FUNCTION SQLReadFileDSN LIB "ODBCCP32.DLL" ALIAS "SQLReadFileDSN" ( _
        BYREF lpszFileName AS ASCIIZ, _
        BYREF lpszAppName  AS ASCIIZ, _
        BYREF lpszKeyName  AS ASCIIZ, _
        BYREF lpszString   AS ASCIIZ, _
        BYVAL cbString     AS WORD, _
        BYREF pcbString    AS WORD _
        ) AS INTEGER

' ========================================================================================
' Retrieves the configuration mode that indicates where the Odbc.ini entry listing DSN
' values is in the system information.
' ========================================================================================
' BOOL INSTAPI SQLGetConfigMode (UWORD *pwConfigMode);
' ========================================================================================
DECLARE FUNCTION SQLGetConfigMode LIB "ODBCCP32.DLL" ALIAS "SQLGetConfigMode" ( _
        BYREF pwConfigMode AS WORD _
        ) AS INTEGER

' ========================================================================================
' Sets the configuration mode that indicates where the Odbc.ini entry listing
' DSN values is in the system information.
' ========================================================================================
' BOOL INSTAPI SQLSetConfigMode (UWORD wConfigMode);
' ========================================================================================
DECLARE FUNCTION SQLSetConfigMode LIB "ODBCCP32.DLL" ALIAS "SQLSetConfigMode" ( _
        BYVAL wConfigMode AS WORD _
        ) AS INTEGER

' ========================================================================================
'//   Driver specific Setup APIs called by installer

' ========================================================================================
' Adds, modifies, or deletes data sources from the system information. It may prompt the
' user for connection information. It can be in the driver DLL or a separate setup DLL.
' ========================================================================================
' BOOL INSTAPI ConfigDSN (
'              HWND     hwndParent,
'              WORD     fRequest,
'              LPCSTR   lpszDriver,
'              LPCSTR   lpszAttributes);
' ========================================================================================
'DECLARE FUNCTION SQLConfigDSN LIB "ODBCCP32.DLL" ALIAS "SQLConfigDSN" ( _
'        BYVAL hwndParent     AS DWORD, _
'        BYVAL fRequest       AS WORD, _
'        BYREF lpszDriver     AS ASCIIZ, _
'        BYREF lpszAttributes AS ASCIIZ _
'        ) AS INTEGER

' ========================================================================================
' Returns a default translation option for a translator. It can be in the translator DLL
' or a separate setup DLL.
' ========================================================================================
' BOOL INSTAPI ConfigTranslator (
'              HWND     hwndParent,
'              DWORD    *pvOption);
' ========================================================================================
'DECLARE FUNCTION SQLConfigTranslator LIB "ODBCCP32.DLL" ALIAS "SQLConfigTranslator" ( _
'        BYVAL hwndParent AS DWORD, _
'        BYREF pvOption   AS DWORD _
'        ) AS INTEGER

' ========================================================================================
' Allows a setup program to perform install and uninstall functions without requiring the
' program to call ConfigDSN. This function will perform driver-specific functions such as
' creating driver-specific system information and performing DSN conversions during
' installation, as well as cleaning up system information modifications during uninstall.
' This function is exposed by the driver setup DLL or a separate setup DLL.
' ========================================================================================
' BOOL INSTAPI ConfigDriver (
'              HWND hwndParent,
'              WORD fRequest,
'              LPCSTR lpszDriver,
'              LPCSTR lpszArgs,
'              LPSTR  lpszMsg,
'              WORD   cbMsgMax,
'              WORD   *pcbMsgOut);
' ========================================================================================
DECLARE FUNCTION SQLConfigDriver LIB "ODBCCP32.DLL" ALIAS "SQLConfigDriver" ( _
        BYVAL hwndParent AS DWORD, _
        BYVAL fRequest   AS WORD, _
        BYREF lpszDriver AS ASCIIZ, _
        BYREF lpszArgs   AS ASCIIZ, _
        BYREF lpszMsg    AS ASCIIZ, _
        BYVAL cbMsgMax   AS WORD, _
        BYREF pcbMsgOut  AS WORD _
        ) AS INTEGER
' ========================================================================================


' ########################################################################################
' Types used by the wrapper functions
' ########################################################################################

' ODBC driver version
%ODBC_DRIVER_VERSION  = 3       ' Version 3.x

TYPE ODBC_COL_DESC_TYPE          ' Structure for SQL_DescribeCol
   clName AS ASCIIZ * 255           ' Column name
   clNameLen AS INTEGER             ' Column name length
   clDataType AS INTEGER            ' Data type
   clSize AS DWORD                  ' Column size
   clDecimals AS INTEGER            ' Decimals
   clNullable AS INTEGER            ' Boolean
END TYPE

TYPE ODBC_COLUMNS_TYPE
   szCatalogName AS ASCIIZ * 129     '  1. Catalog name
   szSchemaName AS ASCIIZ * 129      '  2. Schema name
   szTableName AS ASCIIZ * 129       '  3. Table name
   szColumnName AS ASCIIZ * 129      '  4. Column name
   iDataType AS INTEGER              '  5. SQL data type
   szTypeName AS ASCIIZ * 129        '  6. Data-source dependent data type
   lColumnSize AS LONG               '  7. Column size
   lBufferLength AS LONG             '  8. Length in bytes of data transferred
   iDecimalDigits AS INTEGER         '  9. Decimal digits
   iNumPrecRadix AS INTEGER          ' 10. Numeric precision radix
   iNullable AS INTEGER              ' 11. Indicates with certainty if a column can accept nulls
   szRemarks AS ASCIIZ * 255         ' 12. A description of the column
   szColumnDefault AS ASCIIZ * 129   ' 13. Default value of the column
   iSQLDataType AS INTEGER           ' 14. SQL data type as it appears in the SQL_DESC_TYPE record field in the IRD
   iDatetimeSubtypeCode AS INTEGER   ' 15. The subtype code for datetime and interval data types
   lCharOctetLength AS LONG          ' 16. The maximun length in bytes of a character or binary data type
   lOrdinalPosition AS LONG          ' 17. The ordinal position of the column in the table
   szIsNullable AS ASCIIZ * 4        ' 18. Indicates with certainty if a column cannot accept nulls
END TYPE

TYPE ODBC_DATASOURCES_TYPE
   szServerName AS ASCIIZ * %SQL_MAX_DSN_LENGTH + 1  ' Data dource name
   cbServerNameLen AS INTEGER                        ' Longitud real de ServerName
   szDriverDescription AS ASCIIZ * 255               ' Description of the driver associated with the data source
   cbDriverDescriptionLen AS INTEGER                 ' Longitud real de DriverDescription
END TYPE

TYPE ODBC_TYPEINFO_TYPE           ' Structure fir SQlGetTypeInfo
   szTypeName AS ASCIIZ * 129        '  1. Data source-dependent data type name
   iDataType AS INTEGER              '  2. SQL data type
   lColumnSize AS LONG               '  3. The maximum column size that the driver supports for this data type
   szIntervalPrefix AS ASCIIZ * 129  '  4. Character of characters used to prefix a literal
   szIntervalSuffix AS ASCIIZ * 129  '  5. Character of characters used to terminate a literal
   szCreateParams AS ASCIIZ * 129    '  6. A list of keyword, separated by commas
   iNullable AS INTEGER              '  7. Whether the data type accepts a null value
   iCaseSensitive AS INTEGER         '  8. Whether a character data type is case-sensitive
   iSearchable AS INTEGER            '  9. How the data type is used in a WHERE clause
   iUnsignedAttribute AS INTEGER     ' 10. Whether the data type is unsigned
   iFixedPrecScale AS INTEGER        ' 11. Whether the data type has predefined fixed precision and scale
   iAutoUniqueValue AS INTEGER       ' 12. Whether tha data is autoincrementing
   szLocalTypeName AS ASCIIZ * 129   ' 13. Localized version of the data source-dependent name of the data type
   iMinimumScale AS INTEGER          ' 14. The minimum scale of the data type on the data source
   iMaximumScale AS INTEGER          ' 15. The maximum scale of the data type on the data source
   iSqlDataType AS INTEGER           ' 16. The value of the SQL data type as it appears in the SQL_DESC_TYPE of the descriptor
   iSqlDatetimeSub AS INTEGER        ' 17. Datetime/interval subcode
   lNumPrecRadix AS LONG             ' 18. Numeric precision radix
   iIntervalPrecision AS INTEGER     ' 19. Value of the interval leading precision
END TYPE

TYPE ODBC_STATISTICS_TYPE          ' Structure for SQLStatistics
   szTableCatalogName AS ASCIIZ * 129 '  1. Catalog name of the table to which the statistic or index applies
   szTableSchemaName AS ASCIIZ * 129  '  2. Schema name of the table to which the statistic or index applies
   szTableName AS ASCIIZ * 129        '  3. Table name of the table to which the statistic or index appplies
   iNonUnique AS INTEGER              '  4. Indicates whether the index prohibits duplicate values
   szIndexQualifier AS ASCIIZ * 129   '  5. The identifier that is used to qualify the index name doing a DROP INDEX
   szIndexName AS ASCIIZ * 129        '  6. Index name
   iInfoType AS INTEGER               '  7. Type of information being returned
   iOrdinalPosition AS INTEGER        '  8. Column sequence number in index (starting with 1)
   szColumnName AS ASCIIZ * 129       '  9. Column name
   szAscOrDesc AS ASCIIZ * 2          ' 10. "A" for ascending, "D" for descending, NULL if no supported
   lCardinality AS LONG               ' 11. Cardinality of table or index
   lPages AS LONG                     ' 12. Number of pages used to store the index or table
   szFilterCondition AS ASCIIZ * 129  ' 13. Filter condition
END TYPE

TYPE ODBC_TABLES_TYPE
   szTableCatalogName AS ASCIIZ * 129   ' Catalog Name
   szTableSchemaName AS ASCIIZ * 129     ' Schema name
   szTableName AS ASCIIZ * 129          ' Table name
   szTableType AS ASCIIZ * 129          ' Table type name
   szRemarks AS ASCIIZ * 255            ' Description of the table
END TYPE

TYPE ODBC_TABLEPRIVILEGES_TYPE
   szTableCatalogName AS ASCIIZ * 129  ' Catalog name
   szTableSchemaName AS ASCIIZ * 129   ' Schema name
   szTableName AS ASCIIZ * 129         ' Table name
   szGrantor AS ASCIIZ * 129           ' Name of the user who granted the privilege
   szGrantee AS ASCIIZ * 129           ' Name of the user to whom the privilege was granted
   szPrivilege AS ASCIIZ * 129         ' The table privilege
   szIsGrantable AS ASCIIZ * 4         ' Indicates whether the grantee is permitted to grant the privilege to other users
END TYPE

TYPE ODBC_PRIMARYKEYS_TYPE
   szTableCatalogName AS ASCIIZ * 129    ' Primary key table catalog name
   szTableSchemaName AS ASCIIZ * 129     ' Primary key table schema name
   szTableName AS ASCIIZ * 129           ' Primary key table name
   szColumnName AS ASCIIZ * 129          ' Primary key column name
   iKeySequence AS INTEGER               ' Column sequence number in key (starting with 1)
   szPrimaryKeyName AS ASCIIZ * 129      ' Primary key name
END TYPE

TYPE ODBC_PROCEDURES_TYPE
   szProcedureCatalogIdentifier AS ASCIIZ * 129 ' Procedure catalog identifier
   szProcedureSchemaIdentifier AS ASCIIZ * 129  ' Procedure schema identifier
   szProcedureName AS ASCIIZ * 129              ' Procedure identifier
   lNumInputParams AS LONG                      ' Reserved for future use
   lNumOutputParams AS LONG                     ' Reserved for future use
   lNumResultSets AS LONG                       ' Reserved for future use
   szRemarks AS ASCIIZ * 255                    ' A description of the procedure
   iProcedureType AS INTEGER                    ' Defines the procedure type
   ' SQL_PT_UNKNOWN: It cannot be determined whether the procedure returns a value
   ' SQL_PT_PROCEDURE: The returned object is a procedure; that is, it does not have a return value
   ' SQL_PT_FUNCTION: The returned object is a function; that is, has a return value
END TYPE

TYPE ODBC_SPECIALCOLUMNS_TYPE
   iScope AS INTEGER             ' Actual scope of the rowid
   szColumnName AS ASCIIZ * 129  ' Column name
   iDataType AS INTEGER          ' SQL data type
   szTypeName AS ASCIIZ * 129    ' Data source-dependent fata type
   lColumnSize AS LONG           ' The size of the column on the data source
   lBufferLength AS LONG         ' The length in bytes of data transferred on an SQLGetData of DQLFetch operation if SQL_C_DEFAULT is specified
   iDecimalDigits AS INTEGER     ' The decimal digits of the column on the data source
   iPseudoColumn AS INTEGER      ' Indicates whether the column is a pseudo-column
END TYPE

TYPE ODBC_DRIVERS_TYPE
   szDriverDescription AS ASCIIZ * 255  ' Driver description
   cbDriverDescriptionLen AS INTEGER    ' Driver description total length
   szDriverAttributes AS ASCIIZ * 255   ' Driver attributes
   cbDriverAttributesLen AS INTEGER     ' Driver attributes total length
END TYPE

TYPE ODBC_ATTR_IMP_DESC        ' Structure for FF_ODBC_GetImpRowDesc and FF_ODBC_GetParamRowDesc
   szName AS ASCIIZ * 256         ' Name
   nStringLength AS INTEGER       ' Number of bytes of data available
   nType AS INTEGER               ' Value of the %SQL_DESC_TYPE field for the descriptor record
   nSubType AS INTEGER            ' Value of the %SQL_DESC_DATETIME_INTERVAL_CODE field
   nLength AS LONG                ' Value of the %SQL_DESC_OCTET_LENGTH field for the descriptor record
   nPrecision AS INTEGER          ' Value of the %SQL_DESC_PRECISION field for the descriptor record
   nScale AS INTEGER              ' Value of the %SQL_DESC_SCALE field for the descriptor record
   nNullable AS INTEGER           ' Value of the %SQL_DESC_NULLABLE field for the descriptor record
END TYPE

TYPE ODBC_COLUMN_PRIVILEGES_TYPE
   szTableCatalogName AS ASCIIZ * 129  ' Catalog identifier
   szTableSchemaName AS ASCIIZ * 129   ' Schema identifier
   szTableName AS ASCIIZ * 129         ' Table identifier
   szColumnName AS ASCIIZ * 129        ' Column name
   szGrantor AS ASCIIZ * 129           ' Name of the user who granted the privilege
   szGrantee AS ASCIIZ * 129           ' Name of the user to whom the privilege was granted
   szPrivilege AS ASCIIZ * 129         ' Identifies the column privilege
   szIsGrantable AS ASCIIZ * 5         ' Inficates whether the grantee is permitted to grant the privileges to other users
END TYPE

TYPE ODBC_FOREIGN_KEYS_TYPE
   szPKCatalogName AS ASCIIZ * 129       ' Primary key table catalog name
   szPKSchemaName AS ASCIIZ * 129        ' Primary key table schema name
   szPKTableName AS ASCIIZ * 129         ' Primary key table name
   szPKColumnName AS ASCIIZ * 129        ' Priamry Key column name
   szFKCatalogName AS ASCIIZ * 129       ' Foreign key table catalog name
   szFKSchemaName AS ASCIIZ * 129        ' Foreign key table schema name
   szFKTableName AS ASCIIZ * 129         ' Foreign ke table name
   szFKColumnName AS ASCIIZ * 129        ' Foreign key column name
   iKeySequence AS INTEGER               ' Column sequence number in key (starting with 1)
   iUpdateRule AS INTEGER                ' Action to be applied to the foreign key when the SQL operation is UPDATE
   iDeleteRule AS INTEGER                ' Action to be applied to the foreign key when the SQL operation is DELETE
   szFKName AS ASCIIZ * 129              ' Foreign key name
   szPKName AS ASCIIZ * 129              ' Primary key name
   iDeferrability AS INTEGER             ' Deferrability
END TYPE

TYPE ODBC_PROCEDURE_COLUMNS_TYPE
   szProcedureCatalogName   AS ASCIIZ * 129   ' Procedure catalog name
   szProcedureSchemaName    AS ASCIIZ * 129   ' Procedure schema name
   szProcedureName          AS ASCIIZ * 129   ' Procedure name
   szColumnName             AS ASCIIZ * 129   ' Column name
   iColumnType              AS INTEGER        ' Column type
   iDataType                AS INTEGER        ' Data type
   szTypeName               AS ASCIIZ * 129   ' Type name
   lColumnSize              AS LONG           ' Column size
   lBufferLength            AS LONG           ' Buffer length
   iDecimalDigits           AS INTEGER        ' Decimal digits
   iNumPrecRadix            AS INTEGER        ' For numeric data types, either 10 or 2
   iNullable                AS INTEGER        ' Accepts nulls
   szRemarks                AS ASCIIZ * 129   ' A description of the column
   szColumnDefault          AS ASCIIZ * 129   ' Default value
   iSqlDataType             AS INTEGER        ' SQL data type
   iSqlDateTimeSubtype      AS INTEGER        ' DateTime subtype
   lCharOctetLength         AS LONG           ' Character octet length
   lOrdinalPosition         AS LONG           ' Ordinal position
   szIsNullable             AS ASCIIZ * 4     ' Contains nulls
END TYPE

' ========================================================================================

DECLARE FUNCTION  OdbcError                     LIB "ODBC352.DLL" ALIAS "OdbcError" () AS INTEGER
DECLARE FUNCTION  OdbcResult                    LIB "ODBC352.DLL" ALIAS "OdbcResult" () AS INTEGER
DECLARE SUB       OdbcSetResult                 LIB "ODBC352.DLL" ALIAS "OdbcSetResult" (BYVAL iResultCode AS INTEGER)
DECLARE SUB       OdbcClearResult               LIB "ODBC352.DLL" ALIAS "OdbcClearResult"
DECLARE FUNCTION  OdbcGetErrorInfo              LIB "ODBC352.DLL" ALIAS "OdbcGetErrorInfo" (BYVAL HandleType AS INTEGER, BYVAL hndl AS DWORD, OPTIONAL BYVAL iErrorCode AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcGetConnectionErrorInfo    LIB "ODBC352.DLL" ALIAS "OdbcGetConnectionErrorInfo" (BYVAL hDbc AS DWORD, OPTIONAL BYVAL iErrorCode AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcGetDbcErrorInfo           LIB "ODBC352.DLL" ALIAS "OdbcGetDbcErrorInfo" (BYVAL hDbc AS DWORD, OPTIONAL BYVAL iErrorCode AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcGetEnvironmentErrorInfo   LIB "ODBC352.DLL" ALIAS "OdbcGetEnvironmentErrorInfo" (BYVAL hEnv AS DWORD, OPTIONAL BYVAL iErrorCode AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcGetEnvErrorInfo           LIB "ODBC352.DLL" ALIAS "OdbcGetEnvErrorInfo" (BYVAL hEnv AS DWORD, OPTIONAL BYVAL iErrorCode AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcGetStatementErrorInfo     LIB "ODBC352.DLL" ALIAS "OdbcGetStatementErrorInfo" (BYVAL hStmt AS DWORD, OPTIONAL BYVAL iErrorCode AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcGetStmtErrorInfo          LIB "ODBC352.DLL" ALIAS "OdbcGetStmtErrorInfo" (BYVAL hStmt AS DWORD, OPTIONAL BYVAL iErrorCode AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcGetDescriptorErrorInfo    LIB "ODBC352.DLL" ALIAS "OdbcGetDescriptorErrorInfo" (BYVAL hDesc AS DWORD, OPTIONAL BYVAL iErrorCode AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcGetDescErrorInfo          LIB "ODBC352.DLL" ALIAS "OdbcGetDescErrorInfo" (BYVAL hDesc AS DWORD, OPTIONAL BYVAL iErrorCode AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcAllocHandle               LIB "ODBC352.DLL" ALIAS "OdbcAllocHandle" (BYVAL HandleType AS INTEGER, BYVAL InputHandle AS DWORD) AS DWORD
DECLARE SUB       OdbcFreeHandle                LIB "ODBC352.DLL" ALIAS "OdbcFreeHandle" (BYVAL HandleType AS INTEGER, BYVAL hndl AS DWORD)
DECLARE FUNCTION  OdbcAllocEnv                  LIB "ODBC352.DLL" ALIAS "OdbcAllocEnv" () AS DWORD
DECLARE SUB       OdbcFreeEnv                   LIB "ODBC352.DLL" ALIAS "OdbcFreeEnv" (BYVAL hEnv AS DWORD)
DECLARE FUNCTION  OdbcAllocConnect              LIB "ODBC352.DLL" ALIAS "OdbcAllocConnect" (BYVAL hEnv AS DWORD) AS DWORD
DECLARE SUB       OdbcFreeConnect               LIB "ODBC352.DLL" ALIAS "OdbcFreeConnect" (BYVAL hDbc AS DWORD)
DECLARE FUNCTION  OdbcAllocDbc                  LIB "ODBC352.DLL" ALIAS "OdbcAllocDbc" (BYVAL hEnv AS DWORD) AS DWORD
DECLARE SUB       OdbcFreeDbc                   LIB "ODBC352.DLL" ALIAS "OdbcFreeDbc" (BYVAL hDbc AS DWORD)
DECLARE FUNCTION  OdbcAllocStmt                 LIB "ODBC352.DLL" ALIAS "OdbcAllocStmt" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE SUB       OdbcFreeStmt                  LIB "ODBC352.DLL" ALIAS "OdbcFreeStmt" (BYVAL hStmt AS DWORD, BYVAL iOption AS INTEGER)
DECLARE FUNCTION  OdbcOpenStmt                  LIB "ODBC352.DLL" ALIAS "OdbcOpenStmt" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE SUB       OdbcCloseStmt                 LIB "ODBC352.DLL" ALIAS "OdbcCloseStmt" (BYVAL hStmt AS DWORD)
DECLARE FUNCTION  OdbcAllocDesc                 LIB "ODBC352.DLL" ALIAS "OdbcAllocDesc" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE SUB       OdbcFreeDesc                  LIB "ODBC352.DLL" ALIAS "OdbcFreeDesc" (BYVAL hDesc AS DWORD)
DECLARE FUNCTION  OdbcNativeSql                 LIB "ODBC352.DLL" ALIAS "OdbcNativeSql" (BYVAL hDbc AS DWORD, BYVAL InText AS STRING) AS STRING
Declare Function  OdbcOpenConnection            Lib "ODBC352.DLL" Alias "OdbcOpenConnection" (ByVal hDbc As Dword, ByVal ConStr As String) As String
DECLARE SUB       OdbcCloseConnection           LIB "ODBC352.DLL" ALIAS "OdbcCloseConnection" (BYVAL hDbc AS DWORD)
DECLARE SUB       OdbcConnect                   LIB "ODBC352.DLL" ALIAS "OdbcConnect" (BYVAL hDbc AS DWORD, BYVAL ServerName AS STRING, BYVAL UserName AS STRING, BYVAL Authentication AS STRING)
DECLARE SUB       OdbcDisconnect                LIB "ODBC352.DLL" ALIAS "OdbcDisconnect" (BYVAL hDbc AS DWORD)
DECLARE FUNCTION  OdbcDriverConnect             LIB "ODBC352.DLL" ALIAS "OdbcDriverConnect" (BYVAL hDbc AS DWORD, BYVAL hWnd AS DWORD, BYVAL Constr AS STRING, OPTIONAL BYVAL fDriverCompletion AS WORD) AS STRING
DECLARE FUNCTION  OdbcBrowseConnect             LIB "ODBC352.DLL" ALIAS "OdbcBrowseConnect" (BYVAL hDbc AS DWORD, BYVAL Constr AS STRING) AS STRING
DECLARE FUNCTION  OdbcConfigDataSource          LIB "ODBC352.DLL" ALIAS "OdbcConfigDataSource" (BYVAL hWndParent AS DWORD, BYVAL fRequest AS WORD, BYVAL strDriver AS STRING, BYVAL strAttributes AS STRING) AS INTEGER
DECLARE FUNCTION  OdbcRecordCount               LIB "ODBC352.DLL" ALIAS "OdbcRecordCount" (BYVAL hDbc AS DWORD, BYVAL SqlStr AS STRING) AS LONG
DECLARE FUNCTION  OdbcRowCount                  LIB "ODBC352.DLL" ALIAS "OdbcRowCount" (BYVAL hStmt AS DWORD) AS LONG
DECLARE SUB       OdbcExecDirect                LIB "ODBC352.DLL" ALIAS "OdbcExecDirect" (BYVAL hStmt AS DWORD, BYVAL SqlStr AS STRING)
DECLARE SUB       OdbcCancel                    LIB "ODBC352.DLL" ALIAS "OdbcCancel" (BYVAL hStmt AS DWORD)
DECLARE FUNCTION  OdbcNumResultCols             LIB "ODBC352.DLL" ALIAS "OdbcNumResultCols" (BYVAL hStmt AS DWORD) AS INTEGER
DECLARE SUB       OdbcMoreResults               LIB "ODBC352.DLL" ALIAS "OdbcMoreResults"     (BYVAL hStmt AS DWORD           )                                                     
DECLARE FUNCTION  OdbcNumParams                 LIB "ODBC352.DLL" ALIAS "OdbcNumParams"       (BYVAL hStmt AS DWORD           )  AS                              INTEGER            
DECLARE FUNCTION  OdbcCreateDataSource          LIB "ODBC352.DLL" ALIAS "OdbcCreateDataSource"(BYVAL hWnd AS DWORD            ,  lpszDSN AS ASCIIZ              )       AS INTEGER 
DECLARE SUB       OdbcCopyDesc                  LIB "ODBC352.DLL" ALIAS "OdbcCopyDesc"        (BYVAL SourceDescHandle AS DWORD,  BYVAL TargetDescHandle AS DWORD)                  
DECLARE FUNCTION  OdbcGetConfigMode             LIB "ODBC352.DLL" ALIAS "OdbcGetConfigMode"      ()                               AS WORD                                                                                                                                                                               
DECLARE FUNCTION  OdbcSetConfigMode             LIB "ODBC352.DLL" ALIAS "OdbcSetConfigMode"      ( BYVAL wConfigMode AS WORD      )  AS                          INTEGER                                                                                                                                                
DECLARE FUNCTION  OdbcRemoveDriver              LIB "ODBC352.DLL" ALIAS "OdbcRemoveDriver"       ( BYVAL strDriver AS STRING      ,  BYVAL fRemoveDSN AS INTEGER)         AS                         DWORD                                                                                                             
DECLARE FUNCTION  OdbcRemoveDriverManager       LIB "ODBC352.DLL" ALIAS "OdbcRemoveDriverManager"()                               AS DWORD                                                                                                                                                                              
DECLARE FUNCTION  OdbcRemoveTranslator          LIB "ODBC352.DLL" ALIAS "OdbcRemoveTranslator"   ( BYVAL strTranslator AS STRING  )  AS                          DWORD                                                                                                                                                  
DECLARE FUNCTION  OdbcGetTranslator             LIB "ODBC352.DLL" ALIAS "OdbcGetTranslator"      ( BYVAL hWnd AS DWORD            ,  BYREF strName AS STRING    ,         BYREF strPath AS STRING   ,       BYREF pvOption AS DWORD)     AS                INTEGER                                                   
DECLARE SUB       OdbcPostInstallerError        LIB "ODBC352.DLL" ALIAS "OdbcPostInstallerError" ( BYVAL dwError AS DWORD         ,  BYVAL strErrorMsg AS STRING)                                                                                                                                                      
DECLARE FUNCTION  OdbcInstallDriverEx           LIB "ODBC352.DLL" ALIAS "OdbcInstallDriverEx"    ( BYVAL strDriver AS STRING      ,  BYVAL strPathIn AS STRING  ,         BYREF strPathOut AS STRING,       BYVAL fRequest AS WORD )     AS                DWORD                                                     
DECLARE FUNCTION  OdbcInstallTranslatorEx       LIB "ODBC352.DLL" ALIAS "OdbcInstallTranslatorEx"( BYVAL strTranslator AS STRING  ,  BYVAL strPathIn AS STRING  ,         BYREF strPathOut AS STRING,       BYVAL fRequest AS WORD )     AS                DWORD                                                     
DECLARE FUNCTION  OdbcConfigDriver              LIB "ODBC352.DLL" ALIAS "OdbcConfigDriver"       ( BYVAL hWndParent AS DWORD      ,  BYVAL fRequest AS WORD     ,         BYVAL strDriver AS STRING ,       BYVAL strArgs AS STRING,     lpszMsg AS ASCIIZ,       cbMsgMax AS WORD, pcbMsgOut AS WORD) AS INTEGER 
DECLARE SUB       OdbcGetDescRec                LIB "ODBC352.DLL" ALIAS "OdbcGetDescRec"         ( BYVAL DescriptorHandle AS DWORD,  BYVAL RecNumber AS INTEGER ,         BYREF szName AS ASCIIZ, BYREF StringLength AS INTEGER, BYREF nType AS INTEGER,  BYREF nSubType AS INTEGER, BYREF nLength AS LONG, BYREF nPrecision AS INTEGER, BYREF nScale AS INTEGER, BYREF nNullable AS INTEGER)                                                                                                         
DECLARE SUB       OdbcSetDescRec                LIB "ODBC352.DLL" ALIAS "OdbcSetDescRec" (BYVAL DescriptorHandle AS DWORD, BYVAL RecNumber AS INTEGER, BYVAL nType AS INTEGER, BYVAL nSubType AS INTEGER, BYVAL nLength AS LONG, BYVAL nPrecision AS INTEGER, BYVAL nScale AS INTEGER, BYVAL DataPtr AS DWORD, BYREF StringLength AS LONG, BYREF Indicator AS LONG)
DECLARE SUB       OdbcGetDescField              LIB "ODBC352.DLL" ALIAS "OdbcGetDescField" (BYVAL DescriptorHandle AS DWORD, BYVAL RecNumber AS INTEGER, BYVAL FieldIdentifier AS INTEGER, BYVAL ValuePtr AS DWORD, BYVAL BufferLength AS LONG, BYREF StringLength AS LONG)
DECLARE SUB       OdbcSetDescField              LIB "ODBC352.DLL" ALIAS "OdbcSetDescField" (BYVAL DescriptorHandle AS DWORD, BYVAL RecNumber AS INTEGER, BYVAL FieldIdentifier AS INTEGER, BYVAL ValuePtr AS DWORD, BYVAL BufferLength AS LONG)
DECLARE SUB       OdbcBindCol                   LIB "ODBC352.DLL" ALIAS "OdbcBindCol" (BYVAL StatementHandle AS DWORD, BYVAL ColumnNumber AS INTEGER, BYVAL TargetType AS INTEGER, BYVAL TargetValue AS DWORD, BYVAL BufferLength AS LONG, BYREF StrLen_or_Ind AS LONG)
DECLARE SUB       OdbcGetDiagField              LIB "ODBC352.DLL" ALIAS "OdbcGetDiagField" (BYVAL HandleType AS INTEGER, BYVAL hndl AS DWORD, BYVAL RecNumber AS INTEGER, BYVAL DiagIdentifier AS INTEGER, BYVAL DiagInfo AS DWORD, BYVAL BufferLength AS INTEGER, BYREF StringLength AS INTEGER)
DECLARE SUB       OdbcGetDiagRec                LIB "ODBC352.DLL" ALIAS "OdbcGetDiagRec" (BYVAL HandleType AS DWORD, BYVAL hndl AS DWORD, BYVAL RecNumber AS INTEGER, BYREF Sqlstate AS ASCIIZ, BYREF NativeError AS LONG, BYREF MessageText AS ASCIIZ, BYVAL BufferLength AS INTEGER, BYREF TextLength AS INTEGER)
DECLARE FUNCTION  OdbcReadFileDSN               LIB "ODBC352.DLL" ALIAS "OdbcReadFileDSN" (lpszFileName AS ASCIIZ, lpszAppName AS ASCIIZ, lpszKeyName AS ASCIIZ, lpszString AS ASCIIZ, BYVAL cbString AS WORD, pcbString AS WORD) AS INTEGER
DECLARE FUNCTION  OdbcWritePrivateProfileString LIB "ODBC352.DLL" ALIAS "OdbcWritePrivateProfileString" (lpszSection AS ASCIIZ, lpszEntry AS ASCIIZ, lpszString AS ASCIIZ, lpszFileName AS ASCIIZ) AS INTEGER
DECLARE FUNCTION  OdbcGetPrivateProfileString   LIB "ODBC352.DLL" ALIAS "OdbcGetPrivateProfileString" (lpszSection AS ASCIIZ, lpszEntry AS ASCIIZ, lpszDefault AS ASCIIZ, lpszRetBuffer AS ASCIIZ, BYVAL cbRetBuffer AS INTEGER, lpszFileName AS ASCIIZ) AS INTEGER
DECLARE SUB       OdbcDescribeParam             LIB "ODBC352.DLL" ALIAS "OdbcDescribeParam" (BYVAL hStmt AS DWORD, BYVAL ipar AS WORD, pfSqlType AS INTEGER, pfcbParamDef AS DWORD, pibScale AS INTEGER, pfNullable AS INTEGER)
DECLARE SUB       OdbcBindParameter             LIB "ODBC352.DLL" ALIAS "OdbcBindParameter" (BYVAL hStmt AS DWORD, BYVAL ParameterNumber AS WORD, BYVAL InputOutputType AS INTEGER, BYVAL ValueType AS INTEGER, BYVAL ParameterType AS INTEGER, BYVAL ColumnSize AS DWORD, BYVAL DecimalDigits AS INTEGER, BYVAL ParameterValuePtr AS DWORD, BYVAL BufferLength AS LONG, BYREF StrLen_or_IndPtr AS LONG)
DECLARE FUNCTION  OdbcGetInstalledDrivers       LIB "ODBC352.DLL" ALIAS "OdbcGetInstalledDrivers" () AS STRING
DECLARE SUB       OdbcInstallerError            LIB "ODBC352.DLL" ALIAS "OdbcInstallerError" (BYVAL iError AS WORD, BYREF pfErrorCode AS DWORD, BYREF strErrorMsg AS STRING)
DECLARE FUNCTION  OdbcGetInstallerErrorCode     LIB "ODBC352.DLL" ALIAS "OdbcGetInstallerErrorCode" (BYVAL iError AS WORD) AS DWORD
DECLARE FUNCTION  OdbcGetInstallerErrorMessage  LIB "ODBC352.DLL" ALIAS "OdbcGetInstallerErrorMessage" (BYVAL iError AS WORD) AS STRING
DECLARE FUNCTION  OdbcInstallDriverManager      LIB "ODBC352.DLL" ALIAS "OdbcInstallDriverManager" () AS STRING
DECLARE FUNCTION  OdbcGetDriverManagerInstallPath LIB "ODBC352.DLL" ALIAS "OdbcGetDriverManagerInstallPath" () AS STRING
DECLARE FUNCTION  OdbcManageDataSources         LIB "ODBC352.DLL" ALIAS "OdbcManageDataSources" (BYVAL hWnd AS DWORD) AS INTEGER
DECLARE FUNCTION  OdbcRemoveDSNFromIni          LIB "ODBC352.DLL" ALIAS "OdbcRemoveDSNFromIni" (BYVAL strDSN AS STRING) AS INTEGER
DECLARE FUNCTION  OdbcValidDSN                  LIB "ODBC352.DLL" ALIAS "OdbcValidDSN" (BYVAL strDSN AS STRING) AS INTEGER
DECLARE FUNCTION  OdbcWriteDSNToIni             LIB "ODBC352.DLL" ALIAS "OdbcWriteDSNToIni" (BYVAL strDSN AS STRING, BYVAL strDriver AS STRING) AS INTEGER
DECLARE FUNCTION  OdbcWriteFileDSN              LIB "ODBC352.DLL" ALIAS "OdbcWriteFileDSN" (lpszFileName AS ASCIIZ, lpszAppName AS ASCIIZ, lpszKeyName AS ASCIIZ) AS STRING
DECLARE FUNCTION  OdbcGetFunctions              LIB "ODBC352.DLL" ALIAS "OdbcGetFunctions" (BYVAL hDbc AS DWORD, BYVAL FunctionId AS WORD) AS WORD
DECLARE FUNCTION  OdbcSupports                  LIB "ODBC352.DLL" ALIAS "OdbcSupports" (BYVAL hDbc AS DWORD, BYVAL FunctionId AS WORD) AS WORD
DECLARE FUNCTION  OdbcGetSqlState               LIB "ODBC352.DLL" ALIAS "OdbcGetSqlState" (BYVAL HandleType AS INTEGER, BYVAL hndl AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetEnvSqlState            LIB "ODBC352.DLL" ALIAS "OdbcGetEnvSqlState" (BYVAL hEnv AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetEnvironmentSqlState    LIB "ODBC352.DLL" ALIAS "OdbcGetEnvironmentSqlState" (BYVAL hEnv AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetDbcSqlState            LIB "ODBC352.DLL" ALIAS "OdbcGetDbcSqlState" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetConnectionSqlState     LIB "ODBC352.DLL" ALIAS "OdbcGetConnectionSqlState"         (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetDescSqlState           LIB "ODBC352.DLL" ALIAS "OdbcGetDescSqlState"               (BYVAL hDesc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetDescriptorSqlState     LIB "ODBC352.DLL" ALIAS "OdbcGetDescriptorSqlState"         (BYVAL hDesc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetStmtSqlState           LIB "ODBC352.DLL" ALIAS "OdbcGetStmtSqlState"               (BYVAL hStmt AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetStatementSqlState      LIB "ODBC352.DLL" ALIAS "OdbcGetStatementSqlState"          (BYVAL hStmt AS DWORD) AS STRING
DECLARE SUB       OdbcGetData                   LIB "ODBC352.DLL" ALIAS "OdbcGetData"                       (BYVAL StatementHandle AS DWORD, BYVAL ColumnNumber AS WORD, BYVAL TargetType AS INTEGER, BYVAL TargetValue AS DWORD, BYVAL BufferLength AS LONG, BYREF StrLen_or_Ind AS LONG)
DECLARE FUNCTION  OdbcGetDataString             LIB "ODBC352.DLL" ALIAS "OdbcGetDataString"                 (BYVAL hStmt AS DWORD, BYVAL iCol AS INTEGER, OPTIONAL BYVAL lMaxChars AS LONG) AS STRING
DECLARE FUNCTION  OdbcGetLongVarcharData        LIB "ODBC352.DLL" ALIAS "OdbcGetLongVarcharData"            (BYVAL hStmt AS DWORD, BYVAL iCol AS INTEGER) AS STRING
Declare Function  OdbcGetDataStringByColName    Lib "ODBC352.DLL" Alias "OdbcGetDataStringByColName"        (ByVal hStmt As Dword, ByVal ColumnName As String, Optional ByVal lMaxChars As Long) As String
DECLARE FUNCTION  OdbcGetLongVarcharDataByColName LIB "ODBC352.DLL" ALIAS "OdbcGetLongVarcharDataByColName" (BYVAL hStmt AS DWORD, BYVAL ColumnName AS STRING) AS STRING
DECLARE SUB       OdbcPutData                   LIB "ODBC352.DLL" ALIAS "OdbcPutData"                       (BYVAL StatementHandle AS DWORD, BYVAL DataPtr AS DWORD, BYVAL StrLen_or_Ind AS LONG)
DECLARE SUB       OdbcParamData                 LIB "ODBC352.DLL" ALIAS "OdbcParamData"                     (BYVAL StatementHandle AS DWORD, BYREF ValuePtrPtr AS DWORD)
DECLARE SUB       OdbcUnbindCol                 LIB "ODBC352.DLL" ALIAS "OdbcUnbindCol"                     (BYVAL hStmt AS DWORD, BYVAL iCol AS INTEGER)
DECLARE SUB       OdbcUnbindColumns             LIB "ODBC352.DLL" ALIAS "OdbcUnbindColumns"                 (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcResetParams               LIB "ODBC352.DLL" ALIAS "OdbcResetParams"                   (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcPrepare                   LIB "ODBC352.DLL" ALIAS "OdbcPrepare" (BYVAL hStmt AS DWORD, BYVAL StatementText AS STRING)
DECLARE SUB       OdbcExecute                   LIB "ODBC352.DLL" ALIAS "OdbcExecute" (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcEndTran                   LIB "ODBC352.DLL" ALIAS "OdbcEndTran" (BYVAL HandleType AS INTEGER, BYVAL hndl AS DWORD, BYVAL CompletionType AS INTEGER)
DECLARE SUB       OdbcCommitTran                LIB "ODBC352.DLL" ALIAS "OdbcCommitTran" (BYVAL HandleType AS INTEGER, BYVAL hndl AS DWORD)
DECLARE SUB       OdbcRollbackTran              LIB "ODBC352.DLL" ALIAS "OdbcRollbackTran" (BYVAL HandleType AS INTEGER, BYVAL hndl AS DWORD)
DECLARE SUB       OdbcCommitEnvTran             LIB "ODBC352.DLL" ALIAS "OdbcCommitEnvTran" (BYVAL hEnv AS DWORD)
DECLARE SUB       OdbcRollbackEnvTran           LIB "ODBC352.DLL" ALIAS "OdbcRollbackEnvTran" (BYVAL hEnv AS DWORD)
DECLARE SUB       OdbcCommitDbcTran             LIB "ODBC352.DLL" ALIAS "OdbcCommitDbcTran" (BYVAL hDbc AS DWORD)
DECLARE SUB       OdbcRollbackDbcTran           LIB "ODBC352.DLL" ALIAS "OdbcRollbackDbcTran" (BYVAL hDbc AS DWORD)
DECLARE SUB       OdbcFetch                     LIB "ODBC352.DLL" ALIAS "OdbcFetch" (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcFetchScroll               LIB "ODBC352.DLL" ALIAS "OdbcFetchScroll" (BYVAL hStmt AS DWORD, BYVAL FetchOrientation AS INTEGER, BYVAL FetchOffset AS LONG)
DECLARE SUB       OdbcExtendedFetch             LIB "ODBC352.DLL" ALIAS "OdbcExtendedFetch" (BYVAL hStmt AS DWORD, BYVAL FetchOrientation AS WORD, BYVAL FetchOffset AS LONG, BYREF RowCountPtr AS DWORD, BYVAL RowStatusArray AS DWORD)
DECLARE FUNCTION  OdbcEof                       LIB "ODBC352.DLL" ALIAS "OdbcEof" () AS INTEGER
DECLARE SUB       OdbcCloseCursor               LIB "ODBC352.DLL" ALIAS "OdbcCloseCursor" (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcCloseStmtCursor           LIB "ODBC352.DLL" ALIAS "OdbcCloseStmtCursor" (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcMoveFirst                 LIB "ODBC352.DLL" ALIAS "OdbcMoveFirst" (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcMoveLast                  LIB "ODBC352.DLL" ALIAS "OdbcMoveLast" (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcMoveNext                  LIB "ODBC352.DLL" ALIAS "OdbcMoveNext" (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcMovePrevious              LIB "ODBC352.DLL" ALIAS "OdbcMovePrevious" (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcMove                      LIB "ODBC352.DLL" ALIAS "OdbcMove" (BYVAL hStmt AS DWORD, BYVAL FetchOffset AS LONG)
DECLARE SUB       OdbcSetAbsolutePosition       LIB "ODBC352.DLL" ALIAS "OdbcSetAbsolutePosition" (BYVAL hStmt AS DWORD, BYVAL FetchOffset AS LONG)
DECLARE SUB       OdbcSetRelativePosition       LIB "ODBC352.DLL" ALIAS "OdbcSetRelativePosition" (BYVAL hStmt AS DWORD, BYVAL FetchOffset AS LONG)
DECLARE SUB       OdbcSetCursorName             LIB "ODBC352.DLL" ALIAS "OdbcSetCursorName" (BYVAL hStmt AS DWORD, BYVAL CurName AS STRING)
DECLARE FUNCTION  OdbcGetCursorName             LIB "ODBC352.DLL" ALIAS "OdbcGetCursorName" (BYVAL hStmt AS DWORD) AS STRING
DECLARE SUB       OdbcGetStmtAttr               LIB "ODBC352.DLL" ALIAS "OdbcGetStmtAttr" (BYVAL StatementHandle AS DWORD, BYVAL Attribute AS LONG, BYVAL ValuePtr AS DWORD, BYVAL BufferLength AS LONG, BYVAL StringLength AS DWORD)
DECLARE SUB       OdbcSetStmtAttr               LIB "ODBC352.DLL" ALIAS "OdbcSetStmtAttr" (BYVAL StatementHandle AS DWORD, BYVAL Attribute AS LONG, BYVAL ValuePtr AS DWORD, BYVAL StringLength AS DWORD)
DECLARE SUB       OdbcSetCursorConcurrency      LIB "ODBC352.DLL" ALIAS "OdbcSetCursorConcurrency" (BYVAL hStmt AS DWORD, BYVAL CursorConcurrency AS DWORD)
DECLARE FUNCTION  OdbcGetCursorConcurrency      LIB "ODBC352.DLL" ALIAS "OdbcGetCursorConcurrency" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetCursorLockType         LIB "ODBC352.DLL" ALIAS "OdbcSetCursorLockType" (BYVAL hStmt AS DWORD, BYVAL LockType AS DWORD)
DECLARE FUNCTION  OdbcGetCursorLockType         LIB "ODBC352.DLL" ALIAS "OdbcGetCursorLockType" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetConcurValuesConcurrency  LIB "ODBC352.DLL" ALIAS "OdbcSetConcurValuesConcurrency" (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcSetOptimisticConcurrency  LIB "ODBC352.DLL" ALIAS "OdbcSetOptimisticConcurrency" (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcSetLockConcurrency        LIB "ODBC352.DLL" ALIAS "OdbcSetLockConcurrency" (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcSetReadOnlyConcurrency    LIB "ODBC352.DLL" ALIAS "OdbcSetReadOnlyConcurrency" (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcSetRowVerConcurrency      LIB "ODBC352.DLL" ALIAS "OdbcSetRowVerConcurrency" (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcSetCursorType             LIB "ODBC352.DLL" ALIAS "OdbcSetCursorType" (BYVAL hStmt AS DWORD, BYVAL CursorType AS DWORD)
DECLARE SUB       OdbcSetForwardOnlyCursor      LIB "ODBC352.DLL" ALIAS "OdbcSetForwardOnlyCursor" (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcSetKeysetDrivenCursor     LIB "ODBC352.DLL" ALIAS "OdbcSetKeysetDrivenCursor" (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcSetStaticCursor           LIB "ODBC352.DLL" ALIAS "OdbcSetStaticCursor" (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcSetDynamicCursor          LIB "ODBC352.DLL" ALIAS "OdbcSetDynamicCursor" (BYVAL hStmt AS DWORD)
DECLARE FUNCTION  OdbcGetCursorType             LIB "ODBC352.DLL" ALIAS "OdbcGetCursorType" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetCursorKeysetSize       LIB "ODBC352.DLL" ALIAS "OdbcSetCursorKeysetSize" (BYVAL hStmt AS DWORD, BYVAL KeysetSize AS DWORD)
DECLARE FUNCTION  OdbcGetCursorKeysetSize       LIB "ODBC352.DLL" ALIAS "OdbcGetCursorKeysetSize" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetCursorScrollability    LIB "ODBC352.DLL" ALIAS "OdbcSetCursorScrollability" (BYVAL hStmt AS DWORD, BYVAL CursorScrollability AS DWORD)
DECLARE FUNCTION  OdbcGetCursorScrollability    LIB "ODBC352.DLL" ALIAS "OdbcGetCursorScrollability" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetCursorSensitivity      LIB "ODBC352.DLL" ALIAS "OdbcSetCursorSensitivity" (BYVAL hStmt AS DWORD, BYVAL CursorSensitivity AS DWORD)
DECLARE FUNCTION  OdbcGetCursorSensitivity      LIB "ODBC352.DLL" ALIAS "OdbcGetCursorSensitivity" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcSetMultiuserKeysetCursor  LIB "ODBC352.DLL" ALIAS "OdbcSetMultiuserKeysetCursor" (BYVAL hStmt AS DWORD, BYVAL CursorName AS STRING) AS INTEGER
DECLARE SUB       OdbcSetPos                    LIB "ODBC352.DLL" ALIAS "OdbcSetPos" (BYVAL hStmt AS DWORD, BYVAL iRow AS WORD, BYVAL fOption AS WORD, BYVAL fLock AS WORD)
DECLARE SUB       OdbcSetPosition               LIB "ODBC352.DLL" ALIAS "OdbcSetPosition" (BYVAL hStmt AS DWORD, BYVAL irow AS WORD)
DECLARE SUB       OdbcUpdateRecord              LIB "ODBC352.DLL" ALIAS "OdbcUpdateRecord" (BYVAL hStmt AS DWORD, OPTIONAL BYVAL irow AS WORD)
DECLARE SUB       OdbcRefreshRecord             LIB "ODBC352.DLL" ALIAS "OdbcRefreshRecord" (BYVAL hStmt AS DWORD, OPTIONAL BYVAL irow AS WORD, BYVAL fLock AS WORD)
DECLARE SUB       OdbcLockRecord                LIB "ODBC352.DLL" ALIAS "OdbcLockRecord" (BYVAL hStmt AS DWORD, OPTIONAL BYVAL irow AS WORD)
DECLARE SUB       OdbcUnlockRecord              LIB "ODBC352.DLL" ALIAS "OdbcUnlockRecord" (BYVAL hStmt AS DWORD, OPTIONAL BYVAL irow AS WORD)
DECLARE SUB       OdbcDeleteRecord              LIB "ODBC352.DLL" ALIAS "OdbcDeleteRecord" (BYVAL hStmt AS DWORD, OPTIONAL BYVAL irow AS WORD)
DECLARE SUB       OdbcBulkOperations            LIB "ODBC352.DLL" ALIAS "OdbcBulkOperations" (BYVAL hStmt AS DWORD, BYVAL Operation AS LONG)
DECLARE SUB       OdbcAddRecord                 LIB "ODBC352.DLL" ALIAS "OdbcAddRecord" (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcUpdateByBookmark          LIB "ODBC352.DLL" ALIAS "OdbcUpdateByBookmark" (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcDeleteByBookmark          LIB "ODBC352.DLL" ALIAS "OdbcDeleteByBookmark" (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcFetchByBookmark           LIB "ODBC352.DLL" ALIAS "OdbcFetchByBookmark" (BYVAL hStmt AS DWORD)
DECLARE SUB       OdbcGetEnvAttr                LIB "ODBC352.DLL" ALIAS "OdbcGetEnvAttr" (BYVAL EnvironmentHandle AS DWORD, BYVAL Attribute AS DWORD, BYVAL ValuePtr AS DWORD, BYVAL BufferLength AS LONG, BYVAL StringLength AS DWORD)
DECLARE SUB       OdbcSetEnvAttr                LIB "ODBC352.DLL" ALIAS "OdbcSetEnvAttr" (BYVAL EnvironmentHandle AS DWORD, BYVAL Attribute AS LONG, BYVAL ValuePtr AS DWORD, BYVAL StringLength AS LONG)
DECLARE FUNCTION  OdbcGetEnvConnectionPooling   LIB "ODBC352.DLL" ALIAS "OdbcGetEnvConnectionPooling" (BYVAL hEnv AS DWORD) AS DWORD
DECLARE SUB       OdbcSetEnvConnectionPooling   LIB "ODBC352.DLL" ALIAS "OdbcSetEnvConnectionPooling" (BYVAL hEnv AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetEnvCPMatch             LIB "ODBC352.DLL" ALIAS "OdbcGetEnvCPMatch" (BYVAL hEnv AS DWORD) AS DWORD
DECLARE SUB       OdbcSetEnvCPMatch             LIB "ODBC352.DLL" ALIAS "OdbcSetEnvCPMatch" (BYVAL hEnv AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetEnvOdbcVersion         LIB "ODBC352.DLL" ALIAS "OdbcGetEnvOdbcVersion" (BYVAL hEnv AS DWORD) AS DWORD
DECLARE SUB       OdbcSetEnvOdbcVersion         LIB "ODBC352.DLL" ALIAS "OdbcSetEnvOdbcVersion" (BYVAL hEnv AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetEnvOutputNTS           LIB "ODBC352.DLL" ALIAS "OdbcGetEnvOutputNTS" (BYVAL hEnv AS DWORD) AS DWORD
DECLARE SUB       OdbcSetEnvOutputNTS           LIB "ODBC352.DLL" ALIAS "OdbcSetEnvOutputNTS" (BYVAL hEnv AS DWORD, dwAttr AS DWORD)
DECLARE SUB       OdbcGetConnectAttr            LIB "ODBC352.DLL" ALIAS "OdbcGetConnectAttr" (BYVAL ConnectionHandle AS DWORD, BYVAL Attribute AS LONG, BYVAL ValuePtr AS DWORD, BYVAL BufferLength AS LONG, BYREF StringLength AS LONG)
DECLARE SUB       OdbcSetConnectAttr            LIB "ODBC352.DLL" ALIAS "OdbcSetConnectAttr" (BYVAL ConnectionHandle AS DWORD, BYVAL Attribute AS LONG, BYVAL ValuePtr AS DWORD, BYVAL StringLength AS LONG)
DECLARE FUNCTION  OdbcGetAccessMode             LIB "ODBC352.DLL" ALIAS "OdbcGetAccessMode" (BYVAL hDBC AS DWORD) AS DWORD
DECLARE SUB       OdbcSetAccessMode             LIB "ODBC352.DLL" ALIAS "OdbcSetAccessMode" (BYVAL hDBC AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetAsyncEnable            LIB "ODBC352.DLL" ALIAS "OdbcGetAsyncEnable" (BYVAL hDBC AS DWORD) AS DWORD
DECLARE SUB       OdbcSetAsyncEnable            LIB "ODBC352.DLL" ALIAS "OdbcSetAsyncEnable" (BYVAL hDBC AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetAutoIPD                LIB "ODBC352.DLL" ALIAS "OdbcGetAutoIPD" (BYVAL hDBC AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetAutocommit             LIB "ODBC352.DLL" ALIAS "OdbcGetAutocommit" (BYVAL hDBC AS DWORD) AS DWORD
DECLARE SUB       OdbcSetAutocommit             LIB "ODBC352.DLL" ALIAS "OdbcSetAutocommit" (BYVAL hDBC AS DWORD, dwAttr AS DWORD)
DECLARE SUB       OdbcSetAutocommitOn           LIB "ODBC352.DLL" ALIAS "OdbcSetAutocommitOn" (BYVAL hDBC AS DWORD)
DECLARE SUB       OdbcSetAutocommitOff          LIB "ODBC352.DLL" ALIAS "OdbcSetAutocommitOff" (BYVAL hDBC AS DWORD)
DECLARE FUNCTION  OdbcGetConnectionDead         LIB "ODBC352.DLL" ALIAS "OdbcGetConnectionDead" (BYVAL hDBC AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcConnectionIsDead          LIB "ODBC352.DLL" ALIAS "OdbcConnectionIsDead" (BYVAL hDbc AS DWORD) AS INTEGER
DECLARE FUNCTION  OdbcConnectionIsAlive         LIB "ODBC352.DLL" ALIAS "OdbcConnectionIsAlive" (BYVAL hDbc AS DWORD) AS INTEGER
DECLARE FUNCTION  OdbcGetConnectionTimeout      LIB "ODBC352.DLL" ALIAS "OdbcGetConnectionTimeout" (BYVAL hDBC AS DWORD) AS DWORD
DECLARE SUB       OdbcSetConnectionTimeout      LIB "ODBC352.DLL" ALIAS "OdbcSetConnectionTimeout" (BYVAL hDBC AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetCurrentCatalog         LIB "ODBC352.DLL" ALIAS "OdbcGetCurrentCatalog" (BYVAL hDBC AS DWORD) AS STRING
DECLARE SUB       OdbcSetCurrentCatalog         LIB "ODBC352.DLL" ALIAS "OdbcSetCurrentCatalog" (BYVAL hDBC AS DWORD, BYVAL sAttr AS STRING)
DECLARE FUNCTION  OdbcGetLoginTimeout           LIB "ODBC352.DLL" ALIAS "OdbcGetLoginTimeout" (BYVAL hDBC AS DWORD) AS DWORD
DECLARE SUB       OdbcSetLoginTimeout           LIB "ODBC352.DLL" ALIAS "OdbcSetLoginTimeout" (BYVAL hDBC AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetMetadataID             LIB "ODBC352.DLL" ALIAS "OdbcGetMetadataID" (BYVAL hDBC AS DWORD) AS DWORD
DECLARE SUB       OdbcSetMetadataID             LIB "ODBC352.DLL" ALIAS "OdbcSetMetadataID" (BYVAL hDBC AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetOdbcCursors            LIB "ODBC352.DLL" ALIAS "OdbcGetOdbcCursors" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE SUB       OdbcSetOdbcCursors            LIB "ODBC352.DLL" ALIAS "OdbcSetOdbcCursors" (BYVAL hDbc AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetPacketMode             LIB "ODBC352.DLL" ALIAS "OdbcGetPacketMode" (BYVAL hDBC AS DWORD) AS DWORD
DECLARE SUB       OdbcSetPacketMode             LIB "ODBC352.DLL" ALIAS "OdbcSetPacketMode" (BYVAL hDBC AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetQuietMode              LIB "ODBC352.DLL" ALIAS "OdbcGetQuietMode" (BYVAL hDBC AS DWORD) AS DWORD
DECLARE SUB       OdbcSetQuietMode              LIB "ODBC352.DLL" ALIAS "OdbcSetQuietMode" (BYVAL hDBC AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetTrace                  LIB "ODBC352.DLL" ALIAS "OdbcGetTrace" (BYVAL hDBC AS DWORD) AS DWORD
DECLARE SUB       OdbcSetTrace                  LIB "ODBC352.DLL" ALIAS "OdbcSetTrace" (BYVAL hDBC AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetTraceFile              LIB "ODBC352.DLL" ALIAS "OdbcGetTraceFile" (BYVAL hDBC AS DWORD) AS STRING
DECLARE SUB       OdbcSetTraceFile              LIB "ODBC352.DLL" ALIAS "OdbcSetTraceFile" (BYVAL hDBC AS DWORD, BYVAL sAttr AS STRING)
DECLARE FUNCTION  OdbcGetTranslateLib           LIB "ODBC352.DLL" ALIAS "OdbcGetTranslateLib" (BYVAL hDBC AS DWORD) AS STRING
DECLARE SUB       OdbcSetTranslateLib           LIB "ODBC352.DLL" ALIAS "OdbcSetTranslateLib" (BYVAL hDBC AS DWORD, BYVAL sAttr AS STRING)
DECLARE FUNCTION  OdbcGetTxnIsolation           LIB "ODBC352.DLL" ALIAS "OdbcGetTxnIsolation" (BYVAL hDBC AS DWORD) AS DWORD
DECLARE SUB       OdbcSetTxnIsolation           LIB "ODBC352.DLL" ALIAS "OdbcSetTxnIsolation" (BYVAL hDBC AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtAppParamDesc       LIB "ODBC352.DLL" ALIAS "OdbcGetStmtAppParamDesc" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtAppParamDesc       LIB "ODBC352.DLL" ALIAS "OdbcSetStmtAppParamDesc" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtAppRowDesc         LIB "ODBC352.DLL" ALIAS "OdbcGetStmtAppRowDesc" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtAppRowDesc         LIB "ODBC352.DLL" ALIAS "OdbcSetStmtAppRowDesc" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtAsyncEnable        LIB "ODBC352.DLL" ALIAS "OdbcGetStmtAsyncEnable" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtAsyncEnable        LIB "ODBC352.DLL" ALIAS "OdbcSetStmtAsyncEnable" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtConcurrency        LIB "ODBC352.DLL" ALIAS "OdbcGetStmtConcurrency" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtConcurrency        LIB "ODBC352.DLL" ALIAS "OdbcSetStmtConcurrency" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtCursorScrollable   LIB "ODBC352.DLL" ALIAS "OdbcGetStmtCursorScrollable" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtCursorScrollable   LIB "ODBC352.DLL" ALIAS "OdbcSetStmtCursorScrollable" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtCursorSensitivity  LIB "ODBC352.DLL" ALIAS "OdbcGetStmtCursorSensitivity" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtCursorSensitivity  LIB "ODBC352.DLL" ALIAS "OdbcSetStmtCursorSensitivity" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtCursorType         LIB "ODBC352.DLL" ALIAS "OdbcGetStmtCursorType" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtCursorType         LIB "ODBC352.DLL" ALIAS "OdbcSetStmtCursorType" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtEnableAutoIPD      LIB "ODBC352.DLL" ALIAS "OdbcGetStmtEnableAutoIPD" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtEnableAutoIPD      LIB "ODBC352.DLL" ALIAS "OdbcSetStmtEnableAutoIPD" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtFetchBookmarkPtr   LIB "ODBC352.DLL" ALIAS "OdbcGetStmtFetchBookmarkPtr" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtFetchBookmarkPtr   LIB "ODBC352.DLL" ALIAS "OdbcSetStmtFetchBookmarkPtr" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtImpParamDesc       LIB "ODBC352.DLL" ALIAS "OdbcGetStmtImpParamDesc" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcGetImpParamDescRec        LIB "ODBC352.DLL" ALIAS "OdbcGetImpParamDescRec" (BYVAL hStmt AS DWORD, BYVAL RecNumber AS INTEGER, BYREF udtRowDesc AS ODBC_ATTR_IMP_DESC)
DECLARE SUB       OdbcGetImpParamDescField      LIB "ODBC352.DLL" ALIAS "OdbcGetImpParamDescField" (BYVAL hStmt AS DWORD, BYVAL RecNumber AS INTEGER, BYVAL FieldIdentifier AS INTEGER, BYVAL ValuePtr AS DWORD, BYVAL BufferLength AS LONG, BYREF StringLength AS LONG)
DECLARE FUNCTION  OdbcGetImpParamDescFieldName  LIB "ODBC352.DLL" ALIAS "OdbcGetImpParamDescFieldName" (BYVAL hStmt AS DWORD, BYVAL RecNumber AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcGetImpParamDescFieldType  LIB "ODBC352.DLL" ALIAS "OdbcGetImpParamDescFieldType" (BYVAL hStmt AS DWORD, BYVAL RecNumber AS INTEGER) AS INTEGER
DECLARE FUNCTION  OdbcGetImpParamDescFieldOctetLength LIB "ODBC352.DLL" ALIAS "OdbcGetImpParamDescFieldOctetLength" (BYVAL hStmt AS DWORD, BYVAL RecNumber AS INTEGER) AS INTEGER
DECLARE FUNCTION  OdbcGetImpParamDescFieldPrecision LIB "ODBC352.DLL" ALIAS "OdbcGetImpParamDescFieldPrecision" (BYVAL hStmt AS DWORD, BYVAL RecNumber AS INTEGER) AS INTEGER
DECLARE FUNCTION  OdbcGetImpParamDescFieldScale LIB "ODBC352.DLL" ALIAS "OdbcGetImpParamDescFieldScale" (BYVAL hStmt AS DWORD, BYVAL RecNumber AS INTEGER) AS INTEGER
DECLARE FUNCTION  OdbcGetImpParamDescFieldNullable LIB "ODBC352.DLL" ALIAS "OdbcGetImpParamDescFieldNullable" (BYVAL hStmt AS DWORD, BYVAL RecNumber AS INTEGER) AS INTEGER
DECLARE FUNCTION  OdbcGetStmtImpRowDesc         LIB "ODBC352.DLL" ALIAS "OdbcGetStmtImpRowDesc" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcGetImpRowDescRec          LIB "ODBC352.DLL" ALIAS "OdbcGetImpRowDescRec" (BYVAL hStmt AS DWORD, BYVAL RecNumber AS INTEGER, BYREF udtRowDesc AS ODBC_ATTR_IMP_DESC)
DECLARE SUB       OdbcGetImpRowDescField        LIB "ODBC352.DLL" ALIAS "OdbcGetImpRowDescField" (BYVAL hStmt AS DWORD, BYVAL RecNumber AS INTEGER, BYVAL FieldIdentifier AS INTEGER, BYVAL ValuePtr AS DWORD, BYVAL BufferLength AS LONG, BYREF StringLength AS LONG)
DECLARE FUNCTION  OdbcGetImpRowDescFieldName    LIB "ODBC352.DLL" ALIAS "OdbcGetImpRowDescFieldName" (BYVAL hStmt AS DWORD, BYVAL RecNumber AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcGetImpRowDescFieldType LIB "ODBC352.DLL" ALIAS "OdbcGetImpRowDescFieldType" (BYVAL hStmt AS DWORD, BYVAL RecNumber AS INTEGER) AS INTEGER
DECLARE FUNCTION  OdbcGetImpRowDescFieldOctetLength LIB "ODBC352.DLL" ALIAS "OdbcGetImpRowDescFieldOctetLength" (BYVAL hStmt AS DWORD, BYVAL RecNumber AS INTEGER) AS INTEGER
DECLARE FUNCTION  OdbcGetImpRowDescFieldPrecision LIB "ODBC352.DLL" ALIAS "OdbcGetImpRowDescFieldPrecision" (BYVAL hStmt AS DWORD, BYVAL RecNumber AS INTEGER) AS INTEGER
DECLARE FUNCTION  OdbcGetImpRowDescFieldScale LIB "ODBC352.DLL" ALIAS "OdbcGetImpRowDescFieldScale" (BYVAL hStmt AS DWORD, BYVAL RecNumber AS INTEGER) AS INTEGER
DECLARE FUNCTION  OdbcGetImpRowDescFieldNullable LIB "ODBC352.DLL" ALIAS "OdbcGetImpRowDescFieldNullable" (BYVAL hStmt AS DWORD, BYVAL RecNumber AS INTEGER) AS INTEGER
DECLARE FUNCTION  OdbcGetStmtKeysetSize LIB "ODBC352.DLL" ALIAS "OdbcGetStmtKeysetSize" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtKeysetSize LIB "ODBC352.DLL" ALIAS "OdbcSetStmtKeysetSize" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtMaxLength LIB "ODBC352.DLL" ALIAS "OdbcGetStmtMaxLength" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtMaxLength LIB "ODBC352.DLL" ALIAS "OdbcSetStmtMaxLength" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtMaxRows LIB "ODBC352.DLL" ALIAS "OdbcGetStmtMaxRows" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtMaxRows LIB "ODBC352.DLL" ALIAS "OdbcSetStmtMaxRows" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtMetadataID LIB "ODBC352.DLL" ALIAS "OdbcGetStmtMetadataID" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtMetadataID LIB "ODBC352.DLL" ALIAS "OdbcSetStmtMetadataID" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtNoScan LIB "ODBC352.DLL" ALIAS "OdbcGetStmtNoScan" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtNoScan LIB "ODBC352.DLL" ALIAS "OdbcSetStmtNoScan" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtParamBindOffsetPtr LIB "ODBC352.DLL" ALIAS "OdbcGetStmtParamBindOffsetPtr" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtParamBindOffsetPtr LIB "ODBC352.DLL" ALIAS "OdbcSetStmtParamBindOffsetPtr" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtParamBindType LIB "ODBC352.DLL" ALIAS "OdbcGetStmtParamBindType" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtParamBindType LIB "ODBC352.DLL" ALIAS "OdbcSetStmtParamBindType" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtParamOperationPtr LIB "ODBC352.DLL" ALIAS "OdbcGetStmtParamOperationPtr" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtParamOperationPtr LIB "ODBC352.DLL" ALIAS "OdbcSetStmtParamOperationPtr" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtParamStatusPtr LIB "ODBC352.DLL" ALIAS "OdbcGetStmtParamStatusPtr" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtParamStatusPtr LIB "ODBC352.DLL" ALIAS "OdbcSetStmtParamStatusPtr" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtParamsProcessedPtr LIB "ODBC352.DLL" ALIAS "OdbcGetStmtParamsProcessedPtr" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtParamsProcessedPtr LIB "ODBC352.DLL" ALIAS "OdbcSetStmtParamsProcessedPtr" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtParamsetSize LIB "ODBC352.DLL" ALIAS "OdbcGetStmtParamsetSize" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtParamsetSize LIB "ODBC352.DLL" ALIAS "OdbcSetStmtParamsetSize" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtQueryTimeout LIB "ODBC352.DLL" ALIAS "OdbcGetStmtQueryTimeout" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtQueryTimeout LIB "ODBC352.DLL" ALIAS "OdbcSetStmtQueryTimeout" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtRetrieveData LIB "ODBC352.DLL" ALIAS "OdbcGetStmtRetrieveData" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtRetrieveData LIB "ODBC352.DLL" ALIAS "OdbcSetStmtRetrieveData" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtRowArraySize LIB "ODBC352.DLL" ALIAS "OdbcGetStmtRowArraySize" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtRowArraySize LIB "ODBC352.DLL" ALIAS "OdbcSetStmtRowArraySize" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtRowBindOffsetPtr LIB "ODBC352.DLL" ALIAS "OdbcGetStmtRowBindOffsetPtr" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtRowBindOffsetPtr LIB "ODBC352.DLL" ALIAS "OdbcSetStmtRowBindOffsetPtr" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtRowBindType LIB "ODBC352.DLL" ALIAS "OdbcGetStmtRowBindType" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtRowBindType LIB "ODBC352.DLL" ALIAS "OdbcSetStmtRowBindType" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtRowNumber LIB "ODBC352.DLL" ALIAS "OdbcGetStmtRowNumber" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetStmtRowOperationPtr LIB "ODBC352.DLL" ALIAS "OdbcGetStmtRowOperationPtr" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtRowOperationPtr LIB "ODBC352.DLL" ALIAS "OdbcSetStmtRowOperationPtr" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtRowStatusPtr LIB "ODBC352.DLL" ALIAS "OdbcGetStmtRowStatusPtr" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtRowStatusPtr LIB "ODBC352.DLL" ALIAS "OdbcSetStmtRowStatusPtr" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtRowsFetchedPtr LIB "ODBC352.DLL" ALIAS "OdbcGetStmtRowsFetchedPtr" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtRowsFetchedPtr LIB "ODBC352.DLL" ALIAS "OdbcSetStmtRowsFetchedPtr" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtSimulateCursor LIB "ODBC352.DLL" ALIAS "OdbcGetStmtSimulateCursor" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtSimulateCursor LIB "ODBC352.DLL" ALIAS "OdbcSetStmtSimulateCursor" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE FUNCTION  OdbcGetStmtUseBookmarks LIB "ODBC352.DLL" ALIAS "OdbcGetStmtUseBookmarks" (BYVAL hStmt AS DWORD) AS DWORD
DECLARE SUB       OdbcSetStmtUseBookmarks LIB "ODBC352.DLL" ALIAS "OdbcSetStmtUseBookmarks" (BYVAL hStmt AS DWORD, dwAttr AS DWORD)
DECLARE SUB       OdbcDescribeCol LIB "ODBC352.DLL" ALIAS "OdbcDescribeCol" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER, ucol AS ODBC_COL_DESC_TYPE)
DECLARE SUB       OdbcColAttribute LIB "ODBC352.DLL" ALIAS "OdbcColAttribute" (BYVAL StatementHandle AS DWORD, BYVAL ColumnNumber AS WORD, BYVAL FieldIdentifier AS WORD, BYVAL CharacterAttribute AS DWORD, BYVAL BufferLength AS INTEGER, BYREF StringLength AS INTEGER, BYVAL NumericAttribute AS DWORD)
DECLARE FUNCTION  OdbcColAutoUniqueValue LIB "ODBC352.DLL" ALIAS "OdbcColAutoUniqueValue" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS LONG
DECLARE FUNCTION  OdbcColBaseColumnName LIB "ODBC352.DLL" ALIAS "OdbcColBaseColumnName" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcColBaseTableName LIB "ODBC352.DLL" ALIAS "OdbcColBaseTableName" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcColCaseSensitive LIB "ODBC352.DLL" ALIAS "OdbcColCaseSensitive" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS LONG
DECLARE FUNCTION  OdbcColCatalogName LIB "ODBC352.DLL" ALIAS "OdbcColCatalogName" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcColConciseType LIB "ODBC352.DLL" ALIAS "OdbcColConciseType" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS LONG
DECLARE FUNCTION  OdbcColCount LIB "ODBC352.DLL" ALIAS "OdbcColCount" (BYVAL hStmt AS DWORD) AS LONG
DECLARE FUNCTION  OdbcColDisplaySize LIB "ODBC352.DLL" ALIAS "OdbcColDisplaySize" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS LONG
DECLARE FUNCTION  OdbcColFixedPrecScale LIB "ODBC352.DLL" ALIAS "OdbcColFixedPrecScale" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS LONG
DECLARE FUNCTION  OdbcColLabel LIB "ODBC352.DLL" ALIAS "OdbcColLabel" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcColLength LIB "ODBC352.DLL" ALIAS "OdbcColLength" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS LONG
DECLARE FUNCTION  OdbcColLiteralPrefix LIB "ODBC352.DLL" ALIAS "OdbcColLiteralPrefix" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcColLiteralSuffix LIB "ODBC352.DLL" ALIAS "OdbcColLiteralSuffix" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcColLocalTypeName LIB "ODBC352.DLL" ALIAS "OdbcColLocalTypeName" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcColName LIB "ODBC352.DLL" ALIAS "OdbcColName" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcColNullable LIB "ODBC352.DLL" ALIAS "OdbcColNullable" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS LONG
DECLARE FUNCTION  OdbcColNumPrecRadix LIB "ODBC352.DLL" ALIAS "OdbcColNumPrecRadix" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS LONG
DECLARE FUNCTION  OdbcColOctetLength LIB "ODBC352.DLL" ALIAS "OdbcColOctetLength" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS LONG
DECLARE FUNCTION  OdbcColPrecision LIB "ODBC352.DLL" ALIAS "OdbcColPrecision" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS LONG
DECLARE FUNCTION  OdbcColScale LIB "ODBC352.DLL" ALIAS "OdbcColScale" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS LONG
DECLARE FUNCTION  OdbcColSchemaName LIB "ODBC352.DLL" ALIAS "OdbcColSchemaName" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcColSearchable LIB "ODBC352.DLL" ALIAS "OdbcColSearchable" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS LONG
DECLARE FUNCTION  OdbcColTableName LIB "ODBC352.DLL" ALIAS "OdbcColTableName" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcColType LIB "ODBC352.DLL" ALIAS "OdbcColType" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS LONG
DECLARE FUNCTION  OdbcColTypeName LIB "ODBC352.DLL" ALIAS "OdbcColTypeName" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS STRING
DECLARE FUNCTION  OdbcColUnnamed LIB "ODBC352.DLL" ALIAS "OdbcColUnnamed" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS LONG
DECLARE FUNCTION  OdbcColUnsigned LIB "ODBC352.DLL" ALIAS "OdbcColUnsigned" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS LONG
DECLARE FUNCTION  OdbcColUpdatable LIB "ODBC352.DLL" ALIAS "OdbcColUpdatable" (BYVAL hStmt AS DWORD, BYVAL ColNum AS INTEGER) AS LONG
DECLARE SUB       OdbcGetInfo LIB "ODBC352.DLL" ALIAS "OdbcGetInfo" (BYVAL ConnectionHandle AS DWORD, BYVAL InfoType AS WORD, BYVAL InfoValuePtr AS DWORD, BYVAL BufferLength AS INTEGER, BYREF StringLength AS INTEGER)
DECLARE FUNCTION  OdbcGetInfoStr LIB "ODBC352.DLL" ALIAS "OdbcGetInfoStr" (BYVAL ConnectionHandle AS DWORD, BYVAL InfoType AS WORD) AS STRING
DECLARE FUNCTION  OdbcGetInfoInt LIB "ODBC352.DLL" ALIAS "OdbcGetInfoInt" (BYVAL ConnectionHandle AS DWORD, BYVAL InfoType AS WORD) AS WORD
DECLARE FUNCTION  OdbcGetInfoLong LIB "ODBC352.DLL" ALIAS "OdbcGetInfoLong" (BYVAL ConnectionHandle AS DWORD, BYVAL InfoType AS WORD) AS DWORD
DECLARE FUNCTION  OdbcGetDMVer LIB "ODBC352.DLL" ALIAS "OdbcGetDMVer" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetDMVerMajor LIB "ODBC352.DLL" ALIAS "OdbcGetDMVerMajor" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetDMVerMinor LIB "ODBC352.DLL" ALIAS "OdbcGetDMVerMinor" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcWrongDriver LIB "ODBC352.DLL" ALIAS "OdbcWrongDriver" (BYVAL hDbc AS DWORD) AS INTEGER
DECLARE FUNCTION  OdbcGetXOpenCliYear LIB "ODBC352.DLL" ALIAS "OdbcGetXOpenCliYear" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetActiveEnvironments LIB "ODBC352.DLL" ALIAS "OdbcGetActiveEnvironments" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetAsyncMode LIB "ODBC352.DLL" ALIAS "OdbcGetAsyncMode" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetBatchRowCount LIB "ODBC352.DLL" ALIAS "OdbcGetBatchRowCount" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetBatchSupport LIB "ODBC352.DLL" ALIAS "OdbcGetBatchSupport" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetDataSourceName LIB "ODBC352.DLL" ALIAS "OdbcGetDataSourceName" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetDriverhEnv LIB "ODBC352.DLL" ALIAS "OdbcGetDriverhEnv" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetDriverhDbc LIB "ODBC352.DLL" ALIAS "OdbcGetDriverhDbc" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetDriverhLib LIB "ODBC352.DLL" ALIAS "OdbcGetDriverhLib" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetDriverName LIB "ODBC352.DLL" ALIAS "OdbcGetDriverName" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetDriverOdbcVer LIB "ODBC352.DLL" ALIAS "OdbcGetDriverOdbcVer" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetDriverVer LIB "ODBC352.DLL" ALIAS "OdbcGetDriverVer" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetDynamicCursorAttributes1 LIB "ODBC352.DLL" ALIAS "OdbcGetDynamicCursorAttributes1" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetDynamicCursorAttributes2 LIB "ODBC352.DLL" ALIAS "OdbcGetDynamicCursorAttributes2" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetForwardOnlyCursorAttributes1 LIB "ODBC352.DLL" ALIAS "OdbcGetForwardOnlyCursorAttributes1" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetForwardOnlyCursorAttributes2 LIB "ODBC352.DLL" ALIAS "OdbcGetForwardOnlyCursorAttributes2" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetFileUsage LIB "ODBC352.DLL" ALIAS "OdbcGetFileUsage" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetDataExtensions LIB "ODBC352.DLL" ALIAS "OdbcGetDataExtensions" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetInfoSchemaViews LIB "ODBC352.DLL" ALIAS "OdbcGetInfoSchemaViews" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetKeysetCursorAttributes1 LIB "ODBC352.DLL" ALIAS "OdbcGetKeysetCursorAttributes1" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetKeysetCursorAttributes2 LIB "ODBC352.DLL" ALIAS "OdbcGetKeysetCursorAttributes2" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetMaxAsyncConcurrentStatements LIB "ODBC352.DLL" ALIAS "OdbcGetMaxAsyncConcurrentStatements" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetMaxConcurrentActivities LIB "ODBC352.DLL" ALIAS "OdbcGetMaxConcurrentActivities" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetMaxDriverConnections LIB "ODBC352.DLL" ALIAS "OdbcGetMaxDriverConnections" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetODBCInterfaceConformance LIB "ODBC352.DLL" ALIAS "OdbcGetODBCInterfaceConformance" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetOdbcVer LIB "ODBC352.DLL" ALIAS "OdbcGetOdbcVer" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetParamArrayRowCounts LIB "ODBC352.DLL" ALIAS "OdbcGetParamArrayRowCounts" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetParamArraySelects LIB "ODBC352.DLL" ALIAS "OdbcGetParamArraySelects" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetPosOperations LIB "ODBC352.DLL" ALIAS "OdbcGetPosOperations" (BYVAL hDbc AS DWORD) AS LONG
DECLARE FUNCTION  OdbcGetStandardCliConformance LIB "ODBC352.DLL" ALIAS "OdbcGetStandardCliConformance" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetRowUpdates LIB "ODBC352.DLL" ALIAS "OdbcGetRowUpdates" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetSearchPatternEscape LIB "ODBC352.DLL" ALIAS "OdbcGetSearchPatternEscape" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetServerName LIB "ODBC352.DLL" ALIAS "OdbcGetServerName" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetStaticCursorAttributes1 LIB "ODBC352.DLL" ALIAS "OdbcGetStaticCursorAttributes1" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetStaticCursorAttributes2 LIB "ODBC352.DLL" ALIAS "OdbcGetStaticCursorAttributes2" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetDatabaseName LIB "ODBC352.DLL" ALIAS "OdbcGetDatabaseName" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetDBMSName LIB "ODBC352.DLL" ALIAS "OdbcGetDBMSName" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetDBMSVer LIB "ODBC352.DLL" ALIAS "OdbcGetDBMSVer" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetAccessibleProcedures LIB "ODBC352.DLL" ALIAS "OdbcGetAccessibleProcedures" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetAccessibleTables LIB "ODBC352.DLL" ALIAS "OdbcGetAccessibleTables" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetBookmarkPersistence LIB "ODBC352.DLL" ALIAS "OdbcGetBookmarkPersistence" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetCatalogTerm LIB "ODBC352.DLL" ALIAS "OdbcGetCatalogTerm" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetCollationSeq LIB "ODBC352.DLL" ALIAS "OdbcGetCollationSeq" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetConcatNullBehavior LIB "ODBC352.DLL" ALIAS "OdbcGetConcatNullBehavior" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetCursorCommitBehavior LIB "ODBC352.DLL" ALIAS "OdbcGetCursorCommitBehavior" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetCursorRollbackBehavior LIB "ODBC352.DLL" ALIAS "OdbcGetCursorRollbackBehavior" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetCursorSensitivitySupport LIB "ODBC352.DLL" ALIAS "OdbcGetCursorSensitivitySupport" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetDataSourceReadOnly LIB "ODBC352.DLL" ALIAS "OdbcGetDataSourceReadOnly" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetDefaultTxnIsolation LIB "ODBC352.DLL" ALIAS "OdbcGetDefaultTxnIsolation" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetDescribeParameter LIB "ODBC352.DLL" ALIAS "OdbcGetDescribeParameter" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetMultResultSets LIB "ODBC352.DLL" ALIAS "OdbcGetMultResultSets" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetMultipleActiveTxn LIB "ODBC352.DLL" ALIAS "OdbcGetMultipleActiveTxn" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetNeedLongDataLen LIB "ODBC352.DLL" ALIAS "OdbcGetNeedLongDataLen" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetNullCollation LIB "ODBC352.DLL" ALIAS "OdbcGetNullCollation" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetProcedureTerm LIB "ODBC352.DLL" ALIAS "OdbcGetProcedureTerm" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetSchemaTerm LIB "ODBC352.DLL" ALIAS "OdbcGetSchemaTerm" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetScrollOptions LIB "ODBC352.DLL" ALIAS "OdbcGetScrollOptions" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetTableTerm LIB "ODBC352.DLL" ALIAS "OdbcGetTableTerm" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetTxnCapable LIB "ODBC352.DLL" ALIAS "OdbcGetTxnCapable" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetTxnIsolationOption LIB "ODBC352.DLL" ALIAS "OdbcGetTxnIsolationOption" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetUserName LIB "ODBC352.DLL" ALIAS "OdbcGetUserName" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetAggregateFunctions LIB "ODBC352.DLL" ALIAS "OdbcGetAggregateFunctions" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetAlterDomain LIB "ODBC352.DLL" ALIAS "OdbcGetAlterDomain" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetAlterTable LIB "ODBC352.DLL" ALIAS "OdbcGetAlterTable" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetCatalogLocation LIB "ODBC352.DLL" ALIAS "OdbcGetCatalogLocation" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetCatalogName LIB "ODBC352.DLL" ALIAS "OdbcGetCatalogName" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetCatalogNameSeparator LIB "ODBC352.DLL" ALIAS "OdbcGetCatalogNameSeparator" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetCatalogUsage LIB "ODBC352.DLL" ALIAS "OdbcGetCatalogUsage" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetColumnAlias LIB "ODBC352.DLL" ALIAS "OdbcGetColumnAlias" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetCorrelationName LIB "ODBC352.DLL" ALIAS "OdbcGetCorrelationName" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetCreateAssertion LIB "ODBC352.DLL" ALIAS "OdbcGetCreateAssertion" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetCreateCharacterSet LIB "ODBC352.DLL" ALIAS "OdbcGetCreateCharacterSet" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetCreateCollation LIB "ODBC352.DLL" ALIAS "OdbcGetCreateCollation" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetCreateDomain LIB "ODBC352.DLL" ALIAS "OdbcGetCreateDomain" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetCreateSchema LIB "ODBC352.DLL" ALIAS "OdbcGetCreateSchema" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetCreateTable LIB "ODBC352.DLL" ALIAS "OdbcGetCreateTable" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetCreateTranslation LIB "ODBC352.DLL" ALIAS "OdbcGetCreateTranslation" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetCreateView LIB "ODBC352.DLL" ALIAS "OdbcGetCreateView" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetDateTimeLiterals LIB "ODBC352.DLL" ALIAS "OdbcGetDateTimeLiterals" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetDDLIndex LIB "ODBC352.DLL" ALIAS "OdbcGetDDLIndex" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetDropAssertion LIB "ODBC352.DLL" ALIAS "OdbcGetDropAssertion" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetDropCharacterSet LIB "ODBC352.DLL" ALIAS "OdbcGetDropCharacterSet" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetDropCollation LIB "ODBC352.DLL" ALIAS "OdbcGetDropCollation" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetDropDomain LIB "ODBC352.DLL" ALIAS "OdbcGetDropDomain" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetDropSchema LIB "ODBC352.DLL" ALIAS "OdbcGetDropSchema" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetDropTable LIB "ODBC352.DLL" ALIAS "OdbcGetDropTable" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetDropTranslation LIB "ODBC352.DLL" ALIAS "OdbcGetDropTranslation" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetDropView LIB "ODBC352.DLL" ALIAS "OdbcGetDropView" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetExpressionsInOrderBy LIB "ODBC352.DLL" ALIAS "OdbcGetExpressionsInOrderBy" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetGroupBy LIB "ODBC352.DLL" ALIAS "OdbcGetGroupBy" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetIdentifierCase LIB "ODBC352.DLL" ALIAS "OdbcGetIdentifierCase" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetIdentifierQuoteChar LIB "ODBC352.DLL" ALIAS "OdbcGetIdentifierQuoteChar" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetIndexKeywords LIB "ODBC352.DLL" ALIAS "OdbcGetIndexKeywords" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetInsertStatement LIB "ODBC352.DLL" ALIAS "OdbcGetInsertStatement" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetIntegrity LIB "ODBC352.DLL" ALIAS "OdbcGetIntegrity" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetKeywords LIB "ODBC352.DLL" ALIAS "OdbcGetKeywords" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetLikeEscapeClause LIB "ODBC352.DLL" ALIAS "OdbcGetLikeEscapeClause" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetNonNullableColumns LIB "ODBC352.DLL" ALIAS "OdbcGetNonNullableColumns" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetSqlConformance LIB "ODBC352.DLL" ALIAS "OdbcGetSqlConformance" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetOJCapabilities LIB "ODBC352.DLL" ALIAS "OdbcGetOJCapabilities" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetOuterJoins LIB "ODBC352.DLL" ALIAS "OdbcGetOuterJoins" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetOrderByColumnsInSelect LIB "ODBC352.DLL" ALIAS "OdbcGetOrderByColumnsInSelect" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetProceduresSupport LIB "ODBC352.DLL" ALIAS "OdbcGetProceduresSupport" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcQuotedIdentifierCase LIB "ODBC352.DLL" ALIAS "OdbcQuotedIdentifierCase" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetSchemaUsage LIB "ODBC352.DLL" ALIAS "OdbcGetSchemaUsage" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetSpecialCharacters LIB "ODBC352.DLL" ALIAS "OdbcGetSpecialCharacters" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetSubqueries LIB "ODBC352.DLL" ALIAS "OdbcGetSubqueries" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetUnion LIB "ODBC352.DLL" ALIAS "OdbcGetUnion" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetMaxBinaryLiteralLen LIB "ODBC352.DLL" ALIAS "OdbcGetMaxBinaryLiteralLen" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetMaxCatalogNameLen LIB "ODBC352.DLL" ALIAS "OdbcGetMaxCatalogNameLen" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetMaxCharLiteralLen LIB "ODBC352.DLL" ALIAS "OdbcGetMaxCharLiteralLen" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetMaxColumnNameLen LIB "ODBC352.DLL" ALIAS "OdbcGetMaxColumnNameLen" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetMaxColumnsInGroupBy LIB "ODBC352.DLL" ALIAS "OdbcGetMaxColumnsInGroupBy" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetMaxColumnsInIndex LIB "ODBC352.DLL" ALIAS "OdbcGetMaxColumnsInIndex" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetMaxColumnsInOrderBy LIB "ODBC352.DLL" ALIAS "OdbcGetMaxColumnsInOrderBy" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetMaxColumnsInSelect LIB "ODBC352.DLL" ALIAS "OdbcGetMaxColumnsInSelect" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetMaxColumnsInTable LIB "ODBC352.DLL" ALIAS "OdbcGetMaxColumnsInTable" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetMaxCursorNameLen LIB "ODBC352.DLL" ALIAS "OdbcGetMaxCursorNameLen" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetMaxIdentifierLen LIB "ODBC352.DLL" ALIAS "OdbcGetMaxIdentifierLen" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetMaxIndexSize LIB "ODBC352.DLL" ALIAS "OdbcGetMaxIndexSize" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetMaxProcedureNameLen LIB "ODBC352.DLL" ALIAS "OdbcGetMaxProcedureNameLen" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetMaxRowSize LIB "ODBC352.DLL" ALIAS "OdbcGetMaxRowSize" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetMaxRowSizeIncludesLong LIB "ODBC352.DLL" ALIAS "OdbcGetMaxRowSizeIncludesLong" (BYVAL hDbc AS DWORD) AS STRING
DECLARE FUNCTION  OdbcGetMaxSchemaNameLen LIB "ODBC352.DLL" ALIAS "OdbcGetMaxSchemaNameLen" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetMaxStatementLen LIB "ODBC352.DLL" ALIAS "OdbcGetMaxStatementLen" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetMaxTableNameLen LIB "ODBC352.DLL" ALIAS "OdbcGetMaxTableNameLen" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetMaxTablesInSelect LIB "ODBC352.DLL" ALIAS "OdbcGetMaxTablesInSelect" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetMaxUserNameLen LIB "ODBC352.DLL" ALIAS "OdbcGetMaxUserNameLen" (BYVAL hDbc AS DWORD) AS WORD
DECLARE FUNCTION  OdbcGetConvertFunctions LIB "ODBC352.DLL" ALIAS "OdbcGetConvertFunctions" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetNumericFunctions LIB "ODBC352.DLL" ALIAS "OdbcGetNumericFunctions" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetStringFunctions LIB "ODBC352.DLL" ALIAS "OdbcGetStringFunctions" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetSystemFunctions LIB "ODBC352.DLL" ALIAS "OdbcGetSystemFunctions" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetTimeDateAddIntervals LIB "ODBC352.DLL" ALIAS "OdbcGetTimeDateAddIntervals" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetTimeDateDiffIntervals LIB "ODBC352.DLL" ALIAS "OdbcGetTimeDateDiffIntervals" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetTimeDateFunctions LIB "ODBC352.DLL" ALIAS "OdbcGetTimeDateFunctions" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetConvertBigInt LIB "ODBC352.DLL" ALIAS "OdbcGetConvertBigInt" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetConvertBinary LIB "ODBC352.DLL" ALIAS "OdbcGetConvertBinary" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetConvertBit LIB "ODBC352.DLL" ALIAS "OdbcGetConvertBit" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetConvertChar LIB "ODBC352.DLL" ALIAS "OdbcGetConvertChar" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetConvertDate LIB "ODBC352.DLL" ALIAS "OdbcGetConvertDate" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetConvertDecimal LIB "ODBC352.DLL" ALIAS "OdbcGetConvertDecimal" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetConvertDouble LIB "ODBC352.DLL" ALIAS "OdbcGetConvertDouble" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetConvertFloat LIB "ODBC352.DLL" ALIAS "OdbcGetConvertFloat" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetConvertInteger LIB "ODBC352.DLL" ALIAS "OdbcGetConvertInteger" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetConvertIntervalYearMonth LIB "ODBC352.DLL" ALIAS "OdbcGetConvertIntervalYearMonth" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetConvertIntervalDayTime LIB "ODBC352.DLL" ALIAS "OdbcGetConvertIntervalDayTime" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGEtConvertLongVarBinary LIB "ODBC352.DLL" ALIAS "OdbcGEtConvertLongVarBinary" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetConvertLongVarChar LIB "ODBC352.DLL" ALIAS "OdbcGetConvertLongVarChar" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetConvertNumeric LIB "ODBC352.DLL" ALIAS "OdbcGetConvertNumeric" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetConvertReal LIB "ODBC352.DLL" ALIAS "OdbcGetConvertReal" (BYVAL hDbc AS  DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetConvertSmallInt LIB "ODBC352.DLL" ALIAS "OdbcGetConvertSmallInt" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetConvertTime LIB "ODBC352.DLL" ALIAS "OdbcGetConvertTime" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetConvertTimeStamp LIB "ODBC352.DLL" ALIAS "OdbcGetConvertTimeStamp" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetConvertTinyInt LIB "ODBC352.DLL" ALIAS "OdbcGetConvertTinyInt" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetConvertVarBinary LIB "ODBC352.DLL" ALIAS "OdbcGetConvertVarBinary" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetConvertVarChar LIB "ODBC352.DLL" ALIAS "OdbcGetConvertVarChar" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetSql92DateTimeFunctions LIB "ODBC352.DLL" ALIAS "OdbcGetSql92DateTimeFunctions" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetSql92ForeignKeyDeleteRule LIB "ODBC352.DLL" ALIAS "OdbcGetSql92ForeignKeyDeleteRule" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetSql92ForeignKeyUpdateRule LIB "ODBC352.DLL" ALIAS "OdbcGetSql92ForeignKeyUpdateRule" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetSql92Grant LIB "ODBC352.DLL" ALIAS "OdbcGetSql92Grant" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetSql92NumericValueFunctions LIB "ODBC352.DLL" ALIAS "OdbcGetSql92NumericValueFunctions" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetSql92Predicates LIB "ODBC352.DLL" ALIAS "OdbcGetSql92Predicates" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetSql92RelationalJoinOperators LIB "ODBC352.DLL" ALIAS "OdbcGetSql92RelationalJoinOperators" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetSql92Revoke LIB "ODBC352.DLL" ALIAS "OdbcGetSql92Revoke" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetSql92RowValueConstructor LIB "ODBC352.DLL" ALIAS "OdbcGetSql92RowValueConstructor" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetSql92StringFunctions LIB "ODBC352.DLL" ALIAS "OdbcGetSql92StringFunctions" (BYVAL hDbc AS DWORD) AS DWORD
DECLARE FUNCTION  OdbcGetSql92ValueExpressions LIB "ODBC352.DLL" ALIAS "OdbcGetSql92ValueExpressions" (BYVAL hDbc AS DWORD) AS DWORD

DECLARE FUNCTION  OdbcColumns                   LIB "ODBC352.DLL" ALIAS "OdbcColumns" (BYVAL hDbc AS DWORD, BYVAL InTableName AS STRING, ucol() AS ODBC_COLUMNS_TYPE) AS INTEGER
DECLARE FUNCTION  OdbcColumn                    LIB "ODBC352.DLL" ALIAS "OdbcColumn"  (BYVAL hDbc AS DWORD, BYVAL InTableName AS STRING, BYVAL nCol AS LONG, ucol AS ODBC_COLUMNS_TYPE) AS INTEGER

DECLARE FUNCTION  OdbcColumnsCount LIB "ODBC352.DLL" ALIAS "OdbcColumnsCount" (BYVAL hDbc AS DWORD, BYVAL InTableName AS STRING) AS WORD
DECLARE FUNCTION  OdbcDataSources LIB "ODBC352.DLL" ALIAS "OdbcDataSources" (BYVAL hEnv AS DWORD, BYVAL wDirection AS WORD, ds AS ODBC_DATASOURCES_TYPE) AS INTEGER
DECLARE FUNCTION  OdbcGetTypeInfo LIB "ODBC352.DLL" ALIAS "OdbcGetTypeInfo" (BYVAL hDbc AS DWORD, iInDataType AS INTEGER, ti() AS ODBC_TYPEINFO_TYPE) AS INTEGER
DECLARE FUNCTION  OdbcGetTypeInfoCount LIB "ODBC352.DLL" ALIAS "OdbcGetTypeInfoCount" (BYVAL hDbc AS DWORD, iInDataType AS INTEGER) AS WORD
DECLARE FUNCTION  OdbcStatistics LIB "ODBC352.DLL" ALIAS "OdbcStatistics" (BYVAL hDbc AS DWORD, BYVAL InTableName AS STRING, BYVAL iUnique AS INTEGER, BYVAL iCardinality AS INTEGER, st() AS ODBC_STATISTICS_TYPE) AS INTEGER
DECLARE FUNCTION  OdbcStatisticsCount LIB "ODBC352.DLL" ALIAS "OdbcStatisticsCount" (BYVAL hDbc AS DWORD, BYVAL InTableName AS STRING, BYVAL iUnique AS INTEGER, BYVAL iCardinality AS INTEGER) AS WORD
DECLARE FUNCTION  OdbcTables LIB "ODBC352.DLL" ALIAS "OdbcTables" (BYVAL hDbc AS DWORD, BYVAL TableTypes AS STRING, tb() AS ODBC_TABLES_TYPE) AS INTEGER
DECLARE FUNCTION  OdbcTablesCount LIB "ODBC352.DLL" ALIAS "OdbcTablesCount" (BYVAL hDbc AS DWORD, BYVAL TableTypes AS STRING) AS WORD
DECLARE FUNCTION  OdbcTablePrivileges LIB "ODBC352.DLL" ALIAS "OdbcTablePrivileges" (BYVAL hDbc AS DWORD, BYVAL TableName AS STRING, tp() AS ODBC_TABLEPRIVILEGES_TYPE) AS INTEGER
DECLARE FUNCTION  OdbcTablePrivilegesCount LIB "ODBC352.DLL" ALIAS "OdbcTablePrivilegesCount" (BYVAL hDbc AS DWORD, BYVAL TableName AS STRING) AS WORD
DECLARE FUNCTION  OdbcPrimaryKeys LIB "ODBC352.DLL" ALIAS "OdbcPrimaryKeys" (BYVAL hDbc AS DWORD, BYVAL TableName AS STRING, pk() AS ODBC_PRIMARYKEYS_TYPE) AS INTEGER
DECLARE FUNCTION  OdbcPrimaryKeysCount LIB "ODBC352.DLL" ALIAS "OdbcPrimaryKeysCount" (BYVAL hDbc AS DWORD, BYVAL TableName AS STRING) AS WORD
DECLARE FUNCTION  OdbcProcedures LIB "ODBC352.DLL" ALIAS "OdbcProcedures" (BYVAL hDbc AS DWORD, BYVAL ProcName AS STRING, pr() AS ODBC_PROCEDURES_TYPE) AS INTEGER
DECLARE FUNCTION  OdbcProceduresCount LIB "ODBC352.DLL" ALIAS "OdbcProceduresCount" (BYVAL hDbc AS DWORD, BYVAL ProcName AS STRING) AS WORD
DECLARE FUNCTION  OdbcSpecialColumns LIB "ODBC352.DLL" ALIAS "OdbcSpecialColumns" (BYVAL hDbc AS DWORD, BYVAL IdType AS INTEGER, BYVAL InTableName AS STRING, BYVAL Scope AS INTEGER, BYVAL Nullable AS INTEGER, sc() AS ODBC_SPECIALCOLUMNS_TYPE) AS INTEGER
DECLARE FUNCTION  OdbcSpecialColumnsCount LIB "ODBC352.DLL" ALIAS "OdbcSpecialColumnsCount" (BYVAL hDbc AS DWORD, BYVAL IdType AS INTEGER, BYVAL InTableName AS STRING, BYVAL Scope AS INTEGER, BYVAL Nullable AS INTEGER) AS WORD
DECLARE SUB       OdbcDrivers LIB "ODBC352.DLL" ALIAS "OdbcDrivers" (BYVAL hEnv AS DWORD, BYVAL wDirection AS WORD, dv AS ODBC_DRIVERS_TYPE)
DECLARE FUNCTION  OdbcDriversCount LIB "ODBC352.DLL" ALIAS "OdbcDriversCount" (BYVAL hEnv AS DWORD) AS WORD
DECLARE FUNCTION  OdbcColumnPrivileges LIB "ODBC352.DLL" ALIAS "OdbcColumnPrivileges" (BYVAL hDbc AS DWORD, BYVAL CatalogName AS STRING, BYVAL SchemaName AS STRING, BYVAL TableName AS STRING, BYVAL ColumnName AS STRING, BYREF cp() AS ODBC_COLUMN_PRIVILEGES_TYPE) AS INTEGER
DECLARE FUNCTION  OdbcColumnPrivilegesCount LIB "ODBC352.DLL" ALIAS "OdbcColumnPrivilegesCount" (BYVAL hDbc AS DWORD, BYVAL CatalogName AS STRING, BYVAL SchemaName AS STRING, BYVAL TableName AS STRING, BYVAL ColumnName AS STRING) AS INTEGER
DECLARE FUNCTION  OdbcForeignKeys LIB "ODBC352.DLL" ALIAS "OdbcForeignKeys" (BYVAL hDbc AS DWORD, BYVAL PKCatalogName AS STRING, BYVAL PKSchemaName AS STRING, BYVAL PKTableName AS STRING, BYVAL FKCatalogName AS STRING, BYVAL FKSchemaName AS STRING, BYVAL FKTableName AS STRING, BYREF fk() AS ODBC_FOREIGN_KEYS_TYPE) AS INTEGER
DECLARE FUNCTION  OdbcForeignKeysCount LIB "ODBC352.DLL" ALIAS "OdbcForeignKeysCount" (BYVAL hDbc AS DWORD, BYVAL PKCatalogName AS STRING, BYVAL PKSchemaName AS STRING, BYVAL PKTableName AS STRING, BYVAL FKCatalogName AS STRING, BYVAL FKSchemaName AS STRING, BYVAL FKTableName AS STRING) AS INTEGER
DECLARE FUNCTION  OdbcProcedureColumns LIB "ODBC352.DLL" ALIAS "OdbcProcedureColumns" (BYVAL hDbc AS DWORD, BYVAL CatalogName AS STRING, BYVAL SchemaName AS STRING, BYVAL ProcName AS STRING, BYVAL ColumnName AS STRING, BYREF pc() AS ODBC_PROCEDURE_COLUMNS_TYPE) AS INTEGER
DECLARE FUNCTION  OdbcProcedureColumnsCount LIB "ODBC352.DLL" ALIAS "OdbcProcedureColumnsCount" (BYVAL hDbc AS DWORD, BYVAL CatalogName AS STRING, BYVAL SchemaName AS STRING, BYVAL ProcName AS STRING, BYVAL ColumnName AS STRING) AS INTEGER

' ======================================================================================================
' New functions added to version 1.1 of the library.
' ======================================================================================================

' ======================================================================================================
' Statistics
' ======================================================================================================
DECLARE FUNCTION  OdbcStatTableCardinality LIB "ODBC352.DLL" ALIAS "OdbcStatTableCardinality" (BYVAL hDbc AS DWORD, BYVAL TableName AS STRING) AS LONG
DECLARE FUNCTION  OdbcStatTableCatalogName LIB "ODBC352.DLL" ALIAS "OdbcStatTableCatalogName" (BYVAL hDbc AS DWORD, BYVAL TableName AS STRING) AS STRING
DECLARE FUNCTION  OdbcStatTablePages LIB "ODBC352.DLL" ALIAS "OdbcStatTablePages" (BYVAL hDbc AS DWORD, BYVAL TableName AS STRING) AS LONG
DECLARE FUNCTION  OdbcStatTableSchemaName LIB "ODBC352.DLL" ALIAS "OdbcStatTableSchemaName" (BYVAL hDbc AS DWORD, BYVAL TableName AS STRING) AS STRING
DECLARE FUNCTION  OdbcStatIndexAllowDuplicates LIB "ODBC352.DLL" ALIAS "OdbcStatIndexAllowDuplicates" (BYVAL hDbc AS DWORD, BYVAL TableName AS STRING, BYVAL InIndexName AS STRING) AS INTEGER
DECLARE FUNCTION  OdbcStatIndexCardinality LIB "ODBC352.DLL" ALIAS "OdbcStatIndexCardinality" (BYVAL hDbc AS DWORD, BYVAL TableName AS STRING, BYVAL InIndexName AS STRING) AS LONG
DECLARE FUNCTION  OdbcStatIndexCatalogName LIB "ODBC352.DLL" ALIAS "OdbcStatIndexCatalogName" (BYVAL hDbc AS DWORD, BYVAL TableName AS STRING, BYVAL InIndexName AS STRING) AS STRING
DECLARE FUNCTION  OdbcStatIndexColumnName LIB "ODBC352.DLL" ALIAS "OdbcStatIndexColumnName" (BYVAL hDbc AS DWORD, BYVAL TableName AS STRING, BYVAL InIndexName AS STRING) AS STRING
DECLARE FUNCTION  OdbcStatIndexColumnOrdinalPosition LIB "ODBC352.DLL" ALIAS "OdbcStatIndexColumnOrdinalPosition" (BYVAL hDbc AS DWORD, BYVAL TableName AS STRING, BYVAL InIndexName AS STRING) AS INTEGER
DECLARE FUNCTION  OdbcStatIndexFilterCondition LIB "ODBC352.DLL" ALIAS "OdbcStatIndexFilterCondition" (BYVAL hDbc AS DWORD, BYVAL TableName AS STRING, BYVAL InIndexName AS STRING) AS STRING
DECLARE FUNCTION  OdbcStatIndexPages LIB "ODBC352.DLL" ALIAS "OdbcStatIndexPages" (BYVAL hDbc AS DWORD, BYVAL TableName AS STRING, BYVAL InIndexName AS STRING) AS LONG
DECLARE FUNCTION  OdbcStatIndexQualifier LIB "ODBC352.DLL" ALIAS "OdbcStatIndexQualifier" (BYVAL hDbc AS DWORD, BYVAL TableName AS STRING, BYVAL InIndexName AS STRING) AS STRING
DECLARE FUNCTION  OdbcStatIndexSchemaName LIB "ODBC352.DLL" ALIAS "OdbcStatIndexSchemaName" (BYVAL hDbc AS DWORD, BYVAL TableName AS STRING, BYVAL InIndexName AS STRING) AS STRING
DECLARE FUNCTION  OdbcStatIndexSortSequence LIB "ODBC352.DLL" ALIAS "OdbcStatIndexSortSequence" (BYVAL hDbc AS DWORD, BYVAL TableName AS STRING, BYVAL InIndexName AS STRING) AS STRING
' ======================================================================================================

' ======================================================================================================
' Binding
' ======================================================================================================
DECLARE SUB       OdbcBindColToBit              LIB "ODBC352.DLL" ALIAS "OdbcBindColToBit"        (BYVAL hStmt AS DWORD, BYVAL ColNumber AS INTEGER, BYREF TargetValue AS INTEGER, BYREF StrLen_or_IndPtr AS LONG)
DECLARE SUB       OdbcBindColToByte             LIB "ODBC352.DLL" ALIAS "OdbcBindColToByte"       (BYVAL hStmt AS DWORD, BYVAL ColNumber AS INTEGER, BYREF TargetValue AS BYTE, BYREF StrLen_or_IndPtr AS LONG)

DECLARE SUB       OdbcBindColToNumeric          LIB "ODBC352.DLL" ALIAS "OdbcBindColToNumeric"    (BYVAL hStmt AS DWORD, BYVAL ColNumber AS INTEGER, BYREF TargetValue AS ASCIIZ, BYREF StrLen_or_IndPtr AS LONG)
DECLARE SUB       OdbcBindColToDecimal          LIB "ODBC352.DLL" ALIAS "OdbcBindColToDecimal"    (BYVAL hStmt AS DWORD, BYVAL ColNumber AS INTEGER, BYREF TargetValue AS ASCIIZ, BYREF StrLen_or_IndPtr AS LONG)

DECLARE SUB       OdbcBindColToString           LIB "ODBC352.DLL" ALIAS "OdbcBindColToString"     (BYVAL hStmt AS DWORD, BYVAL ColNumber AS INTEGER, BYREF TargetValue AS ASCIIZ, BYVAL BufferLenght AS LONG, BYREF StrLen_or_IndPtr AS LONG)
DECLARE SUB       OdbcBindColToBinary           LIB "ODBC352.DLL" ALIAS "OdbcBindColToBinary"     (BYVAL hStmt AS DWORD, BYVAL ColNumber AS INTEGER, BYVAL TargetValue AS DWORD, BYVAL BufferLenght AS LONG, BYREF StrLen_or_IndPtr AS LONG)
DECLARE SUB       OdbcBindColToInteger          LIB "ODBC352.DLL" ALIAS "OdbcBindColToInteger"    (BYVAL hStmt AS DWORD, BYVAL ColNumber AS INTEGER, BYREF TargetValue AS INTEGER, BYREF StrLen_or_IndPtr AS LONG)
DECLARE SUB       OdbcBindColToWord             LIB "ODBC352.DLL" ALIAS "OdbcBindColToWord"       (BYVAL hStmt AS DWORD, BYVAL ColNumber AS INTEGER, BYREF TargetValue AS WORD, BYREF StrLen_or_IndPtr AS LONG)
DECLARE SUB       OdbcBindColToLong             LIB "ODBC352.DLL" ALIAS "OdbcBindColToLong"       (BYVAL hStmt AS DWORD, BYVAL ColNumber AS INTEGER, BYREF TargetValue AS LONG, BYREF StrLen_or_IndPtr AS LONG)
DECLARE SUB       OdbcBindColToDword            LIB "ODBC352.DLL" ALIAS "OdbcBindColToDword"      (BYVAL hStmt AS DWORD, BYVAL ColNumber AS INTEGER, BYREF TargetValue AS DWORD, BYREF StrLen_or_IndPtr AS LONG)
DECLARE SUB       OdbcBindColToSingle           LIB "ODBC352.DLL" ALIAS "OdbcBindColToSingle"     (BYVAL hStmt AS DWORD, BYVAL ColNumber AS INTEGER, BYREF TargetValue AS SINGLE, BYREF StrLen_or_IndPtr AS LONG)
DECLARE SUB       OdbcBindColToDouble           LIB "ODBC352.DLL" ALIAS "OdbcBindColToDouble"     (BYVAL hStmt AS DWORD, BYVAL ColNumber AS INTEGER, BYREF TargetValue AS DOUBLE, BYREF StrLen_or_IndPtr AS LONG)
DECLARE SUB       OdbcBindColToQuad             LIB "ODBC352.DLL" ALIAS "OdbcBindColToQuad"       (BYVAL hStmt AS DWORD, BYVAL ColNumber AS INTEGER, BYREF TargetValue AS QUAD, BYREF StrLen_or_IndPtr AS LONG)
DECLARE SUB       OdbcBindColToCurrency         LIB "ODBC352.DLL" ALIAS "OdbcBindColToCurrency"   (BYVAL hStmt AS DWORD, BYVAL ColNumber AS INTEGER, BYREF TargetValue AS DOUBLE, BYREF StrLen_or_IndPtr AS LONG)
DECLARE SUB       OdbcBindColToDate             LIB "ODBC352.DLL" ALIAS "OdbcBindColToDate"       (BYVAL hStmt AS DWORD, BYVAL ColNumber AS INTEGER, BYREF TargetValue AS DATE_STRUCT, BYREF StrLen_or_IndPtr AS LONG)
DECLARE SUB       OdbcBindColToTime             LIB "ODBC352.DLL" ALIAS "OdbcBindColToTime"       (BYVAL hStmt AS DWORD, BYVAL ColNumber AS INTEGER, BYREF TargetValue AS TIME_STRUCT, BYREF StrLen_or_IndPtr AS LONG)
DECLARE SUB       OdbcBindColToTimeStamp        LIB "ODBC352.DLL" ALIAS "OdbcBindColToTimeStamp"  (BYVAL hStmt AS DWORD, BYVAL ColNumber AS INTEGER, BYREF TargetValue AS TIMESTAMP_STRUCT, BYREF StrLen_or_IndPtr AS LONG)
' ======================================================================================================

' ======================================================================================================
' Other functions
' ======================================================================================================
DECLARE FUNCTION  OdbcColIsNull LIB "ODBC352.DLL" ALIAS "OdbcColIsNull" (BYVAL hStmt AS DWORD, BYVAL iCol AS INTEGER) AS INTEGER
' ======================================================================================================


'#ENDIF
 