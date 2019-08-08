'------------------------------------------------------------------------------
'
'  sdkddkver.inc - Master include file for versioning windows SDK/DDK.
'
'  Copyright (c) 2009-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from sdkddkver.h dated 14 July 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%INC_SDKDDKVER = 1

' [target Win32 on x86 processors]
%WIN32 = 100
%M_IX86 = 600
%X86 = 1

' [Microsoft somehow leaves out defining this one, but it's needed]
%WIN32_WINDOWS = &H0601

' [some of the headers try to use this value without checking to see that it's
'  already defined, so we need to set it here]
#IF NOT %DEF(%ISOLATION_AWARE_ENABLED)
%ISOLATION_AWARE_ENABLED = 0
#ENDIF

'
' %WIN32_WINNT version constants
'
%WIN32_WINNT_NT4                  = &H0400
%WIN32_WINNT_WIN2K                = &H0500
%WIN32_WINNT_WINXP                = &H0501
%WIN32_WINNT_WS03                 = &H0502
%WIN32_WINNT_WIN6                 = &H0600
%WIN32_WINNT_VISTA                = &H0600
%WIN32_WINNT_WS08                 = &H0600
%WIN32_WINNT_LONGHORN             = &H0600
%WIN32_WINNT_WIN7                 = &H0601

'
' %WIN32_IE_ version constants
'
%WIN32_IE_IE20                    = &H0200
%WIN32_IE_IE30                    = &H0300
%WIN32_IE_IE302                   = &H0302
%WIN32_IE_IE40                    = &H0400
%WIN32_IE_IE401                   = &H0401
%WIN32_IE_IE50                    = &H0500
%WIN32_IE_IE501                   = &H0501
%WIN32_IE_IE55                    = &H0550
%WIN32_IE_IE60                    = &H0600
%WIN32_IE_IE60SP1                 = &H0601
%WIN32_IE_IE60SP2                 = &H0603
%WIN32_IE_IE70                    = &H0700
%WIN32_IE_IE80                    = &H0800

'
' IE <-> OS version mapping
'
' NT4 supports IE versions 2.0 -> 6.0 SP1
%WIN32_IE_NT4                     = %WIN32_IE_IE20
%WIN32_IE_NT4SP1                  = %WIN32_IE_IE20
%WIN32_IE_NT4SP2                  = %WIN32_IE_IE20
%WIN32_IE_NT4SP3                  = %WIN32_IE_IE302
%WIN32_IE_NT4SP4                  = %WIN32_IE_IE401
%WIN32_IE_NT4SP5                  = %WIN32_IE_IE401
%WIN32_IE_NT4SP6                  = %WIN32_IE_IE50
' Win98 supports IE versions 4.01 -> 6.0 SP1
%WIN32_IE_WIN98                   = %WIN32_IE_IE401
' Win98SE supports IE versions 5.0 -> 6.0 SP1
%WIN32_IE_WIN98SE                 = %WIN32_IE_IE50
' WinME supports IE versions 5.5 -> 6.0 SP1
%WIN32_IE_WINME                   = %WIN32_IE_IE55
' Win2k supports IE versions 5.01 -> 6.0 SP1
%WIN32_IE_WIN2K                   = %WIN32_IE_IE501
%WIN32_IE_WIN2KSP1                = %WIN32_IE_IE501
%WIN32_IE_WIN2KSP2                = %WIN32_IE_IE501
%WIN32_IE_WIN2KSP3                = %WIN32_IE_IE501
%WIN32_IE_WIN2KSP4                = %WIN32_IE_IE501
%WIN32_IE_XP                      = %WIN32_IE_IE60
%WIN32_IE_XPSP1                   = %WIN32_IE_IE60SP1
%WIN32_IE_XPSP2                   = %WIN32_IE_IE60SP2
%WIN32_IE_WS03                    = &H0602
%WIN32_IE_WS03SP1                 = %WIN32_IE_IE60SP2
%WIN32_IE_WIN6                    = %WIN32_IE_IE70
%WIN32_IE_LONGHORN                = %WIN32_IE_IE70
%WIN32_IE_WIN7                    = %WIN32_IE_IE80


