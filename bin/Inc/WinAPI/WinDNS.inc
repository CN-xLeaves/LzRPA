'------------------------------------------------------------------------------
'
'  WinDNS.inc - Domain Name System (DNS) definitions and API.
'
'  Copyright (c) 2010-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 02 May 2011
'
'------------------------------------------------------------------------------
'  from WinDNS.h dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%WINDNS_INCLUDED = 1

#INCLUDE "SdkDdkVer.inc"

'
'  Define QWORD -- not yet defined globally
'

'typedef unsigned __int64 QWORD, *PQWORD;

'
'  DNS public types
'

MACRO DNS_STATUS=LONG

'
'  IP Address
'

MACRO IP4_ADDRESS=DWORD

%SIZEOF_IP4_ADDRESS                = (4)
%IP4_ADDRESS_STRING_LENGTH         = (16)

'  Backcompat only -- length def contains terminating NULL

%IP4_ADDRESS_STRING_BUFFER_LENGTH  = (16)


'
'  IP Address Array type
'

TYPE IP4_ARRAY
    AddrCount    AS DWORD
    AddrArray(0) AS IP4_ADDRESS
END TYPE


'
'  IPv6 Address
'

UNION IP6_ADDRESS
#IF %DEF(%WIN64)
    IP6Qword(1) AS QUAD  ' QWORD
#ENDIF
    IP6Dword(3) AS DWORD
    IP6Word(7) AS DWORD
    IP6Byte(15) AS BYTE
#IF %DEF(%IN6_ADDR)
    In6 AS IN6_ADDR
#ENDIF
END UNION


'
'  IP6 string max is 45 bytes
'      - 6 WORDs in colon+hex (5 chars)
'      - last DWORD as IP4 (15 chars)
'  but include
'      - 11 bytes for scope ID
'      - 6 bytes for port (inc. colon)
'      - two bytes to bracket address with port
'      - terminating NULL
'
'  Note:  this is a change to previous def, but a single
'      definition containing space for ALL possible IPv6
'      address strings, we eliminate many possible errors

'#undef  IP6_ADDRESS_STRING_LENGTH
%IP6_ADDRESS_STRING_LENGTH         = (65)
%IP6_ADDRESS_STRING_BUFFER_LENGTH  = (65)

'
'  IP4/IP6 combined maximum
'

%DNS_ADDRESS_STRING_LENGTH         = (%IP6_ADDRESS_STRING_LENGTH)


'
'  Inline byte flipping -- can be done in registers
'

MACRO INLINE_WORD_FLIP(outb, inb)
    outb = LO(BYTE,inb) OR HI(BYTE,inb)
END MACRO
MACRO INLINE_HTONS(outb,inb)=INLINE_WORD_FLIP(outb,inb)
MACRO INLINE_NTOHS(outb,inb)=INLINE_WORD_FLIP(outb,inb)

MACRO INLINE_DWORD_FLIP(outb, inb)
    outb = HI(BYTE,HI(WORD,inb)) OR LO(BYTE,HI(WORD,inb)) OR HI(BYTE,LO(WORD,inb)) OR LO(BYTE,LO(WORD,inb))
END MACRO
MACRO INLINE_NTOHL(outb, inb)=INLINE_DWORD_FLIP(outb, inb)
MACRO INLINE_HTONL(outb, inb)=INLINE_DWORD_FLIP(outb, inb)


'
'  Inline byte flip and write to packet (unaligned)
'

MACRO INLINE_WRITE_FLIPPED_WORD(pout, inb)=INLINE_WORD_FLIP(*(pout), inb)

MACRO INLINE_WRITE_FLIPPED_DWORD(pout, inb)=INLINE_DWORD_FLIP(*(pout), inb)



'
'  Basic DNS definitions
'

'
'  DNS port for both UDP and TCP is 53.
'

%DNS_PORT_HOST_ORDER   = (&H0035)    ' port 53
%DNS_PORT_NET_ORDER    = (&H3500)

'
'  DNS UDP packets no more than 512 bytes
'

%DNS_RFC_MAX_UDP_PACKET_LENGTH = (512)


'
'  DNS Names limited to 255, 63 in any one label
'

%DNS_MAX_NAME_LENGTH           = (255)
%DNS_MAX_LABEL_LENGTH          = (63)

%DNS_MAX_NAME_BUFFER_LENGTH    = (256)
%DNS_MAX_LABEL_BUFFER_LENGTH   = (64)

'
'  Reverse lookup domain names
'

$DNS_IP4_REVERSE_DOMAIN_STRING_A    = "in-addr.arpa."
$$DNS_IP4_REVERSE_DOMAIN_STRING_W   = "in-addr.arpa."$$

%DNS_MAX_IP4_REVERSE_NAME_LENGTH    = (%IP4_ADDRESS_STRING_LENGTH+15)
    '(IP4_ADDRESS_STRING_LENGTH+1+sizeof(DNS_IP4_REVERSE_DOMAIN_STRING_A))

$DNS_IP6_REVERSE_DOMAIN_STRING_A    = "ip6.arpa."$
$$DNS_IP6_REVERSE_DOMAIN_STRING_W   = "ip6.arpa."$$

%DNS_MAX_IP6_REVERSE_NAME_LENGTH    = (75)
            '(64+sizeof(DNS_IP6_REVERSE_DOMAIN_STRING_A))

'  Combined

%DNS_MAX_REVERSE_NAME_LENGTH  = %DNS_MAX_IP6_REVERSE_NAME_LENGTH

#IF %DEF(%UNICODE)
$$DNS_IP4_REVERSE_DOMAIN_STRING = $$DNS_IP4_REVERSE_DOMAIN_STRING_W
$$DNS_IP6_REVERSE_DOMAIN_STRING = $$DNS_IP6_REVERSE_DOMAIN_STRING_W
#ELSE
$DNS_IP4_REVERSE_DOMAIN_STRING = $DNS_IP4_REVERSE_DOMAIN_STRING_A
$DNS_IP6_REVERSE_DOMAIN_STRING = $DNS_IP6_REVERSE_DOMAIN_STRING_A
#ENDIF

'
'  Backcompat only -- name def contains terminating NULL
'

%DNS_MAX_IP4_REVERSE_NAME_BUFFER_LENGTH = %DNS_MAX_IP4_REVERSE_NAME_LENGTH
%DNS_MAX_IP6_REVERSE_NAME_BUFFER_LENGTH = %DNS_MAX_IP6_REVERSE_NAME_LENGTH
%DNS_MAX_REVERSE_NAME_BUFFER_LENGTH     = %DNS_MAX_REVERSE_NAME_LENGTH


'
'  DNS Text string limited by size representable
'      in a single byte length field

%DNS_MAX_TEXT_STRING_LENGTH = (255)




'
'  DNS On-The-Wire Structures
'


'
'  DNS Message Header
'

TYPE DNS_HEADER
    Xid                AS WORD

    RecursionDesired   AS BIT * 1 IN BYTE
    Truncation         AS BIT * 1
    Authoritative      AS BIT * 1
    Opcode             AS BIT * 4
    IsResponse         AS BIT * 1

    ResponseCode       AS BIT * 4 IN BYTE
    CheckingDisabled   AS BIT * 1
    AuthenticatedData  AS BIT * 1
    Reserved           AS BIT * 1
    RecursionAvailable AS BIT * 1

    QuestionCount      AS WORD
    AnswerCount        AS WORD
    NameServerCount    AS WORD
    AdditionalCount    AS WORD
END TYPE

TYPE DNS_HEADER_EXT
    Reserved  AS BIT * 15 IN WORD
    DnssecOk  AS BIT * 1
    chRcode   AS BYTE
    chVersion AS BYTE
END TYPE

'
'  Flags as WORD
'

'#define DNS_HEADER_FLAGS(pHead)     ( *((PWORD)(pHead)+1) )


'
'  Byte flip DNS header to\from host order.
'
'  Note that this does NOT flip flags, as definition above defines
'  flags as individual bytes for direct access to net byte order.
'

MACRO DNS_BYTE_FLIP_HEADER_COUNTS(pHeader)
    INLINE_HTONS(@pHeader.Xid,@pHeader.Xid)
    INLINE_HTONS(@pHeader.QuestionCount,@pHeader.QuestionCount)
    INLINE_HTONS(@pHeader.AnswerCount,@pHeader.AnswerCount)
    INLINE_HTONS(@pHeader.NameServerCount,@pHeader.NameServerCount)
    INLINE_HTONS(@pHeader.AdditionalCount,@pHeader.AdditionalCount)
END MACRO

'
'  Question name follows header
'

%DNS_OFFSET_TO_QUESTION_NAME  = 12  ' sizeof(DNS_HEADER)

'
'  Question immediately follows header so compressed question name
'      &HC000 OR sizeof(DNS_HEADER)

%DNS_COMPRESSED_QUESTION_NAME = (&HC00C)


'
'  Packet extraction macros
'

'#define DNS_QUESTION_NAME_FROM_HEADER( _pHeader_ )  _
'            ( (PCHAR)( (PDNS_HEADER)(_pHeader_) + 1 ) )
'
'#define DNS_ANSWER_FROM_QUESTION( _pQuestion_ )  _
'            ( (PCHAR)( (PDNS_QUESTION)(_pQuestion_) + 1 ) )


'
'  DNS Question
'

TYPE DNS_WIRE_QUESTION
    '  Preceded by question name

    QuestionType  AS WORD
    QuestionClass AS WORD
END TYPE


'
'  DNS Resource Record
'

