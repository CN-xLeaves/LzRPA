
Declare Function GetPathDir Lib "xyapi.dll" Alias "GetPathDir" (ByVal sPath As ASCIIZ) As ASCIIZ
Declare Function GetPathFile Lib "xyapi.dll" Alias "GetPathFile" (ByVal sPath As ASCIIZ) As ASCIIZ
Declare Function GetPathAbs Lib "xyapi.dll" Alias "GetPathAbs" (ByVal sPath As ASCIIZ) As ASCIIZ
Declare Function GetPathRel Lib "xyapi.dll" Alias "GetPathRel" (ByVal sDir1 As ASCIIZ, ByVal sDir2 As ASCIIZ) As ASCIIZ
Declare Function GetPathPixel Lib "xyapi.dll" Alias "GetPathPixel" (ByVal sPath As ASCIIZ, ByVal hWin As Long, ByVal iPixel As Long) As ASCIIZ
Declare Function GetPathPixelDC Lib "xyapi.dll" Alias "GetPathPixelDC" (ByVal sPath As ASCIIZ, ByVal hDC As Long, ByVal iPixel As Long) As ASCIIZ
Declare Function GetRandPath Lib "xyapi.dll" Alias "GetRandPath" (ByVal sPathHead As ASCIIZ, ByVal sPathFoot As ASCIIZ, ByVal iRandSize As Long) As ASCIIZ

Declare Function Lock_Create lib "xyapi.dll" Alias "Lock_Create" () As Long
Declare Sub Lock_Free lib "xyapi.dll" Alias "Lock_Free" (pLock As Long)
Declare Sub Lock_On lib "xyapi.dll" Alias "Lock_On" (pLock As Long)
Declare Sub Lock_Off lib "xyapi.dll" Alias "Lock_Off" (pLock As Long)

Declare Function Drives_List Lib "kernel32.dll" Alias "GetLogicalDrives" () As Long
Declare Function Drives_Type Lib "kernel32.dll" Alias "GetDriveTypeA" (ByVal sDrives As ASCIIZ) As Long

/*
Declare Function File_List lib "xyapi.dll" Alias "File_List" (ByVal sPath As ASCIIZ, ByVal sFilt As ASCIIZ, ByVal iAttr As Long, ByVal iAtex As Long, ByVal iRecu As Long) As ASCIIZ
Declare Function File_ListName lib "xyapi.dll" Alias "File_ListName" (ByVal sPath As ASCIIZ, ByVal sFilt As ASCIIZ, ByVal iAttr As Long, ByVal iAtex As Long) As ASCIIZ

Declare Function File_Read lib "xyapi.dll" Alias "File_Read" (ByVal sPath As STRING) As STRING
Declare Function File_ReadEx lib "xyapi.dll" Alias "File_ReadEx" (ByVal sPath As ASCIIZ, ByVal iAddr As Long, ByVal iSize As Long, ByVal eChar As Long) As ASCIIZ
Declare Function File_Write lib "xyapi.dll" Alias "File_Write" (ByVal sPath As ASCIIZ, ByVal sText As ASCIIZ, ByVal iSize As Long) As Long
Declare Function File_WriteEx lib "xyapi.dll" Alias "File_WriteEx" (ByVal sPath As ASCIIZ, ByVal sText As ASCIIZ, ByVal iAddr As Long, ByVal iSize As Long, ByVal eChar As Long) As Long
Declare Function File_Append lib "xyapi.dll" Alias "File_Append" (ByVal sPath As ASCIIZ, ByVal sText As ASCIIZ, ByVal iSize As Long) As Long
Declare Function File_AppendEx lib "xyapi.dll" Alias "File_AppendEx" (ByVal sPath As ASCIIZ, ByVal sText As ASCIIZ, ByVal iSize As Long, ByVal eChar As Long) As Long
Declare Function File_Len lib "xyapi.dll" Alias "File_Len" (ByVal sPath As ASCIIZ) As Long
Declare Function File_LenEx lib "xyapi.dll" Alias "File_LenEx" (ByVal sPath As ASCIIZ) As QUAD
Declare Function File_Create lib "xyapi.dll" Alias "File_Create" (ByVal sPath As ASCIIZ) As Long
Declare Function File_Copy lib "xyapi.dll" Alias "File_Copy" (ByVal sPathSrc As ASCIIZ, ByVal sPathDst As ASCIIZ) As Long
Declare Function File_Move lib "xyapi.dll" Alias "File_Move" (ByVal sPathSrc As ASCIIZ, ByVal sPathDst As ASCIIZ) As Long
Declare Function File_Rename lib "xyapi.dll" Alias "File_Rename" (ByVal sPathSrc As ASCIIZ, ByVal sPathDst As ASCIIZ) As Long
Declare Function File_Delete lib "kernel32.dll" Alias "DeleteFileA" (ByVal sPath As ASCIIZ) As Long
Declare Function File_Exists lib "xyapi.dll" Alias "File_Exists" (ByVal sPath As ASCIIZ) As Long
Declare Function File_GetAttr lib "kernel32.dll" Alias "GetFileAttributesA" (ByVal sPath As ASCIIZ) As Long
Declare Function File_SetAttr lib "kernel32.dll" Alias "SetFileAttributesA" (ByVal sPath As ASCIIZ, ByVal uVal As Long) As Long
*/

