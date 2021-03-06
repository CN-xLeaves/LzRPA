'------------------------------------------------------------------------------
'
'  CDErr.inc -- Common dialog error return codes
'
'  Copyright (C) 2009-2010 PowerBASIC, Inc.
'  Portions Copyright (C) Microsoft Corporation
'  All Rights Reserved.
'
'  Last Update: 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from CDErr.h version 1.0 of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%INC_CDERR = 1



%CDERR_DIALOGFAILURE    = &HFFFF??

%CDERR_GENERALCODES     = &H0000
%CDERR_STRUCTSIZE       = &H0001
%CDERR_INITIALIZATION   = &H0002
%CDERR_NOTEMPLATE       = &H0003
%CDERR_NOHINSTANCE      = &H0004
%CDERR_LOADSTRFAILURE   = &H0005
%CDERR_FINDRESFAILURE   = &H0006
%CDERR_LOADRESFAILURE   = &H0007
%CDERR_LOCKRESFAILURE   = &H0008
%CDERR_MEMALLOCFAILURE  = &H0009
%CDERR_MEMLOCKFAILURE   = &H000A
%CDERR_NOHOOK           = &H000B
%CDERR_REGISTERMSGFAIL  = &H000C

%PDERR_PRINTERCODES     = &H1000
%PDERR_SETUPFAILURE     = &H1001
%PDERR_PARSEFAILURE     = &H1002
%PDERR_RETDEFFAILURE    = &H1003
%PDERR_LOADDRVFAILURE   = &H1004
%PDERR_GETDEVMODEFAIL   = &H1005
%PDERR_INITFAILURE      = &H1006
%PDERR_NODEVICES        = &H1007
%PDERR_NODEFAULTPRN     = &H1008
%PDERR_DNDMMISMATCH     = &H1009
%PDERR_CREATEICFAILURE  = &H100A
%PDERR_PRINTERNOTFOUND  = &H100B
%PDERR_DEFAULTDIFFERENT = &H100C

%CFERR_CHOOSEFONTCODES  = &H2000
%CFERR_NOFONTS          = &H2001
%CFERR_MAXLESSTHANMIN   = &H2002

%FNERR_FILENAMECODES    = &H3000
%FNERR_SUBCLASSFAILURE  = &H3001
%FNERR_INVALIDFILENAME  = &H3002
%FNERR_BUFFERTOOSMALL   = &H3003

%FRERR_FINDREPLACECODES = &H4000
%FRERR_BUFFERLENGTHZERO = &H4001

%CCERR_CHOOSECOLORCODES = &H5000
