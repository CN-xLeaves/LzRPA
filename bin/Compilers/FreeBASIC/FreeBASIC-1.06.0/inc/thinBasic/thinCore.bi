'  =============================================================================
'  File NAME   : thinCore.bi
'  Author      : Eros Olmi
'  Version     : 
'  Description : thinBasic external library interface definitions for FreeBasic
'  Web site    : http://www.thinbasic.com
'  =============================================================================
'  COPYRIGHT AND PERMISSION NOTICE
'  =============================================================================
'  Copyright (c) 2003 - 2007, Eros Olmi, <eros.olmi@thinbasic.com>
'   
'  All rights reserved.
'   
'  Permission to use this software is granted only for the purpose to develop
'  thinBasic language modules both for commercial or non commercial purpose.
'  In any case the above copyright notice and this permission notice must appear
'  in all copies.
'   
'  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
'  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
'  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF THIRD PARTY RIGHTS.
'  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
'  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
'  OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
'  USE OR OTHER DEALINGS IN THE SOFTWARE.
'
'  =============================================================================
'  Edit History [+]Add, [-]Fixed, [*]Changed, [N]Note
'  _____________________________________________________________________________
'  Date_______Type_Note_________________________________________________________
'  2007.09.20      First official release into Module SDK forum
'  
'  =============================================================================


	#Inclib "thinCore"

	#include once "windows.bi"
	#Include once "win/ole2.bi"

  '---Include file to use thinString to simulate ThinBasic ole32 BSTR strings in FreeBasic code
  #include once "thinBasic/thinString.bi"

	Const TB_TRUE                     AS long = 1
	const TB_FALSE                    As Long = 0

	Const VarMainType_IsNumber       As Long = 20
	Const VarMainType_IsString       As Long = 30
	Const VarMainType_IsAsciiZ       As Long = 25
	Const VarMainType_IsVariant      As Long = 50

	Const VarSubType_Byte            As Long =  1
	Const VarSubType_Integer         As Long =  2
	Const VarSubType_Word            As Long =  3
	Const VarSubType_DWord           As Long =  4
	Const VarSubType_Long            As Long =  5
	Const VarSubType_Quad            As Long =  6
	Const VarSubType_Single          As Long =  7
	Const VarSubType_Double          As Long =  8
	Const VarSubType_Currency        As Long =  9
	Const VarSubType_Ext             As Long = 10
	Const VarSubType_Variant         As Long = 50

	'------------------------------------------------------------------------------
	'	Return Types from functions/Subs
	'------------------------------------------------------------------------------
	Const thinBasic_ReturnNone           As Long =  0   'Used in thinBasic_LoadSymbol to define a sub
	Const thinBasic_ReturnNumber         As Long = 20   'Used in thinBasic_LoadSymbol to define a function returning a EXT number
	Const thinBasic_ReturnString         As Long = 30   'Used in thinBasic_LoadSymbol to define a function returning a string

	Const thinBasic_ReturnCodeByte       As Long =  1
	Const thinBasic_ReturnCodeInteger    As Long =  2
	Const thinBasic_ReturnCodeWord       As Long =  3
	Const thinBasic_ReturnCodeDWord      As Long =  4
	Const thinBasic_ReturnCodeLong       As Long =  5
	Const thinBasic_ReturnCodeQuad       As Long =  6
	Const thinBasic_ReturnCodeSingle     As Long =  7 
	Const thinBasic_ReturnCodeDouble     As Long =  8
	Const thinBasic_ReturnCodeCurrency   As Long =  9
	Const thinBasic_ReturnCodeExt        As Long = 10
	Const thinBasic_ReturnCodeString     As Long = 30
	'------------------------------------------------------------------------------
  
	'------------------------------------------------------------------------------
	'	Global declares
	'------------------------------------------------------------------------------
	Const thinBasic_ForceOverWrite 		AS Long = 1   'Used in thinBasic_LoadSymbol to force symbol over writing


	'------------------------------------------------------------------------------
	'Types
	'------------------------------------------------------------------------------


        type ext As Double
        '    dbl as double
        '    xtn as word
        'end type

        type extended As Double
        '    dbl as double
        '    xtn as word
        'end type
 

  ' dim p as any ptr
  ' dim myvar as extended
  '
  ' convert from double to extended
  ' p=varptr(myVar)
  ' asm .byte &hdd, &h00, &hdb,&h38
  ' 
  ' convert from extended to double
  ' p=varptr(myVar)
  ' asm .byte &hdb, &h28, &hdd,&h18

  
  '----------------------------------------------------------------------------
  'thinBasic_LoadSymbol
  '----------------------------------------------------------------------------
  ' Description
  '   Creates e new keyword inside interpreter.
  '   You define your own Function or Sub inside your program. Then call
  '   thinBasic_LoadSymbol to add a new keyword connected to your new function/sub
  '
  ' Parameters
  '   SymbolName  : Name you want to give to your sub or function inside the
  '                 interpreter. It is the new keyword name.
  '
  '   ReturnCode  : specify what kind of var your function returns
  '                 Use predefined constants:
  '                 %thinBasic_ReturnNumber
  '                 %thinBasic_ReturnString
  '                 %thinBasic_ReturnNone
  '                 If SymbolName will end with "$" char, ReturnCode will
  '                 be forced to %thinBasic_ReturnString
  '                 Note: if you pass a pointer to a SUB routine and ReturnCode
  '                       is different from %thinBasic_ReturnNone, a GPF will be
  '                       fired by the Operating System.
  '                 Note: if ReturnCode <= 0 then %thinBasic_ReturnNone will be
  '                       assumed 
  '
  '   FunctionOrSubPointer:
  '                 DWORD returned by CODEPTR function pointing to the function
  '                 that will be called when SymbolName keyword will be encountered
  '                 during script execution
  '
  '   ForceOverWrite:
  '                 If different from 0 it means that even if SymbolName
  '                 already exists as a keyword, you want to overwrite it with
  '                 a new one.
  '                 For example, if you want to overwrite behave of MID$
  '                 creating your own MID$ function, set this parameter to a value
  '                 > 0 like in this example:
  '                 thinBasic_LoadSymbol("MID$", %thinBasic_ReturnString, CODEPTR(MyMid), 1)
  '
  ' Possible Return Code
  '   >0 = no error, return the associated SymbolName ID
  '   -1 = empty SymbolName
  '   -2 = duplicated SymbolName and no ForceOverWrite flag
  '   -3 = invalid sub/function pointer
  '   -4 = SymbolName contains invalid char(s)
  '
  ' Example
  '   thinBasic_LoadSymbol "MyNewFunction", %thinBasic_ReturnNumber, CODEPTR(MyFunc)
  '----------------------------------------------------------------------------
	DECLARE Function thinBasic_LoadSymbol														_
							ALIAS "thinBasic_LoadSymbol_FB"										_
								(																			_
									byval SymbolName							As ZString Ptr	, 	_
									BYVAL ReturnCode							AS Long			, 	_
									BYVAL FunctionOrSubPointer				As Any Ptr		, 	_
									BYVAL ForceOverWrite						As Long				_
								) As Long

   '----------------------------------------------------------------------------
   'thinBasic_VariableExists
   '----------------------------------------------------------------------------
   ' Returns true/false depending if the given name is a variable or not
   '----------------------------------------------------------------------------
   DECLARE FUNCTION  thinBasic_VariableExists                      _
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_VariableExists"        _
                           (                                       _
                             BYVAL vName       AS BSTR           _
                           ) AS LONG
 




