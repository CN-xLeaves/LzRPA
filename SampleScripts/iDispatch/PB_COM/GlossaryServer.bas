'==============================================================================
'
'  GlossaryServer.bas example for PowerBASIC For Windows Compiler
'  Copyright (c) 2008-2011 PowerBASIC, Inc.
'  All Rights Reserved.
'
'  Demonstrats the creation of a dual interface COM server
'
'  The server must first be registered before running the client applications.
'  To regerister the server use regsvr32 at the command prompt:
'    regsvr32 GlossaryServer.dll
'
'==============================================================================

#Compiler PBWin 10
#Compile Dll

#Resource TypeLib, 1, "GlossaryServer.tlb"

#Dim All

#Com TLib On
#Com Name "Glossary", 1.0
#Com Doc  "List of Glossary Terms and Definitions"


$CGlossaryGuid = Guid$("{40654F1A-99E3-436F-8F06-DA2ADCB6DFB4}")
$IGlossaryGuid = Guid$("{61884B28-0BFC-4B9E-940F-738377949A9D}")

Class CGlossary $CGlossaryGuid As Com
  Instance Glossary() As WString
  Instance Definitions() As WString

  Class Method Create

    ReDim Glossary(18) As Instance WString
    ReDim Definitions(18) As Instance WString

    Glossary(0)     = "Method"
    Definitions(0)  = "A subroutine, very similar to a user-defined Sub/Function. " + _
                      "A method has the special attribute that it can access the variables" + _
                      " stored in the object. A method can return a value like a Function," + _
                      " or return nothing, like a Sub."

    Glossary(1)     = "Property"
    Definitions(1)  = "This is a METHOD, but in a specific form, for a specific purpose. " + _
                      "A PROPERTY has all the attributes of a standard METHOD. It has a special" + _
                      " syntax, and is specifically used to read or write private data to/from" + _
                      " the internal variables in an object."

    Glossary(2)     = "Interface"
    Definitions(2)  = "A definition of a set of methods and properties which are implemented on" + _
                      "an object. You might think of it as a list of DECLARE statements where the" + _
                      " sequence of the Declares must be preserved."

    Glossary(3)     = "Class"
    Definitions(3)  = "A definition of a complete object, which may include one or more interfaces." + _
                      " This is the place where you declare INSTANCE variables, and write your code" + _
                      " for the enclosed METHOD and PROPERTY procedures."

    Glossary(4)     = "Class Method"
    Definitions(4)  = "This is a private method, which may only be called from within the same CLASS."

    Glossary(5)     = "Constructor"
    Definitions(5)  = "This is a special form of CLASS METHOD, which is executed automatically whenever" + _
                      " an object is created."

    Glossary(6)     = "Destructor"
    Definitions(6)  = "This is a special form of CLASS METHOD, which is executed automatically whenever" + _
                      " an object is destroyed."

    Glossary(7)     = "Object"
    Definitions(7)  = "An instance of a class. When you create an object in your running program, using" + _
                      " the LET (with objects) statement, or its implied form, PowerBASIC allocates a block" + _
                      " of memory for the set of instance variables you defined, and establishes a virtual" + _
                      " function table (a set of function code pointers) for each of the interfaces. " + _
                      "You can create any number of OBJECTS based upon one CLASS definition."

    Glossary(8)     = "Instance Data"
    Definitions(8)  = "Each CLASS defines some INSTANCE variables which are present in every object. " + _
                      "When you create multiple objects (of the same class), each object gets its own " + _
                      "unique copy of them. These variables are called INSTANCE variables because a " + _
                      "new set of them is created for each instance of the object."

    Glossary(9)     = "Virtual Function Table"
    Definitions(9)  = "Commonly called a VFT or VTBL, this is a set of function code pointers, one for " + _
                      "each METHOD or PROPERTY in an interface. This is a tool used internally to " + _
                      "direct program execution to the correct method or property you wish to execute."

    Glossary(10)    = "GUID"
    Definitions(10) = "This is a Globally Unique Identifier, a very large number which is used to uniquely" + _
                      " identify every interface, every class, and every COM application or library which " + _
                      "exists anywhere in the world."

    Glossary(11)    = "Direct Interface"
    Definitions(11) = "This is the most efficient form of interface. When you call a particular METHOD or " + _
                      "PROPERTY, the compiler simply performs an indirect jump to the correct entry point " + _
                      "listed in the virtual function table (VFT or VTBL). This is just as fast as calling" + _
                      " a standard Sub or Function, and is the default access method used by PowerBASIC."

    Glossary(12)    = "Dispatch Interface"
    Definitions(12) = "This is a slow form of interface, originally introduced as a part of Microsoft Visual" + _
                      " Basic. When you use DISPATCH, the compiler actually passes the name of the METHOD " + _
                      "you wish to execute as a text string. The parameters can also be passed in the same way." + _
                      " The object must then look up the names, and decide which METHOD to execute, and which " + _
                      "parameters to use, based upon the text  provided. This is a very slow process. Many " + _
                      "scripting languages still use DISPATCH as their sole method of operation, so continued " + _
                      "support is necessary."

    Glossary(13)    = "Dual Interface"
    Definitions(13) = "This is a combination of a Direct Interface and a Dispatch Interface. This most " + _
                      "flexible form allows either option to be used, depending upon how the calling " + _
                      "application is implemented."

    Glossary(14)    = "Automation"
    Definitions(14) = "This is a special calling convention, defined by MS later in the evolution of COM and " + _
                      "objects. An Automation object is simply one which adheres to the rules for Automation " + _
                      "COM Objects. It may offer just a direct interface, just a Dispatch interface, or both " + _
                      "of them (DUAL). It should be noted that some programmers use the word AUTOMATION to " + _
                      "mean DISPATCH. Even though that's not correct, you should keep the possibility in mind" + _
                      " whenever you encounter the term. Automation Methods must use parameters, return " + _
                      "values, and assignment variables which are AUTOMATION compatible: BYTE, WORD, DWORD, " + _
                      "INTEGER, LONG, QUAD, SINGLE, DOUBLE, CURRENCY, OBJECT, STRING, and VARIANT. All " + _
                      "Automation Methods return a hidden result code which is called the hResult. This is " + _
                      "not really a handle, as the name  suggests, but a result code to report the success " + _
                      "or failure of a call to a METHOD or PROPERTY."

    Glossary(15)    = "IUnknown"
    Definitions(15) = "This is the name of a special interface which is the basis for every object. It has " + _
                      "three methods, which are always defined as the first three methods in every interface." + _
                      " These 3 methods are used by compilers (PowerBASIC or others) to look up other interfaces " + _
                      "on the object, and to keep track of usage of this object. While IUNKNOWN is mandatory for " + _
                      "every object, you won't ever need to reference it directly. PowerBASIC handles all those " + _
                      "messy details automatically."

    Glossary(16)    = "Object Refrence"
    Definitions(16) = "This is a reference (a pointer) to an object, which is the only way objects are used. In " + _
                      "PowerBASIC, an object variable initially contains NOTHING. When you create an object, or " + _
                      "duplicate one, a reference to that object is placed in an object variable by the compiler." + _
                      " That is, a pointer to the object is automatically inserted in the object variable. It is " + _
                      "now considered to contain an OBJECT REFERENCE until such time as the reference is deleted " + _
                      "or set to NOTHING."

    Glossary(17)    = "Component"
    Definitions(17) = "An object that encapsulates code and data, providing a set of publicly available services."

    Glossary(18)    = "Moniker"
    Definitions(18) = "An object that implements the IMoniker interface. A moniker acts as a name that uniquely " + _
                      "identifies a COM object. In the same way that a path identifies a file in the file system," + _
                      " a moniker identifies a COM object in the directory namespace."

    Array Sort Glossary(), TagArray Definitions()

  End Method

  Interface IGlossary $IGlossaryGuid
    Inherit IDispatch

    Property Get Count <1> As Long
      Property = UBound(Glossary())
    End Property

    Property Get Definition <2> (ByVal w As WString) As WString
      Local i As Long

      Array Scan Glossary(), Collate UCase, =w, To i
      Decr i
      If i < 0 Then
        Property = "Undefined"
      Else
        Property = Definitions(i)
      End If
    End Property

    Property Get Terms <3> As WString
      Property = Join$(Glossary(), ",")
    End Property

  End Interface

End Class