Declare Function Folder_Len lib "xyapi.dll" Alias "Folder_Len" (ByVal sPath As ASCIIZ, ByVal sFilt As ASCIIZ, ByVal iRecu As Long) As Long
Declare Function Folder_LenEx lib "xyapi.dll" Alias "Folder_LenEx" (ByVal sPath As ASCIIZ, ByVal sFilt As ASCIIZ, ByVal iRecu As Long) As QUAD
Declare Function Folder_Create lib "xyapi.dll" Alias "Folder_Create" (ByVal sPath As ASCIIZ) As Long
Declare Function Folder_Exists lib "xyapi.dll" Alias "Folder_Exists" (ByVal sPath As ASCIIZ) As Long
Declare Function Folder_Copy lib "xyapi.dll" Alias "Folder_Copy" (ByVal sPathSrc As ASCIIZ, ByVal sPathDst As ASCIIZ, ByVal sFilt As ASCIIZ, ByVal iRecu As Long) As Long
Declare Function Folder_Move lib "xyapi.dll" Alias "Folder_Move" (ByVal sPathSrc As ASCIIZ, ByVal sPathDst As ASCIIZ, ByVal sFilt As ASCIIZ, ByVal iRecu As Long) As Long
Declare Function Folder_Rename lib "xyapi.dll" Alias "File_Rename" (ByVal sPathSrc As ASCIIZ, ByVal sPathDst As ASCIIZ) As Long
Declare Function Folder_Delete lib "xyapi.dll" Alias "Folder_Delete" (ByVal sPath As ASCIIZ, ByVal sFilt As ASCIIZ, ByVal iRecu As Long) As Long
Declare Function Folder_GetAttr lib "kernel32.dll" Alias "GetFileAttributesA" (ByVal sPath As ASCIIZ) As Long
Declare Function Folder_SetAttr lib "kernel32.dll" Alias "SetFileAttributesA" (ByVal sPath As ASCIIZ, ByVal uVal As Long) As Long

Declare Function Ini_Read lib "xyapi.dll" Alias "Ini_Read" (ByVal file As ASCIIZ, ByVal sec As ASCIIZ, ByVal key As ASCIIZ) As ASCIIZ
Declare Function Ini_ReadInt lib "xyapi.dll" Alias "Ini_ReadInt" (ByVal file As ASCIIZ, ByVal sec As ASCIIZ, ByVal key As ASCIIZ) As Long
Declare Function Ini_Write lib "xyapi.dll" Alias "Ini_Write" (ByVal file As ASCIIZ, ByVal sec As ASCIIZ, ByVal key As ASCIIZ, ByVal value As ASCIIZ) As Long
Declare Function Ini_EnumSec lib "xyapi.dll" Alias "Ini_EnumSec" (ByVal file As ASCIIZ) As ASCIIZ
Declare Function Ini_EnumKey lib "xyapi.dll" Alias "Ini_EnumKey" (ByVal file As ASCIIZ, ByVal sec As ASCIIZ) As ASCIIZ
Declare Function Ini_DelSec lib "xyapi.dll" Alias "Ini_DelSec" (ByVal file As ASCIIZ, ByVal sec As ASCIIZ) As Long
Declare Function Ini_DelKey lib "xyapi.dll" Alias "Ini_DelKey" (ByVal file As ASCIIZ, ByVal sec As ASCIIZ, ByVal key As ASCIIZ) As Long

Declare  Function Sys_Bits Lib "xyapi.dll" Alias "Sys_Bits" () As Long

