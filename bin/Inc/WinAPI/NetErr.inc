'------------------------------------------------------------------------------
'
'  NetErr.inc -- Network Monitor driver network error codes
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from NetErr.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%NMNETERR = 1

'=============================================================================
'  TOKENRING errors
'=============================================================================

%NETERR_RING_STATUS_SIGNAL_LOST         = &H00008000

%NETERR_RING_STATUS_HARD_ERROR          = &H00004000

%NETERR_RING_STATUS_SOFT_ERROR          = &H00002000

%NETERR_RING_STATUS_TRANSMIT_BEACON     = &H00001000

%NETERR_RING_STATUS_LOBE_WIRE_FAULT     = &H00000800

%NETERR_RING_STATUS_AUTO_REMOVAL_ERROR  = &H00000400

%NETERR_RING_STATUS_REMOTE_RECEIVED     = &H00000200

%NETERR_RING_STATUS_COUNTER_OVERFLOW    = &H00000100

%NETERR_RING_STATUS_SIGNAL_STATION      = &H00000080

%NETERR_RING_STATUS_RECOVERY            = &H00000040


'
' The following defines a bit mask to be compared with to see if
' the state of the ring should cause us to stop the current network
' capture.
'
' LobeWireFault, Signal Loss, Remove Received, and Auto Removal are
' currently the ones that fall into this category.
'
%NETERR_RING_STOP_CAPTURE               = &H00008E00


'=============================================================================
'  ETHERNET errors
'=============================================================================

'=============================================================================
'  FDDI errors
'=============================================================================
