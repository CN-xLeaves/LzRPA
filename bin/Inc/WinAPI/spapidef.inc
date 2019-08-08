'------------------------------------------------------------------------------
'
'  SpApiDef.inc -- Windows NT Setup and Device Installer services
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from SpApiDef.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%INC_SPAPIDEF = 1


#IF NOT %DEF(%SP_LOG_TOKEN)
%SP_LOG_TOKEN = 1
MACRO SP_LOG_TOKEN=QUAD
#ENDIF


'
' Special txtlog token values
'

%LOGTOKEN_TYPE_MASK         = 3

%LOGTOKEN_UNSPECIFIED       = 0
%LOGTOKEN_NO_LOG            = 1
%LOGTOKEN_SETUPAPI_APPLOG   = 2
%LOGTOKEN_SETUPAPI_DEVLOG   = 3


'
' Flags for SetupCreateTextLogSection
'

%TXTLOG_SETUPAPI_DEVLOG     = &H00000001   ' 1 = setupdi.log, 0 = setupapi.log
%TXTLOG_SETUPAPI_CMDLINE    = &H00000002   ' log the command line

%TXTLOG_SETUPAPI_BITS       = &H00000003


'
' Flags for SetupWriteTextLog
'

'
' Event Levels (bits 0-3)
'

%TXTLOG_ERROR               = &H1   ' shows entries which indicate a real problem
%TXTLOG_WARNING             = &H2   ' shows entries which indicate a potential problem
%TXTLOG_SYSTEM_STATE_CHANGE = &H3   ' system changes only
%TXTLOG_SUMMARY             = &H4   ' show basic operation surrounding system changes
%TXTLOG_DETAILS             = &H5   ' detailed operation of the install process
%TXTLOG_VERBOSE             = &H6   ' log entries which potentially generate a lot of data
%TXTLOG_VERY_VERBOSE        = &H7   ' highest level shows all log entries

'
' Bits reserved for internal use
'

%TXTLOG_RESERVED_FLAGS   = &H0000FFF0

'
' Basic flags (bits 4-31)
'

%TXTLOG_TIMESTAMP        = &H00010000
%TXTLOG_DEPTH_INCR       = &H00020000
%TXTLOG_DEPTH_DECR       = &H00040000
%TXTLOG_TAB_1            = &H00080000
%TXTLOG_FLUSH_FILE       = &H00100000

MACRO TXTLOG_LEVEL(flags)=((flags) AND &H000f)


'
' Setupapi, Setupdi event categories
'

%TXTLOG_DEVINST          = &H00000001
%TXTLOG_INF              = &H00000002
%TXTLOG_FILEQ            = &H00000004
%TXTLOG_COPYFILES        = &H00000008

%TXTLOG_SIGVERIF         = &H00000020

%TXTLOG_BACKUP           = &H00000080
%TXTLOG_UI               = &H00000100
%TXTLOG_UTIL             = &H00000200
%TXTLOG_INFDB            = &H00000400

%TXTLOG_POLICY           = &H00800000
%TXTLOG_NEWDEV           = &H01000000
%TXTLOG_UMPNPMGR         = &H02000000
%TXTLOG_DRIVER_STORE     = &H04000000
%TXTLOG_SETUP            = &H08000000
%TXTLOG_CMI              = &H10000000
%TXTLOG_DEVMGR           = &H20000000

%TXTLOG_INSTALLER        = &H40000000
%TXTLOG_VENDOR           = &H80000000???
