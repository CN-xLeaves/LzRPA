'------------------------------------------------------------------------------
'
'  WinNT.inc
'    This module defines the 32-BIT Windows types and constants that are
'    defined by NT, but exposed through the Win32 API.
'
'  Copyright (c) 2009-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 24 Mar 2011
'
'------------------------------------------------------------------------------
'  from WinNT.h build version 0091 of 14 Jul 2009
'------------------------------------------------------------------------------
'  NOTE: before including this file, use #INCLUDE "Win32Api.inc"
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WINNT = 1

%ANYSIZE_ARRAY = 1

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "BaseTSD.inc"
#INCLUDE "WinDef.inc"
#INCLUDE "NtStatus.inc"
#INCLUDE "WTypes.inc"


#IF NOT %DEF(%SYSTEM_CACHE_ALIGNMENT_SIZE)
#IF %DEF(%AMD64) OR %DEF(%X86)
%SYSTEM_CACHE_ALIGNMENT_SIZE = 64
#ELSE
%SYSTEM_CACHE_ALIGNMENT_SIZE = 128
#ENDIF
#ENDIF

#IF %WIN32_WINNT >= &H0600

'
'  UCS (Universal Character Set) types
'

MACRO UCSCHAR=DWORD

'
'  Even pre-Unicode agreement, UCS values are always in the
'  range U+00000000 to U+7FFFFFFF, so we'll pick an obvious
'  value.

%UCSCHAR_INVALID_CHARACTER = &Hffffffff

%MIN_UCSCHAR = 0

'
'  We'll assume here that the ISO-10646 / Unicode agreement
'  not to assign code points after U+0010FFFF holds so that
'  we do not have to have separate "UCSCHAR" and "UNICODECHAR"
'  types.
'

%MAX_UCSCHAR = &H0010FFFF

#ENDIF ' %WIN32_WINNT >= &H0600

%ALL_PROCESSOR_GROUPS = &Hffff??

'
' Structure to represent a system wide processor number. It contains a
' group number and relative processor number within the group.
'

TYPE PROCESSOR_NUMBER
    Group    AS WORD
    Number   AS BYTE
    Reserved AS BYTE
END TYPE

'
' Structure to represent a group-specific affinity, such as that of a
' thread.  Specifies the group number and the affinity within that group.
'

TYPE GROUP_AFFINITY
    Mask        AS KAFFINITY
    Group       AS WORD
    Reserved(2) AS WORD
END TYPE


' Component Object Model defines, and macros

'MACRO LCID=DWORD
'MACRO LANGID=WORD
%APPLICATION_ERROR_MASK       = &H20000000
%ERROR_SEVERITY_SUCCESS       = &H00000000
%ERROR_SEVERITY_INFORMATIONAL = &H40000000
%ERROR_SEVERITY_WARNING       = &H80000000
%ERROR_SEVERITY_ERROR         = &HC0000000

'
' M_IX86 included so that EM CONTEXT structure compiles with
' x86 programs. *** TBD should this be for all architectures?
'

'
' 16 byte aligned type for 128 bit floats
'

'
' For we define a 128 bit structure and use __declspec(align(16)) pragma to
' align to 128 bits.
'

TYPE FLOAT128
    LowPart  AS QUAD
    HighPart AS QUAD
END TYPE


%ULONGLONG = 1

%MAXLONGLONG = &H7fffffffffffffff

MACRO LONGLONG=QUAD
' [ULONGLONG should be unsigned, but we don't have a QWORD type]
MACRO ULONGLONG=QUAD

' Update Sequence Number

MACRO USN=QUAD

MACRO LARGE_INTEGER=QUAD
MACRO ULARGE_INTEGER=QUAD
'TYPE LARGE_INTEGER_type
'    LowPart  AS DWORD
'    HighPart AS LONG
'END TYPE
'
'UNION LARGE_INTEGER
'    LARGE_INTEGER_type
'    QuadPart AS LONGLONG
'END UNION
'
'TYPE ULARGE_INTEGER_type
'    LowPart  AS DWORD
'    HighPart AS LONG
'END TYPE
'
'UNION ULARGE_INTEGER
'    ULARGE_INTEGER_type
'    QuadPart AS LONGLONG
'END UNION

'
' Locally Unique Identifier
'

'TYPE LUID
'    LowPart  AS DWORD
'    HighPart AS LONG
'END TYPE
' [we'll substitute a QUAD]

'
' Define operations to logically shift an int64 by 0..31 bits and to multiply
' 32-bits by 32-bits to form a 64-bit product.
'
MACRO Int32x32To64(a,b)=((a)*(b))
MACRO UInt32x32To64(a,b)=((a)*(b))

MACRO FUNCTION Int64ShllMod32(a,b)
    MACROTEMP q
    LOCAL q AS QUAD
    q = a
    SHIFT LEFT q, b
END MACRO=q

MACRO FUNCTION Int64ShraMod32(a,b)
    MACROTEMP q
    LOCAL q AS QUAD
    q = a
    SHIFT SIGNED RIGHT q, b
END MACRO=q

MACRO FUNCTION Int64ShrlMod32(a,b)
    MACROTEMP q
    LOCAL q AS QUAD
    q = a
    SHIFT RIGHT q, b
END MACRO=q

%ANSI_NULL = 0
$ANSI_NULL = $NUL
%UNICODE_NULL = 0
$$UNICODE_NULL = $$NUL
%UNICODE_STRING_MAX_BYTES = 65534
%UNICODE_STRING_MAX_CHARS = 32767

'MACRO BOOLEAN=BYTE
'
'  Doubly linked list structure.  Can be used as either a list head, or
'  as link words.
'

TYPE LIST_ENTRY
    Flink AS LIST_ENTRY PTR
    Blink AS LIST_ENTRY PTR
END TYPE

'
'  Singly linked list structure. Can be used as either a list head, or
'  as link words.
'

TYPE SINGLE_LIST_ENTRY
    sNext AS SINGLE_LIST_ENTRY PTR
END TYPE

'
' These are needed for portable debugger support.
'

TYPE LIST_ENTRY32
    Flink AS DWORD
    Blink AS DWORD
END TYPE

TYPE LIST_ENTRY64
    Flink AS QUAD
    Blink AS QUAD
END TYPE


'#INCLUDE "guiddef.inc"

#IF NOT %DEF(%OBJECTID_DEFINED)

%OBJECTID_DEFINED = 1

TYPE OBJECTID      ' size is 20
    Lineage    AS GUID
    Uniquifier AS DWORD
END TYPE

#ENDIF ' !_OBJECTID_DEFINED

%MINCHAR   = &H80?
%MAXCHAR   = &H7f
%MINSHORT  = &H8000??
%MAXSHORT  = &H7fff
%MINLONG   = &H80000000
%MAXLONG   = &H7fffffff
%MAXBYTE   = &Hff?
%MAXWORD   = &Hffff??
%MAXDWORD  = &Hffffffff

'
' Exception handler routine definition.
'

#INCLUDE "excpt.inc"

%EXCEPTION_NONCONTINUABLE     = &H1 ' Noncontinuable exception
%EXCEPTION_MAXIMUM_PARAMETERS = 15  ' maximum number of exception parameters

%VER_SERVER_NT                      = &H80000000
%VER_WORKSTATION_NT                 = &H40000000
%VER_SUITE_SMALLBUSINESS            = &H00000001
%VER_SUITE_ENTERPRISE               = &H00000002
%VER_SUITE_BACKOFFICE               = &H00000004
%VER_SUITE_COMMUNICATIONS           = &H00000008
%VER_SUITE_TERMINAL                 = &H00000010
%VER_SUITE_SMALLBUSINESS_RESTRICTED = &H00000020
%VER_SUITE_EMBEDDEDNT               = &H00000040
%VER_SUITE_DATACENTER               = &H00000080
%VER_SUITE_SINGLEUSERTS             = &H00000100
%VER_SUITE_PERSONAL                 = &H00000200
%VER_SUITE_BLADE                    = &H00000400
%VER_SUITE_EMBEDDED_RESTRICTED      = &H00000800
%VER_SUITE_SECURITY_APPLIANCE       = &H00001000
%VER_SUITE_STORAGE_SERVER           = &H00002000
%VER_SUITE_COMPUTE_SERVER           = &H00004000
%VER_SUITE_WH_SERVER                = &H00008000


'
' Product types
' This list grows with each OS release.
'
' There is no ordering of values to ensure callers
' do an equality test i.e. greater-than and less-than
' comparisons are not useful.
'
' NOTE: Values in this list should never be deleted.
'       When a product-type 'X' gets dropped from a
'       OS release onwards, the value of 'X' continues
'       to be used in the mapping table of GetProductInfo.
'

%PRODUCT_UNDEFINED                         = &H00000000

%PRODUCT_ULTIMATE                          = &H00000001
%PRODUCT_HOME_BASIC                        = &H00000002
%PRODUCT_HOME_PREMIUM                      = &H00000003
%PRODUCT_ENTERPRISE                        = &H00000004
%PRODUCT_HOME_BASIC_N                      = &H00000005
%PRODUCT_BUSINESS                          = &H00000006
%PRODUCT_STANDARD_SERVER                   = &H00000007
%PRODUCT_DATACENTER_SERVER                 = &H00000008
%PRODUCT_SMALLBUSINESS_SERVER              = &H00000009
%PRODUCT_ENTERPRISE_SERVER                 = &H0000000A
%PRODUCT_STARTER                           = &H0000000B
%PRODUCT_DATACENTER_SERVER_CORE            = &H0000000C
%PRODUCT_STANDARD_SERVER_CORE              = &H0000000D
%PRODUCT_ENTERPRISE_SERVER_CORE            = &H0000000E
%PRODUCT_ENTERPRISE_SERVER_IA64            = &H0000000F
%PRODUCT_BUSINESS_N                        = &H00000010
%PRODUCT_WEB_SERVER                        = &H00000011
%PRODUCT_CLUSTER_SERVER                    = &H00000012
%PRODUCT_HOME_SERVER                       = &H00000013
%PRODUCT_STORAGE_EXPRESS_SERVER            = &H00000014
%PRODUCT_STORAGE_STANDARD_SERVER           = &H00000015
%PRODUCT_STORAGE_WORKGROUP_SERVER          = &H00000016
%PRODUCT_STORAGE_ENTERPRISE_SERVER         = &H00000017
%PRODUCT_SERVER_FOR_SMALLBUSINESS          = &H00000018
%PRODUCT_SMALLBUSINESS_SERVER_PREMIUM      = &H00000019
%PRODUCT_HOME_PREMIUM_N                    = &H0000001A
%PRODUCT_ENTERPRISE_N                      = &H0000001B
%PRODUCT_ULTIMATE_N                        = &H0000001C
%PRODUCT_WEB_SERVER_CORE                   = &H0000001D
%PRODUCT_MEDIUMBUSINESS_SERVER_MANAGEMENT  = &H0000001E
%PRODUCT_MEDIUMBUSINESS_SERVER_SECURITY    = &H0000001F
%PRODUCT_MEDIUMBUSINESS_SERVER_MESSAGING   = &H00000020
'%PRODUCT_SMALLBUSINESS_SERVER_PRIME        = &H00000021
%PRODUCT_SERVER_FOUNDATION                 = &H00000021
%PRODUCT_HOME_PREMIUM_SERVER               = &H00000022
%PRODUCT_SERVER_FOR_SMALLBUSINESS_V        = &H00000023
%PRODUCT_STANDARD_SERVER_V                 = &H00000024
%PRODUCT_DATACENTER_SERVER_V               = &H00000025
%PRODUCT_ENTERPRISE_SERVER_V               = &H00000026
%PRODUCT_DATACENTER_SERVER_CORE_V          = &H00000027
%PRODUCT_STANDARD_SERVER_CORE_V            = &H00000028
%PRODUCT_ENTERPRISE_SERVER_CORE_V          = &H00000029
%PRODUCT_HYPERV                            = &H0000002A
%PRODUCT_STORAGE_EXPRESS_SERVER_CORE       = &H0000002B
%PRODUCT_STORAGE_STANDARD_SERVER_CORE      = &H0000002C
%PRODUCT_STORAGE_WORKGROUP_SERVER_CORE     = &H0000002D
%PRODUCT_STORAGE_ENTERPRISE_SERVER_CORE    = &H0000002E
%PRODUCT_STARTER_N                         = &H0000002F
%PRODUCT_PROFESSIONAL                      = &H00000030
%PRODUCT_PROFESSIONAL_N                    = &H00000031
%PRODUCT_SB_SOLUTION_SERVER                = &H00000032
%PRODUCT_SERVER_FOR_SB_SOLUTIONS           = &H00000033
%PRODUCT_STANDARD_SERVER_SOLUTIONS         = &H00000034
%PRODUCT_STANDARD_SERVER_SOLUTIONS_CORE    = &H00000035
%PRODUCT_SB_SOLUTION_SERVER_EM             = &H00000036
%PRODUCT_SERVER_FOR_SB_SOLUTIONS_EM        = &H00000037
%PRODUCT_SOLUTION_EMBEDDEDSERVER           = &H00000038
%PRODUCT_SOLUTION_EMBEDDEDSERVER_CORE      = &H00000039
%PRODUCT_SMALLBUSINESS_SERVER_PREMIUM_CORE = &H0000003F
%PRODUCT_ESSENTIALBUSINESS_SERVER_MGMT     = &H0000003B
%PRODUCT_ESSENTIALBUSINESS_SERVER_ADDL     = &H0000003C
%PRODUCT_ESSENTIALBUSINESS_SERVER_MGMTSVC  = &H0000003D
%PRODUCT_ESSENTIALBUSINESS_SERVER_ADDLSVC  = &H0000003E
%PRODUCT_CLUSTER_SERVER_V                  = &H00000040
%PRODUCT_EMBEDDED                          = &H00000041
%PRODUCT_STARTER_E                         = &H00000042
%PRODUCT_HOME_BASIC_E                      = &H00000043
%PRODUCT_HOME_PREMIUM_E                    = &H00000044
%PRODUCT_PROFESSIONAL_E                    = &H00000045
%PRODUCT_ENTERPRISE_E                      = &H00000046
%PRODUCT_ULTIMATE_E                        = &H00000047

%PRODUCT_UNLICENSED                        = &HABCDABCD

'
'  Language IDs.
'
'  Note that the named locale APIs (eg GetLocaleInfoEx) are preferred.
'
'  Not all locales have unique Language IDs
'
'  The following two combinations of primary language ID and
'  sublanguage ID have special semantics:
'
'    Primary Language ID   Sublanguage ID      Result
'    -------------------   ---------------     ------------------------
'    LANG_NEUTRAL          SUBLANG_NEUTRAL     Language neutral
'    LANG_NEUTRAL          SUBLANG_DEFAULT     User default language
'    LANG_NEUTRAL          SUBLANG_SYS_DEFAULT System default language
'    LANG_INVARIANT        SUBLANG_NEUTRAL     Invariant locale
'
'  It is recommended that applications test for locale names instead of
'  Language IDs / LCIDs.

'
'  Primary language IDs.
'
'  WARNING: These aren't always unique.  Bosnian, Serbian & Croation for example.
'
'  It is recommended that applications test for locale names or actual LCIDs.
'
'  Note that the LANG, SUBLANG construction is not always consistent.
'  The named locale APIs (eg GetLocaleInfoEx) are recommended.
'
%LANG_NEUTRAL              =      &H00
%LANG_INVARIANT            =      &H7f

%LANG_AFRIKAANS            =      &H36
%LANG_ALBANIAN             =      &H1c
%LANG_ALSATIAN             =      &H84?
%LANG_AMHARIC              =      &H5e
%LANG_ARABIC               =      &H01
%LANG_ARMENIAN             =      &H2b
%LANG_ASSAMESE             =      &H4d
%LANG_AZERI                =      &H2c
%LANG_BASHKIR              =      &H6d
%LANG_BASQUE               =      &H2d
%LANG_BELARUSIAN           =      &H23
%LANG_BENGALI              =      &H45
%LANG_BRETON               =      &H7e
%LANG_BOSNIAN              =      &H1a   ' Use with SUBLANG_BOSNIAN_* Sublanguage IDs
%LANG_BOSNIAN_NEUTRAL      =    &H781a   ' Use with the ConvertDefaultLocale function
%LANG_BULGARIAN            =      &H02
%LANG_CATALAN              =      &H03
%LANG_CHINESE              =      &H04   ' Use with SUBLANG_CHINESE_* Sublanguage IDs
%LANG_CHINESE_SIMPLIFIED   =      &H04   ' Use with the ConvertDefaultLocale function
%LANG_CHINESE_TRADITIONAL  =    &H7c04   ' Use with the ConvertDefaultLocale function
%LANG_CORSICAN             =      &H83?
%LANG_CROATIAN             =      &H1a
%LANG_CZECH                =      &H05
%LANG_DANISH               =      &H06
%LANG_DARI                 =      &H8c?
%LANG_DIVEHI               =      &H65
%LANG_DUTCH                =      &H13
%LANG_ENGLISH              =      &H09
%LANG_ESTONIAN             =      &H25
%LANG_FAEROESE             =      &H38
%LANG_FARSI                =      &H29   ' Deprecated: use LANG_PERSIAN instead
%LANG_FILIPINO             =      &H64
%LANG_FINNISH              =      &H0b
%LANG_FRENCH               =      &H0c
%LANG_FRISIAN              =      &H62
%LANG_GALICIAN             =      &H56
%LANG_GEORGIAN             =      &H37
%LANG_GERMAN               =      &H07
%LANG_GREEK                =      &H08
%LANG_GREENLANDIC          =      &H6f
%LANG_GUJARATI             =      &H47
%LANG_HAUSA                =      &H68
%LANG_HEBREW               =      &H0d
%LANG_HINDI                =      &H39
%LANG_HUNGARIAN            =      &H0e
%LANG_ICELANDIC            =      &H0f
%LANG_IGBO                 =      &H70
%LANG_INDONESIAN           =      &H21
%LANG_INUKTITUT            =      &H5d
%LANG_IRISH                =      &H3c   ' Use with the SUBLANG_IRISH_IRELAND Sublanguage ID
%LANG_ITALIAN              =      &H10
%LANG_JAPANESE             =      &H11
%LANG_KANNADA              =      &H4b
%LANG_KASHMIRI             =      &H60
%LANG_KAZAK                =      &H3f
%LANG_KHMER                =      &H53
%LANG_KICHE                =      &H86?
%LANG_KINYARWANDA          =      &H87?
%LANG_KONKANI              =      &H57
%LANG_KOREAN               =      &H12
%LANG_KYRGYZ               =      &H40
%LANG_LAO                  =      &H54
%LANG_LATVIAN              =      &H26
%LANG_LITHUANIAN           =      &H27
%LANG_LOWER_SORBIAN        =      &H2e
%LANG_LUXEMBOURGISH        =      &H6e
%LANG_MACEDONIAN           =      &H2f   ' the Former Yugoslav Republic of Macedonia
%LANG_MALAY                =      &H3e
%LANG_MALAYALAM            =      &H4c
%LANG_MALTESE              =      &H3a
%LANG_MANIPURI             =      &H58
%LANG_MAORI                =      &H81?
%LANG_MAPUDUNGUN           =      &H7a
%LANG_MARATHI              =      &H4e
%LANG_MOHAWK               =      &H7c
%LANG_MONGOLIAN            =      &H50
%LANG_NEPALI               =      &H61
%LANG_NORWEGIAN            =      &H14
%LANG_OCCITAN              =      &H82?
%LANG_ORIYA                =      &H48
%LANG_PASHTO               =      &H63
%LANG_PERSIAN              =      &H29
%LANG_POLISH               =      &H15
%LANG_PORTUGUESE           =      &H16
%LANG_PUNJABI              =      &H46
%LANG_QUECHUA              =      &H6b
%LANG_ROMANIAN             =      &H18
%LANG_ROMANSH              =      &H17
%LANG_RUSSIAN              =      &H19
%LANG_SAMI                 =      &H3b
%LANG_SANSKRIT             =      &H4f
%LANG_SCOTTISH_GAELIC      =      &H91?
%LANG_SERBIAN              =      &H1a   ' Use with the SUBLANG_SERBIAN_* Sublanguage IDs
%LANG_SERBIAN_NEUTRAL      =    &H7c1a   ' Use with the ConvertDefaultLocale function
%LANG_SINDHI               =      &H59
%LANG_SINHALESE            =      &H5b
%LANG_SLOVAK               =      &H1b
%LANG_SLOVENIAN            =      &H24
%LANG_SOTHO                =      &H6c
%LANG_SPANISH              =      &H0a
%LANG_SWAHILI              =      &H41
%LANG_SWEDISH              =      &H1d
%LANG_SYRIAC               =      &H5a
%LANG_TAJIK                =      &H28
%LANG_TAMAZIGHT            =      &H5f
%LANG_TAMIL                =      &H49
%LANG_TATAR                =      &H44
%LANG_TELUGU               =      &H4a
%LANG_THAI                 =      &H1e
%LANG_TIBETAN              =      &H51
%LANG_TIGRIGNA             =      &H73
%LANG_TSWANA               =      &H32
%LANG_TURKISH              =      &H1f
%LANG_TURKMEN              =      &H42
%LANG_UIGHUR               =      &H80?
%LANG_UKRAINIAN            =      &H22
%LANG_UPPER_SORBIAN        =      &H2e
%LANG_URDU                 =      &H20
%LANG_UZBEK                =      &H43
%LANG_VIETNAMESE           =      &H2a
%LANG_WELSH                =      &H52
%LANG_WOLOF                =      &H88?
%LANG_XHOSA                =      &H34
%LANG_YAKUT                =      &H85?
%LANG_YI                   =      &H78
%LANG_YORUBA               =      &H6a
%LANG_ZULU                 =      &H35

'
'  Sublanguage IDs.
'
'  The name immediately following SUBLANG_ dictates which primary
'  language ID that sublanguage ID can be combined with to form a
'  valid language ID.
'
'  Note that the LANG, SUBLANG construction is not always consistent.
'  The named locale APIs (eg GetLocaleInfoEx) are recommended.
'

%SUBLANG_NEUTRAL                             = &H00    ' language neutral
%SUBLANG_DEFAULT                             = &H01    ' user default
%SUBLANG_SYS_DEFAULT                         = &H02    ' system default
%SUBLANG_CUSTOM_DEFAULT                      = &H03    ' default custom language/locale
%SUBLANG_CUSTOM_UNSPECIFIED                  = &H04    ' custom language/locale
%SUBLANG_UI_CUSTOM_DEFAULT                   = &H05    ' Default custom MUI language/locale


%SUBLANG_AFRIKAANS_SOUTH_AFRICA              = &H01    ' Afrikaans (South Africa) &H0436 af-ZA
%SUBLANG_ALBANIAN_ALBANIA                    = &H01    ' Albanian (Albania) &H041c sq-AL
%SUBLANG_ALSATIAN_FRANCE                     = &H01    ' Alsatian (France) &H0484
%SUBLANG_AMHARIC_ETHIOPIA                    = &H01    ' Amharic (Ethiopia) &H045e
%SUBLANG_ARABIC_SAUDI_ARABIA                 = &H01    ' Arabic (Saudi Arabia)
%SUBLANG_ARABIC_IRAQ                         = &H02    ' Arabic (Iraq)
%SUBLANG_ARABIC_EGYPT                        = &H03    ' Arabic (Egypt)
%SUBLANG_ARABIC_LIBYA                        = &H04    ' Arabic (Libya)
%SUBLANG_ARABIC_ALGERIA                      = &H05    ' Arabic (Algeria)
%SUBLANG_ARABIC_MOROCCO                      = &H06    ' Arabic (Morocco)
%SUBLANG_ARABIC_TUNISIA                      = &H07    ' Arabic (Tunisia)
%SUBLANG_ARABIC_OMAN                         = &H08    ' Arabic (Oman)
%SUBLANG_ARABIC_YEMEN                        = &H09    ' Arabic (Yemen)
%SUBLANG_ARABIC_SYRIA                        = &H0a    ' Arabic (Syria)
%SUBLANG_ARABIC_JORDAN                       = &H0b    ' Arabic (Jordan)
%SUBLANG_ARABIC_LEBANON                      = &H0c    ' Arabic (Lebanon)
%SUBLANG_ARABIC_KUWAIT                       = &H0d    ' Arabic (Kuwait)
%SUBLANG_ARABIC_UAE                          = &H0e    ' Arabic (U.A.E)
%SUBLANG_ARABIC_BAHRAIN                      = &H0f    ' Arabic (Bahrain)
%SUBLANG_ARABIC_QATAR                        = &H10    ' Arabic (Qatar)
%SUBLANG_ARMENIAN_ARMENIA                    = &H01    ' Armenian (Armenia) &H042b hy-AM
%SUBLANG_ASSAMESE_INDIA                      = &H01    ' Assamese (India) &H044d
%SUBLANG_AZERI_LATIN                         = &H01    ' Azeri (Latin)
%SUBLANG_AZERI_CYRILLIC                      = &H02    ' Azeri (Cyrillic)
%SUBLANG_BASHKIR_RUSSIA                      = &H01    ' Bashkir (Russia) &H046d ba-RU
%SUBLANG_BASQUE_BASQUE                       = &H01    ' Basque (Basque) &H042d eu-ES
%SUBLANG_BELARUSIAN_BELARUS                  = &H01    ' Belarusian (Belarus) &H0423 be-BY
%SUBLANG_BENGALI_INDIA                       = &H01    ' Bengali (India)
%SUBLANG_BENGALI_BANGLADESH                  = &H02    ' Bengali (Bangladesh)
%SUBLANG_BOSNIAN_BOSNIA_HERZEGOVINA_LATIN    = &H05    ' Bosnian (Bosnia and Herzegovina - Latin) &H141a bs-BA-Latn
%SUBLANG_BOSNIAN_BOSNIA_HERZEGOVINA_CYRILLIC = &H08    ' Bosnian (Bosnia and Herzegovina - Cyrillic) &H201a bs-BA-Cyrl
%SUBLANG_BRETON_FRANCE                       = &H01    ' Breton (France) &H047e
%SUBLANG_BULGARIAN_BULGARIA                  = &H01    ' Bulgarian (Bulgaria) &H0402
%SUBLANG_CATALAN_CATALAN                     = &H01    ' Catalan (Catalan) &H0403
%SUBLANG_CHINESE_TRADITIONAL                 = &H01    ' Chinese (Taiwan) &H0404 zh-TW
%SUBLANG_CHINESE_SIMPLIFIED                  = &H02    ' Chinese (PR China) &H0804 zh-CN
%SUBLANG_CHINESE_HONGKONG                    = &H03    ' Chinese (Hong Kong S.A.R., P.R.C.) &H0c04 zh-HK
%SUBLANG_CHINESE_SINGAPORE                   = &H04    ' Chinese (Singapore) &H1004 zh-SG
%SUBLANG_CHINESE_MACAU                       = &H05    ' Chinese (Macau S.A.R.) &H1404 zh-MO
%SUBLANG_CORSICAN_FRANCE                     = &H01    ' Corsican (France) &H0483
%SUBLANG_CZECH_CZECH_REPUBLIC                = &H01    ' Czech (Czech Republic) &H0405
%SUBLANG_CROATIAN_CROATIA                    = &H01    ' Croatian (Croatia)
%SUBLANG_CROATIAN_BOSNIA_HERZEGOVINA_LATIN   = &H04    ' Croatian (Bosnia and Herzegovina - Latin) &H101a hr-BA
%SUBLANG_DANISH_DENMARK                      = &H01    ' Danish (Denmark) &H0406
%SUBLANG_DARI_AFGHANISTAN                    = &H01    ' Dari (Afghanistan)
%SUBLANG_DIVEHI_MALDIVES                     = &H01    ' Divehi (Maldives) &H0465 div-MV
%SUBLANG_DUTCH                               = &H01    ' Dutch
%SUBLANG_DUTCH_BELGIAN                       = &H02    ' Dutch (Belgian)
%SUBLANG_ENGLISH_US                          = &H01    ' English (USA)
%SUBLANG_ENGLISH_UK                          = &H02    ' English (UK)
%SUBLANG_ENGLISH_AUS                         = &H03    ' English (Australian)
%SUBLANG_ENGLISH_CAN                         = &H04    ' English (Canadian)
%SUBLANG_ENGLISH_NZ                          = &H05    ' English (New Zealand)
%SUBLANG_ENGLISH_EIRE                        = &H06    ' English (Irish)
%SUBLANG_ENGLISH_SOUTH_AFRICA                = &H07    ' English (South Africa)
%SUBLANG_ENGLISH_JAMAICA                     = &H08    ' English (Jamaica)
%SUBLANG_ENGLISH_CARIBBEAN                   = &H09    ' English (Caribbean)
%SUBLANG_ENGLISH_BELIZE                      = &H0a    ' English (Belize)
%SUBLANG_ENGLISH_TRINIDAD                    = &H0b    ' English (Trinidad)
%SUBLANG_ENGLISH_ZIMBABWE                    = &H0c    ' English (Zimbabwe)
%SUBLANG_ENGLISH_PHILIPPINES                 = &H0d    ' English (Philippines)
%SUBLANG_ENGLISH_INDIA                       = &H10    ' English (India)
%SUBLANG_ENGLISH_MALAYSIA                    = &H11    ' English (Malaysia)
%SUBLANG_ENGLISH_SINGAPORE                   = &H12    ' English (Singapore)
%SUBLANG_ESTONIAN_ESTONIA                    = &H01    ' Estonian (Estonia) &H0425 et-EE
%SUBLANG_FAEROESE_FAROE_ISLANDS              = &H01    ' Faroese (Faroe Islands) &H0438 fo-FO
%SUBLANG_FILIPINO_PHILIPPINES                = &H01    ' Filipino (Philippines) &H0464 fil-PH
%SUBLANG_FINNISH_FINLAND                     = &H01    ' Finnish (Finland) &H040b
%SUBLANG_FRENCH                              = &H01    ' French
%SUBLANG_FRENCH_BELGIAN                      = &H02    ' French (Belgian)
%SUBLANG_FRENCH_CANADIAN                     = &H03    ' French (Canadian)
%SUBLANG_FRENCH_SWISS                        = &H04    ' French (Swiss)
%SUBLANG_FRENCH_LUXEMBOURG                   = &H05    ' French (Luxembourg)
%SUBLANG_FRENCH_MONACO                       = &H06    ' French (Monaco)
%SUBLANG_FRISIAN_NETHERLANDS                 = &H01    ' Frisian (Netherlands) &H0462 fy-NL
%SUBLANG_GALICIAN_GALICIAN                   = &H01    ' Galician (Galician) &H0456 gl-ES
%SUBLANG_GEORGIAN_GEORGIA                    = &H01    ' Georgian (Georgia) &H0437 ka-GE
%SUBLANG_GERMAN                              = &H01    ' German
%SUBLANG_GERMAN_SWISS                        = &H02    ' German (Swiss)
%SUBLANG_GERMAN_AUSTRIAN                     = &H03    ' German (Austrian)
%SUBLANG_GERMAN_LUXEMBOURG                   = &H04    ' German (Luxembourg)
%SUBLANG_GERMAN_LIECHTENSTEIN                = &H05    ' German (Liechtenstein)
%SUBLANG_GREEK_GREECE                        = &H01    ' Greek (Greece)
%SUBLANG_GREENLANDIC_GREENLAND               = &H01    ' Greenlandic (Greenland) &H046f kl-GL
%SUBLANG_GUJARATI_INDIA                      = &H01    ' Gujarati (India (Gujarati Script)) &H0447 gu-IN
%SUBLANG_HAUSA_NIGERIA_LATIN                 = &H01    ' Hausa (Latin, Nigeria) &H0468 ha-NG-Latn
%SUBLANG_HEBREW_ISRAEL                       = &H01    ' Hebrew (Israel) &H040d
%SUBLANG_HINDI_INDIA                         = &H01    ' Hindi (India) &H0439 hi-IN
%SUBLANG_HUNGARIAN_HUNGARY                   = &H01    ' Hungarian (Hungary) &H040e
%SUBLANG_ICELANDIC_ICELAND                   = &H01    ' Icelandic (Iceland) &H040f
%SUBLANG_IGBO_NIGERIA                        = &H01    ' Igbo (Nigeria) &H0470 ig-NG
%SUBLANG_INDONESIAN_INDONESIA                = &H01    ' Indonesian (Indonesia) &H0421 id-ID
%SUBLANG_INUKTITUT_CANADA                    = &H01    ' Inuktitut (Syllabics) (Canada) &H045d iu-CA-Cans
%SUBLANG_INUKTITUT_CANADA_LATIN              = &H02    ' Inuktitut (Canada - Latin)
%SUBLANG_IRISH_IRELAND                       = &H02    ' Irish (Ireland)
%SUBLANG_ITALIAN                             = &H01    ' Italian
%SUBLANG_ITALIAN_SWISS                       = &H02    ' Italian (Swiss)
%SUBLANG_JAPANESE_JAPAN                      = &H01    ' Japanese (Japan) &H0411
%SUBLANG_KANNADA_INDIA                       = &H01    ' Kannada (India (Kannada Script)) &H044b kn-IN
%SUBLANG_KASHMIRI_SASIA                      = &H02    ' Kashmiri (South Asia)
%SUBLANG_KASHMIRI_INDIA                      = &H02    ' For app compatibility only
%SUBLANG_KAZAK_KAZAKHSTAN                    = &H01    ' Kazakh (Kazakhstan) &H043f kk-KZ
%SUBLANG_KHMER_CAMBODIA                      = &H01    ' Khmer (Cambodia) &H0453 kh-KH
%SUBLANG_KICHE_GUATEMALA                     = &H01    ' K'iche (Guatemala)
%SUBLANG_KINYARWANDA_RWANDA                  = &H01    ' Kinyarwanda (Rwanda) &H0487 rw-RW
%SUBLANG_KONKANI_INDIA                       = &H01    ' Konkani (India) &H0457 kok-IN
%SUBLANG_KOREAN                              = &H01    ' Korean (Extended Wansung)
%SUBLANG_KYRGYZ_KYRGYZSTAN                   = &H01    ' Kyrgyz (Kyrgyzstan) &H0440 ky-KG
%SUBLANG_LAO_LAO                             = &H01    ' Lao (Lao PDR) &H0454 lo-LA
%SUBLANG_LATVIAN_LATVIA                      = &H01    ' Latvian (Latvia) &H0426 lv-LV
%SUBLANG_LITHUANIAN                          = &H01    ' Lithuanian
%SUBLANG_LOWER_SORBIAN_GERMANY               = &H02    ' Lower Sorbian (Germany) &H082e wee-DE
%SUBLANG_LUXEMBOURGISH_LUXEMBOURG            = &H01    ' Luxembourgish (Luxembourg) &H046e lb-LU
%SUBLANG_MACEDONIAN_MACEDONIA                = &H01    ' Macedonian (Macedonia (FYROM)) &H042f mk-MK
%SUBLANG_MALAY_MALAYSIA                      = &H01    ' Malay (Malaysia)
%SUBLANG_MALAY_BRUNEI_DARUSSALAM             = &H02    ' Malay (Brunei Darussalam)
%SUBLANG_MALAYALAM_INDIA                     = &H01    ' Malayalam (India (Malayalam Script) ) &H044c ml-IN
%SUBLANG_MALTESE_MALTA                       = &H01    ' Maltese (Malta) &H043a mt-MT
%SUBLANG_MAORI_NEW_ZEALAND                   = &H01    ' Maori (New Zealand) &H0481 mi-NZ
%SUBLANG_MAPUDUNGUN_CHILE                    = &H01    ' Mapudungun (Chile) &H047a arn-CL
%SUBLANG_MARATHI_INDIA                       = &H01    ' Marathi (India) &H044e mr-IN
%SUBLANG_MOHAWK_MOHAWK                       = &H01    ' Mohawk (Mohawk) &H047c moh-CA
%SUBLANG_MONGOLIAN_CYRILLIC_MONGOLIA         = &H01    ' Mongolian (Cyrillic, Mongolia)
%SUBLANG_MONGOLIAN_PRC                       = &H02    ' Mongolian (PRC)
%SUBLANG_NEPALI_INDIA                        = &H02    ' Nepali (India)
%SUBLANG_NEPALI_NEPAL                        = &H01    ' Nepali (Nepal) &H0461 ne-NP
%SUBLANG_NORWEGIAN_BOKMAL                    = &H01    ' Norwegian (Bokmal)
%SUBLANG_NORWEGIAN_NYNORSK                   = &H02    ' Norwegian (Nynorsk)
%SUBLANG_OCCITAN_FRANCE                      = &H01    ' Occitan (France) &H0482 oc-FR
%SUBLANG_ORIYA_INDIA                         = &H01    ' Oriya (India (Oriya Script)) &H0448 or-IN
%SUBLANG_PASHTO_AFGHANISTAN                  = &H01    ' Pashto (Afghanistan)
%SUBLANG_PERSIAN_IRAN                        = &H01    ' Persian (Iran) &H0429 fa-IR
%SUBLANG_POLISH_POLAND                       = &H01    ' Polish (Poland) &H0415
%SUBLANG_PORTUGUESE                          = &H02    ' Portuguese
%SUBLANG_PORTUGUESE_BRAZILIAN                = &H01    ' Portuguese (Brazilian)
%SUBLANG_PUNJABI_INDIA                       = &H01    ' Punjabi (India (Gurmukhi Script)) &H0446 pa-IN
%SUBLANG_QUECHUA_BOLIVIA                     = &H01    ' Quechua (Bolivia)
%SUBLANG_QUECHUA_ECUADOR                     = &H02    ' Quechua (Ecuador)
%SUBLANG_QUECHUA_PERU                        = &H03    ' Quechua (Peru)
%SUBLANG_ROMANIAN_ROMANIA                    = &H01    ' Romanian (Romania) &H0418
%SUBLANG_ROMANSH_SWITZERLAND                 = &H01    ' Romansh (Switzerland) &H0417 rm-CH
%SUBLANG_RUSSIAN_RUSSIA                      = &H01    ' Russian (Russia) &H0419
%SUBLANG_SAMI_NORTHERN_NORWAY                = &H01    ' Northern Sami (Norway)
%SUBLANG_SAMI_NORTHERN_SWEDEN                = &H02    ' Northern Sami (Sweden)
%SUBLANG_SAMI_NORTHERN_FINLAND               = &H03    ' Northern Sami (Finland)
%SUBLANG_SAMI_LULE_NORWAY                    = &H04    ' Lule Sami (Norway)
%SUBLANG_SAMI_LULE_SWEDEN                    = &H05    ' Lule Sami (Sweden)
%SUBLANG_SAMI_SOUTHERN_NORWAY                = &H06    ' Southern Sami (Norway)
%SUBLANG_SAMI_SOUTHERN_SWEDEN                = &H07    ' Southern Sami (Sweden)
%SUBLANG_SAMI_SKOLT_FINLAND                  = &H08    ' Skolt Sami (Finland)
%SUBLANG_SAMI_INARI_FINLAND                  = &H09    ' Inari Sami (Finland)
%SUBLANG_SANSKRIT_INDIA                      = &H01    ' Sanskrit (India) &H044f sa-IN
%SUBLANG_SCOTTISH_GAELIC                     = &h01    ' Scottish Gaelic (United Kingdom) 0x0491 gd-GB
%SUBLANG_SERBIAN_BOSNIA_HERZEGOVINA_LATIN    = &H06    ' Serbian (Bosnia and Herzegovina - Latin)
%SUBLANG_SERBIAN_BOSNIA_HERZEGOVINA_CYRILLIC = &H07    ' Serbian (Bosnia and Herzegovina - Cyrillic)
%SUBLANG_SERBIAN_MONTENEGRO_LATIN            = &H0b    ' Serbian (Montenegro - Latn)
%SUBLANG_SERBIAN_MONTENEGRO_CYRILLIC         = &H0c    ' Serbian (Montenegro - Cyrillic)
%SUBLANG_SERBIAN_SERBIA_LATIN                = &H09    ' Serbian (Serbia - Latin)
%SUBLANG_SERBIAN_SERBIA_CYRILLIC             = &H0a    ' Serbian (Serbia - Cyrillic)
%SUBLANG_SERBIAN_CROATIA                     = &H01    ' Croatian (Croatia) &H041a hr-HR
%SUBLANG_SERBIAN_LATIN                       = &H02    ' Serbian (Latin)
%SUBLANG_SERBIAN_CYRILLIC                    = &H03    ' Serbian (Cyrillic)
%SUBLANG_SINDHI_INDIA                        = &H01    ' Sindhi (India) reserved &H0459
%SUBLANG_SINDHI_PAKISTAN                     = &H02    ' Sindhi (Pakistan) reserved &H0859
%SUBLANG_SINDHI_AFGHANISTAN                  = &H02    ' For app compatibility only
%SUBLANG_SINHALESE_SRI_LANKA                 = &H01    ' Sinhalese (Sri Lanka)
%SUBLANG_SOTHO_NORTHERN_SOUTH_AFRICA         = &H01    ' Northern Sotho (South Africa)
%SUBLANG_SLOVAK_SLOVAKIA                     = &H01    ' Slovak (Slovakia) &H041b sk-SK
%SUBLANG_SLOVENIAN_SLOVENIA                  = &H01    ' Slovenian (Slovenia) &H0424 sl-SI
%SUBLANG_SPANISH                             = &H01    ' Spanish (Castilian)
%SUBLANG_SPANISH_MEXICAN                     = &H02    ' Spanish (Mexican)
%SUBLANG_SPANISH_MODERN                      = &H03    ' Spanish (Modern)
%SUBLANG_SPANISH_GUATEMALA                   = &H04    ' Spanish (Guatemala)
%SUBLANG_SPANISH_COSTA_RICA                  = &H05    ' Spanish (Costa Rica)
%SUBLANG_SPANISH_PANAMA                      = &H06    ' Spanish (Panama)
%SUBLANG_SPANISH_DOMINICAN_REPUBLIC          = &H07    ' Spanish (Dominican Republic)
%SUBLANG_SPANISH_VENEZUELA                   = &H08    ' Spanish (Venezuela)
%SUBLANG_SPANISH_COLOMBIA                    = &H09    ' Spanish (Colombia)
%SUBLANG_SPANISH_PERU                        = &H0a    ' Spanish (Peru)
%SUBLANG_SPANISH_ARGENTINA                   = &H0b    ' Spanish (Argentina)
%SUBLANG_SPANISH_ECUADOR                     = &H0c    ' Spanish (Ecuador)
%SUBLANG_SPANISH_CHILE                       = &H0d    ' Spanish (Chile)
%SUBLANG_SPANISH_URUGUAY                     = &H0e    ' Spanish (Uruguay)
%SUBLANG_SPANISH_PARAGUAY                    = &H0f    ' Spanish (Paraguay)
%SUBLANG_SPANISH_BOLIVIA                     = &H10    ' Spanish (Bolivia)
%SUBLANG_SPANISH_EL_SALVADOR                 = &H11    ' Spanish (El Salvador)
%SUBLANG_SPANISH_HONDURAS                    = &H12    ' Spanish (Honduras)
%SUBLANG_SPANISH_NICARAGUA                   = &H13    ' Spanish (Nicaragua)
%SUBLANG_SPANISH_PUERTO_RICO                 = &H14    ' Spanish (Puerto Rico)
%SUBLANG_SPANISH_US                          = &H15    ' Spanish (United States)
%SUBLANG_SWAHILI_KENYA                       = &H01    ' Swahili (Kenya) &H0441 sw-KE
%SUBLANG_SWEDISH                             = &H01    ' Swedish
%SUBLANG_SWEDISH_FINLAND                     = &H02    ' Swedish (Finland)
%SUBLANG_SYRIAC_SYRIA                        = &H01    ' Syriac (Syria) &H045a syr-SY
%SUBLANG_TAJIK_TAJIKISTAN                    = &H01    ' Tajik (Tajikistan) &H0428 tg-TJ-Cyrl
%SUBLANG_TAMAZIGHT_ALGERIA_LATIN             = &H02    ' Tamazight (Latin, Algeria) &H085f tmz-DZ-Latn
%SUBLANG_TAMIL_INDIA                         = &H01    ' Tamil (India)
%SUBLANG_TATAR_RUSSIA                        = &H01    ' Tatar (Russia) &H0444 tt-RU
%SUBLANG_TELUGU_INDIA                        = &H01    ' Telugu (India (Telugu Script)) &H044a te-IN
%SUBLANG_THAI_THAILAND                       = &H01    ' Thai (Thailand) &H041e th-TH
%SUBLANG_TIBETAN_PRC                         = &H01    ' Tibetan (PRC)
%SUBLANG_TIGRIGNA_ERITREA                    = &H02    ' Tigrigna (Eritrea)
%SUBLANG_TSWANA_SOUTH_AFRICA                 = &H01    ' Setswana / Tswana (South Africa) &H0432 tn-ZA
%SUBLANG_TURKISH_TURKEY                      = &H01    ' Turkish (Turkey) &H041f tr-TR
%SUBLANG_TURKMEN_TURKMENISTAN                = &H01    ' Turkmen (Turkmenistan) &H0442 tk-TM
%SUBLANG_UIGHUR_PRC                          = &H01    ' Uighur (PRC) &H0480 ug-CN
%SUBLANG_UKRAINIAN_UKRAINE                   = &H01    ' Ukrainian (Ukraine) &H0422 uk-UA
%SUBLANG_UPPER_SORBIAN_GERMANY               = &H01    ' Upper Sorbian (Germany) &H042e wen-DE
%SUBLANG_URDU_PAKISTAN                       = &H01    ' Urdu (Pakistan)
%SUBLANG_URDU_INDIA                          = &H02    ' Urdu (India)
%SUBLANG_UZBEK_LATIN                         = &H01    ' Uzbek (Latin)
%SUBLANG_UZBEK_CYRILLIC                      = &H02    ' Uzbek (Cyrillic)
%SUBLANG_VIETNAMESE_VIETNAM                  = &H01    ' Vietnamese (Vietnam) &H042a vi-VN
%SUBLANG_WELSH_UNITED_KINGDOM                = &H01    ' Welsh (United Kingdom) &H0452 cy-GB
%SUBLANG_WOLOF_SENEGAL                       = &H01    ' Wolof (Senegal)
%SUBLANG_XHOSA_SOUTH_AFRICA                  = &H01    ' isiXhosa / Xhosa (South Africa) &H0434 xh-ZA
%SUBLANG_YAKUT_RUSSIA                        = &H01    ' Yakut (Russia) &H0485 sah-RU
%SUBLANG_YI_PRC                              = &H01    ' Yi (PRC)) &H0478
%SUBLANG_YORUBA_NIGERIA                      = &H01    ' Yoruba (Nigeria) 046a yo-NG
%SUBLANG_ZULU_SOUTH_AFRICA                   = &H01    ' isiZulu / Zulu (South Africa) &H0435 zu-ZA




'
'  Sorting IDs.
'
'  Note that the named locale APIs (eg CompareStringExEx) are recommended.
'

%SORT_DEFAULT                   = &H0     ' sorting default

%SORT_INVARIANT_MATH            = &H1     ' Invariant (Mathematical Symbols)

%SORT_JAPANESE_XJIS             = &H0     ' Japanese XJIS order
%SORT_JAPANESE_UNICODE          = &H1     ' Japanese Unicode order (no longer supported)
%SORT_JAPANESE_RADICALSTROKE    = &H4     ' Japanese radical/stroke order

%SORT_CHINESE_BIG5              = &H0     ' Chinese BIG5 order
%SORT_CHINESE_PRCP              = &H0     ' PRC Chinese Phonetic order
%SORT_CHINESE_UNICODE           = &H1     ' Chinese Unicode order (no longer supported)
%SORT_CHINESE_PRC               = &H2     ' PRC Chinese Stroke Count order
%SORT_CHINESE_BOPOMOFO          = &H3     ' Traditional Chinese Bopomofo order
%SORT_CHINESE_RADICALSTROKE     = &H4     ' Traditional Chinese radical/stroke order.

%SORT_KOREAN_KSC                = &H0     ' Korean KSC order
%SORT_KOREAN_UNICODE            = &H1     ' Korean Unicode order (no longer supported)

%SORT_GERMAN_PHONE_BOOK         = &H1     ' German Phone Book order

%SORT_HUNGARIAN_DEFAULT         = &H0     ' Hungarian Default order
%SORT_HUNGARIAN_TECHNICAL       = &H1     ' Hungarian Technical order

%SORT_GEORGIAN_TRADITIONAL      = &H0     ' Georgian Traditional order
%SORT_GEORGIAN_MODERN           = &H1     ' Georgian Modern order


'
'  A language ID is a 16 bit value which is the combination of a
'  primary language ID and a secondary language ID.  The bits are
'  allocated as follows:
'
'       +-----------------------+-------------------------+
'       |     Sublanguage ID    |   Primary Language ID   |
'       +-----------------------+-------------------------+
'        15                   10 9                       0   bit
'
'  WARNING:  This pattern isn't always follows, Serbina, Bosnian & Croation
'            for example.
'
'  It is recommended that applications test for locale names or actual LCIDs.
'
'  Language ID creation/extraction macros:
'
'    MAKELANGID    - construct language id from a primary language id and
'                    a sublanguage id.
'    PRIMARYLANGID - extract primary language id from a language id.
'    SUBLANGID     - extract sublanguage id from a language id.
'
'  Note that the LANG, SUBLANG construction is not always consistent.
'  The named locale APIs (eg GetLocaleInfoEx) are recommended.
'
'  Language IDs do not exist for all locales
'
MACRO FUNCTION MAKELANGID(p, s)
    MACROTEMP d
    LOCAL d AS DWORD
    d = LO(WORD, s)
    SHIFT LEFT d, 10
END MACRO=(d OR (p))

MACRO PRIMARYLANGID(lgid) = ((lgid) AND &H3ff)

MACRO FUNCTION SUBLANGID(lgid)
    MACROTEMP d
    LOCAL d AS DWORD
    d = (lgid)
    SHIFT RIGHT d, 10
END MACRO=LO(WORD, d)


'
'  A locale ID is a 32 bit value which is the combination of a
'  language ID, a sort ID, and a reserved area.  The bits are
'  allocated as follows:
'
'       +-------------+---------+-------------------------+
'       |   Reserved  | Sort ID |      Language ID        |
'       +-------------+---------+-------------------------+
'        31         20 19     16 15                      0   bit
'
'  WARNING: This pattern isn't always followed (es-ES_tradnl vs es-ES for example)
'
'  It is recommended that applications test for locale names or actual LCIDs.
'
'  Locale ID creation/extraction macros:
'
'    MAKELCID            - construct the locale id from a language id and a sort id.
'    MAKESORTLCID        - construct the locale id from a language id, sort id, and sort version.
'    LANGIDFROMLCID      - extract the language id from a locale id.
'    SORTIDFROMLCID      - extract the sort id from a locale id.
'    SORTVERSIONFROMLCID - extract the sort version from a locale id.
'
'  Note that the LANG, SUBLANG construction is not always consistent.
'  The named locale APIs (eg GetLocaleInfoEx) are recommended.
'
'  LCIDs do not exist for all locales.
'
%NLS_VALID_LOCALE_MASK = &H000fffff

MACRO MAKELCID(lgid, srtid)=MAK(DWORD, lgid, srtid)

MACRO FUNCTION MAKESORTLCID(lgid, srtid, ver)
    MACROTEMP d
    LOCAL d AS DWORD
    d = (ver)
    SHIFT LEFT d, 20
END MACRO=(MAKELCID(lgid, srtid) OR d)

MACRO LANGIDFROMLCID(lcid)=LO(WORD, (lcid))
MACRO SORTIDFROMLCID(lcid)=LO(BYTE, HI(WORD, (lcid)))

MACRO FUNCTION SORTVERSIONFROMLCID(lcid)
    MACROTEMP d
    LOCAL d AS DWORD
    d = (lcid)
    SHIFT RIGHT d, 20
END MACRO=LO(BYTE, d)

' 8 characters for language
' 8 characters for region
' 64 characters for suffix (script)
' 2 characters for '-' separators
' 2 characters for prefix like "i-" or "x-"
' 1 null termination
%LOCALE_NAME_MAX_LENGTH = 85

'
'  Default System and User IDs for language and locale.
'  Locale names such as %LOCALE_NAME_SYSTEM_DEFAULT, %LOCALE_NAME_USER_DEFAULT,
'  and %LOCALE_NAME_INVARIANT are preferred.
'

%LANG_SYSTEM_DEFAULT = &H0800
%LANG_USER_DEFAULT   = &H0400

MACRO LANG_SYSTEM_DEFAULT  = (MAKELANGID(%LANG_NEUTRAL, %SUBLANG_SYS_DEFAULT))
MACRO LANG_USER_DEFAULT    = (MAKELANGID(%LANG_NEUTRAL, %SUBLANG_DEFAULT))

%LOCALE_SYSTEM_DEFAULT   = &H0800
%LOCALE_USER_DEFAULT     = &H0400

MACRO LOCALE_SYSTEM_DEFAULT = (MAKELCID(LANG_SYSTEM_DEFAULT, %SORT_DEFAULT))
MACRO LOCALE_USER_DEFAULT   = (MAKELCID(LANG_USER_DEFAULT, %SORT_DEFAULT))

'
'  Other special IDs for language and locale.
'
MACRO LOCALE_CUSTOM_DEFAULT=(MAKELCID(MAKELANGID(%LANG_NEUTRAL, %SUBLANG_CUSTOM_DEFAULT), %SORT_DEFAULT))

MACRO LOCALE_CUSTOM_UNSPECIFIED=(MAKELCID(MAKELANGID(%LANG_NEUTRAL, %SUBLANG_CUSTOM_UNSPECIFIED), %SORT_DEFAULT))

MACRO LOCALE_CUSTOM_UI_DEFAULT=(MAKELCID(MAKELANGID(%LANG_NEUTRAL, %SUBLANG_UI_CUSTOM_DEFAULT), %SORT_DEFAULT))

MACRO LOCALE_NEUTRAL=(MAKELCID(MAKELANGID(%LANG_NEUTRAL, %SUBLANG_NEUTRAL), %SORT_DEFAULT))

MACRO LOCALE_INVARIANT=(MAKELCID(MAKELANGID(%LANG_INVARIANT, %SUBLANG_NEUTRAL), %SORT_DEFAULT))

#IF NOT %DEF(%WIN32_NO_STATUS)
%STATUS_WAIT_0                     = &H00000000
%STATUS_ABANDONED_WAIT_0           = &H00000080
%STATUS_USER_APC                   = &H000000C0
%STATUS_TIMEOUT                    = &H00000102
%STATUS_PENDING                    = &H00000103
%DBG_EXCEPTION_HANDLED             = &H00010001
%DBG_CONTINUE                      = &H00010002
%STATUS_SEGMENT_NOTIFICATION       = &H40000005
%DBG_TERMINATE_THREAD              = &H40010003
%DBG_TERMINATE_PROCESS             = &H40010004
%DBG_CONTROL_C                     = &H40010005
%DBG_PRINTEXCEPTION_C              = &H40010006
%DBG_RIPEXCEPTION                  = &H40010007
%DBG_CONTROL_BREAK                 = &H40010008
%DBG_COMMAND_EXCEPTION             = &H40010009
%STATUS_GUARD_PAGE_VIOLATION       = &H80000001
%STATUS_DATATYPE_MISALIGNMENT      = &H80000002
%STATUS_BREAKPOINT                 = &H80000003
%STATUS_SINGLE_STEP                = &H80000004
%STATUS_LONGJUMP                   = &H80000026
%STATUS_UNWIND_CONSOLIDATE         = &H80000029
%DBG_EXCEPTION_NOT_HANDLED         = &H80010001
%STATUS_ACCESS_VIOLATION           = &HC0000005
%STATUS_IN_PAGE_ERROR              = &HC0000006
%STATUS_INVALID_HANDLE             = &HC0000008
%STATUS_INVALID_PARAMETER          = &HC000000D
%STATUS_NO_MEMORY                  = &HC0000017
%STATUS_ILLEGAL_INSTRUCTION        = &HC000001D
%STATUS_NONCONTINUABLE_EXCEPTION   = &HC0000025
%STATUS_INVALID_DISPOSITION        = &HC0000026
%STATUS_ARRAY_BOUNDS_EXCEEDED      = &HC000008C
%STATUS_FLOAT_DENORMAL_OPERAND     = &HC000008D
%STATUS_FLOAT_DIVIDE_BY_ZERO       = &HC000008E
%STATUS_FLOAT_INEXACT_RESULT       = &HC000008F
%STATUS_FLOAT_INVALID_OPERATION    = &HC0000090
%STATUS_FLOAT_OVERFLOW             = &HC0000091
%STATUS_FLOAT_STACK_CHECK          = &HC0000092
%STATUS_FLOAT_UNDERFLOW            = &HC0000093
%STATUS_INTEGER_DIVIDE_BY_ZERO     = &HC0000094
%STATUS_INTEGER_OVERFLOW           = &HC0000095
%STATUS_PRIVILEGED_INSTRUCTION     = &HC0000096
%STATUS_STACK_OVERFLOW             = &HC00000FD
%STATUS_DLL_NOT_FOUND              = &HC0000135
%STATUS_ORDINAL_NOT_FOUND          = &HC0000138
%STATUS_ENTRYPOINT_NOT_FOUND       = &HC0000139
%STATUS_CONTROL_C_EXIT             = &HC000013A
%STATUS_DLL_INIT_FAILED            = &HC0000142
%STATUS_FLOAT_MULTIPLE_FAULTS      = &HC00002B4
%STATUS_FLOAT_MULTIPLE_TRAPS       = &HC00002B5
%STATUS_REG_NAT_CONSUMPTION        = &HC00002C9
%STATUS_STACK_BUFFER_OVERRUN       = &HC0000409
%STATUS_INVALID_CRUNTIME_PARAMETER = &HC0000417
%STATUS_ASSERTION_FAILURE          = &HC0000420

#IF %DEF(%STATUS_SUCCESS) OR (%WIN32_WINNT > &H0500)
%STATUS_SXS_EARLY_DEACTIVATION     = &HC015000F
%STATUS_SXS_INVALID_DEACTIVATION   = &HC0150010
#ENDIF

#ENDIF ' #IF NOT %DEF(%WIN32_NO_STATUS)
%MAXIMUM_WAIT_OBJECTS = 64     ' Maximum number of wait objects

%MAXIMUM_SUSPEND_COUNT = %MAXCHAR ' Maximum times thread can be suspended

MACRO KSPIN_LOCK=DWORD


'//
'// Define 128-bit 16-byte aligned xmm register type.
'//
'
'typedef struct DECLSPEC_ALIGN(16) _M128A {
'    ULONGLONG Low;
'    LONGLONG High;
'} M128A, *PM128A;
'
'//
'// Format of data for (F)XSAVE/(F)XRSTOR instruction
'//
'
'typedef struct DECLSPEC_ALIGN(16) _XSAVE_FORMAT {
'    WORD   ControlWord;
'    WORD   StatusWord;
'    BYTE  TagWord;
'    BYTE  Reserved1;
'    WORD   ErrorOpcode;
'    DWORD ErrorOffset;
'    WORD   ErrorSelector;
'    WORD   Reserved2;
'    DWORD DataOffset;
'    WORD   DataSelector;
'    WORD   Reserved3;
'    DWORD MxCsr;
'    DWORD MxCsr_Mask;
'    M128A FloatRegisters[8];
'
'#if defined(_WIN64)
'
'    M128A XmmRegisters[16];
'    BYTE  Reserved4[96];
'
'#else
'
'    M128A XmmRegisters[8];
'    BYTE  Reserved4[192];
'
'    //
'    // The fields below are not part of XSAVE/XRSTOR format.
'    // They are written by the OS which is relying on a fact that
'    // neither (FX)SAVE nor (F)XSTOR used this area.
'    //
'
'    DWORD   StackControl[7];    // KERNEL_STACK_CONTROL structure actualy
'    DWORD   Cr0NpxState;
'
'#endif
'
'} XSAVE_FORMAT, *PXSAVE_FORMAT;
'
'typedef struct DECLSPEC_ALIGN(8) _XSAVE_AREA_HEADER {
'    DWORD64 Mask;
'    DWORD64 Reserved[7];
'} XSAVE_AREA_HEADER, *PXSAVE_AREA_HEADER;
'
'typedef struct DECLSPEC_ALIGN(16) _XSAVE_AREA {
'    XSAVE_FORMAT LegacyState;
'    XSAVE_AREA_HEADER Header;
'} XSAVE_AREA, *PXSAVE_AREA;
'
'typedef struct _XSTATE_CONTEXT {
'    DWORD64 Mask;
'    DWORD Length;
'    DWORD Reserved1;
'    __field_bcount_opt(Length) PXSAVE_AREA Area;
'
'#if defined(_X86_)
'    DWORD Reserved2;
'#endif
'
'    PVOID Buffer;
'
'#if defined(_X86_)
'    DWORD Reserved3;
'#endif
'
'} XSTATE_CONTEXT, *PXSTATE_CONTEXT;


%XSAVE_ALIGN = 64
'#define MINIMAL_XSTATE_AREA_LENGTH  sizeof(XSAVE_AREA)


'
' This structure specifies an offset (from the beginning of CONTEXT_EX
' structure) and size of a single chunk of an extended context structure.
'
' N.B. Offset may be negative.
'

TYPE CONTEXT_CHUNK
    Offset AS LONG
    Length AS DWORD
END TYPE

'
' CONTEXT_EX structure is an extension to CONTEXT structure. It defines
' a context record as a set of disjoint variable-sized buffers (chunks)
' each containing a portion of processor state. Currently there are only
' two buffers (chunks) are defined:
'
'   - Legacy, that stores traditional CONTEXT structure;
'   - XState, that stores XSAVE save area buffer starting from
'     XSAVE_AREA_HEADER, i.e. without the first 512 bytes.
'
' There a few assumptions exists that simplify conversion of PCONTEXT
' pointer to PCONTEXT_EX pointer.
'
' 1. APIs that work with PCONTEXT pointers assume that CONTEXT_EX is
'    stored right after the CONTEXT structure. It is also assumed that
'    CONTEXT_EX is present if and only if corresponding CONTEXT_XXX
'    flags are set in CONTEXT.ContextFlags.
'
' 2. CONTEXT_EX.Legacy is always present if CONTEXT_EX structure is
'    present. All other chunks are optional.
'
' 3. CONTEXT.ContextFlags unambigiously define which chunks are
'    present. I.e. if CONTEXT_XSTATE is set CONTEXT_EX.XState is valid.
'

TYPE CONTEXT_EX

    '
    ' The total length of the structure starting from the chunk with
    ' the smallest offset. N.B. that the offset may be negative.
    '

    ALL AS CONTEXT_CHUNK

    '
    ' Wrapper for the traditional CONTEXT structure. N.B. the size of
    ' the chunk may be less than sizeof(CONTEXT) is some cases (when
    ' CONTEXT_EXTENDED_REGISTERS is not set on x86 for instance).
    '

    Legacy AS CONTEXT_CHUNK

    '
    ' CONTEXT_XSTATE: Extended processor state chunk. The state is
    ' stored in the same format XSAVE operation strores it with
    ' exception of the first 512 bytes, i.e. staring from
    ' XSAVE_AREA_HEADER. The lower two bits corresponding FP and
    ' SSE state must be zero.
    '

    XState AS CONTEXT_CHUNK

END TYPE

'#define CONTEXT_EX_LENGTH   ALIGN_UP_BY(sizeof(CONTEXT_EX), STACK_ALIGN)

'//
'// These macros make context chunks manupulations easier.
'//
'
'#define RTL_CONTEXT_EX_OFFSET(ContextEx, Chunk)         \
'    ((ContextEx)->Chunk.Offset)
'
'#define RTL_CONTEXT_EX_LENGTH(ContextEx, Chunk)         \
'    ((ContextEx)->Chunk.Length)
'
'#define RTL_CONTEXT_EX_CHUNK(Base, Layout, Chunk)       \
'    ((PVOID)((PCHAR)(Base) + RTL_CONTEXT_EX_OFFSET(Layout, Chunk)))
'
'#define RTL_CONTEXT_OFFSET(Context, Chunk)              \
'    RTL_CONTEXT_EX_OFFSET((PCONTEXT_EX)(Context + 1), Chunk)
'
'#define RTL_CONTEXT_LENGTH(Context, Chunk)              \
'    RTL_CONTEXT_EX_LENGTH((PCONTEXT_EX)(Context + 1), Chunk)
'
'#define RTL_CONTEXT_CHUNK(Context, Chunk)               \
'    RTL_CONTEXT_EX_CHUNK((PCONTEXT_EX)(Context + 1),    \
'                         (PCONTEXT_EX)(Context + 1),    \
'                         Chunk)


'#if !defined(__midl) && !defined(MIDL_PASS)
'
'//
'// XSAVE/XRSTOR save area should be aligned on 64 byte boundary
'//
'
'C_ASSERT((sizeof(XSAVE_FORMAT) & (XSAVE_ALIGN - 1)) == 0);
'C_ASSERT((FIELD_OFFSET(XSAVE_AREA, Header) & (XSAVE_ALIGN - 1)) == 0);
'
'// XSAVE_AREA structure must be sized uniformly on all architectures
'C_ASSERT(MINIMAL_XSTATE_AREA_LENGTH == 512 + 64);
'
'#endif


#IF %DEF(%AMD64)

'
' Define constants for use with _mm_prefetch.
'

%MM_HINT_T0   = 1
%MM_HINT_T1   = 2
%MM_HINT_T2   = 3
%MM_HINT_NTA  = 0

'
' PreFetchCacheLine level defines.
'

%PF_TEMPORAL_LEVEL_1 = %MM_HINT_T0
%PF_TEMPORAL_LEVEL_2 = %MM_HINT_T1
%PF_TEMPORAL_LEVEL_3 = %MM_HINT_T2
%PF_NON_TEMPORAL_LEVEL_ALL = %MM_HINT_NTA

'
' The following values specify the type of access in the first parameter
' of the exception record whan the exception code specifies an access
' violation.
'

%EXCEPTION_READ_FAULT = 0          ' exception caused by a read
%EXCEPTION_WRITE_FAULT = 1         ' exception caused by a write
%EXCEPTION_EXECUTE_FAULT = 8       ' exception caused by an instruction fetch

' begin_wx86
'
' The following flags control the contents of the CONTEXT structure.
'

#IF NOT %DEF(%RC_INVOKED)

%CONTEXT_AMD64 = &H100000

' end_wx86

%CONTEXT_CONTROL = (%CONTEXT_AMD64 OR &H1)
%CONTEXT_INTEGER = (%CONTEXT_AMD64 OR &H2)
%CONTEXT_SEGMENTS = (%CONTEXT_AMD64 OR &H4)
%CONTEXT_FLOATING_POINT  = (%CONTEXT_AMD64 OR &H8)
%CONTEXT_DEBUG_REGISTERS = (%CONTEXT_AMD64 OR &H10)

%CONTEXT_FULL = (%CONTEXT_CONTROL OR %CONTEXT_INTEGER OR %CONTEXT_FLOATING_POINT)

%CONTEXT_ALL = (%CONTEXT_CONTROL OR %CONTEXT_INTEGER OR %CONTEXT_SEGMENTS OR %CONTEXT_FLOATING_POINT OR %CONTEXT_DEBUG_REGISTERS)

%CONTEXT_EXCEPTION_ACTIVE = &H8000000
%CONTEXT_SERVICE_ACTIVE = &H10000000
%CONTEXT_EXCEPTION_REQUEST = &H40000000
%CONTEXT_EXCEPTION_REPORTING = &H80000000

' begin_wx86

#ENDIF ' NOT %DEF(%RC_INVOKED)

'
' Define initial MxCsr and FpCsr control.
'

%INITIAL_MXCSR = &H1f80            ' initial MXCSR value
%INITIAL_FPCSR = &H027f            ' initial FPCSR value

MACRO XMM_SAVE_AREA32=XSAVE_FORMAT

'
' Context Frame
'
'  This frame has a several purposes: 1) it is used as an argument to
'  NtContinue, 2) it is used to constuct a call frame for APC delivery,
'  and 3) it is used in the user level thread creation routines.
'
'
' The flags field within this record controls the contents of a CONTEXT
' record.
'
' If the context record is used as an input parameter, then for each
' portion of the context record controlled by a flag whose value is
' set, it is assumed that that portion of the context record contains
' valid context. If the context record is being used to modify a threads
' context, then only that portion of the threads context is modified.
'
' If the context record is used as an output parameter to capture the
' context of a thread, then only those portions of the thread's context
' corresponding to set flags will be returned.
'
' CONTEXT_CONTROL specifies SegSs, Rsp, SegCs, Rip, and EFlags.
'
' CONTEXT_INTEGER specifies Rax, Rcx, Rdx, Rbx, Rbp, Rsi, Rdi, and R8-R15.
'
' CONTEXT_SEGMENTS specifies SegDs, SegEs, SegFs, and SegGs.
'
' CONTEXT_FLOATING_POINT specifies Xmm0-Xmm15.
'
' CONTEXT_DEBUG_REGISTERS specifies Dr0-Dr3 and Dr6-Dr7.
'

'typedef struct DECLSPEC_ALIGN(16) _CONTEXT {
'
'    //
'    // Register parameter home addresses.
'    //
'    // N.B. These fields are for convience - they could be used to extend the
'    //      context record in the future.
'    //
'
'    DWORD64 P1Home;
'    DWORD64 P2Home;
'    DWORD64 P3Home;
'    DWORD64 P4Home;
'    DWORD64 P5Home;
'    DWORD64 P6Home;
'
'    //
'    // Control flags.
'    //
'
'    DWORD ContextFlags;
'    DWORD MxCsr;
'
'    //
'    // Segment Registers and processor flags.
'    //
'
'    WORD   SegCs;
'    WORD   SegDs;
'    WORD   SegEs;
'    WORD   SegFs;
'    WORD   SegGs;
'    WORD   SegSs;
'    DWORD EFlags;
'
'    //
'    // Debug registers
'    //
'
'    DWORD64 Dr0;
'    DWORD64 Dr1;
'    DWORD64 Dr2;
'    DWORD64 Dr3;
'    DWORD64 Dr6;
'    DWORD64 Dr7;
'
'    //
'    // Integer registers.
'    //
'
'    DWORD64 Rax;
'    DWORD64 Rcx;
'    DWORD64 Rdx;
'    DWORD64 Rbx;
'    DWORD64 Rsp;
'    DWORD64 Rbp;
'    DWORD64 Rsi;
'    DWORD64 Rdi;
'    DWORD64 R8;
'    DWORD64 R9;
'    DWORD64 R10;
'    DWORD64 R11;
'    DWORD64 R12;
'    DWORD64 R13;
'    DWORD64 R14;
'    DWORD64 R15;
'
'    //
'    // Program counter.
'    //
'
'    DWORD64 Rip;
'
'    //
'    // Floating point state.
'    //
'
'    union {
'        XMM_SAVE_AREA32 FltSave;
'        struct {
'            M128A Header[2];
'            M128A Legacy[8];
'            M128A Xmm0;
'            M128A Xmm1;
'            M128A Xmm2;
'            M128A Xmm3;
'            M128A Xmm4;
'            M128A Xmm5;
'            M128A Xmm6;
'            M128A Xmm7;
'            M128A Xmm8;
'            M128A Xmm9;
'            M128A Xmm10;
'            M128A Xmm11;
'            M128A Xmm12;
'            M128A Xmm13;
'            M128A Xmm14;
'            M128A Xmm15;
'        } DUMMYSTRUCTNAME;
'    } DUMMYUNIONNAME;
'
'    //
'    // Vector registers.
'    //
'
'    M128A VectorRegister[26];
'    DWORD64 VectorControl;
'
'    //
'    // Special debug control registers.
'    //
'
'    DWORD64 DebugControl;
'    DWORD64 LastBranchToRip;
'    DWORD64 LastBranchFromRip;
'    DWORD64 LastExceptionToRip;
'    DWORD64 LastExceptionFromRip;
'} CONTEXT, *PCONTEXT;

'
' Define function table entry - a function table entry is generated for
' each frame function.
'

%RUNTIME_FUNCTION_INDIRECT = &H1

TYPE RUNTIME_FUNCTION
    BeginAddress AS DWORD
    EndAddress   AS DWORD
    UnwindData   AS DWORD
END TYPE

'
' Define unwind history table structure.
'

%UNWIND_HISTORY_TABLE_SIZE = 12

TYPE UNWIND_HISTORY_TABLE_ENTRY
    ImageBase     AS QUAD
    FunctionEntry AS DWORD  '     PRUNTIME_FUNCTION
END TYPE

TYPE UNWIND_HISTORY_TABLE
    COUNT       AS DWORD
    LocalHint   AS BYTE
    GlobalHint  AS BYTE
    Search      AS BYTE
    ONCE        AS BYTE
    LowAddress  AS QUAD
    HighAddress AS QUAD
    Entry(%UNWIND_HISTORY_TABLE_SIZE-1) AS UNWIND_HISTORY_TABLE_ENTRY
END TYPE

'
' Define dynamic function table entry.
'

DECLARE FUNCTION PGET_RUNTIME_FUNCTION_CALLBACK (BYVAL ControlPc AS QUAD, _
    Context AS ANY) AS DWORD

DECLARE FUNCTION POUT_OF_PROCESS_FUNCTION_TABLE_CALLBACK _
    (BYVAL PROCESS AS DWORD, TableAddress AS ANY, Entries AS DWORD, _
    Functions AS DWORD) AS DWORD

$OUT_OF_PROCESS_FUNCTION_TABLE_CALLBACK_EXPORT_NAME="OutOfProcessFunctionTableCallback"

'
' Define runtime exception handling prototypes.
'

DECLARE SUB RtlRestoreContext CDECL LIB "Kernel32.dll" _
    ALIAS "RtlRestoreContext" _
    (ContextRecord AS CONTEXT, OPTIONAL ExceptionRecord AS EXCEPTION_RECORD)

DECLARE FUNCTION RtlAddFunctionTable CDECL LIB "Kernel32.dll" _
    ALIAS "RtlAddFunctionTable" _
    (BYVAL FunctionTable AS DWORD, _
    BYVAL EntryCount AS DWORD, _
    BYVAL BaseAddress AS QUAD) _
    AS BYTE

DECLARE FUNCTION RtlLookupFunctionEntry LIB "Kernel32.dll" _
    ALIAS "RtlLookupFunctionEntry" _
    (BYVAL ControlPc AS QUAD, _
    ImageBase AS QUAD, _
    HistoryTable AS DWORD) _
    AS DWORD

'
' Nonvolatile context pointer record.
'

'typedef struct _KNONVOLATILE_CONTEXT_POINTERS {
'    union {
'        PM128A FloatingContext[16];
'        struct {
'            PM128A Xmm0;
'            PM128A Xmm1;
'            PM128A Xmm2;
'            PM128A Xmm3;
'            PM128A Xmm4;
'            PM128A Xmm5;
'            PM128A Xmm6;
'            PM128A Xmm7;
'            PM128A Xmm8;
'            PM128A Xmm9;
'            PM128A Xmm10;
'            PM128A Xmm11;
'            PM128A Xmm12;
'            PM128A Xmm13;
'            PM128A Xmm14;
'            PM128A Xmm15;
'        } DUMMYSTRUCTNAME;
'    } DUMMYUNIONNAME;
'
'    union {
'        PDWORD64 IntegerContext[16];
'        struct {
'            PDWORD64 Rax;
'            PDWORD64 Rcx;
'            PDWORD64 Rdx;
'            PDWORD64 Rbx;
'            PDWORD64 Rsp;
'            PDWORD64 Rbp;
'            PDWORD64 Rsi;
'            PDWORD64 Rdi;
'            PDWORD64 R8;
'            PDWORD64 R9;
'            PDWORD64 R10;
'            PDWORD64 R11;
'            PDWORD64 R12;
'            PDWORD64 R13;
'            PDWORD64 R14;
'            PDWORD64 R15;
'        } DUMMYSTRUCTNAME;
'    } DUMMYUNIONNAME2;
'
'} KNONVOLATILE_CONTEXT_POINTERS, *PKNONVOLATILE_CONTEXT_POINTERS;

DECLARE FUNCTION RtlVirtualUnwind LIB "Kernel32.dll" ALIAS "RtlVirtualUnwind" _
    (BYVAL HandlerType AS DWORD, _
    BYVAL ImageBase AS QUAD, _
    BYVAL ControlPc AS QUAD, _
    BYVAL FunctionEntry AS DWORD, _
    ContextRecord AS CONTEXT, _
    HandlerData AS DWORD, _
    EstablisherFrame AS QUAD, _
    BYVAL ContextPointers AS KNONVOLATILE_CONTEXT_POINTERS PTR) _
    AS DWORD

DECLARE FUNCTION RtlInstallFunctionTableCallback CDECL _
    ALIAS "RtlInstallFunctionTableCallback" _
    (BYVAL TableIdentifier AS QUAD, _
    BYVAL BaseAddress AS QUAD, _
    BYVAL Length AS DWORD, _
    BYVAL CallbackFn AS DWORD, _  'PGET_RUNTIME_FUNCTION_CALLBACK
    Context AS ANY, _
    OPTIONAL BYVAL OutOfProcessCallbackDll AS WSTRINGZ PTR) _
    AS BYTE

DECLARE FUNCTION RtlDeleteFunctionTable CDECL _
    ALIAS "RtlDeleteFunctionTable" _
    (BYVAL FunctionTable AS DWORD) _  ' PRUNTIME_FUNCTION
    AS BYTE

#ENDIF ' %AMD64


#IF %DEF(%X86)

'
' The following values specify the type of failing access when the status is
' STATUS_ACCESS_VIOLATION and the first parameter in the execpetion record.
'

%EXCEPTION_READ_FAULT        = 0 ' Access violation was caused by a read
%EXCEPTION_WRITE_FAULT       = 1 ' Access violation was caused by a write
%EXCEPTION_EXECUTE_FAULT     = 8 ' Access violation was caused by an instruction fetch

' begin_wx86
' begin_ntddk

'
'  Define the size of the 80387 save area, which is in the context frame.
'

%SIZE_OF_80387_REGISTERS    = 80

'
' The following flags control the contents of the CONTEXT structure.
'

#IF NOT %DEF(%RC_INVOKED)

%CONTEXT_i386  = &H00010000    ' this assumes that i386 and
%CONTEXT_i486  = &H00010000    ' i486 have identical context records

' end_wx86

%CONTEXT_CONTROL         = (%CONTEXT_i386 OR &H00000001) ' SS:SP, CS:IP, FLAGS, BP
%CONTEXT_INTEGER         = (%CONTEXT_i386 OR &H00000002) ' AX, BX, CX, DX, SI, DI
%CONTEXT_SEGMENTS        = (%CONTEXT_i386 OR &H00000004) ' DS, ES, FS, GS
%CONTEXT_FLOATING_POINT  = (%CONTEXT_i386 OR &H00000008) ' 387 state
%CONTEXT_DEBUG_REGISTERS = (%CONTEXT_i386 OR &H00000010) ' DB 0-3,6,7
%CONTEXT_EXTENDED_REGISTERS = (%CONTEXT_i386 OR &H00000020) ' cpu specific extensions

%CONTEXT_FULL = (%CONTEXT_CONTROL OR %CONTEXT_INTEGER OR %CONTEXT_SEGMENTS)

%CONTEXT_ALL  = (%CONTEXT_CONTROL OR %CONTEXT_INTEGER OR %CONTEXT_SEGMENTS OR _
                 %CONTEXT_FLOATING_POINT OR %CONTEXT_DEBUG_REGISTERS OR _
                 %CONTEXT_EXTENDED_REGISTERS)

' begin_wx86

#ENDIF ' IF NOT %DEF(%RC_INVOKED)

%MAXIMUM_SUPPORTED_EXTENSION   = 512

TYPE FLOATING_SAVE_AREA
    ControlWord   AS DWORD
    StatusWord    AS DWORD
    TagWord       AS DWORD
    ErrorOffset   AS DWORD
    ErrorSelector AS DWORD
    DataOffset    AS DWORD
    DataSelector  AS DWORD
    RegisterArea(%SIZE_OF_80387_REGISTERS - 1) AS BYTE
    Cr0NpxState   AS DWORD
END TYPE

%MAXIMUM_SUPPORTED_EXTENSION = 512

'
' Context Frame
'
'  This frame has a several purposes: 1) it is used as an argument to
'  NtContinue, 2) is is used to constuct a call frame for APC delivery,
'  and 3) it is used in the user level thread creation routines.
'
'  The layout of the record conforms to a standard call frame.
'

TYPE CONTEXT

    '
    ' The flags values within this flag control the contents of
    ' a CONTEXT record.
    '
    ' If the context record is used as an input parameter, then
    ' for each portion of the context record controlled by a flag
    ' whose value is set, it is assumed that that portion of the
    ' context record contains valid context. If the context record
    ' is being used to modify a threads context, then only that
    ' portion of the threads context will be modified.
    '
    ' If the context record is used as an IN OUT parameter to capture
    ' the context of a thread, then only those portions of the thread's
    ' context corresponding to set flags will be returned.
    '
    ' The context record is never used as an OUT only parameter.
    '

    ContextFlags AS DWORD

    '
    ' This section is specified/returned if CONTEXT_DEBUG_REGISTERS is
    ' set in ContextFlags.  Note that CONTEXT_DEBUG_REGISTERS is NOT
    ' included in CONTEXT_FULL.
    '

    Dr0 AS DWORD
    Dr1 AS DWORD
    Dr2 AS DWORD
    Dr3 AS DWORD
    Dr6 AS DWORD
    Dr7 AS DWORD

    '
    ' This section is specified/returned if the
    ' ContextFlags word contians the flag CONTEXT_FLOATING_POINT.
    '

    FloatSave AS FLOATING_SAVE_AREA

    '
    ' This section is specified/returned if the
    ' ContextFlags word contians the flag CONTEXT_SEGMENTS.
    '

    SegGs AS DWORD
    SegFs AS DWORD
    SegEs AS DWORD
    SegDs AS DWORD

    '
    ' This section is specified/returned if the
    ' ContextFlags word contians the flag CONTEXT_INTEGER.
    '

    Edi AS DWORD
    Esi AS DWORD
    Ebx AS DWORD
    Edx AS DWORD
    Ecx AS DWORD
    Eax AS DWORD

    '
    ' This section is specified/returned if the
    ' ContextFlags word contians the flag CONTEXT_CONTROL.
    '

    Ebp    AS DWORD
    Eip    AS DWORD
    SegCs  AS DWORD    ' MUST BE SANITIZED
    EFlags AS DWORD    ' MUST BE SANITIZED
    Esp    AS DWORD
    SegSs  AS DWORD

    '
    ' This section is specified/returned if the ContextFlags word
    ' contains the flag CONTEXT_EXTENDED_REGISTERS.
    ' The format and contexts are processor specific
    '

    ExtendedRegisters(%MAXIMUM_SUPPORTED_EXTENSION - 1) AS BYTE

END TYPE


#ENDIF  ' #IF %DEF(%X86)


TYPE EXCEPTION_RECORD
    ExceptionCode    AS DWORD
    ExceptionFlags   AS DWORD
    ExceptionRecord  AS EXCEPTION_RECORD PTR
    ExceptionAddress AS DWORD
    NumberParameters AS DWORD
    ExceptionInformation(%EXCEPTION_MAXIMUM_PARAMETERS - 1) AS DWORD
END TYPE

TYPE EXCEPTION_POINTERS
    ExceptionRecord AS EXCEPTION_RECORD PTR
    ContextRecord   AS CONTEXT PTR
END TYPE


' [ Microsoft never defines the type of the result. We're assuming LONG. ]
DECLARE FUNCTION PEXCEPTION_ROUTINE (ExceptionRecord AS EXCEPTION_RECORD, _
    EstablisherFrame AS ANY, ContextRecord AS CONTEXT, DispatcherContext AS ANY) _
    AS LONG


#IF NOT %DEF(%LDT_ENTRY_DEFINED)
%LDT_ENTRY_DEFINED = 1

TYPE LDT_ENTRY_type1
    BaseMid AS BYTE
    Flags1  AS BYTE    ' declare as bytes to avoid alignment
    Flags2  AS BYTE    ' problems
    BaseHi  AS BYTE
END TYPE

TYPE LDT_ENTRY_type2
    BaseMid     AS BIT * 8 IN DWORD
    nType       AS BIT * 5
    Dpl         AS BIT * 2
    Pres        AS BIT * 1
    LimitHi     AS BIT * 4
    Sys         AS BIT * 1
    Reserved_0  AS BIT * 1
    Default_Big AS BIT * 1
    Granularity AS BIT * 1
    BaseHi      AS BIT * 8
END TYPE

UNION LDT_ENTRY_union
    Bytes AS LDT_ENTRY_type1
    Bitss AS LDT_ENTRY_type2
END UNION

TYPE LDT_ENTRY
    LimitLow AS WORD
    BaseLow  AS WORD
    HighWord AS LDT_ENTRY_union
END TYPE

#ENDIF  ' #IF NOT %DEF(%LDT_ENTRY_DEFINED)


'
'  Define the access mask as a longword sized structure divided up as
'  follows:
'
'       3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
'       1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'      +---------------+---------------+-------------------------------+
'      |G|G|G|G|Res'd|A| StandardRights|         SpecificRights        |
'      |R|W|E|A|     |S|               |                               |
'      +-+-------------+---------------+-------------------------------+
'
'      typedef struct _ACCESS_MASK {
'          WORD   SpecificRights;
'          BYTE  StandardRights;
'          BYTE  AccessSystemAcl : 1;
'          BYTE  Reserved : 3;
'          BYTE  GenericAll : 1;
'          BYTE  GenericExecute : 1;
'          BYTE  GenericWrite : 1;
'          BYTE  GenericRead : 1;
'      } ACCESS_MASK;
'      typedef ACCESS_MASK *PACCESS_MASK;
'
'  but to make life simple for programmers we'll allow them to specify
'  a desired access mask by simply ORing together multiple single rights
'  and treat an access mask as a DWORD.  For example
'
'      DesiredAccess = DELETE OR READ_CONTROL
'
'  So we'll declare ACCESS_MASK as DWORD
'

MACRO ACCESS_MASK=DWORD

''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                    '
'                             ACCESS TYPES                           '
'                                                                    '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''


' begin_wdm
'
'  The following are masks for the predefined standard access types
'

%DELETE                         = (&H00010000)
%READ_CONTROL                   = (&H00020000)
%WRITE_DAC                      = (&H00040000)
%WRITE_OWNER                    = (&H00080000)
%SYNCHRONIZE                    = (&H00100000)

%STANDARD_RIGHTS_REQUIRED       = (&H000F0000)

%STANDARD_RIGHTS_READ           = (%READ_CONTROL)
%STANDARD_RIGHTS_WRITE          = (%READ_CONTROL)
%STANDARD_RIGHTS_EXECUTE        = (%READ_CONTROL)

%STANDARD_RIGHTS_ALL            = (&H001F0000)

%SPECIFIC_RIGHTS_ALL            = (&H0000FFFF)

'
' AccessSystemAcl access type
'

%ACCESS_SYSTEM_SECURITY         = (&H01000000)

'
' MaximumAllowed access type
'

%MAXIMUM_ALLOWED                = (&H02000000)

'
'  These are the generic rights.
'

%GENERIC_READ                   = (&H80000000)
%GENERIC_WRITE                  = (&H40000000)
%GENERIC_EXECUTE                = (&H20000000)
%GENERIC_ALL                    = (&H10000000)


'
'  Define the generic mapping array.  This is used to denote the
'  mapping of each generic access right to a specific access mask.
'

TYPE GENERIC_MAPPING
    GenericRead    AS ACCESS_MASK
    GenericWrite   AS ACCESS_MASK
    GenericExecute AS ACCESS_MASK
    GenericAll     AS ACCESS_MASK
END TYPE



''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                    '
'                        LUID_AND_ATTRIBUTES                         '
'                                                                    '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
'


TYPE LUID_AND_ATTRIBUTES
    Luid       AS QUAD
    Attributes AS DWORD
END TYPE


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                    '
'              Security Id     (SID)                                 '
'                                                                    '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
'
' Pictorially the structure of an SID is as follows:
'
'         1   1   1   1   1   1
'         5   4   3   2   1   0   9   8   7   6   5   4   3   2   1   0
'      +---------------------------------------------------------------+
'      |      SubAuthorityCount        |Reserved1 (SBZ)|   Revision    |
'      +---------------------------------------------------------------+
'      |                   IdentifierAuthority[0]                      |
'      +---------------------------------------------------------------+
'      |                   IdentifierAuthority[1]                      |
'      +---------------------------------------------------------------+
'      |                   IdentifierAuthority[2]                      |
'      +---------------------------------------------------------------+
'      |                                                               |
'      +- -  -  -  -  -  -  -  SubAuthority[]  -  -  -  -  -  -  -  - -+
'      |                                                               |
'      +---------------------------------------------------------------+
'
'


' begin_ntifs

#IF NOT %DEF(%SID_IDENTIFIER_AUTHORITY_DEFINED)
%SID_IDENTIFIER_AUTHORITY_DEFINED = 1
TYPE SID_IDENTIFIER_AUTHORITY
    Value(5) AS BYTE
END TYPE
#ENDIF


#IF NOT %DEF(%SID_DEFINED)
%SID_DEFINED = 1
TYPE SID
    Revision            AS BYTE
    SubAuthorityCount   AS BYTE
    IdentifierAuthority AS SID_IDENTIFIER_AUTHORITY
    SubAuthority(0)     AS DWORD
END TYPE
#ENDIF

%SID_REVISION                    = (1)    ' Current revision level
%SID_MAX_SUB_AUTHORITIES         = (15)
%SID_RECOMMENDED_SUB_AUTHORITIES = (1)    ' Will change to around 6

                                                ' in a future release.
#IF NOT %DEF(%MIDL_PASS)
MACRO SECURITY_MAX_SID_SIZE=(SIZEOF(SID)-SIZEOF(DWORD)+(%SID_MAX_SUB_AUTHORITIES * SIZEOF(DWORD)))
#ENDIF ' MIDL_PASS


MACRO SID_NAME_USE_enum=LONG
ENUM SID_NAME_USE SINGULAR
    SidTypeUser   = 1
    SidTypeGroup
    SidTypeDomain
    SidTypeAlias
    SidTypeWellKnownGroup
    SidTypeDeletedAccount
    SidTypeInvalid
    SidTypeUnknown
    SidTypeComputer
    SidTypeLabel
END ENUM

TYPE SID_AND_ATTRIBUTES
    pSid       AS SID PTR
    Attributes AS DWORD
END TYPE

'typedef SID_AND_ATTRIBUTES SID_AND_ATTRIBUTES_ARRAY[ANYSIZE_ARRAY];
'typedef SID_AND_ATTRIBUTES_ARRAY *PSID_AND_ATTRIBUTES_ARRAY;

%SID_HASH_SIZE = 32
MACRO SID_HASH_ENTRY=DWORD

TYPE SID_AND_ATTRIBUTES_HASH
    SidCount               AS DWORD
    SidAttr                AS SID_AND_ATTRIBUTES PTR
    Hash(%SID_HASH_SIZE-1) AS SID_HASH_ENTRY
END TYPE


'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                         '
' Universal well-known SIDs                                               '
'                                                                         '
'     Null SID                     S-1-0-0                                '
'     World                        S-1-1-0                                '
'     Local                        S-1-2-0                                '
'     Creator Owner ID             S-1-3-0                                '
'     Creator Group ID             S-1-3-1                                '
'     Creator Owner Server ID      S-1-3-2                                '
'     Creator Group Server ID      S-1-3-3                                '
'                                                                         '
'     (Non-unique IDs)             S-1-4                                  '
'                                                                         '
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

'#define SECURITY_NULL_SID_AUTHORITY         {0,0,0,0,0,0}
'#define SECURITY_WORLD_SID_AUTHORITY        {0,0,0,0,0,1}
'#define SECURITY_LOCAL_SID_AUTHORITY        {0,0,0,0,0,2}
'#define SECURITY_CREATOR_SID_AUTHORITY      {0,0,0,0,0,3}
'#define SECURITY_NON_UNIQUE_AUTHORITY       {0,0,0,0,0,4}
'#define SECURITY_RESOURCE_MANAGER_AUTHORITY {0,0,0,0,0,9}

%SECURITY_NULL_RID                 = (&H00000000)
%SECURITY_WORLD_RID                = (&H00000000)
%SECURITY_LOCAL_RID                = (&H00000000)

%SECURITY_CREATOR_OWNER_RID        = (&H00000000)
%SECURITY_CREATOR_GROUP_RID        = (&H00000001)

%SECURITY_CREATOR_OWNER_SERVER_RID = (&H00000002)
%SECURITY_CREATOR_GROUP_SERVER_RID = (&H00000003)

%SECURITY_CREATOR_OWNER_RIGHTS_RID = (&H00000004)


'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                           '
' NT well-known SIDs                                                        '
'                                                                           '
'     NT Authority            S-1-5                                         '
'     Dialup                  S-1-5-1                                       '
'                                                                           '
'     Network                 S-1-5-2                                       '
'     Batch                   S-1-5-3                                       '
'     Interactive             S-1-5-4                                       '
'     (Logon IDs)             S-1-5-5-X-Y                                   '
'     Service                 S-1-5-6                                       '
'     AnonymousLogon          S-1-5-7       (aka null logon session)        '
'     Proxy                   S-1-5-8                                       '
'     Enterprise DC (EDC)     S-1-5-9       (aka domain controller account) '
'     Self                    S-1-5-10      (self RID)                      '
'     Authenticated User      S-1-5-11      (Authenticated user somewhere)  '
'     Restricted Code         S-1-5-12      (Running restricted code)       '
'     Terminal Server         S-1-5-13      (Running on Terminal Server)    '
'     Remote Logon            S-1-5-14      (Remote Interactive Logon)      '
'     This Organization       S-1-5-15                                      '
'                                                                           '
'     IUser                   S-1-5-17
'     Local System            S-1-5-18                                      '
'     Local Service           S-1-5-19                                      '
'     Network Service         S-1-5-20                                      '
'                                                                           '
'     (NT non-unique IDs)     S-1-5-&H15-... (NT Domain Sids)               '
'                                                                           '
'     (Built-in domain)       S-1-5-&H20                                    '
'                                                                           '
'     (Security Package IDs)  S-1-5-&H40                                    '
'     NTLM Authentication     S-1-5-&H40-10                                 '
'     SChannel Authentication S-1-5-&H40-14                                 '
'     Digest Authentication   S-1-5-&H40-21                                 '
'                                                                           '
'     Other Organization      S-1-5-1000    (>=1000 can not be filtered)    '
'                                                                           '
'                                                                           '
' NOTE: the relative identifier values (RIDs) determine which security      '
'       boundaries the SID is allowed to cross.  Before adding new RIDs,    '
'       a determination needs to be made regarding which range they should  '
'       be added to in order to ensure proper "SID filtering"               '
'                                                                           '
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''


'#define SECURITY_NT_AUTHORITY           {0,0,0,0,0,5}   ' ntifs

%SECURITY_DIALUP_RID            = (&H00000001)
%SECURITY_NETWORK_RID           = (&H00000002)
%SECURITY_BATCH_RID             = (&H00000003)
%SECURITY_INTERACTIVE_RID       = (&H00000004)
%SECURITY_LOGON_IDS_RID         = (&H00000005)
%SECURITY_LOGON_IDS_RID_COUNT   = (3)
%SECURITY_SERVICE_RID           = (&H00000006)
%SECURITY_ANONYMOUS_LOGON_RID   = (&H00000007)
%SECURITY_PROXY_RID             = (&H00000008)
%SECURITY_ENTERPRISE_CONTROLLERS_RID =(&H00000009)
%SECURITY_SERVER_LOGON_RID      = %SECURITY_ENTERPRISE_CONTROLLERS_RID
%SECURITY_PRINCIPAL_SELF_RID    = (&H0000000A)
%SECURITY_AUTHENTICATED_USER_RID= (&H0000000B)
%SECURITY_RESTRICTED_CODE_RID   = (&H0000000C)
%SECURITY_TERMINAL_SERVER_RID   = (&H0000000D)
%SECURITY_REMOTE_LOGON_RID      = (&H0000000E)
%SECURITY_THIS_ORGANIZATION_RID = (&H0000000F)
%SECURITY_IUSER_RID             = (&H00000011)
%SECURITY_LOCAL_SYSTEM_RID      = (&H00000012)
%SECURITY_LOCAL_SERVICE_RID     = (&H00000013)
%SECURITY_NETWORK_SERVICE_RID   = (&H00000014)

%SECURITY_NT_NON_UNIQUE         = (&H00000015)
%SECURITY_NT_NON_UNIQUE_SUB_AUTH_COUNT = (3)

%SECURITY_ENTERPRISE_READONLY_CONTROLLERS_RID =(&H00000016)

%SECURITY_BUILTIN_DOMAIN_RID    = (&H00000020)
%SECURITY_WRITE_RESTRICTED_CODE_RID =(&H00000021)


%SECURITY_PACKAGE_BASE_RID     = (&H00000040)
%SECURITY_PACKAGE_RID_COUNT    = (2)
%SECURITY_PACKAGE_NTLM_RID     = (&H0000000A)
%SECURITY_PACKAGE_SCHANNEL_RID = (&H0000000E)
%SECURITY_PACKAGE_DIGEST_RID   = (&H00000015)

%SECURITY_MIN_BASE_RID     = (&H00000050)

%SECURITY_SERVICE_ID_BASE_RID   =(&H00000050)
%SECURITY_SERVICE_ID_RID_COUNT  =(6)

%SECURITY_RESERVED_ID_BASE_RID  =(&H00000051)

%SECURITY_APPPOOL_ID_BASE_RID   =(&H00000052)
%SECURITY_APPPOOL_ID_RID_COUNT  =(6)

%SECURITY_VIRTUALSERVER_ID_BASE_RID  = (&H00000053)
%SECURITY_VIRTUALSERVER_ID_RID_COUNT = (6)

%SECURITY_MAX_BASE_RID       =(&H0000006F)

%SECURITY_MAX_ALWAYS_FILTERED    =(&H000003E7)
%SECURITY_MIN_NEVER_FILTERED     =(&H000003E8)

%SECURITY_OTHER_ORGANIZATION_RID =(&H000003E8)



'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                         '
' well-known domain relative sub-authority values (RIDs)...               '
'                                                                         '
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''



%DOMAIN_GROUP_RID_ENTERPRISE_READONLY_DOMAIN_CONTROLLERS =(&H000001F2)

%FOREST_USER_RID_MAX          = (&H000001F3)

' Well-known users ...

%DOMAIN_USER_RID_ADMIN        = (&H000001F4)
%DOMAIN_USER_RID_GUEST        = (&H000001F5)
%DOMAIN_USER_RID_KRBTGT       = (&H000001F6)

%DOMAIN_USER_RID_MAX          = (&H000003E7)


' well-known groups ...

%DOMAIN_GROUP_RID_ADMINS        =(&H00000200)
%DOMAIN_GROUP_RID_USERS         =(&H00000201)
%DOMAIN_GROUP_RID_GUESTS        =(&H00000202)
%DOMAIN_GROUP_RID_COMPUTERS     =(&H00000203)
%DOMAIN_GROUP_RID_CONTROLLERS   =(&H00000204)
%DOMAIN_GROUP_RID_CERT_ADMINS   =(&H00000205)
%DOMAIN_GROUP_RID_SCHEMA_ADMINS =(&H00000206)
%DOMAIN_GROUP_RID_ENTERPRISE_ADMINS =(&H00000207)
%DOMAIN_GROUP_RID_POLICY_ADMINS =(&H00000208)
%DOMAIN_GROUP_RID_READONLY_CONTROLLERS =(&H00000209)

' well-known aliases ...

%DOMAIN_ALIAS_RID_ADMINS                         =(&H00000220)
%DOMAIN_ALIAS_RID_USERS                          =(&H00000221)
%DOMAIN_ALIAS_RID_GUESTS                         =(&H00000222)
%DOMAIN_ALIAS_RID_POWER_USERS                    =(&H00000223)

%DOMAIN_ALIAS_RID_ACCOUNT_OPS                    =(&H00000224)
%DOMAIN_ALIAS_RID_SYSTEM_OPS                     =(&H00000225)
%DOMAIN_ALIAS_RID_PRINT_OPS                      =(&H00000226)
%DOMAIN_ALIAS_RID_BACKUP_OPS                     =(&H00000227)

%DOMAIN_ALIAS_RID_REPLICATOR                     =(&H00000228)
%DOMAIN_ALIAS_RID_RAS_SERVERS                    =(&H00000229)
%DOMAIN_ALIAS_RID_PREW2KCOMPACCESS               =(&H0000022A)
%DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS           =(&H0000022B)
%DOMAIN_ALIAS_RID_NETWORK_CONFIGURATION_OPS      =(&H0000022C)
%DOMAIN_ALIAS_RID_INCOMING_FOREST_TRUST_BUILDERS =(&H0000022D)

%DOMAIN_ALIAS_RID_MONITORING_USERS               =(&H0000022E)
%DOMAIN_ALIAS_RID_LOGGING_USERS                  =(&H0000022F)
%DOMAIN_ALIAS_RID_AUTHORIZATIONACCESS            =(&H00000230)
%DOMAIN_ALIAS_RID_TS_LICENSE_SERVERS             =(&H00000231)
%DOMAIN_ALIAS_RID_DCOM_USERS                     =(&H00000232)
%DOMAIN_ALIAS_RID_IUSERS                         =(&H00000238)
%DOMAIN_ALIAS_RID_CRYPTO_OPERATORS               =(&H00000239)
%DOMAIN_ALIAS_RID_CACHEABLE_PRINCIPALS_GROUP     =(&H0000023B)
%DOMAIN_ALIAS_RID_NON_CACHEABLE_PRINCIPALS_GROUP =(&H0000023C)
%DOMAIN_ALIAS_RID_EVENT_LOG_READERS_GROUP        =(&H0000023D)
%DOMAIN_ALIAS_RID_CERTSVC_DCOM_ACCESS_GROUP      =(&H0000023E)


'#define SECURITY_MANDATORY_LABEL_AUTHORITY          {0,0,0,0,0,16}
%SECURITY_MANDATORY_UNTRUSTED_RID          = (&H00000000)
%SECURITY_MANDATORY_LOW_RID                = (&H00001000)
%SECURITY_MANDATORY_MEDIUM_RID             = (&H00002000)
%SECURITY_MANDATORY_HIGH_RID               = (&H00003000)
%SECURITY_MANDATORY_SYSTEM_RID             = (&H00004000)
%SECURITY_MANDATORY_PROTECTED_PROCESS_RID  = (&H00005000)

'
' SECURITY_MANDATORY_MAXIMUM_USER_RID is the highest RID that
' can be set by a usermode caller.
'

%SECURITY_MANDATORY_MAXIMUM_USER_RID  = %SECURITY_MANDATORY_SYSTEM_RID

MACRO MANDATORY_LEVEL_TO_MANDATORY_RID(IL)=(IL * &H1000)



'
' Well known SID definitions for lookup.
'

MACRO WELL_KNOWN_SID_TYPE_enum=DWORD
ENUM WELL_KNOWN_SID_TYPE SINGULAR
    WinNullSid
    WinWorldSid
    WinLocalSid
    WinCreatorOwnerSid
    WinCreatorGroupSid
    WinCreatorOwnerServerSid
    WinCreatorGroupServerSid
    WinNtAuthoritySid
    WinDialupSid
    WinNetworkSid
    WinBatchSid
    WinInteractiveSid
    WinServiceSid
    WinAnonymousSid
    WinProxySid
    WinEnterpriseControllersSid
    WinSelfSid
    WinAuthenticatedUserSid
    WinRestrictedCodeSid
    WinTerminalServerSid
    WinRemoteLogonIdSid
    WinLogonIdsSid
    WinLocalSystemSid
    WinLocalServiceSid
    WinNetworkServiceSid
    WinBuiltinDomainSid
    WinBuiltinAdministratorsSid
    WinBuiltinUsersSid
    WinBuiltinGuestsSid
    WinBuiltinPowerUsersSid
    WinBuiltinAccountOperatorsSid
    WinBuiltinSystemOperatorsSid
    WinBuiltinPrintOperatorsSid
    WinBuiltinBackupOperatorsSid
    WinBuiltinReplicatorSid
    WinBuiltinPreWindows2000CompatibleAccessSid
    WinBuiltinRemoteDesktopUsersSid
    WinBuiltinNetworkConfigurationOperatorsSid
    WinAccountAdministratorSid
    WinAccountGuestSid
    WinAccountKrbtgtSid
    WinAccountDomainAdminsSid
    WinAccountDomainUsersSid
    WinAccountDomainGuestsSid
    WinAccountComputersSid
    WinAccountControllersSid
    WinAccountCertAdminsSid
    WinAccountSchemaAdminsSid
    WinAccountEnterpriseAdminsSid
    WinAccountPolicyAdminsSid
    WinAccountRasAndIasServersSid
    WinNTLMAuthenticationSid
    WinDigestAuthenticationSid
    WinSChannelAuthenticationSid
    WinThisOrganizationSid
    WinOtherOrganizationSid
    WinBuiltinIncomingForestTrustBuildersSid
    WinBuiltinPerfMonitoringUsersSid
    WinBuiltinPerfLoggingUsersSid
    WinBuiltinAuthorizationAccessSid
    WinBuiltinTerminalServerLicenseServersSid
    WinBuiltinDCOMUsersSid
    WinBuiltinIUsersSid
    WinIUserSid
    WinBuiltinCryptoOperatorsSid
    WinUntrustedLabelSid
    WinLowLabelSid
    WinMediumLabelSid
    WinHighLabelSid
    WinSystemLabelSid
    WinWriteRestrictedCodeSid
    WinCreatorOwnerRightsSid
    WinCacheablePrincipalsGroupSid
    WinNonCacheablePrincipalsGroupSid
    WinEnterpriseReadonlyControllersSid
    WinAccountReadonlyControllersSid
    WinBuiltinEventLogReadersGroup
    WinNewEnterpriseReadonlyControllersSid
    WinBuiltinCertSvcDComAccessGroup
END ENUM  ' WELL_KNOWN_SID_TYPE

'
' Allocate the System Luid.  The first 1000 LUIDs are reserved.
' Use #999 here (&H3e7 = 999)
'

%SYSTEM_LUID            = &H3e7  '{ &H3e7, &H0 }
%ANONYMOUS_LOGON_LUID   = &H3e6  '{ &H3e6, &H0 }
%LOCALSERVICE_LUID      = &H3e5  '{ &H3e5, &H0 }
%NETWORKSERVICE_LUID    = &H3e4  '{ &H3e4, &H0 }
%IUSER_LUID             = &H3e3  '{ &H3e3, &H0 }


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                    '
'                          User and Group related SID attributes     '
'                                                                    '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

'
' Group attributes
'

%SE_GROUP_MANDATORY               = (&H00000001)
%SE_GROUP_ENABLED_BY_DEFAULT      = (&H00000002)
%SE_GROUP_ENABLED                 = (&H00000004)
%SE_GROUP_OWNER                   = (&H00000008)
%SE_GROUP_USE_FOR_DENY_ONLY       = (&H00000010)
%SE_GROUP_INTEGRITY               = (&H00000020)
%SE_GROUP_INTEGRITY_ENABLED       = (&H00000040)
%SE_GROUP_LOGON_ID                = (&HC0000000)
%SE_GROUP_RESOURCE                = (&H20000000)

%SE_GROUP_VALID_ATTRIBUTES        = (%SE_GROUP_MANDATORY          OR _
                                     %SE_GROUP_ENABLED_BY_DEFAULT OR _
                                     %SE_GROUP_ENABLED            OR _
                                     %SE_GROUP_OWNER              OR _
                                     %SE_GROUP_USE_FOR_DENY_ONLY  OR _
                                     %SE_GROUP_LOGON_ID           OR _
                                     %SE_GROUP_RESOURCE           OR _
                                     %SE_GROUP_INTEGRITY          OR _
                                     %SE_GROUP_INTEGRITY_ENABLED)

'
' User attributes
'

' (None yet defined.)


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                    '
'                         ACL  and  ACE                              '
'                                                                    '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

'
'  Define an ACL and the ACE format.  The structure of an ACL header
'  followed by one or more ACEs.  Pictorally the structure of an ACL header
'  is as follows:
'
'       3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
'       1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'      +-------------------------------+---------------+---------------+
'      |            AclSize            |      Sbz1     |  AclRevision  |
'      +-------------------------------+---------------+---------------+
'      |              Sbz2             |           AceCount            |
'      +-------------------------------+-------------------------------+
'
'  The current AclRevision is defined to be ACL_REVISION.
'
'  AclSize is the size, in bytes, allocated for the ACL.  This includes
'  the ACL header, ACES, and remaining free space in the buffer.
'
'  AceCount is the number of ACES in the ACL.
'

' begin_wdm
' This is the *current* ACL revision

%ACL_REVISION    =(2)
%ACL_REVISION_DS =(4)

' This is the history of ACL revisions.  Add a new one whenever
' ACL_REVISION is updated

%ACL_REVISION1 = (1)
%ACL_REVISION2 = (2)
%MIN_ACL_REVISION = %ACL_REVISION2
%ACL_REVISION3 = (3)
%ACL_REVISION4 = (4)
%MAX_ACL_REVISION = %ACL_REVISION4

TYPE ACL
    AclRevision AS BYTE
    Sbz1        AS BYTE
    AclSize     AS WORD
    AceCount    AS WORD
    Sbz2        AS WORD
END TYPE

'
'  The structure of an ACE is a common ace header followed by ace type
'  specific data.  Pictorally the structure of the common ace header is
'  as follows:
'
'       3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
'       1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'      +---------------+-------+-------+---------------+---------------+
'      |            AceSize            |    AceFlags   |     AceType   |
'      +---------------+-------+-------+---------------+---------------+
'
'  AceType denotes the type of the ace, there are some predefined ace
'  types
'
'  AceSize is the size, in bytes, of ace.
'
'  AceFlags are the Ace flags for audit and inheritance, defined shortly.

TYPE ACE_HEADER
    AceType  AS BYTE
    AceFlags AS BYTE
    AceSize  AS WORD
END TYPE

'
'  The following are the predefined ace types that go into the AceType
'  field of an Ace header.
'

%ACCESS_MIN_MS_ACE_TYPE                  =(&H0)
%ACCESS_ALLOWED_ACE_TYPE                 =(&H0)
%ACCESS_DENIED_ACE_TYPE                  =(&H1)
%SYSTEM_AUDIT_ACE_TYPE                   =(&H2)
%SYSTEM_ALARM_ACE_TYPE                   =(&H3)
%ACCESS_MAX_MS_V2_ACE_TYPE               =(&H3)

%ACCESS_ALLOWED_COMPOUND_ACE_TYPE        =(&H4)
%ACCESS_MAX_MS_V3_ACE_TYPE               =(&H4)

%ACCESS_MIN_MS_OBJECT_ACE_TYPE           =(&H5)
%ACCESS_ALLOWED_OBJECT_ACE_TYPE          =(&H5)
%ACCESS_DENIED_OBJECT_ACE_TYPE           =(&H6)
%SYSTEM_AUDIT_OBJECT_ACE_TYPE            =(&H7)
%SYSTEM_ALARM_OBJECT_ACE_TYPE            =(&H8)
%ACCESS_MAX_MS_OBJECT_ACE_TYPE           =(&H8)

%ACCESS_MAX_MS_V4_ACE_TYPE               =(&H8)
%ACCESS_MAX_MS_ACE_TYPE                  =(&H8)

%ACCESS_ALLOWED_CALLBACK_ACE_TYPE        =(&H9)
%ACCESS_DENIED_CALLBACK_ACE_TYPE         =(&HA)
%ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE =(&HB)
%ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE  =(&HC)
%SYSTEM_AUDIT_CALLBACK_ACE_TYPE          =(&HD)
%SYSTEM_ALARM_CALLBACK_ACE_TYPE          =(&HE)
%SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE   =(&HF)
%SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE   =(&H10)

%SYSTEM_MANDATORY_LABEL_ACE_TYPE         =(&H11)
%ACCESS_MAX_MS_V5_ACE_TYPE               =(&H11)


'
'  The following are the inherit flags that go into the AceFlags field
'  of an Ace header.
'

%OBJECT_INHERIT_ACE              = (&H1)
%CONTAINER_INHERIT_ACE           = (&H2)
%NO_PROPAGATE_INHERIT_ACE        = (&H4)
%INHERIT_ONLY_ACE                = (&H8)
%INHERITED_ACE                   = (&H10)
%VALID_INHERIT_FLAGS             = (&H1F)


'  The following are the currently defined ACE flags that go into the
'  AceFlags field of an ACE header.  Each ACE type has its own set of
'  AceFlags.
'
'  SUCCESSFUL_ACCESS_ACE_FLAG - used only with system audit and alarm ACE
'  types to indicate that a message is generated for successful accesses.
'
'  FAILED_ACCESS_ACE_FLAG - used only with system audit and alarm ACE types
'  to indicate that a message is generated for failed accesses.
'

'
'  SYSTEM_AUDIT and SYSTEM_ALARM AceFlags
'
'  These control the signaling of audit and alarms for success or failure.
'

%SUCCESSFUL_ACCESS_ACE_FLAG     = (&H40)
%FAILED_ACCESS_ACE_FLAG         = (&H80?)


'
'  We'll define the structure of the predefined ACE types.  Pictorally
'  the structure of the predefined ACE's is as follows:
'
'       3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
'       1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'      +---------------+-------+-------+---------------+---------------+
'      |    AceFlags   | Resd  |Inherit|    AceSize    |     AceType   |
'      +---------------+-------+-------+---------------+---------------+
'      |                              Mask                             |
'      +---------------------------------------------------------------+
'      |                                                               |
'      +                                                               +
'      |                                                               |
'      +                              Sid                              +
'      |                                                               |
'      +                                                               +
'      |                                                               |
'      +---------------------------------------------------------------+
'
'  Mask is the access mask associated with the ACE.  This is either the
'  access allowed, access denied, audit, or alarm mask.
'
'  Sid is the Sid associated with the ACE.
'

'  The following are the four predefined ACE types.

'  Examine the AceType field in the Header to determine
'  which structure is appropriate to use for casting.


TYPE ACCESS_ALLOWED_ACE
    HEADER   AS ACE_HEADER
    Mask     AS ACCESS_MASK
    SidStart AS DWORD
END TYPE


TYPE ACCESS_DENIED_ACE
    HEADER   AS ACE_HEADER
    Mask     AS ACCESS_MASK
    SidStart AS DWORD
END TYPE

TYPE SYSTEM_AUDIT_ACE
    HEADER   AS ACE_HEADER
    Mask     AS ACCESS_MASK
    SidStart AS DWORD
END TYPE

TYPE SYSTEM_ALARM_ACE
    HEADER   AS ACE_HEADER
    Mask     AS ACCESS_MASK
    SidStart AS DWORD
END TYPE

TYPE SYSTEM_MANDATORY_LABEL_ACE
    HEADER   AS ACE_HEADER
    Mask     AS ACCESS_MASK
    SidStart AS DWORD
END TYPE

%SYSTEM_MANDATORY_LABEL_NO_WRITE_UP       = &H1
%SYSTEM_MANDATORY_LABEL_NO_READ_UP        = &H2
%SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP     = &H4

%SYSTEM_MANDATORY_LABEL_VALID_MASK = (%SYSTEM_MANDATORY_LABEL_NO_WRITE_UP   OR _
                                          %SYSTEM_MANDATORY_LABEL_NO_READ_UP    OR _
                                          %SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP)


TYPE ACCESS_ALLOWED_OBJECT_ACE
    HEADER              AS ACE_HEADER
    Mask                AS ACCESS_MASK
    Flags               AS DWORD
    ObjectType          AS GUID
    InheritedObjectType AS GUID
    SidStart            AS DWORD
END TYPE

TYPE ACCESS_DENIED_OBJECT_ACE
    HEADER              AS ACE_HEADER
    Mask                AS ACCESS_MASK
    Flags               AS DWORD
    ObjectType          AS GUID
    InheritedObjectType AS GUID
    SidStart            AS DWORD
END TYPE

TYPE SYSTEM_AUDIT_OBJECT_ACE
    HEADER              AS ACE_HEADER
    Mask                AS ACCESS_MASK
    Flags               AS DWORD
    ObjectType          AS GUID
    InheritedObjectType AS GUID
    SidStart            AS DWORD
END TYPE

TYPE SYSTEM_ALARM_OBJECT_ACE
    HEADER              AS ACE_HEADER
    Mask                AS ACCESS_MASK
    Flags               AS DWORD
    ObjectType          AS GUID
    InheritedObjectType AS GUID
    SidStart            AS DWORD
END TYPE

'
' Callback ace support in post Win2000.
' Resource managers can put their own data after Sidstart + Length of the sid
'

TYPE ACCESS_ALLOWED_CALLBACK_ACE
    HEADER   AS ACE_HEADER
    Mask     AS ACCESS_MASK
    SidStart AS DWORD
    ' Opaque resouce manager specific data
END TYPE

TYPE ACCESS_DENIED_CALLBACK_ACE
    HEADER   AS ACE_HEADER
    Mask     AS ACCESS_MASK
    SidStart AS DWORD
    ' Opaque resouce manager specific data
END TYPE

TYPE SYSTEM_AUDIT_CALLBACK_ACE
    HEADER   AS ACE_HEADER
    Mask     AS ACCESS_MASK
    SidStart AS DWORD
    ' Opaque resouce manager specific data
END TYPE

TYPE SYSTEM_ALARM_CALLBACK_ACE
    HEADER   AS ACE_HEADER
    Mask     AS ACCESS_MASK
    SidStart AS DWORD
    ' Opaque resouce manager specific data
END TYPE

TYPE ACCESS_ALLOWED_CALLBACK_OBJECT_ACE
    HEADER              AS ACE_HEADER
    Mask                AS ACCESS_MASK
    Flags               AS DWORD
    ObjectType          AS GUID
    InheritedObjectType AS GUID
    SidStart            AS DWORD
    ' Opaque resouce manager specific data
END TYPE

TYPE ACCESS_DENIED_CALLBACK_OBJECT_ACE
    HEADER              AS ACE_HEADER
    Mask                AS ACCESS_MASK
    Flags               AS DWORD
    ObjectType          AS GUID
    InheritedObjectType AS GUID
    SidStart            AS DWORD
    ' Opaque resouce manager specific data
END TYPE

TYPE SYSTEM_AUDIT_CALLBACK_OBJECT_ACE
    HEADER              AS ACE_HEADER
    Mask                AS ACCESS_MASK
    Flags               AS DWORD
    ObjectType          AS GUID
    InheritedObjectType AS GUID
    SidStart            AS DWORD
    ' Opaque resouce manager specific data
END TYPE

TYPE SYSTEM_ALARM_CALLBACK_OBJECT_ACE
    HEADER              AS ACE_HEADER
    Mask                AS ACCESS_MASK
    Flags               AS DWORD
    ObjectType          AS GUID
    InheritedObjectType AS GUID
    SidStart            AS DWORD
    ' Opaque resouce manager specific data
END TYPE

'
' Currently define Flags for "OBJECT" ACE types.
'

%ACE_OBJECT_TYPE_PRESENT           = &H1
%ACE_INHERITED_OBJECT_TYPE_PRESENT = &H2


'
'  The following declarations are used for setting and querying information
'  about and ACL.  First are the various information classes available to
'  the user.
'

MACRO ACL_INFORMATION_CLASS_enum=LONG
ENUM ACL_INFORMATION_CLASS SINGULAR
    AclRevisionInformation = 1
    AclSizeInformation
END ENUM

'
'  This record is returned/sent if the user is requesting/setting the
'  AclRevisionInformation
'

TYPE ACL_REVISION_INFORMATION
    AclRevision AS DWORD
END TYPE

'
'  This record is returned if the user is requesting AclSizeInformation
'

TYPE ACL_SIZE_INFORMATION
    AceCount      AS DWORD
    AclBytesInUse AS DWORD
    AclBytesFree  AS DWORD
END TYPE


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                    '
'                             SECURITY_DESCRIPTOR                    '
'                                                                    '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
'  Define the Security Descriptor and related data types.
'  This is an opaque data structure.
'

'
' Current security descriptor revision value
'

%SECURITY_DESCRIPTOR_REVISION   = (1)
%SECURITY_DESCRIPTOR_REVISION1  = (1)

MACRO SECURITY_DESCRIPTOR_MIN_LENGTH=(SIZEOF(SECURITY_DESCRIPTOR))


MACRO SECURITY_DESCRIPTOR_CONTROL=WORD

%SE_OWNER_DEFAULTED             = (&H0001)
%SE_GROUP_DEFAULTED             = (&H0002)
%SE_DACL_PRESENT                = (&H0004)
%SE_DACL_DEFAULTED              = (&H0008)
%SE_SACL_PRESENT                = (&H0010)
%SE_SACL_DEFAULTED              = (&H0020)
%SE_DACL_AUTO_INHERIT_REQ       = (&H0100)
%SE_SACL_AUTO_INHERIT_REQ       = (&H0200)
%SE_DACL_AUTO_INHERITED         = (&H0400)
%SE_SACL_AUTO_INHERITED         = (&H0800)
%SE_DACL_PROTECTED              = (&H1000)
%SE_SACL_PROTECTED              = (&H2000)
%SE_RM_CONTROL_VALID            = (&H4000)
%SE_SELF_RELATIVE               = (&H8000??)

'
'  Where:
'
'      SE_OWNER_DEFAULTED - This boolean flag, when set, indicates that the
'          SID pointed to by the Owner field was provided by a
'          defaulting mechanism rather than explicitly provided by the
'          original provider of the security descriptor.  This may
'          affect the treatment of the SID with respect to inheritence
'          of an owner.
'
'      SE_GROUP_DEFAULTED - This boolean flag, when set, indicates that the
'          SID in the Group field was provided by a defaulting mechanism
'          rather than explicitly provided by the original provider of
'          the security descriptor.  This may affect the treatment of
'          the SID with respect to inheritence of a primary group.
'
'      SE_DACL_PRESENT - This boolean flag, when set, indicates that the
'          security descriptor contains a discretionary ACL.  If this
'          flag is set and the Dacl field of the SECURITY_DESCRIPTOR is
'          null, then a null ACL is explicitly being specified.
'
'      SE_DACL_DEFAULTED - This boolean flag, when set, indicates that the
'          ACL pointed to by the Dacl field was provided by a defaulting
'          mechanism rather than explicitly provided by the original
'          provider of the security descriptor.  This may affect the
'          treatment of the ACL with respect to inheritence of an ACL.
'          This flag is ignored if the DaclPresent flag is not set.
'
'      SE_SACL_PRESENT - This boolean flag, when set,  indicates that the
'          security descriptor contains a system ACL pointed to by the
'          Sacl field.  If this flag is set and the Sacl field of the
'          SECURITY_DESCRIPTOR is null, then an empty (but present)
'          ACL is being specified.
'
'      SE_SACL_DEFAULTED - This boolean flag, when set, indicates that the
'          ACL pointed to by the Sacl field was provided by a defaulting
'          mechanism rather than explicitly provided by the original
'          provider of the security descriptor.  This may affect the
'          treatment of the ACL with respect to inheritence of an ACL.
'          This flag is ignored if the SaclPresent flag is not set.
'
'      SE_SELF_RELATIVE - This boolean flag, when set, indicates that the
'          security descriptor is in self-relative form.  In this form,
'          all fields of the security descriptor are contiguous in memory
'          and all pointer fields are expressed as offsets from the
'          beginning of the security descriptor.  This form is useful
'          for treating security descriptors as opaque data structures
'          for transmission in communication protocol or for storage on
'          secondary media.
'
'
'
' Pictorially the structure of a security descriptor is as follows:
'
'       3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
'       1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'      +---------------------------------------------------------------+
'      |            Control            |Reserved1 (SBZ)|   Revision    |
'      +---------------------------------------------------------------+
'      |                            Owner                              |
'      +---------------------------------------------------------------+
'      |                            Group                              |
'      +---------------------------------------------------------------+
'      |                            Sacl                               |
'      +---------------------------------------------------------------+
'      |                            Dacl                               |
'      +---------------------------------------------------------------+
'
' In general, this data structure should be treated opaquely to ensure future
' compatibility.
'
'

TYPE SECURITY_DESCRIPTOR_RELATIVE
    Revision AS BYTE
    Sbz1     AS BYTE
    CONTROL  AS SECURITY_DESCRIPTOR_CONTROL
    Owner    AS DWORD
    Group    AS DWORD
    Sacl     AS DWORD
    Dacl     AS DWORD
END TYPE

#IF NOT %DEF(%SECURITY_DESCRIPTOR_REVISION)
%SECURITY_DESCRIPTOR_REVISION = 1

TYPE SECURITY_DESCRIPTOR
    Revision AS BYTE
    Sbz1     AS BYTE
    CONTROL  AS SECURITY_DESCRIPTOR_CONTROL
    Owner    AS SID PTR
    Group    AS SID PTR
    Sacl     AS ACL PTR
    Dacl     AS ACL PTR
END TYPE

#ENDIF ' !SECURITY_DESCRIPTOR_REVISION


' Where:
'
'     Revision - Contains the revision level of the security
'         descriptor.  This allows this structure to be passed between
'         systems or stored on disk even though it is expected to
'         change in the future.
'
'     Control - A set of flags which qualify the meaning of the
'         security descriptor or individual fields of the security
'         descriptor.
'
'     Owner - is a pointer to an SID representing an object's owner.
'         If this field is null, then no owner SID is present in the
'         security descriptor.  If the security descriptor is in
'         self-relative form, then this field contains an offset to
'         the SID, rather than a pointer.
'
'     Group - is a pointer to an SID representing an object's primary
'         group.  If this field is null, then no primary group SID is
'         present in the security descriptor.  If the security descriptor
'         is in self-relative form, then this field contains an offset to
'         the SID, rather than a pointer.
'
'     Sacl - is a pointer to a system ACL.  This field value is only
'         valid if the DaclPresent control flag is set.  If the
'         SaclPresent flag is set and this field is null, then a null
'         ACL  is specified.  If the security descriptor is in
'         self-relative form, then this field contains an offset to
'         the ACL, rather than a pointer.
'
'     Dacl - is a pointer to a discretionary ACL.  This field value is
'         only valid if the DaclPresent control flag is set.  If the
'         DaclPresent flag is set and this field is null, then a null
'         ACL (unconditionally granting access) is specified.  If the
'         security descriptor is in self-relative form, then this field
'         contains an offset to the ACL, rather than a pointer.
'




''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                    '
'               Object Type list for AccessCheckByType               '
'                                                                    '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

TYPE OBJECT_TYPE_LIST
    Level      AS WORD
    Sbz        AS WORD
    ObjectType AS GUID PTR
END TYPE

'
' DS values for Level
'

%ACCESS_OBJECT_GUID       = 0
%ACCESS_PROPERTY_SET_GUID = 1
%ACCESS_PROPERTY_GUID     = 2

%ACCESS_MAX_LEVEL         = 4

'
' Parameters to NtAccessCheckByTypeAndAditAlarm
'

MACRO AUDIT_EVENT_TYPE_enum=LONG
ENUM AUDIT_EVENT_TYPE SINGULAR
    AuditEventObjectAccess
    AuditEventDirectoryServiceAccess
END ENUM

%AUDIT_ALLOW_NO_PRIVILEGE = &H1

'
' DS values for Source and ObjectTypeName
'

$ACCESS_DS_SOURCE_A = "DS"
$$ACCESS_DS_SOURCE_W = "DS"$$
$ACCESS_DS_OBJECT_TYPE_NAME_A = "Directory Service Object"
$$ACCESS_DS_OBJECT_TYPE_NAME_W = "Directory Service Object"$$


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                    '
'               Privilege Related Data Structures                    '
'                                                                    '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

'
' Privilege attributes
'

%SE_PRIVILEGE_ENABLED_BY_DEFAULT =(&H00000001)
%SE_PRIVILEGE_ENABLED            =(&H00000002)
%SE_PRIVILEGE_REMOVED            =(&H00000004)
%SE_PRIVILEGE_USED_FOR_ACCESS    =(&H80000000)

%SE_PRIVILEGE_VALID_ATTRIBUTES   =(%SE_PRIVILEGE_ENABLED_BY_DEFAULT OR _
                                        %SE_PRIVILEGE_ENABLED            OR _
                                        %SE_PRIVILEGE_REMOVED            OR _
                                        %SE_PRIVILEGE_USED_FOR_ACCESS)


'
' Privilege Set Control flags
'

%PRIVILEGE_SET_ALL_NECESSARY   =(1)

'
'  Privilege Set - This is defined for a privilege set of one.
'                  If more than one privilege is needed, then this structure
'                  will need to be allocated with more space.
'
'  Note: don't change this structure without fixing the INITIAL_PRIVILEGE_SET
'  structure (defined in se.h)
'

TYPE PRIVILEGE_SET
    PrivilegeCount AS DWORD
    CONTROL        AS DWORD
    Privilege(0)   AS LUID_AND_ATTRIBUTES
END TYPE


''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                    '
'               NT Defined Privileges                                '
'                                                                    '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

$SE_CREATE_TOKEN_NAME            = "SeCreateTokenPrivilege"
$SE_ASSIGNPRIMARYTOKEN_NAME      = "SeAssignPrimaryTokenPrivilege"
$SE_LOCK_MEMORY_NAME             = "SeLockMemoryPrivilege"
$SE_INCREASE_QUOTA_NAME          = "SeIncreaseQuotaPrivilege"
$SE_UNSOLICITED_INPUT_NAME       = "SeUnsolicitedInputPrivilege"
$SE_MACHINE_ACCOUNT_NAME         = "SeMachineAccountPrivilege"
$SE_TCB_NAME                     = "SeTcbPrivilege"
$SE_SECURITY_NAME                = "SeSecurityPrivilege"
$SE_TAKE_OWNERSHIP_NAME          = "SeTakeOwnershipPrivilege"
$SE_LOAD_DRIVER_NAME             = "SeLoadDriverPrivilege"
$SE_SYSTEM_PROFILE_NAME          = "SeSystemProfilePrivilege"
$SE_SYSTEMTIME_NAME              = "SeSystemtimePrivilege"
$SE_PROF_SINGLE_PROCESS_NAME     = "SeProfileSingleProcessPrivilege"
$SE_INC_BASE_PRIORITY_NAME       = "SeIncreaseBasePriorityPrivilege"
$SE_CREATE_PAGEFILE_NAME         = "SeCreatePagefilePrivilege"
$SE_CREATE_PERMANENT_NAME        = "SeCreatePermanentPrivilege"
$SE_BACKUP_NAME                  = "SeBackupPrivilege"
$SE_RESTORE_NAME                 = "SeRestorePrivilege"
$SE_SHUTDOWN_NAME                = "SeShutdownPrivilege"
$SE_DEBUG_NAME                   = "SeDebugPrivilege"
$SE_AUDIT_NAME                   = "SeAuditPrivilege"
$SE_SYSTEM_ENVIRONMENT_NAME      = "SeSystemEnvironmentPrivilege"
$SE_CHANGE_NOTIFY_NAME           = "SeChangeNotifyPrivilege"
$SE_REMOTE_SHUTDOWN_NAME         = "SeRemoteShutdownPrivilege"
$SE_UNDOCK_NAME                  = "SeUndockPrivilege"
$SE_SYNC_AGENT_NAME              = "SeSyncAgentPrivilege"
$SE_ENABLE_DELEGATION_NAME       = "SeEnableDelegationPrivilege"
$SE_MANAGE_VOLUME_NAME           = "SeManageVolumePrivilege"
$SE_IMPERSONATE_NAME             = "SeImpersonatePrivilege"
$SE_CREATE_GLOBAL_NAME           = "SeCreateGlobalPrivilege"
$SE_TRUSTED_CREDMAN_ACCESS_NAME  = "SeTrustedCredManAccessPrivilege"
$SE_RELABEL_NAME                 = "SeRelabelPrivilege"
$SE_INC_WORKING_SET_NAME         = "SeIncreaseWorkingSetPrivilege"
$SE_TIME_ZONE_NAME               = "SeTimeZonePrivilege"
$SE_CREATE_SYMBOLIC_LINK_NAME    = "SeCreateSymbolicLinkPrivilege"

$$SE_CREATE_TOKEN_NAME            = "SeCreateTokenPrivilege"$$
$$SE_ASSIGNPRIMARYTOKEN_NAME      = "SeAssignPrimaryTokenPrivilege"$$
$$SE_LOCK_MEMORY_NAME             = "SeLockMemoryPrivilege"$$
$$SE_INCREASE_QUOTA_NAME          = "SeIncreaseQuotaPrivilege"$$
$$SE_UNSOLICITED_INPUT_NAME       = "SeUnsolicitedInputPrivilege"$$
$$SE_MACHINE_ACCOUNT_NAME         = "SeMachineAccountPrivilege"$$
$$SE_TCB_NAME                     = "SeTcbPrivilege"$$
$$SE_SECURITY_NAME                = "SeSecurityPrivilege"$$
$$SE_TAKE_OWNERSHIP_NAME          = "SeTakeOwnershipPrivilege"$$
$$SE_LOAD_DRIVER_NAME             = "SeLoadDriverPrivilege"$$
$$SE_SYSTEM_PROFILE_NAME          = "SeSystemProfilePrivilege"$$
$$SE_SYSTEMTIME_NAME              = "SeSystemtimePrivilege"$$
$$SE_PROF_SINGLE_PROCESS_NAME     = "SeProfileSingleProcessPrivilege"$$
$$SE_INC_BASE_PRIORITY_NAME       = "SeIncreaseBasePriorityPrivilege"$$
$$SE_CREATE_PAGEFILE_NAME         = "SeCreatePagefilePrivilege"$$
$$SE_CREATE_PERMANENT_NAME        = "SeCreatePermanentPrivilege"$$
$$SE_BACKUP_NAME                  = "SeBackupPrivilege"$$
$$SE_RESTORE_NAME                 = "SeRestorePrivilege"$$
$$SE_SHUTDOWN_NAME                = "SeShutdownPrivilege"$$
$$SE_DEBUG_NAME                   = "SeDebugPrivilege"$$
$$SE_AUDIT_NAME                   = "SeAuditPrivilege"$$
$$SE_SYSTEM_ENVIRONMENT_NAME      = "SeSystemEnvironmentPrivilege"$$
$$SE_CHANGE_NOTIFY_NAME           = "SeChangeNotifyPrivilege"$$
$$SE_REMOTE_SHUTDOWN_NAME         = "SeRemoteShutdownPrivilege"$$
$$SE_UNDOCK_NAME                  = "SeUndockPrivilege"$$
$$SE_SYNC_AGENT_NAME              = "SeSyncAgentPrivilege"$$
$$SE_ENABLE_DELEGATION_NAME       = "SeEnableDelegationPrivilege"$$
$$SE_MANAGE_VOLUME_NAME           = "SeManageVolumePrivilege"$$
$$SE_IMPERSONATE_NAME             = "SeImpersonatePrivilege"$$
$$SE_CREATE_GLOBAL_NAME           = "SeCreateGlobalPrivilege"$$
$$SE_TRUSTED_CREDMAN_ACCESS_NAME  = "SeTrustedCredManAccessPrivilege"$$
$$SE_RELABEL_NAME                 = "SeRelabelPrivilege"$$
$$SE_INC_WORKING_SET_NAME         = "SeIncreaseWorkingSetPrivilege"$$
$$SE_TIME_ZONE_NAME               = "SeTimeZonePrivilege"$$
$$SE_CREATE_SYMBOLIC_LINK_NAME    = "SeCreateSymbolicLinkPrivilege"$$



''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                '
'           Security Quality Of Service                          '
'                                                                '
'                                                                '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

' begin_wdm
'
' Impersonation Level
'
' Impersonation level is represented by a pair of bits in Windows.
' If a new impersonation level is added or lowest value is changed from
' 0 to something else, fix the Windows CreateFile call.
'

MACRO SECURITY_IMPERSONATION_LEVEL_enum=LONG
ENUM SECURITY_IMPERSONATION_LEVEL SINGULAR
    SecurityAnonymous
    SecurityIdentification
    SecurityImpersonation
    SecurityDelegation
END ENUM

%SECURITY_MAX_IMPERSONATION_LEVEL = %SecurityDelegation
%SECURITY_MIN_IMPERSONATION_LEVEL = %SecurityAnonymous
%DEFAULT_IMPERSONATION_LEVEL      = %SecurityImpersonation

MACRO VALID_IMPERSONATION_LEVEL(L)=(((L) >= %SECURITY_MIN_IMPERSONATION_LEVEL) AND ((L) <= %SECURITY_MAX_IMPERSONATION_LEVEL))

''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'                                                                '
'           Token Object Definitions                             '
'                                                                '
'                                                                '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''


'
' Token Specific Access Rights.
'

%TOKEN_ASSIGN_PRIMARY    =(&H0001)
%TOKEN_DUPLICATE         =(&H0002)
%TOKEN_IMPERSONATE       =(&H0004)
%TOKEN_QUERY             =(&H0008)
%TOKEN_QUERY_SOURCE      =(&H0010)
%TOKEN_ADJUST_PRIVILEGES =(&H0020)
%TOKEN_ADJUST_GROUPS     =(&H0040)
%TOKEN_ADJUST_DEFAULT    =(&H0080)
%TOKEN_ADJUST_SESSIONID  =(&H0100)

%TOKEN_ALL_ACCESS_P =(%STANDARD_RIGHTS_REQUIRED  OR _
                         %TOKEN_ASSIGN_PRIMARY      OR _
                         %TOKEN_DUPLICATE           OR _
                         %TOKEN_IMPERSONATE         OR _
                         %TOKEN_QUERY               OR _
                         %TOKEN_QUERY_SOURCE        OR _
                         %TOKEN_ADJUST_PRIVILEGES   OR _
                         %TOKEN_ADJUST_GROUPS       OR _
                         %TOKEN_ADJUST_DEFAULT )

#IF ((%DEF(%WIN32_WINNT) AND (%WIN32_WINNT > &H0400)) OR (NOT %DEF(%WIN32_WINNT)))
%TOKEN_ALL_ACCESS = (%TOKEN_ALL_ACCESS_P OR _
                         %TOKEN_ADJUST_SESSIONID )
#ELSE
%TOKEN_ALL_ACCESS = (%TOKEN_ALL_ACCESS_P)
#ENDIF

%TOKEN_READ       =(%STANDARD_RIGHTS_READ      OR _
                         %TOKEN_QUERY)


%TOKEN_WRITE      =(%STANDARD_RIGHTS_WRITE     OR _
                         %TOKEN_ADJUST_PRIVILEGES   OR _
                         %TOKEN_ADJUST_GROUPS       OR _
                         %TOKEN_ADJUST_DEFAULT)

%TOKEN_EXECUTE    =(%STANDARD_RIGHTS_EXECUTE)

'
'
' Token Types
'

MACRO TOKEN_TYPE_enum=LONG
ENUM TOKEN_TYPE SINGULAR
    TokenPrimary       = 1
    TokenImpersonation
END ENUM

'
' Token elevation values describe the relative strength of a given token.
' A full token is a token with all groups and privileges to which the principal
' is authorized.  A limited token is one with some groups or privileges removed.
'

MACRO TOKEN_ELEVATION_TYPE_enum=LONG
ENUM TOKEN_ELEVATION_TYPE SINGULAR
    TokenElevationTypeDefault = 1
    TokenElevationTypeFull
    TokenElevationTypeLimited
END ENUM

'
' Token Information Classes.
'

MACRO TOKEN_INFORMATION_CLASS_enum=LONG
ENUM TOKEN_INFORMATION_CLASS SINGULAR
    TokenUser = 1
    TokenGroups
    TokenPrivileges
    TokenOwner
    TokenPrimaryGroup
    TokenDefaultDacl
    TokenSource
    TokenType
    TokenImpersonationLevel
    TokenStatistics
    TokenRestrictedSids
    TokenSessionId
    TokenGroupsAndPrivileges
    TokenSessionReference
    TokenSandBoxInert
    TokenAuditPolicy
    TokenOrigin
    TokenElevationType
    TokenLinkedToken
    TokenElevation
    TokenHasRestrictions
    TokenAccessInformation
    TokenVirtualizationAllowed
    TokenVirtualizationEnabled
    TokenIntegrityLevel
    TokenUIAccess
    TokenMandatoryPolicy
    TokenLogonSid
    MaxTokenInfoClass  ' MaxTokenInfoClass should always be the last enum
END ENUM  ' TOKEN_INFORMATION_CLASS

'
' Token information class structures
'


TYPE TOKEN_USER
    USER AS SID_AND_ATTRIBUTES
END TYPE

TYPE TOKEN_GROUPS
    GroupCount AS DWORD
    Groups(0) AS SID_AND_ATTRIBUTES
END TYPE


TYPE TOKEN_PRIVILEGES
    PrivilegeCount AS DWORD
    Privileges(0) AS LUID_AND_ATTRIBUTES
END TYPE


TYPE TOKEN_OWNER
    Owner AS SID PTR
END TYPE


TYPE TOKEN_PRIMARY_GROUP
    PrimaryGroup AS SID PTR
END TYPE


TYPE TOKEN_DEFAULT_DACL
    DefaultDacl AS ACL PTR
END TYPE

TYPE TOKEN_GROUPS_AND_PRIVILEGES
    SidCount            AS DWORD
    SidLength           AS DWORD
    Sids                AS SID_AND_ATTRIBUTES PTR
    RestrictedSidCount  AS DWORD
    RestrictedSidLength AS DWORD
    RestrictedSids      AS SID_AND_ATTRIBUTES PTR
    PrivilegeCount      AS DWORD
    PrivilegeLength     AS DWORD
    Privileges          AS LUID_AND_ATTRIBUTES PTR
    AuthenticationId    AS QUAD ' LUID
END TYPE

TYPE TOKEN_LINKED_TOKEN
    LinkedToken AS DWORD
END TYPE

TYPE TOKEN_ELEVATION
    TokenIsElevated AS DWORD
END TYPE

TYPE TOKEN_MANDATORY_LABEL
    LABEL AS SID_AND_ATTRIBUTES
END TYPE

%TOKEN_MANDATORY_POLICY_OFF             = &H0
%TOKEN_MANDATORY_POLICY_NO_WRITE_UP     = &H1
%TOKEN_MANDATORY_POLICY_NEW_PROCESS_MIN = &H2

%TOKEN_MANDATORY_POLICY_VALID_MASK      = (%TOKEN_MANDATORY_POLICY_NO_WRITE_UP OR _
                                               %TOKEN_MANDATORY_POLICY_NEW_PROCESS_MIN)

TYPE TOKEN_MANDATORY_POLICY
    Policy AS DWORD
END TYPE

TYPE TOKEN_ACCESS_INFORMATION
    SidHash            AS SID_AND_ATTRIBUTES_HASH PTR
    RestrictedSidHash  AS SID_AND_ATTRIBUTES_HASH PTR
    Privileges         AS TOKEN_PRIVILEGES PTR
    AuthenticationId   AS QUAD ' LUID
    TokenType          AS LONG ' TOKEN_TYPE
    ImpersonationLevel AS LONG ' SECURITY_IMPERSONATION_LEVEL
    MandatoryPolicy    AS TOKEN_MANDATORY_POLICY
    Flags              AS DWORD
END TYPE

'
' Valid bits for each TOKEN_AUDIT_POLICY policy mask field.
'

%POLICY_AUDIT_SUBCATEGORY_COUNT = (52)

TYPE TOKEN_AUDIT_POLICY
    PerUserPolicy(%POLICY_AUDIT_SUBCATEGORY_COUNT \ 2) AS BYTE
END TYPE

%TOKEN_SOURCE_LENGTH = 8

TYPE TOKEN_SOURCE
    SourceName(%TOKEN_SOURCE_LENGTH - 1) AS BYTE
    SourceIdentifier AS QUAD ' LUID
END TYPE


TYPE TOKEN_STATISTICS
    TokenId            AS QUAD ' LUID
    AuthenticationId   AS QUAD ' LUID
    ExpirationTime     AS QUAD ' LARGE_INTEGER
    TokenType          AS LONG ' TOKEN_TYPE
    ImpersonationLevel AS LONG ' SECURITY_IMPERSONATION_LEVEL
    DynamicCharged     AS DWORD
    DynamicAvailable   AS DWORD
    GroupCount         AS DWORD
    PrivilegeCount     AS DWORD
    ModifiedId         AS QUAD ' LUID
END TYPE


TYPE TOKEN_CONTROL
    TokenId          AS QUAD ' LUID
    AuthenticationId AS QUAD ' LUID
    ModifiedId       AS QUAD ' LUID
    TokenSource      AS TOKEN_SOURCE
END TYPE

TYPE TOKEN_ORIGIN
    OriginatingLogonSession AS QUAD ' LUID
END TYPE

MACRO MANDATORY_LEVEL_enum=LONG
ENUM MANDATORY_LEVEL SINGULAR
    MandatoryLevelUntrusted
    MandatoryLevelLow
    MandatoryLevelMedium
    MandatoryLevelHigh
    MandatoryLevelSystem
    MandatoryLevelSecureProcess
    MandatoryLevelCount
END ENUM

'
' Security Tracking Mode
'

%SECURITY_DYNAMIC_TRACKING   = %TRUE
%SECURITY_STATIC_TRACKING    = %FALSE

MACRO SECURITY_CONTEXT_TRACKING_MODE=BYTE



'
' Quality Of Service
'

TYPE SECURITY_QUALITY_OF_SERVICE
    Length              AS DWORD
    ImpersonationLevel  AS LONG ' SECURITY_IMPERSONATION_LEVEL
    ContextTrackingMode AS SECURITY_CONTEXT_TRACKING_MODE
    EffectiveOnly       AS BYTE ' BOOLEAN
END TYPE


'
' Used to represent information related to a thread impersonation
'

TYPE SE_IMPERSONATION_STATE
    Token         AS DWORD ' PACCESS_TOKEN = PVOID
    CopyOnOpen    AS BYTE  ' BOOLEAN
    EffectiveOnly AS BYTE  ' BOOLEAN
    Level         AS LONG  ' SECURITY_IMPERSONATION_LEVEL
END TYPE

%DISABLE_MAX_PRIVILEGE = &H1
%SANDBOX_INERT         = &H2
%LUA_TOKEN             = &H4
%WRITE_RESTRICTED      = &H8

MACRO SECURITY_INFORMATION=DWORD

%OWNER_SECURITY_INFORMATION     = (&H00000001)
%GROUP_SECURITY_INFORMATION     = (&H00000002)
%DACL_SECURITY_INFORMATION      = (&H00000004)
%SACL_SECURITY_INFORMATION      = (&H00000008)
%LABEL_SECURITY_INFORMATION     = (&H00000010)

%PROTECTED_DACL_SECURITY_INFORMATION   = (&H80000000)
%PROTECTED_SACL_SECURITY_INFORMATION   = (&H40000000)
%UNPROTECTED_DACL_SECURITY_INFORMATION = (&H20000000)
%UNPROTECTED_SACL_SECURITY_INFORMATION = (&H10000000)

%PROCESS_TERMINATE                 = (&H0001)
%PROCESS_CREATE_THREAD             = (&H0002)
%PROCESS_SET_SESSIONID             = (&H0004)
%PROCESS_VM_OPERATION              = (&H0008)
%PROCESS_VM_READ                   = (&H0010)
%PROCESS_VM_WRITE                  = (&H0020)
%PROCESS_DUP_HANDLE                = (&H0040)
%PROCESS_CREATE_PROCESS            = (&H0080)
%PROCESS_SET_QUOTA                 = (&H0100)
%PROCESS_SET_INFORMATION           = (&H0200)
%PROCESS_QUERY_INFORMATION         = (&H0400)
%PROCESS_SUSPEND_RESUME            = (&H0800)
%PROCESS_QUERY_LIMITED_INFORMATION = (&H1000)

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%PROCESS_ALL_ACCESS      = (%STANDARD_RIGHTS_REQUIRED OR %SYNCHRONIZE OR _
                                   &HFFFF??)
#ELSE
%PROCESS_ALL_ACCESS      = (%STANDARD_RIGHTS_REQUIRED OR %SYNCHRONIZE OR _
                                   &HFFF)
#ENDIF

#IF %DEF(%WIN64)

%MAXIMUM_PROCESSORS = 64

#ELSE

%MAXIMUM_PROCESSORS = 32

#ENDIF

%THREAD_TERMINATE                 = (&H0001)
%THREAD_SUSPEND_RESUME            = (&H0002)
%THREAD_GET_CONTEXT               = (&H0008)
%THREAD_SET_CONTEXT               = (&H0010)
%THREAD_QUERY_INFORMATION         = (&H0040)
%THREAD_SET_INFORMATION           = (&H0020)
%THREAD_SET_THREAD_TOKEN          = (&H0080)
%THREAD_IMPERSONATE               = (&H0100)
%THREAD_DIRECT_IMPERSONATION      = (&H0200)
' begin_wdm
%THREAD_SET_LIMITED_INFORMATION   = (&H0400)  ' winnt
%THREAD_QUERY_LIMITED_INFORMATION = (&H0800)  ' winnt

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%THREAD_ALL_ACCESS       = (%STANDARD_RIGHTS_REQUIRED OR %SYNCHRONIZE OR _
                                   &HFFFF??)
#ELSE
%THREAD_ALL_ACCESS       = (%STANDARD_RIGHTS_REQUIRED OR %SYNCHRONIZE OR _
                                   &H3FF)
#ENDIF
%JOB_OBJECT_ASSIGN_PROCESS          = (&H0001)
%JOB_OBJECT_SET_ATTRIBUTES          = (&H0002)
%JOB_OBJECT_QUERY                   = (&H0004)
%JOB_OBJECT_TERMINATE               = (&H0008)
%JOB_OBJECT_SET_SECURITY_ATTRIBUTES = (&H0010)
%JOB_OBJECT_ALL_ACCESS     = (%STANDARD_RIGHTS_REQUIRED OR %SYNCHRONIZE OR _
                                        &H1F )

TYPE JOB_SET_ARRAY
    JobHandle   AS DWORD   ' Handle to job object to insert
    MemberLevel AS DWORD   ' Level of this job in the set. Must be > 0. Can be sparse.
    Flags       AS DWORD   ' Unused. Must be zero
END TYPE

%FLS_MAXIMUM_AVAILABLE = 128
%TLS_MINIMUM_AVAILABLE = 64

#IF %DEF(%MSC_EXTENSIONS)
UNION NT_TIB_union
    FiberData AS DWORD
    Version   AS DWORD
END UNION
#ENDIF

TYPE NT_TIB
    ExceptionList AS DWORD ' EXCEPTION_REGISTRATION_RECORD PTR [type is not defined]
    StackBase     AS DWORD
    StackLimit    AS DWORD
    SubSystemTib  AS DWORD
#IF %DEF(%MSC_EXTENSIONS)
    NT_TIB_union
#ELSE
    FiberData     AS DWORD
#ENDIF
    ArbitraryUserPointer AS DWORD
    Self          AS NT_TIB PTR
END TYPE


'
' 32 and 64 bit specific version for wow64 and the debugger
'
MACRO NT_TIB32=NT_TIB

UNION NT_TIB64_union
    FiberData AS QUAD  ' DWORD64
    Version   AS DWORD
END UNION

TYPE NT_TIB64
    ExceptionList AS QUAD  ' DWORD64
    StackBase     AS QUAD  ' DWORD64
    StackLimit    AS QUAD  ' DWORD64
    SubSystemTib  AS QUAD  ' DWORD64
#IF %DEF(%MSC_EXTENSIONS)
    NT_TIB64_union
#ELSE
    FiberData     AS QUAD  ' DWORD64
#ENDIF
    ArbitraryUserPointer AS QUAD  ' DWORD64
    Self          AS QUAD  ' DWORD64
END TYPE



%THREAD_BASE_PRIORITY_LOWRT = 15  ' value that gets a thread to LowRealtime-1
%THREAD_BASE_PRIORITY_MAX   = 2   ' maximum thread base priority boost
%THREAD_BASE_PRIORITY_MIN   = (-2)  ' minimum thread base priority boost
%THREAD_BASE_PRIORITY_IDLE  = (-15) ' value that gets a thread to idle


TYPE QUOTA_LIMITS
    PagedPoolLimit        AS DWORD
    NonPagedPoolLimit     AS DWORD
    MinimumWorkingSetSize AS DWORD
    MaximumWorkingSetSize AS DWORD
    PagefileLimit         AS DWORD
    TimeLimit             AS QUAD ' LARGE_INTEGER
END TYPE

%QUOTA_LIMITS_HARDWS_MIN_ENABLE  = &H00000001
%QUOTA_LIMITS_HARDWS_MIN_DISABLE = &H00000002
%QUOTA_LIMITS_HARDWS_MAX_ENABLE  = &H00000004
%QUOTA_LIMITS_HARDWS_MAX_DISABLE = &H00000008
%QUOTA_LIMITS_USE_DEFAULT_LIMITS = &H00000010

TYPE RATE_QUOTA_LIMIT_type
    RatePercent AS BIT * 7 IN DWORD
    Reserved0   AS BIT * 25
END TYPE

UNION RATE_QUOTA_LIMIT
    RateData AS DWORD
    RATE_QUOTA_LIMIT_type
END UNION

TYPE QUOTA_LIMITS_EX
    PagedPoolLimit        AS DWORD
    NonPagedPoolLimit     AS DWORD
    MinimumWorkingSetSize AS DWORD
    MaximumWorkingSetSize AS DWORD
    PagefileLimit         AS DWORD             ' Limit expressed in pages
    TimeLimit             AS QUAD ' LARGE_INTEGER
    WorkingSetLimit       AS DWORD             ' Limit expressed in pages
    Reserved2             AS DWORD
    Reserved3             AS DWORD
    Reserved4             AS DWORD
    Flags                 AS DWORD
    CpuRateLimit          AS RATE_QUOTA_LIMIT
END TYPE

TYPE IO_COUNTERS
    ReadOperationCount  AS QUAD
    WriteOperationCount AS QUAD
    OtherOperationCount AS QUAD
    ReadTransferCount   AS QUAD
    WriteTransferCount  AS QUAD
    OtherTransferCount  AS QUAD
END TYPE

%MAX_HW_COUNTERS = 16
%THREAD_PROFILING_FLAG_DISPATCH = &H00000001

MACRO HARDWARE_COUNTER_TYPE_enum=LONG
ENUM HARDWARE_COUNTER_TYPE SINGULAR
    PMCCounter
    MaxHardwareCounterType
END ENUM

TYPE JOBOBJECT_BASIC_ACCOUNTING_INFORMATION
    TotalUserTime             AS QUAD ' LARGE_INTEGER
    TotalKernelTime           AS QUAD ' LARGE_INTEGER
    ThisPeriodTotalUserTime   AS QUAD ' LARGE_INTEGER
    ThisPeriodTotalKernelTime AS QUAD ' LARGE_INTEGER
    TotalPageFaultCount       AS DWORD
    TotalProcesses            AS DWORD
    ActiveProcesses           AS DWORD
    TotalTerminatedProcesses  AS DWORD
END TYPE

TYPE JOBOBJECT_BASIC_LIMIT_INFORMATION
    PerProcessUserTimeLimit AS QUAD ' LARGE_INTEGER
    PerJobUserTimeLimit     AS QUAD ' LARGE_INTEGER
    LimitFlags              AS DWORD
    MinimumWorkingSetSize   AS DWORD
    MaximumWorkingSetSize   AS DWORD
    ActiveProcessLimit      AS DWORD
    Affinity                AS DWORD
    PriorityClass           AS DWORD
    SchedulingClass         AS DWORD
END TYPE

TYPE JOBOBJECT_EXTENDED_LIMIT_INFORMATION
    BasicLimitInformation AS JOBOBJECT_BASIC_LIMIT_INFORMATION
    IoInfo                AS IO_COUNTERS
    ProcessMemoryLimit    AS DWORD
    JobMemoryLimit        AS DWORD
    PeakProcessMemoryUsed AS DWORD
    PeakJobMemoryUsed     AS DWORD
END TYPE

TYPE JOBOBJECT_BASIC_PROCESS_ID_LIST
    NumberOfAssignedProcesses AS DWORD
    NumberOfProcessIdsInList  AS DWORD
    ProcessIdList(0)          AS DWORD
END TYPE

TYPE JOBOBJECT_BASIC_UI_RESTRICTIONS
    UIRestrictionsClass AS DWORD
END TYPE

'
' N.B. The JOBOBJECT_SECURITY_LIMIT_INFORMATION information class is no longer supported.
'

TYPE JOBOBJECT_SECURITY_LIMIT_INFORMATION
    SecurityLimitFlags AS DWORD
    JobToken           AS DWORD
    SidsToDisable      AS TOKEN_GROUPS PTR
    PrivilegesToDelete AS TOKEN_PRIVILEGES PTR
    RestrictedSids     AS TOKEN_GROUPS
END TYPE

TYPE JOBOBJECT_END_OF_JOB_TIME_INFORMATION
    EndOfJobTimeAction AS DWORD
END TYPE

TYPE JOBOBJECT_ASSOCIATE_COMPLETION_PORT
    CompletionKey  AS DWORD
    CompletionPort AS DWORD
END TYPE

TYPE JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION
    BasicInfo AS JOBOBJECT_BASIC_ACCOUNTING_INFORMATION
    IoInfo    AS IO_COUNTERS
END TYPE

TYPE JOBOBJECT_JOBSET_INFORMATION
    MemberLevel AS DWORD
END TYPE

%JOB_OBJECT_TERMINATE_AT_END_OF_JOB = 0
%JOB_OBJECT_POST_AT_END_OF_JOB      = 1

'
' Completion Port Messages for job objects
'
' These values are returned via the lpNumberOfBytesTransferred parameter
'

%JOB_OBJECT_MSG_END_OF_JOB_TIME        = 1
%JOB_OBJECT_MSG_END_OF_PROCESS_TIME    = 2
%JOB_OBJECT_MSG_ACTIVE_PROCESS_LIMIT   = 3
%JOB_OBJECT_MSG_ACTIVE_PROCESS_ZERO    = 4
%JOB_OBJECT_MSG_NEW_PROCESS            = 6
%JOB_OBJECT_MSG_EXIT_PROCESS           = 7
%JOB_OBJECT_MSG_ABNORMAL_EXIT_PROCESS  = 8
%JOB_OBJECT_MSG_PROCESS_MEMORY_LIMIT   = 9
%JOB_OBJECT_MSG_JOB_MEMORY_LIMIT       = 10

'
' Basic Limits
'
%JOB_OBJECT_LIMIT_WORKINGSET               = &H00000001
%JOB_OBJECT_LIMIT_PROCESS_TIME             = &H00000002
%JOB_OBJECT_LIMIT_JOB_TIME                 = &H00000004
%JOB_OBJECT_LIMIT_ACTIVE_PROCESS           = &H00000008
%JOB_OBJECT_LIMIT_AFFINITY                 = &H00000010
%JOB_OBJECT_LIMIT_PRIORITY_CLASS           = &H00000020
%JOB_OBJECT_LIMIT_PRESERVE_JOB_TIME        = &H00000040
%JOB_OBJECT_LIMIT_SCHEDULING_CLASS         = &H00000080

'
' Extended Limits
'
%JOB_OBJECT_LIMIT_PROCESS_MEMORY             =&H00000100
%JOB_OBJECT_LIMIT_JOB_MEMORY                 =&H00000200
%JOB_OBJECT_LIMIT_DIE_ON_UNHANDLED_EXCEPTION =&H00000400
%JOB_OBJECT_LIMIT_BREAKAWAY_OK               =&H00000800
%JOB_OBJECT_LIMIT_SILENT_BREAKAWAY_OK        =&H00001000
%JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE          =&H00002000

%JOB_OBJECT_LIMIT_RESERVED2                  =&H00004000
%JOB_OBJECT_LIMIT_RESERVED3                  =&H00008000
%JOB_OBJECT_LIMIT_RESERVED4                  =&H00010000
%JOB_OBJECT_LIMIT_RESERVED5                  =&H00020000
%JOB_OBJECT_LIMIT_RESERVED6                  =&H00040000


%JOB_OBJECT_LIMIT_VALID_FLAGS          = &H0007ffff

%JOB_OBJECT_BASIC_LIMIT_VALID_FLAGS    = &H000000ff
%JOB_OBJECT_EXTENDED_LIMIT_VALID_FLAGS = &H00003fff
%JOB_OBJECT_RESERVED_LIMIT_VALID_FLAGS = &H0007ffff

'
' UI restrictions for jobs
'

%JOB_OBJECT_UILIMIT_NONE             =&H00000000

%JOB_OBJECT_UILIMIT_HANDLES          =&H00000001
%JOB_OBJECT_UILIMIT_READCLIPBOARD    =&H00000002
%JOB_OBJECT_UILIMIT_WRITECLIPBOARD   =&H00000004
%JOB_OBJECT_UILIMIT_SYSTEMPARAMETERS =&H00000008
%JOB_OBJECT_UILIMIT_DISPLAYSETTINGS  =&H00000010
%JOB_OBJECT_UILIMIT_GLOBALATOMS      =&H00000020
%JOB_OBJECT_UILIMIT_DESKTOP          =&H00000040
%JOB_OBJECT_UILIMIT_EXITWINDOWS      =&H00000080

%JOB_OBJECT_UILIMIT_ALL              =&H000000FF

%JOB_OBJECT_UI_VALID_FLAGS           =&H000000FF

%JOB_OBJECT_SECURITY_NO_ADMIN          = &H00000001
%JOB_OBJECT_SECURITY_RESTRICTED_TOKEN  = &H00000002
%JOB_OBJECT_SECURITY_ONLY_TOKEN        = &H00000004
%JOB_OBJECT_SECURITY_FILTER_TOKENS     = &H00000008

%JOB_OBJECT_SECURITY_VALID_FLAGS       = &H0000000f

MACRO JOBOBJECTINFOCLASS_enum=LONG
ENUM JOBOBJECTINFOCLASS SINGULAR
    JobObjectBasicAccountingInformation = 1
    JobObjectBasicLimitInformation
    JobObjectBasicProcessIdList
    JobObjectBasicUIRestrictions
    JobObjectSecurityLimitInformation    ' deprecated
    JobObjectEndOfJobTimeInformation
    JobObjectAssociateCompletionPortInformation
    JobObjectBasicAndIoAccountingInformation
    JobObjectExtendedLimitInformation
    JobObjectJobSetInformation
    MaxJobObjectInfoClass
END ENUM

%EVENT_MODIFY_STATE    = &H0002
%EVENT_ALL_ACCESS = (%STANDARD_RIGHTS_REQUIRED OR %SYNCHRONIZE OR &H3)
%MUTANT_QUERY_STATE    = &H0001

%MUTANT_ALL_ACCESS = (%STANDARD_RIGHTS_REQUIRED OR %SYNCHRONIZE OR _
                          %MUTANT_QUERY_STATE)
%SEMAPHORE_MODIFY_STATE    = &H0002
%SEMAPHORE_ALL_ACCESS = (%STANDARD_RIGHTS_REQUIRED OR %SYNCHRONIZE OR &H3)
'
' Timer Specific Access Rights.
'

%TIMER_QUERY_STATE     = &H0001
%TIMER_MODIFY_STATE    = &H0002

%TIMER_ALL_ACCESS  = (%STANDARD_RIGHTS_REQUIRED OR %SYNCHRONIZE OR _
                          %TIMER_QUERY_STATE OR %TIMER_MODIFY_STATE)

%TIME_ZONE_ID_UNKNOWN  = 0
%TIME_ZONE_ID_STANDARD = 1
%TIME_ZONE_ID_DAYLIGHT = 2

MACRO LOGICAL_PROCESSOR_RELATIONSHIP_enum=LONG
ENUM LOGICAL_PROCESSOR_RELATIONSHIP SINGULAR
    RelationProcessorCore
    RelationNumaNode
    RelationCache
    RelationProcessorPackage
END ENUM

%LTP_PC_SMT = &H1

MACRO PROCESSOR_CACHE_TYPE_enum=LONG
ENUM PROCESSOR_CACHE_TYPE SINGULAR
    CacheUnified
    CacheInstruction
    CacheData
    CacheTrace
END ENUM

%CACHE_FULLY_ASSOCIATIVE = &HFF?

TYPE CACHE_DESCRIPTOR
    Level         AS BYTE
    Associativity AS BYTE
    LineSize      AS WORD
    nSize         AS DWORD
    nType         AS PROCESSOR_CACHE_TYPE_enum
END TYPE

UNION SYSTEM_LOGICAL_PROCESSOR_INFORMATION_union
    Flags       AS BYTE
    NodeNumber  AS DWORD
    Cache       AS CACHE_DESCRIPTOR
    Reserved(1) AS QUAD
END UNION

TYPE SYSTEM_LOGICAL_PROCESSOR_INFORMATION
    ProcessorMask AS DWORD
    Relationship  AS LOGICAL_PROCESSOR_RELATIONSHIP_enum
    SYSTEM_LOGICAL_PROCESSOR_INFORMATION_union
END TYPE

TYPE SYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION
    CycleTime AS QUAD  ' DWORD64
END TYPE

TYPE PROCESSOR_RELATIONSHIP
    Flags        AS BYTE
    Reserved(20) AS BYTE
    GroupCount   AS WORD
    GroupMask(%ANYSIZE_ARRAY-1) AS GROUP_AFFINITY
END TYPE

TYPE NUMA_NODE_RELATIONSHIP
    NodeNumber   AS DWORD
    Reserved(19) AS BYTE
    GroupMask    AS GROUP_AFFINITY
END TYPE

TYPE CACHE_RELATIONSHIP
    Level         AS BYTE
    Associativity AS BYTE
    LineSize      AS WORD
    CacheSize     AS DWORD
    TYPE          AS PROCESSOR_CACHE_TYPE_enum
    Reserved(19)  AS BYTE
    GroupMask     AS GROUP_AFFINITY
END TYPE

TYPE PROCESSOR_GROUP_INFO
    MaximumProcessorCount AS BYTE
    ActiveProcessorCount  AS BYTE
    Reserved(37)          AS BYTE
    ActiveProcessorMask   AS KAFFINITY
END TYPE

TYPE GROUP_RELATIONSHIP
    MaximumGroupCount AS WORD
    ActiveGroupCount  AS WORD
    Reserved(19)      AS BYTE
    GroupInfo(%ANYSIZE_ARRAY-1) AS PROCESSOR_GROUP_INFO
END TYPE

UNION SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX_union
    Processor AS PROCESSOR_RELATIONSHIP
    NumaNode  AS NUMA_NODE_RELATIONSHIP
    Cache     AS CACHE_RELATIONSHIP
    Group     AS GROUP_RELATIONSHIP
END UNION

TYPE SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX
    Relationship  AS LOGICAL_PROCESSOR_RELATIONSHIP_enum
    SIZE          AS DWORD
    SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX_union
END TYPE

%PROCESSOR_INTEL_386     = 386
%PROCESSOR_INTEL_486     = 486
%PROCESSOR_INTEL_PENTIUM = 586
%PROCESSOR_INTEL_IA64    = 2200
%PROCESSOR_AMD_X8664     = 8664
%PROCESSOR_MIPS_R4000    = 4000    ' incl R4101 & R3910 for Windows CE
%PROCESSOR_ALPHA_21064   = 21064
%PROCESSOR_PPC_601       = 601
%PROCESSOR_PPC_603       = 603
%PROCESSOR_PPC_604       = 604
%PROCESSOR_PPC_620       = 620
%PROCESSOR_HITACHI_SH3   = 10003   ' Windows CE
%PROCESSOR_HITACHI_SH3E  = 10004   ' Windows CE
%PROCESSOR_HITACHI_SH4   = 10005   ' Windows CE
%PROCESSOR_MOTOROLA_821  = 821     ' Windows CE
%PROCESSOR_SHx_SH3       = 103     ' Windows CE
%PROCESSOR_SHx_SH4       = 104     ' Windows CE
%PROCESSOR_STRONGARM     = 2577    ' Windows CE - &HA11
%PROCESSOR_ARM720        = 1824    ' Windows CE - &H720
%PROCESSOR_ARM820        = 2080    ' Windows CE - &H820
%PROCESSOR_ARM920        = 2336    ' Windows CE - &H920
%PROCESSOR_ARM_7TDMI     = 70001   ' Windows CE
%PROCESSOR_OPTIL         = &H494f  ' MSIL

%PROCESSOR_ARCHITECTURE_INTEL          = 0
%PROCESSOR_ARCHITECTURE_MIPS           = 1
%PROCESSOR_ARCHITECTURE_ALPHA          = 2
%PROCESSOR_ARCHITECTURE_PPC            = 3
%PROCESSOR_ARCHITECTURE_SHX            = 4
%PROCESSOR_ARCHITECTURE_ARM            = 5
%PROCESSOR_ARCHITECTURE_IA64           = 6
%PROCESSOR_ARCHITECTURE_ALPHA64        = 7
%PROCESSOR_ARCHITECTURE_MSIL           = 8
%PROCESSOR_ARCHITECTURE_AMD64          = 9
%PROCESSOR_ARCHITECTURE_IA32_ON_WIN64  = 10

%PROCESSOR_ARCHITECTURE_UNKNOWN = &HFFFF??

%PF_FLOATING_POINT_PRECISION_ERRATA =0
%PF_FLOATING_POINT_EMULATED         =1
%PF_COMPARE_EXCHANGE_DOUBLE         =2
%PF_MMX_INSTRUCTIONS_AVAILABLE      =3
%PF_PPC_MOVEMEM_64BIT_OK            =4
%PF_ALPHA_BYTE_INSTRUCTIONS         =5
%PF_XMMI_INSTRUCTIONS_AVAILABLE     =6
%PF_3DNOW_INSTRUCTIONS_AVAILABLE    =7
%PF_RDTSC_INSTRUCTION_AVAILABLE     =8
%PF_PAE_ENABLED                     =9
%PF_XMMI64_INSTRUCTIONS_AVAILABLE  =10
%PF_SSE_DAZ_MODE_AVAILABLE         =11
%PF_NX_ENABLED                     =12
%PF_SSE3_INSTRUCTIONS_AVAILABLE    =13
%PF_COMPARE_EXCHANGE128            =14
%PF_COMPARE64_EXCHANGE128          =15
%PF_CHANNELS_ENABLED               =16

TYPE MEMORY_BASIC_INFORMATION
    BaseAddress       AS DWORD
    AllocationBase    AS DWORD
    AllocationProtect AS DWORD
    RegionSize        AS DWORD
    nState            AS DWORD
    Protect           AS DWORD
    nType             AS DWORD
END TYPE

TYPE MEMORY_BASIC_INFORMATION32
    MEMORY_BASIC_INFORMATION
END TYPE

'TYPE MEMORY_BASIC_INFORMATION64
'    QUAD BaseAddress;
'    QUAD AllocationBase;
'    DWORD     AllocationProtect;
'    DWORD     __alignment1;
'    QUAD RegionSize;
'    DWORD     State;
'    DWORD     Protect;
'    DWORD     Type;
'    DWORD     __alignment2;
'END TYPE

%SECTION_QUERY                =&H0001
%SECTION_MAP_WRITE            =&H0002
%SECTION_MAP_READ             =&H0004
%SECTION_MAP_EXECUTE          =&H0008
%SECTION_EXTEND_SIZE          =&H0010
%SECTION_MAP_EXECUTE_EXPLICIT =&H0020 ' not included in SECTION_ALL_ACCESS

%SECTION_ALL_ACCESS = (%STANDARD_RIGHTS_REQUIRED OR %SECTION_QUERY OR _
                           %SECTION_MAP_WRITE  OR       _
                           %SECTION_MAP_READ  OR        _
                           %SECTION_MAP_EXECUTE  OR     _
                           %SECTION_EXTEND_SIZE)

%SESSION_QUERY_ACCESS  =&H0001
%SESSION_MODIFY_ACCESS =&H0002

%SESSION_ALL_ACCESS = (%STANDARD_RIGHTS_REQUIRED  OR   _
                           %SESSION_QUERY_ACCESS  OR              _
                           %SESSION_MODIFY_ACCESS)

%PAGE_NOACCESS          =&H01
%PAGE_READONLY          =&H02
%PAGE_READWRITE         =&H04
%PAGE_WRITECOPY         =&H08
%PAGE_EXECUTE           =&H10
%PAGE_EXECUTE_READ      =&H20
%PAGE_EXECUTE_READWRITE =&H40
%PAGE_EXECUTE_WRITECOPY =&H80?
%PAGE_GUARD            =&H100
%PAGE_NOCACHE          =&H200
%PAGE_WRITECOMBINE     =&H400
%MEM_COMMIT           =&H1000
%MEM_RESERVE          =&H2000
%MEM_DECOMMIT         =&H4000
%MEM_RELEASE          =&H8000??
%MEM_FREE            =&H10000
%MEM_PRIVATE         =&H20000
%MEM_MAPPED          =&H40000
%MEM_RESET           =&H80000
%MEM_TOP_DOWN       =&H100000
%MEM_WRITE_WATCH    =&H200000
%MEM_PHYSICAL       =&H400000
%MEM_ROTATE         =&H800000
%MEM_LARGE_PAGES  =&H20000000
%MEM_4MB_PAGES    =&H80000000
%SEC_FILE           =&H800000
%SEC_IMAGE         =&H1000000
%SEC_PROTECTED_IMAGE  =&H2000000
%SEC_RESERVE       =&H4000000
%SEC_COMMIT        =&H8000000
%SEC_NOCACHE      =&H10000000
%SEC_WRITECOMBINE =&H40000000
%SEC_LARGE_PAGES  =&H80000000
%MEM_IMAGE        = %SEC_IMAGE
%WRITE_WATCH_FLAG_RESET =&H01

'
' Define access rights to files and directories
'

'
' The FILE_READ_DATA and FILE_WRITE_DATA constants are also defined in
' devioctl.h as FILE_READ_ACCESS and FILE_WRITE_ACCESS. The values for these
' constants *MUST* always be in sync.
' The values are redefined in devioctl.h because they must be available to
' both DOS and NT.
'

%FILE_READ_DATA            = &H0001      ' file & pipe
%FILE_LIST_DIRECTORY       = &H0001      ' directory

%FILE_WRITE_DATA           = &H0002      ' file & pipe
%FILE_ADD_FILE             = &H0002      ' directory

%FILE_APPEND_DATA          = &H0004      ' file
%FILE_ADD_SUBDIRECTORY     = &H0004      ' directory
%FILE_CREATE_PIPE_INSTANCE = &H0004      ' named pipe


%FILE_READ_EA              = &H0008      ' file & directory

%FILE_WRITE_EA             = &H0010      ' file & directory

%FILE_EXECUTE              = &H0020      ' file
%FILE_TRAVERSE             = &H0020      ' directory

%FILE_DELETE_CHILD         = &H0040      ' directory

%FILE_READ_ATTRIBUTES      = &H0080      ' all

%FILE_WRITE_ATTRIBUTES     = &H0100      ' all

%FILE_ALL_ACCESS = (%STANDARD_RIGHTS_REQUIRED  OR  %SYNCHRONIZE  OR  &H1FF)

%FILE_GENERIC_READ       = (%STANDARD_RIGHTS_READ     OR _
                                  %FILE_READ_DATA           OR _
                                  %FILE_READ_ATTRIBUTES     OR _
                                  %FILE_READ_EA             OR _
                                  %SYNCHRONIZE)


%FILE_GENERIC_WRITE      = (%STANDARD_RIGHTS_WRITE    OR _
                                  %FILE_WRITE_DATA          OR _
                                  %FILE_WRITE_ATTRIBUTES    OR _
                                  %FILE_WRITE_EA            OR _
                                  %FILE_APPEND_DATA         OR _
                                  %SYNCHRONIZE)


%FILE_GENERIC_EXECUTE    = (%STANDARD_RIGHTS_EXECUTE  OR _
                                  %FILE_READ_ATTRIBUTES     OR _
                                  %FILE_EXECUTE             OR _
                                  %SYNCHRONIZE)

%FILE_SHARE_READ               = &H00000001
%FILE_SHARE_WRITE              = &H00000002
%FILE_SHARE_DELETE             = &H00000004
%FILE_ATTRIBUTE_READONLY            = &H00000001
%FILE_ATTRIBUTE_HIDDEN              = &H00000002
%FILE_ATTRIBUTE_SYSTEM              = &H00000004
%FILE_ATTRIBUTE_DIRECTORY           = &H00000010
%FILE_ATTRIBUTE_ARCHIVE             = &H00000020
%FILE_ATTRIBUTE_DEVICE              = &H00000040
%FILE_ATTRIBUTE_NORMAL              = &H00000080
%FILE_ATTRIBUTE_TEMPORARY           = &H00000100
%FILE_ATTRIBUTE_SPARSE_FILE         = &H00000200
%FILE_ATTRIBUTE_REPARSE_POINT       = &H00000400
%FILE_ATTRIBUTE_COMPRESSED          = &H00000800
%FILE_ATTRIBUTE_OFFLINE             = &H00001000
%FILE_ATTRIBUTE_NOT_CONTENT_INDEXED = &H00002000
%FILE_ATTRIBUTE_ENCRYPTED           = &H00004000
%FILE_ATTRIBUTE_VIRTUAL             = &H00010000
%FILE_NOTIFY_CHANGE_FILE_NAME   = &H00000001
%FILE_NOTIFY_CHANGE_DIR_NAME    = &H00000002
%FILE_NOTIFY_CHANGE_ATTRIBUTES  = &H00000004
%FILE_NOTIFY_CHANGE_SIZE        = &H00000008
%FILE_NOTIFY_CHANGE_LAST_WRITE  = &H00000010
%FILE_NOTIFY_CHANGE_LAST_ACCESS = &H00000020
%FILE_NOTIFY_CHANGE_CREATION    = &H00000040
%FILE_NOTIFY_CHANGE_SECURITY    = &H00000100
%FILE_ACTION_ADDED                 = &H00000001
%FILE_ACTION_REMOVED               = &H00000002
%FILE_ACTION_MODIFIED              = &H00000003
%FILE_ACTION_RENAMED_OLD_NAME      = &H00000004
%FILE_ACTION_RENAMED_NEW_NAME      = &H00000005
%MAILSLOT_NO_MESSAGE           = &HFFFFFFFF  ' ((DWORD)-1)
%MAILSLOT_WAIT_FOREVER         = &HFFFFFFFF  ' ((DWORD)-1)
%FILE_CASE_SENSITIVE_SEARCH    = &H00000001
%FILE_CASE_PRESERVED_NAMES     = &H00000002
%FILE_UNICODE_ON_DISK          = &H00000004
%FILE_PERSISTENT_ACLS          = &H00000008
%FILE_FILE_COMPRESSION         = &H00000010
%FILE_VOLUME_QUOTAS            = &H00000020
%FILE_SUPPORTS_SPARSE_FILES    = &H00000040
%FILE_SUPPORTS_REPARSE_POINTS  = &H00000080
%FILE_SUPPORTS_REMOTE_STORAGE  = &H00000100
%FILE_VOLUME_IS_COMPRESSED     = &H00008000
%FILE_SUPPORTS_OBJECT_IDS      = &H00010000
%FILE_SUPPORTS_ENCRYPTION      = &H00020000
%FILE_NAMED_STREAMS            = &H00040000
%FILE_READ_ONLY_VOLUME         = &H00080000
%FILE_SEQUENTIAL_WRITE_ONCE    = &H00100000
%FILE_SUPPORTS_TRANSACTIONS    = &H00200000

'
' Define the file notification information structure
'

TYPE FILE_NOTIFY_INFORMATION
    NextEntryOffset AS DWORD
    Action          AS DWORD
    FileNameLength  AS DWORD
    FileName        AS WSTRINGZ * 1
END TYPE


'
' Define segment buffer structure for scatter/gather read/write.
'

UNION FILE_SEGMENT_ELEMENT
    Buffer    AS DWORD ' PVOID64
    Alignment AS QUAD
END UNION

'
' The reparse GUID structure is used by all 3rd party layered drivers to
' store data in a reparse point. For non-Microsoft tags, The GUID field
' cannot be GUID_NULL.
' The constraints on reparse tags are defined below.
' Microsoft tags can also be used with this format of the reparse point buffer.
'

TYPE REPARSE_GUID_DATA_BUFFER
    ReparseTag        AS DWORD
    ReparseDataLength AS WORD
    Reserved          AS WORD
    ReparseGuid       AS GUID
    DataBuffer(0)     AS BYTE
END TYPE

%REPARSE_GUID_DATA_BUFFER_HEADER_SIZE = 4+2+2+16 '  FIELD_OFFSET(REPARSE_GUID_DATA_BUFFER, GenericReparseBuffer)



'
' Maximum allowed size of the reparse data.
'

%MAXIMUM_REPARSE_DATA_BUFFER_SIZE    = ( 16 * 1024 )

'
' Predefined reparse tags.
' These tags need to avoid conflicting with IO_REMOUNT defined in ntos_inc_io.h
'

%IO_REPARSE_TAG_RESERVED_ZERO           = (0)
%IO_REPARSE_TAG_RESERVED_ONE            = (1)

'
' The value of the following constant needs to satisfy the following conditions:
'  (1) Be at least as large as the largest of the reserved tags.
'  (2) Be strictly smaller than all the tags in use.
'

%IO_REPARSE_TAG_RESERVED_RANGE          = %IO_REPARSE_TAG_RESERVED_ONE

'
' The reparse tags are a DWORD. The 32 bits are laid out as follows:
'
'   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
'   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'  +-+-+-+-+-----------------------+-------------------------------+
'  |M|R|N|R|     Reserved bits     |       Reparse Tag Value       |
'  +-+-+-+-+-----------------------+-------------------------------+
'
' M is the Microsoft bit. When set to 1, it denotes a tag owned by Microsoft.
'   All ISVs must use a tag with a 0 in this position.
'   Note: If a Microsoft tag is used by non-Microsoft software, the
'   behavior is not defined.
'
' R is reserved.  Must be zero for non-Microsoft tags.
'
' N is name surrogate. When set to 1, the file represents another named
'   entity in the system.
'
' The M and N bits are OR-able.
' The following macros check for the M and N bit values:
'

'
' Macro to determine whether a reparse point tag corresponds to a tag
' owned by Microsoft.
'

MACRO IsReparseTagMicrosoft(tag)=((tag) AND &H80000000)

'
' Macro to determine whether a reparse point tag is a name surrogate
'

MACRO IsReparseTagNameSurrogate(tag)=((tag) AND &H20000000)

%IO_REPARSE_TAG_MOUNT_POINT            = (&HA0000003)
%IO_REPARSE_TAG_HSM                    = (&HC0000004)
%IO_REPARSE_TAG_HSM2                   = (&H80000006)
%IO_REPARSE_TAG_SIS                    = (&H80000007)
%IO_REPARSE_TAG_DFS                    = (&H8000000A)
%IO_REPARSE_TAG_SYMLINK                = (&HA000000C)
%IO_REPARSE_TAG_DFSR                   = (&H80000012)

'
' I/O Completion Specific Access Rights.
'

%IO_COMPLETION_MODIFY_STATE = &H0002
%IO_COMPLETION_ALL_ACCESS = (%STANDARD_RIGHTS_REQUIRED OR %SYNCHRONIZE OR &H3)

'
' Object Manager Symbolic Link Specific Access Rights.
'

%DUPLICATE_CLOSE_SOURCE     = &H00000001
%DUPLICATE_SAME_ACCESS      = &H00000002

'
' =========================================
' Define GUIDs which represent well-known power schemes
' =========================================
'

'
' Maximum Power Savings - indicates that very aggressive power savings measures will be used to help
'                         stretch battery life.
'
MACRO GUID_MAX_POWER_SAVINGS=GUID$("{a1841308-3541-4fab-bc81-f71556f20b4a}")

'
' No Power Savings - indicates that almost no power savings measures will be used.
'
MACRO GUID_MIN_POWER_SAVINGS=GUID$("{8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c}")

'
' Typical Power Savings - indicates that fairly aggressive power savings measures will be used.
'
'
'
MACRO GUID_TYPICAL_POWER_SAVINGS=GUID$("{381b4222-f694-41f0-9685-ff5bb260df2e}")

'
' This is a special GUID that represents "no subgroup" of settings.  That is, it indicates
' that settings that are in the root of the power policy hierarchy as opposed to settings
' that are buried under a subgroup of settings.  This should be used when querying for
' power settings that may not fall into a subgroup.
'
MACRO NO_SUBGROUP_GUID=GUID$("{FEA3413E,7E05,4911,9A,71,70,03,31,F1,C2,94}")

'
' This is a special GUID that represents "every power scheme".  That is, it indicates
' that any write to this power scheme should be reflected to every scheme present.
' This allows users to write a single setting once and have it apply to all schemes.  They
' can then apply custom settings to specific power schemes that they care about.
'
MACRO ALL_POWERSCHEMES_GUID=GUID$("{68A1E95E,13EA,41E1,80,11,0C,49,6C,A4,90,B0}")

'
' This is a special GUID that represents a 'personality' that each power scheme will have.
' In other words, each power scheme will have this key indicating "I'm most like *this* base
' power scheme."  This individual setting will have one of three settings:
' GUID_MAX_POWER_SAVINGS
' GUID_MIN_POWER_SAVINGS
' GUID_TYPICAL_POWER_SAVINGS
'
' This allows several features:
' 1. Drivers and applications can register for notification of this GUID.  So when this power
'    scheme is activiated, this GUID's setting will be sent across the system and drivers/applications
'    can see "GUID_MAX_POWER_SAVINGS" which will tell them in a generic fashion "get real aggressive
'    about conserving power".
' 2. UserB may install a driver or application which creates power settings, and UserB may modify
'    those power settings.  Now UserA logs in.  How does he see those settings?  They simply don't
'    exist in his private power key.  Well they do exist over in the system power key.  When we
'    enumerate all the power settings in this system power key and don't find a corresponding entry
'    in the user's private power key, then we can go look at this "personality" key in the users
'    power scheme.  We can then go get a default value for the power setting, depending on which
'    "personality" power scheme is being operated on.  Here's an example:
'    A. UserB installs an application that creates a power setting Seetting1
'    B. UserB changes Setting1 to have a value of 50 because that's one of the possible settings
'       available for setting1.
'    C. UserB logs out
'    D. UserA logs in and his active power scheme is some custom scheme that was derived from
'       the GUID_TYPICAL_POWER_SAVINGS.  But remember that UserA has no setting1 in his
'       private power key.
'    E. When activating UserA's selected power scheme, all power settings in the system power key will
'       be enumerated (including Setting1).
'    F. The power manager will see that UserA has no Setting1 power setting in his private power scheme.
'    G. The power manager will query UserA's power scheme for its personality and retrieve
'       GUID_TYPICAL_POWER_SAVINGS.
'    H. The power manager then looks in Setting1 in the system power key and looks in its set of default
'       values for the corresponding value for GUID_TYPICAL_POWER_SAVINGS power schemes.
'    I. This derived power setting is applied.
MACRO GUID_POWERSCHEME_PERSONALITY=GUID$("{245D8541,3943,4422,B0,25,13,A7,84,F6,79,B7}")

'
' Define a special GUID which will be used to define the active power scheme.
' User will register for this power setting GUID, and when the active power
' scheme changes, they'll get a callback where the payload is the GUID
' representing the active powerscheme.
' ( 31F9F286-5084-42FE-B720-2B0264993763 }
'
MACRO GUID_ACTIVE_POWERSCHEME=GUID$("{31F9F286,5084,42FE,B7,20,2B,02,64,99,37,63}")

'
' =========================================
' Define GUIDs which represent well-known power settings
' =========================================
'

' Video settings
' --------------
'
' Specifies the subgroup which will contain all of the video
' settings for a single policy.
'
MACRO GUID_VIDEO_SUBGROUP=GUID$("{7516B95F,F776,4464,8C,53,06,16,7F,40,CC,99}")

'
' Specifies (in seconds) how long we wait after the last user input has been
' recieved before we power off the video.
'
MACRO GUID_VIDEO_POWERDOWN_TIMEOUT=GUID$("{3C0BC021,C8A8,4E07,A9,73,6B,14,CB,CB,2B,7E}")

'
' Specifies if the operating system should use adaptive timers (based on
' previous behavior) to power down the video,
'
MACRO GUID_VIDEO_ADAPTIVE_POWERDOWN=GUID$("{90959D22,D6A1,49B9,AF,93,BC,E8,85,AD,33,5B}")

'
' Specifies if the monitor is currently being powered or not.
'
MACRO GUID_MONITOR_POWER_ON=GUID$("{02731015-4510-4526-99E6-E5A17EBD1AEA}")

' Harddisk settings
' -----------------
'
' Specifies the subgroup which will contain all of the harddisk
' settings for a single policy.
'
MACRO GUID_DISK_SUBGROUP=GUID$("{0012EE47,9041,4B5D,9B,77,53,5F,BA,8B,14,42}")

'
' Specifies (in seconds) how long we wait after the last disk access
' before we power off the disk.
'
MACRO GUID_DISK_POWERDOWN_TIMEOUT=GUID$("{6738E2C4,E8A5,4A42,B1,6A,E0,40,E7,69,75,6E}")

'
' Specifies the amount of contiguous disk activity time to ignore when
' calculating disk idleness.
'
'
'

MACRO GUID_DISK_BURST_IGNORE_THRESHOLD=GUID$("{80e3c60e-bb94-4ad8-bbe0-0d3195efc663}")

'
' Specifies if the operating system should use adaptive timers (based on
' previous behavior) to power down the disk,
'
MACRO GUID_DISK_ADAPTIVE_POWERDOWN=GUID$("{396A32E1,499A,40B2,91,24,A9,6A,FE,70,76,67}")

' System sleep settings
' ---------------------
'
' Specifies the subgroup which will contain all of the sleep
' settings for a single policy.
'
MACRO GUID_SLEEP_SUBGROUP=GUID$("{238C9FA8-0AAD-41ED-83F4-97BE242C8F20}")

'
' Specifies an idle treshold percentage (0-100). The system must be this idle
' over a period of time in order to idle to sleep.
'
MACRO GUID_SLEEP_IDLE_THRESHOLD=GUID$("{81cd32e0,7833,44f3,87,37,70,81,f3,8d,1f,70}")

'
' Specifies (in seconds) how long we wait after the system is deemed
' "idle" before moving to standby (S1, S2 or S3).
'
MACRO GUID_STANDBY_TIMEOUT=GUID$("{29F6C1DB,86DA,48C5,9F,DB,F2,B6,7B,1F,44,DA}")

'
' Specifies (in seconds) how long the system should go back to sleep after
' waking unattended. 0 indicates that the standard standby/hibernate idle
' policy should be used instead.
'
MACRO GUID_UNATTEND_SLEEP_TIMEOUT=GUID$("{7bc4a2f9-d8fc-4469-b07b-33eb785aaca0}")

'
' Specifies (in seconds) how long we wait after the system is deemed
' "idle" before moving to hibernate (S4).
'
MACRO GUID_HIBERNATE_TIMEOUT=GUID$("{9D7815A6,7EE4,497E,88,88,51,5A,05,F0,23,64}")

'
' Specifies whether or not Fast S4 should be enabled if the system supports it
'
MACRO GUID_HIBERNATE_FASTS4_POLICY=GUID$("{94AC6D29-73CE-41A6-809F-6363BA21B47E}")

'
' Define a GUID for controlling the criticality of sleep state transitions.
' Critical sleep transitions do not query applications, services or drivers
' before transitioning the platform to a sleep state.
'
MACRO GUID_CRITICAL_POWER_TRANSITION=GUID$("{B7A27025-E569-46c2-A504-2B96CAD225A1}")

'
' Specifies if the system is entering or exiting 'away mode'.
'
MACRO GUID_SYSTEM_AWAYMODE=GUID$("{98A7F580-01F7-48AA-9C0F-44352C29E5C0}")

' Specify whether away mode is allowed
'
MACRO GUID_ALLOW_AWAYMODE=GUID$("{25DFA149-5DD1-4736-B5AB-E8A37B5B8187}")

'
' Defines a guid for enabling/disabling standby (S1-S3) states. This does not
' affect hibernation (S4).
'
MACRO GUID_ALLOW_STANDBY_STATES=GUID$("{abfc2519-3608-4c2a-94ea-171b0ed546ab}")

'
' Defines a guid for enabling/disabling the ability to wake via RTC.
'
MACRO GUID_ALLOW_RTC_WAKE=GUID$("{BD3B718A-0680-4D9D-8AB2-E1D2B4AC806D}")

' System button actions
' ---------------------
'
'
' Specifies the subgroup which will contain all of the system button
' settings for a single policy.
'
MACRO GUID_SYSTEM_BUTTON_SUBGROUP=GUID$("4F971E89,EEBD,4455,A8,DE,9E,59,04,0E,73,47}")

' Specifies (in a POWER_ACTION_POLICY structure) the appropriate action to
' take when the system power button is pressed.
'
MACRO GUID_POWERBUTTON_ACTION=GUID$("{7648EFA3,DD9C,4E3E,B5,66,50,F9,29,38,62,80}")
MACRO GUID_POWERBUTTON_ACTION_FLAGS=GUID$("{857E7FAC,034B,4704,AB,B1,BC,A5,4A,A3,14,78}")

'
' Specifies (in a POWER_ACTION_POLICY structure) the appropriate action to
' take when the system sleep button is pressed.
'
MACRO GUID_SLEEPBUTTON_ACTION=GUID$("{96996BC0,AD50,47EC,92,3B,6F,41,87,4D,D9,EB}")
MACRO GUID_SLEEPBUTTON_ACTION_FLAGS=GUID$("{2A160AB1,B69D,4743,B7,18,BF,14,41,D5,E4,H93}")

'
' Specifies (in a POWER_ACTION_POLICY structure) the appropriate action to
' take when the system sleep button is pressed.
'
'
MACRO GUID_USERINTERFACEBUTTON_ACTION=GUID$("{A7066653-8D6C-40A8-910E-A1F54B84C7E5}")

'
' Specifies (in a POWER_ACTION_POLICY structure) the appropriate action to
' take when the system lid is closed.
'
MACRO GUID_LIDCLOSE_ACTION=GUID$("{5CA83367,6E45,459F,A2,7B,47,6B,1D,01,C9,36}")
MACRO GUID_LIDCLOSE_ACTION_FLAGS=GUID$("{97E969AC,0D6C,4D08,92,7C,D7,BD,7A,D7,85,7B}")
MACRO GUID_LIDOPEN_POWERSTATE=GUID$("{99FF10E7,23B1,4C07,A9,D1,5C,32,06,D7,41,B4}")


' Battery Discharge Settings
' --------------------------
'
' Specifies the subgroup which will contain all of the battery discharge
' settings for a single policy.
'
MACRO GUID_BATTERY_SUBGROUP = GUID$("{E73A048D,BF27,4F12,97,31,8B,20,76,E8,89,1F}")

'
' 4 battery discharge alarm settings.
'
' GUID_BATTERY_DISCHARGE_ACTION_x - This is the action to take.  It is a value
'                                   of type POWER_ACTION
' GUID_BATTERY_DISCHARGE_LEVEL_x  - This is the battery level (%)
' GUID_BATTERY_DISCHARGE_FLAGS_x  - Flags defined below:
'                                   POWER_ACTION_POLICY->EventCode flags
'                                   BATTERY_DISCHARGE_FLAGS_EVENTCODE_MASK
'                                   BATTERY_DISCHARGE_FLAGS_ENABLE
MACRO GUID_BATTERY_DISCHARGE_ACTION_0=GUID$("{637EA02F, &HBBCB, &H4015, &H8E, &H2C, &HA1, &HC7, &HB9, &HC0, &HB5, &H46}")
MACRO GUID_BATTERY_DISCHARGE_LEVEL_0=GUID$("{9A66D8D7, &H4FF7, &H4EF9, &HB5, &HA2, &H5A, &H32, &H6C, &HA2, &HA4, &H69}")
MACRO GUID_BATTERY_DISCHARGE_FLAGS_0=GUID$("{5dbb7c9f, &H38e9, &H40d2, &H97, &H49, &H4f, &H8a, &H0e, &H9f, &H64, &H0f}")

MACRO GUID_BATTERY_DISCHARGE_ACTION_1=GUID$("{D8742DCB, &H3E6A, &H4B3C, &HB3, &HFE, &H37, &H46, &H23, &HCD, &HCF, &H06}")
MACRO GUID_BATTERY_DISCHARGE_LEVEL_1=GUID$("{8183BA9A, &HE910, &H48DA, &H87, &H69, &H14, &HAE, &H6D, &HC1, &H17, &H0A}")
MACRO GUID_BATTERY_DISCHARGE_FLAGS_1=GUID$("{bcded951, &H187b, &H4d05, &Hbc, &Hcc, &Hf7, &He5, &H19, &H60, &Hc2, &H58}")

MACRO GUID_BATTERY_DISCHARGE_ACTION_2=GUID$("{421CBA38, &H1A8E, &H4881, &HAC, &H89, &HE3, &H3A, &H8B, &H04, &HEC, &HE4}")
MACRO GUID_BATTERY_DISCHARGE_LEVEL_2=GUID$("{07A07CA2, &HADAF, &H40D7, &HB0, &H77, &H53, &H3A, &HAD, &HED, &H1B, &HFA}")
MACRO GUID_BATTERY_DISCHARGE_FLAGS_2=GUID$("{7fd2f0c4, &Hfeb7, &H4da3, &H81, &H17, &He3, &Hfb, &Hed, &Hc4, &H65, &H82}")

MACRO GUID_BATTERY_DISCHARGE_ACTION_3=GUID$("{80472613, &H9780, &H455E, &HB3, &H08, &H72, &HD3, &H00, &H3C, &HF2, &HF8}")
MACRO GUID_BATTERY_DISCHARGE_LEVEL_3=GUID$("{58AFD5A6, &HC2DD, &H47D2, &H9F, &HBF, &HEF, &H70, &HCC, &H5C, &H59, &H65}")
MACRO GUID_BATTERY_DISCHARGE_FLAGS_3=GUID$("{73613ccf, &Hdbfa, &H4279, &H83, &H56, &H49, &H35, &Hf6, &Hbf, &H62, &Hf3}")

' Processor power settings
' ------------------------
'

' Specifies the subgroup which will contain all of the processor
' settings for a single policy.
'
MACRO GUID_PROCESSOR_SETTINGS_SUBGROUP=GUID$("{54533251, &H82BE, &H4824, &H96, &HC1, &H47, &HB6, &H0B, &H74, &H0D, &H00}")

MACRO GUID_PROCESSOR_THROTTLE_POLICY=GUID$("{57027304, &H4AF6, &H4104, &H92, &H60, &HE3, &HD9, &H52, &H48, &HFC, &H36}")

'
' Specifies a percentage (between 0 and 100) that the processor frequency
' should never go above.  For example, if this value is set to 80, then
' the processor frequency will never be throttled above 80 percent of its
' maximum frequency by the system.
'
MACRO GUID_PROCESSOR_THROTTLE_MAXIMUM=GUID$("{BC5038F7, &H23E0, &H4960, &H96, &HDA, &H33, &HAB, &HAF, &H59, &H35, &HEC}")

'
' Specifies a percentage (between 0 and 100) that the processor frequency
' should not drop below.  For example, if this value is set to 50, then the
' processor frequency will never be throttled below 50 percent of its
' maximum frequency by the system.
'
MACRO GUID_PROCESSOR_THROTTLE_MINIMUM=GUID$("{893DEE8E, &H2BEF, &H41E0, &H89, &HC6, &HB5, &H5D, &H09, &H29, &H96, &H4C}")

'
' Specifies whether throttle states are allowed to be used even when
' performance states are available.
'
MACRO GUID_PROCESSOR_ALLOW_THROTTLING=GUID$("{3b04d4fd-1cc7-4f23-ab1c-d1337819c4bb}")

'
' Specifies processor power settings for CState policy data
'
MACRO GUID_PROCESSOR_IDLESTATE_POLICY=GUID$("{68F262A7-F621-4069-B9A5-4874169BE23C}")

'
' Specifies processor power settings for PerfState policy data
'
MACRO GUID_PROCESSOR_PERFSTATE_POLICY=GUID$("{BBDC3814-18E9-4463-8A55-D197327C45C0}")

'
' Specifies active vs passive cooling.  Although not directly related to
' processor settings, it is the processor that gets throttled if we're doing
' passive cooling, so it is fairly strongly related.
'
MACRO GUID_SYSTEM_COOLING_POLICY=GUID$("{94D3A615-A899-4AC5-AE2B-E4D8F634367F}")

' Lock Console on Wake
' --------------------
'

' Specifies the behavior of the system when we wake from standby or
' hibernate.  If this is set, then we will cause the console to lock
' after we resume.
'
MACRO GUID_LOCK_CONSOLE_ON_WAKE=GUID$("{0E796BDB,100D,47D6,A2,D5,F7,D2,DA,A5,1F,51}")

' Device idle characteristics
' ---------------------------
'
' Specifies whether to use the "performance" or "conservative" timeouts for
' device idle management.
'
MACRO GUID_DEVICE_IDLE_POLICY=GUID$("{4faab71a-92e5-4726-b531-224559672d19}")

%POWER_DEVICE_IDLE_POLICY_PERFORMANCE  = 0
%POWER_DEVICE_IDLE_POLICY_CONSERVATIVE = 1

' AC/DC power source
' ------------------
'

' Specifies the power source for the system.  consumers may register for
' notification when the power source changes and will be notified with
' one of 3 values:
' 0 - Indicates the system is being powered by an AC power source.
' 1 - Indicates the system is being powered by a DC power source.
' 2 - Indicates the system is being powered by a short-term DC power
'     source.  For example, this would be the case if the system is
'     being powed by a short-term battery supply in a backing UPS
'     system.  When this value is recieved, the consumer should make
'     preparations for either a system hibernate or system shutdown.
'
MACRO GUID_ACDC_POWER_SOURCE=GUID$("{5D3E9A59-E9D5-4B00-A6BD-FF34FF516548}")

' Lid state changes
' -----------------
'
' Specifies the current state of the lid (open or closed). The callback won't
' be called at all until a lid device is found and its current state is known.
'
' Values:
'
' 0 - closed
' 1 - opened
'

MACRO GUID_LIDSWITCH_STATE_CHANGE=GUID$("{BA3E0F4D-B817-4094-A2D1-D56379E6A0F3}")

' Battery life remaining
' ----------------------
'

' Specifies the percentage of battery life remaining.  The consumer
' may register for notification in order to track battery life in
' a fine-grained manner.
'
' Once registered, the consumer can expect to be notified as the battery
' life percentage changes.
'
' The consumer will recieve a value between 0 and 100 (inclusive) which
' indicates percent battery life remaining.
'
MACRO GUID_BATTERY_PERCENTAGE_REMAINING=GUID$("{A7AD8041-B45A-4CAE-87A3-EECBB468A9E1}")


' Notification to listeners that the system is fairly busy and won't be moving
' into an idle state any time soon.  This can be used as a hint to listeners
' that now might be a good time to do background tasks.
'
MACRO GUID_IDLE_BACKGROUND_TASK=GUID$("{515C31D8,F734,163D,A0,FD,11,A0,8C,91,E8,F1}")

' Notification to listeners that the system is fairly busy and won't be moving
' into an idle state any time soon.  This can be used as a hint to listeners
' that now might be a good time to do background tasks.
'
MACRO GUID_BACKGROUND_TASK_NOTIFICATION=GUID$("{CF23F240-2A54-48D8-B114-DE1518FF052E}")

' Define a GUID that will represent the action of a direct experience button
' on the platform.  Users will register for this DPPE setting and recieve
' notification when the h/w button is pressed.
'
MACRO GUID_APPLAUNCH_BUTTON=GUID$("{1A689231-7399-4E9A-8F99-B71F999DB3FA}")

' PCI Express power settings
' ------------------------
'

' Specifies the subgroup which will contain all of the PCI Express
' settings for a single policy.
'
MACRO GUID_PCIEXPRESS_SETTINGS_SUBGROUP=GUID$("{501a4d13-42af-4429-9fd1-a8218c268e20}")

' Specifies the PCI Express ASPM power policy.
'
MACRO GUID_PCIEXPRESS_ASPM_POLICY=GUID$("{ee12f906-d277-404b-b6da-e5fa1a576df5}")


MACRO SYSTEM_POWER_STATE_enum=LONG
ENUM SYSTEM_POWER_STATE SINGULAR
    PowerSystemUnspecified
    PowerSystemWorking
    PowerSystemSleeping1
    PowerSystemSleeping2
    PowerSystemSleeping3
    PowerSystemHibernate
    PowerSystemShutdown
    PowerSystemMaximum
END ENUM

%POWER_SYSTEM_MAXIMUM = 7

MACRO POWER_ACTION_enum=LONG
ENUM POWER_ACTION SINGULAR
    PowerActionNone
    PowerActionReserved
    PowerActionSleep
    PowerActionHibernate
    PowerActionShutdown
    PowerActionShutdownReset
    PowerActionShutdownOff
    PowerActionWarmEject
END ENUM

MACRO DEVICE_POWER_STATE_enum=LONG
ENUM DEVICE_POWER_STATE SINGULAR
    PowerDeviceUnspecified
    PowerDeviceD0
    PowerDeviceD1
    PowerDeviceD2
    PowerDeviceD3
    PowerDeviceMaximum
END ENUM



%ES_SYSTEM_REQUIRED   = &H00000001
%ES_DISPLAY_REQUIRED  = &H00000002
%ES_USER_PRESENT      = &H00000004
%ES_AWAYMODE_REQUIRED = &H00000040
%ES_CONTINUOUS        = &H80000000

MACRO EXECUTION_STATE=DWORD

MACRO LATENCY_TIME_enum=LONG
ENUM LATENCY_TIME SINGULAR
    LT_DONT_CARE
    LT_LOWEST_LATENCY
END ENUM

#IF (%WIN32_WINNT >= %WIN32_WINNT_WIN7)

%DIAGNOSTIC_REASON_VERSION            = 0

%DIAGNOSTIC_REASON_SIMPLE_STRING      = &H00000001
%DIAGNOSTIC_REASON_DETAILED_STRING    = &H00000002
%DIAGNOSTIC_REASON_NOT_SPECIFIED      = &H80000000
%DIAGNOSTIC_REASON_INVALID_FLAGS      = (NOT &H80000003) AND &HFFFFFFFF

#ENDIF ' (%WIN32_WINNT >= %WIN32_WINNT_WIN7)

'
' Defines for power request APIs
'

%POWER_REQUEST_CONTEXT_VERSION         = 0

%POWER_REQUEST_CONTEXT_SIMPLE_STRING   = &H00000001
%POWER_REQUEST_CONTEXT_DETAILED_STRING = &H00000002

'
' N.B. The maximum is a macro (rather than part of enum) for cgen to be able
' to parse power.h correctly. When a new power request type is added, the
' PowerRequestMaximum should be manually incremented.
'

MACRO POWER_REQUEST_TYPE_enum=LONG
ENUM POWER_REQUEST_TYPE SINGULAR
    PowerRequestDisplayRequired
    PowerRequestSystemRequired
    PowerRequestAwayModeRequired
END ENUM

%PowerRequestMaximum = 3

' end_ntminiport

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)

'-----------------------------------------------------------------------------
' Device Power Information
' Accessable via CM_Get_DevInst_Registry_Property_Ex(CM_DRP_DEVICE_POWER_DATA)
'-----------------------------------------------------------------------------

%PDCAP_D0_SUPPORTED            = &H00000001
%PDCAP_D1_SUPPORTED            = &H00000002
%PDCAP_D2_SUPPORTED            = &H00000004
%PDCAP_D3_SUPPORTED            = &H00000008
%PDCAP_WAKE_FROM_D0_SUPPORTED  = &H00000010
%PDCAP_WAKE_FROM_D1_SUPPORTED  = &H00000020
%PDCAP_WAKE_FROM_D2_SUPPORTED  = &H00000040
%PDCAP_WAKE_FROM_D3_SUPPORTED  = &H00000080
%PDCAP_WARM_EJECT_SUPPORTED    = &H00000100

TYPE CM_POWER_DATA
    PD_Size                 AS DWORD
    PD_MostRecentPowerState AS DEVICE_POWER_STATE_enum
    PD_Capabilities         AS DWORD
    PD_D1Latency            AS DWORD
    PD_D2Latency            AS DWORD
    PD_D3Latency            AS DWORD
    PD_PowerStateMapping(%POWER_SYSTEM_MAXIMUM-1) AS DEVICE_POWER_STATE_enum
    PD_DeepestSystemWake    AS SYSTEM_POWER_STATE_enum
END TYPE

#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WINXP)


MACRO POWER_INFORMATION_LEVEL_enum=LONG
ENUM POWER_INFORMATION_LEVEL SINGULAR
    SystemPowerPolicyAc
    SystemPowerPolicyDc
    VerifySystemPolicyAc
    VerifySystemPolicyDc
    SystemPowerCapabilities
    SystemBatteryState
    SystemPowerStateHandler
    ProcessorStateHandler
    SystemPowerPolicyCurrent
    AdministratorPowerPolicy
    SystemReserveHiberFile
    ProcessorInformation
    SystemPowerInformation
    ProcessorStateHandler2
    LastWakeTime                            ' Compare with KeQueryInterruptTime()
    LastSleepTime                           ' Compare with KeQueryInterruptTime()
    SystemExecutionState
    SystemPowerStateNotifyHandler
    ProcessorPowerPolicyAc
    ProcessorPowerPolicyDc
    VerifyProcessorPowerPolicyAc
    VerifyProcessorPowerPolicyDc
    ProcessorPowerPolicyCurrent
    SystemPowerStateLogging
    SystemPowerLoggingEntry
    SetPowerSettingValue
    NotifyUserPowerSetting
    GetPowerTransitionVetoes
    SetPowerTransitionVeto
    SystemVideoState
    TraceApplicationPowerMessage
    TraceApplicationPowerMessageEnd
    ProcessorPerfStates
    ProcessorIdleStates
    ProcessorThrottleStates
    SystemWakeSource
    SystemHiberFileInformation
    TraceServicePowerMessage
    ProcessorLoad
    PowerShutdownNotification
    MonitorCapabilities
END ENUM  ' POWER_INFORMATION_LEVEL

'
' Power Transition Vetos
'

%PO_TRANSITION_VETO_TYPE_WINDOW  = &H00000001
%PO_TRANSITION_VETO_TYPE_SERVICE = &H00000002
'%PO_TRANSITION_VETO_TYPE_DRIVER  = &H00000004

%PO_TRANSITION_VETO_TYPE_ALL =   _
    (%PO_TRANSITION_VETO_TYPE_WINDOW OR %PO_TRANSITION_VETO_TYPE_SERVICE)

TYPE PO_TRANSITION_VETO_REASON
    ResourceId       AS DWORD
    ModuleNameOffset AS DWORD
END TYPE

TYPE PO_TRANSITION_VETO_WINDOW
    HANDLE AS DWORD
END TYPE

TYPE PO_TRANSITION_VETO_SERVICE
    ServiceNameOffset AS DWORD
END TYPE

'
'
'TYPE PO_TRANSITION_VETO_DRIVER
'    InstancePathOffset AS DWORD
'    DriverNameOffset   AS DWORD
'END TYPE
'
'

UNION PO_TRANSITION_VETO_union
    WINDOW  AS PO_TRANSITION_VETO_WINDOW
    Service AS PO_TRANSITION_VETO_SERVICE
    'Driver  as PO_TRANSITION_VETO_DRIVER
END UNION

TYPE PO_TRANSITION_VETO
    nType     AS DWORD
    Reason    AS PO_TRANSITION_VETO_REASON
    ProcessId AS DWORD
    PO_TRANSITION_VETO_union
END TYPE

TYPE PO_TRANSITION_VETOES
    COUNT     AS DWORD
    Vetoes(0) AS PO_TRANSITION_VETO
END TYPE

'
' Power Setting definitions
'

MACRO SYSTEM_POWER_CONDITION_enum=LONG
ENUM SYSTEM_POWER_CONDITION SINGULAR
    PoAc
    PoDc
    PoHot
    PoConditionMaximum
END ENUM


TYPE SET_POWER_SETTING_VALUE
    '
    ' Version of this structure.  Currently should be set to
    ' POWER_SETTING_VALUE_VERSION.
    '
    Version        AS DWORD
    '
    ' GUID representing the power setting being applied.
    '
    nGuid          AS GUID
    '
    ' What power state should this setting be applied to?  E.g.
    ' AC, DC, thermal, ...
    '
    PowerCondition AS LONG  ' SYSTEM_POWER_CONDITION
    '
    ' Length (in bytes) of the 'Data' member.
    '
    DataLength     AS DWORD
    '
    ' Data which contains the actual setting value.
    '
    nData(0)       AS BYTE
END TYPE

%POWER_SETTING_VALUE_VERSION = (&H1)

TYPE NOTIFY_USER_POWER_SETTING
    nGuid AS GUID
END TYPE

'
' Package definition for an experience button device notification.  When
' someone registers for GUID_EXPERIENCE_BUTTON, this is the definition of
' the setting data they'll get.
'
TYPE APPLICATIONLAUNCH_SETTING_VALUE

    '
    ' System time when the most recent button press ocurred.  Note that this is
    ' specified in 100ns internvals since January 1, 1601.
    '
    ActivationTime   AS LARGE_INTEGER

    '
    ' Reserved for internal use.
    '
    Flags            AS DWORD

    '
    ' which instance of this device was pressed?
    '
    ButtonInstanceID AS DWORD


END TYPE

'
' define platform roles
'

MACRO POWER_PLATFORM_ROLE_enum=LONG
ENUM POWER_PLATFORM_ROLE SINGULAR
    PlatformRoleUnspecified
    PlatformRoleDesktop
    PlatformRoleMobile
    PlatformRoleWorkstation
    PlatformRoleEnterpriseServer
    PlatformRoleSOHOServer
    PlatformRoleAppliancePC
    PlatformRolePerformanceServer
    PlatformRoleMaximum
END ENUM

'
' Wake source tracking
'

MACRO PO_WAKE_SOURCE_TYPE_enum=LONG
ENUM PO_WAKE_SOURCE_TYPE SINGULAR
    DeviceWakeSourceType
    FixedWakeSourceType
END ENUM

MACRO PO_FIXED_WAKE_SOURCE_TYPE_enum=LONG
ENUM PO_FIXED_WAKE_SOURCE_TYPE SINGULAR
    FixedWakeSourcePowerButton
    FixedWakeSourceSleepButton
    FixedWakeSourceRtc
END ENUM

TYPE PO_WAKE_SOURCE_HEADER
    nType AS PO_WAKE_SOURCE_TYPE_enum
    nSize AS DWORD
END TYPE

TYPE PO_WAKE_SOURCE_DEVICE
    HEADER       AS PO_WAKE_SOURCE_HEADER
    InstancePath AS WSTRINGZ * 1
END TYPE

TYPE PO_WAKE_SOURCE_FIXED
    HEADER              AS PO_WAKE_SOURCE_HEADER
    FixedWakeSourceType AS PO_FIXED_WAKE_SOURCE_TYPE_enum
END TYPE

TYPE PO_WAKE_SOURCE_INFO
    COUNT      AS DWORD
    Offsets(0) AS DWORD
END TYPE

TYPE PO_WAKE_SOURCE_HISTORY
    COUNT      AS DWORD
    Offsets(0) AS DWORD
END TYPE

'
' System power manager capabilities
'

#IF (%NTDDI_VERSION >= %NTDDI_WINXP) OR (NOT %DEF(%BATCLASS))
TYPE BATTERY_REPORTING_SCALE
    Granularity AS DWORD
    Capacity    AS DWORD
END TYPE
#ENDIF ' (%NTDDI_VERSION >= %NTDDI_WINXP) OR NOT %DEF(%BATCLASS)

'

TYPE PPM_SIMULATED_PROCESSOR_LOAD
    Enabled AS BYTE  ' BOOLEAN
    PercentBusy(%MAXIMUM_PROCESSORS-1) AS BYTE
END TYPE

TYPE PPM_WMI_LEGACY_PERFSTATE
    Frequency        AS DWORD
    Flags            AS DWORD
    PercentFrequency AS DWORD
END TYPE

TYPE PPM_WMI_IDLE_STATE
    Latency        AS DWORD
    Power          AS DWORD
    TimeCheck      AS DWORD
    PromotePercent AS BYTE
    DemotePercent  AS BYTE
    StateType      AS BYTE
    Reserved       AS BYTE
    StateFlags     AS DWORD
    Context        AS DWORD
    IdleHandler    AS DWORD
    Reserved1      AS DWORD     ' reserved for future use
END TYPE

TYPE PPM_WMI_IDLE_STATES
    nType            AS DWORD
    COUNT            AS DWORD
    TargetState      AS DWORD          ' current idle state
    OldState         AS DWORD          ' previous idle state
    TargetProcessors AS QUAD
    STATE(0)         AS PPM_WMI_IDLE_STATE
END TYPE

TYPE PPM_WMI_PERF_STATE
    Frequency        AS DWORD      ' in Mhz
    Power            AS DWORD      ' in milliwatts
    PercentFrequency AS BYTE
    IncreaseLevel    AS BYTE       ' goto higher state
    DecreaseLevel    AS BYTE       ' goto lower state
    nType            AS BYTE       ' performance or throttle
    IncreaseTime     AS DWORD      ' in tick counts
    DecreaseTime     AS DWORD      ' in tick counts
    CONTROL          AS QUAD       ' control value
    STATUS           AS QUAD       ' control value
    HitCount         AS DWORD
    Reserved1        AS DWORD      ' reserved for future use
    Reserved2        AS QUAD
    Reserved3        AS QUAD
END TYPE

TYPE PPM_WMI_PERF_STATES
    COUNT             AS DWORD
    MaxFrequency      AS DWORD
    CurrentState      AS DWORD      ' current state
    MaxPerfState      AS DWORD      ' fastest state considering policy restrictions
    MinPerfState      AS DWORD      ' slowest state considering policy restrictions
    LowestPerfState   AS DWORD      ' slowest perf state, fixed, aka the "knee"
    ThermalConstraint AS DWORD
    BusyAdjThreshold  AS BYTE
    PolicyType        AS BYTE       ' domain coordination
    nType             AS BYTE
    Reserved          AS BYTE
    TimerInterval     AS DWORD
    TargetProcessors  AS QUAD       ' domain affinity
    PStateHandler     AS DWORD
    PStateContext     AS DWORD
    TStateHandler     AS DWORD
    TStateContext     AS DWORD
    FeedbackHandler   AS DWORD
    Reserved1         AS DWORD
    Reserved2         AS QUAD
    STATE(0)          AS PPM_WMI_PERF_STATE
END TYPE

'
' Accounting info.
'

%PROC_IDLE_BUCKET_COUNT = 6

TYPE PPM_IDLE_STATE_ACCOUNTING
    IdleTransitions    AS DWORD
    FailedTransitions  AS DWORD
    InvalidBucketIndex AS DWORD
    TotalTime          AS QUAD
    IdleTimeBuckets(%PROC_IDLE_BUCKET_COUNT-1) AS DWORD
END TYPE

TYPE PPM_IDLE_ACCOUNTING
    StateCount       AS DWORD
    TotalTransitions AS DWORD
    ResetCount       AS DWORD
    StartTime        AS QUAD
    STATE(0)         AS PPM_IDLE_STATE_ACCOUNTING
END TYPE

'
' Definitions of coordination types for _PSD, _TSD, and _CSD BIOS objects from
' the Acpi 3.0 specification
'

%ACPI_PPM_SOFTWARE_ALL   = &HFC
%ACPI_PPM_SOFTWARE_ANY   = &HFD
%ACPI_PPM_HARDWARE_ALL   = &HFE

'
' Definition of Microsoft PPM coordination types.
'

%MS_PPM_SOFTWARE_ALL     = &H1



'
' Processor Power Management WMI interface.
'

MACRO PPM_PERFSTATE_CHANGE_GUID=GUID$("{A5B32DDD-7F39-4abc-B892-900E43B59EBB}")

MACRO PPM_PERFSTATE_DOMAIN_CHANGE_GUID=GUID$("{995e6b7f-d653-497a-b978-36a30c29bf01}")

MACRO PPM_IDLESTATE_CHANGE_GUID=GUID$("{4838fe4f-f71c-4e51-9ecc-8430a7ac4c6c}")

MACRO PPM_PERFSTATES_DATA_GUID=GUID$("{5708cc20-7d40-4bf4-b4aa-2b01338d0126}")

MACRO PPM_IDLESTATES_DATA_GUID=GUID$("{ba138e10-e250-4ad7-8616-cf1a7ad410e7}")

MACRO PPM_IDLE_ACCOUNTING_GUID=GUID$("{e2a26f78-ae07-4ee0-a30f-ce354f5a94cd}")

MACRO PPM_THERMALCONSTRAINT_GUID=GUID$("{a852c2c8-1a4c-423b-8c2c-f30d82931a88}")

MACRO PPM_PERFMON_PERFSTATE_GUID=GUID$("{7fd18652-0cfe-40d2-b0a1-0b066a87759e}")

MACRO PPM_THERMAL_POLICY_CHANGE_GUID=GUID$("{48f377b8-6880-4c7b-8bdc-380176c6654d}")


TYPE PPM_PERFSTATE_EVENT
    STATE     AS DWORD
    STATUS    AS DWORD
    Latency   AS DWORD
    SPEED     AS DWORD
    Processor AS DWORD
END TYPE

TYPE PPM_PERFSTATE_DOMAIN_EVENT
    STATE      AS DWORD
    Latency    AS DWORD
    SPEED      AS DWORD
    Processors AS QUAD
END TYPE

TYPE PPM_IDLESTATE_EVENT
    NewState   AS DWORD
    OldState   AS DWORD
    Processors AS QUAD
END TYPE

TYPE PPM_THERMALCHANGE_EVENT
    ThermalConstraint AS DWORD
    Processors        AS QUAD
END TYPE


TYPE PPM_THERMAL_POLICY_EVENT
    MODE       AS BYTE
    Processors AS QUAD
END TYPE


' Power Policy Management interfaces
'

TYPE POWER_ACTION_POLICY
    Action    AS LONG  ' POWER_ACTION
    Flags     AS DWORD
    EventCode AS DWORD
END TYPE

' POWER_ACTION_POLICY->Flags:
%POWER_ACTION_QUERY_ALLOWED     = &H00000001
%POWER_ACTION_UI_ALLOWED        = &H00000002
%POWER_ACTION_OVERRIDE_APPS     = &H00000004
%POWER_ACTION_PSEUDO_TRANSITION = &H08000000
%POWER_ACTION_LIGHTEST_FIRST    = &H10000000
%POWER_ACTION_LOCK_CONSOLE      = &H20000000
%POWER_ACTION_DISABLE_WAKES     = &H40000000
%POWER_ACTION_CRITICAL          = &H80000000

' POWER_ACTION_POLICY->EventCode flags
%POWER_LEVEL_USER_NOTIFY_TEXT   = &H00000001
%POWER_LEVEL_USER_NOTIFY_SOUND  = &H00000002
%POWER_LEVEL_USER_NOTIFY_EXEC   = &H00000004
%POWER_USER_NOTIFY_BUTTON       = &H00000008
%POWER_USER_NOTIFY_SHUTDOWN     = &H00000010
%POWER_FORCE_TRIGGER_RESET      = &H80000000

' Note: for battery alarm EventCodes, the ID of the battery alarm << 16 is ORed
' into the flags.  For example: DISCHARGE_POLICY_LOW << 16

'
' The GUID_BATTERY_DISCHARGE_FLAGS_x power settings use a subset of EventCode
' flags.  The POWER_FORCE_TRIGGER_RESET flag doesn't make sense for a battery
' alarm so it is overloaded for other purposes (gerneral enable/disable).
%BATTERY_DISCHARGE_FLAGS_EVENTCODE_MASK = &H00000007
%BATTERY_DISCHARGE_FLAGS_ENABLE = &H80000000

' system battery drain policies
TYPE SYSTEM_POWER_LEVEL
    ENABLE         AS BYTE ' BOOLEAN
    Spare(2)       AS BYTE
    BatteryLevel   AS DWORD
    PowerPolicy    AS POWER_ACTION_POLICY
    MinSystemState AS LONG ' SYSTEM_POWER_STATE
END TYPE

' Discharge policy constants
%NUM_DISCHARGE_POLICIES    = 4
%DISCHARGE_POLICY_CRITICAL = 0
%DISCHARGE_POLICY_LOW      = 1


' system power policies
TYPE SYSTEM_POWER_POLICY
    Revision         AS DWORD       ' 1

    ' events
    PowerButton      AS POWER_ACTION_POLICY
    SleepButton      AS POWER_ACTION_POLICY
    LidClose         AS POWER_ACTION_POLICY
    LidOpenWake      AS LONG ' SYSTEM_POWER_STATE
    Reserved         AS DWORD

    ' "system idle" detection
    Idle             AS POWER_ACTION_POLICY
    IdleTimeout      AS DWORD
    IdleSensitivity  AS BYTE

    DynamicThrottle  AS BYTE
    Spare2(1)        AS BYTE

    ' meaning of power action "sleep"
    MinSleep         AS LONG ' SYSTEM_POWER_STATE
    MaxSleep         AS LONG ' SYSTEM_POWER_STATE
    ReducedLatencySleep AS LONG ' SYSTEM_POWER_STATE
    WinLogonFlags    AS DWORD

    Spare3           AS DWORD

    ' parameters for dozing
    '
    DozeS4Timeout    AS DWORD

    ' battery policies
    BroadcastCapacityResolution AS DWORD
    DischargePolicy(%NUM_DISCHARGE_POLICIES-1) AS SYSTEM_POWER_LEVEL

    ' video policies
    VideoTimeout     AS DWORD
    VideoDimDisplay  AS BYTE ' BOOLEAN
    VideoReserved(2) AS DWORD

    ' hard disk policies
    SpindownTimeout  AS DWORD

    ' processor policies
    OptimizeForPower AS BYTE ' BOOLEAN
    FanThrottleTolerance AS BYTE
    ForcedThrottle   AS BYTE
    MinThrottle      AS BYTE
    OverThrottled    AS POWER_ACTION_POLICY

END TYPE


' processor power policy state

'
' Processor Idle State Policy.
'

%PROCESSOR_IDLESTATE_POLICY_COUNT = &H3

TYPE PROCESSOR_IDLESTATE_INFO
    TimeCheck      AS DWORD
    DemotePercent  AS BYTE
    PromotePercent AS BYTE
    Spare(1)       AS BYTE
END TYPE

TYPE PROCESSOR_IDLESTATE_POLICY_type
    AllowScaling AS BIT * 1 IN WORD
    Disabled     AS BIT * 1
    Reserved     AS BIT * 14
END TYPE

UNION PROCESSOR_IDLESTATE_POLICY_union
    AsWORD         AS WORD
    PROCESSOR_IDLESTATE_POLICY_type
END UNION

TYPE PROCESSOR_IDLESTATE_POLICY
    Revision       AS WORD
    Flags          AS PROCESSOR_IDLESTATE_POLICY_union
    PolicyCount    AS DWORD
    Policy(%PROCESSOR_IDLESTATE_POLICY_COUNT-1) AS PROCESSOR_IDLESTATE_INFO
END TYPE

'
' Legacy Processor Policy.  This is only provided to allow legacy
' applications to compile.  New applications must use
' PROCESSOR_IDLESTATE_POLICY.
'

%PO_THROTTLE_NONE          = 0
%PO_THROTTLE_CONSTANT      = 1
%PO_THROTTLE_DEGRADE       = 2
%PO_THROTTLE_ADAPTIVE      = 3
%PO_THROTTLE_MAXIMUM       = 4   ' not a policy, just a limit


TYPE PROCESSOR_POWER_POLICY_INFO

    ' Time based information (will be converted to kernel units)
    TimeCheck     AS DWORD        ' in US
    DemoteLimit   AS DWORD        ' in US
    PromoteLimit  AS DWORD        ' in US

    ' Percentage based information
    DemotePercent  AS BYTE
    PromotePercent AS BYTE
    Spare(1)       AS BYTE

    ' Flags
    AllowDemotion  AS BIT * 1 IN DWORD
    AllowPromotion AS BIT * 1
    Reserved       AS BIT * 30

END TYPE

' processor power policy
TYPE PROCESSOR_POWER_POLICY
    Revision        AS DWORD       ' 1

    ' Dynamic Throttling Policy
    DynamicThrottle AS BYTE
    Spare(2)        AS BYTE

    ' Flags
    DisableCStates  AS BIT * 1 IN DWORD
    Reserved        AS BIT * 31

    ' System policy information
    ' The Array is last, in case it needs to be grown and the structure
    ' revision incremented.
    PolicyCount     AS DWORD
    Policy(2)       AS PROCESSOR_POWER_POLICY_INFO

END TYPE

'
' Processor Perf State Policy.
'

%PERFSTATE_POLICY_CHANGE_IDEAL  = &H00
%PERFSTATE_POLICY_CHANGE_SINGLE = &H01
%PERFSTATE_POLICY_CHANGE_ROCKET = &H02
%PERFSTATE_POLICY_CHANGE_MAX = %PERFSTATE_POLICY_CHANGE_ROCKET

TYPE PROCESSOR_PERFSTATE_POLICY_type
    NoDomainAccounting AS BIT * 1 IN BYTE
    IncreasePolicy     AS BIT * 2
    DecreasePolicy     AS BIT * 2
    Reserved           AS BIT * 3
END TYPE

UNION PROCESSOR_PERFSTATE_POLICY_union2
    AsBYTE  AS BYTE
    PROCESSOR_PERFSTATE_POLICY_type
END UNION

UNION PROCESSOR_PERFSTATE_POLICY_union1
    Spare AS BYTE
    Flags AS PROCESSOR_PERFSTATE_POLICY_union2
END UNION

TYPE PROCESSOR_PERFSTATE_POLICY
    Revision         AS DWORD
    MaxThrottle      AS BYTE
    MinThrottle      AS BYTE
    BusyAdjThreshold AS BYTE
    PROCESSOR_PERFSTATE_POLICY_union1
    TimeCheck        AS DWORD
    IncreaseTime     AS DWORD
    DecreaseTime     AS DWORD
    IncreasePercent  AS DWORD
    DecreasePercent  AS DWORD
END TYPE

' administrator power policy overrides
TYPE ADMINISTRATOR_POWER_POLICY

    ' meaning of power action "sleep"
    MinSleep           AS LONG ' SYSTEM_POWER_STATE
    MaxSleep           AS LONG ' SYSTEM_POWER_STATE

    ' video policies
    MinVideoTimeout    AS DWORD
    MaxVideoTimeout    AS DWORD

    ' disk policies
    MinSpindownTimeout AS DWORD
    MaxSpindownTimeout AS DWORD
END TYPE




TYPE SYSTEM_POWER_CAPABILITIES
    ' Misc supported system features
    PowerButtonPresent AS BYTE  'BOOLEAN
    SleepButtonPresent AS BYTE  'BOOLEAN
    LidPresent         AS BYTE  'BOOLEAN
    SystemS1           AS BYTE  'BOOLEAN
    SystemS2           AS BYTE  'BOOLEAN
    SystemS3           AS BYTE  'BOOLEAN
    SystemS4           AS BYTE  'BOOLEAN       ' hibernate
    SystemS5           AS BYTE  'BOOLEAN       ' off
    HiberFilePresent   AS BYTE  'BOOLEAN
    FullWake           AS BYTE  'BOOLEAN
    VideoDimPresent    AS BYTE  'BOOLEAN
    ApmPresent         AS BYTE  'BOOLEAN
    UpsPresent         AS BYTE  'BOOLEAN

    ' Processors
    ThermalControl       AS BYTE  'BOOLEAN
    ProcessorThrottle    AS BYTE  'BOOLEAN
    ProcessorMinThrottle AS BYTE

#IF (%NTDDI_VERSION < %NTDDI_WINXP)
    ProcessorThrottleScale AS BYTE
    spare2(3) AS BYTE
#ELSE
    ProcessorMaxThrottle AS BYTE
    FastSystemS4         AS BYTE ' BOOLEAN
    spare2(2)            AS BYTE
#ENDIF ' (%NTDDI_VERSION < %NTDDI_WINXP)

    ' Disk
    DiskSpinDown AS BYTE ' BOOLEAN
    spare3(7)    AS BYTE

    ' System Battery
    SystemBatteriesPresent AS BYTE  'BOOLEAN
    BatteriesAreShortTerm  AS BYTE  'BOOLEAN
    BatteryScale(2)        AS BATTERY_REPORTING_SCALE

    ' Wake
    AcOnLineWake          AS LONG ' SYSTEM_POWER_STATE
    SoftLidWake           AS LONG ' SYSTEM_POWER_STATE
    RtcWake               AS LONG ' SYSTEM_POWER_STATE
    MinDeviceWakeState    AS LONG ' SYSTEM_POWER_STATE   ' note this may change on driver load
    DefaultLowLatencyWake AS LONG ' SYSTEM_POWER_STATE
END TYPE

TYPE SYSTEM_BATTERY_STATE
    AcOnLine          AS BYTE  'BOOLEAN
    BatteryPresent    AS BYTE  'BOOLEAN
    Charging          AS BYTE  'BOOLEAN
    Discharging       AS BYTE  'BOOLEAN
    Spare1(3)         AS BYTE  'BOOLEAN

    MaxCapacity       AS DWORD
    RemainingCapacity AS DWORD
    Rate              AS DWORD
    EstimatedTime     AS DWORD

    DefaultAlert1     AS DWORD
    DefaultAlert2     AS DWORD
END TYPE



'
' Image Format
'


#IF NOT %DEF(%MAC)

%IMAGE_DOS_SIGNATURE              = &H5A4D      ' MZ
%IMAGE_OS2_SIGNATURE              = &H454E      ' NE
%IMAGE_OS2_SIGNATURE_LE           = &H454C      ' LE
%IMAGE_VXD_SIGNATURE              = &H454C      ' LE
%IMAGE_NT_SIGNATURE               = &H00004550  ' PE00

#ELSE

%IMAGE_DOS_SIGNATURE              = &H4D5A      ' MZ
%IMAGE_OS2_SIGNATURE              = &H4E45      ' NE
%IMAGE_OS2_SIGNATURE_LE           = &H4C45      ' LE
%IMAGE_NT_SIGNATURE               = &H50450000  ' PE00
#ENDIF

TYPE IMAGE_DOS_HEADER
    e_magic    AS WORD             ' Magic number
    e_cblp     AS WORD             ' Bytes on last page of file
    e_cp       AS WORD             ' Pages in file
    e_crlc     AS WORD             ' Relocations
    e_cparhdr  AS WORD             ' Size of header in paragraphs
    e_minalloc AS WORD             ' Minimum extra paragraphs needed
    e_maxalloc AS WORD             ' Maximum extra paragraphs needed
    e_ss       AS WORD             ' Initial (relative) SS value
    e_sp       AS WORD             ' Initial SP value
    e_csum     AS WORD             ' Checksum
    e_ip       AS WORD             ' Initial IP value
    e_cs       AS WORD             ' Initial (relative) CS value
    e_lfarlc   AS WORD             ' File address of relocation table
    e_ovno     AS WORD             ' Overlay number
    e_res(3)   AS WORD             ' Reserved words
    e_oemid    AS WORD             ' OEM identifier (for e_oeminfo)
    e_oeminfo  AS WORD             ' OEM information; e_oemid specific
    e_res2(9)  AS WORD             ' Reserved words
    e_lfanew   AS LONG             ' File address of new exe header
END TYPE

TYPE IMAGE_OS2_HEADER
    ne_magic        AS WORD        ' Magic number
    ne_ver          AS BYTE        ' Version number
    ne_rev          AS BYTE        ' Revision number
    ne_enttab       AS WORD        ' Offset of Entry Table
    ne_cbenttab     AS WORD        ' Number of bytes in Entry Table
    ne_crc          AS LONG        ' Checksum of whole file
    ne_flags        AS WORD        ' Flag word
    ne_autodata     AS WORD        ' Automatic data segment number
    ne_heap         AS WORD        ' Initial heap allocation
    ne_stack        AS WORD        ' Initial stack allocation
    ne_csip         AS LONG        ' Initial CS:IP setting
    ne_sssp         AS LONG        ' Initial SS:SP setting
    ne_cseg         AS WORD        ' Count of file segments
    ne_cmod         AS WORD        ' Entries in Module Reference Table
    ne_cbnrestab    AS WORD        ' Size of non-resident name table
    ne_segtab       AS WORD        ' Offset of Segment Table
    ne_rsrctab      AS WORD        ' Offset of Resource Table
    ne_restab       AS WORD        ' Offset of resident name table
    ne_modtab       AS WORD        ' Offset of Module Reference Table
    ne_imptab       AS WORD        ' Offset of Imported Names Table
    ne_nrestab      AS LONG        ' Offset of Non-resident Names Table
    ne_cmovent      AS WORD        ' Count of movable entries
    ne_align        AS WORD        ' Segment alignment shift count
    ne_cres         AS WORD        ' Count of resource segments
    ne_exetyp       AS BYTE        ' Target Operating system
    ne_flagsothers  AS BYTE        ' Other .EXE flags
    ne_pretthunks   AS WORD        ' offset to return thunks
    ne_psegrefbytes AS WORD        ' offset to segment ref. bytes
    ne_swaparea     AS WORD        ' Minimum code swap area size
    ne_expver       AS WORD        ' Expected Windows version number
END TYPE

TYPE IMAGE_VXD_HEADER
    e32_magic        AS WORD       ' Magic number
    e32_border       AS BYTE       ' The byte ordering for the VXD
    e32_worder       AS BYTE       ' The word ordering for the VXD
    e32_level        AS DWORD      ' The EXE format level for now = 0
    e32_cpu          AS WORD       ' The CPU type
    e32_os           AS WORD       ' The OS type
    e32_ver          AS DWORD      ' Module version
    e32_mflags       AS DWORD      ' Module flags
    e32_mpages       AS DWORD      ' Module # pages
    e32_startobj     AS DWORD      ' Object # for instruction pointer
    e32_eip          AS DWORD      ' Extended instruction pointer
    e32_stackobj     AS DWORD      ' Object # for stack pointer
    e32_esp          AS DWORD      ' Extended stack pointer
    e32_pagesize     AS DWORD      ' VXD page size
    e32_lastpagesize AS DWORD      ' Last page size in VXD
    e32_fixupsize    AS DWORD      ' Fixup section size
    e32_fixupsum     AS DWORD      ' Fixup section checksum
    e32_ldrsize      AS DWORD      ' Loader section size
    e32_ldrsum       AS DWORD      ' Loader section checksum
    e32_objtab       AS DWORD      ' Object table offset
    e32_objcnt       AS DWORD      ' Number of objects in module
    e32_objmap       AS DWORD      ' Object page map offset
    e32_itermap      AS DWORD      ' Object iterated data map offset
    e32_rsrctab      AS DWORD      ' Offset of Resource Table
    e32_rsrccnt      AS DWORD      ' Number of resource entries
    e32_restab       AS DWORD      ' Offset of resident name table
    e32_enttab       AS DWORD      ' Offset of Entry Table
    e32_dirtab       AS DWORD      ' Offset of Module Directive Table
    e32_dircnt       AS DWORD      ' Number of module directives
    e32_fpagetab     AS DWORD      ' Offset of Fixup Page Table
    e32_frectab      AS DWORD      ' Offset of Fixup Record Table
    e32_impmod       AS DWORD      ' Offset of Import Module Name Table
    e32_impmodcnt    AS DWORD      ' Number of entries in Import Module Name Table
    e32_impproc      AS DWORD      ' Offset of Import Procedure Name Table
    e32_pagesum      AS DWORD      ' Offset of Per-Page Checksum Table
    e32_datapage     AS DWORD      ' Offset of Enumerated Data Pages
    e32_preload      AS DWORD      ' Number of preload pages
    e32_nrestab      AS DWORD      ' Offset of Non-resident Names Table
    e32_cbnrestab    AS DWORD      ' Size of Non-resident Name Table
    e32_nressum      AS DWORD      ' Non-resident Name Table Checksum
    e32_autodata     AS DWORD      ' Object # for automatic data object
    e32_debuginfo    AS DWORD      ' Offset of the debugging information
    e32_debuglen     AS DWORD      ' The length of the debugging info. in bytes
    e32_instpreload  AS DWORD      ' Number of instance pages in preload section of VXD file
    e32_instdemand   AS DWORD      ' Number of instance pages in demand load section of VXD file
    e32_heapsize     AS DWORD      ' Size of heap - for 16-bit apps
    e32_res3(11)     AS BYTE       ' Reserved words
    e32_winresoff    AS DWORD
    e32_winreslen    AS DWORD
    e32_devid        AS WORD       ' Device ID for VxD
    e32_ddkver       AS WORD       ' DDK version for VxD
END TYPE

'
' File header format.
'

TYPE IMAGE_FILE_HEADER
    Machine              AS WORD
    NumberOfSections     AS WORD
    TimeDateStamp        AS DWORD
    PointerToSymbolTable AS DWORD
    NumberOfSymbols      AS DWORD
    SizeOfOptionalHeader AS WORD
    Characteristics      AS WORD
END TYPE

%IMAGE_SIZEOF_FILE_HEADER           = 20

%IMAGE_FILE_RELOCS_STRIPPED         = &H0001  ' Relocation info stripped from file.
%IMAGE_FILE_EXECUTABLE_IMAGE        = &H0002  ' File is executable  (i.e. no unresolved externel references).
%IMAGE_FILE_LINE_NUMS_STRIPPED      = &H0004  ' Line nunbers stripped from file.
%IMAGE_FILE_LOCAL_SYMS_STRIPPED     = &H0008  ' Local symbols stripped from file.
%IMAGE_FILE_AGGRESIVE_WS_TRIM       = &H0010  ' Agressively trim working set
%IMAGE_FILE_LARGE_ADDRESS_AWARE     = &H0020  ' App can handle >2gb addresses
%IMAGE_FILE_BYTES_REVERSED_LO       = &H0080  ' Bytes of machine word are reversed.
%IMAGE_FILE_32BIT_MACHINE           = &H0100  ' 32 bit word machine.
%IMAGE_FILE_DEBUG_STRIPPED          = &H0200  ' Debugging info stripped from file in .DBG file
%IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP = &H0400  ' If Image is on removable media, copy and run from the swap file.
%IMAGE_FILE_NET_RUN_FROM_SWAP       = &H0800  ' If Image is on Net, copy and run from the swap file.
%IMAGE_FILE_SYSTEM                  = &H1000  ' System File.
%IMAGE_FILE_DLL                     = &H2000  ' File is a DLL.
%IMAGE_FILE_UP_SYSTEM_ONLY          = &H4000  ' File should only be run on a UP machine
%IMAGE_FILE_BYTES_REVERSED_HI       = &H8000??  ' Bytes of machine word are reversed.

%IMAGE_FILE_MACHINE_UNKNOWN         = 0
%IMAGE_FILE_MACHINE_I386            = &H014c  ' Intel 386.
%IMAGE_FILE_MACHINE_R3000           = &H0162  ' MIPS little-endian, &H160 big-endian
%IMAGE_FILE_MACHINE_R4000           = &H0166  ' MIPS little-endian
%IMAGE_FILE_MACHINE_R10000          = &H0168  ' MIPS little-endian
%IMAGE_FILE_MACHINE_WCEMIPSV2       = &H0169  ' MIPS little-endian WCE v2
%IMAGE_FILE_MACHINE_ALPHA           = &H0184  ' Alpha_AXP
%IMAGE_FILE_MACHINE_SH3             = &H01a2  ' SH3 little-endian
%IMAGE_FILE_MACHINE_SH3DSP          = &H01a3
%IMAGE_FILE_MACHINE_SH3E            = &H01a4  ' SH3E little-endian
%IMAGE_FILE_MACHINE_SH4             = &H01a6  ' SH4 little-endian
%IMAGE_FILE_MACHINE_SH5             = &H01a8  ' SH5
%IMAGE_FILE_MACHINE_ARM             = &H01c0  ' ARM Little-Endian
%IMAGE_FILE_MACHINE_THUMB           = &H01c2
%IMAGE_FILE_MACHINE_AM33            = &H01d3
%IMAGE_FILE_MACHINE_POWERPC         = &H01F0  ' IBM PowerPC Little-Endian
%IMAGE_FILE_MACHINE_POWERPCFP       = &H01f1
%IMAGE_FILE_MACHINE_IA64            = &H0200  ' Intel 64
%IMAGE_FILE_MACHINE_MIPS16          = &H0266  ' MIPS
%IMAGE_FILE_MACHINE_ALPHA64         = &H0284  ' ALPHA64
%IMAGE_FILE_MACHINE_MIPSFPU         = &H0366  ' MIPS
%IMAGE_FILE_MACHINE_MIPSFPU16       = &H0466  ' MIPS
%IMAGE_FILE_MACHINE_AXP64           = %IMAGE_FILE_MACHINE_ALPHA64
%IMAGE_FILE_MACHINE_TRICORE         = &H0520  ' Infineon
%IMAGE_FILE_MACHINE_CEF             = &H0CEF
%IMAGE_FILE_MACHINE_EBC             = &H0EBC  ' EFI Byte Code
%IMAGE_FILE_MACHINE_AMD64           = &H8664??  ' AMD64 (K8)
%IMAGE_FILE_MACHINE_M32R            = &H9041??  ' M32R little-endian
%IMAGE_FILE_MACHINE_CEE             = &HC0EE??

'
' Directory format.
'

TYPE IMAGE_DATA_DIRECTORY
    VirtualAddress AS DWORD
    nSize          AS DWORD
END TYPE

%IMAGE_NUMBEROF_DIRECTORY_ENTRIES  = 16

'
' Optional header format.
'

TYPE IMAGE_OPTIONAL_HEADER32
    '
    ' Standard fields.
    '

    Magic                   AS WORD
    MajorLinkerVersion      AS BYTE
    MinorLinkerVersion      AS BYTE
    SizeOfCode              AS DWORD
    SizeOfInitializedData   AS DWORD
    SizeOfUninitializedData AS DWORD
    AddressOfEntryPoint     AS DWORD
    BaseOfCode              AS DWORD
    BaseOfData              AS DWORD

    '
    ' NT additional fields.
    '

    ImageBase               AS DWORD
    SectionAlignment        AS DWORD
    FileAlignment           AS DWORD
    MajorOperatingSystemVersion AS WORD
    MinorOperatingSystemVersion AS WORD
    MajorImageVersion       AS WORD
    MinorImageVersion       AS WORD
    MajorSubsystemVersion   AS WORD
    MinorSubsystemVersion   AS WORD
    Win32VersionValue       AS DWORD
    SizeOfImage             AS DWORD
    SizeOfHeaders           AS DWORD
    CheckSum                AS DWORD
    Subsystem               AS WORD
    DllCharacteristics      AS WORD
    SizeOfStackReserve      AS DWORD
    SizeOfStackCommit       AS DWORD
    SizeOfHeapReserve       AS DWORD
    SizeOfHeapCommit        AS DWORD
    LoaderFlags             AS DWORD
    NumberOfRvaAndSizes     AS DWORD
    DataDirectory(%IMAGE_NUMBEROF_DIRECTORY_ENTRIES - 1) AS IMAGE_DATA_DIRECTORY
END TYPE

TYPE IMAGE_ROM_OPTIONAL_HEADER
    Magic                   AS WORD
    MajorLinkerVersion      AS BYTE
    MinorLinkerVersion      AS BYTE
    SizeOfCode              AS DWORD
    SizeOfInitializedData   AS DWORD
    SizeOfUninitializedData AS DWORD
    AddressOfEntryPoint     AS DWORD
    BaseOfCode              AS DWORD
    BaseOfData              AS DWORD
    BaseOfBss               AS DWORD
    GprMask                 AS DWORD
    CprMask(3)              AS DWORD
    GpValue                 AS DWORD
END TYPE

TYPE IMAGE_OPTIONAL_HEADER64
    Magic                       AS WORD
    MajorLinkerVersion          AS BYTE
    MinorLinkerVersion          AS BYTE
    SizeOfCode                  AS DWORD
    SizeOfInitializedData       AS DWORD
    SizeOfUninitializedData     AS DWORD
    AddressOfEntryPoint         AS DWORD
    BaseOfCode                  AS DWORD
    ImageBase                   AS QUAD
    SectionAlignment            AS DWORD
    FileAlignment               AS DWORD
    MajorOperatingSystemVersion AS WORD
    MinorOperatingSystemVersion AS WORD
    MajorImageVersion           AS WORD
    MinorImageVersion           AS WORD
    MajorSubsystemVersion       AS WORD
    MinorSubsystemVersion       AS WORD
    Win32VersionValue           AS DWORD
    SizeOfImage                 AS DWORD
    SizeOfHeaders               AS DWORD
    CheckSum                    AS DWORD
    Subsystem                   AS WORD
    DllCharacteristics          AS WORD
    SizeOfStackReserve          AS QUAD
    SizeOfStackCommit           AS QUAD
    SizeOfHeapReserve           AS QUAD
    SizeOfHeapCommit            AS QUAD
    LoaderFlags                 AS DWORD
    NumberOfRvaAndSizes         AS DWORD
    DataDirectory(%IMAGE_NUMBEROF_DIRECTORY_ENTRIES - 1) AS IMAGE_DATA_DIRECTORY
END TYPE

%IMAGE_NT_OPTIONAL_HDR32_MAGIC    = &H10b
%IMAGE_NT_OPTIONAL_HDR64_MAGIC    = &H20b
%IMAGE_ROM_OPTIONAL_HDR_MAGIC     = &H107

#IF %DEF(%WIN64)
TYPE IMAGE_OPTIONAL_HEADER
    IMAGE_OPTIONAL_HEADER64
END TYPE
%IMAGE_NT_OPTIONAL_HDR_MAGIC = %IMAGE_NT_OPTIONAL_HDR64_MAGIC
#ELSE
TYPE IMAGE_OPTIONAL_HEADER
    IMAGE_OPTIONAL_HEADER32
END TYPE
%IMAGE_NT_OPTIONAL_HDR_MAGIC = %IMAGE_NT_OPTIONAL_HDR32_MAGIC
#ENDIF

TYPE IMAGE_NT_HEADERS64
    Signature      AS DWORD
    FileHeader     AS IMAGE_FILE_HEADER
    OptionalHeader AS IMAGE_OPTIONAL_HEADER64
END TYPE

TYPE IMAGE_NT_HEADERS32
    Signature      AS DWORD
    FileHeader     AS IMAGE_FILE_HEADER
    OptionalHeader AS IMAGE_OPTIONAL_HEADER32
END TYPE

TYPE IMAGE_ROM_HEADERS
    FileHeader     AS IMAGE_FILE_HEADER
    OptionalHeader AS IMAGE_ROM_OPTIONAL_HEADER
END TYPE

#IF %DEF(%WIN64)
TYPE IMAGE_NT_HEADERS
    IMAGE_NT_HEADERS64
END TYPE
#ELSE
TYPE IMAGE_NT_HEADERS
    IMAGE_NT_HEADERS32
END TYPE
#ENDIF

' IMAGE_FIRST_SECTION doesn't need 32/64 versions since the file header is the same either way.

'MACRO IMAGE_FIRST_SECTION( ntheader ) ((PIMAGE_SECTION_HEADER)        _
'    ((ULONG_PTR)(ntheader) +                                            _
'     FIELD_OFFSET( IMAGE_NT_HEADERS, OptionalHeader ) +                 _
'     ((ntheader))->FileHeader.SizeOfOptionalHeader   _
'    ))

' Subsystem Values

%IMAGE_SUBSYSTEM_UNKNOWN            = 0   ' Unknown subsystem.
%IMAGE_SUBSYSTEM_NATIVE             = 1   ' Image doesn't require a subsystem.
%IMAGE_SUBSYSTEM_WINDOWS_GUI        = 2   ' Image runs in the Windows GUI subsystem.
%IMAGE_SUBSYSTEM_WINDOWS_CUI        = 3   ' Image runs in the Windows character subsystem.
%IMAGE_SUBSYSTEM_OS2_CUI            = 5   ' image runs in the OS/2 character subsystem.
%IMAGE_SUBSYSTEM_POSIX_CUI          = 7   ' image runs in the Posix character subsystem.
%IMAGE_SUBSYSTEM_NATIVE_WINDOWS     = 8   ' image is a native Win9x driver.
%IMAGE_SUBSYSTEM_WINDOWS_CE_GUI     = 9   ' Image runs in the Windows CE subsystem.
%IMAGE_SUBSYSTEM_EFI_APPLICATION    = 10  '
%IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER = 11
%IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER = 12  '
%IMAGE_SUBSYSTEM_EFI_ROM            = 13
%IMAGE_SUBSYSTEM_XBOX               = 14
%IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION = 16

' DllCharacteristics Entries

'      IMAGE_LIBRARY_PROCESS_INIT            &H0001     ' Reserved.
'      IMAGE_LIBRARY_PROCESS_TERM            &H0002     ' Reserved.
'      IMAGE_LIBRARY_THREAD_INIT             &H0004     ' Reserved.
'      IMAGE_LIBRARY_THREAD_TERM             &H0008     ' Reserved.
%IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE = &H0040     ' DLL can move.
%IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY = &H0080     ' Code Integrity Image
%IMAGE_DLLCHARACTERISTICS_NX_COMPAT    = &H0100     ' Image is NX compatible
%IMAGE_DLLCHARACTERISTICS_NO_ISOLATION = &H0200     ' Image understands isolation and doesn't want it
%IMAGE_DLLCHARACTERISTICS_NO_SEH       = &H0400     ' Image does not use SEH.  No SE handler may reside in this image
%IMAGE_DLLCHARACTERISTICS_NO_BIND      = &H0800     ' Do not bind this image.
'                                            &H1000     ' Reserved.
%IMAGE_DLLCHARACTERISTICS_WDM_DRIVER   = &H2000     ' Driver uses WDM model
'                                            &H4000     ' Reserved.
%IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE = &H8000??

' Directory Entries

%IMAGE_DIRECTORY_ENTRY_EXPORT         =  0   ' Export Directory
%IMAGE_DIRECTORY_ENTRY_IMPORT         =  1   ' Import Directory
%IMAGE_DIRECTORY_ENTRY_RESOURCE       =  2   ' Resource Directory
%IMAGE_DIRECTORY_ENTRY_EXCEPTION      =  3   ' Exception Directory
%IMAGE_DIRECTORY_ENTRY_SECURITY       =  4   ' Security Directory
%IMAGE_DIRECTORY_ENTRY_BASERELOC      =  5   ' Base Relocation Table
%IMAGE_DIRECTORY_ENTRY_DEBUG          =  6   ' Debug Directory
'      IMAGE_DIRECTORY_ENTRY_COPYRIGHT       7   ' (X86 usage)
%IMAGE_DIRECTORY_ENTRY_ARCHITECTURE   =  7   ' Architecture Specific Data
%IMAGE_DIRECTORY_ENTRY_GLOBALPTR      =  8   ' RVA of GP
%IMAGE_DIRECTORY_ENTRY_TLS            =  9   ' TLS Directory
%IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG    = 10   ' Load Configuration Directory
%IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT   = 11   ' Bound Import Directory in headers
%IMAGE_DIRECTORY_ENTRY_IAT            = 12   ' Import Address Table
%IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT   = 13   ' Delay Load Import Descriptors
%IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR = 14   ' COM Runtime descriptor

'
' Non-COFF Object file header
'

TYPE ANON_OBJECT_HEADER
    Sig1 AS WORD                ' Must be IMAGE_FILE_MACHINE_UNKNOWN
    Sig2 AS WORD                ' Must be &Hffff??
    Version AS WORD             ' >= 1 (implies the CLSID field is present)
    Machine AS WORD
    TimeDateStamp AS DWORD
    ClassID AS GUID ' CLSID     ' Used to invoke CoCreateInstance
    SizeOfData AS DWORD         ' Size of data that follows the header
END TYPE

TYPE ANON_OBJECT_HEADER_V2
    Sig1 AS WORD                ' Must be IMAGE_FILE_MACHINE_UNKNOWN
    Sig2 AS WORD                ' Must be &Hffff??
    Version AS WORD             ' >= 2 (implies the Flags field is present - otherwise V1)
    Machine AS WORD
    TimeDateStamp AS DWORD
    ClassID AS GUID ' CLSID     ' Used to invoke CoCreateInstance
    SizeOfData AS DWORD         ' Size of data that follows the header
    Flags AS DWORD              ' &H1 -> contains metadata
    MetaDataSize AS DWORD       ' Size of CLR metadata
    MetaDataOffset AS DWORD     ' Offset of CLR metadata
END TYPE
'
' Section header format.
'

%IMAGE_SIZEOF_SHORT_NAME           = 8

UNION IMAGE_SECTION_HEADER_union
    PhysicalAddress AS DWORD
    VirtualSize AS DWORD
END UNION

TYPE IMAGE_SECTION_HEADER
    bName(%IMAGE_SIZEOF_SHORT_NAME - 1) AS BYTE
    Misc AS IMAGE_SECTION_HEADER_union
    VirtualAddress AS DWORD
    SizeOfRawData AS DWORD
    PointerToRawData AS DWORD
    PointerToRelocations AS DWORD
    PointerToLinenumbers AS DWORD
    NumberOfRelocations AS WORD
    NumberOfLinenumbers AS WORD
    Characteristics AS DWORD
END TYPE

%IMAGE_SIZEOF_SECTION_HEADER        = 40

'
' Section characteristics.
'
'      IMAGE_SCN_TYPE_REG                   &H00000000  ' Reserved.
'      IMAGE_SCN_TYPE_DSECT                 &H00000001  ' Reserved.
'      IMAGE_SCN_TYPE_NOLOAD                &H00000002  ' Reserved.
'      IMAGE_SCN_TYPE_GROUP                 &H00000004  ' Reserved.
%IMAGE_SCN_TYPE_NO_PAD              = &H00000008  ' Reserved.
'      IMAGE_SCN_TYPE_COPY                  &H00000010  ' Reserved.

%IMAGE_SCN_CNT_CODE                 = &H00000020  ' Section contains code.
%IMAGE_SCN_CNT_INITIALIZED_DATA     = &H00000040  ' Section contains initialized data.
%IMAGE_SCN_CNT_UNINITIALIZED_DATA   = &H00000080  ' Section contains uninitialized data.

%IMAGE_SCN_LNK_OTHER                = &H00000100  ' Reserved.
%IMAGE_SCN_LNK_INFO                 = &H00000200  ' Section contains comments or some other type of information.
'      IMAGE_SCN_TYPE_OVER                  &H00000400  ' Reserved.
%IMAGE_SCN_LNK_REMOVE               = &H00000800  ' Section contents will not become part of image.
%IMAGE_SCN_LNK_COMDAT               = &H00001000  ' Section contents comdat.
'                                           &H00002000  ' Reserved.
'      IMAGE_SCN_MEM_PROTECTED - Obsolete   &H00004000
%IMAGE_SCN_NO_DEFER_SPEC_EXC        = &H00004000  ' Reset speculative exceptions handling bits in the TLB entries for this section.
%IMAGE_SCN_GPREL                    = &H00008000  ' Section content can be accessed relative to GP
%IMAGE_SCN_MEM_FARDATA              = &H00008000
'      IMAGE_SCN_MEM_SYSHEAP  - Obsolete    &H00010000
%IMAGE_SCN_MEM_PURGEABLE            = &H00020000
%IMAGE_SCN_MEM_16BIT                = &H00020000
%IMAGE_SCN_MEM_LOCKED               = &H00040000
%IMAGE_SCN_MEM_PRELOAD              = &H00080000

%IMAGE_SCN_ALIGN_1BYTES             = &H00100000  '
%IMAGE_SCN_ALIGN_2BYTES             = &H00200000  '
%IMAGE_SCN_ALIGN_4BYTES             = &H00300000  '
%IMAGE_SCN_ALIGN_8BYTES             = &H00400000  '
%IMAGE_SCN_ALIGN_16BYTES            = &H00500000  ' Default alignment if no others are specified.
%IMAGE_SCN_ALIGN_32BYTES            = &H00600000  '
%IMAGE_SCN_ALIGN_64BYTES            = &H00700000  '
%IMAGE_SCN_ALIGN_128BYTES           = &H00800000  '
%IMAGE_SCN_ALIGN_256BYTES           = &H00900000  '
%IMAGE_SCN_ALIGN_512BYTES           = &H00A00000  '
%IMAGE_SCN_ALIGN_1024BYTES          = &H00B00000  '
%IMAGE_SCN_ALIGN_2048BYTES          = &H00C00000  '
%IMAGE_SCN_ALIGN_4096BYTES          = &H00D00000  '
%IMAGE_SCN_ALIGN_8192BYTES          = &H00E00000  '
' Unused                                    &H00F00000
%IMAGE_SCN_ALIGN_MASK               = &H00F00000

%IMAGE_SCN_LNK_NRELOC_OVFL          = &H01000000  ' Section contains extended relocations.
%IMAGE_SCN_MEM_DISCARDABLE          = &H02000000  ' Section can be discarded.
%IMAGE_SCN_MEM_NOT_CACHED           = &H04000000  ' Section is not cachable.
%IMAGE_SCN_MEM_NOT_PAGED            = &H08000000  ' Section is not pageable.
%IMAGE_SCN_MEM_SHARED               = &H10000000  ' Section is shareable.
%IMAGE_SCN_MEM_EXECUTE              = &H20000000  ' Section is executable.
%IMAGE_SCN_MEM_READ                 = &H40000000  ' Section is readable.
%IMAGE_SCN_MEM_WRITE                = &H80000000 ' Section is writeable.

'
' TLS Chaacteristic Flags
'
%IMAGE_SCN_SCALE_INDEX              = &H00000001  ' Tls index is scaled


'
' Symbol format.
'

TYPE IMAGE_SYMBOL_type
    dShort AS DWORD        ' if 0, use LongName
    dLong  AS DWORD        ' offset into string table
END TYPE

UNION IMAGE_SYMBOL_union
    ShortName(7) AS BYTE
    nName        AS IMAGE_SYMBOL_type
    LongName(1)  AS DWORD       ' PBYTE [2]
END UNION

TYPE IMAGE_SYMBOL
    N                  AS IMAGE_SYMBOL_union
    Value              AS DWORD
    SectionNumber      AS INTEGER
    wType              AS WORD
    StorageClass       AS BYTE
    NumberOfAuxSymbols AS BYTE
END TYPE


%IMAGE_SIZEOF_SYMBOL         = 18

'
' Section values.
'
' Symbols have a section number of the section in which they are
' defined. Otherwise, section numbers have the following meanings:
'

%IMAGE_SYM_UNDEFINED         = 0           ' Symbol is undefined or is common.
%IMAGE_SYM_ABSOLUTE          = -1          ' Symbol is an absolute value.
%IMAGE_SYM_DEBUG             = -2          ' Symbol is a special debug item.
%IMAGE_SYM_SECTION_MAX       = &HFEFF??    ' Values &HFF00-&HFFFF are special

'
' Type (fundamental) values.
'

%IMAGE_SYM_TYPE_NULL               = &H0000  ' no type.
%IMAGE_SYM_TYPE_VOID               = &H0001  '
%IMAGE_SYM_TYPE_CHAR               = &H0002  ' type character.
%IMAGE_SYM_TYPE_SHORT              = &H0003  ' type short integer.
%IMAGE_SYM_TYPE_INT                = &H0004  '
%IMAGE_SYM_TYPE_LONG               = &H0005  '
%IMAGE_SYM_TYPE_FLOAT              = &H0006  '
%IMAGE_SYM_TYPE_DOUBLE             = &H0007  '
%IMAGE_SYM_TYPE_STRUCT             = &H0008  '
%IMAGE_SYM_TYPE_UNION              = &H0009  '
%IMAGE_SYM_TYPE_ENUM               = &H000A  ' enumeration.
%IMAGE_SYM_TYPE_MOE                = &H000B  ' member of enumeration.
%IMAGE_SYM_TYPE_BYTE               = &H000C  '
%IMAGE_SYM_TYPE_WORD               = &H000D  '
%IMAGE_SYM_TYPE_UINT               = &H000E  '
%IMAGE_SYM_TYPE_DWORD              = &H000F  '
%IMAGE_SYM_TYPE_PCODE              = &H8000??  '
'
' Type (derived) values.
'

%IMAGE_SYM_DTYPE_NULL              = 0       ' no derived type.
%IMAGE_SYM_DTYPE_POINTER           = 1       ' pointer.
%IMAGE_SYM_DTYPE_FUNCTION          = 2       ' function.
%IMAGE_SYM_DTYPE_ARRAY             = 3       ' array.

'
' Storage classes.
'
%IMAGE_SYM_CLASS_END_OF_FUNCTION   = &H00FF  '(BYTE )-1
%IMAGE_SYM_CLASS_NULL              = &H0000
%IMAGE_SYM_CLASS_AUTOMATIC         = &H0001
%IMAGE_SYM_CLASS_EXTERNAL          = &H0002
%IMAGE_SYM_CLASS_STATIC            = &H0003
%IMAGE_SYM_CLASS_REGISTER          = &H0004
%IMAGE_SYM_CLASS_EXTERNAL_DEF      = &H0005
%IMAGE_SYM_CLASS_LABEL             = &H0006
%IMAGE_SYM_CLASS_UNDEFINED_LABEL   = &H0007
%IMAGE_SYM_CLASS_MEMBER_OF_STRUCT  = &H0008
%IMAGE_SYM_CLASS_ARGUMENT          = &H0009
%IMAGE_SYM_CLASS_STRUCT_TAG        = &H000A
%IMAGE_SYM_CLASS_MEMBER_OF_UNION   = &H000B
%IMAGE_SYM_CLASS_UNION_TAG         = &H000C
%IMAGE_SYM_CLASS_TYPE_DEFINITION   = &H000D
%IMAGE_SYM_CLASS_UNDEFINED_STATIC  = &H000E
%IMAGE_SYM_CLASS_ENUM_TAG          = &H000F
%IMAGE_SYM_CLASS_MEMBER_OF_ENUM    = &H0010
%IMAGE_SYM_CLASS_REGISTER_PARAM    = &H0011
%IMAGE_SYM_CLASS_BIT_FIELD         = &H0012

%IMAGE_SYM_CLASS_FAR_EXTERNAL      = &H0044  '

%IMAGE_SYM_CLASS_BLOCK             = &H0064
%IMAGE_SYM_CLASS_FUNCTION          = &H0065
%IMAGE_SYM_CLASS_END_OF_STRUCT     = &H0066
%IMAGE_SYM_CLASS_FILE              = &H0067
' new
%IMAGE_SYM_CLASS_SECTION           = &H0068
%IMAGE_SYM_CLASS_WEAK_EXTERNAL     = &H0069

%IMAGE_SYM_CLASS_CLR_TOKEN         = &H006B

' type packing constants

%N_BTMASK                          = &H000F
%N_TMASK                           = &H0030
%N_TMASK1                          = &H00C0
%N_TMASK2                          = &H00F0
%N_BTSHFT                          = 4
%N_TSHIFT                          = 2
' MACROS

' Basic Type of  x
MACRO BTYPE_macro(x)=((x) AND %N_BTMASK)

' Is x a pointer?
#IF NOT %DEF(%ISPTR)
MACRO ISPTR(x)=(((x) AND %N_TMASK) = DWORDSHL(%IMAGE_SYM_DTYPE_POINTER,%N_BTSHFT))
#ENDIF

' Is x a function?
#IF NOT %DEF(%ISFCN)
MACRO ISFCN(x)=(((x) AND %N_TMASK) = DWORDSHL(%IMAGE_SYM_DTYPE_FUNCTION,%N_BTSHFT))
#ENDIF

' Is x an array?

#IF NOT %DEF(%ISARY)
MACRO ISARY(x)=(((x) AND %N_TMASK) = DWORDSHL(%IMAGE_SYM_DTYPE_ARRAY, %N_BTSHFT))
#ENDIF

' Is x a structure, union, or enumeration TAG?
#IF NOT %DEF(%ISTAG)
MACRO ISTAG(x)=((x)=%IMAGE_SYM_CLASS_STRUCT_TAG OR (x)=%IMAGE_SYM_CLASS_UNION_TAG OR (x)=%IMAGE_SYM_CLASS_ENUM_TAG)
#ENDIF

#IF NOT %DEF(%INCREF)
MACRO INCREF(x)=((DWORDSHL((x) AND NOT %N_BTMASK,%N_TSHIFT) OR (DWORDSHL(%IMAGE_SYM_DTYPE_POINTER,%N_BTSHFT)) OR ((x) AND %N_BTMASK))
#ENDIF
#IF NOT %DEF(%DECREF)
MACRO DECREF(x)=((DWORDSHR((x),%N_TSHIFT) AND NOT %N_BTMASK) OR ((x) AND %N_BTMASK))
#ENDIF

'
' Auxiliary entry format.
'

TYPE IMAGE_AUX_SYMBOL_type5
    Length              AS DWORD         ' section length
    NumberOfRelocations AS WORD          ' number of relocation entries
    NumberOfLinenumbers AS WORD          ' number of line numbers
    CheckSum            AS DWORD         ' checksum for communal
    Number              AS INTEGER       ' section number to associate with
    SELECTION           AS BYTE          ' communal selection type
END TYPE

TYPE IMAGE_AUX_SYMBOL_type4
    bName(%IMAGE_SIZEOF_SYMBOL-1) AS BYTE
END TYPE

TYPE IMAGE_AUX_SYMBOL_type2
    PointerToLinenumber   AS DWORD
    PointerToNextFunction AS DWORD
END TYPE

TYPE IMAGE_AUX_SYMBOL_type3
    Dimension(3) AS WORD
END TYPE

UNION IMAGE_AUX_SYMBOL_union2
    tFunction AS IMAGE_AUX_SYMBOL_type2  ' if ISFCN, tag, or .bb
    tArray    AS IMAGE_AUX_SYMBOL_type3  ' if ISARY, up to 4 dimen.
END UNION

TYPE IMAGE_AUX_SYMBOL_type1
    Linenumber AS WORD             ' declaration line number
    nSize      AS WORD             ' size of struct, union, or enum
END TYPE

UNION IMAGE_AUX_SYMBOL_union1
    LnSz      AS IMAGE_AUX_SYMBOL_type1
    TotalSize AS DWORD
END UNION

TYPE IMAGE_AUX_SYMBOL_type
    TagIndex AS DWORD                      ' struct, union, or enum tag index
    Misc     AS IMAGE_AUX_SYMBOL_union1
    FcnAry   AS IMAGE_AUX_SYMBOL_union1
    TvIndex  AS WORD                       ' tv index
END TYPE

UNION IMAGE_AUX_SYMBOL
    Sym     AS IMAGE_AUX_SYMBOL_type
    File    AS IMAGE_AUX_SYMBOL_type4
    Section AS IMAGE_AUX_SYMBOL_type5
END UNION

MACRO IMAGE_AUX_SYMBOL_TYPE_enum=LONG
ENUM IMAGE_AUX_SYMBOL_TYPE SINGULAR
    IMAGE_AUX_SYMBOL_TYPE_TOKEN_DEF = 1
END ENUM

TYPE IMAGE_AUX_SYMBOL_TOKEN_DEF
    bAuxType AS BYTE                    ' IMAGE_AUX_SYMBOL_TYPE
    bReserved AS BYTE                   ' Must be 0
    SymbolTableIndex AS DWORD
    rgbReserved(11) AS BYTE             ' Must be 0
END TYPE

'
' Communal selection types.
'

%IMAGE_COMDAT_SELECT_NODUPLICATES   = 1
%IMAGE_COMDAT_SELECT_ANY            = 2
%IMAGE_COMDAT_SELECT_SAME_SIZE      = 3
%IMAGE_COMDAT_SELECT_EXACT_MATCH    = 4
%IMAGE_COMDAT_SELECT_ASSOCIATIVE    = 5
%IMAGE_COMDAT_SELECT_LARGEST        = 6
%IMAGE_COMDAT_SELECT_NEWEST         = 7

%IMAGE_WEAK_EXTERN_SEARCH_NOLIBRARY = 1
%IMAGE_WEAK_EXTERN_SEARCH_LIBRARY   = 2
%IMAGE_WEAK_EXTERN_SEARCH_ALIAS     = 3

'
' Relocation format.
'

UNION IMAGE_RELOCATION_union
    VirtualAddress AS DWORD
    RelocCount     AS DWORD   ' Set to the real count when IMAGE_SCN_LNK_NRELOC_OVFL is set
END UNION

TYPE IMAGE_RELOCATION
    IMAGE_RELOCATION_union
    SymbolTableIndex AS DWORD
    nType            AS WORD
END TYPE

'
' I386 relocation types.
'
%IMAGE_REL_I386_ABSOLUTE        = &H0000  ' Reference is absolute, no relocation is necessary
%IMAGE_REL_I386_DIR16           = &H0001  ' Direct 16-bit reference to the symbols virtual address
%IMAGE_REL_I386_REL16           = &H0002  ' PC-relative 16-bit reference to the symbols virtual address
%IMAGE_REL_I386_DIR32           = &H0006  ' Direct 32-bit reference to the symbols virtual address
%IMAGE_REL_I386_DIR32NB         = &H0007  ' Direct 32-bit reference to the symbols virtual address, base not included
%IMAGE_REL_I386_SEG12           = &H0009  ' Direct 16-bit reference to the segment-selector bits of a 32-bit virtual address
%IMAGE_REL_I386_SECTION         = &H000A
%IMAGE_REL_I386_SECREL          = &H000B
%IMAGE_REL_I386_TOKEN           = &H000C  ' clr token
%IMAGE_REL_I386_SECREL7         = &H000D  ' 7 bit offset from base of section containing target
%IMAGE_REL_I386_REL32           = &H0014  ' PC-relative 32-bit reference to the symbols virtual address

'
' MIPS relocation types.
'
%IMAGE_REL_MIPS_ABSOLUTE        = &H0000  ' Reference is absolute, no relocation is necessary
%IMAGE_REL_MIPS_REFHALF         = &H0001
%IMAGE_REL_MIPS_REFWORD         = &H0002
%IMAGE_REL_MIPS_JMPADDR         = &H0003
%IMAGE_REL_MIPS_REFHI           = &H0004
%IMAGE_REL_MIPS_REFLO           = &H0005
%IMAGE_REL_MIPS_GPREL           = &H0006
%IMAGE_REL_MIPS_LITERAL         = &H0007
%IMAGE_REL_MIPS_SECTION         = &H000A
%IMAGE_REL_MIPS_SECREL          = &H000B
%IMAGE_REL_MIPS_SECRELLO        = &H000C  ' Low 16-bit section relative referemce (used for >32k TLS)
%IMAGE_REL_MIPS_SECRELHI        = &H000D  ' High 16-bit section relative reference (used for >32k TLS)
%IMAGE_REL_MIPS_TOKEN           = &H000E  ' clr token
%IMAGE_REL_MIPS_JMPADDR16       = &H0010
%IMAGE_REL_MIPS_REFWORDNB       = &H0022
%IMAGE_REL_MIPS_PAIR            = &H0025

'
' Alpha Relocation types.
'
%IMAGE_REL_ALPHA_ABSOLUTE       = &H0000
%IMAGE_REL_ALPHA_REFLONG        = &H0001
%IMAGE_REL_ALPHA_REFQUAD        = &H0002
%IMAGE_REL_ALPHA_GPREL32        = &H0003
%IMAGE_REL_ALPHA_LITERAL        = &H0004
%IMAGE_REL_ALPHA_LITUSE         = &H0005
%IMAGE_REL_ALPHA_GPDISP         = &H0006
%IMAGE_REL_ALPHA_BRADDR         = &H0007
%IMAGE_REL_ALPHA_HINT           = &H0008
%IMAGE_REL_ALPHA_INLINE_REFLONG = &H0009
%IMAGE_REL_ALPHA_REFHI          = &H000A
%IMAGE_REL_ALPHA_REFLO          = &H000B
%IMAGE_REL_ALPHA_PAIR           = &H000C
%IMAGE_REL_ALPHA_MATCH          = &H000D
%IMAGE_REL_ALPHA_SECTION        = &H000E
%IMAGE_REL_ALPHA_SECREL         = &H000F
%IMAGE_REL_ALPHA_REFLONGNB      = &H0010
%IMAGE_REL_ALPHA_SECRELLO       = &H0011  ' Low 16-bit section relative reference
%IMAGE_REL_ALPHA_SECRELHI       = &H0012  ' High 16-bit section relative reference
%IMAGE_REL_ALPHA_REFQ3          = &H0013  ' High 16 bits of 48 bit reference
%IMAGE_REL_ALPHA_REFQ2          = &H0014  ' Middle 16 bits of 48 bit reference
%IMAGE_REL_ALPHA_REFQ1          = &H0015  ' Low 16 bits of 48 bit reference
%IMAGE_REL_ALPHA_GPRELLO        = &H0016  ' Low 16-bit GP relative reference
%IMAGE_REL_ALPHA_GPRELHI        = &H0017  ' High 16-bit GP relative reference

'
' IBM PowerPC relocation types.
'
%IMAGE_REL_PPC_ABSOLUTE         = &H0000  ' NOP
%IMAGE_REL_PPC_ADDR64           = &H0001  ' 64-bit address
%IMAGE_REL_PPC_ADDR32           = &H0002  ' 32-bit address
%IMAGE_REL_PPC_ADDR24           = &H0003  ' 26-bit address, shifted left 2 (branch absolute)
%IMAGE_REL_PPC_ADDR16           = &H0004  ' 16-bit address
%IMAGE_REL_PPC_ADDR14           = &H0005  ' 16-bit address, shifted left 2 (load doubleword)
%IMAGE_REL_PPC_REL24            = &H0006  ' 26-bit PC-relative offset, shifted left 2 (branch relative)
%IMAGE_REL_PPC_REL14            = &H0007  ' 16-bit PC-relative offset, shifted left 2 (br cond relative)
%IMAGE_REL_PPC_TOCREL16         = &H0008  ' 16-bit offset from TOC base
%IMAGE_REL_PPC_TOCREL14         = &H0009  ' 16-bit offset from TOC base, shifted left 2 (load doubleword)

%IMAGE_REL_PPC_ADDR32NB         = &H000A  ' 32-bit addr w/o image base
%IMAGE_REL_PPC_SECREL           = &H000B  ' va of containing section (as in an image sectionhdr)
%IMAGE_REL_PPC_SECTION          = &H000C  ' sectionheader number
%IMAGE_REL_PPC_IFGLUE           = &H000D  ' substitute TOC restore instruction iff symbol is glue code
%IMAGE_REL_PPC_IMGLUE           = &H000E  ' symbol is glue code; virtual address is TOC restore instruction
%IMAGE_REL_PPC_SECREL16         = &H000F  ' va of containing section (limited to 16 bits)
%IMAGE_REL_PPC_REFHI            = &H0010
%IMAGE_REL_PPC_REFLO            = &H0011
%IMAGE_REL_PPC_PAIR             = &H0012
%IMAGE_REL_PPC_SECRELLO         = &H0013  ' Low 16-bit section relative reference (used for >32k TLS)
%IMAGE_REL_PPC_SECRELHI         = &H0014  ' High 16-bit section relative reference (used for >32k TLS)
%IMAGE_REL_PPC_GPREL            = &H0015
%IMAGE_REL_PPC_TOKEN            = &H0016  ' clr token

%IMAGE_REL_PPC_TYPEMASK         = &H00FF  ' mask to isolate above values in IMAGE_RELOCATION.Type

' Flag bits in IMAGE_RELOCATION.TYPE

%IMAGE_REL_PPC_NEG              = &H0100  ' subtract reloc value rather than adding it
%IMAGE_REL_PPC_BRTAKEN          = &H0200  ' fix branch prediction bit to predict branch taken
%IMAGE_REL_PPC_BRNTAKEN         = &H0400  ' fix branch prediction bit to predict branch not taken
%IMAGE_REL_PPC_TOCDEFN          = &H0800  ' toc slot defined in file (or, data in toc)

'
' Hitachi SH3 relocation types.
'
%IMAGE_REL_SH3_ABSOLUTE         = &H0000  ' No relocation
%IMAGE_REL_SH3_DIRECT16         = &H0001  ' 16 bit direct
%IMAGE_REL_SH3_DIRECT32         = &H0002  ' 32 bit direct
%IMAGE_REL_SH3_DIRECT8          = &H0003  ' 8 bit direct, -128..255
%IMAGE_REL_SH3_DIRECT8_WORD     = &H0004  ' 8 bit direct .W (0 ext.)
%IMAGE_REL_SH3_DIRECT8_LONG     = &H0005  ' 8 bit direct .L (0 ext.)
%IMAGE_REL_SH3_DIRECT4          = &H0006  ' 4 bit direct (0 ext.)
%IMAGE_REL_SH3_DIRECT4_WORD     = &H0007  ' 4 bit direct .W (0 ext.)
%IMAGE_REL_SH3_DIRECT4_LONG     = &H0008  ' 4 bit direct .L (0 ext.)
%IMAGE_REL_SH3_PCREL8_WORD      = &H0009  ' 8 bit PC relative .W
%IMAGE_REL_SH3_PCREL8_LONG      = &H000A  ' 8 bit PC relative .L
%IMAGE_REL_SH3_PCREL12_WORD     = &H000B  ' 12 LSB PC relative .W
%IMAGE_REL_SH3_STARTOF_SECTION  = &H000C  ' Start of EXE section
%IMAGE_REL_SH3_SIZEOF_SECTION   = &H000D  ' Size of EXE section
%IMAGE_REL_SH3_SECTION          = &H000E  ' Section table index
%IMAGE_REL_SH3_SECREL           = &H000F  ' Offset within section
%IMAGE_REL_SH3_DIRECT32_NB      = &H0010  ' 32 bit direct not based
%IMAGE_REL_SH3_GPREL4_LONG      = &H0011  ' GP-relative addressing
%IMAGE_REL_SH3_TOKEN            = &H0012  ' clr token
%IMAGE_REL_SHM_PCRELPT          = &H0013  ' Offset from current
                                                '  instruction in longwords
                                                '  if not NOMODE, insert the
                                                '  inverse of the low bit at
                                                '  bit 32 to select PTA/PTB
%IMAGE_REL_SHM_REFLO            = &H0014  ' Low bits of 32-bit address
%IMAGE_REL_SHM_REFHALF          = &H0015  ' High bits of 32-bit address
%IMAGE_REL_SHM_RELLO            = &H0016  ' Low bits of relative reference
%IMAGE_REL_SHM_RELHALF          = &H0017  ' High bits of relative reference
%IMAGE_REL_SHM_PAIR             = &H0018  ' offset operand for relocation

%IMAGE_REL_SH_NOMODE            = &H8000??  ' relocation ignores section mode


%IMAGE_REL_ARM_ABSOLUTE         = &H0000  ' No relocation required
%IMAGE_REL_ARM_ADDR32           = &H0001  ' 32 bit address
%IMAGE_REL_ARM_ADDR32NB         = &H0002  ' 32 bit address w/o image base
%IMAGE_REL_ARM_BRANCH24         = &H0003  ' 24 bit offset << 2 & sign ext.
%IMAGE_REL_ARM_BRANCH11         = &H0004  ' Thumb: 2 11 bit offsets
%IMAGE_REL_ARM_TOKEN            = &H0005  ' clr token
%IMAGE_REL_ARM_GPREL12          = &H0006  ' GP-relative addressing (ARM)
%IMAGE_REL_ARM_GPREL7           = &H0007  ' GP-relative addressing (Thumb)
%IMAGE_REL_ARM_BLX24            = &H0008
%IMAGE_REL_ARM_BLX11            = &H0009
%IMAGE_REL_ARM_SECTION          = &H000E  ' Section table index
%IMAGE_REL_ARM_SECREL           = &H000F  ' Offset within section

%IMAGE_REL_AM_ABSOLUTE          = &H0000
%IMAGE_REL_AM_ADDR32            = &H0001
%IMAGE_REL_AM_ADDR32NB          = &H0002
%IMAGE_REL_AM_CALL32            = &H0003
%IMAGE_REL_AM_FUNCINFO          = &H0004
%IMAGE_REL_AM_REL32_1           = &H0005
%IMAGE_REL_AM_REL32_2           = &H0006
%IMAGE_REL_AM_SECREL            = &H0007
%IMAGE_REL_AM_SECTION           = &H0008
%IMAGE_REL_AM_TOKEN             = &H0009

'
' x64 relocations
'
%IMAGE_REL_AMD64_ABSOLUTE       = &H0000  ' Reference is absolute, no relocation is necessary
%IMAGE_REL_AMD64_ADDR64         = &H0001  ' 64-bit address (VA).
%IMAGE_REL_AMD64_ADDR32         = &H0002  ' 32-bit address (VA).
%IMAGE_REL_AMD64_ADDR32NB       = &H0003  ' 32-bit address w/o image base (RVA).
%IMAGE_REL_AMD64_REL32          = &H0004  ' 32-bit relative address from byte following reloc
%IMAGE_REL_AMD64_REL32_1        = &H0005  ' 32-bit relative address from byte distance 1 from reloc
%IMAGE_REL_AMD64_REL32_2        = &H0006  ' 32-bit relative address from byte distance 2 from reloc
%IMAGE_REL_AMD64_REL32_3        = &H0007  ' 32-bit relative address from byte distance 3 from reloc
%IMAGE_REL_AMD64_REL32_4        = &H0008  ' 32-bit relative address from byte distance 4 from reloc
%IMAGE_REL_AMD64_REL32_5        = &H0009  ' 32-bit relative address from byte distance 5 from reloc
%IMAGE_REL_AMD64_SECTION        = &H000A  ' Section index
%IMAGE_REL_AMD64_SECREL         = &H000B  ' 32 bit offset from base of section containing target
%IMAGE_REL_AMD64_SECREL7        = &H000C  ' 7 bit unsigned offset from base of section containing target
%IMAGE_REL_AMD64_TOKEN          = &H000D  ' 32 bit metadata token
%IMAGE_REL_AMD64_SREL32         = &H000E  ' 32 bit signed span-dependent value emitted into object
%IMAGE_REL_AMD64_PAIR           = &H000F
%IMAGE_REL_AMD64_SSPAN32        = &H0010  ' 32 bit signed span-dependent value applied at link time

'
' IA64 relocation types.
'
%IMAGE_REL_IA64_ABSOLUTE        = &H0000
%IMAGE_REL_IA64_IMM14           = &H0001
%IMAGE_REL_IA64_IMM22           = &H0002
%IMAGE_REL_IA64_IMM64           = &H0003
%IMAGE_REL_IA64_DIR32           = &H0004
%IMAGE_REL_IA64_DIR64           = &H0005
%IMAGE_REL_IA64_PCREL21B        = &H0006
%IMAGE_REL_IA64_PCREL21M        = &H0007
%IMAGE_REL_IA64_PCREL21F        = &H0008
%IMAGE_REL_IA64_GPREL22         = &H0009
%IMAGE_REL_IA64_LTOFF22         = &H000A
%IMAGE_REL_IA64_SECTION         = &H000B
%IMAGE_REL_IA64_SECREL22        = &H000C
%IMAGE_REL_IA64_SECREL64I       = &H000D
%IMAGE_REL_IA64_SECREL32        = &H000E
'
%IMAGE_REL_IA64_DIR32NB         = &H0010
%IMAGE_REL_IA64_SREL14          = &H0011
%IMAGE_REL_IA64_SREL22          = &H0012
%IMAGE_REL_IA64_SREL32          = &H0013
%IMAGE_REL_IA64_UREL32          = &H0014
%IMAGE_REL_IA64_PCREL60X        = &H0015  ' This is always a BRL and never converted
%IMAGE_REL_IA64_PCREL60B        = &H0016  ' If possible, convert to MBB bundle with NOP.B in slot 1
%IMAGE_REL_IA64_PCREL60F        = &H0017  ' If possible, convert to MFB bundle with NOP.F in slot 1
%IMAGE_REL_IA64_PCREL60I        = &H0018  ' If possible, convert to MIB bundle with NOP.I in slot 1
%IMAGE_REL_IA64_PCREL60M        = &H0019  ' If possible, convert to MMB bundle with NOP.M in slot 1
%IMAGE_REL_IA64_IMMGPREL64      = &H001A
%IMAGE_REL_IA64_TOKEN           = &H001B  ' clr token
%IMAGE_REL_IA64_GPREL32         = &H001C
%IMAGE_REL_IA64_ADDEND          = &H001F

'
' CEF relocation types.
'
%IMAGE_REL_CEF_ABSOLUTE         = &H0000  ' Reference is absolute, no relocation is necessary
%IMAGE_REL_CEF_ADDR32           = &H0001  ' 32-bit address (VA).
%IMAGE_REL_CEF_ADDR64           = &H0002  ' 64-bit address (VA).
%IMAGE_REL_CEF_ADDR32NB         = &H0003  ' 32-bit address w/o image base (RVA).
%IMAGE_REL_CEF_SECTION          = &H0004  ' Section index
%IMAGE_REL_CEF_SECREL           = &H0005  ' 32 bit offset from base of section containing target
%IMAGE_REL_CEF_TOKEN            = &H0006  ' 32 bit metadata token

'
' clr relocation types.
'
%IMAGE_REL_CEE_ABSOLUTE         = &H0000  ' Reference is absolute, no relocation is necessary
%IMAGE_REL_CEE_ADDR32           = &H0001  ' 32-bit address (VA).
%IMAGE_REL_CEE_ADDR64           = &H0002  ' 64-bit address (VA).
%IMAGE_REL_CEE_ADDR32NB         = &H0003  ' 32-bit address w/o image base (RVA).
%IMAGE_REL_CEE_SECTION          = &H0004  ' Section index
%IMAGE_REL_CEE_SECREL           = &H0005  ' 32 bit offset from base of section containing target
%IMAGE_REL_CEE_TOKEN            = &H0006  ' 32 bit metadata token


%IMAGE_REL_M32R_ABSOLUTE        = &H0000  ' No relocation required
%IMAGE_REL_M32R_ADDR32          = &H0001  ' 32 bit address
%IMAGE_REL_M32R_ADDR32NB        = &H0002  ' 32 bit address w/o image base
%IMAGE_REL_M32R_ADDR24          = &H0003  ' 24 bit address
%IMAGE_REL_M32R_GPREL16         = &H0004  ' GP relative addressing
%IMAGE_REL_M32R_PCREL24         = &H0005  ' 24 bit offset << 2 & sign ext.
%IMAGE_REL_M32R_PCREL16         = &H0006  ' 16 bit offset << 2 & sign ext.
%IMAGE_REL_M32R_PCREL8          = &H0007  ' 8 bit offset << 2 & sign ext.
%IMAGE_REL_M32R_REFHALF         = &H0008  ' 16 MSBs
%IMAGE_REL_M32R_REFHI           = &H0009  ' 16 MSBs; adj for LSB sign ext.
%IMAGE_REL_M32R_REFLO           = &H000A  ' 16 LSBs
%IMAGE_REL_M32R_PAIR            = &H000B  ' Link HI and LO
%IMAGE_REL_M32R_SECTION         = &H000C  ' Section table index
%IMAGE_REL_M32R_SECREL32        = &H000D  ' 32 bit section relative reference
%IMAGE_REL_M32R_TOKEN           = &H000E  ' clr token

%IMAGE_REL_EBC_ABSOLUTE         = &H0000  ' No relocation required
%IMAGE_REL_EBC_ADDR32NB         = &H0001  ' 32 bit address w/o image base
%IMAGE_REL_EBC_REL32            = &H0002  ' 32-bit relative address from byte following reloc
%IMAGE_REL_EBC_SECTION          = &H0003  ' Section table index
%IMAGE_REL_EBC_SECREL           = &H0004  ' Offset within section

'MACRO EXT_IMM64(Value, Address, Size, InstPos, ValPos)  ' Intel-IA64-Filler            _
'    Value OR= (((QUAD)((*(Address) >> InstPos) & (((QUAD)1 << Size) - 1))) << ValPos)  ' Intel-IA64-Filler

'MACRO INS_IMM64(Value, Address, Size, InstPos, ValPos)  ' Intel-IA64-Filler _
'    *(PDWORD)Address = (*(PDWORD)Address & ~(((1 << Size) - 1) << InstPos)) OR ' Intel-IA64-Filler _
'          ((DWORD)((((QUAD)Value >> ValPos) & (((QUAD)1 << Size) - 1))) << InstPos)  ' Intel-IA64-Filler

%EMARCH_ENC_I17_IMM7B_INST_WORD_X        = 3  ' Intel-IA64-Filler
%EMARCH_ENC_I17_IMM7B_SIZE_X             = 7  ' Intel-IA64-Filler
%EMARCH_ENC_I17_IMM7B_INST_WORD_POS_X    = 4  ' Intel-IA64-Filler
%EMARCH_ENC_I17_IMM7B_VAL_POS_X          = 0  ' Intel-IA64-Filler

%EMARCH_ENC_I17_IMM9D_INST_WORD_X        = 3  ' Intel-IA64-Filler
%EMARCH_ENC_I17_IMM9D_SIZE_X             = 9  ' Intel-IA64-Filler
%EMARCH_ENC_I17_IMM9D_INST_WORD_POS_X    = 18 ' Intel-IA64-Filler
%EMARCH_ENC_I17_IMM9D_VAL_POS_X          = 7  ' Intel-IA64-Filler

%EMARCH_ENC_I17_IMM5C_INST_WORD_X        = 3  ' Intel-IA64-Filler
%EMARCH_ENC_I17_IMM5C_SIZE_X             = 5  ' Intel-IA64-Filler
%EMARCH_ENC_I17_IMM5C_INST_WORD_POS_X    = 13 ' Intel-IA64-Filler
%EMARCH_ENC_I17_IMM5C_VAL_POS_X          = 16 ' Intel-IA64-Filler

%EMARCH_ENC_I17_IC_INST_WORD_X           = 3  ' Intel-IA64-Filler
%EMARCH_ENC_I17_IC_SIZE_X                = 1  ' Intel-IA64-Filler
%EMARCH_ENC_I17_IC_INST_WORD_POS_X       = 12 ' Intel-IA64-Filler
%EMARCH_ENC_I17_IC_VAL_POS_X             = 21 ' Intel-IA64-Filler

%EMARCH_ENC_I17_IMM41a_INST_WORD_X       = 1  ' Intel-IA64-Filler
%EMARCH_ENC_I17_IMM41a_SIZE_X            = 10 ' Intel-IA64-Filler
%EMARCH_ENC_I17_IMM41a_INST_WORD_POS_X   = 14 ' Intel-IA64-Filler
%EMARCH_ENC_I17_IMM41a_VAL_POS_X         = 22 ' Intel-IA64-Filler

%EMARCH_ENC_I17_IMM41b_INST_WORD_X       = 1  ' Intel-IA64-Filler
%EMARCH_ENC_I17_IMM41b_SIZE_X            = 8  ' Intel-IA64-Filler
%EMARCH_ENC_I17_IMM41b_INST_WORD_POS_X   = 24 ' Intel-IA64-Filler
%EMARCH_ENC_I17_IMM41b_VAL_POS_X         = 32 ' Intel-IA64-Filler

%EMARCH_ENC_I17_IMM41c_INST_WORD_X       = 2  ' Intel-IA64-Filler
%EMARCH_ENC_I17_IMM41c_SIZE_X            = 23 ' Intel-IA64-Filler
%EMARCH_ENC_I17_IMM41c_INST_WORD_POS_X   = 0  ' Intel-IA64-Filler
%EMARCH_ENC_I17_IMM41c_VAL_POS_X         = 40 ' Intel-IA64-Filler

%EMARCH_ENC_I17_SIGN_INST_WORD_X         = 3  ' Intel-IA64-Filler
%EMARCH_ENC_I17_SIGN_SIZE_X              = 1  ' Intel-IA64-Filler
%EMARCH_ENC_I17_SIGN_INST_WORD_POS_X     = 27 ' Intel-IA64-Filler
%EMARCH_ENC_I17_SIGN_VAL_POS_X           = 63 ' Intel-IA64-Filler

%X3_OPCODE_INST_WORD_X                   = 3  ' Intel-IA64-Filler
%X3_OPCODE_SIZE_X                        = 4  ' Intel-IA64-Filler
%X3_OPCODE_INST_WORD_POS_X               = 28 ' Intel-IA64-Filler
%X3_OPCODE_SIGN_VAL_POS_X                = 0  ' Intel-IA64-Filler

%X3_I_INST_WORD_X                        = 3  ' Intel-IA64-Filler
%X3_I_SIZE_X                             = 1  ' Intel-IA64-Filler
%X3_I_INST_WORD_POS_X                    = 27 ' Intel-IA64-Filler
%X3_I_SIGN_VAL_POS_X                     = 59 ' Intel-IA64-Filler

%X3_D_WH_INST_WORD_X                     = 3  ' Intel-IA64-Filler
%X3_D_WH_SIZE_X                          = 3  ' Intel-IA64-Filler
%X3_D_WH_INST_WORD_POS_X                 = 24 ' Intel-IA64-Filler
%X3_D_WH_SIGN_VAL_POS_X                  = 0  ' Intel-IA64-Filler

%X3_IMM20_INST_WORD_X                    = 3  ' Intel-IA64-Filler
%X3_IMM20_SIZE_X                         = 20 ' Intel-IA64-Filler
%X3_IMM20_INST_WORD_POS_X                = 4  ' Intel-IA64-Filler
%X3_IMM20_SIGN_VAL_POS_X                 = 0  ' Intel-IA64-Filler

%X3_IMM39_1_INST_WORD_X                  = 2  ' Intel-IA64-Filler
%X3_IMM39_1_SIZE_X                       = 23 ' Intel-IA64-Filler
%X3_IMM39_1_INST_WORD_POS_X              = 0  ' Intel-IA64-Filler
%X3_IMM39_1_SIGN_VAL_POS_X               = 36 ' Intel-IA64-Filler

%X3_IMM39_2_INST_WORD_X                  = 1  ' Intel-IA64-Filler
%X3_IMM39_2_SIZE_X                       = 16 ' Intel-IA64-Filler
%X3_IMM39_2_INST_WORD_POS_X              = 16 ' Intel-IA64-Filler
%X3_IMM39_2_SIGN_VAL_POS_X               = 20 ' Intel-IA64-Filler

%X3_P_INST_WORD_X                        = 3  ' Intel-IA64-Filler
%X3_P_SIZE_X                             = 4  ' Intel-IA64-Filler
%X3_P_INST_WORD_POS_X                    = 0  ' Intel-IA64-Filler
%X3_P_SIGN_VAL_POS_X                     = 0  ' Intel-IA64-Filler

%X3_TMPLT_INST_WORD_X                    = 0  ' Intel-IA64-Filler
%X3_TMPLT_SIZE_X                         = 4  ' Intel-IA64-Filler
%X3_TMPLT_INST_WORD_POS_X                = 0  ' Intel-IA64-Filler
%X3_TMPLT_SIGN_VAL_POS_X                 = 0  ' Intel-IA64-Filler

%X3_BTYPE_QP_INST_WORD_X                 = 2  ' Intel-IA64-Filler
%X3_BTYPE_QP_SIZE_X                      = 9  ' Intel-IA64-Filler
%X3_BTYPE_QP_INST_WORD_POS_X             = 23 ' Intel-IA64-Filler
%X3_BTYPE_QP_INST_VAL_POS_X              = 0  ' Intel-IA64-Filler

%X3_EMPTY_INST_WORD_X                    = 1  ' Intel-IA64-Filler
%X3_EMPTY_SIZE_X                         = 2  ' Intel-IA64-Filler
%X3_EMPTY_INST_WORD_POS_X                = 14 ' Intel-IA64-Filler
%X3_EMPTY_INST_VAL_POS_X                 = 0  ' Intel-IA64-Filler

'
' Line number format.
'

UNION IMAGE_LINENUMBER_union
    SymbolTableIndex AS DWORD   ' Symbol table index of function name if Linenumber is 0.
    VirtualAddress   AS DWORD   ' Virtual address of line number.
END UNION

TYPE IMAGE_LINENUMBER
    xType      AS IMAGE_LINENUMBER_union
    Linenumber AS WORD                             ' Line number.
END TYPE


'
' Based relocation format.
'

TYPE IMAGE_BASE_RELOCATION
    VirtualAddress AS DWORD
    SizeOfBlock AS DWORD
'  TypeOffset(0) as word
END TYPE

'
' Based relocation types.
'

%IMAGE_REL_BASED_ABSOLUTE           = 0
%IMAGE_REL_BASED_HIGH               = 1
%IMAGE_REL_BASED_LOW                = 2
%IMAGE_REL_BASED_HIGHLOW            = 3
%IMAGE_REL_BASED_HIGHADJ            = 4
%IMAGE_REL_BASED_MIPS_JMPADDR       = 5
%IMAGE_REL_BASED_MIPS_JMPADDR16     = 9
%IMAGE_REL_BASED_IA64_IMM64         = 9
%IMAGE_REL_BASED_DIR64              = 10


'
' Archive format.
'

%IMAGE_ARCHIVE_START_SIZE           = 8
$IMAGE_ARCHIVE_START                = CHR$("!<arch>", 10)
$IMAGE_ARCHIVE_END                  = CHR$("`", 10)
$IMAGE_ARCHIVE_PAD                  = CHR$(10)
$IMAGE_ARCHIVE_LINKER_MEMBER        = "/               "
$IMAGE_ARCHIVE_LONGNAMES_MEMBER     = "//              "

TYPE IMAGE_ARCHIVE_MEMBER_HEADER
    bName(15) AS BYTE                              ' File member name - `/' terminated.
    Date(11) AS BYTE                               ' File member date - decimal.
    UserID(5) AS BYTE                              ' File member user id - decimal.
    GroupID(5) AS BYTE                             ' File member group id - decimal.
    bMode(7) AS BYTE                               ' File member mode - octal.
    bSize(9) AS BYTE                               ' File member size - decimal.
    EndHeader(1) AS BYTE                           ' String to end header.
END TYPE

%IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR     = 60

'
' DLL support.
'

'
' Export Format
'

TYPE IMAGE_EXPORT_DIRECTORY
    Characteristics       AS DWORD
    TimeDateStamp         AS DWORD
    MajorVersion          AS WORD
    MinorVersion          AS WORD
    nName                 AS DWORD
    nBase                 AS DWORD
    NumberOfFunctions     AS DWORD
    NumberOfNames         AS DWORD
    AddressOfFunctions    AS DWORD     ' RVA from base of image
    AddressOfNames        AS DWORD     ' RVA from base of image
    AddressOfNameOrdinals AS DWORD     ' RVA from base of image
END TYPE

'
' Import Format
'

TYPE IMAGE_IMPORT_BY_NAME
    Hint AS WORD
    bName(0) AS BYTE
END TYPE


UNION IMAGE_THUNK_DATA64
    ForwarderString AS QUAD   ' PBYTE
    nFunction       AS QUAD   ' PDWORD
    Ordinal         AS QUAD
    AddressOfData   AS QUAD   ' PIMAGE_IMPORT_BY_NAME
END UNION

UNION IMAGE_THUNK_DATA32
    ForwarderString AS DWORD  ' PBYTE
    nFunction       AS DWORD  ' PDWORD
    Ordinal         AS DWORD
    AddressOfData   AS DWORD  ' PIMAGE_IMPORT_BY_NAME
END UNION

'%IMAGE_ORDINAL_FLAG64 = &H8000000000000000
%IMAGE_ORDINAL_FLAG32 = &H80000000
MACRO IMAGE_ORDINAL64(Ordinal)=LO(WORD,Ordinal)
MACRO IMAGE_ORDINAL32(Ordinal)=LO(WORD,Ordinal)
'MACRO IMAGE_SNAP_BY_ORDINAL64(Ordinal)=((Ordinal AND %IMAGE_ORDINAL_FLAG64) <> 0)
MACRO IMAGE_SNAP_BY_ORDINAL32(Ordinal)=((Ordinal AND %IMAGE_ORDINAL_FLAG32) <> 0)

'
' Thread Local Storage
'

DECLARE SUB PIMAGE_TLS_CALLBACK (BYVAL DllHandle AS DWORD, BYVAL Reason AS DWORD, _
    BYVAL Reserved AS DWORD)

TYPE IMAGE_TLS_DIRECTORY64
    StartAddressOfRawData AS QUAD
    EndAddressOfRawData AS QUAD
    AddressOfIndex AS QUAD            ' PDWORD
    AddressOfCallBacks AS QUAD        ' PIMAGE_TLS_CALLBACK *;
    SizeOfZeroFill AS DWORD
    Characteristics AS DWORD
END TYPE

TYPE IMAGE_TLS_DIRECTORY32
    StartAddressOfRawData AS DWORD
    EndAddressOfRawData   AS DWORD
    AddressOfIndex        AS DWORD    ' PDWORD
    AddressOfCallBacks    AS DWORD    ' PIMAGE_TLS_CALLBACK *
    SizeOfZeroFill        AS DWORD
    Characteristics       AS DWORD
END TYPE

#IF %DEF(%WIN64)
%IMAGE_ORDINAL_FLAG         = %IMAGE_ORDINAL_FLAG64
MACRO IMAGE_ORDINAL(Ordinal)=IMAGE_ORDINAL64(Ordinal)
MACRO IMAGE_THUNK_DATA=IMAGE_THUNK_DATA64
MACRO IMAGE_SNAP_BY_ORDINAL(Ordinal)=IMAGE_SNAP_BY_ORDINAL64(Ordinal)
MACRO IMAGE_TLS_DIRECTORY=IMAGE_TLS_DIRECTORY64
#ELSE
%IMAGE_ORDINAL_FLAG         = %IMAGE_ORDINAL_FLAG32
MACRO IMAGE_ORDINAL(Ordinal)=IMAGE_ORDINAL32(Ordinal)
MACRO IMAGE_THUNK_DATA=IMAGE_THUNK_DATA32
MACRO IMAGE_SNAP_BY_ORDINAL(Ordinal)=IMAGE_SNAP_BY_ORDINAL32(Ordinal)
MACRO IMAGE_TLS_DIRECTORY=IMAGE_TLS_DIRECTORY32
#ENDIF

UNION IMAGE_IMPORT_DESCRIPTOR_union
    Characteristics    AS DWORD  ' 0 for terminating null import descriptor
    OriginalFirstThunk AS DWORD  ' RVA to original unbound IAT (PIMAGE_THUNK_DATA)
END UNION

TYPE IMAGE_IMPORT_DESCRIPTOR
    IMAGE_IMPORT_DESCRIPTOR_union
    TimeDateStamp  AS DWORD   ' 0 if not bound,
                              ' -1 if bound, and real date_time stamp
                              '     in IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT (new BIND)
                              ' O.W. date/time stamp of DLL bound to (Old BIND)

    ForwarderChain AS DWORD   ' -1 if no forwarders
    nName          AS DWORD
    FirstThunk     AS DWORD   ' RVA to IAT (if bound this IAT has actual addresses)
END TYPE

'
' New format import descriptors pointed to by DataDirectory(%IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT-1)
'

TYPE IMAGE_BOUND_IMPORT_DESCRIPTOR
    TimeDateStamp               AS DWORD
    OffsetModuleName            AS WORD
    NumberOfModuleForwarderRefs AS WORD
' Array of zero or more IMAGE_BOUND_FORWARDER_REF follows
END TYPE

TYPE IMAGE_BOUND_FORWARDER_REF
    TimeDateStamp    AS DWORD
    OffsetModuleName AS WORD
    Reserved         AS WORD
END TYPE

'
' Resource Format.
'

'
' Resource directory consists of two counts, following by a variable length
' array of directory entries.  The first count is the number of entries at
' beginning of the array that have actual names associated with each entry.
' The entries are in ascending order, case insensitive strings.  The second
' count is the number of entries that immediately follow the named entries.
' This second count identifies the number of entries that have 16-bit integer
' Ids as their name.  These entries are also sorted in ascending order.
'
' This structure allows fast lookup by either name or number, but for any
' given resource entry only one form of lookup is supported, not both.
' This is consistant with the syntax of the .RC file and the .RES file.
'

TYPE IMAGE_RESOURCE_DIRECTORY
    Characteristics      AS DWORD
    TimeDateStamp        AS DWORD
    MajorVersion         AS WORD
    MinorVersion         AS WORD
    NumberOfNamedEntries AS WORD
    NumberOfIdEntries    AS WORD
'   DirectoryEntries()   AS IMAGE_RESOURCE_DIRECTORY_ENTRY
END TYPE

%IMAGE_RESOURCE_NAME_IS_STRING      = &H80000000
%IMAGE_RESOURCE_DATA_IS_DIRECTORY   = &H80000000
'
' Each directory contains the 32-bit Name of the entry and an offset,
' relative to the beginning of the resource directory of the data associated
' with this directory entry.  If the name of the entry is an actual text
' string instead of an integer Id, then the high order bit of the name field
' is set to one and the low order 31-bits are an offset, relative to the
' beginning of the resource directory of the string, which is of type
' IMAGE_RESOURCE_DIRECTORY_STRING.  Otherwise the high bit is clear and the
' low-order 16-bits are the integer Id that identify this resource directory
' entry. If the directory entry is yet another resource directory (i.e. a
' subdirectory), then the high order bit of the offset field will be
' set to indicate this.  Otherwise the high bit is clear and the offset
' field points to a resource data entry.
'

TYPE IMAGE_RESOURCE_DIRECTORY_ENTRY_type1
    OffsetToDirectory AS BIT * 31 IN DWORD
    DataIsDirectory   AS BIT * 1
END TYPE

UNION IMAGE_RESOURCE_DIRECTORY_ENTRY_union1
    OffsetToData AS DWORD
    IMAGE_RESOURCE_DIRECTORY_ENTRY_type1
END UNION

TYPE IMAGE_RESOURCE_DIRECTORY_ENTRY_type
    NameOffset   AS BIT * 31 IN DWORD
    NameIsString AS BIT * 1
END TYPE

UNION IMAGE_RESOURCE_DIRECTORY_ENTRY_union
    IMAGE_RESOURCE_DIRECTORY_ENTRY_type
    nName AS DWORD
    nId   AS WORD
END UNION

TYPE IMAGE_RESOURCE_DIRECTORY_ENTRY
    IMAGE_RESOURCE_DIRECTORY_ENTRY_union
    IMAGE_RESOURCE_DIRECTORY_ENTRY_union1
END TYPE

'
' For resource directory entries that have actual string names, the Name
' field of the directory entry points to an object of the following type.
' All of these string objects are stored together after the last resource
' directory entry and before the first resource data object.  This minimizes
' the impact of these variable length objects on the alignment of the fixed
' size directory entry objects.
'

TYPE IMAGE_RESOURCE_DIRECTORY_STRING
    Length     AS WORD
    NameString AS ASCIIZ * 1
END TYPE


TYPE IMAGE_RESOURCE_DIR_STRING_U
    Length     AS WORD
    NameString AS WSTRINGZ * 1
END TYPE


'
' Each resource data entry describes a leaf node in the resource directory
' tree.  It contains an offset, relative to the beginning of the resource
' directory of the data for the resource, a size field that gives the number
' of bytes of data at that offset, a CodePage that should be used when
' decoding code point values within the resource data.  Typically for new
' applications the code page would be the unicode code page.
'

TYPE IMAGE_RESOURCE_DATA_ENTRY
    OffsetToData AS DWORD
    dSize        AS DWORD
    CodePage     AS DWORD
    Reserved     AS DWORD
END TYPE

'
' Load Configuration Directory Entry
'

TYPE IMAGE_LOAD_CONFIG_DIRECTORY32
    nSize                         AS DWORD
    TimeDateStamp                 AS DWORD
    MajorVersion                  AS WORD
    MinorVersion                  AS WORD
    GlobalFlagsClear              AS DWORD
    GlobalFlagsSet                AS DWORD
    CriticalSectionDefaultTimeout AS DWORD
    DeCommitFreeBlockThreshold    AS DWORD
    DeCommitTotalFreeThreshold    AS DWORD
    LockPrefixTable               AS DWORD    ' VA
    MaximumAllocationSize         AS DWORD
    VirtualMemoryThreshold        AS DWORD
    ProcessHeapFlags              AS DWORD
    ProcessAffinityMask           AS DWORD
    CSDVersion                    AS WORD
    Reserved1                     AS WORD
    EditList                      AS DWORD    ' VA
    SecurityCookie                AS DWORD    ' VA
    SEHandlerTable                AS DWORD    ' VA
    SEHandlerCount                AS DWORD
END TYPE

TYPE IMAGE_LOAD_CONFIG_DIRECTORY64
    nSize                         AS DWORD
    TimeDateStamp                 AS DWORD
    MajorVersion                  AS WORD
    MinorVersion                  AS WORD
    GlobalFlagsClear              AS DWORD
    GlobalFlagsSet                AS DWORD
    CriticalSectionDefaultTimeout AS DWORD
    DeCommitFreeBlockThreshold    AS QUAD
    DeCommitTotalFreeThreshold    AS QUAD
    LockPrefixTable               AS QUAD     ' VA
    MaximumAllocationSize         AS QUAD
    VirtualMemoryThreshold        AS QUAD
    ProcessAffinityMask           AS QUAD
    ProcessHeapFlags              AS DWORD
    CSDVersion                    AS WORD
    Reserved1                     AS WORD
    EditList                      AS QUAD     ' VA
    SecurityCookie                AS QUAD     ' VA
    SEHandlerTable                AS QUAD     ' VA
    SEHandlerCount                AS QUAD
END TYPE

#IF %DEF(%WIN64)
MACRO IMAGE_LOAD_CONFIG_DIRECTORY=IMAGE_LOAD_CONFIG_DIRECTORY64
#ELSE
MACRO IMAGE_LOAD_CONFIG_DIRECTORY=IMAGE_LOAD_CONFIG_DIRECTORY32
#ENDIF

'
' WIN CE Exception table format
'

'
' Function table entry format.  Function table is pointed to by the
' IMAGE_DIRECTORY_ENTRY_EXCEPTION directory entry.
'

TYPE IMAGE_CE_RUNTIME_FUNCTION_ENTRY
    FuncStart     AS DWORD
    PrologLen     AS BIT * 8 IN DWORD
    FuncLen       AS BIT * 22
    ThirtyTwoBit  AS BIT * 1
    ExceptionFlag AS BIT * 1
END TYPE

TYPE IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY
    BeginAddress     AS QUAD
    EndAddress       AS QUAD
    ExceptionHandler AS QUAD
    HandlerData      AS QUAD
    PrologEndAddress AS QUAD
END TYPE

TYPE IMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY
    BeginAddress     AS DWORD
    EndAddress       AS DWORD
    ExceptionHandler AS DWORD
    HandlerData      AS DWORD
    PrologEndAddress AS DWORD
END TYPE

MACRO IMAGE_IA64_RUNTIME_FUNCTION_ENTRY=IMAGE_RUNTIME_FUNCTION_ENTRY

#IF %DEF(%AXP64)

MACRO IMAGE_AXP64_RUNTIME_FUNCTION_ENTRY=IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY
MACRO IMAGE_RUNTIME_FUNCTION_ENTRY=IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY

#ELSEIF %DEF(%ALPHA)

MACRO IMAGE_RUNTIME_FUNCTION_ENTRY=IMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY

#ELSE

TYPE IMAGE_RUNTIME_FUNCTION_ENTRY
    BeginAddress      AS DWORD
    EndAddress        AS DWORD
    UnwindInfoAddress AS DWORD
END TYPE

#ENDIF

'
' Debug Format
'

TYPE IMAGE_DEBUG_DIRECTORY
    Characteristics  AS DWORD
    TimeDateStamp    AS DWORD
    MajorVersion     AS WORD
    MinorVersion     AS WORD
    nType            AS DWORD
    SizeOfData       AS DWORD
    AddressOfRawData AS DWORD
    PointerToRawData AS DWORD
END TYPE

%IMAGE_DEBUG_TYPE_UNKNOWN        = 0
%IMAGE_DEBUG_TYPE_COFF           = 1
%IMAGE_DEBUG_TYPE_CODEVIEW       = 2
%IMAGE_DEBUG_TYPE_FPO            = 3
%IMAGE_DEBUG_TYPE_MISC           = 4
%IMAGE_DEBUG_TYPE_EXCEPTION      = 5
%IMAGE_DEBUG_TYPE_FIXUP          = 6
%IMAGE_DEBUG_TYPE_OMAP_TO_SRC    = 7
%IMAGE_DEBUG_TYPE_OMAP_FROM_SRC  = 8
%IMAGE_DEBUG_TYPE_BORLAND        = 9
%IMAGE_DEBUG_TYPE_RESERVED10     = 10
%IMAGE_DEBUG_TYPE_CLSID          = 11


TYPE IMAGE_COFF_SYMBOLS_HEADER
    NumberOfSymbols      AS DWORD
    LvaToFirstSymbol     AS DWORD
    NumberOfLinenumbers  AS DWORD
    LvaToFirstLinenumber AS DWORD
    RvaToFirstByteOfCode AS DWORD
    RvaToLastByteOfCode  AS DWORD
    RvaToFirstByteOfData AS DWORD
    RvaToLastByteOfData  AS DWORD
END TYPE

%FRAME_FPO     = 0
%FRAME_TRAP    = 1
%FRAME_TSS     = 2
%FRAME_NONFPO  = 3

TYPE FPO_DATA
    ulOffStart AS DWORD             ' offset 1st byte of function code
    cbProcSize AS DWORD             ' # bytes in function
    cdwLocals  AS DWORD             ' # bytes in locals/4
    cdwParams  AS WORD              ' # bytes in params/4
    cbProlog   AS BIT * 8 IN WORD  ' # bytes in prolog
    cbRegs     AS BIT * 3          ' # regs saved
    fHasSEH    AS BIT * 1          ' TRUE if SEH in func
    fUseBP     AS BIT * 1          ' TRUE if EBP has been allocated
    reserved   AS BIT * 1          ' reserved for future use
    cbFrame    AS BIT * 2          ' frame type
END TYPE

%SIZEOF_RFPO_DATA = 16


%IMAGE_DEBUG_MISC_EXENAME  = 1

TYPE IMAGE_DEBUG_MISC
    DataType    AS DWORD             ' type of misc data, see defines
    Length      AS DWORD             ' total length of record, rounded to four
                                     ' byte multiple.
    UNICODE     AS BYTE              ' BOOLEAN: TRUE if data is unicode string
    Reserved(2) AS BYTE
    bData(0)    AS BYTE              ' Actual data
END TYPE


'
' Function table extracted from MIPS/ALPHA/IA64 images.  Does not contain
' information needed only for runtime support.  Just those fields for
' each entry needed by a debugger.
'

TYPE IMAGE_FUNCTION_ENTRY
    StartingAddress AS DWORD
    EndingAddress   AS DWORD
    EndOfPrologue   AS DWORD
END TYPE

UNION IMAGE_FUNCTION_ENTRY64_union
    EndOfPrologue     AS QUAD
    UnwindInfoAddress AS QUAD
END UNION

TYPE IMAGE_FUNCTION_ENTRY64
    StartingAddress AS QUAD
    EndingAddress   AS QUAD
    IMAGE_FUNCTION_ENTRY64_union
END TYPE

'
' Debugging information can be stripped from an image file and placed
' in a separate .DBG file, whose file name part is the same as the
' image file name part (e.g. symbols for CMD.EXE could be stripped
' and placed in CMD.DBG).  This is indicated by the IMAGE_FILE_DEBUG_STRIPPED
' flag in the Characteristics field of the file header.  The beginning of
' the .DBG file contains the following structure which captures certain
' information from the image file.  This allows a debug to proceed even if
' the original image file is not accessable.  This header is followed by
' zero of more IMAGE_SECTION_HEADER structures, followed by zero or more
' IMAGE_DEBUG_DIRECTORY structures.  The latter structures and those in
' the image file contain file offsets relative to the beginning of the
' .DBG file.
'
' If symbols have been stripped from an image, the IMAGE_DEBUG_MISC structure
' is left in the image file, but not mapped.  This allows a debugger to
' compute the name of the .DBG file, from the name of the image in the
' IMAGE_DEBUG_MISC structure.
'

TYPE IMAGE_SEPARATE_DEBUG_HEADER
    Signature          AS WORD
    Flags              AS WORD
    Machine            AS WORD
    Characteristics    AS WORD
    TimeDateStamp      AS DWORD
    CheckSum           AS DWORD
    ImageBase          AS DWORD
    SizeOfImage        AS DWORD
    NumberOfSections   AS DWORD
    ExportedNamesSize  AS DWORD
    DebugDirectorySize AS DWORD
    SectionAlignment   AS DWORD
    Reserved(1)        AS DWORD
END TYPE

TYPE NON_PAGED_DEBUG_INFO
    Signature       AS WORD
    Flags           AS WORD
    nSize           AS DWORD
    Machine         AS WORD
    Characteristics AS WORD
    TimeDateStamp   AS DWORD
    CheckSum        AS DWORD
    SizeOfImage     AS DWORD
    ImageBase       AS QUAD
    'DebugDirectorySize
    'IMAGE_DEBUG_DIRECTORY
END TYPE

#IF NOT %DEF(%MAC)
%IMAGE_SEPARATE_DEBUG_SIGNATURE = &H4944
%NON_PAGED_DEBUG_SIGNATURE      = &H494E
#ELSE
%IMAGE_SEPARATE_DEBUG_SIGNATURE = &H4449  ' DI
%NON_PAGED_DEBUG_SIGNATURE      = &H4E49  ' NI
#ENDIF

%IMAGE_SEPARATE_DEBUG_FLAGS_MASK = &H8000??
%IMAGE_SEPARATE_DEBUG_MISMATCH   = &H8000??  ' when DBG was updated, the
                                           ' old checksum didn't match.

'
'  The .arch section is made up of headers, each describing an amask position/value
'  pointing to an array of IMAGE_ARCHITECTURE_ENTRY's.  Each "array" (both the header
'  and entry arrays) are terminiated by a quadword of -1
'
'  NOTE: There may be quadwords of 0 sprinkled around and must be skipped.
'

TYPE IMAGE_ARCHITECTURE_HEADER
    AmaskValue    AS BIT * 1 IN DWORD  ' 1 -> code section depends on mask bit
                                       ' 0 -> new instruction depends on mask bit
    junk1         AS BIT * 7           ' MBZ
    AmaskShift    AS BIT * 8           ' Amask bit in question for this fixup
    junk2         AS BIT * 16          ' MBZ
    FirstEntryRVA AS DWORD             ' RVA into .arch section to array of ARCHITECTURE_ENTRYs
END TYPE

TYPE IMAGE_ARCHITECTURE_ENTRY
    FixupInstRVA AS DWORD       ' RVA of instruction to fixup
    NewInst      AS DWORD       ' fixup instruction (see alphaops.h)
END TYPE


' The following structure defines the new import object.  Note the values of the first two fields,
' which must be set as stated in order to differentiate old and new import members.
' Following this structure, the linker emits two null-terminated strings used to recreate the
' import at the time of use.  The first string is the import's name, the second is the dll's name.

%IMPORT_OBJECT_HDR_SIG2 = &Hffff??

UNION IMPORT_OBJECT_HEADER_union
    Ordinal AS WORD                ' if grf & IMPORT_OBJECT_ORDINAL
    Hint    AS WORD
END UNION

TYPE IMPORT_OBJECT_HEADER
    Sig1          AS WORD          ' Must be IMAGE_FILE_MACHINE_UNKNOWN
    Sig2          AS WORD          ' Must be IMPORT_OBJECT_HDR_SIG2.
    Version       AS WORD
    Machine       AS WORD
    TimeDateStamp AS DWORD         ' Time/date stamp
    SizeOfData    AS DWORD         ' particularly useful for incremental links
    IMPORT_OBJECT_HEADER_union

    nType         AS BIT * 2 IN WORD   ' IMPORT_TYPE
    NameType      AS BIT * 3           ' IMPORT_NAME_TYPE
    Reserved      AS BIT * 11          ' Reserved. Must be zero.
END TYPE

MACRO IMPORT_OBJECT_TYPE_enum=LONG
ENUM IMPORT_OBJECT_TYPE SINGULAR
    IMPORT_OBJECT_CODE
    IMPORT_OBJECT_DATA
    IMPORT_OBJECT_CONST
END ENUM

MACRO IMPORT_OBJECT_NAME_TYPE_enum=LONG
ENUM IMPORT_OBJECT_NAME_TYPE SINGULAR
    IMPORT_OBJECT_ORDINAL           ' Import by ordinal
    IMPORT_OBJECT_NAME              ' Import name = public symbol name.
    IMPORT_OBJECT_NAME_NO_PREFIX    ' Import name = public symbol name skipping leading ?, @, or optionally _.
    IMPORT_OBJECT_NAME_UNDECORATE   ' Import name = public symbol name skipping leading ?, @, or optionally _
                                    ' and truncating at first @
END ENUM


#IF NOT %DEF(%IMAGE_COR20_HEADER_DEFINED)

%IMAGE_COR20_HEADER_DEFINED = 1

' COM+ Header entry point flags.
MACRO ReplacesCorHdrNumericDefines_enum=LONG
ENUM ReplacesCorHdrNumericDefines SINGULAR BITS
    COMIMAGE_FLAGS_ILONLY             = &H00000001
    COMIMAGE_FLAGS_32BITREQUIRED
    COMIMAGE_FLAGS_IL_LIBRARY
    COMIMAGE_FLAGS_STRONGNAMESIGNED
    COMIMAGE_FLAGS_NATIVE_ENTRYPOINT
    COMIMAGE_FLAGS_TRACKDEBUGDATA     = &H00010000
END ENUM

' Version flags for image.
%COR_VERSION_MAJOR_V2                = 2
%COR_VERSION_MAJOR                   = %COR_VERSION_MAJOR_V2
%COR_VERSION_MINOR                   = 0
%COR_DELETED_NAME_LENGTH             = 8
%COR_VTABLEGAP_NAME_LENGTH           = 8

' Maximum size of a NativeType descriptor.
%NATIVE_TYPE_MAX_CB                  = 1
%COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE= &HFF?

' #defines for the MIH FLAGS
%IMAGE_COR_MIH_METHODRVA             = &H01
%IMAGE_COR_MIH_EHRVA                 = &H02
%IMAGE_COR_MIH_BASICBLOCK            = &H08

' V-table constants
%COR_VTABLE_32BIT                    = &H01          ' V-table slots are 32-bits in size.
%COR_VTABLE_64BIT                    = &H02          ' V-table slots are 64-bits in size.
%COR_VTABLE_FROM_UNMANAGED           = &H04          ' If set, transition from unmanaged.
%COR_VTABLE_FROM_UNMANAGED_RETAIN_APPDOMAIN  = &H08  ' If set, transition from unmanaged with keeping the current appdomain.
%COR_VTABLE_CALL_MOST_DERIVED        = &H10          ' Call most derived method described by

' EATJ constants
%IMAGE_COR_EATJ_THUNK_SIZE           = 32            ' Size of a jump thunk reserved range.

' Max name lengths
    '@todo: Change to unlimited name lengths.
%MAX_CLASS_NAME                      = 1024
%MAX_PACKAGE_NAME                    = 1024


' CLR 2.0 header structure.
UNION IMAGE_COR20_HEADER_union
    EntryPointToken AS DWORD
    EntryPointRVA   AS DWORD
END UNION

TYPE IMAGE_COR20_HEADER
    ' Header versioning
    cb                  AS DWORD
    MajorRuntimeVersion AS WORD
    MinorRuntimeVersion AS WORD

    ' Symbol table and startup information
    MetaData            AS IMAGE_DATA_DIRECTORY
    Flags               AS DWORD

    ' If COMIMAGE_FLAGS_NATIVE_ENTRYPOINT is not set, EntryPointToken represents a managed entrypoint.
    ' If COMIMAGE_FLAGS_NATIVE_ENTRYPOINT is set, EntryPointRVA represents an RVA to a native entrypoint.
    IMAGE_COR20_HEADER_union

    ' Binding information
    Resources           AS IMAGE_DATA_DIRECTORY
    StrongNameSignature AS IMAGE_DATA_DIRECTORY

    ' Regular fixup and binding information
    CodeManagerTable    AS IMAGE_DATA_DIRECTORY
    VTableFixups        AS IMAGE_DATA_DIRECTORY
    ExportAddressTableJumps AS IMAGE_DATA_DIRECTORY

    ' Precompiled image info (internal use only - set to zero)
    ManagedNativeHeader AS IMAGE_DATA_DIRECTORY
END TYPE

#ENDIF ' %IMAGE_COR20_HEADER_DEFINED

'
' End Image Format
'

'
' for move macros
'
'#IF %DEF(%MAC)
'#IF NOT %DEF(%INC_STRING)
'#include "String.inc"
'#endif ' %INC_STRING
'#else
'#include "String.inc"
'#endif ' %MAC


#IF NOT %DEF(%SLIST_HEADER)

%SLIST_HEADER = 1

#IF %DEF(%WIN64)

'
' The type SINGLE_LIST_ENTRY is not suitable for use with SLISTs.  For
' WIN64, an entry on an SLIST is required to be 16-byte aligned, while a
' SINGLE_LIST_ENTRY structure has only 8 byte alignment.
'
' Therefore, all SLIST code should use the SLIST_ENTRY type instead of the
' SINGLE_LIST_ENTRY type.
'

TYPE SLIST_ENTRY
    tNext AS PSLIST_ENTRY
END TYPE

#ELSE

MACRO SLIST_ENTRY=SINGLE_LIST_ENTRY

#ENDIF ' %WIN64

#IF %DEF(%WIN64)

TYPE SLIST_HEADER_type3
    Depth      AS BIT * 16 IN QUAD
    Sequence   AS BIT * 48
    HeaderType AS BIT * 1 IN QUAD ' 0: 8-byte; 1: 16-byte
    Init       AS BIT * 1         ' 0: uninitialized; 1: initialized
    Reserved   AS BIT * 2
    NextEntry  AS BIT * 60        ' last 4 bits are always 0's
END TYPE

TYPE SLIST_HEADER_type2
    Depth      AS BIT * 16 IN QUAD
    Sequence   AS BIT * 9
    NextEntry  AS BIT * 39
    HeaderType AS BIT * 1 IN QUAD ' 0: 8-byte; 1: 16-byte
    Init       AS BIT * 1         ' 0: uninitialized; 1: initialized
    Reserved   AS BIT * 59
    Region     AS BIT * 3
END TYPE

TYPE SLIST_HEADER_type1
    Alignment AS QUAD
    Region    AS QUAD
END TYPE

UNION SLIST_HEADER
    SLIST_HEADER_type1  ' original struct
    Header8  AS SLIST_HEADER_type2  ' 8-byte header
    Header16 AS SLIST_HEADER_type3  ' 16-byte header
END UNION

#ELSE

TYPE SLIST_HEADER_type
    tNext    AS SLIST_ENTRY
    Depth    AS WORD
    Sequence AS WORD
END TYPE

UNION SLIST_HEADER
    Alignment AS QUAD
    SLIST_HEADER_type
END UNION

#ENDIF ' %WIN64

#ENDIF ' %SLIST_HEADER


'NTSYSAPI
'VOID
'NTAPI
'RtlInitializeSListHead (
'    IN PSLIST_HEADER ListHead
'    );
'
'NTSYSAPI
'PSLIST_ENTRY
'NTAPI
'RtlFirstEntrySList (
'    IN const SLIST_HEADER *ListHead
'    );
'
'NTSYSAPI
'PSLIST_ENTRY
'NTAPI
'RtlInterlockedPopEntrySList (
'    IN PSLIST_HEADER ListHead
'    );
'
'NTSYSAPI
'PSLIST_ENTRY
'NTAPI
'RtlInterlockedPushEntrySList (
'    IN PSLIST_HEADER ListHead,
'    IN PSLIST_ENTRY ListEntry
'    );
'
'NTSYSAPI
'PSLIST_ENTRY
'NTAPI
'RtlInterlockedFlushSList (
'    IN PSLIST_HEADER ListHead
'    );
'
'NTSYSAPI
'WORD
'NTAPI
'RtlQueryDepthSList (
'    IN PSLIST_HEADER ListHead
'    );

' begin_ntddk

#IF NOT %DEF(%RTL_RUN_ONCE_DEF)
%RTL_RUN_ONCE_DEF = 1

'
' Run once
'

%RTL_RUN_ONCE_INIT = 0   ' Static initializer

'
' Run once flags
'

%RTL_RUN_ONCE_CHECK_ONLY   = &H00000001
%RTL_RUN_ONCE_ASYNC        = &H00000002
%RTL_RUN_ONCE_INIT_FAILED  = &H00000004

'
' The context stored in the run once structure must leave the following number
' of low order bits unused.
'

%RTL_RUN_ONCE_CTX_RESERVED_BITS = 2

UNION RTL_RUN_ONCE
    pPtr AS DWORD  ' PVOID
END UNION

'typedef
'DWORD ' LOGICAL
'(NTAPI *PRTL_RUN_ONCE_INIT_FN) (
'    __inout PRTL_RUN_ONCE RunOnce,
'    __inout_opt PVOID Parameter,
'    __deref_opt_out_opt PVOID *Context
'    );

#ENDIF ' %RTL_RUN_ONCE_DEF

#IF (%NTDDI_VERSION >= %NTDDI_LONGHORN)

'NTSYSAPI
'VOID
'NTAPI
'RtlRunOnceInitialize (
'    PRTL_RUN_ONCE RunOnce
'    );
'
'NTSYSAPI
'DWORD
'NTAPI
'RtlRunOnceExecuteOnce (
'    __inout PRTL_RUN_ONCE RunOnce,
'    __callback PRTL_RUN_ONCE_INIT_FN InitFn,
'    __inout_opt PVOID Parameter,
'    __deref_opt_out_opt PVOID *Context
'    );
'
'NTSYSAPI
'DWORD
'NTAPI
'RtlRunOnceBeginInitialize (
'    __inout PRTL_RUN_ONCE RunOnce,
'    DWORD Flags,
'    __deref_opt_out_opt PVOID *Context
'    );
'
'NTSYSAPI
'DWORD
'NTAPI
'RtlRunOnceComplete (
'    __inout PRTL_RUN_ONCE RunOnce,
'    DWORD Flags,
'    __in_opt PVOID Context
'    );

#ENDIF ' %NTDDI_VERSION >= %NTDDI_LONGHORN

%HEAP_NO_SERIALIZE             = &H00000001
%HEAP_GROWABLE                 = &H00000002
%HEAP_GENERATE_EXCEPTIONS      = &H00000004
%HEAP_ZERO_MEMORY              = &H00000008
%HEAP_REALLOC_IN_PLACE_ONLY    = &H00000010
%HEAP_TAIL_CHECKING_ENABLED    = &H00000020
%HEAP_FREE_CHECKING_ENABLED    = &H00000040
%HEAP_DISABLE_COALESCE_ON_FREE = &H00000080
%HEAP_CREATE_ALIGN_16          = &H00010000
%HEAP_CREATE_ENABLE_TRACING    = &H00020000
%HEAP_CREATE_ENABLE_EXECUTE    = &H00040000
%HEAP_MAXIMUM_TAG              = &H0FFF
%HEAP_PSEUDO_TAG_FLAG          = &H8000??
%HEAP_TAG_SHIFT                = 18

#IF NOT %DEF(%MIDL_PASS)
'FORCEINLINE
'DWORD
'HEAP_MAKE_TAG_FLAGS (
'    IN DWORD TagBase,
'    IN DWORD Tag
'    )
'
'{
'    __assume_bound(TagBase);
'    return ((DWORD)((TagBase) + ((Tag) << HEAP_TAG_SHIFT)));
'}
#ENDIF

#IF (%NTDDI_VERSION > %NTDDI_WINXP)
DECLARE FUNCTION RtlCaptureStackBackTrace LIB "Kernel32.dll" _
    ALIAS "RtlCaptureStackBackTrace" ( _
    BYVAL FramesToSkip           AS DWORD, _
    BYVAL FramesToCapture        AS DWORD, _
    BYVAL BackTrace              AS DWORD, _   ' PVOID *
    OPTIONAL BYVAL BackTraceHash AS DWORD _    ' DWORD PTR
    ) AS WORD
#ENDIF

#IF (%NTDDI_VERSION > %NTDDI_WIN2K)
'NTSYSAPI
'VOID
'NTAPI
'RtlCaptureContext (
'    PCONTEXT ContextRecord
'    );
#ENDIF


%IS_TEXT_UNICODE_ASCII16             = &H0001
%IS_TEXT_UNICODE_REVERSE_ASCII16     = &H0010

%IS_TEXT_UNICODE_STATISTICS          = &H0002
%IS_TEXT_UNICODE_REVERSE_STATISTICS  = &H0020

%IS_TEXT_UNICODE_CONTROLS            = &H0004
%IS_TEXT_UNICODE_REVERSE_CONTROLS    = &H0040

%IS_TEXT_UNICODE_SIGNATURE           = &H0008
%IS_TEXT_UNICODE_REVERSE_SIGNATURE   = &H0080

%IS_TEXT_UNICODE_ILLEGAL_CHARS       = &H0100
%IS_TEXT_UNICODE_ODD_LENGTH          = &H0200
%IS_TEXT_UNICODE_DBCS_LEADBYTE       = &H0400
%IS_TEXT_UNICODE_NULL_BYTES          = &H1000

%IS_TEXT_UNICODE_UNICODE_MASK        = &H000F
%IS_TEXT_UNICODE_REVERSE_MASK        = &H00F0
%IS_TEXT_UNICODE_NOT_UNICODE_MASK    = &H0F00
%IS_TEXT_UNICODE_NOT_ASCII_MASK      = &HF000??

%COMPRESSION_FORMAT_NONE         = &H0000
%COMPRESSION_FORMAT_DEFAULT      = &H0001
%COMPRESSION_FORMAT_LZNT1        = &H0002
%COMPRESSION_ENGINE_STANDARD     = &H0000
%COMPRESSION_ENGINE_MAXIMUM      = &H0100
%COMPRESSION_ENGINE_HIBER        = &H0200

#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)
'NTSYSAPI
'DWORD
'NTAPI
'RtlCompareMemory (
'    const VOID *Source1,
'    const VOID *Source2,
'    DWORD Length
'    );

#ENDIF

'MACRO RtlEqualMemory(Destination,Source,Length) (!memcmp((Destination),(Source),(Length)))

SUB RtlMoveMemory (BYVAL pDest AS DWORD, BYVAL pSrc AS DWORD, BYVAL ncBytes AS LONG)
    MEMORY COPY pSrc, pDest, ncBytes
END SUB

SUB RtlCopyMemory (BYVAL pDest AS DWORD, BYVAL pSrc AS DWORD, BYVAL ncBytes AS LONG)
    MEMORY COPY pSrc, pDest, ncBytes
END SUB

SUB RtlFillMemory (BYVAL pDest AS DWORD, BYVAL ncBytes AS DWORD, BYVAL nValue AS BYTE)
    MEMORY FILL pDest, ncBytes, BYTE nValue
END SUB

SUB RtlZeroMemory (BYVAL pDest AS DWORD, BYVAL ncBytes AS LONG)
    MEMORY FILL pDest, ncBytes, BYTE 0
END SUB

SUB RtlSecureZeroMemory (BYVAL pDest AS DWORD, BYVAL ncBytes AS LONG)
    MEMORY FILL pDest, ncBytes, BYTE 0
END SUB

%SEF_DACL_AUTO_INHERIT             = &H01
%SEF_SACL_AUTO_INHERIT             = &H02
%SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT = &H04
%SEF_AVOID_PRIVILEGE_CHECK         = &H08
%SEF_AVOID_OWNER_CHECK             = &H10
%SEF_DEFAULT_OWNER_FROM_PARENT     = &H20
%SEF_DEFAULT_GROUP_FROM_PARENT     = &H40
%SEF_MACL_NO_WRITE_UP              = &H100
%SEF_MACL_NO_READ_UP               = &H200
%SEF_MACL_NO_EXECUTE_UP            = &H400
%SEF_AVOID_OWNER_RESTRICTION       = &H1000

%SEF_MACL_VALID_FLAGS              = (%SEF_MACL_NO_WRITE_UP   OR _
                                      %SEF_MACL_NO_READ_UP    OR _
                                      %SEF_MACL_NO_EXECUTE_UP)


TYPE MESSAGE_RESOURCE_ENTRY
    Length   AS WORD
    Flags    AS WORD
    bText(0) AS BYTE
END TYPE

%MESSAGE_RESOURCE_UNICODE = &H0001

TYPE MESSAGE_RESOURCE_BLOCK
    LowId           AS DWORD
    HighId          AS DWORD
    OffsetToEntries AS DWORD
END TYPE

TYPE MESSAGE_RESOURCE_DATA
    NumberOfBlocks AS DWORD
    Blocks(0)      AS MESSAGE_RESOURCE_BLOCK
END TYPE


'NTSYSAPI
'PVOID
'NTAPI
'RtlPcToFileHeader(
'    PVOID PcValue,
'    PVOID *BaseOfImage
'    );

TYPE OSVERSIONINFOA
    dwOSVersionInfoSize AS DWORD
    dwMajorVersion      AS DWORD
    dwMinorVersion      AS DWORD
    dwBuildNumber       AS DWORD
    dwPlatformId        AS DWORD
    szCSDVersion        AS ASCIIZ * 128      ' Maintenance string for PSS usage
END TYPE

TYPE OSVERSIONINFOW
    dwOSVersionInfoSize AS DWORD
    dwMajorVersion      AS DWORD
    dwMinorVersion      AS DWORD
    dwBuildNumber       AS DWORD
    dwPlatformId        AS DWORD
    szCSDVersion        AS WSTRINGZ * 128      ' Maintenance string for PSS usage
END TYPE
#IF %DEF(%UNICODE)
TYPE OSVERSIONINFO
    OSVERSIONINFOW
END TYPE
#ELSE
TYPE OSVERSIONINFO
    OSVERSIONINFOA
END TYPE
#ENDIF ' UNICODE

TYPE OSVERSIONINFOEXA
    dwOSVersionInfoSize AS DWORD
    dwMajorVersion      AS DWORD
    dwMinorVersion      AS DWORD
    dwBuildNumber       AS DWORD
    dwPlatformId        AS DWORD
    szCSDVersion        AS ASCIIZ * 128      ' Maintenance string for PSS usage
    wServicePackMajor   AS WORD
    wServicePackMinor   AS WORD
    wSuiteMask          AS WORD
    wProductType        AS BYTE
    wReserved           AS BYTE
END TYPE
TYPE OSVERSIONINFOEXW
    dwOSVersionInfoSize AS DWORD
    dwMajorVersion      AS DWORD
    dwMinorVersion      AS DWORD
    dwBuildNumber       AS DWORD
    dwPlatformId        AS DWORD
    szCSDVersion        AS WSTRINGZ * 128   ' Maintenance string for PSS usage
    wServicePackMajor   AS WORD
    wServicePackMinor   AS WORD
    wSuiteMask          AS WORD
    wProductType        AS BYTE
    wReserved           AS BYTE
END TYPE
#IF %DEF(%UNICODE)
TYPE OSVERSIONINFOEX
    OSVERSIONINFOEXW
END TYPE
#ELSE
TYPE OSVERSIONINFOEX
    OSVERSIONINFOEXA
END TYPE
#ENDIF ' UNICODE

'
' RtlVerifyVersionInfo() conditions
'

%VER_EQUAL                     = 1
%VER_GREATER                   = 2
%VER_GREATER_EQUAL             = 3
%VER_LESS                      = 4
%VER_LESS_EQUAL                = 5
%VER_AND                       = 6
%VER_OR                        = 7

%VER_CONDITION_MASK              = 7
%VER_NUM_BITS_PER_CONDITION_MASK = 3

'
' RtlVerifyVersionInfo() type mask bits
'

%VER_MINORVERSION              = &H0000001
%VER_MAJORVERSION              = &H0000002
%VER_BUILDNUMBER               = &H0000004
%VER_PLATFORMID                = &H0000008
%VER_SERVICEPACKMINOR          = &H0000010
%VER_SERVICEPACKMAJOR          = &H0000020
%VER_SUITENAME                 = &H0000040
%VER_PRODUCT_TYPE              = &H0000080

'
' RtlVerifyVersionInfo() os product type values
'

%VER_NT_WORKSTATION            = &H0000001
%VER_NT_DOMAIN_CONTROLLER      = &H0000002
%VER_NT_SERVER                 = &H0000003

'
' dwPlatformId defines:
'

%VER_PLATFORM_WIN32s           = 0
%VER_PLATFORM_WIN32_WINDOWS    = 1
%VER_PLATFORM_WIN32_NT         = 2


'
' VerifyVersionInfo() macro to set the condition mask
'

MACRO VER_SET_CONDITION(m,t,c)
    m=VerSetConditionMask(m,t,c)
END MACRO

#IF (%NTDDI_VERSION >= %NTDDI_WIN2K)
DECLARE FUNCTION VerSetConditionMask LIB "KERNEL32.DLL" ALIAS "VerSetConditionMask" _
    (BYVAL ConditionMask AS QUAD, BYVAL TypeMask AS DWORD, BYVAL Condition AS BYTE) AS QUAD
#ENDIF

'

'#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
'' [not documented by Microsoft]
'NTSYSAPI
'BOOLEAN
'NTAPI
'RtlGetProductInfo(
'     DWORD  OSMajorVersion,
'     DWORD  OSMinorVersion,
'     DWORD  SpMajorVersion,
'     DWORD  SpMinorVersion,
'    PDWORD ReturnedProductType
'    );
'
'#ENDIF

%RTL_UMS_VERSION = &H0100

MACRO RTL_UMS_THREAD_INFO_CLASS_enum=LONG
ENUM RTL_UMS_THREAD_INFO_CLASS SINGULAR
    UmsThreadInvalidInfoClass
    UmsThreadUserContext
    UmsThreadPriority
    UmsThreadAffinity
    UmsThreadTeb
    UmsThreadIsSuspended
    UmsThreadIsTerminated
    UmsThreadMaxInfoClas
END ENUM

MACRO RTL_UMS_SCHEDULER_REASON_enum=LONG
ENUM RTL_UMS_SCHEDULER_REASON SINGULAR
    UmsSchedulerStartup
    UmsSchedulerThreadBlocked
    UmsSchedulerThreadYield
END ENUM

TYPE RTL_CRITICAL_SECTION_DEBUG
    nType                     AS WORD
    CreatorBackTraceIndex     AS WORD
    CriticalSection           AS DWORD 'RTL_CRITICAL_SECTION PTR
    ProcessLocksList          AS LIST_ENTRY
    EntryCount                AS DWORD
    ContentionCount           AS DWORD
    Flags                     AS DWORD
    CreatorBackTraceIndexHigh AS WORD
    SpareWORD                 AS WORD
END TYPE

%RTL_CRITSECT_TYPE = 0
%RTL_RESOURCE_TYPE = 1

'
' These flags define the upper byte of the critical section SpinCount field
'
%RTL_CRITICAL_SECTION_FLAG_NO_DEBUG_INFO     = &H01000000
%RTL_CRITICAL_SECTION_FLAG_DYNAMIC_SPIN      = &H02000000
%RTL_CRITICAL_SECTION_FLAG_STATIC_INIT       = &H04000000
%RTL_CRITICAL_SECTION_ALL_FLAG_BITS          = &HFF000000
%RTL_CRITICAL_SECTION_FLAG_RESERVED = _
    (%RTL_CRITICAL_SECTION_ALL_FLAG_BITS _
    AND (NOT (%RTL_CRITICAL_SECTION_FLAG_NO_DEBUG_INFO _
           OR %RTL_CRITICAL_SECTION_FLAG_DYNAMIC_SPIN _
           OR %RTL_CRITICAL_SECTION_FLAG_STATIC_INIT)))

'
' These flags define possible values stored in the Flags field of a critsec debuginfo.
'
%RTL_CRITICAL_SECTION_DEBUG_FLAG_STATIC_INIT = &H00000001

TYPE RTL_CRITICAL_SECTION
    DebugInfo      AS RTL_CRITICAL_SECTION_DEBUG PTR

    '
    '  The following three fields control entering and exiting the critical
    '  section for the resource
    '

    LockCount      AS LONG
    RecursionCount AS LONG
    OwningThread   AS DWORD         ' from the thread's ClientId->UniqueThread
    LockSemaphore  AS DWORD
    SpinCount      AS DWORD  'ULONG_PTR    ' force size on 64-bit systems when packed
END TYPE

TYPE RTL_SRWLOCK
    pPtr AS DWORD ' PVOID
END TYPE

%RTL_SRWLOCK_INIT = 0

TYPE RTL_CONDITION_VARIABLE
    pPtr AS DWORD ' PVOID
END TYPE

%RTL_CONDITION_VARIABLE_INIT            = 0
%RTL_CONDITION_VARIABLE_LOCKMODE_SHARED = &H1

DECLARE FUNCTION PVECTORED_EXCEPTION_HANDLER _
    (ExceptionInfo AS EXCEPTION_POINTERS) AS LONG

MACRO HEAP_INFORMATION_CLASS_enum=LONG
ENUM HEAP_INFORMATION_CLASS SINGULAR
    HeapCompatibilityInformation
    HeapEnableTerminationOnCorruption
END ENUM


%WT_EXECUTEDEFAULT              = &H00000000
%WT_EXECUTEINIOTHREAD           = &H00000001
%WT_EXECUTEINUITHREAD           = &H00000002
%WT_EXECUTEINWAITTHREAD         = &H00000004
%WT_EXECUTEONLYONCE             = &H00000008
%WT_EXECUTEINTIMERTHREAD        = &H00000020
%WT_EXECUTELONGFUNCTION         = &H00000010
%WT_EXECUTEINPERSISTENTIOTHREAD = &H00000040
%WT_EXECUTEINPERSISTENTTHREAD   = &H00000080
%WT_TRANSFER_IMPERSONATION      = &H00000100

MACRO WT_SET_MAX_THREADPOOL_THREADS(Flags, Limit)
    Flags OR= (Limit) * 65536  ' <<16
END MACRO

DECLARE SUB WAITORTIMERCALLBACKFUNC (BYVAL pv AS DWORD, BYVAL bl AS BYTE)
DECLARE SUB WORKERCALLBACKFUNC (BYVAL pv AS DWORD)
DECLARE SUB APC_CALLBACK_FUNCTION (BYVAL dwd AS DWORD, BYVAL pv1 AS DWORD, _
    BYVAL pv2 AS DWORD)

DECLARE SUB PFLS_CALLBACK_FUNCTION (BYVAL lpFlsData AS DWORD)

DECLARE FUNCTION PSECURE_MEMORY_CACHE_CALLBACK (BYVAL dAddr AS DWORD, _
    BYVAL dRange AS DWORD) AS BYTE ' BOOLEAN

%WT_EXECUTEINLONGTHREAD = &H00000010
%WT_EXECUTEDELETEWAIT   = &H00000008

MACRO ACTIVATION_CONTEXT_INFO_CLASS_enum=LONG
ENUM ACTIVATION_CONTEXT_INFO_CLASS SINGULAR
    ActivationContextBasicInformation                       = 1
    ActivationContextDetailedInformation
    AssemblyDetailedInformationInActivationContext
    FileInformationInAssemblyOfAssemblyInActivationContext
    RunlevelInformationInActivationContext
    MaxActivationContextInfoClass
    '
    ' compatibility with old names
    '
    AssemblyDetailedInformationInActivationContxt           = 3
    FileInformationInAssemblyOfAssemblyInActivationContxt
END ENUM

MACRO ACTIVATIONCONTEXTINFOCLASS_enum=ACTIVATION_CONTEXT_INFO_CLASS_enum


TYPE ACTIVATION_CONTEXT_QUERY_INDEX
    ulAssemblyIndex       AS DWORD
    ulFileIndexInAssembly AS DWORD
END TYPE


%ACTIVATION_CONTEXT_PATH_TYPE_NONE = (1)
%ACTIVATION_CONTEXT_PATH_TYPE_WIN32_FILE = (2)
%ACTIVATION_CONTEXT_PATH_TYPE_URL = (3)
%ACTIVATION_CONTEXT_PATH_TYPE_ASSEMBLYREF = (4)

TYPE ASSEMBLY_FILE_DETAILED_INFORMATION
    ulFlags          AS DWORD
    ulFilenameLength AS DWORD
    ulPathLength     AS DWORD
    lpFileName       AS WSTRINGZ PTR
    lpFilePath       AS WSTRINGZ PTR
END TYPE

'
' compatibility with old names
' The new names use "file" consistently.
'
MACRO ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION=ASSEMBLY_FILE_DETAILED_INFORMATION

TYPE ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION
    ulFlags                         AS DWORD
    ulEncodedAssemblyIdentityLength AS DWORD         ' in bytes
    ulManifestPathType              AS DWORD         ' ACTIVATION_CONTEXT_PATH_TYPE_*
    ulManifestPathLength            AS DWORD         ' in bytes
    liManifestLastWriteTime         AS LARGE_INTEGER ' FILETIME
    ulPolicyPathType                AS DWORD         ' ACTIVATION_CONTEXT_PATH_TYPE_*
    ulPolicyPathLength              AS DWORD         ' in bytes
    liPolicyLastWriteTime           AS LARGE_INTEGER ' FILETIME
    ulMetadataSatelliteRosterIndex  AS DWORD

    ulManifestVersionMajor          AS DWORD         ' 1
    ulManifestVersionMinor          AS DWORD         ' 0
    ulPolicyVersionMajor            AS DWORD         ' 0
    ulPolicyVersionMinor            AS DWORD         ' 0
    ulAssemblyDirectoryNameLength   AS DWORD         ' in bytes

    lpAssemblyEncodedAssemblyIdentity AS WSTRINGZ PTR
    lpAssemblyManifestPath          AS WSTRINGZ PTR
    lpAssemblyPolicyPath            AS WSTRINGZ PTR
    lpAssemblyDirectoryName         AS WSTRINGZ PTR

    ulFileCount                     AS DWORD
END TYPE ' ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION

MACRO ACTCTX_REQUESTED_RUN_LEVEL_enum=LONG
ENUM ACTCTX_REQUESTED_RUN_LEVEL SINGULAR
    ACTCTX_RUN_LEVEL_UNSPECIFIED
    ACTCTX_RUN_LEVEL_AS_INVOKER
    ACTCTX_RUN_LEVEL_HIGHEST_AVAILABLE
    ACTCTX_RUN_LEVEL_REQUIRE_ADMIN
    ACTCTX_RUN_LEVEL_NUMBERS
END ENUM

TYPE ACTIVATION_CONTEXT_RUN_LEVEL_INFORMATION
    ulFlags  AS DWORD
    RunLevel AS ACTCTX_REQUESTED_RUN_LEVEL_enum
    UiAccess AS DWORD
END TYPE

MACRO ACTCTX_COMPATIBILITY_ELEMENT_TYPE_enum=LONG
ENUM ACTCTX_COMPATIBILITY_ELEMENT_TYPE SINGULAR
    ACTCTX_COMPATIBILITY_ELEMENT_TYPE_UNKNOWN
    ACTCTX_COMPATIBILITY_ELEMENT_TYPE_OS
    ACTCTX_COMPATIBILITY_ELEMENT_TYPE_MITIGATION
END ENUM

TYPE COMPATIBILITY_CONTEXT_ELEMENT
    ID   AS GUID
    TYPE AS ACTCTX_COMPATIBILITY_ELEMENT_TYPE_enum
END TYPE

TYPE ACTIVATION_CONTEXT_COMPATIBILITY_INFORMATION
    ElementCount AS DWORD
    Elements     AS COMPATIBILITY_CONTEXT_ELEMENT PTR
END TYPE

%MAX_SUPPORTED_OS_NUM  = 4
%INVALID_OS_COUNT      = &Hffff??

TYPE SUPPORTED_OS_INFO
    OsCount         AS WORD
    MitigationExist AS WORD
    OsList(%MAX_SUPPORTED_OS_NUM-1) AS WORD
END TYPE

TYPE ACTIVATION_CONTEXT_DETAILED_INFORMATION
    dwFlags                      AS DWORD
    ulFormatVersion              AS DWORD
    ulAssemblyCount              AS DWORD
    ulRootManifestPathType       AS DWORD
    ulRootManifestPathChars      AS DWORD
    ulRootConfigurationPathType  AS DWORD
    ulRootConfigurationPathChars AS DWORD
    ulAppDirPathType             AS DWORD
    ulAppDirPathChars            AS DWORD
    lpRootManifestPath           AS WSTRINGZ PTR
    lpRootConfigurationPath      AS WSTRINGZ PTR
    lpAppDirPath                 AS WSTRINGZ PTR
END TYPE

TYPE HARDWARE_COUNTER_DATA
    TYPE     AS HARDWARE_COUNTER_TYPE_enum
    Reserved AS DWORD
    Value    AS QUAD  ' DWORD64
END TYPE

%PERFORMANCE_DATA_VERSION = 1

TYPE PERFORMANCE_DATA
    SIZE               AS WORD
    Version            AS BYTE
    HwCountersCount    AS BYTE
    ContextSwitchCount AS DWORD
    WaitReasonBitMap   AS QUAD  ' DWORD64
    CycleTime          AS QUAD  ' DWORD64
    RetryCount         AS DWORD
    Reserved           AS DWORD
    HwCounters(%MAX_HW_COUNTERS-1) AS HARDWARE_COUNTER_DATA
END TYPE

%READ_THREAD_PROFILING_FLAG_DISPATCHING       = &H00000001
%READ_THREAD_PROFILING_FLAG_HARDWARE_COUNTERS = &H00000002
%DLL_PROCESS_ATTACH  = 1
%DLL_THREAD_ATTACH   = 2
%DLL_THREAD_DETACH   = 3
%DLL_PROCESS_DETACH  = 0

'
' Defines for the READ flags for Eventlogging
'
%EVENTLOG_SEQUENTIAL_READ      =  &H0001
%EVENTLOG_SEEK_READ            =  &H0002
%EVENTLOG_FORWARDS_READ        =  &H0004
%EVENTLOG_BACKWARDS_READ       =  &H0008

'
' The types of events that can be logged.
'
%EVENTLOG_SUCCESS              =  &H0000
%EVENTLOG_ERROR_TYPE           =  &H0001
%EVENTLOG_WARNING_TYPE         =  &H0002
%EVENTLOG_INFORMATION_TYPE     =  &H0004
%EVENTLOG_AUDIT_SUCCESS        =  &H0008
%EVENTLOG_AUDIT_FAILURE        =  &H0010

'
' Defines for the WRITE flags used by Auditing for paired events
' These are not implemented in Product 1
'

%EVENTLOG_START_PAIRED_EVENT    = &H0001
%EVENTLOG_END_PAIRED_EVENT      = &H0002
%EVENTLOG_END_ALL_PAIRED_EVENTS = &H0004
%EVENTLOG_PAIRED_EVENT_ACTIVE   = &H0008
%EVENTLOG_PAIRED_EVENT_INACTIVE = &H0010

'
' Structure that defines the header of the Eventlog record. This is the
' fixed-sized portion before all the variable-length strings, binary
' data and pad bytes.
'
' TimeGenerated is the time it was generated at the client.
' TimeWritten is the time it was put into the log at the server end.
'

TYPE EVENTLOGRECORD
    Length AS DWORD          ' Length of full record
    Reserved AS DWORD        ' Used by the service
    RecordNumber AS DWORD    ' Absolute record number
    TimeGenerated AS DWORD   ' Seconds since 1-1-1970
    TimeWritten AS DWORD     ' Seconds since 1-1-1970
    EventID AS DWORD
    EventType AS WORD
    NumStrings AS WORD
    EventCategory AS WORD
    ReservedFlags AS WORD    ' For use with paired events (auditing)
    ClosingRecordNumber AS DWORD   ' For use with paired events (auditing)
    StringOffset AS DWORD    ' Offset from beginning of record
    UserSidLength AS DWORD
    UserSidOffset AS DWORD
    DataLength AS DWORD
    DataOffset AS DWORD      ' Offset from beginning of record
    '
    ' Then follow:
    '
    ' WCHAR SourceName[]
    ' WCHAR Computername[]
    ' SID   UserSid
    ' WCHAR Strings[]
    ' BYTE  Data[]
    ' CHAR  Pad[]
    ' DWORD Length;
    '
END TYPE

'SS: start of changes to support clustering
'SS: ideally the
%MAXLOGICALLOGNAMESIZE  = 256


'struct _EVENTSFORLOGFILE;
'TYPE EVENTLOGRECORD
'typedef struct _EVENTSFORLOGFILE EVENTSFORLOGFILE, *PEVENTSFORLOGFILE;

'struct _PACKEDEVENTINFO;
'TYPE EVENTLOGRECORD
'typedef struct _PACKEDEVENTINFO PACKEDEVENTINFO, *PPACKEDEVENTINFO;

#IF %DEF(%MSC_EXTENSIONS)

TYPE EVENTSFORLOGFILE
    ulSize              AS DWORD
    szLogicalLogFile    AS WSTRINGZ * %MAXLOGICALLOGNAMESIZE  'name of the logical file-security/application/system
    ulNumRecords        AS DWORD
    pEventLogRecords(0) AS EVENTLOGRECORD
END TYPE

TYPE PACKEDEVENTINFO
    ulSize                AS DWORD  'total size of the structure
    ulNumEventsForLogFile AS DWORD  'number of EventsForLogFile structure that follow
    ulOffsets(0)          AS DWORD  'the offsets from the start of this structure to the EVENTSFORLOGFILE structure
END TYPE

#ENDIF

'SS: end of changes to support clustering
'

' begin_wdm
'
' Registry Specific Access Rights.
'

%KEY_QUERY_VALUE        = &H0001
%KEY_SET_VALUE          = &H0002
%KEY_CREATE_SUB_KEY     = &H0004
%KEY_ENUMERATE_SUB_KEYS = &H0008
%KEY_NOTIFY             = &H0010
%KEY_CREATE_LINK        = &H0020
%KEY_WOW64_32KEY        = &H0200
%KEY_WOW64_64KEY        = &H0100
%KEY_WOW64_RES          = &H0300

%KEY_READ               = ((%STANDARD_RIGHTS_READ       OR _
                                 %KEY_QUERY_VALUE            OR _
                                 %KEY_ENUMERATE_SUB_KEYS     OR _
                                 %KEY_NOTIFY)                 _
                                  AND                           _
                                 (NOT %SYNCHRONIZE))


%KEY_WRITE              = ((%STANDARD_RIGHTS_WRITE      OR _
                                 %KEY_SET_VALUE              OR _
                                 %KEY_CREATE_SUB_KEY)         _
                                  AND                           _
                                 (NOT %SYNCHRONIZE))

%KEY_EXECUTE            = ((%KEY_READ)                   _
                                  AND                           _
                                 (NOT %SYNCHRONIZE))

%KEY_ALL_ACCESS         = ((%STANDARD_RIGHTS_ALL        OR _
                                 %KEY_QUERY_VALUE            OR _
                                 %KEY_SET_VALUE              OR _
                                 %KEY_CREATE_SUB_KEY         OR _
                                 %KEY_ENUMERATE_SUB_KEYS     OR _
                                 %KEY_NOTIFY                 OR _
                                 %KEY_CREATE_LINK)            _
                                  AND                           _
                                 (NOT %SYNCHRONIZE))

'
' Open/Create Options
'

%REG_OPTION_RESERVED        = (&H00000000)   ' Parameter is reserved

%REG_OPTION_NON_VOLATILE    = (&H00000000)   ' Key is preserved
                                             ' when system is rebooted

%REG_OPTION_VOLATILE        = (&H00000001)   ' Key is not preserved
                                             ' when system is rebooted

%REG_OPTION_CREATE_LINK     = (&H00000002)   ' Created key is a
                                             ' symbolic link

%REG_OPTION_BACKUP_RESTORE  = (&H00000004)   ' open for backup or restore
                                             ' special access rules
                                             ' privilege required

%REG_OPTION_OPEN_LINK       = (&H00000008)   ' Open symbolic link

%REG_LEGAL_OPTION           = _
                (%REG_OPTION_RESERVED            OR _
                 %REG_OPTION_NON_VOLATILE        OR _
                 %REG_OPTION_VOLATILE            OR _
                 %REG_OPTION_CREATE_LINK         OR _
                 %REG_OPTION_BACKUP_RESTORE      OR _
                 %REG_OPTION_OPEN_LINK)

'
' Key creation/open disposition
'

%REG_CREATED_NEW_KEY        = (&H00000001)   ' New Registry Key created
%REG_OPENED_EXISTING_KEY    = (&H00000002)   ' Existing Key opened

'
' hive format to be used by Reg(Nt)SaveKeyEx
'
%REG_STANDARD_FORMAT    = 1
%REG_LATEST_FORMAT      = 2
%REG_NO_COMPRESSION     = 4

'
' Key restore & hive load flags
'

%REG_WHOLE_HIVE_VOLATILE        = (&H00000001)   ' Restore whole hive volatile
%REG_REFRESH_HIVE               = (&H00000002)   ' Unwind changes to last flush
%REG_NO_LAZY_FLUSH              = (&H00000004)   ' Never lazy flush this hive
%REG_FORCE_RESTORE              = (&H00000008)   ' Force the restore process even when we have open handles on subkeys
%REG_APP_HIVE                   = (&H00000010)   ' Loads the hive visible to the calling process
%REG_PROCESS_PRIVATE            = (&H00000020)   ' Hive cannot be mounted by any other process while in use
%REG_START_JOURNAL              = (&H00000040)   ' Starts Hive Journal
%REG_HIVE_EXACT_FILE_GROWTH     = (&H00000080)   ' Grow hive file in exact 4k increments
%REG_HIVE_NO_RM                 = (&H00000100)   ' No RM is started for this hive (no transactions)
%REG_HIVE_SINGLE_LOG            = (&H00000200)   ' Legacy single logging is used for this hive

'
' Unload Flags
'
%REG_FORCE_UNLOAD           = 1

'
' Notify filter values
'

%REG_NOTIFY_CHANGE_NAME         = (&H00000001) ' Create or delete (child)
%REG_NOTIFY_CHANGE_ATTRIBUTES   = (&H00000002)
%REG_NOTIFY_CHANGE_LAST_SET     = (&H00000004) ' time stamp
%REG_NOTIFY_CHANGE_SECURITY     = (&H00000008)

%REG_LEGAL_CHANGE_FILTER        =         _
                (%REG_NOTIFY_CHANGE_NAME          OR _
                 %REG_NOTIFY_CHANGE_ATTRIBUTES    OR _
                 %REG_NOTIFY_CHANGE_LAST_SET      OR _
                 %REG_NOTIFY_CHANGE_SECURITY)


'
'
' Predefined Value Types.
'

%REG_NONE                   = ( 0 )   ' No value type
%REG_SZ                     = ( 1 )   ' Unicode nul terminated string
%REG_EXPAND_SZ              = ( 2 )   ' Unicode nul terminated string
                                            ' (with environment variable references)
%REG_BINARY                 = ( 3 )   ' Free form binary
%REG_DWORD                  = ( 4 )   ' 32-bit number
%REG_DWORD_LITTLE_ENDIAN    = ( 4 )   ' 32-bit number (same as REG_DWORD)
%REG_DWORD_BIG_ENDIAN       = ( 5 )   ' 32-bit number
%REG_LINK                   = ( 6 )   ' Symbolic Link (unicode)
%REG_MULTI_SZ               = ( 7 )   ' Multiple Unicode strings
%REG_RESOURCE_LIST          = ( 8 )   ' Resource list in the resource map
%REG_FULL_RESOURCE_DESCRIPTOR =( 9 )  ' Resource list in the hardware description
%REG_RESOURCE_REQUIREMENTS_LIST =( 10 )
%REG_QWORD                  = ( 11 )  ' 64-bit number
%REG_QWORD_LITTLE_ENDIAN    = ( 11 )  ' 64-bit number (same as REG_QWORD)

' end_wdm

' begin_wdm
'
' Service Types (Bit Mask)
'
%SERVICE_KERNEL_DRIVER         = &H00000001
%SERVICE_FILE_SYSTEM_DRIVER    = &H00000002
%SERVICE_ADAPTER               = &H00000004
%SERVICE_RECOGNIZER_DRIVER     = &H00000008

%SERVICE_DRIVER                = (%SERVICE_KERNEL_DRIVER OR _
                                        %SERVICE_FILE_SYSTEM_DRIVER OR _
                                        %SERVICE_RECOGNIZER_DRIVER)

%SERVICE_WIN32_OWN_PROCESS     = &H00000010
%SERVICE_WIN32_SHARE_PROCESS   = &H00000020
%SERVICE_WIN32                 = (%SERVICE_WIN32_OWN_PROCESS OR _
                                        %SERVICE_WIN32_SHARE_PROCESS)

%SERVICE_INTERACTIVE_PROCESS   = &H00000100

%SERVICE_TYPE_ALL              = (%SERVICE_WIN32  OR _
                                        %SERVICE_ADAPTER OR _
                                        %SERVICE_DRIVER  OR _
                                        %SERVICE_INTERACTIVE_PROCESS)

'
' Start Type
'

%SERVICE_BOOT_START           = &H00000000
%SERVICE_SYSTEM_START         = &H00000001
%SERVICE_AUTO_START           = &H00000002
%SERVICE_DEMAND_START         = &H00000003
%SERVICE_DISABLED             = &H00000004

'
' Error control type
'
%SERVICE_ERROR_IGNORE         = &H00000000
%SERVICE_ERROR_NORMAL         = &H00000001
%SERVICE_ERROR_SEVERE         = &H00000002
%SERVICE_ERROR_CRITICAL       = &H00000003

'
'
' Define the registry driver node enumerations
'

MACRO CM_SERVICE_NODE_TYPE_enum=LONG
ENUM CM_SERVICE_NODE_TYPE SINGULAR
    DriverType               = %SERVICE_KERNEL_DRIVER
    FileSystemType           = %SERVICE_FILE_SYSTEM_DRIVER
    Win32ServiceOwnProcess   = %SERVICE_WIN32_OWN_PROCESS
    Win32ServiceShareProcess = %SERVICE_WIN32_SHARE_PROCESS
    AdapterType              = %SERVICE_ADAPTER
    RecognizerType           = %SERVICE_RECOGNIZER_DRIVER
END ENUM

MACRO CM_SERVICE_LOAD_TYPE_enum=LONG
ENUM CM_SERVICE_LOAD_TYPE SINGULAR
    BootLoad    = %SERVICE_BOOT_START
    SystemLoad  = %SERVICE_SYSTEM_START
    AutoLoad    = %SERVICE_AUTO_START
    DemandLoad  = %SERVICE_DEMAND_START
    DisableLoad = %SERVICE_DISABLED
END ENUM

MACRO CM_ERROR_CONTROL_TYPE_enum=LONG
ENUM CM_ERROR_CONTROL_TYPE SINGULAR
    IgnoreError   = %SERVICE_ERROR_IGNORE
    NormalError   = %SERVICE_ERROR_NORMAL
    SevereError   = %SERVICE_ERROR_SEVERE
    CriticalError = %SERVICE_ERROR_CRITICAL
END ENUM

'
' Service node Flags
'

'
' The following flag, if set, is used by the OS loader to promote
' a driver's start type to boot start when booting from a network.
'

%CM_SERVICE_NETWORK_BOOT_LOAD = &H00000001



'
' IOCTL_TAPE_ERASE definitions
'

%TAPE_ERASE_SHORT          = 0
%TAPE_ERASE_LONG           = 1

TYPE TAPE_ERASE
    dType     AS DWORD
    Immediate AS BYTE
END TYPE

'
' IOCTL_TAPE_PREPARE definitions
'

%TAPE_LOAD                 = 0
%TAPE_UNLOAD               = 1
%TAPE_TENSION              = 2
%TAPE_LOCK                 = 3
%TAPE_UNLOCK               = 4
%TAPE_FORMAT               = 5

TYPE TAPE_PREPARE
    Operation AS DWORD
    Immediate AS BYTE
END TYPE

'
' IOCTL_TAPE_WRITE_MARKS definitions
'

%TAPE_SETMARKS             = 0
%TAPE_FILEMARKS            = 1
%TAPE_SHORT_FILEMARKS      = 2
%TAPE_LONG_FILEMARKS       = 3

TYPE TAPE_WRITE_MARKS
    dType     AS DWORD
    COUNT     AS DWORD
    Immediate AS BYTE
END TYPE

'
' IOCTL_TAPE_GET_POSITION definitions
'

%TAPE_ABSOLUTE_POSITION       = 0
%TAPE_LOGICAL_POSITION        = 1
%TAPE_PSEUDO_LOGICAL_POSITION = 2

TYPE TAPE_GET_POSITION
    dType     AS DWORD
    Partition AS DWORD
    Offset    AS QUAD
END TYPE

'
' IOCTL_TAPE_SET_POSITION definitions
'

%TAPE_REWIND                = 0
%TAPE_ABSOLUTE_BLOCK        = 1
%TAPE_LOGICAL_BLOCK         = 2
%TAPE_PSEUDO_LOGICAL_BLOCK  = 3
%TAPE_SPACE_END_OF_DATA     = 4
%TAPE_SPACE_RELATIVE_BLOCKS = 5
%TAPE_SPACE_FILEMARKS       = 6
%TAPE_SPACE_SEQUENTIAL_FMKS = 7
%TAPE_SPACE_SETMARKS        = 8
%TAPE_SPACE_SEQUENTIAL_SMKS = 9

TYPE TAPE_SET_POSITION
    dMethod   AS DWORD
    Partition AS DWORD
    Offset    AS QUAD
    Immediate AS BYTE
END TYPE

'
' IOCTL_TAPE_GET_DRIVE_PARAMS definitions
'

'
' Definitions for FeaturesLow parameter
'

%TAPE_DRIVE_FIXED            = &H00000001
%TAPE_DRIVE_SELECT           = &H00000002
%TAPE_DRIVE_INITIATOR        = &H00000004

%TAPE_DRIVE_ERASE_SHORT      = &H00000010
%TAPE_DRIVE_ERASE_LONG       = &H00000020
%TAPE_DRIVE_ERASE_BOP_ONLY   = &H00000040
%TAPE_DRIVE_ERASE_IMMEDIATE  = &H00000080

%TAPE_DRIVE_TAPE_CAPACITY    = &H00000100
%TAPE_DRIVE_TAPE_REMAINING   = &H00000200
%TAPE_DRIVE_FIXED_BLOCK      = &H00000400
%TAPE_DRIVE_VARIABLE_BLOCK   = &H00000800

%TAPE_DRIVE_WRITE_PROTECT    = &H00001000
%TAPE_DRIVE_EOT_WZ_SIZE      = &H00002000

%TAPE_DRIVE_ECC              = &H00010000
%TAPE_DRIVE_COMPRESSION      = &H00020000
%TAPE_DRIVE_PADDING          = &H00040000
%TAPE_DRIVE_REPORT_SMKS      = &H00080000

%TAPE_DRIVE_GET_ABSOLUTE_BLK = &H00100000
%TAPE_DRIVE_GET_LOGICAL_BLK  = &H00200000
%TAPE_DRIVE_SET_EOT_WZ_SIZE  = &H00400000

%TAPE_DRIVE_EJECT_MEDIA      = &H01000000
%TAPE_DRIVE_CLEAN_REQUESTS   = &H02000000
%TAPE_DRIVE_SET_CMP_BOP_ONLY = &H04000000

%TAPE_DRIVE_RESERVED_BIT     = &H80000000  'don't use this bit!
'                                              'can't be a low features bit!
'                                              'reserved; high features only

'
' Definitions for FeaturesHigh parameter
'

%TAPE_DRIVE_LOAD_UNLOAD      = &H80000001
%TAPE_DRIVE_TENSION          = &H80000002
%TAPE_DRIVE_LOCK_UNLOCK      = &H80000004
%TAPE_DRIVE_REWIND_IMMEDIATE = &H80000008

%TAPE_DRIVE_SET_BLOCK_SIZE   = &H80000010
%TAPE_DRIVE_LOAD_UNLD_IMMED  = &H80000020
%TAPE_DRIVE_TENSION_IMMED    = &H80000040
%TAPE_DRIVE_LOCK_UNLK_IMMED  = &H80000080

%TAPE_DRIVE_SET_ECC          = &H80000100
%TAPE_DRIVE_SET_COMPRESSION  = &H80000200
%TAPE_DRIVE_SET_PADDING      = &H80000400
%TAPE_DRIVE_SET_REPORT_SMKS  = &H80000800

%TAPE_DRIVE_ABSOLUTE_BLK     = &H80001000
%TAPE_DRIVE_ABS_BLK_IMMED    = &H80002000
%TAPE_DRIVE_LOGICAL_BLK      = &H80004000
%TAPE_DRIVE_LOG_BLK_IMMED    = &H80008000

%TAPE_DRIVE_END_OF_DATA      = &H80010000
%TAPE_DRIVE_RELATIVE_BLKS    = &H80020000
%TAPE_DRIVE_FILEMARKS        = &H80040000
%TAPE_DRIVE_SEQUENTIAL_FMKS  = &H80080000

%TAPE_DRIVE_SETMARKS         = &H80100000
%TAPE_DRIVE_SEQUENTIAL_SMKS  = &H80200000
%TAPE_DRIVE_REVERSE_POSITION = &H80400000
%TAPE_DRIVE_SPACE_IMMEDIATE  = &H80800000

%TAPE_DRIVE_WRITE_SETMARKS   = &H81000000
%TAPE_DRIVE_WRITE_FILEMARKS  = &H82000000
%TAPE_DRIVE_WRITE_SHORT_FMKS = &H84000000
%TAPE_DRIVE_WRITE_LONG_FMKS  = &H88000000

%TAPE_DRIVE_WRITE_MARK_IMMED = &H90000000
%TAPE_DRIVE_FORMAT           = &HA0000000
%TAPE_DRIVE_FORMAT_IMMEDIATE = &HC0000000
%TAPE_DRIVE_HIGH_FEATURES    = &H80000000  'mask for high features flag

TYPE TAPE_GET_DRIVE_PARAMETERS
    ECC                   AS BYTE ' BOOLEAN
    Compression           AS BYTE ' BOOLEAN
    DataPadding           AS BYTE ' BOOLEAN
    ReportSetmarks        AS BYTE ' BOOLEAN
    DefaultBlockSize      AS DWORD
    MaximumBlockSize      AS DWORD
    MinimumBlockSize      AS DWORD
    MaximumPartitionCount AS DWORD
    FeaturesLow           AS DWORD
    FeaturesHigh          AS DWORD
    EOTWarningZoneSize    AS DWORD
END TYPE

'
' IOCTL_TAPE_SET_DRIVE_PARAMETERS definitions
'

TYPE TAPE_SET_DRIVE_PARAMETERS
    ECC                AS BYTE ' BOOLEAN
    Compression        AS BYTE ' BOOLEAN
    DataPadding        AS BYTE ' BOOLEAN
    ReportSetmarks     AS BYTE ' BOOLEAN
    EOTWarningZoneSize AS DWORD
END TYPE

'
' IOCTL_TAPE_GET_MEDIA_PARAMETERS definitions
'

TYPE TAPE_GET_MEDIA_PARAMETERS
    Capacity       AS QUAD ' LARGE_INTEGER
    Remaining      AS QUAD ' LARGE_INTEGER
    BlockSize      AS DWORD
    PartitionCount AS DWORD
    WriteProtected AS BYTE ' BOOLEAN
END TYPE

'
' IOCTL_TAPE_SET_MEDIA_PARAMETERS definitions
'

TYPE TAPE_SET_MEDIA_PARAMETERS
    BlockSize AS DWORD
END TYPE

'
' IOCTL_TAPE_CREATE_PARTITION definitions
'

%TAPE_FIXED_PARTITIONS     = 0
%TAPE_SELECT_PARTITIONS    = 1
%TAPE_INITIATOR_PARTITIONS = 2

TYPE TAPE_CREATE_PARTITION
    METHOD AS DWORD
    COUNT  AS DWORD
    SIZE   AS DWORD
END TYPE


'
' WMI Methods
'
%TAPE_QUERY_DRIVE_PARAMETERS     = 0
%TAPE_QUERY_MEDIA_CAPACITY       = 1
%TAPE_CHECK_FOR_DRIVE_PROBLEM    = 2
%TAPE_QUERY_IO_ERROR_DATA        = 3
%TAPE_QUERY_DEVICE_ERROR_DATA    = 4

TYPE TAPE_WMI_OPERATIONS
   METHOD         AS DWORD
   DataBufferSize AS DWORD
   DataBuffer     AS DWORD ' PVOID
END TYPE

'
' Type of drive errors
'
MACRO TAPE_DRIVE_PROBLEM_TYPE_enum=LONG
ENUM TAPE_DRIVE_PROBLEM_TYPE SINGULAR
    TapeDriveProblemNone
    TapeDriveReadWriteWarning
    TapeDriveReadWriteError
    TapeDriveReadWarning
    TapeDriveWriteWarning
    TapeDriveReadError
    TapeDriveWriteError
    TapeDriveHardwareError
    TapeDriveUnsupportedMedia
    TapeDriveScsiConnectionError
    TapeDriveTimetoClean
    TapeDriveCleanDriveNow
    TapeDriveMediaLifeExpired
    TapeDriveSnappedTape
END ENUM

#IF NOT %DEF(%NTTMAPI)

%NTTMAPI = 1


#INCLUDE "ktmtypes.inc"

'
' Types for Nt level TM calls
'

'
' KTM Tm object rights
'
%TRANSACTIONMANAGER_QUERY_INFORMATION     = &H0001
%TRANSACTIONMANAGER_SET_INFORMATION       = &H0002
%TRANSACTIONMANAGER_RECOVER               = &H0004
%TRANSACTIONMANAGER_RENAME                = &H0008
%TRANSACTIONMANAGER_CREATE_RM             = &H0010

' The following right is intended for DTC's use only; it will be
' deprecated, and no one else should take a dependency on it.
%TRANSACTIONMANAGER_BIND_TRANSACTION      = &H0020

'
' Generic mappings for transaction manager rights.
'

%TRANSACTIONMANAGER_GENERIC_READ          = (%STANDARD_RIGHTS_READ            OR _
                                             %TRANSACTIONMANAGER_QUERY_INFORMATION)

%TRANSACTIONMANAGER_GENERIC_WRITE         = (%STANDARD_RIGHTS_WRITE           OR _
                                             %TRANSACTIONMANAGER_SET_INFORMATION     OR _
                                             %TRANSACTIONMANAGER_RECOVER             OR _
                                             %TRANSACTIONMANAGER_RENAME              OR _
                                             %TRANSACTIONMANAGER_CREATE_RM)

%TRANSACTIONMANAGER_GENERIC_EXECUTE       = (%STANDARD_RIGHTS_EXECUTE)

%TRANSACTIONMANAGER_ALL_ACCESS            = (%STANDARD_RIGHTS_REQUIRED        OR _
                                             %TRANSACTIONMANAGER_GENERIC_READ        OR _
                                             %TRANSACTIONMANAGER_GENERIC_WRITE       OR _
                                             %TRANSACTIONMANAGER_GENERIC_EXECUTE     OR _
                                             %TRANSACTIONMANAGER_BIND_TRANSACTION)


'
' KTM transaction object rights.
'
%TRANSACTION_QUERY_INFORMATION     = &H0001
%TRANSACTION_SET_INFORMATION       = &H0002
%TRANSACTION_ENLIST                = &H0004
%TRANSACTION_COMMIT                = &H0008
%TRANSACTION_ROLLBACK              = &H0010
%TRANSACTION_PROPAGATE             = &H0020
%TRANSACTION_RIGHT_RESERVED1       = &H0040

'
' Generic mappings for transaction rights.
' Resource managers, when enlisting, should generally use the macro
' TRANSACTION_RESOURCE_MANAGER_RIGHTS when opening a transaction.
' It's the same as generic read and write except that it does not allow
' a commit decision to be made.
'

%TRANSACTION_GENERIC_READ            = (%STANDARD_RIGHTS_READ            OR _
                                        %TRANSACTION_QUERY_INFORMATION   OR _
                                        %SYNCHRONIZE)

%TRANSACTION_GENERIC_WRITE           = (%STANDARD_RIGHTS_WRITE           OR _
                                        %TRANSACTION_SET_INFORMATION     OR _
                                        %TRANSACTION_COMMIT              OR _
                                        %TRANSACTION_ENLIST              OR _
                                        %TRANSACTION_ROLLBACK            OR _
                                        %TRANSACTION_PROPAGATE           OR _
                                        %SYNCHRONIZE)

%TRANSACTION_GENERIC_EXECUTE         = (%STANDARD_RIGHTS_EXECUTE         OR _
                                        %TRANSACTION_COMMIT              OR _
                                        %TRANSACTION_ROLLBACK            OR _
                                        %SYNCHRONIZE)

%TRANSACTION_ALL_ACCESS              = (%STANDARD_RIGHTS_REQUIRED        OR _
                                        %TRANSACTION_GENERIC_READ        OR _
                                        %TRANSACTION_GENERIC_WRITE       OR _
                                        %TRANSACTION_GENERIC_EXECUTE)

%TRANSACTION_RESOURCE_MANAGER_RIGHTS = (%TRANSACTION_GENERIC_READ        OR _
                                        %STANDARD_RIGHTS_WRITE           OR _
                                        %TRANSACTION_SET_INFORMATION     OR _
                                        %TRANSACTION_ENLIST              OR _
                                        %TRANSACTION_ROLLBACK            OR _
                                        %TRANSACTION_PROPAGATE           OR _
                                        %SYNCHRONIZE)

'
' KTM resource manager object rights.
'
%RESOURCEMANAGER_QUERY_INFORMATION     = &H0001
%RESOURCEMANAGER_SET_INFORMATION       = &H0002
%RESOURCEMANAGER_RECOVER               = &H0004
%RESOURCEMANAGER_ENLIST                = &H0008
%RESOURCEMANAGER_GET_NOTIFICATION      = &H0010
%RESOURCEMANAGER_REGISTER_PROTOCOL     = &H0020
%RESOURCEMANAGER_COMPLETE_PROPAGATION  = &H0040

'
' Generic mappings for resource manager rights.
'
%RESOURCEMANAGER_GENERIC_READ      = (%STANDARD_RIGHTS_READ                 OR _
                                      %RESOURCEMANAGER_QUERY_INFORMATION    OR _
                                      %SYNCHRONIZE)

%RESOURCEMANAGER_GENERIC_WRITE     = (%STANDARD_RIGHTS_WRITE                OR _
                                      %RESOURCEMANAGER_SET_INFORMATION      OR _
                                      %RESOURCEMANAGER_RECOVER              OR _
                                      %RESOURCEMANAGER_ENLIST               OR _
                                      %RESOURCEMANAGER_GET_NOTIFICATION     OR _
                                      %RESOURCEMANAGER_REGISTER_PROTOCOL    OR _
                                      %RESOURCEMANAGER_COMPLETE_PROPAGATION OR _
                                      %SYNCHRONIZE)

%RESOURCEMANAGER_GENERIC_EXECUTE   = (%STANDARD_RIGHTS_EXECUTE              OR _
                                      %RESOURCEMANAGER_RECOVER              OR _
                                      %RESOURCEMANAGER_ENLIST               OR _
                                      %RESOURCEMANAGER_GET_NOTIFICATION     OR _
                                      %RESOURCEMANAGER_COMPLETE_PROPAGATION OR _
                                      %SYNCHRONIZE)

%RESOURCEMANAGER_ALL_ACCESS        = (%STANDARD_RIGHTS_REQUIRED             OR _
                                      %RESOURCEMANAGER_GENERIC_READ         OR _
                                      %RESOURCEMANAGER_GENERIC_WRITE        OR _
                                      %RESOURCEMANAGER_GENERIC_EXECUTE)


'
' KTM enlistment object rights.
'
%ENLISTMENT_QUERY_INFORMATION     = &H0001
%ENLISTMENT_SET_INFORMATION       = &H0002
%ENLISTMENT_RECOVER               = &H0004
%ENLISTMENT_SUBORDINATE_RIGHTS    = &H0008
%ENLISTMENT_SUPERIOR_RIGHTS       = &H0010

'
' Generic mappings for enlistment rights.
'
%ENLISTMENT_GENERIC_READ      = (%STANDARD_RIGHTS_READ           OR _
                                 %ENLISTMENT_QUERY_INFORMATION)

%ENLISTMENT_GENERIC_WRITE     = (%STANDARD_RIGHTS_WRITE          OR _
                                 %ENLISTMENT_SET_INFORMATION     OR _
                                 %ENLISTMENT_RECOVER             OR _
                                 %ENLISTMENT_SUBORDINATE_RIGHTS  OR _
                                 %ENLISTMENT_SUPERIOR_RIGHTS)

%ENLISTMENT_GENERIC_EXECUTE   = (%STANDARD_RIGHTS_EXECUTE        OR _
                                 %ENLISTMENT_RECOVER             OR _
                                 %ENLISTMENT_SUBORDINATE_RIGHTS  OR _
                                 %ENLISTMENT_SUPERIOR_RIGHTS)

%ENLISTMENT_ALL_ACCESS        = (%STANDARD_RIGHTS_REQUIRED       OR _
                                 %ENLISTMENT_GENERIC_READ        OR _
                                 %ENLISTMENT_GENERIC_WRITE       OR _
                                 %ENLISTMENT_GENERIC_EXECUTE)


'
' Transaction outcomes.
'
' TODO: warning, must match values in KTRANSACTION_OUTCOME duplicated def
' in tm.h.
'

MACRO TRANSACTION_OUTCOME_enum=LONG
ENUM TRANSACTION_OUTCOME SINGULAR
    TransactionOutcomeUndetermined = 1
    TransactionOutcomeCommitted
    TransactionOutcomeAborted
END ENUM


MACRO TRANSACTION_STATE_enum=LONG
ENUM TRANSACTION_STATE SINGULAR
    TransactionStateNormal          = 1
    TransactionStateIndoubt
    TransactionStateCommittedNotify
END ENUM


TYPE TRANSACTION_BASIC_INFORMATION
    TransactionId AS GUID
    STATE         AS DWORD
    Outcome       AS DWORD
END TYPE

TYPE TRANSACTIONMANAGER_BASIC_INFORMATION
    TmIdentity   AS GUID
    VirtualClock AS QUAD
END TYPE

TYPE TRANSACTIONMANAGER_LOG_INFORMATION
    LogIdentity AS GUID
END TYPE

TYPE TRANSACTIONMANAGER_LOGPATH_INFORMATION
    LogPathLength AS DWORD
    LogPath AS WSTRINGZ * 1 ' Variable size
'  Data(0)                                         ' Variable size data not declared
END TYPE

TYPE TRANSACTIONMANAGER_RECOVERY_INFORMATION
    LastRecoveredLsn AS QUAD
END TYPE


' end_wdm
TYPE TRANSACTIONMANAGER_OLDEST_INFORMATION
    OldestTransactionGuid AS GUID
END TYPE
' begin_wdm


TYPE TRANSACTION_PROPERTIES_INFORMATION
    IsolationLevel    AS DWORD
    IsolationFlags    AS DWORD
    TIMEOUT           AS QUAD
    Outcome           AS DWORD
    DescriptionLength AS DWORD
    Description       AS WSTRINGZ * 1    ' Variable size
'          Data(0)            ' Variable size data not declared
END TYPE

' The following info-class is intended for DTC's use only; it will be
' deprecated, and no one else should take a dependency on it.
TYPE TRANSACTION_BIND_INFORMATION
    TmHandle AS DWORD
END TYPE

TYPE TRANSACTION_ENLISTMENT_PAIR
    EnlistmentId      AS GUID
    ResourceManagerId AS GUID
END TYPE

TYPE TRANSACTION_ENLISTMENTS_INFORMATION
    NumberOfEnlistments AS DWORD
    EnlistmentPair(0) AS TRANSACTION_ENLISTMENT_PAIR  ' Variable size
END TYPE

TYPE TRANSACTION_SUPERIOR_ENLISTMENT_INFORMATION
    SuperiorEnlistmentPair AS TRANSACTION_ENLISTMENT_PAIR
END TYPE


TYPE RESOURCEMANAGER_BASIC_INFORMATION
    ResourceManagerId AS GUID
    DescriptionLength AS DWORD
    Description AS WSTRINGZ * 1        ' Variable size
END TYPE

TYPE RESOURCEMANAGER_COMPLETION_INFORMATION
    IoCompletionPortHandle AS DWORD
    CompletionKey          AS DWORD
END TYPE

' end_wdm

' begin_wdm
MACRO TRANSACTION_INFORMATION_CLASS_enum=LONG
ENUM TRANSACTION_INFORMATION_CLASS SINGULAR
    TransactionBasicInformation
    TransactionPropertiesInformation
    TransactionEnlistmentInformation
    TransactionSuperiorEnlistmentInformation
END ENUM
' end_wdm

' The following info-classes are intended for DTC's use only; it will be
' deprecated, and no one else should take a dependency on it.
%TransactionBindInformation               = 4 ' private and deprecated
%TransactionDTCPrivateInformation         = 5 ' private and deprecated

' begin_wdm

' begin_wdm
MACRO TRANSACTIONMANAGER_INFORMATION_CLASS_enum=LONG
ENUM TRANSACTIONMANAGER_INFORMATION_CLASS SINGULAR
    TransactionManagerBasicInformation
    TransactionManagerLogInformation
    TransactionManagerLogPathInformation
    TransactionManagerRecoveryInformation = 4
END ENUM
' end_wdm

' The following info-classes are intended for internal use only; they
' are considered deprecated, and no one else should take a dependency
' on them.
%TransactionManagerOnlineProbeInformation = 3
%TransactionManagerOldestTransactionInformation = 5
' end_wdm

' begin_wdm


' begin_wdm
MACRO RESOURCEMANAGER_INFORMATION_CLASS_enum=LONG
ENUM RESOURCEMANAGER_INFORMATION_CLASS SINGULAR
    ResourceManagerBasicInformation
    ResourceManagerCompletionInformation
END ENUM

TYPE ENLISTMENT_BASIC_INFORMATION
    EnlistmentId      AS GUID
    TransactionId     AS GUID
    ResourceManagerId AS GUID
END TYPE

TYPE ENLISTMENT_CRM_INFORMATION
    CrmTransactionManagerId AS GUID
    CrmResourceManagerId    AS GUID
    CrmEnlistmentId         AS GUID
END TYPE


' begin_wdm
MACRO ENLISTMENT_INFORMATION_CLASS_enum=LONG
ENUM ENLISTMENT_INFORMATION_CLASS SINGULAR
    EnlistmentBasicInformation
    EnlistmentRecoveryInformation
    EnlistmentCrmInformation
END ENUM

TYPE TRANSACTION_LIST_ENTRY
    UOW AS GUID
END TYPE

TYPE TRANSACTION_LIST_INFORMATION
    NumberOfTransactions      AS DWORD
    TransactionInformation(0) AS TRANSACTION_LIST_ENTRY  ' Var size
END TYPE


'
' Types of objects known to the kernel transaction manager.
'

MACRO KTMOBJECT_TYPE_enum=LONG
ENUM KTMOBJECT_TYPE SINGULAR
    KTMOBJECT_TRANSACTION
    KTMOBJECT_TRANSACTION_MANAGER
    KTMOBJECT_RESOURCE_MANAGER
    KTMOBJECT_ENLISTMENT
    KTMOBJECT_INVALID
END ENUM

'
' KTMOBJECT_CURSOR
'
' Used by NtEnumerateTransactionObject to enumerate a transaction
' object namespace (e.g. enlistments in a resource manager).
'

TYPE KTMOBJECT_CURSOR

    '
    ' The last GUID enumerated; zero if beginning enumeration.
    '

    LastQuery AS GUID

    '
    ' A count of GUIDs filled in by this last enumeration.
    '

    ObjectIdCount AS DWORD

    '
    ' ObjectIdCount GUIDs from the namespace specified.
    '

    ObjectIds(0) AS GUID

END TYPE

' begin_wdm

#ENDIF ' %NTTMAPI

MACRO TP_VERSION=DWORD

DECLARE SUB PTP_SIMPLE_CALLBACK ( _
    BYVAL pInstance AS DWORD, _   ' TP_CALLBACK_INSTANCE PTR
    BYVAL Context   AS DWORD _    ' PVOID
    )

MACRO TP_CALLBACK_PRIORITY_enum=LONG
ENUM TP_CALLBACK_PRIORITY SINGULAR
    TP_CALLBACK_PRIORITY_HIGH
    TP_CALLBACK_PRIORITY_NORMAL
    TP_CALLBACK_PRIORITY_LOW
    TP_CALLBACK_PRIORITY_INVALID
END ENUM

TYPE TP_POOL_STACK_INFORMATION
    StackReserve AS SIZE_T
    StackCommit AS SIZE_T
END TYPE

DECLARE SUB PTP_CLEANUP_GROUP_CANCEL_CALLBACK ( _
    BYVAL ObjectContext  AS DWORD, _  ' PVOID
    BYVAL CleanupContext AS DWORD _   ' PVOID
    )

'
' Do not manipulate this structure directly!  Allocate space for it
' and use the inline interfaces below.
'
TYPE TP_CALLBACK_ENVIRON_type
    LongFunction AS BIT * 1 IN DWORD
    PRIVATE      AS BIT * 31
END TYPE

UNION TP_CALLBACK_ENVIRON_union
    Flags        AS DWORD
    TP_CALLBACK_ENVIRON_type
END UNION

TYPE TP_CALLBACK_ENVIRON
    Version                    AS TP_VERSION
    Pool                       AS DWORD  ' TP_POOL PTR
    CleanupGroup               AS DWORD  ' TP_CLEANUP_GROUP PTR
    CleanupGroupCancelCallback AS DWORD  ' PTP_CLEANUP_GROUP_CANCEL_CALLBACK
    RaceDll                    AS DWORD
    ActivationContext          AS DWORD  ' ACTIVATION_CONTEXT PTR
    FinalizationCallback       AS DWORD  ' PTP_SIMPLE_CALLBACK
    TP_CALLBACK_ENVIRON_union
END TYPE

#IF NOT %DEF(%MIDL_PASS)

SUB TpInitializeCallbackEnviron ( _
    BYVAL CallbackEnviron AS TP_CALLBACK_ENVIRON PTR _
    )
    @CallbackEnviron.Version = 1
    @CallbackEnviron.Pool = %NULL
    @CallbackEnviron.CleanupGroup = %NULL
    @CallbackEnviron.CleanupGroupCancelCallback = %NULL
    @CallbackEnviron.RaceDll = %NULL
    @CallbackEnviron.ActivationContext = %NULL
    @CallbackEnviron.FinalizationCallback = %NULL
    @CallbackEnviron.Flags = 0
END SUB


SUB TpSetCallbackThreadpool ( _
    BYVAL CallbackEnviron AS TP_CALLBACK_ENVIRON PTR, _
    BYVAL Pool            AS DWORD _  ' TP_POOL PTR _
    )
    @CallbackEnviron.Pool = Pool
END SUB

'FORCEINLINE
'VOID
'TpSetCallbackCleanupGroup(
'    __inout  PTP_CALLBACK_ENVIRON              CallbackEnviron,
'        PTP_CLEANUP_GROUP                 CleanupGroup,
'    __in_opt PTP_CLEANUP_GROUP_CANCEL_CALLBACK CleanupGroupCancelCallback
'    )
'{
'    CallbackEnviron->CleanupGroup = CleanupGroup;
'    CallbackEnviron->CleanupGroupCancelCallback = CleanupGroupCancelCallback;
'}
'
'FORCEINLINE
'VOID
'TpSetCallbackActivationContext(
'    __inout  PTP_CALLBACK_ENVIRON CallbackEnviron,
'    __in_opt struct _ACTIVATION_CONTEXT *ActivationContext
'    )
'{
'    CallbackEnviron->ActivationContext = ActivationContext;
'}
'
'FORCEINLINE
'VOID
'TpSetCallbackNoActivationContext(
'    __inout PTP_CALLBACK_ENVIRON CallbackEnviron
'    )
'{
'    CallbackEnviron->ActivationContext = (struct _ACTIVATION_CONTEXT *)(LONG_PTR) -1; ' INVALID_ACTIVATION_CONTEXT
'}
'
'FORCEINLINE
'VOID
'TpSetCallbackLongFunction(
'    __inout PTP_CALLBACK_ENVIRON CallbackEnviron
'    )
'{
'    CallbackEnviron->u.s.LongFunction = 1;
'}
'
'FORCEINLINE
'VOID
'TpSetCallbackRaceWithDll(
'    __inout PTP_CALLBACK_ENVIRON CallbackEnviron,
'       PVOID                DllHandle
'    )
'{
'    CallbackEnviron->RaceDll = DllHandle;
'}
'
'FORCEINLINE
'VOID
'TpSetCallbackFinalizationCallback(
'    __inout PTP_CALLBACK_ENVIRON CallbackEnviron,
'       PTP_SIMPLE_CALLBACK  FinalizationCallback
'    )
'{
'    CallbackEnviron->FinalizationCallback = FinalizationCallback;
'}
'
'FORCEINLINE
'VOID
'TpDestroyCallbackEnviron(
'    PTP_CALLBACK_ENVIRON CallbackEnviron
'    )
'{
'    '
'    ' For the current version of the callback environment, no actions
'    ' need to be taken to tear down an initialized structure.  This
'    ' may change in a future release.
'    '
'
'    UNREFERENCED_PARAMETER(CallbackEnviron);
'}

#ENDIF ' NOT %DEF(%MIDL_PASS)


DECLARE SUB PTP_WORK_CALLBACK ( _
    BYVAL dInstance AS DWORD, _    ' PTP_CALLBACK_INSTANCE
    BYVAL Context   AS DWORD, _    ' PVOID
    Work            AS ANY _       ' TP_WORK _
    )

DECLARE SUB PTP_TIMER_CALLBACK ( _
    BYVAL dInstance AS DWORD, _    ' PTP_CALLBACK_INSTANCE
    BYVAL Context   AS DWORD, _    ' PVOID
    tTimer          AS ANY _       ' TP_TIMER _
    )

MACRO TP_WAIT_RESULT=DWORD

DECLARE SUB PTP_WAIT_CALLBACK ( _
    BYVAL dInstance  AS DWORD, _    ' PTP_CALLBACK_INSTANCE
    BYVAL Context    AS DWORD, _    ' PVOID
    Wait             AS ANY, _      ' TP_WAIT, _
    BYVAL WaitResult AS TP_WAIT_RESULT _
    )


#IF (%WIN32_WINNT > &H0500) OR %ISOLATION_AWARE_ENABLED ' winnt_only
%ACTIVATION_CONTEXT_SECTION_ASSEMBLY_INFORMATION         = 1
%ACTIVATION_CONTEXT_SECTION_DLL_REDIRECTION              = 2
%ACTIVATION_CONTEXT_SECTION_WINDOW_CLASS_REDIRECTION     = 3
%ACTIVATION_CONTEXT_SECTION_COM_SERVER_REDIRECTION       = 4
%ACTIVATION_CONTEXT_SECTION_COM_INTERFACE_REDIRECTION    = 5
%ACTIVATION_CONTEXT_SECTION_COM_TYPE_LIBRARY_REDIRECTION = 6
%ACTIVATION_CONTEXT_SECTION_COM_PROGID_REDIRECTION       = 7
%ACTIVATION_CONTEXT_SECTION_GLOBAL_OBJECT_RENAME_TABLE   = 8
%ACTIVATION_CONTEXT_SECTION_CLR_SURROGATES               = 9
%ACTIVATION_CONTEXT_SECTION_APPLICATION_SETTINGS         = 10
#ENDIF ' winnt_only
