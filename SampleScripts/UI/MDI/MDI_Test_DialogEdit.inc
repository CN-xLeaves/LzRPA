'-----------------------------------------------------------------
' Declared Functions
'-----------------------------------------------------------------
'Declare Function LoadCursor       Lib "USER32.DLL"  Alias "LoadCursorA"     (ByVal hInstance As DWord, lpCursorName As Asciiz) As Long
Declare Function MapWindowPoints  Lib "USER32.DLL"  Alias "MapWindowPoints" (ByVal hWndFrom As DWord, ByVal hWndTo As Long, lppt As Any, ByVal cPoints As Long) As Long
Declare Function RedrawWindow     Lib "USER32.DLL"  Alias "RedrawWindow"    (ByVal hWnd As DWord, lprcUpdate As RECT, ByVal hRgnUpdate As Long, ByVal fuRedraw As Long) As Long
