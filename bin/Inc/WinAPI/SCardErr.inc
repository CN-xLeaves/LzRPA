'------------------------------------------------------------------------------
'
'  SCardErr.inc -- Error message codes from the Smart Card Resource Manager
'
'  Copyright (c) 2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 18 Feb 2011
'
'------------------------------------------------------------------------------
'  from SCardErr.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

#INCLUDE "WinError.inc"

'
' =============================
' Facility SCARD Error Messages
' =============================
'
%SCARD_S_SUCCESS = %NO_ERROR
'
'  Values are 32 bit values laid out as follows:
'
'   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
'   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'  +---+-+-+-----------------------+-------------------------------+
'  |Sev|C|R|     Facility          |               Code            |
'  +---+-+-+-----------------------+-------------------------------+
'
'  where
'
'      Sev - is the severity code
'
'          00 - Success
'          01 - Informational
'          10 - Warning
'          11 - Error
'
'      C - is the Customer code flag
'
'      R - is a reserved bit
'
'      Facility - is the facility code
'
'      Code - is the facility's status code
'
'
' Define the facility codes
'
%FACILITY_SYSTEM                 = &H0
%FACILITY_SCARD                  = &H10


'
' Define the severity codes
'
%STATUS_SEVERITY_WARNING         = &H2
%STATUS_SEVERITY_INFORMATIONAL   = &H1
%STATUS_SEVERITY_ERROR           = &H3


'
' MessageId: SCARD_F_INTERNAL_ERROR
'
' MessageText:
'
' An internal consistency check failed.
'
%SCARD_F_INTERNAL_ERROR           = &H80100001

'
' MessageId: SCARD_E_CANCELLED
'
' MessageText:
'
' The action was cancelled by an SCardCancel request.
'
%SCARD_E_CANCELLED                = &H80100002

'
' MessageId: SCARD_E_INVALID_HANDLE
'
' MessageText:
'
' The supplied handle was invalid.
'
%SCARD_E_INVALID_HANDLE           = &H80100003

'
' MessageId: SCARD_E_INVALID_PARAMETER
'
' MessageText:
'
' One or more of the supplied parameters could not be properly interpreted.
'
%SCARD_E_INVALID_PARAMETER        = &H80100004

'
' MessageId: SCARD_E_INVALID_TARGET
'
' MessageText:
'
' Registry startup information is missing or invalid.
'
%SCARD_E_INVALID_TARGET           = &H80100005

'
' MessageId: SCARD_E_NO_MEMORY
'
' MessageText:
'
' Not enough memory available to complete this command.
'
%SCARD_E_NO_MEMORY                = &H80100006

'
' MessageId: SCARD_F_WAITED_TOO_LONG
'
' MessageText:
'
' An internal consistency timer has expired.
'
%SCARD_F_WAITED_TOO_LONG          = &H80100007

'
' MessageId: SCARD_E_INSUFFICIENT_BUFFER
'
' MessageText:
'
' The data buffer to receive returned data is too small for the returned data.
'
%SCARD_E_INSUFFICIENT_BUFFER      = &H80100008

'
' MessageId: SCARD_E_UNKNOWN_READER
'
' MessageText:
'
' The specified reader name is not recognized.
'
%SCARD_E_UNKNOWN_READER           = &H80100009

'
' MessageId: SCARD_E_TIMEOUT
'
' MessageText:
'
' The user-specified timeout value has expired.
'
%SCARD_E_TIMEOUT                  = &H8010000A

'
' MessageId: SCARD_E_SHARING_VIOLATION
'
' MessageText:
'
' The smart card cannot be accessed because of other connections outstanding.
'
%SCARD_E_SHARING_VIOLATION        = &H8010000B

'
' MessageId: SCARD_E_NO_SMARTCARD
'
' MessageText:
'
' The operation requires a Smart Card, but no Smart Card is currently in the device.
'
%SCARD_E_NO_SMARTCARD             = &H8010000C