TYPE DNS_WIRE_RECORD
    '  Preceded by record owner name

    RecordType  AS WORD
    RecordClass AS WORD
    TimeToLive  AS DWORD
    DataLength  AS WORD

    '  Followed by record data
END TYPE


'
'  DNS Query Types
'

%DNS_OPCODE_QUERY          = 0   ' Query
%DNS_OPCODE_IQUERY         = 1   ' Obsolete: IP to name
%DNS_OPCODE_SERVER_STATUS  = 2   ' Obsolete: DNS ping
%DNS_OPCODE_UNKNOWN        = 3   ' Unknown
%DNS_OPCODE_NOTIFY         = 4   ' Notify
%DNS_OPCODE_UPDATE         = 5   ' Dynamic Update

'
'  DNS response codes.
'
'  Sent in the "ResponseCode" field of a DNS_HEADER.
'

%DNS_RCODE_NOERROR     = 0
%DNS_RCODE_FORMERR     = 1       ' Format error
%DNS_RCODE_SERVFAIL    = 2       ' Server failure
%DNS_RCODE_NXDOMAIN    = 3       ' Name error
%DNS_RCODE_NOTIMPL     = 4       ' Not implemented
%DNS_RCODE_REFUSED     = 5       ' Refused
%DNS_RCODE_YXDOMAIN    = 6       ' Domain name should not exist
%DNS_RCODE_YXRRSET     = 7       ' RR set should not exist
%DNS_RCODE_NXRRSET     = 8       ' RR set does not exist
%DNS_RCODE_NOTAUTH     = 9       ' Not authoritative for zone
%DNS_RCODE_NOTZONE     = 10      ' Name is not zone
%DNS_RCODE_MAX         = 15

'
'  Extended RCODEs
'

%DNS_RCODE_BADVERS     = 16      ' Bad EDNS version
%DNS_RCODE_BADSIG      = 16      ' Bad signature
%DNS_RCODE_BADKEY      = 17      ' Bad key
%DNS_RCODE_BADTIME     = 18      ' Bad timestamp

'
'  Mappings to friendly names
'

%DNS_RCODE_NO_ERROR        = %DNS_RCODE_NOERROR
%DNS_RCODE_FORMAT_ERROR    = %DNS_RCODE_FORMERR
%DNS_RCODE_SERVER_FAILURE  = %DNS_RCODE_SERVFAIL
%DNS_RCODE_NAME_ERROR      = %DNS_RCODE_NXDOMAIN
%DNS_RCODE_NOT_IMPLEMENTED = %DNS_RCODE_NOTIMPL


'
'  DNS Classes
'
'  Classes are on the wire as WORDs.
'
'  _CLASS_ defines in host order.
'  _RCLASS_ defines in net byte order.
'
'  Generally we'll avoid byte flip and test class in net byte order.
'

%DNS_CLASS_INTERNET = &H0001      '  1
%DNS_CLASS_CSNET    = &H0002      '  2
%DNS_CLASS_CHAOS    = &H0003      '  3
%DNS_CLASS_HESIOD   = &H0004      '  4
%DNS_CLASS_NONE     = &H00fe      '  254
%DNS_CLASS_ALL      = &H00ff      '  255
%DNS_CLASS_ANY      = &H00ff      '  255

%DNS_RCLASS_INTERNET= &H0100      '  1
%DNS_RCLASS_CSNET   = &H0200      '  2
%DNS_RCLASS_CHAOS   = &H0300      '  3
%DNS_RCLASS_HESIOD  = &H0400      '  4
%DNS_RCLASS_NONE    = &Hfe00??    '  254
%DNS_RCLASS_ALL     = &Hff00??    '  255
%DNS_RCLASS_ANY     = &Hff00??    '  255



'
'  DNS Record Types
'
'  _TYPE_ defines are in host byte order.
'  _RTYPE_ defines are in net byte order.
'
'  Usually deal with types in host byte order as we index
'  resource record functions by type.
'

%DNS_TYPE_ZERO      = &H0000

'  RFC 1034/1035
%DNS_TYPE_A         = &H0001      '  1
%DNS_TYPE_NS        = &H0002      '  2
%DNS_TYPE_MD        = &H0003      '  3
%DNS_TYPE_MF        = &H0004      '  4
%DNS_TYPE_CNAME     = &H0005      '  5
%DNS_TYPE_SOA       = &H0006      '  6
%DNS_TYPE_MB        = &H0007      '  7
%DNS_TYPE_MG        = &H0008      '  8
%DNS_TYPE_MR        = &H0009      '  9
%DNS_TYPE_NULL      = &H000a      '  10
%DNS_TYPE_WKS       = &H000b      '  11
%DNS_TYPE_PTR       = &H000c      '  12
%DNS_TYPE_HINFO     = &H000d      '  13
%DNS_TYPE_MINFO     = &H000e      '  14
%DNS_TYPE_MX        = &H000f      '  15
%DNS_TYPE_TEXT      = &H0010      '  16

'  RFC 1183
%DNS_TYPE_RP        = &H0011      '  17
%DNS_TYPE_AFSDB     = &H0012      '  18
%DNS_TYPE_X25       = &H0013      '  19
%DNS_TYPE_ISDN      = &H0014      '  20
%DNS_TYPE_RT        = &H0015      '  21

'  RFC 1348
%DNS_TYPE_NSAP      = &H0016      '  22
%DNS_TYPE_NSAPPTR   = &H0017      '  23

'  RFC 2065    (DNS security)
%DNS_TYPE_SIG       = &H0018      '  24
%DNS_TYPE_KEY       = &H0019      '  25

'  RFC 1664    (X.400 mail)
%DNS_TYPE_PX        = &H001a      '  26

'  RFC 1712    (Geographic position)
%DNS_TYPE_GPOS      = &H001b      '  27

'  RFC 1886    (IPv6 Address)
%DNS_TYPE_AAAA      = &H001c      '  28

'  RFC 1876    (Geographic location)
%DNS_TYPE_LOC       = &H001d      '  29

'  RFC 2065    (Secure negative response)
%DNS_TYPE_NXT       = &H001e      '  30

'  Patton      (Endpoint Identifier)
%DNS_TYPE_EID       = &H001f      '  31

'  Patton      (Nimrod Locator)
%DNS_TYPE_NIMLOC    = &H0020      '  32

'  RFC 2052    (Service location)
%DNS_TYPE_SRV       = &H0021      '  33

'  ATM Standard something-or-another (ATM Address)
%DNS_TYPE_ATMA      = &H0022      '  34

'  RFC 2168    (Naming Authority Pointer)
%DNS_TYPE_NAPTR     = &H0023      '  35

'  RFC 2230    (Key Exchanger)
%DNS_TYPE_KX        = &H0024      '  36

'  RFC 2538    (CERT)
%DNS_TYPE_CERT      = &H0025      '  37

'  A6 Draft    (A6)
%DNS_TYPE_A6        = &H0026      '  38

'  DNAME Draft (DNAME)
%DNS_TYPE_DNAME     = &H0027      '  39

'  Eastlake    (Kitchen Sink)
%DNS_TYPE_SINK      = &H0028      '  40

'  RFC 2671    (EDNS OPT)
%DNS_TYPE_OPT       = &H0029      '  41

'  RFC 4034    (DNSSEC DS)
%DNS_TYPE_DS        = &H002b      '  43

'  RFC 4034    (DNSSEC RRSIG)
%DNS_TYPE_RRSIG     = &H002e      '  46

'  RFC 4034    (DNSSEC NSEC)
%DNS_TYPE_NSEC      = &H002f      '  47

'  RFC 4034    (DNSSEC DNSKEY)
%DNS_TYPE_DNSKEY    = &H0030      '  48

'  RFC 4701    (DHCID)
%DNS_TYPE_DHCID     = &H0031      '  49

'
'  IANA Reserved
'

%DNS_TYPE_UINFO     = &H0064      '  100
%DNS_TYPE_UID       = &H0065      '  101
%DNS_TYPE_GID       = &H0066      '  102
%DNS_TYPE_UNSPEC    = &H0067      '  103

'
'  Query only types (1035, 1995)
'      - Crawford      (ADDRS)
'      - TKEY draft    (TKEY)
'      - TSIG draft    (TSIG)
'      - RFC 1995      (IXFR)
'      - RFC 1035      (AXFR up)
'

%DNS_TYPE_ADDRS     = &H00f8      '  248
%DNS_TYPE_TKEY      = &H00f9      '  249
%DNS_TYPE_TSIG      = &H00fa      '  250
%DNS_TYPE_IXFR      = &H00fb      '  251
%DNS_TYPE_AXFR      = &H00fc      '  252
%DNS_TYPE_MAILB     = &H00fd      '  253
%DNS_TYPE_MAILA     = &H00fe      '  254
%DNS_TYPE_ALL       = &H00ff      '  255
%DNS_TYPE_ANY       = &H00ff      '  255

'
'  Temp Microsoft types -- use until get IANA approval for real type
'

%DNS_TYPE_WINS      = &Hff01??    '  64K - 255
%DNS_TYPE_WINSR     = &Hff02??    '  64K - 254
%DNS_TYPE_NBSTAT    = %DNS_TYPE_WINSR


'
'  DNS Record Types -- Net Byte Order
'

