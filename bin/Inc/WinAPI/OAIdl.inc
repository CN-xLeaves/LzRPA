'------------------------------------------------------------------------------
'
'  OAIdl.inc
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 17 Mar 2011
'
'------------------------------------------------------------------------------
'  from OAIdl.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

' verify that the <rpcndr.h> version is high enough to compile this file
#IF NOT %DEF(%REQUIRED_RPCNDR_H_VERSION)
%REQUIRED_RPCNDR_H_VERSION = 500
#ENDIF

' verify that the <rpcsal.h> version is high enough to compile this file
#IF NOT %DEF(%REQUIRED_RPCSAL_H_VERSION)
%REQUIRED_RPCSAL_H_VERSION = 100
#ENDIF

#INCLUDE "rpc.inc"
'#include "rpcndr.inc"
'
'#ifndef __RPCNDR_H_VERSION__
'#error this stub requires an updated version of <rpcndr.h>
'#endif ' __RPCNDR_H_VERSION__
'
'#if not %def(%COM_NO_WINDOWS_H)
'#include "windows.inc"
'#include "ole2.inc"
'#endif ' %COM_NO_WINDOWS_H

%oaidl_h = 1

#INCLUDE "WTypes.inc"


'' Forward Declarations
'
'#ifndef __ICreateTypeInfo_FWD_DEFINED__
'#define __ICreateTypeInfo_FWD_DEFINED__
'typedef interface ICreateTypeInfo ICreateTypeInfo;
'#endif  ' __ICreateTypeInfo_FWD_DEFINED__
'
'
'#ifndef __ICreateTypeInfo2_FWD_DEFINED__
'#define __ICreateTypeInfo2_FWD_DEFINED__
'typedef interface ICreateTypeInfo2 ICreateTypeInfo2;
'#endif  ' __ICreateTypeInfo2_FWD_DEFINED__
'
'
'#ifndef __ICreateTypeLib_FWD_DEFINED__
'#define __ICreateTypeLib_FWD_DEFINED__
'typedef interface ICreateTypeLib ICreateTypeLib;
'#endif  ' __ICreateTypeLib_FWD_DEFINED__
'
'
'#ifndef __ICreateTypeLib2_FWD_DEFINED__
'#define __ICreateTypeLib2_FWD_DEFINED__
'typedef interface ICreateTypeLib2 ICreateTypeLib2;
'#endif  ' __ICreateTypeLib2_FWD_DEFINED__
'
'
'#ifndef __IDispatch_FWD_DEFINED__
'#define __IDispatch_FWD_DEFINED__
'typedef interface IDispatch IDispatch;
'#endif  ' __IDispatch_FWD_DEFINED__
'
'
'#ifndef __IEnumVARIANT_FWD_DEFINED__
'#define __IEnumVARIANT_FWD_DEFINED__
'typedef interface IEnumVARIANT IEnumVARIANT;
'#endif  ' __IEnumVARIANT_FWD_DEFINED__
'
'
'#ifndef __ITypeComp_FWD_DEFINED__
'#define __ITypeComp_FWD_DEFINED__
'typedef interface ITypeComp ITypeComp;
'#endif  ' __ITypeComp_FWD_DEFINED__
'
'
'#ifndef __ITypeInfo_FWD_DEFINED__
'#define __ITypeInfo_FWD_DEFINED__
'typedef interface ITypeInfo ITypeInfo;
'#endif  ' __ITypeInfo_FWD_DEFINED__
'
'
'#ifndef __ITypeInfo2_FWD_DEFINED__
'#define __ITypeInfo2_FWD_DEFINED__
'typedef interface ITypeInfo2 ITypeInfo2;
'#endif  ' __ITypeInfo2_FWD_DEFINED__
'
'
'#ifndef __ITypeLib_FWD_DEFINED__
'#define __ITypeLib_FWD_DEFINED__
'typedef interface ITypeLib ITypeLib;
'#endif  ' __ITypeLib_FWD_DEFINED__
'
'
'#ifndef __ITypeLib2_FWD_DEFINED__
'#define __ITypeLib2_FWD_DEFINED__
'typedef interface ITypeLib2 ITypeLib2;
'#endif  ' __ITypeLib2_FWD_DEFINED__
'
'
'#ifndef __ITypeChangeEvents_FWD_DEFINED__
'#define __ITypeChangeEvents_FWD_DEFINED__
'typedef interface ITypeChangeEvents ITypeChangeEvents;
'#endif  ' __ITypeChangeEvents_FWD_DEFINED__
'
'
'#ifndef __IErrorInfo_FWD_DEFINED__
'#define __IErrorInfo_FWD_DEFINED__
'typedef interface IErrorInfo IErrorInfo;
'#endif  ' __IErrorInfo_FWD_DEFINED__
'
'
'#ifndef __ICreateErrorInfo_FWD_DEFINED__
'#define __ICreateErrorInfo_FWD_DEFINED__
'typedef interface ICreateErrorInfo ICreateErrorInfo;
'#endif  ' __ICreateErrorInfo_FWD_DEFINED__
'
'
'#ifndef __ISupportErrorInfo_FWD_DEFINED__
'#define __ISupportErrorInfo_FWD_DEFINED__
'typedef interface ISupportErrorInfo ISupportErrorInfo;
'#endif  ' __ISupportErrorInfo_FWD_DEFINED__
'
'
'#ifndef __ITypeFactory_FWD_DEFINED__
'#define __ITypeFactory_FWD_DEFINED__
'typedef interface ITypeFactory ITypeFactory;
'#endif  ' __ITypeFactory_FWD_DEFINED__
'
'
'#ifndef __ITypeMarshal_FWD_DEFINED__
'#define __ITypeMarshal_FWD_DEFINED__
'typedef interface ITypeMarshal ITypeMarshal;
'#endif  ' __ITypeMarshal_FWD_DEFINED__
'
'
'#ifndef __IRecordInfo_FWD_DEFINED__
'#define __IRecordInfo_FWD_DEFINED__
'typedef interface IRecordInfo IRecordInfo;
'#endif  ' __IRecordInfo_FWD_DEFINED__
'
'
'#ifndef __IErrorLog_FWD_DEFINED__
'#define __IErrorLog_FWD_DEFINED__
'typedef interface IErrorLog IErrorLog;
'#endif  ' __IErrorLog_FWD_DEFINED__
'
'
'#ifndef __IPropertyBag_FWD_DEFINED__
'#define __IPropertyBag_FWD_DEFINED__
'typedef interface IPropertyBag IPropertyBag;
'#endif  ' __IPropertyBag_FWD_DEFINED__


' header files for imported files
#INCLUDE "objidl.inc"


' interface __MIDL_itf_oaidl_0000_0000




'extern RPC_IF_HANDLE __MIDL_itf_oaidl_0000_0000_v0_0_c_ifspec;
'extern RPC_IF_HANDLE __MIDL_itf_oaidl_0000_0000_v0_0_s_ifspec;

#IF NOT %DEF(%IOleAutomationTypes_INTERFACE_DEFINED)
%IOleAutomationTypes_INTERFACE_DEFINED = 1

' interface IOleAutomationTypes

'typedef CY CURRENCY;

' [legacy support]
UNION SAFEARRAYBOUND_union
    cLbound AS LONG
    lLbound AS LONG
END UNION

TYPE SAFEARRAYBOUND
    cElements AS DWORD
    SAFEARRAYBOUND_union
END TYPE

TYPE SAFEARR_BSTR
    SIZE  AS DWORD
    aBstr AS DWORD  ' wireBSTR PTR
END TYPE

TYPE SAFEARR_UNKNOWN
    SIZE      AS DWORD
    apUnknown AS DWORD  ' IUnknown **
END TYPE

TYPE SAFEARR_DISPATCH
    SIZE       AS DWORD
    apDispatch AS DWORD  ' IDispatch **
END TYPE

' [must define these a bit later, after wireVARIANT and wireBRECORD]
'TYPE SAFEARR_VARIANT
'    SIZE     AS DWORD
'    aVariant AS wireVARIANT PTR
'END TYPE
'
'TYPE SAFEARR_BRECORD
'    SIZE    AS DWORD
'    aRecord AS wireBRECORD PTR
'END TYPE

TYPE SAFEARR_HAVEIID
    SIZE      AS DWORD
    apUnknown AS DWORD     ' IUnknown **
    iid       AS GUID PTR  ' IID
END TYPE

MACRO SF_TYPE_enum=LONG
ENUM SF_TYPE SINGULAR
    SF_ERROR    = %VT_ERROR
    SF_I1       = %VT_I1
    SF_I2       = %VT_I2
    SF_I4       = %VT_I4
    SF_I8       = %VT_I8
    SF_BSTR     = %VT_BSTR
    SF_UNKNOWN  = %VT_UNKNOWN
    SF_DISPATCH = %VT_DISPATCH
    SF_VARIANT  = %VT_VARIANT
    SF_RECORD   = %VT_RECORD
    SF_HAVEIID  = %VT_UNKNOWN OR %VT_RESERVED
END ENUM

'[need to move this down a bit]
'UNION SAFEARRAY_UNION_union
'    BstrStr     AS SAFEARR_BSTR
'    UnknownStr  AS SAFEARR_UNKNOWN
'    DispatchStr AS SAFEARR_DISPATCH
'    VariantStr  AS SAFEARR_VARIANT
'    RecordStr   AS SAFEARR_BRECORD
'    HaveIidStr  AS SAFEARR_HAVEIID
'    ByteStr     AS BYTE_SIZEDARR
'    WordStr     AS WORD_SIZEDARR
'    LongStr     AS DWORD_SIZEDARR
'    HyperStr    AS HYPER_SIZEDARR
'END UNION
'
'TYPE SAFEARRAYUNION
'    sfType AS DWORD
'    u      AS SAFEARRAY_UNION_union
'END TYPE
'
'TYPE wireSAFEARRAY
'    cDims         AS WORD
'    fFeatures     AS WORD
'    cbElements    AS DWORD
'    cLocks        AS DWORD
'    uArrayStructs AS SAFEARRAYUNION
'    rgsabound(0)  AS SAFEARRAYBOUND
'END TYPE

TYPE SAFEARRAY
    cDims        AS WORD
    fFeatures    AS WORD
    cbElements   AS DWORD
    cLocks       AS DWORD
    pvData       AS DWORD  ' PVOID
    rgsabound(0) AS SAFEARRAYBOUND
END TYPE

%FADF_AUTO        = &H1

%FADF_STATIC      = &H2

%FADF_EMBEDDED    = &H4

%FADF_FIXEDSIZE   = &H10

%FADF_RECORD      = &H20

%FADF_HAVEIID     = &H40

%FADF_HAVEVARTYPE = &H80?

%FADF_BSTR        = &H100

%FADF_UNKNOWN     = &H200

%FADF_DISPATCH    = &H400

%FADF_VARIANT     = &H800

%FADF_RESERVED    = &Hf008??

' VARIANT STRUCTURE
'
'  VARTYPE vt;
'  WORD wReserved1;
'  WORD wReserved2;
'  WORD wReserved3;
'  union {
'    QUAD       VT_I8
'    LONG           VT_I4
'    BYTE           VT_UI1
'    integer          VT_I2
'    FLOAT          VT_R4
'    DOUBLE         VT_R8
'    VARIANT_BOOL   VT_BOOL
'    SCODE          VT_ERROR
'    CY             VT_CY
'    DATE           VT_DATE
'    BSTR           VT_BSTR
'    IUnknown *     VT_UNKNOWN
'    IDispatch *    VT_DISPATCH
'    SAFEARRAY *    VT_ARRAY
'    BYTE *         VT_BYREF|VT_UI1
'    integer *        VT_BYREF|VT_I2
'    LONG *         VT_BYREF|VT_I4
'    QUAD *     VT_BYREF|VT_I8
'    FLOAT *        VT_BYREF|VT_R4
'    DOUBLE *       VT_BYREF|VT_R8
'    VARIANT_BOOL * VT_BYREF|VT_BOOL
'    SCODE *        VT_BYREF|VT_ERROR
'    CY *           VT_BYREF|VT_CY
'    DATE *         VT_BYREF|VT_DATE
'    BSTR *         VT_BYREF|VT_BSTR
'    IUnknown **    VT_BYREF|VT_UNKNOWN
'    IDispatch **   VT_BYREF|VT_DISPATCH
'    SAFEARRAY **   VT_BYREF|VT_ARRAY
'    VARIANT *      VT_BYREF|VT_VARIANT
'    PVOID          VT_BYREF (Generic ByRef)
'    CHAR           VT_I1
'    WORD         VT_UI2
'    DWORD          VT_UI4
'    ULONGLONG      VT_UI8
'    LONG            VT_INT
'    DWORD           VT_UINT
'    DECIMAL *      VT_BYREF|VT_DECIMAL
'    CHAR *         VT_BYREF|VT_I1
'    WORD *       VT_BYREF|VT_UI2
'    DWORD *        VT_BYREF|VT_UI4
'    ULONGLONG *    VT_BYREF|VT_UI8
'    LONG *          VT_BYREF|VT_INT
'    DWORD *         VT_BYREF|VT_UINT
'  }
'
'#if (__STDC__ && !defined(_FORCENAMELESSUNION)) || defined(NONAMELESSUNION) || (!defined(_MSC_EXTENSIONS) && !defined(_FORCENAMELESSUNION))
'#define __VARIANT_NAME_1 n1
'#define __VARIANT_NAME_2 n2
'#define __VARIANT_NAME_3 n3
'#define __VARIANT_NAME_4 brecVal
'#else
'#define __tagVARIANT
'#define __VARIANT_NAME_1
'#define __VARIANT_NAME_2
'#define __VARIANT_NAME_3
'#define __tagBRECORD
'#define __VARIANT_NAME_4
'#endif


TYPE VARIANT_NAME_4
    pvRecord AS DWORD  ' PVOID
    pRecInfo AS DWORD  ' IRecordInfo PTR
END TYPE

UNION VARIANT_NAME_3
    llVal     AS QUAD
    lVal      AS LONG
    bVal      AS BYTE
    iVal      AS INTEGER
    fltVal    AS SINGLE
    dblVal    AS DOUBLE
    boolVal   AS VARIANT_BOOL
    bool      AS VARIANT_BOOL
    scode     AS LONG              ' SCODE
    cyVal     AS CURRENCY
    date      AS DOUBLE            ' DATE
    bstrVal   AS DWORD             ' BSTR
    punkVal   AS DWORD             ' IUnknown PTR
    pdispVal  AS DWORD             ' IDispatch PTR
    parray    AS SAFEARRAY PTR
    pbVal     AS BYTE PTR
    piVal     AS INTEGER PTR
    plVal     AS LONG PTR
    pllVal    AS QUAD PTR
    pfltVal   AS SINGLE PTR
    pdblVal   AS DOUBLE PTR
    pboolVal  AS VARIANT_BOOL PTR
    pbool     AS VARIANT_BOOL PTR
    pscode    AS LONG PTR          ' SCODE PTR
    pcyVal    AS CURRENCY PTR
    pdate     AS DOUBLE PTR        ' DATE PTR
    pbstrVal  AS DWORD             ' BSTR PTR
    ppunkVal  AS DWORD             ' IUnknown PTR PTR
    ppdispVal AS DWORD             ' IDispatch PTR PTR
    pparray   AS DWORD             ' SAFEARRAY PTR PTR
    pvarVal   AS DWORD             ' VARIANT_type PTR
    byref     AS DWORD             ' PVOID
    cVal      AS BYTE
    uiVal     AS WORD
    ulVal     AS DWORD
    ullVal    AS QUAD              ' ULONGLONG
    intVal    AS LONG
    uintVal   AS DWORD
    pdecVal   AS DECIMAL PTR
    pcVal     AS BYTE PTR
    puiVal    AS WORD PTR
    pulVal    AS DWORD PTR
    pullVal   AS QUAD PTR          ' ULONGLONG PTR
    pintVal   AS LONG PTR
    puintVal  AS DWORD PTR
    VARIANT_NAME_4
END UNION

TYPE VARIANT_NAME_2
    vt         AS VARTYPE
    wReserved1 AS WORD
    wReserved2 AS WORD
    wReserved3 AS WORD
    VARIANT_NAME_3
END TYPE

UNION VARIANT_NAME_1
    VARIANT_NAME_2
    decVal AS DECIMAL
END UNION

TYPE VARIANT_type
    VARIANT_NAME_1
END TYPE  ' VARIANT_type

' [legacy]
TYPE VARIANTAPI
    VARIANT_type
END TYPE

'typedef VARIANT *LPVARIANT;
'
'typedef VARIANT VARIANTARG;
'
'typedef VARIANT *LPVARIANTARG;
'
'#ifdef MIDL_PASS
'typedef const VARIANT *REFVARIANT;
'
'#else
'
'#ifndef _REFVARIANT_DEFINED
'#define _REFVARIANT_DEFINED
'#ifdef __cplusplus
'#define REFVARIANT const VARIANT &
'#else
'#define REFVARIANT const VARIANT * __MIDL_CONST
'#endif
'#endif
'
'#endif ' MIDL_PASS

' the following is what MIDL knows how to remote

TYPE wireBRECORD
    fFlags   AS DWORD
    clSize   AS DWORD
    pRecInfo AS DWORD  ' IRecordInfo *
    pRecord  AS BYTE PTR
END TYPE

UNION wireVARIANT_union
    llVal     AS QUAD
    lVal      AS LONG
    bVal      AS BYTE
    iVal      AS INTEGER
    fltVal    AS SINGLE
    dblVal    AS DOUBLE
    boolVal   AS VARIANT_BOOL
    scode     AS LONG    ' SCODE
    cyVal     AS CURRENCY
    date      AS DOUBLE  ' DATE
    bstrVal   AS wireBSTR
    punkVal   AS DWORD   ' IUnknown PTR
    pdispVal  AS DWORD   ' IDispatch PTR
    parray    AS DWORD   ' wireSAFEARRAY PTR
    brecVal   AS DWORD   ' wireBRECORD
    pbVal     AS BYTE PTR
    piVal     AS INTEGER PTR
    plVal     AS LONG PTR
    pllVal    AS QUAD PTR
    pfltVal   AS SINGLE PTR
    pdblVal   AS DOUBLE PTR
    pboolVal  AS VARIANT_BOOL PTR
    pscode    AS LONG PTR  ' SCODE PTR
    pcyVal    AS CURRENCY PTR
    pdate     AS DOUBLE PTR  ' DATE PTR
    pbstrVal  AS DWORD  ' wireBSTR PTR
    ppunkVal  AS DWORD  ' IUnknown **
    ppdispVal AS DWORD  ' IDispatch **
    pparray   AS DWORD  ' wireSAFEARRAY PTR PTR
    pvarVal   AS DWORD  ' wireVARIANT PTR
    cVal      AS BYTE
    uiVal     AS WORD
    ulVal     AS DWORD
    ullVal    AS QUAD  ' ULONGLONG
    intVal    AS LONG
    uintVal   AS DWORD
    decVal    AS DECIMAL
    pdecVal   AS DECIMAL PTR
    pcVal     AS BYTE PTR
    puiVal    AS WORD PTR
    pulVal    AS DWORD PTR
    pullVal   AS QUAD PTR  ' ULONGLONG PTR
    pintVal   AS LONG PTR
    puintVal  AS DWORD PTR
END UNION  ' wireVARIANT_union

TYPE wireVARIANT
    clSize      AS DWORD
    rpcReserved AS DWORD
    vt          AS WORD
    wReserved1  AS WORD
    wReserved2  AS WORD
    wReserved3  AS WORD
    wireVARIANT_union
END TYPE

' [defined earlier in the original .h file, but we need them down here]
TYPE SAFEARR_BRECORD
    SIZE    AS DWORD
    aRecord AS wireBRECORD PTR
END TYPE

TYPE SAFEARR_VARIANT
    SIZE     AS DWORD
    aVariant AS wireVARIANT PTR
END TYPE

UNION SAFEARRAY_UNION_union
    BstrStr     AS SAFEARR_BSTR
    UnknownStr  AS SAFEARR_UNKNOWN
    DispatchStr AS SAFEARR_DISPATCH
    VariantStr  AS SAFEARR_VARIANT
    RecordStr   AS SAFEARR_BRECORD
    HaveIidStr  AS SAFEARR_HAVEIID
    ByteStr     AS BYTE_SIZEDARR
    WordStr     AS WORD_SIZEDARR
    LongStr     AS DWORD_SIZEDARR
    HyperStr    AS HYPER_SIZEDARR
END UNION

TYPE SAFEARRAYUNION
    sfType AS DWORD
    u      AS SAFEARRAY_UNION_union
END TYPE

TYPE wireSAFEARRAY
    cDims         AS WORD
    fFeatures     AS WORD
    cbElements    AS DWORD
    cLocks        AS DWORD
    uArrayStructs AS SAFEARRAYUNION
    rgsabound(0)  AS SAFEARRAYBOUND
END TYPE

'macro DISPID=LONG
'
'macro MEMBERID=DISPID
'
'macro HREFTYPE=DWORD

MACRO TYPEKIND_enum=LONG
ENUM TYPEKIND SINGULAR
    TKIND_ENUM
    TKIND_RECORD
    TKIND_MODULE
    TKIND_INTERFACE
    TKIND_DISPATCH
    TKIND_COCLASS
    TKIND_ALIAS
    TKIND_UNION
    TKIND_MAX
END ENUM

UNION TYPEDESC_union
    lptdesc  AS DWORD  ' TYPEDESC PTR
    lpadesc  AS DWORD  ' ARRAYDESC PTR
    hreftype AS DWORD  ' HREFTYPE
END UNION

TYPE TYPEDESC
    TYPEDESC_union
    vt AS VARTYPE
END TYPE

TYPE ARRAYDESC
    tdescElem   AS TYPEDESC
    cDims       AS WORD
    rgbounds(0) AS SAFEARRAYBOUND
END TYPE

TYPE PARAMDESCEX
    cBytes          AS DWORD
    varDefaultValue AS VARIANT_type
END TYPE

TYPE PARAMDESC_type
    pparamdescex AS PARAMDESCEX PTR
    wParamFlags  AS WORD
END TYPE

%PARAMFLAG_NONE          = 0

%PARAMFLAG_FIN           = &H1

%PARAMFLAG_FOUT          = &H2

%PARAMFLAG_FLCID         = &H4

%PARAMFLAG_FRETVAL       = &H8

%PARAMFLAG_FOPT          = &H10

%PARAMFLAG_FHASDEFAULT   = &H20

%PARAMFLAG_FHASCUSTDATA  = &H40

TYPE IDLDESC_type
    dwReserved AS DWORD  ' ULONG_PTR
    wIDLFlags  AS WORD
END TYPE

%IDLFLAG_NONE    = %PARAMFLAG_NONE

%IDLFLAG_FIN     = %PARAMFLAG_FIN

%IDLFLAG_FOUT    = %PARAMFLAG_FOUT

%IDLFLAG_FLCID   = %PARAMFLAG_FLCID

%IDLFLAG_FRETVAL = %PARAMFLAG_FRETVAL

';begin_internal
#IF 0
' the following is what MIDL knows how to remote
TYPE ELEMDESC
    tdesc     AS TYPEDESC
    paramdesc AS PARAMDESC_type
END TYPE

#ELSE
';end_internal
UNION ELEMDESC_union
    idldesc   AS IDLDESC_type   ' info for remoting the element
    paramdesc AS PARAMDESC_type ' info about the parameter
END UNION

TYPE ELEMDESC
    tdesc AS TYPEDESC              ' the type of the element
    ELEMDESC_union