'
' NTDDI version constants
'
%NTDDI_WIN2K                       = &H05000000
%NTDDI_WIN2KSP1                    = &H05000100
%NTDDI_WIN2KSP2                    = &H05000200
%NTDDI_WIN2KSP3                    = &H05000300
%NTDDI_WIN2KSP4                    = &H05000400

%NTDDI_WINXP                       = &H05010000
%NTDDI_WINXPSP1                    = &H05010100
%NTDDI_WINXPSP2                    = &H05010200
%NTDDI_WINXPSP3                    = &H05010300
%NTDDI_WINXPSP4                    = &H05010400

%NTDDI_WS03                        = &H05020000
%NTDDI_WS03SP1                     = &H05020100
%NTDDI_WS03SP2                     = &H05020200
%NTDDI_WS03SP3                     = &H05020300
%NTDDI_WS03SP4                     = &H05020400

%NTDDI_WIN6                        = &H06000000
%NTDDI_WIN6SP1                     = &H06000100
%NTDDI_WIN6SP2                     = &H06000200
%NTDDI_WIN6SP3                     = &H06000300
%NTDDI_WIN6SP4                     = &H06000400

%NTDDI_VISTA                       = %NTDDI_WIN6
%NTDDI_VISTASP1                    = %NTDDI_WIN6SP1
%NTDDI_VISTASP2                    = %NTDDI_WIN6SP2
%NTDDI_VISTASP3                    = %NTDDI_WIN6SP3
%NTDDI_VISTASP4                    = %NTDDI_WIN6SP4

%NTDDI_WS08                        = %NTDDI_WIN6SP1
%NTDDI_WS08SP2                     = %NTDDI_WIN6SP2
%NTDDI_WS08SP3                     = %NTDDI_WIN6SP3
%NTDDI_WS08SP4                     = %NTDDI_WIN6SP4

%NTDDI_LONGHORN = %NTDDI_VISTA
'[the APIs often make reference to the following equate, but it's never defined.]
'[assuming it used to be LongHorn]
%NTDDI_WINLH = %NTDDI_VISTA

%NTDDI_WIN7                        = &H06010000

'
' masks for version macros
'
%OSVERSION_MASK    = &HFFFF0000???
%SPVERSION_MASK    = &H0000FF00
%SUBVERSION_MASK   = &H000000FF


'
' macros to extract various version fields from the NTDDI version
'
MACRO OSVER(Version) =((Version)  AND %OSVERSION_MASK)
MACRO SPVER(Version) =(((Version) AND %SPVERSION_MASK) \ 256) '>> 8)
MACRO SUBVER(Version)=(((Version) AND %SUBVERSION_MASK))


#IF NOT %DEF(%NTDDI_VERSION)
    %NTDDI_VERSION = &H06010000
#ENDIF

#IF %DEF(%DECLSPEC_DEPRECATED_DDK)

  ' deprecate in 2k or later
  #IF (%NTDDI_VERSION >= %NTDDI_WIN2K)
    %DECLSPEC_DEPRECATED_DDK_WIN2K = %DECLSPEC_DEPRECATED_DDK
  #ELSE
    %DECLSPEC_DEPRECATED_DDK_WIN2K = 0
  #ENDIF

  ' deprecate in XP or later
  #IF (%NTDDI_VERSION >= %NTDDI_WINXP)
    %DECLSPEC_DEPRECATED_DDK_WINXP = %DECLSPEC_DEPRECATED_DDK
  #ELSE
    %DECLSPEC_DEPRECATED_DDK_WINXP = 0
  #ENDIF

  ' deprecate in WS03 or later
  #IF (%NTDDI_VERSION >= %NTDDI_WS03)
    %DECLSPEC_DEPRECATED_DDK_WIN2003 = %DECLSPEC_DEPRECATED_DDK
  #ELSE
    %DECLSPEC_DEPRECATED_DDK_WIN2003 = 0
  #ENDIF

  ' deprecate in WIN6 or later
  #IF (%NTDDI_VERSION >= %NTDDI_WIN6)
    %DECLSPEC_DEPRECATED_DDK_WIN6 = %DECLSPEC_DEPRECATED_DDK
  #ELSE
    %DECLSPEC_DEPRECATED_DDK_WIN6 = 0
  #ENDIF

  %DECLSPEC_DEPRECATED_DDK_LONGHORN = %DECLSPEC_DEPRECATED_DDK_WIN6