'    type PBStringDescriptor
'        bstr  as BSTR
'        other as long
'    end type 


   '----------------------------------------------------------------------------
   'thinBasic_VariableGetInfo
   '----------------------------------------------------------------------------
   ' Returns additional variable info giving variable name.
   ' ATTENTION: pass variable as reference. Function will populate
   '            with relevant information
   ' Function will return a pointer to variable data that can be used in other
   ' situations.
   '----------------------------------------------------------------------------
   DECLARE FUNCTION  thinBasic_VariableGetInfo                     _
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_VariableGetInfo"       _
                           (                                       _
                             Byval SearchKey   AS BSTR, _
                             byref pMainType   As Long        , _       '---ATTENTION: parameter passed BYREF will return info
                             byref pSubType    As Long        , _       '---ATTENTION: parameter passed BYREF will return info
                             byref pIsArray    As Long          _       '---ATTENTION: parameter passed BYREF will return info
                           ) As long
                           
 
'


  '----------------------------------------------------------------------------
  'thinBasic_VariableGetInfoEX
  ' 09:55 16 Mar 2008
  '----------------------------------------------------------------------------
  ' Returns additional variable info giving variable name.
  ' ATTENTION: pass variable as reference. Function will populate
  '            with relevant information
  ' Function returns a pointer to internal thinBAsic variable structure data
  ' that can be used in other situations.
  '----------------------------------------------------------------------------
  declare function  thinBasic_VariableGetInfoEX                   _
                          lib "thinCore.DLL"                      _
                          alias "thinBasic_VariableGetInfoEX"     _
                          (                                       _
                            byval SearchKey   as BSTR           , _
                            byref pMainType   as long        , _   '---ATTENTION: parameter passed BYREF will return info
                            byref pSubType    as long        , _   '---ATTENTION: parameter passed BYREF will return info
                            byref pIsArray    as long        , _   '---ATTENTION: parameter passed BYREF will return info
                            byref pDataPtr    as long        , _   '---ATTENTION: parameter passed BYREF will return info
                            byref pnElements  as long        , _   '---ATTENTION: parameter passed BYREF will return info
                            ByVal WhichLevel  As Long = 0      _   '---Optional parameter
                          ) as long

   '---Equates for variable Main Type
     Const MainType_IsNumber        As Long = 20
     Const MainType_String          As Long = 30
     Const MainType_Variant         As Long = 50
     Const MainType_UDT             As Long = 60
   '---Equates for variable Sub Type
     Const SubType_Byte             As Long =  1
     Const SubType_Integer          As Long =  2
     Const SubType_Word             As Long =  3
     Const SubType_DWord            As Long =  4
     Const SubType_Long             As Long =  5
     Const SubType_Quad             As Long =  6
     Const SubType_Single           As Long =  7
     Const SubType_Double           As Long =  8
     Const SubType_Currency         As Long =  9
     Const SubType_Ext              As Long = 10
     Const SubType_AsciiZ           As Long = 25 
  

   '----------------------------------------------------------------------------
   'thinBasic_VariableIsArray
   '----------------------------------------------------------------------------
   ' Returns true/false depending if given name is an array
   '----------------------------------------------------------------------------
   DECLARE FUNCTION  thinBasic_VariableIsArray                     _
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_VariableIsArray"       _
                           (                                       _
                             BYVAL vName       AS BSTR             _
                           ) AS LONG
 
   '----------------------------------------------------------------------------
   'thinBasic_VariableRedim
   '----------------------------------------------------------------------------
   ' Redim a variable giving variable ptr
   '----------------------------------------------------------------------------
   DECLARE FUNCTION  thinBasic_VariableRedim                       _
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_VariableRedim"         _
                           (                                       _
                             BYVAL pVar AS LONG,                   _
                             BYVAL lPreserve AS LONG,              _
                             BYVAL VarDim1 AS LONG,                _
                             BYVAL VarDim2 AS LONG,                _
                             BYVAL VarDim3 AS LONG                 _
                           ) AS LONG
 
   '----------------------------------------------------------------------------
   'thinBasic_ArrayGetElements
   '----------------------------------------------------------------------------
   ' Returns total number of elements inside an array giving the array name
   ' ATTENTION: this function works on single or multi dimensions arrays
   '----------------------------------------------------------------------------
   DECLARE FUNCTION  thinBasic_ArrayGetElements                    _
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_ArrayGetElements"      _
                           (                                       _
                             BYVAL vName       AS BSTR             _
                           ) AS LONG
 
   '----------------------------------------------------------------------------
   'thinBasic_ArrayGetPtr
   '----------------------------------------------------------------------------
   ' Returns the data structure pointer of an array giving its name
   '----------------------------------------------------------------------------
   DECLARE FUNCTION  thinBasic_ArrayGetPtr                         _
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_ArrayGetPtr"           _
                           (                                       _
                             BYVAL vName       AS BSTR             _
                           ) AS LONG
 
   '----------------------------------------------------------------------------
   'thinBasic_ArrayGetInfo
   '----------------------------------------------------------------------------
   ' Returns information on an array passing array pointer returned by thinBasic_ArrayGetPtr
   '----------------------------------------------------------------------------
   DECLARE FUNCTION  thinBasic_ArrayGetInfo                        _
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_ArrayGetInfo"          _
                           (                                       _
                             BYVAL ArrayPtr    AS LONG,            _
                             BYVAL InfoType    AS LONG             _
                           ) AS LONG
 