END TYPE
';begin_internal
#ENDIF ' 0
';end_internal
TYPE TYPEATTR
    GUID             AS GUID
    lcid             AS DWORD  ' LCID
    dwReserved       AS DWORD
    memidConstructor AS LONG   ' MEMBERID
    memidDestructor  AS LONG   ' MEMBERID
    lpstrSchema      AS WSTRINGZ PTR
    cbSizeInstance   AS DWORD
    typekind         AS TYPEKIND_enum
    cFuncs           AS WORD
    cVars            AS WORD
    cImplTypes       AS WORD
    cbSizeVft        AS WORD
    cbAlignment      AS WORD
    wTypeFlags       AS WORD
    wMajorVerNum     AS WORD
    wMinorVerNum     AS WORD
    tdescAlias       AS TYPEDESC
    idldescType      AS IDLDESC_type
END TYPE


TYPE DISPPARAMS_type
    rgvarg            AS VARIANT_type PTR
    rgdispidNamedArgs AS LONG PTR  ' DISPID ptr
    cArgs             AS DWORD
    cNamedArgs        AS DWORD
END TYPE

';begin_internal
#IF 0
' the following is what MIDL knows how to remote

TYPE EXCEPINFO
    wCode             AS WORD
    wReserved         AS WORD
    bstrSource        AS WSTRING
    bstrDescription   AS WSTRING
    bstrHelpFile      AS WSTRING
    dwHelpContext     AS DWORD
    pvReserved        AS DWORD  ' ULONG_PTR
    pfnDeferredFillIn AS DWORD  ' ULONG_PTR
    scode             AS LONG   ' SCODE
END TYPE

#ELSE
';end_internal
TYPE EXCEPINFO
    wCode             AS WORD
    wReserved         AS WORD
    bstrSource        AS WSTRING PTR
    bstrDescription   AS WSTRING PTR
    bstrHelpFile      AS WSTRING PTR
    dwHelpContext     AS DWORD
    pvReserved        AS DWORD  ' PVOID
    pfnDeferredFillIn AS DWORD  ' pfnDeferredFillIn(BYREF EXCEPINFO) as HRESULT (
    scode             AS LONG   ' SCODE
END TYPE
';begin_internal
#ENDIF ' 0
';end_internal

MACRO CALLCONV_enum=LONG
ENUM CALLCONV SINGULAR
    CC_FASTCALL
    CC_CDECL
    CC_MSCPASCAL
    CC_PASCAL   = %CC_MSCPASCAL
    CC_MACPASCAL
    CC_STDCALL
    CC_FPFASTCALL
    CC_SYSCALL
    CC_MPWCDECL
    CC_MPWPASCAL
    CC_MAX
END ENUM

MACRO FUNCKIND_enum=LONG
ENUM FUNCKIND SINGULAR
    FUNC_VIRTUAL
    FUNC_PUREVIRTUAL
    FUNC_NONVIRTUAL
    FUNC_STATIC
    FUNC_DISPATCH
END ENUM

MACRO INVOKEKIND_enum=LONG
ENUM INVOKEKIND SINGULAR BITS
    INVOKE_FUNC           = 1
    INVOKE_PROPERTYGET
    INVOKE_PROPERTYPUT
    INVOKE_PROPERTYPUTREF
END ENUM

TYPE FUNCDESC
    memid             AS LONG      ' MEMBERID
    lprgscode         AS LONG PTR  ' SCODE ptr
    lprgelemdescParam AS ELEMDESC PTR
    funckind          AS FUNCKIND_enum
    invkind           AS INVOKEKIND_enum
    callconv          AS CALLCONV_enum
    cParams           AS INTEGER
    cParamsOpt        AS INTEGER
    oVft              AS INTEGER
    cScodes           AS INTEGER
    elemdescFunc      AS ELEMDESC
    wFuncFlags        AS WORD
END TYPE

MACRO VARKIND_enum=LONG
ENUM VARKIND SINGULAR
    VAR_PERINSTANCE
    VAR_STATIC
    VAR_CONST
    VAR_DISPATCH
END ENUM

%IMPLTYPEFLAG_FDEFAULT       = &H1

%IMPLTYPEFLAG_FSOURCE        = &H2

%IMPLTYPEFLAG_FRESTRICTED    = &H4

%IMPLTYPEFLAG_FDEFAULTVTABLE = &H8

UNION VARDESC_union
    oInst      AS DWORD
    lpvarValue AS VARIANT_type PTR
END UNION

TYPE VARDESC
    memid       AS LONG    ' MEMBERID
    lpstrSchema AS WSTRINGZ PTR
    VARDESC_union
    elemdescVar AS ELEMDESC
    wVarFlags   AS WORD
    varkind     AS VARKIND_enum
END TYPE


MACRO TYPEFLAGS_enum=LONG
ENUM TYPEFLAGS SINGULAR BITS
    TYPEFLAG_FAPPOBJECT = 1
    TYPEFLAG_FCANCREATE
    TYPEFLAG_FLICENSED
    TYPEFLAG_FPREDECLID
    TYPEFLAG_FHIDDEN
    TYPEFLAG_FCONTROL
    TYPEFLAG_FDUAL
    TYPEFLAG_FNONEXTENSIBLE
    TYPEFLAG_FOLEAUTOMATION
    TYPEFLAG_FRESTRICTED
    TYPEFLAG_FAGGREGATABLE
    TYPEFLAG_FREPLACEABLE
    TYPEFLAG_FDISPATCHABLE
    TYPEFLAG_FREVERSEBIND
    TYPEFLAG_FPROXY
END ENUM

MACRO FUNCFLAGS_enum=LONG
ENUM FUNCFLAGS SINGULAR BITS
    FUNCFLAG_FRESTRICTED = 1
    FUNCFLAG_FSOURCE
    FUNCFLAG_FBINDABLE
    FUNCFLAG_FREQUESTEDIT
    FUNCFLAG_FDISPLAYBIND
    FUNCFLAG_FDEFAULTBIND
    FUNCFLAG_FHIDDEN
    FUNCFLAG_FUSESGETLASTERROR
    FUNCFLAG_FDEFAULTCOLLELEM
    FUNCFLAG_FUIDEFAULT
    FUNCFLAG_FNONBROWSABLE
    FUNCFLAG_FREPLACEABLE
    FUNCFLAG_FIMMEDIATEBIND
END ENUM

MACRO VARFLAGS_enum=LONG
ENUM VARFLAGS SINGULAR BITS
    VARFLAG_FREADONLY = 1
    VARFLAG_FSOURCE
    VARFLAG_FBINDABLE
    VARFLAG_FREQUESTEDIT
    VARFLAG_FDISPLAYBIND
    VARFLAG_FDEFAULTBIND
    VARFLAG_FHIDDEN
    VARFLAG_FRESTRICTED
    VARFLAG_FDEFAULTCOLLELEM
    VARFLAG_FUIDEFAULT
    VARFLAG_FNONBROWSABLE
    VARFLAG_FREPLACEABLE
    VARFLAG_FIMMEDIATEBIND
END ENUM

TYPE CLEANLOCALSTORAGE
    pInterface AS DWORD  ' IUnknown *
    pStorage   AS DWORD  ' PVOID
    flags      AS DWORD
END TYPE

TYPE CUSTDATAITEM
    gguid    AS GUID
    varValue AS VARIANT_type
END TYPE

TYPE CUSTDATA
    cCustData   AS DWORD
    prgCustData AS CUSTDATAITEM PTR
END TYPE



'extern RPC_IF_HANDLE IOleAutomationTypes_v1_0_c_ifspec;
'extern RPC_IF_HANDLE IOleAutomationTypes_v1_0_s_ifspec;
#ENDIF ' %IOleAutomationTypes_INTERFACE_DEFINED

