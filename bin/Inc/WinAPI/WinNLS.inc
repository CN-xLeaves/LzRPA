'------------------------------------------------------------------------------
'
'  WinNLS.inc
'    Procedure declarations, constant definitions, and macros for the
'    NLS component.
'
'  Copyright (c) 1997-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from winnls.h dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WINNLS = 1

#INCLUDE "SdkDdkVer.inc"
#INCLUDE "WinDef.inc"
#INCLUDE "WTypes.inc"

#IF NOT %DEF(%NONLS)


'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
'  Constants
'
'  Define all constants for the NLS component here.
'
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

'
'  String Length Maximums.
'
%MAX_LEADBYTES           = 12          ' 5 ranges, 2 bytes ea., 0 term.
%MAX_DEFAULTCHAR         = 2           ' single or double byte

'
'  Surrogate pairs
'
'  Conversion examples:
'
'  A) The first character in the Surrogate range (D800, DC00) as UTF-32:
'
'  1.  D800: binary 1101100000000000  (lower ten bits: 0000000000)
'  2.  DC00: binary 1101110000000000  (lower ten bits: 0000000000)
'  3.  Concatenate 0000000000+0000000000 = &H0000
'  4.  Add &H10000
'
'  Result: U+10000. This is correct, since the first character in the Supplementary character
'  range immediately follows the last code point in the 16-bit UTF-16 range (U+FFFF)
'
'  B) A UTF-32 code point such as U+2040A (this a CJK character in CJK Extension B), and wish
'  to convert it in UTF-16:
'
'  1.  Subtract &H10000 - Result: &H1040A
'  2.  Split into two ten-bit pieces: 0001000001 0000001010
'  3.  Add 1101100000000000 (&HD800) to the high 10 bits piece (0001000001) - Result: 1101100001000001 (&HD841)
'  4.  Add 1101110000000000 (&HDC00) to the low 10 bits piece (0000001010) - Result: 1101110000001010 (&HDC0A)
'
'  RESULT: The surrogate pair: U+D841, U+DC0A
'
'  Special Unicode code point values, for use with UTF-16 surrogate pairs.
'
%HIGH_SURROGATE_START = &Hd800??
%HIGH_SURROGATE_END   = &Hdbff??
%LOW_SURROGATE_START  = &Hdc00??
%LOW_SURROGATE_END    = &Hdfff??


'
'  MBCS and Unicode Translation Flags.
'
%MB_PRECOMPOSED           = &H00000001  ' use precomposed chars
%MB_COMPOSITE             = &H00000002  ' use composite chars
%MB_USEGLYPHCHARS         = &H00000004  ' use glyph chars, not ctrl chars
%MB_ERR_INVALID_CHARS     = &H00000008  ' error for invalid chars

%WC_COMPOSITECHECK        = &H00000200  ' convert composite to precomposed
%WC_DISCARDNS             = &H00000010  ' discard non-spacing chars
%WC_SEPCHARS              = &H00000020  ' generate separate chars
%WC_DEFAULTCHAR           = &H00000040  ' replace w/ default char
#IF (%WINVER >= &H0600)
%WC_ERR_INVALID_CHARS     = &H00000080  ' error for invalid chars
#ENDIF

#IF (%WINVER >= &H0500)
%WC_NO_BEST_FIT_CHARS     = &H00000400  ' do not use best fit chars
#ENDIF ' WINVER >= &H0500


'
'  Character Type Flags.
'
%CT_CTYPE1               = &H00000001  ' ctype 1 information
%CT_CTYPE2               = &H00000002  ' ctype 2 information
%CT_CTYPE3               = &H00000004  ' ctype 3 information

'
'  CType 1 Flag Bits.
'
%C1_UPPER                = &H0001      ' upper case
%C1_LOWER                = &H0002      ' lower case
%C1_DIGIT                = &H0004      ' decimal digits
%C1_SPACE                = &H0008      ' spacing characters
%C1_PUNCT                = &H0010      ' punctuation characters
%C1_CNTRL                = &H0020      ' control characters
%C1_BLANK                = &H0040      ' blank characters
%C1_XDIGIT               = &H0080      ' other digits
%C1_ALPHA                = &H0100      ' any linguistic character
%C1_DEFINED              = &H0200      ' defined character

'
'  CType 2 Flag Bits.
'
%C2_LEFTTORIGHT          = &H0001      ' left to right
%C2_RIGHTTOLEFT          = &H0002      ' right to left

%C2_EUROPENUMBER         = &H0003      ' European number, digit
%C2_EUROPESEPARATOR      = &H0004      ' European numeric separator
%C2_EUROPETERMINATOR     = &H0005      ' European numeric terminator
%C2_ARABICNUMBER         = &H0006      ' Arabic number
%C2_COMMONSEPARATOR      = &H0007      ' common numeric separator

%C2_BLOCKSEPARATOR       = &H0008      ' block separator
%C2_SEGMENTSEPARATOR     = &H0009      ' segment separator
%C2_WHITESPACE           = &H000A      ' white space
%C2_OTHERNEUTRAL         = &H000B      ' other neutrals

%C2_NOTAPPLICABLE        = &H0000      ' no implicit directionality

'
'  CType 3 Flag Bits.
'
%C3_NONSPACING           = &H0001      ' nonspacing character
%C3_DIACRITIC            = &H0002      ' diacritic mark
%C3_VOWELMARK            = &H0004      ' vowel mark
%C3_SYMBOL               = &H0008      ' symbols

%C3_KATAKANA             = &H0010      ' katakana character
%C3_HIRAGANA             = &H0020      ' hiragana character
%C3_HALFWIDTH            = &H0040      ' half width character
%C3_FULLWIDTH            = &H0080      ' full width character
%C3_IDEOGRAPH            = &H0100      ' ideographic character
%C3_KASHIDA              = &H0200      ' Arabic kashida character
%C3_LEXICAL              = &H0400      ' lexical character
%C3_HIGHSURROGATE        = &H0800      ' high surrogate code unit
%C3_LOWSURROGATE         = &H1000      ' low surrogate code unit

%C3_ALPHA                = &H8000??    ' any linguistic char (C1_ALPHA)

%C3_NOTAPPLICABLE        = &H0000      ' ctype 3 is not applicable


'
'  String Flags.
'
%NORM_IGNORECASE         = &H00000001  ' ignore case
%NORM_IGNORENONSPACE     = &H00000002  ' ignore nonspacing chars
%NORM_IGNORESYMBOLS      = &H00000004  ' ignore symbols

%LINGUISTIC_IGNORECASE   = &H00000010  ' linguistically appropriate 'ignore case'
%LINGUISTIC_IGNOREDIACRITIC = &H00000020  ' linguistically appropriate 'ignore nonspace'

%NORM_IGNOREKANATYPE     = &H00010000  ' ignore kanatype
%NORM_IGNOREWIDTH        = &H00020000  ' ignore width
%NORM_LINGUISTIC_CASING  = &H08000000  ' use linguistic rules for casing


'
'  Locale Independent Mapping Flags.
'
%MAP_FOLDCZONE           = &H00000010  ' fold compatibility zone chars
%MAP_PRECOMPOSED         = &H00000020  ' convert to precomposed chars
%MAP_COMPOSITE           = &H00000040  ' convert to composite chars
%MAP_FOLDDIGITS          = &H00000080  ' all digits to ASCII 0-9

#IF (%WINVER >= &H0500)
%MAP_EXPAND_LIGATURES    = &H00002000  ' expand all ligatures
#ENDIF ' WINVER >= &H0500

'
'  Locale Dependent Mapping Flags.
'
%LCMAP_LOWERCASE           = &H00000100  ' lower case letters
%LCMAP_UPPERCASE           = &H00000200  ' upper case letters
#IF (%WINVER >= %WIN32_WINNT_WIN7)
%LCMAP_TITLECASE           = &H00000300  ' Title Case Letters
#ENDIF  ' (%WINVER >= %WIN32_WINNT_WIN7)

%LCMAP_SORTKEY             = &H00000400  ' WC sort key (normalize)
%LCMAP_BYTEREV             = &H00000800  ' byte reversal

%LCMAP_HIRAGANA            = &H00100000  ' map katakana to hiragana
%LCMAP_KATAKANA            = &H00200000  ' map hiragana to katakana
%LCMAP_HALFWIDTH           = &H00400000  ' map double byte to single byte
%LCMAP_FULLWIDTH           = &H00800000  ' map single byte to double byte

%LCMAP_LINGUISTIC_CASING   = &H01000000  ' use linguistic rules for casing

%LCMAP_SIMPLIFIED_CHINESE  = &H02000000  ' map traditional chinese to simplified chinese
%LCMAP_TRADITIONAL_CHINESE = &H04000000  ' map simplified chinese to traditional chinese


'
'  Search Flags
'
%FIND_STARTSWITH           = &H00100000  ' see if value is at the beginning of source
%FIND_ENDSWITH             = &H00200000  ' see if value is at the end of source
%FIND_FROMSTART            = &H00400000  ' look for value in source, starting at the beginning
%FIND_FROMEND              = &H00800000  ' look for value in source, starting at the end


'
'  Language Group Enumeration Flags.
'
%LGRPID_INSTALLED          = &H00000001  ' installed language group ids
%LGRPID_SUPPORTED          = &H00000002  ' supported language group ids


'
'  Locale Enumeration Flags.
'
%LCID_INSTALLED            = &H00000001  ' installed locale ids
%LCID_SUPPORTED            = &H00000002  ' supported locale ids
%LCID_ALTERNATE_SORTS      = &H00000004  ' alternate sort locale ids


#IF (%WINVER >= %WIN32_WINNT_VISTA)
'
'  Named based enumeration flags.
'
%LOCALE_ALL                = 0            ' enumerate all named based locales
%LOCALE_WINDOWS            = &H00000001   ' shipped locales and/or replacements for them
%LOCALE_SUPPLEMENTAL       = &H00000002   ' supplemental locales only
%LOCALE_ALTERNATE_SORTS    = &H00000004   ' alternate sort locales
%LOCALE_REPLACEMENT        = &H00000008   ' replacement locales only (supplemental - custom)
#ENDIF ' (%WINVER >= %WIN32_WINNT_VISTA)
#IF (%WINVER >= %WIN32_WINNT_WIN7)
%LOCALE_NEUTRALDATA        = &H00000010   ' Locales that are "neutral" (language only, region data is default)
%LOCALE_SPECIFICDATA       = &H00000020   ' Locales that contain language and region data
#ENDIF  ' (%WINVER >= %WIN32_WINNT_WIN7)

'
'  Code Page Enumeration Flags.
'
%CP_INSTALLED              = &H00000001  ' installed code page ids
%CP_SUPPORTED              = &H00000002  ' supported code page ids


'
'  Sorting Flags.
'
'    WORD Sort:    culturally correct sort
'                  hyphen and apostrophe are special cased
'                  example: "coop" and "co-op" will sort together in a list
'
'                        co_op     <-------  underscore (symbol)
'                        coat
'                        comb
'                        coop
'                        co-op     <-------  hyphen (punctuation)
'                        cork
'                        went
'                        were
'                        we're     <-------  apostrophe (punctuation)
'
'
'    STRING Sort:  hyphen and apostrophe will sort with all other symbols
'
'                        co-op     <-------  hyphen (punctuation)
'                        co_op     <-------  underscore (symbol)
'                        coat
'                        comb
'                        coop
'                        cork
'                        we're     <-------  apostrophe (punctuation)
'                        went
'                        were
'
%SORT_STRINGSORT          = &H00001000  ' use string sort method

'  Sort digits as numbers (ie: 2 comes before 10)
#IF (%WINVER >= %WIN32_WINNT_WIN7)
%SORT_DIGITSASNUMBERS      = &H00000008  ' use digits as numbers sort method
#ENDIF ' (%WINVER >= %WIN32_WINNT_WIN7)


'
'  Compare String Return Values.
'
%CSTR_LESS_THAN          = 1           ' string 1 less than string 2
%CSTR_EQUAL              = 2           ' string 1 equal to string 2
%CSTR_GREATER_THAN       = 3           ' string 1 greater than string 2


'
'  Code Page Default Values.
'
%CP_ACP                  = 0           ' default to ANSI code page
%CP_OEMCP                = 1           ' default to OEM  code page
%CP_MACCP                = 2           ' default to MAC  code page
%CP_THREAD_ACP           = 3           ' current thread's ANSI code page
%CP_SYMBOL               = 42          ' SYMBOL translations

%CP_UTF7                 = 65000       ' UTF-7 translation
%CP_UTF8                 = 65001       ' UTF-8 translation


'
'  Country/Region Codes.
'
%CTRY_DEFAULT            = 0