%DNS_RTYPE_A        = &H0100      '  1
%DNS_RTYPE_NS       = &H0200      '  2
%DNS_RTYPE_MD       = &H0300      '  3
%DNS_RTYPE_MF       = &H0400      '  4
%DNS_RTYPE_CNAME    = &H0500      '  5
%DNS_RTYPE_SOA      = &H0600      '  6
%DNS_RTYPE_MB       = &H0700      '  7
%DNS_RTYPE_MG       = &H0800      '  8
%DNS_RTYPE_MR       = &H0900      '  9
%DNS_RTYPE_NULL     = &H0a00      '  10
%DNS_RTYPE_WKS      = &H0b00      '  11
%DNS_RTYPE_PTR      = &H0c00      '  12
%DNS_RTYPE_HINFO    = &H0d00      '  13
%DNS_RTYPE_MINFO    = &H0e00      '  14
%DNS_RTYPE_MX       = &H0f00      '  15
%DNS_RTYPE_TEXT     = &H1000      '  16
%DNS_RTYPE_RP       = &H1100      '  17
%DNS_RTYPE_AFSDB    = &H1200      '  18
%DNS_RTYPE_X25      = &H1300      '  19
%DNS_RTYPE_ISDN     = &H1400      '  20
%DNS_RTYPE_RT       = &H1500      '  21
%DNS_RTYPE_NSAP     = &H1600      '  22
%DNS_RTYPE_NSAPPTR  = &H1700      '  23
%DNS_RTYPE_SIG      = &H1800      '  24
%DNS_RTYPE_KEY      = &H1900      '  25
%DNS_RTYPE_PX       = &H1a00      '  26
%DNS_RTYPE_GPOS     = &H1b00      '  27
%DNS_RTYPE_AAAA     = &H1c00      '  28
%DNS_RTYPE_LOC      = &H1d00      '  29
%DNS_RTYPE_NXT      = &H1e00      '  30
%DNS_RTYPE_EID      = &H1f00      '  31
%DNS_RTYPE_NIMLOC   = &H2000      '  32
%DNS_RTYPE_SRV      = &H2100      '  33
%DNS_RTYPE_ATMA     = &H2200      '  34
%DNS_RTYPE_NAPTR    = &H2300      '  35
%DNS_RTYPE_KX       = &H2400      '  36
%DNS_RTYPE_CERT     = &H2500      '  37
%DNS_RTYPE_A6       = &H2600      '  38
%DNS_RTYPE_DNAME    = &H2700      '  39
%DNS_RTYPE_SINK     = &H2800      '  40
%DNS_RTYPE_OPT      = &H2900      '  41

%DNS_RTYPE_DS       = &H2b00      '  43
%DNS_RTYPE_RRSIG    = &H2e00      '  46
%DNS_RTYPE_NSEC     = &H2f00      '  47
%DNS_RTYPE_DNSKEY   = &H3000      '  48
%DNS_RTYPE_DHCID    = &H3100      '  49

'
'  IANA Reserved
'

%DNS_RTYPE_UINFO    = &H6400      '  100
%DNS_RTYPE_UID      = &H6500      '  101
%DNS_RTYPE_GID      = &H6600      '  102
%DNS_RTYPE_UNSPEC   = &H6700      '  103

'
'  Query only types
'

%DNS_RTYPE_TKEY     = &Hf900??    '  249
%DNS_RTYPE_TSIG     = &Hfa00??    '  250
%DNS_RTYPE_IXFR     = &Hfb00??    '  251
%DNS_RTYPE_AXFR     = &Hfc00??    '  252
%DNS_RTYPE_MAILB    = &Hfd00??    '  253
%DNS_RTYPE_MAILA    = &Hfe00??    '  254
%DNS_RTYPE_ALL      = &Hff00??    '  255
%DNS_RTYPE_ANY      = &Hff00??    '  255

'
'  Temp Microsoft types -- use until get IANA approval for real type
'

%DNS_RTYPE_WINS     = &H01ff      '  64K - 255
%DNS_RTYPE_WINSR    = &H02ff      '  64K - 254




'
'  Record type specific definitions
'

'
'  ATMA (ATM address type) formats
'
'  Define these directly for any environment (ex NT4)
'  without winsock2 ATM support (ws2atm.h)
'

#IF NOT %DEF(%ATMA_E164)
%DNS_ATMA_FORMAT_E164          = 1
%DNS_ATMA_FORMAT_AESA          = 2
%DNS_ATMA_MAX_ADDR_LENGTH      = (20)
#ELSE
%DNS_ATMA_FORMAT_E164          = %ATM_E164
%DNS_ATMA_FORMAT_AESA          = %ATM_AESA
%DNS_ATMA_MAX_ADDR_LENGTH      = %ATM_ADDR_SIZE
#ENDIF

%DNS_ATMA_AESA_ADDR_LENGTH     = (20)
%DNS_ATMA_MAX_RECORD_LENGTH    = (%DNS_ATMA_MAX_ADDR_LENGTH+1)


'
'  DNSSEC defs
'

'  DNSSEC algorithms

%DNSSEC_ALGORITHM_RSAMD5   = 1
%DNSSEC_ALGORITHM_RSASHA1  = 5
%DNSSEC_ALGORITHM_NULL     = 253
%DNSSEC_ALGORITHM_PRIVATE  = 254

'  DNSSEC KEY protocol table

%DNSSEC_PROTOCOL_NONE      = 0
%DNSSEC_PROTOCOL_TLS       = 1
%DNSSEC_PROTOCOL_EMAIL     = 2
%DNSSEC_PROTOCOL_DNSSEC    = 3
%DNSSEC_PROTOCOL_IPSEC     = 4

'  DNSSEC KEY flag field

%DNSSEC_KEY_FLAG_NOAUTH         = &H0001
%DNSSEC_KEY_FLAG_NOCONF         = &H0002
%DNSSEC_KEY_FLAG_FLAG2          = &H0004
%DNSSEC_KEY_FLAG_EXTEND         = &H0008
%DNSSEC_KEY_FLAG = 0 ' [looks like a bug]
%DNSSEC_KEY_FLAG_FLAG4          = &H0010
%DNSSEC_KEY_FLAG_FLAG5          = &H0020

' bits 6,7 are name type

%DNSSEC_KEY_FLAG_USER           = &H0000
%DNSSEC_KEY_FLAG_ZONE           = &H0040
%DNSSEC_KEY_FLAG_HOST           = &H0080
%DNSSEC_KEY_FLAG_NTPE3          = &H00c0

' bits 8-11 are reserved for future use

%DNSSEC_KEY_FLAG_FLAG8          = &H0100
%DNSSEC_KEY_FLAG_FLAG9          = &H0200
%DNSSEC_KEY_FLAG_FLAG10         = &H0400
%DNSSEC_KEY_FLAG_FLAG11         = &H0800

' bits 12-15 are sig field

%DNSSEC_KEY_FLAG_SIG0           = &H0000
%DNSSEC_KEY_FLAG_SIG1           = &H1000
%DNSSEC_KEY_FLAG_SIG2           = &H2000
%DNSSEC_KEY_FLAG_SIG3           = &H3000
%DNSSEC_KEY_FLAG_SIG4           = &H4000
%DNSSEC_KEY_FLAG_SIG5           = &H5000
%DNSSEC_KEY_FLAG_SIG6           = &H6000
%DNSSEC_KEY_FLAG_SIG7           = &H7000
%DNSSEC_KEY_FLAG_SIG8           = &H8000??
%DNSSEC_KEY_FLAG_SIG9           = &H9000??
%DNSSEC_KEY_FLAG_SIG10          = &Ha000??
%DNSSEC_KEY_FLAG_SIG11          = &Hb000??
%DNSSEC_KEY_FLAG_SIG12          = &Hc000??
%DNSSEC_KEY_FLAG_SIG13          = &Hd000??
%DNSSEC_KEY_FLAG_SIG14          = &He000??
%DNSSEC_KEY_FLAG_SIG15          = &Hf000??


'
'  TKEY modes
'

%DNS_TKEY_MODE_SERVER_ASSIGN       = 1
%DNS_TKEY_MODE_DIFFIE_HELLMAN      = 2
%DNS_TKEY_MODE_GSS                 = 3
%DNS_TKEY_MODE_RESOLVER_ASSIGN     = 4

'
'  WINS + NBSTAT flag field
'

%DNS_WINS_FLAG_SCOPE   = &H80000000???
%DNS_WINS_FLAG_LOCAL   = &H00010000


'
'  Helpful checks
'

MACRO IS_WORD_ALIGNED(p) =(NOT ((p) AND 1))
MACRO IS_DWORD_ALIGNED(p)=(NOT ((p) AND 3))
MACRO IS_QWORD_ALIGNED(p)=(NOT ((p) AND 7))




'
'  DNS config API
'

'
'  Types of DNS configuration info
'

MACRO DNS_CONFIG_TYPE_enum=LONG
ENUM DNS_CONFIG_TYPE SINGULAR
    '  In Win2K
    DnsConfigPrimaryDomainName_W
    DnsConfigPrimaryDomainName_A
    DnsConfigPrimaryDomainName_UTF8

    '  Not available yet
    DnsConfigAdapterDomainName_W
    DnsConfigAdapterDomainName_A
    DnsConfigAdapterDomainName_UTF8

    '  In Win2K
    DnsConfigDnsServerList

    '  Not available yet
    DnsConfigSearchList
    DnsConfigAdapterInfo

    '  In Win2K
    DnsConfigPrimaryHostNameRegistrationEnabled
    DnsConfigAdapterHostNameRegistrationEnabled
    DnsConfigAddressRegistrationMaxCount

    '  In WindowsXP
    DnsConfigHostName_W
    DnsConfigHostName_A
    DnsConfigHostName_UTF8
    DnsConfigFullHostName_W
    DnsConfigFullHostName_A
    DnsConfigFullHostName_UTF8

    '  In XP-SP1 (Server.net)
END ENUM  ' DNS_CONFIG_TYPE