#ENDIF ' %DEF(%DECLSPEC_DEPRECATED_DDK)


'
' if versions aren't already defined, default to most current
'

'#define NTDDI_VERSION_FROM_WIN32_WINNT2(ver)    ver##0000
'#define NTDDI_VERSION_FROM_WIN32_WINNT(ver)     NTDDI_VERSION_FROM_WIN32_WINNT2(ver)

#IF NOT %DEF(%WIN32_WINNT) AND (NOT %DEF(%NTDDI_VERSION))
#IF NOT %DEF(%PSAPI_VERSION)
%PSAPI_VERSION = 1
#ENDIF
#ENDIF

#IF NOT %DEF(%WIN32_WINNT) AND (NOT %DEF(%CHICAGO))
  %WIN32_WINNT = &H0601
#ENDIF

#IF NOT %DEF(%WINVER)
  #IF %DEF(%WIN32_WINNT)
    ' set WINVER based on %WIN32_WINNT
    %WINVER        = %WIN32_WINNT
  #ELSE
    %WINVER        = &H0601
  #ENDIF
#ENDIF

#IF NOT %DEF(%WIN32_IE)
  #IF %DEF(%WIN32_WINNT)
    ' set %WIN32_IE based on %WIN32_WINNT
    #IF (%WIN32_WINNT <= %WIN32_WINNT_NT4)
      %WIN32_IE     = %WIN32_IE_IE50
    #ELSEIF (%WIN32_WINNT <= %WIN32_WINNT_WIN2K)
      %WIN32_IE     = %WIN32_IE_IE501
    #ELSEIF (%WIN32_WINNT <= %WIN32_WINNT_WINXP)
      %WIN32_IE     = %WIN32_IE_IE60
    #ELSEIF (%WIN32_WINNT <= %WIN32_WINNT_WS03)
      %WIN32_IE     = &H0602
    #ELSE
      %WIN32_IE     = &H0800
    #ENDIF
  #ELSE
    %WIN32_IE     = &H0800
  #ENDIF
#ENDIF

'
' Sanity check for compatible versions
'
#IF %DEF(%WIN32_WINNT) AND (NOT %DEF(%MIDL_PASS) AND (NOT %DEF(%RC_INVOKED)))

  #IF (%DEF(%WINVER) AND (%WINVER < &H0400) AND (%WIN32_WINNT > &H0400))
    #DEBUG PRINT "WINVER setting conflicts with %WIN32_WINNT setting"
    END
  #ENDIF

  #IF (((%OSVERSION_MASK AND %NTDDI_VERSION) = %NTDDI_WIN2K) AND (%WIN32_WINNT <> %WIN32_WINNT_WIN2K))
    #DEBUG PRINT "%NTDDI_VERSION setting conflicts with %WIN32_WINNT setting"
    END
  #ENDIF

  #IF (((%OSVERSION_MASK AND %NTDDI_VERSION) = %NTDDI_WINXP) AND (%WIN32_WINNT <> %WIN32_WINNT_WINXP))
    #DEBUG PRINT "%NTDDI_VERSION setting conflicts with %WIN32_WINNT setting"
    END
  #ENDIF

  #IF (((%OSVERSION_MASK AND %NTDDI_VERSION) = %NTDDI_WS03) AND (%WIN32_WINNT <> %WIN32_WINNT_WS03))
    #DEBUG PRINT "%NTDDI_VERSION setting conflicts with %WIN32_WINNT setting"
    END
  #ENDIF

  #IF (((%OSVERSION_MASK AND %NTDDI_VERSION) = %NTDDI_VISTA) AND (%WIN32_WINNT <> %WIN32_WINNT_VISTA))
    #DEBUG PRINT "%NTDDI_VERSION setting conflicts with %WIN32_WINNT setting"
    END
  #ENDIF

  #IF ((%WIN32_WINNT < %WIN32_WINNT_WIN2K) AND (%WIN32_IE > %WIN32_IE_IE60SP1))
    #DEBUG PRINT "%WIN32_WINNT settings conflicts with %WIN32_IE setting"
    END
  #ENDIF

#ENDIF  ' %DEF(%WIN32_WINNT) AND NOT %DEF(%MIDL_PASS) AND NOT %DEF(%WINRESRC)
