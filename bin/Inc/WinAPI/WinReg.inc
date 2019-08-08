'------------------------------------------------------------------------------
'
'  WinReg.inc
'    This module contains the function prototypes and constant, type and
'    structure definitions for the Windows 32-Bit Registry API.
'
'  Copyright (c) 1997-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from WinReg.h build 0001 dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WINREG = 1

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "WinDef.inc"


#IF NOT %DEF(%WINVER)
%WINVER = &H0500   ' version 5.0
#ENDIF ' !WINVER

'
' RRF - Registry Routine Flags (for RegGetValue)
'

%RRF_RT_REG_NONE      = &H00000001  ' restrict type to REG_NONE      (other data types will not return ERROR_SUCCESS)
%RRF_RT_REG_SZ        = &H00000002  ' restrict type to REG_SZ        (other data types will not return ERROR_SUCCESS) (automatically converts REG_EXPAND_SZ to REG_SZ unless RRF_NOEXPAND is specified)
%RRF_RT_REG_EXPAND_SZ = &H00000004  ' restrict type to REG_EXPAND_SZ (other data types will not return ERROR_SUCCESS) (must specify RRF_NOEXPAND or RegGetValue will fail with ERROR_INVALID_PARAMETER)
%RRF_RT_REG_BINARY    = &H00000008  ' restrict type to REG_BINARY    (other data types will not return ERROR_SUCCESS)
%RRF_RT_REG_DWORD     = &H00000010  ' restrict type to REG_DWORD     (other data types will not return ERROR_SUCCESS)
%RRF_RT_REG_MULTI_SZ  = &H00000020  ' restrict type to REG_MULTI_SZ  (other data types will not return ERROR_SUCCESS)
%RRF_RT_REG_QWORD     = &H00000040  ' restrict type to REG_QWORD     (other data types will not return ERROR_SUCCESS)

%RRF_RT_DWORD         = (%RRF_RT_REG_BINARY OR %RRF_RT_REG_DWORD) ' restrict type to *32-bit* RRF_RT_REG_BINARY or RRF_RT_REG_DWORD (other data types will not return ERROR_SUCCESS)
%RRF_RT_QWORD         = (%RRF_RT_REG_BINARY OR %RRF_RT_REG_QWORD) ' restrict type to *64-bit* RRF_RT_REG_BINARY or RRF_RT_REG_DWORD (other data types will not return ERROR_SUCCESS)
%RRF_RT_ANY           = &H0000ffff                             ' no type restriction

%RRF_NOEXPAND         = &H10000000  ' do not automatically expand environment strings if value is of type REG_EXPAND_SZ
%RRF_ZEROONFAILURE    = &H20000000  ' if pvData is not NULL, set content to all zeros on failure

'
' Flags for RegLoadAppKey
'
%REG_PROCESS_APPKEY        = &H00000001

'
' Flags for RegLoadMUIString
'
%REG_MUI_STRING_TRUNCATE   = &H00000001

'
' Requested Key access mask type.
'

MACRO REGSAM = ACCESS_MASK

'
' Reserved Key Handles.
'

%HKEY_CLASSES_ROOT                = &H80000000???
%HKEY_CURRENT_USER                = &H80000001???
%HKEY_LOCAL_MACHINE               = &H80000002???
%HKEY_USERS                       = &H80000003???
%HKEY_PERFORMANCE_DATA            = &H80000004???
%HKEY_PERFORMANCE_TEXT            = &H80000050???
%HKEY_PERFORMANCE_NLSTEXT         = &H80000060???
#IF (%WINVER >= &H0400)
%HKEY_CURRENT_CONFIG              = &H80000005???
%HKEY_DYN_DATA                    = &H80000006???
%HKEY_CURRENT_USER_LOCAL_SETTINGS = &H80000007???


'
' RegConnectRegistryEx supported flags
'
%REG_SECURE_CONNECTION = 1

'NOINC
#IF NOT %DEF(%PROVIDER_STRUCTS_DEFINED)

%PROVIDER_STRUCTS_DEFINED = 1

%PROVIDER_KEEPS_VALUE_LENGTH = &H1

TYPE val_context
    valuelen      AS LONG    ' the total length of this value
    value_context AS DWORD   ' provider's context
    val_buff_ptr  AS DWORD   ' where in the ouput buffer the value is.
END TYPE

TYPE pvalueA             ' Provider supplied value/context.
    pv_valuename     AS ASCIIZ PTR   ' The value name pointer
    pv_valuelen      AS LONG
    pv_value_context AS DWORD
    pv_type          AS DWORD
END TYPE

TYPE pvalueW             ' Provider supplied value/context.
    pv_valuename     AS WSTRINGZ PTR   ' The value name pointer
    pv_valuelen      AS LONG
    pv_value_context AS DWORD
    pv_type          AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE PVALUE
    PVALUEW
END TYPE
#ELSE
TYPE PVALUE
    PVALUEA
END TYPE
#ENDIF ' UNICODE

'typedef
'DWORD __cdecl
'QUERYHANDLER (LPVOID keycontext, PVALCONTEXT val_list, DWORD num_vals,
'          LPVOID outputbuffer, DWORD FAR *total_outlen, DWORD input_blen);

TYPE REG_PROVIDER
    pi_R0_1val     AS DWORD
    pi_R0_allvals  AS DWORD
    pi_R3_1val     AS DWORD
    pi_R3_allvals  AS DWORD
    pi_flags       AS DWORD    ' capability flags (none defined yet).
    pi_key_context AS DWORD