%CTRY_ALBANIA            = 355         ' Albania
%CTRY_ALGERIA            = 213         ' Algeria
%CTRY_ARGENTINA          = 54          ' Argentina
%CTRY_ARMENIA            = 374         ' Armenia
%CTRY_AUSTRALIA          = 61          ' Australia
%CTRY_AUSTRIA            = 43          ' Austria
%CTRY_AZERBAIJAN         = 994         ' Azerbaijan
%CTRY_BAHRAIN            = 973         ' Bahrain
%CTRY_BELARUS            = 375         ' Belarus
%CTRY_BELGIUM            = 32          ' Belgium
%CTRY_BELIZE             = 501         ' Belize
%CTRY_BOLIVIA            = 591         ' Bolivia
%CTRY_BRAZIL             = 55          ' Brazil
%CTRY_BRUNEI_DARUSSALAM  = 673         ' Brunei Darussalam
%CTRY_BULGARIA           = 359         ' Bulgaria
%CTRY_CANADA             = 2           ' Canada
%CTRY_CARIBBEAN          = 1           ' Caribbean
%CTRY_CHILE              = 56          ' Chile
%CTRY_COLOMBIA           = 57          ' Colombia
%CTRY_COSTA_RICA         = 506         ' Costa Rica
%CTRY_CROATIA            = 385         ' Croatia
%CTRY_CZECH              = 420         ' Czech Republic
%CTRY_DENMARK            = 45          ' Denmark
%CTRY_DOMINICAN_REPUBLIC = 1           ' Dominican Republic
%CTRY_ECUADOR            = 593         ' Ecuador
%CTRY_EGYPT              = 20          ' Egypt
%CTRY_EL_SALVADOR        = 503         ' El Salvador
%CTRY_ESTONIA            = 372         ' Estonia
%CTRY_FAEROE_ISLANDS     = 298         ' Faeroe Islands
%CTRY_FINLAND            = 358         ' Finland
%CTRY_FRANCE             = 33          ' France
%CTRY_GEORGIA            = 995         ' Georgia
%CTRY_GERMANY            = 49          ' Germany
%CTRY_GREECE             = 30          ' Greece
%CTRY_GUATEMALA          = 502         ' Guatemala
%CTRY_HONDURAS           = 504         ' Honduras
%CTRY_HONG_KONG          = 852         ' Hong Kong S.A.R., P.R.C.
%CTRY_HUNGARY            = 36          ' Hungary
%CTRY_ICELAND            = 354         ' Iceland
%CTRY_INDIA              = 91          ' India
%CTRY_INDONESIA          = 62          ' Indonesia
%CTRY_IRAN               = 981         ' Iran
%CTRY_IRAQ               = 964         ' Iraq
%CTRY_IRELAND            = 353         ' Ireland
%CTRY_ISRAEL             = 972         ' Israel
%CTRY_ITALY              = 39          ' Italy
%CTRY_JAMAICA            = 1           ' Jamaica
%CTRY_JAPAN              = 81          ' Japan
%CTRY_JORDAN             = 962         ' Jordan
%CTRY_KAZAKSTAN          = 7           ' Kazakstan
%CTRY_KENYA              = 254         ' Kenya
%CTRY_KUWAIT             = 965         ' Kuwait
%CTRY_KYRGYZSTAN         = 996         ' Kyrgyzstan
%CTRY_LATVIA             = 371         ' Latvia
%CTRY_LEBANON            = 961         ' Lebanon
%CTRY_LIBYA              = 218         ' Libya
%CTRY_LIECHTENSTEIN      = 41          ' Liechtenstein
%CTRY_LITHUANIA          = 370         ' Lithuania
%CTRY_LUXEMBOURG         = 352         ' Luxembourg
%CTRY_MACAU              = 853         ' Macau S.A.R., PRC
%CTRY_MACEDONIA          = 389         ' Former Yugoslav Republic of Macedonia
%CTRY_MALAYSIA           = 60          ' Malaysia
%CTRY_MALDIVES           = 960         ' Maldives
%CTRY_MEXICO             = 52          ' Mexico
%CTRY_MONACO             = 33          ' Principality of Monaco
%CTRY_MONGOLIA           = 976         ' Mongolia
%CTRY_MOROCCO            = 212         ' Morocco
%CTRY_NETHERLANDS        = 31          ' Netherlands
%CTRY_NEW_ZEALAND        = 64          ' New Zealand
%CTRY_NICARAGUA          = 505         ' Nicaragua
%CTRY_NORWAY             = 47          ' Norway
%CTRY_OMAN               = 968         ' Oman
%CTRY_PAKISTAN           = 92          ' Islamic Republic of Pakistan
%CTRY_PANAMA             = 507         ' Panama
%CTRY_PARAGUAY           = 595         ' Paraguay
%CTRY_PERU               = 51          ' Peru
%CTRY_PHILIPPINES        = 63          ' Republic of the Philippines
%CTRY_POLAND             = 48          ' Poland
%CTRY_PORTUGAL           = 351         ' Portugal
%CTRY_PRCHINA            = 86          ' People's Republic of China
%CTRY_PUERTO_RICO        = 1           ' Puerto Rico
%CTRY_QATAR              = 974         ' Qatar
%CTRY_ROMANIA            = 40          ' Romania
%CTRY_RUSSIA             = 7           ' Russia
%CTRY_SAUDI_ARABIA       = 966         ' Saudi Arabia
%CTRY_SERBIA             = 381         ' Serbia
%CTRY_SINGAPORE          = 65          ' Singapore
%CTRY_SLOVAK             = 421         ' Slovak Republic
%CTRY_SLOVENIA           = 386         ' Slovenia
%CTRY_SOUTH_AFRICA       = 27          ' South Africa
%CTRY_SOUTH_KOREA        = 82          ' Korea
%CTRY_SPAIN              = 34          ' Spain
%CTRY_SWEDEN             = 46          ' Sweden
%CTRY_SWITZERLAND        = 41          ' Switzerland
%CTRY_SYRIA              = 963         ' Syria
%CTRY_TAIWAN             = 886         ' Taiwan
%CTRY_TATARSTAN          = 7           ' Tatarstan
%CTRY_THAILAND           = 66          ' Thailand
%CTRY_TRINIDAD_Y_TOBAGO  = 1           ' Trinidad y Tobago
%CTRY_TUNISIA            = 216         ' Tunisia
%CTRY_TURKEY             = 90          ' Turkey
%CTRY_UAE                = 971         ' U.A.E.
%CTRY_UKRAINE            = 380         ' Ukraine
%CTRY_UNITED_KINGDOM     = 44          ' United Kingdom
%CTRY_UNITED_STATES      = 1           ' United States
%CTRY_URUGUAY            = 598         ' Uruguay
%CTRY_UZBEKISTAN         = 7           ' Uzbekistan
%CTRY_VENEZUELA          = 58          ' Venezuela
%CTRY_VIET_NAM           = 84          ' Viet Nam
%CTRY_YEMEN              = 967         ' Yemen
%CTRY_ZIMBABWE           = 263         ' Zimbabwe


'
'  Locale Types.
'
'  These types are used for the GetLocaleInfo NLS API routine.
'  Some of these types are also used for the SetLocaleInfo NLS API routine.
'

'
'  The following LCTypes may be used in combination with any other LCTypes.
'
'    LOCALE_NOUSEROVERRIDE is also used in GetTimeFormat and
'    GetDateFormat.
'
'    LOCALE_USE_CP_ACP is used in many of the A (Ansi) apis that need
'    to do string translation.
'
'    LOCALE_RETURN_NUMBER will return the result from GetLocaleInfo as a
'    number instead of a string.  This flag is only valid for the LCTypes
'    beginning with LOCALE_I.
'
%LOCALE_NOUSEROVERRIDE       = &H80000000??? ' do not use user overrides
%LOCALE_USE_CP_ACP           = &H40000000    ' use the system ACP

#IF (%WINVER >= &H0400)
%LOCALE_RETURN_NUMBER        = &H20000000    ' return number instead of string
#ENDIF ' WINVER >= &H0400

#IF (%WINVER >= %WIN32_WINNT_WIN7)
%LOCALE_RETURN_GENITIVE_NAMES = &H10000000   ' Flag to return the Genitive forms of month names
%LOCALE_ALLOW_NEUTRAL_NAMES   = &H08000000   ' Flag to allow returning neutral names/lcids for name conversion
#ENDIF  ' (%WINVER >= %WIN32_WINNT_WIN7)


'
'  The following LCTypes are mutually exclusive in that they may NOT
'  be used in combination with each other.
'

'
' These are the various forms of the name of the locale:
'
%LOCALE_SLOCALIZEDDISPLAYNAME  = &H00000002   ' localized name of locale, eg "German (Germany)" in UI language
#IF (%WINVER >= %WIN32_WINNT_WIN7)
%LOCALE_SENGLISHDISPLAYNAME    = &H00000072   ' Display name (language + country usually) in English, eg "German (Germany)"
%LOCALE_SNATIVEDISPLAYNAME     = &H00000073   ' Display name in native locale language, eg "Deutsch (Deutschland)
#ENDIF '(%WINVER >= %WIN32_WINNT_WIN7)

#IF (%WINVER >= %WIN32_WINNT_VISTA)
%LOCALE_SLOCALIZEDLANGUAGENAME = &H0000006f   ' Language Display Name for a language, eg "German" in UI language
#ENDIF '(%WINVER >= %WIN32_WINNT_VISTA)
%LOCALE_SENGLISHLANGUAGENAME   = &H00001001   ' English name of language, eg "German"
%LOCALE_SNATIVELANGUAGENAME    = &H00000004   ' native name of language, eg "Deutsch"

%LOCALE_SLOCALIZEDCOUNTRYNAME  = &H00000006   ' localized name of country, eg "Germany" in UI language
%LOCALE_SENGLISHCOUNTRYNAME    = &H00001002   ' English name of country, eg "Germany"
%LOCALE_SNATIVECOUNTRYNAME     = &H00000008   ' native name of country, eg "Deutschland"

'
' Legacy labels for the locale name values
'
%LOCALE_SLANGUAGE              = &H00000002   ' localized name of locale, eg "German (Germany)" in UI language
#IF (%WINVER >= %WIN32_WINNT_VISTA)
%LOCALE_SLANGDISPLAYNAME       = &H0000006f   ' Language Display Name for a language, eg "German" in UI language
#ENDIF  ' (%WINVER >= %WIN32_WINNT_VISTA)
%LOCALE_SENGLANGUAGE           = &H00001001   ' English name of language, eg "German"
%LOCALE_SNATIVELANGNAME        = &H00000004   ' native name of language, eg "Deutsch"
%LOCALE_SCOUNTRY               = &H00000006   ' localized name of country, eg "Germany" in UI language
%LOCALE_SENGCOUNTRY            = &H00001002   ' English name of country, eg "Germany"
%LOCALE_SNATIVECTRYNAME        = &H00000008   ' native name of country, eg "Deutschland"

' Additional LCTypes
%LOCALE_ILANGUAGE              = &H00000001   ' language id, LOCALE_SNAME preferred

%LOCALE_SABBREVLANGNAME        = &H00000003   ' arbitrary abbreviated language name, LOCALE_SISO639LANGNAME preferred

%LOCALE_ICOUNTRY               = &H00000005   ' country code, eg 1, LOCALE_SISO3166CTRYNAME may be more useful.
%LOCALE_SABBREVCTRYNAME        = &H00000007   ' arbitrary abbreviated country name, LOCALE_SISO3166CTRYNAME preferred
%LOCALE_IGEOID                = &H0000005B   ' geographical location id

%LOCALE_IDEFAULTLANGUAGE      = &H00000009   ' default language id
%LOCALE_IDEFAULTCOUNTRY       = &H0000000A   ' default country code
%LOCALE_IDEFAULTCODEPAGE      = &H0000000B   ' default oem code page
%LOCALE_IDEFAULTANSICODEPAGE  = &H00001004   ' default ansi code page
%LOCALE_IDEFAULTMACCODEPAGE   = &H00001011   ' default mac code page

%LOCALE_SLIST                 = &H0000000C   ' list item separator
%LOCALE_IMEASURE              = &H0000000D   ' 0 = metric, 1 = US

%LOCALE_SDECIMAL              = &H0000000E   ' decimal separator
%LOCALE_STHOUSAND             = &H0000000F   ' thousand separator
%LOCALE_SGROUPING             = &H00000010   ' digit grouping
%LOCALE_IDIGITS               = &H00000011   ' number of fractional digits
%LOCALE_ILZERO                = &H00000012   ' leading zeros for decimal
%LOCALE_INEGNUMBER            = &H00001010   ' negative number mode
%LOCALE_SNATIVEDIGITS         = &H00000013   ' native digits for 0-9

%LOCALE_SCURRENCY             = &H00000014   ' local monetary symbol
%LOCALE_SINTLSYMBOL           = &H00000015   ' intl monetary symbol
%LOCALE_SMONDECIMALSEP        = &H00000016   ' monetary decimal separator
%LOCALE_SMONTHOUSANDSEP       = &H00000017   ' monetary thousand separator
%LOCALE_SMONGROUPING          = &H00000018   ' monetary grouping
%LOCALE_ICURRDIGITS           = &H00000019   ' # local monetary digits
%LOCALE_IINTLCURRDIGITS       = &H0000001A   ' # intl monetary digits
%LOCALE_ICURRENCY             = &H0000001B   ' positive currency mode
%LOCALE_INEGCURR              = &H0000001C   ' negative currency mode

%LOCALE_SDATE                 = &H0000001D   ' date separator (derived from LOCALE_SSHORTDATE, use that instead)
%LOCALE_STIME                 = &H0000001E   ' time separator (derived from LOCALE_STIMEFORMAT, use that instead)
%LOCALE_SSHORTDATE            = &H0000001F   ' short date format string
%LOCALE_SLONGDATE             = &H00000020   ' long date format string
%LOCALE_STIMEFORMAT           = &H00001003   ' time format string
%LOCALE_IDATE                 = &H00000021   ' short date format ordering (derived from LOCALE_SSHORTDATE, use that instead)
%LOCALE_ILDATE                = &H00000022   ' long date format ordering (derived from LOCALE_SLONGDATE, use that instead)
%LOCALE_ITIME                 = &H00000023   ' time format specifier (derived from LOCALE_STIMEFORMAT, use that instead)
%LOCALE_ITIMEMARKPOSN         = &H00001005   ' time marker position (derived from LOCALE_STIMEFORMAT, use that instead)
%LOCALE_ICENTURY              = &H00000024   ' century format specifier (short date, LOCALE_SSHORTDATE is preferred)
%LOCALE_ITLZERO               = &H00000025   ' leading zeros in time field (derived from LOCALE_STIMEFORMAT, use that instead)
%LOCALE_IDAYLZERO             = &H00000026   ' leading zeros in day field (short date, LOCALE_SSHORTDATE is preferred)
%LOCALE_IMONLZERO             = &H00000027   ' leading zeros in month field (short date, LOCALE_SSHORTDATE is preferred)
%LOCALE_S1159                 = &H00000028   ' AM designator
%LOCALE_S2359                 = &H00000029   ' PM designator

%LOCALE_ICALENDARTYPE         = &H00001009   ' type of calendar specifier
%LOCALE_IOPTIONALCALENDAR     = &H0000100B   ' additional calendar types specifier
%LOCALE_IFIRSTDAYOFWEEK       = &H0000100C   ' first day of week specifier
%LOCALE_IFIRSTWEEKOFYEAR      = &H0000100D   ' first week of year specifier

