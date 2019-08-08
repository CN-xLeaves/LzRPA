'------------------------------------------------------------------------------
'
'  IfMib.inc
'    This module contains the public definitions and structures for the
'    non-TCP/IP-specific parts of MIB-II.  These definitions were previously
'    in iprtrmib.h, which now #includes this file.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from IfMib.h of 14 Jul 2009
'------------------------------------------------------------------------------
'  NOTE: before including this file, use #INCLUDE "Win32Api.inc"
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%IFMIB = 1

#INCLUDE "ifdef.inc"

#IF NOT %DEF(%ANY_SIZE)
%ANY_SIZE = 1
#ENDIF

TYPE MIB_IFNUMBER
    dwValue AS DWORD
END TYPE


'
' $REVIEW: This has always been defined as 8.  However, this is not
' sufficient for all media types.
'
%MAXLEN_PHYSADDR = 8

%MAXLEN_IFDESCR = 256

%MAX_INTERFACE_NAME_LEN = 256

TYPE MIB_IFROW
    wszName           AS WSTRINGZ * %MAX_INTERFACE_NAME_LEN
    dwIndex           AS IF_INDEX
    dwType            AS IFTYPE
    dwMtu             AS DWORD
    dwSpeed           AS DWORD
    dwPhysAddrLen     AS DWORD
    bPhysAddr(%MAXLEN_PHYSADDR-1) AS BYTE
    dwAdminStatus     AS DWORD
    dwOperStatus      AS INTERNAL_IF_OPER_STATUS_enum
    dwLastChange      AS DWORD
    dwInOctets        AS DWORD
    dwInUcastPkts     AS DWORD
    dwInNUcastPkts    AS DWORD
    dwInDiscards      AS DWORD
    dwInErrors        AS DWORD
    dwInUnknownProtos AS DWORD
    dwOutOctets       AS DWORD
    dwOutUcastPkts    AS DWORD
    dwOutNUcastPkts   AS DWORD
    dwOutDiscards     AS DWORD
    dwOutErrors       AS DWORD
    dwOutQLen         AS DWORD
    dwDescrLen        AS DWORD
    bDescr(%MAXLEN_IFDESCR-1) AS BYTE
END TYPE

TYPE MIB_IFTABLE
    dwNumEntries      AS DWORD
    table(%ANY_SIZE-1) AS MIB_IFROW
END TYPE

'#define SIZEOF_IFTABLE(X) (FIELD_OFFSET(MIB_IFTABLE,table[0]) + \
'                           ((X) * sizeof(MIB_IFROW)) + ALIGN_SIZE)

