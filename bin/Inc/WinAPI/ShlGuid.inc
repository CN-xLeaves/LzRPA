'------------------------------------------------------------------------------
'
'  ShlGuid.inc
'
'  Copyright (c) 2009-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from ShlGuid.h dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE "SdkDdkVer.inc"

$CLSID_NetworkDomain      = GUID$("{46e06680-4bf0-11d1-83ee-00a0c90dc849}")
$CLSID_NetworkServer      = GUID$("{c0542a90-4bf0-11d1-83ee-00a0c90dc849}")
$CLSID_NetworkShare       = GUID$("{54a754c0-4bf1-11d1-83ee-00a0c90dc849}")
$CLSID_MyComputer         = GUID$("{20D04FE0-3AEA-1069-A2D8-08002B30309D}")
$CLSID_Internet           = GUID$("{871C5380-42A0-1069-A2EA-08002B30309D}")
$CLSID_RecycleBin         = GUID$("{645FF040-5081-101B-9F08-00AA002F954E}")
$CLSID_ControlPanel       = GUID$("{21EC2020-3AEA-1069-A2DD-08002B30309D}")
$CLSID_Printers           = GUID$("{2227A280-3AEA-1069-A2DE-08002B30309D}")
$CLSID_MyDocuments        = GUID$("{450D8FBA-AD25-11D0-98A8-0800361B1103}")
'$CLSID_PictureVideoLibrary= GUID$("{00044b4e-11e6-4bef-aec2-ba157d80f660}")
'$CLSID_MusicLibrary       = GUID$("{00875566-addc-4883-a2bf-62bbd230df07}")
'$CLSID_DocumentLibrary    = GUID$("{00f4a6ac-e2e7-4652-b7a7-ecbd232f7818}")

' string version of above CLSIDs
' useful for doing psfDesktop->ParseDisplayName( L"::" L STR_MYDOCS_CLSID, ...);

$$STR_MYDOCS_CLSID = "{450D8FBA-AD25-11D0-98A8-0800361B1103}"$$

#IF (%WIN32_IE >= &H0400)
$CATID_BrowsableShellExt  = GUID$("{00021490-0000-C000-0000-000000000046}")
$CATID_BrowseInPlace      = GUID$("{00021491-0000-C000-0000-000000000046}")
$CATID_DeskBand           = GUID$("{00021492-0000-C000-0000-000000000046}")
$CATID_InfoBand           = GUID$("{00021493-0000-C000-0000-000000000046}")
$CATID_CommBand           = GUID$("{00021494-0000-C000-0000-000000000046}")

#ENDIF

$PSGUID_INTERNETSHORTCUT = "{000214A0-0000-C000-0000-000000000046}"
$FMTID_Intshcut          = GUID$("{000214A0-0000-C000-0000-000000000046}")

$PSGUID_INTERNETSITE     = "{000214A1-0000-C000-0000-000000000046}"
$FMTID_InternetSite      = GUID$("{000214A1-0000-C000-0000-000000000046}")

$CGID_Explorer           = GUID$("{000214D0-0000-C000-0000-000000000046}")
$CGID_ShellDocView       = GUID$("{000214D1-0000-C000-0000-000000000046}")

#IF (%WIN32_IE >= &H0400)
$CGID_ShellServiceObject = GUID$("{000214D2-0000-C000-0000-000000000046}")
$CGID_ExplorerBarDoc     = GUID$("{000214D3-0000-C000-0000-000000000046}")
#ENDIF


$IID_INewShortcutHookA   = GUID$("{000214E1-0000-C000-0000-000000000046}")
$IID_IShellBrowser       = GUID$("{000214E2-0000-C000-0000-000000000046}")
$IID_IShellView          = GUID$("{000214E3-0000-C000-0000-000000000046}")
$IID_IContextMenu        = GUID$("{000214E4-0000-C000-0000-000000000046}")
$IID_IShellIcon          = GUID$("{000214E5-0000-C000-0000-000000000046}")
$IID_IShellFolder        = GUID$("{000214E6-0000-C000-0000-000000000046}")
$IID_IShellExtInit       = GUID$("{000214E8-0000-C000-0000-000000000046}")
$IID_IShellPropSheetExt  = GUID$("{000214E9-0000-C000-0000-000000000046}")
$IID_IPersistFolder      = GUID$("{000214EA-0000-C000-0000-000000000046}")
$IID_IExtractIconA       = GUID$("{000214EB-0000-C000-0000-000000000046}")
$IID_IShellDetails       = GUID$("{000214EC-0000-C000-0000-000000000046}")
$IID_IShellLinkA         = GUID$("{000214EE-0000-C000-0000-000000000046}")
$IID_ICopyHookA          = GUID$("{000214EF-0000-C000-0000-000000000046}")
$IID_IFileViewerA        = GUID$("{000214F0-0000-C000-0000-000000000046}")
$IID_ICommDlgBrowser     = GUID$("{000214F1-0000-C000-0000-000000000046}")
$IID_IEnumIDList         = GUID$("{000214F2-0000-C000-0000-000000000046}")
$IID_IFileViewerSite     = GUID$("{000214F3-0000-C000-0000-000000000046}")
$IID_IContextMenu2       = GUID$("{000214F4-0000-C000-0000-000000000046}")
$IID_IShellExecuteHookA  = GUID$("{000214F5-0000-C000-0000-000000000046}")
$IID_IPropSheetPage      = GUID$("{000214F6-0000-C000-0000-000000000046}")
$IID_INewShortcutHookW   = GUID$("{000214F7-0000-C000-0000-000000000046}")
$IID_IFileViewerW        = GUID$("{000214F8-0000-C000-0000-000000000046}")
$IID_IShellLinkW         = GUID$("{000214F9-0000-C000-0000-000000000046}")
$IID_IExtractIconW       = GUID$("{000214FA-0000-C000-0000-000000000046}")
$IID_IShellExecuteHookW  = GUID$("{000214FB-0000-C000-0000-000000000046}")
$IID_ICopyHookW          = GUID$("{000214FC-0000-C000-0000-000000000046}")
$IID_IRemoteComputer     = GUID$("{000214FE-0000-C000-0000-000000000046}")

