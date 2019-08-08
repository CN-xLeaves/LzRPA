'------------------------------------------------------------------------------
'
'  Ime_cmodes.inc
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from Ime_cmodes.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%IME_CMODES = 1

' bit field for conversion mode
%IME_CMODE_ALPHANUMERIC    = &H0000
%IME_CMODE_NATIVE          = &H0001
%IME_CMODE_CHINESE         = %IME_CMODE_NATIVE
%IME_CMODE_HANGUL          = %IME_CMODE_NATIVE
%IME_CMODE_JAPANESE        = %IME_CMODE_NATIVE
%IME_CMODE_KATAKANA        = &H0002  ' only effect under %IME_CMODE_NATIVE
%IME_CMODE_LANGUAGE        = &H0003
%IME_CMODE_FULLSHAPE       = &H0008
%IME_CMODE_ROMAN           = &H0010
%IME_CMODE_CHARCODE        = &H0020
%IME_CMODE_HANJACONVERT    = &H0040
