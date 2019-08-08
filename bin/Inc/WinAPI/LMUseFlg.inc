'------------------------------------------------------------------------------
'
'  LmUseFlg.inc -- deletion force levels for deleting a connection.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from LmUseFlg.h build version 0001 of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%LMUSEFLG = 1


'
' Definition for NetWkstaTransportDel and NetUseDel deletion force levels
'

%USE_NOFORCE           = 0
%USE_FORCE             = 1
%USE_LOTS_OF_FORCE     = 2
