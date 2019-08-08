'------------------------------------------------------------------------------
'
'  WTypes.inc
'
'  Copyright (c) 2003-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from WTypes.h of 14 Jul 2009
'------------------------------------------------------------------------------


#INCLUDE THIS ONCE

%WTYPES_H = 1


' Forward Declarations

' header files for imported files
'#include "guiddef.inc"


#IF NOT %DEF(%IWinTypes_INTERFACE_DEFINED)

%IWinTypes_INTERFACE_DEFINED = 1

' interface IWinTypes
' [unique][version][uuid]

#IF NOT %DEF(%PALETTEENTRY_DEFINED)

    %PALETTEENTRY_DEFINED = 1

    TYPE PALETTEENTRY
        peRed   AS BYTE
        peGreen AS BYTE
        peBlue  AS BYTE
        peFlags AS BYTE
    END TYPE

#ENDIF ' NOT %PALETTEENTRY_DEFINED


#IF NOT %DEF(%LOGPALETTE_DEFINED)

    %LOGPALETTE_DEFINED = 1

    TYPE LOGPALETTE
        palVersion     AS WORD
        palNumEntries  AS WORD
        palPalEntry(0) AS PALETTEENTRY
    END TYPE

#ENDIF ' NOT %LOGPALETTE_DEFINED


#IF NOT %DEF(%FILETIME)
%FILETIME = 1

TYPE FILETIME_dword
    dwLowDateTime  AS DWORD
    dwHighDateTime AS DWORD
END TYPE

TYPE FILETIME_quad
    qDateTime      AS QUAD
END TYPE

UNION FILETIME
    FILETIME_dword
    FILETIME_quad
END UNION
#ENDIF


TYPE SYSTEMTIME
    wYear         AS WORD
    wMonth        AS WORD
    wDayOfWeek    AS WORD
    wDay          AS WORD
    wHour         AS WORD
    wMinute       AS WORD
    wSecond       AS WORD
    wMilliseconds AS WORD
END TYPE

TYPE SECURITY_ATTRIBUTES
    nLength              AS DWORD
    lpSecurityDescriptor AS DWORD
    bInheritHandle       AS LONG
END TYPE


#IF NOT %DEF(%SID_IDENTIFIER_AUTHORITY_DEFINED)
%SID_IDENTIFIER_AUTHORITY_DEFINED = 1
TYPE SID_IDENTIFIER_AUTHORITY
    Value(5) AS BYTE
END TYPE
#ENDIF

#IF NOT %DEF(%SID_DEFINED)
%SID_DEFINED = 1
TYPE SID
    Revision            AS BYTE
    SubAuthorityCount   AS BYTE
    IdentifierAuthority AS SID_IDENTIFIER_AUTHORITY
    SubAuthority(0)     AS DWORD
END TYPE
#ENDIF


#IF NOT %DEF(%SECURITY_DESCRIPTOR_REVISION)
%SECURITY_DESCRIPTOR_REVISION = 1

TYPE ACL
    AclRevision AS BYTE
    Sbz1        AS BYTE
    AclSize     AS WORD
    AceCount    AS WORD
    Sbz2        AS WORD
END TYPE

TYPE SECURITY_DESCRIPTOR
    Revision AS BYTE
    Sbz1     AS BYTE
    wControl AS WORD  ' SECURITY_DESCRIPTOR_CONTROL
    Owner    AS SID PTR
    Group    AS SID PTR
    Sacl     AS ACL PTR
    Dacl     AS ACL PTR
END TYPE

#ENDIF ' !SECURITY_DESCRIPTOR_REVISION



TYPE COAUTHIDENTITY
    USER           AS WORD PTR
    UserLength     AS DWORD
    Domain         AS WORD PTR
    DomainLength   AS DWORD
    Password       AS WORD PTR
    PasswordLength AS DWORD
    Flags          AS DWORD
END TYPE

TYPE COAUTHINFO
    dwAuthnSvc           AS DWORD
    dwAuthzSvc           AS DWORD
    pwszServerPrincName  AS WSTRINGZ PTR
    dwAuthnLevel         AS DWORD
    dwImpersonationLevel AS DWORD
    pAuthIdentityData    AS COAUTHIDENTITY PTR
    dwCapabilities       AS DWORD
END TYPE