'  '---Equates for InfoType
     Const Array_ElementsCount        As Long = 1     'Total number of elements in the array
     Const Array_ElementSize          As Long = 2     'The size of the single element (for example an array of LONGs will return 4)
     Const Array_Dimensions           As Long = 3     'Number of dimensions (from 1 to 3)
     Const Array_Size                 As Long = 4     'Memory size allocated for the array. This will not compute the memory needed for strings
     Const Array_ElementsType         As Long = 10    'Type of elements strored into the array. See equates for thinBasic_VariableGetInfo

   '----------------------------------------------------------------------------
   'thinBasic_AddEquate
   '----------------------------------------------------------------------------
   ' Add a new equate (constant)
   '----------------------------------------------------------------------------
'check optional

   DECLARE FUNCTION  thinBasic_AddEquate                           _
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_AddEquate"             _
                           (                                       _
                             BYVAL vName       AS BSTR,            _
                             BYVAL lValString  AS BSTR,            _
                             BYVAL lValNumber  AS EXT,             _
                            _ 'OPTIONAL                            _
                             BYVAL ForceType   AS LONG             _      
                           ) AS LONG
 
   '----------------------------------------------------------------------------
   'thinBasic_AddVariable
   '----------------------------------------------------------------------------
   ' Add a new variable to current stack level
   '----------------------------------------------------------------------------
   DECLARE FUNCTION  thinBasic_AddVariable                         _
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_AddVariable"           _
                           (                                       _
                             BYVAL vName       AS BSTR,            _
                             BYVAL lValString  AS BSTR,            _
                             BYVAL lValNumber  AS EXT   ,          _
                             BYVAL ForceType   AS LONG             _      
                           ) AS LONG

   '----------------------------------------------------------------------------
   'thinBasic_ChangeVariableNumber
   '----------------------------------------------------------------------------
   ' Change the value of a numeric variable giving its name a the new value
   '----------------------------------------------------------------------------
   DECLARE FUNCTION  thinBasic_ChangeVariableNumber                _
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_ChangeVariableNumber"  _
                           (                                       _
                             BYVAL vName       AS BSTR,            _
                             BYVAL lValNumber  AS EXT              _
                           ) AS LONG

   '----------------------------------------------------------------------------
   'thinBasic_ChangeVariableString
   '----------------------------------------------------------------------------
   ' Change the value of a string variable giving its name a the new value
   '----------------------------------------------------------------------------
   DECLARE FUNCTION  thinBasic_ChangeVariableString                _
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_ChangeVariableString"  _
                           (                                       _
                             BYVAL vName       AS BSTR,            _
                             BYVAL lValNumber  AS BSTR             _
                           ) AS LONG

	'----------------------------------------------------------------------------
	'thinBasic_GetToken
	'----------------------------------------------------------------------------
	' Returns the next token as token ID.
	'----------------------------------------------------------------------------
    DECLARE FUNCTION  thinBasic_GetToken									_
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_GetToken"					_
                           (								_
                               BYVAL AutoPutBack AS Long				_
                           ) AS LONG

   '----------------------------------------------------------------------------
   'thinBasic_GetToken
   '----------------------------------------------------------------------------
   ' Returns the next token as string.
   '----------------------------------------------------------------------------
   DECLARE FUNCTION  thinBasic_GetTokenName                        _
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_GetTokenName"          _
                           (                                       _
                             _ ' OPTIONAL
                             BYVAL AutoPutBack AS LONG    _
                           ) AS BSTR

   '----------------------------------------------------------------------------
   'thinBasic_GetTokenID
   '----------------------------------------------------------------------------
   ' Return internal engine unique ID giving the token name
   '----------------------------------------------------------------------------
   DECLARE FUNCTION  thinBasic_GetTokenID                          _
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_GetTokenID"            _
                           (                                       _
                             BYVAL TokenName AS BSTR               _
                           ) AS LONG
 
 
   '----------------------------------------------------------------------------
   'thinBasic_TokenGetCurrentID
   '----------------------------------------------------------------------------
   ' Return current token ID
   '----------------------------------------------------------------------------
   DECLARE FUNCTION  thinBasic_TokenGetCurrentID                   _
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_TokenGetCurrentID"     _
                           () AS LONG
 
   '----------------------------------------------------------------------------
   'thinBasic_PutBack
   '----------------------------------------------------------------------------
   ' Put back into parsing stack the last parsed token
   '----------------------------------------------------------------------------
   DECLARE FUNCTION thinBasic_Putback                              _
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_PutBack"               _
                           (                                       _
                             _ 'OPTIONAL
                             BYVAL llPtr AS LONG                   _
                           ) AS LONG

   '----------------------------------------------------------------------------
   'thinBasic_FunctionExists
   '----------------------------------------------------------------------------
   '----------------------------------------------------------------------------
   DECLARE FUNCTION  thinBasic_FunctionExists                      _
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_FunctionExists"        _
                           (                                       _
                             BYVAL fName       AS BSTR             _
                           ) AS LONG
 
 
