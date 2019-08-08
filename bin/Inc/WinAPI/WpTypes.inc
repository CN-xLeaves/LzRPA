'------------------------------------------------------------------------------
'
'  WpTypes.inc -- Data types for the Microsoft Web Publishing API.
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from WpTypes.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WPTYPES_H = 1


'
'  Site info structures
'

TYPE WPSITEINFOA
    dwSize       AS DWORD
    dwFlags      AS DWORD
    lpszSiteName AS ASCIIZ PTR
    lpszSiteURL  AS ASCIIZ PTR
END TYPE

TYPE WPSITEINFOW
    dwSize       AS DWORD
    dwFlags      AS DWORD
    lpszSiteName AS WSTRINGZ PTR
    lpszSiteURL  AS WSTRINGZ PTR
END TYPE


'
'  Provider info structures
'

TYPE WPPROVINFOA
    dwSize            AS DWORD
    dwFlags           AS DWORD
    dwPriority        AS DWORD
    lpszProviderName  AS ASCIIZ PTR
    lpszProviderCLSID AS ASCIIZ PTR
    lpszDllPath       AS ASCIIZ PTR
END TYPE

TYPE WPPROVINFOW
    dwSize            AS DWORD
    dwFlags           AS DWORD
    dwPriority        AS DWORD
    lpszProviderName  AS WSTRINGZ PTR
    lpszProviderCLSID AS WSTRINGZ PTR
    lpszDllPath       AS WSTRINGZ PTR
END TYPE

#IF %DEF(%UNICODE)

TYPE WPSITEINFO
    WPSITEINFOW
END TYPE
TYPE WPPROVINFO
    WPPROVINFOW
END TYPE

#ELSE

TYPE WPSITEINFO
    WPSITEINFOA
END TYPE
TYPE WPPROVINFO
    WPPROVINFOA
END TYPE

#ENDIF