TYPE OBJECTID
    Lineage    AS GUID
    Uniquifier AS DWORD
END TYPE

MACRO MEMCTX_enum=LONG
ENUM MEMCTX SINGULAR
    MEMCTX_SAME     = -2
    MEMCTX_UNKNOWN
    MEMCTX_reserved1
    MEMCTX_TASK
    MEMCTX_SHARED
    MEMCTX_MACSYSTEM
END ENUM

%ROTFLAGS_REGISTRATIONKEEPSALIVE = 1
%ROTFLAGS_ALLOWANYCLIENT         = 2

%ROTREGFLAGS_ALLOWANYCLIENT = 1

%APPIDREGFLAGS_ACTIVATE_IUSERVER_INDESKTOP       = &H1
%APPIDREGFLAGS_SECURE_SERVER_PROCESS_SD_AND_BIND = &H2
%APPIDREGFLAGS_ISSUE_ACTIVATION_RPC_AT_IDENTIFY  = &H4


%ROT_COMPARE_MAX = 2048

%DCOMSCM_ACTIVATION_USE_ALL_AUTHNSERVICES  = &H1
%DCOMSCM_ACTIVATION_DISALLOW_UNSECURE_CALL = &H2
%DCOMSCM_RESOLVE_USE_ALL_AUTHNSERVICES     = &H4
%DCOMSCM_RESOLVE_DISALLOW_UNSECURE_CALL    = &H8
%DCOMSCM_PING_USE_MID_AUTHNSERVICE         = &H10
%DCOMSCM_PING_DISALLOW_UNSECURE_CALL       = &H20

MACRO CLSCTX_enum=DWORD
ENUM CLSCTX SINGULAR BITS
    CLSCTX_INPROC_SERVER           = &H1
    CLSCTX_INPROC_HANDLER
    CLSCTX_LOCAL_SERVER
    CLSCTX_INPROC_SERVER16
    CLSCTX_REMOTE_SERVER
    CLSCTX_INPROC_HANDLER16
    CLSCTX_RESERVED1
    CLSCTX_RESERVED2
    CLSCTX_RESERVED3
    CLSCTX_RESERVED4
    CLSCTX_NO_CODE_DOWNLOAD
    CLSCTX_RESERVED5
    CLSCTX_NO_CUSTOM_MARSHAL
    CLSCTX_ENABLE_CODE_DOWNLOAD
    CLSCTX_NO_FAILURE_LOG
    CLSCTX_DISABLE_AAA
    CLSCTX_ENABLE_AAA
    CLSCTX_FROM_DEFAULT_CONTEXT
    CLSCTX_ACTIVATE_32_BIT_SERVER
    CLSCTX_ACTIVATE_64_BIT_SERVER
    CLSCTX_ENABLE_CLOAKING
    CLSCTX_PS_DLL                  = &H80000000???
END ENUM

%CLSCTX_VALID_MASK = %CLSCTX_INPROC_SERVER  _
    OR %CLSCTX_INPROC_HANDLER  _
    OR %CLSCTX_LOCAL_SERVER  _
    OR %CLSCTX_INPROC_SERVER16  _
    OR %CLSCTX_REMOTE_SERVER  _
    OR %CLSCTX_NO_CODE_DOWNLOAD  _
    OR %CLSCTX_NO_CUSTOM_MARSHAL  _
    OR %CLSCTX_ENABLE_CODE_DOWNLOAD  _
    OR %CLSCTX_NO_FAILURE_LOG  _
    OR %CLSCTX_DISABLE_AAA  _
    OR %CLSCTX_ENABLE_AAA  _
    OR %CLSCTX_FROM_DEFAULT_CONTEXT  _
    OR %CLSCTX_ACTIVATE_32_BIT_SERVER  _
    OR %CLSCTX_ACTIVATE_64_BIT_SERVER  _
    OR %CLSCTX_ENABLE_CLOAKING  _
    OR %CLSCTX_PS_DLL

MACRO MSHLFLAGS_enum=LONG
ENUM MSHLFLAGS SINGULAR BITS
    MSHLFLAGS_NORMAL
    MSHLFLAGS_TABLESTRONG
    MSHLFLAGS_TABLEWEAK
    MSHLFLAGS_NOPING
    MSHLFLAGS_RESERVED1
    MSHLFLAGS_RESERVED2
    MSHLFLAGS_RESERVED3
    MSHLFLAGS_RESERVED4