'
' MessageId: SCARD_E_UNKNOWN_CARD
'
' MessageText:
'
' The specified smart card name is not recognized.
'
%SCARD_E_UNKNOWN_CARD             = &H8010000D

'
' MessageId: SCARD_E_CANT_DISPOSE
'
' MessageText:
'
' The system could not dispose of the media in the requested manner.
'
%SCARD_E_CANT_DISPOSE             = &H8010000E

'
' MessageId: SCARD_E_PROTO_MISMATCH
'
' MessageText:
'
' The requested protocols are incompatible with the protocol currently in use with the smart card.
'
%SCARD_E_PROTO_MISMATCH           = &H8010000F

'
' MessageId: SCARD_E_NOT_READY
'
' MessageText:
'
' The reader or smart card is not ready to accept commands.
'
%SCARD_E_NOT_READY                = &H80100010

'
' MessageId: SCARD_E_INVALID_VALUE
'
' MessageText:
'
' One or more of the supplied parameters values could not be properly interpreted.
'
%SCARD_E_INVALID_VALUE            = &H80100011

'
' MessageId: SCARD_E_SYSTEM_CANCELLED
'
' MessageText:
'
' The action was cancelled by the system, presumably to log off or shut down.
'
%SCARD_E_SYSTEM_CANCELLED         = &H80100012

'
' MessageId: SCARD_F_COMM_ERROR
'
' MessageText:
'
' An internal communications error has been detected.
'
%SCARD_F_COMM_ERROR               = &H80100013

'
' MessageId: SCARD_F_UNKNOWN_ERROR
'
' MessageText:
'
' An internal error has been detected, but the source is unknown.
'
%SCARD_F_UNKNOWN_ERROR            = &H80100014

'
' MessageId: SCARD_E_INVALID_ATR
'
' MessageText:
'
' An ATR obtained from the registry is not a valid ATR string.
'
%SCARD_E_INVALID_ATR              = &H80100015

'
' MessageId: SCARD_E_NOT_TRANSACTED
'
' MessageText:
'
' An attempt was made to end a non-existent transaction.
'
%SCARD_E_NOT_TRANSACTED           = &H80100016

'
' MessageId: SCARD_E_READER_UNAVAILABLE
'
' MessageText:
'
' The specified reader is not currently available for use.
'
%SCARD_E_READER_UNAVAILABLE       = &H80100017

'
' MessageId: SCARD_P_SHUTDOWN
'
' MessageText:
'
' The operation has been aborted to allow the server application to exit.
'
%SCARD_P_SHUTDOWN                 = &H80100018

'
' MessageId: SCARD_E_PCI_TOO_SMALL
'
' MessageText:
'
' The PCI Receive buffer was too small.
'
%SCARD_E_PCI_TOO_SMALL            = &H80100019

'
' MessageId: SCARD_E_READER_UNSUPPORTED
'
' MessageText:
'
' The reader driver does not meet minimal requirements for support.
'
%SCARD_E_READER_UNSUPPORTED       = &H8010001A

'
' MessageId: SCARD_E_DUPLICATE_READER
'
' MessageText:
'
' The reader driver did not produce a unique reader name.
'
%SCARD_E_DUPLICATE_READER         = &H8010001B

'
' MessageId: SCARD_E_CARD_UNSUPPORTED
'
' MessageText:
'
' The smart card does not meet minimal requirements for support.
'
%SCARD_E_CARD_UNSUPPORTED         = &H8010001C

'
' MessageId: SCARD_E_NO_SERVICE
'
' MessageText:
'
' The Smart card resource manager is not running.
'
%SCARD_E_NO_SERVICE               = &H8010001D

'
' MessageId: SCARD_E_SERVICE_STOPPED
'
' MessageText:
'
' The Smart card resource manager has shut down.
'
%SCARD_E_SERVICE_STOPPED          = &H8010001E

