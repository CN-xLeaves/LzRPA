'------------------------------------------------------------------------------
'
'  ShlObj.inc
'
'  Copyright (c) 2009-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from ShlObj.h dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%SHLOBJ_H = 1


#INCLUDE "WinCon.inc"   ' for COORD
#INCLUDE "Ole2.inc"
#INCLUDE "PrSht.inc"
#INCLUDE "CommCtrl.inc"   ' for LPTBBUTTON
#INCLUDE "ShlGuid.inc"
#INCLUDE "ShTypes.inc"
'#INCLUDE "ShObjIdl.inc"
#INCLUDE "WinNetWk.inc"   ' for NETRESOURCE


'===========================================================================
'
' Legacy exports that are no longer needed, call the COM API instead
'
'===========================================================================

'SHSTDAPI SHGetMalloc(__out IMalloc **ppMalloc); ' CoGetMalloc(MEMCTX_TASK,ppMalloc)
'SHSTDAPI_(void *) SHAlloc(SIZE_T cb);           ' CoTaskMemAlloc(cb)
'SHSTDAPI_(void)   SHFree(__in_opt void * pv);   ' CoTaskMemFree(pv)



'===========================================================================
'
' IExtractIcon interface
'
'  This interface is used in two different places in the shell.
'
' Case-1: Icons of sub-folders for the scope-pane of the explorer.
'
'  It is used by the explorer to get the "icon location" of
' sub-folders from each shell folders. When the user expands a folder
' in the scope pane of the explorer, the explorer does following:
'  (1) binds to the folder (gets IShellFolder),
'  (2) enumerates its sub-folders by calling its EnumObjects member,
'  (3) calls its GetUIObjectOf member to get IExtractIcon interface
'     for each sub-folders.
'  In this case, the explorer uses only IExtractIcon::GetIconLocation
' member to get the location of the appropriate icon. An icon location
' always consists of a file name (typically DLL or EXE) and either an icon
' resource or an icon index.
'
'
' Case-2: Extracting an icon image from a file
'
'  It is used by the shell when it extracts an icon image
' from a file. When the shell is extracting an icon from a file,
' it does following:
'  (1) creates the icon extraction handler object (by getting its CLSID
'     under the {ProgID}\shell\ExtractIconHanler key and calling
'     CoCreateInstance requesting for IExtractIcon interface).
'  (2) Calls IExtractIcon::GetIconLocation.
'  (3) Then, calls IExtractIcon::ExtractIcon with the location/index pair.
'  (4) If (3) returns S_OK, it uses the returned icon.
'  (5) Otherwise, it recursively calls this logic with new location
'     assuming that the location string contains a fully qualified path name.
'
'  From extension programmer's point of view, there are only two cases
' where they provide implementations of IExtractIcon:
'  Case-1) providing explorer extensions (i.e., IShellFolder).
'  Case-2) providing per-instance icons for some types of files.
'
' Because Case-1 is described above, we'll explain only Case-2 here.
'
' When the shell is about display an icon for a file, it does following:
'  (1) Finds its ProgID and ClassID.
'  (2) If the file has a ClassID, it gets the icon location string from the
'    "DefaultIcon" key under it. The string indicates either per-class
'    icon (e.g., "FOOBAR.DLL,2") or per-instance icon (e.g., "%1,1").
'  (3) If a per-instance icon is specified, the shell creates an icon
'    extraction handler object for it, and extracts the icon from it
'    (which is described above).
'
'  It is important to note that the shell calls IExtractIcon::GetIconLocation
' first, then calls IExtractIcon::Extract. Most application programs
' that support per-instance icons will probably store an icon location
' (DLL/EXE name and index/id) rather than an icon image in each file.
' In those cases, a programmer needs to implement only the GetIconLocation
' member and it Extract member simply returns S_FALSE. They need to
' implement Extract member only if they decided to store the icon images
' within files themselved or some other database (which is very rare).
'
'
'
' [Member functions]
'
'
' IExtractIcon::GetIconLocation
'
'  This function returns an icon location.
'
'  Parameters:
'   uFlags     [in]  -- Specifies if it is opened or not (GIL_OPENICON or 0)
'   szIconFile [out] -- Specifies the string buffer buffer for a location name.
'   cchMax     [in]  -- Specifies the size of szIconFile (almost always MAX_PATH)
'   piIndex    [out] -- Sepcifies the address of UINT for the index.
'   pwFlags    [out] -- Returns GIL_* flags
'  Returns:
'   S_OK, if it returns a valid location; S_FALSE, if the shell use a
'   default icon.
'
'  Notes: The location may or may not be a path to a file. The caller can
'   not assume anything unless the subsequent Extract member call returns
'   S_FALSE.
'
'   if the returned location is not a path to a file, GIL_NOTFILENAME should
'   be set in the returned flags.
'
' IExtractIcon::Extract
'
'  This function extracts an icon image from a specified file.
'
'  Parameters:
'   pszFile [in] -- Specifies the icon location (typically a path to a file).
'   nIconIndex [in] -- Specifies the icon index.
'   phiconLarge [out] -- Specifies the HICON variable for large icon.
'   phiconSmall [out] -- Specifies the HICON variable for small icon.
'   nIconSize [in] -- Specifies the size icon required (size of large icon)
'                     LOWORD is the requested large icon size
'                     HIWORD is the requested small icon size
'  Returns:
'   S_OK, if it extracted the from the file.
'   S_FALSE, if the caller should extract from the file specified in the
'           location.
'
'===========================================================================

' GetIconLocation() input flags

%GIL_OPENICON      = &H0001      ' allows containers to specify an "open" look
%GIL_FORSHELL      = &H0002      ' icon is to be displayed in a ShellFolder
%GIL_ASYNC         = &H0020      ' this is an async extract, return E_PENDING
%GIL_DEFAULTICON   = &H0040      ' get the default icon location if the final one takes too long to get
%GIL_FORSHORTCUT   = &H0080      ' the icon is for a shortcut to the object
%GIL_CHECKSHIELD   = &H0200      ' return GIL_SHIELD or GIL_FORCENOSHIELD, don't block if GIL_ASYNC is set

' GetIconLocation() return flags

%GIL_SIMULATEDOC   = &H0001      ' simulate this document icon for this
%GIL_PERINSTANCE   = &H0002      ' icons from this class are per instance (each file has its own)
%GIL_PERCLASS      = &H0004      ' icons from this class per class (shared for all files of this type)
%GIL_NOTFILENAME   = &H0008      ' location is not a filename, must call ::ExtractIcon
%GIL_DONTCACHE     = &H0010      ' this icon should not be cached
%GIL_SHIELD        = &H0200      ' icon should be "stamped" with the LUA shield
%GIL_FORCENOSHIELD = &H0400      ' icon must *not* be "stamped" with the LUA shield

'#undef  INTERFACE
'#define INTERFACE   IExtractIconA
'
'DECLARE_INTERFACE_IID_(IExtractIconA, IUnknown, "000214eb-0000-0000-c000-000000000046")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** IExtractIcon methods ***
'    STDMETHOD(GetIconLocation)(THIS_
'                               UINT   uFlags,
'          __out_ecount(cchMax) LPSTR  szIconFile,
'                               UINT   cchMax,
'                         __out int   * piIndex,
'                         __out UINT  * pwFlags) PURE;
'
'    STDMETHOD(Extract)(THIS_
'                       LPCSTR  pszFile,
'                       UINT    nIconIndex,
'             __out_opt HICON   *phiconLarge,
'             __out_opt HICON   *phiconSmall,
'                       UINT    nIconSize) PURE;
'};
'
'#undef  INTERFACE
'#define INTERFACE   IExtractIconW
'
'DECLARE_INTERFACE_IID_(IExtractIconW, IUnknown, "000214fa-0000-0000-c000-000000000046")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** IExtractIcon methods ***
'    STDMETHOD(GetIconLocation)(THIS_
'                               UINT   uFlags,
'          __out_ecount(cchMax) LPWSTR pszIconFile,
'                               UINT   cchMax,
'                         __out int   * piIndex,
'                         __out UINT  * pwFlags) PURE;
'
'    STDMETHOD(Extract)(THIS_
'                       LPCWSTR pszFile,
'                       UINT    nIconIndex,
'             __out_opt HICON   *phiconLarge,
'             __out_opt HICON   *phiconSmall,
'                       UINT    nIconSize) PURE;
'};
'
'#IF %DEF(%UNICODE)
'MACRO IExtractIcon     = IExtractIconW
'MACRO IExtractIconVtbl = IExtractIconWVtbl
'#ELSE
'MACRO IExtractIcon     = IExtractIconA
'MACRO IExtractIconVtbl = IExtractIconAVtbl
'#ENDIF

'===========================================================================
'
' IShellIconOverlayIdentifier
'
' Used to identify a file as a member of the group of files that have this specific
' icon overlay
'
' Users can create new IconOverlayIdentifiers and place them in the following registry
' location together with the Icon overlay image and their priority.
' HKEY_LOCAL_MACHINE "Software\\Microsoft\\Windows\\CurrentVersion\\ShellIconOverlayIdentifiers"
'
' The shell will enumerate through all IconOverlayIdentifiers at start, and prioritize
' them according to internal rules, in case the internal rules don't apply, we use their
' input priority
'
' IShellIconOverlayIdentifier:IsMemberOf(LPCWSTR pwszPath, DWORD dwAttrib)
'      pwszPath        full path of the file
'      dwAttrib        attribute of this file
'
'  returns:
'      S_OK,    if the file is a member
'      S_FALSE, if the file is not a member
'      E_FAIL,  if the operation failed due to bad WIN32_FIND_DATA
'
' IShellIconOverlayIdentifier::GetOverlayInfo(LPWSTR pwszIconFile, int * pIndex, DWORD * dwFlags) PURE;
'      pszIconFile    the path of the icon file
'      pIndex         Depend on the flags, this could contain the IconIndex
'      dwFlags        defined below
'
' IShellIconOverlayIdentifier::GetPriority(int * pIPriority) PURE;
'      pIPriority     the priority of this Overlay Identifier
'
'===========================================================================

'#undef  INTERFACE
'#define INTERFACE   IShellIconOverlayIdentifier
'
'DECLARE_INTERFACE_IID_(IShellIconOverlayIdentifier, IUnknown, "0c6c4200-c589-11d0-999a-00c04fd655e1")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** IShellIconOverlayIdentifier methods ***
'    STDMETHOD (IsMemberOf)(THIS_ LPCWSTR pwszPath, DWORD dwAttrib) PURE;
'    STDMETHOD (GetOverlayInfo)(THIS_ __out_ecount(cchMax) LPWSTR pwszIconFile, int cchMax, __out int * pIndex, __out DWORD * pdwFlags) PURE;
'    STDMETHOD (GetPriority)(THIS_ __out int * pIPriority) PURE;
'};

%ISIOI_ICONFILE  = &H00000001  ' path is returned through pwszIconFile
%ISIOI_ICONINDEX = &H00000002  ' icon index in pwszIconFile is returned through pIndex

'===========================================================================
'
' IShellIconOverlayManager
'
' Used to return the icon overlay information including OverlayIndex, Image Index or Priority for an IShellFolder object.
'
' IShellIconOverlayManager:GetFileOverlayInfo(LPCWSTR pwszPath, DWORD dwAttrib, int * pIndex, DWORD dwflags)
'      pwszPath        full path of the file
'      dwAttrib        attribute of this file
'      pIndex          pointer to the Icon Index in the system image list
'      pOverlayIndex   pointer to the OverlayIndex in the system image list
'      pPriority       pointer to the Priority of this overlay
' IShellIconOverlayManager:GetReservedOverlayInfo(LPCWSTR pwszPath, DWORD dwAttrib, int * pIndex, DWORD dwflags, int iReservedID)
'      iReservedID     reserved icon overlay id
'  returns:
'      S_OK,  if the index of an Overlay is found
'      S_FALSE, if no Overlay exists for this file
'      E_FAIL, if lpfd is bad
' IShellIconOverlayManager:RefreshOverlayImages(DWORD dwFlags)
'      This will refresh the overlay cache, depends on the dwFlags passed in
'      It will reload the icons into the imagelist, when passed SIOM_ICONINDEX
' IShellIconOverlayManager::LoadNonloadedOverlayIdentifiers()
'      This method loads any registered overlay identifiers (handlers) that
'      are not currently loaded.
' IShellIconOverlayManager::OverlayIndexFromImageIndex(int iImage, int *piIndex, BOOL fAdd)
'      iImage          existing shell image list index to look for
'      piIndex         returned overlay index
'      fAdd            Add image if not already present?
'===========================================================================

'#undef  INTERFACE
'#define INTERFACE   IShellIconOverlayManager
'
'DECLARE_INTERFACE_IID_(IShellIconOverlayManager, IUnknown, "f10b5e34-dd3b-42a7-aa7d-2f4ec54bb09b")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** IShellIconOverlayManager methods ***
'    STDMETHOD(GetFileOverlayInfo)(THIS_ __in LPCWSTR pwszPath, DWORD dwAttrib, __out int * pIndex, DWORD dwflags) PURE;
'    STDMETHOD(GetReservedOverlayInfo)(THIS_ __in_opt LPCWSTR pwszPath, DWORD dwAttrib, __out int * pIndex, DWORD dwflags, int iReservedID) PURE;
'    STDMETHOD(RefreshOverlayImages)(THIS_ DWORD dwFlags) PURE;
'    STDMETHOD(LoadNonloadedOverlayIdentifiers)(THIS) PURE;
'    STDMETHOD(OverlayIndexFromImageIndex)(THIS_ int iImage, __out int * piIndex, BOOL fAdd) PURE;
'};

%SIOM_OVERLAYINDEX      = 1
%SIOM_ICONINDEX         = 2
' %SIOM_PRIORITY         = 3
%SIOM_RESERVED_SHARED   = 0
%SIOM_RESERVED_LINK     = 1
%SIOM_RESERVED_SLOWFILE = 2
%SIOM_RESERVED_DEFAULT  = 3

'===========================================================================
'
' IShellIconOverlay
'
' Used to return the icon overlay index or its icon index for an IShellFolder object,
' this is always implemented with IShellFolder
'
' IShellIconOverlay:GetOverlayIndex(LPCITEMIDLIST pidl, DWORD * pdwIndex)
'      pidl            object to identify icon overlay for.
'      pdwIndex        the Overlay Index in the system image list
'
' IShellIconOverlay:GetOverlayIconIndex(LPCITEMIDLIST pidl, DWORD * pdwIndex)
'      pdwIconIndex    the Overlay Icon index in the system image list
' This method is only used for those who are interested in seeing the real bits
' of the Overlay Icon
'
'  returns:
'      S_OK,  if the index of an Overlay is found
'      S_FALSE, if no Overlay exists for this file
'      E_FAIL, if pidl is bad
'
'===========================================================================

'#undef  INTERFACE
'#define INTERFACE   IShellIconOverlay
'
'DECLARE_INTERFACE_IID_(IShellIconOverlay, IUnknown, "7d688a70-c613-11d0-999b-00c04fd655e1")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** IShellIconOverlay methods ***
'    STDMETHOD(GetOverlayIndex)(THIS_ PCUITEMID_CHILD pidl, __inout int * pIndex) PURE;
'    STDMETHOD(GetOverlayIconIndex)(THIS_ PCUITEMID_CHILD pidl, __inout int * pIconIndex) PURE;
'};

%OI_DEFAULT = &H00000000
%OI_ASYNC   = &HFFFFEEEE???

'-------------------------------------------------------------------------
'
' SHGetIconOverlayIndex
'
' This function takes the path and icon/res id to the icon and convert it into
' an overlay index in the system image list.
' Note: there are totally only 15 slots for system image overlays, some of which
' was reserved by the system, or taken by the overlayidentifiers, so it's possible
' that this function would fail and return -1;
'
' To get the default overlays in the system, such as the share hand, link shortcut
' and slow files, pass NULL as the file name, then the IDO_SHGIOI_* flags as the icon index
'-------------------------------------------------------------------------

%IDO_SHGIOI_SHARE    =  &H0FFFFFFF
%IDO_SHGIOI_LINK     =  &H0FFFFFFE
%IDO_SHGIOI_SLOWFILE = &H0FFFFFFFD
%IDO_SHGIOI_DEFAULT  = &H0FFFFFFFC

DECLARE FUNCTION SHGetIconOverlayIndexA LIB "Shell32.dll" _
    ALIAS "SHGetIconOverlayIndexA" (pszIconPath AS ASCIIZ, _
    BYVAL iIconIndex AS LONG) AS LONG

DECLARE FUNCTION SHGetIconOverlayIndexW LIB "Shell32.dll" _
    ALIAS "SHGetIconOverlayIndexW" (pszIconPath AS WSTRINGZ, _
    BYVAL iIconIndex AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHGetIconOverlayIndex LIB "Shell32.dll" _
    ALIAS "SHGetIconOverlayIndexW" (pszIconPath AS WSTRINGZ, _
    BYVAL iIconIndex AS LONG) AS LONG
#ELSE
DECLARE FUNCTION SHGetIconOverlayIndex LIB "Shell32.dll" _
    ALIAS "SHGetIconOverlayIndexA" (pszIconPath AS ASCIIZ, _
    BYVAL iIconIndex AS LONG) AS LONG
#ENDIF ' NOT %UNICODE


#IF (%WIN32_IE >= &H0400)

' IShellLinkDataList::GetFlags()/SetFlags()
MACRO SHELL_LINK_DATA_FLAGS_enum=LONG
ENUM SHELL_LINK_DATA_FLAGS SINGULAR BITS
    SLDF_DEFAULT
    SLDF_HAS_ID_LIST                            ' Shell link saved with ID list
    SLDF_HAS_LINK_INFO                          ' Shell link saved with LinkInfo
    SLDF_HAS_NAME
    SLDF_HAS_RELPATH
    SLDF_HAS_WORKINGDIR
    SLDF_HAS_ARGS
    SLDF_HAS_ICONLOCATION
    SLDF_UNICODE                                ' the strings are unicode
    SLDF_FORCE_NO_LINKINFO                      ' disable LINKINFO tracking information (used to track network drives and compute UNC paths if one exists)
    SLDF_HAS_EXP_SZ                             ' the link contains expandable env strings
    SLDF_RUN_IN_SEPARATE                        ' Run the 16-bit target exe in a separate VDM/WOW
#IF (%NTDDI_VERSION < %NTDDI_VISTA)
    SLDF_HAS_LOGO3ID                            ' not used anymore
#ENDIF
    SLDF_HAS_DARWINID            = &H00001000   ' MSI (Darwin) link that can be installed on demand
    SLDF_RUNAS_USER                             ' Run target as a different user
    SLDF_HAS_EXP_ICON_SZ                        ' contains expandable env string for icon path
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
    SLDF_NO_PIDL_ALIAS                          ' disable IDList alias mapping when parsing the IDList from the path
    SLDF_FORCE_UNCNAME                          ' make GetPath() prefer the UNC name to the local name
    SLDF_RUN_WITH_SHIMLAYER                     ' activate target of this link with shim layer active
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
    SLDF_FORCE_NO_LINKTRACK                     ' disable ObjectID tracking information
    SLDF_ENABLE_TARGET_METADATA                 ' enable caching of target metadata into link
    SLDF_DISABLE_LINK_PATH_TRACKING             ' disable EXP_SZ_LINK_SIG tracking
    SLDF_DISABLE_KNOWNFOLDER_RELATIVE_TRACKING  ' disable KnownFolder tracking information (EXP_KNOWN_FOLDER)
#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
    SLDF_NO_KF_ALIAS                            ' disable Known Folder alias mapping when loading the IDList during deserialization
    SLDF_ALLOW_LINK_TO_LINK                     ' allows this link to point to another shell link - must only be used when it is not possible to create cycles
    SLDF_UNALIAS_ON_SAVE                        ' unalias the IDList when saving
    SLDF_PREFER_ENVIRONMENT_PATH                ' the IDList is not persisted, instead it is recalculated from the path with environmental variables at load time
                                                ' we don't hit the disk to recalculate the IDList (the result is a simple IDList).  also Resolve does nothing
                                                ' if SetPath is called and the path does not have environmental variable in it, SLDF_PREFER_ENVIRONMENT_PATH is removed
    SLDF_KEEP_LOCAL_IDLIST_FOR_UNC_TARGET       ' if target is a UNC location on a local machine, keep the local target in addition to the remote one
    SLDF_VALID                   = &H07FFF7FF   ' bits that are valid for ::SetFlags()
#ELSE
    SLDF_VALID                   = &H003FF7FF   ' bits that are valid for ::SetFlags()
#ENDIF ' #IF (%NTDDI_VERSION >= %NTDDI_WIN7)
#ENDIF ' #IF (%NTDDI_VERSION >= %NTDDI_VISTA)
    SLDF_RESERVED                = &H80000000??? ' Reserved-- so we can use the low word as an index value in the future
#ENDIF ' #IF (%NTDDI_VERSION >= %NTDDI_WINXP)
END ENUM

TYPE DATABLOCK_HEADER
    cbSize      AS DWORD   ' Size of this extra data block
    dwSignature AS DWORD   ' signature of this extra data block
END TYPE

#IF %DEF(%LF_FACESIZE)
TYPE NT_CONSOLE_PROPS
    DATABLOCK_HEADER
    wFillAttribute          AS WORD         ' fill attribute for console
    wPopupFillAttribute     AS WORD         ' fill attribute for console popups
    dwScreenBufferSize      AS COORD        ' screen buffer size for console
    dwWindowSize            AS COORD        ' window size for console
    dwWindowOrigin          AS COORD        ' window origin for console
    nFont                   AS DWORD
    nInputBufferSize        AS DWORD
    dwFontSize              AS COORD
    uFontFamily             AS DWORD
    uFontWeight             AS DWORD
    FaceName                AS WSTRINGZ * %LF_FACESIZE
    uCursorSize             AS DWORD
    bFullScreen             AS LONG
    bQuickEdit              AS LONG
    bInsertMode             AS LONG
    bAutoPosition           AS LONG
    uHistoryBufferSize      AS DWORD
    uNumberOfHistoryBuffers AS DWORD
    bHistoryNoDup           AS LONG
    ColorTable(15)          AS COLORREF
END TYPE
#ENDIF  ' #IF %DEF(%LF_FACESIZE)

%NT_CONSOLE_PROPS_SIG = &HA0000002???

' This is a FE Console property
TYPE NT_FE_CONSOLE_PROPS
    DATABLOCK_HEADER
    UCODEPAGE AS DWORD
END TYPE
%NT_FE_CONSOLE_PROPS_SIG = &HA0000004???

#IF (%WIN32_IE >= &H0500)
TYPE EXP_DARWIN_LINK
    DATABLOCK_HEADER
    szDarwinID  AS ASCIIZ * %MAX_PATH   ' ANSI darwin ID associated with link
    szwDarwinID AS WSTRINGZ * %MAX_PATH ' UNICODE darwin ID associated with link
END TYPE
%EXP_DARWIN_ID_SIG       = &HA0000006???
#ENDIF

%EXP_SPECIAL_FOLDER_SIG         = &HA0000005???   ' LPEXP_SPECIAL_FOLDER


TYPE EXP_SPECIAL_FOLDER
    cbSize          AS DWORD   ' Size of this extra data block
    dwSignature     AS DWORD   ' signature of this extra data block
    idSpecialFolder AS DWORD   ' special folder id this link points into
    cbOffset        AS DWORD   ' ofset into pidl from SLDF_HAS_ID_LIST for child
END TYPE


TYPE EXP_SZ_LINK
    cbSize      AS DWORD                 ' Size of this extra data block
    dwSignature AS DWORD                 ' signature of this extra data block
    szTarget    AS ASCIIZ * %MAX_PATH    ' ANSI target name w/EXP_SZ in it
    swzTarget   AS WSTRINGZ * %MAX_PATH  ' UNICODE target name w/EXP_SZ in it
END TYPE
%EXP_SZ_LINK_SIG                = &HA0000001???   ' LPEXP_SZ_LINK (target)
%EXP_SZ_ICON_SIG                = &HA0000007???   ' LPEXP_SZ_LINK (icon)

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
TYPE EXP_PROPERTYSTORAGE
    cbSize               AS DWORD        ' Size of this extra data block
    dwSignature          AS DWORD        ' signature of this extra data block
    abPropertyStorage(0) AS BYTE
END TYPE
%EXP_PROPERTYSTORAGE_SIG     = &HA0000009???
#ENDIF

#ENDIF ' (%WIN32_IE >= &H0400)


#IF %DEF(%INC_SHELLAPI)    ' for LPSHELLEXECUTEINFO
'===========================================================================
'
' IShellExecuteHook Interface
'
'===========================================================================

'#undef  INTERFACE
'#define INTERFACE   IShellExecuteHookA
'
'DECLARE_INTERFACE_IID_(IShellExecuteHookA, IUnknown, "000214f5-0000-0000-c000-000000000046")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG, AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG, Release) (THIS) PURE;
'
'    ' *** IShellExecuteHookA methods ***
'    STDMETHOD(Execute)(THIS_ __inout LPSHELLEXECUTEINFOA pei) PURE;
'};
'
'#undef  INTERFACE
'#define INTERFACE   IShellExecuteHookW
'
'DECLARE_INTERFACE_IID_(IShellExecuteHookW, IUnknown, "000214fb-0000-0000-c000-000000000046")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG, AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG, Release) (THIS) PURE;
'
'    ' *** IShellExecuteHookW methods ***
'    STDMETHOD(Execute)(THIS_ __inout LPSHELLEXECUTEINFOW pei) PURE;
'};
'
'#IF %DEF(%UNICODE)
'macro IShellExecuteHook     = IShellExecuteHookW
'macro IShellExecuteHookVtbl = IShellExecuteHookWVtbl
'#else
'macro IShellExecuteHook     = IShellExecuteHookA
'macro IShellExecuteHookVtbl = IShellExecuteHookAVtbl
'#endif
#ENDIF  ' #IF %DEF(%INC_SHELLAPI)    ' for LPSHELLEXECUTEINFO

'===========================================================================
'
' IURLSearchHook Interface
'
'===========================================================================

'#undef  INTERFACE
'#define INTERFACE   IURLSearchHook
'
'DECLARE_INTERFACE_IID_(IURLSearchHook, IUnknown, "ac60f6a0-0fd9-11d0-99cb-00c04fd64497")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG, AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG, Release) (THIS) PURE;
'
'    ' *** IURLSearchHook methods ***
'    STDMETHOD(Translate)(THIS_ __out_ecount(cchBufferSize) LPWSTR lpwszSearchURL, DWORD cchBufferSize) PURE;
'};
'
'#undef  INTERFACE
'#define INTERFACE   ISearchContext
'
'DECLARE_INTERFACE_IID_(ISearchContext, IUnknown, "09F656A2-41AF-480C-88F7-16CC0D164615")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG, AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG, Release) (THIS) PURE;
'
'    ' *** ISearchContext methods ***
'    STDMETHOD(GetSearchUrl)(THIS_ __out BSTR * pbstrSearchUrl) PURE;
'    STDMETHOD(GetSearchText)(THIS_ __out BSTR * pbstrSearchText) PURE;
'    STDMETHOD(GetSearchStyle)(THIS_ __out DWORD * pdwSearchStyle) PURE;
'};
'
'#undef  INTERFACE
'#define INTERFACE   IURLSearchHook2
'
'DECLARE_INTERFACE_IID_(IURLSearchHook2, IURLSearchHook, "5ee44da4-6d32-46e3-86bc-07540dedd0e0")
'{
'    ' *** IURLSearchHook2 methods ***
'    STDMETHOD(TranslateWithSearchContext)(THIS_ __out_ecount(cchBufferSize) LPWSTR lpwszSearchURL, DWORD cchBufferSize, __in_opt ISearchContext * pSearchContext) PURE;
'};

'===========================================================================
'
' INewShortcutHook Interface
'
'===========================================================================

'#undef  INTERFACE
'#define INTERFACE   INewShortcutHookA
'
'DECLARE_INTERFACE_IID_(INewShortcutHookA, IUnknown, "000214e1-0000-0000-c000-000000000046")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG, AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG, Release) (THIS) PURE;
'
'    ' *** INewShortcutHook methods ***
'    STDMETHOD(SetReferent)(THIS_ LPCSTR pcszReferent, HWND hwnd) PURE;
'    STDMETHOD(GetReferent)(THIS_ __out_ecount(cchReferent) LPSTR pszReferent, int cchReferent) PURE;
'    STDMETHOD(SetFolder)(THIS_ LPCSTR pcszFolder) PURE;
'    STDMETHOD(GetFolder)(THIS_ __out_ecount(cchFolder) LPSTR pszFolder, int cchFolder) PURE;
'    STDMETHOD(GetName)(THIS_ __out_ecount(cchName) LPSTR pszName, int cchName) PURE;
'    STDMETHOD(GetExtension)(THIS_ __out_ecount(cchExtension) LPSTR pszExtension, int cchExtension) PURE;
'};
'
'#undef  INTERFACE
'#define INTERFACE   INewShortcutHookW
'
'DECLARE_INTERFACE_IID_(INewShortcutHookW, IUnknown, "000214f7-0000-0000-c000-000000000046")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG, AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG, Release) (THIS) PURE;
'
'    ' *** INewShortcutHook methods ***
'    STDMETHOD(SetReferent)(THIS_ LPCWSTR pcszReferent, HWND hwnd) PURE;
'    STDMETHOD(GetReferent)(THIS_ __out_ecount(cchReferent) LPWSTR pszReferent, int cchReferent) PURE;
'    STDMETHOD(SetFolder)(THIS_ LPCWSTR pcszFolder) PURE;
'    STDMETHOD(GetFolder)(THIS_ __out_ecount(cchFolder) LPWSTR pszFolder, int cchFolder) PURE;
'    STDMETHOD(GetName)(THIS_ __out_ecount(cchName) LPWSTR pszName, int cchName) PURE;
'    STDMETHOD(GetExtension)(THIS_ __out_ecount(cchExtension) LPWSTR pszExtension, int cchExtension) PURE;
'};
'
'#IF %DEF(%UNICODE)
'macro INewShortcutHook     = INewShortcutHookW
'macro INewShortcutHookVtbl = INewShortcutHookWVtbl
'#else
'macro INewShortcutHook     = INewShortcutHookA
'macro INewShortcutHookVtbl = INewShortcutHookAVtbl
'#endif

'===========================================================================
'
' ICopyHook Interface
'
'  The copy hook is called whenever file system directories are
'  copy/moved/deleted/renamed via the shell.  It is also called by the shell
'  on changes of status of printers.
'
'  Clients register their id under STRREG_SHEX_COPYHOOK for file system hooks
'  and STRREG_SHEx_PRNCOPYHOOK for printer hooks.
'  the CopyCallback is called prior to the action, so the hook has the chance
'  to allow, deny or cancel the operation by returning the falues:
'     IDYES  -  means allow the operation
'     IDNO   -  means disallow the operation on this file, but continue with
'              any other operations (eg. batch copy)
'     IDCANCEL - means disallow the current operation and cancel any pending
'              operations
'
'   arguments to the CopyCallback
'      hwnd - window to use for any UI
'      wFunc - what operation is being done
'      wFlags - and flags (FOF_*) set in the initial call to the file operation
'      pszSrcFile - name of the source file
'      dwSrcAttribs - file attributes of the source file
'      pszDestFile - name of the destiation file (for move and renames)
'      dwDestAttribs - file attributes of the destination file
'
'
'===========================================================================

'#undef  INTERFACE
'#define INTERFACE   ICopyHookA
'
'DECLARE_INTERFACE_IID_(ICopyHookA, IUnknown, "000214EF-0000-0000-c000-000000000046")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** ICopyHook methods ***
'    STDMETHOD_(UINT,CopyCallback) (THIS_ HWND hwnd, UINT wFunc, UINT wFlags, LPCSTR pszSrcFile, DWORD dwSrcAttribs,
'                                   LPCSTR pszDestFile, DWORD dwDestAttribs) PURE;
'};
'
'#undef  INTERFACE
'#define INTERFACE   ICopyHookW
'
'DECLARE_INTERFACE_IID_(ICopyHookW, IUnknown, "000214FC-0000-0000-c000-000000000046")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** ICopyHook methods ***
'    STDMETHOD_(UINT,CopyCallback) (THIS_ HWND hwnd, UINT wFunc, UINT wFlags, LPCWSTR pszSrcFile, DWORD dwSrcAttribs,
'                                   LPCWSTR pszDestFile, DWORD dwDestAttribs) PURE;
'};
'
'#IF %DEF(%UNICODE)
'macro ICopyHook     = ICopyHookW
'macro ICopyHookVtbl = ICopyHookWVtbl
'macro LPCOPYHOOK    = LPCOPYHOOKW
'#else
'macro ICopyHook     = ICopyHookA
'macro ICopyHookVtbl = ICopyHookAVtbl
'macro LPCOPYHOOK    = LPCOPYHOOKA
'#endif
'
' IFileViewer, IFileViewerSite not supported as of win2k
#IF (%NTDDI_VERSION < %NTDDI_WIN2K)

'===========================================================================
'
' IFileViewerSite Interface
'
'===========================================================================

'#undef  INTERFACE
'#define INTERFACE   IFileViewerSite
'
'DECLARE_INTERFACE_IID_(IFileViewerSite, IUnknown, "000214f3-0000-0000-c000-000000000046")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** IFileViewerSite methods ***
'    STDMETHOD(SetPinnedWindow) (THIS_ HWND hwnd) PURE;
'    STDMETHOD(GetPinnedWindow) (THIS_ __out HWND *phwnd) PURE;
'};

'===========================================================================
'
' IFileViewer Interface
'
' Implemented in a FileViewer component object.  Used to tell a
' FileViewer to PrintTo or to view, the latter happening though
' ShowInitialize and Show.  The filename is always given to the
' viewer through IPersistFile.
'
'===========================================================================

'TYPE FVSHOWINFO QWORD FILL
'    ' Stuff passed into viewer (in)
'    cbSize AS DWORD            ' Size of structure for future expansion...
'    hwndOwner AS HWND          ' who is the owner window.
'    iShow AS int               ' The show command
'
'    ' Passed in and updated  (in/Out)
'    dwFlags AS DWORD           ' flags
'    rect AS RECT               ' Where to create the window may have defaults
'    punkRel AS IUnknown *      ' Relese this interface when window is visible
'
'    ' Stuff that might be returned from viewer (out)
'    strNewFile[MAX_PATH] AS OLECHAR    ' New File to view.
'
'END TYPE


    ' Define File View Show Info Flags.
%FVSIF_RECT      = &H00000001      ' The rect variable has valid data.
%FVSIF_PINNED    = &H00000002      ' We should Initialize pinned
%FVSIF_NEWFAILED = &H08000000      ' The new file passed back failed
                                   ' to be viewed.

%FVSIF_NEWFILE   = &H80000000???   ' A new file to view has been returned
%FVSIF_CANVIEWIT = &H40000000      ' The viewer can view it.

'#undef  INTERFACE
'#define INTERFACE   IFileViewerA
'
'DECLARE_INTERFACE_IID(IFileViewerA, "000214f0-0000-0000-c000-000000000046")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** IFileViewer methods ***
'    STDMETHOD(ShowInitialize) (THIS_ __in LPFILEVIEWERSITE lpfsi) PURE;
'    STDMETHOD(Show) (THIS_ __in LPFVSHOWINFO pvsi) PURE;
'    STDMETHOD(PrintTo) (THIS_ __in_opt LPSTR pszDriver, BOOL fSuppressUI) PURE;
'};
'
'#undef  INTERFACE
'#define INTERFACE   IFileViewerW
'
'DECLARE_INTERFACE_IID(IFileViewerW, "000214f8-0000-0000-c000-000000000046")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** IFileViewer methods ***
'    STDMETHOD(ShowInitialize) (THIS_ __in LPFILEVIEWERSITE lpfsi) PURE;
'    STDMETHOD(Show) (THIS_ __in LPFVSHOWINFO pvsi) PURE;
'    STDMETHOD(PrintTo) (THIS_ __in_opt LPWSTR pszDriver, BOOL fSuppressUI) PURE;
'};
'
'#IF %DEF(%UNICODE)
'macro IFileViewer=IFileViewerW
'macro LPFILEVIEWER=LPFILEVIEWERW
'#else
'macro IFileViewer=IFileViewerA
'macro LPFILEVIEWER=LPFILEVIEWERA
'#endif

' IFileViewer, IFileViewerSite not supported as of win2k
#ENDIF ' (%NTDDI_VERSION < %NTDDI_WIN2K)


'--------------------------------------------------------------------------
'
' Command/menuitem IDs
'
'  The explorer dispatches WM_COMMAND messages based on the range of
' command/menuitem IDs. All the IDs of menuitems that the view (right
' pane) inserts must be in FCIDM_SHVIEWFIRST/LAST (otherwise, the explorer
' won't dispatch them). The view should not deal with any menuitems
' in FCIDM_BROWSERFIRST/LAST (otherwise, it won't work with the future
' version of the shell).
'
'  FCIDM_SHVIEWFIRST/LAST      for the right pane (IShellView)
'  FCIDM_BROWSERFIRST/LAST     for the explorer frame (IShellBrowser)
'  FCIDM_GLOBAL/LAST           for the explorer's submenu IDs
'
'--------------------------------------------------------------------------

