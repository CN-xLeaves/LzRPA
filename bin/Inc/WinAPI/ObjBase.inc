'------------------------------------------------------------------------------
'
'  ObjBase.inc - Component object model definitions.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from ObjBase.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "WTypes.inc"

'#include <rpc.h>
'#include <rpcndr.h>


#IF (%NTDDI_VERSION >= %NTDDI_VISTA AND NOT %DEF(%WIN32_WINNT))
%WIN32_WINNT = &H0600
#ENDIF

#IF (%NTDDI_VERSION >= %NTDDI_WS03 AND NOT %DEF(%WIN32_WINNT))
%WIN32_WINNT = &H0502
#ENDIF

#IF (%NTDDI_VERSION >= %NTDDI_WINXP AND NOT %DEF(%WIN32_WINNT))
%WIN32_WINNT = &H0501
#ENDIF

#IF (%NTDDI_VERSION >= %NTDDI_WIN2K AND NOT %DEF(%WIN32_WINNT))
%WIN32_WINNT = &H0500
#ENDIF


%OBJBASE_H = 1

'#include <pshpack8.h>

'#ifdef _MAC
'#ifndef _WLM_NOFORCE_LIBS
'
'#ifdef _WLMDLL
'        #ifdef _DEBUG
'                #pragma comment(lib, "oledlgd.lib")
'                #pragma comment(lib, "msvcoled.lib")
'        #else
'                #pragma comment(lib, "oledlg.lib")
'                #pragma comment(lib, "msvcole.lib")
'        #endif
'#else
'        #ifdef _DEBUG
'                #pragma comment(lib, "wlmoled.lib")
'                #pragma comment(lib, "ole2uid.lib")
'        #else
'                #pragma comment(lib, "wlmole.lib")
'                #pragma comment(lib, "ole2ui.lib")
'        #endif
'        #pragma data_seg(".drectve")
'        static char _gszWlmOLEUIResourceDirective[] = "/macres:ole2ui.rsc";
'        #pragma data_seg()
'#endif
'
'#pragma comment(lib, "uuid.lib")
'
'#ifdef _DEBUG
'    #pragma comment(lib, "ole2d.lib")
'    #pragma comment(lib, "ole2autd.lib")
'#else
'    #pragma comment(lib, "ole2.lib")
'    #pragma comment(lib, "ole2auto.lib")
'#endif
'
'#endif ' !_WLM_NOFORCE_LIBS
'#endif ' _MAC

'#ifdef _OLE32_
'#define WINOLEAPI        STDAPI
'#define WINOLEAPI_(type) STDAPI_(type)
'#else
'
'#ifdef _68K_
'#ifndef REQUIRESAPPLEPASCAL
'#define WINOLEAPI        EXTERN_C DECLSPEC_IMPORT HRESULT PASCAL
'#define WINOLEAPI_(type) EXTERN_C DECLSPEC_IMPORT type PASCAL
'#else
'#define WINOLEAPI        EXTERN_C DECLSPEC_IMPORT PASCAL HRESULT
'#define WINOLEAPI_(type) EXTERN_C DECLSPEC_IMPORT PASCAL type
'#endif ' REQUIRESAPPLEPASCAL
'#else
'#define WINOLEAPI        EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE
'#define WINOLEAPI_(type) EXTERN_C DECLSPEC_IMPORT type STDAPICALLTYPE
'#endif ' _68K_
'
'#endif ' _OLE32_

'****** Interface Declaration ************************************************
'
'*
'*      These are macros for declaring interfaces.  They exist so that
'*      a single definition of the interface is simulataneously a proper
'*      declaration of the interface structures (C++ abstract classes)
'*      for both C and C++.
'*
'*      DECLARE_INTERFACE(iface) is used to declare an interface that does
'*      not derive from a base interface.
'*      DECLARE_INTERFACE_(iface, baseiface) is used to declare an interface
'*      that does derive from a base interface.
'*
'*      By default if the source file has a .c extension the C version of
'*      the interface declaratations will be expanded; if it has a .cpp
'*      extension the C++ version will be expanded. if you want to force
'*      the C version expansion even though the source file has a .cpp
'*      extension, then define the macro "CINTERFACE".
'*      eg.     cl -DCINTERFACE file.cpp
'*
'*      Example Interface declaration:
'*
'*          #undef  INTERFACE
'*          #define INTERFACE   IClassFactory
'*
'*          DECLARE_INTERFACE_(IClassFactory, IUnknown)
'*          {
'*              // *** IUnknown methods ***
'*              STDMETHOD(QueryInterface) (THIS_
'*                                        REFIID riid,
'*                                        LPVOID FAR* ppvObj) PURE;
'*              STDMETHOD_(ULONG,AddRef) (THIS) PURE;
'*              STDMETHOD_(ULONG,Release) (THIS) PURE;
'*
'*              // *** IClassFactory methods ***
'*              STDMETHOD(CreateInstance) (THIS_
'*                                        LPUNKNOWN pUnkOuter,
'*                                        REFIID riid,
'*                                        LPVOID FAR* ppvObject) PURE;
'*          };
'*
'*      Example C++ expansion:
'*
'*          struct FAR IClassFactory : public IUnknown
'*          {
'*              virtual HRESULT STDMETHODCALLTYPE QueryInterface(
'*                                                  IID FAR& riid,
'*                                                  LPVOID FAR* ppvObj) = 0;
'*              virtual HRESULT STDMETHODCALLTYPE AddRef(void) = 0;
'*              virtual HRESULT STDMETHODCALLTYPE Release(void) = 0;
'*              virtual HRESULT STDMETHODCALLTYPE CreateInstance(
'*                                              LPUNKNOWN pUnkOuter,
'*                                              IID FAR& riid,
'*                                              LPVOID FAR* ppvObject) = 0;
'*          };
'*
'*          NOTE: Our documentation says '#define interface class' but we use
'*          'struct' instead of 'class' to keep a lot of 'public:' lines
'*          out of the interfaces.  The 'FAR' forces the 'this' pointers to
'*          be far, which is what we need.
'*
'*      Example C expansion:
'*
'*          typedef struct IClassFactory
'*          {
'*              const struct IClassFactoryVtbl FAR* lpVtbl;
'*          } IClassFactory;
'*
'*          typedef struct IClassFactoryVtbl IClassFactoryVtbl;
'*
'*          struct IClassFactoryVtbl
'*          {
'*              HRESULT (STDMETHODCALLTYPE * QueryInterface) (
'*                                                  IClassFactory FAR* This,
'*                                                  IID FAR* riid,
'*                                                  LPVOID FAR* ppvObj) ;
'*              HRESULT (STDMETHODCALLTYPE * AddRef) (IClassFactory FAR* This) ;
'*              HRESULT (STDMETHODCALLTYPE * Release) (IClassFactory FAR* This) ;
'*              HRESULT (STDMETHODCALLTYPE * CreateInstance) (
'*                                                  IClassFactory FAR* This,
'*                                                  LPUNKNOWN pUnkOuter,
'*                                                  IID FAR* riid,
'*                                                  LPVOID FAR* ppvObject);
'*              HRESULT (STDMETHODCALLTYPE * LockServer) (
'*                                                  IClassFactory FAR* This,
'*                                                  BOOL fLock);
'*          };
'*/