'typo?
   '----------------------------------------------------------------------------
   'thinBasic_GetKeywordSpeficic
   '----------------------------------------------------------------------------
   ' Instruct parser to get next token, test if it a keyword and if yes,
   ' check if it is one of the possible keywords passed. If not, a RT-Error
   ' will be generated
   '----------------------------------------------------------------------------
   DECLARE FUNCTION  thinBasic_GetKeywordSpeficic                  _
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_GetKeywordSpeficic"    _
                           (                                       _
                                       BYVAL HideError   AS LONG , _
                                       BYVAL AutoPutBack AS LONG , _
                                       BYVAL lKey1   AS LONG     , _
                                       _' OPTIONAL
                                       BYVAL lKey2   AS LONG     , _
                                       BYVAL lKey3   AS LONG     , _
                                       BYVAL lKey4   AS LONG     , _
                                       BYVAL lKey5   AS LONG     , _
                                       BYVAL lKey6   AS LONG     , _
                                       BYVAL lKey7   AS LONG     , _
                                       BYVAL lKey8   AS LONG     , _
                                       BYVAL lKey9   AS LONG     , _
                                       BYVAL lKey10  AS LONG     , _
                                       BYVAL lKey11  AS LONG     , _
                                       BYVAL lKey12  AS LONG     , _
                                       BYVAL lKey13  AS LONG     , _
                                       BYVAL lKey14  AS LONG     , _
                                       BYVAL lKey15  AS LONG       _
                           ) AS LONG

   '----------------------------------------------------------------------------
   'thinBasic_VariableParse
   '----------------------------------------------------------------------------
   ' Instruct parser to get next token, check if variable, check if array and
   ' return all info needed to subsequent change variable value
   '----------------------------------------------------------------------------
   DECLARE FUNCTION  thinBasic_VariableParse                       _
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_VariableParse"         _
                           (                                       _
                             BYVAL VariablePtr     AS LONG PTR   , _     '---ATTENTION: parameter passed BYREF will return info
                             BYVAL VariableAbsPos  AS LONG PTR     _     '---ATTENTION: parameter passed BYREF will return info
                           ) AS LONG
 
   '----------------------------------------------------------------------------
   'thinBasic_VariableParsePtr
   '----------------------------------------------------------------------------
   ' Instruct parser to get next token, check if variable
   ' return its pointer
   '----------------------------------------------------------------------------
 '  DECLARE FUNCTION  thinBasic_VariableParsePtr                    _
 '                          LIB "thinCore.DLL"                      _
 '                          ALIAS "thinBasic_VariableParsePtr"      _
 '                          (                                       _
 '                            BYREF VariableName    AS STRING     , _     '---ATTENTION: parameter passed BYREF will return info
 '                            BYREF VariablePtr     AS LONG         _     '---ATTENTION: parameter passed BYREF will return info
 '                          ) AS LONG
   DECLARE FUNCTION  thinBasic_VariableParsePtr                    _
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_VariableParsePtr"      _
                           (                                       _
                             BYVAL VariablePtr     AS LONG PTR     _     '---ATTENTION: parameter passed BYREF will return info
                           ) AS LONG

   '----------------------------------------------------------------------------
   'thinBasic_VariablePtrToDirectPtr
   '----------------------------------------------------------------------------
   '
   '----------------------------------------------------------------------------
   DECLARE FUNCTION  thinBasic_VariablePtrToDirectPtr                _
                           LIB "thinCore.DLL"                        _
                           ALIAS "thinBasic_VariablePtrToDirectPtr"  _
                           (                                         _
                             BYVAL VariablePtr     AS LONG           _
                           ) AS LONG
 
   '----------------------------------------------------------------------------
   'thinBasic_DirectPtrToDataPtr
   '----------------------------------------------------------------------------
   '
   '----------------------------------------------------------------------------
   DECLARE FUNCTION  thinBasic_DirectPtrToDataPtr                    _
                           LIB "thinCore.DLL"                        _
                           ALIAS "thinBasic_DirectPtrToDataPtr"      _
                           (                                         _
                             BYVAL DirectPtr       AS LONG           _
                           ) AS LONG
 
   '----------------------------------------------------------------------------
   'thinBasic_VariableParseAndGetInfo
   '----------------------------------------------------------------------------
   '
   '----------------------------------------------------------------------------
   DECLARE FUNCTION thinBasic_VariableParseAndGetInfo                _
                           LIB "thinCore.DLL"                        _
                           ALIAS "thinBasic_VariableParseAndGetInfo" _
                           (                                         _
                             BYVAL VariableName    AS BSTR PTR     , _   '---ATTENTION: parameter passed BYREF will return info
                             BYVAL VariablePtr     AS LONG PTR     , _   '---ATTENTION: parameter passed BYREF will return info
                             BYVAL MainType        AS LONG PTR     , _   '---ATTENTION: parameter passed BYREF will return info
                             BYVAL SubType         AS LONG PTR     , _   '---ATTENTION: parameter passed BYREF will return info
                             BYVAL DataPtr         AS LONG PTR     , _   '---ATTENTION: parameter passed BYREF will return info
                             BYVAL nElements       AS LONG PTR       _   '---ATTENTION: parameter passed BYREF will return info
							) AS LONG

   '----------------------------------------------------------------------------
   'thinBasic_ChangeVariableStringDirect
   '----------------------------------------------------------------------------
   ' See also thinBasic_VariableParse
   '
   ' Change a variable using direct variable pointer's data returned by
   ' thinBasic_VariableParse. This will ensure to work also with arrays
   '----------------------------------------------------------------------------
   DECLARE FUNCTION  thinBasic_ChangeVariableStringDirect          _
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_ChangeVariableStringDirect" _
                           (                                       _
                             BYVAL VariablePtr     AS LONG       , _
                             BYVAL VariableAbsPos  AS LONG       , _
                             BYVAL lValString      AS BSTR       _
                           ) AS LONG

   '----------------------------------------------------------------------------
   'thinBasic_ChangeVariableNumberDirect
   '----------------------------------------------------------------------------
   ' See also thinBasic_VariableParse
   '
   ' Change a variable using direct variable pointer's data returned by
   ' thinBasic_VariableParse. This will ensure to work also with arrays
   '----------------------------------------------------------------------------
   DECLARE FUNCTION  thinBasic_ChangeVariableNumberDirect          _
                           LIB "thinCore.DLL"                      _
                           ALIAS "thinBasic_ChangeVariableNumberDirect" _
                           (                                       _
                             BYVAL VariablePtr     AS LONG       , _
                             BYVAL VariableAbsPos  AS LONG       , _
                             BYVAL lValNumber      AS EXT          _
                           ) AS LONG
 

   '---Used for thinBasic_AddEquate to force an equate type in case of missing first char $ or %
   Const EquateTypeNumber as long  = 3
   Const EquateTypeString as long  = 5
 
   '----------------------------------------------------------------------------
   ' NOTE
   '----------------------------------------------------------------------------
   ' The following functions
   '
   '    thinBasic_ParseNumber
   '    thinBasic_ParseString
   '    thinBasic_CheckOpenParens
   '    thinBasic_CheckCloseParens
   '    thinBasic_CheckComma
   '
   ' are used inside user defined functions/subs to parse function params.
   ' Imagine you want create a user def function like:
   '
   '    MyFunct(String1, String2, Number1)
   '
   ' To get params you have to parse the following tokens:
   '    (           Open parens
   '      String1     a string expression
   '      ,           a comma
   '      String2     a second string expression
   '      ,           another comma
   '      Number1     a numeric expression
   '    )           Finally close parens
   '
   ' thinBasic gives this ability using 5 simple functions to parse user expressions.
   ' Let's take again the above example and see how to write a user defined
   ' function that returns a STRING
   '
   ' FUNCTION MyLeft() AS STRING
   ' 'Syntax: Number = MyLeft(S1, S2, N1)
   '   LOCAL lString1 AS STRING                           'Define first string param
   '   LOCAL lString2 AS STRING                           'Define second string param
   '   LOCAL lNumber1 AS EXT                              'Define third number param
   '   IF thinBasic_CheckOpenParens THEN                  'Check if open parens token found
   '     thinBasic_ParseString lString1                   'Now evaluate a string expression
   '     IF thinBasic_CheckComma THEN                     'Check if there is a comma
   '       thinBasic_ParseString lString2                 'Parse another string expression
   '       IF thinBasic_CheckComma THEN                   'Another comma
   '         thinBasic_ParseNumber lNumber1               'Now get a numeric expression
   '         IF thinBasic_CheckCloseParens THEN           'Finally a close parens
   '           FUNCTION = LEFT$(lString1, lNumber1) + _   '...here we are. Here you can assign
   '                      LEFT$(lString2, lNumber1)       '...to your function whatever value
   '         END IF                                       '...using the evaluated params
   '       END IF
   '     END IF
   '   END IF
   ' END FUNCTION
   '
   '
   ' thinBasic_CheckOpenParens
   ' thinBasic_CheckCloseParens
   ' thinBasic_CheckComma
   ' have the following optional parameters:
   '
   '   HideHerror 
   '               if %TRUE, in case of parsing problems, no runtime error will
   '               be generated
   '   AutoPutBack
   '               if %TRUE, in case of parsing problems, the found token
   '               will be put back into parsing stack
   '
   '----------------------------------------------------------------------------

    DECLARE SUB      thinBasic_ParseNumber        LIB "thinCore.DLL" ALIAS "thinBasic_ParseNumber" (Result AS EXT)
    DECLARE Sub      thinBasic_ParseDouble        LIB "thinCore.DLL" Alias "thinBasic_ParseDouble" (ByRef Result AS Double)
    DECLARE Sub      thinBasic_ParseLong          LIB "thinCore.DLL" Alias "thinBasic_ParseLong" (ByRef Result AS Long)
    DECLARE Function thinBasic_ParseLong_Optional LIB "thinCore.DLL" Alias "thinBasic_ParseLong_Optional" 	(ByRef Result AS Long) As Long
    DECLARE Sub      thinBasic_ParseDWord         LIB "thinCore.DLL" Alias "thinBasic_ParseDWord" (ByRef Result As Dword)


    DECLARE FUNCTION  thinBasic_Parse1Number  LIB "thinCore.DLL" ALIAS "thinBasic_Parse1Number" ( _
                   _ ' BYVAL Num1 AS EXT PTR  _
                   ) AS EXT
    DECLARE FUNCTION  thinBasic_Parse2Numbers LIB "thinCore.DLL" ALIAS "thinBasic_Parse2Numbers" ( _
                   BYVAL Num1 AS EXT PTR, _
                   BYVAL Num2 AS EXT PTR  _
                   ) AS EXT
    DECLARE FUNCTION  thinBasic_Parse3Numbers LIB "thinCore.DLL" ALIAS "thinBasic_Parse3Numbers" ( _
                   BYVAL Num1 AS EXT PTR, _
                   BYVAL Num2 AS EXT PTR, _
                   BYVAL Num3 AS EXT PTR  _
                   ) AS EXT

    DECLARE FUNCTION  thinBasic_Parse4Numbers LIB "thinCore.DLL" ALIAS "thinBasic_Parse4Numbers" ( _
                   BYVAL Num1 AS EXT PTR, _
                   BYVAL Num2 AS EXT PTR, _
                   BYVAL Num3 AS EXT PTR, _
                   BYVAL Num4 AS EXT PTR  _
                   ) AS EXT
    DECLARE FUNCTION  thinBasic_Parse5Numbers LIB "thinCore.DLL" ALIAS "thinBasic_Parse5Numbers" ( _
                   BYVAL Num1 AS EXT PTR, _
                   BYVAL Num2 AS EXT PTR, _
                   BYVAL Num3 AS EXT PTR, _
                   BYVAL Num4 AS EXT PTR, _
                   BYVAL Num5 AS EXT PTR  _
                   ) AS EXT
    DECLARE FUNCTION  thinBasic_Parse6Numbers LIB "thinCore.DLL" ALIAS "thinBasic_Parse6Numbers" ( _
                   BYVAL Num1 AS EXT PTR, _
                   BYVAL Num2 AS EXT PTR, _
                   BYVAL Num3 AS EXT PTR, _
                   BYVAL Num4 AS EXT PTR, _
                   BYVAL Num5 AS EXT PTR, _
                   BYVAL Num6 AS EXT PTR  _
                   ) AS EXT
    DECLARE FUNCTION  thinBasic_Parse7Numbers LIB "thinCore.DLL" ALIAS "thinBasic_Parse7Numbers" ( _
                   BYVAL Num1 AS EXT PTR, _
                   BYVAL Num2 AS EXT PTR, _
                   BYVAL Num3 AS EXT PTR, _
                   BYVAL Num4 AS EXT PTR, _
                   BYVAL Num5 AS EXT PTR, _
                   BYVAL Num6 AS EXT PTR, _
                   BYVAL Num7 AS EXT PTR  _
                   ) AS EXT



  DECLARE FUNCTION  thinBasic_ParseXNumbers LIB "thinCore.DLL" ALIAS "thinBasic_ParseXNumbers"   ( _
                    BYVAL MinNumToParse AS LONG, _
                    BYVAL MaxNumToParse AS LONG, _
                    BYVAL Num1  AS EXT PTR   , _
                    _ ' OPTIONAL
                    BYVAL Num2  AS EXT PTR    , _
                    BYVAL Num3  AS EXT PTR   , _
                    BYVAL Num4  AS EXT PTR   , _
                    BYVAL Num5  AS EXT PTR   , _
                    BYVAL Num6  AS EXT PTR   , _
                    BYVAL Num7  AS EXT PTR   , _
                    BYVAL Num8  AS EXT PTR   , _
                    BYVAL Num9  AS EXT PTR   , _
                    BYVAL Num10 AS EXT PTR     _
                   ) AS EXT

  DECLARE FUNCTION  thinBasic_Parse1StringXNumbers LIB "thinCore.DLL" ALIAS "thinBasic_Parse1StringXNumbers"       ( _
                    BYVAL MinNumToParse AS LONG, _
                    BYVAL MaxNumToParse AS LONG, _
                    BYVAL Str1  AS BSTR PTR, _
                    BYVAL Num1  AS EXT PTR   , _
                    _ 'OPTIONAL 
                    BYVAL Num2  AS EXT PTR   , _
                    BYVAL Num3  AS EXT PTR   , _
                    BYVAL Num4  AS EXT PTR   , _
                    BYVAL Num5  AS EXT PTR   , _
                    BYVAL Num6  AS EXT PTR   , _
                    BYVAL Num7  AS EXT PTR   , _
                    BYVAL Num8  AS EXT PTR   , _
                    BYVAL Num9  AS EXT PTR   , _
                    BYVAL Num10 AS EXT       _
                   ) AS EXT

        '----------------------------------------------------------------------------
	DECLARE FUNCTION  thinBasic_ParseString                 ALIAS "thinBasic_ParseString"                (BYREF Result As thinstring) AS long
	'----------------------------------------------------------------------------
	DECLARE FUNCTION  thinBasic_CheckOpenParens             ALIAS "thinBasic_CheckOpenParens"            (BYVAL HideError AS LONG, BYVAL AutoPutBack AS LONG) AS LONG
	DECLARE FUNCTION  thinBasic_CheckOpenParens_Mandatory   ALIAS "thinBasic_CheckOpenParens_Mandatory"  () AS LONG
	DECLARE FUNCTION  thinBasic_CheckOpenParens_Optional    ALIAS "thinBasic_CheckOpenParens_Optional"   () AS LONG
	'----------------------------------------------------------------------------
	DECLARE FUNCTION  thinBasic_CheckCloseParens            ALIAS "thinBasic_CheckCloseParens"           (BYVAL HideError AS LONG, BYVAL AutoPutBack AS LONG) AS LONG
	DECLARE FUNCTION  thinBasic_CheckCloseParens_Mandatory  ALIAS "thinBasic_CheckCloseParens_Mandatory" () AS LONG
	DECLARE FUNCTION  thinBasic_CheckCloseParens_Optional   ALIAS "thinBasic_CheckCloseParens_Optional"  () AS LONG
	'----------------------------------------------------------------------------
	DECLARE FUNCTION  thinBasic_CheckComma                  ALIAS "thinBasic_CheckComma"                 (BYVAL HideError AS LONG, BYVAL AutoPutBack AS LONG) AS LONG
	DECLARE FUNCTION  thinBasic_CheckComma_Mandatory        ALIAS "thinBasic_CheckComma_Mandatory"       () AS LONG
	DECLARE FUNCTION  thinBasic_CheckComma_Optional         ALIAS "thinBasic_CheckComma_Optional"        () AS LONG