%FCIDM_SHVIEWFIRST  = &H0000
%FCIDM_SHVIEWLAST   = &H7fff
%FCIDM_BROWSERFIRST = &Ha000??
%FCIDM_BROWSERLAST  = &Hbf00??
%FCIDM_GLOBALFIRST  = &H8000??
%FCIDM_GLOBALLAST   = &H9fff??

'
' Global submenu IDs and separator IDs
'
%FCIDM_MENU_FILE             = (%FCIDM_GLOBALFIRST+&H0000)
%FCIDM_MENU_EDIT             = (%FCIDM_GLOBALFIRST+&H0040)
%FCIDM_MENU_VIEW             = (%FCIDM_GLOBALFIRST+&H0080)
%FCIDM_MENU_VIEW_SEP_OPTIONS = (%FCIDM_GLOBALFIRST+&H0081)
%FCIDM_MENU_TOOLS            = (%FCIDM_GLOBALFIRST+&H00c0) ' for Win9x compat
%FCIDM_MENU_TOOLS_SEP_GOTO   = (%FCIDM_GLOBALFIRST+&H00c1) ' for Win9x compat
%FCIDM_MENU_HELP             = (%FCIDM_GLOBALFIRST+&H0100)
%FCIDM_MENU_FIND             = (%FCIDM_GLOBALFIRST+&H0140)
%FCIDM_MENU_EXPLORE          = (%FCIDM_GLOBALFIRST+&H0150)
%FCIDM_MENU_FAVORITES        = (%FCIDM_GLOBALFIRST+&H0170)

'--------------------------------------------------------------------------
' control IDs known to the view
'--------------------------------------------------------------------------

%FCIDM_TOOLBAR    = (%FCIDM_BROWSERFIRST + 0)
%FCIDM_STATUS     = (%FCIDM_BROWSERFIRST + 1)

#IF (%WIN32_IE >= &H0400)
'--------------------------------------------------------------------------
'
' The resource id of the offline cursor
' This cursor is avaialble in shdocvw.dll
%IDC_OFFLINE_HAND        = 103
#IF (%WIN32_IE >= %WIN32_IE_IE70)
%IDC_PANTOOL_HAND_OPEN   = 104
%IDC_PANTOOL_HAND_CLOSED = 105
#ENDIF
'
'--------------------------------------------------------------------------
#ENDIF


' SBCMDID_GETPANE - not necessarily in order
%PANE_NONE       = &HFFFFFFFF??? ' ((DWORD)-1)
%PANE_ZONE       = 1
%PANE_OFFLINE    = 2
%PANE_PRINTER    = 3
%PANE_SSL        = 4
%PANE_NAVIGATION = 5
%PANE_PROGRESS   = 6
#IF (%WIN32_IE >= %WIN32_IE_IE60)
%PANE_PRIVACY    = 7
#ENDIF

DECLARE FUNCTION ILClone LIB "Shell32.dll" ALIAS "ILClone" _
    (pidl AS ITEMIDLIST) AS DWORD

DECLARE FUNCTION ILCloneFirst LIB "Shell32.dll" ALIAS "ILCloneFirst" _
    (pidl AS ITEMIDLIST) AS DWORD

DECLARE FUNCTION ILCombine LIB "Shell32.dll" ALIAS "ILCombine" _
    (pidl1 AS ITEMIDLIST, pidl2 AS ITEMIDLIST) AS DWORD

DECLARE SUB ILFree LIB "Shell32.dll" ALIAS "ILFree" _
    (pidl AS ITEMIDLIST)

DECLARE FUNCTION ILGetNext LIB "Shell32.dll" ALIAS "ILGetNext" _
    (pidl AS ITEMIDLIST) AS DWORD

DECLARE FUNCTION ILGetSize LIB "Shell32.dll" ALIAS "ILGetSize" _
    (pidl AS ITEMIDLIST) AS DWORD

DECLARE FUNCTION ILFindChild LIB "Shell32.dll" ALIAS "ILFindChild" _
    (pidlParent AS ITEMIDLIST, pidlChild AS ITEMIDLIST) AS DWORD

DECLARE FUNCTION ILFindLastID LIB "Shell32.dll" ALIAS "ILFindLastID" _
    (pidl AS ITEMIDLIST) AS DWORD

DECLARE FUNCTION ILRemoveLastID LIB "Shell32.dll" ALIAS "ILRemoveLastID" _
    (pidl AS ITEMIDLIST) AS LONG

DECLARE FUNCTION ILIsEqual LIB "Shell32.dll" ALIAS "ILIsEqual" _
    (pidl1 AS ITEMIDLIST, pidl2 AS ITEMIDLIST) AS LONG

DECLARE FUNCTION ILIsParent LIB "Shell32.dll" ALIAS "ILIsParent" _
    (pidl1 AS ITEMIDLIST, pidl2 AS ITEMIDLIST, _
    BYVAL fImmediate AS LONG) AS LONG

DECLARE FUNCTION ILSaveToStream LIB "Shell32.dll" ALIAS "ILSaveToStream" _
    (pstm AS ANY, pidl AS ITEMIDLIST) AS LONG

DECLARE FUNCTION ILLoadFromStream LIB "Shell32.dll" ALIAS "ILLoadFromStream" _
    (pstm AS ANY, pidl AS ITEMIDLIST) AS LONG

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
DECLARE FUNCTION ILLoadFromStreamEx LIB "Shell32.dll" _
    ALIAS "ILLoadFromStreamEx" (pstm AS ANY, pidl AS ITEMIDLIST) AS LONG
#ENDIF ' NTDDI_VISTA

#IF (%WIN32_IE >= &H0400)

DECLARE FUNCTION ILCreateFromPathA LIB "Shell32.dll" _
    ALIAS "ILCreateFromPathA" (pszPath AS ASCIIZ) AS DWORD

DECLARE FUNCTION ILCreateFromPathW LIB "Shell32.dll" _
    ALIAS "ILCreateFromPathW" (pszPath AS WSTRINGZ) AS DWORD

#IF %DEF(%NO_WRAPPERS_FOR_ILCREATEFROMPATH)
DECLARE FUNCTION ILCreateFromPath LIB "Shell32.dll" _
    ALIAS "ILCreateFromPath" (pszPath AS ANY) AS DWORD