%LOCALE_SDAYNAME1             = &H0000002A   ' long name for Monday
%LOCALE_SDAYNAME2             = &H0000002B   ' long name for Tuesday
%LOCALE_SDAYNAME3             = &H0000002C   ' long name for Wednesday
%LOCALE_SDAYNAME4             = &H0000002D   ' long name for Thursday
%LOCALE_SDAYNAME5             = &H0000002E   ' long name for Friday
%LOCALE_SDAYNAME6             = &H0000002F   ' long name for Saturday
%LOCALE_SDAYNAME7             = &H00000030   ' long name for Sunday
%LOCALE_SABBREVDAYNAME1       = &H00000031   ' abbreviated name for Monday
%LOCALE_SABBREVDAYNAME2       = &H00000032   ' abbreviated name for Tuesday
%LOCALE_SABBREVDAYNAME3       = &H00000033   ' abbreviated name for Wednesday
%LOCALE_SABBREVDAYNAME4       = &H00000034   ' abbreviated name for Thursday
%LOCALE_SABBREVDAYNAME5       = &H00000035   ' abbreviated name for Friday
%LOCALE_SABBREVDAYNAME6       = &H00000036   ' abbreviated name for Saturday
%LOCALE_SABBREVDAYNAME7       = &H00000037   ' abbreviated name for Sunday
%LOCALE_SMONTHNAME1           = &H00000038   ' long name for January
%LOCALE_SMONTHNAME2           = &H00000039   ' long name for February
%LOCALE_SMONTHNAME3           = &H0000003A   ' long name for March
%LOCALE_SMONTHNAME4           = &H0000003B   ' long name for April
%LOCALE_SMONTHNAME5           = &H0000003C   ' long name for May
%LOCALE_SMONTHNAME6           = &H0000003D   ' long name for June
%LOCALE_SMONTHNAME7           = &H0000003E   ' long name for July
%LOCALE_SMONTHNAME8           = &H0000003F   ' long name for August
%LOCALE_SMONTHNAME9           = &H00000040   ' long name for September
%LOCALE_SMONTHNAME10          = &H00000041   ' long name for October
%LOCALE_SMONTHNAME11          = &H00000042   ' long name for November
%LOCALE_SMONTHNAME12          = &H00000043   ' long name for December
%LOCALE_SMONTHNAME13          = &H0000100E   ' long name for 13th month (if exists)
%LOCALE_SABBREVMONTHNAME1     = &H00000044   ' abbreviated name for January
%LOCALE_SABBREVMONTHNAME2     = &H00000045   ' abbreviated name for February
%LOCALE_SABBREVMONTHNAME3     = &H00000046   ' abbreviated name for March
%LOCALE_SABBREVMONTHNAME4     = &H00000047   ' abbreviated name for April
%LOCALE_SABBREVMONTHNAME5     = &H00000048   ' abbreviated name for May
%LOCALE_SABBREVMONTHNAME6     = &H00000049   ' abbreviated name for June
%LOCALE_SABBREVMONTHNAME7     = &H0000004A   ' abbreviated name for July
%LOCALE_SABBREVMONTHNAME8     = &H0000004B   ' abbreviated name for August
%LOCALE_SABBREVMONTHNAME9     = &H0000004C   ' abbreviated name for September
%LOCALE_SABBREVMONTHNAME10    = &H0000004D   ' abbreviated name for October
%LOCALE_SABBREVMONTHNAME11    = &H0000004E   ' abbreviated name for November
%LOCALE_SABBREVMONTHNAME12    = &H0000004F   ' abbreviated name for December
%LOCALE_SABBREVMONTHNAME13    = &H0000100F   ' abbreviated name for 13th month (if exists)

%LOCALE_SPOSITIVESIGN         = &H00000050   ' positive sign
%LOCALE_SNEGATIVESIGN         = &H00000051   ' negative sign
%LOCALE_IPOSSIGNPOSN          = &H00000052   ' positive sign position (derived from INEGCURR)
%LOCALE_INEGSIGNPOSN          = &H00000053   ' negative sign position (derived from INEGCURR)
%LOCALE_IPOSSYMPRECEDES       = &H00000054   ' mon sym precedes pos amt (derived from ICURRENCY)
%LOCALE_IPOSSEPBYSPACE        = &H00000055   ' mon sym sep by space from pos amt (derived from ICURRENCY)
%LOCALE_INEGSYMPRECEDES       = &H00000056   ' mon sym precedes neg amt (derived from INEGCURR)
%LOCALE_INEGSEPBYSPACE        = &H00000057   ' mon sym sep by space from neg amt (derived from INEGCURR)

#IF (%WINVER >= &H0400)
%LOCALE_FONTSIGNATURE         = &H00000058   ' font signature
%LOCALE_SISO639LANGNAME       = &H00000059   ' ISO abbreviated language name
%LOCALE_SISO3166CTRYNAME      = &H0000005A   ' ISO abbreviated country name
#ENDIF ' %WINVER >= &H0400

#IF (%WINVER >= &H0500)
%LOCALE_IDEFAULTEBCDICCODEPAGE = &H00001012   ' default ebcdic code page
%LOCALE_IPAPERSIZE             = &H0000100A   ' 1 = letter, 5 = legal, 8 = a3, 9 = a4
%LOCALE_SENGCURRNAME           = &H00001007   ' english name of currency
%LOCALE_SNATIVECURRNAME        = &H00001008   ' native name of currency
%LOCALE_SYEARMONTH             = &H00001006   ' year month format string
%LOCALE_SSORTNAME              = &H00001013   ' sort name
%LOCALE_IDIGITSUBSTITUTION     = &H00001014   ' 0 = context, 1 = none, 2 = national

#ENDIF ' %WINVER >= &H0500

#IF (%WINVER >= &H0600)
%LOCALE_SNAME                  = &H0000005c   ' locale name (ie: en-us)
%LOCALE_SDURATION              = &H0000005d   ' time duration format
%LOCALE_SKEYBOARDSTOINSTALL    = &H0000005e
%LOCALE_SSHORTESTDAYNAME1      = &H00000060   ' Shortest day name for Monday
%LOCALE_SSHORTESTDAYNAME2      = &H00000061   ' Shortest day name for Tuesday
%LOCALE_SSHORTESTDAYNAME3      = &H00000062   ' Shortest day name for Wednesday
%LOCALE_SSHORTESTDAYNAME4      = &H00000063   ' Shortest day name for Thursday
%LOCALE_SSHORTESTDAYNAME5      = &H00000064   ' Shortest day name for Friday
%LOCALE_SSHORTESTDAYNAME6      = &H00000065   ' Shortest day name for Saturday
%LOCALE_SSHORTESTDAYNAME7      = &H00000066   ' Shortest day name for Sunday
%LOCALE_SISO639LANGNAME2       = &H00000067   ' 3 character ISO abbreviated language name
%LOCALE_SISO3166CTRYNAME2      = &H00000068   ' 3 character ISO country name
%LOCALE_SNAN                   = &H00000069   ' Not a Number
%LOCALE_SPOSINFINITY           = &H0000006a   ' + Infinity
%LOCALE_SNEGINFINITY           = &H0000006b   ' - Infinity
%LOCALE_SSCRIPTS               = &H0000006c   ' Typical scripts in the locale
%LOCALE_SPARENT                = &H0000006d   ' Fallback name for resources
%LOCALE_SCONSOLEFALLBACKNAME   = &H0000006e   ' Fallback name for within the console
#ENDIF ' (%WINVER >= &H0600)

#IF (%WINVER >= %WIN32_WINNT_WIN7)
%LOCALE_IREADINGLAYOUT         = &H00000070   ' Returns one of the following 4 reading layout values:
                                              ' 0 - Left to right (eg en-US)
                                              ' 1 - Right to left (eg arabic locales)
                                              ' 2 - Vertical top to bottom with columns to the left and also left to right (ja-JP locales)
                                              ' 3 - Vertical top to bottom with columns proceeding to the right
%LOCALE_INEUTRAL               = &H00000071   ' Returns 0 for specific cultures, 1 for neutral cultures.
%LOCALE_INEGATIVEPERCENT       = &H00000074   ' Returns 0-11 for the negative percent format
%LOCALE_IPOSITIVEPERCENT       = &H00000075   ' Returns 0-3 for the positive percent formatIPOSITIVEPERCENT
%LOCALE_SPERCENT               = &H00000076   ' Returns the percent symbol
%LOCALE_SPERMILLE              = &H00000077   ' Returns the permille (U+2030) symbol
%LOCALE_SMONTHDAY              = &H00000078   ' Returns the preferred month/day format
%LOCALE_SSHORTTIME             = &H00000079   ' Returns the preferred short time format (ie: no seconds, just h:mm)
%LOCALE_SOPENTYPELANGUAGETAG   = &H0000007a   ' Open type language tag, eg: "latn" or "dflt"
%LOCALE_SSORTLOCALE            = &H0000007b   ' Name of locale to use for sorting/collation/casing behavior.
#ENDIF  ' (%WINVER >= %WIN32_WINNT_WIN7)


'
'  Time Flags for GetTimeFormat.
'
%TIME_NOMINUTESORSECONDS   = &H00000001  ' do not use minutes or seconds
%TIME_NOSECONDS            = &H00000002  ' do not use seconds
%TIME_NOTIMEMARKER         = &H00000004  ' do not use time marker
%TIME_FORCE24HOURFORMAT    = &H00000008  ' always use 24 hour format


'
'  Date Flags for GetDateFormat.
'
%DATE_SHORTDATE            = &H00000001  ' use short date picture
%DATE_LONGDATE             = &H00000002  ' use long date picture
%DATE_USE_ALT_CALENDAR     = &H00000004  ' use alternate calendar (if any)

#IF (%WINVER >= &H0500)
%DATE_YEARMONTH            = &H00000008  ' use year month picture
%DATE_LTRREADING           = &H00000010  ' add marks for left to right reading order layout
%DATE_RTLREADING           = &H00000020  ' add marks for right to left reading order layout
#ENDIF ' %WINVER >= &H0500

#IF (%WINVER >= %WIN32_WINNT_WIN7)
%DATE_AUTOLAYOUT           = &H00000040  ' add appropriate marks for left-to-right or right-to-left reading order layout
#ENDIF  ' (%WINVER >= %WIN32_WINNT_WIN7)


'
'  Calendar Types.
'
'  These types are used for the EnumCalendarInfo and GetCalendarInfo
'  NLS API routines.
'  Some of these types are also used for the SetCalendarInfo NLS API
'  routine.
'

'
'  The following CalTypes may be used in combination with any other CalTypes.
'
'    CAL_NOUSEROVERRIDE
'
'    CAL_USE_CP_ACP is used in the A (Ansi) apis that need to do string
'    translation.
'
'    CAL_RETURN_NUMBER will return the result from GetCalendarInfo as a
'    number instead of a string.  This flag is only valid for the CalTypes
'    beginning with CAL_I.
'
#IF (%WINVER >= &H0500)
%CAL_NOUSEROVERRIDE     = %LOCALE_NOUSEROVERRIDE  ' do not use user overrides
%CAL_USE_CP_ACP         = %LOCALE_USE_CP_ACP      ' use the system ACP
%CAL_RETURN_NUMBER      = %LOCALE_RETURN_NUMBER   ' return number instead of string
#ENDIF ' %WINVER >= &H0500


#IF (%WINVER >= %WIN32_WINNT_WIN7)
%CAL_RETURN_GENITIVE_NAMES = %LOCALE_RETURN_GENITIVE_NAMES  ' return genitive forms of month names
#ENDIF  ' winver >= windows 7

'
'  The following CalTypes are mutually exclusive in that they may NOT
'  be used in combination with each other.
'
%CAL_ICALINTVALUE        = &H00000001  ' calendar type
%CAL_SCALNAME            = &H00000002  ' native name of calendar
%CAL_IYEAROFFSETRANGE    = &H00000003  ' starting years of eras
%CAL_SERASTRING          = &H00000004  ' era name for IYearOffsetRanges
%CAL_SSHORTDATE          = &H00000005  ' short date format string
%CAL_SLONGDATE           = &H00000006  ' long date format string
%CAL_SDAYNAME1           = &H00000007  ' native name for Monday
%CAL_SDAYNAME2           = &H00000008  ' native name for Tuesday
%CAL_SDAYNAME3           = &H00000009  ' native name for Wednesday
%CAL_SDAYNAME4           = &H0000000a  ' native name for Thursday
%CAL_SDAYNAME5           = &H0000000b  ' native name for Friday
%CAL_SDAYNAME6           = &H0000000c  ' native name for Saturday
%CAL_SDAYNAME7           = &H0000000d  ' native name for Sunday
%CAL_SABBREVDAYNAME1     = &H0000000e  ' abbreviated name for Monday
%CAL_SABBREVDAYNAME2     = &H0000000f  ' abbreviated name for Tuesday
%CAL_SABBREVDAYNAME3     = &H00000010  ' abbreviated name for Wednesday
%CAL_SABBREVDAYNAME4     = &H00000011  ' abbreviated name for Thursday
%CAL_SABBREVDAYNAME5     = &H00000012  ' abbreviated name for Friday
%CAL_SABBREVDAYNAME6     = &H00000013  ' abbreviated name for Saturday
%CAL_SABBREVDAYNAME7     = &H00000014  ' abbreviated name for Sunday
' Note that in the hebrew calendar the leap month name is always returned as the 7th month
%CAL_SMONTHNAME1         = &H00000015  ' native name for January
%CAL_SMONTHNAME2         = &H00000016  ' native name for February
%CAL_SMONTHNAME3         = &H00000017  ' native name for March
%CAL_SMONTHNAME4         = &H00000018  ' native name for April
%CAL_SMONTHNAME5         = &H00000019  ' native name for May
%CAL_SMONTHNAME6         = &H0000001a  ' native name for June
%CAL_SMONTHNAME7         = &H0000001b  ' native name for July
%CAL_SMONTHNAME8         = &H0000001c  ' native name for August
%CAL_SMONTHNAME9         = &H0000001d  ' native name for September
%CAL_SMONTHNAME10        = &H0000001e  ' native name for October
%CAL_SMONTHNAME11        = &H0000001f  ' native name for November
%CAL_SMONTHNAME12        = &H00000020  ' native name for December
%CAL_SMONTHNAME13        = &H00000021  ' native name for 13th month (if any)
%CAL_SABBREVMONTHNAME1   = &H00000022  ' abbreviated name for January
%CAL_SABBREVMONTHNAME2   = &H00000023  ' abbreviated name for February
%CAL_SABBREVMONTHNAME3   = &H00000024  ' abbreviated name for March
%CAL_SABBREVMONTHNAME4   = &H00000025  ' abbreviated name for April
%CAL_SABBREVMONTHNAME5   = &H00000026  ' abbreviated name for May
%CAL_SABBREVMONTHNAME6   = &H00000027  ' abbreviated name for June
%CAL_SABBREVMONTHNAME7   = &H00000028  ' abbreviated name for July
%CAL_SABBREVMONTHNAME8   = &H00000029  ' abbreviated name for August
%CAL_SABBREVMONTHNAME9   = &H0000002a  ' abbreviated name for September
%CAL_SABBREVMONTHNAME10  = &H0000002b  ' abbreviated name for October
%CAL_SABBREVMONTHNAME11  = &H0000002c  ' abbreviated name for November
%CAL_SABBREVMONTHNAME12  = &H0000002d  ' abbreviated name for December
%CAL_SABBREVMONTHNAME13  = &H0000002e  ' abbreviated name for 13th month (if any)