'
' MessageId: SCARD_E_UNEXPECTED
'
' MessageText:
'
' An unexpected card error has occurred.
'
%SCARD_E_UNEXPECTED               = &H8010001F

'
' MessageId: SCARD_E_ICC_INSTALLATION
'
' MessageText:
'
' No Primary Provider can be found for the smart card.
'
%SCARD_E_ICC_INSTALLATION         = &H80100020

'
' MessageId: SCARD_E_ICC_CREATEORDER
'
' MessageText:
'
' The requested order of object creation is not supported.
'
%SCARD_E_ICC_CREATEORDER          = &H80100021

'
' MessageId: SCARD_E_UNSUPPORTED_FEATURE
'
' MessageText:
'
' This smart card does not support the requested feature.
'
%SCARD_E_UNSUPPORTED_FEATURE      = &H80100022

'
' MessageId: SCARD_E_DIR_NOT_FOUND
'
' MessageText:
'
' The identified directory does not exist in the smart card.
'
%SCARD_E_DIR_NOT_FOUND            = &H80100023

'
' MessageId: SCARD_E_FILE_NOT_FOUND
'
' MessageText:
'
' The identified file does not exist in the smart card.
'
%SCARD_E_FILE_NOT_FOUND           = &H80100024

'
' MessageId: SCARD_E_NO_DIR
'
' MessageText:
'
' The supplied path does not represent a smart card directory.
'
%SCARD_E_NO_DIR                   = &H80100025

'
' MessageId: SCARD_E_NO_FILE
'
' MessageText:
'
' The supplied path does not represent a smart card file.
'
%SCARD_E_NO_FILE                  = &H80100026

'
' MessageId: SCARD_E_NO_ACCESS
'
' MessageText:
'
' Access is denied to this file.
'
%SCARD_E_NO_ACCESS                = &H80100027

'
' MessageId: SCARD_E_WRITE_TOO_MANY
'
' MessageText:
'
' The smartcard does not have enough memory to store the information.
'
%SCARD_E_WRITE_TOO_MANY           = &H80100028

'
' MessageId: SCARD_E_BAD_SEEK
'
' MessageText:
'
' There was an error trying to set the smart card file object pointer.
'
%SCARD_E_BAD_SEEK                 = &H80100029

'
' MessageId: SCARD_E_INVALID_CHV
'
' MessageText:
'
' The supplied PIN is incorrect.
'
%SCARD_E_INVALID_CHV              = &H8010002A

'
' MessageId: SCARD_E_UNKNOWN_RES_MNG
'
' MessageText:
'
' An unrecognized error code was returned from a layered component.
'
%SCARD_E_UNKNOWN_RES_MNG          = &H8010002B

'
' MessageId: SCARD_E_NO_SUCH_CERTIFICATE
'
' MessageText:
'
' The requested certificate does not exist.
'
%SCARD_E_NO_SUCH_CERTIFICATE      = &H8010002C

'
' MessageId: SCARD_E_CERTIFICATE_UNAVAILABLE
'
' MessageText:
'
' The requested certificate could not be obtained.
'
%SCARD_E_CERTIFICATE_UNAVAILABLE  = &H8010002D

'
' MessageId: SCARD_E_NO_READERS_AVAILABLE
'
' MessageText:
'
' Cannot find a smart card reader.
'
%SCARD_E_NO_READERS_AVAILABLE     = &H8010002E

'
' MessageId: SCARD_E_COMM_DATA_LOST
'
' MessageText:
'
' A communications error with the smart card has been detected.  Retry the operation.
'
%SCARD_E_COMM_DATA_LOST           = &H8010002F

'
' MessageId: SCARD_E_NO_KEY_CONTAINER
'
' MessageText:
'
' The requested key container does not exist on the smart card.
'
%SCARD_E_NO_KEY_CONTAINER         = &H80100030

'
' MessageId: SCARD_E_SERVER_TOO_BUSY
'
' MessageText:
'
' The Smart card resource manager is too busy to complete this operation.
'
%SCARD_E_SERVER_TOO_BUSY          = &H80100031