#ELSE
#IF %DEF(%UNICODE)
DECLARE FUNCTION ILCreateFromPath LIB "Shell32.dll" _
    ALIAS "ILCreateFromPathW" (pszPath AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION ILCreateFromPath LIB "Shell32.dll" _
    ALIAS "ILCreateFromPathA" (pszPath AS ASCIIZ) AS DWORD
#ENDIF  ' NOT %UNICODE
#ENDIF  ' %NO_WRAPPERS_FOR_ILCREATEFROMPATH

#ENDIF  ' (%WIN32_IE >= &H0400)

DECLARE FUNCTION SHILCreateFromPath LIB "Shell32.dll" _
    ALIAS "SHILCreateFromPath" (pszPath AS WSTRINGZ, ppidl AS ANY, _
    rgfInOut AS DWORD) AS LONG

'#define VOID_OFFSET(pv, cb)     ((void*)(((BYTE*)(pv))+(cb)))

DECLARE FUNCTION ILCloneFull LIB "Shell32.dll" ALIAS "ILClone" _
    (pidl AS ITEMIDLIST) AS DWORD

DECLARE FUNCTION ILCloneChild LIB "Shell32.dll" ALIAS "ILCloneFirst" _
    (pidl AS ITEMIDLIST) AS DWORD

'#define ILSkip(pidl, cb)        ((PUIDLIST_RELATIVE)VOID_OFFSET((pidl), (cb)))
'#define ILNext(pidl)            ILSkip(pidl, (pidl)->mkid.cb)
'
'#define ILIsAligned(pidl)       (((DWORD_PTR)(pidl) & (sizeof(void*) - 1)) == 0)
'
'#define ILIsEmpty(pidl)         ((pidl) == NULL || (pidl)->mkid.cb==0)

' ILIsChild does not guarantee that pidl is non-null or non-empty.
'#define ILIsChild(pidl)         (ILIsEmpty(pidl) || ILIsEmpty(ILNext(pidl)))

DECLARE FUNCTION ILAppendID LIB "Shell32.dll" ALIAS "ILAppendID" _
    (pidl AS ITEMIDLIST, pmkid AS SHITEMID, BYVAL fAppend AS LONG) _
    AS DWORD

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

' SHGetPathFromIDListEx returns a win32 file system path for the item in the name space.
'  and has a few special cases that include returning UNC printer names too!
MACRO GPFIDL_FLAGS_enum=LONG
ENUM GPFIDL_FLAGS SINGULAR
    GPFIDL_DEFAULT     ' normal Win32 file name, servers & drive roots included
    GPFIDL_ALTNAME     ' short file name
    GPFIDL_UNCPRINTER  ' include UNC printer names too (non file system item)
END ENUM

#ENDIF  ' #IF (%NTDDI_VERSION >= %NTDDI_VISTA)

DECLARE FUNCTION SHGetPathFromIDListEx LIB "Shell32.dll" _
    ALIAS "SHGetPathFromIDListEx" (BYVAL pidl AS ITEMIDLIST PTR, _
    pszPath AS WSTRINGZ, BYVAL cchPath AS DWORD, BYVAL uOpts AS DWORD) _
    AS LONG

'
' SHGetPathFromIDListW is the old version of SHGetPathFromIDListEx that assumes
' the size of the buffer (MAX_PATH).
' The pidl should point to a file system object.

DECLARE FUNCTION SHGetPathFromIDListA LIB "Shell32.dll" _
    ALIAS "SHGetPathFromIDListA" (BYVAL pidl AS ITEMIDLIST PTR, _
    pszPath AS ASCIIZ) AS LONG

'
' SHGetPathFromIDListW is the old version of SHGetPathFromIDListEx that assumes the size of the buffer (MAX_PATH).
' The pidl should point to a file system object.

DECLARE FUNCTION SHGetPathFromIDListW LIB "Shell32.dll" _
    ALIAS "SHGetPathFromIDListW" (BYVAL pidl AS ITEMIDLIST PTR, _
    pszPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHGetPathFromIDList LIB "Shell32.dll" _
    ALIAS "SHGetPathFromIDListW" (BYVAL pidl AS ITEMIDLIST PTR, _
    pszPath AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION SHGetPathFromIDList LIB "Shell32.dll" _
    ALIAS "SHGetPathFromIDListA" (BYVAL pidl AS ITEMIDLIST PTR, _
    pszPath AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SHCreateDirectory LIB "Shell32.dll" _
    ALIAS "SHCreateDirectory" (BYVAL hwnd AS DWORD, pszPath AS WSTRINGZ) _
    AS LONG

DECLARE FUNCTION SHCreateDirectoryExA LIB "Shell32.dll" _
    ALIAS "SHCreateDirectoryExA" (BYVAL hwnd AS DWORD, pszPath AS ASCIIZ, _
    psa AS SECURITY_ATTRIBUTES) AS LONG

DECLARE FUNCTION SHCreateDirectoryExW LIB "Shell32.dll" _
    ALIAS "SHCreateDirectoryExW" (BYVAL hwnd AS DWORD, pszPath AS WSTRINGZ, _
    psa AS SECURITY_ATTRIBUTES) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHCreateDirectoryEx LIB "Shell32.dll" _
    ALIAS "SHCreateDirectoryExW" (BYVAL hwnd AS DWORD, pszPath AS WSTRINGZ, _
    psa AS SECURITY_ATTRIBUTES) AS LONG
#ELSE
DECLARE FUNCTION SHCreateDirectoryEx LIB "Shell32.dll" _
    ALIAS "SHCreateDirectoryExA" (BYVAL hwnd AS DWORD, pszPath AS ASCIIZ, _
    psa AS SECURITY_ATTRIBUTES) AS LONG
#ENDIF ' NOT %UNICODE

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%OFASI_EDIT          = &H0001
%OFASI_OPENDESKTOP   = &H0002
#ENDIF

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)

DECLARE FUNCTION SHOpenFolderAndSelectItems LIB "Shell32.dll" _
    ALIAS "SHOpenFolderAndSelectItems" _
    (BYVAL pidlFolder AS ITEMIDLIST PTR, BYVAL cidl AS DWORD, _
    BYVAL apidl AS ITEMIDLIST, BYVAL dwFlags AS DWORD) AS LONG

'  deprecated because of parameter ambiguity
'  call SHCreateItemWithParent() or SHCreateItemFromIDList() instead

DECLARE FUNCTION SHCreateShellItem LIB "Shell32.dll" _
    ALIAS "SHCreateShellItem" (BYVAL pidlParent AS ITEMIDLIST PTR, _
    psfParent AS ANY, BYVAL pidl AS ITEMID_CHILD PTR, ppsi AS ANY) AS LONG

#ENDIF

'
' SHGetSpecialFolderLocation
'
'  Caller should use SHGetMalloc to obtain an allocator that can free the pidl
'
' registry entries for special paths are kept in :
$REGSTR_PATH_SPECIAL_FOLDERS="Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders"
$$REGSTR_PATH_SPECIAL_FOLDERS="Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders"$$


%CSIDL_DESKTOP                   = &H0000        ' <desktop>
%CSIDL_INTERNET                  = &H0001        ' Internet Explorer (icon on desktop)
%CSIDL_PROGRAMS                  = &H0002        ' Start Menu\Programs
%CSIDL_CONTROLS                  = &H0003        ' My Computer\Control Panel
%CSIDL_PRINTERS                  = &H0004        ' My Computer\Printers
%CSIDL_PERSONAL                  = &H0005        ' My Documents
%CSIDL_FAVORITES                 = &H0006        ' <user name>\Favorites
%CSIDL_STARTUP                   = &H0007        ' Start Menu\Programs\Startup
%CSIDL_RECENT                    = &H0008        ' <user name>\Recent
%CSIDL_SENDTO                    = &H0009        ' <user name>\SendTo
%CSIDL_BITBUCKET                 = &H000a        ' <desktop>\Recycle Bin
%CSIDL_STARTMENU                 = &H000b        ' <user name>\Start Menu
%CSIDL_MYDOCUMENTS               = %CSIDL_PERSONAL '  Personal was just a silly name for My Documents
%CSIDL_MYMUSIC                   = &H000d        ' "My Music" folder
%CSIDL_MYVIDEO                   = &H000e        ' "My Videos" folder
%CSIDL_DESKTOPDIRECTORY          = &H0010        ' <user name>\Desktop
%CSIDL_DRIVES                    = &H0011        ' My Computer
%CSIDL_NETWORK                   = &H0012        ' Network Neighborhood (My Network Places)
%CSIDL_NETHOOD                   = &H0013        ' <user name>\nethood
%CSIDL_FONTS                     = &H0014        ' windows\fonts
%CSIDL_TEMPLATES                 = &H0015
%CSIDL_COMMON_STARTMENU          = &H0016        ' All Users\Start Menu
%CSIDL_COMMON_PROGRAMS           = &H0017        ' All Users\Start Menu\Programs
%CSIDL_COMMON_STARTUP            = &H0018        ' All Users\Startup
%CSIDL_COMMON_DESKTOPDIRECTORY   = &H0019        ' All Users\Desktop
%CSIDL_APPDATA                   = &H001a        ' <user name>\Application Data
%CSIDL_PRINTHOOD                 = &H001b        ' <user name>\PrintHood

#IF NOT %DEF(%CSIDL_LOCAL_APPDATA)
%CSIDL_LOCAL_APPDATA             = &H001c        ' <user name>\Local Settings\Applicaiton Data (non roaming)
#ENDIF ' CSIDL_LOCAL_APPDATA

%CSIDL_ALTSTARTUP                = &H001d        ' non localized startup
%CSIDL_COMMON_ALTSTARTUP         = &H001e        ' non localized common startup
%CSIDL_COMMON_FAVORITES          = &H001f

#IF NOT %DEF(%SHFOLDER_H)
%CSIDL_INTERNET_CACHE            = &H0020
%CSIDL_COOKIES                   = &H0021
%CSIDL_HISTORY                   = &H0022
%CSIDL_COMMON_APPDATA            = &H0023        ' All Users\Application Data
%CSIDL_WINDOWS                   = &H0024        ' GetWindowsDirectory()
%CSIDL_SYSTEM                    = &H0025        ' GetSystemDirectory()
%CSIDL_PROGRAM_FILES             = &H0026        ' C:\Program Files
%CSIDL_MYPICTURES                = &H0027        ' C:\Program Files\My Pictures
#ENDIF ' %SHFOLDER_H

%CSIDL_PROFILE                   = &H0028        ' USERPROFILE
%CSIDL_SYSTEMX86                 = &H0029        ' x86 system directory on RISC
%CSIDL_PROGRAM_FILESX86          = &H002a        ' x86 C:\Program Files on RISC

#IF NOT %DEF(%SHFOLDER_H)
%CSIDL_PROGRAM_FILES_COMMON      = &H002b        ' C:\Program Files\Common
#ENDIF ' %SHFOLDER_H

%CSIDL_PROGRAM_FILES_COMMONX86   = &H002c        ' x86 Program Files\Common on RISC
%CSIDL_COMMON_TEMPLATES          = &H002d        ' All Users\Templates

#IF NOT %DEF(%SHFOLDER_H)
%CSIDL_COMMON_DOCUMENTS          = &H002e        ' All Users\Documents
%CSIDL_COMMON_ADMINTOOLS         = &H002f        ' All Users\Start Menu\Programs\Administrative Tools
%CSIDL_ADMINTOOLS                = &H0030        ' <user name>\Start Menu\Programs\Administrative Tools
#ENDIF ' %SHFOLDER_H

%CSIDL_CONNECTIONS               = &H0031        ' Network and Dial-up Connections
%CSIDL_COMMON_MUSIC              = &H0035        ' All Users\My Music
%CSIDL_COMMON_PICTURES           = &H0036        ' All Users\My Pictures
%CSIDL_COMMON_VIDEO              = &H0037        ' All Users\My Video
%CSIDL_RESOURCES                 = &H0038        ' Resource Direcotry

#IF NOT %DEF(%SHFOLDER_H)
%CSIDL_RESOURCES_LOCALIZED       = &H0039        ' Localized Resource Direcotry
#ENDIF ' %SHFOLDER_H

%CSIDL_COMMON_OEM_LINKS          = &H003a        ' Links to All Users OEM specific apps
%CSIDL_CDBURN_AREA               = &H003b        ' USERPROFILE\Local Settings\Application Data\Microsoft\CD Burning
' unused                           &H003c
%CSIDL_COMPUTERSNEARME           = &H003d        ' Computers Near Me (computered from Workgroup membership)

#IF NOT %DEF(%SHFOLDER_H)
%CSIDL_FLAG_CREATE               = &H8000??      ' combine with CSIDL_ value to force folder creation in SHGetFolderPath()
#ENDIF ' %SHFOLDER_H

%CSIDL_FLAG_DONT_VERIFY          = &H4000        ' combine with CSIDL_ value to return an unverified folder path
%CSIDL_FLAG_DONT_UNEXPAND        = &H2000        ' combine with CSIDL_ value to avoid unexpanding environment variables
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
%CSIDL_FLAG_NO_ALIAS             = &H1000        ' combine with CSIDL_ value to insure non-alias versions of the pidl
%CSIDL_FLAG_PER_USER_INIT        = &H0800        ' combine with CSIDL_ value to indicate per-user init (eg. upgrade)
#ENDIF  ' %NTDDI_WINXP
%CSIDL_FLAG_MASK                 = &HFF00??      ' mask for all possible flag values

DECLARE FUNCTION SHGetSpecialFolderLocation LIB "Shell32.dll" _
    ALIAS "SHGetSpecialFolderLocation" (BYVAL hwnd AS DWORD, _
    BYVAL csidl AS LONG, ppidl AS ANY) AS LONG

DECLARE FUNCTION SHCloneSpecialIDList LIB "Shell32.dll" _
    ALIAS "SHCloneSpecialIDList" (BYVAL hwnd AS DWORD, BYVAL csidl AS LONG, _
    BYVAL fCreate AS LONG) AS DWORD

DECLARE FUNCTION SHGetSpecialFolderPathA LIB "Shell32.dll" _
    ALIAS "SHGetSpecialFolderPathA" (BYVAL hwnd AS DWORD, _
    pszPath AS ASCIIZ, BYVAL csidl AS LONG, BYVAL fCreate AS LONG) AS LONG

DECLARE FUNCTION SHGetSpecialFolderPathW LIB "Shell32.dll" _
    ALIAS "SHGetSpecialFolderPathW" (BYVAL hwnd AS DWORD, _
    pszPath AS WSTRINGZ, BYVAL csidl AS LONG, BYVAL fCreate AS LONG) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHGetSpecialFolderPath LIB "Shell32.dll" _
    ALIAS "SHGetSpecialFolderPathW" (BYVAL hwnd AS DWORD, _
    pszPath AS WSTRINGZ, BYVAL csidl AS LONG, BYVAL fCreate AS LONG) AS LONG
#ELSE
DECLARE FUNCTION SHGetSpecialFolderPath LIB "Shell32.dll" _
    ALIAS "SHGetSpecialFolderPathA" (BYVAL hwnd AS DWORD, _
    pszPath AS ASCIIZ, BYVAL csidl AS LONG, BYVAL fCreate AS LONG) AS LONG
#ENDIF ' NOT %UNICODE


#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)

DECLARE SUB SHFlushSFCache LIB "Shell32.dll" ALIAS "SHFlushSFCache" ()

MACRO SHGFP_TYPE_enum=LONG
ENUM SHGFP_TYPE SINGULAR
    SHGFP_TYPE_CURRENT    ' current value for user, verify it exists
    SHGFP_TYPE_DEFAULT    ' default value, may not exist
END ENUM

DECLARE FUNCTION SHGetFolderPathA LIB "Shell32.dll" _
    ALIAS "SHGetFolderPathA" (BYVAL hwnd AS DWORD, BYVAL csidl AS LONG, _
    BYVAL hToken AS DWORD, BYVAL dwFlags AS DWORD, pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION SHGetFolderPathW LIB "Shell32.dll" _
    ALIAS "SHGetFolderPathW" (BYVAL hwnd AS DWORD, BYVAL csidl AS LONG, _
    BYVAL hToken AS DWORD, BYVAL dwFlags AS DWORD, pszPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHGetFolderPath LIB "Shell32.dll" _
    ALIAS "SHGetFolderPathW" (BYVAL hwnd AS DWORD, BYVAL csidl AS LONG, _
    BYVAL hToken AS DWORD, BYVAL dwFlags AS DWORD, pszPath AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION SHGetFolderPath LIB "Shell32.dll" _
    ALIAS "SHGetFolderPathA" (BYVAL hwnd AS DWORD, BYVAL csidl AS LONG, _
    BYVAL hToken AS DWORD, BYVAL dwFlags AS DWORD, pszPath AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SHGetFolderLocation LIB "Shell32.dll" _
    ALIAS "SHGetFolderLocation" (BYVAL hwnd AS DWORD, BYVAL csidl AS LONG, _
    BYVAL hToken AS DWORD, BYVAL dwFlags AS DWORD, ppidl AS ANY) AS LONG

DECLARE FUNCTION SHSetFolderPathA LIB "Shell32.dll" ALIAS "SHSetFolderPathA" _
    (BYVAL csidl AS LONG, BYVAL hToken AS DWORD, BYVAL dwFlags AS DWORD, _
    pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION SHSetFolderPathW LIB "Shell32.dll" ALIAS "SHSetFolderPathW" _
    (BYVAL csidl AS LONG, BYVAL hToken AS DWORD, BYVAL dwFlags AS DWORD, _
    pszPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHSetFolderPath LIB "Shell32.dll" ALIAS "SHSetFolderPathW" _
    (BYVAL csidl AS LONG, BYVAL hToken AS DWORD, BYVAL dwFlags AS DWORD, _
    pszPath AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION SHSetFolderPath LIB "Shell32.dll" ALIAS "SHSetFolderPathA" _
    (BYVAL csidl AS LONG, BYVAL hToken AS DWORD, BYVAL dwFlags AS DWORD, _
    pszPath AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF ' #IF (%NTDDI_VERSION >= %NTDDI_WIN2K)


#IF (%NTDDI_VERSION >= %NTDDI_WINXP)

DECLARE FUNCTION SHGetFolderPathAndSubDirA LIB "Shell32.dll" _
    ALIAS "SHGetFolderPathAndSubDirA" (BYVAL hwnd AS DWORD, _
    BYVAL csidl AS LONG, BYVAL hToken AS DWORD, BYVAL dwFlags AS DWORD, _
    pszSubDir AS ASCIIZ, pszPath AS ASCIIZ) AS LONG

DECLARE FUNCTION SHGetFolderPathAndSubDirW LIB "Shell32.dll" _
    ALIAS "SHGetFolderPathAndSubDirW" (BYVAL hwnd AS DWORD, _
    BYVAL csidl AS LONG, BYVAL hToken AS DWORD, BYVAL dwFlags AS DWORD, _
    pszSubDir AS WSTRINGZ, pszPath AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHGetFolderPathAndSubDir LIB "Shell32.dll" _
    ALIAS "SHGetFolderPathAndSubDirW" (BYVAL hwnd AS DWORD, _
    BYVAL csidl AS LONG, BYVAL hToken AS DWORD, BYVAL dwFlags AS DWORD, _
    pszSubDir AS WSTRINGZ, pszPath AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION SHGetFolderPathAndSubDir LIB "Shell32.dll" _
    ALIAS "SHGetFolderPathAndSubDirA" (BYVAL hwnd AS DWORD, _
    BYVAL csidl AS LONG, BYVAL hToken AS DWORD, BYVAL dwFlags AS DWORD, _
    pszSubDir AS ASCIIZ, pszPath AS ASCIIZ) AS LONG
#ENDIF ' NOT %UNICODE
#ENDIF

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

'
'  flags for Known Folder APIs
'

MACRO KNOWN_FOLDER_FLAG_enum=LONG
ENUM KNOWN_FOLDER_FLAG BITS SINGULAR
    KF_FLAG_DEFAULT

    KF_FLAG_SIMPLE_IDLIST       = &H00000100  ' Build simple pidl

    KF_FLAG_NOT_PARENT_RELATIVE ' Get the not-parent-relative default path. Only valid with KF_FLAG_DEFAULT_PATH

    KF_FLAG_DEFAULT_PATH        ' Get the default path, will also verify folder existence unless KF_FLAG_DONT_VERIFY is also specified
    KF_FLAG_INIT                ' Initialize the folder with desktop.ini settings
                                ' If folder can not be initialized then function will return failure and no folder path will be returned
                                ' If folder is located on the network the function may take long time to execute

    KF_FLAG_NO_ALIAS            ' Get file system based IDList if available. If the flag is not specified the Known Folder API
                                ' will try to return aliased IDList by default. Example for FOLDERID_Documents -
                                ' Aliased - [desktop]\[user]\[Documents] - exact location is determined by shell namespace layout and might change
                                ' Non aliased - [desktop]\[computer]\[disk_c]\[users]\[user]\[Documents] - location is determined by folder location in the file system

    KF_FLAG_DONT_UNEXPAND       ' Set folder path as is and do not try to substitute parts of the path with environments variables.
                                ' If flag is not specified then Known Folder will try to replace parts of the path with some
                                ' known environment variables (%USERPROFILE%, %APPDATA% etc.)

    KF_FLAG_DONT_VERIFY         ' If this flag is specified then the folder path is returned and no verification is performed
                                ' Use this flag is you want to get folder's path (IDList) and do not need to verify folder's existence
                                '
                                ' If this flag is NOT specified then Known Folder API will try to verify that the folder exists
                                '     If folder does not exist or can not be accessed then function will return failure and no folder path (IDList) will be returned
                                '     If folder is located on the network the function may take long time to execute

    KF_FLAG_CREATE              ' Make sure that the folder already exists or create it and apply security specified in folder definition
                                ' If folder can not be created then function will return failure and no folder path (IDList) will be returned
                                ' If folder is located on the network the function may take long time to execute

    KF_FLAGS_ALIAS_ONLY         = &H80000000??? ' only return the aliased IDLists, don't fallback to file system path
END ENUM

DECLARE FUNCTION SHGetKnownFolderIDList LIB "Shell32.dll" _
    ALIAS "SHGetKnownFolderIDList" (rfid AS KNOWNFOLDERID, _
    BYVAL dwFlags AS DWORD, BYVAL hToken AS DWORD, ppidl AS ANY) AS LONG

DECLARE FUNCTION SHSetKnownFolderPath LIB "Shell32.dll" _
    ALIAS "SHSetKnownFolderPath" (rfid AS KNOWNFOLDERID, _
    BYVAL dwFlags AS DWORD, BYVAL hToken AS DWORD, pszPath AS WSTRINGZ) AS LONG

DECLARE FUNCTION SHGetKnownFolderPath LIB "Shell32.dll" _
    ALIAS "SHGetKnownFolderPath" (rfid AS KNOWNFOLDERID, _
    BYVAL dwFlags AS DWORD, BYVAL hToken AS DWORD, pszPath AS ANY) AS LONG

#ENDIF  ' %NTDDI_VISTA

#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
' returns IShellItem or related interface

DECLARE FUNCTION SHGetKnownFolderItem LIB "Shell32.dll" _
    ALIAS "SHGetKnownFolderItem" (rfid AS KNOWNFOLDERID, _
    BYVAL flags AS LONG, _   ' KNOWN_FOLDER_FLAG
    BYVAL hToken AS DWORD, _ ' HANDLE
    riid AS GUID, _          ' REFIID = IID PTR = GUID PTR
    ppv AS ANY) _
    AS LONG

#ENDIF ' %NTDDI_WIN7


#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)

%FCS_READ                    = &H00000001
%FCS_FORCEWRITE              = &H00000002
%FCS_WRITE                   = (%FCS_READ OR %FCS_FORCEWRITE)

%FCS_FLAG_DRAGDROP           =  2

' Mask which values have been retrieved or being set.
%FCSM_VIEWID                 = &H00000001    ' deprecated
%FCSM_WEBVIEWTEMPLATE        = &H00000002  ' deprecated
%FCSM_INFOTIP                = &H00000004
%FCSM_CLSID                  = &H00000008
%FCSM_ICONFILE               = &H00000010
%FCSM_LOGO                   = &H00000020
%FCSM_FLAGS                  = &H00000040

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

' Used by SHGetSetFolderCustomSettings
TYPE SHFOLDERCUSTOMSETTINGS QWORD FILL
    dwSize             AS DWORD
    dwMask             AS DWORD   ' IN/OUT  Which Attributes to Get/Set
    pvid               AS DWORD   ' SHELLVIEWID*   ' OUT - if dwReadWrite is FCS_READ, IN - otherwise
    ' The folder's WebView template path
    pszWebViewTemplate AS WSTRINGZ PTR   ' OUT - if dwReadWrite is FCS_READ, IN - otherwise
    cchWebViewTemplate AS DWORD          ' IN - Specifies the size of the buffer pointed to by pszWebViewTemplate
                                         ' Ignored if dwReadWrite is FCS_READ
    pszWebViewTemplateVersion AS WSTRINGZ PTR ' currently IN only
    ' Infotip for the folder
    pszInfoTip         AS WSTRINGZ PTR   ' OUT - if dwReadWrite is FCS_READ, IN - otherwise
    cchInfoTip         AS DWORD          ' IN - Specifies the size of the buffer pointed to by pszInfoTip
                                         ' Ignored if dwReadWrite is FCS_READ
    ' CLSID that points to more info in the registry
    pclsid             AS GUID PTR       ' CLSID*   ' OUT - if dwReadWrite is FCS_READ, IN - otherwise
    ' Other flags for the folder. Takes FCS_FLAG_* values
    dwFlags            AS DWORD          ' OUT - if dwReadWrite is FCS_READ, IN - otherwise


    pszIconFile        AS WSTRINGZ PTR   ' OUT - if dwReadWrite is FCS_READ, IN - otherwise
    cchIconFile        AS DWORD          ' IN - Specifies the size of the buffer pointed to by pszIconFile
                                         ' Ignored if dwReadWrite is FCS_READ

    iIconIndex         AS LONG           ' OUT - if dwReadWrite is FCS_READ, IN - otherwise

    pszLogo            AS WSTRINGZ PTR   ' OUT - if dwReadWrite is FCS_READ, IN - otherwise
    cchLogo            AS DWORD          ' IN - Specifies the size of the buffer pointed to by pszIconFile
                                         ' Ignored if dwReadWrite is FCS_READ
END TYPE

' Gets/Sets the Folder Custom Settings for pszPath based on dwReadWrite.
' dwReadWrite can be FCS_READ/FCS_WRITE/FCS_FORCEWRITE

DECLARE FUNCTION SHGetSetFolderCustomSettings LIB "Shell32.dll" _
    ALIAS "SHGetSetFolderCustomSettings" (pfcs AS SHFOLDERCUSTOMSETTINGS, _
    pszPath AS WSTRINGZ, BYVAL dwReadWrite AS DWORD) AS LONG

#ENDIF  ' %NTDDI_VISTA
#ENDIF  ' %NTDDI_WIN2K

'-------------------------------------------------------------------------
'
' SHBrowseForFolder API
'
'
'-------------------------------------------------------------------------

DECLARE FUNCTION BFFCALLBACK (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, _
    BYVAL lParam AS LONG, BYVAL lpData AS LONG) AS LONG

UNION BROWSEINFO_legacy
    lpfn         AS DWORD
    lpfnCallback AS DWORD
END UNION

TYPE BROWSEINFOA
    hwndOwner      AS DWORD
    pidlRoot       AS ITEMIDLIST PTR
    pszDisplayName AS ASCIIZ PTR ' Return display name of item selected.
    lpszTitle      AS ASCIIZ PTR ' text to go in the banner over the tree.
    ulFlags        AS DWORD      ' Flags that control the return stuff
    BROWSEINFO_legacy
    lParam         AS LONG       ' extra info that's passed back in callbacks
    iImage         AS LONG       ' output var: where to return the Image index.
END TYPE

TYPE BROWSEINFOW
    hwndOwner      AS DWORD
    pidlRoot       AS ITEMIDLIST PTR
    pszDisplayName AS WSTRINGZ PTR ' Return display name of item selected.
    lpszTitle      AS WSTRINGZ PTR ' text to go in the banner over the tree.
    ulFlags        AS DWORD        ' Flags that control the return stuff
    BROWSEINFO_legacy
    lParam         AS LONG       ' extra info that's passed back in callbacks
    iImage         AS LONG       ' output var: where to return the Image index.
END TYPE

#IF %DEF(%UNICODE)
TYPE BROWSEINFO
    BROWSEINFOW
END TYPE
#ELSE
TYPE BROWSEINFO
    BROWSEINFOA
END TYPE
#ENDIF

' Browsing for directory.
%BIF_RETURNONLYFSDIRS    = &H00000001   ' For finding a folder to start document searching
%BIF_DONTGOBELOWDOMAIN   = &H00000002   ' For starting the Find Computer
%BIF_STATUSTEXT          = &H00000004   ' Top of the dialog has 2 lines of text for BROWSEINFO.lpszTitle and one line if
                                        ' this flag is set.  Passing the message BFFM_SETSTATUSTEXTA to the hwnd can set the
                                        ' rest of the text.  This is not used with BIF_USENEWUI and BROWSEINFO.lpszTitle gets
                                        ' all three lines of text.
%BIF_RETURNFSANCESTORS   = &H00000008
%BIF_EDITBOX             = &H00000010   ' Add an editbox to the dialog
%BIF_VALIDATE            = &H00000020   ' insist on valid result (or CANCEL)

%BIF_NEWDIALOGSTYLE      = &H00000040   ' Use the new dialog layout with the ability to resize
                                        ' Caller needs to call OleInitialize() before using this API

%BIF_USENEWUI            = (%BIF_NEWDIALOGSTYLE OR %BIF_EDITBOX)

%BIF_BROWSEINCLUDEURLS   = &H00000080   ' Allow URLs to be displayed or entered. (Requires BIF_USENEWUI)
%BIF_UAHINT              = &H00000100   ' Add a UA hint to the dialog, in place of the edit box. May not be combined with BIF_EDITBOX
%BIF_NONEWFOLDERBUTTON   = &H00000200   ' Do not add the "New Folder" button to the dialog.  Only applicable with BIF_NEWDIALOGSTYLE.
%BIF_NOTRANSLATETARGETS  = &H00000400   ' don't traverse target as shortcut

%BIF_BROWSEFORCOMPUTER   = &H00001000   ' Browsing for Computers.
%BIF_BROWSEFORPRINTER    = &H00002000   ' Browsing for Printers
%BIF_BROWSEINCLUDEFILES  = &H00004000   ' Browsing for Everything
%BIF_SHAREABLE           = &H00008000   ' sharable resources displayed (remote shares, requires BIF_USENEWUI)
%BIF_BROWSEFILEJUNCTIONS = &H00010000   ' allow folder junctions like zip files and libraries to be browsed

' message from browser
%BFFM_INITIALIZED       =  1
%BFFM_SELCHANGED        =  2
%BFFM_VALIDATEFAILEDA   =  3   ' lParam:szPath ret:1(cont),0(EndDialog)
%BFFM_VALIDATEFAILEDW   =  4   ' lParam:wzPath ret:1(cont),0(EndDialog)
%BFFM_IUNKNOWN          =  5   ' provides IUnknown to client. lParam: IUnknown*

' messages to browser
%BFFM_SETSTATUSTEXTA     = (%WM_USER + 100)
%BFFM_ENABLEOK           = (%WM_USER + 101)
%BFFM_SETSELECTIONA      = (%WM_USER + 102)
%BFFM_SETSELECTIONW      = (%WM_USER + 103)
%BFFM_SETSTATUSTEXTW     = (%WM_USER + 104)
%BFFM_SETOKTEXT          = (%WM_USER + 105) ' Unicode only
%BFFM_SETEXPANDED        = (%WM_USER + 106) ' Unicode only

DECLARE FUNCTION SHBrowseForFolderA LIB "Shell32.dll" _
    ALIAS "SHBrowseForFolderA" (lpbi AS BROWSEINFOA) AS DWORD

DECLARE FUNCTION SHBrowseForFolderW LIB "Shell32.dll" _
    ALIAS "SHBrowseForFolderW" (lpbi AS BROWSEINFOW) AS DWORD

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHBrowseForFolder LIB "Shell32.dll" _
    ALIAS "SHBrowseForFolderW" (lpbi AS BROWSEINFOW) AS DWORD
%BFFM_SETSTATUSTEXT  = %BFFM_SETSTATUSTEXTW
%BFFM_SETSELECTION   = %BFFM_SETSELECTIONW

%BFFM_VALIDATEFAILED = %BFFM_VALIDATEFAILEDW
#ELSE
DECLARE FUNCTION SHBrowseForFolder LIB "Shell32.dll" _
    ALIAS "SHBrowseForFolderA" (lpbi AS BROWSEINFOA) AS DWORD
%BFFM_SETSTATUSTEXT  = %BFFM_SETSTATUSTEXTA
%BFFM_SETSELECTION   = %BFFM_SETSELECTIONA

%BFFM_VALIDATEFAILED = %BFFM_VALIDATEFAILEDA
#ENDIF

'-------------------------------------------------------------------------
'
' SHLoadInProc
'
'   This function is no longer implemented. It will return E_NOTIMPL.
'
'-------------------------------------------------------------------------

DECLARE FUNCTION SHLoadInProc LIB "SHELL32.DLL" ALIAS "SHLoadInProc" ( _
    rclsid AS GUID) AS LONG


'-------------------------------------------------------------------------
'
' Internet Shortcut Object
'
'-------------------------------------------------------------------------
' Cmds for CGID_ShortCut
#IF (%WIN32_IE >= %WIN32_IE_IE501)

%ISHCUTCMDID_DOWNLOADICON      = 0
%ISHCUTCMDID_INTSHORTCUTCREATE = 1
#IF (%WIN32_IE >= %WIN32_IE_IE70)
%ISHCUTCMDID_COMMITHISTORY     = 2
%ISHCUTCMDID_SETUSERAWURL      = 3
#ENDIF

%CMDID_INTSHORTCUTCREATE = %ISHCUTCMDID_INTSHORTCUTCREATE
#ENDIF

' Bindctx key, passed to IShellFolder::ParseDiplayName.  Provides dbfolder with extra
' data, besides the name, necessary for the parse. the object in the bind context implements
' IPropertyStore and provides a fixed set of properties
$$STR_PARSE_WITH_PROPERTIES = "ParseWithProperties"$$

' Bindctx key, passed to IShellFolder::ParseDisplayName(). used to pass the original item that
' is being re-parsed. that item is stored as an IShellItem that supports IParentAndItem,
' and should be the un-aliased form of the item.
$$STR_PARSE_PARTIAL_IDLIST  = "ParseOriginalItem"$$


'
' Helper function which returns a IShellFolder interface to the desktop
' folder. This is equivalent to call CoCreateInstance with CLSID_ShellDesktop.
'
'  CoCreateInstance(CLSID_Desktop, NULL, CLSCTX_INPROC, IID_PPV_ARGS(&pshf));
'
DECLARE FUNCTION SHGetDesktopFolder LIB "Shell32.dll" _
    ALIAS "SHGetDesktopFolder" (ppshf AS ANY) AS LONG

' this interface is deprecated, data sources should
' implement IShellFolder2::GetDetailsOf()/GetDetailsEx() instead

'#undef  INTERFACE
'#define INTERFACE   IShellDetails
'
'DECLARE_INTERFACE_IID_(IShellDetails, IUnknown, "000214EC-0000-0000-c000-000000000046")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** IShellDetails methods ***
'    STDMETHOD(GetDetailsOf)(THIS_ PCUITEMID_CHILD pidl, UINT iColumn, __out SHELLDETAILS *pDetails) PURE;
'    STDMETHOD(ColumnClick)(THIS_ UINT iColumn) PURE;
'};


'
' IObjMgr::Append(punk)
'   This function adds an object to the end of a list of objects.
'
' IObjMgr::Remove(punk)
'   This function removes an object from a list of objects.
'
' This is implemented by CLSID_ACLMulti so each AutoComplete List
' (CLSID_ACLHistory, CLSID_ACListISF, CLSID_ACLMRU) can be added.
' CLSID_ACLMulti's IEnumString will then be the union of the results
' from the COM Objects added.
'

'#undef INTERFACE
'#define INTERFACE IObjMgr
'
'DECLARE_INTERFACE_IID_(IObjMgr, IUnknown, "00BB2761-6A77-11D0-A535-00C04FD7D062")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG, AddRef) (THIS) PURE;
'    STDMETHOD_(ULONG, Release) (THIS) PURE;
'
'    ' *** IObjMgr specific methods ***
'    STDMETHOD(Append) (THIS_ __in IUnknown *punk) PURE;
'    STDMETHOD(Remove) (THIS_ __in IUnknown *punk) PURE;
'};


' ICurrentWorkingDirectory::GetDirectory(LPWSTR pwzPath, DWORD cchSize)
'   This function gets the Current Working Directory from a COM object that
'   stores such state.
'
' ICurrentWorkingDirectory::SetDirectory(LPCWSTR pwzPath)
'   This function sets the Current Working Directory of a COM object that
'   stores such state.
'
' This function can be used generically.  One COM object that implements it
' is CLSID_ACListISF so that the AutoComplete engine can complete relative
' paths.  SetDirectory() will set the "Current Working Directory" and
' AutoComplete with then complete both absolute and relative paths.
' For Example, if ::SetDirectory(L"C:\Program Files") is called, then
' the user can AutoComplete "..\winnt".  In order to set the current
' working directory for non-file system paths, "ftp:'ftp.microsoft.com/" or
' "Control Panel" for example, use IPersistFolder.
'

'#undef INTERFACE
'#define INTERFACE ICurrentWorkingDirectory
'
'DECLARE_INTERFACE_IID_(ICurrentWorkingDirectory, IUnknown, "91956D21-9276-11d1-921A-006097DF5BD4")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG, AddRef) (THIS) PURE;
'    STDMETHOD_(ULONG, Release) (THIS) PURE;
'
'    ' *** ICurrentWorkingDirectory specific methods ***
'    STDMETHOD(GetDirectory) (THIS_ __out_ecount(cchSize) LPWSTR pwzPath, DWORD cchSize) PURE;
'    STDMETHOD(SetDirectory) (THIS_ LPCWSTR pwzPath) PURE;
'};


'
' IACList::Expand(LPCWSTR)
'   This function tells an autocomplete list to expand a specific string.
'
' If the user enters a multi-level path, AutoComplete (CLSID_AutoComplete)
' will use this interface to tell the "AutoComplete Lists" where to expand
' the results.
'
' For Example, if the user enters "C:\Program Files\Micros", AutoComplete
' first completely enumerate the "AutoComplete Lists" via IEnumString.  Then it
' will call the "AutoComplete Lists" with IACList::Expand(L"C:\Program Files").
' It will then enumerate the IEnumString interface again to get results in
' that directory.
'

'#undef INTERFACE
'#define INTERFACE IACList
'
'DECLARE_INTERFACE_IID_(IACList, IUnknown, "77A130B0-94FD-11D0-A544-00C04FD7d062")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG, AddRef) (THIS) PURE;
'    STDMETHOD_(ULONG, Release) (THIS) PURE;
'
'    ' *** IACList specific methods ***
'    STDMETHOD(Expand) (THIS_ LPCWSTR pszExpand) PURE;
'};

' This interface exists to allow the caller to set filter criteria
' for an AutoComplete List.  AutoComplete Lists generates the list of
' possible AutoComplete completions.  CLSID_ACListISF is one AutoComplete
' List COM object that implements this interface.

'#undef INTERFACE
'#define INTERFACE IACList2

MACRO AUTOCOMPLETELISTOPTIONS_enum=LONG
ENUM AUTOCOMPLETELISTOPTIONS BITS SINGULAR
    ACLO_NONE               ' don't enumerate anything
    ACLO_CURRENTDIR         ' enumerate current directory
    ACLO_MYCOMPUTER         ' enumerate MyComputer
    ACLO_DESKTOP            ' enumerate Desktop Folder
    ACLO_FAVORITES          ' enumerate Favorites Folder
    ACLO_FILESYSONLY        ' enumerate only the file system
#IF (%WIN32_IE >= %WIN32_IE_IE60)
    ACLO_FILESYSDIRS        ' enumerate only the file system dirs, UNC shares,
                            ' and UNC servers.
#ENDIF
#IF (%WIN32_IE >= %WIN32_IE_IE70)
    ACLO_VIRTUALNAMESPACE   ' enumeeate on the virtual namespace
#ENDIF
END ENUM

'DECLARE_INTERFACE_IID_(IACList2, IACList, "470141a0-5186-11d2-bbb6-0060977b464c")
'{
'    ' *** IACList2 specific methods ***
'    STDMETHOD(SetOptions)(THIS_ DWORD dwFlag) PURE;
'    STDMETHOD(GetOptions)(THIS_ __out DWORD* pdwFlag) PURE;
'};


'
'    INTERFACE: IProgressDialog
'
'    DESCRIPTION:
'        CLSID_ProgressDialog/IProgressDialog exist to allow a caller to create
'    a progress dialog, set it's title, animation, text lines, progress, and
'    it will do all the work of updating on a background thread, being modeless,
'    handling the user canceling the operation, and estimating the time remaining
'    until the operation completes.
'
'    USAGE:
'        This is how the dialog is used during operations that require progress
'    and the ability to cancel:
'    {
'        DWORD dwComplete, dwTotal;
'        IProgressDialog * ppd;
'        CoCreateInstance(CLSID_ProgressDialog, NULL, CLSCTX_INPROC_SERVER, IID_IProgressDialog, (void **)&ppd);
'        ppd->SetTitle(L"My Slow Operation");                                ' Set the title of the dialog.
'        ppd->SetAnimation(hInstApp, IDA_OPERATION_ANIMATION);               ' Set the animation to play.
'        ppd->StartProgressDialog(hwndParent, punk, PROGDLG_AUTOTIME, NULL); ' Display and enable automatic estimated time remaining.
'        ppd->SetCancelMsg(L"Please wait while the current operation is cleaned up", NULL);   ' Will only be displayed if Cancel button is pressed.
'
'        dwComplete = 0;
'        dwTotal = CalcTotalUnitsToDo();
'
'        ' Reset because CalcTotalUnitsToDo() took a long time and the estimated time
'        ' is based on the time between ::StartProgressDialog() and the first
'        ' ::SetProgress() call.
'        ppd->Timer(PDTIMER_RESET, NULL);
'
'        for (nIndex = 0; nIndex < nTotal; nIndex++)
'        {
'            if (TRUE == ppd->HasUserCancelled())
'                break;
'
'            ppd->SetLine(2, L"I'm processing item n", FALSE, NULL);
'            dwComplete += DoSlowOperation();
'
'            ppd->SetProgress(dwCompleted, dwTotal);
'        }
'
'        ppd->StopProgressDialog();
'        ppd->Release();
'    }
'-----------------------------------------------------------------------------

' Flags for IProgressDialog::StartProgressDialog() (dwFlags)
' The flag space includes OPPROGDLG_ and PROGDLG_ values, please guarantee they don't conflict. See shobjidl.idl for OPPROGDLG_*
%PROGDLG_NORMAL          = &H00000000      ' default normal progress dlg behavior
%PROGDLG_MODAL           = &H00000001      ' the dialog is modal to its hwndParent (default is modeless)
%PROGDLG_AUTOTIME        = &H00000002      ' automatically updates the "Line3" text with the "time remaining" (you cant call SetLine3 if you passs this!)
%PROGDLG_NOTIME          = &H00000004      ' we dont show the "time remaining" if this is set. We need this if dwTotal < dwCompleted for sparse files
%PROGDLG_NOMINIMIZE      = &H00000008      ' Do not have a minimize button in the caption bar.
%PROGDLG_NOPROGRESSBAR   = &H00000010      ' Don't display the progress bar
#IF (%WIN32_IE >= %WIN32_IE_IE70)
%PROGDLG_MARQUEEPROGRESS = &H00000020      ' Use marquee progress (comctl32 v6 required)
%PROGDLG_NOCANCEL        = &H00000040      ' No cancel button (operation cannot be canceled) (use sparingly)
#ENDIF

' Time Actions (dwTimerAction)
%PDTIMER_RESET       = &H00000001       ' Reset the timer so the progress will be calculated from now until the first ::SetProgress() is called so
                                        ' those this time will correspond to the values passed to ::SetProgress().  Only do this before ::SetProgress() is called.
#IF (%WIN32_IE >= %WIN32_IE_IE70)
%PDTIMER_PAUSE       = &H00000002       ' Progress has been suspended
%PDTIMER_RESUME      = &H00000003       ' Progress has resumed
#ENDIF


'#undef  INTERFACE
'#define INTERFACE   IProgressDialog
'
'DECLARE_INTERFACE_IID_(IProgressDialog, IUnknown, "EBBC7C04-315E-11d2-B62F-006097DF5BD4")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** IProgressDialog specific methods
'    STDMETHOD(StartProgressDialog)(THIS_ __in_opt HWND hwndParent, __in_opt IUnknown * punkEnableModless, DWORD dwFlags, __reserved LPCVOID pvResevered) PURE;
'    STDMETHOD(StopProgressDialog)(THIS) PURE;
'    STDMETHOD(SetTitle)(THIS_ LPCWSTR pwzTitle) PURE;
'    STDMETHOD(SetAnimation)(THIS_ HINSTANCE hInstAnimation, UINT idAnimation) PURE;
'    STDMETHOD_(BOOL,HasUserCancelled) (THIS) PURE;
'    STDMETHOD(SetProgress)(THIS_ DWORD dwCompleted, DWORD dwTotal) PURE;
'    STDMETHOD(SetProgress64)(THIS_ ULONGLONG ullCompleted, ULONGLONG ullTotal) PURE;
'    STDMETHOD(SetLine)(THIS_ DWORD dwLineNum, LPCWSTR pwzString, BOOL fCompactPath, __reserved LPCVOID pvResevered) PURE;
'    STDMETHOD(SetCancelMsg)(THIS_ LPCWSTR pwzCancelMsg, __reserved LPCVOID pvResevered) PURE;
'    STDMETHOD(Timer)(THIS_ DWORD dwTimerAction, __reserved LPCVOID pvResevered) PURE;
'};


'==========================================================================
' IDockingWindowSite/IDockingWindow/IDockingWindowFrame interfaces
' IInputObjectSite/IInputObject interfaces
'
'  These interfaces allow us (or ISVs) to install/update external Internet
' Toolbar for IE and the shell. The frame will simply get the CLSID from
' registry (to be defined) and CoCreateInstance it.
'
'==========================================================================


'-------------------------------------------------------------------------
'
' IDockingWindowSite interface
'
'   A site implements this interface so the object can negotiate for
' and inquire about real estate on the site.
'
' [Member functions]
'
' IDockingWindowSite::GetBorderDW(punkObj, prcBorder)
'   Site returns the bounding rectangle of the given source object
'   (punkObj).
'
' IDockingWindowSite::RequestBorderSpaceDW(punkObj, pbw)
'   Object requests that the site makes room for it, as specified in
'   *pbw.
'
' IDockingWindowSite::SetBorderSpaceDW(punkObj, pbw)
'   Object requests that the site set the border spacing to the size
'   specified in *pbw.
'
'-------------------------------------------------------------------------


'#undef  INTERFACE
'#define INTERFACE   IDockingWindowSite
'
'DECLARE_INTERFACE_IID_(IDockingWindowSite, IOleWindow, "2a342fc2-7b26-11d0-8ca9-00a0c92dbfe8")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** IOleWindow methods ***
'    STDMETHOD(GetWindow) (THIS_ HWND * lphwnd) PURE;
'    STDMETHOD(ContextSensitiveHelp) (THIS_ BOOL fEnterMode) PURE;
'
'    ' *** IDockingWindowSite methods ***
'    STDMETHOD(GetBorderDW) (THIS_ IUnknown* punkObj, LPRECT prcBorder) PURE;
'    STDMETHOD(RequestBorderSpaceDW) (THIS_ IUnknown* punkObj, LPCBORDERWIDTHS pbw) PURE;
'    STDMETHOD(SetBorderSpaceDW) (THIS_ IUnknown* punkObj, LPCBORDERWIDTHS pbw) PURE;
'};



'-------------------------------------------------------------------------
'
' IDockingWindowFrame interface
'
' [Member functions]
'
' IDockingWindowFrame::AddToolbar(punkSrc, pwszItem, dwReserved)
'
' IDockingWindowFrame::RemoveToolbar(punkSrc, dwRemoveFlags)
'
' IDockingWindowFrame::FindToolbar(pwszItem, riid, ppv)
'
'-------------------------------------------------------------------------


' flags for RemoveToolbar
%DWFRF_NORMAL            = &H0000
%DWFRF_DELETECONFIGDATA  = &H0001


' flags for AddToolbar
%DWFAF_HIDDEN    = &H0001   ' add hidden
%DWFAF_GROUP1    = &H0002   ' insert at end of group 1
%DWFAF_GROUP2    = &H0004   ' insert at end of group 2
%DWFAF_AUTOHIDE  = &H0010   ' The toolbar will be subject to AutoHide in Full Screen mode


'#undef  INTERFACE
'#define INTERFACE   IDockingWindowFrame
'
'DECLARE_INTERFACE_IID_(IDockingWindowFrame, IOleWindow, "47d2657a-7b27-11d0-8ca9-00a0c92dbfe8")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** IOleWindow methods ***
'    STDMETHOD(GetWindow) (THIS_ HWND * lphwnd) PURE;
'    STDMETHOD(ContextSensitiveHelp) (THIS_ BOOL fEnterMode) PURE;
'
'    ' *** IDockingWindowFrame methods ***
'    STDMETHOD(AddToolbar) (THIS_ IUnknown* punkSrc, LPCWSTR pwszItem, DWORD dwAddFlags) PURE;
'    STDMETHOD(RemoveToolbar) (THIS_ IUnknown* punkSrc, DWORD dwRemoveFlags) PURE;
'    STDMETHOD(FindToolbar) (THIS_ LPCWSTR pwszItem, REFIID riid, void **ppv) PURE;
'};



#IF (%WIN32_IE >= &H0400)

' ***************** IThumbnailCapture
' CaptureThumbnail : takes an IHTMLDocument2 and returns a thumbnail of specified
'                    size as an hbitmap
'

'#undef  INTERFACE
'#define INTERFACE   IThumbnailCapture
'
'DECLARE_INTERFACE_IID_(IThumbnailCapture, IUnknown, "4ea39266-7211-409f-b622-f63dbd16c533")
'{
'    ' *** IThumbnailCapture methods ***
'    STDMETHOD (CaptureThumbnail)    ( THIS_ const SIZE * pMaxSize,
'                                      IUnknown * pHTMLDoc2,
'                                      HBITMAP * phbmThumbnail ) PURE;
'};

#ENDIF


#IF (%NTDDI_VERSION >= %NTDDI_WIN2K AND %NTDDI_VERSION < %NTDDI_VISTA)

TYPE ENUMSHELLIMAGESTOREDATA QWORD FILL
    szPath      AS WSTRINGZ * %MAX_PATH
    ftTimeStamp AS FILETIME
END TYPE

'#undef  INTERFACE
'#define INTERFACE   IEnumShellImageStore
'
'DECLARE_INTERFACE_IID_( IEnumShellImageStore, IUnknown, "6DFD582B-92E3-11D1-98A3-00C04FB687DA" )
'{
'    STDMETHOD ( QueryInterface ) ( THIS_ REFIID riid, void **ppv ) PURE;
'    STDMETHOD_( ULONG, AddRef ) ( THIS ) PURE;
'    STDMETHOD_( ULONG, Release ) ( THIS ) PURE;
'
'    STDMETHOD ( Reset ) ( THIS ) PURE;
'    STDMETHOD ( Next ) ( THIS_ ULONG celt, PENUMSHELLIMAGESTOREDATA * prgElt, ULONG * pceltFetched ) PURE;
'    STDMETHOD ( Skip ) ( THIS_ ULONG celt ) PURE;
'    STDMETHOD ( Clone ) ( THIS_ IEnumShellImageStore ** ppEnum ) PURE;
'};
'


' flags used to determine the capabilities of the storage for the images
%SHIMSTCAPFLAG_LOCKABLE  = &H0001  ' does the store require/support locking
%SHIMSTCAPFLAG_PURGEABLE = &H0002  ' does the store require dead items purging externally ?

'#undef  INTERFACE
'#define INTERFACE   IShellImageStore
'
'' this interface is used to manipulate the Image cache. It can potentially be used
'' in a free threaded manner in conjunction with the Lock parameter to Open and close
'DECLARE_INTERFACE_IID_( IShellImageStore, IUnknown, "48C8118C-B924-11D1-98D5-00C04FB687DA" )
'{
'    STDMETHOD ( QueryInterface )( THIS_ REFIID riid, void **ppv ) PURE;
'    STDMETHOD_( ULONG, AddRef ) ( THIS ) PURE;
'    STDMETHOD_( ULONG, Release ) ( THIS ) PURE;
'
'    ' if the lock parameter is used, then all other calls into
'    ' open and/or create will block until the lock is released.
'    STDMETHOD ( Open ) ( THIS_ DWORD dwMode, DWORD * pdwLock ) PURE;
'    STDMETHOD ( Create ) ( THIS_ DWORD dwMode, DWORD * pdwLock ) PURE;
'
'    ' if the lock is passed to either of these two methods, it releases the lock
'    ' once the operation is complete.
'    STDMETHOD ( ReleaseLock ) ( THIS_ DWORD const * pdwLock ) PURE;
'    STDMETHOD ( Close ) ( THIS_ DWORD const * pdwLock ) PURE;
'    STDMETHOD ( Commit ) ( THIS_ DWORD const * pdwLock ) PURE;
'    STDMETHOD ( IsLocked ) ( THIS ) PURE;
'
'    STDMETHOD ( GetMode ) ( THIS_ DWORD * pdwMode ) PURE;
'    STDMETHOD ( GetCapabilities ) ( THIS_ DWORD * pdwCapMask ) PURE;
'
'    STDMETHOD ( AddEntry ) ( THIS_ LPCWSTR pszName, const FILETIME * pftTimeStamp, DWORD dwMode, HBITMAP hImage ) PURE;
'    STDMETHOD ( GetEntry ) ( THIS_ LPCWSTR pszName, DWORD dwMode, HBITMAP * phImage ) PURE;
'    STDMETHOD ( DeleteEntry ) ( THIS_ LPCWSTR pszName ) PURE;
'    STDMETHOD ( IsEntryInStore ) ( THIS_ LPCWSTR pszName, FILETIME * pftTimeStamp ) PURE;
'
'    STDMETHOD ( Enum ) ( THIS_ LPENUMSHELLIMAGESTORE * ppEnum ) PURE;
'};

#ENDIF  ' (%NTDDI_VERSION >= %NTDDI_WIN2K AND %NTDDI_VERSION < %NTDDI_VISTA)

#IF (%WIN32_IE >= &H0400)

''  IShellFolderBand

' Field mask
%ISFB_MASK_STATE          = &H00000001 ' TRUE if dwStateMask and dwState is valid
%ISFB_MASK_BKCOLOR        = &H00000002 ' TRUE if crBkgnd field is valid
%ISFB_MASK_VIEWMODE       = &H00000004 ' TRUE if wViewMode field is valid
%ISFB_MASK_SHELLFOLDER    = &H00000008
%ISFB_MASK_IDLIST         = &H00000010
%ISFB_MASK_COLORS         = &H00000020 ' TRUE if crXXXX fields are valid (except bkgnd)

%ISFB_STATE_DEFAULT       = &H00000000
%ISFB_STATE_DEBOSSED      = &H00000001
%ISFB_STATE_ALLOWRENAME   = &H00000002
%ISFB_STATE_NOSHOWTEXT    = &H00000004 ' TRUE if _fNoShowText
%ISFB_STATE_CHANNELBAR    = &H00000010 ' TRUE if we want NavigateTarget support
%ISFB_STATE_QLINKSMODE    = &H00000020 ' TRUE if we want to turn off drag & drop onto content items
%ISFB_STATE_FULLOPEN      = &H00000040 ' TRUE if band should maximize when opened
%ISFB_STATE_NONAMESORT    = &H00000080 ' TRUE if band should _not_ sort icons by name
%ISFB_STATE_BTNMINSIZE    = &H00000100 ' TRUE if band should report min thickness of button

%ISFBVIEWMODE_SMALLICONS   = &H0001
%ISFBVIEWMODE_LARGEICONS   = &H0002
#IF (%WIN32_IE < %WIN32_IE_IE70)
%ISFBVIEWMODE_LOGOS        = &H0003
#ENDIF

'TYPE BANDINFOSFB QWORD FILL
'    dwMask      AS DWORD             ' [in] ISFB_MASK mask of valid fields from crBkgnd on
'    dwStateMask AS DWORD             ' [in] ISFB_STATE mask of dwState bits being set/queried
'    dwState     AS DWORD             ' [in/out] ISFB_STATE bits
'    crBkgnd     AS COLORREF          ' [in/out]
'    crBtnLt     AS COLORREF          ' [in/out]
'    crBtnDk     AS COLORREF          ' [in/out]
'    wViewMode   AS WORD              ' [in/out]
'    wAlign      AS WORD              ' not used (yet)
'    psf         AS IShellFolder PTR  ' [out]
'    pidl        AS PIDLIST_ABSOLUTE  ' [out]
'END TYPE

'#undef INTERFACE
'#define INTERFACE IShellFolderBand
'
'DECLARE_INTERFACE_IID_(IShellFolderBand, IUnknown, "7FE80CC8-C247-11d0-B93A-00A0C90312E1")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** IShellFolderBand Methods ***
'    STDMETHOD(InitializeSFB)(THIS_ __in_opt IShellFolder *psf, __in_opt PCIDLIST_ABSOLUTE pidl) PURE;
'    STDMETHOD(SetBandInfoSFB)(THIS_ __in PBANDINFOSFB pbi) PURE;
'    STDMETHOD(GetBandInfoSFB)(THIS_ __inout PBANDINFOSFB pbi) PURE;
'};

' Command Target IDs
%SFBID_PIDLCHANGED = 0

''  IDeskBarClient

'#undef  INTERFACE
'#define INTERFACE   IDeskBarClient
'
'DECLARE_INTERFACE_IID_(IDeskBarClient, IOleWindow, "EB0FE175-1A3A-11D0-89B3-00A0C90A90AC")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** IOleWindow methods ***
'    STDMETHOD(GetWindow) (THIS_ __out HWND * lphwnd) PURE;
'    STDMETHOD(ContextSensitiveHelp) (THIS_ BOOL fEnterMode) PURE;
'
'    ' *** IDeskBarClient methods ***
'    STDMETHOD(SetDeskBarSite) (THIS_ __in_opt IUnknown* punkSite) PURE;
'    STDMETHOD(SetModeDBC) (THIS_ DWORD dwMode) PURE;
'    STDMETHOD(UIActivateDBC) (THIS_ DWORD dwState) PURE;
'    STDMETHOD(GetSize) (THIS_ DWORD dwWhich, __out LPRECT prc) PURE;
'};

%DBC_GS_IDEAL         =  0  ' get the ideal size
%DBC_GS_SIZEDOWN      =  1  ' clip the height of a rect to a multiple of the rebar's integral size


%DBC_HIDE        = 0 ' Band is hidden (being destroyed)
%DBC_SHOW        = 1 ' Band is visible
%DBC_SHOWOBSCURE = 2 ' Band is completely obscured


%DBCID_EMPTY      = 0  ' bandsite is empty
%DBCID_ONDRAG     = 1  ' (down)DragMoveEnter/Leave vaIn:I4:eDrag
%DBCID_CLSIDOFBAR = 2  ' clsid of bar inside
%DBCID_RESIZE     = 3  ' resize from keyboard
%DBCID_GETBAR     = 4  ' returns vaOut:VT_UNKNOWN of hosting dockbar (IDeskBar)

#ENDIF ' %WIN32_IE > &H0400


#IF (%WIN32_IE >= &H400)
'
' We need to make sure that WININET.H is included before this interface is
' used because the COMPONENT structure uses INTERNET_MAX_URL_LENGTH
'
#IF %DEF(%WININET)
'
'  Flags and structures used by IActiveDesktop
'

TYPE WALLPAPEROPT
    dwSize  AS DWORD       ' size of this Structure.
    dwStyle AS DWORD       ' WPSTYLE_* mentioned above
END TYPE


TYPE COMPONENTSOPT
    dwSize            AS DWORD     'Size of this structure
    fEnableComponents AS LONG      'BOOL: Enable components?
    fActiveDesktop    AS LONG      'BOOL: Active desktop enabled ?
END TYPE


TYPE COMPPOS
    dwSize                AS DWORD  'Size of this structure
    iLeft                 AS LONG   'Left of top-left corner in screen co-ordinates.
    iTop                  AS LONG   'Top of top-left corner in screen co-ordinates.
    dwWidth               AS DWORD  ' Width in pixels.
    dwHeight              AS DWORD  ' Height in pixels.
    izIndex               AS LONG   ' Indicates the Z-order of the component.
    fCanResize            AS LONG   ' Is the component resizeable?
    fCanResizeX           AS LONG   ' Resizeable in X-direction?
    fCanResizeY           AS LONG   ' Resizeable in Y-direction?
    iPreferredLeftPercent AS LONG   'Left of top-left corner as percent of screen width
    iPreferredTopPercent  AS LONG   'Top of top-left corner as percent of screen height
END TYPE


TYPE COMPSTATEINFO
    dwSize      AS DWORD   ' Size of this structure.
    iLeft       AS LONG    ' Left of the top-left corner in screen co-ordinates.
    iTop        AS LONG    ' Top of top-left corner in screen co-ordinates.
    dwWidth     AS DWORD   ' Width in pixels.
    dwHeight    AS DWORD   ' Height in pixels.
    dwItemState AS DWORD   ' State of the component (full-screen mode or split-screen or normal state.
END TYPE



%COMPONENT_TOP = &H3fffffff  ' izOrder value meaning component is at the top


' iCompType values
%COMP_TYPE_HTMLDOC      =  0
%COMP_TYPE_PICTURE      =  1
%COMP_TYPE_WEBSITE      =  2
%COMP_TYPE_CONTROL      =  3
%COMP_TYPE_CFHTML       =  4
%COMP_TYPE_MAX          =  4

' The following is the COMPONENT structure used in IE4.01, IE4.0 and Memphis. It is kept here for compatibility
' reasons.
TYPE IE4COMPONENT
    dwSize           AS DWORD       'Size of this structure
    dwID             AS DWORD       'Reserved: Set it always to zero.
    iComponentType   AS LONG        'One of COMP_TYPE_*
    fChecked         AS LONG        ' Is this component enabled?
    fDirty           AS LONG        ' Had the component been modified and not yet saved to disk?
    fNoScroll        AS LONG        ' Is the component scrollable?
    cpPos            AS COMPPOS     ' Width, height etc.,
    wszFriendlyName  AS WSTRINGZ * %MAX_PATH                  ' Friendly name of component.
    wszSource        AS WSTRINGZ * %INTERNET_MAX_URL_LENGTH   'URL of the component.
    wszSubscribedURL AS WSTRINGZ * %INTERNET_MAX_URL_LENGTH   'Subscribed URL
END TYPE


'
' The following is the new NT5 component structure. Note that the initial portion of this component exactly
' matches the IE4COMPONENT structure. All new fields are added at the bottom and the dwSize field is used to
' distinguish between IE4COMPONENT and the new COMPONENT structures.
'
TYPE COMPONENT
    dwSize           AS DWORD       'Size of this structure
    dwID             AS DWORD       'Reserved: Set it always to zero.
    iComponentType   AS LONG        'One of COMP_TYPE_*
    fChecked         AS LONG        ' Is this component enabled?
    fDirty           AS LONG        ' Had the component been modified and not yet saved to disk?
    fNoScroll        AS LONG        ' Is the component scrollable?
    cpPos            AS COMPPOS     ' Width, height etc.,
    wszFriendlyName  AS WSTRINGZ * %MAX_PATH                  ' Friendly name of component.
    wszSource        AS WSTRINGZ * %INTERNET_MAX_URL_LENGTH   'URL of the component.
    wszSubscribedURL AS WSTRINGZ * %INTERNET_MAX_URL_LENGTH   'Subscribed URL

    'New fields are added below. Everything above here must exactly match the IE4COMPONENT Structure.
    dwCurItemState   AS DWORD          ' Current state of the Component.
    csiOriginal      AS COMPSTATEINFO  ' Original state of the component when it was first added.
    csiRestored      AS COMPSTATEINFO  ' Restored state of the component.
END TYPE



' Defines for dwCurItemState
%IS_NORMAL               = &H00000001
%IS_FULLSCREEN           = &H00000002
%IS_SPLIT                = &H00000004
%IS_VALIDSIZESTATEBITS   = (%IS_NORMAL OR %IS_SPLIT OR %IS_FULLSCREEN)  ' The set of IS_* state bits which define the "size" of the component - these bits are mutually exclusive.
%IS_VALIDSTATEBITS       = (%IS_NORMAL OR %IS_SPLIT OR %IS_FULLSCREEN OR &H80000000??? OR &H40000000)  ' All of the currently defined IS_* bits.

''''''''''''''''''''''
' Flags for IActiveDesktop::ApplyChanges()
%AD_APPLY_SAVE             = &H00000001
%AD_APPLY_HTMLGEN          = &H00000002
%AD_APPLY_REFRESH          = &H00000004
%AD_APPLY_ALL              = (%AD_APPLY_SAVE OR %AD_APPLY_HTMLGEN OR %AD_APPLY_REFRESH)
%AD_APPLY_FORCE            = &H00000008
%AD_APPLY_BUFFERED_REFRESH = &H00000010
%AD_APPLY_DYNAMICREFRESH   = &H00000020

''''''''''''''''''''''
' Flags for IActiveDesktop::GetWallpaper()
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%AD_GETWP_BMP            = &H00000000
%AD_GETWP_IMAGE          = &H00000001
%AD_GETWP_LAST_APPLIED   = &H00000002
#ENDIF

''''''''''''''''''''''
' Flags for IActiveDesktop::GetWallpaperOptions()
'           IActiveDesktop::SetWallpaperOptions()
%WPSTYLE_CENTER     =  0
%WPSTYLE_TILE       =  1
%WPSTYLE_STRETCH    =  2
#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
%WPSTYLE_KEEPASPECT = 3
%WPSTYLE_CROPTOFIT  = 4
%WPSTYLE_MAX        = 5
#ELSE
%WPSTYLE_MAX        = 3
#ENDIF ' %NTDDI_WIN7


''''''''''''''''''''''
' Flags for IActiveDesktop::ModifyComponent()

%COMP_ELEM_TYPE          = &H00000001
%COMP_ELEM_CHECKED       = &H00000002
%COMP_ELEM_DIRTY         = &H00000004
%COMP_ELEM_NOSCROLL      = &H00000008
%COMP_ELEM_POS_LEFT      = &H00000010
%COMP_ELEM_POS_TOP       = &H00000020
%COMP_ELEM_SIZE_WIDTH    = &H00000040
%COMP_ELEM_SIZE_HEIGHT   = &H00000080
%COMP_ELEM_POS_ZINDEX    = &H00000100
%COMP_ELEM_SOURCE        = &H00000200
%COMP_ELEM_FRIENDLYNAME  = &H00000400
%COMP_ELEM_SUBSCRIBEDURL = &H00000800
%COMP_ELEM_ORIGINAL_CSI  = &H00001000
%COMP_ELEM_RESTORED_CSI  = &H00002000
%COMP_ELEM_CURITEMSTATE  = &H00004000

%COMP_ELEM_ALL = (%COMP_ELEM_TYPE OR %COMP_ELEM_CHECKED OR %COMP_ELEM_DIRTY OR                   _
                  %COMP_ELEM_NOSCROLL OR %COMP_ELEM_POS_LEFT OR %COMP_ELEM_SIZE_WIDTH  OR        _
                  %COMP_ELEM_SIZE_HEIGHT OR %COMP_ELEM_POS_ZINDEX OR %COMP_ELEM_SOURCE OR        _
                  %COMP_ELEM_FRIENDLYNAME OR %COMP_ELEM_POS_TOP OR %COMP_ELEM_SUBSCRIBEDURL OR   _
                  %COMP_ELEM_ORIGINAL_CSI OR %COMP_ELEM_RESTORED_CSI OR %COMP_ELEM_CURITEMSTATE)


''''''''''''''''''''''
' Flags for IActiveDesktop::AddDesktopItemWithUI()
MACRO DTI_ADTIWUI_enum=LONG
ENUM DTI_ADTIWUI SINGULAR
    DTI_ADDUI_DEFAULT
    DTI_ADDUI_DISPSUBWIZARD
    DTI_ADDUI_POSITIONITEM
END ENUM


''''''''''''''''''''''
' Flags for IActiveDesktop::AddUrl()
%ADDURL_SILENT           = &H0001


''''''''''''''''''''''
' Default positions for ADI
%COMPONENT_DEFAULT_LEFT    = &HFFFF??
%COMPONENT_DEFAULT_TOP     = &HFFFF??




'
'  Interface for manipulating the Active Desktop.
'

'#undef INTERFACE
'#define INTERFACE IActiveDesktop
'
'DECLARE_INTERFACE_IID_(IActiveDesktop, IUnknown, "f490eb00-1240-11d1-9888-006097deacf9")
'{
'    ' IUnknown methods
'    STDMETHOD (QueryInterface)(THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG, AddRef) ( THIS ) PURE;
'    STDMETHOD_(ULONG, Release) ( THIS ) PURE;
'
'    ' IActiveDesktop methods
'    STDMETHOD (ApplyChanges)(THIS_ DWORD dwFlags) PURE;
'    STDMETHOD (GetWallpaper)(THIS_ __out_ecount(cchWallpaper) LPWSTR pwszWallpaper, UINT cchWallpaper, DWORD dwFlags) PURE;
'    STDMETHOD (SetWallpaper)(THIS_ LPCWSTR pwszWallpaper, DWORD dwReserved) PURE;
'    STDMETHOD (GetWallpaperOptions)(THIS_ __inout LPWALLPAPEROPT pwpo, DWORD dwReserved) PURE;
'    STDMETHOD (SetWallpaperOptions)(THIS_ __in LPCWALLPAPEROPT pwpo, DWORD dwReserved) PURE;
'    STDMETHOD (GetPattern)(THIS_ __out_ecount(cchPattern) LPWSTR pwszPattern, UINT cchPattern, DWORD dwReserved) PURE;
'    STDMETHOD (SetPattern)(THIS_ LPCWSTR pwszPattern, DWORD dwReserved) PURE;
'    STDMETHOD (GetDesktopItemOptions)(THIS_ __inout LPCOMPONENTSOPT pco, DWORD dwReserved) PURE;
'    STDMETHOD (SetDesktopItemOptions)(THIS_ __in LPCCOMPONENTSOPT pco, DWORD dwReserved) PURE;
'    STDMETHOD (AddDesktopItem)(THIS_ __in LPCCOMPONENT pcomp, DWORD dwReserved) PURE;
'    STDMETHOD (AddDesktopItemWithUI)(THIS_ HWND hwnd, __in LPCOMPONENT pcomp, DWORD dwReserved) PURE;
'    STDMETHOD (ModifyDesktopItem)(THIS_ __inout LPCCOMPONENT pcomp, DWORD dwFlags) PURE;
'    STDMETHOD (RemoveDesktopItem)(THIS_ __in LPCCOMPONENT pcomp, DWORD dwReserved) PURE;
'    STDMETHOD (GetDesktopItemCount)(THIS_ __out LPINT lpiCount, DWORD dwReserved) PURE;
'    STDMETHOD (GetDesktopItem)(THIS_ int nComponent, __inout LPCOMPONENT pcomp, DWORD dwReserved) PURE;
'    STDMETHOD (GetDesktopItemByID)(THIS_ ULONG_PTR dwID, __inout LPCOMPONENT pcomp, DWORD dwReserved) PURE;
'    STDMETHOD (GenerateDesktopItemHtml)(THIS_ LPCWSTR pwszFileName, __in LPCOMPONENT pcomp, DWORD dwReserved) PURE;
'    STDMETHOD (AddUrl)(THIS_ HWND hwnd, LPCWSTR pszSource, __in LPCOMPONENT pcomp, DWORD dwFlags) PURE;
'    STDMETHOD (GetDesktopItemBySource)(THIS_ LPCWSTR pwszSource, __inout LPCOMPONENT pcomp, DWORD dwReserved) PURE;
'};

' Flags for SetSafeMode
%SSM_CLEAR   = &H0000
%SSM_SET     = &H0001
%SSM_REFRESH = &H0002
%SSM_UPDATE  = &H0004

' Flags for Set/GetScheme
%SCHEME_DISPLAY  = &H0001
%SCHEME_EDIT     = &H0002
%SCHEME_LOCAL    = &H0004
%SCHEME_GLOBAL   = &H0008
%SCHEME_REFRESH  = &H0010
%SCHEME_UPDATE   = &H0020
%SCHEME_DONOTUSE = &H0040 ' used to be SCHEME_ENUMERATE; no longer supported
%SCHEME_CREATE   = &H0080

'#undef INTERFACE
'#define INTERFACE IActiveDesktopP
'
'DECLARE_INTERFACE_IID_(IActiveDesktopP, IUnknown, "52502EE0-EC80-11D0-89AB-00C04FC2972D")
'{
'    ' IUnknown methods
'    STDMETHOD (QueryInterface)(THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG, AddRef) ( THIS ) PURE;
'    STDMETHOD_(ULONG, Release) ( THIS ) PURE;
'
'    ' IActiveDesktopP methods
'    STDMETHOD (SetSafeMode)(THIS_ DWORD dwFlags) PURE;
'    STDMETHOD (EnsureUpdateHTML)(THIS) PURE;
'    STDMETHOD (SetScheme)(THIS_ LPCWSTR pwszSchemeName, DWORD dwFlags) PURE;
'    STDMETHOD (GetScheme)(THIS_ __out_ecount(*lpdwcchBuffer) LPWSTR pwszSchemeName, __inout DWORD *lpdwcchBuffer, DWORD dwFlags) PURE;
'    '
'};

'Flags for GetObjectFlags
%GADOF_DIRTY    = &H00000001

'#undef INTERFACE
'#define INTERFACE IADesktopP2
'
'DECLARE_INTERFACE_IID_(IADesktopP2, IUnknown, "B22754E2-4574-11d1-9888-006097DEACF9")
'{
'    ' IUnknown methods
'    STDMETHOD (QueryInterface)(THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG, AddRef) ( THIS ) PURE;
'    STDMETHOD_(ULONG, Release) ( THIS ) PURE;
'
'    ' IADesktopP2 methods
'    STDMETHOD (ReReadWallpaper)(THIS) PURE;
'    STDMETHOD (GetADObjectFlags)(THIS_ __out DWORD *lpdwFlags, DWORD dwMask) PURE;
'    STDMETHOD (UpdateAllDesktopSubscriptions)(THIS) PURE;
'    STDMETHOD (MakeDynamicChanges)(THIS_ __in IOleObject *pOleObj) PURE;
'};


#ENDIF ' %WININET


#IF (%WIN32_IE >= &H0500)

%MAX_COLUMN_NAME_LEN = 80
%MAX_COLUMN_DESC_LEN = 128

TYPE SHCOLUMNINFO
    scid           AS SHCOLUMNID    ' OUT the unique identifier of this column
    vt             AS VARTYPE       ' OUT the native type of the data returned
    fmt            AS DWORD         ' OUT this listview format (%LVCFMT_LEFT, usually)
    cChars         AS DWORD         ' OUT the default width of the column, in characters
    csFlags        AS DWORD         ' OUT SHCOLSTATE flags
    wszTitle       AS WSTRINGZ * %MAX_COLUMN_NAME_LEN   ' OUT the title of the column
    wszDescription AS WSTRINGZ * %MAX_COLUMN_DESC_LEN   ' OUT full description of this column
END TYPE


TYPE SHCOLUMNINIT QWORD FILL
    dwFlags    AS DWORD                 ' initialization flags
    dwReserved AS DWORD                 ' reserved for future use.
    wszFolder  AS WSTRINGZ * %MAX_PATH  ' fully qualified folder path (or empty if multiple folders)
END TYPE

%SHCDF_UPDATEITEM = &H00000001 ' this flag is a hint that the file has changed since the last call to GetItemData

TYPE SHCOLUMNDATA
    dwFlags           AS DWORD                ' combination of SHCDF_ flags.
    dwFileAttributes  AS DWORD                ' file attributes.
    dwReserved        AS DWORD                ' reserved for future use.
    pwszExt           AS WSTRINGZ PTR         ' address of file name extension
    wszFile           AS WSTRINGZ * %MAX_PATH ' Absolute path of file.
END TYPE


'#undef INTERFACE
'#define INTERFACE IColumnProvider
'
'' Note: these objects must be threadsafe!  GetItemData _will_ be called
'' simultaneously from multiple threads.
'DECLARE_INTERFACE_IID_(IColumnProvider, IUnknown, "E8025004-1C42-11d2-BE2C-00A0C9A83DA1")
'{
'    ' IUnknown methods
'    STDMETHOD (QueryInterface)(THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
'    STDMETHOD_(ULONG, Release)(THIS) PURE;
'
'    ' IColumnProvider methods
'    STDMETHOD (Initialize)(THIS_ LPCSHCOLUMNINIT psci) PURE;
'    STDMETHOD (GetColumnInfo)(THIS_ DWORD dwIndex, __out SHCOLUMNINFO *psci) PURE;
'    STDMETHOD (GetItemData)(THIS_ LPCSHCOLUMNID pscid, LPCSHCOLUMNDATA pscd, __out VARIANT *pvarData) PURE;
'};

#ENDIF ' %WIN32_IE >= &H0500
#ENDIF ' %WIN32_IE

'==========================================================================
' Clipboard format which may be supported by IDataObject from system
' defined shell folders (such as directories, network, ...).
'==========================================================================

MACRO CFSTR_SHELLIDLIST                = "Shell IDList Array"                  ' CF_IDLIST
MACRO CFSTR_SHELLIDLISTOFFSET          = "Shell Object Offsets"                ' CF_OBJECTPOSITIONS
MACRO CFSTR_NETRESOURCES               = "Net Resource"                        ' CF_NETRESOURCE
MACRO CFSTR_FILEDESCRIPTORA            = "FileGroupDescriptor"                 ' CF_FILEGROUPDESCRIPTORA
MACRO CFSTR_FILEDESCRIPTORW            = "FileGroupDescriptorW"$$              ' CF_FILEGROUPDESCRIPTORW
MACRO CFSTR_FILECONTENTS               = "FileContents"                        ' CF_FILECONTENTS
MACRO CFSTR_FILENAMEA                  = "FileName"                            ' CF_FILENAMEA
MACRO CFSTR_FILENAMEW                  = "FileNameW"$$                         ' CF_FILENAMEW
MACRO CFSTR_PRINTERGROUP               = "PrinterFriendlyName"                 ' CF_PRINTERS
MACRO CFSTR_FILENAMEMAPA               = "FileNameMap"                         ' CF_FILENAMEMAPA
MACRO CFSTR_FILENAMEMAPW               = "FileNameMapW"$$                      ' CF_FILENAMEMAPW
MACRO CFSTR_SHELLURL                   = "UniformResourceLocator"
MACRO CFSTR_INETURLA                   = CFSTR_SHELLURL
MACRO CFSTR_INETURLW                   = "UniformResourceLocatorW"$$
MACRO CFSTR_PREFERREDDROPEFFECT        = "Preferred DropEffect"
MACRO CFSTR_PERFORMEDDROPEFFECT        = "Performed DropEffect"
MACRO CFSTR_PASTESUCCEEDED             = "Paste Succeeded"
MACRO CFSTR_INDRAGLOOP                 = "InShellDragLoop"
MACRO CFSTR_MOUNTEDVOLUME              = "MountedVolume"
MACRO CFSTR_PERSISTEDDATAOBJECT        = "PersistedDataObject"
MACRO CFSTR_TARGETCLSID                = "TargetCLSID"                         ' HGLOBAL with a CLSID of the drop target
MACRO CFSTR_LOGICALPERFORMEDDROPEFFECT = "Logical Performed DropEffect"
MACRO CFSTR_AUTOPLAY_SHELLIDLISTS      = "Autoplay Enumerated IDList Array"    ' (HGLOBAL with LPIDA)
MACRO CFSTR_UNTRUSTEDDRAGDROP          = "UntrustedDragDrop"                   '  DWORD
MACRO CFSTR_FILE_ATTRIBUTES_ARRAY      = "File Attributes Array"               ' (FILE_ATTRIBUTES_ARRAY format on HGLOBAL)
MACRO CFSTR_INVOKECOMMAND_DROPPARAM    = "InvokeCommand DropParam"             ' (HGLOBAL with LPWSTR)
MACRO CFSTR_SHELLDROPHANDLER           = "DropHandlerCLSID"                    ' (HGLOBAL with CLSID of drop handler)
MACRO CFSTR_DROPDESCRIPTION            = "DropDescription"                     ' (HGLOBAL with DROPDESCRIPTION)

#IF %DEF(%UNICODE)
MACRO CFSTR_FILEDESCRIPTOR = CFSTR_FILEDESCRIPTORW
MACRO CFSTR_FILENAME       = CFSTR_FILENAMEW
MACRO CFSTR_FILENAMEMAP    = CFSTR_FILENAMEMAPW
MACRO CFSTR_INETURL        = CFSTR_INETURLW
#ELSE
MACRO CFSTR_FILEDESCRIPTOR = CFSTR_FILEDESCRIPTORA
MACRO CFSTR_FILENAME       = CFSTR_FILENAMEA
MACRO CFSTR_FILENAMEMAP    = CFSTR_FILENAMEMAPA
MACRO CFSTR_INETURL        = CFSTR_INETURLA
#ENDIF

%DVASPECT_SHORTNAME = 2 ' use for CF_HDROP to get short name version of file paths
%DVASPECT_COPY      = 3 ' use to indicate format is a "Copy" of the data (FILECONTENTS, FILEDESCRIPTOR, etc)
%DVASPECT_LINK      = 4 ' use to indicate format is a "Shortcut" to the data (FILECONTENTS, FILEDESCRIPTOR, etc)

'
' format of CF_NETRESOURCE
'
TYPE NRESARRAY QWORD FILL
    cItems AS DWORD
    nr(0)  AS NETRESOURCE
END TYPE

'
' format of CF_IDLIST
'
TYPE CIDA
    cidl       AS DWORD    ' number of relative IDList
    aoffset(0) AS DWORD    ' [0]: folder IDList, [1]-[cidl]: item IDList
END TYPE

'
' FILEDESCRIPTOR.dwFlags field indicate which fields are valid in the FILEDESCRIPTOR struct
'
MACRO FD_FLAGS_enum=DWORD
ENUM FD_FLAGS BITS SINGULAR
    FD_CLSID      = &H00000001
    FD_SIZEPOINT
    FD_ATTRIBUTES
    FD_CREATETIME
    FD_ACCESSTIME
    FD_WRITESTIME
    FD_FILESIZE
    FD_PROGRESSUI = &H00004000        ' Show Progress UI w/Drag and Drop
    FD_LINKUI                         ' 'link' UI is preferred
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
    FD_UNICODE    = &H80000000???     ' this descriptor is UNICODE
#ENDIF
END ENUM

TYPE FILEDESCRIPTORA
    dwFlags          AS FD_FLAGS_enum
    nclsid           AS GUID   ' CLSID
    sizel            AS SIZEL
    pointl           AS POINTL
    dwFileAttributes AS DWORD
    ftCreationTime   AS FILETIME
    ftLastAccessTime AS FILETIME
    ftLastWriteTime  AS FILETIME
    nFileSizeHigh    AS DWORD
    nFileSizeLow     AS DWORD
    cFileName        AS ASCIIZ * %MAX_PATH
END TYPE

TYPE FILEDESCRIPTORW
    dwFlags          AS FD_FLAGS_enum
    nclsid           AS GUID   ' CLSID
    sizel            AS SIZEL
    pointl           AS POINTL
    dwFileAttributes AS DWORD
    ftCreationTime   AS FILETIME
    ftLastAccessTime AS FILETIME
    ftLastWriteTime  AS FILETIME
    nFileSizeHigh    AS DWORD
    nFileSizeLow     AS DWORD
    cFileName        AS WSTRINGZ * %MAX_PATH
END TYPE

#IF %DEF(%UNICODE)
TYPE FILEDESCRIPTOR
    FILEDESCRIPTORW
END TYPE
#ELSE
TYPE FILEDESCRIPTOR
    FILEDESCRIPTORA
END TYPE
#ENDIF

'
' format of CF_FILEGROUPDESCRIPTOR
'
TYPE FILEGROUPDESCRIPTORA
     cItems AS DWORD
     fgd(0) AS FILEDESCRIPTORA
END TYPE

TYPE FILEGROUPDESCRIPTORW
     cItems AS DWORD
     fgd(0) AS FILEDESCRIPTORW
END TYPE

#IF %DEF(%UNICODE)
TYPE FILEGROUPDESCRIPTOR
    FILEGROUPDESCRIPTORW
END TYPE
#ELSE
TYPE FILEGROUPDESCRIPTOR
    FILEGROUPDESCRIPTORA
END TYPE
#ENDIF

'
' format of CF_HDROP and CF_PRINTERS, in the HDROP case the data that follows
' is a double null terinated list of file names, for printers they are printer
' friendly names
'
TYPE DROPFILES
   pFiles AS DWORD   ' offset of file list
   pt     AS POINT   ' drop point (client coords)
   fNC    AS LONG    ' is it on NonClient area
                     ' and pt is in screen coords
   fWide  AS LONG    ' WIDE character switch
END TYPE


#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
TYPE FILE_ATTRIBUTES_ARRAY
    cItems                  AS DWORD   ' number of items in rgdwFileAttributes array
    dwSumFileAttributes     AS DWORD   ' all of the attributes ORed together
    dwProductFileAttributes AS DWORD   ' all of the attributes ANDed together
    rgdwFileAttributes(0)   AS DWORD   ' array
END TYPE
#ENDIF


#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
MACRO DROPIMAGETYPE_enum=LONG
ENUM DROPIMAGETYPE SINGULAR
    DROPIMAGE_INVALID = -1                ' no drop image at all
    DROPIMAGE_NONE                        ' red "no" circle
    DROPIMAGE_COPY    = %DROPEFFECT_COPY  ' plus for copy
    DROPIMAGE_MOVE    = %DROPEFFECT_MOVE  ' movement arrow for move
    DROPIMAGE_LINK    = %DROPEFFECT_LINK  ' link arrow for link
    DROPIMAGE_LABEL   = 6                 ' tag icon to indicate metadata will be changed
    DROPIMAGE_WARNING                     ' yellow exclamation, something is amiss with the operation
    DROPIMAGE_NOIMAGE                     ' no image at all
END ENUM

TYPE DROPDESCRIPTION
    ntype     AS DROPIMAGETYPE_enum     ' indicates the stock image to use

' text such as "Move to %1"
    szMessage AS WSTRINGZ * %MAX_PATH

' text such as "Documents", inserted as specified by szMessage
    szInsert  AS WSTRINGZ * %MAX_PATH

' some UI coloring is applied to the text in szInsert, if used by specifying %1 in szMessage.
' %% and %1 are the subset of FormatMessage markers that are processed here.
END TYPE

#ENDIF ' (%NTDDI_VERSION >= %NTDDI_VISTA)


'====== File System Notification APIs ===============================
'
TYPE SHChangeNotifyEntry
    pidl       AS ITEMIDLIST PTR  ' PCIDLIST_ABSOLUTE
    fRecursive AS LONG
END TYPE


'
'  File System Notification flags
'

%SHCNRF_InterruptLevel     = &H0001
%SHCNRF_ShellLevel         = &H0002
%SHCNRF_RecursiveInterrupt = &H1000
%SHCNRF_NewDelivery        = &H8000??

%SHCNE_RENAMEITEM          = &H00000001
%SHCNE_CREATE              = &H00000002
%SHCNE_DELETE              = &H00000004
%SHCNE_MKDIR               = &H00000008
%SHCNE_RMDIR               = &H00000010
%SHCNE_MEDIAINSERTED       = &H00000020
%SHCNE_MEDIAREMOVED        = &H00000040
%SHCNE_DRIVEREMOVED        = &H00000080
%SHCNE_DRIVEADD            = &H00000100
%SHCNE_NETSHARE            = &H00000200
%SHCNE_NETUNSHARE          = &H00000400
%SHCNE_ATTRIBUTES          = &H00000800
%SHCNE_UPDATEDIR           = &H00001000
%SHCNE_UPDATEITEM          = &H00002000
%SHCNE_SERVERDISCONNECT    = &H00004000
%SHCNE_UPDATEIMAGE         = &H00008000
%SHCNE_DRIVEADDGUI         = &H00010000
%SHCNE_RENAMEFOLDER        = &H00020000
%SHCNE_FREESPACE           = &H00040000

#IF (%WIN32_IE >= &H0400)
' SHCNE_EXTENDED_EVENT: the extended event is identified in dwItem1,
' packed in LPITEMIDLIST format (same as SHCNF_DWORD packing).
' Additional information can be passed in the dwItem2 parameter
' of SHChangeNotify (called "pidl2" below), which if present, must also
' be in LPITEMIDLIST format.
'
' Unlike the standard events, the extended events are ORDINALs, so we
' don't run out of bits.  Extended events follow the SHCNEE_* naming
' convention.
'
' The dwItem2 parameter varies according to the extended event.

%SHCNE_EXTENDED_EVENT = &H04000000
#ENDIF      ' %WIN32_IE >= &H0400

%SHCNE_ASSOCCHANGED   = &H08000000

%SHCNE_DISKEVENTS     = &H0002381F
%SHCNE_GLOBALEVENTS   = &H0C0581E0  ' Events that dont match pidls first
%SHCNE_ALLEVENTS      = &H7FFFFFFF
%SHCNE_INTERRUPT      = &H80000000??? ' The presence of this flag indicates
                                      ' that the event was generated by an
                                      ' interrupt.  It is stripped out before
                                      ' the clients of SHCNNotify_ see it.

#IF (%WIN32_IE >= &H0400)
' SHCNE_EXTENDED_EVENT extended events.  These events are ordinals.
' This is not a bitfield.

%SHCNEE_ORDERCHANGED        = 2&  ' pidl2 is the changed folder
%SHCNEE_MSI_CHANGE          = 4&  ' pidl2 is a SHChangeProductKeyAsIDList
%SHCNEE_MSI_UNINSTALL       = 5&  ' pidl2 is a SHChangeProductKeyAsIDList
#ENDIF

' Flags
' uFlags & SHCNF_TYPE is an ID which indicates what dwItem1 and dwItem2 mean
%SHCNF_IDLIST      = &H0000        ' LPITEMIDLIST
%SHCNF_PATHA       = &H0001        ' path name
%SHCNF_PRINTERA    = &H0002        ' printer friendly name
%SHCNF_DWORD       = &H0003        ' DWORD
%SHCNF_PATHW       = &H0005        ' path name
%SHCNF_PRINTERW    = &H0006        ' printer friendly name
%SHCNF_TYPE        = &H00FF
%SHCNF_FLUSH       = &H1000
%SHCNF_FLUSHNOWAIT = &H2000

%SHCNF_NOTIFYRECURSIVE      = &H10000 ' Notify clients registered for any child

#IF %DEF(%UNICODE)
MACRO SHCNF_PATH    = SHCNF_PATHW
MACRO SHCNF_PRINTER = SHCNF_PRINTERW
#ELSE
MACRO SHCNF_PATH    = SHCNF_PATHA
MACRO SHCNF_PRINTER = SHCNF_PRINTERA
#ENDIF

'
'  APIs
'
DECLARE SUB SHChangeNotify LIB "Shell32.dll" ALIAS "SHChangeNotify" _
    (BYVAL wEventId AS LONG, BYVAL uFlags AS DWORD, dwItem1 AS ANY, _
    dwItem2 AS ANY)

'
' IShellChangeNotify
'
'#undef  INTERFACE
'#define INTERFACE  IShellChangeNotify
'
'DECLARE_INTERFACE_IID_(IShellChangeNotify, IUnknown, "D82BE2B1-5764-11D0-A96E-00C04FD705A2")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** IShellChangeNotify methods ***
'    STDMETHOD(OnChange) (THIS_ LONG lEvent, PCIDLIST_ABSOLUTE pidl1, PCIDLIST_ABSOLUTE pidl2) PURE;
'} ;

'
' IQueryInfo
'
'-------------------------------------------------------------------------
'
' IQueryInfo interface
'
' [Methods]
'              ::GetInfoTip()
'-------------------------------------------------------------------------

'#undef  INTERFACE
'#define INTERFACE  IQueryInfo
'
'DECLARE_INTERFACE_IID_(IQueryInfo, IUnknown, "00021500-0000-0000-c000-000000000046")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, __out void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** IQueryInfo methods ***
'    STDMETHOD(GetInfoTip)(THIS_ DWORD dwFlags, __out WCHAR **ppwszTip) PURE;
'    STDMETHOD(GetInfoFlags)(THIS_ __out DWORD *pdwFlags) PURE;
'} ;

%QITIPF_DEFAULT          = &H00000000
%QITIPF_USENAME          = &H00000001
%QITIPF_LINKNOTARGET     = &H00000002
%QITIPF_LINKUSETARGET    = &H00000004
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
%QITIPF_USESLOWTIP       = &H00000008  ' Flag says it's OK to take a long time generating tip
#ENDIF
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%QITIPF_SINGLELINE       = &H00000010
#ENDIF

%QIF_CACHED              = &H00000001
%QIF_DONTEXPANDFOLDER    = &H00000002


'
' SHAddToRecentDocs
'
MACRO SHARD_enum=LONG
ENUM SHARD SINGULAR
    SHARD_PIDL  = 1
    SHARD_PATHA
    SHARD_PATHW
#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
    SHARD_APPIDINFO       ' indicates the data type is a pointer to a SHARDAPPIDINFO structure
    SHARD_APPIDINFOIDLIST ' indicates the data type is a pointer to a SHARDAPPIDINFOIDLIST structure
    SHARD_LINK            ' indicates the data type is a pointer to an IShellLink instance
    SHARD_APPIDINFOLINK   ' indicates the data type is a pointer to a SHARDAPPIDINFOLINK structure
    SHARD_SHELLITEM       ' indicates the data type is a pointer to an IShellItem instance
#ENDIF
END ENUM

#IF (%NTDDI_VERSION >= %NTDDI_WIN7)

TYPE SHARDAPPIDINFO
    psi      AS DWORD ' IShellItem PTR   ' The namespace location of the the item that should be added to the recent docs folder.
    pszAppID AS WSTRINGZ PTR     ' The id of the application that should be associated with this recent doc.
END TYPE

TYPE SHARDAPPIDINFOIDLIST
    pidl     AS ITEMIDLIST PTR   ' The idlist for the shell item that should be added to the recent docs folder.
    pszAppID AS WSTRINGZ PTR     ' The id of the application that should be associated with this recent doc.
END TYPE

TYPE SHARDAPPIDINFOLINK
    psl AS DWORD ' IShellLink PTR      ' An IShellLink instance that when launched opens a recently used item in the specified
                               ' application. This link is not added to the recent docs folder, but will be added to the
                               ' specified application's destination list.
    pszAppID AS WSTRINGZ PTR   ' The id of the application that should be associated with this recent doc.
END TYPE

#ENDIF  ' #IF (%NTDDI_VERSION >= %NTDDI_WIN7)

#IF %DEF(%UNICODE)
MACRO SHARD_PATH = SHARD_PATHW
#ELSE
MACRO SHARD_PATH = SHARD_PATHA
#ENDIF

' The type of the data pointed to by pv is a function of uFlags values that
' are %SHARD_XXX values.  PV can be a PCIDLIST_ABSOLUTE, PCWSTR, PCSTR,
' SHARDAPPIDINFO, or SHARDAPPIDINFOIDLIST.
DECLARE SUB SHAddToRecentDocs LIB "Shell32.dll" ALIAS "SHAddToRecentDocs" _
    (BYVAL uFlags AS DWORD, pv AS ANY)

TYPE SHChangeDWORDAsIDList
    cb      AS WORD
    dwItem1 AS DWORD
    dwItem2 AS DWORD
    cbZero  AS WORD
END TYPE


#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)


TYPE SHChangeUpdateImageIDList
    cb          AS WORD
    iIconIndex  AS LONG
    iCurIndex   AS LONG
    uFlags      AS DWORD
    dwProcessID AS DWORD
    szName      AS WSTRINGZ * %MAX_PATH
    cbZero      AS WORD
END TYPE

DECLARE FUNCTION SHHandleUpdateImage LIB "Shell32.dll" _
    ALIAS "SHHandleUpdateImage" (BYVAL pidlExtra AS ITEMIDLIST PTR) _
    AS LONG


TYPE SHChangeProductKeyAsIDList
    cb            AS WORD
    wszProductKey AS WSTRINGZ * 39
    cbZero        AS WORD
END TYPE


DECLARE SUB SHUpdateImageA LIB "Shell32.dll" ALIAS "SHUpdateImageA" _
    (pszHashItem AS ASCIIZ, BYVAL iIndex AS LONG, BYVAL uFlags AS DWORD, _
    BYVAL iImageIndex AS LONG)

DECLARE SUB SHUpdateImageW LIB "Shell32.dll" ALIAS "SHUpdateImageW" _
    (pszHashItem AS WSTRINGZ, BYVAL iIndex AS LONG, BYVAL uFlags AS DWORD, _
    BYVAL iImageIndex AS LONG)

#IF %DEF(%UNICODE)
MACRO SHUpdateImage = SHUpdateImageW
#ELSE
MACRO SHUpdateImage = SHUpdateImageA
#ENDIF ' NOT %UNICODE

#ENDIF ' %NTDDI_WIN2K

DECLARE FUNCTION SHChangeNotifyRegister LIB "Shell32.dll" _
    ALIAS "SHChangeNotifyRegister" (BYVAL hwnd AS DWORD, _
    BYVAL fSources AS LONG, BYVAL fEvents AS LONG, BYVAL wMsg AS DWORD, _
    BYVAL cEntries AS LONG, pshcne AS ANY) AS DWORD

DECLARE FUNCTION SHChangeNotifyDeregister LIB "Shell32.dll" _
    ALIAS "SHChangeNotifyDeregister" (BYVAL ulID AS DWORD) AS LONG

MACRO SCNRT_STATUS_enum=LONG
ENUM SCNRT_STATUS SINGULAR
    SCNRT_ENABLE
    SCNRT_DISABLE
END ENUM

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
' Use SHChangeNotifyRegisterThread() to enable Async Register and Deregister.
' Call with SCNRT_ENABLE at the thread proc beginning and SCNRT_DISABLE at the end.
' The call with SCNRT_DISABLE can block while it synchronizes with the main
' ChangeNotify thread.

DECLARE SUB SHChangeNotifyRegisterThread LIB "Shell32.dll" _
    ALIAS "SHChangeNotifyRegisterThread" (BYVAL nStatus AS LONG)

#ENDIF  ' #IF (%NTDDI_VERSION >= %NTDDI_VISTA)

DECLARE FUNCTION SHChangeNotification_Lock LIB "Shell32.dll" _
    ALIAS "SHChangeNotification_Lock" (BYVAL hChange AS DWORD, _
    BYVAL dwProcId AS DWORD, pppidl AS ANY, plEvent AS LONG) AS DWORD

DECLARE FUNCTION SHChangeNotification_Unlock LIB "Shell32.dll" _
    ALIAS "SHChangeNotification_Unlock" (BYVAL hLock AS DWORD) AS LONG

#IF (%WIN32_IE >= &H0400)

' The pidls that are given to the view via the ChangeNotifyEvents are simple Pidls,
' SHGetRealIDL() will convert them to true PIDLs.

DECLARE FUNCTION SHGetRealIDL LIB "Shell32.dll" ALIAS "SHGetRealIDL" _
    (psf AS ANY, pdlSimple AS ITEMIDLIST, ppidlReal AS ANY) AS LONG

#ENDIF ' %WIN32_IE >= &H0400

DECLARE FUNCTION SHGetInstanceExplorer LIB "Shell32.dll" _
    ALIAS "SHGetInstanceExplorer" (ppunk AS ANY) AS LONG

'
' SHGetDataFromIDListA/W
'
' SHGetDataFromIDList nFormat values TCHAR
%SHGDFIL_FINDDATA       = 1
%SHGDFIL_NETRESOURCE    = 2
%SHGDFIL_DESCRIPTIONID  = 3

%SHDID_ROOT_REGITEM         = 1
%SHDID_FS_FILE              = 2
%SHDID_FS_DIRECTORY         = 3
%SHDID_FS_OTHER             = 4
%SHDID_COMPUTER_DRIVE35     = 5
%SHDID_COMPUTER_DRIVE525    = 6
%SHDID_COMPUTER_REMOVABLE   = 7
%SHDID_COMPUTER_FIXED       = 8
%SHDID_COMPUTER_NETDRIVE    = 9
%SHDID_COMPUTER_CDROM       = 10
%SHDID_COMPUTER_RAMDISK     = 11
%SHDID_COMPUTER_OTHER       = 12
%SHDID_NET_DOMAIN           = 13
%SHDID_NET_SERVER           = 14
%SHDID_NET_SHARE            = 15
%SHDID_NET_RESTOFNET        = 16
%SHDID_NET_OTHER            = 17
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
%SHDID_COMPUTER_IMAGING     = 18
%SHDID_COMPUTER_AUDIO       = 19
%SHDID_COMPUTER_SHAREDDOCS  = 20
#ENDIF
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%SHDID_MOBILE_DEVICE        = 21  ' PDA/PalmPC
#ENDIF

TYPE SHDESCRIPTIONID QWORD FILL
    dwDescriptionId AS DWORD
    nclsid          AS GUID   ' CLSID
END TYPE

' these delegate to IShellFolder2::GetDetailsEx()

DECLARE FUNCTION SHGetDataFromIDListA LIB "Shell32.dll" _
    ALIAS "SHGetDataFromIDListA" (psf AS ANY, pidl AS ITEMIDLIST, _
    BYVAL nFormat AS LONG, pv AS ANY, BYVAL cb AS LONG) AS LONG

DECLARE FUNCTION SHGetDataFromIDListW LIB "Shell32.dll" _
    ALIAS "SHGetDataFromIDListW" (psf AS ANY, pidl AS ITEMIDLIST, _
    BYVAL nFormat AS LONG, pv AS ANY, BYVAL cb AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO SHGetDataFromIDList=SHGetDataFromIDListW
#ELSE
MACRO SHGetDataFromIDList=SHGetDataFromIDListA
#ENDIF ' NOT %UNICODE


'===========================================================================

' PathResolve flags
%PRF_VERIFYEXISTS            = &H0001
%PRF_TRYPROGRAMEXTENSIONS    = &H0002 OR %PRF_VERIFYEXISTS
%PRF_FIRSTDIRDEF             = &H0004
%PRF_DONTFINDLNK             = &H0008      ' if PRF_TRYPROGRAMEXTENSIONS is specified
#IF (%NTDDI_VERSION >= %NTDDI_WINXPSP2)
%PRF_REQUIREABSOLUTE         = &H0010
#ENDIF

DECLARE FUNCTION RestartDialog LIB "Shell32.dll" ALIAS "RestartDialog" _
    (BYVAL hwnd AS DWORD, lpPrompt AS WSTRINGZ, BYVAL dwReturn AS DWORD) _
    AS LONG

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)

DECLARE FUNCTION RestartDialogEx LIB "Shell32.dll" ALIAS "RestartDialogEx" _
    (BYVAL hwnd AS DWORD, lpPrompt AS WSTRINGZ, BYVAL dwReturn AS DWORD, _
    BYVAL dwReasonCode AS DWORD) AS LONG

#ENDIF

DECLARE FUNCTION SHCoCreateInstance LIB "Shell32.dll" _
    ALIAS "SHCoCreateInstance" (pszCLSID AS WSTRINGZ, pclsid AS GUID, _
    pUnkOuter AS ANY, riid AS GUID, ppv AS ANY) AS LONG

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

DECLARE FUNCTION SHCreateDataObject LIB "Shell32.dll" _
    ALIAS "SHCreateDataObject" (pdlFolder AS ITEMIDLIST, _
    BYVAL cidl AS DWORD, BYVAL apidl AS ITEMIDLIST PTR, _
    pdtInner AS ANY, riid AS GUID, ppv AS ANY) AS LONG

#ENDIF

DECLARE FUNCTION CIDLData_CreateFromIDArray LIB "Shell32.dll" _
    ALIAS "CIDLData_CreateFromIDArray" (pidlFolder AS ITEMIDLIST, _
    BYVAL cidl AS DWORD, BYVAL apidl AS ITEMIDLIST PTR, _
    ppdtobj AS ANY) AS LONG

DECLARE FUNCTION SHCreateStdEnumFmtEtc LIB "Shell32.dll" _
    ALIAS "SHCreateStdEnumFmtEtc" (BYVAL cfmt AS DWORD, afmt AS ANY, _
    ppenumFormatEtc AS ANY) AS LONG

DECLARE FUNCTION SHDoDragDrop LIB "Shell32.dll" ALIAS "SHDoDragDrop" _
    (BYVAL hwnd AS DWORD, pdata AS ANY, pdsrc AS ANY, _
    BYVAL dwEffect AS DWORD, pdwEffect AS DWORD) AS LONG

' stuff for doing auto scrolling
%NUM_POINTS    = 3

TYPE AUTO_SCROLL_DATA
    iNextSample            AS LONG
    dwLastScroll           AS DWORD
    bFull                  AS LONG   ' BOOL
    pts(%NUM_POINTS-1)     AS POINT
    dwTimes(%NUM_POINTS-1) AS DWORD
END TYPE

DECLARE FUNCTION DAD_SetDragImage LIB "Shell32.dll" _
    ALIAS "DAD_SetDragImage" (BYVAL him AS DWORD, pptOffset AS POINT) AS LONG

DECLARE FUNCTION DAD_DragEnterEx LIB "Shell32.dll " ALIAS "DAD_DragEnterEx" _
    (BYVAL hwndTarget AS DWORD, BYVAL ptStart AS POINT) AS LONG

DECLARE FUNCTION DAD_DragEnterEx2 LIB "Shell32.dll " ALIAS "DAD_DragEnterEx2" _
    (BYVAL hwndTarget AS DWORD, BYVAL ptStart AS POINT, pdtObject AS ANY) _
    AS LONG

DECLARE FUNCTION DAD_ShowDragImage LIB "Shell32.dll" _
    ALIAS "DAD_ShowDragImage" (BYVAL fShow AS LONG) AS LONG

DECLARE FUNCTION DAD_DragMove LIB "Shell32.dll" ALIAS "DAD_DragMove" _
    (BYVAL pt AS POINT) AS LONG

DECLARE FUNCTION DAD_DragLeave LIB "Shell32.dll" ALIAS "DAD_DragLeave" () _
    AS LONG

DECLARE FUNCTION DAD_AutoScroll LIB "Shell32.dll" ALIAS "DAD_AutoScroll" _
    (BYVAL hwnd AS DWORD, pad AS AUTO_SCROLL_DATA, pptNow AS POINT) AS LONG

TYPE CABINETSTATE
    cLength                   AS WORD
    nVersion                  AS WORD

    fFullPathTitle            AS BIT * 1 IN DWORD
    fSaveLocalView            AS BIT * 1
    fNotShell                 AS BIT * 1
    fSimpleDefault            AS BIT * 1
    fDontShowDescBar          AS BIT * 1
    fNewWindowMode            AS BIT * 1
    fShowCompColor            AS BIT * 1  ' NT: Show compressed volumes in a different colour
    fDontPrettyNames          AS BIT * 1  ' NT: Do 8.3 name conversion, or not!
    fAdminsCreateCommonGroups AS BIT * 1  ' NT: Administrators create common groups
    fUnusedFlags              AS BIT * 7

    fMenuEnumFilter           AS DWORD
END TYPE

%CABINETSTATE_VERSION = 2

' APIs for reading and writing the cabinet state.

DECLARE FUNCTION ReadCabinetState LIB "Shell32.dll" _
    ALIAS "ReadCabinetState" (pcs AS CABINETSTATE, BYVAL cLength AS LONG) _
    AS LONG

DECLARE FUNCTION WriteCabinetState LIB "Shell32.dll" _
    ALIAS "WriteCabinetState" (pcs AS CABINETSTATE) AS LONG

DECLARE FUNCTION PathMakeUniqueName LIB "Shell32.dll" _
    ALIAS "PathMakeUniqueName" (pszUniqueName AS WSTRINGZ, _
    BYVAL cchMax AS DWORD, pszTemplate AS WSTRINGZ, pszLongPlate AS WSTRINGZ, _
    pszDir AS WSTRINGZ) AS LONG

DECLARE SUB PathQualify LIB "Shell32.dll" ALIAS "PathQualify" (psz AS WSTRINGZ)

DECLARE FUNCTION PathIsExe LIB "Shell32.dll" ALIAS "PathIsExe" _
    (pszPath AS WSTRINGZ) AS LONG

DECLARE FUNCTION PathIsSlowA LIB "Shell32.dll" ALIAS "PathIsSlowA" _
    (pszFile AS ASCIIZ, BYVAL dwAttr AS DWORD) AS LONG

DECLARE FUNCTION PathIsSlowW LIB "Shell32.dll" ALIAS "PathIsSlowW" _
    (pszFile AS WSTRINGZ, BYVAL dwAttr AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION PathIsSlow LIB "Shell32.dll" ALIAS "PathIsSlowW" _
    (pszFile AS WSTRINGZ, BYVAL dwAttr AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION PathIsSlow LIB "Shell32.dll" ALIAS "PathIsSlowA" _
    (pszFile AS ASCIIZ, BYVAL dwAttr AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE
'
'  Return codes from PathCleanupSpec.  Negative return values are
'  unrecoverable errors
'
%PCS_FATAL           = &H80000000???
%PCS_REPLACEDCHAR    = &H00000001
%PCS_REMOVEDCHAR     = &H00000002
%PCS_TRUNCATED       = &H00000004
%PCS_PATHTOOLONG     = &H00000008  ' Always combined with FATAL

DECLARE FUNCTION PathCleanupSpec LIB "Shell32.dll" _
    ALIAS "PathCleanupSpec" (pszDir AS WSTRINGZ, pszSpec AS WSTRINGZ) AS LONG

DECLARE FUNCTION PathResolve LIB "Shell32.dll" ALIAS "PathResolve" _
    (lpszPath AS WSTRINGZ, dirs AS ANY, BYVAL fFlags AS DWORD) AS LONG

DECLARE FUNCTION GetFileNameFromBrowse LIB "Shell32.dll" _
    ALIAS "GetFileNameFromBrowse" (BYVAL hwnd AS DWORD, _
    pszDefExt AS WSTRINGZ, BYVAL cchFilePath AS DWORD, _
    pszWorkingDir AS WSTRINGZ, pszDefExt AS WSTRINGZ, pszFilters AS WSTRINGZ, _
    pszTitle AS WSTRINGZ) AS LONG

DECLARE FUNCTION DriveType LIB "Shell32.dll" ALIAS "DriveType" _
    (BYVAL iDrive AS LONG) AS LONG

DECLARE FUNCTION RealDriveType LIB "Shell32.dll" ALIAS "RealDriveType" _
    (BYVAL iDrive AS LONG, BYVAL fOKToHitNet AS LONG) AS LONG

DECLARE FUNCTION IsNetDrive LIB "Shell32.dll" ALIAS "IsNetDrive" _
    (BYVAL iDrive AS LONG) AS LONG

' Flags for Shell_MergeMenus
%MM_ADDSEPARATOR         = &H00000001&
%MM_SUBMENUSHAVEIDS      = &H00000002&
%MM_DONTREMOVESEPS       = &H00000004&

DECLARE FUNCTION Shell_MergeMenus LIB "Shell32.dll" _
    ALIAS "Shell_MergeMenus" (BYVAL hmDst AS DWORD, BYVAL hmSrc AS DWORD, _
    BYVAL uInsert AS DWORD, BYVAL uIDAdjust AS DWORD, _
    BYVAL uIDAdjustMax AS DWORD, BYVAL uFlags AS DWORD) AS DWORD


'
' The SHObjectProperties API provides an easy way to invoke the properties
'   context menu command on a subset of the shell item namespace.
'
'   PARAMETERS
'
'     hwnd              The handle of the window which will own the dialog
'     shopObjectType    A %SHOP_ value AS defined below
'     pszObjectName     Name of the object, see SHOP_ values below
'     pszPropertyPage   The name of the property sheet page to open or NULL.
'
'   RETURN
'
'     TRUE IF the Properties COMMAND was invoked
'

DECLARE FUNCTION SHObjectProperties LIB "Shell32.dll" _
    ALIAS "SHObjectProperties" (BYVAL hwnd AS DWORD, _
    BYVAL shopObjectType AS DWORD, pszObjectName AS WSTRINGZ, _
    pszPropertyPage AS WSTRINGZ) AS LONG

%SHOP_PRINTERNAME = &H00000001  ' pszObjectName points to a printer friendly name
%SHOP_FILEPATH    = &H00000002  ' pszObjectName points to a fully qualified path+file name
%SHOP_VOLUMEGUID  = &H00000004  ' pszObjectName points to a Volume GUID


'
' The SHFormatDrive API provides access to the shell
'   format dialog. this allows apps which want to format disks
'   to bring up the same dialog that the shell does to do it.
'
'   This dialog is not sub-classable. You cannot put custom
'   controls in it. If you want this ability, you will have
'   to write your own front end for the DMaint_FormatDrive
'   engine.
'
'   Note that the user can format as many diskettes in the specified
'   drive, or as many times, as he/she wishes to. There is no way to
'   force any specififc number of disks to format. If you want this
'   ability, you will have to write your own front end for the
'   DMaint_FormatDrive engine.
'
'   Note also that the format will not start till the user pushes the
'   start button in the dialog. There is no way to do auto start. If
'   you want this ability, you will have to write your own front end
'   for the DMaint_FormatDrive engine.
'
'   PARAMETERS
'
'     hwnd    = The window handle of the window which will own the dialog.
'               Note that unlike SHCheckDrive, hwnd = %NULL does not cause
'               this dialog to come up as a "top level application" window.
'               This parameter should always be non-NULL, as this dialog is
'               only designed to be the child of another window, not a
'               stand-alone application.
'     drive   = The 0 based (A: == 0) drive number of the drive to format
'     fmtID   = The ID OF the physical format to format the disk with
'               NOTE: The special value SHFMT_ID_DEFAULT means "use the
'                     default format specified by the DMaint_FormatDrive
'                     engine". If you want to force a particular format
'                     ID "up front" you will have TO call
'                     DMaint_GetFormatOptions yourself before calling
'                     this TO obtain the valid list OF phys format IDs
'                     (contents OF the PhysFmtIDList array in the
'                     FMTINFOSTRUCT).
'     options = There are currently only two option bits defined:
'
'                %SHFMT_OPT_FULL
'                %SHFMT_OPT_SYSONLY
'
'               The normal default in the shell format dialog is
'               "Quick Format", setting this option bit indicates that
'               the caller wants to start with full format selected
'               (this is useful for folks detecting "unformatted" disks
'               and wanting to bring up the format dialog).
'
'               The SHFMT_OPT_SYSONLY initializes the dialog to
'               default to just sys the disk.
'
'               All other bits are reserved for future expansion and
'               must be 0.
'
'               Please note that this is a bit field and not a value
'               and treat it accordingly.
'
'   RETURN
'      The return is either one of the SHFMT_* values, or if the
'      returned dword value is not equal to one of these values, then
'      the return is the physical format id of the last succesful
'      format. the low word of this value can be passed on subsequent
'      calls as the fmtid parameter to "format the same type you did
'      last time".
'

DECLARE FUNCTION SHFormatDrive LIB "Shell32.dll" ALIAS "SHFormatDrive" _
    (BYVAL hwnd AS DWORD, BYVAL drive AS DWORD, BYVAL fmtID AS DWORD, _
    BYVAL options AS DWORD) AS DWORD

'
' Special value of fmtID which means "use the default format"
'
%SHFMT_ID_DEFAULT    = &HFFFF??

'
' Option bits for options parameter
'
%SHFMT_OPT_FULL     = &H0001
%SHFMT_OPT_SYSONLY  = &H0002

'
' Special return values. PLEASE NOTE that these are DWORD values.
' [oddly enough, Microsoft then goes on to incorrectly define them as LONGs.]
'
%SHFMT_ERROR     = &HFFFFFFFF???   ' Error on last format, drive may be formatable
%SHFMT_CANCEL    = &HFFFFFFFE???   ' Last format was canceled
%SHFMT_NOFORMAT  = &HFFFFFFFD???   ' Drive is not formatable

'DECLARE_HANDLE( HPSXA );

DECLARE FUNCTION SHCreatePropSheetExtArray LIB "Shell32.dll" _
    ALIAS "SHCreatePropSheetExtArray" (BYVAL hKey AS DWORD, _
    pszSubKey AS WSTRINGZ, BYVAL max_iface AS DWORD) AS DWORD

DECLARE SUB SHDestroyPropSheetExtArray LIB "Shell32.dll" _
    ALIAS "SHDestroyPropSheetExtArray" (BYVAL hpsxa AS DWORD)

DECLARE FUNCTION SHAddFromPropSheetExtArray LIB "Shell32.dll" _
    ALIAS "SHAddFromPropSheetExtArray" (BYVAL hpsxa AS DWORD, _
    BYVAL lpfnAddPage AS DWORD, BYVAL lParam AS LONG) AS DWORD

DECLARE FUNCTION SHReplaceFromPropSheetExtArray LIB "Shell32.dll" _
    ALIAS "SHReplaceFromPropSheetExtArray" (BYVAL hpsxa AS DWORD, _
    BYVAL uPageID AS DWORD, BYVAL lpfnReplaceWith AS DWORD, _
    BYVAL lParam AS LONG) AS DWORD

'===========================================================================
' Shell restrictions. (Parameter for SHRestricted)
' SHRestricted has been deprecated in favor of SHWindowsPolicy
'--- do not add restrictions here, see winpolicy.cpp c_rgWindowsPolicies
MACRO RESTRICTIONS_enum=LONG
ENUM RESTRICTIONS SINGULAR
    REST_NONE                       = &H00000000
    REST_NORUN                      = &H00000001
    REST_NOCLOSE                    = &H00000002
    REST_NOSAVESET                  = &H00000004
    REST_NOFILEMENU                 = &H00000008
    REST_NOSETFOLDERS               = &H00000010
    REST_NOSETTASKBAR               = &H00000020
    REST_NODESKTOP                  = &H00000040
    REST_NOFIND                     = &H00000080
    REST_NODRIVES                   = &H00000100
    REST_NODRIVEAUTORUN             = &H00000200
    REST_NODRIVETYPEAUTORUN         = &H00000400
    REST_NONETHOOD                  = &H00000800
    REST_STARTBANNER                = &H00001000
    REST_RESTRICTRUN                = &H00002000
    REST_NOPRINTERTABS              = &H00004000
    REST_NOPRINTERDELETE            = &H00008000
    REST_NOPRINTERADD               = &H00010000
    REST_NOSTARTMENUSUBFOLDERS      = &H00020000
    REST_MYDOCSONNET                = &H00040000
    REST_NOEXITTODOS                = &H00080000
    REST_ENFORCESHELLEXTSECURITY    = &H00100000
    REST_LINKRESOLVEIGNORELINKINFO  = &H00200000
    REST_NOCOMMONGROUPS             = &H00400000
    REST_SEPARATEDESKTOPPROCESS     = &H00800000
    REST_NOWEB                      = &H01000000
    REST_NOTRAYCONTEXTMENU          = &H02000000
    REST_NOVIEWCONTEXTMENU          = &H04000000
    REST_NONETCONNECTDISCONNECT     = &H08000000
    REST_STARTMENULOGOFF            = &H10000000
    REST_NOSETTINGSASSIST           = &H20000000
    REST_NOINTERNETICON             = &H40000001
    REST_NORECENTDOCSHISTORY
    REST_NORECENTDOCSMENU
    REST_NOACTIVEDESKTOP
    REST_NOACTIVEDESKTOPCHANGES
    REST_NOFAVORITESMENU
    REST_CLEARRECENTDOCSONEXIT
    REST_CLASSICSHELL
    REST_NOCUSTOMIZEWEBVIEW
    REST_NOHTMLWALLPAPER
    REST_NOCHANGINGWALLPAPER
    REST_NODESKCOMP
    REST_NOADDDESKCOMP
    REST_NODELDESKCOMP
    REST_NOCLOSEDESKCOMP
    REST_NOCLOSE_DRAGDROPBAND       ' Disable Close and Drag & Drop on ALL Bands
    REST_NOMOVINGBAND               ' Disable Moving ALL Bands
    REST_NOEDITDESKCOMP
    REST_NORESOLVESEARCH
    REST_NORESOLVETRACK
    REST_FORCECOPYACLWITHFILE
#IF (%NTDDI_VERSION < %NTDDI_VISTA)
    REST_NOLOGO3CHANNELNOTIFY
#ENDIF
    REST_NOFORGETSOFTWAREUPDATE = &H4000001D
    REST_NOSETACTIVEDESKTOP         ' No Active desktop on Settings Menu
    REST_NOUPDATEWINDOWS            ' No Windows Update on Settings Menu
    REST_NOCHANGESTARMENU           ' No Context menu or Drag and Drop on Start menu
    REST_NOFOLDEROPTIONS            ' No Folder Options on Settings Menu
    REST_HASFINDCOMPUTERS           ' Show Start/Search/Computers
    REST_INTELLIMENUS
    REST_RUNDLGMEMCHECKBOX
    REST_ARP_ShowPostSetup          ' ARP: Show Post-Setup page
    REST_NOCSC                      ' Disable the ClientSide caching on SM
    REST_NOCONTROLPANEL             ' Remove the Control Panel only from SM|Settings
    REST_ENUMWORKGROUP              ' Enumerate workgroup in root of nethood
    REST_ARP_NOARP                  ' ARP: Don't Allow ARP to come up at all
    REST_ARP_NOREMOVEPAGE           ' ARP: Don't allow Remove page
    REST_ARP_NOADDPAGE              ' ARP: Don't allow Add page
    REST_ARP_NOWINSETUPPAGE         ' ARP: Don't allow opt components page
    REST_GREYMSIADS                 ' SM: Allow the greying of Darwin Ads in SM
    REST_NOCHANGEMAPPEDDRIVELABEL   ' Don't enable the UI which allows users to rename mapped drive labels
    REST_NOCHANGEMAPPEDDRIVECOMMENT ' Don't enable the UI which allows users to change mapped drive comments
    REST_MaxRecentDocs
    REST_NONETWORKCONNECTIONS       ' No Start Menu | Settings |Network Connections
    REST_FORCESTARTMENULOGOFF       ' Force logoff on the Start Menu
    REST_NOWEBVIEW                  ' Disable Web View
    REST_NOCUSTOMIZETHISFOLDER      ' Disable Customize This Folder
    REST_NOENCRYPTION               ' Don't allow file encryption
    REST_reserved1
    REST_DONTSHOWSUPERHIDDEN        ' don't show super hidden files
    REST_NOSHELLSEARCHBUTTON
    REST_NOHARDWARETAB              ' No Hardware tab on Drives or in control panel
    REST_NORUNASINSTALLPROMPT       ' Don't bring up "Run As" prompt for install programs
    REST_PROMPTRUNASINSTALLNETPATH  ' Force the  "Run As" prompt for install programs on unc/network shares
    REST_NOMANAGEMYCOMPUTERVERB     ' No Manage verb on My Computer
    REST_reserved2
    REST_DISALLOWRUN                ' don't allow certain apps to be run
    REST_NOWELCOMESCREEN            ' don't allow the welcome screen to be displayed.
    REST_RESTRICTCPL                ' only allow certain cpls to be run
    REST_DISALLOWCPL                ' don't allow certain cpls to be run
    REST_NOSMBALLOONTIP             ' No Start Menu Balloon Tip
    REST_NOSMHELP                   ' No Help on the Start Menu
    REST_NOWINKEYS                  ' No Windows-X Hot keys
    REST_NOENCRYPTONMOVE            ' Don't automatically try to encrypt files that are moved to encryped directories
    REST_NOLOCALMACHINERUN          ' ignore HKLM\sw\ms\win\cv\Run and all of it's sub keys
    REST_NOCURRENTUSERRUN           ' ignore HKCU\sw\ms\win\cv\Run and all of it's sub keys
    REST_NOLOCALMACHINERUNONCE      ' ignore HKLM\sw\ms\win\cv\RunOnce and all of it's sub keys
    REST_NOCURRENTUSERRUNONCE       ' ignore HKCU\sw\ms\win\cv\RunOnce and all of it's sub keys
    REST_FORCEACTIVEDESKTOPON       ' Force ActiveDesktop to be turned ON all the time.
    REST_reserved3
    REST_NOVIEWONDRIVE              ' disallows CreateViewObject() on specified drives (CFSFolder only)
#IF (%NTDDI_VERSION >= %NTDDI_WINXP) OR %DEF(%IE_BACKCOMPAT_VERSION)
    REST_NONETCRAWL  = &H4000004D   ' disables the crawling of the WNet namespace.
    REST_NOSHAREDDOCUMENTS          ' don't auto share the Shared Documents/create link
#ENDIF  ' %NTDDI_WINXP
    REST_NOSMMYDOCS = &H4000004F    ' Don't show the My Documents item on the Start Menu.
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
    REST_NOSMMYPICS = &H40000050    ' Don't show the My Pictures item on the Start Menu
    REST_ALLOWBITBUCKDRIVES         ' Bit mask indicating which which drives have bit bucket support
    REST_NONLEGACYSHELLMODE         ' new consumer shell modes
    REST_NOCONTROLPANELBARRICADE    ' The webview barricade in Control Panel
    REST_NOSTARTPAGE                ' Whistler Start Page on desktop.
    REST_NOAUTOTRAYNOTIFY           ' Whistler auto-tray notify feature
    REST_NOTASKGROUPING             ' Whistler taskbar button grouping feature
    REST_NOCDBURNING                ' whistler cd burning feature
#ENDIF  ' %NTDDI_WINXP
#IF (%NTDDI_VERSION >= %NTDDI_WIN2KSP3)
    REST_MYCOMPNOPROP = &H40000058  ' disables Properties on My Computer's context menu
    REST_MYDOCSNOPROP               ' disables Properties on My Documents' context menu
#ENDIF  ' %NTDDI_WIN2KSP3
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
    REST_NOSTARTPANEL = &H4000005A  ' Windows start panel (New start menu) for Whistler.
    REST_NODISPLAYAPPEARANCEPAGE    ' disable Themes and Appearance tabs in the Display Control Panel.
    REST_NOTHEMESTAB                ' disable the Themes tab in the Display Control Panel.
    REST_NOVISUALSTYLECHOICE        ' disable the visual style drop down in the Appearance tab of the Display Control Panel.
    REST_NOSIZECHOICE               ' disable the size drop down in the Appearance tab of the Display Control Panel.
    REST_NOCOLORCHOICE              ' disable the color drop down in the Appearance tab of the Display Control Panel.
    REST_SETVISUALSTYLE             ' Load the specified file as the visual style.
#ENDIF  ' %NTDDI_WINXP
#IF (%NTDDI_VERSION >= %NTDDI_WIN2KSP3)
    REST_STARTRUNNOHOMEPATH = &H40000061 ' dont use the %HOMEPATH% env var for the Start-Run dialog
#ENDIF  ' %NTDDI_WIN2KSP3
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
    REST_NOUSERNAMEINSTARTPANEL = &H40000062   ' don't show the username is the startpanel.
    REST_NOMYCOMPUTERICON           ' don't show my computer anywhere, hide its contents
    REST_NOSMNETWORKPLACES          ' don't show network places in startpanel.
    REST_NOSMPINNEDLIST             ' don't show the pinned list in startpanel.
    REST_NOSMMYMUSIC                ' don't show MyMusic folder in startpanel
    REST_NOSMEJECTPC                ' don't show "Undoc PC" command in startmenu
    REST_NOSMMOREPROGRAMS           ' don't show "More Programs" button in StartPanel.
    REST_NOSMMFUPROGRAMS            ' don't show the MFU programs list in StartPanel.
    REST_NOTRAYITEMSDISPLAY         ' disables the display of the system tray
    REST_NOTOOLBARSONTASKBAR        ' disables toolbar display on the taskbar
#ENDIF  ' %NTDDI_WINXP
#IF (%NTDDI_VERSION >= %NTDDI_WIN2KSP3)
    REST_NOSMCONFIGUREPROGRAMS = &H4000006F ' No Configure Programs on Settings Menu
#ENDIF  ' %NTDDI_WIN2KSP3
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
    REST_HIDECLOCK = &H40000070     ' don't show the clock
    REST_NOLOWDISKSPACECHECKS       ' disable the low disk space checking
#ENDIF  ' %NTDDI_WINXP
#IF (%NTDDI_VERSION >= %NTDDI_WIN2KSP4)
    REST_NOENTIRENETWORK = &H40000072  ' removes the "Entire Network" link (i.e. from "My Network Places")
#ENDIF  ' %NTDDI_WIN2KSP4
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
    REST_NODESKTOPCLEANUP = &H40000073 ' disable the desktop cleanup wizard
    REST_BITBUCKNUKEONDELETE        ' disables recycling of files
    REST_BITBUCKCONFIRMDELETE       ' always show the delete confirmation dialog when deleting files
    REST_BITBUCKNOPROP              ' disables Properties on Recycle Bin's context menu
    REST_NODISPBACKGROUND           ' disables the Desktop tab in the Display CPL
    REST_NODISPSCREENSAVEPG         ' disables the Screen Saver tab in the Display CPL
    REST_NODISPSETTINGSPG           ' disables the Settings tab in the Display CPL
    REST_NODISPSCREENSAVEPREVIEW    ' disables the screen saver on the Screen Saver tab in the Display CPL
    REST_NODISPLAYCPL               ' disables the Display CPL
    REST_HIDERUNASVERB              ' hides the "Run As..." context menu item
    REST_NOTHUMBNAILCACHE           ' disables use of the thumbnail cache
#ENDIF  ' %NTDDI_WINXP
#IF (%NTDDI_VERSION >= %NTDDI_WINXPSP1) OR %DEF(%IE_BACKCOMPAT_VERSION)
    REST_NOSTRCMPLOGICAL = &H4000007E  ' dont use StrCmpLogical() instead use default CompareString()
    REST_NOPUBLISHWIZARD            ' disables publishing wizard (WPW)
    REST_NOONLINEPRINTSWIZARD       ' disables online prints wizard (OPW)
    REST_NOWEBSERVICES              ' disables the web specified services for both OPW and WPW
#ENDIF  ' %NTDDI_WINXPSP1
#IF (%NTDDI_VERSION >= %NTDDI_WIN2KSP3)
    REST_ALLOWUNHASHEDWEBVIEW = &H40000082  ' allow the user to be promted to accept web view templates that don't already have an md5 hash in the registry
#ENDIF  ' %NTDDI_WIN2KSP3
    REST_ALLOWLEGACYWEBVIEW = &H40000083    ' allow legacy webview template to be shown.
#IF (%NTDDI_VERSION >= %NTDDI_WIN2KSP3)
    REST_REVERTWEBVIEWSECURITY = &H40000084 ' disable added webview security measures (revert to w2k functionality).
#ENDIF  ' %NTDDI_WIN2KSP3
#IF (%NTDDI_VERSION >= %NTDDI_WIN2KSP4)
    REST_INHERITCONSOLEHANDLES = &H40000086 ' ShellExec() will check for the current process and target process being console processes to inherit handles
#ENDIF  ' %NTDDI_WIN2KSP4
#IF (%NTDDI_VERSION >= %NTDDI_WINXPSP2 AND %NTDDI_VERSION < %NTDDI_VISTA)
    REST_SORTMAXITEMCOUNT = &H40000087      ' Do not sort views with more items than this key. Useful for viewing big amount of files in one folder.
#ENDIF
#IF (%NTDDI_VERSION >= %NTDDI_WINXPSP2)
    REST_NOREMOTERECURSIVEEVENTS = &H40000089 ' Dont register network change events recursively to avoid network traffic
#ENDIF  ' %NTDDI_WINXPSP2
#IF (%NTDDI_VERSION >= %NTDDI_WINXPSP2)
    REST_NOREMOTECHANGENOTIFY = &H40000091  ' Do not notify for remote changy notifies
#IF (%NTDDI_VERSION < %NTDDI_VISTA)
    REST_NOSIMPLENETIDLIST = &H40000092     ' No simple network IDLists
#ENDIF
    REST_NOENUMENTIRENETWORK = &H40000093   ' Don't enumerate entire network if we happen to get to it (in conjunction with REST_NOENTIRENETWORK)
#IF (%NTDDI_VERSION < %NTDDI_VISTA)
    REST_NODETAILSTHUMBNAILONNETWORK = &H40000094 ' Disable Thumbnail for Network files in DUI Details pane
#ENDIF
    REST_NOINTERNETOPENWITH = &H40000095    ' dont allow looking on the internet for file associations
#ENDIF  ' %NTDDI_WINXPSP2
#IF (%NTDDI_VERSION >= %NTDDI_WINXPSP2)
    REST_DONTRETRYBADNETNAME = &H4000009B   ' In Network Places: if provider returns ERROR_BAD_NET_NAME, give up
    REST_ALLOWFILECLSIDJUNCTIONS    ' re-enable legacy support for file.{guid} junctions in FileSystem Folder
    REST_NOUPNPINSTALL              ' disable "install UPnP" task in My Net Places
#ENDIF  ' %NTDDI_WINXPSP2
    REST_ARP_DONTGROUPPATCHES = &H400000AC  ' List individual patches in Add/Remove Programs
    REST_ARP_NOCHOOSEPROGRAMSPAGE   'Choose programs page

    REST_NODISCONNECT = &H41000001  ' No Disconnect option in Start menu
    REST_NOSECURITY                 ' No Security option in start menu
    REST_NOFILEASSOCIATE            ' Do not allow user to change file association
#IF (%NTDDI_VERSION >= %NTDDI_WINXPSP2)
    REST_ALLOWCOMMENTTOGGLE = &H41000004    ' Allow the user to toggle the positions of the Comment and the Computer Name
#IF (%NTDDI_VERSION < %NTDDI_VISTA)
    REST_USEDESKTOPINICACHE = &H41000005    ' Cache desktop.ini entries from network folders
#ENDIF  ' %NTDDI_VISTA
#ENDIF  ' %NTDDI_WINXPSP2
END ENUM

DECLARE FUNCTION OpenRegStream LIB "Shell32.dll" ALIAS "OpenRegStream" _
    (BYVAL hkey AS DWORD, pszSubkey AS WSTRINGZ, pszValue AS WSTRINGZ, _
    BYVAL grfMode AS DWORD) AS DWORD

DECLARE FUNCTION SHFindFiles LIB "Shell32.dll" ALIAS "SHFindFiles" _
    (pidlFolder AS ITEMIDLIST, pidlSaveFile AS ITEMIDLIST) AS LONG

DECLARE SUB PathGetShortPath LIB "Shell32.dll" ALIAS "PathGetShortPath" _
    (pszLongPath AS WSTRINGZ)

DECLARE FUNCTION PathYetAnotherMakeUniqueName LIB "Shell32.dll" _
    ALIAS "PathYetAnotherMakeUniqueName" (pszUniqueName AS WSTRINGZ, _
    pszPath AS WSTRINGZ, pszShort AS WSTRINGZ, pszFileSpec AS WSTRINGZ) AS LONG

DECLARE FUNCTION Win32DeleteFile LIB "Shell32.dll" ALIAS "Win32DeleteFile" _
    (pszPath AS WSTRINGZ) AS LONG

#IF (%NTDDI_VERSION < %NTDDI_VISTA)
'
' Path processing function
'
%PPCF_ADDQUOTES               = &H00000001        ' return a quoted name if required
%PPCF_ADDARGUMENTS            = &H00000003        ' appends arguments (and wraps in quotes if required)
%PPCF_NODIRECTORIES           = &H00000010        ' don't match to directories
%PPCF_FORCEQUALIFY            = &H00000040        ' qualify even non-relative names
%PPCF_LONGESTPOSSIBLE         = &H00000080        ' always find the longest possible name

DECLARE FUNCTION PathProcessCommand LIB "Shell32.dll" _
    ALIAS "PathProcessCommand" (lpSrc AS WSTRINGZ, lpDest AS WSTRINGZ, _
    BYVAL iMax AS LONG, BYVAL dwFlags AS DWORD) AS LONG

#ENDIF

DECLARE FUNCTION SHRestricted LIB "Shell32.dll" ALIAS "SHRestricted" _
    (BYVAL rest AS LONG) AS DWORD

DECLARE FUNCTION SignalFileOpen LIB "Shell32.dll" ALIAS "SignalFileOpen" _
    (pidl AS ITEMIDLIST) AS LONG

DECLARE FUNCTION SHSimpleIDListFromPath LIB "Shell32.dll" _
    ALIAS "SHSimpleIDListFromPath" (pszPath AS WSTRINGZ) AS DWORD

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

DECLARE FUNCTION AssocGetDetailsOfPropKey LIB "Shell32.dll" _
    ALIAS "AssocGetDetailsOfPropKey" (psf AS ANY, pidl AS ITEMIDLIST, _
    pkey AS PROPERTYKEY, pv AS VARIANT, pfFoundPropKey AS LONG) AS LONG

#ENDIF

#IF (%NTDDI_VERSION < %NTDDI_VISTA)

DECLARE FUNCTION SHLoadOLE LIB "Shell32.dll" ALIAS "SHLoadOLE" _
    (BYVAL lParam AS LONG) AS LONG

#ENDIF

' both ANSI and UNICODE
DECLARE FUNCTION SHStartNetConnectionDialogA LIB "Shell32.dll" _
    ALIAS "SHStartNetConnectionDialogA" (BYVAL hwnd AS DWORD, _
    pszRemoteName AS ASCIIZ, BYVAL dwType AS DWORD) AS LONG

' both ANSI and UNICODE
DECLARE FUNCTION SHStartNetConnectionDialogW LIB "Shell32.dll" _
    ALIAS "SHStartNetConnectionDialogW" (BYVAL hwnd AS DWORD, _
    pszRemoteName AS WSTRINGZ, BYVAL dwType AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHStartNetConnectionDialog LIB "Shell32.dll" _
    ALIAS "SHStartNetConnectionDialogW" (BYVAL hwnd AS DWORD, _
    pszRemoteName AS WSTRINGZ, BYVAL dwType AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SHStartNetConnectionDialog LIB "Shell32.dll" _
    ALIAS "SHStartNetConnectionDialogA" (BYVAL hwnd AS DWORD, _
    pszRemoteName AS ASCIIZ, BYVAL dwType AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SHDefExtractIconA LIB "Shell32.dll" _
    ALIAS "SHDefExtractIconA" (pszIconFile AS ASCIIZ, BYVAL iIndex AS LONG, _
    BYVAL uFlags AS DWORD, phiconLarge AS DWORD, phiconSmall AS DWORD, _
    BYVAL nIconSize AS DWORD) AS LONG

DECLARE FUNCTION SHDefExtractIconW LIB "Shell32.dll" _
    ALIAS "SHDefExtractIconW" (pszIconFile AS WSTRINGZ, BYVAL iIndex AS LONG, _
    BYVAL uFlags AS DWORD, phiconLarge AS DWORD, phiconSmall AS DWORD, _
    BYVAL nIconSize AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHDefExtractIcon LIB "Shell32.dll" _
    ALIAS "SHDefExtractIconW" (pszIconFile AS WSTRINGZ, BYVAL iIndex AS LONG, _
    BYVAL uFlags AS DWORD, phiconLarge AS DWORD, phiconSmall AS DWORD, _
    BYVAL nIconSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SHDefExtractIcon LIB "Shell32.dll" _
    ALIAS "SHDefExtractIconA" (pszIconFile AS ASCIIZ, BYVAL iIndex AS LONG, _
    BYVAL uFlags AS DWORD, phiconLarge AS DWORD, phiconSmall AS DWORD, _
    BYVAL nIconSize AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

' Elevation

' OpenAsInfo flags
MACRO OPEN_AS_INFO_FLAGS_enum=LONG
ENUM OPEN_AS_INFO_FLAGS BITS SINGULAR
    OAIF_ALLOW_REGISTRATION = 1  ' enable the "always use this file" checkbox (NOTE if you don't pass this, it will be disabled)
    OAIF_REGISTER_EXT            ' do the registration after the user hits "ok"
    OAIF_EXEC                    ' execute file after registering
    OAIF_FORCE_REGISTRATION      ' force the "always use this file" checkbox to be checked (normally, you won't use the OAIF_ALLOW_REGISTRATION when you pass this)
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
    OAIF_HIDE_REGISTRATION  = 32 ' hide the "always use this file" checkbox
    OAIF_URL_PROTOCOL            ' the "extension" passed is actually a protocol, and open with should show apps registered as capable of handling that protocol
#ENDIF
END ENUM


TYPE OPENASINFO QWORD FILL
    pcszFile    AS WSTRINGZ PTR   ' [in] file name, or protocol name if
                                  '      OAIF_URL_PROTOCOL is set.
    pcszClass   AS WSTRINGZ PTR   ' [in] file class description. NULL means
                                  '      use pcszFile's extension. ignored
                                  '      if OAIF_URL_PROTOCOL is set.
    oaifInFlags AS OPEN_AS_INFO_FLAGS_enum  ' [in] input flags from OPEN_AS_INFO_FLAGS enumeration
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
DECLARE FUNCTION SHOpenWithDialog LIB "Shell32.dll" ALIAS "SHOpenWithDialog" _
    (BYVAL hwndParent AS DWORD, poainfo AS OPENASINFO) AS LONG
#ENDIF

DECLARE FUNCTION Shell_GetImageLists LIB "Shell32.dll" _
    ALIAS "Shell_GetImageLists" (phiml AS DWORD, phimlSmall AS DWORD) AS LONG

#IF (%NTDDI_VERSION < %NTDDI_VISTA)

DECLARE FUNCTION Shell_GetCachedImageIndex LIB "Shell32.dll" _
    ALIAS "Shell_GetCachedImageIndex" (pwszIconPath AS WSTRINGZ, _
    BYVAL iIconIndex AS LONG, BYVAL uIconFlags AS DWORD) AS LONG

#ELSE

DECLARE FUNCTION Shell_GetCachedImageIndexA LIB "Shell32.dll" _
    ALIAS "Shell_GetCachedImageIndexA" (pwszIconPath AS ASCIIZ, _
    BYVAL iIconIndex AS LONG, BYVAL uIconFlags AS DWORD) AS LONG

DECLARE FUNCTION Shell_GetCachedImageIndexW LIB "Shell32.dll" _
    ALIAS "Shell_GetCachedImageIndexW" (pwszIconPath AS WSTRINGZ, _
    BYVAL iIconIndex AS LONG, BYVAL uIconFlags AS DWORD) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION Shell_GetCachedImageIndex LIB "Shell32.dll" _
    ALIAS "Shell_GetCachedImageIndexW" (pwszIconPath AS WSTRINGZ, _
    BYVAL iIconIndex AS LONG, BYVAL uIconFlags AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION Shell_GetCachedImageIndex LIB "Shell32.dll" _
    ALIAS "Shell_GetCachedImageIndexA" (pwszIconPath AS ASCIIZ, _
    BYVAL iIconIndex AS LONG, BYVAL uIconFlags AS DWORD) AS LONG
#ENDIF ' NOT %UNICODE

#ENDIF  ' #IF (%NTDDI_VERSION < %NTDDI_VISTA)


'
' IDocViewSite
'
'#undef  INTERFACE
'#define INTERFACE  IDocViewSite
'
'DECLARE_INTERFACE_IID_(IDocViewSite, IUnknown, "87D605E0-C511-11CF-89A9-00A0C9054129")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
'    STDMETHOD_(ULONG,Release)(THIS) PURE;
'
'    ' *** IDocViewSite methods ***
'    STDMETHOD(OnSetTitle) (THIS_ VARIANTARG *pvTitle) PURE;
'
'};

%VALIDATEUNC_CONNECT     = &H0001          ' connect a drive letter
%VALIDATEUNC_NOUI        = &H0002          ' don't bring up UI
%VALIDATEUNC_PRINT       = &H0004          ' validate as print share instead of disk share
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%VALIDATEUNC_PERSIST     = &H0008          ' the connection should be made persistent
%VALIDATEUNC_VALID       = &H000F          ' valid flags
#ELSE
%VALIDATEUNC_VALID       = &H0007          ' valid flags
#ENDIF

DECLARE FUNCTION SHValidateUNC LIB "Shell32.dll" ALIAS "SHValidateUNC" _
    (BYVAL hwndOwner AS DWORD, pszFile AS WSTRINGZ, BYVAL fConnect AS DWORD) _
    AS LONG

%OPENPROPS_NONE          = &H0000
%OPENPROPS_INHIBITPIF    = &H8000??
%GETPROPS_NONE           = &H0000
%SETPROPS_NONE           = &H0000
%CLOSEPROPS_NONE         = &H0000
%CLOSEPROPS_DISCARD      = &H0001

%PIFNAMESIZE     = 30
%PIFSTARTLOCSIZE = 63
%PIFDEFPATHSIZE  = 64
%PIFPARAMSSIZE   = 64
%PIFSHPROGSIZE   = 64
%PIFSHDATASIZE   = 64
%PIFDEFFILESIZE  = 80
%PIFMAXFILEPATH  = 260

TYPE PROPPRG
    flPrg           AS WORD                         ' see PRG_ flags
    flPrgInit       AS WORD                         ' see PRGINIT_ flags
    achTitle        AS WSTRINGZ * %PIFNAMESIZE      ' name[30]
    achCmdLine      AS WSTRINGZ * %PIFSTARTLOCSIZE+%PIFPARAMSSIZE+1    ' startfile[63] + params[64]
    achWorkDir      AS WSTRINGZ * %PIFDEFPATHSIZE   ' defpath[64]
    wHotKey         AS WORD                         ' PfHotKeyScan thru PfHotKeyVal
    achIconFile     AS WSTRINGZ * %PIFDEFFILESIZE   ' name of file containing icon
    wIconIndex      AS WORD                         ' index of icon within file
    dwEnhModeFlags  AS DWORD                        ' reserved enh-mode flags
    dwRealModeFlags AS DWORD                        ' real-mode flags (see RMOPT_*)
    achOtherFile    AS WSTRINGZ * %PIFDEFFILESIZE   ' name of "other" file in directory
    achPIFFile      AS WSTRINGZ * %PIFMAXFILEPATH   ' name of PIF file
END TYPE

DECLARE FUNCTION PifMgr_OpenProperties LIB "Shell32.dll" _
    ALIAS "PifMgr_OpenProperties" (pszApp AS WSTRINGZ, pszPIF AS WSTRINGZ, _
    BYVAL hInf AS DWORD, BYVAL flOpt AS DWORD) AS DWORD

DECLARE FUNCTION PifMgr_GetProperties LIB "Shell32.dll" _
    ALIAS "PifMgr_GetProperties" (BYVAL hProps AS DWORD, pszGroup AS ASCIIZ, _
    lpProps AS ANY, BYVAL cbProps AS LONG, BYVAL flOpt AS DWORD) AS LONG

DECLARE FUNCTION PifMgr_SetProperties LIB "Shell32.dll" _
    ALIAS "PifMgr_SetProperties" (BYVAL hProps AS DWORD, _
    pszGroup AS ASCIIZ, lpProps AS ANY, BYVAL cbProps AS LONG, _
    BYVAL flOpt AS DWORD) AS LONG

DECLARE FUNCTION PifMgr_CloseProperties LIB "Shell32.dll" _
    ALIAS "PifMgr_CloseProperties" (BYVAL hProps AS DWORD, _
    BYVAL flOpt AS DWORD) AS DWORD

DECLARE SUB SHSetInstanceExplorer LIB "Shell32.dll" _
    ALIAS "SHSetInstanceExplorer" (punk AS ANY)

DECLARE FUNCTION IsUserAnAdmin LIB "Shell32.dll" ALIAS "IsUserAnAdmin" () _
    AS LONG

'#undef  INTERFACE
'#define INTERFACE   IInitializeObject
'
'DECLARE_INTERFACE_IID_(IInitializeObject, IUnknown, "4622AD16-FF23-11d0-8D34-00A0C90F2719")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** IInitializeObject methods
'    STDMETHOD(Initialize)(THIS) PURE;
'};


%BMICON_LARGE = 0
%BMICON_SMALL = 1

'#undef  INTERFACE
'#define INTERFACE   IBanneredBar
'
'DECLARE_INTERFACE_IID_(IBanneredBar, IUnknown, "596A9A94-013E-11d1-8D34-00A0C90F2719")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** IBanneredBar methods ***
'    STDMETHOD(SetIconSize)(THIS_ DWORD iIcon) PURE;
'    STDMETHOD(GetIconSize)(THIS_ DWORD* piIcon) PURE;
'    STDMETHOD(SetBitmap)(THIS_ HBITMAP hBitmap) PURE;
'    STDMETHOD(GetBitmap)(THIS_ HBITMAP* phBitmap) PURE;
'
'};

DECLARE FUNCTION SHShellFolderView_Message LIB "Shell32.dll" _
    ALIAS "SHShellFolderView_Message" (BYVAL hwndMain AS DWORD, _
    BYVAL uMsg AS DWORD, BYVAL lParam AS LONG) AS LONG

'
' Callback interface for the IShellView object returned from SHCreateShellFolderView.

'
'#undef  INTERFACE
'#define INTERFACE   IShellFolderViewCB
'
'DECLARE_INTERFACE_IID_(IShellFolderViewCB, IUnknown, "2047E320-F2A9-11CE-AE65-08002B2E1262")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** IShellFolderViewCB methods ***
'    STDMETHOD(MessageSFVCB)(THIS_ UINT uMsg, WPARAM wParam, LPARAM lParam) PURE;
'};


%QCMINFO_PLACE_BEFORE   =  0
%QCMINFO_PLACE_AFTER    =  1

TYPE QCMINFO_IDMAP_PLACEMENT QWORD FILL
    ID     AS DWORD
    fFlags AS DWORD
END TYPE

TYPE QCMINFO_IDMAP QWORD FILL
    nMaxIds    AS DWORD
    pIdList(0) AS QCMINFO_IDMAP_PLACEMENT
END TYPE

TYPE QCMINFO QWORD FILL
    hMenu      AS DWORD              ' in
    indexMenu  AS DWORD              ' in
    idCmdFirst AS DWORD              ' in/out
    idCmdLast  AS DWORD              ' in
    pIdMap     AS QCMINFO_IDMAP PTR  ' in / unused
END TYPE

' TBINFO flags
%TBIF_APPEND          = 0
%TBIF_PREPEND         = 1
%TBIF_REPLACE         = 2
%TBIF_DEFAULT         = &H00000000
%TBIF_INTERNETBAR     = &H00010000
%TBIF_STANDARDTOOLBAR = &H00020000
%TBIF_NOTOOLBAR       = &H00030000

TYPE TBINFO QWORD FILL
    cbuttons AS DWORD               ' out
    uFlags   AS DWORD               ' out (one of TBIF_ flags)
END TYPE


TYPE DETAILSINFO QWORD FILL
    pidl   AS ITEMIDLIST PTR  ' PCUITEMID_CHILD
    fmt    AS LONG
    cxChar AS LONG
    str    AS STRRET
    iImage AS LONG
END TYPE

TYPE SFVM_PROPPAGE_DATA QWORD FILL
    dwReserved AS DWORD
    pfn        AS DWORD ' LPFNADDPROPSHEETPAGE
    lParam     AS LONG  ' LPARAM
END TYPE

TYPE SFVM_HELPTOPIC_DATA QWORD FILL
    wszHelpFile  AS WSTRINGZ * %MAX_PATH
    wszHelpTopic AS WSTRINGZ * %MAX_PATH
END TYPE

'                                 uMsg    wParam             lParam
%SFVM_MERGEMENU            =  1    ' -                  LPQCMINFO
%SFVM_INVOKECOMMAND        =  2    ' idCmd              -
%SFVM_GETHELPTEXT          =  3    ' idCmd,cchMax       pszText
%SFVM_GETTOOLTIPTEXT       =  4    ' idCmd,cchMax       pszText
%SFVM_GETBUTTONINFO        =  5    ' -                  LPTBINFO
%SFVM_GETBUTTONS           =  6    ' idCmdFirst,cbtnMax LPTBBUTTON
%SFVM_INITMENUPOPUP        =  7    ' idCmdFirst,nIndex  hmenu
%SFVM_FSNOTIFY            =  14    ' LPCITEMIDLIST*     lEvent
%SFVM_WINDOWCREATED       =  15    ' hwnd               -
%SFVM_GETDETAILSOF        =  23    ' iColumn            DETAILSINFO*
%SFVM_COLUMNCLICK         =  24    ' iColumn            -
%SFVM_QUERYFSNOTIFY       =  25    ' -                  SHChangeNotifyEntry *
%SFVM_DEFITEMCOUNT        =  26    ' -                  UINT*
%SFVM_DEFVIEWMODE         =  27    ' -                  FOLDERVIEWMODE*
%SFVM_UNMERGEMENU         =  28    ' -                  hmenu
%SFVM_UPDATESTATUSBAR     =  31    ' fInitialize        -
%SFVM_BACKGROUNDENUM      =  32    ' -                  -
%SFVM_DIDDRAGDROP         =  36    ' dwEffect           IDataObject *
%SFVM_SETISFV             =  39    ' -                  IShellFolderView*
%SFVM_THISIDLIST          =  41    ' -                  LPITMIDLIST*
%SFVM_ADDPROPERTYPAGES    =  47    ' -                  SFVM_PROPPAGE_DATA *
%SFVM_BACKGROUNDENUMDONE  =  48    ' -                  -
%SFVM_GETNOTIFY           =  49    ' LPITEMIDLIST*      LONG*
' Note: SFVM_QUERYSTANDARDVIEWS NOT USED: must use SFVM_GETVIEWDATA instead
%SFVM_GETSORTDEFAULTS     =  53    ' iDirection         iParamSort
%SFVM_SIZE                =  57    ' -                  -
%SFVM_GETZONE             =  58    ' -                  DWORD*
%SFVM_GETPANE             =  59    ' Pane ID            DWORD*
%SFVM_GETHELPTOPIC        =  63    ' -                  SFVM_HELPTOPIC_DATA *
%SFVM_GETANIMATION        =  68    ' HINSTANCE *        WCHAR *

' IShellFolderView
'
' Deprecated: use IFolderView and IFolderView2 instead.
'
' IShellFolderView is supported by the IShellView object returned from SHCreateShellFolderView.
'
' Warnings:
'  - Some methods on this interface do not follow standard COM rules.
'  - Some methods can be used to configure the IShellView or cause it to behave incorrectly.
'  - Few of these methods have parameter or range validation, so callers can cause the IShellView to fault.

TYPE ITEMSPACING
    cxSmall AS LONG
    cySmall AS LONG
    cxLarge AS LONG
    cyLarge AS LONG
END TYPE

' defines for IShellFolderView::SetObjectCount
%SFVSOC_INVALIDATE_ALL   = &H00000001  ' Assumed to reset only what is necessary...
%SFVSOC_NOSCROLL         = &H00000002  ' %LVSICF_NOSCROLL

' defines for IShellFolderView::SelectItems()
%SFVS_SELECT_NONE        = &H0 ' unselect all
%SFVS_SELECT_ALLITEMS    = &H1 ' select all
%SFVS_SELECT_INVERT      = &H2 ' Inver the selection

'#undef  INTERFACE
'#define INTERFACE   IShellFolderView
'
'DECLARE_INTERFACE_IID_(IShellFolderView, IUnknown, "37A378C0-F82D-11CE-AE65-08002B2E1262")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'
'    ' *** IShellFolderView methods ***
'    STDMETHOD(Rearrange) (THIS_ LPARAM lParamSort) PURE; ' use IFolderView2::SetSortColumns
'    STDMETHOD(GetArrangeParam) (THIS_ LPARAM *plParamSort) PURE; ' use IFolderView2::GetSortColumns
'    STDMETHOD(ArrangeGrid) (THIS) PURE; ' select Arrange by Grid
'    STDMETHOD(AutoArrange) (THIS) PURE; ' select Auto Arrange
'    STDMETHOD(GetAutoArrange) (THIS) PURE; ' use IFolderView::GetAutoArrange
'    STDMETHOD(AddObject) (THIS_ PUITEMID_CHILD pidl, UINT *puItem) PURE; ' items added here may disappear (the data source is the final arbiter of which items are available to the view)
'    STDMETHOD(GetObject) (THIS_ PITEMID_CHILD *ppidl, UINT uItem) PURE; ' use IFolderView::Item
'    STDMETHOD(RemoveObject) (THIS_ PUITEMID_CHILD pidl, UINT *puItem) PURE; ' items removed here may reappear (the data source is the final arbiter of which items are available to the view)
'    STDMETHOD(GetObjectCount) (THIS_ UINT *puCount) PURE; ' use IFolderView::ItemCount
'    STDMETHOD(SetObjectCount) (THIS_ UINT uCount, UINT dwFlags) PURE; ' not implemented on Vista.  Sends LVM_SETITEMCOUNT with WPARAM=uCount and LPARAM=dwFlags to listview on XP.
'    STDMETHOD(UpdateObject) (THIS_ PUITEMID_CHILD pidlOld, PUITEMID_CHILD pidlNew, UINT *puItem) PURE; ' swaps ITEMID_CHILDs, returning new index.
''        Changes may be discarded (the data source is the final arbiter of which items are available to the view)
'    STDMETHOD(RefreshObject) (THIS_ PUITEMID_CHILD pidl, UINT *puItem) PURE; ' tickles the listview to re-draw the item
'    STDMETHOD(SetRedraw) (THIS_ BOOL bRedraw) PURE; ' sends WM_SETREDRAW to the listview
'    STDMETHOD(GetSelectedCount) (THIS_ UINT *puSelected) PURE; ' use IFolderView2::GetSelection
'    ' NOTE: GetSelectedObjects hands out const pointers to internal ITEMID_CHILD structures. The caller is expected to act on them immediately (and not cache them).  LocalFree the array, but not the items it contains.
'    STDMETHOD(GetSelectedObjects) (THIS_ PCUITEMID_CHILD **pppidl, UINT *puItems) PURE; ' use IFolderView2::GetSelection.
'    STDMETHOD(IsDropOnSource) (THIS_ IDropTarget *pDropTarget) PURE; ' use IFolderView2::IsMoveInSameFolder
'    STDMETHOD(GetDragPoint) (THIS_ POINT *ppt) PURE; ' returns point corresponding to drag-and-drop operation
'    STDMETHOD(GetDropPoint) (THIS_ POINT *ppt) PURE; ' returns point corresponding to drag-and-drop operation
'    STDMETHOD(MoveIcons) (THIS_ IDataObject *pDataObject) PURE; ' not implemented
'    STDMETHOD(SetItemPos) (THIS_ PCUITEMID_CHILD pidl, POINT *ppt) PURE; ' use IFolderView::SelectAndPositionItems
'    STDMETHOD(IsBkDropTarget) (THIS_ IDropTarget *pDropTarget) PURE; ' returns S_OK if drag-and-drop is on the background, S_FALSE otherwise
'    STDMETHOD(SetClipboard) (THIS_ BOOL bMove) PURE; ' if bMove is TRUE, this attempts to cut (edit.cut, ctrl-x) the current selection.  bMove of FALSE is not supported.
'    STDMETHOD(SetPoints) (THIS_ IDataObject *pDataObject) PURE; ' copies points of current selection in to data object.  Call is not needed if drag operation was originated by the IShellView.
'    STDMETHOD(GetItemSpacing) (THIS_ ITEMSPACING *pSpacing) PURE; ' use IFolderView::GetSpacing instead.
''        GetItemSpacing returns the spacing for small and large view modes only, returning S_OK if the current view mode is is positionable, S_FALSE otherwise.
'    STDMETHOD(SetCallback) (THIS_ IShellFolderViewCB* pNewCB, IShellFolderViewCB** ppOldCB) PURE; ' replace the IShellFolderViewCB that the IShellView uses
'    STDMETHOD(Select) ( THIS_  UINT dwFlags ) PURE; ' SFVS_ select flags: select all, select none, invert selection
'    STDMETHOD(QuerySupport) (THIS_ UINT * pdwSupport ) PURE; ' does nothing, returns S_OK.
'    STDMETHOD(SetAutomationObject)(THIS_ IDispatch* pdisp) PURE; ' replaces the IShellView's internal automation object.
'} ;

' SHCreateShellFolderView struct
TYPE SFV_CREATE
    cbSize   AS DWORD               ' must be sizeof(SFV_CREATE)
    pshf     AS DWORD 'IShellFolder PTR    ' IShellFolder the IShellView will use
    psvOuter AS DWORD ' IShellView PTR      ' optional: IShellView to pass to psfvcb
    psfvcb   AS DWORD ' IShellFolderViewCB PTR  ' No callback if NULL
END TYPE

DECLARE FUNCTION SHCreateShellFolderView LIB "Shell32.dll" _
    ALIAS "SHCreateShellFolderView" (pcsfv AS SFV_CREATE, ppsv AS ANY) AS LONG

DECLARE FUNCTION LPFNDFMCALLBACK (psf AS ANY, BYVAL hWnd AS DWORD, _
    pdtobj AS ANY, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION CDefFolderMenu_Create2 LIB "Shell32.dll" _
    ALIAS "CDefFolderMenu_Create2" (pidlFolder AS ITEMIDLIST, _
    BYVAL hwnd AS DWORD, BYVAL cidl AS DWORD, apidl AS ITEMIDLIST, _
    psf AS ANY, BYVAL pfn AS DWORD, BYVAL nKeys AS DWORD, _
    BYVAL ahKeys AS DWORD PTR, ppcm AS ANY) AS LONG

TYPE DEFCONTEXTMENU
    hwnd       AS DWORD
    pcmcb      AS DWORD ' IContextMenuCB PTR    ' optional: callback object
    pidlFolder AS ITEMIDLIST PTR ' PCIDLIST_ABSOLUTE     ' optional: IDList to folder of the items, computed from psf if NULL
    psf        AS DWORD ' IShellFolder PTR             ' folder of the items
    cidl       AS DWORD                 ' # of items in apidl
    apidl      AS ITEMIDLIST PTR ' PCUITEMID_CHILD_ARRAY ' items operating on, used to get IDataObject and IAssociationArray
    punkAssociationInfo AS DWORD ' IUNKNOWN PTR ' optional: IQueryAssociations, specifies where to load extensions from, computed from apidl if NULL
    cKeys      AS DWORD                 ' # of items in aKeys, may be zero
    aKeys      AS DWORD PTR             ' optional: specifies where to load extensions from
END TYPE

' creates object that implements IContextMenu/IContextMenu2/IContextMenu3, typically
' used in the implementation of ::GetUIObjectOf()

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
DECLARE FUNCTION SHCreateDefaultContextMenu LIB "Shell32.dll" _
    ALIAS "SHCreateDefaultContextMenu" (pdcm AS DEFCONTEXTMENU, _
    riid AS GUID, ppv AS ANY) AS LONG
#ENDIF

' [undocumented and apparently not exported]
'DECLARE FUNCTION SHOpenPropSheetA LIB "Shell32.dll" _
'    ALIAS "SHOpenPropSheetA" (pszCaption AS ASCIIZ, ahkeys AS ANY, _
'    BYVAL cikeys AS DWORD, pclsidDefault AS GUID, pdtobj AS ANY, _
'    psb AS ANY, pStartPage AS ASCIIZ) AS LONG

DECLARE FUNCTION SHOpenPropSheetW LIB "Shell32.dll" _
    ALIAS "SHOpenPropSheetW" (pszCaption AS WSTRINGZ, ahkeys AS ANY, _
    BYVAL cikeys AS DWORD, pclsidDefault AS GUID, pdtobj AS ANY, _
    psb AS ANY, pStartPage AS ASCIIZ) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHOpenPropSheet LIB "Shell32.dll" _
    ALIAS "SHOpenPropSheetW" (pszCaption AS WSTRINGZ, ahkeys AS ANY, _
    BYVAL cikeys AS DWORD, pclsidDefault AS GUID, pdtobj AS ANY, _
    psb AS ANY, pStartPage AS ASCIIZ) AS LONG
'#ELSE
'MACRO SHOpenPropSheet=SHOpenPropSheetA
#ENDIF ' NOT %UNICODE

' structure for lParam of DFM_INFOKECOMMANDEX
TYPE DFMICS
    cbSize     AS DWORD
    fMask      AS DWORD     ' CMIC_MASK_ values for the invoke
    lParam     AS LONG      ' same as lParam of DFM_INFOKECOMMAND
    idCmdFirst AS DWORD
    idDefMax   AS DWORD
    pici       AS DWORD ' CMINVOKECOMMANDINFO PTR ' the whole thing so you can re-invoke on a child
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
    punkSite   AS DWORD ' IUNKNOWN PTR       ' site pointer for context menu handler
#ENDIF
END TYPE

' Note on context menus ranges:
'  Standard Items ' DFM_MERGECONTEXTMENU, context menu extensions, DFM_MERGECONTEXTMENU_TOP
'  Separator
'  View Items   ' context menu extensions can get here
'  Separator
'  (defcm S_FALSE "default" items, if applicable)
'  Separator
'  Folder Items ' context menu extensions can get here
'  Separator
'  Bottom Items ' DFM_MERGECONTEXTMENU_BOTTOM

'                                  uMsg       wParam       lParam
%DFM_MERGECONTEXTMENU        = 1      ' uFlags       LPQCMINFO
%DFM_INVOKECOMMAND           = 2      ' idCmd        pszArgs
%DFM_GETHELPTEXT             = 5      ' idCmd,cchMax pszText -Ansi
%DFM_WM_MEASUREITEM          = 6      ' ---from the message---
%DFM_WM_DRAWITEM             = 7      ' ---from the message---
%DFM_WM_INITMENUPOPUP        = 8      ' ---from the message---
%DFM_VALIDATECMD             = 9      ' idCmd        0
%DFM_MERGECONTEXTMENU_TOP    = 10     ' uFlags       LPQCMINFO
%DFM_GETHELPTEXTW            = 11     ' idCmd,cchMax pszText -Unicode
%DFM_INVOKECOMMANDEX         = 12     ' idCmd        PDFMICS
%DFM_MAPCOMMANDNAME          = 13     ' idCmd *      pszCommandName
%DFM_GETDEFSTATICID          = 14     ' idCmd *      0
%DFM_GETVERBW                = 15     ' idCmd,cchMax pszText -Unicode
%DFM_GETVERBA                = 16     ' idCmd,cchMax pszText -Ansi
%DFM_MERGECONTEXTMENU_BOTTOM = 17     ' uFlags       LPQCMINFO
%DFM_MODIFYQCMFLAGS          = 18     ' uFlags       UINT *puNewFlags;   modify the CFM_XXX values passed to IContextMenu::QueryContextMenu

' Commands from DFM_INVOKECOMMAND when strings are passed in
%DFM_CMD_DELETE          = &HFFFFFFFF???  ' (UINT)-1
%DFM_CMD_MOVE            = &HFFFFFFFE???  '(UINT)-2
%DFM_CMD_COPY            = &HFFFFFFFD???  '(UINT)-3
%DFM_CMD_LINK            = &HFFFFFFFC???  '(UINT)-4
%DFM_CMD_PROPERTIES      = &HFFFFFFFB???  '(UINT)-5
%DFM_CMD_NEWFOLDER       = &HFFFFFFFA???  '(UINT)-6
%DFM_CMD_PASTE           = &HFFFFFFF9???  '(UINT)-7
%DFM_CMD_VIEWLIST        = &HFFFFFFF8???  '(UINT)-8
%DFM_CMD_VIEWDETAILS     = &HFFFFFFF7???  '(UINT)-9
%DFM_CMD_PASTELINK       = &HFFFFFFF6???  '(UINT)-10
%DFM_CMD_PASTESPECIAL    = &HFFFFFFF5???  '(UINT)-11
%DFM_CMD_MODALPROP       = &HFFFFFFF4???  '(UINT)-12
%DFM_CMD_RENAME          = &HFFFFFFF3???  '(UINT)-13


DECLARE FUNCTION LPFNVIEWCALLBACK (psvOuter AS ANY, psf AS ANY, _
    BYVAL hwndMain AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

' SHCreateShellFolderViewEx struct
TYPE CSFV
    cbSize      AS DWORD
    pshf        AS DWORD ' IShellFolder PTR
    psvOuter    AS DWORD ' IShellView PTR
    pidl        AS ITEMIDLIST PTR ' PCIDLIST_ABSOLUTE
    lEvents     AS LONG
    pfnCallback AS DWORD  ' LPFNVIEWCALLBACK         ' No callback if NULL
    fvm         AS LONG  ' FOLDERVIEWMODE_enum
END TYPE


' Tell the FolderView to rearrange.  The lParam will be passed to
' IShellFolder::CompareIDs
%SFVM_REARRANGE          = &H00000001

MACRO ShellFolderView_ReArrange(hwnd,lparam)=SHShellFolderView_Message(hwnd, %SFVM_REARRANGE, lparam)

' Add an OBJECT into the view
%SFVM_ADDOBJECT         = &H00000003

MACRO ShellFolderView_AddObject(hwnd,pidl)=SHShellFolderView_Message(hwnd, %SFVM_ADDOBJECT, pidl)

' Remove an OBJECT into the view
%SFVM_REMOVEOBJECT         = &H00000006

MACRO ShellFolderView_RemoveObject(hwnd,pidl)=SHShellFolderView_Message(hwnd, %SFVM_REMOVEOBJECT, pidl)

' updates an object by passing in pointer to two PIDLS, the first
' is the old pidl, the second one is the one with update information.
'
' _ppidl[1] must be a *copy* of a pidl, as control over the lifetime
' of the pidl belongs to the view after successful completion of
' this call.  (Unsuccessful completion (a -1 return) implies failure
' and the caller must free the memory.)  Win95 waits a while before
' freeing the pidl, IE4 frees the pidl immediately.
' IShellFolderView::UpdateObject does not suffer from this problem.
'
%SFVM_UPDATEOBJECT         = &H00000007

MACRO ShellFolderView_UpdateObject(hwnd,ppidl)=SHShellFolderView_Message(hwnd, %SFVM_UPDATEOBJECT, ppidl)


' Returns an array of the selected IDS to the caller.
'     lparam is a pointer to receive the idlists into
'     return value is the count of items in the array.
%SFVM_GETSELECTEDOBJECTS = &H00000009

MACRO ShellFolderView_GetSelectedObjects(hwnd,ppidl)=SHShellFolderView_Message(hwnd, %SFVM_GETSELECTEDOBJECTS, ppidl)

TYPE SFV_SETITEMPOS
    pidl AS ITEMIDLIST PTR ' PCUITEMID_CHILD
    pt   AS POINT
END TYPE

' Sets the position of an item in the viewer
'     lparam is a pointer to a SVF_SETITEMPOS
'     return value is unused
%SFVM_SETITEMPOS         = &H0000000e

'#define ShellFolderView_SetItemPos(_hwnd, _pidl, _x, _y)  _
'{       SFV_SETITEMPOS _sip = {_pidl, {_x, _y}};  _
'        SHShellFolderView_Message(_hwnd, SFVM_SETITEMPOS, (LPARAM)(LPSFV_SETITEMPOS)&_sip);}

'  Notifies a ShellView when one of its objects get put on the clipboard
'  as a result of a menu command.
'
'
'     lparam is the dwEffect (DROPEFFECT_MOVE, DROPEFFECT_COPY)
'     return value is void.
%SFVM_SETCLIPBOARD       = &H00000010

MACRO ShellFolderView_SetClipboard(hwnd,dwEffect)
    SHShellFolderView_Message hwnd, %SFVM_SETCLIPBOARD, dwEffect
END MACRO

%SFVM_SETPOINTS           = &H00000017

MACRO ShellFolderView_SetPoints(hwnd, pdtobj)
    SHShellFolderView_Message hwnd, %SFVM_SETPOINTS, pdtobj)
END MACRO

DECLARE FUNCTION SHFind_InitMenuPopup LIB "Shell32.dll" _
    ALIAS "SHFind_InitMenuPopup" (BYVAL hmenu AS DWORD, _
    BYVAL hwndOwner AS DWORD, BYVAL idCmdFirst AS DWORD, _
    BYVAL idCmdLast AS DWORD) AS DWORD

DECLARE FUNCTION SHCreateShellFolderViewEx LIB "Shell32.dll" _
    ALIAS "SHCreateShellFolderViewEx" (pcsfv AS CSFV, ppsv AS ANY) AS LONG

' Legacy PROPIDs for Internet Shortcuts (FMTID_Intshcut) to be used with
' IPropertySetStorage/IPropertyStorage.
'
' The known property ids and their variant types are:
'      PID_IS_URL          [VT_LPWSTR]   URL
'      PID_IS_NAME         [VT_LPWSTR]   Name of the internet shortcut
'      PID_IS_WORKINGDIR   [VT_LPWSTR]   Working directory for the shortcut
'      PID_IS_HOTKEY       [VT_UI2]      Hotkey for the shortcut
'      PID_IS_SHOWCMD      [VT_I4]       Show command for shortcut
'      PID_IS_ICONINDEX    [VT_I4]       Index into file that has icon
'      PID_IS_ICONFILE     [VT_LPWSTR]   File that has the icon
'      PID_IS_WHATSNEW     [VT_LPWSTR]   What's New text
'      PID_IS_AUTHOR       [VT_LPWSTR]   Author
'      PID_IS_DESCRIPTION  [VT_LPWSTR]   Description text of site
'      PID_IS_COMMENT      [VT_LPWSTR]   User annotated comment

%PID_IS_URL          =  2
%PID_IS_NAME         =  4
%PID_IS_WORKINGDIR   =  5
%PID_IS_HOTKEY       =  6
%PID_IS_SHOWCMD      =  7
%PID_IS_ICONINDEX    =  8
%PID_IS_ICONFILE     =  9
%PID_IS_WHATSNEW     =  10
%PID_IS_AUTHOR       =  11
%PID_IS_DESCRIPTION  =  12
%PID_IS_COMMENT      =  13

' PROPIDs for Internet Sites (FMTID_InternetSite) to be used with
' IPropertySetStorage/IPropertyStorage
'
' The known property ids and their variant types are:
'      PID_INTSITE_WHATSNEW     [VT_LPWSTR]   What's New text
'      PID_INTSITE_AUTHOR       [VT_LPWSTR]   Author
'      PID_INTSITE_LASTVISIT    [VT_FILETIME] Time site was last visited
'      PID_INTSITE_LASTMOD      [VT_FILETIME] Time site was last modified
'      PID_INTSITE_VISITCOUNT   [VT_UI4]      Number of times user has visited
'      PID_INTSITE_DESCRIPTION  [VT_LPWSTR]   Description text of site
'      PID_INTSITE_COMMENT      [VT_LPWSTR]   User annotated comment
'      PID_INTSITE_RECURSE      [VT_UI4]      Levels to recurse (0-3)
'      PID_INTSITE_WATCH        [VT_UI4]      PIDISM_ flags
'      PID_INTSITE_SUBSCRIPTION [VT_UI8]      Subscription cookie
'      PID_INTSITE_URL          [VT_LPWSTR]   URL
'      PID_INTSITE_TITLE        [VT_LPWSTR]   Title
'      PID_INTSITE_CODEPAGE     [VT_UI4]      Codepage of the document
'      PID_INTSITE_TRACKING     [VT_UI4]      Tracking
'      PID_INTSITE_ICONINDEX    [VT_I4]       Retrieve the index to the icon
'      PID_INTSITE_ICONFILE     [VT_LPWSTR]   Retrieve the file containing the icon index.
'      PID_INTSITE_RAWURL       [VT_LPWSTR]   The raw, un-encoded, unicode url.

%PID_INTSITE_WHATSNEW     =  2
%PID_INTSITE_AUTHOR       =  3
%PID_INTSITE_LASTVISIT    =  4
%PID_INTSITE_LASTMOD      =  5
%PID_INTSITE_VISITCOUNT   =  6
%PID_INTSITE_DESCRIPTION  =  7
%PID_INTSITE_COMMENT      =  8
%PID_INTSITE_FLAGS        =  9
%PID_INTSITE_CONTENTLEN   =  10
%PID_INTSITE_CONTENTCODE  =  11
%PID_INTSITE_RECURSE      =  12
%PID_INTSITE_WATCH        =  13
%PID_INTSITE_SUBSCRIPTION =  14
%PID_INTSITE_URL          =  15
%PID_INTSITE_TITLE        =  16
%PID_INTSITE_CODEPAGE     =  18
%PID_INTSITE_TRACKING     =  19
%PID_INTSITE_ICONINDEX    =  20
%PID_INTSITE_ICONFILE     =  21

' Flags for PID_IS_FLAGS
%PIDISF_RECENTLYCHANGED  = &H00000001
%PIDISF_CACHEDSTICKY     = &H00000002
%PIDISF_CACHEIMAGES      = &H00000010
%PIDISF_FOLLOWALLLINKS   = &H00000020


' Values for PID_INTSITE_WATCH
%PIDISM_GLOBAL          =  0       ' Monitor based on global setting
%PIDISM_WATCH           =  1       ' User says watch
%PIDISM_DONTWATCH       =  2       ' User says don't watch


''''''''''''''''''''''''''''''''''
'
' The shell keeps track of some per-user state to handle display
' options that is of major interest to ISVs.
' The key one requested right now is "DoubleClickInWebView".

TYPE SHELLSTATEA
    fShowAllObjects       AS BIT * 1 IN DWORD
    fShowExtensions       AS BIT * 1
    fNoConfirmRecycle     AS BIT * 1

    fShowSysFiles         AS BIT * 1
    fShowCompColor        AS BIT * 1
    fDoubleClickInWebView AS BIT * 1
    fDesktopHTML          AS BIT * 1
    fWin95Classic         AS BIT * 1
    fDontPrettyPath       AS BIT * 1
    fShowAttribCol        AS BIT * 1  ' No longer used, dead bit
    fMapNetDrvBtn         AS BIT * 1
    fShowInfoTip          AS BIT * 1
    fHideIcons            AS BIT * 1
    fWebView              AS BIT * 1
    fFilter               AS BIT * 1
    fShowSuperHidden      AS BIT * 1
    fNoNetCrawling        AS BIT * 1

    dwWin95Unused AS DWORD  ' Win95 only - no longer supported pszHiddenFileExts
    uWin95Unused  AS DWORD  ' Win95 only - no longer supported cbHiddenFileExts

    ' Note: Not a typo!  This is a persisted structure so we cannot use LPARAM
    lParamSort       AS LONG
    iSortDirection   AS LONG

    version          AS DWORD

    ' new for win2k. need notUsed var to calc the right size of ie4 struct
    ' FIELD_OFFSET does not work on bit fields
    uNotUsed         AS DWORD  ' feel free to rename and use
    fSepProcess      AS BIT * 1 IN DWORD

    ' new for Whistler.
    fStartPanelOn    AS BIT * 1   'Indicates if the Whistler StartPanel mode is ON or OFF.
    fShowStartPage   AS BIT * 1   'Indicates if the Whistler StartPage on desktop is ON or OFF.

    ' new for Longhorn
    fAutoCheckSelect AS BIT * 1
    fIconsOnly       AS BIT * 1
    fShowTypeOverlay AS BIT * 1

    fSpareFlags AS BIT * 11

END TYPE

TYPE SHELLSTATEW
    fShowAllObjects       AS BIT * 1 IN DWORD
    fShowExtensions       AS BIT * 1
    fNoConfirmRecycle     AS BIT * 1

    fShowSysFiles         AS BIT * 1
    fShowCompColor        AS BIT * 1
    fDoubleClickInWebView AS BIT * 1
    fDesktopHTML          AS BIT * 1
    fWin95Classic         AS BIT * 1
    fDontPrettyPath       AS BIT * 1
    fShowAttribCol        AS BIT * 1  ' No longer used, dead bit
    fMapNetDrvBtn         AS BIT * 1
    fShowInfoTip          AS BIT * 1
    fHideIcons            AS BIT * 1
    fWebView              AS BIT * 1
    fFilter               AS BIT * 1
    fShowSuperHidden      AS BIT * 1
    fNoNetCrawling        AS BIT * 1

    dwWin95Unused AS DWORD  ' Win95 only - no longer supported pszHiddenFileExts
    uWin95Unused  AS DWORD  ' Win95 only - no longer supported cbHiddenFileExts

    ' Note: Not a typo!  This is a persisted structure so we cannot use LPARAM
    lParamSort       AS LONG
    iSortDirection   AS LONG

    version          AS DWORD

    ' new for win2k. need notUsed var to calc the right size of ie4 struct
    ' FIELD_OFFSET does not work on bit fields
    uNotUsed         AS DWORD  ' feel free to rename and use
    fSepProcess      AS BIT * 1 IN DWORD

    ' new for Whistler.
    fStartPanelOn    AS BIT * 1   'Indicates if the Whistler StartPanel mode is ON or OFF.
    fShowStartPage   AS BIT * 1   'Indicates if the Whistler StartPage on desktop is ON or OFF.

    ' new for Longhorn
    fAutoCheckSelect AS BIT * 1
    fIconsOnly       AS BIT * 1
    fShowTypeOverlay AS BIT * 1

    fSpareFlags AS BIT * 11

END TYPE

%SHELLSTATEVERSION_IE4   = 9
%SHELLSTATEVERSION_WIN2K = 10

#IF %DEF(%UNICODE)
TYPE SHELLSTATE
    SHELLSTATEW
END TYPE
#ELSE
TYPE SHELLSTATE
    SHELLSTATEA
END TYPE
#ENDIF

'#define SHELLSTATE_SIZE_WIN95 FIELD_OFFSET(SHELLSTATE,lParamSort)
'#define SHELLSTATE_SIZE_NT4   FIELD_OFFSET(SHELLSTATE,version)
'#define SHELLSTATE_SIZE_IE4   FIELD_OFFSET(SHELLSTATE,uNotUsed)
'#define SHELLSTATE_SIZE_WIN2K sizeof(SHELLSTATE)

DECLARE SUB SHGetSetSettings LIB "Shell32.dll" ALIAS "SHGetSetSettings" _
    (lpss AS SHELLSTATE, BYVAL dwMask AS DWORD, BYVAL bSet AS LONG)

'
'  SysFiles are these windows special files:
'      "dll sys vxd 386 drv"
'
'  hidden files are files with the FILE_ATTRIBUTE_HIDDEN attribute
'
'  system files are files with the FILE_ATTRIBUTE_SYSTEM attribute
'
'      fShowAllObjects fShowSysFiles   Result
'      --------------- -------------   ------
'      0               0               hide hidden + SysFiles + system files
'      0               1               hide hidden files.
'      1               0               show all files.
'      1               1               show all files.
'
TYPE SHELLFLAGSTATE
    fShowAllObjects       AS BIT * 1 IN DWORD
    fShowExtensions       AS BIT * 1
    fNoConfirmRecycle     AS BIT * 1
    fShowSysFiles         AS BIT * 1
    fShowCompColor        AS BIT * 1
    fDoubleClickInWebView AS BIT * 1
    fDesktopHTML          AS BIT * 1
    fWin95Classic         AS BIT * 1
    fDontPrettyPath       AS BIT * 1
    fShowAttribCol        AS BIT * 1
    fMapNetDrvBtn         AS BIT * 1
    fShowInfoTip          AS BIT * 1
    fHideIcons            AS BIT * 1
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
    fAutoCheckSelect      AS BIT * 1
    fIconsOnly            AS BIT * 1
    fRestFlags            AS BIT * 1
#ELSE
    fRestFlags            AS BIT * 3
#ENDIF
END TYPE

%SSF_SHOWALLOBJECTS          = &H00000001
%SSF_SHOWEXTENSIONS          = &H00000002
%SSF_HIDDENFILEEXTS          = &H00000004
%SSF_SERVERADMINUI           = &H00000004
%SSF_SHOWCOMPCOLOR           = &H00000008
%SSF_SORTCOLUMNS             = &H00000010
%SSF_SHOWSYSFILES            = &H00000020
%SSF_DOUBLECLICKINWEBVIEW    = &H00000080
%SSF_SHOWATTRIBCOL           = &H00000100
%SSF_DESKTOPHTML             = &H00000200
%SSF_WIN95CLASSIC            = &H00000400
%SSF_DONTPRETTYPATH          = &H00000800
%SSF_SHOWINFOTIP             = &H00002000
%SSF_MAPNETDRVBUTTON         = &H00001000
%SSF_NOCONFIRMRECYCLE        = &H00008000
%SSF_HIDEICONS               = &H00004000
%SSF_FILTER                  = &H00010000
%SSF_WEBVIEW                 = &H00020000
%SSF_SHOWSUPERHIDDEN         = &H00040000
%SSF_SEPPROCESS              = &H00080000
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
%SSF_NONETCRAWLING           = &H00100000
%SSF_STARTPANELON            = &H00200000
%SSF_SHOWSTARTPAGE           = &H00400000
#ENDIF  ' %NTDDI_WINXP
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%SSF_AUTOCHECKSELECT         = &H00800000

%SSF_ICONSONLY               = &H01000000
%SSF_SHOWTYPEOVERLAY         = &H02000000

#ENDIF  ' %NTDDI_VISTA

'
' Specify the bits you are interested in in dwMask and they will be
' filled out in the lpss structure.
'
' When these settings change, a WM_SETTINGCHANGE message is sent
' with the string lParam value of "ShellState".
'
DECLARE SUB SHGetSettings LIB "Shell32.dll" ALIAS "SHGetSettings" _
    (psfs AS SHELLFLAGSTATE, BYVAL dwMask AS DWORD)

'
' Given a pidl, you can get an interface pointer (as specified by riid) of the pidl's parent folder (in ppv)
' If ppidlLast is non-NULL, you can also get the pidl of the last item.
'
DECLARE FUNCTION SHBindToParent LIB "Shell32.dll" ALIAS "SHBindToParent" _
    (BYVAL pidl AS ITEMIDLIST PTR, riid AS GUID, ppv AS ANY, _
    ppidlLast AS ANY) AS LONG


#IF (%NTDDI_VERSION >= %NTDDI_VISTA)

' Same as SHBindToParent, except you also specify which root to use.
DECLARE FUNCTION SHBindToFolderIDListParent LIB "Shell32.dll" _
    ALIAS "SHBindToFolderIDListParent" (psfRoot AS ANY, _
    pidl AS ITEMIDLIST, riid AS GUID, ppv AS ANY, _
    ppidlLast AS ANY) AS LONG

' same as SHBindToFolderIDListParent but with a IBindCtx *pbc;
DECLARE FUNCTION SHBindToFolderIDListParentEx LIB "Shell32.dll" _
    ALIAS "SHBindToFolderIDListParentEx" (psfRoot AS ANY, _
    pidl AS ITEMIDLIST, ppbc AS ANY, riid AS GUID, _
    ppv AS ANY, ppidlLast AS ANY) AS LONG

' helper function that gets the desktop object, then calls BindToObject on that
DECLARE FUNCTION SHBindToObject LIB "Shell32.dll" ALIAS "SHBindToObject" _
    (psf AS ANY, pidl AS ITEMIDLIST, pbc AS ANY, riid AS GUID, _
    ppv AS ANY) AS LONG

#ENDIF ' %NTDDI_VISTA

'
'  given a string it will call psfDesktop->ParseDisplayName() to try and create a pidl
'  if no pbc specified, it uses the preferred options for parsing.
'  this includes mapping file system paths to their appropriate aliased location (RegisterObjectParam(STR_PARSE_TRANSLATE_ALIASES))
'  psfgaoOut is optional for SFGAO attributes
'
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)

DECLARE FUNCTION SHParseDisplayName LIB "Shell32.dll" _
    ALIAS "SHParseDisplayName" _
    (pszName      AS WSTRINGZ, _
    pbc           AS ANY, _
    ppidl         AS ANY, _
    BYVAL sfgoaIn AS DWORD, _   ' SFGAOF
    psfgaoOut     AS DWORD _    ' SFGAOF
    ) AS LONG

#ENDIF ' %NTDDI_WINXP

'
' This API will make its best effort to prepare the path for the caller.  This includes:
' 1. Prompting for the ejectable media to be re-inserted. (Floppy, CD-ROM, ZIP drive, etc.)
' 2. Prompting for the media to be formatted. (Floppy, hard drive, etc.)
' 3. Remount mapped drives if the connection was lost. (\\unc\share mapped to N: becomes disconnected)
' 4. If the path doesn't exist, create it.  (SHPPFW_DIRCREATE and SHPPFW_ASKDIRCREATE)
' 5. Display an error if the media is read only. (SHPPFW_NOWRITECHECK not set)
'
' PARAMETERS:
'      hwnd: Parernt window for UI.  NULL means don't display UI. OPTIONAL
'      punkEnableModless: Parent that will be set to modal during UI using IOleInPlaceActiveObject::EnableModeless(). OPTIONAL
'      pszPath: Path to verify is valid for writting.  This can be a UNC or file drive path.  The path
'               should only contain directories.  Pass SHPPFW_IGNOREFILENAME if the last path segment
'               is always filename to ignore.
'      dwFlags: SHPPFW_* Flags to modify behavior

%SHPPFW_NONE           = &H00000000
%SHPPFW_DIRCREATE      = &H00000001         ' Create the directory if it doesn't exist without asking the user.
%SHPPFW_DEFAULT        = %SHPPFW_DIRCREATE  ' May change
%SHPPFW_ASKDIRCREATE   = &H00000002         ' Create the directory if it doesn't exist after asking the user.
%SHPPFW_IGNOREFILENAME = &H00000004         ' Ignore the last item in pszPath because it's a file.  Example: pszPath="C:\DirA\DirB", only use "C:\DirA".
%SHPPFW_NOWRITECHECK   = &H00000008         ' Caller only needs to read from the drive, so don't check if it's READ ONLY.
#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
%SHPPFW_MEDIACHECKONLY = &H00000010         ' do the retrys on the media (or net path), return errors if the file can't be found
#ENDIF ' %NTDDI_WINXP

DECLARE FUNCTION SHPathPrepareForWriteA LIB "Shell32.dll" _
    ALIAS "SHPathPrepareForWriteA" (BYVAL hwnd AS DWORD, _
    punkEnableModless AS ANY, pszPath AS ASCIIZ, BYVAL dwFlags AS DWORD) _
    AS LONG

DECLARE FUNCTION SHPathPrepareForWriteW LIB "Shell32.dll" _
    ALIAS "SHPathPrepareForWriteW" (BYVAL hwnd AS DWORD, _
    punkEnableModless AS ANY, pszPath AS WSTRINGZ, BYVAL dwFlags AS DWORD) _
    AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHPathPrepareForWrite LIB "Shell32.dll" _
    ALIAS "SHPathPrepareForWriteW" (BYVAL hwnd AS DWORD, _
    punkEnableModless AS ANY, pszPath AS WSTRINGZ, BYVAL dwFlags AS DWORD) _
    AS LONG
#ELSE
DECLARE FUNCTION SHPathPrepareForWrite LIB "Shell32.dll" _
    ALIAS "SHPathPrepareForWriteA" (BYVAL hwnd AS DWORD, _
    punkEnableModless AS ANY, pszPath AS ASCIIZ, BYVAL dwFlags AS DWORD) _
    AS LONG
#ENDIF ' NOT %UNICODE


'--------------------------------------------------------------------------
'
' Interface used for exposing the INI file methods on a shortcut file
'
'
'--------------------------------------------------------------------------
'#undef  INTERFACE
'#define INTERFACE  INamedPropertyBag
'
'DECLARE_INTERFACE_IID_(INamedPropertyBag, IUnknown, "FB700430-952C-11d1-946F-000000000000")
'{
'    ' *** IUnknown methods ***
'    STDMETHOD(QueryInterface)   (THIS_ REFIID riid, void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef)    (THIS) PURE;
'    STDMETHOD_(ULONG,Release)   (THIS) PURE;
'    ' *** INamedPropertyBag methods ***
'    STDMETHOD(ReadPropertyNPB) (THIS_  ' [in]  LPCWSTR pszBagname,
'                            ' [in]  LPCWSTR pszPropName,
'                            ' [out][in]  PROPVARIANT *pVar) PURE;
'
'    STDMETHOD(WritePropertyNPB)(THIS_ ' [in]  LPCWSTR pszBagname,
'                           ' [in]  LPCWSTR pszPropName,
'                           ' [in]  PROPVARIANT  *pVar) PURE;
'
'    STDMETHOD(RemovePropertyNPB)(THIS_ ' [in]  LPCWSTR pszBagname,
'                          ' [in]  LPCWSTR pszPropName) PURE;
'};

#IF %DEF(%urlmon_h)
'    NOTE: urlmon.h must be included before shlobj.h to access this function.
'
'    SoftwareUpdateMessageBox
'
'    Provides a standard message box for the alerting the user that a software
'    update is available or installed. No UI will be displayed if there is no
'    update available or if the available update version is less than or equal
'    to the Advertised update version.
'
'    hWnd                - [in] Handle of owner window
'    szDistUnit          - [in] Unique identifier string for a code distribution unit. For
'                               ActiveX controls and Active Setup installed components, this
'                               is typically a GUID string.
'    dwFlags             - [in] Must be 0.
'    psdi                - [in,out] Pointer to SOFTDISTINFO ( see URLMon.h ). May be NULL.
'                                cbSize should be initialized
'                                by the caller to sizeof(SOFTDISTINFO), dwReserved should be set to 0.
'
'    RETURNS:
'
'    IDNO     - The user chose cancel. If *pbRemind is FALSE, the caller should save the
'               update version from the SOFTDISTINFO and pass it in as the Advertised
'               version in future calls.
'
'    IDYES    - The user has selected Update Now/About Update. The caller should navigate to
'               the SOFTDISTINFO's pszHREF to initiate the install or learn about it.
'               The caller should save the update version from the SOFTDISTINFO and pass
'               it in as the Advertised version in future calls.
'
'    IDIGNORE - There is no pending software update. Note: There is
'               no Ignore button in the standard UI. This occurs if the available
'               version is less than the installed version or is not present or if the
'               Advertised version is greater than or equal to the update version.
'
'    IDABORT  - An error occured. Call GetSoftwareUpdateInfo() for a more specific HRESULT.
'               Note: There is no Abort button in the standard UI.


DECLARE FUNCTION SoftwareUpdateMessageBox LIB "ShDocVW.dll" _
    ALIAS "SoftwareUpdateMessageBox" (BYVAL hwnd AS DWORD, _
    pszDistUnit AS WSTRINGZ, BYVAL dwFlags AS DWORD, _
    psdi AS SOFTDISTINFO) AS DWORD

#ENDIF ' if %urlmon_h


'  SHPropStgCreate()
'  Wrap of IPropertySetStorage::Open/Create
'
'  This function ensures proper handling of code page retrieval/assignment
'  for the requested property set operation.
'
'  psstg,          '  Address of IPropertySetStorage vtable
'  fmtid,          '  property set ID
'  pclsid,         '  class ID associated with the set. This can be NULL
'  grfFlags,       '  PROPSETFLAG_xxx.  All sets containing ansi bytes should be created with
                    '  PROPSETFLAG_ANSI, otherwise PROPSETFLAG_DEFAULT.
'  grfMode,        '  STGM_ flags.  Must contain STGM_DIRECT|STGM_EXCLUSIVE.
'  dwDisposition,  '  OPEN_EXISTING. OPEN_ALWAYS, CREATE_NEW, or CREATE_ALWAYS
'  IPropertyStorage** ppstg,  ' Address to receive requested vtable
'  puCodePage      '  Optional address to receive the code page ID for the set.
'
DECLARE FUNCTION SHPropStgCreate LIB "Shell32.dll" _
    ALIAS "SHPropStgCreate" (psstg AS ANY, fmtid AS GUID, _ 'REFFMTID
    pclsid AS GUID, BYVAL grfFlags AS DWORD, BYVAL grfMode AS DWORD, _
    BYVAL dwDisposition AS DWORD, ppstg AS ANY, puCodePage AS DWORD) AS LONG


'  SHPropStgReadMultiple()
'  IPropertyStorage::ReadMultiple wrap
'
'  The wrap ensures ANSI/UNICODE translations are handled properly for
'  legacy property sets.
'
'  pps,       ' address of IPropertyStorage vtable.
'  uCodePage, 'Code page value retrieved from SHCreatePropertySet
'  cpspec,    'Count of properties being read
'  rgpspec,   'Array of the properties to be read
'  rgvar      'Array of PROPVARIANTs containing the property values on return
'
DECLARE FUNCTION SHPropStgReadMultiple LIB "Shell32.dll" _
    ALIAS "SHPropStgReadMultiple" (pps AS ANY, BYVAL ducodepage AS DWORD, _
    BYVAL cpspec AS DWORD, rgpspec AS ANY, rgvar AS ANY) AS LONG


'  SHPropStgWriteMultiple()
'  IPropertyStorage::WriteMultiple wrap
'
'  The wrap ensures ANSI/UNICODE translations are handled properly for
'  legacy property sets.
'
'  pps,       ' address of IPropertyStorage vtable.
'  uCodePage, ' code page retrieved from SHCreatePropertySet.
'  cpspec,    ' The number of properties being set
'  rgpspec,   ' Property specifiers
'  rgvar,     ' Array of PROPVARIANT values
'  propidNameFirst ' Minimum value for property identifiers. This value should be >= PID_FIRST_USABLE
'
DECLARE FUNCTION SHPropStgWriteMultiple LIB "Shell32.dll" _
    ALIAS "SHPropStgWriteMultiple" (pps AS ANY, puCodePage AS DWORD, _
    BYVAL cpspec AS DWORD, rgpspec AS ANY, rgvar AS ANY, _
    BYVAL propidNameFirst AS DWORD _ ' PROPID
    ) AS LONG

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)

' [not exported. msdn hints it doesn't exist.]
'DECLARE FUNCTION SHCreateFileExtractIconA LIB "Shell32.dll" _
'    ALIAS "SHCreateFileExtractIconA" (pszFile AS ASCIIZ, _
'    BYVAL dwFileAttributes AS DWORD, riid AS GUID, ppv AS ANY) AS LONG

DECLARE FUNCTION SHCreateFileExtractIconW LIB "Shell32.dll" _
    ALIAS "SHCreateFileExtractIconW" (pszFile AS WSTRING, _
    BYVAL dwFileAttributes AS DWORD, riid AS GUID, ppv AS ANY) AS LONG

#IF %DEF(%UNICODE)
DECLARE FUNCTION SHCreateFileExtractIcon LIB "Shell32.dll" _
    ALIAS "SHCreateFileExtractIconW" (pszFile AS WSTRING, _
    BYVAL dwFileAttributes AS DWORD, riid AS GUID, ppv AS ANY) AS LONG
'#ELSE
'MACRO SHCreateFileExtractIcon=SHCreateFileExtractIconA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SHLimitInputEdit LIB "Shell32.dll" _
    ALIAS "SHLimitInputEdit" (BYVAL hwndEdit AS DWORD, psf AS ANY) AS LONG

DECLARE FUNCTION SHGetAttributesFromDataObject LIB "Shell32.dll" _
    ALIAS "SHGetAttributesFromDataObject" (pdo AS ANY, _
    BYVAL dwAttributeMask AS DWORD, pdwAttributes AS DWORD, _
    pcItems AS DWORD) AS LONG

#ENDIF  ' %NTDDI_WINXP

#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)

'
' The SHMultiFileProperties API displays a property sheet for a
' set of files specified in an IDList Array.
'
' Parameters:
'      pdtobj  - Data object containing list of files.  The data
'                object must provide the "Shell IDList Array"
'                clipboard format.  The parent folder's implementation of
'                IShellFolder::GetDisplayNameOf must return a fully-qualified
'                filesystem path for each item in response to the
'                SHGDN_FORPARSING flag.
'
'      dwFlags - Reserved for future use.  Should be set to 0.
'
' Returns:
'      S_OK
'
DECLARE FUNCTION SHMultiFileProperties LIB "Shell32.dll" _
    ALIAS "SHMultiFileProperties" (pdtobj AS ANY, BYVAL dwFlags AS DWORD) _
    AS LONG

#ENDIF  ' %NTDDI_WIN2K

' A useful function in Defview for mapping idlist into index into system
' image list.  Optionally it can also look up the index of the selected
' icon.
DECLARE FUNCTION SHMapPIDLToSystemImageListIndex LIB "Shell32.dll" _
    ALIAS "SHMapPIDLToSystemImageListIndex" (pshf AS ANY, _
    pidl AS ITEMIDLIST, _  ' UITEMID_CHILD
    piIndexSel AS LONG) AS LONG

DECLARE FUNCTION SHCLSIDFromString LIB "Shell32.dll" _
    ALIAS "SHCLSIDFromString" (psz AS WSTRINGZ, pclsid AS GUID) AS LONG

' deprecated: use CreateClassMoniker(CLSID_YourOwnClsid, ...)
DECLARE FUNCTION SHCreateQueryCancelAutoPlayMoniker LIB "Shell32.dll" _
    ALIAS "SHCreateQueryCancelAutoPlayMoniker" (ppmoniker AS ANY) AS LONG

' [must be loaded dynamically]
DECLARE SUB PerUserInit ()

DECLARE FUNCTION SHRunControlPanel LIB "Shell32.dll" _
    ALIAS "SHRunControlPanel" _
    (lpcszCmdLine AS WSTRINGZ, BYVAL hwndMsgParent AS DWORD) AS LONG

DECLARE FUNCTION PickIconDlg LIB "Shell32.dll" ALIAS "PickIconDlg" _
    (BYVAL hwnd AS DWORD, pszIconPath AS WSTRINGZ, _
    BYVAL cchIconPath AS DWORD, piIconIndex AS LONG) AS LONG

TYPE AASHELLMENUFILENAME QWORD FILL
    cbTotal         AS INTEGER
    rgbReserved(11) AS BYTE
    szFileName      AS WSTRINGZ * 1    ' variable length string
END TYPE

TYPE AASHELLMENUITEM QWORD FILL
    lpReserved1 AS DWORD
    iReserved   AS LONG
    uiReserved  AS DWORD
    lpName      AS AASHELLMENUFILENAME PTR ' name of file
    psz         AS WSTRINGZ * 1      ' text to use if no file
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
' returns an IStream or IStorage via riid/ppv
DECLARE FUNCTION StgMakeUniqueName LIB "Shell32.dll" _
    ALIAS "StgMakeUniqueName" (pstgParent AS ANY, _ ' IStorage PTR
    pszFileSpec AS WSTRINGZ, BYVAL grfMode AS DWORD, riid AS GUID, _
    ppv AS ANY) AS LONG
#ENDIF ' NTDDI_WIN7

#IF (%WIN32_IE >= %WIN32_IE_IE70)
MACRO IESHORTCUTFLAGS_enum=LONG
ENUM IESHORTCUTFLAGS BITS SINGULAR
    IESHORTCUT_NEWBROWSER    = 1
    IESHORTCUT_OPENNEWTAB
    IESHORTCUT_FORCENAVIGATE
    IESHORTCUT_BACKGROUNDTAB
END ENUM
#ENDIF ' %WIN32_IE_IE70

#IF (%WIN32_IE >= %WIN32_IE_XP)

DECLARE FUNCTION ImportPrivacySettings LIB "ShDocVW.dll" _
    ALIAS "ImportPrivacySettings" (pszFilename AS WSTRINGZ, _
    pfParsePrivacyPreferences AS LONG, pfParsePerSiteRules AS LONG) AS LONG


DECLARE FUNCTION DoPrivacyDlg LIB "ShDocVW.dll" ALIAS "DoPrivacyDlg" _
    (BYVAL hwndOwner AS DWORD, pszUrl AS WSTRINGZ, pPrivacyEnum AS ANY, _
    BYVAL fReportAllSites AS LONG) AS LONG

#ENDIF  ' %WIN32_IE_XP
