'------------------------------------------------------------------------------
'
'  IsGuids.inc - Internet Shortcut GUID definitions.
'
'  Copyright (c) 2009-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2010
'
'------------------------------------------------------------------------------
'  from IsGuids.h dated 14 Jul 2009
'------------------------------------------------------------------------------

' GUIDs
'********

#INCLUDE THIS ONCE

#IF NOT %DEF(%ISGUIDS_H)
%ISGUIDS_H = 1

$CLSID_InternetShortcut       = GUID$("{FBF23B40-E3F0-101B-8488-00AA003E56F8}")

$IID_IUniformResourceLocatorA = GUID$("{FBF23B80-E3F0-101B-8488-00AA003E56F8}")
$IID_IUniformResourceLocatorW = GUID$("{CABB0DA0-DA57-11CF-9974-0020AFD79762}")

#IF %DEF(%UNICODE)
$IID_IUniformResourceLocator = $IID_IUniformResourceLocatorW
#ELSE
$IID_IUniformResourceLocator = $IID_IUniformResourceLocatorA
#ENDIF

#ENDIF
