                       PowerBASIC Win32Api 4 File Set

                  Copyright (c) 2002-2011 PowerBASIC, Inc.
                            All Rights Reserved.




                                  Overview
                                  ========

The Win32Api 4 files are for use with the PowerBASIC Console Compiler 6.0 and
later, and the PowerBASIC For Windows Compiler 10.0 and later. Earlier
compilers are not supported.

The Win32Api file set is a translation of the Microsoft Windows SDK headers.
You may use and distribute these files freely, provided that you agree that
PowerBASIC and Microsoft have no warranty, obligation or liability for their
contents.

The Win32Api files provide definitions that let you access the Windows API, or
Applications Programming Interfaces. The files contain types, declares,
equates, macros and/or subs and functions that help your programs to interface
with the vast collection of DLL calls provided by Windows.

The DLL functionality provided by Windows is not documented here. You can find
an older version of the basic Windows API reference as a help file, available
from our web site or your compiler CD. The Win32.zip archive is about 8 Mb.

   http://www.powerbasic.com/files/pub/mstools/Win32.zip

If you do not install the help file to the default directory, you will need to
modify the "Windows SDK.PBKeys" text file in your compiler directory to point
to the correct location, so that the IDE knows where to find the file.

More recent documentation is available from Microsoft in the form of the MSDN
(MicroSoft Developer Network) CDs or directly online at Microsoft's web site.

Example code that makes use of the Windows APIs may be found in your Samples
folder, as well as on the PowerBASIC web site in the Source Code Forum and in
the Download area.

As large as it is, the Win32Api file set encompasses only a fraction of the
total functionality exported by Windows. If you find that you need access to
Windows APIs that have not been translated to the Win32Api set, let us know,
and we will add them as time allows. Please send email to:

   support@powerbasic.com

The Win32Api file set is updated regularly. The latest version may be found in
the Download section of the PowerBASIC web site.




                                   Remarks
                                   =======

The filenames used for these include files are the same as used by Microsoft,
only with an extension of ".inc" instead of ".h". So, if the Microsoft
documentation calls for "HtmlHelp.h", you would #include "HtmlHelp.inc".

The main include file is Win32Api.inc, which includes many other include files
for your convenience.

Windows version equates have been integrated into the declarations. Be sure to
set the appropriate equates for your target version of Windows. See the new
SdkDdkVer.inc file for available options.

Unicode declares and types have been added. Define %UNICODE before your
#includes to use the Unicode versions in preference to the default ANSI
versions. Both Unicode and ANSI versions are always declared, so you can call
them directly if you do not wish to rely on the default setting. For example:

  MessageBoxA : ANSI version of MessageBox

  MessageBoxW : Unicode version of MessageBox

  MessageBox  : translated to either MessageBoxA or MessageBoxW, depending on
                whether %UNICODE is defined.




                                Key File List
                                =============

 History.txt    history of Win32Api file changes, additions, etc.

 ReadMe.txt     overview of Win32Api files.

-------------

 Resource.h     resource definitions (used by .RC resource files)

-------------

 ComDlg32.inc   Common Dialog definitions.
                Choose Color, Find/Replace, Printer, Open File, Save File, etc.

 CommCtrl.inc   Common Control definitions. See also InitCtrl.inc.
                Calendar, Combo Box, List View, Tree View, Tool Bar, etc.

 DDT.inc        General Windows equates with no API declares.
                This is a reduced Win32Api.inc for use with DDT-style apps.

 PBForms.inc    Support macros for PowerBASIC Forms programs. Do not modify.

 SdkDdkVer.inc  Equates that define the target Windows version for your
                program.

 VBAPI32.inc    Visual Basic API.
                Functions for working with VB native strings and arrays.

 Win32Api.inc   General-purpose Windows API definitions.
                Provides access to a wide variety of Windows functionals.
