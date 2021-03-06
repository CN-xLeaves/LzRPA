' Windows Hello World
' with winmain message loop and wndproc
' Charles Pegge


#basic
#file "HelloWin1.exe"

type WNDCLASS
  ;40 bytes
  STYLE         as long
  lpfnwndproc   as long
  cbClsextra    as long
  cbWndExtra    as long
  hInstance     as long
  hIcon         as long
  hCursor       as long
  hbrBackground as long
  lpszMenuName  as long
  lpszClassName as long
end type

type point
  x as long
  y as long
end type

type MSG
  ; 28 bytes
  hwnd    as long
  message as long
  wParam  as long
  lParam  as long
  time    as long
  pt      as point
end type

  dim kernel32,user32,GDI32 as long
  kernel32=LoadLibrary `kernel32.dll`
  user32=LoadLibrary `user32.dll`
  GDI32=LoadLibrary `GDI32.dll`

  bind kernel32
  (
    GetCommandLine  GetCommandLineA   ; @0
    GetModuleHandle GetModuleHandleA  ; @4
    ExitProcess     ExitProcess       ; @4
  )


  bind user32
  (
    LoadIcon         LoadIconA         ; @8
    LoadCursor       LoadCursorA       ; @8
    RegisterClass    RegisterClassA    ; @4
    MessageBox       MessageBoxA       ; @4
    CreateWindowEx   CreateWindowExA   ; @48
    ShowWindow       ShowWindow        ; @8
    UpdateWindow     UpdateWindow      ; @4
    GetMessage       GetMessageA       ; @16
    TranslateMessage TranslateMessage  ; @4
    DispatchMessage  DispatchMessageA  ; @4
    PostQuitMessage  PostQuitMessage   ; @4
    BeginPaint       BeginPaint        ; @8
    EndPaint         EndPaint          ; @8
    GetClientRect    GetClientRect     ; @8  
    DrawText         DrawTextA         ; @20
    PostMessage      PostMessageA      ; @16
    DefWindowProc    DefWindowProcA    ; @16
  )


  bind GDI32
  (
    GetStockObject   GetStockObject    ; @4
  )







  declare Function WinMain(byval inst as long ,byval prevInst as long ,byval cmdline as asciiz , byval show as long) as long
  declare function WndProc(byval hWnd as long, byval wMsg as long, byval wParam as long, byval lparam as long) as long
                      '
  def SW_NORMAL 1
  def SW_SHOWDEFAULT 10



  ;=====================================
  dim byref cmdline as asciiz,inst as long

  &cmdline=GetCommandLine
  inst=GetModuleHandle 0
  'print cmdline ` 
  '` hex inst

  WinMain inst,0,cmdline,SW_NORMAL
  '
  ExitProcess
  freelibrary kernel32
  freelibrary user32
  freelibrary gdi32
  terminate

  'o2 !10 ; align 16 bytes 
  
  ;=====================================
 
  % CS_VREDRAW      1
  % CS_HREDRAW      2
  % IDI_APPLICATION 32512
  % IDC_ARROW       32512
  % WHITE_BRUSH     0
  % MB_ICONERROR    16

  def CW_USEDEFAULT       0x80000000
  def WS_OVERLAPPEDWINDOW 0x00cf0000


  '------------------------------------------------------------ 
  Function WinMain(byval inst as long ,byval prevInst as long,
  byval cmdline as asciiz , byval show as long) as long
  '===========================================================
                    '
  ; window handle
  
  dim a,b,c,hWnd as long
  dim wc as WndClass
  dim wm as MSG

  with wc.                 '
    style=CS_HREDRAW or CS_VREDRAW
    lpfnWndProc=&WndProc '#long#long#long#long
    cbClsExtra=0
    cbWndExtra=0    
    hInstance=inst
    hIcon=LoadIcon 0, IDI_APPLICATION
    hCursor=LoadCursor 0,IDC_ARROW
    hbrBackground=GetStockObject WHITE_BRUSH '
    lpszMenuName=0
    #view
    lpszClassName=`HelloWin`
    #endv
  end with

  if not RegisterClass &wc
    MessageBox 0,`Registration failed`,`Problem`,MB_ICONERROR
    exit function
  end if                  '

  hWnd=CreateWindowEx 0,wc.lpszClassName,`Hello Window`,
  WS_OVERLAPPEDWINDOW,
  CW_USEDEFAULT,CW_USEDEFAULT,640,480,
  0,0,inst,0
      
  if not hWnd then
    MessageBox 0,`Unable to create window`,`problem`,MB_ICONERROR
    exit function
  end if
                              '
  ShowWindow hWnd,show
  UpdateWindow hWnd
  ;
    
  
   
  ;MESSAGE LOOP
  ;
  do while GetMessage &wm,0,0,0
    TranslateMessage &wm
    DispatchMessage &wm
    '
    'select wm.hwnd
    'case hwnd
    '  if wm.message=256 then print `key down` : exit do
    'end select
    '
  wend
  ;
  function=wm.wparam

  end function ; end of WinMain


  type RECT
    ; 16 bytes
    left   as long
    top    as long
    right  as long
    bottom as long
  end type

  type rgbacolor
    red   as byte
    green as byte
    blue  as byte
    alpha as byte
  end type
  
  type PAINTSTRUCT
    ; 64 bytes
    hDC        as long
    fErase     as long
    rcPaint    as rect
    fRestore   as long
    fIncUpdate as long
    rgb        as rgbacolor
    Reserved   as 32
  end type

  % WM_CREATE     1
  % WM_DESTROY    2
  % WM_PAINT     15
  % WM_CLOSE     16
  % WM_KEYDOWN  256

  '-----------------------------------------
  function WndProc (  byval hWnd as long,
  byval wMsg as long, byval wParam as long,
  byval lparam as long ) as long callback
  '=========================================
  dim cRect   as rect
  dim Paintst as paintstruct
  dim hDC     as long
  
    select wMsg
        
      '--------------
      case WM_CREATE
      '=============
      
      '--------------  
      case WM_DESTROY
      '===============
          
        PostQuitMessage 0
        
      '------------
      case WM_PAINT
      '============
          
        hDC=BeginPaint hWnd,&Paintst
        GetClientRect  hWnd,&cRect
        ; style
        ; 0x20 DT_SINGLELINE
        ; 0x04 DT_VCENTER
        ; 0x01 DT_CENTER
        ; 0x25
        DrawText hDC,`Hello World!`,-1,&cRect,0x25
        EndPaint hWnd,&Paintst
        
      '--------------   
      case WM_KEYDOWN
      '==============
          
        if wParam=27 then
          PostMessage hWnd,WM_CLOSE,0,0
        end if

      '--------        
      case else
      '========
          
        function=DefWindowProc hWnd,wMsg,wParam,lParam
        
    end select

  end function ' WndProc

 