$IID_IShellCopyHookA     = $IID_ICopyHookA
$IID_IShellCopyHookW     = $IID_ICopyHookW

' IServiceProvider::QueryService() access the link object that is defering
' to you
$SID_LinkSite            = $IID_IShellLinkW

#IF (%WIN32_IE >= &H0400)
$IID_IQueryInfo          = GUID$("{00021500-0000-C000-0000-000000000046}")
#ENDIF

$IID_IBriefcaseStg       = GUID$("{8BCE1FA1-0921-101B-B1FF-00DD010CCC48}")
$IID_IShellView2         = GUID$("{88E39E80-3578-11CF-AE69-08002B2E1262}")

#IF (%WIN32_IE >= 0400)
$IID_IURLSearchHook      = GUID$("{AC60F6A0-0FD9-11D0-99CB-00C04FD64497}")
$IID_ISearchContext      = GUID$("{09F656A2-41AF-480C-88F7-16CC0D164615}")
$IID_IURLSearchHook2     = GUID$("{5ee44da4-6d32-46e3-86bc-07540dedd0e0}")
$IID_IDefViewID          = GUID$("{985F64F0-D410-4E02-BE22-DA07F2B5C5E1}")
'#define IDefViewID   IUnknown

#IF (%WIN32_IE >= &H0500)
$CLSID_FolderShortcut    = GUID$("{0AFACED1-E828-11D1-9187-B532F1E9575D}")
#ENDIF

$IID_IDockingWindowSite  = GUID$("{2a342fc2-7b26-11d0-8ca9-00a0c92dbfe8}")
$IID_IDockingWindowFrame = GUID$("{47d2657a-7b27-11d0-8ca9-00a0c92dbfe8}")

$IID_IShellIconOverlay   = GUID$("{7D688A70-C613-11D0-999B-00C04FD655E1}")
$IID_IShellIconOverlayIdentifier = GUID$("{0C6C4200-C589-11D0-999A-00C04FD655E1}")

$IID_ICommDlgBrowser2    = GUID$("{10339516-2894-11d2-9039-00C04F8EEB3E}")

$IID_IShellFolderViewCB  = GUID$("{2047E320-F2A9-11CE-AE65-08002B2E1262}")
$SID_ShellFolderViewCB   = $IID_IShellFolderViewCB

$CLSID_CFSIconOverlayManager = GUID$("{63B51F81-C868-11D0-999C-00C04FD655E1}")


$IID_IShellIconOverlayManager = GUID$("{f10b5e34-dd3b-42a7-aa7d-2f4ec54bb09b}")

$IID_IThumbnailCapture   = GUID$("{4ea39266-7211-409f-b622-f63dbd16c533}")

#IF (%WIN32_IE >= &H0500)

$IID_IShellImageStore    = GUID$("{48C8118C-B924-11d1-98D5-00C04FB687DA}")

#IF (%NTDDI_VERSION < %NTDDI_VISTA) ' removed in Windows Vista
$CLSID_ShellThumbnailDiskCache = GUID$("{1EBDCF80-A200-11d0-A3A4-00C04FD706EC}")
#ENDIF

#ENDIF


$IID_IContextMenu3       = GUID$("{BCFCE0A0-EC17-11d0-8D10-00A0C90F2719}")


#ENDIF ' %WIN32_IE >= &H0400

$SID_DefView             = GUID$("{6D12FE80-7911-11CF-9534-0000C05BAE0B}")

$CGID_DefView            = GUID$("{4af07f10-d231-11d0-b942-00a0c90312e1}")

$CLSID_MenuBand          = GUID$("{5b4dae26-b807-11d0-9815-00c04fd91972}")

' IShellFolderBand stuff
$IID_IShellFolderBand    = GUID$("{7FE80CC8-C247-11d0-B93A-00A0C90312E1}")
$IID_IDefViewFrame       = GUID$("{710EB7A0-45ED-11D0-924A-0020AFC7AC4D}")


$VID_LargeIcons          = GUID$("{0057D0E0-3573-11CF-AE69-08002B2E1262}")
$VID_SmallIcons          = GUID$("{089000C0-3573-11CF-AE69-08002B2E1262}")
$VID_List                = GUID$("{0E1FA5E0-3573-11CF-AE69-08002B2E1262}")
$VID_Details             = GUID$("{137E7700-3573-11CF-AE69-08002B2E1262}")
' 5984FFE0-28D4-11CF-AE66-08002B2E1262
$VID_Tile                = GUID$("{65F125E5-7BE1-4810-BA9D-D271C8432CE3}")
$VID_Content             = GUID$("{30C2C434-0889-4c8d-985D-A9F71830B0A9}")


' NOTE: This has to be the same as the old CLSID_Thumbnails
$VID_Thumbnails          = GUID$("{8BEBB290-52D0-11d0-B7F4-00C04FD706EC}")

' ThumbStrip
$VID_ThumbStrip          = GUID$("{8EEFA624-D1E9-445B-94B7-74FBCE2EA11A}")


$SID_SShellBrowser = $IID_IShellBrowser
#IF (%WIN32_IE >= &H0400)
'$SID_SShellDesktop = $CLSID_ShellDesktop
#ENDIF

