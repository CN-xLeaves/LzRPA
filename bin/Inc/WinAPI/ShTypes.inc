'------------------------------------------------------------------------------
'
'  ShTypes.inc
'
'  Copyright (c) 2009-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from ShTypes.h dated 14 Jul 2009
'------------------------------------------------------------------------------

' verify that the <rpcndr.h> version is high enough to compile this file
#IF NOT %DEF(%REQUIRED_RPCNDR_H_VERSION)
%REQUIRED_RPCNDR_H_VERSION = 500
#ENDIF

' verify that the <rpcsal.h> version is high enough to compile this file
#IF NOT %DEF(%REQUIRED_RPCSAL_H_VERSION)
%REQUIRED_RPCSAL_H_VERSION = 100
#ENDIF

'#include "rpc.inc"
'#include "rpcndr.inc"

'#IF NOT %DEF(%RPCNDR_H_VERSION)
'#DEBUG PRINT "this stub requires an updated version OF RpcNdr.inc"
'#ENDIF ' %RPCNDR_H_VERSION

#INCLUDE THIS ONCE

%shtypes_h = 1

' Forward Declarations

' header files for imported files
#INCLUDE "SdkDdkVer.inc"
#INCLUDE "WTypes.inc"


' interface __MIDL_itf_shtypes_0000_0000
' [local]

'===========================================================================
'
' Object identifiers in the explorer's name space (ItemID and IDList)
'
'  All the items that the user can browse with the explorer (such as files,
' directories, servers, work-groups, etc.) has an identifier which is unique
' among items within the parent folder. Those identifiers are called item
' IDs (SHITEMID). Since all its parent folders have their own item IDs,
' any items can be uniquely identified by a list of item IDs, which is called
' an ID list (ITEMIDLIST).
'
'  ID lists are almost always allocated by the task allocator (see some
' description below as well as OLE 2.0 SDK) and may be passed across
' some of shell interfaces (such as IShellFolder). Each item ID in an ID list
' is only meaningful to its parent folder (which has generated it), and all
' the clients must treat it as an opaque binary data except the first two
' bytes, which indicates the size of the item ID.
'
'  When a shell extension -- which implements the IShellFolder interace --
' generates an item ID, it may put any information in it, not only the data
' with that it needs to identifies the item, but also some additional
' information, which would help implementing some other functions efficiently.
' For example, the shell's IShellFolder implementation of file system items
' stores the primary (long) name of a file or a directory as the item
' identifier, but it also stores its alternative (short) name, size and date
' etc.
'
'  When an ID list is passed to one of shell APIs (such as SHGetPathFromIDList),
' it is always an absolute path -- relative from the root of the name space,
' which is the desktop folder. When an ID list is passed to one of IShellFolder
' member function, it is always a relative path from the folder (unless it
' is explicitly specified).
'
'===========================================================================
'
' SHITEMID -- Item ID  (mkid)
'     USHORT      cb;             ' Size of the ID (including cb itself)
'     BYTE        abID[];         ' The item ID (variable length)
'

TYPE SHITEMID
    cb      AS WORD
    abID(0) AS BYTE
END TYPE

'
' ITEMIDLIST -- List if item IDs (combined with 0-terminator)
'
TYPE ITEMIDLIST
    mkid AS SHITEMID
END TYPE

TYPE ITEMIDLIST_RELATIVE
    ITEMIDLIST
END TYPE

TYPE ITEMID_CHILD
    ITEMIDLIST
END TYPE

TYPE ITEMIDLIST_ABSOLUTE
    ITEMIDLIST
END TYPE

#IF %DEF(%MIDL_PASS)
TYPE WIN32_FIND_DATAA
    dwFileAttributes   AS DWORD
    ftCreationTime     AS FILETIME
    ftLastAccessTime   AS FILETIME
    ftLastWriteTime    AS FILETIME
    nFileSizeHigh      AS DWORD
    nFileSizeLow       AS DWORD
    dwReserved0        AS DWORD
    dwReserved1        AS DWORD
    cFileName          AS ASCIIZ * 260
    cAlternateFileName AS ASCIIZ * 14
END TYPE

TYPE WIN32_FIND_DATAW
    dwFileAttributes   AS DWORD
    ftCreationTime     AS FILETIME
    ftLastAccessTime   AS FILETIME
    ftLastWriteTime    AS FILETIME
    nFileSizeHigh      AS DWORD
    nFileSizeLow       AS DWORD
    dwReserved0        AS DWORD
    dwReserved1        AS DWORD
    cFileName          AS WSTRINGZ * 260
    cAlternateFileName AS WSTRINGZ * 14
END TYPE

#ENDIF ' MIDL_PASS
'-------------------------------------------------------------------------
'
' struct STRRET
'
' structure for returning strings from IShellFolder member functions
'
'-------------------------------------------------------------------------
'
'  uType indicate which union member to use
'    STRRET_WSTR    Use STRRET.pOleStr     must be freed by caller of GetDisplayNameOf
'    STRRET_OFFSET  Use STRRET.uOffset     Offset into SHITEMID for ANSI string
'    STRRET_CSTR    Use STRRET.cStr        ANSI Buffer
'
MACRO STRRET_TYPE_enum=LONG
ENUM STRRET_TYPE SINGULAR
    STRRET_WSTR
    STRRET_OFFSET
    STRRET_CSTR
END ENUM

UNION STRRET_union
    pOleStr AS WSTRINGZ PTR
    uOffset AS DWORD
    cStr    AS ASCIIZ * 260