'
' MessageId: SCARD_E_PIN_CACHE_EXPIRED
'
' MessageText:
'
' The smart card PIN cache has expired.
'
%SCARD_E_PIN_CACHE_EXPIRED        = &H80100032

'
' MessageId: SCARD_E_NO_PIN_CACHE
'
' MessageText:
'
' The smart card PIN cannot be cached.
'
%SCARD_E_NO_PIN_CACHE             = &H80100033

'
' MessageId: SCARD_E_READ_ONLY_CARD
'
' MessageText:
'
' The smart card is read only and cannot be written to.
'
%SCARD_E_READ_ONLY_CARD           = &H80100034

'
' These are warning codes.
'
'
' MessageId: SCARD_W_UNSUPPORTED_CARD
'
' MessageText:
'
' The reader cannot communicate with the smart card, due to ATR configuration conflicts.
'
%SCARD_W_UNSUPPORTED_CARD         = &H80100065

'
' MessageId: SCARD_W_UNRESPONSIVE_CARD
'
' MessageText:
'
' The smart card is not responding to a reset.
'
%SCARD_W_UNRESPONSIVE_CARD        = &H80100066

'
' MessageId: SCARD_W_UNPOWERED_CARD
'
' MessageText:
'
' Power has been removed from the smart card, so that further communication is not possible.
'
%SCARD_W_UNPOWERED_CARD           = &H80100067

'
' MessageId: SCARD_W_RESET_CARD
'
' MessageText:
'
' The smart card has been reset, so any shared state information is invalid.
'
%SCARD_W_RESET_CARD               = &H80100068

'
' MessageId: SCARD_W_REMOVED_CARD
'
' MessageText:
'
' The smart card has been removed, so that further communication is not possible.
'
%SCARD_W_REMOVED_CARD             = &H80100069

'
' MessageId: SCARD_W_SECURITY_VIOLATION
'
' MessageText:
'
' Access was denied because of a security violation.
'
%SCARD_W_SECURITY_VIOLATION       = &H8010006A

'
' MessageId: SCARD_W_WRONG_CHV
'
' MessageText:
'
' The card cannot be accessed because the wrong PIN was presented.
'
%SCARD_W_WRONG_CHV                = &H8010006B

'
' MessageId: SCARD_W_CHV_BLOCKED
'
' MessageText:
'
' The card cannot be accessed because the maximum number of PIN entry attempts has been reached.
'
%SCARD_W_CHV_BLOCKED              = &H8010006C

'
' MessageId: SCARD_W_EOF
'
' MessageText:
'
' The end of the smart card file has been reached.
'
%SCARD_W_EOF                      = &H8010006D

'
' MessageId: SCARD_W_CANCELLED_BY_USER
'
' MessageText:
'
' The action was cancelled by the user.
'
%SCARD_W_CANCELLED_BY_USER        = &H8010006E

'
' MessageId: SCARD_W_CARD_NOT_AUTHENTICATED
'
' MessageText:
'
' No PIN was presented to the smart card.
'
%SCARD_W_CARD_NOT_AUTHENTICATED   = &H8010006F

'
' MessageId: SCARD_W_CACHE_ITEM_NOT_FOUND
'
' MessageText:
'
' The requested item could not be found in the cache.
'
%SCARD_W_CACHE_ITEM_NOT_FOUND     = &H80100070

'
' MessageId: SCARD_W_CACHE_ITEM_STALE
'
' MessageText:
'
' The requested cache item is too old and was deleted from the cache.
'
%SCARD_W_CACHE_ITEM_STALE         = &H80100071

'
' MessageId: SCARD_W_CACHE_ITEM_TOO_BIG
'
' MessageText:
'
' The new cache item exceeds the maximum per-item size defined for the cache.
'
%SCARD_W_CACHE_ITEM_TOO_BIG       = &H80100072