#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
$SID_SInPlaceBrowser     = GUID$("{1D2AE02B-3655-46CC-B63A-285988153BCA}")
#ENDIF ' %NTDDI_WIN7

#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
$SID_SSearchBoxInfo      = GUID$("{142daa61-516b-4713-b49c-fb985ef82998}")
#ENDIF ' %NTDDI_WIN7

#IF (%WIN32_IE >= &H0400)
'
' IShellDiscardable is an IID-only interface. If the object supports this
' interface it can be discarded any time. IWebBrowser::PutProperty QI's for
' this interface to detect discardable properties.
'
$IID_IDiscardableBrowserProperty = GUID$("{49c3de7c-d329-11d0-ab73-00c04fc33e80}")

' IShellChangeNotify is a sink of LPCITEMIDLIST notification events
'
$IID_IShellChangeNotify = GUID$("{D82BE2B1-5764-11D0-A96E-00C04FD705A2}")

#ENDIF ' %WIN32_IE >= &H0400

#IF %DEF(%UNICODE)
$IID_IFileViewer       = $IID_IFileViewerW
$IID_IShellLink        = $IID_IShellLinkW
$IID_IExtractIcon      = $IID_IExtractIconW
$IID_IShellCopyHook    = $IID_IShellCopyHookW
$IID_IShellExecuteHook = $IID_IShellExecuteHookW
$IID_INewShortcutHook  = $IID_INewShortcutHookW
#ELSE
$IID_IFileViewer       = $IID_IFileViewerA
$IID_IShellLink        = $IID_IShellLinkA
$IID_IExtractIcon      = $IID_IExtractIconA
$IID_IShellCopyHook    = $IID_IShellCopyHookA
$IID_IShellExecuteHook = $IID_IShellExecuteHookA
$IID_INewShortcutHook  = $IID_INewShortcutHookA
#ENDIF


#IF NOT %DEF(%NO_INTSHCUT_GUIDS)
#INCLUDE "IsGuids.inc"          ' internet shortcut GUIDs
#ENDIF

#IF NOT %DEF(%NO_SHDOCVW_GUIDS)

'#IF NOT %DEF(%GUID_DEFS_ONLY)
'#include "ExDisp.inc"
'#include "ShlDisp.inc"
'#endif


#IF (%WIN32_IE >= &H0400)
' UrlHistory Guids
$CLSID_CUrlHistory       = GUID$("{3C374A40-BAE4-11CF-BF7D-00AA006946EE}")
$SID_SUrlHistory         = $CLSID_CUrlHistory

'UrlSearchHook Guids
$CLSID_CURLSearchHook    = GUID$("{CFBFAE00-17A6-11D0-99CB-00C04FD64497}")


'$SID_SInternetExplorer   = $IID_IWebBrowserApp
'$SID_SWebBrowserApp      = $IID_IWebBrowserApp

'$SID_SWebBrowserEventsService = $IID_IWebBrowserEventsService

' AutoComplete Guids
$IID_IObjMgr             = GUID$("{00BB2761-6A77-11D0-A535-00C04FD7D062}")
$IID_IACList             = GUID$("{77A130B0-94FD-11D0-A544-00C04FD7d062}")
$IID_IACList2            = GUID$("{470141a0-5186-11d2-bbb6-0060977b464c}")
$IID_ICurrentWorkingDirectory = GUID$("{91956D21-9276-11d1-921A-006097DF5BD4}")
$CLSID_AutoComplete      = GUID$("{00BB2763-6A77-11D0-A535-00C04FD7D062}")
$CLSID_ACLHistory        = GUID$("{00BB2764-6A77-11D0-A535-00C04FD7D062}")
$CLSID_ACListISF         = GUID$("{03C036F1-A186-11D0-824A-00AA005B4383}")
$CLSID_ACLMRU            = GUID$("{6756A641-DE71-11d0-831B-00AA005B4383}")
$CLSID_ACLMulti          = GUID$("{00BB2765-6A77-11D0-A535-00C04FD7D062}")
#IF (%WIN32_IE >= &H0600)
$CLSID_ACLCustomMRU      = GUID$("{6935db93-21e8-4ccc-beb9-9fe3c77a297a}")
#ENDIF


#IF (%WIN32_IE >= &H0500)
' IProgressDialog
$CLSID_ProgressDialog    = GUID$("{F8383852-FCD3-11d1-A6B9-006097DF5BD4}")
$IID_IProgressDialog     = GUID$("{EBBC7C04-315E-11d2-B62F-006097DF5BD4}")
#ENDIF ' %WIN32_IE >= &H0500

'
' Progress objects exposed via QueryService
'
$SID_SProgressUI         = $CLSID_ProgressDialog


'
' Top-most browser implementation in the heirarchy. use IServiceProvider::QueryService()
' to get to interfaces (IID_IShellBrowser, IID_IShellBrowserService, etc.)
'
$SID_STopLevelBrowser    = GUID$("{4C96BE40-915C-11CF-99D3-00AA004AE837}")

#ENDIF ' %WIN32_IE >= &H0400

#ENDIF ' NOT %NO_SHDOCVW_GUIDS


$CLSID_FileTypes         = GUID$("{B091E540-83E3-11CF-A713-0020AFD79762}")


#IF (%WIN32_IE >= &H0400)

$CLSID_ActiveDesktop       = GUID$("{75048700-EF1F-11D0-9888-006097DEACF9}")

$IID_IActiveDesktop        = GUID$("{F490EB00-1240-11D1-9888-006097DEACF9}")

$IID_IActiveDesktopP       = GUID$("{52502EE0-EC80-11D0-89AB-00C04FC2972D}")