'
'  Config API flags
'

'
'  DNS_CONFIG_FLAG_ALLOC -- Causes config info to be allocated.
'      Free with LocalFree().
'
%DNS_CONFIG_FLAG_ALLOC = &H00000001

DECLARE FUNCTION DnsQueryConfig LIB "DnsApi.dll" ALIAS "DnsQueryConfig" ( _
    BYVAL Config   AS DNS_CONFIG_TYPE_enum, _
    BYVAL Flag     AS DWORD, _
    pwsAdapterName AS WSTRINGZ, _
    pReserved      AS ANY, _   ' PVOID
    pBuffer        AS ANY, _   ' PVOID
    pBufLen        AS DWORD _
    ) AS LONG



'
'  DNS resource record structure
'

'
'  Record data for specific types
'

TYPE DNS_A_DATA
    IpAddress AS IP4_ADDRESS
END TYPE

TYPE DNS_PTR_DATAW
    pNameHost AS WSTRINGZ PTR
END TYPE

TYPE DNS_PTR_DATAA
    pNameHost AS ASCIIZ PTR
END TYPE

TYPE DNS_SOA_DATAW
    pNamePrimaryServer AS WSTRINGZ PTR
    pNameAdministrator AS WSTRINGZ PTR
    dwSerialNo         AS DWORD
    dwRefresh          AS DWORD
    dwRetry            AS DWORD
    dwExpire           AS DWORD
    dwDefaultTtl       AS DWORD
END TYPE

TYPE DNS_SOA_DATAA
    pNamePrimaryServer AS ASCIIZ PTR
    pNameAdministrator AS ASCIIZ PTR
    dwSerialNo         AS DWORD
    dwRefresh          AS DWORD
    dwRetry            AS DWORD
    dwExpire           AS DWORD
    dwDefaultTtl       AS DWORD
END TYPE

TYPE DNS_MINFO_DATAW
    pNameMailbox       AS WSTRINGZ PTR
    pNameErrorsMailbox AS WSTRINGZ PTR
END TYPE

TYPE DNS_MINFO_DATAA
    pNameMailbox       AS ASCIIZ PTR
    pNameErrorsMailbox AS ASCIIZ PTR
END TYPE


TYPE DNS_MX_DATAW
    pNameExchange AS WSTRINGZ PTR
    wPreference   AS WORD
    Pad           AS WORD      ' keep ptrs DWORD aligned
END TYPE

TYPE DNS_MX_DATAA
    pNameExchange AS ASCIIZ PTR
    wPreference   AS WORD
    Pad           AS WORD      ' keep ptrs DWORD aligned
END TYPE

TYPE DNS_TXT_DATAW
    dwStringCount   AS DWORD
    pStringArray(0) AS WSTRINGZ PTR
END TYPE

TYPE DNS_TXT_DATAA
    dwStringCount   AS DWORD
    pStringArray(0) AS ASCIIZ PTR
END TYPE

TYPE DNS_NULL_DATA
    dwByteCount AS DWORD
    DATA(0)     AS BYTE
END TYPE

TYPE DNS_WKS_DATA
    IpAddress  AS IP4_ADDRESS
    chProtocol AS BYTE
    BitMask(0) AS BYTE
END TYPE

TYPE DNS_AAAA_DATA
    Ip6Address AS IP6_ADDRESS
END TYPE

TYPE DNS_SIG_DATAW
    wTypeCovered     AS WORD
    chAlgorithm      AS BYTE
    chLabelCount     AS BYTE
    dwOriginalTtl    AS DWORD
    dwExpiration     AS DWORD
    dwTimeSigned     AS DWORD
    wKeyTag          AS WORD
    wSignatureLength AS WORD
    pNameSigner      AS WSTRINGZ PTR
    Signature(0)     AS BYTE
END TYPE

TYPE DNS_RRSIG_DATAW
    DNS_SIG_DATAW
END TYPE

TYPE DNS_SIG_DATAA
    wTypeCovered     AS WORD
    chAlgorithm      AS BYTE
    chLabelCount     AS BYTE
    dwOriginalTtl    AS DWORD
    dwExpiration     AS DWORD
    dwTimeSigned     AS DWORD
    wKeyTag          AS WORD
    wSignatureLength AS WORD
    pNameSigner      AS ASCIIZ PTR
    Signature(0)     AS BYTE
END TYPE

TYPE DNS_RRSIG_DATAA
    DNS_SIG_DATAA
END TYPE

TYPE DNS_KEY_DATA
    wFlags      AS WORD
    chProtocol  AS BYTE
    chAlgorithm AS BYTE
    wKeyLength  AS WORD
    wPad        AS WORD    ' keep byte field aligned
    KEY(0)      AS BYTE
END TYPE

TYPE DNS_DNSKEY_DATA
    DNS_KEY_DATA
END TYPE

TYPE DNS_DHCID_DATA
    dwByteCount AS DWORD
    DHCID(0)    AS BYTE
END TYPE

TYPE DNS_NSEC_DATAW
    pNextDomainName    AS WSTRINGZ PTR
    wTypeBitMapsLength AS WORD
    wPad               AS WORD        ' keep byte field aligned
    TypeBitMaps(0)     AS BYTE
END TYPE

TYPE DNS_NSEC_DATAA
    pNextDomainName    AS ASCIIZ PTR
    wTypeBitMapsLength AS WORD
    wPad               AS WORD        ' keep byte field aligned
    TypeBitMaps(0)     AS BYTE
END TYPE

TYPE DNS_DS_DATA
    wKeyTag       AS WORD
    chAlgorithm   AS BYTE
    chDigestType  AS BYTE
    wDigestLength AS WORD
    wPad          AS WORD     ' keep byte field aligned
    Digest(0)     AS BYTE
END TYPE

TYPE DNS_OPT_DATA
    wDataLength AS WORD
    wPad        AS WORD       ' keep byte field aligned
    DATA(0)     as BYTE
END TYPE

TYPE DNS_LOC_DATA
    wVersion    AS WORD
    wSize       AS WORD
    wHorPrec    AS WORD
    wVerPrec    AS WORD
    dwLatitude  AS DWORD
    dwLongitude AS DWORD
    dwAltitude  AS DWORD
END TYPE

TYPE DNS_NXT_DATAW
    pNameNext AS WSTRINGZ PTR
    wNumTypes AS WORD
    wTypes(0) AS WORD
END TYPE

TYPE DNS_NXT_DATAA
    pNameNext AS ASCIIZ PTR
    wNumTypes AS WORD
    wTypes(0) AS WORD
END TYPE

TYPE DNS_SRV_DATAW
    pNameTarget AS WSTRINGZ PTR
    wPriority   AS WORD
    wWeight     AS WORD
    wPort       AS WORD
    Pad         AS WORD     ' keep ptrs DWORD aligned
END TYPE

TYPE DNS_SRV_DATAA
    pNameTarget AS ASCIIZ PTR
    wPriority   AS WORD
    wWeight     AS WORD
    wPort       AS WORD
    Pad         AS WORD     ' keep ptrs DWORD aligned
END TYPE

TYPE DNS_NAPTR_DATAW
    wOrder             AS WORD
    wPreference        AS WORD
    pFlags             AS WSTRINGZ PTR
    pService           AS WSTRINGZ PTR
    pRegularExpression AS WSTRINGZ PTR
    pReplacement       AS WSTRINGZ PTR
END TYPE

TYPE DNS_NAPTR_DATAA
    wOrder             AS WORD
    wPreference        AS WORD
    pFlags             AS ASCIIZ PTR
    pService           AS ASCIIZ PTR
    pRegularExpression AS ASCIIZ PTR
    pReplacement       AS ASCIIZ PTR
END TYPE



TYPE DNS_ATMA_DATA
    AddressType AS BYTE
    Address(%DNS_ATMA_MAX_ADDR_LENGTH-1) AS BYTE

    '  E164 -- Null terminated string of less than
    '      DNS_ATMA_MAX_ADDR_LENGTH
    '
    '  For NSAP (AESA) BCD encoding of exactly
    '      DNS_ATMA_AESA_ADDR_LENGTH
END TYPE


TYPE DNS_TKEY_DATAW
    pNameAlgorithm   AS WSTRINGZ PTR
    pAlgorithmPacket AS BYTE PTR
    pKey             AS BYTE PTR
    pOtherData       AS BYTE PTR
    dwCreateTime     AS DWORD
    dwExpireTime     AS DWORD
    wMode            AS WORD
    wError           AS WORD
    wKeyLength       AS WORD
    wOtherLength     AS WORD
    cAlgNameLength   AS BYTE
    bPacketPointers  AS LONG  ' BOOL
END TYPE

TYPE DNS_TKEY_DATAA
    pNameAlgorithm   AS ASCIIZ PTR
    pAlgorithmPacket AS BYTE PTR
    pKey             AS BYTE PTR
    pOtherData       AS BYTE PTR
    dwCreateTime     AS DWORD
    dwExpireTime     AS DWORD
    wMode            AS WORD
    wError           AS WORD
    wKeyLength       AS WORD
    wOtherLength     AS WORD
    cAlgNameLength   AS BYTE
    bPacketPointers  AS LONG  ' BOOL
END TYPE

TYPE DNS_TSIG_DATAW
    pNameAlgorithm   AS WSTRINGZ PTR
    pAlgorithmPacket AS BYTE PTR
    pSignature       AS BYTE PTR
    pOtherData       AS BYTE PTR
    i64CreateTime    AS QUAD
    wFudgeTime       AS WORD
    wOriginalXid     AS WORD
    wError           AS WORD
    wSigLength       AS WORD
    wOtherLength     AS WORD
    cAlgNameLength   AS BYTE
    bPacketPointers  AS LONG  ' BOOL