END ENUM

MACRO MSHCTX_enum=LONG
ENUM MSHCTX SINGULAR
    MSHCTX_LOCAL
    MSHCTX_NOSHAREDMEM
    MSHCTX_DIFFERENTMACHINE
    MSHCTX_INPROC
    MSHCTX_CROSSCTX
END ENUM

MACRO DVASPECT_enum=LONG
ENUM DVASPECT SINGULAR BITS
    DVASPECT_CONTENT   = 1
    DVASPECT_THUMBNAIL
    DVASPECT_ICON
    DVASPECT_DOCPRINT
END ENUM

MACRO STGC_enum=LONG
ENUM STGC SINGULAR BITS
    STGC_DEFAULT
    STGC_OVERWRITE
    STGC_ONLYIFCURRENT
    STGC_DANGEROUSLYCOMMITMERELYTODISKCACHE
    STGC_CONSOLIDATE
END ENUM

MACRO STGMOVE_enum=LONG
ENUM STGMOVE SINGULAR
    STGMOVE_MOVE
    STGMOVE_COPY
    STGMOVE_SHALLOWCOPY
END ENUM

MACRO STATFLAG_enum=LONG
ENUM STATFLAG SINGULAR
    STATFLAG_DEFAULT
    STATFLAG_NONAME
    STATFLAG_NOOPEN
END ENUM

'#ifndef _LCID_DEFINED
'#define _LCID_DEFINED
'typedef DWORD LCID;
'
'#endif // !_LCID_DEFINED
'#ifndef _LANGID_DEFINED
'#define _LANGID_DEFINED
'typedef USHORT LANGID;
'
'#endif // !_LANGID_DEFINED

TYPE BYTE_BLOB
    clSize    AS DWORD
    abData(0) AS BYTE
END TYPE

'typedef   BYTE_BLOB *UP_BYTE_BLOB;

TYPE WORD_BLOB
    clSize    AS DWORD
    asData(0) AS WORD
END TYPE

'typedef   WORD_BLOB *UP_WORD_BLOB;

TYPE DWORD_BLOB
    clSize    AS DWORD
    alData(0) AS DWORD
END TYPE

'typedef   DWORD_BLOB *UP_DWORD_BLOB;

TYPE FLAGGED_BYTE_BLOB
    fFlags    AS DWORD
    clSize    AS DWORD
    abData(0) AS BYTE
END TYPE

'typedef   FLAGGED_BYTE_BLOB *UP_FLAGGED_BYTE_BLOB;

TYPE FLAGGED_WORD_BLOB
    fFlags    AS DWORD
    clSize    AS DWORD
    asData(0) AS WORD
END TYPE

'typedef   FLAGGED_WORD_BLOB *UP_FLAGGED_WORD_BLOB;

TYPE BYTE_SIZEDARR
    clSize AS DWORD
    pData  AS BYTE PTR
END TYPE

TYPE WORD_SIZEDARR
    clSize AS DWORD
    pData  AS WORD PTR
END TYPE

TYPE DWORD_SIZEDARR
    clSize AS DWORD
    pData  AS DWORD PTR
END TYPE

TYPE HYPER_SIZEDARR
    clSize AS DWORD
    pData  AS QUAD PTR  ' hyper ptr
END TYPE


%WDT_INPROC_CALL = &H48746457

%WDT_REMOTE_CALL = &H52746457

%WDT_INPROC64_CALL   = &H50746457

TYPE TEXTMETRICW DWORD FILL
    tmHeight           AS LONG
    tmAscent           AS LONG
    tmDescent          AS LONG
    tmInternalLeading  AS LONG
    tmExternalLeading  AS LONG
    tmAveCharWidth     AS LONG
    tmMaxCharWidth     AS LONG
    tmWeight           AS LONG
    tmOverhang         AS LONG
    tmDigitizedAspectX AS LONG
    tmDigitizedAspectY AS LONG
    tmFirstChar        AS WSTRING * 1
    tmLastChar         AS WSTRING * 1
    tmDefaultChar      AS WSTRING * 1
    tmBreakChar        AS WSTRING * 1
    tmItalic           AS BYTE
    tmUnderlined       AS BYTE
    tmStruckOut        AS BYTE
    tmPitchAndFamily   AS BYTE
    tmCharSet          AS BYTE