'#ifndef __ICreateTypeInfo_INTERFACE_DEFINED__
'#define __ICreateTypeInfo_INTERFACE_DEFINED__
'
'' interface ICreateTypeInfo
'
'
'EXTERN_C const IID IID_ICreateTypeInfo;
'
'#if defined(__cplusplus) && !defined(CINTERFACE)
'
'    MIDL_INTERFACE("00020405-0000-0000-C000-000000000046")
'    ICreateTypeInfo : public IUnknown
'    {
'    public:
'        virtual HRESULT STDMETHODCALLTYPE SetGuid(
'            REFGUID guid) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetTypeFlags(
'            DWORD uTypeFlags) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetDocString(
'            LPOLESTR pStrDoc) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetHelpContext(
'            DWORD dwHelpContext) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetVersion(
'            WORD wMajorVerNum,
'            WORD wMinorVerNum) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE AddRefTypeInfo(
'            ITypeInfo *pTInfo,
'            HREFTYPE *phRefType) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE AddFuncDesc(
'            DWORD index,
'            FUNCDESC *pFuncDesc) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE AddImplType(
'            DWORD index,
'            HREFTYPE hRefType) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetImplTypeFlags(
'            DWORD index,
'            LONG implTypeFlags) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetAlignment(
'            WORD cbAlignment) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetSchema(
'            LPOLESTR pStrSchema) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE AddVarDesc(
'            DWORD index,
'            VARDESC *pVarDesc) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetFuncAndParamNames(
'            DWORD index,
'            LPOLESTR *rgszNames,
'            DWORD cNames) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetVarName(
'            DWORD index,
'            LPOLESTR szName) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetTypeDescAlias(
'            TYPEDESC *pTDescAlias) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE DefineFuncAsDllEntry(
'            DWORD index,
'            LPOLESTR szDllName,
'            LPOLESTR szProcName) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetFuncDocString(
'            DWORD index,
'            LPOLESTR szDocString) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetVarDocString(
'            DWORD index,
'            LPOLESTR szDocString) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetFuncHelpContext(
'            DWORD index,
'            DWORD dwHelpContext) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetVarHelpContext(
'            DWORD index,
'            DWORD dwHelpContext) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetMops(
'            DWORD index,
'            BSTR bstrMops) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetTypeIdldesc(
'            IDLDESC_type *pIdlDesc) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE LayOut( void) = 0;
'
'    };
'
'#else   ' C style interface
'
'    typedef struct ICreateTypeInfoVtbl
'    {
'        BEGIN_INTERFACE
'
'        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
'            ICreateTypeInfo * This,
'            REFIID riid,
'            void **ppvObject);
'
'        DWORD ( STDMETHODCALLTYPE *AddRef )(
'            ICreateTypeInfo * This);
'
'        DWORD ( STDMETHODCALLTYPE *Release )(
'            ICreateTypeInfo * This);
'
'        HRESULT ( STDMETHODCALLTYPE *SetGuid )(
'            ICreateTypeInfo * This,
'            REFGUID guid);
'
'        HRESULT ( STDMETHODCALLTYPE *SetTypeFlags )(
'            ICreateTypeInfo * This,
'            DWORD uTypeFlags);
'
'        HRESULT ( STDMETHODCALLTYPE *SetDocString )(
'            ICreateTypeInfo * This,
'            LPOLESTR pStrDoc);
'
'        HRESULT ( STDMETHODCALLTYPE *SetHelpContext )(
'            ICreateTypeInfo * This,
'            DWORD dwHelpContext);
'
'        HRESULT ( STDMETHODCALLTYPE *SetVersion )(
'            ICreateTypeInfo * This,
'            WORD wMajorVerNum,
'            WORD wMinorVerNum);
'
'        HRESULT ( STDMETHODCALLTYPE *AddRefTypeInfo )(
'            ICreateTypeInfo * This,
'            ITypeInfo *pTInfo,
'            HREFTYPE *phRefType);
'
'        HRESULT ( STDMETHODCALLTYPE *AddFuncDesc )(
'            ICreateTypeInfo * This,
'            DWORD index,
'            FUNCDESC *pFuncDesc);
'
'        HRESULT ( STDMETHODCALLTYPE *AddImplType )(
'            ICreateTypeInfo * This,
'            DWORD index,
'            HREFTYPE hRefType);
'
'        HRESULT ( STDMETHODCALLTYPE *SetImplTypeFlags )(
'            ICreateTypeInfo * This,
'            DWORD index,
'            LONG implTypeFlags);
'
'        HRESULT ( STDMETHODCALLTYPE *SetAlignment )(
'            ICreateTypeInfo * This,
'            WORD cbAlignment);
'
'        HRESULT ( STDMETHODCALLTYPE *SetSchema )(
'            ICreateTypeInfo * This,
'            LPOLESTR pStrSchema);
'
'        HRESULT ( STDMETHODCALLTYPE *AddVarDesc )(
'            ICreateTypeInfo * This,
'            DWORD index,
'            VARDESC *pVarDesc);
'
'        HRESULT ( STDMETHODCALLTYPE *SetFuncAndParamNames )(
'            ICreateTypeInfo * This,
'            DWORD index,
'            LPOLESTR *rgszNames,
'            DWORD cNames);
'
'        HRESULT ( STDMETHODCALLTYPE *SetVarName )(
'            ICreateTypeInfo * This,
'            DWORD index,
'            LPOLESTR szName);
'
'        HRESULT ( STDMETHODCALLTYPE *SetTypeDescAlias )(
'            ICreateTypeInfo * This,
'            TYPEDESC *pTDescAlias);
'
'        HRESULT ( STDMETHODCALLTYPE *DefineFuncAsDllEntry )(
'            ICreateTypeInfo * This,
'            DWORD index,
'            LPOLESTR szDllName,
'            LPOLESTR szProcName);
'
'        HRESULT ( STDMETHODCALLTYPE *SetFuncDocString )(
'            ICreateTypeInfo * This,
'            DWORD index,
'            LPOLESTR szDocString);
'
'        HRESULT ( STDMETHODCALLTYPE *SetVarDocString )(
'            ICreateTypeInfo * This,
'            DWORD index,
'            LPOLESTR szDocString);
'
'        HRESULT ( STDMETHODCALLTYPE *SetFuncHelpContext )(
'            ICreateTypeInfo * This,
'            DWORD index,
'            DWORD dwHelpContext);
'
'        HRESULT ( STDMETHODCALLTYPE *SetVarHelpContext )(
'            ICreateTypeInfo * This,
'            DWORD index,
'            DWORD dwHelpContext);
'
'        HRESULT ( STDMETHODCALLTYPE *SetMops )(
'            ICreateTypeInfo * This,
'            DWORD index,
'            BSTR bstrMops);
'
'        HRESULT ( STDMETHODCALLTYPE *SetTypeIdldesc )(
'            ICreateTypeInfo * This,
'            IDLDESC_type *pIdlDesc);
'
'        HRESULT ( STDMETHODCALLTYPE *LayOut )(
'            ICreateTypeInfo * This);
'
'        END_INTERFACE
'    } ICreateTypeInfoVtbl;
'
'    interface ICreateTypeInfo
'    {
'        CONST_VTBL struct ICreateTypeInfoVtbl *lpVtbl;
'    };
'
'
'
'#ifdef COBJMACROS
'
'
'#define ICreateTypeInfo_QueryInterface(This,riid,ppvObject) \
'    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
'
'#define ICreateTypeInfo_AddRef(This)    \
'    ( (This)->lpVtbl -> AddRef(This) )
'
'#define ICreateTypeInfo_Release(This)   \
'    ( (This)->lpVtbl -> Release(This) )
'
'
'#define ICreateTypeInfo_SetGuid(This,guid)  \
'    ( (This)->lpVtbl -> SetGuid(This,guid) )
'
'#define ICreateTypeInfo_SetTypeFlags(This,uTypeFlags)   \
'    ( (This)->lpVtbl -> SetTypeFlags(This,uTypeFlags) )
'
'#define ICreateTypeInfo_SetDocString(This,pStrDoc)  \
'    ( (This)->lpVtbl -> SetDocString(This,pStrDoc) )
'
'#define ICreateTypeInfo_SetHelpContext(This,dwHelpContext)  \
'    ( (This)->lpVtbl -> SetHelpContext(This,dwHelpContext) )
'
'#define ICreateTypeInfo_SetVersion(This,wMajorVerNum,wMinorVerNum)  \
'    ( (This)->lpVtbl -> SetVersion(This,wMajorVerNum,wMinorVerNum) )
'
'#define ICreateTypeInfo_AddRefTypeInfo(This,pTInfo,phRefType)   \
'    ( (This)->lpVtbl -> AddRefTypeInfo(This,pTInfo,phRefType) )
'
'#define ICreateTypeInfo_AddFuncDesc(This,index,pFuncDesc)   \
'    ( (This)->lpVtbl -> AddFuncDesc(This,index,pFuncDesc) )
'
'#define ICreateTypeInfo_AddImplType(This,index,hRefType)    \
'    ( (This)->lpVtbl -> AddImplType(This,index,hRefType) )
'
'#define ICreateTypeInfo_SetImplTypeFlags(This,index,implTypeFlags)  \
'    ( (This)->lpVtbl -> SetImplTypeFlags(This,index,implTypeFlags) )
'
'#define ICreateTypeInfo_SetAlignment(This,cbAlignment)  \
'    ( (This)->lpVtbl -> SetAlignment(This,cbAlignment) )
'
'#define ICreateTypeInfo_SetSchema(This,pStrSchema)  \
'    ( (This)->lpVtbl -> SetSchema(This,pStrSchema) )
'
'#define ICreateTypeInfo_AddVarDesc(This,index,pVarDesc) \
'    ( (This)->lpVtbl -> AddVarDesc(This,index,pVarDesc) )
'
'#define ICreateTypeInfo_SetFuncAndParamNames(This,index,rgszNames,cNames)   \
'    ( (This)->lpVtbl -> SetFuncAndParamNames(This,index,rgszNames,cNames) )
'
'#define ICreateTypeInfo_SetVarName(This,index,szName)   \
'    ( (This)->lpVtbl -> SetVarName(This,index,szName) )
'
'#define ICreateTypeInfo_SetTypeDescAlias(This,pTDescAlias)  \
'    ( (This)->lpVtbl -> SetTypeDescAlias(This,pTDescAlias) )
'
'#define ICreateTypeInfo_DefineFuncAsDllEntry(This,index,szDllName,szProcName)   \
'    ( (This)->lpVtbl -> DefineFuncAsDllEntry(This,index,szDllName,szProcName) )
'
'#define ICreateTypeInfo_SetFuncDocString(This,index,szDocString)    \
'    ( (This)->lpVtbl -> SetFuncDocString(This,index,szDocString) )
'
'#define ICreateTypeInfo_SetVarDocString(This,index,szDocString) \
'    ( (This)->lpVtbl -> SetVarDocString(This,index,szDocString) )
'
'#define ICreateTypeInfo_SetFuncHelpContext(This,index,dwHelpContext)    \
'    ( (This)->lpVtbl -> SetFuncHelpContext(This,index,dwHelpContext) )
'
'#define ICreateTypeInfo_SetVarHelpContext(This,index,dwHelpContext) \
'    ( (This)->lpVtbl -> SetVarHelpContext(This,index,dwHelpContext) )
'
'#define ICreateTypeInfo_SetMops(This,index,bstrMops)    \
'    ( (This)->lpVtbl -> SetMops(This,index,bstrMops) )
'
'#define ICreateTypeInfo_SetTypeIdldesc(This,pIdlDesc)   \
'    ( (This)->lpVtbl -> SetTypeIdldesc(This,pIdlDesc) )
'
'#define ICreateTypeInfo_LayOut(This)    \
'    ( (This)->lpVtbl -> LayOut(This) )
'
'#endif ' COBJMACROS
'
'
'#endif  ' C style interface
'
'
'
'
'#endif  ' __ICreateTypeInfo_INTERFACE_DEFINED__
'
'
'#ifndef __ICreateTypeInfo2_INTERFACE_DEFINED__
'#define __ICreateTypeInfo2_INTERFACE_DEFINED__
'
'' interface ICreateTypeInfo2
'
'
'EXTERN_C const IID IID_ICreateTypeInfo2;
'
'#if defined(__cplusplus) && !defined(CINTERFACE)
'
'    MIDL_INTERFACE("0002040E-0000-0000-C000-000000000046")
'    ICreateTypeInfo2 : public ICreateTypeInfo
'    {
'    public:
'        virtual HRESULT STDMETHODCALLTYPE DeleteFuncDesc(
'            DWORD index) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE DeleteFuncDescByMemId(
'            MEMBERID memid,
'            INVOKEKIND invKind) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE DeleteVarDesc(
'            DWORD index) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE DeleteVarDescByMemId(
'            MEMBERID memid) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE DeleteImplType(
'            DWORD index) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetCustData(
'            REFGUID guid,
'            VARIANT *pVarVal) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetFuncCustData(
'            DWORD index,
'            REFGUID guid,
'            VARIANT *pVarVal) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetParamCustData(
'            DWORD indexFunc,
'            DWORD indexParam,
'            REFGUID guid,
'            VARIANT *pVarVal) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetVarCustData(
'            DWORD index,
'            REFGUID guid,
'            VARIANT *pVarVal) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetImplTypeCustData(
'            DWORD index,
'            REFGUID guid,
'            VARIANT *pVarVal) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetHelpStringContext(
'            DWORD dwHelpStringContext) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetFuncHelpStringContext(
'            DWORD index,
'            DWORD dwHelpStringContext) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetVarHelpStringContext(
'            DWORD index,
'            DWORD dwHelpStringContext) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE Invalidate( void) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetName(
'            LPOLESTR szName) = 0;
'
'    };
'
'#else   ' C style interface
'
'    typedef struct ICreateTypeInfo2Vtbl
'    {
'        BEGIN_INTERFACE
'
'        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
'            ICreateTypeInfo2 * This,
'            REFIID riid,
'            void **ppvObject);
'
'        DWORD ( STDMETHODCALLTYPE *AddRef )(
'            ICreateTypeInfo2 * This);
'
'        DWORD ( STDMETHODCALLTYPE *Release )(
'            ICreateTypeInfo2 * This);
'
'        HRESULT ( STDMETHODCALLTYPE *SetGuid )(
'            ICreateTypeInfo2 * This,
'            REFGUID guid);
'
'        HRESULT ( STDMETHODCALLTYPE *SetTypeFlags )(
'            ICreateTypeInfo2 * This,
'            DWORD uTypeFlags);
'
'        HRESULT ( STDMETHODCALLTYPE *SetDocString )(
'            ICreateTypeInfo2 * This,
'            LPOLESTR pStrDoc);
'
'        HRESULT ( STDMETHODCALLTYPE *SetHelpContext )(
'            ICreateTypeInfo2 * This,
'            DWORD dwHelpContext);
'
'        HRESULT ( STDMETHODCALLTYPE *SetVersion )(
'            ICreateTypeInfo2 * This,
'            WORD wMajorVerNum,
'            WORD wMinorVerNum);
'
'        HRESULT ( STDMETHODCALLTYPE *AddRefTypeInfo )(
'            ICreateTypeInfo2 * This,
'            ITypeInfo *pTInfo,
'            HREFTYPE *phRefType);
'
'        HRESULT ( STDMETHODCALLTYPE *AddFuncDesc )(
'            ICreateTypeInfo2 * This,
'            DWORD index,
'            FUNCDESC *pFuncDesc);
'
'        HRESULT ( STDMETHODCALLTYPE *AddImplType )(
'            ICreateTypeInfo2 * This,
'            DWORD index,
'            HREFTYPE hRefType);
'
'        HRESULT ( STDMETHODCALLTYPE *SetImplTypeFlags )(
'            ICreateTypeInfo2 * This,
'            DWORD index,
'            LONG implTypeFlags);
'
'        HRESULT ( STDMETHODCALLTYPE *SetAlignment )(
'            ICreateTypeInfo2 * This,
'            WORD cbAlignment);
'
'        HRESULT ( STDMETHODCALLTYPE *SetSchema )(
'            ICreateTypeInfo2 * This,
'            LPOLESTR pStrSchema);
'
'        HRESULT ( STDMETHODCALLTYPE *AddVarDesc )(
'            ICreateTypeInfo2 * This,
'            DWORD index,
'            VARDESC *pVarDesc);
'
'        HRESULT ( STDMETHODCALLTYPE *SetFuncAndParamNames )(
'            ICreateTypeInfo2 * This,
'            DWORD index,
'            LPOLESTR *rgszNames,
'            DWORD cNames);
'
'        HRESULT ( STDMETHODCALLTYPE *SetVarName )(
'            ICreateTypeInfo2 * This,
'            DWORD index,
'            LPOLESTR szName);
'
'        HRESULT ( STDMETHODCALLTYPE *SetTypeDescAlias )(
'            ICreateTypeInfo2 * This,
'            TYPEDESC *pTDescAlias);
'
'        HRESULT ( STDMETHODCALLTYPE *DefineFuncAsDllEntry )(
'            ICreateTypeInfo2 * This,
'            DWORD index,
'            LPOLESTR szDllName,
'            LPOLESTR szProcName);
'
'        HRESULT ( STDMETHODCALLTYPE *SetFuncDocString )(
'            ICreateTypeInfo2 * This,
'            DWORD index,
'            LPOLESTR szDocString);
'
'        HRESULT ( STDMETHODCALLTYPE *SetVarDocString )(
'            ICreateTypeInfo2 * This,
'            DWORD index,
'            LPOLESTR szDocString);
'
'        HRESULT ( STDMETHODCALLTYPE *SetFuncHelpContext )(
'            ICreateTypeInfo2 * This,
'            DWORD index,
'            DWORD dwHelpContext);
'
'        HRESULT ( STDMETHODCALLTYPE *SetVarHelpContext )(
'            ICreateTypeInfo2 * This,
'            DWORD index,
'            DWORD dwHelpContext);
'
'        HRESULT ( STDMETHODCALLTYPE *SetMops )(
'            ICreateTypeInfo2 * This,
'            DWORD index,
'            BSTR bstrMops);
'
'        HRESULT ( STDMETHODCALLTYPE *SetTypeIdldesc )(
'            ICreateTypeInfo2 * This,
'            IDLDESC_type *pIdlDesc);
'
'        HRESULT ( STDMETHODCALLTYPE *LayOut )(
'            ICreateTypeInfo2 * This);
'
'        HRESULT ( STDMETHODCALLTYPE *DeleteFuncDesc )(
'            ICreateTypeInfo2 * This,
'            DWORD index);
'
'        HRESULT ( STDMETHODCALLTYPE *DeleteFuncDescByMemId )(
'            ICreateTypeInfo2 * This,
'            MEMBERID memid,
'            INVOKEKIND invKind);
'
'        HRESULT ( STDMETHODCALLTYPE *DeleteVarDesc )(
'            ICreateTypeInfo2 * This,
'            DWORD index);
'
'        HRESULT ( STDMETHODCALLTYPE *DeleteVarDescByMemId )(
'            ICreateTypeInfo2 * This,
'            MEMBERID memid);
'
'        HRESULT ( STDMETHODCALLTYPE *DeleteImplType )(
'            ICreateTypeInfo2 * This,
'            DWORD index);
'
'        HRESULT ( STDMETHODCALLTYPE *SetCustData )(
'            ICreateTypeInfo2 * This,
'            REFGUID guid,
'            VARIANT *pVarVal);
'
'        HRESULT ( STDMETHODCALLTYPE *SetFuncCustData )(
'            ICreateTypeInfo2 * This,
'            DWORD index,
'            REFGUID guid,
'            VARIANT *pVarVal);
'
'        HRESULT ( STDMETHODCALLTYPE *SetParamCustData )(
'            ICreateTypeInfo2 * This,
'            DWORD indexFunc,
'            DWORD indexParam,
'            REFGUID guid,
'            VARIANT *pVarVal);
'
'        HRESULT ( STDMETHODCALLTYPE *SetVarCustData )(
'            ICreateTypeInfo2 * This,
'            DWORD index,
'            REFGUID guid,
'            VARIANT *pVarVal);
'
'        HRESULT ( STDMETHODCALLTYPE *SetImplTypeCustData )(
'            ICreateTypeInfo2 * This,
'            DWORD index,
'            REFGUID guid,
'            VARIANT *pVarVal);
'
'        HRESULT ( STDMETHODCALLTYPE *SetHelpStringContext )(
'            ICreateTypeInfo2 * This,
'            DWORD dwHelpStringContext);
'
'        HRESULT ( STDMETHODCALLTYPE *SetFuncHelpStringContext )(
'            ICreateTypeInfo2 * This,
'            DWORD index,
'            DWORD dwHelpStringContext);
'
'        HRESULT ( STDMETHODCALLTYPE *SetVarHelpStringContext )(
'            ICreateTypeInfo2 * This,
'            DWORD index,
'            DWORD dwHelpStringContext);
'
'        HRESULT ( STDMETHODCALLTYPE *Invalidate )(
'            ICreateTypeInfo2 * This);
'
'        HRESULT ( STDMETHODCALLTYPE *SetName )(
'            ICreateTypeInfo2 * This,
'            LPOLESTR szName);
'
'        END_INTERFACE
'    } ICreateTypeInfo2Vtbl;
'
'    interface ICreateTypeInfo2
'    {
'        CONST_VTBL struct ICreateTypeInfo2Vtbl *lpVtbl;
'    };
'
'
'
'#ifdef COBJMACROS
'
'
'#define ICreateTypeInfo2_QueryInterface(This,riid,ppvObject)    \
'    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
'
'#define ICreateTypeInfo2_AddRef(This)   \
'    ( (This)->lpVtbl -> AddRef(This) )
'
'#define ICreateTypeInfo2_Release(This)  \
'    ( (This)->lpVtbl -> Release(This) )
'
'
'#define ICreateTypeInfo2_SetGuid(This,guid) \
'    ( (This)->lpVtbl -> SetGuid(This,guid) )
'
'#define ICreateTypeInfo2_SetTypeFlags(This,uTypeFlags)  \
'    ( (This)->lpVtbl -> SetTypeFlags(This,uTypeFlags) )
'
'#define ICreateTypeInfo2_SetDocString(This,pStrDoc) \
'    ( (This)->lpVtbl -> SetDocString(This,pStrDoc) )
'
'#define ICreateTypeInfo2_SetHelpContext(This,dwHelpContext) \
'    ( (This)->lpVtbl -> SetHelpContext(This,dwHelpContext) )
'
'#define ICreateTypeInfo2_SetVersion(This,wMajorVerNum,wMinorVerNum) \
'    ( (This)->lpVtbl -> SetVersion(This,wMajorVerNum,wMinorVerNum) )
'
'#define ICreateTypeInfo2_AddRefTypeInfo(This,pTInfo,phRefType)  \
'    ( (This)->lpVtbl -> AddRefTypeInfo(This,pTInfo,phRefType) )
'
'#define ICreateTypeInfo2_AddFuncDesc(This,index,pFuncDesc)  \
'    ( (This)->lpVtbl -> AddFuncDesc(This,index,pFuncDesc) )
'
'#define ICreateTypeInfo2_AddImplType(This,index,hRefType)   \
'    ( (This)->lpVtbl -> AddImplType(This,index,hRefType) )
'
'#define ICreateTypeInfo2_SetImplTypeFlags(This,index,implTypeFlags) \
'    ( (This)->lpVtbl -> SetImplTypeFlags(This,index,implTypeFlags) )
'
'#define ICreateTypeInfo2_SetAlignment(This,cbAlignment) \
'    ( (This)->lpVtbl -> SetAlignment(This,cbAlignment) )
'
'#define ICreateTypeInfo2_SetSchema(This,pStrSchema) \
'    ( (This)->lpVtbl -> SetSchema(This,pStrSchema) )
'
'#define ICreateTypeInfo2_AddVarDesc(This,index,pVarDesc)    \
'    ( (This)->lpVtbl -> AddVarDesc(This,index,pVarDesc) )
'
'#define ICreateTypeInfo2_SetFuncAndParamNames(This,index,rgszNames,cNames)  \
'    ( (This)->lpVtbl -> SetFuncAndParamNames(This,index,rgszNames,cNames) )
'
'#define ICreateTypeInfo2_SetVarName(This,index,szName)  \
'    ( (This)->lpVtbl -> SetVarName(This,index,szName) )
'
'#define ICreateTypeInfo2_SetTypeDescAlias(This,pTDescAlias) \
'    ( (This)->lpVtbl -> SetTypeDescAlias(This,pTDescAlias) )
'
'#define ICreateTypeInfo2_DefineFuncAsDllEntry(This,index,szDllName,szProcName)  \
'    ( (This)->lpVtbl -> DefineFuncAsDllEntry(This,index,szDllName,szProcName) )
'
'#define ICreateTypeInfo2_SetFuncDocString(This,index,szDocString)   \
'    ( (This)->lpVtbl -> SetFuncDocString(This,index,szDocString) )
'
'#define ICreateTypeInfo2_SetVarDocString(This,index,szDocString)    \
'    ( (This)->lpVtbl -> SetVarDocString(This,index,szDocString) )
'
'#define ICreateTypeInfo2_SetFuncHelpContext(This,index,dwHelpContext)   \
'    ( (This)->lpVtbl -> SetFuncHelpContext(This,index,dwHelpContext) )
'
'#define ICreateTypeInfo2_SetVarHelpContext(This,index,dwHelpContext)    \
'    ( (This)->lpVtbl -> SetVarHelpContext(This,index,dwHelpContext) )
'
'#define ICreateTypeInfo2_SetMops(This,index,bstrMops)   \
'    ( (This)->lpVtbl -> SetMops(This,index,bstrMops) )
'
'#define ICreateTypeInfo2_SetTypeIdldesc(This,pIdlDesc)  \
'    ( (This)->lpVtbl -> SetTypeIdldesc(This,pIdlDesc) )
'
'#define ICreateTypeInfo2_LayOut(This)   \
'    ( (This)->lpVtbl -> LayOut(This) )
'
'
'#define ICreateTypeInfo2_DeleteFuncDesc(This,index) \
'    ( (This)->lpVtbl -> DeleteFuncDesc(This,index) )
'
'#define ICreateTypeInfo2_DeleteFuncDescByMemId(This,memid,invKind)  \
'    ( (This)->lpVtbl -> DeleteFuncDescByMemId(This,memid,invKind) )
'
'#define ICreateTypeInfo2_DeleteVarDesc(This,index)  \
'    ( (This)->lpVtbl -> DeleteVarDesc(This,index) )
'
'#define ICreateTypeInfo2_DeleteVarDescByMemId(This,memid)   \
'    ( (This)->lpVtbl -> DeleteVarDescByMemId(This,memid) )
'
'#define ICreateTypeInfo2_DeleteImplType(This,index) \
'    ( (This)->lpVtbl -> DeleteImplType(This,index) )
'
'#define ICreateTypeInfo2_SetCustData(This,guid,pVarVal) \
'    ( (This)->lpVtbl -> SetCustData(This,guid,pVarVal) )
'
'#define ICreateTypeInfo2_SetFuncCustData(This,index,guid,pVarVal)   \
'    ( (This)->lpVtbl -> SetFuncCustData(This,index,guid,pVarVal) )
'
'#define ICreateTypeInfo2_SetParamCustData(This,indexFunc,indexParam,guid,pVarVal)   \
'    ( (This)->lpVtbl -> SetParamCustData(This,indexFunc,indexParam,guid,pVarVal) )
'
'#define ICreateTypeInfo2_SetVarCustData(This,index,guid,pVarVal)    \
'    ( (This)->lpVtbl -> SetVarCustData(This,index,guid,pVarVal) )
'
'#define ICreateTypeInfo2_SetImplTypeCustData(This,index,guid,pVarVal)   \
'    ( (This)->lpVtbl -> SetImplTypeCustData(This,index,guid,pVarVal) )
'
'#define ICreateTypeInfo2_SetHelpStringContext(This,dwHelpStringContext) \
'    ( (This)->lpVtbl -> SetHelpStringContext(This,dwHelpStringContext) )
'
'#define ICreateTypeInfo2_SetFuncHelpStringContext(This,index,dwHelpStringContext)   \
'    ( (This)->lpVtbl -> SetFuncHelpStringContext(This,index,dwHelpStringContext) )
'
'#define ICreateTypeInfo2_SetVarHelpStringContext(This,index,dwHelpStringContext)    \
'    ( (This)->lpVtbl -> SetVarHelpStringContext(This,index,dwHelpStringContext) )
'
'#define ICreateTypeInfo2_Invalidate(This)   \
'    ( (This)->lpVtbl -> Invalidate(This) )
'
'#define ICreateTypeInfo2_SetName(This,szName)   \
'    ( (This)->lpVtbl -> SetName(This,szName) )
'
'#endif ' COBJMACROS
'
'
'#endif  ' C style interface
'
'
'
'
'#endif  ' __ICreateTypeInfo2_INTERFACE_DEFINED__
'
'
'#ifndef __ICreateTypeLib_INTERFACE_DEFINED__
'#define __ICreateTypeLib_INTERFACE_DEFINED__
'
'' interface ICreateTypeLib
'
'
'
'EXTERN_C const IID IID_ICreateTypeLib;
'
'#if defined(__cplusplus) && !defined(CINTERFACE)
'
'    MIDL_INTERFACE("00020406-0000-0000-C000-000000000046")
'    ICreateTypeLib : public IUnknown
'    {
'    public:
'        virtual HRESULT STDMETHODCALLTYPE CreateTypeInfo(
'            LPOLESTR szName,
'            TYPEKIND tkind,
'            ICreateTypeInfo **ppCTInfo) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetName(
'            LPOLESTR szName) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetVersion(
'            WORD wMajorVerNum,
'            WORD wMinorVerNum) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetGuid(
'            REFGUID guid) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetDocString(
'            LPOLESTR szDoc) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetHelpFileName(
'            LPOLESTR szHelpFileName) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetHelpContext(
'            DWORD dwHelpContext) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetLcid(
'            LCID lcid) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetLibFlags(
'            DWORD uLibFlags) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SaveAllChanges( void) = 0;
'
'    };
'
'#else   ' C style interface
'
'    typedef struct ICreateTypeLibVtbl
'    {
'        BEGIN_INTERFACE
'
'        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
'            ICreateTypeLib * This,
'            REFIID riid,
'            void **ppvObject);
'
'        DWORD ( STDMETHODCALLTYPE *AddRef )(
'            ICreateTypeLib * This);
'
'        DWORD ( STDMETHODCALLTYPE *Release )(
'            ICreateTypeLib * This);
'
'        HRESULT ( STDMETHODCALLTYPE *CreateTypeInfo )(
'            ICreateTypeLib * This,
'            LPOLESTR szName,
'            TYPEKIND tkind,
'            ICreateTypeInfo **ppCTInfo);
'
'        HRESULT ( STDMETHODCALLTYPE *SetName )(
'            ICreateTypeLib * This,
'            LPOLESTR szName);
'
'        HRESULT ( STDMETHODCALLTYPE *SetVersion )(
'            ICreateTypeLib * This,
'            WORD wMajorVerNum,
'            WORD wMinorVerNum);
'
'        HRESULT ( STDMETHODCALLTYPE *SetGuid )(
'            ICreateTypeLib * This,
'            REFGUID guid);
'
'        HRESULT ( STDMETHODCALLTYPE *SetDocString )(
'            ICreateTypeLib * This,
'            LPOLESTR szDoc);
'
'        HRESULT ( STDMETHODCALLTYPE *SetHelpFileName )(
'            ICreateTypeLib * This,
'            LPOLESTR szHelpFileName);
'
'        HRESULT ( STDMETHODCALLTYPE *SetHelpContext )(
'            ICreateTypeLib * This,
'            DWORD dwHelpContext);
'
'        HRESULT ( STDMETHODCALLTYPE *SetLcid )(
'            ICreateTypeLib * This,
'            LCID lcid);
'
'        HRESULT ( STDMETHODCALLTYPE *SetLibFlags )(
'            ICreateTypeLib * This,
'            DWORD uLibFlags);
'
'        HRESULT ( STDMETHODCALLTYPE *SaveAllChanges )(
'            ICreateTypeLib * This);
'
'        END_INTERFACE
'    } ICreateTypeLibVtbl;
'
'    interface ICreateTypeLib
'    {
'        CONST_VTBL struct ICreateTypeLibVtbl *lpVtbl;
'    };
'
'
'
'#ifdef COBJMACROS
'
'
'#define ICreateTypeLib_QueryInterface(This,riid,ppvObject)  \
'    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
'
'#define ICreateTypeLib_AddRef(This) \
'    ( (This)->lpVtbl -> AddRef(This) )
'
'#define ICreateTypeLib_Release(This)    \
'    ( (This)->lpVtbl -> Release(This) )
'
'
'#define ICreateTypeLib_CreateTypeInfo(This,szName,tkind,ppCTInfo)   \
'    ( (This)->lpVtbl -> CreateTypeInfo(This,szName,tkind,ppCTInfo) )
'
'#define ICreateTypeLib_SetName(This,szName) \
'    ( (This)->lpVtbl -> SetName(This,szName) )
'
'#define ICreateTypeLib_SetVersion(This,wMajorVerNum,wMinorVerNum)   \
'    ( (This)->lpVtbl -> SetVersion(This,wMajorVerNum,wMinorVerNum) )
'
'#define ICreateTypeLib_SetGuid(This,guid)   \
'    ( (This)->lpVtbl -> SetGuid(This,guid) )
'
'#define ICreateTypeLib_SetDocString(This,szDoc) \
'    ( (This)->lpVtbl -> SetDocString(This,szDoc) )
'
'#define ICreateTypeLib_SetHelpFileName(This,szHelpFileName) \
'    ( (This)->lpVtbl -> SetHelpFileName(This,szHelpFileName) )
'
'#define ICreateTypeLib_SetHelpContext(This,dwHelpContext)   \
'    ( (This)->lpVtbl -> SetHelpContext(This,dwHelpContext) )
'
'#define ICreateTypeLib_SetLcid(This,lcid)   \
'    ( (This)->lpVtbl -> SetLcid(This,lcid) )
'
'#define ICreateTypeLib_SetLibFlags(This,uLibFlags)  \
'    ( (This)->lpVtbl -> SetLibFlags(This,uLibFlags) )
'
'#define ICreateTypeLib_SaveAllChanges(This) \
'    ( (This)->lpVtbl -> SaveAllChanges(This) )
'
'#endif ' COBJMACROS
'
'
'#endif  ' C style interface
'
'
'
'
'#endif  ' __ICreateTypeLib_INTERFACE_DEFINED__
'
'
'#ifndef __ICreateTypeLib2_INTERFACE_DEFINED__
'#define __ICreateTypeLib2_INTERFACE_DEFINED__
'
'' interface ICreateTypeLib2
'
'
'
'EXTERN_C const IID IID_ICreateTypeLib2;
'
'#if defined(__cplusplus) && !defined(CINTERFACE)
'
'    MIDL_INTERFACE("0002040F-0000-0000-C000-000000000046")
'    ICreateTypeLib2 : public ICreateTypeLib
'    {
'    public:
'        virtual HRESULT STDMETHODCALLTYPE DeleteTypeInfo(
'            LPOLESTR szName) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetCustData(
'            REFGUID guid,
'            VARIANT *pVarVal) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetHelpStringContext(
'            DWORD dwHelpStringContext) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetHelpStringDll(
'            LPOLESTR szFileName) = 0;
'
'    };
'
'#else   ' C style interface
'
'    typedef struct ICreateTypeLib2Vtbl
'    {
'        BEGIN_INTERFACE
'
'        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
'            ICreateTypeLib2 * This,
'            REFIID riid,
'            void **ppvObject);
'
'        DWORD ( STDMETHODCALLTYPE *AddRef )(
'            ICreateTypeLib2 * This);
'
'        DWORD ( STDMETHODCALLTYPE *Release )(
'            ICreateTypeLib2 * This);
'
'        HRESULT ( STDMETHODCALLTYPE *CreateTypeInfo )(
'            ICreateTypeLib2 * This,
'            LPOLESTR szName,
'            TYPEKIND tkind,
'            ICreateTypeInfo **ppCTInfo);
'
'        HRESULT ( STDMETHODCALLTYPE *SetName )(
'            ICreateTypeLib2 * This,
'            LPOLESTR szName);
'
'        HRESULT ( STDMETHODCALLTYPE *SetVersion )(
'            ICreateTypeLib2 * This,
'            WORD wMajorVerNum,
'            WORD wMinorVerNum);
'
'        HRESULT ( STDMETHODCALLTYPE *SetGuid )(
'            ICreateTypeLib2 * This,
'            REFGUID guid);
'
'        HRESULT ( STDMETHODCALLTYPE *SetDocString )(
'            ICreateTypeLib2 * This,
'            LPOLESTR szDoc);
'
'        HRESULT ( STDMETHODCALLTYPE *SetHelpFileName )(
'            ICreateTypeLib2 * This,
'            LPOLESTR szHelpFileName);
'
'        HRESULT ( STDMETHODCALLTYPE *SetHelpContext )(
'            ICreateTypeLib2 * This,
'            DWORD dwHelpContext);
'
'        HRESULT ( STDMETHODCALLTYPE *SetLcid )(
'            ICreateTypeLib2 * This,
'            LCID lcid);
'
'        HRESULT ( STDMETHODCALLTYPE *SetLibFlags )(
'            ICreateTypeLib2 * This,
'            DWORD uLibFlags);
'
'        HRESULT ( STDMETHODCALLTYPE *SaveAllChanges )(
'            ICreateTypeLib2 * This);
'
'        HRESULT ( STDMETHODCALLTYPE *DeleteTypeInfo )(
'            ICreateTypeLib2 * This,
'            LPOLESTR szName);
'
'        HRESULT ( STDMETHODCALLTYPE *SetCustData )(
'            ICreateTypeLib2 * This,
'            REFGUID guid,
'            VARIANT *pVarVal);
'
'        HRESULT ( STDMETHODCALLTYPE *SetHelpStringContext )(
'            ICreateTypeLib2 * This,
'            DWORD dwHelpStringContext);
'
'        HRESULT ( STDMETHODCALLTYPE *SetHelpStringDll )(
'            ICreateTypeLib2 * This,
'            LPOLESTR szFileName);
'
'        END_INTERFACE
'    } ICreateTypeLib2Vtbl;
'
'    interface ICreateTypeLib2
'    {
'        CONST_VTBL struct ICreateTypeLib2Vtbl *lpVtbl;
'    };
'
'
'
'#ifdef COBJMACROS
'
'
'#define ICreateTypeLib2_QueryInterface(This,riid,ppvObject) \
'    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
'
'#define ICreateTypeLib2_AddRef(This)    \
'    ( (This)->lpVtbl -> AddRef(This) )
'
'#define ICreateTypeLib2_Release(This)   \
'    ( (This)->lpVtbl -> Release(This) )
'
'
'#define ICreateTypeLib2_CreateTypeInfo(This,szName,tkind,ppCTInfo)  \
'    ( (This)->lpVtbl -> CreateTypeInfo(This,szName,tkind,ppCTInfo) )
'
'#define ICreateTypeLib2_SetName(This,szName)    \
'    ( (This)->lpVtbl -> SetName(This,szName) )
'
'#define ICreateTypeLib2_SetVersion(This,wMajorVerNum,wMinorVerNum)  \
'    ( (This)->lpVtbl -> SetVersion(This,wMajorVerNum,wMinorVerNum) )
'
'#define ICreateTypeLib2_SetGuid(This,guid)  \
'    ( (This)->lpVtbl -> SetGuid(This,guid) )
'
'#define ICreateTypeLib2_SetDocString(This,szDoc)    \
'    ( (This)->lpVtbl -> SetDocString(This,szDoc) )
'
'#define ICreateTypeLib2_SetHelpFileName(This,szHelpFileName)    \
'    ( (This)->lpVtbl -> SetHelpFileName(This,szHelpFileName) )
'
'#define ICreateTypeLib2_SetHelpContext(This,dwHelpContext)  \
'    ( (This)->lpVtbl -> SetHelpContext(This,dwHelpContext) )
'
'#define ICreateTypeLib2_SetLcid(This,lcid)  \
'    ( (This)->lpVtbl -> SetLcid(This,lcid) )
'
'#define ICreateTypeLib2_SetLibFlags(This,uLibFlags) \
'    ( (This)->lpVtbl -> SetLibFlags(This,uLibFlags) )
'
'#define ICreateTypeLib2_SaveAllChanges(This)    \
'    ( (This)->lpVtbl -> SaveAllChanges(This) )
'
'
'#define ICreateTypeLib2_DeleteTypeInfo(This,szName) \
'    ( (This)->lpVtbl -> DeleteTypeInfo(This,szName) )
'
'#define ICreateTypeLib2_SetCustData(This,guid,pVarVal)  \
'    ( (This)->lpVtbl -> SetCustData(This,guid,pVarVal) )
'
'#define ICreateTypeLib2_SetHelpStringContext(This,dwHelpStringContext)  \
'    ( (This)->lpVtbl -> SetHelpStringContext(This,dwHelpStringContext) )
'
'#define ICreateTypeLib2_SetHelpStringDll(This,szFileName)   \
'    ( (This)->lpVtbl -> SetHelpStringDll(This,szFileName) )
'
'#endif ' COBJMACROS
'
'
'#endif  ' C style interface
'
'
'
'
'#endif  ' __ICreateTypeLib2_INTERFACE_DEFINED__


