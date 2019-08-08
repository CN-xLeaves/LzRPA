
'-----------------------------------------
'SAPI VOICE
'=========================================

  #basic 
  #case capital


  'standalone definitions ad hoc

  #define __in
  #define __out
  #define __in_opt      optional
  #define __out_opt     optional
  #define __RPC__in_opt optional

  typedef sys     HANDLE,HRESULT,HWND,WMSG,WPARAM,LPARAM
  typedef dword   DWORD,ULONG,UINT
  typedef qword   ULONGLONG
  typedef bool    BOOL
  typedef zstring *LPCWSTR
  typedef word    USHORT
  typedef void    *pvobject


  typedef struct
  {
    a as dword
    b as word
    c as word
    d[8] as byte
  } GUID, *refiid


  typedef void * PVOID
  typedef void SPNOTIFYCALLBACK, ISpNotifyCallback, ISpNotifySink 
  typedef void ISpObjectToken,IStream,ISpStreamFormat,SPVOICESTATUS,SPVPRIORITY,SPEVENTENUM       
  typedef void SPEVENT,SPEVENTSOURCEINFO

  'typedef long SPEVENT,SPEVENTSOURCEINFO

  'from Unknwn.h
  '---------------------
  class IUnknown virtual
  '=====================

    method QueryInterface(refiid id, pvObject* ppv) as HRESULT
    method AddRef() as ULONG
    method Release() as ULONG

  end class

  'from sapi.h


  'MIDL_INTERFACE("5EFF4AEF-8487-11D2-961C-00C04F8EE628")
  'ISpNotifySource : public IUnknown
  '
  '----------------------------
  class ISpNotifySource virtual
  '============================

    public

    from IUnknown

        method HRESULT SetNotifySink( 
            /* [in] */ __RPC__in_opt ISpNotifySink *pNotifySink)
        
        method HRESULT SetNotifyWindowMessage( 
            /* [in] */ HWND hWnd,
            /* [in] */ UINT Msg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam)
        
        method HRESULT SetNotifyCallbackFunction( 
            /* [in] */ SPNOTIFYCALLBACK *pfnCallback,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam)
        
        method HRESULT SetNotifyCallbackInterface( 
            /* [in] */ ISpNotifyCallback *pSpCallback,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam)
        
        method HRESULT SetNotifyWin32Event( void)
        
        method HRESULT WaitForNotifyEvent( 
            /* [in] */ DWORD dwMilliseconds)
        
        method HANDLE GetNotifyEventHandle( void)

  end class


  'MIDL_INTERFACE("BE7A9CCE-5F9E-11D2-960F-00C04F8EE628")
  'ISpEventSource : public ISpNotifySource
  '

  '---------------------------
  class ISpEventSource virtual
  '===========================

    public

    from ISpNotifySource

        method HRESULT SetInterest( 
            /* [in] */ ULONGLONG ullEventInterest,
            /* [in] */ ULONGLONG ullQueuedInterest)
        
        method HRESULT GetEvents( 
            /* [in] */ ULONG ulCount,
            /* [size_is][out] */ SPEVENT *pEventArray,
            /* [out] */ ULONG *pulFetched)
        
        method HRESULT GetInfo( 
            /* [out] */ SPEVENTSOURCEINFO *pInfo)
        
  end class



    'MIDL_INTERFACE("6C44DF74-72B9-4992-A1EC-EF996E0422D4")
    'ISpVoice : public ISpEventSource
    '

    '---------------------
    class ISpVoice virtual
    '=====================
    '
    public

    from ISpEventSource

        method HRESULT SetOutput( 
            /* [in] */ IUnknown *pUnkOutput,
            /* [in] */ BOOL fAllowFormatChanges)
        
        method HRESULT GetOutputObjectToken( 
            /* [out] */ ISpObjectToken **ppObjectToken)
        
        method HRESULT GetOutputStream( 
            /* [out] */ ISpStreamFormat **ppStream)
        
        method HRESULT Pause( void)
        
        method HRESULT Resume( void)
        
        method HRESULT SetVoice( 
            /* [in] */ ISpObjectToken *pToken)
        
        method HRESULT GetVoice( 
            /* [out] */ ISpObjectToken **ppToken)
        
        method HRESULT Speak( 
            /* [string][in] */ 
            __in_opt  LPCWSTR pwcs,
            /* [in] */ DWORD dwFlags,
            /* [out] */ 
            __out_opt  ULONG *pulStreamNumber)

        method HRESULT SpeakStream( 
            /* [in] */ IStream *pStream,
            /* [in] */ DWORD dwFlags,
            /* [out] */ 
            __out_opt  ULONG *pulStreamNumber)
        
        method HRESULT GetStatus( 
            /* [out] */ SPVOICESTATUS *pStatus,
            /* [out] */ LPWSTR *ppszLastBookmark)
        
        method HRESULT Skip( 
            /* [string][in] */ LPCWSTR pItemType,
            /* [in] */ long lNumItems,
            /* [out] */ ULONG *pulNumSkipped)
        
        method HRESULT SetPriority( 
            /* [in] */ SPVPRIORITY ePriority)
        
        method HRESULT GetPriority( 
            /* [out] */ SPVPRIORITY *pePriority)
        
        method HRESULT SetAlertBoundary( 
            /* [in] */ SPEVENTENUM eBoundary)
        
        method HRESULT GetAlertBoundary( 
            /* [out] */ SPEVENTENUM *peBoundary)
        
        method HRESULT SetRate( 
            /* [in] */ long RateAdjust)
        
        method HRESULT GetRate( 
            /* [out] */ long *pRateAdjust)
        method HRESULT SetVolume( 
            /* [in] */ USHORT usVolume)
        
        method HRESULT GetVolume( 
            /* [out] */ USHORT *pusVolume)
        
        method HRESULT WaitUntilDone( 
            /* [in] */ ULONG msTimeout)
        
        method HRESULT SetSyncSpeakTimeout( 
            /* [in] */ ULONG msTimeout)
        
        method HRESULT GetSyncSpeakTimeout( 
            /* [out] */ ULONG *pmsTimeout)
        
        method /* [local] */ HANDLE SpeakCompleteEvent( void)
        
        method /* [local] */ HRESULT IsUISupported( 
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData,
            /* [out] */ BOOL *pfSupported)
        
        method /* [local] */ HRESULT DisplayUI( 
            /* [in] */ HWND hwndParent,
            /* [in] */ LPCWSTR pszTitle,
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData)
        
    end class



  typedef GUID *REFIID, *REFCLSID
  typedef void *LPVOID, *LPUNKNOWN,*COSERVERINFO

  extern stdcall lib "ole32.dll"


  HRESULT CoInitialize(
    __in_opt  LPVOID pvReserved
  );


  void CoUninitialize(void);



  HRESULT CoCreateInstance(
    __in   REFCLSID rclsid,
    __in   LPUNKNOWN pUnkOuter,
    __in   DWORD dwClsContext,
    __in   REFIID riid,
    __out  LPVOID *ppv
  )



  HRESULT CoGetClassObject(
    __in      REFCLSID rclsid,
    __in      DWORD dwClsContext,
    __in_opt  COSERVERINFO pServerInfo,
    __in      REFIID riid,
    __out     LPVOID *ppv
  );


  'HRESULT __stdcall DllGetClassObject(
  '  __in   REFCLSID rclsid,
  '  __in   REFIID riid,
  '  __out  LPVOID *ppv
  ');

  'HRESULT __stdcall DllCanUnloadNow(void);



  HRESULT CoRegisterClassObject(
    __in   REFCLSID rclsid,
    __in   LPUNKNOWN pUnk,
    __in   DWORD dwClsContext,
    __in   DWORD flags,
    __out  LPDWORD lpdwRegister
  );



  HRESULT CoRevokeClassObject(
    __in  DWORD dwRegister
  );




  end extern


  'CLSCTX_INPROC_SERVER            = 0x1
  'CLSCTX_INPROC_HANDLER           = 0x2
  'CLSCTX_LOCAL_SERVER             = 0x4
  'CLSCTX_INPROC_SERVER16          = 0x8
  'CLSCTX_REMOTE_SERVER            = 0x10
  '
  #define context 7


  '=================
  'UTILITY FUNCTIONS
  '=================


  '-----------------------------
  function w(string s) as string
  '=============================
    '
    'CONVERT TO WIDE STRING
    '
    dim i,j,le
    le=len(s)
    function=nuls(le*2+2)
    for i=1 to le
      j=2*(i-1)+1
      mid (function,j)=mid(s,i,1)
    next
  end function


  '----------------------------------------------
  function ConnectVoice(ISpVoice** pvoice) as sys
  '==============================================

  dim as GUID          VoiceObjGuid, ISpVoiceGuid
  dim as HRESULT       hr
  dim as ISpVoice ptr  voice
  dim as LPUNKNOWN     pUnkOuter

  guidval VoiceObjGuid, "96749377-3391-11D2-9EE3-00C04F797396"
  guidval ISpVoiceGuid, "6C44DF74-72B9-4992-A1EC-EF996E0422D4"

  & pUnkouter=0

  function=CoCreateInstance VoiceObjGuid, pUnkouter, context, ISpVoiceGuid, pvoice

  end function


  '-----------------------------------------------
  function DisconnectVoice(ISpVoice* voice) as sys
  '===============================================
  voice.Release
  & voice=0
  end function

  '
  'UTILITY MACROS FOR LOCAL USE
  '
  '==============
  def VoiceMacros
  '==============
  {
    def Connect
    {
       CoInitialize(byval 0)
       ISpVoice * %1
       Err=ConnectVoice %1
    }

    def Disconnect
    {
      Disconnectvoice %1
      CoUninitialize()
    }

    def Give
    {
      & %1.%2 = & %2
    }

    def Remove
    {
      & %1.%2 = 0
    }

    def ErrorHandler
    {
      if Err then
        print "SAPI Error " hex(Err)
        %e
      end if
    }

    def forever
    {
      &hffffffff
    }

  }