END TYPE

TYPE DNS_TSIG_DATAA
    pNameAlgorithm   AS ASCIIZ PTR
    pAlgorithmPacket AS BYTE PTR
    pSignature       AS BYTE PTR
    pOtherData       AS BYTE PTR
    i64CreateTime    AS QUAD
    wFudgeTime       AS WORD
    wOriginalXid     AS WORD
    wError           AS WORD
    wSigLength       AS WORD
    wOtherLength     AS WORD
    cAlgNameLength   AS BYTE
    bPacketPointers  AS LONG  ' BOOL
END TYPE

'
'  MS only types -- only hit the wire in MS-MS zone transfer
'

TYPE DNS_WINS_DATA
    dwMappingFlag    AS DWORD
    dwLookupTimeout  AS DWORD
    dwCacheTimeout   AS DWORD
    cWinsServerCount AS DWORD
    WinsServers(0)   AS IP4_ADDRESS
END TYPE

TYPE DNS_WINSR_DATAW
    dwMappingFlag     AS DWORD
    dwLookupTimeout   AS DWORD
    dwCacheTimeout    AS DWORD
    pNameResultDomain AS WSTRINGZ PTR
END TYPE

TYPE DNS_WINSR_DATAA
    dwMappingFlag     AS DWORD
    dwLookupTimeout   AS DWORD
    dwCacheTimeout    AS DWORD
    pNameResultDomain AS ASCIIZ PTR
END TYPE

'
'  Unicode/ANSI record types
'

#IF %DEF(%UNICODE)
TYPE DNS_PTR_DATA
    DNS_PTR_DATAW
END TYPE
TYPE DNS_SOA_DATA
    DNS_SOA_DATAW
END TYPE
TYPE DNS_MINFO_DATA
    DNS_MINFO_DATAW
END TYPE
TYPE DNS_MX_DATA
    DNS_MX_DATAW
END TYPE
TYPE DNS_TXT_DATA
    DNS_TXT_DATAW
END TYPE
TYPE DNS_SIG_DATA
    DNS_SIG_DATAW
END TYPE
TYPE DNS_NXT_DATA
    DNS_NXT_DATAW
END TYPE
TYPE DNS_SRV_DATA
    DNS_SRV_DATAW
END TYPE
TYPE DNS_NAPTR_DATA
    DNS_NAPTR_DATAW
END TYPE
TYPE DNS_RRSIG_DATA
    DNS_RRSIG_DATAW
END TYPE
TYPE DNS_NSEC_DATA
    DNS_NSEC_DATAW
END TYPE
TYPE DNS_TKEY_DATA
    DNS_TKEY_DATAW
END TYPE
TYPE DNS_TSIG_DATA
    DNS_TSIG_DATAW
END TYPE
TYPE DNS_WINSR_DATA
    DNS_WINSR_DATAW
END TYPE
#ELSE
TYPE DNS_PTR_DATA
    DNS_PTR_DATAA
END TYPE
TYPE DNS_SOA_DATA
    DNS_SOA_DATAA
END TYPE
TYPE DNS_MINFO_DATA
    DNS_MINFO_DATAA
END TYPE
TYPE DNS_MX_DATA
    DNS_MX_DATAA
END TYPE
TYPE DNS_TXT_DATA
    DNS_TXT_DATAA
END TYPE
TYPE DNS_SIG_DATA
    DNS_SIG_DATAA
END TYPE
TYPE DNS_NXT_DATA
    DNS_NXT_DATAA
END TYPE
TYPE DNS_SRV_DATA
    DNS_SRV_DATAA
END TYPE
TYPE DNS_NAPTR_DATA
    DNS_NAPTR_DATAA
END TYPE
TYPE DNS_RRSIG_DATA
    DNS_RRSIG_DATAA
END TYPE
TYPE DNS_NSEC_DATA
    DNS_NSEC_DATAA
END TYPE
TYPE DNS_TKEY_DATA
    DNS_TKEY_DATAA
END TYPE
TYPE DNS_TSIG_DATA
    DNS_TSIG_DATAA
END TYPE
TYPE DNS_WINSR_DATA
    DNS_WINSR_DATAA
END TYPE
#ENDIF

'
'  Length of non-fixed-length data types
'

'#define DNS_TEXT_RECORD_LENGTH(StringCount)  _
'            (FIELD_OFFSET(DNS_TXT_DATA, pStringArray) + ((StringCount) * sizeof(PCHAR)))
'
'#define DNS_NULL_RECORD_LENGTH(ByteCount)  _
'            (FIELD_OFFSET(DNS_NULL_DATA, Data) + (ByteCount))
'
'#define DNS_WKS_RECORD_LENGTH(ByteCount)  _
'            (FIELD_OFFSET(DNS_WKS_DATA, BitMask) + (ByteCount))
'
'#define DNS_WINS_RECORD_LENGTH(IpCount)  _
'            (FIELD_OFFSET(DNS_WINS_DATA, WinsServers) + ((IpCount) * sizeof(IP4_ADDRESS)))
'
'#define DNS_KEY_RECORD_LENGTH(ByteCount)  _
'            (FIELD_OFFSET(DNS_KEY_DATA, Key) + (ByteCount))
'
'#define DNS_SIG_RECORD_LENGTH(ByteCount)  _
'            (FIELD_OFFSET(DNS_SIG_DATA, Signature) + (ByteCount))
'
'#define DNS_NSEC_RECORD_LENGTH(ByteCount)  _
'            (FIELD_OFFSET(DNS_NSEC_DATA, TypeBitMaps) + (ByteCount))
'
'#define DNS_DS_RECORD_LENGTH(ByteCount)  _
'            (FIELD_OFFSET(DNS_DS_DATA, Digest) + (ByteCount))
'
'#define DNS_OPT_RECORD_LENGTH(ByteCount)  _
'            (FIELD_OFFSET(DNS_OPT_DATA, Data) + (ByteCount))
'
'#define DNS_DHCID_RECORD_LENGTH(ByteCount)  _
'            (FIELD_OFFSET(DNS_DHCID_DATA, DHCID) + (ByteCount))

'
'  Record flags
'

TYPE DNS_RECORD_FLAGS
    Section  AS BIT * 2 IN DWORD
    DELETE   AS BIT * 1
    CharSet  AS BIT * 2
    Unused   AS BIT * 3

    Reserved AS BIT * 24
END TYPE


'
'  Wire Record Sections
'
'  Useable both in record flags "Section" and as index into
'  wire message header section counts.
'

MACRO DNS_SECTION_enum=LONG
ENUM DNS_SECTION SINGULAR
    DnsSectionQuestion
    DnsSectionAnswer
    DnsSectionAuthority
    DnsSectionAddtional
END ENUM

'  Update message section names

%DnsSectionZone   = %DnsSectionQuestion
%DnsSectionPrereq = %DnsSectionAnswer
%DnsSectionUpdate = %DnsSectionAuthority

'
'  Record flags as bit flags
'  These may be or'd together to set the fields
'

'  RR Section in packet

%DNSREC_SECTION      = &H00000003

%DNSREC_QUESTION     = &H00000000
%DNSREC_ANSWER       = &H00000001
%DNSREC_AUTHORITY    = &H00000002
%DNSREC_ADDITIONAL   = &H00000003

'  RR Section in packet (update)

%DNSREC_ZONE         = &H00000000
%DNSREC_PREREQ       = &H00000001
%DNSREC_UPDATE       = &H00000002

'  Delete RR (update) or No-exist (prerequisite)

%DNSREC_DELETE       = &H00000004
%DNSREC_NOEXIST      = &H00000004


'
'  Record \ RR set structure
'
'  Note:  The dwReserved flag serves to insure that the substructures
'  start on 64-bit boundaries.  Do NOT pack this structure, as the
'  substructures may contain pointers or int64 values which are
'  properly aligned unpacked.
'

UNION DNS_RECORDW_union1
    DW AS DWORD                    ' flags as DWORD
    S  AS DNS_RECORD_FLAGS         ' flags as structure
END UNION

UNION DNS_RECORDW_union2
    A      AS DNS_A_DATA
    Soa    AS DNS_SOA_DATAW
    PTR    AS DNS_PTR_DATAW
    Ns     AS DNS_PTR_DATAW
    Cname  AS DNS_PTR_DATAW
    Dname  AS DNS_PTR_DATAW
    Mb     AS DNS_PTR_DATAW
    Md     AS DNS_PTR_DATAW
    Mf     AS DNS_PTR_DATAW
    Mg     AS DNS_PTR_DATAW
    Mr     AS DNS_PTR_DATAW
    MInfo  AS DNS_MINFO_DATAW
    Rp     AS DNS_MINFO_DATAW
    Mx     AS DNS_MX_DATAW
    AfsDb  AS DNS_MX_DATAW
    Rt     AS DNS_MX_DATAW
    Hinfo  AS DNS_TXT_DATAW
    Isdn   AS DNS_TXT_DATAW
    TXT    AS DNS_TXT_DATAW
    X25    AS DNS_TXT_DATAW
    NULL   AS DNS_NULL_DATA
    Wks    AS DNS_WKS_DATA
    AAAA   AS DNS_AAAA_DATA
    KEY    AS DNS_KEY_DATA
    Sig    AS DNS_SIG_DATAW
    Atma   AS DNS_ATMA_DATA
    Nxt    AS DNS_NXT_DATAW
    Srv    AS DNS_SRV_DATAW
    Naptr  AS DNS_NAPTR_DATAW
    OPT    AS DNS_OPT_DATA
    Ds     AS DNS_DS_DATA
    Rrsig  AS DNS_RRSIG_DATAW
    Nsec   AS DNS_NSEC_DATAW
    Dnskey AS DNS_DNSKEY_DATA
    Tkey   AS DNS_TKEY_DATAW
    Tsig   AS DNS_TSIG_DATAW
    Wins   AS DNS_WINS_DATA
    WinsR  AS DNS_WINSR_DATAW
    Nbstat AS DNS_WINSR_DATAW
    DHCID  AS DNS_DHCID_DATA