END TYPE

TYPE VALENTA
    ve_valuename AS ASCIIZ PTR
    ve_valuelen  AS DWORD
    ve_valueptr  AS DWORD
    ve_type      AS DWORD
END TYPE

TYPE VALENTW
    ve_valuename AS WSTRINGZ PTR
    ve_valuelen  AS DWORD
    ve_valueptr  AS DWORD
    ve_type      AS DWORD
END TYPE

#IF %DEF(%UNICODE)
TYPE VALENT
    VALENTW
END TYPE
#ELSE
TYPE VALENT
    VALENTA
END TYPE
#ENDIF ' UNICODE

#ENDIF ' not(%PROVIDER_STRUCTS_DEFINED)

#ENDIF ' WINVER >= &H0400

'
' Default values for parameters that do not exist in the Win 3.1
' compatible APIs.
'

%WIN31_CLASS = %NULL

'
' API Prototypes.
'

DECLARE FUNCTION RegCloseKey LIB "AdvApi32.dll" ALIAS "RegCloseKey" _
    (BYVAL hKey AS DWORD) AS LONG

DECLARE FUNCTION RegOverridePredefKey LIB "AdvApi32.dll" _
    ALIAS "RegOverridePredefKey" (BYVAL hKey AS DWORD, _
    BYVAL hNewHKey AS DWORD) AS LONG

DECLARE FUNCTION RegOpenUserClassesRoot LIB "AdvApi32.dll" _
    ALIAS "RegOpenUserClassesRoot" (BYVAL hToken AS DWORD, _
    BYVAL dwOptions AS DWORD, BYVAL samDesired AS DWORD, phkResult AS DWORD) _
    AS LONG

DECLARE FUNCTION RegOpenCurrentUser LIB "AdvApi32.dll" _
    ALIAS "RegOpenCurrentUser" (BYVAL samDesired AS DWORD, _
    phkResult AS DWORD) AS LONG

DECLARE FUNCTION RegDisablePredefinedCache LIB "AdvApi32.dll" _
    ALIAS "RegDisablePredefinedCache" () AS LONG

DECLARE FUNCTION RegDisablePredefinedCacheEx LIB "AdvApi32.dll" _
    ALIAS "RegDisablePredefinedCacheEx" () AS LONG

DECLARE FUNCTION RegConnectRegistryA LIB "AdvApi32.dll" _
    ALIAS "RegConnectRegistryA" (lpMachineName AS ASCIIZ, _
    BYVAL hKey AS DWORD, phkResult AS DWORD) AS LONG

