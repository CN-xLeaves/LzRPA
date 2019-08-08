'------------------------------------------------------------------------------
'
'  ASFErr.inc -- definition of ASF HRESULT codes
'
'  Copyright (c) 2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 17 Mar 2011
'
'------------------------------------------------------------------------------
'  from ASFErr.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%ASFERR_H = 1


#IF NOT %DEF(%STATUS_SEVERITY_macro)
%STATUS_SEVERITY_macro = 1
MACRO FUNCTION STATUS_SEVERITY(hr)
    MACROTEMP dTemp
    LOCAL dTemp AS DWORD
    dTemp = (hr)
    SHIFT RIGHT dTemp, 30
END MACRO=(dTemp AND 3)
#ENDIF



'-------------------------------------------------------------------------
'
' Advanced Streaming Format (ASF) Errors (2000 - 2999)
'
'
'  Values are 32 bit values layed out as follows:
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
%FACILITY_NS                    = &HD


'
' Define the severity codes
'
%STATUS_SEVERITY_WARNING        = &H2
%STATUS_SEVERITY_SUCCESS        = &H0
%STATUS_SEVERITY_INFORMATIONAL  = &H1
%STATUS_SEVERITY_ERROR          = &H3


'
' MessageId: ASF_E_BUFFEROVERRUN
'
' MessageText:
'
'  An attempt was made to seek or position past the end of a buffer.%0
'
%ASF_E_BUFFEROVERRUN              = &HC00D07D0&

'
' MessageId: ASF_E_BUFFERTOOSMALL
'
' MessageText:
'
'  The supplied input or output buffer was too small.%0
'
%ASF_E_BUFFERTOOSMALL             = &HC00D07D1&

'
' MessageId: ASF_E_BADLANGUAGEID
'
' MessageText:
'
'  The language ID was not found.%0
'
%ASF_E_BADLANGUAGEID              = &HC00D07D2&

'
' MessageId: ASF_E_NOPAYLOADLENGTH
'
' MessageText:
'
'  The multiple payload packet is missing the payload length.%0
'
%ASF_E_NOPAYLOADLENGTH            = &HC00D07DB&

'
' MessageId: ASF_E_TOOMANYPAYLOADS
'
' MessageText:
'
'  The packet contains too many payloads.%0
'
%ASF_E_TOOMANYPAYLOADS            = &HC00D07DC&

'
' MessageId: ASF_E_PACKETCONTENTTOOLARGE
'
' MessageText:
'
'  ASF_E_PACKETCONTENTTOOLARGE
'
%ASF_E_PACKETCONTENTTOOLARGE      = &HC00D07DE&

'
' MessageId: ASF_E_UNKNOWNPACKETSIZE
'
' MessageText:
'
'  Expecting a fixed packet size but min. and max. are not equal.%0
'
%ASF_E_UNKNOWNPACKETSIZE          = &HC00D07E0&

'
' MessageId: ASF_E_INVALIDHEADER
'
' MessageText:
'
'  ASF_E_INVALIDHEADER
'
%ASF_E_INVALIDHEADER              = &HC00D07E2&

'
' MessageId: ASF_E_NOCLOCKOBJECT
'
' MessageText:
'
'  The object does not have a valid clock object.%0
'
%ASF_E_NOCLOCKOBJECT              = &HC00D07E6&

'
' MessageId: ASF_E_UNKNOWNCLOCKTYPE
'
' MessageText:
'
'  ASF_E_UNKNOWNCLOCKTYPE
'
%ASF_E_UNKNOWNCLOCKTYPE           = &HC00D07EB&

'
' MessageId: ASF_E_OPAQUEPACKET
'
' MessageText:
'
'  An attempt was made to restore or access an opaque packet.%0
'
%ASF_E_OPAQUEPACKET               = &HC00D07ED&

'
' MessageId: ASF_E_WRONGVERSION
'
' MessageText:
'
'  ASF_E_WRONGVERSION
'
%ASF_E_WRONGVERSION               = &HC00D07EE&

'
' MessageId: ASF_E_OVERFLOW
'
' MessageText:
'
'  An attempt was made to store a value which was larger than then destination's maximum value.%0
'
%ASF_E_OVERFLOW                   = &HC00D07EF&

'
' MessageId: ASF_E_NOTFOUND
'
' MessageText:
'
'  The object was not found.%0
'
%ASF_E_NOTFOUND                   = &HC00D07F0&

'
' Someone else is using MessageIds 2033 & 2034, so we skip them
'
' 2033 = NS_E_NOTHING_TO_DO
' 2034 = NS_E_NO_MULTICAST

'
' MessageId: ASF_E_OBJECTTOOBIG
'
' MessageText:
'
'  The object is too large to be processed in the requested manner.%0
'
%ASF_E_OBJECTTOOBIG               = &HC00D07F3&

'
' MessageId: ASF_E_UNEXPECTEDVALUE
'
' MessageText:
'
'  A value was not set as expected.%0
'
%ASF_E_UNEXPECTEDVALUE            = &HC00D07F4&

'
' MessageId: ASF_E_INVALIDSTATE
'
' MessageText:
'
'  The request is not valid in the object's current state.%0
'
%ASF_E_INVALIDSTATE               = &HC00D07F5&

'
' MessageId: ASF_E_NOLIBRARY
'
' MessageText:
'
'  This object does not have a valid library pointer; it was not properly created or it has been Shutdown().%0
'
%ASF_E_NOLIBRARY                  = &HC00D07F6&

'
' MessageId: ASF_E_ALREADYINITIALIZED
'
' MessageText:
'
'  This object has already been initialized; the setting cannot be changed.%0
'
%ASF_E_ALREADYINITIALIZED         = &HC00D07F7&