END UNION

TYPE DNS_RECORDW
    pNext       AS DNS_RECORDW PTR
    pName       AS WSTRINGZ PTR
    wType       AS WORD
    wDataLength AS WORD   ' Not referenced for DNS record types defined above.
    Flags       AS DNS_RECORDW_union1

    dwTtl       AS DWORD
    dwReserved  AS DWORD

    '  Record Data

    DATA        AS DNS_RECORDW_union2
END TYPE  ' DNS_RECORDW

UNION DNS_RECORD_OPTW_union1
    DW AS DWORD                    ' flags as DWORD
    S  AS DNS_RECORD_FLAGS         ' flags as structure
END UNION

UNION DNS_RECORD_OPTW_union2
    OPT AS DNS_OPT_DATA
END UNION

TYPE DNS_RECORD_OPTW
    pNext        AS DNS_RECORD_OPTW PTR
    pName        AS WSTRINGZ PTR
    wType        AS WORD
    wDataLength  AS WORD   ' Not referenced for DNS record types defined above.
    Flags        AS DNS_RECORD_OPTW_union1

    ExtHeader    AS DNS_HEADER_EXT     ' TTL
    wPayloadSize AS WORD               ' dwReserved
    wReserved    AS WORD

    '  Record Data
    DATA         AS DNS_RECORD_OPTW_union2
END TYPE  ' DNS_RECORD_OPTW


UNION DNS_RECORDA_union1
    DW AS DWORD                    ' flags as DWORD
    S  AS DNS_RECORD_FLAGS         ' flags as structure
END UNION

UNION DNS_RECORDA_union2
    A      AS DNS_A_DATA
    Soa    AS DNS_SOA_DATAA
    PTR    AS DNS_PTR_DATAA
    Ns     AS DNS_PTR_DATAA
    Cname  AS DNS_PTR_DATAA
    Dname  AS DNS_PTR_DATAA
    Mb     AS DNS_PTR_DATAA
    Md     AS DNS_PTR_DATAA
    Mf     AS DNS_PTR_DATAA
    Mg     AS DNS_PTR_DATAA
    Mr     AS DNS_PTR_DATAA
    MInfo  AS DNS_MINFO_DATAA
    Rp     AS DNS_MINFO_DATAA
    Mx     AS DNS_MX_DATAA
    AfsDb  AS DNS_MX_DATAA
    Rt     AS DNS_MX_DATAA
    Hinfo  AS DNS_TXT_DATAA
    Isdn   AS DNS_TXT_DATAA
    TXT    AS DNS_TXT_DATAA
    X25    AS DNS_TXT_DATAA
    NULL   AS DNS_NULL_DATA
    Wks    AS DNS_WKS_DATA
    AAAA   AS DNS_AAAA_DATA
    KEY    AS DNS_KEY_DATA
    Sig    AS DNS_SIG_DATAA
    Atma   AS DNS_ATMA_DATA
    Nxt    AS DNS_NXT_DATAA
    Srv    AS DNS_SRV_DATAA
    Naptr  AS DNS_NAPTR_DATAA
    OPT    AS DNS_OPT_DATA
    Ds     AS DNS_DS_DATA
    Rrsig  AS DNS_RRSIG_DATAA
    Nsec   AS DNS_NSEC_DATAA
    Dnskey AS DNS_DNSKEY_DATA
    Tkey   AS DNS_TKEY_DATAA
    Tsig   AS DNS_TSIG_DATAA
    Wins   AS DNS_WINS_DATA
    WinsR  AS DNS_WINSR_DATAA
    Nbstat AS DNS_WINSR_DATAA
    DHCID  AS DNS_DHCID_DATA
END UNION

TYPE DNS_RECORDA
    pNext       AS DNS_RECORDA PTR
    pName       AS ASCIIZ PTR
    wType       AS WORD
    wDataLength AS WORD   ' Not referenced for DNS record types defined above.
    Flags       AS DNS_RECORDA_union1

    dwTtl       AS DWORD
    dwReserved  AS DWORD

    '  Record Data

    DATA        AS DNS_RECORDA_union2
END TYPE  ' DNS_RECORDA

UNION DNS_RECORD_OPTA_union1
    DW AS DWORD                    ' flags as DWORD
    S  AS DNS_RECORD_FLAGS         ' flags as structure
END UNION

UNION DNS_RECORD_OPTA_union2
    OPT AS DNS_OPT_DATA
END UNION

TYPE DNS_RECORD_OPTA
    pNext        AS DNS_RECORD_OPTA PTR
    pName        AS ASCIIZ PTR
    wType        AS WORD
    wDataLength  AS WORD   ' Not referenced for DNS record types defined above.
    Flags        AS DNS_RECORD_OPTA_union1

    ExtHeader    AS DNS_HEADER_EXT     ' TTL
    wPayloadSize AS WORD               ' dwReserved
    wReserved    AS WORD

    '  Record Data
    DATA         AS DNS_RECORD_OPTA_union2
END TYPE  ' DNS_RECORD_OPTA


#IF %DEF(%UNICODE)
TYPE DNS_RECORD
    DNS_RECORDW
END TYPE
TYPE DNS_RECORD_OPT
    DNS_RECORD_OPTW
END TYPE
#ELSE
TYPE DNS_RECORD
    DNS_RECORDA
END TYPE
TYPE DNS_RECORD_OPT
    DNS_RECORD_OPTA
END TYPE
#ENDIF

'
'  Header or fixed size of DNS_RECORD
'

'#define DNS_RECORD_FIXED_SIZE       FIELD_OFFSET( DNS_RECORD, Data )
'#define SIZEOF_DNS_RECORD_HEADER    DNS_RECORD_FIXED_SIZE



'
'  Resource record set building
'
'  pFirst points to first record in list.
'  pLast points to last record in list.
'

TYPE DNS_RRSET
    pFirstRR AS DNS_RECORD PTR
    pLastRR  AS DNS_RECORD PTR
END TYPE


'
'  To init pFirst is NULL.
'  But pLast points at the location of the pFirst pointer -- essentially
'  treating the pFirst ptr as a DNS_RECORD.  (It is a DNS_RECORD with
'  only a pNext field, but that's the only part we use.)
'
'  Then when the first record is added to the list, the pNext field of
'  this dummy record (which corresponds to pFirst's value) is set to
'  point at the first record.  So pFirst then properly points at the
'  first record.
'
'  (This works only because pNext is the first field in a
'  DNS_RECORD structure and hence casting a PDNS_RECORD ptr to
'  PDNS_RECORD* and dereferencing yields its pNext field)
'
'  Use TERMINATE when have built RR set by grabbing records out of
'  existing set.   This makes sure that at the end, the last RR is
'  properly NULL terminated.
'

'#define DNS_RRSET_INIT( rrset )                  _
'        {                                        _
'            PDNS_RRSET  _prrset = &(rrset);      _
'            _prrset->pFirstRR = NULL;            _
'            _prrset->pLastRR = (PDNS_RECORD) &_prrset->pFirstRR;  _
'        }
'
'#define DNS_RRSET_ADD( rrset, pnewRR )           _
'        {                                        _
'            PDNS_RRSET  _prrset = &(rrset);      _
'            PDNS_RECORD _prrnew = (pnewRR);      _
'            _prrset->pLastRR->pNext = _prrnew;   _
'            _prrset->pLastRR = _prrnew;          _
'        }
'
'#define DNS_RRSET_TERMINATE( rrset )             _
'        {                                        _
'            PDNS_RRSET  _prrset = &(rrset);      _
'            _prrset->pLastRR->pNext = NULL;      _
'        }



DECLARE SUB DNS_PROXY_COMPLETION_ROUTINE ( _
    completionContext AS ANY, _  ' void *
    BYVAL STATUS AS DNS_STATUS)


MACRO DNS_PROXY_INFORMATION_TYPE_enum=LONG
ENUM DNS_PROXY_INFORMATION_TYPE SINGULAR
    DNS_PROXY_INFORMATION_DIRECT
    DNS_PROXY_INFORMATION_DEFAULT_SETTINGS
    DNS_PROXY_INFORMATION_PROXY_NAME
    DNS_PROXY_INFORMATION_DOES_NOT_EXIST
END ENUM

TYPE DNS_PROXY_INFORMATION
    version              AS DWORD  ' Current version is 1
    proxyInformationType AS DNS_PROXY_INFORMATION_TYPE_enum
    proxyName            AS WSTRINGZ PTR
END TYPE

'
'  Record set manipulation
'

'
'  Record Copy
'  Record copy functions also do conversion between character sets.
'
'  Note, it might be advisable to directly expose non-Ex copy
'  functions _W, _A for record and set, to avoid exposing the
'  conversion enum.
'

MACRO DNS_CHARSET_enum=LONG
ENUM DNS_CHARSET SINGULAR
    DnsCharSetUnknown
    DnsCharSetUnicode
    DnsCharSetUtf8
    DnsCharSetAnsi
END ENUM


