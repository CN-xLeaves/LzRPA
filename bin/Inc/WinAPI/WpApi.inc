'------------------------------------------------------------------------------
'
'  WpApi.inc -- Declaration of the Microsoft Web Publishing API
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from WpApi.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WP15API_H = 1


'#INCLUDE "windows.inc"

#IF NOT %DEF(%WPTYPES_H)
#INCLUDE "wptypes.inc"
#ENDIF

'
' Assume packing on DWORD boundary
'

'#include <pshpack4.h>


'
'  Flags
'

%WPF_NO_RECURSIVE_POST         = &H00000001      '  WpPost
%WPF_NO_WIZARD                 = &H00000002      '  WpPost
%WPF_MINIMAL_UI                = &H00000004      '  WpPost - OBSOLETE
%WPF_FIRST_FILE_AS_DEFAULT     = &H00000008      '  WpPost/PostFiles
%WPF_NO_DIRECT_LOOKUP          = &H00000010      '  WpBindToSite
%WPF_NO_URL_LOOKUP             = &H00000020      '  WpBindToSite
%WPF_USE_PROVIDER_PASSED       = &H00000040      '  WpCreateSite
%WPF_NO_VERIFY_POST            = &H00000080      '  WpPost
%WPF_NO_PROGRESS_DLGS          = &H00000200      '  WpPost
%WPF_SHOWPAGE_WELCOME          = &H00010000      '  WpPost/Wizard
%WPF_SHOWPAGE_SRCFILE          = &H00020000      '  WpPost/Wizard
%WPF_SHOWPAGE_DESTSITE         = &H00040000      '  WpPost/Wizard
%WPF_SHOWPAGE_PROVIDER         = &H00080000      '  WpPost/Wizard/AddWizardPages
%WPF_ENABLE_LOCAL_BASE_DIR     = &H00100000      '  WpPost/Wizard

%WPF_NO_UI                     = %WPF_NO_WIZARD OR _
                                       %WPF_NO_PROGRESS_DLGS

%WPF_SHOWPAGE_ALL              = %WPF_SHOWPAGE_WELCOME OR _
                                       %WPF_SHOWPAGE_SRCFILE OR _
                                       %WPF_SHOWPAGE_DESTSITE OR _
                                       %WPF_SHOWPAGE_PROVIDER


'
'  Miscellaneous
'

%MAX_SITENAME_LEN              = 128


'
'  Unicode APIs
'

DECLARE FUNCTION WpPostW LIB "WebPost.dll" ALIAS "WpPostW" ( _
    BYVAL hwnd            AS DWORD, _
    BYVAL dwNumLocalPaths AS DWORD, _
    BYVAL psLocalPaths    AS DWORD, _      ' wstringz ptr ptr
    pdwSiteNameBufLen     AS DWORD, _
    sSiteName             AS WSTRINGZ, _
    pdwDestURLBufLen      AS DWORD, _
    sDestURLBufLen        AS WSTRINGZ, _
    BYVAL dwFlag          AS DWORD) AS DWORD

DECLARE FUNCTION WpListSitesW LIB "WebPost.dll" ALIAS "WpListSitesW" ( _
    pdwSitesBufLen     AS DWORD, _
    BYVAL pSitesBuffer AS WPSITEINFOW PTR, _
    pdwNumSites        AS DWORD) AS DWORD

DECLARE FUNCTION WpDoesSiteExistW LIB "WebPost.dll" _
   ALIAS "WpDoesSiteExistW" ( _
    sSiteName    AS WSTRINGZ, _
    pfSiteExists AS LONG) AS DWORD

DECLARE FUNCTION WpDeleteSiteW LIB "WebPost.dll" ALIAS "WpDeleteSiteW" ( _
    sSiteName AS WSTRINGZ) AS DWORD

DECLARE FUNCTION WpBindToSiteW LIB "WebPost.dll" ALIAS "WpBindToSiteW" ( _
    BYVAL hwnd       AS DWORD, _
    sSiteName        AS WSTRINGZ, _
    sSitePostingURL  AS WSTRINGZ, _
    BYVAL dwFlag     AS DWORD, _
    BYVAL dwReserved AS DWORD, _
    BYVAL ppvUnk     AS DWORD) AS DWORD

DECLARE FUNCTION WpCreateSiteW LIB "WebPost.dll" ALIAS "WpCreateSiteW" ( _
    sSiteName         AS WSTRINGZ, _
    sSiteLocalBaseDir AS WSTRINGZ, _
    sSitePostingURL   AS WSTRINGZ, _
    sProviderCLSID    AS WSTRINGZ, _
    BYVAL dwFlags     AS DWORD) AS DWORD