'
' MessageId: ASF_E_INVALIDINIT
'
' MessageText:
'
'  This object has not been initialized properly; that operation cannot be performed.%0
'
%ASF_E_INVALIDINIT                = &HC00D07F8&

'
' MessageId: ASF_E_NOHEADEROBJECT
'
' MessageText:
'
'  The ASF Header object could not be found.%0
'
%ASF_E_NOHEADEROBJECT             = &HC00D07F9&

'
' MessageId: ASF_E_NODATAOBJECT
'
' MessageText:
'
'  The ASF Data object could not be found.%0
'
%ASF_E_NODATAOBJECT               = &HC00D07FA&

'
' MessageId: ASF_E_NOINDEXOBJECT
'
' MessageText:
'
'  The ASF Index object could not be found.%0
'
%ASF_E_NOINDEXOBJECT              = &HC00D07FB&

'
' MessageId: ASF_E_NOSTREAMPROPS
'
' MessageText:
'
'  A Stream Properties object with the correct stream number could not be found.%0
'
%ASF_E_NOSTREAMPROPS              = &HC00D07FC&

'
' MessageId: ASF_E_NOFILEPROPS
'
' MessageText:
'
'  The File Properties object could not be found.%0
'
%ASF_E_NOFILEPROPS                = &HC00D07FD&

'
' MessageId: ASF_E_NOLANGUAGELIST
'
' MessageText:
'
'  The Language List object could not be found.%0
'
%ASF_E_NOLANGUAGELIST             = &HC00D07FE&

'
' MessageId: ASF_E_NOINDEXPARAMETERS
'
' MessageText:
'
'  The Index Parameters object could not be found.%0
'
%ASF_E_NOINDEXPARAMETERS          = &HC00D07FF&

'
' MessageId: ASF_E_UNSUPPORTEDERRORCONCEALMENT
'
' MessageText:
'
'  The requested error concealment strategy is not supported by this component.%0
'
%ASF_E_UNSUPPORTEDERRORCONCEALMENT = &HC00D0800&

'
' MessageId: ASF_E_INVALIDFLAGS
'
' MessageText:
'
'  The flags for this object or set of objects are not properly set.%0
'
%ASF_E_INVALIDFLAGS               = &HC00D0801&

'
' MessageId: ASF_E_BADDATADESCRIPTOR
'
' MessageText:
'
'  One or more data descriptors is not properly set.%0
'
%ASF_E_BADDATADESCRIPTOR          = &HC00D0802&

'
' MessageId: ASF_E_BADINDEXINTERVAL
'
' MessageText:
'
'  The index has an invalid time interval (probably zero).%0
'
%ASF_E_BADINDEXINTERVAL           = &HC00D0803&

'
' MessageId: ASF_E_INVALIDTIME
'
' MessageText:
'
'  The given time value is not valid.%0
'
%ASF_E_INVALIDTIME                = &HC00D0804&

'
' MessageId: ASF_E_INVALIDINDEX
'
' MessageText:
'
'  The given index value is not valid.%0
'
%ASF_E_INVALIDINDEX               = &HC00D0805&

'
' MessageId: ASF_E_STREAMNUMBERINUSE
'
' MessageText:
'
'  The specified stream number is already in use.%0
'
%ASF_E_STREAMNUMBERINUSE          = &HC00D0806&

'
' MessageId: ASF_E_BADMEDIATYPE
'
' MessageText:
'
'  The specified media type does not work with this component.%0
'
%ASF_E_BADMEDIATYPE               = &HC00D0807&

'
' MessageId: ASF_E_WRITEFAILED
'
' MessageText:
'
'  The object could not be written as specified.%0
'
%ASF_E_WRITEFAILED                = &HC00D0808&

'
' MessageId: ASF_E_NOTENOUGHDESCRIPTORS
'
' MessageText:
'
'  The given data unit requires a larger number of descriptors to be fully parsed.%0
'
%ASF_E_NOTENOUGHDESCRIPTORS       = &HC00D0809&

'
' MessageId: ASF_E_INDEXBLOCKUNLOADED
'
' MessageText:
'
'  The index entries for the specified index block have been unloaded from memory and are not available.%0
'
%ASF_E_INDEXBLOCKUNLOADED         = &HC00D080A&

'
' MessageId: ASF_E_NOTENOUGHBANDWIDTH
'
' MessageText:
'
'  The specified bandwidth is not large enough.%0
'
%ASF_E_NOTENOUGHBANDWIDTH         = &HC00D080B&

'
' MessageId: ASF_E_EXCEEDEDMAXIMUMOBJECTSIZE
'
' MessageText:
'
'  The object has exceeded its maximum size.%0
'
%ASF_E_EXCEEDEDMAXIMUMOBJECTSIZE  = &HC00D080C&

'
' MessageId: ASF_E_BADDATAUNIT
'
' MessageText:
'
'  The given data unit is corrupted, badly formatted, or otherwise not valid.%0
'
%ASF_E_BADDATAUNIT                = &HC00D080D&

'
' MessageId: ASF_E_HEADERSIZE
'
' MessageText:
'
'  The ASF header has exceeded the specified maximum size.%0
'
%ASF_E_HEADERSIZE                 = &HC00D080E&


'-------------------------------------------------------------------------
'
' Advanced Streaming Format (ASF) Success Codes (2000 - 2999)
'

'
' MessageId: ASF_S_OPAQUEPACKET
'
' MessageText:
'
'  ASF_S_OPAQUEPACKET
'
%ASF_S_OPAQUEPACKET               = &H000D07F0&


'-------------------------------------------------------------------------
'
' Advanced Streaming Format (ASF) Warnings (2000 - 2999)
'
