'------------------------------------------------------------------------------
'
'  NB30.inc
'    This module contains the definitions for portable NetBIOS 3.0
'    support.
'
'  Copyright (c) 1997-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from NB30.h dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%NCB_INCLUDED = 1


'****************************************************************
'*                                                              *
'*              Data structure templates                        *
'*                                                              *
'****************************************************************

%NCBNAMSZ     =  16    ' absolute length of a net name
%MAX_LANA     = 254    ' lana's in range 0 to MAX_LANA inclusive

'
' Network Control Block
'

TYPE NCB
    ncb_command  AS BYTE          ' command code
    ncb_retcode  AS BYTE          ' return code
    ncb_lsn      AS BYTE          ' local session number
    ncb_num      AS BYTE          ' number of our network name
    ncb_buffer   AS BYTE PTR      ' address of message buffer
    ncb_length   AS WORD          ' size of message buffer
    ncb_callname AS STRING * %NCBNAMSZ   ' blank-padded name of remote
    ncb_name     AS STRING * %NCBNAMSZ   ' our blank-padded netname
    ncb_rto      AS BYTE          ' rcv timeout/retry count
    ncb_sto      AS BYTE          ' send timeout/sys timeout
    ncb_post     AS DWORD         ' void (CALLBACK *ncb_post)( struct _NCB * ); ' POST routine address
    ncb_lana_num AS BYTE          ' lana (adapter) number
    ncb_cmd_cplt AS BYTE          ' &Hff => commmand pending
#IF %DEF(%WIN64)
    ncb_reserve  AS STRING * 18   ' reserved, used by BIOS
#ELSE
    ncb_reserve  AS STRING * 10   ' reserved, used by BIOS
#ENDIF
    ncb_event    AS DWORD         ' DWORD to Win32 event which
                                  ' will be set to the signalled
                                  ' state when an ASYNCH command
                                  ' completes
END TYPE

'
'  Structure returned to the NCB command NCBASTAT is ADAPTER_STATUS followed
'  by an array of NAME_BUFFER structures.
'

TYPE ADAPTER_STATUS DWORD FILL
    adapter_address   AS STRING * 6
    rev_major         AS BYTE
    reserved0         AS BYTE
    adapter_type      AS BYTE
    rev_minor         AS BYTE
    duration          AS WORD
    frmr_recv         AS WORD
    frmr_xmit         AS WORD

    iframe_recv_err   AS WORD

    xmit_aborts       AS WORD
    xmit_success      AS DWORD
    recv_success      AS DWORD

    iframe_xmit_err   AS WORD

    recv_buff_unavail AS WORD
    t1_timeouts       AS WORD
    ti_timeouts       AS WORD
    reserved1         AS DWORD
    free_ncbs         AS WORD
    max_cfg_ncbs      AS WORD
    max_ncbs          AS WORD
    xmit_buf_unavail  AS WORD
    max_dgram_size    AS WORD
    pending_sess      AS WORD
    max_cfg_sess      AS WORD
    max_sess          AS WORD
    max_sess_pkt_size AS WORD
    name_count        AS WORD
END TYPE

TYPE NAME_BUFFER
    sname      AS STRING * %NCBNAMSZ
    name_num   AS BYTE
    name_flags AS BYTE
END TYPE

'  values for name_flags bits.

%NAME_FLAGS_MASK = &H87?

%GROUP_NAME      = &H80?
%UNIQUE_NAME     = &H00

%REGISTERING     = &H00
%REGISTERED      = &H04
%DEREGISTERED    = &H05
%DUPLICATE       = &H06
%DUPLICATE_DEREG = &H07

'
'  Structure returned to the NCB command NCBSSTAT is SESSION_HEADER followed
'  by an array of SESSION_BUFFER structures. If the NCB_NAME starts with an
'  asterisk then an array of these structures is returned containing the
'  status for all names.
'

TYPE SESSION_HEADER
    sess_name           AS BYTE
    num_sess            AS BYTE
    rcv_dg_outstanding  AS BYTE
    rcv_any_outstanding AS BYTE
END TYPE

TYPE SESSION_BUFFER
    lsn               AS BYTE
    state             AS BYTE
    local_name        AS STRING * %NCBNAMSZ
    remote_name       AS STRING * %NCBNAMSZ
    rcvs_outstanding  AS BYTE
    sends_outstanding AS BYTE
END TYPE

'  Values for state

%LISTEN_OUTSTANDING    = &H01
%CALL_PENDING          = &H02
%SESSION_ESTABLISHED   = &H03
%HANGUP_PENDING        = &H04
%HANGUP_COMPLETE       = &H05
%SESSION_ABORTED       = &H06

'
'  Structure returned to the NCB command NCBENUM.
'
'  On a system containing lana's 0, 2 and 3, a structure with
'  length =3, lana[0]=0, lana[1]=2 and lana[2]=3 will be returned.
'

TYPE LANA_ENUM
    length          AS BYTE    '  Number of valid entries in lana()
    lana(%MAX_LANA) AS BYTE
END TYPE

'
'  Structure returned to the NCB command NCBFINDNAME is FIND_NAME_HEADER followed
'  by an array of FIND_NAME_BUFFER structures.
'

TYPE FIND_NAME_HEADER
    node_count   AS DWORD
    reserved     AS BYTE
    unique_group AS BYTE
END TYPE

TYPE FIND_NAME_BUFFER DWORD FILL
    length           AS BYTE
    access_control   AS BYTE
    frame_control    AS BYTE
    destination_addr AS STRING * 6
    source_addr      AS STRING * 6
    routing_info     AS STRING * 18
