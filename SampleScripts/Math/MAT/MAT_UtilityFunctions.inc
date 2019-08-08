'------------------------------------------------------------
Sub MyMat_Print(ByRef Matrix() As Ext, Optional ByVal sComment As String, ByVal Looper As Long, ByVal tTime As Double)
'------------------------------------------------------------
  Local i, j As Long
  
  If UBound(Matrix) = 0 Then 
    PrintL "[" & sComment & "]" 
    PrintL "Matrix not yet dimensioned"
    PrintL
    Exit Sub
  End If      
  
  PrintL "[" & sComment & "]" & IIf$(Looper > 0, " [Time for " & Looper & " loops: " & Format$(tTime, "#0.0000") & " secs]", "")
  For i = 1 To UBound(Matrix, 1)      
               
    For j = 1 To UBound(Matrix, 2)
      Print Str$(Matrix(i,j))+$TAB
    Next
    PrintL

  Next
      
  PrintL
      
end sub