'----------------------------------------------------------------------------

  '----------------------------------------------------------------------------
 DECLARE FUNCTION  thinBasic_DetermineType     LIB "thinCore.DLL" ALIAS "thinBasic_DetermineType"    () AS LONG
  '----------------------------------------------------------------------------

  '----------------------------------------------------------------------------
  'thinBasic_GetRunTimeInfo
  '----------------------------------------------------------------------------
  ' The following information can be taken:
  '  "SCRIPT_PATH"  Path to script
  '  "APP_PATH"     Path to thinBasic
  '  "HWND"         Handle to main thinBasic window
  '----------------------------------------------------------------------------
  DECLARE FUNCTION  thinBasic_GetRunTimeInfo    LIB "thinCore.DLL" ALIAS "thinBasic_GetRunTimeInfo"   (BYVAL InfoName AS BSTR) AS BSTR
  '----------------------------------------------------------------------------

  '----------------------------------------------------------------------------
  'thinBasic_GetLastError
  '----------------------------------------------------------------------------
  DECLARE FUNCTION  thinBasic_GetLastError      LIB "thinCore.DLL" ALIAS "thinBasic_GetLastError"     () AS LONG

'  FUNCTION thinBasic_ErrorFree () AS LONG
'    IF thinBasic_GetLastError = 0 THEN
'      FUNCTION = ISTRUE(1=1)
'    ELSE
'     FUNCTION = ISTRUE(1<>1)
'    END IF
'  END FUNCTION
  '----------------------------------------------------------------------------