Declare Function Dlg_OpenFile lib "xyapi.dll" Alias "Dlg_OpenFile" (ByVal Parent As Long, ByVal DefPath As ASCIIZ, ByVal Filter As ASCIIZ) As ASCIIZ Ptr
Declare Function Dlg_OpenFiles lib "xyapi.dll" Alias "Dlg_OpenFiles" (ByVal Parent As Long, ByVal DefPath As ASCIIZ, ByVal Filter As ASCIIZ) As ASCIIZ Ptr
Declare Function Dlg_SaveFile lib "xyapi.dll" Alias "Dlg_SaveFile" (ByVal Parent As Long, ByVal DefPath As ASCIIZ, ByVal Filter As ASCIIZ) As ASCIIZ Ptr
Declare Function Dlg_SelFolder lib "xyapi.dll" Alias "Dlg_SelFolder" (ByVal Parent As Long) As ASCIIZ Ptr
Declare Function Dlg_SelFont lib "xyapi.dll" Alias "Dlg_SelFont" (ByVal Parent As Long) As ASCIIZ Ptr
Declare Function Dlg_SelColor lib "xyapi.dll" Alias "Dlg_SelColor" (ByVal Parent As Long, ByVal defColor As Long) As Long

Declare Function CRC32 lib "xyapi.dll" Alias "CRC32" (ByVal pDat As ASCIIZ, ByVal iSize As Long) As Long
Declare Function CRC32_File lib "xyapi.dll" Alias "CRC32_File" (ByVal sPath As ASCIIZ) As Long
//Declare Function MD5 lib "xyapi.dll" Alias "MD5" (ByVal pDat As ASCIIZ, ByVal iSize As Long) As ASCIIZ
Declare Function MD5_File lib "xyapi.dll" Alias "MD5_File" (ByVal sPath As ASCIIZ) As ASCIIZ
Declare Function SHA1 lib "xyapi.dll" Alias "SHA1" (ByRef pDat As ASCIIZ, ByVal iSize As Long) As ASCIIZ
Declare Function SHA1_File lib "xyapi.dll" Alias "SHA1_File" (ByVal sPath As ASCIIZ) As ASCIIZ
Declare Function SHA256 lib "xyapi.dll" Alias "SHA256" (ByVal pDat As ASCIIZ, ByVal iSize As Long) As ASCIIZ
Declare Function SHA256_File lib "xyapi.dll" Alias "SHA256_File" (ByVal sPath As ASCIIZ) As ASCIIZ
Declare Function Base64_Encode lib "xyapi.dll" Alias "Base64_Encode" (ByVal pDat As ASCIIZ, ByVal iSize As Long) As ASCIIZ
Declare Function Base64_Decode lib "xyapi.dll" Alias "Base64_Decode" (ByVal pDat As ASCIIZ) As ASCIIZ
Declare Function Base64_Encode_File lib "xyapi.dll" Alias "Base64_Encode_File" (ByVal sPath As ASCIIZ) As ASCIIZ
Declare Function Base64_Decode_File lib "xyapi.dll" Alias "Base64_Decode_File" (ByVal sPath As ASCIIZ) As ASCIIZ

Declare Function Window_GetCaption Lib "xyapi.dll" Alias "Window_GetCaption" (ByVal hWnd As Long) As ASCIIZ
Declare Function Window_SetCaption Lib "user32.dll" Alias "SetWindowTextA" (ByVal hWnd As Long, ByVal sText As ASCIIZ) As Long
Declare Function Window_GetText Lib "xyapi.dll" Alias "Window_GetCaption" (ByVal hWnd As Long) As ASCIIZ
Declare Function Window_SetText Lib "user32.dll" Alias "SetWindowTextA" (ByVal hWnd As Long, ByVal sText As ASCIIZ) As Long
Declare Function Window_GetClassName Lib "xyapi.dll" Alias "Window_GetClassName" (ByVal hWnd As Long) As ASCIIZ
Declare Function Window_GetRoot Lib "xyapi.dll" Alias "Window_GetRoot" (ByVal hWnd As Long) As Long
Declare Function Window_GetParent Lib "user32.dll" Alias "GetParent" (ByVal hWnd As Long) As Long
Declare Function Window_H2E Lib "xyapi.dll" Alias "Window_H2E" (ByVal Parent As Long, ByVal ClassName As ASCIIZ, ByVal Eid As Long) As Long
Declare Function Window_List Lib "xyapi.dll" Alias "Window_List" (ByVal Mask As Long, ByVal ClassName As ASCIIZ, ByVal Caption As ASCIIZ, ByVal Style As Long, ByVal ExStyle As Long, ByVal PID As Long, ByVal Thread As Long) As ASCIIZ
Declare Function Window_EasyFind Lib "user32.dll" Alias "FindWindowA" (ByVal sClassName As ASCIIZ, ByVal sCaption As ASCIIZ) As Long