$IID_IADesktopP2           = GUID$("{B22754E2-4574-11d1-9888-006097DEACF9}")

$IID_ISynchronizedCallBack = GUID$("{74C26041-70D1-11d1-B75A-00A0C90564FE}")

$IID_IQueryAssociations    = GUID$("{c46ca590-3c3f-11d2-bee6-0000f805ca57}")

$CLSID_QueryAssociations   = GUID$("{a07034fd-6caa-4954-ac3f-97a27216f98a}")

$IID_IColumnProvider       = GUID$("{E8025004-1C42-11d2-BE2C-00A0C9A83DA1}")

$CLSID_LinkColumnProvider  = GUID$("{24F14F02-7B1C-11d1-838f-0000F80461CF}")

' For Internet Shortcut Creation Command
' The shell uses this command to allow trident to save off its per frame data
' in the shortcut
' and to allow it to fire the OnPersist() event on every frame
$CGID_ShortCut             = GUID$("{93A68750-951A-11d1-946F-000000000000}")


$IID_INamedPropertyBag     = GUID$("{FB700430-952C-11d1-946F-000000000000}")

$CLSID_InternetButtons     = GUID$("{1E796980-9CC5-11D1-A83F-00C04FC99D61}")

#IF (%WIN32_IE >= &H0500)
$CLSID_MSOButtons          = GUID$("{178F34B8-A282-11d2-86C5-00C04F8EEA99}")

$CLSID_ToolbarExtButtons   = GUID$("{2CE4B5D8-A28F-11d2-86C5-00C04F8EEA99}")
#ENDIF ' %WIN32_IE >= &H0500

$CLSID_DarwinAppPublisher  = GUID$("{CFCCC7A0-A282-11D1-9082-006008059382}")

$CLSID_DocHostUIHandler    = GUID$("{7057E952-BD1B-11d1-8919-00C04FC2C836}")
#ENDIF  ' %WIN32_IE >= &H0400

#IF (%WIN32_IE >= &H0500)

$IID_IShellFolder2         = GUID$("{93F2F68C-1D1B-11d3-A30E-00C04F79ABD1}")

$PSGUID_SHELLDETAILS       = "{28636aa6-953d-11d2-b5d6-00c04fd918d0}"
$FMTID_ShellDetails        = GUID$("{28636aa6-953d-11d2-b5d6-00c04fd918d0}")

%PID_FINDDATA        = 0
%PID_NETRESOURCE     = 1
%PID_DESCRIPTIONID   = 2
%PID_WHICHFOLDER     = 3
%PID_NETWORKLOCATION = 4
%PID_COMPUTERNAME    = 5

' PSGUID_STORAGE comes from ntquery.h
'$PSGUID_STORAGE            = "{b725f130-47ef-101a-a5f1-02608c9eebac}"
$FMTID_Storage             = GUID$("{b725f130-47ef-101a-a5f1-02608c9eebac}")

' Image properties
$PSGUID_IMAGEPROPERTIES    = "{14b81da1-0135-4d31-96d9-6cbfc9671a99}"
$FMTID_ImageProperties     = GUID$("{14b81da1-0135-4d31-96d9-6cbfc9671a99}")

' Custom Image Properties (not EXIF tags, which go into the auxiliary image property store)
$PSGUID_CUSTOMIMAGEPROPERTIES = "{7ECD8B0E-C136-4a9b-9411-4EBD6673CCC3}"
$FMTID_CustomImageProperties  = GUID$("{7ECD8B0E-C136-4a9b-9411-4EBD6673CCC3}")

' Library properties
$PSGUID_LIBRARYPROPERTIES = "{5d76b67f-9b3d-44bb-b6ae-25da4f638a67}"
$FMTID_LibraryProperties  = GUID$("{5d76b67f-9b3d-44bb-b6ae-25da4f638a67}")

' The GUIDs used to identify shell item attributes (columns). See IShellFolder2::GetDetailsEx implementations...

$PSGUID_DISPLACED          = "{9B174B33-40FF-11d2-A27E-00C04FC30871}"
$FMTID_Displaced           = GUID$("{9B174B33-40FF-11d2-A27E-00C04FC30871}")
%PID_DISPLACED_FROM = 2
%PID_DISPLACED_DATE = 3

$PSGUID_BRIEFCASE          = "{328D8B21-7729-4bfc-954C-902B329D56B0}"
$FMTID_Briefcase           = GUID$("{328D8B21-7729-4bfc-954C-902B329D56B0}")
%PID_SYNC_COPY_IN   = 2


$PSGUID_MISC               = "{9B174B34-40FF-11d2-A27E-00C04FC30871}"
$FMTID_Misc                = GUID$("{9B174B34-40FF-11d2-A27E-00C04FC30871}")
%PID_MISC_STATUS       = 2
%PID_MISC_ACCESSCOUNT  = 3
%PID_MISC_OWNER        = 4
%PID_HTMLINFOTIPFILE   = 5
%PID_MISC_PICS         = 6
' Do not add more pids beyond what shipped in Server 2k3 - just add PROPERTYKEYs to propkey.w

$PSGUID_WEBVIEW            = "{F2275480-F782-4291-BD94-F13693513AEC}"
$FMTID_WebView             = GUID$("{F2275480-F782-4291-BD94-F13693513AEC}")
%PID_DISPLAY_PROPERTIES = 0
%PID_INTROTEXT          = 1