END TYPE

'
'  Structure provided with NCBACTION. The purpose of NCBACTION is to provide
'  transport specific extensions to netbios.
'

TYPE ACTION_HEADER
    transport_id AS DWORD
    action_code  AS WORD
    reserved     AS WORD
END TYPE

'  Values for transport_id

$ALL_TRANSPORTS = "M\0\0\0"
$MS_NBF         = "MNBF"


'****************************************************************
'*                                                              *
'*              Special values and constants                    *
'*                                                              *
'****************************************************************

'
'      NCB Command codes
'

%NCBCALL         = &H10            ' NCB CALL
%NCBLISTEN       = &H11            ' NCB LISTEN
%NCBHANGUP       = &H12            ' NCB HANG UP
%NCBSEND         = &H14            ' NCB SEND
%NCBRECV         = &H15            ' NCB RECEIVE
%NCBRECVANY      = &H16            ' NCB RECEIVE ANY
%NCBCHAINSEND    = &H17            ' NCB CHAIN SEND
%NCBDGSEND       = &H20            ' NCB SEND DATAGRAM
%NCBDGRECV       = &H21            ' NCB RECEIVE DATAGRAM
%NCBDGSENDBC     = &H22            ' NCB SEND BROADCAST DATAGRAM
%NCBDGRECVBC     = &H23            ' NCB RECEIVE BROADCAST DATAGRAM
%NCBADDNAME      = &H30            ' NCB ADD NAME
%NCBDELNAME      = &H31            ' NCB DELETE NAME
%NCBRESET        = &H32            ' NCB RESET
%NCBASTAT        = &H33            ' NCB ADAPTER STATUS
%NCBSSTAT        = &H34            ' NCB SESSION STATUS
%NCBCANCEL       = &H35            ' NCB CANCEL
%NCBADDGRNAME    = &H36            ' NCB ADD GROUP NAME
%NCBENUM         = &H37            ' NCB ENUMERATE LANA NUMBERS
%NCBUNLINK       = &H70            ' NCB UNLINK
%NCBSENDNA       = &H71            ' NCB SEND NO ACK
%NCBCHAINSENDNA  = &H72            ' NCB CHAIN SEND NO ACK
%NCBLANSTALERT   = &H73            ' NCB LAN STATUS ALERT
%NCBACTION       = &H77            ' NCB ACTION
%NCBFINDNAME     = &H78            ' NCB FIND NAME
%NCBTRACE        = &H79            ' NCB TRACE


%ASYNCH          = &H80?           ' high bit set == asynchronous

'
'      NCB Return codes
'

%NRC_GOODRET     = &H00    ' good return
                                ' also returned when ASYNCH request accepted
%NRC_BUFLEN      = &H01    ' illegal buffer length
%NRC_ILLCMD      = &H03    ' illegal command
%NRC_CMDTMO      = &H05    ' command timed out
%NRC_INCOMP      = &H06    ' message incomplete, issue another command
%NRC_BADDR       = &H07    ' illegal buffer address
%NRC_SNUMOUT     = &H08    ' session number out of range
%NRC_NORES       = &H09    ' no resource available
%NRC_SCLOSED     = &H0a    ' session closed
%NRC_CMDCAN      = &H0b    ' command cancelled
%NRC_DUPNAME     = &H0d    ' duplicate name
%NRC_NAMTFUL     = &H0e    ' name table full
%NRC_ACTSES      = &H0f    ' no deletions, name has active sessions
%NRC_LOCTFUL     = &H11    ' local session table full
%NRC_REMTFUL     = &H12    ' remote session table full
%NRC_ILLNN       = &H13    ' illegal name number
%NRC_NOCALL      = &H14    ' no callname
%NRC_NOWILD      = &H15    ' cannot put * in NCB_NAME
%NRC_INUSE       = &H16    ' name in use on remote adapter
%NRC_NAMERR      = &H17    ' name deleted
%NRC_SABORT      = &H18    ' session ended abnormally
%NRC_NAMCONF     = &H19    ' name conflict detected
%NRC_IFBUSY      = &H21    ' interface busy, IRET before retrying
%NRC_TOOMANY     = &H22    ' too many commands outstanding, retry later
%NRC_BRIDGE      = &H23    ' ncb_lana_num field invalid
%NRC_CANOCCR     = &H24    ' command completed while cancel occurring
%NRC_CANCEL      = &H26    ' command not valid to cancel
%NRC_DUPENV      = &H30    ' name defined by anther local process
%NRC_ENVNOTDEF   = &H34    ' environment undefined. RESET required
%NRC_OSRESNOTAV  = &H35    ' required OS resources exhausted
%NRC_MAXAPPS     = &H36    ' max number of applications exceeded
%NRC_NOSAPS      = &H37    ' no saps available for netbios
%NRC_NORESOURCES = &H38    ' requested resources are not available
%NRC_INVADDRESS  = &H39    ' invalid ncb address or length > segment
%NRC_INVDDID     = &H3B    ' invalid NCB DDID
%NRC_LOCKFAIL    = &H3C    ' lock of user area failed
%NRC_OPENERR     = &H3f    ' NETBIOS not loaded
%NRC_SYSTEM      = &H40    ' system error

%NRC_PENDING     = &Hff?   ' asynchronous command is not yet finished

'****************************************************************
'*                                                              *
'*              main user entry point for NetBIOS 3.0           *
'*                                                              *
'* Usage: result = Netbios( pncb );                             *
'****************************************************************

DECLARE FUNCTION Netbios LIB "NetApi32.dll" ALIAS "Netbios" _
    (pncb AS NCB) AS BYTE
