'------------------------------------------------------------------------------
'
'  SecExt.inc -- Security functions not part of the SSPI interface.
'
'  Copyright (c) 2002-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from secext.h of 14 Jul 2009
'------------------------------------------------------------------------------

' This file should not be directly included - use security.inc instead.

#INCLUDE THIS ONCE

%SECEXT_INC = 1



'
' Extended Name APIs for ADS
'


' Enumerated type EXTENDED_NAME_FORMAT ----------------------------------------

' Examples for the following formats assume a fictitous company
' which hooks into the global X.500 and DNS name spaces as follows.
'
' Enterprise root domain in DNS is
'
'      widget.com
'
' Enterprise root domain in X.500 (RFC 1779 format) is
'
'      O=Widget, C=US
'
' There exists the child domain
'
'      engineering.widget.com
'
' equivalent to
'
'      OU=Engineering, O=Widget, C=US
'
' There exists a container within the Engineering domain
'
'      OU=Software, OU=Engineering, O=Widget, C=US
'
' There exists the user
'
'      CN=John Doe, OU=Software, OU=Engineering, O=Widget, C=US
'
' And this user's downlevel (pre-ADS) user name is
'
'      Engineering\JohnDoe

' unknown name type
%NameUnknown = 0

' CN=John Doe, OU=Software, OU=Engineering, O=Widget, C=US
%NameFullyQualifiedDN = 1

' Engineering\JohnDoe
%NameSamCompatible = 2

' Probably "John Doe" but could be something else.  I.e. The
' display name is not necessarily the defining RDN.
%NameDisplay = 3


' String-ized GUID as returned by IIDFromString().
' eg: {4fa050f0-f561-11cf-bdd9-00aa003a77b6}
%NameUniqueId = 6

' engineering.widget.com/software/John Doe
%NameCanonical = 7

' johndoe@engineering.com
%NameUserPrincipal = 8

' Same as NameCanonical except that rightmost "/" is
' replaced with $CR - even in domain-only case.
' eg: "engineering.widget.com/software" + $CR + "John Doe"
%NameCanonicalEx = 9

' www/srv.engineering.com/engineering.com
%NameServicePrincipal = 10

' DNS domain name + SAM username
' eg: engineering.widget.com\JohnDoe
%NameDnsDomain = 12

' end of enumerated type EXTENDED_NAME_FORMAT ---------------------------------



DECLARE FUNCTION GetUserNameExA LIB "SECUR32.DLL" ALIAS "GetUserNameExA" ( _
    BYVAL NameFormat AS LONG, _   ' EXTENDED_NAME_FORMAT value
    lpNameBuffer AS ASCIIZ, _
    nSize AS DWORD) AS BYTE

DECLARE FUNCTION GetUserNameExW LIB "SECUR32.DLL" ALIAS "GetUserNameExW" ( _
    BYVAL NameFormat AS LONG, _   ' EXTENDED_NAME_FORMAT value
    lpNameBuffer AS WSTRINGZ, _
    nSize AS DWORD) AS BYTE

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetUserNameEx LIB "SECUR32.DLL" ALIAS "GetUserNameExW" ( _
    BYVAL NameFormat AS LONG, _   ' EXTENDED_NAME_FORMAT value
    lpNameBuffer AS WSTRINGZ, _
    nSize AS DWORD) AS BYTE
#ELSE
DECLARE FUNCTION GetUserNameEx LIB "SECUR32.DLL" ALIAS "GetUserNameExA" ( _
    BYVAL NameFormat AS LONG, _   ' EXTENDED_NAME_FORMAT value
    lpNameBuffer AS ASCIIZ, _
    nSize AS DWORD) AS BYTE
#ENDIF


DECLARE FUNCTION GetComputerObjectNameA LIB "SECUR32.DLL" _
   ALIAS "GetComputerObjectNameA" ( _
    BYVAL NameFormat AS LONG, _   ' EXTENDED_NAME_FORMAT value
    lpNameBuffer AS ASCIIZ, _
    nSize AS DWORD) AS BYTE

DECLARE FUNCTION GetComputerObjectNameW LIB "SECUR32.DLL" _
   ALIAS "GetComputerObjectNameW" ( _
    BYVAL NameFormat AS LONG, _   ' EXTENDED_NAME_FORMAT value
    lpNameBuffer AS WSTRINGZ, _
    nSize AS DWORD) AS BYTE

#IF %DEF(%UNICODE)
DECLARE FUNCTION GetComputerObjectName LIB "SECUR32.DLL" _
   ALIAS "GetComputerObjectNameW" ( _
    BYVAL NameFormat AS LONG, _   ' EXTENDED_NAME_FORMAT value
    lpNameBuffer AS WSTRINGZ, _
    nSize AS DWORD) AS BYTE
#ELSE
DECLARE FUNCTION GetComputerObjectName LIB "SECUR32.DLL" _
   ALIAS "GetComputerObjectNameA" ( _
    BYVAL NameFormat AS LONG, _   ' EXTENDED_NAME_FORMAT value
    lpNameBuffer AS ASCIIZ, _
    nSize AS DWORD) AS BYTE
#ENDIF


DECLARE FUNCTION TranslateNameA LIB "SECUR32.DLL" ALIAS "TranslateNameA" ( _
    lpAccountName AS ASCIIZ, _
    BYVAL AccountNameFormat AS LONG, _   ' EXTENDED_NAME_FORMAT value
    BYVAL DesiredNameFormat AS LONG, _   ' EXTENDED_NAME_FORMAT value
    lpTranslatedName AS ASCIIZ, _
    nSize AS DWORD) AS BYTE

DECLARE FUNCTION TranslateNameW LIB "SECUR32.DLL" ALIAS "TranslateNameW" ( _
    lpAccountName AS WSTRINGZ, _
    BYVAL AccountNameFormat AS LONG, _   ' EXTENDED_NAME_FORMAT value
    BYVAL DesiredNameFormat AS LONG, _   ' EXTENDED_NAME_FORMAT value
    lpTranslatedName AS WSTRINGZ, _
    nSize AS DWORD) AS BYTE

#IF %DEF(%UNICODE)
DECLARE FUNCTION TranslateName LIB "SECUR32.DLL" ALIAS "TranslateNameW" ( _
    lpAccountName AS WSTRINGZ, _
    BYVAL AccountNameFormat AS LONG, _   ' EXTENDED_NAME_FORMAT value
    BYVAL DesiredNameFormat AS LONG, _   ' EXTENDED_NAME_FORMAT value
    lpTranslatedName AS WSTRINGZ, _
    nSize AS DWORD) AS BYTE
#ELSE
DECLARE FUNCTION TranslateName LIB "SECUR32.DLL" ALIAS "TranslateNameA" ( _
    lpAccountName AS ASCIIZ, _
    BYVAL AccountNameFormat AS LONG, _   ' EXTENDED_NAME_FORMAT value
    BYVAL DesiredNameFormat AS LONG, _   ' EXTENDED_NAME_FORMAT value
    lpTranslatedName AS ASCIIZ, _
    nSize AS DWORD) AS BYTE
#ENDIF