DECLARE FUNCTION DnsRecordCopyEx LIB "DnsApi.dll" ALIAS "DnsRecordCopyEx" ( _
    pRecord AS DNS_RECORD, _
    BYVAL CharSetIn  AS DNS_CHARSET_enum, _
    BYVAL CharSetOut AS DNS_CHARSET_enum _
    ) AS DWORD  ' DNS_RECORD PTR

DECLARE FUNCTION DnsRecordSetCopyEx LIB "DnsApi.dll" _
    ALIAS "DnsRecordSetCopyEx" ( _
    BYVAL pRecordSet AS DNS_RECORD PTR, _
    BYVAL CharSetIn AS DNS_CHARSET_enum, _
    BYVAL CharSetOut AS DNS_CHARSET_enum _
    ) AS DWORD  ' DNS_RECORD PTR

#IF %DEF(%UNICODE)
MACRO DnsRecordCopy(pRR)=DnsRecordCopyEx((pRR), DnsCharSetUnicode, DnsCharSetUnicode)
MACRO DnsRecordSetCopy(pRR)=DnsRecordSetCopyEx((pRR), DnsCharSetUnicode, DnsCharSetUnicode)
#ELSE
MACRO DnsRecordCopy(pRR)=DnsRecordCopyEx((pRR), DnsCharSetAnsi, DnsCharSetAnsi)
MACRO DnsRecordSetCopy(pRR)=DnsRecordSetCopyEx((pRR), DnsCharSetAnsi, DnsCharSetAnsi)
#ENDIF


'
'  Record Compare
'
'  Note:  these routines only compare records of the SAME character set.
'  (ANSI, unicode or UTF8).  Furthermore the routines assume the character
'  set is indicated within the record.  If compare of user created, rather
'  than DNS API created record lists is desired, then caller should use
'  DnsRecordCopy API and compare copies.
'

DECLARE FUNCTION DnsRecordCompare LIB "DnsApi.dll" _
    ALIAS "DnsRecordCompare" ( _
    pRecord1 AS DNS_RECORD, _
    pRecord2 AS DNS_RECORD _
    ) AS LONG  ' BOOL

DECLARE FUNCTION DnsRecordSetCompare LIB "DnsApi.dll" _
    ALIAS "DnsRecordSetCompare" ( _
    pRR1    AS DNS_RECORD, _
    pRR2    AS DNS_RECORD, _
    ppDiff1 AS ANY, _  ' DNS_RECORD PTR PTR
    ppDiff2 AS ANY _   ' DNS_RECORD PTR PTR
    ) AS LONG  ' BOOL

'
'  Detach next record set from record list
'


DECLARE FUNCTION DnsRecordSetDetach LIB "DnsApi.dll" _
    ALIAS "DnsRecordSetDetach" ( _
    pRecordList AS DNS_RECORD _
    ) AS DWORD  ' DNS_RECORD PTR

'
'  Free structures returned from dnsapi.dll
'
'  Currently supported free structures:
'      Flat -- flat structure, including those allocated by DnsQueryConfig()
'      RecordList -- deep record list free, including sub-fields of DNS_RECORD;
'          includes those returned by DnsQuery() or DnsRecordSetCopy()
'

MACRO DNS_FREE_TYPE_enum=LONG
ENUM DNS_FREE_TYPE SINGULAR
    DnsFreeFlat
    DnsFreeRecordList
    DnsFreeParsedMessageFields
END ENUM

DECLARE SUB DnsFree LIB "DnsApi.dll" ALIAS "DnsFree" ( _
    pData    AS ANY, _  ' PVOID
    FreeType AS DNS_FREE_TYPE_enum _
    )

'
'  Backward compatibility with Win2K, do not use for XP+ applications
'
'  To free record lists, code
'      DnsFree( pRecordList, DnsFreeRecordList );
'

%DnsFreeRecordListDeep = %DnsFreeRecordList

#IF (%WIN32_WINNT >= &H0501)
MACRO DnsRecordListFree(p,t)=DnsFree(p,%DnsFreeRecordList)
#ELSE
DECLARE SUB DnsRecordListFree LIB "DnsApi.dll" ALIAS "DnsRecordListFree" ( _
    pRecordList AS DNS_RECORD, _
    FreeType    AS DNS_FREE_TYPE )
    
#ENDIF ' %WIN32_WINNT >= &H0501



'
'  DNS Query API
'

'
'  Options for DnsQuery
'

%DNS_QUERY_STANDARD                  = &H00000000
%DNS_QUERY_ACCEPT_TRUNCATED_RESPONSE = &H00000001
%DNS_QUERY_USE_TCP_ONLY              = &H00000002
%DNS_QUERY_NO_RECURSION              = &H00000004
%DNS_QUERY_BYPASS_CACHE              = &H00000008

%DNS_QUERY_NO_WIRE_QUERY             = &H00000010
%DNS_QUERY_NO_LOCAL_NAME             = &H00000020
%DNS_QUERY_NO_HOSTS_FILE             = &H00000040
%DNS_QUERY_NO_NETBT                  = &H00000080

%DNS_QUERY_WIRE_ONLY                 = &H00000100
%DNS_QUERY_RETURN_MESSAGE            = &H00000200

%DNS_QUERY_MULTICAST_ONLY            = &H00000400
%DNS_QUERY_NO_MULTICAST              = &H00000800

%DNS_QUERY_TREAT_AS_FQDN             = &H00001000
%DNS_QUERY_APPEND_MULTILABEL         = &H00800000

%DNS_QUERY_DONT_RESET_TTL_VALUES     = &H00100000
%DNS_QUERY_RESERVED                  = &Hf0000000???



'  Backward compatibility with Win2K
'  Do not use

%DNS_QUERY_CACHE_ONLY                = %DNS_QUERY_NO_WIRE_QUERY



DECLARE FUNCTION DnsQuery_A LIB "DnsApi.dll" ALIAS "DnsQuery_A" ( _
    pszName        AS ASCIIZ, _
    BYVAL wType    AS WORD, _
    BYVAL Options  AS DWORD, _
    pExtra         AS ANY, _   ' PVOID
    ppQueryResults AS ANY, _   ' DNS_RECORD PTR PTR
    pReserved      AS ANY _    ' PVOID *
    ) AS LONG

DECLARE FUNCTION DnsQuery_UTF8 LIB "DnsApi.dll" ALIAS "DnsQuery_UTF8" ( _
    pszName        AS ASCIIZ, _
    BYVAL wType    AS WORD, _
    BYVAL Options  AS DWORD, _
    pExtra         AS ANY, _   ' PVOID
    ppQueryResults AS ANY, _   ' DNS_RECORD PTR PTR
    pReserved      AS ANY _    ' PVOID *
    ) AS LONG