#IF (%WINVER >= &H0500)
%CAL_SYEARMONTH          = &H0000002f  ' year month format string
%CAL_ITWODIGITYEARMAX    = &H00000030  ' two digit year max
#ENDIF ' %WINVER >= &H0500

#IF (%WINVER >= &H0600)
%CAL_SSHORTESTDAYNAME1   = &H00000031  ' Shortest day name for Monday
%CAL_SSHORTESTDAYNAME2   = &H00000032  ' Shortest day name for Tuesday
%CAL_SSHORTESTDAYNAME3   = &H00000033  ' Shortest day name for Wednesday
%CAL_SSHORTESTDAYNAME4   = &H00000034  ' Shortest day name for Thursday
%CAL_SSHORTESTDAYNAME5   = &H00000035  ' Shortest day name for Friday
%CAL_SSHORTESTDAYNAME6   = &H00000036  ' Shortest day name for Saturday
%CAL_SSHORTESTDAYNAME7   = &H00000037  ' Shortest day name for Sunday
#ENDIF ' (%WINVER >= &H0600)

#IF (%WINVER >= %WIN32_WINNT_WIN7)
%CAL_SMONTHDAY           = &H00000038  ' Month/day format
%CAL_SABBREVERASTRING    = &H00000039  ' Abbreviated era string (eg: AD)
#ENDIF  ' winver >= windows 7


'
'  Calendar Enumeration Value.
'
%ENUM_ALL_CALENDARS      = &Hffffffff  ' enumerate all calendars


'
'  Calendar ID Values.
'
%CAL_GREGORIAN                = 1      ' Gregorian (localized) calendar
%CAL_GREGORIAN_US             = 2      ' Gregorian (U.S.) calendar
%CAL_JAPAN                    = 3      ' Japanese Emperor Era calendar
%CAL_TAIWAN                   = 4      ' Taiwan calendar
%CAL_KOREA                    = 5      ' Korean Tangun Era calendar
%CAL_HIJRI                    = 6      ' Hijri (Arabic Lunar) calendar
%CAL_THAI                     = 7      ' Thai calendar
%CAL_HEBREW                   = 8      ' Hebrew (Lunar) calendar
%CAL_GREGORIAN_ME_FRENCH      = 9      ' Gregorian Middle East French calendar
%CAL_GREGORIAN_ARABIC         = 10     ' Gregorian Arabic calendar
%CAL_GREGORIAN_XLIT_ENGLISH   = 11     ' Gregorian Transliterated English calendar
%CAL_GREGORIAN_XLIT_FRENCH    = 12     ' Gregorian Transliterated French calendar
%CAL_UMALQURA                 = 23     ' UmAlQura Hijri (Arabic Lunar) calendar


'
'  Language Group ID Values.
'
%LGRPID_WESTERN_EUROPE      = &H0001   ' Western Europe & U.S.
%LGRPID_CENTRAL_EUROPE      = &H0002   ' Central Europe
%LGRPID_BALTIC              = &H0003   ' Baltic
%LGRPID_GREEK               = &H0004   ' Greek
%LGRPID_CYRILLIC            = &H0005   ' Cyrillic
%LGRPID_TURKIC              = &H0006   ' Turkic
%LGRPID_TURKISH             = &H0006   ' Turkish
%LGRPID_JAPANESE            = &H0007   ' Japanese
%LGRPID_KOREAN              = &H0008   ' Korean
%LGRPID_TRADITIONAL_CHINESE = &H0009   ' Traditional Chinese
%LGRPID_SIMPLIFIED_CHINESE  = &H000a   ' Simplified Chinese
%LGRPID_THAI                = &H000b   ' Thai
%LGRPID_HEBREW              = &H000c   ' Hebrew
%LGRPID_ARABIC              = &H000d   ' Arabic
%LGRPID_VIETNAMESE          = &H000e   ' Vietnamese
%LGRPID_INDIC               = &H000f   ' Indic
%LGRPID_GEORGIAN            = &H0010   ' Georgian
%LGRPID_ARMENIAN            = &H0011   ' Armenian


#IF (%WINVER >= &H0600)
'
'  MUI function flag values
'
%MUI_LANGUAGE_ID                    = &H4      ' Use traditional language ID convention
%MUI_LANGUAGE_NAME                  = &H8      ' Use ISO language (culture) name convention
%MUI_MERGE_SYSTEM_FALLBACK          = &H10     ' GetThreadPreferredUILanguages merges in parent and base languages
%MUI_MERGE_USER_FALLBACK            = &H20     ' GetThreadPreferredUILanguages merges in user preferred languages
%MUI_UI_FALLBACK                    = %MUI_MERGE_SYSTEM_FALLBACK _
                                   OR %MUI_MERGE_USER_FALLBACK
%MUI_THREAD_LANGUAGES               = &H40     ' GetThreadPreferredUILanguages merges in user preferred languages
%MUI_CONSOLE_FILTER                 = &H100    ' SetThreadPreferredUILanguages takes on console specific behavior
%MUI_COMPLEX_SCRIPT_FILTER          = &H200    ' SetThreadPreferredUILanguages takes on complex script specific behavior
%MUI_RESET_FILTERS                  = &H001    ' Reset MUI_CONSOLE_FILTER and MUI_COMPLEX_SCRIPT_FILTER
%MUI_USER_PREFERRED_UI_LANGUAGES    = &H10     ' GetFileMUIPath returns the MUI files for the languages in the fallback list
%MUI_USE_INSTALLED_LANGUAGES        = &H20     ' GetFileMUIPath returns all the MUI files installed in the machine
%MUI_USE_SEARCH_ALL_LANGUAGES       = &H40     ' GetFileMUIPath returns all the MUI files irrespective of whether language is installed
%MUI_LANG_NEUTRAL_PE_FILE           = &H100    ' GetFileMUIPath returns target file with .mui extension
%MUI_NON_LANG_NEUTRAL_FILE          = &H200    ' GetFileMUIPath returns target file with same name as source
%MUI_MACHINE_LANGUAGE_SETTINGS      = &H400
%MUI_BYPASS_SESSION_BEHAVIOR        = &H80?   'EnumUILanguages,GetFileMUIInfo: includes latest changes in installed languages
%MUI_FILETYPE_NOT_LANGUAGE_NEUTRAL  = &H001   ' GetFileMUIInfo found a non-split resource file
%MUI_FILETYPE_LANGUAGE_NEUTRAL_MAIN = &H002   ' GetFileMUIInfo found a LN main module resource file
%MUI_FILETYPE_LANGUAGE_NEUTRAL_MUI  = &H004   ' GetFileMUIInfo found a LN MUI module resource file
%MUI_QUERY_TYPE                     = &H001   ' GetFileMUIInfo will look for the type of the resource file
%MUI_QUERY_CHECKSUM                 = &H002   ' GetFileMUIInfo will look for the checksum of the resource file
%MUI_QUERY_LANGUAGE_NAME            = &H004   ' GetFileMUIInfo will look for the culture of the resource file
%MUI_QUERY_RESOURCE_TYPES           = &H008   ' GetFileMUIInfo will look for the resource types of the resource file
%MUI_FILEINFO_VERSION               = &H001   ' Version of FILEMUIINFO structure used with GetFileMUIInfo
%MUI_SXS_FALLBACK              = &H00010000   ' SXS

%MUI_FULL_LANGUAGE             = &H01
%MUI_PARTIAL_LANGUAGE          = &H02
%MUI_LIP_LANGUAGE              = &H04
%MUI_LANGUAGE_INSTALLED        = &H20
%MUI_LANGUAGE_LICENSED         = &H40

%MUI_PUBLIC_LANGUAGE_TYPE_FLAGS_MASK = &H67

'
' MUI_CALLBACK_FLAG defines are duplicated in rtlmui.h
'

' [Microsoft never defines %MUI_CALLBACK_FLAG_UPGRADED_INSTALLATION]
'%MUI_CALLBACK_ALL_FLAGS       = %MUI_CALLBACK_FLAG_UPGRADED_INSTALLATION ' OR all other flags when defined.

'
' MUI_CALLBACK_ flags are duplicated in rtlmui.h
'

#ENDIF  ' #IF (%WINVER >= &H0600)

''''''''''''''''''''''''''''''''''''''
'
'  Typedefs
'
'  Define all types for the NLS component here.
'
''''''''''''''''''''''''''''''''''''''

'
'  Language Group ID.
'
'typedef DWORD LGRPID;


'
'  Locale type constant.
'
'typedef DWORD LCTYPE;


'
'  Calendar type constant.
'
'typedef DWORD CALTYPE;


'
'  Calendar ID.
'
'typedef DWORD CALID;


'
'  CP Info.
'

TYPE CPINFO
    MaxCharSize AS DWORD                           ' max length (bytes) of a char
    DefaultChar(%MAX_DEFAULTCHAR - 1) AS BYTE ' default character
    LeadByte(%MAX_LEADBYTES - 1) AS BYTE      ' lead byte ranges
END TYPE

TYPE CPINFOEXA
    MaxCharSize AS DWORD                 ' max length (in bytes) of a char
    DefaultChar(%MAX_DEFAULTCHAR - 1) AS BYTE ' default character (MB)
    LeadByte(%MAX_LEADBYTES - 1) AS BYTE      ' lead byte ranges
    UnicodeDefaultChar AS DWORD          ' default character (Unicode)
    CodePage AS DWORD                    ' code page id
    CodePageName AS ASCIIZ * %MAX_PATH   ' code page name (ANSI?)
END TYPE

TYPE CPINFOEXW
    MaxCharSize AS DWORD                 ' max length (in bytes) of a char
    DefaultChar(%MAX_DEFAULTCHAR - 1) AS BYTE ' default character (MB)
    LeadByte(%MAX_LEADBYTES - 1) AS BYTE      ' lead byte ranges
    UnicodeDefaultChar AS DWORD          ' default character (Unicode)
    CodePage AS DWORD                    ' code page id
    CodePageName AS WSTRINGZ * %MAX_PATH ' code page name (Unicode)
END TYPE

#IF %DEF(%UNICODE)
TYPE CPINFOEX
    CPINFOEXW
END TYPE
#ELSE
TYPE CPINFOEX
    CPINFOEXA
END TYPE
#ENDIF ' UNICODE


'
'  Number format.
'

TYPE NUMBERFMTA
    NumDigits AS DWORD           ' number of decimal digits
    LeadingZero AS DWORD         ' if leading zero in decimal fields
    Grouping AS DWORD            ' group size left of decimal
    lpDecimalSep AS ASCIIZ PTR   ' ptr to decimal separator string
    lpThousandSep AS ASCIIZ PTR  ' ptr to thousand separator string
    NegativeOrder AS DWORD       ' negative number ordering
END TYPE

TYPE NUMBERFMTW
    NumDigits AS DWORD             ' number of decimal digits
    LeadingZero AS DWORD           ' if leading zero in decimal fields
    Grouping AS DWORD              ' group size left of decimal
    lpDecimalSep AS WSTRINGZ PTR   ' ptr to decimal separator string
    lpThousandSep AS WSTRINGZ PTR  ' ptr to thousand separator string
    NegativeOrder AS DWORD         ' negative number ordering
END TYPE

#IF %DEF(%UNICODE)
TYPE NUMBERFMT
    NUMBERFMTW
END TYPE
#ELSE
TYPE NUMBERFMT
    NUMBERFMTA
END TYPE
#ENDIF ' UNICODE


'
'  Currency format.
'

TYPE CURRENCYFMTA
    NumDigits AS DWORD             ' number of decimal digits
    LeadingZero AS DWORD           ' if leading zero in decimal fields
    Grouping AS DWORD              ' group size left of decimal
    lpDecimalSep AS ASCIIZ PTR     ' ptr to decimal separator string
    lpThousandSep AS ASCIIZ PTR    ' ptr to thousand separator string
    NegativeOrder AS DWORD         ' negative currency ordering
    PositiveOrder AS DWORD         ' positive currency ordering
    lpCurrencySymbol AS ASCIIZ PTR ' ptr to currency symbol string
END TYPE

TYPE CURRENCYFMTW
    NumDigits AS DWORD               ' number of decimal digits
    LeadingZero AS DWORD             ' if leading zero in decimal fields
    Grouping AS DWORD                ' group size left of decimal
    lpDecimalSep AS WSTRINGZ PTR     ' ptr to decimal separator string
    lpThousandSep AS WSTRINGZ PTR    ' ptr to thousand separator string
    NegativeOrder AS DWORD           ' negative currency ordering
    PositiveOrder AS DWORD           ' positive currency ordering
    lpCurrencySymbol AS WSTRINGZ PTR ' ptr to currency symbol string