// 已验证使用
Declare Function Window_Send Lib "user32.dll" Alias "SendMessageA" (ByVal hWin As Long, ByVal uMsg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
Declare Function Window_Post Lib "user32.dll" Alias "PostMessageA" (ByVal hWin As Long, ByVal uMsg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
Declare Function Window_Show Lib "user32.dll" Alias "ShowWindow" (ByVal hWin As Long, ByVal iShow As Long) As Long
Declare Function Window_Find Lib "xyapi.dll" Alias "Window_Find" (ByVal Mask As Long, ByVal ClassName As ASCIIZ, ByVal Caption As ASCIIZ, ByVal Style As Long, ByVal ExStyle As Long, ByVal PID As Long, ByVal Thread As Long) As Long
Declare Function Window_E2H Lib "xyapi.dll" Alias "Window_E2H" (ByVal Parent As Long, ByVal ClassName As ASCIIZ, ByVal Eid As Long) As Long
Declare Function Window_GetPID Lib "xyapi.dll" Alias "Window_GetPID" (ByVal hWin As Long) As Long



Declare Function Window_ListChild Lib "xyapi.dll" Alias "Window_ListChild" (ByVal Parent As Long, ByVal Mask As Long, ByVal ClassName As ASCIIZ, ByVal Caption As ASCIIZ, ByVal Style As Long, ByVal ExStyle As Long, ByVal PID As Long, ByVal Thread As Long) As ASCIIZ
Declare Function Window_FindChild Lib "xyapi.dll" Alias "Window_FindChild" (ByVal Parent As Long, ByVal Mask As Long, ByVal ClassName As ASCIIZ, ByVal Caption As ASCIIZ, ByVal Style As Long, ByVal ExStyle As Long, ByVal PID As Long, ByVal Thread As Long) As Long
Declare Function Window_GetTID Lib "xyapi.dll" Alias "Window_GetTID" (ByVal hWin As Long) As Long
Declare Function Window_GetPath Lib "xyapi.dll" Alias "Window_GetPath" (ByVal hWin As Long) As ASCIIZ
Declare Function Window_FormPoint Lib "xyapi.dll" Alias "Window_FormPoint" (ByVal x As Long, ByVal y As Long) As Long
Declare Function Window_FormMouse Lib "xyapi.dll" Alias "Window_FormMouse" () As Long
Declare Function Window_ConvS2C Lib "xyapi.dll" Alias "Window_ConvS2C" (ByVal hWin As Long, ByVal x As Long, ByVal y As Long) As Long
Declare Function Window_ConvC2S Lib "xyapi.dll" Alias "Window_ConvC2S" (ByVal hWin As Long, ByVal x As Long, ByVal y As Long) As Long
Declare Function Window_GetRect Lib "xyapi.dll" Alias "Window_GetRect" (ByVal hWin As Long) As Long

Declare Function Process_List Lib "xyapi.dll" Alias "Process_List" () As ASCIIZ
Declare Function Process_FindChild Lib "xyapi.dll" Alias "Process_FindChild" (ByVal pHdr As Long) As Long
Declare Function Process_ListChild Lib "xyapi.dll" Alias "Process_ListChild" (ByVal pHdr As Long) As ASCIIZ
Declare Function PID_FindChild Lib "xyapi.dll" Alias "PID_FindChild" (ByVal pid As Long) As Long
Declare Function PID_ListChild Lib "xyapi.dll" Alias "PID_ListChild" (ByVal pid As Long) As ASCIIZ

Declare Function Process_Is64 Lib "xyapi.dll" Alias "Process_Is64" (ByVal pHdr As Long) As Long
Declare Function Process_CmdLine Lib "xyapi.dll" Alias "Process_CmdLine" (ByVal pHdr As Long) As ASCIIZ
Declare Function Process_CurPath Lib "xyapi.dll" Alias "Process_CurPath" (ByVal pHdr As Long) As ASCIIZ
Declare Function Process_ImageName Lib "xyapi.dll" Alias "Process_ImageName" (ByVal pHdr As Long) As ASCIIZ
Declare Function Process_GetPath Lib "xyapi.dll" Alias "Process_GetPath" (ByVal pHdr As Long) As ASCIIZ
Declare Function Proecss_WorkMenory Lib "xyapi.dll" Alias "Proecss_WorkMenory" (ByVal pHdr As Long) As Long
Declare Function Proecss_PageMenory Lib "xyapi.dll" Alias "Proecss_PageMenory" (ByVal pHdr As Long) As Long
Declare Function Process_Parent Lib "xyapi.dll" Alias "Process_Parent" (ByVal pHdr As Long) As Long
Declare Function Process_H2ID Lib "xyapi.dll" Alias "Process_H2ID" (ByVal pHdr As Long) As Long
Declare Function Process_Status Lib "xyapi.dll" Alias "Process_Status" (ByVal pHdr As Long) As Long
Declare Function Process_Kill Lib "xyapi.dll" Alias "Process_Kill" (ByVal pHdr As Long) As Long
Declare Function Process_Pause Lib "xyapi.dll" Alias "Process_Pause" (ByVal pHdr As Long) As Long
Declare Function Process_Resume Lib "xyapi.dll" Alias "Process_Resume" (ByVal pHdr As Long) As Long
Declare Function Process_InjectDll Lib "xyapi.dll" Alias "Process_InjectDll" (ByVal hProcess As Long, ByVal sDll As ASCIIZ) As Long

Declare Function PID_Is64 Lib "xyapi.dll" Alias "PID_Is64" (ByVal pid As Long) As Long
Declare Function PID_CmdLine Lib "xyapi.dll" Alias "PID_CmdLine" (ByVal pid As Long) As ASCIIZ
Declare Function PID_CurPath Lib "xyapi.dll" Alias "PID_CurPath" (ByVal pid As Long) As ASCIIZ
Declare Function PID_ImageName Lib "xyapi.dll" Alias "PID_ImageName" (ByVal pid As Long) As ASCIIZ
Declare Function PID_GetPath Lib "xyapi.dll" Alias "PID_GetPath" (ByVal pid As Long) As ASCIIZ
Declare Function PID_WorkMenory Lib "xyapi.dll" Alias "PID_WorkMenory" (ByVal pid As Long) As Long
Declare Function PID_PageMenory Lib "xyapi.dll" Alias "PID_PageMenory" (ByVal pid As Long) As Long
Declare Function PID_Parent Lib "xyapi.dll" Alias "PID_Parent" (ByVal pid As Long) As Long
Declare Function PID_Status Lib "xyapi.dll" Alias "PID_Status" (ByVal pid As Long) As Long
Declare Function PID_Kill Lib "xyapi.dll" Alias "PID_Kill" (ByVal pid As Long) As Long
Declare Function PID_Pause Lib "xyapi.dll" Alias "PID_Pause" (ByVal pid As Long) As Long
Declare Function PID_Resume Lib "xyapi.dll" Alias "PID_Resume" (ByVal pid As Long) As Long
Declare Function PID_InjectDll Lib "xyapi.dll" Alias "PID_InjectDll" (ByVal pid As Long, ByVal sDll As ASCIIZ) As Long

Declare Function Network_LocalIP lib "xyapi.dll" Alias "Network_LocalIP" () As ASCIIZ
Declare Function Ping lib "xyapi.dll" Alias "Ping" (ByVal IP As ASCIIZ, ByVal ot As Long) As Long
Declare Function Ping_Port lib "xyapi.dll" Alias "Ping_Port" (ByVal IP As ASCIIZ, ByVal port As Long) As Long

Declare Sub Hook_InsKey_LowLevel Lib "xyapi.dll" Alias "Hook_InsKey_LowLevel" (ByVal EventProc As Long)
Declare Sub Hook_DelKey_LowLevel Lib "xyapi.dll" Alias "Hook_DelKey_LowLevel" ()
Declare Sub Hook_InsMouse_LowLevel Lib "xyapi.dll" Alias "Hook_InsMouse_LowLevel" (ByVal EventProc As Long)
Declare Sub Hook_DelMouse_LowLevel Lib "xyapi.dll" Alias "Hook_DelMouse_LowLevel" ()

Declare Function Spy_Create Lib "xyapi.dll" Alias "Spy_Create" (ByVal hParent As Long, ByVal x As Long, ByVal y As Long, ByVal Event_Over As Long, ByVal Event_Move As Long) As Long
Declare Sub Spy_Destroy Lib "xyapi.dll" Alias "Spy_Destroy" (ByVal hSpy As Long)
