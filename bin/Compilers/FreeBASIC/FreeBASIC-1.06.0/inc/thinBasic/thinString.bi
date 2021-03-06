﻿  #Include Once "win/ole2.bi"
  
  '---------------------------------------------------------------
    Type thinString
      ' Simple ANSI/BSTR type class to take a FreeBASIC string and create
      ' a ThinBASIC compatible string
      ' Takes an ANSI string as input, and returns a BSTR that contains an ANSI string. 
      ' Does not perform any ANSI-to-Unicode translation.

      Private:
        m_str As BSTR

      Public:
        Declare Constructor           (ByRef xStr As Const String = "")
        Declare Destructor            ()
        
        Declare Property    handle    () As BSTR
        Declare Property    handle    (ByVal bHandle As BSTR)
        
        Declare Property    text      () As String
        Declare Property    text      (ByRef xStr As Const String)
        
        Declare Operator    Let       (ByRef x As Const String)
        Declare Operator    Let       (ByVal bHandle As BSTR)

        Declare Function    sLen      () As long
        Declare Function    sLeft     (byval nBytes as long) As String
        Declare Function    sRight    (byval nBytes as long) As String
        Declare Function    sMid      (byval lStartByte as long, byval nBytes as long) As String

    End Type

  '---------------------------------------------------------------
  
    Constructor thinString(ByRef xStr As Const String)
      this.text = xStr
    End Constructor
    
    Destructor thinString()
      SysFreeString(m_str)
    End Destructor
    
    '---
    
    Property thinString.handle(ByVal bHandle As BSTR)
      this.m_str = bHandle
    End Property
    
    Property thinString.handle() As BSTR
      Property = this.m_str
    End Property
    
    '---
    
    Property thinString.text() As String
      DIM n1    AS long   = SysStringByteLen(this.m_str)
      Dim sTemp As String

      sTemp = Space(n1)
      memcpy(strptr(sTemp), m_str, n1)
      Property = sTemp
      
    End Property
    
    Property thinString.text(ByRef xStr As Const String)
      SysFreeString(m_str)
      m_str = SysAllocStringByteLen(xStr, Len(xStr))  ' creates an ANSI BSTR
    End Property
    
    '---
    
    Operator thinString.Let(ByRef rhs As Const String)
      this.text = rhs
    End Operator
    
    Operator thinString.Let(ByVal bHandle As BSTR)
      this.m_str = bHandle
    End Operator

    '---
    
    Function thinString.sLen() As Long
      Return SysStringByteLen(m_str)
    End Function

    '---

    Function thinString.sLeft(byval nBytes as long) As String
      return left(this.text, nBytes)
    End Function

    Function thinString.sRight(byval nBytes as long) As String
      return Right(this.text, nBytes)
    End Function

    Function thinString.sMid(byval lStartByte as long, byval nBytes as long) As String
      return Mid(this.text, lStartByte, nBytes)
    End Function

  '---------------------------------------------------------------
  



 