END TYPE

#IF %DEF(%UNICODE)
TYPE CURRENCYFMT
    CURRENCYFMTW
END TYPE
#ELSE
TYPE CURRENCYFMT
    CURRENCYFMTA
END TYPE
#ENDIF ' UNICODE

'
'  NLS function capabilities
'

MACRO SYSNLS_FUNCTION_enum=DWORD
ENUM SYSNLS_FUNCTION SINGULAR
    COMPARE_STRING    =  &H0001
END ENUM


'
'  NLS version structure.
'

TYPE NLSVERSIONINFO
    dwNLSVersionInfoSize AS DWORD     ' 12 bytes
    dwNLSVersion         AS DWORD
    dwDefinedVersion     AS DWORD
END TYPE

' This is to be deprecated, please use the NLSVERSIONINFO
' structure above in the future.  The difference is that
' the effective ID is more robust.
TYPE NLSVERSIONINFOEX
    dwNLSVersionInfoSize AS DWORD     ' sizeof(NLSVERSIONINFOEX) == 32 bytes
    dwNLSVersion         AS DWORD
    dwDefinedVersion     AS DWORD
    dwEffectiveId        AS DWORD
    guidCustomVersion    AS GUID
END TYPE

'
'  GEO defines
'

MACRO GEOID=LONG
MACRO GEOTYPE=DWORD
MACRO GEOCLASS=DWORD

%GEOID_NOT_AVAILABLE = -1

'
'  GEO information types for clients to query
'

MACRO SYSGEOTYPE_enum=LONG
ENUM SYSGEOTYPE SINGULAR
    GEO_NATION   = &H0001
    GEO_LATITUDE
    GEO_LONGITUDE
    GEO_ISO2
    GEO_ISO3
    GEO_RFC1766
    GEO_LCID
    GEO_FRIENDLYNAME
    GEO_OFFICIALNAME
    GEO_TIMEZONES
    GEO_OFFICIALLANGUAGES
END ENUM

'
'  More GEOCLASS defines will be listed here
'

MACRO SYSGEOCLASS_enum=LONG
ENUM SYSGEOCLASS SINGULAR
    GEOCLASS_NATION = 16
    GEOCLASS_REGION = 14
END ENUM

#IF (%WINVER >= &H0600)
'
'  Normalization forms
'

MACRO NORM_FORM_enum=LONG
ENUM NORM_FORM SINGULAR
    NormalizationOther   ' Not supported
    NormalizationC       ' Each base plus combining characters to the canonical precomposed equivalent.
    NormalizationD       ' Each precomposed character to its canonical decomposed equivalent.
    NormalizationKC = 5  ' Each base plus combining characters to the canonical precomposed
                         '   equivalents and all compatibility characters to their equivalents.
    NormalizationKD      ' Each precomposed character to its canonical decomposed equivalent
                         '   and all compatibility characters to their equivalents.
END ENUM

'
' IDN (International Domain Name) Flags
'
%IDN_ALLOW_UNASSIGNED        = &H01  ' Allow unassigned "query" behavior per RFC 3454
%IDN_USE_STD3_ASCII_RULES    = &H02  ' Enforce STD3 ASCII restrictions for legal characters

%VS_ALLOW_LATIN              = &H0001  ' Allow Latin in test script even if not present in locale script

%GSS_ALLOW_INHERITED_COMMON  = &H0001  ' Output script ids for inherited and common character types if present
#ENDIF ' (%WINVER >= &H0600)

'
'  Enumeration function constants.
'

'typedef BOOL (CALLBACK* LANGUAGEGROUP_ENUMPROCA)(LGRPID, LPSTR, LPSTR, DWORD, LONG_PTR);
'typedef BOOL (CALLBACK* LANGGROUPLOCALE_ENUMPROCA)(LGRPID, LCID, LPSTR, LONG_PTR);
'typedef BOOL (CALLBACK* UILANGUAGE_ENUMPROCA)(LPSTR, LONG_PTR);
'typedef BOOL (CALLBACK* LOCALE_ENUMPROCA)(LPSTR);
'typedef BOOL (CALLBACK* CODEPAGE_ENUMPROCA)(LPSTR);
'typedef BOOL (CALLBACK* DATEFMT_ENUMPROCA)(LPSTR);
'typedef BOOL (CALLBACK* DATEFMT_ENUMPROCEXA)(LPSTR, CALID);
'typedef BOOL (CALLBACK* TIMEFMT_ENUMPROCA)(LPSTR);
'typedef BOOL (CALLBACK* CALINFO_ENUMPROCA)(LPSTR);
'typedef BOOL (CALLBACK* CALINFO_ENUMPROCEXA)(LPSTR, CALID);
'
'typedef BOOL (CALLBACK* LANGUAGEGROUP_ENUMPROCW)(LGRPID, LPWSTR, LPWSTR, DWORD, LONG_PTR);
'typedef BOOL (CALLBACK* LANGGROUPLOCALE_ENUMPROCW)(LGRPID, LCID, LPWSTR, LONG_PTR);
'typedef BOOL (CALLBACK* UILANGUAGE_ENUMPROCW)(LPWSTR, LONG_PTR);
'typedef BOOL (CALLBACK* LOCALE_ENUMPROCW)(LPWSTR);
'typedef BOOL (CALLBACK* CODEPAGE_ENUMPROCW)(LPWSTR);
'typedef BOOL (CALLBACK* DATEFMT_ENUMPROCW)(LPWSTR);
'typedef BOOL (CALLBACK* DATEFMT_ENUMPROCEXW)(LPWSTR, CALID);
'typedef BOOL (CALLBACK* TIMEFMT_ENUMPROCW)(LPWSTR);
'typedef BOOL (CALLBACK* CALINFO_ENUMPROCW)(LPWSTR);
'typedef BOOL (CALLBACK* CALINFO_ENUMPROCEXW)(LPWSTR, CALID);
'typedef BOOL (CALLBACK* GEO_ENUMPROC)(GEOID);

#IF %DEF(%UNICODE)

MACRO LANGUAGEGROUP_ENUMPROC=LANGUAGEGROUP_ENUMPROCW
MACRO LANGGROUPLOCALE_ENUMPROC=LANGGROUPLOCALE_ENUMPROCW
MACRO UILANGUAGE_ENUMPROC=UILANGUAGE_ENUMPROCW
MACRO LOCALE_ENUMPROC=LOCALE_ENUMPROCW
MACRO CODEPAGE_ENUMPROC=CODEPAGE_ENUMPROCW
MACRO DATEFMT_ENUMPROC=DATEFMT_ENUMPROCW
MACRO DATEFMT_ENUMPROCEX=DATEFMT_ENUMPROCEXW
MACRO TIMEFMT_ENUMPROC=TIMEFMT_ENUMPROCW
MACRO CALINFO_ENUMPROC=CALINFO_ENUMPROCW
MACRO CALINFO_ENUMPROCEX=CALINFO_ENUMPROCEXW

#ELSE

MACRO LANGUAGEGROUP_ENUMPROC=LANGUAGEGROUP_ENUMPROCA
MACRO LANGGROUPLOCALE_ENUMPROC=LANGGROUPLOCALE_ENUMPROCA
MACRO UILANGUAGE_ENUMPROC=UILANGUAGE_ENUMPROCA
MACRO LOCALE_ENUMPROC=LOCALE_ENUMPROCA
MACRO CODEPAGE_ENUMPROC=CODEPAGE_ENUMPROCA
MACRO DATEFMT_ENUMPROC=DATEFMT_ENUMPROCA
MACRO DATEFMT_ENUMPROCEX=DATEFMT_ENUMPROCEXA
MACRO TIMEFMT_ENUMPROC=TIMEFMT_ENUMPROCA
MACRO CALINFO_ENUMPROC=CALINFO_ENUMPROCA
MACRO CALINFO_ENUMPROCEX=CALINFO_ENUMPROCEXA

#ENDIF ' NOT %UNICODE

'
' Information about a MUI file, used as input/output in GetFileMUIInfo
' All offsets are relative to start of the structure. Offsets with value 0 mean empty field.
'

TYPE FILEMUIINFO
    dwSize               AS DWORD   ' Size of the structure including buffer size [in]
    dwVersion            AS DWORD   ' Version of the structure [in]
    dwFileType           AS DWORD   ' Type of the file [out]
    pChecksum(15)        AS BYTE    ' Checksum of the file (0 TO out)
    pServiceChecksum(15) AS BYTE    ' Checksum of the file (0 TO out)
    dwLanguageNameOffset AS DWORD   ' Language name of the file (0 TO out)
    dwTypeIDMainSize     AS DWORD   ' Number of TypeIDs in main module (0 TO out)
    dwTypeIDMainOffset   AS DWORD   ' Array of TypeIDs (DWORD) in main module (0 TO out)
    dwTypeNameMainOffset AS DWORD   ' Multistring array of TypeNames in main module (0 TO out)
    dwTypeIDMUISize      AS DWORD   ' Number of TypeIDs in MUI module (0 TO out)
    dwTypeIDMUIOffset    AS DWORD   ' Array of TypeIDs (DWORD) in MUI module (0 TO out)
    dwTypeNameMUIOffset  AS DWORD   ' Multistring array of TypeNames in MUI module (0 TO out)
    abBuffer(7)          AS BYTE    ' Buffer for extra data (0 TO in) (Size 4 is for padding)
END TYPE



'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
'  Macros
'
'  Define all macros for the NLS component here.
'
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

'
'  Macros to determine whether a character is a high or low surrogate,
'  and whether two code points make up a surrogate pair (a high surrogate
'  and a low surrogate).
'
MACRO IS_HIGH_SURROGATE(wch)=(((wch) >= %HIGH_SURROGATE_START) AND ((wch) <= %HIGH_SURROGATE_END))
MACRO IS_LOW_SURROGATE(wch)=(((wch) >= %LOW_SURROGATE_START) AND ((wch) <= %LOW_SURROGATE_END))
MACRO IS_SURROGATE_PAIR(hs, ls)=(IS_HIGH_SURROGATE(hs) AND IS_LOW_SURROGATE(ls))

' ----------------------------------------------------------------------
' The following macros retrieve information from a MUIFILEINFO structure
'
' Gets the culture name (LPWSTR), NULL if not initialized
'#define FILEMUIINFO_GET_CULTURE(pInfo)           _
'    ((LPWSTR)((pInfo->dwLanguageNameOffset>0)?(ULONG_PTR)pInfo+pInfo->dwLanguageNameOffset:NULL))
'
' Gets the main module types array (DWORD[]), NULL if not initialized
'#define FILEMUIINFO_GET_MAIN_TYPEIDS(pInfo)        _
'    ((DWORD*)((pInfo->dwTypeIDMainOffset>0)?(ULONG_PTR)pInfo+pInfo->dwTypeIDMainOffset:NULL))
'
' Gets the main module type array element iType (DWORD), the array is not initialized or index is out of bounds
'#define FILEMUIINFO_GET_MAIN_TYPEID(pInfo,iType)   _
'    (((iType<pInfo->dwTypeIDMainSize) AND (pInfo->dwTypeIDMainOffset>0))?*((DWORD*)((ULONG_PTR)pInfo+pInfo->dwTypeIDMainOffset)+iType):0)
'
' Gets the main module names multistring array (LPWSTR), NULL if not initialized
'#define FILEMUIINFO_GET_MAIN_TYPENAMES(pInfo)        _
'    ((LPWSTR)((pInfo->dwTypeNameMainOffset>0)?(ULONG_PTR)pInfo+pInfo->dwTypeNameMainOffset:NULL))
'
' Gets the mui module types array (DWORD[]), NULL if not initialized
'#define FILEMUIINFO_GET_MUI_TYPEIDS(pInfo)         _
'    ((DWORD*)((pInfo->dwTypeIDMUIOffset>0)?(ULONG_PTR)pInfo+pInfo->dwTypeIDMUIOffset:NULL))
'
' Gets the mui module type array element iType (DWORD), the array is not initialized or index is out of bounds
'#define FILEMUIINFO_GET_MUI_TYPEID(pInfo,iType)    _
'    (((iType<pInfo->dwTypeIDMUISize) AND (pInfo->dwTypeIDMUIOffset>0))?*((DWORD*)((ULONG_PTR)pInfo+pInfo->dwTypeIDMUIOffset)+iType):0)
'
' Gets the mui module names multistring array (LPWSTR), NULL if not initialized
'#define FILEMUIINFO_GET_MUI_TYPENAMES(pInfo)         _
'    ((LPWSTR)((pInfo->dwTypeNameMUIOffset>0)?(ULONG_PTR)pInfo+pInfo->dwTypeNameMUIOffset:NULL))
' ------------------------------------------------------------------------


'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
'  Function Prototypes
'
'  Only prototypes for the NLS APIs should go here.
'
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

'
'  Code Page Dependent APIs.
'

DECLARE FUNCTION IsValidCodePage LIB "KERNEL32.DLL" ALIAS "IsValidCodePage" _
    (BYVAL CodePag AS DWORD) AS LONG

DECLARE FUNCTION GetACP LIB "KERNEL32.DLL" ALIAS "GetACP" () AS DWORD

DECLARE FUNCTION GetOEMCP LIB "KERNEL32.DLL" ALIAS "GetOEMCP" () AS DWORD

DECLARE FUNCTION GetCPInfo LIB "KERNEL32.DLL" ALIAS "GetCPInfo" _
    (BYVAL CodePag AS DWORD, lpCPInfo AS CPINFO) AS LONG

DECLARE FUNCTION GetCPInfoExA LIB "KERNEL32.DLL" ALIAS "GetCPInfoExA" _
    (BYVAL CodePag AS DWORD, BYVAL dwFlags AS DWORD, _
    lpCPInfo AS CPINFOEXA) AS LONG

DECLARE FUNCTION GetCPInfoExW LIB "KERNEL32.DLL" ALIAS "GetCPInfoExW" _
    (BYVAL CodePag AS DWORD, BYVAL dwFlags AS DWORD, _
    lpCPInfo AS CPINFOEXW) AS LONG