DECLARE FUNCTION DnsQuery_W LIB "DnsApi.dll" ALIAS "DnsQuery_W" ( _
    pszName        AS WSTRINGZ, _
    BYVAL wType    AS WORD, _
    BYVAL Options  AS DWORD, _
    pExtra         AS ANY, _   ' PVOID
    ppQueryResults AS ANY, _   ' DNS_RECORD PTR PTR
    pReserved      AS ANY _    ' PVOID *
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO DnsQuery=DnsQuery_W
#ELSE
MACRO DnsQuery=DnsQuery_A
#ENDIF




'
'  DNS Update API
'
'      DnsAcquireContextHandle
'      DnsReleaseContextHandle
'      DnsModifyRecordsInSet
'      DnsReplaceRecordSet
'

'
'  Update flags
'

%DNS_UPDATE_SECURITY_USE_DEFAULT    = &H00000000
%DNS_UPDATE_SECURITY_OFF            = &H00000010
%DNS_UPDATE_SECURITY_ON             = &H00000020
%DNS_UPDATE_SECURITY_ONLY           = &H00000100
%DNS_UPDATE_CACHE_SECURITY_CONTEXT  = &H00000200
%DNS_UPDATE_TEST_USE_LOCAL_SYS_ACCT = &H00000400
%DNS_UPDATE_FORCE_SECURITY_NEGO     = &H00000800
%DNS_UPDATE_TRY_ALL_MASTER_SERVERS  = &H00001000
%DNS_UPDATE_SKIP_NO_UPDATE_ADAPTERS = &H00002000
%DNS_UPDATE_REMOTE_SERVER           = &H00004000
%DNS_UPDATE_RESERVED                = &Hffff0000???


'
'  Note:  pCredentials paramater is currently respectively
'  PSEC_WINNT_AUTH_IDENTITY_W or PSEC_WINNT_AUTH_IDENTITY_A.
'  Using PVOID to obviate the need for including rpcdce.h
'  in order to include this file and to leave open the
'  possibility of alternative credential specifications in
'  the future.
'

DECLARE FUNCTION DnsAcquireContextHandle_W LIB "DnsApi.dll" _
    ALIAS "DnsAcquireContextHandle_W" ( _
    BYVAL CredentialFlags AS DWORD, _
    Credentials           AS ANY, _    ' PVOID
    pContext              AS DWORD _   ' HANDLE PTR
    ) AS LONG

DECLARE FUNCTION DnsAcquireContextHandle_A LIB "DnsApi.dll" _
    ALIAS "DnsAcquireContextHandle_A" ( _
    BYVAL CredentialFlags AS DWORD, _
    Credentials           AS ANY, _    ' PVOID
    pContext              AS DWORD _   ' HANDLE PTR
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO DnsAcquireContextHandle=DnsAcquireContextHandle_W
#ELSE
MACRO DnsAcquireContextHandle=DnsAcquireContextHandle_A
#ENDIF

DECLARE SUB DnsReleaseContextHandle LIB "DnsApi.dll" _
    ALIAS "DnsReleaseContextHandle" ( _
    BYVAL hContext AS DWORD _  ' HANDLE
    )

'
'  Dynamic Update API
'

DECLARE FUNCTION DnsModifyRecordsInSet_W LIB "DnsApi.dll" _
    ALIAS "DnsModifyRecordsInSet_W" ( _
    pAddRecords        AS DNS_RECORD, _
    pDeleteRecords     AS DNS_RECORD, _
    BYVAL Options      AS DWORD, _
    BYVAL hCredentials AS DWORD, _  ' HANDLE
    pExtraList         AS ANY, _    ' PVOID
    pReserved          AS ANY _     ' PVOID
    ) AS LONG

DECLARE FUNCTION DnsModifyRecordsInSet_A LIB "DnsApi.dll" _
    ALIAS "DnsModifyRecordsInSet_A" ( _
    pAddRecords        AS DNS_RECORD, _
    pDeleteRecords     AS DNS_RECORD, _
    BYVAL Options      AS DWORD, _
    BYVAL hCredentials AS DWORD, _  ' HANDLE
    pExtraList         AS ANY, _    ' PVOID
    pReserved          AS ANY _     ' PVOID
    ) AS LONG

DECLARE FUNCTION DnsModifyRecordsInSet_UTF8 LIB "DnsApi.dll" _
    ALIAS "DnsModifyRecordsInSet_UTF8" ( _
    pAddRecords        AS DNS_RECORD, _
    pDeleteRecords     AS DNS_RECORD, _
    BYVAL Options      AS DWORD, _
    BYVAL hCredentials AS DWORD, _  ' HANDLE
    pExtraList         AS ANY, _    ' PVOID
    pReserved          AS ANY _     ' PVOID
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO DnsModifyRecordsInSet=DnsModifyRecordsInSet_W
#ELSE
MACRO DnsModifyRecordsInSet=DnsModifyRecordsInSet_A
#ENDIF


DECLARE FUNCTION DnsReplaceRecordSetW LIB "DnsApi.dll" _
    ALIAS "DnsReplaceRecordSetW" ( _
    pReplaceSet    AS DNS_RECORD, _
    BYVAL Options  AS DWORD, _
    BYVAL hContext AS DWORD, _  ' HANDLE
    pExtraInfo     AS ANY, _    ' PVOID
    pReserved      AS ANY _     ' PVOID
    ) AS LONG

DECLARE FUNCTION DnsReplaceRecordSetA LIB "DnsApi.dll" _
    ALIAS "DnsReplaceRecordSetA" ( _
    pReplaceSet    AS DNS_RECORD, _
    BYVAL Options  AS DWORD, _
    BYVAL hContext AS DWORD, _  ' HANDLE
    pExtraInfo     AS ANY, _    ' PVOID
    pReserved      AS ANY _     ' PVOID
    ) AS LONG

DECLARE FUNCTION DnsReplaceRecordSetUTF8 LIB "DnsApi.dll" _
    ALIAS "DnsReplaceRecordSetUTF8" ( _
    pReplaceSet    AS DNS_RECORD, _
    BYVAL Options  AS DWORD, _
    BYVAL hContext AS DWORD, _  ' HANDLE
    pExtraInfo     AS ANY, _    ' PVOID
    pReserved      AS ANY _     ' PVOID
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO DnsReplaceRecordSet=DnsReplaceRecordSetW
#ELSE
MACRO DnsReplaceRecordSet=DnsReplaceRecordSetA
#ENDIF



'
'  DNS name validation
'

MACRO DNS_NAME_FORMAT_enum=LONG
ENUM DNS_NAME_FORMAT SINGULAR
    DnsNameDomain
    DnsNameDomainLabel
    DnsNameHostnameFull
    DnsNameHostnameLabel
    DnsNameWildcard
    DnsNameSrvRecord
    DnsNameValidateTld
END ENUM


DECLARE FUNCTION DnsValidateName_W LIB "DnsApi.dll" _
    ALIAS "DnsValidateName_W" ( _
    pszName AS WSTRINGZ, _
    Format  AS DNS_NAME_FORMAT_enum _
    ) AS LONG

DECLARE FUNCTION DnsValidateName_A LIB "DnsApi.dll" _
    ALIAS "DnsValidateName_A" ( _
    pszName AS ASCIIZ, _
    Format  AS DNS_NAME_FORMAT_enum _
    ) AS LONG

DECLARE FUNCTION DnsValidateName_UTF8 LIB "DnsApi.dll" _
    ALIAS "DnsValidateName_UTF8" ( _
    pszName AS ASCIIZ, _
    Format  AS DNS_NAME_FORMAT_enum _
    ) AS LONG

#IF %DEF(%UNICODE)
MACRO DnsValidateName=DnsValidateName_W
#ELSE
MACRO DnsValidateName=DnsValidateName_A
#ENDIF

'
' DNS server validation
'

' DNS server validation error codes
%DNS_VALSVR_ERROR_INVALID_ADDR             = &H01
%DNS_VALSVR_ERROR_INVALID_NAME             = &H02
%DNS_VALSVR_ERROR_UNREACHABLE              = &H03
%DNS_VALSVR_ERROR_NO_RESPONSE              = &H04
%DNS_VALSVR_ERROR_NO_AUTH                  = &H05
%DNS_VALSVR_ERROR_REFUSED                  = &H06

%DNS_VALSVR_ERROR_NO_TCP                   = &H10
%DNS_VALSVR_ERROR_UNKNOWN                  = &HFF??

' Winsock2.inc must be included before windns.inc to use the
' validate server function

#IF %DEF(%WS2DEF)

DECLARE FUNCTION DnsValidateServerStatus LIB "DnsApi.dll" _
    ALIAS "DnsValidateServerStatus" ( _
    SERVER       AS SOCKADDR, _
    queryName    AS WSTRINGZ, _
    serverStatus AS DWORD _
    ) AS LONG

#ENDIF

'
'  DNS name comparison
'

DECLARE FUNCTION DnsNameCompare_A LIB "DnsApi.dll" _
    ALIAS "DnsNameCompare_A" ( _
    pName1 AS ASCIIZ, _
    pName2 AS ASCIIZ _
    ) AS LONG  ' BOOL

DECLARE FUNCTION DnsNameCompare_W LIB "DnsApi.dll" _
    ALIAS "DnsNameCompare_W" ( _
    pName1 AS WSTRINGZ, _
    pName2 AS WSTRINGZ _
    ) AS LONG  ' BOOL

#IF %DEF(%UNICODE)
MACRO DnsNameCompare=DnsNameCompare_W
#ELSE
MACRO DnsNameCompare=DnsNameCompare_A
#ENDIF



'
'  DNS message "roll-your-own" routines
'

TYPE DNS_MESSAGE_BUFFER
    MessageHead    AS DNS_HEADER
    MessageBody(0) AS BYTE
END TYPE

DECLARE FUNCTION DnsWriteQuestionToBuffer_W LIB "DnsApi.dll" _
    ALIAS "DnsWriteQuestionToBuffer_W" ( _
    BYVAL pDnsBuffer        AS DNS_MESSAGE_BUFFER PTR, _
    pdwBufferSize           AS DWORD, _
    pszName                 AS WSTRINGZ, _
    BYVAL wType             AS WORD, _
    BYVAL Xid               AS WORD, _
    BYVAL fRecursionDesired AS LONG _  ' BOOL
    ) AS LONG  ' BOOL

DECLARE FUNCTION DnsWriteQuestionToBuffer_UTF8 LIB "DnsApi.dll" _
    ALIAS "DnsWriteQuestionToBuffer_UTF8" ( _
    BYVAL pDnsBuffer        AS DNS_MESSAGE_BUFFER PTR, _
    pdwBufferSize           AS DWORD, _
    pszName                 AS ASCIIZ, _
    BYVAL wType             AS WORD, _
    BYVAL Xid               AS WORD, _
    BYVAL fRecursionDesired AS LONG _  ' BOOL
    ) AS LONG  ' BOOL

DECLARE FUNCTION DnsExtractRecordsFromMessage_W LIB "DnsApi.dll" _
    ALIAS "DnsExtractRecordsFromMessage_W" ( _
    BYVAL pDnsBuffer     AS DNS_MESSAGE_BUFFER PTR, _
    BYVAL wMessageLength AS WORD, _
    ppRecord             AS ANY _  ' PDNS_RECORD *
    ) AS LONG

DECLARE FUNCTION DnsExtractRecordsFromMessage_UTF8 LIB "DnsApi.dll" _
    ALIAS "DnsExtractRecordsFromMessage_UTF8" ( _
    BYVAL pDnsBuffer     AS DNS_MESSAGE_BUFFER PTR, _
    BYVAL wMessageLength AS WORD, _
    ppRecord             AS ANY _  ' PDNS_RECORD *
    ) AS LONG



DECLARE FUNCTION DnsGetProxyInformation LIB "DnsApi.dll" _
    ALIAS "DnsGetProxyInformation" ( _
    hostName                AS WSTRINGZ, _
    proxyInformation        AS DNS_PROXY_INFORMATION, _
    defaultProxyInformation AS DNS_PROXY_INFORMATION, _
    BYVAL completionRoutine AS DWORD, _  ' DNS_PROXY_COMPLETION_ROUTINE
    completionContext       AS ANY _  ' void *
    ) AS DWORD


DECLARE SUB DnsFreeProxyName LIB "DnsApi.dll" ALIAS "DnsFreeProxyName" ( _
    proxyName AS WSTRINGZ)