' more funs: see inc

  '----------------------------------------------------------------------------


  ' Duplicated defs
  '------------------------------------------------------------------------------
  'Return Types from functions/Subs
  '------------------------------------------------------------------------------
  '#define thinBasic_ReturnNone               0   'Used in thinBasic_LoadSymbol to define a sub
  '#define thinBasic_ReturnNumber            20   'Used in thinBasic_LoadSymbol to define a function returning a EXT number
  '#define thinBasic_ReturnString            30   'Used in thinBasic_LoadSymbol to define a function returning a string

  '#define thinBasic_ReturnCodeByte           1
  '#define thinBasic_ReturnCodeInteger        2
  '#define thinBasic_ReturnCodeWord           3
  '#define thinBasic_ReturnCodeDWord          4
  '#define thinBasic_ReturnCodeLong           5
  '#define thinBasic_ReturnCodeQuad           6
  '#define thinBasic_ReturnCodeSingle         7 
  '#define thinBasic_ReturnCodeDouble         8
  '#define thinBasic_ReturnCodeCurrency       9
  '#define thinBasic_ReturnCodeExt           10
  '------------------------------------------------------------------------------

  '------------------------------------------------------------------------------
  'Global declares
  '------------------------------------------------------------------------------
  '#define thinBasic_ForceOverWrite = 1   'Used in thinBasic_LoadSymbol to force symbol over writing


  '----------------------------------------------------------------------------
  'thinBasic_RunTimeError
  '----------------------------------------------------------------------------
  ' Use internal thinCore engine to generate a runtime error
  '  ErrorCode      Error code. Get one from the below list
  '  AdditionalInfo Personalized text to be shown into runtime error dialog
  '----------------------------------------------------------------------------
  Declare Function thinBasic_RunTimeError                               _
                          Lib "thinCore.dll"                            _
                          Alias "thinBasic_RunTimeError"                _
                          ( _
                                      ByVal ErrorCode       As Long   , _
                             _' Optional 
                                      ByVal AdditionalInfo  As BSTR     _
                          ) As Long

  '------------------------------------------------------------------------------
  ' RunTime Errors Codes
  '------------------------------------------------------------------------------
      #define ERR__PARENS                                 1
      #define ERR__NOEXP                                  2
      #define ERR__DIV_ZERO                               3
      #define ERR__EQUAL_EXP                              4
      #define ERR__NOT_VAR                                5
      #define ERR__LAB_TAB_FULL                           6
      #define ERR__DUP_LAB                                7
      #define ERR__UNDEF_LAB                              8
      #define ERR__THEN_EXPECTED                          9
      #define ERR__TO_EXPECTED                           10
      #define ERR__TOO_MANY_FOR                          11
      #define ERR__NEXT_WITHOUT_FOR                      12
      #define ERR__MISS_QUOTE                            15
      #define ERR__BAD_FILE                              16
      #define ERR__STR_EXPECTED                          17
      #define ERR__UNKNOWN_KEYWORD                       18
      #define ERR__MISSING_OPENPARENS                    19
      #define ERR__MISSING_CLOSEPARENS                   20
      #define ERR__MISSING_COMMA                         21
      #define ERR__ATOM_COMMAND                          22
      #define ERR__ATOM_TOKEN_TYPE                       23
      #define ERR__ATOM                                  24
      #define ERR__COMMAND_UNKNOWN_RETURNED_PARAMETER    25
      #define ERR__PRIMITIVE_STR                         26
      #define ERR__PRIMITIVE_NUM                         27
      #define ERR__PRINT_ERROR                           28
      #define ERR__PRINT_ERROR_NOENDOFLINE               29
      #define ERR__VARIABLE_NOT_DEFINED                  30
      #define ERR__ATOM_TOKEN_TYPE_NUMERIC               31
      #define ERR__IF_WITHOUT_ENDIF                      32
      #define ERR__IF_ENDIF_WITHOUT_IF                   33
      #define ERR__TOO_MANY_WHILE                        34
      #define ERR__WHILE_WITHOUT_WEND                    35
      #define ERR__DIM_TYPE_NOT_DEFINED                  36
      #define ERR__EXIT_NO_KEY_FOUND                     37
      #define ERR__NO_END_FUNCTION_FOUND                 38
      #define ERR__FUNCTION_NAME_DUPLICATE               39
      #define ERR__FUNCTION_NAME_IS_KEY                  40
      #define ERR__FUNCTION_NAME_IS_VAR                  41
      #define ERR__FUNCTION_NAME_IS_UDT                  42
    
    
      #define ERR__DIM_MISSING_AS                        43
      #define ERR__UNDEFINED_TOKEN                       44
      #define ERR__UNSUPPORTED_CHAR                      45
                                                
      #define ERR__FUNCTION_DECLARE_MISSING_AS           47
      #define ERR__DECLARE_FUNCTION_OR_SUB_EXPECTED      48
                                                
      #define ERR__DOLOOP_WRONG_CONDITION                49
                                                
                                                
      #define ERR__MISSING_ALIAS                         50
      #define ERR__MISSING_LIB                           51
      #define ERR__UNDEFINED_VAR_TYPE                    52
                                                
      #define ERR__LOOP_EXPECTED_WHILE_OR_UNTIL          55
                                                
      #define ERR__END_FUNCTION_FOUND                    59
                                                
      #define ERR__ITERATE_NO_KEY_FOUND                  60
                                                
      #define ERR__VARIABLE_NOT_DIMENSIONED              70
      #define ERR__VARIABLE_ISNOT_ARRAY                  71
      #define ERR__VARIABLE_MUSTBE_STRING_TYPE           72
                                                
      #define ERR__KEYWORD_NOT_EXPECTED                  75
      #define ERR__TOKEN_NOT_EXPECTED                    76
                                                
      #define ERR__INCLUDE_FILE_NOT_FOUND                80
                                                
      #define ERR__FUNCTION_NOT_SUPPORTED                90
                                                
      #define ERR__ARRAY_FUNCTION_NOT_SUPPORTED          91
                                                
      #define ERR__UDT_ELEMENT_NOT_FOUND                100
                                                
      #define ERR__ASSIGNMENT_NOT_SUPPORTED             110
                                                
      #define ERR__RELATIONAL_EXPECTED                  115
                                                
      #define ERR__API_LIB_NOT_FOUND                    120
      #define ERR__API_FUNCTION_NOT_FOUND_IN_LIB        121
      #define ERR__API_GENERAL_ADDRESS_NOT_PRESENT      122
                                               
      #define ERR__CALL_NOTSUPPORTEDSTATEMENT           130
      #define ERR__CALL_FUNCTIONNOTFOUND                131
                                               
      #define ERR__EQUATE_ALREADY_DEFINED               135
                                               
      #define ERR__VARIABLE_NAME_DUPLICATE_GLOBAL       142
      #define ERR__VARIABLE_NAME_DUPLICATE_FUNCTION     144
      #define ERR__VARIABLE_NAME_DUPLICATE_LOCAL        145
      #define ERR__VARIABLE_NAME_DUPLICATE              146
                                               
      #define ERR__FOR_StepShouldBeNegative             150
      #define ERR__FOR_StepShouldBePositive             151
      #define ERR__FOR_ExpectedAVariable                152
      #define ERR__FOR_StepIsZero                       153
                                               
      #define ERR__ALIAS_CommandNameExpected            160
      #define ERR__ALIAS_AsExpected                     161
      #define ERR__ALIAS_UndefNotUndef                  162
                                               
      #define ERR__TYPE_MISSING_END_TYPE                170
      #define ERR__TYPE_TYPE_NOT_DEFINED                171
      #define ERR__TYPE_MISSING_AS                      172
      #define ERR__TYPE_NAME_MUSTBE_UNDEFINED           173
      #define ERR__TYPE_ARRAY_MUSTBE_DIMENSIONED        174
      #define ERR__TYPE_STRINGS_MUST_HAVE_SIZE          175
                                               
      #define ERR__FUNCTION_MISSING_AS                  246
      #define ERR__REGEXPR_MISSING_TO                   247
      #define ERR__REGEXPR_MISSING_IN                   248
      #define ERR__SELECT_WITHOUT_ENDSELECT             249
      #define ERR__DUPLICATE_SYMBOL                     250
      #define ERR__INVALIDNUMERICCHAR                   251
      #define ERR__INVALIDDELIMITER                     252
      #define ERR__INVALIDDATATYPE                      253
      #define ERR__VARIABLE_EXPECTED                    254 
      #define ERR__VARIABLE_VARIANT_EXPECTED            255 
                                               
      #define ERR__SELECT_MISSING_CASE                  270
      #define ERR__SELECT_ERROR_KINDOF_OPERATION        271
                                               
      #define ERR__APICALL_REF_EXPECTED                 300
                                               
      #define ERR__ARRAY_OUT_OF_BOUND                   400
      
      #define ERR__MODULE_SPECIFIC                      500
      
 