#IF %DEF(%UNICODE)
MACRO GetCPInfoEx=GetCPInfoExW
#ELSE
MACRO GetCPInfoEx=GetCPInfoExA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION IsDBCSLeadByte LIB "KERNEL32.DLL" ALIAS "IsDBCSLeadByte" _
    (BYVAL bTestChar AS BYTE) AS LONG
DECLARE FUNCTION IsDBCSLeadByteEx LIB "KERNEL32.DLL" ALIAS "IsDBCSLeadByteEx" _
    (BYVAL CodePag AS DWORD, BYVAL bTestChar AS BYTE) AS LONG

DECLARE FUNCTION MultiByteToWideChar LIB "KERNEL32.DLL" _
    ALIAS "MultiByteToWideChar" (BYVAL CodePag AS DWORD, _
    BYVAL dwFlags AS DWORD, lpMultiByteStr AS ASCIIZ, _
    BYVAL cchMultiByte AS LONG, lpWideCharStr AS WSTRINGZ, _
    BYVAL cchWideChar AS LONG) AS LONG

DECLARE FUNCTION WideCharToMultiByte LIB "KERNEL32.DLL" _
    ALIAS "WideCharToMultiByte" (BYVAL CodePag AS DWORD, _
    BYVAL dwFlags AS DWORD, lpWideCharStr AS WSTRINGZ, _
    BYVAL cchWideChar AS LONG, lpMultiByteStr AS ASCIIZ, _
    BYVAL cchMultiByte AS LONG, lpDefaultChar AS ASCIIZ, _
    lpUsedDefaultChar AS LONG) AS LONG


'
'  Locale Dependent APIs.
'

DECLARE FUNCTION CompareStringA LIB "KERNEL32.DLL" ALIAS "CompareStringA" _
    (BYVAL Locale AS DWORD, BYVAL dwCmpFlags AS DWORD, lpString1 AS ASCIIZ, _
    BYVAL cchCount1 AS LONG, lpString2 AS ASCIIZ, BYVAL cchCount2 AS LONG) _
    AS LONG

DECLARE FUNCTION CompareStringW LIB "KERNEL32.DLL" ALIAS "CompareStringW" _
    (BYVAL Locale AS DWORD, BYVAL dwCmpFlags AS DWORD, lpString1 AS WSTRINGZ, _
    BYVAL cchCount1 AS LONG, lpString2 AS WSTRINGZ, BYVAL cchCount2 AS LONG) _
    AS LONG

#IF %DEF(%UNICODE)
MACRO CompareString=CompareStringW
#ELSE
MACRO CompareString=CompareStringA
#ENDIF ' NOT %UNICODE

' For Windows Vista and above CompareStringEx is preferred

#IF (%WINVER >= &H0600)

DECLARE FUNCTION FindNLSString LIB "Kernel32.dll" ALIAS "FindNLSString" _
    (BYVAL Locale AS DWORD, _
    BYVAL dwFindNLSStringFlags AS DWORD, lpStringSource AS WSTRINGZ, _
    BYVAL cchSource AS LONG, lpStringValue AS WSTRINGZ, _
    BYVAL cchValue AS LONG, pcchFound AS LONG) AS LONG

#ENDIF '(%WINVER >= &H0600)

#IF (%WINVER >= %WIN32_WINNT_WIN7)

DECLARE FUNCTION FindStringOrdinal LIB "Kernel32.dll" _
    ALIAS "FindStringOrdinal" (BYVAL dwFindStringOrdinalFlags AS DWORD, _
    lpStringSource AS WSTRINGZ, BYVAL cchSource AS LONG, _
    lpStringValue AS WSTRINGZ, BYVAL cchValue AS LONG, _
    BYVAL bIgnoreCase AS LONG) AS LONG

#ENDIF ' (%WINVER >= %WIN32_WINNT_WIN7)


DECLARE FUNCTION LCMapStringA LIB "KERNEL32.DLL" ALIAS "LCMapStringA" _
    (BYVAL Locale AS DWORD, BYVAL dwMapFlags AS DWORD, lpSrcStr AS ASCIIZ, _
    BYVAL cchSrc AS LONG, lpDestStr AS ASCIIZ, BYVAL cchDest AS LONG) AS LONG