DECLARE FUNCTION WpEnumProvidersW LIB "WebPost.dll" _
   ALIAS "WpEnumProvidersW" ( _
    pdwProvidersBufLen     AS DWORD, _
    BYVAL pProvidersBuffer AS WPPROVINFOW PTR, _
    pdwNumProviders        AS DWORD) AS DWORD

DECLARE FUNCTION WpGetErrorStringW LIB "WebPost.dll" _
   ALIAS "WpGetErrorStringW" ( _
    BYVAL uErrCode AS DWORD, _
    sOutputBuf     AS WSTRINGZ, _
    pdwBufLen      AS DWORD) AS DWORD


'
'  ANSI APIs
'

DECLARE FUNCTION WpPostA LIB "WebPost.dll" ALIAS "WpPostA" ( _
    BYVAL hwnd            AS DWORD, _
    BYVAL dwNumLocalPaths AS DWORD, _
    BYVAL psLocalPaths    AS DWORD, _
    pdwSiteNameBufLen     AS DWORD, _
    sSiteName             AS ASCIIZ, _
    pdwDestURLBufLen      AS DWORD, _
    sDestURLBufLen        AS ASCIIZ, _
    BYVAL dwFlag          AS DWORD) AS DWORD

DECLARE FUNCTION WpListSitesA LIB "WebPost.dll" ALIAS "WpListSitesA" ( _
    pdwSitesBufLen        AS DWORD, _
    BYVAL pSitesBuffer    AS WPSITEINFOA PTR, _
    pdwNumSites AS DWORD) AS DWORD

DECLARE FUNCTION WpDoesSiteExistA LIB "WebPost.dll" _
   ALIAS "WpDoesSiteExistA" ( _
    sSiteName    AS ASCIIZ, _
    pfSiteExists AS LONG) AS DWORD

DECLARE FUNCTION WpDeleteSiteA LIB "WebPost.dll" ALIAS "WpDeleteSiteA" ( _
    sSiteName AS ASCIIZ) AS DWORD

DECLARE FUNCTION WpBindToSiteA LIB "WebPost.dll" ALIAS "WpBindToSiteA" ( _
    BYVAL hwnd       AS DWORD, _
    sSiteName        AS ASCIIZ, _
    sSitePostingURL  AS ASCIIZ, _
    BYVAL dwFlag     AS DWORD, _
    BYVAL dwReserved AS DWORD, _
    BYVAL ppvUnk     AS DWORD) AS DWORD

DECLARE FUNCTION WpCreateSiteA LIB "WebPost.dll" ALIAS "WpCreateSiteA" ( _
    sSiteName         AS ASCIIZ, _
    sSiteLocalBaseDir AS ASCIIZ, _
    sSitePostingURL   AS ASCIIZ, _
    sProviderCLSID    AS ASCIIZ, _
    BYVAL dwFlags     AS DWORD) AS DWORD

DECLARE FUNCTION WpEnumProvidersA LIB "WebPost.dll" _
   ALIAS "WpEnumProvidersA" ( _
    pdwProvidersBufLen     AS DWORD, _
    BYVAL pProvidersBuffer AS WPPROVINFOA PTR, _
    pdwNumProviders        AS DWORD) AS DWORD

DECLARE FUNCTION WpGetErrorStringA LIB "WebPost.dll" _
   ALIAS "WpGetErrorStringA" ( _
    BYVAL uErrCode AS DWORD, _
    sOutputBuf     AS ASCIIZ, _
    pdwBufLen      AS DWORD) AS DWORD



#IF %DEF(%UNICODE)

DECLARE FUNCTION WpPost LIB "WebPost.dll" ALIAS "WpPostW" ( _
    BYVAL hwnd            AS DWORD, _
    BYVAL dwNumLocalPaths AS DWORD, _
    BYVAL psLocalPaths    AS DWORD, _      ' wstringz ptr ptr
    pdwSiteNameBufLen     AS DWORD, _
    sSiteName             AS WSTRINGZ, _
    pdwDestURLBufLen      AS DWORD, _
    sDestURLBufLen        AS WSTRINGZ, _
    BYVAL dwFlag          AS DWORD) AS DWORD

DECLARE FUNCTION WpListSites LIB "WebPost.dll" ALIAS "WpListSitesW" ( _
    pdwSitesBufLen     AS DWORD, _
    BYVAL pSitesBuffer AS WPSITEINFOW PTR, _
    pdwNumSites        AS DWORD) AS DWORD

DECLARE FUNCTION WpDoesSiteExist LIB "WebPost.dll" _
   ALIAS "WpDoesSiteExistW" ( _
    sSiteName    AS WSTRINGZ, _
    pfSiteExists AS LONG) AS DWORD

