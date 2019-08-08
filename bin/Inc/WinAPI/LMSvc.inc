'------------------------------------------------------------------------------
'
'  LMSvc.inc -- definitions for the NetService API.
'
'  Copyright (c) 2009-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from LMSvc.h build version 0002 dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%LMSVC = 1

#INCLUDE "LmCons.inc"
'
' Include the file which contains all the service name strings.
'
#INCLUDE "LmsName.inc"

'
'  Data Structures
'

TYPE SERVICE_INFO_0
    svci0_name AS WSTRINGZ PTR
END TYPE

TYPE SERVICE_INFO_1
    svci1_name   AS WSTRINGZ PTR
    svci1_status AS DWORD
    svci1_code   AS DWORD
    svci1_pid    AS DWORD
END TYPE

TYPE SERVICE_INFO_2
    svci2_name           AS WSTRINGZ PTR
    svci2_status         AS DWORD
    svci2_code           AS DWORD
    svci2_pid            AS DWORD
    svci2_text           AS WSTRINGZ PTR
    svci2_specific_error AS DWORD
    svci2_display_name   AS WSTRINGZ PTR
END TYPE

'
' Function Prototypes
'

DECLARE FUNCTION NetServiceControl LIB "NetApi32.dll" _
    ALIAS "NetServiceControl" ( _
    servername   AS WSTRINGZ, _
    service      AS WSTRINGZ, _
    BYVAL opcode AS DWORD, _
    BYVAL arg    AS DWORD, _
    BYVAL bufptr AS BYTE PTR _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetServiceEnum LIB "NetApi32.dll" _
    ALIAS "NetServiceEnum" ( _
    servername       AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    BYVAL bufptr     AS BYTE PTR, _
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resume_handle    AS DWORD _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetServiceGetInfo LIB "NetApi32.dll" _
    ALIAS "NetServiceGetInfo" ( _
    servername   AS WSTRINGZ, _
    service      AS WSTRINGZ, _
    BYVAL level  AS DWORD, _
    BYVAL bufptr AS BYTE PTR _
    ) AS NET_API_STATUS

DECLARE FUNCTION NetServiceInstall LIB "NetApi32.dll" _
    ALIAS "NetServiceInstall" ( _
    servername   AS WSTRINGZ, _
    service      AS WSTRINGZ, _
    BYVAL argc   AS DWORD, _
    argv         AS ANY, _  ' array of wstringz, _
    BYVAL bufptr AS BYTE PTR _
    ) AS NET_API_STATUS

'
' Special Values and Constants
'

'
'  Bitmask and bit values for svci1_status, and svci2_status
'  fields.  For each "subfield", there is a mask defined,
'  and a number of constants representing the value
'  obtained by doing (status & mask).
'

' Bits 0,1 -- general status

%SERVICE_INSTALL_STATE     = &H03
%SERVICE_UNINSTALLED       = &H00
%SERVICE_INSTALL_PENDING   = &H01
%SERVICE_UNINSTALL_PENDING = &H02
%SERVICE_INSTALLED         = &H03

' Bits 2,3 -- paused/active status

%SERVICE_PAUSE_STATE           = &H0C
%LM20_SERVICE_ACTIVE           = &H00
%LM20_SERVICE_CONTINUE_PENDING = &H04
%LM20_SERVICE_PAUSE_PENDING    = &H08
%LM20_SERVICE_PAUSED           = &H0C

' Bit 4 -- uninstallable indication

%SERVICE_NOT_UNINSTALLABLE = &H00
%SERVICE_UNINSTALLABLE     = &H10

' Bit 5 -- pausable indication

%SERVICE_NOT_PAUSABLE      = &H00
%SERVICE_PAUSABLE          = &H20

' Workstation service only:
' Bits 8,9,10 -- redirection paused/active

%SERVICE_REDIR_PAUSED       = &H700
%SERVICE_REDIR_DISK_PAUSED  = &H100
%SERVICE_REDIR_PRINT_PAUSED = &H200
%SERVICE_REDIR_COMM_PAUSED  = &H400

'
'  Additional standard LAN Manager for MS-DOS services
'

$$SERVICE_DOS_ENCRYPTION = "ENCRYPT"$$

'
'  NetServiceControl opcodes.
'

%SERVICE_CTRL_INTERROGATE  = 0
%SERVICE_CTRL_PAUSE        = 1
%SERVICE_CTRL_CONTINUE     = 2
%SERVICE_CTRL_UNINSTALL    = 3

'
'  Workstation service only:  Bits used in the "arg" parameter
'  to NetServiceControl in conjunction with the opcode
'  SERVICE_CTRL_PAUSE or SERVICE_CTRL_CONTINUE, to pause or
'  continue redirection.
'

%SERVICE_CTRL_REDIR_DISK   = &H1
%SERVICE_CTRL_REDIR_PRINT  = &H2
%SERVICE_CTRL_REDIR_COMM   = &H4

'
'  Values for svci1_code, and svci2_code when status
'  of the service is SERVICE_INSTALL_PENDING or
'  SERVICE_UNINSTALL_PENDING.
'  A service can optionally provide a hint to the installer
'  that the install is proceeding and how long to wait
'  (in 0.1 second increments) before querying status again.
'

%SERVICE_IP_NO_HINT        = &H0
%SERVICE_CCP_NO_HINT       = &H0

%SERVICE_IP_QUERY_HINT     = &H10000
%SERVICE_CCP_QUERY_HINT    = &H10000

'
' Mask for install proceeding checkpoint number
'

%SERVICE_IP_CHKPT_NUM      = &H0FF
%SERVICE_CCP_CHKPT_NUM     = &H0FF

'
' Mask for wait time hint before querying again
'

%SERVICE_IP_WAIT_TIME      = &H0FF00
%SERVICE_CCP_WAIT_TIME     = &H0FF00

'
' Shift count for building wait time _code values
'

%SERVICE_IP_WAITTIME_SHIFT   = 8
%SERVICE_NTIP_WAITTIME_SHIFT = 12

'
' Mask used for upper and lower portions of wait hint time.
'
%UPPER_HINT_MASK     = &H0000FF00
%LOWER_HINT_MASK     = &H000000FF
%UPPER_GET_HINT_MASK = &H0FF00000
%LOWER_GET_HINT_MASK = &H0000FF00
%SERVICE_NT_MAXTIME  = &H0000FFFF
%SERVICE_RESRV_MASK  = &H0001FFFF
%SERVICE_MAXTIME     = &H000000FF

'
'  SERVICE_BASE is the base of service error codes,
'  chosen to avoid conflict with OS, redirector,
'  netapi, and errlog codes.
'
' Don't change the comments following the manifest constants without
' understanding how mapmsg works.
'

%SERVICE_BASE              = 3050
%SERVICE_UIC_NORMAL        = 0
'
'  Uninstall codes, to be used in high byte of 'code' on final NetStatus,
'  which sets the status to UNINSTALLED.
'

%SERVICE_UIC_BADPARMVAL        = (%SERVICE_BASE + 1)
'
' The Registry or the information you just typed includes an illegal
' value for "%1".
'

%SERVICE_UIC_MISSPARM          = (%SERVICE_BASE + 2)
'
' The required parameter was not provided on the command
' line or in the configuration file.
'

%SERVICE_UIC_UNKPARM           = (%SERVICE_BASE + 3)
'
' LAN Manager does not recognize "%1" as a valid option.
'

%SERVICE_UIC_RESOURCE          = (%SERVICE_BASE + 4)
'
' A request for resource could not be satisfied.
'

%SERVICE_UIC_CONFIG            = (%SERVICE_BASE + 5)
'
' A problem exists with the system configuration.
'

%SERVICE_UIC_SYSTEM            = (%SERVICE_BASE + 6)
'
' A system error has occurred.
'

%SERVICE_UIC_INTERNAL          = (%SERVICE_BASE + 7)
'
' An internal consistency error has occurred.
'

%SERVICE_UIC_AMBIGPARM         = (%SERVICE_BASE + 8)
'
' The configuration file or the command line has an ambiguous option.
'

%SERVICE_UIC_DUPPARM           = (%SERVICE_BASE + 9)
'
' The configuration file or the command line has a duplicate parameter.
'

%SERVICE_UIC_KILL              = (%SERVICE_BASE + 10)
'
' The service did not respond to control and was stopped with
' the DosKillProc function.
'

%SERVICE_UIC_EXEC              = (%SERVICE_BASE + 11)
'
' An error occurred when attempting to run the service program.
'

%SERVICE_UIC_SUBSERV           = (%SERVICE_BASE + 12)
'
' The sub-service failed to start.
'

%SERVICE_UIC_CONFLPARM         = (%SERVICE_BASE + 13)
'
' There is a conflict in the value or use of these options: %1.
'

%SERVICE_UIC_FILE              = (%SERVICE_BASE + 14)
'
' There is a problem with the file.
'



'
'  The modifiers
'

'
' General:
'

%SERVICE_UIC_M_NULL = 0

'
'  RESOURCE:
'

%SERVICE_UIC_M_MEMORY    = (%SERVICE_BASE + 20)     ' memory
%SERVICE_UIC_M_DISK      = (%SERVICE_BASE + 21)     ' disk space
%SERVICE_UIC_M_THREADS   = (%SERVICE_BASE + 22)     ' thread
%SERVICE_UIC_M_PROCESSES = (%SERVICE_BASE + 23)     ' process

'
'  CONFIG:
'

'
' Security failure
'

%SERVICE_UIC_M_SECURITY        = (%SERVICE_BASE + 24)
' Security Failure. %0

%SERVICE_UIC_M_LANROOT         = (%SERVICE_BASE + 25)
'
' Bad or missing LAN Manager root directory.
'

%SERVICE_UIC_M_REDIR           = (%SERVICE_BASE + 26)
'
' The network software is not installed.
'

%SERVICE_UIC_M_SERVER          = (%SERVICE_BASE + 27)
'
' The server is not started.
'

%SERVICE_UIC_M_SEC_FILE_ERR    = (%SERVICE_BASE + 28)
'
' The server cannot access the user accounts database (NET.ACC).
'

%SERVICE_UIC_M_FILES           = (%SERVICE_BASE + 29)
'
' Incompatible files are installed in the LANMAN tree.
'

%SERVICE_UIC_M_LOGS            = (%SERVICE_BASE + 30)
'
' The LANMAN\LOGS directory is invalid.
'

%SERVICE_UIC_M_LANGROUP        = (%SERVICE_BASE + 31)
'
' The domain specified could not be used.
'

%SERVICE_UIC_M_MSGNAME         = (%SERVICE_BASE + 32)
'
' The computer name is being used as a message alias on another computer.
'

%SERVICE_UIC_M_ANNOUNCE        = (%SERVICE_BASE + 33)
'
' The announcement of the server name failed.
'

%SERVICE_UIC_M_UAS             = (%SERVICE_BASE + 34)
'
' The user accounts database is not configured correctly.
'

%SERVICE_UIC_M_SERVER_SEC_ERR  = (%SERVICE_BASE + 35)
'
' The server is not running with user-level security.
'

%SERVICE_UIC_M_WKSTA           = (%SERVICE_BASE + 37)
'
' The workstation is not configured properly.
'

%SERVICE_UIC_M_ERRLOG          = (%SERVICE_BASE + 38)
'
' View your error log for details.
'

%SERVICE_UIC_M_FILE_UW         = (%SERVICE_BASE + 39)
'
' Unable to write to this file.
'

%SERVICE_UIC_M_ADDPAK          = (%SERVICE_BASE + 40)
'
' ADDPAK file is corrupted.  Delete LANMAN\NETPROG\ADDPAK.SER
' and reapply all ADDPAKs.
'

%SERVICE_UIC_M_LAZY            = (%SERVICE_BASE + 41)
'
' The LM386 server cannot be started because CACHE.EXE is not running.
'

%SERVICE_UIC_M_UAS_MACHINE_ACCT= (%SERVICE_BASE + 42)
'
' There is no account for this computer in the security database.
'

%SERVICE_UIC_M_UAS_SERVERS_NMEMB = (%SERVICE_BASE + 43)
'
' This computer is not a member of the group SERVERS.
'

%SERVICE_UIC_M_UAS_SERVERS_NOGRP = (%SERVICE_BASE + 44)
'
' The group SERVERS is not present in the local security database.
'

%SERVICE_UIC_M_UAS_INVALID_ROLE = (%SERVICE_BASE + 45)
'
' This computer is configured as a member of a workgroup, not as
' a member of a domain. The Netlogon service does not need to run in this
' configuration.
'

%SERVICE_UIC_M_NETLOGON_NO_DC  = (%SERVICE_BASE + 46)
'
' The primary Domain Controller for this domain could not be located.
'

%SERVICE_UIC_M_NETLOGON_DC_CFLCT = (%SERVICE_BASE + 47)
'
' This computer is configured to be the primary domain controller of its domain.
' However, the computer %1 is currently claiming to be the primary domain controller
' of the domain.
'

%SERVICE_UIC_M_NETLOGON_AUTH   = (%SERVICE_BASE + 48)
'
' The service failed to authenticate with the primary domain controller.
'

%SERVICE_UIC_M_UAS_PROLOG      = (%SERVICE_BASE + 49)
'
' There is a problem with the security database creation date or serial number.
'


%SERVICE2_BASE  = 5600
' new SEVICE_UIC messages go here

%SERVICE_UIC_M_NETLOGON_MPATH  = (%SERVICE2_BASE + 0)
'
' Could not share the User or Script path.
'

%SERVICE_UIC_M_LSA_MACHINE_ACCT= (%SERVICE2_BASE + 1)
'
' The password for this computer is not found in the local security
' database.
'

%SERVICE_UIC_M_DATABASE_ERROR  = (%SERVICE2_BASE + 2)
'
' An internal error occurred while accessing the computer's
' local or network security database.
'


'
'  End modifiers
'

'
' Commonly used Macros:
'

FUNCTION SERVICE_IP_CODE (BYVAL tt AS LONG, BYVAL nn AS LONG) AS LONG
    SHIFT LEFT tt, %SERVICE_IP_WAITTIME_SHIFT
    FUNCTION = %SERVICE_IP_QUERY_HINT OR nn OR tt
END FUNCTION

FUNCTION SERVICE_CCP_CODE (BYVAL tt AS LONG, BYVAL nn AS LONG) AS LONG
    SHIFT LEFT tt, %SERVICE_IP_WAITTIME_SHIFT
    FUNCTION = %SERVICE_CCP_QUERY_HINT OR nn OR tt
END FUNCTION

FUNCTION SERVICE_UIC_CODE (BYVAL cc AS LONG, BYVAL mm AS LONG) AS LONG
    SHIFT LEFT cc, 16
    FUNCTION = cc OR LO(WORD, mm)
END FUNCTION

'
' This macro takes a wait hint (tt) which can have a maximum value of
' &HFFFF and puts it into the service status code field.
' &H0FF1FFnn  (where nn is the checkpoint information).
'
FUNCTION SERVICE_NT_CCP_CODE (BYVAL tt AS LONG, BYVAL nn AS LONG) AS LONG

    LOCAL t1, t2 AS LONG

    t1 = tt AND %LOWER_HINT_MASK
    SHIFT LEFT t1, %SERVICE_IP_WAITTIME_SHIFT

    t2 = tt AND %UPPER_HINT_MASK
    SHIFT LEFT t2, %SERVICE_NTIP_WAITTIME_SHIFT

    FUNCTION = %SERVICE_CCP_QUERY_HINT OR LO(WORD, nn) OR t1 OR t2

END FUNCTION

'
' This macro takes a status code field, and strips out the wait hint
' from the upper and lower sections.
' &H0FF1FFnn results in &H0000FFFF.
'
FUNCTION SERVICE_NT_WAIT_GET (BYVAL CODE AS LONG) AS LONG

    LOCAL c1, c2 AS LONG

    c1 = CODE AND %UPPER_GET_HINT_MASK
    SHIFT RIGHT c1, %SERVICE_NTIP_WAITTIME_SHIFT

    c2 = CODE AND %LOWER_GET_HINT_MASK
    SHIFT RIGHT c2, %SERVICE_IP_WAITTIME_SHIFT

    FUNCTION = c1 OR c2

END FUNCTION