#IF NOT %DEF(%IDispatch_INTERFACE_DEFINED)
%IDispatch_INTERFACE_DEFINED = 1

' interface IDispatch


' DISPID reserved to indicate an "unknown" name
' only reserved for data members (properties); reused as a method dispid below
%DISPID_UNKNOWN  = -1

' DISPID reserved for the "value" property
%DISPID_VALUE    = 0

' The following DISPID is reserved to indicate the param
' that is the right-hand-side =or "put" value of a PropertyPut
'
%DISPID_PROPERTYPUT  = -3

' DISPID reserved for the standard "NewEnum" method
%DISPID_NEWENUM  = -4

' DISPID reserved for the standard "Evaluate" method
%DISPID_EVALUATE = -5

%DISPID_CONSTRUCTOR  = -6

%DISPID_DESTRUCTOR   = -7

%DISPID_COLLECT  = -8

' The range -500 through -999 is reserved for Controls
' The range 0x80010000 through 0x8001FFFF is reserved for Controls
' The range -5000 through -5499 is reserved for ActiveX Accessability
' The range -2000 through -2499 is reserved for VB5
' The range -3900 through -3999 is reserved for Forms
' The range -5500 through -5550 is reserved for Forms
' The remainder of the negative DISPIDs are reserved for future use

'EXTERN_C const IID IID_IDispatch;
'
'#if defined(__cplusplus) && !defined(CINTERFACE)
'
'    MIDL_INTERFACE("00020400-0000-0000-C000-000000000046")
'    IDispatch : public IUnknown
'    {
'    public:
'        virtual HRESULT STDMETHODCALLTYPE GetTypeInfoCount(
'            DWORD *pctinfo) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetTypeInfo(
'            DWORD iTInfo,
'            LCID lcid,
'            ITypeInfo **ppTInfo) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetIDsOfNames(
'            REFIID riid,
'            LPOLESTR *rgszNames,
'            DWORD cNames,
'            LCID lcid,
'            DISPID *rgDispId) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE Invoke(
'            DISPID dispIdMember,
'            REFIID riid,
'            LCID lcid,
'            WORD wFlags,
'            DISPPARAMS *pDispParams,
'            VARIANT *pVarResult,
'            EXCEPINFO *pExcepInfo,
'            DWORD *puArgErr) = 0;
'
'    };
'
'#else   ' C style interface
'
'    typedef struct IDispatchVtbl
'    {
'        BEGIN_INTERFACE
'
'        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
'            IDispatch * This,
'            REFIID riid,
'            void **ppvObject);
'
'        DWORD ( STDMETHODCALLTYPE *AddRef )(
'            IDispatch * This);
'
'        DWORD ( STDMETHODCALLTYPE *Release )(
'            IDispatch * This);
'
'        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )(
'            IDispatch * This,
'            DWORD *pctinfo);
'
'        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )(
'            IDispatch * This,
'            DWORD iTInfo,
'            LCID lcid,
'            ITypeInfo **ppTInfo);
'
'        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )(
'            IDispatch * This,
'            REFIID riid,
'            LPOLESTR *rgszNames,
'            DWORD cNames,
'            LCID lcid,
'            DISPID *rgDispId);
'
'        HRESULT ( STDMETHODCALLTYPE *Invoke )(
'            IDispatch * This,
'            DISPID dispIdMember,
'            REFIID riid,
'            LCID lcid,
'            WORD wFlags,
'            DISPPARAMS *pDispParams,
'            VARIANT *pVarResult,
'            EXCEPINFO *pExcepInfo,
'            DWORD *puArgErr);
'
'        END_INTERFACE
'    } IDispatchVtbl;
'
'    interface IDispatch
'    {
'        CONST_VTBL struct IDispatchVtbl *lpVtbl;
'    };
'
'
'
'#ifdef COBJMACROS
'
'
'#define IDispatch_QueryInterface(This,riid,ppvObject)   \
'    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
'
'#define IDispatch_AddRef(This)  \
'    ( (This)->lpVtbl -> AddRef(This) )
'
'#define IDispatch_Release(This) \
'    ( (This)->lpVtbl -> Release(This) )
'
'
'#define IDispatch_GetTypeInfoCount(This,pctinfo)    \
'    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) )
'
'#define IDispatch_GetTypeInfo(This,iTInfo,lcid,ppTInfo) \
'    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) )
'
'#define IDispatch_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)   \
'    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) )
'
'#define IDispatch_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) \
'    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) )
'
'#endif ' COBJMACROS
'
'
'#endif  ' C style interface
'
'
'
'HRESULT STDMETHODCALLTYPE IDispatch_RemoteInvoke_Proxy(
'    IDispatch * This,
'    DISPID dispIdMember,
'    REFIID riid,
'    LCID lcid,
'    DWORD dwFlags,
'    DISPPARAMS *pDispParams,
'    VARIANT *pVarResult,
'    EXCEPINFO *pExcepInfo,
'    DWORD *pArgErr,
'    DWORD cVarRef,
'    DWORD *rgVarRefIdx,
'    VARIANT *rgVarRef);
'
'
'void IDispatch_RemoteInvoke_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);



#ENDIF  ' %IDispatch_INTERFACE_DEFINED


'#ifndef __IEnumVARIANT_INTERFACE_DEFINED__
'#define __IEnumVARIANT_INTERFACE_DEFINED__
'
'' interface IEnumVARIANT
'
'
'
'EXTERN_C const IID IID_IEnumVARIANT;
'
'#if defined(__cplusplus) && !defined(CINTERFACE)
'
'    MIDL_INTERFACE("00020404-0000-0000-C000-000000000046")
'    IEnumVARIANT : public IUnknown
'    {
'    public:
'        virtual HRESULT STDMETHODCALLTYPE Next(
'            DWORD celt,
'            VARIANT *rgVar,
'            DWORD *pCeltFetched) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE Skip(
'            DWORD celt) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE Clone(
'            IEnumVARIANT **ppEnum) = 0;
'
'    };
'
'#else   ' C style interface
'
'    typedef struct IEnumVARIANTVtbl
'    {
'        BEGIN_INTERFACE
'
'        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
'            IEnumVARIANT * This,
'            REFIID riid,
'            void **ppvObject);
'
'        DWORD ( STDMETHODCALLTYPE *AddRef )(
'            IEnumVARIANT * This);
'
'        DWORD ( STDMETHODCALLTYPE *Release )(
'            IEnumVARIANT * This);
'
'        HRESULT ( STDMETHODCALLTYPE *Next )(
'            IEnumVARIANT * This,
'            DWORD celt,
'            VARIANT *rgVar,
'            DWORD *pCeltFetched);
'
'        HRESULT ( STDMETHODCALLTYPE *Skip )(
'            IEnumVARIANT * This,
'            DWORD celt);
'
'        HRESULT ( STDMETHODCALLTYPE *Reset )(
'            IEnumVARIANT * This);
'
'        HRESULT ( STDMETHODCALLTYPE *Clone )(
'            IEnumVARIANT * This,
'            IEnumVARIANT **ppEnum);
'
'        END_INTERFACE
'    } IEnumVARIANTVtbl;
'
'    interface IEnumVARIANT
'    {
'        CONST_VTBL struct IEnumVARIANTVtbl *lpVtbl;
'    };
'
'
'
'#ifdef COBJMACROS
'
'
'#define IEnumVARIANT_QueryInterface(This,riid,ppvObject)    \
'    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
'
'#define IEnumVARIANT_AddRef(This)   \
'    ( (This)->lpVtbl -> AddRef(This) )
'
'#define IEnumVARIANT_Release(This)  \
'    ( (This)->lpVtbl -> Release(This) )
'
'
'#define IEnumVARIANT_Next(This,celt,rgVar,pCeltFetched) \
'    ( (This)->lpVtbl -> Next(This,celt,rgVar,pCeltFetched) )
'
'#define IEnumVARIANT_Skip(This,celt)    \
'    ( (This)->lpVtbl -> Skip(This,celt) )
'
'#define IEnumVARIANT_Reset(This)    \
'    ( (This)->lpVtbl -> Reset(This) )
'
'#define IEnumVARIANT_Clone(This,ppEnum) \
'    ( (This)->lpVtbl -> Clone(This,ppEnum) )
'
'#endif ' COBJMACROS
'
'
'#endif  ' C style interface
'
'
'
'HRESULT STDMETHODCALLTYPE IEnumVARIANT_RemoteNext_Proxy(
'    IEnumVARIANT * This,
'    DWORD celt,
'    VARIANT *rgVar,
'    DWORD *pCeltFetched);
'
'
'void IEnumVARIANT_RemoteNext_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'
'#endif  ' __IEnumVARIANT_INTERFACE_DEFINED__


#IF NOT %DEF(%ITypeComp_INTERFACE_DEFINED)
%ITypeComp_INTERFACE_DEFINED = 1

' interface ITypeComp


MACRO DESCKIND_enum=LONG
ENUM DESCKIND SINGULAR
    DESCKIND_NONE
    DESCKIND_FUNCDESC
    DESCKIND_VARDESC
    DESCKIND_TYPECOMP
    DESCKIND_IMPLICITAPPOBJ
    DESCKIND_MAX
END ENUM

TYPE BINDPTR
    lpfuncdesc AS FUNCDESC PTR
    lpvardesc  AS VARDESC PTR
    lptcomp    AS DWORD  ' ITypeComp ptr
END TYPE