DECLARE FUNCTION LCMapStringW LIB "KERNEL32.DLL" ALIAS "LCMapStringW" _
    (BYVAL Locale AS DWORD, BYVAL dwMapFlags AS DWORD, lpSrcStr AS WSTRINGZ, _
    BYVAL cchSrc AS LONG, lpDestStr AS WSTRINGZ, BYVAL cchDest AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO LCMapString=LCMapStringW
#ELSE
MACRO LCMapString=LCMapStringA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetLocaleInfoA LIB "KERNEL32.DLL" ALIAS "GetLocaleInfoA" _
    (BYVAL Locale AS DWORD, BYVAL LCType AS LONG, lpLCData AS ASCIIZ, _
    BYVAL cchData AS LONG) AS LONG

DECLARE FUNCTION GetLocaleInfoW LIB "KERNEL32.DLL" ALIAS "GetLocaleInfoW" _
    (BYVAL Locale AS DWORD, BYVAL LCType AS LONG, lpLCData AS WSTRINGZ, _
    BYVAL cchData AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO GetLocaleInfo=GetLocaleInfoW
#ELSE
MACRO GetLocaleInfo=GetLocaleInfoA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetLocaleInfoA LIB "KERNEL32.DLL" ALIAS "SetLocaleInfoA" _
    (BYVAL Locale AS DWORD, BYVAL LCType AS LONG, lpLCData AS ASCIIZ) AS LONG

DECLARE FUNCTION SetLocaleInfoW LIB "KERNEL32.DLL" ALIAS "SetLocaleInfoW" _
    (BYVAL Locale AS DWORD, BYVAL LCType AS LONG, lpLCData AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO SetLocaleInfo=SetLocaleInfoW
#ELSE
MACRO SetLocaleInfo=SetLocaleInfoA
#ENDIF ' NOT %UNICODE


#IF (%WINVER >= &H040A)

DECLARE FUNCTION GetCalendarInfoA LIB "KERNEL32.DLL" ALIAS "GetCalendarInfoA" _
   (BYVAL Locale AS DWORD, BYVAL Calendar AS DWORD, BYVAL CalType AS DWORD, _
   lpCalData AS ASCIIZ, BYVAL cchData AS LONG, lpValue AS DWORD) AS LONG

DECLARE FUNCTION GetCalendarInfoW LIB "KERNEL32.DLL" ALIAS "GetCalendarInfoW" _
   (BYVAL Locale AS DWORD, BYVAL Calendar AS DWORD, BYVAL CalType AS DWORD, _
   lpCalData AS WSTRINGZ, BYVAL cchData AS LONG, lpValue AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO GetCalendarInfo=GetCalendarInfoW
#ELSE
MACRO GetCalendarInfo=GetCalendarInfoA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION SetCalendarInfoA LIB "KERNEL32.DLL" ALIAS "SetCalendarInfoA" _
   (BYVAL Locale AS DWORD, BYVAL Calendar AS DWORD, BYVAL CalType AS DWORD, _
   lpCalData AS ASCIIZ) AS LONG

DECLARE FUNCTION SetCalendarInfoW LIB "KERNEL32.DLL" ALIAS "SetCalendarInfoW" _
   (BYVAL Locale AS DWORD, BYVAL Calendar AS DWORD, BYVAL CalType AS DWORD, _
   lpCalData AS WSTRINGZ) AS LONG

#IF %DEF(%UNICODE)
MACRO SetCalendarInfo=SetCalendarInfoW
#ELSE
MACRO SetCalendarInfo=SetCalendarInfoA
#ENDIF ' NOT %UNICODE

#ENDIF ' #IF (%WINVER >= &H040A)


#IF (%WINVER >= &H0600)

DECLARE FUNCTION LCIDToLocaleName LIB "Kernel32.dll" ALIAS "LCIDToLocaleName" _
    (BYVAL Locale AS DWORD, lpName AS WSTRINGZ, BYVAL ccName AS LONG, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION LocaleNameToLCID LIB "Kernel32.dll" _
    ALIAS "LocaleNameToLCID" (lpName AS WSTRINGZ, BYVAL dwFlags AS DWORD) _
    AS DWORD

#ENDIF  ' (%WINVER >= &H0600)


DECLARE FUNCTION GetTimeFormatA LIB "KERNEL32.DLL" ALIAS "GetTimeFormatA" _
    (BYVAL Locale AS DWORD, BYVAL dwFlags AS DWORD, lpTime AS SYSTEMTIME, _
    lpFormat AS ASCIIZ, lpTimeStr AS ASCIIZ, BYVAL cchTime AS LONG) AS LONG

DECLARE FUNCTION GetTimeFormatW LIB "KERNEL32.DLL" ALIAS "GetTimeFormatW" _
    (BYVAL Locale AS DWORD, BYVAL dwFlags AS DWORD, lpTime AS SYSTEMTIME, _
    lpFormat AS WSTRINGZ, lpTimeStr AS WSTRINGZ, BYVAL cchTime AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO GetTimeFormat=GetTimeFormatW
#ELSE
MACRO GetTimeFormat=GetTimeFormatA
#ENDIF ' NOT %UNICODE


#IF (%WINVER >= &H0600)

DECLARE FUNCTION GetDurationFormat LIB "Kernel32.dll" _
    ALIAS "GetDurationFormat" (BYVAL Locale AS DWORD, BYVAL dwFlags AS DWORD, _
    lpDuration AS SYSTEMTIME, BYVAL ullDuration AS QUAD, _
    lpFormat AS WSTRINGZ, lpDurationStr AS WSTRINGZ, _
    BYVAL cchDuration AS LONG) AS LONG

#ENDIF '(%WINVER >= &H0600)

DECLARE FUNCTION GetDateFormatA LIB "KERNEL32.DLL" ALIAS "GetDateFormatA" _
    (BYVAL Locale AS DWORD, BYVAL dwFlags AS DWORD, lpDate AS SYSTEMTIME, _
    lpFormat AS ASCIIZ, lpDateStr AS ASCIIZ, BYVAL cchDate AS LONG) AS LONG

DECLARE FUNCTION GetDateFormatW LIB "KERNEL32.DLL" ALIAS "GetDateFormatW" _
    (BYVAL Locale AS DWORD, BYVAL dwFlags AS DWORD, lpDate AS SYSTEMTIME, _
    lpFormat AS WSTRINGZ, lpDateStr AS WSTRINGZ, BYVAL cchDate AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO GetDateFormat=GetDateFormatW
#ELSE
MACRO GetDateFormat=GetDateFormatA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetNumberFormatA LIB "KERNEL32.DLL" ALIAS "GetNumberFormatA" _
    (BYVAL Locale AS DWORD, BYVAL dwFlags AS DWORD, lpValue AS ASCIIZ, _
    lpFormat AS NUMBERFMT, lpNumberStr AS ASCIIZ, BYVAL cchNumber AS LONG) _
    AS LONG

DECLARE FUNCTION GetNumberFormatW LIB "KERNEL32.DLL" ALIAS "GetNumberFormatW" _
    (BYVAL Locale AS DWORD, BYVAL dwFlags AS DWORD, lpValue AS WSTRINGZ, _
    lpFormat AS NUMBERFMT, lpNumberStr AS WSTRINGZ, BYVAL cchNumber AS LONG) _
    AS LONG

#IF %DEF(%UNICODE)
MACRO GetNumberFormat=GetNumberFormatW
#ELSE
MACRO GetNumberFormat=GetNumberFormatA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION GetCurrencyFormatA LIB "KERNEL32.DLL" _
    ALIAS "GetCurrencyFormatA" (BYVAL Locale AS DWORD, _
    BYVAL dwFlags AS DWORD, lpValue AS ASCIIZ, lpFormat AS CURRENCYFMTA, _
    lpCurrencyStr AS ASCIIZ, BYVAL cchCurrency AS LONG) AS LONG

DECLARE FUNCTION GetCurrencyFormatW LIB "KERNEL32.DLL" _
    ALIAS "GetCurrencyFormatW" (BYVAL Locale AS DWORD, _
    BYVAL dwFlags AS DWORD, lpValue AS WSTRINGZ, lpFormat AS CURRENCYFMTW, _
    lpCurrencyStr AS WSTRINGZ, BYVAL cchCurrency AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO GetCurrencyFormat=GetCurrencyFormatW
#ELSE
MACRO GetCurrencyFormat=GetCurrencyFormatA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumCalendarInfoA LIB "KERNEL32.DLL" _
    ALIAS "EnumCalendarInfoA" (BYVAL lpCalInfoEnumProc AS DWORD, _
    BYVAL Locale AS DWORD, BYVAL Calendar AS DWORD, BYVAL CalType AS DWORD) _
    AS LONG

DECLARE FUNCTION EnumCalendarInfoW LIB "KERNEL32.DLL" _
    ALIAS "EnumCalendarInfoW" (BYVAL lpCalInfoEnumProc AS DWORD, _
    BYVAL Locale AS DWORD, BYVAL Calendar AS DWORD, BYVAL CalType AS DWORD) _
    AS LONG

#IF %DEF(%UNICODE)
MACRO EnumCalendarInfo=EnumCalendarInfoW
#ELSE
MACRO EnumCalendarInfo=EnumCalendarInfoA
#ENDIF ' NOT %UNICODE

#IF (%WINVER >= &H0500)

DECLARE FUNCTION EnumCalendarInfoExA LIB "KERNEL32.DLL" _
    ALIAS "EnumCalendarInfoExA" (BYVAL lpCalInfoEnumProc AS DWORD, _
    BYVAL Locale AS DWORD, BYVAL Calendar AS DWORD, BYVAL CalType AS DWORD) _
    AS LONG

DECLARE FUNCTION EnumCalendarInfoExW LIB "KERNEL32.DLL" _
    ALIAS "EnumCalendarInfoExW" (BYVAL lpCalInfoEnumProc AS DWORD, _
    BYVAL Locale AS DWORD, BYVAL Calendar AS DWORD, BYVAL CalType AS DWORD) _
    AS LONG

#IF %DEF(%UNICODE)
MACRO EnumCalendarInfoEx=EnumCalendarInfoExW
#ELSE
MACRO EnumCalendarInfoEx=EnumCalendarInfoExA
#ENDIF ' NOT %UNICODE

#ENDIF ' WINVER >= &H0500

DECLARE FUNCTION EnumTimeFormatsA LIB "KERNEL32.DLL" ALIAS "EnumTimeFormatsA" _
    (BYVAL lpTimeFmtEnumProc AS DWORD, BYVAL Locale AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION EnumTimeFormatsW LIB "KERNEL32.DLL" ALIAS "EnumTimeFormatsW" _
    (BYVAL lpTimeFmtEnumProc AS DWORD, BYVAL Locale AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO EnumTimeFormats=EnumTimeFormatsW
#ELSE
MACRO EnumTimeFormats=EnumTimeFormatsA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumDateFormatsA LIB "KERNEL32.DLL" ALIAS "EnumDateFormatsA" _
    (BYVAL lpDateFmtEnumProc AS DWORD, BYVAL Locale AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION EnumDateFormatsW LIB "KERNEL32.DLL" ALIAS "EnumDateFormatsW" _
    (BYVAL lpDateFmtEnumProc AS DWORD, BYVAL Locale AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO EnumDateFormats=EnumDateFormatsW
#ELSE
MACRO EnumDateFormats=EnumDateFormatsA
#ENDIF ' NOT %UNICODE

#IF (%WINVER >= &H0500)

DECLARE FUNCTION EnumDateFormatsExA LIB "KERNEL32.DLL" _
    ALIAS "EnumDateFormatsExA" (BYVAL lpDateFmtEnumProc AS DWORD, _
    BYVAL Locale AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION EnumDateFormatsExW LIB "KERNEL32.DLL" _
    ALIAS "EnumDateFormatsExW" (BYVAL lpDateFmtEnumProc AS DWORD, _
    BYVAL Locale AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO EnumDateFormatsEx=EnumDateFormatsExW
#ELSE
MACRO EnumDateFormatsEx=EnumDateFormatsExA
#ENDIF ' NOT %UNICODE

#ENDIF ' WINVER >= &H0500

#IF (%WINVER >= &H0500)

DECLARE FUNCTION IsValidLanguageGroup LIB "KERNEL32.DLL" _
    ALIAS "IsValidLanguageGroup" (BYVAL LanguageGroup AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG

#ENDIF ' %WINVER >= &H0500

DECLARE FUNCTION GetNLSVersion LIB "Kernel32.dll" ALIAS "GetNLSVersion" _
    (BYVAL nFunction AS DWORD, BYVAL Locale AS DWORD, _
    lpVersionInformation AS NLSVERSIONINFO) AS LONG

DECLARE FUNCTION IsNLSDefinedString LIB "Kernel32.dll" _
    ALIAS "IsNLSDefinedString" (BYVAL nFunction AS DWORD, _
    BYVAL dwFlags AS DWORD, lpVersionInformation AS NLSVERSIONINFO, _
    lpString AS WSTRINGZ, BYVAL cchStr AS LONG) AS LONG

DECLARE FUNCTION IsValidLocale LIB "KERNEL32.DLL" ALIAS "IsValidLocale" _
    (BYVAL Locale AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION GetGeoInfoA LIB "KERNEL32.DLL" ALIAS "GetGeoInfoA" _
    (BYVAL Location AS LONG, BYVAL GeoType AS DWORD, lpGeoData AS ASCIIZ, _
    BYVAL cchData AS LONG, BYVAL LangId AS WORD) AS LONG

DECLARE FUNCTION GetGeoInfoW LIB "KERNEL32.DLL" ALIAS "GetGeoInfoW" _
    (BYVAL Location AS LONG, BYVAL GeoType AS DWORD, lpGeoData AS WSTRINGZ, _
    BYVAL cchData AS LONG, BYVAL LangId AS WORD) AS LONG

#IF %DEF(%UNICODE)
MACRO GetGeoInfo=GetGeoInfoW
#ELSE
MACRO GetGeoInfo=GetGeoInfoA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumSystemGeoID LIB "KERNEL32.DLL" ALIAS "EnumSystemGeoID" _
    (BYVAL GeoClass AS DWORD, BYVAL ParentGeoId AS LONG, _
    BYVAL lpGeoEnumProc AS DWORD) AS LONG

DECLARE FUNCTION GetUserGeoID LIB "KERNEL32.DLL" ALIAS "GetUserGeoID" _
    (BYVAL GeoClass AS DWORD) AS LONG

DECLARE FUNCTION SetUserGeoID LIB "KERNEL32.DLL" ALIAS "SetUserGeoID" _
    (BYVAL GeoId AS LONG) AS LONG

DECLARE FUNCTION ConvertDefaultLocale LIB "KERNEL32.DLL" _
    ALIAS "ConvertDefaultLocale" (BYVAL Locale AS DWORD) AS DWORD

DECLARE FUNCTION GetThreadLocale LIB "KERNEL32.DLL" ALIAS "GetThreadLocale" _
    () AS DWORD

DECLARE FUNCTION SetThreadLocale LIB "KERNEL32.DLL" ALIAS "SetThreadLocale" _
    (BYVAL Locale AS DWORD) AS LONG

#IF (%WINVER >= &H0500)

DECLARE FUNCTION GetSystemDefaultUILanguage LIB "KERNEL32.DLL" _
    ALIAS "GetSystemDefaultUILanguage" () AS DWORD

DECLARE FUNCTION GetUserDefaultUILanguage LIB "KERNEL32.DLL" _
    ALIAS "GetUserDefaultUILanguage" () AS DWORD

#ENDIF ' WINVER >= &H0500

DECLARE FUNCTION GetSystemDefaultLangID LIB "KERNEL32.DLL" _
    ALIAS "GetSystemDefaultLangID" () AS WORD

DECLARE FUNCTION GetUserDefaultLangID LIB "KERNEL32.DLL" _
    ALIAS "GetUserDefaultLangID" () AS WORD

DECLARE FUNCTION GetSystemDefaultLCID LIB "KERNEL32.DLL" _
    ALIAS "GetSystemDefaultLCID" () AS DWORD

DECLARE FUNCTION GetUserDefaultLCID LIB "KERNEL32.DLL" _
    ALIAS "GetUserDefaultLCID" () AS DWORD

DECLARE FUNCTION SetThreadUILanguage LIB "Kernel32.dll" _
    ALIAS "SetThreadUILanguage" (BYVAL LangId AS WORD) AS WORD


#IF (%WINVER >= &H0600)

DECLARE FUNCTION GetThreadUILanguage LIB "Kernel32.dll" _
    ALIAS "GetThreadUILanguage" () AS WORD

DECLARE FUNCTION GetProcessPreferredUILanguages LIB "Kernel32.dll" _
    ALIAS "GetProcessPreferredUILanguages" (BYVAL dwFlags AS DWORD, _
    pulNumLanguages AS DWORD, pwszLanguagesBuffer AS ANY, _
    pcchLanguagesBuffer AS DWORD) AS LONG

DECLARE FUNCTION SetProcessPreferredUILanguages LIB "Kernel32.dll" _
    ALIAS "SetProcesspreferredUILanguages" (BYVAL dwFlags AS DWORD, _
    pwszLanguagesBuffer AS ANY, pulNumLanguages AS DWORD) AS LONG

DECLARE FUNCTION GetUserPreferredUILanguages LIB "Kernel32.dll" _
    ALIAS "GetUserPreferredUILanguages" (BYVAL dwFlags AS DWORD, _
    pulNumLanguages AS DWORD, BYVAL pwszLanguagesBuffer AS DWORD, _
    pcchLanguagesBuffer AS DWORD) AS LONG

DECLARE FUNCTION GetSystemPreferredUILanguages LIB "Kernel32.dll" _
    ALIAS "GetSystemPreferredUILanguages" (BYVAL dwFlags AS DWORD, _
    pulNumLanguages AS DWORD, BYVAL pwszLanguagesBuffer AS DWORD, _
    pcchLanguagesBuffer AS DWORD) AS LONG

DECLARE FUNCTION GetThreadPreferredUILanguages LIB "Kernel32.dll" _
    ALIAS "GetThreadPreferredUILanguages" (BYVAL dwFlags AS DWORD, _
    pulNumLanguages AS DWORD, BYVAL pwszLanguagesBuffer AS DWORD, _
    pcchLanguagesBuffer AS DWORD) AS LONG

DECLARE FUNCTION SetThreadPreferredUILanguages LIB "Kernel32.dll" _
    ALIAS "SetThreadPreferredUILanguages" (BYVAL dwFlags AS DWORD, _
    BYVAL pwszLanguagesBuffer AS DWORD, pulNumLanguages AS DWORD) AS LONG

DECLARE FUNCTION GetFileMUIInfo LIB "Kernel32.dll" ALIAS "GetFileMUIInfo" _
    (BYVAL dwFlags AS DWORD, pcwszFilePath AS WSTRINGZ, _
    pFileMUIInfo AS FILEMUIINFO, pcbFileMUIInfo AS DWORD) AS LONG

DECLARE FUNCTION GetFileMUIPath LIB "Kernel32.dll" ALIAS "GetFileMUIPath" _
    (BYVAL dwFlags AS DWORD, pcwszFilePath AS WSTRINGZ, _
    pwszLanguage AS WSTRINGZ, pcchLanguage AS DWORD, _
    pwszFileMUIPath AS WSTRINGZ, pcchFileMUIPath AS DWORD, _
    pululEnumerator AS QUAD) AS LONG

DECLARE FUNCTION GetUILanguageInfo LIB "Kernel32.dll" _
    ALIAS "GetUILanguageInfo" (BYVAL dwFlags AS DWORD, _
    pwmszLanguage AS WSTRINGZ, pwszFallbackLanguages AS WSTRINGZ, _
    pcchFallbackLanguages AS DWORD, pAttributes AS DWORD) AS LONG

DECLARE FUNCTION NotifyUILanguageChange LIB "Kernel32.dll" _
    ALIAS "NotifyUILanguageChange" (BYVAL dwFlags AS DWORD, _
    pcwstrNewLanguage AS WSTRINGZ, pcwstrPreviousLanguage AS WSTRINGZ, _
    BYVAL dwReserved AS DWORD, pdwStatusRtrn AS DWORD) AS LONG

#ENDIF

'
'  Locale Independent APIs.
'

DECLARE FUNCTION GetStringTypeExA LIB "KERNEL32.DLL" ALIAS "GetStringTypeExA" _
    (BYVAL Locale AS DWORD, BYVAL dwInfoType AS DWORD, lpSrcStr AS ASCIIZ, _
    BYVAL cchSrc AS LONG, lpCharType AS WORD) AS LONG

DECLARE FUNCTION GetStringTypeExW LIB "KERNEL32.DLL" ALIAS "GetStringTypeExW" _
    (BYVAL Locale AS DWORD, BYVAL dwInfoType AS DWORD, lpSrcStr AS WSTRINGZ, _
    BYVAL cchSrc AS LONG, lpCharType AS WORD) AS LONG

#IF %DEF(%UNICODE)
MACRO GetStringTypeEx=GetStringTypeExW
#ELSE
MACRO GetStringTypeEx=GetStringTypeExA
#ENDIF ' NOT %UNICODE

'
'  NOTE: The parameters for GetStringTypeA and GetStringTypeW are
'        NOT the same.  The W version was shipped in NT 3.1.  The
'        A version was then shipped in 16-bit OLE with the wrong
'        parameters (ported from Win95).  To be compatible, we
'        must break the relationship between the A and W versions
'        of GetStringType.  There will be NO function call for the
'        generic GetStringType.
'
'        GetStringTypeEx (above) should be used instead.
'

DECLARE FUNCTION GetStringTypeA LIB "KERNEL32.DLL" ALIAS "GetStringTypeA" _
    (BYVAL lcid AS DWORD, BYVAL dwInfoType AS DWORD, lpSrcStr AS ASCIIZ, _
    BYVAL cchSrc AS LONG, lpCharType AS WORD) AS LONG

DECLARE FUNCTION GetStringTypeW LIB "KERNEL32.DLL" ALIAS "GetStringTypeW" _
    (BYVAL dwInfoType AS DWORD, lpSrcStr AS WSTRINGZ, BYVAL cchSrc AS LONG, _
    lpCharType AS WORD) AS LONG

DECLARE FUNCTION FoldStringA LIB "KERNEL32.DLL" ALIAS "FoldStringA" _
    (BYVAL dwMapFlags AS DWORD, lpSrcStr AS ASCIIZ, BYVAL cchSrc AS LONG, _
    lpDestStr AS ASCIIZ, BYVAL cchDest AS LONG) AS LONG

DECLARE FUNCTION FoldStringW LIB "KERNEL32.DLL" ALIAS "FoldStringW" _
    (BYVAL dwMapFlags AS DWORD, lpSrcStr AS WSTRINGZ, BYVAL cchSrc AS LONG, _
    lpDestStr AS WSTRINGZ, BYVAL cchDest AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO FoldString=FoldStringW
#ELSE
MACRO FoldString=FoldStringA
#ENDIF ' NOT %UNICODE

#IF (%WINVER >= &H0500)

DECLARE FUNCTION EnumSystemLanguageGroupsA LIB "KERNEL32.DLL" _
    ALIAS "EnumSystemLanguageGroupsA" _
    (BYVAL lpLanguageGroupEnumProc AS DWORD, BYVAL dwFlags AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION EnumSystemLanguageGroupsW LIB "KERNEL32.DLL" _
    ALIAS "EnumSystemLanguageGroupsW" _
    (BYVAL lpLanguageGroupEnumProc AS DWORD, BYVAL dwFlags AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO EnumSystemLanguageGroups=EnumSystemLanguageGroupsW
#ELSE
MACRO EnumSystemLanguageGroups=EnumSystemLanguageGroupsA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumLanguageGroupLocalesA LIB "Kernel32.dll" _
    ALIAS "EnumLanguageGroupLocalesA" _
    (BYVAL lpLangGroupLocaleEnumProc AS DWORD, BYVAL LanguageGroup AS DWORD, _
    BYVAL dwFlags AS DWORD, BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION EnumLanguageGroupLocalesW LIB "Kernel32.dll" _
    ALIAS "EnumLanguageGroupLocalesW" _
    (BYVAL lpLangGroupLocaleEnumProc AS DWORD, BYVAL LanguageGroup AS DWORD, _
    BYVAL dwFlags AS DWORD, BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO EnumLanguageGroupLocales=EnumLanguageGroupLocalesW
#ELSE
MACRO EnumLanguageGroupLocales=EnumLanguageGroupLocalesA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumUILanguagesA LIB "KERNEL32.DLL" ALIAS "EnumUILanguagesA" _
    (BYVAL lpUILanguageEnumProc AS DWORD, BYVAL dwFlags AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION EnumUILanguagesW LIB "KERNEL32.DLL" ALIAS "EnumUILanguagesW" _
    (BYVAL lpUILanguageEnumProc AS DWORD, BYVAL dwFlags AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
MACRO EnumUILanguages=EnumUILanguagesW
#ELSE
MACRO EnumUILanguages=EnumUILanguagesA
#ENDIF ' NOT %UNICODE
#ENDIF ' WINVER >= &H0500

DECLARE FUNCTION EnumSystemLocalesA LIB "KERNEL32.DLL" _
    ALIAS "EnumSystemLocalesA" (BYVAL lpLocaleEnumProc AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION EnumSystemLocalesW LIB "KERNEL32.DLL" _
    ALIAS "EnumSystemLocalesW" (BYVAL lpLocaleEnumProc AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO EnumSystemLocales=EnumSystemLocalesW
#ELSE
MACRO EnumSystemLocales=EnumSystemLocalesA
#ENDIF ' NOT %UNICODE

DECLARE FUNCTION EnumSystemCodePagesA LIB "KERNEL32.DLL" _
    ALIAS "EnumSystemCodePagesA" (BYVAL lpCodePageEnumProc AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG

DECLARE FUNCTION EnumSystemCodePagesW LIB "KERNEL32.DLL" _
    ALIAS "EnumSystemCodePagesW" (BYVAL lpCodePageEnumProc AS DWORD, _
    BYVAL dwFlags AS DWORD) AS LONG

#IF %DEF(%UNICODE)
MACRO EnumSystemCodePages=EnumSystemCodePagesW
#ELSE
MACRO EnumSystemCodePages=EnumSystemCodePagesA
#ENDIF ' NOT %UNICODE


#IF (%WINVER >= &H0600)
'
' Windows API Normalization Functions
'

DECLARE FUNCTION NormalizeString LIB "Normaliz.dll" ALIAS "NormalizeString" _
    (BYVAL NormForm AS LONG, lpSrcString AS WSTRINGZ, _
    BYVAL cwSrcLength AS LONG, lpDstString AS WSTRINGZ, _
    BYVAL cwDstLength AS LONG) AS LONG

DECLARE FUNCTION IsNormalizedString LIB "Normaliz.dll" _
    ALIAS "IsNormalizedString" (BYVAL NormForm AS LONG, lpString AS WSTRINGZ, _
    BYVAL cwLength AS LONG) AS LONG

'
' IDN (International Domain Name) Functions
'
DECLARE FUNCTION IdnToAscii LIB "Normaliz.dll" ALIAS "IdnToAscii" _
    (BYVAL dwFlags AS DWORD, lpUnicodeCharStr AS WSTRINGZ, _
    BYVAL cchUnicodeChar AS LONG, lpASCIICharStr AS WSTRINGZ, _
    BYVAL cchASCIIChar AS LONG) AS LONG

DECLARE FUNCTION IdnToNameprepUnicode LIB "Normaliz.dll" _
    ALIAS "IdnToNameprepUnicode" (BYVAL dwFlags AS DWORD, _
    lpUnicodeCharStr AS WSTRINGZ, BYVAL cchUnicodeChar AS LONG, _
    lpNameprepCharStr AS WSTRINGZ, BYVAL cchNameprepChar AS LONG) AS LONG

DECLARE FUNCTION IdnToUnicode LIB "Normaliz.dll" ALIAS "IdnToUnicode" _
    (BYVAL dwFlags AS DWORD, lpASCIICharStr AS WSTRINGZ, _
    BYVAL cchASCIIChar AS LONG, lpUnicodeCharStr AS WSTRINGZ, _
    BYVAL cchUnicodeChar AS LONG) AS LONG

DECLARE FUNCTION VerifyScripts LIB "Kernel32.dll" ALIAS "VerifyScripts" _
    (BYVAL dwFlags AS DWORD, _          ' optional behavior flags
    BYVAL lpLocaleScripts AS DWORD, _   ' Locale list of scripts string
    BYVAL cchLocaleScripts AS LONG, _   ' size of locale script list string
    BYVAL lpTestScripts AS DWORD, _     ' test scripts string
    BYVAL cchTestScripts AS LONG) _     ' size of test list string
    AS LONG

DECLARE FUNCTION GetStringScripts LIB "Kernel32.dll" ALIAS "GetStringScripts" _
    (BYVAL dwFlags AS DWORD, _       ' optional behavior flags
    BYVAL lpString AS DWORD PTR, _   ' Unicode character input string
    BYVAL cchString AS LONG, _       ' size of input string
    lpScripts AS WSTRINGZ, _         ' Script list output string
    BYVAL cchScripts AS LONG) _      ' size of output string
    AS LONG

#ENDIF '(%WINVER >= &H0600)

#IF (%WINVER >= &H0600)
'
' String based NLS APIs
'

%LOCALE_NAME_USER_DEFAULT          = %NULL
$$LOCALE_NAME_INVARIANT            = ""$$
$$LOCALE_NAME_SYSTEM_DEFAULT       = "!x-sys-default-locale"$$

DECLARE FUNCTION GetLocaleInfoEx LIB "Kernel32.dll" ALIAS "GetLocaleInfoEx" _
    (lpLocaleName AS WSTRINGZ, BYVAL LCType AS DWORD, lpLCData AS WSTRINGZ, _
    BYVAL cchData AS LONG) AS LONG

DECLARE FUNCTION GetCalendarInfoEx LIB "Kernel32.dll" _
    ALIAS "GetCalendarInfoEx" (lpLocaleName AS WSTRINGZ, _
    BYVAL dCalendar AS DWORD, lpReserved AS WSTRINGZ, BYVAL CalType AS DWORD, _
    lpCalData AS WSTRINGZ, BYVAL cchData AS LONG, lpValue AS DWORD) AS LONG

DECLARE FUNCTION GetTimeFormatEx LIB "Kernel32.dll" ALIAS "GetTimeFormatEx" _
    (lpLocaleName AS WSTRINGZ, BYVAL dwFlags AS DWORD, lpTime AS SYSTEMTIME, _
    lpFormat AS WSTRINGZ, lpTimeStr AS WSTRINGZ, BYVAL cchTime AS LONG) AS LONG

DECLARE FUNCTION GetDateFormatEx LIB "Kernel32.dll" ALIAS "GetDateFormatEx" _
    (lpLocaleName AS WSTRINGZ, BYVAL dwFlags AS DWORD, lpDate AS SYSTEMTIME, _
    lpFormat AS WSTRINGZ, lpDateStr AS WSTRINGZ, BYVAL cchDate AS LONG, _
    lpCalendar AS WSTRINGZ) AS LONG

DECLARE FUNCTION GetDurationFormatEx LIB "Kernel32.dll" _
    ALIAS "GetDurationFormatEx" (lpLocaleName AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD, lpDuration AS SYSTEMTIME, _
    BYVAL ullDuration AS QUAD, lpFormat AS WSTRINGZ, _
    lpDurationString AS WSTRINGZ, BYVAL cchDuration AS LONG) AS LONG

DECLARE FUNCTION GetNumberFormatEx LIB "Kernel32.dll" _
    ALIAS "GetNumberFormatEx" (lpLocaleName AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD, lpValue AS WSTRINGZ, lpFormat AS NUMBERFMTW, _
    lpNumberStr AS WSTRINGZ, BYVAL cchNumber AS LONG) AS LONG

DECLARE FUNCTION GetCurrencyFormatEx LIB "Kernel32.dll" _
    ALIAS "GetCurrencyFormatEx" (lpLocaleName AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD, lpValue AS WSTRINGZ, lpFormat AS CURRENCYFMTW, _
    lpCurrencyStr AS WSTRINGZ, BYVAL cchCurrency AS LONG) AS LONG

DECLARE FUNCTION GetUserDefaultLocaleName LIB "Kernel32.dll" _
    ALIAS "GetUserDefaultLocaleName" (lpLocaleName AS WSTRINGZ, _
    BYVAL cchLocaleName AS LONG) AS LONG

DECLARE FUNCTION GetSystemDefaultLocaleName LIB "Kernel32.dll" _
    ALIAS "GetSystemDefaultLocaleName" (lpLocaleName AS WSTRINGZ, _
    BYVAL cchLocaleName AS LONG) AS LONG

DECLARE FUNCTION GetNLSVersionEx LIB "Kernel32.dll" _
    ALIAS "GetNLSVersionEx" (BYVAL nFunction AS DWORD, _
    BYVAL cchLocaleName AS LONG) AS LONG

DECLARE FUNCTION CompareStringEx LIB "Kernel32.dll" _
    ALIAS "CompareStringEx" (lpLocaleName AS WSTRINGZ, _
    BYVAL dwCmpFlags AS DWORD, lpString1 AS WSTRINGZ, _
    BYVAL cchCount1 AS LONG, lpString2 AS WSTRINGZ, BYVAL cchCount2 AS LONG, _
    lpVersionInformation AS NLSVERSIONINFO, lpReserved AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION FindNLSStringEx LIB "Kernel32.dll" _
    ALIAS "FindNLSStringEx" (lpLocaleName AS WSTRINGZ, _
    BYVAL dwFindNLSStringFlags AS DWORD, lpStringSource AS WSTRINGZ, _
    BYVAL cchSource AS LONG, lpStringValue AS WSTRINGZ, _
    BYVAL cchValue AS LONG, pcchFound AS LONG, _
    lpVersionInformation AS NLSVERSIONINFO, lpReserved AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION LCMapStringEx LIB "Kernel32.dll" _
    ALIAS "LCMapStringEx" (lpLocaleName AS WSTRINGZ, _
    BYVAL dwMapFlags AS DWORD, lpSrcStr AS WSTRINGZ, BYVAL cchSrc AS LONG, _
    lpDestStr AS WSTRINGZ, BYVAL cchDest AS LONG, _
    lpVersionInformation AS NLSVERSIONINFO, lpReserved AS DWORD, _
    BYVAL lParam AS LONG) AS LONG

DECLARE FUNCTION CompareStringOrdinal LIB "Kernel32.dll" _
    ALIAS "CompareStringOrdinal" (lpString1 AS WSTRINGZ, _
    BYVAL cchCount1 AS LONG, lpString2 AS WSTRINGZ, BYVAL cchCount2 AS LONG, _
    BYVAL bIgnoreCase AS LONG) AS LONG

DECLARE FUNCTION IsValidLocaleName LIB "Kernel32.dll" _
    ALIAS "IsValidLocaleName" (lpLocaleName AS WSTRINGZ) AS LONG

'typedef BOOL (CALLBACK* CALINFO_ENUMPROCEXEX)(LPWSTR, CALID, LPWSTR, LPARAM);

DECLARE FUNCTION EnumCalendarInfoExEx LIB "Kernel32.dll" _
    ALIAS "EnumCalendarInfoExEx" (BYVAL pCalInfoEnumProcExEx AS DWORD, _
    lpLocaleName AS WSTRINGZ, BYVAL nCalendar AS DWORD, _
    lpReserved AS WSTRINGZ, BYVAL CalType AS DWORD, BYVAL lParam AS LONG) _
    AS LONG

'typedef BOOL (CALLBACK* DATEFMT_ENUMPROCEXEX)(LPWSTR, CALID, LPARAM);

DECLARE FUNCTION EnumDateFormatsExEx LIB "Kernel32.dll" _
    ALIAS "EnumDateFormatsExEx" (BYVAL lpDateFmtEnumProcExEx AS DWORD, _
    lpLocaleName AS WSTRINGZ, BYVAL dwFlags AS DWORD, BYVAL lParam AS LONG) _
    AS LONG

'typedef BOOL (CALLBACK* TIMEFMT_ENUMPROCEX)(LPWSTR, LPARAM);

DECLARE FUNCTION EnumTimeFormatsEx LIB "Kernel32.dll" _
    ALIAS "EnumTimeFormatsEx" (BYVAL lpTimeFmtEnumProcEx AS DWORD, _
    lpLocaleName AS WSTRINGZ, BYVAL dwFlags AS DWORD, BYVAL lParam AS LONG) _
    AS LONG

'typedef BOOL (CALLBACK* LOCALE_ENUMPROCEX)(LPWSTR, DWORD, LPARAM);

DECLARE FUNCTION EnumSystemLocalesEx LIB "Kernel32.dll" _
    ALIAS "EnumSystemLocalesEx" (BYVAL lpLocaleEnumProcEx AS DWORD, _
    BYVAL dwFlags AS DWORD, BYVAL lParam AS LONG, lpReserved AS DWORD) AS LONG

#ENDIF ' (%WINVER >= &H0600)

#IF (%WINVER >= %WIN32_WINNT_WIN7)

DECLARE FUNCTION ResolveLocaleName LIB "Kernel32.dll" _
    ALIAS "ResolveLocaleName" (lpNameToResolve AS WSTRINGZ, _
    lpLocaleName AS WSTRINGZ, BYVAL cchLocaleName AS LONG) AS LONG

#ENDIF  ' #if (%WINVER >= %WIN32_WINNT_WIN7)

#ENDIF ' %NONLS