$PSGUID_MUSIC              = "{56A3372E-CE9C-11d2-9F0E-006097C686F6}"
$FMTID_MUSIC               = GUID$("{56A3372E-CE9C-11d2-9F0E-006097C686F6}")
%PIDSI_ARTIST    = 2
%PIDSI_SONGTITLE = 3
%PIDSI_ALBUM     = 4
%PIDSI_YEAR      = 5
%PIDSI_COMMENT   = 6
%PIDSI_TRACK     = 7
%PIDSI_GENRE     = 11
%PIDSI_LYRICS    = 12
' Do not add more pids to this file. Add new PROPERTYKEYs to propkey.w instead

$PSGUID_DRM                = "{AEAC19E4-89AE-4508-B9B7-BB867ABEE2ED}"
$FMTID_DRM                 = GUID$("{AEAC19E4-89AE-4508-B9B7-BB867ABEE2ED}")
%PIDDRSI_PROTECTED   = 2
%PIDDRSI_DESCRIPTION = 3
%PIDDRSI_PLAYCOUNT   = 4
%PIDDRSI_PLAYSTARTS  = 5
%PIDDRSI_PLAYEXPIRES = 6

$PSGUID_VIDEO              = "{64440491-4C8B-11D1-8B70-080036B11A03}"
'  FMTID_VideoSummaryInformation property identifiers.  See propkey.h for their types.
%PIDVSI_STREAM_NAME   = &H00000002 ' "System.Video.StreamName"   (old name "StreamName")
%PIDVSI_FRAME_WIDTH   = &H00000003 ' "System.Video.FrameWidth"   (old name "FrameWidth")
%PIDVSI_FRAME_HEIGHT  = &H00000004 ' "System.Video.FrameHeight"  (old name "FrameHeight")
%PIDVSI_TIMELENGTH    = &H00000007 '                             (old name "TimeLength")
%PIDVSI_FRAME_COUNT   = &H00000005 ' "System.Media.FrameCount"   (old name "FrameCount")
%PIDVSI_FRAME_RATE    = &H00000006 ' "System.Video.FrameRate"    (old name "FrameRate")
%PIDVSI_DATA_RATE     = &H00000008 ' "System.Video.DataRate"     (old name "DataRate")
%PIDVSI_SAMPLE_SIZE   = &H00000009 ' "System.Video.SampleSize"   (old name "SampleSize")
%PIDVSI_COMPRESSION   = &H0000000A ' "System.Video.Compression"  (old name "Compression")
%PIDVSI_STREAM_NUMBER = &H0000000B ' "System.Video.StreamNumber" (old name "StreamNumber")

$PSGUID_AUDIO              = "{64440490-4C8B-11D1-8B70-080036B11A03}"
'  FMTID_AudioSummaryInformation property identifiers
%PIDASI_FORMAT         = &H00000002 ' VT_BSTR
%PIDASI_TIMELENGTH     = &H00000003 ' VT_UI4, milliseconds
%PIDASI_AVG_DATA_RATE  = &H00000004 ' VT_UI4,  Hz
%PIDASI_SAMPLE_RATE    = &H00000005 ' VT_UI4,  bits
%PIDASI_SAMPLE_SIZE    = &H00000006 ' VT_UI4,  bits
%PIDASI_CHANNEL_COUNT  = &H00000007 ' VT_UI4
%PIDASI_STREAM_NUMBER  = &H00000008 ' VT_UI2
%PIDASI_STREAM_NAME    = &H00000009 ' VT_LPWSTR
%PIDASI_COMPRESSION    = &H0000000A ' VT_LPWSTR
' Do not add more pids to this file. Add new PROPERTYKEYs to propkey.w instead


$PSGUID_CONTROLPANEL       = "{305CA226-D286-468e-B848-2B2E8E697B74}"
%PID_CONTROLPANEL_CATEGORY = 2
' Do not add more pids to this file. Add new PROPERTYKEYs to propkey.w instead

$PSGUID_VOLUME             = "{9B174B35-40FF-11d2-A27E-00C04FC30871}"
$FMTID_Volume              = GUID$("{9B174B35-40FF-11d2-A27E-00C04FC30871}")
%PID_VOLUME_FREE       = 2
%PID_VOLUME_CAPACITY   = 3
%PID_VOLUME_FILESYSTEM = 4
' Do not add more pids to this file. Add new PROPERTYKEYs to propkey.w instead

$PSGUID_SHARE              = "{D8C3986F-813B-449c-845D-87B95D674ADE}"
%PID_SHARE_CSC_STATUS  = 2   ' server or share status, "online" "offline"
' Do not add more pids to this file. Add new PROPERTYKEYs to propkey.w instead

$PSGUID_LINK               = "{B9B4B3FC-2B51-4a42-B5D8-324146AFCF25}"
%PID_LINK_TARGET       = 2
%PID_LINK_TARGET_TYPE  = 3

$PSGUID_QUERY_D            = "{49691c90-7e17-101a-a91c-08002b2ecda9}"
$FMTID_Query               = GUID$("{49691c90-7e17-101a-a91c-08002b2ecda9}")
%PID_QUERY_RANK = 2

' FMTID_SummaryInformation, see OLE docs for PID_ values for these
$PSGUID_SUMMARYINFORMATION = "{f29f85e0-4ff9-1068-ab91-08002b27b3d9}"
' FMTID_DocumentSummaryInformation, see OLE docs on the PID_ values for this
$PSGUID_DOCUMENTSUMMARYINFORMATION = "{d5cdd502-2e9c-101b-9397-08002b2cf9ae}"

' FMTID_MediaFileSummaryInformation, see propidl.h PID_ values for this
$PSGUID_MEDIAFILESUMMARYINFORMATION = "{&H64440492-4c8b-11d1-8b70-080036b11a03}"

' FMTID_ImageSummaryInformation
$PSGUID_IMAGESUMMARYINFORMATION = "{6444048f-4c8b-11d1-8b70-080036b11a03}"

