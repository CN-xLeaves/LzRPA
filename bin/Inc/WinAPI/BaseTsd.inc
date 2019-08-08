'------------------------------------------------------------------------------
'
'  BaseTsd.inc -- Type definitions for the basic sized types.
'
'  Copyright (c) 2010 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from BaseTsd.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%BASETSD_H = 1

%ADDRESS_TAG_BIT = &H80000000???

'
' SIZE_T used for counts or ranges which need to span the range of
' of a pointer.  SSIZE_T is the signed variation.
'

#IF NOT %DEF(%SIZE_T_DEFINED)
MACRO SIZE_T=DWORD
%SIZE_T_DEFINED = 1
#ENDIF
MACRO SSIZE_T=LONG

'
' Add Windows flavor DWORD_PTR types
'

MACRO DWORD_PTR=DWORD

'
' The following types are guaranteed to be signed and 64 bits wide.
'

MACRO LONG64=QUAD


'
' The following types are guaranteed to be unsigned and 64 bits wide.
' [SIGNED values here]

MACRO DWORD64=QUAD
MACRO ULONG64=QUAD

'
' Legacy thread affinity.
'

MACRO KAFFINITY=DWORD
