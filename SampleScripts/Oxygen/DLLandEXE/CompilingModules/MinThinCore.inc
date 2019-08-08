
'     ####
'   ########
'  ##     ###
' ##       ###  ####
' ##       ##      ##
' ###     ###      ##
'  ########      ##
'    ####      ##
'              ######


  '--------------------------------------
  ' FOR THE FULL FUNCTIONALITY THIS CAN 
  ' BE FOUND IN THE THINBASIC SDK FOLDER.
  ' THE PB VERSION IS USED.
  '======================================
  '
  '
  'include `..\..\thincore.inc` 

  


  library "thincore.dll"

  'SUBSET OF THINCORE

  %thinBasic_ReturnNone          0   'Used in thinBasic_LoadSymbol to define a sub
  %thinBasic_ReturnNumber       20   'Used in thinBasic_LoadSymbol to define a function returning a EXT number
  %thinBasic_ReturnString       30   'Used in thinBasic_LoadSymbol to define a function returning a string
  %thinBasic_ReturnCodeByte      1
  %thinBasic_ReturnCodeInteger   2
  %thinBasic_ReturnCodeWord      3
  %thinBasic_ReturnCodeDWord     4
  %thinBasic_ReturnCodeLong      5
  %thinBasic_ReturnCodeQuad      6
  %thinBasic_ReturnCodeSingle    7 
  %thinBasic_ReturnCodeDouble    8
  %thinBasic_ReturnCodeCurrency  9
  %thinBasic_ReturnCodeExt      10

  % thinBasic_ForceOverWrite    1    'Used in thinBasic_LoadSymbol to force symbol over writing


  declare thinBasic_LoadSymbol        (string SymbolName, sys ReturnCode,FunctionOrSubPointer,
                                      optional ForceOverWrite) as sys
  declare thinBasic_Class_Add         (string cn,sys m) as sys
  declare thinBasic_Class_AddMethod   (sys pt,string na,sys rt, sys ad) as sys
  declare thinBasic_Class_AddProperty (sys pt,string na,sys rt, sys ad) as sys

  declare thinBasic_AddUdt ( string sUDT_Code) as sys
  declare thinBasic_DeclareFunction( string sDeclare, sys pFun) as sys

  declare thinBasic_ParseNumber                 (Result as ext)
  declare thinBasic_ParseLong                   (Result as long)
  declare thinBasic_ParseString                 (Result as string) As ext

  declare thinBasic_CheckOpenParens_Optional    () as sys
  declare thinBasic_CheckCloseParens_Mandatory  () as sys
  declare thinBasic_CheckComma_Optional         () as sys


  declare thinBasic_CheckOpenParens             (optional long HideError,AutoPutBack) as sys
  declare thinBasic_CheckOpenParens_Mandatory   () as sys
  declare thinBasic_CheckOpenParens_Optional    () as sys

  declare thinBasic_CheckCloseParens            (optional long HideError,AutoPutBack) as sys
  declare thinBasic_CheckCloseParens_Mandatory  ()  as sys
  declare thinBasic_CheckCloseParens_Optional   () as sys

  declare thinBasic_CheckComma                  (optional long HideError, AutoPutBack) as sys
  declare thinBasic_CheckComma_Mandatory        () as sys
  declare thinBasic_CheckComma_Optional         () as sys

  declare thinBasic_CheckSemicolon_Mandatory    () as sys
  declare thinBasic_CheckSemicolon_Optional     () as sys

  declare thinBasic_CheckPoint_Mandatory        () as sys
  declare thinBasic_CheckPoint_Optional         () as sys

  declare thinBasic_CheckEqual_Mandatory        () as sys
  declare thinBasic_CheckEqual_Optional         () as sys

  declare thinBasic_CheckPlus_Optional          () as sys
  declare thinBasic_CheckMinus_Optional         () as sys
  declare thinBasic_CheckMult_Optional          () as sys
  declare thinBasic_CheckDiv_Optional           () as sys

  declare thinBasic_CheckEOL_Optional () as sys

  declare thinBasic_GetUnknownToken (optional sys AutoPutBack) as string


  declare Function  thinBasic_CheckEqualType_Mandatory () as sys
    %Equal_EQ             1520   ' =
    %Equal_PLUSEQUAL      1521   ' +=
    %Equal_MINUSEQUAL     1522   ' -=
    %Equal_MULTIPLYEQUAL  1523   ' *=
    %Equal_DIVIDEEQUAL    1524   ' /=
    %Equal_IDIVIDEEQUAL   1525   ' \=
    %Equal_CONCEQUAL      1526   ' &=
    %Equal_POINTEQUAL     1527   ' .=

  %Class_Action_None          0
  %Class_Action_Get           1
  %Class_Action_Set           2
  
  %Class_Action_Constructor   100
  %Class_Action_Destructor    110



  Declare thinBasic_RunTimeError (long ErrorCode,optional string AdditionalInfo ) as sys

  ' RunTime Errors Codes
  '=====================

    %ERR__PARENS                              1
    %ERR__NOEXP                               2
    %ERR__DIV_ZERO                            3
    %ERR__EQUAL_EXP                           4
    %ERR__NOT_VAR                             5
    %ERR__LAB_TAB_FULL                        6
    %ERR__DUP_LAB                             7
    %ERR__UNDEF_LAB                           8
    %ERR__THEN_EXPECTED                       9
    %ERR__TO_EXPECTED                        10
    %ERR__TOO_MANY_FOR                       11
    %ERR__NEXT_WITHOUT_FOR                   12
    %ERR__MISSING_SEMICOLON                  13

    %ERR__MISS_QUOTE                         15
    %ERR__BAD_FILE                           16
    %ERR__STR_EXPECTED                       17
    %ERR__UNKNOWN_KEYWORD                    18
    %ERR__MISSING_OPENPARENS                 19
    %ERR__MISSING_CLOSEPARENS                20
    %ERR__MISSING_COMMA                      21

    %ERR__COMMAND_UNKNOWN_RETURNED_PARAMETER 25
    %ERR__PRIMITIVE_STR                      26
    %ERR__PRIMITIVE_NUM                      27
    %ERR__PRINT_ERROR                        28
    %ERR__PRINT_ERROR_NOENDOFLINE            29
    %ERR__VARIABLE_NOT_DEFINED               30
    %ERR__ATOM_TOKEN_TYPE_NUMERIC            31
    %ERR__IF_WITHOUT_ENDIF                   32
    %ERR__IF_ENDIF_WITHOUT_IF                33
    %ERR__TOO_MANY_WHILE                     34
    %ERR__WHILE_WITHOUT_WEND                 35
    %ERR__DIM_TYPE_NOT_DEFINED               36
    %ERR__EXIT_NO_KEY_FOUND                  37
    %ERR__NO_END_FUNCTION_FOUND              38
    %ERR__FUNCTION_NAME_DUPLICATE            39
    %ERR__FUNCTION_NAME_IS_KEY               40
    %ERR__FUNCTION_NAME_IS_VAR               41
    %ERR__FUNCTION_NAME_IS_UDT               42
  
    %ERR__DIM_MISSING_AS                     44
    %ERR__UNDEFINED_TOKEN                    45
    %ERR__UNSUPPORTED_CHAR                   46

    %ERR__FUNCTION_DECLARE_MISSING_AS        47
    %ERR__DECLARE_FUNCTION_OR_SUB_EXPECTED   48
  
    %ERR__DOLOOP_WRONG_CONDITION             49
    
  
    %ERR__MISSING_ALIAS                      50
    %ERR__MISSING_LIB                        51
    %ERR__UNDEFINED_VAR_TYPE                 52
    %ERR__PARAMETER_BYREF_INCORRECT_PTR      53
  
    %ERR__LOOP_EXPECTED_WHILE_OR_UNTIL       55
  
    %ERR__END_FUNCTION_FOUND                 59
  
    %ERR__ITERATE_NO_KEY_FOUND               60
  
    %ERR__WITH_ENDWITH_ERROR                 64
  
    %ERR__VARIABLE_NOT_DIMENSIONED           70
    %ERR__VARIABLE_ISNOT_ARRAY               71
    %ERR__VARIABLE_MUSTBE_STRING_TYPE        72
    %ERR__REDIM_NEW_TYPE_NOT_SUPPORTED       73
    %ERR__VARIABLE_MUSTBE_UDT_TYPE           74
  
    %ERR__KEYWORD_NOT_EXPECTED               75
    %ERR__TOKEN_NOT_EXPECTED                 76
  
    %ERR__INCLUDE_FILE_NOT_FOUND             80
  
    %ERR__FUNCTION_NOT_SUPPORTED             90
  
    %ERR__ARRAY_FUNCTION_NOT_SUPPORTED       91
  
    %ERR__UDT_ELEMENT_NOT_FOUND             100
    %ERR__UDT_EXPECTED                      101
    %ERR__UDT_EQU_OR_ELEMENT_EXPECTED       102
  
    %ERR__ASSIGNMENT_NOT_SUPPORTED          110
  
    %ERR__RELATIONAL_EXPECTED               115
  
    %ERR__API_LIB_NOT_FOUND                 120
    %ERR__API_FUNCTION_NOT_FOUND_IN_LIB     121
    %ERR__API_GENERAL_ADDRESS_NOT_PRESENT   122
  
    %ERR__CALL_NOTSUPPORTEDSTATEMENT        130
    %ERR__CALL_FUNCTIONNOTFOUND             131
  
    %ERR__EQUATE_ALREADY_DEFINED            135
    
    %ERR__VARIABLE_NAME_DUPLICATE_GLOBAL    142
    %ERR__VARIABLE_NAME_DUPLICATE_FUNCTION  144
    %ERR__VARIABLE_NAME_DUPLICATE_LOCAL     145
    %ERR__VARIABLE_NAME_DUPLICATE           146
  
    %ERR__FOR_StepShouldBeNegative          150
    %ERR__FOR_StepShouldBePositive          151
    %ERR__FOR_ExpectedAVariable             152
    %ERR__FOR_StepIsZero                    153
  
    %ERR__ALIAS_CommandNameExpected         160
    %ERR__ALIAS_AsExpected                  161
    %ERR__ALIAS_UndefNotUndef               162
  
    %ERR__TYPE_MISSING_END_UNION            169
    %ERR__TYPE_MISSING_END_TYPE             170
    %ERR__TYPE_TYPE_NOT_DEFINED             171&
    %ERR__TYPE_MISSING_AS                   172
    %ERR__TYPE_NAME_MUSTBE_UNDEFINED        173
    %ERR__TYPE_ARRAY_MUSTBE_DIMENSIONED     174
    %ERR__TYPE_STRINGS_MUST_HAVE_SIZE       175
    %ERR__TYPE_ELEMENT_ALREADY_PRESENT      176
    %ERR__TYPE_ELEMENT_ALREADY_PRESENT_INHERIT  177
  
    %ERR__NO_END_ROWTEXT_FOUND              180
  
    %ERR__BEGIN_BLOCK_UNSUPORTED            190
    %ERR__BEGIN_CONST_MISSING_END           191
  
    %ERR__FUNCTION_MISSING_AS               246
    %ERR__REGEXPR_MISSING_TO                247
    %ERR__REGEXPR_MISSING_IN                248
    %ERR__SELECT_WITHOUT_ENDSELECT          249
    %ERR__DUPLICATE_SYMBOL                  250
    %ERR__INVALIDNUMERICCHAR                251
    %ERR__INVALIDDELIMITER                  252
    %ERR__INVALIDDATATYPE                   253
    %ERR__VARIABLE_EXPECTED                 254
    %ERR__VARIABLE_VARIANT_EXPECTED         255
    
    %ERR__SELECT_MISSING_CASE               270
    %ERR__SELECT_ERROR_KINDOF_OPERATION     271
  
    %ERR__APICALL_REF_EXPECTED              300
  
    %ERR__ARRAY_OUT_OF_BOUND                400
  
    %ERR__MODULE_SPECIFIC                   500
    
    %ERR__PREPARSER_DirectiveNotSupported   800
  
    %ERR__PREPARSER_ScriptVersionRequest    820
  
    %ERR__INTERNAL_RETURNMAINTYPE           900
  
    %ERR__INTERNAL_DECRIPTION               910
    
    %ERR__INTERNAL_RETURNNONE_NOCODEPTR     921
    %ERR__INTERNAL_RETURNNUMBER_NOCODEPTR   922
    %ERR__INTERNAL_RETURNSTRING_NOCODEPTR   923
    
    %ERR__TRACE_STOP_BY_USER                1100
  
    %ERR__OBFUSCATION_FILENOTVALID          1200
  
    %ERR__COM_GENERIC                       3000

library ""

