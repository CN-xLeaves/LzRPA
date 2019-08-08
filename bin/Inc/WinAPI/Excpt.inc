'------------------------------------------------------------------------------
'
'  Excpt.inc -- exception values
'
'  Copyright (c) 2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from excpt.h of 29 Jun 2006
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%INC_EXCPT = 1


'
' Exception disposition return values.
'
ENUM EXCEPTION_DISPOSITION SINGULAR
    ExceptionContinueExecution
    ExceptionContinueSearch
    ExceptionNestedException
    ExceptionCollidedUnwind
END ENUM


'
' Legal values for expression in except().
'

%EXCEPTION_EXECUTE_HANDLER    = 1
%EXCEPTION_CONTINUE_SEARCH    = 0
%EXCEPTION_CONTINUE_EXECUTION = -1
