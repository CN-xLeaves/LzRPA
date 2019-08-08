'------------------------------------------------------------------------------
'
'  lm.inc
'    This is the top level include file that includes all the files
'    necessary for writing Lan Manager Application.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from lm.h build version 0001 of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%LM = 1

#INCLUDE "lmcons.inc"     ' LAN Manager common definitions
#INCLUDE "lmerr.inc"      ' LAN Manager network error definitions

#INCLUDE "lmaccess.inc"   ' Access, Domain, Group and User classes
#INCLUDE "lmalert.inc"    ' Alerter
#INCLUDE "lmshare.inc"    ' Connection, File, Session and Share classes
#INCLUDE "lmmsg.inc"      ' Message class
#INCLUDE "lmremutl.inc"   ' Remote Utility class
#INCLUDE "lmrepl.inc"     ' Replicator class
#INCLUDE "lmserver.inc"   ' Server class
#INCLUDE "lmsvc.inc"      ' Service class
#INCLUDE "lmuse.inc"      ' Use class
#INCLUDE "lmwksta.inc"    ' Workstation class
#INCLUDE "lmapibuf.inc"   ' NetApiBuffer class
#INCLUDE "lmerrlog.inc"   ' NetErrorLog class
#INCLUDE "lmconfig.inc"   ' NetConfig class
#INCLUDE "lmstats.inc"    ' NetStats class
#INCLUDE "lmaudit.inc"    ' NetAudit class
#INCLUDE "lmjoin.inc"     ' NetJoinDomain class