'#if defined(__cplusplus) && !defined(CINTERFACE)
'//#define interface               struct FAR
'
'#ifdef COM_STDMETHOD_CAN_THROW
'#define COM_DECLSPEC_NOTHROW
'#else
'#define COM_DECLSPEC_NOTHROW DECLSPEC_NOTHROW
'#endif
'
'#define __STRUCT__ struct
'#define interface __STRUCT__
'#define STDMETHOD(method)        virtual COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE method
'#define STDMETHOD_(type,method)  virtual COM_DECLSPEC_NOTHROW type STDMETHODCALLTYPE method
'#define STDMETHODV(method)       virtual COM_DECLSPEC_NOTHROW HRESULT STDMETHODVCALLTYPE method
'#define STDMETHODV_(type,method) virtual COM_DECLSPEC_NOTHROW type STDMETHODVCALLTYPE method
'#define PURE                    = 0
'#define THIS_
'#define THIS                    void
'#define DECLARE_INTERFACE(iface)                        interface DECLSPEC_NOVTABLE iface
'#define DECLARE_INTERFACE_(iface, baseiface)            interface DECLSPEC_NOVTABLE iface : public baseiface
'#define DECLARE_INTERFACE_IID(iface, iid)               interface DECLSPEC_UUID(iid) DECLSPEC_NOVTABLE iface
'#define DECLARE_INTERFACE_IID_(iface, baseiface, iid)   interface DECLSPEC_UUID(iid) DECLSPEC_NOVTABLE iface : public baseiface
'
'#define IFACEMETHOD(method)         __override STDMETHOD(method)
'#define IFACEMETHOD_(type,method)   __override STDMETHOD_(type,method)
'#define IFACEMETHODV(method)        __override STDMETHODV(method)
'#define IFACEMETHODV_(type,method)  __override STDMETHODV_(type,method)
'
'#if !defined(BEGIN_INTERFACE)
'#if defined(_MPPC_)  && \
'    ( (defined(_MSC_VER) || defined(__SC__) || defined(__MWERKS__)) && \
'    !defined(NO_NULL_VTABLE_ENTRY) )
'   #define BEGIN_INTERFACE virtual void a() {}
'   #define END_INTERFACE
'#else
'   #define BEGIN_INTERFACE
'   #define END_INTERFACE
'#endif ' _MPPC_
'#endif ' BEGIN_INTERFACE
'
'//  IID_PPV_ARGS(ppType)
'//      ppType is the variable of type IType that will be filled
'//
'//      RESULTS in:  IID_IType, ppvType
'//      will create a compiler error if wrong level of indirection is used.
'//
'extern "C++"
'{
'    template<typename T> void** IID_PPV_ARGS_Helper(T** pp)
'    {
'        static_cast<IUnknown*>(*pp);    // make sure everyone derives from IUnknown
'        return reinterpret_cast<void**>(pp);
'    }
'}
'
'#define IID_PPV_ARGS(ppType) __uuidof(**(ppType)), IID_PPV_ARGS_Helper(ppType)
'
'#else ' __cplusplus
'
'#define interface               struct
'
'#define STDMETHOD(method)       HRESULT (STDMETHODCALLTYPE * method)
'#define STDMETHOD_(type,method) type (STDMETHODCALLTYPE * method)
'#define STDMETHODV(method)       HRESULT (STDMETHODVCALLTYPE * method)
'#define STDMETHODV_(type,method) type (STDMETHODVCALLTYPE * method)
'
'#define IFACEMETHOD(method)         __override STDMETHOD(method)
'#define IFACEMETHOD_(type,method)   __override STDMETHOD_(type,method)
'#define IFACEMETHODV(method)        __override STDMETHODV(method)
'#define IFACEMETHODV_(type,method)  __override STDMETHODV_(type,method)
'
'#if !defined(BEGIN_INTERFACE)
'#if defined(_MPPC_)
'    #define BEGIN_INTERFACE       void    *b;
'    #define END_INTERFACE
'#else
'    #define BEGIN_INTERFACE
'    #define END_INTERFACE
'#endif ' _MPPC_
'#endif ' BEGIN_INTERFACE
'
'
'#define PURE
'#define THIS_                   INTERFACE FAR* This,
'#define THIS                    INTERFACE FAR* This
'#ifdef CONST_VTABLE
'#undef CONST_VTBL
'#define CONST_VTBL const
'#define DECLARE_INTERFACE(iface)    typedef interface iface { \
'                                    const struct iface##Vtbl FAR* lpVtbl; \
'                                } iface; \
'                                typedef const struct iface##Vtbl iface##Vtbl; \
'                                const struct iface##Vtbl
'#else
'#undef CONST_VTBL
'#define CONST_VTBL
'#define DECLARE_INTERFACE(iface)    typedef interface iface { \
'                                    struct iface##Vtbl FAR* lpVtbl; \
'                                } iface; \
'                                typedef struct iface##Vtbl iface##Vtbl; \
'                                struct iface##Vtbl
'#endif ' CONST_VTABLE
'#define DECLARE_INTERFACE_(iface, baseiface)    DECLARE_INTERFACE(iface)
'#define DECLARE_INTERFACE_IID(iface, iid)               DECLARE_INTERFACE(iface)
'#define DECLARE_INTERFACE_IID_(iface, baseiface, iid)   DECLARE_INTERFACE_(iface, baseiface)
'#endif ' __cplusplus




'****** Additional basic types ***********************************************


'#ifndef FARSTRUCT
'#ifdef __cplusplus
'#define FARSTRUCT   FAR
'#else
'#define FARSTRUCT
'#endif  // __cplusplus
'#endif  // FARSTRUCT



'#ifndef HUGEP
'#if defined(_WIN32) || defined(_MPPC_)
'#define HUGEP
'#else
'#define HUGEP __huge
'#endif // WIN32
'#endif // HUGEP


'#ifdef _MAC
'#if !defined(OLE2ANSI)
'#define OLE2ANSI
'#endif
'#endif

'#include <stdlib.h>

MACRO LISet32(li, v)
    li.HighPart = ((v) < 0)
    li.LowPart = v
END MACRO

MACRO ULISet32(li, v)
    li.HighPart = 0
    li.LowPart = v
END MACRO




%CLSCTX_INPROC  = (%CLSCTX_INPROC_SERVER OR %CLSCTX_INPROC_HANDLER)

' With DCOM, CLSCTX_REMOTE_SERVER should be included
#IF (%WIN32_WINNT >= &H0400) OR %DEF(%WIN32_DCOM) ' DCOM
%CLSCTX_ALL     = (%CLSCTX_INPROC_SERVER OR _
                   %CLSCTX_INPROC_HANDLER OR _
                   %CLSCTX_LOCAL_SERVER OR _
                   %CLSCTX_REMOTE_SERVER)

%CLSCTX_SERVER  = (%CLSCTX_INPROC_SERVER OR _
                   %CLSCTX_LOCAL_SERVER OR _
                   %CLSCTX_REMOTE_SERVER)
#ELSE
%CLSCTX_ALL     = (%CLSCTX_INPROC_SERVER OR _
                   %CLSCTX_INPROC_HANDLER OR _
                   %CLSCTX_LOCAL_SERVER )

%CLSCTX_SERVER  = (%CLSCTX_INPROC_SERVER OR %CLSCTX_LOCAL_SERVER)
#ENDIF


' class registration flags; passed to CoRegisterClassObject
MACRO REGCLS_enum=DWORD
ENUM REGCLS SINGULAR BITS
    REGCLS_SINGLEUSE        ' class object only generates one instance
    REGCLS_MULTIPLEUSE      ' same class object genereates multiple inst.
                            ' and local automatically goes into inproc tbl.
    REGCLS_MULTI_SEPARATE   ' multiple use, but separate control over each
                            ' context.
    REGCLS_SUSPENDED        ' register is as suspended, will be activated
                            ' when app calls CoResumeClassObjects
    REGCLS_SURROGATE        ' must be used when a surrogate process
                            ' is registering a class object that will be
                            ' loaded in the surrogate
END ENUM

' interface marshaling definitions
%MARSHALINTERFACE_MIN = 500 ' minimum number of bytes for interface marshl


'
' Common typedefs for paramaters used in Storage APIs, gleaned from storage.h
' Also contains Storage error codes, which should be moved into the storage
' idl files.
'


%CWCSTORAGENAME = 32

' Storage instantiation modes
%STGM_DIRECT           = &H00000000
%STGM_TRANSACTED       = &H00010000
%STGM_SIMPLE           = &H08000000

%STGM_READ             = &H00000000
%STGM_WRITE            = &H00000001
%STGM_READWRITE        = &H00000002

%STGM_SHARE_DENY_NONE  = &H00000040
%STGM_SHARE_DENY_READ  = &H00000030
%STGM_SHARE_DENY_WRITE = &H00000020
%STGM_SHARE_EXCLUSIVE  = &H00000010

%STGM_PRIORITY         = &H00040000
%STGM_DELETEONRELEASE  = &H04000000
'#if (%WINVER >= 400)   [obvious typo]
#IF (%WINVER >= &H0400)
%STGM_NOSCRATCH        = &H00100000
#ENDIF ' %WINVER

%STGM_CREATE           = &H00001000
%STGM_CONVERT          = &H00020000
%STGM_FAILIFTHERE      = &H00000000

%STGM_NOSNAPSHOT       = &H00200000
#IF (%WIN32_WINNT >= &H0500)
%STGM_DIRECT_SWMR      = &H00400000
#ENDIF

'  flags for internet asyncronous and layout docfile
%ASYNC_MODE_COMPATIBILITY  = &H00000001
%ASYNC_MODE_DEFAULT        = &H00000000

%STGTY_REPEAT              = &H00000100
%STG_TOEND                 = &HFFFFFFFF???

%STG_LAYOUT_SEQUENTIAL     = &H00000000
%STG_LAYOUT_INTERLEAVED    = &H00000001

MACRO STGFMT=DWORD

%STGFMT_STORAGE        = 0
%STGFMT_NATIVE         = 1
%STGFMT_FILE           = 3
%STGFMT_ANY            = 4
%STGFMT_DOCFILE        = 5

' This is a legacy define to allow old component to builds
%STGFMT_DOCUMENT       = 0

'/* here is where we pull in the MIDL generated headers for the interfaces */
'typedef interface    IRpcStubBuffer     IRpcStubBuffer;
'typedef interface    IRpcChannelBuffer  IRpcChannelBuffer;

#INCLUDE "WTypes.inc"
#INCLUDE "Unknwn.inc"
#INCLUDE "ObjIdl.inc"

'#ifdef _OLE32_
'#ifdef _OLE32PRIV_
'BOOL _fastcall wIsEqualGUID(REFGUID rguid1, REFGUID rguid2);
'#define IsEqualGUID(rguid1, rguid2) wIsEqualGUID(rguid1, rguid2)
'#else
'#define __INLINE_ISEQUAL_GUID
'#endif  // _OLE32PRIV_
'#endif  // _OLE32_

'#include "guiddef.inc"

'#if not %def(%INITGUID)
'#include "cguid.inc"
'#endif

' COM initialization flags; passed to CoInitialize.
MACRO COINIT_enum=DWORD
ENUM COINIT SINGULAR
    COINIT_APARTMENTTHREADED  = &H2       ' Apartment model

#IF (%WIN32_WINNT >= &H0400 ) OR %DEF(%WIN32_DCOM) ' DCOM
    ' These constants are only valid on Windows NT 4.0
    COINIT_MULTITHREADED      = &H0       ' OLE calls objects on any thread.
    COINIT_DISABLE_OLE1DDE    = &H4       ' Don't use DDE for Ole1 support.
    COINIT_SPEED_OVER_MEMORY  = &H8       ' Trade memory for speed.
#ENDIF ' DCOM
END ENUM





'***** STD Object API Prototypes ******************************************

DECLARE FUNCTION CoBuildVersion LIB "Ole32.dll" ALIAS "CoBuildVersion" () _
    AS DWORD

' init/uninit

DECLARE FUNCTION CoInitialize LIB "Ole32.dll" ALIAS "CoInitialize" ( _
    pvReserved AS ANY _  ' LPVOID
    ) AS LONG

DECLARE SUB CoUninitialize LIB "Ole32.dll" ALIAS "CoUninitialize" ()

DECLARE FUNCTION CoGetMalloc LIB "Ole32.dll" ALIAS "CoGetMalloc" ( _
    BYVAL dwMemContext AS DWORD, _
    ppMalloc           AS ANY _  ' LPMALLOC FAR*
    ) AS LONG

DECLARE FUNCTION CoGetCurrentProcess LIB "Ole32.dll" _
    ALIAS "CoGetCurrentProcess" () AS DWORD

DECLARE FUNCTION CoRegisterMallocSpy LIB "Ole32.dll" _
    ALIAS "CoRegisterMallocSpy" ( _
    pMallocSpy AS ANY _  ' LPMALLOCSPY
    ) AS LONG

DECLARE FUNCTION CoRevokeMallocSpy LIB "Ole32.dll" _
    ALIAS "CoRevokeMallocSpy" () AS LONG

DECLARE FUNCTION CoCreateStandardMalloc LIB "Ole32.dll" _
    ALIAS "CoCreateStandardMalloc" ( _
    BYVAL memctx AS DWORD, _
    ppMalloc     AS ANY _  ' IMalloc FAR* FAR*
    ) AS LONG

#IF (%WIN32_WINNT >= &H0400) OR %DEF(%WIN32_DCOM) ' DCOM

DECLARE FUNCTION CoInitializeEx LIB "Ole32.dll" ALIAS "CoInitializeEx" ( _
    pvReserved     AS ANY, _  ' LPVOID
    BYVAL dwCoInit AS DWORD _
    ) AS LONG


DECLARE FUNCTION CoGetCallerTID LIB "Ole32.dll" ALIAS "CoGetCallerTID" ( _
    lpdwTID AS DWORD) AS LONG


DECLARE FUNCTION CoGetCurrentLogicalThreadId LIB "Ole32.dll" _
    ALIAS "CoGetCurrentLogicalThreadId" ( _
    pguid AS GUID _
    ) AS LONG
#ENDIF ' DCOM

#IF (%WIN32_WINNT >= &H0501)

DECLARE FUNCTION CoRegisterInitializeSpy  LIB "Ole32.dll" _
    ALIAS "CoRegisterInitializeSpy" ( _
    pSpy       AS ANY, _  ' LPINITIALIZESPY
    puliCookie AS QUAD _  ' ULARGE_INTEGER
    ) AS LONG

DECLARE FUNCTION CoRevokeInitializeSpy LIB "Ole32.dll" _
    ALIAS "CoRevokeInitializeSpy" ( _
    BYVAL uliCookie AS QUAD _  ' ULARGE_INTEGER
    ) AS LONG

DECLARE FUNCTION CoGetContextToken LIB "Ole32.dll" _
    ALIAS "CoGetContextToken" ( _
    pToken AS DWORD _
    ) AS LONG

' COM System Security Descriptors (used when the corresponding registry
' entries are absent)
MACRO COMSD_enum=LONG
ENUM COMSD SINGULAR
    SD_LAUNCHPERMISSIONS     ' Machine wide launch permissions
    SD_ACCESSPERMISSIONS     ' Machine wide acesss permissions
    SD_LAUNCHRESTRICTIONS    ' Machine wide launch limits
    SD_ACCESSRESTRICTIONS    ' Machine wide access limits
END ENUM

DECLARE FUNCTION CoGetSystemSecurityPermissions LIB "Ole32.dll" _
    ALIAS "CoGetSystemSecurityPermissions" ( _
    BYVAL comSDType AS COMSD_enum, _
    ppSD            AS ANY _  ' PSECURITY_DESCRIPTOR *
    ) AS LONG

#ENDIF

' definition for Win7 new APIs
' [NT_TARGET_VERSION_WIN7 is never defined. assuming intended test...]
'#if (%WIN32_WINNT >= %NT_TARGET_VERSION_WIN7)
#IF (%WIN32_WINNT >= %WIN32_WINNT_WIN7)

DECLARE FUNCTION CoGetApartmentType LIB "Ole32.dll" _
    ALIAS "CoGetApartmentType" ( _
    pAptType      AS APTTYPE_enum, _
    pAptQualifier AS APTTYPEQUALIFIER_enum _
    ) AS LONG

#ENDIF

'#if %DBG = 1   ' [DBG doesn't seem to be defined anywhere]
#IF %DEF(%DBG)
DECLARE FUNCTION DebugCoGetRpcFault LIB "Ole32.dll" _
    ALIAS "DebugCoGetRpcFault" () AS DWORD
DECLARE SUB DebugCoSetRpcFault LIB "Ole32.dll" ALIAS "DebugCoSetRpcFault" ( _
    BYVAL DWORD)
#ENDIF

#IF (%WIN32_WINNT >= &H0500)

TYPE SOleTlsDataPublic
    pvReserved0(1) AS DWORD  ' void *
    dwReserved0(2) AS DWORD
    pvReserved1(0) AS DWORD  ' void *
    dwReserved1(2) AS DWORD
    pvReserved2(3) AS DWORD  ' void *
    dwReserved2(0) AS DWORD
    pCurrentCtx    AS DWORD  ' void *
END TYPE

#ENDIF

' COM+ APIs

DECLARE FUNCTION CoGetObjectContext LIB "Ole32.dll" _
    ALIAS "CoGetObjectContext" ( _
    riid AS GUID, _  ' REFIID
    ppv  AS ANY _  ' LPVOID FAR*
    ) AS LONG

' register/revoke/get class objects

DECLARE FUNCTION CoGetClassObject LIB "Ole32.dll" _
    ALIAS "CoGetClassObject" ( _
    rclsid             AS GUID, _  ' REFCLSID
    BYVAL dwClsContext AS DWORD, _
    pvReserved         AS ANY, _  ' LPVOID
    riid               AS GUID, _  ' REFIID
    ppv                AS ANY _  ' LPVOID FAR*
    ) AS LONG

DECLARE FUNCTION CoRegisterClassObject LIB "Ole32.dll" _
    ALIAS "CoRegisterClassObject" ( _
    rclsid             AS GUID, _  ' REFCLSID
    pUnk               AS ANY, _  ' LPUNKNOWN
    BYVAL dwClsContext AS DWORD, _
    BYVAL flags        AS DWORD, _
    lpdwRegister       AS DWORD _
    ) AS LONG

DECLARE FUNCTION CoRevokeClassObject LIB "Ole32.dll" _
    ALIAS "CoRevokeClassObject" ( _
    BYVAL dwRegister AS DWORD _
    ) AS LONG

DECLARE FUNCTION CoResumeClassObjects LIB "Ole32.dll" _
    ALIAS "CoResumeClassObjects" () AS LONG

DECLARE FUNCTION CoSuspendClassObjects LIB "Ole32.dll" _
    ALIAS "CoSuspendClassObjects" () AS LONG

DECLARE FUNCTION CoAddRefServerProcess LIB "Ole32.dll" _
    ALIAS "CoAddRefServerProcess" () AS DWORD

DECLARE FUNCTION CoReleaseServerProcess LIB "Ole32.dll" _
    ALIAS "CoReleaseServerProcess" () AS DWORD

DECLARE FUNCTION CoGetPSClsid LIB "Ole32.dll" _
    ALIAS "CoGetPSClsid" ( _
    riid   AS GUID, _  ' REFIID
    pClsid AS ANY _    ' CLSID *
    ) AS LONG

DECLARE FUNCTION CoRegisterPSClsid LIB "Ole32.dll" _
    ALIAS "CoRegisterPSClsid" ( _
    riid   AS GUID, _  ' REFIID
    rclsid AS GUID _   ' REFCLSID
    ) AS LONG

' Registering surrogate processes
DECLARE FUNCTION CoRegisterSurrogate LIB "Ole32.dll" _
    ALIAS "CoRegisterSurrogate" ( _
    pSurrogate AS ANY _  ' LPSURROGATE
    ) AS LONG

' marshaling interface pointers

DECLARE FUNCTION CoGetMarshalSizeMax LIB "Ole32.dll" _
    ALIAS "CoGetMarshalSizeMax" ( _
    pulSize             AS DWORD, _
    riid                AS GUID, _  ' REFIID
    pUnk                AS ANY, _   ' LPUNKNOWN
    BYVAL dwDestContext AS DWORD, _
    pvDestContext       AS ANY, _   ' LPVOID
    BYVAL mshlflags     AS DWORD _
    ) AS LONG

DECLARE FUNCTION CoMarshalInterface LIB "Ole32.dll" _
    ALIAS "CoMarshalInterface" ( _
    pStm                AS ANY, _   ' LPSTREAM
    riid                AS GUID, _  ' REFIID
    pUnk                AS ANY, _   ' LPUNKNOWN
    BYVAL dwDestContext AS DWORD, _
    pvDestContext       AS ANY, _   ' LPVOID
    BYVAL mshlflags     AS DWORD _
    ) AS LONG

DECLARE FUNCTION CoUnmarshalInterface LIB "Ole32.dll" _
    ALIAS "CoUnmarshalInterface" ( _
    pStm AS ANY, _   ' LPSTREAM
    riid AS GUID, _  ' REFIID
    ppv  AS ANY _    ' LPVOID FAR*
    ) AS LONG

DECLARE FUNCTION CoMarshalHresult LIB "Ole32.dll" _
    ALIAS "CoMarshalHresult" ( _
    pStm          AS ANY, _  ' LPSTREAM
    BYVAL hresult AS LONG _  ' HRESULT
    ) AS LONG

DECLARE FUNCTION CoUnmarshalHresult LIB "Ole32.dll" _
    ALIAS "CoUnmarshalHresult" ( _
    pStm     AS ANY, _  ' LPSTREAM
    phresult AS LONG _  ' HRESULT FAR *
    ) AS LONG

DECLARE FUNCTION CoReleaseMarshalData LIB "Ole32.dll" _
    ALIAS "CoReleaseMarshalData" ( _
    pStm AS ANY _  ' LPSTREAM
    ) AS LONG

DECLARE FUNCTION CoDisconnectObject LIB "Ole32.dll" _
    ALIAS "CoDisconnectObject" ( _
    pUnk             AS ANY, _  ' LPUNKNOWN
    BYVAL dwReserved AS DWORD _
    ) AS LONG

DECLARE FUNCTION CoLockObjectExternal LIB "Ole32.dll" _
    ALIAS "CoLockObjectExternal" ( _
    pUnk                      AS ANY, _  ' LPUNKNOWN
    BYVAL fLock               AS LONG, _  ' BOOL
    BYVAL fLastUnlockReleases AS LONG _  ' BOOL
    ) AS LONG

DECLARE FUNCTION CoGetStandardMarshal LIB "Ole32.dll" _
    ALIAS "CoGetStandardMarshal" ( _
    riid                AS GUID, _  ' REFIID
    pUnk                AS ANY, _   ' LPUNKNOWN
    BYVAL dwDestContext AS DWORD, _
    pvDestContext       AS ANY, _   ' LPVOID
    BYVAL mshlflags     AS DWORD, _
    ppMarshal           AS ANY _    ' LPMARSHAL FAR*
    ) AS LONG

DECLARE FUNCTION CoGetStdMarshalEx LIB "Ole32.dll" _
    ALIAS "CoGetStdMarshalEx" ( _
    pUnkOuter       AS ANY, _  ' LPUNKNOWN
    BYVAL smexflags AS DWORD, _
    ppUnkInner      AS ANY _   ' LPUNKNOWN FAR*
    ) AS LONG

' flags for CoGetStdMarshalEx
MACRO STDMSHLFLAGS_enum=DWORD
ENUM STDMSHLFLAGS SINGULAR
    SMEXF_SERVER   = &H01   ' server side aggregated std marshaler
    SMEXF_HANDLER           ' client side (handler) agg std marshaler
END ENUM


DECLARE FUNCTION CoIsHandlerConnected LIB "Ole32.dll" _
    ALIAS "CoIsHandlerConnected" ( _
    pUnk AS ANY _  ' LPUNKNOWN
    ) AS LONG  ' BOOL

' Apartment model inter-thread interface passing helpers
DECLARE FUNCTION CoMarshalInterThreadInterfaceInStream LIB "Ole32.dll" _
    ALIAS "CoMarshalInterThreadInterfaceInStream" ( _
    riid  AS GUID, _  ' REFIID
    pUnk  AS ANY, _   ' LPUNKNOWN
    ppStm AS ANY _    ' LPSTREAM *
    ) AS LONG

DECLARE FUNCTION CoGetInterfaceAndReleaseStream LIB "Ole32.dll" _
    ALIAS "CoGetInterfaceAndReleaseStream" ( _
    pStm AS ANY, _   ' LPSTREAM
    iid  AS GUID, _  ' REFIID
    ppv  AS ANY _    ' LPVOID FAR*
    ) AS LONG

DECLARE FUNCTION CoCreateFreeThreadedMarshaler LIB "Ole32.dll" _
    ALIAS "CoCreateFreeThreadedMarshaler" ( _
    punkOuter    AS ANY, _  ' LPUNKNOWN
    ppunkMarshal AS ANY _   ' LPUNKNOWN *
    ) AS LONG

' dll loading helpers; keeps track of ref counts and unloads all on exit

DECLARE FUNCTION CoLoadLibrary LIB "Ole32.dll" ALIAS "CoLoadLibrary" ( _
    lpszLibName     AS WSTRINGZ, _
    BYVAL bAutoFree AS LONG _  ' BOOL
    ) AS DWORD  ' HINSTANCE

DECLARE SUB CoFreeLibrary LIB "Ole32.dll" ALIAS "CoFreeLibrary" ( _
    BYVAL hInst AS DWORD _  ' HINSTANCE
    )

DECLARE SUB CoFreeAllLibraries LIB "Ole32.dll" ALIAS "CoFreeAllLibraries" ()

DECLARE SUB CoFreeUnusedLibraries LIB "Ole32.dll" _
    ALIAS "CoFreeUnusedLibraries" ()

#IF (%WIN32_WINNT >= &H0501)

DECLARE SUB CoFreeUnusedLibrariesEx LIB "Ole32.dll" _
    ALIAS "CoFreeUnusedLibrariesEx" ( _
    BYVAL dwUnloadDelay AS DWORD, _
    BYVAL dwReserved    AS DWORD)
#ENDIF

#IF (%WIN32_WINNT >= &H0600)
DECLARE FUNCTION CoDisconnectContext LIB "Ole32.dll" _
    ALIAS "CoDisconnectContext" (BYVAL dwTimeout AS DWORD) AS LONG
#ENDIF

#IF (%WIN32_WINNT >= &H0400 ) OR %DEF(%WIN32_DCOM) ' DCOM

' Call Security.


DECLARE FUNCTION CoInitializeSecurity LIB "Ole32.dll" _
    ALIAS "CoInitializeSecurity" ( _
    pSecDesc             AS SECURITY_DESCRIPTOR, _
    BYVAL cAuthSvc       AS LONG, _
    asAuthSvc            AS SOLE_AUTHENTICATION_SERVICE, _
    pReserved1           AS ANY, _  ' void *
    BYVAL dwAuthnLevel   AS DWORD, _
    BYVAL dwImpLevel     AS DWORD, _
    pAuthList            AS ANY, _  ' void *
    BYVAL dwCapabilities AS DWORD, _
    pReserved3           AS ANY _   ' void *
    ) AS LONG


DECLARE FUNCTION CoGetCallContext LIB "Ole32.dll" _
    ALIAS "CoGetCallContext" ( _
    riid        AS GUID, _  ' REFIID
    ppInterface AS ANY _    ' void **
    ) AS LONG


DECLARE FUNCTION CoQueryProxyBlanket LIB "Ole32.dll" _
    ALIAS "CoQueryProxyBlanket" ( _
    pProxy           AS ANY, _  ' IUnknown PTR
    pwAuthnSvc       AS DWORD, _
    pAuthzSvc        AS DWORD, _
    pServerPrincName AS ANY, _  ' OLECHAR **
    pAuthnLevel      AS DWORD, _
    pImpLevel        AS DWORD, _
    pAuthInfo        AS ANY, _  ' RPC_AUTH_IDENTITY_HANDLE
    pCapabilites     AS DWORD _
    ) AS LONG


DECLARE FUNCTION CoSetProxyBlanket LIB "Ole32.dll" _
    ALIAS "CoSetProxyBlanket" ( _
    pProxy               AS ANY, _  ' IUnknown PTR
    BYVAL dwAuthnSvc     AS DWORD, _
    BYVAL dwAuthzSvc     AS DWORD, _
    pServerPrincName     AS WSTRINGZ, _
    BYVAL dwAuthnLevel   AS DWORD, _
    BYVAL dwImpLevel     AS DWORD, _
    pAuthInfo            AS ANY, _  ' RPC_AUTH_IDENTITY_HANDLE
    BYVAL dwCapabilities AS DWORD _
    ) AS LONG


DECLARE FUNCTION CoCopyProxy LIB "Ole32.dll" ALIAS "CoCopyProxy" ( _
    pProxy AS ANY, _  ' IUnknown PTR
    ppCopy AS ANY _   ' IUnknown PTR PTR
    ) AS LONG


DECLARE FUNCTION CoQueryClientBlanket LIB "Ole32.dll" _
    ALIAS "CoQueryClientBlanket" ( _
    pAuthnSvc        AS DWORD, _
    pAuthzSvc        AS DWORD, _
    pServerPrincName AS ANY, _  ' OLECHAR **, _
    pAuthnLevel      AS DWORD, _
    pImpLevel        AS DWORD, _
    pPrivs           AS ANY, _  ' RPC_AUTHZ_HANDLE
    pCapabilities    AS DWORD _
    ) AS LONG


DECLARE FUNCTION CoImpersonateClient LIB "Ole32.dll" _
    ALIAS "CoImpersonateClient" () AS LONG


DECLARE FUNCTION CoRevertToSelf LIB "Ole32.dll" ALIAS "CoRevertToSelf" () _
    AS LONG


DECLARE FUNCTION CoQueryAuthenticationServices LIB "Ole32.dll" _
    ALIAS "CoQueryAuthenticationServices" ( _
    pcAuthSvc AS DWORD, _
    asAuthSvc AS ANY _  ' SOLE_AUTHENTICATION_SERVICE **
    ) AS LONG


DECLARE FUNCTION CoSwitchCallContext LIB "Ole32.dll" _
    ALIAS "CoSwitchCallContext" ( _
    pNewObject  AS ANY, _  ' IUnknown PTR
    ppOldObject AS ANY _   ' IUnknown PTR PTR
    ) AS LONG

%COM_RIGHTS_EXECUTE         =  1
%COM_RIGHTS_EXECUTE_LOCAL   =  2
%COM_RIGHTS_EXECUTE_REMOTE  =  4
%COM_RIGHTS_ACTIVATE_LOCAL  =  8
%COM_RIGHTS_ACTIVATE_REMOTE = 16



#ENDIF ' DCOM

' helper for creating instances

DECLARE FUNCTION CoCreateInstance LIB "Ole32.dll" _
    ALIAS "CoCreateInstance" ( _
    rclsid             AS GUID, _  ' REFCLSID
    pUnkOuter          AS ANY, _   ' LPUNKNOWN
    BYVAL dwClsContext AS DWORD, _
    riid               AS GUID, _  ' REFIID
    ppv                AS ANY _    ' FAR* LPVOID
    ) AS LONG


#IF (%WIN32_WINNT >= &H0400 ) OR %DEF(%WIN32_DCOM) ' DCOM


DECLARE FUNCTION CoGetInstanceFromFile LIB "Ole32.dll" _
    ALIAS "CoGetInstanceFromFile" ( _
    pServerInfo    AS COSERVERINFO, _
    pClsid         AS GUID, _     ' CLSID
    punkOuter      AS ANY, _      ' IUnknown PTR ' only relevant locally _
    BYVAL dwClsCtx AS DWORD, _
    BYVAL grfMode  AS DWORD, _
    pwszName       AS WSTRINGZ, _ ' OLECHAR *
    BYVAL dwCount  AS DWORD, _
    pResults       AS MULTI_QI  _
    ) AS LONG


DECLARE FUNCTION CoGetInstanceFromIStorage LIB "Ole32.dll" _
    ALIAS "CoGetInstanceFromIStorage" ( _
    pServerInfo    AS COSERVERINFO, _
    pClsid         AS GUID, _  ' CLSID
    punkOuter      AS ANY, _   ' IUnknown PTR ' only relevant locally
    BYVAL dwClsCtx AS DWORD, _
    pstg           AS ANY, _   ' IStorage *
    BYVAL dwCount  AS DWORD, _
    pResults       AS MULTI_QI _
    ) AS LONG


DECLARE FUNCTION CoCreateInstanceEx LIB "Ole32.dll" _
    ALIAS "CoCreateInstanceEx" ( _
    Clsid          AS GUID, _  ' REFCLSID
    punkOuter      AS ANY, _  ' IUnknown PTR ' only relevant locally _
    BYVAL dwClsCtx AS DWORD, _
    pServerInfo    AS COSERVERINFO, _
    BYVAL dwCount  AS DWORD, _
    pResults       AS MULTI_QI _
    ) AS LONG

#ENDIF ' DCOM

' Call related APIs
#IF (%WIN32_WINNT >= &H0500 ) OR %DEF(%WIN32_DCOM) ' DCOM


DECLARE FUNCTION CoGetCancelObject LIB "Ole32.dll" _
    ALIAS "CoGetCancelObject" ( _
    BYVAL dwThreadId AS DWORD, _
    iid              AS GUID, _  ' REFIID
    ppUnk            AS ANY _    ' void **
    ) AS LONG


DECLARE FUNCTION CoSetCancelObject LIB "Ole32.dll" _
    ALIAS "CoSetCancelObject" ( _
    pUnk AS ANY _  ' IUnknown PTR
    ) AS LONG


DECLARE FUNCTION CoCancelCall LIB "Ole32.dll" _
    ALIAS "CoCancelCall" ( _
    BYVAL dwThreadId AS DWORD, _
    BYVAL ulTimeout  AS DWORD  _
    ) AS LONG


DECLARE FUNCTION CoTestCancel LIB "Ole32.dll" ALIAS "CoTestCancel" () AS LONG


DECLARE FUNCTION CoEnableCallCancellation LIB "Ole32.dll" _
    ALIAS "CoEnableCallCancellation" ( _
    pReserved AS ANY _  ' LPVOID
    ) AS LONG


DECLARE FUNCTION CoDisableCallCancellation LIB "Ole32.dll" _
    ALIAS "CoDisableCallCancellation" ( _
    pReserved AS ANY _  ' LPVOID
    ) AS LONG


DECLARE FUNCTION CoAllowSetForegroundWindow LIB "Ole32.dll" _
    ALIAS "CoAllowSetForegroundWindow" ( _
    pUnk        AS ANY, _  ' IUnknown PTR
    lpvReserved AS ANY _   ' LPVOID
    ) AS LONG


DECLARE FUNCTION DcomChannelSetHResult LIB "Ole32.dll" _
    ALIAS "DcomChannelSetHResult" ( _
    pvReserved   AS ANY, _  ' LPVOID
    pulReserved  AS DWORD, _
    BYVAL appsHR AS LONG _  ' HRESULT
    ) AS LONG

#ENDIF

' other helpers

DECLARE FUNCTION StringFromCLSID LIB "Ole32.dll" ALIAS "StringFromCLSID" ( _
    rclsid AS GUID, _  ' REFCLSID
    lplpsz AS WSTRINGZ _
    ) AS LONG

DECLARE FUNCTION CLSIDFromString LIB "Ole32.dll" ALIAS "CLSIDFromString" ( _
    lpsz   AS WSTRINGZ, _
    pclsid AS GUID _  ' LPCLSID
    ) AS LONG

DECLARE FUNCTION StringFromIID LIB "Ole32.dll" ALIAS "StringFromIID" ( _
    rclsid AS GUID, _  ' REFIID
    lplpsz AS WSTRINGZ _
    ) AS LONG

DECLARE FUNCTION IIDFromString LIB "Ole32.dll" ALIAS "IIDFromString" ( _
    lpsz  AS WSTRINGZ, _
    lpiid AS GUID _
    ) AS LONG

DECLARE FUNCTION CoIsOle1Class LIB "Ole32.dll" ALIAS "CoIsOle1Class" ( _
    rclsid AS GUID _  ' REFCLSID
    ) AS LONG  ' BOOL

DECLARE FUNCTION ProgIDFromCLSID LIB "Ole32.dll" ALIAS "ProgIDFromCLSID" ( _
    clsid        AS GUID, _  ' REFCLSID
    lplpszProgID AS WSTRINGZ _
    ) AS LONG

DECLARE FUNCTION CLSIDFromProgID LIB "Ole32.dll" ALIAS "CLSIDFromProgID" ( _
    lpszProgID AS WSTRINGZ, _
    lpclsid    AS GUID _  ' LPCLSID _
    ) AS LONG

DECLARE FUNCTION CLSIDFromProgIDEx LIB "Ole32.dll" _
    ALIAS "CLSIDFromProgIDEx" ( _
    lpszProgID AS WSTRINGZ, _
    lpclsid    AS GUID _  ' LPCLSID
    ) AS LONG

DECLARE FUNCTION StringFromGUID2 LIB "Ole32.dll" ALIAS "StringFromGUID2" ( _
    rguid        AS GUID, _  ' REFGUID
    lpsz         AS WSTRINGZ, _
    BYVAL cchMax AS LONG _
    ) AS LONG

DECLARE FUNCTION CoCreateGuid LIB "Ole32.dll" ALIAS "CoCreateGuid" ( _
    pguid AS GUID _
    ) AS LONG

DECLARE FUNCTION CoFileTimeToDosDateTime LIB "Ole32.dll" _
    ALIAS "CoFileTimeToDosDateTime" ( _
    lpFileTime AS FILETIME, _
    lpDosDate  AS WORD, _
    lpDosTime  AS WORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION CoDosDateTimeToFileTime LIB "Ole32.dll" _
    ALIAS "CoDosDateTimeToFileTime" ( _
    BYVAL nDosDate AS WORD, _
    BYVAL nDosTime AS WORD, _
    lpFileTime     AS FILETIME _
    ) AS LONG  ' BOOL

DECLARE FUNCTION CoFileTimeNow LIB "Ole32.dll" ALIAS "CoFileTimeNow" ( _
    lpFileTime AS FILETIME _
    ) AS LONG


DECLARE FUNCTION CoRegisterMessageFilter LIB "Ole32.dll" _
    ALIAS "CoRegisterMessageFilter" ( _
    lpMessageFilter   AS ANY, _  ' LPMESSAGEFILTER
    lplpMessageFilter AS ANY _   ' LPMESSAGEFILTER
    ) AS LONG

#IF (%WIN32_WINNT >= &H0400) OR %DEF (%WIN32_DCOM) ' DCOM

DECLARE FUNCTION CoRegisterChannelHook LIB "Ole32.dll" _
    ALIAS "CoRegisterChannelHook" ( _
    ExtensionUuid AS GUID, _  ' REFGUID
    pChannelHook  AS ANY _    ' as IChannelHook PTR
    ) AS LONG
#ENDIF ' DCOM

#IF (%WIN32_WINNT >= &H0400) OR %DEF (%WIN32_DCOM) ' DCOM
' Synchronization API


DECLARE FUNCTION CoWaitForMultipleHandles LIB "Ole32.dll" _
    ALIAS "CoWaitForMultipleHandles" ( _
    BYVAL dwFlags   AS DWORD, _
    BYVAL dwTimeout AS DWORD, _
    BYVAL cHandles  AS DWORD, _
    BYVAL pHandles  AS DWORD PTR, _  ' LPHANDLE
    lpdwindex       AS DWORD  _
    ) AS LONG

' Flags for Synchronization API and Classes

MACRO COWAIT_FLAGS_enum=DWORD
ENUM COWAIT_FLAGS SINGULAR BITS
    COWAIT_WAITALL        = 1
    COWAIT_ALERTABLE
    COWAIT_INPUTAVAILABLE
END ENUM

#ENDIF ' DCOM

' for flushing OLESCM remote binding handles

#IF  (%WIN32_WINNT >= &H0501)

DECLARE FUNCTION CoInvalidateRemoteMachineBindings LIB "Ole32.dll" _
    ALIAS "CoInvalidateRemoteMachineBindings" ( _
    pszMachineName AS WSTRINGZ _
    ) AS LONG
#ENDIF

' TreatAs APIS

DECLARE FUNCTION CoGetTreatAsClass LIB "Ole32.dll" _
    ALIAS "CoGetTreatAsClass" ( _
    clsidOld  AS GUID, _  ' REFCLSID
    pClsidNew AS GUID _  ' CLSID
    ) AS LONG

DECLARE FUNCTION CoTreatAsClass LIB "Ole32.dll" ALIAS "CoTreatAsClass" ( _
    clsidOld AS GUID, _  ' REFCLSID
    clsidNew AS GUID _   ' REFCLSID
    ) AS LONG


' the server dlls must define their DllGetClassObject and DllCanUnloadNow
' to match these; the typedefs are located here to ensure all are changed at
' the same time.
'

'#ifdef _MAC
'typedef STDAPICALLTYPE HRESULT (* LPFNGETCLASSOBJECT) (REFCLSID, REFIID, LPVOID *);
'#else
'typedef HRESULT (STDAPICALLTYPE * LPFNGETCLASSOBJECT) (REFCLSID, REFIID, LPVOID *);
'#endif

'#ifdef _MAC
'typedef STDAPICALLTYPE HRESULT (* LPFNCANUNLOADNOW)(void);
'#else
'typedef HRESULT (STDAPICALLTYPE * LPFNCANUNLOADNOW)(void);
'#endif

' [function prototype]
DECLARE FUNCTION DllGetClassObject ( _
    rclsid AS GUID, _  ' REFCLSID
    riid   AS GUID, _  ' REFIID
    ppv    AS ANY _    ' LPVOID
    ) AS LONG  ' HRESULT

' [function prototype]
DECLARE FUNCTION DllCanUnloadNow () AS LONG  ' HRESULT


'***** Default Memory Allocation *******************************************
DECLARE FUNCTION CoTaskMemAlloc LIB "Ole32.dll" ALIAS "CoTaskMemAlloc" ( _
    BYVAL cb AS SIZE_T _
    ) AS DWORD  ' LPVOID

DECLARE FUNCTION CoTaskMemRealloc LIB "Ole32.dll" ALIAS "CoTaskMemRealloc" ( _
    pv       AS ANY, _  ' LPVOID
    BYVAL cb AS SIZE_T _
    ) AS DWORD  ' LPVOID

DECLARE SUB CoTaskMemFree LIB "Ole32.dll" ALIAS "CoTaskMemFree" ( _
    pv AS ANY _  ' LPVOID
    )


'***** DV APIs ************************************************************

' This function is declared in objbase.h and ole2.h
DECLARE FUNCTION CreateDataAdviseHolder LIB "Ole32.dll" _
    ALIAS "CreateDataAdviseHolder" ( _
    ppDAHolder AS ANY _  ' LPDATAADVISEHOLDER _
    ) AS LONG

DECLARE FUNCTION CreateDataCache LIB "Ole32.dll" _
    ALIAS "CreateDataCache" ( _
    pUnkOuter AS ANY, _   ' LPUNKNOWN
    rclsid    AS GUID, _  ' REFCLSID
    iid       AS GUID, _  ' REFIID
    ppv       AS ANY _    ' LPVOID
    ) AS LONG


'***** Storage API Prototypes *********************************************


DECLARE FUNCTION StgCreateDocfile LIB "Ole32.dll" _
    ALIAS "StgCreateDocfile" ( _
    pwcsName       AS WSTRINGZ, _
    BYVAL grfMode  AS DWORD, _
    BYVAL reserved AS DWORD, _
    ppstgOpen      AS ANY _  ' IStorage PTR PTR
    ) AS LONG

DECLARE FUNCTION StgCreateDocfileOnILockBytes LIB "Ole32.dll" _
    ALIAS "StgCreateDocfileOnILockBytes" ( _
    plkbyt         AS ANY, _  ' ILockBytes PTR
    BYVAL grfMode  AS DWORD, _
    BYVAL reserved AS DWORD, _
    ppstgOpen      AS ANY _   ' IStorage PTR PTR
    ) AS LONG

DECLARE FUNCTION StgOpenStorage LIB "Ole32.dll" _
    ALIAS "StgOpenStorage" ( _
    pwcsName       AS WSTRINGZ, _
    pstgPriority   AS ANY, _  ' IStorage PTR
    BYVAL grfMode  AS DWORD, _
    snbExclude     AS ANY, _  ' SNB
    BYVAL reserved AS DWORD, _
    ppstgOpen      AS ANY _   ' IStorage PTR PTR
    ) AS LONG

DECLARE FUNCTION StgOpenStorageOnILockBytes LIB "Ole32.dll" _
    ALIAS "StgOpenStorageOnILockBytes" ( _
    plkbyt         AS ANY, _  ' ILockBytes PTR
    pstgPriority   AS ANY, _  IStorage PTR
    BYVAL grfMode  AS DWORD, _
    snbExclude     AS ANY, _  ' SNB
    BYVAL reserved AS DWORD, _
    ppstgOpen      AS ANY _   ' IStorage PTR PTR
    ) AS LONG

DECLARE FUNCTION StgIsStorageFile LIB "Ole32.dll" _
    ALIAS "StgIsStorageFile" ( _
    pwcsName AS WSTRINGZ _
    ) AS LONG

DECLARE FUNCTION StgIsStorageILockBytes LIB "Ole32.dll" _
    ALIAS "StgIsStorageILockBytes" ( _
    plkbyt AS ANY _  ' ILockBytes PTR
    ) AS LONG

DECLARE FUNCTION StgSetTimes LIB "Ole32.dll" _
    ALIAS "StgSetTimes" ( _
    lpszName AS WSTRINGZ, _
    pctime AS FILETIME, _
    patime AS FILETIME, _
    pmtime AS FILETIME _
    ) AS LONG

DECLARE FUNCTION StgOpenAsyncDocfileOnIFillLockBytes LIB "Ole32.dll" _
    ALIAS "StgOpenAsyncDocfileOnIFillLockBytes" ( _
    pflb             AS ANY, _  ' IFillLockBytes PTR
    BYVAL grfMode    AS DWORD, _
    BYVAL asyncFlags AS DWORD, _
    ppstgOpen        AS ANY _  ' IStorage PTR PTR
    ) AS LONG

DECLARE FUNCTION StgGetIFillLockBytesOnILockBytes LIB "Ole32.dll" _
    ALIAS "StgGetIFillLockBytesOnILockBytes" ( _
    pilb  AS ANY, _  ' ILockBytes PTR
    ppflb AS ANY _   ' IFillLockBytes PTR PTR
    ) AS LONG

DECLARE FUNCTION StgGetIFillLockBytesOnFile LIB "Ole32.dll" _
    ALIAS "StgGetIFillLockBytesOnFile" ( _
    pwcsName AS WSTRINGZ, _
    ppflb    AS ANY _   ' IFillLockBytes PTR PTR
    ) AS LONG


DECLARE FUNCTION StgOpenLayoutDocfile LIB "Ole32.dll" _
    ALIAS "StgOpenLayoutDocfile" ( _
    pwcsDfName     AS WSTRINGZ, _
    BYVAL grfMode  AS DWORD, _
    BYVAL reserved AS DWORD, _
    ppstgOpen      AS ANY _  ' IStorage PTR PTR
    ) AS LONG

' byval STG initialization options for StgCreateStorageEx and StgOpenStorag as IStorage* eEx _
#IF %WIN32_WINNT = &H500
%STGOPTIONS_VERSION = 1
#ELSEIF %WIN32_WINNT > &H500
%STGOPTIONS_VERSION = 2
#ELSE
%STGOPTIONS_VERSION = 0
#ENDIF

TYPE STGOPTIONS
    usVersion        AS WORD          ' Versions 1 and 2 supported
    reserved         AS WORD          ' must be 0 for padding
    ulSectorSize     AS DWORD         ' docfile header sector size (512)
#IF %STGOPTIONS_VERSION >= 2
    pwcsTemplateFile AS WSTRINGZ PTR  ' version 2 or above
#ENDIF
END TYPE

DECLARE FUNCTION StgCreateStorageEx LIB "Ole32.dll" _
    ALIAS "StgCreateStorageEx" ( _
    pwcsName            AS WSTRINGZ, _
    BYVAL grfMode       AS DWORD, _
    BYVAL stgfmt        AS DWORD, _ ' enum _
    BYVAL grfAttrs      AS DWORD, _
    pStgOptions         AS STGOPTIONS, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    riid                AS GUID, _  ' REFIID
    ppObjectOpen        AS ANY _    ' void**
    ) AS LONG

DECLARE FUNCTION StgOpenStorageEx LIB "Ole32.dll" _
    ALIAS "StgOpenStorageEx" ( _
    pwcsName            AS WSTRINGZ, _
    BYVAL grfMode       AS DWORD, _
    BYVAL stgfmt        AS DWORD, _            ' enum _
    BYVAL grfAttrs      AS DWORD, _
    pStgOptions         AS STGOPTIONS, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    riid                AS GUID, _  ' REFIID
    ppObjectOpen        AS ANY _  ' void**
    ) AS LONG


'
'  Moniker APIs
'

DECLARE FUNCTION BindMoniker LIB "Ole32.dll" _
    ALIAS "BindMoniker" ( _
    pmk          AS ANY, _  ' LPMONIKER
    BYVAL grfOpt AS DWORD, _
    iidResult    AS GUID, _  ' REFIID
    ppvResult    AS ANY _  FAR * LPVOID
    ) AS LONG

DECLARE FUNCTION CoInstall LIB "Ole32.dll" _
    ALIAS "CoInstall" ( _
    pbc         AS ANY, _  ' IBindCtx *
    BYVAL       dwFlags AS DWORD, _
    pClassSpec  AS uCLSSPEC, _
    pQuery      AS QUERYCONTEXT, _
    pszCodeBase AS WSTRINGZ _
    ) AS LONG

DECLARE FUNCTION CoGetObject LIB "Ole32.dll" _
    ALIAS "CoGetObject" ( _
    pszName      AS WSTRINGZ, _
    pBindOptions AS BIND_OPTS, _
    riid         AS GUID, _  ' REFIID
    ppv          AS ANY _    ' void *
    ) AS LONG

DECLARE FUNCTION MkParseDisplayName LIB "Ole32.dll" _
    ALIAS "MkParseDisplayName" ( _
    pbc        AS ANY, _  ' LPBC
    szUserName AS WSTRINGZ, _
    pchEaten   AS DWORD, _
    ppmk       AS ANY _  ' FAR * LPMONIKER
    ) AS LONG

DECLARE FUNCTION MonikerRelativePathTo LIB "Ole32.dll" _
    ALIAS "MonikerRelativePathTo" ( _
    pmkSrc           AS ANY, _  ' LPMONIKER
    pmkDest          AS ANY, _  ' LPMONIKER
    ppmkRelPath      AS ANY, _  ' FAR* LPMONIKER
    BYVAL dwReserved AS LONG _  ' BOOL
    ) AS LONG

DECLARE FUNCTION MonikerCommonPrefixWith LIB "Ole32.dll" _
    ALIAS "MonikerCommonPrefixWith" ( _
    pmkThis    AS ANY, _  ' LPMONIKER
    pmkOther   AS ANY, _  ' LPMONIKER
    ppmkCommon AS ANY _   ' FAR* LPMONIKER
    ) AS LONG

DECLARE FUNCTION CreateBindCtx LIB "Ole32.dll" _
    ALIAS "CreateBindCtx" ( _
    BYVAL reserved AS DWORD, _
    ppbc           AS ANY _  ' FAR* LPBC
    ) AS LONG

DECLARE FUNCTION CreateGenericComposite LIB "Ole32.dll" _
    ALIAS "CreateGenericComposite" ( _
    pmkFirst      AS ANY, _  ' LPMONIKER
    pmkRest       AS ANY, _  ' LPMONIKER
    ppmkComposite AS ANY _   ' FAR* LPMONIKER
    ) AS LONG

DECLARE FUNCTION GetClassFile LIB "Ole32.dll" _
    ALIAS "GetClassFile" ( _
    szFilename AS WSTRINGZ, _
    pclsid     AS ANY _  ' FAR* CLSID
    ) AS LONG

DECLARE FUNCTION CreateClassMoniker LIB "Ole32.dll" _
    ALIAS "CreateClassMoniker" ( _
    rclsid AS GUID, _  ' REFCLSID
    ppmk   AS ANY _    ' FAR* LPMONIKER
    ) AS LONG

DECLARE FUNCTION CreateFileMoniker LIB "Ole32.dll" _
    ALIAS "CreateFileMoniker" ( _
    lpszPathName AS WSTRINGZ, _
    ppmk         AS ANY _  ' FAR* LPMONIKER
    ) AS LONG

DECLARE FUNCTION CreateItemMoniker LIB "Ole32.dll" _
    ALIAS "CreateItemMoniker" ( _
    lpszDelim AS WSTRINGZ, _
    lpszItem  AS WSTRINGZ, _
    ppmk      AS ANY _  ' FAR* LPMONIKER
    ) AS LONG

DECLARE FUNCTION CreateAntiMoniker LIB "Ole32.dll" _
    ALIAS "CreateAntiMoniker" ( _
    ppmk AS ANY _  ' FAR* LPMONIKER
    ) AS LONG

DECLARE FUNCTION CreatePointerMoniker LIB "Ole32.dll" _
    ALIAS "CreatePointerMoniker" ( _
    punk AS ANY, _  ' LPUNKNOWN
    ppmk AS ANY _   ' FAR* LPMONIKER
    ) AS LONG

DECLARE FUNCTION CreateObjrefMoniker LIB "Ole32.dll" _
    ALIAS "CreateObjrefMoniker" ( _
    punk AS ANY, _  ' LPUNKNOWN
    ppmk AS ANY _   ' FAR * LPMONIKER
    ) AS LONG

DECLARE FUNCTION GetRunningObjectTable LIB "Ole32.dll" _
    ALIAS "GetRunningObjectTable" ( _
    BYVAL reserved AS DWORD, _
    pprot          AS ANY _  ' FAR* LPRUNNINGOBJECTTABLE
    ) AS LONG

'#include "urlmon.inc"
'#include "propidl.inc"

'
' Standard Progress Indicator impolementation
'
DECLARE FUNCTION CreateStdProgressIndicator LIB "Ole32.dll" _
    ALIAS "CreateStdProgressIndicator" ( _
    BYVAL hwndParent AS DWORD, _  ' HWND
    pszTitle         AS WSTRINGZ, _
    pIbscCaller      AS ANY, _    ' IBindStatusCallback *
    ppIbsc           AS ANY _     ' IBindStatusCallback **
    ) AS LONG


'#ifndef RC_INVOKED
'#include <poppack.h>
'#endif // RC_INVOKED