$IID_IEnumExtraSearch      = "{0E700BE1-9DB6-11d1-A1CE-00C04FD75D13}"

$CLSID_HWShellExecute      = GUID$("{FFB8655F-81B9-4fce-B89C-9A6BA76D13E7}")
$CLSID_DragDropHelper      = GUID$("{4657278A-411B-11d2-839A-00C04FD918D0}")

$CLSID_CAnchorBrowsePropertyPage = GUID$("{3050f3BB-98b5-11cf-bb82-00aa00bdce0b}")
$CLSID_CImageBrowsePropertyPage  = GUID$("{3050f3B3-98b5-11cf-bb82-00aa00bdce0b}")
$CLSID_CDocBrowsePropertyPage    = GUID$("{3050f3B4-98b5-11cf-bb82-00aa00bdce0b}")

$IID_IFileSystemBindData     = GUID$("{01E18D10-4D8B-11d2-855D-006008059367}")
$SID_STopWindow              = GUID$("{49E1B500-4636-11d3-97F7-00C04F45D0B3}")
$SID_SGetViewFromViewDual    = GUID$("{889A935D-971E-4B12-B90C-24DFC9E1E5E8}")
$CLSID_FolderItem            = GUID$("{FEF10FA2-355E-4e06-9381-9B24D7F7CC88}")
$CLSID_FolderItemsMultiLevel = GUID$("{53C74826-AB99-4d33-ACA4-3117F51D3788}")
$CLSID_NewMen                = GUID$("{D969A300-E7FF-11d0-A93B-00A0C90F2719}")


'  BHIDs for IShellItem::BindToHandler()


' use this for IShellFolder::BindToObject() objects; IShellFolder
$BHID_SFObject = GUID$("{3981e224-f559-11d3-8e3a-00c04f6837d5}")

' use this for IShellFolder::GetUIObject() objects; IContextMenu, IDataObject, IDropTarget, IQueryAssociation, etc.
$BHID_SFUIObject = GUID$("{3981e225-f559-11d3-8e3a-00c04f6837d5}")

' use this for IShellFolder::CreateViewObject() objects; IShellView, IDropTarget, IContextMenu
$BHID_SFViewObject = GUID$("{3981e226-f559-11d3-8e3a-00c04f6837d5}")

' use this for storage objects like IStream, IPropertyStore, IStorage
$BHID_Storage = GUID$("{3981e227-f559-11d3-8e3a-00c04f6837d5}")

' use this to get an IStream for the item
$BHID_Stream = GUID$("{1CEBB3AB-7C10-499a-A417-92CA16C4CB83}")

' use this to deref the item if it is a link to get its target item, use IShellItem
$BHID_LinkTargetItem = GUID$("{3981e228-f559-11d3-8e3a-00c04f6837d5}")

' if the item is a folder use this to get an IEnumShellItems that enumerates the storage contents
$BHID_StorageEnum = GUID$("{4621A4E3-F0D6-4773-8A9C-46E77B174840}")

' if the item is a folder use this to get an ITransferSource or ITransferDestiation object
$BHID_Transfer = GUID$("{5D080304-FE2C-48fc-84CE-CF620B0F3C53}")

' use this to get an IPropertyStore or IPropertyStoreFactory
' to have more control over the property store for the item
$BHID_PropertyStore = GUID$("{0384e1a4-1523-439c-a4c8-ab911052f586}")

' use this to get IExtractImage / IThumbnailProvider for an item
$BHID_ThumbnailHandler = GUID$("{7b2e650a-8e20-4f4a-b09e-6597afc72fb0}")

' if the item is a folder use this to get an IEnumShellItems that enumerates all items
' in the folder including folders, non folders and hidden items
$BHID_EnumItems = GUID$("{94f60519-2850-4924-aa5a-d15e84868039}")

' use this to get an IDataObject for an item or an array of items IShellItem/IShellItemArray::BindToHandler()
$BHID_DataObject = GUID$("{B8C0BD9F-ED24-455c-83E6-D5390C4FE8C4}")

' use this to get an IQueryAssociations for an item or an array of items IShellItem/IShellItemArray::BindToHandler()
$BHID_AssociationArray = GUID$("{bea9ef17-82f1-4f60-9284-4f8db75c3be9}")

' use this to get an IFilter for an item
$BHID_Filter = GUID$("{38d08778-f557-4690-9ebf-ba54706ad8f7}")

' use this to retrieve an IEnumAssocHandlers that enumerates the association handlers for the given item.  Returns an
' enumeration of recommended handlers, similar to calling SHAssocEnumHandlers with ASSOC_FILTER_RECOMMENDED.
$BHID_EnumAssocHandlers = GUID$("{b8ab0b9c-c2ec-4f7a-918d-314900e6280a}")


#ENDIF ' %WIN32_IE >= &H0500

#IF %WIN32_IE >= &H0600

$SID_CtxQueryAssociations = GUID$("{faadfc40-b777-4b69-aa81-77035ef0e6e8}")

#ENDIF ' %WIN32_IE >= &H0600


$IID_IDocViewSite  = GUID$("{87D605E0-C511-11CF-89A9-00A0C9054129}")


$CLSID_QuickLinks  = GUID$("{0E5CBF21-D15F-11d0-8301-00AA005B4383}")

' The IShellFolder band
$CLSID_ISFBand     = GUID$("{082BE2B0-5764-11D0-A96E-00C04FD705A2}")

$IID_CDefView      = GUID$("{4434FF80-EF4C-11CE-AE65-08002B2E1262}")


$CLSID_ShellFldSetExt = GUID$("{6D5313C0-8C62-11D1-B2CD-006097DF8C11}")