DECLARE FUNCTION RegConnectRegistryW LIB "AdvApi32.dll" _
    ALIAS "RegConnectRegistryW" (lpMachineName AS WSTRINGZ, _
    BYVAL hKey AS DWORD, phkResult AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO RegConnectRegistry=RegConnectRegistryW
#ELSE
MACRO RegConnectRegistry=RegConnectRegistryA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegConnectRegistryExA LIB "AdvApi32.dll" _
    ALIAS "RegConnectRegistryExA" (lpMachineName AS ASCIIZ, _
    BYVAL hKey AS DWORD, BYVAL dFlags AS DWORD, phkResult AS DWORD) AS LONG

DECLARE FUNCTION RegConnectRegistryExW LIB "AdvApi32.dll" _
    ALIAS "RegConnectRegistryExW" (lpMachineName AS WSTRINGZ, _
    BYVAL hKey AS DWORD, BYVAL dFlags AS DWORD, phkResult AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO RegConnectRegistryEx=RegConnectRegistryExW
#ELSE
MACRO RegConnectRegistryEx=RegConnectRegistryExA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegCreateKeyA LIB "AdvApi32.dll" ALIAS "RegCreateKeyA" _
    (BYVAL hKey AS DWORD, lpSubKey AS ASCIIZ, phkResult AS DWORD) AS LONG

DECLARE FUNCTION RegCreateKeyW LIB "AdvApi32.dll" ALIAS "RegCreateKeyW" _
    (BYVAL hKey AS DWORD, lpSubKey AS WSTRINGZ, phkResult AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO RegCreateKey=RegCreateKeyW
#ELSE
MACRO RegCreateKey=RegCreateKeyA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegCreateKeyExA LIB "AdvApi32.dll" ALIAS "RegCreateKeyExA" _
    (BYVAL hKey AS DWORD, lpSubKey AS ASCIIZ, BYVAL Reserved AS LONG, _
    lpClass AS ASCIIZ, BYVAL dwOptions AS DWORD, BYVAL samDesired AS DWORD, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES, phkResult AS DWORD, _
    lpdwDisposition AS DWORD) AS LONG

DECLARE FUNCTION RegCreateKeyExW LIB "AdvApi32.dll" ALIAS "RegCreateKeyExW" _
    (BYVAL hKey AS DWORD, lpSubKey AS WSTRINGZ, BYVAL Reserved AS LONG, _
    lpClass AS WSTRINGZ, BYVAL dwOptions AS DWORD, BYVAL samDesired AS DWORD, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES, phkResult AS DWORD, _
    lpdwDisposition AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO RegCreateKeyEx=RegCreateKeyExW
#ELSE
MACRO RegCreateKeyEx=RegCreateKeyExA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegCreateKeyTransactedA LIB "AdvAPI32.dll" _
    ALIAS "RegCreateKeyTransactedA" (BYVAL hKey AS DWORD, lpSubKey AS ASCIIZ, _
    BYVAL Reserved AS DWORD, lpClass AS ASCIIZ, BYVAL dwOptions AS DWORD, _
    BYVAL samDesired AS DWORD, lpSecurityAttributes AS SECURITY_ATTRIBUTES, _
    phkResult AS DWORD, lpdwDisposition AS DWORD, _
    BYVAL hTransaction AS DWORD, BYVAL pExtendedParameter AS DWORD) AS LONG

DECLARE FUNCTION RegCreateKeyTransactedW LIB "AdvAPI32.dll" _
    ALIAS "RegCreateKeyTransactedW" (BYVAL hKey AS DWORD, _
    lpSubKey AS WSTRINGZ, BYVAL Reserved AS DWORD, lpClass AS WSTRINGZ, _
    BYVAL dwOptions AS DWORD, BYVAL samDesired AS DWORD, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES, phkResult AS DWORD, _
    lpdwDisposition AS DWORD, BYVAL hTransaction AS DWORD, _
    BYVAL pExtendedParameter AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO RegCreateKeyTransacted=RegCreateKeyTransactedW
#ELSE
MACRO RegCreateKeyTransacted=RegCreateKeyTransactedA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegDeleteKeyA LIB "AdvApi32.dll" ALIAS "RegDeleteKeyA" _
    (BYVAL hKey AS DWORD, lpSubKey AS ASCIIZ) AS LONG

DECLARE FUNCTION RegDeleteKeyW LIB "AdvApi32.dll" ALIAS "RegDeleteKeyW" _
    (BYVAL hKey AS DWORD, lpSubKey AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO RegDeleteKey=RegDeleteKeyW
#ELSE
MACRO RegDeleteKey=RegDeleteKeyA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegDeleteKeyExA LIB "AdvApi32.dll" ALIAS "RegDeleteKeyExA" _
    (BYVAL hKey AS DWORD, lpSubKey AS ASCIIZ, BYVAL samDesired AS DWORD, _
    BYVAL Reserved AS DWORD) AS LONG

DECLARE FUNCTION RegDeleteKeyExW LIB "AdvApi32.dll" ALIAS "RegDeleteKeyExW" _
    (BYVAL hKey AS DWORD, lpSubKey AS WSTRINGZ, BYVAL samDesired AS DWORD, _
    BYVAL Reserved AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO RegDeleteKeyEx=RegDeleteKeyExW
#ELSE
MACRO RegDeleteKeyEx=RegDeleteKeyExA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegDeleteKeyTransactedA LIB "AdvApi32.dll" ALIAS _
    "RegDeleteKeyTransactedA" (BYVAL hKey AS DWORD, lpSubKey AS ASCIIZ, _
    BYVAL samDesired AS DWORD, BYVAL Reserved AS DWORD, _
    BYVAL hTransaction AS DWORD, BYVAL pExtendedParameter AS DWORD) AS LONG

DECLARE FUNCTION RegDeleteKeyTransactedW LIB "AdvApi32.dll" ALIAS _
    "RegDeleteKeyTransactedW" (BYVAL hKey AS DWORD, lpSubKey AS WSTRINGZ, _
    BYVAL samDesired AS DWORD, BYVAL Reserved AS DWORD, _
    BYVAL hTransaction AS DWORD, BYVAL pExtendedParameter AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO RegDeleteKeyTransacted=RegDeleteKeyTransactedW
#ELSE
MACRO RegDeleteKeyTransacted=RegDeleteKeyTransactedA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegDisableReflectionKey LIB "AdvApi32.dll" _
    ALIAS "RegDisableReflectionKey" (BYVAL hBase AS DWORD) AS LONG

DECLARE FUNCTION RegEnableReflectionKey LIB "AdvApi32.dll" _
    ALIAS "RegEnableReflectionKey" (BYVAL hBase AS DWORD) AS LONG

DECLARE FUNCTION RegQueryReflectionKey LIB "AdvApi32.dll" _
    ALIAS "RegQueryReflectionKey" (BYVAL hBase AS DWORD, _
    bIsReflectionDisabled AS LONG) AS LONG

DECLARE FUNCTION RegDeleteValueA LIB "AdvApi32.dll" ALIAS "RegDeleteValueA" _
    (BYVAL hKey AS DWORD, lpValueName AS ASCIIZ) AS LONG

DECLARE FUNCTION RegDeleteValueW LIB "AdvApi32.dll" ALIAS "RegDeleteValueW" _
    (BYVAL hKey AS DWORD, lpValueName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO RegDeleteValue=RegDeleteValueW
#ELSE
MACRO RegDeleteValue=RegDeleteValueA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegEnumKeyA LIB "AdvApi32.dll" ALIAS "RegEnumKeyA" _
    (BYVAL hKey AS DWORD, BYVAL dwIndex AS DWORD, lpName AS ASCIIZ, _
    BYVAL cbName AS DWORD) AS LONG

DECLARE FUNCTION RegEnumKeyW LIB "AdvApi32.dll" ALIAS "RegEnumKeyW" _
    (BYVAL hKey AS DWORD, BYVAL dwIndex AS DWORD, lpName AS WSTRINGZ, _
    BYVAL cbName AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO RegEnumKey=RegEnumKeyW
#ELSE
MACRO RegEnumKey=RegEnumKeyA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegEnumKeyExA LIB "AdvApi32.dll" ALIAS "RegEnumKeyExA" _
    (BYVAL hKey AS DWORD, BYVAL dwIndex AS DWORD, lpName AS ASCIIZ, _
    lpcbName AS DWORD, lpReserved AS DWORD, lpClass AS ASCIIZ, _
    lpcbClass AS LONG, lpftLastWriteTime AS FILETIME) AS LONG

DECLARE FUNCTION RegEnumKeyExW LIB "AdvApi32.dll" ALIAS "RegEnumKeyExW" _
    (BYVAL hKey AS DWORD, BYVAL dwIndex AS DWORD, lpName AS WSTRINGZ, _
    lpcbName AS DWORD, lpReserved AS DWORD, lpClass AS WSTRINGZ, _
    lpcbClass AS LONG, lpftLastWriteTime AS FILETIME) AS LONG

#IF %DEF(%UNICODE)
MACRO RegEnumKeyEx=RegEnumKeyExW
#ELSE
MACRO RegEnumKeyEx=RegEnumKeyExA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegEnumValueA LIB "AdvApi32.dll" ALIAS "RegEnumValueA" _
    (BYVAL hKey AS DWORD, BYVAL dwIndex AS DWORD, lpValueName AS ASCIIZ, _
    lpcbValueName AS DWORD, lpReserved AS DWORD, lpType AS DWORD, _
    lpData AS ANY, lpcbData AS DWORD) AS LONG

DECLARE FUNCTION RegEnumValueW LIB "AdvApi32.dll" ALIAS "RegEnumValueW" _
    (BYVAL hKey AS DWORD, BYVAL dwIndex AS DWORD, lpValueName AS WSTRINGZ, _
    lpcbValueName AS DWORD, lpReserved AS DWORD, lpType AS DWORD, _
    lpData AS ANY, lpcbData AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO RegEnumValue=RegEnumValueW
#ELSE
MACRO RegEnumValue=RegEnumValueA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegFlushKey LIB "AdvApi32.dll" ALIAS "RegFlushKey" _
    (BYVAL hKey AS DWORD) AS LONG

DECLARE FUNCTION RegGetKeySecurity LIB "AdvApi32.dll" _
    ALIAS "RegGetKeySecurity" (BYVAL hKey AS DWORD, _
    BYVAL SecurityInformation AS LONG, _
    pSecurityDescriptor AS DWORD, lpcbSecurityDescriptor AS DWORD) AS LONG

DECLARE FUNCTION RegLoadKeyA LIB "AdvApi32.dll" ALIAS "RegLoadKeyA" _
    (BYVAL hKey AS DWORD, lpSubKey AS ASCIIZ, lpFile AS ASCIIZ) AS LONG

DECLARE FUNCTION RegLoadKeyW LIB "AdvApi32.dll" ALIAS "RegLoadKeyW" _
    (BYVAL hKey AS DWORD, lpSubKey AS WSTRINGZ, lpFile AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO RegLoadKey=RegLoadKeyW
#ELSE
MACRO RegLoadKey=RegLoadKeyA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegNotifyChangeKeyValue LIB "AdvApi32.dll" _
    ALIAS "RegNotifyChangeKeyValue" (BYVAL hKey AS DWORD, _
    BYVAL bWatchSubtree AS LONG, BYVAL dwNotifyFilter AS DWORD, _
    BYVAL hEvent AS DWORD, BYVAL fAsynchronous AS LONG) AS LONG

DECLARE FUNCTION RegOpenKeyA LIB "AdvApi32.dll" ALIAS "RegOpenKeyA" _
    (BYVAL hKey AS DWORD, lpSubKey AS ASCIIZ, phkResult AS DWORD) AS LONG

DECLARE FUNCTION RegOpenKeyW LIB "AdvApi32.dll" ALIAS "RegOpenKeyW" _
    (BYVAL hKey AS DWORD, lpSubKey AS WSTRINGZ, phkResult AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO RegOpenKey=RegOpenKeyW
#ELSE
MACRO RegOpenKey=RegOpenKeyA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegOpenKeyExA LIB "AdvApi32.dll" ALIAS "RegOpenKeyExA" _
    (BYVAL hKey AS DWORD, lpSubKey AS ASCIIZ, BYVAL ulOptions AS DWORD, _
    BYVAL samDesired AS DWORD, phkResult AS DWORD) AS LONG

DECLARE FUNCTION RegOpenKeyExW LIB "AdvApi32.dll" ALIAS "RegOpenKeyExW" _
    (BYVAL hKey AS DWORD, lpSubKey AS WSTRINGZ, BYVAL ulOptions AS DWORD, _
    BYVAL samDesired AS DWORD, phkResult AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO RegOpenKeyEx=RegOpenKeyExW
#ELSE
MACRO RegOpenKeyEx=RegOpenKeyExA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegOpenKeyTransactedA LIB "AdvApi32.dll" _
    ALIAS "RegOpenKeyTransactedA" (BYVAL hKey AS DWORD, lpSubKey AS ASCIIZ, _
    BYVAL ulOptions AS DWORD, BYVAL samDesired AS DWORD, phkResult AS DWORD, _
    BYVAL hTransaction AS DWORD, pExtendedParameter AS DWORD) AS LONG

DECLARE FUNCTION RegOpenKeyTransactedW LIB "AdvApi32.dll" _
    ALIAS "RegOpenKeyTransactedW" (BYVAL hKey AS DWORD, lpSubKey AS WSTRINGZ, _
    BYVAL ulOptions AS DWORD, BYVAL samDesired AS DWORD, phkResult AS DWORD, _
    BYVAL hTransaction AS DWORD, pExtendedParameter AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO RegOpenKeyTransacted=RegOpenKeyTransactedW
#ELSE
MACRO RegOpenKeyTransacted=RegOpenKeyTransactedA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegQueryInfoKeyA LIB "AdvApi32.dll" ALIAS "RegQueryInfoKeyA" _
    (BYVAL hKey AS DWORD, lpClass AS ASCIIZ, lpcbClass AS DWORD, _
    lpReserved AS DWORD, lpcSubKeys AS DWORD, lpcbMaxSubKeyLen AS DWORD, _
    lpcbMaxClassLen AS DWORD, lpcValues AS DWORD, _
    lpcbMaxValueNameLen AS DWORD, lpcbMaxValueLen AS DWORD, _
    lpcbSecurityDescriptor AS DWORD, lpftLastWriteTime AS FILETIME) AS LONG

DECLARE FUNCTION RegQueryInfoKeyW LIB "AdvApi32.dll" ALIAS "RegQueryInfoKeyW" _
    (BYVAL hKey AS DWORD, lpClass AS WSTRINGZ, lpcbClass AS DWORD, _
    lpReserved AS DWORD, lpcSubKeys AS DWORD, lpcbMaxSubKeyLen AS DWORD, _
    lpcbMaxClassLen AS DWORD, lpcValues AS DWORD, _
    lpcbMaxValueNameLen AS DWORD, lpcbMaxValueLen AS DWORD, _
    lpcbSecurityDescriptor AS DWORD, lpftLastWriteTime AS FILETIME) AS LONG

#IF %DEF(%UNICODE)
MACRO RegQueryInfoKey=RegQueryInfoKeyW
#ELSE
MACRO RegQueryInfoKey=RegQueryInfoKeyA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegQueryValueA LIB "AdvApi32.dll" ALIAS "RegQueryValueA" _
    (BYVAL hKey AS DWORD, lpSubKey AS ASCIIZ, lpValue AS ASCIIZ, _
    lpcbValue AS LONG) AS LONG

DECLARE FUNCTION RegQueryValueW LIB "AdvApi32.dll" ALIAS "RegQueryValueW" _
    (BYVAL hKey AS DWORD, lpSubKey AS WSTRINGZ, lpValue AS WSTRINGZ, _
    lpcbValue AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO RegQueryValue=RegQueryValueW
#ELSE
MACRO RegQueryValue=RegQueryValueA
#ENDIF ' NOT %UNICODE

#IF (%WINVER >= &H0400)

DECLARE FUNCTION RegQueryMultipleValuesA LIB "AdvApi32.dll" _
    ALIAS "RegQueryMultipleValuesA" (BYVAL hKey AS DWORD, _
    BYVAL pvallist AS VALENTA PTR, BYVAL numvals AS DWORD, _
    lpValueBuf AS ASCIIZ, pdwTotSize AS DWORD) AS LONG

DECLARE FUNCTION RegQueryMultipleValuesW LIB "AdvApi32.dll" _
    ALIAS "RegQueryMultipleValuesW" (BYVAL hKey AS DWORD, _
    BYVAL pvallist AS VALENTW PTR, BYVAL numvals AS DWORD, _
    lpValueBuf AS WSTRINGZ, pdwTotSize AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO RegQueryMultipleValues=RegQueryMultipleValuesW
#ELSE
MACRO RegQueryMultipleValues=RegQueryMultipleValuesA
#ENDIF ' NOT %UNICODE

#ENDIF ' WINVER >= &H0400

DECLARE FUNCTION RegQueryValueExA LIB "AdvApi32.dll" ALIAS "RegQueryValueExA" _
    (BYVAL hKey AS DWORD, lpValueName AS ASCIIZ, BYVAL lpReserved AS DWORD, _
    lpType AS DWORD, lpData AS ANY, lpcbData AS DWORD) AS LONG

DECLARE FUNCTION RegQueryValueExW LIB "AdvApi32.dll" ALIAS "RegQueryValueExW" _
    (BYVAL hKey AS DWORD, lpValueName AS WSTRINGZ, BYVAL lpReserved AS DWORD, _
    lpType AS DWORD, lpData AS ANY, lpcbData AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO RegQueryValueEx=RegQueryValueExW
#ELSE
MACRO RegQueryValueEx=RegQueryValueExA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegReplaceKeyA LIB "AdvApi32.dll" ALIAS "RegReplaceKeyA" _
    (BYVAL hKey AS DWORD, lpSubKey AS ASCIIZ, lpNewFile AS ASCIIZ, _
    lpOldFile AS ASCIIZ) AS LONG

DECLARE FUNCTION RegReplaceKeyW LIB "AdvApi32.dll" ALIAS "RegReplaceKeyW" _
    (BYVAL hKey AS DWORD, lpSubKey AS WSTRINGZ, lpNewFile AS WSTRINGZ, _
    lpOldFile AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO RegReplaceKey=RegReplaceKeyW
#ELSE
MACRO RegReplaceKey=RegReplaceKeyA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegRestoreKeyA LIB "AdvApi32.dll" ALIAS "RegRestoreKeyA" _
    (BYVAL hKey AS DWORD, lpFile AS ASCIIZ, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION RegRestoreKeyW LIB "AdvApi32.dll" ALIAS "RegRestoreKeyW" _
    (BYVAL hKey AS DWORD, lpFile AS WSTRINGZ, BYVAL dwFlags AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO RegRestoreKey=RegRestoreKeyW
#ELSE
MACRO RegRestoreKey=RegRestoreKeyA
#ENDIF ' NOT %UNICODE

#IF (%WINVER >= &H0600)
DECLARE FUNCTION RegRenameKey LIB "AdvApi32.dll" ALIAS "RegRenameKey" _
    (BYVAL hKey AS DWORD, lpSubKeyName AS WSTRINGZ, lpNewKeyName AS WSTRINGZ) _
    AS LONG
#ENDIF  ' #IF (%WINVER >= &H0600)

DECLARE FUNCTION RegSaveKeyA LIB "AdvApi32.dll" ALIAS "RegSaveKeyA" _
    (BYVAL hKey AS DWORD, lpFile AS ASCIIZ, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES) AS LONG

DECLARE FUNCTION RegSaveKeyW LIB "AdvApi32.dll" ALIAS "RegSaveKeyW" _
    (BYVAL hKey AS DWORD, lpFile AS WSTRINGZ, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES) AS LONG

#IF %DEF(%UNICODE)
MACRO RegSaveKey=RegSaveKeyW
#ELSE
MACRO RegSaveKey=RegSaveKeyA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegSetKeySecurity LIB "AdvApi32.dll" _
    ALIAS "RegSetKeySecurity" (BYVAL hKey AS DWORD, _
    BYVAL SecurityInformation AS LONG, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR) AS LONG

DECLARE FUNCTION RegSetValueA LIB "AdvApi32.dll" ALIAS "RegSetValueA" _
    (BYVAL hKey AS DWORD, lpSubKey AS ASCIIZ, BYVAL dwType AS DWORD, _
    lpData AS ASCIIZ, BYVAL cbData AS DWORD) AS LONG

DECLARE FUNCTION RegSetValueW LIB "AdvApi32.dll" ALIAS "RegSetValueW" _
    (BYVAL hKey AS DWORD, lpSubKey AS WSTRINGZ, BYVAL dwType AS DWORD, _
    lpData AS WSTRINGZ, BYVAL cbData AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO RegSetValue=RegSetValueW
#ELSE
MACRO RegSetValue=RegSetValueA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegSetValueExA LIB "AdvApi32.dll" ALIAS "RegSetValueExA" _
    (BYVAL hKey AS DWORD, lpValueName AS ASCIIZ, BYVAL dwReserved AS DWORD, _
    BYVAL dwType AS DWORD, lpData AS ANY, BYVAL cbData AS DWORD) _
    AS LONG

DECLARE FUNCTION RegSetValueExW LIB "AdvApi32.dll" ALIAS "RegSetValueExW" _
    (BYVAL hKey AS DWORD, lpValueName AS WSTRINGZ, BYVAL dwReserved AS DWORD, _
    BYVAL dwType AS DWORD, lpData AS ANY, BYVAL cbData AS DWORD) _
    AS LONG

#IF %DEF(%UNICODE)
MACRO RegSetValueEx=RegSetValueExW
#ELSE
MACRO RegSetValueEx=RegSetValueExA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegUnLoadKeyA LIB "AdvApi32.dll" ALIAS "RegUnLoadKeyA" _
    (BYVAL hKey AS DWORD, lpSubKey AS ASCIIZ) AS LONG

DECLARE FUNCTION RegUnLoadKeyW LIB "AdvApi32.dll" ALIAS "RegUnLoadKeyW" _
    (BYVAL hKey AS DWORD, lpSubKey AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO RegUnLoadKey=RegUnLoadKeyW
#ELSE
MACRO RegUnLoadKey=RegUnLoadKeyA
#ENDIF ' NOT %UNICODE

'
' Utils wrappers
'
#IF %WIN32_WINNT >= &H0600

DECLARE FUNCTION RegDeleteKeyValueA LIB "AdvApi32.dll" _
    ALIAS "RegDeleteKeyValueA" (BYVAL hKey AS DWORD, lpSubKey AS ASCIIZ, _
    lpValueName AS ASCIIZ) AS DWORD

DECLARE FUNCTION RegDeleteKeyValueW LIB "AdvApi32.dll" _
    ALIAS "RegDeleteKeyValueW" (BYVAL hKey AS DWORD, lpSubKey AS WSTRINGZ, _
    lpValueName AS WSTRINGZ) AS DWORD

#IF %DEF(%UNICODE)
MACRO RegDeleteKeyValue=RegDeleteKeyValueW
#ELSE
MACRO RegDeleteKeyValue=RegDeleteKeyValueA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegSetKeyValueA LIB "AdvApi32.dll" _
    ALIAS "RegSetKeyValueA" (BYVAL hKey AS DWORD, lpSubKey AS ASCIIZ, _
    lpValueName AS ASCIIZ, BYVAL dwType AS DWORD, lpData AS ANY, _
    BYVAL cbData AS DWORD) AS LONG

DECLARE FUNCTION RegSetKeyValueW LIB "AdvApi32.dll" _
    ALIAS "RegSetKeyValueW" (BYVAL hKey AS DWORD, lpSubKey AS WSTRINGZ, _
    lpValueName AS WSTRINGZ, BYVAL dwType AS DWORD, lpData AS ANY, _
    BYVAL cbData AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO RegSetKeyValue=RegSetKeyValueW
#ELSE
MACRO RegSetKeyValue=RegSetKeyValueA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegDeleteTreeA LIB "AdvApi32.dll" ALIAS "RegDeleteTreeA" _
    (BYVAL hTree AS DWORD, lpSubKey AS ASCIIZ) AS LONG

DECLARE FUNCTION RegDeleteTreeW LIB "AdvApi32.dll" ALIAS "RegDeleteTreeW" _
    (BYVAL hTree AS DWORD, lpSubKey AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO RegDeleteTree=RegDeleteTreeW
#ELSE
MACRO RegDeleteTree=RegDeleteTreeA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegCopyTreeA LIB "AdvApi32.dll" ALIAS "RegCopyTreeA" _
    (BYVAL hKeySrc AS DWORD, lpSubKey AS ASCIIZ, BYVAL hKeyDest AS DWORD) _
    AS LONG

DECLARE FUNCTION RegCopyTreeW LIB "AdvApi32.dll" ALIAS "RegCopyTreeW" _
    (BYVAL hKeySrc AS DWORD, lpSubKey AS WSTRINGZ, BYVAL hKeyDest AS DWORD) _
    AS LONG

#IF %DEF(%UNICODE)
MACRO RegCopyTree=RegCopyTreeW
#ELSE
MACRO RegCopyTree=RegCopyTreeA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegGetValueA LIB "AdvApi32.dll" ALIAS "RegGetValueA" _
    (BYVAL hKey AS DWORD, lpSubKey AS ASCIIZ, lpValue AS ASCIIZ, _
    BYVAL dwFlags AS DWORD, pdwType AS DWORD, pvData AS DWORD, _
    pcbData AS DWORD) AS LONG

DECLARE FUNCTION RegGetValueW LIB "AdvApi32.dll" ALIAS "RegGetValueW" _
    (BYVAL hKey AS DWORD, lpSubKey AS WSTRINGZ, lpValue AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD, pdwType AS DWORD, pvData AS DWORD, _
    pcbData AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO RegGetValue=RegGetValueW
#ELSE
MACRO RegGetValue=RegGetValueA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegLoadMUIStringA LIB "AdvApi32.dll" _
    ALIAS "RegLoadMUIStringA" (BYVAL hKey AS DWORD, pszValue AS ASCIIZ, _
    pszOutBuf AS ASCIIZ, BYVAL cbOutBuf AS DWORD, pcbData AS DWORD, _
    BYVAL dFlags AS DWORD, pszDirectory AS ASCIIZ) AS LONG

DECLARE FUNCTION RegLoadMUIStringW LIB "AdvApi32.dll" _
    ALIAS "RegLoadMUIStringW" (BYVAL hKey AS DWORD, pszValue AS WSTRINGZ, _
    pszOutBuf AS WSTRINGZ, BYVAL cbOutBuf AS DWORD, pcbData AS DWORD, _
    BYVAL dFlags AS DWORD, pszDirectory AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO RegLoadMUIString=RegLoadMUIStringW
#ELSE
MACRO RegLoadMUIString=RegLoadMUIStringA
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION RegLoadAppKeyA LIB "AdvApi32.dll" ALIAS "RegLoadAppKeyA" _
    (lpFile AS ASCIIZ, phkResult AS DWORD, BYVAL samDesired AS DWORD, _
    BYVAL dwOptions AS DWORD, BYVAL Reserved AS DWORD) AS LONG

DECLARE FUNCTION RegLoadAppKeyW LIB "AdvApi32.dll" ALIAS "RegLoadAppKeyW" _
    (lpFile AS WSTRINGZ, phkResult AS DWORD, BYVAL samDesired AS DWORD, _
    BYVAL dwOptions AS DWORD, BYVAL Reserved AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO RegLoadAppKey=RegLoadAppKeyW
#ELSE
MACRO RegLoadAppKey=RegLoadAppKeyA
#ENDIF ' NOT %UNICODE

#ENDIF ' _WIN32_WINNT >= &H0600

'
' Remoteable System Shutdown APIs
'

DECLARE FUNCTION InitiateSystemShutdownA LIB "AdvApi32.dll" _
    ALIAS "InitiateSystemShutdownA" (lpMachineName AS ASCIIZ, _
    lpMessage AS ASCIIZ, BYVAL dwTimeout AS DWORD, _
    BYVAL bForceAppsClosed AS LONG, BYVAL bRebootAfterShutdown AS LONG) AS LONG

DECLARE FUNCTION InitiateSystemShutdownW LIB "AdvApi32.dll" _
    ALIAS "InitiateSystemShutdownW" (lpMachineName AS WSTRINGZ, _
    lpMessage AS WSTRINGZ, BYVAL dwTimeout AS DWORD, _
    BYVAL bForceAppsClosed AS LONG, BYVAL bRebootAfterShutdown AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO InitiateSystemShutdown=InitiateSystemShutdownW
#ELSE
MACRO InitiateSystemShutdown=InitiateSystemShutdownA
#ENDIF ' NOT %UNICODE


DECLARE FUNCTION AbortSystemShutdownA LIB "AdvApi32.dll" _
    ALIAS "AbortSystemShutdownA" (lpMachineName AS ASCIIZ) AS LONG

DECLARE FUNCTION AbortSystemShutdownW LIB "AdvApi32.dll" _
    ALIAS "AbortSystemShutdownW" (lpMachineName AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO AbortSystemShutdown=AbortSystemShutdownW
#ELSE
MACRO AbortSystemShutdown=AbortSystemShutdownA
#ENDIF ' NOT %UNICODE

'
' defines for InitiateSystemShutdownEx reason codes
'

#IF NOT %DEF(%REASON_INC)
#INCLUDE "Reason.inc"           ' get the public reasons
#ENDIF
'
' Then for Historical reasons support some old symbols, internal only

%REASON_SWINSTALL    = (%SHTDN_REASON_MAJOR_SOFTWARE OR %SHTDN_REASON_MINOR_INSTALLATION)
%REASON_HWINSTALL    = (%SHTDN_REASON_MAJOR_HARDWARE OR %SHTDN_REASON_MINOR_INSTALLATION)
%REASON_SERVICEHANG  = (%SHTDN_REASON_MAJOR_SOFTWARE OR %SHTDN_REASON_MINOR_HUNG)
%REASON_UNSTABLE     = (%SHTDN_REASON_MAJOR_SYSTEM OR %SHTDN_REASON_MINOR_UNSTABLE)
%REASON_SWHWRECONF   = (%SHTDN_REASON_MAJOR_SOFTWARE OR %SHTDN_REASON_MINOR_RECONFIG)
%REASON_OTHER        = (%SHTDN_REASON_MAJOR_OTHER OR %SHTDN_REASON_MINOR_OTHER)
%REASON_UNKNOWN      = %SHTDN_REASON_UNKNOWN
%REASON_LEGACY_API   = %SHTDN_REASON_LEGACY_API
%REASON_PLANNED_FLAG = %SHTDN_REASON_FLAG_PLANNED

'
' MAX Shutdown TimeOut == 10 Years in seconds
'
%MAX_SHUTDOWN_TIMEOUT = (10*365*24*60*60)

DECLARE FUNCTION InitiateSystemShutdownExA LIB "AdvApi32.dll" _
    ALIAS "InitiateSystemShutdownExA" (lpMachineName AS ASCIIZ, _
    lpMessage AS ASCIIZ, BYVAL dwTimeout AS DWORD, _
    BYVAL bForceAppsClosed AS LONG, BYVAL bRebootAfterShutdown AS LONG, _
    BYVAL dwReason AS DWORD) AS LONG

DECLARE FUNCTION InitiateSystemShutdownExW LIB "AdvApi32.dll" _
    ALIAS "InitiateSystemShutdownExW" (lpMachineName AS WSTRINGZ, _
    lpMessage AS WSTRINGZ, BYVAL dwTimeout AS DWORD, _
    BYVAL bForceAppsClosed AS LONG, BYVAL bRebootAfterShutdown AS LONG, _
    BYVAL dwReason AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO InitiateSystemShutdownEx=InitiateSystemShutdownExW
#ELSE
MACRO InitiateSystemShutdownEx=InitiateSystemShutdownExA
#ENDIF ' NOT %UNICODE

'
' Shutdown flags
'

%SHUTDOWN_FORCE_OTHERS         = &H00000001
%SHUTDOWN_FORCE_SELF           = &H00000002
%SHUTDOWN_RESTART              = &H00000004
%SHUTDOWN_POWEROFF             = &H00000008
%SHUTDOWN_NOREBOOT             = &H00000010
%SHUTDOWN_GRACE_OVERRIDE       = &H00000020
%SHUTDOWN_INSTALL_UPDATES      = &H00000040
%SHUTDOWN_RESTARTAPPS          = &H00000080
%SHUTDOWN_SKIP_SVC_PRESHUTDOWN = &H00000100


DECLARE FUNCTION InitiateShutdownA LIB "AdvApi32.dll" _
    ALIAS "InitiateShutdownA" (lpMachineName AS ASCIIZ, lpMessage AS ASCIIZ, _
    BYVAL dwGracePeriod AS DWORD, BYVAL dwShutdownFlags AS DWORD, _
    BYVAL dwReason AS DWORD) AS DWORD

DECLARE FUNCTION InitiateShutdownW LIB "AdvApi32.dll" _
    ALIAS "InitiateShutdownW" (lpMachineName AS WSTRINGZ, _
    lpMessage AS WSTRINGZ, BYVAL dwGracePeriod AS DWORD, _
    BYVAL dwShutdownFlags AS DWORD, BYVAL dwReason AS DWORD) AS DWORD

#IF %DEF(%UNICODE)
MACRO InitiateShutdown=InitiateShutdownW
#ELSE
MACRO InitiateShutdown=InitiateShutdownA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION RegSaveKeyExA LIB "AdvApi32.dll" ALIAS "RegSaveKeyExA" _
    (BYVAL hKey AS DWORD, lpFile AS ASCIIZ, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES, BYVAL dwFlags AS DWORD) _
    AS LONG

DECLARE FUNCTION RegSaveKeyExW LIB "AdvApi32.dll" ALIAS "RegSaveKeyExW" _
    (BYVAL hKey AS DWORD, lpFile AS WSTRINGZ, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES, BYVAL dwFlags AS DWORD) _
    AS LONG

#IF %DEF(%UNICODE)
MACRO RegSaveKeyEx=RegSaveKeyExW
#ELSE
MACRO RegSaveKeyEx=RegSaveKeyExA
#ENDIF ' NOT %UNICODE
