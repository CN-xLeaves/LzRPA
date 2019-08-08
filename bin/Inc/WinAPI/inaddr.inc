'------------------------------------------------------------------------------
'
'  inaddr.inc -
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from inaddr.h dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%s_addr = 1

'
' IPv4 Internet address
' This is an 'on-wire' format structure.
'

TYPE IN_ADDR_union_type1
    s_b1 AS BYTE
    s_b2 AS BYTE
    s_b3 AS BYTE
    s_b4 AS BYTE
END TYPE

TYPE IN_ADDR_union_type2
    s_w1 AS WORD
    s_w2 AS WORD
END TYPE

UNION IN_ADDR_union
    S_un_b AS IN_ADDR_union_type1
    S_un_w AS IN_ADDR_union_type2
    S_addr AS DWORD
END UNION

TYPE IN_ADDR
    S_un AS IN_ADDR_union
END TYPE

'macro s_addr =S_un.S_addr ' can be used for most tcp & ip code
'macro s_host =S_un.S_un_b.s_b2    ' host on imp
'macro s_net  =S_un.S_un_b.s_b1    ' network
'macro s_imp  =S_un.S_un_w.s_w2    ' imp
'macro s_impno=S_un.S_un_b.s_b4    ' imp #
'macro s_lh   =S_un.S_un_b.s_b3    ' logical host