END TYPE

#ENDIF ' %IWinTypes_INTERFACE_DEFINED



TYPE DECIMAL_type1
    SCALE AS BYTE
    sign  AS BYTE
END TYPE

UNION DECIMAL_union1
    DECIMAL_type1
    signscale AS WORD
END UNION

TYPE DECIMAL_type2
    Lo32  AS DWORD
    Mid32 AS DWORD
END TYPE

UNION DECIMAL_union2
    DECIMAL_type2
    Lo64 AS QUAD
END UNION

TYPE DECIMAL
    wReserved AS WORD
    DECIMAL_union1
    Hi32      AS DWORD
    DECIMAL_union2
END TYPE

%DECIMAL_NEG = &H80?

MACRO DECIMAL_SETZERO(dec)
    dec.Lo64 = 0
    dec.Hi32 = 0
    dec.signscale = 0
END MACRO

MACRO wireBSTR=FLAGGED_WORD_BLOB PTR

MACRO VARIANT_BOOL=INTEGER


' The BSTRBLOB structure is used by some implementations
' of the IPropertyStorage interface when marshaling BSTRs
' on systems which don't support BSTR marshaling.

TYPE BSTRBLOB
    cbSize AS DWORD
    pData  AS BYTE PTR
END TYPE

%VARIANT_TRUE  = -1
%VARIANT_FALSE = 0

TYPE BLOB
    cbSize    AS DWORD
    pBlobData AS BYTE PTR
END TYPE

TYPE CLIPDATA
    cbSize    AS DWORD
    ulClipFmt AS LONG
    pClipData AS BYTE PTR
END TYPE

' Macro to calculate the size of the above pClipData
MACRO CBPCLIPDATA(vbl)=(vbl.cbSize-SIZEOF(vbl.ulClipFmt))

MACRO VARTYPE=WORD

'
' VARENUM usage key,
'
'   [V] - may appear in a VARIANT
'   [T] - may appear in a TYPEDESC
'   [P] - may appear in an OLE property set
'   [S] - may appear in a Safe Array
'
'
'  VT_EMPTY            [V]   [P]     nothing
'  VT_NULL             [V]   [P]     SQL style Null
'  VT_I2               [V][T][P][S]  2 byte signed int
'  VT_I4               [V][T][P][S]  4 byte signed int
'  VT_R4               [V][T][P][S]  4 byte real
'  VT_R8               [V][T][P][S]  8 byte real
'  VT_CY               [V][T][P][S]  currency
'  VT_DATE             [V][T][P][S]  date
'  VT_BSTR             [V][T][P][S]  OLE Automation string
'  VT_DISPATCH         [V][T]   [S]  IDispatch'
'  VT_ERROR            [V][T][P][S]  SCODE
'  VT_BOOL             [V][T][P][S]  True=-1, False=0
'  VT_VARIANT          [V][T][P][S]  VARIANT'
'  VT_UNKNOWN          [V][T]   [S]  IUnknown'
'  VT_DECIMAL          [V][T]   [S]  16 byte fixed point
'  VT_RECORD           [V]   [P][S]  user defined type
'  VT_I1               [V][T][P][s]  signed char
'  VT_UI1              [V][T][P][S]  unsigned char
'  VT_UI2              [V][T][P][S]  unsigned short
'  VT_UI4              [V][T][P][S]  unsigned long
'  VT_I8                  [T][P]     signed 64-bit int
'  VT_UI8                 [T][P]     unsigned 64-bit int
'  VT_INT              [V][T][P][S]  signed machine int
'  VT_UINT             [V][T]   [S]  unsigned machine int
'  VT_INT_PTR             [T]        signed machine register size width
'  VT_UINT_PTR            [T]        unsigned machine register size width
'  VT_VOID                [T]        C style void
'  VT_HRESULT             [T]        Standard return type
'  VT_PTR                 [T]        pointer type
'  VT_SAFEARRAY           [T]        (use VT_ARRAY in VARIANT)
'  VT_CARRAY              [T]        C style array
'  VT_USERDEFINED         [T]        user defined type
'  VT_LPSTR               [T][P]     null terminated string
'  VT_LPWSTR              [T][P]     wide null terminated string
'  VT_FILETIME               [P]     FILETIME
'  VT_BLOB                   [P]     Length prefixed bytes
'  VT_STREAM                 [P]     Name of the stream follows
'  VT_STORAGE                [P]     Name of the storage follows
'  VT_STREAMED_OBJECT        [P]     Stream contains an object
'  VT_STORED_OBJECT          [P]     Storage contains an object
'  VT_VERSIONED_STREAM       [P]     Stream with a GUID version
'  VT_BLOB_OBJECT            [P]     Blob contains an object
'  VT_CF                     [P]     Clipboard format
'  VT_CLSID                  [P]     A Class ID
'  VT_VECTOR                 [P]     simple counted array
'  VT_ARRAY            [V]           SAFEARRAY*
'  VT_BYREF            [V]           void* for local use
'  VT_BSTR_BLOB                      Reserved for system use
'

