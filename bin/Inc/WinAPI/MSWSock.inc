'------------------------------------------------------------------------------
'
'  MsWSock.inc -- Microsoft-specific extensions to the Windows Sockets API.
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from MsWSock.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%MSWSOCK = 1


#INCLUDE "MsWSockDef.inc"
#INCLUDE "WinBase.inc"
#INCLUDE "WinSock2.inc"

'
' Options for connect and disconnect data and options.  Used only by
' non-TCP/IP transports such as DECNet, OSI TP4, etc.
'
%SO_CONNDATA               = &H7000
%SO_CONNOPT                = &H7001
%SO_DISCDATA               = &H7002
%SO_DISCOPT                = &H7003
%SO_CONNDATALEN            = &H7004
%SO_CONNOPTLEN             = &H7005
%SO_DISCDATALEN            = &H7006
%SO_DISCOPTLEN             = &H7007

'
' Option for opening sockets for synchronous access.
'
%SO_OPENTYPE               = &H7008

%SO_SYNCHRONOUS_ALERT      = &H10
%SO_SYNCHRONOUS_NONALERT   = &H20

'
' Other NT-specific options.
'
%SO_MAXDG                  = &H7009
%SO_MAXPATHDG              = &H700A
%SO_UPDATE_ACCEPT_CONTEXT  = &H700B
%SO_CONNECT_TIME           = &H700C
#IF (%WIN32_WINNT >= &H0501)
%SO_UPDATE_CONNECT_CONTEXT = &H7010
#ENDIF  ' (%WIN32_WINNT >= &H0501)

'
' TCP options.
'
%TCP_BSDURGENT             = &H7000

'
' MS Transport Provider IOCTL to control
' reporting PORT_UNREACHABLE messages
' on UDP sockets via recv/WSARecv/etc.
' Path TRUE in input buffer to enable (default if supported),
' FALSE to disable.
'
%SIO_UDP_CONNRESET = &H9800000C???   ' _WSAIOW(IOC_VENDOR,12)


#IF ((%WIN32_WINNT < &H0600) AND (%WIN32_WINNT >= &H0501))

'
' MS Transport Provider IOCTL to request
' notification when a given socket is closed.
' Input buffer must be a pointer to the socket handle.
' Input buffer size must be exactly sizeof(HANDLE).
' Output buffer and output buffer length must be
' %NULL and 0 respectively. This IOCTL must always
' be issued with an overlapped structure.
'
' This Ioctl code is available only on WinXP SP2 and Win2k3 SP1.
'
%SIO_SOCKET_CLOSE_NOTIFY = &H9800000D???   ' _WSAIOW(IOC_VENDOR,13)

#ENDIF '(%WIN32_WINNT < &H0600 AND %WIN32_WINNT >= &H0501)

'
' MS Transport Provider IOCTL to control
' reporting NET_UNREACHABLE (TTL expired) messages
' on UDP sockets via recv/WSARecv/Etc.
' Pass TRUE in input buffer to enabled (default if supported),
' FALSE to disable.
'
%SIO_UDP_NETRESET = &H9800000F???   ' _WSAIOW(IOC_VENDOR,15)

'
' Microsoft extended APIs.
'

DECLARE FUNCTION WSARecvEx LIB "Mswsock.dll" ALIAS "WSARecvEx" ( _
    BYVAL s      AS DWORD, _  ' SOCKET
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG, _
    flags        AS LONG _
    ) AS LONG

TYPE TRANSMIT_FILE_BUFFERS
    Head       AS DWORD  ' VOID PTR
    HeadLength AS DWORD
    Tail       AS DWORD  ' VOID PTR
    TailLength AS DWORD
END TYPE

%TF_DISCONNECT         = &H01
%TF_REUSE_SOCKET       = &H02
%TF_WRITE_BEHIND       = &H04
%TF_USE_DEFAULT_WORKER = &H00
%TF_USE_SYSTEM_THREAD  = &H10
%TF_USE_KERNEL_APC     = &H20