DECLARE FUNCTION WpDeleteSite LIB "WebPost.dll" ALIAS "WpDeleteSiteW" ( _
    sSiteName AS WSTRINGZ) AS DWORD

DECLARE FUNCTION WpBindToSite LIB "WebPost.dll" ALIAS "WpBindToSiteW" ( _
    BYVAL hwnd       AS DWORD, _
    sSiteName        AS WSTRINGZ, _
    sSitePostingURL  AS WSTRINGZ, _
    BYVAL dwFlag     AS DWORD, _
    BYVAL dwReserved AS DWORD, _
    BYVAL ppvUnk     AS DWORD) AS DWORD

DECLARE FUNCTION WpCreateSite LIB "WebPost.dll" ALIAS "WpCreateSiteW" ( _
    sSiteName         AS WSTRINGZ, _
    sSiteLocalBaseDir AS WSTRINGZ, _
    sSitePostingURL   AS WSTRINGZ, _
    sProviderCLSID    AS WSTRINGZ, _
    BYVAL dwFlags     AS DWORD) AS DWORD

DECLARE FUNCTION WpEnumProviders LIB "WebPost.dll" _
   ALIAS "WpEnumProvidersW" ( _
    pdwProvidersBufLen     AS DWORD, _
    BYVAL pProvidersBuffer AS WPPROVINFOW PTR, _
    pdwNumProviders        AS DWORD) AS DWORD

DECLARE FUNCTION WpGetErrorString LIB "WebPost.dll" _
   ALIAS "WpGetErrorStringW" ( _
    BYVAL uErrCode AS DWORD, _
    sOutputBuf     AS WSTRINGZ, _
    pdwBufLen      AS DWORD) AS DWORD

#ELSE

DECLARE FUNCTION WpPost LIB "WebPost.dll" ALIAS "WpPostA" ( _
    BYVAL hwnd            AS DWORD, _
    BYVAL dwNumLocalPaths AS DWORD, _
    BYVAL psLocalPaths    AS DWORD, _
    pdwSiteNameBufLen     AS DWORD, _
    sSiteName             AS ASCIIZ, _
    pdwDestURLBufLen      AS DWORD, _
    sDestURLBufLen        AS ASCIIZ, _
    BYVAL dwFlag          AS DWORD) AS DWORD

DECLARE FUNCTION WpListSites LIB "WebPost.dll" ALIAS "WpListSitesA" ( _
    pdwSitesBufLen        AS DWORD, _
    BYVAL pSitesBuffer    AS WPSITEINFOA PTR, _
    pdwNumSites AS DWORD) AS DWORD

DECLARE FUNCTION WpDoesSiteExist LIB "WebPost.dll" _
   ALIAS "WpDoesSiteExistA" ( _
    sSiteName    AS ASCIIZ, _
    pfSiteExists AS LONG) AS DWORD

DECLARE FUNCTION WpDeleteSite LIB "WebPost.dll" ALIAS "WpDeleteSiteA" ( _
    sSiteName AS ASCIIZ) AS DWORD

DECLARE FUNCTION WpBindToSite LIB "WebPost.dll" ALIAS "WpBindToSiteA" ( _
    BYVAL hwnd       AS DWORD, _
    sSiteName        AS ASCIIZ, _
    sSitePostingURL  AS ASCIIZ, _
    BYVAL dwFlag     AS DWORD, _
    BYVAL dwReserved AS DWORD, _
    BYVAL ppvUnk     AS DWORD) AS DWORD

DECLARE FUNCTION WpCreateSite LIB "WebPost.dll" ALIAS "WpCreateSiteA" ( _
    sSiteName         AS ASCIIZ, _
    sSiteLocalBaseDir AS ASCIIZ, _
    sSitePostingURL   AS ASCIIZ, _
    sProviderCLSID    AS ASCIIZ, _
    BYVAL dwFlags     AS DWORD) AS DWORD

DECLARE FUNCTION WpEnumProviders LIB "WebPost.dll" _
   ALIAS "WpEnumProvidersA" ( _
    pdwProvidersBufLen     AS DWORD, _
    BYVAL pProvidersBuffer AS WPPROVINFOA PTR, _
    pdwNumProviders        AS DWORD) AS DWORD

DECLARE FUNCTION WpGetErrorString LIB "WebPost.dll" _
   ALIAS "WpGetErrorStringA" ( _
    BYVAL uErrCode AS DWORD, _
    sOutputBuf     AS ASCIIZ, _
    pdwBufLen      AS DWORD) AS DWORD

#ENDIF


'#include <poppack.h>