$SID_SMenuBandChild   = GUID$("{ed9cc020-08b9-11d1-9823-00c04fd91972}")

$SID_SMenuBandParent  = GUID$("{8c278eec-3eab-11d1-8cb0-00c04fd918d0}")

$SID_SMenuPopup       = GUID$("{01E7AFEB-6A2E-11d0-8C78-00C04FD918B4}")

$SID_SMenuBandBottomSelected = GUID$("{165EBAF4-6D51-11d2-83AD-00C04FD918D0}")

$SID_SMenuBandBottom  = GUID$("{743ca664-0deb-11d1-9825-00c04fd91972}")


$SID_MenuShellFolder  = GUID$("{A6C17EB4-2D65-11d2-838F-00C04FD918D0}")


$SID_SMenuBandContextMenuModifier = GUID$("{39545874-7162-465e-b783-2aa1874fef81}")


$SID_SMenuBandBKContextMenu = GUID$("{164BBD86-1D0D-4de0-9A3B-D9729647C2B8}")

'Command Group ID for MenuDeskBar

$CGID_MENUDESKBAR = GUID$("{5C9F0A12-959E-11d0-A3A4-00A0C9082636}")

$SID_SMenuBandTop = GUID$("{9493a810-ec38-11d0-bc46-00aa006ce2f5}")


$CLSID_MenuToolbarBase = GUID$("{40B96610-B522-11d1-B3B4-00AA006EFDE7}")

$IID_IBanneredBar = GUID$("{596A9A94-013E-11d1-8D34-00A0C90F2719}")

$CLSID_MenuBandSite = GUID$("{E13EF4E4-D2F2-11d0-9816-00C04FD91972}")

$SID_SCommDlgBrowser = GUID$("{80F30233-B7DF-11d2-A33B-006097DF5BD4}")


'
' These GUIDs may be assigned to the CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR::guidFieldType
' member by Microsoft ICredentialProvider implementations.
'

$CPFG_LOGON_USERNAME = GUID$("{da15bbe8-954d-4fd3-b0f4-1fb5b90b174b}")

$CPFG_LOGON_PASSWORD = GUID$("{60624cfa-a477-47b1-8a8e-3a4a19981827}")

$CPFG_SMARTCARD_USERNAME = GUID$("{3e1ecf69-568c-4d96-9d59-46444174e2d6}")

$CPFG_SMARTCARD_PIN = GUID$("{4fe5263b-9181-46c1-b0a4-9dedd4db7dea}")


'
'  Known Folder IDs
'
#INCLUDE "KnownFolders.inc"


' some known folder types

' default value == GUID_NULL

'$FOLDERTYPEID_NotSpecified = GUID$("{5c4f28b5-f869-4e84-8e60-f11db97c5cc7}")

$FOLDERTYPEID_Invalid = GUID$("{57807898-8c4f-4462-bb63-71042380b109}")

' FOLDERTYPEID_Generic:
$FOLDERTYPEID_Generic = GUID$("{5c4f28b5-f869-4e84-8e60-f11db97c5cc7}")

' FOLDERTYPEID_GenericSearchResults:
$FOLDERTYPEID_GenericSearchResults = GUID$("{7fde1a1e-8b31-49a5-93b8-6be14cfa4943}")

' FOLDERTYPEID_GenericLibrary:
$FOLDERTYPEID_GenericLibrary = GUID$("{5f4eab9a-6833-4f61-899d-31cf46979d49}")

' typically under FOLDERID_Documents
$FOLDERTYPEID_Documents = GUID$("{7d49d726-3c21-4f05-99aa-fdc2c9474656}")

' typically under FOLDERID_Pictures, where there's fewer images
$FOLDERTYPEID_Pictures = GUID$("{b3690e58-e961-423b-b687-386ebfd83239}")

' FOLDERTYPEID_Music:
$FOLDERTYPEID_Music = GUID$("{94d6ddcc-4a68-4175-a374-bd584a510b78}")

' FOLDERTYPEID_Videos:
$FOLDERTYPEID_Videos = GUID$("{5fa96407-7e77-483c-ac93-691d05850de8}")

' FOLDERTYPEID_UserFiles:
$FOLDERTYPEID_UserFiles = GUID$("{CD0FC69B-71E2-46e5-9690-5BCD9F57AAB3}")

' FOLDERTYPID_UsersLibraries
$FOLDERTYPEID_UsersLibraries = GUID$("{C4D98F09-6124-4fe0-9942-826416082DA9}")

' FOLDERTYPEID_OtherUsers,
$FOLDERTYPEID_OtherUsers = GUID$("{B337FD00-9DD5-4635-A6D4-DA33FD102B7A}")

' {7F2F5B96-FF74-41da-AFD8-1C78A5F3AEA2}
$FOLDERTYPEID_PublishedItems = GUID$("{7F2F5B96-FF74-41da-AFD8-1C78A5F3AEA2}")

' FOLDERTYPEID_Communications:
$FOLDERTYPEID_Communications = GUID$("{91475fe5-586b-4eba-8d75-d17434b8cdf6}")

' FOLDERTYPEID_Contacts:
$FOLDERTYPEID_Contacts = GUID$("{de2b70ec-9bf7-4a93-bd3d-243f7881d492}")

' typically under FOLDERID_Music, where there's many songs in a list
'$FOLDERTYPEID_MusicDetails = GUID$("{af9c03d6-7db9-4a15-9464-13bf9fb69a2a}")

' typically under FOLDERID_Music, where we're displaying a set of folders
'$FOLDERTYPEID_MusicIcons = GUID$("{0b7467fb-84ba-4aae-a09b-15b71097af9e}")

