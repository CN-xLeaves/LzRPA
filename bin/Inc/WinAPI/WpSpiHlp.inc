'------------------------------------------------------------------------------
'
'  WpSpiHlp.inc
'    Declaration of Microsoft Web Publishing Service Provider helper functions.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from WpSpiHlp.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WPSPIHLP_H = 1


'#INCLUDE "windows.inc"
#INCLUDE "wptypes.inc"


'
'  Flags
'

%WPF_FORCE_BIND                = &H00000100      '  WppBindToSite


'
'  Helper function declarations and typedefs
'

DECLARE FUNCTION WppBindToSiteA ALIAS "WppBindToSiteA" ( _
    BYVAL hwnd AS DWORD, sSiteName AS ASCIIZ, sUrl AS ASCIIZ, riid AS GUID, _
    BYVAL dwFlag AS DWORD, BYVAL dwReserved AS DWORD, ppvUnk AS ANY) _
    AS LONG  ' HRESULT

DECLARE FUNCTION WppListSitesA ALIAS "WppListSitesA" ( _
    pdwSitesBufLen AS DWORD, BYVAL pSitesBuffer AS WPSITEINFOA PTR, _
    pdwNumSites AS DWORD) AS LONG  ' HRESULT


DECLARE FUNCTION PFN_WPPLISTSITESA (pdwSitesBufLen AS DWORD, _
    BYVAL pSitesBuffer AS WPSITEINFOA PTR, pdwNumSites AS DWORD) _
    AS LONG  ' HRESULT

DECLARE FUNCTION WppDeleteSiteA ALIAS "WppDeleteSiteA" (sSiteName AS ASCIIZ) _
    AS LONG  ' HRESULT

DECLARE FUNCTION PFN_WPPDELETESITEA (sSiteName AS ASCIIZ) AS LONG  ' HRESULT

DECLARE FUNCTION WppBindToSiteW ALIAS "WppBindToSiteW" ( _
    BYVAL hwnd AS DWORD, sSiteName AS WSTRINGZ, sUrl AS WSTRINGZ, riid AS GUID, _
    BYVAL dwFlag AS DWORD, BYVAL dwReserved AS DWORD, ppvUnk AS ANY) _
    AS LONG  ' HRESULT

DECLARE FUNCTION WppListSitesW ALIAS "WppListSitesW" ( _
    pdwSitesBufLen AS DWORD, BYVAL pSitesBuffer AS WPSITEINFOW PTR, _
    pdwNumSites AS DWORD) AS LONG  ' HRESULT


DECLARE FUNCTION PFN_WPPLISTSITESW (pdwSitesBufLen AS DWORD, _
    BYVAL pSitesBuffer AS WPSITEINFOW PTR, pdwNumSites AS DWORD) _
    AS LONG  ' HRESULT

DECLARE FUNCTION WppDeleteSiteW ALIAS "WppDeleteSiteW" ( _
    sSiteName AS WSTRINGZ) AS LONG  ' HRESULT

DECLARE FUNCTION PFN_WPPDELETESITEW (sSiteName AS WSTRINGZ) AS LONG  ' HRESULT


'
'  Entry Points
'

$$EP_WPPBINDTOSITEW = "WppBindToSiteW"$$
$$EP_WPPLISTSITESW  = "WppListSitesW"$$
$$EP_WPPDELETESITEW = "WppDeleteSiteW"$$

$$EP_WPPBINDTOSITEA = "WppBindToSiteA"$$
$$EP_WPPLISTSITESA  = "WppListSitesA"$$
$$EP_WPPDELETESITEA = "WppDeleteSiteA"$$