'EXTERN_C const IID IID_ITypeComp;
'
'#if defined(__cplusplus) && !defined(CINTERFACE)
'
'    MIDL_INTERFACE("00020403-0000-0000-C000-000000000046")
'    ITypeComp : public IUnknown
'    {
'    public:
'        virtual  HRESULT STDMETHODCALLTYPE Bind(
'            LPOLESTR szName,
'            DWORD lHashVal,
'            WORD wFlags,
'            ITypeInfo **ppTInfo,
'            DESCKIND *pDescKind,
'            BINDPTR *pBindPtr) = 0;
'
'        virtual  HRESULT STDMETHODCALLTYPE BindType(
'            LPOLESTR szName,
'            DWORD lHashVal,
'            ITypeInfo **ppTInfo,
'            ITypeComp **ppTComp) = 0;
'
'    };
'
'#else   ' C style interface
'
'    typedef struct ITypeCompVtbl
'    {
'        BEGIN_INTERFACE
'
'        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
'            ITypeComp * This,
'            REFIID riid,
'            void **ppvObject);
'
'        DWORD ( STDMETHODCALLTYPE *AddRef )(
'            ITypeComp * This);
'
'        DWORD ( STDMETHODCALLTYPE *Release )(
'            ITypeComp * This);
'
'         HRESULT ( STDMETHODCALLTYPE *Bind )(
'            ITypeComp * This,
'            LPOLESTR szName,
'            DWORD lHashVal,
'            WORD wFlags,
'            ITypeInfo **ppTInfo,
'            DESCKIND *pDescKind,
'            BINDPTR *pBindPtr);
'
'         HRESULT ( STDMETHODCALLTYPE *BindType )(
'            ITypeComp * This,
'            LPOLESTR szName,
'            DWORD lHashVal,
'            ITypeInfo **ppTInfo,
'            ITypeComp **ppTComp);
'
'        END_INTERFACE
'    } ITypeCompVtbl;
'
'    interface ITypeComp
'    {
'        CONST_VTBL struct ITypeCompVtbl *lpVtbl;
'    };
'
'
'
'#ifdef COBJMACROS
'
'
'#define ITypeComp_QueryInterface(This,riid,ppvObject)   \
'    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
'
'#define ITypeComp_AddRef(This)  \
'    ( (This)->lpVtbl -> AddRef(This) )
'
'#define ITypeComp_Release(This) \
'    ( (This)->lpVtbl -> Release(This) )
'
'
'#define ITypeComp_Bind(This,szName,lHashVal,wFlags,ppTInfo,pDescKind,pBindPtr)  \
'    ( (This)->lpVtbl -> Bind(This,szName,lHashVal,wFlags,ppTInfo,pDescKind,pBindPtr) )
'
'#define ITypeComp_BindType(This,szName,lHashVal,ppTInfo,ppTComp)    \
'    ( (This)->lpVtbl -> BindType(This,szName,lHashVal,ppTInfo,ppTComp) )
'
'#endif ' COBJMACROS
'
'
'#endif  ' C style interface
'
'
'
'HRESULT STDMETHODCALLTYPE ITypeComp_RemoteBind_Proxy(
'    ITypeComp * This,
'    LPOLESTR szName,
'    DWORD lHashVal,
'    WORD wFlags,
'    ITypeInfo **ppTInfo,
'    DESCKIND *pDescKind,
'    LPFUNCDESC *ppFuncDesc,
'    LPVARDESC *ppVarDesc,
'    ITypeComp **ppTypeComp,
'    CLEANLOCALSTORAGE *pDummy);
'
'
'void ITypeComp_RemoteBind_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'HRESULT STDMETHODCALLTYPE ITypeComp_RemoteBindType_Proxy(
'    ITypeComp * This,
'    LPOLESTR szName,
'    DWORD lHashVal,
'    ITypeInfo **ppTInfo);
'
'
'void ITypeComp_RemoteBindType_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);


#ENDIF  ' %ITypeComp_INTERFACE_DEFINED



'#ifndef __ITypeInfo_INTERFACE_DEFINED__
'#define __ITypeInfo_INTERFACE_DEFINED__
'
'' interface ITypeInfo
'
'
'
'EXTERN_C const IID IID_ITypeInfo;
'
'#if defined(__cplusplus) && !defined(CINTERFACE)
'
'    MIDL_INTERFACE("00020401-0000-0000-C000-000000000046")
'    ITypeInfo : public IUnknown
'    {
'    public:
'        virtual  HRESULT STDMETHODCALLTYPE GetTypeAttr(
'            TYPEATTR **ppTypeAttr) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetTypeComp(
'            ITypeComp **ppTComp) = 0;
'
'        virtual  HRESULT STDMETHODCALLTYPE GetFuncDesc(
'            DWORD index,
'            FUNCDESC **ppFuncDesc) = 0;
'
'        virtual  HRESULT STDMETHODCALLTYPE GetVarDesc(
'            DWORD index,
'            VARDESC **ppVarDesc) = 0;
'
'        virtual  HRESULT STDMETHODCALLTYPE GetNames(
'            MEMBERID memid,
'            BSTR *rgBstrNames,
'            DWORD cMaxNames,
'            DWORD *pcNames) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetRefTypeOfImplType(
'            DWORD index,
'            HREFTYPE *pRefType) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetImplTypeFlags(
'            DWORD index,
'            LONG *pImplTypeFlags) = 0;
'
'        virtual  HRESULT STDMETHODCALLTYPE GetIDsOfNames(
'            LPOLESTR *rgszNames,
'            DWORD cNames,
'            MEMBERID *pMemId) = 0;
'
'        virtual  HRESULT STDMETHODCALLTYPE Invoke(
'            PVOID pvInstance,
'            MEMBERID memid,
'            WORD wFlags,
'            DISPPARAMS *pDispParams,
'            VARIANT *pVarResult,
'            EXCEPINFO *pExcepInfo,
'            DWORD *puArgErr) = 0;
'
'        virtual  HRESULT STDMETHODCALLTYPE GetDocumentation(
'            MEMBERID memid,
'            BSTR *pBstrName,
'            BSTR *pBstrDocString,
'            DWORD *pdwHelpContext,
'            BSTR *pBstrHelpFile) = 0;
'
'        virtual  HRESULT STDMETHODCALLTYPE GetDllEntry(
'            MEMBERID memid,
'            INVOKEKIND invKind,
'            BSTR *pBstrDllName,
'            BSTR *pBstrName,
'            WORD *pwOrdinal) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetRefTypeInfo(
'            HREFTYPE hRefType,
'            ITypeInfo **ppTInfo) = 0;
'
'        virtual  HRESULT STDMETHODCALLTYPE AddressOfMember(
'            MEMBERID memid,
'            INVOKEKIND invKind,
'            PVOID *ppv) = 0;
'
'        virtual  HRESULT STDMETHODCALLTYPE CreateInstance(
'            IUnknown *pUnkOuter,
'            REFIID riid,
'            PVOID *ppvObj) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetMops(
'            MEMBERID memid,
'            BSTR *pBstrMops) = 0;
'
'        virtual  HRESULT STDMETHODCALLTYPE GetContainingTypeLib(
'            ITypeLib **ppTLib,
'            DWORD *pIndex) = 0;
'
'        virtual  void STDMETHODCALLTYPE ReleaseTypeAttr(
'            TYPEATTR *pTypeAttr) = 0;
'
'        virtual  void STDMETHODCALLTYPE ReleaseFuncDesc(
'            FUNCDESC *pFuncDesc) = 0;
'
'        virtual  void STDMETHODCALLTYPE ReleaseVarDesc(
'            VARDESC *pVarDesc) = 0;
'
'    };
'
'#else   ' C style interface
'
'    typedef struct ITypeInfoVtbl
'    {
'        BEGIN_INTERFACE
'
'        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
'            ITypeInfo * This,
'            REFIID riid,
'            void **ppvObject);
'
'        DWORD ( STDMETHODCALLTYPE *AddRef )(
'            ITypeInfo * This);
'
'        DWORD ( STDMETHODCALLTYPE *Release )(
'            ITypeInfo * This);
'
'        HRESULT ( STDMETHODCALLTYPE *GetTypeAttr )(
'            ITypeInfo * This,
'            TYPEATTR **ppTypeAttr);
'
'        HRESULT ( STDMETHODCALLTYPE *GetTypeComp )(
'            ITypeInfo * This,
'            ITypeComp **ppTComp);
'
'        HRESULT ( STDMETHODCALLTYPE *GetFuncDesc )(
'            ITypeInfo * This,
'            DWORD index,
'            FUNCDESC **ppFuncDesc);
'
'        HRESULT ( STDMETHODCALLTYPE *GetVarDesc )(
'            ITypeInfo * This,
'            DWORD index,
'            VARDESC **ppVarDesc);
'
'        HRESULT ( STDMETHODCALLTYPE *GetNames )(
'            ITypeInfo * This,
'            MEMBERID memid,
'            BSTR *rgBstrNames,
'            DWORD cMaxNames,
'            DWORD *pcNames);
'
'        HRESULT ( STDMETHODCALLTYPE *GetRefTypeOfImplType )(
'            ITypeInfo * This,
'            DWORD index,
'            HREFTYPE *pRefType);
'
'        HRESULT ( STDMETHODCALLTYPE *GetImplTypeFlags )(
'            ITypeInfo * This,
'            DWORD index,
'            LONG *pImplTypeFlags);
'
'        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )(
'            ITypeInfo * This,
'            LPOLESTR *rgszNames,
'            DWORD cNames,
'            MEMBERID *pMemId);
'
'         HRESULT ( STDMETHODCALLTYPE *Invoke )(
'            ITypeInfo * This,
'            PVOID pvInstance,
'            MEMBERID memid,
'            WORD wFlags,
'            DISPPARAMS *pDispParams,
'            VARIANT *pVarResult,
'            EXCEPINFO *pExcepInfo,
'            DWORD *puArgErr);
'
'         HRESULT ( STDMETHODCALLTYPE *GetDocumentation )(
'            ITypeInfo * This,
'            MEMBERID memid,
'            BSTR *pBstrName,
'            BSTR *pBstrDocString,
'            DWORD *pdwHelpContext,
'            BSTR *pBstrHelpFile);
'
'         HRESULT ( STDMETHODCALLTYPE *GetDllEntry )(
'            ITypeInfo * This,
'            MEMBERID memid,
'            INVOKEKIND invKind,
'            BSTR *pBstrDllName,
'            BSTR *pBstrName,
'            WORD *pwOrdinal);
'
'        HRESULT ( STDMETHODCALLTYPE *GetRefTypeInfo )(
'            ITypeInfo * This,
'            HREFTYPE hRefType,
'            ITypeInfo **ppTInfo);
'
'        HRESULT ( STDMETHODCALLTYPE *AddressOfMember )(
'            ITypeInfo * This,
'            MEMBERID memid,
'            INVOKEKIND invKind,
'            PVOID *ppv);
'
'        HRESULT ( STDMETHODCALLTYPE *CreateInstance )(
'            ITypeInfo * This,
'            IUnknown *pUnkOuter,
'            REFIID riid,
'            PVOID *ppvObj);
'
'        HRESULT ( STDMETHODCALLTYPE *GetMops )(
'            ITypeInfo * This,
'            MEMBERID memid,
'            BSTR *pBstrMops);
'
'         HRESULT ( STDMETHODCALLTYPE *GetContainingTypeLib )(
'            ITypeInfo * This,
'            ITypeLib **ppTLib,
'            DWORD *pIndex);
'
'         void ( STDMETHODCALLTYPE *ReleaseTypeAttr )(
'            ITypeInfo * This,
'            TYPEATTR *pTypeAttr);
'
'         void ( STDMETHODCALLTYPE *ReleaseFuncDesc )(
'            ITypeInfo * This,
'            FUNCDESC *pFuncDesc);
'
'         void ( STDMETHODCALLTYPE *ReleaseVarDesc )(
'            ITypeInfo * This,
'            VARDESC *pVarDesc);
'
'        END_INTERFACE
'    } ITypeInfoVtbl;
'
'    interface ITypeInfo
'    {
'        CONST_VTBL struct ITypeInfoVtbl *lpVtbl;
'    };
'
'
'
'#ifdef COBJMACROS
'
'
'#define ITypeInfo_QueryInterface(This,riid,ppvObject)   \
'    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
'
'#define ITypeInfo_AddRef(This)  \
'    ( (This)->lpVtbl -> AddRef(This) )
'
'#define ITypeInfo_Release(This) \
'    ( (This)->lpVtbl -> Release(This) )
'
'
'#define ITypeInfo_GetTypeAttr(This,ppTypeAttr)  \
'    ( (This)->lpVtbl -> GetTypeAttr(This,ppTypeAttr) )
'
'#define ITypeInfo_GetTypeComp(This,ppTComp) \
'    ( (This)->lpVtbl -> GetTypeComp(This,ppTComp) )
'
'#define ITypeInfo_GetFuncDesc(This,index,ppFuncDesc)    \
'    ( (This)->lpVtbl -> GetFuncDesc(This,index,ppFuncDesc) )
'
'#define ITypeInfo_GetVarDesc(This,index,ppVarDesc)  \
'    ( (This)->lpVtbl -> GetVarDesc(This,index,ppVarDesc) )
'
'#define ITypeInfo_GetNames(This,memid,rgBstrNames,cMaxNames,pcNames)    \
'    ( (This)->lpVtbl -> GetNames(This,memid,rgBstrNames,cMaxNames,pcNames) )
'
'#define ITypeInfo_GetRefTypeOfImplType(This,index,pRefType) \
'    ( (This)->lpVtbl -> GetRefTypeOfImplType(This,index,pRefType) )
'
'#define ITypeInfo_GetImplTypeFlags(This,index,pImplTypeFlags)   \
'    ( (This)->lpVtbl -> GetImplTypeFlags(This,index,pImplTypeFlags) )
'
'#define ITypeInfo_GetIDsOfNames(This,rgszNames,cNames,pMemId)   \
'    ( (This)->lpVtbl -> GetIDsOfNames(This,rgszNames,cNames,pMemId) )
'
'#define ITypeInfo_Invoke(This,pvInstance,memid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)   \
'    ( (This)->lpVtbl -> Invoke(This,pvInstance,memid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) )
'
'#define ITypeInfo_GetDocumentation(This,memid,pBstrName,pBstrDocString,pdwHelpContext,pBstrHelpFile)    \
'    ( (This)->lpVtbl -> GetDocumentation(This,memid,pBstrName,pBstrDocString,pdwHelpContext,pBstrHelpFile) )
'
'#define ITypeInfo_GetDllEntry(This,memid,invKind,pBstrDllName,pBstrName,pwOrdinal)  \
'    ( (This)->lpVtbl -> GetDllEntry(This,memid,invKind,pBstrDllName,pBstrName,pwOrdinal) )
'
'#define ITypeInfo_GetRefTypeInfo(This,hRefType,ppTInfo) \
'    ( (This)->lpVtbl -> GetRefTypeInfo(This,hRefType,ppTInfo) )
'
'#define ITypeInfo_AddressOfMember(This,memid,invKind,ppv)   \
'    ( (This)->lpVtbl -> AddressOfMember(This,memid,invKind,ppv) )
'
'#define ITypeInfo_CreateInstance(This,pUnkOuter,riid,ppvObj)    \
'    ( (This)->lpVtbl -> CreateInstance(This,pUnkOuter,riid,ppvObj) )
'
'#define ITypeInfo_GetMops(This,memid,pBstrMops) \
'    ( (This)->lpVtbl -> GetMops(This,memid,pBstrMops) )
'
'#define ITypeInfo_GetContainingTypeLib(This,ppTLib,pIndex)  \
'    ( (This)->lpVtbl -> GetContainingTypeLib(This,ppTLib,pIndex) )
'
'#define ITypeInfo_ReleaseTypeAttr(This,pTypeAttr)   \
'    ( (This)->lpVtbl -> ReleaseTypeAttr(This,pTypeAttr) )
'
'#define ITypeInfo_ReleaseFuncDesc(This,pFuncDesc)   \
'    ( (This)->lpVtbl -> ReleaseFuncDesc(This,pFuncDesc) )
'
'#define ITypeInfo_ReleaseVarDesc(This,pVarDesc) \
'    ( (This)->lpVtbl -> ReleaseVarDesc(This,pVarDesc) )
'
'#endif ' COBJMACROS
'
'
'#endif  ' C style interface
'
'
'
'HRESULT STDMETHODCALLTYPE ITypeInfo_RemoteGetTypeAttr_Proxy(
'    ITypeInfo * This,
'    LPTYPEATTR *ppTypeAttr,
'    CLEANLOCALSTORAGE *pDummy);
'
'
'void ITypeInfo_RemoteGetTypeAttr_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'HRESULT STDMETHODCALLTYPE ITypeInfo_RemoteGetFuncDesc_Proxy(
'    ITypeInfo * This,
'    DWORD index,
'    LPFUNCDESC *ppFuncDesc,
'    CLEANLOCALSTORAGE *pDummy);
'
'
'void ITypeInfo_RemoteGetFuncDesc_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'HRESULT STDMETHODCALLTYPE ITypeInfo_RemoteGetVarDesc_Proxy(
'    ITypeInfo * This,
'    DWORD index,
'    LPVARDESC *ppVarDesc,
'    CLEANLOCALSTORAGE *pDummy);
'
'
'void ITypeInfo_RemoteGetVarDesc_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'HRESULT STDMETHODCALLTYPE ITypeInfo_RemoteGetNames_Proxy(
'    ITypeInfo * This,
'    MEMBERID memid,
'    BSTR *rgBstrNames,
'    DWORD cMaxNames,
'    DWORD *pcNames);
'
'
'void ITypeInfo_RemoteGetNames_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'HRESULT STDMETHODCALLTYPE ITypeInfo_LocalGetIDsOfNames_Proxy(
'    ITypeInfo * This);
'
'
'void ITypeInfo_LocalGetIDsOfNames_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'HRESULT STDMETHODCALLTYPE ITypeInfo_LocalInvoke_Proxy(
'    ITypeInfo * This);
'
'
'void ITypeInfo_LocalInvoke_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'HRESULT STDMETHODCALLTYPE ITypeInfo_RemoteGetDocumentation_Proxy(
'    ITypeInfo * This,
'    MEMBERID memid,
'    DWORD refPtrFlags,
'    BSTR *pBstrName,
'    BSTR *pBstrDocString,
'    DWORD *pdwHelpContext,
'    BSTR *pBstrHelpFile);
'
'
'void ITypeInfo_RemoteGetDocumentation_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'HRESULT STDMETHODCALLTYPE ITypeInfo_RemoteGetDllEntry_Proxy(
'    ITypeInfo * This,
'    MEMBERID memid,
'    INVOKEKIND invKind,
'    DWORD refPtrFlags,
'    BSTR *pBstrDllName,
'    BSTR *pBstrName,
'    WORD *pwOrdinal);
'
'
'void ITypeInfo_RemoteGetDllEntry_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'HRESULT STDMETHODCALLTYPE ITypeInfo_LocalAddressOfMember_Proxy(
'    ITypeInfo * This);
'
'
'void ITypeInfo_LocalAddressOfMember_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'HRESULT STDMETHODCALLTYPE ITypeInfo_RemoteCreateInstance_Proxy(
'    ITypeInfo * This,
'    REFIID riid,
'    IUnknown **ppvObj);
'
'
'void ITypeInfo_RemoteCreateInstance_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'HRESULT STDMETHODCALLTYPE ITypeInfo_RemoteGetContainingTypeLib_Proxy(
'    ITypeInfo * This,
'    ITypeLib **ppTLib,
'    DWORD *pIndex);
'
'
'void ITypeInfo_RemoteGetContainingTypeLib_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'HRESULT STDMETHODCALLTYPE ITypeInfo_LocalReleaseTypeAttr_Proxy(
'    ITypeInfo * This);
'
'
'void ITypeInfo_LocalReleaseTypeAttr_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'HRESULT STDMETHODCALLTYPE ITypeInfo_LocalReleaseFuncDesc_Proxy(
'    ITypeInfo * This);
'
'
'void ITypeInfo_LocalReleaseFuncDesc_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'HRESULT STDMETHODCALLTYPE ITypeInfo_LocalReleaseVarDesc_Proxy(
'    ITypeInfo * This);
'
'
'void ITypeInfo_LocalReleaseVarDesc_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'
'#endif  ' __ITypeInfo_INTERFACE_DEFINED__
'
'
'#ifndef __ITypeInfo2_INTERFACE_DEFINED__
'#define __ITypeInfo2_INTERFACE_DEFINED__
'
'' interface ITypeInfo2
'
'
'
'EXTERN_C const IID IID_ITypeInfo2;
'
'#if defined(__cplusplus) && !defined(CINTERFACE)
'
'    MIDL_INTERFACE("00020412-0000-0000-C000-000000000046")
'    ITypeInfo2 : public ITypeInfo
'    {
'    public:
'        virtual HRESULT STDMETHODCALLTYPE GetTypeKind(
'            TYPEKIND *pTypeKind) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetTypeFlags(
'            DWORD *pTypeFlags) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetFuncIndexOfMemId(
'            MEMBERID memid,
'            INVOKEKIND invKind,
'            DWORD *pFuncIndex) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetVarIndexOfMemId(
'            MEMBERID memid,
'            DWORD *pVarIndex) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetCustData(
'            REFGUID guid,
'            VARIANT *pVarVal) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetFuncCustData(
'            DWORD index,
'            REFGUID guid,
'            VARIANT *pVarVal) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetParamCustData(
'            DWORD indexFunc,
'            DWORD indexParam,
'            REFGUID guid,
'            VARIANT *pVarVal) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetVarCustData(
'            DWORD index,
'            REFGUID guid,
'            VARIANT *pVarVal) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetImplTypeCustData(
'            DWORD index,
'            REFGUID guid,
'            VARIANT *pVarVal) = 0;
'
'        virtual  HRESULT STDMETHODCALLTYPE GetDocumentation2(
'            MEMBERID memid,
'            LCID lcid,
'            BSTR *pbstrHelpString,
'            DWORD *pdwHelpStringContext,
'            BSTR *pbstrHelpStringDll) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetAllCustData(
'            CUSTDATA *pCustData) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetAllFuncCustData(
'            DWORD index,
'            CUSTDATA *pCustData) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetAllParamCustData(
'            DWORD indexFunc,
'            DWORD indexParam,
'            CUSTDATA *pCustData) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetAllVarCustData(
'            DWORD index,
'            CUSTDATA *pCustData) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetAllImplTypeCustData(
'            DWORD index,
'            CUSTDATA *pCustData) = 0;
'
'    };
'
'#else   ' C style interface
'
'    typedef struct ITypeInfo2Vtbl
'    {
'        BEGIN_INTERFACE
'
'        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
'            ITypeInfo2 * This,
'            REFIID riid,
'            void **ppvObject);
'
'        DWORD ( STDMETHODCALLTYPE *AddRef )(
'            ITypeInfo2 * This);
'
'        DWORD ( STDMETHODCALLTYPE *Release )(
'            ITypeInfo2 * This);
'
'        HRESULT ( STDMETHODCALLTYPE *GetTypeAttr )(
'            ITypeInfo2 * This,
'            TYPEATTR **ppTypeAttr);
'
'        HRESULT ( STDMETHODCALLTYPE *GetTypeComp )(
'            ITypeInfo2 * This,
'            ITypeComp **ppTComp);
'
'        HRESULT ( STDMETHODCALLTYPE *GetFuncDesc )(
'            ITypeInfo2 * This,
'            DWORD index,
'            FUNCDESC **ppFuncDesc);
'
'        HRESULT ( STDMETHODCALLTYPE *GetVarDesc )(
'            ITypeInfo2 * This,
'            DWORD index,
'            VARDESC **ppVarDesc);
'
'        HRESULT ( STDMETHODCALLTYPE *GetNames )(
'            ITypeInfo2 * This,
'            MEMBERID memid,
'            BSTR *rgBstrNames,
'            DWORD cMaxNames,
'            DWORD *pcNames);
'
'        HRESULT ( STDMETHODCALLTYPE *GetRefTypeOfImplType )(
'            ITypeInfo2 * This,
'            DWORD index,
'            HREFTYPE *pRefType);
'
'        HRESULT ( STDMETHODCALLTYPE *GetImplTypeFlags )(
'            ITypeInfo2 * This,
'            DWORD index,
'            LONG *pImplTypeFlags);
'
'        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )(
'            ITypeInfo2 * This,
'            LPOLESTR *rgszNames,
'            DWORD cNames,
'            MEMBERID *pMemId);
'
'        HRESULT ( STDMETHODCALLTYPE *Invoke )(
'            ITypeInfo2 * This,
'            PVOID pvInstance,
'            MEMBERID memid,
'            WORD wFlags,
'            DISPPARAMS *pDispParams,
'            VARIANT *pVarResult,
'            EXCEPINFO *pExcepInfo,
'            DWORD *puArgErr);
'
'        HRESULT ( STDMETHODCALLTYPE *GetDocumentation )(
'            ITypeInfo2 * This,
'            MEMBERID memid,
'            BSTR *pBstrName,
'            BSTR *pBstrDocString,
'            DWORD *pdwHelpContext,
'            BSTR *pBstrHelpFile);
'
'        HRESULT ( STDMETHODCALLTYPE *GetDllEntry )(
'            ITypeInfo2 * This,
'            MEMBERID memid,
'            INVOKEKIND invKind,
'            BSTR *pBstrDllName,
'            BSTR *pBstrName,
'            WORD *pwOrdinal);
'
'        HRESULT ( STDMETHODCALLTYPE *GetRefTypeInfo )(
'            ITypeInfo2 * This,
'            HREFTYPE hRefType,
'            ITypeInfo **ppTInfo);
'
'        HRESULT ( STDMETHODCALLTYPE *AddressOfMember )(
'            ITypeInfo2 * This,
'            MEMBERID memid,
'            INVOKEKIND invKind,
'            PVOID *ppv);
'
'         HRESULT ( STDMETHODCALLTYPE *CreateInstance )(
'            ITypeInfo2 * This,
'            IUnknown *pUnkOuter,
'            REFIID riid,
'            PVOID *ppvObj);
'
'        HRESULT ( STDMETHODCALLTYPE *GetMops )(
'            ITypeInfo2 * This,
'            MEMBERID memid,
'            BSTR *pBstrMops);
'
'        HRESULT ( STDMETHODCALLTYPE *GetContainingTypeLib )(
'            ITypeInfo2 * This,
'            ITypeLib **ppTLib,
'            DWORD *pIndex);
'
'        void ( STDMETHODCALLTYPE *ReleaseTypeAttr )(
'            ITypeInfo2 * This,
'            TYPEATTR *pTypeAttr);
'
'        void ( STDMETHODCALLTYPE *ReleaseFuncDesc )(
'            ITypeInfo2 * This,
'            FUNCDESC *pFuncDesc);
'
'        void ( STDMETHODCALLTYPE *ReleaseVarDesc )(
'            ITypeInfo2 * This,
'            VARDESC *pVarDesc);
'
'        HRESULT ( STDMETHODCALLTYPE *GetTypeKind )(
'            ITypeInfo2 * This,
'            TYPEKIND *pTypeKind);
'
'        HRESULT ( STDMETHODCALLTYPE *GetTypeFlags )(
'            ITypeInfo2 * This,
'            DWORD *pTypeFlags);
'
'        HRESULT ( STDMETHODCALLTYPE *GetFuncIndexOfMemId )(
'            ITypeInfo2 * This,
'            MEMBERID memid,
'            INVOKEKIND invKind,
'            DWORD *pFuncIndex);
'
'        HRESULT ( STDMETHODCALLTYPE *GetVarIndexOfMemId )(
'            ITypeInfo2 * This,
'            MEMBERID memid,
'            DWORD *pVarIndex);
'
'        HRESULT ( STDMETHODCALLTYPE *GetCustData )(
'            ITypeInfo2 * This,
'            REFGUID guid,
'            VARIANT *pVarVal);
'
'        HRESULT ( STDMETHODCALLTYPE *GetFuncCustData )(
'            ITypeInfo2 * This,
'            DWORD index,
'            REFGUID guid,
'            VARIANT *pVarVal);
'
'        HRESULT ( STDMETHODCALLTYPE *GetParamCustData )(
'            ITypeInfo2 * This,
'            DWORD indexFunc,
'            DWORD indexParam,
'            REFGUID guid,
'            VARIANT *pVarVal);
'
'        HRESULT ( STDMETHODCALLTYPE *GetVarCustData )(
'            ITypeInfo2 * This,
'            DWORD index,
'            REFGUID guid,
'            VARIANT *pVarVal);
'
'        HRESULT ( STDMETHODCALLTYPE *GetImplTypeCustData )(
'            ITypeInfo2 * This,
'            DWORD index,
'            REFGUID guid,
'            VARIANT *pVarVal);
'
'        HRESULT ( STDMETHODCALLTYPE *GetDocumentation2 )(
'            ITypeInfo2 * This,
'            MEMBERID memid,
'            LCID lcid,
'            BSTR *pbstrHelpString,
'            DWORD *pdwHelpStringContext,
'            BSTR *pbstrHelpStringDll);
'
'        HRESULT ( STDMETHODCALLTYPE *GetAllCustData )(
'            ITypeInfo2 * This,
'            CUSTDATA *pCustData);
'
'        HRESULT ( STDMETHODCALLTYPE *GetAllFuncCustData )(
'            ITypeInfo2 * This,
'            DWORD index,
'            CUSTDATA *pCustData);
'
'        HRESULT ( STDMETHODCALLTYPE *GetAllParamCustData )(
'            ITypeInfo2 * This,
'            DWORD indexFunc,
'            DWORD indexParam,
'            CUSTDATA *pCustData);
'
'        HRESULT ( STDMETHODCALLTYPE *GetAllVarCustData )(
'            ITypeInfo2 * This,
'            DWORD index,
'            CUSTDATA *pCustData);
'
'        HRESULT ( STDMETHODCALLTYPE *GetAllImplTypeCustData )(
'            ITypeInfo2 * This,
'            DWORD index,
'            CUSTDATA *pCustData);
'
'        END_INTERFACE
'    } ITypeInfo2Vtbl;
'
'    interface ITypeInfo2
'    {
'        CONST_VTBL struct ITypeInfo2Vtbl *lpVtbl;
'    };
'
'
'
'#ifdef COBJMACROS
'
'
'#define ITypeInfo2_QueryInterface(This,riid,ppvObject)  \
'    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
'
'#define ITypeInfo2_AddRef(This) \
'    ( (This)->lpVtbl -> AddRef(This) )
'
'#define ITypeInfo2_Release(This)    \
'    ( (This)->lpVtbl -> Release(This) )
'
'
'#define ITypeInfo2_GetTypeAttr(This,ppTypeAttr) \
'    ( (This)->lpVtbl -> GetTypeAttr(This,ppTypeAttr) )
'
'#define ITypeInfo2_GetTypeComp(This,ppTComp)    \
'    ( (This)->lpVtbl -> GetTypeComp(This,ppTComp) )
'
'#define ITypeInfo2_GetFuncDesc(This,index,ppFuncDesc)   \
'    ( (This)->lpVtbl -> GetFuncDesc(This,index,ppFuncDesc) )
'
'#define ITypeInfo2_GetVarDesc(This,index,ppVarDesc) \
'    ( (This)->lpVtbl -> GetVarDesc(This,index,ppVarDesc) )
'
'#define ITypeInfo2_GetNames(This,memid,rgBstrNames,cMaxNames,pcNames)   \
'    ( (This)->lpVtbl -> GetNames(This,memid,rgBstrNames,cMaxNames,pcNames) )
'
'#define ITypeInfo2_GetRefTypeOfImplType(This,index,pRefType)    \
'    ( (This)->lpVtbl -> GetRefTypeOfImplType(This,index,pRefType) )
'
'#define ITypeInfo2_GetImplTypeFlags(This,index,pImplTypeFlags)  \
'    ( (This)->lpVtbl -> GetImplTypeFlags(This,index,pImplTypeFlags) )
'
'#define ITypeInfo2_GetIDsOfNames(This,rgszNames,cNames,pMemId)  \
'    ( (This)->lpVtbl -> GetIDsOfNames(This,rgszNames,cNames,pMemId) )
'
'#define ITypeInfo2_Invoke(This,pvInstance,memid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)  \
'    ( (This)->lpVtbl -> Invoke(This,pvInstance,memid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) )
'
'#define ITypeInfo2_GetDocumentation(This,memid,pBstrName,pBstrDocString,pdwHelpContext,pBstrHelpFile)   \
'    ( (This)->lpVtbl -> GetDocumentation(This,memid,pBstrName,pBstrDocString,pdwHelpContext,pBstrHelpFile) )
'
'#define ITypeInfo2_GetDllEntry(This,memid,invKind,pBstrDllName,pBstrName,pwOrdinal) \
'    ( (This)->lpVtbl -> GetDllEntry(This,memid,invKind,pBstrDllName,pBstrName,pwOrdinal) )
'
'#define ITypeInfo2_GetRefTypeInfo(This,hRefType,ppTInfo)    \
'    ( (This)->lpVtbl -> GetRefTypeInfo(This,hRefType,ppTInfo) )
'
'#define ITypeInfo2_AddressOfMember(This,memid,invKind,ppv)  \
'    ( (This)->lpVtbl -> AddressOfMember(This,memid,invKind,ppv) )
'
'#define ITypeInfo2_CreateInstance(This,pUnkOuter,riid,ppvObj)   \
'    ( (This)->lpVtbl -> CreateInstance(This,pUnkOuter,riid,ppvObj) )
'
'#define ITypeInfo2_GetMops(This,memid,pBstrMops)    \
'    ( (This)->lpVtbl -> GetMops(This,memid,pBstrMops) )
'
'#define ITypeInfo2_GetContainingTypeLib(This,ppTLib,pIndex) \
'    ( (This)->lpVtbl -> GetContainingTypeLib(This,ppTLib,pIndex) )
'
'#define ITypeInfo2_ReleaseTypeAttr(This,pTypeAttr)  \
'    ( (This)->lpVtbl -> ReleaseTypeAttr(This,pTypeAttr) )
'
'#define ITypeInfo2_ReleaseFuncDesc(This,pFuncDesc)  \
'    ( (This)->lpVtbl -> ReleaseFuncDesc(This,pFuncDesc) )
'
'#define ITypeInfo2_ReleaseVarDesc(This,pVarDesc)    \
'    ( (This)->lpVtbl -> ReleaseVarDesc(This,pVarDesc) )
'
'
'#define ITypeInfo2_GetTypeKind(This,pTypeKind)  \
'    ( (This)->lpVtbl -> GetTypeKind(This,pTypeKind) )
'
'#define ITypeInfo2_GetTypeFlags(This,pTypeFlags)    \
'    ( (This)->lpVtbl -> GetTypeFlags(This,pTypeFlags) )
'
'#define ITypeInfo2_GetFuncIndexOfMemId(This,memid,invKind,pFuncIndex)   \
'    ( (This)->lpVtbl -> GetFuncIndexOfMemId(This,memid,invKind,pFuncIndex) )
'
'#define ITypeInfo2_GetVarIndexOfMemId(This,memid,pVarIndex) \
'    ( (This)->lpVtbl -> GetVarIndexOfMemId(This,memid,pVarIndex) )
'
'#define ITypeInfo2_GetCustData(This,guid,pVarVal)   \
'    ( (This)->lpVtbl -> GetCustData(This,guid,pVarVal) )
'
'#define ITypeInfo2_GetFuncCustData(This,index,guid,pVarVal) \
'    ( (This)->lpVtbl -> GetFuncCustData(This,index,guid,pVarVal) )
'
'#define ITypeInfo2_GetParamCustData(This,indexFunc,indexParam,guid,pVarVal) \
'    ( (This)->lpVtbl -> GetParamCustData(This,indexFunc,indexParam,guid,pVarVal) )
'
'#define ITypeInfo2_GetVarCustData(This,index,guid,pVarVal)  \
'    ( (This)->lpVtbl -> GetVarCustData(This,index,guid,pVarVal) )
'
'#define ITypeInfo2_GetImplTypeCustData(This,index,guid,pVarVal) \
'    ( (This)->lpVtbl -> GetImplTypeCustData(This,index,guid,pVarVal) )
'
'#define ITypeInfo2_GetDocumentation2(This,memid,lcid,pbstrHelpString,pdwHelpStringContext,pbstrHelpStringDll)   \
'    ( (This)->lpVtbl -> GetDocumentation2(This,memid,lcid,pbstrHelpString,pdwHelpStringContext,pbstrHelpStringDll) )
'
'#define ITypeInfo2_GetAllCustData(This,pCustData)   \
'    ( (This)->lpVtbl -> GetAllCustData(This,pCustData) )
'
'#define ITypeInfo2_GetAllFuncCustData(This,index,pCustData) \
'    ( (This)->lpVtbl -> GetAllFuncCustData(This,index,pCustData) )
'
'#define ITypeInfo2_GetAllParamCustData(This,indexFunc,indexParam,pCustData) \
'    ( (This)->lpVtbl -> GetAllParamCustData(This,indexFunc,indexParam,pCustData) )
'
'#define ITypeInfo2_GetAllVarCustData(This,index,pCustData)  \
'    ( (This)->lpVtbl -> GetAllVarCustData(This,index,pCustData) )
'
'#define ITypeInfo2_GetAllImplTypeCustData(This,index,pCustData) \
'    ( (This)->lpVtbl -> GetAllImplTypeCustData(This,index,pCustData) )
'
'#endif ' COBJMACROS
'
'
'#endif  ' C style interface
'
'
'
'HRESULT STDMETHODCALLTYPE ITypeInfo2_RemoteGetDocumentation2_Proxy(
'    ITypeInfo2 * This,
'    MEMBERID memid,
'    LCID lcid,
'    DWORD refPtrFlags,
'    BSTR *pbstrHelpString,
'    DWORD *pdwHelpStringContext,
'    BSTR *pbstrHelpStringDll);
'
'
'void ITypeInfo2_RemoteGetDocumentation2_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'
'#endif  ' __ITypeInfo2_INTERFACE_DEFINED__


#IF NOT %DEF(%ITypeLib_INTERFACE_DEFINED)
%ITypeLib_INTERFACE_DEFINED = 1

' interface ITypeLib

MACRO SYSKIND_enum=LONG
ENUM SYSKIND SINGULAR
    SYS_WIN16
    SYS_WIN32
    SYS_MAC
    SYS_WIN64
END ENUM

MACRO LIBFLAGS_enum=LONG
ENUM LIBFLAGS SINGULAR BITS
    LIBFLAG_FRESTRICTED = 1
    LIBFLAG_FCONTROL
    LIBFLAG_FHIDDEN
    LIBFLAG_FHASDISKIMAGE
END ENUM


TYPE TLIBATTR
    gguid        AS GUID
    lcid         AS DWORD  ' LCID
    syskind      AS SYSKIND_enum
    wMajorVerNum AS WORD
    wMinorVerNum AS WORD
    wLibFlags    AS WORD
END TYPE


'EXTERN_C const IID IID_ITypeLib;
'
'#if defined(__cplusplus) && !defined(CINTERFACE)
'
'    MIDL_INTERFACE("00020402-0000-0000-C000-000000000046")
'    ITypeLib : public IUnknown
'    {
'    public:
'        virtual  DWORD STDMETHODCALLTYPE GetTypeInfoCount( void) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetTypeInfo(
'            DWORD index,
'            ITypeInfo **ppTInfo) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetTypeInfoType(
'            DWORD index,
'            TYPEKIND *pTKind) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetTypeInfoOfGuid(
'            REFGUID guid,
'            ITypeInfo **ppTinfo) = 0;
'
'        virtual  HRESULT STDMETHODCALLTYPE GetLibAttr(
'            TLIBATTR **ppTLibAttr) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetTypeComp(
'            ITypeComp **ppTComp) = 0;
'
'        virtual  HRESULT STDMETHODCALLTYPE GetDocumentation(
'            LONG index,
'            BSTR *pBstrName,
'            BSTR *pBstrDocString,
'            DWORD *pdwHelpContext,
'            BSTR *pBstrHelpFile) = 0;
'
'        virtual  HRESULT STDMETHODCALLTYPE IsName(
'            LPOLESTR szNameBuf,
'            DWORD lHashVal,
'            BOOL *pfName) = 0;
'
'        virtual  HRESULT STDMETHODCALLTYPE FindName(
'            LPOLESTR szNameBuf,
'            DWORD lHashVal,
'            ITypeInfo **ppTInfo,
'            MEMBERID *rgMemId,
'            WORD *pcFound) = 0;
'
'        virtual  void STDMETHODCALLTYPE ReleaseTLibAttr(
'            TLIBATTR *pTLibAttr) = 0;
'
'    };
'
'#else   ' C style interface
'
'    typedef struct ITypeLibVtbl
'    {
'        BEGIN_INTERFACE
'
'        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
'            ITypeLib * This,
'            REFIID riid,
'            void **ppvObject);
'
'        DWORD ( STDMETHODCALLTYPE *AddRef )(
'            ITypeLib * This);
'
'        DWORD ( STDMETHODCALLTYPE *Release )(
'            ITypeLib * This);
'
'         DWORD ( STDMETHODCALLTYPE *GetTypeInfoCount )(
'            ITypeLib * This);
'
'        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )(
'            ITypeLib * This,
'            DWORD index,
'            ITypeInfo **ppTInfo);
'
'        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoType )(
'            ITypeLib * This,
'            DWORD index,
'            TYPEKIND *pTKind);
'
'        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoOfGuid )(
'            ITypeLib * This,
'            REFGUID guid,
'            ITypeInfo **ppTinfo);
'
'         HRESULT ( STDMETHODCALLTYPE *GetLibAttr )(
'            ITypeLib * This,
'            TLIBATTR **ppTLibAttr);
'
'        HRESULT ( STDMETHODCALLTYPE *GetTypeComp )(
'            ITypeLib * This,
'            ITypeComp **ppTComp);
'
'         HRESULT ( STDMETHODCALLTYPE *GetDocumentation )(
'            ITypeLib * This,
'            LONG index,
'            BSTR *pBstrName,
'            BSTR *pBstrDocString,
'            DWORD *pdwHelpContext,
'            BSTR *pBstrHelpFile);
'
'         HRESULT ( STDMETHODCALLTYPE *IsName )(
'            ITypeLib * This,
'            LPOLESTR szNameBuf,
'            DWORD lHashVal,
'            BOOL *pfName);
'
'         HRESULT ( STDMETHODCALLTYPE *FindName )(
'            ITypeLib * This,
'            LPOLESTR szNameBuf,
'            DWORD lHashVal,
'            ITypeInfo **ppTInfo,
'            MEMBERID *rgMemId,
'            WORD *pcFound);
'
'         void ( STDMETHODCALLTYPE *ReleaseTLibAttr )(
'            ITypeLib * This,
'            TLIBATTR *pTLibAttr);
'
'        END_INTERFACE
'    } ITypeLibVtbl;
'
'    interface ITypeLib
'    {
'        CONST_VTBL struct ITypeLibVtbl *lpVtbl;
'    };
'
'
'
'#ifdef COBJMACROS
'
'
'#define ITypeLib_QueryInterface(This,riid,ppvObject)    \
'    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
'
'#define ITypeLib_AddRef(This)   \
'    ( (This)->lpVtbl -> AddRef(This) )
'
'#define ITypeLib_Release(This)  \
'    ( (This)->lpVtbl -> Release(This) )
'
'
'#define ITypeLib_GetTypeInfoCount(This) \
'    ( (This)->lpVtbl -> GetTypeInfoCount(This) )
'
'#define ITypeLib_GetTypeInfo(This,index,ppTInfo)    \
'    ( (This)->lpVtbl -> GetTypeInfo(This,index,ppTInfo) )
'
'#define ITypeLib_GetTypeInfoType(This,index,pTKind) \
'    ( (This)->lpVtbl -> GetTypeInfoType(This,index,pTKind) )
'
'#define ITypeLib_GetTypeInfoOfGuid(This,guid,ppTinfo)   \
'    ( (This)->lpVtbl -> GetTypeInfoOfGuid(This,guid,ppTinfo) )
'
'#define ITypeLib_GetLibAttr(This,ppTLibAttr)    \
'    ( (This)->lpVtbl -> GetLibAttr(This,ppTLibAttr) )
'
'#define ITypeLib_GetTypeComp(This,ppTComp)  \
'    ( (This)->lpVtbl -> GetTypeComp(This,ppTComp) )
'
'#define ITypeLib_GetDocumentation(This,index,pBstrName,pBstrDocString,pdwHelpContext,pBstrHelpFile) \
'    ( (This)->lpVtbl -> GetDocumentation(This,index,pBstrName,pBstrDocString,pdwHelpContext,pBstrHelpFile) )
'
'#define ITypeLib_IsName(This,szNameBuf,lHashVal,pfName) \
'    ( (This)->lpVtbl -> IsName(This,szNameBuf,lHashVal,pfName) )
'
'#define ITypeLib_FindName(This,szNameBuf,lHashVal,ppTInfo,rgMemId,pcFound)  \
'    ( (This)->lpVtbl -> FindName(This,szNameBuf,lHashVal,ppTInfo,rgMemId,pcFound) )
'
'#define ITypeLib_ReleaseTLibAttr(This,pTLibAttr)    \
'    ( (This)->lpVtbl -> ReleaseTLibAttr(This,pTLibAttr) )
'
'#endif ' COBJMACROS
'
'
'#endif  ' C style interface
'
'
'
'HRESULT STDMETHODCALLTYPE ITypeLib_RemoteGetTypeInfoCount_Proxy(
'    ITypeLib * This,
'    DWORD *pcTInfo);
'
'
'void ITypeLib_RemoteGetTypeInfoCount_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'HRESULT STDMETHODCALLTYPE ITypeLib_RemoteGetLibAttr_Proxy(
'    ITypeLib * This,
'    LPTLIBATTR *ppTLibAttr,
'    CLEANLOCALSTORAGE *pDummy);
'
'
'void ITypeLib_RemoteGetLibAttr_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'HRESULT STDMETHODCALLTYPE ITypeLib_RemoteGetDocumentation_Proxy(
'    ITypeLib * This,
'    LONG index,
'    DWORD refPtrFlags,
'    BSTR *pBstrName,
'    BSTR *pBstrDocString,
'    DWORD *pdwHelpContext,
'    BSTR *pBstrHelpFile);
'
'
'void ITypeLib_RemoteGetDocumentation_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'HRESULT STDMETHODCALLTYPE ITypeLib_RemoteIsName_Proxy(
'    ITypeLib * This,
'    LPOLESTR szNameBuf,
'    DWORD lHashVal,
'    BOOL *pfName,
'    BSTR *pBstrLibName);
'
'
'void ITypeLib_RemoteIsName_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'HRESULT STDMETHODCALLTYPE ITypeLib_RemoteFindName_Proxy(
'    ITypeLib * This,
'    LPOLESTR szNameBuf,
'    DWORD lHashVal,
'    ITypeInfo **ppTInfo,
'    MEMBERID *rgMemId,
'    WORD *pcFound,
'    BSTR *pBstrLibName);
'
'
'void ITypeLib_RemoteFindName_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'HRESULT STDMETHODCALLTYPE ITypeLib_LocalReleaseTLibAttr_Proxy(
'    ITypeLib * This);
'
'
'void ITypeLib_LocalReleaseTLibAttr_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'


#ENDIF  ' %ITypeLib_INTERFACE_DEFINED


'#ifndef __ITypeLib2_INTERFACE_DEFINED__
'#define __ITypeLib2_INTERFACE_DEFINED__
'
'' interface ITypeLib2
'
'
'
'EXTERN_C const IID IID_ITypeLib2;
'
'#if defined(__cplusplus) && !defined(CINTERFACE)
'
'    MIDL_INTERFACE("00020411-0000-0000-C000-000000000046")
'    ITypeLib2 : public ITypeLib
'    {
'    public:
'        virtual HRESULT STDMETHODCALLTYPE GetCustData(
'            REFGUID guid,
'            VARIANT *pVarVal) = 0;
'
'        virtual  HRESULT STDMETHODCALLTYPE GetLibStatistics(
'            DWORD *pcUniqueNames,
'            DWORD *pcchUniqueNames) = 0;
'
'        virtual  HRESULT STDMETHODCALLTYPE GetDocumentation2(
'            LONG index,
'            LCID lcid,
'            BSTR *pbstrHelpString,
'            DWORD *pdwHelpStringContext,
'            BSTR *pbstrHelpStringDll) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetAllCustData(
'            CUSTDATA *pCustData) = 0;
'
'    };
'
'#else   ' C style interface
'
'    typedef struct ITypeLib2Vtbl
'    {
'        BEGIN_INTERFACE
'
'        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
'            ITypeLib2 * This,
'            REFIID riid,
'            void **ppvObject);
'
'        DWORD ( STDMETHODCALLTYPE *AddRef )(
'            ITypeLib2 * This);
'
'        DWORD ( STDMETHODCALLTYPE *Release )(
'            ITypeLib2 * This);
'
'         DWORD ( STDMETHODCALLTYPE *GetTypeInfoCount )(
'            ITypeLib2 * This);
'
'        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )(
'            ITypeLib2 * This,
'            DWORD index,
'            ITypeInfo **ppTInfo);
'
'        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoType )(
'            ITypeLib2 * This,
'            DWORD index,
'            TYPEKIND *pTKind);
'
'        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoOfGuid )(
'            ITypeLib2 * This,
'            REFGUID guid,
'            ITypeInfo **ppTinfo);
'
'         HRESULT ( STDMETHODCALLTYPE *GetLibAttr )(
'            ITypeLib2 * This,
'            TLIBATTR **ppTLibAttr);
'
'        HRESULT ( STDMETHODCALLTYPE *GetTypeComp )(
'            ITypeLib2 * This,
'            ITypeComp **ppTComp);
'
'         HRESULT ( STDMETHODCALLTYPE *GetDocumentation )(
'            ITypeLib2 * This,
'            LONG index,
'            BSTR *pBstrName,
'            BSTR *pBstrDocString,
'            DWORD *pdwHelpContext,
'            BSTR *pBstrHelpFile);
'
'         HRESULT ( STDMETHODCALLTYPE *IsName )(
'            ITypeLib2 * This,
'            LPOLESTR szNameBuf,
'            DWORD lHashVal,
'            BOOL *pfName);
'
'         HRESULT ( STDMETHODCALLTYPE *FindName )(
'            ITypeLib2 * This,
'            LPOLESTR szNameBuf,
'            DWORD lHashVal,
'            ITypeInfo **ppTInfo,
'            MEMBERID *rgMemId,
'            WORD *pcFound);
'
'         void ( STDMETHODCALLTYPE *ReleaseTLibAttr )(
'            ITypeLib2 * This,
'            TLIBATTR *pTLibAttr);
'
'        HRESULT ( STDMETHODCALLTYPE *GetCustData )(
'            ITypeLib2 * This,
'            REFGUID guid,
'            VARIANT *pVarVal);
'
'         HRESULT ( STDMETHODCALLTYPE *GetLibStatistics )(
'            ITypeLib2 * This,
'            DWORD *pcUniqueNames,
'            DWORD *pcchUniqueNames);
'
'         HRESULT ( STDMETHODCALLTYPE *GetDocumentation2 )(
'            ITypeLib2 * This,
'            LONG index,
'            LCID lcid,
'            BSTR *pbstrHelpString,
'            DWORD *pdwHelpStringContext,
'            BSTR *pbstrHelpStringDll);
'
'        HRESULT ( STDMETHODCALLTYPE *GetAllCustData )(
'            ITypeLib2 * This,
'            CUSTDATA *pCustData);
'
'        END_INTERFACE
'    } ITypeLib2Vtbl;
'
'    interface ITypeLib2
'    {
'        CONST_VTBL struct ITypeLib2Vtbl *lpVtbl;
'    };
'
'
'
'#ifdef COBJMACROS
'
'
'#define ITypeLib2_QueryInterface(This,riid,ppvObject)   \
'    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
'
'#define ITypeLib2_AddRef(This)  \
'    ( (This)->lpVtbl -> AddRef(This) )
'
'#define ITypeLib2_Release(This) \
'    ( (This)->lpVtbl -> Release(This) )
'
'
'#define ITypeLib2_GetTypeInfoCount(This)    \
'    ( (This)->lpVtbl -> GetTypeInfoCount(This) )
'
'#define ITypeLib2_GetTypeInfo(This,index,ppTInfo)   \
'    ( (This)->lpVtbl -> GetTypeInfo(This,index,ppTInfo) )
'
'#define ITypeLib2_GetTypeInfoType(This,index,pTKind)    \
'    ( (This)->lpVtbl -> GetTypeInfoType(This,index,pTKind) )
'
'#define ITypeLib2_GetTypeInfoOfGuid(This,guid,ppTinfo)  \
'    ( (This)->lpVtbl -> GetTypeInfoOfGuid(This,guid,ppTinfo) )
'
'#define ITypeLib2_GetLibAttr(This,ppTLibAttr)   \
'    ( (This)->lpVtbl -> GetLibAttr(This,ppTLibAttr) )
'
'#define ITypeLib2_GetTypeComp(This,ppTComp) \
'    ( (This)->lpVtbl -> GetTypeComp(This,ppTComp) )
'
'#define ITypeLib2_GetDocumentation(This,index,pBstrName,pBstrDocString,pdwHelpContext,pBstrHelpFile)    \
'    ( (This)->lpVtbl -> GetDocumentation(This,index,pBstrName,pBstrDocString,pdwHelpContext,pBstrHelpFile) )
'
'#define ITypeLib2_IsName(This,szNameBuf,lHashVal,pfName)    \
'    ( (This)->lpVtbl -> IsName(This,szNameBuf,lHashVal,pfName) )
'
'#define ITypeLib2_FindName(This,szNameBuf,lHashVal,ppTInfo,rgMemId,pcFound) \
'    ( (This)->lpVtbl -> FindName(This,szNameBuf,lHashVal,ppTInfo,rgMemId,pcFound) )
'
'#define ITypeLib2_ReleaseTLibAttr(This,pTLibAttr)   \
'    ( (This)->lpVtbl -> ReleaseTLibAttr(This,pTLibAttr) )
'
'
'#define ITypeLib2_GetCustData(This,guid,pVarVal)    \
'    ( (This)->lpVtbl -> GetCustData(This,guid,pVarVal) )
'
'#define ITypeLib2_GetLibStatistics(This,pcUniqueNames,pcchUniqueNames)  \
'    ( (This)->lpVtbl -> GetLibStatistics(This,pcUniqueNames,pcchUniqueNames) )
'
'#define ITypeLib2_GetDocumentation2(This,index,lcid,pbstrHelpString,pdwHelpStringContext,pbstrHelpStringDll)    \
'    ( (This)->lpVtbl -> GetDocumentation2(This,index,lcid,pbstrHelpString,pdwHelpStringContext,pbstrHelpStringDll) )
'
'#define ITypeLib2_GetAllCustData(This,pCustData)    \
'    ( (This)->lpVtbl -> GetAllCustData(This,pCustData) )
'
'#endif ' COBJMACROS
'
'
'#endif  ' C style interface
'
'
'
'HRESULT STDMETHODCALLTYPE ITypeLib2_RemoteGetLibStatistics_Proxy(
'    ITypeLib2 * This,
'    DWORD *pcUniqueNames,
'    DWORD *pcchUniqueNames);
'
'
'void ITypeLib2_RemoteGetLibStatistics_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'HRESULT STDMETHODCALLTYPE ITypeLib2_RemoteGetDocumentation2_Proxy(
'    ITypeLib2 * This,
'    LONG index,
'    LCID lcid,
'    DWORD refPtrFlags,
'    BSTR *pbstrHelpString,
'    DWORD *pdwHelpStringContext,
'    BSTR *pbstrHelpStringDll);
'
'
'void ITypeLib2_RemoteGetDocumentation2_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'
'#endif  ' __ITypeLib2_INTERFACE_DEFINED__


#IF NOT %DEF(%ITypeChangeEvents_INTERFACE_DEFINED)
%ITypeChangeEvents_INTERFACE_DEFINED = 1

' interface ITypeChangeEvents


MACRO CHANGEKIND_enum=LONG
ENUM CHANGEKIND SINGULAR
    CHANGEKIND_ADDMEMBER
    CHANGEKIND_DELETEMEMBER
    CHANGEKIND_SETNAMES
    CHANGEKIND_SETDOCUMENTATION
    CHANGEKIND_GENERAL
    CHANGEKIND_INVALIDATE
    CHANGEKIND_CHANGEFAILED
    CHANGEKIND_MAX
END ENUM


'EXTERN_C const IID IID_ITypeChangeEvents;
'
'#if defined(__cplusplus) && !defined(CINTERFACE)
'
'    MIDL_INTERFACE("00020410-0000-0000-C000-000000000046")
'    ITypeChangeEvents : public IUnknown
'    {
'    public:
'        virtual HRESULT STDMETHODCALLTYPE RequestTypeChange(
'            CHANGEKIND changeKind,
'            ITypeInfo *pTInfoBefore,
'            LPOLESTR pStrName,
'            LONG *pfCancel) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE AfterTypeChange(
'            CHANGEKIND changeKind,
'            ITypeInfo *pTInfoAfter,
'            LPOLESTR pStrName) = 0;
'
'    };
'
'#else   ' C style interface
'
'    typedef struct ITypeChangeEventsVtbl
'    {
'        BEGIN_INTERFACE
'
'        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
'            ITypeChangeEvents * This,
'            REFIID riid,
'            void **ppvObject);
'
'        DWORD ( STDMETHODCALLTYPE *AddRef )(
'            ITypeChangeEvents * This);
'
'        DWORD ( STDMETHODCALLTYPE *Release )(
'            ITypeChangeEvents * This);
'
'        HRESULT ( STDMETHODCALLTYPE *RequestTypeChange )(
'            ITypeChangeEvents * This,
'            CHANGEKIND changeKind,
'            ITypeInfo *pTInfoBefore,
'            LPOLESTR pStrName,
'            LONG *pfCancel);
'
'        HRESULT ( STDMETHODCALLTYPE *AfterTypeChange )(
'            ITypeChangeEvents * This,
'            CHANGEKIND changeKind,
'            ITypeInfo *pTInfoAfter,
'            LPOLESTR pStrName);
'
'        END_INTERFACE
'    } ITypeChangeEventsVtbl;
'
'    interface ITypeChangeEvents
'    {
'        CONST_VTBL struct ITypeChangeEventsVtbl *lpVtbl;
'    };
'
'
'
'#ifdef COBJMACROS
'
'
'#define ITypeChangeEvents_QueryInterface(This,riid,ppvObject)   \
'    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
'
'#define ITypeChangeEvents_AddRef(This)  \
'    ( (This)->lpVtbl -> AddRef(This) )
'
'#define ITypeChangeEvents_Release(This) \
'    ( (This)->lpVtbl -> Release(This) )
'
'
'#define ITypeChangeEvents_RequestTypeChange(This,changeKind,pTInfoBefore,pStrName,pfCancel) \
'    ( (This)->lpVtbl -> RequestTypeChange(This,changeKind,pTInfoBefore,pStrName,pfCancel) )
'
'#define ITypeChangeEvents_AfterTypeChange(This,changeKind,pTInfoAfter,pStrName) \
'    ( (This)->lpVtbl -> AfterTypeChange(This,changeKind,pTInfoAfter,pStrName) )
'
'#endif ' COBJMACROS
'
'
'#endif  ' C style interface



#ENDIF  ' %ITypeChangeEvents_INTERFACE_DEFINED


'#ifndef __IErrorInfo_INTERFACE_DEFINED__
'#define __IErrorInfo_INTERFACE_DEFINED__
'
'' interface IErrorInfo
'
'
'
'EXTERN_C const IID IID_IErrorInfo;
'
'#if defined(__cplusplus) && !defined(CINTERFACE)
'
'    MIDL_INTERFACE("1CF2B120-547D-101B-8E65-08002B2BD119")
'    IErrorInfo : public IUnknown
'    {
'    public:
'        virtual HRESULT STDMETHODCALLTYPE GetGUID(
'            GUID *pGUID) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetSource(
'            BSTR *pBstrSource) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetDescription(
'            BSTR *pBstrDescription) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetHelpFile(
'            BSTR *pBstrHelpFile) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetHelpContext(
'            DWORD *pdwHelpContext) = 0;
'
'    };
'
'#else   ' C style interface
'
'    typedef struct IErrorInfoVtbl
'    {
'        BEGIN_INTERFACE
'
'        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
'            IErrorInfo * This,
'            REFIID riid,
'            void **ppvObject);
'
'        DWORD ( STDMETHODCALLTYPE *AddRef )(
'            IErrorInfo * This);
'
'        DWORD ( STDMETHODCALLTYPE *Release )(
'            IErrorInfo * This);
'
'        HRESULT ( STDMETHODCALLTYPE *GetGUID )(
'            IErrorInfo * This,
'            GUID *pGUID);
'
'        HRESULT ( STDMETHODCALLTYPE *GetSource )(
'            IErrorInfo * This,
'            BSTR *pBstrSource);
'
'        HRESULT ( STDMETHODCALLTYPE *GetDescription )(
'            IErrorInfo * This,
'            BSTR *pBstrDescription);
'
'        HRESULT ( STDMETHODCALLTYPE *GetHelpFile )(
'            IErrorInfo * This,
'            BSTR *pBstrHelpFile);
'
'        HRESULT ( STDMETHODCALLTYPE *GetHelpContext )(
'            IErrorInfo * This,
'            DWORD *pdwHelpContext);
'
'        END_INTERFACE
'    } IErrorInfoVtbl;
'
'    interface IErrorInfo
'    {
'        CONST_VTBL struct IErrorInfoVtbl *lpVtbl;
'    };
'
'
'
'#ifdef COBJMACROS
'
'
'#define IErrorInfo_QueryInterface(This,riid,ppvObject)  \
'    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
'
'#define IErrorInfo_AddRef(This) \
'    ( (This)->lpVtbl -> AddRef(This) )
'
'#define IErrorInfo_Release(This)    \
'    ( (This)->lpVtbl -> Release(This) )
'
'
'#define IErrorInfo_GetGUID(This,pGUID)  \
'    ( (This)->lpVtbl -> GetGUID(This,pGUID) )
'
'#define IErrorInfo_GetSource(This,pBstrSource)  \
'    ( (This)->lpVtbl -> GetSource(This,pBstrSource) )
'
'#define IErrorInfo_GetDescription(This,pBstrDescription)    \
'    ( (This)->lpVtbl -> GetDescription(This,pBstrDescription) )
'
'#define IErrorInfo_GetHelpFile(This,pBstrHelpFile)  \
'    ( (This)->lpVtbl -> GetHelpFile(This,pBstrHelpFile) )
'
'#define IErrorInfo_GetHelpContext(This,pdwHelpContext)  \
'    ( (This)->lpVtbl -> GetHelpContext(This,pdwHelpContext) )
'
'#endif ' COBJMACROS
'
'
'#endif  ' C style interface
'
'
'
'
'#endif  ' __IErrorInfo_INTERFACE_DEFINED__
'
'
'#ifndef __ICreateErrorInfo_INTERFACE_DEFINED__
'#define __ICreateErrorInfo_INTERFACE_DEFINED__
'
'' interface ICreateErrorInfo
'
'
'
'EXTERN_C const IID IID_ICreateErrorInfo;
'
'#if defined(__cplusplus) && !defined(CINTERFACE)
'
'    MIDL_INTERFACE("22F03340-547D-101B-8E65-08002B2BD119")
'    ICreateErrorInfo : public IUnknown
'    {
'    public:
'        virtual HRESULT STDMETHODCALLTYPE SetGUID(
'            REFGUID rguid) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetSource(
'            LPOLESTR szSource) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetDescription(
'            LPOLESTR szDescription) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetHelpFile(
'            LPOLESTR szHelpFile) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE SetHelpContext(
'            DWORD dwHelpContext) = 0;
'
'    };
'
'#else   ' C style interface
'
'    typedef struct ICreateErrorInfoVtbl
'    {
'        BEGIN_INTERFACE
'
'        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
'            ICreateErrorInfo * This,
'            REFIID riid,
'            void **ppvObject);
'
'        DWORD ( STDMETHODCALLTYPE *AddRef )(
'            ICreateErrorInfo * This);
'
'        DWORD ( STDMETHODCALLTYPE *Release )(
'            ICreateErrorInfo * This);
'
'        HRESULT ( STDMETHODCALLTYPE *SetGUID )(
'            ICreateErrorInfo * This,
'            REFGUID rguid);
'
'        HRESULT ( STDMETHODCALLTYPE *SetSource )(
'            ICreateErrorInfo * This,
'            LPOLESTR szSource);
'
'        HRESULT ( STDMETHODCALLTYPE *SetDescription )(
'            ICreateErrorInfo * This,
'            LPOLESTR szDescription);
'
'        HRESULT ( STDMETHODCALLTYPE *SetHelpFile )(
'            ICreateErrorInfo * This,
'            LPOLESTR szHelpFile);
'
'        HRESULT ( STDMETHODCALLTYPE *SetHelpContext )(
'            ICreateErrorInfo * This,
'            DWORD dwHelpContext);
'
'        END_INTERFACE
'    } ICreateErrorInfoVtbl;
'
'    interface ICreateErrorInfo
'    {
'        CONST_VTBL struct ICreateErrorInfoVtbl *lpVtbl;
'    };
'
'
'
'#ifdef COBJMACROS
'
'
'#define ICreateErrorInfo_QueryInterface(This,riid,ppvObject)    \
'    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
'
'#define ICreateErrorInfo_AddRef(This)   \
'    ( (This)->lpVtbl -> AddRef(This) )
'
'#define ICreateErrorInfo_Release(This)  \
'    ( (This)->lpVtbl -> Release(This) )
'
'
'#define ICreateErrorInfo_SetGUID(This,rguid)    \
'    ( (This)->lpVtbl -> SetGUID(This,rguid) )
'
'#define ICreateErrorInfo_SetSource(This,szSource)   \
'    ( (This)->lpVtbl -> SetSource(This,szSource) )
'
'#define ICreateErrorInfo_SetDescription(This,szDescription) \
'    ( (This)->lpVtbl -> SetDescription(This,szDescription) )
'
'#define ICreateErrorInfo_SetHelpFile(This,szHelpFile)   \
'    ( (This)->lpVtbl -> SetHelpFile(This,szHelpFile) )
'
'#define ICreateErrorInfo_SetHelpContext(This,dwHelpContext) \
'    ( (This)->lpVtbl -> SetHelpContext(This,dwHelpContext) )
'
'#endif ' COBJMACROS
'
'
'#endif  ' C style interface
'
'
'
'
'#endif  ' __ICreateErrorInfo_INTERFACE_DEFINED__
'
'
'#ifndef __ISupportErrorInfo_INTERFACE_DEFINED__
'#define __ISupportErrorInfo_INTERFACE_DEFINED__
'
'' interface ISupportErrorInfo
'
'
'
'EXTERN_C const IID IID_ISupportErrorInfo;
'
'#if defined(__cplusplus) && !defined(CINTERFACE)
'
'    MIDL_INTERFACE("DF0B3D60-548F-101B-8E65-08002B2BD119")
'    ISupportErrorInfo : public IUnknown
'    {
'    public:
'        virtual HRESULT STDMETHODCALLTYPE InterfaceSupportsErrorInfo(
'            REFIID riid) = 0;
'
'    };
'
'#else   ' C style interface
'
'    typedef struct ISupportErrorInfoVtbl
'    {
'        BEGIN_INTERFACE
'
'        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
'            ISupportErrorInfo * This,
'            REFIID riid,
'            void **ppvObject);
'
'        DWORD ( STDMETHODCALLTYPE *AddRef )(
'            ISupportErrorInfo * This);
'
'        DWORD ( STDMETHODCALLTYPE *Release )(
'            ISupportErrorInfo * This);
'
'        HRESULT ( STDMETHODCALLTYPE *InterfaceSupportsErrorInfo )(
'            ISupportErrorInfo * This,
'            REFIID riid);
'
'        END_INTERFACE
'    } ISupportErrorInfoVtbl;
'
'    interface ISupportErrorInfo
'    {
'        CONST_VTBL struct ISupportErrorInfoVtbl *lpVtbl;
'    };
'
'
'
'#ifdef COBJMACROS
'
'
'#define ISupportErrorInfo_QueryInterface(This,riid,ppvObject)   \
'    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
'
'#define ISupportErrorInfo_AddRef(This)  \
'    ( (This)->lpVtbl -> AddRef(This) )
'
'#define ISupportErrorInfo_Release(This) \
'    ( (This)->lpVtbl -> Release(This) )
'
'
'#define ISupportErrorInfo_InterfaceSupportsErrorInfo(This,riid) \
'    ( (This)->lpVtbl -> InterfaceSupportsErrorInfo(This,riid) )
'
'#endif ' COBJMACROS
'
'
'#endif  ' C style interface
'
'
'
'#endif  ' __ISupportErrorInfo_INTERFACE_DEFINED__
'
'
'#ifndef __ITypeFactory_INTERFACE_DEFINED__
'#define __ITypeFactory_INTERFACE_DEFINED__
'
'' interface ITypeFactory
'
'
'EXTERN_C const IID IID_ITypeFactory;
'
'#if defined(__cplusplus) && !defined(CINTERFACE)
'
'    MIDL_INTERFACE("0000002E-0000-0000-C000-000000000046")
'    ITypeFactory : public IUnknown
'    {
'    public:
'        virtual HRESULT STDMETHODCALLTYPE CreateFromTypeInfo(
'            ITypeInfo *pTypeInfo,
'            REFIID riid,
'            IUnknown **ppv) = 0;
'
'    };
'
'#else   ' C style interface
'
'    typedef struct ITypeFactoryVtbl
'    {
'        BEGIN_INTERFACE
'
'        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
'            ITypeFactory * This,
'            REFIID riid,
'            void **ppvObject);
'
'        DWORD ( STDMETHODCALLTYPE *AddRef )(
'            ITypeFactory * This);
'
'        DWORD ( STDMETHODCALLTYPE *Release )(
'            ITypeFactory * This);
'
'        HRESULT ( STDMETHODCALLTYPE *CreateFromTypeInfo )(
'            ITypeFactory * This,
'            ITypeInfo *pTypeInfo,
'            REFIID riid,
'            IUnknown **ppv);
'
'        END_INTERFACE
'    } ITypeFactoryVtbl;
'
'    interface ITypeFactory
'    {
'        CONST_VTBL struct ITypeFactoryVtbl *lpVtbl;
'    };
'
'
'
'#ifdef COBJMACROS
'
'
'#define ITypeFactory_QueryInterface(This,riid,ppvObject)    \
'    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
'
'#define ITypeFactory_AddRef(This)   \
'    ( (This)->lpVtbl -> AddRef(This) )
'
'#define ITypeFactory_Release(This)  \
'    ( (This)->lpVtbl -> Release(This) )
'
'
'#define ITypeFactory_CreateFromTypeInfo(This,pTypeInfo,riid,ppv)    \
'    ( (This)->lpVtbl -> CreateFromTypeInfo(This,pTypeInfo,riid,ppv) )
'
'#endif ' COBJMACROS
'
'
'#endif  ' C style interface
'
'
'
'
'#endif  ' __ITypeFactory_INTERFACE_DEFINED__
'
'
'#ifndef __ITypeMarshal_INTERFACE_DEFINED__
'#define __ITypeMarshal_INTERFACE_DEFINED__
'
'' interface ITypeMarshal
'
'
'EXTERN_C const IID IID_ITypeMarshal;
'
'#if defined(__cplusplus) && !defined(CINTERFACE)
'
'    MIDL_INTERFACE("0000002D-0000-0000-C000-000000000046")
'    ITypeMarshal : public IUnknown
'    {
'    public:
'        virtual HRESULT STDMETHODCALLTYPE Size(
'            PVOID pvType,
'            DWORD dwDestContext,
'            PVOID pvDestContext,
'            DWORD *pSize) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE Marshal(
'            PVOID pvType,
'            DWORD dwDestContext,
'            PVOID pvDestContext,
'            DWORD cbBufferLength,
'            BYTE *pBuffer,
'            DWORD *pcbWritten) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE Unmarshal(
'            PVOID pvType,
'            DWORD dwFlags,
'            DWORD cbBufferLength,
'            BYTE *pBuffer,
'            DWORD *pcbRead) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE Free(
'            PVOID pvType) = 0;
'
'    };
'
'#else   ' C style interface
'
'    typedef struct ITypeMarshalVtbl
'    {
'        BEGIN_INTERFACE
'
'        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
'            ITypeMarshal * This,
'            REFIID riid,
'            void **ppvObject);
'
'        DWORD ( STDMETHODCALLTYPE *AddRef )(
'            ITypeMarshal * This);
'
'        DWORD ( STDMETHODCALLTYPE *Release )(
'            ITypeMarshal * This);
'
'        HRESULT ( STDMETHODCALLTYPE *Size )(
'            ITypeMarshal * This,
'            PVOID pvType,
'            DWORD dwDestContext,
'            PVOID pvDestContext,
'            DWORD *pSize);
'
'        HRESULT ( STDMETHODCALLTYPE *Marshal )(
'            ITypeMarshal * This,
'            PVOID pvType,
'            DWORD dwDestContext,
'            PVOID pvDestContext,
'            DWORD cbBufferLength,
'            BYTE *pBuffer,
'            DWORD *pcbWritten);
'
'        HRESULT ( STDMETHODCALLTYPE *Unmarshal )(
'            ITypeMarshal * This,
'            PVOID pvType,
'            DWORD dwFlags,
'            DWORD cbBufferLength,
'            BYTE *pBuffer,
'            DWORD *pcbRead);
'
'        HRESULT ( STDMETHODCALLTYPE *Free )(
'            ITypeMarshal * This,
'            PVOID pvType);
'
'        END_INTERFACE
'    } ITypeMarshalVtbl;
'
'    interface ITypeMarshal
'    {
'        CONST_VTBL struct ITypeMarshalVtbl *lpVtbl;
'    };
'
'
'
'#ifdef COBJMACROS
'
'
'#define ITypeMarshal_QueryInterface(This,riid,ppvObject)    \
'    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
'
'#define ITypeMarshal_AddRef(This)   \
'    ( (This)->lpVtbl -> AddRef(This) )
'
'#define ITypeMarshal_Release(This)  \
'    ( (This)->lpVtbl -> Release(This) )
'
'
'#define ITypeMarshal_Size(This,pvType,dwDestContext,pvDestContext,pSize)    \
'    ( (This)->lpVtbl -> Size(This,pvType,dwDestContext,pvDestContext,pSize) )
'
'#define ITypeMarshal_Marshal(This,pvType,dwDestContext,pvDestContext,cbBufferLength,pBuffer,pcbWritten) \
'    ( (This)->lpVtbl -> Marshal(This,pvType,dwDestContext,pvDestContext,cbBufferLength,pBuffer,pcbWritten) )
'
'#define ITypeMarshal_Unmarshal(This,pvType,dwFlags,cbBufferLength,pBuffer,pcbRead)  \
'    ( (This)->lpVtbl -> Unmarshal(This,pvType,dwFlags,cbBufferLength,pBuffer,pcbRead) )
'
'#define ITypeMarshal_Free(This,pvType)  \
'    ( (This)->lpVtbl -> Free(This,pvType) )
'
'#endif ' COBJMACROS
'
'
'#endif  ' C style interface
'
'
'
'
'#endif  ' __ITypeMarshal_INTERFACE_DEFINED__
'
'
'#ifndef __IRecordInfo_INTERFACE_DEFINED__
'#define __IRecordInfo_INTERFACE_DEFINED__
'
'' interface IRecordInfo
'
'
'
'EXTERN_C const IID IID_IRecordInfo;
'
'#if defined(__cplusplus) && !defined(CINTERFACE)
'
'    MIDL_INTERFACE("0000002F-0000-0000-C000-000000000046")
'    IRecordInfo : public IUnknown
'    {
'    public:
'        virtual HRESULT STDMETHODCALLTYPE RecordInit(
'            PVOID pvNew) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE RecordClear(
'            PVOID pvExisting) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE RecordCopy(
'            PVOID pvExisting,
'            PVOID pvNew) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetGuid(
'            GUID *pguid) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetName(
'            BSTR *pbstrName) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetSize(
'            DWORD *pcbSize) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetTypeInfo(
'            ITypeInfo **ppTypeInfo) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetField(
'            PVOID pvData,
'            LPCOLESTR szFieldName,
'            VARIANT *pvarField) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetFieldNoCopy(
'            PVOID pvData,
'            LPCOLESTR szFieldName,
'            VARIANT *pvarField,
'            PVOID *ppvDataCArray) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE PutField(
'            DWORD wFlags,
'            PVOID pvData,
'            LPCOLESTR szFieldName,
'            VARIANT *pvarField) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE PutFieldNoCopy(
'            DWORD wFlags,
'            PVOID pvData,
'            LPCOLESTR szFieldName,
'            VARIANT *pvarField) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE GetFieldNames(
'            DWORD *pcNames,
'            BSTR *rgBstrNames) = 0;
'
'        virtual BOOL STDMETHODCALLTYPE IsMatchingType(
'            IRecordInfo *pRecordInfo) = 0;
'
'        virtual PVOID STDMETHODCALLTYPE RecordCreate( void) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE RecordCreateCopy(
'            PVOID pvSource,
'            PVOID *ppvDest) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE RecordDestroy(
'            PVOID pvRecord) = 0;
'
'    };
'
'#else   ' C style interface
'
'    typedef struct IRecordInfoVtbl
'    {
'        BEGIN_INTERFACE
'
'        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
'            IRecordInfo * This,
'            REFIID riid,
'            void **ppvObject);
'
'        DWORD ( STDMETHODCALLTYPE *AddRef )(
'            IRecordInfo * This);
'
'        DWORD ( STDMETHODCALLTYPE *Release )(
'            IRecordInfo * This);
'
'        HRESULT ( STDMETHODCALLTYPE *RecordInit )(
'            IRecordInfo * This,
'            PVOID pvNew);
'
'        HRESULT ( STDMETHODCALLTYPE *RecordClear )(
'            IRecordInfo * This,
'            PVOID pvExisting);
'
'        HRESULT ( STDMETHODCALLTYPE *RecordCopy )(
'            IRecordInfo * This,
'            PVOID pvExisting,
'            PVOID pvNew);
'
'        HRESULT ( STDMETHODCALLTYPE *GetGuid )(
'            IRecordInfo * This,
'            GUID *pguid);
'
'        HRESULT ( STDMETHODCALLTYPE *GetName )(
'            IRecordInfo * This,
'            BSTR *pbstrName);
'
'        HRESULT ( STDMETHODCALLTYPE *GetSize )(
'            IRecordInfo * This,
'            DWORD *pcbSize);
'
'        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )(
'            IRecordInfo * This,
'            ITypeInfo **ppTypeInfo);
'
'        HRESULT ( STDMETHODCALLTYPE *GetField )(
'            IRecordInfo * This,
'            PVOID pvData,
'            LPCOLESTR szFieldName,
'            VARIANT *pvarField);
'
'        HRESULT ( STDMETHODCALLTYPE *GetFieldNoCopy )(
'            IRecordInfo * This,
'            PVOID pvData,
'            LPCOLESTR szFieldName,
'            VARIANT *pvarField,
'            PVOID *ppvDataCArray);
'
'        HRESULT ( STDMETHODCALLTYPE *PutField )(
'            IRecordInfo * This,
'            DWORD wFlags,
'             PVOID pvData,
'            LPCOLESTR szFieldName,
'            VARIANT *pvarField);
'
'        HRESULT ( STDMETHODCALLTYPE *PutFieldNoCopy )(
'            IRecordInfo * This,
'            DWORD wFlags,
'             PVOID pvData,
'            LPCOLESTR szFieldName,
'            VARIANT *pvarField);
'
'        HRESULT ( STDMETHODCALLTYPE *GetFieldNames )(
'            IRecordInfo * This,
'             DWORD *pcNames,
'            BSTR *rgBstrNames);
'
'        BOOL ( STDMETHODCALLTYPE *IsMatchingType )(
'            IRecordInfo * This,
'            IRecordInfo *pRecordInfo);
'
'        PVOID ( STDMETHODCALLTYPE *RecordCreate )(
'            IRecordInfo * This);
'
'        HRESULT ( STDMETHODCALLTYPE *RecordCreateCopy )(
'            IRecordInfo * This,
'            PVOID pvSource,
'            PVOID *ppvDest);
'
'        HRESULT ( STDMETHODCALLTYPE *RecordDestroy )(
'            IRecordInfo * This,
'            PVOID pvRecord);
'
'        END_INTERFACE
'    } IRecordInfoVtbl;
'
'    interface IRecordInfo
'    {
'        CONST_VTBL struct IRecordInfoVtbl *lpVtbl;
'    };
'
'
'
'#ifdef COBJMACROS
'
'
'#define IRecordInfo_QueryInterface(This,riid,ppvObject) \
'    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
'
'#define IRecordInfo_AddRef(This)    \
'    ( (This)->lpVtbl -> AddRef(This) )
'
'#define IRecordInfo_Release(This)   \
'    ( (This)->lpVtbl -> Release(This) )
'
'
'#define IRecordInfo_RecordInit(This,pvNew)  \
'    ( (This)->lpVtbl -> RecordInit(This,pvNew) )
'
'#define IRecordInfo_RecordClear(This,pvExisting)    \
'    ( (This)->lpVtbl -> RecordClear(This,pvExisting) )
'
'#define IRecordInfo_RecordCopy(This,pvExisting,pvNew)   \
'    ( (This)->lpVtbl -> RecordCopy(This,pvExisting,pvNew) )
'
'#define IRecordInfo_GetGuid(This,pguid) \
'    ( (This)->lpVtbl -> GetGuid(This,pguid) )
'
'#define IRecordInfo_GetName(This,pbstrName) \
'    ( (This)->lpVtbl -> GetName(This,pbstrName) )
'
'#define IRecordInfo_GetSize(This,pcbSize)   \
'    ( (This)->lpVtbl -> GetSize(This,pcbSize) )
'
'#define IRecordInfo_GetTypeInfo(This,ppTypeInfo)    \
'    ( (This)->lpVtbl -> GetTypeInfo(This,ppTypeInfo) )
'
'#define IRecordInfo_GetField(This,pvData,szFieldName,pvarField) \
'    ( (This)->lpVtbl -> GetField(This,pvData,szFieldName,pvarField) )
'
'#define IRecordInfo_GetFieldNoCopy(This,pvData,szFieldName,pvarField,ppvDataCArray) \
'    ( (This)->lpVtbl -> GetFieldNoCopy(This,pvData,szFieldName,pvarField,ppvDataCArray) )
'
'#define IRecordInfo_PutField(This,wFlags,pvData,szFieldName,pvarField)  \
'    ( (This)->lpVtbl -> PutField(This,wFlags,pvData,szFieldName,pvarField) )
'
'#define IRecordInfo_PutFieldNoCopy(This,wFlags,pvData,szFieldName,pvarField)    \
'    ( (This)->lpVtbl -> PutFieldNoCopy(This,wFlags,pvData,szFieldName,pvarField) )
'
'#define IRecordInfo_GetFieldNames(This,pcNames,rgBstrNames) \
'    ( (This)->lpVtbl -> GetFieldNames(This,pcNames,rgBstrNames) )
'
'#define IRecordInfo_IsMatchingType(This,pRecordInfo)    \
'    ( (This)->lpVtbl -> IsMatchingType(This,pRecordInfo) )
'
'#define IRecordInfo_RecordCreate(This)  \
'    ( (This)->lpVtbl -> RecordCreate(This) )
'
'#define IRecordInfo_RecordCreateCopy(This,pvSource,ppvDest) \
'    ( (This)->lpVtbl -> RecordCreateCopy(This,pvSource,ppvDest) )
'
'#define IRecordInfo_RecordDestroy(This,pvRecord)    \
'    ( (This)->lpVtbl -> RecordDestroy(This,pvRecord) )
'
'#endif ' COBJMACROS
'
'
'#endif  ' C style interface
'
'
'
'
'#endif  ' __IRecordInfo_INTERFACE_DEFINED__
'
'
'#ifndef __IErrorLog_INTERFACE_DEFINED__
'#define __IErrorLog_INTERFACE_DEFINED__
'
'' interface IErrorLog
'
'
'
'EXTERN_C const IID IID_IErrorLog;
'
'#if defined(__cplusplus) && !defined(CINTERFACE)
'
'    MIDL_INTERFACE("3127CA40-446E-11CE-8135-00AA004BB851")
'    IErrorLog : public IUnknown
'    {
'    public:
'        virtual HRESULT STDMETHODCALLTYPE AddError(
'            LPCOLESTR pszPropName,
'            EXCEPINFO *pExcepInfo) = 0;
'
'    };
'
'#else   ' C style interface
'
'    typedef struct IErrorLogVtbl
'    {
'        BEGIN_INTERFACE
'
'        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
'            IErrorLog * This,
'            REFIID riid,
'            void **ppvObject);
'
'        DWORD ( STDMETHODCALLTYPE *AddRef )(
'            IErrorLog * This);
'
'        DWORD ( STDMETHODCALLTYPE *Release )(
'            IErrorLog * This);
'
'        HRESULT ( STDMETHODCALLTYPE *AddError )(
'            IErrorLog * This,
'            LPCOLESTR pszPropName,
'            EXCEPINFO *pExcepInfo);
'
'        END_INTERFACE
'    } IErrorLogVtbl;
'
'    interface IErrorLog
'    {
'        CONST_VTBL struct IErrorLogVtbl *lpVtbl;
'    };
'
'
'
'#ifdef COBJMACROS
'
'
'#define IErrorLog_QueryInterface(This,riid,ppvObject)   \
'    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
'
'#define IErrorLog_AddRef(This)  \
'    ( (This)->lpVtbl -> AddRef(This) )
'
'#define IErrorLog_Release(This) \
'    ( (This)->lpVtbl -> Release(This) )
'
'
'#define IErrorLog_AddError(This,pszPropName,pExcepInfo) \
'    ( (This)->lpVtbl -> AddError(This,pszPropName,pExcepInfo) )
'
'#endif ' COBJMACROS
'
'
'#endif  ' C style interface
'
'
'
'
'#endif  ' __IErrorLog_INTERFACE_DEFINED__
'
'
'#ifndef __IPropertyBag_INTERFACE_DEFINED__
'#define __IPropertyBag_INTERFACE_DEFINED__
'
'' interface IPropertyBag
'
'
'
'EXTERN_C const IID IID_IPropertyBag;
'
'#if defined(__cplusplus) && !defined(CINTERFACE)
'
'    MIDL_INTERFACE("55272A00-42CB-11CE-8135-00AA004BB851")
'    IPropertyBag : public IUnknown
'    {
'    public:
'        virtual  HRESULT STDMETHODCALLTYPE Read(
'            LPCOLESTR pszPropName,
'            VARIANT *pVar,
'            IErrorLog *pErrorLog) = 0;
'
'        virtual HRESULT STDMETHODCALLTYPE Write(
'            LPCOLESTR pszPropName,
'            VARIANT *pVar) = 0;
'
'    };
'
'#else   ' C style interface
'
'    typedef struct IPropertyBagVtbl
'    {
'        BEGIN_INTERFACE
'
'        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
'            IPropertyBag * This,
'            REFIID riid,
'            void **ppvObject);
'
'        DWORD ( STDMETHODCALLTYPE *AddRef )(
'            IPropertyBag * This);
'
'        DWORD ( STDMETHODCALLTYPE *Release )(
'            IPropertyBag * This);
'
'         HRESULT ( STDMETHODCALLTYPE *Read )(
'            IPropertyBag * This,
'            LPCOLESTR pszPropName,
'            VARIANT *pVar,
'            IErrorLog *pErrorLog);
'
'        HRESULT ( STDMETHODCALLTYPE *Write )(
'            IPropertyBag * This,
'            LPCOLESTR pszPropName,
'            VARIANT *pVar);
'
'        END_INTERFACE
'    } IPropertyBagVtbl;
'
'    interface IPropertyBag
'    {
'        CONST_VTBL struct IPropertyBagVtbl *lpVtbl;
'    };
'
'
'
'#ifdef COBJMACROS
'
'
'#define IPropertyBag_QueryInterface(This,riid,ppvObject)    \
'    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
'
'#define IPropertyBag_AddRef(This)   \
'    ( (This)->lpVtbl -> AddRef(This) )
'
'#define IPropertyBag_Release(This)  \
'    ( (This)->lpVtbl -> Release(This) )
'
'
'#define IPropertyBag_Read(This,pszPropName,pVar,pErrorLog)  \
'    ( (This)->lpVtbl -> Read(This,pszPropName,pVar,pErrorLog) )
'
'#define IPropertyBag_Write(This,pszPropName,pVar)   \
'    ( (This)->lpVtbl -> Write(This,pszPropName,pVar) )
'
'#endif ' COBJMACROS
'
'
'#endif  ' C style interface
'
'
'
'HRESULT STDMETHODCALLTYPE IPropertyBag_RemoteRead_Proxy(
'    IPropertyBag * This,
'    LPCOLESTR pszPropName,
'    VARIANT *pVar,
'    IErrorLog *pErrorLog,
'    DWORD varType,
'    IUnknown *pUnkObj);
'
'
'void IPropertyBag_RemoteRead_Stub(
'    IRpcStubBuffer *This,
'    IRpcChannelBuffer *_pRpcChannelBuffer,
'    PRPC_MESSAGE _pRpcMessage,
'    DWORD *_pdwStubPhase);
'
'
'
'#endif  ' __IPropertyBag_INTERFACE_DEFINED__
'
'
'' interface __MIDL_itf_oaidl_0000_0021
'
'
''extern RPC_IF_HANDLE __MIDL_itf_oaidl_0000_0021_v0_0_c_ifspec;
''extern RPC_IF_HANDLE __MIDL_itf_oaidl_0000_0021_v0_0_s_ifspec;
'
'' Additional Prototypes for ALL interfaces
'
'dword   BSTR_UserSize(dword *, dword, BSTR *);
'unsigned char * BSTR_UserMarshal(dword *, unsigned char *, BSTR *);
'unsigned char * BSTR_UserUnmarshal(dword *, unsigned char *, BSTR *);
'void            BSTR_UserFree(dword *, BSTR *);
'
'dword   CLEANLOCALSTORAGE_UserSize(dword *, dword, CLEANLOCALSTORAGE *);
'unsigned char * CLEANLOCALSTORAGE_UserMarshal(dword *, unsigned char *, CLEANLOCALSTORAGE *);
'unsigned char * CLEANLOCALSTORAGE_UserUnmarshal(dword *, unsigned char *, CLEANLOCALSTORAGE *);
'void            CLEANLOCALSTORAGE_UserFree(dword *, CLEANLOCALSTORAGE *);
'
'dword   VARIANT_UserSize(dword *, dword, VARIANT *);
'unsigned char * VARIANT_UserMarshal(dword *, unsigned char *, VARIANT *);
'unsigned char * VARIANT_UserUnmarshal(dword *, unsigned char *, VARIANT *);
'void            VARIANT_UserFree(dword *, VARIANT *);
'
'dword   BSTR_UserSize64(dword *, dword, BSTR *);
'unsigned char * BSTR_UserMarshal64(dword *, unsigned char *, BSTR *);
'unsigned char * BSTR_UserUnmarshal64(dword *, unsigned char *, BSTR *);
'void            BSTR_UserFree64(dword *, BSTR *);
'
'dword   CLEANLOCALSTORAGE_UserSize64(dword *, dword, CLEANLOCALSTORAGE *);
'unsigned char * CLEANLOCALSTORAGE_UserMarshal64(dword *, unsigned char *, CLEANLOCALSTORAGE *);
'unsigned char * CLEANLOCALSTORAGE_UserUnmarshal64(dword *, unsigned char *, CLEANLOCALSTORAGE *);
'void                      CLEANLOCALSTORAGE_UserFree64(dword *, CLEANLOCALSTORAGE *);
'
'dword   VARIANT_UserSize64(dword *, dword, VARIANT *);
'unsigned char * VARIANT_UserMarshal64(dword *, unsigned char *, VARIANT *);
'unsigned char * VARIANT_UserUnmarshal64(dword *, unsigned char *, VARIANT *);
'void            VARIANT_UserFree64(dword *, VARIANT *);
'
' HRESULT STDMETHODCALLTYPE IDispatch_Invoke_Proxy(
'    IDispatch * This,
'    DISPID dispIdMember,
'    REFIID riid,
'    LCID lcid,
'    WORD wFlags,
'    DISPPARAMS *pDispParams,
'    VARIANT *pVarResult,
'    EXCEPINFO *pExcepInfo,
'    DWORD *puArgErr);
'
'
' HRESULT STDMETHODCALLTYPE IDispatch_Invoke_Stub(
'    IDispatch * This,
'    DISPID dispIdMember,
'    REFIID riid,
'    LCID lcid,
'    DWORD dwFlags,
'    DISPPARAMS *pDispParams,
'    VARIANT *pVarResult,
'    EXCEPINFO *pExcepInfo,
'    DWORD *pArgErr,
'    DWORD cVarRef,
'    DWORD *rgVarRefIdx,
'    VARIANT *rgVarRef);
'
' HRESULT STDMETHODCALLTYPE IEnumVARIANT_Next_Proxy(
'    IEnumVARIANT * This,
'    DWORD celt,
'    VARIANT *rgVar,
'    DWORD *pCeltFetched);
'
'
' HRESULT STDMETHODCALLTYPE IEnumVARIANT_Next_Stub(
'    IEnumVARIANT * This,
'    DWORD celt,
'    VARIANT *rgVar,
'    DWORD *pCeltFetched);
'
' HRESULT STDMETHODCALLTYPE ITypeComp_Bind_Proxy(
'    ITypeComp * This,
'    LPOLESTR szName,
'    DWORD lHashVal,
'    WORD wFlags,
'    ITypeInfo **ppTInfo,
'    DESCKIND *pDescKind,
'    BINDPTR *pBindPtr);
'
'
' HRESULT STDMETHODCALLTYPE ITypeComp_Bind_Stub(
'    ITypeComp * This,
'    LPOLESTR szName,
'    DWORD lHashVal,
'    WORD wFlags,
'    ITypeInfo **ppTInfo,
'    DESCKIND *pDescKind,
'    LPFUNCDESC *ppFuncDesc,
'    LPVARDESC *ppVarDesc,
'    ITypeComp **ppTypeComp,
'    CLEANLOCALSTORAGE *pDummy);
'
' HRESULT STDMETHODCALLTYPE ITypeComp_BindType_Proxy(
'    ITypeComp * This,
'    LPOLESTR szName,
'    DWORD lHashVal,
'    ITypeInfo **ppTInfo,
'    ITypeComp **ppTComp);
'
'
' HRESULT STDMETHODCALLTYPE ITypeComp_BindType_Stub(
'    ITypeComp * This,
'    LPOLESTR szName,
'    DWORD lHashVal,
'    ITypeInfo **ppTInfo);
'
' HRESULT STDMETHODCALLTYPE ITypeInfo_GetTypeAttr_Proxy(
'    ITypeInfo * This,
'    TYPEATTR **ppTypeAttr);
'
'
' HRESULT STDMETHODCALLTYPE ITypeInfo_GetTypeAttr_Stub(
'    ITypeInfo * This,
'    LPTYPEATTR *ppTypeAttr,
'    CLEANLOCALSTORAGE *pDummy);
'
' HRESULT STDMETHODCALLTYPE ITypeInfo_GetFuncDesc_Proxy(
'    ITypeInfo * This,
'    DWORD index,
'    FUNCDESC **ppFuncDesc);
'
'
' HRESULT STDMETHODCALLTYPE ITypeInfo_GetFuncDesc_Stub(
'    ITypeInfo * This,
'    DWORD index,
'    LPFUNCDESC *ppFuncDesc,
'    CLEANLOCALSTORAGE *pDummy);
'
' HRESULT STDMETHODCALLTYPE ITypeInfo_GetVarDesc_Proxy(
'    ITypeInfo * This,
'    DWORD index,
'    VARDESC **ppVarDesc);
'
'
' HRESULT STDMETHODCALLTYPE ITypeInfo_GetVarDesc_Stub(
'    ITypeInfo * This,
'    DWORD index,
'    LPVARDESC *ppVarDesc,
'    CLEANLOCALSTORAGE *pDummy);
'
' HRESULT STDMETHODCALLTYPE ITypeInfo_GetNames_Proxy(
'    ITypeInfo * This,
'    MEMBERID memid,
'    BSTR *rgBstrNames,
'    DWORD cMaxNames,
'    DWORD *pcNames);
'
'
' HRESULT STDMETHODCALLTYPE ITypeInfo_GetNames_Stub(
'    ITypeInfo * This,
'    MEMBERID memid,
'    BSTR *rgBstrNames,
'    DWORD cMaxNames,
'    DWORD *pcNames);
'
' HRESULT STDMETHODCALLTYPE ITypeInfo_GetIDsOfNames_Proxy(
'    ITypeInfo * This,
'    LPOLESTR *rgszNames,
'    DWORD cNames,
'    MEMBERID *pMemId);
'
'
' HRESULT STDMETHODCALLTYPE ITypeInfo_GetIDsOfNames_Stub(
'    ITypeInfo * This);
'
' HRESULT STDMETHODCALLTYPE ITypeInfo_Invoke_Proxy(
'    ITypeInfo * This,
'    PVOID pvInstance,
'    MEMBERID memid,
'    WORD wFlags,
'    DISPPARAMS *pDispParams,
'    VARIANT *pVarResult,
'    EXCEPINFO *pExcepInfo,
'    DWORD *puArgErr);
'
'
'HRESULT STDMETHODCALLTYPE ITypeInfo_Invoke_Stub(
'    ITypeInfo * This);
'
' HRESULT STDMETHODCALLTYPE ITypeInfo_GetDocumentation_Proxy(
'    ITypeInfo * This,
'    MEMBERID memid,
'    BSTR *pBstrName,
'    BSTR *pBstrDocString,
'    DWORD *pdwHelpContext,
'    BSTR *pBstrHelpFile);
'
'
' HRESULT STDMETHODCALLTYPE ITypeInfo_GetDocumentation_Stub(
'    ITypeInfo * This,
'    MEMBERID memid,
'    DWORD refPtrFlags,
'    BSTR *pBstrName,
'    BSTR *pBstrDocString,
'    DWORD *pdwHelpContext,
'    BSTR *pBstrHelpFile);
'
' HRESULT STDMETHODCALLTYPE ITypeInfo_GetDllEntry_Proxy(
'    ITypeInfo * This,
'    MEMBERID memid,
'    INVOKEKIND invKind,
'    BSTR *pBstrDllName,
'    BSTR *pBstrName,
'    WORD *pwOrdinal);
'
'
' HRESULT STDMETHODCALLTYPE ITypeInfo_GetDllEntry_Stub(
'    ITypeInfo * This,
'    MEMBERID memid,
'    INVOKEKIND invKind,
'    DWORD refPtrFlags,
'    BSTR *pBstrDllName,
'    BSTR *pBstrName,
'    WORD *pwOrdinal);
'
' HRESULT STDMETHODCALLTYPE ITypeInfo_AddressOfMember_Proxy(
'    ITypeInfo * This,
'    MEMBERID memid,
'    INVOKEKIND invKind,
'    PVOID *ppv);
'
'
'HRESULT STDMETHODCALLTYPE ITypeInfo_AddressOfMember_Stub(
'    ITypeInfo * This);
'
' HRESULT STDMETHODCALLTYPE ITypeInfo_CreateInstance_Proxy(
'    ITypeInfo * This,
'    IUnknown *pUnkOuter,
'    REFIID riid,
'    PVOID *ppvObj);
'
'
' HRESULT STDMETHODCALLTYPE ITypeInfo_CreateInstance_Stub(
'    ITypeInfo * This,
'    REFIID riid,
'    IUnknown **ppvObj);
'
' HRESULT STDMETHODCALLTYPE ITypeInfo_GetContainingTypeLib_Proxy(
'    ITypeInfo * This,
'    ITypeLib **ppTLib,
'    DWORD *pIndex);
'
'
' HRESULT STDMETHODCALLTYPE ITypeInfo_GetContainingTypeLib_Stub(
'    ITypeInfo * This,
'    ITypeLib **ppTLib,
'    DWORD *pIndex);
'
' void STDMETHODCALLTYPE ITypeInfo_ReleaseTypeAttr_Proxy(
'    ITypeInfo * This,
'    TYPEATTR *pTypeAttr);
'
'
'HRESULT STDMETHODCALLTYPE ITypeInfo_ReleaseTypeAttr_Stub(
'    ITypeInfo * This);
'
' void STDMETHODCALLTYPE ITypeInfo_ReleaseFuncDesc_Proxy(
'    ITypeInfo * This,
'    FUNCDESC *pFuncDesc);
'
'
'HRESULT STDMETHODCALLTYPE ITypeInfo_ReleaseFuncDesc_Stub(
'    ITypeInfo * This);
'
' void STDMETHODCALLTYPE ITypeInfo_ReleaseVarDesc_Proxy(
'    ITypeInfo * This,
'    VARDESC *pVarDesc);
'
'
'HRESULT STDMETHODCALLTYPE ITypeInfo_ReleaseVarDesc_Stub(
'    ITypeInfo * This);
'
' HRESULT STDMETHODCALLTYPE ITypeInfo2_GetDocumentation2_Proxy(
'    ITypeInfo2 * This,
'    MEMBERID memid,
'    LCID lcid,
'    BSTR *pbstrHelpString,
'    DWORD *pdwHelpStringContext,
'    BSTR *pbstrHelpStringDll);
'
'
' HRESULT STDMETHODCALLTYPE ITypeInfo2_GetDocumentation2_Stub(
'    ITypeInfo2 * This,
'    MEMBERID memid,
'    LCID lcid,
'    DWORD refPtrFlags,
'    BSTR *pbstrHelpString,
'    DWORD *pdwHelpStringContext,
'    BSTR *pbstrHelpStringDll);
'
' DWORD STDMETHODCALLTYPE ITypeLib_GetTypeInfoCount_Proxy(
'    ITypeLib * This);
'
'
' HRESULT STDMETHODCALLTYPE ITypeLib_GetTypeInfoCount_Stub(
'    ITypeLib * This,
'    DWORD *pcTInfo);
'
' HRESULT STDMETHODCALLTYPE ITypeLib_GetLibAttr_Proxy(
'    ITypeLib * This,
'    TLIBATTR **ppTLibAttr);
'
'
' HRESULT STDMETHODCALLTYPE ITypeLib_GetLibAttr_Stub(
'    ITypeLib * This,
'    LPTLIBATTR *ppTLibAttr,
'    CLEANLOCALSTORAGE *pDummy);
'
' HRESULT STDMETHODCALLTYPE ITypeLib_GetDocumentation_Proxy(
'    ITypeLib * This,
'    LONG index,
'    BSTR *pBstrName,
'    BSTR *pBstrDocString,
'    DWORD *pdwHelpContext,
'    BSTR *pBstrHelpFile);
'
'
' HRESULT STDMETHODCALLTYPE ITypeLib_GetDocumentation_Stub(
'    ITypeLib * This,
'    LONG index,
'    DWORD refPtrFlags,
'    BSTR *pBstrName,
'    BSTR *pBstrDocString,
'    DWORD *pdwHelpContext,
'    BSTR *pBstrHelpFile);
'
' HRESULT STDMETHODCALLTYPE ITypeLib_IsName_Proxy(
'    ITypeLib * This,
'    LPOLESTR szNameBuf,
'    DWORD lHashVal,
'    BOOL *pfName);
'
'
' HRESULT STDMETHODCALLTYPE ITypeLib_IsName_Stub(
'    ITypeLib * This,
'    LPOLESTR szNameBuf,
'    DWORD lHashVal,
'    BOOL *pfName,
'    BSTR *pBstrLibName);
'
' HRESULT STDMETHODCALLTYPE ITypeLib_FindName_Proxy(
'    ITypeLib * This,
'    LPOLESTR szNameBuf,
'    DWORD lHashVal,
'    ITypeInfo **ppTInfo,
'    MEMBERID *rgMemId,
'    WORD *pcFound);
'
'
' HRESULT STDMETHODCALLTYPE ITypeLib_FindName_Stub(
'    ITypeLib * This,
'    LPOLESTR szNameBuf,
'    DWORD lHashVal,
'    ITypeInfo **ppTInfo,
'    MEMBERID *rgMemId,
'    WORD *pcFound,
'    BSTR *pBstrLibName);
'
' void STDMETHODCALLTYPE ITypeLib_ReleaseTLibAttr_Proxy(
'    ITypeLib * This,
'    TLIBATTR *pTLibAttr);
'
'
'HRESULT STDMETHODCALLTYPE ITypeLib_ReleaseTLibAttr_Stub(
'    ITypeLib * This);
'
' HRESULT STDMETHODCALLTYPE ITypeLib2_GetLibStatistics_Proxy(
'    ITypeLib2 * This,
'    DWORD *pcUniqueNames,
'    DWORD *pcchUniqueNames);
'
'
' HRESULT STDMETHODCALLTYPE ITypeLib2_GetLibStatistics_Stub(
'    ITypeLib2 * This,
'    DWORD *pcUniqueNames,
'    DWORD *pcchUniqueNames);
'
' HRESULT STDMETHODCALLTYPE ITypeLib2_GetDocumentation2_Proxy(
'    ITypeLib2 * This,
'    LONG index,
'    LCID lcid,
'    BSTR *pbstrHelpString,
'    DWORD *pdwHelpStringContext,
'    BSTR *pbstrHelpStringDll);
'
'
' HRESULT STDMETHODCALLTYPE ITypeLib2_GetDocumentation2_Stub(
'    ITypeLib2 * This,
'    LONG index,
'    LCID lcid,
'    DWORD refPtrFlags,
'    BSTR *pbstrHelpString,
'    DWORD *pdwHelpStringContext,
'    BSTR *pbstrHelpStringDll);
'
' HRESULT STDMETHODCALLTYPE IPropertyBag_Read_Proxy(
'    IPropertyBag * This,
'    LPCOLESTR pszPropName,
'    VARIANT *pVar,
'    IErrorLog *pErrorLog);
'
'
' HRESULT STDMETHODCALLTYPE IPropertyBag_Read_Stub(
'    IPropertyBag * This,
'    LPCOLESTR pszPropName,
'    VARIANT *pVar,
'    IErrorLog *pErrorLog,
'    DWORD varType,
'    IUnknown *pUnkObj);



' end of Additional Prototypes