' FOLDERTYPEID_Games Folder
$FOLDERTYPEID_Games = GUID$("{b689b0d0-76d3-4cbb-87f7-585d0e0ce070}")

' category view of control panel
$FOLDERTYPEID_ControlPanelCategory = GUID$("{de4f0660-fa10-4b8f-a494-068b20b22307}")

' classic-mode control panel
$FOLDERTYPEID_ControlPanelClassic = GUID$("{0c3794f3-b545-43aa-a329-c37430c58d2a}")

' prnfldr
$FOLDERTYPEID_Printers = GUID$("{2c7bbec6-c844-4a0a-91fa-cef6f59cfda1}")

' bbckfldr
$FOLDERTYPEID_RecycleBin = GUID$("{d6d9e004-cd87-442b-9d57-5e0aeb4f6f72}")

' software explorer for ARP
$FOLDERTYPEID_SoftwareExplorer = GUID$("{d674391b-52d9-4e07-834e-67c98610f39d}")

' ZIP folders
$FOLDERTYPEID_CompressedFolder = GUID$("{80213e82-bcfd-4c4f-8817-bb27601267a9}")

' this only needs to be defined here because it's used by the multimedia depot
' contact folders under FOLDERID_Contacts
'$FOLDERTYPEID_Contacts = GUID$("{de2b70ec-9bf7-4a93-bd3d-243f7881d492}")

' default library views that don't have a more specific template
'$FOLDERTYPEID_Library = GUID$("{4badfc68-c4ac-4716-a0a0-4d5daa6b0f3e}")

' NetworkExplorerFolder
$FOLDERTYPEID_NetworkExplorer = GUID$("{25CC242B-9A7C-4f51-80E0-7A2928FEBE42}")

' User files folder
'$FOLDERTYPEID_UserFiles = GUID$("{CD0FC69B-71E2-46e5-9690-5BCD9F57AAB3}")

' searches folder
' FOLDERTYPEID_Searches:
$FOLDERTYPEID_Searches = GUID$("{0b0ba2e3-405f-415e-a6ee-cad625207853}")

' search home
' FOLDERTYPEID_SearchHome:
$FOLDERTYPEID_SearchHome = GUID$("{834d8a44-0974-4ed6-866e-f203d80b3810}")


'
' Sync Manager object IDs.  These are GUIDs used in calls to the GetObject()
' method on ISyncMgrHandler and ISyncMgrSyncItem, defined in SyncMgr.idl.
'

$SYNCMGR_OBJECTID_Icon = GUID$("{6DBC85C3-5D07-4c72-A777-7FEC78072C06}")

$SYNCMGR_OBJECTID_EventStore = GUID$("{4BEF34B9-A786-4075-BA88-0C2B9D89A98F}")

$SYNCMGR_OBJECTID_ConflictStore = GUID$("{D78181F4-2389-47e4-A960-60BCC2ED930B}")

$SYNCMGR_OBJECTID_BrowseContent = GUID$("{57CBB584-E9B4-47ae-A120-C4DF3335DEE2}")

$SYNCMGR_OBJECTID_ShowSchedule = GUID$("{EDC6F3E3-8441-4109-ADF3-6C1CA0B7DE47}")

$SYNCMGR_OBJECTID_QueryBeforeActivate = GUID$("{D882D80B-E7AA-49ed-86B7-E6E1F714CDFE}")

$SYNCMGR_OBJECTID_QueryBeforeDeactivate = GUID$("{A0EFC282-60E0-460e-9374-EA88513CFC80}")

$SYNCMGR_OBJECTID_QueryBeforeEnable = GUID$("{04CBF7F0-5BEB-4de1-BC90-908345C480F6}")

$SYNCMGR_OBJECTID_QueryBeforeDisable = GUID$("{BB5F64AA-F004-4eb5-8E4D-26751966344C}")

$SYNCMGR_OBJECTID_QueryBeforeDelete = GUID$("{F76C3397-AFB3-45d7-A59F-5A49E905437E}")

$SYNCMGR_OBJECTID_EventLinkClick = GUID$("{2203bdc1-1af1-4082-8c30-28399f41384c}")

' IExplorerPaneVisibility constants
$EP_NavPane            = GUID$("{cb316b22-25f7-42b8-8a09-540d23a43c2f}")
$EP_Commands           = GUID$("{d9745868-ca5f-4a76-91cd-f5a129fbb076}")
$EP_Commands_Organize  = GUID$("{72e81700-e3ec-4660-bf24-3c3b7b648806}")
$EP_Commands_View      = GUID$("{21f7c32d-eeaa-439b-bb51-37b96fd6a943}")
$EP_DetailsPane        = GUID$("{43abf98b-89b8-472d-b9ce-e69b8229f019}")
$EP_PreviewPane        = GUID$("{893c63d1-45c8-4d17-be19-223be71be365}")
$EP_QueryPane          = GUID$("{65bcde4f-4f07-4f27-83a7-1afca4df7ddd}")
$EP_AdvQueryPane       = GUID$("{b4e9db8b-34ba-4c39-b5cc-16a1bd2c411c}")

$CATID_LocationFactory = GUID$("{965c4d51-8b76-4e57-80b7-564d2ea4b55e}")
$CATID_LocationProvider= GUID$("{1b3ca474-2614-414b-b813-1aceca3e3dd8}")

' ItemsView
$ItemCount_Property_GUID = GUID$("{ABBF5C45-5CCC-47b7-BB4E-87CB87BBD162}")
$SelectedItemCount_Property_GUID = GUID$("{8FE316D2-0E52-460a-9C1E-48F273D470A3}")
$ItemIndex_Property_GUID = GUID$("{92A053DA-2969-4021-BF27-514CFC2E4A69}")
