
Oxygen Scripts which do not depend on the thinBasic runtime or additional modules can be compiled to EXE files.

thinBasic_Oxygen.dll is required so that these programs (EXE files) can access the Oxygen runtime library.

ThinBasic_Oxygen.dll may be located in the same folder as the EXE file or any folder specified in an oxygen.cfg file.
This file must be in the same folder as the EXE file.


Example oxygen.cfg

c:\thinbasic\lib\thinbasic_oxygen.dll
\thinbasic\lib\thinbasic_oxygen.dll




In the Oxygen script, use the #file command to specify the name of the EXE (or DLL) to be generated:

Example:

#file "HelloWin1.exe"

