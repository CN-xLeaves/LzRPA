'------------------------------------------------------------------------------
'
'  verrsrc.inc -- Version Resource definitions
'                 Include file declaring version resources in rc files
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from verrsrc.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

#INCLUDE "WinUser.inc"

' ----- Symbols -----
%VS_FILE_INFO          = %RT_VERSION
%VS_VERSION_INFO       = 1
%VS_USER_DEFINED       = 100

' ----- VS_VERSION.dwFileFlags -----
#IF NOT %DEF(%MAC)
%VS_FFI_SIGNATURE      = &HFEEF04BD???
#ELSE
%VS_FFI_SIGNATURE      = &HBD04EFFE???
#ENDIF
%VS_FFI_STRUCVERSION   = &H00010000
%VS_FFI_FILEFLAGSMASK  = &H0000003F

' ----- VS_VERSION.dwFileFlags -----
%VS_FF_DEBUG           = &H00000001
%VS_FF_PRERELEASE      = &H00000002
%VS_FF_PATCHED         = &H00000004
%VS_FF_PRIVATEBUILD    = &H00000008
%VS_FF_INFOINFERRED    = &H00000010
%VS_FF_SPECIALBUILD    = &H00000020

' ----- VS_VERSION.dwFileOS -----
%VOS_UNKNOWN           = &H00000000
%VOS_DOS               = &H00010000
%VOS_OS216             = &H00020000
%VOS_OS232             = &H00030000
%VOS_NT                = &H00040000
%VOS_WINCE             = &H00050000

%VOS__BASE             = &H00000000
%VOS__WINDOWS16        = &H00000001
%VOS__PM16             = &H00000002
%VOS__PM32             = &H00000003
%VOS__WINDOWS32        = &H00000004

%VOS_DOS_WINDOWS16     = &H00010001
%VOS_DOS_WINDOWS32     = &H00010004
%VOS_OS216_PM16        = &H00020002
%VOS_OS232_PM32        = &H00030003
%VOS_NT_WINDOWS32      = &H00040004

' ----- VS_VERSION.dwFileType -----
%VFT_UNKNOWN           = &H00000000
%VFT_APP               = &H00000001
%VFT_DLL               = &H00000002
%VFT_DRV               = &H00000003
%VFT_FONT              = &H00000004
%VFT_VXD               = &H00000005
%VFT_STATIC_LIB        = &H00000007

' ----- VS_VERSION.dwFileSubtype for VFT_WINDOWS_DRV -----
%VFT2_UNKNOWN          = &H00000000
%VFT2_DRV_PRINTER      = &H00000001
%VFT2_DRV_KEYBOARD     = &H00000002
%VFT2_DRV_LANGUAGE     = &H00000003
%VFT2_DRV_DISPLAY      = &H00000004
%VFT2_DRV_MOUSE        = &H00000005
%VFT2_DRV_NETWORK      = &H00000006
%VFT2_DRV_SYSTEM       = &H00000007
%VFT2_DRV_INSTALLABLE  = &H00000008
%VFT2_DRV_SOUND        = &H00000009
%VFT2_DRV_COMM         = &H0000000A
%VFT2_DRV_INPUTMETHOD  = &H0000000B
%VFT2_DRV_VERSIONED_PRINTER  = &H0000000C

' ----- VS_VERSION.dwFileSubtype for VFT_WINDOWS_FONT -----
%VFT2_FONT_RASTER      = &H00000001
%VFT2_FONT_VECTOR      = &H00000002
%VFT2_FONT_TRUETYPE    = &H00000003

' ----- VerFindFile() flags -----
%VFFF_ISSHAREDFILE     = &H0001

%VFF_CURNEDEST         = &H0001
%VFF_FILEINUSE         = &H0002
%VFF_BUFFTOOSMALL      = &H0004

' ----- VerInstallFile() flags -----
%VIFF_FORCEINSTALL     = &H0001
%VIFF_DONTDELETEOLD    = &H0002

%VIF_TEMPFILE          = &H00000001
%VIF_MISMATCH          = &H00000002
%VIF_SRCOLD            = &H00000004

%VIF_DIFFLANG          = &H00000008
%VIF_DIFFCODEPG        = &H00000010
%VIF_DIFFTYPE          = &H00000020

%VIF_WRITEPROT         = &H00000040
%VIF_FILEINUSE         = &H00000080
%VIF_OUTOFSPACE        = &H00000100
%VIF_ACCESSVIOLATION   = &H00000200
%VIF_SHARINGVIOLATION  = &H00000400
%VIF_CANNOTCREATE      = &H00000800
%VIF_CANNOTDELETE      = &H00001000
%VIF_CANNOTRENAME      = &H00002000
%VIF_CANNOTDELETECUR   = &H00004000
%VIF_OUTOFMEMORY       = &H00008000

%VIF_CANNOTREADSRC     = &H00010000
%VIF_CANNOTREADDST     = &H00020000

%VIF_BUFFTOOSMALL      = &H00040000
%VIF_CANNOTLOADLZ32    = &H00080000
%VIF_CANNOTLOADCABINET = &H00100000


'
'  FILE_VER_GET_... flags are for use by
'  GetFileVersionInfoSizeEx
'  GetFileVersionInfoExW
'
%FILE_VER_GET_LOCALISED  = &H01
%FILE_VER_GET_NEUTRAL    = &H02
%FILE_VER_GET_PREFETCHED = &H04

' ----- Types and structures -----

TYPE VS_FIXEDFILEINFO
    dwSignature        AS DWORD   ' e.g. &Hfeef04bd
    dwStrucVersion     AS DWORD   ' e.g. &H00000042 = "0.42"
    dwFileVersionMS    AS DWORD   ' e.g. &H00030075 = "3.75"
    dwFileVersionLS    AS DWORD   ' e.g. &H00000031 = "0.31"
    dwProductVersionMS AS DWORD   ' e.g. &H00030010 = "3.10"
    dwProductVersionLS AS DWORD   ' e.g. &H00000031 = "0.31"
    dwFileFlagsMask    AS DWORD   ' = &H3F for version "0.42"
    dwFileFlags        AS DWORD   ' e.g. VFF_DEBUG | VFF_PRERELEASE
    dwFileOS           AS DWORD   ' e.g. VOS_DOS_WINDOWS16
    dwFileType         AS DWORD   ' e.g. VFT_DRIVER
    dwFileSubtype      AS DWORD   ' e.g. VFT2_DRV_KEYBOARD
    dwFileDateMS       AS DWORD   ' e.g. 0
    dwFileDateLS       AS DWORD   ' e.g. 0
END TYPE
