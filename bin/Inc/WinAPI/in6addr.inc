'------------------------------------------------------------------------------
'
'  in6addr.inc
'
'  Copyright (c) 2009-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from in6addr.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%s6_addr = 1

'
' IPv6 Internet address (RFC 2553)
' This is an 'on-wire' format structure.
'
UNION IN6_ADDR_union
    nByte(15) AS BYTE
    nWord(7)  AS WORD
END UNION

TYPE IN6_ADDR
    u AS IN6_ADDR_union
END TYPE

TYPE in_addr6
    in6_addr
END TYPE

'
' Defines to match RFC 2553.
'
'MACRO _S6_un  = u
'MACRO _S6_u8  = Byte
'MACRO s6_addr = _S6_un._S6_u8

'
' Defines for our implementation.
'
MACRO s6_bytes = u.Byte
MACRO s6_words = u.Word