DECLARE FUNCTION TransmitFile LIB "MsWSock.dll" ALIAS "TransmitFile" ( _
    BYVAL hSocket               AS DWORD, _  ' SOCKET
    BYVAL hFile                 AS DWORD, _  ' HANDLE
    BYVAL nNumberOfBytesToWrite AS DWORD, _
    BYVAL nNumberOfBytesToSend  AS DWORD, _
    lpOverlapped                AS OVERLAPPED, _
    lpTransmitBuffers           AS TRANSMIT_FILE_BUFFERS, _
    BYVAL dwReserved            AS DWORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION AcceptEx LIB "MsWSock.dll" ALIAS "AcceptEx" ( _
    BYVAL sListenSocket         AS DWORD, _  ' SOCKET
    BYVAL sAcceptSocket         AS DWORD, _  ' SOCKET
    lpOutputBuffer              AS ANY, _    ' PVOID
    BYVAL dwReceiveDataLength   AS DWORD, _
    BYVAL dwLocalAddressLength  AS DWORD, _
    BYVAL dwRemoteAddressLength AS DWORD, _
    lpdwBytesReceived           AS DWORD, _
    lpOverlapped                AS OVERLAPPED _
    ) AS LONG  ' BOOL

DECLARE SUB GetAcceptExSockaddrs LIB "MsWSock.dll" _
    ALIAS "GetAcceptExSockaddrs" ( _
    lpOutputBuffer              AS ANY, _  ' PVOID
    BYVAL dwReceiveDataLength   AS DWORD, _
    BYVAL dwLocalAddressLength  AS DWORD, _
    BYVAL dwRemoteAddressLength AS DWORD, _
    LocalSockaddr               AS ANY, _  ' sockaddr PTR PTR
    LocalSockaddrLength         AS LONG, _
    RemoteSockaddr              AS ANY, _  ' sockaddr PTR PTR
    RemoveSockaddrLength        AS LONG _
    )

'
' "QueryInterface" versions of the above APIs.
'

DECLARE FUNCTION LPFN_TRANSMITFILE ( _
    BYVAL hSocket AS DWORD, _  ' SOCKET
    BYVAL hFile AS DWORD, _  ' HANDLE
    BYVAL nNumberOfBytesToWrite AS DWORD, _
    BYVAL nNumberOfBytesPerSend AS DWORD, _
    lpOverlapped AS OVERLAPPED, _
    lpTransmitBuffers AS TRANSMIT_FILE_BUFFERS, _
    BYVAL dwReserved AS DWORD _
    ) AS LONG  ' BOOL

$WSAID_TRANSMITFILE = GUID$("{b5367df0-cbac-11cf-95ca-00805f48a192}")

DECLARE FUNCTION LPFN_ACCEPTEX ( _
    BYVAL sListenSocket         AS DWORD, _  ' SOCKET
    BYVAL sAcceptSocket         AS DWORD, _  ' SOCKET
    lpOutputBuffer              AS ANY, _    ' PVOID
    BYVAL dwReceiveDataLength   AS DWORD, _
    BYVAL dwLocalAddressLength  AS DWORD, _
    BYVAL dwRemoteAddressLength AS DWORD, _
    lpdwBytesReceived           AS DWORD, _
    lpOverlapped                AS OVERLAPPED _
    ) AS LONG  ' BOOL

$WSAID_ACCEPTEX = GUID$("{b5367df1-cbac-11cf-95ca-00805f48a192}")

DECLARE SUB LPFN_GETACCEPTEXSOCKADDRS ( _
    lpOutputBuffer              AS ANY, _  ' PVOID
    BYVAL dwReceiveDataLength   AS DWORD, _
    BYVAL dwLocalAddressLength  AS DWORD, _
    BYVAL dwRemoteAddressLength AS DWORD, _
    LocalSockaddr               AS ANY, _  ' sockaddr PTR PTR
    LocalSockaddrLength         AS LONG, _
    RemoteSockaddr              AS ANY, _  ' sockaddr PTR PTR
    RemoteSockaddrLength        AS LONG _
    )

$WSAID_GETACCEPTEXSOCKADDRS = GUID$("{b5367df2-cbac-11cf-95ca-00805f48a192}")

#IF (%WIN32_WINNT >= &H0501)

%TP_ELEMENT_MEMORY = 1
%TP_ELEMENT_FILE   = 2
%TP_ELEMENT_EOP    = 4

TYPE TRANSMIT_PACKETS_ELEMENT_union_type
    nFileOffset AS LARGE_INTEGER
    hFile       AS DWORD  ' HANDLE
END TYPE

UNION TRANSMIT_PACKETS_ELEMENT_union
    TRANSMIT_PACKETS_ELEMENT_union_type
    pBuffer AS DWORD  ' PVOID
END UNION

TYPE TRANSMIT_PACKETS_ELEMENT
    dwElFlags AS DWORD
    cLength   AS DWORD
    TRANSMIT_PACKETS_ELEMENT_union
END TYPE

DECLARE FUNCTION LPFN_TRANSMITPACKETS ( _
    BYVAL hSocket       AS DWORD, _  ' SOCKET
    lpPacketArray       AS TRANSMIT_PACKETS_ELEMENT, _
    BYVAL nElementCount AS DWORD, _
    BYVAL nSendSize     AS DWORD, _
    lpOverlapped        AS OVERLAPPED, _
    BYVAL dwFlags       AS DWORD _
    ) AS LONG  ' BOOL

$WSAID_TRANSMITPACKETS = GUID$("{d9689da0-1f90-11d3-9971-00c04f68c876}")

DECLARE FUNCTION LPFN_CONNECTEX ( _
    BYVAL s                AS DWORD, _  ' SOCKET
    BYVAL sname            AS sockaddr, _
    BYVAL namelen          AS LONG, _
    lpSendBuffer           AS ANY, _    ' PVOID
    BYVAL dwSendDataLength AS DWORD, _
    lpdwBytesSent          AS DWORD, _
    lpOverlapped           AS OVERLAPPED _
    ) AS LONG  ' BOOL

$WSAID_CONNECTEX = GUID$("{25a207b9-ddf3-4660-8ee9-76e58c74063e}")

DECLARE FUNCTION LPFN_DISCONNECTEX ( _
    BYVAL s          AS DWORD, _  ' SOCKET
    lpOverlapped     AS OVERLAPPED, _
    BYVAL dwFlags    AS DWORD, _
    BYVAL dwReserved AS DWORD _
    ) AS LONG  ' BOOL

$WSAID_DISCONNECTEX = GUID$("{7fda2e11-8630-436f-a031-f536a6eec157}")

%DE_REUSE_SOCKET = %TF_REUSE_SOCKET

'
' Network-location awareness -- Name registration values for use
' with WSASetService and other structures.
'

$NLA_NAMESPACE_GUID = GUID$("{6642243A-3BA8-4aa6-BAA5-2E0BD71FDD83}")

$NLA_SERVICE_CLASS_GUID = GUID$("{6642243A-3BA8-4aa6-BAA5-2E0BD71FDD83}")

%NLA_ALLUSERS_NETWORK = &H00000001
%NLA_FRIENDLY_NAME    = &H00000002

MACRO NLA_BLOB_DATA_TYPE_enum=LONG
ENUM NLA_BLOB_DATA_TYPE SINGULAR
    NLA_RAW_DATA
    NLA_INTERFACE
    NLA_802_1X_LOCATION
    NLA_CONNECTIVITY
    NLA_ICS
END ENUM

MACRO NLA_CONNECTIVITY_TYPE_enum=LONG
ENUM NLA_CONNECTIVITY_TYPE SINGULAR
    NLA_NETWORK_AD_HOC
    NLA_NETWORK_MANAGED
    NLA_NETWORK_UNMANAGED
    NLA_NETWORK_UNKNOWN
END ENUM

MACRO NLA_INTERNET_enum=LONG
ENUM NLA_INTERNET SINGULAR
    NLA_INTERNET_UNKNOWN
    NLA_INTERNET_NO
    NLA_INTERNET_YES
END ENUM

TYPE NLA_BLOB_type
    type       AS NLA_BLOB_DATA_TYPE_enum
    dwSize     AS DWORD
    nextOffset AS DWORD
END TYPE

TYPE NLA_BLOB_union_type1
    dwType      AS DWORD
    dwSpeed     AS DWORD
    adapterName AS BYTE
END TYPE

TYPE NLA_BLOB_union_type2
    information AS BYTE
END TYPE

TYPE NLA_BLOB_union_type3
    type     AS NLA_CONNECTIVITY_TYPE_enum
    internet AS NLA_INTERNET_enum
END TYPE

TYPE NLA_BLOB_union_type4
    speed             AS DWORD
    type              AS DWORD
    state             AS DWORD
    machineName       AS WSTRINGZ * 256
    sharedAdapterName AS WSTRINGZ * 256
END TYPE

TYPE NLA_BLOB_union_type5
    remote AS NLA_BLOB_union_type4
END TYPE

UNION NLA_BLOB_union
    ' header.type -> NLA_RAW_DATA
    rawData       AS BYTE

    ' header.type -> NLA_INTERFACE
    interfaceData AS NLA_BLOB_union_type1

    ' header.type -> NLA_802_1X_LOCATION
    locationData  AS NLA_BLOB_union_type2

    ' header.type -> NLA_CONNECTIVITY
    connectivity  AS NLA_BLOB_union_type3

    ' header.type -> NLA_ICS
    ICS           AS NLA_BLOB_union_type5
END UNION

TYPE NLA_BLOB
    header AS NLA_BLOB_type
    data   AS NLA_BLOB_union
END TYPE


'
' WSARecvMsg -- support for receiving ancilliary
' data/control information with a message.
'
DECLARE FUNCTION LPFN_WSARECVMSG ( _
    BYVAL s                   AS DWORD, _  ' SOCKET
    lpMsg                     AS WSAMSG , _
    lpdwNumberOfBytesRecvd    AS DWORD, _
    lpOverlapped              AS WSAOVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD _  ' LPWSAOVERLAPPED_COMPLETION_ROUTINE
    ) AS LONG

$WSAID_WSARECVMSG = GUID$("{f689d7c8-6f1f-436b-8a53-e54fe351c322}")

#ENDIF '(%WIN32_WINNT >= &H0501)


#IF (%WIN32_WINNT >= &H0600)

'
' Ioctl codes for translating socket handles to the base provider handle.
' This is performed to prevent breaking non-IFS LSPs when new Winsock extension
' funtions are added.
'
%SIO_BSP_HANDLE        = &H4800001B  ' _WSAIOR(IOC_WS2,27)
%SIO_BSP_HANDLE_SELECT = &H4800001C  ' _WSAIOR(IOC_WS2,28)
%SIO_BSP_HANDLE_POLL   = &H4800001D  ' _WSAIOR(IOC_WS2,29)

'
' Ioctl code used to translate a socket handle into the base provider's handle.
' This is not used by any Winsock extension function and should not be intercepted
' by Winsock LSPs.
'
%SIO_BASE_HANDLE = &HC8000022???  ' _WSAIOR(IOC_WS2,34)

'
' Ioctl codes for Winsock extension functions.
'
%SIO_EXT_SELECT  = &HC800001E???   ' _WSAIORW(IOC_WS2,30)
%SIO_EXT_POLL    = &HC800001F???   ' _WSAIORW(IOC_WS2,31)
%SIO_EXT_SENDMSG = &HC8000020???   ' _WSAIORW(IOC_WS2,32)

'
' Data structure for passing WSAPoll arugments through WSAIoctl
'
TYPE WSAPOLLDATA
    result     AS LONG
    fds        AS DWORD
    timeout    AS LONG
    fdArray(0) AS WSAPOLLFD
END TYPE


'
' Data structure for passing WSASendMsg arguments through WSAIoctl
'
TYPE WSASENDMSG_type
    lpMsg               AS WSAMSG PTR
    dwFlags             AS DWORD
    lpNumberOfBytesSent AS DWORD PTR
    lpOverlapped        AS WSAOVERLAPPED PTR
    lpCompletionRoutine AS DWORD  ' LPWSAOVERLAPPED_COMPLETION_ROUTINE
END TYPE


'
' WSASendMsg -- send data to a specific destination, with options, using
'    overlapped I/O where applicable.
'
' Valid flags for dwFlags parameter:
'    MSG_DONTROUTE
'    MSG_PARTIAL (a.k.a. MSG_EOR) (only for non-stream sockets)
'    MSG_OOB (only for stream style sockets) (NYI)
'
' Caller must provide either lpOverlapped or lpCompletionRoutine
' or neither (both NULL).
'
DECLARE FUNCTION LPFN_WSASENDMSG ( _
    BYVAL s             AS DWORD, _  ' SOCKET
    lpMsg               AS WSAMSG, _
    BYVAL dwFlags       AS DWORD, _
    lpNumberOfBytesSent AS DWORD, _
    lpOverlapped        AS WSAOVERLAPPED, _
    lpCompletionRoutine AS DWORD _  ' LPWSAOVERLAPPED_COMPLETION_ROUTINE
    ) AS LONG

$WSAID_WSASENDMSG = GUID$("{a441e712-754f-43ca-84a7-0dee44cf606d}")

'
' WSAPoll
'
DECLARE FUNCTION LPFN_WSAPOLL ( _
    fdarray       AS WSAPOLLFD, _
    BYVAL nfds    AS DWORD, _
    BYVAL timeout AS LONG _
    ) AS LONG

$WSAID_WSAPOLL = GUID$("{18C76F85-DC66-4964-972E-23C27238312B}")

#ENDIF ' (%WIN32_WINNT >= &H0600)