MACRO VARENUM_enum=LONG
ENUM VARENUM SINGULAR
    VT_EMPTY
    VT_NULL
    VT_I2
    VT_I4
    VT_R4
    VT_R8
    VT_CY
    VT_DATE
    VT_BSTR
    VT_DISPATCH
    VT_ERROR
    VT_BOOL
    VT_VARIANT
    VT_UNKNOWN
    VT_DECIMAL
    VT_reserved1
    VT_I1
    VT_UI1
    VT_UI2
    VT_UI4
    VT_I8
    VT_UI8
    VT_INT
    VT_UINT
    VT_VOID
    VT_HRESULT
    VT_PTR
    VT_SAFEARRAY
    VT_CARRAY
    VT_USERDEFINED
    VT_LPSTR
    VT_LPWSTR
    VT_RECORD   = 36
    VT_INT_PTR
    VT_UINT_PTR
    VT_FILETIME = 64
    VT_BLOB
    VT_STREAM
    VT_STORAGE
    VT_STREAMED_OBJECT
    VT_STORED_OBJECT
    VT_BLOB_OBJECT
    VT_CF
    VT_CLSID
    VT_VERSIONED_STREAM
    VT_BSTR_BLOB     = &H00000fff
    VT_VECTOR        = &H00001000
    VT_ARRAY         = &H00002000
    VT_BYREF         = &H00004000
    VT_RESERVED      = &H00008000
    VT_ILLEGAL       = &H0000ffff
    VT_ILLEGALMASKED = &H00000fff
    VT_TYPEMASK      = &H00000fff
END ENUM  ' VARENUM

TYPE PROPERTYKEY
    fmtid AS GUID
    pid   AS DWORD
END TYPE

TYPE SID_AND_ATTRIBUTES
    pSid       AS SID PTR
    Attributes AS DWORD
END TYPE

TYPE CSPLATFORM
    dwPlatformId    AS DWORD
    dwVersionHi     AS DWORD
    dwVersionLo     AS DWORD
    dwProcessorArch AS DWORD
END TYPE

TYPE QUERYCONTEXT
    dwContext   AS DWORD
    Platform    AS CSPLATFORM
    Locale      AS DWORD ' LCID
    dwVersionHi AS DWORD
    dwVersionLo AS DWORD
END TYPE

MACRO TYSPEC_enum=LONG
ENUM TYSPEC SINGULAR
    TYSPEC_CLSID
    TYSPEC_FILEEXT
    TYSPEC_MIMETYPE
    TYSPEC_FILENAME
    TYSPEC_PROGID
    TYSPEC_PACKAGENAME
    TYSPEC_OBJECTID
END ENUM

TYPE uCLSSPEC_union_type1
    pPackageName AS WSTRINGZ PTR
    PolicyId     AS GUID
END TYPE

TYPE uCLSSPEC_union_type2
    ObjectId AS GUID
    PolicyId AS GUID
END TYPE

UNION uCLSSPEC_union
    clsid     AS GUID  ' CLSID
    pFileExt  AS WSTRINGZ PTR
    pMimeType AS WSTRINGZ PTR
    pProgId   AS WSTRINGZ PTR
    pFileName AS WSTRINGZ PTR
    ByName    AS uCLSSPEC_union_type1
    ByObjectId AS uCLSSPEC_union_type2
END UNION

TYPE uCLSSPEC
    tyspec AS DWORD
    uCLSSPEC_union
END TYPE