END UNION

TYPE STRRET QWORD FILL
    uType   AS DWORD
    STRRET_union
END TYPE

'-------------------------------------------------------------------------
'
' struct SHELLDETAILS
'
' structure for returning strings from IShellDetails
'
'-------------------------------------------------------------------------
'
'  fmt;            ' LVCFMT_* value (header only)
'  cxChar;         ' Number of 'average' characters (header only)
'  str;            ' String information
'
TYPE SHELLDETAILS
    fmt    AS LONG
    cxChar AS LONG
    str    AS STRRET
END TYPE

#IF (%WIN32_IE >= %WIN32_IE_IE60SP2)
MACRO PERCEIVED_enum=LONG
ENUM PERCEIVED SINGULAR
    PERCEIVED_TYPE_FIRST       = -3
    PERCEIVED_TYPE_CUSTOM      = -3
    PERCEIVED_TYPE_UNSPECIFIED
    PERCEIVED_TYPE_FOLDER
    PERCEIVED_TYPE_UNKNOWN
    PERCEIVED_TYPE_TEXT
    PERCEIVED_TYPE_IMAGE
    PERCEIVED_TYPE_AUDIO
    PERCEIVED_TYPE_VIDEO
    PERCEIVED_TYPE_COMPRESSED
    PERCEIVED_TYPE_DOCUMENT
    PERCEIVED_TYPE_SYSTEM
    PERCEIVED_TYPE_APPLICATION
    PERCEIVED_TYPE_GAMEMEDIA
    PERCEIVED_TYPE_CONTACTS
    PERCEIVED_TYPE_LAST        = 10
END ENUM

MACRO PERCEIVEDFLAG_enum=DWORD
ENUM PERCEIVEDFLAG BITS SINGULAR
    PERCEIVEDFLAG_UNDEFINED
    PERCEIVEDFLAG_SOFTCODED
    PERCEIVEDFLAG_HARDCODED
    PERCEIVEDFLAG_NATIVESUPPORT
    PERCEIVEDFLAG_reserved
    PERCEIVEDFLAG_GDIPLUS
    PERCEIVEDFLAG_WMSDK
    PERCEIVEDFLAG_ZIPFOLDER
END ENUM

#ENDIF  ' %WIN32_IE_IE60SP2

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
TYPE COMDLG_FILTERSPEC
    pszName AS WSTRINGZ PTR
    pszSpec AS WSTRINGZ PTR
END TYPE

MACRO KNOWNFOLDERID=GUID

#ENDIF  ' %NTDDI_VISTA

MACRO KF_REDIRECT_FLAGS=DWORD
MACRO FOLDERTYPEID=GUID

MACRO TASKOWNERID=GUID

#IF NOT %DEF(%LF_FACESIZE)
TYPE LOGFONTA
    lfHeight         AS LONG
    lfWidth          AS LONG
    lfEscapement     AS LONG
    lfOrientation    AS LONG
    lfWeight         AS LONG
    lfItalic         AS BYTE
    lfUnderline      AS BYTE
    lfStrikeOut      AS BYTE
    lfCharSet        AS BYTE
    lfOutPrecision   AS BYTE
    lfClipPrecision  AS BYTE
    lfQuality        AS BYTE
    lfPitchAndFamily AS BYTE
    lfFaceName       AS ASCIIZ * 32
END TYPE

TYPE LOGFONTW
    lfHeight         AS LONG
    lfWidth          AS LONG
    lfEscapement     AS LONG
    lfOrientation    AS LONG
    lfWeight         AS LONG
    lfItalic         AS BYTE
    lfUnderline      AS BYTE
    lfStrikeOut      AS BYTE
    lfCharSet        AS BYTE
    lfOutPrecision   AS BYTE
    lfClipPrecision  AS BYTE
    lfQuality        AS BYTE
    lfPitchAndFamily AS BYTE
    lfFaceName       AS WSTRINGZ * 32
END TYPE

TYPE LOGFONT
    LOGFONTA
END TYPE

#ENDIF ' LF_FACESIZE

MACRO SHCOLSTATE_enum=LONG
ENUM SHCOLSTATE BITS SINGULAR
    SHCOLSTATE_DEFAULT
    SHCOLSTATE_TYPE_STR
    SHCOLSTATE_TYPE_INT
    SHCOLSTATE_TYPE_DATE   = &H00000003
    SHCOLSTATE_TYPEMASK    = &H0000000f
    SHCOLSTATE_ONBYDEFAULT = &H00000010
    SHCOLSTATE_SLOW
    SHCOLSTATE_EXTENDED
    SHCOLSTATE_SECONDARYUI
    SHCOLSTATE_HIDDEN
    SHCOLSTATE_PREFER_VARCMP
    SHCOLSTATE_PREFER_FMTCMP
    SHCOLSTATE_NOSORTBYFOLDERNESS
    SHCOLSTATE_FIXED_WIDTH
    SHCOLSTATE_NODPISCALE
    SHCOLSTATE_FIXED_RATIO
    SHCOLSTATE_DISPLAYMASK = &H0000f000
    SHCOLSTATE_VIEWONLY    = &H00010000
    SHCOLSTATE_BATCHREAD
    SHCOLSTATE_NO_GROUPBY
END ENUM

MACRO SHCOLSTATEF=DWORD

TYPE SHCOLUMNID
    PROPERTYKEY
END TYPE
